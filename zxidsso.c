/* zxidsso.c  -  Handwritten functions for implementing Single Sign-On logic for SP
 * Copyright (c) 2006-2009 Symlabs (symlabs@symlabs.com), All Rights Reserved.
 * Author: Sampo Kellomaki (sampo@iki.fi)
 * This is confidential unpublished proprietary source code of the author.
 * NO WARRANTY, not even implied warranties. Contains trade secrets.
 * Distribution prohibited unless authorized in writing.
 * Licensed under Apache License 2.0, see file COPYING.
 * $Id: zxidsso.c,v 1.64 2010-01-08 02:10:09 sampo Exp $
 *
 * 12.8.2006, created --Sampo
 * 30.9.2006, added signature verification --Sampo
 * 9.10.2007, added signing SOAP requests, Destination for redirects --Sampo
 * 22.3.2008, permitted passing RelayState for SSO --Sampo
 * 7.10.2008,  added documentation --Sampo
 *
 * See also: http://hoohoo.ncsa.uiuc.edu/cgi/interface.html (CGI specification)
 */

#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <time.h>
#include <sys/time.h>
#include <sys/types.h>
#include <sys/stat.h>

#include "errmac.h"
#include "zxid.h"
#include "zxidconf.h"
#include "saml2.h"
#include "c/zx-const.h"
#include "c/zx-ns.h"
#include "c/zx-data.h"

/* ============== Generating and sending AuthnReq ============== */

/*() This function makes the policy decision about which profile to
 * use. It is only used if there was no explicit specification in the
 * CGI form (e.g. "Login (P)" button. Currently it's a stub that
 * always picks the artifact profile. Eventually configuration options
 * or cgi input can be used to determine the profile in a more
 * sophisticated way. Often zxid_mk_authn_req() will override the
 * return value of this function by its own inspection of the CGI
 * variables. */

/* Called by:  zxid_start_sso_url */
int zxid_pick_sso_profile(struct zxid_conf* cf, struct zxid_cgi* cgi, struct zxid_entity* idp_meta)
{
  /* More sophisticated policy may eventually go here. */
  return ZXID_SAML2_ART;
}

/*() Map name id format form field to SAML specified URN string. */
/* Called by:  zxid_mk_authn_req */
char* zxid_saml2_map_nid_fmt(char* f)
{
  switch (f[0]) {
  case 'n' /*'none'*/:   return "";
  case 'p' /*'prstnt'*/: return SAML2_PERSISTENT_NID_FMT;
  case 't' /*'trnsnt'*/: return SAML2_TRANSIENT_NID_FMT;
  case 'u' /*'unspfd'*/: return SAML2_UNSPECIFIED_NID_FMT;
  case 'e' /*'emladr'*/: return SAML2_EMAILADDR_NID_FMT;
  case 'x' /*'x509sn'*/: return SAML2_X509_NID_FMT;
  case 'w' /*'windmn'*/: return SAML2_WINDOMAINQN_NID_FMT;
  case 'k' /*'kerbrs'*/: return SAML2_KERBEROS_NID_FMT;
  case 's' /*'saml'*/:   return SAML2_ENTITY_NID_FMT;
  default:               return f;
  }
}

/*() Map protocol binding form field to SAML specified URN string. */
/* Called by: */
char* zxid_saml2_map_protocol_binding(char* b)
{
  switch (b[0]) {
  case 'r' /*'redir'*/: return SAML2_REDIR;
  case 'a' /*'art'*/:   return SAML2_ART;
  case 'p' /*'post'*/:  return SAML2_POST;
  case 'q' /*'qsimplesig'*/:  return SAML2_POST_SIMPLE_SIGN;
  case 's' /*'soap'*/:  return SAML2_SOAP;
  case 'e' /*'ecp'*/:
    /*case 'paos':*/  return SAML2_PAOS;
  default:      return b;
  }
}

