/* zxidecp.c  -  Handwritten functions for implementing Enhanced Client Proxy and SP
 * Copyright (c) 2010 Sampo Kellomaki (sampo@iki.fi), All Rights Reserved.
 * Copyright (c) 2006-2008 Symlabs (symlabs@symlabs.com), All Rights Reserved.
 * Author: Sampo Kellomaki (sampo@iki.fi)
 * This is confidential unpublished proprietary source code of the author.
 * NO WARRANTY, not even implied warranties. Contains trade secrets.
 * Distribution prohibited unless authorized in writing.
 * Licensed under Apache License 2.0, see file COPYING.
 * $Id: zxidecp.c,v 1.10 2008-10-08 03:56:55 sampo Exp $
 *
 * 12.8.2006, created --Sampo
 * 16.1.2007, split from zxidlib.c --Sampo
 * 7.10.2008, added documentation --Sampo
 * 14.3.2010, reformed eid presentation --Sampo
 *
 * See: zxid_sp_soap_dispatch() in zxidslo.c for handling PAOS response
 *
 * If you do not know what PAOS, ECP or LECP means, you should read SAML2 Profiles specification.
 */

#include <stdio.h>
#include <stdlib.h>

#include "errmac.h"
#include "zxid.h"
#include "zxidconf.h"
#include "saml2.h"
#include "c/zx-paos-data.h"

extern char **environ;

/*() Generate SOAP headers for use with PAOS carried SAML2 ECP profile AuthnRequest.
 *
 * If you do not know what PAOS, ECP or LECP means, you should read [SAML2bind] specification. */

/* Called by:  zxid_lecp_check */
struct zx_paos_Request_s* zxid_mk_paos_Request_hdr(zxid_conf* cf)
{
  struct zx_paos_Request_s* hdr= zx_NEW_paos_Request(cf->ctx);
  /*hdr->messageID = zx_ref_str(cf->ctx, "1"); OPTIONAL */
  hdr->mustUnderstand = zx_ref_str(cf->ctx, ZXID_TRUE);
  hdr->actor = zx_ref_str(cf->ctx, SOAP_ACTOR_NEXT);
  hdr->service = zx_ref_str(cf->ctx, SAML2_SSO_ECP);
  hdr->responseConsumerURL = zx_strf(cf->ctx, "%s?o=P", cf->url);
  return hdr;
}

/*() Build IDPList of IDPEntry(s) from the IdPs know to us at the moment (our CoT).
 * Can be used for ECP and IdP proxying.
 *
 * cf:: ZXID configuration object, used to locate the CoT directory (PATH
 *     configuration option) and for memory allocation
 * binding:: The SSO protocol binding the qualifying IdPs MUST support, or 0 if anything goes
 * return:: IdP list data structure or 0 on failure */

/* Called by:  zxid_mk_ecp_Request_hdr */
struct zx_sp_IDPList_s* zxid_mk_idp_list(zxid_conf* cf, char* binding)
{
  zxid_entity* idp;
  struct zx_md_SingleSignOnService_s* sso_svc;
  struct zx_sp_IDPList_s* idp_list;
  struct zx_sp_IDPEntry_s* idp_entry;

  idp = zxid_load_cot_cache(cf);
  if (!idp)
    return 0;
  
  idp_list = zx_NEW_sp_IDPList(cf->ctx);
  for (; idp; idp = idp->n) {
    D("IDPList consider idp(%s)", idp->eid);
    if (!idp->ed->IDPSSODescriptor)
      continue;
    for (sso_svc = idp->ed->IDPSSODescriptor->SingleSignOnService;
	 sso_svc;
	 sso_svc = (struct zx_md_SingleSignOnService_s*)sso_svc->gg.g.n)
      if (sso_svc->Binding && !memcmp(binding, sso_svc->Binding->s, sso_svc->Binding->len))
	break;
    if (!sso_svc) {
      D("Entity(%s) does not have any IdP SSO Service with binding(%s)", idp->eid, binding);
      continue;  /* Not eligible IdP, next one please. */
    }
    
    idp_entry = zx_NEW_sp_IDPEntry(cf->ctx);
    idp_entry->ProviderID = zx_ref_str(cf->ctx, idp->eid);
    idp_entry->Name = zx_ref_str(cf->ctx, idp->dpy_name);
    idp_entry->Loc = sso_svc->Location;
    idp_entry->gg.g.n = &idp_list->IDPEntry->gg.g; /* zx_sp_IDPList_PUSH_IDPEntry(idp_list, idp_entry); */
    idp_list->IDPEntry = idp_entry;
  }
  return idp_list;
}

