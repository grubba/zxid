/* c/zx-enc.c - WARNING: This file was automatically generated. DO NOT EDIT!
 * $Id$ */
/* Code generation design Copyright (c) 2006 Sampo Kellomaki (sampo@iki.fi),
 * All Rights Reserved. NO WARRANTY. See file COPYING for terms and conditions
 * of use. Some aspects of code generation were driven by schema
 * descriptions that were used as input and may be subject to their own copyright.
 * Code generation uses a template, whose copyright statement follows. */

/** enc-templ.c  -  XML encoder template, used in code generation
 ** Copyright (c) 2010 Sampo Kellomaki (sampo@iki.fi), All Rights Reserved.
 ** Copyright (c) 2006-2007 Symlabs (symlabs@symlabs.com), All Rights Reserved.
 ** Author: Sampo Kellomaki (sampo@iki.fi)
 ** This is confidential unpublished proprietary source code of the author.
 ** NO WARRANTY, not even implied warranties. Contains trade secrets.
 ** Distribution prohibited unless authorized in writing.
 ** Licensed under Apache License 2.0, see file COPYING.
 ** Id: enc-templ.c,v 1.27 2007-10-05 22:24:28 sampo Exp $
 **
 ** 30.5.2006, created, Sampo Kellomaki (sampo@iki.fi)
 ** 6.8.2006,  factored data structure walking to aux-templ.c --Sampo
 ** 8.8.2006,  reworked namespace handling --Sampo
 ** 26.8.2006, some CSE --Sampo
 ** 23.9.2006, added WO logic --Sampo
 ** 30.9.2007, improvements to WO encoding --Sampo
 ** 8.2.2010,  better handling of schema order encoding of unknown namespace prefixes --Sampo
 **
 ** N.B: wo=wire order (needed for exc-c14n), so=schema order
 ** N.B2: This template is meant to be processed by pd/xsd2sg.pl. Beware
 ** of special markers that xsd2sg.pl expects to find and understand.
 **/

#include <memory.h>
#include "errmac.h"
#include "zx.h"
#include "c/zx-const.h"
#include "c/zx-data.h"
#include "c/zx-ns.h"



#ifdef EL_NAME
#undef EL_NAME
#endif
#ifdef EL_STRUCT
#undef EL_STRUCT
#endif
#ifdef EL_NS
#undef EL_NS
#endif
#ifdef EL_TAG
#undef EL_TAG
#endif

#define EL_NAME   root
#define EL_STRUCT zx_root_s
#define EL_NS     
#define EL_TAG    root

#ifndef MAYBE_UNUSED
#define MAYBE_UNUSED   /* May appear as unused variable, but is needed by some generated code. */
#endif

#if 0
#define ENC_LEN_DEBUG(x,tag,len) D("x=%p tag(%s) len=%d",(x),(tag),(len))
#define ENC_LEN_DEBUG_BASE char* enc_base = p
#else
#define ENC_LEN_DEBUG(x,tag,len)
#define ENC_LEN_DEBUG_BASE
#endif

/* FUNC(zx_LEN_SO_root) */

/* Compute length of an element (and its subelements). The XML attributes
 * and elements are processed in schema order. */

/* Called by: */
int zx_LEN_SO_root(struct zx_ctx* c, struct zx_root_s* x )
{
  struct zx_ns_s* pop_seen = 0;
  struct zx_elem_s* se MAYBE_UNUSED;

  /* root node has no begin tag */
  int len = 0;

  
  {
      struct zx_sa_Assertion_s* e;
      for (e = x->Assertion; e; e = (struct zx_sa_Assertion_s*)e->gg.g.n)
	  len += zx_LEN_SO_sa_Assertion(c, e);
  }
  {
      struct zx_sa_NameID_s* e;
      for (e = x->NameID; e; e = (struct zx_sa_NameID_s*)e->gg.g.n)
	  len += zx_LEN_SO_sa_NameID(c, e);
  }
  for (se = x->NewID; se; se = (struct zx_elem_s*)se->g.n)
    len += zx_LEN_SO_simple_elem(c,se, sizeof("sp:NewID")-1, zx_ns_tab+zx_xmlns_ix_sp);
  {
      struct zx_sp_AuthnRequest_s* e;
      for (e = x->AuthnRequest; e; e = (struct zx_sp_AuthnRequest_s*)e->gg.g.n)
	  len += zx_LEN_SO_sp_AuthnRequest(c, e);
  }
  {
      struct zx_sp_Response_s* e;
      for (e = x->Response; e; e = (struct zx_sp_Response_s*)e->gg.g.n)
	  len += zx_LEN_SO_sp_Response(c, e);
  }
  {
      struct zx_sp_LogoutRequest_s* e;
      for (e = x->LogoutRequest; e; e = (struct zx_sp_LogoutRequest_s*)e->gg.g.n)
	  len += zx_LEN_SO_sp_LogoutRequest(c, e);
  }
  {
      struct zx_sp_LogoutResponse_s* e;
      for (e = x->LogoutResponse; e; e = (struct zx_sp_LogoutResponse_s*)e->gg.g.n)
	  len += zx_LEN_SO_sp_LogoutResponse(c, e);
  }
  {
      struct zx_sp_ManageNameIDRequest_s* e;
      for (e = x->ManageNameIDRequest; e; e = (struct zx_sp_ManageNameIDRequest_s*)e->gg.g.n)
	  len += zx_LEN_SO_sp_ManageNameIDRequest(c, e);
  }
  {
      struct zx_sp_ManageNameIDResponse_s* e;
      for (e = x->ManageNameIDResponse; e; e = (struct zx_sp_ManageNameIDResponse_s*)e->gg.g.n)
	  len += zx_LEN_SO_sp_ManageNameIDResponse(c, e);
  }
  {
      struct zx_e_Envelope_s* e;
      for (e = x->Envelope; e; e = (struct zx_e_Envelope_s*)e->gg.g.n)
	  len += zx_LEN_SO_e_Envelope(c, e);
  }
  {
      struct zx_e_Header_s* e;
      for (e = x->Header; e; e = (struct zx_e_Header_s*)e->gg.g.n)
	  len += zx_LEN_SO_e_Header(c, e);
  }
  {
      struct zx_e_Body_s* e;
      for (e = x->Body; e; e = (struct zx_e_Body_s*)e->gg.g.n)
	  len += zx_LEN_SO_e_Body(c, e);
  }
  {
      struct zx_md_EntityDescriptor_s* e;
      for (e = x->EntityDescriptor; e; e = (struct zx_md_EntityDescriptor_s*)e->gg.g.n)
	  len += zx_LEN_SO_md_EntityDescriptor(c, e);
  }
  {
      struct zx_md_EntitiesDescriptor_s* e;
      for (e = x->EntitiesDescriptor; e; e = (struct zx_md_EntitiesDescriptor_s*)e->gg.g.n)
	  len += zx_LEN_SO_md_EntitiesDescriptor(c, e);
  }
  {
      struct zx_sa11_Assertion_s* e;
      for (e = x->sa11_Assertion; e; e = (struct zx_sa11_Assertion_s*)e->gg.g.n)
	  len += zx_LEN_SO_sa11_Assertion(c, e);
  }
  {
      struct zx_sp11_Request_s* e;
      for (e = x->Request; e; e = (struct zx_sp11_Request_s*)e->gg.g.n)
	  len += zx_LEN_SO_sp11_Request(c, e);
  }
  {
      struct zx_sp11_Response_s* e;
      for (e = x->sp11_Response; e; e = (struct zx_sp11_Response_s*)e->gg.g.n)
	  len += zx_LEN_SO_sp11_Response(c, e);
  }
  {
      struct zx_ff12_Assertion_s* e;
      for (e = x->ff12_Assertion; e; e = (struct zx_ff12_Assertion_s*)e->gg.g.n)
	  len += zx_LEN_SO_ff12_Assertion(c, e);
  }
  {
      struct zx_ff12_AuthnRequest_s* e;
      for (e = x->ff12_AuthnRequest; e; e = (struct zx_ff12_AuthnRequest_s*)e->gg.g.n)
	  len += zx_LEN_SO_ff12_AuthnRequest(c, e);
  }
  {
      struct zx_ff12_AuthnResponse_s* e;
      for (e = x->AuthnResponse; e; e = (struct zx_ff12_AuthnResponse_s*)e->gg.g.n)
	  len += zx_LEN_SO_ff12_AuthnResponse(c, e);
  }
  {
      struct zx_ff12_AuthnRequestEnvelope_s* e;
      for (e = x->AuthnRequestEnvelope; e; e = (struct zx_ff12_AuthnRequestEnvelope_s*)e->gg.g.n)
	  len += zx_LEN_SO_ff12_AuthnRequestEnvelope(c, e);
  }
  {
      struct zx_ff12_AuthnResponseEnvelope_s* e;
      for (e = x->AuthnResponseEnvelope; e; e = (struct zx_ff12_AuthnResponseEnvelope_s*)e->gg.g.n)
	  len += zx_LEN_SO_ff12_AuthnResponseEnvelope(c, e);
  }
  {
      struct zx_ff12_RegisterNameIdentifierRequest_s* e;
      for (e = x->RegisterNameIdentifierRequest; e; e = (struct zx_ff12_RegisterNameIdentifierRequest_s*)e->gg.g.n)
	  len += zx_LEN_SO_ff12_RegisterNameIdentifierRequest(c, e);
  }
  {
      struct zx_ff12_RegisterNameIdentifierResponse_s* e;
      for (e = x->RegisterNameIdentifierResponse; e; e = (struct zx_ff12_RegisterNameIdentifierResponse_s*)e->gg.g.n)
	  len += zx_LEN_SO_ff12_RegisterNameIdentifierResponse(c, e);
  }
  {
      struct zx_ff12_FederationTerminationNotification_s* e;
      for (e = x->FederationTerminationNotification; e; e = (struct zx_ff12_FederationTerminationNotification_s*)e->gg.g.n)
	  len += zx_LEN_SO_ff12_FederationTerminationNotification(c, e);
  }
  {
      struct zx_ff12_LogoutRequest_s* e;
      for (e = x->ff12_LogoutRequest; e; e = (struct zx_ff12_LogoutRequest_s*)e->gg.g.n)
	  len += zx_LEN_SO_ff12_LogoutRequest(c, e);
  }
  {
      struct zx_ff12_LogoutResponse_s* e;
      for (e = x->ff12_LogoutResponse; e; e = (struct zx_ff12_LogoutResponse_s*)e->gg.g.n)
	  len += zx_LEN_SO_ff12_LogoutResponse(c, e);
  }
  {
      struct zx_ff12_NameIdentifierMappingRequest_s* e;
      for (e = x->NameIdentifierMappingRequest; e; e = (struct zx_ff12_NameIdentifierMappingRequest_s*)e->gg.g.n)
	  len += zx_LEN_SO_ff12_NameIdentifierMappingRequest(c, e);
  }
  {
      struct zx_ff12_NameIdentifierMappingResponse_s* e;
      for (e = x->NameIdentifierMappingResponse; e; e = (struct zx_ff12_NameIdentifierMappingResponse_s*)e->gg.g.n)
	  len += zx_LEN_SO_ff12_NameIdentifierMappingResponse(c, e);
  }
  {
      struct zx_m20_EntityDescriptor_s* e;
      for (e = x->m20_EntityDescriptor; e; e = (struct zx_m20_EntityDescriptor_s*)e->gg.g.n)
	  len += zx_LEN_SO_m20_EntityDescriptor(c, e);
  }
  {
      struct zx_m20_EntitiesDescriptor_s* e;
      for (e = x->m20_EntitiesDescriptor; e; e = (struct zx_m20_EntitiesDescriptor_s*)e->gg.g.n)
	  len += zx_LEN_SO_m20_EntitiesDescriptor(c, e);
  }
  {
      struct zx_a_EndpointReference_s* e;
      for (e = x->EndpointReference; e; e = (struct zx_a_EndpointReference_s*)e->gg.g.n)
	  len += zx_LEN_SO_a_EndpointReference(c, e);
  }
  {
      struct zx_hrxml_Candidate_s* e;
      for (e = x->Candidate; e; e = (struct zx_hrxml_Candidate_s*)e->gg.g.n)
	  len += zx_LEN_SO_hrxml_Candidate(c, e);
  }
  {
      struct zx_xasp_XACMLAuthzDecisionQuery_s* e;
      for (e = x->XACMLAuthzDecisionQuery; e; e = (struct zx_xasp_XACMLAuthzDecisionQuery_s*)e->gg.g.n)
	  len += zx_LEN_SO_xasp_XACMLAuthzDecisionQuery(c, e);
  }
  {
      struct zx_xasp_XACMLPolicyQuery_s* e;
      for (e = x->XACMLPolicyQuery; e; e = (struct zx_xasp_XACMLPolicyQuery_s*)e->gg.g.n)
	  len += zx_LEN_SO_xasp_XACMLPolicyQuery(c, e);
  }
  {
      struct zx_xaspcd1_XACMLAuthzDecisionQuery_s* e;
      for (e = x->xaspcd1_XACMLAuthzDecisionQuery; e; e = (struct zx_xaspcd1_XACMLAuthzDecisionQuery_s*)e->gg.g.n)
	  len += zx_LEN_SO_xaspcd1_XACMLAuthzDecisionQuery(c, e);
  }
  {
      struct zx_xaspcd1_XACMLPolicyQuery_s* e;
      for (e = x->xaspcd1_XACMLPolicyQuery; e; e = (struct zx_xaspcd1_XACMLPolicyQuery_s*)e->gg.g.n)
	  len += zx_LEN_SO_xaspcd1_XACMLPolicyQuery(c, e);
  }


  len += zx_len_so_common(c, &x->gg);
  zx_pop_seen(pop_seen);
  ENC_LEN_DEBUG(x, ":root", len);
  return len;
}

/* FUNC(zx_LEN_WO_root) */

/* Compute length of an element (and its subelements). The XML attributes
 * and elements are processed in wire order and no assumptions
 * are made about namespace prefixes. */

/* Called by: */
int zx_LEN_WO_root(struct zx_ctx* c, struct zx_root_s* x )
{
  struct zx_ns_s* pop_seen = 0;
  struct zx_elem_s* se MAYBE_UNUSED;

  /* root node has no begin tag */
  int len = 0;

  
  {
      struct zx_sa_Assertion_s* e;
      for (e = x->Assertion; e; e = (struct zx_sa_Assertion_s*)e->gg.g.n)
	  len += zx_LEN_WO_sa_Assertion(c, e);
  }
  {
      struct zx_sa_NameID_s* e;
      for (e = x->NameID; e; e = (struct zx_sa_NameID_s*)e->gg.g.n)
	  len += zx_LEN_WO_sa_NameID(c, e);
  }
  for (se = x->NewID; se; se = (struct zx_elem_s*)se->g.n)
    len += zx_LEN_WO_simple_elem(c, se, sizeof("NewID")-1);
  {
      struct zx_sp_AuthnRequest_s* e;
      for (e = x->AuthnRequest; e; e = (struct zx_sp_AuthnRequest_s*)e->gg.g.n)
	  len += zx_LEN_WO_sp_AuthnRequest(c, e);
  }
  {
      struct zx_sp_Response_s* e;
      for (e = x->Response; e; e = (struct zx_sp_Response_s*)e->gg.g.n)
	  len += zx_LEN_WO_sp_Response(c, e);
  }
  {
      struct zx_sp_LogoutRequest_s* e;
      for (e = x->LogoutRequest; e; e = (struct zx_sp_LogoutRequest_s*)e->gg.g.n)
	  len += zx_LEN_WO_sp_LogoutRequest(c, e);
  }
  {
      struct zx_sp_LogoutResponse_s* e;
      for (e = x->LogoutResponse; e; e = (struct zx_sp_LogoutResponse_s*)e->gg.g.n)
	  len += zx_LEN_WO_sp_LogoutResponse(c, e);
  }
  {
      struct zx_sp_ManageNameIDRequest_s* e;
      for (e = x->ManageNameIDRequest; e; e = (struct zx_sp_ManageNameIDRequest_s*)e->gg.g.n)
	  len += zx_LEN_WO_sp_ManageNameIDRequest(c, e);
  }
  {
      struct zx_sp_ManageNameIDResponse_s* e;
      for (e = x->ManageNameIDResponse; e; e = (struct zx_sp_ManageNameIDResponse_s*)e->gg.g.n)
	  len += zx_LEN_WO_sp_ManageNameIDResponse(c, e);
  }
  {
      struct zx_e_Envelope_s* e;
      for (e = x->Envelope; e; e = (struct zx_e_Envelope_s*)e->gg.g.n)
	  len += zx_LEN_WO_e_Envelope(c, e);
  }
  {
      struct zx_e_Header_s* e;
      for (e = x->Header; e; e = (struct zx_e_Header_s*)e->gg.g.n)
	  len += zx_LEN_WO_e_Header(c, e);
  }
  {
      struct zx_e_Body_s* e;
      for (e = x->Body; e; e = (struct zx_e_Body_s*)e->gg.g.n)
	  len += zx_LEN_WO_e_Body(c, e);
  }
  {
      struct zx_md_EntityDescriptor_s* e;
      for (e = x->EntityDescriptor; e; e = (struct zx_md_EntityDescriptor_s*)e->gg.g.n)
	  len += zx_LEN_WO_md_EntityDescriptor(c, e);
  }
  {
      struct zx_md_EntitiesDescriptor_s* e;
      for (e = x->EntitiesDescriptor; e; e = (struct zx_md_EntitiesDescriptor_s*)e->gg.g.n)
	  len += zx_LEN_WO_md_EntitiesDescriptor(c, e);
  }
  {
      struct zx_sa11_Assertion_s* e;
      for (e = x->sa11_Assertion; e; e = (struct zx_sa11_Assertion_s*)e->gg.g.n)
	  len += zx_LEN_WO_sa11_Assertion(c, e);
  }
  {
      struct zx_sp11_Request_s* e;
      for (e = x->Request; e; e = (struct zx_sp11_Request_s*)e->gg.g.n)
	  len += zx_LEN_WO_sp11_Request(c, e);
  }
  {
      struct zx_sp11_Response_s* e;
      for (e = x->sp11_Response; e; e = (struct zx_sp11_Response_s*)e->gg.g.n)
	  len += zx_LEN_WO_sp11_Response(c, e);
  }
  {
      struct zx_ff12_Assertion_s* e;
      for (e = x->ff12_Assertion; e; e = (struct zx_ff12_Assertion_s*)e->gg.g.n)
	  len += zx_LEN_WO_ff12_Assertion(c, e);
  }
  {
      struct zx_ff12_AuthnRequest_s* e;
      for (e = x->ff12_AuthnRequest; e; e = (struct zx_ff12_AuthnRequest_s*)e->gg.g.n)
	  len += zx_LEN_WO_ff12_AuthnRequest(c, e);
  }
  {
      struct zx_ff12_AuthnResponse_s* e;
      for (e = x->AuthnResponse; e; e = (struct zx_ff12_AuthnResponse_s*)e->gg.g.n)
	  len += zx_LEN_WO_ff12_AuthnResponse(c, e);
  }
  {
      struct zx_ff12_AuthnRequestEnvelope_s* e;
      for (e = x->AuthnRequestEnvelope; e; e = (struct zx_ff12_AuthnRequestEnvelope_s*)e->gg.g.n)
	  len += zx_LEN_WO_ff12_AuthnRequestEnvelope(c, e);
  }
  {
      struct zx_ff12_AuthnResponseEnvelope_s* e;
      for (e = x->AuthnResponseEnvelope; e; e = (struct zx_ff12_AuthnResponseEnvelope_s*)e->gg.g.n)
	  len += zx_LEN_WO_ff12_AuthnResponseEnvelope(c, e);
  }
  {
      struct zx_ff12_RegisterNameIdentifierRequest_s* e;
      for (e = x->RegisterNameIdentifierRequest; e; e = (struct zx_ff12_RegisterNameIdentifierRequest_s*)e->gg.g.n)
	  len += zx_LEN_WO_ff12_RegisterNameIdentifierRequest(c, e);
  }
  {
      struct zx_ff12_RegisterNameIdentifierResponse_s* e;
      for (e = x->RegisterNameIdentifierResponse; e; e = (struct zx_ff12_RegisterNameIdentifierResponse_s*)e->gg.g.n)
	  len += zx_LEN_WO_ff12_RegisterNameIdentifierResponse(c, e);
  }
  {
      struct zx_ff12_FederationTerminationNotification_s* e;
      for (e = x->FederationTerminationNotification; e; e = (struct zx_ff12_FederationTerminationNotification_s*)e->gg.g.n)
	  len += zx_LEN_WO_ff12_FederationTerminationNotification(c, e);
  }
  {
      struct zx_ff12_LogoutRequest_s* e;
      for (e = x->ff12_LogoutRequest; e; e = (struct zx_ff12_LogoutRequest_s*)e->gg.g.n)
	  len += zx_LEN_WO_ff12_LogoutRequest(c, e);
  }
  {
      struct zx_ff12_LogoutResponse_s* e;
      for (e = x->ff12_LogoutResponse; e; e = (struct zx_ff12_LogoutResponse_s*)e->gg.g.n)
	  len += zx_LEN_WO_ff12_LogoutResponse(c, e);
  }
  {
      struct zx_ff12_NameIdentifierMappingRequest_s* e;
      for (e = x->NameIdentifierMappingRequest; e; e = (struct zx_ff12_NameIdentifierMappingRequest_s*)e->gg.g.n)
	  len += zx_LEN_WO_ff12_NameIdentifierMappingRequest(c, e);
  }
  {
      struct zx_ff12_NameIdentifierMappingResponse_s* e;
      for (e = x->NameIdentifierMappingResponse; e; e = (struct zx_ff12_NameIdentifierMappingResponse_s*)e->gg.g.n)
	  len += zx_LEN_WO_ff12_NameIdentifierMappingResponse(c, e);
  }
  {
      struct zx_m20_EntityDescriptor_s* e;
      for (e = x->m20_EntityDescriptor; e; e = (struct zx_m20_EntityDescriptor_s*)e->gg.g.n)
	  len += zx_LEN_WO_m20_EntityDescriptor(c, e);
  }
  {
      struct zx_m20_EntitiesDescriptor_s* e;
      for (e = x->m20_EntitiesDescriptor; e; e = (struct zx_m20_EntitiesDescriptor_s*)e->gg.g.n)
	  len += zx_LEN_WO_m20_EntitiesDescriptor(c, e);
  }
  {
      struct zx_a_EndpointReference_s* e;
      for (e = x->EndpointReference; e; e = (struct zx_a_EndpointReference_s*)e->gg.g.n)
	  len += zx_LEN_WO_a_EndpointReference(c, e);
  }
  {
      struct zx_hrxml_Candidate_s* e;
      for (e = x->Candidate; e; e = (struct zx_hrxml_Candidate_s*)e->gg.g.n)
	  len += zx_LEN_WO_hrxml_Candidate(c, e);
  }
  {
      struct zx_xasp_XACMLAuthzDecisionQuery_s* e;
      for (e = x->XACMLAuthzDecisionQuery; e; e = (struct zx_xasp_XACMLAuthzDecisionQuery_s*)e->gg.g.n)
	  len += zx_LEN_WO_xasp_XACMLAuthzDecisionQuery(c, e);
  }
  {
      struct zx_xasp_XACMLPolicyQuery_s* e;
      for (e = x->XACMLPolicyQuery; e; e = (struct zx_xasp_XACMLPolicyQuery_s*)e->gg.g.n)
	  len += zx_LEN_WO_xasp_XACMLPolicyQuery(c, e);
  }
  {
      struct zx_xaspcd1_XACMLAuthzDecisionQuery_s* e;
      for (e = x->xaspcd1_XACMLAuthzDecisionQuery; e; e = (struct zx_xaspcd1_XACMLAuthzDecisionQuery_s*)e->gg.g.n)
	  len += zx_LEN_WO_xaspcd1_XACMLAuthzDecisionQuery(c, e);
  }
  {
      struct zx_xaspcd1_XACMLPolicyQuery_s* e;
      for (e = x->xaspcd1_XACMLPolicyQuery; e; e = (struct zx_xaspcd1_XACMLPolicyQuery_s*)e->gg.g.n)
	  len += zx_LEN_WO_xaspcd1_XACMLPolicyQuery(c, e);
  }


  len += zx_len_wo_common(c, &x->gg); 
  zx_pop_seen(pop_seen);
  ENC_LEN_DEBUG(x, ":root", len);
  return len;
}

/* FUNC(zx_ENC_SO_root) */

/* Render element into string. The XML attributes and elements are
 * processed in schema order. This is what you generally want for
 * rendering new data structure to a string. The wo pointers are not used. */

/* Called by: */
char* zx_ENC_SO_root(struct zx_ctx* c, struct zx_root_s* x, char* p )
{
  struct zx_elem_s* se MAYBE_UNUSED;
  struct zx_ns_s* pop_seen = 0;
  ENC_LEN_DEBUG_BASE;

  /* root node has no begin tag */

  
  {
      struct zx_sa_Assertion_s* e;
      for (e = x->Assertion; e; e = (struct zx_sa_Assertion_s*)e->gg.g.n)
	  p = zx_ENC_SO_sa_Assertion(c, e, p);
  }
  {
      struct zx_sa_NameID_s* e;
      for (e = x->NameID; e; e = (struct zx_sa_NameID_s*)e->gg.g.n)
	  p = zx_ENC_SO_sa_NameID(c, e, p);
  }
  for (se = x->NewID; se; se = (struct zx_elem_s*)se->g.n)
    p = zx_ENC_SO_simple_elem(c, se, p, "sp:NewID", sizeof("sp:NewID")-1, zx_ns_tab+zx_xmlns_ix_sp);
  {
      struct zx_sp_AuthnRequest_s* e;
      for (e = x->AuthnRequest; e; e = (struct zx_sp_AuthnRequest_s*)e->gg.g.n)
	  p = zx_ENC_SO_sp_AuthnRequest(c, e, p);
  }
  {
      struct zx_sp_Response_s* e;
      for (e = x->Response; e; e = (struct zx_sp_Response_s*)e->gg.g.n)
	  p = zx_ENC_SO_sp_Response(c, e, p);
  }
  {
      struct zx_sp_LogoutRequest_s* e;
      for (e = x->LogoutRequest; e; e = (struct zx_sp_LogoutRequest_s*)e->gg.g.n)
	  p = zx_ENC_SO_sp_LogoutRequest(c, e, p);
  }
  {
      struct zx_sp_LogoutResponse_s* e;
      for (e = x->LogoutResponse; e; e = (struct zx_sp_LogoutResponse_s*)e->gg.g.n)
	  p = zx_ENC_SO_sp_LogoutResponse(c, e, p);
  }
  {
      struct zx_sp_ManageNameIDRequest_s* e;
      for (e = x->ManageNameIDRequest; e; e = (struct zx_sp_ManageNameIDRequest_s*)e->gg.g.n)
	  p = zx_ENC_SO_sp_ManageNameIDRequest(c, e, p);
  }
  {
      struct zx_sp_ManageNameIDResponse_s* e;
      for (e = x->ManageNameIDResponse; e; e = (struct zx_sp_ManageNameIDResponse_s*)e->gg.g.n)
	  p = zx_ENC_SO_sp_ManageNameIDResponse(c, e, p);
  }
  {
      struct zx_e_Envelope_s* e;
      for (e = x->Envelope; e; e = (struct zx_e_Envelope_s*)e->gg.g.n)
	  p = zx_ENC_SO_e_Envelope(c, e, p);
  }
  {
      struct zx_e_Header_s* e;
      for (e = x->Header; e; e = (struct zx_e_Header_s*)e->gg.g.n)
	  p = zx_ENC_SO_e_Header(c, e, p);
  }
  {
      struct zx_e_Body_s* e;
      for (e = x->Body; e; e = (struct zx_e_Body_s*)e->gg.g.n)
	  p = zx_ENC_SO_e_Body(c, e, p);
  }
  {
      struct zx_md_EntityDescriptor_s* e;
      for (e = x->EntityDescriptor; e; e = (struct zx_md_EntityDescriptor_s*)e->gg.g.n)
	  p = zx_ENC_SO_md_EntityDescriptor(c, e, p);
  }
  {
      struct zx_md_EntitiesDescriptor_s* e;
      for (e = x->EntitiesDescriptor; e; e = (struct zx_md_EntitiesDescriptor_s*)e->gg.g.n)
	  p = zx_ENC_SO_md_EntitiesDescriptor(c, e, p);
  }
  {
      struct zx_sa11_Assertion_s* e;
      for (e = x->sa11_Assertion; e; e = (struct zx_sa11_Assertion_s*)e->gg.g.n)
	  p = zx_ENC_SO_sa11_Assertion(c, e, p);
  }
  {
      struct zx_sp11_Request_s* e;
      for (e = x->Request; e; e = (struct zx_sp11_Request_s*)e->gg.g.n)
	  p = zx_ENC_SO_sp11_Request(c, e, p);
  }
  {
      struct zx_sp11_Response_s* e;
      for (e = x->sp11_Response; e; e = (struct zx_sp11_Response_s*)e->gg.g.n)
	  p = zx_ENC_SO_sp11_Response(c, e, p);
  }
  {
      struct zx_ff12_Assertion_s* e;
      for (e = x->ff12_Assertion; e; e = (struct zx_ff12_Assertion_s*)e->gg.g.n)
	  p = zx_ENC_SO_ff12_Assertion(c, e, p);
  }
  {
      struct zx_ff12_AuthnRequest_s* e;
      for (e = x->ff12_AuthnRequest; e; e = (struct zx_ff12_AuthnRequest_s*)e->gg.g.n)
	  p = zx_ENC_SO_ff12_AuthnRequest(c, e, p);
  }
  {
      struct zx_ff12_AuthnResponse_s* e;
      for (e = x->AuthnResponse; e; e = (struct zx_ff12_AuthnResponse_s*)e->gg.g.n)
	  p = zx_ENC_SO_ff12_AuthnResponse(c, e, p);
  }
  {
      struct zx_ff12_AuthnRequestEnvelope_s* e;
      for (e = x->AuthnRequestEnvelope; e; e = (struct zx_ff12_AuthnRequestEnvelope_s*)e->gg.g.n)
	  p = zx_ENC_SO_ff12_AuthnRequestEnvelope(c, e, p);
  }
  {
      struct zx_ff12_AuthnResponseEnvelope_s* e;
      for (e = x->AuthnResponseEnvelope; e; e = (struct zx_ff12_AuthnResponseEnvelope_s*)e->gg.g.n)
	  p = zx_ENC_SO_ff12_AuthnResponseEnvelope(c, e, p);
  }
  {
      struct zx_ff12_RegisterNameIdentifierRequest_s* e;
      for (e = x->RegisterNameIdentifierRequest; e; e = (struct zx_ff12_RegisterNameIdentifierRequest_s*)e->gg.g.n)
	  p = zx_ENC_SO_ff12_RegisterNameIdentifierRequest(c, e, p);
  }
  {
      struct zx_ff12_RegisterNameIdentifierResponse_s* e;
      for (e = x->RegisterNameIdentifierResponse; e; e = (struct zx_ff12_RegisterNameIdentifierResponse_s*)e->gg.g.n)
	  p = zx_ENC_SO_ff12_RegisterNameIdentifierResponse(c, e, p);
  }
  {
      struct zx_ff12_FederationTerminationNotification_s* e;
      for (e = x->FederationTerminationNotification; e; e = (struct zx_ff12_FederationTerminationNotification_s*)e->gg.g.n)
	  p = zx_ENC_SO_ff12_FederationTerminationNotification(c, e, p);
  }
  {
      struct zx_ff12_LogoutRequest_s* e;
      for (e = x->ff12_LogoutRequest; e; e = (struct zx_ff12_LogoutRequest_s*)e->gg.g.n)
	  p = zx_ENC_SO_ff12_LogoutRequest(c, e, p);
  }
  {
      struct zx_ff12_LogoutResponse_s* e;
      for (e = x->ff12_LogoutResponse; e; e = (struct zx_ff12_LogoutResponse_s*)e->gg.g.n)
	  p = zx_ENC_SO_ff12_LogoutResponse(c, e, p);
  }
  {
      struct zx_ff12_NameIdentifierMappingRequest_s* e;
      for (e = x->NameIdentifierMappingRequest; e; e = (struct zx_ff12_NameIdentifierMappingRequest_s*)e->gg.g.n)
	  p = zx_ENC_SO_ff12_NameIdentifierMappingRequest(c, e, p);
  }
  {
      struct zx_ff12_NameIdentifierMappingResponse_s* e;
      for (e = x->NameIdentifierMappingResponse; e; e = (struct zx_ff12_NameIdentifierMappingResponse_s*)e->gg.g.n)
	  p = zx_ENC_SO_ff12_NameIdentifierMappingResponse(c, e, p);
  }
  {
      struct zx_m20_EntityDescriptor_s* e;
      for (e = x->m20_EntityDescriptor; e; e = (struct zx_m20_EntityDescriptor_s*)e->gg.g.n)
	  p = zx_ENC_SO_m20_EntityDescriptor(c, e, p);
  }
  {
      struct zx_m20_EntitiesDescriptor_s* e;
      for (e = x->m20_EntitiesDescriptor; e; e = (struct zx_m20_EntitiesDescriptor_s*)e->gg.g.n)
	  p = zx_ENC_SO_m20_EntitiesDescriptor(c, e, p);
  }
  {
      struct zx_a_EndpointReference_s* e;
      for (e = x->EndpointReference; e; e = (struct zx_a_EndpointReference_s*)e->gg.g.n)
	  p = zx_ENC_SO_a_EndpointReference(c, e, p);
  }
  {
      struct zx_hrxml_Candidate_s* e;
      for (e = x->Candidate; e; e = (struct zx_hrxml_Candidate_s*)e->gg.g.n)
	  p = zx_ENC_SO_hrxml_Candidate(c, e, p);
  }
  {
      struct zx_xasp_XACMLAuthzDecisionQuery_s* e;
      for (e = x->XACMLAuthzDecisionQuery; e; e = (struct zx_xasp_XACMLAuthzDecisionQuery_s*)e->gg.g.n)
	  p = zx_ENC_SO_xasp_XACMLAuthzDecisionQuery(c, e, p);
  }
  {
      struct zx_xasp_XACMLPolicyQuery_s* e;
      for (e = x->XACMLPolicyQuery; e; e = (struct zx_xasp_XACMLPolicyQuery_s*)e->gg.g.n)
	  p = zx_ENC_SO_xasp_XACMLPolicyQuery(c, e, p);
  }
  {
      struct zx_xaspcd1_XACMLAuthzDecisionQuery_s* e;
      for (e = x->xaspcd1_XACMLAuthzDecisionQuery; e; e = (struct zx_xaspcd1_XACMLAuthzDecisionQuery_s*)e->gg.g.n)
	  p = zx_ENC_SO_xaspcd1_XACMLAuthzDecisionQuery(c, e, p);
  }
  {
      struct zx_xaspcd1_XACMLPolicyQuery_s* e;
      for (e = x->xaspcd1_XACMLPolicyQuery; e; e = (struct zx_xaspcd1_XACMLPolicyQuery_s*)e->gg.g.n)
	  p = zx_ENC_SO_xaspcd1_XACMLPolicyQuery(c, e, p);
  }

  p = zx_enc_so_unknown_elems_and_content(c, p, &x->gg);
  

  /* root node has no end tag either */

  ENC_LEN_DEBUG(x, ":root", p-enc_base);
  return p;
}

/* FUNC(zx_ENC_WO_root) */

/* Render element into string. The XML attributes and elements are
 * processed in wire order by chasing wo pointers. This is what you want for
 * validating signatures on other people's XML documents. */

/* Called by: */
char* zx_ENC_WO_root(struct zx_ctx* c, struct zx_root_s* x, char* p )
{
  struct zx_elem_s* kid;
  struct zx_ns_s* pop_seen = 0;
  char* q;
  char* qq;
  ENC_LEN_DEBUG_BASE;

  /* root node has no begin tag */

  
  for (kid = x->gg.kids; kid; kid = ((struct zx_elem_s*)(kid->g.wo)))
    p = zx_ENC_WO_any_elem(c, kid, p);
  

  /* root node has no end tag either */

  ENC_LEN_DEBUG(x, ":root", p-enc_base);
  return p;
}

/* FUNC(zx_EASY_ENC_SO_root) */

/* Called by: */
struct zx_str* zx_EASY_ENC_SO_root(struct zx_ctx* c, struct zx_root_s* x )
{
  int len;
  char* buf;
  c->ns_tab = ZX_ALLOC(c, sizeof(zx_ns_tab));
  memcpy(c->ns_tab, zx_ns_tab, sizeof(zx_ns_tab));
  len = zx_LEN_SO_root(c, x );
  buf = ZX_ALLOC(c, len+1);
  return zx_easy_enc_common(c, zx_ENC_SO_root(c, x, buf ), buf, len);
}

/* FUNC(zx_EASY_ENC_WO_root) */

/* Called by: */
struct zx_str* zx_EASY_ENC_WO_root(struct zx_ctx* c, struct zx_root_s* x )
{
  int len;
  char* buf;
  c->ns_tab = ZX_ALLOC(c, sizeof(zx_ns_tab));
  memcpy(c->ns_tab, zx_ns_tab, sizeof(zx_ns_tab));
  len = zx_LEN_WO_root(c, x );
  buf = ZX_ALLOC(c, len+1);
  return zx_easy_enc_common(c, zx_ENC_WO_root(c, x, buf ), buf, len);
}






#ifdef EL_NAME
#undef EL_NAME
#endif
#ifdef EL_STRUCT
#undef EL_STRUCT
#endif
#ifdef EL_NS
#undef EL_NS
#endif
#ifdef EL_TAG
#undef EL_TAG
#endif

#define EL_NAME   simple_elem
#define EL_STRUCT zx_elem_s
#define EL_NS     
#define EL_TAG    simple_elem

#ifndef MAYBE_UNUSED
#define MAYBE_UNUSED   /* May appear as unused variable, but is needed by some generated code. */
#endif

#if 0
#define ENC_LEN_DEBUG(x,tag,len) D("x=%p tag(%s) len=%d",(x),(tag),(len))
#define ENC_LEN_DEBUG_BASE char* enc_base = p
#else
#define ENC_LEN_DEBUG(x,tag,len)
#define ENC_LEN_DEBUG_BASE
#endif

/* FUNC(zx_LEN_SO_simple_elem) */

/* Compute length of an element (and its subelements). The XML attributes
 * and elements are processed in schema order. */

/* Called by: */
int zx_LEN_SO_simple_elem(struct zx_ctx* c, struct zx_elem_s* x , int simplelen, struct zx_ns_s* ns)
{
  struct zx_ns_s* pop_seen = 0;
  struct zx_elem_s* se MAYBE_UNUSED;
#if 1 /* NORMALMODE */
  /* *** in simple_elem case should output ns prefix from ns node. */
  int len = ZX_LEN_SIMPLE_TAG(x->g.tok, simplelen, ns) + 1 + ZX_LEN_SIMPLE_TAG(x->g.tok, simplelen, ns)+2;
  if (c->inc_ns_len)
    len += zx_len_inc_ns(c, &pop_seen);
  len += zx_len_xmlns_if_not_seen(c, ns, &pop_seen);


#else
  /* root node has no begin tag */
  int len = 0;
#endif
  


  len += zx_len_so_common(c, x);
  zx_pop_seen(pop_seen);
  ENC_LEN_DEBUG(x, "simple_elem", len);
  return len;
}

/* FUNC(zx_LEN_WO_simple_elem) */

/* Compute length of an element (and its subelements). The XML attributes
 * and elements are processed in wire order and no assumptions
 * are made about namespace prefixes. */

/* Called by: */
int zx_LEN_WO_simple_elem(struct zx_ctx* c, struct zx_elem_s* x , int simplelen)
{
  struct zx_ns_s* pop_seen = 0;
  struct zx_elem_s* se MAYBE_UNUSED;
#if 1 /* NORMALMODE */
  int len = 1 + simplelen + 1 + 2 + simplelen + 1;
  
  if (x->g.ns && x->g.ns->prefix_len)
    len += (x->g.ns->prefix_len + 1) * 2;
  if (c->inc_ns_len)
    len += zx_len_inc_ns(c, &pop_seen);
  len += zx_len_xmlns_if_not_seen(c, x->g.ns, &pop_seen);


#else
  /* root node has no begin tag */
  int len = 0;
#endif
  


  len += zx_len_wo_common(c, x); 
  zx_pop_seen(pop_seen);
  ENC_LEN_DEBUG(x, "simple_elem", len);
  return len;
}

/* FUNC(zx_ENC_SO_simple_elem) */

/* Render element into string. The XML attributes and elements are
 * processed in schema order. This is what you generally want for
 * rendering new data structure to a string. The wo pointers are not used. */

/* Called by: */
char* zx_ENC_SO_simple_elem(struct zx_ctx* c, struct zx_elem_s* x, char* p , char* simpletag, int simplelen, struct zx_ns_s* ns)
{
  struct zx_elem_s* se MAYBE_UNUSED;
  struct zx_ns_s* pop_seen = 0;
  ENC_LEN_DEBUG_BASE;
#if 1 /* NORMALMODE */
  /* *** in simple_elem case should output ns prefix from ns node. */
  ZX_OUT_SIMPLE_TAG(p, x->g.tok, simpletag, simplelen, ns);
  if (c->inc_ns)
    p = zx_enc_inc_ns(c, p, &pop_seen);
  p = zx_enc_xmlns_if_not_seen(c, p, ns, &pop_seen);

  p = zx_enc_unknown_attrs(p, x->any_attr);
#else
  /* root node has no begin tag */
#endif
  

  p = zx_enc_so_unknown_elems_and_content(c, p, x);
  
#if 1 /* NORMALMODE */
  ZX_OUT_SIMPLE_CLOSE_TAG(p, x->g.tok, simpletag, simplelen, ns);
  zx_pop_seen(pop_seen);
#else
  /* root node has no end tag either */
#endif
  ENC_LEN_DEBUG(x, "simple_elem", p-enc_base);
  return p;
}

/* FUNC(zx_ENC_WO_simple_elem) */

/* Render element into string. The XML attributes and elements are
 * processed in wire order by chasing wo pointers. This is what you want for
 * validating signatures on other people's XML documents. */

/* Called by: */
char* zx_ENC_WO_simple_elem(struct zx_ctx* c, struct zx_elem_s* x, char* p , char* simpletag, int simplelen)
{
  struct zx_elem_s* kid;
  struct zx_ns_s* pop_seen = 0;
  char* q;
  char* qq;
  ENC_LEN_DEBUG_BASE;
#if 1 /* NORMALMODE */
  ZX_OUT_CH(p, '<');
  q = p;
  if (x->g.ns && x->g.ns->prefix_len) {
    ZX_OUT_MEM(p, x->g.ns->prefix, x->g.ns->prefix_len);
    ZX_OUT_CH(p, ':');
  }
  ZX_OUT_MEM(p, simpletag, simplelen);
  qq = p;

  /* *** sort the namespaces */
  if (c->inc_ns)
    zx_add_inc_ns(c, &pop_seen);
  zx_add_xmlns_if_not_seen(c, x->g.ns, &pop_seen);

  p = zx_enc_seen(p, pop_seen); 

  p = zx_enc_unknown_attrs(p, x->any_attr);
#else
  /* root node has no begin tag */
#endif
  
  for (kid = x->kids; kid; kid = ((struct zx_elem_s*)(kid->g.wo)))
    p = zx_ENC_WO_any_elem(c, kid, p);
  
#if 1 /* NORMALMODE */
  ZX_OUT_CH(p, '<');
  ZX_OUT_CH(p, '/');
  ZX_OUT_MEM(p, q, qq-q);
  ZX_OUT_CH(p, '>');
  zx_pop_seen(pop_seen);
#else
  /* root node has no end tag either */
#endif
  ENC_LEN_DEBUG(x, "simple_elem", p-enc_base);
  return p;
}

/* FUNC(zx_EASY_ENC_SO_simple_elem) */

/* Called by: */
struct zx_str* zx_EASY_ENC_SO_simple_elem(struct zx_ctx* c, struct zx_elem_s* x , char* simpletag, int simplelen, struct zx_ns_s* ns)
{
  int len;
  char* buf;
  c->ns_tab = ZX_ALLOC(c, sizeof(zx_ns_tab));
  memcpy(c->ns_tab, zx_ns_tab, sizeof(zx_ns_tab));
  len = zx_LEN_SO_simple_elem(c, x , simplelen, ns);
  buf = ZX_ALLOC(c, len+1);
  return zx_easy_enc_common(c, zx_ENC_SO_simple_elem(c, x, buf , simpletag, simplelen, ns), buf, len);
}

/* FUNC(zx_EASY_ENC_WO_simple_elem) */

/* Called by: */
struct zx_str* zx_EASY_ENC_WO_simple_elem(struct zx_ctx* c, struct zx_elem_s* x , char* simpletag, int simplelen)
{
  int len;
  char* buf;
  c->ns_tab = ZX_ALLOC(c, sizeof(zx_ns_tab));
  memcpy(c->ns_tab, zx_ns_tab, sizeof(zx_ns_tab));
  len = zx_LEN_WO_simple_elem(c, x , simplelen);
  buf = ZX_ALLOC(c, len+1);
  return zx_easy_enc_common(c, zx_ENC_WO_simple_elem(c, x, buf , simpletag, simplelen), buf, len);
}






/* FUNC(zx_ENC_WO_any_elem) */

/* Called by: */
int zx_LEN_WO_any_elem(struct zx_ctx* c, struct zx_elem_s* x)
{
  int len;
  //struct zx_elem_s* kid;
  switch (x->g.tok) {
  case zx_a_Address_ELEM:
    return zx_LEN_WO_a_Address(c, (struct zx_a_Address_s*)x);
  case zx_a_ReferenceParameters_ELEM:
    return zx_LEN_WO_a_ReferenceParameters(c, (struct zx_a_ReferenceParameters_s*)x);
  case zx_a_Metadata_ELEM:
    return zx_LEN_WO_a_Metadata(c, (struct zx_a_Metadata_s*)x);
  case zx_sbf_Framework_ELEM:
    return zx_LEN_WO_sbf_Framework(c, (struct zx_sbf_Framework_s*)x);
  case zx_di_Abstract_ELEM:
    return zx_LEN_WO_simple_elem(c, (struct zx_elem_s*)x, sizeof("Abstract")-1);
  case zx_di_ProviderID_ELEM:
    return zx_LEN_WO_simple_elem(c, (struct zx_elem_s*)x, sizeof("ProviderID")-1);
  case zx_di_ServiceType_ELEM:
    return zx_LEN_WO_simple_elem(c, (struct zx_elem_s*)x, sizeof("ServiceType")-1);
  case zx_di_SecurityContext_ELEM:
    return zx_LEN_WO_di_SecurityContext(c, (struct zx_di_SecurityContext_s*)x);
  case zx_a_Action_ELEM:
    return zx_LEN_WO_a_Action(c, (struct zx_a_Action_s*)x);
  case zx_a_SoapAction_ELEM:
    return zx_LEN_WO_simple_elem(c, (struct zx_elem_s*)x, sizeof("SoapAction")-1);
  case zx_b_TargetIdentity_ELEM:
    return zx_LEN_WO_b_TargetIdentity(c, (struct zx_b_TargetIdentity_s*)x);
  case zx_ac_ActivationLimitDuration_ELEM:
    return zx_LEN_WO_ac_ActivationLimitDuration(c, (struct zx_ac_ActivationLimitDuration_s*)x);
  case zx_ac_ActivationLimitUsages_ELEM:
    return zx_LEN_WO_ac_ActivationLimitUsages(c, (struct zx_ac_ActivationLimitUsages_s*)x);
  case zx_ac_ActivationLimitSession_ELEM:
    return zx_LEN_WO_simple_elem(c, (struct zx_elem_s*)x, sizeof("ActivationLimitSession")-1);
  case zx_ac_Length_ELEM:
    return zx_LEN_WO_ac_Length(c, (struct zx_ac_Length_s*)x);
  case zx_ac_Alphabet_ELEM:
    return zx_LEN_WO_ac_Alphabet(c, (struct zx_ac_Alphabet_s*)x);
  case zx_ac_Generation_ELEM:
    return zx_LEN_WO_ac_Generation(c, (struct zx_ac_Generation_s*)x);
  case zx_ac_ActivationLimit_ELEM:
    return zx_LEN_WO_ac_ActivationLimit(c, (struct zx_ac_ActivationLimit_s*)x);
  case zx_ac_Extension_ELEM:
    return zx_LEN_WO_ac_Extension(c, (struct zx_ac_Extension_s*)x);
  case zx_ac_GoverningAgreements_ELEM:
    return zx_LEN_WO_ac_GoverningAgreements(c, (struct zx_ac_GoverningAgreements_s*)x);
  case zx_ac_Identification_ELEM:
    return zx_LEN_WO_ac_Identification(c, (struct zx_ac_Identification_s*)x);
  case zx_ac_TechnicalProtection_ELEM:
    return zx_LEN_WO_ac_TechnicalProtection(c, (struct zx_ac_TechnicalProtection_s*)x);
  case zx_ac_OperationalProtection_ELEM:
    return zx_LEN_WO_ac_OperationalProtection(c, (struct zx_ac_OperationalProtection_s*)x);
  case zx_ac_AuthenticationMethod_ELEM:
    return zx_LEN_WO_ac_AuthenticationMethod(c, (struct zx_ac_AuthenticationMethod_s*)x);
  case zx_ac_AuthenticatingAuthority_ELEM:
    return zx_LEN_WO_ac_AuthenticatingAuthority(c, (struct zx_ac_AuthenticatingAuthority_s*)x);
  case zx_ac_PrincipalAuthenticationMechanism_ELEM:
    return zx_LEN_WO_ac_PrincipalAuthenticationMechanism(c, (struct zx_ac_PrincipalAuthenticationMechanism_s*)x);
  case zx_ac_Authenticator_ELEM:
    return zx_LEN_WO_ac_Authenticator(c, (struct zx_ac_Authenticator_s*)x);
  case zx_ac_AuthenticatorTransportProtocol_ELEM:
    return zx_LEN_WO_ac_AuthenticatorTransportProtocol(c, (struct zx_ac_AuthenticatorTransportProtocol_s*)x);
  case zx_ac_PreviousSession_ELEM:
    return zx_LEN_WO_ac_PreviousSession(c, (struct zx_ac_PreviousSession_s*)x);
  case zx_ac_ResumeSession_ELEM:
    return zx_LEN_WO_ac_ResumeSession(c, (struct zx_ac_ResumeSession_s*)x);
  case zx_ac_DigSig_ELEM:
    return zx_LEN_WO_ac_DigSig(c, (struct zx_ac_DigSig_s*)x);
  case zx_ac_Password_ELEM:
    return zx_LEN_WO_ac_Password(c, (struct zx_ac_Password_s*)x);
  case zx_ac_ZeroKnowledge_ELEM:
    return zx_LEN_WO_ac_ZeroKnowledge(c, (struct zx_ac_ZeroKnowledge_s*)x);
  case zx_ac_SharedSecretChallengeResponse_ELEM:
    return zx_LEN_WO_ac_SharedSecretChallengeResponse(c, (struct zx_ac_SharedSecretChallengeResponse_s*)x);
  case zx_ac_SharedSecretDynamicPlaintext_ELEM:
    return zx_LEN_WO_ac_SharedSecretDynamicPlaintext(c, (struct zx_ac_SharedSecretDynamicPlaintext_s*)x);
  case zx_ac_IPAddress_ELEM:
    return zx_LEN_WO_ac_IPAddress(c, (struct zx_ac_IPAddress_s*)x);
  case zx_ac_AsymmetricDecryption_ELEM:
    return zx_LEN_WO_ac_AsymmetricDecryption(c, (struct zx_ac_AsymmetricDecryption_s*)x);
  case zx_ac_AsymmetricKeyAgreement_ELEM:
    return zx_LEN_WO_ac_AsymmetricKeyAgreement(c, (struct zx_ac_AsymmetricKeyAgreement_s*)x);
  case zx_ac_HTTP_ELEM:
    return zx_LEN_WO_ac_HTTP(c, (struct zx_ac_HTTP_s*)x);
  case zx_ac_SSL_ELEM:
    return zx_LEN_WO_ac_SSL(c, (struct zx_ac_SSL_s*)x);
  case zx_ac_MobileNetworkNoEncryption_ELEM:
    return zx_LEN_WO_ac_MobileNetworkNoEncryption(c, (struct zx_ac_MobileNetworkNoEncryption_s*)x);
  case zx_ac_MobileNetworkRadioEncryption_ELEM:
    return zx_LEN_WO_ac_MobileNetworkRadioEncryption(c, (struct zx_ac_MobileNetworkRadioEncryption_s*)x);
  case zx_ac_MobileNetworkEndToEndEncryption_ELEM:
    return zx_LEN_WO_ac_MobileNetworkEndToEndEncryption(c, (struct zx_ac_MobileNetworkEndToEndEncryption_s*)x);
  case zx_ac_WTLS_ELEM:
    return zx_LEN_WO_ac_WTLS(c, (struct zx_ac_WTLS_s*)x);
  case zx_ac_IPSec_ELEM:
    return zx_LEN_WO_ac_IPSec(c, (struct zx_ac_IPSec_s*)x);
  case zx_ac_GoverningAgreementRef_ELEM:
    return zx_LEN_WO_ac_GoverningAgreementRef(c, (struct zx_ac_GoverningAgreementRef_s*)x);
  case zx_ac_PhysicalVerification_ELEM:
    return zx_LEN_WO_ac_PhysicalVerification(c, (struct zx_ac_PhysicalVerification_s*)x);
  case zx_ac_WrittenConsent_ELEM:
    return zx_LEN_WO_ac_WrittenConsent(c, (struct zx_ac_WrittenConsent_s*)x);
  case zx_ac_ActivationPin_ELEM:
    return zx_LEN_WO_ac_ActivationPin(c, (struct zx_ac_ActivationPin_s*)x);
  case zx_ac_SecurityAudit_ELEM:
    return zx_LEN_WO_ac_SecurityAudit(c, (struct zx_ac_SecurityAudit_s*)x);
  case zx_ac_DeactivationCallCenter_ELEM:
    return zx_LEN_WO_ac_DeactivationCallCenter(c, (struct zx_ac_DeactivationCallCenter_s*)x);
  case zx_ac_Token_ELEM:
    return zx_LEN_WO_ac_Token(c, (struct zx_ac_Token_s*)x);
  case zx_ac_Smartcard_ELEM:
    return zx_LEN_WO_ac_Smartcard(c, (struct zx_ac_Smartcard_s*)x);
  case zx_ac_KeyActivation_ELEM:
    return zx_LEN_WO_ac_KeyActivation(c, (struct zx_ac_KeyActivation_s*)x);
  case zx_ac_KeyStorage_ELEM:
    return zx_LEN_WO_ac_KeyStorage(c, (struct zx_ac_KeyStorage_s*)x);
  case zx_ac_KeySharing_ELEM:
    return zx_LEN_WO_ac_KeySharing(c, (struct zx_ac_KeySharing_s*)x);
  case zx_ac_SwitchAudit_ELEM:
    return zx_LEN_WO_ac_SwitchAudit(c, (struct zx_ac_SwitchAudit_s*)x);
  case zx_ac_PrivateKeyProtection_ELEM:
    return zx_LEN_WO_ac_PrivateKeyProtection(c, (struct zx_ac_PrivateKeyProtection_s*)x);
  case zx_ac_SecretKeyProtection_ELEM:
    return zx_LEN_WO_ac_SecretKeyProtection(c, (struct zx_ac_SecretKeyProtection_s*)x);
  case zx_ac_TimeSyncToken_ELEM:
    return zx_LEN_WO_ac_TimeSyncToken(c, (struct zx_ac_TimeSyncToken_s*)x);
  case zx_as_Transform_ELEM:
    return zx_LEN_WO_as_Transform(c, (struct zx_as_Transform_s*)x);
  case zx_as_Data_ELEM:
    return zx_LEN_WO_simple_elem(c, (struct zx_elem_s*)x, sizeof("Data")-1);
  case zx_sp_RequestedAuthnContext_ELEM:
    return zx_LEN_WO_sp_RequestedAuthnContext(c, (struct zx_sp_RequestedAuthnContext_s*)x);
  case zx_as_Extensions_ELEM:
    return zx_LEN_WO_as_Extensions(c, (struct zx_as_Extensions_s*)x);
  case zx_lu_Status_ELEM:
    return zx_LEN_WO_lu_Status(c, (struct zx_lu_Status_s*)x);
  case zx_as_PasswordTransforms_ELEM:
    return zx_LEN_WO_as_PasswordTransforms(c, (struct zx_as_PasswordTransforms_s*)x);
  case zx_a_EndpointReference_ELEM:
    return zx_LEN_WO_a_EndpointReference(c, (struct zx_a_EndpointReference_s*)x);
  case zx_as_Parameter_ELEM:
    return zx_LEN_WO_as_Parameter(c, (struct zx_as_Parameter_s*)x);
  case zx_b_SecurityMechID_ELEM:
    return zx_LEN_WO_simple_elem(c, (struct zx_elem_s*)x, sizeof("SecurityMechID")-1);
  case zx_sa_Assertion_ELEM:
    return zx_LEN_WO_sa_Assertion(c, (struct zx_sa_Assertion_s*)x);
  case zx_sa_EncryptedAssertion_ELEM:
    return zx_LEN_WO_sa_EncryptedAssertion(c, (struct zx_sa_EncryptedAssertion_s*)x);
  case zx_sa11_Assertion_ELEM:
    return zx_LEN_WO_sa11_Assertion(c, (struct zx_sa11_Assertion_s*)x);
  case zx_ff12_Assertion_ELEM:
    return zx_LEN_WO_ff12_Assertion(c, (struct zx_ff12_Assertion_s*)x);
  case zx_xa_Obligation_ELEM:
    return zx_LEN_WO_xa_Obligation(c, (struct zx_xa_Obligation_s*)x);
  case zx_tas3sol_Dict_ELEM:
    return zx_LEN_WO_tas3sol_Dict(c, (struct zx_tas3sol_Dict_s*)x);
  case zx_b_InteractionService_ELEM:
    return zx_LEN_WO_b_InteractionService(c, (struct zx_b_InteractionService_s*)x);
  case zx_cb_ResourceID_ELEM:
    return zx_LEN_WO_cb_ResourceID(c, (struct zx_cb_ResourceID_s*)x);
  case zx_cb_EncryptedResourceID_ELEM:
    return zx_LEN_WO_cb_EncryptedResourceID(c, (struct zx_cb_EncryptedResourceID_s*)x);
  case zx_cb_Subscription_ELEM:
    return zx_LEN_WO_cb_Subscription(c, (struct zx_cb_Subscription_s*)x);
  case zx_cb_CreateItem_ELEM:
    return zx_LEN_WO_cb_CreateItem(c, (struct zx_cb_CreateItem_s*)x);
  case zx_cb_ItemSelection_ELEM:
    return zx_LEN_WO_cb_ItemSelection(c, (struct zx_cb_ItemSelection_s*)x);
  case zx_cb_Extension_ELEM:
    return zx_LEN_WO_cb_Extension(c, (struct zx_cb_Extension_s*)x);
  case zx_cb_NewData_ELEM:
    return zx_LEN_WO_cb_NewData(c, (struct zx_cb_NewData_s*)x);
  case zx_cb_Status_ELEM:
    return zx_LEN_WO_cb_Status(c, (struct zx_cb_Status_s*)x);
  case zx_cb_ItemData_ELEM:
    return zx_LEN_WO_cb_ItemData(c, (struct zx_cb_ItemData_s*)x);
  case zx_cb_Card_ELEM:
    return zx_LEN_WO_simple_elem(c, (struct zx_elem_s*)x, sizeof("Card")-1);
  case zx_cb_DeleteItem_ELEM:
    return zx_LEN_WO_cb_DeleteItem(c, (struct zx_cb_DeleteItem_s*)x);
  case zx_cb_Select_ELEM:
    return zx_LEN_WO_simple_elem(c, (struct zx_elem_s*)x, sizeof("Select")-1);
  case zx_xenc_EncryptedData_ELEM:
    return zx_LEN_WO_xenc_EncryptedData(c, (struct zx_xenc_EncryptedData_s*)x);
  case zx_xenc_EncryptedKey_ELEM:
    return zx_LEN_WO_xenc_EncryptedKey(c, (struct zx_xenc_EncryptedKey_s*)x);
  case zx_cb_Modification_ELEM:
    return zx_LEN_WO_cb_Modification(c, (struct zx_cb_Modification_s*)x);
  case zx_cb_Notification_ELEM:
    return zx_LEN_WO_cb_Notification(c, (struct zx_cb_Notification_s*)x);
  case zx_cb_SecurityMechID_ELEM:
    return zx_LEN_WO_simple_elem(c, (struct zx_elem_s*)x, sizeof("SecurityMechID")-1);
  case zx_cb_Credential_ELEM:
    return zx_LEN_WO_cb_Credential(c, (struct zx_cb_Credential_s*)x);
  case zx_cb_Endpoint_ELEM:
    return zx_LEN_WO_simple_elem(c, (struct zx_elem_s*)x, sizeof("Endpoint")-1);
  case zx_cb_QueryItem_ELEM:
    return zx_LEN_WO_cb_QueryItem(c, (struct zx_cb_QueryItem_s*)x);
  case zx_cb_Data_ELEM:
    return zx_LEN_WO_cb_Data(c, (struct zx_cb_Data_s*)x);
  case zx_cdm_CARDID_ELEM:
    return zx_LEN_WO_simple_elem(c, (struct zx_elem_s*)x, sizeof("CARDID")-1);
  case zx_cb_UsageType_ELEM:
    return zx_LEN_WO_cb_UsageType(c, (struct zx_cb_UsageType_s*)x);
  case zx_cb_RefItem_ELEM:
    return zx_LEN_WO_cb_RefItem(c, (struct zx_cb_RefItem_s*)x);
  case zx_cb_NotifyTo_ELEM:
    return zx_LEN_WO_cb_NotifyTo(c, (struct zx_cb_NotifyTo_s*)x);
  case zx_cb_NotifyAdminTo_ELEM:
    return zx_LEN_WO_cb_NotifyAdminTo(c, (struct zx_cb_NotifyAdminTo_s*)x);
  case zx_cb_Aggregation_ELEM:
    return zx_LEN_WO_simple_elem(c, (struct zx_elem_s*)x, sizeof("Aggregation")-1);
  case zx_cb_Trigger_ELEM:
    return zx_LEN_WO_simple_elem(c, (struct zx_elem_s*)x, sizeof("Trigger")-1);
  case zx_cdm_HOME_ELEM:
    return zx_LEN_WO_simple_elem(c, (struct zx_elem_s*)x, sizeof("HOME")-1);
  case zx_cdm_WORK_ELEM:
    return zx_LEN_WO_simple_elem(c, (struct zx_elem_s*)x, sizeof("WORK")-1);
  case zx_cdm_POSTAL_ELEM:
    return zx_LEN_WO_simple_elem(c, (struct zx_elem_s*)x, sizeof("POSTAL")-1);
  case zx_cdm_PARCEL_ELEM:
    return zx_LEN_WO_simple_elem(c, (struct zx_elem_s*)x, sizeof("PARCEL")-1);
  case zx_cdm_DOM_ELEM:
    return zx_LEN_WO_simple_elem(c, (struct zx_elem_s*)x, sizeof("DOM")-1);
  case zx_cdm_INTL_ELEM:
    return zx_LEN_WO_simple_elem(c, (struct zx_elem_s*)x, sizeof("INTL")-1);
  case zx_cdm_PREF_ELEM:
    return zx_LEN_WO_simple_elem(c, (struct zx_elem_s*)x, sizeof("PREF")-1);
  case zx_cdm_POBOX_ELEM:
    return zx_LEN_WO_cdm_POBOX(c, (struct zx_cdm_POBOX_s*)x);
  case zx_cdm_EXTADR_ELEM:
    return zx_LEN_WO_cdm_EXTADR(c, (struct zx_cdm_EXTADR_s*)x);
  case zx_cdm_STREET_ELEM:
    return zx_LEN_WO_cdm_STREET(c, (struct zx_cdm_STREET_s*)x);
  case zx_cdm_LOCALITY_ELEM:
    return zx_LEN_WO_cdm_LOCALITY(c, (struct zx_cdm_LOCALITY_s*)x);
  case zx_cdm_REGION_ELEM:
    return zx_LEN_WO_cdm_REGION(c, (struct zx_cdm_REGION_s*)x);
  case zx_cdm_PCODE_ELEM:
    return zx_LEN_WO_cdm_PCODE(c, (struct zx_cdm_PCODE_s*)x);
  case zx_cdm_CTRY_ELEM:
    return zx_LEN_WO_cdm_CTRY(c, (struct zx_cdm_CTRY_s*)x);
  case zx_cdm_vCard_ELEM:
    return zx_LEN_WO_cdm_vCard(c, (struct zx_cdm_vCard_s*)x);
  case zx_cdm_EXTVAL_ELEM:
    return zx_LEN_WO_cdm_EXTVAL(c, (struct zx_cdm_EXTVAL_s*)x);
  case zx_cdm_URI_ELEM:
    return zx_LEN_WO_cdm_URI(c, (struct zx_cdm_URI_s*)x);
  case zx_cdm_KEYWORD_ELEM:
    return zx_LEN_WO_cdm_KEYWORD(c, (struct zx_cdm_KEYWORD_s*)x);
  case zx_cdm_PUBLIC_ELEM:
    return zx_LEN_WO_simple_elem(c, (struct zx_elem_s*)x, sizeof("PUBLIC")-1);
  case zx_cdm_PRIVATE_ELEM:
    return zx_LEN_WO_simple_elem(c, (struct zx_elem_s*)x, sizeof("PRIVATE")-1);
  case zx_cdm_CONFIDENTIAL_ELEM:
    return zx_LEN_WO_simple_elem(c, (struct zx_elem_s*)x, sizeof("CONFIDENTIAL")-1);
  case zx_cdm_INTERNET_ELEM:
    return zx_LEN_WO_simple_elem(c, (struct zx_elem_s*)x, sizeof("INTERNET")-1);
  case zx_cdm_X400_ELEM:
    return zx_LEN_WO_simple_elem(c, (struct zx_elem_s*)x, sizeof("X400")-1);
  case zx_cdm_USERID_ELEM:
    return zx_LEN_WO_cdm_USERID(c, (struct zx_cdm_USERID_s*)x);
  case zx_cdm_LAT_ELEM:
    return zx_LEN_WO_cdm_LAT(c, (struct zx_cdm_LAT_s*)x);
  case zx_cdm_LON_ELEM:
    return zx_LEN_WO_cdm_LON(c, (struct zx_cdm_LON_s*)x);
  case zx_cdm_TYPE_ELEM:
    return zx_LEN_WO_cdm_TYPE(c, (struct zx_cdm_TYPE_s*)x);
  case zx_cdm_CRED_ELEM:
    return zx_LEN_WO_cdm_CRED(c, (struct zx_cdm_CRED_s*)x);
  case zx_cdm_LINE_ELEM:
    return zx_LEN_WO_cdm_LINE(c, (struct zx_cdm_LINE_s*)x);
  case zx_cdm_BINVAL_ELEM:
    return zx_LEN_WO_cdm_BINVAL(c, (struct zx_cdm_BINVAL_s*)x);
  case zx_cdm_FAMILY_ELEM:
    return zx_LEN_WO_cdm_FAMILY(c, (struct zx_cdm_FAMILY_s*)x);
  case zx_cdm_GIVEN_ELEM:
    return zx_LEN_WO_cdm_GIVEN(c, (struct zx_cdm_GIVEN_s*)x);
  case zx_cdm_MIDDLE_ELEM:
    return zx_LEN_WO_cdm_MIDDLE(c, (struct zx_cdm_MIDDLE_s*)x);
  case zx_cdm_PREFIX_ELEM:
    return zx_LEN_WO_cdm_PREFIX(c, (struct zx_cdm_PREFIX_s*)x);
  case zx_cdm_SUFFIX_ELEM:
    return zx_LEN_WO_cdm_SUFFIX(c, (struct zx_cdm_SUFFIX_s*)x);
  case zx_cdm_ORGNAME_ELEM:
    return zx_LEN_WO_cdm_ORGNAME(c, (struct zx_cdm_ORGNAME_s*)x);
  case zx_cdm_ORGUNIT_ELEM:
    return zx_LEN_WO_cdm_ORGUNIT(c, (struct zx_cdm_ORGUNIT_s*)x);
  case zx_cdm_PHONETIC_ELEM:
    return zx_LEN_WO_cdm_PHONETIC(c, (struct zx_cdm_PHONETIC_s*)x);
  case zx_cdm_VOICE_ELEM:
    return zx_LEN_WO_simple_elem(c, (struct zx_elem_s*)x, sizeof("VOICE")-1);
  case zx_cdm_FAX_ELEM:
    return zx_LEN_WO_simple_elem(c, (struct zx_elem_s*)x, sizeof("FAX")-1);
  case zx_cdm_PAGER_ELEM:
    return zx_LEN_WO_simple_elem(c, (struct zx_elem_s*)x, sizeof("PAGER")-1);
  case zx_cdm_MSG_ELEM:
    return zx_LEN_WO_simple_elem(c, (struct zx_elem_s*)x, sizeof("MSG")-1);
  case zx_cdm_CELL_ELEM:
    return zx_LEN_WO_simple_elem(c, (struct zx_elem_s*)x, sizeof("CELL")-1);
  case zx_cdm_VIDEO_ELEM:
    return zx_LEN_WO_simple_elem(c, (struct zx_elem_s*)x, sizeof("VIDEO")-1);
  case zx_cdm_BBS_ELEM:
    return zx_LEN_WO_simple_elem(c, (struct zx_elem_s*)x, sizeof("BBS")-1);
  case zx_cdm_MODEM_ELEM:
    return zx_LEN_WO_simple_elem(c, (struct zx_elem_s*)x, sizeof("MODEM")-1);
  case zx_cdm_ISDN_ELEM:
    return zx_LEN_WO_simple_elem(c, (struct zx_elem_s*)x, sizeof("ISDN")-1);
  case zx_cdm_PCS_ELEM:
    return zx_LEN_WO_simple_elem(c, (struct zx_elem_s*)x, sizeof("PCS")-1);
  case zx_cdm_NUMBER_ELEM:
    return zx_LEN_WO_cdm_NUMBER(c, (struct zx_cdm_NUMBER_s*)x);
  case zx_cdm_VERSION_ELEM:
    return zx_LEN_WO_cdm_VERSION(c, (struct zx_cdm_VERSION_s*)x);
  case zx_cdm_DISTRIBUTIONLIST_ELEM:
    return zx_LEN_WO_simple_elem(c, (struct zx_elem_s*)x, sizeof("DISTRIBUTIONLIST")-1);
  case zx_cdm_SELF_ELEM:
    return zx_LEN_WO_simple_elem(c, (struct zx_elem_s*)x, sizeof("SELF")-1);
  case zx_cdm_FAVORITE_ELEM:
    return zx_LEN_WO_simple_elem(c, (struct zx_elem_s*)x, sizeof("FAVORITE")-1);
  case zx_cdm_FN_ELEM:
    return zx_LEN_WO_cdm_FN(c, (struct zx_cdm_FN_s*)x);
  case zx_cdm_N_ELEM:
    return zx_LEN_WO_cdm_N(c, (struct zx_cdm_N_s*)x);
  case zx_cdm_LISTMEMBER_ELEM:
    return zx_LEN_WO_cdm_LISTMEMBER(c, (struct zx_cdm_LISTMEMBER_s*)x);
  case zx_cdm_NICKNAME_ELEM:
    return zx_LEN_WO_cdm_NICKNAME(c, (struct zx_cdm_NICKNAME_s*)x);
  case zx_cdm_PHOTO_ELEM:
    return zx_LEN_WO_cdm_PHOTO(c, (struct zx_cdm_PHOTO_s*)x);
  case zx_cdm_BDAY_ELEM:
    return zx_LEN_WO_cdm_BDAY(c, (struct zx_cdm_BDAY_s*)x);
  case zx_cdm_ADR_ELEM:
    return zx_LEN_WO_cdm_ADR(c, (struct zx_cdm_ADR_s*)x);
  case zx_cdm_LABEL_ELEM:
    return zx_LEN_WO_cdm_LABEL(c, (struct zx_cdm_LABEL_s*)x);
  case zx_cdm_TEL_ELEM:
    return zx_LEN_WO_cdm_TEL(c, (struct zx_cdm_TEL_s*)x);
  case zx_cdm_EMAIL_ELEM:
    return zx_LEN_WO_cdm_EMAIL(c, (struct zx_cdm_EMAIL_s*)x);
  case zx_cdm_JABBERID_ELEM:
    return zx_LEN_WO_cdm_JABBERID(c, (struct zx_cdm_JABBERID_s*)x);
  case zx_cdm_MAILER_ELEM:
    return zx_LEN_WO_cdm_MAILER(c, (struct zx_cdm_MAILER_s*)x);
  case zx_cdm_TZ_ELEM:
    return zx_LEN_WO_cdm_TZ(c, (struct zx_cdm_TZ_s*)x);
  case zx_cdm_GEO_ELEM:
    return zx_LEN_WO_cdm_GEO(c, (struct zx_cdm_GEO_s*)x);
  case zx_cdm_TITLE_ELEM:
    return zx_LEN_WO_cdm_TITLE(c, (struct zx_cdm_TITLE_s*)x);
  case zx_cdm_ROLE_ELEM:
    return zx_LEN_WO_cdm_ROLE(c, (struct zx_cdm_ROLE_s*)x);
  case zx_cdm_LOGO_ELEM:
    return zx_LEN_WO_cdm_LOGO(c, (struct zx_cdm_LOGO_s*)x);
  case zx_cdm_AGENT_ELEM:
    return zx_LEN_WO_cdm_AGENT(c, (struct zx_cdm_AGENT_s*)x);
  case zx_cdm_ORG_ELEM:
    return zx_LEN_WO_cdm_ORG(c, (struct zx_cdm_ORG_s*)x);
  case zx_cdm_CATEGORIES_ELEM:
    return zx_LEN_WO_cdm_CATEGORIES(c, (struct zx_cdm_CATEGORIES_s*)x);
  case zx_cdm_NOTE_ELEM:
    return zx_LEN_WO_cdm_NOTE(c, (struct zx_cdm_NOTE_s*)x);
  case zx_cdm_PRODID_ELEM:
    return zx_LEN_WO_cdm_PRODID(c, (struct zx_cdm_PRODID_s*)x);
  case zx_cdm_REV_ELEM:
    return zx_LEN_WO_cdm_REV(c, (struct zx_cdm_REV_s*)x);
  case zx_cdm_SORT_STRING_ELEM:
    return zx_LEN_WO_cdm_SORT_STRING(c, (struct zx_cdm_SORT_STRING_s*)x);
  case zx_cdm_SOUND_ELEM:
    return zx_LEN_WO_cdm_SOUND(c, (struct zx_cdm_SOUND_s*)x);
  case zx_cdm_UID_ELEM:
    return zx_LEN_WO_cdm_UID(c, (struct zx_cdm_UID_s*)x);
  case zx_cdm_URL_ELEM:
    return zx_LEN_WO_cdm_URL(c, (struct zx_cdm_URL_s*)x);
  case zx_cdm_CLASS_ELEM:
    return zx_LEN_WO_cdm_CLASS(c, (struct zx_cdm_CLASS_s*)x);
  case zx_cdm_KEY_ELEM:
    return zx_LEN_WO_cdm_KEY(c, (struct zx_cdm_KEY_s*)x);
  case zx_cdm_DESC_ELEM:
    return zx_LEN_WO_cdm_DESC(c, (struct zx_cdm_DESC_s*)x);
  case zx_cdm_PHYSICALACCESS_ELEM:
    return zx_LEN_WO_cdm_PHYSICALACCESS(c, (struct zx_cdm_PHYSICALACCESS_s*)x);
  case zx_cdm_CALURI_ELEM:
    return zx_LEN_WO_cdm_CALURI(c, (struct zx_cdm_CALURI_s*)x);
  case zx_cdm_CAPURI_ELEM:
    return zx_LEN_WO_cdm_CAPURI(c, (struct zx_cdm_CAPURI_s*)x);
  case zx_cdm_CALADRURI_ELEM:
    return zx_LEN_WO_cdm_CALADRURI(c, (struct zx_cdm_CALADRURI_s*)x);
  case zx_cdm_FBURL_ELEM:
    return zx_LEN_WO_cdm_FBURL(c, (struct zx_cdm_FBURL_s*)x);
  case zx_lu_Extension_ELEM:
    return zx_LEN_WO_lu_Extension(c, (struct zx_lu_Extension_s*)x);
  case zx_dap_Subscription_ELEM:
    return zx_LEN_WO_dap_Subscription(c, (struct zx_dap_Subscription_s*)x);
  case zx_dap_CreateItem_ELEM:
    return zx_LEN_WO_dap_CreateItem(c, (struct zx_dap_CreateItem_s*)x);
  case zx_dap_ResultQuery_ELEM:
    return zx_LEN_WO_dap_ResultQuery(c, (struct zx_dap_ResultQuery_s*)x);
  case zx_dap_NewData_ELEM:
    return zx_LEN_WO_dap_NewData(c, (struct zx_dap_NewData_s*)x);
  case zx_dap_ItemData_ELEM:
    return zx_LEN_WO_dap_ItemData(c, (struct zx_dap_ItemData_s*)x);
  case zx_dap_LDIF_ELEM:
    return zx_LEN_WO_dap_LDIF(c, (struct zx_dap_LDIF_s*)x);
  case zx_dap_DeleteItem_ELEM:
    return zx_LEN_WO_dap_DeleteItem(c, (struct zx_dap_DeleteItem_s*)x);
  case zx_dap_Select_ELEM:
    return zx_LEN_WO_dap_Select(c, (struct zx_dap_Select_s*)x);
  case zx_dap_ModifyItem_ELEM:
    return zx_LEN_WO_dap_ModifyItem(c, (struct zx_dap_ModifyItem_s*)x);
  case zx_lu_TestResult_ELEM:
    return zx_LEN_WO_lu_TestResult(c, (struct zx_lu_TestResult_s*)x);
  case zx_dap_Notification_ELEM:
    return zx_LEN_WO_dap_Notification(c, (struct zx_dap_Notification_s*)x);
  case zx_dap_TestItem_ELEM:
    return zx_LEN_WO_dap_TestItem(c, (struct zx_dap_TestItem_s*)x);
  case zx_dap_QueryItem_ELEM:
    return zx_LEN_WO_dap_QueryItem(c, (struct zx_dap_QueryItem_s*)x);
  case zx_dst_ChangeFormat_ELEM:
    return zx_LEN_WO_simple_elem(c, (struct zx_elem_s*)x, sizeof("ChangeFormat")-1);
  case zx_dap_Sort_ELEM:
    return zx_LEN_WO_simple_elem(c, (struct zx_elem_s*)x, sizeof("Sort")-1);
  case zx_dst_TestResult_ELEM:
    return zx_LEN_WO_dst_TestResult(c, (struct zx_dst_TestResult_s*)x);
  case zx_dap_Data_ELEM:
    return zx_LEN_WO_dap_Data(c, (struct zx_dap_Data_s*)x);
  case zx_dap_dn_ELEM:
    return zx_LEN_WO_simple_elem(c, (struct zx_elem_s*)x, sizeof("dn")-1);
  case zx_dap_filter_ELEM:
    return zx_LEN_WO_simple_elem(c, (struct zx_elem_s*)x, sizeof("filter")-1);
  case zx_subs_RefItem_ELEM:
    return zx_LEN_WO_subs_RefItem(c, (struct zx_subs_RefItem_s*)x);
  case zx_dap_Aggregation_ELEM:
    return zx_LEN_WO_simple_elem(c, (struct zx_elem_s*)x, sizeof("Aggregation")-1);
  case zx_dap_Trigger_ELEM:
    return zx_LEN_WO_simple_elem(c, (struct zx_elem_s*)x, sizeof("Trigger")-1);
  case zx_dap_TestOp_ELEM:
    return zx_LEN_WO_dap_TestOp(c, (struct zx_dap_TestOp_s*)x);
  case zx_demomed_ObjectID_ELEM:
    return zx_LEN_WO_simple_elem(c, (struct zx_elem_s*)x, sizeof("ObjectID")-1);
  case zx_demomed_Count_ELEM:
    return zx_LEN_WO_simple_elem(c, (struct zx_elem_s*)x, sizeof("Count")-1);
  case zx_demomed_ObjectSearchParm_ELEM:
    return zx_LEN_WO_demomed_ObjectSearchParm(c, (struct zx_demomed_ObjectSearchParm_s*)x);
  case zx_demomed_ObjectInfo_ELEM:
    return zx_LEN_WO_demomed_ObjectInfo(c, (struct zx_demomed_ObjectInfo_s*)x);
  case zx_demomed_ObjectData_ELEM:
    return zx_LEN_WO_demomed_ObjectData(c, (struct zx_demomed_ObjectData_s*)x);
  case zx_demomed_Dir_ELEM:
    return zx_LEN_WO_simple_elem(c, (struct zx_elem_s*)x, sizeof("Dir")-1);
  case zx_demomed_Name_ELEM:
    return zx_LEN_WO_simple_elem(c, (struct zx_elem_s*)x, sizeof("Name")-1);
  case zx_demomed_Type_ELEM:
    return zx_LEN_WO_simple_elem(c, (struct zx_elem_s*)x, sizeof("Type")-1);
  case zx_demomed_Created_ELEM:
    return zx_LEN_WO_simple_elem(c, (struct zx_elem_s*)x, sizeof("Created")-1);
  case zx_demomed_Comment_ELEM:
    return zx_LEN_WO_simple_elem(c, (struct zx_elem_s*)x, sizeof("Comment")-1);
  case zx_demomed_objectID_ELEM:
    return zx_LEN_WO_simple_elem(c, (struct zx_elem_s*)x, sizeof("objectID")-1);
  case zx_demomed_Object_ELEM:
    return zx_LEN_WO_demomed_Object(c, (struct zx_demomed_Object_s*)x);
  case zx_demomed_ObjectStoreInfo_ELEM:
    return zx_LEN_WO_demomed_ObjectStoreInfo(c, (struct zx_demomed_ObjectStoreInfo_s*)x);
  case zx_di_Address_ELEM:
    return zx_LEN_WO_simple_elem(c, (struct zx_elem_s*)x, sizeof("Address")-1);
  case zx_di_SecurityMechID_ELEM:
    return zx_LEN_WO_simple_elem(c, (struct zx_elem_s*)x, sizeof("SecurityMechID")-1);
  case zx_di_Action_ELEM:
    return zx_LEN_WO_simple_elem(c, (struct zx_elem_s*)x, sizeof("Action")-1);
  case zx_md_KeyDescriptor_ELEM:
    return zx_LEN_WO_md_KeyDescriptor(c, (struct zx_md_KeyDescriptor_s*)x);
  case zx_di_Option_ELEM:
    return zx_LEN_WO_simple_elem(c, (struct zx_elem_s*)x, sizeof("Option")-1);
  case zx_di_RequestedService_ELEM:
    return zx_LEN_WO_di_RequestedService(c, (struct zx_di_RequestedService_s*)x);
  case zx_di_Options_ELEM:
    return zx_LEN_WO_di_Options(c, (struct zx_di_Options_s*)x);
  case zx_di_Framework_ELEM:
    return zx_LEN_WO_di_Framework(c, (struct zx_di_Framework_s*)x);
  case zx_sec_Token_ELEM:
    return zx_LEN_WO_sec_Token(c, (struct zx_sec_Token_s*)x);
  case zx_di_EndpointContext_ELEM:
    return zx_LEN_WO_di_EndpointContext(c, (struct zx_di_EndpointContext_s*)x);
  case zx_di_ServiceContext_ELEM:
    return zx_LEN_WO_di_ServiceContext(c, (struct zx_di_ServiceContext_s*)x);
  case zx_di_SvcMDID_ELEM:
    return zx_LEN_WO_simple_elem(c, (struct zx_elem_s*)x, sizeof("SvcMDID")-1);
  case zx_di_SvcMD_ELEM:
    return zx_LEN_WO_di_SvcMD(c, (struct zx_di_SvcMD_s*)x);
  case zx_di_Keys_ELEM:
    return zx_LEN_WO_di_Keys(c, (struct zx_di_Keys_s*)x);
  case zx_di12_SecurityMechID_ELEM:
    return zx_LEN_WO_simple_elem(c, (struct zx_elem_s*)x, sizeof("SecurityMechID")-1);
  case zx_di12_CredentialRef_ELEM:
    return zx_LEN_WO_simple_elem(c, (struct zx_elem_s*)x, sizeof("CredentialRef")-1);
  case zx_di12_WsdlURI_ELEM:
    return zx_LEN_WO_simple_elem(c, (struct zx_elem_s*)x, sizeof("WsdlURI")-1);
  case zx_di12_ServiceNameRef_ELEM:
    return zx_LEN_WO_simple_elem(c, (struct zx_elem_s*)x, sizeof("ServiceNameRef")-1);
  case zx_di12_Endpoint_ELEM:
    return zx_LEN_WO_simple_elem(c, (struct zx_elem_s*)x, sizeof("Endpoint")-1);
  case zx_di12_SoapAction_ELEM:
    return zx_LEN_WO_simple_elem(c, (struct zx_elem_s*)x, sizeof("SoapAction")-1);
  case zx_di12_ResourceOffering_ELEM:
    return zx_LEN_WO_di12_ResourceOffering(c, (struct zx_di12_ResourceOffering_s*)x);
  case zx_di12_ResourceID_ELEM:
    return zx_LEN_WO_di12_ResourceID(c, (struct zx_di12_ResourceID_s*)x);
  case zx_di12_EncryptedResourceID_ELEM:
    return zx_LEN_WO_di12_EncryptedResourceID(c, (struct zx_di12_EncryptedResourceID_s*)x);
  case zx_di12_InsertEntry_ELEM:
    return zx_LEN_WO_di12_InsertEntry(c, (struct zx_di12_InsertEntry_s*)x);
  case zx_di12_RemoveEntry_ELEM:
    return zx_LEN_WO_di12_RemoveEntry(c, (struct zx_di12_RemoveEntry_s*)x);
  case zx_di12_Status_ELEM:
    return zx_LEN_WO_di12_Status(c, (struct zx_di12_Status_s*)x);
  case zx_di12_Extension_ELEM:
    return zx_LEN_WO_di12_Extension(c, (struct zx_di12_Extension_s*)x);
  case zx_di12_Option_ELEM:
    return zx_LEN_WO_simple_elem(c, (struct zx_elem_s*)x, sizeof("Option")-1);
  case zx_di12_RequestedServiceType_ELEM:
    return zx_LEN_WO_di12_RequestedServiceType(c, (struct zx_di12_RequestedServiceType_s*)x);
  case zx_di12_Credentials_ELEM:
    return zx_LEN_WO_di12_Credentials(c, (struct zx_di12_Credentials_s*)x);
  case zx_di12_ServiceType_ELEM:
    return zx_LEN_WO_simple_elem(c, (struct zx_elem_s*)x, sizeof("ServiceType")-1);
  case zx_di12_Options_ELEM:
    return zx_LEN_WO_di12_Options(c, (struct zx_di12_Options_s*)x);
  case zx_di12_ServiceInstance_ELEM:
    return zx_LEN_WO_di12_ServiceInstance(c, (struct zx_di12_ServiceInstance_s*)x);
  case zx_di12_Abstract_ELEM:
    return zx_LEN_WO_simple_elem(c, (struct zx_elem_s*)x, sizeof("Abstract")-1);
  case zx_di12_ProviderID_ELEM:
    return zx_LEN_WO_simple_elem(c, (struct zx_elem_s*)x, sizeof("ProviderID")-1);
  case zx_di12_Description_ELEM:
    return zx_LEN_WO_di12_Description(c, (struct zx_di12_Description_s*)x);
  case zx_ds_P_ELEM:
    return zx_LEN_WO_simple_elem(c, (struct zx_elem_s*)x, sizeof("P")-1);
  case zx_ds_Q_ELEM:
    return zx_LEN_WO_simple_elem(c, (struct zx_elem_s*)x, sizeof("Q")-1);
  case zx_ds_G_ELEM:
    return zx_LEN_WO_simple_elem(c, (struct zx_elem_s*)x, sizeof("G")-1);
  case zx_ds_Y_ELEM:
    return zx_LEN_WO_simple_elem(c, (struct zx_elem_s*)x, sizeof("Y")-1);
  case zx_ds_J_ELEM:
    return zx_LEN_WO_simple_elem(c, (struct zx_elem_s*)x, sizeof("J")-1);
  case zx_ds_Seed_ELEM:
    return zx_LEN_WO_simple_elem(c, (struct zx_elem_s*)x, sizeof("Seed")-1);
  case zx_ds_PgenCounter_ELEM:
    return zx_LEN_WO_simple_elem(c, (struct zx_elem_s*)x, sizeof("PgenCounter")-1);
  case zx_ds_KeyName_ELEM:
    return zx_LEN_WO_simple_elem(c, (struct zx_elem_s*)x, sizeof("KeyName")-1);
  case zx_ds_KeyValue_ELEM:
    return zx_LEN_WO_ds_KeyValue(c, (struct zx_ds_KeyValue_s*)x);
  case zx_ds_RetrievalMethod_ELEM:
    return zx_LEN_WO_ds_RetrievalMethod(c, (struct zx_ds_RetrievalMethod_s*)x);
  case zx_ds_X509Data_ELEM:
    return zx_LEN_WO_ds_X509Data(c, (struct zx_ds_X509Data_s*)x);
  case zx_ds_PGPData_ELEM:
    return zx_LEN_WO_ds_PGPData(c, (struct zx_ds_PGPData_s*)x);
  case zx_ds_SPKIData_ELEM:
    return zx_LEN_WO_ds_SPKIData(c, (struct zx_ds_SPKIData_s*)x);
  case zx_ds_MgmtData_ELEM:
    return zx_LEN_WO_simple_elem(c, (struct zx_elem_s*)x, sizeof("MgmtData")-1);
  case zx_ds_DSAKeyValue_ELEM:
    return zx_LEN_WO_ds_DSAKeyValue(c, (struct zx_ds_DSAKeyValue_s*)x);
  case zx_ds_RSAKeyValue_ELEM:
    return zx_LEN_WO_ds_RSAKeyValue(c, (struct zx_ds_RSAKeyValue_s*)x);
  case zx_ds_Reference_ELEM:
    return zx_LEN_WO_ds_Reference(c, (struct zx_ds_Reference_s*)x);
  case zx_ds_PGPKeyID_ELEM:
    return zx_LEN_WO_simple_elem(c, (struct zx_elem_s*)x, sizeof("PGPKeyID")-1);
  case zx_ds_PGPKeyPacket_ELEM:
    return zx_LEN_WO_simple_elem(c, (struct zx_elem_s*)x, sizeof("PGPKeyPacket")-1);
  case zx_ds_Modulus_ELEM:
    return zx_LEN_WO_simple_elem(c, (struct zx_elem_s*)x, sizeof("Modulus")-1);
  case zx_ds_Exponent_ELEM:
    return zx_LEN_WO_simple_elem(c, (struct zx_elem_s*)x, sizeof("Exponent")-1);
  case zx_ds_Transforms_ELEM:
    return zx_LEN_WO_ds_Transforms(c, (struct zx_ds_Transforms_s*)x);
  case zx_ds_DigestMethod_ELEM:
    return zx_LEN_WO_ds_DigestMethod(c, (struct zx_ds_DigestMethod_s*)x);
  case zx_ds_DigestValue_ELEM:
    return zx_LEN_WO_simple_elem(c, (struct zx_elem_s*)x, sizeof("DigestValue")-1);
  case zx_ds_SPKISexp_ELEM:
    return zx_LEN_WO_simple_elem(c, (struct zx_elem_s*)x, sizeof("SPKISexp")-1);
  case zx_ds_SignedInfo_ELEM:
    return zx_LEN_WO_ds_SignedInfo(c, (struct zx_ds_SignedInfo_s*)x);
  case zx_ds_SignatureValue_ELEM:
    return zx_LEN_WO_ds_SignatureValue(c, (struct zx_ds_SignatureValue_s*)x);
  case zx_ds_KeyInfo_ELEM:
    return zx_LEN_WO_ds_KeyInfo(c, (struct zx_ds_KeyInfo_s*)x);
  case zx_ds_Object_ELEM:
    return zx_LEN_WO_ds_Object(c, (struct zx_ds_Object_s*)x);
  case zx_ds_HMACOutputLength_ELEM:
    return zx_LEN_WO_simple_elem(c, (struct zx_elem_s*)x, sizeof("HMACOutputLength")-1);
  case zx_ds_SignatureProperty_ELEM:
    return zx_LEN_WO_ds_SignatureProperty(c, (struct zx_ds_SignatureProperty_s*)x);
  case zx_ds_CanonicalizationMethod_ELEM:
    return zx_LEN_WO_ds_CanonicalizationMethod(c, (struct zx_ds_CanonicalizationMethod_s*)x);
  case zx_ds_SignatureMethod_ELEM:
    return zx_LEN_WO_ds_SignatureMethod(c, (struct zx_ds_SignatureMethod_s*)x);
  case zx_ds_XPath_ELEM:
    return zx_LEN_WO_simple_elem(c, (struct zx_elem_s*)x, sizeof("XPath")-1);
  case zx_exca_InclusiveNamespaces_ELEM:
    return zx_LEN_WO_exca_InclusiveNamespaces(c, (struct zx_exca_InclusiveNamespaces_s*)x);
  case zx_ds_Transform_ELEM:
    return zx_LEN_WO_ds_Transform(c, (struct zx_ds_Transform_s*)x);
  case zx_ds_X509IssuerSerial_ELEM:
    return zx_LEN_WO_ds_X509IssuerSerial(c, (struct zx_ds_X509IssuerSerial_s*)x);
  case zx_ds_X509SKI_ELEM:
    return zx_LEN_WO_simple_elem(c, (struct zx_elem_s*)x, sizeof("X509SKI")-1);
  case zx_ds_X509SubjectName_ELEM:
    return zx_LEN_WO_simple_elem(c, (struct zx_elem_s*)x, sizeof("X509SubjectName")-1);
  case zx_ds_X509Certificate_ELEM:
    return zx_LEN_WO_simple_elem(c, (struct zx_elem_s*)x, sizeof("X509Certificate")-1);
  case zx_ds_X509CRL_ELEM:
    return zx_LEN_WO_simple_elem(c, (struct zx_elem_s*)x, sizeof("X509CRL")-1);
  case zx_ds_X509IssuerName_ELEM:
    return zx_LEN_WO_simple_elem(c, (struct zx_elem_s*)x, sizeof("X509IssuerName")-1);
  case zx_ds_X509SerialNumber_ELEM:
    return zx_LEN_WO_simple_elem(c, (struct zx_elem_s*)x, sizeof("X509SerialNumber")-1);
  case zx_sp_ArtifactResolve_ELEM:
    return zx_LEN_WO_sp_ArtifactResolve(c, (struct zx_sp_ArtifactResolve_s*)x);
  case zx_sp_ArtifactResponse_ELEM:
    return zx_LEN_WO_sp_ArtifactResponse(c, (struct zx_sp_ArtifactResponse_s*)x);
  case zx_sp_ManageNameIDRequest_ELEM:
    return zx_LEN_WO_sp_ManageNameIDRequest(c, (struct zx_sp_ManageNameIDRequest_s*)x);
  case zx_sp_ManageNameIDResponse_ELEM:
    return zx_LEN_WO_sp_ManageNameIDResponse(c, (struct zx_sp_ManageNameIDResponse_s*)x);
  case zx_sp_LogoutRequest_ELEM:
    return zx_LEN_WO_sp_LogoutRequest(c, (struct zx_sp_LogoutRequest_s*)x);
  case zx_sp_LogoutResponse_ELEM:
    return zx_LEN_WO_sp_LogoutResponse(c, (struct zx_sp_LogoutResponse_s*)x);
  case zx_sp_NameIDMappingRequest_ELEM:
    return zx_LEN_WO_sp_NameIDMappingRequest(c, (struct zx_sp_NameIDMappingRequest_s*)x);
  case zx_sp_NameIDMappingResponse_ELEM:
    return zx_LEN_WO_sp_NameIDMappingResponse(c, (struct zx_sp_NameIDMappingResponse_s*)x);
  case zx_sp_AttributeQuery_ELEM:
    return zx_LEN_WO_sp_AttributeQuery(c, (struct zx_sp_AttributeQuery_s*)x);
  case zx_sp_AuthnQuery_ELEM:
    return zx_LEN_WO_sp_AuthnQuery(c, (struct zx_sp_AuthnQuery_s*)x);
  case zx_sp_AuthzDecisionQuery_ELEM:
    return zx_LEN_WO_sp_AuthzDecisionQuery(c, (struct zx_sp_AuthzDecisionQuery_s*)x);
  case zx_sp_AssertionIDRequest_ELEM:
    return zx_LEN_WO_sp_AssertionIDRequest(c, (struct zx_sp_AssertionIDRequest_s*)x);
  case zx_sp_Response_ELEM:
    return zx_LEN_WO_sp_Response(c, (struct zx_sp_Response_s*)x);
  case zx_sp_AuthnRequest_ELEM:
    return zx_LEN_WO_sp_AuthnRequest(c, (struct zx_sp_AuthnRequest_s*)x);
  case zx_sp11_Request_ELEM:
    return zx_LEN_WO_sp11_Request(c, (struct zx_sp11_Request_s*)x);
  case zx_sp11_Response_ELEM:
    return zx_LEN_WO_sp11_Response(c, (struct zx_sp11_Response_s*)x);
  case zx_ff12_RegisterNameIdentifierRequest_ELEM:
    return zx_LEN_WO_ff12_RegisterNameIdentifierRequest(c, (struct zx_ff12_RegisterNameIdentifierRequest_s*)x);
  case zx_ff12_RegisterNameIdentifierResponse_ELEM:
    return zx_LEN_WO_ff12_RegisterNameIdentifierResponse(c, (struct zx_ff12_RegisterNameIdentifierResponse_s*)x);
  case zx_ff12_FederationTerminationNotification_ELEM:
    return zx_LEN_WO_ff12_FederationTerminationNotification(c, (struct zx_ff12_FederationTerminationNotification_s*)x);
  case zx_ff12_LogoutRequest_ELEM:
    return zx_LEN_WO_ff12_LogoutRequest(c, (struct zx_ff12_LogoutRequest_s*)x);
  case zx_ff12_LogoutResponse_ELEM:
    return zx_LEN_WO_ff12_LogoutResponse(c, (struct zx_ff12_LogoutResponse_s*)x);
  case zx_ff12_NameIdentifierMappingRequest_ELEM:
    return zx_LEN_WO_ff12_NameIdentifierMappingRequest(c, (struct zx_ff12_NameIdentifierMappingRequest_s*)x);
  case zx_ff12_NameIdentifierMappingResponse_ELEM:
    return zx_LEN_WO_ff12_NameIdentifierMappingResponse(c, (struct zx_ff12_NameIdentifierMappingResponse_s*)x);
  case zx_xasp_XACMLAuthzDecisionQuery_ELEM:
    return zx_LEN_WO_xasp_XACMLAuthzDecisionQuery(c, (struct zx_xasp_XACMLAuthzDecisionQuery_s*)x);
  case zx_xasp_XACMLPolicyQuery_ELEM:
    return zx_LEN_WO_xasp_XACMLPolicyQuery(c, (struct zx_xasp_XACMLPolicyQuery_s*)x);
  case zx_xaspcd1_XACMLAuthzDecisionQuery_ELEM:
    return zx_LEN_WO_xaspcd1_XACMLAuthzDecisionQuery(c, (struct zx_xaspcd1_XACMLAuthzDecisionQuery_s*)x);
  case zx_xaspcd1_XACMLPolicyQuery_ELEM:
    return zx_LEN_WO_xaspcd1_XACMLPolicyQuery(c, (struct zx_xaspcd1_XACMLPolicyQuery_s*)x);
  case zx_xac_Request_ELEM:
    return zx_LEN_WO_xac_Request(c, (struct zx_xac_Request_s*)x);
  case zx_xac_Response_ELEM:
    return zx_LEN_WO_xac_Response(c, (struct zx_xac_Response_s*)x);
  case zx_di_Query_ELEM:
    return zx_LEN_WO_di_Query(c, (struct zx_di_Query_s*)x);
  case zx_di_QueryResponse_ELEM:
    return zx_LEN_WO_di_QueryResponse(c, (struct zx_di_QueryResponse_s*)x);
  case zx_di12_Query_ELEM:
    return zx_LEN_WO_di12_Query(c, (struct zx_di12_Query_s*)x);
  case zx_di12_QueryResponse_ELEM:
    return zx_LEN_WO_di12_QueryResponse(c, (struct zx_di12_QueryResponse_s*)x);
  case zx_di12_Modify_ELEM:
    return zx_LEN_WO_di12_Modify(c, (struct zx_di12_Modify_s*)x);
  case zx_di12_ModifyResponse_ELEM:
    return zx_LEN_WO_di12_ModifyResponse(c, (struct zx_di12_ModifyResponse_s*)x);
  case zx_e_Fault_ELEM:
    return zx_LEN_WO_e_Fault(c, (struct zx_e_Fault_s*)x);
  case zx_di_SvcMDAssociationAdd_ELEM:
    return zx_LEN_WO_di_SvcMDAssociationAdd(c, (struct zx_di_SvcMDAssociationAdd_s*)x);
  case zx_di_SvcMDAssociationAddResponse_ELEM:
    return zx_LEN_WO_di_SvcMDAssociationAddResponse(c, (struct zx_di_SvcMDAssociationAddResponse_s*)x);
  case zx_di_SvcMDAssociationDelete_ELEM:
    return zx_LEN_WO_di_SvcMDAssociationDelete(c, (struct zx_di_SvcMDAssociationDelete_s*)x);
  case zx_di_SvcMDAssociationDeleteResponse_ELEM:
    return zx_LEN_WO_di_SvcMDAssociationDeleteResponse(c, (struct zx_di_SvcMDAssociationDeleteResponse_s*)x);
  case zx_di_SvcMDAssociationQuery_ELEM:
    return zx_LEN_WO_di_SvcMDAssociationQuery(c, (struct zx_di_SvcMDAssociationQuery_s*)x);
  case zx_di_SvcMDAssociationQueryResponse_ELEM:
    return zx_LEN_WO_di_SvcMDAssociationQueryResponse(c, (struct zx_di_SvcMDAssociationQueryResponse_s*)x);
  case zx_di_SvcMDRegister_ELEM:
    return zx_LEN_WO_di_SvcMDRegister(c, (struct zx_di_SvcMDRegister_s*)x);
  case zx_di_SvcMDRegisterResponse_ELEM:
    return zx_LEN_WO_di_SvcMDRegisterResponse(c, (struct zx_di_SvcMDRegisterResponse_s*)x);
  case zx_di_SvcMDDelete_ELEM:
    return zx_LEN_WO_di_SvcMDDelete(c, (struct zx_di_SvcMDDelete_s*)x);
  case zx_di_SvcMDDeleteResponse_ELEM:
    return zx_LEN_WO_di_SvcMDDeleteResponse(c, (struct zx_di_SvcMDDeleteResponse_s*)x);
  case zx_di_SvcMDQuery_ELEM:
    return zx_LEN_WO_di_SvcMDQuery(c, (struct zx_di_SvcMDQuery_s*)x);
  case zx_di_SvcMDQueryResponse_ELEM:
    return zx_LEN_WO_di_SvcMDQueryResponse(c, (struct zx_di_SvcMDQueryResponse_s*)x);
  case zx_di_SvcMDReplace_ELEM:
    return zx_LEN_WO_di_SvcMDReplace(c, (struct zx_di_SvcMDReplace_s*)x);
  case zx_di_SvcMDReplaceResponse_ELEM:
    return zx_LEN_WO_di_SvcMDReplaceResponse(c, (struct zx_di_SvcMDReplaceResponse_s*)x);
  case zx_dap_Create_ELEM:
    return zx_LEN_WO_dap_Create(c, (struct zx_dap_Create_s*)x);
  case zx_dap_CreateResponse_ELEM:
    return zx_LEN_WO_dap_CreateResponse(c, (struct zx_dap_CreateResponse_s*)x);
  case zx_dap_Query_ELEM:
    return zx_LEN_WO_dap_Query(c, (struct zx_dap_Query_s*)x);
  case zx_dap_QueryResponse_ELEM:
    return zx_LEN_WO_dap_QueryResponse(c, (struct zx_dap_QueryResponse_s*)x);
  case zx_dap_Modify_ELEM:
    return zx_LEN_WO_dap_Modify(c, (struct zx_dap_Modify_s*)x);
  case zx_dap_ModifyResponse_ELEM:
    return zx_LEN_WO_dap_ModifyResponse(c, (struct zx_dap_ModifyResponse_s*)x);
  case zx_dap_Delete_ELEM:
    return zx_LEN_WO_dap_Delete(c, (struct zx_dap_Delete_s*)x);
  case zx_dap_DeleteResponse_ELEM:
    return zx_LEN_WO_dap_DeleteResponse(c, (struct zx_dap_DeleteResponse_s*)x);
  case zx_dap_Notify_ELEM:
    return zx_LEN_WO_dap_Notify(c, (struct zx_dap_Notify_s*)x);
  case zx_dap_NotifyResponse_ELEM:
    return zx_LEN_WO_dap_NotifyResponse(c, (struct zx_dap_NotifyResponse_s*)x);
  case zx_ps_AddEntityRequest_ELEM:
    return zx_LEN_WO_ps_AddEntityRequest(c, (struct zx_ps_AddEntityRequest_s*)x);
  case zx_ps_AddEntityResponse_ELEM:
    return zx_LEN_WO_ps_AddEntityResponse(c, (struct zx_ps_AddEntityResponse_s*)x);
  case zx_ps_AddKnownEntityRequest_ELEM:
    return zx_LEN_WO_ps_AddKnownEntityRequest(c, (struct zx_ps_AddKnownEntityRequest_s*)x);
  case zx_ps_AddKnownEntityResponse_ELEM:
    return zx_LEN_WO_ps_AddKnownEntityResponse(c, (struct zx_ps_AddKnownEntityResponse_s*)x);
  case zx_ps_AddCollectionRequest_ELEM:
    return zx_LEN_WO_ps_AddCollectionRequest(c, (struct zx_ps_AddCollectionRequest_s*)x);
  case zx_ps_AddCollectionResponse_ELEM:
    return zx_LEN_WO_ps_AddCollectionResponse(c, (struct zx_ps_AddCollectionResponse_s*)x);
  case zx_ps_AddToCollectionRequest_ELEM:
    return zx_LEN_WO_ps_AddToCollectionRequest(c, (struct zx_ps_AddToCollectionRequest_s*)x);
  case zx_ps_AddToCollectionResponse_ELEM:
    return zx_LEN_WO_ps_AddToCollectionResponse(c, (struct zx_ps_AddToCollectionResponse_s*)x);
  case zx_ps_RemoveEntityRequest_ELEM:
    return zx_LEN_WO_ps_RemoveEntityRequest(c, (struct zx_ps_RemoveEntityRequest_s*)x);
  case zx_ps_RemoveEntityResponse_ELEM:
    return zx_LEN_WO_ps_RemoveEntityResponse(c, (struct zx_ps_RemoveEntityResponse_s*)x);
  case zx_ps_RemoveCollectionRequest_ELEM:
    return zx_LEN_WO_ps_RemoveCollectionRequest(c, (struct zx_ps_RemoveCollectionRequest_s*)x);
  case zx_ps_RemoveCollectionResponse_ELEM:
    return zx_LEN_WO_ps_RemoveCollectionResponse(c, (struct zx_ps_RemoveCollectionResponse_s*)x);
  case zx_ps_RemoveFromCollectionRequest_ELEM:
    return zx_LEN_WO_ps_RemoveFromCollectionRequest(c, (struct zx_ps_RemoveFromCollectionRequest_s*)x);
  case zx_ps_RemoveFromCollectionResponse_ELEM:
    return zx_LEN_WO_ps_RemoveFromCollectionResponse(c, (struct zx_ps_RemoveFromCollectionResponse_s*)x);
  case zx_ps_ListMembersRequest_ELEM:
    return zx_LEN_WO_ps_ListMembersRequest(c, (struct zx_ps_ListMembersRequest_s*)x);
  case zx_ps_ListMembersResponse_ELEM:
    return zx_LEN_WO_ps_ListMembersResponse(c, (struct zx_ps_ListMembersResponse_s*)x);
  case zx_ps_QueryObjectsRequest_ELEM:
    return zx_LEN_WO_ps_QueryObjectsRequest(c, (struct zx_ps_QueryObjectsRequest_s*)x);
  case zx_ps_QueryObjectsResponse_ELEM:
    return zx_LEN_WO_ps_QueryObjectsResponse(c, (struct zx_ps_QueryObjectsResponse_s*)x);
  case zx_ps_GetObjectInfoRequest_ELEM:
    return zx_LEN_WO_ps_GetObjectInfoRequest(c, (struct zx_ps_GetObjectInfoRequest_s*)x);
  case zx_ps_GetObjectInfoResponse_ELEM:
    return zx_LEN_WO_ps_GetObjectInfoResponse(c, (struct zx_ps_GetObjectInfoResponse_s*)x);
  case zx_ps_SetObjectInfoRequest_ELEM:
    return zx_LEN_WO_ps_SetObjectInfoRequest(c, (struct zx_ps_SetObjectInfoRequest_s*)x);
  case zx_ps_SetObjectInfoResponse_ELEM:
    return zx_LEN_WO_ps_SetObjectInfoResponse(c, (struct zx_ps_SetObjectInfoResponse_s*)x);
  case zx_ps_TestMembershipRequest_ELEM:
    return zx_LEN_WO_ps_TestMembershipRequest(c, (struct zx_ps_TestMembershipRequest_s*)x);
  case zx_ps_TestMembershipResponse_ELEM:
    return zx_LEN_WO_ps_TestMembershipResponse(c, (struct zx_ps_TestMembershipResponse_s*)x);
  case zx_ps_ResolveIdentifierRequest_ELEM:
    return zx_LEN_WO_ps_ResolveIdentifierRequest(c, (struct zx_ps_ResolveIdentifierRequest_s*)x);
  case zx_ps_ResolveIdentifierResponse_ELEM:
    return zx_LEN_WO_ps_ResolveIdentifierResponse(c, (struct zx_ps_ResolveIdentifierResponse_s*)x);
  case zx_ps_Notify_ELEM:
    return zx_LEN_WO_ps_Notify(c, (struct zx_ps_Notify_s*)x);
  case zx_ps_NotifyResponse_ELEM:
    return zx_LEN_WO_ps_NotifyResponse(c, (struct zx_ps_NotifyResponse_s*)x);
  case zx_im_IdentityMappingRequest_ELEM:
    return zx_LEN_WO_im_IdentityMappingRequest(c, (struct zx_im_IdentityMappingRequest_s*)x);
  case zx_im_IdentityMappingResponse_ELEM:
    return zx_LEN_WO_im_IdentityMappingResponse(c, (struct zx_im_IdentityMappingResponse_s*)x);
  case zx_as_SASLRequest_ELEM:
    return zx_LEN_WO_as_SASLRequest(c, (struct zx_as_SASLRequest_s*)x);
  case zx_as_SASLResponse_ELEM:
    return zx_LEN_WO_as_SASLResponse(c, (struct zx_as_SASLResponse_s*)x);
  case zx_mm7_SubmitReq_ELEM:
    return zx_LEN_WO_mm7_SubmitReq(c, (struct zx_mm7_SubmitReq_s*)x);
  case zx_mm7_SubmitRsp_ELEM:
    return zx_LEN_WO_mm7_SubmitRsp(c, (struct zx_mm7_SubmitRsp_s*)x);
  case zx_mm7_DeliverReq_ELEM:
    return zx_LEN_WO_mm7_DeliverReq(c, (struct zx_mm7_DeliverReq_s*)x);
  case zx_mm7_DeliverRsp_ELEM:
    return zx_LEN_WO_mm7_DeliverRsp(c, (struct zx_mm7_DeliverRsp_s*)x);
  case zx_mm7_CancelReq_ELEM:
    return zx_LEN_WO_mm7_CancelReq(c, (struct zx_mm7_CancelReq_s*)x);
  case zx_mm7_CancelRsp_ELEM:
    return zx_LEN_WO_mm7_CancelRsp(c, (struct zx_mm7_CancelRsp_s*)x);
  case zx_mm7_ReplaceReq_ELEM:
    return zx_LEN_WO_mm7_ReplaceReq(c, (struct zx_mm7_ReplaceReq_s*)x);
  case zx_mm7_ReplaceRsp_ELEM:
    return zx_LEN_WO_mm7_ReplaceRsp(c, (struct zx_mm7_ReplaceRsp_s*)x);
  case zx_mm7_extendedCancelReq_ELEM:
    return zx_LEN_WO_mm7_extendedCancelReq(c, (struct zx_mm7_extendedCancelReq_s*)x);
  case zx_mm7_extendedCancelRsp_ELEM:
    return zx_LEN_WO_mm7_extendedCancelRsp(c, (struct zx_mm7_extendedCancelRsp_s*)x);
  case zx_mm7_extendedReplaceReq_ELEM:
    return zx_LEN_WO_mm7_extendedReplaceReq(c, (struct zx_mm7_extendedReplaceReq_s*)x);
  case zx_mm7_extendedReplaceRsp_ELEM:
    return zx_LEN_WO_mm7_extendedReplaceRsp(c, (struct zx_mm7_extendedReplaceRsp_s*)x);
  case zx_mm7_DeliveryReportReq_ELEM:
    return zx_LEN_WO_mm7_DeliveryReportReq(c, (struct zx_mm7_DeliveryReportReq_s*)x);
  case zx_mm7_DeliveryReportRsp_ELEM:
    return zx_LEN_WO_mm7_DeliveryReportRsp(c, (struct zx_mm7_DeliveryReportRsp_s*)x);
  case zx_mm7_ReadReplyReq_ELEM:
    return zx_LEN_WO_mm7_ReadReplyReq(c, (struct zx_mm7_ReadReplyReq_s*)x);
  case zx_mm7_ReadReplyRsp_ELEM:
    return zx_LEN_WO_mm7_ReadReplyRsp(c, (struct zx_mm7_ReadReplyRsp_s*)x);
  case zx_mm7_RSErrorRsp_ELEM:
    return zx_LEN_WO_mm7_RSErrorRsp(c, (struct zx_mm7_RSErrorRsp_s*)x);
  case zx_mm7_VASPErrorRsp_ELEM:
    return zx_LEN_WO_mm7_VASPErrorRsp(c, (struct zx_mm7_VASPErrorRsp_s*)x);
  case zx_mm7_QueryStatusReq_ELEM:
    return zx_LEN_WO_mm7_QueryStatusReq(c, (struct zx_mm7_QueryStatusReq_s*)x);
  case zx_mm7_QueryStatusRsp_ELEM:
    return zx_LEN_WO_mm7_QueryStatusRsp(c, (struct zx_mm7_QueryStatusRsp_s*)x);
  case zx_cb_Query_ELEM:
    return zx_LEN_WO_cb_Query(c, (struct zx_cb_Query_s*)x);
  case zx_cb_QueryResponse_ELEM:
    return zx_LEN_WO_cb_QueryResponse(c, (struct zx_cb_QueryResponse_s*)x);
  case zx_cb_Create_ELEM:
    return zx_LEN_WO_cb_Create(c, (struct zx_cb_Create_s*)x);
  case zx_cb_CreateResponse_ELEM:
    return zx_LEN_WO_cb_CreateResponse(c, (struct zx_cb_CreateResponse_s*)x);
  case zx_cb_Delete_ELEM:
    return zx_LEN_WO_cb_Delete(c, (struct zx_cb_Delete_s*)x);
  case zx_cb_DeleteResponse_ELEM:
    return zx_LEN_WO_cb_DeleteResponse(c, (struct zx_cb_DeleteResponse_s*)x);
  case zx_cb_Modify_ELEM:
    return zx_LEN_WO_cb_Modify(c, (struct zx_cb_Modify_s*)x);
  case zx_cb_ModifyResponse_ELEM:
    return zx_LEN_WO_cb_ModifyResponse(c, (struct zx_cb_ModifyResponse_s*)x);
  case zx_cb_Notify_ELEM:
    return zx_LEN_WO_cb_Notify(c, (struct zx_cb_Notify_s*)x);
  case zx_cb_NotifyResponse_ELEM:
    return zx_LEN_WO_cb_NotifyResponse(c, (struct zx_cb_NotifyResponse_s*)x);
  case zx_cb_ReportUsage_ELEM:
    return zx_LEN_WO_cb_ReportUsage(c, (struct zx_cb_ReportUsage_s*)x);
  case zx_cb_ReportUsageResponse_ELEM:
    return zx_LEN_WO_cb_ReportUsageResponse(c, (struct zx_cb_ReportUsageResponse_s*)x);
  case zx_gl_Query_ELEM:
    return zx_LEN_WO_gl_Query(c, (struct zx_gl_Query_s*)x);
  case zx_gl_QueryResponse_ELEM:
    return zx_LEN_WO_gl_QueryResponse(c, (struct zx_gl_QueryResponse_s*)x);
  case zx_gl_Create_ELEM:
    return zx_LEN_WO_gl_Create(c, (struct zx_gl_Create_s*)x);
  case zx_gl_CreateResponse_ELEM:
    return zx_LEN_WO_gl_CreateResponse(c, (struct zx_gl_CreateResponse_s*)x);
  case zx_gl_Delete_ELEM:
    return zx_LEN_WO_gl_Delete(c, (struct zx_gl_Delete_s*)x);
  case zx_gl_DeleteResponse_ELEM:
    return zx_LEN_WO_gl_DeleteResponse(c, (struct zx_gl_DeleteResponse_s*)x);
  case zx_gl_Modify_ELEM:
    return zx_LEN_WO_gl_Modify(c, (struct zx_gl_Modify_s*)x);
  case zx_gl_ModifyResponse_ELEM:
    return zx_LEN_WO_gl_ModifyResponse(c, (struct zx_gl_ModifyResponse_s*)x);
  case zx_gl_Notify_ELEM:
    return zx_LEN_WO_gl_Notify(c, (struct zx_gl_Notify_s*)x);
  case zx_gl_NotifyResponse_ELEM:
    return zx_LEN_WO_gl_NotifyResponse(c, (struct zx_gl_NotifyResponse_s*)x);
  case zx_demomed_StoreObjectRequest_ELEM:
    return zx_LEN_WO_demomed_StoreObjectRequest(c, (struct zx_demomed_StoreObjectRequest_s*)x);
  case zx_demomed_StoreObjectResponse_ELEM:
    return zx_LEN_WO_demomed_StoreObjectResponse(c, (struct zx_demomed_StoreObjectResponse_s*)x);
  case zx_demomed_GetObjectListRequest_ELEM:
    return zx_LEN_WO_demomed_GetObjectListRequest(c, (struct zx_demomed_GetObjectListRequest_s*)x);
  case zx_demomed_GetObjectListResponse_ELEM:
    return zx_LEN_WO_demomed_GetObjectListResponse(c, (struct zx_demomed_GetObjectListResponse_s*)x);
  case zx_demomed_GetObjectRequest_ELEM:
    return zx_LEN_WO_demomed_GetObjectRequest(c, (struct zx_demomed_GetObjectRequest_s*)x);
  case zx_demomed_GetObjectResponse_ELEM:
    return zx_LEN_WO_demomed_GetObjectResponse(c, (struct zx_demomed_GetObjectResponse_s*)x);
  case zx_demomed_DeleteObjectRequest_ELEM:
    return zx_LEN_WO_demomed_DeleteObjectRequest(c, (struct zx_demomed_DeleteObjectRequest_s*)x);
  case zx_demomed_DeleteObjectResponse_ELEM:
    return zx_LEN_WO_demomed_DeleteObjectResponse(c, (struct zx_demomed_DeleteObjectResponse_s*)x);
  case zx_pmm_Provision_ELEM:
    return zx_LEN_WO_pmm_Provision(c, (struct zx_pmm_Provision_s*)x);
  case zx_pmm_ProvisionResponse_ELEM:
    return zx_LEN_WO_pmm_ProvisionResponse(c, (struct zx_pmm_ProvisionResponse_s*)x);
  case zx_pmm_PMActivate_ELEM:
    return zx_LEN_WO_pmm_PMActivate(c, (struct zx_pmm_PMActivate_s*)x);
  case zx_pmm_PMActivateResponse_ELEM:
    return zx_LEN_WO_pmm_PMActivateResponse(c, (struct zx_pmm_PMActivateResponse_s*)x);
  case zx_pmm_PMDeactivate_ELEM:
    return zx_LEN_WO_pmm_PMDeactivate(c, (struct zx_pmm_PMDeactivate_s*)x);
  case zx_pmm_PMDeactivateResponse_ELEM:
    return zx_LEN_WO_pmm_PMDeactivateResponse(c, (struct zx_pmm_PMDeactivateResponse_s*)x);
  case zx_pmm_PMDelete_ELEM:
    return zx_LEN_WO_pmm_PMDelete(c, (struct zx_pmm_PMDelete_s*)x);
  case zx_pmm_PMDeleteResponse_ELEM:
    return zx_LEN_WO_pmm_PMDeleteResponse(c, (struct zx_pmm_PMDeleteResponse_s*)x);
  case zx_pmm_PMUpdate_ELEM:
    return zx_LEN_WO_pmm_PMUpdate(c, (struct zx_pmm_PMUpdate_s*)x);
  case zx_pmm_PMUpdateResponse_ELEM:
    return zx_LEN_WO_pmm_PMUpdateResponse(c, (struct zx_pmm_PMUpdateResponse_s*)x);
  case zx_pmm_PMGetStatus_ELEM:
    return zx_LEN_WO_pmm_PMGetStatus(c, (struct zx_pmm_PMGetStatus_s*)x);
  case zx_pmm_PMGetStatusResponse_ELEM:
    return zx_LEN_WO_pmm_PMGetStatusResponse(c, (struct zx_pmm_PMGetStatusResponse_s*)x);
  case zx_pmm_PMSetStatus_ELEM:
    return zx_LEN_WO_pmm_PMSetStatus(c, (struct zx_pmm_PMSetStatus_s*)x);
  case zx_pmm_PMSetStatusResponse_ELEM:
    return zx_LEN_WO_pmm_PMSetStatusResponse(c, (struct zx_pmm_PMSetStatusResponse_s*)x);
  case zx_prov_PMERegister_ELEM:
    return zx_LEN_WO_prov_PMERegister(c, (struct zx_prov_PMERegister_s*)x);
  case zx_prov_PMERegisterResponse_ELEM:
    return zx_LEN_WO_prov_PMERegisterResponse(c, (struct zx_prov_PMERegisterResponse_s*)x);
  case zx_prov_PMEUpload_ELEM:
    return zx_LEN_WO_prov_PMEUpload(c, (struct zx_prov_PMEUpload_s*)x);
  case zx_prov_PMEUploadResponse_ELEM:
    return zx_LEN_WO_prov_PMEUploadResponse(c, (struct zx_prov_PMEUploadResponse_s*)x);
  case zx_prov_PMEDownload_ELEM:
    return zx_LEN_WO_prov_PMEDownload(c, (struct zx_prov_PMEDownload_s*)x);
  case zx_prov_PMEDownloadResponse_ELEM:
    return zx_LEN_WO_prov_PMEDownloadResponse(c, (struct zx_prov_PMEDownloadResponse_s*)x);
  case zx_prov_PMEEnable_ELEM:
    return zx_LEN_WO_prov_PMEEnable(c, (struct zx_prov_PMEEnable_s*)x);
  case zx_prov_PMEEnableResponse_ELEM:
    return zx_LEN_WO_prov_PMEEnableResponse(c, (struct zx_prov_PMEEnableResponse_s*)x);
  case zx_prov_PMEDisable_ELEM:
    return zx_LEN_WO_prov_PMEDisable(c, (struct zx_prov_PMEDisable_s*)x);
  case zx_prov_PMEDisableResponse_ELEM:
    return zx_LEN_WO_prov_PMEDisableResponse(c, (struct zx_prov_PMEDisableResponse_s*)x);
  case zx_prov_PMEDelete_ELEM:
    return zx_LEN_WO_prov_PMEDelete(c, (struct zx_prov_PMEDelete_s*)x);
  case zx_prov_PMEDeleteResponse_ELEM:
    return zx_LEN_WO_prov_PMEDeleteResponse(c, (struct zx_prov_PMEDeleteResponse_s*)x);
  case zx_prov_PMEGetInfo_ELEM:
    return zx_LEN_WO_prov_PMEGetInfo(c, (struct zx_prov_PMEGetInfo_s*)x);
  case zx_prov_PMEGetInfoResponse_ELEM:
    return zx_LEN_WO_prov_PMEGetInfoResponse(c, (struct zx_prov_PMEGetInfoResponse_s*)x);
  case zx_prov_PMGetStatus_ELEM:
    return zx_LEN_WO_prov_PMGetStatus(c, (struct zx_prov_PMGetStatus_s*)x);
  case zx_prov_PMGetStatusResponse_ELEM:
    return zx_LEN_WO_prov_PMGetStatusResponse(c, (struct zx_prov_PMGetStatusResponse_s*)x);
  case zx_prov_PMSetStatus_ELEM:
    return zx_LEN_WO_prov_PMSetStatus(c, (struct zx_prov_PMSetStatus_s*)x);
  case zx_prov_PMSetStatusResponse_ELEM:
    return zx_LEN_WO_prov_PMSetStatusResponse(c, (struct zx_prov_PMSetStatusResponse_s*)x);
  case zx_prov_PMGetDescriptor_ELEM:
    return zx_LEN_WO_prov_PMGetDescriptor(c, (struct zx_prov_PMGetDescriptor_s*)x);
  case zx_prov_PMGetDescriptorResponse_ELEM:
    return zx_LEN_WO_prov_PMGetDescriptorResponse(c, (struct zx_prov_PMGetDescriptorResponse_s*)x);
  case zx_prov_PMActivate_ELEM:
    return zx_LEN_WO_prov_PMActivate(c, (struct zx_prov_PMActivate_s*)x);
  case zx_prov_PMActivateResponse_ELEM:
    return zx_LEN_WO_prov_PMActivateResponse(c, (struct zx_prov_PMActivateResponse_s*)x);
  case zx_prov_PMDeactivate_ELEM:
    return zx_LEN_WO_prov_PMDeactivate(c, (struct zx_prov_PMDeactivate_s*)x);
  case zx_prov_PMDeactivateResponse_ELEM:
    return zx_LEN_WO_prov_PMDeactivateResponse(c, (struct zx_prov_PMDeactivateResponse_s*)x);
  case zx_prov_PMRegisterDescriptor_ELEM:
    return zx_LEN_WO_prov_PMRegisterDescriptor(c, (struct zx_prov_PMRegisterDescriptor_s*)x);
  case zx_prov_PMRegisterDescriptorResponse_ELEM:
    return zx_LEN_WO_prov_PMRegisterDescriptorResponse(c, (struct zx_prov_PMRegisterDescriptorResponse_s*)x);
  case zx_prov_PMUpdate_ELEM:
    return zx_LEN_WO_prov_PMUpdate(c, (struct zx_prov_PMUpdate_s*)x);
  case zx_prov_PMUpdateResponse_ELEM:
    return zx_LEN_WO_prov_PMUpdateResponse(c, (struct zx_prov_PMUpdateResponse_s*)x);
  case zx_prov_PMDelete_ELEM:
    return zx_LEN_WO_prov_PMDelete(c, (struct zx_prov_PMDelete_s*)x);
  case zx_prov_PMDeleteResponse_ELEM:
    return zx_LEN_WO_prov_PMDeleteResponse(c, (struct zx_prov_PMDeleteResponse_s*)x);
  case zx_prov_Poll_ELEM:
    return zx_LEN_WO_prov_Poll(c, (struct zx_prov_Poll_s*)x);
  case zx_prov_PollResponse_ELEM:
    return zx_LEN_WO_prov_PollResponse(c, (struct zx_prov_PollResponse_s*)x);
  case zx_prov_UpdateEPR_ELEM:
    return zx_LEN_WO_prov_UpdateEPR(c, (struct zx_prov_UpdateEPR_s*)x);
  case zx_prov_UpdateEPRResponse_ELEM:
    return zx_LEN_WO_prov_UpdateEPRResponse(c, (struct zx_prov_UpdateEPRResponse_s*)x);
  case zx_idp_GetAssertion_ELEM:
    return zx_LEN_WO_idp_GetAssertion(c, (struct zx_idp_GetAssertion_s*)x);
  case zx_idp_GetAssertionResponse_ELEM:
    return zx_LEN_WO_idp_GetAssertionResponse(c, (struct zx_idp_GetAssertionResponse_s*)x);
  case zx_idp_GetProviderInfo_ELEM:
    return zx_LEN_WO_idp_GetProviderInfo(c, (struct zx_idp_GetProviderInfo_s*)x);
  case zx_idp_GetProviderInfoResponse_ELEM:
    return zx_LEN_WO_idp_GetProviderInfoResponse(c, (struct zx_idp_GetProviderInfoResponse_s*)x);
  case zx_idp_CreatedStatus_ELEM:
    return zx_LEN_WO_idp_CreatedStatus(c, (struct zx_idp_CreatedStatus_s*)x);
  case zx_idp_CreatedStatusResponse_ELEM:
    return zx_LEN_WO_idp_CreatedStatusResponse(c, (struct zx_idp_CreatedStatusResponse_s*)x);
  case zx_shps_Delete_ELEM:
    return zx_LEN_WO_shps_Delete(c, (struct zx_shps_Delete_s*)x);
  case zx_shps_DeleteResponse_ELEM:
    return zx_LEN_WO_shps_DeleteResponse(c, (struct zx_shps_DeleteResponse_s*)x);
  case zx_shps_GetStatus_ELEM:
    return zx_LEN_WO_shps_GetStatus(c, (struct zx_shps_GetStatus_s*)x);
  case zx_shps_GetStatusResponse_ELEM:
    return zx_LEN_WO_shps_GetStatusResponse(c, (struct zx_shps_GetStatusResponse_s*)x);
  case zx_shps_Query_ELEM:
    return zx_LEN_WO_shps_Query(c, (struct zx_shps_Query_s*)x);
  case zx_shps_QueryResponse_ELEM:
    return zx_LEN_WO_shps_QueryResponse(c, (struct zx_shps_QueryResponse_s*)x);
  case zx_shps_Invoke_ELEM:
    return zx_LEN_WO_simple_elem(c, (struct zx_elem_s*)x, sizeof("Invoke")-1);
  case zx_shps_InvokeResponse_ELEM:
    return zx_LEN_WO_shps_InvokeResponse(c, (struct zx_shps_InvokeResponse_s*)x);
  case zx_shps_QueryRegistered_ELEM:
    return zx_LEN_WO_shps_QueryRegistered(c, (struct zx_shps_QueryRegistered_s*)x);
  case zx_shps_QueryRegisteredResponse_ELEM:
    return zx_LEN_WO_shps_QueryRegisteredResponse(c, (struct zx_shps_QueryRegisteredResponse_s*)x);
  case zx_shps_Register_ELEM:
    return zx_LEN_WO_shps_Register(c, (struct zx_shps_Register_s*)x);
  case zx_shps_RegisterResponse_ELEM:
    return zx_LEN_WO_shps_RegisterResponse(c, (struct zx_shps_RegisterResponse_s*)x);
  case zx_shps_SetStatus_ELEM:
    return zx_LEN_WO_shps_SetStatus(c, (struct zx_shps_SetStatus_s*)x);
  case zx_shps_SetStatusResponse_ELEM:
    return zx_LEN_WO_shps_SetStatusResponse(c, (struct zx_shps_SetStatusResponse_s*)x);
  case zx_shps_Update_ELEM:
    return zx_LEN_WO_shps_Update(c, (struct zx_shps_Update_s*)x);
  case zx_shps_UpdateResponse_ELEM:
    return zx_LEN_WO_shps_UpdateResponse(c, (struct zx_shps_UpdateResponse_s*)x);
  case zx_shps_Poll_ELEM:
    return zx_LEN_WO_shps_Poll(c, (struct zx_shps_Poll_s*)x);
  case zx_shps_PollResponse_ELEM:
    return zx_LEN_WO_shps_PollResponse(c, (struct zx_shps_PollResponse_s*)x);
  case zx_shps_ProxyInvoke_ELEM:
    return zx_LEN_WO_shps_ProxyInvoke(c, (struct zx_shps_ProxyInvoke_s*)x);
  case zx_shps_ProxyInvokeResponse_ELEM:
    return zx_LEN_WO_shps_ProxyInvokeResponse(c, (struct zx_shps_ProxyInvokeResponse_s*)x);
  case zx_idhrxml_Create_ELEM:
    return zx_LEN_WO_idhrxml_Create(c, (struct zx_idhrxml_Create_s*)x);
  case zx_idhrxml_CreateResponse_ELEM:
    return zx_LEN_WO_idhrxml_CreateResponse(c, (struct zx_idhrxml_CreateResponse_s*)x);
  case zx_idhrxml_Query_ELEM:
    return zx_LEN_WO_idhrxml_Query(c, (struct zx_idhrxml_Query_s*)x);
  case zx_idhrxml_QueryResponse_ELEM:
    return zx_LEN_WO_idhrxml_QueryResponse(c, (struct zx_idhrxml_QueryResponse_s*)x);
  case zx_idhrxml_Modify_ELEM:
    return zx_LEN_WO_idhrxml_Modify(c, (struct zx_idhrxml_Modify_s*)x);
  case zx_idhrxml_ModifyResponse_ELEM:
    return zx_LEN_WO_idhrxml_ModifyResponse(c, (struct zx_idhrxml_ModifyResponse_s*)x);
  case zx_idhrxml_Delete_ELEM:
    return zx_LEN_WO_idhrxml_Delete(c, (struct zx_idhrxml_Delete_s*)x);
  case zx_idhrxml_DeleteResponse_ELEM:
    return zx_LEN_WO_idhrxml_DeleteResponse(c, (struct zx_idhrxml_DeleteResponse_s*)x);
  case zx_idhrxml_Notify_ELEM:
    return zx_LEN_WO_idhrxml_Notify(c, (struct zx_idhrxml_Notify_s*)x);
  case zx_idhrxml_NotifyResponse_ELEM:
    return zx_LEN_WO_idhrxml_NotifyResponse(c, (struct zx_idhrxml_NotifyResponse_s*)x);
  case zx_e_Header_ELEM:
    return zx_LEN_WO_e_Header(c, (struct zx_e_Header_s*)x);
  case zx_e_Body_ELEM:
    return zx_LEN_WO_e_Body(c, (struct zx_e_Body_s*)x);
  case zx_e_faultcode_ELEM:
    return zx_LEN_WO_simple_elem(c, (struct zx_elem_s*)x, sizeof("faultcode")-1);
  case zx_e_faultstring_ELEM:
    return zx_LEN_WO_simple_elem(c, (struct zx_elem_s*)x, sizeof("faultstring")-1);
  case zx_e_faultactor_ELEM:
    return zx_LEN_WO_simple_elem(c, (struct zx_elem_s*)x, sizeof("faultactor")-1);
  case zx_e_detail_ELEM:
    return zx_LEN_WO_e_detail(c, (struct zx_e_detail_s*)x);
  case zx_paos_Request_ELEM:
    return zx_LEN_WO_paos_Request(c, (struct zx_paos_Request_s*)x);
  case zx_paos_Response_ELEM:
    return zx_LEN_WO_paos_Response(c, (struct zx_paos_Response_s*)x);
  case zx_ecp_Request_ELEM:
    return zx_LEN_WO_ecp_Request(c, (struct zx_ecp_Request_s*)x);
  case zx_ecp_Response_ELEM:
    return zx_LEN_WO_ecp_Response(c, (struct zx_ecp_Response_s*)x);
  case zx_ecp_RelayState_ELEM:
    return zx_LEN_WO_ecp_RelayState(c, (struct zx_ecp_RelayState_s*)x);
  case zx_a_MessageID_ELEM:
    return zx_LEN_WO_a_MessageID(c, (struct zx_a_MessageID_s*)x);
  case zx_a_RelatesTo_ELEM:
    return zx_LEN_WO_a_RelatesTo(c, (struct zx_a_RelatesTo_s*)x);
  case zx_a_ReplyTo_ELEM:
    return zx_LEN_WO_a_ReplyTo(c, (struct zx_a_ReplyTo_s*)x);
  case zx_a_From_ELEM:
    return zx_LEN_WO_a_From(c, (struct zx_a_From_s*)x);
  case zx_a_FaultTo_ELEM:
    return zx_LEN_WO_a_FaultTo(c, (struct zx_a_FaultTo_s*)x);
  case zx_a_To_ELEM:
    return zx_LEN_WO_a_To(c, (struct zx_a_To_s*)x);
  case zx_b_Framework_ELEM:
    return zx_LEN_WO_b_Framework(c, (struct zx_b_Framework_s*)x);
  case zx_b_Sender_ELEM:
    return zx_LEN_WO_b_Sender(c, (struct zx_b_Sender_s*)x);
  case zx_b_CredentialsContext_ELEM:
    return zx_LEN_WO_b_CredentialsContext(c, (struct zx_b_CredentialsContext_s*)x);
  case zx_b_EndpointUpdate_ELEM:
    return zx_LEN_WO_b_EndpointUpdate(c, (struct zx_b_EndpointUpdate_s*)x);
  case zx_b_Timeout_ELEM:
    return zx_LEN_WO_b_Timeout(c, (struct zx_b_Timeout_s*)x);
  case zx_b_ProcessingContext_ELEM:
    return zx_LEN_WO_b_ProcessingContext(c, (struct zx_b_ProcessingContext_s*)x);
  case zx_b_Consent_ELEM:
    return zx_LEN_WO_b_Consent(c, (struct zx_b_Consent_s*)x);
  case zx_b_UsageDirective_ELEM:
    return zx_LEN_WO_b_UsageDirective(c, (struct zx_b_UsageDirective_s*)x);
  case zx_b_ApplicationEPR_ELEM:
    return zx_LEN_WO_b_ApplicationEPR(c, (struct zx_b_ApplicationEPR_s*)x);
  case zx_b_UserInteraction_ELEM:
    return zx_LEN_WO_b_UserInteraction(c, (struct zx_b_UserInteraction_s*)x);
  case zx_b_RedirectRequest_ELEM:
    return zx_LEN_WO_b_RedirectRequest(c, (struct zx_b_RedirectRequest_s*)x);
  case zx_b12_Correlation_ELEM:
    return zx_LEN_WO_b12_Correlation(c, (struct zx_b12_Correlation_s*)x);
  case zx_b12_Provider_ELEM:
    return zx_LEN_WO_b12_Provider(c, (struct zx_b12_Provider_s*)x);
  case zx_b12_ProcessingContext_ELEM:
    return zx_LEN_WO_b12_ProcessingContext(c, (struct zx_b12_ProcessingContext_s*)x);
  case zx_b12_Consent_ELEM:
    return zx_LEN_WO_b12_Consent(c, (struct zx_b12_Consent_s*)x);
  case zx_b12_UsageDirective_ELEM:
    return zx_LEN_WO_b12_UsageDirective(c, (struct zx_b12_UsageDirective_s*)x);
  case zx_mm7_TransactionID_ELEM:
    return zx_LEN_WO_mm7_TransactionID(c, (struct zx_mm7_TransactionID_s*)x);
  case zx_wsse_Security_ELEM:
    return zx_LEN_WO_wsse_Security(c, (struct zx_wsse_Security_s*)x);
  case zx_tas3_Status_ELEM:
    return zx_LEN_WO_tas3_Status(c, (struct zx_tas3_Status_s*)x);
  case zx_tas3_Credentials_ELEM:
    return zx_LEN_WO_tas3_Credentials(c, (struct zx_tas3_Credentials_s*)x);
  case zx_tas3_ESLPolicies_ELEM:
    return zx_LEN_WO_tas3_ESLPolicies(c, (struct zx_tas3_ESLPolicies_s*)x);
  case zx_sa_Issuer_ELEM:
    return zx_LEN_WO_sa_Issuer(c, (struct zx_sa_Issuer_s*)x);
  case zx_sp_IDPList_ELEM:
    return zx_LEN_WO_sp_IDPList(c, (struct zx_sp_IDPList_s*)x);
  case zx_sa11_Conditions_ELEM:
    return zx_LEN_WO_sa11_Conditions(c, (struct zx_sa11_Conditions_s*)x);
  case zx_sa11_Advice_ELEM:
    return zx_LEN_WO_sa11_Advice(c, (struct zx_sa11_Advice_s*)x);
  case zx_sa11_Statement_ELEM:
    return zx_LEN_WO_simple_elem(c, (struct zx_elem_s*)x, sizeof("Statement")-1);
  case zx_sa11_SubjectStatement_ELEM:
    return zx_LEN_WO_sa11_SubjectStatement(c, (struct zx_sa11_SubjectStatement_s*)x);
  case zx_sa11_AuthenticationStatement_ELEM:
    return zx_LEN_WO_sa11_AuthenticationStatement(c, (struct zx_sa11_AuthenticationStatement_s*)x);
  case zx_sa11_AuthorizationDecisionStatement_ELEM:
    return zx_LEN_WO_sa11_AuthorizationDecisionStatement(c, (struct zx_sa11_AuthorizationDecisionStatement_s*)x);
  case zx_sa11_AttributeStatement_ELEM:
    return zx_LEN_WO_sa11_AttributeStatement(c, (struct zx_sa11_AttributeStatement_s*)x);
  case zx_xasa_XACMLAuthzDecisionStatement_ELEM:
    return zx_LEN_WO_xasa_XACMLAuthzDecisionStatement(c, (struct zx_xasa_XACMLAuthzDecisionStatement_s*)x);
  case zx_xasa_XACMLPolicyStatement_ELEM:
    return zx_LEN_WO_xasa_XACMLPolicyStatement(c, (struct zx_xasa_XACMLPolicyStatement_s*)x);
  case zx_xasacd1_XACMLAuthzDecisionStatement_ELEM:
    return zx_LEN_WO_xasacd1_XACMLAuthzDecisionStatement(c, (struct zx_xasacd1_XACMLAuthzDecisionStatement_s*)x);
  case zx_xasacd1_XACMLPolicyStatement_ELEM:
    return zx_LEN_WO_xasacd1_XACMLPolicyStatement(c, (struct zx_xasacd1_XACMLPolicyStatement_s*)x);
  case zx_ds_Signature_ELEM:
    return (x != c->exclude_sig) ? zx_LEN_WO_ds_Signature(c, (struct zx_ds_Signature_s*)x) : 0;
  case zx_sa11_Subject_ELEM:
    return zx_LEN_WO_sa11_Subject(c, (struct zx_sa11_Subject_s*)x);
  case zx_sa11_SubjectLocality_ELEM:
    return zx_LEN_WO_sa11_SubjectLocality(c, (struct zx_sa11_SubjectLocality_s*)x);
  case zx_sa11_AuthorityBinding_ELEM:
    return zx_LEN_WO_sa11_AuthorityBinding(c, (struct zx_sa11_AuthorityBinding_s*)x);
  case zx_ff12_AuthnContext_ELEM:
    return zx_LEN_WO_ff12_AuthnContext(c, (struct zx_ff12_AuthnContext_s*)x);
  case zx_ff12_AuthnContextClassRef_ELEM:
    return zx_LEN_WO_simple_elem(c, (struct zx_elem_s*)x, sizeof("AuthnContextClassRef")-1);
  case zx_ac_AuthenticationContextStatement_ELEM:
    return zx_LEN_WO_ac_AuthenticationContextStatement(c, (struct zx_ac_AuthenticationContextStatement_s*)x);
  case zx_ff12_AuthnContextStatementRef_ELEM:
    return zx_LEN_WO_simple_elem(c, (struct zx_elem_s*)x, sizeof("AuthnContextStatementRef")-1);
  case zx_sp11_RespondWith_ELEM:
    return zx_LEN_WO_simple_elem(c, (struct zx_elem_s*)x, sizeof("RespondWith")-1);
  case zx_ff12_Extension_ELEM:
    return zx_LEN_WO_ff12_Extension(c, (struct zx_ff12_Extension_s*)x);
  case zx_ff12_ProviderID_ELEM:
    return zx_LEN_WO_simple_elem(c, (struct zx_elem_s*)x, sizeof("ProviderID")-1);
  case zx_ff12_AffiliationID_ELEM:
    return zx_LEN_WO_simple_elem(c, (struct zx_elem_s*)x, sizeof("AffiliationID")-1);
  case zx_ff12_NameIDPolicy_ELEM:
    return zx_LEN_WO_simple_elem(c, (struct zx_elem_s*)x, sizeof("NameIDPolicy")-1);
  case zx_ff12_ForceAuthn_ELEM:
    return zx_LEN_WO_simple_elem(c, (struct zx_elem_s*)x, sizeof("ForceAuthn")-1);
  case zx_ff12_IsPassive_ELEM:
    return zx_LEN_WO_simple_elem(c, (struct zx_elem_s*)x, sizeof("IsPassive")-1);
  case zx_ff12_ProtocolProfile_ELEM:
    return zx_LEN_WO_simple_elem(c, (struct zx_elem_s*)x, sizeof("ProtocolProfile")-1);
  case zx_ff12_AssertionConsumerServiceID_ELEM:
    return zx_LEN_WO_simple_elem(c, (struct zx_elem_s*)x, sizeof("AssertionConsumerServiceID")-1);
  case zx_ff12_RequestAuthnContext_ELEM:
    return zx_LEN_WO_ff12_RequestAuthnContext(c, (struct zx_ff12_RequestAuthnContext_s*)x);
  case zx_ff12_RelayState_ELEM:
    return zx_LEN_WO_simple_elem(c, (struct zx_elem_s*)x, sizeof("RelayState")-1);
  case zx_ff12_Scoping_ELEM:
    return zx_LEN_WO_ff12_Scoping(c, (struct zx_ff12_Scoping_s*)x);
  case zx_ff12_AuthnRequest_ELEM:
    return zx_LEN_WO_ff12_AuthnRequest(c, (struct zx_ff12_AuthnRequest_s*)x);
  case zx_ff12_ProviderName_ELEM:
    return zx_LEN_WO_simple_elem(c, (struct zx_elem_s*)x, sizeof("ProviderName")-1);
  case zx_ff12_AssertionConsumerServiceURL_ELEM:
    return zx_LEN_WO_simple_elem(c, (struct zx_elem_s*)x, sizeof("AssertionConsumerServiceURL")-1);
  case zx_ff12_IDPList_ELEM:
    return zx_LEN_WO_ff12_IDPList(c, (struct zx_ff12_IDPList_s*)x);
  case zx_sp11_Status_ELEM:
    return zx_LEN_WO_sp11_Status(c, (struct zx_sp11_Status_s*)x);
  case zx_ff12_AuthnResponse_ELEM:
    return zx_LEN_WO_ff12_AuthnResponse(c, (struct zx_ff12_AuthnResponse_s*)x);
  case zx_sa11_NameIdentifier_ELEM:
    return zx_LEN_WO_sa11_NameIdentifier(c, (struct zx_sa11_NameIdentifier_s*)x);
  case zx_ff12_IDPEntry_ELEM:
    return zx_LEN_WO_ff12_IDPEntry(c, (struct zx_ff12_IDPEntry_s*)x);
  case zx_ff12_Loc_ELEM:
    return zx_LEN_WO_simple_elem(c, (struct zx_elem_s*)x, sizeof("Loc")-1);
  case zx_ff12_IDPEntries_ELEM:
    return zx_LEN_WO_ff12_IDPEntries(c, (struct zx_ff12_IDPEntries_s*)x);
  case zx_ff12_GetComplete_ELEM:
    return zx_LEN_WO_simple_elem(c, (struct zx_elem_s*)x, sizeof("GetComplete")-1);
  case zx_ff12_SessionIndex_ELEM:
    return zx_LEN_WO_simple_elem(c, (struct zx_elem_s*)x, sizeof("SessionIndex")-1);
  case zx_ff12_TargetNamespace_ELEM:
    return zx_LEN_WO_simple_elem(c, (struct zx_elem_s*)x, sizeof("TargetNamespace")-1);
  case zx_ff12_IDPProvidedNameIdentifier_ELEM:
    return zx_LEN_WO_ff12_IDPProvidedNameIdentifier(c, (struct zx_ff12_IDPProvidedNameIdentifier_s*)x);
  case zx_ff12_SPProvidedNameIdentifier_ELEM:
    return zx_LEN_WO_ff12_SPProvidedNameIdentifier(c, (struct zx_ff12_SPProvidedNameIdentifier_s*)x);
  case zx_ff12_OldProvidedNameIdentifier_ELEM:
    return zx_LEN_WO_ff12_OldProvidedNameIdentifier(c, (struct zx_ff12_OldProvidedNameIdentifier_s*)x);
  case zx_ff12_AuthnContextComparison_ELEM:
    return zx_LEN_WO_simple_elem(c, (struct zx_elem_s*)x, sizeof("AuthnContextComparison")-1);
  case zx_ff12_ProxyCount_ELEM:
    return zx_LEN_WO_simple_elem(c, (struct zx_elem_s*)x, sizeof("ProxyCount")-1);
  case zx_sa11_SubjectConfirmation_ELEM:
    return zx_LEN_WO_sa11_SubjectConfirmation(c, (struct zx_sa11_SubjectConfirmation_s*)x);
  case zx_gl_CivilData_ELEM:
    return zx_LEN_WO_gl_CivilData(c, (struct zx_gl_CivilData_s*)x);
  case zx_gl_shape_ELEM:
    return zx_LEN_WO_gl_shape(c, (struct zx_gl_shape_s*)x);
  case zx_gl_Extension_ELEM:
    return zx_LEN_WO_gl_Extension(c, (struct zx_gl_Extension_s*)x);
  case zx_gl_coord_ELEM:
    return zx_LEN_WO_gl_coord(c, (struct zx_gl_coord_s*)x);
  case zx_gl_inRadius_ELEM:
    return zx_LEN_WO_simple_elem(c, (struct zx_elem_s*)x, sizeof("inRadius")-1);
  case zx_gl_outRadius_ELEM:
    return zx_LEN_WO_simple_elem(c, (struct zx_elem_s*)x, sizeof("outRadius")-1);
  case zx_gl_startAngle_ELEM:
    return zx_LEN_WO_simple_elem(c, (struct zx_elem_s*)x, sizeof("startAngle")-1);
  case zx_gl_stopAngle_ELEM:
    return zx_LEN_WO_simple_elem(c, (struct zx_elem_s*)x, sizeof("stopAngle")-1);
  case zx_gl_angularUnit_ELEM:
    return zx_LEN_WO_simple_elem(c, (struct zx_elem_s*)x, sizeof("angularUnit")-1);
  case zx_gl_distanceUnit_ELEM:
    return zx_LEN_WO_simple_elem(c, (struct zx_elem_s*)x, sizeof("distanceUnit")-1);
  case zx_gl_radius_ELEM:
    return zx_LEN_WO_simple_elem(c, (struct zx_elem_s*)x, sizeof("radius")-1);
  case zx_gl_PostalAddress_ELEM:
    return zx_LEN_WO_simple_elem(c, (struct zx_elem_s*)x, sizeof("PostalAddress")-1);
  case zx_gl_LPostalAddress_ELEM:
    return zx_LEN_WO_gl_LPostalAddress(c, (struct zx_gl_LPostalAddress_s*)x);
  case zx_gl_PostalCode_ELEM:
    return zx_LEN_WO_simple_elem(c, (struct zx_elem_s*)x, sizeof("PostalCode")-1);
  case zx_gl_L_ELEM:
    return zx_LEN_WO_simple_elem(c, (struct zx_elem_s*)x, sizeof("L")-1);
  case zx_gl_LL_ELEM:
    return zx_LEN_WO_gl_LL(c, (struct zx_gl_LL_s*)x);
  case zx_gl_St_ELEM:
    return zx_LEN_WO_simple_elem(c, (struct zx_elem_s*)x, sizeof("St")-1);
  case zx_gl_LSt_ELEM:
    return zx_LEN_WO_gl_LSt(c, (struct zx_gl_LSt_s*)x);
  case zx_gl_C_ELEM:
    return zx_LEN_WO_simple_elem(c, (struct zx_elem_s*)x, sizeof("C")-1);
  case zx_gl_MNC_ELEM:
    return zx_LEN_WO_simple_elem(c, (struct zx_elem_s*)x, sizeof("MNC")-1);
  case zx_gl_Identifier_ELEM:
    return zx_LEN_WO_gl_Identifier(c, (struct zx_gl_Identifier_s*)x);
  case zx_gl_ResourceID_ELEM:
    return zx_LEN_WO_gl_ResourceID(c, (struct zx_gl_ResourceID_s*)x);
  case zx_gl_EncryptedResourceID_ELEM:
    return zx_LEN_WO_gl_EncryptedResourceID(c, (struct zx_gl_EncryptedResourceID_s*)x);
  case zx_gl_Subscription_ELEM:
    return zx_LEN_WO_gl_Subscription(c, (struct zx_gl_Subscription_s*)x);
  case zx_gl_CreateItem_ELEM:
    return zx_LEN_WO_gl_CreateItem(c, (struct zx_gl_CreateItem_s*)x);
  case zx_gl_ItemSelection_ELEM:
    return zx_LEN_WO_gl_ItemSelection(c, (struct zx_gl_ItemSelection_s*)x);
  case zx_gl_NewData_ELEM:
    return zx_LEN_WO_gl_NewData(c, (struct zx_gl_NewData_s*)x);
  case zx_gl_Status_ELEM:
    return zx_LEN_WO_gl_Status(c, (struct zx_gl_Status_s*)x);
  case zx_gl_ItemData_ELEM:
    return zx_LEN_WO_gl_ItemData(c, (struct zx_gl_ItemData_s*)x);
  case zx_gl_DeleteItem_ELEM:
    return zx_LEN_WO_gl_DeleteItem(c, (struct zx_gl_DeleteItem_s*)x);
  case zx_gl_Select_ELEM:
    return zx_LEN_WO_simple_elem(c, (struct zx_elem_s*)x, sizeof("Select")-1);
  case zx_gl_angle_ELEM:
    return zx_LEN_WO_simple_elem(c, (struct zx_elem_s*)x, sizeof("angle")-1);
  case zx_gl_semiMajor_ELEM:
    return zx_LEN_WO_simple_elem(c, (struct zx_elem_s*)x, sizeof("semiMajor")-1);
  case zx_gl_semiMinor_ELEM:
    return zx_LEN_WO_simple_elem(c, (struct zx_elem_s*)x, sizeof("semiMinor")-1);
  case zx_gl_code_ELEM:
    return zx_LEN_WO_simple_elem(c, (struct zx_elem_s*)x, sizeof("code")-1);
  case zx_gl_codeSpace_ELEM:
    return zx_LEN_WO_simple_elem(c, (struct zx_elem_s*)x, sizeof("codeSpace")-1);
  case zx_gl_edition_ELEM:
    return zx_LEN_WO_simple_elem(c, (struct zx_elem_s*)x, sizeof("edition")-1);
  case zx_gl_AreaComparison_ELEM:
    return zx_LEN_WO_gl_AreaComparison(c, (struct zx_gl_AreaComparison_s*)x);
  case zx_gl_eqop_ELEM:
    return zx_LEN_WO_gl_eqop(c, (struct zx_gl_eqop_s*)x);
  case zx_gl_geoinfo_ELEM:
    return zx_LEN_WO_gl_geoinfo(c, (struct zx_gl_geoinfo_s*)x);
  case zx_gl_loc_type_ELEM:
    return zx_LEN_WO_gl_loc_type(c, (struct zx_gl_loc_type_s*)x);
  case zx_gl_prio_ELEM:
    return zx_LEN_WO_gl_prio(c, (struct zx_gl_prio_s*)x);
  case zx_gl_Modification_ELEM:
    return zx_LEN_WO_gl_Modification(c, (struct zx_gl_Modification_s*)x);
  case zx_gl_LineString_ELEM:
    return zx_LEN_WO_gl_LineString(c, (struct zx_gl_LineString_s*)x);
  case zx_gl_Point_ELEM:
    return zx_LEN_WO_gl_Point(c, (struct zx_gl_Point_s*)x);
  case zx_gl_Polygon_ELEM:
    return zx_LEN_WO_gl_Polygon(c, (struct zx_gl_Polygon_s*)x);
  case zx_gl_Box_ELEM:
    return zx_LEN_WO_gl_Box(c, (struct zx_gl_Box_s*)x);
  case zx_gl_CircularArea_ELEM:
    return zx_LEN_WO_gl_CircularArea(c, (struct zx_gl_CircularArea_s*)x);
  case zx_gl_CircularArcArea_ELEM:
    return zx_LEN_WO_gl_CircularArcArea(c, (struct zx_gl_CircularArcArea_s*)x);
  case zx_gl_EllipticalArea_ELEM:
    return zx_LEN_WO_gl_EllipticalArea(c, (struct zx_gl_EllipticalArea_s*)x);
  case zx_gl_Notification_ELEM:
    return zx_LEN_WO_gl_Notification(c, (struct zx_gl_Notification_s*)x);
  case zx_gl_SecurityMechID_ELEM:
    return zx_LEN_WO_simple_elem(c, (struct zx_elem_s*)x, sizeof("SecurityMechID")-1);
  case zx_gl_Credential_ELEM:
    return zx_LEN_WO_gl_Credential(c, (struct zx_gl_Credential_s*)x);
  case zx_gl_Endpoint_ELEM:
    return zx_LEN_WO_simple_elem(c, (struct zx_elem_s*)x, sizeof("Endpoint")-1);
  case zx_gl_outerBoundaryIs_ELEM:
    return zx_LEN_WO_gl_outerBoundaryIs(c, (struct zx_gl_outerBoundaryIs_s*)x);
  case zx_gl_innerBoundaryIs_ELEM:
    return zx_LEN_WO_gl_innerBoundaryIs(c, (struct zx_gl_innerBoundaryIs_s*)x);
  case zx_gl_QueryItem_ELEM:
    return zx_LEN_WO_gl_QueryItem(c, (struct zx_gl_QueryItem_s*)x);
  case zx_gl_Data_ELEM:
    return zx_LEN_WO_gl_Data(c, (struct zx_gl_Data_s*)x);
  case zx_gl_RefItem_ELEM:
    return zx_LEN_WO_gl_RefItem(c, (struct zx_gl_RefItem_s*)x);
  case zx_gl_NotifyTo_ELEM:
    return zx_LEN_WO_gl_NotifyTo(c, (struct zx_gl_NotifyTo_s*)x);
  case zx_gl_NotifyAdminTo_ELEM:
    return zx_LEN_WO_gl_NotifyAdminTo(c, (struct zx_gl_NotifyAdminTo_s*)x);
  case zx_gl_Aggregation_ELEM:
    return zx_LEN_WO_simple_elem(c, (struct zx_elem_s*)x, sizeof("Aggregation")-1);
  case zx_gl_Trigger_ELEM:
    return zx_LEN_WO_gl_Trigger(c, (struct zx_gl_Trigger_s*)x);
  case zx_gl_Granularity_ELEM:
    return zx_LEN_WO_simple_elem(c, (struct zx_elem_s*)x, sizeof("Granularity")-1);
  case zx_gl_Interval_ELEM:
    return zx_LEN_WO_simple_elem(c, (struct zx_elem_s*)x, sizeof("Interval")-1);
  case zx_gl_ms_action_ELEM:
    return zx_LEN_WO_gl_ms_action(c, (struct zx_gl_ms_action_s*)x);
  case zx_gl_ChangeArea_ELEM:
    return zx_LEN_WO_gl_ChangeArea(c, (struct zx_gl_ChangeArea_s*)x);
  case zx_gl_X_ELEM:
    return zx_LEN_WO_simple_elem(c, (struct zx_elem_s*)x, sizeof("X")-1);
  case zx_gl_Y_ELEM:
    return zx_LEN_WO_simple_elem(c, (struct zx_elem_s*)x, sizeof("Y")-1);
  case zx_gl_Z_ELEM:
    return zx_LEN_WO_simple_elem(c, (struct zx_elem_s*)x, sizeof("Z")-1);
  case zx_gl_resp_req_ELEM:
    return zx_LEN_WO_gl_resp_req(c, (struct zx_gl_resp_req_s*)x);
  case zx_gl_ll_acc_ELEM:
    return zx_LEN_WO_simple_elem(c, (struct zx_elem_s*)x, sizeof("ll_acc")-1);
  case zx_gl_hor_acc_ELEM:
    return zx_LEN_WO_simple_elem(c, (struct zx_elem_s*)x, sizeof("hor_acc")-1);
  case zx_gl_alt_acc_ELEM:
    return zx_LEN_WO_simple_elem(c, (struct zx_elem_s*)x, sizeof("alt_acc")-1);
  case zx_gl_max_loc_age_ELEM:
    return zx_LEN_WO_simple_elem(c, (struct zx_elem_s*)x, sizeof("max_loc_age")-1);
  case zx_gl_CoordinateReferenceSystem_ELEM:
    return zx_LEN_WO_gl_CoordinateReferenceSystem(c, (struct zx_gl_CoordinateReferenceSystem_s*)x);
  case zx_gl_speed_ELEM:
    return zx_LEN_WO_simple_elem(c, (struct zx_elem_s*)x, sizeof("speed")-1);
  case zx_gl_alt_ELEM:
    return zx_LEN_WO_simple_elem(c, (struct zx_elem_s*)x, sizeof("alt")-1);
  case zx_gl_direction_ELEM:
    return zx_LEN_WO_simple_elem(c, (struct zx_elem_s*)x, sizeof("direction")-1);
  case zx_gl_Heading_ELEM:
    return zx_LEN_WO_simple_elem(c, (struct zx_elem_s*)x, sizeof("Heading")-1);
  case zx_gl_LinearRing_ELEM:
    return zx_LEN_WO_gl_LinearRing(c, (struct zx_gl_LinearRing_s*)x);
  case zx_gl_time_ELEM:
    return zx_LEN_WO_simple_elem(c, (struct zx_elem_s*)x, sizeof("time")-1);
  case zx_gl_lev_conf_ELEM:
    return zx_LEN_WO_simple_elem(c, (struct zx_elem_s*)x, sizeof("lev_conf")-1);
  case zx_gl_GeometryCollection_ELEM:
    return zx_LEN_WO_gl_GeometryCollection(c, (struct zx_gl_GeometryCollection_s*)x);
  case zx_gl_MultiLineString_ELEM:
    return zx_LEN_WO_gl_MultiLineString(c, (struct zx_gl_MultiLineString_s*)x);
  case zx_gl_MultiPoint_ELEM:
    return zx_LEN_WO_gl_MultiPoint(c, (struct zx_gl_MultiPoint_s*)x);
  case zx_gl_MultiPolygon_ELEM:
    return zx_LEN_WO_gl_MultiPolygon(c, (struct zx_gl_MultiPolygon_s*)x);
  case zx_hrxml_Date_ELEM:
    return zx_LEN_WO_simple_elem(c, (struct zx_elem_s*)x, sizeof("Date")-1);
  case zx_hrxml_Description_ELEM:
    return zx_LEN_WO_hrxml_Description(c, (struct zx_hrxml_Description_s*)x);
  case zx_hrxml_IssuingAuthority_ELEM:
    return zx_LEN_WO_hrxml_IssuingAuthority(c, (struct zx_hrxml_IssuingAuthority_s*)x);
  case zx_hrxml_Achievement_ELEM:
    return zx_LEN_WO_hrxml_Achievement(c, (struct zx_hrxml_Achievement_s*)x);
  case zx_hrxml_IdValue_ELEM:
    return zx_LEN_WO_hrxml_IdValue(c, (struct zx_hrxml_IdValue_s*)x);
  case zx_hrxml_FormattedName_ELEM:
    return zx_LEN_WO_simple_elem(c, (struct zx_elem_s*)x, sizeof("FormattedName")-1);
  case zx_hrxml_LegalName_ELEM:
    return zx_LEN_WO_simple_elem(c, (struct zx_elem_s*)x, sizeof("LegalName")-1);
  case zx_hrxml_GivenName_ELEM:
    return zx_LEN_WO_simple_elem(c, (struct zx_elem_s*)x, sizeof("GivenName")-1);
  case zx_hrxml_PreferredGivenName_ELEM:
    return zx_LEN_WO_simple_elem(c, (struct zx_elem_s*)x, sizeof("PreferredGivenName")-1);
  case zx_hrxml_MiddleName_ELEM:
    return zx_LEN_WO_simple_elem(c, (struct zx_elem_s*)x, sizeof("MiddleName")-1);
  case zx_hrxml_FamilyName_ELEM:
    return zx_LEN_WO_hrxml_FamilyName(c, (struct zx_hrxml_FamilyName_s*)x);
  case zx_hrxml_Affix_ELEM:
    return zx_LEN_WO_hrxml_Affix(c, (struct zx_hrxml_Affix_s*)x);
  case zx_hrxml_Value_ELEM:
    return zx_LEN_WO_simple_elem(c, (struct zx_elem_s*)x, sizeof("Value")-1);
  case zx_hrxml_Area_ELEM:
    return zx_LEN_WO_hrxml_Area(c, (struct zx_hrxml_Area_s*)x);
  case zx_hrxml_Title_ELEM:
    return zx_LEN_WO_simple_elem(c, (struct zx_elem_s*)x, sizeof("Title")-1);
  case zx_hrxml_Name_ELEM:
    return zx_LEN_WO_simple_elem(c, (struct zx_elem_s*)x, sizeof("Name")-1);
  case zx_hrxml_PublicationDate_ELEM:
    return zx_LEN_WO_hrxml_PublicationDate(c, (struct zx_hrxml_PublicationDate_s*)x);
  case zx_hrxml_Link_ELEM:
    return zx_LEN_WO_simple_elem(c, (struct zx_elem_s*)x, sizeof("Link")-1);
  case zx_hrxml_Abstract_ELEM:
    return zx_LEN_WO_simple_elem(c, (struct zx_elem_s*)x, sizeof("Abstract")-1);
  case zx_hrxml_Copyright_ELEM:
    return zx_LEN_WO_hrxml_Copyright(c, (struct zx_hrxml_Copyright_s*)x);
  case zx_hrxml_Comments_ELEM:
    return zx_LEN_WO_simple_elem(c, (struct zx_elem_s*)x, sizeof("Comments")-1);
  case zx_hrxml_JournalOrSerialName_ELEM:
    return zx_LEN_WO_simple_elem(c, (struct zx_elem_s*)x, sizeof("JournalOrSerialName")-1);
  case zx_hrxml_ISSN_ELEM:
    return zx_LEN_WO_simple_elem(c, (struct zx_elem_s*)x, sizeof("ISSN")-1);
  case zx_hrxml_Volume_ELEM:
    return zx_LEN_WO_simple_elem(c, (struct zx_elem_s*)x, sizeof("Volume")-1);
  case zx_hrxml_Issue_ELEM:
    return zx_LEN_WO_simple_elem(c, (struct zx_elem_s*)x, sizeof("Issue")-1);
  case zx_hrxml_PageNumber_ELEM:
    return zx_LEN_WO_simple_elem(c, (struct zx_elem_s*)x, sizeof("PageNumber")-1);
  case zx_hrxml_PublicationLanguage_ELEM:
    return zx_LEN_WO_hrxml_PublicationLanguage(c, (struct zx_hrxml_PublicationLanguage_s*)x);
  case zx_hrxml_Id_ELEM:
    return zx_LEN_WO_hrxml_Id(c, (struct zx_hrxml_Id_s*)x);
  case zx_hrxml_StartDate_ELEM:
    return zx_LEN_WO_hrxml_StartDate(c, (struct zx_hrxml_StartDate_s*)x);
  case zx_hrxml_EndDate_ELEM:
    return zx_LEN_WO_hrxml_EndDate(c, (struct zx_hrxml_EndDate_s*)x);
  case zx_hrxml_Role_ELEM:
    return zx_LEN_WO_simple_elem(c, (struct zx_elem_s*)x, sizeof("Role")-1);
  case zx_hrxml_Association_ELEM:
    return zx_LEN_WO_hrxml_Association(c, (struct zx_hrxml_Association_s*)x);
  case zx_hrxml_AvailabilityDates_ELEM:
    return zx_LEN_WO_hrxml_AvailabilityDates(c, (struct zx_hrxml_AvailabilityDates_s*)x);
  case zx_hrxml_TermOfNotice_ELEM:
    return zx_LEN_WO_hrxml_TermOfNotice(c, (struct zx_hrxml_TermOfNotice_s*)x);
  case zx_hrxml_BKZId_ELEM:
    return zx_LEN_WO_hrxml_BKZId(c, (struct zx_hrxml_BKZId_s*)x);
  case zx_hrxml_BKZName_ELEM:
    return zx_LEN_WO_simple_elem(c, (struct zx_elem_s*)x, sizeof("BKZName")-1);
  case zx_hrxml_BasePayAmountMin_ELEM:
    return zx_LEN_WO_simple_elem(c, (struct zx_elem_s*)x, sizeof("BasePayAmountMin")-1);
  case zx_hrxml_BasePayAmountMax_ELEM:
    return zx_LEN_WO_simple_elem(c, (struct zx_elem_s*)x, sizeof("BasePayAmountMax")-1);
  case zx_hrxml_Insurance_ELEM:
    return zx_LEN_WO_hrxml_Insurance(c, (struct zx_hrxml_Insurance_s*)x);
  case zx_hrxml_RetirementOrSavingsPlan_ELEM:
    return zx_LEN_WO_simple_elem(c, (struct zx_elem_s*)x, sizeof("RetirementOrSavingsPlan")-1);
  case zx_hrxml_CompanyVehicle_ELEM:
    return zx_LEN_WO_hrxml_CompanyVehicle(c, (struct zx_hrxml_CompanyVehicle_s*)x);
  case zx_hrxml_RelocationAssistance_ELEM:
    return zx_LEN_WO_hrxml_RelocationAssistance(c, (struct zx_hrxml_RelocationAssistance_s*)x);
  case zx_hrxml_VisaSponsorship_ELEM:
    return zx_LEN_WO_simple_elem(c, (struct zx_elem_s*)x, sizeof("VisaSponsorship")-1);
  case zx_hrxml_TimeOffAllowance_ELEM:
    return zx_LEN_WO_hrxml_TimeOffAllowance(c, (struct zx_hrxml_TimeOffAllowance_s*)x);
  case zx_hrxml_ExpatriateBenefits_ELEM:
    return zx_LEN_WO_hrxml_ExpatriateBenefits(c, (struct zx_hrxml_ExpatriateBenefits_s*)x);
  case zx_hrxml_OtherBenefits_ELEM:
    return zx_LEN_WO_hrxml_OtherBenefits(c, (struct zx_hrxml_OtherBenefits_s*)x);
  case zx_hrxml_DateOfBirth_ELEM:
    return zx_LEN_WO_simple_elem(c, (struct zx_elem_s*)x, sizeof("DateOfBirth")-1);
  case zx_hrxml_MonthDayOfBirth_ELEM:
    return zx_LEN_WO_simple_elem(c, (struct zx_elem_s*)x, sizeof("MonthDayOfBirth")-1);
  case zx_hrxml_Age_ELEM:
    return zx_LEN_WO_simple_elem(c, (struct zx_elem_s*)x, sizeof("Age")-1);
  case zx_hrxml_GenderCode_ELEM:
    return zx_LEN_WO_simple_elem(c, (struct zx_elem_s*)x, sizeof("GenderCode")-1);
  case zx_hrxml_EyeColor_ELEM:
    return zx_LEN_WO_simple_elem(c, (struct zx_elem_s*)x, sizeof("EyeColor")-1);
  case zx_hrxml_HairColor_ELEM:
    return zx_LEN_WO_simple_elem(c, (struct zx_elem_s*)x, sizeof("HairColor")-1);
  case zx_hrxml_Height_ELEM:
    return zx_LEN_WO_hrxml_Height(c, (struct zx_hrxml_Height_s*)x);
  case zx_hrxml_Weight_ELEM:
    return zx_LEN_WO_hrxml_Weight(c, (struct zx_hrxml_Weight_s*)x);
  case zx_hrxml_IdentifyingMarks_ELEM:
    return zx_LEN_WO_simple_elem(c, (struct zx_elem_s*)x, sizeof("IdentifyingMarks")-1);
  case zx_hrxml_DisabilityInfo_ELEM:
    return zx_LEN_WO_hrxml_DisabilityInfo(c, (struct zx_hrxml_DisabilityInfo_s*)x);
  case zx_hrxml_UserArea_ELEM:
    return zx_LEN_WO_hrxml_UserArea(c, (struct zx_hrxml_UserArea_s*)x);
  case zx_hrxml_Edition_ELEM:
    return zx_LEN_WO_simple_elem(c, (struct zx_elem_s*)x, sizeof("Edition")-1);
  case zx_hrxml_Chapter_ELEM:
    return zx_LEN_WO_simple_elem(c, (struct zx_elem_s*)x, sizeof("Chapter")-1);
  case zx_hrxml_ISBN_ELEM:
    return zx_LEN_WO_simple_elem(c, (struct zx_elem_s*)x, sizeof("ISBN")-1);
  case zx_hrxml_NumberOfPages_ELEM:
    return zx_LEN_WO_simple_elem(c, (struct zx_elem_s*)x, sizeof("NumberOfPages")-1);
  case zx_hrxml_PublisherName_ELEM:
    return zx_LEN_WO_simple_elem(c, (struct zx_elem_s*)x, sizeof("PublisherName")-1);
  case zx_hrxml_PublisherLocation_ELEM:
    return zx_LEN_WO_simple_elem(c, (struct zx_elem_s*)x, sizeof("PublisherLocation")-1);
  case zx_hrxml_CandidateRecordInfo_ELEM:
    return zx_LEN_WO_hrxml_CandidateRecordInfo(c, (struct zx_hrxml_CandidateRecordInfo_s*)x);
  case zx_hrxml_RelatedPositionPostings_ELEM:
    return zx_LEN_WO_hrxml_RelatedPositionPostings(c, (struct zx_hrxml_RelatedPositionPostings_s*)x);
  case zx_hrxml_CandidateSupplier_ELEM:
    return zx_LEN_WO_hrxml_CandidateSupplier(c, (struct zx_hrxml_CandidateSupplier_s*)x);
  case zx_hrxml_DistributionGuidelines_ELEM:
    return zx_LEN_WO_simple_elem(c, (struct zx_elem_s*)x, sizeof("DistributionGuidelines")-1);
  case zx_hrxml_CandidateProfile_ELEM:
    return zx_LEN_WO_hrxml_CandidateProfile(c, (struct zx_hrxml_CandidateProfile_s*)x);
  case zx_hrxml_Resume_ELEM:
    return zx_LEN_WO_hrxml_Resume(c, (struct zx_hrxml_Resume_s*)x);
  case zx_hrxml_ProfileId_ELEM:
    return zx_LEN_WO_hrxml_ProfileId(c, (struct zx_hrxml_ProfileId_s*)x);
  case zx_hrxml_ProfileName_ELEM:
    return zx_LEN_WO_simple_elem(c, (struct zx_elem_s*)x, sizeof("ProfileName")-1);
  case zx_hrxml_AvailabilityInfo_ELEM:
    return zx_LEN_WO_hrxml_AvailabilityInfo(c, (struct zx_hrxml_AvailabilityInfo_s*)x);
  case zx_hrxml_PersonalData_ELEM:
    return zx_LEN_WO_hrxml_PersonalData(c, (struct zx_hrxml_PersonalData_s*)x);
  case zx_hrxml_PreferredPosition_ELEM:
    return zx_LEN_WO_hrxml_PreferredPosition(c, (struct zx_hrxml_PreferredPosition_s*)x);
  case zx_hrxml_EmploymentHistory_ELEM:
    return zx_LEN_WO_hrxml_EmploymentHistory(c, (struct zx_hrxml_EmploymentHistory_s*)x);
  case zx_hrxml_EducationHistory_ELEM:
    return zx_LEN_WO_hrxml_EducationHistory(c, (struct zx_hrxml_EducationHistory_s*)x);
  case zx_hrxml_MilitaryHistory_ELEM:
    return zx_LEN_WO_hrxml_MilitaryHistory(c, (struct zx_hrxml_MilitaryHistory_s*)x);
  case zx_hrxml_Associations_ELEM:
    return zx_LEN_WO_hrxml_Associations(c, (struct zx_hrxml_Associations_s*)x);
  case zx_hrxml_SupportingMaterials_ELEM:
    return zx_LEN_WO_hrxml_SupportingMaterials(c, (struct zx_hrxml_SupportingMaterials_s*)x);
  case zx_hrxml_Status_ELEM:
    return zx_LEN_WO_hrxml_Status(c, (struct zx_hrxml_Status_s*)x);
  case zx_hrxml_SupplierId_ELEM:
    return zx_LEN_WO_hrxml_SupplierId(c, (struct zx_hrxml_SupplierId_s*)x);
  case zx_hrxml_EntityName_ELEM:
    return zx_LEN_WO_simple_elem(c, (struct zx_elem_s*)x, sizeof("EntityName")-1);
  case zx_hrxml_ContactName_ELEM:
    return zx_LEN_WO_hrxml_ContactName(c, (struct zx_hrxml_ContactName_s*)x);
  case zx_hrxml_ContactMethod_ELEM:
    return zx_LEN_WO_hrxml_ContactMethod(c, (struct zx_hrxml_ContactMethod_s*)x);
  case zx_hrxml_SourceType_ELEM:
    return zx_LEN_WO_hrxml_SourceType(c, (struct zx_hrxml_SourceType_s*)x);
  case zx_hrxml_NumberOfChildren_ELEM:
    return zx_LEN_WO_simple_elem(c, (struct zx_elem_s*)x, sizeof("NumberOfChildren")-1);
  case zx_hrxml_TimeMax_ELEM:
    return zx_LEN_WO_hrxml_TimeMax(c, (struct zx_hrxml_TimeMax_s*)x);
  case zx_hrxml_DistanceMax_ELEM:
    return zx_LEN_WO_hrxml_DistanceMax(c, (struct zx_hrxml_DistanceMax_s*)x);
  case zx_hrxml_StartingCompensation_ELEM:
    return zx_LEN_WO_hrxml_StartingCompensation(c, (struct zx_hrxml_StartingCompensation_s*)x);
  case zx_hrxml_EndingCompensation_ELEM:
    return zx_LEN_WO_hrxml_EndingCompensation(c, (struct zx_hrxml_EndingCompensation_s*)x);
  case zx_hrxml_OtherCompensation_ELEM:
    return zx_LEN_WO_hrxml_OtherCompensation(c, (struct zx_hrxml_OtherCompensation_s*)x);
  case zx_hrxml_CompetencyId_ELEM:
    return zx_LEN_WO_hrxml_CompetencyId(c, (struct zx_hrxml_CompetencyId_s*)x);
  case zx_hrxml_TaxonomyId_ELEM:
    return zx_LEN_WO_hrxml_TaxonomyId(c, (struct zx_hrxml_TaxonomyId_s*)x);
  case zx_hrxml_CompetencyEvidence_ELEM:
    return zx_LEN_WO_hrxml_CompetencyEvidence(c, (struct zx_hrxml_CompetencyEvidence_s*)x);
  case zx_hrxml_CompetencyWeight_ELEM:
    return zx_LEN_WO_hrxml_CompetencyWeight(c, (struct zx_hrxml_CompetencyWeight_s*)x);
  case zx_hrxml_Competency_ELEM:
    return zx_LEN_WO_hrxml_Competency(c, (struct zx_hrxml_Competency_s*)x);
  case zx_hrxml_EvidenceId_ELEM:
    return zx_LEN_WO_hrxml_EvidenceId(c, (struct zx_hrxml_EvidenceId_s*)x);
  case zx_hrxml_NumericValue_ELEM:
    return zx_LEN_WO_hrxml_NumericValue(c, (struct zx_hrxml_NumericValue_s*)x);
  case zx_hrxml_StringValue_ELEM:
    return zx_LEN_WO_hrxml_StringValue(c, (struct zx_hrxml_StringValue_s*)x);
  case zx_hrxml_SupportingInformation_ELEM:
    return zx_LEN_WO_simple_elem(c, (struct zx_elem_s*)x, sizeof("SupportingInformation")-1);
  case zx_hrxml_AnyDate_ELEM:
    return zx_LEN_WO_simple_elem(c, (struct zx_elem_s*)x, sizeof("AnyDate")-1);
  case zx_hrxml_YearMonth_ELEM:
    return zx_LEN_WO_simple_elem(c, (struct zx_elem_s*)x, sizeof("YearMonth")-1);
  case zx_hrxml_Year_ELEM:
    return zx_LEN_WO_simple_elem(c, (struct zx_elem_s*)x, sizeof("Year")-1);
  case zx_hrxml_MonthDay_ELEM:
    return zx_LEN_WO_simple_elem(c, (struct zx_elem_s*)x, sizeof("MonthDay")-1);
  case zx_hrxml_StringDate_ELEM:
    return zx_LEN_WO_simple_elem(c, (struct zx_elem_s*)x, sizeof("StringDate")-1);
  case zx_hrxml_EventName_ELEM:
    return zx_LEN_WO_simple_elem(c, (struct zx_elem_s*)x, sizeof("EventName")-1);
  case zx_hrxml_ConferenceDate_ELEM:
    return zx_LEN_WO_hrxml_ConferenceDate(c, (struct zx_hrxml_ConferenceDate_s*)x);
  case zx_hrxml_ConferenceLocation_ELEM:
    return zx_LEN_WO_simple_elem(c, (struct zx_elem_s*)x, sizeof("ConferenceLocation")-1);
  case zx_hrxml_General_ELEM:
    return zx_LEN_WO_simple_elem(c, (struct zx_elem_s*)x, sizeof("General")-1);
  case zx_hrxml_Physical_ELEM:
    return zx_LEN_WO_simple_elem(c, (struct zx_elem_s*)x, sizeof("Physical")-1);
  case zx_hrxml_SafetyEquipment_ELEM:
    return zx_LEN_WO_hrxml_SafetyEquipment(c, (struct zx_hrxml_SafetyEquipment_s*)x);
  case zx_hrxml_DressCode_ELEM:
    return zx_LEN_WO_hrxml_DressCode(c, (struct zx_hrxml_DressCode_s*)x);
  case zx_hrxml_PersonName_ELEM:
    return zx_LEN_WO_hrxml_PersonName(c, (struct zx_hrxml_PersonName_s*)x);
  case zx_hrxml_Use_ELEM:
    return zx_LEN_WO_simple_elem(c, (struct zx_elem_s*)x, sizeof("Use")-1);
  case zx_hrxml_Location_ELEM:
    return zx_LEN_WO_simple_elem(c, (struct zx_elem_s*)x, sizeof("Location")-1);
  case zx_hrxml_WhenAvailable_ELEM:
    return zx_LEN_WO_simple_elem(c, (struct zx_elem_s*)x, sizeof("WhenAvailable")-1);
  case zx_hrxml_Telephone_ELEM:
    return zx_LEN_WO_hrxml_Telephone(c, (struct zx_hrxml_Telephone_s*)x);
  case zx_hrxml_Mobile_ELEM:
    return zx_LEN_WO_hrxml_Mobile(c, (struct zx_hrxml_Mobile_s*)x);
  case zx_hrxml_Fax_ELEM:
    return zx_LEN_WO_hrxml_Fax(c, (struct zx_hrxml_Fax_s*)x);
  case zx_hrxml_Pager_ELEM:
    return zx_LEN_WO_hrxml_Pager(c, (struct zx_hrxml_Pager_s*)x);
  case zx_hrxml_TTYTDD_ELEM:
    return zx_LEN_WO_hrxml_TTYTDD(c, (struct zx_hrxml_TTYTDD_s*)x);
  case zx_hrxml_InternetEmailAddress_ELEM:
    return zx_LEN_WO_simple_elem(c, (struct zx_elem_s*)x, sizeof("InternetEmailAddress")-1);
  case zx_hrxml_InternetWebAddress_ELEM:
    return zx_LEN_WO_simple_elem(c, (struct zx_elem_s*)x, sizeof("InternetWebAddress")-1);
  case zx_hrxml_PostalAddress_ELEM:
    return zx_LEN_WO_hrxml_PostalAddress(c, (struct zx_hrxml_PostalAddress_s*)x);
  case zx_hrxml_AlternateScript_ELEM:
    return zx_LEN_WO_hrxml_AlternateScript(c, (struct zx_hrxml_AlternateScript_s*)x);
  case zx_hrxml_CopyrightDates_ELEM:
    return zx_LEN_WO_hrxml_CopyrightDates(c, (struct zx_hrxml_CopyrightDates_s*)x);
  case zx_hrxml_CopyrightText_ELEM:
    return zx_LEN_WO_simple_elem(c, (struct zx_elem_s*)x, sizeof("CopyrightText")-1);
  case zx_hrxml_OriginalDate_ELEM:
    return zx_LEN_WO_hrxml_OriginalDate(c, (struct zx_hrxml_OriginalDate_s*)x);
  case zx_hrxml_MostRecentDate_ELEM:
    return zx_LEN_WO_hrxml_MostRecentDate(c, (struct zx_hrxml_MostRecentDate_s*)x);
  case zx_hrxml_DegreeName_ELEM:
    return zx_LEN_WO_hrxml_DegreeName(c, (struct zx_hrxml_DegreeName_s*)x);
  case zx_hrxml_DegreeDate_ELEM:
    return zx_LEN_WO_hrxml_DegreeDate(c, (struct zx_hrxml_DegreeDate_s*)x);
  case zx_hrxml_OtherHonors_ELEM:
    return zx_LEN_WO_hrxml_OtherHonors(c, (struct zx_hrxml_OtherHonors_s*)x);
  case zx_hrxml_DegreeMajor_ELEM:
    return zx_LEN_WO_hrxml_DegreeMajor(c, (struct zx_hrxml_DegreeMajor_s*)x);
  case zx_hrxml_DegreeMinor_ELEM:
    return zx_LEN_WO_hrxml_DegreeMinor(c, (struct zx_hrxml_DegreeMinor_s*)x);
  case zx_hrxml_DegreeMeasure_ELEM:
    return zx_LEN_WO_hrxml_DegreeMeasure(c, (struct zx_hrxml_DegreeMeasure_s*)x);
  case zx_hrxml_DatesOfAttendance_ELEM:
    return zx_LEN_WO_hrxml_DatesOfAttendance(c, (struct zx_hrxml_DatesOfAttendance_s*)x);
  case zx_hrxml_DegreeClassification_ELEM:
    return zx_LEN_WO_hrxml_DegreeClassification(c, (struct zx_hrxml_DegreeClassification_s*)x);
  case zx_hrxml_ProgramId_ELEM:
    return zx_LEN_WO_hrxml_ProgramId(c, (struct zx_hrxml_ProgramId_s*)x);
  case zx_hrxml_DegreeConcentration_ELEM:
    return zx_LEN_WO_simple_elem(c, (struct zx_elem_s*)x, sizeof("DegreeConcentration")-1);
  case zx_hrxml_Option_ELEM:
    return zx_LEN_WO_simple_elem(c, (struct zx_elem_s*)x, sizeof("Option")-1);
  case zx_hrxml_EducationalMeasure_ELEM:
    return zx_LEN_WO_hrxml_EducationalMeasure(c, (struct zx_hrxml_EducationalMeasure_s*)x);
  case zx_hrxml_AcademicCreditCode_ELEM:
    return zx_LEN_WO_simple_elem(c, (struct zx_elem_s*)x, sizeof("AcademicCreditCode")-1);
  case zx_hrxml_CourseLevelCode_ELEM:
    return zx_LEN_WO_simple_elem(c, (struct zx_elem_s*)x, sizeof("CourseLevelCode")-1);
  case zx_hrxml_CumulativeSummaryIndicator_ELEM:
    return zx_LEN_WO_simple_elem(c, (struct zx_elem_s*)x, sizeof("CumulativeSummaryIndicator")-1);
  case zx_hrxml_AcademicCreditHoursIncluded_ELEM:
    return zx_LEN_WO_simple_elem(c, (struct zx_elem_s*)x, sizeof("AcademicCreditHoursIncluded")-1);
  case zx_hrxml_AcademicCreditHoursAttempted_ELEM:
    return zx_LEN_WO_simple_elem(c, (struct zx_elem_s*)x, sizeof("AcademicCreditHoursAttempted")-1);
  case zx_hrxml_AcademicCreditHoursEarned_ELEM:
    return zx_LEN_WO_simple_elem(c, (struct zx_elem_s*)x, sizeof("AcademicCreditHoursEarned")-1);
  case zx_hrxml_ClassRank_ELEM:
    return zx_LEN_WO_hrxml_ClassRank(c, (struct zx_hrxml_ClassRank_s*)x);
  case zx_hrxml_AddressLine_ELEM:
    return zx_LEN_WO_simple_elem(c, (struct zx_elem_s*)x, sizeof("AddressLine")-1);
  case zx_hrxml_StreetName_ELEM:
    return zx_LEN_WO_simple_elem(c, (struct zx_elem_s*)x, sizeof("StreetName")-1);
  case zx_hrxml_BuildingNumber_ELEM:
    return zx_LEN_WO_simple_elem(c, (struct zx_elem_s*)x, sizeof("BuildingNumber")-1);
  case zx_hrxml_Unit_ELEM:
    return zx_LEN_WO_simple_elem(c, (struct zx_elem_s*)x, sizeof("Unit")-1);
  case zx_hrxml_PostOfficeBox_ELEM:
    return zx_LEN_WO_simple_elem(c, (struct zx_elem_s*)x, sizeof("PostOfficeBox")-1);
  case zx_hrxml_Race_ELEM:
    return zx_LEN_WO_simple_elem(c, (struct zx_elem_s*)x, sizeof("Race")-1);
  case zx_hrxml_Ethnicity_ELEM:
    return zx_LEN_WO_simple_elem(c, (struct zx_elem_s*)x, sizeof("Ethnicity")-1);
  case zx_hrxml_Nationality_ELEM:
    return zx_LEN_WO_simple_elem(c, (struct zx_elem_s*)x, sizeof("Nationality")-1);
  case zx_hrxml_PrimaryLanguage_ELEM:
    return zx_LEN_WO_hrxml_PrimaryLanguage(c, (struct zx_hrxml_PrimaryLanguage_s*)x);
  case zx_hrxml_BirthPlace_ELEM:
    return zx_LEN_WO_simple_elem(c, (struct zx_elem_s*)x, sizeof("BirthPlace")-1);
  case zx_hrxml_Religion_ELEM:
    return zx_LEN_WO_simple_elem(c, (struct zx_elem_s*)x, sizeof("Religion")-1);
  case zx_hrxml_MaritalStatus_ELEM:
    return zx_LEN_WO_simple_elem(c, (struct zx_elem_s*)x, sizeof("MaritalStatus")-1);
  case zx_hrxml_ChildrenInfo_ELEM:
    return zx_LEN_WO_hrxml_ChildrenInfo(c, (struct zx_hrxml_ChildrenInfo_s*)x);
  case zx_hrxml_LevelOfDisability_ELEM:
    return zx_LEN_WO_simple_elem(c, (struct zx_elem_s*)x, sizeof("LevelOfDisability")-1);
  case zx_hrxml_Percentage_ELEM:
    return zx_LEN_WO_simple_elem(c, (struct zx_elem_s*)x, sizeof("Percentage")-1);
  case zx_hrxml_Type_ELEM:
    return zx_LEN_WO_simple_elem(c, (struct zx_elem_s*)x, sizeof("Type")-1);
  case zx_hrxml_AccommodationsNeeded_ELEM:
    return zx_LEN_WO_simple_elem(c, (struct zx_elem_s*)x, sizeof("AccommodationsNeeded")-1);
  case zx_hrxml_StandardValue_ELEM:
    return zx_LEN_WO_simple_elem(c, (struct zx_elem_s*)x, sizeof("StandardValue")-1);
  case zx_hrxml_NonStandardValue_ELEM:
    return zx_LEN_WO_simple_elem(c, (struct zx_elem_s*)x, sizeof("NonStandardValue")-1);
  case zx_hrxml_SchoolOrInstitution_ELEM:
    return zx_LEN_WO_hrxml_SchoolOrInstitution(c, (struct zx_hrxml_SchoolOrInstitution_s*)x);
  case zx_hrxml_MeasureSystem_ELEM:
    return zx_LEN_WO_simple_elem(c, (struct zx_elem_s*)x, sizeof("MeasureSystem")-1);
  case zx_hrxml_MeasureValue_ELEM:
    return zx_LEN_WO_simple_elem(c, (struct zx_elem_s*)x, sizeof("MeasureValue")-1);
  case zx_hrxml_LowestPossibleValue_ELEM:
    return zx_LEN_WO_hrxml_LowestPossibleValue(c, (struct zx_hrxml_LowestPossibleValue_s*)x);
  case zx_hrxml_HighestPossibleValue_ELEM:
    return zx_LEN_WO_hrxml_HighestPossibleValue(c, (struct zx_hrxml_HighestPossibleValue_s*)x);
  case zx_hrxml_ExcessiveValueIndicator_ELEM:
    return zx_LEN_WO_simple_elem(c, (struct zx_elem_s*)x, sizeof("ExcessiveValueIndicator")-1);
  case zx_hrxml_GoodStudentIndicator_ELEM:
    return zx_LEN_WO_simple_elem(c, (struct zx_elem_s*)x, sizeof("GoodStudentIndicator")-1);
  case zx_hrxml_LocationSummary_ELEM:
    return zx_LEN_WO_hrxml_LocationSummary(c, (struct zx_hrxml_LocationSummary_s*)x);
  case zx_hrxml_InternetDomainName_ELEM:
    return zx_LEN_WO_hrxml_InternetDomainName(c, (struct zx_hrxml_InternetDomainName_s*)x);
  case zx_hrxml_EmployerOrgName_ELEM:
    return zx_LEN_WO_simple_elem(c, (struct zx_elem_s*)x, sizeof("EmployerOrgName")-1);
  case zx_hrxml_EmployerContactInfo_ELEM:
    return zx_LEN_WO_hrxml_EmployerContactInfo(c, (struct zx_hrxml_EmployerContactInfo_s*)x);
  case zx_hrxml_PositionHistory_ELEM:
    return zx_LEN_WO_hrxml_PositionHistory(c, (struct zx_hrxml_PositionHistory_s*)x);
  case zx_hrxml_EmployerOrg_ELEM:
    return zx_LEN_WO_hrxml_EmployerOrg(c, (struct zx_hrxml_EmployerOrg_s*)x);
  case zx_hrxml_ExpatriateBenefitsOffered_ELEM:
    return zx_LEN_WO_simple_elem(c, (struct zx_elem_s*)x, sizeof("ExpatriateBenefitsOffered")-1);
  case zx_hrxml_ExpatriateBenefitList_ELEM:
    return zx_LEN_WO_simple_elem(c, (struct zx_elem_s*)x, sizeof("ExpatriateBenefitList")-1);
  case zx_hrxml_FormattedNumber_ELEM:
    return zx_LEN_WO_simple_elem(c, (struct zx_elem_s*)x, sizeof("FormattedNumber")-1);
  case zx_hrxml_InventorName_ELEM:
    return zx_LEN_WO_simple_elem(c, (struct zx_elem_s*)x, sizeof("InventorName")-1);
  case zx_hrxml_TaxonomyName_ELEM:
    return zx_LEN_WO_hrxml_TaxonomyName(c, (struct zx_hrxml_TaxonomyName_s*)x);
  case zx_hrxml_CategoryCode_ELEM:
    return zx_LEN_WO_simple_elem(c, (struct zx_elem_s*)x, sizeof("CategoryCode")-1);
  case zx_hrxml_CategoryDescription_ELEM:
    return zx_LEN_WO_simple_elem(c, (struct zx_elem_s*)x, sizeof("CategoryDescription")-1);
  case zx_hrxml_JobCategory_ELEM:
    return zx_LEN_WO_hrxml_JobCategory(c, (struct zx_hrxml_JobCategory_s*)x);
  case zx_hrxml_JobPlan_ELEM:
    return zx_LEN_WO_simple_elem(c, (struct zx_elem_s*)x, sizeof("JobPlan")-1);
  case zx_hrxml_JobGrade_ELEM:
    return zx_LEN_WO_simple_elem(c, (struct zx_elem_s*)x, sizeof("JobGrade")-1);
  case zx_hrxml_JobStep_ELEM:
    return zx_LEN_WO_simple_elem(c, (struct zx_elem_s*)x, sizeof("JobStep")-1);
  case zx_hrxml_LanguageCode_ELEM:
    return zx_LEN_WO_hrxml_LanguageCode(c, (struct zx_hrxml_LanguageCode_s*)x);
  case zx_hrxml_Read_ELEM:
    return zx_LEN_WO_simple_elem(c, (struct zx_elem_s*)x, sizeof("Read")-1);
  case zx_hrxml_Write_ELEM:
    return zx_LEN_WO_simple_elem(c, (struct zx_elem_s*)x, sizeof("Write")-1);
  case zx_hrxml_Speak_ELEM:
    return zx_LEN_WO_simple_elem(c, (struct zx_elem_s*)x, sizeof("Speak")-1);
  case zx_hrxml_Language_ELEM:
    return zx_LEN_WO_hrxml_Language(c, (struct zx_hrxml_Language_s*)x);
  case zx_hrxml_PersonLegalId_ELEM:
    return zx_LEN_WO_hrxml_PersonLegalId(c, (struct zx_hrxml_PersonLegalId_s*)x);
  case zx_hrxml_MilitaryStatus_ELEM:
    return zx_LEN_WO_hrxml_MilitaryStatus(c, (struct zx_hrxml_MilitaryStatus_s*)x);
  case zx_hrxml_VisaStatus_ELEM:
    return zx_LEN_WO_hrxml_VisaStatus(c, (struct zx_hrxml_VisaStatus_s*)x);
  case zx_hrxml_Citizenship_ELEM:
    return zx_LEN_WO_simple_elem(c, (struct zx_elem_s*)x, sizeof("Citizenship")-1);
  case zx_hrxml_Residency_ELEM:
    return zx_LEN_WO_simple_elem(c, (struct zx_elem_s*)x, sizeof("Residency")-1);
  case zx_hrxml_EffectiveDate_ELEM:
    return zx_LEN_WO_hrxml_EffectiveDate(c, (struct zx_hrxml_EffectiveDate_s*)x);
  case zx_hrxml_LicenseOrCertification_ELEM:
    return zx_LEN_WO_hrxml_LicenseOrCertification(c, (struct zx_hrxml_LicenseOrCertification_s*)x);
  case zx_hrxml_Item_ELEM:
    return zx_LEN_WO_simple_elem(c, (struct zx_elem_s*)x, sizeof("Item")-1);
  case zx_hrxml_Municipality_ELEM:
    return zx_LEN_WO_simple_elem(c, (struct zx_elem_s*)x, sizeof("Municipality")-1);
  case zx_hrxml_Region_ELEM:
    return zx_LEN_WO_simple_elem(c, (struct zx_elem_s*)x, sizeof("Region")-1);
  case zx_hrxml_CountryCode_ELEM:
    return zx_LEN_WO_simple_elem(c, (struct zx_elem_s*)x, sizeof("CountryCode")-1);
  case zx_hrxml_PostalCode_ELEM:
    return zx_LEN_WO_simple_elem(c, (struct zx_elem_s*)x, sizeof("PostalCode")-1);
  case zx_hrxml_CountryServed_ELEM:
    return zx_LEN_WO_simple_elem(c, (struct zx_elem_s*)x, sizeof("CountryServed")-1);
  case zx_hrxml_ServiceNumber_ELEM:
    return zx_LEN_WO_hrxml_ServiceNumber(c, (struct zx_hrxml_ServiceNumber_s*)x);
  case zx_hrxml_ServiceDetail_ELEM:
    return zx_LEN_WO_hrxml_ServiceDetail(c, (struct zx_hrxml_ServiceDetail_s*)x);
  case zx_hrxml_ServiceStatus_ELEM:
    return zx_LEN_WO_simple_elem(c, (struct zx_elem_s*)x, sizeof("ServiceStatus")-1);
  case zx_hrxml_TextResume_ELEM:
    return zx_LEN_WO_simple_elem(c, (struct zx_elem_s*)x, sizeof("TextResume")-1);
  case zx_hrxml_LinkToResume_ELEM:
    return zx_LEN_WO_simple_elem(c, (struct zx_elem_s*)x, sizeof("LinkToResume")-1);
  case zx_hrxml_RevisionDate_ELEM:
    return zx_LEN_WO_simple_elem(c, (struct zx_elem_s*)x, sizeof("RevisionDate")-1);
  case zx_hrxml_IndustryDescription_ELEM:
    return zx_LEN_WO_simple_elem(c, (struct zx_elem_s*)x, sizeof("IndustryDescription")-1);
  case zx_hrxml_IndustryCode_ELEM:
    return zx_LEN_WO_hrxml_IndustryCode(c, (struct zx_hrxml_IndustryCode_s*)x);
  case zx_hrxml_PositionLocation_ELEM:
    return zx_LEN_WO_hrxml_PositionLocation(c, (struct zx_hrxml_PositionLocation_s*)x);
  case zx_hrxml_WebSite_ELEM:
    return zx_LEN_WO_simple_elem(c, (struct zx_elem_s*)x, sizeof("WebSite")-1);
  case zx_hrxml_OrganizationName_ELEM:
    return zx_LEN_WO_simple_elem(c, (struct zx_elem_s*)x, sizeof("OrganizationName")-1);
  case zx_hrxml_OrgName_ELEM:
    return zx_LEN_WO_hrxml_OrgName(c, (struct zx_hrxml_OrgName_s*)x);
  case zx_hrxml_OrganizationalUnitName_ELEM:
    return zx_LEN_WO_simple_elem(c, (struct zx_elem_s*)x, sizeof("OrganizationalUnitName")-1);
  case zx_hrxml_OrganizationalUnitId_ELEM:
    return zx_LEN_WO_hrxml_OrganizationalUnitId(c, (struct zx_hrxml_OrganizationalUnitId_s*)x);
  case zx_hrxml_OrganizationId_ELEM:
    return zx_LEN_WO_hrxml_OrganizationId(c, (struct zx_hrxml_OrganizationId_s*)x);
  case zx_hrxml_AccountingCode_ELEM:
    return zx_LEN_WO_hrxml_AccountingCode(c, (struct zx_hrxml_AccountingCode_s*)x);
  case zx_hrxml_WorkSite_ELEM:
    return zx_LEN_WO_hrxml_WorkSite(c, (struct zx_hrxml_WorkSite_s*)x);
  case zx_hrxml_RelatedOrganizationalUnit_ELEM:
    return zx_LEN_WO_hrxml_RelatedOrganizationalUnit(c, (struct zx_hrxml_RelatedOrganizationalUnit_s*)x);
  case zx_hrxml_PersonMember_ELEM:
    return zx_LEN_WO_hrxml_PersonMember(c, (struct zx_hrxml_PersonMember_s*)x);
  case zx_hrxml_Applicable_ELEM:
    return zx_LEN_WO_simple_elem(c, (struct zx_elem_s*)x, sizeof("Applicable")-1);
  case zx_hrxml_List_ELEM:
    return zx_LEN_WO_hrxml_List(c, (struct zx_hrxml_List_s*)x);
  case zx_hrxml_OtherPayAmountMin_ELEM:
    return zx_LEN_WO_simple_elem(c, (struct zx_elem_s*)x, sizeof("OtherPayAmountMin")-1);
  case zx_hrxml_OtherPayAmountMax_ELEM:
    return zx_LEN_WO_simple_elem(c, (struct zx_elem_s*)x, sizeof("OtherPayAmountMax")-1);
  case zx_hrxml_OtherPayCalculation_ELEM:
    return zx_LEN_WO_simple_elem(c, (struct zx_elem_s*)x, sizeof("OtherPayCalculation")-1);
  case zx_hrxml_PatentTitle_ELEM:
    return zx_LEN_WO_simple_elem(c, (struct zx_elem_s*)x, sizeof("PatentTitle")-1);
  case zx_hrxml_Inventors_ELEM:
    return zx_LEN_WO_hrxml_Inventors(c, (struct zx_hrxml_Inventors_s*)x);
  case zx_hrxml_PatentDetail_ELEM:
    return zx_LEN_WO_hrxml_PatentDetail(c, (struct zx_hrxml_PatentDetail_s*)x);
  case zx_hrxml_PatentMilestone_ELEM:
    return zx_LEN_WO_hrxml_PatentMilestone(c, (struct zx_hrxml_PatentMilestone_s*)x);
  case zx_hrxml_Patent_ELEM:
    return zx_LEN_WO_hrxml_Patent(c, (struct zx_hrxml_Patent_s*)x);
  case zx_hrxml_LegalIdentifiers_ELEM:
    return zx_LEN_WO_hrxml_LegalIdentifiers(c, (struct zx_hrxml_LegalIdentifiers_s*)x);
  case zx_hrxml_DemographicDescriptors_ELEM:
    return zx_LEN_WO_hrxml_DemographicDescriptors(c, (struct zx_hrxml_DemographicDescriptors_s*)x);
  case zx_hrxml_BiologicalDescriptors_ELEM:
    return zx_LEN_WO_hrxml_BiologicalDescriptors(c, (struct zx_hrxml_BiologicalDescriptors_s*)x);
  case zx_hrxml_OtherDescriptors_ELEM:
    return zx_LEN_WO_hrxml_OtherDescriptors(c, (struct zx_hrxml_OtherDescriptors_s*)x);
  case zx_hrxml_PersonId_ELEM:
    return zx_LEN_WO_hrxml_PersonId(c, (struct zx_hrxml_PersonId_s*)x);
  case zx_hrxml_PersonRole_ELEM:
    return zx_LEN_WO_hrxml_PersonRole(c, (struct zx_hrxml_PersonRole_s*)x);
  case zx_hrxml_RoleName_ELEM:
    return zx_LEN_WO_simple_elem(c, (struct zx_elem_s*)x, sizeof("RoleName")-1);
  case zx_hrxml_RoleId_ELEM:
    return zx_LEN_WO_hrxml_RoleId(c, (struct zx_hrxml_RoleId_s*)x);
  case zx_hrxml_PersonDescriptors_ELEM:
    return zx_LEN_WO_hrxml_PersonDescriptors(c, (struct zx_hrxml_PersonDescriptors_s*)x);
  case zx_hrxml_SpatialLocation_ELEM:
    return zx_LEN_WO_hrxml_SpatialLocation(c, (struct zx_hrxml_SpatialLocation_s*)x);
  case zx_hrxml_TravelDirections_ELEM:
    return zx_LEN_WO_hrxml_TravelDirections(c, (struct zx_hrxml_TravelDirections_s*)x);
  case zx_hrxml_OrgInfo_ELEM:
    return zx_LEN_WO_hrxml_OrgInfo(c, (struct zx_hrxml_OrgInfo_s*)x);
  case zx_hrxml_OrgIndustry_ELEM:
    return zx_LEN_WO_hrxml_OrgIndustry(c, (struct zx_hrxml_OrgIndustry_s*)x);
  case zx_hrxml_OrgSize_ELEM:
    return zx_LEN_WO_simple_elem(c, (struct zx_elem_s*)x, sizeof("OrgSize")-1);
  case zx_hrxml_Compensation_ELEM:
    return zx_LEN_WO_hrxml_Compensation(c, (struct zx_hrxml_Compensation_s*)x);
  case zx_hrxml_Verification_ELEM:
    return zx_LEN_WO_hrxml_Verification(c, (struct zx_hrxml_Verification_s*)x);
  case zx_hrxml_JobLevelInfo_ELEM:
    return zx_LEN_WO_hrxml_JobLevelInfo(c, (struct zx_hrxml_JobLevelInfo_s*)x);
  case zx_hrxml_DeliveryAddress_ELEM:
    return zx_LEN_WO_hrxml_DeliveryAddress(c, (struct zx_hrxml_DeliveryAddress_s*)x);
  case zx_hrxml_Recipient_ELEM:
    return zx_LEN_WO_hrxml_Recipient(c, (struct zx_hrxml_Recipient_s*)x);
  case zx_hrxml_Company_ELEM:
    return zx_LEN_WO_hrxml_Company(c, (struct zx_hrxml_Company_s*)x);
  case zx_hrxml_CompanyScale_ELEM:
    return zx_LEN_WO_simple_elem(c, (struct zx_elem_s*)x, sizeof("CompanyScale")-1);
  case zx_hrxml_PhysicalLocation_ELEM:
    return zx_LEN_WO_hrxml_PhysicalLocation(c, (struct zx_hrxml_PhysicalLocation_s*)x);
  case zx_hrxml_PositionTitle_ELEM:
    return zx_LEN_WO_simple_elem(c, (struct zx_elem_s*)x, sizeof("PositionTitle")-1);
  case zx_hrxml_PositionClassification_ELEM:
    return zx_LEN_WO_simple_elem(c, (struct zx_elem_s*)x, sizeof("PositionClassification")-1);
  case zx_hrxml_PositionSchedule_ELEM:
    return zx_LEN_WO_hrxml_PositionSchedule(c, (struct zx_hrxml_PositionSchedule_s*)x);
  case zx_hrxml_Shift_ELEM:
    return zx_LEN_WO_hrxml_Shift(c, (struct zx_hrxml_Shift_s*)x);
  case zx_hrxml_RemunerationPackage_ELEM:
    return zx_LEN_WO_hrxml_RemunerationPackage(c, (struct zx_hrxml_RemunerationPackage_s*)x);
  case zx_hrxml_WorkStyle_ELEM:
    return zx_LEN_WO_simple_elem(c, (struct zx_elem_s*)x, sizeof("WorkStyle")-1);
  case zx_hrxml_Travel_ELEM:
    return zx_LEN_WO_hrxml_Travel(c, (struct zx_hrxml_Travel_s*)x);
  case zx_hrxml_Relocation_ELEM:
    return zx_LEN_WO_hrxml_Relocation(c, (struct zx_hrxml_Relocation_s*)x);
  case zx_hrxml_PreferredLanguage_ELEM:
    return zx_LEN_WO_hrxml_PreferredLanguage(c, (struct zx_hrxml_PreferredLanguage_s*)x);
  case zx_hrxml_SearchCriteria_ELEM:
    return zx_LEN_WO_hrxml_SearchCriteria(c, (struct zx_hrxml_SearchCriteria_s*)x);
  case zx_hrxml_SearchResult_ELEM:
    return zx_LEN_WO_hrxml_SearchResult(c, (struct zx_hrxml_SearchResult_s*)x);
  case zx_hrxml_Commute_ELEM:
    return zx_LEN_WO_hrxml_Commute(c, (struct zx_hrxml_Commute_s*)x);
  case zx_hrxml_BasePay_ELEM:
    return zx_LEN_WO_hrxml_BasePay(c, (struct zx_hrxml_BasePay_s*)x);
  case zx_hrxml_OtherPay_ELEM:
    return zx_LEN_WO_hrxml_OtherPay(c, (struct zx_hrxml_OtherPay_s*)x);
  case zx_hrxml_Benefits_ELEM:
    return zx_LEN_WO_hrxml_Benefits(c, (struct zx_hrxml_Benefits_s*)x);
  case zx_hrxml_FormattedPublicationDescription_ELEM:
    return zx_LEN_WO_hrxml_FormattedPublicationDescription(c, (struct zx_hrxml_FormattedPublicationDescription_s*)x);
  case zx_hrxml_Article_ELEM:
    return zx_LEN_WO_hrxml_Article(c, (struct zx_hrxml_Article_s*)x);
  case zx_hrxml_Book_ELEM:
    return zx_LEN_WO_hrxml_Book(c, (struct zx_hrxml_Book_s*)x);
  case zx_hrxml_ConferencePaper_ELEM:
    return zx_LEN_WO_hrxml_ConferencePaper(c, (struct zx_hrxml_ConferencePaper_s*)x);
  case zx_hrxml_OtherPublication_ELEM:
    return zx_LEN_WO_hrxml_OtherPublication(c, (struct zx_hrxml_OtherPublication_s*)x);
  case zx_hrxml_QualificationSummary_ELEM:
    return zx_LEN_WO_simple_elem(c, (struct zx_elem_s*)x, sizeof("QualificationSummary")-1);
  case zx_hrxml_StartRank_ELEM:
    return zx_LEN_WO_simple_elem(c, (struct zx_elem_s*)x, sizeof("StartRank")-1);
  case zx_hrxml_CurrentOrEndRank_ELEM:
    return zx_LEN_WO_simple_elem(c, (struct zx_elem_s*)x, sizeof("CurrentOrEndRank")-1);
  case zx_hrxml_CriterionName_ELEM:
    return zx_LEN_WO_simple_elem(c, (struct zx_elem_s*)x, sizeof("CriterionName")-1);
  case zx_hrxml_Requested_ELEM:
    return zx_LEN_WO_simple_elem(c, (struct zx_elem_s*)x, sizeof("Requested")-1);
  case zx_hrxml_Offered_ELEM:
    return zx_LEN_WO_simple_elem(c, (struct zx_elem_s*)x, sizeof("Offered")-1);
  case zx_hrxml_Score_ELEM:
    return zx_LEN_WO_hrxml_Score(c, (struct zx_hrxml_Score_s*)x);
  case zx_hrxml_RankedResult_ELEM:
    return zx_LEN_WO_hrxml_RankedResult(c, (struct zx_hrxml_RankedResult_s*)x);
  case zx_hrxml_AdditionalText_ELEM:
    return zx_LEN_WO_simple_elem(c, (struct zx_elem_s*)x, sizeof("AdditionalText")-1);
  case zx_hrxml_Organization_ELEM:
    return zx_LEN_WO_hrxml_Organization(c, (struct zx_hrxml_Organization_s*)x);
  case zx_hrxml_Reference_ELEM:
    return zx_LEN_WO_hrxml_Reference(c, (struct zx_hrxml_Reference_s*)x);
  case zx_hrxml_TaxId_ELEM:
    return zx_LEN_WO_hrxml_TaxId(c, (struct zx_hrxml_TaxId_s*)x);
  case zx_hrxml_LegalId_ELEM:
    return zx_LEN_WO_hrxml_LegalId(c, (struct zx_hrxml_LegalId_s*)x);
  case zx_hrxml_DunsNumber_ELEM:
    return zx_LEN_WO_hrxml_DunsNumber(c, (struct zx_hrxml_DunsNumber_s*)x);
  case zx_hrxml_IsPublicCompany_ELEM:
    return zx_LEN_WO_simple_elem(c, (struct zx_elem_s*)x, sizeof("IsPublicCompany")-1);
  case zx_hrxml_Stock_ELEM:
    return zx_LEN_WO_hrxml_Stock(c, (struct zx_hrxml_Stock_s*)x);
  case zx_hrxml_MissionStatement_ELEM:
    return zx_LEN_WO_simple_elem(c, (struct zx_elem_s*)x, sizeof("MissionStatement")-1);
  case zx_hrxml_ValueStatement_ELEM:
    return zx_LEN_WO_simple_elem(c, (struct zx_elem_s*)x, sizeof("ValueStatement")-1);
  case zx_hrxml_DoingBusinessAs_ELEM:
    return zx_LEN_WO_hrxml_DoingBusinessAs(c, (struct zx_hrxml_DoingBusinessAs_s*)x);
  case zx_hrxml_LegalClassification_ELEM:
    return zx_LEN_WO_hrxml_LegalClassification(c, (struct zx_hrxml_LegalClassification_s*)x);
  case zx_hrxml_Headcount_ELEM:
    return zx_LEN_WO_simple_elem(c, (struct zx_elem_s*)x, sizeof("Headcount")-1);
  case zx_hrxml_ContactInfo_ELEM:
    return zx_LEN_WO_hrxml_ContactInfo(c, (struct zx_hrxml_ContactInfo_s*)x);
  case zx_hrxml_RelatedOrganization_ELEM:
    return zx_LEN_WO_hrxml_RelatedOrganization(c, (struct zx_hrxml_RelatedOrganization_s*)x);
  case zx_hrxml_OrganizationalUnit_ELEM:
    return zx_LEN_WO_hrxml_OrganizationalUnit(c, (struct zx_hrxml_OrganizationalUnit_s*)x);
  case zx_hrxml_PositionPosting_ELEM:
    return zx_LEN_WO_hrxml_PositionPosting(c, (struct zx_hrxml_PositionPosting_s*)x);
  case zx_hrxml_ResumeId_ELEM:
    return zx_LEN_WO_simple_elem(c, (struct zx_elem_s*)x, sizeof("ResumeId")-1);
  case zx_hrxml_StructuredXMLResume_ELEM:
    return zx_LEN_WO_hrxml_StructuredXMLResume(c, (struct zx_hrxml_StructuredXMLResume_s*)x);
  case zx_hrxml_NonXMLResume_ELEM:
    return zx_LEN_WO_hrxml_NonXMLResume(c, (struct zx_hrxml_NonXMLResume_s*)x);
  case zx_hrxml_ResumeAdditionalItem_ELEM:
    return zx_LEN_WO_hrxml_ResumeAdditionalItem(c, (struct zx_hrxml_ResumeAdditionalItem_s*)x);
  case zx_hrxml_SchoolId_ELEM:
    return zx_LEN_WO_hrxml_SchoolId(c, (struct zx_hrxml_SchoolId_s*)x);
  case zx_hrxml_SchoolName_ELEM:
    return zx_LEN_WO_simple_elem(c, (struct zx_elem_s*)x, sizeof("SchoolName")-1);
  case zx_hrxml_School_ELEM:
    return zx_LEN_WO_hrxml_School(c, (struct zx_hrxml_School_s*)x);
  case zx_hrxml_OrganizationUnit_ELEM:
    return zx_LEN_WO_hrxml_OrganizationUnit(c, (struct zx_hrxml_OrganizationUnit_s*)x);
  case zx_hrxml_Degree_ELEM:
    return zx_LEN_WO_hrxml_Degree(c, (struct zx_hrxml_Degree_s*)x);
  case zx_hrxml_Major_ELEM:
    return zx_LEN_WO_simple_elem(c, (struct zx_elem_s*)x, sizeof("Major")-1);
  case zx_hrxml_Minor_ELEM:
    return zx_LEN_WO_simple_elem(c, (struct zx_elem_s*)x, sizeof("Minor")-1);
  case zx_hrxml_Measure_ELEM:
    return zx_LEN_WO_hrxml_Measure(c, (struct zx_hrxml_Measure_s*)x);
  case zx_hrxml_ISCEDInstitutionClassification_ELEM:
    return zx_LEN_WO_simple_elem(c, (struct zx_elem_s*)x, sizeof("ISCEDInstitutionClassification")-1);
  case zx_hrxml_LocalInstitutionClassification_ELEM:
    return zx_LEN_WO_hrxml_LocalInstitutionClassification(c, (struct zx_hrxml_LocalInstitutionClassification_s*)x);
  case zx_hrxml_SearchCriteriaId_ELEM:
    return zx_LEN_WO_hrxml_SearchCriteriaId(c, (struct zx_hrxml_SearchCriteriaId_s*)x);
  case zx_hrxml_SearchTarget_ELEM:
    return zx_LEN_WO_simple_elem(c, (struct zx_elem_s*)x, sizeof("SearchTarget")-1);
  case zx_hrxml_UserId_ELEM:
    return zx_LEN_WO_hrxml_UserId(c, (struct zx_hrxml_UserId_s*)x);
  case zx_hrxml_SearchTimeStamp_ELEM:
    return zx_LEN_WO_simple_elem(c, (struct zx_elem_s*)x, sizeof("SearchTimeStamp")-1);
  case zx_hrxml_SearchString_ELEM:
    return zx_LEN_WO_simple_elem(c, (struct zx_elem_s*)x, sizeof("SearchString")-1);
  case zx_hrxml_SearchCriterion_ELEM:
    return zx_LEN_WO_hrxml_SearchCriterion(c, (struct zx_hrxml_SearchCriterion_s*)x);
  case zx_hrxml_CriterionValue_ELEM:
    return zx_LEN_WO_simple_elem(c, (struct zx_elem_s*)x, sizeof("CriterionValue")-1);
  case zx_hrxml_SearchResultId_ELEM:
    return zx_LEN_WO_hrxml_SearchResultId(c, (struct zx_hrxml_SearchResultId_s*)x);
  case zx_hrxml_MatchedObjectId_ELEM:
    return zx_LEN_WO_hrxml_MatchedObjectId(c, (struct zx_hrxml_MatchedObjectId_s*)x);
  case zx_hrxml_SearchRelevanceScore_ELEM:
    return zx_LEN_WO_hrxml_SearchRelevanceScore(c, (struct zx_hrxml_SearchRelevanceScore_s*)x);
  case zx_hrxml_SearchRelevanceRank_ELEM:
    return zx_LEN_WO_simple_elem(c, (struct zx_elem_s*)x, sizeof("SearchRelevanceRank")-1);
  case zx_hrxml_SearchResultCount_ELEM:
    return zx_LEN_WO_simple_elem(c, (struct zx_elem_s*)x, sizeof("SearchResultCount")-1);
  case zx_hrxml_RankedSearchResults_ELEM:
    return zx_LEN_WO_hrxml_RankedSearchResults(c, (struct zx_hrxml_RankedSearchResults_s*)x);
  case zx_hrxml_SecurityCredential_ELEM:
    return zx_LEN_WO_hrxml_SecurityCredential(c, (struct zx_hrxml_SecurityCredential_s*)x);
  case zx_hrxml_UnitOrDivision_ELEM:
    return zx_LEN_WO_simple_elem(c, (struct zx_elem_s*)x, sizeof("UnitOrDivision")-1);
  case zx_hrxml_RankAchieved_ELEM:
    return zx_LEN_WO_hrxml_RankAchieved(c, (struct zx_hrxml_RankAchieved_s*)x);
  case zx_hrxml_DatesOfService_ELEM:
    return zx_LEN_WO_hrxml_DatesOfService(c, (struct zx_hrxml_DatesOfService_s*)x);
  case zx_hrxml_Campaign_ELEM:
    return zx_LEN_WO_simple_elem(c, (struct zx_elem_s*)x, sizeof("Campaign")-1);
  case zx_hrxml_AreaOfExpertise_ELEM:
    return zx_LEN_WO_simple_elem(c, (struct zx_elem_s*)x, sizeof("AreaOfExpertise")-1);
  case zx_hrxml_RecognitionAchieved_ELEM:
    return zx_LEN_WO_simple_elem(c, (struct zx_elem_s*)x, sizeof("RecognitionAchieved")-1);
  case zx_hrxml_DisciplinaryAction_ELEM:
    return zx_LEN_WO_simple_elem(c, (struct zx_elem_s*)x, sizeof("DisciplinaryAction")-1);
  case zx_hrxml_DischargeStatus_ELEM:
    return zx_LEN_WO_simple_elem(c, (struct zx_elem_s*)x, sizeof("DischargeStatus")-1);
  case zx_hrxml_Hours_ELEM:
    return zx_LEN_WO_simple_elem(c, (struct zx_elem_s*)x, sizeof("Hours")-1);
  case zx_hrxml_StartTime_ELEM:
    return zx_LEN_WO_simple_elem(c, (struct zx_elem_s*)x, sizeof("StartTime")-1);
  case zx_hrxml_EndTime_ELEM:
    return zx_LEN_WO_simple_elem(c, (struct zx_elem_s*)x, sizeof("EndTime")-1);
  case zx_hrxml_PayTypeHours_ELEM:
    return zx_LEN_WO_simple_elem(c, (struct zx_elem_s*)x, sizeof("PayTypeHours")-1);
  case zx_hrxml_Latitude_ELEM:
    return zx_LEN_WO_hrxml_Latitude(c, (struct zx_hrxml_Latitude_s*)x);
  case zx_hrxml_Longitude_ELEM:
    return zx_LEN_WO_hrxml_Longitude(c, (struct zx_hrxml_Longitude_s*)x);
  case zx_hrxml_Altitude_ELEM:
    return zx_LEN_WO_simple_elem(c, (struct zx_elem_s*)x, sizeof("Altitude")-1);
  case zx_hrxml_AltitudeMeanSeaLevel_ELEM:
    return zx_LEN_WO_simple_elem(c, (struct zx_elem_s*)x, sizeof("AltitudeMeanSeaLevel")-1);
  case zx_hrxml_HorizontalAccuracy_ELEM:
    return zx_LEN_WO_hrxml_HorizontalAccuracy(c, (struct zx_hrxml_HorizontalAccuracy_s*)x);
  case zx_hrxml_VerticalAccuracy_ELEM:
    return zx_LEN_WO_hrxml_VerticalAccuracy(c, (struct zx_hrxml_VerticalAccuracy_s*)x);
  case zx_hrxml_EventType_ELEM:
    return zx_LEN_WO_simple_elem(c, (struct zx_elem_s*)x, sizeof("EventType")-1);
  case zx_hrxml_AffiliatedOrganization_ELEM:
    return zx_LEN_WO_simple_elem(c, (struct zx_elem_s*)x, sizeof("AffiliatedOrganization")-1);
  case zx_hrxml_SpeakingEvent_ELEM:
    return zx_LEN_WO_hrxml_SpeakingEvent(c, (struct zx_hrxml_SpeakingEvent_s*)x);
  case zx_hrxml_ProficencyLevel_ELEM:
    return zx_LEN_WO_simple_elem(c, (struct zx_elem_s*)x, sizeof("ProficencyLevel")-1);
  case zx_hrxml_Symbol_ELEM:
    return zx_LEN_WO_simple_elem(c, (struct zx_elem_s*)x, sizeof("Symbol")-1);
  case zx_hrxml_Exchange_ELEM:
    return zx_LEN_WO_simple_elem(c, (struct zx_elem_s*)x, sizeof("Exchange")-1);
  case zx_hrxml_ExecutiveSummary_ELEM:
    return zx_LEN_WO_simple_elem(c, (struct zx_elem_s*)x, sizeof("ExecutiveSummary")-1);
  case zx_hrxml_Objective_ELEM:
    return zx_LEN_WO_simple_elem(c, (struct zx_elem_s*)x, sizeof("Objective")-1);
  case zx_hrxml_LicensesAndCertifications_ELEM:
    return zx_LEN_WO_hrxml_LicensesAndCertifications(c, (struct zx_hrxml_LicensesAndCertifications_s*)x);
  case zx_hrxml_PatentHistory_ELEM:
    return zx_LEN_WO_hrxml_PatentHistory(c, (struct zx_hrxml_PatentHistory_s*)x);
  case zx_hrxml_PublicationHistory_ELEM:
    return zx_LEN_WO_hrxml_PublicationHistory(c, (struct zx_hrxml_PublicationHistory_s*)x);
  case zx_hrxml_SpeakingEventsHistory_ELEM:
    return zx_LEN_WO_hrxml_SpeakingEventsHistory(c, (struct zx_hrxml_SpeakingEventsHistory_s*)x);
  case zx_hrxml_Qualifications_ELEM:
    return zx_LEN_WO_hrxml_Qualifications(c, (struct zx_hrxml_Qualifications_s*)x);
  case zx_hrxml_Languages_ELEM:
    return zx_LEN_WO_hrxml_Languages(c, (struct zx_hrxml_Languages_s*)x);
  case zx_hrxml_Achievements_ELEM:
    return zx_LEN_WO_hrxml_Achievements(c, (struct zx_hrxml_Achievements_s*)x);
  case zx_hrxml_References_ELEM:
    return zx_LEN_WO_hrxml_References(c, (struct zx_hrxml_References_s*)x);
  case zx_hrxml_SecurityCredentials_ELEM:
    return zx_LEN_WO_hrxml_SecurityCredentials(c, (struct zx_hrxml_SecurityCredentials_s*)x);
  case zx_hrxml_ResumeAdditionalItems_ELEM:
    return zx_LEN_WO_hrxml_ResumeAdditionalItems(c, (struct zx_hrxml_ResumeAdditionalItems_s*)x);
  case zx_hrxml_ProfessionalAssociations_ELEM:
    return zx_LEN_WO_hrxml_ProfessionalAssociations(c, (struct zx_hrxml_ProfessionalAssociations_s*)x);
  case zx_hrxml_AttachmentReference_ELEM:
    return zx_LEN_WO_hrxml_AttachmentReference(c, (struct zx_hrxml_AttachmentReference_s*)x);
  case zx_hrxml_Interval_ELEM:
    return zx_LEN_WO_simple_elem(c, (struct zx_elem_s*)x, sizeof("Interval")-1);
  case zx_hrxml_TravelFrequency_ELEM:
    return zx_LEN_WO_simple_elem(c, (struct zx_elem_s*)x, sizeof("TravelFrequency")-1);
  case zx_hrxml_TravelConsiderations_ELEM:
    return zx_LEN_WO_simple_elem(c, (struct zx_elem_s*)x, sizeof("TravelConsiderations")-1);
  case zx_hrxml_ReasonForLeaving_ELEM:
    return zx_LEN_WO_simple_elem(c, (struct zx_elem_s*)x, sizeof("ReasonForLeaving")-1);
  case zx_hrxml_PermissionToContact_ELEM:
    return zx_LEN_WO_simple_elem(c, (struct zx_elem_s*)x, sizeof("PermissionToContact")-1);
  case zx_hrxml_VerifyEmployment_ELEM:
    return zx_LEN_WO_simple_elem(c, (struct zx_elem_s*)x, sizeof("VerifyEmployment")-1);
  case zx_hrxml_EligibleForRehire_ELEM:
    return zx_LEN_WO_simple_elem(c, (struct zx_elem_s*)x, sizeof("EligibleForRehire")-1);
  case zx_hrxml_AttendanceRating_ELEM:
    return zx_LEN_WO_simple_elem(c, (struct zx_elem_s*)x, sizeof("AttendanceRating")-1);
  case zx_hrxml_OverallPerformanceRating_ELEM:
    return zx_LEN_WO_simple_elem(c, (struct zx_elem_s*)x, sizeof("OverallPerformanceRating")-1);
  case zx_hrxml_QuestionAnswerPair_ELEM:
    return zx_LEN_WO_simple_elem(c, (struct zx_elem_s*)x, sizeof("QuestionAnswerPair")-1);
  case zx_hrxml_WorkSiteName_ELEM:
    return zx_LEN_WO_simple_elem(c, (struct zx_elem_s*)x, sizeof("WorkSiteName")-1);
  case zx_hrxml_WorkSiteId_ELEM:
    return zx_LEN_WO_hrxml_WorkSiteId(c, (struct zx_hrxml_WorkSiteId_s*)x);
  case zx_hrxml_Details_ELEM:
    return zx_LEN_WO_hrxml_Details(c, (struct zx_hrxml_Details_s*)x);
  case zx_hrxml_ParkingInstructions_ELEM:
    return zx_LEN_WO_hrxml_ParkingInstructions(c, (struct zx_hrxml_ParkingInstructions_s*)x);
  case zx_hrxml_WorkSiteEnvironment_ELEM:
    return zx_LEN_WO_hrxml_WorkSiteEnvironment(c, (struct zx_hrxml_WorkSiteEnvironment_s*)x);
  case zx_hrxml_EnvironmentName_ELEM:
    return zx_LEN_WO_simple_elem(c, (struct zx_elem_s*)x, sizeof("EnvironmentName")-1);
  case zx_hrxml_EnvironmentId_ELEM:
    return zx_LEN_WO_hrxml_EnvironmentId(c, (struct zx_hrxml_EnvironmentId_s*)x);
  case zx_hrxml_Considerations_ELEM:
    return zx_LEN_WO_hrxml_Considerations(c, (struct zx_hrxml_Considerations_s*)x);
  case zx_idhrxml_Subscription_ELEM:
    return zx_LEN_WO_idhrxml_Subscription(c, (struct zx_idhrxml_Subscription_s*)x);
  case zx_idhrxml_CreateItem_ELEM:
    return zx_LEN_WO_idhrxml_CreateItem(c, (struct zx_idhrxml_CreateItem_s*)x);
  case zx_idhrxml_ResultQuery_ELEM:
    return zx_LEN_WO_idhrxml_ResultQuery(c, (struct zx_idhrxml_ResultQuery_s*)x);
  case zx_idhrxml_NewData_ELEM:
    return zx_LEN_WO_idhrxml_NewData(c, (struct zx_idhrxml_NewData_s*)x);
  case zx_idhrxml_ItemData_ELEM:
    return zx_LEN_WO_idhrxml_ItemData(c, (struct zx_idhrxml_ItemData_s*)x);
  case zx_hrxml_Candidate_ELEM:
    return zx_LEN_WO_hrxml_Candidate(c, (struct zx_hrxml_Candidate_s*)x);
  case zx_idhrxml_DeleteItem_ELEM:
    return zx_LEN_WO_idhrxml_DeleteItem(c, (struct zx_idhrxml_DeleteItem_s*)x);
  case zx_idhrxml_Select_ELEM:
    return zx_LEN_WO_simple_elem(c, (struct zx_elem_s*)x, sizeof("Select")-1);
  case zx_idhrxml_ModifyItem_ELEM:
    return zx_LEN_WO_idhrxml_ModifyItem(c, (struct zx_idhrxml_ModifyItem_s*)x);
  case zx_idhrxml_Notification_ELEM:
    return zx_LEN_WO_idhrxml_Notification(c, (struct zx_idhrxml_Notification_s*)x);
  case zx_idhrxml_TestItem_ELEM:
    return zx_LEN_WO_idhrxml_TestItem(c, (struct zx_idhrxml_TestItem_s*)x);
  case zx_idhrxml_QueryItem_ELEM:
    return zx_LEN_WO_idhrxml_QueryItem(c, (struct zx_idhrxml_QueryItem_s*)x);
  case zx_idhrxml_Sort_ELEM:
    return zx_LEN_WO_simple_elem(c, (struct zx_elem_s*)x, sizeof("Sort")-1);
  case zx_idhrxml_Data_ELEM:
    return zx_LEN_WO_idhrxml_Data(c, (struct zx_idhrxml_Data_s*)x);
  case zx_idhrxml_Aggregation_ELEM:
    return zx_LEN_WO_simple_elem(c, (struct zx_elem_s*)x, sizeof("Aggregation")-1);
  case zx_idhrxml_Trigger_ELEM:
    return zx_LEN_WO_simple_elem(c, (struct zx_elem_s*)x, sizeof("Trigger")-1);
  case zx_idhrxml_TestOp_ELEM:
    return zx_LEN_WO_simple_elem(c, (struct zx_elem_s*)x, sizeof("TestOp")-1);
  case zx_idp_MEDInfo_ELEM:
    return zx_LEN_WO_idp_MEDInfo(c, (struct zx_idp_MEDInfo_s*)x);
  case zx_sa_AuthnContext_ELEM:
    return zx_LEN_WO_sa_AuthnContext(c, (struct zx_sa_AuthnContext_s*)x);
  case zx_idp_CreatedStatusItem_ELEM:
    return zx_LEN_WO_idp_CreatedStatusItem(c, (struct zx_idp_CreatedStatusItem_s*)x);
  case zx_idp_GetAssertionResponseItem_ELEM:
    return zx_LEN_WO_idp_GetAssertionResponseItem(c, (struct zx_idp_GetAssertionResponseItem_s*)x);
  case zx_idp_AssertionItem_ELEM:
    return zx_LEN_WO_idp_AssertionItem(c, (struct zx_idp_AssertionItem_s*)x);
  case zx_idp_ProviderID_ELEM:
    return zx_LEN_WO_simple_elem(c, (struct zx_elem_s*)x, sizeof("ProviderID")-1);
  case zx_idp_ProviderInfo_ELEM:
    return zx_LEN_WO_idp_ProviderInfo(c, (struct zx_idp_ProviderInfo_s*)x);
  case zx_sa_NameID_ELEM:
    return zx_LEN_WO_sa_NameID(c, (struct zx_sa_NameID_s*)x);
  case zx_sa_AttributeStatement_ELEM:
    return zx_LEN_WO_sa_AttributeStatement(c, (struct zx_sa_AttributeStatement_s*)x);
  case zx_sa_Subject_ELEM:
    return zx_LEN_WO_sa_Subject(c, (struct zx_sa_Subject_s*)x);
  case zx_im_MappingInput_ELEM:
    return zx_LEN_WO_im_MappingInput(c, (struct zx_im_MappingInput_s*)x);
  case zx_im_MappingOutput_ELEM:
    return zx_LEN_WO_im_MappingOutput(c, (struct zx_im_MappingOutput_s*)x);
  case zx_sec_TokenPolicy_ELEM:
    return zx_LEN_WO_sec_TokenPolicy(c, (struct zx_sec_TokenPolicy_s*)x);
  case zx_is_Help_ELEM:
    return zx_LEN_WO_is_Help(c, (struct zx_is_Help_s*)x);
  case zx_is_Hint_ELEM:
    return zx_LEN_WO_simple_elem(c, (struct zx_elem_s*)x, sizeof("Hint")-1);
  case zx_is_Label_ELEM:
    return zx_LEN_WO_simple_elem(c, (struct zx_elem_s*)x, sizeof("Label")-1);
  case zx_is_Value_ELEM:
    return zx_LEN_WO_simple_elem(c, (struct zx_elem_s*)x, sizeof("Value")-1);
  case zx_is_Select_ELEM:
    return zx_LEN_WO_is_Select(c, (struct zx_is_Select_s*)x);
  case zx_is_Confirm_ELEM:
    return zx_LEN_WO_is_Confirm(c, (struct zx_is_Confirm_s*)x);
  case zx_is_Text_ELEM:
    return zx_LEN_WO_is_Text(c, (struct zx_is_Text_s*)x);
  case zx_is_Inquiry_ELEM:
    return zx_LEN_WO_is_Inquiry(c, (struct zx_is_Inquiry_s*)x);
  case zx_is_InteractionStatement_ELEM:
    return zx_LEN_WO_is_InteractionStatement(c, (struct zx_is_InteractionStatement_s*)x);
  case zx_is_Parameter_ELEM:
    return zx_LEN_WO_is_Parameter(c, (struct zx_is_Parameter_s*)x);
  case zx_is_Item_ELEM:
    return zx_LEN_WO_is_Item(c, (struct zx_is_Item_s*)x);
  case zx_is12_Help_ELEM:
    return zx_LEN_WO_is12_Help(c, (struct zx_is12_Help_s*)x);
  case zx_is12_Hint_ELEM:
    return zx_LEN_WO_simple_elem(c, (struct zx_elem_s*)x, sizeof("Hint")-1);
  case zx_is12_Label_ELEM:
    return zx_LEN_WO_simple_elem(c, (struct zx_elem_s*)x, sizeof("Label")-1);
  case zx_is12_Value_ELEM:
    return zx_LEN_WO_simple_elem(c, (struct zx_elem_s*)x, sizeof("Value")-1);
  case zx_is12_Select_ELEM:
    return zx_LEN_WO_is12_Select(c, (struct zx_is12_Select_s*)x);
  case zx_is12_Confirm_ELEM:
    return zx_LEN_WO_is12_Confirm(c, (struct zx_is12_Confirm_s*)x);
  case zx_is12_Text_ELEM:
    return zx_LEN_WO_is12_Text(c, (struct zx_is12_Text_s*)x);
  case zx_is12_Inquiry_ELEM:
    return zx_LEN_WO_is12_Inquiry(c, (struct zx_is12_Inquiry_s*)x);
  case zx_is12_Status_ELEM:
    return zx_LEN_WO_is12_Status(c, (struct zx_is12_Status_s*)x);
  case zx_is12_InteractionStatement_ELEM:
    return zx_LEN_WO_is12_InteractionStatement(c, (struct zx_is12_InteractionStatement_s*)x);
  case zx_is12_Parameter_ELEM:
    return zx_LEN_WO_is12_Parameter(c, (struct zx_is12_Parameter_s*)x);
  case zx_is12_Item_ELEM:
    return zx_LEN_WO_is12_Item(c, (struct zx_is12_Item_s*)x);
  case zx_is12_InteractionService_ELEM:
    return zx_LEN_WO_is12_InteractionService(c, (struct zx_is12_InteractionService_s*)x);
  case zx_m20_AffiliateMember_ELEM:
    return zx_LEN_WO_simple_elem(c, (struct zx_elem_s*)x, sizeof("AffiliateMember")-1);
  case zx_m20_Extension_ELEM:
    return zx_LEN_WO_m20_Extension(c, (struct zx_m20_Extension_s*)x);
  case zx_m20_KeyDescriptor_ELEM:
    return zx_LEN_WO_m20_KeyDescriptor(c, (struct zx_m20_KeyDescriptor_s*)x);
  case zx_m20_Company_ELEM:
    return zx_LEN_WO_simple_elem(c, (struct zx_elem_s*)x, sizeof("Company")-1);
  case zx_m20_GivenName_ELEM:
    return zx_LEN_WO_simple_elem(c, (struct zx_elem_s*)x, sizeof("GivenName")-1);
  case zx_m20_SurName_ELEM:
    return zx_LEN_WO_simple_elem(c, (struct zx_elem_s*)x, sizeof("SurName")-1);
  case zx_m20_EmailAddress_ELEM:
    return zx_LEN_WO_simple_elem(c, (struct zx_elem_s*)x, sizeof("EmailAddress")-1);
  case zx_m20_TelephoneNumber_ELEM:
    return zx_LEN_WO_simple_elem(c, (struct zx_elem_s*)x, sizeof("TelephoneNumber")-1);
  case zx_m20_EntityDescriptor_ELEM:
    return zx_LEN_WO_m20_EntityDescriptor(c, (struct zx_m20_EntityDescriptor_s*)x);
  case zx_m20_IDPDescriptor_ELEM:
    return zx_LEN_WO_m20_IDPDescriptor(c, (struct zx_m20_IDPDescriptor_s*)x);
  case zx_m20_SPDescriptor_ELEM:
    return zx_LEN_WO_m20_SPDescriptor(c, (struct zx_m20_SPDescriptor_s*)x);
  case zx_m20_AffiliationDescriptor_ELEM:
    return zx_LEN_WO_m20_AffiliationDescriptor(c, (struct zx_m20_AffiliationDescriptor_s*)x);
  case zx_m20_ContactPerson_ELEM:
    return zx_LEN_WO_m20_ContactPerson(c, (struct zx_m20_ContactPerson_s*)x);
  case zx_m20_Organization_ELEM:
    return zx_LEN_WO_m20_Organization(c, (struct zx_m20_Organization_s*)x);
  case zx_m20_SoapEndpoint_ELEM:
    return zx_LEN_WO_simple_elem(c, (struct zx_elem_s*)x, sizeof("SoapEndpoint")-1);
  case zx_m20_SingleLogoutServiceURL_ELEM:
    return zx_LEN_WO_simple_elem(c, (struct zx_elem_s*)x, sizeof("SingleLogoutServiceURL")-1);
  case zx_m20_SingleLogoutServiceReturnURL_ELEM:
    return zx_LEN_WO_simple_elem(c, (struct zx_elem_s*)x, sizeof("SingleLogoutServiceReturnURL")-1);
  case zx_m20_FederationTerminationServiceURL_ELEM:
    return zx_LEN_WO_simple_elem(c, (struct zx_elem_s*)x, sizeof("FederationTerminationServiceURL")-1);
  case zx_m20_FederationTerminationServiceReturnURL_ELEM:
    return zx_LEN_WO_simple_elem(c, (struct zx_elem_s*)x, sizeof("FederationTerminationServiceReturnURL")-1);
  case zx_m20_FederationTerminationNotificationProtocolProfile_ELEM:
    return zx_LEN_WO_simple_elem(c, (struct zx_elem_s*)x, sizeof("FederationTerminationNotificationProtocolProfile")-1);
  case zx_m20_SingleLogoutProtocolProfile_ELEM:
    return zx_LEN_WO_simple_elem(c, (struct zx_elem_s*)x, sizeof("SingleLogoutProtocolProfile")-1);
  case zx_m20_RegisterNameIdentifierProtocolProfile_ELEM:
    return zx_LEN_WO_simple_elem(c, (struct zx_elem_s*)x, sizeof("RegisterNameIdentifierProtocolProfile")-1);
  case zx_m20_RegisterNameIdentifierServiceURL_ELEM:
    return zx_LEN_WO_simple_elem(c, (struct zx_elem_s*)x, sizeof("RegisterNameIdentifierServiceURL")-1);
  case zx_m20_RegisterNameIdentifierServiceReturnURL_ELEM:
    return zx_LEN_WO_simple_elem(c, (struct zx_elem_s*)x, sizeof("RegisterNameIdentifierServiceReturnURL")-1);
  case zx_m20_NameIdentifierMappingProtocolProfile_ELEM:
    return zx_LEN_WO_simple_elem(c, (struct zx_elem_s*)x, sizeof("NameIdentifierMappingProtocolProfile")-1);
  case zx_m20_NameIdentifierMappingEncryptionProfile_ELEM:
    return zx_LEN_WO_simple_elem(c, (struct zx_elem_s*)x, sizeof("NameIdentifierMappingEncryptionProfile")-1);
  case zx_m20_AdditionalMetaLocation_ELEM:
    return zx_LEN_WO_m20_AdditionalMetaLocation(c, (struct zx_m20_AdditionalMetaLocation_s*)x);
  case zx_m20_SingleSignOnServiceURL_ELEM:
    return zx_LEN_WO_simple_elem(c, (struct zx_elem_s*)x, sizeof("SingleSignOnServiceURL")-1);
  case zx_m20_SingleSignOnProtocolProfile_ELEM:
    return zx_LEN_WO_simple_elem(c, (struct zx_elem_s*)x, sizeof("SingleSignOnProtocolProfile")-1);
  case zx_m20_AuthnServiceURL_ELEM:
    return zx_LEN_WO_simple_elem(c, (struct zx_elem_s*)x, sizeof("AuthnServiceURL")-1);
  case zx_m20_EncryptionMethod_ELEM:
    return zx_LEN_WO_simple_elem(c, (struct zx_elem_s*)x, sizeof("EncryptionMethod")-1);
  case zx_m20_KeySize_ELEM:
    return zx_LEN_WO_simple_elem(c, (struct zx_elem_s*)x, sizeof("KeySize")-1);
  case zx_m20_OrganizationName_ELEM:
    return zx_LEN_WO_m20_OrganizationName(c, (struct zx_m20_OrganizationName_s*)x);
  case zx_m20_OrganizationDisplayName_ELEM:
    return zx_LEN_WO_m20_OrganizationDisplayName(c, (struct zx_m20_OrganizationDisplayName_s*)x);
  case zx_m20_OrganizationURL_ELEM:
    return zx_LEN_WO_m20_OrganizationURL(c, (struct zx_m20_OrganizationURL_s*)x);
  case zx_m20_AssertionConsumerServiceURL_ELEM:
    return zx_LEN_WO_m20_AssertionConsumerServiceURL(c, (struct zx_m20_AssertionConsumerServiceURL_s*)x);
  case zx_m20_AuthnRequestsSigned_ELEM:
    return zx_LEN_WO_simple_elem(c, (struct zx_elem_s*)x, sizeof("AuthnRequestsSigned")-1);
  case zx_md_Extensions_ELEM:
    return zx_LEN_WO_md_Extensions(c, (struct zx_md_Extensions_s*)x);
  case zx_md_AffiliateMember_ELEM:
    return zx_LEN_WO_simple_elem(c, (struct zx_elem_s*)x, sizeof("AffiliateMember")-1);
  case zx_md_Organization_ELEM:
    return zx_LEN_WO_md_Organization(c, (struct zx_md_Organization_s*)x);
  case zx_md_ContactPerson_ELEM:
    return zx_LEN_WO_md_ContactPerson(c, (struct zx_md_ContactPerson_s*)x);
  case zx_md_AttributeService_ELEM:
    return zx_LEN_WO_md_AttributeService(c, (struct zx_md_AttributeService_s*)x);
  case zx_md_AssertionIDRequestService_ELEM:
    return zx_LEN_WO_md_AssertionIDRequestService(c, (struct zx_md_AssertionIDRequestService_s*)x);
  case zx_md_NameIDFormat_ELEM:
    return zx_LEN_WO_simple_elem(c, (struct zx_elem_s*)x, sizeof("NameIDFormat")-1);
  case zx_md_AttributeProfile_ELEM:
    return zx_LEN_WO_simple_elem(c, (struct zx_elem_s*)x, sizeof("AttributeProfile")-1);
  case zx_sa_Attribute_ELEM:
    return zx_LEN_WO_sa_Attribute(c, (struct zx_sa_Attribute_s*)x);
  case zx_md_ServiceName_ELEM:
    return zx_LEN_WO_md_ServiceName(c, (struct zx_md_ServiceName_s*)x);
  case zx_md_ServiceDescription_ELEM:
    return zx_LEN_WO_md_ServiceDescription(c, (struct zx_md_ServiceDescription_s*)x);
  case zx_md_RequestedAttribute_ELEM:
    return zx_LEN_WO_md_RequestedAttribute(c, (struct zx_md_RequestedAttribute_s*)x);
  case zx_md_AuthnQueryService_ELEM:
    return zx_LEN_WO_md_AuthnQueryService(c, (struct zx_md_AuthnQueryService_s*)x);
  case zx_md_Company_ELEM:
    return zx_LEN_WO_simple_elem(c, (struct zx_elem_s*)x, sizeof("Company")-1);
  case zx_md_GivenName_ELEM:
    return zx_LEN_WO_simple_elem(c, (struct zx_elem_s*)x, sizeof("GivenName")-1);
  case zx_md_SurName_ELEM:
    return zx_LEN_WO_simple_elem(c, (struct zx_elem_s*)x, sizeof("SurName")-1);
  case zx_md_EmailAddress_ELEM:
    return zx_LEN_WO_simple_elem(c, (struct zx_elem_s*)x, sizeof("EmailAddress")-1);
  case zx_md_TelephoneNumber_ELEM:
    return zx_LEN_WO_simple_elem(c, (struct zx_elem_s*)x, sizeof("TelephoneNumber")-1);
  case zx_xenc_KeySize_ELEM:
    return zx_LEN_WO_simple_elem(c, (struct zx_elem_s*)x, sizeof("KeySize")-1);
  case zx_xenc_OAEPparams_ELEM:
    return zx_LEN_WO_simple_elem(c, (struct zx_elem_s*)x, sizeof("OAEPparams")-1);
  case zx_md_EntityDescriptor_ELEM:
    return zx_LEN_WO_md_EntityDescriptor(c, (struct zx_md_EntityDescriptor_s*)x);
  case zx_md_EntitiesDescriptor_ELEM:
    return zx_LEN_WO_md_EntitiesDescriptor(c, (struct zx_md_EntitiesDescriptor_s*)x);
  case zx_md_RoleDescriptor_ELEM:
    return zx_LEN_WO_md_RoleDescriptor(c, (struct zx_md_RoleDescriptor_s*)x);
  case zx_md_IDPSSODescriptor_ELEM:
    return zx_LEN_WO_md_IDPSSODescriptor(c, (struct zx_md_IDPSSODescriptor_s*)x);
  case zx_md_SPSSODescriptor_ELEM:
    return zx_LEN_WO_md_SPSSODescriptor(c, (struct zx_md_SPSSODescriptor_s*)x);
  case zx_md_AuthnAuthorityDescriptor_ELEM:
    return zx_LEN_WO_md_AuthnAuthorityDescriptor(c, (struct zx_md_AuthnAuthorityDescriptor_s*)x);
  case zx_md_AttributeAuthorityDescriptor_ELEM:
    return zx_LEN_WO_md_AttributeAuthorityDescriptor(c, (struct zx_md_AttributeAuthorityDescriptor_s*)x);
  case zx_md_PDPDescriptor_ELEM:
    return zx_LEN_WO_md_PDPDescriptor(c, (struct zx_md_PDPDescriptor_s*)x);
  case zx_md_AffiliationDescriptor_ELEM:
    return zx_LEN_WO_md_AffiliationDescriptor(c, (struct zx_md_AffiliationDescriptor_s*)x);
  case zx_md_AdditionalMetadataLocation_ELEM:
    return zx_LEN_WO_md_AdditionalMetadataLocation(c, (struct zx_md_AdditionalMetadataLocation_s*)x);
  case zx_shibmd_Scope_ELEM:
    return zx_LEN_WO_shibmd_Scope(c, (struct zx_shibmd_Scope_s*)x);
  case zx_shibmd_KeyAuthority_ELEM:
    return zx_LEN_WO_shibmd_KeyAuthority(c, (struct zx_shibmd_KeyAuthority_s*)x);
  case zx_idpdisc_DiscoveryResponse_ELEM:
    return zx_LEN_WO_idpdisc_DiscoveryResponse(c, (struct zx_idpdisc_DiscoveryResponse_s*)x);
  case zx_md_ArtifactResolutionService_ELEM:
    return zx_LEN_WO_md_ArtifactResolutionService(c, (struct zx_md_ArtifactResolutionService_s*)x);
  case zx_md_SingleLogoutService_ELEM:
    return zx_LEN_WO_md_SingleLogoutService(c, (struct zx_md_SingleLogoutService_s*)x);
  case zx_md_ManageNameIDService_ELEM:
    return zx_LEN_WO_md_ManageNameIDService(c, (struct zx_md_ManageNameIDService_s*)x);
  case zx_md_SingleSignOnService_ELEM:
    return zx_LEN_WO_md_SingleSignOnService(c, (struct zx_md_SingleSignOnService_s*)x);
  case zx_md_NameIDMappingService_ELEM:
    return zx_LEN_WO_md_NameIDMappingService(c, (struct zx_md_NameIDMappingService_s*)x);
  case zx_md_EncryptionMethod_ELEM:
    return zx_LEN_WO_md_EncryptionMethod(c, (struct zx_md_EncryptionMethod_s*)x);
  case zx_md_OrganizationName_ELEM:
    return zx_LEN_WO_md_OrganizationName(c, (struct zx_md_OrganizationName_s*)x);
  case zx_md_OrganizationDisplayName_ELEM:
    return zx_LEN_WO_md_OrganizationDisplayName(c, (struct zx_md_OrganizationDisplayName_s*)x);
  case zx_md_OrganizationURL_ELEM:
    return zx_LEN_WO_md_OrganizationURL(c, (struct zx_md_OrganizationURL_s*)x);
  case zx_md_AuthzService_ELEM:
    return zx_LEN_WO_md_AuthzService(c, (struct zx_md_AuthzService_s*)x);
  case zx_sa_AttributeValue_ELEM:
    return zx_LEN_WO_sa_AttributeValue(c, (struct zx_sa_AttributeValue_s*)x);
  case zx_md_AssertionConsumerService_ELEM:
    return zx_LEN_WO_md_AssertionConsumerService(c, (struct zx_md_AssertionConsumerService_s*)x);
  case zx_md_AttributeConsumingService_ELEM:
    return zx_LEN_WO_md_AttributeConsumingService(c, (struct zx_md_AttributeConsumingService_s*)x);
  case zx_mm7_RFC2822Address_ELEM:
    return zx_LEN_WO_mm7_RFC2822Address(c, (struct zx_mm7_RFC2822Address_s*)x);
  case zx_mm7_Number_ELEM:
    return zx_LEN_WO_mm7_Number(c, (struct zx_mm7_Number_s*)x);
  case zx_mm7_ShortCode_ELEM:
    return zx_LEN_WO_mm7_ShortCode(c, (struct zx_mm7_ShortCode_s*)x);
  case zx_mm7_Extension_ELEM:
    return zx_LEN_WO_mm7_Extension(c, (struct zx_mm7_Extension_s*)x);
  case zx_mm7_MM7Version_ELEM:
    return zx_LEN_WO_simple_elem(c, (struct zx_elem_s*)x, sizeof("MM7Version")-1);
  case zx_mm7_SenderIdentification_ELEM:
    return zx_LEN_WO_mm7_SenderIdentification(c, (struct zx_mm7_SenderIdentification_s*)x);
  case zx_mm7_MessageID_ELEM:
    return zx_LEN_WO_simple_elem(c, (struct zx_elem_s*)x, sizeof("MessageID")-1);
  case zx_mm7_Recipients_ELEM:
    return zx_LEN_WO_mm7_Recipients(c, (struct zx_mm7_Recipients_s*)x);
  case zx_mm7_ApplicID_ELEM:
    return zx_LEN_WO_simple_elem(c, (struct zx_elem_s*)x, sizeof("ApplicID")-1);
  case zx_mm7_ReplyApplicID_ELEM:
    return zx_LEN_WO_simple_elem(c, (struct zx_elem_s*)x, sizeof("ReplyApplicID")-1);
  case zx_mm7_AuxApplicInfo_ELEM:
    return zx_LEN_WO_simple_elem(c, (struct zx_elem_s*)x, sizeof("AuxApplicInfo")-1);
  case zx_mm7_Status_ELEM:
    return zx_LEN_WO_mm7_Status(c, (struct zx_mm7_Status_s*)x);
  case zx_mm7_MMSRelayServerID_ELEM:
    return zx_LEN_WO_simple_elem(c, (struct zx_elem_s*)x, sizeof("MMSRelayServerID")-1);
  case zx_mm7_VASPID_ELEM:
    return zx_LEN_WO_simple_elem(c, (struct zx_elem_s*)x, sizeof("VASPID")-1);
  case zx_mm7_VASID_ELEM:
    return zx_LEN_WO_simple_elem(c, (struct zx_elem_s*)x, sizeof("VASID")-1);
  case zx_mm7_LinkedID_ELEM:
    return zx_LEN_WO_simple_elem(c, (struct zx_elem_s*)x, sizeof("LinkedID")-1);
  case zx_mm7_Sender_ELEM:
    return zx_LEN_WO_mm7_Sender(c, (struct zx_mm7_Sender_s*)x);
  case zx_mm7_Previouslysentby_ELEM:
    return zx_LEN_WO_mm7_Previouslysentby(c, (struct zx_mm7_Previouslysentby_s*)x);
  case zx_mm7_Previouslysentdateandtime_ELEM:
    return zx_LEN_WO_mm7_Previouslysentdateandtime(c, (struct zx_mm7_Previouslysentdateandtime_s*)x);
  case zx_mm7_SenderSPI_ELEM:
    return zx_LEN_WO_simple_elem(c, (struct zx_elem_s*)x, sizeof("SenderSPI")-1);
  case zx_mm7_RecipientSPI_ELEM:
    return zx_LEN_WO_simple_elem(c, (struct zx_elem_s*)x, sizeof("RecipientSPI")-1);
  case zx_mm7_TimeStamp_ELEM:
    return zx_LEN_WO_simple_elem(c, (struct zx_elem_s*)x, sizeof("TimeStamp")-1);
  case zx_mm7_ReplyChargingID_ELEM:
    return zx_LEN_WO_simple_elem(c, (struct zx_elem_s*)x, sizeof("ReplyChargingID")-1);
  case zx_mm7_Priority_ELEM:
    return zx_LEN_WO_simple_elem(c, (struct zx_elem_s*)x, sizeof("Priority")-1);
  case zx_mm7_Subject_ELEM:
    return zx_LEN_WO_simple_elem(c, (struct zx_elem_s*)x, sizeof("Subject")-1);
  case zx_mm7_UACapabilities_ELEM:
    return zx_LEN_WO_mm7_UACapabilities(c, (struct zx_mm7_UACapabilities_s*)x);
  case zx_mm7_Content_ELEM:
    return zx_LEN_WO_mm7_Content(c, (struct zx_mm7_Content_s*)x);
  case zx_mm7_AdditionalInformation_ELEM:
    return zx_LEN_WO_mm7_AdditionalInformation(c, (struct zx_mm7_AdditionalInformation_s*)x);
  case zx_mm7_MessageExtraData_ELEM:
    return zx_LEN_WO_mm7_MessageExtraData(c, (struct zx_mm7_MessageExtraData_s*)x);
  case zx_mm7_ServiceCode_ELEM:
    return zx_LEN_WO_mm7_ServiceCode(c, (struct zx_mm7_ServiceCode_s*)x);
  case zx_mm7_DC_ELEM:
    return zx_LEN_WO_simple_elem(c, (struct zx_elem_s*)x, sizeof("DC")-1);
  case zx_mm7_Recipient_ELEM:
    return zx_LEN_WO_mm7_Recipient(c, (struct zx_mm7_Recipient_s*)x);
  case zx_mm7_Date_ELEM:
    return zx_LEN_WO_simple_elem(c, (struct zx_elem_s*)x, sizeof("Date")-1);
  case zx_mm7_MMStatus_ELEM:
    return zx_LEN_WO_simple_elem(c, (struct zx_elem_s*)x, sizeof("MMStatus")-1);
  case zx_mm7_MMStatusExtension_ELEM:
    return zx_LEN_WO_simple_elem(c, (struct zx_elem_s*)x, sizeof("MMStatusExtension")-1);
  case zx_mm7_StatusText_ELEM:
    return zx_LEN_WO_simple_elem(c, (struct zx_elem_s*)x, sizeof("StatusText")-1);
  case zx_mm7_IdentityAddressingToken_ELEM:
    return zx_LEN_WO_mm7_IdentityAddressingToken(c, (struct zx_mm7_IdentityAddressingToken_s*)x);
  case zx_mm7_CredentialRef_ELEM:
    return zx_LEN_WO_simple_elem(c, (struct zx_elem_s*)x, sizeof("CredentialRef")-1);
  case zx_mm7_element_ELEM:
    return zx_LEN_WO_mm7_element(c, (struct zx_mm7_element_s*)x);
  case zx_mm7_DeliverUsing_ELEM:
    return zx_LEN_WO_simple_elem(c, (struct zx_elem_s*)x, sizeof("DeliverUsing")-1);
  case zx_mm7_UserAgent_ELEM:
    return zx_LEN_WO_mm7_UserAgent(c, (struct zx_mm7_UserAgent_s*)x);
  case zx_mm7_DateTime_ELEM:
    return zx_LEN_WO_mm7_DateTime(c, (struct zx_mm7_DateTime_s*)x);
  case zx_mm7_MessageType_ELEM:
    return zx_LEN_WO_simple_elem(c, (struct zx_elem_s*)x, sizeof("MessageType")-1);
  case zx_mm7_StatusCode_ELEM:
    return zx_LEN_WO_simple_elem(c, (struct zx_elem_s*)x, sizeof("StatusCode")-1);
  case zx_mm7_Details_ELEM:
    return zx_LEN_WO_mm7_Details(c, (struct zx_mm7_Details_s*)x);
  case zx_mm7_To_ELEM:
    return zx_LEN_WO_mm7_To(c, (struct zx_mm7_To_s*)x);
  case zx_mm7_Cc_ELEM:
    return zx_LEN_WO_mm7_Cc(c, (struct zx_mm7_Cc_s*)x);
  case zx_mm7_Bcc_ELEM:
    return zx_LEN_WO_mm7_Bcc(c, (struct zx_mm7_Bcc_s*)x);
  case zx_mm7_ReadReply_ELEM:
    return zx_LEN_WO_simple_elem(c, (struct zx_elem_s*)x, sizeof("ReadReply")-1);
  case zx_mm7_EarliestDeliveryTime_ELEM:
    return zx_LEN_WO_simple_elem(c, (struct zx_elem_s*)x, sizeof("EarliestDeliveryTime")-1);
  case zx_mm7_DistributionIndicator_ELEM:
    return zx_LEN_WO_simple_elem(c, (struct zx_elem_s*)x, sizeof("DistributionIndicator")-1);
  case zx_mm7_ContentClass_ELEM:
    return zx_LEN_WO_simple_elem(c, (struct zx_elem_s*)x, sizeof("ContentClass")-1);
  case zx_mm7_DRMContent_ELEM:
    return zx_LEN_WO_simple_elem(c, (struct zx_elem_s*)x, sizeof("DRMContent")-1);
  case zx_mm7_SenderAddress_ELEM:
    return zx_LEN_WO_mm7_SenderAddress(c, (struct zx_mm7_SenderAddress_s*)x);
  case zx_mm7_PreferredChannels_ELEM:
    return zx_LEN_WO_mm7_PreferredChannels(c, (struct zx_mm7_PreferredChannels_s*)x);
  case zx_mm7_MessageClass_ELEM:
    return zx_LEN_WO_simple_elem(c, (struct zx_elem_s*)x, sizeof("MessageClass")-1);
  case zx_mm7_ReplyCharging_ELEM:
    return zx_LEN_WO_mm7_ReplyCharging(c, (struct zx_mm7_ReplyCharging_s*)x);
  case zx_mm7_ExpiryDate_ELEM:
    return zx_LEN_WO_simple_elem(c, (struct zx_elem_s*)x, sizeof("ExpiryDate")-1);
  case zx_mm7_DeliveryReport_ELEM:
    return zx_LEN_WO_simple_elem(c, (struct zx_elem_s*)x, sizeof("DeliveryReport")-1);
  case zx_mm7_ChargedParty_ELEM:
    return zx_LEN_WO_simple_elem(c, (struct zx_elem_s*)x, sizeof("ChargedParty")-1);
  case zx_mm7_ChargedPartyID_ELEM:
    return zx_LEN_WO_simple_elem(c, (struct zx_elem_s*)x, sizeof("ChargedPartyID")-1);
  case zx_mm7_ThirdPartyPayer_ELEM:
    return zx_LEN_WO_mm7_ThirdPartyPayer(c, (struct zx_mm7_ThirdPartyPayer_s*)x);
  case zx_mm7_DeliveryCondition_ELEM:
    return zx_LEN_WO_mm7_DeliveryCondition(c, (struct zx_mm7_DeliveryCondition_s*)x);
  case zx_mm7_key_ELEM:
    return zx_LEN_WO_simple_elem(c, (struct zx_elem_s*)x, sizeof("key")-1);
  case zx_mm7_value_ELEM:
    return zx_LEN_WO_simple_elem(c, (struct zx_elem_s*)x, sizeof("value")-1);
  case zx_mm7_CancelID_ELEM:
    return zx_LEN_WO_simple_elem(c, (struct zx_elem_s*)x, sizeof("CancelID")-1);
  case zx_mm7_ReplaceID_ELEM:
    return zx_LEN_WO_simple_elem(c, (struct zx_elem_s*)x, sizeof("ReplaceID")-1);
  case zx_pmm_PMActivateItem_ELEM:
    return zx_LEN_WO_pmm_PMActivateItem(c, (struct zx_pmm_PMActivateItem_s*)x);
  case zx_dp_NotifyTo_ELEM:
    return zx_LEN_WO_simple_elem(c, (struct zx_elem_s*)x, sizeof("NotifyTo")-1);
  case zx_prov_PMID_ELEM:
    return zx_LEN_WO_prov_PMID(c, (struct zx_prov_PMID_s*)x);
  case zx_pmm_PMDeactivateItem_ELEM:
    return zx_LEN_WO_pmm_PMDeactivateItem(c, (struct zx_pmm_PMDeactivateItem_s*)x);
  case zx_pmm_PMDeleteItem_ELEM:
    return zx_LEN_WO_pmm_PMDeleteItem(c, (struct zx_pmm_PMDeleteItem_s*)x);
  case zx_prov_PMStatus_ELEM:
    return zx_LEN_WO_prov_PMStatus(c, (struct zx_prov_PMStatus_s*)x);
  case zx_pmm_PMUpdateItem_ELEM:
    return zx_LEN_WO_pmm_PMUpdateItem(c, (struct zx_pmm_PMUpdateItem_s*)x);
  case zx_prov_PMDescriptor_ELEM:
    return zx_LEN_WO_prov_PMDescriptor(c, (struct zx_prov_PMDescriptor_s*)x);
  case zx_prov_ProvisioningHandle_ELEM:
    return zx_LEN_WO_prov_ProvisioningHandle(c, (struct zx_prov_ProvisioningHandle_s*)x);
  case zx_prov_PMActivateItem_ELEM:
    return zx_LEN_WO_prov_PMActivateItem(c, (struct zx_prov_PMActivateItem_s*)x);
  case zx_prov_PMDeactivateItem_ELEM:
    return zx_LEN_WO_prov_PMDeactivateItem(c, (struct zx_prov_PMDeactivateItem_s*)x);
  case zx_prov_PMDeleteItem_ELEM:
    return zx_LEN_WO_prov_PMDeleteItem(c, (struct zx_prov_PMDeleteItem_s*)x);
  case zx_prov_PMEngineRef_ELEM:
    return zx_LEN_WO_simple_elem(c, (struct zx_elem_s*)x, sizeof("PMEngineRef")-1);
  case zx_prov_PMInitData_ELEM:
    return zx_LEN_WO_simple_elem(c, (struct zx_elem_s*)x, sizeof("PMInitData")-1);
  case zx_prov_PMRTData_ELEM:
    return zx_LEN_WO_simple_elem(c, (struct zx_elem_s*)x, sizeof("PMRTData")-1);
  case zx_prov_EngineData_ELEM:
    return zx_LEN_WO_simple_elem(c, (struct zx_elem_s*)x, sizeof("EngineData")-1);
  case zx_prov_PMEInfo_ELEM:
    return zx_LEN_WO_prov_PMEInfo(c, (struct zx_prov_PMEInfo_s*)x);
  case zx_prov_PMECreatorID_ELEM:
    return zx_LEN_WO_simple_elem(c, (struct zx_elem_s*)x, sizeof("PMECreatorID")-1);
  case zx_prov_PMEWhenCreated_ELEM:
    return zx_LEN_WO_simple_elem(c, (struct zx_elem_s*)x, sizeof("PMEWhenCreated")-1);
  case zx_prov_PMEEnabled_ELEM:
    return zx_LEN_WO_simple_elem(c, (struct zx_elem_s*)x, sizeof("PMEEnabled")-1);
  case zx_prov_PMEWhenEnabled_ELEM:
    return zx_LEN_WO_simple_elem(c, (struct zx_elem_s*)x, sizeof("PMEWhenEnabled")-1);
  case zx_prov_PMESize_ELEM:
    return zx_LEN_WO_simple_elem(c, (struct zx_elem_s*)x, sizeof("PMESize")-1);
  case zx_prov_PMEHash_ELEM:
    return zx_LEN_WO_prov_PMEHash(c, (struct zx_prov_PMEHash_s*)x);
  case zx_prov_PMEUploadMax_ELEM:
    return zx_LEN_WO_simple_elem(c, (struct zx_elem_s*)x, sizeof("PMEUploadMax")-1);
  case zx_prov_PMDArtifact_ELEM:
    return zx_LEN_WO_simple_elem(c, (struct zx_elem_s*)x, sizeof("PMDArtifact")-1);
  case zx_prov_CallbackEPR_ELEM:
    return zx_LEN_WO_prov_CallbackEPR(c, (struct zx_prov_CallbackEPR_s*)x);
  case zx_prov_PMRegisterDescriptorItem_ELEM:
    return zx_LEN_WO_prov_PMRegisterDescriptorItem(c, (struct zx_prov_PMRegisterDescriptorItem_s*)x);
  case zx_prov_PMRegisterDescriptorResponseItem_ELEM:
    return zx_LEN_WO_prov_PMRegisterDescriptorResponseItem(c, (struct zx_prov_PMRegisterDescriptorResponseItem_s*)x);
  case zx_prov_State_ELEM:
    return zx_LEN_WO_prov_State(c, (struct zx_prov_State_s*)x);
  case zx_prov_PMUpdateItem_ELEM:
    return zx_LEN_WO_prov_PMUpdateItem(c, (struct zx_prov_PMUpdateItem_s*)x);
  case zx_dp_Response_ELEM:
    return zx_LEN_WO_dp_Response(c, (struct zx_dp_Response_s*)x);
  case zx_dp_Request_ELEM:
    return zx_LEN_WO_dp_Request(c, (struct zx_dp_Request_s*)x);
  case zx_prov_ProvisioningServiceEPR_ELEM:
    return zx_LEN_WO_prov_ProvisioningServiceEPR(c, (struct zx_prov_ProvisioningServiceEPR_s*)x);
  case zx_prov_UpdateEPRItem_ELEM:
    return zx_LEN_WO_prov_UpdateEPRItem(c, (struct zx_prov_UpdateEPRItem_s*)x);
  case zx_ps_Object_ELEM:
    return zx_LEN_WO_ps_Object(c, (struct zx_ps_Object_s*)x);
  case zx_ps_Subscription_ELEM:
    return zx_LEN_WO_ps_Subscription(c, (struct zx_ps_Subscription_s*)x);
  case zx_ps_PStoSPRedirectURL_ELEM:
    return zx_LEN_WO_simple_elem(c, (struct zx_elem_s*)x, sizeof("PStoSPRedirectURL")-1);
  case zx_ps_CreatePSObject_ELEM:
    return zx_LEN_WO_ps_CreatePSObject(c, (struct zx_ps_CreatePSObject_s*)x);
  case zx_ps_SPtoPSRedirectURL_ELEM:
    return zx_LEN_WO_simple_elem(c, (struct zx_elem_s*)x, sizeof("SPtoPSRedirectURL")-1);
  case zx_ps_QueryString_ELEM:
    return zx_LEN_WO_simple_elem(c, (struct zx_elem_s*)x, sizeof("QueryString")-1);
  case zx_ps_TargetObjectID_ELEM:
    return zx_LEN_WO_simple_elem(c, (struct zx_elem_s*)x, sizeof("TargetObjectID")-1);
  case zx_ps_ObjectID_ELEM:
    return zx_LEN_WO_simple_elem(c, (struct zx_elem_s*)x, sizeof("ObjectID")-1);
  case zx_ps_ItemData_ELEM:
    return zx_LEN_WO_ps_ItemData(c, (struct zx_ps_ItemData_s*)x);
  case zx_ps_Notification_ELEM:
    return zx_LEN_WO_ps_Notification(c, (struct zx_ps_Notification_s*)x);
  case zx_ps_DisplayName_ELEM:
    return zx_LEN_WO_ps_DisplayName(c, (struct zx_ps_DisplayName_s*)x);
  case zx_ps_Tag_ELEM:
    return zx_LEN_WO_ps_Tag(c, (struct zx_ps_Tag_s*)x);
  case zx_ps_ObjectRef_ELEM:
    return zx_LEN_WO_simple_elem(c, (struct zx_elem_s*)x, sizeof("ObjectRef")-1);
  case zx_ps_Filter_ELEM:
    return zx_LEN_WO_simple_elem(c, (struct zx_elem_s*)x, sizeof("Filter")-1);
  case zx_ps_ResolveInput_ELEM:
    return zx_LEN_WO_ps_ResolveInput(c, (struct zx_ps_ResolveInput_s*)x);
  case zx_ps_ResolveOutput_ELEM:
    return zx_LEN_WO_ps_ResolveOutput(c, (struct zx_ps_ResolveOutput_s*)x);
  case zx_ps_Result_ELEM:
    return zx_LEN_WO_simple_elem(c, (struct zx_elem_s*)x, sizeof("Result")-1);
  case zx_sa_AssertionIDRef_ELEM:
    return zx_LEN_WO_simple_elem(c, (struct zx_elem_s*)x, sizeof("AssertionIDRef")-1);
  case zx_sa_AssertionURIRef_ELEM:
    return zx_LEN_WO_simple_elem(c, (struct zx_elem_s*)x, sizeof("AssertionURIRef")-1);
  case zx_sa_Conditions_ELEM:
    return zx_LEN_WO_sa_Conditions(c, (struct zx_sa_Conditions_s*)x);
  case zx_sa_Advice_ELEM:
    return zx_LEN_WO_sa_Advice(c, (struct zx_sa_Advice_s*)x);
  case zx_sa_Statement_ELEM:
    return zx_LEN_WO_sa_Statement(c, (struct zx_sa_Statement_s*)x);
  case zx_sa_AuthnStatement_ELEM:
    return zx_LEN_WO_sa_AuthnStatement(c, (struct zx_sa_AuthnStatement_s*)x);
  case zx_sa_AuthzDecisionStatement_ELEM:
    return zx_LEN_WO_sa_AuthzDecisionStatement(c, (struct zx_sa_AuthzDecisionStatement_s*)x);
  case zx_sa_EncryptedAttribute_ELEM:
    return zx_LEN_WO_sa_EncryptedAttribute(c, (struct zx_sa_EncryptedAttribute_s*)x);
  case zx_sa_Audience_ELEM:
    return zx_LEN_WO_simple_elem(c, (struct zx_elem_s*)x, sizeof("Audience")-1);
  case zx_sa_AuthnContextClassRef_ELEM:
    return zx_LEN_WO_simple_elem(c, (struct zx_elem_s*)x, sizeof("AuthnContextClassRef")-1);
  case zx_sa_AuthnContextDecl_ELEM:
    return zx_LEN_WO_simple_elem(c, (struct zx_elem_s*)x, sizeof("AuthnContextDecl")-1);
  case zx_sa_AuthnContextDeclRef_ELEM:
    return zx_LEN_WO_simple_elem(c, (struct zx_elem_s*)x, sizeof("AuthnContextDeclRef")-1);
  case zx_sa_AuthenticatingAuthority_ELEM:
    return zx_LEN_WO_simple_elem(c, (struct zx_elem_s*)x, sizeof("AuthenticatingAuthority")-1);
  case zx_sa_SubjectLocality_ELEM:
    return zx_LEN_WO_sa_SubjectLocality(c, (struct zx_sa_SubjectLocality_s*)x);
  case zx_sa_Action_ELEM:
    return zx_LEN_WO_sa_Action(c, (struct zx_sa_Action_s*)x);
  case zx_sa_Evidence_ELEM:
    return zx_LEN_WO_sa_Evidence(c, (struct zx_sa_Evidence_s*)x);
  case zx_sa_Condition_ELEM:
    return zx_LEN_WO_simple_elem(c, (struct zx_elem_s*)x, sizeof("Condition")-1);
  case zx_sa_AudienceRestriction_ELEM:
    return zx_LEN_WO_sa_AudienceRestriction(c, (struct zx_sa_AudienceRestriction_s*)x);
  case zx_sa_OneTimeUse_ELEM:
    return zx_LEN_WO_sa_OneTimeUse(c, (struct zx_sa_OneTimeUse_s*)x);
  case zx_sa_ProxyRestriction_ELEM:
    return zx_LEN_WO_sa_ProxyRestriction(c, (struct zx_sa_ProxyRestriction_s*)x);
  case zx_idp_SubjectRestriction_ELEM:
    return zx_LEN_WO_idp_SubjectRestriction(c, (struct zx_idp_SubjectRestriction_s*)x);
  case zx_sa_BaseID_ELEM:
    return zx_LEN_WO_sa_BaseID(c, (struct zx_sa_BaseID_s*)x);
  case zx_sa_EncryptedID_ELEM:
    return zx_LEN_WO_sa_EncryptedID(c, (struct zx_sa_EncryptedID_s*)x);
  case zx_sa_SubjectConfirmation_ELEM:
    return zx_LEN_WO_sa_SubjectConfirmation(c, (struct zx_sa_SubjectConfirmation_s*)x);
  case zx_sa_SubjectConfirmationData_ELEM:
    return zx_LEN_WO_sa_SubjectConfirmationData(c, (struct zx_sa_SubjectConfirmationData_s*)x);
  case zx_sa11_AssertionIDReference_ELEM:
    return zx_LEN_WO_simple_elem(c, (struct zx_elem_s*)x, sizeof("AssertionIDReference")-1);
  case zx_sa11_AttributeValue_ELEM:
    return zx_LEN_WO_sa11_AttributeValue(c, (struct zx_sa11_AttributeValue_s*)x);
  case zx_sa11_Attribute_ELEM:
    return zx_LEN_WO_sa11_Attribute(c, (struct zx_sa11_Attribute_s*)x);
  case zx_sa11_Audience_ELEM:
    return zx_LEN_WO_simple_elem(c, (struct zx_elem_s*)x, sizeof("Audience")-1);
  case zx_sa11_Action_ELEM:
    return zx_LEN_WO_sa11_Action(c, (struct zx_sa11_Action_s*)x);
  case zx_sa11_Evidence_ELEM:
    return zx_LEN_WO_sa11_Evidence(c, (struct zx_sa11_Evidence_s*)x);
  case zx_sa11_AudienceRestrictionCondition_ELEM:
    return zx_LEN_WO_sa11_AudienceRestrictionCondition(c, (struct zx_sa11_AudienceRestrictionCondition_s*)x);
  case zx_sa11_DoNotCacheCondition_ELEM:
    return zx_LEN_WO_sa11_DoNotCacheCondition(c, (struct zx_sa11_DoNotCacheCondition_s*)x);
  case zx_sa11_Condition_ELEM:
    return zx_LEN_WO_simple_elem(c, (struct zx_elem_s*)x, sizeof("Condition")-1);
  case zx_sa11_ConfirmationMethod_ELEM:
    return zx_LEN_WO_simple_elem(c, (struct zx_elem_s*)x, sizeof("ConfirmationMethod")-1);
  case zx_sa11_SubjectConfirmationData_ELEM:
    return zx_LEN_WO_simple_elem(c, (struct zx_elem_s*)x, sizeof("SubjectConfirmationData")-1);
  case zx_sec_TransitedProvider_ELEM:
    return zx_LEN_WO_sec_TransitedProvider(c, (struct zx_sec_TransitedProvider_s*)x);
  case zx_sec12_Issuer_ELEM:
    return zx_LEN_WO_simple_elem(c, (struct zx_elem_s*)x, sizeof("Issuer")-1);
  case zx_sec12_IssueInstant_ELEM:
    return zx_LEN_WO_simple_elem(c, (struct zx_elem_s*)x, sizeof("IssueInstant")-1);
  case zx_sec12_ProxySubject_ELEM:
    return zx_LEN_WO_sec12_ProxySubject(c, (struct zx_sec12_ProxySubject_s*)x);
  case zx_sec12_SessionContext_ELEM:
    return zx_LEN_WO_sec12_SessionContext(c, (struct zx_sec12_SessionContext_s*)x);
  case zx_sec12_SessionSubject_ELEM:
    return zx_LEN_WO_sec12_SessionSubject(c, (struct zx_sec12_SessionSubject_s*)x);
  case zx_sec12_ProviderID_ELEM:
    return zx_LEN_WO_simple_elem(c, (struct zx_elem_s*)x, sizeof("ProviderID")-1);
  case zx_sec12_NumberOfUses_ELEM:
    return zx_LEN_WO_simple_elem(c, (struct zx_elem_s*)x, sizeof("NumberOfUses")-1);
  case zx_shps_ServiceHandle_ELEM:
    return zx_LEN_WO_simple_elem(c, (struct zx_elem_s*)x, sizeof("ServiceHandle")-1);
  case zx_shps_GetStatusResponseItem_ELEM:
    return zx_LEN_WO_shps_GetStatusResponseItem(c, (struct zx_shps_GetStatusResponseItem_s*)x);
  case zx_shps_ServiceStatus_ELEM:
    return zx_LEN_WO_simple_elem(c, (struct zx_elem_s*)x, sizeof("ServiceStatus")-1);
  case zx_shps_InvokingProvider_ELEM:
    return zx_LEN_WO_simple_elem(c, (struct zx_elem_s*)x, sizeof("InvokingProvider")-1);
  case zx_shps_InvokingPrincipal_ELEM:
    return zx_LEN_WO_simple_elem(c, (struct zx_elem_s*)x, sizeof("InvokingPrincipal")-1);
  case zx_shps_InvokeResponseItem_ELEM:
    return zx_LEN_WO_shps_InvokeResponseItem(c, (struct zx_shps_InvokeResponseItem_s*)x);
  case zx_shps_ProxyInvokeItem_ELEM:
    return zx_LEN_WO_shps_ProxyInvokeItem(c, (struct zx_shps_ProxyInvokeItem_s*)x);
  case zx_shps_InvocationContext_ELEM:
    return zx_LEN_WO_shps_InvocationContext(c, (struct zx_shps_InvocationContext_s*)x);
  case zx_shps_RequestHeaders_ELEM:
    return zx_LEN_WO_simple_elem(c, (struct zx_elem_s*)x, sizeof("RequestHeaders")-1);
  case zx_shps_ProxyInvokeResponseItem_ELEM:
    return zx_LEN_WO_shps_ProxyInvokeResponseItem(c, (struct zx_shps_ProxyInvokeResponseItem_s*)x);
  case zx_shps_ResponseHeaders_ELEM:
    return zx_LEN_WO_simple_elem(c, (struct zx_elem_s*)x, sizeof("ResponseHeaders")-1);
  case zx_shps_RegisterResponseItem_ELEM:
    return zx_LEN_WO_shps_RegisterResponseItem(c, (struct zx_shps_RegisterResponseItem_s*)x);
  case zx_shps_SetStatusItem_ELEM:
    return zx_LEN_WO_shps_SetStatusItem(c, (struct zx_shps_SetStatusItem_s*)x);
  case zx_shps_UpdateItem_ELEM:
    return zx_LEN_WO_shps_UpdateItem(c, (struct zx_shps_UpdateItem_s*)x);
  case zx_sp_Extensions_ELEM:
    return zx_LEN_WO_sp_Extensions(c, (struct zx_sp_Extensions_s*)x);
  case zx_sp_Artifact_ELEM:
    return zx_LEN_WO_simple_elem(c, (struct zx_elem_s*)x, sizeof("Artifact")-1);
  case zx_sp_Status_ELEM:
    return zx_LEN_WO_sp_Status(c, (struct zx_sp_Status_s*)x);
  case zx_sp_NameIDPolicy_ELEM:
    return zx_LEN_WO_sp_NameIDPolicy(c, (struct zx_sp_NameIDPolicy_s*)x);
  case zx_sp_Scoping_ELEM:
    return zx_LEN_WO_sp_Scoping(c, (struct zx_sp_Scoping_s*)x);
  case zx_sp_IDPEntry_ELEM:
    return zx_LEN_WO_sp_IDPEntry(c, (struct zx_sp_IDPEntry_s*)x);
  case zx_sp_GetComplete_ELEM:
    return zx_LEN_WO_simple_elem(c, (struct zx_elem_s*)x, sizeof("GetComplete")-1);
  case zx_sp_SessionIndex_ELEM:
    return zx_LEN_WO_simple_elem(c, (struct zx_elem_s*)x, sizeof("SessionIndex")-1);
  case zx_sp_NewID_ELEM:
    return zx_LEN_WO_simple_elem(c, (struct zx_elem_s*)x, sizeof("NewID")-1);
  case zx_sp_NewEncryptedID_ELEM:
    return zx_LEN_WO_sp_NewEncryptedID(c, (struct zx_sp_NewEncryptedID_s*)x);
  case zx_sp_Terminate_ELEM:
    return zx_LEN_WO_simple_elem(c, (struct zx_elem_s*)x, sizeof("Terminate")-1);
  case zx_sp_RequesterID_ELEM:
    return zx_LEN_WO_simple_elem(c, (struct zx_elem_s*)x, sizeof("RequesterID")-1);
  case zx_sp_StatusCode_ELEM:
    return zx_LEN_WO_sp_StatusCode(c, (struct zx_sp_StatusCode_s*)x);
  case zx_sp_StatusMessage_ELEM:
    return zx_LEN_WO_simple_elem(c, (struct zx_elem_s*)x, sizeof("StatusMessage")-1);
  case zx_sp_StatusDetail_ELEM:
    return zx_LEN_WO_sp_StatusDetail(c, (struct zx_sp_StatusDetail_s*)x);
  case zx_sa11_AttributeDesignator_ELEM:
    return zx_LEN_WO_sa11_AttributeDesignator(c, (struct zx_sa11_AttributeDesignator_s*)x);
  case zx_sp11_Query_ELEM:
    return zx_LEN_WO_simple_elem(c, (struct zx_elem_s*)x, sizeof("Query")-1);
  case zx_sp11_SubjectQuery_ELEM:
    return zx_LEN_WO_sp11_SubjectQuery(c, (struct zx_sp11_SubjectQuery_s*)x);
  case zx_sp11_AuthenticationQuery_ELEM:
    return zx_LEN_WO_sp11_AuthenticationQuery(c, (struct zx_sp11_AuthenticationQuery_s*)x);
  case zx_sp11_AttributeQuery_ELEM:
    return zx_LEN_WO_sp11_AttributeQuery(c, (struct zx_sp11_AttributeQuery_s*)x);
  case zx_sp11_AuthorizationDecisionQuery_ELEM:
    return zx_LEN_WO_sp11_AuthorizationDecisionQuery(c, (struct zx_sp11_AuthorizationDecisionQuery_s*)x);
  case zx_sp11_AssertionArtifact_ELEM:
    return zx_LEN_WO_simple_elem(c, (struct zx_elem_s*)x, sizeof("AssertionArtifact")-1);
  case zx_sp11_StatusCode_ELEM:
    return zx_LEN_WO_sp11_StatusCode(c, (struct zx_sp11_StatusCode_s*)x);
  case zx_sp11_StatusMessage_ELEM:
    return zx_LEN_WO_simple_elem(c, (struct zx_elem_s*)x, sizeof("StatusMessage")-1);
  case zx_sp11_StatusDetail_ELEM:
    return zx_LEN_WO_sp11_StatusDetail(c, (struct zx_sp11_StatusDetail_s*)x);
  case zx_xac_Attribute_ELEM:
    return zx_LEN_WO_xac_Attribute(c, (struct zx_xac_Attribute_s*)x);
  case zx_tas3_ESLRef_ELEM:
    return zx_LEN_WO_tas3_ESLRef(c, (struct zx_tas3_ESLRef_s*)x);
  case zx_tas3_ESLApply_ELEM:
    return zx_LEN_WO_tas3_ESLApply(c, (struct zx_tas3_ESLApply_s*)x);
  case zx_wsse_SecurityTokenReference_ELEM:
    return zx_LEN_WO_wsse_SecurityTokenReference(c, (struct zx_wsse_SecurityTokenReference_s*)x);
  case zx_wsc_Properties_ELEM:
    return zx_LEN_WO_wsc_Properties(c, (struct zx_wsc_Properties_s*)x);
  case zx_wsc_Generation_ELEM:
    return zx_LEN_WO_simple_elem(c, (struct zx_elem_s*)x, sizeof("Generation")-1);
  case zx_wsc_Offset_ELEM:
    return zx_LEN_WO_simple_elem(c, (struct zx_elem_s*)x, sizeof("Offset")-1);
  case zx_wsc_Length_ELEM:
    return zx_LEN_WO_simple_elem(c, (struct zx_elem_s*)x, sizeof("Length")-1);
  case zx_wsc_Label_ELEM:
    return zx_LEN_WO_simple_elem(c, (struct zx_elem_s*)x, sizeof("Label")-1);
  case zx_wsc_Nonce_ELEM:
    return zx_LEN_WO_simple_elem(c, (struct zx_elem_s*)x, sizeof("Nonce")-1);
  case zx_wsp_Policy_ELEM:
    return zx_LEN_WO_wsp_Policy(c, (struct zx_wsp_Policy_s*)x);
  case zx_wsp_All_ELEM:
    return zx_LEN_WO_wsp_All(c, (struct zx_wsp_All_s*)x);
  case zx_wsp_ExactlyOne_ELEM:
    return zx_LEN_WO_wsp_ExactlyOne(c, (struct zx_wsp_ExactlyOne_s*)x);
  case zx_wsp_PolicyReference_ELEM:
    return zx_LEN_WO_wsp_PolicyReference(c, (struct zx_wsp_PolicyReference_s*)x);
  case zx_wsp_AppliesTo_ELEM:
    return zx_LEN_WO_wsp_AppliesTo(c, (struct zx_wsp_AppliesTo_s*)x);
  case zx_wsse_BinarySecurityToken_ELEM:
    return zx_LEN_WO_wsse_BinarySecurityToken(c, (struct zx_wsse_BinarySecurityToken_s*)x);
  case zx_wsu_Timestamp_ELEM:
    return zx_LEN_WO_wsu_Timestamp(c, (struct zx_wsu_Timestamp_s*)x);
  case zx_wsse_KeyIdentifier_ELEM:
    return zx_LEN_WO_wsse_KeyIdentifier(c, (struct zx_wsse_KeyIdentifier_s*)x);
  case zx_wsse_Username_ELEM:
    return zx_LEN_WO_wsse_Username(c, (struct zx_wsse_Username_s*)x);
  case zx_wst_CombinedHash_ELEM:
    return zx_LEN_WO_simple_elem(c, (struct zx_elem_s*)x, sizeof("CombinedHash")-1);
  case zx_wst_RequestSecurityTokenResponse_ELEM:
    return zx_LEN_WO_wst_RequestSecurityTokenResponse(c, (struct zx_wst_RequestSecurityTokenResponse_s*)x);
  case zx_wsu_Created_ELEM:
    return zx_LEN_WO_wsu_Created(c, (struct zx_wsu_Created_s*)x);
  case zx_wsu_Expires_ELEM:
    return zx_LEN_WO_wsu_Expires(c, (struct zx_wsu_Expires_s*)x);
  case zx_wst_Primary_ELEM:
    return zx_LEN_WO_wst_Primary(c, (struct zx_wst_Primary_s*)x);
  case zx_wst_Participant_ELEM:
    return zx_LEN_WO_wst_Participant(c, (struct zx_wst_Participant_s*)x);
  case zx_wst_TokenType_ELEM:
    return zx_LEN_WO_simple_elem(c, (struct zx_elem_s*)x, sizeof("TokenType")-1);
  case zx_wst_RequestType_ELEM:
    return zx_LEN_WO_simple_elem(c, (struct zx_elem_s*)x, sizeof("RequestType")-1);
  case zx_wst_Claims_ELEM:
    return zx_LEN_WO_wst_Claims(c, (struct zx_wst_Claims_s*)x);
  case zx_wst_Entropy_ELEM:
    return zx_LEN_WO_wst_Entropy(c, (struct zx_wst_Entropy_s*)x);
  case zx_wst_Lifetime_ELEM:
    return zx_LEN_WO_wst_Lifetime(c, (struct zx_wst_Lifetime_s*)x);
  case zx_wst_AllowPostdating_ELEM:
    return zx_LEN_WO_simple_elem(c, (struct zx_elem_s*)x, sizeof("AllowPostdating")-1);
  case zx_wst_Renewing_ELEM:
    return zx_LEN_WO_wst_Renewing(c, (struct zx_wst_Renewing_s*)x);
  case zx_wst_OnBehalfOf_ELEM:
    return zx_LEN_WO_wst_OnBehalfOf(c, (struct zx_wst_OnBehalfOf_s*)x);
  case zx_wst_Issuer_ELEM:
    return zx_LEN_WO_wst_Issuer(c, (struct zx_wst_Issuer_s*)x);
  case zx_wst_AuthenticationType_ELEM:
    return zx_LEN_WO_simple_elem(c, (struct zx_elem_s*)x, sizeof("AuthenticationType")-1);
  case zx_wst_KeyType_ELEM:
    return zx_LEN_WO_simple_elem(c, (struct zx_elem_s*)x, sizeof("KeyType")-1);
  case zx_wst_KeySize_ELEM:
    return zx_LEN_WO_simple_elem(c, (struct zx_elem_s*)x, sizeof("KeySize")-1);
  case zx_wst_SignatureAlgorithm_ELEM:
    return zx_LEN_WO_simple_elem(c, (struct zx_elem_s*)x, sizeof("SignatureAlgorithm")-1);
  case zx_wst_Encryption_ELEM:
    return zx_LEN_WO_wst_Encryption(c, (struct zx_wst_Encryption_s*)x);
  case zx_wst_EncryptionAlgorithm_ELEM:
    return zx_LEN_WO_simple_elem(c, (struct zx_elem_s*)x, sizeof("EncryptionAlgorithm")-1);
  case zx_wst_CanonicalizationAlgorithm_ELEM:
    return zx_LEN_WO_simple_elem(c, (struct zx_elem_s*)x, sizeof("CanonicalizationAlgorithm")-1);
  case zx_wst_ProofEncryption_ELEM:
    return zx_LEN_WO_wst_ProofEncryption(c, (struct zx_wst_ProofEncryption_s*)x);
  case zx_wst_UseKey_ELEM:
    return zx_LEN_WO_wst_UseKey(c, (struct zx_wst_UseKey_s*)x);
  case zx_wst_SignWith_ELEM:
    return zx_LEN_WO_simple_elem(c, (struct zx_elem_s*)x, sizeof("SignWith")-1);
  case zx_wst_EncryptWith_ELEM:
    return zx_LEN_WO_simple_elem(c, (struct zx_elem_s*)x, sizeof("EncryptWith")-1);
  case zx_wst_DelegateTo_ELEM:
    return zx_LEN_WO_wst_DelegateTo(c, (struct zx_wst_DelegateTo_s*)x);
  case zx_wst_Forwardable_ELEM:
    return zx_LEN_WO_simple_elem(c, (struct zx_elem_s*)x, sizeof("Forwardable")-1);
  case zx_wst_Delegatable_ELEM:
    return zx_LEN_WO_simple_elem(c, (struct zx_elem_s*)x, sizeof("Delegatable")-1);
  case zx_wst_RequestSecurityToken_ELEM:
    return zx_LEN_WO_wst_RequestSecurityToken(c, (struct zx_wst_RequestSecurityToken_s*)x);
  case zx_wst_RequestedSecurityToken_ELEM:
    return zx_LEN_WO_wst_RequestedSecurityToken(c, (struct zx_wst_RequestedSecurityToken_s*)x);
  case zx_wst_RequestedAttachedReference_ELEM:
    return zx_LEN_WO_wst_RequestedAttachedReference(c, (struct zx_wst_RequestedAttachedReference_s*)x);
  case zx_wst_RequestedUnattachedReference_ELEM:
    return zx_LEN_WO_wst_RequestedUnattachedReference(c, (struct zx_wst_RequestedUnattachedReference_s*)x);
  case zx_wst_RequestedProofToken_ELEM:
    return zx_LEN_WO_wst_RequestedProofToken(c, (struct zx_wst_RequestedProofToken_s*)x);
  case zx_wst_Status_ELEM:
    return zx_LEN_WO_wst_Status(c, (struct zx_wst_Status_s*)x);
  case zx_wst_Authenticator_ELEM:
    return zx_LEN_WO_wst_Authenticator(c, (struct zx_wst_Authenticator_s*)x);
  case zx_wst_Challenge_ELEM:
    return zx_LEN_WO_simple_elem(c, (struct zx_elem_s*)x, sizeof("Challenge")-1);
  case zx_wst_Code_ELEM:
    return zx_LEN_WO_simple_elem(c, (struct zx_elem_s*)x, sizeof("Code")-1);
  case zx_wst_Reason_ELEM:
    return zx_LEN_WO_simple_elem(c, (struct zx_elem_s*)x, sizeof("Reason")-1);
  case zx_xa_ActionMatch_ELEM:
    return zx_LEN_WO_xa_ActionMatch(c, (struct zx_xa_ActionMatch_s*)x);
  case zx_xa_AttributeValue_ELEM:
    return zx_LEN_WO_xa_AttributeValue(c, (struct zx_xa_AttributeValue_s*)x);
  case zx_xa_ActionAttributeDesignator_ELEM:
    return zx_LEN_WO_xa_ActionAttributeDesignator(c, (struct zx_xa_ActionAttributeDesignator_s*)x);
  case zx_xa_AttributeSelector_ELEM:
    return zx_LEN_WO_xa_AttributeSelector(c, (struct zx_xa_AttributeSelector_s*)x);
  case zx_xa_Action_ELEM:
    return zx_LEN_WO_xa_Action(c, (struct zx_xa_Action_s*)x);
  case zx_xa_Expression_ELEM:
    return zx_LEN_WO_simple_elem(c, (struct zx_elem_s*)x, sizeof("Expression")-1);
  case zx_xa_CombinerParameter_ELEM:
    return zx_LEN_WO_xa_CombinerParameter(c, (struct zx_xa_CombinerParameter_s*)x);
  case zx_xa_EnvironmentMatch_ELEM:
    return zx_LEN_WO_xa_EnvironmentMatch(c, (struct zx_xa_EnvironmentMatch_s*)x);
  case zx_xa_EnvironmentAttributeDesignator_ELEM:
    return zx_LEN_WO_xa_EnvironmentAttributeDesignator(c, (struct zx_xa_EnvironmentAttributeDesignator_s*)x);
  case zx_xa_Environment_ELEM:
    return zx_LEN_WO_xa_Environment(c, (struct zx_xa_Environment_s*)x);
  case zx_xa_AttributeAssignment_ELEM:
    return zx_LEN_WO_xa_AttributeAssignment(c, (struct zx_xa_AttributeAssignment_s*)x);
  case zx_xa_Description_ELEM:
    return zx_LEN_WO_simple_elem(c, (struct zx_elem_s*)x, sizeof("Description")-1);
  case zx_xa_PolicyDefaults_ELEM:
    return zx_LEN_WO_xa_PolicyDefaults(c, (struct zx_xa_PolicyDefaults_s*)x);
  case zx_xa_Target_ELEM:
    return zx_LEN_WO_xa_Target(c, (struct zx_xa_Target_s*)x);
  case zx_xa_CombinerParameters_ELEM:
    return zx_LEN_WO_xa_CombinerParameters(c, (struct zx_xa_CombinerParameters_s*)x);
  case zx_xa_RuleCombinerParameters_ELEM:
    return zx_LEN_WO_xa_RuleCombinerParameters(c, (struct zx_xa_RuleCombinerParameters_s*)x);
  case zx_xa_VariableDefinition_ELEM:
    return zx_LEN_WO_xa_VariableDefinition(c, (struct zx_xa_VariableDefinition_s*)x);
  case zx_xa_Rule_ELEM:
    return zx_LEN_WO_xa_Rule(c, (struct zx_xa_Rule_s*)x);
  case zx_xa_Obligations_ELEM:
    return zx_LEN_WO_xa_Obligations(c, (struct zx_xa_Obligations_s*)x);
  case zx_xa_XPathVersion_ELEM:
    return zx_LEN_WO_simple_elem(c, (struct zx_elem_s*)x, sizeof("XPathVersion")-1);
  case zx_xa_PolicySetDefaults_ELEM:
    return zx_LEN_WO_xa_PolicySetDefaults(c, (struct zx_xa_PolicySetDefaults_s*)x);
  case zx_xa_PolicySet_ELEM:
    return zx_LEN_WO_xa_PolicySet(c, (struct zx_xa_PolicySet_s*)x);
  case zx_xa_Policy_ELEM:
    return zx_LEN_WO_xa_Policy(c, (struct zx_xa_Policy_s*)x);
  case zx_xa_PolicySetIdReference_ELEM:
    return zx_LEN_WO_xa_PolicySetIdReference(c, (struct zx_xa_PolicySetIdReference_s*)x);
  case zx_xa_PolicyIdReference_ELEM:
    return zx_LEN_WO_xa_PolicyIdReference(c, (struct zx_xa_PolicyIdReference_s*)x);
  case zx_xa_PolicyCombinerParameters_ELEM:
    return zx_LEN_WO_xa_PolicyCombinerParameters(c, (struct zx_xa_PolicyCombinerParameters_s*)x);
  case zx_xa_PolicySetCombinerParameters_ELEM:
    return zx_LEN_WO_xa_PolicySetCombinerParameters(c, (struct zx_xa_PolicySetCombinerParameters_s*)x);
  case zx_xa_ResourceMatch_ELEM:
    return zx_LEN_WO_xa_ResourceMatch(c, (struct zx_xa_ResourceMatch_s*)x);
  case zx_xa_ResourceAttributeDesignator_ELEM:
    return zx_LEN_WO_xa_ResourceAttributeDesignator(c, (struct zx_xa_ResourceAttributeDesignator_s*)x);
  case zx_xa_Resource_ELEM:
    return zx_LEN_WO_xa_Resource(c, (struct zx_xa_Resource_s*)x);
  case zx_xa_Condition_ELEM:
    return zx_LEN_WO_xa_Condition(c, (struct zx_xa_Condition_s*)x);
  case zx_xa_SubjectMatch_ELEM:
    return zx_LEN_WO_xa_SubjectMatch(c, (struct zx_xa_SubjectMatch_s*)x);
  case zx_xa_SubjectAttributeDesignator_ELEM:
    return zx_LEN_WO_xa_SubjectAttributeDesignator(c, (struct zx_xa_SubjectAttributeDesignator_s*)x);
  case zx_xa_Subject_ELEM:
    return zx_LEN_WO_xa_Subject(c, (struct zx_xa_Subject_s*)x);
  case zx_xa_Subjects_ELEM:
    return zx_LEN_WO_xa_Subjects(c, (struct zx_xa_Subjects_s*)x);
  case zx_xa_Resources_ELEM:
    return zx_LEN_WO_xa_Resources(c, (struct zx_xa_Resources_s*)x);
  case zx_xa_Actions_ELEM:
    return zx_LEN_WO_xa_Actions(c, (struct zx_xa_Actions_s*)x);
  case zx_xa_Environments_ELEM:
    return zx_LEN_WO_xa_Environments(c, (struct zx_xa_Environments_s*)x);
  case zx_xac_AttributeValue_ELEM:
    return zx_LEN_WO_simple_elem(c, (struct zx_elem_s*)x, sizeof("AttributeValue")-1);
  case zx_xac_Subject_ELEM:
    return zx_LEN_WO_xac_Subject(c, (struct zx_xac_Subject_s*)x);
  case zx_xac_Resource_ELEM:
    return zx_LEN_WO_xac_Resource(c, (struct zx_xac_Resource_s*)x);
  case zx_xac_Action_ELEM:
    return zx_LEN_WO_xac_Action(c, (struct zx_xac_Action_s*)x);
  case zx_xac_Environment_ELEM:
    return zx_LEN_WO_xac_Environment(c, (struct zx_xac_Environment_s*)x);
  case zx_xac_ResourceContent_ELEM:
    return zx_LEN_WO_xac_ResourceContent(c, (struct zx_xac_ResourceContent_s*)x);
  case zx_xac_Result_ELEM:
    return zx_LEN_WO_xac_Result(c, (struct zx_xac_Result_s*)x);
  case zx_xac_Decision_ELEM:
    return zx_LEN_WO_simple_elem(c, (struct zx_elem_s*)x, sizeof("Decision")-1);
  case zx_xac_Status_ELEM:
    return zx_LEN_WO_xac_Status(c, (struct zx_xac_Status_s*)x);
  case zx_xac_StatusCode_ELEM:
    return zx_LEN_WO_xac_StatusCode(c, (struct zx_xac_StatusCode_s*)x);
  case zx_xac_StatusMessage_ELEM:
    return zx_LEN_WO_simple_elem(c, (struct zx_elem_s*)x, sizeof("StatusMessage")-1);
  case zx_xac_StatusDetail_ELEM:
    return zx_LEN_WO_xac_StatusDetail(c, (struct zx_xac_StatusDetail_s*)x);
  case zx_xasacd1_ReferencedPolicies_ELEM:
    return zx_LEN_WO_xasacd1_ReferencedPolicies(c, (struct zx_xasacd1_ReferencedPolicies_s*)x);
  case zx_xenc_KA_Nonce_ELEM:
    return zx_LEN_WO_simple_elem(c, (struct zx_elem_s*)x, sizeof("KA_Nonce")-1);
  case zx_xenc_OriginatorKeyInfo_ELEM:
    return zx_LEN_WO_xenc_OriginatorKeyInfo(c, (struct zx_xenc_OriginatorKeyInfo_s*)x);
  case zx_xenc_RecipientKeyInfo_ELEM:
    return zx_LEN_WO_xenc_RecipientKeyInfo(c, (struct zx_xenc_RecipientKeyInfo_s*)x);
  case zx_xenc_CipherValue_ELEM:
    return zx_LEN_WO_simple_elem(c, (struct zx_elem_s*)x, sizeof("CipherValue")-1);
  case zx_xenc_CipherReference_ELEM:
    return zx_LEN_WO_xenc_CipherReference(c, (struct zx_xenc_CipherReference_s*)x);
  case zx_xenc_Transforms_ELEM:
    return zx_LEN_WO_xenc_Transforms(c, (struct zx_xenc_Transforms_s*)x);
  case zx_xenc_EncryptionMethod_ELEM:
    return zx_LEN_WO_xenc_EncryptionMethod(c, (struct zx_xenc_EncryptionMethod_s*)x);
  case zx_xenc_CipherData_ELEM:
    return zx_LEN_WO_xenc_CipherData(c, (struct zx_xenc_CipherData_s*)x);
  case zx_xenc_EncryptionProperties_ELEM:
    return zx_LEN_WO_xenc_EncryptionProperties(c, (struct zx_xenc_EncryptionProperties_s*)x);
  case zx_xenc_ReferenceList_ELEM:
    return zx_LEN_WO_xenc_ReferenceList(c, (struct zx_xenc_ReferenceList_s*)x);
  case zx_xenc_CarriedKeyName_ELEM:
    return zx_LEN_WO_simple_elem(c, (struct zx_elem_s*)x, sizeof("CarriedKeyName")-1);
  case zx_xenc_EncryptionProperty_ELEM:
    return zx_LEN_WO_xenc_EncryptionProperty(c, (struct zx_xenc_EncryptionProperty_s*)x);
  case zx_xenc_DataReference_ELEM:
    return zx_LEN_WO_xenc_DataReference(c, (struct zx_xenc_DataReference_s*)x);
  case zx_xenc_KeyReference_ELEM:
    return zx_LEN_WO_xenc_KeyReference(c, (struct zx_xenc_KeyReference_s*)x);
  case zx_e_Envelope_ELEM:
    return zx_LEN_WO_e_Envelope(c, (struct zx_e_Envelope_s*)x);
  case zx_ff12_AuthnRequestEnvelope_ELEM:
    return zx_LEN_WO_ff12_AuthnRequestEnvelope(c, (struct zx_ff12_AuthnRequestEnvelope_s*)x);
  case zx_ff12_AuthnResponseEnvelope_ELEM:
    return zx_LEN_WO_ff12_AuthnResponseEnvelope(c, (struct zx_ff12_AuthnResponseEnvelope_s*)x);
  case zx_m20_EntitiesDescriptor_ELEM:
    return zx_LEN_WO_m20_EntitiesDescriptor(c, (struct zx_m20_EntitiesDescriptor_s*)x);

  case ZX_TOK_NOT_FOUND:
    len = 1 + ZX_ANY_EL(x)->name_len + 1 + 2 + ZX_ANY_EL(x)->name_len + 1;
    if (x->g.ns && x->g.ns->prefix_len)
      len += (x->g.ns->prefix_len + 1) * 2;
    len += zx_len_wo_common(c, x);
    return len;
  case ZX_TOK_DATA:
    return ((struct zx_str*)x)->len;
    break;
  default:
    NEVER("Impossible token(%d)", x->g.tok);
  }
  return 0;
}

/* FUNC(zx_ENC_WO_any_elem) */

/* Called by: */
char* zx_ENC_WO_any_elem(struct zx_ctx* c, struct zx_elem_s* x, char* p)
{
  struct zx_ns_s* pop_seen = 0;
  struct zx_elem_s* kid;
  switch (x->g.tok) {
  case zx_a_Address_ELEM:
    return zx_ENC_WO_a_Address(c, (struct zx_a_Address_s*)x, p);
  case zx_a_ReferenceParameters_ELEM:
    return zx_ENC_WO_a_ReferenceParameters(c, (struct zx_a_ReferenceParameters_s*)x, p);
  case zx_a_Metadata_ELEM:
    return zx_ENC_WO_a_Metadata(c, (struct zx_a_Metadata_s*)x, p);
  case zx_sbf_Framework_ELEM:
    return zx_ENC_WO_sbf_Framework(c, (struct zx_sbf_Framework_s*)x, p);
  case zx_di_Abstract_ELEM:
    return zx_ENC_WO_simple_elem(c, (struct zx_elem_s*)x, p, "Abstract", sizeof("Abstract")-1);
  case zx_di_ProviderID_ELEM:
    return zx_ENC_WO_simple_elem(c, (struct zx_elem_s*)x, p, "ProviderID", sizeof("ProviderID")-1);
  case zx_di_ServiceType_ELEM:
    return zx_ENC_WO_simple_elem(c, (struct zx_elem_s*)x, p, "ServiceType", sizeof("ServiceType")-1);
  case zx_di_SecurityContext_ELEM:
    return zx_ENC_WO_di_SecurityContext(c, (struct zx_di_SecurityContext_s*)x, p);
  case zx_a_Action_ELEM:
    return zx_ENC_WO_a_Action(c, (struct zx_a_Action_s*)x, p);
  case zx_a_SoapAction_ELEM:
    return zx_ENC_WO_simple_elem(c, (struct zx_elem_s*)x, p, "SoapAction", sizeof("SoapAction")-1);
  case zx_b_TargetIdentity_ELEM:
    return zx_ENC_WO_b_TargetIdentity(c, (struct zx_b_TargetIdentity_s*)x, p);
  case zx_ac_ActivationLimitDuration_ELEM:
    return zx_ENC_WO_ac_ActivationLimitDuration(c, (struct zx_ac_ActivationLimitDuration_s*)x, p);
  case zx_ac_ActivationLimitUsages_ELEM:
    return zx_ENC_WO_ac_ActivationLimitUsages(c, (struct zx_ac_ActivationLimitUsages_s*)x, p);
  case zx_ac_ActivationLimitSession_ELEM:
    return zx_ENC_WO_simple_elem(c, (struct zx_elem_s*)x, p, "ActivationLimitSession", sizeof("ActivationLimitSession")-1);
  case zx_ac_Length_ELEM:
    return zx_ENC_WO_ac_Length(c, (struct zx_ac_Length_s*)x, p);
  case zx_ac_Alphabet_ELEM:
    return zx_ENC_WO_ac_Alphabet(c, (struct zx_ac_Alphabet_s*)x, p);
  case zx_ac_Generation_ELEM:
    return zx_ENC_WO_ac_Generation(c, (struct zx_ac_Generation_s*)x, p);
  case zx_ac_ActivationLimit_ELEM:
    return zx_ENC_WO_ac_ActivationLimit(c, (struct zx_ac_ActivationLimit_s*)x, p);
  case zx_ac_Extension_ELEM:
    return zx_ENC_WO_ac_Extension(c, (struct zx_ac_Extension_s*)x, p);
  case zx_ac_GoverningAgreements_ELEM:
    return zx_ENC_WO_ac_GoverningAgreements(c, (struct zx_ac_GoverningAgreements_s*)x, p);
  case zx_ac_Identification_ELEM:
    return zx_ENC_WO_ac_Identification(c, (struct zx_ac_Identification_s*)x, p);
  case zx_ac_TechnicalProtection_ELEM:
    return zx_ENC_WO_ac_TechnicalProtection(c, (struct zx_ac_TechnicalProtection_s*)x, p);
  case zx_ac_OperationalProtection_ELEM:
    return zx_ENC_WO_ac_OperationalProtection(c, (struct zx_ac_OperationalProtection_s*)x, p);
  case zx_ac_AuthenticationMethod_ELEM:
    return zx_ENC_WO_ac_AuthenticationMethod(c, (struct zx_ac_AuthenticationMethod_s*)x, p);
  case zx_ac_AuthenticatingAuthority_ELEM:
    return zx_ENC_WO_ac_AuthenticatingAuthority(c, (struct zx_ac_AuthenticatingAuthority_s*)x, p);
  case zx_ac_PrincipalAuthenticationMechanism_ELEM:
    return zx_ENC_WO_ac_PrincipalAuthenticationMechanism(c, (struct zx_ac_PrincipalAuthenticationMechanism_s*)x, p);
  case zx_ac_Authenticator_ELEM:
    return zx_ENC_WO_ac_Authenticator(c, (struct zx_ac_Authenticator_s*)x, p);
  case zx_ac_AuthenticatorTransportProtocol_ELEM:
    return zx_ENC_WO_ac_AuthenticatorTransportProtocol(c, (struct zx_ac_AuthenticatorTransportProtocol_s*)x, p);
  case zx_ac_PreviousSession_ELEM:
    return zx_ENC_WO_ac_PreviousSession(c, (struct zx_ac_PreviousSession_s*)x, p);
  case zx_ac_ResumeSession_ELEM:
    return zx_ENC_WO_ac_ResumeSession(c, (struct zx_ac_ResumeSession_s*)x, p);
  case zx_ac_DigSig_ELEM:
    return zx_ENC_WO_ac_DigSig(c, (struct zx_ac_DigSig_s*)x, p);
  case zx_ac_Password_ELEM:
    return zx_ENC_WO_ac_Password(c, (struct zx_ac_Password_s*)x, p);
  case zx_ac_ZeroKnowledge_ELEM:
    return zx_ENC_WO_ac_ZeroKnowledge(c, (struct zx_ac_ZeroKnowledge_s*)x, p);
  case zx_ac_SharedSecretChallengeResponse_ELEM:
    return zx_ENC_WO_ac_SharedSecretChallengeResponse(c, (struct zx_ac_SharedSecretChallengeResponse_s*)x, p);
  case zx_ac_SharedSecretDynamicPlaintext_ELEM:
    return zx_ENC_WO_ac_SharedSecretDynamicPlaintext(c, (struct zx_ac_SharedSecretDynamicPlaintext_s*)x, p);
  case zx_ac_IPAddress_ELEM:
    return zx_ENC_WO_ac_IPAddress(c, (struct zx_ac_IPAddress_s*)x, p);
  case zx_ac_AsymmetricDecryption_ELEM:
    return zx_ENC_WO_ac_AsymmetricDecryption(c, (struct zx_ac_AsymmetricDecryption_s*)x, p);
  case zx_ac_AsymmetricKeyAgreement_ELEM:
    return zx_ENC_WO_ac_AsymmetricKeyAgreement(c, (struct zx_ac_AsymmetricKeyAgreement_s*)x, p);
  case zx_ac_HTTP_ELEM:
    return zx_ENC_WO_ac_HTTP(c, (struct zx_ac_HTTP_s*)x, p);
  case zx_ac_SSL_ELEM:
    return zx_ENC_WO_ac_SSL(c, (struct zx_ac_SSL_s*)x, p);
  case zx_ac_MobileNetworkNoEncryption_ELEM:
    return zx_ENC_WO_ac_MobileNetworkNoEncryption(c, (struct zx_ac_MobileNetworkNoEncryption_s*)x, p);
  case zx_ac_MobileNetworkRadioEncryption_ELEM:
    return zx_ENC_WO_ac_MobileNetworkRadioEncryption(c, (struct zx_ac_MobileNetworkRadioEncryption_s*)x, p);
  case zx_ac_MobileNetworkEndToEndEncryption_ELEM:
    return zx_ENC_WO_ac_MobileNetworkEndToEndEncryption(c, (struct zx_ac_MobileNetworkEndToEndEncryption_s*)x, p);
  case zx_ac_WTLS_ELEM:
    return zx_ENC_WO_ac_WTLS(c, (struct zx_ac_WTLS_s*)x, p);
  case zx_ac_IPSec_ELEM:
    return zx_ENC_WO_ac_IPSec(c, (struct zx_ac_IPSec_s*)x, p);
  case zx_ac_GoverningAgreementRef_ELEM:
    return zx_ENC_WO_ac_GoverningAgreementRef(c, (struct zx_ac_GoverningAgreementRef_s*)x, p);
  case zx_ac_PhysicalVerification_ELEM:
    return zx_ENC_WO_ac_PhysicalVerification(c, (struct zx_ac_PhysicalVerification_s*)x, p);
  case zx_ac_WrittenConsent_ELEM:
    return zx_ENC_WO_ac_WrittenConsent(c, (struct zx_ac_WrittenConsent_s*)x, p);
  case zx_ac_ActivationPin_ELEM:
    return zx_ENC_WO_ac_ActivationPin(c, (struct zx_ac_ActivationPin_s*)x, p);
  case zx_ac_SecurityAudit_ELEM:
    return zx_ENC_WO_ac_SecurityAudit(c, (struct zx_ac_SecurityAudit_s*)x, p);
  case zx_ac_DeactivationCallCenter_ELEM:
    return zx_ENC_WO_ac_DeactivationCallCenter(c, (struct zx_ac_DeactivationCallCenter_s*)x, p);
  case zx_ac_Token_ELEM:
    return zx_ENC_WO_ac_Token(c, (struct zx_ac_Token_s*)x, p);
  case zx_ac_Smartcard_ELEM:
    return zx_ENC_WO_ac_Smartcard(c, (struct zx_ac_Smartcard_s*)x, p);
  case zx_ac_KeyActivation_ELEM:
    return zx_ENC_WO_ac_KeyActivation(c, (struct zx_ac_KeyActivation_s*)x, p);
  case zx_ac_KeyStorage_ELEM:
    return zx_ENC_WO_ac_KeyStorage(c, (struct zx_ac_KeyStorage_s*)x, p);
  case zx_ac_KeySharing_ELEM:
    return zx_ENC_WO_ac_KeySharing(c, (struct zx_ac_KeySharing_s*)x, p);
  case zx_ac_SwitchAudit_ELEM:
    return zx_ENC_WO_ac_SwitchAudit(c, (struct zx_ac_SwitchAudit_s*)x, p);
  case zx_ac_PrivateKeyProtection_ELEM:
    return zx_ENC_WO_ac_PrivateKeyProtection(c, (struct zx_ac_PrivateKeyProtection_s*)x, p);
  case zx_ac_SecretKeyProtection_ELEM:
    return zx_ENC_WO_ac_SecretKeyProtection(c, (struct zx_ac_SecretKeyProtection_s*)x, p);
  case zx_ac_TimeSyncToken_ELEM:
    return zx_ENC_WO_ac_TimeSyncToken(c, (struct zx_ac_TimeSyncToken_s*)x, p);
  case zx_as_Transform_ELEM:
    return zx_ENC_WO_as_Transform(c, (struct zx_as_Transform_s*)x, p);
  case zx_as_Data_ELEM:
    return zx_ENC_WO_simple_elem(c, (struct zx_elem_s*)x, p, "Data", sizeof("Data")-1);
  case zx_sp_RequestedAuthnContext_ELEM:
    return zx_ENC_WO_sp_RequestedAuthnContext(c, (struct zx_sp_RequestedAuthnContext_s*)x, p);
  case zx_as_Extensions_ELEM:
    return zx_ENC_WO_as_Extensions(c, (struct zx_as_Extensions_s*)x, p);
  case zx_lu_Status_ELEM:
    return zx_ENC_WO_lu_Status(c, (struct zx_lu_Status_s*)x, p);
  case zx_as_PasswordTransforms_ELEM:
    return zx_ENC_WO_as_PasswordTransforms(c, (struct zx_as_PasswordTransforms_s*)x, p);
  case zx_a_EndpointReference_ELEM:
    return zx_ENC_WO_a_EndpointReference(c, (struct zx_a_EndpointReference_s*)x, p);
  case zx_as_Parameter_ELEM:
    return zx_ENC_WO_as_Parameter(c, (struct zx_as_Parameter_s*)x, p);
  case zx_b_SecurityMechID_ELEM:
    return zx_ENC_WO_simple_elem(c, (struct zx_elem_s*)x, p, "SecurityMechID", sizeof("SecurityMechID")-1);
  case zx_sa_Assertion_ELEM:
    return zx_ENC_WO_sa_Assertion(c, (struct zx_sa_Assertion_s*)x, p);
  case zx_sa_EncryptedAssertion_ELEM:
    return zx_ENC_WO_sa_EncryptedAssertion(c, (struct zx_sa_EncryptedAssertion_s*)x, p);
  case zx_sa11_Assertion_ELEM:
    return zx_ENC_WO_sa11_Assertion(c, (struct zx_sa11_Assertion_s*)x, p);
  case zx_ff12_Assertion_ELEM:
    return zx_ENC_WO_ff12_Assertion(c, (struct zx_ff12_Assertion_s*)x, p);
  case zx_xa_Obligation_ELEM:
    return zx_ENC_WO_xa_Obligation(c, (struct zx_xa_Obligation_s*)x, p);
  case zx_tas3sol_Dict_ELEM:
    return zx_ENC_WO_tas3sol_Dict(c, (struct zx_tas3sol_Dict_s*)x, p);
  case zx_b_InteractionService_ELEM:
    return zx_ENC_WO_b_InteractionService(c, (struct zx_b_InteractionService_s*)x, p);
  case zx_cb_ResourceID_ELEM:
    return zx_ENC_WO_cb_ResourceID(c, (struct zx_cb_ResourceID_s*)x, p);
  case zx_cb_EncryptedResourceID_ELEM:
    return zx_ENC_WO_cb_EncryptedResourceID(c, (struct zx_cb_EncryptedResourceID_s*)x, p);
  case zx_cb_Subscription_ELEM:
    return zx_ENC_WO_cb_Subscription(c, (struct zx_cb_Subscription_s*)x, p);
  case zx_cb_CreateItem_ELEM:
    return zx_ENC_WO_cb_CreateItem(c, (struct zx_cb_CreateItem_s*)x, p);
  case zx_cb_ItemSelection_ELEM:
    return zx_ENC_WO_cb_ItemSelection(c, (struct zx_cb_ItemSelection_s*)x, p);
  case zx_cb_Extension_ELEM:
    return zx_ENC_WO_cb_Extension(c, (struct zx_cb_Extension_s*)x, p);
  case zx_cb_NewData_ELEM:
    return zx_ENC_WO_cb_NewData(c, (struct zx_cb_NewData_s*)x, p);
  case zx_cb_Status_ELEM:
    return zx_ENC_WO_cb_Status(c, (struct zx_cb_Status_s*)x, p);
  case zx_cb_ItemData_ELEM:
    return zx_ENC_WO_cb_ItemData(c, (struct zx_cb_ItemData_s*)x, p);
  case zx_cb_Card_ELEM:
    return zx_ENC_WO_simple_elem(c, (struct zx_elem_s*)x, p, "Card", sizeof("Card")-1);
  case zx_cb_DeleteItem_ELEM:
    return zx_ENC_WO_cb_DeleteItem(c, (struct zx_cb_DeleteItem_s*)x, p);
  case zx_cb_Select_ELEM:
    return zx_ENC_WO_simple_elem(c, (struct zx_elem_s*)x, p, "Select", sizeof("Select")-1);
  case zx_xenc_EncryptedData_ELEM:
    return zx_ENC_WO_xenc_EncryptedData(c, (struct zx_xenc_EncryptedData_s*)x, p);
  case zx_xenc_EncryptedKey_ELEM:
    return zx_ENC_WO_xenc_EncryptedKey(c, (struct zx_xenc_EncryptedKey_s*)x, p);
  case zx_cb_Modification_ELEM:
    return zx_ENC_WO_cb_Modification(c, (struct zx_cb_Modification_s*)x, p);
  case zx_cb_Notification_ELEM:
    return zx_ENC_WO_cb_Notification(c, (struct zx_cb_Notification_s*)x, p);
  case zx_cb_SecurityMechID_ELEM:
    return zx_ENC_WO_simple_elem(c, (struct zx_elem_s*)x, p, "SecurityMechID", sizeof("SecurityMechID")-1);
  case zx_cb_Credential_ELEM:
    return zx_ENC_WO_cb_Credential(c, (struct zx_cb_Credential_s*)x, p);
  case zx_cb_Endpoint_ELEM:
    return zx_ENC_WO_simple_elem(c, (struct zx_elem_s*)x, p, "Endpoint", sizeof("Endpoint")-1);
  case zx_cb_QueryItem_ELEM:
    return zx_ENC_WO_cb_QueryItem(c, (struct zx_cb_QueryItem_s*)x, p);
  case zx_cb_Data_ELEM:
    return zx_ENC_WO_cb_Data(c, (struct zx_cb_Data_s*)x, p);
  case zx_cdm_CARDID_ELEM:
    return zx_ENC_WO_simple_elem(c, (struct zx_elem_s*)x, p, "CARDID", sizeof("CARDID")-1);
  case zx_cb_UsageType_ELEM:
    return zx_ENC_WO_cb_UsageType(c, (struct zx_cb_UsageType_s*)x, p);
  case zx_cb_RefItem_ELEM:
    return zx_ENC_WO_cb_RefItem(c, (struct zx_cb_RefItem_s*)x, p);
  case zx_cb_NotifyTo_ELEM:
    return zx_ENC_WO_cb_NotifyTo(c, (struct zx_cb_NotifyTo_s*)x, p);
  case zx_cb_NotifyAdminTo_ELEM:
    return zx_ENC_WO_cb_NotifyAdminTo(c, (struct zx_cb_NotifyAdminTo_s*)x, p);
  case zx_cb_Aggregation_ELEM:
    return zx_ENC_WO_simple_elem(c, (struct zx_elem_s*)x, p, "Aggregation", sizeof("Aggregation")-1);
  case zx_cb_Trigger_ELEM:
    return zx_ENC_WO_simple_elem(c, (struct zx_elem_s*)x, p, "Trigger", sizeof("Trigger")-1);
  case zx_cdm_HOME_ELEM:
    return zx_ENC_WO_simple_elem(c, (struct zx_elem_s*)x, p, "HOME", sizeof("HOME")-1);
  case zx_cdm_WORK_ELEM:
    return zx_ENC_WO_simple_elem(c, (struct zx_elem_s*)x, p, "WORK", sizeof("WORK")-1);
  case zx_cdm_POSTAL_ELEM:
    return zx_ENC_WO_simple_elem(c, (struct zx_elem_s*)x, p, "POSTAL", sizeof("POSTAL")-1);
  case zx_cdm_PARCEL_ELEM:
    return zx_ENC_WO_simple_elem(c, (struct zx_elem_s*)x, p, "PARCEL", sizeof("PARCEL")-1);
  case zx_cdm_DOM_ELEM:
    return zx_ENC_WO_simple_elem(c, (struct zx_elem_s*)x, p, "DOM", sizeof("DOM")-1);
  case zx_cdm_INTL_ELEM:
    return zx_ENC_WO_simple_elem(c, (struct zx_elem_s*)x, p, "INTL", sizeof("INTL")-1);
  case zx_cdm_PREF_ELEM:
    return zx_ENC_WO_simple_elem(c, (struct zx_elem_s*)x, p, "PREF", sizeof("PREF")-1);
  case zx_cdm_POBOX_ELEM:
    return zx_ENC_WO_cdm_POBOX(c, (struct zx_cdm_POBOX_s*)x, p);
  case zx_cdm_EXTADR_ELEM:
    return zx_ENC_WO_cdm_EXTADR(c, (struct zx_cdm_EXTADR_s*)x, p);
  case zx_cdm_STREET_ELEM:
    return zx_ENC_WO_cdm_STREET(c, (struct zx_cdm_STREET_s*)x, p);
  case zx_cdm_LOCALITY_ELEM:
    return zx_ENC_WO_cdm_LOCALITY(c, (struct zx_cdm_LOCALITY_s*)x, p);
  case zx_cdm_REGION_ELEM:
    return zx_ENC_WO_cdm_REGION(c, (struct zx_cdm_REGION_s*)x, p);
  case zx_cdm_PCODE_ELEM:
    return zx_ENC_WO_cdm_PCODE(c, (struct zx_cdm_PCODE_s*)x, p);
  case zx_cdm_CTRY_ELEM:
    return zx_ENC_WO_cdm_CTRY(c, (struct zx_cdm_CTRY_s*)x, p);
  case zx_cdm_vCard_ELEM:
    return zx_ENC_WO_cdm_vCard(c, (struct zx_cdm_vCard_s*)x, p);
  case zx_cdm_EXTVAL_ELEM:
    return zx_ENC_WO_cdm_EXTVAL(c, (struct zx_cdm_EXTVAL_s*)x, p);
  case zx_cdm_URI_ELEM:
    return zx_ENC_WO_cdm_URI(c, (struct zx_cdm_URI_s*)x, p);
  case zx_cdm_KEYWORD_ELEM:
    return zx_ENC_WO_cdm_KEYWORD(c, (struct zx_cdm_KEYWORD_s*)x, p);
  case zx_cdm_PUBLIC_ELEM:
    return zx_ENC_WO_simple_elem(c, (struct zx_elem_s*)x, p, "PUBLIC", sizeof("PUBLIC")-1);
  case zx_cdm_PRIVATE_ELEM:
    return zx_ENC_WO_simple_elem(c, (struct zx_elem_s*)x, p, "PRIVATE", sizeof("PRIVATE")-1);
  case zx_cdm_CONFIDENTIAL_ELEM:
    return zx_ENC_WO_simple_elem(c, (struct zx_elem_s*)x, p, "CONFIDENTIAL", sizeof("CONFIDENTIAL")-1);
  case zx_cdm_INTERNET_ELEM:
    return zx_ENC_WO_simple_elem(c, (struct zx_elem_s*)x, p, "INTERNET", sizeof("INTERNET")-1);
  case zx_cdm_X400_ELEM:
    return zx_ENC_WO_simple_elem(c, (struct zx_elem_s*)x, p, "X400", sizeof("X400")-1);
  case zx_cdm_USERID_ELEM:
    return zx_ENC_WO_cdm_USERID(c, (struct zx_cdm_USERID_s*)x, p);
  case zx_cdm_LAT_ELEM:
    return zx_ENC_WO_cdm_LAT(c, (struct zx_cdm_LAT_s*)x, p);
  case zx_cdm_LON_ELEM:
    return zx_ENC_WO_cdm_LON(c, (struct zx_cdm_LON_s*)x, p);
  case zx_cdm_TYPE_ELEM:
    return zx_ENC_WO_cdm_TYPE(c, (struct zx_cdm_TYPE_s*)x, p);
  case zx_cdm_CRED_ELEM:
    return zx_ENC_WO_cdm_CRED(c, (struct zx_cdm_CRED_s*)x, p);
  case zx_cdm_LINE_ELEM:
    return zx_ENC_WO_cdm_LINE(c, (struct zx_cdm_LINE_s*)x, p);
  case zx_cdm_BINVAL_ELEM:
    return zx_ENC_WO_cdm_BINVAL(c, (struct zx_cdm_BINVAL_s*)x, p);
  case zx_cdm_FAMILY_ELEM:
    return zx_ENC_WO_cdm_FAMILY(c, (struct zx_cdm_FAMILY_s*)x, p);
  case zx_cdm_GIVEN_ELEM:
    return zx_ENC_WO_cdm_GIVEN(c, (struct zx_cdm_GIVEN_s*)x, p);
  case zx_cdm_MIDDLE_ELEM:
    return zx_ENC_WO_cdm_MIDDLE(c, (struct zx_cdm_MIDDLE_s*)x, p);
  case zx_cdm_PREFIX_ELEM:
    return zx_ENC_WO_cdm_PREFIX(c, (struct zx_cdm_PREFIX_s*)x, p);
  case zx_cdm_SUFFIX_ELEM:
    return zx_ENC_WO_cdm_SUFFIX(c, (struct zx_cdm_SUFFIX_s*)x, p);
  case zx_cdm_ORGNAME_ELEM:
    return zx_ENC_WO_cdm_ORGNAME(c, (struct zx_cdm_ORGNAME_s*)x, p);
  case zx_cdm_ORGUNIT_ELEM:
    return zx_ENC_WO_cdm_ORGUNIT(c, (struct zx_cdm_ORGUNIT_s*)x, p);
  case zx_cdm_PHONETIC_ELEM:
    return zx_ENC_WO_cdm_PHONETIC(c, (struct zx_cdm_PHONETIC_s*)x, p);
  case zx_cdm_VOICE_ELEM:
    return zx_ENC_WO_simple_elem(c, (struct zx_elem_s*)x, p, "VOICE", sizeof("VOICE")-1);
  case zx_cdm_FAX_ELEM:
    return zx_ENC_WO_simple_elem(c, (struct zx_elem_s*)x, p, "FAX", sizeof("FAX")-1);
  case zx_cdm_PAGER_ELEM:
    return zx_ENC_WO_simple_elem(c, (struct zx_elem_s*)x, p, "PAGER", sizeof("PAGER")-1);
  case zx_cdm_MSG_ELEM:
    return zx_ENC_WO_simple_elem(c, (struct zx_elem_s*)x, p, "MSG", sizeof("MSG")-1);
  case zx_cdm_CELL_ELEM:
    return zx_ENC_WO_simple_elem(c, (struct zx_elem_s*)x, p, "CELL", sizeof("CELL")-1);
  case zx_cdm_VIDEO_ELEM:
    return zx_ENC_WO_simple_elem(c, (struct zx_elem_s*)x, p, "VIDEO", sizeof("VIDEO")-1);
  case zx_cdm_BBS_ELEM:
    return zx_ENC_WO_simple_elem(c, (struct zx_elem_s*)x, p, "BBS", sizeof("BBS")-1);
  case zx_cdm_MODEM_ELEM:
    return zx_ENC_WO_simple_elem(c, (struct zx_elem_s*)x, p, "MODEM", sizeof("MODEM")-1);
  case zx_cdm_ISDN_ELEM:
    return zx_ENC_WO_simple_elem(c, (struct zx_elem_s*)x, p, "ISDN", sizeof("ISDN")-1);
  case zx_cdm_PCS_ELEM:
    return zx_ENC_WO_simple_elem(c, (struct zx_elem_s*)x, p, "PCS", sizeof("PCS")-1);
  case zx_cdm_NUMBER_ELEM:
    return zx_ENC_WO_cdm_NUMBER(c, (struct zx_cdm_NUMBER_s*)x, p);
  case zx_cdm_VERSION_ELEM:
    return zx_ENC_WO_cdm_VERSION(c, (struct zx_cdm_VERSION_s*)x, p);
  case zx_cdm_DISTRIBUTIONLIST_ELEM:
    return zx_ENC_WO_simple_elem(c, (struct zx_elem_s*)x, p, "DISTRIBUTIONLIST", sizeof("DISTRIBUTIONLIST")-1);
  case zx_cdm_SELF_ELEM:
    return zx_ENC_WO_simple_elem(c, (struct zx_elem_s*)x, p, "SELF", sizeof("SELF")-1);
  case zx_cdm_FAVORITE_ELEM:
    return zx_ENC_WO_simple_elem(c, (struct zx_elem_s*)x, p, "FAVORITE", sizeof("FAVORITE")-1);
  case zx_cdm_FN_ELEM:
    return zx_ENC_WO_cdm_FN(c, (struct zx_cdm_FN_s*)x, p);
  case zx_cdm_N_ELEM:
    return zx_ENC_WO_cdm_N(c, (struct zx_cdm_N_s*)x, p);
  case zx_cdm_LISTMEMBER_ELEM:
    return zx_ENC_WO_cdm_LISTMEMBER(c, (struct zx_cdm_LISTMEMBER_s*)x, p);
  case zx_cdm_NICKNAME_ELEM:
    return zx_ENC_WO_cdm_NICKNAME(c, (struct zx_cdm_NICKNAME_s*)x, p);
  case zx_cdm_PHOTO_ELEM:
    return zx_ENC_WO_cdm_PHOTO(c, (struct zx_cdm_PHOTO_s*)x, p);
  case zx_cdm_BDAY_ELEM:
    return zx_ENC_WO_cdm_BDAY(c, (struct zx_cdm_BDAY_s*)x, p);
  case zx_cdm_ADR_ELEM:
    return zx_ENC_WO_cdm_ADR(c, (struct zx_cdm_ADR_s*)x, p);
  case zx_cdm_LABEL_ELEM:
    return zx_ENC_WO_cdm_LABEL(c, (struct zx_cdm_LABEL_s*)x, p);
  case zx_cdm_TEL_ELEM:
    return zx_ENC_WO_cdm_TEL(c, (struct zx_cdm_TEL_s*)x, p);
  case zx_cdm_EMAIL_ELEM:
    return zx_ENC_WO_cdm_EMAIL(c, (struct zx_cdm_EMAIL_s*)x, p);
  case zx_cdm_JABBERID_ELEM:
    return zx_ENC_WO_cdm_JABBERID(c, (struct zx_cdm_JABBERID_s*)x, p);
  case zx_cdm_MAILER_ELEM:
    return zx_ENC_WO_cdm_MAILER(c, (struct zx_cdm_MAILER_s*)x, p);
  case zx_cdm_TZ_ELEM:
    return zx_ENC_WO_cdm_TZ(c, (struct zx_cdm_TZ_s*)x, p);
  case zx_cdm_GEO_ELEM:
    return zx_ENC_WO_cdm_GEO(c, (struct zx_cdm_GEO_s*)x, p);
  case zx_cdm_TITLE_ELEM:
    return zx_ENC_WO_cdm_TITLE(c, (struct zx_cdm_TITLE_s*)x, p);
  case zx_cdm_ROLE_ELEM:
    return zx_ENC_WO_cdm_ROLE(c, (struct zx_cdm_ROLE_s*)x, p);
  case zx_cdm_LOGO_ELEM:
    return zx_ENC_WO_cdm_LOGO(c, (struct zx_cdm_LOGO_s*)x, p);
  case zx_cdm_AGENT_ELEM:
    return zx_ENC_WO_cdm_AGENT(c, (struct zx_cdm_AGENT_s*)x, p);
  case zx_cdm_ORG_ELEM:
    return zx_ENC_WO_cdm_ORG(c, (struct zx_cdm_ORG_s*)x, p);
  case zx_cdm_CATEGORIES_ELEM:
    return zx_ENC_WO_cdm_CATEGORIES(c, (struct zx_cdm_CATEGORIES_s*)x, p);
  case zx_cdm_NOTE_ELEM:
    return zx_ENC_WO_cdm_NOTE(c, (struct zx_cdm_NOTE_s*)x, p);
  case zx_cdm_PRODID_ELEM:
    return zx_ENC_WO_cdm_PRODID(c, (struct zx_cdm_PRODID_s*)x, p);
  case zx_cdm_REV_ELEM:
    return zx_ENC_WO_cdm_REV(c, (struct zx_cdm_REV_s*)x, p);
  case zx_cdm_SORT_STRING_ELEM:
    return zx_ENC_WO_cdm_SORT_STRING(c, (struct zx_cdm_SORT_STRING_s*)x, p);
  case zx_cdm_SOUND_ELEM:
    return zx_ENC_WO_cdm_SOUND(c, (struct zx_cdm_SOUND_s*)x, p);
  case zx_cdm_UID_ELEM:
    return zx_ENC_WO_cdm_UID(c, (struct zx_cdm_UID_s*)x, p);
  case zx_cdm_URL_ELEM:
    return zx_ENC_WO_cdm_URL(c, (struct zx_cdm_URL_s*)x, p);
  case zx_cdm_CLASS_ELEM:
    return zx_ENC_WO_cdm_CLASS(c, (struct zx_cdm_CLASS_s*)x, p);
  case zx_cdm_KEY_ELEM:
    return zx_ENC_WO_cdm_KEY(c, (struct zx_cdm_KEY_s*)x, p);
  case zx_cdm_DESC_ELEM:
    return zx_ENC_WO_cdm_DESC(c, (struct zx_cdm_DESC_s*)x, p);
  case zx_cdm_PHYSICALACCESS_ELEM:
    return zx_ENC_WO_cdm_PHYSICALACCESS(c, (struct zx_cdm_PHYSICALACCESS_s*)x, p);
  case zx_cdm_CALURI_ELEM:
    return zx_ENC_WO_cdm_CALURI(c, (struct zx_cdm_CALURI_s*)x, p);
  case zx_cdm_CAPURI_ELEM:
    return zx_ENC_WO_cdm_CAPURI(c, (struct zx_cdm_CAPURI_s*)x, p);
  case zx_cdm_CALADRURI_ELEM:
    return zx_ENC_WO_cdm_CALADRURI(c, (struct zx_cdm_CALADRURI_s*)x, p);
  case zx_cdm_FBURL_ELEM:
    return zx_ENC_WO_cdm_FBURL(c, (struct zx_cdm_FBURL_s*)x, p);
  case zx_lu_Extension_ELEM:
    return zx_ENC_WO_lu_Extension(c, (struct zx_lu_Extension_s*)x, p);
  case zx_dap_Subscription_ELEM:
    return zx_ENC_WO_dap_Subscription(c, (struct zx_dap_Subscription_s*)x, p);
  case zx_dap_CreateItem_ELEM:
    return zx_ENC_WO_dap_CreateItem(c, (struct zx_dap_CreateItem_s*)x, p);
  case zx_dap_ResultQuery_ELEM:
    return zx_ENC_WO_dap_ResultQuery(c, (struct zx_dap_ResultQuery_s*)x, p);
  case zx_dap_NewData_ELEM:
    return zx_ENC_WO_dap_NewData(c, (struct zx_dap_NewData_s*)x, p);
  case zx_dap_ItemData_ELEM:
    return zx_ENC_WO_dap_ItemData(c, (struct zx_dap_ItemData_s*)x, p);
  case zx_dap_LDIF_ELEM:
    return zx_ENC_WO_dap_LDIF(c, (struct zx_dap_LDIF_s*)x, p);
  case zx_dap_DeleteItem_ELEM:
    return zx_ENC_WO_dap_DeleteItem(c, (struct zx_dap_DeleteItem_s*)x, p);
  case zx_dap_Select_ELEM:
    return zx_ENC_WO_dap_Select(c, (struct zx_dap_Select_s*)x, p);
  case zx_dap_ModifyItem_ELEM:
    return zx_ENC_WO_dap_ModifyItem(c, (struct zx_dap_ModifyItem_s*)x, p);
  case zx_lu_TestResult_ELEM:
    return zx_ENC_WO_lu_TestResult(c, (struct zx_lu_TestResult_s*)x, p);
  case zx_dap_Notification_ELEM:
    return zx_ENC_WO_dap_Notification(c, (struct zx_dap_Notification_s*)x, p);
  case zx_dap_TestItem_ELEM:
    return zx_ENC_WO_dap_TestItem(c, (struct zx_dap_TestItem_s*)x, p);
  case zx_dap_QueryItem_ELEM:
    return zx_ENC_WO_dap_QueryItem(c, (struct zx_dap_QueryItem_s*)x, p);
  case zx_dst_ChangeFormat_ELEM:
    return zx_ENC_WO_simple_elem(c, (struct zx_elem_s*)x, p, "ChangeFormat", sizeof("ChangeFormat")-1);
  case zx_dap_Sort_ELEM:
    return zx_ENC_WO_simple_elem(c, (struct zx_elem_s*)x, p, "Sort", sizeof("Sort")-1);
  case zx_dst_TestResult_ELEM:
    return zx_ENC_WO_dst_TestResult(c, (struct zx_dst_TestResult_s*)x, p);
  case zx_dap_Data_ELEM:
    return zx_ENC_WO_dap_Data(c, (struct zx_dap_Data_s*)x, p);
  case zx_dap_dn_ELEM:
    return zx_ENC_WO_simple_elem(c, (struct zx_elem_s*)x, p, "dn", sizeof("dn")-1);
  case zx_dap_filter_ELEM:
    return zx_ENC_WO_simple_elem(c, (struct zx_elem_s*)x, p, "filter", sizeof("filter")-1);
  case zx_subs_RefItem_ELEM:
    return zx_ENC_WO_subs_RefItem(c, (struct zx_subs_RefItem_s*)x, p);
  case zx_dap_Aggregation_ELEM:
    return zx_ENC_WO_simple_elem(c, (struct zx_elem_s*)x, p, "Aggregation", sizeof("Aggregation")-1);
  case zx_dap_Trigger_ELEM:
    return zx_ENC_WO_simple_elem(c, (struct zx_elem_s*)x, p, "Trigger", sizeof("Trigger")-1);
  case zx_dap_TestOp_ELEM:
    return zx_ENC_WO_dap_TestOp(c, (struct zx_dap_TestOp_s*)x, p);
  case zx_demomed_ObjectID_ELEM:
    return zx_ENC_WO_simple_elem(c, (struct zx_elem_s*)x, p, "ObjectID", sizeof("ObjectID")-1);
  case zx_demomed_Count_ELEM:
    return zx_ENC_WO_simple_elem(c, (struct zx_elem_s*)x, p, "Count", sizeof("Count")-1);
  case zx_demomed_ObjectSearchParm_ELEM:
    return zx_ENC_WO_demomed_ObjectSearchParm(c, (struct zx_demomed_ObjectSearchParm_s*)x, p);
  case zx_demomed_ObjectInfo_ELEM:
    return zx_ENC_WO_demomed_ObjectInfo(c, (struct zx_demomed_ObjectInfo_s*)x, p);
  case zx_demomed_ObjectData_ELEM:
    return zx_ENC_WO_demomed_ObjectData(c, (struct zx_demomed_ObjectData_s*)x, p);
  case zx_demomed_Dir_ELEM:
    return zx_ENC_WO_simple_elem(c, (struct zx_elem_s*)x, p, "Dir", sizeof("Dir")-1);
  case zx_demomed_Name_ELEM:
    return zx_ENC_WO_simple_elem(c, (struct zx_elem_s*)x, p, "Name", sizeof("Name")-1);
  case zx_demomed_Type_ELEM:
    return zx_ENC_WO_simple_elem(c, (struct zx_elem_s*)x, p, "Type", sizeof("Type")-1);
  case zx_demomed_Created_ELEM:
    return zx_ENC_WO_simple_elem(c, (struct zx_elem_s*)x, p, "Created", sizeof("Created")-1);
  case zx_demomed_Comment_ELEM:
    return zx_ENC_WO_simple_elem(c, (struct zx_elem_s*)x, p, "Comment", sizeof("Comment")-1);
  case zx_demomed_objectID_ELEM:
    return zx_ENC_WO_simple_elem(c, (struct zx_elem_s*)x, p, "objectID", sizeof("objectID")-1);
  case zx_demomed_Object_ELEM:
    return zx_ENC_WO_demomed_Object(c, (struct zx_demomed_Object_s*)x, p);
  case zx_demomed_ObjectStoreInfo_ELEM:
    return zx_ENC_WO_demomed_ObjectStoreInfo(c, (struct zx_demomed_ObjectStoreInfo_s*)x, p);
  case zx_di_Address_ELEM:
    return zx_ENC_WO_simple_elem(c, (struct zx_elem_s*)x, p, "Address", sizeof("Address")-1);
  case zx_di_SecurityMechID_ELEM:
    return zx_ENC_WO_simple_elem(c, (struct zx_elem_s*)x, p, "SecurityMechID", sizeof("SecurityMechID")-1);
  case zx_di_Action_ELEM:
    return zx_ENC_WO_simple_elem(c, (struct zx_elem_s*)x, p, "Action", sizeof("Action")-1);
  case zx_md_KeyDescriptor_ELEM:
    return zx_ENC_WO_md_KeyDescriptor(c, (struct zx_md_KeyDescriptor_s*)x, p);
  case zx_di_Option_ELEM:
    return zx_ENC_WO_simple_elem(c, (struct zx_elem_s*)x, p, "Option", sizeof("Option")-1);
  case zx_di_RequestedService_ELEM:
    return zx_ENC_WO_di_RequestedService(c, (struct zx_di_RequestedService_s*)x, p);
  case zx_di_Options_ELEM:
    return zx_ENC_WO_di_Options(c, (struct zx_di_Options_s*)x, p);
  case zx_di_Framework_ELEM:
    return zx_ENC_WO_di_Framework(c, (struct zx_di_Framework_s*)x, p);
  case zx_sec_Token_ELEM:
    return zx_ENC_WO_sec_Token(c, (struct zx_sec_Token_s*)x, p);
  case zx_di_EndpointContext_ELEM:
    return zx_ENC_WO_di_EndpointContext(c, (struct zx_di_EndpointContext_s*)x, p);
  case zx_di_ServiceContext_ELEM:
    return zx_ENC_WO_di_ServiceContext(c, (struct zx_di_ServiceContext_s*)x, p);
  case zx_di_SvcMDID_ELEM:
    return zx_ENC_WO_simple_elem(c, (struct zx_elem_s*)x, p, "SvcMDID", sizeof("SvcMDID")-1);
  case zx_di_SvcMD_ELEM:
    return zx_ENC_WO_di_SvcMD(c, (struct zx_di_SvcMD_s*)x, p);
  case zx_di_Keys_ELEM:
    return zx_ENC_WO_di_Keys(c, (struct zx_di_Keys_s*)x, p);
  case zx_di12_SecurityMechID_ELEM:
    return zx_ENC_WO_simple_elem(c, (struct zx_elem_s*)x, p, "SecurityMechID", sizeof("SecurityMechID")-1);
  case zx_di12_CredentialRef_ELEM:
    return zx_ENC_WO_simple_elem(c, (struct zx_elem_s*)x, p, "CredentialRef", sizeof("CredentialRef")-1);
  case zx_di12_WsdlURI_ELEM:
    return zx_ENC_WO_simple_elem(c, (struct zx_elem_s*)x, p, "WsdlURI", sizeof("WsdlURI")-1);
  case zx_di12_ServiceNameRef_ELEM:
    return zx_ENC_WO_simple_elem(c, (struct zx_elem_s*)x, p, "ServiceNameRef", sizeof("ServiceNameRef")-1);
  case zx_di12_Endpoint_ELEM:
    return zx_ENC_WO_simple_elem(c, (struct zx_elem_s*)x, p, "Endpoint", sizeof("Endpoint")-1);
  case zx_di12_SoapAction_ELEM:
    return zx_ENC_WO_simple_elem(c, (struct zx_elem_s*)x, p, "SoapAction", sizeof("SoapAction")-1);
  case zx_di12_ResourceOffering_ELEM:
    return zx_ENC_WO_di12_ResourceOffering(c, (struct zx_di12_ResourceOffering_s*)x, p);
  case zx_di12_ResourceID_ELEM:
    return zx_ENC_WO_di12_ResourceID(c, (struct zx_di12_ResourceID_s*)x, p);
  case zx_di12_EncryptedResourceID_ELEM:
    return zx_ENC_WO_di12_EncryptedResourceID(c, (struct zx_di12_EncryptedResourceID_s*)x, p);
  case zx_di12_InsertEntry_ELEM:
    return zx_ENC_WO_di12_InsertEntry(c, (struct zx_di12_InsertEntry_s*)x, p);
  case zx_di12_RemoveEntry_ELEM:
    return zx_ENC_WO_di12_RemoveEntry(c, (struct zx_di12_RemoveEntry_s*)x, p);
  case zx_di12_Status_ELEM:
    return zx_ENC_WO_di12_Status(c, (struct zx_di12_Status_s*)x, p);
  case zx_di12_Extension_ELEM:
    return zx_ENC_WO_di12_Extension(c, (struct zx_di12_Extension_s*)x, p);
  case zx_di12_Option_ELEM:
    return zx_ENC_WO_simple_elem(c, (struct zx_elem_s*)x, p, "Option", sizeof("Option")-1);
  case zx_di12_RequestedServiceType_ELEM:
    return zx_ENC_WO_di12_RequestedServiceType(c, (struct zx_di12_RequestedServiceType_s*)x, p);
  case zx_di12_Credentials_ELEM:
    return zx_ENC_WO_di12_Credentials(c, (struct zx_di12_Credentials_s*)x, p);
  case zx_di12_ServiceType_ELEM:
    return zx_ENC_WO_simple_elem(c, (struct zx_elem_s*)x, p, "ServiceType", sizeof("ServiceType")-1);
  case zx_di12_Options_ELEM:
    return zx_ENC_WO_di12_Options(c, (struct zx_di12_Options_s*)x, p);
  case zx_di12_ServiceInstance_ELEM:
    return zx_ENC_WO_di12_ServiceInstance(c, (struct zx_di12_ServiceInstance_s*)x, p);
  case zx_di12_Abstract_ELEM:
    return zx_ENC_WO_simple_elem(c, (struct zx_elem_s*)x, p, "Abstract", sizeof("Abstract")-1);
  case zx_di12_ProviderID_ELEM:
    return zx_ENC_WO_simple_elem(c, (struct zx_elem_s*)x, p, "ProviderID", sizeof("ProviderID")-1);
  case zx_di12_Description_ELEM:
    return zx_ENC_WO_di12_Description(c, (struct zx_di12_Description_s*)x, p);
  case zx_ds_P_ELEM:
    return zx_ENC_WO_simple_elem(c, (struct zx_elem_s*)x, p, "P", sizeof("P")-1);
  case zx_ds_Q_ELEM:
    return zx_ENC_WO_simple_elem(c, (struct zx_elem_s*)x, p, "Q", sizeof("Q")-1);
  case zx_ds_G_ELEM:
    return zx_ENC_WO_simple_elem(c, (struct zx_elem_s*)x, p, "G", sizeof("G")-1);
  case zx_ds_Y_ELEM:
    return zx_ENC_WO_simple_elem(c, (struct zx_elem_s*)x, p, "Y", sizeof("Y")-1);
  case zx_ds_J_ELEM:
    return zx_ENC_WO_simple_elem(c, (struct zx_elem_s*)x, p, "J", sizeof("J")-1);
  case zx_ds_Seed_ELEM:
    return zx_ENC_WO_simple_elem(c, (struct zx_elem_s*)x, p, "Seed", sizeof("Seed")-1);
  case zx_ds_PgenCounter_ELEM:
    return zx_ENC_WO_simple_elem(c, (struct zx_elem_s*)x, p, "PgenCounter", sizeof("PgenCounter")-1);
  case zx_ds_KeyName_ELEM:
    return zx_ENC_WO_simple_elem(c, (struct zx_elem_s*)x, p, "KeyName", sizeof("KeyName")-1);
  case zx_ds_KeyValue_ELEM:
    return zx_ENC_WO_ds_KeyValue(c, (struct zx_ds_KeyValue_s*)x, p);
  case zx_ds_RetrievalMethod_ELEM:
    return zx_ENC_WO_ds_RetrievalMethod(c, (struct zx_ds_RetrievalMethod_s*)x, p);
  case zx_ds_X509Data_ELEM:
    return zx_ENC_WO_ds_X509Data(c, (struct zx_ds_X509Data_s*)x, p);
  case zx_ds_PGPData_ELEM:
    return zx_ENC_WO_ds_PGPData(c, (struct zx_ds_PGPData_s*)x, p);
  case zx_ds_SPKIData_ELEM:
    return zx_ENC_WO_ds_SPKIData(c, (struct zx_ds_SPKIData_s*)x, p);
  case zx_ds_MgmtData_ELEM:
    return zx_ENC_WO_simple_elem(c, (struct zx_elem_s*)x, p, "MgmtData", sizeof("MgmtData")-1);
  case zx_ds_DSAKeyValue_ELEM:
    return zx_ENC_WO_ds_DSAKeyValue(c, (struct zx_ds_DSAKeyValue_s*)x, p);
  case zx_ds_RSAKeyValue_ELEM:
    return zx_ENC_WO_ds_RSAKeyValue(c, (struct zx_ds_RSAKeyValue_s*)x, p);
  case zx_ds_Reference_ELEM:
    return zx_ENC_WO_ds_Reference(c, (struct zx_ds_Reference_s*)x, p);
  case zx_ds_PGPKeyID_ELEM:
    return zx_ENC_WO_simple_elem(c, (struct zx_elem_s*)x, p, "PGPKeyID", sizeof("PGPKeyID")-1);
  case zx_ds_PGPKeyPacket_ELEM:
    return zx_ENC_WO_simple_elem(c, (struct zx_elem_s*)x, p, "PGPKeyPacket", sizeof("PGPKeyPacket")-1);
  case zx_ds_Modulus_ELEM:
    return zx_ENC_WO_simple_elem(c, (struct zx_elem_s*)x, p, "Modulus", sizeof("Modulus")-1);
  case zx_ds_Exponent_ELEM:
    return zx_ENC_WO_simple_elem(c, (struct zx_elem_s*)x, p, "Exponent", sizeof("Exponent")-1);
  case zx_ds_Transforms_ELEM:
    return zx_ENC_WO_ds_Transforms(c, (struct zx_ds_Transforms_s*)x, p);
  case zx_ds_DigestMethod_ELEM:
    return zx_ENC_WO_ds_DigestMethod(c, (struct zx_ds_DigestMethod_s*)x, p);
  case zx_ds_DigestValue_ELEM:
    return zx_ENC_WO_simple_elem(c, (struct zx_elem_s*)x, p, "DigestValue", sizeof("DigestValue")-1);
  case zx_ds_SPKISexp_ELEM:
    return zx_ENC_WO_simple_elem(c, (struct zx_elem_s*)x, p, "SPKISexp", sizeof("SPKISexp")-1);
  case zx_ds_SignedInfo_ELEM:
    return zx_ENC_WO_ds_SignedInfo(c, (struct zx_ds_SignedInfo_s*)x, p);
  case zx_ds_SignatureValue_ELEM:
    return zx_ENC_WO_ds_SignatureValue(c, (struct zx_ds_SignatureValue_s*)x, p);
  case zx_ds_KeyInfo_ELEM:
    return zx_ENC_WO_ds_KeyInfo(c, (struct zx_ds_KeyInfo_s*)x, p);
  case zx_ds_Object_ELEM:
    return zx_ENC_WO_ds_Object(c, (struct zx_ds_Object_s*)x, p);
  case zx_ds_HMACOutputLength_ELEM:
    return zx_ENC_WO_simple_elem(c, (struct zx_elem_s*)x, p, "HMACOutputLength", sizeof("HMACOutputLength")-1);
  case zx_ds_SignatureProperty_ELEM:
    return zx_ENC_WO_ds_SignatureProperty(c, (struct zx_ds_SignatureProperty_s*)x, p);
  case zx_ds_CanonicalizationMethod_ELEM:
    return zx_ENC_WO_ds_CanonicalizationMethod(c, (struct zx_ds_CanonicalizationMethod_s*)x, p);
  case zx_ds_SignatureMethod_ELEM:
    return zx_ENC_WO_ds_SignatureMethod(c, (struct zx_ds_SignatureMethod_s*)x, p);
  case zx_ds_XPath_ELEM:
    return zx_ENC_WO_simple_elem(c, (struct zx_elem_s*)x, p, "XPath", sizeof("XPath")-1);
  case zx_exca_InclusiveNamespaces_ELEM:
    return zx_ENC_WO_exca_InclusiveNamespaces(c, (struct zx_exca_InclusiveNamespaces_s*)x, p);
  case zx_ds_Transform_ELEM:
    return zx_ENC_WO_ds_Transform(c, (struct zx_ds_Transform_s*)x, p);
  case zx_ds_X509IssuerSerial_ELEM:
    return zx_ENC_WO_ds_X509IssuerSerial(c, (struct zx_ds_X509IssuerSerial_s*)x, p);
  case zx_ds_X509SKI_ELEM:
    return zx_ENC_WO_simple_elem(c, (struct zx_elem_s*)x, p, "X509SKI", sizeof("X509SKI")-1);
  case zx_ds_X509SubjectName_ELEM:
    return zx_ENC_WO_simple_elem(c, (struct zx_elem_s*)x, p, "X509SubjectName", sizeof("X509SubjectName")-1);
  case zx_ds_X509Certificate_ELEM:
    return zx_ENC_WO_simple_elem(c, (struct zx_elem_s*)x, p, "X509Certificate", sizeof("X509Certificate")-1);
  case zx_ds_X509CRL_ELEM:
    return zx_ENC_WO_simple_elem(c, (struct zx_elem_s*)x, p, "X509CRL", sizeof("X509CRL")-1);
  case zx_ds_X509IssuerName_ELEM:
    return zx_ENC_WO_simple_elem(c, (struct zx_elem_s*)x, p, "X509IssuerName", sizeof("X509IssuerName")-1);
  case zx_ds_X509SerialNumber_ELEM:
    return zx_ENC_WO_simple_elem(c, (struct zx_elem_s*)x, p, "X509SerialNumber", sizeof("X509SerialNumber")-1);
  case zx_sp_ArtifactResolve_ELEM:
    return zx_ENC_WO_sp_ArtifactResolve(c, (struct zx_sp_ArtifactResolve_s*)x, p);
  case zx_sp_ArtifactResponse_ELEM:
    return zx_ENC_WO_sp_ArtifactResponse(c, (struct zx_sp_ArtifactResponse_s*)x, p);
  case zx_sp_ManageNameIDRequest_ELEM:
    return zx_ENC_WO_sp_ManageNameIDRequest(c, (struct zx_sp_ManageNameIDRequest_s*)x, p);
  case zx_sp_ManageNameIDResponse_ELEM:
    return zx_ENC_WO_sp_ManageNameIDResponse(c, (struct zx_sp_ManageNameIDResponse_s*)x, p);
  case zx_sp_LogoutRequest_ELEM:
    return zx_ENC_WO_sp_LogoutRequest(c, (struct zx_sp_LogoutRequest_s*)x, p);
  case zx_sp_LogoutResponse_ELEM:
    return zx_ENC_WO_sp_LogoutResponse(c, (struct zx_sp_LogoutResponse_s*)x, p);
  case zx_sp_NameIDMappingRequest_ELEM:
    return zx_ENC_WO_sp_NameIDMappingRequest(c, (struct zx_sp_NameIDMappingRequest_s*)x, p);
  case zx_sp_NameIDMappingResponse_ELEM:
    return zx_ENC_WO_sp_NameIDMappingResponse(c, (struct zx_sp_NameIDMappingResponse_s*)x, p);
  case zx_sp_AttributeQuery_ELEM:
    return zx_ENC_WO_sp_AttributeQuery(c, (struct zx_sp_AttributeQuery_s*)x, p);
  case zx_sp_AuthnQuery_ELEM:
    return zx_ENC_WO_sp_AuthnQuery(c, (struct zx_sp_AuthnQuery_s*)x, p);
  case zx_sp_AuthzDecisionQuery_ELEM:
    return zx_ENC_WO_sp_AuthzDecisionQuery(c, (struct zx_sp_AuthzDecisionQuery_s*)x, p);
  case zx_sp_AssertionIDRequest_ELEM:
    return zx_ENC_WO_sp_AssertionIDRequest(c, (struct zx_sp_AssertionIDRequest_s*)x, p);
  case zx_sp_Response_ELEM:
    return zx_ENC_WO_sp_Response(c, (struct zx_sp_Response_s*)x, p);
  case zx_sp_AuthnRequest_ELEM:
    return zx_ENC_WO_sp_AuthnRequest(c, (struct zx_sp_AuthnRequest_s*)x, p);
  case zx_sp11_Request_ELEM:
    return zx_ENC_WO_sp11_Request(c, (struct zx_sp11_Request_s*)x, p);
  case zx_sp11_Response_ELEM:
    return zx_ENC_WO_sp11_Response(c, (struct zx_sp11_Response_s*)x, p);
  case zx_ff12_RegisterNameIdentifierRequest_ELEM:
    return zx_ENC_WO_ff12_RegisterNameIdentifierRequest(c, (struct zx_ff12_RegisterNameIdentifierRequest_s*)x, p);
  case zx_ff12_RegisterNameIdentifierResponse_ELEM:
    return zx_ENC_WO_ff12_RegisterNameIdentifierResponse(c, (struct zx_ff12_RegisterNameIdentifierResponse_s*)x, p);
  case zx_ff12_FederationTerminationNotification_ELEM:
    return zx_ENC_WO_ff12_FederationTerminationNotification(c, (struct zx_ff12_FederationTerminationNotification_s*)x, p);
  case zx_ff12_LogoutRequest_ELEM:
    return zx_ENC_WO_ff12_LogoutRequest(c, (struct zx_ff12_LogoutRequest_s*)x, p);
  case zx_ff12_LogoutResponse_ELEM:
    return zx_ENC_WO_ff12_LogoutResponse(c, (struct zx_ff12_LogoutResponse_s*)x, p);
  case zx_ff12_NameIdentifierMappingRequest_ELEM:
    return zx_ENC_WO_ff12_NameIdentifierMappingRequest(c, (struct zx_ff12_NameIdentifierMappingRequest_s*)x, p);
  case zx_ff12_NameIdentifierMappingResponse_ELEM:
    return zx_ENC_WO_ff12_NameIdentifierMappingResponse(c, (struct zx_ff12_NameIdentifierMappingResponse_s*)x, p);
  case zx_xasp_XACMLAuthzDecisionQuery_ELEM:
    return zx_ENC_WO_xasp_XACMLAuthzDecisionQuery(c, (struct zx_xasp_XACMLAuthzDecisionQuery_s*)x, p);
  case zx_xasp_XACMLPolicyQuery_ELEM:
    return zx_ENC_WO_xasp_XACMLPolicyQuery(c, (struct zx_xasp_XACMLPolicyQuery_s*)x, p);
  case zx_xaspcd1_XACMLAuthzDecisionQuery_ELEM:
    return zx_ENC_WO_xaspcd1_XACMLAuthzDecisionQuery(c, (struct zx_xaspcd1_XACMLAuthzDecisionQuery_s*)x, p);
  case zx_xaspcd1_XACMLPolicyQuery_ELEM:
    return zx_ENC_WO_xaspcd1_XACMLPolicyQuery(c, (struct zx_xaspcd1_XACMLPolicyQuery_s*)x, p);
  case zx_xac_Request_ELEM:
    return zx_ENC_WO_xac_Request(c, (struct zx_xac_Request_s*)x, p);
  case zx_xac_Response_ELEM:
    return zx_ENC_WO_xac_Response(c, (struct zx_xac_Response_s*)x, p);
  case zx_di_Query_ELEM:
    return zx_ENC_WO_di_Query(c, (struct zx_di_Query_s*)x, p);
  case zx_di_QueryResponse_ELEM:
    return zx_ENC_WO_di_QueryResponse(c, (struct zx_di_QueryResponse_s*)x, p);
  case zx_di12_Query_ELEM:
    return zx_ENC_WO_di12_Query(c, (struct zx_di12_Query_s*)x, p);
  case zx_di12_QueryResponse_ELEM:
    return zx_ENC_WO_di12_QueryResponse(c, (struct zx_di12_QueryResponse_s*)x, p);
  case zx_di12_Modify_ELEM:
    return zx_ENC_WO_di12_Modify(c, (struct zx_di12_Modify_s*)x, p);
  case zx_di12_ModifyResponse_ELEM:
    return zx_ENC_WO_di12_ModifyResponse(c, (struct zx_di12_ModifyResponse_s*)x, p);
  case zx_e_Fault_ELEM:
    return zx_ENC_WO_e_Fault(c, (struct zx_e_Fault_s*)x, p);
  case zx_di_SvcMDAssociationAdd_ELEM:
    return zx_ENC_WO_di_SvcMDAssociationAdd(c, (struct zx_di_SvcMDAssociationAdd_s*)x, p);
  case zx_di_SvcMDAssociationAddResponse_ELEM:
    return zx_ENC_WO_di_SvcMDAssociationAddResponse(c, (struct zx_di_SvcMDAssociationAddResponse_s*)x, p);
  case zx_di_SvcMDAssociationDelete_ELEM:
    return zx_ENC_WO_di_SvcMDAssociationDelete(c, (struct zx_di_SvcMDAssociationDelete_s*)x, p);
  case zx_di_SvcMDAssociationDeleteResponse_ELEM:
    return zx_ENC_WO_di_SvcMDAssociationDeleteResponse(c, (struct zx_di_SvcMDAssociationDeleteResponse_s*)x, p);
  case zx_di_SvcMDAssociationQuery_ELEM:
    return zx_ENC_WO_di_SvcMDAssociationQuery(c, (struct zx_di_SvcMDAssociationQuery_s*)x, p);
  case zx_di_SvcMDAssociationQueryResponse_ELEM:
    return zx_ENC_WO_di_SvcMDAssociationQueryResponse(c, (struct zx_di_SvcMDAssociationQueryResponse_s*)x, p);
  case zx_di_SvcMDRegister_ELEM:
    return zx_ENC_WO_di_SvcMDRegister(c, (struct zx_di_SvcMDRegister_s*)x, p);
  case zx_di_SvcMDRegisterResponse_ELEM:
    return zx_ENC_WO_di_SvcMDRegisterResponse(c, (struct zx_di_SvcMDRegisterResponse_s*)x, p);
  case zx_di_SvcMDDelete_ELEM:
    return zx_ENC_WO_di_SvcMDDelete(c, (struct zx_di_SvcMDDelete_s*)x, p);
  case zx_di_SvcMDDeleteResponse_ELEM:
    return zx_ENC_WO_di_SvcMDDeleteResponse(c, (struct zx_di_SvcMDDeleteResponse_s*)x, p);
  case zx_di_SvcMDQuery_ELEM:
    return zx_ENC_WO_di_SvcMDQuery(c, (struct zx_di_SvcMDQuery_s*)x, p);
  case zx_di_SvcMDQueryResponse_ELEM:
    return zx_ENC_WO_di_SvcMDQueryResponse(c, (struct zx_di_SvcMDQueryResponse_s*)x, p);
  case zx_di_SvcMDReplace_ELEM:
    return zx_ENC_WO_di_SvcMDReplace(c, (struct zx_di_SvcMDReplace_s*)x, p);
  case zx_di_SvcMDReplaceResponse_ELEM:
    return zx_ENC_WO_di_SvcMDReplaceResponse(c, (struct zx_di_SvcMDReplaceResponse_s*)x, p);
  case zx_dap_Create_ELEM:
    return zx_ENC_WO_dap_Create(c, (struct zx_dap_Create_s*)x, p);
  case zx_dap_CreateResponse_ELEM:
    return zx_ENC_WO_dap_CreateResponse(c, (struct zx_dap_CreateResponse_s*)x, p);
  case zx_dap_Query_ELEM:
    return zx_ENC_WO_dap_Query(c, (struct zx_dap_Query_s*)x, p);
  case zx_dap_QueryResponse_ELEM:
    return zx_ENC_WO_dap_QueryResponse(c, (struct zx_dap_QueryResponse_s*)x, p);
  case zx_dap_Modify_ELEM:
    return zx_ENC_WO_dap_Modify(c, (struct zx_dap_Modify_s*)x, p);
  case zx_dap_ModifyResponse_ELEM:
    return zx_ENC_WO_dap_ModifyResponse(c, (struct zx_dap_ModifyResponse_s*)x, p);
  case zx_dap_Delete_ELEM:
    return zx_ENC_WO_dap_Delete(c, (struct zx_dap_Delete_s*)x, p);
  case zx_dap_DeleteResponse_ELEM:
    return zx_ENC_WO_dap_DeleteResponse(c, (struct zx_dap_DeleteResponse_s*)x, p);
  case zx_dap_Notify_ELEM:
    return zx_ENC_WO_dap_Notify(c, (struct zx_dap_Notify_s*)x, p);
  case zx_dap_NotifyResponse_ELEM:
    return zx_ENC_WO_dap_NotifyResponse(c, (struct zx_dap_NotifyResponse_s*)x, p);
  case zx_ps_AddEntityRequest_ELEM:
    return zx_ENC_WO_ps_AddEntityRequest(c, (struct zx_ps_AddEntityRequest_s*)x, p);
  case zx_ps_AddEntityResponse_ELEM:
    return zx_ENC_WO_ps_AddEntityResponse(c, (struct zx_ps_AddEntityResponse_s*)x, p);
  case zx_ps_AddKnownEntityRequest_ELEM:
    return zx_ENC_WO_ps_AddKnownEntityRequest(c, (struct zx_ps_AddKnownEntityRequest_s*)x, p);
  case zx_ps_AddKnownEntityResponse_ELEM:
    return zx_ENC_WO_ps_AddKnownEntityResponse(c, (struct zx_ps_AddKnownEntityResponse_s*)x, p);
  case zx_ps_AddCollectionRequest_ELEM:
    return zx_ENC_WO_ps_AddCollectionRequest(c, (struct zx_ps_AddCollectionRequest_s*)x, p);
  case zx_ps_AddCollectionResponse_ELEM:
    return zx_ENC_WO_ps_AddCollectionResponse(c, (struct zx_ps_AddCollectionResponse_s*)x, p);
  case zx_ps_AddToCollectionRequest_ELEM:
    return zx_ENC_WO_ps_AddToCollectionRequest(c, (struct zx_ps_AddToCollectionRequest_s*)x, p);
  case zx_ps_AddToCollectionResponse_ELEM:
    return zx_ENC_WO_ps_AddToCollectionResponse(c, (struct zx_ps_AddToCollectionResponse_s*)x, p);
  case zx_ps_RemoveEntityRequest_ELEM:
    return zx_ENC_WO_ps_RemoveEntityRequest(c, (struct zx_ps_RemoveEntityRequest_s*)x, p);
  case zx_ps_RemoveEntityResponse_ELEM:
    return zx_ENC_WO_ps_RemoveEntityResponse(c, (struct zx_ps_RemoveEntityResponse_s*)x, p);
  case zx_ps_RemoveCollectionRequest_ELEM:
    return zx_ENC_WO_ps_RemoveCollectionRequest(c, (struct zx_ps_RemoveCollectionRequest_s*)x, p);
  case zx_ps_RemoveCollectionResponse_ELEM:
    return zx_ENC_WO_ps_RemoveCollectionResponse(c, (struct zx_ps_RemoveCollectionResponse_s*)x, p);
  case zx_ps_RemoveFromCollectionRequest_ELEM:
    return zx_ENC_WO_ps_RemoveFromCollectionRequest(c, (struct zx_ps_RemoveFromCollectionRequest_s*)x, p);
  case zx_ps_RemoveFromCollectionResponse_ELEM:
    return zx_ENC_WO_ps_RemoveFromCollectionResponse(c, (struct zx_ps_RemoveFromCollectionResponse_s*)x, p);
  case zx_ps_ListMembersRequest_ELEM:
    return zx_ENC_WO_ps_ListMembersRequest(c, (struct zx_ps_ListMembersRequest_s*)x, p);
  case zx_ps_ListMembersResponse_ELEM:
    return zx_ENC_WO_ps_ListMembersResponse(c, (struct zx_ps_ListMembersResponse_s*)x, p);
  case zx_ps_QueryObjectsRequest_ELEM:
    return zx_ENC_WO_ps_QueryObjectsRequest(c, (struct zx_ps_QueryObjectsRequest_s*)x, p);
  case zx_ps_QueryObjectsResponse_ELEM:
    return zx_ENC_WO_ps_QueryObjectsResponse(c, (struct zx_ps_QueryObjectsResponse_s*)x, p);
  case zx_ps_GetObjectInfoRequest_ELEM:
    return zx_ENC_WO_ps_GetObjectInfoRequest(c, (struct zx_ps_GetObjectInfoRequest_s*)x, p);
  case zx_ps_GetObjectInfoResponse_ELEM:
    return zx_ENC_WO_ps_GetObjectInfoResponse(c, (struct zx_ps_GetObjectInfoResponse_s*)x, p);
  case zx_ps_SetObjectInfoRequest_ELEM:
    return zx_ENC_WO_ps_SetObjectInfoRequest(c, (struct zx_ps_SetObjectInfoRequest_s*)x, p);
  case zx_ps_SetObjectInfoResponse_ELEM:
    return zx_ENC_WO_ps_SetObjectInfoResponse(c, (struct zx_ps_SetObjectInfoResponse_s*)x, p);
  case zx_ps_TestMembershipRequest_ELEM:
    return zx_ENC_WO_ps_TestMembershipRequest(c, (struct zx_ps_TestMembershipRequest_s*)x, p);
  case zx_ps_TestMembershipResponse_ELEM:
    return zx_ENC_WO_ps_TestMembershipResponse(c, (struct zx_ps_TestMembershipResponse_s*)x, p);
  case zx_ps_ResolveIdentifierRequest_ELEM:
    return zx_ENC_WO_ps_ResolveIdentifierRequest(c, (struct zx_ps_ResolveIdentifierRequest_s*)x, p);
  case zx_ps_ResolveIdentifierResponse_ELEM:
    return zx_ENC_WO_ps_ResolveIdentifierResponse(c, (struct zx_ps_ResolveIdentifierResponse_s*)x, p);
  case zx_ps_Notify_ELEM:
    return zx_ENC_WO_ps_Notify(c, (struct zx_ps_Notify_s*)x, p);
  case zx_ps_NotifyResponse_ELEM:
    return zx_ENC_WO_ps_NotifyResponse(c, (struct zx_ps_NotifyResponse_s*)x, p);
  case zx_im_IdentityMappingRequest_ELEM:
    return zx_ENC_WO_im_IdentityMappingRequest(c, (struct zx_im_IdentityMappingRequest_s*)x, p);
  case zx_im_IdentityMappingResponse_ELEM:
    return zx_ENC_WO_im_IdentityMappingResponse(c, (struct zx_im_IdentityMappingResponse_s*)x, p);
  case zx_as_SASLRequest_ELEM:
    return zx_ENC_WO_as_SASLRequest(c, (struct zx_as_SASLRequest_s*)x, p);
  case zx_as_SASLResponse_ELEM:
    return zx_ENC_WO_as_SASLResponse(c, (struct zx_as_SASLResponse_s*)x, p);
  case zx_mm7_SubmitReq_ELEM:
    return zx_ENC_WO_mm7_SubmitReq(c, (struct zx_mm7_SubmitReq_s*)x, p);
  case zx_mm7_SubmitRsp_ELEM:
    return zx_ENC_WO_mm7_SubmitRsp(c, (struct zx_mm7_SubmitRsp_s*)x, p);
  case zx_mm7_DeliverReq_ELEM:
    return zx_ENC_WO_mm7_DeliverReq(c, (struct zx_mm7_DeliverReq_s*)x, p);
  case zx_mm7_DeliverRsp_ELEM:
    return zx_ENC_WO_mm7_DeliverRsp(c, (struct zx_mm7_DeliverRsp_s*)x, p);
  case zx_mm7_CancelReq_ELEM:
    return zx_ENC_WO_mm7_CancelReq(c, (struct zx_mm7_CancelReq_s*)x, p);
  case zx_mm7_CancelRsp_ELEM:
    return zx_ENC_WO_mm7_CancelRsp(c, (struct zx_mm7_CancelRsp_s*)x, p);
  case zx_mm7_ReplaceReq_ELEM:
    return zx_ENC_WO_mm7_ReplaceReq(c, (struct zx_mm7_ReplaceReq_s*)x, p);
  case zx_mm7_ReplaceRsp_ELEM:
    return zx_ENC_WO_mm7_ReplaceRsp(c, (struct zx_mm7_ReplaceRsp_s*)x, p);
  case zx_mm7_extendedCancelReq_ELEM:
    return zx_ENC_WO_mm7_extendedCancelReq(c, (struct zx_mm7_extendedCancelReq_s*)x, p);
  case zx_mm7_extendedCancelRsp_ELEM:
    return zx_ENC_WO_mm7_extendedCancelRsp(c, (struct zx_mm7_extendedCancelRsp_s*)x, p);
  case zx_mm7_extendedReplaceReq_ELEM:
    return zx_ENC_WO_mm7_extendedReplaceReq(c, (struct zx_mm7_extendedReplaceReq_s*)x, p);
  case zx_mm7_extendedReplaceRsp_ELEM:
    return zx_ENC_WO_mm7_extendedReplaceRsp(c, (struct zx_mm7_extendedReplaceRsp_s*)x, p);
  case zx_mm7_DeliveryReportReq_ELEM:
    return zx_ENC_WO_mm7_DeliveryReportReq(c, (struct zx_mm7_DeliveryReportReq_s*)x, p);
  case zx_mm7_DeliveryReportRsp_ELEM:
    return zx_ENC_WO_mm7_DeliveryReportRsp(c, (struct zx_mm7_DeliveryReportRsp_s*)x, p);
  case zx_mm7_ReadReplyReq_ELEM:
    return zx_ENC_WO_mm7_ReadReplyReq(c, (struct zx_mm7_ReadReplyReq_s*)x, p);
  case zx_mm7_ReadReplyRsp_ELEM:
    return zx_ENC_WO_mm7_ReadReplyRsp(c, (struct zx_mm7_ReadReplyRsp_s*)x, p);
  case zx_mm7_RSErrorRsp_ELEM:
    return zx_ENC_WO_mm7_RSErrorRsp(c, (struct zx_mm7_RSErrorRsp_s*)x, p);
  case zx_mm7_VASPErrorRsp_ELEM:
    return zx_ENC_WO_mm7_VASPErrorRsp(c, (struct zx_mm7_VASPErrorRsp_s*)x, p);
  case zx_mm7_QueryStatusReq_ELEM:
    return zx_ENC_WO_mm7_QueryStatusReq(c, (struct zx_mm7_QueryStatusReq_s*)x, p);
  case zx_mm7_QueryStatusRsp_ELEM:
    return zx_ENC_WO_mm7_QueryStatusRsp(c, (struct zx_mm7_QueryStatusRsp_s*)x, p);
  case zx_cb_Query_ELEM:
    return zx_ENC_WO_cb_Query(c, (struct zx_cb_Query_s*)x, p);
  case zx_cb_QueryResponse_ELEM:
    return zx_ENC_WO_cb_QueryResponse(c, (struct zx_cb_QueryResponse_s*)x, p);
  case zx_cb_Create_ELEM:
    return zx_ENC_WO_cb_Create(c, (struct zx_cb_Create_s*)x, p);
  case zx_cb_CreateResponse_ELEM:
    return zx_ENC_WO_cb_CreateResponse(c, (struct zx_cb_CreateResponse_s*)x, p);
  case zx_cb_Delete_ELEM:
    return zx_ENC_WO_cb_Delete(c, (struct zx_cb_Delete_s*)x, p);
  case zx_cb_DeleteResponse_ELEM:
    return zx_ENC_WO_cb_DeleteResponse(c, (struct zx_cb_DeleteResponse_s*)x, p);
  case zx_cb_Modify_ELEM:
    return zx_ENC_WO_cb_Modify(c, (struct zx_cb_Modify_s*)x, p);
  case zx_cb_ModifyResponse_ELEM:
    return zx_ENC_WO_cb_ModifyResponse(c, (struct zx_cb_ModifyResponse_s*)x, p);
  case zx_cb_Notify_ELEM:
    return zx_ENC_WO_cb_Notify(c, (struct zx_cb_Notify_s*)x, p);
  case zx_cb_NotifyResponse_ELEM:
    return zx_ENC_WO_cb_NotifyResponse(c, (struct zx_cb_NotifyResponse_s*)x, p);
  case zx_cb_ReportUsage_ELEM:
    return zx_ENC_WO_cb_ReportUsage(c, (struct zx_cb_ReportUsage_s*)x, p);
  case zx_cb_ReportUsageResponse_ELEM:
    return zx_ENC_WO_cb_ReportUsageResponse(c, (struct zx_cb_ReportUsageResponse_s*)x, p);
  case zx_gl_Query_ELEM:
    return zx_ENC_WO_gl_Query(c, (struct zx_gl_Query_s*)x, p);
  case zx_gl_QueryResponse_ELEM:
    return zx_ENC_WO_gl_QueryResponse(c, (struct zx_gl_QueryResponse_s*)x, p);
  case zx_gl_Create_ELEM:
    return zx_ENC_WO_gl_Create(c, (struct zx_gl_Create_s*)x, p);
  case zx_gl_CreateResponse_ELEM:
    return zx_ENC_WO_gl_CreateResponse(c, (struct zx_gl_CreateResponse_s*)x, p);
  case zx_gl_Delete_ELEM:
    return zx_ENC_WO_gl_Delete(c, (struct zx_gl_Delete_s*)x, p);
  case zx_gl_DeleteResponse_ELEM:
    return zx_ENC_WO_gl_DeleteResponse(c, (struct zx_gl_DeleteResponse_s*)x, p);
  case zx_gl_Modify_ELEM:
    return zx_ENC_WO_gl_Modify(c, (struct zx_gl_Modify_s*)x, p);
  case zx_gl_ModifyResponse_ELEM:
    return zx_ENC_WO_gl_ModifyResponse(c, (struct zx_gl_ModifyResponse_s*)x, p);
  case zx_gl_Notify_ELEM:
    return zx_ENC_WO_gl_Notify(c, (struct zx_gl_Notify_s*)x, p);
  case zx_gl_NotifyResponse_ELEM:
    return zx_ENC_WO_gl_NotifyResponse(c, (struct zx_gl_NotifyResponse_s*)x, p);
  case zx_demomed_StoreObjectRequest_ELEM:
    return zx_ENC_WO_demomed_StoreObjectRequest(c, (struct zx_demomed_StoreObjectRequest_s*)x, p);
  case zx_demomed_StoreObjectResponse_ELEM:
    return zx_ENC_WO_demomed_StoreObjectResponse(c, (struct zx_demomed_StoreObjectResponse_s*)x, p);
  case zx_demomed_GetObjectListRequest_ELEM:
    return zx_ENC_WO_demomed_GetObjectListRequest(c, (struct zx_demomed_GetObjectListRequest_s*)x, p);
  case zx_demomed_GetObjectListResponse_ELEM:
    return zx_ENC_WO_demomed_GetObjectListResponse(c, (struct zx_demomed_GetObjectListResponse_s*)x, p);
  case zx_demomed_GetObjectRequest_ELEM:
    return zx_ENC_WO_demomed_GetObjectRequest(c, (struct zx_demomed_GetObjectRequest_s*)x, p);
  case zx_demomed_GetObjectResponse_ELEM:
    return zx_ENC_WO_demomed_GetObjectResponse(c, (struct zx_demomed_GetObjectResponse_s*)x, p);
  case zx_demomed_DeleteObjectRequest_ELEM:
    return zx_ENC_WO_demomed_DeleteObjectRequest(c, (struct zx_demomed_DeleteObjectRequest_s*)x, p);
  case zx_demomed_DeleteObjectResponse_ELEM:
    return zx_ENC_WO_demomed_DeleteObjectResponse(c, (struct zx_demomed_DeleteObjectResponse_s*)x, p);
  case zx_pmm_Provision_ELEM:
    return zx_ENC_WO_pmm_Provision(c, (struct zx_pmm_Provision_s*)x, p);
  case zx_pmm_ProvisionResponse_ELEM:
    return zx_ENC_WO_pmm_ProvisionResponse(c, (struct zx_pmm_ProvisionResponse_s*)x, p);
  case zx_pmm_PMActivate_ELEM:
    return zx_ENC_WO_pmm_PMActivate(c, (struct zx_pmm_PMActivate_s*)x, p);
  case zx_pmm_PMActivateResponse_ELEM:
    return zx_ENC_WO_pmm_PMActivateResponse(c, (struct zx_pmm_PMActivateResponse_s*)x, p);
  case zx_pmm_PMDeactivate_ELEM:
    return zx_ENC_WO_pmm_PMDeactivate(c, (struct zx_pmm_PMDeactivate_s*)x, p);
  case zx_pmm_PMDeactivateResponse_ELEM:
    return zx_ENC_WO_pmm_PMDeactivateResponse(c, (struct zx_pmm_PMDeactivateResponse_s*)x, p);
  case zx_pmm_PMDelete_ELEM:
    return zx_ENC_WO_pmm_PMDelete(c, (struct zx_pmm_PMDelete_s*)x, p);
  case zx_pmm_PMDeleteResponse_ELEM:
    return zx_ENC_WO_pmm_PMDeleteResponse(c, (struct zx_pmm_PMDeleteResponse_s*)x, p);
  case zx_pmm_PMUpdate_ELEM:
    return zx_ENC_WO_pmm_PMUpdate(c, (struct zx_pmm_PMUpdate_s*)x, p);
  case zx_pmm_PMUpdateResponse_ELEM:
    return zx_ENC_WO_pmm_PMUpdateResponse(c, (struct zx_pmm_PMUpdateResponse_s*)x, p);
  case zx_pmm_PMGetStatus_ELEM:
    return zx_ENC_WO_pmm_PMGetStatus(c, (struct zx_pmm_PMGetStatus_s*)x, p);
  case zx_pmm_PMGetStatusResponse_ELEM:
    return zx_ENC_WO_pmm_PMGetStatusResponse(c, (struct zx_pmm_PMGetStatusResponse_s*)x, p);
  case zx_pmm_PMSetStatus_ELEM:
    return zx_ENC_WO_pmm_PMSetStatus(c, (struct zx_pmm_PMSetStatus_s*)x, p);
  case zx_pmm_PMSetStatusResponse_ELEM:
    return zx_ENC_WO_pmm_PMSetStatusResponse(c, (struct zx_pmm_PMSetStatusResponse_s*)x, p);
  case zx_prov_PMERegister_ELEM:
    return zx_ENC_WO_prov_PMERegister(c, (struct zx_prov_PMERegister_s*)x, p);
  case zx_prov_PMERegisterResponse_ELEM:
    return zx_ENC_WO_prov_PMERegisterResponse(c, (struct zx_prov_PMERegisterResponse_s*)x, p);
  case zx_prov_PMEUpload_ELEM:
    return zx_ENC_WO_prov_PMEUpload(c, (struct zx_prov_PMEUpload_s*)x, p);
  case zx_prov_PMEUploadResponse_ELEM:
    return zx_ENC_WO_prov_PMEUploadResponse(c, (struct zx_prov_PMEUploadResponse_s*)x, p);
  case zx_prov_PMEDownload_ELEM:
    return zx_ENC_WO_prov_PMEDownload(c, (struct zx_prov_PMEDownload_s*)x, p);
  case zx_prov_PMEDownloadResponse_ELEM:
    return zx_ENC_WO_prov_PMEDownloadResponse(c, (struct zx_prov_PMEDownloadResponse_s*)x, p);
  case zx_prov_PMEEnable_ELEM:
    return zx_ENC_WO_prov_PMEEnable(c, (struct zx_prov_PMEEnable_s*)x, p);
  case zx_prov_PMEEnableResponse_ELEM:
    return zx_ENC_WO_prov_PMEEnableResponse(c, (struct zx_prov_PMEEnableResponse_s*)x, p);
  case zx_prov_PMEDisable_ELEM:
    return zx_ENC_WO_prov_PMEDisable(c, (struct zx_prov_PMEDisable_s*)x, p);
  case zx_prov_PMEDisableResponse_ELEM:
    return zx_ENC_WO_prov_PMEDisableResponse(c, (struct zx_prov_PMEDisableResponse_s*)x, p);
  case zx_prov_PMEDelete_ELEM:
    return zx_ENC_WO_prov_PMEDelete(c, (struct zx_prov_PMEDelete_s*)x, p);
  case zx_prov_PMEDeleteResponse_ELEM:
    return zx_ENC_WO_prov_PMEDeleteResponse(c, (struct zx_prov_PMEDeleteResponse_s*)x, p);
  case zx_prov_PMEGetInfo_ELEM:
    return zx_ENC_WO_prov_PMEGetInfo(c, (struct zx_prov_PMEGetInfo_s*)x, p);
  case zx_prov_PMEGetInfoResponse_ELEM:
    return zx_ENC_WO_prov_PMEGetInfoResponse(c, (struct zx_prov_PMEGetInfoResponse_s*)x, p);
  case zx_prov_PMGetStatus_ELEM:
    return zx_ENC_WO_prov_PMGetStatus(c, (struct zx_prov_PMGetStatus_s*)x, p);
  case zx_prov_PMGetStatusResponse_ELEM:
    return zx_ENC_WO_prov_PMGetStatusResponse(c, (struct zx_prov_PMGetStatusResponse_s*)x, p);
  case zx_prov_PMSetStatus_ELEM:
    return zx_ENC_WO_prov_PMSetStatus(c, (struct zx_prov_PMSetStatus_s*)x, p);
  case zx_prov_PMSetStatusResponse_ELEM:
    return zx_ENC_WO_prov_PMSetStatusResponse(c, (struct zx_prov_PMSetStatusResponse_s*)x, p);
  case zx_prov_PMGetDescriptor_ELEM:
    return zx_ENC_WO_prov_PMGetDescriptor(c, (struct zx_prov_PMGetDescriptor_s*)x, p);
  case zx_prov_PMGetDescriptorResponse_ELEM:
    return zx_ENC_WO_prov_PMGetDescriptorResponse(c, (struct zx_prov_PMGetDescriptorResponse_s*)x, p);
  case zx_prov_PMActivate_ELEM:
    return zx_ENC_WO_prov_PMActivate(c, (struct zx_prov_PMActivate_s*)x, p);
  case zx_prov_PMActivateResponse_ELEM:
    return zx_ENC_WO_prov_PMActivateResponse(c, (struct zx_prov_PMActivateResponse_s*)x, p);
  case zx_prov_PMDeactivate_ELEM:
    return zx_ENC_WO_prov_PMDeactivate(c, (struct zx_prov_PMDeactivate_s*)x, p);
  case zx_prov_PMDeactivateResponse_ELEM:
    return zx_ENC_WO_prov_PMDeactivateResponse(c, (struct zx_prov_PMDeactivateResponse_s*)x, p);
  case zx_prov_PMRegisterDescriptor_ELEM:
    return zx_ENC_WO_prov_PMRegisterDescriptor(c, (struct zx_prov_PMRegisterDescriptor_s*)x, p);
  case zx_prov_PMRegisterDescriptorResponse_ELEM:
    return zx_ENC_WO_prov_PMRegisterDescriptorResponse(c, (struct zx_prov_PMRegisterDescriptorResponse_s*)x, p);
  case zx_prov_PMUpdate_ELEM:
    return zx_ENC_WO_prov_PMUpdate(c, (struct zx_prov_PMUpdate_s*)x, p);
  case zx_prov_PMUpdateResponse_ELEM:
    return zx_ENC_WO_prov_PMUpdateResponse(c, (struct zx_prov_PMUpdateResponse_s*)x, p);
  case zx_prov_PMDelete_ELEM:
    return zx_ENC_WO_prov_PMDelete(c, (struct zx_prov_PMDelete_s*)x, p);
  case zx_prov_PMDeleteResponse_ELEM:
    return zx_ENC_WO_prov_PMDeleteResponse(c, (struct zx_prov_PMDeleteResponse_s*)x, p);
  case zx_prov_Poll_ELEM:
    return zx_ENC_WO_prov_Poll(c, (struct zx_prov_Poll_s*)x, p);
  case zx_prov_PollResponse_ELEM:
    return zx_ENC_WO_prov_PollResponse(c, (struct zx_prov_PollResponse_s*)x, p);
  case zx_prov_UpdateEPR_ELEM:
    return zx_ENC_WO_prov_UpdateEPR(c, (struct zx_prov_UpdateEPR_s*)x, p);
  case zx_prov_UpdateEPRResponse_ELEM:
    return zx_ENC_WO_prov_UpdateEPRResponse(c, (struct zx_prov_UpdateEPRResponse_s*)x, p);
  case zx_idp_GetAssertion_ELEM:
    return zx_ENC_WO_idp_GetAssertion(c, (struct zx_idp_GetAssertion_s*)x, p);
  case zx_idp_GetAssertionResponse_ELEM:
    return zx_ENC_WO_idp_GetAssertionResponse(c, (struct zx_idp_GetAssertionResponse_s*)x, p);
  case zx_idp_GetProviderInfo_ELEM:
    return zx_ENC_WO_idp_GetProviderInfo(c, (struct zx_idp_GetProviderInfo_s*)x, p);
  case zx_idp_GetProviderInfoResponse_ELEM:
    return zx_ENC_WO_idp_GetProviderInfoResponse(c, (struct zx_idp_GetProviderInfoResponse_s*)x, p);
  case zx_idp_CreatedStatus_ELEM:
    return zx_ENC_WO_idp_CreatedStatus(c, (struct zx_idp_CreatedStatus_s*)x, p);
  case zx_idp_CreatedStatusResponse_ELEM:
    return zx_ENC_WO_idp_CreatedStatusResponse(c, (struct zx_idp_CreatedStatusResponse_s*)x, p);
  case zx_shps_Delete_ELEM:
    return zx_ENC_WO_shps_Delete(c, (struct zx_shps_Delete_s*)x, p);
  case zx_shps_DeleteResponse_ELEM:
    return zx_ENC_WO_shps_DeleteResponse(c, (struct zx_shps_DeleteResponse_s*)x, p);
  case zx_shps_GetStatus_ELEM:
    return zx_ENC_WO_shps_GetStatus(c, (struct zx_shps_GetStatus_s*)x, p);
  case zx_shps_GetStatusResponse_ELEM:
    return zx_ENC_WO_shps_GetStatusResponse(c, (struct zx_shps_GetStatusResponse_s*)x, p);
  case zx_shps_Query_ELEM:
    return zx_ENC_WO_shps_Query(c, (struct zx_shps_Query_s*)x, p);
  case zx_shps_QueryResponse_ELEM:
    return zx_ENC_WO_shps_QueryResponse(c, (struct zx_shps_QueryResponse_s*)x, p);
  case zx_shps_Invoke_ELEM:
    return zx_ENC_WO_simple_elem(c, (struct zx_elem_s*)x, p, "Invoke", sizeof("Invoke")-1);
  case zx_shps_InvokeResponse_ELEM:
    return zx_ENC_WO_shps_InvokeResponse(c, (struct zx_shps_InvokeResponse_s*)x, p);
  case zx_shps_QueryRegistered_ELEM:
    return zx_ENC_WO_shps_QueryRegistered(c, (struct zx_shps_QueryRegistered_s*)x, p);
  case zx_shps_QueryRegisteredResponse_ELEM:
    return zx_ENC_WO_shps_QueryRegisteredResponse(c, (struct zx_shps_QueryRegisteredResponse_s*)x, p);
  case zx_shps_Register_ELEM:
    return zx_ENC_WO_shps_Register(c, (struct zx_shps_Register_s*)x, p);
  case zx_shps_RegisterResponse_ELEM:
    return zx_ENC_WO_shps_RegisterResponse(c, (struct zx_shps_RegisterResponse_s*)x, p);
  case zx_shps_SetStatus_ELEM:
    return zx_ENC_WO_shps_SetStatus(c, (struct zx_shps_SetStatus_s*)x, p);
  case zx_shps_SetStatusResponse_ELEM:
    return zx_ENC_WO_shps_SetStatusResponse(c, (struct zx_shps_SetStatusResponse_s*)x, p);
  case zx_shps_Update_ELEM:
    return zx_ENC_WO_shps_Update(c, (struct zx_shps_Update_s*)x, p);
  case zx_shps_UpdateResponse_ELEM:
    return zx_ENC_WO_shps_UpdateResponse(c, (struct zx_shps_UpdateResponse_s*)x, p);
  case zx_shps_Poll_ELEM:
    return zx_ENC_WO_shps_Poll(c, (struct zx_shps_Poll_s*)x, p);
  case zx_shps_PollResponse_ELEM:
    return zx_ENC_WO_shps_PollResponse(c, (struct zx_shps_PollResponse_s*)x, p);
  case zx_shps_ProxyInvoke_ELEM:
    return zx_ENC_WO_shps_ProxyInvoke(c, (struct zx_shps_ProxyInvoke_s*)x, p);
  case zx_shps_ProxyInvokeResponse_ELEM:
    return zx_ENC_WO_shps_ProxyInvokeResponse(c, (struct zx_shps_ProxyInvokeResponse_s*)x, p);
  case zx_idhrxml_Create_ELEM:
    return zx_ENC_WO_idhrxml_Create(c, (struct zx_idhrxml_Create_s*)x, p);
  case zx_idhrxml_CreateResponse_ELEM:
    return zx_ENC_WO_idhrxml_CreateResponse(c, (struct zx_idhrxml_CreateResponse_s*)x, p);
  case zx_idhrxml_Query_ELEM:
    return zx_ENC_WO_idhrxml_Query(c, (struct zx_idhrxml_Query_s*)x, p);
  case zx_idhrxml_QueryResponse_ELEM:
    return zx_ENC_WO_idhrxml_QueryResponse(c, (struct zx_idhrxml_QueryResponse_s*)x, p);
  case zx_idhrxml_Modify_ELEM:
    return zx_ENC_WO_idhrxml_Modify(c, (struct zx_idhrxml_Modify_s*)x, p);
  case zx_idhrxml_ModifyResponse_ELEM:
    return zx_ENC_WO_idhrxml_ModifyResponse(c, (struct zx_idhrxml_ModifyResponse_s*)x, p);
  case zx_idhrxml_Delete_ELEM:
    return zx_ENC_WO_idhrxml_Delete(c, (struct zx_idhrxml_Delete_s*)x, p);
  case zx_idhrxml_DeleteResponse_ELEM:
    return zx_ENC_WO_idhrxml_DeleteResponse(c, (struct zx_idhrxml_DeleteResponse_s*)x, p);
  case zx_idhrxml_Notify_ELEM:
    return zx_ENC_WO_idhrxml_Notify(c, (struct zx_idhrxml_Notify_s*)x, p);
  case zx_idhrxml_NotifyResponse_ELEM:
    return zx_ENC_WO_idhrxml_NotifyResponse(c, (struct zx_idhrxml_NotifyResponse_s*)x, p);
  case zx_e_Header_ELEM:
    return zx_ENC_WO_e_Header(c, (struct zx_e_Header_s*)x, p);
  case zx_e_Body_ELEM:
    return zx_ENC_WO_e_Body(c, (struct zx_e_Body_s*)x, p);
  case zx_e_faultcode_ELEM:
    return zx_ENC_WO_simple_elem(c, (struct zx_elem_s*)x, p, "faultcode", sizeof("faultcode")-1);
  case zx_e_faultstring_ELEM:
    return zx_ENC_WO_simple_elem(c, (struct zx_elem_s*)x, p, "faultstring", sizeof("faultstring")-1);
  case zx_e_faultactor_ELEM:
    return zx_ENC_WO_simple_elem(c, (struct zx_elem_s*)x, p, "faultactor", sizeof("faultactor")-1);
  case zx_e_detail_ELEM:
    return zx_ENC_WO_e_detail(c, (struct zx_e_detail_s*)x, p);
  case zx_paos_Request_ELEM:
    return zx_ENC_WO_paos_Request(c, (struct zx_paos_Request_s*)x, p);
  case zx_paos_Response_ELEM:
    return zx_ENC_WO_paos_Response(c, (struct zx_paos_Response_s*)x, p);
  case zx_ecp_Request_ELEM:
    return zx_ENC_WO_ecp_Request(c, (struct zx_ecp_Request_s*)x, p);
  case zx_ecp_Response_ELEM:
    return zx_ENC_WO_ecp_Response(c, (struct zx_ecp_Response_s*)x, p);
  case zx_ecp_RelayState_ELEM:
    return zx_ENC_WO_ecp_RelayState(c, (struct zx_ecp_RelayState_s*)x, p);
  case zx_a_MessageID_ELEM:
    return zx_ENC_WO_a_MessageID(c, (struct zx_a_MessageID_s*)x, p);
  case zx_a_RelatesTo_ELEM:
    return zx_ENC_WO_a_RelatesTo(c, (struct zx_a_RelatesTo_s*)x, p);
  case zx_a_ReplyTo_ELEM:
    return zx_ENC_WO_a_ReplyTo(c, (struct zx_a_ReplyTo_s*)x, p);
  case zx_a_From_ELEM:
    return zx_ENC_WO_a_From(c, (struct zx_a_From_s*)x, p);
  case zx_a_FaultTo_ELEM:
    return zx_ENC_WO_a_FaultTo(c, (struct zx_a_FaultTo_s*)x, p);
  case zx_a_To_ELEM:
    return zx_ENC_WO_a_To(c, (struct zx_a_To_s*)x, p);
  case zx_b_Framework_ELEM:
    return zx_ENC_WO_b_Framework(c, (struct zx_b_Framework_s*)x, p);
  case zx_b_Sender_ELEM:
    return zx_ENC_WO_b_Sender(c, (struct zx_b_Sender_s*)x, p);
  case zx_b_CredentialsContext_ELEM:
    return zx_ENC_WO_b_CredentialsContext(c, (struct zx_b_CredentialsContext_s*)x, p);
  case zx_b_EndpointUpdate_ELEM:
    return zx_ENC_WO_b_EndpointUpdate(c, (struct zx_b_EndpointUpdate_s*)x, p);
  case zx_b_Timeout_ELEM:
    return zx_ENC_WO_b_Timeout(c, (struct zx_b_Timeout_s*)x, p);
  case zx_b_ProcessingContext_ELEM:
    return zx_ENC_WO_b_ProcessingContext(c, (struct zx_b_ProcessingContext_s*)x, p);
  case zx_b_Consent_ELEM:
    return zx_ENC_WO_b_Consent(c, (struct zx_b_Consent_s*)x, p);
  case zx_b_UsageDirective_ELEM:
    return zx_ENC_WO_b_UsageDirective(c, (struct zx_b_UsageDirective_s*)x, p);
  case zx_b_ApplicationEPR_ELEM:
    return zx_ENC_WO_b_ApplicationEPR(c, (struct zx_b_ApplicationEPR_s*)x, p);
  case zx_b_UserInteraction_ELEM:
    return zx_ENC_WO_b_UserInteraction(c, (struct zx_b_UserInteraction_s*)x, p);
  case zx_b_RedirectRequest_ELEM:
    return zx_ENC_WO_b_RedirectRequest(c, (struct zx_b_RedirectRequest_s*)x, p);
  case zx_b12_Correlation_ELEM:
    return zx_ENC_WO_b12_Correlation(c, (struct zx_b12_Correlation_s*)x, p);
  case zx_b12_Provider_ELEM:
    return zx_ENC_WO_b12_Provider(c, (struct zx_b12_Provider_s*)x, p);
  case zx_b12_ProcessingContext_ELEM:
    return zx_ENC_WO_b12_ProcessingContext(c, (struct zx_b12_ProcessingContext_s*)x, p);
  case zx_b12_Consent_ELEM:
    return zx_ENC_WO_b12_Consent(c, (struct zx_b12_Consent_s*)x, p);
  case zx_b12_UsageDirective_ELEM:
    return zx_ENC_WO_b12_UsageDirective(c, (struct zx_b12_UsageDirective_s*)x, p);
  case zx_mm7_TransactionID_ELEM:
    return zx_ENC_WO_mm7_TransactionID(c, (struct zx_mm7_TransactionID_s*)x, p);
  case zx_wsse_Security_ELEM:
    return zx_ENC_WO_wsse_Security(c, (struct zx_wsse_Security_s*)x, p);
  case zx_tas3_Status_ELEM:
    return zx_ENC_WO_tas3_Status(c, (struct zx_tas3_Status_s*)x, p);
  case zx_tas3_Credentials_ELEM:
    return zx_ENC_WO_tas3_Credentials(c, (struct zx_tas3_Credentials_s*)x, p);
  case zx_tas3_ESLPolicies_ELEM:
    return zx_ENC_WO_tas3_ESLPolicies(c, (struct zx_tas3_ESLPolicies_s*)x, p);
  case zx_sa_Issuer_ELEM:
    return zx_ENC_WO_sa_Issuer(c, (struct zx_sa_Issuer_s*)x, p);
  case zx_sp_IDPList_ELEM:
    return zx_ENC_WO_sp_IDPList(c, (struct zx_sp_IDPList_s*)x, p);
  case zx_sa11_Conditions_ELEM:
    return zx_ENC_WO_sa11_Conditions(c, (struct zx_sa11_Conditions_s*)x, p);
  case zx_sa11_Advice_ELEM:
    return zx_ENC_WO_sa11_Advice(c, (struct zx_sa11_Advice_s*)x, p);
  case zx_sa11_Statement_ELEM:
    return zx_ENC_WO_simple_elem(c, (struct zx_elem_s*)x, p, "Statement", sizeof("Statement")-1);
  case zx_sa11_SubjectStatement_ELEM:
    return zx_ENC_WO_sa11_SubjectStatement(c, (struct zx_sa11_SubjectStatement_s*)x, p);
  case zx_sa11_AuthenticationStatement_ELEM:
    return zx_ENC_WO_sa11_AuthenticationStatement(c, (struct zx_sa11_AuthenticationStatement_s*)x, p);
  case zx_sa11_AuthorizationDecisionStatement_ELEM:
    return zx_ENC_WO_sa11_AuthorizationDecisionStatement(c, (struct zx_sa11_AuthorizationDecisionStatement_s*)x, p);
  case zx_sa11_AttributeStatement_ELEM:
    return zx_ENC_WO_sa11_AttributeStatement(c, (struct zx_sa11_AttributeStatement_s*)x, p);
  case zx_xasa_XACMLAuthzDecisionStatement_ELEM:
    return zx_ENC_WO_xasa_XACMLAuthzDecisionStatement(c, (struct zx_xasa_XACMLAuthzDecisionStatement_s*)x, p);
  case zx_xasa_XACMLPolicyStatement_ELEM:
    return zx_ENC_WO_xasa_XACMLPolicyStatement(c, (struct zx_xasa_XACMLPolicyStatement_s*)x, p);
  case zx_xasacd1_XACMLAuthzDecisionStatement_ELEM:
    return zx_ENC_WO_xasacd1_XACMLAuthzDecisionStatement(c, (struct zx_xasacd1_XACMLAuthzDecisionStatement_s*)x, p);
  case zx_xasacd1_XACMLPolicyStatement_ELEM:
    return zx_ENC_WO_xasacd1_XACMLPolicyStatement(c, (struct zx_xasacd1_XACMLPolicyStatement_s*)x, p);
  case zx_ds_Signature_ELEM:
    return (x != c->exclude_sig) ? zx_ENC_WO_ds_Signature(c, (struct zx_ds_Signature_s*)x, p) : p;
  case zx_sa11_Subject_ELEM:
    return zx_ENC_WO_sa11_Subject(c, (struct zx_sa11_Subject_s*)x, p);
  case zx_sa11_SubjectLocality_ELEM:
    return zx_ENC_WO_sa11_SubjectLocality(c, (struct zx_sa11_SubjectLocality_s*)x, p);
  case zx_sa11_AuthorityBinding_ELEM:
    return zx_ENC_WO_sa11_AuthorityBinding(c, (struct zx_sa11_AuthorityBinding_s*)x, p);
  case zx_ff12_AuthnContext_ELEM:
    return zx_ENC_WO_ff12_AuthnContext(c, (struct zx_ff12_AuthnContext_s*)x, p);
  case zx_ff12_AuthnContextClassRef_ELEM:
    return zx_ENC_WO_simple_elem(c, (struct zx_elem_s*)x, p, "AuthnContextClassRef", sizeof("AuthnContextClassRef")-1);
  case zx_ac_AuthenticationContextStatement_ELEM:
    return zx_ENC_WO_ac_AuthenticationContextStatement(c, (struct zx_ac_AuthenticationContextStatement_s*)x, p);
  case zx_ff12_AuthnContextStatementRef_ELEM:
    return zx_ENC_WO_simple_elem(c, (struct zx_elem_s*)x, p, "AuthnContextStatementRef", sizeof("AuthnContextStatementRef")-1);
  case zx_sp11_RespondWith_ELEM:
    return zx_ENC_WO_simple_elem(c, (struct zx_elem_s*)x, p, "RespondWith", sizeof("RespondWith")-1);
  case zx_ff12_Extension_ELEM:
    return zx_ENC_WO_ff12_Extension(c, (struct zx_ff12_Extension_s*)x, p);
  case zx_ff12_ProviderID_ELEM:
    return zx_ENC_WO_simple_elem(c, (struct zx_elem_s*)x, p, "ProviderID", sizeof("ProviderID")-1);
  case zx_ff12_AffiliationID_ELEM:
    return zx_ENC_WO_simple_elem(c, (struct zx_elem_s*)x, p, "AffiliationID", sizeof("AffiliationID")-1);
  case zx_ff12_NameIDPolicy_ELEM:
    return zx_ENC_WO_simple_elem(c, (struct zx_elem_s*)x, p, "NameIDPolicy", sizeof("NameIDPolicy")-1);
  case zx_ff12_ForceAuthn_ELEM:
    return zx_ENC_WO_simple_elem(c, (struct zx_elem_s*)x, p, "ForceAuthn", sizeof("ForceAuthn")-1);
  case zx_ff12_IsPassive_ELEM:
    return zx_ENC_WO_simple_elem(c, (struct zx_elem_s*)x, p, "IsPassive", sizeof("IsPassive")-1);
  case zx_ff12_ProtocolProfile_ELEM:
    return zx_ENC_WO_simple_elem(c, (struct zx_elem_s*)x, p, "ProtocolProfile", sizeof("ProtocolProfile")-1);
  case zx_ff12_AssertionConsumerServiceID_ELEM:
    return zx_ENC_WO_simple_elem(c, (struct zx_elem_s*)x, p, "AssertionConsumerServiceID", sizeof("AssertionConsumerServiceID")-1);
  case zx_ff12_RequestAuthnContext_ELEM:
    return zx_ENC_WO_ff12_RequestAuthnContext(c, (struct zx_ff12_RequestAuthnContext_s*)x, p);
  case zx_ff12_RelayState_ELEM:
    return zx_ENC_WO_simple_elem(c, (struct zx_elem_s*)x, p, "RelayState", sizeof("RelayState")-1);
  case zx_ff12_Scoping_ELEM:
    return zx_ENC_WO_ff12_Scoping(c, (struct zx_ff12_Scoping_s*)x, p);
  case zx_ff12_AuthnRequest_ELEM:
    return zx_ENC_WO_ff12_AuthnRequest(c, (struct zx_ff12_AuthnRequest_s*)x, p);
  case zx_ff12_ProviderName_ELEM:
    return zx_ENC_WO_simple_elem(c, (struct zx_elem_s*)x, p, "ProviderName", sizeof("ProviderName")-1);
  case zx_ff12_AssertionConsumerServiceURL_ELEM:
    return zx_ENC_WO_simple_elem(c, (struct zx_elem_s*)x, p, "AssertionConsumerServiceURL", sizeof("AssertionConsumerServiceURL")-1);
  case zx_ff12_IDPList_ELEM:
    return zx_ENC_WO_ff12_IDPList(c, (struct zx_ff12_IDPList_s*)x, p);
  case zx_sp11_Status_ELEM:
    return zx_ENC_WO_sp11_Status(c, (struct zx_sp11_Status_s*)x, p);
  case zx_ff12_AuthnResponse_ELEM:
    return zx_ENC_WO_ff12_AuthnResponse(c, (struct zx_ff12_AuthnResponse_s*)x, p);
  case zx_sa11_NameIdentifier_ELEM:
    return zx_ENC_WO_sa11_NameIdentifier(c, (struct zx_sa11_NameIdentifier_s*)x, p);
  case zx_ff12_IDPEntry_ELEM:
    return zx_ENC_WO_ff12_IDPEntry(c, (struct zx_ff12_IDPEntry_s*)x, p);
  case zx_ff12_Loc_ELEM:
    return zx_ENC_WO_simple_elem(c, (struct zx_elem_s*)x, p, "Loc", sizeof("Loc")-1);
  case zx_ff12_IDPEntries_ELEM:
    return zx_ENC_WO_ff12_IDPEntries(c, (struct zx_ff12_IDPEntries_s*)x, p);
  case zx_ff12_GetComplete_ELEM:
    return zx_ENC_WO_simple_elem(c, (struct zx_elem_s*)x, p, "GetComplete", sizeof("GetComplete")-1);
  case zx_ff12_SessionIndex_ELEM:
    return zx_ENC_WO_simple_elem(c, (struct zx_elem_s*)x, p, "SessionIndex", sizeof("SessionIndex")-1);
  case zx_ff12_TargetNamespace_ELEM:
    return zx_ENC_WO_simple_elem(c, (struct zx_elem_s*)x, p, "TargetNamespace", sizeof("TargetNamespace")-1);
  case zx_ff12_IDPProvidedNameIdentifier_ELEM:
    return zx_ENC_WO_ff12_IDPProvidedNameIdentifier(c, (struct zx_ff12_IDPProvidedNameIdentifier_s*)x, p);
  case zx_ff12_SPProvidedNameIdentifier_ELEM:
    return zx_ENC_WO_ff12_SPProvidedNameIdentifier(c, (struct zx_ff12_SPProvidedNameIdentifier_s*)x, p);
  case zx_ff12_OldProvidedNameIdentifier_ELEM:
    return zx_ENC_WO_ff12_OldProvidedNameIdentifier(c, (struct zx_ff12_OldProvidedNameIdentifier_s*)x, p);
  case zx_ff12_AuthnContextComparison_ELEM:
    return zx_ENC_WO_simple_elem(c, (struct zx_elem_s*)x, p, "AuthnContextComparison", sizeof("AuthnContextComparison")-1);
  case zx_ff12_ProxyCount_ELEM:
    return zx_ENC_WO_simple_elem(c, (struct zx_elem_s*)x, p, "ProxyCount", sizeof("ProxyCount")-1);
  case zx_sa11_SubjectConfirmation_ELEM:
    return zx_ENC_WO_sa11_SubjectConfirmation(c, (struct zx_sa11_SubjectConfirmation_s*)x, p);
  case zx_gl_CivilData_ELEM:
    return zx_ENC_WO_gl_CivilData(c, (struct zx_gl_CivilData_s*)x, p);
  case zx_gl_shape_ELEM:
    return zx_ENC_WO_gl_shape(c, (struct zx_gl_shape_s*)x, p);
  case zx_gl_Extension_ELEM:
    return zx_ENC_WO_gl_Extension(c, (struct zx_gl_Extension_s*)x, p);
  case zx_gl_coord_ELEM:
    return zx_ENC_WO_gl_coord(c, (struct zx_gl_coord_s*)x, p);
  case zx_gl_inRadius_ELEM:
    return zx_ENC_WO_simple_elem(c, (struct zx_elem_s*)x, p, "inRadius", sizeof("inRadius")-1);
  case zx_gl_outRadius_ELEM:
    return zx_ENC_WO_simple_elem(c, (struct zx_elem_s*)x, p, "outRadius", sizeof("outRadius")-1);
  case zx_gl_startAngle_ELEM:
    return zx_ENC_WO_simple_elem(c, (struct zx_elem_s*)x, p, "startAngle", sizeof("startAngle")-1);
  case zx_gl_stopAngle_ELEM:
    return zx_ENC_WO_simple_elem(c, (struct zx_elem_s*)x, p, "stopAngle", sizeof("stopAngle")-1);
  case zx_gl_angularUnit_ELEM:
    return zx_ENC_WO_simple_elem(c, (struct zx_elem_s*)x, p, "angularUnit", sizeof("angularUnit")-1);
  case zx_gl_distanceUnit_ELEM:
    return zx_ENC_WO_simple_elem(c, (struct zx_elem_s*)x, p, "distanceUnit", sizeof("distanceUnit")-1);
  case zx_gl_radius_ELEM:
    return zx_ENC_WO_simple_elem(c, (struct zx_elem_s*)x, p, "radius", sizeof("radius")-1);
  case zx_gl_PostalAddress_ELEM:
    return zx_ENC_WO_simple_elem(c, (struct zx_elem_s*)x, p, "PostalAddress", sizeof("PostalAddress")-1);
  case zx_gl_LPostalAddress_ELEM:
    return zx_ENC_WO_gl_LPostalAddress(c, (struct zx_gl_LPostalAddress_s*)x, p);
  case zx_gl_PostalCode_ELEM:
    return zx_ENC_WO_simple_elem(c, (struct zx_elem_s*)x, p, "PostalCode", sizeof("PostalCode")-1);
  case zx_gl_L_ELEM:
    return zx_ENC_WO_simple_elem(c, (struct zx_elem_s*)x, p, "L", sizeof("L")-1);
  case zx_gl_LL_ELEM:
    return zx_ENC_WO_gl_LL(c, (struct zx_gl_LL_s*)x, p);
  case zx_gl_St_ELEM:
    return zx_ENC_WO_simple_elem(c, (struct zx_elem_s*)x, p, "St", sizeof("St")-1);
  case zx_gl_LSt_ELEM:
    return zx_ENC_WO_gl_LSt(c, (struct zx_gl_LSt_s*)x, p);
  case zx_gl_C_ELEM:
    return zx_ENC_WO_simple_elem(c, (struct zx_elem_s*)x, p, "C", sizeof("C")-1);
  case zx_gl_MNC_ELEM:
    return zx_ENC_WO_simple_elem(c, (struct zx_elem_s*)x, p, "MNC", sizeof("MNC")-1);
  case zx_gl_Identifier_ELEM:
    return zx_ENC_WO_gl_Identifier(c, (struct zx_gl_Identifier_s*)x, p);
  case zx_gl_ResourceID_ELEM:
    return zx_ENC_WO_gl_ResourceID(c, (struct zx_gl_ResourceID_s*)x, p);
  case zx_gl_EncryptedResourceID_ELEM:
    return zx_ENC_WO_gl_EncryptedResourceID(c, (struct zx_gl_EncryptedResourceID_s*)x, p);
  case zx_gl_Subscription_ELEM:
    return zx_ENC_WO_gl_Subscription(c, (struct zx_gl_Subscription_s*)x, p);
  case zx_gl_CreateItem_ELEM:
    return zx_ENC_WO_gl_CreateItem(c, (struct zx_gl_CreateItem_s*)x, p);
  case zx_gl_ItemSelection_ELEM:
    return zx_ENC_WO_gl_ItemSelection(c, (struct zx_gl_ItemSelection_s*)x, p);
  case zx_gl_NewData_ELEM:
    return zx_ENC_WO_gl_NewData(c, (struct zx_gl_NewData_s*)x, p);
  case zx_gl_Status_ELEM:
    return zx_ENC_WO_gl_Status(c, (struct zx_gl_Status_s*)x, p);
  case zx_gl_ItemData_ELEM:
    return zx_ENC_WO_gl_ItemData(c, (struct zx_gl_ItemData_s*)x, p);
  case zx_gl_DeleteItem_ELEM:
    return zx_ENC_WO_gl_DeleteItem(c, (struct zx_gl_DeleteItem_s*)x, p);
  case zx_gl_Select_ELEM:
    return zx_ENC_WO_simple_elem(c, (struct zx_elem_s*)x, p, "Select", sizeof("Select")-1);
  case zx_gl_angle_ELEM:
    return zx_ENC_WO_simple_elem(c, (struct zx_elem_s*)x, p, "angle", sizeof("angle")-1);
  case zx_gl_semiMajor_ELEM:
    return zx_ENC_WO_simple_elem(c, (struct zx_elem_s*)x, p, "semiMajor", sizeof("semiMajor")-1);
  case zx_gl_semiMinor_ELEM:
    return zx_ENC_WO_simple_elem(c, (struct zx_elem_s*)x, p, "semiMinor", sizeof("semiMinor")-1);
  case zx_gl_code_ELEM:
    return zx_ENC_WO_simple_elem(c, (struct zx_elem_s*)x, p, "code", sizeof("code")-1);
  case zx_gl_codeSpace_ELEM:
    return zx_ENC_WO_simple_elem(c, (struct zx_elem_s*)x, p, "codeSpace", sizeof("codeSpace")-1);
  case zx_gl_edition_ELEM:
    return zx_ENC_WO_simple_elem(c, (struct zx_elem_s*)x, p, "edition", sizeof("edition")-1);
  case zx_gl_AreaComparison_ELEM:
    return zx_ENC_WO_gl_AreaComparison(c, (struct zx_gl_AreaComparison_s*)x, p);
  case zx_gl_eqop_ELEM:
    return zx_ENC_WO_gl_eqop(c, (struct zx_gl_eqop_s*)x, p);
  case zx_gl_geoinfo_ELEM:
    return zx_ENC_WO_gl_geoinfo(c, (struct zx_gl_geoinfo_s*)x, p);
  case zx_gl_loc_type_ELEM:
    return zx_ENC_WO_gl_loc_type(c, (struct zx_gl_loc_type_s*)x, p);
  case zx_gl_prio_ELEM:
    return zx_ENC_WO_gl_prio(c, (struct zx_gl_prio_s*)x, p);
  case zx_gl_Modification_ELEM:
    return zx_ENC_WO_gl_Modification(c, (struct zx_gl_Modification_s*)x, p);
  case zx_gl_LineString_ELEM:
    return zx_ENC_WO_gl_LineString(c, (struct zx_gl_LineString_s*)x, p);
  case zx_gl_Point_ELEM:
    return zx_ENC_WO_gl_Point(c, (struct zx_gl_Point_s*)x, p);
  case zx_gl_Polygon_ELEM:
    return zx_ENC_WO_gl_Polygon(c, (struct zx_gl_Polygon_s*)x, p);
  case zx_gl_Box_ELEM:
    return zx_ENC_WO_gl_Box(c, (struct zx_gl_Box_s*)x, p);
  case zx_gl_CircularArea_ELEM:
    return zx_ENC_WO_gl_CircularArea(c, (struct zx_gl_CircularArea_s*)x, p);
  case zx_gl_CircularArcArea_ELEM:
    return zx_ENC_WO_gl_CircularArcArea(c, (struct zx_gl_CircularArcArea_s*)x, p);
  case zx_gl_EllipticalArea_ELEM:
    return zx_ENC_WO_gl_EllipticalArea(c, (struct zx_gl_EllipticalArea_s*)x, p);
  case zx_gl_Notification_ELEM:
    return zx_ENC_WO_gl_Notification(c, (struct zx_gl_Notification_s*)x, p);
  case zx_gl_SecurityMechID_ELEM:
    return zx_ENC_WO_simple_elem(c, (struct zx_elem_s*)x, p, "SecurityMechID", sizeof("SecurityMechID")-1);
  case zx_gl_Credential_ELEM:
    return zx_ENC_WO_gl_Credential(c, (struct zx_gl_Credential_s*)x, p);
  case zx_gl_Endpoint_ELEM:
    return zx_ENC_WO_simple_elem(c, (struct zx_elem_s*)x, p, "Endpoint", sizeof("Endpoint")-1);
  case zx_gl_outerBoundaryIs_ELEM:
    return zx_ENC_WO_gl_outerBoundaryIs(c, (struct zx_gl_outerBoundaryIs_s*)x, p);
  case zx_gl_innerBoundaryIs_ELEM:
    return zx_ENC_WO_gl_innerBoundaryIs(c, (struct zx_gl_innerBoundaryIs_s*)x, p);
  case zx_gl_QueryItem_ELEM:
    return zx_ENC_WO_gl_QueryItem(c, (struct zx_gl_QueryItem_s*)x, p);
  case zx_gl_Data_ELEM:
    return zx_ENC_WO_gl_Data(c, (struct zx_gl_Data_s*)x, p);
  case zx_gl_RefItem_ELEM:
    return zx_ENC_WO_gl_RefItem(c, (struct zx_gl_RefItem_s*)x, p);
  case zx_gl_NotifyTo_ELEM:
    return zx_ENC_WO_gl_NotifyTo(c, (struct zx_gl_NotifyTo_s*)x, p);
  case zx_gl_NotifyAdminTo_ELEM:
    return zx_ENC_WO_gl_NotifyAdminTo(c, (struct zx_gl_NotifyAdminTo_s*)x, p);
  case zx_gl_Aggregation_ELEM:
    return zx_ENC_WO_simple_elem(c, (struct zx_elem_s*)x, p, "Aggregation", sizeof("Aggregation")-1);
  case zx_gl_Trigger_ELEM:
    return zx_ENC_WO_gl_Trigger(c, (struct zx_gl_Trigger_s*)x, p);
  case zx_gl_Granularity_ELEM:
    return zx_ENC_WO_simple_elem(c, (struct zx_elem_s*)x, p, "Granularity", sizeof("Granularity")-1);
  case zx_gl_Interval_ELEM:
    return zx_ENC_WO_simple_elem(c, (struct zx_elem_s*)x, p, "Interval", sizeof("Interval")-1);
  case zx_gl_ms_action_ELEM:
    return zx_ENC_WO_gl_ms_action(c, (struct zx_gl_ms_action_s*)x, p);
  case zx_gl_ChangeArea_ELEM:
    return zx_ENC_WO_gl_ChangeArea(c, (struct zx_gl_ChangeArea_s*)x, p);
  case zx_gl_X_ELEM:
    return zx_ENC_WO_simple_elem(c, (struct zx_elem_s*)x, p, "X", sizeof("X")-1);
  case zx_gl_Y_ELEM:
    return zx_ENC_WO_simple_elem(c, (struct zx_elem_s*)x, p, "Y", sizeof("Y")-1);
  case zx_gl_Z_ELEM:
    return zx_ENC_WO_simple_elem(c, (struct zx_elem_s*)x, p, "Z", sizeof("Z")-1);
  case zx_gl_resp_req_ELEM:
    return zx_ENC_WO_gl_resp_req(c, (struct zx_gl_resp_req_s*)x, p);
  case zx_gl_ll_acc_ELEM:
    return zx_ENC_WO_simple_elem(c, (struct zx_elem_s*)x, p, "ll_acc", sizeof("ll_acc")-1);
  case zx_gl_hor_acc_ELEM:
    return zx_ENC_WO_simple_elem(c, (struct zx_elem_s*)x, p, "hor_acc", sizeof("hor_acc")-1);
  case zx_gl_alt_acc_ELEM:
    return zx_ENC_WO_simple_elem(c, (struct zx_elem_s*)x, p, "alt_acc", sizeof("alt_acc")-1);
  case zx_gl_max_loc_age_ELEM:
    return zx_ENC_WO_simple_elem(c, (struct zx_elem_s*)x, p, "max_loc_age", sizeof("max_loc_age")-1);
  case zx_gl_CoordinateReferenceSystem_ELEM:
    return zx_ENC_WO_gl_CoordinateReferenceSystem(c, (struct zx_gl_CoordinateReferenceSystem_s*)x, p);
  case zx_gl_speed_ELEM:
    return zx_ENC_WO_simple_elem(c, (struct zx_elem_s*)x, p, "speed", sizeof("speed")-1);
  case zx_gl_alt_ELEM:
    return zx_ENC_WO_simple_elem(c, (struct zx_elem_s*)x, p, "alt", sizeof("alt")-1);
  case zx_gl_direction_ELEM:
    return zx_ENC_WO_simple_elem(c, (struct zx_elem_s*)x, p, "direction", sizeof("direction")-1);
  case zx_gl_Heading_ELEM:
    return zx_ENC_WO_simple_elem(c, (struct zx_elem_s*)x, p, "Heading", sizeof("Heading")-1);
  case zx_gl_LinearRing_ELEM:
    return zx_ENC_WO_gl_LinearRing(c, (struct zx_gl_LinearRing_s*)x, p);
  case zx_gl_time_ELEM:
    return zx_ENC_WO_simple_elem(c, (struct zx_elem_s*)x, p, "time", sizeof("time")-1);
  case zx_gl_lev_conf_ELEM:
    return zx_ENC_WO_simple_elem(c, (struct zx_elem_s*)x, p, "lev_conf", sizeof("lev_conf")-1);
  case zx_gl_GeometryCollection_ELEM:
    return zx_ENC_WO_gl_GeometryCollection(c, (struct zx_gl_GeometryCollection_s*)x, p);
  case zx_gl_MultiLineString_ELEM:
    return zx_ENC_WO_gl_MultiLineString(c, (struct zx_gl_MultiLineString_s*)x, p);
  case zx_gl_MultiPoint_ELEM:
    return zx_ENC_WO_gl_MultiPoint(c, (struct zx_gl_MultiPoint_s*)x, p);
  case zx_gl_MultiPolygon_ELEM:
    return zx_ENC_WO_gl_MultiPolygon(c, (struct zx_gl_MultiPolygon_s*)x, p);
  case zx_hrxml_Date_ELEM:
    return zx_ENC_WO_simple_elem(c, (struct zx_elem_s*)x, p, "Date", sizeof("Date")-1);
  case zx_hrxml_Description_ELEM:
    return zx_ENC_WO_hrxml_Description(c, (struct zx_hrxml_Description_s*)x, p);
  case zx_hrxml_IssuingAuthority_ELEM:
    return zx_ENC_WO_hrxml_IssuingAuthority(c, (struct zx_hrxml_IssuingAuthority_s*)x, p);
  case zx_hrxml_Achievement_ELEM:
    return zx_ENC_WO_hrxml_Achievement(c, (struct zx_hrxml_Achievement_s*)x, p);
  case zx_hrxml_IdValue_ELEM:
    return zx_ENC_WO_hrxml_IdValue(c, (struct zx_hrxml_IdValue_s*)x, p);
  case zx_hrxml_FormattedName_ELEM:
    return zx_ENC_WO_simple_elem(c, (struct zx_elem_s*)x, p, "FormattedName", sizeof("FormattedName")-1);
  case zx_hrxml_LegalName_ELEM:
    return zx_ENC_WO_simple_elem(c, (struct zx_elem_s*)x, p, "LegalName", sizeof("LegalName")-1);
  case zx_hrxml_GivenName_ELEM:
    return zx_ENC_WO_simple_elem(c, (struct zx_elem_s*)x, p, "GivenName", sizeof("GivenName")-1);
  case zx_hrxml_PreferredGivenName_ELEM:
    return zx_ENC_WO_simple_elem(c, (struct zx_elem_s*)x, p, "PreferredGivenName", sizeof("PreferredGivenName")-1);
  case zx_hrxml_MiddleName_ELEM:
    return zx_ENC_WO_simple_elem(c, (struct zx_elem_s*)x, p, "MiddleName", sizeof("MiddleName")-1);
  case zx_hrxml_FamilyName_ELEM:
    return zx_ENC_WO_hrxml_FamilyName(c, (struct zx_hrxml_FamilyName_s*)x, p);
  case zx_hrxml_Affix_ELEM:
    return zx_ENC_WO_hrxml_Affix(c, (struct zx_hrxml_Affix_s*)x, p);
  case zx_hrxml_Value_ELEM:
    return zx_ENC_WO_simple_elem(c, (struct zx_elem_s*)x, p, "Value", sizeof("Value")-1);
  case zx_hrxml_Area_ELEM:
    return zx_ENC_WO_hrxml_Area(c, (struct zx_hrxml_Area_s*)x, p);
  case zx_hrxml_Title_ELEM:
    return zx_ENC_WO_simple_elem(c, (struct zx_elem_s*)x, p, "Title", sizeof("Title")-1);
  case zx_hrxml_Name_ELEM:
    return zx_ENC_WO_simple_elem(c, (struct zx_elem_s*)x, p, "Name", sizeof("Name")-1);
  case zx_hrxml_PublicationDate_ELEM:
    return zx_ENC_WO_hrxml_PublicationDate(c, (struct zx_hrxml_PublicationDate_s*)x, p);
  case zx_hrxml_Link_ELEM:
    return zx_ENC_WO_simple_elem(c, (struct zx_elem_s*)x, p, "Link", sizeof("Link")-1);
  case zx_hrxml_Abstract_ELEM:
    return zx_ENC_WO_simple_elem(c, (struct zx_elem_s*)x, p, "Abstract", sizeof("Abstract")-1);
  case zx_hrxml_Copyright_ELEM:
    return zx_ENC_WO_hrxml_Copyright(c, (struct zx_hrxml_Copyright_s*)x, p);
  case zx_hrxml_Comments_ELEM:
    return zx_ENC_WO_simple_elem(c, (struct zx_elem_s*)x, p, "Comments", sizeof("Comments")-1);
  case zx_hrxml_JournalOrSerialName_ELEM:
    return zx_ENC_WO_simple_elem(c, (struct zx_elem_s*)x, p, "JournalOrSerialName", sizeof("JournalOrSerialName")-1);
  case zx_hrxml_ISSN_ELEM:
    return zx_ENC_WO_simple_elem(c, (struct zx_elem_s*)x, p, "ISSN", sizeof("ISSN")-1);
  case zx_hrxml_Volume_ELEM:
    return zx_ENC_WO_simple_elem(c, (struct zx_elem_s*)x, p, "Volume", sizeof("Volume")-1);
  case zx_hrxml_Issue_ELEM:
    return zx_ENC_WO_simple_elem(c, (struct zx_elem_s*)x, p, "Issue", sizeof("Issue")-1);
  case zx_hrxml_PageNumber_ELEM:
    return zx_ENC_WO_simple_elem(c, (struct zx_elem_s*)x, p, "PageNumber", sizeof("PageNumber")-1);
  case zx_hrxml_PublicationLanguage_ELEM:
    return zx_ENC_WO_hrxml_PublicationLanguage(c, (struct zx_hrxml_PublicationLanguage_s*)x, p);
  case zx_hrxml_Id_ELEM:
    return zx_ENC_WO_hrxml_Id(c, (struct zx_hrxml_Id_s*)x, p);
  case zx_hrxml_StartDate_ELEM:
    return zx_ENC_WO_hrxml_StartDate(c, (struct zx_hrxml_StartDate_s*)x, p);
  case zx_hrxml_EndDate_ELEM:
    return zx_ENC_WO_hrxml_EndDate(c, (struct zx_hrxml_EndDate_s*)x, p);
  case zx_hrxml_Role_ELEM:
    return zx_ENC_WO_simple_elem(c, (struct zx_elem_s*)x, p, "Role", sizeof("Role")-1);
  case zx_hrxml_Association_ELEM:
    return zx_ENC_WO_hrxml_Association(c, (struct zx_hrxml_Association_s*)x, p);
  case zx_hrxml_AvailabilityDates_ELEM:
    return zx_ENC_WO_hrxml_AvailabilityDates(c, (struct zx_hrxml_AvailabilityDates_s*)x, p);
  case zx_hrxml_TermOfNotice_ELEM:
    return zx_ENC_WO_hrxml_TermOfNotice(c, (struct zx_hrxml_TermOfNotice_s*)x, p);
  case zx_hrxml_BKZId_ELEM:
    return zx_ENC_WO_hrxml_BKZId(c, (struct zx_hrxml_BKZId_s*)x, p);
  case zx_hrxml_BKZName_ELEM:
    return zx_ENC_WO_simple_elem(c, (struct zx_elem_s*)x, p, "BKZName", sizeof("BKZName")-1);
  case zx_hrxml_BasePayAmountMin_ELEM:
    return zx_ENC_WO_simple_elem(c, (struct zx_elem_s*)x, p, "BasePayAmountMin", sizeof("BasePayAmountMin")-1);
  case zx_hrxml_BasePayAmountMax_ELEM:
    return zx_ENC_WO_simple_elem(c, (struct zx_elem_s*)x, p, "BasePayAmountMax", sizeof("BasePayAmountMax")-1);
  case zx_hrxml_Insurance_ELEM:
    return zx_ENC_WO_hrxml_Insurance(c, (struct zx_hrxml_Insurance_s*)x, p);
  case zx_hrxml_RetirementOrSavingsPlan_ELEM:
    return zx_ENC_WO_simple_elem(c, (struct zx_elem_s*)x, p, "RetirementOrSavingsPlan", sizeof("RetirementOrSavingsPlan")-1);
  case zx_hrxml_CompanyVehicle_ELEM:
    return zx_ENC_WO_hrxml_CompanyVehicle(c, (struct zx_hrxml_CompanyVehicle_s*)x, p);
  case zx_hrxml_RelocationAssistance_ELEM:
    return zx_ENC_WO_hrxml_RelocationAssistance(c, (struct zx_hrxml_RelocationAssistance_s*)x, p);
  case zx_hrxml_VisaSponsorship_ELEM:
    return zx_ENC_WO_simple_elem(c, (struct zx_elem_s*)x, p, "VisaSponsorship", sizeof("VisaSponsorship")-1);
  case zx_hrxml_TimeOffAllowance_ELEM:
    return zx_ENC_WO_hrxml_TimeOffAllowance(c, (struct zx_hrxml_TimeOffAllowance_s*)x, p);
  case zx_hrxml_ExpatriateBenefits_ELEM:
    return zx_ENC_WO_hrxml_ExpatriateBenefits(c, (struct zx_hrxml_ExpatriateBenefits_s*)x, p);
  case zx_hrxml_OtherBenefits_ELEM:
    return zx_ENC_WO_hrxml_OtherBenefits(c, (struct zx_hrxml_OtherBenefits_s*)x, p);
  case zx_hrxml_DateOfBirth_ELEM:
    return zx_ENC_WO_simple_elem(c, (struct zx_elem_s*)x, p, "DateOfBirth", sizeof("DateOfBirth")-1);
  case zx_hrxml_MonthDayOfBirth_ELEM:
    return zx_ENC_WO_simple_elem(c, (struct zx_elem_s*)x, p, "MonthDayOfBirth", sizeof("MonthDayOfBirth")-1);
  case zx_hrxml_Age_ELEM:
    return zx_ENC_WO_simple_elem(c, (struct zx_elem_s*)x, p, "Age", sizeof("Age")-1);
  case zx_hrxml_GenderCode_ELEM:
    return zx_ENC_WO_simple_elem(c, (struct zx_elem_s*)x, p, "GenderCode", sizeof("GenderCode")-1);
  case zx_hrxml_EyeColor_ELEM:
    return zx_ENC_WO_simple_elem(c, (struct zx_elem_s*)x, p, "EyeColor", sizeof("EyeColor")-1);
  case zx_hrxml_HairColor_ELEM:
    return zx_ENC_WO_simple_elem(c, (struct zx_elem_s*)x, p, "HairColor", sizeof("HairColor")-1);
  case zx_hrxml_Height_ELEM:
    return zx_ENC_WO_hrxml_Height(c, (struct zx_hrxml_Height_s*)x, p);
  case zx_hrxml_Weight_ELEM:
    return zx_ENC_WO_hrxml_Weight(c, (struct zx_hrxml_Weight_s*)x, p);
  case zx_hrxml_IdentifyingMarks_ELEM:
    return zx_ENC_WO_simple_elem(c, (struct zx_elem_s*)x, p, "IdentifyingMarks", sizeof("IdentifyingMarks")-1);
  case zx_hrxml_DisabilityInfo_ELEM:
    return zx_ENC_WO_hrxml_DisabilityInfo(c, (struct zx_hrxml_DisabilityInfo_s*)x, p);
  case zx_hrxml_UserArea_ELEM:
    return zx_ENC_WO_hrxml_UserArea(c, (struct zx_hrxml_UserArea_s*)x, p);
  case zx_hrxml_Edition_ELEM:
    return zx_ENC_WO_simple_elem(c, (struct zx_elem_s*)x, p, "Edition", sizeof("Edition")-1);
  case zx_hrxml_Chapter_ELEM:
    return zx_ENC_WO_simple_elem(c, (struct zx_elem_s*)x, p, "Chapter", sizeof("Chapter")-1);
  case zx_hrxml_ISBN_ELEM:
    return zx_ENC_WO_simple_elem(c, (struct zx_elem_s*)x, p, "ISBN", sizeof("ISBN")-1);
  case zx_hrxml_NumberOfPages_ELEM:
    return zx_ENC_WO_simple_elem(c, (struct zx_elem_s*)x, p, "NumberOfPages", sizeof("NumberOfPages")-1);
  case zx_hrxml_PublisherName_ELEM:
    return zx_ENC_WO_simple_elem(c, (struct zx_elem_s*)x, p, "PublisherName", sizeof("PublisherName")-1);
  case zx_hrxml_PublisherLocation_ELEM:
    return zx_ENC_WO_simple_elem(c, (struct zx_elem_s*)x, p, "PublisherLocation", sizeof("PublisherLocation")-1);
  case zx_hrxml_CandidateRecordInfo_ELEM:
    return zx_ENC_WO_hrxml_CandidateRecordInfo(c, (struct zx_hrxml_CandidateRecordInfo_s*)x, p);
  case zx_hrxml_RelatedPositionPostings_ELEM:
    return zx_ENC_WO_hrxml_RelatedPositionPostings(c, (struct zx_hrxml_RelatedPositionPostings_s*)x, p);
  case zx_hrxml_CandidateSupplier_ELEM:
    return zx_ENC_WO_hrxml_CandidateSupplier(c, (struct zx_hrxml_CandidateSupplier_s*)x, p);
  case zx_hrxml_DistributionGuidelines_ELEM:
    return zx_ENC_WO_simple_elem(c, (struct zx_elem_s*)x, p, "DistributionGuidelines", sizeof("DistributionGuidelines")-1);
  case zx_hrxml_CandidateProfile_ELEM:
    return zx_ENC_WO_hrxml_CandidateProfile(c, (struct zx_hrxml_CandidateProfile_s*)x, p);
  case zx_hrxml_Resume_ELEM:
    return zx_ENC_WO_hrxml_Resume(c, (struct zx_hrxml_Resume_s*)x, p);
  case zx_hrxml_ProfileId_ELEM:
    return zx_ENC_WO_hrxml_ProfileId(c, (struct zx_hrxml_ProfileId_s*)x, p);
  case zx_hrxml_ProfileName_ELEM:
    return zx_ENC_WO_simple_elem(c, (struct zx_elem_s*)x, p, "ProfileName", sizeof("ProfileName")-1);
  case zx_hrxml_AvailabilityInfo_ELEM:
    return zx_ENC_WO_hrxml_AvailabilityInfo(c, (struct zx_hrxml_AvailabilityInfo_s*)x, p);
  case zx_hrxml_PersonalData_ELEM:
    return zx_ENC_WO_hrxml_PersonalData(c, (struct zx_hrxml_PersonalData_s*)x, p);
  case zx_hrxml_PreferredPosition_ELEM:
    return zx_ENC_WO_hrxml_PreferredPosition(c, (struct zx_hrxml_PreferredPosition_s*)x, p);
  case zx_hrxml_EmploymentHistory_ELEM:
    return zx_ENC_WO_hrxml_EmploymentHistory(c, (struct zx_hrxml_EmploymentHistory_s*)x, p);
  case zx_hrxml_EducationHistory_ELEM:
    return zx_ENC_WO_hrxml_EducationHistory(c, (struct zx_hrxml_EducationHistory_s*)x, p);
  case zx_hrxml_MilitaryHistory_ELEM:
    return zx_ENC_WO_hrxml_MilitaryHistory(c, (struct zx_hrxml_MilitaryHistory_s*)x, p);
  case zx_hrxml_Associations_ELEM:
    return zx_ENC_WO_hrxml_Associations(c, (struct zx_hrxml_Associations_s*)x, p);
  case zx_hrxml_SupportingMaterials_ELEM:
    return zx_ENC_WO_hrxml_SupportingMaterials(c, (struct zx_hrxml_SupportingMaterials_s*)x, p);
  case zx_hrxml_Status_ELEM:
    return zx_ENC_WO_hrxml_Status(c, (struct zx_hrxml_Status_s*)x, p);
  case zx_hrxml_SupplierId_ELEM:
    return zx_ENC_WO_hrxml_SupplierId(c, (struct zx_hrxml_SupplierId_s*)x, p);
  case zx_hrxml_EntityName_ELEM:
    return zx_ENC_WO_simple_elem(c, (struct zx_elem_s*)x, p, "EntityName", sizeof("EntityName")-1);
  case zx_hrxml_ContactName_ELEM:
    return zx_ENC_WO_hrxml_ContactName(c, (struct zx_hrxml_ContactName_s*)x, p);
  case zx_hrxml_ContactMethod_ELEM:
    return zx_ENC_WO_hrxml_ContactMethod(c, (struct zx_hrxml_ContactMethod_s*)x, p);
  case zx_hrxml_SourceType_ELEM:
    return zx_ENC_WO_hrxml_SourceType(c, (struct zx_hrxml_SourceType_s*)x, p);
  case zx_hrxml_NumberOfChildren_ELEM:
    return zx_ENC_WO_simple_elem(c, (struct zx_elem_s*)x, p, "NumberOfChildren", sizeof("NumberOfChildren")-1);
  case zx_hrxml_TimeMax_ELEM:
    return zx_ENC_WO_hrxml_TimeMax(c, (struct zx_hrxml_TimeMax_s*)x, p);
  case zx_hrxml_DistanceMax_ELEM:
    return zx_ENC_WO_hrxml_DistanceMax(c, (struct zx_hrxml_DistanceMax_s*)x, p);
  case zx_hrxml_StartingCompensation_ELEM:
    return zx_ENC_WO_hrxml_StartingCompensation(c, (struct zx_hrxml_StartingCompensation_s*)x, p);
  case zx_hrxml_EndingCompensation_ELEM:
    return zx_ENC_WO_hrxml_EndingCompensation(c, (struct zx_hrxml_EndingCompensation_s*)x, p);
  case zx_hrxml_OtherCompensation_ELEM:
    return zx_ENC_WO_hrxml_OtherCompensation(c, (struct zx_hrxml_OtherCompensation_s*)x, p);
  case zx_hrxml_CompetencyId_ELEM:
    return zx_ENC_WO_hrxml_CompetencyId(c, (struct zx_hrxml_CompetencyId_s*)x, p);
  case zx_hrxml_TaxonomyId_ELEM:
    return zx_ENC_WO_hrxml_TaxonomyId(c, (struct zx_hrxml_TaxonomyId_s*)x, p);
  case zx_hrxml_CompetencyEvidence_ELEM:
    return zx_ENC_WO_hrxml_CompetencyEvidence(c, (struct zx_hrxml_CompetencyEvidence_s*)x, p);
  case zx_hrxml_CompetencyWeight_ELEM:
    return zx_ENC_WO_hrxml_CompetencyWeight(c, (struct zx_hrxml_CompetencyWeight_s*)x, p);
  case zx_hrxml_Competency_ELEM:
    return zx_ENC_WO_hrxml_Competency(c, (struct zx_hrxml_Competency_s*)x, p);
  case zx_hrxml_EvidenceId_ELEM:
    return zx_ENC_WO_hrxml_EvidenceId(c, (struct zx_hrxml_EvidenceId_s*)x, p);
  case zx_hrxml_NumericValue_ELEM:
    return zx_ENC_WO_hrxml_NumericValue(c, (struct zx_hrxml_NumericValue_s*)x, p);
  case zx_hrxml_StringValue_ELEM:
    return zx_ENC_WO_hrxml_StringValue(c, (struct zx_hrxml_StringValue_s*)x, p);
  case zx_hrxml_SupportingInformation_ELEM:
    return zx_ENC_WO_simple_elem(c, (struct zx_elem_s*)x, p, "SupportingInformation", sizeof("SupportingInformation")-1);
  case zx_hrxml_AnyDate_ELEM:
    return zx_ENC_WO_simple_elem(c, (struct zx_elem_s*)x, p, "AnyDate", sizeof("AnyDate")-1);
  case zx_hrxml_YearMonth_ELEM:
    return zx_ENC_WO_simple_elem(c, (struct zx_elem_s*)x, p, "YearMonth", sizeof("YearMonth")-1);
  case zx_hrxml_Year_ELEM:
    return zx_ENC_WO_simple_elem(c, (struct zx_elem_s*)x, p, "Year", sizeof("Year")-1);
  case zx_hrxml_MonthDay_ELEM:
    return zx_ENC_WO_simple_elem(c, (struct zx_elem_s*)x, p, "MonthDay", sizeof("MonthDay")-1);
  case zx_hrxml_StringDate_ELEM:
    return zx_ENC_WO_simple_elem(c, (struct zx_elem_s*)x, p, "StringDate", sizeof("StringDate")-1);
  case zx_hrxml_EventName_ELEM:
    return zx_ENC_WO_simple_elem(c, (struct zx_elem_s*)x, p, "EventName", sizeof("EventName")-1);
  case zx_hrxml_ConferenceDate_ELEM:
    return zx_ENC_WO_hrxml_ConferenceDate(c, (struct zx_hrxml_ConferenceDate_s*)x, p);
  case zx_hrxml_ConferenceLocation_ELEM:
    return zx_ENC_WO_simple_elem(c, (struct zx_elem_s*)x, p, "ConferenceLocation", sizeof("ConferenceLocation")-1);
  case zx_hrxml_General_ELEM:
    return zx_ENC_WO_simple_elem(c, (struct zx_elem_s*)x, p, "General", sizeof("General")-1);
  case zx_hrxml_Physical_ELEM:
    return zx_ENC_WO_simple_elem(c, (struct zx_elem_s*)x, p, "Physical", sizeof("Physical")-1);
  case zx_hrxml_SafetyEquipment_ELEM:
    return zx_ENC_WO_hrxml_SafetyEquipment(c, (struct zx_hrxml_SafetyEquipment_s*)x, p);
  case zx_hrxml_DressCode_ELEM:
    return zx_ENC_WO_hrxml_DressCode(c, (struct zx_hrxml_DressCode_s*)x, p);
  case zx_hrxml_PersonName_ELEM:
    return zx_ENC_WO_hrxml_PersonName(c, (struct zx_hrxml_PersonName_s*)x, p);
  case zx_hrxml_Use_ELEM:
    return zx_ENC_WO_simple_elem(c, (struct zx_elem_s*)x, p, "Use", sizeof("Use")-1);
  case zx_hrxml_Location_ELEM:
    return zx_ENC_WO_simple_elem(c, (struct zx_elem_s*)x, p, "Location", sizeof("Location")-1);
  case zx_hrxml_WhenAvailable_ELEM:
    return zx_ENC_WO_simple_elem(c, (struct zx_elem_s*)x, p, "WhenAvailable", sizeof("WhenAvailable")-1);
  case zx_hrxml_Telephone_ELEM:
    return zx_ENC_WO_hrxml_Telephone(c, (struct zx_hrxml_Telephone_s*)x, p);
  case zx_hrxml_Mobile_ELEM:
    return zx_ENC_WO_hrxml_Mobile(c, (struct zx_hrxml_Mobile_s*)x, p);
  case zx_hrxml_Fax_ELEM:
    return zx_ENC_WO_hrxml_Fax(c, (struct zx_hrxml_Fax_s*)x, p);
  case zx_hrxml_Pager_ELEM:
    return zx_ENC_WO_hrxml_Pager(c, (struct zx_hrxml_Pager_s*)x, p);
  case zx_hrxml_TTYTDD_ELEM:
    return zx_ENC_WO_hrxml_TTYTDD(c, (struct zx_hrxml_TTYTDD_s*)x, p);
  case zx_hrxml_InternetEmailAddress_ELEM:
    return zx_ENC_WO_simple_elem(c, (struct zx_elem_s*)x, p, "InternetEmailAddress", sizeof("InternetEmailAddress")-1);
  case zx_hrxml_InternetWebAddress_ELEM:
    return zx_ENC_WO_simple_elem(c, (struct zx_elem_s*)x, p, "InternetWebAddress", sizeof("InternetWebAddress")-1);
  case zx_hrxml_PostalAddress_ELEM:
    return zx_ENC_WO_hrxml_PostalAddress(c, (struct zx_hrxml_PostalAddress_s*)x, p);
  case zx_hrxml_AlternateScript_ELEM:
    return zx_ENC_WO_hrxml_AlternateScript(c, (struct zx_hrxml_AlternateScript_s*)x, p);
  case zx_hrxml_CopyrightDates_ELEM:
    return zx_ENC_WO_hrxml_CopyrightDates(c, (struct zx_hrxml_CopyrightDates_s*)x, p);
  case zx_hrxml_CopyrightText_ELEM:
    return zx_ENC_WO_simple_elem(c, (struct zx_elem_s*)x, p, "CopyrightText", sizeof("CopyrightText")-1);
  case zx_hrxml_OriginalDate_ELEM:
    return zx_ENC_WO_hrxml_OriginalDate(c, (struct zx_hrxml_OriginalDate_s*)x, p);
  case zx_hrxml_MostRecentDate_ELEM:
    return zx_ENC_WO_hrxml_MostRecentDate(c, (struct zx_hrxml_MostRecentDate_s*)x, p);
  case zx_hrxml_DegreeName_ELEM:
    return zx_ENC_WO_hrxml_DegreeName(c, (struct zx_hrxml_DegreeName_s*)x, p);
  case zx_hrxml_DegreeDate_ELEM:
    return zx_ENC_WO_hrxml_DegreeDate(c, (struct zx_hrxml_DegreeDate_s*)x, p);
  case zx_hrxml_OtherHonors_ELEM:
    return zx_ENC_WO_hrxml_OtherHonors(c, (struct zx_hrxml_OtherHonors_s*)x, p);
  case zx_hrxml_DegreeMajor_ELEM:
    return zx_ENC_WO_hrxml_DegreeMajor(c, (struct zx_hrxml_DegreeMajor_s*)x, p);
  case zx_hrxml_DegreeMinor_ELEM:
    return zx_ENC_WO_hrxml_DegreeMinor(c, (struct zx_hrxml_DegreeMinor_s*)x, p);
  case zx_hrxml_DegreeMeasure_ELEM:
    return zx_ENC_WO_hrxml_DegreeMeasure(c, (struct zx_hrxml_DegreeMeasure_s*)x, p);
  case zx_hrxml_DatesOfAttendance_ELEM:
    return zx_ENC_WO_hrxml_DatesOfAttendance(c, (struct zx_hrxml_DatesOfAttendance_s*)x, p);
  case zx_hrxml_DegreeClassification_ELEM:
    return zx_ENC_WO_hrxml_DegreeClassification(c, (struct zx_hrxml_DegreeClassification_s*)x, p);
  case zx_hrxml_ProgramId_ELEM:
    return zx_ENC_WO_hrxml_ProgramId(c, (struct zx_hrxml_ProgramId_s*)x, p);
  case zx_hrxml_DegreeConcentration_ELEM:
    return zx_ENC_WO_simple_elem(c, (struct zx_elem_s*)x, p, "DegreeConcentration", sizeof("DegreeConcentration")-1);
  case zx_hrxml_Option_ELEM:
    return zx_ENC_WO_simple_elem(c, (struct zx_elem_s*)x, p, "Option", sizeof("Option")-1);
  case zx_hrxml_EducationalMeasure_ELEM:
    return zx_ENC_WO_hrxml_EducationalMeasure(c, (struct zx_hrxml_EducationalMeasure_s*)x, p);
  case zx_hrxml_AcademicCreditCode_ELEM:
    return zx_ENC_WO_simple_elem(c, (struct zx_elem_s*)x, p, "AcademicCreditCode", sizeof("AcademicCreditCode")-1);
  case zx_hrxml_CourseLevelCode_ELEM:
    return zx_ENC_WO_simple_elem(c, (struct zx_elem_s*)x, p, "CourseLevelCode", sizeof("CourseLevelCode")-1);
  case zx_hrxml_CumulativeSummaryIndicator_ELEM:
    return zx_ENC_WO_simple_elem(c, (struct zx_elem_s*)x, p, "CumulativeSummaryIndicator", sizeof("CumulativeSummaryIndicator")-1);
  case zx_hrxml_AcademicCreditHoursIncluded_ELEM:
    return zx_ENC_WO_simple_elem(c, (struct zx_elem_s*)x, p, "AcademicCreditHoursIncluded", sizeof("AcademicCreditHoursIncluded")-1);
  case zx_hrxml_AcademicCreditHoursAttempted_ELEM:
    return zx_ENC_WO_simple_elem(c, (struct zx_elem_s*)x, p, "AcademicCreditHoursAttempted", sizeof("AcademicCreditHoursAttempted")-1);
  case zx_hrxml_AcademicCreditHoursEarned_ELEM:
    return zx_ENC_WO_simple_elem(c, (struct zx_elem_s*)x, p, "AcademicCreditHoursEarned", sizeof("AcademicCreditHoursEarned")-1);
  case zx_hrxml_ClassRank_ELEM:
    return zx_ENC_WO_hrxml_ClassRank(c, (struct zx_hrxml_ClassRank_s*)x, p);
  case zx_hrxml_AddressLine_ELEM:
    return zx_ENC_WO_simple_elem(c, (struct zx_elem_s*)x, p, "AddressLine", sizeof("AddressLine")-1);
  case zx_hrxml_StreetName_ELEM:
    return zx_ENC_WO_simple_elem(c, (struct zx_elem_s*)x, p, "StreetName", sizeof("StreetName")-1);
  case zx_hrxml_BuildingNumber_ELEM:
    return zx_ENC_WO_simple_elem(c, (struct zx_elem_s*)x, p, "BuildingNumber", sizeof("BuildingNumber")-1);
  case zx_hrxml_Unit_ELEM:
    return zx_ENC_WO_simple_elem(c, (struct zx_elem_s*)x, p, "Unit", sizeof("Unit")-1);
  case zx_hrxml_PostOfficeBox_ELEM:
    return zx_ENC_WO_simple_elem(c, (struct zx_elem_s*)x, p, "PostOfficeBox", sizeof("PostOfficeBox")-1);
  case zx_hrxml_Race_ELEM:
    return zx_ENC_WO_simple_elem(c, (struct zx_elem_s*)x, p, "Race", sizeof("Race")-1);
  case zx_hrxml_Ethnicity_ELEM:
    return zx_ENC_WO_simple_elem(c, (struct zx_elem_s*)x, p, "Ethnicity", sizeof("Ethnicity")-1);
  case zx_hrxml_Nationality_ELEM:
    return zx_ENC_WO_simple_elem(c, (struct zx_elem_s*)x, p, "Nationality", sizeof("Nationality")-1);
  case zx_hrxml_PrimaryLanguage_ELEM:
    return zx_ENC_WO_hrxml_PrimaryLanguage(c, (struct zx_hrxml_PrimaryLanguage_s*)x, p);
  case zx_hrxml_BirthPlace_ELEM:
    return zx_ENC_WO_simple_elem(c, (struct zx_elem_s*)x, p, "BirthPlace", sizeof("BirthPlace")-1);
  case zx_hrxml_Religion_ELEM:
    return zx_ENC_WO_simple_elem(c, (struct zx_elem_s*)x, p, "Religion", sizeof("Religion")-1);
  case zx_hrxml_MaritalStatus_ELEM:
    return zx_ENC_WO_simple_elem(c, (struct zx_elem_s*)x, p, "MaritalStatus", sizeof("MaritalStatus")-1);
  case zx_hrxml_ChildrenInfo_ELEM:
    return zx_ENC_WO_hrxml_ChildrenInfo(c, (struct zx_hrxml_ChildrenInfo_s*)x, p);
  case zx_hrxml_LevelOfDisability_ELEM:
    return zx_ENC_WO_simple_elem(c, (struct zx_elem_s*)x, p, "LevelOfDisability", sizeof("LevelOfDisability")-1);
  case zx_hrxml_Percentage_ELEM:
    return zx_ENC_WO_simple_elem(c, (struct zx_elem_s*)x, p, "Percentage", sizeof("Percentage")-1);
  case zx_hrxml_Type_ELEM:
    return zx_ENC_WO_simple_elem(c, (struct zx_elem_s*)x, p, "Type", sizeof("Type")-1);
  case zx_hrxml_AccommodationsNeeded_ELEM:
    return zx_ENC_WO_simple_elem(c, (struct zx_elem_s*)x, p, "AccommodationsNeeded", sizeof("AccommodationsNeeded")-1);
  case zx_hrxml_StandardValue_ELEM:
    return zx_ENC_WO_simple_elem(c, (struct zx_elem_s*)x, p, "StandardValue", sizeof("StandardValue")-1);
  case zx_hrxml_NonStandardValue_ELEM:
    return zx_ENC_WO_simple_elem(c, (struct zx_elem_s*)x, p, "NonStandardValue", sizeof("NonStandardValue")-1);
  case zx_hrxml_SchoolOrInstitution_ELEM:
    return zx_ENC_WO_hrxml_SchoolOrInstitution(c, (struct zx_hrxml_SchoolOrInstitution_s*)x, p);
  case zx_hrxml_MeasureSystem_ELEM:
    return zx_ENC_WO_simple_elem(c, (struct zx_elem_s*)x, p, "MeasureSystem", sizeof("MeasureSystem")-1);
  case zx_hrxml_MeasureValue_ELEM:
    return zx_ENC_WO_simple_elem(c, (struct zx_elem_s*)x, p, "MeasureValue", sizeof("MeasureValue")-1);
  case zx_hrxml_LowestPossibleValue_ELEM:
    return zx_ENC_WO_hrxml_LowestPossibleValue(c, (struct zx_hrxml_LowestPossibleValue_s*)x, p);
  case zx_hrxml_HighestPossibleValue_ELEM:
    return zx_ENC_WO_hrxml_HighestPossibleValue(c, (struct zx_hrxml_HighestPossibleValue_s*)x, p);
  case zx_hrxml_ExcessiveValueIndicator_ELEM:
    return zx_ENC_WO_simple_elem(c, (struct zx_elem_s*)x, p, "ExcessiveValueIndicator", sizeof("ExcessiveValueIndicator")-1);
  case zx_hrxml_GoodStudentIndicator_ELEM:
    return zx_ENC_WO_simple_elem(c, (struct zx_elem_s*)x, p, "GoodStudentIndicator", sizeof("GoodStudentIndicator")-1);
  case zx_hrxml_LocationSummary_ELEM:
    return zx_ENC_WO_hrxml_LocationSummary(c, (struct zx_hrxml_LocationSummary_s*)x, p);
  case zx_hrxml_InternetDomainName_ELEM:
    return zx_ENC_WO_hrxml_InternetDomainName(c, (struct zx_hrxml_InternetDomainName_s*)x, p);
  case zx_hrxml_EmployerOrgName_ELEM:
    return zx_ENC_WO_simple_elem(c, (struct zx_elem_s*)x, p, "EmployerOrgName", sizeof("EmployerOrgName")-1);
  case zx_hrxml_EmployerContactInfo_ELEM:
    return zx_ENC_WO_hrxml_EmployerContactInfo(c, (struct zx_hrxml_EmployerContactInfo_s*)x, p);
  case zx_hrxml_PositionHistory_ELEM:
    return zx_ENC_WO_hrxml_PositionHistory(c, (struct zx_hrxml_PositionHistory_s*)x, p);
  case zx_hrxml_EmployerOrg_ELEM:
    return zx_ENC_WO_hrxml_EmployerOrg(c, (struct zx_hrxml_EmployerOrg_s*)x, p);
  case zx_hrxml_ExpatriateBenefitsOffered_ELEM:
    return zx_ENC_WO_simple_elem(c, (struct zx_elem_s*)x, p, "ExpatriateBenefitsOffered", sizeof("ExpatriateBenefitsOffered")-1);
  case zx_hrxml_ExpatriateBenefitList_ELEM:
    return zx_ENC_WO_simple_elem(c, (struct zx_elem_s*)x, p, "ExpatriateBenefitList", sizeof("ExpatriateBenefitList")-1);
  case zx_hrxml_FormattedNumber_ELEM:
    return zx_ENC_WO_simple_elem(c, (struct zx_elem_s*)x, p, "FormattedNumber", sizeof("FormattedNumber")-1);
  case zx_hrxml_InventorName_ELEM:
    return zx_ENC_WO_simple_elem(c, (struct zx_elem_s*)x, p, "InventorName", sizeof("InventorName")-1);
  case zx_hrxml_TaxonomyName_ELEM:
    return zx_ENC_WO_hrxml_TaxonomyName(c, (struct zx_hrxml_TaxonomyName_s*)x, p);
  case zx_hrxml_CategoryCode_ELEM:
    return zx_ENC_WO_simple_elem(c, (struct zx_elem_s*)x, p, "CategoryCode", sizeof("CategoryCode")-1);
  case zx_hrxml_CategoryDescription_ELEM:
    return zx_ENC_WO_simple_elem(c, (struct zx_elem_s*)x, p, "CategoryDescription", sizeof("CategoryDescription")-1);
  case zx_hrxml_JobCategory_ELEM:
    return zx_ENC_WO_hrxml_JobCategory(c, (struct zx_hrxml_JobCategory_s*)x, p);
  case zx_hrxml_JobPlan_ELEM:
    return zx_ENC_WO_simple_elem(c, (struct zx_elem_s*)x, p, "JobPlan", sizeof("JobPlan")-1);
  case zx_hrxml_JobGrade_ELEM:
    return zx_ENC_WO_simple_elem(c, (struct zx_elem_s*)x, p, "JobGrade", sizeof("JobGrade")-1);
  case zx_hrxml_JobStep_ELEM:
    return zx_ENC_WO_simple_elem(c, (struct zx_elem_s*)x, p, "JobStep", sizeof("JobStep")-1);
  case zx_hrxml_LanguageCode_ELEM:
    return zx_ENC_WO_hrxml_LanguageCode(c, (struct zx_hrxml_LanguageCode_s*)x, p);
  case zx_hrxml_Read_ELEM:
    return zx_ENC_WO_simple_elem(c, (struct zx_elem_s*)x, p, "Read", sizeof("Read")-1);
  case zx_hrxml_Write_ELEM:
    return zx_ENC_WO_simple_elem(c, (struct zx_elem_s*)x, p, "Write", sizeof("Write")-1);
  case zx_hrxml_Speak_ELEM:
    return zx_ENC_WO_simple_elem(c, (struct zx_elem_s*)x, p, "Speak", sizeof("Speak")-1);
  case zx_hrxml_Language_ELEM:
    return zx_ENC_WO_hrxml_Language(c, (struct zx_hrxml_Language_s*)x, p);
  case zx_hrxml_PersonLegalId_ELEM:
    return zx_ENC_WO_hrxml_PersonLegalId(c, (struct zx_hrxml_PersonLegalId_s*)x, p);
  case zx_hrxml_MilitaryStatus_ELEM:
    return zx_ENC_WO_hrxml_MilitaryStatus(c, (struct zx_hrxml_MilitaryStatus_s*)x, p);
  case zx_hrxml_VisaStatus_ELEM:
    return zx_ENC_WO_hrxml_VisaStatus(c, (struct zx_hrxml_VisaStatus_s*)x, p);
  case zx_hrxml_Citizenship_ELEM:
    return zx_ENC_WO_simple_elem(c, (struct zx_elem_s*)x, p, "Citizenship", sizeof("Citizenship")-1);
  case zx_hrxml_Residency_ELEM:
    return zx_ENC_WO_simple_elem(c, (struct zx_elem_s*)x, p, "Residency", sizeof("Residency")-1);
  case zx_hrxml_EffectiveDate_ELEM:
    return zx_ENC_WO_hrxml_EffectiveDate(c, (struct zx_hrxml_EffectiveDate_s*)x, p);
  case zx_hrxml_LicenseOrCertification_ELEM:
    return zx_ENC_WO_hrxml_LicenseOrCertification(c, (struct zx_hrxml_LicenseOrCertification_s*)x, p);
  case zx_hrxml_Item_ELEM:
    return zx_ENC_WO_simple_elem(c, (struct zx_elem_s*)x, p, "Item", sizeof("Item")-1);
  case zx_hrxml_Municipality_ELEM:
    return zx_ENC_WO_simple_elem(c, (struct zx_elem_s*)x, p, "Municipality", sizeof("Municipality")-1);
  case zx_hrxml_Region_ELEM:
    return zx_ENC_WO_simple_elem(c, (struct zx_elem_s*)x, p, "Region", sizeof("Region")-1);
  case zx_hrxml_CountryCode_ELEM:
    return zx_ENC_WO_simple_elem(c, (struct zx_elem_s*)x, p, "CountryCode", sizeof("CountryCode")-1);
  case zx_hrxml_PostalCode_ELEM:
    return zx_ENC_WO_simple_elem(c, (struct zx_elem_s*)x, p, "PostalCode", sizeof("PostalCode")-1);
  case zx_hrxml_CountryServed_ELEM:
    return zx_ENC_WO_simple_elem(c, (struct zx_elem_s*)x, p, "CountryServed", sizeof("CountryServed")-1);
  case zx_hrxml_ServiceNumber_ELEM:
    return zx_ENC_WO_hrxml_ServiceNumber(c, (struct zx_hrxml_ServiceNumber_s*)x, p);
  case zx_hrxml_ServiceDetail_ELEM:
    return zx_ENC_WO_hrxml_ServiceDetail(c, (struct zx_hrxml_ServiceDetail_s*)x, p);
  case zx_hrxml_ServiceStatus_ELEM:
    return zx_ENC_WO_simple_elem(c, (struct zx_elem_s*)x, p, "ServiceStatus", sizeof("ServiceStatus")-1);
  case zx_hrxml_TextResume_ELEM:
    return zx_ENC_WO_simple_elem(c, (struct zx_elem_s*)x, p, "TextResume", sizeof("TextResume")-1);
  case zx_hrxml_LinkToResume_ELEM:
    return zx_ENC_WO_simple_elem(c, (struct zx_elem_s*)x, p, "LinkToResume", sizeof("LinkToResume")-1);
  case zx_hrxml_RevisionDate_ELEM:
    return zx_ENC_WO_simple_elem(c, (struct zx_elem_s*)x, p, "RevisionDate", sizeof("RevisionDate")-1);
  case zx_hrxml_IndustryDescription_ELEM:
    return zx_ENC_WO_simple_elem(c, (struct zx_elem_s*)x, p, "IndustryDescription", sizeof("IndustryDescription")-1);
  case zx_hrxml_IndustryCode_ELEM:
    return zx_ENC_WO_hrxml_IndustryCode(c, (struct zx_hrxml_IndustryCode_s*)x, p);
  case zx_hrxml_PositionLocation_ELEM:
    return zx_ENC_WO_hrxml_PositionLocation(c, (struct zx_hrxml_PositionLocation_s*)x, p);
  case zx_hrxml_WebSite_ELEM:
    return zx_ENC_WO_simple_elem(c, (struct zx_elem_s*)x, p, "WebSite", sizeof("WebSite")-1);
  case zx_hrxml_OrganizationName_ELEM:
    return zx_ENC_WO_simple_elem(c, (struct zx_elem_s*)x, p, "OrganizationName", sizeof("OrganizationName")-1);
  case zx_hrxml_OrgName_ELEM:
    return zx_ENC_WO_hrxml_OrgName(c, (struct zx_hrxml_OrgName_s*)x, p);
  case zx_hrxml_OrganizationalUnitName_ELEM:
    return zx_ENC_WO_simple_elem(c, (struct zx_elem_s*)x, p, "OrganizationalUnitName", sizeof("OrganizationalUnitName")-1);
  case zx_hrxml_OrganizationalUnitId_ELEM:
    return zx_ENC_WO_hrxml_OrganizationalUnitId(c, (struct zx_hrxml_OrganizationalUnitId_s*)x, p);
  case zx_hrxml_OrganizationId_ELEM:
    return zx_ENC_WO_hrxml_OrganizationId(c, (struct zx_hrxml_OrganizationId_s*)x, p);
  case zx_hrxml_AccountingCode_ELEM:
    return zx_ENC_WO_hrxml_AccountingCode(c, (struct zx_hrxml_AccountingCode_s*)x, p);
  case zx_hrxml_WorkSite_ELEM:
    return zx_ENC_WO_hrxml_WorkSite(c, (struct zx_hrxml_WorkSite_s*)x, p);
  case zx_hrxml_RelatedOrganizationalUnit_ELEM:
    return zx_ENC_WO_hrxml_RelatedOrganizationalUnit(c, (struct zx_hrxml_RelatedOrganizationalUnit_s*)x, p);
  case zx_hrxml_PersonMember_ELEM:
    return zx_ENC_WO_hrxml_PersonMember(c, (struct zx_hrxml_PersonMember_s*)x, p);
  case zx_hrxml_Applicable_ELEM:
    return zx_ENC_WO_simple_elem(c, (struct zx_elem_s*)x, p, "Applicable", sizeof("Applicable")-1);
  case zx_hrxml_List_ELEM:
    return zx_ENC_WO_hrxml_List(c, (struct zx_hrxml_List_s*)x, p);
  case zx_hrxml_OtherPayAmountMin_ELEM:
    return zx_ENC_WO_simple_elem(c, (struct zx_elem_s*)x, p, "OtherPayAmountMin", sizeof("OtherPayAmountMin")-1);
  case zx_hrxml_OtherPayAmountMax_ELEM:
    return zx_ENC_WO_simple_elem(c, (struct zx_elem_s*)x, p, "OtherPayAmountMax", sizeof("OtherPayAmountMax")-1);
  case zx_hrxml_OtherPayCalculation_ELEM:
    return zx_ENC_WO_simple_elem(c, (struct zx_elem_s*)x, p, "OtherPayCalculation", sizeof("OtherPayCalculation")-1);
  case zx_hrxml_PatentTitle_ELEM:
    return zx_ENC_WO_simple_elem(c, (struct zx_elem_s*)x, p, "PatentTitle", sizeof("PatentTitle")-1);
  case zx_hrxml_Inventors_ELEM:
    return zx_ENC_WO_hrxml_Inventors(c, (struct zx_hrxml_Inventors_s*)x, p);
  case zx_hrxml_PatentDetail_ELEM:
    return zx_ENC_WO_hrxml_PatentDetail(c, (struct zx_hrxml_PatentDetail_s*)x, p);
  case zx_hrxml_PatentMilestone_ELEM:
    return zx_ENC_WO_hrxml_PatentMilestone(c, (struct zx_hrxml_PatentMilestone_s*)x, p);
  case zx_hrxml_Patent_ELEM:
    return zx_ENC_WO_hrxml_Patent(c, (struct zx_hrxml_Patent_s*)x, p);
  case zx_hrxml_LegalIdentifiers_ELEM:
    return zx_ENC_WO_hrxml_LegalIdentifiers(c, (struct zx_hrxml_LegalIdentifiers_s*)x, p);
  case zx_hrxml_DemographicDescriptors_ELEM:
    return zx_ENC_WO_hrxml_DemographicDescriptors(c, (struct zx_hrxml_DemographicDescriptors_s*)x, p);
  case zx_hrxml_BiologicalDescriptors_ELEM:
    return zx_ENC_WO_hrxml_BiologicalDescriptors(c, (struct zx_hrxml_BiologicalDescriptors_s*)x, p);
  case zx_hrxml_OtherDescriptors_ELEM:
    return zx_ENC_WO_hrxml_OtherDescriptors(c, (struct zx_hrxml_OtherDescriptors_s*)x, p);
  case zx_hrxml_PersonId_ELEM:
    return zx_ENC_WO_hrxml_PersonId(c, (struct zx_hrxml_PersonId_s*)x, p);
  case zx_hrxml_PersonRole_ELEM:
    return zx_ENC_WO_hrxml_PersonRole(c, (struct zx_hrxml_PersonRole_s*)x, p);
  case zx_hrxml_RoleName_ELEM:
    return zx_ENC_WO_simple_elem(c, (struct zx_elem_s*)x, p, "RoleName", sizeof("RoleName")-1);
  case zx_hrxml_RoleId_ELEM:
    return zx_ENC_WO_hrxml_RoleId(c, (struct zx_hrxml_RoleId_s*)x, p);
  case zx_hrxml_PersonDescriptors_ELEM:
    return zx_ENC_WO_hrxml_PersonDescriptors(c, (struct zx_hrxml_PersonDescriptors_s*)x, p);
  case zx_hrxml_SpatialLocation_ELEM:
    return zx_ENC_WO_hrxml_SpatialLocation(c, (struct zx_hrxml_SpatialLocation_s*)x, p);
  case zx_hrxml_TravelDirections_ELEM:
    return zx_ENC_WO_hrxml_TravelDirections(c, (struct zx_hrxml_TravelDirections_s*)x, p);
  case zx_hrxml_OrgInfo_ELEM:
    return zx_ENC_WO_hrxml_OrgInfo(c, (struct zx_hrxml_OrgInfo_s*)x, p);
  case zx_hrxml_OrgIndustry_ELEM:
    return zx_ENC_WO_hrxml_OrgIndustry(c, (struct zx_hrxml_OrgIndustry_s*)x, p);
  case zx_hrxml_OrgSize_ELEM:
    return zx_ENC_WO_simple_elem(c, (struct zx_elem_s*)x, p, "OrgSize", sizeof("OrgSize")-1);
  case zx_hrxml_Compensation_ELEM:
    return zx_ENC_WO_hrxml_Compensation(c, (struct zx_hrxml_Compensation_s*)x, p);
  case zx_hrxml_Verification_ELEM:
    return zx_ENC_WO_hrxml_Verification(c, (struct zx_hrxml_Verification_s*)x, p);
  case zx_hrxml_JobLevelInfo_ELEM:
    return zx_ENC_WO_hrxml_JobLevelInfo(c, (struct zx_hrxml_JobLevelInfo_s*)x, p);
  case zx_hrxml_DeliveryAddress_ELEM:
    return zx_ENC_WO_hrxml_DeliveryAddress(c, (struct zx_hrxml_DeliveryAddress_s*)x, p);
  case zx_hrxml_Recipient_ELEM:
    return zx_ENC_WO_hrxml_Recipient(c, (struct zx_hrxml_Recipient_s*)x, p);
  case zx_hrxml_Company_ELEM:
    return zx_ENC_WO_hrxml_Company(c, (struct zx_hrxml_Company_s*)x, p);
  case zx_hrxml_CompanyScale_ELEM:
    return zx_ENC_WO_simple_elem(c, (struct zx_elem_s*)x, p, "CompanyScale", sizeof("CompanyScale")-1);
  case zx_hrxml_PhysicalLocation_ELEM:
    return zx_ENC_WO_hrxml_PhysicalLocation(c, (struct zx_hrxml_PhysicalLocation_s*)x, p);
  case zx_hrxml_PositionTitle_ELEM:
    return zx_ENC_WO_simple_elem(c, (struct zx_elem_s*)x, p, "PositionTitle", sizeof("PositionTitle")-1);
  case zx_hrxml_PositionClassification_ELEM:
    return zx_ENC_WO_simple_elem(c, (struct zx_elem_s*)x, p, "PositionClassification", sizeof("PositionClassification")-1);
  case zx_hrxml_PositionSchedule_ELEM:
    return zx_ENC_WO_hrxml_PositionSchedule(c, (struct zx_hrxml_PositionSchedule_s*)x, p);
  case zx_hrxml_Shift_ELEM:
    return zx_ENC_WO_hrxml_Shift(c, (struct zx_hrxml_Shift_s*)x, p);
  case zx_hrxml_RemunerationPackage_ELEM:
    return zx_ENC_WO_hrxml_RemunerationPackage(c, (struct zx_hrxml_RemunerationPackage_s*)x, p);
  case zx_hrxml_WorkStyle_ELEM:
    return zx_ENC_WO_simple_elem(c, (struct zx_elem_s*)x, p, "WorkStyle", sizeof("WorkStyle")-1);
  case zx_hrxml_Travel_ELEM:
    return zx_ENC_WO_hrxml_Travel(c, (struct zx_hrxml_Travel_s*)x, p);
  case zx_hrxml_Relocation_ELEM:
    return zx_ENC_WO_hrxml_Relocation(c, (struct zx_hrxml_Relocation_s*)x, p);
  case zx_hrxml_PreferredLanguage_ELEM:
    return zx_ENC_WO_hrxml_PreferredLanguage(c, (struct zx_hrxml_PreferredLanguage_s*)x, p);
  case zx_hrxml_SearchCriteria_ELEM:
    return zx_ENC_WO_hrxml_SearchCriteria(c, (struct zx_hrxml_SearchCriteria_s*)x, p);
  case zx_hrxml_SearchResult_ELEM:
    return zx_ENC_WO_hrxml_SearchResult(c, (struct zx_hrxml_SearchResult_s*)x, p);
  case zx_hrxml_Commute_ELEM:
    return zx_ENC_WO_hrxml_Commute(c, (struct zx_hrxml_Commute_s*)x, p);
  case zx_hrxml_BasePay_ELEM:
    return zx_ENC_WO_hrxml_BasePay(c, (struct zx_hrxml_BasePay_s*)x, p);
  case zx_hrxml_OtherPay_ELEM:
    return zx_ENC_WO_hrxml_OtherPay(c, (struct zx_hrxml_OtherPay_s*)x, p);
  case zx_hrxml_Benefits_ELEM:
    return zx_ENC_WO_hrxml_Benefits(c, (struct zx_hrxml_Benefits_s*)x, p);
  case zx_hrxml_FormattedPublicationDescription_ELEM:
    return zx_ENC_WO_hrxml_FormattedPublicationDescription(c, (struct zx_hrxml_FormattedPublicationDescription_s*)x, p);
  case zx_hrxml_Article_ELEM:
    return zx_ENC_WO_hrxml_Article(c, (struct zx_hrxml_Article_s*)x, p);
  case zx_hrxml_Book_ELEM:
    return zx_ENC_WO_hrxml_Book(c, (struct zx_hrxml_Book_s*)x, p);
  case zx_hrxml_ConferencePaper_ELEM:
    return zx_ENC_WO_hrxml_ConferencePaper(c, (struct zx_hrxml_ConferencePaper_s*)x, p);
  case zx_hrxml_OtherPublication_ELEM:
    return zx_ENC_WO_hrxml_OtherPublication(c, (struct zx_hrxml_OtherPublication_s*)x, p);
  case zx_hrxml_QualificationSummary_ELEM:
    return zx_ENC_WO_simple_elem(c, (struct zx_elem_s*)x, p, "QualificationSummary", sizeof("QualificationSummary")-1);
  case zx_hrxml_StartRank_ELEM:
    return zx_ENC_WO_simple_elem(c, (struct zx_elem_s*)x, p, "StartRank", sizeof("StartRank")-1);
  case zx_hrxml_CurrentOrEndRank_ELEM:
    return zx_ENC_WO_simple_elem(c, (struct zx_elem_s*)x, p, "CurrentOrEndRank", sizeof("CurrentOrEndRank")-1);
  case zx_hrxml_CriterionName_ELEM:
    return zx_ENC_WO_simple_elem(c, (struct zx_elem_s*)x, p, "CriterionName", sizeof("CriterionName")-1);
  case zx_hrxml_Requested_ELEM:
    return zx_ENC_WO_simple_elem(c, (struct zx_elem_s*)x, p, "Requested", sizeof("Requested")-1);
  case zx_hrxml_Offered_ELEM:
    return zx_ENC_WO_simple_elem(c, (struct zx_elem_s*)x, p, "Offered", sizeof("Offered")-1);
  case zx_hrxml_Score_ELEM:
    return zx_ENC_WO_hrxml_Score(c, (struct zx_hrxml_Score_s*)x, p);
  case zx_hrxml_RankedResult_ELEM:
    return zx_ENC_WO_hrxml_RankedResult(c, (struct zx_hrxml_RankedResult_s*)x, p);
  case zx_hrxml_AdditionalText_ELEM:
    return zx_ENC_WO_simple_elem(c, (struct zx_elem_s*)x, p, "AdditionalText", sizeof("AdditionalText")-1);
  case zx_hrxml_Organization_ELEM:
    return zx_ENC_WO_hrxml_Organization(c, (struct zx_hrxml_Organization_s*)x, p);
  case zx_hrxml_Reference_ELEM:
    return zx_ENC_WO_hrxml_Reference(c, (struct zx_hrxml_Reference_s*)x, p);
  case zx_hrxml_TaxId_ELEM:
    return zx_ENC_WO_hrxml_TaxId(c, (struct zx_hrxml_TaxId_s*)x, p);
  case zx_hrxml_LegalId_ELEM:
    return zx_ENC_WO_hrxml_LegalId(c, (struct zx_hrxml_LegalId_s*)x, p);
  case zx_hrxml_DunsNumber_ELEM:
    return zx_ENC_WO_hrxml_DunsNumber(c, (struct zx_hrxml_DunsNumber_s*)x, p);
  case zx_hrxml_IsPublicCompany_ELEM:
    return zx_ENC_WO_simple_elem(c, (struct zx_elem_s*)x, p, "IsPublicCompany", sizeof("IsPublicCompany")-1);
  case zx_hrxml_Stock_ELEM:
    return zx_ENC_WO_hrxml_Stock(c, (struct zx_hrxml_Stock_s*)x, p);
  case zx_hrxml_MissionStatement_ELEM:
    return zx_ENC_WO_simple_elem(c, (struct zx_elem_s*)x, p, "MissionStatement", sizeof("MissionStatement")-1);
  case zx_hrxml_ValueStatement_ELEM:
    return zx_ENC_WO_simple_elem(c, (struct zx_elem_s*)x, p, "ValueStatement", sizeof("ValueStatement")-1);
  case zx_hrxml_DoingBusinessAs_ELEM:
    return zx_ENC_WO_hrxml_DoingBusinessAs(c, (struct zx_hrxml_DoingBusinessAs_s*)x, p);
  case zx_hrxml_LegalClassification_ELEM:
    return zx_ENC_WO_hrxml_LegalClassification(c, (struct zx_hrxml_LegalClassification_s*)x, p);
  case zx_hrxml_Headcount_ELEM:
    return zx_ENC_WO_simple_elem(c, (struct zx_elem_s*)x, p, "Headcount", sizeof("Headcount")-1);
  case zx_hrxml_ContactInfo_ELEM:
    return zx_ENC_WO_hrxml_ContactInfo(c, (struct zx_hrxml_ContactInfo_s*)x, p);
  case zx_hrxml_RelatedOrganization_ELEM:
    return zx_ENC_WO_hrxml_RelatedOrganization(c, (struct zx_hrxml_RelatedOrganization_s*)x, p);
  case zx_hrxml_OrganizationalUnit_ELEM:
    return zx_ENC_WO_hrxml_OrganizationalUnit(c, (struct zx_hrxml_OrganizationalUnit_s*)x, p);
  case zx_hrxml_PositionPosting_ELEM:
    return zx_ENC_WO_hrxml_PositionPosting(c, (struct zx_hrxml_PositionPosting_s*)x, p);
  case zx_hrxml_ResumeId_ELEM:
    return zx_ENC_WO_simple_elem(c, (struct zx_elem_s*)x, p, "ResumeId", sizeof("ResumeId")-1);
  case zx_hrxml_StructuredXMLResume_ELEM:
    return zx_ENC_WO_hrxml_StructuredXMLResume(c, (struct zx_hrxml_StructuredXMLResume_s*)x, p);
  case zx_hrxml_NonXMLResume_ELEM:
    return zx_ENC_WO_hrxml_NonXMLResume(c, (struct zx_hrxml_NonXMLResume_s*)x, p);
  case zx_hrxml_ResumeAdditionalItem_ELEM:
    return zx_ENC_WO_hrxml_ResumeAdditionalItem(c, (struct zx_hrxml_ResumeAdditionalItem_s*)x, p);
  case zx_hrxml_SchoolId_ELEM:
    return zx_ENC_WO_hrxml_SchoolId(c, (struct zx_hrxml_SchoolId_s*)x, p);
  case zx_hrxml_SchoolName_ELEM:
    return zx_ENC_WO_simple_elem(c, (struct zx_elem_s*)x, p, "SchoolName", sizeof("SchoolName")-1);
  case zx_hrxml_School_ELEM:
    return zx_ENC_WO_hrxml_School(c, (struct zx_hrxml_School_s*)x, p);
  case zx_hrxml_OrganizationUnit_ELEM:
    return zx_ENC_WO_hrxml_OrganizationUnit(c, (struct zx_hrxml_OrganizationUnit_s*)x, p);
  case zx_hrxml_Degree_ELEM:
    return zx_ENC_WO_hrxml_Degree(c, (struct zx_hrxml_Degree_s*)x, p);
  case zx_hrxml_Major_ELEM:
    return zx_ENC_WO_simple_elem(c, (struct zx_elem_s*)x, p, "Major", sizeof("Major")-1);
  case zx_hrxml_Minor_ELEM:
    return zx_ENC_WO_simple_elem(c, (struct zx_elem_s*)x, p, "Minor", sizeof("Minor")-1);
  case zx_hrxml_Measure_ELEM:
    return zx_ENC_WO_hrxml_Measure(c, (struct zx_hrxml_Measure_s*)x, p);
  case zx_hrxml_ISCEDInstitutionClassification_ELEM:
    return zx_ENC_WO_simple_elem(c, (struct zx_elem_s*)x, p, "ISCEDInstitutionClassification", sizeof("ISCEDInstitutionClassification")-1);
  case zx_hrxml_LocalInstitutionClassification_ELEM:
    return zx_ENC_WO_hrxml_LocalInstitutionClassification(c, (struct zx_hrxml_LocalInstitutionClassification_s*)x, p);
  case zx_hrxml_SearchCriteriaId_ELEM:
    return zx_ENC_WO_hrxml_SearchCriteriaId(c, (struct zx_hrxml_SearchCriteriaId_s*)x, p);
  case zx_hrxml_SearchTarget_ELEM:
    return zx_ENC_WO_simple_elem(c, (struct zx_elem_s*)x, p, "SearchTarget", sizeof("SearchTarget")-1);
  case zx_hrxml_UserId_ELEM:
    return zx_ENC_WO_hrxml_UserId(c, (struct zx_hrxml_UserId_s*)x, p);
  case zx_hrxml_SearchTimeStamp_ELEM:
    return zx_ENC_WO_simple_elem(c, (struct zx_elem_s*)x, p, "SearchTimeStamp", sizeof("SearchTimeStamp")-1);
  case zx_hrxml_SearchString_ELEM:
    return zx_ENC_WO_simple_elem(c, (struct zx_elem_s*)x, p, "SearchString", sizeof("SearchString")-1);
  case zx_hrxml_SearchCriterion_ELEM:
    return zx_ENC_WO_hrxml_SearchCriterion(c, (struct zx_hrxml_SearchCriterion_s*)x, p);
  case zx_hrxml_CriterionValue_ELEM:
    return zx_ENC_WO_simple_elem(c, (struct zx_elem_s*)x, p, "CriterionValue", sizeof("CriterionValue")-1);
  case zx_hrxml_SearchResultId_ELEM:
    return zx_ENC_WO_hrxml_SearchResultId(c, (struct zx_hrxml_SearchResultId_s*)x, p);
  case zx_hrxml_MatchedObjectId_ELEM:
    return zx_ENC_WO_hrxml_MatchedObjectId(c, (struct zx_hrxml_MatchedObjectId_s*)x, p);
  case zx_hrxml_SearchRelevanceScore_ELEM:
    return zx_ENC_WO_hrxml_SearchRelevanceScore(c, (struct zx_hrxml_SearchRelevanceScore_s*)x, p);
  case zx_hrxml_SearchRelevanceRank_ELEM:
    return zx_ENC_WO_simple_elem(c, (struct zx_elem_s*)x, p, "SearchRelevanceRank", sizeof("SearchRelevanceRank")-1);
  case zx_hrxml_SearchResultCount_ELEM:
    return zx_ENC_WO_simple_elem(c, (struct zx_elem_s*)x, p, "SearchResultCount", sizeof("SearchResultCount")-1);
  case zx_hrxml_RankedSearchResults_ELEM:
    return zx_ENC_WO_hrxml_RankedSearchResults(c, (struct zx_hrxml_RankedSearchResults_s*)x, p);
  case zx_hrxml_SecurityCredential_ELEM:
    return zx_ENC_WO_hrxml_SecurityCredential(c, (struct zx_hrxml_SecurityCredential_s*)x, p);
  case zx_hrxml_UnitOrDivision_ELEM:
    return zx_ENC_WO_simple_elem(c, (struct zx_elem_s*)x, p, "UnitOrDivision", sizeof("UnitOrDivision")-1);
  case zx_hrxml_RankAchieved_ELEM:
    return zx_ENC_WO_hrxml_RankAchieved(c, (struct zx_hrxml_RankAchieved_s*)x, p);
  case zx_hrxml_DatesOfService_ELEM:
    return zx_ENC_WO_hrxml_DatesOfService(c, (struct zx_hrxml_DatesOfService_s*)x, p);
  case zx_hrxml_Campaign_ELEM:
    return zx_ENC_WO_simple_elem(c, (struct zx_elem_s*)x, p, "Campaign", sizeof("Campaign")-1);
  case zx_hrxml_AreaOfExpertise_ELEM:
    return zx_ENC_WO_simple_elem(c, (struct zx_elem_s*)x, p, "AreaOfExpertise", sizeof("AreaOfExpertise")-1);
  case zx_hrxml_RecognitionAchieved_ELEM:
    return zx_ENC_WO_simple_elem(c, (struct zx_elem_s*)x, p, "RecognitionAchieved", sizeof("RecognitionAchieved")-1);
  case zx_hrxml_DisciplinaryAction_ELEM:
    return zx_ENC_WO_simple_elem(c, (struct zx_elem_s*)x, p, "DisciplinaryAction", sizeof("DisciplinaryAction")-1);
  case zx_hrxml_DischargeStatus_ELEM:
    return zx_ENC_WO_simple_elem(c, (struct zx_elem_s*)x, p, "DischargeStatus", sizeof("DischargeStatus")-1);
  case zx_hrxml_Hours_ELEM:
    return zx_ENC_WO_simple_elem(c, (struct zx_elem_s*)x, p, "Hours", sizeof("Hours")-1);
  case zx_hrxml_StartTime_ELEM:
    return zx_ENC_WO_simple_elem(c, (struct zx_elem_s*)x, p, "StartTime", sizeof("StartTime")-1);
  case zx_hrxml_EndTime_ELEM:
    return zx_ENC_WO_simple_elem(c, (struct zx_elem_s*)x, p, "EndTime", sizeof("EndTime")-1);
  case zx_hrxml_PayTypeHours_ELEM:
    return zx_ENC_WO_simple_elem(c, (struct zx_elem_s*)x, p, "PayTypeHours", sizeof("PayTypeHours")-1);
  case zx_hrxml_Latitude_ELEM:
    return zx_ENC_WO_hrxml_Latitude(c, (struct zx_hrxml_Latitude_s*)x, p);
  case zx_hrxml_Longitude_ELEM:
    return zx_ENC_WO_hrxml_Longitude(c, (struct zx_hrxml_Longitude_s*)x, p);
  case zx_hrxml_Altitude_ELEM:
    return zx_ENC_WO_simple_elem(c, (struct zx_elem_s*)x, p, "Altitude", sizeof("Altitude")-1);
  case zx_hrxml_AltitudeMeanSeaLevel_ELEM:
    return zx_ENC_WO_simple_elem(c, (struct zx_elem_s*)x, p, "AltitudeMeanSeaLevel", sizeof("AltitudeMeanSeaLevel")-1);
  case zx_hrxml_HorizontalAccuracy_ELEM:
    return zx_ENC_WO_hrxml_HorizontalAccuracy(c, (struct zx_hrxml_HorizontalAccuracy_s*)x, p);
  case zx_hrxml_VerticalAccuracy_ELEM:
    return zx_ENC_WO_hrxml_VerticalAccuracy(c, (struct zx_hrxml_VerticalAccuracy_s*)x, p);
  case zx_hrxml_EventType_ELEM:
    return zx_ENC_WO_simple_elem(c, (struct zx_elem_s*)x, p, "EventType", sizeof("EventType")-1);
  case zx_hrxml_AffiliatedOrganization_ELEM:
    return zx_ENC_WO_simple_elem(c, (struct zx_elem_s*)x, p, "AffiliatedOrganization", sizeof("AffiliatedOrganization")-1);
  case zx_hrxml_SpeakingEvent_ELEM:
    return zx_ENC_WO_hrxml_SpeakingEvent(c, (struct zx_hrxml_SpeakingEvent_s*)x, p);
  case zx_hrxml_ProficencyLevel_ELEM:
    return zx_ENC_WO_simple_elem(c, (struct zx_elem_s*)x, p, "ProficencyLevel", sizeof("ProficencyLevel")-1);
  case zx_hrxml_Symbol_ELEM:
    return zx_ENC_WO_simple_elem(c, (struct zx_elem_s*)x, p, "Symbol", sizeof("Symbol")-1);
  case zx_hrxml_Exchange_ELEM:
    return zx_ENC_WO_simple_elem(c, (struct zx_elem_s*)x, p, "Exchange", sizeof("Exchange")-1);
  case zx_hrxml_ExecutiveSummary_ELEM:
    return zx_ENC_WO_simple_elem(c, (struct zx_elem_s*)x, p, "ExecutiveSummary", sizeof("ExecutiveSummary")-1);
  case zx_hrxml_Objective_ELEM:
    return zx_ENC_WO_simple_elem(c, (struct zx_elem_s*)x, p, "Objective", sizeof("Objective")-1);
  case zx_hrxml_LicensesAndCertifications_ELEM:
    return zx_ENC_WO_hrxml_LicensesAndCertifications(c, (struct zx_hrxml_LicensesAndCertifications_s*)x, p);
  case zx_hrxml_PatentHistory_ELEM:
    return zx_ENC_WO_hrxml_PatentHistory(c, (struct zx_hrxml_PatentHistory_s*)x, p);
  case zx_hrxml_PublicationHistory_ELEM:
    return zx_ENC_WO_hrxml_PublicationHistory(c, (struct zx_hrxml_PublicationHistory_s*)x, p);
  case zx_hrxml_SpeakingEventsHistory_ELEM:
    return zx_ENC_WO_hrxml_SpeakingEventsHistory(c, (struct zx_hrxml_SpeakingEventsHistory_s*)x, p);
  case zx_hrxml_Qualifications_ELEM:
    return zx_ENC_WO_hrxml_Qualifications(c, (struct zx_hrxml_Qualifications_s*)x, p);
  case zx_hrxml_Languages_ELEM:
    return zx_ENC_WO_hrxml_Languages(c, (struct zx_hrxml_Languages_s*)x, p);
  case zx_hrxml_Achievements_ELEM:
    return zx_ENC_WO_hrxml_Achievements(c, (struct zx_hrxml_Achievements_s*)x, p);
  case zx_hrxml_References_ELEM:
    return zx_ENC_WO_hrxml_References(c, (struct zx_hrxml_References_s*)x, p);
  case zx_hrxml_SecurityCredentials_ELEM:
    return zx_ENC_WO_hrxml_SecurityCredentials(c, (struct zx_hrxml_SecurityCredentials_s*)x, p);
  case zx_hrxml_ResumeAdditionalItems_ELEM:
    return zx_ENC_WO_hrxml_ResumeAdditionalItems(c, (struct zx_hrxml_ResumeAdditionalItems_s*)x, p);
  case zx_hrxml_ProfessionalAssociations_ELEM:
    return zx_ENC_WO_hrxml_ProfessionalAssociations(c, (struct zx_hrxml_ProfessionalAssociations_s*)x, p);
  case zx_hrxml_AttachmentReference_ELEM:
    return zx_ENC_WO_hrxml_AttachmentReference(c, (struct zx_hrxml_AttachmentReference_s*)x, p);
  case zx_hrxml_Interval_ELEM:
    return zx_ENC_WO_simple_elem(c, (struct zx_elem_s*)x, p, "Interval", sizeof("Interval")-1);
  case zx_hrxml_TravelFrequency_ELEM:
    return zx_ENC_WO_simple_elem(c, (struct zx_elem_s*)x, p, "TravelFrequency", sizeof("TravelFrequency")-1);
  case zx_hrxml_TravelConsiderations_ELEM:
    return zx_ENC_WO_simple_elem(c, (struct zx_elem_s*)x, p, "TravelConsiderations", sizeof("TravelConsiderations")-1);
  case zx_hrxml_ReasonForLeaving_ELEM:
    return zx_ENC_WO_simple_elem(c, (struct zx_elem_s*)x, p, "ReasonForLeaving", sizeof("ReasonForLeaving")-1);
  case zx_hrxml_PermissionToContact_ELEM:
    return zx_ENC_WO_simple_elem(c, (struct zx_elem_s*)x, p, "PermissionToContact", sizeof("PermissionToContact")-1);
  case zx_hrxml_VerifyEmployment_ELEM:
    return zx_ENC_WO_simple_elem(c, (struct zx_elem_s*)x, p, "VerifyEmployment", sizeof("VerifyEmployment")-1);
  case zx_hrxml_EligibleForRehire_ELEM:
    return zx_ENC_WO_simple_elem(c, (struct zx_elem_s*)x, p, "EligibleForRehire", sizeof("EligibleForRehire")-1);
  case zx_hrxml_AttendanceRating_ELEM:
    return zx_ENC_WO_simple_elem(c, (struct zx_elem_s*)x, p, "AttendanceRating", sizeof("AttendanceRating")-1);
  case zx_hrxml_OverallPerformanceRating_ELEM:
    return zx_ENC_WO_simple_elem(c, (struct zx_elem_s*)x, p, "OverallPerformanceRating", sizeof("OverallPerformanceRating")-1);
  case zx_hrxml_QuestionAnswerPair_ELEM:
    return zx_ENC_WO_simple_elem(c, (struct zx_elem_s*)x, p, "QuestionAnswerPair", sizeof("QuestionAnswerPair")-1);
  case zx_hrxml_WorkSiteName_ELEM:
    return zx_ENC_WO_simple_elem(c, (struct zx_elem_s*)x, p, "WorkSiteName", sizeof("WorkSiteName")-1);
  case zx_hrxml_WorkSiteId_ELEM:
    return zx_ENC_WO_hrxml_WorkSiteId(c, (struct zx_hrxml_WorkSiteId_s*)x, p);
  case zx_hrxml_Details_ELEM:
    return zx_ENC_WO_hrxml_Details(c, (struct zx_hrxml_Details_s*)x, p);
  case zx_hrxml_ParkingInstructions_ELEM:
    return zx_ENC_WO_hrxml_ParkingInstructions(c, (struct zx_hrxml_ParkingInstructions_s*)x, p);
  case zx_hrxml_WorkSiteEnvironment_ELEM:
    return zx_ENC_WO_hrxml_WorkSiteEnvironment(c, (struct zx_hrxml_WorkSiteEnvironment_s*)x, p);
  case zx_hrxml_EnvironmentName_ELEM:
    return zx_ENC_WO_simple_elem(c, (struct zx_elem_s*)x, p, "EnvironmentName", sizeof("EnvironmentName")-1);
  case zx_hrxml_EnvironmentId_ELEM:
    return zx_ENC_WO_hrxml_EnvironmentId(c, (struct zx_hrxml_EnvironmentId_s*)x, p);
  case zx_hrxml_Considerations_ELEM:
    return zx_ENC_WO_hrxml_Considerations(c, (struct zx_hrxml_Considerations_s*)x, p);
  case zx_idhrxml_Subscription_ELEM:
    return zx_ENC_WO_idhrxml_Subscription(c, (struct zx_idhrxml_Subscription_s*)x, p);
  case zx_idhrxml_CreateItem_ELEM:
    return zx_ENC_WO_idhrxml_CreateItem(c, (struct zx_idhrxml_CreateItem_s*)x, p);
  case zx_idhrxml_ResultQuery_ELEM:
    return zx_ENC_WO_idhrxml_ResultQuery(c, (struct zx_idhrxml_ResultQuery_s*)x, p);
  case zx_idhrxml_NewData_ELEM:
    return zx_ENC_WO_idhrxml_NewData(c, (struct zx_idhrxml_NewData_s*)x, p);
  case zx_idhrxml_ItemData_ELEM:
    return zx_ENC_WO_idhrxml_ItemData(c, (struct zx_idhrxml_ItemData_s*)x, p);
  case zx_hrxml_Candidate_ELEM:
    return zx_ENC_WO_hrxml_Candidate(c, (struct zx_hrxml_Candidate_s*)x, p);
  case zx_idhrxml_DeleteItem_ELEM:
    return zx_ENC_WO_idhrxml_DeleteItem(c, (struct zx_idhrxml_DeleteItem_s*)x, p);
  case zx_idhrxml_Select_ELEM:
    return zx_ENC_WO_simple_elem(c, (struct zx_elem_s*)x, p, "Select", sizeof("Select")-1);
  case zx_idhrxml_ModifyItem_ELEM:
    return zx_ENC_WO_idhrxml_ModifyItem(c, (struct zx_idhrxml_ModifyItem_s*)x, p);
  case zx_idhrxml_Notification_ELEM:
    return zx_ENC_WO_idhrxml_Notification(c, (struct zx_idhrxml_Notification_s*)x, p);
  case zx_idhrxml_TestItem_ELEM:
    return zx_ENC_WO_idhrxml_TestItem(c, (struct zx_idhrxml_TestItem_s*)x, p);
  case zx_idhrxml_QueryItem_ELEM:
    return zx_ENC_WO_idhrxml_QueryItem(c, (struct zx_idhrxml_QueryItem_s*)x, p);
  case zx_idhrxml_Sort_ELEM:
    return zx_ENC_WO_simple_elem(c, (struct zx_elem_s*)x, p, "Sort", sizeof("Sort")-1);
  case zx_idhrxml_Data_ELEM:
    return zx_ENC_WO_idhrxml_Data(c, (struct zx_idhrxml_Data_s*)x, p);
  case zx_idhrxml_Aggregation_ELEM:
    return zx_ENC_WO_simple_elem(c, (struct zx_elem_s*)x, p, "Aggregation", sizeof("Aggregation")-1);
  case zx_idhrxml_Trigger_ELEM:
    return zx_ENC_WO_simple_elem(c, (struct zx_elem_s*)x, p, "Trigger", sizeof("Trigger")-1);
  case zx_idhrxml_TestOp_ELEM:
    return zx_ENC_WO_simple_elem(c, (struct zx_elem_s*)x, p, "TestOp", sizeof("TestOp")-1);
  case zx_idp_MEDInfo_ELEM:
    return zx_ENC_WO_idp_MEDInfo(c, (struct zx_idp_MEDInfo_s*)x, p);
  case zx_sa_AuthnContext_ELEM:
    return zx_ENC_WO_sa_AuthnContext(c, (struct zx_sa_AuthnContext_s*)x, p);
  case zx_idp_CreatedStatusItem_ELEM:
    return zx_ENC_WO_idp_CreatedStatusItem(c, (struct zx_idp_CreatedStatusItem_s*)x, p);
  case zx_idp_GetAssertionResponseItem_ELEM:
    return zx_ENC_WO_idp_GetAssertionResponseItem(c, (struct zx_idp_GetAssertionResponseItem_s*)x, p);
  case zx_idp_AssertionItem_ELEM:
    return zx_ENC_WO_idp_AssertionItem(c, (struct zx_idp_AssertionItem_s*)x, p);
  case zx_idp_ProviderID_ELEM:
    return zx_ENC_WO_simple_elem(c, (struct zx_elem_s*)x, p, "ProviderID", sizeof("ProviderID")-1);
  case zx_idp_ProviderInfo_ELEM:
    return zx_ENC_WO_idp_ProviderInfo(c, (struct zx_idp_ProviderInfo_s*)x, p);
  case zx_sa_NameID_ELEM:
    return zx_ENC_WO_sa_NameID(c, (struct zx_sa_NameID_s*)x, p);
  case zx_sa_AttributeStatement_ELEM:
    return zx_ENC_WO_sa_AttributeStatement(c, (struct zx_sa_AttributeStatement_s*)x, p);
  case zx_sa_Subject_ELEM:
    return zx_ENC_WO_sa_Subject(c, (struct zx_sa_Subject_s*)x, p);
  case zx_im_MappingInput_ELEM:
    return zx_ENC_WO_im_MappingInput(c, (struct zx_im_MappingInput_s*)x, p);
  case zx_im_MappingOutput_ELEM:
    return zx_ENC_WO_im_MappingOutput(c, (struct zx_im_MappingOutput_s*)x, p);
  case zx_sec_TokenPolicy_ELEM:
    return zx_ENC_WO_sec_TokenPolicy(c, (struct zx_sec_TokenPolicy_s*)x, p);
  case zx_is_Help_ELEM:
    return zx_ENC_WO_is_Help(c, (struct zx_is_Help_s*)x, p);
  case zx_is_Hint_ELEM:
    return zx_ENC_WO_simple_elem(c, (struct zx_elem_s*)x, p, "Hint", sizeof("Hint")-1);
  case zx_is_Label_ELEM:
    return zx_ENC_WO_simple_elem(c, (struct zx_elem_s*)x, p, "Label", sizeof("Label")-1);
  case zx_is_Value_ELEM:
    return zx_ENC_WO_simple_elem(c, (struct zx_elem_s*)x, p, "Value", sizeof("Value")-1);
  case zx_is_Select_ELEM:
    return zx_ENC_WO_is_Select(c, (struct zx_is_Select_s*)x, p);
  case zx_is_Confirm_ELEM:
    return zx_ENC_WO_is_Confirm(c, (struct zx_is_Confirm_s*)x, p);
  case zx_is_Text_ELEM:
    return zx_ENC_WO_is_Text(c, (struct zx_is_Text_s*)x, p);
  case zx_is_Inquiry_ELEM:
    return zx_ENC_WO_is_Inquiry(c, (struct zx_is_Inquiry_s*)x, p);
  case zx_is_InteractionStatement_ELEM:
    return zx_ENC_WO_is_InteractionStatement(c, (struct zx_is_InteractionStatement_s*)x, p);
  case zx_is_Parameter_ELEM:
    return zx_ENC_WO_is_Parameter(c, (struct zx_is_Parameter_s*)x, p);
  case zx_is_Item_ELEM:
    return zx_ENC_WO_is_Item(c, (struct zx_is_Item_s*)x, p);
  case zx_is12_Help_ELEM:
    return zx_ENC_WO_is12_Help(c, (struct zx_is12_Help_s*)x, p);
  case zx_is12_Hint_ELEM:
    return zx_ENC_WO_simple_elem(c, (struct zx_elem_s*)x, p, "Hint", sizeof("Hint")-1);
  case zx_is12_Label_ELEM:
    return zx_ENC_WO_simple_elem(c, (struct zx_elem_s*)x, p, "Label", sizeof("Label")-1);
  case zx_is12_Value_ELEM:
    return zx_ENC_WO_simple_elem(c, (struct zx_elem_s*)x, p, "Value", sizeof("Value")-1);
  case zx_is12_Select_ELEM:
    return zx_ENC_WO_is12_Select(c, (struct zx_is12_Select_s*)x, p);
  case zx_is12_Confirm_ELEM:
    return zx_ENC_WO_is12_Confirm(c, (struct zx_is12_Confirm_s*)x, p);
  case zx_is12_Text_ELEM:
    return zx_ENC_WO_is12_Text(c, (struct zx_is12_Text_s*)x, p);
  case zx_is12_Inquiry_ELEM:
    return zx_ENC_WO_is12_Inquiry(c, (struct zx_is12_Inquiry_s*)x, p);
  case zx_is12_Status_ELEM:
    return zx_ENC_WO_is12_Status(c, (struct zx_is12_Status_s*)x, p);
  case zx_is12_InteractionStatement_ELEM:
    return zx_ENC_WO_is12_InteractionStatement(c, (struct zx_is12_InteractionStatement_s*)x, p);
  case zx_is12_Parameter_ELEM:
    return zx_ENC_WO_is12_Parameter(c, (struct zx_is12_Parameter_s*)x, p);
  case zx_is12_Item_ELEM:
    return zx_ENC_WO_is12_Item(c, (struct zx_is12_Item_s*)x, p);
  case zx_is12_InteractionService_ELEM:
    return zx_ENC_WO_is12_InteractionService(c, (struct zx_is12_InteractionService_s*)x, p);
  case zx_m20_AffiliateMember_ELEM:
    return zx_ENC_WO_simple_elem(c, (struct zx_elem_s*)x, p, "AffiliateMember", sizeof("AffiliateMember")-1);
  case zx_m20_Extension_ELEM:
    return zx_ENC_WO_m20_Extension(c, (struct zx_m20_Extension_s*)x, p);
  case zx_m20_KeyDescriptor_ELEM:
    return zx_ENC_WO_m20_KeyDescriptor(c, (struct zx_m20_KeyDescriptor_s*)x, p);
  case zx_m20_Company_ELEM:
    return zx_ENC_WO_simple_elem(c, (struct zx_elem_s*)x, p, "Company", sizeof("Company")-1);
  case zx_m20_GivenName_ELEM:
    return zx_ENC_WO_simple_elem(c, (struct zx_elem_s*)x, p, "GivenName", sizeof("GivenName")-1);
  case zx_m20_SurName_ELEM:
    return zx_ENC_WO_simple_elem(c, (struct zx_elem_s*)x, p, "SurName", sizeof("SurName")-1);
  case zx_m20_EmailAddress_ELEM:
    return zx_ENC_WO_simple_elem(c, (struct zx_elem_s*)x, p, "EmailAddress", sizeof("EmailAddress")-1);
  case zx_m20_TelephoneNumber_ELEM:
    return zx_ENC_WO_simple_elem(c, (struct zx_elem_s*)x, p, "TelephoneNumber", sizeof("TelephoneNumber")-1);
  case zx_m20_EntityDescriptor_ELEM:
    return zx_ENC_WO_m20_EntityDescriptor(c, (struct zx_m20_EntityDescriptor_s*)x, p);
  case zx_m20_IDPDescriptor_ELEM:
    return zx_ENC_WO_m20_IDPDescriptor(c, (struct zx_m20_IDPDescriptor_s*)x, p);
  case zx_m20_SPDescriptor_ELEM:
    return zx_ENC_WO_m20_SPDescriptor(c, (struct zx_m20_SPDescriptor_s*)x, p);
  case zx_m20_AffiliationDescriptor_ELEM:
    return zx_ENC_WO_m20_AffiliationDescriptor(c, (struct zx_m20_AffiliationDescriptor_s*)x, p);
  case zx_m20_ContactPerson_ELEM:
    return zx_ENC_WO_m20_ContactPerson(c, (struct zx_m20_ContactPerson_s*)x, p);
  case zx_m20_Organization_ELEM:
    return zx_ENC_WO_m20_Organization(c, (struct zx_m20_Organization_s*)x, p);
  case zx_m20_SoapEndpoint_ELEM:
    return zx_ENC_WO_simple_elem(c, (struct zx_elem_s*)x, p, "SoapEndpoint", sizeof("SoapEndpoint")-1);
  case zx_m20_SingleLogoutServiceURL_ELEM:
    return zx_ENC_WO_simple_elem(c, (struct zx_elem_s*)x, p, "SingleLogoutServiceURL", sizeof("SingleLogoutServiceURL")-1);
  case zx_m20_SingleLogoutServiceReturnURL_ELEM:
    return zx_ENC_WO_simple_elem(c, (struct zx_elem_s*)x, p, "SingleLogoutServiceReturnURL", sizeof("SingleLogoutServiceReturnURL")-1);
  case zx_m20_FederationTerminationServiceURL_ELEM:
    return zx_ENC_WO_simple_elem(c, (struct zx_elem_s*)x, p, "FederationTerminationServiceURL", sizeof("FederationTerminationServiceURL")-1);
  case zx_m20_FederationTerminationServiceReturnURL_ELEM:
    return zx_ENC_WO_simple_elem(c, (struct zx_elem_s*)x, p, "FederationTerminationServiceReturnURL", sizeof("FederationTerminationServiceReturnURL")-1);
  case zx_m20_FederationTerminationNotificationProtocolProfile_ELEM:
    return zx_ENC_WO_simple_elem(c, (struct zx_elem_s*)x, p, "FederationTerminationNotificationProtocolProfile", sizeof("FederationTerminationNotificationProtocolProfile")-1);
  case zx_m20_SingleLogoutProtocolProfile_ELEM:
    return zx_ENC_WO_simple_elem(c, (struct zx_elem_s*)x, p, "SingleLogoutProtocolProfile", sizeof("SingleLogoutProtocolProfile")-1);
  case zx_m20_RegisterNameIdentifierProtocolProfile_ELEM:
    return zx_ENC_WO_simple_elem(c, (struct zx_elem_s*)x, p, "RegisterNameIdentifierProtocolProfile", sizeof("RegisterNameIdentifierProtocolProfile")-1);
  case zx_m20_RegisterNameIdentifierServiceURL_ELEM:
    return zx_ENC_WO_simple_elem(c, (struct zx_elem_s*)x, p, "RegisterNameIdentifierServiceURL", sizeof("RegisterNameIdentifierServiceURL")-1);
  case zx_m20_RegisterNameIdentifierServiceReturnURL_ELEM:
    return zx_ENC_WO_simple_elem(c, (struct zx_elem_s*)x, p, "RegisterNameIdentifierServiceReturnURL", sizeof("RegisterNameIdentifierServiceReturnURL")-1);
  case zx_m20_NameIdentifierMappingProtocolProfile_ELEM:
    return zx_ENC_WO_simple_elem(c, (struct zx_elem_s*)x, p, "NameIdentifierMappingProtocolProfile", sizeof("NameIdentifierMappingProtocolProfile")-1);
  case zx_m20_NameIdentifierMappingEncryptionProfile_ELEM:
    return zx_ENC_WO_simple_elem(c, (struct zx_elem_s*)x, p, "NameIdentifierMappingEncryptionProfile", sizeof("NameIdentifierMappingEncryptionProfile")-1);
  case zx_m20_AdditionalMetaLocation_ELEM:
    return zx_ENC_WO_m20_AdditionalMetaLocation(c, (struct zx_m20_AdditionalMetaLocation_s*)x, p);
  case zx_m20_SingleSignOnServiceURL_ELEM:
    return zx_ENC_WO_simple_elem(c, (struct zx_elem_s*)x, p, "SingleSignOnServiceURL", sizeof("SingleSignOnServiceURL")-1);
  case zx_m20_SingleSignOnProtocolProfile_ELEM:
    return zx_ENC_WO_simple_elem(c, (struct zx_elem_s*)x, p, "SingleSignOnProtocolProfile", sizeof("SingleSignOnProtocolProfile")-1);
  case zx_m20_AuthnServiceURL_ELEM:
    return zx_ENC_WO_simple_elem(c, (struct zx_elem_s*)x, p, "AuthnServiceURL", sizeof("AuthnServiceURL")-1);
  case zx_m20_EncryptionMethod_ELEM:
    return zx_ENC_WO_simple_elem(c, (struct zx_elem_s*)x, p, "EncryptionMethod", sizeof("EncryptionMethod")-1);
  case zx_m20_KeySize_ELEM:
    return zx_ENC_WO_simple_elem(c, (struct zx_elem_s*)x, p, "KeySize", sizeof("KeySize")-1);
  case zx_m20_OrganizationName_ELEM:
    return zx_ENC_WO_m20_OrganizationName(c, (struct zx_m20_OrganizationName_s*)x, p);
  case zx_m20_OrganizationDisplayName_ELEM:
    return zx_ENC_WO_m20_OrganizationDisplayName(c, (struct zx_m20_OrganizationDisplayName_s*)x, p);
  case zx_m20_OrganizationURL_ELEM:
    return zx_ENC_WO_m20_OrganizationURL(c, (struct zx_m20_OrganizationURL_s*)x, p);
  case zx_m20_AssertionConsumerServiceURL_ELEM:
    return zx_ENC_WO_m20_AssertionConsumerServiceURL(c, (struct zx_m20_AssertionConsumerServiceURL_s*)x, p);
  case zx_m20_AuthnRequestsSigned_ELEM:
    return zx_ENC_WO_simple_elem(c, (struct zx_elem_s*)x, p, "AuthnRequestsSigned", sizeof("AuthnRequestsSigned")-1);
  case zx_md_Extensions_ELEM:
    return zx_ENC_WO_md_Extensions(c, (struct zx_md_Extensions_s*)x, p);
  case zx_md_AffiliateMember_ELEM:
    return zx_ENC_WO_simple_elem(c, (struct zx_elem_s*)x, p, "AffiliateMember", sizeof("AffiliateMember")-1);
  case zx_md_Organization_ELEM:
    return zx_ENC_WO_md_Organization(c, (struct zx_md_Organization_s*)x, p);
  case zx_md_ContactPerson_ELEM:
    return zx_ENC_WO_md_ContactPerson(c, (struct zx_md_ContactPerson_s*)x, p);
  case zx_md_AttributeService_ELEM:
    return zx_ENC_WO_md_AttributeService(c, (struct zx_md_AttributeService_s*)x, p);
  case zx_md_AssertionIDRequestService_ELEM:
    return zx_ENC_WO_md_AssertionIDRequestService(c, (struct zx_md_AssertionIDRequestService_s*)x, p);
  case zx_md_NameIDFormat_ELEM:
    return zx_ENC_WO_simple_elem(c, (struct zx_elem_s*)x, p, "NameIDFormat", sizeof("NameIDFormat")-1);
  case zx_md_AttributeProfile_ELEM:
    return zx_ENC_WO_simple_elem(c, (struct zx_elem_s*)x, p, "AttributeProfile", sizeof("AttributeProfile")-1);
  case zx_sa_Attribute_ELEM:
    return zx_ENC_WO_sa_Attribute(c, (struct zx_sa_Attribute_s*)x, p);
  case zx_md_ServiceName_ELEM:
    return zx_ENC_WO_md_ServiceName(c, (struct zx_md_ServiceName_s*)x, p);
  case zx_md_ServiceDescription_ELEM:
    return zx_ENC_WO_md_ServiceDescription(c, (struct zx_md_ServiceDescription_s*)x, p);
  case zx_md_RequestedAttribute_ELEM:
    return zx_ENC_WO_md_RequestedAttribute(c, (struct zx_md_RequestedAttribute_s*)x, p);
  case zx_md_AuthnQueryService_ELEM:
    return zx_ENC_WO_md_AuthnQueryService(c, (struct zx_md_AuthnQueryService_s*)x, p);
  case zx_md_Company_ELEM:
    return zx_ENC_WO_simple_elem(c, (struct zx_elem_s*)x, p, "Company", sizeof("Company")-1);
  case zx_md_GivenName_ELEM:
    return zx_ENC_WO_simple_elem(c, (struct zx_elem_s*)x, p, "GivenName", sizeof("GivenName")-1);
  case zx_md_SurName_ELEM:
    return zx_ENC_WO_simple_elem(c, (struct zx_elem_s*)x, p, "SurName", sizeof("SurName")-1);
  case zx_md_EmailAddress_ELEM:
    return zx_ENC_WO_simple_elem(c, (struct zx_elem_s*)x, p, "EmailAddress", sizeof("EmailAddress")-1);
  case zx_md_TelephoneNumber_ELEM:
    return zx_ENC_WO_simple_elem(c, (struct zx_elem_s*)x, p, "TelephoneNumber", sizeof("TelephoneNumber")-1);
  case zx_xenc_KeySize_ELEM:
    return zx_ENC_WO_simple_elem(c, (struct zx_elem_s*)x, p, "KeySize", sizeof("KeySize")-1);
  case zx_xenc_OAEPparams_ELEM:
    return zx_ENC_WO_simple_elem(c, (struct zx_elem_s*)x, p, "OAEPparams", sizeof("OAEPparams")-1);
  case zx_md_EntityDescriptor_ELEM:
    return zx_ENC_WO_md_EntityDescriptor(c, (struct zx_md_EntityDescriptor_s*)x, p);
  case zx_md_EntitiesDescriptor_ELEM:
    return zx_ENC_WO_md_EntitiesDescriptor(c, (struct zx_md_EntitiesDescriptor_s*)x, p);
  case zx_md_RoleDescriptor_ELEM:
    return zx_ENC_WO_md_RoleDescriptor(c, (struct zx_md_RoleDescriptor_s*)x, p);
  case zx_md_IDPSSODescriptor_ELEM:
    return zx_ENC_WO_md_IDPSSODescriptor(c, (struct zx_md_IDPSSODescriptor_s*)x, p);
  case zx_md_SPSSODescriptor_ELEM:
    return zx_ENC_WO_md_SPSSODescriptor(c, (struct zx_md_SPSSODescriptor_s*)x, p);
  case zx_md_AuthnAuthorityDescriptor_ELEM:
    return zx_ENC_WO_md_AuthnAuthorityDescriptor(c, (struct zx_md_AuthnAuthorityDescriptor_s*)x, p);
  case zx_md_AttributeAuthorityDescriptor_ELEM:
    return zx_ENC_WO_md_AttributeAuthorityDescriptor(c, (struct zx_md_AttributeAuthorityDescriptor_s*)x, p);
  case zx_md_PDPDescriptor_ELEM:
    return zx_ENC_WO_md_PDPDescriptor(c, (struct zx_md_PDPDescriptor_s*)x, p);
  case zx_md_AffiliationDescriptor_ELEM:
    return zx_ENC_WO_md_AffiliationDescriptor(c, (struct zx_md_AffiliationDescriptor_s*)x, p);
  case zx_md_AdditionalMetadataLocation_ELEM:
    return zx_ENC_WO_md_AdditionalMetadataLocation(c, (struct zx_md_AdditionalMetadataLocation_s*)x, p);
  case zx_shibmd_Scope_ELEM:
    return zx_ENC_WO_shibmd_Scope(c, (struct zx_shibmd_Scope_s*)x, p);
  case zx_shibmd_KeyAuthority_ELEM:
    return zx_ENC_WO_shibmd_KeyAuthority(c, (struct zx_shibmd_KeyAuthority_s*)x, p);
  case zx_idpdisc_DiscoveryResponse_ELEM:
    return zx_ENC_WO_idpdisc_DiscoveryResponse(c, (struct zx_idpdisc_DiscoveryResponse_s*)x, p);
  case zx_md_ArtifactResolutionService_ELEM:
    return zx_ENC_WO_md_ArtifactResolutionService(c, (struct zx_md_ArtifactResolutionService_s*)x, p);
  case zx_md_SingleLogoutService_ELEM:
    return zx_ENC_WO_md_SingleLogoutService(c, (struct zx_md_SingleLogoutService_s*)x, p);
  case zx_md_ManageNameIDService_ELEM:
    return zx_ENC_WO_md_ManageNameIDService(c, (struct zx_md_ManageNameIDService_s*)x, p);
  case zx_md_SingleSignOnService_ELEM:
    return zx_ENC_WO_md_SingleSignOnService(c, (struct zx_md_SingleSignOnService_s*)x, p);
  case zx_md_NameIDMappingService_ELEM:
    return zx_ENC_WO_md_NameIDMappingService(c, (struct zx_md_NameIDMappingService_s*)x, p);
  case zx_md_EncryptionMethod_ELEM:
    return zx_ENC_WO_md_EncryptionMethod(c, (struct zx_md_EncryptionMethod_s*)x, p);
  case zx_md_OrganizationName_ELEM:
    return zx_ENC_WO_md_OrganizationName(c, (struct zx_md_OrganizationName_s*)x, p);
  case zx_md_OrganizationDisplayName_ELEM:
    return zx_ENC_WO_md_OrganizationDisplayName(c, (struct zx_md_OrganizationDisplayName_s*)x, p);
  case zx_md_OrganizationURL_ELEM:
    return zx_ENC_WO_md_OrganizationURL(c, (struct zx_md_OrganizationURL_s*)x, p);
  case zx_md_AuthzService_ELEM:
    return zx_ENC_WO_md_AuthzService(c, (struct zx_md_AuthzService_s*)x, p);
  case zx_sa_AttributeValue_ELEM:
    return zx_ENC_WO_sa_AttributeValue(c, (struct zx_sa_AttributeValue_s*)x, p);
  case zx_md_AssertionConsumerService_ELEM:
    return zx_ENC_WO_md_AssertionConsumerService(c, (struct zx_md_AssertionConsumerService_s*)x, p);
  case zx_md_AttributeConsumingService_ELEM:
    return zx_ENC_WO_md_AttributeConsumingService(c, (struct zx_md_AttributeConsumingService_s*)x, p);
  case zx_mm7_RFC2822Address_ELEM:
    return zx_ENC_WO_mm7_RFC2822Address(c, (struct zx_mm7_RFC2822Address_s*)x, p);
  case zx_mm7_Number_ELEM:
    return zx_ENC_WO_mm7_Number(c, (struct zx_mm7_Number_s*)x, p);
  case zx_mm7_ShortCode_ELEM:
    return zx_ENC_WO_mm7_ShortCode(c, (struct zx_mm7_ShortCode_s*)x, p);
  case zx_mm7_Extension_ELEM:
    return zx_ENC_WO_mm7_Extension(c, (struct zx_mm7_Extension_s*)x, p);
  case zx_mm7_MM7Version_ELEM:
    return zx_ENC_WO_simple_elem(c, (struct zx_elem_s*)x, p, "MM7Version", sizeof("MM7Version")-1);
  case zx_mm7_SenderIdentification_ELEM:
    return zx_ENC_WO_mm7_SenderIdentification(c, (struct zx_mm7_SenderIdentification_s*)x, p);
  case zx_mm7_MessageID_ELEM:
    return zx_ENC_WO_simple_elem(c, (struct zx_elem_s*)x, p, "MessageID", sizeof("MessageID")-1);
  case zx_mm7_Recipients_ELEM:
    return zx_ENC_WO_mm7_Recipients(c, (struct zx_mm7_Recipients_s*)x, p);
  case zx_mm7_ApplicID_ELEM:
    return zx_ENC_WO_simple_elem(c, (struct zx_elem_s*)x, p, "ApplicID", sizeof("ApplicID")-1);
  case zx_mm7_ReplyApplicID_ELEM:
    return zx_ENC_WO_simple_elem(c, (struct zx_elem_s*)x, p, "ReplyApplicID", sizeof("ReplyApplicID")-1);
  case zx_mm7_AuxApplicInfo_ELEM:
    return zx_ENC_WO_simple_elem(c, (struct zx_elem_s*)x, p, "AuxApplicInfo", sizeof("AuxApplicInfo")-1);
  case zx_mm7_Status_ELEM:
    return zx_ENC_WO_mm7_Status(c, (struct zx_mm7_Status_s*)x, p);
  case zx_mm7_MMSRelayServerID_ELEM:
    return zx_ENC_WO_simple_elem(c, (struct zx_elem_s*)x, p, "MMSRelayServerID", sizeof("MMSRelayServerID")-1);
  case zx_mm7_VASPID_ELEM:
    return zx_ENC_WO_simple_elem(c, (struct zx_elem_s*)x, p, "VASPID", sizeof("VASPID")-1);
  case zx_mm7_VASID_ELEM:
    return zx_ENC_WO_simple_elem(c, (struct zx_elem_s*)x, p, "VASID", sizeof("VASID")-1);
  case zx_mm7_LinkedID_ELEM:
    return zx_ENC_WO_simple_elem(c, (struct zx_elem_s*)x, p, "LinkedID", sizeof("LinkedID")-1);
  case zx_mm7_Sender_ELEM:
    return zx_ENC_WO_mm7_Sender(c, (struct zx_mm7_Sender_s*)x, p);
  case zx_mm7_Previouslysentby_ELEM:
    return zx_ENC_WO_mm7_Previouslysentby(c, (struct zx_mm7_Previouslysentby_s*)x, p);
  case zx_mm7_Previouslysentdateandtime_ELEM:
    return zx_ENC_WO_mm7_Previouslysentdateandtime(c, (struct zx_mm7_Previouslysentdateandtime_s*)x, p);
  case zx_mm7_SenderSPI_ELEM:
    return zx_ENC_WO_simple_elem(c, (struct zx_elem_s*)x, p, "SenderSPI", sizeof("SenderSPI")-1);
  case zx_mm7_RecipientSPI_ELEM:
    return zx_ENC_WO_simple_elem(c, (struct zx_elem_s*)x, p, "RecipientSPI", sizeof("RecipientSPI")-1);
  case zx_mm7_TimeStamp_ELEM:
    return zx_ENC_WO_simple_elem(c, (struct zx_elem_s*)x, p, "TimeStamp", sizeof("TimeStamp")-1);
  case zx_mm7_ReplyChargingID_ELEM:
    return zx_ENC_WO_simple_elem(c, (struct zx_elem_s*)x, p, "ReplyChargingID", sizeof("ReplyChargingID")-1);
  case zx_mm7_Priority_ELEM:
    return zx_ENC_WO_simple_elem(c, (struct zx_elem_s*)x, p, "Priority", sizeof("Priority")-1);
  case zx_mm7_Subject_ELEM:
    return zx_ENC_WO_simple_elem(c, (struct zx_elem_s*)x, p, "Subject", sizeof("Subject")-1);
  case zx_mm7_UACapabilities_ELEM:
    return zx_ENC_WO_mm7_UACapabilities(c, (struct zx_mm7_UACapabilities_s*)x, p);
  case zx_mm7_Content_ELEM:
    return zx_ENC_WO_mm7_Content(c, (struct zx_mm7_Content_s*)x, p);
  case zx_mm7_AdditionalInformation_ELEM:
    return zx_ENC_WO_mm7_AdditionalInformation(c, (struct zx_mm7_AdditionalInformation_s*)x, p);
  case zx_mm7_MessageExtraData_ELEM:
    return zx_ENC_WO_mm7_MessageExtraData(c, (struct zx_mm7_MessageExtraData_s*)x, p);
  case zx_mm7_ServiceCode_ELEM:
    return zx_ENC_WO_mm7_ServiceCode(c, (struct zx_mm7_ServiceCode_s*)x, p);
  case zx_mm7_DC_ELEM:
    return zx_ENC_WO_simple_elem(c, (struct zx_elem_s*)x, p, "DC", sizeof("DC")-1);
  case zx_mm7_Recipient_ELEM:
    return zx_ENC_WO_mm7_Recipient(c, (struct zx_mm7_Recipient_s*)x, p);
  case zx_mm7_Date_ELEM:
    return zx_ENC_WO_simple_elem(c, (struct zx_elem_s*)x, p, "Date", sizeof("Date")-1);
  case zx_mm7_MMStatus_ELEM:
    return zx_ENC_WO_simple_elem(c, (struct zx_elem_s*)x, p, "MMStatus", sizeof("MMStatus")-1);
  case zx_mm7_MMStatusExtension_ELEM:
    return zx_ENC_WO_simple_elem(c, (struct zx_elem_s*)x, p, "MMStatusExtension", sizeof("MMStatusExtension")-1);
  case zx_mm7_StatusText_ELEM:
    return zx_ENC_WO_simple_elem(c, (struct zx_elem_s*)x, p, "StatusText", sizeof("StatusText")-1);
  case zx_mm7_IdentityAddressingToken_ELEM:
    return zx_ENC_WO_mm7_IdentityAddressingToken(c, (struct zx_mm7_IdentityAddressingToken_s*)x, p);
  case zx_mm7_CredentialRef_ELEM:
    return zx_ENC_WO_simple_elem(c, (struct zx_elem_s*)x, p, "CredentialRef", sizeof("CredentialRef")-1);
  case zx_mm7_element_ELEM:
    return zx_ENC_WO_mm7_element(c, (struct zx_mm7_element_s*)x, p);
  case zx_mm7_DeliverUsing_ELEM:
    return zx_ENC_WO_simple_elem(c, (struct zx_elem_s*)x, p, "DeliverUsing", sizeof("DeliverUsing")-1);
  case zx_mm7_UserAgent_ELEM:
    return zx_ENC_WO_mm7_UserAgent(c, (struct zx_mm7_UserAgent_s*)x, p);
  case zx_mm7_DateTime_ELEM:
    return zx_ENC_WO_mm7_DateTime(c, (struct zx_mm7_DateTime_s*)x, p);
  case zx_mm7_MessageType_ELEM:
    return zx_ENC_WO_simple_elem(c, (struct zx_elem_s*)x, p, "MessageType", sizeof("MessageType")-1);
  case zx_mm7_StatusCode_ELEM:
    return zx_ENC_WO_simple_elem(c, (struct zx_elem_s*)x, p, "StatusCode", sizeof("StatusCode")-1);
  case zx_mm7_Details_ELEM:
    return zx_ENC_WO_mm7_Details(c, (struct zx_mm7_Details_s*)x, p);
  case zx_mm7_To_ELEM:
    return zx_ENC_WO_mm7_To(c, (struct zx_mm7_To_s*)x, p);
  case zx_mm7_Cc_ELEM:
    return zx_ENC_WO_mm7_Cc(c, (struct zx_mm7_Cc_s*)x, p);
  case zx_mm7_Bcc_ELEM:
    return zx_ENC_WO_mm7_Bcc(c, (struct zx_mm7_Bcc_s*)x, p);
  case zx_mm7_ReadReply_ELEM:
    return zx_ENC_WO_simple_elem(c, (struct zx_elem_s*)x, p, "ReadReply", sizeof("ReadReply")-1);
  case zx_mm7_EarliestDeliveryTime_ELEM:
    return zx_ENC_WO_simple_elem(c, (struct zx_elem_s*)x, p, "EarliestDeliveryTime", sizeof("EarliestDeliveryTime")-1);
  case zx_mm7_DistributionIndicator_ELEM:
    return zx_ENC_WO_simple_elem(c, (struct zx_elem_s*)x, p, "DistributionIndicator", sizeof("DistributionIndicator")-1);
  case zx_mm7_ContentClass_ELEM:
    return zx_ENC_WO_simple_elem(c, (struct zx_elem_s*)x, p, "ContentClass", sizeof("ContentClass")-1);
  case zx_mm7_DRMContent_ELEM:
    return zx_ENC_WO_simple_elem(c, (struct zx_elem_s*)x, p, "DRMContent", sizeof("DRMContent")-1);
  case zx_mm7_SenderAddress_ELEM:
    return zx_ENC_WO_mm7_SenderAddress(c, (struct zx_mm7_SenderAddress_s*)x, p);
  case zx_mm7_PreferredChannels_ELEM:
    return zx_ENC_WO_mm7_PreferredChannels(c, (struct zx_mm7_PreferredChannels_s*)x, p);
  case zx_mm7_MessageClass_ELEM:
    return zx_ENC_WO_simple_elem(c, (struct zx_elem_s*)x, p, "MessageClass", sizeof("MessageClass")-1);
  case zx_mm7_ReplyCharging_ELEM:
    return zx_ENC_WO_mm7_ReplyCharging(c, (struct zx_mm7_ReplyCharging_s*)x, p);
  case zx_mm7_ExpiryDate_ELEM:
    return zx_ENC_WO_simple_elem(c, (struct zx_elem_s*)x, p, "ExpiryDate", sizeof("ExpiryDate")-1);
  case zx_mm7_DeliveryReport_ELEM:
    return zx_ENC_WO_simple_elem(c, (struct zx_elem_s*)x, p, "DeliveryReport", sizeof("DeliveryReport")-1);
  case zx_mm7_ChargedParty_ELEM:
    return zx_ENC_WO_simple_elem(c, (struct zx_elem_s*)x, p, "ChargedParty", sizeof("ChargedParty")-1);
  case zx_mm7_ChargedPartyID_ELEM:
    return zx_ENC_WO_simple_elem(c, (struct zx_elem_s*)x, p, "ChargedPartyID", sizeof("ChargedPartyID")-1);
  case zx_mm7_ThirdPartyPayer_ELEM:
    return zx_ENC_WO_mm7_ThirdPartyPayer(c, (struct zx_mm7_ThirdPartyPayer_s*)x, p);
  case zx_mm7_DeliveryCondition_ELEM:
    return zx_ENC_WO_mm7_DeliveryCondition(c, (struct zx_mm7_DeliveryCondition_s*)x, p);
  case zx_mm7_key_ELEM:
    return zx_ENC_WO_simple_elem(c, (struct zx_elem_s*)x, p, "key", sizeof("key")-1);
  case zx_mm7_value_ELEM:
    return zx_ENC_WO_simple_elem(c, (struct zx_elem_s*)x, p, "value", sizeof("value")-1);
  case zx_mm7_CancelID_ELEM:
    return zx_ENC_WO_simple_elem(c, (struct zx_elem_s*)x, p, "CancelID", sizeof("CancelID")-1);
  case zx_mm7_ReplaceID_ELEM:
    return zx_ENC_WO_simple_elem(c, (struct zx_elem_s*)x, p, "ReplaceID", sizeof("ReplaceID")-1);
  case zx_pmm_PMActivateItem_ELEM:
    return zx_ENC_WO_pmm_PMActivateItem(c, (struct zx_pmm_PMActivateItem_s*)x, p);
  case zx_dp_NotifyTo_ELEM:
    return zx_ENC_WO_simple_elem(c, (struct zx_elem_s*)x, p, "NotifyTo", sizeof("NotifyTo")-1);
  case zx_prov_PMID_ELEM:
    return zx_ENC_WO_prov_PMID(c, (struct zx_prov_PMID_s*)x, p);
  case zx_pmm_PMDeactivateItem_ELEM:
    return zx_ENC_WO_pmm_PMDeactivateItem(c, (struct zx_pmm_PMDeactivateItem_s*)x, p);
  case zx_pmm_PMDeleteItem_ELEM:
    return zx_ENC_WO_pmm_PMDeleteItem(c, (struct zx_pmm_PMDeleteItem_s*)x, p);
  case zx_prov_PMStatus_ELEM:
    return zx_ENC_WO_prov_PMStatus(c, (struct zx_prov_PMStatus_s*)x, p);
  case zx_pmm_PMUpdateItem_ELEM:
    return zx_ENC_WO_pmm_PMUpdateItem(c, (struct zx_pmm_PMUpdateItem_s*)x, p);
  case zx_prov_PMDescriptor_ELEM:
    return zx_ENC_WO_prov_PMDescriptor(c, (struct zx_prov_PMDescriptor_s*)x, p);
  case zx_prov_ProvisioningHandle_ELEM:
    return zx_ENC_WO_prov_ProvisioningHandle(c, (struct zx_prov_ProvisioningHandle_s*)x, p);
  case zx_prov_PMActivateItem_ELEM:
    return zx_ENC_WO_prov_PMActivateItem(c, (struct zx_prov_PMActivateItem_s*)x, p);
  case zx_prov_PMDeactivateItem_ELEM:
    return zx_ENC_WO_prov_PMDeactivateItem(c, (struct zx_prov_PMDeactivateItem_s*)x, p);
  case zx_prov_PMDeleteItem_ELEM:
    return zx_ENC_WO_prov_PMDeleteItem(c, (struct zx_prov_PMDeleteItem_s*)x, p);
  case zx_prov_PMEngineRef_ELEM:
    return zx_ENC_WO_simple_elem(c, (struct zx_elem_s*)x, p, "PMEngineRef", sizeof("PMEngineRef")-1);
  case zx_prov_PMInitData_ELEM:
    return zx_ENC_WO_simple_elem(c, (struct zx_elem_s*)x, p, "PMInitData", sizeof("PMInitData")-1);
  case zx_prov_PMRTData_ELEM:
    return zx_ENC_WO_simple_elem(c, (struct zx_elem_s*)x, p, "PMRTData", sizeof("PMRTData")-1);
  case zx_prov_EngineData_ELEM:
    return zx_ENC_WO_simple_elem(c, (struct zx_elem_s*)x, p, "EngineData", sizeof("EngineData")-1);
  case zx_prov_PMEInfo_ELEM:
    return zx_ENC_WO_prov_PMEInfo(c, (struct zx_prov_PMEInfo_s*)x, p);
  case zx_prov_PMECreatorID_ELEM:
    return zx_ENC_WO_simple_elem(c, (struct zx_elem_s*)x, p, "PMECreatorID", sizeof("PMECreatorID")-1);
  case zx_prov_PMEWhenCreated_ELEM:
    return zx_ENC_WO_simple_elem(c, (struct zx_elem_s*)x, p, "PMEWhenCreated", sizeof("PMEWhenCreated")-1);
  case zx_prov_PMEEnabled_ELEM:
    return zx_ENC_WO_simple_elem(c, (struct zx_elem_s*)x, p, "PMEEnabled", sizeof("PMEEnabled")-1);
  case zx_prov_PMEWhenEnabled_ELEM:
    return zx_ENC_WO_simple_elem(c, (struct zx_elem_s*)x, p, "PMEWhenEnabled", sizeof("PMEWhenEnabled")-1);
  case zx_prov_PMESize_ELEM:
    return zx_ENC_WO_simple_elem(c, (struct zx_elem_s*)x, p, "PMESize", sizeof("PMESize")-1);
  case zx_prov_PMEHash_ELEM:
    return zx_ENC_WO_prov_PMEHash(c, (struct zx_prov_PMEHash_s*)x, p);
  case zx_prov_PMEUploadMax_ELEM:
    return zx_ENC_WO_simple_elem(c, (struct zx_elem_s*)x, p, "PMEUploadMax", sizeof("PMEUploadMax")-1);
  case zx_prov_PMDArtifact_ELEM:
    return zx_ENC_WO_simple_elem(c, (struct zx_elem_s*)x, p, "PMDArtifact", sizeof("PMDArtifact")-1);
  case zx_prov_CallbackEPR_ELEM:
    return zx_ENC_WO_prov_CallbackEPR(c, (struct zx_prov_CallbackEPR_s*)x, p);
  case zx_prov_PMRegisterDescriptorItem_ELEM:
    return zx_ENC_WO_prov_PMRegisterDescriptorItem(c, (struct zx_prov_PMRegisterDescriptorItem_s*)x, p);
  case zx_prov_PMRegisterDescriptorResponseItem_ELEM:
    return zx_ENC_WO_prov_PMRegisterDescriptorResponseItem(c, (struct zx_prov_PMRegisterDescriptorResponseItem_s*)x, p);
  case zx_prov_State_ELEM:
    return zx_ENC_WO_prov_State(c, (struct zx_prov_State_s*)x, p);
  case zx_prov_PMUpdateItem_ELEM:
    return zx_ENC_WO_prov_PMUpdateItem(c, (struct zx_prov_PMUpdateItem_s*)x, p);
  case zx_dp_Response_ELEM:
    return zx_ENC_WO_dp_Response(c, (struct zx_dp_Response_s*)x, p);
  case zx_dp_Request_ELEM:
    return zx_ENC_WO_dp_Request(c, (struct zx_dp_Request_s*)x, p);
  case zx_prov_ProvisioningServiceEPR_ELEM:
    return zx_ENC_WO_prov_ProvisioningServiceEPR(c, (struct zx_prov_ProvisioningServiceEPR_s*)x, p);
  case zx_prov_UpdateEPRItem_ELEM:
    return zx_ENC_WO_prov_UpdateEPRItem(c, (struct zx_prov_UpdateEPRItem_s*)x, p);
  case zx_ps_Object_ELEM:
    return zx_ENC_WO_ps_Object(c, (struct zx_ps_Object_s*)x, p);
  case zx_ps_Subscription_ELEM:
    return zx_ENC_WO_ps_Subscription(c, (struct zx_ps_Subscription_s*)x, p);
  case zx_ps_PStoSPRedirectURL_ELEM:
    return zx_ENC_WO_simple_elem(c, (struct zx_elem_s*)x, p, "PStoSPRedirectURL", sizeof("PStoSPRedirectURL")-1);
  case zx_ps_CreatePSObject_ELEM:
    return zx_ENC_WO_ps_CreatePSObject(c, (struct zx_ps_CreatePSObject_s*)x, p);
  case zx_ps_SPtoPSRedirectURL_ELEM:
    return zx_ENC_WO_simple_elem(c, (struct zx_elem_s*)x, p, "SPtoPSRedirectURL", sizeof("SPtoPSRedirectURL")-1);
  case zx_ps_QueryString_ELEM:
    return zx_ENC_WO_simple_elem(c, (struct zx_elem_s*)x, p, "QueryString", sizeof("QueryString")-1);
  case zx_ps_TargetObjectID_ELEM:
    return zx_ENC_WO_simple_elem(c, (struct zx_elem_s*)x, p, "TargetObjectID", sizeof("TargetObjectID")-1);
  case zx_ps_ObjectID_ELEM:
    return zx_ENC_WO_simple_elem(c, (struct zx_elem_s*)x, p, "ObjectID", sizeof("ObjectID")-1);
  case zx_ps_ItemData_ELEM:
    return zx_ENC_WO_ps_ItemData(c, (struct zx_ps_ItemData_s*)x, p);
  case zx_ps_Notification_ELEM:
    return zx_ENC_WO_ps_Notification(c, (struct zx_ps_Notification_s*)x, p);
  case zx_ps_DisplayName_ELEM:
    return zx_ENC_WO_ps_DisplayName(c, (struct zx_ps_DisplayName_s*)x, p);
  case zx_ps_Tag_ELEM:
    return zx_ENC_WO_ps_Tag(c, (struct zx_ps_Tag_s*)x, p);
  case zx_ps_ObjectRef_ELEM:
    return zx_ENC_WO_simple_elem(c, (struct zx_elem_s*)x, p, "ObjectRef", sizeof("ObjectRef")-1);
  case zx_ps_Filter_ELEM:
    return zx_ENC_WO_simple_elem(c, (struct zx_elem_s*)x, p, "Filter", sizeof("Filter")-1);
  case zx_ps_ResolveInput_ELEM:
    return zx_ENC_WO_ps_ResolveInput(c, (struct zx_ps_ResolveInput_s*)x, p);
  case zx_ps_ResolveOutput_ELEM:
    return zx_ENC_WO_ps_ResolveOutput(c, (struct zx_ps_ResolveOutput_s*)x, p);
  case zx_ps_Result_ELEM:
    return zx_ENC_WO_simple_elem(c, (struct zx_elem_s*)x, p, "Result", sizeof("Result")-1);
  case zx_sa_AssertionIDRef_ELEM:
    return zx_ENC_WO_simple_elem(c, (struct zx_elem_s*)x, p, "AssertionIDRef", sizeof("AssertionIDRef")-1);
  case zx_sa_AssertionURIRef_ELEM:
    return zx_ENC_WO_simple_elem(c, (struct zx_elem_s*)x, p, "AssertionURIRef", sizeof("AssertionURIRef")-1);
  case zx_sa_Conditions_ELEM:
    return zx_ENC_WO_sa_Conditions(c, (struct zx_sa_Conditions_s*)x, p);
  case zx_sa_Advice_ELEM:
    return zx_ENC_WO_sa_Advice(c, (struct zx_sa_Advice_s*)x, p);
  case zx_sa_Statement_ELEM:
    return zx_ENC_WO_sa_Statement(c, (struct zx_sa_Statement_s*)x, p);
  case zx_sa_AuthnStatement_ELEM:
    return zx_ENC_WO_sa_AuthnStatement(c, (struct zx_sa_AuthnStatement_s*)x, p);
  case zx_sa_AuthzDecisionStatement_ELEM:
    return zx_ENC_WO_sa_AuthzDecisionStatement(c, (struct zx_sa_AuthzDecisionStatement_s*)x, p);
  case zx_sa_EncryptedAttribute_ELEM:
    return zx_ENC_WO_sa_EncryptedAttribute(c, (struct zx_sa_EncryptedAttribute_s*)x, p);
  case zx_sa_Audience_ELEM:
    return zx_ENC_WO_simple_elem(c, (struct zx_elem_s*)x, p, "Audience", sizeof("Audience")-1);
  case zx_sa_AuthnContextClassRef_ELEM:
    return zx_ENC_WO_simple_elem(c, (struct zx_elem_s*)x, p, "AuthnContextClassRef", sizeof("AuthnContextClassRef")-1);
  case zx_sa_AuthnContextDecl_ELEM:
    return zx_ENC_WO_simple_elem(c, (struct zx_elem_s*)x, p, "AuthnContextDecl", sizeof("AuthnContextDecl")-1);
  case zx_sa_AuthnContextDeclRef_ELEM:
    return zx_ENC_WO_simple_elem(c, (struct zx_elem_s*)x, p, "AuthnContextDeclRef", sizeof("AuthnContextDeclRef")-1);
  case zx_sa_AuthenticatingAuthority_ELEM:
    return zx_ENC_WO_simple_elem(c, (struct zx_elem_s*)x, p, "AuthenticatingAuthority", sizeof("AuthenticatingAuthority")-1);
  case zx_sa_SubjectLocality_ELEM:
    return zx_ENC_WO_sa_SubjectLocality(c, (struct zx_sa_SubjectLocality_s*)x, p);
  case zx_sa_Action_ELEM:
    return zx_ENC_WO_sa_Action(c, (struct zx_sa_Action_s*)x, p);
  case zx_sa_Evidence_ELEM:
    return zx_ENC_WO_sa_Evidence(c, (struct zx_sa_Evidence_s*)x, p);
  case zx_sa_Condition_ELEM:
    return zx_ENC_WO_simple_elem(c, (struct zx_elem_s*)x, p, "Condition", sizeof("Condition")-1);
  case zx_sa_AudienceRestriction_ELEM:
    return zx_ENC_WO_sa_AudienceRestriction(c, (struct zx_sa_AudienceRestriction_s*)x, p);
  case zx_sa_OneTimeUse_ELEM:
    return zx_ENC_WO_sa_OneTimeUse(c, (struct zx_sa_OneTimeUse_s*)x, p);
  case zx_sa_ProxyRestriction_ELEM:
    return zx_ENC_WO_sa_ProxyRestriction(c, (struct zx_sa_ProxyRestriction_s*)x, p);
  case zx_idp_SubjectRestriction_ELEM:
    return zx_ENC_WO_idp_SubjectRestriction(c, (struct zx_idp_SubjectRestriction_s*)x, p);
  case zx_sa_BaseID_ELEM:
    return zx_ENC_WO_sa_BaseID(c, (struct zx_sa_BaseID_s*)x, p);
  case zx_sa_EncryptedID_ELEM:
    return zx_ENC_WO_sa_EncryptedID(c, (struct zx_sa_EncryptedID_s*)x, p);
  case zx_sa_SubjectConfirmation_ELEM:
    return zx_ENC_WO_sa_SubjectConfirmation(c, (struct zx_sa_SubjectConfirmation_s*)x, p);
  case zx_sa_SubjectConfirmationData_ELEM:
    return zx_ENC_WO_sa_SubjectConfirmationData(c, (struct zx_sa_SubjectConfirmationData_s*)x, p);
  case zx_sa11_AssertionIDReference_ELEM:
    return zx_ENC_WO_simple_elem(c, (struct zx_elem_s*)x, p, "AssertionIDReference", sizeof("AssertionIDReference")-1);
  case zx_sa11_AttributeValue_ELEM:
    return zx_ENC_WO_sa11_AttributeValue(c, (struct zx_sa11_AttributeValue_s*)x, p);
  case zx_sa11_Attribute_ELEM:
    return zx_ENC_WO_sa11_Attribute(c, (struct zx_sa11_Attribute_s*)x, p);
  case zx_sa11_Audience_ELEM:
    return zx_ENC_WO_simple_elem(c, (struct zx_elem_s*)x, p, "Audience", sizeof("Audience")-1);
  case zx_sa11_Action_ELEM:
    return zx_ENC_WO_sa11_Action(c, (struct zx_sa11_Action_s*)x, p);
  case zx_sa11_Evidence_ELEM:
    return zx_ENC_WO_sa11_Evidence(c, (struct zx_sa11_Evidence_s*)x, p);
  case zx_sa11_AudienceRestrictionCondition_ELEM:
    return zx_ENC_WO_sa11_AudienceRestrictionCondition(c, (struct zx_sa11_AudienceRestrictionCondition_s*)x, p);
  case zx_sa11_DoNotCacheCondition_ELEM:
    return zx_ENC_WO_sa11_DoNotCacheCondition(c, (struct zx_sa11_DoNotCacheCondition_s*)x, p);
  case zx_sa11_Condition_ELEM:
    return zx_ENC_WO_simple_elem(c, (struct zx_elem_s*)x, p, "Condition", sizeof("Condition")-1);
  case zx_sa11_ConfirmationMethod_ELEM:
    return zx_ENC_WO_simple_elem(c, (struct zx_elem_s*)x, p, "ConfirmationMethod", sizeof("ConfirmationMethod")-1);
  case zx_sa11_SubjectConfirmationData_ELEM:
    return zx_ENC_WO_simple_elem(c, (struct zx_elem_s*)x, p, "SubjectConfirmationData", sizeof("SubjectConfirmationData")-1);
  case zx_sec_TransitedProvider_ELEM:
    return zx_ENC_WO_sec_TransitedProvider(c, (struct zx_sec_TransitedProvider_s*)x, p);
  case zx_sec12_Issuer_ELEM:
    return zx_ENC_WO_simple_elem(c, (struct zx_elem_s*)x, p, "Issuer", sizeof("Issuer")-1);
  case zx_sec12_IssueInstant_ELEM:
    return zx_ENC_WO_simple_elem(c, (struct zx_elem_s*)x, p, "IssueInstant", sizeof("IssueInstant")-1);
  case zx_sec12_ProxySubject_ELEM:
    return zx_ENC_WO_sec12_ProxySubject(c, (struct zx_sec12_ProxySubject_s*)x, p);
  case zx_sec12_SessionContext_ELEM:
    return zx_ENC_WO_sec12_SessionContext(c, (struct zx_sec12_SessionContext_s*)x, p);
  case zx_sec12_SessionSubject_ELEM:
    return zx_ENC_WO_sec12_SessionSubject(c, (struct zx_sec12_SessionSubject_s*)x, p);
  case zx_sec12_ProviderID_ELEM:
    return zx_ENC_WO_simple_elem(c, (struct zx_elem_s*)x, p, "ProviderID", sizeof("ProviderID")-1);
  case zx_sec12_NumberOfUses_ELEM:
    return zx_ENC_WO_simple_elem(c, (struct zx_elem_s*)x, p, "NumberOfUses", sizeof("NumberOfUses")-1);
  case zx_shps_ServiceHandle_ELEM:
    return zx_ENC_WO_simple_elem(c, (struct zx_elem_s*)x, p, "ServiceHandle", sizeof("ServiceHandle")-1);
  case zx_shps_GetStatusResponseItem_ELEM:
    return zx_ENC_WO_shps_GetStatusResponseItem(c, (struct zx_shps_GetStatusResponseItem_s*)x, p);
  case zx_shps_ServiceStatus_ELEM:
    return zx_ENC_WO_simple_elem(c, (struct zx_elem_s*)x, p, "ServiceStatus", sizeof("ServiceStatus")-1);
  case zx_shps_InvokingProvider_ELEM:
    return zx_ENC_WO_simple_elem(c, (struct zx_elem_s*)x, p, "InvokingProvider", sizeof("InvokingProvider")-1);
  case zx_shps_InvokingPrincipal_ELEM:
    return zx_ENC_WO_simple_elem(c, (struct zx_elem_s*)x, p, "InvokingPrincipal", sizeof("InvokingPrincipal")-1);
  case zx_shps_InvokeResponseItem_ELEM:
    return zx_ENC_WO_shps_InvokeResponseItem(c, (struct zx_shps_InvokeResponseItem_s*)x, p);
  case zx_shps_ProxyInvokeItem_ELEM:
    return zx_ENC_WO_shps_ProxyInvokeItem(c, (struct zx_shps_ProxyInvokeItem_s*)x, p);
  case zx_shps_InvocationContext_ELEM:
    return zx_ENC_WO_shps_InvocationContext(c, (struct zx_shps_InvocationContext_s*)x, p);
  case zx_shps_RequestHeaders_ELEM:
    return zx_ENC_WO_simple_elem(c, (struct zx_elem_s*)x, p, "RequestHeaders", sizeof("RequestHeaders")-1);
  case zx_shps_ProxyInvokeResponseItem_ELEM:
    return zx_ENC_WO_shps_ProxyInvokeResponseItem(c, (struct zx_shps_ProxyInvokeResponseItem_s*)x, p);
  case zx_shps_ResponseHeaders_ELEM:
    return zx_ENC_WO_simple_elem(c, (struct zx_elem_s*)x, p, "ResponseHeaders", sizeof("ResponseHeaders")-1);
  case zx_shps_RegisterResponseItem_ELEM:
    return zx_ENC_WO_shps_RegisterResponseItem(c, (struct zx_shps_RegisterResponseItem_s*)x, p);
  case zx_shps_SetStatusItem_ELEM:
    return zx_ENC_WO_shps_SetStatusItem(c, (struct zx_shps_SetStatusItem_s*)x, p);
  case zx_shps_UpdateItem_ELEM:
    return zx_ENC_WO_shps_UpdateItem(c, (struct zx_shps_UpdateItem_s*)x, p);
  case zx_sp_Extensions_ELEM:
    return zx_ENC_WO_sp_Extensions(c, (struct zx_sp_Extensions_s*)x, p);
  case zx_sp_Artifact_ELEM:
    return zx_ENC_WO_simple_elem(c, (struct zx_elem_s*)x, p, "Artifact", sizeof("Artifact")-1);
  case zx_sp_Status_ELEM:
    return zx_ENC_WO_sp_Status(c, (struct zx_sp_Status_s*)x, p);
  case zx_sp_NameIDPolicy_ELEM:
    return zx_ENC_WO_sp_NameIDPolicy(c, (struct zx_sp_NameIDPolicy_s*)x, p);
  case zx_sp_Scoping_ELEM:
    return zx_ENC_WO_sp_Scoping(c, (struct zx_sp_Scoping_s*)x, p);
  case zx_sp_IDPEntry_ELEM:
    return zx_ENC_WO_sp_IDPEntry(c, (struct zx_sp_IDPEntry_s*)x, p);
  case zx_sp_GetComplete_ELEM:
    return zx_ENC_WO_simple_elem(c, (struct zx_elem_s*)x, p, "GetComplete", sizeof("GetComplete")-1);
  case zx_sp_SessionIndex_ELEM:
    return zx_ENC_WO_simple_elem(c, (struct zx_elem_s*)x, p, "SessionIndex", sizeof("SessionIndex")-1);
  case zx_sp_NewID_ELEM:
    return zx_ENC_WO_simple_elem(c, (struct zx_elem_s*)x, p, "NewID", sizeof("NewID")-1);
  case zx_sp_NewEncryptedID_ELEM:
    return zx_ENC_WO_sp_NewEncryptedID(c, (struct zx_sp_NewEncryptedID_s*)x, p);
  case zx_sp_Terminate_ELEM:
    return zx_ENC_WO_simple_elem(c, (struct zx_elem_s*)x, p, "Terminate", sizeof("Terminate")-1);
  case zx_sp_RequesterID_ELEM:
    return zx_ENC_WO_simple_elem(c, (struct zx_elem_s*)x, p, "RequesterID", sizeof("RequesterID")-1);
  case zx_sp_StatusCode_ELEM:
    return zx_ENC_WO_sp_StatusCode(c, (struct zx_sp_StatusCode_s*)x, p);
  case zx_sp_StatusMessage_ELEM:
    return zx_ENC_WO_simple_elem(c, (struct zx_elem_s*)x, p, "StatusMessage", sizeof("StatusMessage")-1);
  case zx_sp_StatusDetail_ELEM:
    return zx_ENC_WO_sp_StatusDetail(c, (struct zx_sp_StatusDetail_s*)x, p);
  case zx_sa11_AttributeDesignator_ELEM:
    return zx_ENC_WO_sa11_AttributeDesignator(c, (struct zx_sa11_AttributeDesignator_s*)x, p);
  case zx_sp11_Query_ELEM:
    return zx_ENC_WO_simple_elem(c, (struct zx_elem_s*)x, p, "Query", sizeof("Query")-1);
  case zx_sp11_SubjectQuery_ELEM:
    return zx_ENC_WO_sp11_SubjectQuery(c, (struct zx_sp11_SubjectQuery_s*)x, p);
  case zx_sp11_AuthenticationQuery_ELEM:
    return zx_ENC_WO_sp11_AuthenticationQuery(c, (struct zx_sp11_AuthenticationQuery_s*)x, p);
  case zx_sp11_AttributeQuery_ELEM:
    return zx_ENC_WO_sp11_AttributeQuery(c, (struct zx_sp11_AttributeQuery_s*)x, p);
  case zx_sp11_AuthorizationDecisionQuery_ELEM:
    return zx_ENC_WO_sp11_AuthorizationDecisionQuery(c, (struct zx_sp11_AuthorizationDecisionQuery_s*)x, p);
  case zx_sp11_AssertionArtifact_ELEM:
    return zx_ENC_WO_simple_elem(c, (struct zx_elem_s*)x, p, "AssertionArtifact", sizeof("AssertionArtifact")-1);
  case zx_sp11_StatusCode_ELEM:
    return zx_ENC_WO_sp11_StatusCode(c, (struct zx_sp11_StatusCode_s*)x, p);
  case zx_sp11_StatusMessage_ELEM:
    return zx_ENC_WO_simple_elem(c, (struct zx_elem_s*)x, p, "StatusMessage", sizeof("StatusMessage")-1);
  case zx_sp11_StatusDetail_ELEM:
    return zx_ENC_WO_sp11_StatusDetail(c, (struct zx_sp11_StatusDetail_s*)x, p);
  case zx_xac_Attribute_ELEM:
    return zx_ENC_WO_xac_Attribute(c, (struct zx_xac_Attribute_s*)x, p);
  case zx_tas3_ESLRef_ELEM:
    return zx_ENC_WO_tas3_ESLRef(c, (struct zx_tas3_ESLRef_s*)x, p);
  case zx_tas3_ESLApply_ELEM:
    return zx_ENC_WO_tas3_ESLApply(c, (struct zx_tas3_ESLApply_s*)x, p);
  case zx_wsse_SecurityTokenReference_ELEM:
    return zx_ENC_WO_wsse_SecurityTokenReference(c, (struct zx_wsse_SecurityTokenReference_s*)x, p);
  case zx_wsc_Properties_ELEM:
    return zx_ENC_WO_wsc_Properties(c, (struct zx_wsc_Properties_s*)x, p);
  case zx_wsc_Generation_ELEM:
    return zx_ENC_WO_simple_elem(c, (struct zx_elem_s*)x, p, "Generation", sizeof("Generation")-1);
  case zx_wsc_Offset_ELEM:
    return zx_ENC_WO_simple_elem(c, (struct zx_elem_s*)x, p, "Offset", sizeof("Offset")-1);
  case zx_wsc_Length_ELEM:
    return zx_ENC_WO_simple_elem(c, (struct zx_elem_s*)x, p, "Length", sizeof("Length")-1);
  case zx_wsc_Label_ELEM:
    return zx_ENC_WO_simple_elem(c, (struct zx_elem_s*)x, p, "Label", sizeof("Label")-1);
  case zx_wsc_Nonce_ELEM:
    return zx_ENC_WO_simple_elem(c, (struct zx_elem_s*)x, p, "Nonce", sizeof("Nonce")-1);
  case zx_wsp_Policy_ELEM:
    return zx_ENC_WO_wsp_Policy(c, (struct zx_wsp_Policy_s*)x, p);
  case zx_wsp_All_ELEM:
    return zx_ENC_WO_wsp_All(c, (struct zx_wsp_All_s*)x, p);
  case zx_wsp_ExactlyOne_ELEM:
    return zx_ENC_WO_wsp_ExactlyOne(c, (struct zx_wsp_ExactlyOne_s*)x, p);
  case zx_wsp_PolicyReference_ELEM:
    return zx_ENC_WO_wsp_PolicyReference(c, (struct zx_wsp_PolicyReference_s*)x, p);
  case zx_wsp_AppliesTo_ELEM:
    return zx_ENC_WO_wsp_AppliesTo(c, (struct zx_wsp_AppliesTo_s*)x, p);
  case zx_wsse_BinarySecurityToken_ELEM:
    return zx_ENC_WO_wsse_BinarySecurityToken(c, (struct zx_wsse_BinarySecurityToken_s*)x, p);
  case zx_wsu_Timestamp_ELEM:
    return zx_ENC_WO_wsu_Timestamp(c, (struct zx_wsu_Timestamp_s*)x, p);
  case zx_wsse_KeyIdentifier_ELEM:
    return zx_ENC_WO_wsse_KeyIdentifier(c, (struct zx_wsse_KeyIdentifier_s*)x, p);
  case zx_wsse_Username_ELEM:
    return zx_ENC_WO_wsse_Username(c, (struct zx_wsse_Username_s*)x, p);
  case zx_wst_CombinedHash_ELEM:
    return zx_ENC_WO_simple_elem(c, (struct zx_elem_s*)x, p, "CombinedHash", sizeof("CombinedHash")-1);
  case zx_wst_RequestSecurityTokenResponse_ELEM:
    return zx_ENC_WO_wst_RequestSecurityTokenResponse(c, (struct zx_wst_RequestSecurityTokenResponse_s*)x, p);
  case zx_wsu_Created_ELEM:
    return zx_ENC_WO_wsu_Created(c, (struct zx_wsu_Created_s*)x, p);
  case zx_wsu_Expires_ELEM:
    return zx_ENC_WO_wsu_Expires(c, (struct zx_wsu_Expires_s*)x, p);
  case zx_wst_Primary_ELEM:
    return zx_ENC_WO_wst_Primary(c, (struct zx_wst_Primary_s*)x, p);
  case zx_wst_Participant_ELEM:
    return zx_ENC_WO_wst_Participant(c, (struct zx_wst_Participant_s*)x, p);
  case zx_wst_TokenType_ELEM:
    return zx_ENC_WO_simple_elem(c, (struct zx_elem_s*)x, p, "TokenType", sizeof("TokenType")-1);
  case zx_wst_RequestType_ELEM:
    return zx_ENC_WO_simple_elem(c, (struct zx_elem_s*)x, p, "RequestType", sizeof("RequestType")-1);
  case zx_wst_Claims_ELEM:
    return zx_ENC_WO_wst_Claims(c, (struct zx_wst_Claims_s*)x, p);
  case zx_wst_Entropy_ELEM:
    return zx_ENC_WO_wst_Entropy(c, (struct zx_wst_Entropy_s*)x, p);
  case zx_wst_Lifetime_ELEM:
    return zx_ENC_WO_wst_Lifetime(c, (struct zx_wst_Lifetime_s*)x, p);
  case zx_wst_AllowPostdating_ELEM:
    return zx_ENC_WO_simple_elem(c, (struct zx_elem_s*)x, p, "AllowPostdating", sizeof("AllowPostdating")-1);
  case zx_wst_Renewing_ELEM:
    return zx_ENC_WO_wst_Renewing(c, (struct zx_wst_Renewing_s*)x, p);
  case zx_wst_OnBehalfOf_ELEM:
    return zx_ENC_WO_wst_OnBehalfOf(c, (struct zx_wst_OnBehalfOf_s*)x, p);
  case zx_wst_Issuer_ELEM:
    return zx_ENC_WO_wst_Issuer(c, (struct zx_wst_Issuer_s*)x, p);
  case zx_wst_AuthenticationType_ELEM:
    return zx_ENC_WO_simple_elem(c, (struct zx_elem_s*)x, p, "AuthenticationType", sizeof("AuthenticationType")-1);
  case zx_wst_KeyType_ELEM:
    return zx_ENC_WO_simple_elem(c, (struct zx_elem_s*)x, p, "KeyType", sizeof("KeyType")-1);
  case zx_wst_KeySize_ELEM:
    return zx_ENC_WO_simple_elem(c, (struct zx_elem_s*)x, p, "KeySize", sizeof("KeySize")-1);
  case zx_wst_SignatureAlgorithm_ELEM:
    return zx_ENC_WO_simple_elem(c, (struct zx_elem_s*)x, p, "SignatureAlgorithm", sizeof("SignatureAlgorithm")-1);
  case zx_wst_Encryption_ELEM:
    return zx_ENC_WO_wst_Encryption(c, (struct zx_wst_Encryption_s*)x, p);
  case zx_wst_EncryptionAlgorithm_ELEM:
    return zx_ENC_WO_simple_elem(c, (struct zx_elem_s*)x, p, "EncryptionAlgorithm", sizeof("EncryptionAlgorithm")-1);
  case zx_wst_CanonicalizationAlgorithm_ELEM:
    return zx_ENC_WO_simple_elem(c, (struct zx_elem_s*)x, p, "CanonicalizationAlgorithm", sizeof("CanonicalizationAlgorithm")-1);
  case zx_wst_ProofEncryption_ELEM:
    return zx_ENC_WO_wst_ProofEncryption(c, (struct zx_wst_ProofEncryption_s*)x, p);
  case zx_wst_UseKey_ELEM:
    return zx_ENC_WO_wst_UseKey(c, (struct zx_wst_UseKey_s*)x, p);
  case zx_wst_SignWith_ELEM:
    return zx_ENC_WO_simple_elem(c, (struct zx_elem_s*)x, p, "SignWith", sizeof("SignWith")-1);
  case zx_wst_EncryptWith_ELEM:
    return zx_ENC_WO_simple_elem(c, (struct zx_elem_s*)x, p, "EncryptWith", sizeof("EncryptWith")-1);
  case zx_wst_DelegateTo_ELEM:
    return zx_ENC_WO_wst_DelegateTo(c, (struct zx_wst_DelegateTo_s*)x, p);
  case zx_wst_Forwardable_ELEM:
    return zx_ENC_WO_simple_elem(c, (struct zx_elem_s*)x, p, "Forwardable", sizeof("Forwardable")-1);
  case zx_wst_Delegatable_ELEM:
    return zx_ENC_WO_simple_elem(c, (struct zx_elem_s*)x, p, "Delegatable", sizeof("Delegatable")-1);
  case zx_wst_RequestSecurityToken_ELEM:
    return zx_ENC_WO_wst_RequestSecurityToken(c, (struct zx_wst_RequestSecurityToken_s*)x, p);
  case zx_wst_RequestedSecurityToken_ELEM:
    return zx_ENC_WO_wst_RequestedSecurityToken(c, (struct zx_wst_RequestedSecurityToken_s*)x, p);
  case zx_wst_RequestedAttachedReference_ELEM:
    return zx_ENC_WO_wst_RequestedAttachedReference(c, (struct zx_wst_RequestedAttachedReference_s*)x, p);
  case zx_wst_RequestedUnattachedReference_ELEM:
    return zx_ENC_WO_wst_RequestedUnattachedReference(c, (struct zx_wst_RequestedUnattachedReference_s*)x, p);
  case zx_wst_RequestedProofToken_ELEM:
    return zx_ENC_WO_wst_RequestedProofToken(c, (struct zx_wst_RequestedProofToken_s*)x, p);
  case zx_wst_Status_ELEM:
    return zx_ENC_WO_wst_Status(c, (struct zx_wst_Status_s*)x, p);
  case zx_wst_Authenticator_ELEM:
    return zx_ENC_WO_wst_Authenticator(c, (struct zx_wst_Authenticator_s*)x, p);
  case zx_wst_Challenge_ELEM:
    return zx_ENC_WO_simple_elem(c, (struct zx_elem_s*)x, p, "Challenge", sizeof("Challenge")-1);
  case zx_wst_Code_ELEM:
    return zx_ENC_WO_simple_elem(c, (struct zx_elem_s*)x, p, "Code", sizeof("Code")-1);
  case zx_wst_Reason_ELEM:
    return zx_ENC_WO_simple_elem(c, (struct zx_elem_s*)x, p, "Reason", sizeof("Reason")-1);
  case zx_xa_ActionMatch_ELEM:
    return zx_ENC_WO_xa_ActionMatch(c, (struct zx_xa_ActionMatch_s*)x, p);
  case zx_xa_AttributeValue_ELEM:
    return zx_ENC_WO_xa_AttributeValue(c, (struct zx_xa_AttributeValue_s*)x, p);
  case zx_xa_ActionAttributeDesignator_ELEM:
    return zx_ENC_WO_xa_ActionAttributeDesignator(c, (struct zx_xa_ActionAttributeDesignator_s*)x, p);
  case zx_xa_AttributeSelector_ELEM:
    return zx_ENC_WO_xa_AttributeSelector(c, (struct zx_xa_AttributeSelector_s*)x, p);
  case zx_xa_Action_ELEM:
    return zx_ENC_WO_xa_Action(c, (struct zx_xa_Action_s*)x, p);
  case zx_xa_Expression_ELEM:
    return zx_ENC_WO_simple_elem(c, (struct zx_elem_s*)x, p, "Expression", sizeof("Expression")-1);
  case zx_xa_CombinerParameter_ELEM:
    return zx_ENC_WO_xa_CombinerParameter(c, (struct zx_xa_CombinerParameter_s*)x, p);
  case zx_xa_EnvironmentMatch_ELEM:
    return zx_ENC_WO_xa_EnvironmentMatch(c, (struct zx_xa_EnvironmentMatch_s*)x, p);
  case zx_xa_EnvironmentAttributeDesignator_ELEM:
    return zx_ENC_WO_xa_EnvironmentAttributeDesignator(c, (struct zx_xa_EnvironmentAttributeDesignator_s*)x, p);
  case zx_xa_Environment_ELEM:
    return zx_ENC_WO_xa_Environment(c, (struct zx_xa_Environment_s*)x, p);
  case zx_xa_AttributeAssignment_ELEM:
    return zx_ENC_WO_xa_AttributeAssignment(c, (struct zx_xa_AttributeAssignment_s*)x, p);
  case zx_xa_Description_ELEM:
    return zx_ENC_WO_simple_elem(c, (struct zx_elem_s*)x, p, "Description", sizeof("Description")-1);
  case zx_xa_PolicyDefaults_ELEM:
    return zx_ENC_WO_xa_PolicyDefaults(c, (struct zx_xa_PolicyDefaults_s*)x, p);
  case zx_xa_Target_ELEM:
    return zx_ENC_WO_xa_Target(c, (struct zx_xa_Target_s*)x, p);
  case zx_xa_CombinerParameters_ELEM:
    return zx_ENC_WO_xa_CombinerParameters(c, (struct zx_xa_CombinerParameters_s*)x, p);
  case zx_xa_RuleCombinerParameters_ELEM:
    return zx_ENC_WO_xa_RuleCombinerParameters(c, (struct zx_xa_RuleCombinerParameters_s*)x, p);
  case zx_xa_VariableDefinition_ELEM:
    return zx_ENC_WO_xa_VariableDefinition(c, (struct zx_xa_VariableDefinition_s*)x, p);
  case zx_xa_Rule_ELEM:
    return zx_ENC_WO_xa_Rule(c, (struct zx_xa_Rule_s*)x, p);
  case zx_xa_Obligations_ELEM:
    return zx_ENC_WO_xa_Obligations(c, (struct zx_xa_Obligations_s*)x, p);
  case zx_xa_XPathVersion_ELEM:
    return zx_ENC_WO_simple_elem(c, (struct zx_elem_s*)x, p, "XPathVersion", sizeof("XPathVersion")-1);
  case zx_xa_PolicySetDefaults_ELEM:
    return zx_ENC_WO_xa_PolicySetDefaults(c, (struct zx_xa_PolicySetDefaults_s*)x, p);
  case zx_xa_PolicySet_ELEM:
    return zx_ENC_WO_xa_PolicySet(c, (struct zx_xa_PolicySet_s*)x, p);
  case zx_xa_Policy_ELEM:
    return zx_ENC_WO_xa_Policy(c, (struct zx_xa_Policy_s*)x, p);
  case zx_xa_PolicySetIdReference_ELEM:
    return zx_ENC_WO_xa_PolicySetIdReference(c, (struct zx_xa_PolicySetIdReference_s*)x, p);
  case zx_xa_PolicyIdReference_ELEM:
    return zx_ENC_WO_xa_PolicyIdReference(c, (struct zx_xa_PolicyIdReference_s*)x, p);
  case zx_xa_PolicyCombinerParameters_ELEM:
    return zx_ENC_WO_xa_PolicyCombinerParameters(c, (struct zx_xa_PolicyCombinerParameters_s*)x, p);
  case zx_xa_PolicySetCombinerParameters_ELEM:
    return zx_ENC_WO_xa_PolicySetCombinerParameters(c, (struct zx_xa_PolicySetCombinerParameters_s*)x, p);
  case zx_xa_ResourceMatch_ELEM:
    return zx_ENC_WO_xa_ResourceMatch(c, (struct zx_xa_ResourceMatch_s*)x, p);
  case zx_xa_ResourceAttributeDesignator_ELEM:
    return zx_ENC_WO_xa_ResourceAttributeDesignator(c, (struct zx_xa_ResourceAttributeDesignator_s*)x, p);
  case zx_xa_Resource_ELEM:
    return zx_ENC_WO_xa_Resource(c, (struct zx_xa_Resource_s*)x, p);
  case zx_xa_Condition_ELEM:
    return zx_ENC_WO_xa_Condition(c, (struct zx_xa_Condition_s*)x, p);
  case zx_xa_SubjectMatch_ELEM:
    return zx_ENC_WO_xa_SubjectMatch(c, (struct zx_xa_SubjectMatch_s*)x, p);
  case zx_xa_SubjectAttributeDesignator_ELEM:
    return zx_ENC_WO_xa_SubjectAttributeDesignator(c, (struct zx_xa_SubjectAttributeDesignator_s*)x, p);
  case zx_xa_Subject_ELEM:
    return zx_ENC_WO_xa_Subject(c, (struct zx_xa_Subject_s*)x, p);
  case zx_xa_Subjects_ELEM:
    return zx_ENC_WO_xa_Subjects(c, (struct zx_xa_Subjects_s*)x, p);
  case zx_xa_Resources_ELEM:
    return zx_ENC_WO_xa_Resources(c, (struct zx_xa_Resources_s*)x, p);
  case zx_xa_Actions_ELEM:
    return zx_ENC_WO_xa_Actions(c, (struct zx_xa_Actions_s*)x, p);
  case zx_xa_Environments_ELEM:
    return zx_ENC_WO_xa_Environments(c, (struct zx_xa_Environments_s*)x, p);
  case zx_xac_AttributeValue_ELEM:
    return zx_ENC_WO_simple_elem(c, (struct zx_elem_s*)x, p, "AttributeValue", sizeof("AttributeValue")-1);
  case zx_xac_Subject_ELEM:
    return zx_ENC_WO_xac_Subject(c, (struct zx_xac_Subject_s*)x, p);
  case zx_xac_Resource_ELEM:
    return zx_ENC_WO_xac_Resource(c, (struct zx_xac_Resource_s*)x, p);
  case zx_xac_Action_ELEM:
    return zx_ENC_WO_xac_Action(c, (struct zx_xac_Action_s*)x, p);
  case zx_xac_Environment_ELEM:
    return zx_ENC_WO_xac_Environment(c, (struct zx_xac_Environment_s*)x, p);
  case zx_xac_ResourceContent_ELEM:
    return zx_ENC_WO_xac_ResourceContent(c, (struct zx_xac_ResourceContent_s*)x, p);
  case zx_xac_Result_ELEM:
    return zx_ENC_WO_xac_Result(c, (struct zx_xac_Result_s*)x, p);
  case zx_xac_Decision_ELEM:
    return zx_ENC_WO_simple_elem(c, (struct zx_elem_s*)x, p, "Decision", sizeof("Decision")-1);
  case zx_xac_Status_ELEM:
    return zx_ENC_WO_xac_Status(c, (struct zx_xac_Status_s*)x, p);
  case zx_xac_StatusCode_ELEM:
    return zx_ENC_WO_xac_StatusCode(c, (struct zx_xac_StatusCode_s*)x, p);
  case zx_xac_StatusMessage_ELEM:
    return zx_ENC_WO_simple_elem(c, (struct zx_elem_s*)x, p, "StatusMessage", sizeof("StatusMessage")-1);
  case zx_xac_StatusDetail_ELEM:
    return zx_ENC_WO_xac_StatusDetail(c, (struct zx_xac_StatusDetail_s*)x, p);
  case zx_xasacd1_ReferencedPolicies_ELEM:
    return zx_ENC_WO_xasacd1_ReferencedPolicies(c, (struct zx_xasacd1_ReferencedPolicies_s*)x, p);
  case zx_xenc_KA_Nonce_ELEM:
    return zx_ENC_WO_simple_elem(c, (struct zx_elem_s*)x, p, "KA_Nonce", sizeof("KA_Nonce")-1);
  case zx_xenc_OriginatorKeyInfo_ELEM:
    return zx_ENC_WO_xenc_OriginatorKeyInfo(c, (struct zx_xenc_OriginatorKeyInfo_s*)x, p);
  case zx_xenc_RecipientKeyInfo_ELEM:
    return zx_ENC_WO_xenc_RecipientKeyInfo(c, (struct zx_xenc_RecipientKeyInfo_s*)x, p);
  case zx_xenc_CipherValue_ELEM:
    return zx_ENC_WO_simple_elem(c, (struct zx_elem_s*)x, p, "CipherValue", sizeof("CipherValue")-1);
  case zx_xenc_CipherReference_ELEM:
    return zx_ENC_WO_xenc_CipherReference(c, (struct zx_xenc_CipherReference_s*)x, p);
  case zx_xenc_Transforms_ELEM:
    return zx_ENC_WO_xenc_Transforms(c, (struct zx_xenc_Transforms_s*)x, p);
  case zx_xenc_EncryptionMethod_ELEM:
    return zx_ENC_WO_xenc_EncryptionMethod(c, (struct zx_xenc_EncryptionMethod_s*)x, p);
  case zx_xenc_CipherData_ELEM:
    return zx_ENC_WO_xenc_CipherData(c, (struct zx_xenc_CipherData_s*)x, p);
  case zx_xenc_EncryptionProperties_ELEM:
    return zx_ENC_WO_xenc_EncryptionProperties(c, (struct zx_xenc_EncryptionProperties_s*)x, p);
  case zx_xenc_ReferenceList_ELEM:
    return zx_ENC_WO_xenc_ReferenceList(c, (struct zx_xenc_ReferenceList_s*)x, p);
  case zx_xenc_CarriedKeyName_ELEM:
    return zx_ENC_WO_simple_elem(c, (struct zx_elem_s*)x, p, "CarriedKeyName", sizeof("CarriedKeyName")-1);
  case zx_xenc_EncryptionProperty_ELEM:
    return zx_ENC_WO_xenc_EncryptionProperty(c, (struct zx_xenc_EncryptionProperty_s*)x, p);
  case zx_xenc_DataReference_ELEM:
    return zx_ENC_WO_xenc_DataReference(c, (struct zx_xenc_DataReference_s*)x, p);
  case zx_xenc_KeyReference_ELEM:
    return zx_ENC_WO_xenc_KeyReference(c, (struct zx_xenc_KeyReference_s*)x, p);
  case zx_e_Envelope_ELEM:
    return zx_ENC_WO_e_Envelope(c, (struct zx_e_Envelope_s*)x, p);
  case zx_ff12_AuthnRequestEnvelope_ELEM:
    return zx_ENC_WO_ff12_AuthnRequestEnvelope(c, (struct zx_ff12_AuthnRequestEnvelope_s*)x, p);
  case zx_ff12_AuthnResponseEnvelope_ELEM:
    return zx_ENC_WO_ff12_AuthnResponseEnvelope(c, (struct zx_ff12_AuthnResponseEnvelope_s*)x, p);
  case zx_m20_EntitiesDescriptor_ELEM:
    return zx_ENC_WO_m20_EntitiesDescriptor(c, (struct zx_m20_EntitiesDescriptor_s*)x, p);

  case ZX_TOK_NOT_FOUND:
    pop_seen = 0;
    ZX_OUT_CH(p, '<');
    if (x->g.ns && x->g.ns->prefix_len) {
      ZX_OUT_MEM(p, x->g.ns->prefix, x->g.ns->prefix_len);
      ZX_OUT_CH(p, ':');
    }
    ZX_OUT_MEM(p, ZX_ANY_EL(x)->name, ZX_ANY_EL(x)->name_len);
    zx_add_xmlns_if_not_seen(c, x->g.ns, &pop_seen);
    
    /* *** xmlns specs */ 
    p = zx_enc_seen(p, pop_seen); 
    p = zx_enc_unknown_attrs(p, ZX_ANY_EL(x)->gg.any_attr);
  
    for (kid = x->kids; kid; kid = ((struct zx_elem_s*)(kid->g.wo)))
      p = zx_ENC_WO_any_elem(c, kid, p);
  
    ZX_OUT_CH(p, '<');
    ZX_OUT_CH(p, '/');
    if (x->g.ns && x->g.ns->prefix_len) {
      ZX_OUT_MEM(p, x->g.ns->prefix, x->g.ns->prefix_len);
      ZX_OUT_CH(p, ':');
    }
    ZX_OUT_MEM(p, ZX_ANY_EL(x)->name, ZX_ANY_EL(x)->name_len);
    ZX_OUT_CH(p, '>');
    zx_pop_seen(pop_seen);
    break;
  case ZX_TOK_DATA:
    ZX_OUT_STR(p, x);
    break;
  default:
    NEVER("Impossible token(%d)", x->g.tok);
  }
  return p;
}

/* FUNC(zx_EASY_ENC_WO_any_elem) */

/* Called by: */
struct zx_str* zx_EASY_ENC_WO_any_elem(struct zx_ctx* c, struct zx_elem_s* x)
{
  int len = zx_LEN_WO_any_elem(c, x);
  char* buf = ZX_ALLOC(c, len+1);
  return zx_easy_enc_common(c, zx_ENC_WO_any_elem(c, x, buf), buf, len);
}

/* EOF -- c/zx-enc.c */
