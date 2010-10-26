/* zxidwsp.c  -  Handwritten nitty-gritty functions for Liberty ID-WSF Web Services Provider
 * Copyright (c) 2009-2010 Sampo Kellomaki (sampo@iki.fi), All Rights Reserved.
 * Copyright (c) 2009 Symlabs (symlabs@symlabs.com), All Rights Reserved.
 * Author: Sampo Kellomaki (sampo@iki.fi)
 * This is confidential unpublished proprietary source code of the author.
 * NO WARRANTY, not even implied warranties. Contains trade secrets.
 * Distribution prohibited unless authorized in writing.
 * Licensed under Apache License 2.0, see file COPYING.
 * $Id: zxidwsc.c,v 1.16 2009-11-20 20:27:13 sampo Exp $
 *
 * 22.11.2009, created --Sampo
 * 7.1.2010,   added WSP signing --Sampo
 * 31.5.2010,  reworked PEPs extensively --Sampo
 */

#include "platform.h"  /* needed on Win32 for pthread_mutex_lock() et al. */

#include "errmac.h"
#include "zxid.h"
#include "zxidconf.h"
#include "saml2.h"
#include "wsf.h"
#include "c/zx-const.h"
#include "c/zx-ns.h"
#include "c/zx-data.h"

#define BOOL_STR_TEST(x) ((x) && (x) != '0')

/*(i) zxid_wsf_decor() implements the main low level ID-WSF web service call logic, including
 * preparation of SOAP headers, use of sec mech (e.g. preparation of wsse:Security
 * header and signing of appropriate compoments of the message), and sequencing
 * of the call. In particular, it is possible that WSP requests user interaction
 * and thus the caller web application will need to perform a redirect and then
 * later call this function again to continue the web service call after interaction.
 *
 * env (rather than Body) is taken as argument so that caller can prepare
 * additional SOAP headers at will before calling this function. This function
 * will add Liberty ID-WSF specific SOAP headers. */

