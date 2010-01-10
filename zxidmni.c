/* zxidmni.c  -  Handwritten functions for NameID Management logic for SP
 * Copyright (c) 2006-2009 Symlabs (symlabs@symlabs.com), All Rights Reserved.
 * Author: Sampo Kellomaki (sampo@iki.fi)
 * This is confidential unpublished proprietary source code of the author.
 * NO WARRANTY, not even implied warranties. Contains trade secrets.
 * Distribution prohibited unless authorized in writing.
 * Licensed under Apache License 2.0, see file COPYING.
 * $Id: zxidmni.c,v 1.10 2010-01-08 02:10:09 sampo Exp $
 *
 * 12.10.2007, split from zxidslo.c --Sampo
 * 7.10.2008,  added documentation --Sampo
 */

#include "errmac.h"
#include "zxid.h"
#include "zxidconf.h"
#include "saml2.h"
#include "c/zx-const.h"
#include "c/zx-ns.h"
#include "c/zx-data.h"

/* ============== MNI / NID Mgmt / Defederation ============== */

/*() Change SPNameID (newnym supplied), or Terminate federation (newnym not supplied),
 * using SAML2 SOAP binding. This is the (SP) client side that contacts the IdP. */

/* Called by:  zxid_mgmt, zxid_simple_ses_active_cf */
int zxid_sp_mni_soap(struct zxid_conf* cf, struct zxid_cgi* cgi, struct zxid_ses* ses, struct zx_str* new_nym)
{
  zxid_get_ses_sso_a7n(cf, ses);
  if (ses->a7n) {
    struct zxsig_ref refs;
    struct zx_root_s* r;
    struct zx_e_Body_s* body;
    struct zxid_entity* idp_meta;

    if (cf->log_level>0)
      zxlog(cf, 0, 0, 0, 0, 0, 0, ses->nameid?ses->nameid->gg.content:0, "N", "W", "MNISOAP", ses->sid, "newnym(%.*s) loc", new_nym?new_nym->len:0, new_nym?new_nym->s:"");
    
    idp_meta = zxid_get_ses_idp(cf, ses);
    if (!idp_meta)
      return 0;

    body = zx_NEW_e_Body(cf->ctx);
    body->ManageNameIDRequest = zxid_mk_mni(cf, zxid_get_user_nameid(cf, ses->nameid), new_nym, idp_meta);
    if (cf->sso_soap_sign) {
      refs.id = body->ManageNameIDRequest->ID;
      refs.canon = zx_EASY_ENC_SO_sp_ManageNameIDRequest(cf->ctx, body->ManageNameIDRequest);
      if (!cf->sign_cert) // Lazy load cert and private key
	cf->sign_cert = zxid_read_cert(cf, "sign-nopw-cert.pem");
      if (!cf->sign_pkey)
	cf->sign_pkey = zxid_read_private_key(cf, "sign-nopw-cert.pem");
      body->ManageNameIDRequest->Signature = zxsig_sign(cf->ctx, 1, &refs, cf->sign_cert, cf->sign_pkey);
      zx_str_free(cf->ctx, refs.canon);
    }
    r = zxid_idp_soap(cf, cgi, ses, idp_meta, ZXID_MNI_SVC, body);
    if (!zxid_saml_ok(cf, cgi, r->Envelope->Body->ManageNameIDResponse->Status, "MniResp"))
      return 0;
    /* *** Take actual steps to terminate the federation or change the name IDs */
    return 1;
  }
  if (ses->a7n11) {
    ERR("Not implemented, SAML 1.1 assetion %d", 0);
  }
  if (ses->a7n12) {
    ERR("Not implemented, ID-FF 1.2 type SAML 1.1 assetion %d", 0);
  }
  ERR("Session sid(%s) lacks SSO assertion.", ses->sid);
  return 0;
}

/*() Change SPNameID (newnym supplied), or Terminate federation (newnym not supplied),
 * using SAML2 HTTP redirect binding. This is the (SP) client side that contacts the IdP.
 * Return the HTTP 302 redirect LOCATION header + CRLF2. Returns the URL as string to which
 * the environment should cause the user (browser) to be redirected. */