/*() Map SAML protocol binding URN to form field. */
/* Called by:  zxid_idp_sso x3, zxid_sp_loc_by_index_raw */
int zxid_protocol_binding_map_saml2(struct zx_str* b)
{
  if (!b || !b->len || !b->s) {
    D("No binding supplied, assume redir %d", 0);
    return 'r';
  }
  if (b->len == sizeof(SAML2_REDIR)-1 && !memcmp(b->s, SAML2_REDIR, b->len)) return 'r';
  if (b->len == sizeof(SAML2_ART)-1   && !memcmp(b->s, SAML2_ART, b->len))   return 'a';
  if (b->len == sizeof(SAML2_POST)-1  && !memcmp(b->s, SAML2_POST, b->len))  return 'p';
  if (b->len == sizeof(SAML2_POST_SIMPLE_SIGN)-1  && !memcmp(b->s, SAML2_POST_SIMPLE_SIGN, b->len)) return 'q';
  if (b->len == sizeof(SAML2_SOAP)-1  && !memcmp(b->s, SAML2_SOAP, b->len))  return 's';
  if (b->len == sizeof(SAML2_PAOS)-1  && !memcmp(b->s, SAML2_PAOS, b->len))  return 'e';
  D("Unknown binding(%.*s) supplied, assume redir.", b->len, b->s);
  return 'r';
}

/*() Map authentication contest class ref form field to SAML specified URN string. */
/* Called by:  zxid_mk_authn_req */
char* zxid_saml2_map_authn_ctx(char* c)
{
  switch (c[0]) {
  case 'n' /*'none'*/:      return "";
  case 'p':
    switch (c[2]) {
    case 'p' /*'pwp'*/:     return SAML_AUTHCTX_PASSWORDPROTECTED;
    case 0   /*'pw'*/:      return SAML_AUTHCTX_PASSWORD;
    case 'v' /*'prvses'*/:  return SAML_AUTHCTX_PREVSESS;
    }
    break;
  case 'c' /*'clicert'*/:   return SAML_AUTHCTX_SSL_TLS_CERT;
  case 'u' /*'unspcf'*/:    return SAML_AUTHCTX_UNSPCFD;
  case 'i' /*'ip'*/:        return SAML_AUTHCTX_INPROT;
  }
  return c;
}

/*(i) Generate an authentication request and make a URL out of it.
 * cf::     Used for many configuration options and memory allocation
 * cgi::    Used to pick the desired SSO profile based on hidden fields or user input.
 * return:: Redirect URL as zx_str. Caller should eventually free this memory.
 */
