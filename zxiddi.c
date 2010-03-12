/* zxiddi.c  -  Discovery Server
 * Copyright (c) 2010 Sampo Kellomaki (sampo@iki.fi), All Rights Reserved.
 * Copyright (c) 2009 Symlabs (symlabs@symlabs.com), All Rights Reserved.
 * Author: Sampo Kellomaki (sampo@iki.fi)
 * This is confidential unpublished proprietary source code of the author.
 * NO WARRANTY, not even implied warranties. Contains trade secrets.
 * Distribution prohibited unless authorized in writing.
 * Licensed under Apache License 2.0, see file COPYING.
 * $Id: zxiddi.c,v 1.2 2009-11-24 23:53:40 sampo Exp $
 *
 * 15.11.2009, created --Sampo
 *
 * See also zxidepr.c for discovery client code.
 */

#include <dirent.h>

#include "errmac.h"
#include "zxid.h"
#include "zxidconf.h"
#include "saml2.h"
#include "wsf.h"
#include "c/zx-const.h"
#include "c/zx-ns.h"
#include "c/zx-data.h"

/*() Server side  Discovery Service Query processing. See also zxid_gen_bootstraps() */

/* Called by:  zxid_sp_soap_dispatch */
struct zx_di_QueryResponse_s* zxid_di_query(struct zxid_conf* cf, struct zx_sa_Assertion_s* a7n, struct zx_di_Query_s* req)
{
  struct zx_sa_NameID_s* nameid;
  struct zx_di_RequestedService_s* rs;
  struct zx_di_QueryResponse_s* resp = zx_NEW_di_QueryResponse(cf->ctx);
  struct zx_root_s* r;
  char* logop;
  int len, epr_len, match, n_discovered = 0;
  char uid[ZXID_MAX_BUF];
  char sp_name_buf[1024];
  char mdpath[ZXID_MAX_BUF];
  char path[ZXID_MAX_BUF];
  char* epr_buf;
  DIR* dir;
  struct dirent * de;
  struct zx_str* affil;
  struct zx_elem_s* el;
  struct zx_a_Metadata_s* md = 0;  
  struct zx_str* addr = 0;  
  struct zx_a_EndpointReference_s* epr = 0;
  D_INDENT("di_query: ");

  //resp->ID = zxid_mk_id(cf, "DIR", ZXID_ID_BITS);
  
  if (!a7n || !a7n->Subject) {
    ERR("Malformed Assertion(%p): Subject missing.", a7n);
    resp->Status = zxid_mk_lu_Status(cf, "Fail", 0, 0, 0);
    D_DEDENT("di_query: ");
    return resp;
  }

  /* Recover end user's identity: uid at IdP. This is actually done via "self federation"
   * that was created when token for accessing discovery was issued. */
  
  nameid = zxid_decrypt_nameid(cf, a7n->Subject->NameID, a7n->Subject->EncryptedID);
  affil = nameid->SPNameQualifier ? nameid->SPNameQualifier : zxid_my_entity_id(cf);
  
  zxid_nice_sha1(cf, sp_name_buf, sizeof(sp_name_buf), affil, affil, 7);
  len = read_all(sizeof(uid)-1, uid, "idp_map_nid2uid", "%s" ZXID_NID_DIR "%s/%.*s", cf->path, sp_name_buf, nameid->gg.content->len, nameid->gg.content->s);
  if (!len) {
    ERR("Can not find reverse mapping for SP,SHA1(%s) nid(%.*s)", sp_name_buf, nameid->gg.content->len, nameid->gg.content->s);
    resp->Status = zxid_mk_lu_Status(cf, "Fail", 0, 0, 0);
    D_DEDENT("di_query: ");
    return resp;
  }

  name_from_path(mdpath, sizeof(mdpath), "%sdimd", cf->path);

  /* Work through all requests */

