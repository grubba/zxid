/* zxidim.c  -  Identity Mapping Service
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
 * - liberty-idwsf-authn-svc-v2.0.pdf sec 7 "Identity Mapping Service"
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

/*() Single Sign-On Service (SSOS): Issue SSO assertion in response to receiving a token.
 * See also zxid_idp_sso() for similar code. */

/* Called by:  zxid_sp_soap_dispatch */
struct zx_sp_Response_s* zxid_ssos_anreq(zxid_conf* cf, zxid_a7n* a7n, struct zx_sp_AuthnRequest_s* ar)
{
  X509* sign_cert;
  RSA*  sign_pkey;
  struct zxsig_ref refs;
  struct timeval srcts = {0,501000};
  zxid_cgi cgi;
  zxid_ses ses;
  zxid_nid* nameid;
  char* logop;
  struct zx_sp_Response_s* resp = zx_NEW_sp_Response(cf->ctx);
  struct zx_str* payload;
  struct zx_str* affil;
  struct zx_str* ss;
  zxid_entity* sp_meta;
  int len;
  char uid[ZXID_MAX_BUF];
  char sp_name_buf[1024];
  D_INDENT("ssos: ");

  if (!ar || !ar->Issuer || !ar->Issuer->gg.content) {
    ERR("No Issuer found in AuthnRequest %p", ar);
    resp->Status = zxid_mk_Status(cf, "Fail", 0, 0);
    D_DEDENT("ssos: ");
    return resp;
  }

  //resp->ID = zxid_mk_id(cf, "DIR", ZXID_ID_BITS);
  
  if (!a7n || !a7n->Subject) {
    ERR("Malformed Assertion(%p): Subject missing.", a7n);
    resp->Status = zxid_mk_Status(cf, "Fail", 0, 0);
    D_DEDENT("ssos: ");
    return resp;
  }

  nameid = zxid_decrypt_nameid(cf, a7n->Subject->NameID, a7n->Subject->EncryptedID);
  affil = nameid->SPNameQualifier ? nameid->SPNameQualifier : zxid_my_entity_id(cf);
  
  zxid_nice_sha1(cf, sp_name_buf, sizeof(sp_name_buf), affil, affil, 7);
  len = read_all(sizeof(uid)-1, uid, "idp_map_nid2uid", "%s" ZXID_NID_DIR "%s/%.*s", cf->path, sp_name_buf, nameid->gg.content->len, nameid->gg.content->s);
  if (!len) {
    ERR("Can not find reverse mapping for SP,SHA1(%s) nid(%.*s)", sp_name_buf, nameid->gg.content->len, nameid->gg.content->s);
    resp->Status = zxid_mk_Status(cf, "Fail", 0, 0);
    D_DEDENT("ssos: ");
    return resp;
  }

  memset(&cgi, 0, sizeof(cgi));
  memset(&ses, 0, sizeof(ses));
  ses.magic = ZXID_SES_MAGIC;
  ses.an_instant = time(0);  /* This will be later used by AuthnStatement constructor. */
  ses.an_ctx = SAML_AUTHCTX_PREVSESS;  /* Is there better one to use for token based auth? */
  ss = zxid_mk_id(cf, "OSES", ZXID_ID_BITS);  /* Onetime Master session. Each pairwise SSO should have its own to avoid correlation. The session can not be used for SLO. */
  ses.sesix = ss->s;
  ZX_FREE(cf->ctx, ss);
  ses.sid = cgi.sid = ses.sesix;
  cgi.uid = uid;
  ses.uid = cgi.uid;
  /*zxid_put_ses(cf, ses);*/
  
  sp_meta = zxid_get_ent_ss(cf, ar->Issuer->gg.content);
  if (!sp_meta) {
    ERR("The metadata for Issuer of the AuthnRequest could not be found or fetched %d", 0);
    resp->Status = zxid_mk_Status(cf, "Fail", 0, 0);
    D_DEDENT("ssos: ");
    return resp;
  }
  D("sp_eid(%s)", sp_meta->eid);

  a7n = zxid_sso_issue_a7n(cf, &cgi, &ses, &srcts, sp_meta, 0, &nameid, &logop, ar);

