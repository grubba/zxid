/* zxidpep.c  -  Handwritten functions for XACML Policy Enforcement Point
 * Copyright (c) 2009 Symlabs (symlabs@symlabs.com), All Rights Reserved.
 * Author: Sampo Kellomaki (sampo@iki.fi)
 * This is confidential unpublished proprietary source code of the author.
 * NO WARRANTY, not even implied warranties. Contains trade secrets.
 * Distribution prohibited unless authorized in writing.
 * Licensed under Apache License 2.0, see file COPYING.
 * $Id: zxidpep.c,v 1.10 2010-01-08 02:10:09 sampo Exp $
 *
 * 24.8.2009, created --Sampo
 * 10.10.2009, added zxid_az() family --Sampo
 */

#include "errmac.h"
#include "zxid.h"
#include "zxidconf.h"
#include "saml2.h"
#include "c/zx-const.h"
#include "c/zx-ns.h"
#include "c/zx-data.h"

#if 0
#define XS_STRING "xs:string"
#else
#define XS_STRING "http://www.w3.org/2001/XMLSchema#string"
#endif

/* ============== Policy Enforcement Point, Authorization Decision Query ============== */

/*(i) Call Policy Decision Point (PDP) to obtain an authorization decision
 * about a contemplated action on a resource. The attributes from the session
 * pool, as filtered by PEPMAP are fed to the PDP as inputs
 * for the decision. The call is using XACML SAML profile over SOAP.
 *
 * cf:: the configuration will need to have ~PEPMAP~ and ~PDP_URL~ options
 *     set according to your situation.
 * cgi:: if non-null, will receive error and status codes
 * ses:: all attributes are obtained from the session. You may wish
 *     to add additional attributes that are not known by SSO.
 * returns:: 0 on deny (for any reason, e.g. indeterminate), or 1 if permit
 *
 * For simpler API, see zxid_az() family of functions.
 */

