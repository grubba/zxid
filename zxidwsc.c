/* zxidwsc.c  -  Handwritten nitty-gritty functions for Liberty ID-WSF Web Services Client
 * Copyright (c) 2009-2010 Sampo Kellomaki (sampo@iki.fi), All Rights Reserved.
 * Copyright (c) 2007-2009 Symlabs (symlabs@symlabs.com), All Rights Reserved.
 * Author: Sampo Kellomaki (sampo@iki.fi)
 * This is confidential unpublished proprietary source code of the author.
 * NO WARRANTY, not even implied warranties. Contains trade secrets.
 * Distribution prohibited unless authorized in writing.
 * Licensed under Apache License 2.0, see file COPYING.
 * $Id: zxidwsc.c,v 1.19 2010-01-08 02:10:09 sampo Exp $
 *
 * 7.1.2007,  created --Sampo
 * 7.10.2008, added documentation --Sampo
 * 7.1.2010,  added WSC signing --Sampo
 * 31.5.2010, added WSC sig validation and PDP calls --Sampo
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
#include "c/zx-e-data.h"

/*() WSC response validation work horse. This check the ID-WSF [SOAPbind2] specified
 * criteria, as well as additional criteria and calls PDP, if configured.
 *
 * cf:: ZXID configuration object, see zxid_new_conf()
 * ses:: Session object, used for attributes passed to az, and for recording errors
 * az_cred:: (Optional) Additional authorization credentials or
 *     attributes, query string format. These credentials will be populated
 *     to the attribute pool in addition to the ones obtained from token and
 *     other sources. Then a PDP is called to get an authorization
 *     decision (matching obligations we support to those in the request,
 *     and obligations pleged by caller to those we insist on). See
 *     also PEPMAP configuration option. This implements generalized
 *     (application independent) Responder In PEP. To implement
 *     application dependent PEP features you should call zxid_az() directly.
 * env:: Entire SOAP envelope as a data structure
 * enve:: SOAP envelope as string
 * return:: 1 on success, 0 on validation failure. Exact reason of the failure is
 *     available from ses->curflt and ses->curstatus.
 *
 * See also: zxid_wsp_validate() */

