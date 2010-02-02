/* zxidspx.c  -  Handwritten functions for SP dispatch
 * Copyright (c) 2006-2009 Symlabs (symlabs@symlabs.com), All Rights Reserved.
 * Author: Sampo Kellomaki (sampo@iki.fi)
 * This is confidential unpublished proprietary source code of the author.
 * NO WARRANTY, not even implied warranties. Contains trade secrets.
 * Distribution prohibited unless authorized in writing.
 * Licensed under Apache License 2.0, see file COPYING.
 * $Id: zxidspx.c,v 1.14 2010-01-08 02:10:09 sampo Exp $
 *
 * 12.8.2006,  created --Sampo
 * 12.10.2007, tweaked for signing SLO and MNI --Sampo
 * 14.4.2008,  added SimpleSign --Sampo
 * 7.10.2008,  added documentation --Sampo
 * 22.8.2009,  added XACML dummy PDP support --Sampo
 * 15.11.2009, added discovery service Query --Sampo
 *
 * See also zxid/sg/wsf-soap11.sg and zxid/c/zx-e-data.h, which is generated.
 */

#include "errmac.h"
#include "zxid.h"
#include "zxidconf.h"
#include "saml2.h"
#include "c/zx-const.h"
#include "c/zx-ns.h"
#include "c/zx-data.h"

/* ============== Dispatch incoming requests and responses ============== */

/*() Extract an assertion, decrypting EncryptedAssertion if needed. */

/* Called by:  zxid_sp_dig_sso_a7n, zxid_sp_soap_dispatch */
struct zx_sa_Assertion_s* zxid_dec_a7n(struct zxid_conf* cf, struct zx_sa_Assertion_s* a7n, struct zx_sa_EncryptedAssertion_s* enca7n)
{
  struct zx_str* ss;
  struct zx_root_s* r;
  
  if (!a7n && enca7n) {
    ss = zxenc_privkey_dec(cf, enca7n->EncryptedData, enca7n->EncryptedKey);
    if (!ss || !ss->s || !ss->len) {
      return 0;
    }
    zx_prepare_dec_ctx(cf->ctx, zx_ns_tab, ss->s, ss->s + ss->len);
    r = zx_DEC_root(cf->ctx, 0, 1);
    if (!r) {
      ERR("Failed to parse EncryptedAssertion buf(%.*s)", ss->len, ss->s);
      zxlog(cf, 0, 0, 0, 0, 0, 0, 0, "N", "C", "BADXML", 0, "bad EncryptedAssertion");
      return 0;
    }
    a7n = r->Assertion;
  }
  return a7n;
}

/*() Extract an assertion from Request, decrypting EncryptedAssertion if needed, and perform SSO */

/* Called by:  zxid_idp_soap_dispatch, zxid_sp_dispatch, zxid_sp_soap_dispatch x3 */
static int zxid_sp_dig_sso_a7n(struct zxid_conf* cf, struct zxid_cgi* cgi, struct zxid_ses* ses, struct zx_sp_Response_s* resp)
{
  struct zx_sa_Assertion_s* a7n;

  if (!zxid_chk_sig(cf, cgi, ses, (struct zx_elem_s*)resp, resp->Signature, resp->Issuer, "Response"))
    return 0;
  
  a7n = zxid_dec_a7n(cf, resp->Assertion, resp->EncryptedAssertion);
  if (a7n)
    return zxid_sp_sso_finalize(cf, cgi, ses, a7n);
  if (cf->anon_ok && cgi->rs && !strcmp(cf->anon_ok, cgi->rs))  /* Prefix match */
    return zxid_sp_anon_finalize(cf, cgi, ses);
  ERR("No Assertion found and not anon_ok in SAML Response %d", 0);
  zxlog(cf, 0, 0, 0, 0, 0, 0, ses->nameid?ses->nameid->gg.content:0, "N", "C", "ERR", 0, "sid(%s) No assertion", ses->sid);
  return 0;
}

/*() Dispatch redirct or post binding requests (and sometimes responses).
 *
 * return:: a string (such as Location: header) and let the caller output it.
 *     Sometimes a dummy string is just output to indicate status, e.g.
 *     "O" for SSO OK, "K" for normal OK no further action needed,
 *     "M" show management screen, "I" forward to IdP dispatch, or
 *     "* ERR" for error situations. These special strings
 *     are allocated from static storage and MUST NOT be freed. Other
 *     strings such as "Location: ..." should be freed by caller. */