/* Called by:  zxid_az_cf_ses, zxid_simple_ab_pep, zxid_simple_ses_active_cf */
int zxid_pep_az_soap(struct zxid_conf* cf, struct zxid_cgi* cgi, struct zxid_ses* ses, const char* pdp_url)
{
  struct zxid_map* map;
  struct zxid_attr* at;
  struct zxid_attr* av;
  struct zx_xac_Attribute_s* xac_at;
  struct zx_xac_Attribute_s* subj = 0;
  struct zx_xac_Attribute_s* rsrc = 0;
  struct zx_xac_Attribute_s* act = 0;
  struct zx_xac_Attribute_s* env = 0;
  char* name;

  struct zxsig_ref refs;
  struct zx_root_s* r;
  struct zx_e_Header_s* hdr;
  struct zx_e_Body_s* body;
  struct zx_str* loc;
  struct zx_sp_Response_s* resp;
  struct zx_sa_Statement_s* stmt;
  struct zx_xasa_XACMLAuthzDecisionStatement_s* az_stmt;
  struct zx_xasacd1_XACMLAuthzDecisionStatement_s* az_stmt_cd1;
  struct zx_elem_s* decision;

  if (cf->log_level>0)
    zxlog(cf, 0, 0, 0, 0, 0, 0, ses&&ses->nameid?ses->nameid->gg.content:0, "N", "W", "AZSOAP", ses?ses->sid:0, " ");
  
  if (!pdp_url) {
    ERR("No PDP_URL or PDP_CALL_URL set. Deny. %d", 0);
    return 0;
  }

  for (at = ses?ses->at:0; at; at = at->n) {
    map = zxid_find_map(cf->pepmap, at->name);
    if (map) {
      if (map->rule == ZXID_MAP_RULE_DEL) {
	D("attribute(%s) filtered out by del rule in PEPMAP", at->name);
	continue;
      }
      at->map_val = zxid_map_val(cf, map, zx_ref_str(cf->ctx, at->val));
      if (map->dst && map->dst[0] && map->src && map->src[0] != '*') {
	D("renaming(%s) to(%s) orig_val(%s) map_val(%.*s)", at->name, map->dst, at->val, at->map_val->len, at->map_val->s);
	name = map->dst;
      } else {
	name = at->name;
      }
      xac_at = zxid_mk_xacml_simple_at(cf, 0,
				       zx_dup_str(cf->ctx, name),
				       zx_dup_str(cf->ctx, XS_STRING),
				       at->issuer, at->map_val);
      if (map->ns && *map->ns) {
	if (!strcmp(map->ns, "subj")) {
	  ZX_NEXT(xac_at) = (void*)subj;
	  subj = xac_at;
	} else if (!strcmp(map->ns, "rsrc")) {
	  ZX_NEXT(xac_at) = (void*)rsrc;
	  rsrc = xac_at;
	} else if (!strcmp(map->ns, "act")) {
	  act = xac_at;  /* there can be only one */
	} else if (!strcmp(map->ns, "env")) {
	  ZX_NEXT(xac_at) = (void*)env;
	  env = xac_at;
	} else {
	  ERR("PEPMAP unknown ns(%s). Valid values are subj, rsrc, act, and env.", map->ns);
	}
      } else {
	ERR("PEPMAP entry lacks ns %p", map->ns);
      }
      
      for (av = at->nv; av; av = av->n) {
	av->map_val = zxid_map_val(cf, map, zx_ref_str(cf->ctx, av->val));
	xac_at = zxid_mk_xacml_simple_at(cf, 0,
					 zx_dup_str(cf->ctx, name),
					 zx_dup_str(cf->ctx, XS_STRING),
					 at->issuer, at->map_val);
	if (map->ns && *map->ns) {
	  if (!strcmp(map->ns, "subj")) {
	    ZX_NEXT(xac_at) = (void*)subj;
	    subj = xac_at;
	  } else if (!strcmp(map->ns, "rsrc")) {
	    ZX_NEXT(xac_at) = (void*)rsrc;
	    rsrc = xac_at;
	  } else if (!strcmp(map->ns, "act")) {
	    ERR("PEPMAP: Only one XACML action attribute allowed %d", 0);
	  } else if (!strcmp(map->ns, "env")) {
	    ZX_NEXT(xac_at) = (void*)env;
	    env = xac_at;
	  } else {
	    ERR("PEPMAP unknown ns(%s). Valid values are subj, rsrc, act, and env.", map->ns);
	  }
	} else {
	  ERR("PEPMAP entry lacks ns %p", map->ns);
	}
      }
    } else {
      D("ATTR(%s)=VAL(%s): Ignored due to no matching PEPMAP", at->name, at->val);
    }
  }

  if (!act) {
    act = zxid_mk_xacml_simple_at(cf, 0,
	     zx_dup_str(cf->ctx, "urn:oasis:names:tc:xacml:1.0:action:action-id"),
	     zx_dup_str(cf->ctx, XS_STRING),
	     0,
	     zx_dup_str(cf->ctx, "urn:oasis:names:tc:xacml:1.0:action:implied-action"));
  }

#if 0
  hdr = zx_NEW_e_Header(cf->ctx);
  hdr->Action = zx_NEW_a_Action(cf->ctx);
  //hdr->Action->gg.content = zx_dup_str(cf->ctx, "urn:oasis:names:tc:xacml:2.0:profile:saml2.0:v2:schema:protocol:cd-01");
  hdr->Action->gg.content = zx_dup_str(cf->ctx, "urn:oasis:xacml:2.0:saml:protocol:schema:os");

  //hdr->Action->gg.content = zx_dup_str(cf->ctx, "SAML2XACMLAuthzRequest");
  //hdr->Action->gg.content = zx_dup_str(cf->ctx, "http://ws.apache.org/axis2/TestPolicyPortType/authRequestRequest");
  hdr->Action->actor = zx_ref_str(cf->ctx, SOAP_ACTOR_NEXT);
  hdr->Action->mustUnderstand = zx_ref_str(cf->ctx, ZXID_TRUE);
#else
  hdr = 0;
#endif

  body = zx_NEW_e_Body(cf->ctx);
  if (!strcmp(cf->xasp_vers, "2.0-cd1")) {
    body->xaspcd1_XACMLAuthzDecisionQuery = zxid_mk_az_cd1(cf, subj, rsrc, act, env);
    if (cf->sso_soap_sign) {
      refs.id = body->xaspcd1_XACMLAuthzDecisionQuery->ID;
      refs.canon = zx_EASY_ENC_SO_xaspcd1_XACMLAuthzDecisionQuery(cf->ctx, body->xaspcd1_XACMLAuthzDecisionQuery);

      if (!cf->sign_cert) // Lazy load cert and private key
	cf->sign_cert = zxid_read_cert(cf, "sign-nopw-cert.pem");
      if (!cf->sign_pkey)
	cf->sign_pkey = zxid_read_private_key(cf, "sign-nopw-cert.pem");
      body->xaspcd1_XACMLAuthzDecisionQuery->Signature = zxsig_sign(cf->ctx, 1, &refs, cf->sign_cert, cf->sign_pkey);
      zx_str_free(cf->ctx, refs.canon);
    }
  } else {
    body->XACMLAuthzDecisionQuery = zxid_mk_az(cf, subj, rsrc, act, env);
    if (cf->sso_soap_sign) {
      refs.id = body->XACMLAuthzDecisionQuery->ID;
      refs.canon = zx_EASY_ENC_SO_xasp_XACMLAuthzDecisionQuery(cf->ctx, body->XACMLAuthzDecisionQuery);
      if (!cf->sign_cert) // Lazy load cert and private key
	cf->sign_cert = zxid_read_cert(cf, "sign-nopw-cert.pem");
      if (!cf->sign_pkey)
	cf->sign_pkey = zxid_read_private_key(cf, "sign-nopw-cert.pem");
      body->XACMLAuthzDecisionQuery->Signature = zxsig_sign(cf->ctx, 1, &refs, cf->sign_cert, cf->sign_pkey);
      zx_str_free(cf->ctx, refs.canon);
    }
  }

#if 0
  //loc = zx_ref_str(cf->ctx, "https://idpdemo.tas3.eu:8443/zxididp?o=S");
  // http://192.168.136.42:1104/axis2/services/TestPolicy.PERMISAuthzServerHttpSoap12Endpoint/
  // http://192.168.1.27:1104/axis2/services/TestPolicy?wsdl
  // http://192.168.1.66:1104/axis2/services/TestPolicy.PERMISAuthzServerHttpEndpoint/
  loc = zx_ref_str(cf->ctx, "http://192.168.1.27:1104/axis2/services/TestPolicy.PERMISAuthzServerHttpEndpoint/");
  //loc = zx_ref_str(cf->ctx, "");
  //loc = zx_ref_str(cf->ctx, "http://192.168.1.66:1104/axis2/services/TestPolicy.PERMISAuthzServerHttpEndpoint/");
  //loc = zx_ref_str(cf->ctx, "http://192.168.1.27:1104/axis2/services/TestPolicy.PERMISAuthzServerHttpSoap12Endpoint/");
#else
  loc = zx_ref_str(cf->ctx, pdp_url);
#endif
  r = zxid_soap_call_hdr_body(cf, loc, hdr, body);
  //r = zxid_idp_soap(cf, cgi, ses, idp_meta, ZXID_MNI_SVC, body);
  if (!r || !r->Envelope || !r->Envelope->Body || !r->Envelope->Body->Response) {
    ERR("Missing Response or other essential element %p %p %p %p", r, r?r->Envelope:0, r && r->Envelope?r->Envelope->Body:0, r && r->Envelope && r->Envelope->Body ? r->Envelope->Body->Response:0);
    return 0;
  }
  resp = r->Envelope->Body->Response;
  if (!zxid_saml_ok(cf, cgi, resp->Status, "AzResp")) {
    ERR("Response->Status no OK (%p)", resp->Status);
    return 0;
  }
  if (!resp->Assertion) {
    ERR("No Assertion in the Response (%p)", resp);
    return 0;
  }
  az_stmt = resp->Assertion->XACMLAuthzDecisionStatement;
  if (az_stmt && az_stmt->Response && az_stmt->Response->Result) {
    decision = az_stmt->Response->Result->Decision;
    if (decision && decision->content->len == sizeof("Permit")-1
	&& !memcmp(decision->content->s, "Permit", sizeof("Permit")-1)) {
      D("Permit %d", 1);
      return 1;
    }
  }
  az_stmt_cd1 = resp->Assertion->xasacd1_XACMLAuthzDecisionStatement;
  if (az_stmt_cd1 && az_stmt_cd1->Response && az_stmt_cd1->Response->Result) {
    decision = az_stmt_cd1->Response->Result->Decision;
    if (decision && decision->content->len == sizeof("Permit")-1
	&& !memcmp(decision->content->s, "Permit", sizeof("Permit")-1)) {
      D("Permit cd1 %d", 1);
      return 1;
    }
  }
  stmt = resp->Assertion->Statement;
  if (stmt && stmt->Response && stmt->Response->Result) {  /* Response here is xac:Response */
    decision = stmt->Response->Result->Decision;
    if (decision && decision->content->len == sizeof("Permit")-1
	&& !memcmp(decision->content->s, "Permit", sizeof("Permit")-1)) {
      D("Permit stmt %d", 1);
      return 1;
    }
  }
  /*if (resp->Assertion->AuthzDecisionStatement) {  }*/
  D("Deny %d",0);
  return 0;
}