/* Called by:  zxid_start_sso, zxid_start_sso_location */
struct zx_str* zxid_start_sso_url(struct zxid_conf* cf, struct zxid_cgi* cgi)
{
  struct zx_md_SingleSignOnService_s* sso_svc;
  struct zx_sp_AuthnRequest_s* ar;
  struct zx_str* ars;
  int sso_profile_ix;
  struct zxid_entity* idp_meta;
  D_INDENT("start_sso: ");
  D("start_sso: cgi=%p cgi->eid=%p eid(%s)", cgi, cgi->eid, cgi->eid?cgi->eid:"-");
  if (!cgi->pr_ix || !cgi->eid || !cgi->eid[0]) {
    D("Either protocol index or entity ID missing %d", cgi->pr_ix);
    cgi->err = "IdP URL Missing or incorrect";
    D_DEDENT("start_sso: ");
    return 0;
  }
  idp_meta = zxid_get_ent(cf, cgi->eid);
  if (!idp_meta) {
    cgi->err = "IdP URL incorrect or IdP does not support fetching metadata from that URL.";
    D_DEDENT("start_sso: ");
    return 0;
  }
  switch (sso_profile_ix = zxid_pick_sso_profile(cf, cgi, idp_meta)) {
  case ZXID_SAML2_ART:
  case ZXID_SAML2_POST:
  case ZXID_SAML2_POST_SIMPLE_SIGN:
    if (!idp_meta->ed->IDPSSODescriptor) {
      ERR("Entity(%s) does not have IdP SSO Descriptor (metadata problem)", cgi->eid);
      zxlog(cf, 0, 0, 0, 0, 0, 0, 0, "N", "B", "ERR", cgi->eid, "No IDPSSODescriptor");
      cgi->err = "Bad IdP metadata. Try different IdP.";
      D_DEDENT("start_sso: ");
      return 0;
    }
    for (sso_svc = idp_meta->ed->IDPSSODescriptor->SingleSignOnService;
	 sso_svc;
	 sso_svc = (struct zx_md_SingleSignOnService_s*)sso_svc->gg.g.n)
      if (sso_svc->Binding && !memcmp(SAML2_REDIR, sso_svc->Binding->s, sso_svc->Binding->len))
	break;
    if (!sso_svc) {
      ERR("IdP Entity(%s) does not have any IdP SSO Service with " SAML2_REDIR " binding (metadata problem)", cgi->eid);
      zxlog(cf, 0, 0, 0, 0, 0, 0, 0, "N", "B", "ERR", cgi->eid, "No redir binding");
      cgi->err = "Bad IdP metadata. Try different IdP.";
      D_DEDENT("start_sso: ");
      return 0;
    }
    ar = zxid_mk_authn_req(cf, cgi);
    ar->Destination = sso_svc->Location;
    ars = zx_EASY_ENC_SO_sp_AuthnRequest(cf->ctx, ar);
    D("AuthnReq(%.*s)", ars->len, ars->s);
    break;
  default:
    NEVER("Inappropriate SSO profile: %d", sso_profile_ix);
    cgi->err = "Inappropriate SSO profile. Bad metadata?";
    D_DEDENT("start_sso: ");
    return 0;
  }
  if (cf->log_level>0)
    zxlog(cf, 0, 0, 0, 0, 0, 0, 0, "N", "W", "ANREDIR", cgi->eid, 0);
  ars = zxid_saml2_redir_url(cf, sso_svc->Location, ars, cgi->rs);
  D_DEDENT("start_sso: ");
  return ars;
}

/*() Wrapper for zxid_start_sso_url(), used in CGI scripts. */

/* Called by:  main x2, zxid_simple_no_ses_cf */
int zxid_start_sso(struct zxid_conf* cf, struct zxid_cgi* cgi)
{
  struct zx_str* url = zxid_start_sso_url(cf, cgi);
  if (!url)
    return 0;
  printf("Location: %.*s" CRLF2, url->len, url->s);
  return ZXID_REDIR_OK;
}

/*() Wrapper for zxid_start_sso_url(), used when Location header needs to be passed outside.
 * return:: Location header as zx_str. Caller should eventually free this memory. */

/* Called by:  zxid_simple_no_ses_cf */
struct zx_str* zxid_start_sso_location(struct zxid_conf* cf, struct zxid_cgi* cgi)
{
  struct zx_str* ss;
  struct zx_str* url = zxid_start_sso_url(cf, cgi);
  if (!url)
    return 0; //zx_dup_str(cf->ctx, "* ERR");
  ss = zx_strf(cf->ctx, "Location: %.*s" CRLF2, url->len, url->s);
  zx_str_free(cf->ctx, url);
  return ss;
}

/* ============== Process Response and SSO Assertion ============== */

/*(i) Dereference an artifact to obtain an assertion. This is the last
 * step in artifact SSO profile and involved making a SOAP call to the
 * IdP. The artifact is received in saml_art CGI field, <<see:
 * zxid_parse_cgi()>> where SAMLart query string argument is parsed. */

