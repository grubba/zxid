/* zxidmk.c  -  Handwritten nitty-gritty functions for constructing various elems
 * Copyright (c) 2006-2009 Symlabs (symlabs@symlabs.com), All Rights Reserved.
 * Author: Sampo Kellomaki (sampo@iki.fi)
 * This is confidential unpublished proprietary source code of the author.
 * NO WARRANTY, not even implied warranties. Contains trade secrets.
 * Distribution prohibited unless authorized in writing.
 * Licensed under Apache License 2.0, see file COPYING.
 * $Id: zxidmk.c,v 1.27 2009-11-24 23:53:40 sampo Exp $
 *
 * 12.8.2006, created --Sampo
 * 8.10.2007, added signing ArtifactResolve --Sampo
 * 7.10.2008, added documentation --Sampo
 * 24.8.2009, added XACML stuff --Sampo
 */

#include "errmac.h"
#include "zxid.h"
#include "zxidconf.h"
#include "saml2.h"
#include "c/zx-const.h"
#include "c/zx-ns.h"
#include "c/zx-data.h"

/*() Interpret ZXID standard form fields to construct a XML structure for AuthnRequest */

/* Called by:  zxid_lecp_check, zxid_start_sso_url */
struct zx_sp_AuthnRequest_s* zxid_mk_authn_req(zxid_conf* cf, zxid_cgi* cgi)
{
  char index[2] = "1";
  struct zx_sp_AuthnRequest_s* ar = zx_NEW_sp_AuthnRequest(cf->ctx);
  ar->Issuer = zxid_my_issuer(cf);
  ar->ID = zxid_mk_id(cf, "N", ZXID_ID_BITS);
  ar->Version = zx_ref_str(cf->ctx, SAML2_VERSION);
  ar->IssueInstant = zxid_date_time(cf, time(0));
  if (cf->nice_name && cf->nice_name[0])  ar->ProviderName = zx_ref_str(cf->ctx, cf->nice_name);
  if (BOOL_STR_TEST(cgi->force_authn))    ar->ForceAuthn = zx_ref_str(cf->ctx, ZXID_TRUE);
  if (BOOL_STR_TEST(cgi->ispassive))      ar->IsPassive = zx_ref_str(cf->ctx, ZXID_TRUE);
  if (cgi->consent && cgi->consent[0])    ar->Consent = zx_ref_str(cf->ctx, cgi->consent);
  D("nid_fmt(%s) allow_create=%c ispassive=%c", cgi->nid_fmt, cgi->allow_create, cgi->ispassive);
  if (cgi->nid_fmt && cgi->nid_fmt[0] || cgi->affil && cgi->affil[0]
      || BOOL_STR_TEST(cgi->allow_create)) {
    ar->NameIDPolicy = zx_NEW_sp_NameIDPolicy(cf->ctx);
    if (cgi->nid_fmt && cgi->nid_fmt[0])
      ar->NameIDPolicy->Format = zx_ref_str(cf->ctx, zxid_saml2_map_nid_fmt(cgi->nid_fmt));
    if (cgi->affil && cgi->affil[0])
      ar->NameIDPolicy->SPNameQualifier = zx_ref_str(cf->ctx, cgi->affil);
    if (BOOL_STR_TEST(cgi->allow_create))
      ar->NameIDPolicy->AllowCreate = zx_ref_str(cf->ctx, ZXID_TRUE);  /* default false */
  }
  if (cgi->authn_ctx && cgi->authn_ctx[0]) {
    ar->RequestedAuthnContext = zx_NEW_sp_RequestedAuthnContext(cf->ctx);
    ar->RequestedAuthnContext->AuthnContextClassRef
      = zx_ref_simple_elem(cf->ctx, zxid_saml2_map_authn_ctx(cgi->authn_ctx));
    if (cgi->matching_rule && cgi->matching_rule[0])
      ar->RequestedAuthnContext->Comparison = zx_ref_str(cf->ctx, cgi->matching_rule);
  }
  if (cgi->pr_ix && cgi->pr_ix != '0') {
    index[0] = cgi->pr_ix;
    ar->AssertionConsumerServiceIndex = zx_dup_str(cf->ctx, index);
  }
  if (cgi->get_complete && cgi->get_complete[0]
      || cgi->pxy_count && cgi->pxy_count[0]
      || cgi->idppxylist && cgi->idppxylist[0]) {
    ar->Scoping = zx_NEW_sp_Scoping(cf->ctx);
    if (cgi->pxy_count && cgi->pxy_count[0])
      ar->Scoping->ProxyCount = zx_ref_str(cf->ctx, cgi->pxy_count);
#if 0
    if (cgi->get_complete && cgi->get_complete[0] || cgi->idppxylist) {
      ar->Scoping->IDPList = zx_NEW_sp_IDPList(cf->ctx);
      /* *** Add IDPEntry and GetComplete */
    }
#endif
  }
  return ar;
}