/* Called by:  zxid_mgmt, zxid_simple_ses_active_cf */
struct zx_str* zxid_sp_mni_redir(struct zxid_conf* cf, struct zxid_cgi* cgi, struct zxid_ses* ses, struct zx_str* new_nym)
{
  zxid_get_ses_sso_a7n(cf, ses);
  if (ses->a7n) {
    struct zx_sp_ManageNameIDRequest_s* r;
    struct zx_str* rs;
    struct zx_str* loc;
    struct zxid_entity* idp_meta;

    if (cf->log_level>0)
      zxlog(cf, 0, 0, 0, 0, 0, 0, ses->nameid?ses->nameid->gg.content:0, "N", "W", "MNIREDIR", ses->sid, "newnym(%.*s)", new_nym?new_nym->len:0, new_nym?new_nym->s:"");
    
    idp_meta = zxid_get_ses_idp(cf, ses);
    if (!idp_meta)
      return zx_dup_str(cf->ctx, "* ERR");

    loc = zxid_idp_loc(cf, cgi, ses, idp_meta, ZXID_MNI_SVC, SAML2_REDIR);
    if (!loc)
      return zx_dup_str(cf->ctx, "* ERR");
    r = zxid_mk_mni(cf, zxid_get_user_nameid(cf, ses->nameid), new_nym, 0);
    r->Destination = loc;
    rs = zx_EASY_ENC_SO_sp_ManageNameIDRequest(cf->ctx, r);
    D("NIReq(%.*s)", rs->len, rs->s);
    return zxid_saml2_redir(cf, loc, rs, 0);
  }
  if (ses->a7n11) {
    ERR("Not implemented, SAML 1.1 assetion %d", 0);
  }
  if (ses->a7n12) {
    ERR("Not implemented, ID-FF 1.2 type SAML 1.1 assetion %d", 0);
  }
  ERR("Session sid(%s) lacks SSO assertion.", ses->sid);
  return zx_dup_str(cf->ctx, "* ERR");
}

/*() Process <ManageNameIDRequest>, presumably received from IdP. This is very rarely
 * used. */

/* Called by:  zxid_idp_soap_dispatch, zxid_mni_do_ss, zxid_sp_soap_dispatch */
struct zx_sp_ManageNameIDResponse_s* zxid_mni_do(struct zxid_conf* cf, struct zxid_cgi* cgi, struct zxid_ses* ses, struct zx_sp_ManageNameIDRequest_s* mni)
{
  struct zx_sa_NameID_s* nid;
  struct zx_str* newnym;
  
  if (!zxid_chk_sig(cf, cgi, ses, (struct zx_elem_s*)mni, mni->Signature, mni->Issuer, "ManageNameIDRequest"))
    return 0;
  
  nid = zxid_decrypt_nameid(cf, mni->NameID, mni->EncryptedID);
  if (!nid || !nid->gg.content) {
    ERR("MNI failed: request does not have NameID. %p", nid);
    return 0;
  }
  
  newnym = zxid_decrypt_newnym(cf, mni->NewID?mni->NewID->content:0, mni->NewEncryptedID);
  if (!newnym) {
    D("MNI Terminate %d",0);
  } else {
    D("MNI Change newnym(%.*s)", newnym->len, newnym->s);
    zxid_user_change_nameid(cf, nid, newnym);
  }
  return zxid_mk_mni_resp(cf, zxid_OK(cf), mni->ID);
}

/*() Wrapper for zxid_mni_do(), which see. */

/* Called by:  zxid_idp_dispatch, zxid_sp_dispatch */
struct zx_str* zxid_mni_do_ss(struct zxid_conf* cf, struct zxid_cgi* cgi, struct zxid_ses* ses, struct zx_sp_ManageNameIDRequest_s* mni, struct zx_str* loc)
{
  struct zx_sp_ManageNameIDResponse_s* res;
  res = zxid_mk_mni_resp(cf, zxid_OK(cf), mni->ID);
  res = zxid_mni_do(cf, cgi, ses, mni);
  res->Destination = loc;
  return zx_EASY_ENC_SO_sp_ManageNameIDResponse(cf->ctx, res);
}

/* EOF  --  zxidmni.c */