/* Called by:  main x2, zxid_simple_no_ses_cf */
int zxid_sp_deref_art(struct zxid_conf* cf, struct zxid_cgi* cgi, struct zxid_ses* ses)
{
  struct zx_md_ArtifactResolutionService_s* ar_svc;
  struct zx_e_Body_s* body;
  struct zx_root_s* r;
  struct zxid_entity* idp_meta;
  int len;
  char end_pt_ix[16];
  char* raw_succinct_id;
  /*char* msg_handle;*/
  char* p;
  char buf[64];
  D_INDENT("deref: ");
  len = strlen(cgi->saml_art);
  if (cf->log_level > 0)
    zxlog(cf, 0, 0, 0, 0, 0, 0, ses->nameid?ses->nameid->gg.content:0, "N", "W", "ART", cgi->saml_art, 0);
  if (len-7 >= sizeof(buf)*4/3) {
    ERR("SAMLart(%s), %d chars, too long. Max(%d) chars.", cgi->saml_art, len, sizeof(buf)*4/3+6);
    zxlog(cf, 0, 0, 0, 0, 0, 0, 0, "N", "C", "ERR", cgi->saml_art, "Artifact too long");
    D_DEDENT("deref: ");
    return 0;
  }
  p = unbase64_raw(cgi->saml_art, cgi->saml_art + len, buf, zx_std_index_64);
  *p = 0;
  if (buf[0])
    goto badart;
  switch (buf[1]) {
  case 0x03: /* SAML 1.1 */
    end_pt_ix[0] = 0;
    raw_succinct_id = buf + 2;
    /*msg_handle = buf + 22;*/
    break;
  case 0x04: /* SAML 2.0 */
    sprintf(end_pt_ix, "%d", (unsigned)buf[2] << 8 | (unsigned)buf[3]);
    raw_succinct_id = buf + 4;
    /*msg_handle = buf + 24;*/
    break;
  default: goto badart;
  }
  
  idp_meta = zxid_get_ent_by_succinct_id(cf, raw_succinct_id);
  if (!idp_meta) {
    ERR("Unable to dereference SAMLart(%s). Can not find metadata for IdP.", cgi->saml_art);
    D_DEDENT("deref: ");
    return 0;
  }
  
  switch (buf[1]) {
  case 0x03: /* SAML 1.1 */
    /* *** ff12_resolve_art() */
    break;
  case 0x04: /* SAML 2.0 */
    if (!idp_meta->ed->IDPSSODescriptor) {
      ERR("Entity(%.*s) does not have IdP SSO Descriptor (metadata problem)", idp_meta->eid_len, idp_meta->eid);
      zxlog(cf, 0, 0, 0, 0, 0, 0, 0, "N", "B", "ERR", 0, "No IDPSSODescriptor eid(%.*)", idp_meta->eid_len, idp_meta->eid);
      D_DEDENT("deref: ");
      return 0;
    }
    for (ar_svc = idp_meta->ed->IDPSSODescriptor->ArtifactResolutionService;
	 ar_svc;
	 ar_svc = (struct zx_md_ArtifactResolutionService_s*)ar_svc->gg.g.n)
      if (ar_svc->Binding  && !memcmp(SAML2_SOAP, ar_svc->Binding->s, ar_svc->Binding->len)
	  && ar_svc->index && !memcmp(end_pt_ix, ar_svc->index->s, ar_svc->index->len)
	  && ar_svc->Location)
	break;
    if (!ar_svc) {
      ERR("Entity(%.*s) does not have any IdP Artifact Resolution Service with " SAML2_SOAP " binding and index(%s) (metadata problem)", idp_meta->eid_len, idp_meta->eid, end_pt_ix);
      zxlog(cf, 0, 0, 0, 0, 0, 0, 0, "N", "B", "ERR", 0, "No Artifact Resolution Svc eid(%.*) ep_ix(%s)", idp_meta->eid_len, idp_meta->eid, end_pt_ix);
      D_DEDENT("deref: ");
      return 0;
    }
    
    body = zx_NEW_e_Body(cf->ctx);
    body->ArtifactResolve = zxid_mk_art_deref(cf, idp_meta, cgi->saml_art);
    r = zxid_soap_call_body(cf, ar_svc->Location, body);
    len =  zxid_sp_soap_dispatch(cf, cgi, ses, r);
    D_DEDENT("deref: ");
    return len;
  default: goto badart;
  }
  
 badart:
  ERR("Bad SAMLart type code 0x%02x 0x%02x", buf[0], buf[1]);
  zxlog(cf, 0, 0, 0, 0, 0, 0, 0, "N", "C", "ERR", 0, "Bad SAMLart type code 0x%02x 0x%02x", buf[0], buf[1]);
  D_DEDENT("deref: ");
  return 0;
}