  if (cf->sso_sign & ZXID_SSO_SIGN_A7N) {
    refs.id = a7n->ID;
    refs.canon = zx_EASY_ENC_SO_sa_Assertion(cf->ctx, a7n);
    if (zxid_lazy_load_sign_cert_and_pkey(cf, &sign_cert, &sign_pkey, "use sign cert paos"))
      a7n->Signature = zxsig_sign(cf->ctx, 1, &refs, sign_cert, sign_pkey);
  }
  resp = zxid_mk_saml_resp(cf);
  if (cf->post_a7n_enc) {
    resp->EncryptedAssertion = zxid_mk_enc_a7n(cf, a7n, sp_meta);
  } else {
    resp->Assertion = a7n;
  }
  payload = zxid_anoint_sso_resp(cf, cf->sso_sign & ZXID_SSO_SIGN_RESP, resp, ar);
  if (!payload) {
    resp->Status = zxid_mk_Status(cf, "Fail", 0, 0);
    D_DEDENT("ssos: ");
    return resp;
  }
  zx_str_free(cf->ctx, payload);

  zxlog(cf, 0, &srcts, 0, ar->Issuer->gg.content, 0, a7n->ID, nameid->gg.content, "N", "K", logop, ses.uid, "SSOS");

  /* *** Generate SOAP envelope with ECP header as required by ECP PAOS */

  
  D_DEDENT("ssos: ");
  return resp;
}

/*() Identity Mapping Service: Issue token in response to receiving a token */

/* Called by:  zxid_sp_soap_dispatch */
struct zx_im_IdentityMappingResponse_s* zxid_imreq(zxid_conf* cf, zxid_a7n* a7n, struct zx_im_IdentityMappingRequest_s* req)
{
  struct zx_im_IdentityMappingResponse_s* resp = zx_NEW_im_IdentityMappingResponse(cf->ctx);
  struct zx_im_MappingInput_s* mapinp;
  struct zx_im_MappingOutput_s* mapout;
  struct zx_sec_Token_s* tok;
  zxid_a7n* ina7n;
  zxid_a7n* outa7n;
  struct zx_str* issue_to;
  struct zx_str* affil;
  char allow_create;
  char* nid_fmt;
  zxid_nid* nameid;
  char* logop;
  int len, n_mapped = 0;
  char uid[ZXID_MAX_BUF];
  char sp_name_buf[1024];
  zxid_entity* sp_meta;
  D_INDENT("imreq: ");

  if (!req || !req->MappingInput) {
    ERR("No IdentityMappingRequest/MappingInput found (WSC error) %p", req);
    resp->Status = zxid_mk_lu_Status(cf, "Fail", 0, 0, 0);
    D_DEDENT("imreq: ");
    return resp;
  }
  