static int zxid_wsc_validate_resp_env(zxid_conf* cf, zxid_ses* ses, const char* az_cred, struct zx_e_Envelope_s* env, const char* enve)
{
  int n_refs = 0;
  struct zxsig_ref refs[ZXID_N_WSF_SIGNED_HEADERS];
  struct timeval ourts;
  struct timeval srcts = {0,501000};
  zxid_entity* wsc_meta;
  struct zx_wsse_Security_s* sec;
  struct zx_e_Header_s* hdr;
  struct zx_str* issuer;
  struct zx_str* logpath;
  struct zx_str ss;
  zxid_cgi cgi;

  GETTIMEOFDAY(&ourts, 0);
  zxid_set_fault(cf, ses, 0);
  zxid_set_tas3_status(cf, ses, 0);
  
  if (!env) {
    ERR("No <e:Envelope> found. enve(%s)", STRNULLCHK(enve));
    zxid_set_fault(cf, ses, zxid_mk_fault(cf, TAS3_PEP_RS_IN, "e:Server", "No SOAP Envelope found.", "IDStarMsgNotUnderstood", 0, 0, 0));
    return 0;
  }
  hdr = env->Header;
  if (!hdr) {
    ERR("No <e:Header> found. enve(%s)", STRNULLCHK(enve));
    zxid_set_fault(cf, ses, zxid_mk_fault(cf, TAS3_PEP_RS_IN, "e:Server", "No SOAP Header found.", "IDStarMsgNotUnderstood", 0, 0, 0));
    return 0;
  }
  if (!ZX_SIMPLE_ELEM_CHK(hdr->MessageID)) {
    ERR("No <a:MessageID> found. enve(%s)", STRNULLCHK(enve));
    zxid_set_fault(cf, ses, zxid_mk_fault(cf, TAS3_PEP_RS_IN, "e:Server", "No MessageID header found.", "IDStarMsgNotUnderstood", 0, 0, 0));
    return 0;
  }
  if (ZX_SIMPLE_ELEM_CHK(hdr->RelatesTo)) {
    if (ses->wsc_msgid) {
      if (strlen(ses->wsc_msgid) == hdr->RelatesTo->gg.content->len
	  && !memcmp(ses->wsc_msgid,
		     hdr->RelatesTo->gg.content->s,
		     hdr->RelatesTo->gg.content->len)) {
	D("RelatesTo check OK %d",1);
      } else {
	/* N.B. [SOAPBinding2] p.27, ll.818-822 indicates RelatesTo checking as SHOULD. */
	if (cf->relto_fatal) {
	  ERR("<a:RelatesTo> (%.*s) does not match request msgid(%s).", hdr->RelatesTo->gg.content->len, hdr->RelatesTo->gg.content->s, ses->wsc_msgid);
	  zxid_set_fault(cf, ses, zxid_mk_fault(cf, TAS3_PEP_RS_IN, "e:Server", "RelatesTo in response does not match request MessageID.", "InvalidRefToMsgID", 0, 0, 0));
	  return 0;
	} else {
	  INFO("<a:RelatesTo> (%.*s) does not match request msgid(%s), but configured to ignore this error (RELTO_FATAL=0).", hdr->RelatesTo->gg.content->len, hdr->RelatesTo->gg.content->s, ses->wsc_msgid);
	}
      }
    } else {
      INFO("Session does not have wsc_msgid. Skipping <a:RelatesTo> check. %d",0);
    }
  } else {
    if (cf->relto_fatal) {
      ERR("No <a:RelatesTo> found. enve(%s)", STRNULLCHK(enve));
      zxid_set_fault(cf, ses, zxid_mk_fault(cf, TAS3_PEP_RS_IN, "e:Server", "No RelatesTo header found in reply.", "IDStarMsgNotUnderstood", 0, 0, 0));
      return 0;
    } else {
      INFO("No <a:RelatesTo> found, but configured to ignore this (RELTO_FATAL=0). %d", 0);
      D("No RelTo OK enve(%s)", STRNULLCHK(enve));
    }
  }

  if (!hdr->Sender || !hdr->Sender->providerID && !hdr->Sender->affiliationID) {
    ERR("No <b:Sender> found (or missing providerID or affiliationID). enve(%s)", STRNULLCHK(enve));
    zxid_set_fault(cf, ses, zxid_mk_fault(cf, TAS3_PEP_RS_IN, "e:Server", "No b:Sender header found (or missing providerID or affiliationID).", "IDStarMsgNotUnderstood", 0, 0, 0));
    return 0;
  }
  issuer = hdr->Sender->providerID;
  
  /* Validate message signature (*** add Issuer trusted check, CA validation, etc.) */
  
  if (!(sec = hdr->Security)) {
    ERR("No <wsse:Security> found. enve(%s)", STRNULLCHK(enve));
    zxid_set_fault(cf, ses, zxid_mk_fault(cf, TAS3_PEP_RS_IN, "e:Server", "No wsse:Security header found.", "IDStarMsgNotUnderstood", 0, 0, 0));
    return 0;
  }

  if (!sec->Signature || !sec->Signature->SignedInfo || !sec->Signature->SignedInfo->Reference) {
    ses->sigres = ZXSIG_NO_SIG;
    if (cf->wsp_nosig_fatal) {
      ERR("No Security/Signature found. enve(%s) %p", STRNULLCHK(enve), sec->Signature);
      zxid_set_fault(cf, ses, zxid_mk_fault(cf, TAS3_PEP_RS_IN, "e:Server", "No wsse:Security/ds:Signature found.", TAS3_STATUS_NOSIG, 0, 0, 0));
      return 0;
    } else {
      INFO("No Security/Signature found, but configured to ignore this problem. %p", sec->Signature);
      D("No sig OK enve(%s)", STRNULLCHK(enve));
    }
  }
  
  wsc_meta = zxid_get_ent_ss(cf, issuer);
  if (!wsc_meta) {
    ses->sigres = ZXSIG_NO_SIG;
    if (cf->nosig_fatal) {
      INFO("Unable to find SAML metadata for Sender(%.*s), but configured to ignore this problem (NOSIG_FATAL=0).", issuer->len, issuer->s);
    } else {
      ERR("Unable to find SAML metadata for Sender(%.*s).", issuer->len, issuer->s);
      zxid_set_fault(cf, ses, zxid_mk_fault(cf, TAS3_PEP_RS_IN, "e:Server", "No unable to find SAML metadata for sender.", "ProviderIDNotValid", 0, 0, 0));
      return 0;
    }
  }

  ZERO(refs, sizeof(refs));
  n_refs = zxid_hunt_sig_parts(cf, n_refs, refs, sec->Signature->SignedInfo->Reference, hdr, env->Body);
  /* *** Consider adding BDY and STR */
  ses->sigres = zxsig_validate(cf->ctx, wsc_meta->sign_cert, sec->Signature, n_refs, refs);
  zxid_sigres_map(ses->sigres, &cgi.sigval, &cgi.sigmsg);
  if (cf->sig_fatal && ses->sigres) {
    ERR("Fail due to failed message signature sigres=%d", ses->sigres);
    zxid_set_fault(cf, ses, zxid_mk_fault(cf, TAS3_PEP_RS_IN, "e:Server", "Message signature did not validate.", TAS3_STATUS_BADSIG, 0, 0, 0));
    return 0;
  }

  if (!zxid_wsf_timestamp_check(cf, ses, sec->Timestamp, &ourts,&srcts,TAS3_PEP_RS_IN,"e:Server"))
    return 0;

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

  zxid_ses_to_pool(cf, ses);
  zxid_snarf_eprs_from_ses(cf, ses);  /* Harvest attributes and bootstrap(s) */

  if (hdr->Status && hdr->Status->code
      && (hdr->Status->code->len != 2
	  || hdr->Status->code->s[0] != 'O'
	  || hdr->Status->code->s[1] != 'K')) {
    ERR("TAS3 or app level error code(%.*s)", hdr->Status->code->len, hdr->Status->code->s);
    return 0;
  }
  
  /* Call Rs-In PDP */
  
  if (!zxid_localpdp(cf, ses)) {
    ERR("RSIN4 Deny by local PDP %d",0);
    zxid_set_fault(cf, ses, zxid_mk_fault(cf, TAS3_PEP_RS_IN, "e:Client", "Response denied by WSC local policy", TAS3_STATUS_DENY, 0, 0, 0));
    return 0;
  } else if (cf->pdp_url && *cf->pdp_url) {
    //zxid_add_attr_to_pool(cf, ses, "Action", zx_dup_str(cf->ctx, "access"));
    if (!zxid_pep_az_soap_pepmap(cf, 0, ses, cf->pdp_url, cf->pepmap_rsin)) {
      ERR("RSIN4 Deny %d", 0);
      zxid_set_fault(cf, ses, zxid_mk_fault(cf, TAS3_PEP_RS_IN, "e:Client", "Response denied by WSC policy at PDP", TAS3_STATUS_DENY, 0, 0, 0));
      return 0;
    }
  }
  
  /* *** execute (or store for future execution) the obligations. */
  
  ss.s = (char*)enve;
  ss.len = strlen(enve);
  logpath = zxlog_path(cf, issuer, hdr->MessageID->gg.content,
		       ZXLOG_RELY_DIR, ZXLOG_MSG_KIND, 1);
  if (zxlog_dup_check(cf, logpath, "validate response")) {
    if (cf->dup_msg_fatal) {
      zxlog_blob(cf, cf->log_rely_msg, logpath, &ss, "validate response dup err");
      zxid_set_fault(cf, ses, zxid_mk_fault(cf, TAS3_PEP_RS_IN, "e:Server", "Duplicate Message.", "DuplicateMsg", 0, 0, 0));
      return 0;
    } else {
      INFO("Duplicate message detected, but configured to ignore this (DUP_MSG_FATAL=0). %d",0);
    }
  }
  zxlog_blob(cf, cf->log_rely_msg, logpath, &ss, "validate response");
  zxlog(cf, &ourts, &srcts, 0, issuer, 0, ses->a7n?ses->a7n->ID:0, ses->nameid?ses->nameid->gg.content:0, "N", "K", "VALID", logpath->s, 0);
  return 1;
}