/*() Map ZXSIG constant to letter for log and string message. */

/* Called by:  zxid_chk_sig, zxid_decode_redir_or_post, zxid_sp_sso_finalize */
void zxid_sigres_map(int sigres, char** sigval, char** sigmsg)
{
  switch (sigres) {
  case ZXSIG_OK:
    D("Signature validated. %d", 1);
    *sigval = "O";
    *sigmsg = "Signature validated.";
    break;
  case ZXSIG_BAD_DALGO:  /* 1 Unsupported digest algorithm. */
    ERR("Bad digest algo. %d", sigres);
    *sigval = "A";
    *sigmsg = "Unsupported digest algorithm. Signature can not be validated.";
    break;
  case ZXSIG_DIGEST_LEN: /* 2 Wrong digest length. */
    ERR("Bad digest length. %d", sigres);
    *sigval = "G";
    *sigmsg = "Wrong digest length. Signature can not be validated.";
    break;
  case ZXSIG_BAD_DIGEST: /* 3 Digest value does not match. */
    ERR("Bad digest. Canon problem? %d", sigres);
    *sigval = "G";
    *sigmsg = "Message digest does not match signed content. Canonicalization problem? Or falsified or altered or substituted content. Signature can not be validated.";
    break;
  case ZXSIG_BAD_SALGO:  /* 4 Unsupported signature algorithm. */
    ERR("Bad sig algo. %d", sigres);
    *sigval = "A";
    *sigmsg = "Unsupported signature algorithm. Signature can not be validated.";
    break;
  case ZXSIG_BAD_CERT:   /* 5 Extraction of public key from certificate failed. */
    ERR("Bad cert. %d", sigres);
    *sigval = "I";
    *sigmsg = "Bad IdP certificate or bad IdP metadata or unknown IdP. Signature can not be validated.";
    break;
  case ZXSIG_VFY_FAIL:   /* 6 Verification of signature failed. */
    ERR("Bad sig. %d", sigres);
    *sigval = "R";
    *sigmsg = "Signature does not match signed content (but content checksum matches). Content may have been falsified, altered, or substituted; or IdP metadata does not match the keys actually used by the IdP.";
    break;
  case ZXSIG_NO_SIG:
    ERR("Not signed. %d", sigres);
    *sigval = "N";
    *sigmsg = "No signature found.";
    break;
  case ZXSIG_TIMEOUT:
    ERR("Out of validity period. %d", sigres);
    *sigval = "V";
    *sigmsg = "Assertion is not in its validity period.";
    break;
  case ZXSIG_AUDIENCE:
    ERR("Wrong audience. %d", sigres);
    *sigval = "V";
    *sigmsg = "Assertion has wrong audience.";
    break;
  default:
    ERR("Other sig err(%d)", sigres);
    *sigval = "E";
    *sigmsg = "Broken or unvalidatable signature.";
  }
}

/*(i) Validates conditions required by Liberty Alliance SAML2 conformance testing.
 *
 * May eventually validate additional conditions as well (this is the right place
 * to add them). N.B. It is not an error if a condition is missing, or there
 * is no Conditions element at all.
 *
 * cf::      Configuration object, used to determine time slops. Potentially
 *     used for memory allocation via cf->ctx.
 * cgi::     Optional CGI object. If non-NULL, sigval and sigmsg will be set.
 * ses::     Optional session object. If non-NULL, then sigres code will be set.
 * a7n::     Assertion whose conditions are checked.
 * myentid:: Entity ID used for checking audience restriction. Typically from zxid_my_entity_id(cf)
 * ourts::   Timestamp for validating NotOnOrAfter and NotBefore.
 * err::     Result argument: Error letter (as may appear in audit log entry). The returned
 *     string will be a constant and MUST NOT be freed by the caller.
 * return::  0 (ZXSIG_OK) if validation was successful, otherwise a ZXSIG error code. */