/*() Make the body for the ArtifactResolve SOAP message, signing it if needed. */

/* Called by:  zxid_sp_deref_art */
struct zx_sp_ArtifactResolve_s* zxid_mk_art_deref(zxid_conf* cf, zxid_entity* idp_meta, char* artifact)
{
  X509* sign_cert;
  RSA*  sign_pkey;
  struct zxsig_ref refs;
  struct zx_sp_ArtifactResolve_s* ar = zx_NEW_sp_ArtifactResolve(cf->ctx);
  ar->Issuer = zxid_my_issuer(cf);
  ar->ID = zxid_mk_id(cf, "R", ZXID_ID_BITS);
  ar->Version = zx_ref_str(cf->ctx, SAML2_VERSION);
  ar->IssueInstant = zxid_date_time(cf, time(0));
  ar->Artifact = zx_ref_simple_elem(cf->ctx, artifact);
  if (cf->sso_soap_sign) {
    refs.id = ar->ID;
    refs.canon = zx_EASY_ENC_SO_sp_ArtifactResolve(cf->ctx, ar);
    if (zxid_lazy_load_sign_cert_and_pkey(cf, &sign_cert, &sign_pkey, "use sign cert art deref"))
      ar->Signature = zxsig_sign(cf->ctx, 1, &refs, sign_cert, sign_pkey);
    zx_str_free(cf->ctx, refs.canon);
  }
  return ar;
}

/*() Create SAML protocol <Status> element, given various levels of error input. */

/* Called by:  zxid_OK */
struct zx_sp_Status_s* zxid_mk_Status(zxid_conf* cf, char* sc1, char* sc2, char* msg)
{
  struct zx_sp_Status_s* st = zx_NEW_sp_Status(cf->ctx);
  if (msg)
    st->StatusMessage = zx_ref_simple_elem(cf->ctx, msg);
  st->StatusCode = zx_NEW_sp_StatusCode(cf->ctx);
  st->StatusCode->Value = zx_ref_str(cf->ctx, sc1);
  if (sc2) {
    st->StatusCode->StatusCode = zx_NEW_sp_StatusCode(cf->ctx);
    st->StatusCode->StatusCode->Value = zx_ref_str(cf->ctx, sc2);
  }
  return st;
}

/*() Create SAML <Status> element indicating success. */

/* Called by:  zxid_idp_soap_dispatch, zxid_mk_saml_resp, zxid_mni_do, zxid_mni_do_ss, zxid_slo_resp_redir, zxid_sp_soap_dispatch */
struct zx_sp_Status_s* zxid_OK(zxid_conf* cf)
{
  return zxid_mk_Status(cf, SAML2_SC_SUCCESS, 0, 0);
}

/*() Create EncryptedID given normal NameID and metadata of destination. Encryption
 * will be done using encryption certificate of the receiver identified by the metadata. */

/* Called by:  zxid_mk_logout, zxid_mk_mni, zxid_mk_subj */
struct zx_sa_EncryptedID_s* zxid_mk_enc_id(zxid_conf* cf, zxid_nid* nid, zxid_entity* meta)
{
  struct zx_sa_EncryptedID_s* encid = zx_NEW_sa_EncryptedID(cf->ctx);
  struct zx_str* ss = zx_EASY_ENC_SO_sa_NameID(cf->ctx, nid);
  if (cf->enckey_opt & 0x20) {
    /* Nested EncryptedKey approach (Shibboleth early 2010) */
    encid->EncryptedData = zxenc_pubkey_enc(cf, ss, 0, meta->enc_cert, "41", 0);
  } else {
    /* RetrievalMethod approach */
    encid->EncryptedData = zxenc_pubkey_enc(cf, ss, &encid->EncryptedKey, meta->enc_cert, "38", meta);
  }
  zx_str_free(cf->ctx, ss);
  return encid;
}

/*() Create EncryptedAssertion given normal A7N and metadata of destination. Encryption
 * will be done using encryption certificate of the receiver identified by the metadata. */