/*() Generate headers for use with Liberty ID-FF 1.2 LECP carried AuthnRequest.
 *
 * If you do not know what PAOS, ECP or LECP means, you should read [SAML2bind] specification. */

/* Called by:  zxid_lecp_check */
struct zx_ecp_Request_s* zxid_mk_ecp_Request_hdr(zxid_conf* cf)
{
  struct zx_ecp_Request_s* hdr= zx_NEW_ecp_Request(cf->ctx);
  hdr->mustUnderstand = zx_ref_str(cf->ctx, ZXID_TRUE);
  hdr->actor = zx_ref_str(cf->ctx, SOAP_ACTOR_NEXT);
  /*hdr->IsPassive = zx_ref_str(cf->ctx, ZXID_TRUE);  OPTIONAL, default=? */
  hdr->ProviderName = zxid_my_entity_id(cf);  /* *** Friendly name? */
  hdr->Issuer = zxid_my_issuer(cf);
  hdr->IDPList = zxid_mk_idp_list(cf, SAML2_SOAP);
  return hdr;
}

/* ============== LECP or ECP ============== */

/*() Check for ECP indications in HTTP request headers and initiate
 * PAOS based Single Sign On, i.e AuthnRequest. This is part of the
 * SAML2 Enhanced Client Proxy profile.
 *
 * Limitation:: Current (2008) code only works in CGI environment due to
 *     reliance on environment variables. (*** fixme)
 *
 * If you do not know what PAOS, ECP or LECP means, you should read [SAML2bind] specification. */

/* Called by:  main x4, zxid_simple_no_ses_cf x2 */
struct zx_str* zxid_lecp_check(zxid_conf* cf, zxid_cgi* cgi)
{
  struct zx_e_Envelope_s* se;
  struct zx_str* env;
  struct zx_str* req;
  char* le;
#if 0
  char** pp;
  for (pp = environ; *pp; ++pp)   /* Debug envirnment problems, e.g. mini_httpd does not pass HTTP_PAOS, unless patched. */
    D("ENV(%s)", *pp);
#endif

  le = getenv("HTTP_PAOS");
  if (!le) {
    le = getenv("HTTP_LIBERTY_ENABLED");
    if (!le) {
      D("Neither ECP nor LECP request %d", 0);
      return 0;  /* No ECP/LECP detected, return to normal processing. */
    }
    D("LECP detected HTTP_LIBERTY_ENABLED(%s) (*** NOT IMPLEMENTED)", le);
    /* *** start ID-FF 1.2 LECP processing */
    return 0; /* ars = ...; */
  }
  D("ECP detected HTTP_PAOS(%s)", le);
  if (!strstr(le, SAML2_SSO_ECP))
    return 0;
    
  /* SAML 2.0 ECP: Create PAOS request to be sent in HTTP response. */
    
  se = zx_NEW_e_Envelope(cf->ctx);
  se->Body = zx_NEW_e_Body(cf->ctx);
  se->Body->AuthnRequest = zxid_mk_authn_req(cf, cgi);
  se->Header = zx_NEW_e_Header(cf->ctx);
  se->Header->Request = zxid_mk_paos_Request_hdr(cf);
  se->Header->ecp_Request = zxid_mk_ecp_Request_hdr(cf);
  env = zx_EASY_ENC_SO_e_Envelope(cf->ctx, se);
  req = zx_strf(cf->ctx,
		"Cache-Control: no-cache, no-store, must-revalidate, private" CRLF
		"Pragma: no-cache" CRLF
		"Content-Type: " PAOS_CONTENT CRLF  /* content type only specified for ECP */
		"Content-Length: %d" CRLF2
		"%.*s", env->len, env->len, env->s);
  zx_str_free(cf->ctx, env);
  return req;
}

/* EOF  --  zxidecp.c */