/* Called by:  zxid_sp_sso_finalize */
int zxid_validate_cond(struct zxid_conf* cf, struct zxid_cgi* cgi, struct zxid_ses* ses, struct zx_sa_Assertion_s* a7n, struct zx_str* myentid, struct timeval* ourts, char** err)
{
  struct zx_sa_AudienceRestriction_s* audr;
  struct zx_elem_s* aud;
  int secs;

  if (!a7n || !a7n->Conditions) {
    INFO("Assertion does not have Conditions. %p", a7n);
    return ZXSIG_OK;
  }

  if (a7n->Conditions->AudienceRestriction) {
    myentid = zxid_my_entity_id(cf);
    for (audr = a7n->Conditions->AudienceRestriction; audr; audr = (struct zx_sa_AudienceRestriction_s*)audr->gg.g.n)
      for (aud = audr->Audience; aud; aud = (struct zx_elem_s*)aud->g.n)
	if (aud->content->len == myentid->len
	    && !memcmp(aud->content->s, myentid->s, aud->content->len)) {
	  D("Found audience. %d", 0);
	  goto found_audience;
	}
    ERR("SSO warn: AudienceRestriction wrong. %d", 0);
    if (cgi) {
      cgi->sigval = "V";
      cgi->sigmsg = "This SP not included in the Assertion Audience.";
    }
    if (ses)
      ses->sigres = ZXSIG_AUDIENCE;
    if (cf->audience_fatal) {
      *err = "P";
      return ZXSIG_AUDIENCE;
    }
  } else {
    INFO("Assertion does not have AudienceRestriction. %d", 0);
  }
 found_audience:
  
  if (a7n->Conditions->NotOnOrAfter && a7n->Conditions->NotOnOrAfter->len > 18) {
    secs = zx_date_time_to_secs(a7n->Conditions->NotOnOrAfter->s);
    if (secs <= ourts->tv_sec) {
      if (secs + cf->after_slop <= ourts->tv_sec) {
	ERR("NotOnOrAfter rejected with slop of %d. Time to expiry %ld secs", cf->after_slop, secs - ourts->tv_sec);
	if (cgi) {
	  cgi->sigval = "V";
	  cgi->sigmsg = "Assertion has expired.";
	}
	if (ses)
	  ses->sigres = ZXSIG_TIMEOUT;
	if (cf->timeout_fatal) {
	  *err = "P";
	  return ZXSIG_TIMEOUT;
	}
      } else {
	D("NotOnOrAfter accepted with slop of %d. Time to expiry %ld secs", cf->after_slop, secs - ourts->tv_sec);
      }
    } else {
      D("NotOnOrAfter ok. Time to expiry %ld secs", secs - ourts->tv_sec);
    }
  } else {
    INFO("Assertion does not have NotOnOrAfter. %d", 0);
  }
  
  if (a7n->Conditions->NotBefore && a7n->Conditions->NotBefore->len > 18) {
    secs = zx_date_time_to_secs(a7n->Conditions->NotBefore->s);
    if (secs > ourts->tv_sec) {
      if (secs - cf->before_slop > ourts->tv_sec) {
	ERR("NotBefore rejected with slop of %d. Time to validity %ld secs", cf->after_slop, secs - ourts->tv_sec);
	if (cgi) {
	  cgi->sigval = "V";
	  cgi->sigmsg = "Assertion is not valid yet (too soon).";
	}
	if (ses)
	  ses->sigres = ZXSIG_TIMEOUT;
	if (cf->timeout_fatal) {
	  *err = "P";
	  return ZXSIG_TIMEOUT;
	}
      } else {
	D("NotBefore accepted with slop of %d. Time to validity %ld secs", cf->after_slop, secs - ourts->tv_sec);
      }
    } else {
      D("NotBefore ok. Time from validity %ld secs", ourts->tv_sec - secs);
    }
  } else {
    INFO("Assertion does not have NotBefore. %d", 0);
  }
  return ZXSIG_OK;
}

struct zx_str unknown_str = {{0,0,0,0,0}, 1, "??"};  /* Static string used as dummy value. */

