/* zxidepr.c  -  Handwritten functions for client side EPR and bootstrap handling
 * Copyright (c) 2010 Sampo Kellomaki (sampo@iki.fi), All Rights Reserved.
 * Copyright (c) 2007-2009 Symlabs (symlabs@symlabs.com), All Rights Reserved.
 * Author: Sampo Kellomaki (sampo@iki.fi)
 * This is confidential unpublished proprietary source code of the author.
 * NO WARRANTY, not even implied warranties. Contains trade secrets.
 * Distribution prohibited unless authorized in writing.
 * Licensed under Apache License 2.0, see file COPYING.
 * $Id: zxidepr.c,v 1.19 2009-11-29 12:23:06 sampo Exp $
 *
 * 5.2.2007, created --Sampo
 * 7.10.2008, added documentation --Sampo
 *
 * See also: zxidsimp.c (attributes to LDIF), and zxida7n.c (general attribute querying)
 *
 * N.B. Like session storage, the epr cache makes case preserving assumption about
 * underlying filesystem. Case insensitive filesystem will insignificantly increase
 * chances of naming collitions.
 *
 * See also zxiddi.c for discovery server code.
 */

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>
#include <stdio.h>
#include <dirent.h>
#include <unistd.h>

#include "errmac.h"
#include "zxid.h"
#include "platform.h"
#include "zxidconf.h"
#include "saml2.h"
#include "c/zx-ns.h"

/*() Fold service type (or any URN or URL) to file name. */

/* Called by:  main, zxid_di_query, zxid_find_epr */
void zxid_fold_svc(char* p, int len)
{
  for (; *p && len; ++p, --len)
    if (ONE_OF_6(*p, ':','/',',','?','&','='))
      *p = '_';
}

/*() Compute (and fold) unique nice sha1 name according to NAME,SHA1
 *
 * This name format is designed to ensure unique name, while
 * maintainting human readability. This is
 * useful in the common case where WSC wants to call a specific type of web service.
 *
 * cf::  ZXID configuration object, also used for memory allocation
 * buf:: result parameter. The buffer, which must have been allocated, will be
 *     modified to have the path. The path will be nul terminated.
 * buf_len:: The length of the buf (including nul termination), usually sizeof(buf)
 * name:: Often Service name or SP Entity ID
 * cont:: content of EPR or the SP EntityID, used to compute sha1 hash that becomes part
 *     of the file name
 * ign_prefix:: How many characters to ignore from beginning of name: 0 or 7
 * return:: 0 on success (the real return value is returned via ~buf~ result parameter) */

/* Called by:  zxid_add_fed_tok_to_epr, zxid_di_query, zxid_epr_path, zxid_idp_sso */
int zxid_nice_sha1(struct zxid_conf* cf, char* buf, int buf_len,
		   struct zx_str* name, struct zx_str* cont, int ign_prefix)
{
  char* p;
  char* q;
  int len;
  char sha1_cont[28];
  sha1_safe_base64(sha1_cont, cont->len, cont->s);
  sha1_cont[27] = 0;
  len = snprintf(buf, buf_len, "%.*s,%s",
		 MAX(name->len-ign_prefix,0), name->s+ign_prefix, sha1_cont);

  /* 012345678
   * http://
   * https://   */

  /* Sanity scan the name part (svc or eid), folding dangerous chars to _. */

  p = buf;
  q = MIN(p + MAX(name->len-7,0), buf + buf_len);
  zxid_fold_svc(p, q-p);
  return 0;
}

/*() Compute (and fold) unique EPR name according to /var/zxid/ses/SESID/SVC,SHA1
 *
 * This name format is designed to ensure unique name for each EPR, while
 * also making it easy to determine the service type from the name. This is
 * useful in the common case where WSC wants to call a specific type of web service.
 *
 * cf::  ZXID configuration object, also used for memory allocation
 * dir:: Directory, such as "ses/"
 * sid:: Session ID whose EPR cache the file is/will be located
 * buf:: result parameter. The buffer, which must have been allocated, will be
 *     modified to have the path. The path will be nul terminated.
 * buf_len:: The length of the buf (including nul termination), usually sizeof(buf)
 * svc:: Service name
 * cont:: content of EPR, used to compute sha1 hash that becomes part of the file name
 * return:: 0 on success (the real return value is returned via ~buf~ result parameter)
 *
 * N.B. This function relies on specific, ANSI documented, functioning
 * of snprintf(3) library function. Unfortunately, it has been found that
 * on some platforms this function only works correctly in the 'C' locale. If
 * you suspect this to be the case, you may want to try
 *
 *    export LANG=C
 *
 * especially if you get errors about multibyte characters. */