/* Called by:  main x3, zxid_mgmt, zxid_simple_no_ses_cf, zxid_simple_ses_active_cf */
struct zx_str* zxid_sp_dispatch(struct zxid_conf* cf, struct zxid_cgi* cgi, struct zxid_ses* ses)
{
  struct zx_sp_LogoutRequest_s* req;
  struct zxid_entity* idp_meta;
  struct zx_str* loc;
  struct zx_str* ss;
  struct zx_str* ss2;
  struct zx_root_s* r;
  int ret;

  ses->sigres = ZXSIG_NO_SIG;
  r = zxid_decode_redir_or_post(cf, cgi, ses, 1);
  if (!r)
    return zx_dup_str(cf->ctx, "* ERR");

  if (r->Response) {
    if (!zxid_saml_ok(cf, cgi, r->Response->Status, "SAMLresp"))
      return zx_dup_str(cf->ctx, "* ERR");
    ret = zxid_sp_dig_sso_a7n(cf, cgi, ses, r->Response);
    D("ret=%d", ret);
    switch (ret) {
    case ZXID_OK:     return zx_dup_str(cf->ctx, "K");
    case ZXID_SSO_OK: return zx_dup_str(cf->ctx, "O");
    case ZXID_FAIL:   D("*** FAIL, should send back to IdP select %d", 0);
    }
    return zx_dup_str(cf->ctx, "M");
  }
  
  if (req = r->LogoutRequest) {
    if (cf->idp_ena) {  /* *** Kludgy check */
      D("IdP SLO %d", 0);
      if (!zxid_idp_slo_do(cf, cgi, ses, req))
	return zx_dup_str(cf->ctx, "* ERR");
    } else {
      if (!zxid_sp_slo_do(cf, cgi, ses, req))
	return zx_dup_str(cf->ctx, "* ERR");
    }
    return zxid_slo_resp_redir(cf, cgi, req);    
  }
  
  if (r->LogoutResponse) {
    if (!zxid_saml_ok(cf, cgi, r->LogoutResponse->Status, "SLO resp"))
      return zx_dup_str(cf->ctx, "* ERR");
    cgi->msg = "Logout Response OK. Logged out.";
    zxid_del_ses(cf, ses);
    return zx_dup_str(cf->ctx, "K"); /* Prevent mgmt screen from displaying, show login screen. */
  }

  if (r->ManageNameIDRequest) {
    idp_meta = zxid_get_ent_ss(cf, r->ManageNameIDRequest->Issuer->gg.content);
    loc = zxid_idp_loc_raw(cf, cgi, idp_meta, ZXID_MNI_SVC, SAML2_REDIR, 0);
    if (!loc)
      return zx_dup_str(cf->ctx, "* ERR");  /* *** consider sending error page */
    ss = zxid_mni_do_ss(cf, cgi, ses, r->ManageNameIDRequest, loc);
    ss2 = zxid_saml2_resp_redir(cf, loc, ss, cgi->rs);
    zx_str_free(cf->ctx, loc);
    zx_str_free(cf->ctx, ss);
    return ss2;
  }
  
  if (r->ManageNameIDResponse) {
    if (!zxid_saml_ok(cf, cgi, r->ManageNameIDResponse->Status, "MNI resp")) {
      ERR("MNI Response indicates failure. %d", 0);
      return zx_dup_str(cf->ctx, "* ERR");
    }
    cgi->msg = "Manage NameID Response OK.";
    return zx_dup_str(cf->ctx, "M"); /* Defederation doesn't have to mean SLO, show mgmt screen. */
  }
  
  if (r->AuthnRequest) {
    D("AuthnRequest %d", 0);
    return zx_dup_str(cf->ctx, "I");
  }
  
  if (cf->log_level > 0)
    zxlog(cf, 0, 0, 0, 0, 0, 0, ses->nameid?ses->nameid->gg.content:0, "N", "C", "SPDISP", 0, "sid(%s) unknown req or resp", STRNULLCHK(ses->sid));
  ERR("Unknown request or response %p", r);
  return zx_dup_str(cf->ctx, "* ERR");
}

/*() Create Authorization Decision */

