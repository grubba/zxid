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

/*() Try to map security mechanisms across different frame works. Low level function. */

/* Called by:  zxid_wsc_call */
int zxid_map_sec_mech(struct zx_a_EndpointReference_s* epr)
{
  int len;
  char* s;
  if (!epr)
    return 0;
  if (!epr->Metadata)
    return 0;
  if (!epr->Metadata->SecurityContext)
    return 0;
  if (!epr->Metadata->SecurityContext->SecurityMechID)
    return 0;
  
  len = epr->Metadata->SecurityContext->SecurityMechID->content->len;
  s = epr->Metadata->SecurityContext->SecurityMechID->content->s;

  if (!len || !s)
    return 0;

  D("mapping secmec(%.*s)", len, s);

#define SEC_MECH_TEST(ret, val) if (len == sizeof(val)-1 && !memcmp(s, val, sizeof(val)-1)) return ret;
  
  SEC_MECH_TEST(ZXID_SEC_MECH_BEARER, WSF10_SEC_MECH_NULL_BEARER);
  SEC_MECH_TEST(ZXID_SEC_MECH_BEARER, WSF10_SEC_MECH_TLS_BEARER);
  SEC_MECH_TEST(ZXID_SEC_MECH_BEARER, WSF11_SEC_MECH_NULL_BEARER);
  SEC_MECH_TEST(ZXID_SEC_MECH_BEARER, WSF11_SEC_MECH_TLS_BEARER);
  SEC_MECH_TEST(ZXID_SEC_MECH_BEARER, WSF11_SEC_MECH_CLTLS_BEARER);
  SEC_MECH_TEST(ZXID_SEC_MECH_BEARER, WSF20_SEC_MECH_NULL_BEARER);
  SEC_MECH_TEST(ZXID_SEC_MECH_BEARER, WSF20_SEC_MECH_TLS_BEARER);
     
  SEC_MECH_TEST(ZXID_SEC_MECH_NULL, WSF11_SEC_MECH_NULL_NULL);
  SEC_MECH_TEST(ZXID_SEC_MECH_NULL, WSF11_SEC_MECH_TLS_NULL);
  SEC_MECH_TEST(ZXID_SEC_MECH_NULL, WSF11_SEC_MECH_CLTLS_NULL);
  SEC_MECH_TEST(ZXID_SEC_MECH_NULL, WSF20_SEC_MECH_NULL_NULL);
  SEC_MECH_TEST(ZXID_SEC_MECH_NULL, WSF20_SEC_MECH_TLS_NULL);

  SEC_MECH_TEST(ZXID_SEC_MECH_X509, WSF11_SEC_MECH_NULL_X509);
  SEC_MECH_TEST(ZXID_SEC_MECH_X509, WSF11_SEC_MECH_TLS_X509);
  SEC_MECH_TEST(ZXID_SEC_MECH_X509, WSF11_SEC_MECH_CLTLS_X509);
  
  SEC_MECH_TEST(ZXID_SEC_MECH_SAML, WSF11_SEC_MECH_NULL_SAML);
  SEC_MECH_TEST(ZXID_SEC_MECH_SAML, WSF11_SEC_MECH_TLS_SAML);
  SEC_MECH_TEST(ZXID_SEC_MECH_SAML, WSF11_SEC_MECH_CLTLS_SAML);
  SEC_MECH_TEST(ZXID_SEC_MECH_SAML, WSF20_SEC_MECH_NULL_SAML2);
  SEC_MECH_TEST(ZXID_SEC_MECH_SAML, WSF20_SEC_MECH_TLS_SAML2);
  SEC_MECH_TEST(ZXID_SEC_MECH_SAML, WSF20_SEC_MECH_CLTLS_SAML2);
     
  SEC_MECH_TEST(ZXID_SEC_MECH_PEERS, WSF20_SEC_MECH_CLTLS_PEERS2);

  ERR("Unknown security mechanism(%.*s), taking a guess...", len, s);
  
  if (len >= sizeof("Bearer")-1 && zx_memmem(s, len, "Bearer", sizeof("Bearer")-1))
    return ZXID_SEC_MECH_BEARER;
  if (len >= sizeof("SAML")-1 && zx_memmem(s, len, "SAML", sizeof("SAML")-1))
    return ZXID_SEC_MECH_BEARER;
  if (len >= sizeof("X509")-1 && zx_memmem(s, len, "X509", sizeof("X509")-1))
    return ZXID_SEC_MECH_BEARER;
  
  return 0;
}

