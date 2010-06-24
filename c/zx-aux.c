/* c/zx-aux.c - WARNING: This file was automatically generated. DO NOT EDIT!
 * $Id$ */
/* Code generation design Copyright (c) 2006 Sampo Kellomaki (sampo@iki.fi),
 * All Rights Reserved. NO WARRANTY. See file COPYING for terms and conditions
 * of use. Some aspects of code generation were driven by schema
 * descriptions that were used as input and may be subject to their own copyright.
 * Code generation uses a template, whose copyright statement follows. */

/** aux-templ.c  -  Auxiliary functions template: cloning, freeing, walking data
 ** Copyright (c) 2006 Symlabs (symlabs@symlabs.com), All Rights Reserved.
 ** Author: Sampo Kellomaki (sampo@iki.fi)
 ** This is confidential unpublished proprietary source code of the author.
 ** NO WARRANTY, not even implied warranties. Contains trade secrets.
 ** Distribution prohibited unless authorized in writing.
 ** Licensed under Apache License 2.0, see file COPYING.
 ** Id: aux-templ.c,v 1.12 2008-10-04 23:42:14 sampo Exp $
 **
 ** 30.5.2006, created, Sampo Kellomaki (sampo@iki.fi)
 ** 6.8.2006, factored from enc-templ.c to separate file --Sampo
 **
 ** N.B: wo=wire order (needed for exc-c14n), so=schema order
 **/

#include <memory.h>
#include "errmac.h"
#include "zx.h"
#include "c/zx-const.h"
#include "c/zx-data.h"



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

/* FUNC(zx_FREE_root) */

/* Depth first traversal of data structure to free it and its subelements. Simple
 * strings are handled as a special case according to the free_strs flag. This
 * is useful if the strings point to underlying data from the wire that was
 * allocated differently. */

