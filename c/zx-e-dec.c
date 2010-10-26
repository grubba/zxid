/* c/zx-e-dec.c - WARNING: This file was automatically generated. DO NOT EDIT!
 * $Id$ */
/* Code generation design Copyright (c) 2006 Sampo Kellomaki (sampo@iki.fi),
 * All Rights Reserved. NO WARRANTY. See file COPYING for terms and conditions
 * of use. Some aspects of code generation were driven by schema
 * descriptions that were used as input and may be subject to their own copyright.
 * Code generation uses a template, whose copyright statement follows. */

/** dec-templ.c  -  XML decoder template, used in code generation
 ** Copyright (c) 2010 Sampo Kellomaki (sampo@iki.fi), All Rights Reserved.
 ** Copyright (c) 2006-2007 Symlabs (symlabs@symlabs.com), All Rights Reserved.
 ** Author: Sampo Kellomaki (sampo@iki.fi)
 ** This is confidential unpublished proprietary source code of the author.
 ** NO WARRANTY, not even implied warranties. Contains trade secrets.
 ** Distribution prohibited unless authorized in writing.
 ** Licensed under Apache License 2.0, see file COPYING.
 ** Id: dec-templ.c,v 1.30 2008-10-04 23:42:14 sampo Exp $
 **
 ** 28.5.2006, created, Sampo Kellomaki (sampo@iki.fi)
 ** 8.8.2006,  reworked namespace handling --Sampo
 ** 12.8.2006, added special scanning of xmlns to avoid backtracking elem recognition --Sampo
 ** 23.9.2006, added collection of WO information --Sampo
 ** 21.6.2007, improved handling of undeclared namespace prefixes --Sampo
 **
 ** N.B: This template is meant to be processed by pd/xsd2sg.pl. Beware
 ** of special markers that xsd2sg.pl expects to find and understand.
 **/

#include "errmac.h"
#include "zx.h"
#include "c/zx-const.h"
#include "c/zx-data.h"
#include "c/zx-e-data.h"

#define TPF zx_

#ifndef ZX_ATTR_DEC_EXT
#define ZX_ATTR_DEC_EXT(ss)  /* Extension point called just after decoding known attribute */
#endif

#ifndef ZX_XMLNS_DEC_EXT
#define ZX_XMLNS_DEC_EXT(ss) /* Extension point called just after decoding xmlns attribute */
#endif

#ifndef ZX_UNKNOWN_ATTR_DEC_EXT
#define ZX_UNKNOWN_ATTR_DEC_EXT(ss) /* Extension point called just after decoding unknown attr */
#endif

#ifndef ZX_START_DEC_EXT
#define ZX_START_DEC_EXT(x) /* Extension point called just after decoding element name and allocating struct, but before decoding any of the attributes. */
#endif

#ifndef ZX_END_DEC_EXT
#define ZX_END_DEC_EXT(x) /* Extension point called just after decoding the entire element. */
#endif

#ifndef ZX_START_BODY_DEC_EXT
#define ZX_START_BODY_DEC_EXT(x) /* Extension point called just after decoding element tag, including attributes, but before decoding the body of the element. */
#endif

#ifndef ZX_PI_DEC_EXT
#define ZX_PI_DEC_EXT(pi) /* Extension point called just after decoding processing instruction */
#endif

#ifndef ZX_COMMENT_DEC_EXT
#define ZX_COMMENT_DEC_EXT(comment) /* Extension point called just after decoding comment */
#endif

#ifndef ZX_CONTENT_DEC
#define ZX_CONTENT_DEC(ss) /* Extension point called just after decoding string content */
#endif

#ifndef ZX_UNKNOWN_ELEM_DEC_EXT
#define ZX_UNKNOWN_ELEM_DEC_EXT(elem) /* Extension point called just after decoding unknown element */
#endif



/* FUNC(zx_DEC_e_Body) */

#define EL_NAME   e_Body
#define EL_STRUCT zx_e_Body_s
#define EL_NS     e
#define EL_TAG    Body

/* Called by: */
struct zx_e_Body_s* zx_DEC_e_Body(struct zx_ctx* c, struct zx_ns_s* ns )
{
  int tok;
  struct zx_elem_s* el;
  struct zx_str* ss;
  struct zx_ns_s* pop_seen;
  const char* name;
  const char* data;
  struct zx_e_Body_s* x = ZX_ZALLOC(c, struct zx_e_Body_s);
  x->gg.g.tok = zx_e_Body_ELEM;
  x->gg.g.ns = ns;
  ZX_START_DEC_EXT(x);

#if 1 /* NORMALMODE */
  ZX_DEC_TAG_NOT_YET_CLOSED(x->gg.g);

  /* The tag name has already been detected. Process attributes until '>' */
  
  for (; c->p; ++c->p) {
    ZX_SKIP_WS(c,x);
    if (ONE_OF_2(*c->p, '>', '/'))
      break;
    if (!(data = zx_dec_attr_val(c, &name, (const char*)__FUNCTION__)))
      return x;
    tok = zx_attr_lookup(c, name, data-2, &ns);
    switch (tok) {
    case zx_id_ATTR:
      ss = ZX_ZALLOC(c, struct zx_str);
      ss->g.n = &x->id->g;
      x->id = ss;
      ZX_ATTR_DEC_EXT(ss);
      break;

    case ZX_TOK_XMLNS:
      ZX_XMLNS_DEC_EXT(name);
      DD("xmlns detected(%.*s)", data-2-name, name);
      ns = zx_new_ns(c, data-2-name, name, c->p - data, data);
      ns->n = x->gg.xmlns;
      x->gg.xmlns = ns;
      goto next_attr;
    default:
      ss = zx_dec_unknown_attr(c, &x->gg, name, data, tok, x->gg.g.tok);
    }
    ss->g.ns = ns;    /* Fill in the rest of the ss fields (its already linked to right list). */
    ss->g.tok = tok;
    ss->g.err |= ZXERR_ATTR_FLAG;
    ss->len = c->p - data;
    ss->s = (char*)data;
next_attr:
    continue;
  }
  if (c->p) {
    ++c->p;
    if (c->p[-1] == '/' && c->p[0] == '>') {  /* Tag without content */
      ++c->p;
      ZX_DEC_TAG_NOW_CLOSED(x->gg.g);
      goto out;
    }
  }
#endif

  /* Process contents until '</' */
  
  ZX_START_BODY_DEC_EXT(x);
  