/*() For purposes of signing, add references and canon forms of all known SOAP headers */

int zxid_add_header_refs(struct zxid_conf* cf, int n_refs, struct zxsig_ref* refs, struct zx_e_Header_s* hdr)
{
  /* Addressing and Security Headers */

  if (hdr->Framework) {
    if (!hdr->Framework->Id)
      hdr->Framework->Id = zx_ref_str(cf->ctx, "FWK");
    refs[n_refs].id = hdr->Framework->Id;
    refs[n_refs].canon = zx_EASY_ENC_SO_sbf_Framework(cf->ctx, hdr->Framework);
    ++n_refs;
  }
  
  if (hdr->Security && hdr->Security->Timestamp) {
    if (!hdr->Security->Timestamp->Id)
      hdr->Security->Timestamp->Id = zx_ref_str(cf->ctx, "TS");
    refs[n_refs].id = hdr->Security->Timestamp->Id;
    refs[n_refs].canon = zx_EASY_ENC_SO_wsu_Timestamp(cf->ctx, hdr->Security->Timestamp);
    ++n_refs;
  }

  if (hdr->MessageID) {
    if (!hdr->MessageID->Id)
      hdr->MessageID->Id = zx_ref_str(cf->ctx, "MID");
    refs[n_refs].id = hdr->MessageID->Id;
    refs[n_refs].canon = zx_EASY_ENC_SO_a_MessageID(cf->ctx, hdr->MessageID);
    ++n_refs;
  }
  
  if (hdr->RelatesTo) {
    if (!hdr->RelatesTo->Id)
      hdr->RelatesTo->Id = zx_ref_str(cf->ctx, "REL");
    refs[n_refs].id = hdr->RelatesTo->Id;
    refs[n_refs].canon = zx_EASY_ENC_SO_a_RelatesTo(cf->ctx, hdr->RelatesTo);
    ++n_refs;
  }
  
  if (hdr->Action) {
    if (!hdr->Action->Id)
      hdr->Action->Id = zx_ref_str(cf->ctx, "ACT");
    refs[n_refs].id = hdr->Action->Id;
    refs[n_refs].canon = zx_EASY_ENC_SO_a_Action(cf->ctx, hdr->Action);
    ++n_refs;
  }

  if (hdr->To) {
    if (!hdr->To->Id)
      hdr->To->Id = zx_ref_str(cf->ctx, "TO");
    refs[n_refs].id = hdr->To->Id;
    refs[n_refs].canon = zx_EASY_ENC_SO_a_To(cf->ctx, hdr->To);
    ++n_refs;
  }

  if (hdr->ReplyTo) {
    if (!hdr->ReplyTo->Id)
      hdr->ReplyTo->Id = zx_ref_str(cf->ctx, "REP");
    refs[n_refs].id = hdr->ReplyTo->Id;
    refs[n_refs].canon = zx_EASY_ENC_SO_a_ReplyTo(cf->ctx, hdr->ReplyTo);
    ++n_refs;
  }
  
  if (hdr->From) {
    if (!hdr->From->Id)
      hdr->From->Id = zx_ref_str(cf->ctx, "FRM");
    refs[n_refs].id = hdr->From->Id;
    refs[n_refs].canon = zx_EASY_ENC_SO_a_From(cf->ctx, hdr->From);
    ++n_refs;
  }
  
  if (hdr->Sender) {
    if (!hdr->Sender->Id)
      hdr->Sender->Id = zx_ref_str(cf->ctx, "PRV");
    refs[n_refs].id = hdr->Sender->Id;
    refs[n_refs].canon = zx_EASY_ENC_SO_b_Sender(cf->ctx, hdr->Sender);
    ++n_refs;
  }
  
  if (hdr->FaultTo) {
    if (!hdr->FaultTo->Id)
      hdr->FaultTo->Id = zx_ref_str(cf->ctx, "FLT");
    refs[n_refs].id = hdr->FaultTo->Id;
    refs[n_refs].canon = zx_EASY_ENC_SO_a_FaultTo(cf->ctx, hdr->FaultTo);
    ++n_refs;
  }
  
  if (hdr->ReferenceParameters) {
    if (!hdr->ReferenceParameters->Id)
      hdr->ReferenceParameters->Id = zx_ref_str(cf->ctx, "PAR");
    refs[n_refs].id = hdr->ReferenceParameters->Id;
    refs[n_refs].canon = zx_EASY_ENC_SO_a_ReferenceParameters(cf->ctx, hdr->ReferenceParameters);
    ++n_refs;
  }
  
  /* ID-WSF headers */
  
  if (hdr->TargetIdentity) {
    if (!hdr->TargetIdentity->Id)
      hdr->TargetIdentity->Id = zx_ref_str(cf->ctx, "TRG");
    refs[n_refs].id = hdr->TargetIdentity->Id;
    refs[n_refs].canon = zx_EASY_ENC_SO_b_TargetIdentity(cf->ctx, hdr->TargetIdentity);
    ++n_refs;
  }
  
  if (hdr->UsageDirective) {
    if (!hdr->UsageDirective->Id)
      hdr->UsageDirective->Id = zx_ref_str(cf->ctx, "UD");
    refs[n_refs].id = hdr->UsageDirective->Id;
    refs[n_refs].canon = zx_EASY_ENC_SO_b_UsageDirective(cf->ctx, hdr->UsageDirective);
    ++n_refs;
  }
  
  if (hdr->UserInteraction) {
    if (!hdr->UserInteraction->Id)
      hdr->UserInteraction->Id = zx_ref_str(cf->ctx, "UI");
    refs[n_refs].id = hdr->UserInteraction->Id;
    refs[n_refs].canon = zx_EASY_ENC_SO_b_UserInteraction(cf->ctx, hdr->UserInteraction);
    ++n_refs;
  }
  
  if (hdr->ProcessingContext) {
    if (!hdr->ProcessingContext->Id)
      hdr->ProcessingContext->Id = zx_ref_str(cf->ctx, "PC");
    refs[n_refs].id = hdr->ProcessingContext->Id;
    refs[n_refs].canon = zx_EASY_ENC_SO_b_ProcessingContext(cf->ctx, hdr->ProcessingContext);
    ++n_refs;
  }
  
  if (hdr->EndpointUpdate) {
    if (!hdr->EndpointUpdate->Id)
      hdr->EndpointUpdate->Id = zx_ref_str(cf->ctx, "EP");
    refs[n_refs].id = hdr->EndpointUpdate->Id;
    refs[n_refs].canon = zx_EASY_ENC_SO_b_EndpointUpdate(cf->ctx, hdr->EndpointUpdate);
    ++n_refs;
  }
  
  if (hdr->Timeout) {
    if (!hdr->Timeout->Id)
      hdr->Timeout->Id = zx_ref_str(cf->ctx, "TI");
    refs[n_refs].id = hdr->Timeout->Id;
    refs[n_refs].canon = zx_EASY_ENC_SO_b_Timeout(cf->ctx, hdr->Timeout);
    ++n_refs;
  }
  
  if (hdr->Consent) {
    if (!hdr->Consent->Id)
      hdr->Consent->Id = zx_ref_str(cf->ctx, "CON");
    refs[n_refs].id = hdr->Consent->Id;
    refs[n_refs].canon = zx_EASY_ENC_SO_b_Consent(cf->ctx, hdr->Consent);
    ++n_refs;
  }
  
  if (hdr->ApplicationEPR) {
    if (!hdr->ApplicationEPR->Id)
      hdr->ApplicationEPR->Id = zx_ref_str(cf->ctx, "AEP");
    refs[n_refs].id = hdr->ApplicationEPR->Id;
    refs[n_refs].canon = zx_EASY_ENC_SO_b_ApplicationEPR(cf->ctx, hdr->ApplicationEPR);
    ++n_refs;
  }
  
  if (hdr->RedirectRequest) {
    if (!hdr->RedirectRequest->Id)
      hdr->RedirectRequest->Id = zx_ref_str(cf->ctx, "RR");
    refs[n_refs].id = hdr->RedirectRequest->Id;
    refs[n_refs].canon = zx_EASY_ENC_SO_b_RedirectRequest(cf->ctx, hdr->RedirectRequest);
    ++n_refs;
  }
  
  if (hdr->CredentialsContext) {
    if (!hdr->CredentialsContext->Id)
      hdr->CredentialsContext->Id = zx_ref_str(cf->ctx, "CCX");
    refs[n_refs].id = hdr->CredentialsContext->Id;
    refs[n_refs].canon = zx_EASY_ENC_SO_b_CredentialsContext(cf->ctx, hdr->CredentialsContext);
    ++n_refs;
  }
  
  /* TAS3 specifics */
  
  if (hdr->Credentials) {
    if (!hdr->Credentials->Id)
      hdr->Credentials->Id = zx_ref_str(cf->ctx, "CRED");
    refs[n_refs].id = hdr->Credentials->Id;
    refs[n_refs].canon = zx_EASY_ENC_SO_tas3_Credentials(cf->ctx, hdr->Credentials);
    ++n_refs;
  }
  
  if (hdr->ESLPolicies) {
    if (!hdr->ESLPolicies->Id)
      hdr->ESLPolicies->Id = zx_ref_str(cf->ctx, "ESL");
    refs[n_refs].id = hdr->ESLPolicies->Id;
    refs[n_refs].canon = zx_EASY_ENC_SO_tas3_ESLPolicies(cf->ctx, hdr->ESLPolicies);
    ++n_refs;
  }
  
  /* Old ID-WSF 1.2 Headers and App specific headers */
  
  if (hdr->Correlation) {
    if (!hdr->Correlation->id)
      hdr->Correlation->id = zx_ref_str(cf->ctx, "COR");
    refs[n_refs].id = hdr->Correlation->id;
    refs[n_refs].canon
      = zx_EASY_ENC_SO_b12_Correlation(cf->ctx, hdr->Correlation);
    ++n_refs;
  }
  
  if (hdr->Provider) {
    if (!hdr->Provider->id)
      hdr->Provider->id = zx_ref_str(cf->ctx, "PC12");
    refs[n_refs].id = hdr->Provider->id;
    refs[n_refs].canon = zx_EASY_ENC_SO_b12_Provider(cf->ctx, hdr->Provider);
    ++n_refs;
  }
  
  if (hdr->b12_ProcessingContext) {
    if (!hdr->b12_ProcessingContext->id)
      hdr->b12_ProcessingContext->id = zx_ref_str(cf->ctx, "PC12");
    refs[n_refs].id = hdr->b12_ProcessingContext->id;
    refs[n_refs].canon = zx_EASY_ENC_SO_b12_ProcessingContext(cf->ctx, hdr->b12_ProcessingContext);
    ++n_refs;
  }
  
  if (hdr->b12_Consent) {
    if (!hdr->b12_Consent->id)
      hdr->b12_Consent->id = zx_ref_str(cf->ctx, "CON12");
    refs[n_refs].id = hdr->b12_Consent->id;
    refs[n_refs].canon = zx_EASY_ENC_SO_b12_Consent(cf->ctx, hdr->b12_Consent);
    ++n_refs;
  }
  
  if (hdr->b12_UsageDirective) {
    if (!hdr->b12_UsageDirective->id)
      hdr->b12_UsageDirective->id = zx_ref_str(cf->ctx, "UD12");
    refs[n_refs].id = hdr->b12_UsageDirective->id;
    refs[n_refs].canon = zx_EASY_ENC_SO_b12_UsageDirective(cf->ctx, hdr->b12_UsageDirective);
    ++n_refs;
  }
#if 0
  if (hdr->TransactionID) {
    if (!hdr->TransactionID->id)
      hdr->TransactionID->id = zx_ref_str(cf->ctx, "MM7TX");
    refs[n_refs].id = hdr->TransactionID->id;  /* *** mm7:TransactionID does not have id or Id */
    refs[n_refs].canon = zx_EASY_ENC_SO_mm7_TransactionID(cf->ctx, hdr->TransactionID);
    ++n_refs;
  }
#endif
  return n_refs;
}

