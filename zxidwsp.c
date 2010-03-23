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
 * 22.11.2009,  created --Sampo
 * 7.1.2010,    added WSP signing --Sampo
 */

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

/* Called by:  main, zxid_wsp_decorate */
int zxid_wsf_decor(struct zxid_conf* cf, struct zxid_ses* ses, struct zx_e_Envelope_s* env, int is_resp)
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
    hdr->RelatesTo = zx_NEW_a_RelatesTo(cf->ctx);
    hdr->RelatesTo->gg.content = zx_ref_str(cf->ctx, ses->msgid);
    hdr->RelatesTo->actor = zx_ref_str(cf->ctx, SOAP_ACTOR_NEXT);
    hdr->RelatesTo->mustUnderstand = zx_ref_str(cf->ctx, ZXID_TRUE);
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
 *     decision (generating obligations). See also PEPMAP configuration
 *     option. This implements generalized (application independent)
 *     Responder Out PEP. To implement application dependent PEP features
 *     you should call zxid_az() directly.
 * env:: XML payload
 * return:: SOAP Envelope of the response, as a string, ready to be
 *     sent as HTTP response. */

/* Called by:  main x7, zxid_wsp_decoratef, zxidwspcgi_parent */
struct zx_str* zxid_wsp_decorate(struct zxid_conf* cf, struct zxid_ses* ses, const char* az_cred, const char* enve)
{
  struct zx_str* ss;
  struct zx_root_s* r;
  struct zx_e_Envelope_s* env;

  D_INDENT("decor: ");

  env = zxid_add_env_if_needed(cf, enve);
  if (!env) {
    D_DEDENT("decor: ");
    return 0;
  }
  
  //*** Needs thought and development
  