/*(i) zxid_sp_sso_finalize() gets called irrespective of binding (POST, Artifact)
 * and validates the SSO a7n, including the authentication statement.
 * Then, it creates session and optionally user entry.
 *
 * cf::  Configuration object, used to determine time slops, potentially memalloc via cf->ctx
 * cgi:: CGI object. sigval and sigmsg may be set.
 * ses:: Session object. Will be modified according to new session created from the SSO assertion.
 * a7n:: Single Sign-On assertion
 * return:: 0 for failure, otherwise some success code such as ZXID_SSO_OK */

/* Called by:  main, zxid_sp_dig_sso_a7n */
int zxid_sp_sso_finalize(struct zxid_conf* cf, struct zxid_cgi* cgi, struct zxid_ses* ses, struct zx_sa_Assertion_s* a7n)
{
  char* err = "S"; /* See: RES in zxid-log.pd, section "ZXID Log Format" */
  struct timeval ourts;
  struct timeval srcts = {0,501000};
  struct zx_str* logpath;
  struct zx_str* issuer = &unknown_str;
  struct zx_str* subj = &unknown_str;
  struct zx_str* ss;
  struct zxsig_ref refs;
  struct zxid_entity* idp_meta;
  /*ses->sigres = ZXSIG_NO_SIG; set earlier, do not overwrite */
  ses->a7n = a7n;
  ses->rs = cgi->rs;
  GETTIMEOFDAY(&ourts, 0);
  
  D_INDENT("ssof: ");

  if (!a7n || !a7n->AuthnStatement) {
    ERR("SSO failed: no assertion supplied, or assertion didn't contain AuthnStatement. %p", a7n);
    goto erro;
  }
  if (!a7n->IssueInstant || !a7n->IssueInstant->len || !a7n->IssueInstant->s || !a7n->IssueInstant->s[0]) {
    ERR("SSO failed: assertion does not have IssueInstant or it is empty. %p", a7n->IssueInstant);
    goto erro;
  }
  srcts.tv_sec = zx_date_time_to_secs(a7n->IssueInstant->s);
  if (!a7n->Issuer || !a7n->Issuer->gg.content) {
    ERR("SSO failed: assertion does not have Issuer. %p", a7n->Issuer);
    goto erro;
  }
  
  /* See zxid_wsp_validate() for similar code. *** consider factoring out commonality */
  
  issuer = a7n->Issuer->gg.content;
  if (!issuer || !issuer->len || !issuer->s[0]) {
    ERR("SSO failed: Issuer of the assertion is empty. %d", issuer->len);
    goto erro;
  }

  if (!a7n->Subject) {
    ERR("SSO failed: assertion does not have Subject. %p", a7n);
    goto erro;
  }

  ses->nameid = zxid_decrypt_nameid(cf, a7n->Subject->NameID, a7n->Subject->EncryptedID);
  if (!ses->nameid || !ses->nameid->gg.content) {
    ERR("SSO failed: assertion does not have Subject->NameID. %p", ses->nameid);
    goto erro;
  }
  
  subj = ses->nameid->gg.content;
  ses->nid = ses->tgt = zx_str_to_c(cf->ctx, subj);
  if (ses->nameid->Format && !memcmp(ses->nameid->Format->s, SAML2_TRANSIENT_NID_FMT, ses->nameid->Format->len)) {
    ses->nidfmt = ses->tgtfmt = 0;
  } else {
    ses->nidfmt = ses->tgtfmt = 1;  /* anything nontransient may be a federation */
  }
  
  if (a7n->AuthnStatement->SessionIndex)
    ses->sesix = zx_str_to_c(cf->ctx, a7n->AuthnStatement->SessionIndex);
  
  D("SSOA7N received. NID(%s) FMT(%d) SESIX(%s)", ses->nid, ses->nidfmt, ses->sesix?ses->sesix:"");
  
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
    ERR("Fail SSO due to failed signature sigres=%d", ses->sigres);
    err = "P";
    goto erro;
  }
  
  if (zxid_validate_cond(cf, cgi, ses, a7n, zxid_my_entity_id(cf), &ourts, &err))
    goto erro;
  
  if (cf->log_rely_a7n) {
    DD("Logging... %d", 0);
    logpath = zxlog_path(cf, issuer, a7n->ID, ZXLOG_RELY_DIR, ZXLOG_A7N_KIND, 1);
    if (logpath) {
      ses->sso_a7n_path = ses->tgt_a7n_path = zx_str_to_c(cf->ctx, logpath);
      ss = zx_EASY_ENC_WO_sa_Assertion(cf->ctx, a7n);
      if (zxlog_dup_check(cf, logpath, "SSO assertion")) {
	if (cf->dup_a7n_fatal) {
	  err = "C";
	  zxlog_blob(cf, cf->log_rely_a7n, logpath, ss, "sp_sso_finalize dup err");
	  goto erro;
	}
      }
      zxlog_blob(cf, cf->log_rely_a7n, logpath, ss, "sp_sso_finalize");
    }
  }
  DD("Creating session... %d", 0);
  zxid_put_ses(cf, ses);
  zxid_snarf_eprs_from_ses(cf, ses);  /* Harvest attributes and bootstrap(s) */
  cgi->msg = "SSO completed and session created.";
  cgi->op = '-';  /* Make sure management screen does not try to redispatch. */
  zxid_put_user(cf, ses->nameid->Format, ses->nameid->NameQualifier, ses->nameid->SPNameQualifier, ses->nameid->gg.content, 0);
  DD("Logging... %d", 0);
  zxlog(cf, &ourts, &srcts, 0, issuer, 0, a7n->ID, subj,
	cgi->sigval, "K", ses->nidfmt?"FEDSSO":"TMPSSO", ses->sesix?ses->sesix:"-", 0);
  D_DEDENT("ssof: ");
  return ZXID_SSO_OK;