/* Called by: */
void zx_FREE_root(struct zx_ctx* c, struct zx_root_s* x, int free_strs)
{
  /* *** deal with xmlns specifications in exc c14n way */


  {
      struct zx_sa_Assertion_s* e;
      struct zx_sa_Assertion_s* en;
      for (e = x->Assertion; e; e = en) {
	  en = (struct zx_sa_Assertion_s*)e->gg.g.n;
	  zx_FREE_sa_Assertion(c, e, free_strs);
      }
  }
  {
      struct zx_sa_NameID_s* e;
      struct zx_sa_NameID_s* en;
      for (e = x->NameID; e; e = en) {
	  en = (struct zx_sa_NameID_s*)e->gg.g.n;
	  zx_FREE_sa_NameID(c, e, free_strs);
      }
  }
  zx_free_simple_elems(c, x->NewID, free_strs);
  {
      struct zx_sp_AuthnRequest_s* e;
      struct zx_sp_AuthnRequest_s* en;
      for (e = x->AuthnRequest; e; e = en) {
	  en = (struct zx_sp_AuthnRequest_s*)e->gg.g.n;
	  zx_FREE_sp_AuthnRequest(c, e, free_strs);
      }
  }
  {
      struct zx_sp_Response_s* e;
      struct zx_sp_Response_s* en;
      for (e = x->Response; e; e = en) {
	  en = (struct zx_sp_Response_s*)e->gg.g.n;
	  zx_FREE_sp_Response(c, e, free_strs);
      }
  }
  {
      struct zx_sp_LogoutRequest_s* e;
      struct zx_sp_LogoutRequest_s* en;
      for (e = x->LogoutRequest; e; e = en) {
	  en = (struct zx_sp_LogoutRequest_s*)e->gg.g.n;
	  zx_FREE_sp_LogoutRequest(c, e, free_strs);
      }
  }
  {
      struct zx_sp_LogoutResponse_s* e;
      struct zx_sp_LogoutResponse_s* en;
      for (e = x->LogoutResponse; e; e = en) {
	  en = (struct zx_sp_LogoutResponse_s*)e->gg.g.n;
	  zx_FREE_sp_LogoutResponse(c, e, free_strs);
      }
  }
  {
      struct zx_sp_ManageNameIDRequest_s* e;
      struct zx_sp_ManageNameIDRequest_s* en;
      for (e = x->ManageNameIDRequest; e; e = en) {
	  en = (struct zx_sp_ManageNameIDRequest_s*)e->gg.g.n;
	  zx_FREE_sp_ManageNameIDRequest(c, e, free_strs);
      }
  }
  {
      struct zx_sp_ManageNameIDResponse_s* e;
      struct zx_sp_ManageNameIDResponse_s* en;
      for (e = x->ManageNameIDResponse; e; e = en) {
	  en = (struct zx_sp_ManageNameIDResponse_s*)e->gg.g.n;
	  zx_FREE_sp_ManageNameIDResponse(c, e, free_strs);
      }
  }
  {
      struct zx_e_Envelope_s* e;
      struct zx_e_Envelope_s* en;
      for (e = x->Envelope; e; e = en) {
	  en = (struct zx_e_Envelope_s*)e->gg.g.n;
	  zx_FREE_e_Envelope(c, e, free_strs);
      }
  }
  {
      struct zx_e_Header_s* e;
      struct zx_e_Header_s* en;
      for (e = x->Header; e; e = en) {
	  en = (struct zx_e_Header_s*)e->gg.g.n;
	  zx_FREE_e_Header(c, e, free_strs);
      }
  }
  {
      struct zx_e_Body_s* e;
      struct zx_e_Body_s* en;
      for (e = x->Body; e; e = en) {
	  en = (struct zx_e_Body_s*)e->gg.g.n;
	  zx_FREE_e_Body(c, e, free_strs);
      }
  }
  {
      struct zx_md_EntityDescriptor_s* e;
      struct zx_md_EntityDescriptor_s* en;
      for (e = x->EntityDescriptor; e; e = en) {
	  en = (struct zx_md_EntityDescriptor_s*)e->gg.g.n;
	  zx_FREE_md_EntityDescriptor(c, e, free_strs);
      }
  }
  {
      struct zx_md_EntitiesDescriptor_s* e;
      struct zx_md_EntitiesDescriptor_s* en;
      for (e = x->EntitiesDescriptor; e; e = en) {
	  en = (struct zx_md_EntitiesDescriptor_s*)e->gg.g.n;
	  zx_FREE_md_EntitiesDescriptor(c, e, free_strs);
      }
  }
  {
      struct zx_sa11_Assertion_s* e;
      struct zx_sa11_Assertion_s* en;
      for (e = x->sa11_Assertion; e; e = en) {
	  en = (struct zx_sa11_Assertion_s*)e->gg.g.n;
	  zx_FREE_sa11_Assertion(c, e, free_strs);
      }
  }
  {
      struct zx_sp11_Request_s* e;
      struct zx_sp11_Request_s* en;
      for (e = x->Request; e; e = en) {
	  en = (struct zx_sp11_Request_s*)e->gg.g.n;
	  zx_FREE_sp11_Request(c, e, free_strs);
      }
  }
  {
      struct zx_sp11_Response_s* e;
      struct zx_sp11_Response_s* en;
      for (e = x->sp11_Response; e; e = en) {
	  en = (struct zx_sp11_Response_s*)e->gg.g.n;
	  zx_FREE_sp11_Response(c, e, free_strs);
      }
  }
  {
      struct zx_ff12_Assertion_s* e;
      struct zx_ff12_Assertion_s* en;
      for (e = x->ff12_Assertion; e; e = en) {
	  en = (struct zx_ff12_Assertion_s*)e->gg.g.n;
	  zx_FREE_ff12_Assertion(c, e, free_strs);
      }
  }
  {
      struct zx_ff12_AuthnRequest_s* e;
      struct zx_ff12_AuthnRequest_s* en;
      for (e = x->ff12_AuthnRequest; e; e = en) {
	  en = (struct zx_ff12_AuthnRequest_s*)e->gg.g.n;
	  zx_FREE_ff12_AuthnRequest(c, e, free_strs);
      }
  }
  {
      struct zx_ff12_AuthnResponse_s* e;
      struct zx_ff12_AuthnResponse_s* en;
      for (e = x->AuthnResponse; e; e = en) {
	  en = (struct zx_ff12_AuthnResponse_s*)e->gg.g.n;
	  zx_FREE_ff12_AuthnResponse(c, e, free_strs);
      }
  }
  {
      struct zx_ff12_AuthnRequestEnvelope_s* e;
      struct zx_ff12_AuthnRequestEnvelope_s* en;
      for (e = x->AuthnRequestEnvelope; e; e = en) {
	  en = (struct zx_ff12_AuthnRequestEnvelope_s*)e->gg.g.n;
	  zx_FREE_ff12_AuthnRequestEnvelope(c, e, free_strs);
      }
  }
  {
      struct zx_ff12_AuthnResponseEnvelope_s* e;
      struct zx_ff12_AuthnResponseEnvelope_s* en;
      for (e = x->AuthnResponseEnvelope; e; e = en) {
	  en = (struct zx_ff12_AuthnResponseEnvelope_s*)e->gg.g.n;
	  zx_FREE_ff12_AuthnResponseEnvelope(c, e, free_strs);
      }
  }
  {
      struct zx_ff12_RegisterNameIdentifierRequest_s* e;
      struct zx_ff12_RegisterNameIdentifierRequest_s* en;
      for (e = x->RegisterNameIdentifierRequest; e; e = en) {
	  en = (struct zx_ff12_RegisterNameIdentifierRequest_s*)e->gg.g.n;
	  zx_FREE_ff12_RegisterNameIdentifierRequest(c, e, free_strs);
      }
  }
  {
      struct zx_ff12_RegisterNameIdentifierResponse_s* e;
      struct zx_ff12_RegisterNameIdentifierResponse_s* en;
      for (e = x->RegisterNameIdentifierResponse; e; e = en) {
	  en = (struct zx_ff12_RegisterNameIdentifierResponse_s*)e->gg.g.n;
	  zx_FREE_ff12_RegisterNameIdentifierResponse(c, e, free_strs);
      }
  }
  {
      struct zx_ff12_FederationTerminationNotification_s* e;
      struct zx_ff12_FederationTerminationNotification_s* en;
      for (e = x->FederationTerminationNotification; e; e = en) {
	  en = (struct zx_ff12_FederationTerminationNotification_s*)e->gg.g.n;
	  zx_FREE_ff12_FederationTerminationNotification(c, e, free_strs);
      }
  }
  {
      struct zx_ff12_LogoutRequest_s* e;
      struct zx_ff12_LogoutRequest_s* en;
      for (e = x->ff12_LogoutRequest; e; e = en) {
	  en = (struct zx_ff12_LogoutRequest_s*)e->gg.g.n;
	  zx_FREE_ff12_LogoutRequest(c, e, free_strs);
      }
  }
  {
      struct zx_ff12_LogoutResponse_s* e;
      struct zx_ff12_LogoutResponse_s* en;
      for (e = x->ff12_LogoutResponse; e; e = en) {
	  en = (struct zx_ff12_LogoutResponse_s*)e->gg.g.n;
	  zx_FREE_ff12_LogoutResponse(c, e, free_strs);
      }
  }
  {
      struct zx_ff12_NameIdentifierMappingRequest_s* e;
      struct zx_ff12_NameIdentifierMappingRequest_s* en;
      for (e = x->NameIdentifierMappingRequest; e; e = en) {
	  en = (struct zx_ff12_NameIdentifierMappingRequest_s*)e->gg.g.n;
	  zx_FREE_ff12_NameIdentifierMappingRequest(c, e, free_strs);
      }
  }
  {
      struct zx_ff12_NameIdentifierMappingResponse_s* e;
      struct zx_ff12_NameIdentifierMappingResponse_s* en;
      for (e = x->NameIdentifierMappingResponse; e; e = en) {
	  en = (struct zx_ff12_NameIdentifierMappingResponse_s*)e->gg.g.n;
	  zx_FREE_ff12_NameIdentifierMappingResponse(c, e, free_strs);
      }
  }
  {
      struct zx_m20_EntityDescriptor_s* e;
      struct zx_m20_EntityDescriptor_s* en;
      for (e = x->m20_EntityDescriptor; e; e = en) {
	  en = (struct zx_m20_EntityDescriptor_s*)e->gg.g.n;
	  zx_FREE_m20_EntityDescriptor(c, e, free_strs);
      }
  }
  {
      struct zx_m20_EntitiesDescriptor_s* e;
      struct zx_m20_EntitiesDescriptor_s* en;
      for (e = x->m20_EntitiesDescriptor; e; e = en) {
	  en = (struct zx_m20_EntitiesDescriptor_s*)e->gg.g.n;
	  zx_FREE_m20_EntitiesDescriptor(c, e, free_strs);
      }
  }
  {
      struct zx_a_EndpointReference_s* e;
      struct zx_a_EndpointReference_s* en;
      for (e = x->EndpointReference; e; e = en) {
	  en = (struct zx_a_EndpointReference_s*)e->gg.g.n;
	  zx_FREE_a_EndpointReference(c, e, free_strs);
      }
  }
  {
      struct zx_hrxml_Candidate_s* e;
      struct zx_hrxml_Candidate_s* en;
      for (e = x->Candidate; e; e = en) {
	  en = (struct zx_hrxml_Candidate_s*)e->gg.g.n;
	  zx_FREE_hrxml_Candidate(c, e, free_strs);
      }
  }
  {
      struct zx_xasp_XACMLAuthzDecisionQuery_s* e;
      struct zx_xasp_XACMLAuthzDecisionQuery_s* en;
      for (e = x->XACMLAuthzDecisionQuery; e; e = en) {
	  en = (struct zx_xasp_XACMLAuthzDecisionQuery_s*)e->gg.g.n;
	  zx_FREE_xasp_XACMLAuthzDecisionQuery(c, e, free_strs);
      }
  }
  {
      struct zx_xasp_XACMLPolicyQuery_s* e;
      struct zx_xasp_XACMLPolicyQuery_s* en;
      for (e = x->XACMLPolicyQuery; e; e = en) {
	  en = (struct zx_xasp_XACMLPolicyQuery_s*)e->gg.g.n;
	  zx_FREE_xasp_XACMLPolicyQuery(c, e, free_strs);
      }
  }
  {
      struct zx_xaspcd1_XACMLAuthzDecisionQuery_s* e;
      struct zx_xaspcd1_XACMLAuthzDecisionQuery_s* en;
      for (e = x->xaspcd1_XACMLAuthzDecisionQuery; e; e = en) {
	  en = (struct zx_xaspcd1_XACMLAuthzDecisionQuery_s*)e->gg.g.n;
	  zx_FREE_xaspcd1_XACMLAuthzDecisionQuery(c, e, free_strs);
      }
  }
  {
      struct zx_xaspcd1_XACMLPolicyQuery_s* e;
      struct zx_xaspcd1_XACMLPolicyQuery_s* en;
      for (e = x->xaspcd1_XACMLPolicyQuery; e; e = en) {
	  en = (struct zx_xaspcd1_XACMLPolicyQuery_s*)e->gg.g.n;
	  zx_FREE_xaspcd1_XACMLPolicyQuery(c, e, free_strs);
      }
  }


  zx_free_elem_common(c, &x->gg, free_strs); 
}

/* FUNC(zx_NEW_root) */

/* Trivial allocator/constructor for the datatype. */

/* Called by: */
struct zx_root_s* zx_NEW_root(struct zx_ctx* c)
{
  struct zx_root_s* x = ZX_ZALLOC(c, struct zx_root_s);
  x->gg.g.tok = zx_root_ELEM;
  return x;
}

#ifdef ZX_ENA_AUX

/* FUNC(zx_DUP_STRS_root) */

/* Depth first traversal of data structure to copy its simple strings
 * to memory allocated from the memory allocator. The decoder will
 * use the underlying wireprotocol PDU buffer for strings, i.e.
 * strings are not copied - they point to the real data. If the
 * datastructure needs to outlast the protocol data or needs a different
 * memory allocation strategy, you need to call this function.  */