/* Called by:  zxid_xacml_az_do x2 */
static void zxid_ins_xacml_az_stmt(struct zxid_conf* cf, struct zx_sa_Assertion_s* a7n, char* deci)
{
  /* Two ways of doing assertion with XACMLAuthzDecisionStatement:
   * 1. Explicitly include such statement in assertion
   * 2. Use sa:Statement, but brandit with xsi:type
   * The former is more logical, but the latter is what Jericho does
   * and in effect the XACML interop events have done (de-facto standard?). */

#if 1
  a7n->XACMLAuthzDecisionStatement = zx_NEW_xasa_XACMLAuthzDecisionStatement(cf->ctx);
  a7n->XACMLAuthzDecisionStatement->Response = zxid_mk_xacml_resp(cf, deci);
  /* *** Add xaspcd1 and xasacd1 variants */
#else
  a7n->Statement = zx_NEW_sa_Statement(cf->ctx);
  a7n->Statement->type = zx_ref_str(cf->ctx, "xasa:XACMLAuthzDecisionStatementType");
  a7n->Statement->Response = zxid_mk_xacml_resp(cf, deci);
#endif
}

/*() Process <XACMLAuthzDecisionQuery>. The response will have
 * SAML assertion containing Authorization Decision Statement. */

/* Called by:  zxid_sp_soap_dispatch */
static struct zx_sp_Response_s* zxid_xacml_az_do(struct zxid_conf* cf, struct zxid_cgi* cgi, struct zxid_ses* ses, struct zx_xasp_XACMLAuthzDecisionQuery_s* azq)
{
  struct zx_sp_Response_s* resp;
  struct zx_sa_Assertion_s* a7n;
  struct zx_str* affil;
  struct zx_str* subj;
  struct zx_xac_Attribute_s* xac_at;
  
  if (!zxid_chk_sig(cf, cgi, ses, (struct zx_elem_s*)azq, azq->Signature, azq->Issuer, "XACMLAuthzDecisionQuery"))
    return 0;

  affil = subj = 0;
#if 0
  affil = ar->NameIDPolicy && ar->NameIDPolicy->SPNameQualifier
    ? ar->NameIDPolicy->SPNameQualifier
    : ar->Issuer->gg.content;
  subj = zxid_mk_subj(cf, ses, affil, sp_meta);
#endif
  //a7n = zxid_mk_a7n(cf, affil, subj, 0, 0, 0);
  a7n = zxid_mk_a7n(cf, affil, 0, 0, 0, 0);

  if (azq->Request && azq->Request->Subject) {
    for (xac_at = azq->Request->Subject->Attribute; xac_at; xac_at = (struct zx_xac_Attribute_s*)ZX_NEXT(xac_at)) {
      if (xac_at->AttributeId->len == sizeof("role")-1
	  && !memcmp(xac_at->AttributeId->s, "role", sizeof("role")-1)) {
	if (xac_at->AttributeValue && xac_at->AttributeValue->content
	    && xac_at->AttributeValue->content->len == sizeof("deny")-1
	    && !memcmp(xac_at->AttributeValue->content->s, "deny", sizeof("deny")-1)) {
	  D("PDP: Deny due to role=deny %d",0);
	  zxid_ins_xacml_az_stmt(cf, a7n, "Deny");
	  resp = zxid_mk_saml_resp(cf);
	  resp->Assertion = a7n;
	  return resp;
	}
      }
    }
  }
  zxid_ins_xacml_az_stmt(cf, a7n, "Permit");
  resp = zxid_mk_saml_resp(cf);
  resp->Assertion = a7n;
  return resp;
}

/*() SOAP dispatch can also handle requests and responses received via artifact
 * resolution. However only some combinations make sense.
 * See zxid/sg/wsf-soap11.sg for the master SOAP dispatch from parsing perspective.
 *
 * Return 0 for failure, otherwise some success code such as ZXID_SSO_OK */