/* Called by:  zxid_cache_epr, zxid_snarf_eprs_from_ses */
int zxid_epr_path(struct zxid_conf* cf, char* dir, char* sid,
		  char* buf, int buf_len, struct zx_str* svc, struct zx_str* cont)
{
  int len = snprintf(buf, buf_len, "%s%s%s/", cf->path, dir, sid);
  if (len < 0) {
    perror("snprintf");
    ERR("Broken snprintf? Impossible to compute length of string. Be sure to `export LANG=C' if you get errors about multibyte characters. Length returned: %d", len);
    if (buf && buf_len > 0)
      buf[0] = 0;
    return 1;
  }
  return zxid_nice_sha1(cf, buf+len, buf_len - len, svc, cont, 0);
}

/*() Serialize EPR data structure to XML and write it to session's EPR cache under
 * file name that is both unique and indicates the service type.
 *
 * cf:: ZXID configuration object, also used for memory allocation
 * ses:: Session object in whose EPR cache the file will be located
 * epr:: XML data structure representing the EPR
 * return:: 1 on success, 0 on failure */

/* Called by:  main x2, zxid_get_epr, zxid_snarf_eprs_from_ses */
int zxid_cache_epr(struct zxid_conf* cf, struct zxid_ses* ses, struct zx_a_EndpointReference_s* epr)
{
  fdtype fd;
  struct zx_str* ss;
  char path[ZXID_MAX_BUF];
  
  if (!ses || !ses->sid || !ses->sid[0]) {
    ERR("Valid session required %p", ses);
    return 0;
  }
  if (!epr || !epr->Metadata || !epr->Metadata->ServiceType) {
    ERR("EPR is not a ID-WSF 2.0 Bootstrap: no Metadata %p", epr);
    return 0;
  }
  ss = zx_EASY_ENC_WO_a_EndpointReference(cf->ctx, epr);
  if (!ss) {
    ERR("Encoding EndpointReference failed %p", epr);
    return 0;
  }
  zxid_epr_path(cf, ZXID_SES_DIR, ses->sid, path, sizeof(path),
		epr->Metadata->ServiceType->content, ss);
  //fd = open(path, O_CREAT | O_WRONLY | O_TRUNC, 0666);
  fd = open_fd_from_path(O_CREAT | O_WRONLY | O_TRUNC, 0666, "zxid_cache_epr", "%s", path);
  if (fd == BADFD) {
    perror("open for write cache_epr");
    ERR("EPR path(%s) creation failed", path);
  } else if (write_all_fd(fd, ss->s, ss->len) == -1) {
    perror("Trouble writing EPR");
  }
  close_file(fd, (const char*)__FUNCTION__);
  zx_str_free(cf->ctx, ss);
  return 1;
}

/*() Look into attribute statements of a SSO assertion and extract anything
 * that looks like EPR, storing results in the session for later reference.
 *
 * cf:: ZXID configuration object, also used for memory allocation
 * ses:: Session object in whose EPR cache will be populated
 *
 * N.B. This approach ignores the official attribute names totally. Anything
 * that looks like an EPR and that is strcturally in right place will work.
 * Typical name /var/zxid/ses/SESID/SVCTYPE,SHA1 */

/* Called by:  zxid_sp_anon_finalize, zxid_sp_sso_finalize */
void zxid_snarf_eprs(struct zxid_conf* cf, struct zxid_ses* ses, struct zx_a_EndpointReference_s* epr)
{
  struct zx_str* ss;
  struct zx_str* urlss;
  int wsf20 = 0;
  for (; epr; epr = (struct zx_a_EndpointReference_s*)epr->gg.g.n) {
    ss = epr->Metadata->ServiceType->content;
    urlss = epr->Address->gg.content;
    D("%d: EPR svc(%.*s) url(%.*s)", wsf20, ss?ss->len:0, ss?ss->s:"", urlss?urlss->len:0, urlss?urlss->s:"");
    if (zxid_cache_epr(cf, ses, epr)) {
      ++wsf20;
      D("%d: EPR cached svc(%.*s) url(%.*s)", wsf20, ss?ss->len:0, ss?ss->s:"", urlss?urlss->len:0, urlss?urlss->s:"");
    }
  }
  D("TOTAL wsf20 EPRs snarfed: %d", wsf20);
}