/* Called by: */
void zx_DUP_STRS_root(struct zx_ctx* c, struct zx_root_s* x)
{
  zx_dup_strs_common(c, &x->gg);
  /* *** deal with xmlns specifications in exc c14n way */


  {
      struct zx_sa_Assertion_s* e;
      for (e = x->Assertion; e; e = (struct zx_sa_Assertion_s*)e->gg.g.n)
	  zx_DUP_STRS_sa_Assertion(c, e);
  }
  {
      struct zx_sa_NameID_s* e;
      for (e = x->NameID; e; e = (struct zx_sa_NameID_s*)e->gg.g.n)
	  zx_DUP_STRS_sa_NameID(c, e);
  }
  zx_dup_strs_simple_elems(c, x->NewID);
  {
      struct zx_sp_AuthnRequest_s* e;
      for (e = x->AuthnRequest; e; e = (struct zx_sp_AuthnRequest_s*)e->gg.g.n)
	  zx_DUP_STRS_sp_AuthnRequest(c, e);
  }
  {
      struct zx_sp_Response_s* e;
      for (e = x->Response; e; e = (struct zx_sp_Response_s*)e->gg.g.n)
	  zx_DUP_STRS_sp_Response(c, e);
  }
  {
      struct zx_sp_LogoutRequest_s* e;
      for (e = x->LogoutRequest; e; e = (struct zx_sp_LogoutRequest_s*)e->gg.g.n)
	  zx_DUP_STRS_sp_LogoutRequest(c, e);
  }
  {
      struct zx_sp_LogoutResponse_s* e;
      for (e = x->LogoutResponse; e; e = (struct zx_sp_LogoutResponse_s*)e->gg.g.n)
	  zx_DUP_STRS_sp_LogoutResponse(c, e);
  }
  {
      struct zx_sp_ManageNameIDRequest_s* e;
      for (e = x->ManageNameIDRequest; e; e = (struct zx_sp_ManageNameIDRequest_s*)e->gg.g.n)
	  zx_DUP_STRS_sp_ManageNameIDRequest(c, e);
  }
  {
      struct zx_sp_ManageNameIDResponse_s* e;
      for (e = x->ManageNameIDResponse; e; e = (struct zx_sp_ManageNameIDResponse_s*)e->gg.g.n)
	  zx_DUP_STRS_sp_ManageNameIDResponse(c, e);
  }
  {
      struct zx_e_Envelope_s* e;
      for (e = x->Envelope; e; e = (struct zx_e_Envelope_s*)e->gg.g.n)
	  zx_DUP_STRS_e_Envelope(c, e);
  }
  {
      struct zx_e_Header_s* e;
      for (e = x->Header; e; e = (struct zx_e_Header_s*)e->gg.g.n)
	  zx_DUP_STRS_e_Header(c, e);
  }
  {
      struct zx_e_Body_s* e;
      for (e = x->Body; e; e = (struct zx_e_Body_s*)e->gg.g.n)
	  zx_DUP_STRS_e_Body(c, e);
  }
  {
      struct zx_md_EntityDescriptor_s* e;
      for (e = x->EntityDescriptor; e; e = (struct zx_md_EntityDescriptor_s*)e->gg.g.n)
	  zx_DUP_STRS_md_EntityDescriptor(c, e);
  }
  {
      struct zx_md_EntitiesDescriptor_s* e;
      for (e = x->EntitiesDescriptor; e; e = (struct zx_md_EntitiesDescriptor_s*)e->gg.g.n)
	  zx_DUP_STRS_md_EntitiesDescriptor(c, e);
  }
  {
      struct zx_sa11_Assertion_s* e;
      for (e = x->sa11_Assertion; e; e = (struct zx_sa11_Assertion_s*)e->gg.g.n)
	  zx_DUP_STRS_sa11_Assertion(c, e);
  }
  {
      struct zx_sp11_Request_s* e;
      for (e = x->Request; e; e = (struct zx_sp11_Request_s*)e->gg.g.n)
	  zx_DUP_STRS_sp11_Request(c, e);
  }
  {
      struct zx_sp11_Response_s* e;
      for (e = x->sp11_Response; e; e = (struct zx_sp11_Response_s*)e->gg.g.n)
	  zx_DUP_STRS_sp11_Response(c, e);
  }
  {
      struct zx_ff12_Assertion_s* e;
      for (e = x->ff12_Assertion; e; e = (struct zx_ff12_Assertion_s*)e->gg.g.n)
	  zx_DUP_STRS_ff12_Assertion(c, e);
  }
  {
      struct zx_ff12_AuthnRequest_s* e;
      for (e = x->ff12_AuthnRequest; e; e = (struct zx_ff12_AuthnRequest_s*)e->gg.g.n)
	  zx_DUP_STRS_ff12_AuthnRequest(c, e);
  }
  {
      struct zx_ff12_AuthnResponse_s* e;
      for (e = x->AuthnResponse; e; e = (struct zx_ff12_AuthnResponse_s*)e->gg.g.n)
	  zx_DUP_STRS_ff12_AuthnResponse(c, e);
  }
  {
      struct zx_ff12_AuthnRequestEnvelope_s* e;
      for (e = x->AuthnRequestEnvelope; e; e = (struct zx_ff12_AuthnRequestEnvelope_s*)e->gg.g.n)
	  zx_DUP_STRS_ff12_AuthnRequestEnvelope(c, e);
  }
  {
      struct zx_ff12_AuthnResponseEnvelope_s* e;
      for (e = x->AuthnResponseEnvelope; e; e = (struct zx_ff12_AuthnResponseEnvelope_s*)e->gg.g.n)
	  zx_DUP_STRS_ff12_AuthnResponseEnvelope(c, e);
  }
  {
      struct zx_ff12_RegisterNameIdentifierRequest_s* e;
      for (e = x->RegisterNameIdentifierRequest; e; e = (struct zx_ff12_RegisterNameIdentifierRequest_s*)e->gg.g.n)
	  zx_DUP_STRS_ff12_RegisterNameIdentifierRequest(c, e);
  }
  {
      struct zx_ff12_RegisterNameIdentifierResponse_s* e;
      for (e = x->RegisterNameIdentifierResponse; e; e = (struct zx_ff12_RegisterNameIdentifierResponse_s*)e->gg.g.n)
	  zx_DUP_STRS_ff12_RegisterNameIdentifierResponse(c, e);
  }
  {
      struct zx_ff12_FederationTerminationNotification_s* e;
      for (e = x->FederationTerminationNotification; e; e = (struct zx_ff12_FederationTerminationNotification_s*)e->gg.g.n)
	  zx_DUP_STRS_ff12_FederationTerminationNotification(c, e);
  }
  {
      struct zx_ff12_LogoutRequest_s* e;
      for (e = x->ff12_LogoutRequest; e; e = (struct zx_ff12_LogoutRequest_s*)e->gg.g.n)
	  zx_DUP_STRS_ff12_LogoutRequest(c, e);
  }
  {
      struct zx_ff12_LogoutResponse_s* e;
      for (e = x->ff12_LogoutResponse; e; e = (struct zx_ff12_LogoutResponse_s*)e->gg.g.n)
	  zx_DUP_STRS_ff12_LogoutResponse(c, e);
  }
  {
      struct zx_ff12_NameIdentifierMappingRequest_s* e;
      for (e = x->NameIdentifierMappingRequest; e; e = (struct zx_ff12_NameIdentifierMappingRequest_s*)e->gg.g.n)
	  zx_DUP_STRS_ff12_NameIdentifierMappingRequest(c, e);
  }
  {
      struct zx_ff12_NameIdentifierMappingResponse_s* e;
      for (e = x->NameIdentifierMappingResponse; e; e = (struct zx_ff12_NameIdentifierMappingResponse_s*)e->gg.g.n)
	  zx_DUP_STRS_ff12_NameIdentifierMappingResponse(c, e);
  }
  {
      struct zx_m20_EntityDescriptor_s* e;
      for (e = x->m20_EntityDescriptor; e; e = (struct zx_m20_EntityDescriptor_s*)e->gg.g.n)
	  zx_DUP_STRS_m20_EntityDescriptor(c, e);
  }
  {
      struct zx_m20_EntitiesDescriptor_s* e;
      for (e = x->m20_EntitiesDescriptor; e; e = (struct zx_m20_EntitiesDescriptor_s*)e->gg.g.n)
	  zx_DUP_STRS_m20_EntitiesDescriptor(c, e);
  }
  {
      struct zx_a_EndpointReference_s* e;
      for (e = x->EndpointReference; e; e = (struct zx_a_EndpointReference_s*)e->gg.g.n)
	  zx_DUP_STRS_a_EndpointReference(c, e);
  }
  {
      struct zx_hrxml_Candidate_s* e;
      for (e = x->Candidate; e; e = (struct zx_hrxml_Candidate_s*)e->gg.g.n)
	  zx_DUP_STRS_hrxml_Candidate(c, e);
  }
  {
      struct zx_xasp_XACMLAuthzDecisionQuery_s* e;
      for (e = x->XACMLAuthzDecisionQuery; e; e = (struct zx_xasp_XACMLAuthzDecisionQuery_s*)e->gg.g.n)
	  zx_DUP_STRS_xasp_XACMLAuthzDecisionQuery(c, e);
  }
  {
      struct zx_xasp_XACMLPolicyQuery_s* e;
      for (e = x->XACMLPolicyQuery; e; e = (struct zx_xasp_XACMLPolicyQuery_s*)e->gg.g.n)
	  zx_DUP_STRS_xasp_XACMLPolicyQuery(c, e);
  }
  {
      struct zx_xaspcd1_XACMLAuthzDecisionQuery_s* e;
      for (e = x->xaspcd1_XACMLAuthzDecisionQuery; e; e = (struct zx_xaspcd1_XACMLAuthzDecisionQuery_s*)e->gg.g.n)
	  zx_DUP_STRS_xaspcd1_XACMLAuthzDecisionQuery(c, e);
  }
  {
      struct zx_xaspcd1_XACMLPolicyQuery_s* e;
      for (e = x->xaspcd1_XACMLPolicyQuery; e; e = (struct zx_xaspcd1_XACMLPolicyQuery_s*)e->gg.g.n)
	  zx_DUP_STRS_xaspcd1_XACMLPolicyQuery(c, e);
  }

}