/* Called by:  main, zxid_wsc_prep, zxid_wsp_decorate */
int zxid_wsf_decor(zxid_conf* cf, zxid_ses* ses, struct zx_e_Envelope_s* env, int is_resp)
{
  struct zx_wsse_Security_s* sec;
  struct zx_e_Header_s* hdr;
  
  if (!env || !env->Body) {
    ERR("NULL SOAP envelope or body %p", env);
    return 0;
  }
  
  if (!env->Header)
    env->Header = zx_NEW_e_Header(cf->ctx);
  hdr = env->Header;

  if (ses->curstatus) {
    hdr->Status = ses->curstatus;
  }

  /* Populate SOAP headers. */
  
  hdr->Framework = zx_NEW_sbf_Framework(cf->ctx);
  hdr->Framework->version = zx_ref_str(cf->ctx, "2.0");
  hdr->Framework->actor = zx_ref_str(cf->ctx, SOAP_ACTOR_NEXT);
  hdr->Framework->mustUnderstand = zx_ref_str(cf->ctx, ZXID_TRUE);

#if 1
  /* *** Conor claims Sender is not mandatory */
  hdr->Sender = zx_NEW_b_Sender(cf->ctx);
  hdr->Sender->actor = zx_ref_str(cf->ctx, SOAP_ACTOR_NEXT);
  hdr->Sender->mustUnderstand = zx_ref_str(cf->ctx, ZXID_TRUE);
  if (cf->affiliation)
    hdr->Sender->affiliationID = zx_ref_str(cf->ctx, cf->affiliation);
  hdr->Sender->providerID = zxid_my_entity_id(cf);
#endif

#if 0
  hdr->Action = zx_NEW_a_Action(cf->ctx);
  hdr->Action->gg.content = zx_ref_str(cf->ctx, ***);
  hdr->Action->actor = zx_ref_str(cf->ctx, SOAP_ACTOR_NEXT);
  hdr->Action->mustUnderstand = zx_ref_str(cf->ctx, ZXID_TRUE);
#endif

#if 0
  hdr->From = zx_NEW_a_From(cf->ctx);
  hdr->From->Address = zxid_mk_addr(cf, zx_strf(cf->ctx, "%s?o=P", cf->url));
  hdr->From->actor = zx_ref_str(cf->ctx, SOAP_ACTOR_NEXT);
  hdr->From->mustUnderstand = zx_ref_str(cf->ctx, ZXID_TRUE);
#endif

#if 0
  hdr->ReferenceParameters = zx_NEW_a_ReferenceParameters(cf->ctx);
  hdr->ReferenceParameters->actor = zx_ref_str(cf->ctx, SOAP_ACTOR_NEXT);
  hdr->ReferenceParameters->mustUnderstand = zx_ref_str(cf->ctx, ZXID_TRUE);
#endif

#if 0
  hdr->Credentials = zx_NEW_tas3_Credentials(cf->ctx);
  hdr->Credentials->actor = zx_ref_str(cf->ctx, SOAP_ACTOR_NEXT);
  hdr->Credentials->mustUnderstand = zx_ref_str(cf->ctx, ZXID_TRUE);
#endif

#if 0
  /* If you want this header, you should
   * create it prior to calling zxid_wsc_call() */
  hdr->UsageDirective = zx_NEW_b_UsageDirective(cf->ctx);
  hdr->UsageDirective->actor = zx_ref_str(cf->ctx, SOAP_ACTOR_NEXT);
  hdr->UsageDirective->mustUnderstand = zx_ref_str(cf->ctx, ZXID_TRUE);
#endif

#if 0
  /* Interaction or redirection. If you want this header, you should
   * create it prior to calling zxid_wsc_call() */
  hdr->UserInteraction = zx_NEW_b_UserInteraction(cf->ctx);
  hdr->UserInteraction->actor = zx_ref_str(cf->ctx, SOAP_ACTOR_NEXT);
  hdr->UserInteraction->mustUnderstand = zx_ref_str(cf->ctx, ZXID_TRUE);
#endif
  
  sec = hdr->Security = zx_NEW_wsse_Security(cf->ctx);
  sec->actor = zx_ref_str(cf->ctx, SOAP_ACTOR_NEXT);
  sec->mustUnderstand = zx_ref_str(cf->ctx, ZXID_TRUE);
  sec->Timestamp = zx_NEW_wsu_Timestamp(cf->ctx);
  sec->Timestamp->Created = zx_NEW_wsu_Created(cf->ctx);
  
  hdr->MessageID = zx_NEW_a_MessageID(cf->ctx);
  hdr->MessageID->actor = zx_ref_str(cf->ctx, SOAP_ACTOR_NEXT);
  hdr->MessageID->mustUnderstand = zx_ref_str(cf->ctx, ZXID_TRUE);

  if (is_resp) {
    sec->Timestamp->Created->gg.content = zxid_date_time(cf, time(0));
    hdr->MessageID->gg.content = zxid_mk_id(cf, "urn:M", ZXID_ID_BITS);;
    /* Clear away any credentials from previous iteration. */
    sec->Signature = 0;
    sec->BinarySecurityToken = 0;
    sec->SecurityTokenReference = 0;
    sec->Assertion = 0;
    sec->sa11_Assertion = 0;
    sec->ff12_Assertion = 0;
    
#if 1
    if (ses->wsp_msgid && *ses->wsp_msgid) {
      hdr->RelatesTo = zx_NEW_a_RelatesTo(cf->ctx);
      hdr->RelatesTo->gg.content = zx_ref_str(cf->ctx, ses->wsp_msgid);
      hdr->RelatesTo->actor = zx_ref_str(cf->ctx, SOAP_ACTOR_NEXT);
      hdr->RelatesTo->mustUnderstand = zx_ref_str(cf->ctx, ZXID_TRUE);
    }
#endif

    zxid_wsf_sign(cf, cf->wsp_sign, sec, 0, hdr, env->Body);
  }
  return 1;
}

/* ----------------------------------------
 * Simplify writing WSPs */