  while (c->p) {
  next_elem:
    /*ZX_SKIP_WS(c,x);    DO NOT SQUASH WS! EXC-CANON NEEDS IT. */
    if (*c->p == '<') {
    potential_tag:
      ++c->p;
      switch (*c->p) {
      case '?':  /* processing instruction <?xml ... ?> */
      case '!':  /* comment <!-- ... --> */
	if (zx_scan_pi_or_comment(c))
	  break;
	goto next_elem;
      case '/':  /* close tag */
	++c->p;
	name = c->p;
	ZX_LOOK_FOR(c,'>');
#if defined(DEC_WRONG_ELEM)
	if (x->gg.g.ns->prefix_len
	    ?(c->p - name - x->gg.g.ns->prefix_len - 1 != namlen || memcmp(name+x->gg.g.ns->prefix_len+1, nam, namlen))
	    :(c->p-name != namlen || memcmp(name, nam, namlen)))
#else
	tok = zx_elem_lookup(c, name, c->p, &ns);
	if (tok != x->gg.g.tok)
#endif
	{
	  zx_xml_parse_err_mismatching_close_tag(c, (const char*)__FUNCTION__, name, tok);
	  ZX_DEC_TAG_MISMATCH_CLOSE(x->gg.g);
	  return x;
	}
	/* Legitimate close tag. Normal exit from this function. */
	++c->p;
	ZX_DEC_TAG_NOW_CLOSED(x->gg.g);
	goto out;
      default:
	if (A_Z_a_z_(*c->p)) {
	  if (!(name = zx_scan_elem_start(c, (const char*)__FUNCTION__)))
	    return x;
	  pop_seen = zx_scan_xmlns(c);  /* Prescan namespaces so that token can be correctly recognized. */
	  tok = zx_elem_lookup(c, name, c->p, &ns);
	  switch (tok) {
          case zx_sp_ArtifactResolve_ELEM:
            el = (struct zx_elem_s*)zx_DEC_sp_ArtifactResolve(c, ns);
            el->g.n = &x->ArtifactResolve->gg.g;
            x->ArtifactResolve = (struct zx_sp_ArtifactResolve_s*)el;
            break;
          case zx_sp_ArtifactResponse_ELEM:
            el = (struct zx_elem_s*)zx_DEC_sp_ArtifactResponse(c, ns);
            el->g.n = &x->ArtifactResponse->gg.g;
            x->ArtifactResponse = (struct zx_sp_ArtifactResponse_s*)el;
            break;
          case zx_sp_ManageNameIDRequest_ELEM:
            el = (struct zx_elem_s*)zx_DEC_sp_ManageNameIDRequest(c, ns);
            el->g.n = &x->ManageNameIDRequest->gg.g;
            x->ManageNameIDRequest = (struct zx_sp_ManageNameIDRequest_s*)el;
            break;
          case zx_sp_ManageNameIDResponse_ELEM:
            el = (struct zx_elem_s*)zx_DEC_sp_ManageNameIDResponse(c, ns);
            el->g.n = &x->ManageNameIDResponse->gg.g;
            x->ManageNameIDResponse = (struct zx_sp_ManageNameIDResponse_s*)el;
            break;
          case zx_sp_LogoutRequest_ELEM:
            el = (struct zx_elem_s*)zx_DEC_sp_LogoutRequest(c, ns);
            el->g.n = &x->LogoutRequest->gg.g;
            x->LogoutRequest = (struct zx_sp_LogoutRequest_s*)el;
            break;
          case zx_sp_LogoutResponse_ELEM:
            el = (struct zx_elem_s*)zx_DEC_sp_LogoutResponse(c, ns);
            el->g.n = &x->LogoutResponse->gg.g;
            x->LogoutResponse = (struct zx_sp_LogoutResponse_s*)el;
            break;
          case zx_sp_NameIDMappingRequest_ELEM:
            el = (struct zx_elem_s*)zx_DEC_sp_NameIDMappingRequest(c, ns);
            el->g.n = &x->NameIDMappingRequest->gg.g;
            x->NameIDMappingRequest = (struct zx_sp_NameIDMappingRequest_s*)el;
            break;
          case zx_sp_NameIDMappingResponse_ELEM:
            el = (struct zx_elem_s*)zx_DEC_sp_NameIDMappingResponse(c, ns);
            el->g.n = &x->NameIDMappingResponse->gg.g;
            x->NameIDMappingResponse = (struct zx_sp_NameIDMappingResponse_s*)el;
            break;
          case zx_sp_AttributeQuery_ELEM:
            el = (struct zx_elem_s*)zx_DEC_sp_AttributeQuery(c, ns);
            el->g.n = &x->AttributeQuery->gg.g;
            x->AttributeQuery = (struct zx_sp_AttributeQuery_s*)el;
            break;
          case zx_sp_AuthnQuery_ELEM:
            el = (struct zx_elem_s*)zx_DEC_sp_AuthnQuery(c, ns);
            el->g.n = &x->AuthnQuery->gg.g;
            x->AuthnQuery = (struct zx_sp_AuthnQuery_s*)el;
            break;
          case zx_sp_AuthzDecisionQuery_ELEM:
            el = (struct zx_elem_s*)zx_DEC_sp_AuthzDecisionQuery(c, ns);
            el->g.n = &x->AuthzDecisionQuery->gg.g;
            x->AuthzDecisionQuery = (struct zx_sp_AuthzDecisionQuery_s*)el;
            break;
          case zx_sp_AssertionIDRequest_ELEM:
            el = (struct zx_elem_s*)zx_DEC_sp_AssertionIDRequest(c, ns);
            el->g.n = &x->AssertionIDRequest->gg.g;
            x->AssertionIDRequest = (struct zx_sp_AssertionIDRequest_s*)el;
            break;
          case zx_sp_Response_ELEM:
            el = (struct zx_elem_s*)zx_DEC_sp_Response(c, ns);
            el->g.n = &x->Response->gg.g;
            x->Response = (struct zx_sp_Response_s*)el;
            break;
          case zx_sp_AuthnRequest_ELEM:
            el = (struct zx_elem_s*)zx_DEC_sp_AuthnRequest(c, ns);
            el->g.n = &x->AuthnRequest->gg.g;
            x->AuthnRequest = (struct zx_sp_AuthnRequest_s*)el;
            break;
          case zx_sp11_Request_ELEM:
            el = (struct zx_elem_s*)zx_DEC_sp11_Request(c, ns);
            el->g.n = &x->Request->gg.g;
            x->Request = (struct zx_sp11_Request_s*)el;
            break;
          case zx_sp11_Response_ELEM:
            el = (struct zx_elem_s*)zx_DEC_sp11_Response(c, ns);
            el->g.n = &x->sp11_Response->gg.g;
            x->sp11_Response = (struct zx_sp11_Response_s*)el;
            break;
          case zx_ff12_RegisterNameIdentifierRequest_ELEM:
            el = (struct zx_elem_s*)zx_DEC_ff12_RegisterNameIdentifierRequest(c, ns);
            el->g.n = &x->RegisterNameIdentifierRequest->gg.g;
            x->RegisterNameIdentifierRequest = (struct zx_ff12_RegisterNameIdentifierRequest_s*)el;
            break;
          case zx_ff12_RegisterNameIdentifierResponse_ELEM:
            el = (struct zx_elem_s*)zx_DEC_ff12_RegisterNameIdentifierResponse(c, ns);
            el->g.n = &x->RegisterNameIdentifierResponse->gg.g;
            x->RegisterNameIdentifierResponse = (struct zx_ff12_RegisterNameIdentifierResponse_s*)el;
            break;
          case zx_ff12_FederationTerminationNotification_ELEM:
            el = (struct zx_elem_s*)zx_DEC_ff12_FederationTerminationNotification(c, ns);
            el->g.n = &x->FederationTerminationNotification->gg.g;
            x->FederationTerminationNotification = (struct zx_ff12_FederationTerminationNotification_s*)el;
            break;
          case zx_ff12_LogoutRequest_ELEM:
            el = (struct zx_elem_s*)zx_DEC_ff12_LogoutRequest(c, ns);
            el->g.n = &x->ff12_LogoutRequest->gg.g;
            x->ff12_LogoutRequest = (struct zx_ff12_LogoutRequest_s*)el;
            break;
          case zx_ff12_LogoutResponse_ELEM:
            el = (struct zx_elem_s*)zx_DEC_ff12_LogoutResponse(c, ns);
            el->g.n = &x->ff12_LogoutResponse->gg.g;
            x->ff12_LogoutResponse = (struct zx_ff12_LogoutResponse_s*)el;
            break;
          case zx_ff12_NameIdentifierMappingRequest_ELEM:
            el = (struct zx_elem_s*)zx_DEC_ff12_NameIdentifierMappingRequest(c, ns);
            el->g.n = &x->NameIdentifierMappingRequest->gg.g;
            x->NameIdentifierMappingRequest = (struct zx_ff12_NameIdentifierMappingRequest_s*)el;
            break;
          case zx_ff12_NameIdentifierMappingResponse_ELEM:
            el = (struct zx_elem_s*)zx_DEC_ff12_NameIdentifierMappingResponse(c, ns);
            el->g.n = &x->NameIdentifierMappingResponse->gg.g;
            x->NameIdentifierMappingResponse = (struct zx_ff12_NameIdentifierMappingResponse_s*)el;
            break;
          case zx_xasp_XACMLAuthzDecisionQuery_ELEM:
            el = (struct zx_elem_s*)zx_DEC_xasp_XACMLAuthzDecisionQuery(c, ns);
            el->g.n = &x->XACMLAuthzDecisionQuery->gg.g;
            x->XACMLAuthzDecisionQuery = (struct zx_xasp_XACMLAuthzDecisionQuery_s*)el;
            break;
          case zx_xasp_XACMLPolicyQuery_ELEM:
            el = (struct zx_elem_s*)zx_DEC_xasp_XACMLPolicyQuery(c, ns);
            el->g.n = &x->XACMLPolicyQuery->gg.g;
            x->XACMLPolicyQuery = (struct zx_xasp_XACMLPolicyQuery_s*)el;
            break;
          case zx_xaspcd1_XACMLAuthzDecisionQuery_ELEM:
            el = (struct zx_elem_s*)zx_DEC_xaspcd1_XACMLAuthzDecisionQuery(c, ns);
            el->g.n = &x->xaspcd1_XACMLAuthzDecisionQuery->gg.g;
            x->xaspcd1_XACMLAuthzDecisionQuery = (struct zx_xaspcd1_XACMLAuthzDecisionQuery_s*)el;
            break;
          case zx_xaspcd1_XACMLPolicyQuery_ELEM:
            el = (struct zx_elem_s*)zx_DEC_xaspcd1_XACMLPolicyQuery(c, ns);
            el->g.n = &x->xaspcd1_XACMLPolicyQuery->gg.g;
            x->xaspcd1_XACMLPolicyQuery = (struct zx_xaspcd1_XACMLPolicyQuery_s*)el;
            break;
          case zx_xac_Request_ELEM:
            el = (struct zx_elem_s*)zx_DEC_xac_Request(c, ns);
            el->g.n = &x->xac_Request->gg.g;
            x->xac_Request = (struct zx_xac_Request_s*)el;
            break;
          case zx_xac_Response_ELEM:
            el = (struct zx_elem_s*)zx_DEC_xac_Response(c, ns);
            el->g.n = &x->xac_Response->gg.g;
            x->xac_Response = (struct zx_xac_Response_s*)el;
            break;
          case zx_di_Query_ELEM:
            el = (struct zx_elem_s*)zx_DEC_di_Query(c, ns);
            el->g.n = &x->Query->gg.g;
            x->Query = (struct zx_di_Query_s*)el;
            break;
          case zx_di_QueryResponse_ELEM:
            el = (struct zx_elem_s*)zx_DEC_di_QueryResponse(c, ns);
            el->g.n = &x->QueryResponse->gg.g;
            x->QueryResponse = (struct zx_di_QueryResponse_s*)el;
            break;
          case zx_di12_Query_ELEM:
            el = (struct zx_elem_s*)zx_DEC_di12_Query(c, ns);
            el->g.n = &x->di12_Query->gg.g;
            x->di12_Query = (struct zx_di12_Query_s*)el;
            break;
          case zx_di12_QueryResponse_ELEM:
            el = (struct zx_elem_s*)zx_DEC_di12_QueryResponse(c, ns);
            el->g.n = &x->di12_QueryResponse->gg.g;
            x->di12_QueryResponse = (struct zx_di12_QueryResponse_s*)el;
            break;
          case zx_di12_Modify_ELEM:
            el = (struct zx_elem_s*)zx_DEC_di12_Modify(c, ns);
            el->g.n = &x->Modify->gg.g;
            x->Modify = (struct zx_di12_Modify_s*)el;
            break;
          case zx_di12_ModifyResponse_ELEM:
            el = (struct zx_elem_s*)zx_DEC_di12_ModifyResponse(c, ns);
            el->g.n = &x->ModifyResponse->gg.g;
            x->ModifyResponse = (struct zx_di12_ModifyResponse_s*)el;
            break;
          case zx_e_Fault_ELEM:
            el = (struct zx_elem_s*)zx_DEC_e_Fault(c, ns);
            el->g.n = &x->Fault->gg.g;
            x->Fault = (struct zx_e_Fault_s*)el;
            break;
          case zx_di_SvcMDAssociationAdd_ELEM:
            el = (struct zx_elem_s*)zx_DEC_di_SvcMDAssociationAdd(c, ns);
            el->g.n = &x->SvcMDAssociationAdd->gg.g;
            x->SvcMDAssociationAdd = (struct zx_di_SvcMDAssociationAdd_s*)el;
            break;
          case zx_di_SvcMDAssociationAddResponse_ELEM:
            el = (struct zx_elem_s*)zx_DEC_di_SvcMDAssociationAddResponse(c, ns);
            el->g.n = &x->SvcMDAssociationAddResponse->gg.g;
            x->SvcMDAssociationAddResponse = (struct zx_di_SvcMDAssociationAddResponse_s*)el;
            break;
          case zx_di_SvcMDAssociationDelete_ELEM:
            el = (struct zx_elem_s*)zx_DEC_di_SvcMDAssociationDelete(c, ns);
            el->g.n = &x->SvcMDAssociationDelete->gg.g;
            x->SvcMDAssociationDelete = (struct zx_di_SvcMDAssociationDelete_s*)el;
            break;
          case zx_di_SvcMDAssociationDeleteResponse_ELEM:
            el = (struct zx_elem_s*)zx_DEC_di_SvcMDAssociationDeleteResponse(c, ns);
            el->g.n = &x->SvcMDAssociationDeleteResponse->gg.g;
            x->SvcMDAssociationDeleteResponse = (struct zx_di_SvcMDAssociationDeleteResponse_s*)el;
            break;
          case zx_di_SvcMDAssociationQuery_ELEM:
            el = (struct zx_elem_s*)zx_DEC_di_SvcMDAssociationQuery(c, ns);
            el->g.n = &x->SvcMDAssociationQuery->gg.g;
            x->SvcMDAssociationQuery = (struct zx_di_SvcMDAssociationQuery_s*)el;
            break;
          case zx_di_SvcMDAssociationQueryResponse_ELEM:
            el = (struct zx_elem_s*)zx_DEC_di_SvcMDAssociationQueryResponse(c, ns);
            el->g.n = &x->SvcMDAssociationQueryResponse->gg.g;
            x->SvcMDAssociationQueryResponse = (struct zx_di_SvcMDAssociationQueryResponse_s*)el;
            break;
          case zx_di_SvcMDRegister_ELEM:
            el = (struct zx_elem_s*)zx_DEC_di_SvcMDRegister(c, ns);
            el->g.n = &x->SvcMDRegister->gg.g;
            x->SvcMDRegister = (struct zx_di_SvcMDRegister_s*)el;
            break;
          case zx_di_SvcMDRegisterResponse_ELEM:
            el = (struct zx_elem_s*)zx_DEC_di_SvcMDRegisterResponse(c, ns);
            el->g.n = &x->SvcMDRegisterResponse->gg.g;
            x->SvcMDRegisterResponse = (struct zx_di_SvcMDRegisterResponse_s*)el;
            break;
          case zx_di_SvcMDDelete_ELEM:
            el = (struct zx_elem_s*)zx_DEC_di_SvcMDDelete(c, ns);
            el->g.n = &x->SvcMDDelete->gg.g;
            x->SvcMDDelete = (struct zx_di_SvcMDDelete_s*)el;
            break;
          case zx_di_SvcMDDeleteResponse_ELEM:
            el = (struct zx_elem_s*)zx_DEC_di_SvcMDDeleteResponse(c, ns);
            el->g.n = &x->SvcMDDeleteResponse->gg.g;
            x->SvcMDDeleteResponse = (struct zx_di_SvcMDDeleteResponse_s*)el;
            break;
          case zx_di_SvcMDQuery_ELEM:
            el = (struct zx_elem_s*)zx_DEC_di_SvcMDQuery(c, ns);
            el->g.n = &x->SvcMDQuery->gg.g;
            x->SvcMDQuery = (struct zx_di_SvcMDQuery_s*)el;
            break;
          case zx_di_SvcMDQueryResponse_ELEM:
            el = (struct zx_elem_s*)zx_DEC_di_SvcMDQueryResponse(c, ns);
            el->g.n = &x->SvcMDQueryResponse->gg.g;
            x->SvcMDQueryResponse = (struct zx_di_SvcMDQueryResponse_s*)el;
            break;
          case zx_di_SvcMDReplace_ELEM:
            el = (struct zx_elem_s*)zx_DEC_di_SvcMDReplace(c, ns);
            el->g.n = &x->SvcMDReplace->gg.g;
            x->SvcMDReplace = (struct zx_di_SvcMDReplace_s*)el;
            break;
          case zx_di_SvcMDReplaceResponse_ELEM:
            el = (struct zx_elem_s*)zx_DEC_di_SvcMDReplaceResponse(c, ns);
            el->g.n = &x->SvcMDReplaceResponse->gg.g;
            x->SvcMDReplaceResponse = (struct zx_di_SvcMDReplaceResponse_s*)el;
            break;
          case zx_dap_Create_ELEM:
            el = (struct zx_elem_s*)zx_DEC_dap_Create(c, ns);
            el->g.n = &x->Create->gg.g;
            x->Create = (struct zx_dap_Create_s*)el;
            break;
          case zx_dap_CreateResponse_ELEM:
            el = (struct zx_elem_s*)zx_DEC_dap_CreateResponse(c, ns);
            el->g.n = &x->CreateResponse->gg.g;
            x->CreateResponse = (struct zx_dap_CreateResponse_s*)el;
            break;
          case zx_dap_Query_ELEM:
            el = (struct zx_elem_s*)zx_DEC_dap_Query(c, ns);
            el->g.n = &x->dap_Query->gg.g;
            x->dap_Query = (struct zx_dap_Query_s*)el;
            break;
          case zx_dap_QueryResponse_ELEM:
            el = (struct zx_elem_s*)zx_DEC_dap_QueryResponse(c, ns);
            el->g.n = &x->dap_QueryResponse->gg.g;
            x->dap_QueryResponse = (struct zx_dap_QueryResponse_s*)el;
            break;
          case zx_dap_Modify_ELEM:
            el = (struct zx_elem_s*)zx_DEC_dap_Modify(c, ns);
            el->g.n = &x->dap_Modify->gg.g;
            x->dap_Modify = (struct zx_dap_Modify_s*)el;
            break;
          case zx_dap_ModifyResponse_ELEM:
            el = (struct zx_elem_s*)zx_DEC_dap_ModifyResponse(c, ns);
            el->g.n = &x->dap_ModifyResponse->gg.g;
            x->dap_ModifyResponse = (struct zx_dap_ModifyResponse_s*)el;
            break;
          case zx_dap_Delete_ELEM:
            el = (struct zx_elem_s*)zx_DEC_dap_Delete(c, ns);
            el->g.n = &x->Delete->gg.g;
            x->Delete = (struct zx_dap_Delete_s*)el;
            break;
          case zx_dap_DeleteResponse_ELEM:
            el = (struct zx_elem_s*)zx_DEC_dap_DeleteResponse(c, ns);
            el->g.n = &x->DeleteResponse->gg.g;
            x->DeleteResponse = (struct zx_dap_DeleteResponse_s*)el;
            break;
          case zx_dap_Notify_ELEM:
            el = (struct zx_elem_s*)zx_DEC_dap_Notify(c, ns);
            el->g.n = &x->Notify->gg.g;
            x->Notify = (struct zx_dap_Notify_s*)el;
            break;
          case zx_dap_NotifyResponse_ELEM:
            el = (struct zx_elem_s*)zx_DEC_dap_NotifyResponse(c, ns);
            el->g.n = &x->NotifyResponse->gg.g;
            x->NotifyResponse = (struct zx_dap_NotifyResponse_s*)el;
            break;
          case zx_ps_AddEntityRequest_ELEM:
            el = (struct zx_elem_s*)zx_DEC_ps_AddEntityRequest(c, ns);
            el->g.n = &x->AddEntityRequest->gg.g;
            x->AddEntityRequest = (struct zx_ps_AddEntityRequest_s*)el;
            break;
          case zx_ps_AddEntityResponse_ELEM:
            el = (struct zx_elem_s*)zx_DEC_ps_AddEntityResponse(c, ns);
            el->g.n = &x->AddEntityResponse->gg.g;
            x->AddEntityResponse = (struct zx_ps_AddEntityResponse_s*)el;
            break;
          case zx_ps_AddKnownEntityRequest_ELEM:
            el = (struct zx_elem_s*)zx_DEC_ps_AddKnownEntityRequest(c, ns);
            el->g.n = &x->AddKnownEntityRequest->gg.g;
            x->AddKnownEntityRequest = (struct zx_ps_AddKnownEntityRequest_s*)el;
            break;
          case zx_ps_AddKnownEntityResponse_ELEM:
            el = (struct zx_elem_s*)zx_DEC_ps_AddKnownEntityResponse(c, ns);
            el->g.n = &x->AddKnownEntityResponse->gg.g;
            x->AddKnownEntityResponse = (struct zx_ps_AddKnownEntityResponse_s*)el;
            break;
          case zx_ps_AddCollectionRequest_ELEM:
            el = (struct zx_elem_s*)zx_DEC_ps_AddCollectionRequest(c, ns);
            el->g.n = &x->AddCollectionRequest->gg.g;
            x->AddCollectionRequest = (struct zx_ps_AddCollectionRequest_s*)el;
            break;
          case zx_ps_AddCollectionResponse_ELEM:
            el = (struct zx_elem_s*)zx_DEC_ps_AddCollectionResponse(c, ns);
            el->g.n = &x->AddCollectionResponse->gg.g;
            x->AddCollectionResponse = (struct zx_ps_AddCollectionResponse_s*)el;
            break;
          case zx_ps_AddToCollectionRequest_ELEM:
            el = (struct zx_elem_s*)zx_DEC_ps_AddToCollectionRequest(c, ns);
            el->g.n = &x->AddToCollectionRequest->gg.g;
            x->AddToCollectionRequest = (struct zx_ps_AddToCollectionRequest_s*)el;
            break;
          case zx_ps_AddToCollectionResponse_ELEM:
            el = (struct zx_elem_s*)zx_DEC_ps_AddToCollectionResponse(c, ns);
            el->g.n = &x->AddToCollectionResponse->gg.g;
            x->AddToCollectionResponse = (struct zx_ps_AddToCollectionResponse_s*)el;
            break;
          case zx_ps_RemoveEntityRequest_ELEM:
            el = (struct zx_elem_s*)zx_DEC_ps_RemoveEntityRequest(c, ns);
            el->g.n = &x->RemoveEntityRequest->gg.g;
            x->RemoveEntityRequest = (struct zx_ps_RemoveEntityRequest_s*)el;
            break;
          case zx_ps_RemoveEntityResponse_ELEM:
            el = (struct zx_elem_s*)zx_DEC_ps_RemoveEntityResponse(c, ns);
            el->g.n = &x->RemoveEntityResponse->gg.g;
            x->RemoveEntityResponse = (struct zx_ps_RemoveEntityResponse_s*)el;
            break;
          case zx_ps_RemoveCollectionRequest_ELEM:
            el = (struct zx_elem_s*)zx_DEC_ps_RemoveCollectionRequest(c, ns);
            el->g.n = &x->RemoveCollectionRequest->gg.g;
            x->RemoveCollectionRequest = (struct zx_ps_RemoveCollectionRequest_s*)el;
            break;
          case zx_ps_RemoveCollectionResponse_ELEM:
            el = (struct zx_elem_s*)zx_DEC_ps_RemoveCollectionResponse(c, ns);
            el->g.n = &x->RemoveCollectionResponse->gg.g;
            x->RemoveCollectionResponse = (struct zx_ps_RemoveCollectionResponse_s*)el;
            break;
          case zx_ps_RemoveFromCollectionRequest_ELEM:
            el = (struct zx_elem_s*)zx_DEC_ps_RemoveFromCollectionRequest(c, ns);
            el->g.n = &x->RemoveFromCollectionRequest->gg.g;
            x->RemoveFromCollectionRequest = (struct zx_ps_RemoveFromCollectionRequest_s*)el;
            break;
          case zx_ps_RemoveFromCollectionResponse_ELEM:
            el = (struct zx_elem_s*)zx_DEC_ps_RemoveFromCollectionResponse(c, ns);
            el->g.n = &x->RemoveFromCollectionResponse->gg.g;
            x->RemoveFromCollectionResponse = (struct zx_ps_RemoveFromCollectionResponse_s*)el;
            break;
          case zx_ps_ListMembersRequest_ELEM:
            el = (struct zx_elem_s*)zx_DEC_ps_ListMembersRequest(c, ns);
            el->g.n = &x->ListMembersRequest->gg.g;
            x->ListMembersRequest = (struct zx_ps_ListMembersRequest_s*)el;
            break;
          case zx_ps_ListMembersResponse_ELEM:
            el = (struct zx_elem_s*)zx_DEC_ps_ListMembersResponse(c, ns);
            el->g.n = &x->ListMembersResponse->gg.g;
            x->ListMembersResponse = (struct zx_ps_ListMembersResponse_s*)el;
            break;
          case zx_ps_QueryObjectsRequest_ELEM:
            el = (struct zx_elem_s*)zx_DEC_ps_QueryObjectsRequest(c, ns);
            el->g.n = &x->QueryObjectsRequest->gg.g;
            x->QueryObjectsRequest = (struct zx_ps_QueryObjectsRequest_s*)el;
            break;
          case zx_ps_QueryObjectsResponse_ELEM:
            el = (struct zx_elem_s*)zx_DEC_ps_QueryObjectsResponse(c, ns);
            el->g.n = &x->QueryObjectsResponse->gg.g;
            x->QueryObjectsResponse = (struct zx_ps_QueryObjectsResponse_s*)el;
            break;
          case zx_ps_GetObjectInfoRequest_ELEM:
            el = (struct zx_elem_s*)zx_DEC_ps_GetObjectInfoRequest(c, ns);
            el->g.n = &x->GetObjectInfoRequest->gg.g;
            x->GetObjectInfoRequest = (struct zx_ps_GetObjectInfoRequest_s*)el;
            break;
          case zx_ps_GetObjectInfoResponse_ELEM:
            el = (struct zx_elem_s*)zx_DEC_ps_GetObjectInfoResponse(c, ns);
            el->g.n = &x->GetObjectInfoResponse->gg.g;
            x->GetObjectInfoResponse = (struct zx_ps_GetObjectInfoResponse_s*)el;
            break;
          case zx_ps_SetObjectInfoRequest_ELEM:
            el = (struct zx_elem_s*)zx_DEC_ps_SetObjectInfoRequest(c, ns);
            el->g.n = &x->SetObjectInfoRequest->gg.g;
            x->SetObjectInfoRequest = (struct zx_ps_SetObjectInfoRequest_s*)el;
            break;
          case zx_ps_SetObjectInfoResponse_ELEM:
            el = (struct zx_elem_s*)zx_DEC_ps_SetObjectInfoResponse(c, ns);
            el->g.n = &x->SetObjectInfoResponse->gg.g;
            x->SetObjectInfoResponse = (struct zx_ps_SetObjectInfoResponse_s*)el;
            break;
          case zx_ps_TestMembershipRequest_ELEM:
            el = (struct zx_elem_s*)zx_DEC_ps_TestMembershipRequest(c, ns);
            el->g.n = &x->TestMembershipRequest->gg.g;
            x->TestMembershipRequest = (struct zx_ps_TestMembershipRequest_s*)el;
            break;
          case zx_ps_TestMembershipResponse_ELEM:
            el = (struct zx_elem_s*)zx_DEC_ps_TestMembershipResponse(c, ns);
            el->g.n = &x->TestMembershipResponse->gg.g;
            x->TestMembershipResponse = (struct zx_ps_TestMembershipResponse_s*)el;
            break;
          case zx_ps_ResolveIdentifierRequest_ELEM:
            el = (struct zx_elem_s*)zx_DEC_ps_ResolveIdentifierRequest(c, ns);
            el->g.n = &x->ResolveIdentifierRequest->gg.g;
            x->ResolveIdentifierRequest = (struct zx_ps_ResolveIdentifierRequest_s*)el;
            break;
          case zx_ps_ResolveIdentifierResponse_ELEM:
            el = (struct zx_elem_s*)zx_DEC_ps_ResolveIdentifierResponse(c, ns);
            el->g.n = &x->ResolveIdentifierResponse->gg.g;
            x->ResolveIdentifierResponse = (struct zx_ps_ResolveIdentifierResponse_s*)el;
            break;
          case zx_ps_Notify_ELEM:
            el = (struct zx_elem_s*)zx_DEC_ps_Notify(c, ns);
            el->g.n = &x->ps_Notify->gg.g;
            x->ps_Notify = (struct zx_ps_Notify_s*)el;
            break;
          case zx_ps_NotifyResponse_ELEM:
            el = (struct zx_elem_s*)zx_DEC_ps_NotifyResponse(c, ns);
            el->g.n = &x->ps_NotifyResponse->gg.g;
            x->ps_NotifyResponse = (struct zx_ps_NotifyResponse_s*)el;
            break;
          case zx_im_IdentityMappingRequest_ELEM:
            el = (struct zx_elem_s*)zx_DEC_im_IdentityMappingRequest(c, ns);
            el->g.n = &x->IdentityMappingRequest->gg.g;
            x->IdentityMappingRequest = (struct zx_im_IdentityMappingRequest_s*)el;
            break;
          case zx_im_IdentityMappingResponse_ELEM:
            el = (struct zx_elem_s*)zx_DEC_im_IdentityMappingResponse(c, ns);
            el->g.n = &x->IdentityMappingResponse->gg.g;
            x->IdentityMappingResponse = (struct zx_im_IdentityMappingResponse_s*)el;
            break;
          case zx_as_SASLRequest_ELEM:
            el = (struct zx_elem_s*)zx_DEC_as_SASLRequest(c, ns);
            el->g.n = &x->SASLRequest->gg.g;
            x->SASLRequest = (struct zx_as_SASLRequest_s*)el;
            break;
          case zx_as_SASLResponse_ELEM:
            el = (struct zx_elem_s*)zx_DEC_as_SASLResponse(c, ns);
            el->g.n = &x->SASLResponse->gg.g;
            x->SASLResponse = (struct zx_as_SASLResponse_s*)el;
            break;
          case zx_mm7_SubmitReq_ELEM:
            el = (struct zx_elem_s*)zx_DEC_mm7_SubmitReq(c, ns);
            el->g.n = &x->SubmitReq->gg.g;
            x->SubmitReq = (struct zx_mm7_SubmitReq_s*)el;
            break;
          case zx_mm7_SubmitRsp_ELEM:
            el = (struct zx_elem_s*)zx_DEC_mm7_SubmitRsp(c, ns);
            el->g.n = &x->SubmitRsp->gg.g;
            x->SubmitRsp = (struct zx_mm7_SubmitRsp_s*)el;
            break;
          case zx_mm7_DeliverReq_ELEM:
            el = (struct zx_elem_s*)zx_DEC_mm7_DeliverReq(c, ns);
            el->g.n = &x->DeliverReq->gg.g;
            x->DeliverReq = (struct zx_mm7_DeliverReq_s*)el;
            break;
          case zx_mm7_DeliverRsp_ELEM:
            el = (struct zx_elem_s*)zx_DEC_mm7_DeliverRsp(c, ns);
            el->g.n = &x->DeliverRsp->gg.g;
            x->DeliverRsp = (struct zx_mm7_DeliverRsp_s*)el;
            break;
          case zx_mm7_CancelReq_ELEM:
            el = (struct zx_elem_s*)zx_DEC_mm7_CancelReq(c, ns);
            el->g.n = &x->CancelReq->gg.g;
            x->CancelReq = (struct zx_mm7_CancelReq_s*)el;
            break;
          case zx_mm7_CancelRsp_ELEM:
            el = (struct zx_elem_s*)zx_DEC_mm7_CancelRsp(c, ns);
            el->g.n = &x->CancelRsp->gg.g;
            x->CancelRsp = (struct zx_mm7_CancelRsp_s*)el;
            break;
          case zx_mm7_ReplaceReq_ELEM:
            el = (struct zx_elem_s*)zx_DEC_mm7_ReplaceReq(c, ns);
            el->g.n = &x->ReplaceReq->gg.g;
            x->ReplaceReq = (struct zx_mm7_ReplaceReq_s*)el;
            break;
          case zx_mm7_ReplaceRsp_ELEM:
            el = (struct zx_elem_s*)zx_DEC_mm7_ReplaceRsp(c, ns);
            el->g.n = &x->ReplaceRsp->gg.g;
            x->ReplaceRsp = (struct zx_mm7_ReplaceRsp_s*)el;
            break;
          case zx_mm7_extendedCancelReq_ELEM:
            el = (struct zx_elem_s*)zx_DEC_mm7_extendedCancelReq(c, ns);
            el->g.n = &x->extendedCancelReq->gg.g;
            x->extendedCancelReq = (struct zx_mm7_extendedCancelReq_s*)el;
            break;
          case zx_mm7_extendedCancelRsp_ELEM:
            el = (struct zx_elem_s*)zx_DEC_mm7_extendedCancelRsp(c, ns);
            el->g.n = &x->extendedCancelRsp->gg.g;
            x->extendedCancelRsp = (struct zx_mm7_extendedCancelRsp_s*)el;
            break;
          case zx_mm7_extendedReplaceReq_ELEM:
            el = (struct zx_elem_s*)zx_DEC_mm7_extendedReplaceReq(c, ns);
            el->g.n = &x->extendedReplaceReq->gg.g;
            x->extendedReplaceReq = (struct zx_mm7_extendedReplaceReq_s*)el;
            break;
          case zx_mm7_extendedReplaceRsp_ELEM:
            el = (struct zx_elem_s*)zx_DEC_mm7_extendedReplaceRsp(c, ns);
            el->g.n = &x->extendedReplaceRsp->gg.g;
            x->extendedReplaceRsp = (struct zx_mm7_extendedReplaceRsp_s*)el;
            break;
          case zx_mm7_DeliveryReportReq_ELEM:
            el = (struct zx_elem_s*)zx_DEC_mm7_DeliveryReportReq(c, ns);
            el->g.n = &x->DeliveryReportReq->gg.g;
            x->DeliveryReportReq = (struct zx_mm7_DeliveryReportReq_s*)el;
            break;
          case zx_mm7_DeliveryReportRsp_ELEM:
            el = (struct zx_elem_s*)zx_DEC_mm7_DeliveryReportRsp(c, ns);
            el->g.n = &x->DeliveryReportRsp->gg.g;
            x->DeliveryReportRsp = (struct zx_mm7_DeliveryReportRsp_s*)el;
            break;
          case zx_mm7_ReadReplyReq_ELEM:
            el = (struct zx_elem_s*)zx_DEC_mm7_ReadReplyReq(c, ns);
            el->g.n = &x->ReadReplyReq->gg.g;
            x->ReadReplyReq = (struct zx_mm7_ReadReplyReq_s*)el;
            break;
          case zx_mm7_ReadReplyRsp_ELEM:
            el = (struct zx_elem_s*)zx_DEC_mm7_ReadReplyRsp(c, ns);
            el->g.n = &x->ReadReplyRsp->gg.g;
            x->ReadReplyRsp = (struct zx_mm7_ReadReplyRsp_s*)el;
            break;
          case zx_mm7_RSErrorRsp_ELEM:
            el = (struct zx_elem_s*)zx_DEC_mm7_RSErrorRsp(c, ns);
            el->g.n = &x->RSErrorRsp->gg.g;
            x->RSErrorRsp = (struct zx_mm7_RSErrorRsp_s*)el;
            break;
          case zx_mm7_VASPErrorRsp_ELEM:
            el = (struct zx_elem_s*)zx_DEC_mm7_VASPErrorRsp(c, ns);
            el->g.n = &x->VASPErrorRsp->gg.g;
            x->VASPErrorRsp = (struct zx_mm7_VASPErrorRsp_s*)el;
            break;
          case zx_mm7_QueryStatusReq_ELEM:
            el = (struct zx_elem_s*)zx_DEC_mm7_QueryStatusReq(c, ns);
            el->g.n = &x->QueryStatusReq->gg.g;
            x->QueryStatusReq = (struct zx_mm7_QueryStatusReq_s*)el;
            break;
          case zx_mm7_QueryStatusRsp_ELEM:
            el = (struct zx_elem_s*)zx_DEC_mm7_QueryStatusRsp(c, ns);
            el->g.n = &x->QueryStatusRsp->gg.g;
            x->QueryStatusRsp = (struct zx_mm7_QueryStatusRsp_s*)el;
            break;
          case zx_cb_Query_ELEM:
            el = (struct zx_elem_s*)zx_DEC_cb_Query(c, ns);
            el->g.n = &x->cb_Query->gg.g;
            x->cb_Query = (struct zx_cb_Query_s*)el;
            break;
          case zx_cb_QueryResponse_ELEM:
            el = (struct zx_elem_s*)zx_DEC_cb_QueryResponse(c, ns);
            el->g.n = &x->cb_QueryResponse->gg.g;
            x->cb_QueryResponse = (struct zx_cb_QueryResponse_s*)el;
            break;
          case zx_cb_Create_ELEM:
            el = (struct zx_elem_s*)zx_DEC_cb_Create(c, ns);
            el->g.n = &x->cb_Create->gg.g;
            x->cb_Create = (struct zx_cb_Create_s*)el;
            break;
          case zx_cb_CreateResponse_ELEM:
            el = (struct zx_elem_s*)zx_DEC_cb_CreateResponse(c, ns);
            el->g.n = &x->cb_CreateResponse->gg.g;
            x->cb_CreateResponse = (struct zx_cb_CreateResponse_s*)el;
            break;
          case zx_cb_Delete_ELEM:
            el = (struct zx_elem_s*)zx_DEC_cb_Delete(c, ns);
            el->g.n = &x->cb_Delete->gg.g;
            x->cb_Delete = (struct zx_cb_Delete_s*)el;
            break;
          case zx_cb_DeleteResponse_ELEM:
            el = (struct zx_elem_s*)zx_DEC_cb_DeleteResponse(c, ns);
            el->g.n = &x->cb_DeleteResponse->gg.g;
            x->cb_DeleteResponse = (struct zx_cb_DeleteResponse_s*)el;
            break;
          case zx_cb_Modify_ELEM:
            el = (struct zx_elem_s*)zx_DEC_cb_Modify(c, ns);
            el->g.n = &x->cb_Modify->gg.g;
            x->cb_Modify = (struct zx_cb_Modify_s*)el;
            break;
          case zx_cb_ModifyResponse_ELEM:
            el = (struct zx_elem_s*)zx_DEC_cb_ModifyResponse(c, ns);
            el->g.n = &x->cb_ModifyResponse->gg.g;
            x->cb_ModifyResponse = (struct zx_cb_ModifyResponse_s*)el;
            break;
          case zx_cb_Notify_ELEM:
            el = (struct zx_elem_s*)zx_DEC_cb_Notify(c, ns);
            el->g.n = &x->cb_Notify->gg.g;
            x->cb_Notify = (struct zx_cb_Notify_s*)el;
            break;
          case zx_cb_NotifyResponse_ELEM:
            el = (struct zx_elem_s*)zx_DEC_cb_NotifyResponse(c, ns);
            el->g.n = &x->cb_NotifyResponse->gg.g;
            x->cb_NotifyResponse = (struct zx_cb_NotifyResponse_s*)el;
            break;
          case zx_cb_ReportUsage_ELEM:
            el = (struct zx_elem_s*)zx_DEC_cb_ReportUsage(c, ns);
            el->g.n = &x->ReportUsage->gg.g;
            x->ReportUsage = (struct zx_cb_ReportUsage_s*)el;
            break;
          case zx_cb_ReportUsageResponse_ELEM:
            el = (struct zx_elem_s*)zx_DEC_cb_ReportUsageResponse(c, ns);
            el->g.n = &x->ReportUsageResponse->gg.g;
            x->ReportUsageResponse = (struct zx_cb_ReportUsageResponse_s*)el;
            break;
          case zx_gl_Query_ELEM:
            el = (struct zx_elem_s*)zx_DEC_gl_Query(c, ns);
            el->g.n = &x->gl_Query->gg.g;
            x->gl_Query = (struct zx_gl_Query_s*)el;
            break;
          case zx_gl_QueryResponse_ELEM:
            el = (struct zx_elem_s*)zx_DEC_gl_QueryResponse(c, ns);
            el->g.n = &x->gl_QueryResponse->gg.g;
            x->gl_QueryResponse = (struct zx_gl_QueryResponse_s*)el;
            break;
          case zx_gl_Create_ELEM:
            el = (struct zx_elem_s*)zx_DEC_gl_Create(c, ns);
            el->g.n = &x->gl_Create->gg.g;
            x->gl_Create = (struct zx_gl_Create_s*)el;
            break;
          case zx_gl_CreateResponse_ELEM:
            el = (struct zx_elem_s*)zx_DEC_gl_CreateResponse(c, ns);
            el->g.n = &x->gl_CreateResponse->gg.g;
            x->gl_CreateResponse = (struct zx_gl_CreateResponse_s*)el;
            break;
          case zx_gl_Delete_ELEM:
            el = (struct zx_elem_s*)zx_DEC_gl_Delete(c, ns);
            el->g.n = &x->gl_Delete->gg.g;
            x->gl_Delete = (struct zx_gl_Delete_s*)el;
            break;
          case zx_gl_DeleteResponse_ELEM:
            el = (struct zx_elem_s*)zx_DEC_gl_DeleteResponse(c, ns);
            el->g.n = &x->gl_DeleteResponse->gg.g;
            x->gl_DeleteResponse = (struct zx_gl_DeleteResponse_s*)el;
            break;
          case zx_gl_Modify_ELEM:
            el = (struct zx_elem_s*)zx_DEC_gl_Modify(c, ns);
            el->g.n = &x->gl_Modify->gg.g;
            x->gl_Modify = (struct zx_gl_Modify_s*)el;
            break;
          case zx_gl_ModifyResponse_ELEM:
            el = (struct zx_elem_s*)zx_DEC_gl_ModifyResponse(c, ns);
            el->g.n = &x->gl_ModifyResponse->gg.g;
            x->gl_ModifyResponse = (struct zx_gl_ModifyResponse_s*)el;
            break;
          case zx_gl_Notify_ELEM:
            el = (struct zx_elem_s*)zx_DEC_gl_Notify(c, ns);
            el->g.n = &x->gl_Notify->gg.g;
            x->gl_Notify = (struct zx_gl_Notify_s*)el;
            break;
          case zx_gl_NotifyResponse_ELEM:
            el = (struct zx_elem_s*)zx_DEC_gl_NotifyResponse(c, ns);
            el->g.n = &x->gl_NotifyResponse->gg.g;
            x->gl_NotifyResponse = (struct zx_gl_NotifyResponse_s*)el;
            break;
          case zx_demomed_StoreObjectRequest_ELEM:
            el = (struct zx_elem_s*)zx_DEC_demomed_StoreObjectRequest(c, ns);
            el->g.n = &x->StoreObjectRequest->gg.g;
            x->StoreObjectRequest = (struct zx_demomed_StoreObjectRequest_s*)el;
            break;
          case zx_demomed_StoreObjectResponse_ELEM:
            el = (struct zx_elem_s*)zx_DEC_demomed_StoreObjectResponse(c, ns);
            el->g.n = &x->StoreObjectResponse->gg.g;
            x->StoreObjectResponse = (struct zx_demomed_StoreObjectResponse_s*)el;
            break;
          case zx_demomed_GetObjectListRequest_ELEM:
            el = (struct zx_elem_s*)zx_DEC_demomed_GetObjectListRequest(c, ns);
            el->g.n = &x->GetObjectListRequest->gg.g;
            x->GetObjectListRequest = (struct zx_demomed_GetObjectListRequest_s*)el;
            break;
          case zx_demomed_GetObjectListResponse_ELEM:
            el = (struct zx_elem_s*)zx_DEC_demomed_GetObjectListResponse(c, ns);
            el->g.n = &x->GetObjectListResponse->gg.g;
            x->GetObjectListResponse = (struct zx_demomed_GetObjectListResponse_s*)el;
            break;
          case zx_demomed_GetObjectRequest_ELEM:
            el = (struct zx_elem_s*)zx_DEC_demomed_GetObjectRequest(c, ns);
            el->g.n = &x->GetObjectRequest->gg.g;
            x->GetObjectRequest = (struct zx_demomed_GetObjectRequest_s*)el;
            break;
          case zx_demomed_GetObjectResponse_ELEM:
            el = (struct zx_elem_s*)zx_DEC_demomed_GetObjectResponse(c, ns);
            el->g.n = &x->GetObjectResponse->gg.g;
            x->GetObjectResponse = (struct zx_demomed_GetObjectResponse_s*)el;
            break;
          case zx_demomed_DeleteObjectRequest_ELEM:
            el = (struct zx_elem_s*)zx_DEC_demomed_DeleteObjectRequest(c, ns);
            el->g.n = &x->DeleteObjectRequest->gg.g;
            x->DeleteObjectRequest = (struct zx_demomed_DeleteObjectRequest_s*)el;
            break;
          case zx_demomed_DeleteObjectResponse_ELEM:
            el = (struct zx_elem_s*)zx_DEC_demomed_DeleteObjectResponse(c, ns);
            el->g.n = &x->DeleteObjectResponse->gg.g;
            x->DeleteObjectResponse = (struct zx_demomed_DeleteObjectResponse_s*)el;
            break;
          case zx_pmm_Provision_ELEM:
            el = (struct zx_elem_s*)zx_DEC_pmm_Provision(c, ns);
            el->g.n = &x->Provision->gg.g;
            x->Provision = (struct zx_pmm_Provision_s*)el;
            break;
          case zx_pmm_ProvisionResponse_ELEM:
            el = (struct zx_elem_s*)zx_DEC_pmm_ProvisionResponse(c, ns);
            el->g.n = &x->ProvisionResponse->gg.g;
            x->ProvisionResponse = (struct zx_pmm_ProvisionResponse_s*)el;
            break;
          case zx_pmm_PMActivate_ELEM:
            el = (struct zx_elem_s*)zx_DEC_pmm_PMActivate(c, ns);
            el->g.n = &x->PMActivate->gg.g;
            x->PMActivate = (struct zx_pmm_PMActivate_s*)el;
            break;
          case zx_pmm_PMActivateResponse_ELEM:
            el = (struct zx_elem_s*)zx_DEC_pmm_PMActivateResponse(c, ns);
            el->g.n = &x->PMActivateResponse->gg.g;
            x->PMActivateResponse = (struct zx_pmm_PMActivateResponse_s*)el;
            break;
          case zx_pmm_PMDeactivate_ELEM:
            el = (struct zx_elem_s*)zx_DEC_pmm_PMDeactivate(c, ns);
            el->g.n = &x->PMDeactivate->gg.g;
            x->PMDeactivate = (struct zx_pmm_PMDeactivate_s*)el;
            break;
          case zx_pmm_PMDeactivateResponse_ELEM:
            el = (struct zx_elem_s*)zx_DEC_pmm_PMDeactivateResponse(c, ns);
            el->g.n = &x->PMDeactivateResponse->gg.g;
            x->PMDeactivateResponse = (struct zx_pmm_PMDeactivateResponse_s*)el;
            break;
          case zx_pmm_PMDelete_ELEM:
            el = (struct zx_elem_s*)zx_DEC_pmm_PMDelete(c, ns);
            el->g.n = &x->PMDelete->gg.g;
            x->PMDelete = (struct zx_pmm_PMDelete_s*)el;
            break;
          case zx_pmm_PMDeleteResponse_ELEM:
            el = (struct zx_elem_s*)zx_DEC_pmm_PMDeleteResponse(c, ns);
            el->g.n = &x->PMDeleteResponse->gg.g;
            x->PMDeleteResponse = (struct zx_pmm_PMDeleteResponse_s*)el;
            break;
          case zx_pmm_PMUpdate_ELEM:
            el = (struct zx_elem_s*)zx_DEC_pmm_PMUpdate(c, ns);
            el->g.n = &x->PMUpdate->gg.g;
            x->PMUpdate = (struct zx_pmm_PMUpdate_s*)el;
            break;
          case zx_pmm_PMUpdateResponse_ELEM:
            el = (struct zx_elem_s*)zx_DEC_pmm_PMUpdateResponse(c, ns);
            el->g.n = &x->PMUpdateResponse->gg.g;
            x->PMUpdateResponse = (struct zx_pmm_PMUpdateResponse_s*)el;
            break;
          case zx_pmm_PMGetStatus_ELEM:
            el = (struct zx_elem_s*)zx_DEC_pmm_PMGetStatus(c, ns);
            el->g.n = &x->PMGetStatus->gg.g;
            x->PMGetStatus = (struct zx_pmm_PMGetStatus_s*)el;
            break;
          case zx_pmm_PMGetStatusResponse_ELEM:
            el = (struct zx_elem_s*)zx_DEC_pmm_PMGetStatusResponse(c, ns);
            el->g.n = &x->PMGetStatusResponse->gg.g;
            x->PMGetStatusResponse = (struct zx_pmm_PMGetStatusResponse_s*)el;
            break;
          case zx_pmm_PMSetStatus_ELEM:
            el = (struct zx_elem_s*)zx_DEC_pmm_PMSetStatus(c, ns);
            el->g.n = &x->PMSetStatus->gg.g;
            x->PMSetStatus = (struct zx_pmm_PMSetStatus_s*)el;
            break;
          case zx_pmm_PMSetStatusResponse_ELEM:
            el = (struct zx_elem_s*)zx_DEC_pmm_PMSetStatusResponse(c, ns);
            el->g.n = &x->PMSetStatusResponse->gg.g;
            x->PMSetStatusResponse = (struct zx_pmm_PMSetStatusResponse_s*)el;
            break;
          case zx_prov_PMERegister_ELEM:
            el = (struct zx_elem_s*)zx_DEC_prov_PMERegister(c, ns);
            el->g.n = &x->PMERegister->gg.g;
            x->PMERegister = (struct zx_prov_PMERegister_s*)el;
            break;
          case zx_prov_PMERegisterResponse_ELEM:
            el = (struct zx_elem_s*)zx_DEC_prov_PMERegisterResponse(c, ns);
            el->g.n = &x->PMERegisterResponse->gg.g;
            x->PMERegisterResponse = (struct zx_prov_PMERegisterResponse_s*)el;
            break;
          case zx_prov_PMEUpload_ELEM:
            el = (struct zx_elem_s*)zx_DEC_prov_PMEUpload(c, ns);
            el->g.n = &x->PMEUpload->gg.g;
            x->PMEUpload = (struct zx_prov_PMEUpload_s*)el;
            break;
          case zx_prov_PMEUploadResponse_ELEM:
            el = (struct zx_elem_s*)zx_DEC_prov_PMEUploadResponse(c, ns);
            el->g.n = &x->PMEUploadResponse->gg.g;
            x->PMEUploadResponse = (struct zx_prov_PMEUploadResponse_s*)el;
            break;
          case zx_prov_PMEDownload_ELEM:
            el = (struct zx_elem_s*)zx_DEC_prov_PMEDownload(c, ns);
            el->g.n = &x->PMEDownload->gg.g;
            x->PMEDownload = (struct zx_prov_PMEDownload_s*)el;
            break;
          case zx_prov_PMEDownloadResponse_ELEM:
            el = (struct zx_elem_s*)zx_DEC_prov_PMEDownloadResponse(c, ns);
            el->g.n = &x->PMEDownloadResponse->gg.g;
            x->PMEDownloadResponse = (struct zx_prov_PMEDownloadResponse_s*)el;
            break;
          case zx_prov_PMEEnable_ELEM:
            el = (struct zx_elem_s*)zx_DEC_prov_PMEEnable(c, ns);
            el->g.n = &x->PMEEnable->gg.g;
            x->PMEEnable = (struct zx_prov_PMEEnable_s*)el;
            break;
          case zx_prov_PMEEnableResponse_ELEM:
            el = (struct zx_elem_s*)zx_DEC_prov_PMEEnableResponse(c, ns);
            el->g.n = &x->PMEEnableResponse->gg.g;
            x->PMEEnableResponse = (struct zx_prov_PMEEnableResponse_s*)el;
            break;
          case zx_prov_PMEDisable_ELEM:
            el = (struct zx_elem_s*)zx_DEC_prov_PMEDisable(c, ns);
            el->g.n = &x->PMEDisable->gg.g;
            x->PMEDisable = (struct zx_prov_PMEDisable_s*)el;
            break;
          case zx_prov_PMEDisableResponse_ELEM:
            el = (struct zx_elem_s*)zx_DEC_prov_PMEDisableResponse(c, ns);
            el->g.n = &x->PMEDisableResponse->gg.g;
            x->PMEDisableResponse = (struct zx_prov_PMEDisableResponse_s*)el;
            break;
          case zx_prov_PMEDelete_ELEM:
            el = (struct zx_elem_s*)zx_DEC_prov_PMEDelete(c, ns);
            el->g.n = &x->PMEDelete->gg.g;
            x->PMEDelete = (struct zx_prov_PMEDelete_s*)el;
            break;
          case zx_prov_PMEDeleteResponse_ELEM:
            el = (struct zx_elem_s*)zx_DEC_prov_PMEDeleteResponse(c, ns);
            el->g.n = &x->PMEDeleteResponse->gg.g;
            x->PMEDeleteResponse = (struct zx_prov_PMEDeleteResponse_s*)el;
            break;
          case zx_prov_PMEGetInfo_ELEM:
            el = (struct zx_elem_s*)zx_DEC_prov_PMEGetInfo(c, ns);
            el->g.n = &x->PMEGetInfo->gg.g;
            x->PMEGetInfo = (struct zx_prov_PMEGetInfo_s*)el;
            break;
          case zx_prov_PMEGetInfoResponse_ELEM:
            el = (struct zx_elem_s*)zx_DEC_prov_PMEGetInfoResponse(c, ns);
            el->g.n = &x->PMEGetInfoResponse->gg.g;
            x->PMEGetInfoResponse = (struct zx_prov_PMEGetInfoResponse_s*)el;
            break;
          case zx_prov_PMGetStatus_ELEM:
            el = (struct zx_elem_s*)zx_DEC_prov_PMGetStatus(c, ns);
            el->g.n = &x->prov_PMGetStatus->gg.g;
            x->prov_PMGetStatus = (struct zx_prov_PMGetStatus_s*)el;
            break;
          case zx_prov_PMGetStatusResponse_ELEM:
            el = (struct zx_elem_s*)zx_DEC_prov_PMGetStatusResponse(c, ns);
            el->g.n = &x->prov_PMGetStatusResponse->gg.g;
            x->prov_PMGetStatusResponse = (struct zx_prov_PMGetStatusResponse_s*)el;
            break;
          case zx_prov_PMSetStatus_ELEM:
            el = (struct zx_elem_s*)zx_DEC_prov_PMSetStatus(c, ns);
            el->g.n = &x->prov_PMSetStatus->gg.g;
            x->prov_PMSetStatus = (struct zx_prov_PMSetStatus_s*)el;
            break;
          case zx_prov_PMSetStatusResponse_ELEM:
            el = (struct zx_elem_s*)zx_DEC_prov_PMSetStatusResponse(c, ns);
            el->g.n = &x->prov_PMSetStatusResponse->gg.g;
            x->prov_PMSetStatusResponse = (struct zx_prov_PMSetStatusResponse_s*)el;
            break;
          case zx_prov_PMGetDescriptor_ELEM:
            el = (struct zx_elem_s*)zx_DEC_prov_PMGetDescriptor(c, ns);
            el->g.n = &x->PMGetDescriptor->gg.g;
            x->PMGetDescriptor = (struct zx_prov_PMGetDescriptor_s*)el;
            break;
          case zx_prov_PMGetDescriptorResponse_ELEM:
            el = (struct zx_elem_s*)zx_DEC_prov_PMGetDescriptorResponse(c, ns);
            el->g.n = &x->PMGetDescriptorResponse->gg.g;
            x->PMGetDescriptorResponse = (struct zx_prov_PMGetDescriptorResponse_s*)el;
            break;
          case zx_prov_PMActivate_ELEM:
            el = (struct zx_elem_s*)zx_DEC_prov_PMActivate(c, ns);
            el->g.n = &x->prov_PMActivate->gg.g;
            x->prov_PMActivate = (struct zx_prov_PMActivate_s*)el;
            break;
          case zx_prov_PMActivateResponse_ELEM:
            el = (struct zx_elem_s*)zx_DEC_prov_PMActivateResponse(c, ns);
            el->g.n = &x->prov_PMActivateResponse->gg.g;
            x->prov_PMActivateResponse = (struct zx_prov_PMActivateResponse_s*)el;
            break;
          case zx_prov_PMDeactivate_ELEM:
            el = (struct zx_elem_s*)zx_DEC_prov_PMDeactivate(c, ns);
            el->g.n = &x->prov_PMDeactivate->gg.g;
            x->prov_PMDeactivate = (struct zx_prov_PMDeactivate_s*)el;
            break;
          case zx_prov_PMDeactivateResponse_ELEM:
            el = (struct zx_elem_s*)zx_DEC_prov_PMDeactivateResponse(c, ns);
            el->g.n = &x->prov_PMDeactivateResponse->gg.g;
            x->prov_PMDeactivateResponse = (struct zx_prov_PMDeactivateResponse_s*)el;
            break;
          case zx_prov_PMRegisterDescriptor_ELEM:
            el = (struct zx_elem_s*)zx_DEC_prov_PMRegisterDescriptor(c, ns);
            el->g.n = &x->PMRegisterDescriptor->gg.g;
            x->PMRegisterDescriptor = (struct zx_prov_PMRegisterDescriptor_s*)el;
            break;
          case zx_prov_PMRegisterDescriptorResponse_ELEM:
            el = (struct zx_elem_s*)zx_DEC_prov_PMRegisterDescriptorResponse(c, ns);
            el->g.n = &x->PMRegisterDescriptorResponse->gg.g;
            x->PMRegisterDescriptorResponse = (struct zx_prov_PMRegisterDescriptorResponse_s*)el;
            break;
          case zx_prov_PMUpdate_ELEM:
            el = (struct zx_elem_s*)zx_DEC_prov_PMUpdate(c, ns);
            el->g.n = &x->prov_PMUpdate->gg.g;
            x->prov_PMUpdate = (struct zx_prov_PMUpdate_s*)el;
            break;
          case zx_prov_PMUpdateResponse_ELEM:
            el = (struct zx_elem_s*)zx_DEC_prov_PMUpdateResponse(c, ns);
            el->g.n = &x->prov_PMUpdateResponse->gg.g;
            x->prov_PMUpdateResponse = (struct zx_prov_PMUpdateResponse_s*)el;
            break;
          case zx_prov_PMDelete_ELEM:
            el = (struct zx_elem_s*)zx_DEC_prov_PMDelete(c, ns);
            el->g.n = &x->prov_PMDelete->gg.g;
            x->prov_PMDelete = (struct zx_prov_PMDelete_s*)el;
            break;
          case zx_prov_PMDeleteResponse_ELEM:
            el = (struct zx_elem_s*)zx_DEC_prov_PMDeleteResponse(c, ns);
            el->g.n = &x->prov_PMDeleteResponse->gg.g;
            x->prov_PMDeleteResponse = (struct zx_prov_PMDeleteResponse_s*)el;
            break;
          case zx_prov_Poll_ELEM:
            el = (struct zx_elem_s*)zx_DEC_prov_Poll(c, ns);
            el->g.n = &x->Poll->gg.g;
            x->Poll = (struct zx_prov_Poll_s*)el;
            break;
          case zx_prov_PollResponse_ELEM:
            el = (struct zx_elem_s*)zx_DEC_prov_PollResponse(c, ns);
            el->g.n = &x->PollResponse->gg.g;
            x->PollResponse = (struct zx_prov_PollResponse_s*)el;
            break;
          case zx_prov_UpdateEPR_ELEM:
            el = (struct zx_elem_s*)zx_DEC_prov_UpdateEPR(c, ns);
            el->g.n = &x->UpdateEPR->gg.g;
            x->UpdateEPR = (struct zx_prov_UpdateEPR_s*)el;
            break;
          case zx_prov_UpdateEPRResponse_ELEM:
            el = (struct zx_elem_s*)zx_DEC_prov_UpdateEPRResponse(c, ns);
            el->g.n = &x->UpdateEPRResponse->gg.g;
            x->UpdateEPRResponse = (struct zx_prov_UpdateEPRResponse_s*)el;
            break;
          case zx_idp_GetAssertion_ELEM:
            el = (struct zx_elem_s*)zx_DEC_idp_GetAssertion(c, ns);
            el->g.n = &x->GetAssertion->gg.g;
            x->GetAssertion = (struct zx_idp_GetAssertion_s*)el;
            break;
          case zx_idp_GetAssertionResponse_ELEM:
            el = (struct zx_elem_s*)zx_DEC_idp_GetAssertionResponse(c, ns);
            el->g.n = &x->GetAssertionResponse->gg.g;
            x->GetAssertionResponse = (struct zx_idp_GetAssertionResponse_s*)el;
            break;
          case zx_idp_GetProviderInfo_ELEM:
            el = (struct zx_elem_s*)zx_DEC_idp_GetProviderInfo(c, ns);
            el->g.n = &x->GetProviderInfo->gg.g;
            x->GetProviderInfo = (struct zx_idp_GetProviderInfo_s*)el;
            break;
          case zx_idp_GetProviderInfoResponse_ELEM:
            el = (struct zx_elem_s*)zx_DEC_idp_GetProviderInfoResponse(c, ns);
            el->g.n = &x->GetProviderInfoResponse->gg.g;
            x->GetProviderInfoResponse = (struct zx_idp_GetProviderInfoResponse_s*)el;
            break;
          case zx_idp_CreatedStatus_ELEM:
            el = (struct zx_elem_s*)zx_DEC_idp_CreatedStatus(c, ns);
            el->g.n = &x->CreatedStatus->gg.g;
            x->CreatedStatus = (struct zx_idp_CreatedStatus_s*)el;
            break;
          case zx_idp_CreatedStatusResponse_ELEM:
            el = (struct zx_elem_s*)zx_DEC_idp_CreatedStatusResponse(c, ns);
            el->g.n = &x->CreatedStatusResponse->gg.g;
            x->CreatedStatusResponse = (struct zx_idp_CreatedStatusResponse_s*)el;
            break;
          case zx_shps_Delete_ELEM:
            el = (struct zx_elem_s*)zx_DEC_shps_Delete(c, ns);
            el->g.n = &x->shps_Delete->gg.g;
            x->shps_Delete = (struct zx_shps_Delete_s*)el;
            break;
          case zx_shps_DeleteResponse_ELEM:
            el = (struct zx_elem_s*)zx_DEC_shps_DeleteResponse(c, ns);
            el->g.n = &x->shps_DeleteResponse->gg.g;
            x->shps_DeleteResponse = (struct zx_shps_DeleteResponse_s*)el;
            break;
          case zx_shps_GetStatus_ELEM:
            el = (struct zx_elem_s*)zx_DEC_shps_GetStatus(c, ns);
            el->g.n = &x->GetStatus->gg.g;
            x->GetStatus = (struct zx_shps_GetStatus_s*)el;
            break;
          case zx_shps_GetStatusResponse_ELEM:
            el = (struct zx_elem_s*)zx_DEC_shps_GetStatusResponse(c, ns);
            el->g.n = &x->GetStatusResponse->gg.g;
            x->GetStatusResponse = (struct zx_shps_GetStatusResponse_s*)el;
            break;
          case zx_shps_Query_ELEM:
            el = (struct zx_elem_s*)zx_DEC_shps_Query(c, ns);
            el->g.n = &x->shps_Query->gg.g;
            x->shps_Query = (struct zx_shps_Query_s*)el;
            break;
          case zx_shps_QueryResponse_ELEM:
            el = (struct zx_elem_s*)zx_DEC_shps_QueryResponse(c, ns);
            el->g.n = &x->shps_QueryResponse->gg.g;
            x->shps_QueryResponse = (struct zx_shps_QueryResponse_s*)el;
            break;
          case zx_shps_Invoke_ELEM:
            el = zx_DEC_simple_elem(c, ns, tok);
            el->g.n = &x->Invoke->g;
            x->Invoke = el;
            break;
          case zx_shps_InvokeResponse_ELEM:
            el = (struct zx_elem_s*)zx_DEC_shps_InvokeResponse(c, ns);
            el->g.n = &x->InvokeResponse->gg.g;
            x->InvokeResponse = (struct zx_shps_InvokeResponse_s*)el;
            break;
          case zx_shps_QueryRegistered_ELEM:
            el = (struct zx_elem_s*)zx_DEC_shps_QueryRegistered(c, ns);
            el->g.n = &x->QueryRegistered->gg.g;
            x->QueryRegistered = (struct zx_shps_QueryRegistered_s*)el;
            break;
          case zx_shps_QueryRegisteredResponse_ELEM:
            el = (struct zx_elem_s*)zx_DEC_shps_QueryRegisteredResponse(c, ns);
            el->g.n = &x->QueryRegisteredResponse->gg.g;
            x->QueryRegisteredResponse = (struct zx_shps_QueryRegisteredResponse_s*)el;
            break;
          case zx_shps_Register_ELEM:
            el = (struct zx_elem_s*)zx_DEC_shps_Register(c, ns);
            el->g.n = &x->Register->gg.g;
            x->Register = (struct zx_shps_Register_s*)el;
            break;
          case zx_shps_RegisterResponse_ELEM:
            el = (struct zx_elem_s*)zx_DEC_shps_RegisterResponse(c, ns);
            el->g.n = &x->RegisterResponse->gg.g;
            x->RegisterResponse = (struct zx_shps_RegisterResponse_s*)el;
            break;
          case zx_shps_SetStatus_ELEM:
            el = (struct zx_elem_s*)zx_DEC_shps_SetStatus(c, ns);
            el->g.n = &x->SetStatus->gg.g;
            x->SetStatus = (struct zx_shps_SetStatus_s*)el;
            break;
          case zx_shps_SetStatusResponse_ELEM:
            el = (struct zx_elem_s*)zx_DEC_shps_SetStatusResponse(c, ns);
            el->g.n = &x->SetStatusResponse->gg.g;
            x->SetStatusResponse = (struct zx_shps_SetStatusResponse_s*)el;
            break;
          case zx_shps_Update_ELEM:
            el = (struct zx_elem_s*)zx_DEC_shps_Update(c, ns);
            el->g.n = &x->Update->gg.g;
            x->Update = (struct zx_shps_Update_s*)el;
            break;
          case zx_shps_UpdateResponse_ELEM:
            el = (struct zx_elem_s*)zx_DEC_shps_UpdateResponse(c, ns);
            el->g.n = &x->UpdateResponse->gg.g;
            x->UpdateResponse = (struct zx_shps_UpdateResponse_s*)el;
            break;
          case zx_shps_Poll_ELEM:
            el = (struct zx_elem_s*)zx_DEC_shps_Poll(c, ns);
            el->g.n = &x->shps_Poll->gg.g;
            x->shps_Poll = (struct zx_shps_Poll_s*)el;
            break;
          case zx_shps_PollResponse_ELEM:
            el = (struct zx_elem_s*)zx_DEC_shps_PollResponse(c, ns);
            el->g.n = &x->shps_PollResponse->gg.g;
            x->shps_PollResponse = (struct zx_shps_PollResponse_s*)el;
            break;
          case zx_shps_ProxyInvoke_ELEM:
            el = (struct zx_elem_s*)zx_DEC_shps_ProxyInvoke(c, ns);
            el->g.n = &x->ProxyInvoke->gg.g;
            x->ProxyInvoke = (struct zx_shps_ProxyInvoke_s*)el;
            break;
          case zx_shps_ProxyInvokeResponse_ELEM:
            el = (struct zx_elem_s*)zx_DEC_shps_ProxyInvokeResponse(c, ns);
            el->g.n = &x->ProxyInvokeResponse->gg.g;
            x->ProxyInvokeResponse = (struct zx_shps_ProxyInvokeResponse_s*)el;
            break;
          case zx_idhrxml_Create_ELEM:
            el = (struct zx_elem_s*)zx_DEC_idhrxml_Create(c, ns);
            el->g.n = &x->idhrxml_Create->gg.g;
            x->idhrxml_Create = (struct zx_idhrxml_Create_s*)el;
            break;
          case zx_idhrxml_CreateResponse_ELEM:
            el = (struct zx_elem_s*)zx_DEC_idhrxml_CreateResponse(c, ns);
            el->g.n = &x->idhrxml_CreateResponse->gg.g;
            x->idhrxml_CreateResponse = (struct zx_idhrxml_CreateResponse_s*)el;
            break;
          case zx_idhrxml_Query_ELEM:
            el = (struct zx_elem_s*)zx_DEC_idhrxml_Query(c, ns);
            el->g.n = &x->idhrxml_Query->gg.g;
            x->idhrxml_Query = (struct zx_idhrxml_Query_s*)el;
            break;
          case zx_idhrxml_QueryResponse_ELEM:
            el = (struct zx_elem_s*)zx_DEC_idhrxml_QueryResponse(c, ns);
            el->g.n = &x->idhrxml_QueryResponse->gg.g;
            x->idhrxml_QueryResponse = (struct zx_idhrxml_QueryResponse_s*)el;
            break;
          case zx_idhrxml_Modify_ELEM:
            el = (struct zx_elem_s*)zx_DEC_idhrxml_Modify(c, ns);
            el->g.n = &x->idhrxml_Modify->gg.g;
            x->idhrxml_Modify = (struct zx_idhrxml_Modify_s*)el;
            break;
          case zx_idhrxml_ModifyResponse_ELEM:
            el = (struct zx_elem_s*)zx_DEC_idhrxml_ModifyResponse(c, ns);
            el->g.n = &x->idhrxml_ModifyResponse->gg.g;
            x->idhrxml_ModifyResponse = (struct zx_idhrxml_ModifyResponse_s*)el;
            break;
          case zx_idhrxml_Delete_ELEM:
            el = (struct zx_elem_s*)zx_DEC_idhrxml_Delete(c, ns);
            el->g.n = &x->idhrxml_Delete->gg.g;
            x->idhrxml_Delete = (struct zx_idhrxml_Delete_s*)el;
            break;
          case zx_idhrxml_DeleteResponse_ELEM:
            el = (struct zx_elem_s*)zx_DEC_idhrxml_DeleteResponse(c, ns);
            el->g.n = &x->idhrxml_DeleteResponse->gg.g;
            x->idhrxml_DeleteResponse = (struct zx_idhrxml_DeleteResponse_s*)el;
            break;
          case zx_idhrxml_Notify_ELEM:
            el = (struct zx_elem_s*)zx_DEC_idhrxml_Notify(c, ns);
            el->g.n = &x->idhrxml_Notify->gg.g;
            x->idhrxml_Notify = (struct zx_idhrxml_Notify_s*)el;
            break;
          case zx_idhrxml_NotifyResponse_ELEM:
            el = (struct zx_elem_s*)zx_DEC_idhrxml_NotifyResponse(c, ns);
            el->g.n = &x->idhrxml_NotifyResponse->gg.g;
            x->idhrxml_NotifyResponse = (struct zx_idhrxml_NotifyResponse_s*)el;
            break;

	  default:
	    el = zx_known_or_unknown_elem(c, tok, &x->gg, c->p - name, name, ns);
	    tok = ZX_TOK_NOT_FOUND;
	    break;
	  }
          el->g.wo = &x->gg.kids->g;
          x->gg.kids = el;
	  zx_pop_seen(pop_seen);
	  
	  goto next_elem;
	}
      }
      /* false alarm <, fall thru */
    }
    if (!zx_scan_data(c, &x->gg))
      return x;
    goto potential_tag;
  }
 out:
  zx_dec_reverse_lists(&x->gg);
  ZX_END_DEC_EXT(x);
  return x;