  for (rs = req->RequestedService; rs; rs = (struct zx_di_RequestedService_s*)ZX_NEXT(rs)) {

    /* Look for all entities providing service */

    if (rs->ServiceType && rs->ServiceType->content && rs->ServiceType->content->len) {
      /* *** proper handling of discovering simultaneously multiple service types? */
    } else {
      D("%d: No specific service type given. Looking for all. %p", n_discovered, rs->ServiceType);
      len = 0;
      path[0] = 0;
    }

    D("%d: Looking for service metadata in dir(%s)", n_discovered, mdpath);
    dir = opendir(mdpath);
    if (!dir) {
      perror("opendir to find service metadata");
      ERR("Opening service metadata directory failed path(%s)", mdpath);
      resp->Status = zxid_mk_lu_Status(cf, "Fail", 0, 0, 0);
      D_DEDENT("di_query: ");
      return resp;
    }
    
    /* Work through all available providers, filtering out insuitable ones. */
    
    while (de = readdir(dir)) {
      D("%d: Considering file(%s)", n_discovered, de->d_name);

      if (de->d_name[strlen(de->d_name)-1] == '~')  /* Ignore backups from hand edited EPRs. */
	continue;
      
      /* Filter file name by service type */
      
      for (el = rs->ServiceType; el; el = (struct zx_elem_s*)el->g.n) {
	if (!el->content || !el->content->len)
	  continue;
	len = MIN(el->content->len, sizeof(path)-1);
	memcpy(path, el->content->s, len);
	path[len] = 0;
	zxid_fold_svc(path, len);
	if (memcmp(de->d_name, path, len) || de->d_name[len] != ',') {
	  D("%d: rejected due to prefix(%s) file(%s)", n_discovered, path, de->d_name);
	  goto next_file;
	}
      }
      
      /* Probable enough, read and parse EPR so we can continue examination. */

      epr_buf = ZX_ALLOC(cf->ctx, ZXID_INIT_EPR_BUF);
      epr_len = read_all(ZXID_INIT_EPR_BUF, epr_buf, "find_svcmd", "%s/%s", mdpath, de->d_name);
      if (!epr_len) {
	ZX_FREE(cf->ctx, epr_buf);
	continue;
      }
      LOCK(cf->ctx->mx, "diq epr");
      zx_prepare_dec_ctx(cf->ctx, zx_ns_tab, epr_buf, epr_buf + epr_len);
      r = zx_DEC_root(cf->ctx, 0, 1);
      UNLOCK(cf->ctx->mx, "diq epr");
      if (!r) {
	ERR("Failed to XML parse epr_buf(%.*s) file(%s)", epr_len, epr_buf, de->d_name);
	ZX_FREE(cf->ctx, epr_buf);
	continue;
      }
      /* *** add ID-WSF 1.1 handling */
      epr = r->EndpointReference;
      ZX_FREE(cf->ctx, r);
      if (!epr || !epr->Metadata) {
	ERR("No EPR or missing <Metadata>. epr_buf(%.*s) file(%s)", epr_len, epr_buf, de->d_name);
	ZX_FREE(cf->ctx, epr_buf);
	continue;
      }
      if (!epr->Address || !epr->Address->gg.content || !epr->Address->gg.content->len) {
	ERR("EPR missing <Address>. epr_buf(%.*s) file(%s)", epr_len, epr_buf, de->d_name);
	ZX_FREE(cf->ctx, epr_buf);
	continue;
      }
      addr = epr->Address->gg.content;
      md = epr->Metadata;

      /* Filter by service type */
      
      match = 1;
      for (el = rs->ServiceType; el; el = (struct zx_elem_s*)el->g.n) {
	if (!el->content || !el->content->len)
	  continue;
	match = 0;
	if (!md->ServiceType || !md->ServiceType->content || !md->ServiceType->content->len) {
	  INFO("EPR missing ServiceType. Rejected. epr_buf(%.*s) file(%s)", epr_len, epr_buf, de->d_name);
	  ZX_FREE(cf->ctx, epr_buf);
	  goto next_file;
	}
	if (el->content->len != md->ServiceType->content->len
	    || memcmp(el->content->s, md->ServiceType->content->s, el->content->len)) {
	  D("%d: Internal svctype(%.*s) does not match desired(%.*s)", n_discovered, md->ServiceType->content->len, md->ServiceType->content->s, el->content->len, el->content->s);
	  continue;
	}
	D("%d: ServiceType matches. file(%s)", n_discovered, de->d_name);
	match = 1;
	break;
      }
      if (!match) {
	  D("%d: Rejected due to ServiceType. file(%s)", n_discovered, de->d_name);
	  ZX_FREE(cf->ctx, epr_buf);
	  goto next_file;
      }

      /* Filter by provider id */
      
      for (el = rs->ProviderID; el; el = (struct zx_elem_s*)el->g.n) {
	if (!el->content || !el->content->len)
	  continue;
	match = 0;
	if (!md->ProviderID || !md->ProviderID->content || !md->ProviderID->content->len) {
	  INFO("EPR missing ProviderID. epr_buf(%.*s) file(%s)", epr_len, epr_buf, de->d_name);
	  break;
	}
	if (el->content->len != md->ProviderID->content->len
	    || memcmp(el->content->s, md->ProviderID->content->s, el->content->len)) {
	  D("%d: ProviderID(%.*s) does not match desired(%.*s)", n_discovered, md->ProviderID->content->len, md->ProviderID->content->s, el->content->len, el->content->s);
	  continue;
	}
	D("%d: ProviderID matches. file(%s)", n_discovered, de->d_name);
	match = 1;
	break;
      }
#if 1
      /* TAS3 extension: allow matching by the Address (URL) as well */
      if (!match) {
	for (el = rs->ProviderID; el; el = (struct zx_elem_s*)el->g.n) {
	  if (!el->content || !el->content->len)
	    continue;
	  match = 0;
	  if (el->content->len != addr->len
	      || memcmp(el->content->s, addr->s, el->content->len)) {
	    D("%d: Address(%.*s) does not match desired(%.*s)", n_discovered, addr->len, addr->s, el->content->len, el->content->s);
	    continue;
	  }
	  D("%d: Address matches. file(%s)", n_discovered, de->d_name);
	  match = 1;
	  break;
	}
      }
#endif
      if (!match) {
	D("%d: Rejected due to ProviderID. file(%s)", n_discovered, de->d_name);
	ZX_FREE(cf->ctx, epr_buf);
	goto next_file;
      }

      /* *** Check Options */

      /* *** Check Framework */

      /* *** Check Action */

#if 0
      /* Call Trust and Privacy Negotiation (TrustBuilder), Andreas. */
      systemf("./tpn-client.sh %s %s %s", idpnid, "urn:idhrxml:cv:update", host);
#endif
      ++n_discovered;
      D("%d: DISCOVERED EPR url(%.*s)", n_discovered, addr->len, addr->s);
      logop = zxid_add_fed_tok_to_epr(cf, epr, uid, 1);
      if (!logop) {
	ZX_FREE(cf->ctx, epr_buf);
	goto next_file;
      }

      epr->gg.g.n = (void*)resp->EndpointReference;
      resp->EndpointReference = epr;

      zxlog(cf, 0, 0, 0, 0, 0, a7n->ID, nameid->gg.content, "N", "K", logop, uid, "");

      if (rs->resultsType && rs->resultsType->s
	  && (!memcmp(rs->resultsType->s, "only-one", rs->resultsType->len)
	      || !memcmp(rs->resultsType->s, "best", rs->resultsType->len))) {
	D("only-one or best requested (%.*s)", rs->resultsType->len, rs->resultsType->s);
	break;
      }
      
next_file:
      continue;
    }
    
    closedir(dir);
  }
  el = req->RequestedService->ServiceType && req->RequestedService->ServiceType->content
    ? req->RequestedService->ServiceType : 0;
  D("TOTAL discovered %d svctype(%.*s)", n_discovered, el?el->content->len:0, el?el->content->s:"");
  zxlog(cf, 0, 0, 0, 0, 0, a7n->ID, nameid->gg.content, "N", "K", "DIOK", 0, "%.*s n=%d", el?el->content->len:1, el?el->content->s:"-", n_discovered);
  resp->Status = zxid_mk_lu_Status(cf, "OK", 0, 0, 0);
  D_DEDENT("di_query: ");
  return resp;
}

/* EOF  --  zxiddi.c */