/*() Prepare some headers for WSC call */

/* Called by:  zxid_wsc_call */
static int zxid_wsc_prep(zxid_conf* cf, zxid_ses* ses, zxid_epr* epr, struct zx_e_Envelope_s* env)
{
  struct zx_sec_Token_s* tok;
  struct zx_e_Header_s* hdr;
  if (!zxid_wsf_decor(cf, ses, env, 0))
    return 0;
  hdr = env->Header;

  if (ses->call_tgttok || ses->call_invoktok && epr && epr->Metadata && epr->Metadata->SecurityContext && epr->Metadata->SecurityContext->Token) {
    if (ses->call_tgttok) {
      D("TargetIdentity: Explicit specification of ses->call_tgttok %d",0);
      tok = ses->call_tgttok;
    } else {
      D("TargetIdentity: Using token from EPR due to specification of ses->call_invoktok %d",0);
      tok = epr->Metadata->SecurityContext->Token;
    }
    hdr->TargetIdentity = zx_NEW_b_TargetIdentity(cf->ctx);
    hdr->TargetIdentity->actor = zx_ref_str(cf->ctx, SOAP_ACTOR_NEXT);
    hdr->TargetIdentity->mustUnderstand = zx_ref_str(cf->ctx, ZXID_TRUE);
    if (tok->EncryptedAssertion)
      hdr->TargetIdentity->EncryptedAssertion = tok->EncryptedAssertion;
    else if (tok->Assertion)
      hdr->TargetIdentity->Assertion = tok->Assertion;
    else {
      ERR("No <sa:EncryptedAssertion> or <sa:Assertion> found in <sec:Token> %p", tok);
    }
  } /* else this is just implied by the sec mech */

  hdr->To = zx_NEW_a_To(cf->ctx);
  hdr->To->gg.content = epr->Address->gg.content;
  hdr->To->actor = zx_ref_str(cf->ctx, SOAP_ACTOR_NEXT);
  hdr->To->mustUnderstand = zx_ref_str(cf->ctx, ZXID_TRUE);

  /* Mandatory for a request. */
  hdr->ReplyTo = zx_NEW_a_ReplyTo(cf->ctx);
  /*hdr->ReplyTo->Address = zxid_mk_addr(cf, zx_strf(cf->ctx, "%s?o=P", cf->url));*/
  hdr->ReplyTo->Address = zxid_mk_addr(cf, zx_dup_str(cf->ctx, A_ANON));
  hdr->ReplyTo->actor = zx_ref_str(cf->ctx, SOAP_ACTOR_NEXT);
  hdr->ReplyTo->mustUnderstand = zx_ref_str(cf->ctx, ZXID_TRUE);

#if 0
  /* Omission means to use same address as ReplyTo */
  hdr->FaultTo = zx_NEW_a_FaultTo(cf->ctx);
  hdr->FaultTo->Address = zx_mk_addr(cf->ctx, zx_strf(cf->ctx, "%s?o=P", cf->url));
  hdr->FaultTo->actor = zx_ref_str(cf->ctx, SOAP_ACTOR_NEXT);
  hdr->FaultTo->mustUnderstand = zx_ref_str(cf->ctx, ZXID_TRUE);
#endif

  zxid_attach_sol1_usage_directive(cf, ses, env, TAS3_PLEDGE, cf->wsc_localpdp_obl_pledge);
  return 1;
}