erro:
  ERR("SSO fail (%s)", err);
  cgi->msg = "SSO failed. This could be due to signature, timeout, etc., technical failures, or by policy.";
  zxlog(cf, &ourts, &srcts, 0, issuer, 0, a7n?a7n->ID:0, subj,
	cgi->sigval, err, ses->nidfmt?"FEDSSO":"TMPSSO", ses->sesix?ses->sesix:"-", "Error.");
  D_DEDENT("ssof: ");
  return 0;
}

/*() Fake a login and generate a session. Used if SSO failure is configured to result
 * anonymous session.
 *
 * cf::  Configuration object, used to determine time slops, potentially memalloc via cf->ctx
 * cgi:: CGI object. sigval and sigmsg may be set.
 * ses:: Session object. Will be modified according to new session created from the SSO assertion.
 * return:: 0 for failure, otherwise some success code such as ZXID_SSO_OK */

/* Called by:  zxid_sp_dig_sso_a7n */
int zxid_sp_anon_finalize(struct zxid_conf* cf, struct zxid_cgi* cgi, struct zxid_ses* ses)
{
  D_INDENT("anoan_ssof: ");
  cgi->sigval = "N";
  cgi->sigmsg = "Anonymous login. No signature.";
  ses->sigres = ZXSIG_NO_SIG;
  ses->a7n = 0;
  ses->rs = cgi->rs;
  ses->nameid = 0;
  ses->nid = "-";
  ses->nidfmt = 0;
  ses->sesix = 0;
  
  D("SSO FAIL: ANON_OK. Creating session... %p", ses);
  
  zxid_put_ses(cf, ses);
  zxid_snarf_eprs_from_ses(cf, ses);  /* Harvest attributes and bootstrap(s) */
  cgi->msg = "SSO Failure treated as anonymous login and session created.";
  cgi->op = '-';  /* Make sure management screen does not try to redispatch. */
  /*zxid_put_user(cf, ses->nameid->Format, ses->nameid->NameQualifier, ses->nameid->SPNameQualifier, ses->nameid->gg.content, 0);*/
  zxlog(cf, 0, 0, 0, 0, 0, 0, 0, cgi->sigval, "K", "TMPSSO", "-", 0);
  D_DEDENT("anon_ssof: ");
  return ZXID_SSO_OK;
}

/* EOF  --  zxidsso.c */