/*int zxid_az_cf_cgi_ses(struct zxid_conf* cf,  struct zxid_cgi* cgi, struct zxid_ses* ses);*/

/*() See zxid_call_cf() for documentation. Only difference is that the session is
 * accepted as data structure instead of a session id. */

/* Called by:  zxid_az_cf */
int zxid_az_cf_ses(struct zxid_conf* cf, const char* qs, struct zxid_ses* ses)
{
  int ret;
  struct zxid_cgi cgi;
  D_INDENT("az: ");
  memset(&cgi, 0 , sizeof(struct zxid_cgi));
  zxid_parse_cgi(&cgi, "");
  DD("qs(%s) ses=%p", STRNULLCHKD(qs), ses);
  if (qs && ses)
    zxid_add_qs_to_ses(cf, ses, zx_dup_cstr(cf->ctx, qs), 1);
  ret =  zxid_pep_az_soap(cf, &cgi, ses, cf->pdp_call_url?cf->pdp_call_url:cf->pdp_url);
  D_DEDENT("az: ");
  return ret;
}

/*(i) Call Policy Decision Point (PDP) to obtain an authorization decision
 * about a contemplated action on a resource. The attributes from the session
 * pool, as filtered by ~PEPMAP~ are fed to the PDP as inputs
 * for the decision.
 *
 * cf:: the configuration will need to have ~PEPMAP~ and ~PDP_URL~ options
 *     set according to your situation.
 * qs:: if non-null, will resceive error and status codes
 * ses:: all attributes are obtained from the session. You may wish
 *     to add additional attributes that are not known by SSO.
 * returns:: 0 on deny (for any reason, e.g. indeterminate), or 1 if permit
 *
 * For simpler API, see zxid_az() family of functions.
 */

/* Called by:  zxid_az */
int zxid_az_cf(struct zxid_conf* cf, const char* qs, const char* sid)
{
  struct zxid_ses ses;
  memset(&ses, 0 , sizeof(struct zxid_ses));
  if (sid && sid[0])
    zxid_get_ses(cf, &ses, sid);
  return zxid_az_cf_ses(cf, qs, &ses);
}

/*() See zxid_az_cf() for description. Only difference is that the configuration
 * is accepted as a string instead of an object. */

/* Called by: */
int zxid_az(const char* conf, const char* qs, const char* sid)
{
  struct zx_ctx ctx;
  struct zxid_conf cf;
  zx_reset_ctx(&ctx);
  memset(&cf, 0, sizeof(struct zxid_conf));
  cf.ctx = &ctx;
  zxid_conf_to_cf_len(&cf, -1, conf);
  return zxid_az_cf(&cf, qs, sid);
}

/* EOF  --  zxidpep.c */