static void zxid_choose_security_token(zxid_conf* cf, zxid_ses* ses, zxid_epr* epr, struct zx_wsse_Security_s* sec)
{
  struct zx_sec_Token_s* tok;
  if (ses->call_invoktok) {
    D("Security Token: Explicit specification of ses->call_invoktok %d",0);
    tok = ses->call_invoktok;
  } else {
    if (epr && epr->Metadata && epr->Metadata->SecurityContext && epr->Metadata->SecurityContext->Token) {
      D("Security Token: Using token from EPR Metadata %d",0);
      tok = epr->Metadata->SecurityContext->Token;
    } else {
      ERR("Security Token: No SecurityContext in EPR Metadata %p",epr);
      return;
    }
  }
  if (tok->EncryptedAssertion)
    sec->EncryptedAssertion = tok->EncryptedAssertion;
  else if (tok->Assertion)
    sec->Assertion = tok->Assertion;
  else
    ERR("No <sa:EncryptedAssertion> or <sa:Assertion> found in <sec:Token> %p", tok);
}

/*() Perform security mechanism related processing for a WSC call */

/* Called by:  zxid_wsc_call */
static int zxid_wsc_prep_secmech(zxid_conf* cf, zxid_ses* ses, zxid_epr* epr, struct zx_e_Envelope_s* env)
{
  int secmech;
  struct zx_wsse_Security_s* sec;
  struct zx_wsse_SecurityTokenReference_s* str;
  struct zx_e_Header_s* hdr;
  
  if (!epr || !env) {
    ERR("MUST supply epr %p and envelope as arguments", epr);
    return 0;
  }

  hdr = env->Header;
  hdr->MessageID->gg.content = zxid_mk_id(cf, "urn:M", ZXID_ID_BITS);
  sec = hdr->Security;
  if (!sec || !sec->Timestamp || !sec->Timestamp->Created) {
    ERR("MUST supply wsse:Security and Timestamp %p", sec);
    return 0;
  }
  sec->Timestamp->Created->gg.content = zxid_date_time(cf, time(0));
    
  /* Clear away any credentials from previous iteration, if any. */
  sec->Signature = 0;
  sec->BinarySecurityToken = 0;
  sec->SecurityTokenReference = 0;
  sec->Assertion = 0;
  sec->sa11_Assertion = 0;
  sec->ff12_Assertion = 0;
    
  /* Sign all Headers that have Id set. See wsc_sign_sec_mech() */
  secmech = zxid_map_sec_mech(epr);
  switch (secmech) {
  case ZXID_SEC_MECH_NULL:
    D("secmech null %d", secmech);
    break;
  case ZXID_SEC_MECH_BEARER:
    zxid_choose_security_token(cf, ses, epr, sec);
    str = sec->SecurityTokenReference = zx_NEW_wsse_SecurityTokenReference(cf->ctx);
    str->KeyIdentifier = zx_NEW_wsse_KeyIdentifier(cf->ctx);
    str->KeyIdentifier->ValueType = zx_ref_str(cf->ctx, SAMLID_TOK_PROFILE);
    if (sec->Assertion)
      str->KeyIdentifier->gg.content = sec->Assertion->ID;
    /* *** In case of encrypted assertion, how is the KeyIdentifier populated? */
    
    zxid_wsf_sign(cf, cf->wsc_sign, sec, str, hdr, env->Body);
    D("secmech bearer %d", secmech);
    break;
  case ZXID_SEC_MECH_SAML:
    zxid_choose_security_token(cf, ses, epr, sec);
    /* *** Sign SEC, MID, TO, ACT (if any) */
    zxid_wsf_sign(cf, cf->wsc_sign, sec, 0, hdr, env->Body);
    D("secmech saml hok %d", secmech);
    break;
  case ZXID_SEC_MECH_X509:
    /* *** Sign SEC, MID, TO, ACT (if any) */
    zxid_wsf_sign(cf, cf->wsc_sign, sec, 0, hdr, env->Body);
    D("secmech x509 %d", secmech);
    break;
  case ZXID_SEC_MECH_PEERS:
    /* *** ? */
    D("secmech peers %d", secmech);
    break;
  default:
    ERR("Unknown secmech %d", secmech);
    return 0;
  }
  return 1;
}