/*(i) Add ID-WSF (and TAS3) specific headers and signatures to
 * web service response. Simple and intuitive specification of
 * XML as string: no need to build complex data structures.
 *
 * If the string starts by "<e:Envelope", then string should be
 * a complete SOAP envelope including <e:Header> and <e:Body> parts. This
 * allows caller to specify custom SOAP headers, in addition to the ones
 * that the underlying zxid_wsc_call() will add. Usually the payload service
 * will be passed as the contents of the body. If the string starts by
 * "<e:Body", then the <e:Envelope> and <e:Header> are automatically added. If
 * the string starts by neither of the above (be careful to use the "e:" as
 * namespace prefix), the it is assumed to be the payload content of
 * the <e:Body> and the rest of the SOAP envelope is added.
 *
 * cf:: ZXID configuration object, see zxid_new_conf()
 * ses:: Session object that contains the EPR cache
 * az_cred:: (Optional) Additional authorization credentials or
 *     attributes, query string format. These credentials will be populated
 *     to the attribute pool in addition to the ones obtained from token and
 *     other sources. Then a PDP is called to get an authorization
 *     decision (generating obligations). See also PEPMAP_RSOUT configuration
 *     option. This implements generalized (application independent)
 *     Responder Out PEP. To implement application dependent PEP features
 *     you should call zxid_az() directly.
 * env:: XML payload
 * return:: SOAP Envelope of the response, as a string, ready to be
 *     sent as HTTP response. */

/* Called by:  main x9, zxid_wsp_decoratef, zxidwspcgi_parent */
struct zx_str* zxid_wsp_decorate(zxid_conf* cf, zxid_ses* ses, const char* az_cred, const char* enve)
{
  struct zx_str* ss;
  struct zx_e_Envelope_s* env;
  D_INDENT("decor: ");

  env = zxid_add_env_if_needed(cf, enve);
  if (!env) {
    D_DEDENT("decor: ");
    return 0;
  }
  
  //*** Needs thought and development

  /* Call Rs-Out PDP */

  if (!zxid_localpdp(cf, ses)) {
    ERR("RSOUT3 Deny by local PDP %d",0);
    zxid_set_fault(cf, ses, zxid_mk_fault(cf, TAS3_PEP_RS_OUT, "e:Server", "Response denied by WSP local policy", TAS3_STATUS_DENY, 0, 0, 0));
    /* Fall through, letting zxid_wsf_decor() pick up the fault and package it as response. */
  } else if (cf->pdp_url && *cf->pdp_url) {
    //zxid_add_attr_to_pool(cf, ses, "Action", zx_dup_str(cf->ctx, "access"));
    if (!zxid_pep_az_soap_pepmap(cf, 0, ses, cf->pdp_url, cf->pepmap_rsout)) {
      ERR("RSOUT3 Deny %d", 0);
      zxid_set_fault(cf, ses, zxid_mk_fault(cf, TAS3_PEP_RS_OUT, "e:Server", "Response denied by WSP policy at PDP", TAS3_STATUS_DENY, 0, 0, 0));
      /* Fall through, letting zxid_wsf_decor() pick up the fault and package it as response. */
    }
  }
  
  if (ses->curflt) {
    D("Detected curflt, abandoning previous Body content. %d", 0);
    /* *** LEAK: Should free previous body content */
    env->Body = zx_NEW_e_Body(cf->ctx);
    env->Body->Fault = ses->curflt;
  }
  
  zxid_attach_sol1_usage_directive(cf, ses, env, TAS3_REQUIRE, cf->wsp_localpdp_obl_emit);
  
  if (!zxid_wsf_decor(cf, ses, env, 1)) {
    ERR("Response decoration failed %p", env);
    D_DEDENT("decor: ");
    return 0;
  }
  
  ss = zx_EASY_ENC_SO_e_Envelope(cf->ctx, env);
  D("DECOR len=%d envelope(%.*s)", ss->len, ss->len, ss->s);
  D_DEDENT("decor: ");
  return ss;
}

/*() Create web service response, printf style. See zxid_wsp_decorate() for more documentation. */

/* Called by:  main */
struct zx_str* zxid_wsp_decoratef(zxid_conf* cf, zxid_ses* ses, const char* az_cred, const char* env_f, ...)
{
  char* s;
  va_list ap;
  va_start(ap, env_f);
  s = zx_alloc_vasprintf(cf->ctx, 0, env_f, ap);
  va_end(ap);
  return zxid_wsp_decorate(cf, ses, az_cred, s);
}