/* Called by:  zxid_add_fed_tok_to_epr, zxid_idp_sso x4 */
struct zx_sa_EncryptedAssertion_s* zxid_mk_enc_a7n(zxid_conf* cf, zxid_a7n* a7n, zxid_entity* meta)
{
  struct zx_sa_EncryptedAssertion_s* enc_a7n = zx_NEW_sa_EncryptedAssertion(cf->ctx);
  struct zx_str* ss = zx_EASY_ENC_SO_sa_Assertion(cf->ctx, a7n);
  if (cf->enckey_opt & 0x20) {
    /* Nested EncryptedKey approach (Shibboleth early 2010) */
    enc_a7n->EncryptedData = zxenc_pubkey_enc(cf, ss, 0, meta->enc_cert, "40", 0);
  } else {
    /* RetrievalMethod approach */
    enc_a7n->EncryptedData = zxenc_pubkey_enc(cf, ss, &enc_a7n->EncryptedKey, meta->enc_cert, "39", meta);
  }
  zx_str_free(cf->ctx, ss);
  return enc_a7n;
}

/*() Create XML data structure for <LogoutRequest> element. Low level API. */

/* Called by:  test_ibm_cert_problem_enc_dec, zxid_sp_slo_redir, zxid_sp_slo_soap */
struct zx_sp_LogoutRequest_s* zxid_mk_logout(zxid_conf* cf, zxid_nid* nid, struct zx_str* ses_ix, zxid_entity* idp_meta)
{
  struct zx_sp_LogoutRequest_s* r = zx_NEW_sp_LogoutRequest(cf->ctx);
  r->Issuer = zxid_my_issuer(cf);
  r->ID = zxid_mk_id(cf, "L", ZXID_ID_BITS);
  r->Version = zx_ref_str(cf->ctx, SAML2_VERSION);
  r->IssueInstant = zxid_date_time(cf, time(0));

  D("nameid_enc(%d) idp_meta(%p) enc_cert(%p)", cf->nameid_enc, idp_meta, idp_meta->enc_cert);
  if (cf->nameid_enc && idp_meta)
    r->EncryptedID = zxid_mk_enc_id(cf, nid, idp_meta);
  else
    r->NameID = nid;
  if (ses_ix)
    r->SessionIndex = zx_new_simple_elem(cf->ctx, ses_ix);
  return r;
}

/*() Create XML data structure for <LogoutResponse> element. Low level API. */

/* Called by:  zxid_idp_soap_dispatch, zxid_slo_resp_redir, zxid_sp_soap_dispatch */
struct zx_sp_LogoutResponse_s* zxid_mk_logout_resp(zxid_conf* cf, struct zx_sp_Status_s* st, struct zx_str* req_id)
{
  struct zx_sp_LogoutResponse_s* r = zx_NEW_sp_LogoutResponse(cf->ctx);
  r->Issuer = zxid_my_issuer(cf);
  r->ID = zxid_mk_id(cf, "r", ZXID_ID_BITS);
  r->Version = zx_ref_str(cf->ctx, SAML2_VERSION);
  r->IssueInstant = zxid_date_time(cf, time(0));
  if (req_id)
    r->InResponseTo = req_id;
  r->Status = st;
  return r;
}

/*() Change SPNameID (newnym supplied), or Terminate federation (newnym not supplied).
 * Create XML data structure for <ManageNameIDRequest> element. Low level API. */

/* Called by:  zxid_sp_mni_redir, zxid_sp_mni_soap */
struct zx_sp_ManageNameIDRequest_s* zxid_mk_mni(zxid_conf* cf, zxid_nid* nid, struct zx_str* new_nym, zxid_entity* idp_meta)
{
  struct zx_str* ss;
  struct zx_xenc_EncryptedKey_s* ek;
  struct zx_sp_ManageNameIDRequest_s* r = zx_NEW_sp_ManageNameIDRequest(cf->ctx);
  r->Issuer = zxid_my_issuer(cf);
  r->ID = zxid_mk_id(cf, "R", ZXID_ID_BITS);
  r->Version = zx_ref_str(cf->ctx, SAML2_VERSION);
  r->IssueInstant = zxid_date_time(cf, time(0));
  if (cf->nameid_enc && idp_meta) {
    r->EncryptedID = zxid_mk_enc_id(cf, nid, idp_meta);
    if (new_nym && new_nym->len) {
      struct zx_elem_s* newid = zx_new_simple_elem(cf->ctx, new_nym);
      ss = zx_EASY_ENC_SO_simple_elem(cf->ctx, newid, "sp:NewID", sizeof("sp:NewID")-1, zx_ns_tab+zx_xmlns_ix_sp);
      r->NewEncryptedID = zx_NEW_sp_NewEncryptedID(cf->ctx);
      if (cf->enckey_opt & 0x20) {
	/* Nested EncryptedKey approach (Shibboleth early 2010) */
	r->NewEncryptedID->EncryptedData = zxenc_pubkey_enc(cf, ss, 0, idp_meta->enc_cert, "43",0);
      } else {
	/* RetrievalMethod approach */
	r->NewEncryptedID->EncryptedData = zxenc_pubkey_enc(cf, ss, &ek, idp_meta->enc_cert, "39", idp_meta);
	r->NewEncryptedID->EncryptedKey = ek;
      }
      zx_str_free(cf->ctx, ss);
      zx_FREE_simple_elem(cf->ctx, newid, 0);
    } else
      r->Terminate = zx_new_simple_elem(cf->ctx, 0);
  } else {
    r->NameID = nid;
    if (new_nym && new_nym->len)
      r->NewID = zx_new_simple_elem(cf->ctx, new_nym);
    else
      r->Terminate = zx_new_simple_elem(cf->ctx, 0);
  }
  return r;
}