  for (mapinp = req->MappingInput; mapinp; mapinp = (struct zx_im_MappingInput_s*)mapinp->gg.g.n) {
  
    if (tok = mapinp->Token) {
      if (tok->Assertion || tok->EncryptedAssertion) {
	ina7n = zxid_dec_a7n(cf, tok->Assertion, tok->EncryptedAssertion);
      } else if (tok->ref && !ZX_STRCMP(tok->ref, a7n->ID)) {
	D("Token->ref(%.*s) matches invocation security token.", tok->ref->len, tok->ref->s);
	/* N.B. This is a common optimization as it often happens that invoker (delegatee) needs to
	 * IDMap his own token, while delegator's token can usually be found using discovery. */
	ina7n = a7n;
      } else {
	ERR("*** Missing IdentityMappingRequest/MappingInput/Token/(Encrypted)Assertion (WSC error). Using invocation identity instead. %p", a7n);
	ina7n = a7n;
      }
    } else {
      ERR("*** Missing IdentityMappingRequest/MappingInput/Token (WSC error). Using invocation identity instead. %p", a7n);
      ina7n = a7n;
    }

    //resp->ID = zxid_mk_id(cf, "DIR", ZXID_ID_BITS);
    
    if (!ina7n || !ina7n->Subject) {
      ERR("Malformed Assertion(%p): Subject missing.", a7n);
      resp->Status = zxid_mk_lu_Status(cf, "Fail", 0, 0, 0);
      D_DEDENT("imreq: ");
      return resp;
    }
    
    if (!mapinp->TokenPolicy) {
      ERR("Missing TokenPolicy. %d", 0);
      resp->Status = zxid_mk_lu_Status(cf, "Fail", 0, 0, 0);
      D_DEDENT("imreq: ");
      return resp;
    }
    
    nameid = zxid_decrypt_nameid(cf, ina7n->Subject->NameID, ina7n->Subject->EncryptedID);
    affil = nameid->SPNameQualifier ? nameid->SPNameQualifier : zxid_my_entity_id(cf);
    
    zxid_nice_sha1(cf, sp_name_buf, sizeof(sp_name_buf), affil, affil, 7);
    len = read_all(sizeof(uid)-1, uid, "idp_map_nid2uid", "%s" ZXID_NID_DIR "%s/%.*s", cf->path, sp_name_buf, nameid->gg.content->len, nameid->gg.content->s);
    if (!len) {
      ERR("Can not find reverse mapping for SP,SHA1(%s) nid(%.*s)", sp_name_buf, nameid->gg.content->len, nameid->gg.content->s);
      resp->Status = zxid_mk_lu_Status(cf, "Fail", 0, 0, 0);
      D_DEDENT("imreq: ");
      return resp;
    }

    /* Figure out destination */

    if (mapinp->TokenPolicy->NameIDPolicy) {
      issue_to = mapinp->TokenPolicy->NameIDPolicy->SPNameQualifier;
      nid_fmt = mapinp->TokenPolicy->NameIDPolicy->Format->len == sizeof(SAML2_TRANSIENT_NID_FMT)-1
	&& !memcmp(mapinp->TokenPolicy->NameIDPolicy->Format->s, SAML2_TRANSIENT_NID_FMT, sizeof(SAML2_TRANSIENT_NID_FMT)-1)
	? "trnsnt" : "prstnt";
      allow_create = ZXID_XML_TRUE_TEST(mapinp->TokenPolicy->NameIDPolicy->AllowCreate) ? '1' : '0';
    } else {
      issue_to = mapinp->TokenPolicy->issueTo;
      nid_fmt = "prstnt";
      allow_create = '1';
    }
    
    if (!issue_to) {
      ERR("No NameIDPolicy->SPNameQualifier or issueTo %p", mapinp->TokenPolicy);
      resp->Status = zxid_mk_lu_Status(cf, "Fail", 0, 0, 0);
      D_DEDENT("imreq: ");
      return resp;
    }
    zxid_nice_sha1(cf, sp_name_buf, sizeof(sp_name_buf), issue_to, issue_to, 7);

    /* Check for federation */

    nameid = zxid_check_fed(cf, issue_to, uid, allow_create, 0, 0, 0, sp_name_buf);
    if (nameid) {
      if (nid_fmt && !strcmp(nid_fmt, "trnsnt")) {
	D("Despite old fed, using transient due to nid_fmt(%s)", STRNULLCHKD(nid_fmt));
	zxid_mk_transient_nid(cf, nameid, sp_name_buf, uid);
	logop = "ITIM";
      } else
	logop = "IFIM";
    } else {
      D("No nameid (because of no federation), using transient %d", 0);
      nameid = zx_NEW_sa_NameID(cf->ctx);
      zxid_mk_transient_nid(cf, nameid, sp_name_buf, uid);
      logop = "ITIM";
    }

    /* Issue the assertion and sign it. */

    sp_meta = zxid_get_ent_ss(cf, issue_to);
    if (!sp_meta) {
      ERR("The metadata for provider could not be found or fetched. Reject. %d", 0);
      resp->Status = zxid_mk_lu_Status(cf, "Fail", 0, 0, 0);
      D_DEDENT("imreq: ");
      return resp;
    }

    outa7n = zxid_mk_user_a7n_to_sp(cf, 0, uid, nameid, sp_meta, sp_name_buf, 1);

    if (!zxid_anoint_a7n(cf, cf->sso_sign & ZXID_SSO_SIGN_A7N, outa7n, issue_to, "IMA7N", uid)) {
      resp->Status = zxid_mk_lu_Status(cf, "Fail", 0, 0, 0);
      D_DEDENT("imreq: ");
      return resp;
    }
    
    /* Formulate mapping output */

    mapout = zx_NEW_im_MappingOutput(cf->ctx);
    if (mapinp->reqID && mapinp->reqID->len && mapinp->reqID->s)
      mapout->reqRef = zx_dup_len_str(cf->ctx, mapinp->reqID->len, mapinp->reqID->s);
    mapout->Token = zx_NEW_sec_Token(cf->ctx);
    if (cf->di_a7n_enc) {
      mapout->Token->EncryptedAssertion = zxid_mk_enc_a7n(cf, outa7n, sp_meta);
    } else {
      mapout->Token->Assertion = outa7n;
    }
    
    mapout->gg.g.n = &resp->MappingOutput->gg.g;
    resp->MappingOutput = mapout;

    zxlog(cf, 0, 0, 0, 0, 0, a7n->ID, nameid->gg.content, "N", "K", logop, 0, "n=%d", n_mapped);
  }
  