/* FUNC(zx_DEEP_CLONE_root) */

/* Depth first traversal of data structure to clone it and its sublements.
 * The simple strings are handled as a special case according to dup_strs flag. */

/* Called by: */
struct zx_root_s* zx_DEEP_CLONE_root(struct zx_ctx* c, struct zx_root_s* x, int dup_strs)
{
  x = (struct zx_root_s*)zx_clone_elem_common(c, &x->gg, sizeof(struct zx_root_s), dup_strs);
  /* *** deal with xmlns specifications in exc c14n way */


  {
      struct zx_sa_Assertion_s* e;
      struct zx_sa_Assertion_s* en;
      struct zx_sa_Assertion_s* enn;
      for (enn = 0, e = x->Assertion; e; e = (struct zx_sa_Assertion_s*)e->gg.g.n) {
	  en = zx_DEEP_CLONE_sa_Assertion(c, e, dup_strs);
	  if (!enn)
	      x->Assertion = en;
	  else
	      enn->gg.g.n = &en->gg.g;
	  enn = en;
      }
  }
  {
      struct zx_sa_NameID_s* e;
      struct zx_sa_NameID_s* en;
      struct zx_sa_NameID_s* enn;
      for (enn = 0, e = x->NameID; e; e = (struct zx_sa_NameID_s*)e->gg.g.n) {
	  en = zx_DEEP_CLONE_sa_NameID(c, e, dup_strs);
	  if (!enn)
	      x->NameID = en;
	  else
	      enn->gg.g.n = &en->gg.g;
	  enn = en;
      }
  }
  x->NewID = zx_deep_clone_simple_elems(c,x->NewID, dup_strs);
  {
      struct zx_sp_AuthnRequest_s* e;
      struct zx_sp_AuthnRequest_s* en;
      struct zx_sp_AuthnRequest_s* enn;
      for (enn = 0, e = x->AuthnRequest; e; e = (struct zx_sp_AuthnRequest_s*)e->gg.g.n) {
	  en = zx_DEEP_CLONE_sp_AuthnRequest(c, e, dup_strs);
	  if (!enn)
	      x->AuthnRequest = en;
	  else
	      enn->gg.g.n = &en->gg.g;
	  enn = en;
      }
  }
  {
      struct zx_sp_Response_s* e;
      struct zx_sp_Response_s* en;
      struct zx_sp_Response_s* enn;
      for (enn = 0, e = x->Response; e; e = (struct zx_sp_Response_s*)e->gg.g.n) {
	  en = zx_DEEP_CLONE_sp_Response(c, e, dup_strs);
	  if (!enn)
	      x->Response = en;
	  else
	      enn->gg.g.n = &en->gg.g;
	  enn = en;
      }
  }
  {
      struct zx_sp_LogoutRequest_s* e;
      struct zx_sp_LogoutRequest_s* en;
      struct zx_sp_LogoutRequest_s* enn;
      for (enn = 0, e = x->LogoutRequest; e; e = (struct zx_sp_LogoutRequest_s*)e->gg.g.n) {
	  en = zx_DEEP_CLONE_sp_LogoutRequest(c, e, dup_strs);
	  if (!enn)
	      x->LogoutRequest = en;
	  else
	      enn->gg.g.n = &en->gg.g;
	  enn = en;
      }
  }
  {
      struct zx_sp_LogoutResponse_s* e;
      struct zx_sp_LogoutResponse_s* en;
      struct zx_sp_LogoutResponse_s* enn;
      for (enn = 0, e = x->LogoutResponse; e; e = (struct zx_sp_LogoutResponse_s*)e->gg.g.n) {
	  en = zx_DEEP_CLONE_sp_LogoutResponse(c, e, dup_strs);
	  if (!enn)
	      x->LogoutResponse = en;
	  else
	      enn->gg.g.n = &en->gg.g;
	  enn = en;
      }
  }
  {
      struct zx_sp_ManageNameIDRequest_s* e;
      struct zx_sp_ManageNameIDRequest_s* en;
      struct zx_sp_ManageNameIDRequest_s* enn;
      for (enn = 0, e = x->ManageNameIDRequest; e; e = (struct zx_sp_ManageNameIDRequest_s*)e->gg.g.n) {
	  en = zx_DEEP_CLONE_sp_ManageNameIDRequest(c, e, dup_strs);
	  if (!enn)
	      x->ManageNameIDRequest = en;
	  else
	      enn->gg.g.n = &en->gg.g;
	  enn = en;
      }
  }
  {
      struct zx_sp_ManageNameIDResponse_s* e;
      struct zx_sp_ManageNameIDResponse_s* en;
      struct zx_sp_ManageNameIDResponse_s* enn;
      for (enn = 0, e = x->ManageNameIDResponse; e; e = (struct zx_sp_ManageNameIDResponse_s*)e->gg.g.n) {
	  en = zx_DEEP_CLONE_sp_ManageNameIDResponse(c, e, dup_strs);
	  if (!enn)
	      x->ManageNameIDResponse = en;
	  else
	      enn->gg.g.n = &en->gg.g;
	  enn = en;
      }
  }
  {
      struct zx_e_Envelope_s* e;
      struct zx_e_Envelope_s* en;
      struct zx_e_Envelope_s* enn;
      for (enn = 0, e = x->Envelope; e; e = (struct zx_e_Envelope_s*)e->gg.g.n) {
	  en = zx_DEEP_CLONE_e_Envelope(c, e, dup_strs);
	  if (!enn)
	      x->Envelope = en;
	  else
	      enn->gg.g.n = &en->gg.g;
	  enn = en;
      }
  }
  {
      struct zx_e_Header_s* e;
      struct zx_e_Header_s* en;
      struct zx_e_Header_s* enn;
      for (enn = 0, e = x->Header; e; e = (struct zx_e_Header_s*)e->gg.g.n) {
	  en = zx_DEEP_CLONE_e_Header(c, e, dup_strs);
	  if (!enn)
	      x->Header = en;
	  else
	      enn->gg.g.n = &en->gg.g;
	  enn = en;
      }
  }
  {
      struct zx_e_Body_s* e;
      struct zx_e_Body_s* en;
      struct zx_e_Body_s* enn;
      for (enn = 0, e = x->Body; e; e = (struct zx_e_Body_s*)e->gg.g.n) {
	  en = zx_DEEP_CLONE_e_Body(c, e, dup_strs);
	  if (!enn)
	      x->Body = en;
	  else
	      enn->gg.g.n = &en->gg.g;
	  enn = en;
      }
  }
  {
      struct zx_md_EntityDescriptor_s* e;
      struct zx_md_EntityDescriptor_s* en;
      struct zx_md_EntityDescriptor_s* enn;
      for (enn = 0, e = x->EntityDescriptor; e; e = (struct zx_md_EntityDescriptor_s*)e->gg.g.n) {
	  en = zx_DEEP_CLONE_md_EntityDescriptor(c, e, dup_strs);
	  if (!enn)
	      x->EntityDescriptor = en;
	  else
	      enn->gg.g.n = &en->gg.g;
	  enn = en;
      }
  }
  {
      struct zx_md_EntitiesDescriptor_s* e;
      struct zx_md_EntitiesDescriptor_s* en;
      struct zx_md_EntitiesDescriptor_s* enn;
      for (enn = 0, e = x->EntitiesDescriptor; e; e = (struct zx_md_EntitiesDescriptor_s*)e->gg.g.n) {
	  en = zx_DEEP_CLONE_md_EntitiesDescriptor(c, e, dup_strs);
	  if (!enn)
	      x->EntitiesDescriptor = en;
	  else
	      enn->gg.g.n = &en->gg.g;
	  enn = en;
      }
  }
  {
      struct zx_sa11_Assertion_s* e;
      struct zx_sa11_Assertion_s* en;
      struct zx_sa11_Assertion_s* enn;
      for (enn = 0, e = x->sa11_Assertion; e; e = (struct zx_sa11_Assertion_s*)e->gg.g.n) {
	  en = zx_DEEP_CLONE_sa11_Assertion(c, e, dup_strs);
	  if (!enn)
	      x->sa11_Assertion = en;
	  else
	      enn->gg.g.n = &en->gg.g;
	  enn = en;
      }
  }
  {
      struct zx_sp11_Request_s* e;
      struct zx_sp11_Request_s* en;
      struct zx_sp11_Request_s* enn;
      for (enn = 0, e = x->Request; e; e = (struct zx_sp11_Request_s*)e->gg.g.n) {
	  en = zx_DEEP_CLONE_sp11_Request(c, e, dup_strs);
	  if (!enn)
	      x->Request = en;
	  else
	      enn->gg.g.n = &en->gg.g;
	  enn = en;
      }
  }
  {
      struct zx_sp11_Response_s* e;
      struct zx_sp11_Response_s* en;
      struct zx_sp11_Response_s* enn;
      for (enn = 0, e = x->sp11_Response; e; e = (struct zx_sp11_Response_s*)e->gg.g.n) {
	  en = zx_DEEP_CLONE_sp11_Response(c, e, dup_strs);
	  if (!enn)
	      x->sp11_Response = en;
	  else
	      enn->gg.g.n = &en->gg.g;
	  enn = en;
      }
  }
  {
      struct zx_ff12_Assertion_s* e;
      struct zx_ff12_Assertion_s* en;
      struct zx_ff12_Assertion_s* enn;
      for (enn = 0, e = x->ff12_Assertion; e; e = (struct zx_ff12_Assertion_s*)e->gg.g.n) {
	  en = zx_DEEP_CLONE_ff12_Assertion(c, e, dup_strs);
	  if (!enn)
	      x->ff12_Assertion = en;
	  else
	      enn->gg.g.n = &en->gg.g;
	  enn = en;
      }
  }
  {
      struct zx_ff12_AuthnRequest_s* e;
      struct zx_ff12_AuthnRequest_s* en;
      struct zx_ff12_AuthnRequest_s* enn;
      for (enn = 0, e = x->ff12_AuthnRequest; e; e = (struct zx_ff12_AuthnRequest_s*)e->gg.g.n) {
	  en = zx_DEEP_CLONE_ff12_AuthnRequest(c, e, dup_strs);
	  if (!enn)
	      x->ff12_AuthnRequest = en;
	  else
	      enn->gg.g.n = &en->gg.g;
	  enn = en;
      }
  }
  {
      struct zx_ff12_AuthnResponse_s* e;
      struct zx_ff12_AuthnResponse_s* en;
      struct zx_ff12_AuthnResponse_s* enn;
      for (enn = 0, e = x->AuthnResponse; e; e = (struct zx_ff12_AuthnResponse_s*)e->gg.g.n) {
	  en = zx_DEEP_CLONE_ff12_AuthnResponse(c, e, dup_strs);
	  if (!enn)
	      x->AuthnResponse = en;
	  else
	      enn->gg.g.n = &en->gg.g;
	  enn = en;
      }
  }
  {
      struct zx_ff12_AuthnRequestEnvelope_s* e;
      struct zx_ff12_AuthnRequestEnvelope_s* en;
      struct zx_ff12_AuthnRequestEnvelope_s* enn;
      for (enn = 0, e = x->AuthnRequestEnvelope; e; e = (struct zx_ff12_AuthnRequestEnvelope_s*)e->gg.g.n) {
	  en = zx_DEEP_CLONE_ff12_AuthnRequestEnvelope(c, e, dup_strs);
	  if (!enn)
	      x->AuthnRequestEnvelope = en;
	  else
	      enn->gg.g.n = &en->gg.g;
	  enn = en;
      }
  }
  {
      struct zx_ff12_AuthnResponseEnvelope_s* e;
      struct zx_ff12_AuthnResponseEnvelope_s* en;
      struct zx_ff12_AuthnResponseEnvelope_s* enn;
      for (enn = 0, e = x->AuthnResponseEnvelope; e; e = (struct zx_ff12_AuthnResponseEnvelope_s*)e->gg.g.n) {
	  en = zx_DEEP_CLONE_ff12_AuthnResponseEnvelope(c, e, dup_strs);
	  if (!enn)
	      x->AuthnResponseEnvelope = en;
	  else
	      enn->gg.g.n = &en->gg.g;
	  enn = en;
      }
  }
  {
      struct zx_ff12_RegisterNameIdentifierRequest_s* e;
      struct zx_ff12_RegisterNameIdentifierRequest_s* en;
      struct zx_ff12_RegisterNameIdentifierRequest_s* enn;
      for (enn = 0, e = x->RegisterNameIdentifierRequest; e; e = (struct zx_ff12_RegisterNameIdentifierRequest_s*)e->gg.g.n) {
	  en = zx_DEEP_CLONE_ff12_RegisterNameIdentifierRequest(c, e, dup_strs);
	  if (!enn)
	      x->RegisterNameIdentifierRequest = en;
	  else
	      enn->gg.g.n = &en->gg.g;
	  enn = en;
      }
  }
  {
      struct zx_ff12_RegisterNameIdentifierResponse_s* e;
      struct zx_ff12_RegisterNameIdentifierResponse_s* en;
      struct zx_ff12_RegisterNameIdentifierResponse_s* enn;
      for (enn = 0, e = x->RegisterNameIdentifierResponse; e; e = (struct zx_ff12_RegisterNameIdentifierResponse_s*)e->gg.g.n) {
	  en = zx_DEEP_CLONE_ff12_RegisterNameIdentifierResponse(c, e, dup_strs);
	  if (!enn)
	      x->RegisterNameIdentifierResponse = en;
	  else
	      enn->gg.g.n = &en->gg.g;
	  enn = en;
      }
  }
  {
      struct zx_ff12_FederationTerminationNotification_s* e;
      struct zx_ff12_FederationTerminationNotification_s* en;
      struct zx_ff12_FederationTerminationNotification_s* enn;
      for (enn = 0, e = x->FederationTerminationNotification; e; e = (struct zx_ff12_FederationTerminationNotification_s*)e->gg.g.n) {
	  en = zx_DEEP_CLONE_ff12_FederationTerminationNotification(c, e, dup_strs);
	  if (!enn)
	      x->FederationTerminationNotification = en;
	  else
	      enn->gg.g.n = &en->gg.g;
	  enn = en;
      }
  }
  {
      struct zx_ff12_LogoutRequest_s* e;
      struct zx_ff12_LogoutRequest_s* en;
      struct zx_ff12_LogoutRequest_s* enn;
      for (enn = 0, e = x->ff12_LogoutRequest; e; e = (struct zx_ff12_LogoutRequest_s*)e->gg.g.n) {
	  en = zx_DEEP_CLONE_ff12_LogoutRequest(c, e, dup_strs);
	  if (!enn)
	      x->ff12_LogoutRequest = en;
	  else
	      enn->gg.g.n = &en->gg.g;
	  enn = en;
      }
  }
  {
      struct zx_ff12_LogoutResponse_s* e;
      struct zx_ff12_LogoutResponse_s* en;
      struct zx_ff12_LogoutResponse_s* enn;
      for (enn = 0, e = x->ff12_LogoutResponse; e; e = (struct zx_ff12_LogoutResponse_s*)e->gg.g.n) {
	  en = zx_DEEP_CLONE_ff12_LogoutResponse(c, e, dup_strs);
	  if (!enn)
	      x->ff12_LogoutResponse = en;
	  else
	      enn->gg.g.n = &en->gg.g;
	  enn = en;
      }
  }
  {
      struct zx_ff12_NameIdentifierMappingRequest_s* e;
      struct zx_ff12_NameIdentifierMappingRequest_s* en;
      struct zx_ff12_NameIdentifierMappingRequest_s* enn;
      for (enn = 0, e = x->NameIdentifierMappingRequest; e; e = (struct zx_ff12_NameIdentifierMappingRequest_s*)e->gg.g.n) {
	  en = zx_DEEP_CLONE_ff12_NameIdentifierMappingRequest(c, e, dup_strs);
	  if (!enn)
	      x->NameIdentifierMappingRequest = en;
	  else
	      enn->gg.g.n = &en->gg.g;
	  enn = en;
      }
  }
  {
      struct zx_ff12_NameIdentifierMappingResponse_s* e;
      struct zx_ff12_NameIdentifierMappingResponse_s* en;
      struct zx_ff12_NameIdentifierMappingResponse_s* enn;
      for (enn = 0, e = x->NameIdentifierMappingResponse; e; e = (struct zx_ff12_NameIdentifierMappingResponse_s*)e->gg.g.n) {
	  en = zx_DEEP_CLONE_ff12_NameIdentifierMappingResponse(c, e, dup_strs);
	  if (!enn)
	      x->NameIdentifierMappingResponse = en;
	  else
	      enn->gg.g.n = &en->gg.g;
	  enn = en;
      }
  }
  {
      struct zx_m20_EntityDescriptor_s* e;
      struct zx_m20_EntityDescriptor_s* en;
      struct zx_m20_EntityDescriptor_s* enn;
      for (enn = 0, e = x->m20_EntityDescriptor; e; e = (struct zx_m20_EntityDescriptor_s*)e->gg.g.n) {
	  en = zx_DEEP_CLONE_m20_EntityDescriptor(c, e, dup_strs);
	  if (!enn)
	      x->m20_EntityDescriptor = en;
	  else
	      enn->gg.g.n = &en->gg.g;
	  enn = en;
      }
  }
  {
      struct zx_m20_EntitiesDescriptor_s* e;
      struct zx_m20_EntitiesDescriptor_s* en;
      struct zx_m20_EntitiesDescriptor_s* enn;
      for (enn = 0, e = x->m20_EntitiesDescriptor; e; e = (struct zx_m20_EntitiesDescriptor_s*)e->gg.g.n) {
	  en = zx_DEEP_CLONE_m20_EntitiesDescriptor(c, e, dup_strs);
	  if (!enn)
	      x->m20_EntitiesDescriptor = en;
	  else
	      enn->gg.g.n = &en->gg.g;
	  enn = en;
      }
  }
  {
      struct zx_a_EndpointReference_s* e;
      struct zx_a_EndpointReference_s* en;
      struct zx_a_EndpointReference_s* enn;
      for (enn = 0, e = x->EndpointReference; e; e = (struct zx_a_EndpointReference_s*)e->gg.g.n) {
	  en = zx_DEEP_CLONE_a_EndpointReference(c, e, dup_strs);
	  if (!enn)
	      x->EndpointReference = en;
	  else
	      enn->gg.g.n = &en->gg.g;
	  enn = en;
      }
  }
  {
      struct zx_hrxml_Candidate_s* e;
      struct zx_hrxml_Candidate_s* en;
      struct zx_hrxml_Candidate_s* enn;
      for (enn = 0, e = x->Candidate; e; e = (struct zx_hrxml_Candidate_s*)e->gg.g.n) {
	  en = zx_DEEP_CLONE_hrxml_Candidate(c, e, dup_strs);
	  if (!enn)
	      x->Candidate = en;
	  else
	      enn->gg.g.n = &en->gg.g;
	  enn = en;
      }
  }
  {
      struct zx_xasp_XACMLAuthzDecisionQuery_s* e;
      struct zx_xasp_XACMLAuthzDecisionQuery_s* en;
      struct zx_xasp_XACMLAuthzDecisionQuery_s* enn;
      for (enn = 0, e = x->XACMLAuthzDecisionQuery; e; e = (struct zx_xasp_XACMLAuthzDecisionQuery_s*)e->gg.g.n) {
	  en = zx_DEEP_CLONE_xasp_XACMLAuthzDecisionQuery(c, e, dup_strs);
	  if (!enn)
	      x->XACMLAuthzDecisionQuery = en;
	  else
	      enn->gg.g.n = &en->gg.g;
	  enn = en;
      }
  }
  {
      struct zx_xasp_XACMLPolicyQuery_s* e;
      struct zx_xasp_XACMLPolicyQuery_s* en;
      struct zx_xasp_XACMLPolicyQuery_s* enn;
      for (enn = 0, e = x->XACMLPolicyQuery; e; e = (struct zx_xasp_XACMLPolicyQuery_s*)e->gg.g.n) {
	  en = zx_DEEP_CLONE_xasp_XACMLPolicyQuery(c, e, dup_strs);
	  if (!enn)
	      x->XACMLPolicyQuery = en;
	  else
	      enn->gg.g.n = &en->gg.g;
	  enn = en;
      }
  }
  {
      struct zx_xaspcd1_XACMLAuthzDecisionQuery_s* e;
      struct zx_xaspcd1_XACMLAuthzDecisionQuery_s* en;
      struct zx_xaspcd1_XACMLAuthzDecisionQuery_s* enn;
      for (enn = 0, e = x->xaspcd1_XACMLAuthzDecisionQuery; e; e = (struct zx_xaspcd1_XACMLAuthzDecisionQuery_s*)e->gg.g.n) {
	  en = zx_DEEP_CLONE_xaspcd1_XACMLAuthzDecisionQuery(c, e, dup_strs);
	  if (!enn)
	      x->xaspcd1_XACMLAuthzDecisionQuery = en;
	  else
	      enn->gg.g.n = &en->gg.g;
	  enn = en;
      }
  }
  {
      struct zx_xaspcd1_XACMLPolicyQuery_s* e;
      struct zx_xaspcd1_XACMLPolicyQuery_s* en;
      struct zx_xaspcd1_XACMLPolicyQuery_s* enn;
      for (enn = 0, e = x->xaspcd1_XACMLPolicyQuery; e; e = (struct zx_xaspcd1_XACMLPolicyQuery_s*)e->gg.g.n) {
	  en = zx_DEEP_CLONE_xaspcd1_XACMLPolicyQuery(c, e, dup_strs);
	  if (!enn)
	      x->xaspcd1_XACMLPolicyQuery = en;
	  else
	      enn->gg.g.n = &en->gg.g;
	  enn = en;
      }
  }