/*() Perform necessary validation steps to check either requester or target identity
 * assertion. Also log the assertion and extract from assertion relevant information
 * into the session. The two types of assertion are distinguished by lk == "req" or "tgt".
 * returns 0 on failure and 1 on success.
 * See zxid_sp_sso_finalize() for similar code.  *** consider factoring out commonality */

/* Called by:  zxid_wsp_validate */
static int zxid_wsf_validate_a7n(zxid_conf* cf, zxid_ses* ses, zxid_a7n* a7n, const char* lk, struct timeval* srcts)
{
  struct zx_str* logpath;
  struct zx_str* a7nss;
  struct zxsig_ref refs;
  zxid_nid* nameid;
  int fmt;
  struct zx_str* issuer;
  zxid_entity* idp_meta;
  zxid_cgi cgi;

  issuer = a7n->Issuer->gg.content;
  nameid = zxid_decrypt_nameid(cf, a7n->Subject->NameID, a7n->Subject->EncryptedID);
  if (!nameid || !nameid->gg.content) {
    ERR("%s: Assertion does not have Subject->NameID. %p", lk, ses->nameid);
    zxid_set_fault(cf, ses, zxid_mk_fault(cf, TAS3_PEP_RQ_IN, "e:Client", "Assertion does not have Subject->NameID.", "IDStarMsgNotUnderstood", 0, lk, 0));
    return 0;
  }
  
  if (nameid->Format && !memcmp(nameid->Format->s,SAML2_TRANSIENT_NID_FMT,nameid->Format->len)) {
    fmt = 0;
  } else {
    fmt = 1;  /* anything nontransient may be a federation */
  }

  D("A7N received. NID(%s) FMT(%d) SESIX(%s)", STRNULLCHKQ(ses->nid), ses->nidfmt, STRNULLCHK(ses->sesix));
  if (!strcmp(lk, "tgt")) {
    ses->tgtnameid = nameid;
    ses->tgt = zx_str_to_c(cf->ctx, nameid->gg.content);
    ses->tgtfmt = fmt;
  } else {
    ses->nameid = nameid;
    ses->nid = zx_str_to_c(cf->ctx, nameid->gg.content);
    ses->nidfmt = fmt;
  }
  
  /* Validate signature (*** add Issuer trusted check, CA validation, etc.) */
  
  idp_meta = zxid_get_ent_ss(cf, issuer);
  if (!idp_meta) {
    ses->sigres = ZXSIG_NO_SIG;
    if (!cf->nosig_fatal) {
      ERR("%s: Unable to find metadata for Assertion Issuer(%.*s).", lk, issuer->len, issuer->s);
      zxid_set_fault(cf, ses, zxid_mk_fault(cf, TAS3_PEP_RQ_IN, "e:Client", "No unable to find SAML metadata for Assertion Issuer.", "ProviderIDNotValid", 0, lk, 0));
      return 0;
    } else {
      INFO("%s: Unable to find metadata for Assertion Issuer(%.*s), but configured to ignore this problem (NOSIG_FATAL=0).", lk, issuer->len, issuer->s);
    }
  } else {
    if (a7n->Signature && a7n->Signature->SignedInfo && a7n->Signature->SignedInfo->Reference) {
      ZERO(&refs, sizeof(refs));
      refs.sref = a7n->Signature->SignedInfo->Reference;
      refs.blob = (struct zx_elem_s*)a7n;
      ses->sigres = zxsig_validate(cf->ctx, idp_meta->sign_cert, a7n->Signature, 1, &refs);
      zxid_sigres_map(ses->sigres, &cgi.sigval, &cgi.sigmsg);
    } else {
      if (cf->msg_sig_ok && !ses->sigres) {
	INFO("Assertion without signature accepted due to message level signature (SimpleSign) %d", 0);
      } else {
	ses->sigres = ZXSIG_NO_SIG;
	if (!cf->nosig_fatal) {
	  ERR("Assertion not signed. Sigval(%s) %p", STRNULLCHKNULL(cgi.sigval), a7n->Signature);
	  zxid_set_fault(cf, ses, zxid_mk_fault(cf, TAS3_PEP_RQ_IN, "e:Client", "Assertion not signed.", TAS3_STATUS_NOSIG, 0, lk, 0));
	  return 0;
	} else {
	  INFO("SSO warn: assertion not signed, but configured to ignore this problem (NOSIG_FATAL=0). Sigval(%s) %p", STRNULLCHKNULL(cgi.sigval), a7n->Signature);
	}
      }
    }
  }
  if (cf->sig_fatal && ses->sigres) {
    ERR("Fail due to failed assertion signature sigres=%d", ses->sigres);
    zxid_set_fault(cf, ses, zxid_mk_fault(cf, TAS3_PEP_RQ_IN, "e:Client", "Assertion signature did not validate.", TAS3_STATUS_BADSIG, 0, lk, 0));
    return 0;
  }
  
  if (zxid_validate_cond(cf, &cgi, ses, a7n, zxid_my_entity_id(cf), 0, 0)) {
    zxid_set_fault(cf, ses, zxid_mk_fault(cf, TAS3_PEP_RQ_IN, "e:Client", "Conditions did not validate.", TAS3_STATUS_BADCOND, 0, lk, 0));
    return 0;
  }
  
  if (cf->log_rely_a7n) {
    DD("Logging... %d", 0);
    logpath = zxlog_path(cf, issuer, a7n->ID, ZXLOG_RELY_DIR, ZXLOG_A7N_KIND, 1);
    if (logpath) {
      ses->sso_a7n_path = ses->tgt_a7n_path = zx_str_to_c(cf->ctx, logpath);
      a7nss = zx_EASY_ENC_WO_sa_Assertion(cf->ctx, a7n);
      if (zxlog_dup_check(cf, logpath, "SSO assertion")) {
	if (cf->dup_a7n_fatal) {
	  zxlog_blob(cf, cf->log_rely_a7n, logpath, a7nss, "wsp_validade dup err");
	  return 0;
	}
      }
      zxlog_blob(cf, cf->log_rely_a7n, logpath, a7nss, "wsp_validate");
      zxlog(cf, 0, srcts, 0, issuer, 0, a7n->ID, nameid->gg.content, "N", "K", "A7N VALID", logpath->s, 0);
    }
  }
  return 1;
}