 look_for_not_found:
  zx_xml_parse_err(c, '>', (const char*)__FUNCTION__, "char not found");
  return x;
}

#undef EL_NAME
#undef EL_STRUCT
#undef EL_NS
#undef EL_TAG






/* FUNC(zx_DEC_e_Envelope) */

#define EL_NAME   e_Envelope
#define EL_STRUCT zx_e_Envelope_s
#define EL_NS     e
#define EL_TAG    Envelope

/* Called by: */
struct zx_e_Envelope_s* zx_DEC_e_Envelope(struct zx_ctx* c, struct zx_ns_s* ns )
{
  int tok;
  struct zx_elem_s* el;
  struct zx_str* ss;
  struct zx_ns_s* pop_seen;
  const char* name;
  const char* data;
  struct zx_e_Envelope_s* x = ZX_ZALLOC(c, struct zx_e_Envelope_s);
  x->gg.g.tok = zx_e_Envelope_ELEM;
  x->gg.g.ns = ns;
  ZX_START_DEC_EXT(x);

#if 1 /* NORMALMODE */
  ZX_DEC_TAG_NOT_YET_CLOSED(x->gg.g);

  /* The tag name has already been detected. Process attributes until '>' */
  
  for (; c->p; ++c->p) {
    ZX_SKIP_WS(c,x);
    if (ONE_OF_2(*c->p, '>', '/'))
      break;
    if (!(data = zx_dec_attr_val(c, &name, (const char*)__FUNCTION__)))
      return x;
    tok = zx_attr_lookup(c, name, data-2, &ns);
    switch (tok) {
    case zx_id_ATTR:
      ss = ZX_ZALLOC(c, struct zx_str);
      ss->g.n = &x->id->g;
      x->id = ss;
      ZX_ATTR_DEC_EXT(ss);
      break;

    case ZX_TOK_XMLNS:
      ZX_XMLNS_DEC_EXT(name);
      DD("xmlns detected(%.*s)", data-2-name, name);
      ns = zx_new_ns(c, data-2-name, name, c->p - data, data);
      ns->n = x->gg.xmlns;
      x->gg.xmlns = ns;
      goto next_attr;
    default:
      ss = zx_dec_unknown_attr(c, &x->gg, name, data, tok, x->gg.g.tok);
    }
    ss->g.ns = ns;    /* Fill in the rest of the ss fields (its already linked to right list). */
    ss->g.tok = tok;
    ss->g.err |= ZXERR_ATTR_FLAG;
    ss->len = c->p - data;
    ss->s = (char*)data;
next_attr:
    continue;
  }
  if (c->p) {
    ++c->p;
    if (c->p[-1] == '/' && c->p[0] == '>') {  /* Tag without content */
      ++c->p;
      ZX_DEC_TAG_NOW_CLOSED(x->gg.g);
      goto out;
    }
  }
#endif

