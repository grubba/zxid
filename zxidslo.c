/* zxidslo.c  -  Handwritten functions for implementing Single LogOut logic for SP
 * Copyright (c) 2006-2009 Symlabs (symlabs@symlabs.com), All Rights Reserved.
 * Author: Sampo Kellomaki (sampo@iki.fi)
 * This is confidential unpublished proprietary source code of the author.
 * NO WARRANTY, not even implied warranties. Contains trade secrets.
 * Distribution prohibited unless authorized in writing.
 * Licensed under Apache License 2.0, see file COPYING.
 * $Id: zxidslo.c,v 1.42 2010-01-08 02:10:09 sampo Exp $
 *
 * 12.8.2006,  created --Sampo
 * 12.10.2007, tweaked for signing SLO and MNI --Sampo
 * 14.4.2008,  added SimpleSign --Sampo
 * 7.10.2008,  added documentation --Sampo
 */

#include "errmac.h"
#include "zxid.h"
#include "zxidconf.h"
#include "saml2.h"
#include "c/zx-const.h"
#include "c/zx-ns.h"
#include "c/zx-data.h"

/* ============== Single Logout ============== */

/*(i) SOAP client for sending Single Logout to IdP. The SOAP call is made
 * using CURL HTTP Client and will block until response is received.
 *
 * return:: 1 if successful. 0 upon failure. */