/*(i) zxid_wsc_call() implements the main low level ID-WSF web service call
 * logic, including preparation of SOAP headers, use of sec mech (e.g.
 * preparation of wsse:Security header and signing of appropriate compoments
 * of the message), and sequencing of the call. In particular, it is
 * possible that WSP requests user interaction and thus the caller web
 * application will need to perform a redirect and then later call this
 * function again to continue the web service call after interaction.
 *
 * env (rather than Body) is taken as argument so that caller can prepare
 * additional SOAP headers at will before calling this function. This function
 * will add Liberty ID-WSF specific SOAP headers. */

/* Called by:  main x9, zxid_call, zxid_get_epr */
struct zx_e_Envelope_s* zxid_wsc_call(zxid_conf* cf, zxid_ses* ses, zxid_epr* epr, struct zx_e_Envelope_s* env, char** ret_enve)
{
  int i, res;
  struct zx_root_s* root;
  struct zx_e_Fault_s* flt;

  D_INDENT("wsc_call: ");
  
  if (!zxid_wsc_prep(cf, ses, epr, env)) {
    D_DEDENT("wsc_call: ");
    return 0;
  }
  
  for (i=0; i < cf->max_soap_retry; ++i) {
    if (!zxid_wsc_prep_secmech(cf, ses, epr, env)) {
      D_DEDENT("wsc_call: ");
      return 0;
    }
    ses->wsc_msgid = zx_str_to_c(cf->ctx, env->Header->MessageID->gg.content);
    
    root = zxid_soap_call_envelope(cf, epr->Address->gg.content, env, ret_enve);
    if (!root || !root->Envelope || !root->Envelope->Body) {
      ERR("soap call returned empty or seriously flawed response %p", root);
      D_DEDENT("wsc_call: ");
      return 0;
    }
    flt = root->Envelope->Body->Fault;
    if (flt) {
      D("SOAP Fault(%.*s) string(%.*s) actor(%.*s)", flt->faultcode?flt->faultcode->content->len:1, flt->faultcode?flt->faultcode->content->s:"?", flt->faultstring?flt->faultstring->content->len:1, flt->faultstring?flt->faultstring->content->s:"?", flt->faultactor?flt->faultactor->content->len:1, flt->faultactor?flt->faultactor->content->s:"?");
      D_DEDENT("wsc_call: ");
      return 0;
    }
    
    //res = zxid_wsf_analyze_result_headers(cf, ret);
    res = ZXID_OK;
    switch (res) {
    case ZXID_OK:
      D_DEDENT("wsc_call: ");
      return root->Envelope;
#if 0
    case ZXID_NEW_CRED:
      break;
    case ZXID_EP_MOVE:  // ***
      break;
    case ZXID_EP_UPDATE:
      break;
#endif
    case ZXID_REDIR_OK:
      D("Redirection requested (e.g. Interaction Service) %d", 0);
      D_DEDENT("wsc_call: ");
      return (void*)ZXID_REDIR_OK;
    default:
      ERR("Unknown result code: %d", res);
      D_DEDENT("wsc_call: ");
      return 0;
    }
  }
  ERR("Number of soap call retries exhausted max_soap_retry=%d", cf->max_soap_retry);
  D_DEDENT("wsc_call: ");
  return 0;
}

static char zx_env_body_open[]  = "<e:Envelope xmlns:e=\""zx_xmlns_e"\"><e:Header></e:Header><e:Body>";
static char zx_env_body_close[] = "</e:Body></e:Envelope>";
#if 0
static char zx_env_open[]  = "<e:Envelope xmlns:e=\""zx_xmlns_e"\"><e:Header></e:Header>";
static char zx_env_close[] = "</e:Envelope>";
#endif