  /* Process contents until '</' */
  
  ZX_START_BODY_DEC_EXT(x);
  
  while (c->p) {
  next_elem:
    /*ZX_SKIP_WS(c,x);    DO NOT SQUASH WS! EXC-CANON NEEDS IT. */
    if (*c->p == '<') {
    potential_tag:
      ++c->p;
      switch (*c->p) {
      case '?':  /* processing instruction <?xml ... ?> */
      case '!':  /* comment <!-- ... --> */
	if (zx_scan_pi_or_comment(c))
	  break;
	goto next_elem;
      case '/':  /* close tag */
	++c->p;
	name = c->p;
	ZX_LOOK_FOR(c,'>');
#if defined(DEC_WRONG_ELEM)
	if (x->gg.g.ns->prefix_len
	    ?(c->p - name - x->gg.g.ns->prefix_len - 1 != namlen || memcmp(name+x->gg.g.ns->prefix_len+1, nam, namlen))
	    :(c->p-name != namlen || memcmp(name, nam, namlen)))
#else
	tok = zx_elem_lookup(c, name, c->p, &ns);
	if (tok != x->gg.g.tok)
#endif
	{
	  zx_xml_parse_err_mismatching_close_tag(c, (const char*)__FUNCTION__, name, tok);
	  ZX_DEC_TAG_MISMATCH_CLOSE(x->gg.g);
	  return x;
	}
	/* Legitimate close tag. Normal exit from this function. */
	++c->p;
	ZX_DEC_TAG_NOW_CLOSED(x->gg.g);
	goto out;
      default:
	if (A_Z_a_z_(*c->p)) {
	  if (!(name = zx_scan_elem_start(c, (const char*)__FUNCTION__)))
	    return x;
	  pop_seen = zx_scan_xmlns(c);  /* Prescan namespaces so that token can be correctly recognized. */
	  tok = zx_elem_lookup(c, name, c->p, &ns);
	  switch (tok) {
          case zx_e_Header_ELEM:
            el = (struct zx_elem_s*)zx_DEC_e_Header(c, ns);
            el->g.n = &x->Header->gg.g;
            x->Header = (struct zx_e_Header_s*)el;
            break;
          case zx_e_Body_ELEM:
            el = (struct zx_elem_s*)zx_DEC_e_Body(c, ns);
            el->g.n = &x->Body->gg.g;
            x->Body = (struct zx_e_Body_s*)el;
            break;

	  default:
	    el = zx_known_or_unknown_elem(c, tok, &x->gg, c->p - name, name, ns);
	    tok = ZX_TOK_NOT_FOUND;
	    break;
	  }
          el->g.wo = &x->gg.kids->g;
          x->gg.kids = el;
	  zx_pop_seen(pop_seen);
	  
	  goto next_elem;
	}
      }
      /* false alarm <, fall thru */
    }
    if (!zx_scan_data(c, &x->gg))
      return x;
    goto potential_tag;
  }
 out:
  zx_dec_reverse_lists(&x->gg);
  ZX_END_DEC_EXT(x);
  return x;