/*() Look into attribute statements of a SSO assertion and extract anything
 * that looks like EPR, storing results in the session for later reference.
 *
 * cf:: ZXID configuration object, also used for memory allocation
 * ses:: Session object in whose EPR cache will be populated
 *
 * N.B. This approach ignores the official attribute names totally. Anything
 * that looks like an EPR and that is strcturally in right place will work.
 * Typical name /var/zxid/ses/SESID/SVCTYPE,SHA1 */

/* Called by:  zxid_sp_anon_finalize, zxid_sp_sso_finalize */
void zxid_snarf_eprs_from_ses(struct zxid_conf* cf, struct zxid_ses* ses)
{
  struct zx_sa_AttributeStatement_s* as;
  struct zx_sa_Attribute_s* at;
  struct zx_sa_AttributeValue_s* av;
  int wsf11 = 0;
  
  D_INDENT("snarf_eprs: ");
  zxid_get_ses_sso_a7n(cf, ses);
  if (ses->a7n)
    for (as = ses->a7n->AttributeStatement; as; as = (struct zx_sa_AttributeStatement_s*)as->gg.g.n)
      for (at = as->Attribute; at; at = (struct zx_sa_Attribute_s*)at->gg.g.n)
	for (av = at->AttributeValue; av; av = (struct zx_sa_AttributeValue_s*)av->gg.g.n) {
	  zxid_snarf_eprs(cf, ses, av->EndpointReference);
	  if (av->ResourceOffering) {
	    ++wsf11;
	    D("Detected wsf11 resource offering. %d", wsf11);
#if 0	    
	    ss = zx_EASY_ENC_WO_di12_ResourceOffering(cf->ctx, av->ResourceOffering);
	    
	    zxid_epr_path(cf, ZXID_SES_DIR, ses->sid, path, sizeof(path),
			  av->EndpointReference->Metadata->ServiceType->content, ss);
	    fd = open(path, O_CREAT | O_WRONLY | O_TRUNC, 0666);
	    if (fd == -1) {
	      perror("open for write epr");
	      ERR("EPR path(%s) creation failed", path);
	    } else if (write_all_fd(fd, ss->s, ss->len) == -1) {
	      perror("Trouble writing EPR");
	      close__file(fd, __FUNCTION__);
	    }
	    zx_str_free(cf->ctx, ss);
#endif
	  }
	}
#if 0
  if (ses->a7n12)
    for (as = ses->a7n->AttributeStatement; as; as = (struct zx_sa11_AttributeStatement_s*)as->gg.g.n)
      for (at = as->Attribute; at; at = (struct zx_sa_Attribute_s*)at->gg.g.n)
	for (av = at->AttributeValue; av; av = (struct zx_sa_AttributeValue_s*)av->gg.g.n) {
	}
#endif
  D_DEDENT("snarf_eprs: ");
}

/*() Search the EPRs cached under the session for a match. First directory is searched
 * for files whose name starts by service type. These files are opened and parsed
 * as EPR and further checks are made. The nth match is returned. 1 means first.
 * Typical name: /var/zxid/ses/SESID/SVCTYPE,SHA1
 *
 * cf:: ZXID configuration object, also used for memory allocation
 * ses:: Session object in whose EPR cache the file is searched
 * svc:: Service type (usually a URN)
 * url:: (Optional) If provided, this argument has to match either
 *     the ProviderID, EntityID, or actual service endpoint URL.
 * di_opt:: (Optional) Additional discovery options for selecting the service, query string format
 * action:: (Optional) The action, or method, that must be invocable on the service
 * n:: How manieth matching instance is returned. 1 means first
 * return:: EPR data structure (or linked list of EPRs) on success, 0 on failure */

/* Called by:  main x3, zxid_get_epr x2 */
struct zx_a_EndpointReference_s* zxid_find_epr(struct zxid_conf* cf, struct zxid_ses* ses, const char* svc, const char* url, const char* di_opt, const char* action, int n)
{
  struct zx_root_s* r;
  int len, epr_len, siz = ZXID_INIT_EPR_BUF;
  char path[ZXID_MAX_BUF];
  char* epr_buf;  /* MUST NOT come from stack. */
  DIR* dir;
  struct dirent * de;
  struct zx_a_EndpointReference_s* epr = 0;
  struct zx_a_Metadata_s* md = 0;  
  D_INDENT("find_epr: ");

#if 1
  if (!svc || !*svc) {
    /* *** Relax this to allow discovery of multiple or all service types */
    ERR("Must supply service type %p", svc);
    D_DEDENT("find_epr: ");
    return 0;
  }
#endif
  
  if (!name_from_path(path, sizeof(path), "%s" ZXID_SES_DIR "%s", cf->path, ses->sid)) {
    D_DEDENT("find_epr: ");
    return 0;
  }
  
