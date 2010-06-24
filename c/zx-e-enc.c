/* c/zx-e-enc.c - WARNING: This file was automatically generated. DO NOT EDIT!
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
#include "c/zx-e-data.h"
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

#define EL_NAME   e_Body
#define EL_STRUCT zx_e_Body_s
#define EL_NS     e
#define EL_TAG    Body

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

/* FUNC(zx_LEN_SO_e_Body) */

/* Compute length of an element (and its subelements). The XML attributes
 * and elements are processed in schema order. */

/* Called by: */
int zx_LEN_SO_e_Body(struct zx_ctx* c, struct zx_e_Body_s* x )
{
  struct zx_ns_s* pop_seen = 0;
  struct zx_elem_s* se MAYBE_UNUSED;
#if 1 /* NORMALMODE */
  /* *** in simple_elem case should output ns prefix from ns node. */
  int len = sizeof("<e:Body")-1 + 1 + sizeof("</e:Body>")-1;
  if (c->inc_ns_len)
    len += zx_len_inc_ns(c, &pop_seen);
  len += zx_len_xmlns_if_not_seen(c, zx_ns_tab+zx_xmlns_ix_e, &pop_seen);

  len += zx_attr_so_len(x->id, sizeof("id")-1);

#else
  /* root node has no begin tag */
  int len = 0;
#endif
  
  {
      struct zx_sp_ArtifactResolve_s* e;
      for (e = x->ArtifactResolve; e; e = (struct zx_sp_ArtifactResolve_s*)e->gg.g.n)
	  len += zx_LEN_SO_sp_ArtifactResolve(c, e);
  }
  {
      struct zx_sp_ArtifactResponse_s* e;
      for (e = x->ArtifactResponse; e; e = (struct zx_sp_ArtifactResponse_s*)e->gg.g.n)
	  len += zx_LEN_SO_sp_ArtifactResponse(c, e);
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
      struct zx_sp_NameIDMappingRequest_s* e;
      for (e = x->NameIDMappingRequest; e; e = (struct zx_sp_NameIDMappingRequest_s*)e->gg.g.n)
	  len += zx_LEN_SO_sp_NameIDMappingRequest(c, e);
  }
  {
      struct zx_sp_NameIDMappingResponse_s* e;
      for (e = x->NameIDMappingResponse; e; e = (struct zx_sp_NameIDMappingResponse_s*)e->gg.g.n)
	  len += zx_LEN_SO_sp_NameIDMappingResponse(c, e);
  }
  {
      struct zx_sp_AttributeQuery_s* e;
      for (e = x->AttributeQuery; e; e = (struct zx_sp_AttributeQuery_s*)e->gg.g.n)
	  len += zx_LEN_SO_sp_AttributeQuery(c, e);
  }
  {
      struct zx_sp_AuthnQuery_s* e;
      for (e = x->AuthnQuery; e; e = (struct zx_sp_AuthnQuery_s*)e->gg.g.n)
	  len += zx_LEN_SO_sp_AuthnQuery(c, e);
  }
  {
      struct zx_sp_AuthzDecisionQuery_s* e;
      for (e = x->AuthzDecisionQuery; e; e = (struct zx_sp_AuthzDecisionQuery_s*)e->gg.g.n)
	  len += zx_LEN_SO_sp_AuthzDecisionQuery(c, e);
  }
  {
      struct zx_sp_AssertionIDRequest_s* e;
      for (e = x->AssertionIDRequest; e; e = (struct zx_sp_AssertionIDRequest_s*)e->gg.g.n)
	  len += zx_LEN_SO_sp_AssertionIDRequest(c, e);
  }
  {
      struct zx_sp_Response_s* e;
      for (e = x->Response; e; e = (struct zx_sp_Response_s*)e->gg.g.n)
	  len += zx_LEN_SO_sp_Response(c, e);
  }
  {
      struct zx_sp_AuthnRequest_s* e;
      for (e = x->AuthnRequest; e; e = (struct zx_sp_AuthnRequest_s*)e->gg.g.n)
	  len += zx_LEN_SO_sp_AuthnRequest(c, e);
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
  {
      struct zx_xac_Request_s* e;
      for (e = x->xac_Request; e; e = (struct zx_xac_Request_s*)e->gg.g.n)
	  len += zx_LEN_SO_xac_Request(c, e);
  }
  {
      struct zx_xac_Response_s* e;
      for (e = x->xac_Response; e; e = (struct zx_xac_Response_s*)e->gg.g.n)
	  len += zx_LEN_SO_xac_Response(c, e);
  }
  {
      struct zx_di_Query_s* e;
      for (e = x->Query; e; e = (struct zx_di_Query_s*)e->gg.g.n)
	  len += zx_LEN_SO_di_Query(c, e);
  }
  {
      struct zx_di_QueryResponse_s* e;
      for (e = x->QueryResponse; e; e = (struct zx_di_QueryResponse_s*)e->gg.g.n)
	  len += zx_LEN_SO_di_QueryResponse(c, e);
  }
  {
      struct zx_di12_Query_s* e;
      for (e = x->di12_Query; e; e = (struct zx_di12_Query_s*)e->gg.g.n)
	  len += zx_LEN_SO_di12_Query(c, e);
  }
  {
      struct zx_di12_QueryResponse_s* e;
      for (e = x->di12_QueryResponse; e; e = (struct zx_di12_QueryResponse_s*)e->gg.g.n)
	  len += zx_LEN_SO_di12_QueryResponse(c, e);
  }
  {
      struct zx_di12_Modify_s* e;
      for (e = x->Modify; e; e = (struct zx_di12_Modify_s*)e->gg.g.n)
	  len += zx_LEN_SO_di12_Modify(c, e);
  }
  {
      struct zx_di12_ModifyResponse_s* e;
      for (e = x->ModifyResponse; e; e = (struct zx_di12_ModifyResponse_s*)e->gg.g.n)
	  len += zx_LEN_SO_di12_ModifyResponse(c, e);
  }
  {
      struct zx_e_Fault_s* e;
      for (e = x->Fault; e; e = (struct zx_e_Fault_s*)e->gg.g.n)
	  len += zx_LEN_SO_e_Fault(c, e);
  }
  {
      struct zx_di_SvcMDAssociationAdd_s* e;
      for (e = x->SvcMDAssociationAdd; e; e = (struct zx_di_SvcMDAssociationAdd_s*)e->gg.g.n)
	  len += zx_LEN_SO_di_SvcMDAssociationAdd(c, e);
  }
  {
      struct zx_di_SvcMDAssociationAddResponse_s* e;
      for (e = x->SvcMDAssociationAddResponse; e; e = (struct zx_di_SvcMDAssociationAddResponse_s*)e->gg.g.n)
	  len += zx_LEN_SO_di_SvcMDAssociationAddResponse(c, e);
  }
  {
      struct zx_di_SvcMDAssociationDelete_s* e;
      for (e = x->SvcMDAssociationDelete; e; e = (struct zx_di_SvcMDAssociationDelete_s*)e->gg.g.n)
	  len += zx_LEN_SO_di_SvcMDAssociationDelete(c, e);
  }
  {
      struct zx_di_SvcMDAssociationDeleteResponse_s* e;
      for (e = x->SvcMDAssociationDeleteResponse; e; e = (struct zx_di_SvcMDAssociationDeleteResponse_s*)e->gg.g.n)
	  len += zx_LEN_SO_di_SvcMDAssociationDeleteResponse(c, e);
  }
  {
      struct zx_di_SvcMDAssociationQuery_s* e;
      for (e = x->SvcMDAssociationQuery; e; e = (struct zx_di_SvcMDAssociationQuery_s*)e->gg.g.n)
	  len += zx_LEN_SO_di_SvcMDAssociationQuery(c, e);
  }
  {
      struct zx_di_SvcMDAssociationQueryResponse_s* e;
      for (e = x->SvcMDAssociationQueryResponse; e; e = (struct zx_di_SvcMDAssociationQueryResponse_s*)e->gg.g.n)
	  len += zx_LEN_SO_di_SvcMDAssociationQueryResponse(c, e);
  }
  {
      struct zx_di_SvcMDRegister_s* e;
      for (e = x->SvcMDRegister; e; e = (struct zx_di_SvcMDRegister_s*)e->gg.g.n)
	  len += zx_LEN_SO_di_SvcMDRegister(c, e);
  }
  {
      struct zx_di_SvcMDRegisterResponse_s* e;
      for (e = x->SvcMDRegisterResponse; e; e = (struct zx_di_SvcMDRegisterResponse_s*)e->gg.g.n)
	  len += zx_LEN_SO_di_SvcMDRegisterResponse(c, e);
  }
  {
      struct zx_di_SvcMDDelete_s* e;
      for (e = x->SvcMDDelete; e; e = (struct zx_di_SvcMDDelete_s*)e->gg.g.n)
	  len += zx_LEN_SO_di_SvcMDDelete(c, e);
  }
  {
      struct zx_di_SvcMDDeleteResponse_s* e;
      for (e = x->SvcMDDeleteResponse; e; e = (struct zx_di_SvcMDDeleteResponse_s*)e->gg.g.n)
	  len += zx_LEN_SO_di_SvcMDDeleteResponse(c, e);
  }
  {
      struct zx_di_SvcMDQuery_s* e;
      for (e = x->SvcMDQuery; e; e = (struct zx_di_SvcMDQuery_s*)e->gg.g.n)
	  len += zx_LEN_SO_di_SvcMDQuery(c, e);
  }
  {
      struct zx_di_SvcMDQueryResponse_s* e;
      for (e = x->SvcMDQueryResponse; e; e = (struct zx_di_SvcMDQueryResponse_s*)e->gg.g.n)
	  len += zx_LEN_SO_di_SvcMDQueryResponse(c, e);
  }
  {
      struct zx_di_SvcMDReplace_s* e;
      for (e = x->SvcMDReplace; e; e = (struct zx_di_SvcMDReplace_s*)e->gg.g.n)
	  len += zx_LEN_SO_di_SvcMDReplace(c, e);
  }
  {
      struct zx_di_SvcMDReplaceResponse_s* e;
      for (e = x->SvcMDReplaceResponse; e; e = (struct zx_di_SvcMDReplaceResponse_s*)e->gg.g.n)
	  len += zx_LEN_SO_di_SvcMDReplaceResponse(c, e);
  }
  {
      struct zx_dap_Create_s* e;
      for (e = x->Create; e; e = (struct zx_dap_Create_s*)e->gg.g.n)
	  len += zx_LEN_SO_dap_Create(c, e);
  }
  {
      struct zx_dap_CreateResponse_s* e;
      for (e = x->CreateResponse; e; e = (struct zx_dap_CreateResponse_s*)e->gg.g.n)
	  len += zx_LEN_SO_dap_CreateResponse(c, e);
  }
  {
      struct zx_dap_Query_s* e;
      for (e = x->dap_Query; e; e = (struct zx_dap_Query_s*)e->gg.g.n)
	  len += zx_LEN_SO_dap_Query(c, e);
  }
  {
      struct zx_dap_QueryResponse_s* e;
      for (e = x->dap_QueryResponse; e; e = (struct zx_dap_QueryResponse_s*)e->gg.g.n)
	  len += zx_LEN_SO_dap_QueryResponse(c, e);
  }
  {
      struct zx_dap_Modify_s* e;
      for (e = x->dap_Modify; e; e = (struct zx_dap_Modify_s*)e->gg.g.n)
	  len += zx_LEN_SO_dap_Modify(c, e);
  }
  {
      struct zx_dap_ModifyResponse_s* e;
      for (e = x->dap_ModifyResponse; e; e = (struct zx_dap_ModifyResponse_s*)e->gg.g.n)
	  len += zx_LEN_SO_dap_ModifyResponse(c, e);
  }
  {
      struct zx_dap_Delete_s* e;
      for (e = x->Delete; e; e = (struct zx_dap_Delete_s*)e->gg.g.n)
	  len += zx_LEN_SO_dap_Delete(c, e);
  }
  {
      struct zx_dap_DeleteResponse_s* e;
      for (e = x->DeleteResponse; e; e = (struct zx_dap_DeleteResponse_s*)e->gg.g.n)
	  len += zx_LEN_SO_dap_DeleteResponse(c, e);
  }
  {
      struct zx_dap_Notify_s* e;
      for (e = x->Notify; e; e = (struct zx_dap_Notify_s*)e->gg.g.n)
	  len += zx_LEN_SO_dap_Notify(c, e);
  }
  {
      struct zx_dap_NotifyResponse_s* e;
      for (e = x->NotifyResponse; e; e = (struct zx_dap_NotifyResponse_s*)e->gg.g.n)
	  len += zx_LEN_SO_dap_NotifyResponse(c, e);
  }
  {
      struct zx_ps_AddEntityRequest_s* e;
      for (e = x->AddEntityRequest; e; e = (struct zx_ps_AddEntityRequest_s*)e->gg.g.n)
	  len += zx_LEN_SO_ps_AddEntityRequest(c, e);
  }
  {
      struct zx_ps_AddEntityResponse_s* e;
      for (e = x->AddEntityResponse; e; e = (struct zx_ps_AddEntityResponse_s*)e->gg.g.n)
	  len += zx_LEN_SO_ps_AddEntityResponse(c, e);
  }
  {
      struct zx_ps_AddKnownEntityRequest_s* e;
      for (e = x->AddKnownEntityRequest; e; e = (struct zx_ps_AddKnownEntityRequest_s*)e->gg.g.n)
	  len += zx_LEN_SO_ps_AddKnownEntityRequest(c, e);
  }
  {
      struct zx_ps_AddKnownEntityResponse_s* e;
      for (e = x->AddKnownEntityResponse; e; e = (struct zx_ps_AddKnownEntityResponse_s*)e->gg.g.n)
	  len += zx_LEN_SO_ps_AddKnownEntityResponse(c, e);
  }
  {
      struct zx_ps_AddCollectionRequest_s* e;
      for (e = x->AddCollectionRequest; e; e = (struct zx_ps_AddCollectionRequest_s*)e->gg.g.n)
	  len += zx_LEN_SO_ps_AddCollectionRequest(c, e);
  }
  {
      struct zx_ps_AddCollectionResponse_s* e;
      for (e = x->AddCollectionResponse; e; e = (struct zx_ps_AddCollectionResponse_s*)e->gg.g.n)
	  len += zx_LEN_SO_ps_AddCollectionResponse(c, e);
  }
  {
      struct zx_ps_AddToCollectionRequest_s* e;
      for (e = x->AddToCollectionRequest; e; e = (struct zx_ps_AddToCollectionRequest_s*)e->gg.g.n)
	  len += zx_LEN_SO_ps_AddToCollectionRequest(c, e);
  }
  {
      struct zx_ps_AddToCollectionResponse_s* e;
      for (e = x->AddToCollectionResponse; e; e = (struct zx_ps_AddToCollectionResponse_s*)e->gg.g.n)
	  len += zx_LEN_SO_ps_AddToCollectionResponse(c, e);
  }
  {
      struct zx_ps_RemoveEntityRequest_s* e;
      for (e = x->RemoveEntityRequest; e; e = (struct zx_ps_RemoveEntityRequest_s*)e->gg.g.n)
	  len += zx_LEN_SO_ps_RemoveEntityRequest(c, e);
  }
  {
      struct zx_ps_RemoveEntityResponse_s* e;
      for (e = x->RemoveEntityResponse; e; e = (struct zx_ps_RemoveEntityResponse_s*)e->gg.g.n)
	  len += zx_LEN_SO_ps_RemoveEntityResponse(c, e);
  }
  {
      struct zx_ps_RemoveCollectionRequest_s* e;
      for (e = x->RemoveCollectionRequest; e; e = (struct zx_ps_RemoveCollectionRequest_s*)e->gg.g.n)
	  len += zx_LEN_SO_ps_RemoveCollectionRequest(c, e);
  }
  {
      struct zx_ps_RemoveCollectionResponse_s* e;
      for (e = x->RemoveCollectionResponse; e; e = (struct zx_ps_RemoveCollectionResponse_s*)e->gg.g.n)
	  len += zx_LEN_SO_ps_RemoveCollectionResponse(c, e);
  }
  {
      struct zx_ps_RemoveFromCollectionRequest_s* e;
      for (e = x->RemoveFromCollectionRequest; e; e = (struct zx_ps_RemoveFromCollectionRequest_s*)e->gg.g.n)
	  len += zx_LEN_SO_ps_RemoveFromCollectionRequest(c, e);
  }
  {
      struct zx_ps_RemoveFromCollectionResponse_s* e;
      for (e = x->RemoveFromCollectionResponse; e; e = (struct zx_ps_RemoveFromCollectionResponse_s*)e->gg.g.n)
	  len += zx_LEN_SO_ps_RemoveFromCollectionResponse(c, e);
  }
  {
      struct zx_ps_ListMembersRequest_s* e;
      for (e = x->ListMembersRequest; e; e = (struct zx_ps_ListMembersRequest_s*)e->gg.g.n)
	  len += zx_LEN_SO_ps_ListMembersRequest(c, e);
  }
  {
      struct zx_ps_ListMembersResponse_s* e;
      for (e = x->ListMembersResponse; e; e = (struct zx_ps_ListMembersResponse_s*)e->gg.g.n)
	  len += zx_LEN_SO_ps_ListMembersResponse(c, e);
  }
  {
      struct zx_ps_QueryObjectsRequest_s* e;
      for (e = x->QueryObjectsRequest; e; e = (struct zx_ps_QueryObjectsRequest_s*)e->gg.g.n)
	  len += zx_LEN_SO_ps_QueryObjectsRequest(c, e);
  }
  {
      struct zx_ps_QueryObjectsResponse_s* e;
      for (e = x->QueryObjectsResponse; e; e = (struct zx_ps_QueryObjectsResponse_s*)e->gg.g.n)
	  len += zx_LEN_SO_ps_QueryObjectsResponse(c, e);
  }
  {
      struct zx_ps_GetObjectInfoRequest_s* e;
      for (e = x->GetObjectInfoRequest; e; e = (struct zx_ps_GetObjectInfoRequest_s*)e->gg.g.n)
	  len += zx_LEN_SO_ps_GetObjectInfoRequest(c, e);
  }
  {
      struct zx_ps_GetObjectInfoResponse_s* e;
      for (e = x->GetObjectInfoResponse; e; e = (struct zx_ps_GetObjectInfoResponse_s*)e->gg.g.n)
	  len += zx_LEN_SO_ps_GetObjectInfoResponse(c, e);
  }
  {
      struct zx_ps_SetObjectInfoRequest_s* e;
      for (e = x->SetObjectInfoRequest; e; e = (struct zx_ps_SetObjectInfoRequest_s*)e->gg.g.n)
	  len += zx_LEN_SO_ps_SetObjectInfoRequest(c, e);
  }
  {
      struct zx_ps_SetObjectInfoResponse_s* e;
      for (e = x->SetObjectInfoResponse; e; e = (struct zx_ps_SetObjectInfoResponse_s*)e->gg.g.n)
	  len += zx_LEN_SO_ps_SetObjectInfoResponse(c, e);
  }
  {
      struct zx_ps_TestMembershipRequest_s* e;
      for (e = x->TestMembershipRequest; e; e = (struct zx_ps_TestMembershipRequest_s*)e->gg.g.n)
	  len += zx_LEN_SO_ps_TestMembershipRequest(c, e);
  }
  {
      struct zx_ps_TestMembershipResponse_s* e;
      for (e = x->TestMembershipResponse; e; e = (struct zx_ps_TestMembershipResponse_s*)e->gg.g.n)
	  len += zx_LEN_SO_ps_TestMembershipResponse(c, e);
  }
  {
      struct zx_ps_ResolveIdentifierRequest_s* e;
      for (e = x->ResolveIdentifierRequest; e; e = (struct zx_ps_ResolveIdentifierRequest_s*)e->gg.g.n)
	  len += zx_LEN_SO_ps_ResolveIdentifierRequest(c, e);
  }
  {
      struct zx_ps_ResolveIdentifierResponse_s* e;
      for (e = x->ResolveIdentifierResponse; e; e = (struct zx_ps_ResolveIdentifierResponse_s*)e->gg.g.n)
	  len += zx_LEN_SO_ps_ResolveIdentifierResponse(c, e);
  }
  {
      struct zx_ps_Notify_s* e;
      for (e = x->ps_Notify; e; e = (struct zx_ps_Notify_s*)e->gg.g.n)
	  len += zx_LEN_SO_ps_Notify(c, e);
  }
  {
      struct zx_ps_NotifyResponse_s* e;
      for (e = x->ps_NotifyResponse; e; e = (struct zx_ps_NotifyResponse_s*)e->gg.g.n)
	  len += zx_LEN_SO_ps_NotifyResponse(c, e);
  }
  {
      struct zx_im_IdentityMappingRequest_s* e;
      for (e = x->IdentityMappingRequest; e; e = (struct zx_im_IdentityMappingRequest_s*)e->gg.g.n)
	  len += zx_LEN_SO_im_IdentityMappingRequest(c, e);
  }
  {
      struct zx_im_IdentityMappingResponse_s* e;
      for (e = x->IdentityMappingResponse; e; e = (struct zx_im_IdentityMappingResponse_s*)e->gg.g.n)
	  len += zx_LEN_SO_im_IdentityMappingResponse(c, e);
  }
  {
      struct zx_as_SASLRequest_s* e;
      for (e = x->SASLRequest; e; e = (struct zx_as_SASLRequest_s*)e->gg.g.n)
	  len += zx_LEN_SO_as_SASLRequest(c, e);
  }
  {
      struct zx_as_SASLResponse_s* e;
      for (e = x->SASLResponse; e; e = (struct zx_as_SASLResponse_s*)e->gg.g.n)
	  len += zx_LEN_SO_as_SASLResponse(c, e);
  }
  {
      struct zx_mm7_SubmitReq_s* e;
      for (e = x->SubmitReq; e; e = (struct zx_mm7_SubmitReq_s*)e->gg.g.n)
	  len += zx_LEN_SO_mm7_SubmitReq(c, e);
  }
  {
      struct zx_mm7_SubmitRsp_s* e;
      for (e = x->SubmitRsp; e; e = (struct zx_mm7_SubmitRsp_s*)e->gg.g.n)
	  len += zx_LEN_SO_mm7_SubmitRsp(c, e);
  }
  {
      struct zx_mm7_DeliverReq_s* e;
      for (e = x->DeliverReq; e; e = (struct zx_mm7_DeliverReq_s*)e->gg.g.n)
	  len += zx_LEN_SO_mm7_DeliverReq(c, e);
  }
  {
      struct zx_mm7_DeliverRsp_s* e;
      for (e = x->DeliverRsp; e; e = (struct zx_mm7_DeliverRsp_s*)e->gg.g.n)
	  len += zx_LEN_SO_mm7_DeliverRsp(c, e);
  }
  {
      struct zx_mm7_CancelReq_s* e;
      for (e = x->CancelReq; e; e = (struct zx_mm7_CancelReq_s*)e->gg.g.n)
	  len += zx_LEN_SO_mm7_CancelReq(c, e);
  }
  {
      struct zx_mm7_CancelRsp_s* e;
      for (e = x->CancelRsp; e; e = (struct zx_mm7_CancelRsp_s*)e->gg.g.n)
	  len += zx_LEN_SO_mm7_CancelRsp(c, e);
  }
  {
      struct zx_mm7_ReplaceReq_s* e;
      for (e = x->ReplaceReq; e; e = (struct zx_mm7_ReplaceReq_s*)e->gg.g.n)
	  len += zx_LEN_SO_mm7_ReplaceReq(c, e);
  }
  {
      struct zx_mm7_ReplaceRsp_s* e;
      for (e = x->ReplaceRsp; e; e = (struct zx_mm7_ReplaceRsp_s*)e->gg.g.n)
	  len += zx_LEN_SO_mm7_ReplaceRsp(c, e);
  }
  {
      struct zx_mm7_extendedCancelReq_s* e;
      for (e = x->extendedCancelReq; e; e = (struct zx_mm7_extendedCancelReq_s*)e->gg.g.n)
	  len += zx_LEN_SO_mm7_extendedCancelReq(c, e);
  }
  {
      struct zx_mm7_extendedCancelRsp_s* e;
      for (e = x->extendedCancelRsp; e; e = (struct zx_mm7_extendedCancelRsp_s*)e->gg.g.n)
	  len += zx_LEN_SO_mm7_extendedCancelRsp(c, e);
  }
  {
      struct zx_mm7_extendedReplaceReq_s* e;
      for (e = x->extendedReplaceReq; e; e = (struct zx_mm7_extendedReplaceReq_s*)e->gg.g.n)
	  len += zx_LEN_SO_mm7_extendedReplaceReq(c, e);
  }
  {
      struct zx_mm7_extendedReplaceRsp_s* e;
      for (e = x->extendedReplaceRsp; e; e = (struct zx_mm7_extendedReplaceRsp_s*)e->gg.g.n)
	  len += zx_LEN_SO_mm7_extendedReplaceRsp(c, e);
  }
  {
      struct zx_mm7_DeliveryReportReq_s* e;
      for (e = x->DeliveryReportReq; e; e = (struct zx_mm7_DeliveryReportReq_s*)e->gg.g.n)
	  len += zx_LEN_SO_mm7_DeliveryReportReq(c, e);
  }
  {
      struct zx_mm7_DeliveryReportRsp_s* e;
      for (e = x->DeliveryReportRsp; e; e = (struct zx_mm7_DeliveryReportRsp_s*)e->gg.g.n)
	  len += zx_LEN_SO_mm7_DeliveryReportRsp(c, e);
  }
  {
      struct zx_mm7_ReadReplyReq_s* e;
      for (e = x->ReadReplyReq; e; e = (struct zx_mm7_ReadReplyReq_s*)e->gg.g.n)
	  len += zx_LEN_SO_mm7_ReadReplyReq(c, e);
  }
  {
      struct zx_mm7_ReadReplyRsp_s* e;
      for (e = x->ReadReplyRsp; e; e = (struct zx_mm7_ReadReplyRsp_s*)e->gg.g.n)
	  len += zx_LEN_SO_mm7_ReadReplyRsp(c, e);
  }
  {
      struct zx_mm7_RSErrorRsp_s* e;
      for (e = x->RSErrorRsp; e; e = (struct zx_mm7_RSErrorRsp_s*)e->gg.g.n)
	  len += zx_LEN_SO_mm7_RSErrorRsp(c, e);
  }
  {
      struct zx_mm7_VASPErrorRsp_s* e;
      for (e = x->VASPErrorRsp; e; e = (struct zx_mm7_VASPErrorRsp_s*)e->gg.g.n)
	  len += zx_LEN_SO_mm7_VASPErrorRsp(c, e);
  }
  {
      struct zx_mm7_QueryStatusReq_s* e;
      for (e = x->QueryStatusReq; e; e = (struct zx_mm7_QueryStatusReq_s*)e->gg.g.n)
	  len += zx_LEN_SO_mm7_QueryStatusReq(c, e);
  }
  {
      struct zx_mm7_QueryStatusRsp_s* e;
      for (e = x->QueryStatusRsp; e; e = (struct zx_mm7_QueryStatusRsp_s*)e->gg.g.n)
	  len += zx_LEN_SO_mm7_QueryStatusRsp(c, e);
  }
  {
      struct zx_cb_Query_s* e;
      for (e = x->cb_Query; e; e = (struct zx_cb_Query_s*)e->gg.g.n)
	  len += zx_LEN_SO_cb_Query(c, e);
  }
  {
      struct zx_cb_QueryResponse_s* e;
      for (e = x->cb_QueryResponse; e; e = (struct zx_cb_QueryResponse_s*)e->gg.g.n)
	  len += zx_LEN_SO_cb_QueryResponse(c, e);
  }
  {
      struct zx_cb_Create_s* e;
      for (e = x->cb_Create; e; e = (struct zx_cb_Create_s*)e->gg.g.n)
	  len += zx_LEN_SO_cb_Create(c, e);
  }
  {
      struct zx_cb_CreateResponse_s* e;
      for (e = x->cb_CreateResponse; e; e = (struct zx_cb_CreateResponse_s*)e->gg.g.n)
	  len += zx_LEN_SO_cb_CreateResponse(c, e);
  }
  {
      struct zx_cb_Delete_s* e;
      for (e = x->cb_Delete; e; e = (struct zx_cb_Delete_s*)e->gg.g.n)
	  len += zx_LEN_SO_cb_Delete(c, e);
  }
  {
      struct zx_cb_DeleteResponse_s* e;
      for (e = x->cb_DeleteResponse; e; e = (struct zx_cb_DeleteResponse_s*)e->gg.g.n)
	  len += zx_LEN_SO_cb_DeleteResponse(c, e);
  }
  {
      struct zx_cb_Modify_s* e;
      for (e = x->cb_Modify; e; e = (struct zx_cb_Modify_s*)e->gg.g.n)
	  len += zx_LEN_SO_cb_Modify(c, e);
  }
  {
      struct zx_cb_ModifyResponse_s* e;
      for (e = x->cb_ModifyResponse; e; e = (struct zx_cb_ModifyResponse_s*)e->gg.g.n)
	  len += zx_LEN_SO_cb_ModifyResponse(c, e);
  }
  {
      struct zx_cb_Notify_s* e;
      for (e = x->cb_Notify; e; e = (struct zx_cb_Notify_s*)e->gg.g.n)
	  len += zx_LEN_SO_cb_Notify(c, e);
  }
  {
      struct zx_cb_NotifyResponse_s* e;
      for (e = x->cb_NotifyResponse; e; e = (struct zx_cb_NotifyResponse_s*)e->gg.g.n)
	  len += zx_LEN_SO_cb_NotifyResponse(c, e);
  }
  {
      struct zx_cb_ReportUsage_s* e;
      for (e = x->ReportUsage; e; e = (struct zx_cb_ReportUsage_s*)e->gg.g.n)
	  len += zx_LEN_SO_cb_ReportUsage(c, e);
  }
  {
      struct zx_cb_ReportUsageResponse_s* e;
      for (e = x->ReportUsageResponse; e; e = (struct zx_cb_ReportUsageResponse_s*)e->gg.g.n)
	  len += zx_LEN_SO_cb_ReportUsageResponse(c, e);
  }
  {
      struct zx_gl_Query_s* e;
      for (e = x->gl_Query; e; e = (struct zx_gl_Query_s*)e->gg.g.n)
	  len += zx_LEN_SO_gl_Query(c, e);
  }
  {
      struct zx_gl_QueryResponse_s* e;
      for (e = x->gl_QueryResponse; e; e = (struct zx_gl_QueryResponse_s*)e->gg.g.n)
	  len += zx_LEN_SO_gl_QueryResponse(c, e);
  }
  {
      struct zx_gl_Create_s* e;
      for (e = x->gl_Create; e; e = (struct zx_gl_Create_s*)e->gg.g.n)
	  len += zx_LEN_SO_gl_Create(c, e);
  }
  {
      struct zx_gl_CreateResponse_s* e;
      for (e = x->gl_CreateResponse; e; e = (struct zx_gl_CreateResponse_s*)e->gg.g.n)
	  len += zx_LEN_SO_gl_CreateResponse(c, e);
  }
  {
      struct zx_gl_Delete_s* e;
      for (e = x->gl_Delete; e; e = (struct zx_gl_Delete_s*)e->gg.g.n)
	  len += zx_LEN_SO_gl_Delete(c, e);
  }
  {
      struct zx_gl_DeleteResponse_s* e;
      for (e = x->gl_DeleteResponse; e; e = (struct zx_gl_DeleteResponse_s*)e->gg.g.n)
	  len += zx_LEN_SO_gl_DeleteResponse(c, e);
  }
  {
      struct zx_gl_Modify_s* e;
      for (e = x->gl_Modify; e; e = (struct zx_gl_Modify_s*)e->gg.g.n)
	  len += zx_LEN_SO_gl_Modify(c, e);
  }
  {
      struct zx_gl_ModifyResponse_s* e;
      for (e = x->gl_ModifyResponse; e; e = (struct zx_gl_ModifyResponse_s*)e->gg.g.n)
	  len += zx_LEN_SO_gl_ModifyResponse(c, e);
  }
  {
      struct zx_gl_Notify_s* e;
      for (e = x->gl_Notify; e; e = (struct zx_gl_Notify_s*)e->gg.g.n)
	  len += zx_LEN_SO_gl_Notify(c, e);
  }
  {
      struct zx_gl_NotifyResponse_s* e;
      for (e = x->gl_NotifyResponse; e; e = (struct zx_gl_NotifyResponse_s*)e->gg.g.n)
	  len += zx_LEN_SO_gl_NotifyResponse(c, e);
  }
  {
      struct zx_demomed_StoreObjectRequest_s* e;
      for (e = x->StoreObjectRequest; e; e = (struct zx_demomed_StoreObjectRequest_s*)e->gg.g.n)
	  len += zx_LEN_SO_demomed_StoreObjectRequest(c, e);
  }
  {
      struct zx_demomed_StoreObjectResponse_s* e;
      for (e = x->StoreObjectResponse; e; e = (struct zx_demomed_StoreObjectResponse_s*)e->gg.g.n)
	  len += zx_LEN_SO_demomed_StoreObjectResponse(c, e);
  }
  {
      struct zx_demomed_GetObjectListRequest_s* e;
      for (e = x->GetObjectListRequest; e; e = (struct zx_demomed_GetObjectListRequest_s*)e->gg.g.n)
	  len += zx_LEN_SO_demomed_GetObjectListRequest(c, e);
  }
  {
      struct zx_demomed_GetObjectListResponse_s* e;
      for (e = x->GetObjectListResponse; e; e = (struct zx_demomed_GetObjectListResponse_s*)e->gg.g.n)
	  len += zx_LEN_SO_demomed_GetObjectListResponse(c, e);
  }
  {
      struct zx_demomed_GetObjectRequest_s* e;
      for (e = x->GetObjectRequest; e; e = (struct zx_demomed_GetObjectRequest_s*)e->gg.g.n)
	  len += zx_LEN_SO_demomed_GetObjectRequest(c, e);
  }
  {
      struct zx_demomed_GetObjectResponse_s* e;
      for (e = x->GetObjectResponse; e; e = (struct zx_demomed_GetObjectResponse_s*)e->gg.g.n)
	  len += zx_LEN_SO_demomed_GetObjectResponse(c, e);
  }
  {
      struct zx_demomed_DeleteObjectRequest_s* e;
      for (e = x->DeleteObjectRequest; e; e = (struct zx_demomed_DeleteObjectRequest_s*)e->gg.g.n)
	  len += zx_LEN_SO_demomed_DeleteObjectRequest(c, e);
  }
  {
      struct zx_demomed_DeleteObjectResponse_s* e;
      for (e = x->DeleteObjectResponse; e; e = (struct zx_demomed_DeleteObjectResponse_s*)e->gg.g.n)
	  len += zx_LEN_SO_demomed_DeleteObjectResponse(c, e);
  }
  {
      struct zx_pmm_Provision_s* e;
      for (e = x->Provision; e; e = (struct zx_pmm_Provision_s*)e->gg.g.n)
	  len += zx_LEN_SO_pmm_Provision(c, e);
  }
  {
      struct zx_pmm_ProvisionResponse_s* e;
      for (e = x->ProvisionResponse; e; e = (struct zx_pmm_ProvisionResponse_s*)e->gg.g.n)
	  len += zx_LEN_SO_pmm_ProvisionResponse(c, e);
  }
  {
      struct zx_pmm_PMActivate_s* e;
      for (e = x->PMActivate; e; e = (struct zx_pmm_PMActivate_s*)e->gg.g.n)
	  len += zx_LEN_SO_pmm_PMActivate(c, e);
  }
  {
      struct zx_pmm_PMActivateResponse_s* e;
      for (e = x->PMActivateResponse; e; e = (struct zx_pmm_PMActivateResponse_s*)e->gg.g.n)
	  len += zx_LEN_SO_pmm_PMActivateResponse(c, e);
  }
  {
      struct zx_pmm_PMDeactivate_s* e;
      for (e = x->PMDeactivate; e; e = (struct zx_pmm_PMDeactivate_s*)e->gg.g.n)
	  len += zx_LEN_SO_pmm_PMDeactivate(c, e);
  }
  {
      struct zx_pmm_PMDeactivateResponse_s* e;
      for (e = x->PMDeactivateResponse; e; e = (struct zx_pmm_PMDeactivateResponse_s*)e->gg.g.n)
	  len += zx_LEN_SO_pmm_PMDeactivateResponse(c, e);
  }
  {
      struct zx_pmm_PMDelete_s* e;
      for (e = x->PMDelete; e; e = (struct zx_pmm_PMDelete_s*)e->gg.g.n)
	  len += zx_LEN_SO_pmm_PMDelete(c, e);
  }
  {
      struct zx_pmm_PMDeleteResponse_s* e;
      for (e = x->PMDeleteResponse; e; e = (struct zx_pmm_PMDeleteResponse_s*)e->gg.g.n)
	  len += zx_LEN_SO_pmm_PMDeleteResponse(c, e);
  }
  {
      struct zx_pmm_PMUpdate_s* e;
      for (e = x->PMUpdate; e; e = (struct zx_pmm_PMUpdate_s*)e->gg.g.n)
	  len += zx_LEN_SO_pmm_PMUpdate(c, e);
  }
  {
      struct zx_pmm_PMUpdateResponse_s* e;
      for (e = x->PMUpdateResponse; e; e = (struct zx_pmm_PMUpdateResponse_s*)e->gg.g.n)
	  len += zx_LEN_SO_pmm_PMUpdateResponse(c, e);
  }
  {
      struct zx_pmm_PMGetStatus_s* e;
      for (e = x->PMGetStatus; e; e = (struct zx_pmm_PMGetStatus_s*)e->gg.g.n)
	  len += zx_LEN_SO_pmm_PMGetStatus(c, e);
  }
  {
      struct zx_pmm_PMGetStatusResponse_s* e;
      for (e = x->PMGetStatusResponse; e; e = (struct zx_pmm_PMGetStatusResponse_s*)e->gg.g.n)
	  len += zx_LEN_SO_pmm_PMGetStatusResponse(c, e);
  }
  {
      struct zx_pmm_PMSetStatus_s* e;
      for (e = x->PMSetStatus; e; e = (struct zx_pmm_PMSetStatus_s*)e->gg.g.n)
	  len += zx_LEN_SO_pmm_PMSetStatus(c, e);
  }
  {
      struct zx_pmm_PMSetStatusResponse_s* e;
      for (e = x->PMSetStatusResponse; e; e = (struct zx_pmm_PMSetStatusResponse_s*)e->gg.g.n)
	  len += zx_LEN_SO_pmm_PMSetStatusResponse(c, e);
  }
  {
      struct zx_prov_PMERegister_s* e;
      for (e = x->PMERegister; e; e = (struct zx_prov_PMERegister_s*)e->gg.g.n)
	  len += zx_LEN_SO_prov_PMERegister(c, e);
  }
  {
      struct zx_prov_PMERegisterResponse_s* e;
      for (e = x->PMERegisterResponse; e; e = (struct zx_prov_PMERegisterResponse_s*)e->gg.g.n)
	  len += zx_LEN_SO_prov_PMERegisterResponse(c, e);
  }
  {
      struct zx_prov_PMEUpload_s* e;
      for (e = x->PMEUpload; e; e = (struct zx_prov_PMEUpload_s*)e->gg.g.n)
	  len += zx_LEN_SO_prov_PMEUpload(c, e);
  }
  {
      struct zx_prov_PMEUploadResponse_s* e;
      for (e = x->PMEUploadResponse; e; e = (struct zx_prov_PMEUploadResponse_s*)e->gg.g.n)
	  len += zx_LEN_SO_prov_PMEUploadResponse(c, e);
  }
  {
      struct zx_prov_PMEDownload_s* e;
      for (e = x->PMEDownload; e; e = (struct zx_prov_PMEDownload_s*)e->gg.g.n)
	  len += zx_LEN_SO_prov_PMEDownload(c, e);
  }
  {
      struct zx_prov_PMEDownloadResponse_s* e;
      for (e = x->PMEDownloadResponse; e; e = (struct zx_prov_PMEDownloadResponse_s*)e->gg.g.n)
	  len += zx_LEN_SO_prov_PMEDownloadResponse(c, e);
  }
  {
      struct zx_prov_PMEEnable_s* e;
      for (e = x->PMEEnable; e; e = (struct zx_prov_PMEEnable_s*)e->gg.g.n)
	  len += zx_LEN_SO_prov_PMEEnable(c, e);
  }
  {
      struct zx_prov_PMEEnableResponse_s* e;
      for (e = x->PMEEnableResponse; e; e = (struct zx_prov_PMEEnableResponse_s*)e->gg.g.n)
	  len += zx_LEN_SO_prov_PMEEnableResponse(c, e);
  }
  {
      struct zx_prov_PMEDisable_s* e;
      for (e = x->PMEDisable; e; e = (struct zx_prov_PMEDisable_s*)e->gg.g.n)
	  len += zx_LEN_SO_prov_PMEDisable(c, e);
  }
  {
      struct zx_prov_PMEDisableResponse_s* e;
      for (e = x->PMEDisableResponse; e; e = (struct zx_prov_PMEDisableResponse_s*)e->gg.g.n)
	  len += zx_LEN_SO_prov_PMEDisableResponse(c, e);
  }
  {
      struct zx_prov_PMEDelete_s* e;
      for (e = x->PMEDelete; e; e = (struct zx_prov_PMEDelete_s*)e->gg.g.n)
	  len += zx_LEN_SO_prov_PMEDelete(c, e);
  }
  {
      struct zx_prov_PMEDeleteResponse_s* e;
      for (e = x->PMEDeleteResponse; e; e = (struct zx_prov_PMEDeleteResponse_s*)e->gg.g.n)
	  len += zx_LEN_SO_prov_PMEDeleteResponse(c, e);
  }
  {
      struct zx_prov_PMEGetInfo_s* e;
      for (e = x->PMEGetInfo; e; e = (struct zx_prov_PMEGetInfo_s*)e->gg.g.n)
	  len += zx_LEN_SO_prov_PMEGetInfo(c, e);
  }
  {
      struct zx_prov_PMEGetInfoResponse_s* e;
      for (e = x->PMEGetInfoResponse; e; e = (struct zx_prov_PMEGetInfoResponse_s*)e->gg.g.n)
	  len += zx_LEN_SO_prov_PMEGetInfoResponse(c, e);
  }
  {
      struct zx_prov_PMGetStatus_s* e;
      for (e = x->prov_PMGetStatus; e; e = (struct zx_prov_PMGetStatus_s*)e->gg.g.n)
	  len += zx_LEN_SO_prov_PMGetStatus(c, e);
  }
  {
      struct zx_prov_PMGetStatusResponse_s* e;
      for (e = x->prov_PMGetStatusResponse; e; e = (struct zx_prov_PMGetStatusResponse_s*)e->gg.g.n)
	  len += zx_LEN_SO_prov_PMGetStatusResponse(c, e);
  }
  {
      struct zx_prov_PMSetStatus_s* e;
      for (e = x->prov_PMSetStatus; e; e = (struct zx_prov_PMSetStatus_s*)e->gg.g.n)
	  len += zx_LEN_SO_prov_PMSetStatus(c, e);
  }
  {
      struct zx_prov_PMSetStatusResponse_s* e;
      for (e = x->prov_PMSetStatusResponse; e; e = (struct zx_prov_PMSetStatusResponse_s*)e->gg.g.n)
	  len += zx_LEN_SO_prov_PMSetStatusResponse(c, e);
  }
  {
      struct zx_prov_PMGetDescriptor_s* e;
      for (e = x->PMGetDescriptor; e; e = (struct zx_prov_PMGetDescriptor_s*)e->gg.g.n)
	  len += zx_LEN_SO_prov_PMGetDescriptor(c, e);
  }
  {
      struct zx_prov_PMGetDescriptorResponse_s* e;
      for (e = x->PMGetDescriptorResponse; e; e = (struct zx_prov_PMGetDescriptorResponse_s*)e->gg.g.n)
	  len += zx_LEN_SO_prov_PMGetDescriptorResponse(c, e);
  }
  {
      struct zx_prov_PMActivate_s* e;
      for (e = x->prov_PMActivate; e; e = (struct zx_prov_PMActivate_s*)e->gg.g.n)
	  len += zx_LEN_SO_prov_PMActivate(c, e);
  }
  {
      struct zx_prov_PMActivateResponse_s* e;
      for (e = x->prov_PMActivateResponse; e; e = (struct zx_prov_PMActivateResponse_s*)e->gg.g.n)
	  len += zx_LEN_SO_prov_PMActivateResponse(c, e);
  }
  {
      struct zx_prov_PMDeactivate_s* e;
      for (e = x->prov_PMDeactivate; e; e = (struct zx_prov_PMDeactivate_s*)e->gg.g.n)
	  len += zx_LEN_SO_prov_PMDeactivate(c, e);
  }
  {
      struct zx_prov_PMDeactivateResponse_s* e;
      for (e = x->prov_PMDeactivateResponse; e; e = (struct zx_prov_PMDeactivateResponse_s*)e->gg.g.n)
	  len += zx_LEN_SO_prov_PMDeactivateResponse(c, e);
  }
  {
      struct zx_prov_PMRegisterDescriptor_s* e;
      for (e = x->PMRegisterDescriptor; e; e = (struct zx_prov_PMRegisterDescriptor_s*)e->gg.g.n)
	  len += zx_LEN_SO_prov_PMRegisterDescriptor(c, e);
  }
  {
      struct zx_prov_PMRegisterDescriptorResponse_s* e;
      for (e = x->PMRegisterDescriptorResponse; e; e = (struct zx_prov_PMRegisterDescriptorResponse_s*)e->gg.g.n)
	  len += zx_LEN_SO_prov_PMRegisterDescriptorResponse(c, e);
  }
  {
      struct zx_prov_PMUpdate_s* e;
      for (e = x->prov_PMUpdate; e; e = (struct zx_prov_PMUpdate_s*)e->gg.g.n)
	  len += zx_LEN_SO_prov_PMUpdate(c, e);
  }
  {
      struct zx_prov_PMUpdateResponse_s* e;
      for (e = x->prov_PMUpdateResponse; e; e = (struct zx_prov_PMUpdateResponse_s*)e->gg.g.n)
	  len += zx_LEN_SO_prov_PMUpdateResponse(c, e);
  }
  {
      struct zx_prov_PMDelete_s* e;
      for (e = x->prov_PMDelete; e; e = (struct zx_prov_PMDelete_s*)e->gg.g.n)
	  len += zx_LEN_SO_prov_PMDelete(c, e);
  }
  {
      struct zx_prov_PMDeleteResponse_s* e;
      for (e = x->prov_PMDeleteResponse; e; e = (struct zx_prov_PMDeleteResponse_s*)e->gg.g.n)
	  len += zx_LEN_SO_prov_PMDeleteResponse(c, e);
  }
  {
      struct zx_prov_Poll_s* e;
      for (e = x->Poll; e; e = (struct zx_prov_Poll_s*)e->gg.g.n)
	  len += zx_LEN_SO_prov_Poll(c, e);
  }
  {
      struct zx_prov_PollResponse_s* e;
      for (e = x->PollResponse; e; e = (struct zx_prov_PollResponse_s*)e->gg.g.n)
	  len += zx_LEN_SO_prov_PollResponse(c, e);
  }
  {
      struct zx_prov_UpdateEPR_s* e;
      for (e = x->UpdateEPR; e; e = (struct zx_prov_UpdateEPR_s*)e->gg.g.n)
	  len += zx_LEN_SO_prov_UpdateEPR(c, e);
  }
  {
      struct zx_prov_UpdateEPRResponse_s* e;
      for (e = x->UpdateEPRResponse; e; e = (struct zx_prov_UpdateEPRResponse_s*)e->gg.g.n)
	  len += zx_LEN_SO_prov_UpdateEPRResponse(c, e);
  }
  {
      struct zx_idp_GetAssertion_s* e;
      for (e = x->GetAssertion; e; e = (struct zx_idp_GetAssertion_s*)e->gg.g.n)
	  len += zx_LEN_SO_idp_GetAssertion(c, e);
  }
  {
      struct zx_idp_GetAssertionResponse_s* e;
      for (e = x->GetAssertionResponse; e; e = (struct zx_idp_GetAssertionResponse_s*)e->gg.g.n)
	  len += zx_LEN_SO_idp_GetAssertionResponse(c, e);
  }
  {
      struct zx_idp_GetProviderInfo_s* e;
      for (e = x->GetProviderInfo; e; e = (struct zx_idp_GetProviderInfo_s*)e->gg.g.n)
	  len += zx_LEN_SO_idp_GetProviderInfo(c, e);
  }
  {
      struct zx_idp_GetProviderInfoResponse_s* e;
      for (e = x->GetProviderInfoResponse; e; e = (struct zx_idp_GetProviderInfoResponse_s*)e->gg.g.n)
	  len += zx_LEN_SO_idp_GetProviderInfoResponse(c, e);
  }
  {
      struct zx_idp_CreatedStatus_s* e;
      for (e = x->CreatedStatus; e; e = (struct zx_idp_CreatedStatus_s*)e->gg.g.n)
	  len += zx_LEN_SO_idp_CreatedStatus(c, e);
  }
  {
      struct zx_idp_CreatedStatusResponse_s* e;
      for (e = x->CreatedStatusResponse; e; e = (struct zx_idp_CreatedStatusResponse_s*)e->gg.g.n)
	  len += zx_LEN_SO_idp_CreatedStatusResponse(c, e);
  }
  {
      struct zx_shps_Delete_s* e;
      for (e = x->shps_Delete; e; e = (struct zx_shps_Delete_s*)e->gg.g.n)
	  len += zx_LEN_SO_shps_Delete(c, e);
  }
  {
      struct zx_shps_DeleteResponse_s* e;
      for (e = x->shps_DeleteResponse; e; e = (struct zx_shps_DeleteResponse_s*)e->gg.g.n)
	  len += zx_LEN_SO_shps_DeleteResponse(c, e);
  }
  {
      struct zx_shps_GetStatus_s* e;
      for (e = x->GetStatus; e; e = (struct zx_shps_GetStatus_s*)e->gg.g.n)
	  len += zx_LEN_SO_shps_GetStatus(c, e);
  }
  {
      struct zx_shps_GetStatusResponse_s* e;
      for (e = x->GetStatusResponse; e; e = (struct zx_shps_GetStatusResponse_s*)e->gg.g.n)
	  len += zx_LEN_SO_shps_GetStatusResponse(c, e);
  }
  {
      struct zx_shps_Query_s* e;
      for (e = x->shps_Query; e; e = (struct zx_shps_Query_s*)e->gg.g.n)
	  len += zx_LEN_SO_shps_Query(c, e);
  }
  {
      struct zx_shps_QueryResponse_s* e;
      for (e = x->shps_QueryResponse; e; e = (struct zx_shps_QueryResponse_s*)e->gg.g.n)
	  len += zx_LEN_SO_shps_QueryResponse(c, e);
  }
  for (se = x->Invoke; se; se = (struct zx_elem_s*)se->g.n)
    len += zx_LEN_SO_simple_elem(c,se, sizeof("shps:Invoke")-1, zx_ns_tab+zx_xmlns_ix_shps);
  {
      struct zx_shps_InvokeResponse_s* e;
      for (e = x->InvokeResponse; e; e = (struct zx_shps_InvokeResponse_s*)e->gg.g.n)
	  len += zx_LEN_SO_shps_InvokeResponse(c, e);
  }
  {
      struct zx_shps_QueryRegistered_s* e;
      for (e = x->QueryRegistered; e; e = (struct zx_shps_QueryRegistered_s*)e->gg.g.n)
	  len += zx_LEN_SO_shps_QueryRegistered(c, e);
  }
  {
      struct zx_shps_QueryRegisteredResponse_s* e;
      for (e = x->QueryRegisteredResponse; e; e = (struct zx_shps_QueryRegisteredResponse_s*)e->gg.g.n)
	  len += zx_LEN_SO_shps_QueryRegisteredResponse(c, e);
  }
  {
      struct zx_shps_Register_s* e;
      for (e = x->Register; e; e = (struct zx_shps_Register_s*)e->gg.g.n)
	  len += zx_LEN_SO_shps_Register(c, e);
  }
  {
      struct zx_shps_RegisterResponse_s* e;
      for (e = x->RegisterResponse; e; e = (struct zx_shps_RegisterResponse_s*)e->gg.g.n)
	  len += zx_LEN_SO_shps_RegisterResponse(c, e);
  }
  {
      struct zx_shps_SetStatus_s* e;
      for (e = x->SetStatus; e; e = (struct zx_shps_SetStatus_s*)e->gg.g.n)
	  len += zx_LEN_SO_shps_SetStatus(c, e);
  }
  {
      struct zx_shps_SetStatusResponse_s* e;
      for (e = x->SetStatusResponse; e; e = (struct zx_shps_SetStatusResponse_s*)e->gg.g.n)
	  len += zx_LEN_SO_shps_SetStatusResponse(c, e);
  }
  {
      struct zx_shps_Update_s* e;
      for (e = x->Update; e; e = (struct zx_shps_Update_s*)e->gg.g.n)
	  len += zx_LEN_SO_shps_Update(c, e);
  }
  {
      struct zx_shps_UpdateResponse_s* e;
      for (e = x->UpdateResponse; e; e = (struct zx_shps_UpdateResponse_s*)e->gg.g.n)
	  len += zx_LEN_SO_shps_UpdateResponse(c, e);
  }
  {
      struct zx_shps_Poll_s* e;
      for (e = x->shps_Poll; e; e = (struct zx_shps_Poll_s*)e->gg.g.n)
	  len += zx_LEN_SO_shps_Poll(c, e);
  }
  {
      struct zx_shps_PollResponse_s* e;
      for (e = x->shps_PollResponse; e; e = (struct zx_shps_PollResponse_s*)e->gg.g.n)
	  len += zx_LEN_SO_shps_PollResponse(c, e);
  }
  {
      struct zx_shps_ProxyInvoke_s* e;
      for (e = x->ProxyInvoke; e; e = (struct zx_shps_ProxyInvoke_s*)e->gg.g.n)
	  len += zx_LEN_SO_shps_ProxyInvoke(c, e);
  }
  {
      struct zx_shps_ProxyInvokeResponse_s* e;
      for (e = x->ProxyInvokeResponse; e; e = (struct zx_shps_ProxyInvokeResponse_s*)e->gg.g.n)
	  len += zx_LEN_SO_shps_ProxyInvokeResponse(c, e);
  }
  {
      struct zx_idhrxml_Create_s* e;
      for (e = x->idhrxml_Create; e; e = (struct zx_idhrxml_Create_s*)e->gg.g.n)
	  len += zx_LEN_SO_idhrxml_Create(c, e);
  }
  {
      struct zx_idhrxml_CreateResponse_s* e;
      for (e = x->idhrxml_CreateResponse; e; e = (struct zx_idhrxml_CreateResponse_s*)e->gg.g.n)
	  len += zx_LEN_SO_idhrxml_CreateResponse(c, e);
  }
  {
      struct zx_idhrxml_Query_s* e;
      for (e = x->idhrxml_Query; e; e = (struct zx_idhrxml_Query_s*)e->gg.g.n)
	  len += zx_LEN_SO_idhrxml_Query(c, e);
  }
  {
      struct zx_idhrxml_QueryResponse_s* e;
      for (e = x->idhrxml_QueryResponse; e; e = (struct zx_idhrxml_QueryResponse_s*)e->gg.g.n)
	  len += zx_LEN_SO_idhrxml_QueryResponse(c, e);
  }
  {
      struct zx_idhrxml_Modify_s* e;
      for (e = x->idhrxml_Modify; e; e = (struct zx_idhrxml_Modify_s*)e->gg.g.n)
	  len += zx_LEN_SO_idhrxml_Modify(c, e);
  }
  {
      struct zx_idhrxml_ModifyResponse_s* e;
      for (e = x->idhrxml_ModifyResponse; e; e = (struct zx_idhrxml_ModifyResponse_s*)e->gg.g.n)
	  len += zx_LEN_SO_idhrxml_ModifyResponse(c, e);
  }
  {
      struct zx_idhrxml_Delete_s* e;
      for (e = x->idhrxml_Delete; e; e = (struct zx_idhrxml_Delete_s*)e->gg.g.n)
	  len += zx_LEN_SO_idhrxml_Delete(c, e);
  }
  {
      struct zx_idhrxml_DeleteResponse_s* e;
      for (e = x->idhrxml_DeleteResponse; e; e = (struct zx_idhrxml_DeleteResponse_s*)e->gg.g.n)
	  len += zx_LEN_SO_idhrxml_DeleteResponse(c, e);
  }
  {
      struct zx_idhrxml_Notify_s* e;
      for (e = x->idhrxml_Notify; e; e = (struct zx_idhrxml_Notify_s*)e->gg.g.n)
	  len += zx_LEN_SO_idhrxml_Notify(c, e);
  }
  {
      struct zx_idhrxml_NotifyResponse_s* e;
      for (e = x->idhrxml_NotifyResponse; e; e = (struct zx_idhrxml_NotifyResponse_s*)e->gg.g.n)
	  len += zx_LEN_SO_idhrxml_NotifyResponse(c, e);
  }


  len += zx_len_so_common(c, &x->gg);
  zx_pop_seen(pop_seen);
  ENC_LEN_DEBUG(x, "e:Body", len);
  return len;
}

/* FUNC(zx_LEN_WO_e_Body) */

/* Compute length of an element (and its subelements). The XML attributes
 * and elements are processed in wire order and no assumptions
 * are made about namespace prefixes. */

/* Called by: */
int zx_LEN_WO_e_Body(struct zx_ctx* c, struct zx_e_Body_s* x )
{
  struct zx_ns_s* pop_seen = 0;
  struct zx_elem_s* se MAYBE_UNUSED;
#if 1 /* NORMALMODE */
  int len = 1 + sizeof("Body")-1 + 1 + 2 + sizeof("Body")-1 + 1;
  
  if (x->gg.g.ns && x->gg.g.ns->prefix_len)
    len += (x->gg.g.ns->prefix_len + 1) * 2;
  if (c->inc_ns_len)
    len += zx_len_inc_ns(c, &pop_seen);
  len += zx_len_xmlns_if_not_seen(c, x->gg.g.ns, &pop_seen);

  len += zx_attr_wo_len(x->id, sizeof("id")-1);

#else
  /* root node has no begin tag */
  int len = 0;
#endif
  
  {
      struct zx_sp_ArtifactResolve_s* e;
      for (e = x->ArtifactResolve; e; e = (struct zx_sp_ArtifactResolve_s*)e->gg.g.n)
	  len += zx_LEN_WO_sp_ArtifactResolve(c, e);
  }
  {
      struct zx_sp_ArtifactResponse_s* e;
      for (e = x->ArtifactResponse; e; e = (struct zx_sp_ArtifactResponse_s*)e->gg.g.n)
	  len += zx_LEN_WO_sp_ArtifactResponse(c, e);
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
      struct zx_sp_NameIDMappingRequest_s* e;
      for (e = x->NameIDMappingRequest; e; e = (struct zx_sp_NameIDMappingRequest_s*)e->gg.g.n)
	  len += zx_LEN_WO_sp_NameIDMappingRequest(c, e);
  }
  {
      struct zx_sp_NameIDMappingResponse_s* e;
      for (e = x->NameIDMappingResponse; e; e = (struct zx_sp_NameIDMappingResponse_s*)e->gg.g.n)
	  len += zx_LEN_WO_sp_NameIDMappingResponse(c, e);
  }
  {
      struct zx_sp_AttributeQuery_s* e;
      for (e = x->AttributeQuery; e; e = (struct zx_sp_AttributeQuery_s*)e->gg.g.n)
	  len += zx_LEN_WO_sp_AttributeQuery(c, e);
  }
  {
      struct zx_sp_AuthnQuery_s* e;
      for (e = x->AuthnQuery; e; e = (struct zx_sp_AuthnQuery_s*)e->gg.g.n)
	  len += zx_LEN_WO_sp_AuthnQuery(c, e);
  }
  {
      struct zx_sp_AuthzDecisionQuery_s* e;
      for (e = x->AuthzDecisionQuery; e; e = (struct zx_sp_AuthzDecisionQuery_s*)e->gg.g.n)
	  len += zx_LEN_WO_sp_AuthzDecisionQuery(c, e);
  }
  {
      struct zx_sp_AssertionIDRequest_s* e;
      for (e = x->AssertionIDRequest; e; e = (struct zx_sp_AssertionIDRequest_s*)e->gg.g.n)
	  len += zx_LEN_WO_sp_AssertionIDRequest(c, e);
  }
  {
      struct zx_sp_Response_s* e;
      for (e = x->Response; e; e = (struct zx_sp_Response_s*)e->gg.g.n)
	  len += zx_LEN_WO_sp_Response(c, e);
  }
  {
      struct zx_sp_AuthnRequest_s* e;
      for (e = x->AuthnRequest; e; e = (struct zx_sp_AuthnRequest_s*)e->gg.g.n)
	  len += zx_LEN_WO_sp_AuthnRequest(c, e);
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
  {
      struct zx_xac_Request_s* e;
      for (e = x->xac_Request; e; e = (struct zx_xac_Request_s*)e->gg.g.n)
	  len += zx_LEN_WO_xac_Request(c, e);
  }
  {
      struct zx_xac_Response_s* e;
      for (e = x->xac_Response; e; e = (struct zx_xac_Response_s*)e->gg.g.n)
	  len += zx_LEN_WO_xac_Response(c, e);
  }
  {
      struct zx_di_Query_s* e;
      for (e = x->Query; e; e = (struct zx_di_Query_s*)e->gg.g.n)
	  len += zx_LEN_WO_di_Query(c, e);
  }
  {
      struct zx_di_QueryResponse_s* e;
      for (e = x->QueryResponse; e; e = (struct zx_di_QueryResponse_s*)e->gg.g.n)
	  len += zx_LEN_WO_di_QueryResponse(c, e);
  }
  {
      struct zx_di12_Query_s* e;
      for (e = x->di12_Query; e; e = (struct zx_di12_Query_s*)e->gg.g.n)
	  len += zx_LEN_WO_di12_Query(c, e);
  }
  {
      struct zx_di12_QueryResponse_s* e;
      for (e = x->di12_QueryResponse; e; e = (struct zx_di12_QueryResponse_s*)e->gg.g.n)
	  len += zx_LEN_WO_di12_QueryResponse(c, e);
  }
  {
      struct zx_di12_Modify_s* e;
      for (e = x->Modify; e; e = (struct zx_di12_Modify_s*)e->gg.g.n)
	  len += zx_LEN_WO_di12_Modify(c, e);
  }
  {
      struct zx_di12_ModifyResponse_s* e;
      for (e = x->ModifyResponse; e; e = (struct zx_di12_ModifyResponse_s*)e->gg.g.n)
	  len += zx_LEN_WO_di12_ModifyResponse(c, e);
  }
  {
      struct zx_e_Fault_s* e;
      for (e = x->Fault; e; e = (struct zx_e_Fault_s*)e->gg.g.n)
	  len += zx_LEN_WO_e_Fault(c, e);
  }
  {
      struct zx_di_SvcMDAssociationAdd_s* e;
      for (e = x->SvcMDAssociationAdd; e; e = (struct zx_di_SvcMDAssociationAdd_s*)e->gg.g.n)
	  len += zx_LEN_WO_di_SvcMDAssociationAdd(c, e);
  }
  {
      struct zx_di_SvcMDAssociationAddResponse_s* e;
      for (e = x->SvcMDAssociationAddResponse; e; e = (struct zx_di_SvcMDAssociationAddResponse_s*)e->gg.g.n)
	  len += zx_LEN_WO_di_SvcMDAssociationAddResponse(c, e);
  }
  {
      struct zx_di_SvcMDAssociationDelete_s* e;
      for (e = x->SvcMDAssociationDelete; e; e = (struct zx_di_SvcMDAssociationDelete_s*)e->gg.g.n)
	  len += zx_LEN_WO_di_SvcMDAssociationDelete(c, e);
  }
  {
      struct zx_di_SvcMDAssociationDeleteResponse_s* e;
      for (e = x->SvcMDAssociationDeleteResponse; e; e = (struct zx_di_SvcMDAssociationDeleteResponse_s*)e->gg.g.n)
	  len += zx_LEN_WO_di_SvcMDAssociationDeleteResponse(c, e);
  }
  {
      struct zx_di_SvcMDAssociationQuery_s* e;
      for (e = x->SvcMDAssociationQuery; e; e = (struct zx_di_SvcMDAssociationQuery_s*)e->gg.g.n)
	  len += zx_LEN_WO_di_SvcMDAssociationQuery(c, e);
  }
  {
      struct zx_di_SvcMDAssociationQueryResponse_s* e;
      for (e = x->SvcMDAssociationQueryResponse; e; e = (struct zx_di_SvcMDAssociationQueryResponse_s*)e->gg.g.n)
	  len += zx_LEN_WO_di_SvcMDAssociationQueryResponse(c, e);
  }
  {
      struct zx_di_SvcMDRegister_s* e;
      for (e = x->SvcMDRegister; e; e = (struct zx_di_SvcMDRegister_s*)e->gg.g.n)
	  len += zx_LEN_WO_di_SvcMDRegister(c, e);
  }
  {
      struct zx_di_SvcMDRegisterResponse_s* e;
      for (e = x->SvcMDRegisterResponse; e; e = (struct zx_di_SvcMDRegisterResponse_s*)e->gg.g.n)
	  len += zx_LEN_WO_di_SvcMDRegisterResponse(c, e);
  }
  {
      struct zx_di_SvcMDDelete_s* e;
      for (e = x->SvcMDDelete; e; e = (struct zx_di_SvcMDDelete_s*)e->gg.g.n)
	  len += zx_LEN_WO_di_SvcMDDelete(c, e);
  }
  {
      struct zx_di_SvcMDDeleteResponse_s* e;
      for (e = x->SvcMDDeleteResponse; e; e = (struct zx_di_SvcMDDeleteResponse_s*)e->gg.g.n)
	  len += zx_LEN_WO_di_SvcMDDeleteResponse(c, e);
  }
  {
      struct zx_di_SvcMDQuery_s* e;
      for (e = x->SvcMDQuery; e; e = (struct zx_di_SvcMDQuery_s*)e->gg.g.n)
	  len += zx_LEN_WO_di_SvcMDQuery(c, e);
  }
  {
      struct zx_di_SvcMDQueryResponse_s* e;
      for (e = x->SvcMDQueryResponse; e; e = (struct zx_di_SvcMDQueryResponse_s*)e->gg.g.n)
	  len += zx_LEN_WO_di_SvcMDQueryResponse(c, e);
  }
  {
      struct zx_di_SvcMDReplace_s* e;
      for (e = x->SvcMDReplace; e; e = (struct zx_di_SvcMDReplace_s*)e->gg.g.n)
	  len += zx_LEN_WO_di_SvcMDReplace(c, e);
  }
  {
      struct zx_di_SvcMDReplaceResponse_s* e;
      for (e = x->SvcMDReplaceResponse; e; e = (struct zx_di_SvcMDReplaceResponse_s*)e->gg.g.n)
	  len += zx_LEN_WO_di_SvcMDReplaceResponse(c, e);
  }
  {
      struct zx_dap_Create_s* e;
      for (e = x->Create; e; e = (struct zx_dap_Create_s*)e->gg.g.n)
	  len += zx_LEN_WO_dap_Create(c, e);
  }
  {
      struct zx_dap_CreateResponse_s* e;
      for (e = x->CreateResponse; e; e = (struct zx_dap_CreateResponse_s*)e->gg.g.n)
	  len += zx_LEN_WO_dap_CreateResponse(c, e);
  }
  {
      struct zx_dap_Query_s* e;
      for (e = x->dap_Query; e; e = (struct zx_dap_Query_s*)e->gg.g.n)
	  len += zx_LEN_WO_dap_Query(c, e);
  }
  {
      struct zx_dap_QueryResponse_s* e;
      for (e = x->dap_QueryResponse; e; e = (struct zx_dap_QueryResponse_s*)e->gg.g.n)
	  len += zx_LEN_WO_dap_QueryResponse(c, e);
  }
  {
      struct zx_dap_Modify_s* e;
      for (e = x->dap_Modify; e; e = (struct zx_dap_Modify_s*)e->gg.g.n)
	  len += zx_LEN_WO_dap_Modify(c, e);
  }
  {
      struct zx_dap_ModifyResponse_s* e;
      for (e = x->dap_ModifyResponse; e; e = (struct zx_dap_ModifyResponse_s*)e->gg.g.n)
	  len += zx_LEN_WO_dap_ModifyResponse(c, e);
  }
  {
      struct zx_dap_Delete_s* e;
      for (e = x->Delete; e; e = (struct zx_dap_Delete_s*)e->gg.g.n)
	  len += zx_LEN_WO_dap_Delete(c, e);
  }
  {
      struct zx_dap_DeleteResponse_s* e;
      for (e = x->DeleteResponse; e; e = (struct zx_dap_DeleteResponse_s*)e->gg.g.n)
	  len += zx_LEN_WO_dap_DeleteResponse(c, e);
  }
  {
      struct zx_dap_Notify_s* e;
      for (e = x->Notify; e; e = (struct zx_dap_Notify_s*)e->gg.g.n)
	  len += zx_LEN_WO_dap_Notify(c, e);
  }
  {
      struct zx_dap_NotifyResponse_s* e;
      for (e = x->NotifyResponse; e; e = (struct zx_dap_NotifyResponse_s*)e->gg.g.n)
	  len += zx_LEN_WO_dap_NotifyResponse(c, e);
  }
  {
      struct zx_ps_AddEntityRequest_s* e;
      for (e = x->AddEntityRequest; e; e = (struct zx_ps_AddEntityRequest_s*)e->gg.g.n)
	  len += zx_LEN_WO_ps_AddEntityRequest(c, e);
  }
  {
      struct zx_ps_AddEntityResponse_s* e;
      for (e = x->AddEntityResponse; e; e = (struct zx_ps_AddEntityResponse_s*)e->gg.g.n)
	  len += zx_LEN_WO_ps_AddEntityResponse(c, e);
  }
  {
      struct zx_ps_AddKnownEntityRequest_s* e;
      for (e = x->AddKnownEntityRequest; e; e = (struct zx_ps_AddKnownEntityRequest_s*)e->gg.g.n)
	  len += zx_LEN_WO_ps_AddKnownEntityRequest(c, e);
  }
  {
      struct zx_ps_AddKnownEntityResponse_s* e;
      for (e = x->AddKnownEntityResponse; e; e = (struct zx_ps_AddKnownEntityResponse_s*)e->gg.g.n)
	  len += zx_LEN_WO_ps_AddKnownEntityResponse(c, e);
  }
  {
      struct zx_ps_AddCollectionRequest_s* e;
      for (e = x->AddCollectionRequest; e; e = (struct zx_ps_AddCollectionRequest_s*)e->gg.g.n)
	  len += zx_LEN_WO_ps_AddCollectionRequest(c, e);
  }
  {
      struct zx_ps_AddCollectionResponse_s* e;
      for (e = x->AddCollectionResponse; e; e = (struct zx_ps_AddCollectionResponse_s*)e->gg.g.n)
	  len += zx_LEN_WO_ps_AddCollectionResponse(c, e);
  }
  {
      struct zx_ps_AddToCollectionRequest_s* e;
      for (e = x->AddToCollectionRequest; e; e = (struct zx_ps_AddToCollectionRequest_s*)e->gg.g.n)
	  len += zx_LEN_WO_ps_AddToCollectionRequest(c, e);
  }
  {
      struct zx_ps_AddToCollectionResponse_s* e;
      for (e = x->AddToCollectionResponse; e; e = (struct zx_ps_AddToCollectionResponse_s*)e->gg.g.n)
	  len += zx_LEN_WO_ps_AddToCollectionResponse(c, e);
  }
  {
      struct zx_ps_RemoveEntityRequest_s* e;
      for (e = x->RemoveEntityRequest; e; e = (struct zx_ps_RemoveEntityRequest_s*)e->gg.g.n)
	  len += zx_LEN_WO_ps_RemoveEntityRequest(c, e);
  }
  {
      struct zx_ps_RemoveEntityResponse_s* e;
      for (e = x->RemoveEntityResponse; e; e = (struct zx_ps_RemoveEntityResponse_s*)e->gg.g.n)
	  len += zx_LEN_WO_ps_RemoveEntityResponse(c, e);
  }
  {
      struct zx_ps_RemoveCollectionRequest_s* e;
      for (e = x->RemoveCollectionRequest; e; e = (struct zx_ps_RemoveCollectionRequest_s*)e->gg.g.n)
	  len += zx_LEN_WO_ps_RemoveCollectionRequest(c, e);
  }
  {
      struct zx_ps_RemoveCollectionResponse_s* e;
      for (e = x->RemoveCollectionResponse; e; e = (struct zx_ps_RemoveCollectionResponse_s*)e->gg.g.n)
	  len += zx_LEN_WO_ps_RemoveCollectionResponse(c, e);
  }
  {
      struct zx_ps_RemoveFromCollectionRequest_s* e;
      for (e = x->RemoveFromCollectionRequest; e; e = (struct zx_ps_RemoveFromCollectionRequest_s*)e->gg.g.n)
	  len += zx_LEN_WO_ps_RemoveFromCollectionRequest(c, e);
  }
  {
      struct zx_ps_RemoveFromCollectionResponse_s* e;
      for (e = x->RemoveFromCollectionResponse; e; e = (struct zx_ps_RemoveFromCollectionResponse_s*)e->gg.g.n)
	  len += zx_LEN_WO_ps_RemoveFromCollectionResponse(c, e);
  }
  {
      struct zx_ps_ListMembersRequest_s* e;
      for (e = x->ListMembersRequest; e; e = (struct zx_ps_ListMembersRequest_s*)e->gg.g.n)
	  len += zx_LEN_WO_ps_ListMembersRequest(c, e);
  }
  {
      struct zx_ps_ListMembersResponse_s* e;
      for (e = x->ListMembersResponse; e; e = (struct zx_ps_ListMembersResponse_s*)e->gg.g.n)
	  len += zx_LEN_WO_ps_ListMembersResponse(c, e);
  }
  {
      struct zx_ps_QueryObjectsRequest_s* e;
      for (e = x->QueryObjectsRequest; e; e = (struct zx_ps_QueryObjectsRequest_s*)e->gg.g.n)
	  len += zx_LEN_WO_ps_QueryObjectsRequest(c, e);
  }
  {
      struct zx_ps_QueryObjectsResponse_s* e;
      for (e = x->QueryObjectsResponse; e; e = (struct zx_ps_QueryObjectsResponse_s*)e->gg.g.n)
	  len += zx_LEN_WO_ps_QueryObjectsResponse(c, e);
  }
  {
      struct zx_ps_GetObjectInfoRequest_s* e;
      for (e = x->GetObjectInfoRequest; e; e = (struct zx_ps_GetObjectInfoRequest_s*)e->gg.g.n)
	  len += zx_LEN_WO_ps_GetObjectInfoRequest(c, e);
  }
  {
      struct zx_ps_GetObjectInfoResponse_s* e;
      for (e = x->GetObjectInfoResponse; e; e = (struct zx_ps_GetObjectInfoResponse_s*)e->gg.g.n)
	  len += zx_LEN_WO_ps_GetObjectInfoResponse(c, e);
  }
  {
      struct zx_ps_SetObjectInfoRequest_s* e;
      for (e = x->SetObjectInfoRequest; e; e = (struct zx_ps_SetObjectInfoRequest_s*)e->gg.g.n)
	  len += zx_LEN_WO_ps_SetObjectInfoRequest(c, e);
  }
  {
      struct zx_ps_SetObjectInfoResponse_s* e;
      for (e = x->SetObjectInfoResponse; e; e = (struct zx_ps_SetObjectInfoResponse_s*)e->gg.g.n)
	  len += zx_LEN_WO_ps_SetObjectInfoResponse(c, e);
  }
  {
      struct zx_ps_TestMembershipRequest_s* e;
      for (e = x->TestMembershipRequest; e; e = (struct zx_ps_TestMembershipRequest_s*)e->gg.g.n)
	  len += zx_LEN_WO_ps_TestMembershipRequest(c, e);
  }
  {
      struct zx_ps_TestMembershipResponse_s* e;
      for (e = x->TestMembershipResponse; e; e = (struct zx_ps_TestMembershipResponse_s*)e->gg.g.n)
	  len += zx_LEN_WO_ps_TestMembershipResponse(c, e);
  }
  {
      struct zx_ps_ResolveIdentifierRequest_s* e;
      for (e = x->ResolveIdentifierRequest; e; e = (struct zx_ps_ResolveIdentifierRequest_s*)e->gg.g.n)
	  len += zx_LEN_WO_ps_ResolveIdentifierRequest(c, e);
  }
  {
      struct zx_ps_ResolveIdentifierResponse_s* e;
      for (e = x->ResolveIdentifierResponse; e; e = (struct zx_ps_ResolveIdentifierResponse_s*)e->gg.g.n)
	  len += zx_LEN_WO_ps_ResolveIdentifierResponse(c, e);
  }
  {
      struct zx_ps_Notify_s* e;
      for (e = x->ps_Notify; e; e = (struct zx_ps_Notify_s*)e->gg.g.n)
	  len += zx_LEN_WO_ps_Notify(c, e);
  }
  {
      struct zx_ps_NotifyResponse_s* e;
      for (e = x->ps_NotifyResponse; e; e = (struct zx_ps_NotifyResponse_s*)e->gg.g.n)
	  len += zx_LEN_WO_ps_NotifyResponse(c, e);
  }
  {
      struct zx_im_IdentityMappingRequest_s* e;
      for (e = x->IdentityMappingRequest; e; e = (struct zx_im_IdentityMappingRequest_s*)e->gg.g.n)
	  len += zx_LEN_WO_im_IdentityMappingRequest(c, e);
  }
  {
      struct zx_im_IdentityMappingResponse_s* e;
      for (e = x->IdentityMappingResponse; e; e = (struct zx_im_IdentityMappingResponse_s*)e->gg.g.n)
	  len += zx_LEN_WO_im_IdentityMappingResponse(c, e);
  }
  {
      struct zx_as_SASLRequest_s* e;
      for (e = x->SASLRequest; e; e = (struct zx_as_SASLRequest_s*)e->gg.g.n)
	  len += zx_LEN_WO_as_SASLRequest(c, e);
  }
  {
      struct zx_as_SASLResponse_s* e;
      for (e = x->SASLResponse; e; e = (struct zx_as_SASLResponse_s*)e->gg.g.n)
	  len += zx_LEN_WO_as_SASLResponse(c, e);
  }
  {
      struct zx_mm7_SubmitReq_s* e;
      for (e = x->SubmitReq; e; e = (struct zx_mm7_SubmitReq_s*)e->gg.g.n)
	  len += zx_LEN_WO_mm7_SubmitReq(c, e);
  }
  {
      struct zx_mm7_SubmitRsp_s* e;
      for (e = x->SubmitRsp; e; e = (struct zx_mm7_SubmitRsp_s*)e->gg.g.n)
	  len += zx_LEN_WO_mm7_SubmitRsp(c, e);
  }
  {
      struct zx_mm7_DeliverReq_s* e;
      for (e = x->DeliverReq; e; e = (struct zx_mm7_DeliverReq_s*)e->gg.g.n)
	  len += zx_LEN_WO_mm7_DeliverReq(c, e);
  }
  {
      struct zx_mm7_DeliverRsp_s* e;
      for (e = x->DeliverRsp; e; e = (struct zx_mm7_DeliverRsp_s*)e->gg.g.n)
	  len += zx_LEN_WO_mm7_DeliverRsp(c, e);
  }
  {
      struct zx_mm7_CancelReq_s* e;
      for (e = x->CancelReq; e; e = (struct zx_mm7_CancelReq_s*)e->gg.g.n)
	  len += zx_LEN_WO_mm7_CancelReq(c, e);
  }
  {
      struct zx_mm7_CancelRsp_s* e;
      for (e = x->CancelRsp; e; e = (struct zx_mm7_CancelRsp_s*)e->gg.g.n)
	  len += zx_LEN_WO_mm7_CancelRsp(c, e);
  }
  {
      struct zx_mm7_ReplaceReq_s* e;
      for (e = x->ReplaceReq; e; e = (struct zx_mm7_ReplaceReq_s*)e->gg.g.n)
	  len += zx_LEN_WO_mm7_ReplaceReq(c, e);
  }
  {
      struct zx_mm7_ReplaceRsp_s* e;
      for (e = x->ReplaceRsp; e; e = (struct zx_mm7_ReplaceRsp_s*)e->gg.g.n)
	  len += zx_LEN_WO_mm7_ReplaceRsp(c, e);
  }
  {
      struct zx_mm7_extendedCancelReq_s* e;
      for (e = x->extendedCancelReq; e; e = (struct zx_mm7_extendedCancelReq_s*)e->gg.g.n)
	  len += zx_LEN_WO_mm7_extendedCancelReq(c, e);
  }
  {
      struct zx_mm7_extendedCancelRsp_s* e;
      for (e = x->extendedCancelRsp; e; e = (struct zx_mm7_extendedCancelRsp_s*)e->gg.g.n)
	  len += zx_LEN_WO_mm7_extendedCancelRsp(c, e);
  }
  {
      struct zx_mm7_extendedReplaceReq_s* e;
      for (e = x->extendedReplaceReq; e; e = (struct zx_mm7_extendedReplaceReq_s*)e->gg.g.n)
	  len += zx_LEN_WO_mm7_extendedReplaceReq(c, e);
  }
  {
      struct zx_mm7_extendedReplaceRsp_s* e;
      for (e = x->extendedReplaceRsp; e; e = (struct zx_mm7_extendedReplaceRsp_s*)e->gg.g.n)
	  len += zx_LEN_WO_mm7_extendedReplaceRsp(c, e);
  }
  {
      struct zx_mm7_DeliveryReportReq_s* e;
      for (e = x->DeliveryReportReq; e; e = (struct zx_mm7_DeliveryReportReq_s*)e->gg.g.n)
	  len += zx_LEN_WO_mm7_DeliveryReportReq(c, e);
  }
  {
      struct zx_mm7_DeliveryReportRsp_s* e;
      for (e = x->DeliveryReportRsp; e; e = (struct zx_mm7_DeliveryReportRsp_s*)e->gg.g.n)
	  len += zx_LEN_WO_mm7_DeliveryReportRsp(c, e);
  }
  {
      struct zx_mm7_ReadReplyReq_s* e;
      for (e = x->ReadReplyReq; e; e = (struct zx_mm7_ReadReplyReq_s*)e->gg.g.n)
	  len += zx_LEN_WO_mm7_ReadReplyReq(c, e);
  }
  {
      struct zx_mm7_ReadReplyRsp_s* e;
      for (e = x->ReadReplyRsp; e; e = (struct zx_mm7_ReadReplyRsp_s*)e->gg.g.n)
	  len += zx_LEN_WO_mm7_ReadReplyRsp(c, e);
  }
  {
      struct zx_mm7_RSErrorRsp_s* e;
      for (e = x->RSErrorRsp; e; e = (struct zx_mm7_RSErrorRsp_s*)e->gg.g.n)
	  len += zx_LEN_WO_mm7_RSErrorRsp(c, e);
  }
  {
      struct zx_mm7_VASPErrorRsp_s* e;
      for (e = x->VASPErrorRsp; e; e = (struct zx_mm7_VASPErrorRsp_s*)e->gg.g.n)
	  len += zx_LEN_WO_mm7_VASPErrorRsp(c, e);
  }
  {
      struct zx_mm7_QueryStatusReq_s* e;
      for (e = x->QueryStatusReq; e; e = (struct zx_mm7_QueryStatusReq_s*)e->gg.g.n)
	  len += zx_LEN_WO_mm7_QueryStatusReq(c, e);
  }
  {
      struct zx_mm7_QueryStatusRsp_s* e;
      for (e = x->QueryStatusRsp; e; e = (struct zx_mm7_QueryStatusRsp_s*)e->gg.g.n)
	  len += zx_LEN_WO_mm7_QueryStatusRsp(c, e);
  }
  {
      struct zx_cb_Query_s* e;
      for (e = x->cb_Query; e; e = (struct zx_cb_Query_s*)e->gg.g.n)
	  len += zx_LEN_WO_cb_Query(c, e);
  }
  {
      struct zx_cb_QueryResponse_s* e;
      for (e = x->cb_QueryResponse; e; e = (struct zx_cb_QueryResponse_s*)e->gg.g.n)
	  len += zx_LEN_WO_cb_QueryResponse(c, e);
  }
  {
      struct zx_cb_Create_s* e;
      for (e = x->cb_Create; e; e = (struct zx_cb_Create_s*)e->gg.g.n)
	  len += zx_LEN_WO_cb_Create(c, e);
  }
  {
      struct zx_cb_CreateResponse_s* e;
      for (e = x->cb_CreateResponse; e; e = (struct zx_cb_CreateResponse_s*)e->gg.g.n)
	  len += zx_LEN_WO_cb_CreateResponse(c, e);
  }
  {
      struct zx_cb_Delete_s* e;
      for (e = x->cb_Delete; e; e = (struct zx_cb_Delete_s*)e->gg.g.n)
	  len += zx_LEN_WO_cb_Delete(c, e);
  }
  {
      struct zx_cb_DeleteResponse_s* e;
      for (e = x->cb_DeleteResponse; e; e = (struct zx_cb_DeleteResponse_s*)e->gg.g.n)
	  len += zx_LEN_WO_cb_DeleteResponse(c, e);
  }
  {
      struct zx_cb_Modify_s* e;
      for (e = x->cb_Modify; e; e = (struct zx_cb_Modify_s*)e->gg.g.n)
	  len += zx_LEN_WO_cb_Modify(c, e);
  }
  {
      struct zx_cb_ModifyResponse_s* e;
      for (e = x->cb_ModifyResponse; e; e = (struct zx_cb_ModifyResponse_s*)e->gg.g.n)
	  len += zx_LEN_WO_cb_ModifyResponse(c, e);
  }
  {
      struct zx_cb_Notify_s* e;
      for (e = x->cb_Notify; e; e = (struct zx_cb_Notify_s*)e->gg.g.n)
	  len += zx_LEN_WO_cb_Notify(c, e);
  }
  {
      struct zx_cb_NotifyResponse_s* e;
      for (e = x->cb_NotifyResponse; e; e = (struct zx_cb_NotifyResponse_s*)e->gg.g.n)
	  len += zx_LEN_WO_cb_NotifyResponse(c, e);
  }
  {
      struct zx_cb_ReportUsage_s* e;
      for (e = x->ReportUsage; e; e = (struct zx_cb_ReportUsage_s*)e->gg.g.n)
	  len += zx_LEN_WO_cb_ReportUsage(c, e);
  }
  {
      struct zx_cb_ReportUsageResponse_s* e;
      for (e = x->ReportUsageResponse; e; e = (struct zx_cb_ReportUsageResponse_s*)e->gg.g.n)
	  len += zx_LEN_WO_cb_ReportUsageResponse(c, e);
  }
  {
      struct zx_gl_Query_s* e;
      for (e = x->gl_Query; e; e = (struct zx_gl_Query_s*)e->gg.g.n)
	  len += zx_LEN_WO_gl_Query(c, e);
  }
  {
      struct zx_gl_QueryResponse_s* e;
      for (e = x->gl_QueryResponse; e; e = (struct zx_gl_QueryResponse_s*)e->gg.g.n)
	  len += zx_LEN_WO_gl_QueryResponse(c, e);
  }
  {
      struct zx_gl_Create_s* e;
      for (e = x->gl_Create; e; e = (struct zx_gl_Create_s*)e->gg.g.n)
	  len += zx_LEN_WO_gl_Create(c, e);
  }
  {
      struct zx_gl_CreateResponse_s* e;
      for (e = x->gl_CreateResponse; e; e = (struct zx_gl_CreateResponse_s*)e->gg.g.n)
	  len += zx_LEN_WO_gl_CreateResponse(c, e);
  }
  {
      struct zx_gl_Delete_s* e;
      for (e = x->gl_Delete; e; e = (struct zx_gl_Delete_s*)e->gg.g.n)
	  len += zx_LEN_WO_gl_Delete(c, e);
  }
  {
      struct zx_gl_DeleteResponse_s* e;
      for (e = x->gl_DeleteResponse; e; e = (struct zx_gl_DeleteResponse_s*)e->gg.g.n)
	  len += zx_LEN_WO_gl_DeleteResponse(c, e);
  }
  {
      struct zx_gl_Modify_s* e;
      for (e = x->gl_Modify; e; e = (struct zx_gl_Modify_s*)e->gg.g.n)
	  len += zx_LEN_WO_gl_Modify(c, e);
  }
  {
      struct zx_gl_ModifyResponse_s* e;
      for (e = x->gl_ModifyResponse; e; e = (struct zx_gl_ModifyResponse_s*)e->gg.g.n)
	  len += zx_LEN_WO_gl_ModifyResponse(c, e);
  }
  {
      struct zx_gl_Notify_s* e;
      for (e = x->gl_Notify; e; e = (struct zx_gl_Notify_s*)e->gg.g.n)
	  len += zx_LEN_WO_gl_Notify(c, e);
  }
  {
      struct zx_gl_NotifyResponse_s* e;
      for (e = x->gl_NotifyResponse; e; e = (struct zx_gl_NotifyResponse_s*)e->gg.g.n)
	  len += zx_LEN_WO_gl_NotifyResponse(c, e);
  }
  {
      struct zx_demomed_StoreObjectRequest_s* e;
      for (e = x->StoreObjectRequest; e; e = (struct zx_demomed_StoreObjectRequest_s*)e->gg.g.n)
	  len += zx_LEN_WO_demomed_StoreObjectRequest(c, e);
  }
  {
      struct zx_demomed_StoreObjectResponse_s* e;
      for (e = x->StoreObjectResponse; e; e = (struct zx_demomed_StoreObjectResponse_s*)e->gg.g.n)
	  len += zx_LEN_WO_demomed_StoreObjectResponse(c, e);
  }
  {
      struct zx_demomed_GetObjectListRequest_s* e;
      for (e = x->GetObjectListRequest; e; e = (struct zx_demomed_GetObjectListRequest_s*)e->gg.g.n)
	  len += zx_LEN_WO_demomed_GetObjectListRequest(c, e);
  }
  {
      struct zx_demomed_GetObjectListResponse_s* e;
      for (e = x->GetObjectListResponse; e; e = (struct zx_demomed_GetObjectListResponse_s*)e->gg.g.n)
	  len += zx_LEN_WO_demomed_GetObjectListResponse(c, e);
  }
  {
      struct zx_demomed_GetObjectRequest_s* e;
      for (e = x->GetObjectRequest; e; e = (struct zx_demomed_GetObjectRequest_s*)e->gg.g.n)
	  len += zx_LEN_WO_demomed_GetObjectRequest(c, e);
  }
  {
      struct zx_demomed_GetObjectResponse_s* e;
      for (e = x->GetObjectResponse; e; e = (struct zx_demomed_GetObjectResponse_s*)e->gg.g.n)
	  len += zx_LEN_WO_demomed_GetObjectResponse(c, e);
  }
  {
      struct zx_demomed_DeleteObjectRequest_s* e;
      for (e = x->DeleteObjectRequest; e; e = (struct zx_demomed_DeleteObjectRequest_s*)e->gg.g.n)
	  len += zx_LEN_WO_demomed_DeleteObjectRequest(c, e);
  }
  {
      struct zx_demomed_DeleteObjectResponse_s* e;
      for (e = x->DeleteObjectResponse; e; e = (struct zx_demomed_DeleteObjectResponse_s*)e->gg.g.n)
	  len += zx_LEN_WO_demomed_DeleteObjectResponse(c, e);
  }
  {
      struct zx_pmm_Provision_s* e;
      for (e = x->Provision; e; e = (struct zx_pmm_Provision_s*)e->gg.g.n)
	  len += zx_LEN_WO_pmm_Provision(c, e);
  }
  {
      struct zx_pmm_ProvisionResponse_s* e;
      for (e = x->ProvisionResponse; e; e = (struct zx_pmm_ProvisionResponse_s*)e->gg.g.n)
	  len += zx_LEN_WO_pmm_ProvisionResponse(c, e);
  }
  {
      struct zx_pmm_PMActivate_s* e;
      for (e = x->PMActivate; e; e = (struct zx_pmm_PMActivate_s*)e->gg.g.n)
	  len += zx_LEN_WO_pmm_PMActivate(c, e);
  }
  {
      struct zx_pmm_PMActivateResponse_s* e;
      for (e = x->PMActivateResponse; e; e = (struct zx_pmm_PMActivateResponse_s*)e->gg.g.n)
	  len += zx_LEN_WO_pmm_PMActivateResponse(c, e);
  }
  {
      struct zx_pmm_PMDeactivate_s* e;
      for (e = x->PMDeactivate; e; e = (struct zx_pmm_PMDeactivate_s*)e->gg.g.n)
	  len += zx_LEN_WO_pmm_PMDeactivate(c, e);
  }
  {
      struct zx_pmm_PMDeactivateResponse_s* e;
      for (e = x->PMDeactivateResponse; e; e = (struct zx_pmm_PMDeactivateResponse_s*)e->gg.g.n)
	  len += zx_LEN_WO_pmm_PMDeactivateResponse(c, e);
  }
  {
      struct zx_pmm_PMDelete_s* e;
      for (e = x->PMDelete; e; e = (struct zx_pmm_PMDelete_s*)e->gg.g.n)
	  len += zx_LEN_WO_pmm_PMDelete(c, e);
  }
  {
      struct zx_pmm_PMDeleteResponse_s* e;
      for (e = x->PMDeleteResponse; e; e = (struct zx_pmm_PMDeleteResponse_s*)e->gg.g.n)
	  len += zx_LEN_WO_pmm_PMDeleteResponse(c, e);
  }
  {
      struct zx_pmm_PMUpdate_s* e;
      for (e = x->PMUpdate; e; e = (struct zx_pmm_PMUpdate_s*)e->gg.g.n)
	  len += zx_LEN_WO_pmm_PMUpdate(c, e);
  }
  {
      struct zx_pmm_PMUpdateResponse_s* e;
      for (e = x->PMUpdateResponse; e; e = (struct zx_pmm_PMUpdateResponse_s*)e->gg.g.n)
	  len += zx_LEN_WO_pmm_PMUpdateResponse(c, e);
  }
  {
      struct zx_pmm_PMGetStatus_s* e;
      for (e = x->PMGetStatus; e; e = (struct zx_pmm_PMGetStatus_s*)e->gg.g.n)
	  len += zx_LEN_WO_pmm_PMGetStatus(c, e);
  }
  {
      struct zx_pmm_PMGetStatusResponse_s* e;
      for (e = x->PMGetStatusResponse; e; e = (struct zx_pmm_PMGetStatusResponse_s*)e->gg.g.n)
	  len += zx_LEN_WO_pmm_PMGetStatusResponse(c, e);
  }
  {
      struct zx_pmm_PMSetStatus_s* e;
      for (e = x->PMSetStatus; e; e = (struct zx_pmm_PMSetStatus_s*)e->gg.g.n)
	  len += zx_LEN_WO_pmm_PMSetStatus(c, e);
  }
  {
      struct zx_pmm_PMSetStatusResponse_s* e;
      for (e = x->PMSetStatusResponse; e; e = (struct zx_pmm_PMSetStatusResponse_s*)e->gg.g.n)
	  len += zx_LEN_WO_pmm_PMSetStatusResponse(c, e);
  }
  {
      struct zx_prov_PMERegister_s* e;
      for (e = x->PMERegister; e; e = (struct zx_prov_PMERegister_s*)e->gg.g.n)
	  len += zx_LEN_WO_prov_PMERegister(c, e);
  }
  {
      struct zx_prov_PMERegisterResponse_s* e;
      for (e = x->PMERegisterResponse; e; e = (struct zx_prov_PMERegisterResponse_s*)e->gg.g.n)
	  len += zx_LEN_WO_prov_PMERegisterResponse(c, e);
  }
  {
      struct zx_prov_PMEUpload_s* e;
      for (e = x->PMEUpload; e; e = (struct zx_prov_PMEUpload_s*)e->gg.g.n)
	  len += zx_LEN_WO_prov_PMEUpload(c, e);
  }
  {
      struct zx_prov_PMEUploadResponse_s* e;
      for (e = x->PMEUploadResponse; e; e = (struct zx_prov_PMEUploadResponse_s*)e->gg.g.n)
	  len += zx_LEN_WO_prov_PMEUploadResponse(c, e);
  }
  {
      struct zx_prov_PMEDownload_s* e;
      for (e = x->PMEDownload; e; e = (struct zx_prov_PMEDownload_s*)e->gg.g.n)
	  len += zx_LEN_WO_prov_PMEDownload(c, e);
  }
  {
      struct zx_prov_PMEDownloadResponse_s* e;
      for (e = x->PMEDownloadResponse; e; e = (struct zx_prov_PMEDownloadResponse_s*)e->gg.g.n)
	  len += zx_LEN_WO_prov_PMEDownloadResponse(c, e);
  }
  {
      struct zx_prov_PMEEnable_s* e;
      for (e = x->PMEEnable; e; e = (struct zx_prov_PMEEnable_s*)e->gg.g.n)
	  len += zx_LEN_WO_prov_PMEEnable(c, e);
  }
  {
      struct zx_prov_PMEEnableResponse_s* e;
      for (e = x->PMEEnableResponse; e; e = (struct zx_prov_PMEEnableResponse_s*)e->gg.g.n)
	  len += zx_LEN_WO_prov_PMEEnableResponse(c, e);
  }
  {
      struct zx_prov_PMEDisable_s* e;
      for (e = x->PMEDisable; e; e = (struct zx_prov_PMEDisable_s*)e->gg.g.n)
	  len += zx_LEN_WO_prov_PMEDisable(c, e);
  }
  {
      struct zx_prov_PMEDisableResponse_s* e;
      for (e = x->PMEDisableResponse; e; e = (struct zx_prov_PMEDisableResponse_s*)e->gg.g.n)
	  len += zx_LEN_WO_prov_PMEDisableResponse(c, e);
  }
  {
      struct zx_prov_PMEDelete_s* e;
      for (e = x->PMEDelete; e; e = (struct zx_prov_PMEDelete_s*)e->gg.g.n)
	  len += zx_LEN_WO_prov_PMEDelete(c, e);
  }
  {
      struct zx_prov_PMEDeleteResponse_s* e;
      for (e = x->PMEDeleteResponse; e; e = (struct zx_prov_PMEDeleteResponse_s*)e->gg.g.n)
	  len += zx_LEN_WO_prov_PMEDeleteResponse(c, e);
  }
  {
      struct zx_prov_PMEGetInfo_s* e;
      for (e = x->PMEGetInfo; e; e = (struct zx_prov_PMEGetInfo_s*)e->gg.g.n)
	  len += zx_LEN_WO_prov_PMEGetInfo(c, e);
  }
  {
      struct zx_prov_PMEGetInfoResponse_s* e;
      for (e = x->PMEGetInfoResponse; e; e = (struct zx_prov_PMEGetInfoResponse_s*)e->gg.g.n)
	  len += zx_LEN_WO_prov_PMEGetInfoResponse(c, e);
  }
  {
      struct zx_prov_PMGetStatus_s* e;
      for (e = x->prov_PMGetStatus; e; e = (struct zx_prov_PMGetStatus_s*)e->gg.g.n)
	  len += zx_LEN_WO_prov_PMGetStatus(c, e);
  }
  {
      struct zx_prov_PMGetStatusResponse_s* e;
      for (e = x->prov_PMGetStatusResponse; e; e = (struct zx_prov_PMGetStatusResponse_s*)e->gg.g.n)
	  len += zx_LEN_WO_prov_PMGetStatusResponse(c, e);
  }
  {
      struct zx_prov_PMSetStatus_s* e;
      for (e = x->prov_PMSetStatus; e; e = (struct zx_prov_PMSetStatus_s*)e->gg.g.n)
	  len += zx_LEN_WO_prov_PMSetStatus(c, e);
  }
  {
      struct zx_prov_PMSetStatusResponse_s* e;
      for (e = x->prov_PMSetStatusResponse; e; e = (struct zx_prov_PMSetStatusResponse_s*)e->gg.g.n)
	  len += zx_LEN_WO_prov_PMSetStatusResponse(c, e);
  }
  {
      struct zx_prov_PMGetDescriptor_s* e;
      for (e = x->PMGetDescriptor; e; e = (struct zx_prov_PMGetDescriptor_s*)e->gg.g.n)
	  len += zx_LEN_WO_prov_PMGetDescriptor(c, e);
  }
  {
      struct zx_prov_PMGetDescriptorResponse_s* e;
      for (e = x->PMGetDescriptorResponse; e; e = (struct zx_prov_PMGetDescriptorResponse_s*)e->gg.g.n)
	  len += zx_LEN_WO_prov_PMGetDescriptorResponse(c, e);
  }
  {
      struct zx_prov_PMActivate_s* e;
      for (e = x->prov_PMActivate; e; e = (struct zx_prov_PMActivate_s*)e->gg.g.n)
	  len += zx_LEN_WO_prov_PMActivate(c, e);
  }
  {
      struct zx_prov_PMActivateResponse_s* e;
      for (e = x->prov_PMActivateResponse; e; e = (struct zx_prov_PMActivateResponse_s*)e->gg.g.n)
	  len += zx_LEN_WO_prov_PMActivateResponse(c, e);
  }
  {
      struct zx_prov_PMDeactivate_s* e;
      for (e = x->prov_PMDeactivate; e; e = (struct zx_prov_PMDeactivate_s*)e->gg.g.n)
	  len += zx_LEN_WO_prov_PMDeactivate(c, e);
  }
  {
      struct zx_prov_PMDeactivateResponse_s* e;
      for (e = x->prov_PMDeactivateResponse; e; e = (struct zx_prov_PMDeactivateResponse_s*)e->gg.g.n)
	  len += zx_LEN_WO_prov_PMDeactivateResponse(c, e);
  }
  {
      struct zx_prov_PMRegisterDescriptor_s* e;
      for (e = x->PMRegisterDescriptor; e; e = (struct zx_prov_PMRegisterDescriptor_s*)e->gg.g.n)
	  len += zx_LEN_WO_prov_PMRegisterDescriptor(c, e);
  }
  {
      struct zx_prov_PMRegisterDescriptorResponse_s* e;
      for (e = x->PMRegisterDescriptorResponse; e; e = (struct zx_prov_PMRegisterDescriptorResponse_s*)e->gg.g.n)
	  len += zx_LEN_WO_prov_PMRegisterDescriptorResponse(c, e);
  }
  {
      struct zx_prov_PMUpdate_s* e;
      for (e = x->prov_PMUpdate; e; e = (struct zx_prov_PMUpdate_s*)e->gg.g.n)
	  len += zx_LEN_WO_prov_PMUpdate(c, e);
  }
  {
      struct zx_prov_PMUpdateResponse_s* e;
      for (e = x->prov_PMUpdateResponse; e; e = (struct zx_prov_PMUpdateResponse_s*)e->gg.g.n)
	  len += zx_LEN_WO_prov_PMUpdateResponse(c, e);
  }
  {
      struct zx_prov_PMDelete_s* e;
      for (e = x->prov_PMDelete; e; e = (struct zx_prov_PMDelete_s*)e->gg.g.n)
	  len += zx_LEN_WO_prov_PMDelete(c, e);
  }
  {
      struct zx_prov_PMDeleteResponse_s* e;
      for (e = x->prov_PMDeleteResponse; e; e = (struct zx_prov_PMDeleteResponse_s*)e->gg.g.n)
	  len += zx_LEN_WO_prov_PMDeleteResponse(c, e);
  }
  {
      struct zx_prov_Poll_s* e;
      for (e = x->Poll; e; e = (struct zx_prov_Poll_s*)e->gg.g.n)
	  len += zx_LEN_WO_prov_Poll(c, e);
  }
  {
      struct zx_prov_PollResponse_s* e;
      for (e = x->PollResponse; e; e = (struct zx_prov_PollResponse_s*)e->gg.g.n)
	  len += zx_LEN_WO_prov_PollResponse(c, e);
  }
  {
      struct zx_prov_UpdateEPR_s* e;
      for (e = x->UpdateEPR; e; e = (struct zx_prov_UpdateEPR_s*)e->gg.g.n)
	  len += zx_LEN_WO_prov_UpdateEPR(c, e);
  }
  {
      struct zx_prov_UpdateEPRResponse_s* e;
      for (e = x->UpdateEPRResponse; e; e = (struct zx_prov_UpdateEPRResponse_s*)e->gg.g.n)
	  len += zx_LEN_WO_prov_UpdateEPRResponse(c, e);
  }
  {
      struct zx_idp_GetAssertion_s* e;
      for (e = x->GetAssertion; e; e = (struct zx_idp_GetAssertion_s*)e->gg.g.n)
	  len += zx_LEN_WO_idp_GetAssertion(c, e);
  }
  {
      struct zx_idp_GetAssertionResponse_s* e;
      for (e = x->GetAssertionResponse; e; e = (struct zx_idp_GetAssertionResponse_s*)e->gg.g.n)
	  len += zx_LEN_WO_idp_GetAssertionResponse(c, e);
  }
  {
      struct zx_idp_GetProviderInfo_s* e;
      for (e = x->GetProviderInfo; e; e = (struct zx_idp_GetProviderInfo_s*)e->gg.g.n)
	  len += zx_LEN_WO_idp_GetProviderInfo(c, e);
  }
  {
      struct zx_idp_GetProviderInfoResponse_s* e;
      for (e = x->GetProviderInfoResponse; e; e = (struct zx_idp_GetProviderInfoResponse_s*)e->gg.g.n)
	  len += zx_LEN_WO_idp_GetProviderInfoResponse(c, e);
  }
  {
      struct zx_idp_CreatedStatus_s* e;
      for (e = x->CreatedStatus; e; e = (struct zx_idp_CreatedStatus_s*)e->gg.g.n)
	  len += zx_LEN_WO_idp_CreatedStatus(c, e);
  }
  {
      struct zx_idp_CreatedStatusResponse_s* e;
      for (e = x->CreatedStatusResponse; e; e = (struct zx_idp_CreatedStatusResponse_s*)e->gg.g.n)
	  len += zx_LEN_WO_idp_CreatedStatusResponse(c, e);
  }
  {
      struct zx_shps_Delete_s* e;
      for (e = x->shps_Delete; e; e = (struct zx_shps_Delete_s*)e->gg.g.n)
	  len += zx_LEN_WO_shps_Delete(c, e);
  }
  {
      struct zx_shps_DeleteResponse_s* e;
      for (e = x->shps_DeleteResponse; e; e = (struct zx_shps_DeleteResponse_s*)e->gg.g.n)
	  len += zx_LEN_WO_shps_DeleteResponse(c, e);
  }
  {
      struct zx_shps_GetStatus_s* e;
      for (e = x->GetStatus; e; e = (struct zx_shps_GetStatus_s*)e->gg.g.n)
	  len += zx_LEN_WO_shps_GetStatus(c, e);
  }
  {
      struct zx_shps_GetStatusResponse_s* e;
      for (e = x->GetStatusResponse; e; e = (struct zx_shps_GetStatusResponse_s*)e->gg.g.n)
	  len += zx_LEN_WO_shps_GetStatusResponse(c, e);
  }
  {
      struct zx_shps_Query_s* e;
      for (e = x->shps_Query; e; e = (struct zx_shps_Query_s*)e->gg.g.n)
	  len += zx_LEN_WO_shps_Query(c, e);
  }
  {
      struct zx_shps_QueryResponse_s* e;
      for (e = x->shps_QueryResponse; e; e = (struct zx_shps_QueryResponse_s*)e->gg.g.n)
	  len += zx_LEN_WO_shps_QueryResponse(c, e);
  }
  for (se = x->Invoke; se; se = (struct zx_elem_s*)se->g.n)
    len += zx_LEN_WO_simple_elem(c, se, sizeof("Invoke")-1);
  {
      struct zx_shps_InvokeResponse_s* e;
      for (e = x->InvokeResponse; e; e = (struct zx_shps_InvokeResponse_s*)e->gg.g.n)
	  len += zx_LEN_WO_shps_InvokeResponse(c, e);
  }
  {
      struct zx_shps_QueryRegistered_s* e;
      for (e = x->QueryRegistered; e; e = (struct zx_shps_QueryRegistered_s*)e->gg.g.n)
	  len += zx_LEN_WO_shps_QueryRegistered(c, e);
  }
  {
      struct zx_shps_QueryRegisteredResponse_s* e;
      for (e = x->QueryRegisteredResponse; e; e = (struct zx_shps_QueryRegisteredResponse_s*)e->gg.g.n)
	  len += zx_LEN_WO_shps_QueryRegisteredResponse(c, e);
  }
  {
      struct zx_shps_Register_s* e;
      for (e = x->Register; e; e = (struct zx_shps_Register_s*)e->gg.g.n)
	  len += zx_LEN_WO_shps_Register(c, e);
  }
  {
      struct zx_shps_RegisterResponse_s* e;
      for (e = x->RegisterResponse; e; e = (struct zx_shps_RegisterResponse_s*)e->gg.g.n)
	  len += zx_LEN_WO_shps_RegisterResponse(c, e);
  }
  {
      struct zx_shps_SetStatus_s* e;
      for (e = x->SetStatus; e; e = (struct zx_shps_SetStatus_s*)e->gg.g.n)
	  len += zx_LEN_WO_shps_SetStatus(c, e);
  }
  {
      struct zx_shps_SetStatusResponse_s* e;
      for (e = x->SetStatusResponse; e; e = (struct zx_shps_SetStatusResponse_s*)e->gg.g.n)
	  len += zx_LEN_WO_shps_SetStatusResponse(c, e);
  }
  {
      struct zx_shps_Update_s* e;
      for (e = x->Update; e; e = (struct zx_shps_Update_s*)e->gg.g.n)
	  len += zx_LEN_WO_shps_Update(c, e);
  }
  {
      struct zx_shps_UpdateResponse_s* e;
      for (e = x->UpdateResponse; e; e = (struct zx_shps_UpdateResponse_s*)e->gg.g.n)
	  len += zx_LEN_WO_shps_UpdateResponse(c, e);
  }
  {
      struct zx_shps_Poll_s* e;
      for (e = x->shps_Poll; e; e = (struct zx_shps_Poll_s*)e->gg.g.n)
	  len += zx_LEN_WO_shps_Poll(c, e);
  }
  {
      struct zx_shps_PollResponse_s* e;
      for (e = x->shps_PollResponse; e; e = (struct zx_shps_PollResponse_s*)e->gg.g.n)
	  len += zx_LEN_WO_shps_PollResponse(c, e);
  }
  {
      struct zx_shps_ProxyInvoke_s* e;
      for (e = x->ProxyInvoke; e; e = (struct zx_shps_ProxyInvoke_s*)e->gg.g.n)
	  len += zx_LEN_WO_shps_ProxyInvoke(c, e);
  }
  {
      struct zx_shps_ProxyInvokeResponse_s* e;
      for (e = x->ProxyInvokeResponse; e; e = (struct zx_shps_ProxyInvokeResponse_s*)e->gg.g.n)
	  len += zx_LEN_WO_shps_ProxyInvokeResponse(c, e);
  }
  {
      struct zx_idhrxml_Create_s* e;
      for (e = x->idhrxml_Create; e; e = (struct zx_idhrxml_Create_s*)e->gg.g.n)
	  len += zx_LEN_WO_idhrxml_Create(c, e);
  }
  {
      struct zx_idhrxml_CreateResponse_s* e;
      for (e = x->idhrxml_CreateResponse; e; e = (struct zx_idhrxml_CreateResponse_s*)e->gg.g.n)
	  len += zx_LEN_WO_idhrxml_CreateResponse(c, e);
  }
  {
      struct zx_idhrxml_Query_s* e;
      for (e = x->idhrxml_Query; e; e = (struct zx_idhrxml_Query_s*)e->gg.g.n)
	  len += zx_LEN_WO_idhrxml_Query(c, e);
  }
  {
      struct zx_idhrxml_QueryResponse_s* e;
      for (e = x->idhrxml_QueryResponse; e; e = (struct zx_idhrxml_QueryResponse_s*)e->gg.g.n)
	  len += zx_LEN_WO_idhrxml_QueryResponse(c, e);
  }
  {
      struct zx_idhrxml_Modify_s* e;
      for (e = x->idhrxml_Modify; e; e = (struct zx_idhrxml_Modify_s*)e->gg.g.n)
	  len += zx_LEN_WO_idhrxml_Modify(c, e);
  }
  {
      struct zx_idhrxml_ModifyResponse_s* e;
      for (e = x->idhrxml_ModifyResponse; e; e = (struct zx_idhrxml_ModifyResponse_s*)e->gg.g.n)
	  len += zx_LEN_WO_idhrxml_ModifyResponse(c, e);
  }
  {
      struct zx_idhrxml_Delete_s* e;
      for (e = x->idhrxml_Delete; e; e = (struct zx_idhrxml_Delete_s*)e->gg.g.n)
	  len += zx_LEN_WO_idhrxml_Delete(c, e);
  }
  {
      struct zx_idhrxml_DeleteResponse_s* e;
      for (e = x->idhrxml_DeleteResponse; e; e = (struct zx_idhrxml_DeleteResponse_s*)e->gg.g.n)
	  len += zx_LEN_WO_idhrxml_DeleteResponse(c, e);
  }
  {
      struct zx_idhrxml_Notify_s* e;
      for (e = x->idhrxml_Notify; e; e = (struct zx_idhrxml_Notify_s*)e->gg.g.n)
	  len += zx_LEN_WO_idhrxml_Notify(c, e);
  }
  {
      struct zx_idhrxml_NotifyResponse_s* e;
      for (e = x->idhrxml_NotifyResponse; e; e = (struct zx_idhrxml_NotifyResponse_s*)e->gg.g.n)
	  len += zx_LEN_WO_idhrxml_NotifyResponse(c, e);
  }


  len += zx_len_wo_common(c, &x->gg); 
  zx_pop_seen(pop_seen);
  ENC_LEN_DEBUG(x, "e:Body", len);
  return len;
}

/* FUNC(zx_ENC_SO_e_Body) */

/* Render element into string. The XML attributes and elements are
 * processed in schema order. This is what you generally want for
 * rendering new data structure to a string. The wo pointers are not used. */

/* Called by: */
char* zx_ENC_SO_e_Body(struct zx_ctx* c, struct zx_e_Body_s* x, char* p )
{
  struct zx_elem_s* se MAYBE_UNUSED;
  ENC_LEN_DEBUG_BASE;
#if 1 /* NORMALMODE */
  struct zx_ns_s* pop_seen = 0;
  /* *** in simple_elem case should output ns prefix from ns node. */
  ZX_OUT_TAG(p, "<e:Body");
  if (c->inc_ns)
    p = zx_enc_inc_ns(c, p, &pop_seen);
  p = zx_enc_xmlns_if_not_seen(c, p, zx_ns_tab+zx_xmlns_ix_e, &pop_seen);

  p = zx_attr_so_enc(p, x->id, " id=\"", sizeof(" id=\"")-1);

  p = zx_enc_unknown_attrs(p, x->gg.any_attr);
#else
  /* root node has no begin tag */
#endif
  
  {
      struct zx_sp_ArtifactResolve_s* e;
      for (e = x->ArtifactResolve; e; e = (struct zx_sp_ArtifactResolve_s*)e->gg.g.n)
	  p = zx_ENC_SO_sp_ArtifactResolve(c, e, p);
  }
  {
      struct zx_sp_ArtifactResponse_s* e;
      for (e = x->ArtifactResponse; e; e = (struct zx_sp_ArtifactResponse_s*)e->gg.g.n)
	  p = zx_ENC_SO_sp_ArtifactResponse(c, e, p);
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
      struct zx_sp_NameIDMappingRequest_s* e;
      for (e = x->NameIDMappingRequest; e; e = (struct zx_sp_NameIDMappingRequest_s*)e->gg.g.n)
	  p = zx_ENC_SO_sp_NameIDMappingRequest(c, e, p);
  }
  {
      struct zx_sp_NameIDMappingResponse_s* e;
      for (e = x->NameIDMappingResponse; e; e = (struct zx_sp_NameIDMappingResponse_s*)e->gg.g.n)
	  p = zx_ENC_SO_sp_NameIDMappingResponse(c, e, p);
  }
  {
      struct zx_sp_AttributeQuery_s* e;
      for (e = x->AttributeQuery; e; e = (struct zx_sp_AttributeQuery_s*)e->gg.g.n)
	  p = zx_ENC_SO_sp_AttributeQuery(c, e, p);
  }
  {
      struct zx_sp_AuthnQuery_s* e;
      for (e = x->AuthnQuery; e; e = (struct zx_sp_AuthnQuery_s*)e->gg.g.n)
	  p = zx_ENC_SO_sp_AuthnQuery(c, e, p);
  }
  {
      struct zx_sp_AuthzDecisionQuery_s* e;
      for (e = x->AuthzDecisionQuery; e; e = (struct zx_sp_AuthzDecisionQuery_s*)e->gg.g.n)
	  p = zx_ENC_SO_sp_AuthzDecisionQuery(c, e, p);
  }
  {
      struct zx_sp_AssertionIDRequest_s* e;
      for (e = x->AssertionIDRequest; e; e = (struct zx_sp_AssertionIDRequest_s*)e->gg.g.n)
	  p = zx_ENC_SO_sp_AssertionIDRequest(c, e, p);
  }
  {
      struct zx_sp_Response_s* e;
      for (e = x->Response; e; e = (struct zx_sp_Response_s*)e->gg.g.n)
	  p = zx_ENC_SO_sp_Response(c, e, p);
  }
  {
      struct zx_sp_AuthnRequest_s* e;
      for (e = x->AuthnRequest; e; e = (struct zx_sp_AuthnRequest_s*)e->gg.g.n)
	  p = zx_ENC_SO_sp_AuthnRequest(c, e, p);
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
  {
      struct zx_xac_Request_s* e;
      for (e = x->xac_Request; e; e = (struct zx_xac_Request_s*)e->gg.g.n)
	  p = zx_ENC_SO_xac_Request(c, e, p);
  }
  {
      struct zx_xac_Response_s* e;
      for (e = x->xac_Response; e; e = (struct zx_xac_Response_s*)e->gg.g.n)
	  p = zx_ENC_SO_xac_Response(c, e, p);
  }
  {
      struct zx_di_Query_s* e;
      for (e = x->Query; e; e = (struct zx_di_Query_s*)e->gg.g.n)
	  p = zx_ENC_SO_di_Query(c, e, p);
  }
  {
      struct zx_di_QueryResponse_s* e;
      for (e = x->QueryResponse; e; e = (struct zx_di_QueryResponse_s*)e->gg.g.n)
	  p = zx_ENC_SO_di_QueryResponse(c, e, p);
  }
  {
      struct zx_di12_Query_s* e;
      for (e = x->di12_Query; e; e = (struct zx_di12_Query_s*)e->gg.g.n)
	  p = zx_ENC_SO_di12_Query(c, e, p);
  }
  {
      struct zx_di12_QueryResponse_s* e;
      for (e = x->di12_QueryResponse; e; e = (struct zx_di12_QueryResponse_s*)e->gg.g.n)
	  p = zx_ENC_SO_di12_QueryResponse(c, e, p);
  }
  {
      struct zx_di12_Modify_s* e;
      for (e = x->Modify; e; e = (struct zx_di12_Modify_s*)e->gg.g.n)
	  p = zx_ENC_SO_di12_Modify(c, e, p);
  }
  {
      struct zx_di12_ModifyResponse_s* e;
      for (e = x->ModifyResponse; e; e = (struct zx_di12_ModifyResponse_s*)e->gg.g.n)
	  p = zx_ENC_SO_di12_ModifyResponse(c, e, p);
  }
  {
      struct zx_e_Fault_s* e;
      for (e = x->Fault; e; e = (struct zx_e_Fault_s*)e->gg.g.n)
	  p = zx_ENC_SO_e_Fault(c, e, p);
  }
  {
      struct zx_di_SvcMDAssociationAdd_s* e;
      for (e = x->SvcMDAssociationAdd; e; e = (struct zx_di_SvcMDAssociationAdd_s*)e->gg.g.n)
	  p = zx_ENC_SO_di_SvcMDAssociationAdd(c, e, p);
  }
  {
      struct zx_di_SvcMDAssociationAddResponse_s* e;
      for (e = x->SvcMDAssociationAddResponse; e; e = (struct zx_di_SvcMDAssociationAddResponse_s*)e->gg.g.n)
	  p = zx_ENC_SO_di_SvcMDAssociationAddResponse(c, e, p);
  }
  {
      struct zx_di_SvcMDAssociationDelete_s* e;
      for (e = x->SvcMDAssociationDelete; e; e = (struct zx_di_SvcMDAssociationDelete_s*)e->gg.g.n)
	  p = zx_ENC_SO_di_SvcMDAssociationDelete(c, e, p);
  }
  {
      struct zx_di_SvcMDAssociationDeleteResponse_s* e;
      for (e = x->SvcMDAssociationDeleteResponse; e; e = (struct zx_di_SvcMDAssociationDeleteResponse_s*)e->gg.g.n)
	  p = zx_ENC_SO_di_SvcMDAssociationDeleteResponse(c, e, p);
  }
  {
      struct zx_di_SvcMDAssociationQuery_s* e;
      for (e = x->SvcMDAssociationQuery; e; e = (struct zx_di_SvcMDAssociationQuery_s*)e->gg.g.n)
	  p = zx_ENC_SO_di_SvcMDAssociationQuery(c, e, p);
  }
  {
      struct zx_di_SvcMDAssociationQueryResponse_s* e;
      for (e = x->SvcMDAssociationQueryResponse; e; e = (struct zx_di_SvcMDAssociationQueryResponse_s*)e->gg.g.n)
	  p = zx_ENC_SO_di_SvcMDAssociationQueryResponse(c, e, p);
  }
  {
      struct zx_di_SvcMDRegister_s* e;
      for (e = x->SvcMDRegister; e; e = (struct zx_di_SvcMDRegister_s*)e->gg.g.n)
	  p = zx_ENC_SO_di_SvcMDRegister(c, e, p);
  }
  {
      struct zx_di_SvcMDRegisterResponse_s* e;
      for (e = x->SvcMDRegisterResponse; e; e = (struct zx_di_SvcMDRegisterResponse_s*)e->gg.g.n)
	  p = zx_ENC_SO_di_SvcMDRegisterResponse(c, e, p);
  }
  {
      struct zx_di_SvcMDDelete_s* e;
      for (e = x->SvcMDDelete; e; e = (struct zx_di_SvcMDDelete_s*)e->gg.g.n)
	  p = zx_ENC_SO_di_SvcMDDelete(c, e, p);
  }
  {
      struct zx_di_SvcMDDeleteResponse_s* e;
      for (e = x->SvcMDDeleteResponse; e; e = (struct zx_di_SvcMDDeleteResponse_s*)e->gg.g.n)
	  p = zx_ENC_SO_di_SvcMDDeleteResponse(c, e, p);
  }
  {
      struct zx_di_SvcMDQuery_s* e;
      for (e = x->SvcMDQuery; e; e = (struct zx_di_SvcMDQuery_s*)e->gg.g.n)
	  p = zx_ENC_SO_di_SvcMDQuery(c, e, p);
  }
  {
      struct zx_di_SvcMDQueryResponse_s* e;
      for (e = x->SvcMDQueryResponse; e; e = (struct zx_di_SvcMDQueryResponse_s*)e->gg.g.n)
	  p = zx_ENC_SO_di_SvcMDQueryResponse(c, e, p);
  }
  {
      struct zx_di_SvcMDReplace_s* e;
      for (e = x->SvcMDReplace; e; e = (struct zx_di_SvcMDReplace_s*)e->gg.g.n)
	  p = zx_ENC_SO_di_SvcMDReplace(c, e, p);
  }
  {
      struct zx_di_SvcMDReplaceResponse_s* e;
      for (e = x->SvcMDReplaceResponse; e; e = (struct zx_di_SvcMDReplaceResponse_s*)e->gg.g.n)
	  p = zx_ENC_SO_di_SvcMDReplaceResponse(c, e, p);
  }
  {
      struct zx_dap_Create_s* e;
      for (e = x->Create; e; e = (struct zx_dap_Create_s*)e->gg.g.n)
	  p = zx_ENC_SO_dap_Create(c, e, p);
  }
  {
      struct zx_dap_CreateResponse_s* e;
      for (e = x->CreateResponse; e; e = (struct zx_dap_CreateResponse_s*)e->gg.g.n)
	  p = zx_ENC_SO_dap_CreateResponse(c, e, p);
  }
  {
      struct zx_dap_Query_s* e;
      for (e = x->dap_Query; e; e = (struct zx_dap_Query_s*)e->gg.g.n)
	  p = zx_ENC_SO_dap_Query(c, e, p);
  }
  {
      struct zx_dap_QueryResponse_s* e;
      for (e = x->dap_QueryResponse; e; e = (struct zx_dap_QueryResponse_s*)e->gg.g.n)
	  p = zx_ENC_SO_dap_QueryResponse(c, e, p);
  }
  {
      struct zx_dap_Modify_s* e;
      for (e = x->dap_Modify; e; e = (struct zx_dap_Modify_s*)e->gg.g.n)
	  p = zx_ENC_SO_dap_Modify(c, e, p);
  }
  {
      struct zx_dap_ModifyResponse_s* e;
      for (e = x->dap_ModifyResponse; e; e = (struct zx_dap_ModifyResponse_s*)e->gg.g.n)
	  p = zx_ENC_SO_dap_ModifyResponse(c, e, p);
  }
  {
      struct zx_dap_Delete_s* e;
      for (e = x->Delete; e; e = (struct zx_dap_Delete_s*)e->gg.g.n)
	  p = zx_ENC_SO_dap_Delete(c, e, p);
  }
  {
      struct zx_dap_DeleteResponse_s* e;
      for (e = x->DeleteResponse; e; e = (struct zx_dap_DeleteResponse_s*)e->gg.g.n)
	  p = zx_ENC_SO_dap_DeleteResponse(c, e, p);
  }
  {
      struct zx_dap_Notify_s* e;
      for (e = x->Notify; e; e = (struct zx_dap_Notify_s*)e->gg.g.n)
	  p = zx_ENC_SO_dap_Notify(c, e, p);
  }
  {
      struct zx_dap_NotifyResponse_s* e;
      for (e = x->NotifyResponse; e; e = (struct zx_dap_NotifyResponse_s*)e->gg.g.n)
	  p = zx_ENC_SO_dap_NotifyResponse(c, e, p);
  }
  {
      struct zx_ps_AddEntityRequest_s* e;
      for (e = x->AddEntityRequest; e; e = (struct zx_ps_AddEntityRequest_s*)e->gg.g.n)
	  p = zx_ENC_SO_ps_AddEntityRequest(c, e, p);
  }
  {
      struct zx_ps_AddEntityResponse_s* e;
      for (e = x->AddEntityResponse; e; e = (struct zx_ps_AddEntityResponse_s*)e->gg.g.n)
	  p = zx_ENC_SO_ps_AddEntityResponse(c, e, p);
  }
  {
      struct zx_ps_AddKnownEntityRequest_s* e;
      for (e = x->AddKnownEntityRequest; e; e = (struct zx_ps_AddKnownEntityRequest_s*)e->gg.g.n)
	  p = zx_ENC_SO_ps_AddKnownEntityRequest(c, e, p);
  }
  {
      struct zx_ps_AddKnownEntityResponse_s* e;
      for (e = x->AddKnownEntityResponse; e; e = (struct zx_ps_AddKnownEntityResponse_s*)e->gg.g.n)
	  p = zx_ENC_SO_ps_AddKnownEntityResponse(c, e, p);
  }
  {
      struct zx_ps_AddCollectionRequest_s* e;
      for (e = x->AddCollectionRequest; e; e = (struct zx_ps_AddCollectionRequest_s*)e->gg.g.n)
	  p = zx_ENC_SO_ps_AddCollectionRequest(c, e, p);
  }
  {
      struct zx_ps_AddCollectionResponse_s* e;
      for (e = x->AddCollectionResponse; e; e = (struct zx_ps_AddCollectionResponse_s*)e->gg.g.n)
	  p = zx_ENC_SO_ps_AddCollectionResponse(c, e, p);
  }
  {
      struct zx_ps_AddToCollectionRequest_s* e;
      for (e = x->AddToCollectionRequest; e; e = (struct zx_ps_AddToCollectionRequest_s*)e->gg.g.n)
	  p = zx_ENC_SO_ps_AddToCollectionRequest(c, e, p);
  }
  {
      struct zx_ps_AddToCollectionResponse_s* e;
      for (e = x->AddToCollectionResponse; e; e = (struct zx_ps_AddToCollectionResponse_s*)e->gg.g.n)
	  p = zx_ENC_SO_ps_AddToCollectionResponse(c, e, p);
  }
  {
      struct zx_ps_RemoveEntityRequest_s* e;
      for (e = x->RemoveEntityRequest; e; e = (struct zx_ps_RemoveEntityRequest_s*)e->gg.g.n)
	  p = zx_ENC_SO_ps_RemoveEntityRequest(c, e, p);
  }
  {
      struct zx_ps_RemoveEntityResponse_s* e;
      for (e = x->RemoveEntityResponse; e; e = (struct zx_ps_RemoveEntityResponse_s*)e->gg.g.n)
	  p = zx_ENC_SO_ps_RemoveEntityResponse(c, e, p);
  }
  {
      struct zx_ps_RemoveCollectionRequest_s* e;
      for (e = x->RemoveCollectionRequest; e; e = (struct zx_ps_RemoveCollectionRequest_s*)e->gg.g.n)
	  p = zx_ENC_SO_ps_RemoveCollectionRequest(c, e, p);
  }
  {
      struct zx_ps_RemoveCollectionResponse_s* e;
      for (e = x->RemoveCollectionResponse; e; e = (struct zx_ps_RemoveCollectionResponse_s*)e->gg.g.n)
	  p = zx_ENC_SO_ps_RemoveCollectionResponse(c, e, p);
  }
  {
      struct zx_ps_RemoveFromCollectionRequest_s* e;
      for (e = x->RemoveFromCollectionRequest; e; e = (struct zx_ps_RemoveFromCollectionRequest_s*)e->gg.g.n)
	  p = zx_ENC_SO_ps_RemoveFromCollectionRequest(c, e, p);
  }
  {
      struct zx_ps_RemoveFromCollectionResponse_s* e;
      for (e = x->RemoveFromCollectionResponse; e; e = (struct zx_ps_RemoveFromCollectionResponse_s*)e->gg.g.n)
	  p = zx_ENC_SO_ps_RemoveFromCollectionResponse(c, e, p);
  }
  {
      struct zx_ps_ListMembersRequest_s* e;
      for (e = x->ListMembersRequest; e; e = (struct zx_ps_ListMembersRequest_s*)e->gg.g.n)
	  p = zx_ENC_SO_ps_ListMembersRequest(c, e, p);
  }
  {
      struct zx_ps_ListMembersResponse_s* e;
      for (e = x->ListMembersResponse; e; e = (struct zx_ps_ListMembersResponse_s*)e->gg.g.n)
	  p = zx_ENC_SO_ps_ListMembersResponse(c, e, p);
  }
  {
      struct zx_ps_QueryObjectsRequest_s* e;
      for (e = x->QueryObjectsRequest; e; e = (struct zx_ps_QueryObjectsRequest_s*)e->gg.g.n)
	  p = zx_ENC_SO_ps_QueryObjectsRequest(c, e, p);
  }
  {
      struct zx_ps_QueryObjectsResponse_s* e;
      for (e = x->QueryObjectsResponse; e; e = (struct zx_ps_QueryObjectsResponse_s*)e->gg.g.n)
	  p = zx_ENC_SO_ps_QueryObjectsResponse(c, e, p);
  }
  {
      struct zx_ps_GetObjectInfoRequest_s* e;
      for (e = x->GetObjectInfoRequest; e; e = (struct zx_ps_GetObjectInfoRequest_s*)e->gg.g.n)
	  p = zx_ENC_SO_ps_GetObjectInfoRequest(c, e, p);
  }
  {
      struct zx_ps_GetObjectInfoResponse_s* e;
      for (e = x->GetObjectInfoResponse; e; e = (struct zx_ps_GetObjectInfoResponse_s*)e->gg.g.n)
	  p = zx_ENC_SO_ps_GetObjectInfoResponse(c, e, p);
  }
  {
      struct zx_ps_SetObjectInfoRequest_s* e;
      for (e = x->SetObjectInfoRequest; e; e = (struct zx_ps_SetObjectInfoRequest_s*)e->gg.g.n)
	  p = zx_ENC_SO_ps_SetObjectInfoRequest(c, e, p);
  }
  {
      struct zx_ps_SetObjectInfoResponse_s* e;
      for (e = x->SetObjectInfoResponse; e; e = (struct zx_ps_SetObjectInfoResponse_s*)e->gg.g.n)
	  p = zx_ENC_SO_ps_SetObjectInfoResponse(c, e, p);
  }
  {
      struct zx_ps_TestMembershipRequest_s* e;
      for (e = x->TestMembershipRequest; e; e = (struct zx_ps_TestMembershipRequest_s*)e->gg.g.n)
	  p = zx_ENC_SO_ps_TestMembershipRequest(c, e, p);
  }
  {
      struct zx_ps_TestMembershipResponse_s* e;
      for (e = x->TestMembershipResponse; e; e = (struct zx_ps_TestMembershipResponse_s*)e->gg.g.n)
	  p = zx_ENC_SO_ps_TestMembershipResponse(c, e, p);
  }
  {
      struct zx_ps_ResolveIdentifierRequest_s* e;
      for (e = x->ResolveIdentifierRequest; e; e = (struct zx_ps_ResolveIdentifierRequest_s*)e->gg.g.n)
	  p = zx_ENC_SO_ps_ResolveIdentifierRequest(c, e, p);
  }
  {
      struct zx_ps_ResolveIdentifierResponse_s* e;
      for (e = x->ResolveIdentifierResponse; e; e = (struct zx_ps_ResolveIdentifierResponse_s*)e->gg.g.n)
	  p = zx_ENC_SO_ps_ResolveIdentifierResponse(c, e, p);
  }
  {
      struct zx_ps_Notify_s* e;
      for (e = x->ps_Notify; e; e = (struct zx_ps_Notify_s*)e->gg.g.n)
	  p = zx_ENC_SO_ps_Notify(c, e, p);
  }
  {
      struct zx_ps_NotifyResponse_s* e;
      for (e = x->ps_NotifyResponse; e; e = (struct zx_ps_NotifyResponse_s*)e->gg.g.n)
	  p = zx_ENC_SO_ps_NotifyResponse(c, e, p);
  }
  {
      struct zx_im_IdentityMappingRequest_s* e;
      for (e = x->IdentityMappingRequest; e; e = (struct zx_im_IdentityMappingRequest_s*)e->gg.g.n)
	  p = zx_ENC_SO_im_IdentityMappingRequest(c, e, p);
  }
  {
      struct zx_im_IdentityMappingResponse_s* e;
      for (e = x->IdentityMappingResponse; e; e = (struct zx_im_IdentityMappingResponse_s*)e->gg.g.n)
	  p = zx_ENC_SO_im_IdentityMappingResponse(c, e, p);
  }
  {
      struct zx_as_SASLRequest_s* e;
      for (e = x->SASLRequest; e; e = (struct zx_as_SASLRequest_s*)e->gg.g.n)
	  p = zx_ENC_SO_as_SASLRequest(c, e, p);
  }
  {
      struct zx_as_SASLResponse_s* e;
      for (e = x->SASLResponse; e; e = (struct zx_as_SASLResponse_s*)e->gg.g.n)
	  p = zx_ENC_SO_as_SASLResponse(c, e, p);
  }
  {
      struct zx_mm7_SubmitReq_s* e;
      for (e = x->SubmitReq; e; e = (struct zx_mm7_SubmitReq_s*)e->gg.g.n)
	  p = zx_ENC_SO_mm7_SubmitReq(c, e, p);
  }
  {
      struct zx_mm7_SubmitRsp_s* e;
      for (e = x->SubmitRsp; e; e = (struct zx_mm7_SubmitRsp_s*)e->gg.g.n)
	  p = zx_ENC_SO_mm7_SubmitRsp(c, e, p);
  }
  {
      struct zx_mm7_DeliverReq_s* e;
      for (e = x->DeliverReq; e; e = (struct zx_mm7_DeliverReq_s*)e->gg.g.n)
	  p = zx_ENC_SO_mm7_DeliverReq(c, e, p);
  }
  {
      struct zx_mm7_DeliverRsp_s* e;
      for (e = x->DeliverRsp; e; e = (struct zx_mm7_DeliverRsp_s*)e->gg.g.n)
	  p = zx_ENC_SO_mm7_DeliverRsp(c, e, p);
  }
  {
      struct zx_mm7_CancelReq_s* e;
      for (e = x->CancelReq; e; e = (struct zx_mm7_CancelReq_s*)e->gg.g.n)
	  p = zx_ENC_SO_mm7_CancelReq(c, e, p);
  }
  {
      struct zx_mm7_CancelRsp_s* e;
      for (e = x->CancelRsp; e; e = (struct zx_mm7_CancelRsp_s*)e->gg.g.n)
	  p = zx_ENC_SO_mm7_CancelRsp(c, e, p);
  }
  {
      struct zx_mm7_ReplaceReq_s* e;
      for (e = x->ReplaceReq; e; e = (struct zx_mm7_ReplaceReq_s*)e->gg.g.n)
	  p = zx_ENC_SO_mm7_ReplaceReq(c, e, p);
  }
  {
      struct zx_mm7_ReplaceRsp_s* e;
      for (e = x->ReplaceRsp; e; e = (struct zx_mm7_ReplaceRsp_s*)e->gg.g.n)
	  p = zx_ENC_SO_mm7_ReplaceRsp(c, e, p);
  }
  {
      struct zx_mm7_extendedCancelReq_s* e;
      for (e = x->extendedCancelReq; e; e = (struct zx_mm7_extendedCancelReq_s*)e->gg.g.n)
	  p = zx_ENC_SO_mm7_extendedCancelReq(c, e, p);
  }
  {
      struct zx_mm7_extendedCancelRsp_s* e;
      for (e = x->extendedCancelRsp; e; e = (struct zx_mm7_extendedCancelRsp_s*)e->gg.g.n)
	  p = zx_ENC_SO_mm7_extendedCancelRsp(c, e, p);
  }
  {
      struct zx_mm7_extendedReplaceReq_s* e;
      for (e = x->extendedReplaceReq; e; e = (struct zx_mm7_extendedReplaceReq_s*)e->gg.g.n)
	  p = zx_ENC_SO_mm7_extendedReplaceReq(c, e, p);
  }
  {
      struct zx_mm7_extendedReplaceRsp_s* e;
      for (e = x->extendedReplaceRsp; e; e = (struct zx_mm7_extendedReplaceRsp_s*)e->gg.g.n)
	  p = zx_ENC_SO_mm7_extendedReplaceRsp(c, e, p);
  }
  {
      struct zx_mm7_DeliveryReportReq_s* e;
      for (e = x->DeliveryReportReq; e; e = (struct zx_mm7_DeliveryReportReq_s*)e->gg.g.n)
	  p = zx_ENC_SO_mm7_DeliveryReportReq(c, e, p);
  }
  {
      struct zx_mm7_DeliveryReportRsp_s* e;
      for (e = x->DeliveryReportRsp; e; e = (struct zx_mm7_DeliveryReportRsp_s*)e->gg.g.n)
	  p = zx_ENC_SO_mm7_DeliveryReportRsp(c, e, p);
  }
  {
      struct zx_mm7_ReadReplyReq_s* e;
      for (e = x->ReadReplyReq; e; e = (struct zx_mm7_ReadReplyReq_s*)e->gg.g.n)
	  p = zx_ENC_SO_mm7_ReadReplyReq(c, e, p);
  }
  {
      struct zx_mm7_ReadReplyRsp_s* e;
      for (e = x->ReadReplyRsp; e; e = (struct zx_mm7_ReadReplyRsp_s*)e->gg.g.n)
	  p = zx_ENC_SO_mm7_ReadReplyRsp(c, e, p);
  }
  {
      struct zx_mm7_RSErrorRsp_s* e;
      for (e = x->RSErrorRsp; e; e = (struct zx_mm7_RSErrorRsp_s*)e->gg.g.n)
	  p = zx_ENC_SO_mm7_RSErrorRsp(c, e, p);
  }
  {
      struct zx_mm7_VASPErrorRsp_s* e;
      for (e = x->VASPErrorRsp; e; e = (struct zx_mm7_VASPErrorRsp_s*)e->gg.g.n)
	  p = zx_ENC_SO_mm7_VASPErrorRsp(c, e, p);
  }
  {
      struct zx_mm7_QueryStatusReq_s* e;
      for (e = x->QueryStatusReq; e; e = (struct zx_mm7_QueryStatusReq_s*)e->gg.g.n)
	  p = zx_ENC_SO_mm7_QueryStatusReq(c, e, p);
  }
  {
      struct zx_mm7_QueryStatusRsp_s* e;
      for (e = x->QueryStatusRsp; e; e = (struct zx_mm7_QueryStatusRsp_s*)e->gg.g.n)
	  p = zx_ENC_SO_mm7_QueryStatusRsp(c, e, p);
  }
  {
      struct zx_cb_Query_s* e;
      for (e = x->cb_Query; e; e = (struct zx_cb_Query_s*)e->gg.g.n)
	  p = zx_ENC_SO_cb_Query(c, e, p);
  }
  {
      struct zx_cb_QueryResponse_s* e;
      for (e = x->cb_QueryResponse; e; e = (struct zx_cb_QueryResponse_s*)e->gg.g.n)
	  p = zx_ENC_SO_cb_QueryResponse(c, e, p);
  }
  {
      struct zx_cb_Create_s* e;
      for (e = x->cb_Create; e; e = (struct zx_cb_Create_s*)e->gg.g.n)
	  p = zx_ENC_SO_cb_Create(c, e, p);
  }
  {
      struct zx_cb_CreateResponse_s* e;
      for (e = x->cb_CreateResponse; e; e = (struct zx_cb_CreateResponse_s*)e->gg.g.n)
	  p = zx_ENC_SO_cb_CreateResponse(c, e, p);
  }
  {
      struct zx_cb_Delete_s* e;
      for (e = x->cb_Delete; e; e = (struct zx_cb_Delete_s*)e->gg.g.n)
	  p = zx_ENC_SO_cb_Delete(c, e, p);
  }
  {
      struct zx_cb_DeleteResponse_s* e;
      for (e = x->cb_DeleteResponse; e; e = (struct zx_cb_DeleteResponse_s*)e->gg.g.n)
	  p = zx_ENC_SO_cb_DeleteResponse(c, e, p);
  }
  {
      struct zx_cb_Modify_s* e;
      for (e = x->cb_Modify; e; e = (struct zx_cb_Modify_s*)e->gg.g.n)
	  p = zx_ENC_SO_cb_Modify(c, e, p);
  }
  {
      struct zx_cb_ModifyResponse_s* e;
      for (e = x->cb_ModifyResponse; e; e = (struct zx_cb_ModifyResponse_s*)e->gg.g.n)
	  p = zx_ENC_SO_cb_ModifyResponse(c, e, p);
  }
  {
      struct zx_cb_Notify_s* e;
      for (e = x->cb_Notify; e; e = (struct zx_cb_Notify_s*)e->gg.g.n)
	  p = zx_ENC_SO_cb_Notify(c, e, p);
  }
  {
      struct zx_cb_NotifyResponse_s* e;
      for (e = x->cb_NotifyResponse; e; e = (struct zx_cb_NotifyResponse_s*)e->gg.g.n)
	  p = zx_ENC_SO_cb_NotifyResponse(c, e, p);
  }
  {
      struct zx_cb_ReportUsage_s* e;
      for (e = x->ReportUsage; e; e = (struct zx_cb_ReportUsage_s*)e->gg.g.n)
	  p = zx_ENC_SO_cb_ReportUsage(c, e, p);
  }
  {
      struct zx_cb_ReportUsageResponse_s* e;
      for (e = x->ReportUsageResponse; e; e = (struct zx_cb_ReportUsageResponse_s*)e->gg.g.n)
	  p = zx_ENC_SO_cb_ReportUsageResponse(c, e, p);
  }
  {
      struct zx_gl_Query_s* e;
      for (e = x->gl_Query; e; e = (struct zx_gl_Query_s*)e->gg.g.n)
	  p = zx_ENC_SO_gl_Query(c, e, p);
  }
  {
      struct zx_gl_QueryResponse_s* e;
      for (e = x->gl_QueryResponse; e; e = (struct zx_gl_QueryResponse_s*)e->gg.g.n)
	  p = zx_ENC_SO_gl_QueryResponse(c, e, p);
  }
  {
      struct zx_gl_Create_s* e;
      for (e = x->gl_Create; e; e = (struct zx_gl_Create_s*)e->gg.g.n)
	  p = zx_ENC_SO_gl_Create(c, e, p);
  }
  {
      struct zx_gl_CreateResponse_s* e;
      for (e = x->gl_CreateResponse; e; e = (struct zx_gl_CreateResponse_s*)e->gg.g.n)
	  p = zx_ENC_SO_gl_CreateResponse(c, e, p);
  }
  {
      struct zx_gl_Delete_s* e;
      for (e = x->gl_Delete; e; e = (struct zx_gl_Delete_s*)e->gg.g.n)
	  p = zx_ENC_SO_gl_Delete(c, e, p);
  }
  {
      struct zx_gl_DeleteResponse_s* e;
      for (e = x->gl_DeleteResponse; e; e = (struct zx_gl_DeleteResponse_s*)e->gg.g.n)
	  p = zx_ENC_SO_gl_DeleteResponse(c, e, p);
  }
  {
      struct zx_gl_Modify_s* e;
      for (e = x->gl_Modify; e; e = (struct zx_gl_Modify_s*)e->gg.g.n)
	  p = zx_ENC_SO_gl_Modify(c, e, p);
  }
  {
      struct zx_gl_ModifyResponse_s* e;
      for (e = x->gl_ModifyResponse; e; e = (struct zx_gl_ModifyResponse_s*)e->gg.g.n)
	  p = zx_ENC_SO_gl_ModifyResponse(c, e, p);
  }
  {
      struct zx_gl_Notify_s* e;
      for (e = x->gl_Notify; e; e = (struct zx_gl_Notify_s*)e->gg.g.n)
	  p = zx_ENC_SO_gl_Notify(c, e, p);
  }
  {
      struct zx_gl_NotifyResponse_s* e;
      for (e = x->gl_NotifyResponse; e; e = (struct zx_gl_NotifyResponse_s*)e->gg.g.n)
	  p = zx_ENC_SO_gl_NotifyResponse(c, e, p);
  }
  {
      struct zx_demomed_StoreObjectRequest_s* e;
      for (e = x->StoreObjectRequest; e; e = (struct zx_demomed_StoreObjectRequest_s*)e->gg.g.n)
	  p = zx_ENC_SO_demomed_StoreObjectRequest(c, e, p);
  }
  {
      struct zx_demomed_StoreObjectResponse_s* e;
      for (e = x->StoreObjectResponse; e; e = (struct zx_demomed_StoreObjectResponse_s*)e->gg.g.n)
	  p = zx_ENC_SO_demomed_StoreObjectResponse(c, e, p);
  }
  {
      struct zx_demomed_GetObjectListRequest_s* e;
      for (e = x->GetObjectListRequest; e; e = (struct zx_demomed_GetObjectListRequest_s*)e->gg.g.n)
	  p = zx_ENC_SO_demomed_GetObjectListRequest(c, e, p);
  }
  {
      struct zx_demomed_GetObjectListResponse_s* e;
      for (e = x->GetObjectListResponse; e; e = (struct zx_demomed_GetObjectListResponse_s*)e->gg.g.n)
	  p = zx_ENC_SO_demomed_GetObjectListResponse(c, e, p);
  }
  {
      struct zx_demomed_GetObjectRequest_s* e;
      for (e = x->GetObjectRequest; e; e = (struct zx_demomed_GetObjectRequest_s*)e->gg.g.n)
	  p = zx_ENC_SO_demomed_GetObjectRequest(c, e, p);
  }
  {
      struct zx_demomed_GetObjectResponse_s* e;
      for (e = x->GetObjectResponse; e; e = (struct zx_demomed_GetObjectResponse_s*)e->gg.g.n)
	  p = zx_ENC_SO_demomed_GetObjectResponse(c, e, p);
  }
  {
      struct zx_demomed_DeleteObjectRequest_s* e;
      for (e = x->DeleteObjectRequest; e; e = (struct zx_demomed_DeleteObjectRequest_s*)e->gg.g.n)
	  p = zx_ENC_SO_demomed_DeleteObjectRequest(c, e, p);
  }
  {
      struct zx_demomed_DeleteObjectResponse_s* e;
      for (e = x->DeleteObjectResponse; e; e = (struct zx_demomed_DeleteObjectResponse_s*)e->gg.g.n)
	  p = zx_ENC_SO_demomed_DeleteObjectResponse(c, e, p);
  }
  {
      struct zx_pmm_Provision_s* e;
      for (e = x->Provision; e; e = (struct zx_pmm_Provision_s*)e->gg.g.n)
	  p = zx_ENC_SO_pmm_Provision(c, e, p);
  }
  {
      struct zx_pmm_ProvisionResponse_s* e;
      for (e = x->ProvisionResponse; e; e = (struct zx_pmm_ProvisionResponse_s*)e->gg.g.n)
	  p = zx_ENC_SO_pmm_ProvisionResponse(c, e, p);
  }
  {
      struct zx_pmm_PMActivate_s* e;
      for (e = x->PMActivate; e; e = (struct zx_pmm_PMActivate_s*)e->gg.g.n)
	  p = zx_ENC_SO_pmm_PMActivate(c, e, p);
  }
  {
      struct zx_pmm_PMActivateResponse_s* e;
      for (e = x->PMActivateResponse; e; e = (struct zx_pmm_PMActivateResponse_s*)e->gg.g.n)
	  p = zx_ENC_SO_pmm_PMActivateResponse(c, e, p);
  }
  {
      struct zx_pmm_PMDeactivate_s* e;
      for (e = x->PMDeactivate; e; e = (struct zx_pmm_PMDeactivate_s*)e->gg.g.n)
	  p = zx_ENC_SO_pmm_PMDeactivate(c, e, p);
  }
  {
      struct zx_pmm_PMDeactivateResponse_s* e;
      for (e = x->PMDeactivateResponse; e; e = (struct zx_pmm_PMDeactivateResponse_s*)e->gg.g.n)
	  p = zx_ENC_SO_pmm_PMDeactivateResponse(c, e, p);
  }
  {
      struct zx_pmm_PMDelete_s* e;
      for (e = x->PMDelete; e; e = (struct zx_pmm_PMDelete_s*)e->gg.g.n)
	  p = zx_ENC_SO_pmm_PMDelete(c, e, p);
  }
  {
      struct zx_pmm_PMDeleteResponse_s* e;
      for (e = x->PMDeleteResponse; e; e = (struct zx_pmm_PMDeleteResponse_s*)e->gg.g.n)
	  p = zx_ENC_SO_pmm_PMDeleteResponse(c, e, p);
  }
  {
      struct zx_pmm_PMUpdate_s* e;
      for (e = x->PMUpdate; e; e = (struct zx_pmm_PMUpdate_s*)e->gg.g.n)
	  p = zx_ENC_SO_pmm_PMUpdate(c, e, p);
  }
  {
      struct zx_pmm_PMUpdateResponse_s* e;
      for (e = x->PMUpdateResponse; e; e = (struct zx_pmm_PMUpdateResponse_s*)e->gg.g.n)
	  p = zx_ENC_SO_pmm_PMUpdateResponse(c, e, p);
  }
  {
      struct zx_pmm_PMGetStatus_s* e;
      for (e = x->PMGetStatus; e; e = (struct zx_pmm_PMGetStatus_s*)e->gg.g.n)
	  p = zx_ENC_SO_pmm_PMGetStatus(c, e, p);
  }
  {
      struct zx_pmm_PMGetStatusResponse_s* e;
      for (e = x->PMGetStatusResponse; e; e = (struct zx_pmm_PMGetStatusResponse_s*)e->gg.g.n)
	  p = zx_ENC_SO_pmm_PMGetStatusResponse(c, e, p);
  }
  {
      struct zx_pmm_PMSetStatus_s* e;
      for (e = x->PMSetStatus; e; e = (struct zx_pmm_PMSetStatus_s*)e->gg.g.n)
	  p = zx_ENC_SO_pmm_PMSetStatus(c, e, p);
  }
  {
      struct zx_pmm_PMSetStatusResponse_s* e;
      for (e = x->PMSetStatusResponse; e; e = (struct zx_pmm_PMSetStatusResponse_s*)e->gg.g.n)
	  p = zx_ENC_SO_pmm_PMSetStatusResponse(c, e, p);
  }
  {
      struct zx_prov_PMERegister_s* e;
      for (e = x->PMERegister; e; e = (struct zx_prov_PMERegister_s*)e->gg.g.n)
	  p = zx_ENC_SO_prov_PMERegister(c, e, p);
  }
  {
      struct zx_prov_PMERegisterResponse_s* e;
      for (e = x->PMERegisterResponse; e; e = (struct zx_prov_PMERegisterResponse_s*)e->gg.g.n)
	  p = zx_ENC_SO_prov_PMERegisterResponse(c, e, p);
  }
  {
      struct zx_prov_PMEUpload_s* e;
      for (e = x->PMEUpload; e; e = (struct zx_prov_PMEUpload_s*)e->gg.g.n)
	  p = zx_ENC_SO_prov_PMEUpload(c, e, p);
  }
  {
      struct zx_prov_PMEUploadResponse_s* e;
      for (e = x->PMEUploadResponse; e; e = (struct zx_prov_PMEUploadResponse_s*)e->gg.g.n)
	  p = zx_ENC_SO_prov_PMEUploadResponse(c, e, p);
  }
  {
      struct zx_prov_PMEDownload_s* e;
      for (e = x->PMEDownload; e; e = (struct zx_prov_PMEDownload_s*)e->gg.g.n)
	  p = zx_ENC_SO_prov_PMEDownload(c, e, p);
  }
  {
      struct zx_prov_PMEDownloadResponse_s* e;
      for (e = x->PMEDownloadResponse; e; e = (struct zx_prov_PMEDownloadResponse_s*)e->gg.g.n)
	  p = zx_ENC_SO_prov_PMEDownloadResponse(c, e, p);
  }
  {
      struct zx_prov_PMEEnable_s* e;
      for (e = x->PMEEnable; e; e = (struct zx_prov_PMEEnable_s*)e->gg.g.n)
	  p = zx_ENC_SO_prov_PMEEnable(c, e, p);
  }
  {
      struct zx_prov_PMEEnableResponse_s* e;
      for (e = x->PMEEnableResponse; e; e = (struct zx_prov_PMEEnableResponse_s*)e->gg.g.n)
	  p = zx_ENC_SO_prov_PMEEnableResponse(c, e, p);
  }
  {
      struct zx_prov_PMEDisable_s* e;
      for (e = x->PMEDisable; e; e = (struct zx_prov_PMEDisable_s*)e->gg.g.n)
	  p = zx_ENC_SO_prov_PMEDisable(c, e, p);
  }
  {
      struct zx_prov_PMEDisableResponse_s* e;
      for (e = x->PMEDisableResponse; e; e = (struct zx_prov_PMEDisableResponse_s*)e->gg.g.n)
	  p = zx_ENC_SO_prov_PMEDisableResponse(c, e, p);
  }
  {
      struct zx_prov_PMEDelete_s* e;
      for (e = x->PMEDelete; e; e = (struct zx_prov_PMEDelete_s*)e->gg.g.n)
	  p = zx_ENC_SO_prov_PMEDelete(c, e, p);
  }
  {
      struct zx_prov_PMEDeleteResponse_s* e;
      for (e = x->PMEDeleteResponse; e; e = (struct zx_prov_PMEDeleteResponse_s*)e->gg.g.n)
	  p = zx_ENC_SO_prov_PMEDeleteResponse(c, e, p);
  }
  {
      struct zx_prov_PMEGetInfo_s* e;
      for (e = x->PMEGetInfo; e; e = (struct zx_prov_PMEGetInfo_s*)e->gg.g.n)
	  p = zx_ENC_SO_prov_PMEGetInfo(c, e, p);
  }
  {
      struct zx_prov_PMEGetInfoResponse_s* e;
      for (e = x->PMEGetInfoResponse; e; e = (struct zx_prov_PMEGetInfoResponse_s*)e->gg.g.n)
	  p = zx_ENC_SO_prov_PMEGetInfoResponse(c, e, p);
  }
  {
      struct zx_prov_PMGetStatus_s* e;
      for (e = x->prov_PMGetStatus; e; e = (struct zx_prov_PMGetStatus_s*)e->gg.g.n)
	  p = zx_ENC_SO_prov_PMGetStatus(c, e, p);
  }
  {
      struct zx_prov_PMGetStatusResponse_s* e;
      for (e = x->prov_PMGetStatusResponse; e; e = (struct zx_prov_PMGetStatusResponse_s*)e->gg.g.n)
	  p = zx_ENC_SO_prov_PMGetStatusResponse(c, e, p);
  }
  {
      struct zx_prov_PMSetStatus_s* e;
      for (e = x->prov_PMSetStatus; e; e = (struct zx_prov_PMSetStatus_s*)e->gg.g.n)
	  p = zx_ENC_SO_prov_PMSetStatus(c, e, p);
  }
  {
      struct zx_prov_PMSetStatusResponse_s* e;
      for (e = x->prov_PMSetStatusResponse; e; e = (struct zx_prov_PMSetStatusResponse_s*)e->gg.g.n)
	  p = zx_ENC_SO_prov_PMSetStatusResponse(c, e, p);
  }
  {
      struct zx_prov_PMGetDescriptor_s* e;
      for (e = x->PMGetDescriptor; e; e = (struct zx_prov_PMGetDescriptor_s*)e->gg.g.n)
	  p = zx_ENC_SO_prov_PMGetDescriptor(c, e, p);
  }
  {
      struct zx_prov_PMGetDescriptorResponse_s* e;
      for (e = x->PMGetDescriptorResponse; e; e = (struct zx_prov_PMGetDescriptorResponse_s*)e->gg.g.n)
	  p = zx_ENC_SO_prov_PMGetDescriptorResponse(c, e, p);
  }
  {
      struct zx_prov_PMActivate_s* e;
      for (e = x->prov_PMActivate; e; e = (struct zx_prov_PMActivate_s*)e->gg.g.n)
	  p = zx_ENC_SO_prov_PMActivate(c, e, p);
  }
  {
      struct zx_prov_PMActivateResponse_s* e;
      for (e = x->prov_PMActivateResponse; e; e = (struct zx_prov_PMActivateResponse_s*)e->gg.g.n)
	  p = zx_ENC_SO_prov_PMActivateResponse(c, e, p);
  }
  {
      struct zx_prov_PMDeactivate_s* e;
      for (e = x->prov_PMDeactivate; e; e = (struct zx_prov_PMDeactivate_s*)e->gg.g.n)
	  p = zx_ENC_SO_prov_PMDeactivate(c, e, p);
  }
  {
      struct zx_prov_PMDeactivateResponse_s* e;
      for (e = x->prov_PMDeactivateResponse; e; e = (struct zx_prov_PMDeactivateResponse_s*)e->gg.g.n)
	  p = zx_ENC_SO_prov_PMDeactivateResponse(c, e, p);
  }
  {
      struct zx_prov_PMRegisterDescriptor_s* e;
      for (e = x->PMRegisterDescriptor; e; e = (struct zx_prov_PMRegisterDescriptor_s*)e->gg.g.n)
	  p = zx_ENC_SO_prov_PMRegisterDescriptor(c, e, p);
  }
  {
      struct zx_prov_PMRegisterDescriptorResponse_s* e;
      for (e = x->PMRegisterDescriptorResponse; e; e = (struct zx_prov_PMRegisterDescriptorResponse_s*)e->gg.g.n)
	  p = zx_ENC_SO_prov_PMRegisterDescriptorResponse(c, e, p);
  }
  {
      struct zx_prov_PMUpdate_s* e;
      for (e = x->prov_PMUpdate; e; e = (struct zx_prov_PMUpdate_s*)e->gg.g.n)
	  p = zx_ENC_SO_prov_PMUpdate(c, e, p);
  }
  {
      struct zx_prov_PMUpdateResponse_s* e;
      for (e = x->prov_PMUpdateResponse; e; e = (struct zx_prov_PMUpdateResponse_s*)e->gg.g.n)
	  p = zx_ENC_SO_prov_PMUpdateResponse(c, e, p);
  }
  {
      struct zx_prov_PMDelete_s* e;
      for (e = x->prov_PMDelete; e; e = (struct zx_prov_PMDelete_s*)e->gg.g.n)
	  p = zx_ENC_SO_prov_PMDelete(c, e, p);
  }
  {
      struct zx_prov_PMDeleteResponse_s* e;
      for (e = x->prov_PMDeleteResponse; e; e = (struct zx_prov_PMDeleteResponse_s*)e->gg.g.n)
	  p = zx_ENC_SO_prov_PMDeleteResponse(c, e, p);
  }
  {
      struct zx_prov_Poll_s* e;
      for (e = x->Poll; e; e = (struct zx_prov_Poll_s*)e->gg.g.n)
	  p = zx_ENC_SO_prov_Poll(c, e, p);
  }
  {
      struct zx_prov_PollResponse_s* e;
      for (e = x->PollResponse; e; e = (struct zx_prov_PollResponse_s*)e->gg.g.n)
	  p = zx_ENC_SO_prov_PollResponse(c, e, p);
  }
  {
      struct zx_prov_UpdateEPR_s* e;
      for (e = x->UpdateEPR; e; e = (struct zx_prov_UpdateEPR_s*)e->gg.g.n)
	  p = zx_ENC_SO_prov_UpdateEPR(c, e, p);
  }
  {
      struct zx_prov_UpdateEPRResponse_s* e;
      for (e = x->UpdateEPRResponse; e; e = (struct zx_prov_UpdateEPRResponse_s*)e->gg.g.n)
	  p = zx_ENC_SO_prov_UpdateEPRResponse(c, e, p);
  }
  {
      struct zx_idp_GetAssertion_s* e;
      for (e = x->GetAssertion; e; e = (struct zx_idp_GetAssertion_s*)e->gg.g.n)
	  p = zx_ENC_SO_idp_GetAssertion(c, e, p);
  }
  {
      struct zx_idp_GetAssertionResponse_s* e;
      for (e = x->GetAssertionResponse; e; e = (struct zx_idp_GetAssertionResponse_s*)e->gg.g.n)
	  p = zx_ENC_SO_idp_GetAssertionResponse(c, e, p);
  }
  {
      struct zx_idp_GetProviderInfo_s* e;
      for (e = x->GetProviderInfo; e; e = (struct zx_idp_GetProviderInfo_s*)e->gg.g.n)
	  p = zx_ENC_SO_idp_GetProviderInfo(c, e, p);
  }
  {
      struct zx_idp_GetProviderInfoResponse_s* e;
      for (e = x->GetProviderInfoResponse; e; e = (struct zx_idp_GetProviderInfoResponse_s*)e->gg.g.n)
	  p = zx_ENC_SO_idp_GetProviderInfoResponse(c, e, p);
  }
  {
      struct zx_idp_CreatedStatus_s* e;
      for (e = x->CreatedStatus; e; e = (struct zx_idp_CreatedStatus_s*)e->gg.g.n)
	  p = zx_ENC_SO_idp_CreatedStatus(c, e, p);
  }
  {
      struct zx_idp_CreatedStatusResponse_s* e;
      for (e = x->CreatedStatusResponse; e; e = (struct zx_idp_CreatedStatusResponse_s*)e->gg.g.n)
	  p = zx_ENC_SO_idp_CreatedStatusResponse(c, e, p);
  }
  {
      struct zx_shps_Delete_s* e;
      for (e = x->shps_Delete; e; e = (struct zx_shps_Delete_s*)e->gg.g.n)
	  p = zx_ENC_SO_shps_Delete(c, e, p);
  }
  {
      struct zx_shps_DeleteResponse_s* e;
      for (e = x->shps_DeleteResponse; e; e = (struct zx_shps_DeleteResponse_s*)e->gg.g.n)
	  p = zx_ENC_SO_shps_DeleteResponse(c, e, p);
  }
  {
      struct zx_shps_GetStatus_s* e;
      for (e = x->GetStatus; e; e = (struct zx_shps_GetStatus_s*)e->gg.g.n)
	  p = zx_ENC_SO_shps_GetStatus(c, e, p);
  }
  {
      struct zx_shps_GetStatusResponse_s* e;
      for (e = x->GetStatusResponse; e; e = (struct zx_shps_GetStatusResponse_s*)e->gg.g.n)
	  p = zx_ENC_SO_shps_GetStatusResponse(c, e, p);
  }
  {
      struct zx_shps_Query_s* e;
      for (e = x->shps_Query; e; e = (struct zx_shps_Query_s*)e->gg.g.n)
	  p = zx_ENC_SO_shps_Query(c, e, p);
  }
  {
      struct zx_shps_QueryResponse_s* e;
      for (e = x->shps_QueryResponse; e; e = (struct zx_shps_QueryResponse_s*)e->gg.g.n)
	  p = zx_ENC_SO_shps_QueryResponse(c, e, p);
  }
  for (se = x->Invoke; se; se = (struct zx_elem_s*)se->g.n)
    p = zx_ENC_SO_simple_elem(c, se, p, "shps:Invoke", sizeof("shps:Invoke")-1, zx_ns_tab+zx_xmlns_ix_shps);
  {
      struct zx_shps_InvokeResponse_s* e;
      for (e = x->InvokeResponse; e; e = (struct zx_shps_InvokeResponse_s*)e->gg.g.n)
	  p = zx_ENC_SO_shps_InvokeResponse(c, e, p);
  }
  {
      struct zx_shps_QueryRegistered_s* e;
      for (e = x->QueryRegistered; e; e = (struct zx_shps_QueryRegistered_s*)e->gg.g.n)
	  p = zx_ENC_SO_shps_QueryRegistered(c, e, p);
  }
  {
      struct zx_shps_QueryRegisteredResponse_s* e;
      for (e = x->QueryRegisteredResponse; e; e = (struct zx_shps_QueryRegisteredResponse_s*)e->gg.g.n)
	  p = zx_ENC_SO_shps_QueryRegisteredResponse(c, e, p);
  }
  {
      struct zx_shps_Register_s* e;
      for (e = x->Register; e; e = (struct zx_shps_Register_s*)e->gg.g.n)
	  p = zx_ENC_SO_shps_Register(c, e, p);
  }
  {
      struct zx_shps_RegisterResponse_s* e;
      for (e = x->RegisterResponse; e; e = (struct zx_shps_RegisterResponse_s*)e->gg.g.n)
	  p = zx_ENC_SO_shps_RegisterResponse(c, e, p);
  }
  {
      struct zx_shps_SetStatus_s* e;
      for (e = x->SetStatus; e; e = (struct zx_shps_SetStatus_s*)e->gg.g.n)
	  p = zx_ENC_SO_shps_SetStatus(c, e, p);
  }
  {
      struct zx_shps_SetStatusResponse_s* e;
      for (e = x->SetStatusResponse; e; e = (struct zx_shps_SetStatusResponse_s*)e->gg.g.n)
	  p = zx_ENC_SO_shps_SetStatusResponse(c, e, p);
  }
  {
      struct zx_shps_Update_s* e;
      for (e = x->Update; e; e = (struct zx_shps_Update_s*)e->gg.g.n)
	  p = zx_ENC_SO_shps_Update(c, e, p);
  }
  {
      struct zx_shps_UpdateResponse_s* e;
      for (e = x->UpdateResponse; e; e = (struct zx_shps_UpdateResponse_s*)e->gg.g.n)
	  p = zx_ENC_SO_shps_UpdateResponse(c, e, p);
  }
  {
      struct zx_shps_Poll_s* e;
      for (e = x->shps_Poll; e; e = (struct zx_shps_Poll_s*)e->gg.g.n)
	  p = zx_ENC_SO_shps_Poll(c, e, p);
  }
  {
      struct zx_shps_PollResponse_s* e;
      for (e = x->shps_PollResponse; e; e = (struct zx_shps_PollResponse_s*)e->gg.g.n)
	  p = zx_ENC_SO_shps_PollResponse(c, e, p);
  }
  {
      struct zx_shps_ProxyInvoke_s* e;
      for (e = x->ProxyInvoke; e; e = (struct zx_shps_ProxyInvoke_s*)e->gg.g.n)
	  p = zx_ENC_SO_shps_ProxyInvoke(c, e, p);
  }
  {
      struct zx_shps_ProxyInvokeResponse_s* e;
      for (e = x->ProxyInvokeResponse; e; e = (struct zx_shps_ProxyInvokeResponse_s*)e->gg.g.n)
	  p = zx_ENC_SO_shps_ProxyInvokeResponse(c, e, p);
  }
  {
      struct zx_idhrxml_Create_s* e;
      for (e = x->idhrxml_Create; e; e = (struct zx_idhrxml_Create_s*)e->gg.g.n)
	  p = zx_ENC_SO_idhrxml_Create(c, e, p);
  }
  {
      struct zx_idhrxml_CreateResponse_s* e;
      for (e = x->idhrxml_CreateResponse; e; e = (struct zx_idhrxml_CreateResponse_s*)e->gg.g.n)
	  p = zx_ENC_SO_idhrxml_CreateResponse(c, e, p);
  }
  {
      struct zx_idhrxml_Query_s* e;
      for (e = x->idhrxml_Query; e; e = (struct zx_idhrxml_Query_s*)e->gg.g.n)
	  p = zx_ENC_SO_idhrxml_Query(c, e, p);
  }
  {
      struct zx_idhrxml_QueryResponse_s* e;
      for (e = x->idhrxml_QueryResponse; e; e = (struct zx_idhrxml_QueryResponse_s*)e->gg.g.n)
	  p = zx_ENC_SO_idhrxml_QueryResponse(c, e, p);
  }
  {
      struct zx_idhrxml_Modify_s* e;
      for (e = x->idhrxml_Modify; e; e = (struct zx_idhrxml_Modify_s*)e->gg.g.n)
	  p = zx_ENC_SO_idhrxml_Modify(c, e, p);
  }
  {
      struct zx_idhrxml_ModifyResponse_s* e;
      for (e = x->idhrxml_ModifyResponse; e; e = (struct zx_idhrxml_ModifyResponse_s*)e->gg.g.n)
	  p = zx_ENC_SO_idhrxml_ModifyResponse(c, e, p);
  }
  {
      struct zx_idhrxml_Delete_s* e;
      for (e = x->idhrxml_Delete; e; e = (struct zx_idhrxml_Delete_s*)e->gg.g.n)
	  p = zx_ENC_SO_idhrxml_Delete(c, e, p);
  }
  {
      struct zx_idhrxml_DeleteResponse_s* e;
      for (e = x->idhrxml_DeleteResponse; e; e = (struct zx_idhrxml_DeleteResponse_s*)e->gg.g.n)
	  p = zx_ENC_SO_idhrxml_DeleteResponse(c, e, p);
  }
  {
      struct zx_idhrxml_Notify_s* e;
      for (e = x->idhrxml_Notify; e; e = (struct zx_idhrxml_Notify_s*)e->gg.g.n)
	  p = zx_ENC_SO_idhrxml_Notify(c, e, p);
  }
  {
      struct zx_idhrxml_NotifyResponse_s* e;
      for (e = x->idhrxml_NotifyResponse; e; e = (struct zx_idhrxml_NotifyResponse_s*)e->gg.g.n)
	  p = zx_ENC_SO_idhrxml_NotifyResponse(c, e, p);
  }

  p = zx_enc_so_unknown_elems_and_content(c, p, &x->gg);
  
#if 1 /* NORMALMODE */
  ZX_OUT_CLOSE_TAG(p, "</e:Body>");
  zx_pop_seen(pop_seen);
#else
  /* root node has no end tag either */
#endif
  ENC_LEN_DEBUG(x, "e:Body", p-enc_base);
  return p;
}

/* FUNC(zx_ENC_WO_e_Body) */

/* Render element into string. The XML attributes and elements are
 * processed in wire order by chasing wo pointers. This is what you want for
 * validating signatures on other people's XML documents. */

/* Called by: */
char* zx_ENC_WO_e_Body(struct zx_ctx* c, struct zx_e_Body_s* x, char* p )
{
  struct zx_elem_s* kid;
  ENC_LEN_DEBUG_BASE;
#if 1 /* NORMALMODE */
  struct zx_ns_s* pop_seen = 0;
  char* q;
  char* qq;
  ZX_OUT_CH(p, '<');
  q = p;
  if (x->gg.g.ns && x->gg.g.ns->prefix_len) {
    ZX_OUT_MEM(p, x->gg.g.ns->prefix, x->gg.g.ns->prefix_len);
    ZX_OUT_CH(p, ':');
  }
  ZX_OUT_MEM(p, "Body", sizeof("Body")-1);
  qq = p;

  /* *** sort the namespaces */
  if (c->inc_ns)
    zx_add_inc_ns(c, &pop_seen);
  zx_add_xmlns_if_not_seen(c, x->gg.g.ns, &pop_seen);

  p = zx_enc_seen(p, pop_seen); 
  p = zx_attr_wo_enc(p, x->id, "id=\"", sizeof("id=\"")-1);

  p = zx_enc_unknown_attrs(p, x->gg.any_attr);
#else
  /* root node has no begin tag */
#endif
  
  for (kid = x->gg.kids; kid; kid = ((struct zx_elem_s*)(kid->g.wo)))
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
  ENC_LEN_DEBUG(x, "e:Body", p-enc_base);
  return p;
}

/* FUNC(zx_EASY_ENC_SO_e_Body) */

/* Called by: */
struct zx_str* zx_EASY_ENC_SO_e_Body(struct zx_ctx* c, struct zx_e_Body_s* x )
{
  int len;
  char* buf;
  c->ns_tab = ZX_ALLOC(c, sizeof(zx_ns_tab));
  memcpy(c->ns_tab, zx_ns_tab, sizeof(zx_ns_tab));
  len = zx_LEN_SO_e_Body(c, x );
  buf = ZX_ALLOC(c, len+1);
  return zx_easy_enc_common(c, zx_ENC_SO_e_Body(c, x, buf ), buf, len);
}

/* FUNC(zx_EASY_ENC_WO_e_Body) */

/* Called by: */
struct zx_str* zx_EASY_ENC_WO_e_Body(struct zx_ctx* c, struct zx_e_Body_s* x )
{
  int len;
  char* buf;
  c->ns_tab = ZX_ALLOC(c, sizeof(zx_ns_tab));
  memcpy(c->ns_tab, zx_ns_tab, sizeof(zx_ns_tab));
  len = zx_LEN_WO_e_Body(c, x );
  buf = ZX_ALLOC(c, len+1);
  return zx_easy_enc_common(c, zx_ENC_WO_e_Body(c, x, buf ), buf, len);
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

#define EL_NAME   e_Envelope
#define EL_STRUCT zx_e_Envelope_s
#define EL_NS     e
#define EL_TAG    Envelope

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

/* FUNC(zx_LEN_SO_e_Envelope) */

/* Compute length of an element (and its subelements). The XML attributes
 * and elements are processed in schema order. */

/* Called by: */
int zx_LEN_SO_e_Envelope(struct zx_ctx* c, struct zx_e_Envelope_s* x )
{
  struct zx_ns_s* pop_seen = 0;
  struct zx_elem_s* se MAYBE_UNUSED;
#if 1 /* NORMALMODE */
  /* *** in simple_elem case should output ns prefix from ns node. */
  int len = sizeof("<e:Envelope")-1 + 1 + sizeof("</e:Envelope>")-1;
  if (c->inc_ns_len)
    len += zx_len_inc_ns(c, &pop_seen);
  len += zx_len_xmlns_if_not_seen(c, zx_ns_tab+zx_xmlns_ix_e, &pop_seen);

  len += zx_attr_so_len(x->id, sizeof("id")-1);

#else
  /* root node has no begin tag */
  int len = 0;
#endif
  
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


  len += zx_len_so_common(c, &x->gg);
  zx_pop_seen(pop_seen);
  ENC_LEN_DEBUG(x, "e:Envelope", len);
  return len;
}

/* FUNC(zx_LEN_WO_e_Envelope) */

/* Compute length of an element (and its subelements). The XML attributes
 * and elements are processed in wire order and no assumptions
 * are made about namespace prefixes. */

/* Called by: */
int zx_LEN_WO_e_Envelope(struct zx_ctx* c, struct zx_e_Envelope_s* x )
{
  struct zx_ns_s* pop_seen = 0;
  struct zx_elem_s* se MAYBE_UNUSED;
#if 1 /* NORMALMODE */
  int len = 1 + sizeof("Envelope")-1 + 1 + 2 + sizeof("Envelope")-1 + 1;
  
  if (x->gg.g.ns && x->gg.g.ns->prefix_len)
    len += (x->gg.g.ns->prefix_len + 1) * 2;
  if (c->inc_ns_len)
    len += zx_len_inc_ns(c, &pop_seen);
  len += zx_len_xmlns_if_not_seen(c, x->gg.g.ns, &pop_seen);

  len += zx_attr_wo_len(x->id, sizeof("id")-1);

#else
  /* root node has no begin tag */
  int len = 0;
#endif
  
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


  len += zx_len_wo_common(c, &x->gg); 
  zx_pop_seen(pop_seen);
  ENC_LEN_DEBUG(x, "e:Envelope", len);
  return len;
}

/* FUNC(zx_ENC_SO_e_Envelope) */

/* Render element into string. The XML attributes and elements are
 * processed in schema order. This is what you generally want for
 * rendering new data structure to a string. The wo pointers are not used. */

/* Called by: */
char* zx_ENC_SO_e_Envelope(struct zx_ctx* c, struct zx_e_Envelope_s* x, char* p )
{
  struct zx_elem_s* se MAYBE_UNUSED;
  ENC_LEN_DEBUG_BASE;
#if 1 /* NORMALMODE */
  struct zx_ns_s* pop_seen = 0;
  /* *** in simple_elem case should output ns prefix from ns node. */
  ZX_OUT_TAG(p, "<e:Envelope");
  if (c->inc_ns)
    p = zx_enc_inc_ns(c, p, &pop_seen);
  p = zx_enc_xmlns_if_not_seen(c, p, zx_ns_tab+zx_xmlns_ix_e, &pop_seen);

  p = zx_attr_so_enc(p, x->id, " id=\"", sizeof(" id=\"")-1);

  p = zx_enc_unknown_attrs(p, x->gg.any_attr);
#else
  /* root node has no begin tag */
#endif
  
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

  p = zx_enc_so_unknown_elems_and_content(c, p, &x->gg);
  
#if 1 /* NORMALMODE */
  ZX_OUT_CLOSE_TAG(p, "</e:Envelope>");
  zx_pop_seen(pop_seen);
#else
  /* root node has no end tag either */
#endif
  ENC_LEN_DEBUG(x, "e:Envelope", p-enc_base);
  return p;
}

/* FUNC(zx_ENC_WO_e_Envelope) */

/* Render element into string. The XML attributes and elements are
 * processed in wire order by chasing wo pointers. This is what you want for
 * validating signatures on other people's XML documents. */

/* Called by: */
char* zx_ENC_WO_e_Envelope(struct zx_ctx* c, struct zx_e_Envelope_s* x, char* p )
{
  struct zx_elem_s* kid;
  ENC_LEN_DEBUG_BASE;
#if 1 /* NORMALMODE */
  struct zx_ns_s* pop_seen = 0;
  char* q;
  char* qq;
  ZX_OUT_CH(p, '<');
  q = p;
  if (x->gg.g.ns && x->gg.g.ns->prefix_len) {
    ZX_OUT_MEM(p, x->gg.g.ns->prefix, x->gg.g.ns->prefix_len);
    ZX_OUT_CH(p, ':');
  }
  ZX_OUT_MEM(p, "Envelope", sizeof("Envelope")-1);
  qq = p;

  /* *** sort the namespaces */
  if (c->inc_ns)
    zx_add_inc_ns(c, &pop_seen);
  zx_add_xmlns_if_not_seen(c, x->gg.g.ns, &pop_seen);

  p = zx_enc_seen(p, pop_seen); 
  p = zx_attr_wo_enc(p, x->id, "id=\"", sizeof("id=\"")-1);

  p = zx_enc_unknown_attrs(p, x->gg.any_attr);
#else
  /* root node has no begin tag */
#endif
  
  for (kid = x->gg.kids; kid; kid = ((struct zx_elem_s*)(kid->g.wo)))
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
  ENC_LEN_DEBUG(x, "e:Envelope", p-enc_base);
  return p;
}

/* FUNC(zx_EASY_ENC_SO_e_Envelope) */

/* Called by: */
struct zx_str* zx_EASY_ENC_SO_e_Envelope(struct zx_ctx* c, struct zx_e_Envelope_s* x )
{
  int len;
  char* buf;
  c->ns_tab = ZX_ALLOC(c, sizeof(zx_ns_tab));
  memcpy(c->ns_tab, zx_ns_tab, sizeof(zx_ns_tab));
  len = zx_LEN_SO_e_Envelope(c, x );
  buf = ZX_ALLOC(c, len+1);
  return zx_easy_enc_common(c, zx_ENC_SO_e_Envelope(c, x, buf ), buf, len);
}

/* FUNC(zx_EASY_ENC_WO_e_Envelope) */

/* Called by: */
struct zx_str* zx_EASY_ENC_WO_e_Envelope(struct zx_ctx* c, struct zx_e_Envelope_s* x )
{
  int len;
  char* buf;
  c->ns_tab = ZX_ALLOC(c, sizeof(zx_ns_tab));
  memcpy(c->ns_tab, zx_ns_tab, sizeof(zx_ns_tab));
  len = zx_LEN_WO_e_Envelope(c, x );
  buf = ZX_ALLOC(c, len+1);
  return zx_easy_enc_common(c, zx_ENC_WO_e_Envelope(c, x, buf ), buf, len);
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

#define EL_NAME   e_Fault
#define EL_STRUCT zx_e_Fault_s
#define EL_NS     e
#define EL_TAG    Fault

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

/* FUNC(zx_LEN_SO_e_Fault) */

/* Compute length of an element (and its subelements). The XML attributes
 * and elements are processed in schema order. */

/* Called by: */
int zx_LEN_SO_e_Fault(struct zx_ctx* c, struct zx_e_Fault_s* x )
{
  struct zx_ns_s* pop_seen = 0;
  struct zx_elem_s* se MAYBE_UNUSED;
#if 1 /* NORMALMODE */
  /* *** in simple_elem case should output ns prefix from ns node. */
  int len = sizeof("<e:Fault")-1 + 1 + sizeof("</e:Fault>")-1;
  if (c->inc_ns_len)
    len += zx_len_inc_ns(c, &pop_seen);
  len += zx_len_xmlns_if_not_seen(c, zx_ns_tab+zx_xmlns_ix_e, &pop_seen);


#else
  /* root node has no begin tag */
  int len = 0;
#endif
  
  for (se = x->faultcode; se; se = (struct zx_elem_s*)se->g.n)
    len += zx_LEN_SO_simple_elem(c,se, sizeof("e:faultcode")-1, zx_ns_tab+zx_xmlns_ix_e);
  for (se = x->faultstring; se; se = (struct zx_elem_s*)se->g.n)
    len += zx_LEN_SO_simple_elem(c,se, sizeof("e:faultstring")-1, zx_ns_tab+zx_xmlns_ix_e);
  for (se = x->faultactor; se; se = (struct zx_elem_s*)se->g.n)
    len += zx_LEN_SO_simple_elem(c,se, sizeof("e:faultactor")-1, zx_ns_tab+zx_xmlns_ix_e);
  {
      struct zx_e_detail_s* e;
      for (e = x->detail; e; e = (struct zx_e_detail_s*)e->gg.g.n)
	  len += zx_LEN_SO_e_detail(c, e);
  }


  len += zx_len_so_common(c, &x->gg);
  zx_pop_seen(pop_seen);
  ENC_LEN_DEBUG(x, "e:Fault", len);
  return len;
}

/* FUNC(zx_LEN_WO_e_Fault) */

/* Compute length of an element (and its subelements). The XML attributes
 * and elements are processed in wire order and no assumptions
 * are made about namespace prefixes. */

/* Called by: */
int zx_LEN_WO_e_Fault(struct zx_ctx* c, struct zx_e_Fault_s* x )
{
  struct zx_ns_s* pop_seen = 0;
  struct zx_elem_s* se MAYBE_UNUSED;
#if 1 /* NORMALMODE */
  int len = 1 + sizeof("Fault")-1 + 1 + 2 + sizeof("Fault")-1 + 1;
  
  if (x->gg.g.ns && x->gg.g.ns->prefix_len)
    len += (x->gg.g.ns->prefix_len + 1) * 2;
  if (c->inc_ns_len)
    len += zx_len_inc_ns(c, &pop_seen);
  len += zx_len_xmlns_if_not_seen(c, x->gg.g.ns, &pop_seen);


#else
  /* root node has no begin tag */
  int len = 0;
#endif
  
  for (se = x->faultcode; se; se = (struct zx_elem_s*)se->g.n)
    len += zx_LEN_WO_simple_elem(c, se, sizeof("faultcode")-1);
  for (se = x->faultstring; se; se = (struct zx_elem_s*)se->g.n)
    len += zx_LEN_WO_simple_elem(c, se, sizeof("faultstring")-1);
  for (se = x->faultactor; se; se = (struct zx_elem_s*)se->g.n)
    len += zx_LEN_WO_simple_elem(c, se, sizeof("faultactor")-1);
  {
      struct zx_e_detail_s* e;
      for (e = x->detail; e; e = (struct zx_e_detail_s*)e->gg.g.n)
	  len += zx_LEN_WO_e_detail(c, e);
  }


  len += zx_len_wo_common(c, &x->gg); 
  zx_pop_seen(pop_seen);
  ENC_LEN_DEBUG(x, "e:Fault", len);
  return len;
}

/* FUNC(zx_ENC_SO_e_Fault) */

/* Render element into string. The XML attributes and elements are
 * processed in schema order. This is what you generally want for
 * rendering new data structure to a string. The wo pointers are not used. */

/* Called by: */
char* zx_ENC_SO_e_Fault(struct zx_ctx* c, struct zx_e_Fault_s* x, char* p )
{
  struct zx_elem_s* se MAYBE_UNUSED;
  ENC_LEN_DEBUG_BASE;
#if 1 /* NORMALMODE */
  struct zx_ns_s* pop_seen = 0;
  /* *** in simple_elem case should output ns prefix from ns node. */
  ZX_OUT_TAG(p, "<e:Fault");
  if (c->inc_ns)
    p = zx_enc_inc_ns(c, p, &pop_seen);
  p = zx_enc_xmlns_if_not_seen(c, p, zx_ns_tab+zx_xmlns_ix_e, &pop_seen);


  p = zx_enc_unknown_attrs(p, x->gg.any_attr);
#else
  /* root node has no begin tag */
#endif
  
  for (se = x->faultcode; se; se = (struct zx_elem_s*)se->g.n)
    p = zx_ENC_SO_simple_elem(c, se, p, "e:faultcode", sizeof("e:faultcode")-1, zx_ns_tab+zx_xmlns_ix_e);
  for (se = x->faultstring; se; se = (struct zx_elem_s*)se->g.n)
    p = zx_ENC_SO_simple_elem(c, se, p, "e:faultstring", sizeof("e:faultstring")-1, zx_ns_tab+zx_xmlns_ix_e);
  for (se = x->faultactor; se; se = (struct zx_elem_s*)se->g.n)
    p = zx_ENC_SO_simple_elem(c, se, p, "e:faultactor", sizeof("e:faultactor")-1, zx_ns_tab+zx_xmlns_ix_e);
  {
      struct zx_e_detail_s* e;
      for (e = x->detail; e; e = (struct zx_e_detail_s*)e->gg.g.n)
	  p = zx_ENC_SO_e_detail(c, e, p);
  }

  p = zx_enc_so_unknown_elems_and_content(c, p, &x->gg);
  
#if 1 /* NORMALMODE */
  ZX_OUT_CLOSE_TAG(p, "</e:Fault>");
  zx_pop_seen(pop_seen);
#else
  /* root node has no end tag either */
#endif
  ENC_LEN_DEBUG(x, "e:Fault", p-enc_base);
  return p;
}

/* FUNC(zx_ENC_WO_e_Fault) */

/* Render element into string. The XML attributes and elements are
 * processed in wire order by chasing wo pointers. This is what you want for
 * validating signatures on other people's XML documents. */

/* Called by: */
char* zx_ENC_WO_e_Fault(struct zx_ctx* c, struct zx_e_Fault_s* x, char* p )
{
  struct zx_elem_s* kid;
  ENC_LEN_DEBUG_BASE;
#if 1 /* NORMALMODE */
  struct zx_ns_s* pop_seen = 0;
  char* q;
  char* qq;
  ZX_OUT_CH(p, '<');
  q = p;
  if (x->gg.g.ns && x->gg.g.ns->prefix_len) {
    ZX_OUT_MEM(p, x->gg.g.ns->prefix, x->gg.g.ns->prefix_len);
    ZX_OUT_CH(p, ':');
  }
  ZX_OUT_MEM(p, "Fault", sizeof("Fault")-1);
  qq = p;

  /* *** sort the namespaces */
  if (c->inc_ns)
    zx_add_inc_ns(c, &pop_seen);
  zx_add_xmlns_if_not_seen(c, x->gg.g.ns, &pop_seen);

  p = zx_enc_seen(p, pop_seen); 

  p = zx_enc_unknown_attrs(p, x->gg.any_attr);
#else
  /* root node has no begin tag */
#endif
  
  for (kid = x->gg.kids; kid; kid = ((struct zx_elem_s*)(kid->g.wo)))
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
  ENC_LEN_DEBUG(x, "e:Fault", p-enc_base);
  return p;
}

/* FUNC(zx_EASY_ENC_SO_e_Fault) */

/* Called by: */
struct zx_str* zx_EASY_ENC_SO_e_Fault(struct zx_ctx* c, struct zx_e_Fault_s* x )
{
  int len;
  char* buf;
  c->ns_tab = ZX_ALLOC(c, sizeof(zx_ns_tab));
  memcpy(c->ns_tab, zx_ns_tab, sizeof(zx_ns_tab));
  len = zx_LEN_SO_e_Fault(c, x );
  buf = ZX_ALLOC(c, len+1);
  return zx_easy_enc_common(c, zx_ENC_SO_e_Fault(c, x, buf ), buf, len);
}

/* FUNC(zx_EASY_ENC_WO_e_Fault) */

/* Called by: */
struct zx_str* zx_EASY_ENC_WO_e_Fault(struct zx_ctx* c, struct zx_e_Fault_s* x )
{
  int len;
  char* buf;
  c->ns_tab = ZX_ALLOC(c, sizeof(zx_ns_tab));
  memcpy(c->ns_tab, zx_ns_tab, sizeof(zx_ns_tab));
  len = zx_LEN_WO_e_Fault(c, x );
  buf = ZX_ALLOC(c, len+1);
  return zx_easy_enc_common(c, zx_ENC_WO_e_Fault(c, x, buf ), buf, len);
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

#define EL_NAME   e_Header
#define EL_STRUCT zx_e_Header_s
#define EL_NS     e
#define EL_TAG    Header

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

/* FUNC(zx_LEN_SO_e_Header) */

/* Compute length of an element (and its subelements). The XML attributes
 * and elements are processed in schema order. */

/* Called by: */
int zx_LEN_SO_e_Header(struct zx_ctx* c, struct zx_e_Header_s* x )
{
  struct zx_ns_s* pop_seen = 0;
  struct zx_elem_s* se MAYBE_UNUSED;
#if 1 /* NORMALMODE */
  /* *** in simple_elem case should output ns prefix from ns node. */
  int len = sizeof("<e:Header")-1 + 1 + sizeof("</e:Header>")-1;
  if (c->inc_ns_len)
    len += zx_len_inc_ns(c, &pop_seen);
  len += zx_len_xmlns_if_not_seen(c, zx_ns_tab+zx_xmlns_ix_e, &pop_seen);

  len += zx_attr_so_len(x->id, sizeof("id")-1);

#else
  /* root node has no begin tag */
  int len = 0;
#endif
  
  {
      struct zx_paos_Request_s* e;
      for (e = x->Request; e; e = (struct zx_paos_Request_s*)e->gg.g.n)
	  len += zx_LEN_SO_paos_Request(c, e);
  }
  {
      struct zx_paos_Response_s* e;
      for (e = x->Response; e; e = (struct zx_paos_Response_s*)e->gg.g.n)
	  len += zx_LEN_SO_paos_Response(c, e);
  }
  {
      struct zx_ecp_Request_s* e;
      for (e = x->ecp_Request; e; e = (struct zx_ecp_Request_s*)e->gg.g.n)
	  len += zx_LEN_SO_ecp_Request(c, e);
  }
  {
      struct zx_ecp_Response_s* e;
      for (e = x->ecp_Response; e; e = (struct zx_ecp_Response_s*)e->gg.g.n)
	  len += zx_LEN_SO_ecp_Response(c, e);
  }
  {
      struct zx_ecp_RelayState_s* e;
      for (e = x->RelayState; e; e = (struct zx_ecp_RelayState_s*)e->gg.g.n)
	  len += zx_LEN_SO_ecp_RelayState(c, e);
  }
  {
      struct zx_a_MessageID_s* e;
      for (e = x->MessageID; e; e = (struct zx_a_MessageID_s*)e->gg.g.n)
	  len += zx_LEN_SO_a_MessageID(c, e);
  }
  {
      struct zx_a_RelatesTo_s* e;
      for (e = x->RelatesTo; e; e = (struct zx_a_RelatesTo_s*)e->gg.g.n)
	  len += zx_LEN_SO_a_RelatesTo(c, e);
  }
  {
      struct zx_a_ReplyTo_s* e;
      for (e = x->ReplyTo; e; e = (struct zx_a_ReplyTo_s*)e->gg.g.n)
	  len += zx_LEN_SO_a_ReplyTo(c, e);
  }
  {
      struct zx_a_From_s* e;
      for (e = x->From; e; e = (struct zx_a_From_s*)e->gg.g.n)
	  len += zx_LEN_SO_a_From(c, e);
  }
  {
      struct zx_a_FaultTo_s* e;
      for (e = x->FaultTo; e; e = (struct zx_a_FaultTo_s*)e->gg.g.n)
	  len += zx_LEN_SO_a_FaultTo(c, e);
  }
  {
      struct zx_a_To_s* e;
      for (e = x->To; e; e = (struct zx_a_To_s*)e->gg.g.n)
	  len += zx_LEN_SO_a_To(c, e);
  }
  {
      struct zx_a_Action_s* e;
      for (e = x->Action; e; e = (struct zx_a_Action_s*)e->gg.g.n)
	  len += zx_LEN_SO_a_Action(c, e);
  }
  {
      struct zx_a_ReferenceParameters_s* e;
      for (e = x->ReferenceParameters; e; e = (struct zx_a_ReferenceParameters_s*)e->gg.g.n)
	  len += zx_LEN_SO_a_ReferenceParameters(c, e);
  }
  {
      struct zx_sbf_Framework_s* e;
      for (e = x->Framework; e; e = (struct zx_sbf_Framework_s*)e->gg.g.n)
	  len += zx_LEN_SO_sbf_Framework(c, e);
  }
  {
      struct zx_b_Framework_s* e;
      for (e = x->b_Framework; e; e = (struct zx_b_Framework_s*)e->gg.g.n)
	  len += zx_LEN_SO_b_Framework(c, e);
  }
  {
      struct zx_b_Sender_s* e;
      for (e = x->Sender; e; e = (struct zx_b_Sender_s*)e->gg.g.n)
	  len += zx_LEN_SO_b_Sender(c, e);
  }
  {
      struct zx_b_TargetIdentity_s* e;
      for (e = x->TargetIdentity; e; e = (struct zx_b_TargetIdentity_s*)e->gg.g.n)
	  len += zx_LEN_SO_b_TargetIdentity(c, e);
  }
  {
      struct zx_b_CredentialsContext_s* e;
      for (e = x->CredentialsContext; e; e = (struct zx_b_CredentialsContext_s*)e->gg.g.n)
	  len += zx_LEN_SO_b_CredentialsContext(c, e);
  }
  {
      struct zx_b_EndpointUpdate_s* e;
      for (e = x->EndpointUpdate; e; e = (struct zx_b_EndpointUpdate_s*)e->gg.g.n)
	  len += zx_LEN_SO_b_EndpointUpdate(c, e);
  }
  {
      struct zx_b_Timeout_s* e;
      for (e = x->Timeout; e; e = (struct zx_b_Timeout_s*)e->gg.g.n)
	  len += zx_LEN_SO_b_Timeout(c, e);
  }
  {
      struct zx_b_ProcessingContext_s* e;
      for (e = x->ProcessingContext; e; e = (struct zx_b_ProcessingContext_s*)e->gg.g.n)
	  len += zx_LEN_SO_b_ProcessingContext(c, e);
  }
  {
      struct zx_b_Consent_s* e;
      for (e = x->Consent; e; e = (struct zx_b_Consent_s*)e->gg.g.n)
	  len += zx_LEN_SO_b_Consent(c, e);
  }
  {
      struct zx_b_UsageDirective_s* e;
      for (e = x->UsageDirective; e; e = (struct zx_b_UsageDirective_s*)e->gg.g.n)
	  len += zx_LEN_SO_b_UsageDirective(c, e);
  }
  {
      struct zx_b_ApplicationEPR_s* e;
      for (e = x->ApplicationEPR; e; e = (struct zx_b_ApplicationEPR_s*)e->gg.g.n)
	  len += zx_LEN_SO_b_ApplicationEPR(c, e);
  }
  {
      struct zx_b_UserInteraction_s* e;
      for (e = x->UserInteraction; e; e = (struct zx_b_UserInteraction_s*)e->gg.g.n)
	  len += zx_LEN_SO_b_UserInteraction(c, e);
  }
  {
      struct zx_b_RedirectRequest_s* e;
      for (e = x->RedirectRequest; e; e = (struct zx_b_RedirectRequest_s*)e->gg.g.n)
	  len += zx_LEN_SO_b_RedirectRequest(c, e);
  }
  {
      struct zx_b12_Correlation_s* e;
      for (e = x->Correlation; e; e = (struct zx_b12_Correlation_s*)e->gg.g.n)
	  len += zx_LEN_SO_b12_Correlation(c, e);
  }
  {
      struct zx_b12_Provider_s* e;
      for (e = x->Provider; e; e = (struct zx_b12_Provider_s*)e->gg.g.n)
	  len += zx_LEN_SO_b12_Provider(c, e);
  }
  {
      struct zx_b12_ProcessingContext_s* e;
      for (e = x->b12_ProcessingContext; e; e = (struct zx_b12_ProcessingContext_s*)e->gg.g.n)
	  len += zx_LEN_SO_b12_ProcessingContext(c, e);
  }
  {
      struct zx_b12_Consent_s* e;
      for (e = x->b12_Consent; e; e = (struct zx_b12_Consent_s*)e->gg.g.n)
	  len += zx_LEN_SO_b12_Consent(c, e);
  }
  {
      struct zx_b12_UsageDirective_s* e;
      for (e = x->b12_UsageDirective; e; e = (struct zx_b12_UsageDirective_s*)e->gg.g.n)
	  len += zx_LEN_SO_b12_UsageDirective(c, e);
  }
  {
      struct zx_mm7_TransactionID_s* e;
      for (e = x->TransactionID; e; e = (struct zx_mm7_TransactionID_s*)e->gg.g.n)
	  len += zx_LEN_SO_mm7_TransactionID(c, e);
  }
  {
      struct zx_wsse_Security_s* e;
      for (e = x->Security; e; e = (struct zx_wsse_Security_s*)e->gg.g.n)
	  len += zx_LEN_SO_wsse_Security(c, e);
  }
  {
      struct zx_tas3_Status_s* e;
      for (e = x->Status; e; e = (struct zx_tas3_Status_s*)e->gg.g.n)
	  len += zx_LEN_SO_tas3_Status(c, e);
  }
  {
      struct zx_tas3_Credentials_s* e;
      for (e = x->Credentials; e; e = (struct zx_tas3_Credentials_s*)e->gg.g.n)
	  len += zx_LEN_SO_tas3_Credentials(c, e);
  }
  {
      struct zx_tas3_ESLPolicies_s* e;
      for (e = x->ESLPolicies; e; e = (struct zx_tas3_ESLPolicies_s*)e->gg.g.n)
	  len += zx_LEN_SO_tas3_ESLPolicies(c, e);
  }


  len += zx_len_so_common(c, &x->gg);
  zx_pop_seen(pop_seen);
  ENC_LEN_DEBUG(x, "e:Header", len);
  return len;
}

/* FUNC(zx_LEN_WO_e_Header) */

/* Compute length of an element (and its subelements). The XML attributes
 * and elements are processed in wire order and no assumptions
 * are made about namespace prefixes. */

/* Called by: */
int zx_LEN_WO_e_Header(struct zx_ctx* c, struct zx_e_Header_s* x )
{
  struct zx_ns_s* pop_seen = 0;
  struct zx_elem_s* se MAYBE_UNUSED;
#if 1 /* NORMALMODE */
  int len = 1 + sizeof("Header")-1 + 1 + 2 + sizeof("Header")-1 + 1;
  
  if (x->gg.g.ns && x->gg.g.ns->prefix_len)
    len += (x->gg.g.ns->prefix_len + 1) * 2;
  if (c->inc_ns_len)
    len += zx_len_inc_ns(c, &pop_seen);
  len += zx_len_xmlns_if_not_seen(c, x->gg.g.ns, &pop_seen);

  len += zx_attr_wo_len(x->id, sizeof("id")-1);

#else
  /* root node has no begin tag */
  int len = 0;
#endif
  
  {
      struct zx_paos_Request_s* e;
      for (e = x->Request; e; e = (struct zx_paos_Request_s*)e->gg.g.n)
	  len += zx_LEN_WO_paos_Request(c, e);
  }
  {
      struct zx_paos_Response_s* e;
      for (e = x->Response; e; e = (struct zx_paos_Response_s*)e->gg.g.n)
	  len += zx_LEN_WO_paos_Response(c, e);
  }
  {
      struct zx_ecp_Request_s* e;
      for (e = x->ecp_Request; e; e = (struct zx_ecp_Request_s*)e->gg.g.n)
	  len += zx_LEN_WO_ecp_Request(c, e);
  }
  {
      struct zx_ecp_Response_s* e;
      for (e = x->ecp_Response; e; e = (struct zx_ecp_Response_s*)e->gg.g.n)
	  len += zx_LEN_WO_ecp_Response(c, e);
  }
  {
      struct zx_ecp_RelayState_s* e;
      for (e = x->RelayState; e; e = (struct zx_ecp_RelayState_s*)e->gg.g.n)
	  len += zx_LEN_WO_ecp_RelayState(c, e);
  }
  {
      struct zx_a_MessageID_s* e;
      for (e = x->MessageID; e; e = (struct zx_a_MessageID_s*)e->gg.g.n)
	  len += zx_LEN_WO_a_MessageID(c, e);
  }
  {
      struct zx_a_RelatesTo_s* e;
      for (e = x->RelatesTo; e; e = (struct zx_a_RelatesTo_s*)e->gg.g.n)
	  len += zx_LEN_WO_a_RelatesTo(c, e);
  }
  {
      struct zx_a_ReplyTo_s* e;
      for (e = x->ReplyTo; e; e = (struct zx_a_ReplyTo_s*)e->gg.g.n)
	  len += zx_LEN_WO_a_ReplyTo(c, e);
  }
  {
      struct zx_a_From_s* e;
      for (e = x->From; e; e = (struct zx_a_From_s*)e->gg.g.n)
	  len += zx_LEN_WO_a_From(c, e);
  }
  {
      struct zx_a_FaultTo_s* e;
      for (e = x->FaultTo; e; e = (struct zx_a_FaultTo_s*)e->gg.g.n)
	  len += zx_LEN_WO_a_FaultTo(c, e);
  }
  {
      struct zx_a_To_s* e;
      for (e = x->To; e; e = (struct zx_a_To_s*)e->gg.g.n)
	  len += zx_LEN_WO_a_To(c, e);
  }
  {
      struct zx_a_Action_s* e;
      for (e = x->Action; e; e = (struct zx_a_Action_s*)e->gg.g.n)
	  len += zx_LEN_WO_a_Action(c, e);
  }
  {
      struct zx_a_ReferenceParameters_s* e;
      for (e = x->ReferenceParameters; e; e = (struct zx_a_ReferenceParameters_s*)e->gg.g.n)
	  len += zx_LEN_WO_a_ReferenceParameters(c, e);
  }
  {
      struct zx_sbf_Framework_s* e;
      for (e = x->Framework; e; e = (struct zx_sbf_Framework_s*)e->gg.g.n)
	  len += zx_LEN_WO_sbf_Framework(c, e);
  }
  {
      struct zx_b_Framework_s* e;
      for (e = x->b_Framework; e; e = (struct zx_b_Framework_s*)e->gg.g.n)
	  len += zx_LEN_WO_b_Framework(c, e);
  }
  {
      struct zx_b_Sender_s* e;
      for (e = x->Sender; e; e = (struct zx_b_Sender_s*)e->gg.g.n)
	  len += zx_LEN_WO_b_Sender(c, e);
  }
  {
      struct zx_b_TargetIdentity_s* e;
      for (e = x->TargetIdentity; e; e = (struct zx_b_TargetIdentity_s*)e->gg.g.n)
	  len += zx_LEN_WO_b_TargetIdentity(c, e);
  }
  {
      struct zx_b_CredentialsContext_s* e;
      for (e = x->CredentialsContext; e; e = (struct zx_b_CredentialsContext_s*)e->gg.g.n)
	  len += zx_LEN_WO_b_CredentialsContext(c, e);
  }
  {
      struct zx_b_EndpointUpdate_s* e;
      for (e = x->EndpointUpdate; e; e = (struct zx_b_EndpointUpdate_s*)e->gg.g.n)
	  len += zx_LEN_WO_b_EndpointUpdate(c, e);
  }
  {
      struct zx_b_Timeout_s* e;
      for (e = x->Timeout; e; e = (struct zx_b_Timeout_s*)e->gg.g.n)
	  len += zx_LEN_WO_b_Timeout(c, e);
  }
  {
      struct zx_b_ProcessingContext_s* e;
      for (e = x->ProcessingContext; e; e = (struct zx_b_ProcessingContext_s*)e->gg.g.n)
	  len += zx_LEN_WO_b_ProcessingContext(c, e);
  }
  {
      struct zx_b_Consent_s* e;
      for (e = x->Consent; e; e = (struct zx_b_Consent_s*)e->gg.g.n)
	  len += zx_LEN_WO_b_Consent(c, e);
  }
  {
      struct zx_b_UsageDirective_s* e;
      for (e = x->UsageDirective; e; e = (struct zx_b_UsageDirective_s*)e->gg.g.n)
	  len += zx_LEN_WO_b_UsageDirective(c, e);
  }
  {
      struct zx_b_ApplicationEPR_s* e;
      for (e = x->ApplicationEPR; e; e = (struct zx_b_ApplicationEPR_s*)e->gg.g.n)
	  len += zx_LEN_WO_b_ApplicationEPR(c, e);
  }
  {
      struct zx_b_UserInteraction_s* e;
      for (e = x->UserInteraction; e; e = (struct zx_b_UserInteraction_s*)e->gg.g.n)
	  len += zx_LEN_WO_b_UserInteraction(c, e);
  }
  {
      struct zx_b_RedirectRequest_s* e;
      for (e = x->RedirectRequest; e; e = (struct zx_b_RedirectRequest_s*)e->gg.g.n)
	  len += zx_LEN_WO_b_RedirectRequest(c, e);
  }
  {
      struct zx_b12_Correlation_s* e;
      for (e = x->Correlation; e; e = (struct zx_b12_Correlation_s*)e->gg.g.n)
	  len += zx_LEN_WO_b12_Correlation(c, e);
  }
  {
      struct zx_b12_Provider_s* e;
      for (e = x->Provider; e; e = (struct zx_b12_Provider_s*)e->gg.g.n)
	  len += zx_LEN_WO_b12_Provider(c, e);
  }
  {
      struct zx_b12_ProcessingContext_s* e;
      for (e = x->b12_ProcessingContext; e; e = (struct zx_b12_ProcessingContext_s*)e->gg.g.n)
	  len += zx_LEN_WO_b12_ProcessingContext(c, e);
  }
  {
      struct zx_b12_Consent_s* e;
      for (e = x->b12_Consent; e; e = (struct zx_b12_Consent_s*)e->gg.g.n)
	  len += zx_LEN_WO_b12_Consent(c, e);
  }
  {
      struct zx_b12_UsageDirective_s* e;
      for (e = x->b12_UsageDirective; e; e = (struct zx_b12_UsageDirective_s*)e->gg.g.n)
	  len += zx_LEN_WO_b12_UsageDirective(c, e);
  }
  {
      struct zx_mm7_TransactionID_s* e;
      for (e = x->TransactionID; e; e = (struct zx_mm7_TransactionID_s*)e->gg.g.n)
	  len += zx_LEN_WO_mm7_TransactionID(c, e);
  }
  {
      struct zx_wsse_Security_s* e;
      for (e = x->Security; e; e = (struct zx_wsse_Security_s*)e->gg.g.n)
	  len += zx_LEN_WO_wsse_Security(c, e);
  }
  {
      struct zx_tas3_Status_s* e;
      for (e = x->Status; e; e = (struct zx_tas3_Status_s*)e->gg.g.n)
	  len += zx_LEN_WO_tas3_Status(c, e);
  }
  {
      struct zx_tas3_Credentials_s* e;
      for (e = x->Credentials; e; e = (struct zx_tas3_Credentials_s*)e->gg.g.n)
	  len += zx_LEN_WO_tas3_Credentials(c, e);
  }
  {
      struct zx_tas3_ESLPolicies_s* e;
      for (e = x->ESLPolicies; e; e = (struct zx_tas3_ESLPolicies_s*)e->gg.g.n)
	  len += zx_LEN_WO_tas3_ESLPolicies(c, e);
  }


  len += zx_len_wo_common(c, &x->gg); 
  zx_pop_seen(pop_seen);
  ENC_LEN_DEBUG(x, "e:Header", len);
  return len;
}

/* FUNC(zx_ENC_SO_e_Header) */

/* Render element into string. The XML attributes and elements are
 * processed in schema order. This is what you generally want for
 * rendering new data structure to a string. The wo pointers are not used. */

/* Called by: */
char* zx_ENC_SO_e_Header(struct zx_ctx* c, struct zx_e_Header_s* x, char* p )
{
  struct zx_elem_s* se MAYBE_UNUSED;
  ENC_LEN_DEBUG_BASE;
#if 1 /* NORMALMODE */
  struct zx_ns_s* pop_seen = 0;
  /* *** in simple_elem case should output ns prefix from ns node. */
  ZX_OUT_TAG(p, "<e:Header");
  if (c->inc_ns)
    p = zx_enc_inc_ns(c, p, &pop_seen);
  p = zx_enc_xmlns_if_not_seen(c, p, zx_ns_tab+zx_xmlns_ix_e, &pop_seen);

  p = zx_attr_so_enc(p, x->id, " id=\"", sizeof(" id=\"")-1);

  p = zx_enc_unknown_attrs(p, x->gg.any_attr);
#else
  /* root node has no begin tag */
#endif
  
  {
      struct zx_paos_Request_s* e;
      for (e = x->Request; e; e = (struct zx_paos_Request_s*)e->gg.g.n)
	  p = zx_ENC_SO_paos_Request(c, e, p);
  }
  {
      struct zx_paos_Response_s* e;
      for (e = x->Response; e; e = (struct zx_paos_Response_s*)e->gg.g.n)
	  p = zx_ENC_SO_paos_Response(c, e, p);
  }
  {
      struct zx_ecp_Request_s* e;
      for (e = x->ecp_Request; e; e = (struct zx_ecp_Request_s*)e->gg.g.n)
	  p = zx_ENC_SO_ecp_Request(c, e, p);
  }
  {
      struct zx_ecp_Response_s* e;
      for (e = x->ecp_Response; e; e = (struct zx_ecp_Response_s*)e->gg.g.n)
	  p = zx_ENC_SO_ecp_Response(c, e, p);
  }
  {
      struct zx_ecp_RelayState_s* e;
      for (e = x->RelayState; e; e = (struct zx_ecp_RelayState_s*)e->gg.g.n)
	  p = zx_ENC_SO_ecp_RelayState(c, e, p);
  }
  {
      struct zx_a_MessageID_s* e;
      for (e = x->MessageID; e; e = (struct zx_a_MessageID_s*)e->gg.g.n)
	  p = zx_ENC_SO_a_MessageID(c, e, p);
  }
  {
      struct zx_a_RelatesTo_s* e;
      for (e = x->RelatesTo; e; e = (struct zx_a_RelatesTo_s*)e->gg.g.n)
	  p = zx_ENC_SO_a_RelatesTo(c, e, p);
  }
  {
      struct zx_a_ReplyTo_s* e;
      for (e = x->ReplyTo; e; e = (struct zx_a_ReplyTo_s*)e->gg.g.n)
	  p = zx_ENC_SO_a_ReplyTo(c, e, p);
  }
  {
      struct zx_a_From_s* e;
      for (e = x->From; e; e = (struct zx_a_From_s*)e->gg.g.n)
	  p = zx_ENC_SO_a_From(c, e, p);
  }
  {
      struct zx_a_FaultTo_s* e;
      for (e = x->FaultTo; e; e = (struct zx_a_FaultTo_s*)e->gg.g.n)
	  p = zx_ENC_SO_a_FaultTo(c, e, p);
  }
  {
      struct zx_a_To_s* e;
      for (e = x->To; e; e = (struct zx_a_To_s*)e->gg.g.n)
	  p = zx_ENC_SO_a_To(c, e, p);
  }
  {
      struct zx_a_Action_s* e;
      for (e = x->Action; e; e = (struct zx_a_Action_s*)e->gg.g.n)
	  p = zx_ENC_SO_a_Action(c, e, p);
  }
  {
      struct zx_a_ReferenceParameters_s* e;
      for (e = x->ReferenceParameters; e; e = (struct zx_a_ReferenceParameters_s*)e->gg.g.n)
	  p = zx_ENC_SO_a_ReferenceParameters(c, e, p);
  }
  {
      struct zx_sbf_Framework_s* e;
      for (e = x->Framework; e; e = (struct zx_sbf_Framework_s*)e->gg.g.n)
	  p = zx_ENC_SO_sbf_Framework(c, e, p);
  }
  {
      struct zx_b_Framework_s* e;
      for (e = x->b_Framework; e; e = (struct zx_b_Framework_s*)e->gg.g.n)
	  p = zx_ENC_SO_b_Framework(c, e, p);
  }
  {
      struct zx_b_Sender_s* e;
      for (e = x->Sender; e; e = (struct zx_b_Sender_s*)e->gg.g.n)
	  p = zx_ENC_SO_b_Sender(c, e, p);
  }
  {
      struct zx_b_TargetIdentity_s* e;
      for (e = x->TargetIdentity; e; e = (struct zx_b_TargetIdentity_s*)e->gg.g.n)
	  p = zx_ENC_SO_b_TargetIdentity(c, e, p);
  }
  {
      struct zx_b_CredentialsContext_s* e;
      for (e = x->CredentialsContext; e; e = (struct zx_b_CredentialsContext_s*)e->gg.g.n)
	  p = zx_ENC_SO_b_CredentialsContext(c, e, p);
  }
  {
      struct zx_b_EndpointUpdate_s* e;
      for (e = x->EndpointUpdate; e; e = (struct zx_b_EndpointUpdate_s*)e->gg.g.n)
	  p = zx_ENC_SO_b_EndpointUpdate(c, e, p);
  }
  {
      struct zx_b_Timeout_s* e;
      for (e = x->Timeout; e; e = (struct zx_b_Timeout_s*)e->gg.g.n)
	  p = zx_ENC_SO_b_Timeout(c, e, p);
  }
  {
      struct zx_b_ProcessingContext_s* e;
      for (e = x->ProcessingContext; e; e = (struct zx_b_ProcessingContext_s*)e->gg.g.n)
	  p = zx_ENC_SO_b_ProcessingContext(c, e, p);
  }
  {
      struct zx_b_Consent_s* e;
      for (e = x->Consent; e; e = (struct zx_b_Consent_s*)e->gg.g.n)
	  p = zx_ENC_SO_b_Consent(c, e, p);
  }
  {
      struct zx_b_UsageDirective_s* e;
      for (e = x->UsageDirective; e; e = (struct zx_b_UsageDirective_s*)e->gg.g.n)
	  p = zx_ENC_SO_b_UsageDirective(c, e, p);
  }
  {
      struct zx_b_ApplicationEPR_s* e;
      for (e = x->ApplicationEPR; e; e = (struct zx_b_ApplicationEPR_s*)e->gg.g.n)
	  p = zx_ENC_SO_b_ApplicationEPR(c, e, p);
  }
  {
      struct zx_b_UserInteraction_s* e;
      for (e = x->UserInteraction; e; e = (struct zx_b_UserInteraction_s*)e->gg.g.n)
	  p = zx_ENC_SO_b_UserInteraction(c, e, p);
  }
  {
      struct zx_b_RedirectRequest_s* e;
      for (e = x->RedirectRequest; e; e = (struct zx_b_RedirectRequest_s*)e->gg.g.n)
	  p = zx_ENC_SO_b_RedirectRequest(c, e, p);
  }
  {
      struct zx_b12_Correlation_s* e;
      for (e = x->Correlation; e; e = (struct zx_b12_Correlation_s*)e->gg.g.n)
	  p = zx_ENC_SO_b12_Correlation(c, e, p);
  }
  {
      struct zx_b12_Provider_s* e;
      for (e = x->Provider; e; e = (struct zx_b12_Provider_s*)e->gg.g.n)
	  p = zx_ENC_SO_b12_Provider(c, e, p);
  }
  {
      struct zx_b12_ProcessingContext_s* e;
      for (e = x->b12_ProcessingContext; e; e = (struct zx_b12_ProcessingContext_s*)e->gg.g.n)
	  p = zx_ENC_SO_b12_ProcessingContext(c, e, p);
  }
  {
      struct zx_b12_Consent_s* e;
      for (e = x->b12_Consent; e; e = (struct zx_b12_Consent_s*)e->gg.g.n)
	  p = zx_ENC_SO_b12_Consent(c, e, p);
  }
  {
      struct zx_b12_UsageDirective_s* e;
      for (e = x->b12_UsageDirective; e; e = (struct zx_b12_UsageDirective_s*)e->gg.g.n)
	  p = zx_ENC_SO_b12_UsageDirective(c, e, p);
  }
  {
      struct zx_mm7_TransactionID_s* e;
      for (e = x->TransactionID; e; e = (struct zx_mm7_TransactionID_s*)e->gg.g.n)
	  p = zx_ENC_SO_mm7_TransactionID(c, e, p);
  }
  {
      struct zx_wsse_Security_s* e;
      for (e = x->Security; e; e = (struct zx_wsse_Security_s*)e->gg.g.n)
	  p = zx_ENC_SO_wsse_Security(c, e, p);
  }
  {
      struct zx_tas3_Status_s* e;
      for (e = x->Status; e; e = (struct zx_tas3_Status_s*)e->gg.g.n)
	  p = zx_ENC_SO_tas3_Status(c, e, p);
  }
  {
      struct zx_tas3_Credentials_s* e;
      for (e = x->Credentials; e; e = (struct zx_tas3_Credentials_s*)e->gg.g.n)
	  p = zx_ENC_SO_tas3_Credentials(c, e, p);
  }
  {
      struct zx_tas3_ESLPolicies_s* e;
      for (e = x->ESLPolicies; e; e = (struct zx_tas3_ESLPolicies_s*)e->gg.g.n)
	  p = zx_ENC_SO_tas3_ESLPolicies(c, e, p);
  }

  p = zx_enc_so_unknown_elems_and_content(c, p, &x->gg);
  
#if 1 /* NORMALMODE */
  ZX_OUT_CLOSE_TAG(p, "</e:Header>");
  zx_pop_seen(pop_seen);
#else
  /* root node has no end tag either */
#endif
  ENC_LEN_DEBUG(x, "e:Header", p-enc_base);
  return p;
}

/* FUNC(zx_ENC_WO_e_Header) */

/* Render element into string. The XML attributes and elements are
 * processed in wire order by chasing wo pointers. This is what you want for
 * validating signatures on other people's XML documents. */

/* Called by: */
char* zx_ENC_WO_e_Header(struct zx_ctx* c, struct zx_e_Header_s* x, char* p )
{
  struct zx_elem_s* kid;
  ENC_LEN_DEBUG_BASE;
#if 1 /* NORMALMODE */
  struct zx_ns_s* pop_seen = 0;
  char* q;
  char* qq;
  ZX_OUT_CH(p, '<');
  q = p;
  if (x->gg.g.ns && x->gg.g.ns->prefix_len) {
    ZX_OUT_MEM(p, x->gg.g.ns->prefix, x->gg.g.ns->prefix_len);
    ZX_OUT_CH(p, ':');
  }
  ZX_OUT_MEM(p, "Header", sizeof("Header")-1);
  qq = p;

  /* *** sort the namespaces */
  if (c->inc_ns)
    zx_add_inc_ns(c, &pop_seen);
  zx_add_xmlns_if_not_seen(c, x->gg.g.ns, &pop_seen);

  p = zx_enc_seen(p, pop_seen); 
  p = zx_attr_wo_enc(p, x->id, "id=\"", sizeof("id=\"")-1);

  p = zx_enc_unknown_attrs(p, x->gg.any_attr);
#else
  /* root node has no begin tag */
#endif
  
  for (kid = x->gg.kids; kid; kid = ((struct zx_elem_s*)(kid->g.wo)))
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
  ENC_LEN_DEBUG(x, "e:Header", p-enc_base);
  return p;
}

/* FUNC(zx_EASY_ENC_SO_e_Header) */

/* Called by: */
struct zx_str* zx_EASY_ENC_SO_e_Header(struct zx_ctx* c, struct zx_e_Header_s* x )
{
  int len;
  char* buf;
  c->ns_tab = ZX_ALLOC(c, sizeof(zx_ns_tab));
  memcpy(c->ns_tab, zx_ns_tab, sizeof(zx_ns_tab));
  len = zx_LEN_SO_e_Header(c, x );
  buf = ZX_ALLOC(c, len+1);
  return zx_easy_enc_common(c, zx_ENC_SO_e_Header(c, x, buf ), buf, len);
}

/* FUNC(zx_EASY_ENC_WO_e_Header) */

/* Called by: */
struct zx_str* zx_EASY_ENC_WO_e_Header(struct zx_ctx* c, struct zx_e_Header_s* x )
{
  int len;
  char* buf;
  c->ns_tab = ZX_ALLOC(c, sizeof(zx_ns_tab));
  memcpy(c->ns_tab, zx_ns_tab, sizeof(zx_ns_tab));
  len = zx_LEN_WO_e_Header(c, x );
  buf = ZX_ALLOC(c, len+1);
  return zx_easy_enc_common(c, zx_ENC_WO_e_Header(c, x, buf ), buf, len);
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

#define EL_NAME   e_detail
#define EL_STRUCT zx_e_detail_s
#define EL_NS     e
#define EL_TAG    detail

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

/* FUNC(zx_LEN_SO_e_detail) */

/* Compute length of an element (and its subelements). The XML attributes
 * and elements are processed in schema order. */

/* Called by: */
int zx_LEN_SO_e_detail(struct zx_ctx* c, struct zx_e_detail_s* x )
{
  struct zx_ns_s* pop_seen = 0;
  struct zx_elem_s* se MAYBE_UNUSED;
#if 1 /* NORMALMODE */
  /* *** in simple_elem case should output ns prefix from ns node. */
  int len = sizeof("<e:detail")-1 + 1 + sizeof("</e:detail>")-1;
  if (c->inc_ns_len)
    len += zx_len_inc_ns(c, &pop_seen);
  len += zx_len_xmlns_if_not_seen(c, zx_ns_tab+zx_xmlns_ix_e, &pop_seen);


#else
  /* root node has no begin tag */
  int len = 0;
#endif
  
  {
      struct zx_lu_Status_s* e;
      for (e = x->Status; e; e = (struct zx_lu_Status_s*)e->gg.g.n)
	  len += zx_LEN_SO_lu_Status(c, e);
  }


  len += zx_len_so_common(c, &x->gg);
  zx_pop_seen(pop_seen);
  ENC_LEN_DEBUG(x, "e:detail", len);
  return len;
}

/* FUNC(zx_LEN_WO_e_detail) */

/* Compute length of an element (and its subelements). The XML attributes
 * and elements are processed in wire order and no assumptions
 * are made about namespace prefixes. */

/* Called by: */
int zx_LEN_WO_e_detail(struct zx_ctx* c, struct zx_e_detail_s* x )
{
  struct zx_ns_s* pop_seen = 0;
  struct zx_elem_s* se MAYBE_UNUSED;
#if 1 /* NORMALMODE */
  int len = 1 + sizeof("detail")-1 + 1 + 2 + sizeof("detail")-1 + 1;
  
  if (x->gg.g.ns && x->gg.g.ns->prefix_len)
    len += (x->gg.g.ns->prefix_len + 1) * 2;
  if (c->inc_ns_len)
    len += zx_len_inc_ns(c, &pop_seen);
  len += zx_len_xmlns_if_not_seen(c, x->gg.g.ns, &pop_seen);


#else
  /* root node has no begin tag */
  int len = 0;
#endif
  
  {
      struct zx_lu_Status_s* e;
      for (e = x->Status; e; e = (struct zx_lu_Status_s*)e->gg.g.n)
	  len += zx_LEN_WO_lu_Status(c, e);
  }


  len += zx_len_wo_common(c, &x->gg); 
  zx_pop_seen(pop_seen);
  ENC_LEN_DEBUG(x, "e:detail", len);
  return len;
}

/* FUNC(zx_ENC_SO_e_detail) */

/* Render element into string. The XML attributes and elements are
 * processed in schema order. This is what you generally want for
 * rendering new data structure to a string. The wo pointers are not used. */

/* Called by: */
char* zx_ENC_SO_e_detail(struct zx_ctx* c, struct zx_e_detail_s* x, char* p )
{
  struct zx_elem_s* se MAYBE_UNUSED;
  ENC_LEN_DEBUG_BASE;
#if 1 /* NORMALMODE */
  struct zx_ns_s* pop_seen = 0;
  /* *** in simple_elem case should output ns prefix from ns node. */
  ZX_OUT_TAG(p, "<e:detail");
  if (c->inc_ns)
    p = zx_enc_inc_ns(c, p, &pop_seen);
  p = zx_enc_xmlns_if_not_seen(c, p, zx_ns_tab+zx_xmlns_ix_e, &pop_seen);


  p = zx_enc_unknown_attrs(p, x->gg.any_attr);
#else
  /* root node has no begin tag */
#endif
  
  {
      struct zx_lu_Status_s* e;
      for (e = x->Status; e; e = (struct zx_lu_Status_s*)e->gg.g.n)
	  p = zx_ENC_SO_lu_Status(c, e, p);
  }

  p = zx_enc_so_unknown_elems_and_content(c, p, &x->gg);
  
#if 1 /* NORMALMODE */
  ZX_OUT_CLOSE_TAG(p, "</e:detail>");
  zx_pop_seen(pop_seen);
#else
  /* root node has no end tag either */
#endif
  ENC_LEN_DEBUG(x, "e:detail", p-enc_base);
  return p;
}

/* FUNC(zx_ENC_WO_e_detail) */

/* Render element into string. The XML attributes and elements are
 * processed in wire order by chasing wo pointers. This is what you want for
 * validating signatures on other people's XML documents. */

/* Called by: */
char* zx_ENC_WO_e_detail(struct zx_ctx* c, struct zx_e_detail_s* x, char* p )
{
  struct zx_elem_s* kid;
  ENC_LEN_DEBUG_BASE;
#if 1 /* NORMALMODE */
  struct zx_ns_s* pop_seen = 0;
  char* q;
  char* qq;
  ZX_OUT_CH(p, '<');
  q = p;
  if (x->gg.g.ns && x->gg.g.ns->prefix_len) {
    ZX_OUT_MEM(p, x->gg.g.ns->prefix, x->gg.g.ns->prefix_len);
    ZX_OUT_CH(p, ':');
  }
  ZX_OUT_MEM(p, "detail", sizeof("detail")-1);
  qq = p;

  /* *** sort the namespaces */
  if (c->inc_ns)
    zx_add_inc_ns(c, &pop_seen);
  zx_add_xmlns_if_not_seen(c, x->gg.g.ns, &pop_seen);

  p = zx_enc_seen(p, pop_seen); 

  p = zx_enc_unknown_attrs(p, x->gg.any_attr);
#else
  /* root node has no begin tag */
#endif
  
  for (kid = x->gg.kids; kid; kid = ((struct zx_elem_s*)(kid->g.wo)))
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
  ENC_LEN_DEBUG(x, "e:detail", p-enc_base);
  return p;
}

/* FUNC(zx_EASY_ENC_SO_e_detail) */

/* Called by: */
struct zx_str* zx_EASY_ENC_SO_e_detail(struct zx_ctx* c, struct zx_e_detail_s* x )
{
  int len;
  char* buf;
  c->ns_tab = ZX_ALLOC(c, sizeof(zx_ns_tab));
  memcpy(c->ns_tab, zx_ns_tab, sizeof(zx_ns_tab));
  len = zx_LEN_SO_e_detail(c, x );
  buf = ZX_ALLOC(c, len+1);
  return zx_easy_enc_common(c, zx_ENC_SO_e_detail(c, x, buf ), buf, len);
}

/* FUNC(zx_EASY_ENC_WO_e_detail) */

/* Called by: */
struct zx_str* zx_EASY_ENC_WO_e_detail(struct zx_ctx* c, struct zx_e_detail_s* x )
{
  int len;
  char* buf;
  c->ns_tab = ZX_ALLOC(c, sizeof(zx_ns_tab));
  memcpy(c->ns_tab, zx_ns_tab, sizeof(zx_ns_tab));
  len = zx_LEN_WO_e_detail(c, x );
  buf = ZX_ALLOC(c, len+1);
  return zx_easy_enc_common(c, zx_ENC_WO_e_detail(c, x, buf ), buf, len);
}




/* EOF -- c/zx-e-enc.c */