 look_for_not_found:
  zx_xml_parse_err(c, '>', (const char*)__FUNCTION__, "char not found");
  return x;
}

#undef EL_NAME
#undef EL_STRUCT
#undef EL_NS
#undef EL_TAG






/* FUNC(zx_DEC_e_Fault) */

#define EL_NAME   e_Fault
#define EL_STRUCT zx_e_Fault_s
#define EL_NS     e
#define EL_TAG    Fault

/* Called by: */
struct zx_e_Fault_s* zx_DEC_e_Fault(struct zx_ctx* c, struct zx_ns_s* ns )
{
  int tok;
  struct zx_elem_s* el;
  struct zx_str* ss;
  struct zx_ns_s* pop_seen;
  const char* name;
  const char* data;
  struct zx_e_Fault_s* x = ZX_ZALLOC(c, struct zx_e_Fault_s);
  x->gg.g.tok = zx_e_Fault_ELEM;
  x->gg.g.ns = ns;
  ZX_START_DEC_EXT(x);

#if 1 /* NORMALMODE */
  ZX_DEC_TAG_NOT_YET_CLOSED(x->gg.g);

  /* The tag name has already been detected. Process attributes until '>' */
  
  for (; c->p; ++c->p) {
    ZX_SKIP_WS(c,x);
    if (ONE_OF_2(*c->p, '>', '/'))
      break;
    if (!(data = zx_dec_attr_val(c, &name, (const char*)__FUNCTION__)))
      return x;
    tok = zx_attr_lookup(c, name, data-2, &ns);
    switch (tok) {

    case ZX_TOK_XMLNS:
      ZX_XMLNS_DEC_EXT(name);
      DD("xmlns detected(%.*s)", data-2-name, name);
      ns = zx_new_ns(c, data-2-name, name, c->p - data, data);
      ns->n = x->gg.xmlns;
      x->gg.xmlns = ns;
      goto next_attr;
    default:
      ss = zx_dec_unknown_attr(c, &x->gg, name, data, tok, x->gg.g.tok);
    }
    ss->g.ns = ns;    /* Fill in the rest of the ss fields (its already linked to right list). */
    ss->g.tok = tok;
    ss->g.err |= ZXERR_ATTR_FLAG;
    ss->len = c->p - data;
    ss->s = (char*)data;
next_attr:
    continue;
  }
  if (c->p) {
    ++c->p;
    if (c->p[-1] == '/' && c->p[0] == '>') {  /* Tag without content */
      ++c->p;
      ZX_DEC_TAG_NOW_CLOSED(x->gg.g);
      goto out;
    }
  }
#endif