  D("Looking in session dir(%s) svc(%s) pses=%p", path, svc, ses);
  dir = opendir(path);
  if (!dir) {
    perror("opendir to find epr in session");
    ERR("Opening session for find epr by opendir failed path(%s) sesptr=%p", path, ses);
    D_DEDENT("find_epr: ");
    return 0;
  }

  epr_buf = ZX_ALLOC(cf->ctx, siz);  /* MUST NOT come from stack. */
  len = strlen(svc);
  len = MIN(len, sizeof(path)-1);
  memcpy(path, svc, len);
  path[len] = 0;
  zxid_fold_svc(path, len);
  D("Folded path prefix(%.*s) len=%d", len, path, len);
      
  while (de = readdir(dir)) {
    D("Considering file(%s)", de->d_name);
    if (de->d_name[0] == '.')  /* . .. and "hidden" files */
      continue;
    if (de->d_name[strlen(de->d_name)-1] == '~')  /* Ignore backups from hand edited EPRs. */
      continue;
    if (memcmp(de->d_name, path, len) || de->d_name[len] != ',')
      continue;
    D("Checking EPR content file(%s)", de->d_name);
    epr_len = read_all(siz, epr_buf, "find_epr",
		       "%s" ZXID_SES_DIR "%s/%s", cf->path, ses->sid, de->d_name);
    if (!epr_len)
      continue;

    while (epr_len == siz) {
      siz += siz;
      if (siz > ZXID_MAX_CURL_BUF) {
	ERR("Fail: Size of EPR(%s) exeeds internal limit %d.", de->d_name, ZXID_MAX_CURL_BUF);
	ZX_FREE(cf->ctx, epr_buf);
	D_DEDENT("find_epr: ");
	return 0;
      }
      D("Large EPR. Reallocating and rereading %d", siz);
      REALLOCN(/*cf->ctx,*/ epr_buf, siz);
      epr_len = read_all(siz, epr_buf, "find_epr",
			 "%s" ZXID_SES_DIR "%s/%s", cf->path, ses->sid, de->d_name);
    }
    
    LOCK(cf->ctx->mx, "find epr");
    zx_prepare_dec_ctx(cf->ctx, zx_ns_tab, epr_buf, epr_buf + epr_len);
    r = zx_DEC_root(cf->ctx, 0, 1);
    UNLOCK(cf->ctx->mx, "find epr");
    if (!r || !r->EndpointReference) {
      ERR("No EPR found. Failed to parse epr_buf(%.*s)", epr_len, epr_buf);
      continue;
    }
    epr = r->EndpointReference;
    ZX_FREE(cf->ctx, r);
    if (!epr->Address || !epr->Address->gg.content->s || !epr->Address->gg.content->len) {
      ERR("The EPR does not have <Address> element. Rejected. %p", epr->Address);
      continue;
    }
    /* *** add ID-WSF 1.1 handling */
    md = epr->Metadata;
    if (svc &&
	(!md || !md->ServiceType || !md->ServiceType->content || !md->ServiceType->content->len)) {
      ERR("No Metadata %p or ServiceType. Failed to parse epr_buf(%.*s)", md, epr_len, epr_buf);
      continue;
    }
    if (svc && (len != md->ServiceType->content->len
		|| memcmp(svc, md->ServiceType->content->s, len))) {
      D("Internal svctype(%.*s) does not match desired(%s). Reject.", md->ServiceType->content->len, md->ServiceType->content->s, svc);
      continue;
    }
    
    if (url && (strlen(url) != epr->Address->gg.content->len
		|| memcmp(url, epr->Address->gg.content->s, epr->Address->gg.content->len))) {
      if (md && md->ProviderID && md->ProviderID->content || md->ProviderID->content->len
	  && (strlen(url) != md->ProviderID->content->len
	      || memcmp(url, md->ProviderID->content->s, md->ProviderID->content->len))) {
	D("ProviderID(%.*s) or endpoint URL(%.*s) does not match desired url(%s). Reject.", epr->Metadata->ProviderID->content->len, epr->Metadata->ProviderID->content->s, epr->Address->gg.content->len, epr->Address->gg.content->s, url);
	continue;
      }
    }

    /* *** Evaluate di_opt */

    /* *** Evaluate action */
    
    if (--n)
      continue;
    
    D("Found svc(%s) url(%.*s)", STRNULLCHK(svc), epr->Address->gg.content->len, epr->Address->gg.content->s);
    closedir(dir);
    D_DEDENT("find_epr: ");
    return epr;
  }
  ZX_FREE(cf->ctx, epr_buf);
  closedir(dir);
  D_DEDENT("find_epr: ");
  return 0;
}