/*() Create XML data structure for <ManageNameIDResponse> element. Low level API.*/

/* Called by:  zxid_mni_do, zxid_mni_do_ss */
struct zx_sp_ManageNameIDResponse_s* zxid_mk_mni_resp(zxid_conf* cf, struct zx_sp_Status_s* st, struct zx_str* req_id)
{
  struct zx_sp_ManageNameIDResponse_s* r = zx_NEW_sp_ManageNameIDResponse(cf->ctx);
  r->Issuer = zxid_my_issuer(cf);
  r->ID = zxid_mk_id(cf, "r", ZXID_ID_BITS);
  r->Version = zx_ref_str(cf->ctx, SAML2_VERSION);
  r->IssueInstant = zxid_date_time(cf, time(0));
  if (req_id)
    r->InResponseTo = req_id;
  r->Status = st;
  return r;
}

/* ======== IdP SSO Related ======== */

/*() Constructor for Assertion */

/* Called by:  zxid_mk_user_a7n_to_sp, zxid_xacml_az_cd1_do x2, zxid_xacml_az_do x2 */
zxid_a7n* zxid_mk_a7n(zxid_conf* cf, struct zx_str* audience, struct zx_sa_Subject_s* subj, struct zx_sa_AuthnStatement_s* an_stmt, struct zx_sa_AttributeStatement_s* at_stmt, struct zx_xasa_XACMLAuthzDecisionStatement_s* az_stmt)
{
  zxid_a7n* a7n =  zx_NEW_sa_Assertion(cf->ctx);
  a7n->Version = zx_dup_str(cf->ctx, SAML2_VERSION);
  a7n->ID = zxid_mk_id(cf, "A", ZXID_ID_BITS);
  a7n->Issuer = zxid_my_issuer(cf);
  a7n->IssueInstant = zxid_date_time(cf, time(0));
  a7n->Subject = subj;
  a7n->Conditions = zx_NEW_sa_Conditions(cf->ctx);
  a7n->Conditions->NotBefore = zxid_date_time(cf, time(0));
  a7n->Conditions->NotOnOrAfter = zxid_date_time(cf, time(0) + cf->a7nttl);
  if (audience) {
    a7n->Conditions->AudienceRestriction = zx_NEW_sa_AudienceRestriction(cf->ctx);
    a7n->Conditions->AudienceRestriction->Audience = zx_new_simple_elem(cf->ctx, audience);
  }
  a7n->AuthnStatement = an_stmt;
  a7n->AttributeStatement = at_stmt;
  a7n->XACMLAuthzDecisionStatement = az_stmt;
  return a7n;
}

/*() Construct Subject, possibly with EncryptedID */

/* Called by:  zxid_mk_user_a7n_to_sp, zxid_xacml_az_cd1_do, zxid_xacml_az_do */
struct zx_sa_Subject_s* zxid_mk_subj(zxid_conf* cf, zxid_entity* sp_meta, zxid_nid* nid)
{
  struct zx_sa_Subject_s* subj = zx_NEW_sa_Subject(cf->ctx);

#if 0
  // , struct zx_str* affil, char* fmt
  nid = zx_NEW_sa_NameID(cf->ctx);
  nid->Format = zx_dup_str(cf->ctx, fmt);  /* *** implement persistent */
  nid->NameQualifier = zxid_my_entity_id(cf);
  nid->SPNameQualifier = affil;
  if (!strcmp(fmt, SAML2_TRANSIENT_NID_FMT)) {
    nid->gg.content = zxid_mk_id(cf, "T", ZXID_ID_BITS);
  } else {
    /* *** see also zxid_get_user_nameid() */
  }
#endif