  /* Process contents until '</' */
  
  ZX_START_BODY_DEC_EXT(x);
  
  while (c->p) {
  next_elem:
    /*ZX_SKIP_WS(c,x);    DO NOT SQUASH WS! EXC-CANON NEEDS IT. */
    if (*c->p == '<') {
    potential_tag:
      ++c->p;
      switch (*c->p) {
      case '?':  /* processing instruction <?xml ... ?> */
      case '!':  /* comment <!-- ... --> */
	if (zx_scan_pi_or_comment(c))
	  break;
	goto next_elem;
      case '/':  /* close tag */
	++c->p;
	name = c->p;
	ZX_LOOK_FOR(c,'>');
#if defined(DEC_WRONG_ELEM)
	if (x->gg.g.ns->prefix_len
	    ?(c->p - name - x->gg.g.ns->prefix_len - 1 != namlen || memcmp(name+x->gg.g.ns->prefix_len+1, nam, namlen))
	    :(c->p-name != namlen || memcmp(name, nam, namlen)))
#else
	tok = zx_elem_lookup(c, name, c->p, &ns);
	if (tok != x->gg.g.tok)
#endif
	{
	  zx_xml_parse_err_mismatching_close_tag(c, (const char*)__FUNCTION__, name, tok);
	  ZX_DEC_TAG_MISMATCH_CLOSE(x->gg.g);
	  return x;
	}
	/* Legitimate close tag. Normal exit from this function. */
	++c->p;
	ZX_DEC_TAG_NOW_CLOSED(x->gg.g);
	goto out;
      default:
	if (A_Z_a_z_(*c->p)) {
	  if (!(name = zx_scan_elem_start(c, (const char*)__FUNCTION__)))
	    return x;
	  pop_seen = zx_scan_xmlns(c);  /* Prescan namespaces so that token can be correctly recognized. */
	  tok = zx_elem_lookup(c, name, c->p, &ns);
	  switch (tok) {
          case zx_e_faultcode_ELEM:
            el = zx_DEC_simple_elem(c, ns, tok);
            el->g.n = &x->faultcode->g;
            x->faultcode = el;
            break;
          case zx_e_faultstring_ELEM:
            el = zx_DEC_simple_elem(c, ns, tok);
            el->g.n = &x->faultstring->g;
            x->faultstring = el;
            break;
          case zx_e_faultactor_ELEM:
            el = zx_DEC_simple_elem(c, ns, tok);
            el->g.n = &x->faultactor->g;
            x->faultactor = el;
            break;
          case zx_e_detail_ELEM:
            el = (struct zx_elem_s*)zx_DEC_e_detail(c, ns);
            el->g.n = &x->detail->gg.g;
            x->detail = (struct zx_e_detail_s*)el;
            break;

	  default:
	    el = zx_known_or_unknown_elem(c, tok, &x->gg, c->p - name, name, ns);
	    tok = ZX_TOK_NOT_FOUND;
	    break;
	  }
          el->g.wo = &x->gg.kids->g;
          x->gg.kids = el;
	  zx_pop_seen(pop_seen);
	  
	  goto next_elem;
	}
      }
      /* false alarm <, fall thru */
    }
    if (!zx_scan_data(c, &x->gg))
      return x;
    goto potential_tag;
  }
 out:
  zx_dec_reverse_lists(&x->gg);
  ZX_END_DEC_EXT(x);
  return x;

