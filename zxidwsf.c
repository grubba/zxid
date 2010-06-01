/* zxidwsf.c  -  Handwritten nitty-gritty functions for Liberty ID-WSF Framework level
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
 * 31.5.2010, added complex sig validation and hunt --Sampo
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

/*() Try to map security mechanisms across different frame works. Low level
 * function. This also makes some elementary checks as to whether the
 * EPR is even capable of supporting the sec mech. */

/* Called by:  zxid_wsc_prep_secmech */
int zxid_map_sec_mech(zxid_epr* epr)
{
  int len;
  const char* s;
  struct zx_elem_s* secmechid;
  if (!epr || !epr->Metadata || !epr->Metadata->SecurityContext) {
    INFO("EPR lacks Metadata or SecurityContext. Forcing X509. %p", epr->Metadata);
    return ZXID_SEC_MECH_X509;
  }
  secmechid = epr->Metadata->SecurityContext->SecurityMechID;
  if (!secmechid || !secmechid->content
      || !secmechid->content->s || !secmechid->content->len) {
    if (epr->Metadata->SecurityContext->Token) {
      INFO("EPR does not specify sec mech id. Forcing Bearer. %p", secmechid);
      return ZXID_SEC_MECH_BEARER;
    } else {
      INFO("EPR lacks Token. Forcing X509. %p", secmechid);
      return ZXID_SEC_MECH_X509;
    }
  }

  len = secmechid->content->len;
  s = secmechid->content->s;

  D("mapping secmec(%.*s)", len, s);

#define SEC_MECH_TEST(ret, val) if (len == sizeof(val)-1 && !memcmp(s, val, sizeof(val)-1)) return ret;

  SEC_MECH_TEST(ZXID_SEC_MECH_X509, WSF11_SEC_MECH_NULL_X509);
  SEC_MECH_TEST(ZXID_SEC_MECH_X509, WSF11_SEC_MECH_TLS_X509);
  SEC_MECH_TEST(ZXID_SEC_MECH_X509, WSF11_SEC_MECH_CLTLS_X509);
  
  SEC_MECH_TEST(ZXID_SEC_MECH_NULL, WSF11_SEC_MECH_NULL_NULL);
  SEC_MECH_TEST(ZXID_SEC_MECH_NULL, WSF11_SEC_MECH_TLS_NULL);
  SEC_MECH_TEST(ZXID_SEC_MECH_NULL, WSF11_SEC_MECH_CLTLS_NULL);
  SEC_MECH_TEST(ZXID_SEC_MECH_NULL, WSF20_SEC_MECH_NULL_NULL);
  SEC_MECH_TEST(ZXID_SEC_MECH_NULL, WSF20_SEC_MECH_TLS_NULL);

  SEC_MECH_TEST(ZXID_SEC_MECH_PEERS, WSF20_SEC_MECH_CLTLS_PEERS2);

  if (!epr->Metadata->SecurityContext->Token) {
      INFO("EPR lacks Token despite not being NULL or X509. Forcing X509. %.*s", len, s);
      return ZXID_SEC_MECH_X509;
  }
  
  SEC_MECH_TEST(ZXID_SEC_MECH_BEARER, WSF10_SEC_MECH_NULL_BEARER);
  SEC_MECH_TEST(ZXID_SEC_MECH_BEARER, WSF10_SEC_MECH_TLS_BEARER);
  SEC_MECH_TEST(ZXID_SEC_MECH_BEARER, WSF11_SEC_MECH_NULL_BEARER);
  SEC_MECH_TEST(ZXID_SEC_MECH_BEARER, WSF11_SEC_MECH_TLS_BEARER);
  SEC_MECH_TEST(ZXID_SEC_MECH_BEARER, WSF11_SEC_MECH_CLTLS_BEARER);
  SEC_MECH_TEST(ZXID_SEC_MECH_BEARER, WSF20_SEC_MECH_NULL_BEARER);
  SEC_MECH_TEST(ZXID_SEC_MECH_BEARER, WSF20_SEC_MECH_TLS_BEARER);
     
  SEC_MECH_TEST(ZXID_SEC_MECH_SAML, WSF11_SEC_MECH_NULL_SAML);
  SEC_MECH_TEST(ZXID_SEC_MECH_SAML, WSF11_SEC_MECH_TLS_SAML);
  SEC_MECH_TEST(ZXID_SEC_MECH_SAML, WSF11_SEC_MECH_CLTLS_SAML);
  SEC_MECH_TEST(ZXID_SEC_MECH_SAML, WSF20_SEC_MECH_NULL_SAML2);
  SEC_MECH_TEST(ZXID_SEC_MECH_SAML, WSF20_SEC_MECH_TLS_SAML2);
  SEC_MECH_TEST(ZXID_SEC_MECH_SAML, WSF20_SEC_MECH_CLTLS_SAML2);

  ERR("Unknown security mechanism(%.*s), taking a guess...", len, s);
  
  if (len >= sizeof("Bearer")-1 && zx_memmem(s, len, "Bearer", sizeof("Bearer")-1))
    return ZXID_SEC_MECH_BEARER;
  if (len >= sizeof("SAML")-1 && zx_memmem(s, len, "SAML", sizeof("SAML")-1))
    return ZXID_SEC_MECH_BEARER;
  if (len >= sizeof("X509")-1 && zx_memmem(s, len, "X509", sizeof("X509")-1))
    return ZXID_SEC_MECH_BEARER;
  
  ERR("Unknown security mechanism(%.*s), uable to guess.", len, s);
  return ZXID_SEC_MECH_NULL;
}