/* Called by:  zxid_idp_soap_parse, zxid_sp_deref_art, zxid_sp_soap_parse */
int zxid_sp_soap_dispatch(struct zxid_conf* cf, struct zxid_cgi* cgi, struct zxid_ses* ses, struct zx_root_s* r)
{
  struct zxsig_ref refs;
  struct zx_e_Body_s* body;
  struct zx_sp_LogoutRequest_s* req;
  ses->sigres = ZXSIG_NO_SIG;

  if (!r) goto bad;
  if (!r->Envelope) goto bad;
  
  if (cf->log_level > 1)
    zxlog(cf, 0, 0, 0, 0, 0, 0, ses->nameid?ses->nameid->gg.content:0, "N", "W", "SPDISP", 0, "sid(%s) soap", STRNULLCHK(ses->sid));

  if (r->Envelope->Body->ArtifactResponse) {
    if (!zxid_saml_ok(cf, cgi, r->Envelope->Body->ArtifactResponse->Status, "ArtResp"))
      return 0;
    return zxid_sp_dig_sso_a7n(cf, cgi, ses, r->Envelope->Body->ArtifactResponse->Response);
  }

  if (r->Envelope->Body->Response) {    /* PAOS/ECP response */
    if (!zxid_saml_ok(cf, cgi, r->Envelope->Body->Response->Status, "PAOS Resp"))
      return 0;
    return zxid_sp_dig_sso_a7n(cf, cgi, ses, r->Envelope->Body->Response);
  }
  
  if (req = r->Envelope->Body->LogoutRequest) {
    if (!zxid_sp_slo_do(cf, cgi, ses, req))
      return 0;

    body = zx_NEW_e_Body(cf->ctx);
    body->LogoutResponse = zxid_mk_logout_resp(cf, zxid_OK(cf), req->ID);
    if (cf->sso_soap_resp_sign) {
      refs.id = body->LogoutResponse->ID;
      refs.canon = zx_EASY_ENC_SO_sp_LogoutResponse(cf->ctx, body->LogoutResponse);
      if (!cf->sign_cert) // Lazy load cert and private key
	cf->sign_cert = zxid_read_cert(cf, "sign-nopw-cert.pem");
      if (!cf->sign_pkey)
	cf->sign_pkey = zxid_read_private_key(cf, "sign-nopw-cert.pem");
      body->LogoutResponse->Signature = zxsig_sign(cf->ctx, 1, &refs, cf->sign_cert, cf->sign_pkey);
      zx_str_free(cf->ctx, refs.canon);
    }
    return zxid_soap_cgi_resp_body(cf, body);
  }

  if (r->Envelope->Body->ManageNameIDRequest) {
    struct zx_sp_ManageNameIDResponse_s* res;
    res = zxid_mni_do(cf, cgi, ses, r->Envelope->Body->ManageNameIDRequest);
    body = zx_NEW_e_Body(cf->ctx);
    body->ManageNameIDResponse = res;
    if (cf->sso_soap_resp_sign) {
      refs.id = res->ID;
      refs.canon = zx_EASY_ENC_SO_sp_ManageNameIDResponse(cf->ctx, res);
      if (!cf->sign_cert) // Lazy load cert and private key
	cf->sign_cert = zxid_read_cert(cf, "sign-nopw-cert.pem");
      if (!cf->sign_pkey)
	cf->sign_pkey = zxid_read_private_key(cf, "sign-nopw-cert.pem");
      res->Signature = zxsig_sign(cf->ctx, 1, &refs, cf->sign_cert, cf->sign_pkey);
      zx_str_free(cf->ctx, refs.canon);
    }
    return zxid_soap_cgi_resp_body(cf, body);
  }

  D("as_ena=%d %p", cf->as_ena, r->Envelope->Body->SASLRequest);
  if (cf->as_ena) {
    if (r->Envelope->Body->SASLRequest) {
      struct zx_as_SASLResponse_s* res;
      res = zxid_idp_as_do(cf, r->Envelope->Body->SASLRequest);
      body = zx_NEW_e_Body(cf->ctx);
      body->SASLResponse = res;
#if 0
      if (cf->sso_soap_resp_sign) {
	refs.id = res->ID;
	refs.canon = zx_EASY_ENC_SO_as_SASLResponse(cf->ctx, res);
	if (!cf->sign_cert) // Lazy load cert and private key
	  cf->sign_cert = zxid_read_cert(cf, "sign-nopw-cert.pem");
	if (!cf->sign_pkey)
	  cf->sign_pkey = zxid_read_private_key(cf, "sign-nopw-cert.pem");
	res->Signature = zxsig_sign(cf->ctx, 1, &refs, cf->sign_cert, cf->sign_pkey);
	zx_str_free(cf->ctx, refs.canon);
      }
#endif
      return zxid_soap_cgi_resp_body(cf, body);
    }
  }
  
  if (cf->idp_ena) {
    if (r->Envelope->Body->ArtifactResolve) {
      D("*** ArtifactResolve not implemented yet %d",0);
      //if (!zxid_saml_ok(cf, cgi, r->Envelope->Body->ArtifactResponse->Status, "ArtResp"))
      //  return 0;
      //return zxid_sp_dig_sso_a7n(cf, cgi, ses, r->Envelope->Body->ArtifactResponse->Response);
    }

    if (r->Envelope->Body->Query) { /* Discovery 2.0 Query */
      struct zx_sa_Assertion_s* a7n;
      struct zx_di_QueryResponse_s* di_resp;

      if (!r->Envelope->Header || !r->Envelope->Header->Security) {
	goto malformed;
      }

      a7n = zxid_dec_a7n(cf, r->Envelope->Header->Security->Assertion,
			 r->Envelope->Header->Security->EncryptedAssertion);
      di_resp = zxid_di_query(cf, a7n, r->Envelope->Body->Query);
      body = zx_NEW_e_Body(cf->ctx);
      body->QueryResponse = di_resp;
#if 0
      // *** should really sign the Body, putting sig in wsse:Security header
      if (cf->sso_soap_resp_sign) {
	refs.id = di_resp->ID;
	refs.canon = zx_EASY_ENC_SO_e_Body(cf->ctx, body);
	if (!cf->sign_cert) // Lazy load cert and private key
	  cf->sign_cert = zxid_read_cert(cf, "sign-nopw-cert.pem");
	if (!cf->sign_pkey)
	  cf->sign_pkey = zxid_read_private_key(cf, "sign-nopw-cert.pem");
	res->Signature = zxsig_sign(cf->ctx, 1, &refs, cf->sign_cert, cf->sign_pkey);
	zx_str_free(cf->ctx, refs.canon);
      }
#endif
      return zxid_soap_cgi_resp_body(cf, body);
    }
  }
  
  if (cf->pdp_ena) {
    if (r->Envelope->Body->XACMLAuthzDecisionQuery) {
      struct zx_sp_Response_s* res;
      D("XACMLAuthzDecisionQuery %d",0);
      res = zxid_xacml_az_do(cf, cgi, ses, r->Envelope->Body->XACMLAuthzDecisionQuery);
      body = zx_NEW_e_Body(cf->ctx);
      body->Response = res;
      if (cf->sso_soap_resp_sign) {
	refs.id = res->ID;
	refs.canon = zx_EASY_ENC_SO_sp_Response(cf->ctx, res);
	if (!cf->sign_cert) // Lazy load cert and private key
	  cf->sign_cert = zxid_read_cert(cf, "sign-nopw-cert.pem");
	if (!cf->sign_pkey)
	  cf->sign_pkey = zxid_read_private_key(cf, "sign-nopw-cert.pem");
	res->Signature = zxsig_sign(cf->ctx, 1, &refs, cf->sign_cert, cf->sign_pkey);
	zx_str_free(cf->ctx, refs.canon);
      }
      return zxid_soap_cgi_resp_body(cf, body);
    }
  }
  
 bad:
  ERR("Unknown soap request %p", r);
  if (cf->log_level > 0)
    zxlog(cf, 0, 0, 0, 0, 0, 0, ses->nameid?ses->nameid->gg.content:0, "N", "C", "SPDISP", 0, "sid(%s) unknown soap req", STRNULLCHK(ses->sid));
  return 0;
 malformed:
  ERR("Malformed soap request %p", r);
  if (cf->log_level > 0)
    zxlog(cf, 0, 0, 0, 0, 0, 0, ses->nameid?ses->nameid->gg.content:0, "N", "C", "SPDISP", 0, "sid(%s) malformed soap req", STRNULLCHK(ses->sid));
  return 0;
}

/*() Return 0 for failure, otherwise some success code such as ZXID_SSO_OK */

/* Called by:  chkuid, main x6, zxid_simple_cf_ses */
int zxid_sp_soap_parse(struct zxid_conf* cf, struct zxid_cgi* cgi, struct zxid_ses* ses, int len, char* buf)
{
  struct zx_root_s* r;
  zx_prepare_dec_ctx(cf->ctx, zx_ns_tab, buf, buf + len);
  r = zx_DEC_root(cf->ctx, 0, 1);
  if (!r || !r->Envelope || !r->Envelope->Body) {
    ERR("Failed to parse SOAP request buf(%.*s)", len, buf);
    zxlog(cf, 0, 0, 0, 0, 0, 0, ses->nameid?ses->nameid->gg.content:0, "N", "C", "BADXML", 0, "sid(%s) bad soap req", STRNULLCHK(ses->sid));
    return 0;
  }
  return zxid_sp_soap_dispatch(cf, cgi, ses, r);
}

/* EOF  --  zxidspx.c */