 look_for_not_found:
  zx_xml_parse_err(c, '>', (const char*)__FUNCTION__, "char not found");
  return x;
}

#undef EL_NAME
#undef EL_STRUCT
#undef EL_NS
#undef EL_TAG






/* FUNC(zx_DEC_e_Header) */

#define EL_NAME   e_Header
#define EL_STRUCT zx_e_Header_s
#define EL_NS     e
#define EL_TAG    Header

/* Called by: */
struct zx_e_Header_s* zx_DEC_e_Header(struct zx_ctx* c, struct zx_ns_s* ns )
{
  int tok;
  struct zx_elem_s* el;
  struct zx_str* ss;
  struct zx_ns_s* pop_seen;
  const char* name;
  const char* data;
  struct zx_e_Header_s* x = ZX_ZALLOC(c, struct zx_e_Header_s);
  x->gg.g.tok = zx_e_Header_ELEM;
  x->gg.g.ns = ns;
  ZX_START_DEC_EXT(x);

#if 1 /* NORMALMODE */
  ZX_DEC_TAG_NOT_YET_CLOSED(x->gg.g);

  /* The tag name has already been detected. Process attributes until '>' */
  
  for (; c->p; ++c->p) {
    ZX_SKIP_WS(c,x);
    if (ONE_OF_2(*c->p, '>', '/'))
      break;
    if (!(data = zx_dec_attr_val(c, &name, (const char*)__FUNCTION__)))
      return x;
    tok = zx_attr_lookup(c, name, data-2, &ns);
    switch (tok) {
    case zx_id_ATTR:
      ss = ZX_ZALLOC(c, struct zx_str);
      ss->g.n = &x->id->g;
      x->id = ss;
      ZX_ATTR_DEC_EXT(ss);
      break;

    case ZX_TOK_XMLNS:
      ZX_XMLNS_DEC_EXT(name);
      DD("xmlns detected(%.*s)", data-2-name, name);
      ns = zx_new_ns(c, data-2-name, name, c->p - data, data);
      ns->n = x->gg.xmlns;
      x->gg.xmlns = ns;
      goto next_attr;
    default:
      ss = zx_dec_unknown_attr(c, &x->gg, name, data, tok, x->gg.g.tok);
    }
    ss->g.ns = ns;    /* Fill in the rest of the ss fields (its already linked to right list). */
    ss->g.tok = tok;
    ss->g.err |= ZXERR_ATTR_FLAG;
    ss->len = c->p - data;
    ss->s = (char*)data;
next_attr:
    continue;
  }
  if (c->p) {
    ++c->p;
    if (c->p[-1] == '/' && c->p[0] == '>') {  /* Tag without content */
      ++c->p;
      ZX_DEC_TAG_NOW_CLOSED(x->gg.g);
      goto out;
    }
  }
#endif

  /* Process contents until '</' */
  
  ZX_START_BODY_DEC_EXT(x);
  