void zxid_wsf_sign(struct zxid_conf* cf, int sign_flags, struct zx_wsse_Security_s* sec, struct zx_wsse_SecurityTokenReference_s* str, struct zx_e_Header_s* hdr, struct zx_e_Body_s* bdy)
{
  int n_refs;
  struct zxsig_ref refs[ZXID_N_WSF_SIGNED_HEADERS];
      
  if (sign_flags) {
    n_refs = 0;
    
    if (sign_flags & ZXID_SIGN_HDR)
      n_refs = zxid_add_header_refs(cf, n_refs, refs, hdr);
    
    if (str) {
      if (!str->Id)
	str->Id = zx_ref_str(cf->ctx, "STR");
      refs[n_refs].id = str->Id;
      refs[n_refs].canon = zx_EASY_ENC_SO_wsse_SecurityTokenReference(cf->ctx, str);
      ++n_refs;
    }
    
    if (bdy && (sign_flags & ZXID_SIGN_BDY)) {
      if (!bdy->id)
	bdy->id = zx_ref_str(cf->ctx, "BDY");
      refs[n_refs].id = bdy->id;
      refs[n_refs].canon = zx_EASY_ENC_SO_e_Body(cf->ctx, bdy);
      ++n_refs;
    }
   
    ASSERTOP(n_refs, <=, ZXID_N_WSF_SIGNED_HEADERS);

    if (!cf->sign_cert) /* Lazy load cert and private key */
      cf->sign_cert = zxid_read_cert(cf, "sign-nopw-cert.pem");
    if (!cf->sign_pkey)
      cf->sign_pkey = zxid_read_private_key(cf, "sign-nopw-cert.pem");
    sec->Signature = zxsig_sign(cf->ctx, n_refs, refs, cf->sign_cert, cf->sign_pkey);
  }
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

/* Called by:  main x15, zxid_call, zxid_get_epr */
struct zx_e_Envelope_s* zxid_wsc_call(struct zxid_conf* cf, struct zxid_ses* ses, struct zx_a_EndpointReference_s* epr, struct zx_e_Envelope_s* env)
{
  int i, res, secmech;
  struct zx_root_s* root;
  struct zx_e_Fault_s* flt;
  struct zx_wsse_Security_s* sec;
  struct zx_wsse_SecurityTokenReference_s* str;
  struct zx_e_Header_s* hdr;
  
  if (!env || !env->Body) {
    ERR("NULL SOAP envelope or body %p", env);
    return 0;
  }

  D_INDENT("wsc_call: ");
  
  if (!env->Header)
    env->Header = zx_NEW_e_Header(cf->ctx);
  hdr = env->Header;
  
  /* *** Much similarity to zxid_wsp_decor(), consider merge. */
  
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
  /**** for now, this is just implied by the sec mech */
  hdr->TargetIdentity = zx_NEW_b_TargetIdentity(cf->ctx);
  hdr->TargetIdentity->actor = zx_ref_str(cf->ctx, SOAP_ACTOR_NEXT);
  hdr->TargetIdentity->mustUnderstand = zx_ref_str(cf->ctx, ZXID_TRUE);
#endif

  hdr->To = zx_NEW_a_To(cf->ctx);
  hdr->To->gg.content = epr->Address->gg.content;
  hdr->To->actor = zx_ref_str(cf->ctx, SOAP_ACTOR_NEXT);
  hdr->To->mustUnderstand = zx_ref_str(cf->ctx, ZXID_TRUE);

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
  //sec->Id = zx_ref_str(cf->ctx, "SEC");
  sec->actor = zx_ref_str(cf->ctx, SOAP_ACTOR_NEXT);
  sec->mustUnderstand = zx_ref_str(cf->ctx, ZXID_TRUE);
  sec->Timestamp = zx_NEW_wsu_Timestamp(cf->ctx);
  sec->Timestamp->Created = zx_NEW_wsu_Created(cf->ctx);
  
  hdr->MessageID = zx_NEW_a_MessageID(cf->ctx);
  hdr->MessageID->actor = zx_ref_str(cf->ctx, SOAP_ACTOR_NEXT);
  hdr->MessageID->mustUnderstand = zx_ref_str(cf->ctx, ZXID_TRUE);
  
  for (i=0; i < cf->max_soap_retry; ++i) {
    
    /* Every iteration gets its own MessageID, Timestamp, and credential assertion. */
    
    hdr->MessageID->gg.content = zxid_mk_id(cf, "urn:M", ZXID_ID_BITS);;
    sec->Timestamp->Created->gg.content = zxid_date_time(cf, time(0));
    
    /* Clear away any credentials from previous iteration. */
    sec->Signature = 0;
    sec->BinarySecurityToken = 0;
    sec->SecurityTokenReference = 0;
    sec->Assertion = 0;
    sec->sa11_Assertion = 0;
    sec->ff12_Assertion = 0;
    
    /* Sign all Headers that have Id set. See wsc_sign_sec_mech() */
    secmech = zxid_map_sec_mech(epr);
    if (!secmech)
      secmech = ZXID_SEC_MECH_BEARER;
    switch (secmech) {
    case ZXID_SEC_MECH_NULL:
      D("secmech null %d", secmech);
      break;
    case ZXID_SEC_MECH_BEARER:
      if (epr->Metadata->SecurityContext->Token->EncryptedAssertion)
	sec->EncryptedAssertion = epr->Metadata->SecurityContext->Token->EncryptedAssertion;
      else if (epr->Metadata->SecurityContext->Token->Assertion)
	sec->Assertion = epr->Metadata->SecurityContext->Token->Assertion;
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
      if (epr->Metadata->SecurityContext->Token->EncryptedAssertion)
	sec->EncryptedAssertion
	  = epr->Metadata->SecurityContext->Token->EncryptedAssertion;
      else if (epr->Metadata->SecurityContext->Token->Assertion)
	sec->Assertion = epr->Metadata->SecurityContext->Token->Assertion;
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
    }
    
    root = zxid_soap_call_envelope(cf, epr->Address->gg.content, env);
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

/* ----------------------------------------
 * Simplify writing WSCs */

static char zx_env_body_open[]  = "<e:Envelope xmlns:e=\""zx_xmlns_e"\"><e:Header></e:Header><e:Body>";
static char zx_env_body_close[] = "</e:Body></e:Envelope>";
static char zx_env_open[]  = "<e:Envelope xmlns:e=\""zx_xmlns_e"\"><e:Header></e:Header>";
static char zx_env_close[] = "</e:Envelope>";

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
 *     content. */

/* Called by:  zxid_callf */
struct zx_str* zxid_call(struct zxid_conf* cf, struct zxid_ses* ses, const char* svctype, const char* url, const char* di_opt, const char* az_cred, const char* enve)
{
  struct zx_str* ret;
  struct zx_root_s* r;
  struct zx_e_Envelope_s* env;
  struct zx_a_EndpointReference_s* epr;
  D_INDENT("call: ");
  
  if (memcmp(enve, "<e:Envelope", sizeof("<e:Envelope")-1)) {
    if (memcmp(enve, "<e:Body", sizeof("<e:Body")-1)) {
      /* Must be just payload */
      enve = zx_alloc_sprintf(cf->ctx, 0, "%s%s%s", zx_env_body_open, enve, zx_env_body_close);
    } else {
      /* <e:Body> provided */
      enve = zx_alloc_sprintf(cf->ctx, 0, "%s%s%s", zx_env_open, enve, zx_env_close);
    }
  } /* else <e:Envelope> provided */

  zx_prepare_dec_ctx(cf->ctx, zx_ns_tab, enve, enve + strlen(enve));
  r = zx_DEC_root(cf->ctx, 0, 1);
  if (!r) {
    ERR("Malformed XML enve(%s)", enve);
    D_DEDENT("call: ");
    return 0;
  }
  env = r->Envelope;
  if (!env) {
    ERR("No <e:Envelope> found. enve(%s)", enve);
    D_DEDENT("call: ");
    return 0;
  }
  ZX_FREE(cf->ctx, r);

  //*** Needs thought and development

  epr = zxid_get_epr(cf, ses, svctype, url, di_opt, 0 /*Action*/, 1);
  if (!epr) {
    ERR("EPR could not be discovered for svctype(%s)", svctype);
    D_DEDENT("call: ");
    return 0;
  }

  /* *** Call Rq-Out PDP */
#if 0
  if (!zxid_pep_az_soap(cf, 0, ses, cf->pdp_url)) {
    D("Deny %d", 0);
    D_DEDENT("ab_pep: ");
    return "z";
  }
#endif

  env = zxid_wsc_call(cf, ses, epr, env);
  if (!env) {
    ERR("Web services call failed svctype(%s)", svctype);
    D_DEDENT("call: ");
    return 0;
  }
  
  /* *** Call Rq-In PDP */
#if 0
  if (!zxid_pep_az_soap(cf, 0, ses, cf->pdp_url)) {
    D("Deny %d", 0);
    D_DEDENT("ab_pep: ");
    return "z";
  }
#endif
  
  ret = zx_EASY_ENC_SO_e_Envelope(cf->ctx, env);
  D_DEDENT("call: ");
  return ret;
}

/*() Call web service, printf style. See zxid_call() for more documentation. */

/* Called by:  main */
struct zx_str* zxid_callf(struct zxid_conf* cf, struct zxid_ses* ses, const char* svctype, const char* url, const char* di_opt, const char* az_cred, const char* env_f, ...)
{
  char* s;
  va_list ap;
  va_start(ap, env_f);
  s = zx_alloc_vasprintf(cf->ctx, 0, env_f, ap);
  va_end(ap);
  return zxid_call(cf, ses, svctype, url, di_opt, az_cred, s);
}

/* EOF  --  zxidwsc.c */