  /* *** Call Rs-Out PDP */
  
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
struct zx_str* zxid_wsp_decoratef(struct zxid_conf* cf, struct zxid_ses* ses, const char* az_cred, const char* env_f, ...)
{
  char* s;
  va_list ap;
  va_start(ap, env_f);
  s = zx_alloc_vasprintf(cf->ctx, 0, env_f, ap);
  va_end(ap);
  return zxid_wsp_decorate(cf, ses, az_cred, s);
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
 *     the validation failure. */

/* Called by:  main, zxidwspcgi_main */
char* zxid_wsp_validate(struct zxid_conf* cf, struct zxid_ses* ses, const char* az_cred, const char* enve)
{
  int n_refs = 0;
  struct zxsig_ref refs[ZXID_N_WSF_SIGNED_HEADERS];
  struct timeval srcts = {0,501000};
  struct zx_root_s* r;
  struct zxid_entity* wsc_meta;
  struct zx_e_Envelope_s* env;
  struct zx_wsse_Security_s* sec;
  //struct zx_sa_Assertion_s* a7n;
  struct zx_str* issuer = 0; //&unknown_str;
  struct zx_str* subj = 0; //&unknown_str;
  struct zx_str* logpath;
  struct zx_str* a7nss;
  struct zx_str  ss;
  struct zxid_cgi cgi;

  D_INDENT("valid: ");
  
  ss.s = enve;
  ss.len = strlen(enve);
  LOCK(cf->ctx->mx, "valid");
  zx_prepare_dec_ctx(cf->ctx, zx_ns_tab, enve, enve + ss.len);
  r = zx_DEC_root(cf->ctx, 0, 1);
  UNLOCK(cf->ctx->mx, "valid");
  if (!r) {
    ERR("Malformed XML enve(%s)", enve);
    D_DEDENT("valid: ");
    return 0;
  }
  env = r->Envelope;
  if (!env) {
    ERR("No <e:Envelope> found. enve(%s)", enve);
    D_DEDENT("valid: ");
    return 0;
  }
  ZX_FREE(cf->ctx, r);

  if (!env->Header) {
    ERR("No <e:Header> found. enve(%s)", enve);
    D_DEDENT("valid: ");
    return 0;
  }
  if (!env->Header->MessageID) {
    ERR("No <a:MessageID> found. enve(%s)", enve);
    D_DEDENT("valid: ");
    return 0;
  }
  ses->msgid = zx_str_to_c(cf->ctx, env->Header->MessageID->gg.content);

  if (!env->Header->Sender || !env->Header->Sender->providerID
      && !env->Header->Sender->affiliationID) {
    ERR("No <b:Sender> found (or missing providerID or affiliationID). enve(%s)", enve);
    D_DEDENT("valid: ");
    return 0;
  }
  issuer = env->Header->Sender->providerID;

  if (!(sec = env->Header->Security)) {
    ERR("No <wsse:Security> found. enve(%s)", enve);
    D_DEDENT("valid: ");
    return 0;
  }

  if (!sec->Signature) {
    if (cf->wsp_nosig_fatal) {
      ERR("No Security/Signature found. enve(%s)", enve);
      D_DEDENT("valid: ");
      return 0;
    } else {
      INFO("No Security/Signature found. enve(%s)", enve);
    }
  }

  /* Validate message signature (*** add Issuer trusted check, CA validation, etc.) */
  
  wsc_meta = zxid_get_ent_ss(cf, issuer);
  if (!wsc_meta) {
    ERR("Unable to find metadata for Sender(%.*s).", issuer->len, issuer->s);
    D_DEDENT("valid: ");
    return 0;
    //cgi->sigval = "I";
    //cgi->sigmsg = "Issuer of Assertion unknown.";
    //ses->sigres = ZXSIG_NO_SIG;
    //if (cf->nosig_fatal) {  err = "P";  goto erro; }
  }

#if 0
    n_refs = zxid_add_header_refs(cf, n_refs, env->Header);

    if (a7n->Signature && a7n->Signature->SignedInfo && a7n->Signature->SignedInfo->Reference) {
      refs.sref = a7n->Signature->SignedInfo->Reference;
      refs.blob = (struct zx_elem_s*)a7n;
      ses->sigres = zxsig_validate(cf->ctx, idp_meta->sign_cert, a7n->Signature, 1, &refs);
      zxid_sigres_map(ses->sigres, &cgi->sigval, &cgi->sigmsg);
    } else {
      if (cf->msg_sig_ok && !ses->sigres) {
	INFO("Assertion without signature accepted due to message level signature (SimpleSign) %d", 0);
      } else {
	ERR("SSO warn: assertion not signed. Sigval(%s) %p", STRNULLCHKNULL(cgi->sigval), a7n->Signature);
	cgi->sigval = "N";
	cgi->sigmsg = "Assertion was not signed.";
	ses->sigres = ZXSIG_NO_SIG;
	if (cf->nosig_fatal) {
	  err = "P";
	  goto erro;
	}
      }
    }
#endif

  if (sec->Timestamp && sec->Timestamp->Created && sec->Timestamp->Created->gg.content
      && sec->Timestamp->Created->gg.content->s) {
    srcts.tv_sec = zx_date_time_to_secs(sec->Timestamp->Created->gg.content->s);
  } else {
    if (cf->notimestamp_fatal) {
      ERR("No Security/Timestamp found. enve(%s)", enve);
      D_DEDENT("valid: ");
      return 0;
    } else {
      INFO("No Security/Timestamp found. enve(%s)", enve);
    }
  }

  /* See zxid_sp_sso_finalize() for similar code.  *** consider factoring out commonality */

  ses->a7n = zxid_dec_a7n(cf, env->Header->Security->Assertion,
			  env->Header->Security->EncryptedAssertion);
  if (ses->a7n && ses->a7n->Subject) {

    ses->nameid = zxid_decrypt_nameid(cf, ses->a7n->Subject->NameID, ses->a7n->Subject->EncryptedID);
    if (!ses->nameid || !ses->nameid->gg.content) {
      ERR("SSO failed: assertion does not have Subject->NameID. %p", ses->nameid);
      D_DEDENT("valid: ");
      return 0;
    }
    
    subj = ses->nameid->gg.content;
    ses->nid = ses->tgt = zx_str_to_c(cf->ctx, subj);
    if (ses->nameid->Format && !memcmp(ses->nameid->Format->s, SAML2_TRANSIENT_NID_FMT, ses->nameid->Format->len)) {
      ses->nidfmt = ses->tgtfmt = 0;
    } else {
      ses->nidfmt = ses->tgtfmt = 1;  /* anything nontransient may be a federation */
    }

#if 0
    D("SSOA7N received. NID(%s) FMT(%d) SESIX(%s)", ses->nid, ses->nidfmt, STRNULLCHK(ses->sesix));
    
    /* Validate signature (*** add Issuer trusted check, CA validation, etc.) */
    
    idp_meta = zxid_get_ent_ss(cf, issuer);
    if (!idp_meta) {
      ERR("Unable to find metadata for Issuer(%.*s).", issuer->len, issuer->s);
      cgi->sigval = "I";
      cgi->sigmsg = "Issuer of Assertion unknown.";
      ses->sigres = ZXSIG_NO_SIG;
      if (cf->nosig_fatal) {
	err = "P";
	goto erro;
      }
    } else {
      if (a7n->Signature && a7n->Signature->SignedInfo && a7n->Signature->SignedInfo->Reference) {
	refs.sref = a7n->Signature->SignedInfo->Reference;
	refs.blob = (struct zx_elem_s*)a7n;
	ses->sigres = zxsig_validate(cf->ctx, idp_meta->sign_cert, a7n->Signature, 1, &refs);
	zxid_sigres_map(ses->sigres, &cgi->sigval, &cgi->sigmsg);
      } else {
	if (cf->msg_sig_ok && !ses->sigres) {
	  INFO("Assertion without signature accepted due to message level signature (SimpleSign) %d", 0);
	} else {
	  ERR("SSO warn: assertion not signed. Sigval(%s) %p", STRNULLCHKNULL(cgi->sigval), a7n->Signature);
	  cgi->sigval = "N";
	  cgi->sigmsg = "Assertion was not signed.";
	  ses->sigres = ZXSIG_NO_SIG;
	  if (cf->nosig_fatal) {
	    err = "P";
	    goto erro;
	  }
	}
      }
    }
    if (cf->sig_fatal && ses->sigres) {
      ERR("Fail SSO due to failed signeture sigres=%d", ses->sigres);
      err = "P";
      goto erro;
    }
    
    if (zxid_validate_cond(cf, cgi, ses, a7n, zxid_my_entity_id(cf), &ourts, &err))
      goto erro;    
#endif
    
    if (cf->log_rely_a7n) {
      DD("Logging... %d", 0);
      logpath = zxlog_path(cf, issuer, ses->a7n->ID, ZXLOG_RELY_DIR, ZXLOG_A7N_KIND, 1);
      if (logpath) {
	ses->sso_a7n_path = ses->tgt_a7n_path = zx_str_to_c(cf->ctx, logpath);
	a7nss = zx_EASY_ENC_WO_sa_Assertion(cf->ctx, ses->a7n);
	if (zxlog_dup_check(cf, logpath, "SSO assertion")) {
	  if (cf->dup_a7n_fatal) {
	    zxlog_blob(cf, cf->log_rely_a7n, logpath, a7nss, "wsp_validade dup err");
	    D_DEDENT("valid: ");
	    return 0;
	  }
	}
	zxlog_blob(cf, cf->log_rely_a7n, logpath, a7nss, "wsp_validate");
	zxlog(cf, 0, &srcts, 0, issuer, 0, ses->a7n->ID, subj, "N", "K", "A7N VALID", logpath->s, 0);  /* *** not yet validating */
      }
    }
    DD("Creating session... %d", 0);
    zxid_put_ses(cf, ses);
    zxid_ses_to_pool(cf, ses);
    zxid_snarf_eprs_from_ses(cf, ses);  /* Harvest attributes and bootstrap(s) */
    zxid_put_user(cf, ses->nameid->Format, ses->nameid->NameQualifier, ses->nameid->SPNameQualifier, ses->nameid->gg.content, 0);
    zxlog(cf, 0, &srcts, 0, issuer, 0, ses->a7n->ID, subj, "N", "K", "PNEWSES", ses->sid, 0);
  } else {
    ERR("No <sa:Assertion> found. enve(%s)", enve);
    D_DEDENT("valid: ");
    return 0;
  }

  if (env->Header->TargetIdentity) {
    
  } else {
    ses->tgta7n = ses->a7n;
  }

  /* *** Call Rs-In PDP */

  logpath = zxlog_path(cf, issuer, env->Header->MessageID->gg.content,
		       ZXLOG_RELY_DIR, ZXLOG_MSG_KIND, 1);
  if (zxlog_dup_check(cf, logpath, "validate request")) {
    if (cf->dup_msg_fatal) {
      zxlog_blob(cf, cf->log_rely_msg, logpath, &ss, "validate request dup err");
      D_DEDENT("valid: ");
      return 0;
    }
  }
  zxlog_blob(cf, cf->log_rely_msg, logpath, &ss, "validate request");
  zxlog(cf, 0, &srcts, 0, issuer, 0, ses->a7n->ID, subj, "N", "K", "VALID", logpath->s, 0);
  
  D_DEDENT("valid: ");
  return ses->tgt;
}

/* EOF  --  zxidwsp.c */