  while (c->p) {
  next_elem:
    /*ZX_SKIP_WS(c,x);    DO NOT SQUASH WS! EXC-CANON NEEDS IT. */
    if (*c->p == '<') {
    potential_tag:
      ++c->p;
      switch (*c->p) {
      case '?':  /* processing instruction <?xml ... ?> */
      case '!':  /* comment <!-- ... --> */
	if (zx_scan_pi_or_comment(c))
	  break;
	goto next_elem;
      case '/':  /* close tag */
	++c->p;
	name = c->p;
	ZX_LOOK_FOR(c,'>');
#if defined(DEC_WRONG_ELEM)
	if (x->gg.g.ns->prefix_len
	    ?(c->p - name - x->gg.g.ns->prefix_len - 1 != namlen || memcmp(name+x->gg.g.ns->prefix_len+1, nam, namlen))
	    :(c->p-name != namlen || memcmp(name, nam, namlen)))
#else
	tok = zx_elem_lookup(c, name, c->p, &ns);
	if (tok != x->gg.g.tok)
#endif
	{
	  zx_xml_parse_err_mismatching_close_tag(c, (const char*)__FUNCTION__, name, tok);
	  ZX_DEC_TAG_MISMATCH_CLOSE(x->gg.g);
	  return x;
	}
	/* Legitimate close tag. Normal exit from this function. */
	++c->p;
	ZX_DEC_TAG_NOW_CLOSED(x->gg.g);
	goto out;
      default:
	if (A_Z_a_z_(*c->p)) {
	  if (!(name = zx_scan_elem_start(c, (const char*)__FUNCTION__)))
	    return x;
	  pop_seen = zx_scan_xmlns(c);  /* Prescan namespaces so that token can be correctly recognized. */
	  tok = zx_elem_lookup(c, name, c->p, &ns);
	  switch (tok) {
          case zx_paos_Request_ELEM:
            el = (struct zx_elem_s*)zx_DEC_paos_Request(c, ns);
            el->g.n = &x->Request->gg.g;
            x->Request = (struct zx_paos_Request_s*)el;
            break;
          case zx_paos_Response_ELEM:
            el = (struct zx_elem_s*)zx_DEC_paos_Response(c, ns);
            el->g.n = &x->Response->gg.g;
            x->Response = (struct zx_paos_Response_s*)el;
            break;
          case zx_ecp_Request_ELEM:
            el = (struct zx_elem_s*)zx_DEC_ecp_Request(c, ns);
            el->g.n = &x->ecp_Request->gg.g;
            x->ecp_Request = (struct zx_ecp_Request_s*)el;
            break;
          case zx_ecp_Response_ELEM:
            el = (struct zx_elem_s*)zx_DEC_ecp_Response(c, ns);
            el->g.n = &x->ecp_Response->gg.g;
            x->ecp_Response = (struct zx_ecp_Response_s*)el;
            break;
          case zx_ecp_RelayState_ELEM:
            el = (struct zx_elem_s*)zx_DEC_ecp_RelayState(c, ns);
            el->g.n = &x->RelayState->gg.g;
            x->RelayState = (struct zx_ecp_RelayState_s*)el;
            break;
          case zx_a_MessageID_ELEM:
            el = (struct zx_elem_s*)zx_DEC_a_MessageID(c, ns);
            el->g.n = &x->MessageID->gg.g;
            x->MessageID = (struct zx_a_MessageID_s*)el;
            break;
          case zx_a_RelatesTo_ELEM:
            el = (struct zx_elem_s*)zx_DEC_a_RelatesTo(c, ns);
            el->g.n = &x->RelatesTo->gg.g;
            x->RelatesTo = (struct zx_a_RelatesTo_s*)el;
            break;
          case zx_a_ReplyTo_ELEM:
            el = (struct zx_elem_s*)zx_DEC_a_ReplyTo(c, ns);
            el->g.n = &x->ReplyTo->gg.g;
            x->ReplyTo = (struct zx_a_ReplyTo_s*)el;
            break;
          case zx_a_From_ELEM:
            el = (struct zx_elem_s*)zx_DEC_a_From(c, ns);
            el->g.n = &x->From->gg.g;
            x->From = (struct zx_a_From_s*)el;
            break;
          case zx_a_FaultTo_ELEM:
            el = (struct zx_elem_s*)zx_DEC_a_FaultTo(c, ns);
            el->g.n = &x->FaultTo->gg.g;
            x->FaultTo = (struct zx_a_FaultTo_s*)el;
            break;
          case zx_a_To_ELEM:
            el = (struct zx_elem_s*)zx_DEC_a_To(c, ns);
            el->g.n = &x->To->gg.g;
            x->To = (struct zx_a_To_s*)el;
            break;
          case zx_a_Action_ELEM:
            el = (struct zx_elem_s*)zx_DEC_a_Action(c, ns);
            el->g.n = &x->Action->gg.g;
            x->Action = (struct zx_a_Action_s*)el;
            break;
          case zx_a_ReferenceParameters_ELEM:
            el = (struct zx_elem_s*)zx_DEC_a_ReferenceParameters(c, ns);
            el->g.n = &x->ReferenceParameters->gg.g;
            x->ReferenceParameters = (struct zx_a_ReferenceParameters_s*)el;
            break;
          case zx_sbf_Framework_ELEM:
            el = (struct zx_elem_s*)zx_DEC_sbf_Framework(c, ns);
            el->g.n = &x->Framework->gg.g;
            x->Framework = (struct zx_sbf_Framework_s*)el;
            break;
          case zx_b_Framework_ELEM:
            el = (struct zx_elem_s*)zx_DEC_b_Framework(c, ns);
            el->g.n = &x->b_Framework->gg.g;
            x->b_Framework = (struct zx_b_Framework_s*)el;
            break;
          case zx_b_Sender_ELEM:
            el = (struct zx_elem_s*)zx_DEC_b_Sender(c, ns);
            el->g.n = &x->Sender->gg.g;
            x->Sender = (struct zx_b_Sender_s*)el;
            break;
          case zx_b_TargetIdentity_ELEM:
            el = (struct zx_elem_s*)zx_DEC_b_TargetIdentity(c, ns);
            el->g.n = &x->TargetIdentity->gg.g;
            x->TargetIdentity = (struct zx_b_TargetIdentity_s*)el;
            break;
          case zx_b_CredentialsContext_ELEM:
            el = (struct zx_elem_s*)zx_DEC_b_CredentialsContext(c, ns);
            el->g.n = &x->CredentialsContext->gg.g;
            x->CredentialsContext = (struct zx_b_CredentialsContext_s*)el;
            break;
          case zx_b_EndpointUpdate_ELEM:
            el = (struct zx_elem_s*)zx_DEC_b_EndpointUpdate(c, ns);
            el->g.n = &x->EndpointUpdate->gg.g;
            x->EndpointUpdate = (struct zx_b_EndpointUpdate_s*)el;
            break;
          case zx_b_Timeout_ELEM:
            el = (struct zx_elem_s*)zx_DEC_b_Timeout(c, ns);
            el->g.n = &x->Timeout->gg.g;
            x->Timeout = (struct zx_b_Timeout_s*)el;
            break;
          case zx_b_ProcessingContext_ELEM:
            el = (struct zx_elem_s*)zx_DEC_b_ProcessingContext(c, ns);
            el->g.n = &x->ProcessingContext->gg.g;
            x->ProcessingContext = (struct zx_b_ProcessingContext_s*)el;
            break;
          case zx_b_Consent_ELEM:
            el = (struct zx_elem_s*)zx_DEC_b_Consent(c, ns);
            el->g.n = &x->Consent->gg.g;
            x->Consent = (struct zx_b_Consent_s*)el;
            break;
          case zx_b_UsageDirective_ELEM:
            el = (struct zx_elem_s*)zx_DEC_b_UsageDirective(c, ns);
            el->g.n = &x->UsageDirective->gg.g;
            x->UsageDirective = (struct zx_b_UsageDirective_s*)el;
            break;
          case zx_b_ApplicationEPR_ELEM:
            el = (struct zx_elem_s*)zx_DEC_b_ApplicationEPR(c, ns);
            el->g.n = &x->ApplicationEPR->gg.g;
            x->ApplicationEPR = (struct zx_b_ApplicationEPR_s*)el;
            break;
          case zx_b_UserInteraction_ELEM:
            el = (struct zx_elem_s*)zx_DEC_b_UserInteraction(c, ns);
            el->g.n = &x->UserInteraction->gg.g;
            x->UserInteraction = (struct zx_b_UserInteraction_s*)el;
            break;
          case zx_b_RedirectRequest_ELEM:
            el = (struct zx_elem_s*)zx_DEC_b_RedirectRequest(c, ns);
            el->g.n = &x->RedirectRequest->gg.g;
            x->RedirectRequest = (struct zx_b_RedirectRequest_s*)el;
            break;
          case zx_b12_Correlation_ELEM:
            el = (struct zx_elem_s*)zx_DEC_b12_Correlation(c, ns);
            el->g.n = &x->Correlation->gg.g;
            x->Correlation = (struct zx_b12_Correlation_s*)el;
            break;
          case zx_b12_Provider_ELEM:
            el = (struct zx_elem_s*)zx_DEC_b12_Provider(c, ns);
            el->g.n = &x->Provider->gg.g;
            x->Provider = (struct zx_b12_Provider_s*)el;
            break;
          case zx_b12_ProcessingContext_ELEM:
            el = (struct zx_elem_s*)zx_DEC_b12_ProcessingContext(c, ns);
            el->g.n = &x->b12_ProcessingContext->gg.g;
            x->b12_ProcessingContext = (struct zx_b12_ProcessingContext_s*)el;
            break;
          case zx_b12_Consent_ELEM:
            el = (struct zx_elem_s*)zx_DEC_b12_Consent(c, ns);
            el->g.n = &x->b12_Consent->gg.g;
            x->b12_Consent = (struct zx_b12_Consent_s*)el;
            break;
          case zx_b12_UsageDirective_ELEM:
            el = (struct zx_elem_s*)zx_DEC_b12_UsageDirective(c, ns);
            el->g.n = &x->b12_UsageDirective->gg.g;
            x->b12_UsageDirective = (struct zx_b12_UsageDirective_s*)el;
            break;
          case zx_mm7_TransactionID_ELEM:
            el = (struct zx_elem_s*)zx_DEC_mm7_TransactionID(c, ns);
            el->g.n = &x->TransactionID->gg.g;
            x->TransactionID = (struct zx_mm7_TransactionID_s*)el;
            break;
          case zx_wsse_Security_ELEM:
            el = (struct zx_elem_s*)zx_DEC_wsse_Security(c, ns);
            el->g.n = &x->Security->gg.g;
            x->Security = (struct zx_wsse_Security_s*)el;
            break;
          case zx_tas3_Status_ELEM:
            el = (struct zx_elem_s*)zx_DEC_tas3_Status(c, ns);
            el->g.n = &x->Status->gg.g;
            x->Status = (struct zx_tas3_Status_s*)el;
            break;
          case zx_tas3_Credentials_ELEM:
            el = (struct zx_elem_s*)zx_DEC_tas3_Credentials(c, ns);
            el->g.n = &x->Credentials->gg.g;
            x->Credentials = (struct zx_tas3_Credentials_s*)el;
            break;
          case zx_tas3_ESLPolicies_ELEM:
            el = (struct zx_elem_s*)zx_DEC_tas3_ESLPolicies(c, ns);
            el->g.n = &x->ESLPolicies->gg.g;
            x->ESLPolicies = (struct zx_tas3_ESLPolicies_s*)el;
            break;

	  default:
	    el = zx_known_or_unknown_elem(c, tok, &x->gg, c->p - name, name, ns);
	    tok = ZX_TOK_NOT_FOUND;
	    break;
	  }
          el->g.wo = &x->gg.kids->g;
          x->gg.kids = el;
	  zx_pop_seen(pop_seen);
	  
	  goto next_elem;
	}
      }
      /* false alarm <, fall thru */
    }
    if (!zx_scan_data(c, &x->gg))
      return x;
    goto potential_tag;
  }
 out:
  zx_dec_reverse_lists(&x->gg);
  ZX_END_DEC_EXT(x);
  return x;

 look_for_not_found:
  zx_xml_parse_err(c, '>', (const char*)__FUNCTION__, "char not found");
  return x;
}

#undef EL_NAME
#undef EL_STRUCT
#undef EL_NS
#undef EL_TAG






/* FUNC(zx_DEC_e_detail) */

#define EL_NAME   e_detail
#define EL_STRUCT zx_e_detail_s
#define EL_NS     e
#define EL_TAG    detail

/* Called by: */
struct zx_e_detail_s* zx_DEC_e_detail(struct zx_ctx* c, struct zx_ns_s* ns )
{
  int tok;
  struct zx_elem_s* el;
  struct zx_str* ss;
  struct zx_ns_s* pop_seen;
  const char* name;
  const char* data;
  struct zx_e_detail_s* x = ZX_ZALLOC(c, struct zx_e_detail_s);
  x->gg.g.tok = zx_e_detail_ELEM;
  x->gg.g.ns = ns;
  ZX_START_DEC_EXT(x);

#if 1 /* NORMALMODE */
  ZX_DEC_TAG_NOT_YET_CLOSED(x->gg.g);

  /* The tag name has already been detected. Process attributes until '>' */
  
  for (; c->p; ++c->p) {
    ZX_SKIP_WS(c,x);
    if (ONE_OF_2(*c->p, '>', '/'))
      break;
    if (!(data = zx_dec_attr_val(c, &name, (const char*)__FUNCTION__)))
      return x;
    tok = zx_attr_lookup(c, name, data-2, &ns);
    switch (tok) {

    case ZX_TOK_XMLNS:
      ZX_XMLNS_DEC_EXT(name);
      DD("xmlns detected(%.*s)", data-2-name, name);
      ns = zx_new_ns(c, data-2-name, name, c->p - data, data);
      ns->n = x->gg.xmlns;
      x->gg.xmlns = ns;
      goto next_attr;
    default:
      ss = zx_dec_unknown_attr(c, &x->gg, name, data, tok, x->gg.g.tok);
    }
    ss->g.ns = ns;    /* Fill in the rest of the ss fields (its already linked to right list). */
    ss->g.tok = tok;
    ss->g.err |= ZXERR_ATTR_FLAG;
    ss->len = c->p - data;
    ss->s = (char*)data;
next_attr:
    continue;
  }
  if (c->p) {
    ++c->p;
    if (c->p[-1] == '/' && c->p[0] == '>') {  /* Tag without content */
      ++c->p;
      ZX_DEC_TAG_NOW_CLOSED(x->gg.g);
      goto out;
    }
  }
#endif

  /* Process contents until '</' */
  
  ZX_START_BODY_DEC_EXT(x);
  
  while (c->p) {
  next_elem:
    /*ZX_SKIP_WS(c,x);    DO NOT SQUASH WS! EXC-CANON NEEDS IT. */
    if (*c->p == '<') {
    potential_tag:
      ++c->p;
      switch (*c->p) {
      case '?':  /* processing instruction <?xml ... ?> */
      case '!':  /* comment <!-- ... --> */
	if (zx_scan_pi_or_comment(c))
	  break;
	goto next_elem;
      case '/':  /* close tag */
	++c->p;
	name = c->p;
	ZX_LOOK_FOR(c,'>');
#if defined(DEC_WRONG_ELEM)
	if (x->gg.g.ns->prefix_len
	    ?(c->p - name - x->gg.g.ns->prefix_len - 1 != namlen || memcmp(name+x->gg.g.ns->prefix_len+1, nam, namlen))
	    :(c->p-name != namlen || memcmp(name, nam, namlen)))
#else
	tok = zx_elem_lookup(c, name, c->p, &ns);
	if (tok != x->gg.g.tok)
#endif
	{
	  zx_xml_parse_err_mismatching_close_tag(c, (const char*)__FUNCTION__, name, tok);
	  ZX_DEC_TAG_MISMATCH_CLOSE(x->gg.g);
	  return x;
	}
	/* Legitimate close tag. Normal exit from this function. */
	++c->p;
	ZX_DEC_TAG_NOW_CLOSED(x->gg.g);
	goto out;
      default:
	if (A_Z_a_z_(*c->p)) {
	  if (!(name = zx_scan_elem_start(c, (const char*)__FUNCTION__)))
	    return x;
	  pop_seen = zx_scan_xmlns(c);  /* Prescan namespaces so that token can be correctly recognized. */
	  tok = zx_elem_lookup(c, name, c->p, &ns);
	  switch (tok) {
          case zx_lu_Status_ELEM:
            el = (struct zx_elem_s*)zx_DEC_lu_Status(c, ns);
            el->g.n = &x->Status->gg.g;
            x->Status = (struct zx_lu_Status_s*)el;
            break;

	  default:
	    el = zx_known_or_unknown_elem(c, tok, &x->gg, c->p - name, name, ns);
	    tok = ZX_TOK_NOT_FOUND;
	    break;
	  }
          el->g.wo = &x->gg.kids->g;
          x->gg.kids = el;
	  zx_pop_seen(pop_seen);
	  
	  goto next_elem;
	}
      }
      /* false alarm <, fall thru */
    }
    if (!zx_scan_data(c, &x->gg))
      return x;
    goto potential_tag;
  }
 out:
  zx_dec_reverse_lists(&x->gg);
  ZX_END_DEC_EXT(x);
  return x;

 look_for_not_found:
  zx_xml_parse_err(c, '>', (const char*)__FUNCTION__, "char not found");
  return x;
}

#undef EL_NAME
#undef EL_STRUCT
#undef EL_NS
#undef EL_TAG




/* EOF -- c/zx-e-dec.c */