/*(i) Validate SOAP request (envelope), specified by the string.
 *
 * If the string starts by "<e:Envelope", then string
 * should be a complete SOAP envelope including <e:Header> (and <e:Body>)
 * parts.
 *
 * cf:: ZXID configuration object, see zxid_new_conf()
 * ses:: Session object that contains the EPR cache
 * az_cred:: (Optional) Additional authorization credentials or
 *     attributes, query string format. These credentials will be populated
 *     to the attribute pool in addition to the ones obtained from token and
 *     other sources. Then a PDP is called to get an authorization
 *     decision (matching obligations we support to those in the request,
 *     and obligations pleged by caller to those we insist on). See
 *     also PEPMAP configuration option. This implements generalized
 *     (application independent) Responder In PEP. To implement
 *     application dependent PEP features you should call zxid_az() directly.
 * env:: Entire SOAP envelope as a string
 * return:: idpnid of target identity of the request (rest of the information
 *     is populated to the session object, from where it can be retrieved).
 *     NULL if the validation fails. The target identity is still retrievable
 *     from the session, should there be desire to process the message despite
 *     the validation failure.
 *
 * See also: zxid_wsc_validate_resp_env() */

/* Called by:  main, zxidwspcgi_main */
char* zxid_wsp_validate(zxid_conf* cf, zxid_ses* ses, const char* az_cred, const char* enve)
{
  int n_refs = 0;
  struct zxsig_ref refs[ZXID_N_WSF_SIGNED_HEADERS];
  struct timeval ourts;
  struct timeval srcts = {0,501000};
  struct zx_root_s* r;
  zxid_entity* wsc_meta;
  struct zx_e_Envelope_s* env;
  struct zx_e_Header_s* hdr;
  struct zx_wsse_Security_s* sec;
  //zxid_a7n* a7n;
  struct zx_str* issuer;
  struct zx_str* logpath;
  struct zx_str  ss;
  zxid_cgi cgi;
  char* p;
  char msg[256];

  D_INDENT("valid: ");
  GETTIMEOFDAY(&ourts, 0);
  zxid_set_fault(cf, ses, 0);
  zxid_set_tas3_status(cf, ses, 0);
  
  ss.s = (char*)enve;
  ss.len = strlen(enve);
  LOCK(cf->ctx->mx, "valid");
  zx_prepare_dec_ctx(cf->ctx, zx_ns_tab, enve, enve + ss.len);
  r = zx_DEC_root(cf->ctx, 0, 1);
  UNLOCK(cf->ctx->mx, "valid");
  if (!r) {
    ERR("Malformed XML enve(%s)", enve);
    zx_format_parse_error(cf->ctx, msg, sizeof(msg), "valid");
    ERR("Detail: %s", msg);
    /* Squash " to ' because the message will appear in XML attribute value delimited by " */
    for (p = msg; *p; ++p)
      if (*p == '"')
	*p = '\'';
    zxid_set_fault(cf, ses, zxid_mk_fault(cf, TAS3_PEP_RQ_IN, "e:Client", "Malformed XML", "IDStarMsgNotUnderstood", 0, msg, 0));
    D_DEDENT("valid: ");
    return 0;
  }
  env = r->Envelope;
  if (!env) {
    ERR("No <e:Envelope> found. enve(%s)", enve);
    zxid_set_fault(cf, ses, zxid_mk_fault(cf, TAS3_PEP_RQ_IN, "e:Client", "No SOAP Envelope found.", "IDStarMsgNotUnderstood", 0, 0, 0));
    D_DEDENT("valid: ");
    return 0;
  }
  ZX_FREE(cf->ctx, r);

  hdr = env->Header;
  if (!hdr) {
    ERR("No <e:Header> found. enve(%s)", enve);
    zxid_set_fault(cf, ses, zxid_mk_fault(cf, TAS3_PEP_RQ_IN, "e:Client", "No SOAP Header found.", "IDStarMsgNotUnderstood", 0, 0, 0));
    D_DEDENT("valid: ");
    return 0;
  }
  if (!ZX_SIMPLE_ELEM_CHK(hdr->MessageID)) {
    ERR("No <a:MessageID> found. enve(%s)", enve);
    zxid_set_fault(cf, ses, zxid_mk_fault(cf, TAS3_PEP_RQ_IN, "e:Client", "No MessageID header found.", "IDStarMsgNotUnderstood", 0, 0, 0));
    D_DEDENT("valid: ");
    return 0;
  }
  /* Remember MessageID for generating RelatesTo in Response */
  ses->wsp_msgid = zx_str_to_c(cf->ctx, hdr->MessageID->gg.content);
  
  if (!hdr->Sender || !hdr->Sender->providerID
      && !hdr->Sender->affiliationID) {
    ERR("No <b:Sender> found (or missing providerID or affiliationID). enve(%s)", enve);
    zxid_set_fault(cf, ses, zxid_mk_fault(cf, TAS3_PEP_RQ_IN, "e:Client", "No b:Sender header found (or missing providerID or affiliationID).", "IDStarMsgNotUnderstood", 0, 0, 0));
    D_DEDENT("valid: ");
    return 0;
  }
  issuer = hdr->Sender->providerID;
  
  /* Validate message signature (*** add Issuer trusted check, CA validation, etc.) */
  
  if (!(sec = hdr->Security)) {
    ERR("No <wsse:Security> found. enve(%s)", enve);
    zxid_set_fault(cf, ses, zxid_mk_fault(cf, TAS3_PEP_RQ_IN, "e:Client", "No wsse:Security header found.", "IDStarMsgNotUnderstood", 0, 0, 0));
    D_DEDENT("valid: ");
    return 0;
  }

  if (!sec->Signature || !sec->Signature->SignedInfo || !sec->Signature->SignedInfo->Reference) {
    ses->sigres = ZXSIG_NO_SIG;
    if (cf->wsp_nosig_fatal) {
      ERR("No Security/Signature found. enve(%s) %p", enve, sec->Signature);
      zxid_set_fault(cf, ses, zxid_mk_fault(cf, TAS3_PEP_RQ_IN, "e:Client", "No wsse:Security/ds:Signature found.", TAS3_STATUS_NOSIG, 0, 0, 0));
      D_DEDENT("valid: ");
      return 0;
    } else {
      INFO("No Security/Signature found, but configured to ignore this problem (NOSIG_FATAL=0). %p", sec->Signature);
      D("No sig OK enve(%s)", enve);
    }
  }
  
  wsc_meta = zxid_get_ent_ss(cf, issuer);
  if (wsc_meta) {
    ZERO(refs, sizeof(refs));
    n_refs = zxid_hunt_sig_parts(cf, n_refs, refs, sec->Signature->SignedInfo->Reference, hdr, env->Body);
    /* *** Consider adding BDY and STR */
    ses->sigres = zxsig_validate(cf->ctx, wsc_meta->sign_cert, sec->Signature, n_refs, refs);
    zxid_sigres_map(ses->sigres, &cgi.sigval, &cgi.sigmsg);
    if (cf->sig_fatal && ses->sigres) {
      ERR("Fail due to failed message signature sigres=%d", ses->sigres);
      zxid_set_fault(cf, ses, zxid_mk_fault(cf, TAS3_PEP_RQ_IN, "e:Client", "Message signature did not validate.", TAS3_STATUS_BADSIG, 0, 0, 0));
      D_DEDENT("valid: ");
      return 0;
    }
  } else {
    ses->sigres = ZXSIG_NO_SIG;
    if (cf->nosig_fatal) {
      INFO("Unable to find SAML metadata for Sender(%.*s), but configured to ignore this problem (NOSIG_FATAL=0).", issuer->len, issuer->s);
    } else {
      ERR("Unable to find SAML metadata for Sender(%.*s).", issuer->len, issuer->s);
      zxid_set_fault(cf, ses, zxid_mk_fault(cf, TAS3_PEP_RQ_IN, "e:Client", "No unable to find SAML metadata for sender.", "ProviderIDNotValid", 0, 0, 0));
      D_DEDENT("valid: ");
      return 0;
    }
  }

  if (!zxid_wsf_timestamp_check(cf, ses, sec->Timestamp,&ourts,&srcts,TAS3_PEP_RQ_IN,"e:Client"))
    return 0;
  
  /* Check Requester Identity */

  ses->a7n = zxid_dec_a7n(cf, sec->Assertion, sec->EncryptedAssertion);
  if (ses->a7n && ses->a7n->Subject) {
    if (!zxid_wsf_validate_a7n(cf, ses, ses->a7n, "req", &srcts)) {
      D_DEDENT("valid: ");
      return 0;
    }
  } else {
    /* *** should there be absolute requirement for a requester assertion to exist? */
    ERR("No Requester <sa:Assertion> found. enve(%s)", enve);
    zxid_set_fault(cf, ses, zxid_mk_fault(cf, TAS3_PEP_RQ_IN, "e:Client", "No assertion found.", TAS3_STATUS_BADCOND, 0, 0, 0));
    D_DEDENT("valid: ");
    return 0;
  }

  /* Check Target Identity */

  if (hdr->TargetIdentity) {
    ses->tgta7n = zxid_dec_a7n(cf, hdr->TargetIdentity->Assertion, hdr->TargetIdentity->EncryptedAssertion);
    if (ses->tgta7n && ses->tgta7n->Subject) {
      if (!zxid_wsf_validate_a7n(cf, ses, ses->a7n, "tgt", &srcts)) {
	D_DEDENT("valid: ");
	return 0;
      }
    } else {
      ERR("No TargetIdentity <sa:Assertion> found. enve(%s)", enve);
      zxid_set_fault(cf, ses, zxid_mk_fault(cf, TAS3_PEP_RQ_IN, "e:Client", "No TargetIdentity Assertion found.", TAS3_STATUS_BADCOND, 0, 0, 0));
      D_DEDENT("valid: ");
      return 0;
    }
    
  } else {
    INFO("No explicit TargetIdentity, using requester identity as target identity. %d", 0);
    ses->tgta7n = ses->a7n;
    ses->tgtnameid = ses->nameid;
    ses->tgt = ses->nid;
    ses->tgtfmt = ses->nidfmt;
    ses->tgt_a7n_path = ses->sso_a7n_path;
  }

  if (hdr->UsageDirective) {
    if (hdr->UsageDirective->Obligation && hdr->UsageDirective->Obligation->AttributeAssignment && hdr->UsageDirective->Obligation->AttributeAssignment->gg.content) {
      ses->rcvd_usagedir = zx_str_to_c(cf->ctx, hdr->UsageDirective->Obligation->AttributeAssignment->gg.content);
      D("Found TAS3 UsageDirective with obligation(%s)", ses->rcvd_usagedir);
    } else if (hdr->UsageDirective->gg.content) {
      ses->rcvd_usagedir = zx_str_to_c(cf->ctx, hdr->UsageDirective->gg.content);
      D("Found unknown UsageDirective(%s)", ses->rcvd_usagedir);
    } else {
      ERR("UsageDirective empty or not understood. %p", hdr->UsageDirective->Dict);
    }
  }

  if (hdr->UsageDirective && hdr->UsageDirective->Obligation
      && ZX_STR_EQ(hdr->UsageDirective->Obligation->ObligationId, TAS3_SOL1_ENGINE)) {
    /* *** extract usage directive */
  }

  DD("Creating session... %d", 0);  /* *** */
  zxid_put_ses(cf, ses);
  zxid_ses_to_pool(cf, ses);
  zxid_snarf_eprs_from_ses(cf, ses);  /* Harvest attributes and bootstrap(s) */
  zxid_put_user(cf, ses->nameid->Format, ses->nameid->NameQualifier, ses->nameid->SPNameQualifier, ses->nameid->gg.content, 0);
  zxlog(cf, &ourts, &srcts, 0, issuer, 0, ses->a7n->ID, ses->nameid->gg.content, "N", "K", "PNEWSES", ses->sid, 0);
  
  /* Call Rq-In PDP */
  
  if (!zxid_localpdp(cf, ses)) {
    ERR("RQIN2 Deny by local PDP %d",0);
    zxid_set_fault(cf, ses, zxid_mk_fault(cf, TAS3_PEP_RS_OUT, "e:Server", "Request denied by WSP local policy", TAS3_STATUS_DENY, 0, 0, 0));
    /* Fall through, letting zxid_wsf_decor() pick up the fault and package it as response. */
  } else if (cf->pdp_url && *cf->pdp_url) {
    //zxid_add_attr_to_pool(cf, ses, "Action", zx_dup_str(cf->ctx, "access"));
    if (!zxid_pep_az_soap_pepmap(cf, 0, ses, cf->pdp_url, cf->pepmap_rqin)) {
      ERR("RQIN2 Deny %d", 0);
      zxid_set_fault(cf, ses, zxid_mk_fault(cf, TAS3_PEP_RQ_IN, "e:Server", "Request denied by WSP policy", TAS3_STATUS_DENY, 0, 0, 0));
      D_DEDENT("valid: ");
      return 0;
    }
  }
  
  logpath = zxlog_path(cf, issuer, hdr->MessageID->gg.content,
		       ZXLOG_RELY_DIR, ZXLOG_MSG_KIND, 1);
  if (zxlog_dup_check(cf, logpath, "validate request")) {
    if (cf->dup_msg_fatal) {
      zxlog_blob(cf, cf->log_rely_msg, logpath, &ss, "validate request dup err");
      zxid_set_fault(cf, ses, zxid_mk_fault(cf, TAS3_PEP_RS_IN, "e:Client", "Duplicate Message.", "DuplicateMsg", 0, 0, 0));
      D_DEDENT("valid: ");
      return 0;
    } else {
      INFO("Duplicate message detected, but configured to ignore this (DUP_MSG_FATAL=0). %d",0);
    }
  }
  zxlog_blob(cf, cf->log_rely_msg, logpath, &ss, "validate request");
  zxlog(cf, &ourts, &srcts, 0, issuer, 0, ses->a7n->ID, ses->nameid->gg.content, "N", "K", "VALID", logpath->s, 0);
  
  D_DEDENT("valid: ");
  return ses->tgt;
}

/* EOF  --  zxidwsp.c */