  if (cf->nameid_enc) {
    if (sp_meta)
      subj->EncryptedID = zxid_mk_enc_id(cf, nid, sp_meta);
    else {
      ERR("NameID encryption confugred, but no metadata supplied. Defaulting to unencrypted NameID %d", 0);
      subj->NameID = nid;
    }
  } else
    subj->NameID = nid;
  /* SAML spec is more lax than the schema: saml-core-2.0-os.pdf ll.653-657 says <SubjectConfirmation> [Zero or More] */
  return subj;
}

/*() Construct AuthnStatement */

/* Called by:  zxid_mk_user_a7n_to_sp */
struct zx_sa_AuthnStatement_s* zxid_mk_an_stmt(zxid_conf* cf, zxid_ses* ses)
{
  struct zx_sa_AuthnStatement_s* an_stmt = zx_NEW_sa_AuthnStatement(cf->ctx);
  an_stmt->SessionIndex = zx_dup_str(cf->ctx, ses->sesix);  /* *** need noncorrelatable session index */
  an_stmt->AuthnInstant = zxid_date_time(cf, ses->an_instant);
  an_stmt->AuthnContext = zx_NEW_sa_AuthnContext(cf->ctx);
  if (ses->an_ctx)
    an_stmt->AuthnContext->AuthnContextClassRef = zx_dup_simple_elem(cf->ctx, ses->an_ctx);
  else {
    ERR("Session(%s) lacks AuthentContextClassRef. Output AuthnStatement will not satisfy all processing rules. See configuration option ISSUE_AUTHNCTX_PW.", ses->sesix);
  }
  return an_stmt;
}

/*() Construct SAML SAML Attribute */

/* Called by:  zxid_add_ldif_attrs, zxid_gen_boots, zxid_mk_user_a7n_to_sp */
struct zx_sa_Attribute_s* zxid_mk_attribute(zxid_conf* cf, char* name, char* val)
{
  struct zx_sa_Attribute_s* r = zx_NEW_sa_Attribute(cf->ctx);
  r->Name = zx_dup_str(cf->ctx, name);
  r->AttributeValue = zx_NEW_sa_AttributeValue(cf->ctx);
  if (val)
    r->AttributeValue->gg.content = zx_dup_str(cf->ctx, val);
  return r;
}

/*() Construct SAML protocol Response (such as may be used to carry assertion in SSO) */

/* Called by:  zxid_idp_sso x4, zxid_xacml_az_cd1_do x2, zxid_xacml_az_do x2 */
struct zx_sp_Response_s* zxid_mk_saml_resp(zxid_conf* cf)
{
  struct zx_sp_Response_s* r = zx_NEW_sp_Response(cf->ctx);
  r->Version = zx_dup_str(cf->ctx, SAML2_VERSION);
  r->ID = zxid_mk_id(cf, "R", ZXID_ID_BITS);
  r->Issuer = zxid_my_issuer(cf);
  r->IssueInstant = zxid_date_time(cf, time(0));
  r->Status = zxid_OK(cf);
  return r;
}

/*() Construct XACML Response */

/* Called by:  zxid_ins_xacml_az_cd1_stmt x2, zxid_ins_xacml_az_stmt x2 */
struct zx_xac_Response_s* zxid_mk_xacml_resp(zxid_conf* cf, char* decision)
{
  struct zx_xac_Response_s* resp = zx_NEW_xac_Response(cf->ctx);
  resp->Result = zx_NEW_xac_Result(cf->ctx);
  resp->Result->Decision = zx_ref_simple_elem(cf->ctx, decision);
  resp->Result->Status = zx_NEW_xac_Status(cf->ctx);
  resp->Result->Status->StatusCode = zx_NEW_xac_StatusCode(cf->ctx);
  resp->Result->Status->StatusCode->Value
    = zx_ref_str(cf->ctx, "urn:oasis:names:tc:xacml:1.0:status:ok");
  return resp;
}