/*() Convenience helper function to parse SOAP Envelope input string.
 * If the specified envelope is incomplete, it is completed.
 *
 * If the string starts by "<e:Envelope", then string
 * should be a complete SOAP envelope including <e:Header> and <e:Body> parts.
 * If the string starts by "<e:Body", then the <e:Envelope> and <e:Header> are
 * automatically added. If the string starts by neither of the above (be
 * careful to use the "e:" as namespace prefix), then it is assumed to be the
 * payload content of the <e:Body> and the rest of the SOAP envelope is added.
 */

/* Called by:  zxid_call, zxid_wsc_prepare_call, zxid_wsc_valid_resp, zxid_wsp_decorate */
struct zx_e_Envelope_s* zxid_add_env_if_needed(zxid_conf* cf, const char* enve)
{
  struct zx_e_Envelope_s* env;
  struct zx_root_s* r;
#if 0
#endif
  LOCK(cf->ctx->mx, "add_env");
  zx_prepare_dec_ctx(cf->ctx, zx_ns_tab, enve, enve + strlen(enve));
  r = zx_DEC_root(cf->ctx, 0, 1);
  UNLOCK(cf->ctx->mx, "add_env");
  if (!r) {
    ERR("Malformed XML enve(%s)", enve);
    return 0;
  }
  env = r->Envelope;
  if (env) {
    if (!env->Body)
      env->Body = zx_NEW_e_Body(cf->ctx);
    if (!env->Header)
      env->Header = zx_NEW_e_Header(cf->ctx);
  } else if (r->Body) {
    env = zx_NEW_e_Envelope(cf->ctx);
    if (r->Header)
      env->Header = r->Header;
    else
      env->Header = zx_NEW_e_Header(cf->ctx);
    env->Body = r->Body;
  } else { /* Resort to stringwise attempt to add envelope. */
    ZX_FREE(cf->ctx, r);
    if (!memcmp(enve, "<?xml ", sizeof("<?xml ")-1)) {  /* Ignore common, but unnecessary decl. */
      for (enve += sizeof("<?xml "); *enve && !(enve[0] == '?' && enve[1] == '>'); ++enve) ;
      if (*enve)
	enve += 2;
    }
    /* Must be just payload */
    enve = zx_alloc_sprintf(cf->ctx, 0, "%s%s%s", zx_env_body_open, enve, zx_env_body_close);
    LOCK(cf->ctx->mx, "add_env2");
    zx_prepare_dec_ctx(cf->ctx, zx_ns_tab, enve, enve + strlen(enve));
    r = zx_DEC_root(cf->ctx, 0, 1);
    UNLOCK(cf->ctx->mx, "add_env2");
    if (!r) {
      ERR("Malformed XML enve(%s)", enve);
      return 0;
    }
    env = r->Envelope;
  }
  ZX_FREE(cf->ctx, r);
  if (!env)
    ERR("No <e:Envelope> found in input argument. enve(%s)", enve);
  return env;
}

/* ----------------------------------------
 * Simplify writing WSCs */

/*() Make a SOAP call given XML payload for SOAP <e:Envelope> or <e:Body> content,
 * specified by the string. Assumes the EPR has already been discovered.
 * This is sometimes useful in prediscovered or delegated use cases, but
 * normally you should be using zxid_call() and let the discovery
 * take its course. */

/* Called by:  zxcall_main, zxid_callf */
struct zx_str* zxid_call_epr(zxid_conf* cf, zxid_ses* ses, zxid_epr* epr, const char* az_cred, const char* enve)
{
  char* ret_enve;
  struct zx_str* ret;
  struct zx_e_Envelope_s* env;

  if (!cf || !ses || !enve) {
    ERR("Missing mandatory arguments ses=%p", ses);
    return 0;
  }

  D_INDENT("call: ");
  env = zxid_add_env_if_needed(cf, enve);
  if (!env) {
    D_DEDENT("call: ");
    return 0;
  }
  
  /* Call Rq-Out PDP */
  
  if (!zxid_localpdp(cf, ses)) {
    ERR("RQOUT1 Deny by local PDP %d",0);
    zxid_set_fault(cf, ses, zxid_mk_fault(cf, TAS3_PEP_RQ_OUT, "e:Client", "Request denied by WSC local policy", TAS3_STATUS_DENY, 0, 0, 0));
    D_DEDENT("call: ");
    return 0;
  } else if (cf->pdp_url && *cf->pdp_url) {
    //zxid_add_attr_to_pool(cf, ses, "Action", zx_dup_str(cf->ctx, "access"));
    if (!zxid_pep_az_soap_pepmap(cf, 0, ses, cf->pdp_url, cf->pepmap_rqout)) {
      ERR("RQOUT1 Deny %d", 0);
      zxid_set_fault(cf, ses, zxid_mk_fault(cf, TAS3_PEP_RQ_OUT, "e:Client", "Request denied by WSC policy", TAS3_STATUS_DENY, 0, 0, 0));
      D_DEDENT("call: ");
      return 0;
    }
  }

