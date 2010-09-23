/* zxidps.c  -  People Service
 * Copyright (c) 2010 Sampo Kellomaki (sampo@iki.fi), All Rights Reserved.
 * Copyright (c) 2010 Risaris Ltd, All Rights Reserved.
 * Author: Sampo Kellomaki (sampo@iki.fi)
 * This is confidential unpublished proprietary source code of the author.
 * NO WARRANTY, not even implied warranties. Contains trade secrets.
 * Distribution prohibited unless authorized in writing.
 * Licensed under Apache License 2.0, see file COPYING.
 * $Id: zxiddi.c,v 1.2 2009-11-24 23:53:40 sampo Exp $
 *
 * 16.9.2010, created --Sampo
 *
 * See also zxcall for client
 * - liberty-idwsf-overview-v2.0.pdf sec 2.3 and 2.4 (pp.15-31) for use cases
 * - liberty-idwsf-people-service-v1.0.pdf, sec 4.4 Elements Supporting Invitation (pp.53-57)
 *
 *  zxcot -e http://idp.tas3.pt:8081/zxididp?o=S 'People Svc' \
 *    http://idp.tas3.pt:8081/zxididp?o=B urn:liberty:ps:2006-08 \
 *  | zxcot -b /var/zxid/idpdimd
 */

#include "platform.h"  /* for dirent.h */
#include "errmac.h"
#include "zxid.h"
#include "zxidconf.h"
#include "saml2.h"
#include "wsf.h"
#include "c/zx-const.h"
#include "c/zx-ns.h"
#include "c/zx-data.h"

/*() Add an entity to buddy store, obtain an invitation token. */

/* Called by:  zxid_sp_soap_dispatch */
struct zx_ps_AddEntityResponse_s* zxid_ps_addent_invite(zxid_conf* cf, zxid_a7n* a7n, struct zx_ps_AddEntityRequest_s* req)
{
  // ***
  return 0;
}

/*() Resolve an invitation token to identity */

/* Called by:  zxid_sp_soap_dispatch */
struct zx_ps_ResolveIdentifierResponse_s* zxid_ps_resolv_id(zxid_conf* cf, zxid_a7n* a7n, struct zx_ps_ResolveIdentifierRequest_s* req)
{
  zxid_nid* nameid;
  struct zx_ps_ResolveIdentifierResponse_s* resp = zx_NEW_ps_ResolveIdentifierResponse(cf->ctx);
  struct zx_ps_ResolveInput_s* inp;
  struct zx_ps_ResolveOutput_s* out;
  int len, n_resolv = 0;
  char uid[ZXID_MAX_BUF];
  char sp_name_buf[1024];
  struct zx_str* affil;
  D_INDENT("ps_resolv: ");

  //resp->ID = zxid_mk_id(cf, "DIR", ZXID_ID_BITS);
  
  if (!a7n || !a7n->Subject) {
    ERR("Malformed Assertion(%p): Subject missing.", a7n);
    resp->Status = zxid_mk_lu_Status(cf, "Fail", 0, 0, 0);
    D_DEDENT("ps_resolv: ");
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
    D_DEDENT("ps_resolv: ");
    return resp;
  }

  for (inp = req->ResolveInput; inp; inp = (struct zx_ps_ResolveInput_s*)inp->gg.g.n) {
    // ***
  }

  zxlog(cf, 0, 0, 0, 0, 0, a7n->ID, nameid->gg.content, "N", "K", "PSRESOLVOK", 0, "n=%d", n_resolv);
  resp->Status = zxid_mk_lu_Status(cf, "OK", 0, 0, 0);
  D_DEDENT("ps_resolv: ");
  return resp;
}

/* EOF  --  zxidps.c */
