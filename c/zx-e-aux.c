/* c/zx-e-aux.c - WARNING: This file was automatically generated. DO NOT EDIT!
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
#include "c/zx-e-data.h"



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

/* FUNC(zx_FREE_e_Body) */

/* Depth first traversal of data structure to free it and its subelements. Simple
 * strings are handled as a special case according to the free_strs flag. This
 * is useful if the strings point to underlying data from the wire that was
 * allocated differently. */

/* Called by: */
void zx_FREE_e_Body(struct zx_ctx* c, struct zx_e_Body_s* x, int free_strs)
{
  /* *** deal with xmlns specifications in exc c14n way */

  zx_free_attr(c, x->id, free_strs);

  {
      struct zx_sp_ArtifactResolve_s* e;
      struct zx_sp_ArtifactResolve_s* en;
      for (e = x->ArtifactResolve; e; e = en) {
	  en = (struct zx_sp_ArtifactResolve_s*)e->gg.g.n;
	  zx_FREE_sp_ArtifactResolve(c, e, free_strs);
      }
  }
  {
      struct zx_sp_ArtifactResponse_s* e;
      struct zx_sp_ArtifactResponse_s* en;
      for (e = x->ArtifactResponse; e; e = en) {
	  en = (struct zx_sp_ArtifactResponse_s*)e->gg.g.n;
	  zx_FREE_sp_ArtifactResponse(c, e, free_strs);
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
      struct zx_sp_NameIDMappingRequest_s* e;
      struct zx_sp_NameIDMappingRequest_s* en;
      for (e = x->NameIDMappingRequest; e; e = en) {
	  en = (struct zx_sp_NameIDMappingRequest_s*)e->gg.g.n;
	  zx_FREE_sp_NameIDMappingRequest(c, e, free_strs);
      }
  }
  {
      struct zx_sp_NameIDMappingResponse_s* e;
      struct zx_sp_NameIDMappingResponse_s* en;
      for (e = x->NameIDMappingResponse; e; e = en) {
	  en = (struct zx_sp_NameIDMappingResponse_s*)e->gg.g.n;
	  zx_FREE_sp_NameIDMappingResponse(c, e, free_strs);
      }
  }
  {
      struct zx_sp_AttributeQuery_s* e;
      struct zx_sp_AttributeQuery_s* en;
      for (e = x->AttributeQuery; e; e = en) {
	  en = (struct zx_sp_AttributeQuery_s*)e->gg.g.n;
	  zx_FREE_sp_AttributeQuery(c, e, free_strs);
      }
  }
  {
      struct zx_sp_AuthnQuery_s* e;
      struct zx_sp_AuthnQuery_s* en;
      for (e = x->AuthnQuery; e; e = en) {
	  en = (struct zx_sp_AuthnQuery_s*)e->gg.g.n;
	  zx_FREE_sp_AuthnQuery(c, e, free_strs);
      }
  }
  {
      struct zx_sp_AuthzDecisionQuery_s* e;
      struct zx_sp_AuthzDecisionQuery_s* en;
      for (e = x->AuthzDecisionQuery; e; e = en) {
	  en = (struct zx_sp_AuthzDecisionQuery_s*)e->gg.g.n;
	  zx_FREE_sp_AuthzDecisionQuery(c, e, free_strs);
      }
  }
  {
      struct zx_sp_AssertionIDRequest_s* e;
      struct zx_sp_AssertionIDRequest_s* en;
      for (e = x->AssertionIDRequest; e; e = en) {
	  en = (struct zx_sp_AssertionIDRequest_s*)e->gg.g.n;
	  zx_FREE_sp_AssertionIDRequest(c, e, free_strs);
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
      struct zx_sp_AuthnRequest_s* e;
      struct zx_sp_AuthnRequest_s* en;
      for (e = x->AuthnRequest; e; e = en) {
	  en = (struct zx_sp_AuthnRequest_s*)e->gg.g.n;
	  zx_FREE_sp_AuthnRequest(c, e, free_strs);
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
  {
      struct zx_xac_Request_s* e;
      struct zx_xac_Request_s* en;
      for (e = x->xac_Request; e; e = en) {
	  en = (struct zx_xac_Request_s*)e->gg.g.n;
	  zx_FREE_xac_Request(c, e, free_strs);
      }
  }
  {
      struct zx_xac_Response_s* e;
      struct zx_xac_Response_s* en;
      for (e = x->xac_Response; e; e = en) {
	  en = (struct zx_xac_Response_s*)e->gg.g.n;
	  zx_FREE_xac_Response(c, e, free_strs);
      }
  }
  {
      struct zx_di_Query_s* e;
      struct zx_di_Query_s* en;
      for (e = x->Query; e; e = en) {
	  en = (struct zx_di_Query_s*)e->gg.g.n;
	  zx_FREE_di_Query(c, e, free_strs);
      }
  }
  {
      struct zx_di_QueryResponse_s* e;
      struct zx_di_QueryResponse_s* en;
      for (e = x->QueryResponse; e; e = en) {
	  en = (struct zx_di_QueryResponse_s*)e->gg.g.n;
	  zx_FREE_di_QueryResponse(c, e, free_strs);
      }
  }
  {
      struct zx_di12_Query_s* e;
      struct zx_di12_Query_s* en;
      for (e = x->di12_Query; e; e = en) {
	  en = (struct zx_di12_Query_s*)e->gg.g.n;
	  zx_FREE_di12_Query(c, e, free_strs);
      }
  }
  {
      struct zx_di12_QueryResponse_s* e;
      struct zx_di12_QueryResponse_s* en;
      for (e = x->di12_QueryResponse; e; e = en) {
	  en = (struct zx_di12_QueryResponse_s*)e->gg.g.n;
	  zx_FREE_di12_QueryResponse(c, e, free_strs);
      }
  }
  {
      struct zx_di12_Modify_s* e;
      struct zx_di12_Modify_s* en;
      for (e = x->Modify; e; e = en) {
	  en = (struct zx_di12_Modify_s*)e->gg.g.n;
	  zx_FREE_di12_Modify(c, e, free_strs);
      }
  }
  {
      struct zx_di12_ModifyResponse_s* e;
      struct zx_di12_ModifyResponse_s* en;
      for (e = x->ModifyResponse; e; e = en) {
	  en = (struct zx_di12_ModifyResponse_s*)e->gg.g.n;
	  zx_FREE_di12_ModifyResponse(c, e, free_strs);
      }
  }
  {
      struct zx_e_Fault_s* e;
      struct zx_e_Fault_s* en;
      for (e = x->Fault; e; e = en) {
	  en = (struct zx_e_Fault_s*)e->gg.g.n;
	  zx_FREE_e_Fault(c, e, free_strs);
      }
  }
  {
      struct zx_di_SvcMDAssociationAdd_s* e;
      struct zx_di_SvcMDAssociationAdd_s* en;
      for (e = x->SvcMDAssociationAdd; e; e = en) {
	  en = (struct zx_di_SvcMDAssociationAdd_s*)e->gg.g.n;
	  zx_FREE_di_SvcMDAssociationAdd(c, e, free_strs);
      }
  }
  {
      struct zx_di_SvcMDAssociationAddResponse_s* e;
      struct zx_di_SvcMDAssociationAddResponse_s* en;
      for (e = x->SvcMDAssociationAddResponse; e; e = en) {
	  en = (struct zx_di_SvcMDAssociationAddResponse_s*)e->gg.g.n;
	  zx_FREE_di_SvcMDAssociationAddResponse(c, e, free_strs);
      }
  }
  {
      struct zx_di_SvcMDAssociationDelete_s* e;
      struct zx_di_SvcMDAssociationDelete_s* en;
      for (e = x->SvcMDAssociationDelete; e; e = en) {
	  en = (struct zx_di_SvcMDAssociationDelete_s*)e->gg.g.n;
	  zx_FREE_di_SvcMDAssociationDelete(c, e, free_strs);
      }
  }
  {
      struct zx_di_SvcMDAssociationDeleteResponse_s* e;
      struct zx_di_SvcMDAssociationDeleteResponse_s* en;
      for (e = x->SvcMDAssociationDeleteResponse; e; e = en) {
	  en = (struct zx_di_SvcMDAssociationDeleteResponse_s*)e->gg.g.n;
	  zx_FREE_di_SvcMDAssociationDeleteResponse(c, e, free_strs);
      }
  }
  {
      struct zx_di_SvcMDAssociationQuery_s* e;
      struct zx_di_SvcMDAssociationQuery_s* en;
      for (e = x->SvcMDAssociationQuery; e; e = en) {
	  en = (struct zx_di_SvcMDAssociationQuery_s*)e->gg.g.n;
	  zx_FREE_di_SvcMDAssociationQuery(c, e, free_strs);
      }
  }
  {
      struct zx_di_SvcMDAssociationQueryResponse_s* e;
      struct zx_di_SvcMDAssociationQueryResponse_s* en;
      for (e = x->SvcMDAssociationQueryResponse; e; e = en) {
	  en = (struct zx_di_SvcMDAssociationQueryResponse_s*)e->gg.g.n;
	  zx_FREE_di_SvcMDAssociationQueryResponse(c, e, free_strs);
      }
  }
  {
      struct zx_di_SvcMDRegister_s* e;
      struct zx_di_SvcMDRegister_s* en;
      for (e = x->SvcMDRegister; e; e = en) {
	  en = (struct zx_di_SvcMDRegister_s*)e->gg.g.n;
	  zx_FREE_di_SvcMDRegister(c, e, free_strs);
      }
  }
  {
      struct zx_di_SvcMDRegisterResponse_s* e;
      struct zx_di_SvcMDRegisterResponse_s* en;
      for (e = x->SvcMDRegisterResponse; e; e = en) {
	  en = (struct zx_di_SvcMDRegisterResponse_s*)e->gg.g.n;
	  zx_FREE_di_SvcMDRegisterResponse(c, e, free_strs);
      }
  }
  {
      struct zx_di_SvcMDDelete_s* e;
      struct zx_di_SvcMDDelete_s* en;
      for (e = x->SvcMDDelete; e; e = en) {
	  en = (struct zx_di_SvcMDDelete_s*)e->gg.g.n;
	  zx_FREE_di_SvcMDDelete(c, e, free_strs);
      }
  }
  {
      struct zx_di_SvcMDDeleteResponse_s* e;
      struct zx_di_SvcMDDeleteResponse_s* en;
      for (e = x->SvcMDDeleteResponse; e; e = en) {
	  en = (struct zx_di_SvcMDDeleteResponse_s*)e->gg.g.n;
	  zx_FREE_di_SvcMDDeleteResponse(c, e, free_strs);
      }
  }
  {
      struct zx_di_SvcMDQuery_s* e;
      struct zx_di_SvcMDQuery_s* en;
      for (e = x->SvcMDQuery; e; e = en) {
	  en = (struct zx_di_SvcMDQuery_s*)e->gg.g.n;
	  zx_FREE_di_SvcMDQuery(c, e, free_strs);
      }
  }
  {
      struct zx_di_SvcMDQueryResponse_s* e;
      struct zx_di_SvcMDQueryResponse_s* en;
      for (e = x->SvcMDQueryResponse; e; e = en) {
	  en = (struct zx_di_SvcMDQueryResponse_s*)e->gg.g.n;
	  zx_FREE_di_SvcMDQueryResponse(c, e, free_strs);
      }
  }
  {
      struct zx_di_SvcMDReplace_s* e;
      struct zx_di_SvcMDReplace_s* en;
      for (e = x->SvcMDReplace; e; e = en) {
	  en = (struct zx_di_SvcMDReplace_s*)e->gg.g.n;
	  zx_FREE_di_SvcMDReplace(c, e, free_strs);
      }
  }
  {
      struct zx_di_SvcMDReplaceResponse_s* e;
      struct zx_di_SvcMDReplaceResponse_s* en;
      for (e = x->SvcMDReplaceResponse; e; e = en) {
	  en = (struct zx_di_SvcMDReplaceResponse_s*)e->gg.g.n;
	  zx_FREE_di_SvcMDReplaceResponse(c, e, free_strs);
      }
  }
  {
      struct zx_dap_Create_s* e;
      struct zx_dap_Create_s* en;
      for (e = x->Create; e; e = en) {
	  en = (struct zx_dap_Create_s*)e->gg.g.n;
	  zx_FREE_dap_Create(c, e, free_strs);
      }
  }
  {
      struct zx_dap_CreateResponse_s* e;
      struct zx_dap_CreateResponse_s* en;
      for (e = x->CreateResponse; e; e = en) {
	  en = (struct zx_dap_CreateResponse_s*)e->gg.g.n;
	  zx_FREE_dap_CreateResponse(c, e, free_strs);
      }
  }
  {
      struct zx_dap_Query_s* e;
      struct zx_dap_Query_s* en;
      for (e = x->dap_Query; e; e = en) {
	  en = (struct zx_dap_Query_s*)e->gg.g.n;
	  zx_FREE_dap_Query(c, e, free_strs);
      }
  }
  {
      struct zx_dap_QueryResponse_s* e;
      struct zx_dap_QueryResponse_s* en;
      for (e = x->dap_QueryResponse; e; e = en) {
	  en = (struct zx_dap_QueryResponse_s*)e->gg.g.n;
	  zx_FREE_dap_QueryResponse(c, e, free_strs);
      }
  }
  {
      struct zx_dap_Modify_s* e;
      struct zx_dap_Modify_s* en;
      for (e = x->dap_Modify; e; e = en) {
	  en = (struct zx_dap_Modify_s*)e->gg.g.n;
	  zx_FREE_dap_Modify(c, e, free_strs);
      }
  }
  {
      struct zx_dap_ModifyResponse_s* e;
      struct zx_dap_ModifyResponse_s* en;
      for (e = x->dap_ModifyResponse; e; e = en) {
	  en = (struct zx_dap_ModifyResponse_s*)e->gg.g.n;
	  zx_FREE_dap_ModifyResponse(c, e, free_strs);
      }
  }
  {
      struct zx_dap_Delete_s* e;
      struct zx_dap_Delete_s* en;
      for (e = x->Delete; e; e = en) {
	  en = (struct zx_dap_Delete_s*)e->gg.g.n;
	  zx_FREE_dap_Delete(c, e, free_strs);
      }
  }
  {
      struct zx_dap_DeleteResponse_s* e;
      struct zx_dap_DeleteResponse_s* en;
      for (e = x->DeleteResponse; e; e = en) {
	  en = (struct zx_dap_DeleteResponse_s*)e->gg.g.n;
	  zx_FREE_dap_DeleteResponse(c, e, free_strs);
      }
  }
  {
      struct zx_dap_Notify_s* e;
      struct zx_dap_Notify_s* en;
      for (e = x->Notify; e; e = en) {
	  en = (struct zx_dap_Notify_s*)e->gg.g.n;
	  zx_FREE_dap_Notify(c, e, free_strs);
      }
  }
  {
      struct zx_dap_NotifyResponse_s* e;
      struct zx_dap_NotifyResponse_s* en;
      for (e = x->NotifyResponse; e; e = en) {
	  en = (struct zx_dap_NotifyResponse_s*)e->gg.g.n;
	  zx_FREE_dap_NotifyResponse(c, e, free_strs);
      }
  }
  {
      struct zx_ps_AddEntityRequest_s* e;
      struct zx_ps_AddEntityRequest_s* en;
      for (e = x->AddEntityRequest; e; e = en) {
	  en = (struct zx_ps_AddEntityRequest_s*)e->gg.g.n;
	  zx_FREE_ps_AddEntityRequest(c, e, free_strs);
      }
  }
  {
      struct zx_ps_AddEntityResponse_s* e;
      struct zx_ps_AddEntityResponse_s* en;
      for (e = x->AddEntityResponse; e; e = en) {
	  en = (struct zx_ps_AddEntityResponse_s*)e->gg.g.n;
	  zx_FREE_ps_AddEntityResponse(c, e, free_strs);
      }
  }
  {
      struct zx_ps_AddKnownEntityRequest_s* e;
      struct zx_ps_AddKnownEntityRequest_s* en;
      for (e = x->AddKnownEntityRequest; e; e = en) {
	  en = (struct zx_ps_AddKnownEntityRequest_s*)e->gg.g.n;
	  zx_FREE_ps_AddKnownEntityRequest(c, e, free_strs);
      }
  }
  {
      struct zx_ps_AddKnownEntityResponse_s* e;
      struct zx_ps_AddKnownEntityResponse_s* en;
      for (e = x->AddKnownEntityResponse; e; e = en) {
	  en = (struct zx_ps_AddKnownEntityResponse_s*)e->gg.g.n;
	  zx_FREE_ps_AddKnownEntityResponse(c, e, free_strs);
      }
  }
  {
      struct zx_ps_AddCollectionRequest_s* e;
      struct zx_ps_AddCollectionRequest_s* en;
      for (e = x->AddCollectionRequest; e; e = en) {
	  en = (struct zx_ps_AddCollectionRequest_s*)e->gg.g.n;
	  zx_FREE_ps_AddCollectionRequest(c, e, free_strs);
      }
  }
  {
      struct zx_ps_AddCollectionResponse_s* e;
      struct zx_ps_AddCollectionResponse_s* en;
      for (e = x->AddCollectionResponse; e; e = en) {
	  en = (struct zx_ps_AddCollectionResponse_s*)e->gg.g.n;
	  zx_FREE_ps_AddCollectionResponse(c, e, free_strs);
      }
  }
  {
      struct zx_ps_AddToCollectionRequest_s* e;
      struct zx_ps_AddToCollectionRequest_s* en;
      for (e = x->AddToCollectionRequest; e; e = en) {
	  en = (struct zx_ps_AddToCollectionRequest_s*)e->gg.g.n;
	  zx_FREE_ps_AddToCollectionRequest(c, e, free_strs);
      }
  }
  {
      struct zx_ps_AddToCollectionResponse_s* e;
      struct zx_ps_AddToCollectionResponse_s* en;
      for (e = x->AddToCollectionResponse; e; e = en) {
	  en = (struct zx_ps_AddToCollectionResponse_s*)e->gg.g.n;
	  zx_FREE_ps_AddToCollectionResponse(c, e, free_strs);
      }
  }
  {
      struct zx_ps_RemoveEntityRequest_s* e;
      struct zx_ps_RemoveEntityRequest_s* en;
      for (e = x->RemoveEntityRequest; e; e = en) {
	  en = (struct zx_ps_RemoveEntityRequest_s*)e->gg.g.n;
	  zx_FREE_ps_RemoveEntityRequest(c, e, free_strs);
      }
  }
  {
      struct zx_ps_RemoveEntityResponse_s* e;
      struct zx_ps_RemoveEntityResponse_s* en;
      for (e = x->RemoveEntityResponse; e; e = en) {
	  en = (struct zx_ps_RemoveEntityResponse_s*)e->gg.g.n;
	  zx_FREE_ps_RemoveEntityResponse(c, e, free_strs);
      }
  }
  {
      struct zx_ps_RemoveCollectionRequest_s* e;
      struct zx_ps_RemoveCollectionRequest_s* en;
      for (e = x->RemoveCollectionRequest; e; e = en) {
	  en = (struct zx_ps_RemoveCollectionRequest_s*)e->gg.g.n;
	  zx_FREE_ps_RemoveCollectionRequest(c, e, free_strs);
      }
  }
  {
      struct zx_ps_RemoveCollectionResponse_s* e;
      struct zx_ps_RemoveCollectionResponse_s* en;
      for (e = x->RemoveCollectionResponse; e; e = en) {
	  en = (struct zx_ps_RemoveCollectionResponse_s*)e->gg.g.n;
	  zx_FREE_ps_RemoveCollectionResponse(c, e, free_strs);
      }
  }
  {
      struct zx_ps_RemoveFromCollectionRequest_s* e;
      struct zx_ps_RemoveFromCollectionRequest_s* en;
      for (e = x->RemoveFromCollectionRequest; e; e = en) {
	  en = (struct zx_ps_RemoveFromCollectionRequest_s*)e->gg.g.n;
	  zx_FREE_ps_RemoveFromCollectionRequest(c, e, free_strs);
      }
  }
  {
      struct zx_ps_RemoveFromCollectionResponse_s* e;
      struct zx_ps_RemoveFromCollectionResponse_s* en;
      for (e = x->RemoveFromCollectionResponse; e; e = en) {
	  en = (struct zx_ps_RemoveFromCollectionResponse_s*)e->gg.g.n;
	  zx_FREE_ps_RemoveFromCollectionResponse(c, e, free_strs);
      }
  }
  {
      struct zx_ps_ListMembersRequest_s* e;
      struct zx_ps_ListMembersRequest_s* en;
      for (e = x->ListMembersRequest; e; e = en) {
	  en = (struct zx_ps_ListMembersRequest_s*)e->gg.g.n;
	  zx_FREE_ps_ListMembersRequest(c, e, free_strs);
      }
  }
  {
      struct zx_ps_ListMembersResponse_s* e;
      struct zx_ps_ListMembersResponse_s* en;
      for (e = x->ListMembersResponse; e; e = en) {
	  en = (struct zx_ps_ListMembersResponse_s*)e->gg.g.n;
	  zx_FREE_ps_ListMembersResponse(c, e, free_strs);
      }
  }
  {
      struct zx_ps_QueryObjectsRequest_s* e;
      struct zx_ps_QueryObjectsRequest_s* en;
      for (e = x->QueryObjectsRequest; e; e = en) {
	  en = (struct zx_ps_QueryObjectsRequest_s*)e->gg.g.n;
	  zx_FREE_ps_QueryObjectsRequest(c, e, free_strs);
      }
  }
  {
      struct zx_ps_QueryObjectsResponse_s* e;
      struct zx_ps_QueryObjectsResponse_s* en;
      for (e = x->QueryObjectsResponse; e; e = en) {
	  en = (struct zx_ps_QueryObjectsResponse_s*)e->gg.g.n;
	  zx_FREE_ps_QueryObjectsResponse(c, e, free_strs);
      }
  }
  {
      struct zx_ps_GetObjectInfoRequest_s* e;
      struct zx_ps_GetObjectInfoRequest_s* en;
      for (e = x->GetObjectInfoRequest; e; e = en) {
	  en = (struct zx_ps_GetObjectInfoRequest_s*)e->gg.g.n;
	  zx_FREE_ps_GetObjectInfoRequest(c, e, free_strs);
      }
  }
  {
      struct zx_ps_GetObjectInfoResponse_s* e;
      struct zx_ps_GetObjectInfoResponse_s* en;
      for (e = x->GetObjectInfoResponse; e; e = en) {
	  en = (struct zx_ps_GetObjectInfoResponse_s*)e->gg.g.n;
	  zx_FREE_ps_GetObjectInfoResponse(c, e, free_strs);
      }
  }
  {
      struct zx_ps_SetObjectInfoRequest_s* e;
      struct zx_ps_SetObjectInfoRequest_s* en;
      for (e = x->SetObjectInfoRequest; e; e = en) {
	  en = (struct zx_ps_SetObjectInfoRequest_s*)e->gg.g.n;
	  zx_FREE_ps_SetObjectInfoRequest(c, e, free_strs);
      }
  }
  {
      struct zx_ps_SetObjectInfoResponse_s* e;
      struct zx_ps_SetObjectInfoResponse_s* en;
      for (e = x->SetObjectInfoResponse; e; e = en) {
	  en = (struct zx_ps_SetObjectInfoResponse_s*)e->gg.g.n;
	  zx_FREE_ps_SetObjectInfoResponse(c, e, free_strs);
      }
  }
  {
      struct zx_ps_TestMembershipRequest_s* e;
      struct zx_ps_TestMembershipRequest_s* en;
      for (e = x->TestMembershipRequest; e; e = en) {
	  en = (struct zx_ps_TestMembershipRequest_s*)e->gg.g.n;
	  zx_FREE_ps_TestMembershipRequest(c, e, free_strs);
      }
  }
  {
      struct zx_ps_TestMembershipResponse_s* e;
      struct zx_ps_TestMembershipResponse_s* en;
      for (e = x->TestMembershipResponse; e; e = en) {
	  en = (struct zx_ps_TestMembershipResponse_s*)e->gg.g.n;
	  zx_FREE_ps_TestMembershipResponse(c, e, free_strs);
      }
  }
  {
      struct zx_ps_ResolveIdentifierRequest_s* e;
      struct zx_ps_ResolveIdentifierRequest_s* en;
      for (e = x->ResolveIdentifierRequest; e; e = en) {
	  en = (struct zx_ps_ResolveIdentifierRequest_s*)e->gg.g.n;
	  zx_FREE_ps_ResolveIdentifierRequest(c, e, free_strs);
      }
  }
  {
      struct zx_ps_ResolveIdentifierResponse_s* e;
      struct zx_ps_ResolveIdentifierResponse_s* en;
      for (e = x->ResolveIdentifierResponse; e; e = en) {
	  en = (struct zx_ps_ResolveIdentifierResponse_s*)e->gg.g.n;
	  zx_FREE_ps_ResolveIdentifierResponse(c, e, free_strs);
      }
  }
  {
      struct zx_ps_Notify_s* e;
      struct zx_ps_Notify_s* en;
      for (e = x->ps_Notify; e; e = en) {
	  en = (struct zx_ps_Notify_s*)e->gg.g.n;
	  zx_FREE_ps_Notify(c, e, free_strs);
      }
  }
  {
      struct zx_ps_NotifyResponse_s* e;
      struct zx_ps_NotifyResponse_s* en;
      for (e = x->ps_NotifyResponse; e; e = en) {
	  en = (struct zx_ps_NotifyResponse_s*)e->gg.g.n;
	  zx_FREE_ps_NotifyResponse(c, e, free_strs);
      }
  }
  {
      struct zx_im_IdentityMappingRequest_s* e;
      struct zx_im_IdentityMappingRequest_s* en;
      for (e = x->IdentityMappingRequest; e; e = en) {
	  en = (struct zx_im_IdentityMappingRequest_s*)e->gg.g.n;
	  zx_FREE_im_IdentityMappingRequest(c, e, free_strs);
      }
  }
  {
      struct zx_im_IdentityMappingResponse_s* e;
      struct zx_im_IdentityMappingResponse_s* en;
      for (e = x->IdentityMappingResponse; e; e = en) {
	  en = (struct zx_im_IdentityMappingResponse_s*)e->gg.g.n;
	  zx_FREE_im_IdentityMappingResponse(c, e, free_strs);
      }
  }
  {
      struct zx_as_SASLRequest_s* e;
      struct zx_as_SASLRequest_s* en;
      for (e = x->SASLRequest; e; e = en) {
	  en = (struct zx_as_SASLRequest_s*)e->gg.g.n;
	  zx_FREE_as_SASLRequest(c, e, free_strs);
      }
  }
  {
      struct zx_as_SASLResponse_s* e;
      struct zx_as_SASLResponse_s* en;
      for (e = x->SASLResponse; e; e = en) {
	  en = (struct zx_as_SASLResponse_s*)e->gg.g.n;
	  zx_FREE_as_SASLResponse(c, e, free_strs);
      }
  }
  {
      struct zx_mm7_SubmitReq_s* e;
      struct zx_mm7_SubmitReq_s* en;
      for (e = x->SubmitReq; e; e = en) {
	  en = (struct zx_mm7_SubmitReq_s*)e->gg.g.n;
	  zx_FREE_mm7_SubmitReq(c, e, free_strs);
      }
  }
  {
      struct zx_mm7_SubmitRsp_s* e;
      struct zx_mm7_SubmitRsp_s* en;
      for (e = x->SubmitRsp; e; e = en) {
	  en = (struct zx_mm7_SubmitRsp_s*)e->gg.g.n;
	  zx_FREE_mm7_SubmitRsp(c, e, free_strs);
      }
  }
  {
      struct zx_mm7_DeliverReq_s* e;
      struct zx_mm7_DeliverReq_s* en;
      for (e = x->DeliverReq; e; e = en) {
	  en = (struct zx_mm7_DeliverReq_s*)e->gg.g.n;
	  zx_FREE_mm7_DeliverReq(c, e, free_strs);
      }
  }
  {
      struct zx_mm7_DeliverRsp_s* e;
      struct zx_mm7_DeliverRsp_s* en;
      for (e = x->DeliverRsp; e; e = en) {
	  en = (struct zx_mm7_DeliverRsp_s*)e->gg.g.n;
	  zx_FREE_mm7_DeliverRsp(c, e, free_strs);
      }
  }
  {
      struct zx_mm7_CancelReq_s* e;
      struct zx_mm7_CancelReq_s* en;
      for (e = x->CancelReq; e; e = en) {
	  en = (struct zx_mm7_CancelReq_s*)e->gg.g.n;
	  zx_FREE_mm7_CancelReq(c, e, free_strs);
      }
  }
  {
      struct zx_mm7_CancelRsp_s* e;
      struct zx_mm7_CancelRsp_s* en;
      for (e = x->CancelRsp; e; e = en) {
	  en = (struct zx_mm7_CancelRsp_s*)e->gg.g.n;
	  zx_FREE_mm7_CancelRsp(c, e, free_strs);
      }
  }
  {
      struct zx_mm7_ReplaceReq_s* e;
      struct zx_mm7_ReplaceReq_s* en;
      for (e = x->ReplaceReq; e; e = en) {
	  en = (struct zx_mm7_ReplaceReq_s*)e->gg.g.n;
	  zx_FREE_mm7_ReplaceReq(c, e, free_strs);
      }
  }
  {
      struct zx_mm7_ReplaceRsp_s* e;
      struct zx_mm7_ReplaceRsp_s* en;
      for (e = x->ReplaceRsp; e; e = en) {
	  en = (struct zx_mm7_ReplaceRsp_s*)e->gg.g.n;
	  zx_FREE_mm7_ReplaceRsp(c, e, free_strs);
      }
  }
  {
      struct zx_mm7_extendedCancelReq_s* e;
      struct zx_mm7_extendedCancelReq_s* en;
      for (e = x->extendedCancelReq; e; e = en) {
	  en = (struct zx_mm7_extendedCancelReq_s*)e->gg.g.n;
	  zx_FREE_mm7_extendedCancelReq(c, e, free_strs);
      }
  }
  {
      struct zx_mm7_extendedCancelRsp_s* e;
      struct zx_mm7_extendedCancelRsp_s* en;
      for (e = x->extendedCancelRsp; e; e = en) {
	  en = (struct zx_mm7_extendedCancelRsp_s*)e->gg.g.n;
	  zx_FREE_mm7_extendedCancelRsp(c, e, free_strs);
      }
  }
  {
      struct zx_mm7_extendedReplaceReq_s* e;
      struct zx_mm7_extendedReplaceReq_s* en;
      for (e = x->extendedReplaceReq; e; e = en) {
	  en = (struct zx_mm7_extendedReplaceReq_s*)e->gg.g.n;
	  zx_FREE_mm7_extendedReplaceReq(c, e, free_strs);
      }
  }
  {
      struct zx_mm7_extendedReplaceRsp_s* e;
      struct zx_mm7_extendedReplaceRsp_s* en;
      for (e = x->extendedReplaceRsp; e; e = en) {
	  en = (struct zx_mm7_extendedReplaceRsp_s*)e->gg.g.n;
	  zx_FREE_mm7_extendedReplaceRsp(c, e, free_strs);
      }
  }
  {
      struct zx_mm7_DeliveryReportReq_s* e;
      struct zx_mm7_DeliveryReportReq_s* en;
      for (e = x->DeliveryReportReq; e; e = en) {
	  en = (struct zx_mm7_DeliveryReportReq_s*)e->gg.g.n;
	  zx_FREE_mm7_DeliveryReportReq(c, e, free_strs);
      }
  }
  {
      struct zx_mm7_DeliveryReportRsp_s* e;
      struct zx_mm7_DeliveryReportRsp_s* en;
      for (e = x->DeliveryReportRsp; e; e = en) {
	  en = (struct zx_mm7_DeliveryReportRsp_s*)e->gg.g.n;
	  zx_FREE_mm7_DeliveryReportRsp(c, e, free_strs);
      }
  }
  {
      struct zx_mm7_ReadReplyReq_s* e;
      struct zx_mm7_ReadReplyReq_s* en;
      for (e = x->ReadReplyReq; e; e = en) {
	  en = (struct zx_mm7_ReadReplyReq_s*)e->gg.g.n;
	  zx_FREE_mm7_ReadReplyReq(c, e, free_strs);
      }
  }
  {
      struct zx_mm7_ReadReplyRsp_s* e;
      struct zx_mm7_ReadReplyRsp_s* en;
      for (e = x->ReadReplyRsp; e; e = en) {
	  en = (struct zx_mm7_ReadReplyRsp_s*)e->gg.g.n;
	  zx_FREE_mm7_ReadReplyRsp(c, e, free_strs);
      }
  }
  {
      struct zx_mm7_RSErrorRsp_s* e;
      struct zx_mm7_RSErrorRsp_s* en;
      for (e = x->RSErrorRsp; e; e = en) {
	  en = (struct zx_mm7_RSErrorRsp_s*)e->gg.g.n;
	  zx_FREE_mm7_RSErrorRsp(c, e, free_strs);
      }
  }
  {
      struct zx_mm7_VASPErrorRsp_s* e;
      struct zx_mm7_VASPErrorRsp_s* en;
      for (e = x->VASPErrorRsp; e; e = en) {
	  en = (struct zx_mm7_VASPErrorRsp_s*)e->gg.g.n;
	  zx_FREE_mm7_VASPErrorRsp(c, e, free_strs);
      }
  }
  {
      struct zx_mm7_QueryStatusReq_s* e;
      struct zx_mm7_QueryStatusReq_s* en;
      for (e = x->QueryStatusReq; e; e = en) {
	  en = (struct zx_mm7_QueryStatusReq_s*)e->gg.g.n;
	  zx_FREE_mm7_QueryStatusReq(c, e, free_strs);
      }
  }
  {
      struct zx_mm7_QueryStatusRsp_s* e;
      struct zx_mm7_QueryStatusRsp_s* en;
      for (e = x->QueryStatusRsp; e; e = en) {
	  en = (struct zx_mm7_QueryStatusRsp_s*)e->gg.g.n;
	  zx_FREE_mm7_QueryStatusRsp(c, e, free_strs);
      }
  }
  {
      struct zx_cb_Query_s* e;
      struct zx_cb_Query_s* en;
      for (e = x->cb_Query; e; e = en) {
	  en = (struct zx_cb_Query_s*)e->gg.g.n;
	  zx_FREE_cb_Query(c, e, free_strs);
      }
  }
  {
      struct zx_cb_QueryResponse_s* e;
      struct zx_cb_QueryResponse_s* en;
      for (e = x->cb_QueryResponse; e; e = en) {
	  en = (struct zx_cb_QueryResponse_s*)e->gg.g.n;
	  zx_FREE_cb_QueryResponse(c, e, free_strs);
      }
  }
  {
      struct zx_cb_Create_s* e;
      struct zx_cb_Create_s* en;
      for (e = x->cb_Create; e; e = en) {
	  en = (struct zx_cb_Create_s*)e->gg.g.n;
	  zx_FREE_cb_Create(c, e, free_strs);
      }
  }
  {
      struct zx_cb_CreateResponse_s* e;
      struct zx_cb_CreateResponse_s* en;
      for (e = x->cb_CreateResponse; e; e = en) {
	  en = (struct zx_cb_CreateResponse_s*)e->gg.g.n;
	  zx_FREE_cb_CreateResponse(c, e, free_strs);
      }
  }
  {
      struct zx_cb_Delete_s* e;
      struct zx_cb_Delete_s* en;
      for (e = x->cb_Delete; e; e = en) {
	  en = (struct zx_cb_Delete_s*)e->gg.g.n;
	  zx_FREE_cb_Delete(c, e, free_strs);
      }
  }
  {
      struct zx_cb_DeleteResponse_s* e;
      struct zx_cb_DeleteResponse_s* en;
      for (e = x->cb_DeleteResponse; e; e = en) {
	  en = (struct zx_cb_DeleteResponse_s*)e->gg.g.n;
	  zx_FREE_cb_DeleteResponse(c, e, free_strs);
      }
  }
  {
      struct zx_cb_Modify_s* e;
      struct zx_cb_Modify_s* en;
      for (e = x->cb_Modify; e; e = en) {
	  en = (struct zx_cb_Modify_s*)e->gg.g.n;
	  zx_FREE_cb_Modify(c, e, free_strs);
      }
  }
  {
      struct zx_cb_ModifyResponse_s* e;
      struct zx_cb_ModifyResponse_s* en;
      for (e = x->cb_ModifyResponse; e; e = en) {
	  en = (struct zx_cb_ModifyResponse_s*)e->gg.g.n;
	  zx_FREE_cb_ModifyResponse(c, e, free_strs);
      }
  }
  {
      struct zx_cb_Notify_s* e;
      struct zx_cb_Notify_s* en;
      for (e = x->cb_Notify; e; e = en) {
	  en = (struct zx_cb_Notify_s*)e->gg.g.n;
	  zx_FREE_cb_Notify(c, e, free_strs);
      }
  }
  {
      struct zx_cb_NotifyResponse_s* e;
      struct zx_cb_NotifyResponse_s* en;
      for (e = x->cb_NotifyResponse; e; e = en) {
	  en = (struct zx_cb_NotifyResponse_s*)e->gg.g.n;
	  zx_FREE_cb_NotifyResponse(c, e, free_strs);
      }
  }
  {
      struct zx_cb_ReportUsage_s* e;
      struct zx_cb_ReportUsage_s* en;
      for (e = x->ReportUsage; e; e = en) {
	  en = (struct zx_cb_ReportUsage_s*)e->gg.g.n;
	  zx_FREE_cb_ReportUsage(c, e, free_strs);
      }
  }
  {
      struct zx_cb_ReportUsageResponse_s* e;
      struct zx_cb_ReportUsageResponse_s* en;
      for (e = x->ReportUsageResponse; e; e = en) {
	  en = (struct zx_cb_ReportUsageResponse_s*)e->gg.g.n;
	  zx_FREE_cb_ReportUsageResponse(c, e, free_strs);
      }
  }
  {
      struct zx_gl_Query_s* e;
      struct zx_gl_Query_s* en;
      for (e = x->gl_Query; e; e = en) {
	  en = (struct zx_gl_Query_s*)e->gg.g.n;
	  zx_FREE_gl_Query(c, e, free_strs);
      }
  }
  {
      struct zx_gl_QueryResponse_s* e;
      struct zx_gl_QueryResponse_s* en;
      for (e = x->gl_QueryResponse; e; e = en) {
	  en = (struct zx_gl_QueryResponse_s*)e->gg.g.n;
	  zx_FREE_gl_QueryResponse(c, e, free_strs);
      }
  }
  {
      struct zx_gl_Create_s* e;
      struct zx_gl_Create_s* en;
      for (e = x->gl_Create; e; e = en) {
	  en = (struct zx_gl_Create_s*)e->gg.g.n;
	  zx_FREE_gl_Create(c, e, free_strs);
      }
  }
  {
      struct zx_gl_CreateResponse_s* e;
      struct zx_gl_CreateResponse_s* en;
      for (e = x->gl_CreateResponse; e; e = en) {
	  en = (struct zx_gl_CreateResponse_s*)e->gg.g.n;
	  zx_FREE_gl_CreateResponse(c, e, free_strs);
      }
  }
  {
      struct zx_gl_Delete_s* e;
      struct zx_gl_Delete_s* en;
      for (e = x->gl_Delete; e; e = en) {
	  en = (struct zx_gl_Delete_s*)e->gg.g.n;
	  zx_FREE_gl_Delete(c, e, free_strs);
      }
  }
  {
      struct zx_gl_DeleteResponse_s* e;
      struct zx_gl_DeleteResponse_s* en;
      for (e = x->gl_DeleteResponse; e; e = en) {
	  en = (struct zx_gl_DeleteResponse_s*)e->gg.g.n;
	  zx_FREE_gl_DeleteResponse(c, e, free_strs);
      }
  }
  {
      struct zx_gl_Modify_s* e;
      struct zx_gl_Modify_s* en;
      for (e = x->gl_Modify; e; e = en) {
	  en = (struct zx_gl_Modify_s*)e->gg.g.n;
	  zx_FREE_gl_Modify(c, e, free_strs);
      }
  }
  {
      struct zx_gl_ModifyResponse_s* e;
      struct zx_gl_ModifyResponse_s* en;
      for (e = x->gl_ModifyResponse; e; e = en) {
	  en = (struct zx_gl_ModifyResponse_s*)e->gg.g.n;
	  zx_FREE_gl_ModifyResponse(c, e, free_strs);
      }
  }
  {
      struct zx_gl_Notify_s* e;
      struct zx_gl_Notify_s* en;
      for (e = x->gl_Notify; e; e = en) {
	  en = (struct zx_gl_Notify_s*)e->gg.g.n;
	  zx_FREE_gl_Notify(c, e, free_strs);
      }
  }
  {
      struct zx_gl_NotifyResponse_s* e;
      struct zx_gl_NotifyResponse_s* en;
      for (e = x->gl_NotifyResponse; e; e = en) {
	  en = (struct zx_gl_NotifyResponse_s*)e->gg.g.n;
	  zx_FREE_gl_NotifyResponse(c, e, free_strs);
      }
  }
  {
      struct zx_demomed_StoreObjectRequest_s* e;
      struct zx_demomed_StoreObjectRequest_s* en;
      for (e = x->StoreObjectRequest; e; e = en) {
	  en = (struct zx_demomed_StoreObjectRequest_s*)e->gg.g.n;
	  zx_FREE_demomed_StoreObjectRequest(c, e, free_strs);
      }
  }
  {
      struct zx_demomed_StoreObjectResponse_s* e;
      struct zx_demomed_StoreObjectResponse_s* en;
      for (e = x->StoreObjectResponse; e; e = en) {
	  en = (struct zx_demomed_StoreObjectResponse_s*)e->gg.g.n;
	  zx_FREE_demomed_StoreObjectResponse(c, e, free_strs);
      }
  }
  {
      struct zx_demomed_GetObjectListRequest_s* e;
      struct zx_demomed_GetObjectListRequest_s* en;
      for (e = x->GetObjectListRequest; e; e = en) {
	  en = (struct zx_demomed_GetObjectListRequest_s*)e->gg.g.n;
	  zx_FREE_demomed_GetObjectListRequest(c, e, free_strs);
      }
  }
  {
      struct zx_demomed_GetObjectListResponse_s* e;
      struct zx_demomed_GetObjectListResponse_s* en;
      for (e = x->GetObjectListResponse; e; e = en) {
	  en = (struct zx_demomed_GetObjectListResponse_s*)e->gg.g.n;
	  zx_FREE_demomed_GetObjectListResponse(c, e, free_strs);
      }
  }
  {
      struct zx_demomed_GetObjectRequest_s* e;
      struct zx_demomed_GetObjectRequest_s* en;
      for (e = x->GetObjectRequest; e; e = en) {
	  en = (struct zx_demomed_GetObjectRequest_s*)e->gg.g.n;
	  zx_FREE_demomed_GetObjectRequest(c, e, free_strs);
      }
  }
  {
      struct zx_demomed_GetObjectResponse_s* e;
      struct zx_demomed_GetObjectResponse_s* en;
      for (e = x->GetObjectResponse; e; e = en) {
	  en = (struct zx_demomed_GetObjectResponse_s*)e->gg.g.n;
	  zx_FREE_demomed_GetObjectResponse(c, e, free_strs);
      }
  }
  {
      struct zx_demomed_DeleteObjectRequest_s* e;
      struct zx_demomed_DeleteObjectRequest_s* en;
      for (e = x->DeleteObjectRequest; e; e = en) {
	  en = (struct zx_demomed_DeleteObjectRequest_s*)e->gg.g.n;
	  zx_FREE_demomed_DeleteObjectRequest(c, e, free_strs);
      }
  }
  {
      struct zx_demomed_DeleteObjectResponse_s* e;
      struct zx_demomed_DeleteObjectResponse_s* en;
      for (e = x->DeleteObjectResponse; e; e = en) {
	  en = (struct zx_demomed_DeleteObjectResponse_s*)e->gg.g.n;
	  zx_FREE_demomed_DeleteObjectResponse(c, e, free_strs);
      }
  }
  {
      struct zx_pmm_Provision_s* e;
      struct zx_pmm_Provision_s* en;
      for (e = x->Provision; e; e = en) {
	  en = (struct zx_pmm_Provision_s*)e->gg.g.n;
	  zx_FREE_pmm_Provision(c, e, free_strs);
      }
  }
  {
      struct zx_pmm_ProvisionResponse_s* e;
      struct zx_pmm_ProvisionResponse_s* en;
      for (e = x->ProvisionResponse; e; e = en) {
	  en = (struct zx_pmm_ProvisionResponse_s*)e->gg.g.n;
	  zx_FREE_pmm_ProvisionResponse(c, e, free_strs);
      }
  }
  {
      struct zx_pmm_PMActivate_s* e;
      struct zx_pmm_PMActivate_s* en;
      for (e = x->PMActivate; e; e = en) {
	  en = (struct zx_pmm_PMActivate_s*)e->gg.g.n;
	  zx_FREE_pmm_PMActivate(c, e, free_strs);
      }
  }
  {
      struct zx_pmm_PMActivateResponse_s* e;
      struct zx_pmm_PMActivateResponse_s* en;
      for (e = x->PMActivateResponse; e; e = en) {
	  en = (struct zx_pmm_PMActivateResponse_s*)e->gg.g.n;
	  zx_FREE_pmm_PMActivateResponse(c, e, free_strs);
      }
  }
  {
      struct zx_pmm_PMDeactivate_s* e;
      struct zx_pmm_PMDeactivate_s* en;
      for (e = x->PMDeactivate; e; e = en) {
	  en = (struct zx_pmm_PMDeactivate_s*)e->gg.g.n;
	  zx_FREE_pmm_PMDeactivate(c, e, free_strs);
      }
  }
  {
      struct zx_pmm_PMDeactivateResponse_s* e;
      struct zx_pmm_PMDeactivateResponse_s* en;
      for (e = x->PMDeactivateResponse; e; e = en) {
	  en = (struct zx_pmm_PMDeactivateResponse_s*)e->gg.g.n;
	  zx_FREE_pmm_PMDeactivateResponse(c, e, free_strs);
      }
  }
  {
      struct zx_pmm_PMDelete_s* e;
      struct zx_pmm_PMDelete_s* en;
      for (e = x->PMDelete; e; e = en) {
	  en = (struct zx_pmm_PMDelete_s*)e->gg.g.n;
	  zx_FREE_pmm_PMDelete(c, e, free_strs);
      }
  }
  {
      struct zx_pmm_PMDeleteResponse_s* e;
      struct zx_pmm_PMDeleteResponse_s* en;
      for (e = x->PMDeleteResponse; e; e = en) {
	  en = (struct zx_pmm_PMDeleteResponse_s*)e->gg.g.n;
	  zx_FREE_pmm_PMDeleteResponse(c, e, free_strs);
      }
  }
  {
      struct zx_pmm_PMUpdate_s* e;
      struct zx_pmm_PMUpdate_s* en;
      for (e = x->PMUpdate; e; e = en) {
	  en = (struct zx_pmm_PMUpdate_s*)e->gg.g.n;
	  zx_FREE_pmm_PMUpdate(c, e, free_strs);
      }
  }
  {
      struct zx_pmm_PMUpdateResponse_s* e;
      struct zx_pmm_PMUpdateResponse_s* en;
      for (e = x->PMUpdateResponse; e; e = en) {
	  en = (struct zx_pmm_PMUpdateResponse_s*)e->gg.g.n;
	  zx_FREE_pmm_PMUpdateResponse(c, e, free_strs);
      }
  }
  {
      struct zx_pmm_PMGetStatus_s* e;
      struct zx_pmm_PMGetStatus_s* en;
      for (e = x->PMGetStatus; e; e = en) {
	  en = (struct zx_pmm_PMGetStatus_s*)e->gg.g.n;
	  zx_FREE_pmm_PMGetStatus(c, e, free_strs);
      }
  }
  {
      struct zx_pmm_PMGetStatusResponse_s* e;
      struct zx_pmm_PMGetStatusResponse_s* en;
      for (e = x->PMGetStatusResponse; e; e = en) {
	  en = (struct zx_pmm_PMGetStatusResponse_s*)e->gg.g.n;
	  zx_FREE_pmm_PMGetStatusResponse(c, e, free_strs);
      }
  }
  {
      struct zx_pmm_PMSetStatus_s* e;
      struct zx_pmm_PMSetStatus_s* en;
      for (e = x->PMSetStatus; e; e = en) {
	  en = (struct zx_pmm_PMSetStatus_s*)e->gg.g.n;
	  zx_FREE_pmm_PMSetStatus(c, e, free_strs);
      }
  }
  {
      struct zx_pmm_PMSetStatusResponse_s* e;
      struct zx_pmm_PMSetStatusResponse_s* en;
      for (e = x->PMSetStatusResponse; e; e = en) {
	  en = (struct zx_pmm_PMSetStatusResponse_s*)e->gg.g.n;
	  zx_FREE_pmm_PMSetStatusResponse(c, e, free_strs);
      }
  }
  {
      struct zx_prov_PMERegister_s* e;
      struct zx_prov_PMERegister_s* en;
      for (e = x->PMERegister; e; e = en) {
	  en = (struct zx_prov_PMERegister_s*)e->gg.g.n;
	  zx_FREE_prov_PMERegister(c, e, free_strs);
      }
  }
  {
      struct zx_prov_PMERegisterResponse_s* e;
      struct zx_prov_PMERegisterResponse_s* en;
      for (e = x->PMERegisterResponse; e; e = en) {
	  en = (struct zx_prov_PMERegisterResponse_s*)e->gg.g.n;
	  zx_FREE_prov_PMERegisterResponse(c, e, free_strs);
      }
  }
  {
      struct zx_prov_PMEUpload_s* e;
      struct zx_prov_PMEUpload_s* en;
      for (e = x->PMEUpload; e; e = en) {
	  en = (struct zx_prov_PMEUpload_s*)e->gg.g.n;
	  zx_FREE_prov_PMEUpload(c, e, free_strs);
      }
  }
  {
      struct zx_prov_PMEUploadResponse_s* e;
      struct zx_prov_PMEUploadResponse_s* en;
      for (e = x->PMEUploadResponse; e; e = en) {
	  en = (struct zx_prov_PMEUploadResponse_s*)e->gg.g.n;
	  zx_FREE_prov_PMEUploadResponse(c, e, free_strs);
      }
  }
  {
      struct zx_prov_PMEDownload_s* e;
      struct zx_prov_PMEDownload_s* en;
      for (e = x->PMEDownload; e; e = en) {
	  en = (struct zx_prov_PMEDownload_s*)e->gg.g.n;
	  zx_FREE_prov_PMEDownload(c, e, free_strs);
      }
  }
  {
      struct zx_prov_PMEDownloadResponse_s* e;
      struct zx_prov_PMEDownloadResponse_s* en;
      for (e = x->PMEDownloadResponse; e; e = en) {
	  en = (struct zx_prov_PMEDownloadResponse_s*)e->gg.g.n;
	  zx_FREE_prov_PMEDownloadResponse(c, e, free_strs);
      }
  }
  {
      struct zx_prov_PMEEnable_s* e;
      struct zx_prov_PMEEnable_s* en;
      for (e = x->PMEEnable; e; e = en) {
	  en = (struct zx_prov_PMEEnable_s*)e->gg.g.n;
	  zx_FREE_prov_PMEEnable(c, e, free_strs);
      }
  }
  {
      struct zx_prov_PMEEnableResponse_s* e;
      struct zx_prov_PMEEnableResponse_s* en;
      for (e = x->PMEEnableResponse; e; e = en) {
	  en = (struct zx_prov_PMEEnableResponse_s*)e->gg.g.n;
	  zx_FREE_prov_PMEEnableResponse(c, e, free_strs);
      }
  }
  {
      struct zx_prov_PMEDisable_s* e;
      struct zx_prov_PMEDisable_s* en;
      for (e = x->PMEDisable; e; e = en) {
	  en = (struct zx_prov_PMEDisable_s*)e->gg.g.n;
	  zx_FREE_prov_PMEDisable(c, e, free_strs);
      }
  }
  {
      struct zx_prov_PMEDisableResponse_s* e;
      struct zx_prov_PMEDisableResponse_s* en;
      for (e = x->PMEDisableResponse; e; e = en) {
	  en = (struct zx_prov_PMEDisableResponse_s*)e->gg.g.n;
	  zx_FREE_prov_PMEDisableResponse(c, e, free_strs);
      }
  }
  {
      struct zx_prov_PMEDelete_s* e;
      struct zx_prov_PMEDelete_s* en;
      for (e = x->PMEDelete; e; e = en) {
	  en = (struct zx_prov_PMEDelete_s*)e->gg.g.n;
	  zx_FREE_prov_PMEDelete(c, e, free_strs);
      }
  }
  {
      struct zx_prov_PMEDeleteResponse_s* e;
      struct zx_prov_PMEDeleteResponse_s* en;
      for (e = x->PMEDeleteResponse; e; e = en) {
	  en = (struct zx_prov_PMEDeleteResponse_s*)e->gg.g.n;
	  zx_FREE_prov_PMEDeleteResponse(c, e, free_strs);
      }
  }
  {
      struct zx_prov_PMEGetInfo_s* e;
      struct zx_prov_PMEGetInfo_s* en;
      for (e = x->PMEGetInfo; e; e = en) {
	  en = (struct zx_prov_PMEGetInfo_s*)e->gg.g.n;
	  zx_FREE_prov_PMEGetInfo(c, e, free_strs);
      }
  }
  {
      struct zx_prov_PMEGetInfoResponse_s* e;
      struct zx_prov_PMEGetInfoResponse_s* en;
      for (e = x->PMEGetInfoResponse; e; e = en) {
	  en = (struct zx_prov_PMEGetInfoResponse_s*)e->gg.g.n;
	  zx_FREE_prov_PMEGetInfoResponse(c, e, free_strs);
      }
  }
  {
      struct zx_prov_PMGetStatus_s* e;
      struct zx_prov_PMGetStatus_s* en;
      for (e = x->prov_PMGetStatus; e; e = en) {
	  en = (struct zx_prov_PMGetStatus_s*)e->gg.g.n;
	  zx_FREE_prov_PMGetStatus(c, e, free_strs);
      }
  }
  {
      struct zx_prov_PMGetStatusResponse_s* e;
      struct zx_prov_PMGetStatusResponse_s* en;
      for (e = x->prov_PMGetStatusResponse; e; e = en) {
	  en = (struct zx_prov_PMGetStatusResponse_s*)e->gg.g.n;
	  zx_FREE_prov_PMGetStatusResponse(c, e, free_strs);
      }
  }
  {
      struct zx_prov_PMSetStatus_s* e;
      struct zx_prov_PMSetStatus_s* en;
      for (e = x->prov_PMSetStatus; e; e = en) {
	  en = (struct zx_prov_PMSetStatus_s*)e->gg.g.n;
	  zx_FREE_prov_PMSetStatus(c, e, free_strs);
      }
  }
  {
      struct zx_prov_PMSetStatusResponse_s* e;
      struct zx_prov_PMSetStatusResponse_s* en;
      for (e = x->prov_PMSetStatusResponse; e; e = en) {
	  en = (struct zx_prov_PMSetStatusResponse_s*)e->gg.g.n;
	  zx_FREE_prov_PMSetStatusResponse(c, e, free_strs);
      }
  }
  {
      struct zx_prov_PMGetDescriptor_s* e;
      struct zx_prov_PMGetDescriptor_s* en;
      for (e = x->PMGetDescriptor; e; e = en) {
	  en = (struct zx_prov_PMGetDescriptor_s*)e->gg.g.n;
	  zx_FREE_prov_PMGetDescriptor(c, e, free_strs);
      }
  }
  {
      struct zx_prov_PMGetDescriptorResponse_s* e;
      struct zx_prov_PMGetDescriptorResponse_s* en;
      for (e = x->PMGetDescriptorResponse; e; e = en) {
	  en = (struct zx_prov_PMGetDescriptorResponse_s*)e->gg.g.n;
	  zx_FREE_prov_PMGetDescriptorResponse(c, e, free_strs);
      }
  }
  {
      struct zx_prov_PMActivate_s* e;
      struct zx_prov_PMActivate_s* en;
      for (e = x->prov_PMActivate; e; e = en) {
	  en = (struct zx_prov_PMActivate_s*)e->gg.g.n;
	  zx_FREE_prov_PMActivate(c, e, free_strs);
      }
  }
  {
      struct zx_prov_PMActivateResponse_s* e;
      struct zx_prov_PMActivateResponse_s* en;
      for (e = x->prov_PMActivateResponse; e; e = en) {
	  en = (struct zx_prov_PMActivateResponse_s*)e->gg.g.n;
	  zx_FREE_prov_PMActivateResponse(c, e, free_strs);
      }
  }
  {
      struct zx_prov_PMDeactivate_s* e;
      struct zx_prov_PMDeactivate_s* en;
      for (e = x->prov_PMDeactivate; e; e = en) {
	  en = (struct zx_prov_PMDeactivate_s*)e->gg.g.n;
	  zx_FREE_prov_PMDeactivate(c, e, free_strs);
      }
  }
  {
      struct zx_prov_PMDeactivateResponse_s* e;
      struct zx_prov_PMDeactivateResponse_s* en;
      for (e = x->prov_PMDeactivateResponse; e; e = en) {
	  en = (struct zx_prov_PMDeactivateResponse_s*)e->gg.g.n;
	  zx_FREE_prov_PMDeactivateResponse(c, e, free_strs);
      }
  }
  {
      struct zx_prov_PMRegisterDescriptor_s* e;
      struct zx_prov_PMRegisterDescriptor_s* en;
      for (e = x->PMRegisterDescriptor; e; e = en) {
	  en = (struct zx_prov_PMRegisterDescriptor_s*)e->gg.g.n;
	  zx_FREE_prov_PMRegisterDescriptor(c, e, free_strs);
      }
  }
  {
      struct zx_prov_PMRegisterDescriptorResponse_s* e;
      struct zx_prov_PMRegisterDescriptorResponse_s* en;
      for (e = x->PMRegisterDescriptorResponse; e; e = en) {
	  en = (struct zx_prov_PMRegisterDescriptorResponse_s*)e->gg.g.n;
	  zx_FREE_prov_PMRegisterDescriptorResponse(c, e, free_strs);
      }
  }
  {
      struct zx_prov_PMUpdate_s* e;
      struct zx_prov_PMUpdate_s* en;
      for (e = x->prov_PMUpdate; e; e = en) {
	  en = (struct zx_prov_PMUpdate_s*)e->gg.g.n;
	  zx_FREE_prov_PMUpdate(c, e, free_strs);
      }
  }
  {
      struct zx_prov_PMUpdateResponse_s* e;
      struct zx_prov_PMUpdateResponse_s* en;
      for (e = x->prov_PMUpdateResponse; e; e = en) {
	  en = (struct zx_prov_PMUpdateResponse_s*)e->gg.g.n;
	  zx_FREE_prov_PMUpdateResponse(c, e, free_strs);
      }
  }
  {
      struct zx_prov_PMDelete_s* e;
      struct zx_prov_PMDelete_s* en;
      for (e = x->prov_PMDelete; e; e = en) {
	  en = (struct zx_prov_PMDelete_s*)e->gg.g.n;
	  zx_FREE_prov_PMDelete(c, e, free_strs);
      }
  }
  {
      struct zx_prov_PMDeleteResponse_s* e;
      struct zx_prov_PMDeleteResponse_s* en;
      for (e = x->prov_PMDeleteResponse; e; e = en) {
	  en = (struct zx_prov_PMDeleteResponse_s*)e->gg.g.n;
	  zx_FREE_prov_PMDeleteResponse(c, e, free_strs);
      }
  }
  {
      struct zx_prov_Poll_s* e;
      struct zx_prov_Poll_s* en;
      for (e = x->Poll; e; e = en) {
	  en = (struct zx_prov_Poll_s*)e->gg.g.n;
	  zx_FREE_prov_Poll(c, e, free_strs);
      }
  }
  {
      struct zx_prov_PollResponse_s* e;
      struct zx_prov_PollResponse_s* en;
      for (e = x->PollResponse; e; e = en) {
	  en = (struct zx_prov_PollResponse_s*)e->gg.g.n;
	  zx_FREE_prov_PollResponse(c, e, free_strs);
      }
  }
  {
      struct zx_prov_UpdateEPR_s* e;
      struct zx_prov_UpdateEPR_s* en;
      for (e = x->UpdateEPR; e; e = en) {
	  en = (struct zx_prov_UpdateEPR_s*)e->gg.g.n;
	  zx_FREE_prov_UpdateEPR(c, e, free_strs);
      }
  }
  {
      struct zx_prov_UpdateEPRResponse_s* e;
      struct zx_prov_UpdateEPRResponse_s* en;
      for (e = x->UpdateEPRResponse; e; e = en) {
	  en = (struct zx_prov_UpdateEPRResponse_s*)e->gg.g.n;
	  zx_FREE_prov_UpdateEPRResponse(c, e, free_strs);
      }
  }
  {
      struct zx_idp_GetAssertion_s* e;
      struct zx_idp_GetAssertion_s* en;
      for (e = x->GetAssertion; e; e = en) {
	  en = (struct zx_idp_GetAssertion_s*)e->gg.g.n;
	  zx_FREE_idp_GetAssertion(c, e, free_strs);
      }
  }
  {
      struct zx_idp_GetAssertionResponse_s* e;
      struct zx_idp_GetAssertionResponse_s* en;
      for (e = x->GetAssertionResponse; e; e = en) {
	  en = (struct zx_idp_GetAssertionResponse_s*)e->gg.g.n;
	  zx_FREE_idp_GetAssertionResponse(c, e, free_strs);
      }
  }
  {
      struct zx_idp_GetProviderInfo_s* e;
      struct zx_idp_GetProviderInfo_s* en;
      for (e = x->GetProviderInfo; e; e = en) {
	  en = (struct zx_idp_GetProviderInfo_s*)e->gg.g.n;
	  zx_FREE_idp_GetProviderInfo(c, e, free_strs);
      }
  }
  {
      struct zx_idp_GetProviderInfoResponse_s* e;
      struct zx_idp_GetProviderInfoResponse_s* en;
      for (e = x->GetProviderInfoResponse; e; e = en) {
	  en = (struct zx_idp_GetProviderInfoResponse_s*)e->gg.g.n;
	  zx_FREE_idp_GetProviderInfoResponse(c, e, free_strs);
      }
  }
  {
      struct zx_idp_CreatedStatus_s* e;
      struct zx_idp_CreatedStatus_s* en;
      for (e = x->CreatedStatus; e; e = en) {
	  en = (struct zx_idp_CreatedStatus_s*)e->gg.g.n;
	  zx_FREE_idp_CreatedStatus(c, e, free_strs);
      }
  }
  {
      struct zx_idp_CreatedStatusResponse_s* e;
      struct zx_idp_CreatedStatusResponse_s* en;
      for (e = x->CreatedStatusResponse; e; e = en) {
	  en = (struct zx_idp_CreatedStatusResponse_s*)e->gg.g.n;
	  zx_FREE_idp_CreatedStatusResponse(c, e, free_strs);
      }
  }
  {
      struct zx_shps_Delete_s* e;
      struct zx_shps_Delete_s* en;
      for (e = x->shps_Delete; e; e = en) {
	  en = (struct zx_shps_Delete_s*)e->gg.g.n;
	  zx_FREE_shps_Delete(c, e, free_strs);
      }
  }
  {
      struct zx_shps_DeleteResponse_s* e;
      struct zx_shps_DeleteResponse_s* en;
      for (e = x->shps_DeleteResponse; e; e = en) {
	  en = (struct zx_shps_DeleteResponse_s*)e->gg.g.n;
	  zx_FREE_shps_DeleteResponse(c, e, free_strs);
      }
  }
  {
      struct zx_shps_GetStatus_s* e;
      struct zx_shps_GetStatus_s* en;
      for (e = x->GetStatus; e; e = en) {
	  en = (struct zx_shps_GetStatus_s*)e->gg.g.n;
	  zx_FREE_shps_GetStatus(c, e, free_strs);
      }
  }
  {
      struct zx_shps_GetStatusResponse_s* e;
      struct zx_shps_GetStatusResponse_s* en;
      for (e = x->GetStatusResponse; e; e = en) {
	  en = (struct zx_shps_GetStatusResponse_s*)e->gg.g.n;
	  zx_FREE_shps_GetStatusResponse(c, e, free_strs);
      }
  }
  {
      struct zx_shps_Query_s* e;
      struct zx_shps_Query_s* en;
      for (e = x->shps_Query; e; e = en) {
	  en = (struct zx_shps_Query_s*)e->gg.g.n;
	  zx_FREE_shps_Query(c, e, free_strs);
      }
  }
  {
      struct zx_shps_QueryResponse_s* e;
      struct zx_shps_QueryResponse_s* en;
      for (e = x->shps_QueryResponse; e; e = en) {
	  en = (struct zx_shps_QueryResponse_s*)e->gg.g.n;
	  zx_FREE_shps_QueryResponse(c, e, free_strs);
      }
  }
  zx_free_simple_elems(c, x->Invoke, free_strs);
  {
      struct zx_shps_InvokeResponse_s* e;
      struct zx_shps_InvokeResponse_s* en;
      for (e = x->InvokeResponse; e; e = en) {
	  en = (struct zx_shps_InvokeResponse_s*)e->gg.g.n;
	  zx_FREE_shps_InvokeResponse(c, e, free_strs);
      }
  }
  {
      struct zx_shps_QueryRegistered_s* e;
      struct zx_shps_QueryRegistered_s* en;
      for (e = x->QueryRegistered; e; e = en) {
	  en = (struct zx_shps_QueryRegistered_s*)e->gg.g.n;
	  zx_FREE_shps_QueryRegistered(c, e, free_strs);
      }
  }
  {
      struct zx_shps_QueryRegisteredResponse_s* e;
      struct zx_shps_QueryRegisteredResponse_s* en;
      for (e = x->QueryRegisteredResponse; e; e = en) {
	  en = (struct zx_shps_QueryRegisteredResponse_s*)e->gg.g.n;
	  zx_FREE_shps_QueryRegisteredResponse(c, e, free_strs);
      }
  }
  {
      struct zx_shps_Register_s* e;
      struct zx_shps_Register_s* en;
      for (e = x->Register; e; e = en) {
	  en = (struct zx_shps_Register_s*)e->gg.g.n;
	  zx_FREE_shps_Register(c, e, free_strs);
      }
  }
  {
      struct zx_shps_RegisterResponse_s* e;
      struct zx_shps_RegisterResponse_s* en;
      for (e = x->RegisterResponse; e; e = en) {
	  en = (struct zx_shps_RegisterResponse_s*)e->gg.g.n;
	  zx_FREE_shps_RegisterResponse(c, e, free_strs);
      }
  }
  {
      struct zx_shps_SetStatus_s* e;
      struct zx_shps_SetStatus_s* en;
      for (e = x->SetStatus; e; e = en) {
	  en = (struct zx_shps_SetStatus_s*)e->gg.g.n;
	  zx_FREE_shps_SetStatus(c, e, free_strs);
      }
  }
  {
      struct zx_shps_SetStatusResponse_s* e;
      struct zx_shps_SetStatusResponse_s* en;
      for (e = x->SetStatusResponse; e; e = en) {
	  en = (struct zx_shps_SetStatusResponse_s*)e->gg.g.n;
	  zx_FREE_shps_SetStatusResponse(c, e, free_strs);
      }
  }
  {
      struct zx_shps_Update_s* e;
      struct zx_shps_Update_s* en;
      for (e = x->Update; e; e = en) {
	  en = (struct zx_shps_Update_s*)e->gg.g.n;
	  zx_FREE_shps_Update(c, e, free_strs);
      }
  }
  {
      struct zx_shps_UpdateResponse_s* e;
      struct zx_shps_UpdateResponse_s* en;
      for (e = x->UpdateResponse; e; e = en) {
	  en = (struct zx_shps_UpdateResponse_s*)e->gg.g.n;
	  zx_FREE_shps_UpdateResponse(c, e, free_strs);
      }
  }
  {
      struct zx_shps_Poll_s* e;
      struct zx_shps_Poll_s* en;
      for (e = x->shps_Poll; e; e = en) {
	  en = (struct zx_shps_Poll_s*)e->gg.g.n;
	  zx_FREE_shps_Poll(c, e, free_strs);
      }
  }
  {
      struct zx_shps_PollResponse_s* e;
      struct zx_shps_PollResponse_s* en;
      for (e = x->shps_PollResponse; e; e = en) {
	  en = (struct zx_shps_PollResponse_s*)e->gg.g.n;
	  zx_FREE_shps_PollResponse(c, e, free_strs);
      }
  }
  {
      struct zx_shps_ProxyInvoke_s* e;
      struct zx_shps_ProxyInvoke_s* en;
      for (e = x->ProxyInvoke; e; e = en) {
	  en = (struct zx_shps_ProxyInvoke_s*)e->gg.g.n;
	  zx_FREE_shps_ProxyInvoke(c, e, free_strs);
      }
  }
  {
      struct zx_shps_ProxyInvokeResponse_s* e;
      struct zx_shps_ProxyInvokeResponse_s* en;
      for (e = x->ProxyInvokeResponse; e; e = en) {
	  en = (struct zx_shps_ProxyInvokeResponse_s*)e->gg.g.n;
	  zx_FREE_shps_ProxyInvokeResponse(c, e, free_strs);
      }
  }
  {
      struct zx_idhrxml_Create_s* e;
      struct zx_idhrxml_Create_s* en;
      for (e = x->idhrxml_Create; e; e = en) {
	  en = (struct zx_idhrxml_Create_s*)e->gg.g.n;
	  zx_FREE_idhrxml_Create(c, e, free_strs);
      }
  }
  {
      struct zx_idhrxml_CreateResponse_s* e;
      struct zx_idhrxml_CreateResponse_s* en;
      for (e = x->idhrxml_CreateResponse; e; e = en) {
	  en = (struct zx_idhrxml_CreateResponse_s*)e->gg.g.n;
	  zx_FREE_idhrxml_CreateResponse(c, e, free_strs);
      }
  }
  {
      struct zx_idhrxml_Query_s* e;
      struct zx_idhrxml_Query_s* en;
      for (e = x->idhrxml_Query; e; e = en) {
	  en = (struct zx_idhrxml_Query_s*)e->gg.g.n;
	  zx_FREE_idhrxml_Query(c, e, free_strs);
      }
  }
  {
      struct zx_idhrxml_QueryResponse_s* e;
      struct zx_idhrxml_QueryResponse_s* en;
      for (e = x->idhrxml_QueryResponse; e; e = en) {
	  en = (struct zx_idhrxml_QueryResponse_s*)e->gg.g.n;
	  zx_FREE_idhrxml_QueryResponse(c, e, free_strs);
      }
  }
  {
      struct zx_idhrxml_Modify_s* e;
      struct zx_idhrxml_Modify_s* en;
      for (e = x->idhrxml_Modify; e; e = en) {
	  en = (struct zx_idhrxml_Modify_s*)e->gg.g.n;
	  zx_FREE_idhrxml_Modify(c, e, free_strs);
      }
  }
  {
      struct zx_idhrxml_ModifyResponse_s* e;
      struct zx_idhrxml_ModifyResponse_s* en;
      for (e = x->idhrxml_ModifyResponse; e; e = en) {
	  en = (struct zx_idhrxml_ModifyResponse_s*)e->gg.g.n;
	  zx_FREE_idhrxml_ModifyResponse(c, e, free_strs);
      }
  }
  {
      struct zx_idhrxml_Delete_s* e;
      struct zx_idhrxml_Delete_s* en;
      for (e = x->idhrxml_Delete; e; e = en) {
	  en = (struct zx_idhrxml_Delete_s*)e->gg.g.n;
	  zx_FREE_idhrxml_Delete(c, e, free_strs);
      }
  }
  {
      struct zx_idhrxml_DeleteResponse_s* e;
      struct zx_idhrxml_DeleteResponse_s* en;
      for (e = x->idhrxml_DeleteResponse; e; e = en) {
	  en = (struct zx_idhrxml_DeleteResponse_s*)e->gg.g.n;
	  zx_FREE_idhrxml_DeleteResponse(c, e, free_strs);
      }
  }
  {
      struct zx_idhrxml_Notify_s* e;
      struct zx_idhrxml_Notify_s* en;
      for (e = x->idhrxml_Notify; e; e = en) {
	  en = (struct zx_idhrxml_Notify_s*)e->gg.g.n;
	  zx_FREE_idhrxml_Notify(c, e, free_strs);
      }
  }
  {
      struct zx_idhrxml_NotifyResponse_s* e;
      struct zx_idhrxml_NotifyResponse_s* en;
      for (e = x->idhrxml_NotifyResponse; e; e = en) {
	  en = (struct zx_idhrxml_NotifyResponse_s*)e->gg.g.n;
	  zx_FREE_idhrxml_NotifyResponse(c, e, free_strs);
      }
  }


  zx_free_elem_common(c, &x->gg, free_strs); 
}

/* FUNC(zx_NEW_e_Body) */

/* Trivial allocator/constructor for the datatype. */

/* Called by: */
struct zx_e_Body_s* zx_NEW_e_Body(struct zx_ctx* c)
{
  struct zx_e_Body_s* x = ZX_ZALLOC(c, struct zx_e_Body_s);
  x->gg.g.tok = zx_e_Body_ELEM;
  return x;
}

#ifdef ZX_ENA_AUX

/* FUNC(zx_DUP_STRS_e_Body) */

/* Depth first traversal of data structure to copy its simple strings
 * to memory allocated from the memory allocator. The decoder will
 * use the underlying wireprotocol PDU buffer for strings, i.e.
 * strings are not copied - they point to the real data. If the
 * datastructure needs to outlast the protocol data or needs a different
 * memory allocation strategy, you need to call this function.  */

/* Called by: */
void zx_DUP_STRS_e_Body(struct zx_ctx* c, struct zx_e_Body_s* x)
{
  zx_dup_strs_common(c, &x->gg);
  /* *** deal with xmlns specifications in exc c14n way */

  zx_dup_attr(c, x->id);

  {
      struct zx_sp_ArtifactResolve_s* e;
      for (e = x->ArtifactResolve; e; e = (struct zx_sp_ArtifactResolve_s*)e->gg.g.n)
	  zx_DUP_STRS_sp_ArtifactResolve(c, e);
  }
  {
      struct zx_sp_ArtifactResponse_s* e;
      for (e = x->ArtifactResponse; e; e = (struct zx_sp_ArtifactResponse_s*)e->gg.g.n)
	  zx_DUP_STRS_sp_ArtifactResponse(c, e);
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
      struct zx_sp_NameIDMappingRequest_s* e;
      for (e = x->NameIDMappingRequest; e; e = (struct zx_sp_NameIDMappingRequest_s*)e->gg.g.n)
	  zx_DUP_STRS_sp_NameIDMappingRequest(c, e);
  }
  {
      struct zx_sp_NameIDMappingResponse_s* e;
      for (e = x->NameIDMappingResponse; e; e = (struct zx_sp_NameIDMappingResponse_s*)e->gg.g.n)
	  zx_DUP_STRS_sp_NameIDMappingResponse(c, e);
  }
  {
      struct zx_sp_AttributeQuery_s* e;
      for (e = x->AttributeQuery; e; e = (struct zx_sp_AttributeQuery_s*)e->gg.g.n)
	  zx_DUP_STRS_sp_AttributeQuery(c, e);
  }
  {
      struct zx_sp_AuthnQuery_s* e;
      for (e = x->AuthnQuery; e; e = (struct zx_sp_AuthnQuery_s*)e->gg.g.n)
	  zx_DUP_STRS_sp_AuthnQuery(c, e);
  }
  {
      struct zx_sp_AuthzDecisionQuery_s* e;
      for (e = x->AuthzDecisionQuery; e; e = (struct zx_sp_AuthzDecisionQuery_s*)e->gg.g.n)
	  zx_DUP_STRS_sp_AuthzDecisionQuery(c, e);
  }
  {
      struct zx_sp_AssertionIDRequest_s* e;
      for (e = x->AssertionIDRequest; e; e = (struct zx_sp_AssertionIDRequest_s*)e->gg.g.n)
	  zx_DUP_STRS_sp_AssertionIDRequest(c, e);
  }
  {
      struct zx_sp_Response_s* e;
      for (e = x->Response; e; e = (struct zx_sp_Response_s*)e->gg.g.n)
	  zx_DUP_STRS_sp_Response(c, e);
  }
  {
      struct zx_sp_AuthnRequest_s* e;
      for (e = x->AuthnRequest; e; e = (struct zx_sp_AuthnRequest_s*)e->gg.g.n)
	  zx_DUP_STRS_sp_AuthnRequest(c, e);
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
  {
      struct zx_xac_Request_s* e;
      for (e = x->xac_Request; e; e = (struct zx_xac_Request_s*)e->gg.g.n)
	  zx_DUP_STRS_xac_Request(c, e);
  }
  {
      struct zx_xac_Response_s* e;
      for (e = x->xac_Response; e; e = (struct zx_xac_Response_s*)e->gg.g.n)
	  zx_DUP_STRS_xac_Response(c, e);
  }
  {
      struct zx_di_Query_s* e;
      for (e = x->Query; e; e = (struct zx_di_Query_s*)e->gg.g.n)
	  zx_DUP_STRS_di_Query(c, e);
  }
  {
      struct zx_di_QueryResponse_s* e;
      for (e = x->QueryResponse; e; e = (struct zx_di_QueryResponse_s*)e->gg.g.n)
	  zx_DUP_STRS_di_QueryResponse(c, e);
  }
  {
      struct zx_di12_Query_s* e;
      for (e = x->di12_Query; e; e = (struct zx_di12_Query_s*)e->gg.g.n)
	  zx_DUP_STRS_di12_Query(c, e);
  }
  {
      struct zx_di12_QueryResponse_s* e;
      for (e = x->di12_QueryResponse; e; e = (struct zx_di12_QueryResponse_s*)e->gg.g.n)
	  zx_DUP_STRS_di12_QueryResponse(c, e);
  }
  {
      struct zx_di12_Modify_s* e;
      for (e = x->Modify; e; e = (struct zx_di12_Modify_s*)e->gg.g.n)
	  zx_DUP_STRS_di12_Modify(c, e);
  }
  {
      struct zx_di12_ModifyResponse_s* e;
      for (e = x->ModifyResponse; e; e = (struct zx_di12_ModifyResponse_s*)e->gg.g.n)
	  zx_DUP_STRS_di12_ModifyResponse(c, e);
  }
  {
      struct zx_e_Fault_s* e;
      for (e = x->Fault; e; e = (struct zx_e_Fault_s*)e->gg.g.n)
	  zx_DUP_STRS_e_Fault(c, e);
  }
  {
      struct zx_di_SvcMDAssociationAdd_s* e;
      for (e = x->SvcMDAssociationAdd; e; e = (struct zx_di_SvcMDAssociationAdd_s*)e->gg.g.n)
	  zx_DUP_STRS_di_SvcMDAssociationAdd(c, e);
  }
  {
      struct zx_di_SvcMDAssociationAddResponse_s* e;
      for (e = x->SvcMDAssociationAddResponse; e; e = (struct zx_di_SvcMDAssociationAddResponse_s*)e->gg.g.n)
	  zx_DUP_STRS_di_SvcMDAssociationAddResponse(c, e);
  }
  {
      struct zx_di_SvcMDAssociationDelete_s* e;
      for (e = x->SvcMDAssociationDelete; e; e = (struct zx_di_SvcMDAssociationDelete_s*)e->gg.g.n)
	  zx_DUP_STRS_di_SvcMDAssociationDelete(c, e);
  }
  {
      struct zx_di_SvcMDAssociationDeleteResponse_s* e;
      for (e = x->SvcMDAssociationDeleteResponse; e; e = (struct zx_di_SvcMDAssociationDeleteResponse_s*)e->gg.g.n)
	  zx_DUP_STRS_di_SvcMDAssociationDeleteResponse(c, e);
  }
  {
      struct zx_di_SvcMDAssociationQuery_s* e;
      for (e = x->SvcMDAssociationQuery; e; e = (struct zx_di_SvcMDAssociationQuery_s*)e->gg.g.n)
	  zx_DUP_STRS_di_SvcMDAssociationQuery(c, e);
  }
  {
      struct zx_di_SvcMDAssociationQueryResponse_s* e;
      for (e = x->SvcMDAssociationQueryResponse; e; e = (struct zx_di_SvcMDAssociationQueryResponse_s*)e->gg.g.n)
	  zx_DUP_STRS_di_SvcMDAssociationQueryResponse(c, e);
  }
  {
      struct zx_di_SvcMDRegister_s* e;
      for (e = x->SvcMDRegister; e; e = (struct zx_di_SvcMDRegister_s*)e->gg.g.n)
	  zx_DUP_STRS_di_SvcMDRegister(c, e);
  }
  {
      struct zx_di_SvcMDRegisterResponse_s* e;
      for (e = x->SvcMDRegisterResponse; e; e = (struct zx_di_SvcMDRegisterResponse_s*)e->gg.g.n)
	  zx_DUP_STRS_di_SvcMDRegisterResponse(c, e);
  }
  {
      struct zx_di_SvcMDDelete_s* e;
      for (e = x->SvcMDDelete; e; e = (struct zx_di_SvcMDDelete_s*)e->gg.g.n)
	  zx_DUP_STRS_di_SvcMDDelete(c, e);
  }
  {
      struct zx_di_SvcMDDeleteResponse_s* e;
      for (e = x->SvcMDDeleteResponse; e; e = (struct zx_di_SvcMDDeleteResponse_s*)e->gg.g.n)
	  zx_DUP_STRS_di_SvcMDDeleteResponse(c, e);
  }
  {
      struct zx_di_SvcMDQuery_s* e;
      for (e = x->SvcMDQuery; e; e = (struct zx_di_SvcMDQuery_s*)e->gg.g.n)
	  zx_DUP_STRS_di_SvcMDQuery(c, e);
  }
  {
      struct zx_di_SvcMDQueryResponse_s* e;
      for (e = x->SvcMDQueryResponse; e; e = (struct zx_di_SvcMDQueryResponse_s*)e->gg.g.n)
	  zx_DUP_STRS_di_SvcMDQueryResponse(c, e);
  }
  {
      struct zx_di_SvcMDReplace_s* e;
      for (e = x->SvcMDReplace; e; e = (struct zx_di_SvcMDReplace_s*)e->gg.g.n)
	  zx_DUP_STRS_di_SvcMDReplace(c, e);
  }
  {
      struct zx_di_SvcMDReplaceResponse_s* e;
      for (e = x->SvcMDReplaceResponse; e; e = (struct zx_di_SvcMDReplaceResponse_s*)e->gg.g.n)
	  zx_DUP_STRS_di_SvcMDReplaceResponse(c, e);
  }
  {
      struct zx_dap_Create_s* e;
      for (e = x->Create; e; e = (struct zx_dap_Create_s*)e->gg.g.n)
	  zx_DUP_STRS_dap_Create(c, e);
  }
  {
      struct zx_dap_CreateResponse_s* e;
      for (e = x->CreateResponse; e; e = (struct zx_dap_CreateResponse_s*)e->gg.g.n)
	  zx_DUP_STRS_dap_CreateResponse(c, e);
  }
  {
      struct zx_dap_Query_s* e;
      for (e = x->dap_Query; e; e = (struct zx_dap_Query_s*)e->gg.g.n)
	  zx_DUP_STRS_dap_Query(c, e);
  }
  {
      struct zx_dap_QueryResponse_s* e;
      for (e = x->dap_QueryResponse; e; e = (struct zx_dap_QueryResponse_s*)e->gg.g.n)
	  zx_DUP_STRS_dap_QueryResponse(c, e);
  }
  {
      struct zx_dap_Modify_s* e;
      for (e = x->dap_Modify; e; e = (struct zx_dap_Modify_s*)e->gg.g.n)
	  zx_DUP_STRS_dap_Modify(c, e);
  }
  {
      struct zx_dap_ModifyResponse_s* e;
      for (e = x->dap_ModifyResponse; e; e = (struct zx_dap_ModifyResponse_s*)e->gg.g.n)
	  zx_DUP_STRS_dap_ModifyResponse(c, e);
  }
  {
      struct zx_dap_Delete_s* e;
      for (e = x->Delete; e; e = (struct zx_dap_Delete_s*)e->gg.g.n)
	  zx_DUP_STRS_dap_Delete(c, e);
  }
  {
      struct zx_dap_DeleteResponse_s* e;
      for (e = x->DeleteResponse; e; e = (struct zx_dap_DeleteResponse_s*)e->gg.g.n)
	  zx_DUP_STRS_dap_DeleteResponse(c, e);
  }
  {
      struct zx_dap_Notify_s* e;
      for (e = x->Notify; e; e = (struct zx_dap_Notify_s*)e->gg.g.n)
	  zx_DUP_STRS_dap_Notify(c, e);
  }
  {
      struct zx_dap_NotifyResponse_s* e;
      for (e = x->NotifyResponse; e; e = (struct zx_dap_NotifyResponse_s*)e->gg.g.n)
	  zx_DUP_STRS_dap_NotifyResponse(c, e);
  }
  {
      struct zx_ps_AddEntityRequest_s* e;
      for (e = x->AddEntityRequest; e; e = (struct zx_ps_AddEntityRequest_s*)e->gg.g.n)
	  zx_DUP_STRS_ps_AddEntityRequest(c, e);
  }
  {
      struct zx_ps_AddEntityResponse_s* e;
      for (e = x->AddEntityResponse; e; e = (struct zx_ps_AddEntityResponse_s*)e->gg.g.n)
	  zx_DUP_STRS_ps_AddEntityResponse(c, e);
  }
  {
      struct zx_ps_AddKnownEntityRequest_s* e;
      for (e = x->AddKnownEntityRequest; e; e = (struct zx_ps_AddKnownEntityRequest_s*)e->gg.g.n)
	  zx_DUP_STRS_ps_AddKnownEntityRequest(c, e);
  }
  {
      struct zx_ps_AddKnownEntityResponse_s* e;
      for (e = x->AddKnownEntityResponse; e; e = (struct zx_ps_AddKnownEntityResponse_s*)e->gg.g.n)
	  zx_DUP_STRS_ps_AddKnownEntityResponse(c, e);
  }
  {
      struct zx_ps_AddCollectionRequest_s* e;
      for (e = x->AddCollectionRequest; e; e = (struct zx_ps_AddCollectionRequest_s*)e->gg.g.n)
	  zx_DUP_STRS_ps_AddCollectionRequest(c, e);
  }
  {
      struct zx_ps_AddCollectionResponse_s* e;
      for (e = x->AddCollectionResponse; e; e = (struct zx_ps_AddCollectionResponse_s*)e->gg.g.n)
	  zx_DUP_STRS_ps_AddCollectionResponse(c, e);
  }
  {
      struct zx_ps_AddToCollectionRequest_s* e;
      for (e = x->AddToCollectionRequest; e; e = (struct zx_ps_AddToCollectionRequest_s*)e->gg.g.n)
	  zx_DUP_STRS_ps_AddToCollectionRequest(c, e);
  }
  {
      struct zx_ps_AddToCollectionResponse_s* e;
      for (e = x->AddToCollectionResponse; e; e = (struct zx_ps_AddToCollectionResponse_s*)e->gg.g.n)
	  zx_DUP_STRS_ps_AddToCollectionResponse(c, e);
  }
  {
      struct zx_ps_RemoveEntityRequest_s* e;
      for (e = x->RemoveEntityRequest; e; e = (struct zx_ps_RemoveEntityRequest_s*)e->gg.g.n)
	  zx_DUP_STRS_ps_RemoveEntityRequest(c, e);
  }
  {
      struct zx_ps_RemoveEntityResponse_s* e;
      for (e = x->RemoveEntityResponse; e; e = (struct zx_ps_RemoveEntityResponse_s*)e->gg.g.n)
	  zx_DUP_STRS_ps_RemoveEntityResponse(c, e);
  }
  {
      struct zx_ps_RemoveCollectionRequest_s* e;
      for (e = x->RemoveCollectionRequest; e; e = (struct zx_ps_RemoveCollectionRequest_s*)e->gg.g.n)
	  zx_DUP_STRS_ps_RemoveCollectionRequest(c, e);
  }
  {
      struct zx_ps_RemoveCollectionResponse_s* e;
      for (e = x->RemoveCollectionResponse; e; e = (struct zx_ps_RemoveCollectionResponse_s*)e->gg.g.n)
	  zx_DUP_STRS_ps_RemoveCollectionResponse(c, e);
  }
  {
      struct zx_ps_RemoveFromCollectionRequest_s* e;
      for (e = x->RemoveFromCollectionRequest; e; e = (struct zx_ps_RemoveFromCollectionRequest_s*)e->gg.g.n)
	  zx_DUP_STRS_ps_RemoveFromCollectionRequest(c, e);
  }
  {
      struct zx_ps_RemoveFromCollectionResponse_s* e;
      for (e = x->RemoveFromCollectionResponse; e; e = (struct zx_ps_RemoveFromCollectionResponse_s*)e->gg.g.n)
	  zx_DUP_STRS_ps_RemoveFromCollectionResponse(c, e);
  }
  {
      struct zx_ps_ListMembersRequest_s* e;
      for (e = x->ListMembersRequest; e; e = (struct zx_ps_ListMembersRequest_s*)e->gg.g.n)
	  zx_DUP_STRS_ps_ListMembersRequest(c, e);
  }
  {
      struct zx_ps_ListMembersResponse_s* e;
      for (e = x->ListMembersResponse; e; e = (struct zx_ps_ListMembersResponse_s*)e->gg.g.n)
	  zx_DUP_STRS_ps_ListMembersResponse(c, e);
  }
  {
      struct zx_ps_QueryObjectsRequest_s* e;
      for (e = x->QueryObjectsRequest; e; e = (struct zx_ps_QueryObjectsRequest_s*)e->gg.g.n)
	  zx_DUP_STRS_ps_QueryObjectsRequest(c, e);
  }
  {
      struct zx_ps_QueryObjectsResponse_s* e;
      for (e = x->QueryObjectsResponse; e; e = (struct zx_ps_QueryObjectsResponse_s*)e->gg.g.n)
	  zx_DUP_STRS_ps_QueryObjectsResponse(c, e);
  }
  {
      struct zx_ps_GetObjectInfoRequest_s* e;
      for (e = x->GetObjectInfoRequest; e; e = (struct zx_ps_GetObjectInfoRequest_s*)e->gg.g.n)
	  zx_DUP_STRS_ps_GetObjectInfoRequest(c, e);
  }
  {
      struct zx_ps_GetObjectInfoResponse_s* e;
      for (e = x->GetObjectInfoResponse; e; e = (struct zx_ps_GetObjectInfoResponse_s*)e->gg.g.n)
	  zx_DUP_STRS_ps_GetObjectInfoResponse(c, e);
  }
  {
      struct zx_ps_SetObjectInfoRequest_s* e;
      for (e = x->SetObjectInfoRequest; e; e = (struct zx_ps_SetObjectInfoRequest_s*)e->gg.g.n)
	  zx_DUP_STRS_ps_SetObjectInfoRequest(c, e);
  }
  {
      struct zx_ps_SetObjectInfoResponse_s* e;
      for (e = x->SetObjectInfoResponse; e; e = (struct zx_ps_SetObjectInfoResponse_s*)e->gg.g.n)
	  zx_DUP_STRS_ps_SetObjectInfoResponse(c, e);
  }
  {
      struct zx_ps_TestMembershipRequest_s* e;
      for (e = x->TestMembershipRequest; e; e = (struct zx_ps_TestMembershipRequest_s*)e->gg.g.n)
	  zx_DUP_STRS_ps_TestMembershipRequest(c, e);
  }
  {
      struct zx_ps_TestMembershipResponse_s* e;
      for (e = x->TestMembershipResponse; e; e = (struct zx_ps_TestMembershipResponse_s*)e->gg.g.n)
	  zx_DUP_STRS_ps_TestMembershipResponse(c, e);
  }
  {
      struct zx_ps_ResolveIdentifierRequest_s* e;
      for (e = x->ResolveIdentifierRequest; e; e = (struct zx_ps_ResolveIdentifierRequest_s*)e->gg.g.n)
	  zx_DUP_STRS_ps_ResolveIdentifierRequest(c, e);
  }
  {
      struct zx_ps_ResolveIdentifierResponse_s* e;
      for (e = x->ResolveIdentifierResponse; e; e = (struct zx_ps_ResolveIdentifierResponse_s*)e->gg.g.n)
	  zx_DUP_STRS_ps_ResolveIdentifierResponse(c, e);
  }
  {
      struct zx_ps_Notify_s* e;
      for (e = x->ps_Notify; e; e = (struct zx_ps_Notify_s*)e->gg.g.n)
	  zx_DUP_STRS_ps_Notify(c, e);
  }
  {
      struct zx_ps_NotifyResponse_s* e;
      for (e = x->ps_NotifyResponse; e; e = (struct zx_ps_NotifyResponse_s*)e->gg.g.n)
	  zx_DUP_STRS_ps_NotifyResponse(c, e);
  }
  {
      struct zx_im_IdentityMappingRequest_s* e;
      for (e = x->IdentityMappingRequest; e; e = (struct zx_im_IdentityMappingRequest_s*)e->gg.g.n)
	  zx_DUP_STRS_im_IdentityMappingRequest(c, e);
  }
  {
      struct zx_im_IdentityMappingResponse_s* e;
      for (e = x->IdentityMappingResponse; e; e = (struct zx_im_IdentityMappingResponse_s*)e->gg.g.n)
	  zx_DUP_STRS_im_IdentityMappingResponse(c, e);
  }
  {
      struct zx_as_SASLRequest_s* e;
      for (e = x->SASLRequest; e; e = (struct zx_as_SASLRequest_s*)e->gg.g.n)
	  zx_DUP_STRS_as_SASLRequest(c, e);
  }
  {
      struct zx_as_SASLResponse_s* e;
      for (e = x->SASLResponse; e; e = (struct zx_as_SASLResponse_s*)e->gg.g.n)
	  zx_DUP_STRS_as_SASLResponse(c, e);
  }
  {
      struct zx_mm7_SubmitReq_s* e;
      for (e = x->SubmitReq; e; e = (struct zx_mm7_SubmitReq_s*)e->gg.g.n)
	  zx_DUP_STRS_mm7_SubmitReq(c, e);
  }
  {
      struct zx_mm7_SubmitRsp_s* e;
      for (e = x->SubmitRsp; e; e = (struct zx_mm7_SubmitRsp_s*)e->gg.g.n)
	  zx_DUP_STRS_mm7_SubmitRsp(c, e);
  }
  {
      struct zx_mm7_DeliverReq_s* e;
      for (e = x->DeliverReq; e; e = (struct zx_mm7_DeliverReq_s*)e->gg.g.n)
	  zx_DUP_STRS_mm7_DeliverReq(c, e);
  }
  {
      struct zx_mm7_DeliverRsp_s* e;
      for (e = x->DeliverRsp; e; e = (struct zx_mm7_DeliverRsp_s*)e->gg.g.n)
	  zx_DUP_STRS_mm7_DeliverRsp(c, e);
  }
  {
      struct zx_mm7_CancelReq_s* e;
      for (e = x->CancelReq; e; e = (struct zx_mm7_CancelReq_s*)e->gg.g.n)
	  zx_DUP_STRS_mm7_CancelReq(c, e);
  }
  {
      struct zx_mm7_CancelRsp_s* e;
      for (e = x->CancelRsp; e; e = (struct zx_mm7_CancelRsp_s*)e->gg.g.n)
	  zx_DUP_STRS_mm7_CancelRsp(c, e);
  }
  {
      struct zx_mm7_ReplaceReq_s* e;
      for (e = x->ReplaceReq; e; e = (struct zx_mm7_ReplaceReq_s*)e->gg.g.n)
	  zx_DUP_STRS_mm7_ReplaceReq(c, e);
  }
  {
      struct zx_mm7_ReplaceRsp_s* e;
      for (e = x->ReplaceRsp; e; e = (struct zx_mm7_ReplaceRsp_s*)e->gg.g.n)
	  zx_DUP_STRS_mm7_ReplaceRsp(c, e);
  }
  {
      struct zx_mm7_extendedCancelReq_s* e;
      for (e = x->extendedCancelReq; e; e = (struct zx_mm7_extendedCancelReq_s*)e->gg.g.n)
	  zx_DUP_STRS_mm7_extendedCancelReq(c, e);
  }
  {
      struct zx_mm7_extendedCancelRsp_s* e;
      for (e = x->extendedCancelRsp; e; e = (struct zx_mm7_extendedCancelRsp_s*)e->gg.g.n)
	  zx_DUP_STRS_mm7_extendedCancelRsp(c, e);
  }
  {
      struct zx_mm7_extendedReplaceReq_s* e;
      for (e = x->extendedReplaceReq; e; e = (struct zx_mm7_extendedReplaceReq_s*)e->gg.g.n)
	  zx_DUP_STRS_mm7_extendedReplaceReq(c, e);
  }
  {
      struct zx_mm7_extendedReplaceRsp_s* e;
      for (e = x->extendedReplaceRsp; e; e = (struct zx_mm7_extendedReplaceRsp_s*)e->gg.g.n)
	  zx_DUP_STRS_mm7_extendedReplaceRsp(c, e);
  }
  {
      struct zx_mm7_DeliveryReportReq_s* e;
      for (e = x->DeliveryReportReq; e; e = (struct zx_mm7_DeliveryReportReq_s*)e->gg.g.n)
	  zx_DUP_STRS_mm7_DeliveryReportReq(c, e);
  }
  {
      struct zx_mm7_DeliveryReportRsp_s* e;
      for (e = x->DeliveryReportRsp; e; e = (struct zx_mm7_DeliveryReportRsp_s*)e->gg.g.n)
	  zx_DUP_STRS_mm7_DeliveryReportRsp(c, e);
  }
  {
      struct zx_mm7_ReadReplyReq_s* e;
      for (e = x->ReadReplyReq; e; e = (struct zx_mm7_ReadReplyReq_s*)e->gg.g.n)
	  zx_DUP_STRS_mm7_ReadReplyReq(c, e);
  }
  {
      struct zx_mm7_ReadReplyRsp_s* e;
      for (e = x->ReadReplyRsp; e; e = (struct zx_mm7_ReadReplyRsp_s*)e->gg.g.n)
	  zx_DUP_STRS_mm7_ReadReplyRsp(c, e);
  }
  {
      struct zx_mm7_RSErrorRsp_s* e;
      for (e = x->RSErrorRsp; e; e = (struct zx_mm7_RSErrorRsp_s*)e->gg.g.n)
	  zx_DUP_STRS_mm7_RSErrorRsp(c, e);
  }
  {
      struct zx_mm7_VASPErrorRsp_s* e;
      for (e = x->VASPErrorRsp; e; e = (struct zx_mm7_VASPErrorRsp_s*)e->gg.g.n)
	  zx_DUP_STRS_mm7_VASPErrorRsp(c, e);
  }
  {
      struct zx_mm7_QueryStatusReq_s* e;
      for (e = x->QueryStatusReq; e; e = (struct zx_mm7_QueryStatusReq_s*)e->gg.g.n)
	  zx_DUP_STRS_mm7_QueryStatusReq(c, e);
  }
  {
      struct zx_mm7_QueryStatusRsp_s* e;
      for (e = x->QueryStatusRsp; e; e = (struct zx_mm7_QueryStatusRsp_s*)e->gg.g.n)
	  zx_DUP_STRS_mm7_QueryStatusRsp(c, e);
  }
  {
      struct zx_cb_Query_s* e;
      for (e = x->cb_Query; e; e = (struct zx_cb_Query_s*)e->gg.g.n)
	  zx_DUP_STRS_cb_Query(c, e);
  }
  {
      struct zx_cb_QueryResponse_s* e;
      for (e = x->cb_QueryResponse; e; e = (struct zx_cb_QueryResponse_s*)e->gg.g.n)
	  zx_DUP_STRS_cb_QueryResponse(c, e);
  }
  {
      struct zx_cb_Create_s* e;
      for (e = x->cb_Create; e; e = (struct zx_cb_Create_s*)e->gg.g.n)
	  zx_DUP_STRS_cb_Create(c, e);
  }
  {
      struct zx_cb_CreateResponse_s* e;
      for (e = x->cb_CreateResponse; e; e = (struct zx_cb_CreateResponse_s*)e->gg.g.n)
	  zx_DUP_STRS_cb_CreateResponse(c, e);
  }
  {
      struct zx_cb_Delete_s* e;
      for (e = x->cb_Delete; e; e = (struct zx_cb_Delete_s*)e->gg.g.n)
	  zx_DUP_STRS_cb_Delete(c, e);
  }
  {
      struct zx_cb_DeleteResponse_s* e;
      for (e = x->cb_DeleteResponse; e; e = (struct zx_cb_DeleteResponse_s*)e->gg.g.n)
	  zx_DUP_STRS_cb_DeleteResponse(c, e);
  }
  {
      struct zx_cb_Modify_s* e;
      for (e = x->cb_Modify; e; e = (struct zx_cb_Modify_s*)e->gg.g.n)
	  zx_DUP_STRS_cb_Modify(c, e);
  }
  {
      struct zx_cb_ModifyResponse_s* e;
      for (e = x->cb_ModifyResponse; e; e = (struct zx_cb_ModifyResponse_s*)e->gg.g.n)
	  zx_DUP_STRS_cb_ModifyResponse(c, e);
  }
  {
      struct zx_cb_Notify_s* e;
      for (e = x->cb_Notify; e; e = (struct zx_cb_Notify_s*)e->gg.g.n)
	  zx_DUP_STRS_cb_Notify(c, e);
  }
  {
      struct zx_cb_NotifyResponse_s* e;
      for (e = x->cb_NotifyResponse; e; e = (struct zx_cb_NotifyResponse_s*)e->gg.g.n)
	  zx_DUP_STRS_cb_NotifyResponse(c, e);
  }
  {
      struct zx_cb_ReportUsage_s* e;
      for (e = x->ReportUsage; e; e = (struct zx_cb_ReportUsage_s*)e->gg.g.n)
	  zx_DUP_STRS_cb_ReportUsage(c, e);
  }
  {
      struct zx_cb_ReportUsageResponse_s* e;
      for (e = x->ReportUsageResponse; e; e = (struct zx_cb_ReportUsageResponse_s*)e->gg.g.n)
	  zx_DUP_STRS_cb_ReportUsageResponse(c, e);
  }
  {
      struct zx_gl_Query_s* e;
      for (e = x->gl_Query; e; e = (struct zx_gl_Query_s*)e->gg.g.n)
	  zx_DUP_STRS_gl_Query(c, e);
  }
  {
      struct zx_gl_QueryResponse_s* e;
      for (e = x->gl_QueryResponse; e; e = (struct zx_gl_QueryResponse_s*)e->gg.g.n)
	  zx_DUP_STRS_gl_QueryResponse(c, e);
  }
  {
      struct zx_gl_Create_s* e;
      for (e = x->gl_Create; e; e = (struct zx_gl_Create_s*)e->gg.g.n)
	  zx_DUP_STRS_gl_Create(c, e);
  }
  {
      struct zx_gl_CreateResponse_s* e;
      for (e = x->gl_CreateResponse; e; e = (struct zx_gl_CreateResponse_s*)e->gg.g.n)
	  zx_DUP_STRS_gl_CreateResponse(c, e);
  }
  {
      struct zx_gl_Delete_s* e;
      for (e = x->gl_Delete; e; e = (struct zx_gl_Delete_s*)e->gg.g.n)
	  zx_DUP_STRS_gl_Delete(c, e);
  }
  {
      struct zx_gl_DeleteResponse_s* e;
      for (e = x->gl_DeleteResponse; e; e = (struct zx_gl_DeleteResponse_s*)e->gg.g.n)
	  zx_DUP_STRS_gl_DeleteResponse(c, e);
  }
  {
      struct zx_gl_Modify_s* e;
      for (e = x->gl_Modify; e; e = (struct zx_gl_Modify_s*)e->gg.g.n)
	  zx_DUP_STRS_gl_Modify(c, e);
  }
  {
      struct zx_gl_ModifyResponse_s* e;
      for (e = x->gl_ModifyResponse; e; e = (struct zx_gl_ModifyResponse_s*)e->gg.g.n)
	  zx_DUP_STRS_gl_ModifyResponse(c, e);
  }
  {
      struct zx_gl_Notify_s* e;
      for (e = x->gl_Notify; e; e = (struct zx_gl_Notify_s*)e->gg.g.n)
	  zx_DUP_STRS_gl_Notify(c, e);
  }
  {
      struct zx_gl_NotifyResponse_s* e;
      for (e = x->gl_NotifyResponse; e; e = (struct zx_gl_NotifyResponse_s*)e->gg.g.n)
	  zx_DUP_STRS_gl_NotifyResponse(c, e);
  }
  {
      struct zx_demomed_StoreObjectRequest_s* e;
      for (e = x->StoreObjectRequest; e; e = (struct zx_demomed_StoreObjectRequest_s*)e->gg.g.n)
	  zx_DUP_STRS_demomed_StoreObjectRequest(c, e);
  }
  {
      struct zx_demomed_StoreObjectResponse_s* e;
      for (e = x->StoreObjectResponse; e; e = (struct zx_demomed_StoreObjectResponse_s*)e->gg.g.n)
	  zx_DUP_STRS_demomed_StoreObjectResponse(c, e);
  }
  {
      struct zx_demomed_GetObjectListRequest_s* e;
      for (e = x->GetObjectListRequest; e; e = (struct zx_demomed_GetObjectListRequest_s*)e->gg.g.n)
	  zx_DUP_STRS_demomed_GetObjectListRequest(c, e);
  }
  {
      struct zx_demomed_GetObjectListResponse_s* e;
      for (e = x->GetObjectListResponse; e; e = (struct zx_demomed_GetObjectListResponse_s*)e->gg.g.n)
	  zx_DUP_STRS_demomed_GetObjectListResponse(c, e);
  }
  {
      struct zx_demomed_GetObjectRequest_s* e;
      for (e = x->GetObjectRequest; e; e = (struct zx_demomed_GetObjectRequest_s*)e->gg.g.n)
	  zx_DUP_STRS_demomed_GetObjectRequest(c, e);
  }
  {
      struct zx_demomed_GetObjectResponse_s* e;
      for (e = x->GetObjectResponse; e; e = (struct zx_demomed_GetObjectResponse_s*)e->gg.g.n)
	  zx_DUP_STRS_demomed_GetObjectResponse(c, e);
  }
  {
      struct zx_demomed_DeleteObjectRequest_s* e;
      for (e = x->DeleteObjectRequest; e; e = (struct zx_demomed_DeleteObjectRequest_s*)e->gg.g.n)
	  zx_DUP_STRS_demomed_DeleteObjectRequest(c, e);
  }
  {
      struct zx_demomed_DeleteObjectResponse_s* e;
      for (e = x->DeleteObjectResponse; e; e = (struct zx_demomed_DeleteObjectResponse_s*)e->gg.g.n)
	  zx_DUP_STRS_demomed_DeleteObjectResponse(c, e);
  }
  {
      struct zx_pmm_Provision_s* e;
      for (e = x->Provision; e; e = (struct zx_pmm_Provision_s*)e->gg.g.n)
	  zx_DUP_STRS_pmm_Provision(c, e);
  }
  {
      struct zx_pmm_ProvisionResponse_s* e;
      for (e = x->ProvisionResponse; e; e = (struct zx_pmm_ProvisionResponse_s*)e->gg.g.n)
	  zx_DUP_STRS_pmm_ProvisionResponse(c, e);
  }
  {
      struct zx_pmm_PMActivate_s* e;
      for (e = x->PMActivate; e; e = (struct zx_pmm_PMActivate_s*)e->gg.g.n)
	  zx_DUP_STRS_pmm_PMActivate(c, e);
  }
  {
      struct zx_pmm_PMActivateResponse_s* e;
      for (e = x->PMActivateResponse; e; e = (struct zx_pmm_PMActivateResponse_s*)e->gg.g.n)
	  zx_DUP_STRS_pmm_PMActivateResponse(c, e);
  }
  {
      struct zx_pmm_PMDeactivate_s* e;
      for (e = x->PMDeactivate; e; e = (struct zx_pmm_PMDeactivate_s*)e->gg.g.n)
	  zx_DUP_STRS_pmm_PMDeactivate(c, e);
  }
  {
      struct zx_pmm_PMDeactivateResponse_s* e;
      for (e = x->PMDeactivateResponse; e; e = (struct zx_pmm_PMDeactivateResponse_s*)e->gg.g.n)
	  zx_DUP_STRS_pmm_PMDeactivateResponse(c, e);
  }
  {
      struct zx_pmm_PMDelete_s* e;
      for (e = x->PMDelete; e; e = (struct zx_pmm_PMDelete_s*)e->gg.g.n)
	  zx_DUP_STRS_pmm_PMDelete(c, e);
  }
  {
      struct zx_pmm_PMDeleteResponse_s* e;
      for (e = x->PMDeleteResponse; e; e = (struct zx_pmm_PMDeleteResponse_s*)e->gg.g.n)
	  zx_DUP_STRS_pmm_PMDeleteResponse(c, e);
  }
  {
      struct zx_pmm_PMUpdate_s* e;
      for (e = x->PMUpdate; e; e = (struct zx_pmm_PMUpdate_s*)e->gg.g.n)
	  zx_DUP_STRS_pmm_PMUpdate(c, e);
  }
  {
      struct zx_pmm_PMUpdateResponse_s* e;
      for (e = x->PMUpdateResponse; e; e = (struct zx_pmm_PMUpdateResponse_s*)e->gg.g.n)
	  zx_DUP_STRS_pmm_PMUpdateResponse(c, e);
  }
  {
      struct zx_pmm_PMGetStatus_s* e;
      for (e = x->PMGetStatus; e; e = (struct zx_pmm_PMGetStatus_s*)e->gg.g.n)
	  zx_DUP_STRS_pmm_PMGetStatus(c, e);
  }
  {
      struct zx_pmm_PMGetStatusResponse_s* e;
      for (e = x->PMGetStatusResponse; e; e = (struct zx_pmm_PMGetStatusResponse_s*)e->gg.g.n)
	  zx_DUP_STRS_pmm_PMGetStatusResponse(c, e);
  }
  {
      struct zx_pmm_PMSetStatus_s* e;
      for (e = x->PMSetStatus; e; e = (struct zx_pmm_PMSetStatus_s*)e->gg.g.n)
	  zx_DUP_STRS_pmm_PMSetStatus(c, e);
  }
  {
      struct zx_pmm_PMSetStatusResponse_s* e;
      for (e = x->PMSetStatusResponse; e; e = (struct zx_pmm_PMSetStatusResponse_s*)e->gg.g.n)
	  zx_DUP_STRS_pmm_PMSetStatusResponse(c, e);
  }
  {
      struct zx_prov_PMERegister_s* e;
      for (e = x->PMERegister; e; e = (struct zx_prov_PMERegister_s*)e->gg.g.n)
	  zx_DUP_STRS_prov_PMERegister(c, e);
  }
  {
      struct zx_prov_PMERegisterResponse_s* e;
      for (e = x->PMERegisterResponse; e; e = (struct zx_prov_PMERegisterResponse_s*)e->gg.g.n)
	  zx_DUP_STRS_prov_PMERegisterResponse(c, e);
  }
  {
      struct zx_prov_PMEUpload_s* e;
      for (e = x->PMEUpload; e; e = (struct zx_prov_PMEUpload_s*)e->gg.g.n)
	  zx_DUP_STRS_prov_PMEUpload(c, e);
  }
  {
      struct zx_prov_PMEUploadResponse_s* e;
      for (e = x->PMEUploadResponse; e; e = (struct zx_prov_PMEUploadResponse_s*)e->gg.g.n)
	  zx_DUP_STRS_prov_PMEUploadResponse(c, e);
  }
  {
      struct zx_prov_PMEDownload_s* e;
      for (e = x->PMEDownload; e; e = (struct zx_prov_PMEDownload_s*)e->gg.g.n)
	  zx_DUP_STRS_prov_PMEDownload(c, e);
  }
  {
      struct zx_prov_PMEDownloadResponse_s* e;
      for (e = x->PMEDownloadResponse; e; e = (struct zx_prov_PMEDownloadResponse_s*)e->gg.g.n)
	  zx_DUP_STRS_prov_PMEDownloadResponse(c, e);
  }
  {
      struct zx_prov_PMEEnable_s* e;
      for (e = x->PMEEnable; e; e = (struct zx_prov_PMEEnable_s*)e->gg.g.n)
	  zx_DUP_STRS_prov_PMEEnable(c, e);
  }
  {
      struct zx_prov_PMEEnableResponse_s* e;
      for (e = x->PMEEnableResponse; e; e = (struct zx_prov_PMEEnableResponse_s*)e->gg.g.n)
	  zx_DUP_STRS_prov_PMEEnableResponse(c, e);
  }
  {
      struct zx_prov_PMEDisable_s* e;
      for (e = x->PMEDisable; e; e = (struct zx_prov_PMEDisable_s*)e->gg.g.n)
	  zx_DUP_STRS_prov_PMEDisable(c, e);
  }
  {
      struct zx_prov_PMEDisableResponse_s* e;
      for (e = x->PMEDisableResponse; e; e = (struct zx_prov_PMEDisableResponse_s*)e->gg.g.n)
	  zx_DUP_STRS_prov_PMEDisableResponse(c, e);
  }
  {
      struct zx_prov_PMEDelete_s* e;
      for (e = x->PMEDelete; e; e = (struct zx_prov_PMEDelete_s*)e->gg.g.n)
	  zx_DUP_STRS_prov_PMEDelete(c, e);
  }
  {
      struct zx_prov_PMEDeleteResponse_s* e;
      for (e = x->PMEDeleteResponse; e; e = (struct zx_prov_PMEDeleteResponse_s*)e->gg.g.n)
	  zx_DUP_STRS_prov_PMEDeleteResponse(c, e);
  }
  {
      struct zx_prov_PMEGetInfo_s* e;
      for (e = x->PMEGetInfo; e; e = (struct zx_prov_PMEGetInfo_s*)e->gg.g.n)
	  zx_DUP_STRS_prov_PMEGetInfo(c, e);
  }
  {
      struct zx_prov_PMEGetInfoResponse_s* e;
      for (e = x->PMEGetInfoResponse; e; e = (struct zx_prov_PMEGetInfoResponse_s*)e->gg.g.n)
	  zx_DUP_STRS_prov_PMEGetInfoResponse(c, e);
  }
  {
      struct zx_prov_PMGetStatus_s* e;
      for (e = x->prov_PMGetStatus; e; e = (struct zx_prov_PMGetStatus_s*)e->gg.g.n)
	  zx_DUP_STRS_prov_PMGetStatus(c, e);
  }
  {
      struct zx_prov_PMGetStatusResponse_s* e;
      for (e = x->prov_PMGetStatusResponse; e; e = (struct zx_prov_PMGetStatusResponse_s*)e->gg.g.n)
	  zx_DUP_STRS_prov_PMGetStatusResponse(c, e);
  }
  {
      struct zx_prov_PMSetStatus_s* e;
      for (e = x->prov_PMSetStatus; e; e = (struct zx_prov_PMSetStatus_s*)e->gg.g.n)
	  zx_DUP_STRS_prov_PMSetStatus(c, e);
  }
  {
      struct zx_prov_PMSetStatusResponse_s* e;
      for (e = x->prov_PMSetStatusResponse; e; e = (struct zx_prov_PMSetStatusResponse_s*)e->gg.g.n)
	  zx_DUP_STRS_prov_PMSetStatusResponse(c, e);
  }
  {
      struct zx_prov_PMGetDescriptor_s* e;
      for (e = x->PMGetDescriptor; e; e = (struct zx_prov_PMGetDescriptor_s*)e->gg.g.n)
	  zx_DUP_STRS_prov_PMGetDescriptor(c, e);
  }
  {
      struct zx_prov_PMGetDescriptorResponse_s* e;
      for (e = x->PMGetDescriptorResponse; e; e = (struct zx_prov_PMGetDescriptorResponse_s*)e->gg.g.n)
	  zx_DUP_STRS_prov_PMGetDescriptorResponse(c, e);
  }
  {
      struct zx_prov_PMActivate_s* e;
      for (e = x->prov_PMActivate; e; e = (struct zx_prov_PMActivate_s*)e->gg.g.n)
	  zx_DUP_STRS_prov_PMActivate(c, e);
  }
  {
      struct zx_prov_PMActivateResponse_s* e;
      for (e = x->prov_PMActivateResponse; e; e = (struct zx_prov_PMActivateResponse_s*)e->gg.g.n)
	  zx_DUP_STRS_prov_PMActivateResponse(c, e);
  }
  {
      struct zx_prov_PMDeactivate_s* e;
      for (e = x->prov_PMDeactivate; e; e = (struct zx_prov_PMDeactivate_s*)e->gg.g.n)
	  zx_DUP_STRS_prov_PMDeactivate(c, e);
  }
  {
      struct zx_prov_PMDeactivateResponse_s* e;
      for (e = x->prov_PMDeactivateResponse; e; e = (struct zx_prov_PMDeactivateResponse_s*)e->gg.g.n)
	  zx_DUP_STRS_prov_PMDeactivateResponse(c, e);
  }
  {
      struct zx_prov_PMRegisterDescriptor_s* e;
      for (e = x->PMRegisterDescriptor; e; e = (struct zx_prov_PMRegisterDescriptor_s*)e->gg.g.n)
	  zx_DUP_STRS_prov_PMRegisterDescriptor(c, e);
  }
  {
      struct zx_prov_PMRegisterDescriptorResponse_s* e;
      for (e = x->PMRegisterDescriptorResponse; e; e = (struct zx_prov_PMRegisterDescriptorResponse_s*)e->gg.g.n)
	  zx_DUP_STRS_prov_PMRegisterDescriptorResponse(c, e);
  }
  {
      struct zx_prov_PMUpdate_s* e;
      for (e = x->prov_PMUpdate; e; e = (struct zx_prov_PMUpdate_s*)e->gg.g.n)
	  zx_DUP_STRS_prov_PMUpdate(c, e);
  }
  {
      struct zx_prov_PMUpdateResponse_s* e;
      for (e = x->prov_PMUpdateResponse; e; e = (struct zx_prov_PMUpdateResponse_s*)e->gg.g.n)
	  zx_DUP_STRS_prov_PMUpdateResponse(c, e);
  }
  {
      struct zx_prov_PMDelete_s* e;
      for (e = x->prov_PMDelete; e; e = (struct zx_prov_PMDelete_s*)e->gg.g.n)
	  zx_DUP_STRS_prov_PMDelete(c, e);
  }
  {
      struct zx_prov_PMDeleteResponse_s* e;
      for (e = x->prov_PMDeleteResponse; e; e = (struct zx_prov_PMDeleteResponse_s*)e->gg.g.n)
	  zx_DUP_STRS_prov_PMDeleteResponse(c, e);
  }
  {
      struct zx_prov_Poll_s* e;
      for (e = x->Poll; e; e = (struct zx_prov_Poll_s*)e->gg.g.n)
	  zx_DUP_STRS_prov_Poll(c, e);
  }
  {
      struct zx_prov_PollResponse_s* e;
      for (e = x->PollResponse; e; e = (struct zx_prov_PollResponse_s*)e->gg.g.n)
	  zx_DUP_STRS_prov_PollResponse(c, e);
  }
  {
      struct zx_prov_UpdateEPR_s* e;
      for (e = x->UpdateEPR; e; e = (struct zx_prov_UpdateEPR_s*)e->gg.g.n)
	  zx_DUP_STRS_prov_UpdateEPR(c, e);
  }
  {
      struct zx_prov_UpdateEPRResponse_s* e;
      for (e = x->UpdateEPRResponse; e; e = (struct zx_prov_UpdateEPRResponse_s*)e->gg.g.n)
	  zx_DUP_STRS_prov_UpdateEPRResponse(c, e);
  }
  {
      struct zx_idp_GetAssertion_s* e;
      for (e = x->GetAssertion; e; e = (struct zx_idp_GetAssertion_s*)e->gg.g.n)
	  zx_DUP_STRS_idp_GetAssertion(c, e);
  }
  {
      struct zx_idp_GetAssertionResponse_s* e;
      for (e = x->GetAssertionResponse; e; e = (struct zx_idp_GetAssertionResponse_s*)e->gg.g.n)
	  zx_DUP_STRS_idp_GetAssertionResponse(c, e);
  }
  {
      struct zx_idp_GetProviderInfo_s* e;
      for (e = x->GetProviderInfo; e; e = (struct zx_idp_GetProviderInfo_s*)e->gg.g.n)
	  zx_DUP_STRS_idp_GetProviderInfo(c, e);
  }
  {
      struct zx_idp_GetProviderInfoResponse_s* e;
      for (e = x->GetProviderInfoResponse; e; e = (struct zx_idp_GetProviderInfoResponse_s*)e->gg.g.n)
	  zx_DUP_STRS_idp_GetProviderInfoResponse(c, e);
  }
  {
      struct zx_idp_CreatedStatus_s* e;
      for (e = x->CreatedStatus; e; e = (struct zx_idp_CreatedStatus_s*)e->gg.g.n)
	  zx_DUP_STRS_idp_CreatedStatus(c, e);
  }
  {
      struct zx_idp_CreatedStatusResponse_s* e;
      for (e = x->CreatedStatusResponse; e; e = (struct zx_idp_CreatedStatusResponse_s*)e->gg.g.n)
	  zx_DUP_STRS_idp_CreatedStatusResponse(c, e);
  }
  {
      struct zx_shps_Delete_s* e;
      for (e = x->shps_Delete; e; e = (struct zx_shps_Delete_s*)e->gg.g.n)
	  zx_DUP_STRS_shps_Delete(c, e);
  }
  {
      struct zx_shps_DeleteResponse_s* e;
      for (e = x->shps_DeleteResponse; e; e = (struct zx_shps_DeleteResponse_s*)e->gg.g.n)
	  zx_DUP_STRS_shps_DeleteResponse(c, e);
  }
  {
      struct zx_shps_GetStatus_s* e;
      for (e = x->GetStatus; e; e = (struct zx_shps_GetStatus_s*)e->gg.g.n)
	  zx_DUP_STRS_shps_GetStatus(c, e);
  }
  {
      struct zx_shps_GetStatusResponse_s* e;
      for (e = x->GetStatusResponse; e; e = (struct zx_shps_GetStatusResponse_s*)e->gg.g.n)
	  zx_DUP_STRS_shps_GetStatusResponse(c, e);
  }
  {
      struct zx_shps_Query_s* e;
      for (e = x->shps_Query; e; e = (struct zx_shps_Query_s*)e->gg.g.n)
	  zx_DUP_STRS_shps_Query(c, e);
  }
  {
      struct zx_shps_QueryResponse_s* e;
      for (e = x->shps_QueryResponse; e; e = (struct zx_shps_QueryResponse_s*)e->gg.g.n)
	  zx_DUP_STRS_shps_QueryResponse(c, e);
  }
  zx_dup_strs_simple_elems(c, x->Invoke);
  {
      struct zx_shps_InvokeResponse_s* e;
      for (e = x->InvokeResponse; e; e = (struct zx_shps_InvokeResponse_s*)e->gg.g.n)
	  zx_DUP_STRS_shps_InvokeResponse(c, e);
  }
  {
      struct zx_shps_QueryRegistered_s* e;
      for (e = x->QueryRegistered; e; e = (struct zx_shps_QueryRegistered_s*)e->gg.g.n)
	  zx_DUP_STRS_shps_QueryRegistered(c, e);
  }
  {
      struct zx_shps_QueryRegisteredResponse_s* e;
      for (e = x->QueryRegisteredResponse; e; e = (struct zx_shps_QueryRegisteredResponse_s*)e->gg.g.n)
	  zx_DUP_STRS_shps_QueryRegisteredResponse(c, e);
  }
  {
      struct zx_shps_Register_s* e;
      for (e = x->Register; e; e = (struct zx_shps_Register_s*)e->gg.g.n)
	  zx_DUP_STRS_shps_Register(c, e);
  }
  {
      struct zx_shps_RegisterResponse_s* e;
      for (e = x->RegisterResponse; e; e = (struct zx_shps_RegisterResponse_s*)e->gg.g.n)
	  zx_DUP_STRS_shps_RegisterResponse(c, e);
  }
  {
      struct zx_shps_SetStatus_s* e;
      for (e = x->SetStatus; e; e = (struct zx_shps_SetStatus_s*)e->gg.g.n)
	  zx_DUP_STRS_shps_SetStatus(c, e);
  }
  {
      struct zx_shps_SetStatusResponse_s* e;
      for (e = x->SetStatusResponse; e; e = (struct zx_shps_SetStatusResponse_s*)e->gg.g.n)
	  zx_DUP_STRS_shps_SetStatusResponse(c, e);
  }
  {
      struct zx_shps_Update_s* e;
      for (e = x->Update; e; e = (struct zx_shps_Update_s*)e->gg.g.n)
	  zx_DUP_STRS_shps_Update(c, e);
  }
  {
      struct zx_shps_UpdateResponse_s* e;
      for (e = x->UpdateResponse; e; e = (struct zx_shps_UpdateResponse_s*)e->gg.g.n)
	  zx_DUP_STRS_shps_UpdateResponse(c, e);
  }
  {
      struct zx_shps_Poll_s* e;
      for (e = x->shps_Poll; e; e = (struct zx_shps_Poll_s*)e->gg.g.n)
	  zx_DUP_STRS_shps_Poll(c, e);
  }
  {
      struct zx_shps_PollResponse_s* e;
      for (e = x->shps_PollResponse; e; e = (struct zx_shps_PollResponse_s*)e->gg.g.n)
	  zx_DUP_STRS_shps_PollResponse(c, e);
  }
  {
      struct zx_shps_ProxyInvoke_s* e;
      for (e = x->ProxyInvoke; e; e = (struct zx_shps_ProxyInvoke_s*)e->gg.g.n)
	  zx_DUP_STRS_shps_ProxyInvoke(c, e);
  }
  {
      struct zx_shps_ProxyInvokeResponse_s* e;
      for (e = x->ProxyInvokeResponse; e; e = (struct zx_shps_ProxyInvokeResponse_s*)e->gg.g.n)
	  zx_DUP_STRS_shps_ProxyInvokeResponse(c, e);
  }
  {
      struct zx_idhrxml_Create_s* e;
      for (e = x->idhrxml_Create; e; e = (struct zx_idhrxml_Create_s*)e->gg.g.n)
	  zx_DUP_STRS_idhrxml_Create(c, e);
  }
  {
      struct zx_idhrxml_CreateResponse_s* e;
      for (e = x->idhrxml_CreateResponse; e; e = (struct zx_idhrxml_CreateResponse_s*)e->gg.g.n)
	  zx_DUP_STRS_idhrxml_CreateResponse(c, e);
  }
  {
      struct zx_idhrxml_Query_s* e;
      for (e = x->idhrxml_Query; e; e = (struct zx_idhrxml_Query_s*)e->gg.g.n)
	  zx_DUP_STRS_idhrxml_Query(c, e);
  }
  {
      struct zx_idhrxml_QueryResponse_s* e;
      for (e = x->idhrxml_QueryResponse; e; e = (struct zx_idhrxml_QueryResponse_s*)e->gg.g.n)
	  zx_DUP_STRS_idhrxml_QueryResponse(c, e);
  }
  {
      struct zx_idhrxml_Modify_s* e;
      for (e = x->idhrxml_Modify; e; e = (struct zx_idhrxml_Modify_s*)e->gg.g.n)
	  zx_DUP_STRS_idhrxml_Modify(c, e);
  }
  {
      struct zx_idhrxml_ModifyResponse_s* e;
      for (e = x->idhrxml_ModifyResponse; e; e = (struct zx_idhrxml_ModifyResponse_s*)e->gg.g.n)
	  zx_DUP_STRS_idhrxml_ModifyResponse(c, e);
  }
  {
      struct zx_idhrxml_Delete_s* e;
      for (e = x->idhrxml_Delete; e; e = (struct zx_idhrxml_Delete_s*)e->gg.g.n)
	  zx_DUP_STRS_idhrxml_Delete(c, e);
  }
  {
      struct zx_idhrxml_DeleteResponse_s* e;
      for (e = x->idhrxml_DeleteResponse; e; e = (struct zx_idhrxml_DeleteResponse_s*)e->gg.g.n)
	  zx_DUP_STRS_idhrxml_DeleteResponse(c, e);
  }
  {
      struct zx_idhrxml_Notify_s* e;
      for (e = x->idhrxml_Notify; e; e = (struct zx_idhrxml_Notify_s*)e->gg.g.n)
	  zx_DUP_STRS_idhrxml_Notify(c, e);
  }
  {
      struct zx_idhrxml_NotifyResponse_s* e;
      for (e = x->idhrxml_NotifyResponse; e; e = (struct zx_idhrxml_NotifyResponse_s*)e->gg.g.n)
	  zx_DUP_STRS_idhrxml_NotifyResponse(c, e);
  }

}

/* FUNC(zx_DEEP_CLONE_e_Body) */

/* Depth first traversal of data structure to clone it and its sublements.
 * The simple strings are handled as a special case according to dup_strs flag. */

/* Called by: */
struct zx_e_Body_s* zx_DEEP_CLONE_e_Body(struct zx_ctx* c, struct zx_e_Body_s* x, int dup_strs)
{
  x = (struct zx_e_Body_s*)zx_clone_elem_common(c, &x->gg, sizeof(struct zx_e_Body_s), dup_strs);
  /* *** deal with xmlns specifications in exc c14n way */

  x->id = zx_clone_attr(c, x->id);

  {
      struct zx_sp_ArtifactResolve_s* e;
      struct zx_sp_ArtifactResolve_s* en;
      struct zx_sp_ArtifactResolve_s* enn;
      for (enn = 0, e = x->ArtifactResolve; e; e = (struct zx_sp_ArtifactResolve_s*)e->gg.g.n) {
	  en = zx_DEEP_CLONE_sp_ArtifactResolve(c, e, dup_strs);
	  if (!enn)
	      x->ArtifactResolve = en;
	  else
	      enn->gg.g.n = &en->gg.g;
	  enn = en;
      }
  }
  {
      struct zx_sp_ArtifactResponse_s* e;
      struct zx_sp_ArtifactResponse_s* en;
      struct zx_sp_ArtifactResponse_s* enn;
      for (enn = 0, e = x->ArtifactResponse; e; e = (struct zx_sp_ArtifactResponse_s*)e->gg.g.n) {
	  en = zx_DEEP_CLONE_sp_ArtifactResponse(c, e, dup_strs);
	  if (!enn)
	      x->ArtifactResponse = en;
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
      struct zx_sp_NameIDMappingRequest_s* e;
      struct zx_sp_NameIDMappingRequest_s* en;
      struct zx_sp_NameIDMappingRequest_s* enn;
      for (enn = 0, e = x->NameIDMappingRequest; e; e = (struct zx_sp_NameIDMappingRequest_s*)e->gg.g.n) {
	  en = zx_DEEP_CLONE_sp_NameIDMappingRequest(c, e, dup_strs);
	  if (!enn)
	      x->NameIDMappingRequest = en;
	  else
	      enn->gg.g.n = &en->gg.g;
	  enn = en;
      }
  }
  {
      struct zx_sp_NameIDMappingResponse_s* e;
      struct zx_sp_NameIDMappingResponse_s* en;
      struct zx_sp_NameIDMappingResponse_s* enn;
      for (enn = 0, e = x->NameIDMappingResponse; e; e = (struct zx_sp_NameIDMappingResponse_s*)e->gg.g.n) {
	  en = zx_DEEP_CLONE_sp_NameIDMappingResponse(c, e, dup_strs);
	  if (!enn)
	      x->NameIDMappingResponse = en;
	  else
	      enn->gg.g.n = &en->gg.g;
	  enn = en;
      }
  }
  {
      struct zx_sp_AttributeQuery_s* e;
      struct zx_sp_AttributeQuery_s* en;
      struct zx_sp_AttributeQuery_s* enn;
      for (enn = 0, e = x->AttributeQuery; e; e = (struct zx_sp_AttributeQuery_s*)e->gg.g.n) {
	  en = zx_DEEP_CLONE_sp_AttributeQuery(c, e, dup_strs);
	  if (!enn)
	      x->AttributeQuery = en;
	  else
	      enn->gg.g.n = &en->gg.g;
	  enn = en;
      }
  }
  {
      struct zx_sp_AuthnQuery_s* e;
      struct zx_sp_AuthnQuery_s* en;
      struct zx_sp_AuthnQuery_s* enn;
      for (enn = 0, e = x->AuthnQuery; e; e = (struct zx_sp_AuthnQuery_s*)e->gg.g.n) {
	  en = zx_DEEP_CLONE_sp_AuthnQuery(c, e, dup_strs);
	  if (!enn)
	      x->AuthnQuery = en;
	  else
	      enn->gg.g.n = &en->gg.g;
	  enn = en;
      }
  }
  {
      struct zx_sp_AuthzDecisionQuery_s* e;
      struct zx_sp_AuthzDecisionQuery_s* en;
      struct zx_sp_AuthzDecisionQuery_s* enn;
      for (enn = 0, e = x->AuthzDecisionQuery; e; e = (struct zx_sp_AuthzDecisionQuery_s*)e->gg.g.n) {
	  en = zx_DEEP_CLONE_sp_AuthzDecisionQuery(c, e, dup_strs);
	  if (!enn)
	      x->AuthzDecisionQuery = en;
	  else
	      enn->gg.g.n = &en->gg.g;
	  enn = en;
      }
  }
  {
      struct zx_sp_AssertionIDRequest_s* e;
      struct zx_sp_AssertionIDRequest_s* en;
      struct zx_sp_AssertionIDRequest_s* enn;
      for (enn = 0, e = x->AssertionIDRequest; e; e = (struct zx_sp_AssertionIDRequest_s*)e->gg.g.n) {
	  en = zx_DEEP_CLONE_sp_AssertionIDRequest(c, e, dup_strs);
	  if (!enn)
	      x->AssertionIDRequest = en;
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
  {
      struct zx_xac_Request_s* e;
      struct zx_xac_Request_s* en;
      struct zx_xac_Request_s* enn;
      for (enn = 0, e = x->xac_Request; e; e = (struct zx_xac_Request_s*)e->gg.g.n) {
	  en = zx_DEEP_CLONE_xac_Request(c, e, dup_strs);
	  if (!enn)
	      x->xac_Request = en;
	  else
	      enn->gg.g.n = &en->gg.g;
	  enn = en;
      }
  }
  {
      struct zx_xac_Response_s* e;
      struct zx_xac_Response_s* en;
      struct zx_xac_Response_s* enn;
      for (enn = 0, e = x->xac_Response; e; e = (struct zx_xac_Response_s*)e->gg.g.n) {
	  en = zx_DEEP_CLONE_xac_Response(c, e, dup_strs);
	  if (!enn)
	      x->xac_Response = en;
	  else
	      enn->gg.g.n = &en->gg.g;
	  enn = en;
      }
  }
  {
      struct zx_di_Query_s* e;
      struct zx_di_Query_s* en;
      struct zx_di_Query_s* enn;
      for (enn = 0, e = x->Query; e; e = (struct zx_di_Query_s*)e->gg.g.n) {
	  en = zx_DEEP_CLONE_di_Query(c, e, dup_strs);
	  if (!enn)
	      x->Query = en;
	  else
	      enn->gg.g.n = &en->gg.g;
	  enn = en;
      }
  }
  {
      struct zx_di_QueryResponse_s* e;
      struct zx_di_QueryResponse_s* en;
      struct zx_di_QueryResponse_s* enn;
      for (enn = 0, e = x->QueryResponse; e; e = (struct zx_di_QueryResponse_s*)e->gg.g.n) {
	  en = zx_DEEP_CLONE_di_QueryResponse(c, e, dup_strs);
	  if (!enn)
	      x->QueryResponse = en;
	  else
	      enn->gg.g.n = &en->gg.g;
	  enn = en;
      }
  }
  {
      struct zx_di12_Query_s* e;
      struct zx_di12_Query_s* en;
      struct zx_di12_Query_s* enn;
      for (enn = 0, e = x->di12_Query; e; e = (struct zx_di12_Query_s*)e->gg.g.n) {
	  en = zx_DEEP_CLONE_di12_Query(c, e, dup_strs);
	  if (!enn)
	      x->di12_Query = en;
	  else
	      enn->gg.g.n = &en->gg.g;
	  enn = en;
      }
  }
  {
      struct zx_di12_QueryResponse_s* e;
      struct zx_di12_QueryResponse_s* en;
      struct zx_di12_QueryResponse_s* enn;
      for (enn = 0, e = x->di12_QueryResponse; e; e = (struct zx_di12_QueryResponse_s*)e->gg.g.n) {
	  en = zx_DEEP_CLONE_di12_QueryResponse(c, e, dup_strs);
	  if (!enn)
	      x->di12_QueryResponse = en;
	  else
	      enn->gg.g.n = &en->gg.g;
	  enn = en;
      }
  }
  {
      struct zx_di12_Modify_s* e;
      struct zx_di12_Modify_s* en;
      struct zx_di12_Modify_s* enn;
      for (enn = 0, e = x->Modify; e; e = (struct zx_di12_Modify_s*)e->gg.g.n) {
	  en = zx_DEEP_CLONE_di12_Modify(c, e, dup_strs);
	  if (!enn)
	      x->Modify = en;
	  else
	      enn->gg.g.n = &en->gg.g;
	  enn = en;
      }
  }
  {
      struct zx_di12_ModifyResponse_s* e;
      struct zx_di12_ModifyResponse_s* en;
      struct zx_di12_ModifyResponse_s* enn;
      for (enn = 0, e = x->ModifyResponse; e; e = (struct zx_di12_ModifyResponse_s*)e->gg.g.n) {
	  en = zx_DEEP_CLONE_di12_ModifyResponse(c, e, dup_strs);
	  if (!enn)
	      x->ModifyResponse = en;
	  else
	      enn->gg.g.n = &en->gg.g;
	  enn = en;
      }
  }
  {
      struct zx_e_Fault_s* e;
      struct zx_e_Fault_s* en;
      struct zx_e_Fault_s* enn;
      for (enn = 0, e = x->Fault; e; e = (struct zx_e_Fault_s*)e->gg.g.n) {
	  en = zx_DEEP_CLONE_e_Fault(c, e, dup_strs);
	  if (!enn)
	      x->Fault = en;
	  else
	      enn->gg.g.n = &en->gg.g;
	  enn = en;
      }
  }
  {
      struct zx_di_SvcMDAssociationAdd_s* e;
      struct zx_di_SvcMDAssociationAdd_s* en;
      struct zx_di_SvcMDAssociationAdd_s* enn;
      for (enn = 0, e = x->SvcMDAssociationAdd; e; e = (struct zx_di_SvcMDAssociationAdd_s*)e->gg.g.n) {
	  en = zx_DEEP_CLONE_di_SvcMDAssociationAdd(c, e, dup_strs);
	  if (!enn)
	      x->SvcMDAssociationAdd = en;
	  else
	      enn->gg.g.n = &en->gg.g;
	  enn = en;
      }
  }
  {
      struct zx_di_SvcMDAssociationAddResponse_s* e;
      struct zx_di_SvcMDAssociationAddResponse_s* en;
      struct zx_di_SvcMDAssociationAddResponse_s* enn;
      for (enn = 0, e = x->SvcMDAssociationAddResponse; e; e = (struct zx_di_SvcMDAssociationAddResponse_s*)e->gg.g.n) {
	  en = zx_DEEP_CLONE_di_SvcMDAssociationAddResponse(c, e, dup_strs);
	  if (!enn)
	      x->SvcMDAssociationAddResponse = en;
	  else
	      enn->gg.g.n = &en->gg.g;
	  enn = en;
      }
  }
  {
      struct zx_di_SvcMDAssociationDelete_s* e;
      struct zx_di_SvcMDAssociationDelete_s* en;
      struct zx_di_SvcMDAssociationDelete_s* enn;
      for (enn = 0, e = x->SvcMDAssociationDelete; e; e = (struct zx_di_SvcMDAssociationDelete_s*)e->gg.g.n) {
	  en = zx_DEEP_CLONE_di_SvcMDAssociationDelete(c, e, dup_strs);
	  if (!enn)
	      x->SvcMDAssociationDelete = en;
	  else
	      enn->gg.g.n = &en->gg.g;
	  enn = en;
      }
  }
  {
      struct zx_di_SvcMDAssociationDeleteResponse_s* e;
      struct zx_di_SvcMDAssociationDeleteResponse_s* en;
      struct zx_di_SvcMDAssociationDeleteResponse_s* enn;
      for (enn = 0, e = x->SvcMDAssociationDeleteResponse; e; e = (struct zx_di_SvcMDAssociationDeleteResponse_s*)e->gg.g.n) {
	  en = zx_DEEP_CLONE_di_SvcMDAssociationDeleteResponse(c, e, dup_strs);
	  if (!enn)
	      x->SvcMDAssociationDeleteResponse = en;
	  else
	      enn->gg.g.n = &en->gg.g;
	  enn = en;
      }
  }
  {
      struct zx_di_SvcMDAssociationQuery_s* e;
      struct zx_di_SvcMDAssociationQuery_s* en;
      struct zx_di_SvcMDAssociationQuery_s* enn;
      for (enn = 0, e = x->SvcMDAssociationQuery; e; e = (struct zx_di_SvcMDAssociationQuery_s*)e->gg.g.n) {
	  en = zx_DEEP_CLONE_di_SvcMDAssociationQuery(c, e, dup_strs);
	  if (!enn)
	      x->SvcMDAssociationQuery = en;
	  else
	      enn->gg.g.n = &en->gg.g;
	  enn = en;
      }
  }
  {
      struct zx_di_SvcMDAssociationQueryResponse_s* e;
      struct zx_di_SvcMDAssociationQueryResponse_s* en;
      struct zx_di_SvcMDAssociationQueryResponse_s* enn;
      for (enn = 0, e = x->SvcMDAssociationQueryResponse; e; e = (struct zx_di_SvcMDAssociationQueryResponse_s*)e->gg.g.n) {
	  en = zx_DEEP_CLONE_di_SvcMDAssociationQueryResponse(c, e, dup_strs);
	  if (!enn)
	      x->SvcMDAssociationQueryResponse = en;
	  else
	      enn->gg.g.n = &en->gg.g;
	  enn = en;
      }
  }
  {
      struct zx_di_SvcMDRegister_s* e;
      struct zx_di_SvcMDRegister_s* en;
      struct zx_di_SvcMDRegister_s* enn;
      for (enn = 0, e = x->SvcMDRegister; e; e = (struct zx_di_SvcMDRegister_s*)e->gg.g.n) {
	  en = zx_DEEP_CLONE_di_SvcMDRegister(c, e, dup_strs);
	  if (!enn)
	      x->SvcMDRegister = en;
	  else
	      enn->gg.g.n = &en->gg.g;
	  enn = en;
      }
  }
  {
      struct zx_di_SvcMDRegisterResponse_s* e;
      struct zx_di_SvcMDRegisterResponse_s* en;
      struct zx_di_SvcMDRegisterResponse_s* enn;
      for (enn = 0, e = x->SvcMDRegisterResponse; e; e = (struct zx_di_SvcMDRegisterResponse_s*)e->gg.g.n) {
	  en = zx_DEEP_CLONE_di_SvcMDRegisterResponse(c, e, dup_strs);
	  if (!enn)
	      x->SvcMDRegisterResponse = en;
	  else
	      enn->gg.g.n = &en->gg.g;
	  enn = en;
      }
  }
  {
      struct zx_di_SvcMDDelete_s* e;
      struct zx_di_SvcMDDelete_s* en;
      struct zx_di_SvcMDDelete_s* enn;
      for (enn = 0, e = x->SvcMDDelete; e; e = (struct zx_di_SvcMDDelete_s*)e->gg.g.n) {
	  en = zx_DEEP_CLONE_di_SvcMDDelete(c, e, dup_strs);
	  if (!enn)
	      x->SvcMDDelete = en;
	  else
	      enn->gg.g.n = &en->gg.g;
	  enn = en;
      }
  }
  {
      struct zx_di_SvcMDDeleteResponse_s* e;
      struct zx_di_SvcMDDeleteResponse_s* en;
      struct zx_di_SvcMDDeleteResponse_s* enn;
      for (enn = 0, e = x->SvcMDDeleteResponse; e; e = (struct zx_di_SvcMDDeleteResponse_s*)e->gg.g.n) {
	  en = zx_DEEP_CLONE_di_SvcMDDeleteResponse(c, e, dup_strs);
	  if (!enn)
	      x->SvcMDDeleteResponse = en;
	  else
	      enn->gg.g.n = &en->gg.g;
	  enn = en;
      }
  }
  {
      struct zx_di_SvcMDQuery_s* e;
      struct zx_di_SvcMDQuery_s* en;
      struct zx_di_SvcMDQuery_s* enn;
      for (enn = 0, e = x->SvcMDQuery; e; e = (struct zx_di_SvcMDQuery_s*)e->gg.g.n) {
	  en = zx_DEEP_CLONE_di_SvcMDQuery(c, e, dup_strs);
	  if (!enn)
	      x->SvcMDQuery = en;
	  else
	      enn->gg.g.n = &en->gg.g;
	  enn = en;
      }
  }
  {
      struct zx_di_SvcMDQueryResponse_s* e;
      struct zx_di_SvcMDQueryResponse_s* en;
      struct zx_di_SvcMDQueryResponse_s* enn;
      for (enn = 0, e = x->SvcMDQueryResponse; e; e = (struct zx_di_SvcMDQueryResponse_s*)e->gg.g.n) {
	  en = zx_DEEP_CLONE_di_SvcMDQueryResponse(c, e, dup_strs);
	  if (!enn)
	      x->SvcMDQueryResponse = en;
	  else
	      enn->gg.g.n = &en->gg.g;
	  enn = en;
      }
  }
  {
      struct zx_di_SvcMDReplace_s* e;
      struct zx_di_SvcMDReplace_s* en;
      struct zx_di_SvcMDReplace_s* enn;
      for (enn = 0, e = x->SvcMDReplace; e; e = (struct zx_di_SvcMDReplace_s*)e->gg.g.n) {
	  en = zx_DEEP_CLONE_di_SvcMDReplace(c, e, dup_strs);
	  if (!enn)
	      x->SvcMDReplace = en;
	  else
	      enn->gg.g.n = &en->gg.g;
	  enn = en;
      }
  }
  {
      struct zx_di_SvcMDReplaceResponse_s* e;
      struct zx_di_SvcMDReplaceResponse_s* en;
      struct zx_di_SvcMDReplaceResponse_s* enn;
      for (enn = 0, e = x->SvcMDReplaceResponse; e; e = (struct zx_di_SvcMDReplaceResponse_s*)e->gg.g.n) {
	  en = zx_DEEP_CLONE_di_SvcMDReplaceResponse(c, e, dup_strs);
	  if (!enn)
	      x->SvcMDReplaceResponse = en;
	  else
	      enn->gg.g.n = &en->gg.g;
	  enn = en;
      }
  }
  {
      struct zx_dap_Create_s* e;
      struct zx_dap_Create_s* en;
      struct zx_dap_Create_s* enn;
      for (enn = 0, e = x->Create; e; e = (struct zx_dap_Create_s*)e->gg.g.n) {
	  en = zx_DEEP_CLONE_dap_Create(c, e, dup_strs);
	  if (!enn)
	      x->Create = en;
	  else
	      enn->gg.g.n = &en->gg.g;
	  enn = en;
      }
  }
  {
      struct zx_dap_CreateResponse_s* e;
      struct zx_dap_CreateResponse_s* en;
      struct zx_dap_CreateResponse_s* enn;
      for (enn = 0, e = x->CreateResponse; e; e = (struct zx_dap_CreateResponse_s*)e->gg.g.n) {
	  en = zx_DEEP_CLONE_dap_CreateResponse(c, e, dup_strs);
	  if (!enn)
	      x->CreateResponse = en;
	  else
	      enn->gg.g.n = &en->gg.g;
	  enn = en;
      }
  }
  {
      struct zx_dap_Query_s* e;
      struct zx_dap_Query_s* en;
      struct zx_dap_Query_s* enn;
      for (enn = 0, e = x->dap_Query; e; e = (struct zx_dap_Query_s*)e->gg.g.n) {
	  en = zx_DEEP_CLONE_dap_Query(c, e, dup_strs);
	  if (!enn)
	      x->dap_Query = en;
	  else
	      enn->gg.g.n = &en->gg.g;
	  enn = en;
      }
  }
  {
      struct zx_dap_QueryResponse_s* e;
      struct zx_dap_QueryResponse_s* en;
      struct zx_dap_QueryResponse_s* enn;
      for (enn = 0, e = x->dap_QueryResponse; e; e = (struct zx_dap_QueryResponse_s*)e->gg.g.n) {
	  en = zx_DEEP_CLONE_dap_QueryResponse(c, e, dup_strs);
	  if (!enn)
	      x->dap_QueryResponse = en;
	  else
	      enn->gg.g.n = &en->gg.g;
	  enn = en;
      }
  }
  {
      struct zx_dap_Modify_s* e;
      struct zx_dap_Modify_s* en;
      struct zx_dap_Modify_s* enn;
      for (enn = 0, e = x->dap_Modify; e; e = (struct zx_dap_Modify_s*)e->gg.g.n) {
	  en = zx_DEEP_CLONE_dap_Modify(c, e, dup_strs);
	  if (!enn)
	      x->dap_Modify = en;
	  else
	      enn->gg.g.n = &en->gg.g;
	  enn = en;
      }
  }
  {
      struct zx_dap_ModifyResponse_s* e;
      struct zx_dap_ModifyResponse_s* en;
      struct zx_dap_ModifyResponse_s* enn;
      for (enn = 0, e = x->dap_ModifyResponse; e; e = (struct zx_dap_ModifyResponse_s*)e->gg.g.n) {
	  en = zx_DEEP_CLONE_dap_ModifyResponse(c, e, dup_strs);
	  if (!enn)
	      x->dap_ModifyResponse = en;
	  else
	      enn->gg.g.n = &en->gg.g;
	  enn = en;
      }
  }
  {
      struct zx_dap_Delete_s* e;
      struct zx_dap_Delete_s* en;
      struct zx_dap_Delete_s* enn;
      for (enn = 0, e = x->Delete; e; e = (struct zx_dap_Delete_s*)e->gg.g.n) {
	  en = zx_DEEP_CLONE_dap_Delete(c, e, dup_strs);
	  if (!enn)
	      x->Delete = en;
	  else
	      enn->gg.g.n = &en->gg.g;
	  enn = en;
      }
  }
  {
      struct zx_dap_DeleteResponse_s* e;
      struct zx_dap_DeleteResponse_s* en;
      struct zx_dap_DeleteResponse_s* enn;
      for (enn = 0, e = x->DeleteResponse; e; e = (struct zx_dap_DeleteResponse_s*)e->gg.g.n) {
	  en = zx_DEEP_CLONE_dap_DeleteResponse(c, e, dup_strs);
	  if (!enn)
	      x->DeleteResponse = en;
	  else
	      enn->gg.g.n = &en->gg.g;
	  enn = en;
      }
  }
  {
      struct zx_dap_Notify_s* e;
      struct zx_dap_Notify_s* en;
      struct zx_dap_Notify_s* enn;
      for (enn = 0, e = x->Notify; e; e = (struct zx_dap_Notify_s*)e->gg.g.n) {
	  en = zx_DEEP_CLONE_dap_Notify(c, e, dup_strs);
	  if (!enn)
	      x->Notify = en;
	  else
	      enn->gg.g.n = &en->gg.g;
	  enn = en;
      }
  }
  {
      struct zx_dap_NotifyResponse_s* e;
      struct zx_dap_NotifyResponse_s* en;
      struct zx_dap_NotifyResponse_s* enn;
      for (enn = 0, e = x->NotifyResponse; e; e = (struct zx_dap_NotifyResponse_s*)e->gg.g.n) {
	  en = zx_DEEP_CLONE_dap_NotifyResponse(c, e, dup_strs);
	  if (!enn)
	      x->NotifyResponse = en;
	  else
	      enn->gg.g.n = &en->gg.g;
	  enn = en;
      }
  }
  {
      struct zx_ps_AddEntityRequest_s* e;
      struct zx_ps_AddEntityRequest_s* en;
      struct zx_ps_AddEntityRequest_s* enn;
      for (enn = 0, e = x->AddEntityRequest; e; e = (struct zx_ps_AddEntityRequest_s*)e->gg.g.n) {
	  en = zx_DEEP_CLONE_ps_AddEntityRequest(c, e, dup_strs);
	  if (!enn)
	      x->AddEntityRequest = en;
	  else
	      enn->gg.g.n = &en->gg.g;
	  enn = en;
      }
  }
  {
      struct zx_ps_AddEntityResponse_s* e;
      struct zx_ps_AddEntityResponse_s* en;
      struct zx_ps_AddEntityResponse_s* enn;
      for (enn = 0, e = x->AddEntityResponse; e; e = (struct zx_ps_AddEntityResponse_s*)e->gg.g.n) {
	  en = zx_DEEP_CLONE_ps_AddEntityResponse(c, e, dup_strs);
	  if (!enn)
	      x->AddEntityResponse = en;
	  else
	      enn->gg.g.n = &en->gg.g;
	  enn = en;
      }
  }
  {
      struct zx_ps_AddKnownEntityRequest_s* e;
      struct zx_ps_AddKnownEntityRequest_s* en;
      struct zx_ps_AddKnownEntityRequest_s* enn;
      for (enn = 0, e = x->AddKnownEntityRequest; e; e = (struct zx_ps_AddKnownEntityRequest_s*)e->gg.g.n) {
	  en = zx_DEEP_CLONE_ps_AddKnownEntityRequest(c, e, dup_strs);
	  if (!enn)
	      x->AddKnownEntityRequest = en;
	  else
	      enn->gg.g.n = &en->gg.g;
	  enn = en;
      }
  }
  {
      struct zx_ps_AddKnownEntityResponse_s* e;
      struct zx_ps_AddKnownEntityResponse_s* en;
      struct zx_ps_AddKnownEntityResponse_s* enn;
      for (enn = 0, e = x->AddKnownEntityResponse; e; e = (struct zx_ps_AddKnownEntityResponse_s*)e->gg.g.n) {
	  en = zx_DEEP_CLONE_ps_AddKnownEntityResponse(c, e, dup_strs);
	  if (!enn)
	      x->AddKnownEntityResponse = en;
	  else
	      enn->gg.g.n = &en->gg.g;
	  enn = en;
      }
  }
  {
      struct zx_ps_AddCollectionRequest_s* e;
      struct zx_ps_AddCollectionRequest_s* en;
      struct zx_ps_AddCollectionRequest_s* enn;
      for (enn = 0, e = x->AddCollectionRequest; e; e = (struct zx_ps_AddCollectionRequest_s*)e->gg.g.n) {
	  en = zx_DEEP_CLONE_ps_AddCollectionRequest(c, e, dup_strs);
	  if (!enn)
	      x->AddCollectionRequest = en;
	  else
	      enn->gg.g.n = &en->gg.g;
	  enn = en;
      }
  }
  {
      struct zx_ps_AddCollectionResponse_s* e;
      struct zx_ps_AddCollectionResponse_s* en;
      struct zx_ps_AddCollectionResponse_s* enn;
      for (enn = 0, e = x->AddCollectionResponse; e; e = (struct zx_ps_AddCollectionResponse_s*)e->gg.g.n) {
	  en = zx_DEEP_CLONE_ps_AddCollectionResponse(c, e, dup_strs);
	  if (!enn)
	      x->AddCollectionResponse = en;
	  else
	      enn->gg.g.n = &en->gg.g;
	  enn = en;
      }
  }
  {
      struct zx_ps_AddToCollectionRequest_s* e;
      struct zx_ps_AddToCollectionRequest_s* en;
      struct zx_ps_AddToCollectionRequest_s* enn;
      for (enn = 0, e = x->AddToCollectionRequest; e; e = (struct zx_ps_AddToCollectionRequest_s*)e->gg.g.n) {
	  en = zx_DEEP_CLONE_ps_AddToCollectionRequest(c, e, dup_strs);
	  if (!enn)
	      x->AddToCollectionRequest = en;
	  else
	      enn->gg.g.n = &en->gg.g;
	  enn = en;
      }
  }
  {
      struct zx_ps_AddToCollectionResponse_s* e;
      struct zx_ps_AddToCollectionResponse_s* en;
      struct zx_ps_AddToCollectionResponse_s* enn;
      for (enn = 0, e = x->AddToCollectionResponse; e; e = (struct zx_ps_AddToCollectionResponse_s*)e->gg.g.n) {
	  en = zx_DEEP_CLONE_ps_AddToCollectionResponse(c, e, dup_strs);
	  if (!enn)
	      x->AddToCollectionResponse = en;
	  else
	      enn->gg.g.n = &en->gg.g;
	  enn = en;
      }
  }
  {
      struct zx_ps_RemoveEntityRequest_s* e;
      struct zx_ps_RemoveEntityRequest_s* en;
      struct zx_ps_RemoveEntityRequest_s* enn;
      for (enn = 0, e = x->RemoveEntityRequest; e; e = (struct zx_ps_RemoveEntityRequest_s*)e->gg.g.n) {
	  en = zx_DEEP_CLONE_ps_RemoveEntityRequest(c, e, dup_strs);
	  if (!enn)
	      x->RemoveEntityRequest = en;
	  else
	      enn->gg.g.n = &en->gg.g;
	  enn = en;
      }
  }
  {
      struct zx_ps_RemoveEntityResponse_s* e;
      struct zx_ps_RemoveEntityResponse_s* en;
      struct zx_ps_RemoveEntityResponse_s* enn;
      for (enn = 0, e = x->RemoveEntityResponse; e; e = (struct zx_ps_RemoveEntityResponse_s*)e->gg.g.n) {
	  en = zx_DEEP_CLONE_ps_RemoveEntityResponse(c, e, dup_strs);
	  if (!enn)
	      x->RemoveEntityResponse = en;
	  else
	      enn->gg.g.n = &en->gg.g;
	  enn = en;
      }
  }
  {
      struct zx_ps_RemoveCollectionRequest_s* e;
      struct zx_ps_RemoveCollectionRequest_s* en;
      struct zx_ps_RemoveCollectionRequest_s* enn;
      for (enn = 0, e = x->RemoveCollectionRequest; e; e = (struct zx_ps_RemoveCollectionRequest_s*)e->gg.g.n) {
	  en = zx_DEEP_CLONE_ps_RemoveCollectionRequest(c, e, dup_strs);
	  if (!enn)
	      x->RemoveCollectionRequest = en;
	  else
	      enn->gg.g.n = &en->gg.g;
	  enn = en;
      }
  }
  {
      struct zx_ps_RemoveCollectionResponse_s* e;
      struct zx_ps_RemoveCollectionResponse_s* en;
      struct zx_ps_RemoveCollectionResponse_s* enn;
      for (enn = 0, e = x->RemoveCollectionResponse; e; e = (struct zx_ps_RemoveCollectionResponse_s*)e->gg.g.n) {
	  en = zx_DEEP_CLONE_ps_RemoveCollectionResponse(c, e, dup_strs);
	  if (!enn)
	      x->RemoveCollectionResponse = en;
	  else
	      enn->gg.g.n = &en->gg.g;
	  enn = en;
      }
  }
  {
      struct zx_ps_RemoveFromCollectionRequest_s* e;
      struct zx_ps_RemoveFromCollectionRequest_s* en;
      struct zx_ps_RemoveFromCollectionRequest_s* enn;
      for (enn = 0, e = x->RemoveFromCollectionRequest; e; e = (struct zx_ps_RemoveFromCollectionRequest_s*)e->gg.g.n) {
	  en = zx_DEEP_CLONE_ps_RemoveFromCollectionRequest(c, e, dup_strs);
	  if (!enn)
	      x->RemoveFromCollectionRequest = en;
	  else
	      enn->gg.g.n = &en->gg.g;
	  enn = en;
      }
  }
  {
      struct zx_ps_RemoveFromCollectionResponse_s* e;
      struct zx_ps_RemoveFromCollectionResponse_s* en;
      struct zx_ps_RemoveFromCollectionResponse_s* enn;
      for (enn = 0, e = x->RemoveFromCollectionResponse; e; e = (struct zx_ps_RemoveFromCollectionResponse_s*)e->gg.g.n) {
	  en = zx_DEEP_CLONE_ps_RemoveFromCollectionResponse(c, e, dup_strs);
	  if (!enn)
	      x->RemoveFromCollectionResponse = en;
	  else
	      enn->gg.g.n = &en->gg.g;
	  enn = en;
      }
  }
  {
      struct zx_ps_ListMembersRequest_s* e;
      struct zx_ps_ListMembersRequest_s* en;
      struct zx_ps_ListMembersRequest_s* enn;
      for (enn = 0, e = x->ListMembersRequest; e; e = (struct zx_ps_ListMembersRequest_s*)e->gg.g.n) {
	  en = zx_DEEP_CLONE_ps_ListMembersRequest(c, e, dup_strs);
	  if (!enn)
	      x->ListMembersRequest = en;
	  else
	      enn->gg.g.n = &en->gg.g;
	  enn = en;
      }
  }
  {
      struct zx_ps_ListMembersResponse_s* e;
      struct zx_ps_ListMembersResponse_s* en;
      struct zx_ps_ListMembersResponse_s* enn;
      for (enn = 0, e = x->ListMembersResponse; e; e = (struct zx_ps_ListMembersResponse_s*)e->gg.g.n) {
	  en = zx_DEEP_CLONE_ps_ListMembersResponse(c, e, dup_strs);
	  if (!enn)
	      x->ListMembersResponse = en;
	  else
	      enn->gg.g.n = &en->gg.g;
	  enn = en;
      }
  }
  {
      struct zx_ps_QueryObjectsRequest_s* e;
      struct zx_ps_QueryObjectsRequest_s* en;
      struct zx_ps_QueryObjectsRequest_s* enn;
      for (enn = 0, e = x->QueryObjectsRequest; e; e = (struct zx_ps_QueryObjectsRequest_s*)e->gg.g.n) {
	  en = zx_DEEP_CLONE_ps_QueryObjectsRequest(c, e, dup_strs);
	  if (!enn)
	      x->QueryObjectsRequest = en;
	  else
	      enn->gg.g.n = &en->gg.g;
	  enn = en;
      }
  }
  {
      struct zx_ps_QueryObjectsResponse_s* e;
      struct zx_ps_QueryObjectsResponse_s* en;
      struct zx_ps_QueryObjectsResponse_s* enn;
      for (enn = 0, e = x->QueryObjectsResponse; e; e = (struct zx_ps_QueryObjectsResponse_s*)e->gg.g.n) {
	  en = zx_DEEP_CLONE_ps_QueryObjectsResponse(c, e, dup_strs);
	  if (!enn)
	      x->QueryObjectsResponse = en;
	  else
	      enn->gg.g.n = &en->gg.g;
	  enn = en;
      }
  }
  {
      struct zx_ps_GetObjectInfoRequest_s* e;
      struct zx_ps_GetObjectInfoRequest_s* en;
      struct zx_ps_GetObjectInfoRequest_s* enn;
      for (enn = 0, e = x->GetObjectInfoRequest; e; e = (struct zx_ps_GetObjectInfoRequest_s*)e->gg.g.n) {
	  en = zx_DEEP_CLONE_ps_GetObjectInfoRequest(c, e, dup_strs);
	  if (!enn)
	      x->GetObjectInfoRequest = en;
	  else
	      enn->gg.g.n = &en->gg.g;
	  enn = en;
      }
  }
  {
      struct zx_ps_GetObjectInfoResponse_s* e;
      struct zx_ps_GetObjectInfoResponse_s* en;
      struct zx_ps_GetObjectInfoResponse_s* enn;
      for (enn = 0, e = x->GetObjectInfoResponse; e; e = (struct zx_ps_GetObjectInfoResponse_s*)e->gg.g.n) {
	  en = zx_DEEP_CLONE_ps_GetObjectInfoResponse(c, e, dup_strs);
	  if (!enn)
	      x->GetObjectInfoResponse = en;
	  else
	      enn->gg.g.n = &en->gg.g;
	  enn = en;
      }
  }
  {
      struct zx_ps_SetObjectInfoRequest_s* e;
      struct zx_ps_SetObjectInfoRequest_s* en;
      struct zx_ps_SetObjectInfoRequest_s* enn;
      for (enn = 0, e = x->SetObjectInfoRequest; e; e = (struct zx_ps_SetObjectInfoRequest_s*)e->gg.g.n) {
	  en = zx_DEEP_CLONE_ps_SetObjectInfoRequest(c, e, dup_strs);
	  if (!enn)
	      x->SetObjectInfoRequest = en;
	  else
	      enn->gg.g.n = &en->gg.g;
	  enn = en;
      }
  }
  {
      struct zx_ps_SetObjectInfoResponse_s* e;
      struct zx_ps_SetObjectInfoResponse_s* en;
      struct zx_ps_SetObjectInfoResponse_s* enn;
      for (enn = 0, e = x->SetObjectInfoResponse; e; e = (struct zx_ps_SetObjectInfoResponse_s*)e->gg.g.n) {
	  en = zx_DEEP_CLONE_ps_SetObjectInfoResponse(c, e, dup_strs);
	  if (!enn)
	      x->SetObjectInfoResponse = en;
	  else
	      enn->gg.g.n = &en->gg.g;
	  enn = en;
      }
  }
  {
      struct zx_ps_TestMembershipRequest_s* e;
      struct zx_ps_TestMembershipRequest_s* en;
      struct zx_ps_TestMembershipRequest_s* enn;
      for (enn = 0, e = x->TestMembershipRequest; e; e = (struct zx_ps_TestMembershipRequest_s*)e->gg.g.n) {
	  en = zx_DEEP_CLONE_ps_TestMembershipRequest(c, e, dup_strs);
	  if (!enn)
	      x->TestMembershipRequest = en;
	  else
	      enn->gg.g.n = &en->gg.g;
	  enn = en;
      }
  }
  {
      struct zx_ps_TestMembershipResponse_s* e;
      struct zx_ps_TestMembershipResponse_s* en;
      struct zx_ps_TestMembershipResponse_s* enn;
      for (enn = 0, e = x->TestMembershipResponse; e; e = (struct zx_ps_TestMembershipResponse_s*)e->gg.g.n) {
	  en = zx_DEEP_CLONE_ps_TestMembershipResponse(c, e, dup_strs);
	  if (!enn)
	      x->TestMembershipResponse = en;
	  else
	      enn->gg.g.n = &en->gg.g;
	  enn = en;
      }
  }
  {
      struct zx_ps_ResolveIdentifierRequest_s* e;
      struct zx_ps_ResolveIdentifierRequest_s* en;
      struct zx_ps_ResolveIdentifierRequest_s* enn;
      for (enn = 0, e = x->ResolveIdentifierRequest; e; e = (struct zx_ps_ResolveIdentifierRequest_s*)e->gg.g.n) {
	  en = zx_DEEP_CLONE_ps_ResolveIdentifierRequest(c, e, dup_strs);
	  if (!enn)
	      x->ResolveIdentifierRequest = en;
	  else
	      enn->gg.g.n = &en->gg.g;
	  enn = en;
      }
  }
  {
      struct zx_ps_ResolveIdentifierResponse_s* e;
      struct zx_ps_ResolveIdentifierResponse_s* en;
      struct zx_ps_ResolveIdentifierResponse_s* enn;
      for (enn = 0, e = x->ResolveIdentifierResponse; e; e = (struct zx_ps_ResolveIdentifierResponse_s*)e->gg.g.n) {
	  en = zx_DEEP_CLONE_ps_ResolveIdentifierResponse(c, e, dup_strs);
	  if (!enn)
	      x->ResolveIdentifierResponse = en;
	  else
	      enn->gg.g.n = &en->gg.g;
	  enn = en;
      }
  }
  {
      struct zx_ps_Notify_s* e;
      struct zx_ps_Notify_s* en;
      struct zx_ps_Notify_s* enn;
      for (enn = 0, e = x->ps_Notify; e; e = (struct zx_ps_Notify_s*)e->gg.g.n) {
	  en = zx_DEEP_CLONE_ps_Notify(c, e, dup_strs);
	  if (!enn)
	      x->ps_Notify = en;
	  else
	      enn->gg.g.n = &en->gg.g;
	  enn = en;
      }
  }
  {
      struct zx_ps_NotifyResponse_s* e;
      struct zx_ps_NotifyResponse_s* en;
      struct zx_ps_NotifyResponse_s* enn;
      for (enn = 0, e = x->ps_NotifyResponse; e; e = (struct zx_ps_NotifyResponse_s*)e->gg.g.n) {
	  en = zx_DEEP_CLONE_ps_NotifyResponse(c, e, dup_strs);
	  if (!enn)
	      x->ps_NotifyResponse = en;
	  else
	      enn->gg.g.n = &en->gg.g;
	  enn = en;
      }
  }
  {
      struct zx_im_IdentityMappingRequest_s* e;
      struct zx_im_IdentityMappingRequest_s* en;
      struct zx_im_IdentityMappingRequest_s* enn;
      for (enn = 0, e = x->IdentityMappingRequest; e; e = (struct zx_im_IdentityMappingRequest_s*)e->gg.g.n) {
	  en = zx_DEEP_CLONE_im_IdentityMappingRequest(c, e, dup_strs);
	  if (!enn)
	      x->IdentityMappingRequest = en;
	  else
	      enn->gg.g.n = &en->gg.g;
	  enn = en;
      }
  }
  {
      struct zx_im_IdentityMappingResponse_s* e;
      struct zx_im_IdentityMappingResponse_s* en;
      struct zx_im_IdentityMappingResponse_s* enn;
      for (enn = 0, e = x->IdentityMappingResponse; e; e = (struct zx_im_IdentityMappingResponse_s*)e->gg.g.n) {
	  en = zx_DEEP_CLONE_im_IdentityMappingResponse(c, e, dup_strs);
	  if (!enn)
	      x->IdentityMappingResponse = en;
	  else
	      enn->gg.g.n = &en->gg.g;
	  enn = en;
      }
  }
  {
      struct zx_as_SASLRequest_s* e;
      struct zx_as_SASLRequest_s* en;
      struct zx_as_SASLRequest_s* enn;
      for (enn = 0, e = x->SASLRequest; e; e = (struct zx_as_SASLRequest_s*)e->gg.g.n) {
	  en = zx_DEEP_CLONE_as_SASLRequest(c, e, dup_strs);
	  if (!enn)
	      x->SASLRequest = en;
	  else
	      enn->gg.g.n = &en->gg.g;
	  enn = en;
      }
  }
  {
      struct zx_as_SASLResponse_s* e;
      struct zx_as_SASLResponse_s* en;
      struct zx_as_SASLResponse_s* enn;
      for (enn = 0, e = x->SASLResponse; e; e = (struct zx_as_SASLResponse_s*)e->gg.g.n) {
	  en = zx_DEEP_CLONE_as_SASLResponse(c, e, dup_strs);
	  if (!enn)
	      x->SASLResponse = en;
	  else
	      enn->gg.g.n = &en->gg.g;
	  enn = en;
      }
  }
  {
      struct zx_mm7_SubmitReq_s* e;
      struct zx_mm7_SubmitReq_s* en;
      struct zx_mm7_SubmitReq_s* enn;
      for (enn = 0, e = x->SubmitReq; e; e = (struct zx_mm7_SubmitReq_s*)e->gg.g.n) {
	  en = zx_DEEP_CLONE_mm7_SubmitReq(c, e, dup_strs);
	  if (!enn)
	      x->SubmitReq = en;
	  else
	      enn->gg.g.n = &en->gg.g;
	  enn = en;
      }
  }
  {
      struct zx_mm7_SubmitRsp_s* e;
      struct zx_mm7_SubmitRsp_s* en;
      struct zx_mm7_SubmitRsp_s* enn;
      for (enn = 0, e = x->SubmitRsp; e; e = (struct zx_mm7_SubmitRsp_s*)e->gg.g.n) {
	  en = zx_DEEP_CLONE_mm7_SubmitRsp(c, e, dup_strs);
	  if (!enn)
	      x->SubmitRsp = en;
	  else
	      enn->gg.g.n = &en->gg.g;
	  enn = en;
      }
  }
  {
      struct zx_mm7_DeliverReq_s* e;
      struct zx_mm7_DeliverReq_s* en;
      struct zx_mm7_DeliverReq_s* enn;
      for (enn = 0, e = x->DeliverReq; e; e = (struct zx_mm7_DeliverReq_s*)e->gg.g.n) {
	  en = zx_DEEP_CLONE_mm7_DeliverReq(c, e, dup_strs);
	  if (!enn)
	      x->DeliverReq = en;
	  else
	      enn->gg.g.n = &en->gg.g;
	  enn = en;
      }
  }
  {
      struct zx_mm7_DeliverRsp_s* e;
      struct zx_mm7_DeliverRsp_s* en;
      struct zx_mm7_DeliverRsp_s* enn;
      for (enn = 0, e = x->DeliverRsp; e; e = (struct zx_mm7_DeliverRsp_s*)e->gg.g.n) {
	  en = zx_DEEP_CLONE_mm7_DeliverRsp(c, e, dup_strs);
	  if (!enn)
	      x->DeliverRsp = en;
	  else
	      enn->gg.g.n = &en->gg.g;
	  enn = en;
      }
  }
  {
      struct zx_mm7_CancelReq_s* e;
      struct zx_mm7_CancelReq_s* en;
      struct zx_mm7_CancelReq_s* enn;
      for (enn = 0, e = x->CancelReq; e; e = (struct zx_mm7_CancelReq_s*)e->gg.g.n) {
	  en = zx_DEEP_CLONE_mm7_CancelReq(c, e, dup_strs);
	  if (!enn)
	      x->CancelReq = en;
	  else
	      enn->gg.g.n = &en->gg.g;
	  enn = en;
      }
  }
  {
      struct zx_mm7_CancelRsp_s* e;
      struct zx_mm7_CancelRsp_s* en;
      struct zx_mm7_CancelRsp_s* enn;
      for (enn = 0, e = x->CancelRsp; e; e = (struct zx_mm7_CancelRsp_s*)e->gg.g.n) {
	  en = zx_DEEP_CLONE_mm7_CancelRsp(c, e, dup_strs);
	  if (!enn)
	      x->CancelRsp = en;
	  else
	      enn->gg.g.n = &en->gg.g;
	  enn = en;
      }
  }
  {
      struct zx_mm7_ReplaceReq_s* e;
      struct zx_mm7_ReplaceReq_s* en;
      struct zx_mm7_ReplaceReq_s* enn;
      for (enn = 0, e = x->ReplaceReq; e; e = (struct zx_mm7_ReplaceReq_s*)e->gg.g.n) {
	  en = zx_DEEP_CLONE_mm7_ReplaceReq(c, e, dup_strs);
	  if (!enn)
	      x->ReplaceReq = en;
	  else
	      enn->gg.g.n = &en->gg.g;
	  enn = en;
      }
  }
  {
      struct zx_mm7_ReplaceRsp_s* e;
      struct zx_mm7_ReplaceRsp_s* en;
      struct zx_mm7_ReplaceRsp_s* enn;
      for (enn = 0, e = x->ReplaceRsp; e; e = (struct zx_mm7_ReplaceRsp_s*)e->gg.g.n) {
	  en = zx_DEEP_CLONE_mm7_ReplaceRsp(c, e, dup_strs);
	  if (!enn)
	      x->ReplaceRsp = en;
	  else
	      enn->gg.g.n = &en->gg.g;
	  enn = en;
      }
  }
  {
      struct zx_mm7_extendedCancelReq_s* e;
      struct zx_mm7_extendedCancelReq_s* en;
      struct zx_mm7_extendedCancelReq_s* enn;
      for (enn = 0, e = x->extendedCancelReq; e; e = (struct zx_mm7_extendedCancelReq_s*)e->gg.g.n) {
	  en = zx_DEEP_CLONE_mm7_extendedCancelReq(c, e, dup_strs);
	  if (!enn)
	      x->extendedCancelReq = en;
	  else
	      enn->gg.g.n = &en->gg.g;
	  enn = en;
      }
  }
  {
      struct zx_mm7_extendedCancelRsp_s* e;
      struct zx_mm7_extendedCancelRsp_s* en;
      struct zx_mm7_extendedCancelRsp_s* enn;
      for (enn = 0, e = x->extendedCancelRsp; e; e = (struct zx_mm7_extendedCancelRsp_s*)e->gg.g.n) {
	  en = zx_DEEP_CLONE_mm7_extendedCancelRsp(c, e, dup_strs);
	  if (!enn)
	      x->extendedCancelRsp = en;
	  else
	      enn->gg.g.n = &en->gg.g;
	  enn = en;
      }
  }
  {
      struct zx_mm7_extendedReplaceReq_s* e;
      struct zx_mm7_extendedReplaceReq_s* en;
      struct zx_mm7_extendedReplaceReq_s* enn;
      for (enn = 0, e = x->extendedReplaceReq; e; e = (struct zx_mm7_extendedReplaceReq_s*)e->gg.g.n) {
	  en = zx_DEEP_CLONE_mm7_extendedReplaceReq(c, e, dup_strs);
	  if (!enn)
	      x->extendedReplaceReq = en;
	  else
	      enn->gg.g.n = &en->gg.g;
	  enn = en;
      }
  }
  {
      struct zx_mm7_extendedReplaceRsp_s* e;
      struct zx_mm7_extendedReplaceRsp_s* en;
      struct zx_mm7_extendedReplaceRsp_s* enn;
      for (enn = 0, e = x->extendedReplaceRsp; e; e = (struct zx_mm7_extendedReplaceRsp_s*)e->gg.g.n) {
	  en = zx_DEEP_CLONE_mm7_extendedReplaceRsp(c, e, dup_strs);
	  if (!enn)
	      x->extendedReplaceRsp = en;
	  else
	      enn->gg.g.n = &en->gg.g;
	  enn = en;
      }
  }
  {
      struct zx_mm7_DeliveryReportReq_s* e;
      struct zx_mm7_DeliveryReportReq_s* en;
      struct zx_mm7_DeliveryReportReq_s* enn;
      for (enn = 0, e = x->DeliveryReportReq; e; e = (struct zx_mm7_DeliveryReportReq_s*)e->gg.g.n) {
	  en = zx_DEEP_CLONE_mm7_DeliveryReportReq(c, e, dup_strs);
	  if (!enn)
	      x->DeliveryReportReq = en;
	  else
	      enn->gg.g.n = &en->gg.g;
	  enn = en;
      }
  }
  {
      struct zx_mm7_DeliveryReportRsp_s* e;
      struct zx_mm7_DeliveryReportRsp_s* en;
      struct zx_mm7_DeliveryReportRsp_s* enn;
      for (enn = 0, e = x->DeliveryReportRsp; e; e = (struct zx_mm7_DeliveryReportRsp_s*)e->gg.g.n) {
	  en = zx_DEEP_CLONE_mm7_DeliveryReportRsp(c, e, dup_strs);
	  if (!enn)
	      x->DeliveryReportRsp = en;
	  else
	      enn->gg.g.n = &en->gg.g;
	  enn = en;
      }
  }
  {
      struct zx_mm7_ReadReplyReq_s* e;
      struct zx_mm7_ReadReplyReq_s* en;
      struct zx_mm7_ReadReplyReq_s* enn;
      for (enn = 0, e = x->ReadReplyReq; e; e = (struct zx_mm7_ReadReplyReq_s*)e->gg.g.n) {
	  en = zx_DEEP_CLONE_mm7_ReadReplyReq(c, e, dup_strs);
	  if (!enn)
	      x->ReadReplyReq = en;
	  else
	      enn->gg.g.n = &en->gg.g;
	  enn = en;
      }
  }
  {
      struct zx_mm7_ReadReplyRsp_s* e;
      struct zx_mm7_ReadReplyRsp_s* en;
      struct zx_mm7_ReadReplyRsp_s* enn;
      for (enn = 0, e = x->ReadReplyRsp; e; e = (struct zx_mm7_ReadReplyRsp_s*)e->gg.g.n) {
	  en = zx_DEEP_CLONE_mm7_ReadReplyRsp(c, e, dup_strs);
	  if (!enn)
	      x->ReadReplyRsp = en;
	  else
	      enn->gg.g.n = &en->gg.g;
	  enn = en;
      }
  }
  {
      struct zx_mm7_RSErrorRsp_s* e;
      struct zx_mm7_RSErrorRsp_s* en;
      struct zx_mm7_RSErrorRsp_s* enn;
      for (enn = 0, e = x->RSErrorRsp; e; e = (struct zx_mm7_RSErrorRsp_s*)e->gg.g.n) {
	  en = zx_DEEP_CLONE_mm7_RSErrorRsp(c, e, dup_strs);
	  if (!enn)
	      x->RSErrorRsp = en;
	  else
	      enn->gg.g.n = &en->gg.g;
	  enn = en;
      }
  }
  {
      struct zx_mm7_VASPErrorRsp_s* e;
      struct zx_mm7_VASPErrorRsp_s* en;
      struct zx_mm7_VASPErrorRsp_s* enn;
      for (enn = 0, e = x->VASPErrorRsp; e; e = (struct zx_mm7_VASPErrorRsp_s*)e->gg.g.n) {
	  en = zx_DEEP_CLONE_mm7_VASPErrorRsp(c, e, dup_strs);
	  if (!enn)
	      x->VASPErrorRsp = en;
	  else
	      enn->gg.g.n = &en->gg.g;
	  enn = en;
      }
  }
  {
      struct zx_mm7_QueryStatusReq_s* e;
      struct zx_mm7_QueryStatusReq_s* en;
      struct zx_mm7_QueryStatusReq_s* enn;
      for (enn = 0, e = x->QueryStatusReq; e; e = (struct zx_mm7_QueryStatusReq_s*)e->gg.g.n) {
	  en = zx_DEEP_CLONE_mm7_QueryStatusReq(c, e, dup_strs);
	  if (!enn)
	      x->QueryStatusReq = en;
	  else
	      enn->gg.g.n = &en->gg.g;
	  enn = en;
      }
  }
  {
      struct zx_mm7_QueryStatusRsp_s* e;
      struct zx_mm7_QueryStatusRsp_s* en;
      struct zx_mm7_QueryStatusRsp_s* enn;
      for (enn = 0, e = x->QueryStatusRsp; e; e = (struct zx_mm7_QueryStatusRsp_s*)e->gg.g.n) {
	  en = zx_DEEP_CLONE_mm7_QueryStatusRsp(c, e, dup_strs);
	  if (!enn)
	      x->QueryStatusRsp = en;
	  else
	      enn->gg.g.n = &en->gg.g;
	  enn = en;
      }
  }
  {
      struct zx_cb_Query_s* e;
      struct zx_cb_Query_s* en;
      struct zx_cb_Query_s* enn;
      for (enn = 0, e = x->cb_Query; e; e = (struct zx_cb_Query_s*)e->gg.g.n) {
	  en = zx_DEEP_CLONE_cb_Query(c, e, dup_strs);
	  if (!enn)
	      x->cb_Query = en;
	  else
	      enn->gg.g.n = &en->gg.g;
	  enn = en;
      }
  }
  {
      struct zx_cb_QueryResponse_s* e;
      struct zx_cb_QueryResponse_s* en;
      struct zx_cb_QueryResponse_s* enn;
      for (enn = 0, e = x->cb_QueryResponse; e; e = (struct zx_cb_QueryResponse_s*)e->gg.g.n) {
	  en = zx_DEEP_CLONE_cb_QueryResponse(c, e, dup_strs);
	  if (!enn)
	      x->cb_QueryResponse = en;
	  else
	      enn->gg.g.n = &en->gg.g;
	  enn = en;
      }
  }
  {
      struct zx_cb_Create_s* e;
      struct zx_cb_Create_s* en;
      struct zx_cb_Create_s* enn;
      for (enn = 0, e = x->cb_Create; e; e = (struct zx_cb_Create_s*)e->gg.g.n) {
	  en = zx_DEEP_CLONE_cb_Create(c, e, dup_strs);
	  if (!enn)
	      x->cb_Create = en;
	  else
	      enn->gg.g.n = &en->gg.g;
	  enn = en;
      }
  }
  {
      struct zx_cb_CreateResponse_s* e;
      struct zx_cb_CreateResponse_s* en;
      struct zx_cb_CreateResponse_s* enn;
      for (enn = 0, e = x->cb_CreateResponse; e; e = (struct zx_cb_CreateResponse_s*)e->gg.g.n) {
	  en = zx_DEEP_CLONE_cb_CreateResponse(c, e, dup_strs);
	  if (!enn)
	      x->cb_CreateResponse = en;
	  else
	      enn->gg.g.n = &en->gg.g;
	  enn = en;
      }
  }
  {
      struct zx_cb_Delete_s* e;
      struct zx_cb_Delete_s* en;
      struct zx_cb_Delete_s* enn;
      for (enn = 0, e = x->cb_Delete; e; e = (struct zx_cb_Delete_s*)e->gg.g.n) {
	  en = zx_DEEP_CLONE_cb_Delete(c, e, dup_strs);
	  if (!enn)
	      x->cb_Delete = en;
	  else
	      enn->gg.g.n = &en->gg.g;
	  enn = en;
      }
  }
  {
      struct zx_cb_DeleteResponse_s* e;
      struct zx_cb_DeleteResponse_s* en;
      struct zx_cb_DeleteResponse_s* enn;
      for (enn = 0, e = x->cb_DeleteResponse; e; e = (struct zx_cb_DeleteResponse_s*)e->gg.g.n) {
	  en = zx_DEEP_CLONE_cb_DeleteResponse(c, e, dup_strs);
	  if (!enn)
	      x->cb_DeleteResponse = en;
	  else
	      enn->gg.g.n = &en->gg.g;
	  enn = en;
      }
  }
  {
      struct zx_cb_Modify_s* e;
      struct zx_cb_Modify_s* en;
      struct zx_cb_Modify_s* enn;
      for (enn = 0, e = x->cb_Modify; e; e = (struct zx_cb_Modify_s*)e->gg.g.n) {
	  en = zx_DEEP_CLONE_cb_Modify(c, e, dup_strs);
	  if (!enn)
	      x->cb_Modify = en;
	  else
	      enn->gg.g.n = &en->gg.g;
	  enn = en;
      }
  }
  {
      struct zx_cb_ModifyResponse_s* e;
      struct zx_cb_ModifyResponse_s* en;
      struct zx_cb_ModifyResponse_s* enn;
      for (enn = 0, e = x->cb_ModifyResponse; e; e = (struct zx_cb_ModifyResponse_s*)e->gg.g.n) {
	  en = zx_DEEP_CLONE_cb_ModifyResponse(c, e, dup_strs);
	  if (!enn)
	      x->cb_ModifyResponse = en;
	  else
	      enn->gg.g.n = &en->gg.g;
	  enn = en;
      }
  }
  {
      struct zx_cb_Notify_s* e;
      struct zx_cb_Notify_s* en;
      struct zx_cb_Notify_s* enn;
      for (enn = 0, e = x->cb_Notify; e; e = (struct zx_cb_Notify_s*)e->gg.g.n) {
	  en = zx_DEEP_CLONE_cb_Notify(c, e, dup_strs);
	  if (!enn)
	      x->cb_Notify = en;
	  else
	      enn->gg.g.n = &en->gg.g;
	  enn = en;
      }
  }
  {
      struct zx_cb_NotifyResponse_s* e;
      struct zx_cb_NotifyResponse_s* en;
      struct zx_cb_NotifyResponse_s* enn;
      for (enn = 0, e = x->cb_NotifyResponse; e; e = (struct zx_cb_NotifyResponse_s*)e->gg.g.n) {
	  en = zx_DEEP_CLONE_cb_NotifyResponse(c, e, dup_strs);
	  if (!enn)
	      x->cb_NotifyResponse = en;
	  else
	      enn->gg.g.n = &en->gg.g;
	  enn = en;
      }
  }
  {
      struct zx_cb_ReportUsage_s* e;
      struct zx_cb_ReportUsage_s* en;
      struct zx_cb_ReportUsage_s* enn;
      for (enn = 0, e = x->ReportUsage; e; e = (struct zx_cb_ReportUsage_s*)e->gg.g.n) {
	  en = zx_DEEP_CLONE_cb_ReportUsage(c, e, dup_strs);
	  if (!enn)
	      x->ReportUsage = en;
	  else
	      enn->gg.g.n = &en->gg.g;
	  enn = en;
      }
  }
  {
      struct zx_cb_ReportUsageResponse_s* e;
      struct zx_cb_ReportUsageResponse_s* en;
      struct zx_cb_ReportUsageResponse_s* enn;
      for (enn = 0, e = x->ReportUsageResponse; e; e = (struct zx_cb_ReportUsageResponse_s*)e->gg.g.n) {
	  en = zx_DEEP_CLONE_cb_ReportUsageResponse(c, e, dup_strs);
	  if (!enn)
	      x->ReportUsageResponse = en;
	  else
	      enn->gg.g.n = &en->gg.g;
	  enn = en;
      }
  }
  {
      struct zx_gl_Query_s* e;
      struct zx_gl_Query_s* en;
      struct zx_gl_Query_s* enn;
      for (enn = 0, e = x->gl_Query; e; e = (struct zx_gl_Query_s*)e->gg.g.n) {
	  en = zx_DEEP_CLONE_gl_Query(c, e, dup_strs);
	  if (!enn)
	      x->gl_Query = en;
	  else
	      enn->gg.g.n = &en->gg.g;
	  enn = en;
      }
  }
  {
      struct zx_gl_QueryResponse_s* e;
      struct zx_gl_QueryResponse_s* en;
      struct zx_gl_QueryResponse_s* enn;
      for (enn = 0, e = x->gl_QueryResponse; e; e = (struct zx_gl_QueryResponse_s*)e->gg.g.n) {
	  en = zx_DEEP_CLONE_gl_QueryResponse(c, e, dup_strs);
	  if (!enn)
	      x->gl_QueryResponse = en;
	  else
	      enn->gg.g.n = &en->gg.g;
	  enn = en;
      }
  }
  {
      struct zx_gl_Create_s* e;
      struct zx_gl_Create_s* en;
      struct zx_gl_Create_s* enn;
      for (enn = 0, e = x->gl_Create; e; e = (struct zx_gl_Create_s*)e->gg.g.n) {
	  en = zx_DEEP_CLONE_gl_Create(c, e, dup_strs);
	  if (!enn)
	      x->gl_Create = en;
	  else
	      enn->gg.g.n = &en->gg.g;
	  enn = en;
      }
  }
  {
      struct zx_gl_CreateResponse_s* e;
      struct zx_gl_CreateResponse_s* en;
      struct zx_gl_CreateResponse_s* enn;
      for (enn = 0, e = x->gl_CreateResponse; e; e = (struct zx_gl_CreateResponse_s*)e->gg.g.n) {
	  en = zx_DEEP_CLONE_gl_CreateResponse(c, e, dup_strs);
	  if (!enn)
	      x->gl_CreateResponse = en;
	  else
	      enn->gg.g.n = &en->gg.g;
	  enn = en;
      }
  }
  {
      struct zx_gl_Delete_s* e;
      struct zx_gl_Delete_s* en;
      struct zx_gl_Delete_s* enn;
      for (enn = 0, e = x->gl_Delete; e; e = (struct zx_gl_Delete_s*)e->gg.g.n) {
	  en = zx_DEEP_CLONE_gl_Delete(c, e, dup_strs);
	  if (!enn)
	      x->gl_Delete = en;
	  else
	      enn->gg.g.n = &en->gg.g;
	  enn = en;
      }
  }
  {
      struct zx_gl_DeleteResponse_s* e;
      struct zx_gl_DeleteResponse_s* en;
      struct zx_gl_DeleteResponse_s* enn;
      for (enn = 0, e = x->gl_DeleteResponse; e; e = (struct zx_gl_DeleteResponse_s*)e->gg.g.n) {
	  en = zx_DEEP_CLONE_gl_DeleteResponse(c, e, dup_strs);
	  if (!enn)
	      x->gl_DeleteResponse = en;
	  else
	      enn->gg.g.n = &en->gg.g;
	  enn = en;
      }
  }
  {
      struct zx_gl_Modify_s* e;
      struct zx_gl_Modify_s* en;
      struct zx_gl_Modify_s* enn;
      for (enn = 0, e = x->gl_Modify; e; e = (struct zx_gl_Modify_s*)e->gg.g.n) {
	  en = zx_DEEP_CLONE_gl_Modify(c, e, dup_strs);
	  if (!enn)
	      x->gl_Modify = en;
	  else
	      enn->gg.g.n = &en->gg.g;
	  enn = en;
      }
  }
  {
      struct zx_gl_ModifyResponse_s* e;
      struct zx_gl_ModifyResponse_s* en;
      struct zx_gl_ModifyResponse_s* enn;
      for (enn = 0, e = x->gl_ModifyResponse; e; e = (struct zx_gl_ModifyResponse_s*)e->gg.g.n) {
	  en = zx_DEEP_CLONE_gl_ModifyResponse(c, e, dup_strs);
	  if (!enn)
	      x->gl_ModifyResponse = en;
	  else
	      enn->gg.g.n = &en->gg.g;
	  enn = en;
      }
  }
  {
      struct zx_gl_Notify_s* e;
      struct zx_gl_Notify_s* en;
      struct zx_gl_Notify_s* enn;
      for (enn = 0, e = x->gl_Notify; e; e = (struct zx_gl_Notify_s*)e->gg.g.n) {
	  en = zx_DEEP_CLONE_gl_Notify(c, e, dup_strs);
	  if (!enn)
	      x->gl_Notify = en;
	  else
	      enn->gg.g.n = &en->gg.g;
	  enn = en;
      }
  }
  {
      struct zx_gl_NotifyResponse_s* e;
      struct zx_gl_NotifyResponse_s* en;
      struct zx_gl_NotifyResponse_s* enn;
      for (enn = 0, e = x->gl_NotifyResponse; e; e = (struct zx_gl_NotifyResponse_s*)e->gg.g.n) {
	  en = zx_DEEP_CLONE_gl_NotifyResponse(c, e, dup_strs);
	  if (!enn)
	      x->gl_NotifyResponse = en;
	  else
	      enn->gg.g.n = &en->gg.g;
	  enn = en;
      }
  }
  {
      struct zx_demomed_StoreObjectRequest_s* e;
      struct zx_demomed_StoreObjectRequest_s* en;
      struct zx_demomed_StoreObjectRequest_s* enn;
      for (enn = 0, e = x->StoreObjectRequest; e; e = (struct zx_demomed_StoreObjectRequest_s*)e->gg.g.n) {
	  en = zx_DEEP_CLONE_demomed_StoreObjectRequest(c, e, dup_strs);
	  if (!enn)
	      x->StoreObjectRequest = en;
	  else
	      enn->gg.g.n = &en->gg.g;
	  enn = en;
      }
  }
  {
      struct zx_demomed_StoreObjectResponse_s* e;
      struct zx_demomed_StoreObjectResponse_s* en;
      struct zx_demomed_StoreObjectResponse_s* enn;
      for (enn = 0, e = x->StoreObjectResponse; e; e = (struct zx_demomed_StoreObjectResponse_s*)e->gg.g.n) {
	  en = zx_DEEP_CLONE_demomed_StoreObjectResponse(c, e, dup_strs);
	  if (!enn)
	      x->StoreObjectResponse = en;
	  else
	      enn->gg.g.n = &en->gg.g;
	  enn = en;
      }
  }
  {
      struct zx_demomed_GetObjectListRequest_s* e;
      struct zx_demomed_GetObjectListRequest_s* en;
      struct zx_demomed_GetObjectListRequest_s* enn;
      for (enn = 0, e = x->GetObjectListRequest; e; e = (struct zx_demomed_GetObjectListRequest_s*)e->gg.g.n) {
	  en = zx_DEEP_CLONE_demomed_GetObjectListRequest(c, e, dup_strs);
	  if (!enn)
	      x->GetObjectListRequest = en;
	  else
	      enn->gg.g.n = &en->gg.g;
	  enn = en;
      }
  }
  {
      struct zx_demomed_GetObjectListResponse_s* e;
      struct zx_demomed_GetObjectListResponse_s* en;
      struct zx_demomed_GetObjectListResponse_s* enn;
      for (enn = 0, e = x->GetObjectListResponse; e; e = (struct zx_demomed_GetObjectListResponse_s*)e->gg.g.n) {
	  en = zx_DEEP_CLONE_demomed_GetObjectListResponse(c, e, dup_strs);
	  if (!enn)
	      x->GetObjectListResponse = en;
	  else
	      enn->gg.g.n = &en->gg.g;
	  enn = en;
      }
  }
  {
      struct zx_demomed_GetObjectRequest_s* e;
      struct zx_demomed_GetObjectRequest_s* en;
      struct zx_demomed_GetObjectRequest_s* enn;
      for (enn = 0, e = x->GetObjectRequest; e; e = (struct zx_demomed_GetObjectRequest_s*)e->gg.g.n) {
	  en = zx_DEEP_CLONE_demomed_GetObjectRequest(c, e, dup_strs);
	  if (!enn)
	      x->GetObjectRequest = en;
	  else
	      enn->gg.g.n = &en->gg.g;
	  enn = en;
      }
  }
  {
      struct zx_demomed_GetObjectResponse_s* e;
      struct zx_demomed_GetObjectResponse_s* en;
      struct zx_demomed_GetObjectResponse_s* enn;
      for (enn = 0, e = x->GetObjectResponse; e; e = (struct zx_demomed_GetObjectResponse_s*)e->gg.g.n) {
	  en = zx_DEEP_CLONE_demomed_GetObjectResponse(c, e, dup_strs);
	  if (!enn)
	      x->GetObjectResponse = en;
	  else
	      enn->gg.g.n = &en->gg.g;
	  enn = en;
      }
  }
  {
      struct zx_demomed_DeleteObjectRequest_s* e;
      struct zx_demomed_DeleteObjectRequest_s* en;
      struct zx_demomed_DeleteObjectRequest_s* enn;
      for (enn = 0, e = x->DeleteObjectRequest; e; e = (struct zx_demomed_DeleteObjectRequest_s*)e->gg.g.n) {
	  en = zx_DEEP_CLONE_demomed_DeleteObjectRequest(c, e, dup_strs);
	  if (!enn)
	      x->DeleteObjectRequest = en;
	  else
	      enn->gg.g.n = &en->gg.g;
	  enn = en;
      }
  }
  {
      struct zx_demomed_DeleteObjectResponse_s* e;
      struct zx_demomed_DeleteObjectResponse_s* en;
      struct zx_demomed_DeleteObjectResponse_s* enn;
      for (enn = 0, e = x->DeleteObjectResponse; e; e = (struct zx_demomed_DeleteObjectResponse_s*)e->gg.g.n) {
	  en = zx_DEEP_CLONE_demomed_DeleteObjectResponse(c, e, dup_strs);
	  if (!enn)
	      x->DeleteObjectResponse = en;
	  else
	      enn->gg.g.n = &en->gg.g;
	  enn = en;
      }
  }
  {
      struct zx_pmm_Provision_s* e;
      struct zx_pmm_Provision_s* en;
      struct zx_pmm_Provision_s* enn;
      for (enn = 0, e = x->Provision; e; e = (struct zx_pmm_Provision_s*)e->gg.g.n) {
	  en = zx_DEEP_CLONE_pmm_Provision(c, e, dup_strs);
	  if (!enn)
	      x->Provision = en;
	  else
	      enn->gg.g.n = &en->gg.g;
	  enn = en;
      }
  }
  {
      struct zx_pmm_ProvisionResponse_s* e;
      struct zx_pmm_ProvisionResponse_s* en;
      struct zx_pmm_ProvisionResponse_s* enn;
      for (enn = 0, e = x->ProvisionResponse; e; e = (struct zx_pmm_ProvisionResponse_s*)e->gg.g.n) {
	  en = zx_DEEP_CLONE_pmm_ProvisionResponse(c, e, dup_strs);
	  if (!enn)
	      x->ProvisionResponse = en;
	  else
	      enn->gg.g.n = &en->gg.g;
	  enn = en;
      }
  }
  {
      struct zx_pmm_PMActivate_s* e;
      struct zx_pmm_PMActivate_s* en;
      struct zx_pmm_PMActivate_s* enn;
      for (enn = 0, e = x->PMActivate; e; e = (struct zx_pmm_PMActivate_s*)e->gg.g.n) {
	  en = zx_DEEP_CLONE_pmm_PMActivate(c, e, dup_strs);
	  if (!enn)
	      x->PMActivate = en;
	  else
	      enn->gg.g.n = &en->gg.g;
	  enn = en;
      }
  }
  {
      struct zx_pmm_PMActivateResponse_s* e;
      struct zx_pmm_PMActivateResponse_s* en;
      struct zx_pmm_PMActivateResponse_s* enn;
      for (enn = 0, e = x->PMActivateResponse; e; e = (struct zx_pmm_PMActivateResponse_s*)e->gg.g.n) {
	  en = zx_DEEP_CLONE_pmm_PMActivateResponse(c, e, dup_strs);
	  if (!enn)
	      x->PMActivateResponse = en;
	  else
	      enn->gg.g.n = &en->gg.g;
	  enn = en;
      }
  }
  {
      struct zx_pmm_PMDeactivate_s* e;
      struct zx_pmm_PMDeactivate_s* en;
      struct zx_pmm_PMDeactivate_s* enn;
      for (enn = 0, e = x->PMDeactivate; e; e = (struct zx_pmm_PMDeactivate_s*)e->gg.g.n) {
	  en = zx_DEEP_CLONE_pmm_PMDeactivate(c, e, dup_strs);
	  if (!enn)
	      x->PMDeactivate = en;
	  else
	      enn->gg.g.n = &en->gg.g;
	  enn = en;
      }
  }
  {
      struct zx_pmm_PMDeactivateResponse_s* e;
      struct zx_pmm_PMDeactivateResponse_s* en;
      struct zx_pmm_PMDeactivateResponse_s* enn;
      for (enn = 0, e = x->PMDeactivateResponse; e; e = (struct zx_pmm_PMDeactivateResponse_s*)e->gg.g.n) {
	  en = zx_DEEP_CLONE_pmm_PMDeactivateResponse(c, e, dup_strs);
	  if (!enn)
	      x->PMDeactivateResponse = en;
	  else
	      enn->gg.g.n = &en->gg.g;
	  enn = en;
      }
  }
  {
      struct zx_pmm_PMDelete_s* e;
      struct zx_pmm_PMDelete_s* en;
      struct zx_pmm_PMDelete_s* enn;
      for (enn = 0, e = x->PMDelete; e; e = (struct zx_pmm_PMDelete_s*)e->gg.g.n) {
	  en = zx_DEEP_CLONE_pmm_PMDelete(c, e, dup_strs);
	  if (!enn)
	      x->PMDelete = en;
	  else
	      enn->gg.g.n = &en->gg.g;
	  enn = en;
      }
  }
  {
      struct zx_pmm_PMDeleteResponse_s* e;
      struct zx_pmm_PMDeleteResponse_s* en;
      struct zx_pmm_PMDeleteResponse_s* enn;
      for (enn = 0, e = x->PMDeleteResponse; e; e = (struct zx_pmm_PMDeleteResponse_s*)e->gg.g.n) {
	  en = zx_DEEP_CLONE_pmm_PMDeleteResponse(c, e, dup_strs);
	  if (!enn)
	      x->PMDeleteResponse = en;
	  else
	      enn->gg.g.n = &en->gg.g;
	  enn = en;
      }
  }
  {
      struct zx_pmm_PMUpdate_s* e;
      struct zx_pmm_PMUpdate_s* en;
      struct zx_pmm_PMUpdate_s* enn;
      for (enn = 0, e = x->PMUpdate; e; e = (struct zx_pmm_PMUpdate_s*)e->gg.g.n) {
	  en = zx_DEEP_CLONE_pmm_PMUpdate(c, e, dup_strs);
	  if (!enn)
	      x->PMUpdate = en;
	  else
	      enn->gg.g.n = &en->gg.g;
	  enn = en;
      }
  }
  {
      struct zx_pmm_PMUpdateResponse_s* e;
      struct zx_pmm_PMUpdateResponse_s* en;
      struct zx_pmm_PMUpdateResponse_s* enn;
      for (enn = 0, e = x->PMUpdateResponse; e; e = (struct zx_pmm_PMUpdateResponse_s*)e->gg.g.n) {
	  en = zx_DEEP_CLONE_pmm_PMUpdateResponse(c, e, dup_strs);
	  if (!enn)
	      x->PMUpdateResponse = en;
	  else
	      enn->gg.g.n = &en->gg.g;
	  enn = en;
      }
  }
  {
      struct zx_pmm_PMGetStatus_s* e;
      struct zx_pmm_PMGetStatus_s* en;
      struct zx_pmm_PMGetStatus_s* enn;
      for (enn = 0, e = x->PMGetStatus; e; e = (struct zx_pmm_PMGetStatus_s*)e->gg.g.n) {
	  en = zx_DEEP_CLONE_pmm_PMGetStatus(c, e, dup_strs);
	  if (!enn)
	      x->PMGetStatus = en;
	  else
	      enn->gg.g.n = &en->gg.g;
	  enn = en;
      }
  }
  {
      struct zx_pmm_PMGetStatusResponse_s* e;
      struct zx_pmm_PMGetStatusResponse_s* en;
      struct zx_pmm_PMGetStatusResponse_s* enn;
      for (enn = 0, e = x->PMGetStatusResponse; e; e = (struct zx_pmm_PMGetStatusResponse_s*)e->gg.g.n) {
	  en = zx_DEEP_CLONE_pmm_PMGetStatusResponse(c, e, dup_strs);
	  if (!enn)
	      x->PMGetStatusResponse = en;
	  else
	      enn->gg.g.n = &en->gg.g;
	  enn = en;
      }
  }
  {
      struct zx_pmm_PMSetStatus_s* e;
      struct zx_pmm_PMSetStatus_s* en;
      struct zx_pmm_PMSetStatus_s* enn;
      for (enn = 0, e = x->PMSetStatus; e; e = (struct zx_pmm_PMSetStatus_s*)e->gg.g.n) {
	  en = zx_DEEP_CLONE_pmm_PMSetStatus(c, e, dup_strs);
	  if (!enn)
	      x->PMSetStatus = en;
	  else
	      enn->gg.g.n = &en->gg.g;
	  enn = en;
      }
  }
  {
      struct zx_pmm_PMSetStatusResponse_s* e;
      struct zx_pmm_PMSetStatusResponse_s* en;
      struct zx_pmm_PMSetStatusResponse_s* enn;
      for (enn = 0, e = x->PMSetStatusResponse; e; e = (struct zx_pmm_PMSetStatusResponse_s*)e->gg.g.n) {
	  en = zx_DEEP_CLONE_pmm_PMSetStatusResponse(c, e, dup_strs);
	  if (!enn)
	      x->PMSetStatusResponse = en;
	  else
	      enn->gg.g.n = &en->gg.g;
	  enn = en;
      }
  }
  {
      struct zx_prov_PMERegister_s* e;
      struct zx_prov_PMERegister_s* en;
      struct zx_prov_PMERegister_s* enn;
      for (enn = 0, e = x->PMERegister; e; e = (struct zx_prov_PMERegister_s*)e->gg.g.n) {
	  en = zx_DEEP_CLONE_prov_PMERegister(c, e, dup_strs);
	  if (!enn)
	      x->PMERegister = en;
	  else
	      enn->gg.g.n = &en->gg.g;
	  enn = en;
      }
  }
  {
      struct zx_prov_PMERegisterResponse_s* e;
      struct zx_prov_PMERegisterResponse_s* en;
      struct zx_prov_PMERegisterResponse_s* enn;
      for (enn = 0, e = x->PMERegisterResponse; e; e = (struct zx_prov_PMERegisterResponse_s*)e->gg.g.n) {
	  en = zx_DEEP_CLONE_prov_PMERegisterResponse(c, e, dup_strs);
	  if (!enn)
	      x->PMERegisterResponse = en;
	  else
	      enn->gg.g.n = &en->gg.g;
	  enn = en;
      }
  }
  {
      struct zx_prov_PMEUpload_s* e;
      struct zx_prov_PMEUpload_s* en;
      struct zx_prov_PMEUpload_s* enn;
      for (enn = 0, e = x->PMEUpload; e; e = (struct zx_prov_PMEUpload_s*)e->gg.g.n) {
	  en = zx_DEEP_CLONE_prov_PMEUpload(c, e, dup_strs);
	  if (!enn)
	      x->PMEUpload = en;
	  else
	      enn->gg.g.n = &en->gg.g;
	  enn = en;
      }
  }
  {
      struct zx_prov_PMEUploadResponse_s* e;
      struct zx_prov_PMEUploadResponse_s* en;
      struct zx_prov_PMEUploadResponse_s* enn;
      for (enn = 0, e = x->PMEUploadResponse; e; e = (struct zx_prov_PMEUploadResponse_s*)e->gg.g.n) {
	  en = zx_DEEP_CLONE_prov_PMEUploadResponse(c, e, dup_strs);
	  if (!enn)
	      x->PMEUploadResponse = en;
	  else
	      enn->gg.g.n = &en->gg.g;
	  enn = en;
      }
  }
  {
      struct zx_prov_PMEDownload_s* e;
      struct zx_prov_PMEDownload_s* en;
      struct zx_prov_PMEDownload_s* enn;
      for (enn = 0, e = x->PMEDownload; e; e = (struct zx_prov_PMEDownload_s*)e->gg.g.n) {
	  en = zx_DEEP_CLONE_prov_PMEDownload(c, e, dup_strs);
	  if (!enn)
	      x->PMEDownload = en;
	  else
	      enn->gg.g.n = &en->gg.g;
	  enn = en;
      }
  }
  {
      struct zx_prov_PMEDownloadResponse_s* e;
      struct zx_prov_PMEDownloadResponse_s* en;
      struct zx_prov_PMEDownloadResponse_s* enn;
      for (enn = 0, e = x->PMEDownloadResponse; e; e = (struct zx_prov_PMEDownloadResponse_s*)e->gg.g.n) {
	  en = zx_DEEP_CLONE_prov_PMEDownloadResponse(c, e, dup_strs);
	  if (!enn)
	      x->PMEDownloadResponse = en;
	  else
	      enn->gg.g.n = &en->gg.g;
	  enn = en;
      }
  }
  {
      struct zx_prov_PMEEnable_s* e;
      struct zx_prov_PMEEnable_s* en;
      struct zx_prov_PMEEnable_s* enn;
      for (enn = 0, e = x->PMEEnable; e; e = (struct zx_prov_PMEEnable_s*)e->gg.g.n) {
	  en = zx_DEEP_CLONE_prov_PMEEnable(c, e, dup_strs);
	  if (!enn)
	      x->PMEEnable = en;
	  else
	      enn->gg.g.n = &en->gg.g;
	  enn = en;
      }
  }
  {
      struct zx_prov_PMEEnableResponse_s* e;
      struct zx_prov_PMEEnableResponse_s* en;
      struct zx_prov_PMEEnableResponse_s* enn;
      for (enn = 0, e = x->PMEEnableResponse; e; e = (struct zx_prov_PMEEnableResponse_s*)e->gg.g.n) {
	  en = zx_DEEP_CLONE_prov_PMEEnableResponse(c, e, dup_strs);
	  if (!enn)
	      x->PMEEnableResponse = en;
	  else
	      enn->gg.g.n = &en->gg.g;
	  enn = en;
      }
  }
  {
      struct zx_prov_PMEDisable_s* e;
      struct zx_prov_PMEDisable_s* en;
      struct zx_prov_PMEDisable_s* enn;
      for (enn = 0, e = x->PMEDisable; e; e = (struct zx_prov_PMEDisable_s*)e->gg.g.n) {
	  en = zx_DEEP_CLONE_prov_PMEDisable(c, e, dup_strs);
	  if (!enn)
	      x->PMEDisable = en;
	  else
	      enn->gg.g.n = &en->gg.g;
	  enn = en;
      }
  }
  {
      struct zx_prov_PMEDisableResponse_s* e;
      struct zx_prov_PMEDisableResponse_s* en;
      struct zx_prov_PMEDisableResponse_s* enn;
      for (enn = 0, e = x->PMEDisableResponse; e; e = (struct zx_prov_PMEDisableResponse_s*)e->gg.g.n) {
	  en = zx_DEEP_CLONE_prov_PMEDisableResponse(c, e, dup_strs);
	  if (!enn)
	      x->PMEDisableResponse = en;
	  else
	      enn->gg.g.n = &en->gg.g;
	  enn = en;
      }
  }
  {
      struct zx_prov_PMEDelete_s* e;
      struct zx_prov_PMEDelete_s* en;
      struct zx_prov_PMEDelete_s* enn;
      for (enn = 0, e = x->PMEDelete; e; e = (struct zx_prov_PMEDelete_s*)e->gg.g.n) {
	  en = zx_DEEP_CLONE_prov_PMEDelete(c, e, dup_strs);
	  if (!enn)
	      x->PMEDelete = en;
	  else
	      enn->gg.g.n = &en->gg.g;
	  enn = en;
      }
  }
  {
      struct zx_prov_PMEDeleteResponse_s* e;
      struct zx_prov_PMEDeleteResponse_s* en;
      struct zx_prov_PMEDeleteResponse_s* enn;
      for (enn = 0, e = x->PMEDeleteResponse; e; e = (struct zx_prov_PMEDeleteResponse_s*)e->gg.g.n) {
	  en = zx_DEEP_CLONE_prov_PMEDeleteResponse(c, e, dup_strs);
	  if (!enn)
	      x->PMEDeleteResponse = en;
	  else
	      enn->gg.g.n = &en->gg.g;
	  enn = en;
      }
  }
  {
      struct zx_prov_PMEGetInfo_s* e;
      struct zx_prov_PMEGetInfo_s* en;
      struct zx_prov_PMEGetInfo_s* enn;
      for (enn = 0, e = x->PMEGetInfo; e; e = (struct zx_prov_PMEGetInfo_s*)e->gg.g.n) {
	  en = zx_DEEP_CLONE_prov_PMEGetInfo(c, e, dup_strs);
	  if (!enn)
	      x->PMEGetInfo = en;
	  else
	      enn->gg.g.n = &en->gg.g;
	  enn = en;
      }
  }
  {
      struct zx_prov_PMEGetInfoResponse_s* e;
      struct zx_prov_PMEGetInfoResponse_s* en;
      struct zx_prov_PMEGetInfoResponse_s* enn;
      for (enn = 0, e = x->PMEGetInfoResponse; e; e = (struct zx_prov_PMEGetInfoResponse_s*)e->gg.g.n) {
	  en = zx_DEEP_CLONE_prov_PMEGetInfoResponse(c, e, dup_strs);
	  if (!enn)
	      x->PMEGetInfoResponse = en;
	  else
	      enn->gg.g.n = &en->gg.g;
	  enn = en;
      }
  }
  {
      struct zx_prov_PMGetStatus_s* e;
      struct zx_prov_PMGetStatus_s* en;
      struct zx_prov_PMGetStatus_s* enn;
      for (enn = 0, e = x->prov_PMGetStatus; e; e = (struct zx_prov_PMGetStatus_s*)e->gg.g.n) {
	  en = zx_DEEP_CLONE_prov_PMGetStatus(c, e, dup_strs);
	  if (!enn)
	      x->prov_PMGetStatus = en;
	  else
	      enn->gg.g.n = &en->gg.g;
	  enn = en;
      }
  }
  {
      struct zx_prov_PMGetStatusResponse_s* e;
      struct zx_prov_PMGetStatusResponse_s* en;
      struct zx_prov_PMGetStatusResponse_s* enn;
      for (enn = 0, e = x->prov_PMGetStatusResponse; e; e = (struct zx_prov_PMGetStatusResponse_s*)e->gg.g.n) {
	  en = zx_DEEP_CLONE_prov_PMGetStatusResponse(c, e, dup_strs);
	  if (!enn)
	      x->prov_PMGetStatusResponse = en;
	  else
	      enn->gg.g.n = &en->gg.g;
	  enn = en;
      }
  }
  {
      struct zx_prov_PMSetStatus_s* e;
      struct zx_prov_PMSetStatus_s* en;
      struct zx_prov_PMSetStatus_s* enn;
      for (enn = 0, e = x->prov_PMSetStatus; e; e = (struct zx_prov_PMSetStatus_s*)e->gg.g.n) {
	  en = zx_DEEP_CLONE_prov_PMSetStatus(c, e, dup_strs);
	  if (!enn)
	      x->prov_PMSetStatus = en;
	  else
	      enn->gg.g.n = &en->gg.g;
	  enn = en;
      }
  }
  {
      struct zx_prov_PMSetStatusResponse_s* e;
      struct zx_prov_PMSetStatusResponse_s* en;
      struct zx_prov_PMSetStatusResponse_s* enn;
      for (enn = 0, e = x->prov_PMSetStatusResponse; e; e = (struct zx_prov_PMSetStatusResponse_s*)e->gg.g.n) {
	  en = zx_DEEP_CLONE_prov_PMSetStatusResponse(c, e, dup_strs);
	  if (!enn)
	      x->prov_PMSetStatusResponse = en;
	  else
	      enn->gg.g.n = &en->gg.g;
	  enn = en;
      }
  }
  {
      struct zx_prov_PMGetDescriptor_s* e;
      struct zx_prov_PMGetDescriptor_s* en;
      struct zx_prov_PMGetDescriptor_s* enn;
      for (enn = 0, e = x->PMGetDescriptor; e; e = (struct zx_prov_PMGetDescriptor_s*)e->gg.g.n) {
	  en = zx_DEEP_CLONE_prov_PMGetDescriptor(c, e, dup_strs);
	  if (!enn)
	      x->PMGetDescriptor = en;
	  else
	      enn->gg.g.n = &en->gg.g;
	  enn = en;
      }
  }
  {
      struct zx_prov_PMGetDescriptorResponse_s* e;
      struct zx_prov_PMGetDescriptorResponse_s* en;
      struct zx_prov_PMGetDescriptorResponse_s* enn;
      for (enn = 0, e = x->PMGetDescriptorResponse; e; e = (struct zx_prov_PMGetDescriptorResponse_s*)e->gg.g.n) {
	  en = zx_DEEP_CLONE_prov_PMGetDescriptorResponse(c, e, dup_strs);
	  if (!enn)
	      x->PMGetDescriptorResponse = en;
	  else
	      enn->gg.g.n = &en->gg.g;
	  enn = en;
      }
  }
  {
      struct zx_prov_PMActivate_s* e;
      struct zx_prov_PMActivate_s* en;
      struct zx_prov_PMActivate_s* enn;
      for (enn = 0, e = x->prov_PMActivate; e; e = (struct zx_prov_PMActivate_s*)e->gg.g.n) {
	  en = zx_DEEP_CLONE_prov_PMActivate(c, e, dup_strs);
	  if (!enn)
	      x->prov_PMActivate = en;
	  else
	      enn->gg.g.n = &en->gg.g;
	  enn = en;
      }
  }
  {
      struct zx_prov_PMActivateResponse_s* e;
      struct zx_prov_PMActivateResponse_s* en;
      struct zx_prov_PMActivateResponse_s* enn;
      for (enn = 0, e = x->prov_PMActivateResponse; e; e = (struct zx_prov_PMActivateResponse_s*)e->gg.g.n) {
	  en = zx_DEEP_CLONE_prov_PMActivateResponse(c, e, dup_strs);
	  if (!enn)
	      x->prov_PMActivateResponse = en;
	  else
	      enn->gg.g.n = &en->gg.g;
	  enn = en;
      }
  }
  {
      struct zx_prov_PMDeactivate_s* e;
      struct zx_prov_PMDeactivate_s* en;
      struct zx_prov_PMDeactivate_s* enn;
      for (enn = 0, e = x->prov_PMDeactivate; e; e = (struct zx_prov_PMDeactivate_s*)e->gg.g.n) {
	  en = zx_DEEP_CLONE_prov_PMDeactivate(c, e, dup_strs);
	  if (!enn)
	      x->prov_PMDeactivate = en;
	  else
	      enn->gg.g.n = &en->gg.g;
	  enn = en;
      }
  }
  {
      struct zx_prov_PMDeactivateResponse_s* e;
      struct zx_prov_PMDeactivateResponse_s* en;
      struct zx_prov_PMDeactivateResponse_s* enn;
      for (enn = 0, e = x->prov_PMDeactivateResponse; e; e = (struct zx_prov_PMDeactivateResponse_s*)e->gg.g.n) {
	  en = zx_DEEP_CLONE_prov_PMDeactivateResponse(c, e, dup_strs);
	  if (!enn)
	      x->prov_PMDeactivateResponse = en;
	  else
	      enn->gg.g.n = &en->gg.g;
	  enn = en;
      }
  }
  {
      struct zx_prov_PMRegisterDescriptor_s* e;
      struct zx_prov_PMRegisterDescriptor_s* en;
      struct zx_prov_PMRegisterDescriptor_s* enn;
      for (enn = 0, e = x->PMRegisterDescriptor; e; e = (struct zx_prov_PMRegisterDescriptor_s*)e->gg.g.n) {
	  en = zx_DEEP_CLONE_prov_PMRegisterDescriptor(c, e, dup_strs);
	  if (!enn)
	      x->PMRegisterDescriptor = en;
	  else
	      enn->gg.g.n = &en->gg.g;
	  enn = en;
      }
  }
  {
      struct zx_prov_PMRegisterDescriptorResponse_s* e;
      struct zx_prov_PMRegisterDescriptorResponse_s* en;
      struct zx_prov_PMRegisterDescriptorResponse_s* enn;
      for (enn = 0, e = x->PMRegisterDescriptorResponse; e; e = (struct zx_prov_PMRegisterDescriptorResponse_s*)e->gg.g.n) {
	  en = zx_DEEP_CLONE_prov_PMRegisterDescriptorResponse(c, e, dup_strs);
	  if (!enn)
	      x->PMRegisterDescriptorResponse = en;
	  else
	      enn->gg.g.n = &en->gg.g;
	  enn = en;
      }
  }
  {
      struct zx_prov_PMUpdate_s* e;
      struct zx_prov_PMUpdate_s* en;
      struct zx_prov_PMUpdate_s* enn;
      for (enn = 0, e = x->prov_PMUpdate; e; e = (struct zx_prov_PMUpdate_s*)e->gg.g.n) {
	  en = zx_DEEP_CLONE_prov_PMUpdate(c, e, dup_strs);
	  if (!enn)
	      x->prov_PMUpdate = en;
	  else
	      enn->gg.g.n = &en->gg.g;
	  enn = en;
      }
  }
  {
      struct zx_prov_PMUpdateResponse_s* e;
      struct zx_prov_PMUpdateResponse_s* en;
      struct zx_prov_PMUpdateResponse_s* enn;
      for (enn = 0, e = x->prov_PMUpdateResponse; e; e = (struct zx_prov_PMUpdateResponse_s*)e->gg.g.n) {
	  en = zx_DEEP_CLONE_prov_PMUpdateResponse(c, e, dup_strs);
	  if (!enn)
	      x->prov_PMUpdateResponse = en;
	  else
	      enn->gg.g.n = &en->gg.g;
	  enn = en;
      }
  }
  {
      struct zx_prov_PMDelete_s* e;
      struct zx_prov_PMDelete_s* en;
      struct zx_prov_PMDelete_s* enn;
      for (enn = 0, e = x->prov_PMDelete; e; e = (struct zx_prov_PMDelete_s*)e->gg.g.n) {
	  en = zx_DEEP_CLONE_prov_PMDelete(c, e, dup_strs);
	  if (!enn)
	      x->prov_PMDelete = en;
	  else
	      enn->gg.g.n = &en->gg.g;
	  enn = en;
      }
  }
  {
      struct zx_prov_PMDeleteResponse_s* e;
      struct zx_prov_PMDeleteResponse_s* en;
      struct zx_prov_PMDeleteResponse_s* enn;
      for (enn = 0, e = x->prov_PMDeleteResponse; e; e = (struct zx_prov_PMDeleteResponse_s*)e->gg.g.n) {
	  en = zx_DEEP_CLONE_prov_PMDeleteResponse(c, e, dup_strs);
	  if (!enn)
	      x->prov_PMDeleteResponse = en;
	  else
	      enn->gg.g.n = &en->gg.g;
	  enn = en;
      }
  }
  {
      struct zx_prov_Poll_s* e;
      struct zx_prov_Poll_s* en;
      struct zx_prov_Poll_s* enn;
      for (enn = 0, e = x->Poll; e; e = (struct zx_prov_Poll_s*)e->gg.g.n) {
	  en = zx_DEEP_CLONE_prov_Poll(c, e, dup_strs);
	  if (!enn)
	      x->Poll = en;
	  else
	      enn->gg.g.n = &en->gg.g;
	  enn = en;
      }
  }
  {
      struct zx_prov_PollResponse_s* e;
      struct zx_prov_PollResponse_s* en;
      struct zx_prov_PollResponse_s* enn;
      for (enn = 0, e = x->PollResponse; e; e = (struct zx_prov_PollResponse_s*)e->gg.g.n) {
	  en = zx_DEEP_CLONE_prov_PollResponse(c, e, dup_strs);
	  if (!enn)
	      x->PollResponse = en;
	  else
	      enn->gg.g.n = &en->gg.g;
	  enn = en;
      }
  }
  {
      struct zx_prov_UpdateEPR_s* e;
      struct zx_prov_UpdateEPR_s* en;
      struct zx_prov_UpdateEPR_s* enn;
      for (enn = 0, e = x->UpdateEPR; e; e = (struct zx_prov_UpdateEPR_s*)e->gg.g.n) {
	  en = zx_DEEP_CLONE_prov_UpdateEPR(c, e, dup_strs);
	  if (!enn)
	      x->UpdateEPR = en;
	  else
	      enn->gg.g.n = &en->gg.g;
	  enn = en;
      }
  }
  {
      struct zx_prov_UpdateEPRResponse_s* e;
      struct zx_prov_UpdateEPRResponse_s* en;
      struct zx_prov_UpdateEPRResponse_s* enn;
      for (enn = 0, e = x->UpdateEPRResponse; e; e = (struct zx_prov_UpdateEPRResponse_s*)e->gg.g.n) {
	  en = zx_DEEP_CLONE_prov_UpdateEPRResponse(c, e, dup_strs);
	  if (!enn)
	      x->UpdateEPRResponse = en;
	  else
	      enn->gg.g.n = &en->gg.g;
	  enn = en;
      }
  }
  {
      struct zx_idp_GetAssertion_s* e;
      struct zx_idp_GetAssertion_s* en;
      struct zx_idp_GetAssertion_s* enn;
      for (enn = 0, e = x->GetAssertion; e; e = (struct zx_idp_GetAssertion_s*)e->gg.g.n) {
	  en = zx_DEEP_CLONE_idp_GetAssertion(c, e, dup_strs);
	  if (!enn)
	      x->GetAssertion = en;
	  else
	      enn->gg.g.n = &en->gg.g;
	  enn = en;
      }
  }
  {
      struct zx_idp_GetAssertionResponse_s* e;
      struct zx_idp_GetAssertionResponse_s* en;
      struct zx_idp_GetAssertionResponse_s* enn;
      for (enn = 0, e = x->GetAssertionResponse; e; e = (struct zx_idp_GetAssertionResponse_s*)e->gg.g.n) {
	  en = zx_DEEP_CLONE_idp_GetAssertionResponse(c, e, dup_strs);
	  if (!enn)
	      x->GetAssertionResponse = en;
	  else
	      enn->gg.g.n = &en->gg.g;
	  enn = en;
      }
  }
  {
      struct zx_idp_GetProviderInfo_s* e;
      struct zx_idp_GetProviderInfo_s* en;
      struct zx_idp_GetProviderInfo_s* enn;
      for (enn = 0, e = x->GetProviderInfo; e; e = (struct zx_idp_GetProviderInfo_s*)e->gg.g.n) {
	  en = zx_DEEP_CLONE_idp_GetProviderInfo(c, e, dup_strs);
	  if (!enn)
	      x->GetProviderInfo = en;
	  else
	      enn->gg.g.n = &en->gg.g;
	  enn = en;
      }
  }
  {
      struct zx_idp_GetProviderInfoResponse_s* e;
      struct zx_idp_GetProviderInfoResponse_s* en;
      struct zx_idp_GetProviderInfoResponse_s* enn;
      for (enn = 0, e = x->GetProviderInfoResponse; e; e = (struct zx_idp_GetProviderInfoResponse_s*)e->gg.g.n) {
	  en = zx_DEEP_CLONE_idp_GetProviderInfoResponse(c, e, dup_strs);
	  if (!enn)
	      x->GetProviderInfoResponse = en;
	  else
	      enn->gg.g.n = &en->gg.g;
	  enn = en;
      }
  }
  {
      struct zx_idp_CreatedStatus_s* e;
      struct zx_idp_CreatedStatus_s* en;
      struct zx_idp_CreatedStatus_s* enn;
      for (enn = 0, e = x->CreatedStatus; e; e = (struct zx_idp_CreatedStatus_s*)e->gg.g.n) {
	  en = zx_DEEP_CLONE_idp_CreatedStatus(c, e, dup_strs);
	  if (!enn)
	      x->CreatedStatus = en;
	  else
	      enn->gg.g.n = &en->gg.g;
	  enn = en;
      }
  }
  {
      struct zx_idp_CreatedStatusResponse_s* e;
      struct zx_idp_CreatedStatusResponse_s* en;
      struct zx_idp_CreatedStatusResponse_s* enn;
      for (enn = 0, e = x->CreatedStatusResponse; e; e = (struct zx_idp_CreatedStatusResponse_s*)e->gg.g.n) {
	  en = zx_DEEP_CLONE_idp_CreatedStatusResponse(c, e, dup_strs);
	  if (!enn)
	      x->CreatedStatusResponse = en;
	  else
	      enn->gg.g.n = &en->gg.g;
	  enn = en;
      }
  }
  {
      struct zx_shps_Delete_s* e;
      struct zx_shps_Delete_s* en;
      struct zx_shps_Delete_s* enn;
      for (enn = 0, e = x->shps_Delete; e; e = (struct zx_shps_Delete_s*)e->gg.g.n) {
	  en = zx_DEEP_CLONE_shps_Delete(c, e, dup_strs);
	  if (!enn)
	      x->shps_Delete = en;
	  else
	      enn->gg.g.n = &en->gg.g;
	  enn = en;
      }
  }
  {
      struct zx_shps_DeleteResponse_s* e;
      struct zx_shps_DeleteResponse_s* en;
      struct zx_shps_DeleteResponse_s* enn;
      for (enn = 0, e = x->shps_DeleteResponse; e; e = (struct zx_shps_DeleteResponse_s*)e->gg.g.n) {
	  en = zx_DEEP_CLONE_shps_DeleteResponse(c, e, dup_strs);
	  if (!enn)
	      x->shps_DeleteResponse = en;
	  else
	      enn->gg.g.n = &en->gg.g;
	  enn = en;
      }
  }
  {
      struct zx_shps_GetStatus_s* e;
      struct zx_shps_GetStatus_s* en;
      struct zx_shps_GetStatus_s* enn;
      for (enn = 0, e = x->GetStatus; e; e = (struct zx_shps_GetStatus_s*)e->gg.g.n) {
	  en = zx_DEEP_CLONE_shps_GetStatus(c, e, dup_strs);
	  if (!enn)
	      x->GetStatus = en;
	  else
	      enn->gg.g.n = &en->gg.g;
	  enn = en;
      }
  }
  {
      struct zx_shps_GetStatusResponse_s* e;
      struct zx_shps_GetStatusResponse_s* en;
      struct zx_shps_GetStatusResponse_s* enn;
      for (enn = 0, e = x->GetStatusResponse; e; e = (struct zx_shps_GetStatusResponse_s*)e->gg.g.n) {
	  en = zx_DEEP_CLONE_shps_GetStatusResponse(c, e, dup_strs);
	  if (!enn)
	      x->GetStatusResponse = en;
	  else
	      enn->gg.g.n = &en->gg.g;
	  enn = en;
      }
  }
  {
      struct zx_shps_Query_s* e;
      struct zx_shps_Query_s* en;
      struct zx_shps_Query_s* enn;
      for (enn = 0, e = x->shps_Query; e; e = (struct zx_shps_Query_s*)e->gg.g.n) {
	  en = zx_DEEP_CLONE_shps_Query(c, e, dup_strs);
	  if (!enn)
	      x->shps_Query = en;
	  else
	      enn->gg.g.n = &en->gg.g;
	  enn = en;
      }
  }
  {
      struct zx_shps_QueryResponse_s* e;
      struct zx_shps_QueryResponse_s* en;
      struct zx_shps_QueryResponse_s* enn;
      for (enn = 0, e = x->shps_QueryResponse; e; e = (struct zx_shps_QueryResponse_s*)e->gg.g.n) {
	  en = zx_DEEP_CLONE_shps_QueryResponse(c, e, dup_strs);
	  if (!enn)
	      x->shps_QueryResponse = en;
	  else
	      enn->gg.g.n = &en->gg.g;
	  enn = en;
      }
  }
  x->Invoke = zx_deep_clone_simple_elems(c,x->Invoke, dup_strs);
  {
      struct zx_shps_InvokeResponse_s* e;
      struct zx_shps_InvokeResponse_s* en;
      struct zx_shps_InvokeResponse_s* enn;
      for (enn = 0, e = x->InvokeResponse; e; e = (struct zx_shps_InvokeResponse_s*)e->gg.g.n) {
	  en = zx_DEEP_CLONE_shps_InvokeResponse(c, e, dup_strs);
	  if (!enn)
	      x->InvokeResponse = en;
	  else
	      enn->gg.g.n = &en->gg.g;
	  enn = en;
      }
  }
  {
      struct zx_shps_QueryRegistered_s* e;
      struct zx_shps_QueryRegistered_s* en;
      struct zx_shps_QueryRegistered_s* enn;
      for (enn = 0, e = x->QueryRegistered; e; e = (struct zx_shps_QueryRegistered_s*)e->gg.g.n) {
	  en = zx_DEEP_CLONE_shps_QueryRegistered(c, e, dup_strs);
	  if (!enn)
	      x->QueryRegistered = en;
	  else
	      enn->gg.g.n = &en->gg.g;
	  enn = en;
      }
  }
  {
      struct zx_shps_QueryRegisteredResponse_s* e;
      struct zx_shps_QueryRegisteredResponse_s* en;
      struct zx_shps_QueryRegisteredResponse_s* enn;
      for (enn = 0, e = x->QueryRegisteredResponse; e; e = (struct zx_shps_QueryRegisteredResponse_s*)e->gg.g.n) {
	  en = zx_DEEP_CLONE_shps_QueryRegisteredResponse(c, e, dup_strs);
	  if (!enn)
	      x->QueryRegisteredResponse = en;
	  else
	      enn->gg.g.n = &en->gg.g;
	  enn = en;
      }
  }
  {
      struct zx_shps_Register_s* e;
      struct zx_shps_Register_s* en;
      struct zx_shps_Register_s* enn;
      for (enn = 0, e = x->Register; e; e = (struct zx_shps_Register_s*)e->gg.g.n) {
	  en = zx_DEEP_CLONE_shps_Register(c, e, dup_strs);
	  if (!enn)
	      x->Register = en;
	  else
	      enn->gg.g.n = &en->gg.g;
	  enn = en;
      }
  }
  {
      struct zx_shps_RegisterResponse_s* e;
      struct zx_shps_RegisterResponse_s* en;
      struct zx_shps_RegisterResponse_s* enn;
      for (enn = 0, e = x->RegisterResponse; e; e = (struct zx_shps_RegisterResponse_s*)e->gg.g.n) {
	  en = zx_DEEP_CLONE_shps_RegisterResponse(c, e, dup_strs);
	  if (!enn)
	      x->RegisterResponse = en;
	  else
	      enn->gg.g.n = &en->gg.g;
	  enn = en;
      }
  }
  {
      struct zx_shps_SetStatus_s* e;
      struct zx_shps_SetStatus_s* en;
      struct zx_shps_SetStatus_s* enn;
      for (enn = 0, e = x->SetStatus; e; e = (struct zx_shps_SetStatus_s*)e->gg.g.n) {
	  en = zx_DEEP_CLONE_shps_SetStatus(c, e, dup_strs);
	  if (!enn)
	      x->SetStatus = en;
	  else
	      enn->gg.g.n = &en->gg.g;
	  enn = en;
      }
  }
  {
      struct zx_shps_SetStatusResponse_s* e;
      struct zx_shps_SetStatusResponse_s* en;
      struct zx_shps_SetStatusResponse_s* enn;
      for (enn = 0, e = x->SetStatusResponse; e; e = (struct zx_shps_SetStatusResponse_s*)e->gg.g.n) {
	  en = zx_DEEP_CLONE_shps_SetStatusResponse(c, e, dup_strs);
	  if (!enn)
	      x->SetStatusResponse = en;
	  else
	      enn->gg.g.n = &en->gg.g;
	  enn = en;
      }
  }
  {
      struct zx_shps_Update_s* e;
      struct zx_shps_Update_s* en;
      struct zx_shps_Update_s* enn;
      for (enn = 0, e = x->Update; e; e = (struct zx_shps_Update_s*)e->gg.g.n) {
	  en = zx_DEEP_CLONE_shps_Update(c, e, dup_strs);
	  if (!enn)
	      x->Update = en;
	  else
	      enn->gg.g.n = &en->gg.g;
	  enn = en;
      }
  }
  {
      struct zx_shps_UpdateResponse_s* e;
      struct zx_shps_UpdateResponse_s* en;
      struct zx_shps_UpdateResponse_s* enn;
      for (enn = 0, e = x->UpdateResponse; e; e = (struct zx_shps_UpdateResponse_s*)e->gg.g.n) {
	  en = zx_DEEP_CLONE_shps_UpdateResponse(c, e, dup_strs);
	  if (!enn)
	      x->UpdateResponse = en;
	  else
	      enn->gg.g.n = &en->gg.g;
	  enn = en;
      }
  }
  {
      struct zx_shps_Poll_s* e;
      struct zx_shps_Poll_s* en;
      struct zx_shps_Poll_s* enn;
      for (enn = 0, e = x->shps_Poll; e; e = (struct zx_shps_Poll_s*)e->gg.g.n) {
	  en = zx_DEEP_CLONE_shps_Poll(c, e, dup_strs);
	  if (!enn)
	      x->shps_Poll = en;
	  else
	      enn->gg.g.n = &en->gg.g;
	  enn = en;
      }
  }
  {
      struct zx_shps_PollResponse_s* e;
      struct zx_shps_PollResponse_s* en;
      struct zx_shps_PollResponse_s* enn;
      for (enn = 0, e = x->shps_PollResponse; e; e = (struct zx_shps_PollResponse_s*)e->gg.g.n) {
	  en = zx_DEEP_CLONE_shps_PollResponse(c, e, dup_strs);
	  if (!enn)
	      x->shps_PollResponse = en;
	  else
	      enn->gg.g.n = &en->gg.g;
	  enn = en;
      }
  }
  {
      struct zx_shps_ProxyInvoke_s* e;
      struct zx_shps_ProxyInvoke_s* en;
      struct zx_shps_ProxyInvoke_s* enn;
      for (enn = 0, e = x->ProxyInvoke; e; e = (struct zx_shps_ProxyInvoke_s*)e->gg.g.n) {
	  en = zx_DEEP_CLONE_shps_ProxyInvoke(c, e, dup_strs);
	  if (!enn)
	      x->ProxyInvoke = en;
	  else
	      enn->gg.g.n = &en->gg.g;
	  enn = en;
      }
  }
  {
      struct zx_shps_ProxyInvokeResponse_s* e;
      struct zx_shps_ProxyInvokeResponse_s* en;
      struct zx_shps_ProxyInvokeResponse_s* enn;
      for (enn = 0, e = x->ProxyInvokeResponse; e; e = (struct zx_shps_ProxyInvokeResponse_s*)e->gg.g.n) {
	  en = zx_DEEP_CLONE_shps_ProxyInvokeResponse(c, e, dup_strs);
	  if (!enn)
	      x->ProxyInvokeResponse = en;
	  else
	      enn->gg.g.n = &en->gg.g;
	  enn = en;
      }
  }
  {
      struct zx_idhrxml_Create_s* e;
      struct zx_idhrxml_Create_s* en;
      struct zx_idhrxml_Create_s* enn;
      for (enn = 0, e = x->idhrxml_Create; e; e = (struct zx_idhrxml_Create_s*)e->gg.g.n) {
	  en = zx_DEEP_CLONE_idhrxml_Create(c, e, dup_strs);
	  if (!enn)
	      x->idhrxml_Create = en;
	  else
	      enn->gg.g.n = &en->gg.g;
	  enn = en;
      }
  }
  {
      struct zx_idhrxml_CreateResponse_s* e;
      struct zx_idhrxml_CreateResponse_s* en;
      struct zx_idhrxml_CreateResponse_s* enn;
      for (enn = 0, e = x->idhrxml_CreateResponse; e; e = (struct zx_idhrxml_CreateResponse_s*)e->gg.g.n) {
	  en = zx_DEEP_CLONE_idhrxml_CreateResponse(c, e, dup_strs);
	  if (!enn)
	      x->idhrxml_CreateResponse = en;
	  else
	      enn->gg.g.n = &en->gg.g;
	  enn = en;
      }
  }
  {
      struct zx_idhrxml_Query_s* e;
      struct zx_idhrxml_Query_s* en;
      struct zx_idhrxml_Query_s* enn;
      for (enn = 0, e = x->idhrxml_Query; e; e = (struct zx_idhrxml_Query_s*)e->gg.g.n) {
	  en = zx_DEEP_CLONE_idhrxml_Query(c, e, dup_strs);
	  if (!enn)
	      x->idhrxml_Query = en;
	  else
	      enn->gg.g.n = &en->gg.g;
	  enn = en;
      }
  }
  {
      struct zx_idhrxml_QueryResponse_s* e;
      struct zx_idhrxml_QueryResponse_s* en;
      struct zx_idhrxml_QueryResponse_s* enn;
      for (enn = 0, e = x->idhrxml_QueryResponse; e; e = (struct zx_idhrxml_QueryResponse_s*)e->gg.g.n) {
	  en = zx_DEEP_CLONE_idhrxml_QueryResponse(c, e, dup_strs);
	  if (!enn)
	      x->idhrxml_QueryResponse = en;
	  else
	      enn->gg.g.n = &en->gg.g;
	  enn = en;
      }
  }
  {
      struct zx_idhrxml_Modify_s* e;
      struct zx_idhrxml_Modify_s* en;
      struct zx_idhrxml_Modify_s* enn;
      for (enn = 0, e = x->idhrxml_Modify; e; e = (struct zx_idhrxml_Modify_s*)e->gg.g.n) {
	  en = zx_DEEP_CLONE_idhrxml_Modify(c, e, dup_strs);
	  if (!enn)
	      x->idhrxml_Modify = en;
	  else
	      enn->gg.g.n = &en->gg.g;
	  enn = en;
      }
  }
  {
      struct zx_idhrxml_ModifyResponse_s* e;
      struct zx_idhrxml_ModifyResponse_s* en;
      struct zx_idhrxml_ModifyResponse_s* enn;
      for (enn = 0, e = x->idhrxml_ModifyResponse; e; e = (struct zx_idhrxml_ModifyResponse_s*)e->gg.g.n) {
	  en = zx_DEEP_CLONE_idhrxml_ModifyResponse(c, e, dup_strs);
	  if (!enn)
	      x->idhrxml_ModifyResponse = en;
	  else
	      enn->gg.g.n = &en->gg.g;
	  enn = en;
      }
  }
  {
      struct zx_idhrxml_Delete_s* e;
      struct zx_idhrxml_Delete_s* en;
      struct zx_idhrxml_Delete_s* enn;
      for (enn = 0, e = x->idhrxml_Delete; e; e = (struct zx_idhrxml_Delete_s*)e->gg.g.n) {
	  en = zx_DEEP_CLONE_idhrxml_Delete(c, e, dup_strs);
	  if (!enn)
	      x->idhrxml_Delete = en;
	  else
	      enn->gg.g.n = &en->gg.g;
	  enn = en;
      }
  }
  {
      struct zx_idhrxml_DeleteResponse_s* e;
      struct zx_idhrxml_DeleteResponse_s* en;
      struct zx_idhrxml_DeleteResponse_s* enn;
      for (enn = 0, e = x->idhrxml_DeleteResponse; e; e = (struct zx_idhrxml_DeleteResponse_s*)e->gg.g.n) {
	  en = zx_DEEP_CLONE_idhrxml_DeleteResponse(c, e, dup_strs);
	  if (!enn)
	      x->idhrxml_DeleteResponse = en;
	  else
	      enn->gg.g.n = &en->gg.g;
	  enn = en;
      }
  }
  {
      struct zx_idhrxml_Notify_s* e;
      struct zx_idhrxml_Notify_s* en;
      struct zx_idhrxml_Notify_s* enn;
      for (enn = 0, e = x->idhrxml_Notify; e; e = (struct zx_idhrxml_Notify_s*)e->gg.g.n) {
	  en = zx_DEEP_CLONE_idhrxml_Notify(c, e, dup_strs);
	  if (!enn)
	      x->idhrxml_Notify = en;
	  else
	      enn->gg.g.n = &en->gg.g;
	  enn = en;
      }
  }
  {
      struct zx_idhrxml_NotifyResponse_s* e;
      struct zx_idhrxml_NotifyResponse_s* en;
      struct zx_idhrxml_NotifyResponse_s* enn;
      for (enn = 0, e = x->idhrxml_NotifyResponse; e; e = (struct zx_idhrxml_NotifyResponse_s*)e->gg.g.n) {
	  en = zx_DEEP_CLONE_idhrxml_NotifyResponse(c, e, dup_strs);
	  if (!enn)
	      x->idhrxml_NotifyResponse = en;
	  else
	      enn->gg.g.n = &en->gg.g;
	  enn = en;
      }
  }

  return x;
}

/* FUNC(zx_WALK_SO_e_Body) */

/* Depth first traversal of the tree in either schema order or the wire order. */
 
int zx_WALK_SO_e_Body(struct zx_ctx* c, struct zx_e_Body_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
{
  int ret = callback(&x->gg.g, ctx);
  if (ret)
    return ret;
  
  /* *** deal with xmlns specifications in exc c14n way */


  
  ret = zx_walk_so_unknown_attributes(c, &x->gg, ctx, callback); 
  if (ret)
    return ret;

  {
      struct zx_sp_ArtifactResolve_s* e;
      for (e = x->ArtifactResolve; e; e = (struct zx_sp_ArtifactResolve_s*)e->gg.g.n) {
	  ret = zx_WALK_SO_sp_ArtifactResolve(c, e, ctx, callback);
	  if (ret)
	      return ret;
      }
  }
  {
      struct zx_sp_ArtifactResponse_s* e;
      for (e = x->ArtifactResponse; e; e = (struct zx_sp_ArtifactResponse_s*)e->gg.g.n) {
	  ret = zx_WALK_SO_sp_ArtifactResponse(c, e, ctx, callback);
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
      struct zx_sp_NameIDMappingRequest_s* e;
      for (e = x->NameIDMappingRequest; e; e = (struct zx_sp_NameIDMappingRequest_s*)e->gg.g.n) {
	  ret = zx_WALK_SO_sp_NameIDMappingRequest(c, e, ctx, callback);
	  if (ret)
	      return ret;
      }
  }
  {
      struct zx_sp_NameIDMappingResponse_s* e;
      for (e = x->NameIDMappingResponse; e; e = (struct zx_sp_NameIDMappingResponse_s*)e->gg.g.n) {
	  ret = zx_WALK_SO_sp_NameIDMappingResponse(c, e, ctx, callback);
	  if (ret)
	      return ret;
      }
  }
  {
      struct zx_sp_AttributeQuery_s* e;
      for (e = x->AttributeQuery; e; e = (struct zx_sp_AttributeQuery_s*)e->gg.g.n) {
	  ret = zx_WALK_SO_sp_AttributeQuery(c, e, ctx, callback);
	  if (ret)
	      return ret;
      }
  }
  {
      struct zx_sp_AuthnQuery_s* e;
      for (e = x->AuthnQuery; e; e = (struct zx_sp_AuthnQuery_s*)e->gg.g.n) {
	  ret = zx_WALK_SO_sp_AuthnQuery(c, e, ctx, callback);
	  if (ret)
	      return ret;
      }
  }
  {
      struct zx_sp_AuthzDecisionQuery_s* e;
      for (e = x->AuthzDecisionQuery; e; e = (struct zx_sp_AuthzDecisionQuery_s*)e->gg.g.n) {
	  ret = zx_WALK_SO_sp_AuthzDecisionQuery(c, e, ctx, callback);
	  if (ret)
	      return ret;
      }
  }
  {
      struct zx_sp_AssertionIDRequest_s* e;
      for (e = x->AssertionIDRequest; e; e = (struct zx_sp_AssertionIDRequest_s*)e->gg.g.n) {
	  ret = zx_WALK_SO_sp_AssertionIDRequest(c, e, ctx, callback);
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
      struct zx_sp_AuthnRequest_s* e;
      for (e = x->AuthnRequest; e; e = (struct zx_sp_AuthnRequest_s*)e->gg.g.n) {
	  ret = zx_WALK_SO_sp_AuthnRequest(c, e, ctx, callback);
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
  {
      struct zx_xac_Request_s* e;
      for (e = x->xac_Request; e; e = (struct zx_xac_Request_s*)e->gg.g.n) {
	  ret = zx_WALK_SO_xac_Request(c, e, ctx, callback);
	  if (ret)
	      return ret;
      }
  }
  {
      struct zx_xac_Response_s* e;
      for (e = x->xac_Response; e; e = (struct zx_xac_Response_s*)e->gg.g.n) {
	  ret = zx_WALK_SO_xac_Response(c, e, ctx, callback);
	  if (ret)
	      return ret;
      }
  }
  {
      struct zx_di_Query_s* e;
      for (e = x->Query; e; e = (struct zx_di_Query_s*)e->gg.g.n) {
	  ret = zx_WALK_SO_di_Query(c, e, ctx, callback);
	  if (ret)
	      return ret;
      }
  }
  {
      struct zx_di_QueryResponse_s* e;
      for (e = x->QueryResponse; e; e = (struct zx_di_QueryResponse_s*)e->gg.g.n) {
	  ret = zx_WALK_SO_di_QueryResponse(c, e, ctx, callback);
	  if (ret)
	      return ret;
      }
  }
  {
      struct zx_di12_Query_s* e;
      for (e = x->di12_Query; e; e = (struct zx_di12_Query_s*)e->gg.g.n) {
	  ret = zx_WALK_SO_di12_Query(c, e, ctx, callback);
	  if (ret)
	      return ret;
      }
  }
  {
      struct zx_di12_QueryResponse_s* e;
      for (e = x->di12_QueryResponse; e; e = (struct zx_di12_QueryResponse_s*)e->gg.g.n) {
	  ret = zx_WALK_SO_di12_QueryResponse(c, e, ctx, callback);
	  if (ret)
	      return ret;
      }
  }
  {
      struct zx_di12_Modify_s* e;
      for (e = x->Modify; e; e = (struct zx_di12_Modify_s*)e->gg.g.n) {
	  ret = zx_WALK_SO_di12_Modify(c, e, ctx, callback);
	  if (ret)
	      return ret;
      }
  }
  {
      struct zx_di12_ModifyResponse_s* e;
      for (e = x->ModifyResponse; e; e = (struct zx_di12_ModifyResponse_s*)e->gg.g.n) {
	  ret = zx_WALK_SO_di12_ModifyResponse(c, e, ctx, callback);
	  if (ret)
	      return ret;
      }
  }
  {
      struct zx_e_Fault_s* e;
      for (e = x->Fault; e; e = (struct zx_e_Fault_s*)e->gg.g.n) {
	  ret = zx_WALK_SO_e_Fault(c, e, ctx, callback);
	  if (ret)
	      return ret;
      }
  }
  {
      struct zx_di_SvcMDAssociationAdd_s* e;
      for (e = x->SvcMDAssociationAdd; e; e = (struct zx_di_SvcMDAssociationAdd_s*)e->gg.g.n) {
	  ret = zx_WALK_SO_di_SvcMDAssociationAdd(c, e, ctx, callback);
	  if (ret)
	      return ret;
      }
  }
  {
      struct zx_di_SvcMDAssociationAddResponse_s* e;
      for (e = x->SvcMDAssociationAddResponse; e; e = (struct zx_di_SvcMDAssociationAddResponse_s*)e->gg.g.n) {
	  ret = zx_WALK_SO_di_SvcMDAssociationAddResponse(c, e, ctx, callback);
	  if (ret)
	      return ret;
      }
  }
  {
      struct zx_di_SvcMDAssociationDelete_s* e;
      for (e = x->SvcMDAssociationDelete; e; e = (struct zx_di_SvcMDAssociationDelete_s*)e->gg.g.n) {
	  ret = zx_WALK_SO_di_SvcMDAssociationDelete(c, e, ctx, callback);
	  if (ret)
	      return ret;
      }
  }
  {
      struct zx_di_SvcMDAssociationDeleteResponse_s* e;
      for (e = x->SvcMDAssociationDeleteResponse; e; e = (struct zx_di_SvcMDAssociationDeleteResponse_s*)e->gg.g.n) {
	  ret = zx_WALK_SO_di_SvcMDAssociationDeleteResponse(c, e, ctx, callback);
	  if (ret)
	      return ret;
      }
  }
  {
      struct zx_di_SvcMDAssociationQuery_s* e;
      for (e = x->SvcMDAssociationQuery; e; e = (struct zx_di_SvcMDAssociationQuery_s*)e->gg.g.n) {
	  ret = zx_WALK_SO_di_SvcMDAssociationQuery(c, e, ctx, callback);
	  if (ret)
	      return ret;
      }
  }
  {
      struct zx_di_SvcMDAssociationQueryResponse_s* e;
      for (e = x->SvcMDAssociationQueryResponse; e; e = (struct zx_di_SvcMDAssociationQueryResponse_s*)e->gg.g.n) {
	  ret = zx_WALK_SO_di_SvcMDAssociationQueryResponse(c, e, ctx, callback);
	  if (ret)
	      return ret;
      }
  }
  {
      struct zx_di_SvcMDRegister_s* e;
      for (e = x->SvcMDRegister; e; e = (struct zx_di_SvcMDRegister_s*)e->gg.g.n) {
	  ret = zx_WALK_SO_di_SvcMDRegister(c, e, ctx, callback);
	  if (ret)
	      return ret;
      }
  }
  {
      struct zx_di_SvcMDRegisterResponse_s* e;
      for (e = x->SvcMDRegisterResponse; e; e = (struct zx_di_SvcMDRegisterResponse_s*)e->gg.g.n) {
	  ret = zx_WALK_SO_di_SvcMDRegisterResponse(c, e, ctx, callback);
	  if (ret)
	      return ret;
      }
  }
  {
      struct zx_di_SvcMDDelete_s* e;
      for (e = x->SvcMDDelete; e; e = (struct zx_di_SvcMDDelete_s*)e->gg.g.n) {
	  ret = zx_WALK_SO_di_SvcMDDelete(c, e, ctx, callback);
	  if (ret)
	      return ret;
      }
  }
  {
      struct zx_di_SvcMDDeleteResponse_s* e;
      for (e = x->SvcMDDeleteResponse; e; e = (struct zx_di_SvcMDDeleteResponse_s*)e->gg.g.n) {
	  ret = zx_WALK_SO_di_SvcMDDeleteResponse(c, e, ctx, callback);
	  if (ret)
	      return ret;
      }
  }
  {
      struct zx_di_SvcMDQuery_s* e;
      for (e = x->SvcMDQuery; e; e = (struct zx_di_SvcMDQuery_s*)e->gg.g.n) {
	  ret = zx_WALK_SO_di_SvcMDQuery(c, e, ctx, callback);
	  if (ret)
	      return ret;
      }
  }
  {
      struct zx_di_SvcMDQueryResponse_s* e;
      for (e = x->SvcMDQueryResponse; e; e = (struct zx_di_SvcMDQueryResponse_s*)e->gg.g.n) {
	  ret = zx_WALK_SO_di_SvcMDQueryResponse(c, e, ctx, callback);
	  if (ret)
	      return ret;
      }
  }
  {
      struct zx_di_SvcMDReplace_s* e;
      for (e = x->SvcMDReplace; e; e = (struct zx_di_SvcMDReplace_s*)e->gg.g.n) {
	  ret = zx_WALK_SO_di_SvcMDReplace(c, e, ctx, callback);
	  if (ret)
	      return ret;
      }
  }
  {
      struct zx_di_SvcMDReplaceResponse_s* e;
      for (e = x->SvcMDReplaceResponse; e; e = (struct zx_di_SvcMDReplaceResponse_s*)e->gg.g.n) {
	  ret = zx_WALK_SO_di_SvcMDReplaceResponse(c, e, ctx, callback);
	  if (ret)
	      return ret;
      }
  }
  {
      struct zx_dap_Create_s* e;
      for (e = x->Create; e; e = (struct zx_dap_Create_s*)e->gg.g.n) {
	  ret = zx_WALK_SO_dap_Create(c, e, ctx, callback);
	  if (ret)
	      return ret;
      }
  }
  {
      struct zx_dap_CreateResponse_s* e;
      for (e = x->CreateResponse; e; e = (struct zx_dap_CreateResponse_s*)e->gg.g.n) {
	  ret = zx_WALK_SO_dap_CreateResponse(c, e, ctx, callback);
	  if (ret)
	      return ret;
      }
  }
  {
      struct zx_dap_Query_s* e;
      for (e = x->dap_Query; e; e = (struct zx_dap_Query_s*)e->gg.g.n) {
	  ret = zx_WALK_SO_dap_Query(c, e, ctx, callback);
	  if (ret)
	      return ret;
      }
  }
  {
      struct zx_dap_QueryResponse_s* e;
      for (e = x->dap_QueryResponse; e; e = (struct zx_dap_QueryResponse_s*)e->gg.g.n) {
	  ret = zx_WALK_SO_dap_QueryResponse(c, e, ctx, callback);
	  if (ret)
	      return ret;
      }
  }
  {
      struct zx_dap_Modify_s* e;
      for (e = x->dap_Modify; e; e = (struct zx_dap_Modify_s*)e->gg.g.n) {
	  ret = zx_WALK_SO_dap_Modify(c, e, ctx, callback);
	  if (ret)
	      return ret;
      }
  }
  {
      struct zx_dap_ModifyResponse_s* e;
      for (e = x->dap_ModifyResponse; e; e = (struct zx_dap_ModifyResponse_s*)e->gg.g.n) {
	  ret = zx_WALK_SO_dap_ModifyResponse(c, e, ctx, callback);
	  if (ret)
	      return ret;
      }
  }
  {
      struct zx_dap_Delete_s* e;
      for (e = x->Delete; e; e = (struct zx_dap_Delete_s*)e->gg.g.n) {
	  ret = zx_WALK_SO_dap_Delete(c, e, ctx, callback);
	  if (ret)
	      return ret;
      }
  }
  {
      struct zx_dap_DeleteResponse_s* e;
      for (e = x->DeleteResponse; e; e = (struct zx_dap_DeleteResponse_s*)e->gg.g.n) {
	  ret = zx_WALK_SO_dap_DeleteResponse(c, e, ctx, callback);
	  if (ret)
	      return ret;
      }
  }
  {
      struct zx_dap_Notify_s* e;
      for (e = x->Notify; e; e = (struct zx_dap_Notify_s*)e->gg.g.n) {
	  ret = zx_WALK_SO_dap_Notify(c, e, ctx, callback);
	  if (ret)
	      return ret;
      }
  }
  {
      struct zx_dap_NotifyResponse_s* e;
      for (e = x->NotifyResponse; e; e = (struct zx_dap_NotifyResponse_s*)e->gg.g.n) {
	  ret = zx_WALK_SO_dap_NotifyResponse(c, e, ctx, callback);
	  if (ret)
	      return ret;
      }
  }
  {
      struct zx_ps_AddEntityRequest_s* e;
      for (e = x->AddEntityRequest; e; e = (struct zx_ps_AddEntityRequest_s*)e->gg.g.n) {
	  ret = zx_WALK_SO_ps_AddEntityRequest(c, e, ctx, callback);
	  if (ret)
	      return ret;
      }
  }
  {
      struct zx_ps_AddEntityResponse_s* e;
      for (e = x->AddEntityResponse; e; e = (struct zx_ps_AddEntityResponse_s*)e->gg.g.n) {
	  ret = zx_WALK_SO_ps_AddEntityResponse(c, e, ctx, callback);
	  if (ret)
	      return ret;
      }
  }
  {
      struct zx_ps_AddKnownEntityRequest_s* e;
      for (e = x->AddKnownEntityRequest; e; e = (struct zx_ps_AddKnownEntityRequest_s*)e->gg.g.n) {
	  ret = zx_WALK_SO_ps_AddKnownEntityRequest(c, e, ctx, callback);
	  if (ret)
	      return ret;
      }
  }
  {
      struct zx_ps_AddKnownEntityResponse_s* e;
      for (e = x->AddKnownEntityResponse; e; e = (struct zx_ps_AddKnownEntityResponse_s*)e->gg.g.n) {
	  ret = zx_WALK_SO_ps_AddKnownEntityResponse(c, e, ctx, callback);
	  if (ret)
	      return ret;
      }
  }
  {
      struct zx_ps_AddCollectionRequest_s* e;
      for (e = x->AddCollectionRequest; e; e = (struct zx_ps_AddCollectionRequest_s*)e->gg.g.n) {
	  ret = zx_WALK_SO_ps_AddCollectionRequest(c, e, ctx, callback);
	  if (ret)
	      return ret;
      }
  }
  {
      struct zx_ps_AddCollectionResponse_s* e;
      for (e = x->AddCollectionResponse; e; e = (struct zx_ps_AddCollectionResponse_s*)e->gg.g.n) {
	  ret = zx_WALK_SO_ps_AddCollectionResponse(c, e, ctx, callback);
	  if (ret)
	      return ret;
      }
  }
  {
      struct zx_ps_AddToCollectionRequest_s* e;
      for (e = x->AddToCollectionRequest; e; e = (struct zx_ps_AddToCollectionRequest_s*)e->gg.g.n) {
	  ret = zx_WALK_SO_ps_AddToCollectionRequest(c, e, ctx, callback);
	  if (ret)
	      return ret;
      }
  }
  {
      struct zx_ps_AddToCollectionResponse_s* e;
      for (e = x->AddToCollectionResponse; e; e = (struct zx_ps_AddToCollectionResponse_s*)e->gg.g.n) {
	  ret = zx_WALK_SO_ps_AddToCollectionResponse(c, e, ctx, callback);
	  if (ret)
	      return ret;
      }
  }
  {
      struct zx_ps_RemoveEntityRequest_s* e;
      for (e = x->RemoveEntityRequest; e; e = (struct zx_ps_RemoveEntityRequest_s*)e->gg.g.n) {
	  ret = zx_WALK_SO_ps_RemoveEntityRequest(c, e, ctx, callback);
	  if (ret)
	      return ret;
      }
  }
  {
      struct zx_ps_RemoveEntityResponse_s* e;
      for (e = x->RemoveEntityResponse; e; e = (struct zx_ps_RemoveEntityResponse_s*)e->gg.g.n) {
	  ret = zx_WALK_SO_ps_RemoveEntityResponse(c, e, ctx, callback);
	  if (ret)
	      return ret;
      }
  }
  {
      struct zx_ps_RemoveCollectionRequest_s* e;
      for (e = x->RemoveCollectionRequest; e; e = (struct zx_ps_RemoveCollectionRequest_s*)e->gg.g.n) {
	  ret = zx_WALK_SO_ps_RemoveCollectionRequest(c, e, ctx, callback);
	  if (ret)
	      return ret;
      }
  }
  {
      struct zx_ps_RemoveCollectionResponse_s* e;
      for (e = x->RemoveCollectionResponse; e; e = (struct zx_ps_RemoveCollectionResponse_s*)e->gg.g.n) {
	  ret = zx_WALK_SO_ps_RemoveCollectionResponse(c, e, ctx, callback);
	  if (ret)
	      return ret;
      }
  }
  {
      struct zx_ps_RemoveFromCollectionRequest_s* e;
      for (e = x->RemoveFromCollectionRequest; e; e = (struct zx_ps_RemoveFromCollectionRequest_s*)e->gg.g.n) {
	  ret = zx_WALK_SO_ps_RemoveFromCollectionRequest(c, e, ctx, callback);
	  if (ret)
	      return ret;
      }
  }
  {
      struct zx_ps_RemoveFromCollectionResponse_s* e;
      for (e = x->RemoveFromCollectionResponse; e; e = (struct zx_ps_RemoveFromCollectionResponse_s*)e->gg.g.n) {
	  ret = zx_WALK_SO_ps_RemoveFromCollectionResponse(c, e, ctx, callback);
	  if (ret)
	      return ret;
      }
  }
  {
      struct zx_ps_ListMembersRequest_s* e;
      for (e = x->ListMembersRequest; e; e = (struct zx_ps_ListMembersRequest_s*)e->gg.g.n) {
	  ret = zx_WALK_SO_ps_ListMembersRequest(c, e, ctx, callback);
	  if (ret)
	      return ret;
      }
  }
  {
      struct zx_ps_ListMembersResponse_s* e;
      for (e = x->ListMembersResponse; e; e = (struct zx_ps_ListMembersResponse_s*)e->gg.g.n) {
	  ret = zx_WALK_SO_ps_ListMembersResponse(c, e, ctx, callback);
	  if (ret)
	      return ret;
      }
  }
  {
      struct zx_ps_QueryObjectsRequest_s* e;
      for (e = x->QueryObjectsRequest; e; e = (struct zx_ps_QueryObjectsRequest_s*)e->gg.g.n) {
	  ret = zx_WALK_SO_ps_QueryObjectsRequest(c, e, ctx, callback);
	  if (ret)
	      return ret;
      }
  }
  {
      struct zx_ps_QueryObjectsResponse_s* e;
      for (e = x->QueryObjectsResponse; e; e = (struct zx_ps_QueryObjectsResponse_s*)e->gg.g.n) {
	  ret = zx_WALK_SO_ps_QueryObjectsResponse(c, e, ctx, callback);
	  if (ret)
	      return ret;
      }
  }
  {
      struct zx_ps_GetObjectInfoRequest_s* e;
      for (e = x->GetObjectInfoRequest; e; e = (struct zx_ps_GetObjectInfoRequest_s*)e->gg.g.n) {
	  ret = zx_WALK_SO_ps_GetObjectInfoRequest(c, e, ctx, callback);
	  if (ret)
	      return ret;
      }
  }
  {
      struct zx_ps_GetObjectInfoResponse_s* e;
      for (e = x->GetObjectInfoResponse; e; e = (struct zx_ps_GetObjectInfoResponse_s*)e->gg.g.n) {
	  ret = zx_WALK_SO_ps_GetObjectInfoResponse(c, e, ctx, callback);
	  if (ret)
	      return ret;
      }
  }
  {
      struct zx_ps_SetObjectInfoRequest_s* e;
      for (e = x->SetObjectInfoRequest; e; e = (struct zx_ps_SetObjectInfoRequest_s*)e->gg.g.n) {
	  ret = zx_WALK_SO_ps_SetObjectInfoRequest(c, e, ctx, callback);
	  if (ret)
	      return ret;
      }
  }
  {
      struct zx_ps_SetObjectInfoResponse_s* e;
      for (e = x->SetObjectInfoResponse; e; e = (struct zx_ps_SetObjectInfoResponse_s*)e->gg.g.n) {
	  ret = zx_WALK_SO_ps_SetObjectInfoResponse(c, e, ctx, callback);
	  if (ret)
	      return ret;
      }
  }
  {
      struct zx_ps_TestMembershipRequest_s* e;
      for (e = x->TestMembershipRequest; e; e = (struct zx_ps_TestMembershipRequest_s*)e->gg.g.n) {
	  ret = zx_WALK_SO_ps_TestMembershipRequest(c, e, ctx, callback);
	  if (ret)
	      return ret;
      }
  }
  {
      struct zx_ps_TestMembershipResponse_s* e;
      for (e = x->TestMembershipResponse; e; e = (struct zx_ps_TestMembershipResponse_s*)e->gg.g.n) {
	  ret = zx_WALK_SO_ps_TestMembershipResponse(c, e, ctx, callback);
	  if (ret)
	      return ret;
      }
  }
  {
      struct zx_ps_ResolveIdentifierRequest_s* e;
      for (e = x->ResolveIdentifierRequest; e; e = (struct zx_ps_ResolveIdentifierRequest_s*)e->gg.g.n) {
	  ret = zx_WALK_SO_ps_ResolveIdentifierRequest(c, e, ctx, callback);
	  if (ret)
	      return ret;
      }
  }
  {
      struct zx_ps_ResolveIdentifierResponse_s* e;
      for (e = x->ResolveIdentifierResponse; e; e = (struct zx_ps_ResolveIdentifierResponse_s*)e->gg.g.n) {
	  ret = zx_WALK_SO_ps_ResolveIdentifierResponse(c, e, ctx, callback);
	  if (ret)
	      return ret;
      }
  }
  {
      struct zx_ps_Notify_s* e;
      for (e = x->ps_Notify; e; e = (struct zx_ps_Notify_s*)e->gg.g.n) {
	  ret = zx_WALK_SO_ps_Notify(c, e, ctx, callback);
	  if (ret)
	      return ret;
      }
  }
  {
      struct zx_ps_NotifyResponse_s* e;
      for (e = x->ps_NotifyResponse; e; e = (struct zx_ps_NotifyResponse_s*)e->gg.g.n) {
	  ret = zx_WALK_SO_ps_NotifyResponse(c, e, ctx, callback);
	  if (ret)
	      return ret;
      }
  }
  {
      struct zx_im_IdentityMappingRequest_s* e;
      for (e = x->IdentityMappingRequest; e; e = (struct zx_im_IdentityMappingRequest_s*)e->gg.g.n) {
	  ret = zx_WALK_SO_im_IdentityMappingRequest(c, e, ctx, callback);
	  if (ret)
	      return ret;
      }
  }
  {
      struct zx_im_IdentityMappingResponse_s* e;
      for (e = x->IdentityMappingResponse; e; e = (struct zx_im_IdentityMappingResponse_s*)e->gg.g.n) {
	  ret = zx_WALK_SO_im_IdentityMappingResponse(c, e, ctx, callback);
	  if (ret)
	      return ret;
      }
  }
  {
      struct zx_as_SASLRequest_s* e;
      for (e = x->SASLRequest; e; e = (struct zx_as_SASLRequest_s*)e->gg.g.n) {
	  ret = zx_WALK_SO_as_SASLRequest(c, e, ctx, callback);
	  if (ret)
	      return ret;
      }
  }
  {
      struct zx_as_SASLResponse_s* e;
      for (e = x->SASLResponse; e; e = (struct zx_as_SASLResponse_s*)e->gg.g.n) {
	  ret = zx_WALK_SO_as_SASLResponse(c, e, ctx, callback);
	  if (ret)
	      return ret;
      }
  }
  {
      struct zx_mm7_SubmitReq_s* e;
      for (e = x->SubmitReq; e; e = (struct zx_mm7_SubmitReq_s*)e->gg.g.n) {
	  ret = zx_WALK_SO_mm7_SubmitReq(c, e, ctx, callback);
	  if (ret)
	      return ret;
      }
  }
  {
      struct zx_mm7_SubmitRsp_s* e;
      for (e = x->SubmitRsp; e; e = (struct zx_mm7_SubmitRsp_s*)e->gg.g.n) {
	  ret = zx_WALK_SO_mm7_SubmitRsp(c, e, ctx, callback);
	  if (ret)
	      return ret;
      }
  }
  {
      struct zx_mm7_DeliverReq_s* e;
      for (e = x->DeliverReq; e; e = (struct zx_mm7_DeliverReq_s*)e->gg.g.n) {
	  ret = zx_WALK_SO_mm7_DeliverReq(c, e, ctx, callback);
	  if (ret)
	      return ret;
      }
  }
  {
      struct zx_mm7_DeliverRsp_s* e;
      for (e = x->DeliverRsp; e; e = (struct zx_mm7_DeliverRsp_s*)e->gg.g.n) {
	  ret = zx_WALK_SO_mm7_DeliverRsp(c, e, ctx, callback);
	  if (ret)
	      return ret;
      }
  }
  {
      struct zx_mm7_CancelReq_s* e;
      for (e = x->CancelReq; e; e = (struct zx_mm7_CancelReq_s*)e->gg.g.n) {
	  ret = zx_WALK_SO_mm7_CancelReq(c, e, ctx, callback);
	  if (ret)
	      return ret;
      }
  }
  {
      struct zx_mm7_CancelRsp_s* e;
      for (e = x->CancelRsp; e; e = (struct zx_mm7_CancelRsp_s*)e->gg.g.n) {
	  ret = zx_WALK_SO_mm7_CancelRsp(c, e, ctx, callback);
	  if (ret)
	      return ret;
      }
  }
  {
      struct zx_mm7_ReplaceReq_s* e;
      for (e = x->ReplaceReq; e; e = (struct zx_mm7_ReplaceReq_s*)e->gg.g.n) {
	  ret = zx_WALK_SO_mm7_ReplaceReq(c, e, ctx, callback);
	  if (ret)
	      return ret;
      }
  }
  {
      struct zx_mm7_ReplaceRsp_s* e;
      for (e = x->ReplaceRsp; e; e = (struct zx_mm7_ReplaceRsp_s*)e->gg.g.n) {
	  ret = zx_WALK_SO_mm7_ReplaceRsp(c, e, ctx, callback);
	  if (ret)
	      return ret;
      }
  }
  {
      struct zx_mm7_extendedCancelReq_s* e;
      for (e = x->extendedCancelReq; e; e = (struct zx_mm7_extendedCancelReq_s*)e->gg.g.n) {
	  ret = zx_WALK_SO_mm7_extendedCancelReq(c, e, ctx, callback);
	  if (ret)
	      return ret;
      }
  }
  {
      struct zx_mm7_extendedCancelRsp_s* e;
      for (e = x->extendedCancelRsp; e; e = (struct zx_mm7_extendedCancelRsp_s*)e->gg.g.n) {
	  ret = zx_WALK_SO_mm7_extendedCancelRsp(c, e, ctx, callback);
	  if (ret)
	      return ret;
      }
  }
  {
      struct zx_mm7_extendedReplaceReq_s* e;
      for (e = x->extendedReplaceReq; e; e = (struct zx_mm7_extendedReplaceReq_s*)e->gg.g.n) {
	  ret = zx_WALK_SO_mm7_extendedReplaceReq(c, e, ctx, callback);
	  if (ret)
	      return ret;
      }
  }
  {
      struct zx_mm7_extendedReplaceRsp_s* e;
      for (e = x->extendedReplaceRsp; e; e = (struct zx_mm7_extendedReplaceRsp_s*)e->gg.g.n) {
	  ret = zx_WALK_SO_mm7_extendedReplaceRsp(c, e, ctx, callback);
	  if (ret)
	      return ret;
      }
  }
  {
      struct zx_mm7_DeliveryReportReq_s* e;
      for (e = x->DeliveryReportReq; e; e = (struct zx_mm7_DeliveryReportReq_s*)e->gg.g.n) {
	  ret = zx_WALK_SO_mm7_DeliveryReportReq(c, e, ctx, callback);
	  if (ret)
	      return ret;
      }
  }
  {
      struct zx_mm7_DeliveryReportRsp_s* e;
      for (e = x->DeliveryReportRsp; e; e = (struct zx_mm7_DeliveryReportRsp_s*)e->gg.g.n) {
	  ret = zx_WALK_SO_mm7_DeliveryReportRsp(c, e, ctx, callback);
	  if (ret)
	      return ret;
      }
  }
  {
      struct zx_mm7_ReadReplyReq_s* e;
      for (e = x->ReadReplyReq; e; e = (struct zx_mm7_ReadReplyReq_s*)e->gg.g.n) {
	  ret = zx_WALK_SO_mm7_ReadReplyReq(c, e, ctx, callback);
	  if (ret)
	      return ret;
      }
  }
  {
      struct zx_mm7_ReadReplyRsp_s* e;
      for (e = x->ReadReplyRsp; e; e = (struct zx_mm7_ReadReplyRsp_s*)e->gg.g.n) {
	  ret = zx_WALK_SO_mm7_ReadReplyRsp(c, e, ctx, callback);
	  if (ret)
	      return ret;
      }
  }
  {
      struct zx_mm7_RSErrorRsp_s* e;
      for (e = x->RSErrorRsp; e; e = (struct zx_mm7_RSErrorRsp_s*)e->gg.g.n) {
	  ret = zx_WALK_SO_mm7_RSErrorRsp(c, e, ctx, callback);
	  if (ret)
	      return ret;
      }
  }
  {
      struct zx_mm7_VASPErrorRsp_s* e;
      for (e = x->VASPErrorRsp; e; e = (struct zx_mm7_VASPErrorRsp_s*)e->gg.g.n) {
	  ret = zx_WALK_SO_mm7_VASPErrorRsp(c, e, ctx, callback);
	  if (ret)
	      return ret;
      }
  }
  {
      struct zx_mm7_QueryStatusReq_s* e;
      for (e = x->QueryStatusReq; e; e = (struct zx_mm7_QueryStatusReq_s*)e->gg.g.n) {
	  ret = zx_WALK_SO_mm7_QueryStatusReq(c, e, ctx, callback);
	  if (ret)
	      return ret;
      }
  }
  {
      struct zx_mm7_QueryStatusRsp_s* e;
      for (e = x->QueryStatusRsp; e; e = (struct zx_mm7_QueryStatusRsp_s*)e->gg.g.n) {
	  ret = zx_WALK_SO_mm7_QueryStatusRsp(c, e, ctx, callback);
	  if (ret)
	      return ret;
      }
  }
  {
      struct zx_cb_Query_s* e;
      for (e = x->cb_Query; e; e = (struct zx_cb_Query_s*)e->gg.g.n) {
	  ret = zx_WALK_SO_cb_Query(c, e, ctx, callback);
	  if (ret)
	      return ret;
      }
  }
  {
      struct zx_cb_QueryResponse_s* e;
      for (e = x->cb_QueryResponse; e; e = (struct zx_cb_QueryResponse_s*)e->gg.g.n) {
	  ret = zx_WALK_SO_cb_QueryResponse(c, e, ctx, callback);
	  if (ret)
	      return ret;
      }
  }
  {
      struct zx_cb_Create_s* e;
      for (e = x->cb_Create; e; e = (struct zx_cb_Create_s*)e->gg.g.n) {
	  ret = zx_WALK_SO_cb_Create(c, e, ctx, callback);
	  if (ret)
	      return ret;
      }
  }
  {
      struct zx_cb_CreateResponse_s* e;
      for (e = x->cb_CreateResponse; e; e = (struct zx_cb_CreateResponse_s*)e->gg.g.n) {
	  ret = zx_WALK_SO_cb_CreateResponse(c, e, ctx, callback);
	  if (ret)
	      return ret;
      }
  }
  {
      struct zx_cb_Delete_s* e;
      for (e = x->cb_Delete; e; e = (struct zx_cb_Delete_s*)e->gg.g.n) {
	  ret = zx_WALK_SO_cb_Delete(c, e, ctx, callback);
	  if (ret)
	      return ret;
      }
  }
  {
      struct zx_cb_DeleteResponse_s* e;
      for (e = x->cb_DeleteResponse; e; e = (struct zx_cb_DeleteResponse_s*)e->gg.g.n) {
	  ret = zx_WALK_SO_cb_DeleteResponse(c, e, ctx, callback);
	  if (ret)
	      return ret;
      }
  }
  {
      struct zx_cb_Modify_s* e;
      for (e = x->cb_Modify; e; e = (struct zx_cb_Modify_s*)e->gg.g.n) {
	  ret = zx_WALK_SO_cb_Modify(c, e, ctx, callback);
	  if (ret)
	      return ret;
      }
  }
  {
      struct zx_cb_ModifyResponse_s* e;
      for (e = x->cb_ModifyResponse; e; e = (struct zx_cb_ModifyResponse_s*)e->gg.g.n) {
	  ret = zx_WALK_SO_cb_ModifyResponse(c, e, ctx, callback);
	  if (ret)
	      return ret;
      }
  }
  {
      struct zx_cb_Notify_s* e;
      for (e = x->cb_Notify; e; e = (struct zx_cb_Notify_s*)e->gg.g.n) {
	  ret = zx_WALK_SO_cb_Notify(c, e, ctx, callback);
	  if (ret)
	      return ret;
      }
  }
  {
      struct zx_cb_NotifyResponse_s* e;
      for (e = x->cb_NotifyResponse; e; e = (struct zx_cb_NotifyResponse_s*)e->gg.g.n) {
	  ret = zx_WALK_SO_cb_NotifyResponse(c, e, ctx, callback);
	  if (ret)
	      return ret;
      }
  }
  {
      struct zx_cb_ReportUsage_s* e;
      for (e = x->ReportUsage; e; e = (struct zx_cb_ReportUsage_s*)e->gg.g.n) {
	  ret = zx_WALK_SO_cb_ReportUsage(c, e, ctx, callback);
	  if (ret)
	      return ret;
      }
  }
  {
      struct zx_cb_ReportUsageResponse_s* e;
      for (e = x->ReportUsageResponse; e; e = (struct zx_cb_ReportUsageResponse_s*)e->gg.g.n) {
	  ret = zx_WALK_SO_cb_ReportUsageResponse(c, e, ctx, callback);
	  if (ret)
	      return ret;
      }
  }
  {
      struct zx_gl_Query_s* e;
      for (e = x->gl_Query; e; e = (struct zx_gl_Query_s*)e->gg.g.n) {
	  ret = zx_WALK_SO_gl_Query(c, e, ctx, callback);
	  if (ret)
	      return ret;
      }
  }
  {
      struct zx_gl_QueryResponse_s* e;
      for (e = x->gl_QueryResponse; e; e = (struct zx_gl_QueryResponse_s*)e->gg.g.n) {
	  ret = zx_WALK_SO_gl_QueryResponse(c, e, ctx, callback);
	  if (ret)
	      return ret;
      }
  }
  {
      struct zx_gl_Create_s* e;
      for (e = x->gl_Create; e; e = (struct zx_gl_Create_s*)e->gg.g.n) {
	  ret = zx_WALK_SO_gl_Create(c, e, ctx, callback);
	  if (ret)
	      return ret;
      }
  }
  {
      struct zx_gl_CreateResponse_s* e;
      for (e = x->gl_CreateResponse; e; e = (struct zx_gl_CreateResponse_s*)e->gg.g.n) {
	  ret = zx_WALK_SO_gl_CreateResponse(c, e, ctx, callback);
	  if (ret)
	      return ret;
      }
  }
  {
      struct zx_gl_Delete_s* e;
      for (e = x->gl_Delete; e; e = (struct zx_gl_Delete_s*)e->gg.g.n) {
	  ret = zx_WALK_SO_gl_Delete(c, e, ctx, callback);
	  if (ret)
	      return ret;
      }
  }
  {
      struct zx_gl_DeleteResponse_s* e;
      for (e = x->gl_DeleteResponse; e; e = (struct zx_gl_DeleteResponse_s*)e->gg.g.n) {
	  ret = zx_WALK_SO_gl_DeleteResponse(c, e, ctx, callback);
	  if (ret)
	      return ret;
      }
  }
  {
      struct zx_gl_Modify_s* e;
      for (e = x->gl_Modify; e; e = (struct zx_gl_Modify_s*)e->gg.g.n) {
	  ret = zx_WALK_SO_gl_Modify(c, e, ctx, callback);
	  if (ret)
	      return ret;
      }
  }
  {
      struct zx_gl_ModifyResponse_s* e;
      for (e = x->gl_ModifyResponse; e; e = (struct zx_gl_ModifyResponse_s*)e->gg.g.n) {
	  ret = zx_WALK_SO_gl_ModifyResponse(c, e, ctx, callback);
	  if (ret)
	      return ret;
      }
  }
  {
      struct zx_gl_Notify_s* e;
      for (e = x->gl_Notify; e; e = (struct zx_gl_Notify_s*)e->gg.g.n) {
	  ret = zx_WALK_SO_gl_Notify(c, e, ctx, callback);
	  if (ret)
	      return ret;
      }
  }
  {
      struct zx_gl_NotifyResponse_s* e;
      for (e = x->gl_NotifyResponse; e; e = (struct zx_gl_NotifyResponse_s*)e->gg.g.n) {
	  ret = zx_WALK_SO_gl_NotifyResponse(c, e, ctx, callback);
	  if (ret)
	      return ret;
      }
  }
  {
      struct zx_demomed_StoreObjectRequest_s* e;
      for (e = x->StoreObjectRequest; e; e = (struct zx_demomed_StoreObjectRequest_s*)e->gg.g.n) {
	  ret = zx_WALK_SO_demomed_StoreObjectRequest(c, e, ctx, callback);
	  if (ret)
	      return ret;
      }
  }
  {
      struct zx_demomed_StoreObjectResponse_s* e;
      for (e = x->StoreObjectResponse; e; e = (struct zx_demomed_StoreObjectResponse_s*)e->gg.g.n) {
	  ret = zx_WALK_SO_demomed_StoreObjectResponse(c, e, ctx, callback);
	  if (ret)
	      return ret;
      }
  }
  {
      struct zx_demomed_GetObjectListRequest_s* e;
      for (e = x->GetObjectListRequest; e; e = (struct zx_demomed_GetObjectListRequest_s*)e->gg.g.n) {
	  ret = zx_WALK_SO_demomed_GetObjectListRequest(c, e, ctx, callback);
	  if (ret)
	      return ret;
      }
  }
  {
      struct zx_demomed_GetObjectListResponse_s* e;
      for (e = x->GetObjectListResponse; e; e = (struct zx_demomed_GetObjectListResponse_s*)e->gg.g.n) {
	  ret = zx_WALK_SO_demomed_GetObjectListResponse(c, e, ctx, callback);
	  if (ret)
	      return ret;
      }
  }
  {
      struct zx_demomed_GetObjectRequest_s* e;
      for (e = x->GetObjectRequest; e; e = (struct zx_demomed_GetObjectRequest_s*)e->gg.g.n) {
	  ret = zx_WALK_SO_demomed_GetObjectRequest(c, e, ctx, callback);
	  if (ret)
	      return ret;
      }
  }
  {
      struct zx_demomed_GetObjectResponse_s* e;
      for (e = x->GetObjectResponse; e; e = (struct zx_demomed_GetObjectResponse_s*)e->gg.g.n) {
	  ret = zx_WALK_SO_demomed_GetObjectResponse(c, e, ctx, callback);
	  if (ret)
	      return ret;
      }
  }
  {
      struct zx_demomed_DeleteObjectRequest_s* e;
      for (e = x->DeleteObjectRequest; e; e = (struct zx_demomed_DeleteObjectRequest_s*)e->gg.g.n) {
	  ret = zx_WALK_SO_demomed_DeleteObjectRequest(c, e, ctx, callback);
	  if (ret)
	      return ret;
      }
  }
  {
      struct zx_demomed_DeleteObjectResponse_s* e;
      for (e = x->DeleteObjectResponse; e; e = (struct zx_demomed_DeleteObjectResponse_s*)e->gg.g.n) {
	  ret = zx_WALK_SO_demomed_DeleteObjectResponse(c, e, ctx, callback);
	  if (ret)
	      return ret;
      }
  }
  {
      struct zx_pmm_Provision_s* e;
      for (e = x->Provision; e; e = (struct zx_pmm_Provision_s*)e->gg.g.n) {
	  ret = zx_WALK_SO_pmm_Provision(c, e, ctx, callback);
	  if (ret)
	      return ret;
      }
  }
  {
      struct zx_pmm_ProvisionResponse_s* e;
      for (e = x->ProvisionResponse; e; e = (struct zx_pmm_ProvisionResponse_s*)e->gg.g.n) {
	  ret = zx_WALK_SO_pmm_ProvisionResponse(c, e, ctx, callback);
	  if (ret)
	      return ret;
      }
  }
  {
      struct zx_pmm_PMActivate_s* e;
      for (e = x->PMActivate; e; e = (struct zx_pmm_PMActivate_s*)e->gg.g.n) {
	  ret = zx_WALK_SO_pmm_PMActivate(c, e, ctx, callback);
	  if (ret)
	      return ret;
      }
  }
  {
      struct zx_pmm_PMActivateResponse_s* e;
      for (e = x->PMActivateResponse; e; e = (struct zx_pmm_PMActivateResponse_s*)e->gg.g.n) {
	  ret = zx_WALK_SO_pmm_PMActivateResponse(c, e, ctx, callback);
	  if (ret)
	      return ret;
      }
  }
  {
      struct zx_pmm_PMDeactivate_s* e;
      for (e = x->PMDeactivate; e; e = (struct zx_pmm_PMDeactivate_s*)e->gg.g.n) {
	  ret = zx_WALK_SO_pmm_PMDeactivate(c, e, ctx, callback);
	  if (ret)
	      return ret;
      }
  }
  {
      struct zx_pmm_PMDeactivateResponse_s* e;
      for (e = x->PMDeactivateResponse; e; e = (struct zx_pmm_PMDeactivateResponse_s*)e->gg.g.n) {
	  ret = zx_WALK_SO_pmm_PMDeactivateResponse(c, e, ctx, callback);
	  if (ret)
	      return ret;
      }
  }
  {
      struct zx_pmm_PMDelete_s* e;
      for (e = x->PMDelete; e; e = (struct zx_pmm_PMDelete_s*)e->gg.g.n) {
	  ret = zx_WALK_SO_pmm_PMDelete(c, e, ctx, callback);
	  if (ret)
	      return ret;
      }
  }
  {
      struct zx_pmm_PMDeleteResponse_s* e;
      for (e = x->PMDeleteResponse; e; e = (struct zx_pmm_PMDeleteResponse_s*)e->gg.g.n) {
	  ret = zx_WALK_SO_pmm_PMDeleteResponse(c, e, ctx, callback);
	  if (ret)
	      return ret;
      }
  }
  {
      struct zx_pmm_PMUpdate_s* e;
      for (e = x->PMUpdate; e; e = (struct zx_pmm_PMUpdate_s*)e->gg.g.n) {
	  ret = zx_WALK_SO_pmm_PMUpdate(c, e, ctx, callback);
	  if (ret)
	      return ret;
      }
  }
  {
      struct zx_pmm_PMUpdateResponse_s* e;
      for (e = x->PMUpdateResponse; e; e = (struct zx_pmm_PMUpdateResponse_s*)e->gg.g.n) {
	  ret = zx_WALK_SO_pmm_PMUpdateResponse(c, e, ctx, callback);
	  if (ret)
	      return ret;
      }
  }
  {
      struct zx_pmm_PMGetStatus_s* e;
      for (e = x->PMGetStatus; e; e = (struct zx_pmm_PMGetStatus_s*)e->gg.g.n) {
	  ret = zx_WALK_SO_pmm_PMGetStatus(c, e, ctx, callback);
	  if (ret)
	      return ret;
      }
  }
  {
      struct zx_pmm_PMGetStatusResponse_s* e;
      for (e = x->PMGetStatusResponse; e; e = (struct zx_pmm_PMGetStatusResponse_s*)e->gg.g.n) {
	  ret = zx_WALK_SO_pmm_PMGetStatusResponse(c, e, ctx, callback);
	  if (ret)
	      return ret;
      }
  }
  {
      struct zx_pmm_PMSetStatus_s* e;
      for (e = x->PMSetStatus; e; e = (struct zx_pmm_PMSetStatus_s*)e->gg.g.n) {
	  ret = zx_WALK_SO_pmm_PMSetStatus(c, e, ctx, callback);
	  if (ret)
	      return ret;
      }
  }
  {
      struct zx_pmm_PMSetStatusResponse_s* e;
      for (e = x->PMSetStatusResponse; e; e = (struct zx_pmm_PMSetStatusResponse_s*)e->gg.g.n) {
	  ret = zx_WALK_SO_pmm_PMSetStatusResponse(c, e, ctx, callback);
	  if (ret)
	      return ret;
      }
  }
  {
      struct zx_prov_PMERegister_s* e;
      for (e = x->PMERegister; e; e = (struct zx_prov_PMERegister_s*)e->gg.g.n) {
	  ret = zx_WALK_SO_prov_PMERegister(c, e, ctx, callback);
	  if (ret)
	      return ret;
      }
  }
  {
      struct zx_prov_PMERegisterResponse_s* e;
      for (e = x->PMERegisterResponse; e; e = (struct zx_prov_PMERegisterResponse_s*)e->gg.g.n) {
	  ret = zx_WALK_SO_prov_PMERegisterResponse(c, e, ctx, callback);
	  if (ret)
	      return ret;
      }
  }
  {
      struct zx_prov_PMEUpload_s* e;
      for (e = x->PMEUpload; e; e = (struct zx_prov_PMEUpload_s*)e->gg.g.n) {
	  ret = zx_WALK_SO_prov_PMEUpload(c, e, ctx, callback);
	  if (ret)
	      return ret;
      }
  }
  {
      struct zx_prov_PMEUploadResponse_s* e;
      for (e = x->PMEUploadResponse; e; e = (struct zx_prov_PMEUploadResponse_s*)e->gg.g.n) {
	  ret = zx_WALK_SO_prov_PMEUploadResponse(c, e, ctx, callback);
	  if (ret)
	      return ret;
      }
  }
  {
      struct zx_prov_PMEDownload_s* e;
      for (e = x->PMEDownload; e; e = (struct zx_prov_PMEDownload_s*)e->gg.g.n) {
	  ret = zx_WALK_SO_prov_PMEDownload(c, e, ctx, callback);
	  if (ret)
	      return ret;
      }
  }
  {
      struct zx_prov_PMEDownloadResponse_s* e;
      for (e = x->PMEDownloadResponse; e; e = (struct zx_prov_PMEDownloadResponse_s*)e->gg.g.n) {
	  ret = zx_WALK_SO_prov_PMEDownloadResponse(c, e, ctx, callback);
	  if (ret)
	      return ret;
      }
  }
  {
      struct zx_prov_PMEEnable_s* e;
      for (e = x->PMEEnable; e; e = (struct zx_prov_PMEEnable_s*)e->gg.g.n) {
	  ret = zx_WALK_SO_prov_PMEEnable(c, e, ctx, callback);
	  if (ret)
	      return ret;
      }
  }
  {
      struct zx_prov_PMEEnableResponse_s* e;
      for (e = x->PMEEnableResponse; e; e = (struct zx_prov_PMEEnableResponse_s*)e->gg.g.n) {
	  ret = zx_WALK_SO_prov_PMEEnableResponse(c, e, ctx, callback);
	  if (ret)
	      return ret;
      }
  }
  {
      struct zx_prov_PMEDisable_s* e;
      for (e = x->PMEDisable; e; e = (struct zx_prov_PMEDisable_s*)e->gg.g.n) {
	  ret = zx_WALK_SO_prov_PMEDisable(c, e, ctx, callback);
	  if (ret)
	      return ret;
      }
  }
  {
      struct zx_prov_PMEDisableResponse_s* e;
      for (e = x->PMEDisableResponse; e; e = (struct zx_prov_PMEDisableResponse_s*)e->gg.g.n) {
	  ret = zx_WALK_SO_prov_PMEDisableResponse(c, e, ctx, callback);
	  if (ret)
	      return ret;
      }
  }
  {
      struct zx_prov_PMEDelete_s* e;
      for (e = x->PMEDelete; e; e = (struct zx_prov_PMEDelete_s*)e->gg.g.n) {
	  ret = zx_WALK_SO_prov_PMEDelete(c, e, ctx, callback);
	  if (ret)
	      return ret;
      }
  }
  {
      struct zx_prov_PMEDeleteResponse_s* e;
      for (e = x->PMEDeleteResponse; e; e = (struct zx_prov_PMEDeleteResponse_s*)e->gg.g.n) {
	  ret = zx_WALK_SO_prov_PMEDeleteResponse(c, e, ctx, callback);
	  if (ret)
	      return ret;
      }
  }
  {
      struct zx_prov_PMEGetInfo_s* e;
      for (e = x->PMEGetInfo; e; e = (struct zx_prov_PMEGetInfo_s*)e->gg.g.n) {
	  ret = zx_WALK_SO_prov_PMEGetInfo(c, e, ctx, callback);
	  if (ret)
	      return ret;
      }
  }
  {
      struct zx_prov_PMEGetInfoResponse_s* e;
      for (e = x->PMEGetInfoResponse; e; e = (struct zx_prov_PMEGetInfoResponse_s*)e->gg.g.n) {
	  ret = zx_WALK_SO_prov_PMEGetInfoResponse(c, e, ctx, callback);
	  if (ret)
	      return ret;
      }
  }
  {
      struct zx_prov_PMGetStatus_s* e;
      for (e = x->prov_PMGetStatus; e; e = (struct zx_prov_PMGetStatus_s*)e->gg.g.n) {
	  ret = zx_WALK_SO_prov_PMGetStatus(c, e, ctx, callback);
	  if (ret)
	      return ret;
      }
  }
  {
      struct zx_prov_PMGetStatusResponse_s* e;
      for (e = x->prov_PMGetStatusResponse; e; e = (struct zx_prov_PMGetStatusResponse_s*)e->gg.g.n) {
	  ret = zx_WALK_SO_prov_PMGetStatusResponse(c, e, ctx, callback);
	  if (ret)
	      return ret;
      }
  }
  {
      struct zx_prov_PMSetStatus_s* e;
      for (e = x->prov_PMSetStatus; e; e = (struct zx_prov_PMSetStatus_s*)e->gg.g.n) {
	  ret = zx_WALK_SO_prov_PMSetStatus(c, e, ctx, callback);
	  if (ret)
	      return ret;
      }
  }
  {
      struct zx_prov_PMSetStatusResponse_s* e;
      for (e = x->prov_PMSetStatusResponse; e; e = (struct zx_prov_PMSetStatusResponse_s*)e->gg.g.n) {
	  ret = zx_WALK_SO_prov_PMSetStatusResponse(c, e, ctx, callback);
	  if (ret)
	      return ret;
      }
  }
  {
      struct zx_prov_PMGetDescriptor_s* e;
      for (e = x->PMGetDescriptor; e; e = (struct zx_prov_PMGetDescriptor_s*)e->gg.g.n) {
	  ret = zx_WALK_SO_prov_PMGetDescriptor(c, e, ctx, callback);
	  if (ret)
	      return ret;
      }
  }
  {
      struct zx_prov_PMGetDescriptorResponse_s* e;
      for (e = x->PMGetDescriptorResponse; e; e = (struct zx_prov_PMGetDescriptorResponse_s*)e->gg.g.n) {
	  ret = zx_WALK_SO_prov_PMGetDescriptorResponse(c, e, ctx, callback);
	  if (ret)
	      return ret;
      }
  }
  {
      struct zx_prov_PMActivate_s* e;
      for (e = x->prov_PMActivate; e; e = (struct zx_prov_PMActivate_s*)e->gg.g.n) {
	  ret = zx_WALK_SO_prov_PMActivate(c, e, ctx, callback);
	  if (ret)
	      return ret;
      }
  }
  {
      struct zx_prov_PMActivateResponse_s* e;
      for (e = x->prov_PMActivateResponse; e; e = (struct zx_prov_PMActivateResponse_s*)e->gg.g.n) {
	  ret = zx_WALK_SO_prov_PMActivateResponse(c, e, ctx, callback);
	  if (ret)
	      return ret;
      }
  }
  {
      struct zx_prov_PMDeactivate_s* e;
      for (e = x->prov_PMDeactivate; e; e = (struct zx_prov_PMDeactivate_s*)e->gg.g.n) {
	  ret = zx_WALK_SO_prov_PMDeactivate(c, e, ctx, callback);
	  if (ret)
	      return ret;
      }
  }
  {
      struct zx_prov_PMDeactivateResponse_s* e;
      for (e = x->prov_PMDeactivateResponse; e; e = (struct zx_prov_PMDeactivateResponse_s*)e->gg.g.n) {
	  ret = zx_WALK_SO_prov_PMDeactivateResponse(c, e, ctx, callback);
	  if (ret)
	      return ret;
      }
  }
  {
      struct zx_prov_PMRegisterDescriptor_s* e;
      for (e = x->PMRegisterDescriptor; e; e = (struct zx_prov_PMRegisterDescriptor_s*)e->gg.g.n) {
	  ret = zx_WALK_SO_prov_PMRegisterDescriptor(c, e, ctx, callback);
	  if (ret)
	      return ret;
      }
  }
  {
      struct zx_prov_PMRegisterDescriptorResponse_s* e;
      for (e = x->PMRegisterDescriptorResponse; e; e = (struct zx_prov_PMRegisterDescriptorResponse_s*)e->gg.g.n) {
	  ret = zx_WALK_SO_prov_PMRegisterDescriptorResponse(c, e, ctx, callback);
	  if (ret)
	      return ret;
      }
  }
  {
      struct zx_prov_PMUpdate_s* e;
      for (e = x->prov_PMUpdate; e; e = (struct zx_prov_PMUpdate_s*)e->gg.g.n) {
	  ret = zx_WALK_SO_prov_PMUpdate(c, e, ctx, callback);
	  if (ret)
	      return ret;
      }
  }
  {
      struct zx_prov_PMUpdateResponse_s* e;
      for (e = x->prov_PMUpdateResponse; e; e = (struct zx_prov_PMUpdateResponse_s*)e->gg.g.n) {
	  ret = zx_WALK_SO_prov_PMUpdateResponse(c, e, ctx, callback);
	  if (ret)
	      return ret;
      }
  }
  {
      struct zx_prov_PMDelete_s* e;
      for (e = x->prov_PMDelete; e; e = (struct zx_prov_PMDelete_s*)e->gg.g.n) {
	  ret = zx_WALK_SO_prov_PMDelete(c, e, ctx, callback);
	  if (ret)
	      return ret;
      }
  }
  {
      struct zx_prov_PMDeleteResponse_s* e;
      for (e = x->prov_PMDeleteResponse; e; e = (struct zx_prov_PMDeleteResponse_s*)e->gg.g.n) {
	  ret = zx_WALK_SO_prov_PMDeleteResponse(c, e, ctx, callback);
	  if (ret)
	      return ret;
      }
  }
  {
      struct zx_prov_Poll_s* e;
      for (e = x->Poll; e; e = (struct zx_prov_Poll_s*)e->gg.g.n) {
	  ret = zx_WALK_SO_prov_Poll(c, e, ctx, callback);
	  if (ret)
	      return ret;
      }
  }
  {
      struct zx_prov_PollResponse_s* e;
      for (e = x->PollResponse; e; e = (struct zx_prov_PollResponse_s*)e->gg.g.n) {
	  ret = zx_WALK_SO_prov_PollResponse(c, e, ctx, callback);
	  if (ret)
	      return ret;
      }
  }
  {
      struct zx_prov_UpdateEPR_s* e;
      for (e = x->UpdateEPR; e; e = (struct zx_prov_UpdateEPR_s*)e->gg.g.n) {
	  ret = zx_WALK_SO_prov_UpdateEPR(c, e, ctx, callback);
	  if (ret)
	      return ret;
      }
  }
  {
      struct zx_prov_UpdateEPRResponse_s* e;
      for (e = x->UpdateEPRResponse; e; e = (struct zx_prov_UpdateEPRResponse_s*)e->gg.g.n) {
	  ret = zx_WALK_SO_prov_UpdateEPRResponse(c, e, ctx, callback);
	  if (ret)
	      return ret;
      }
  }
  {
      struct zx_idp_GetAssertion_s* e;
      for (e = x->GetAssertion; e; e = (struct zx_idp_GetAssertion_s*)e->gg.g.n) {
	  ret = zx_WALK_SO_idp_GetAssertion(c, e, ctx, callback);
	  if (ret)
	      return ret;
      }
  }
  {
      struct zx_idp_GetAssertionResponse_s* e;
      for (e = x->GetAssertionResponse; e; e = (struct zx_idp_GetAssertionResponse_s*)e->gg.g.n) {
	  ret = zx_WALK_SO_idp_GetAssertionResponse(c, e, ctx, callback);
	  if (ret)
	      return ret;
      }
  }
  {
      struct zx_idp_GetProviderInfo_s* e;
      for (e = x->GetProviderInfo; e; e = (struct zx_idp_GetProviderInfo_s*)e->gg.g.n) {
	  ret = zx_WALK_SO_idp_GetProviderInfo(c, e, ctx, callback);
	  if (ret)
	      return ret;
      }
  }
  {
      struct zx_idp_GetProviderInfoResponse_s* e;
      for (e = x->GetProviderInfoResponse; e; e = (struct zx_idp_GetProviderInfoResponse_s*)e->gg.g.n) {
	  ret = zx_WALK_SO_idp_GetProviderInfoResponse(c, e, ctx, callback);
	  if (ret)
	      return ret;
      }
  }
  {
      struct zx_idp_CreatedStatus_s* e;
      for (e = x->CreatedStatus; e; e = (struct zx_idp_CreatedStatus_s*)e->gg.g.n) {
	  ret = zx_WALK_SO_idp_CreatedStatus(c, e, ctx, callback);
	  if (ret)
	      return ret;
      }
  }
  {
      struct zx_idp_CreatedStatusResponse_s* e;
      for (e = x->CreatedStatusResponse; e; e = (struct zx_idp_CreatedStatusResponse_s*)e->gg.g.n) {
	  ret = zx_WALK_SO_idp_CreatedStatusResponse(c, e, ctx, callback);
	  if (ret)
	      return ret;
      }
  }
  {
      struct zx_shps_Delete_s* e;
      for (e = x->shps_Delete; e; e = (struct zx_shps_Delete_s*)e->gg.g.n) {
	  ret = zx_WALK_SO_shps_Delete(c, e, ctx, callback);
	  if (ret)
	      return ret;
      }
  }
  {
      struct zx_shps_DeleteResponse_s* e;
      for (e = x->shps_DeleteResponse; e; e = (struct zx_shps_DeleteResponse_s*)e->gg.g.n) {
	  ret = zx_WALK_SO_shps_DeleteResponse(c, e, ctx, callback);
	  if (ret)
	      return ret;
      }
  }
  {
      struct zx_shps_GetStatus_s* e;
      for (e = x->GetStatus; e; e = (struct zx_shps_GetStatus_s*)e->gg.g.n) {
	  ret = zx_WALK_SO_shps_GetStatus(c, e, ctx, callback);
	  if (ret)
	      return ret;
      }
  }
  {
      struct zx_shps_GetStatusResponse_s* e;
      for (e = x->GetStatusResponse; e; e = (struct zx_shps_GetStatusResponse_s*)e->gg.g.n) {
	  ret = zx_WALK_SO_shps_GetStatusResponse(c, e, ctx, callback);
	  if (ret)
	      return ret;
      }
  }
  {
      struct zx_shps_Query_s* e;
      for (e = x->shps_Query; e; e = (struct zx_shps_Query_s*)e->gg.g.n) {
	  ret = zx_WALK_SO_shps_Query(c, e, ctx, callback);
	  if (ret)
	      return ret;
      }
  }
  {
      struct zx_shps_QueryResponse_s* e;
      for (e = x->shps_QueryResponse; e; e = (struct zx_shps_QueryResponse_s*)e->gg.g.n) {
	  ret = zx_WALK_SO_shps_QueryResponse(c, e, ctx, callback);
	  if (ret)
	      return ret;
      }
  }
  ret = zx_walk_so_simple_elems(c, x->Invoke, ctx, callback);
  if (ret)
    return ret;
  {
      struct zx_shps_InvokeResponse_s* e;
      for (e = x->InvokeResponse; e; e = (struct zx_shps_InvokeResponse_s*)e->gg.g.n) {
	  ret = zx_WALK_SO_shps_InvokeResponse(c, e, ctx, callback);
	  if (ret)
	      return ret;
      }
  }
  {
      struct zx_shps_QueryRegistered_s* e;
      for (e = x->QueryRegistered; e; e = (struct zx_shps_QueryRegistered_s*)e->gg.g.n) {
	  ret = zx_WALK_SO_shps_QueryRegistered(c, e, ctx, callback);
	  if (ret)
	      return ret;
      }
  }
  {
      struct zx_shps_QueryRegisteredResponse_s* e;
      for (e = x->QueryRegisteredResponse; e; e = (struct zx_shps_QueryRegisteredResponse_s*)e->gg.g.n) {
	  ret = zx_WALK_SO_shps_QueryRegisteredResponse(c, e, ctx, callback);
	  if (ret)
	      return ret;
      }
  }
  {
      struct zx_shps_Register_s* e;
      for (e = x->Register; e; e = (struct zx_shps_Register_s*)e->gg.g.n) {
	  ret = zx_WALK_SO_shps_Register(c, e, ctx, callback);
	  if (ret)
	      return ret;
      }
  }
  {
      struct zx_shps_RegisterResponse_s* e;
      for (e = x->RegisterResponse; e; e = (struct zx_shps_RegisterResponse_s*)e->gg.g.n) {
	  ret = zx_WALK_SO_shps_RegisterResponse(c, e, ctx, callback);
	  if (ret)
	      return ret;
      }
  }
  {
      struct zx_shps_SetStatus_s* e;
      for (e = x->SetStatus; e; e = (struct zx_shps_SetStatus_s*)e->gg.g.n) {
	  ret = zx_WALK_SO_shps_SetStatus(c, e, ctx, callback);
	  if (ret)
	      return ret;
      }
  }
  {
      struct zx_shps_SetStatusResponse_s* e;
      for (e = x->SetStatusResponse; e; e = (struct zx_shps_SetStatusResponse_s*)e->gg.g.n) {
	  ret = zx_WALK_SO_shps_SetStatusResponse(c, e, ctx, callback);
	  if (ret)
	      return ret;
      }
  }
  {
      struct zx_shps_Update_s* e;
      for (e = x->Update; e; e = (struct zx_shps_Update_s*)e->gg.g.n) {
	  ret = zx_WALK_SO_shps_Update(c, e, ctx, callback);
	  if (ret)
	      return ret;
      }
  }
  {
      struct zx_shps_UpdateResponse_s* e;
      for (e = x->UpdateResponse; e; e = (struct zx_shps_UpdateResponse_s*)e->gg.g.n) {
	  ret = zx_WALK_SO_shps_UpdateResponse(c, e, ctx, callback);
	  if (ret)
	      return ret;
      }
  }
  {
      struct zx_shps_Poll_s* e;
      for (e = x->shps_Poll; e; e = (struct zx_shps_Poll_s*)e->gg.g.n) {
	  ret = zx_WALK_SO_shps_Poll(c, e, ctx, callback);
	  if (ret)
	      return ret;
      }
  }
  {
      struct zx_shps_PollResponse_s* e;
      for (e = x->shps_PollResponse; e; e = (struct zx_shps_PollResponse_s*)e->gg.g.n) {
	  ret = zx_WALK_SO_shps_PollResponse(c, e, ctx, callback);
	  if (ret)
	      return ret;
      }
  }
  {
      struct zx_shps_ProxyInvoke_s* e;
      for (e = x->ProxyInvoke; e; e = (struct zx_shps_ProxyInvoke_s*)e->gg.g.n) {
	  ret = zx_WALK_SO_shps_ProxyInvoke(c, e, ctx, callback);
	  if (ret)
	      return ret;
      }
  }
  {
      struct zx_shps_ProxyInvokeResponse_s* e;
      for (e = x->ProxyInvokeResponse; e; e = (struct zx_shps_ProxyInvokeResponse_s*)e->gg.g.n) {
	  ret = zx_WALK_SO_shps_ProxyInvokeResponse(c, e, ctx, callback);
	  if (ret)
	      return ret;
      }
  }
  {
      struct zx_idhrxml_Create_s* e;
      for (e = x->idhrxml_Create; e; e = (struct zx_idhrxml_Create_s*)e->gg.g.n) {
	  ret = zx_WALK_SO_idhrxml_Create(c, e, ctx, callback);
	  if (ret)
	      return ret;
      }
  }
  {
      struct zx_idhrxml_CreateResponse_s* e;
      for (e = x->idhrxml_CreateResponse; e; e = (struct zx_idhrxml_CreateResponse_s*)e->gg.g.n) {
	  ret = zx_WALK_SO_idhrxml_CreateResponse(c, e, ctx, callback);
	  if (ret)
	      return ret;
      }
  }
  {
      struct zx_idhrxml_Query_s* e;
      for (e = x->idhrxml_Query; e; e = (struct zx_idhrxml_Query_s*)e->gg.g.n) {
	  ret = zx_WALK_SO_idhrxml_Query(c, e, ctx, callback);
	  if (ret)
	      return ret;
      }
  }
  {
      struct zx_idhrxml_QueryResponse_s* e;
      for (e = x->idhrxml_QueryResponse; e; e = (struct zx_idhrxml_QueryResponse_s*)e->gg.g.n) {
	  ret = zx_WALK_SO_idhrxml_QueryResponse(c, e, ctx, callback);
	  if (ret)
	      return ret;
      }
  }
  {
      struct zx_idhrxml_Modify_s* e;
      for (e = x->idhrxml_Modify; e; e = (struct zx_idhrxml_Modify_s*)e->gg.g.n) {
	  ret = zx_WALK_SO_idhrxml_Modify(c, e, ctx, callback);
	  if (ret)
	      return ret;
      }
  }
  {
      struct zx_idhrxml_ModifyResponse_s* e;
      for (e = x->idhrxml_ModifyResponse; e; e = (struct zx_idhrxml_ModifyResponse_s*)e->gg.g.n) {
	  ret = zx_WALK_SO_idhrxml_ModifyResponse(c, e, ctx, callback);
	  if (ret)
	      return ret;
      }
  }
  {
      struct zx_idhrxml_Delete_s* e;
      for (e = x->idhrxml_Delete; e; e = (struct zx_idhrxml_Delete_s*)e->gg.g.n) {
	  ret = zx_WALK_SO_idhrxml_Delete(c, e, ctx, callback);
	  if (ret)
	      return ret;
      }
  }
  {
      struct zx_idhrxml_DeleteResponse_s* e;
      for (e = x->idhrxml_DeleteResponse; e; e = (struct zx_idhrxml_DeleteResponse_s*)e->gg.g.n) {
	  ret = zx_WALK_SO_idhrxml_DeleteResponse(c, e, ctx, callback);
	  if (ret)
	      return ret;
      }
  }
  {
      struct zx_idhrxml_Notify_s* e;
      for (e = x->idhrxml_Notify; e; e = (struct zx_idhrxml_Notify_s*)e->gg.g.n) {
	  ret = zx_WALK_SO_idhrxml_Notify(c, e, ctx, callback);
	  if (ret)
	      return ret;
      }
  }
  {
      struct zx_idhrxml_NotifyResponse_s* e;
      for (e = x->idhrxml_NotifyResponse; e; e = (struct zx_idhrxml_NotifyResponse_s*)e->gg.g.n) {
	  ret = zx_WALK_SO_idhrxml_NotifyResponse(c, e, ctx, callback);
	  if (ret)
	      return ret;
      }
  }

  
  return zx_walk_so_unknown_elems_and_content(c, &x->gg, ctx, callback);
}

/* FUNC(zx_WALK_WO_e_Body) */

int zx_WALK_WO_e_Body(struct zx_ctx* c, struct zx_e_Body_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
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

#define EL_NAME   e_Envelope
#define EL_STRUCT zx_e_Envelope_s
#define EL_NS     e
#define EL_TAG    Envelope

/* FUNC(zx_FREE_e_Envelope) */

/* Depth first traversal of data structure to free it and its subelements. Simple
 * strings are handled as a special case according to the free_strs flag. This
 * is useful if the strings point to underlying data from the wire that was
 * allocated differently. */

/* Called by: */
void zx_FREE_e_Envelope(struct zx_ctx* c, struct zx_e_Envelope_s* x, int free_strs)
{
  /* *** deal with xmlns specifications in exc c14n way */

  zx_free_attr(c, x->id, free_strs);

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


  zx_free_elem_common(c, &x->gg, free_strs); 
}

/* FUNC(zx_NEW_e_Envelope) */

/* Trivial allocator/constructor for the datatype. */

/* Called by: */
struct zx_e_Envelope_s* zx_NEW_e_Envelope(struct zx_ctx* c)
{
  struct zx_e_Envelope_s* x = ZX_ZALLOC(c, struct zx_e_Envelope_s);
  x->gg.g.tok = zx_e_Envelope_ELEM;
  return x;
}

#ifdef ZX_ENA_AUX

/* FUNC(zx_DUP_STRS_e_Envelope) */

/* Depth first traversal of data structure to copy its simple strings
 * to memory allocated from the memory allocator. The decoder will
 * use the underlying wireprotocol PDU buffer for strings, i.e.
 * strings are not copied - they point to the real data. If the
 * datastructure needs to outlast the protocol data or needs a different
 * memory allocation strategy, you need to call this function.  */

/* Called by: */
void zx_DUP_STRS_e_Envelope(struct zx_ctx* c, struct zx_e_Envelope_s* x)
{
  zx_dup_strs_common(c, &x->gg);
  /* *** deal with xmlns specifications in exc c14n way */

  zx_dup_attr(c, x->id);

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

}

/* FUNC(zx_DEEP_CLONE_e_Envelope) */

/* Depth first traversal of data structure to clone it and its sublements.
 * The simple strings are handled as a special case according to dup_strs flag. */

/* Called by: */
struct zx_e_Envelope_s* zx_DEEP_CLONE_e_Envelope(struct zx_ctx* c, struct zx_e_Envelope_s* x, int dup_strs)
{
  x = (struct zx_e_Envelope_s*)zx_clone_elem_common(c, &x->gg, sizeof(struct zx_e_Envelope_s), dup_strs);
  /* *** deal with xmlns specifications in exc c14n way */

  x->id = zx_clone_attr(c, x->id);

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

  return x;
}

/* FUNC(zx_WALK_SO_e_Envelope) */

/* Depth first traversal of the tree in either schema order or the wire order. */
 
int zx_WALK_SO_e_Envelope(struct zx_ctx* c, struct zx_e_Envelope_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
{
  int ret = callback(&x->gg.g, ctx);
  if (ret)
    return ret;
  
  /* *** deal with xmlns specifications in exc c14n way */


  
  ret = zx_walk_so_unknown_attributes(c, &x->gg, ctx, callback); 
  if (ret)
    return ret;

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

  
  return zx_walk_so_unknown_elems_and_content(c, &x->gg, ctx, callback);
}

/* FUNC(zx_WALK_WO_e_Envelope) */

int zx_WALK_WO_e_Envelope(struct zx_ctx* c, struct zx_e_Envelope_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
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

#define EL_NAME   e_Fault
#define EL_STRUCT zx_e_Fault_s
#define EL_NS     e
#define EL_TAG    Fault

/* FUNC(zx_FREE_e_Fault) */

/* Depth first traversal of data structure to free it and its subelements. Simple
 * strings are handled as a special case according to the free_strs flag. This
 * is useful if the strings point to underlying data from the wire that was
 * allocated differently. */

/* Called by: */
void zx_FREE_e_Fault(struct zx_ctx* c, struct zx_e_Fault_s* x, int free_strs)
{
  /* *** deal with xmlns specifications in exc c14n way */


  zx_free_simple_elems(c, x->faultcode, free_strs);
  zx_free_simple_elems(c, x->faultstring, free_strs);
  zx_free_simple_elems(c, x->faultactor, free_strs);
  {
      struct zx_e_detail_s* e;
      struct zx_e_detail_s* en;
      for (e = x->detail; e; e = en) {
	  en = (struct zx_e_detail_s*)e->gg.g.n;
	  zx_FREE_e_detail(c, e, free_strs);
      }
  }


  zx_free_elem_common(c, &x->gg, free_strs); 
}

/* FUNC(zx_NEW_e_Fault) */

/* Trivial allocator/constructor for the datatype. */

/* Called by: */
struct zx_e_Fault_s* zx_NEW_e_Fault(struct zx_ctx* c)
{
  struct zx_e_Fault_s* x = ZX_ZALLOC(c, struct zx_e_Fault_s);
  x->gg.g.tok = zx_e_Fault_ELEM;
  return x;
}

#ifdef ZX_ENA_AUX

/* FUNC(zx_DUP_STRS_e_Fault) */

/* Depth first traversal of data structure to copy its simple strings
 * to memory allocated from the memory allocator. The decoder will
 * use the underlying wireprotocol PDU buffer for strings, i.e.
 * strings are not copied - they point to the real data. If the
 * datastructure needs to outlast the protocol data or needs a different
 * memory allocation strategy, you need to call this function.  */

/* Called by: */
void zx_DUP_STRS_e_Fault(struct zx_ctx* c, struct zx_e_Fault_s* x)
{
  zx_dup_strs_common(c, &x->gg);
  /* *** deal with xmlns specifications in exc c14n way */


  zx_dup_strs_simple_elems(c, x->faultcode);
  zx_dup_strs_simple_elems(c, x->faultstring);
  zx_dup_strs_simple_elems(c, x->faultactor);
  {
      struct zx_e_detail_s* e;
      for (e = x->detail; e; e = (struct zx_e_detail_s*)e->gg.g.n)
	  zx_DUP_STRS_e_detail(c, e);
  }

}

/* FUNC(zx_DEEP_CLONE_e_Fault) */

/* Depth first traversal of data structure to clone it and its sublements.
 * The simple strings are handled as a special case according to dup_strs flag. */

/* Called by: */
struct zx_e_Fault_s* zx_DEEP_CLONE_e_Fault(struct zx_ctx* c, struct zx_e_Fault_s* x, int dup_strs)
{
  x = (struct zx_e_Fault_s*)zx_clone_elem_common(c, &x->gg, sizeof(struct zx_e_Fault_s), dup_strs);
  /* *** deal with xmlns specifications in exc c14n way */


  x->faultcode = zx_deep_clone_simple_elems(c,x->faultcode, dup_strs);
  x->faultstring = zx_deep_clone_simple_elems(c,x->faultstring, dup_strs);
  x->faultactor = zx_deep_clone_simple_elems(c,x->faultactor, dup_strs);
  {
      struct zx_e_detail_s* e;
      struct zx_e_detail_s* en;
      struct zx_e_detail_s* enn;
      for (enn = 0, e = x->detail; e; e = (struct zx_e_detail_s*)e->gg.g.n) {
	  en = zx_DEEP_CLONE_e_detail(c, e, dup_strs);
	  if (!enn)
	      x->detail = en;
	  else
	      enn->gg.g.n = &en->gg.g;
	  enn = en;
      }
  }

  return x;
}

/* FUNC(zx_WALK_SO_e_Fault) */

/* Depth first traversal of the tree in either schema order or the wire order. */
 
int zx_WALK_SO_e_Fault(struct zx_ctx* c, struct zx_e_Fault_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
{
  int ret = callback(&x->gg.g, ctx);
  if (ret)
    return ret;
  
  /* *** deal with xmlns specifications in exc c14n way */


  
  ret = zx_walk_so_unknown_attributes(c, &x->gg, ctx, callback); 
  if (ret)
    return ret;

  ret = zx_walk_so_simple_elems(c, x->faultcode, ctx, callback);
  if (ret)
    return ret;
  ret = zx_walk_so_simple_elems(c, x->faultstring, ctx, callback);
  if (ret)
    return ret;
  ret = zx_walk_so_simple_elems(c, x->faultactor, ctx, callback);
  if (ret)
    return ret;
  {
      struct zx_e_detail_s* e;
      for (e = x->detail; e; e = (struct zx_e_detail_s*)e->gg.g.n) {
	  ret = zx_WALK_SO_e_detail(c, e, ctx, callback);
	  if (ret)
	      return ret;
      }
  }

  
  return zx_walk_so_unknown_elems_and_content(c, &x->gg, ctx, callback);
}

/* FUNC(zx_WALK_WO_e_Fault) */

int zx_WALK_WO_e_Fault(struct zx_ctx* c, struct zx_e_Fault_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
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

#define EL_NAME   e_Header
#define EL_STRUCT zx_e_Header_s
#define EL_NS     e
#define EL_TAG    Header

/* FUNC(zx_FREE_e_Header) */

/* Depth first traversal of data structure to free it and its subelements. Simple
 * strings are handled as a special case according to the free_strs flag. This
 * is useful if the strings point to underlying data from the wire that was
 * allocated differently. */

/* Called by: */
void zx_FREE_e_Header(struct zx_ctx* c, struct zx_e_Header_s* x, int free_strs)
{
  /* *** deal with xmlns specifications in exc c14n way */

  zx_free_attr(c, x->id, free_strs);

  {
      struct zx_paos_Request_s* e;
      struct zx_paos_Request_s* en;
      for (e = x->Request; e; e = en) {
	  en = (struct zx_paos_Request_s*)e->gg.g.n;
	  zx_FREE_paos_Request(c, e, free_strs);
      }
  }
  {
      struct zx_paos_Response_s* e;
      struct zx_paos_Response_s* en;
      for (e = x->Response; e; e = en) {
	  en = (struct zx_paos_Response_s*)e->gg.g.n;
	  zx_FREE_paos_Response(c, e, free_strs);
      }
  }
  {
      struct zx_ecp_Request_s* e;
      struct zx_ecp_Request_s* en;
      for (e = x->ecp_Request; e; e = en) {
	  en = (struct zx_ecp_Request_s*)e->gg.g.n;
	  zx_FREE_ecp_Request(c, e, free_strs);
      }
  }
  {
      struct zx_ecp_Response_s* e;
      struct zx_ecp_Response_s* en;
      for (e = x->ecp_Response; e; e = en) {
	  en = (struct zx_ecp_Response_s*)e->gg.g.n;
	  zx_FREE_ecp_Response(c, e, free_strs);
      }
  }
  {
      struct zx_ecp_RelayState_s* e;
      struct zx_ecp_RelayState_s* en;
      for (e = x->RelayState; e; e = en) {
	  en = (struct zx_ecp_RelayState_s*)e->gg.g.n;
	  zx_FREE_ecp_RelayState(c, e, free_strs);
      }
  }
  {
      struct zx_a_MessageID_s* e;
      struct zx_a_MessageID_s* en;
      for (e = x->MessageID; e; e = en) {
	  en = (struct zx_a_MessageID_s*)e->gg.g.n;
	  zx_FREE_a_MessageID(c, e, free_strs);
      }
  }
  {
      struct zx_a_RelatesTo_s* e;
      struct zx_a_RelatesTo_s* en;
      for (e = x->RelatesTo; e; e = en) {
	  en = (struct zx_a_RelatesTo_s*)e->gg.g.n;
	  zx_FREE_a_RelatesTo(c, e, free_strs);
      }
  }
  {
      struct zx_a_ReplyTo_s* e;
      struct zx_a_ReplyTo_s* en;
      for (e = x->ReplyTo; e; e = en) {
	  en = (struct zx_a_ReplyTo_s*)e->gg.g.n;
	  zx_FREE_a_ReplyTo(c, e, free_strs);
      }
  }
  {
      struct zx_a_From_s* e;
      struct zx_a_From_s* en;
      for (e = x->From; e; e = en) {
	  en = (struct zx_a_From_s*)e->gg.g.n;
	  zx_FREE_a_From(c, e, free_strs);
      }
  }
  {
      struct zx_a_FaultTo_s* e;
      struct zx_a_FaultTo_s* en;
      for (e = x->FaultTo; e; e = en) {
	  en = (struct zx_a_FaultTo_s*)e->gg.g.n;
	  zx_FREE_a_FaultTo(c, e, free_strs);
      }
  }
  {
      struct zx_a_To_s* e;
      struct zx_a_To_s* en;
      for (e = x->To; e; e = en) {
	  en = (struct zx_a_To_s*)e->gg.g.n;
	  zx_FREE_a_To(c, e, free_strs);
      }
  }
  {
      struct zx_a_Action_s* e;
      struct zx_a_Action_s* en;
      for (e = x->Action; e; e = en) {
	  en = (struct zx_a_Action_s*)e->gg.g.n;
	  zx_FREE_a_Action(c, e, free_strs);
      }
  }
  {
      struct zx_a_ReferenceParameters_s* e;
      struct zx_a_ReferenceParameters_s* en;
      for (e = x->ReferenceParameters; e; e = en) {
	  en = (struct zx_a_ReferenceParameters_s*)e->gg.g.n;
	  zx_FREE_a_ReferenceParameters(c, e, free_strs);
      }
  }
  {
      struct zx_sbf_Framework_s* e;
      struct zx_sbf_Framework_s* en;
      for (e = x->Framework; e; e = en) {
	  en = (struct zx_sbf_Framework_s*)e->gg.g.n;
	  zx_FREE_sbf_Framework(c, e, free_strs);
      }
  }
  {
      struct zx_b_Framework_s* e;
      struct zx_b_Framework_s* en;
      for (e = x->b_Framework; e; e = en) {
	  en = (struct zx_b_Framework_s*)e->gg.g.n;
	  zx_FREE_b_Framework(c, e, free_strs);
      }
  }
  {
      struct zx_b_Sender_s* e;
      struct zx_b_Sender_s* en;
      for (e = x->Sender; e; e = en) {
	  en = (struct zx_b_Sender_s*)e->gg.g.n;
	  zx_FREE_b_Sender(c, e, free_strs);
      }
  }
  {
      struct zx_b_TargetIdentity_s* e;
      struct zx_b_TargetIdentity_s* en;
      for (e = x->TargetIdentity; e; e = en) {
	  en = (struct zx_b_TargetIdentity_s*)e->gg.g.n;
	  zx_FREE_b_TargetIdentity(c, e, free_strs);
      }
  }
  {
      struct zx_b_CredentialsContext_s* e;
      struct zx_b_CredentialsContext_s* en;
      for (e = x->CredentialsContext; e; e = en) {
	  en = (struct zx_b_CredentialsContext_s*)e->gg.g.n;
	  zx_FREE_b_CredentialsContext(c, e, free_strs);
      }
  }
  {
      struct zx_b_EndpointUpdate_s* e;
      struct zx_b_EndpointUpdate_s* en;
      for (e = x->EndpointUpdate; e; e = en) {
	  en = (struct zx_b_EndpointUpdate_s*)e->gg.g.n;
	  zx_FREE_b_EndpointUpdate(c, e, free_strs);
      }
  }
  {
      struct zx_b_Timeout_s* e;
      struct zx_b_Timeout_s* en;
      for (e = x->Timeout; e; e = en) {
	  en = (struct zx_b_Timeout_s*)e->gg.g.n;
	  zx_FREE_b_Timeout(c, e, free_strs);
      }
  }
  {
      struct zx_b_ProcessingContext_s* e;
      struct zx_b_ProcessingContext_s* en;
      for (e = x->ProcessingContext; e; e = en) {
	  en = (struct zx_b_ProcessingContext_s*)e->gg.g.n;
	  zx_FREE_b_ProcessingContext(c, e, free_strs);
      }
  }
  {
      struct zx_b_Consent_s* e;
      struct zx_b_Consent_s* en;
      for (e = x->Consent; e; e = en) {
	  en = (struct zx_b_Consent_s*)e->gg.g.n;
	  zx_FREE_b_Consent(c, e, free_strs);
      }
  }
  {
      struct zx_b_UsageDirective_s* e;
      struct zx_b_UsageDirective_s* en;
      for (e = x->UsageDirective; e; e = en) {
	  en = (struct zx_b_UsageDirective_s*)e->gg.g.n;
	  zx_FREE_b_UsageDirective(c, e, free_strs);
      }
  }
  {
      struct zx_b_ApplicationEPR_s* e;
      struct zx_b_ApplicationEPR_s* en;
      for (e = x->ApplicationEPR; e; e = en) {
	  en = (struct zx_b_ApplicationEPR_s*)e->gg.g.n;
	  zx_FREE_b_ApplicationEPR(c, e, free_strs);
      }
  }
  {
      struct zx_b_UserInteraction_s* e;
      struct zx_b_UserInteraction_s* en;
      for (e = x->UserInteraction; e; e = en) {
	  en = (struct zx_b_UserInteraction_s*)e->gg.g.n;
	  zx_FREE_b_UserInteraction(c, e, free_strs);
      }
  }
  {
      struct zx_b_RedirectRequest_s* e;
      struct zx_b_RedirectRequest_s* en;
      for (e = x->RedirectRequest; e; e = en) {
	  en = (struct zx_b_RedirectRequest_s*)e->gg.g.n;
	  zx_FREE_b_RedirectRequest(c, e, free_strs);
      }
  }
  {
      struct zx_b12_Correlation_s* e;
      struct zx_b12_Correlation_s* en;
      for (e = x->Correlation; e; e = en) {
	  en = (struct zx_b12_Correlation_s*)e->gg.g.n;
	  zx_FREE_b12_Correlation(c, e, free_strs);
      }
  }
  {
      struct zx_b12_Provider_s* e;
      struct zx_b12_Provider_s* en;
      for (e = x->Provider; e; e = en) {
	  en = (struct zx_b12_Provider_s*)e->gg.g.n;
	  zx_FREE_b12_Provider(c, e, free_strs);
      }
  }
  {
      struct zx_b12_ProcessingContext_s* e;
      struct zx_b12_ProcessingContext_s* en;
      for (e = x->b12_ProcessingContext; e; e = en) {
	  en = (struct zx_b12_ProcessingContext_s*)e->gg.g.n;
	  zx_FREE_b12_ProcessingContext(c, e, free_strs);
      }
  }
  {
      struct zx_b12_Consent_s* e;
      struct zx_b12_Consent_s* en;
      for (e = x->b12_Consent; e; e = en) {
	  en = (struct zx_b12_Consent_s*)e->gg.g.n;
	  zx_FREE_b12_Consent(c, e, free_strs);
      }
  }
  {
      struct zx_b12_UsageDirective_s* e;
      struct zx_b12_UsageDirective_s* en;
      for (e = x->b12_UsageDirective; e; e = en) {
	  en = (struct zx_b12_UsageDirective_s*)e->gg.g.n;
	  zx_FREE_b12_UsageDirective(c, e, free_strs);
      }
  }
  {
      struct zx_mm7_TransactionID_s* e;
      struct zx_mm7_TransactionID_s* en;
      for (e = x->TransactionID; e; e = en) {
	  en = (struct zx_mm7_TransactionID_s*)e->gg.g.n;
	  zx_FREE_mm7_TransactionID(c, e, free_strs);
      }
  }
  {
      struct zx_wsse_Security_s* e;
      struct zx_wsse_Security_s* en;
      for (e = x->Security; e; e = en) {
	  en = (struct zx_wsse_Security_s*)e->gg.g.n;
	  zx_FREE_wsse_Security(c, e, free_strs);
      }
  }
  {
      struct zx_tas3_Status_s* e;
      struct zx_tas3_Status_s* en;
      for (e = x->Status; e; e = en) {
	  en = (struct zx_tas3_Status_s*)e->gg.g.n;
	  zx_FREE_tas3_Status(c, e, free_strs);
      }
  }
  {
      struct zx_tas3_Credentials_s* e;
      struct zx_tas3_Credentials_s* en;
      for (e = x->Credentials; e; e = en) {
	  en = (struct zx_tas3_Credentials_s*)e->gg.g.n;
	  zx_FREE_tas3_Credentials(c, e, free_strs);
      }
  }
  {
      struct zx_tas3_ESLPolicies_s* e;
      struct zx_tas3_ESLPolicies_s* en;
      for (e = x->ESLPolicies; e; e = en) {
	  en = (struct zx_tas3_ESLPolicies_s*)e->gg.g.n;
	  zx_FREE_tas3_ESLPolicies(c, e, free_strs);
      }
  }


  zx_free_elem_common(c, &x->gg, free_strs); 
}

/* FUNC(zx_NEW_e_Header) */

/* Trivial allocator/constructor for the datatype. */

/* Called by: */
struct zx_e_Header_s* zx_NEW_e_Header(struct zx_ctx* c)
{
  struct zx_e_Header_s* x = ZX_ZALLOC(c, struct zx_e_Header_s);
  x->gg.g.tok = zx_e_Header_ELEM;
  return x;
}

#ifdef ZX_ENA_AUX

/* FUNC(zx_DUP_STRS_e_Header) */

/* Depth first traversal of data structure to copy its simple strings
 * to memory allocated from the memory allocator. The decoder will
 * use the underlying wireprotocol PDU buffer for strings, i.e.
 * strings are not copied - they point to the real data. If the
 * datastructure needs to outlast the protocol data or needs a different
 * memory allocation strategy, you need to call this function.  */

/* Called by: */
void zx_DUP_STRS_e_Header(struct zx_ctx* c, struct zx_e_Header_s* x)
{
  zx_dup_strs_common(c, &x->gg);
  /* *** deal with xmlns specifications in exc c14n way */

  zx_dup_attr(c, x->id);

  {
      struct zx_paos_Request_s* e;
      for (e = x->Request; e; e = (struct zx_paos_Request_s*)e->gg.g.n)
	  zx_DUP_STRS_paos_Request(c, e);
  }
  {
      struct zx_paos_Response_s* e;
      for (e = x->Response; e; e = (struct zx_paos_Response_s*)e->gg.g.n)
	  zx_DUP_STRS_paos_Response(c, e);
  }
  {
      struct zx_ecp_Request_s* e;
      for (e = x->ecp_Request; e; e = (struct zx_ecp_Request_s*)e->gg.g.n)
	  zx_DUP_STRS_ecp_Request(c, e);
  }
  {
      struct zx_ecp_Response_s* e;
      for (e = x->ecp_Response; e; e = (struct zx_ecp_Response_s*)e->gg.g.n)
	  zx_DUP_STRS_ecp_Response(c, e);
  }
  {
      struct zx_ecp_RelayState_s* e;
      for (e = x->RelayState; e; e = (struct zx_ecp_RelayState_s*)e->gg.g.n)
	  zx_DUP_STRS_ecp_RelayState(c, e);
  }
  {
      struct zx_a_MessageID_s* e;
      for (e = x->MessageID; e; e = (struct zx_a_MessageID_s*)e->gg.g.n)
	  zx_DUP_STRS_a_MessageID(c, e);
  }
  {
      struct zx_a_RelatesTo_s* e;
      for (e = x->RelatesTo; e; e = (struct zx_a_RelatesTo_s*)e->gg.g.n)
	  zx_DUP_STRS_a_RelatesTo(c, e);
  }
  {
      struct zx_a_ReplyTo_s* e;
      for (e = x->ReplyTo; e; e = (struct zx_a_ReplyTo_s*)e->gg.g.n)
	  zx_DUP_STRS_a_ReplyTo(c, e);
  }
  {
      struct zx_a_From_s* e;
      for (e = x->From; e; e = (struct zx_a_From_s*)e->gg.g.n)
	  zx_DUP_STRS_a_From(c, e);
  }
  {
      struct zx_a_FaultTo_s* e;
      for (e = x->FaultTo; e; e = (struct zx_a_FaultTo_s*)e->gg.g.n)
	  zx_DUP_STRS_a_FaultTo(c, e);
  }
  {
      struct zx_a_To_s* e;
      for (e = x->To; e; e = (struct zx_a_To_s*)e->gg.g.n)
	  zx_DUP_STRS_a_To(c, e);
  }
  {
      struct zx_a_Action_s* e;
      for (e = x->Action; e; e = (struct zx_a_Action_s*)e->gg.g.n)
	  zx_DUP_STRS_a_Action(c, e);
  }
  {
      struct zx_a_ReferenceParameters_s* e;
      for (e = x->ReferenceParameters; e; e = (struct zx_a_ReferenceParameters_s*)e->gg.g.n)
	  zx_DUP_STRS_a_ReferenceParameters(c, e);
  }
  {
      struct zx_sbf_Framework_s* e;
      for (e = x->Framework; e; e = (struct zx_sbf_Framework_s*)e->gg.g.n)
	  zx_DUP_STRS_sbf_Framework(c, e);
  }
  {
      struct zx_b_Framework_s* e;
      for (e = x->b_Framework; e; e = (struct zx_b_Framework_s*)e->gg.g.n)
	  zx_DUP_STRS_b_Framework(c, e);
  }
  {
      struct zx_b_Sender_s* e;
      for (e = x->Sender; e; e = (struct zx_b_Sender_s*)e->gg.g.n)
	  zx_DUP_STRS_b_Sender(c, e);
  }
  {
      struct zx_b_TargetIdentity_s* e;
      for (e = x->TargetIdentity; e; e = (struct zx_b_TargetIdentity_s*)e->gg.g.n)
	  zx_DUP_STRS_b_TargetIdentity(c, e);
  }
  {
      struct zx_b_CredentialsContext_s* e;
      for (e = x->CredentialsContext; e; e = (struct zx_b_CredentialsContext_s*)e->gg.g.n)
	  zx_DUP_STRS_b_CredentialsContext(c, e);
  }
  {
      struct zx_b_EndpointUpdate_s* e;
      for (e = x->EndpointUpdate; e; e = (struct zx_b_EndpointUpdate_s*)e->gg.g.n)
	  zx_DUP_STRS_b_EndpointUpdate(c, e);
  }
  {
      struct zx_b_Timeout_s* e;
      for (e = x->Timeout; e; e = (struct zx_b_Timeout_s*)e->gg.g.n)
	  zx_DUP_STRS_b_Timeout(c, e);
  }
  {
      struct zx_b_ProcessingContext_s* e;
      for (e = x->ProcessingContext; e; e = (struct zx_b_ProcessingContext_s*)e->gg.g.n)
	  zx_DUP_STRS_b_ProcessingContext(c, e);
  }
  {
      struct zx_b_Consent_s* e;
      for (e = x->Consent; e; e = (struct zx_b_Consent_s*)e->gg.g.n)
	  zx_DUP_STRS_b_Consent(c, e);
  }
  {
      struct zx_b_UsageDirective_s* e;
      for (e = x->UsageDirective; e; e = (struct zx_b_UsageDirective_s*)e->gg.g.n)
	  zx_DUP_STRS_b_UsageDirective(c, e);
  }
  {
      struct zx_b_ApplicationEPR_s* e;
      for (e = x->ApplicationEPR; e; e = (struct zx_b_ApplicationEPR_s*)e->gg.g.n)
	  zx_DUP_STRS_b_ApplicationEPR(c, e);
  }
  {
      struct zx_b_UserInteraction_s* e;
      for (e = x->UserInteraction; e; e = (struct zx_b_UserInteraction_s*)e->gg.g.n)
	  zx_DUP_STRS_b_UserInteraction(c, e);
  }
  {
      struct zx_b_RedirectRequest_s* e;
      for (e = x->RedirectRequest; e; e = (struct zx_b_RedirectRequest_s*)e->gg.g.n)
	  zx_DUP_STRS_b_RedirectRequest(c, e);
  }
  {
      struct zx_b12_Correlation_s* e;
      for (e = x->Correlation; e; e = (struct zx_b12_Correlation_s*)e->gg.g.n)
	  zx_DUP_STRS_b12_Correlation(c, e);
  }
  {
      struct zx_b12_Provider_s* e;
      for (e = x->Provider; e; e = (struct zx_b12_Provider_s*)e->gg.g.n)
	  zx_DUP_STRS_b12_Provider(c, e);
  }
  {
      struct zx_b12_ProcessingContext_s* e;
      for (e = x->b12_ProcessingContext; e; e = (struct zx_b12_ProcessingContext_s*)e->gg.g.n)
	  zx_DUP_STRS_b12_ProcessingContext(c, e);
  }
  {
      struct zx_b12_Consent_s* e;
      for (e = x->b12_Consent; e; e = (struct zx_b12_Consent_s*)e->gg.g.n)
	  zx_DUP_STRS_b12_Consent(c, e);
  }
  {
      struct zx_b12_UsageDirective_s* e;
      for (e = x->b12_UsageDirective; e; e = (struct zx_b12_UsageDirective_s*)e->gg.g.n)
	  zx_DUP_STRS_b12_UsageDirective(c, e);
  }
  {
      struct zx_mm7_TransactionID_s* e;
      for (e = x->TransactionID; e; e = (struct zx_mm7_TransactionID_s*)e->gg.g.n)
	  zx_DUP_STRS_mm7_TransactionID(c, e);
  }
  {
      struct zx_wsse_Security_s* e;
      for (e = x->Security; e; e = (struct zx_wsse_Security_s*)e->gg.g.n)
	  zx_DUP_STRS_wsse_Security(c, e);
  }
  {
      struct zx_tas3_Status_s* e;
      for (e = x->Status; e; e = (struct zx_tas3_Status_s*)e->gg.g.n)
	  zx_DUP_STRS_tas3_Status(c, e);
  }
  {
      struct zx_tas3_Credentials_s* e;
      for (e = x->Credentials; e; e = (struct zx_tas3_Credentials_s*)e->gg.g.n)
	  zx_DUP_STRS_tas3_Credentials(c, e);
  }
  {
      struct zx_tas3_ESLPolicies_s* e;
      for (e = x->ESLPolicies; e; e = (struct zx_tas3_ESLPolicies_s*)e->gg.g.n)
	  zx_DUP_STRS_tas3_ESLPolicies(c, e);
  }

}

/* FUNC(zx_DEEP_CLONE_e_Header) */

/* Depth first traversal of data structure to clone it and its sublements.
 * The simple strings are handled as a special case according to dup_strs flag. */

/* Called by: */
struct zx_e_Header_s* zx_DEEP_CLONE_e_Header(struct zx_ctx* c, struct zx_e_Header_s* x, int dup_strs)
{
  x = (struct zx_e_Header_s*)zx_clone_elem_common(c, &x->gg, sizeof(struct zx_e_Header_s), dup_strs);
  /* *** deal with xmlns specifications in exc c14n way */

  x->id = zx_clone_attr(c, x->id);

  {
      struct zx_paos_Request_s* e;
      struct zx_paos_Request_s* en;
      struct zx_paos_Request_s* enn;
      for (enn = 0, e = x->Request; e; e = (struct zx_paos_Request_s*)e->gg.g.n) {
	  en = zx_DEEP_CLONE_paos_Request(c, e, dup_strs);
	  if (!enn)
	      x->Request = en;
	  else
	      enn->gg.g.n = &en->gg.g;
	  enn = en;
      }
  }
  {
      struct zx_paos_Response_s* e;
      struct zx_paos_Response_s* en;
      struct zx_paos_Response_s* enn;
      for (enn = 0, e = x->Response; e; e = (struct zx_paos_Response_s*)e->gg.g.n) {
	  en = zx_DEEP_CLONE_paos_Response(c, e, dup_strs);
	  if (!enn)
	      x->Response = en;
	  else
	      enn->gg.g.n = &en->gg.g;
	  enn = en;
      }
  }
  {
      struct zx_ecp_Request_s* e;
      struct zx_ecp_Request_s* en;
      struct zx_ecp_Request_s* enn;
      for (enn = 0, e = x->ecp_Request; e; e = (struct zx_ecp_Request_s*)e->gg.g.n) {
	  en = zx_DEEP_CLONE_ecp_Request(c, e, dup_strs);
	  if (!enn)
	      x->ecp_Request = en;
	  else
	      enn->gg.g.n = &en->gg.g;
	  enn = en;
      }
  }
  {
      struct zx_ecp_Response_s* e;
      struct zx_ecp_Response_s* en;
      struct zx_ecp_Response_s* enn;
      for (enn = 0, e = x->ecp_Response; e; e = (struct zx_ecp_Response_s*)e->gg.g.n) {
	  en = zx_DEEP_CLONE_ecp_Response(c, e, dup_strs);
	  if (!enn)
	      x->ecp_Response = en;
	  else
	      enn->gg.g.n = &en->gg.g;
	  enn = en;
      }
  }
  {
      struct zx_ecp_RelayState_s* e;
      struct zx_ecp_RelayState_s* en;
      struct zx_ecp_RelayState_s* enn;
      for (enn = 0, e = x->RelayState; e; e = (struct zx_ecp_RelayState_s*)e->gg.g.n) {
	  en = zx_DEEP_CLONE_ecp_RelayState(c, e, dup_strs);
	  if (!enn)
	      x->RelayState = en;
	  else
	      enn->gg.g.n = &en->gg.g;
	  enn = en;
      }
  }
  {
      struct zx_a_MessageID_s* e;
      struct zx_a_MessageID_s* en;
      struct zx_a_MessageID_s* enn;
      for (enn = 0, e = x->MessageID; e; e = (struct zx_a_MessageID_s*)e->gg.g.n) {
	  en = zx_DEEP_CLONE_a_MessageID(c, e, dup_strs);
	  if (!enn)
	      x->MessageID = en;
	  else
	      enn->gg.g.n = &en->gg.g;
	  enn = en;
      }
  }
  {
      struct zx_a_RelatesTo_s* e;
      struct zx_a_RelatesTo_s* en;
      struct zx_a_RelatesTo_s* enn;
      for (enn = 0, e = x->RelatesTo; e; e = (struct zx_a_RelatesTo_s*)e->gg.g.n) {
	  en = zx_DEEP_CLONE_a_RelatesTo(c, e, dup_strs);
	  if (!enn)
	      x->RelatesTo = en;
	  else
	      enn->gg.g.n = &en->gg.g;
	  enn = en;
      }
  }
  {
      struct zx_a_ReplyTo_s* e;
      struct zx_a_ReplyTo_s* en;
      struct zx_a_ReplyTo_s* enn;
      for (enn = 0, e = x->ReplyTo; e; e = (struct zx_a_ReplyTo_s*)e->gg.g.n) {
	  en = zx_DEEP_CLONE_a_ReplyTo(c, e, dup_strs);
	  if (!enn)
	      x->ReplyTo = en;
	  else
	      enn->gg.g.n = &en->gg.g;
	  enn = en;
      }
  }
  {
      struct zx_a_From_s* e;
      struct zx_a_From_s* en;
      struct zx_a_From_s* enn;
      for (enn = 0, e = x->From; e; e = (struct zx_a_From_s*)e->gg.g.n) {
	  en = zx_DEEP_CLONE_a_From(c, e, dup_strs);
	  if (!enn)
	      x->From = en;
	  else
	      enn->gg.g.n = &en->gg.g;
	  enn = en;
      }
  }
  {
      struct zx_a_FaultTo_s* e;
      struct zx_a_FaultTo_s* en;
      struct zx_a_FaultTo_s* enn;
      for (enn = 0, e = x->FaultTo; e; e = (struct zx_a_FaultTo_s*)e->gg.g.n) {
	  en = zx_DEEP_CLONE_a_FaultTo(c, e, dup_strs);
	  if (!enn)
	      x->FaultTo = en;
	  else
	      enn->gg.g.n = &en->gg.g;
	  enn = en;
      }
  }
  {
      struct zx_a_To_s* e;
      struct zx_a_To_s* en;
      struct zx_a_To_s* enn;
      for (enn = 0, e = x->To; e; e = (struct zx_a_To_s*)e->gg.g.n) {
	  en = zx_DEEP_CLONE_a_To(c, e, dup_strs);
	  if (!enn)
	      x->To = en;
	  else
	      enn->gg.g.n = &en->gg.g;
	  enn = en;
      }
  }
  {
      struct zx_a_Action_s* e;
      struct zx_a_Action_s* en;
      struct zx_a_Action_s* enn;
      for (enn = 0, e = x->Action; e; e = (struct zx_a_Action_s*)e->gg.g.n) {
	  en = zx_DEEP_CLONE_a_Action(c, e, dup_strs);
	  if (!enn)
	      x->Action = en;
	  else
	      enn->gg.g.n = &en->gg.g;
	  enn = en;
      }
  }
  {
      struct zx_a_ReferenceParameters_s* e;
      struct zx_a_ReferenceParameters_s* en;
      struct zx_a_ReferenceParameters_s* enn;
      for (enn = 0, e = x->ReferenceParameters; e; e = (struct zx_a_ReferenceParameters_s*)e->gg.g.n) {
	  en = zx_DEEP_CLONE_a_ReferenceParameters(c, e, dup_strs);
	  if (!enn)
	      x->ReferenceParameters = en;
	  else
	      enn->gg.g.n = &en->gg.g;
	  enn = en;
      }
  }
  {
      struct zx_sbf_Framework_s* e;
      struct zx_sbf_Framework_s* en;
      struct zx_sbf_Framework_s* enn;
      for (enn = 0, e = x->Framework; e; e = (struct zx_sbf_Framework_s*)e->gg.g.n) {
	  en = zx_DEEP_CLONE_sbf_Framework(c, e, dup_strs);
	  if (!enn)
	      x->Framework = en;
	  else
	      enn->gg.g.n = &en->gg.g;
	  enn = en;
      }
  }
  {
      struct zx_b_Framework_s* e;
      struct zx_b_Framework_s* en;
      struct zx_b_Framework_s* enn;
      for (enn = 0, e = x->b_Framework; e; e = (struct zx_b_Framework_s*)e->gg.g.n) {
	  en = zx_DEEP_CLONE_b_Framework(c, e, dup_strs);
	  if (!enn)
	      x->b_Framework = en;
	  else
	      enn->gg.g.n = &en->gg.g;
	  enn = en;
      }
  }
  {
      struct zx_b_Sender_s* e;
      struct zx_b_Sender_s* en;
      struct zx_b_Sender_s* enn;
      for (enn = 0, e = x->Sender; e; e = (struct zx_b_Sender_s*)e->gg.g.n) {
	  en = zx_DEEP_CLONE_b_Sender(c, e, dup_strs);
	  if (!enn)
	      x->Sender = en;
	  else
	      enn->gg.g.n = &en->gg.g;
	  enn = en;
      }
  }
  {
      struct zx_b_TargetIdentity_s* e;
      struct zx_b_TargetIdentity_s* en;
      struct zx_b_TargetIdentity_s* enn;
      for (enn = 0, e = x->TargetIdentity; e; e = (struct zx_b_TargetIdentity_s*)e->gg.g.n) {
	  en = zx_DEEP_CLONE_b_TargetIdentity(c, e, dup_strs);
	  if (!enn)
	      x->TargetIdentity = en;
	  else
	      enn->gg.g.n = &en->gg.g;
	  enn = en;
      }
  }
  {
      struct zx_b_CredentialsContext_s* e;
      struct zx_b_CredentialsContext_s* en;
      struct zx_b_CredentialsContext_s* enn;
      for (enn = 0, e = x->CredentialsContext; e; e = (struct zx_b_CredentialsContext_s*)e->gg.g.n) {
	  en = zx_DEEP_CLONE_b_CredentialsContext(c, e, dup_strs);
	  if (!enn)
	      x->CredentialsContext = en;
	  else
	      enn->gg.g.n = &en->gg.g;
	  enn = en;
      }
  }
  {
      struct zx_b_EndpointUpdate_s* e;
      struct zx_b_EndpointUpdate_s* en;
      struct zx_b_EndpointUpdate_s* enn;
      for (enn = 0, e = x->EndpointUpdate; e; e = (struct zx_b_EndpointUpdate_s*)e->gg.g.n) {
	  en = zx_DEEP_CLONE_b_EndpointUpdate(c, e, dup_strs);
	  if (!enn)
	      x->EndpointUpdate = en;
	  else
	      enn->gg.g.n = &en->gg.g;
	  enn = en;
      }
  }
  {
      struct zx_b_Timeout_s* e;
      struct zx_b_Timeout_s* en;
      struct zx_b_Timeout_s* enn;
      for (enn = 0, e = x->Timeout; e; e = (struct zx_b_Timeout_s*)e->gg.g.n) {
	  en = zx_DEEP_CLONE_b_Timeout(c, e, dup_strs);
	  if (!enn)
	      x->Timeout = en;
	  else
	      enn->gg.g.n = &en->gg.g;
	  enn = en;
      }
  }
  {
      struct zx_b_ProcessingContext_s* e;
      struct zx_b_ProcessingContext_s* en;
      struct zx_b_ProcessingContext_s* enn;
      for (enn = 0, e = x->ProcessingContext; e; e = (struct zx_b_ProcessingContext_s*)e->gg.g.n) {
	  en = zx_DEEP_CLONE_b_ProcessingContext(c, e, dup_strs);
	  if (!enn)
	      x->ProcessingContext = en;
	  else
	      enn->gg.g.n = &en->gg.g;
	  enn = en;
      }
  }
  {
      struct zx_b_Consent_s* e;
      struct zx_b_Consent_s* en;
      struct zx_b_Consent_s* enn;
      for (enn = 0, e = x->Consent; e; e = (struct zx_b_Consent_s*)e->gg.g.n) {
	  en = zx_DEEP_CLONE_b_Consent(c, e, dup_strs);
	  if (!enn)
	      x->Consent = en;
	  else
	      enn->gg.g.n = &en->gg.g;
	  enn = en;
      }
  }
  {
      struct zx_b_UsageDirective_s* e;
      struct zx_b_UsageDirective_s* en;
      struct zx_b_UsageDirective_s* enn;
      for (enn = 0, e = x->UsageDirective; e; e = (struct zx_b_UsageDirective_s*)e->gg.g.n) {
	  en = zx_DEEP_CLONE_b_UsageDirective(c, e, dup_strs);
	  if (!enn)
	      x->UsageDirective = en;
	  else
	      enn->gg.g.n = &en->gg.g;
	  enn = en;
      }
  }
  {
      struct zx_b_ApplicationEPR_s* e;
      struct zx_b_ApplicationEPR_s* en;
      struct zx_b_ApplicationEPR_s* enn;
      for (enn = 0, e = x->ApplicationEPR; e; e = (struct zx_b_ApplicationEPR_s*)e->gg.g.n) {
	  en = zx_DEEP_CLONE_b_ApplicationEPR(c, e, dup_strs);
	  if (!enn)
	      x->ApplicationEPR = en;
	  else
	      enn->gg.g.n = &en->gg.g;
	  enn = en;
      }
  }
  {
      struct zx_b_UserInteraction_s* e;
      struct zx_b_UserInteraction_s* en;
      struct zx_b_UserInteraction_s* enn;
      for (enn = 0, e = x->UserInteraction; e; e = (struct zx_b_UserInteraction_s*)e->gg.g.n) {
	  en = zx_DEEP_CLONE_b_UserInteraction(c, e, dup_strs);
	  if (!enn)
	      x->UserInteraction = en;
	  else
	      enn->gg.g.n = &en->gg.g;
	  enn = en;
      }
  }
  {
      struct zx_b_RedirectRequest_s* e;
      struct zx_b_RedirectRequest_s* en;
      struct zx_b_RedirectRequest_s* enn;
      for (enn = 0, e = x->RedirectRequest; e; e = (struct zx_b_RedirectRequest_s*)e->gg.g.n) {
	  en = zx_DEEP_CLONE_b_RedirectRequest(c, e, dup_strs);
	  if (!enn)
	      x->RedirectRequest = en;
	  else
	      enn->gg.g.n = &en->gg.g;
	  enn = en;
      }
  }
  {
      struct zx_b12_Correlation_s* e;
      struct zx_b12_Correlation_s* en;
      struct zx_b12_Correlation_s* enn;
      for (enn = 0, e = x->Correlation; e; e = (struct zx_b12_Correlation_s*)e->gg.g.n) {
	  en = zx_DEEP_CLONE_b12_Correlation(c, e, dup_strs);
	  if (!enn)
	      x->Correlation = en;
	  else
	      enn->gg.g.n = &en->gg.g;
	  enn = en;
      }
  }
  {
      struct zx_b12_Provider_s* e;
      struct zx_b12_Provider_s* en;
      struct zx_b12_Provider_s* enn;
      for (enn = 0, e = x->Provider; e; e = (struct zx_b12_Provider_s*)e->gg.g.n) {
	  en = zx_DEEP_CLONE_b12_Provider(c, e, dup_strs);
	  if (!enn)
	      x->Provider = en;
	  else
	      enn->gg.g.n = &en->gg.g;
	  enn = en;
      }
  }
  {
      struct zx_b12_ProcessingContext_s* e;
      struct zx_b12_ProcessingContext_s* en;
      struct zx_b12_ProcessingContext_s* enn;
      for (enn = 0, e = x->b12_ProcessingContext; e; e = (struct zx_b12_ProcessingContext_s*)e->gg.g.n) {
	  en = zx_DEEP_CLONE_b12_ProcessingContext(c, e, dup_strs);
	  if (!enn)
	      x->b12_ProcessingContext = en;
	  else
	      enn->gg.g.n = &en->gg.g;
	  enn = en;
      }
  }
  {
      struct zx_b12_Consent_s* e;
      struct zx_b12_Consent_s* en;
      struct zx_b12_Consent_s* enn;
      for (enn = 0, e = x->b12_Consent; e; e = (struct zx_b12_Consent_s*)e->gg.g.n) {
	  en = zx_DEEP_CLONE_b12_Consent(c, e, dup_strs);
	  if (!enn)
	      x->b12_Consent = en;
	  else
	      enn->gg.g.n = &en->gg.g;
	  enn = en;
      }
  }
  {
      struct zx_b12_UsageDirective_s* e;
      struct zx_b12_UsageDirective_s* en;
      struct zx_b12_UsageDirective_s* enn;
      for (enn = 0, e = x->b12_UsageDirective; e; e = (struct zx_b12_UsageDirective_s*)e->gg.g.n) {
	  en = zx_DEEP_CLONE_b12_UsageDirective(c, e, dup_strs);
	  if (!enn)
	      x->b12_UsageDirective = en;
	  else
	      enn->gg.g.n = &en->gg.g;
	  enn = en;
      }
  }
  {
      struct zx_mm7_TransactionID_s* e;
      struct zx_mm7_TransactionID_s* en;
      struct zx_mm7_TransactionID_s* enn;
      for (enn = 0, e = x->TransactionID; e; e = (struct zx_mm7_TransactionID_s*)e->gg.g.n) {
	  en = zx_DEEP_CLONE_mm7_TransactionID(c, e, dup_strs);
	  if (!enn)
	      x->TransactionID = en;
	  else
	      enn->gg.g.n = &en->gg.g;
	  enn = en;
      }
  }
  {
      struct zx_wsse_Security_s* e;
      struct zx_wsse_Security_s* en;
      struct zx_wsse_Security_s* enn;
      for (enn = 0, e = x->Security; e; e = (struct zx_wsse_Security_s*)e->gg.g.n) {
	  en = zx_DEEP_CLONE_wsse_Security(c, e, dup_strs);
	  if (!enn)
	      x->Security = en;
	  else
	      enn->gg.g.n = &en->gg.g;
	  enn = en;
      }
  }
  {
      struct zx_tas3_Status_s* e;
      struct zx_tas3_Status_s* en;
      struct zx_tas3_Status_s* enn;
      for (enn = 0, e = x->Status; e; e = (struct zx_tas3_Status_s*)e->gg.g.n) {
	  en = zx_DEEP_CLONE_tas3_Status(c, e, dup_strs);
	  if (!enn)
	      x->Status = en;
	  else
	      enn->gg.g.n = &en->gg.g;
	  enn = en;
      }
  }
  {
      struct zx_tas3_Credentials_s* e;
      struct zx_tas3_Credentials_s* en;
      struct zx_tas3_Credentials_s* enn;
      for (enn = 0, e = x->Credentials; e; e = (struct zx_tas3_Credentials_s*)e->gg.g.n) {
	  en = zx_DEEP_CLONE_tas3_Credentials(c, e, dup_strs);
	  if (!enn)
	      x->Credentials = en;
	  else
	      enn->gg.g.n = &en->gg.g;
	  enn = en;
      }
  }
  {
      struct zx_tas3_ESLPolicies_s* e;
      struct zx_tas3_ESLPolicies_s* en;
      struct zx_tas3_ESLPolicies_s* enn;
      for (enn = 0, e = x->ESLPolicies; e; e = (struct zx_tas3_ESLPolicies_s*)e->gg.g.n) {
	  en = zx_DEEP_CLONE_tas3_ESLPolicies(c, e, dup_strs);
	  if (!enn)
	      x->ESLPolicies = en;
	  else
	      enn->gg.g.n = &en->gg.g;
	  enn = en;
      }
  }

  return x;
}

/* FUNC(zx_WALK_SO_e_Header) */

/* Depth first traversal of the tree in either schema order or the wire order. */
 
int zx_WALK_SO_e_Header(struct zx_ctx* c, struct zx_e_Header_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
{
  int ret = callback(&x->gg.g, ctx);
  if (ret)
    return ret;
  
  /* *** deal with xmlns specifications in exc c14n way */


  
  ret = zx_walk_so_unknown_attributes(c, &x->gg, ctx, callback); 
  if (ret)
    return ret;

  {
      struct zx_paos_Request_s* e;
      for (e = x->Request; e; e = (struct zx_paos_Request_s*)e->gg.g.n) {
	  ret = zx_WALK_SO_paos_Request(c, e, ctx, callback);
	  if (ret)
	      return ret;
      }
  }
  {
      struct zx_paos_Response_s* e;
      for (e = x->Response; e; e = (struct zx_paos_Response_s*)e->gg.g.n) {
	  ret = zx_WALK_SO_paos_Response(c, e, ctx, callback);
	  if (ret)
	      return ret;
      }
  }
  {
      struct zx_ecp_Request_s* e;
      for (e = x->ecp_Request; e; e = (struct zx_ecp_Request_s*)e->gg.g.n) {
	  ret = zx_WALK_SO_ecp_Request(c, e, ctx, callback);
	  if (ret)
	      return ret;
      }
  }
  {
      struct zx_ecp_Response_s* e;
      for (e = x->ecp_Response; e; e = (struct zx_ecp_Response_s*)e->gg.g.n) {
	  ret = zx_WALK_SO_ecp_Response(c, e, ctx, callback);
	  if (ret)
	      return ret;
      }
  }
  {
      struct zx_ecp_RelayState_s* e;
      for (e = x->RelayState; e; e = (struct zx_ecp_RelayState_s*)e->gg.g.n) {
	  ret = zx_WALK_SO_ecp_RelayState(c, e, ctx, callback);
	  if (ret)
	      return ret;
      }
  }
  {
      struct zx_a_MessageID_s* e;
      for (e = x->MessageID; e; e = (struct zx_a_MessageID_s*)e->gg.g.n) {
	  ret = zx_WALK_SO_a_MessageID(c, e, ctx, callback);
	  if (ret)
	      return ret;
      }
  }
  {
      struct zx_a_RelatesTo_s* e;
      for (e = x->RelatesTo; e; e = (struct zx_a_RelatesTo_s*)e->gg.g.n) {
	  ret = zx_WALK_SO_a_RelatesTo(c, e, ctx, callback);
	  if (ret)
	      return ret;
      }
  }
  {
      struct zx_a_ReplyTo_s* e;
      for (e = x->ReplyTo; e; e = (struct zx_a_ReplyTo_s*)e->gg.g.n) {
	  ret = zx_WALK_SO_a_ReplyTo(c, e, ctx, callback);
	  if (ret)
	      return ret;
      }
  }
  {
      struct zx_a_From_s* e;
      for (e = x->From; e; e = (struct zx_a_From_s*)e->gg.g.n) {
	  ret = zx_WALK_SO_a_From(c, e, ctx, callback);
	  if (ret)
	      return ret;
      }
  }
  {
      struct zx_a_FaultTo_s* e;
      for (e = x->FaultTo; e; e = (struct zx_a_FaultTo_s*)e->gg.g.n) {
	  ret = zx_WALK_SO_a_FaultTo(c, e, ctx, callback);
	  if (ret)
	      return ret;
      }
  }
  {
      struct zx_a_To_s* e;
      for (e = x->To; e; e = (struct zx_a_To_s*)e->gg.g.n) {
	  ret = zx_WALK_SO_a_To(c, e, ctx, callback);
	  if (ret)
	      return ret;
      }
  }
  {
      struct zx_a_Action_s* e;
      for (e = x->Action; e; e = (struct zx_a_Action_s*)e->gg.g.n) {
	  ret = zx_WALK_SO_a_Action(c, e, ctx, callback);
	  if (ret)
	      return ret;
      }
  }
  {
      struct zx_a_ReferenceParameters_s* e;
      for (e = x->ReferenceParameters; e; e = (struct zx_a_ReferenceParameters_s*)e->gg.g.n) {
	  ret = zx_WALK_SO_a_ReferenceParameters(c, e, ctx, callback);
	  if (ret)
	      return ret;
      }
  }
  {
      struct zx_sbf_Framework_s* e;
      for (e = x->Framework; e; e = (struct zx_sbf_Framework_s*)e->gg.g.n) {
	  ret = zx_WALK_SO_sbf_Framework(c, e, ctx, callback);
	  if (ret)
	      return ret;
      }
  }
  {
      struct zx_b_Framework_s* e;
      for (e = x->b_Framework; e; e = (struct zx_b_Framework_s*)e->gg.g.n) {
	  ret = zx_WALK_SO_b_Framework(c, e, ctx, callback);
	  if (ret)
	      return ret;
      }
  }
  {
      struct zx_b_Sender_s* e;
      for (e = x->Sender; e; e = (struct zx_b_Sender_s*)e->gg.g.n) {
	  ret = zx_WALK_SO_b_Sender(c, e, ctx, callback);
	  if (ret)
	      return ret;
      }
  }
  {
      struct zx_b_TargetIdentity_s* e;
      for (e = x->TargetIdentity; e; e = (struct zx_b_TargetIdentity_s*)e->gg.g.n) {
	  ret = zx_WALK_SO_b_TargetIdentity(c, e, ctx, callback);
	  if (ret)
	      return ret;
      }
  }
  {
      struct zx_b_CredentialsContext_s* e;
      for (e = x->CredentialsContext; e; e = (struct zx_b_CredentialsContext_s*)e->gg.g.n) {
	  ret = zx_WALK_SO_b_CredentialsContext(c, e, ctx, callback);
	  if (ret)
	      return ret;
      }
  }
  {
      struct zx_b_EndpointUpdate_s* e;
      for (e = x->EndpointUpdate; e; e = (struct zx_b_EndpointUpdate_s*)e->gg.g.n) {
	  ret = zx_WALK_SO_b_EndpointUpdate(c, e, ctx, callback);
	  if (ret)
	      return ret;
      }
  }
  {
      struct zx_b_Timeout_s* e;
      for (e = x->Timeout; e; e = (struct zx_b_Timeout_s*)e->gg.g.n) {
	  ret = zx_WALK_SO_b_Timeout(c, e, ctx, callback);
	  if (ret)
	      return ret;
      }
  }
  {
      struct zx_b_ProcessingContext_s* e;
      for (e = x->ProcessingContext; e; e = (struct zx_b_ProcessingContext_s*)e->gg.g.n) {
	  ret = zx_WALK_SO_b_ProcessingContext(c, e, ctx, callback);
	  if (ret)
	      return ret;
      }
  }
  {
      struct zx_b_Consent_s* e;
      for (e = x->Consent; e; e = (struct zx_b_Consent_s*)e->gg.g.n) {
	  ret = zx_WALK_SO_b_Consent(c, e, ctx, callback);
	  if (ret)
	      return ret;
      }
  }
  {
      struct zx_b_UsageDirective_s* e;
      for (e = x->UsageDirective; e; e = (struct zx_b_UsageDirective_s*)e->gg.g.n) {
	  ret = zx_WALK_SO_b_UsageDirective(c, e, ctx, callback);
	  if (ret)
	      return ret;
      }
  }
  {
      struct zx_b_ApplicationEPR_s* e;
      for (e = x->ApplicationEPR; e; e = (struct zx_b_ApplicationEPR_s*)e->gg.g.n) {
	  ret = zx_WALK_SO_b_ApplicationEPR(c, e, ctx, callback);
	  if (ret)
	      return ret;
      }
  }
  {
      struct zx_b_UserInteraction_s* e;
      for (e = x->UserInteraction; e; e = (struct zx_b_UserInteraction_s*)e->gg.g.n) {
	  ret = zx_WALK_SO_b_UserInteraction(c, e, ctx, callback);
	  if (ret)
	      return ret;
      }
  }
  {
      struct zx_b_RedirectRequest_s* e;
      for (e = x->RedirectRequest; e; e = (struct zx_b_RedirectRequest_s*)e->gg.g.n) {
	  ret = zx_WALK_SO_b_RedirectRequest(c, e, ctx, callback);
	  if (ret)
	      return ret;
      }
  }
  {
      struct zx_b12_Correlation_s* e;
      for (e = x->Correlation; e; e = (struct zx_b12_Correlation_s*)e->gg.g.n) {
	  ret = zx_WALK_SO_b12_Correlation(c, e, ctx, callback);
	  if (ret)
	      return ret;
      }
  }
  {
      struct zx_b12_Provider_s* e;
      for (e = x->Provider; e; e = (struct zx_b12_Provider_s*)e->gg.g.n) {
	  ret = zx_WALK_SO_b12_Provider(c, e, ctx, callback);
	  if (ret)
	      return ret;
      }
  }
  {
      struct zx_b12_ProcessingContext_s* e;
      for (e = x->b12_ProcessingContext; e; e = (struct zx_b12_ProcessingContext_s*)e->gg.g.n) {
	  ret = zx_WALK_SO_b12_ProcessingContext(c, e, ctx, callback);
	  if (ret)
	      return ret;
      }
  }
  {
      struct zx_b12_Consent_s* e;
      for (e = x->b12_Consent; e; e = (struct zx_b12_Consent_s*)e->gg.g.n) {
	  ret = zx_WALK_SO_b12_Consent(c, e, ctx, callback);
	  if (ret)
	      return ret;
      }
  }
  {
      struct zx_b12_UsageDirective_s* e;
      for (e = x->b12_UsageDirective; e; e = (struct zx_b12_UsageDirective_s*)e->gg.g.n) {
	  ret = zx_WALK_SO_b12_UsageDirective(c, e, ctx, callback);
	  if (ret)
	      return ret;
      }
  }
  {
      struct zx_mm7_TransactionID_s* e;
      for (e = x->TransactionID; e; e = (struct zx_mm7_TransactionID_s*)e->gg.g.n) {
	  ret = zx_WALK_SO_mm7_TransactionID(c, e, ctx, callback);
	  if (ret)
	      return ret;
      }
  }
  {
      struct zx_wsse_Security_s* e;
      for (e = x->Security; e; e = (struct zx_wsse_Security_s*)e->gg.g.n) {
	  ret = zx_WALK_SO_wsse_Security(c, e, ctx, callback);
	  if (ret)
	      return ret;
      }
  }
  {
      struct zx_tas3_Status_s* e;
      for (e = x->Status; e; e = (struct zx_tas3_Status_s*)e->gg.g.n) {
	  ret = zx_WALK_SO_tas3_Status(c, e, ctx, callback);
	  if (ret)
	      return ret;
      }
  }
  {
      struct zx_tas3_Credentials_s* e;
      for (e = x->Credentials; e; e = (struct zx_tas3_Credentials_s*)e->gg.g.n) {
	  ret = zx_WALK_SO_tas3_Credentials(c, e, ctx, callback);
	  if (ret)
	      return ret;
      }
  }
  {
      struct zx_tas3_ESLPolicies_s* e;
      for (e = x->ESLPolicies; e; e = (struct zx_tas3_ESLPolicies_s*)e->gg.g.n) {
	  ret = zx_WALK_SO_tas3_ESLPolicies(c, e, ctx, callback);
	  if (ret)
	      return ret;
      }
  }

  
  return zx_walk_so_unknown_elems_and_content(c, &x->gg, ctx, callback);
}

/* FUNC(zx_WALK_WO_e_Header) */

int zx_WALK_WO_e_Header(struct zx_ctx* c, struct zx_e_Header_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
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

#define EL_NAME   e_detail
#define EL_STRUCT zx_e_detail_s
#define EL_NS     e
#define EL_TAG    detail

/* FUNC(zx_FREE_e_detail) */

/* Depth first traversal of data structure to free it and its subelements. Simple
 * strings are handled as a special case according to the free_strs flag. This
 * is useful if the strings point to underlying data from the wire that was
 * allocated differently. */

/* Called by: */
void zx_FREE_e_detail(struct zx_ctx* c, struct zx_e_detail_s* x, int free_strs)
{
  /* *** deal with xmlns specifications in exc c14n way */


  {
      struct zx_lu_Status_s* e;
      struct zx_lu_Status_s* en;
      for (e = x->Status; e; e = en) {
	  en = (struct zx_lu_Status_s*)e->gg.g.n;
	  zx_FREE_lu_Status(c, e, free_strs);
      }
  }


  zx_free_elem_common(c, &x->gg, free_strs); 
}

/* FUNC(zx_NEW_e_detail) */

/* Trivial allocator/constructor for the datatype. */

/* Called by: */
struct zx_e_detail_s* zx_NEW_e_detail(struct zx_ctx* c)
{
  struct zx_e_detail_s* x = ZX_ZALLOC(c, struct zx_e_detail_s);
  x->gg.g.tok = zx_e_detail_ELEM;
  return x;
}

#ifdef ZX_ENA_AUX

/* FUNC(zx_DUP_STRS_e_detail) */

/* Depth first traversal of data structure to copy its simple strings
 * to memory allocated from the memory allocator. The decoder will
 * use the underlying wireprotocol PDU buffer for strings, i.e.
 * strings are not copied - they point to the real data. If the
 * datastructure needs to outlast the protocol data or needs a different
 * memory allocation strategy, you need to call this function.  */

/* Called by: */
void zx_DUP_STRS_e_detail(struct zx_ctx* c, struct zx_e_detail_s* x)
{
  zx_dup_strs_common(c, &x->gg);
  /* *** deal with xmlns specifications in exc c14n way */


  {
      struct zx_lu_Status_s* e;
      for (e = x->Status; e; e = (struct zx_lu_Status_s*)e->gg.g.n)
	  zx_DUP_STRS_lu_Status(c, e);
  }

}

/* FUNC(zx_DEEP_CLONE_e_detail) */

/* Depth first traversal of data structure to clone it and its sublements.
 * The simple strings are handled as a special case according to dup_strs flag. */

/* Called by: */
struct zx_e_detail_s* zx_DEEP_CLONE_e_detail(struct zx_ctx* c, struct zx_e_detail_s* x, int dup_strs)
{
  x = (struct zx_e_detail_s*)zx_clone_elem_common(c, &x->gg, sizeof(struct zx_e_detail_s), dup_strs);
  /* *** deal with xmlns specifications in exc c14n way */


  {
      struct zx_lu_Status_s* e;
      struct zx_lu_Status_s* en;
      struct zx_lu_Status_s* enn;
      for (enn = 0, e = x->Status; e; e = (struct zx_lu_Status_s*)e->gg.g.n) {
	  en = zx_DEEP_CLONE_lu_Status(c, e, dup_strs);
	  if (!enn)
	      x->Status = en;
	  else
	      enn->gg.g.n = &en->gg.g;
	  enn = en;
      }
  }

  return x;
}

/* FUNC(zx_WALK_SO_e_detail) */

/* Depth first traversal of the tree in either schema order or the wire order. */
 
int zx_WALK_SO_e_detail(struct zx_ctx* c, struct zx_e_detail_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
{
  int ret = callback(&x->gg.g, ctx);
  if (ret)
    return ret;
  
  /* *** deal with xmlns specifications in exc c14n way */


  
  ret = zx_walk_so_unknown_attributes(c, &x->gg, ctx, callback); 
  if (ret)
    return ret;

  {
      struct zx_lu_Status_s* e;
      for (e = x->Status; e; e = (struct zx_lu_Status_s*)e->gg.g.n) {
	  ret = zx_WALK_SO_lu_Status(c, e, ctx, callback);
	  if (ret)
	      return ret;
      }
  }

  
  return zx_walk_so_unknown_elems_and_content(c, &x->gg, ctx, callback);
}

/* FUNC(zx_WALK_WO_e_detail) */

int zx_WALK_WO_e_detail(struct zx_ctx* c, struct zx_e_detail_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
{
  ERR("*** walk_wo not implemented %d", 0);
  return 0;
}

#endif


/* EOF -- c/zx-e-aux.c */