  D("TOTAL Identity Mappings issued %d", n_mapped);
  zxlog(cf, 0, 0, 0, 0, 0, a7n->ID, nameid->gg.content, "N", "K", "IMOK", 0, "n=%d", n_mapped);
  resp->Status = zxid_mk_lu_Status(cf, "OK", 0, 0, 0);
  D_DEDENT("imreq: ");
  return resp;
}

/*() SAML NameID Mapping Service: Issue token in response to receiving a token */

/* Called by:  zxid_sp_soap_dispatch */
struct zx_sp_NameIDMappingResponse_s* zxid_nidmap_do(zxid_conf* cf, struct zx_sp_NameIDMappingRequest_s* req)
{
  struct zx_sp_NameIDMappingResponse_s* resp = zx_NEW_sp_NameIDMappingResponse(cf->ctx);
  struct zx_str* issue_to;
  struct zx_str* affil;
  char allow_create;
  char* nid_fmt;
  zxid_nid* nameid;
  char* logop;
  int len, n_mapped = 0;
  char uid[ZXID_MAX_BUF];
  char sp_name_buf[1024];
  D_INDENT("nidmap: ");

  //resp->ID = zxid_mk_id(cf, "DIR", ZXID_ID_BITS);
    
  /* *** there should be some strict access control policies here, otherwise
   * privacy can be lost by consulting nameids directly via this service. */
  
  nameid = zxid_decrypt_nameid(cf, req->NameID, req->EncryptedID);
  affil = nameid->SPNameQualifier ? nameid->SPNameQualifier : zxid_my_entity_id(cf);
  
  zxid_nice_sha1(cf, sp_name_buf, sizeof(sp_name_buf), affil, affil, 7);
  len = read_all(sizeof(uid)-1, uid, "idp_map_nid2uid", "%s" ZXID_NID_DIR "%s/%.*s", cf->path, sp_name_buf, nameid->gg.content->len, nameid->gg.content->s);
  if (!len) {
    ERR("Can not find reverse mapping for SP,SHA1(%s) nid(%.*s)", sp_name_buf, nameid->gg.content->len, nameid->gg.content->s);
    resp->Status = zxid_mk_Status(cf, "Fail", 0, 0);
    D_DEDENT("nidmap: ");
    return resp;
  }
  
  /* Figure out destination */
  
  if (req->NameIDPolicy) {
    issue_to = req->NameIDPolicy->SPNameQualifier;
    nid_fmt = req->NameIDPolicy->Format->len == sizeof(SAML2_TRANSIENT_NID_FMT)-1
      && !memcmp(req->NameIDPolicy->Format->s, SAML2_TRANSIENT_NID_FMT, sizeof(SAML2_TRANSIENT_NID_FMT)-1)
      ? "trnsnt" : "prstnt";
    allow_create = ZXID_XML_TRUE_TEST(req->NameIDPolicy->AllowCreate) ? '1' : '0';
  } else {
    issue_to = 0;
  }
  
  if (!issue_to) {
    ERR("No NameIDPolicy->SPNameQualifier %p", req->NameIDPolicy);
    resp->Status = zxid_mk_Status(cf, "Fail", 0, 0);
    D_DEDENT("nidmap: ");
    return resp;
  }
  zxid_nice_sha1(cf, sp_name_buf, sizeof(sp_name_buf), issue_to, issue_to, 7);
  
  /* Check for federation */
  
  nameid = zxid_check_fed(cf, issue_to, uid, allow_create, 0, 0, 0, sp_name_buf);
  if (nameid) {
    if (nid_fmt && !strcmp(nid_fmt, "trnsnt")) {
      D("Despite old fed, using transient due to nid_fmt(%s)", STRNULLCHKD(nid_fmt));
      zxid_mk_transient_nid(cf, nameid, sp_name_buf, uid);
      logop = "ITNIDMAP";
    } else
      logop = "IFNIDMAP";
  } else {
    D("No nameid (because of no federation), using transient %d", 0);
    nameid = zx_NEW_sa_NameID(cf->ctx);
    zxid_mk_transient_nid(cf, nameid, sp_name_buf, uid);
    logop = "ITNIDMAP";
  }
  
  zxlog(cf, 0, 0, 0, 0, 0, 0, nameid->gg.content, "N", "K", logop, 0, "n=%d", n_mapped);
  resp->Status = zxid_OK(cf);
  D_DEDENT("nidmap: ");
  return resp;
}

/* EOF  --  zxidim.c */