  /* *** add usage directives */

  env = zxid_wsc_call(cf, ses, epr, env, &ret_enve);
  if (!env) {
    ERR("Web services call failed %d", 0);
    /* Let validate report the error so that tas3 status gets set correctly */
  }
  if (zxid_wsc_validate_resp_env(cf, ses, az_cred, env, ret_enve) != 1) {
    D_DEDENT("call: ");
    return 0;
  }
  
  ret = zx_EASY_ENC_SO_e_Envelope(cf->ctx, env);
  D_DEDENT("call: ");
  return ret;
}

/*() Call web service, printf style. See zxid_call() for more documentation.
 * Normally you should be calling zxid_callf() instead. */

/* Called by:  main */
struct zx_str* zxid_callf_epr(zxid_conf* cf, zxid_ses* ses, zxid_epr* epr, const char* az_cred, const char* env_f, ...)
{
  char* s;
  va_list ap;
  va_start(ap, env_f);
  s = zx_alloc_vasprintf(cf->ctx, 0, env_f, ap);
  va_end(ap);
  return zxid_call_epr(cf, ses, epr, az_cred, s);
}

/*(i) Make a SOAP call given XML payload for SOAP <e:Envelope> or <e:Body> content,
 * specified by the string. This is your WSC work horse for calling almost any kind
 * of web service. Simple and intuitive specification of XML as string: no need
 * to build complex data structures.
 *
 * If the string starts by "<e:Envelope", then string
 * should be a complete SOAP envelope including <e:Header> and <e:Body> parts. This
 * allows caller to specify custom SOAP headers, in addition to the ones
 * that the underlying zxid_wsc_call() will add. Usually the payload service
 * will be passed as the contents of the body. If the string starts by
 * "<e:Body", then the <e:Envelope> and <e:Header> are automatically added. If
 * the string starts by neither of the above (be careful to use the "e:" as
 * namespace prefix), then it is assumed to be the payload content of the <e:Body>
 * and the rest of the SOAP envelope is added.
 *
 * cf:: ZXID configuration object, see zxid_new_conf()
 * ses:: Session object that contains the EPR cache
 * svctype:: URI (often the namespace URI) specifying the kind of service we
 *     wish to call. Used for EPR lookup or discovery.
 * url:: (Optional) If provided, this argument has to match either
 *     the ProviderID, EntityID, or actual service endpoint URL.
 * di_opt:: (Optional) Additional discovery options for selecting the
 *     service, query string format
 * az_cred:: (Optional) Additional authorization credentials or
 *     attributes, query string format. These credentials will be populated
 *     to the attribute pool in addition to the ones obtained from SSO and
 *     other sources. Then a PDP is called to get an authorization decision
 *     (as well as obligations we pledge to support). See also PEPMAP
 *     configuration option. This implementes generalized (application
 *     independent) Requestor Out and Requestor In PEPs. To implement
 *     application dependent PEP features you should call zxid_az() directly.
 * env:: XML payload
 * return:: SOAP Envelope of the response, as a string. You can parse this
 *     string to obtain all returned SOAP headers as well as the Body and its
 *     content. NULL on failure. ses->curflt and/or ses->curstatus contain
 *     more detailed error information. */

struct zx_str* zxid_call(zxid_conf* cf, zxid_ses* ses, const char* svctype, const char* url, const char* di_opt, const char* az_cred, const char* enve)
{
  zxid_epr* epr;

  if (!cf || !ses) {
    ERR("Missing mandatory arguments ses=%p", ses);
    return 0;
  }

  epr = zxid_get_epr(cf, ses, svctype, url, di_opt, 0 /*Action*/, 1);
  if (!epr) {
    ERR("EPR could not be discovered for svctype(%s)", svctype);
    return 0;
  }
  
  return zxid_call_epr(cf, ses, epr, az_cred, enve);
}

/*() Call web service, printf style. See zxid_call() for more documentation. */

/* Called by:  main */
struct zx_str* zxid_callf(zxid_conf* cf, zxid_ses* ses, const char* svctype, const char* url, const char* di_opt, const char* az_cred, const char* env_f, ...)
{
  char* s;
  va_list ap;
  va_start(ap, env_f);
  s = zx_alloc_vasprintf(cf->ctx, 0, env_f, ap);
  va_end(ap);
  return zxid_call(cf, ses, svctype, url, di_opt, az_cred, s);
}