/* Called by:  zxid_pep_az_soap x3 */
struct zx_xac_Attribute_s* zxid_mk_xacml_simple_at(zxid_conf* cf, struct zx_xac_Attribute_s* aa, struct zx_str* atid, struct zx_str* attype, struct zx_str* atissuer, struct zx_str* atvalue)
{
  struct zx_xac_Attribute_s* at = zx_NEW_xac_Attribute(cf->ctx);
  ZX_NEXT(at) = (void*)aa;
  at->AttributeId = atid;
  at->DataType = attype;
  at->Issuer = atissuer;
  //at->AttributeValue = zx_NEW_xac_AttributeValue(cf->ctx);
  at->AttributeValue = zx_new_simple_elem(cf->ctx, atvalue);
  return at;
}

/*() Construct xac_Request */

/* Called by:  zxid_pep_az_soap */
struct zx_xac_Request_s* zxid_mk_xac_az(zxid_conf* cf, struct zx_xac_Attribute_s* subj, struct zx_xac_Attribute_s* rsrc, struct zx_xac_Attribute_s* act, struct zx_xac_Attribute_s* env)
{
  struct zx_xac_Request_s* r = zx_NEW_xac_Request(cf->ctx);
  r->Subject  = zx_NEW_xac_Subject(cf->ctx);
  r->Subject->Attribute = subj;
  r->Resource = zx_NEW_xac_Resource(cf->ctx);
  r->Resource->Attribute = rsrc;
  r->Action   = zx_NEW_xac_Action(cf->ctx);
  r->Action->Attribute = act;
  r->Environment = zx_NEW_xac_Environment(cf->ctx);
  r->Environment->Attribute = env;
  return r;
}

/*() Construct XACMLAuthzDecisionQuery */

/* Called by:  zxid_pep_az_soap */
struct zx_xasp_XACMLAuthzDecisionQuery_s* zxid_mk_az(zxid_conf* cf, struct zx_xac_Attribute_s* subj, struct zx_xac_Attribute_s* rsrc, struct zx_xac_Attribute_s* act, struct zx_xac_Attribute_s* env)
{
  struct zx_xasp_XACMLAuthzDecisionQuery_s* r = zx_NEW_xasp_XACMLAuthzDecisionQuery(cf->ctx);
  r->Issuer = zxid_my_issuer(cf);
  r->ID = zxid_mk_id(cf, "R", ZXID_ID_BITS);
  r->Version = zx_ref_str(cf->ctx, SAML2_VERSION);
  r->IssueInstant = zxid_date_time(cf, time(0));
  r->Request = zxid_mk_xac_az(cf, subj, rsrc, act, env);

  r->Request = zx_NEW_xac_Request(cf->ctx);
  r->Request->Subject  = zx_NEW_xac_Subject(cf->ctx);
  r->Request->Subject->Attribute = subj;
  r->Request->Resource = zx_NEW_xac_Resource(cf->ctx);
  r->Request->Resource->Attribute = rsrc;
  r->Request->Action   = zx_NEW_xac_Action(cf->ctx);
  r->Request->Action->Attribute = act;
  r->Request->Environment = zx_NEW_xac_Environment(cf->ctx);
  r->Request->Environment->Attribute = env;
  return r;
}

/*() Construct XACMLAuthzDecisionQuery according to Commitee Draft 1 */

/* Called by:  zxid_pep_az_soap x2 */
struct zx_xaspcd1_XACMLAuthzDecisionQuery_s* zxid_mk_az_cd1(zxid_conf* cf, struct zx_xac_Attribute_s* subj, struct zx_xac_Attribute_s* rsrc, struct zx_xac_Attribute_s* act, struct zx_xac_Attribute_s* env)
{
  struct zx_xaspcd1_XACMLAuthzDecisionQuery_s* r = zx_NEW_xaspcd1_XACMLAuthzDecisionQuery(cf->ctx);
  r->Issuer = zxid_my_issuer(cf);
  r->ID = zxid_mk_id(cf, "R", ZXID_ID_BITS);
  r->Version = zx_ref_str(cf->ctx, SAML2_VERSION);
  r->IssueInstant = zxid_date_time(cf, time(0));
  r->Request = zx_NEW_xac_Request(cf->ctx);
  r->Request->Subject  = zx_NEW_xac_Subject(cf->ctx);
  r->Request->Subject->Attribute = subj;
  r->Request->Resource = zx_NEW_xac_Resource(cf->ctx);
  r->Request->Resource->Attribute = rsrc;
  r->Request->Action   = zx_NEW_xac_Action(cf->ctx);
  r->Request->Action->Attribute = act;
  r->Request->Environment = zx_NEW_xac_Environment(cf->ctx);
  r->Request->Environment->Attribute = env;
  return r;
}

/* EOF  --  zxidmk.c */