  return x;
}

/* FUNC(zx_WALK_SO_root) */

/* Depth first traversal of the tree in either schema order or the wire order. */
 
int zx_WALK_SO_root(struct zx_ctx* c, struct zx_root_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
{
  int ret = callback(&x->gg.g, ctx);
  if (ret)
    return ret;
  
  /* *** deal with xmlns specifications in exc c14n way */


  
  ret = zx_walk_so_unknown_attributes(c, &x->gg, ctx, callback); 
  if (ret)
    return ret;

  {
      struct zx_sa_Assertion_s* e;
      for (e = x->Assertion; e; e = (struct zx_sa_Assertion_s*)e->gg.g.n) {
	  ret = zx_WALK_SO_sa_Assertion(c, e, ctx, callback);
	  if (ret)
	      return ret;
      }
  }
  {
      struct zx_sa_NameID_s* e;
      for (e = x->NameID; e; e = (struct zx_sa_NameID_s*)e->gg.g.n) {
	  ret = zx_WALK_SO_sa_NameID(c, e, ctx, callback);
	  if (ret)
	      return ret;
      }
  }
  ret = zx_walk_so_simple_elems(c, x->NewID, ctx, callback);
  if (ret)
    return ret;
  {
      struct zx_sp_AuthnRequest_s* e;
      for (e = x->AuthnRequest; e; e = (struct zx_sp_AuthnRequest_s*)e->gg.g.n) {
	  ret = zx_WALK_SO_sp_AuthnRequest(c, e, ctx, callback);
	  if (ret)
	      return ret;
      }
  }
  {
      struct zx_sp_Response_s* e;
      for (e = x->Response; e; e = (struct zx_sp_Response_s*)e->gg.g.n) {
	  ret = zx_WALK_SO_sp_Response(c, e, ctx, callback);
	  if (ret)
	      return ret;
      }
  }
  {
      struct zx_sp_LogoutRequest_s* e;
      for (e = x->LogoutRequest; e; e = (struct zx_sp_LogoutRequest_s*)e->gg.g.n) {
	  ret = zx_WALK_SO_sp_LogoutRequest(c, e, ctx, callback);
	  if (ret)
	      return ret;
      }
  }
  {
      struct zx_sp_LogoutResponse_s* e;
      for (e = x->LogoutResponse; e; e = (struct zx_sp_LogoutResponse_s*)e->gg.g.n) {
	  ret = zx_WALK_SO_sp_LogoutResponse(c, e, ctx, callback);
	  if (ret)
	      return ret;
      }
  }
  {
      struct zx_sp_ManageNameIDRequest_s* e;
      for (e = x->ManageNameIDRequest; e; e = (struct zx_sp_ManageNameIDRequest_s*)e->gg.g.n) {
	  ret = zx_WALK_SO_sp_ManageNameIDRequest(c, e, ctx, callback);
	  if (ret)
	      return ret;
      }
  }
  {
      struct zx_sp_ManageNameIDResponse_s* e;
      for (e = x->ManageNameIDResponse; e; e = (struct zx_sp_ManageNameIDResponse_s*)e->gg.g.n) {
	  ret = zx_WALK_SO_sp_ManageNameIDResponse(c, e, ctx, callback);
	  if (ret)
	      return ret;
      }
  }
  {
      struct zx_e_Envelope_s* e;
      for (e = x->Envelope; e; e = (struct zx_e_Envelope_s*)e->gg.g.n) {
	  ret = zx_WALK_SO_e_Envelope(c, e, ctx, callback);
	  if (ret)
	      return ret;
      }
  }
  {
      struct zx_e_Header_s* e;
      for (e = x->Header; e; e = (struct zx_e_Header_s*)e->gg.g.n) {
	  ret = zx_WALK_SO_e_Header(c, e, ctx, callback);
	  if (ret)
	      return ret;
      }
  }
  {
      struct zx_e_Body_s* e;
      for (e = x->Body; e; e = (struct zx_e_Body_s*)e->gg.g.n) {
	  ret = zx_WALK_SO_e_Body(c, e, ctx, callback);
	  if (ret)
	      return ret;
      }
  }
  {
      struct zx_md_EntityDescriptor_s* e;
      for (e = x->EntityDescriptor; e; e = (struct zx_md_EntityDescriptor_s*)e->gg.g.n) {
	  ret = zx_WALK_SO_md_EntityDescriptor(c, e, ctx, callback);
	  if (ret)
	      return ret;
      }
  }
  {
      struct zx_md_EntitiesDescriptor_s* e;
      for (e = x->EntitiesDescriptor; e; e = (struct zx_md_EntitiesDescriptor_s*)e->gg.g.n) {
	  ret = zx_WALK_SO_md_EntitiesDescriptor(c, e, ctx, callback);
	  if (ret)
	      return ret;
      }
  }
  {
      struct zx_sa11_Assertion_s* e;
      for (e = x->sa11_Assertion; e; e = (struct zx_sa11_Assertion_s*)e->gg.g.n) {
	  ret = zx_WALK_SO_sa11_Assertion(c, e, ctx, callback);
	  if (ret)
	      return ret;
      }
  }
  {
      struct zx_sp11_Request_s* e;
      for (e = x->Request; e; e = (struct zx_sp11_Request_s*)e->gg.g.n) {
	  ret = zx_WALK_SO_sp11_Request(c, e, ctx, callback);
	  if (ret)
	      return ret;
      }
  }
  {
      struct zx_sp11_Response_s* e;
      for (e = x->sp11_Response; e; e = (struct zx_sp11_Response_s*)e->gg.g.n) {
	  ret = zx_WALK_SO_sp11_Response(c, e, ctx, callback);
	  if (ret)
	      return ret;
      }
  }
  {
      struct zx_ff12_Assertion_s* e;
      for (e = x->ff12_Assertion; e; e = (struct zx_ff12_Assertion_s*)e->gg.g.n) {
	  ret = zx_WALK_SO_ff12_Assertion(c, e, ctx, callback);
	  if (ret)
	      return ret;
      }
  }
  {
      struct zx_ff12_AuthnRequest_s* e;
      for (e = x->ff12_AuthnRequest; e; e = (struct zx_ff12_AuthnRequest_s*)e->gg.g.n) {
	  ret = zx_WALK_SO_ff12_AuthnRequest(c, e, ctx, callback);
	  if (ret)
	      return ret;
      }
  }
  {
      struct zx_ff12_AuthnResponse_s* e;
      for (e = x->AuthnResponse; e; e = (struct zx_ff12_AuthnResponse_s*)e->gg.g.n) {
	  ret = zx_WALK_SO_ff12_AuthnResponse(c, e, ctx, callback);
	  if (ret)
	      return ret;
      }
  }
  {
      struct zx_ff12_AuthnRequestEnvelope_s* e;
      for (e = x->AuthnRequestEnvelope; e; e = (struct zx_ff12_AuthnRequestEnvelope_s*)e->gg.g.n) {
	  ret = zx_WALK_SO_ff12_AuthnRequestEnvelope(c, e, ctx, callback);
	  if (ret)
	      return ret;
      }
  }
  {
      struct zx_ff12_AuthnResponseEnvelope_s* e;
      for (e = x->AuthnResponseEnvelope; e; e = (struct zx_ff12_AuthnResponseEnvelope_s*)e->gg.g.n) {
	  ret = zx_WALK_SO_ff12_AuthnResponseEnvelope(c, e, ctx, callback);
	  if (ret)
	      return ret;
      }
  }
  {
      struct zx_ff12_RegisterNameIdentifierRequest_s* e;
      for (e = x->RegisterNameIdentifierRequest; e; e = (struct zx_ff12_RegisterNameIdentifierRequest_s*)e->gg.g.n) {
	  ret = zx_WALK_SO_ff12_RegisterNameIdentifierRequest(c, e, ctx, callback);
	  if (ret)
	      return ret;
      }
  }
  {
      struct zx_ff12_RegisterNameIdentifierResponse_s* e;
      for (e = x->RegisterNameIdentifierResponse; e; e = (struct zx_ff12_RegisterNameIdentifierResponse_s*)e->gg.g.n) {
	  ret = zx_WALK_SO_ff12_RegisterNameIdentifierResponse(c, e, ctx, callback);
	  if (ret)
	      return ret;
      }
  }
  {
      struct zx_ff12_FederationTerminationNotification_s* e;
      for (e = x->FederationTerminationNotification; e; e = (struct zx_ff12_FederationTerminationNotification_s*)e->gg.g.n) {
	  ret = zx_WALK_SO_ff12_FederationTerminationNotification(c, e, ctx, callback);
	  if (ret)
	      return ret;
      }
  }
  {
      struct zx_ff12_LogoutRequest_s* e;
      for (e = x->ff12_LogoutRequest; e; e = (struct zx_ff12_LogoutRequest_s*)e->gg.g.n) {
	  ret = zx_WALK_SO_ff12_LogoutRequest(c, e, ctx, callback);
	  if (ret)
	      return ret;
      }
  }
  {
      struct zx_ff12_LogoutResponse_s* e;
      for (e = x->ff12_LogoutResponse; e; e = (struct zx_ff12_LogoutResponse_s*)e->gg.g.n) {
	  ret = zx_WALK_SO_ff12_LogoutResponse(c, e, ctx, callback);
	  if (ret)
	      return ret;
      }
  }
  {
      struct zx_ff12_NameIdentifierMappingRequest_s* e;
      for (e = x->NameIdentifierMappingRequest; e; e = (struct zx_ff12_NameIdentifierMappingRequest_s*)e->gg.g.n) {
	  ret = zx_WALK_SO_ff12_NameIdentifierMappingRequest(c, e, ctx, callback);
	  if (ret)
	      return ret;
      }
  }
  {
      struct zx_ff12_NameIdentifierMappingResponse_s* e;
      for (e = x->NameIdentifierMappingResponse; e; e = (struct zx_ff12_NameIdentifierMappingResponse_s*)e->gg.g.n) {
	  ret = zx_WALK_SO_ff12_NameIdentifierMappingResponse(c, e, ctx, callback);
	  if (ret)
	      return ret;
      }
  }
  {
      struct zx_m20_EntityDescriptor_s* e;
      for (e = x->m20_EntityDescriptor; e; e = (struct zx_m20_EntityDescriptor_s*)e->gg.g.n) {
	  ret = zx_WALK_SO_m20_EntityDescriptor(c, e, ctx, callback);
	  if (ret)
	      return ret;
      }
  }
  {
      struct zx_m20_EntitiesDescriptor_s* e;
      for (e = x->m20_EntitiesDescriptor; e; e = (struct zx_m20_EntitiesDescriptor_s*)e->gg.g.n) {
	  ret = zx_WALK_SO_m20_EntitiesDescriptor(c, e, ctx, callback);
	  if (ret)
	      return ret;
      }
  }
  {
      struct zx_a_EndpointReference_s* e;
      for (e = x->EndpointReference; e; e = (struct zx_a_EndpointReference_s*)e->gg.g.n) {
	  ret = zx_WALK_SO_a_EndpointReference(c, e, ctx, callback);
	  if (ret)
	      return ret;
      }
  }
  {
      struct zx_hrxml_Candidate_s* e;
      for (e = x->Candidate; e; e = (struct zx_hrxml_Candidate_s*)e->gg.g.n) {
	  ret = zx_WALK_SO_hrxml_Candidate(c, e, ctx, callback);
	  if (ret)
	      return ret;
      }
  }
  {
      struct zx_xasp_XACMLAuthzDecisionQuery_s* e;
      for (e = x->XACMLAuthzDecisionQuery; e; e = (struct zx_xasp_XACMLAuthzDecisionQuery_s*)e->gg.g.n) {
	  ret = zx_WALK_SO_xasp_XACMLAuthzDecisionQuery(c, e, ctx, callback);
	  if (ret)
	      return ret;
      }
  }
  {
      struct zx_xasp_XACMLPolicyQuery_s* e;
      for (e = x->XACMLPolicyQuery; e; e = (struct zx_xasp_XACMLPolicyQuery_s*)e->gg.g.n) {
	  ret = zx_WALK_SO_xasp_XACMLPolicyQuery(c, e, ctx, callback);
	  if (ret)
	      return ret;
      }
  }
  {
      struct zx_xaspcd1_XACMLAuthzDecisionQuery_s* e;
      for (e = x->xaspcd1_XACMLAuthzDecisionQuery; e; e = (struct zx_xaspcd1_XACMLAuthzDecisionQuery_s*)e->gg.g.n) {
	  ret = zx_WALK_SO_xaspcd1_XACMLAuthzDecisionQuery(c, e, ctx, callback);
	  if (ret)
	      return ret;
      }
  }
  {
      struct zx_xaspcd1_XACMLPolicyQuery_s* e;
      for (e = x->xaspcd1_XACMLPolicyQuery; e; e = (struct zx_xaspcd1_XACMLPolicyQuery_s*)e->gg.g.n) {
	  ret = zx_WALK_SO_xaspcd1_XACMLPolicyQuery(c, e, ctx, callback);
	  if (ret)
	      return ret;
      }
  }

  
  return zx_walk_so_unknown_elems_and_content(c, &x->gg, ctx, callback);
}

/* FUNC(zx_WALK_WO_root) */

int zx_WALK_WO_root(struct zx_ctx* c, struct zx_root_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
{
  ERR("*** walk_wo not implemented %d", 0);
  return 0;
}

#endif




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

/* FUNC(zx_FREE_simple_elem) */

/* Depth first traversal of data structure to free it and its subelements. Simple
 * strings are handled as a special case according to the free_strs flag. This
 * is useful if the strings point to underlying data from the wire that was
 * allocated differently. */

/* Called by: */
void zx_FREE_simple_elem(struct zx_ctx* c, struct zx_elem_s* x, int free_strs)
{
  /* *** deal with xmlns specifications in exc c14n way */




  zx_free_elem_common(c, x, free_strs); 
}

/* FUNC(zx_NEW_simple_elem) */

/* Trivial allocator/constructor for the datatype. */

/* Called by: */
struct zx_elem_s* zx_NEW_simple_elem(struct zx_ctx* c, int toke)
{
  struct zx_elem_s* x = ZX_ZALLOC(c, struct zx_elem_s);
  x->g.tok = toke;
  return x;
}

#ifdef ZX_ENA_AUX

/* FUNC(zx_DUP_STRS_simple_elem) */

/* Depth first traversal of data structure to copy its simple strings
 * to memory allocated from the memory allocator. The decoder will
 * use the underlying wireprotocol PDU buffer for strings, i.e.
 * strings are not copied - they point to the real data. If the
 * datastructure needs to outlast the protocol data or needs a different
 * memory allocation strategy, you need to call this function.  */

/* Called by: */
void zx_DUP_STRS_simple_elem(struct zx_ctx* c, struct zx_elem_s* x)
{
  zx_dup_strs_common(c, x);
  /* *** deal with xmlns specifications in exc c14n way */



}

/* FUNC(zx_DEEP_CLONE_simple_elem) */

/* Depth first traversal of data structure to clone it and its sublements.
 * The simple strings are handled as a special case according to dup_strs flag. */

/* Called by: */
struct zx_elem_s* zx_DEEP_CLONE_simple_elem(struct zx_ctx* c, struct zx_elem_s* x, int dup_strs)
{
  x = (struct zx_elem_s*)zx_clone_elem_common(c, x, sizeof(struct zx_elem_s), dup_strs);
  /* *** deal with xmlns specifications in exc c14n way */



  return x;
}

/* FUNC(zx_WALK_SO_simple_elem) */

/* Depth first traversal of the tree in either schema order or the wire order. */
 
int zx_WALK_SO_simple_elem(struct zx_ctx* c, struct zx_elem_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
{
  int ret = callback(&x->g, ctx);
  if (ret)
    return ret;
  
  /* *** deal with xmlns specifications in exc c14n way */


  
  ret = zx_walk_so_unknown_attributes(c, x, ctx, callback); 
  if (ret)
    return ret;


  
  return zx_walk_so_unknown_elems_and_content(c, x, ctx, callback);
}

/* FUNC(zx_WALK_WO_simple_elem) */

int zx_WALK_WO_simple_elem(struct zx_ctx* c, struct zx_elem_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
{
  ERR("*** walk_wo not implemented %d", 0);
  return 0;
}

#endif


/* EOF -- c/zx-aux.c */