#define ZX_URI_Id_CMP(hdr) ((hdr) && (hdr)->Id && (hdr)->Id->len == sref->URI->len-1 && !memcmp((hdr)->Id->s, sref->URI->s+1, (hdr)->Id->len))
#define ZX_URI_id_CMP(hdr) ((hdr) && (hdr)->id && (hdr)->id->len == sref->URI->len-1 && !memcmp((hdr)->id->s, sref->URI->s+1, (hdr)->id->len))

/*() For purposes of signature validation, add references and xml data structures
 * of all apparently signed message parts.
 * See also: zxid_add_header_refs() and zxsig_sign() or zxid_chk_sig() + zxsig_validate() */

/* Called by:  zxid_wsf_sign */
int zxid_hunt_sig_parts(zxid_conf* cf, int n_refs, struct zxsig_ref* refs, struct zx_ds_Reference_s* sref, struct zx_e_Header_s* hdr, struct zx_e_Body_s* bdy)
{
  for (; sref && n_refs < ZXID_N_WSF_SIGNED_HEADERS; sref = ZX_NEXT(sref)) {
    if (!sref->URI || !sref->URI->len || !sref->URI->s || !sref->URI->s[0]) {
      ERR("Malformed signature: Reference is missing URI %p n_refs=%d", sref->URI, n_refs);
      continue;
    }
    refs[n_refs].sref = sref;
    refs[n_refs].blob = 0;

    /* Addressing and Security Headers */

    if (ZX_URI_Id_CMP(hdr->Framework)) {
      D("Found ref URI(%.*s) Framework %d", sref->URI->len, sref->URI->s, n_refs);
      refs[n_refs].blob = (struct zx_elem_s*)hdr->Framework;
      ++n_refs;
      continue;
    }
  
    if (hdr->Security) {
      if (ZX_URI_Id_CMP(hdr->Security->Timestamp)) {
	D("Found ref URI(%.*s) Timestamp %d", sref->URI->len, sref->URI->s, n_refs);
	refs[n_refs].blob = (struct zx_elem_s*)hdr->Security->Timestamp;
	++n_refs;
	continue;
      }
      if (ZX_URI_Id_CMP(hdr->Security->SecurityTokenReference)) {
	D("Found ref URI(%.*s) SecurityTokenReference %d", sref->URI->len, sref->URI->s, n_refs);
	refs[n_refs].blob = (struct zx_elem_s*)hdr->Security->SecurityTokenReference;
	++n_refs;
	continue;
      }
    }

    if (ZX_URI_Id_CMP(hdr->MessageID)) {
      D("Found ref URI(%.*s) MessageID %d", sref->URI->len, sref->URI->s, n_refs);
      refs[n_refs].blob = (struct zx_elem_s*)hdr->MessageID;
      ++n_refs;
      continue;
    }
  
    if (ZX_URI_Id_CMP(hdr->RelatesTo)) {
      D("Found ref URI(%.*s) RelatesTo %d", sref->URI->len, sref->URI->s, n_refs);
      refs[n_refs].blob = (struct zx_elem_s*)hdr->RelatesTo;
      ++n_refs;
      continue;
    }
  
    if (ZX_URI_Id_CMP(hdr->Action)) {
      D("Found ref URI(%.*s) Action %d", sref->URI->len, sref->URI->s, n_refs);
      refs[n_refs].blob = (struct zx_elem_s*)hdr->Action;
      ++n_refs;
      continue;
    }

    if (ZX_URI_Id_CMP(hdr->To)) {
      D("Found ref URI(%.*s) To %d", sref->URI->len, sref->URI->s, n_refs);
      refs[n_refs].blob = (struct zx_elem_s*)hdr->To;
      ++n_refs;
      continue;
    }

    if (ZX_URI_Id_CMP(hdr->ReplyTo)) {
      D("Found ref URI(%.*s) ReplyTo %d", sref->URI->len, sref->URI->s, n_refs);
      refs[n_refs].blob = (struct zx_elem_s*)hdr->ReplyTo;
      ++n_refs;
      continue;
    }
  
    if (ZX_URI_Id_CMP(hdr->From)) {
      D("Found ref URI(%.*s) From %d", sref->URI->len, sref->URI->s, n_refs);
      refs[n_refs].blob = (struct zx_elem_s*)hdr->From;
      ++n_refs;
      continue;
    }
  
    if (ZX_URI_Id_CMP(hdr->Sender)) {
      D("Found ref URI(%.*s) Sender %d", sref->URI->len, sref->URI->s, n_refs);
      refs[n_refs].blob = (struct zx_elem_s*)hdr->Sender;
      ++n_refs;
      continue;
    }
  
    if (ZX_URI_Id_CMP(hdr->FaultTo)) {
      D("Found ref URI(%.*s) FaultTo %d", sref->URI->len, sref->URI->s, n_refs);
      refs[n_refs].blob = (struct zx_elem_s*)hdr->FaultTo;
      ++n_refs;
      continue;
    }
  
    if (ZX_URI_Id_CMP(hdr->ReferenceParameters)) {
      D("Found ref URI(%.*s) ReferenceParameters %d", sref->URI->len, sref->URI->s, n_refs);
      refs[n_refs].blob = (struct zx_elem_s*)hdr->ReferenceParameters;
      ++n_refs;
      continue;
    }
  
    /* ID-WSF headers */
  
    if (ZX_URI_Id_CMP(hdr->TargetIdentity)) {
      D("Found ref URI(%.*s) TargetIdentity %d", sref->URI->len, sref->URI->s, n_refs);
      refs[n_refs].blob = (struct zx_elem_s*)hdr->TargetIdentity;
      ++n_refs;
      continue;
    }
  
    if (ZX_URI_Id_CMP(hdr->UsageDirective)) {
      D("Found ref URI(%.*s) UsageDirective %d", sref->URI->len, sref->URI->s, n_refs);
      refs[n_refs].blob = (struct zx_elem_s*)hdr->UsageDirective;
      ++n_refs;
      continue;
    }
  
    if (ZX_URI_Id_CMP(hdr->UserInteraction)) {
      D("Found ref URI(%.*s) UserInteraction %d", sref->URI->len, sref->URI->s, n_refs);
      refs[n_refs].blob = (struct zx_elem_s*)hdr->UserInteraction;
      ++n_refs;
      continue;
    }
  
    if (ZX_URI_Id_CMP(hdr->ProcessingContext)) {
      D("Found ref URI(%.*s) ProcessingContext %d", sref->URI->len, sref->URI->s, n_refs);
      refs[n_refs].blob = (struct zx_elem_s*)hdr->ProcessingContext;
      ++n_refs;
      continue;
    }
  
    if (ZX_URI_Id_CMP(hdr->EndpointUpdate)) {
      D("Found ref URI(%.*s) EndpointUpdate %d", sref->URI->len, sref->URI->s, n_refs);
      refs[n_refs].blob = (struct zx_elem_s*)hdr->EndpointUpdate;
      ++n_refs;
      continue;
    }
  
    if (ZX_URI_Id_CMP(hdr->Timeout)) {
      D("Found ref URI(%.*s) Timeout %d", sref->URI->len, sref->URI->s, n_refs);
      refs[n_refs].blob = (struct zx_elem_s*)hdr->Timeout;
      ++n_refs;
      continue;
    }
  
    if (ZX_URI_Id_CMP(hdr->Consent)) {
      D("Found ref URI(%.*s) Consent %d", sref->URI->len, sref->URI->s, n_refs);
      refs[n_refs].blob = (struct zx_elem_s*)hdr->Consent;
      ++n_refs;
      continue;
    }
  
    if (ZX_URI_Id_CMP(hdr->ApplicationEPR)) {
      D("Found ref URI(%.*s) ApplicationEPR %d", sref->URI->len, sref->URI->s, n_refs);
      refs[n_refs].blob = (struct zx_elem_s*)hdr->ApplicationEPR;
      ++n_refs;
      continue;
    }
  
    if (ZX_URI_Id_CMP(hdr->RedirectRequest)) {
      D("Found ref URI(%.*s) RedirectRequest %d", sref->URI->len, sref->URI->s, n_refs);
      refs[n_refs].blob = (struct zx_elem_s*)hdr->RedirectRequest;
      ++n_refs;
      continue;
    }
  
    if (ZX_URI_Id_CMP(hdr->CredentialsContext)) {
      D("Found ref URI(%.*s) CredentialsContext %d", sref->URI->len, sref->URI->s, n_refs);
      refs[n_refs].blob = (struct zx_elem_s*)hdr->CredentialsContext;
      ++n_refs;
      continue;
    }
  
    /* TAS3 specifics */
  
    if (ZX_URI_Id_CMP(hdr->Credentials)) {
      D("Found ref URI(%.*s) Credentials %d", sref->URI->len, sref->URI->s, n_refs);
      refs[n_refs].blob = (struct zx_elem_s*)hdr->Credentials;
      ++n_refs;
      continue;
    }
  
    if (ZX_URI_Id_CMP(hdr->ESLPolicies)) {
      D("Found ref URI(%.*s) ESLPolicies %d", sref->URI->len, sref->URI->s, n_refs);
      refs[n_refs].blob = (struct zx_elem_s*)hdr->ESLPolicies;
      ++n_refs;
      continue;
    }
  
    /* Old ID-WSF 1.2 Headers and App specific headers */
  
    if (ZX_URI_id_CMP(hdr->Correlation)) {
      D("Found ref URI(%.*s) Correlation %d", sref->URI->len, sref->URI->s, n_refs);
      refs[n_refs].blob = (struct zx_elem_s*)hdr->Correlation;
      ++n_refs;
      continue;
    }
  
    if (ZX_URI_id_CMP(hdr->Provider)) {
      D("Found ref URI(%.*s) Provider %d", sref->URI->len, sref->URI->s, n_refs);
      refs[n_refs].blob = (struct zx_elem_s*)hdr->Provider;
      ++n_refs;
      continue;
    }
  
    if (ZX_URI_id_CMP(hdr->b12_ProcessingContext)) {
      D("Found ref URI(%.*s) b12_ProcessingContext %d", sref->URI->len, sref->URI->s, n_refs);
      refs[n_refs].blob = (struct zx_elem_s*)hdr->b12_ProcessingContext;
      ++n_refs;
      continue;
    }
  
    if (ZX_URI_id_CMP(hdr->b12_Consent)) {
      D("Found ref URI(%.*s) b12_Consent %d", sref->URI->len, sref->URI->s, n_refs);
      refs[n_refs].blob = (struct zx_elem_s*)hdr->b12_Consent;
      ++n_refs;
      continue;
    }
  
    if (ZX_URI_id_CMP(hdr->b12_UsageDirective)) {
      D("Found ref URI(%.*s) b12_UsageDirective %d", sref->URI->len, sref->URI->s, n_refs);
      refs[n_refs].blob = (struct zx_elem_s*)hdr->b12_UsageDirective;
      ++n_refs;
      continue;
    }
#if 0
    if (ZX_URI_id_CMP(hdr->TransactionID)) {
      D("Found ref URI(%.*s) TransactionID %d", sref->URI->len, sref->URI->s, n_refs);
      refs[n_refs].blob = (struct zx_elem_s*)hdr->TransactionID;
      ++n_refs;
      continue;
    }
#endif
    if (ZX_URI_id_CMP(bdy)) {
      D("Found ref URI(%.*s) Body %d", sref->URI->len, sref->URI->s, n_refs);
      refs[n_refs].blob = (struct zx_elem_s*)bdy;
      ++n_refs;
      continue;
    }
  }
  return n_refs;
}
/*() For purposes of signing, add references and canon forms of all known SOAP headers.
 * N.B. This function only works for preparing for signing.
 * See also: zxsig_sign(), zxid_hunt_sig_parts() or zxid_chk_sig() + zxsig_validate() */