/*(i) Prepare a SOAP call given XML payload for SOAP <e:Envelope> or <e:Body> content,
 * specified by the string. Usually you should use zxid_call(), but if you want
 * to control the steps yourself or use your own http client, this function
 * may be useful.
 *
 * If the string starts by "<e:Envelope", then string
 * should be a complete SOAP envelope including <e:Header> and <e:Body> parts. This
 * allows caller to specify custom SOAP headers, in addition to the ones
 * that the underlying zxid_wsc_call() will add. Usually the payload service
 * will be passed as the contents of the body. If the string starts by
 * "<e:Body", then the <e:Envelope> and <e:Header> are automatically added. If
 * the string starts by neither of the above (be careful to use the "e:" as
 * namespace prefix), then it is assumed to be the payload content of the <e:Body>
 * and the rest of the SOAP envelope is added.
 *
 * cf:: ZXID configuration object, see zxid_new_conf()
 * ses:: Session object that contains the EPR cache
 * epr:: End point to call. From zxid_get_epr().
 * az_cred:: (Optional) Additional authorization credentials or
 *     attributes, query string format. These credentials will be populated
 *     to the attribute pool in addition to the ones obtained from SSO and
 *     other sources. Then a PDP is called to get an authorization decision
 *     (as well as obligations we pledge to support). See also PEPMAP
 *     configuration option. This implementes generalized (application
 *     independent) Requestor Out and Requestor In PEPs. To implement
 *     application dependent PEP features you should call zxid_az() directly.
 * env:: XML payload as a string
 * return:: SOAP Envelope ready to be sent to the WSP. You can pass this to HTTP client. */

/* Called by:  zxid_wsc_prepare_callf */
struct zx_str* zxid_wsc_prepare_call(zxid_conf* cf, zxid_ses* ses, zxid_epr* epr, const char* az_cred, const char* enve)
{
  struct zx_str* ret;
  struct zx_e_Envelope_s* env;

  if (!cf || !ses || !enve) {
    ERR("Missing mandatory arguments ses=%p", ses);
    return 0;
  }
  D_INDENT("prep: ");
  env = zxid_add_env_if_needed(cf, enve);
  if (!env) {
    D_DEDENT("prep: ");
    return 0;
  }
  
  //*** Needs thought and development

  if (!zxid_wsc_prep(cf, ses, epr, env)) {
    D_DEDENT("prep: ");
    return 0;
  }
  if (!zxid_wsc_prep_secmech(cf, ses, epr, env)) {
    D_DEDENT("prep: ");
    return 0;
  }
  ses->wsc_msgid = zx_str_to_c(cf->ctx, env->Header->MessageID->gg.content);

  /* Call Rq-Out PDP */
  
  if (!zxid_localpdp(cf, ses)) {
    ERR("RQOUT1 Deny by local PDP %d",0);
    zxid_set_fault(cf, ses, zxid_mk_fault(cf, TAS3_PEP_RQ_OUT, "e:Client", "Request denied by WSC local policy", TAS3_STATUS_DENY, 0, 0, 0));
    D_DEDENT("prep: ");
    return 0;
  } else if (cf->pdp_url && *cf->pdp_url) {
    //zxid_add_attr_to_pool(cf, ses, "Action", zx_dup_str(cf->ctx, "access"));
    if (!zxid_pep_az_soap_pepmap(cf, 0, ses, cf->pdp_url, cf->pepmap_rqout)) {
      ERR("RQOUT1 Deny %d", 0);
      zxid_set_fault(cf, ses, zxid_mk_fault(cf, TAS3_PEP_RQ_IN, "e:Client", "Request denied by WSC policy", TAS3_STATUS_DENY, 0, 0, 0));
      D_DEDENT("prep: ");
      return 0;
    }
  }
  
  /* *** add usage directives */

  ret = zx_EASY_ENC_SO_e_Envelope(cf->ctx, env);
  D_DEDENT("prep: ");
  return ret;
}

/*() Prepare a web service call, printf style.
 * See zxid_wsc_prepare_call() for more documentation. */

/* Called by: */
struct zx_str* zxid_wsc_prepare_callf(zxid_conf* cf, zxid_ses* ses, zxid_epr* epr, const char* az_cred, const char* env_f, ...)
{
  char* s;
  va_list ap;
  va_start(ap, env_f);
  s = zx_alloc_vasprintf(cf->ctx, 0, env_f, ap);
  va_end(ap);
  return zxid_wsc_prepare_call(cf, ses, epr, az_cred, s);
}

/*(i) Validate a response to web service call. Return: 1=valid. */

/* Called by: */
int zxid_wsc_valid_resp(zxid_conf* cf, zxid_ses* ses, const char* az_cred, const char* enve)
{
  int ret;
  struct zx_e_Envelope_s* env;

  if (!cf || !ses || !enve) {
    ERR("Missing mandatory arguments ses=%p enve=%p", ses, enve);
    return 0;
  }

  D_INDENT("valid: ");
  env = zxid_add_env_if_needed(cf, enve);
  ret = zxid_wsc_validate_resp_env(cf, ses, az_cred, env, enve);
  D_DEDENT("valid: ");
  return ret;
}

/* EOF  --  zxidwsc.c */