/*(i) First search epr cache, and if miss, go discover an EPR over the net.
 * This is the main work horse for WSCs wishing to call WSPs via EPR.
 *
 * cf:: ZXID configuration object, also used for memory allocation
 * ses:: Session object in whose EPR cache the file will be searched
 * svc:: Service type (usually a URN)
 * url:: (Optional) If provided, this argument has to match either
 *     the ProviderID, EntityID, or actual service endpoint URL.
 * di_opt:: (Optional) Additional discovery options for selecting the service, query string format
 * action:: (Optional) The action, or method, that must be invocable on the service
 * n:: How manieth matching instance is returned. 1 means first
 * return:: EPR data structure on success, 0 on failure (no discovery EPR in cache, or
 *     not found by the discovery service). If more than one were found, a linked list
 *     of EPRs is returned.
 */

/* Called by:  main x7 */
struct zx_a_EndpointReference_s* zxid_get_epr(struct zxid_conf* cf, struct zxid_ses* ses, const char* svc, const char* url, const char* di_opt, const char* action, int n)
{
  int wsf20 = 0;
  struct zx_str* ss;
  struct zx_str* urlss;
  struct zx_e_Envelope_s* env;
  struct zx_a_EndpointReference_s* epr;
  epr = zxid_find_epr(cf, ses, svc, url, di_opt, action, n);
  if (epr)
    return epr;
  
  INFO("Discovering svc(%s)...", STRNULLCHK(svc));
  env = zx_NEW_e_Envelope(cf->ctx);
  env->Header = zx_NEW_e_Header(cf->ctx);
  env->Body = zx_NEW_e_Body(cf->ctx);
  env->Body->Query = zxid_mk_di_query(cf, svc, url, di_opt, 0);
  epr = zxid_find_epr(cf, ses, zx_xmlns_di, 0, 0, 0, n);
  if (!epr) {
    ERR("EPR for svc(%s) not found in cache and no discovery EPR in cache, thus no way to discover the svc.", STRNULLCHK(svc));
    return 0;
  }
  env = zxid_wsc_call(cf, ses, epr, env);
  if (env && env->Body) {
    if (env->Body->QueryResponse) {
      for (epr = env->Body->QueryResponse->EndpointReference; epr; epr = (struct zx_a_EndpointReference_s*)ZX_NEXT(epr)) {
	ss = epr->Metadata->ServiceType->content;
	urlss = epr->Address->gg.content;
	D("%d: EPR svc(%.*s) url(%.*s)", wsf20, ss?ss->len:0, ss?ss->s:"", urlss?urlss->len:0, urlss?urlss->s:"");
	if (zxid_cache_epr(cf, ses, epr)) {
	  ++wsf20;
	  D("%d: EPR cached svc(%.*s) url(%.*s)", wsf20, ss?ss->len:0, ss?ss->s:"", urlss?urlss->len:0, urlss?urlss->s:"");
	}
      }
      epr = env->Body->QueryResponse->EndpointReference;
    } else {
      epr = 0;
    }
    if (!epr)
      ERR("No end point discovered for svc(%s)", STRNULLCHK(svc));
    D("TOTAL wsf20 EPRs discovered: %d", wsf20);
    return epr;
  }
  ERR("discovery call failed envelope=%p", env);
  return 0;
}

/*() Accessor function for extracting endpoint address URL. */

/* Called by: */
struct zx_str* zxid_get_epr_address(struct zxid_conf* cf, struct zx_a_EndpointReference_s* epr) {
  return epr->Address->gg.content;
}

/*() Accessor function for extracting endpoint ProviderID. */

/* Called by: */
struct zx_str* zxid_get_epr_entid(struct zxid_conf* cf, struct zx_a_EndpointReference_s* epr) {
  return epr->Metadata->ProviderID->content;
}

/*() Accessor function for extracting endpoint Description (Abstract). */

/* Called by: */
struct zx_str* zxid_get_epr_desc(struct zxid_conf* cf, struct zx_a_EndpointReference_s* epr) {
  return epr->Metadata->Abstract->content;
}

#if 0
/*() Accessor function for extracting endpoint's SAML2 assertion token. */

/* Called by: */
struct zx_str* zxid_get_epr_a7n(struct zxid_conf* cf, struct zx_a_EndpointReference_s* epr) {
  return epr->Metadata->SecurityContext->Token->Assertion;
}
#endif

/* EOF  --  zxidepr.c */