/* Called by:  zxid_mgmt, zxid_simple_ses_active_cf */
int zxid_sp_slo_soap(struct zxid_conf* cf, struct zxid_cgi* cgi, struct zxid_ses* ses)
{
  zxid_get_ses_sso_a7n(cf, ses);  
  if (ses->a7n) {
    struct zxsig_ref refs;
    struct zx_root_s* r;
    struct zx_e_Body_s* body;
    struct zx_str* ses_ix;
    struct zxid_entity* idp_meta;
    
    ses_ix = ses->a7n->AuthnStatement?ses->a7n->AuthnStatement->SessionIndex:0;
    if (cf->log_level>0)
      zxlog(cf, 0, 0, 0, 0, 0, 0, ses->nameid?ses->nameid->gg.content:0, "N", "W", "SLOSOAP", ses->sid, "sesix(%.*s)", ses_ix?ses_ix->len:1, ses_ix?ses_ix->s:"?");
    
    idp_meta = zxid_get_ses_idp(cf, ses);
    if (!idp_meta)
      return 0;
    
    body = zx_NEW_e_Body(cf->ctx);
    body->LogoutRequest = zxid_mk_logout(cf, zxid_get_user_nameid(cf, ses->nameid), ses_ix, idp_meta);
    if (cf->sso_soap_sign) {
      refs.id = body->LogoutRequest->ID;
      refs.canon = zx_EASY_ENC_SO_sp_LogoutRequest(cf->ctx, body->LogoutRequest);
      if (!cf->sign_cert) // Lazy load cert and private key
	cf->sign_cert = zxid_read_cert(cf, "sign-nopw-cert.pem");
      if (!cf->sign_pkey)
	cf->sign_pkey = zxid_read_private_key(cf, "sign-nopw-cert.pem");
      body->LogoutRequest->Signature = zxsig_sign(cf->ctx, 1, &refs, cf->sign_cert, cf->sign_pkey);
      zx_str_free(cf->ctx, refs.canon);
    }
    r = zxid_idp_soap(cf, cgi, ses, idp_meta, ZXID_SLO_SVC, body);
    if (!zxid_saml_ok(cf, cgi, r->Envelope->Body->LogoutResponse->Status, "LogoutResp"))
      return 0;
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

/*(i) Send Single Logout to IdP using redirect binding. This function
 * generates the URL encapsulating the request. You need to pass this
 * URL to the appropriate function in your environment to provoke
 * an HTTP 302 redirect.
 *
 * cf:: ZXID config object, also used for memory allocation
 * cgi:: Data parsed from POST or query string. Provides parameters to determine
 *     details of the SLO request
 * ses:: Session object. Used to determine session index (~ses_ix~) and name id, among others
 * return:: location string if successful. "* ERR" upon failure. */

/* Called by:  zxid_mgmt, zxid_simple_ses_active_cf */
struct zx_str* zxid_sp_slo_redir(struct zxid_conf* cf, struct zxid_cgi* cgi, struct zxid_ses* ses)
{
  zxid_get_ses_sso_a7n(cf, ses);
  if (ses->a7n) {
    struct zx_sp_LogoutRequest_s* r;
    struct zx_str* rs;
    struct zx_str* loc;
    struct zxid_entity* idp_meta;
    struct zx_str* ses_ix;

    ses_ix = ses->a7n->AuthnStatement?ses->a7n->AuthnStatement->SessionIndex:0;
    if (cf->log_level>0)
      zxlog(cf, 0, 0, 0, 0, 0, 0, ses->nameid?ses->nameid->gg.content:0, "N", "W", "SLOREDIR", ses->sid, "sesix(%.*s)", ses_ix?ses_ix->len:1, ses_ix?ses_ix->s:"?");
    
    idp_meta = zxid_get_ses_idp(cf, ses);
    if (!idp_meta)
      return zx_dup_str(cf->ctx, "* ERR");

    loc = zxid_idp_loc(cf, cgi, ses, idp_meta, ZXID_SLO_SVC, SAML2_REDIR);
    if (!loc)
      return zx_dup_str(cf->ctx, "* ERR");
    r = zxid_mk_logout(cf, zxid_get_user_nameid(cf, ses->nameid), ses_ix, idp_meta);
    r->Destination = loc;
    rs = zx_EASY_ENC_SO_sp_LogoutRequest(cf->ctx, r);
    D("SLO(%.*s)", rs->len, rs->s);
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

/*() Generate SLO Response, SP or IdP variant. The actual session invalidation must be
 * done somewhere else, i.e. this is just the final protocol phase of the SLO. */

/* Called by:  zxid_idp_dispatch, zxid_sp_dispatch */
struct zx_str* zxid_slo_resp_redir(struct zxid_conf* cf, struct zxid_cgi* cgi, struct zx_sp_LogoutRequest_s* req)
{
  struct zx_sp_LogoutResponse_s* res;
  struct zxid_entity* meta;
  struct zx_str* loc;
  struct zx_str* ss;
  struct zx_str* ss2;

  meta = zxid_get_ent_ss(cf, req->Issuer->gg.content);
  loc = zxid_idp_loc_raw(cf, cgi, meta, ZXID_SLO_SVC, SAML2_REDIR, 0);
  if (!loc)
    loc = zxid_sp_loc_raw(cf, cgi, meta, ZXID_SLO_SVC, SAML2_REDIR, 0);
  if (!loc)
    return zx_dup_str(cf->ctx, "* ERR");  /* *** consider sending error page */

  zxlog(cf, 0, 0, 0, 0, 0, 0, 0, "N", "W", "SLORESREDIR", 0, "");

  res = zxid_mk_logout_resp(cf, zxid_OK(cf), req->ID);
  res->Destination = loc;
  ss = zx_EASY_ENC_SO_sp_LogoutResponse(cf->ctx, res);
  ss2 = zxid_saml2_resp_redir(cf, loc, ss, cgi->rs);
  /*zx_str_free(cf->ctx, loc); Do NOT free loc as it is still referenced by the metadata. */
  zx_str_free(cf->ctx, ss);
  return ss2;
}

/*() Process SP SLO request. */

/* Called by:  zxid_idp_dispatch, zxid_sp_dispatch, zxid_sp_soap_dispatch */
int zxid_sp_slo_do(struct zxid_conf* cf, struct zxid_cgi* cgi, struct zxid_ses* ses, struct zx_sp_LogoutRequest_s* req)
{
  if (!zxid_chk_sig(cf, cgi, ses, (struct zx_elem_s*)req, req->Signature, req->Issuer, "LogoutRequest"))
    return 0;

  req->NameID = zxid_decrypt_nameid(cf, req->NameID, req->EncryptedID);
  if (!req->NameID || !req->NameID->gg.content) {
    ERR("SLO failed: request does not have NameID. %p", req->NameID);
    return 0;
  }
  zxid_find_ses(cf, ses, req->SessionIndex?req->SessionIndex->content:0, req->NameID->gg.content);
  zxid_del_ses(cf, ses);
  return 1;
}

/*() Process IdP SLO request. The IdP SLO Requests are complicated by the need
 * to log the user out of other SPs as well, if they belong to same session.
 * Part of the complication is figuring out what constitutes "same session".
 * Finally, the redirect profiles may be "hairy" to handle if some SP does
 * not collaborate in the SLO. For SOAP similar problem exists, but it should be
 * manageable. */

/* Called by:  zxid_idp_dispatch, zxid_idp_soap_dispatch, zxid_sp_dispatch */
int zxid_idp_slo_do(struct zxid_conf* cf, struct zxid_cgi* cgi, struct zxid_ses* ses, struct zx_sp_LogoutRequest_s* req)
{
  if (!zxid_chk_sig(cf, cgi, ses, (struct zx_elem_s*)req, req->Signature, req->Issuer, "LogoutRequest"))
    return 0;

  req->NameID = zxid_decrypt_nameid(cf, req->NameID, req->EncryptedID);
  if (!req->NameID || !req->NameID->gg.content) {
    ERR("SLO failed: request does not have NameID. %p", req->NameID);
    return 0;
  }
  if (zxid_find_ses(cf, ses, req->SessionIndex?req->SessionIndex->content:0, 0 /*req->NameID->gg.content*/))
    zxid_del_ses(cf, ses);
  return 1;
}

/* EOF  --  zxidslo.c */