/* Called by:  zxid_wsf_sign */
int zxid_add_header_refs(zxid_conf* cf, int n_refs, struct zxsig_ref* refs, struct zx_e_Header_s* hdr)
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

/*() Apply WSF style signature. */

/* Called by:  zxid_wsc_prep_secmech x3, zxid_wsf_decor */
void zxid_wsf_sign(zxid_conf* cf, int sign_flags, struct zx_wsse_Security_s* sec, struct zx_wsse_SecurityTokenReference_s* str, struct zx_e_Header_s* hdr, struct zx_e_Body_s* bdy)
{
  X509* sign_cert;
  RSA*  sign_pkey;
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

    if (zxid_lazy_load_sign_cert_and_pkey(cf, &sign_cert, &sign_pkey, "use sign cert wsc"))
      sec->Signature = zxsig_sign(cf->ctx, n_refs, refs, sign_cert, sign_pkey);
  }
}

/*() Check ID-WSF Timestamp.
 * The validity is controlled by configuration parameters BEFORE_SLOP and AFTER_SLOP.
 * returns 1 on success, 0 on failure. */

int zxid_wsf_timestamp_check(zxid_conf* cf, zxid_ses* ses, struct zx_wsu_Timestamp_s* ts, struct timeval* ourts, struct timeval* srcts, const char* ctlpt, const char* faultactor)
{
  if (ts && ZX_SIMPLE_ELEM_CHK(ts->Created)) {
    srcts->tv_sec = zx_date_time_to_secs(ts->Created->gg.content->s);
     
    if (srcts->tv_sec >= ourts->tv_sec - cf->before_slop
	&& srcts->tv_sec <= ourts->tv_sec + cf->after_slop) {
      D("Timestamp accepted src=%d our=%d before_slop=%d after_slop=%d", (int)srcts->tv_sec, (int)ourts->tv_sec, cf->before_slop, cf->after_slop);
    } else {
      if (cf->notimestamp_fatal) {
	ERR("Timestamp rejected: src=%d our=%d before_slop=%d after_slop=%d secs", (int)srcts->tv_sec, (int)ourts->tv_sec, cf->before_slop, cf->after_slop);
	zxid_set_fault(cf, ses, zxid_mk_fault(cf, ctlpt, faultactor, "Message signature did not validate.", "StaleMsg", 0, 0, 0));
	return 0;
      } else {
	INFO("Timestamp rejected: src=%d our=%d before_slop=%d after_slop=%d secs, but configured to ignore this (NOTIMESTAMPFATAL=0)", (int)srcts->tv_sec, (int)ourts->tv_sec, cf->before_slop, cf->after_slop);
      }
    }

  } else {
    if (cf->notimestamp_fatal) {
      ERR("No Security/Timestamp found. %p", ts);
      zxid_set_fault(cf, ses, zxid_mk_fault(cf, ctlpt, faultactor, "No unable to find wsse:Security/Timestamp.", "StaleMsg", 0, 0, 0));
      return 0;
    } else {
      INFO("No Security/Timestamp found, but configured to ignore this (NOTIMESTAMP_FATAL=0). %p", ts);
      D("No ts OK %p", ts);
    }
  }
  return 1;
}

/* EOF  --  zxidwsf.c */
