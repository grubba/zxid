/* wsf.h  -  Widely used Liberty ID-WSF constants
 * Copyright (c) 2006-2007 Symlabs (symlabs@symlabs.com), All Rights Reserved.
 * Author: Sampo Kellomaki (sampo@iki.fi)
 * This is confidential unpublished proprietary source code of the author.
 * NO WARRANTY, not even implied warranties. Contains trade secrets.
 * Distribution prohibited unless authorized in writing.
 * Licensed under Apache License 2.0, see file COPYING.
 * $Id: wsf.h,v 1.8 2009-11-24 23:53:40 sampo Exp $
 *
 * 26.12.2006, created --Sampo
 */

#ifndef _wsf_h
#define _wsf_h

/* AuthnSvc */

#define XMLNS_SA     "urn:liberty:sa:2006-08"
#define XMLNS_IMS    "urn:liberty:ims:2006-08"
#define XMLNS_LIB    "urn:liberty:iff:2003-08"
#define ACT_SASL_REQ "urn:liberty:sa:2006-08:SASLRequest"
#define ACT_SASL_RES "urn:liberty:sa:2006-08:SASLResponse"
#define PWTRUNCATE   "urn:liberty:sa:pw:truncate"
#define PWLOWERCASE  "urn:liberty:sa:pw:lowercase"
#define PWUPPERCASE  "urn:liberty:sa:pw:uppercase"
#define PWSELECT     "urn:liberty:sa:pw:select"

/* Subscriptions and Notifications */

#define XMLNS_SUBS         "urn:liberty:ssos:2006-08"  /* *** wrong? ssos? */
#define XMLNS_SUBSREF      "urn:liberty:ssos:2006-08:ref"  /* *** wrong? ssos? */
#define SUBS_OPT_NOSUBSCIB "urn:liberty:subs:noSubscribe"
#define SUBS_OPT_NOQUESUBS "urn:liberty:subs:noQuerySubscriptions"
#define SUBS_END_EXPIRED   "urn:liberty:dst:endreason:expired"
#define SUBS_END_DELETED   "urn:liberty:dst:endreason:resourcedeleted"

/* Discovery */

#define WSF11_DI_RO "DiscoveryResourceOffering"               /* Name of bootstrap attribute */
#define WSF20_DI_RO "urn:liberty:disco:2006-08:DiscoveryEPR"

#define IMPLIED_RSC        "urn:liberty:isf:implied-resource"
#define XMLNS_DISCO_1_1    "urn:liberty:disco:2003-08"
#define XMLNS_DISCO_EXT    "urn:liberty:disco:2004-04"
#define XMLNS_DISCO_2_0    "urn:liberty:disco:2006-08"
//#define XMLNS_DISCO_2_0    "urn:liberty:disco:2005-11"
//#define WSF20_DI_RO "urn:liberty:disco:2005-11:DiscoveryEPR"
#define XMLNS_SBF          "urn:liberty:sb"
#define ACT_QUE            "urn:liberty:disco:2006-08:Query"
#define ACT_QUE_RES        "urn:liberty:disco:2006-08:QueryResponse"
#define ACT_ASSO_QUE     "urn:liberty:disco:2006-08:SvcMDAssociationQuery"
#define ACT_ASSO_QUE_RES "urn:liberty:disco:2006-08:SvcMDAssociationQueryResponse"
#define ACT_ASSO_ADD     "urn:liberty:disco:2006-08:SvcMDAssociationAdd"
#define ACT_ASSO_ADD_RES "urn:liberty:disco:2006-08:SvcMDAssociationAddResponse"
#define ACT_ASSO_DEL     "urn:liberty:disco:2006-08:SvcMDAssociationDelete"
#define ACT_ASSO_DEL_RES "urn:liberty:disco:2006-08:SvcMDAssociationDeleteResponse"
#define ACT_SVCMD_QUE      "urn:liberty:disco:2006-08:SvcMDQuery"
#define ACT_SVCMD_QUE_RES  "urn:liberty:disco:2006-08:SvcMDQueryResponse"
#define ACT_SVCMD_REG      "urn:liberty:disco:2006-08:SvcMDRegister"
#define ACT_SVCMD_REG_RES  "urn:liberty:disco:2006-08:SvcMDRegisterResponse"
#define ACT_SVCMD_REP      "urn:liberty:disco:2006-08:SvcMDReplace"
#define ACT_SVCMD_REP_RES  "urn:liberty:disco:2006-08:SvcMDReplaceResponse"
#define ACT_SVCMD_DEL      "urn:liberty:disco:2006-08:SvcMDDelete"
#define ACT_SVCMD_DEL_RES  "urn:liberty:disco:2006-08:SvcMDDeleteResponse"

/* GeoLocation */

#define XMLNS_GL          "urn:liberty:id-sis-gl:2005-07"
#define GL_OPT_SHAPE      "urn:liberty:id-sis-gl:shape"
#define GL_OPT_SPEED      "urn:liberty:id-sis-gl:speed"
#define GL_OPT_DIRECTION  "urn:liberty:id-sis-gl:direction"
#define GL_OPT_HEADING    "urn:liberty:id-sis-gl:heading"
#define GL_OPT_ALT        "urn:liberty:id-sis-gl:alt"
#define GL_OPT_CIVIL_DATA "urn:liberty:id-sis-gl:civil-data"
#define GL_OPT_AC         "urn:liberty:id-sis-gl:areacomparison"
#define GL_OPT_AC_ONLY    "urn:liberty:id-sis-gl:onlyareacomparison"
#define GL_OPT_ACC_HIGH   "urn:liberty:id-sis-gl:accuracy:high"
#define GL_OPT_ACC_MEDIUM "urn:liberty:id-sis-gl:accuracy:medium"
#define GL_OPT_ACC_LOW    "urn:liberty:id-sis-gl:accuracy:low"

/* Interaction Service */

#define XMLNS_IS11   "urn:liberty:is:2003-08"
#define XMLNS_IS20   "urn:liberty:is:2006-08"
#define ACT_IREQ     "urn:liberty:is:2006-08:InteractionRequest"
#define ACT_IRES     "urn:liberty:is:2006-08:InteractionResponse"

/* Personal Profile */

#define OPT_PP        "urn:liberty:id-sis-pp"
#define OPT_PP_INAME  "urn:liberty:id-sis-pp:informalName"
#define OPT_PP_CN     "urn:liberty:id-sis-pp:cn"
#define OPT_PP_LEG    "urn:liberty:id-sis-pp:legal"
#define OPT_PP_ADD    "urn:liberty:id-sis-pp:address"
#define OPTC_PP       "urn:liberty:id-sis-pp:can"
#define OPTC_PP_INAME "urn:liberty:id-sis-pp:can:informalName"
#define OPTC_PP_CN    "urn:liberty:id-sis-pp:can:cn"
#define OPTC_PP_LEG   "urn:liberty:id-sis-pp:can:legal"
#define OPTC_PP_ADD   "urn:liberty:id-sis-pp:can:address"
#define OPT_MULT_QI   "urn:liberty:dst:multipleQueryItems"
#define OPT_MULT_MI   "urn:liberty:dst:multipleModification"
#define XMLNS_PP      "urn:liberty:id-sis-pp:2003-08"

/* People Service */

#define PS_COL                "urn:liberty:ps:collection"
#define PS_ENT                "urn:liberty:ps:entity"
#define XMLNS_PS              "urn:liberty:ps:2006-08"
#define ACT_PS_ADDENT_REQ     "urn:liberty:ps:2006-08:AddEntityRequest"
#define ACT_PS_ADDENT_RES     "urn:liberty:ps:2006-08:AddEntityResponse"
#define ACT_PS_ADDKENT_REQ    "urn:liberty:ps:2006-08:AddKnownEntityRequest"
#define ACT_PS_ADDKENT_RES    "urn:liberty:ps:2006-08:AddKnownEntityResponse"
#define ACT_PS_REMENT_REQ     "urn:liberty:ps:2006-08:RemoveEntityRequest"
#define ACT_PS_REMENT_RES     "urn:liberty:ps:2006-08:RemoveEntityResponse"
#define ACT_PS_ADDCOL_REQ     "urn:liberty:ps:2006-08:AddCollectionRequest"
#define ACT_PS_ADDCOL_RES     "urn:liberty:ps:2006-08:AddCollectionResponse"
#define ACT_PS_REMCOL_REQ     "urn:liberty:ps:2006-08:RemoveCollectionRequest"
#define ACT_PS_REMCOL_RES     "urn:liberty:ps:2006-08:RemoveCollectionResponse"
#define ACT_PS_ADDTOCOL_REQ   "urn:liberty:ps:2006-08:AddToCollectionRequest"
#define ACT_PS_ADDTOCOL_RES   "urn:liberty:ps:2006-08:AddToCollectionResponse"
#define ACT_PS_REMFROMCOL_REQ "urn:liberty:ps:2006-08:RemoveFromCollectionRequest"
#define ACT_PS_REMFROMCOL_RES "urn:liberty:ps:2006-08:RemoveFromCollectionResponse"
#define ACT_PS_LISTMEM_REQ    "urn:liberty:ps:2006-08:ListMembersRequest"
#define ACT_PS_LISTMEM_RES    "urn:liberty:ps:2006-08:ListMembersResponse"
#define ACT_PS_GETOBJ_REQ     "urn:liberty:ps:2006-08:GetObjectInfoRequest"
#define ACT_PS_GETOBJ_RES     "urn:liberty:ps:2006-08:GetObjectInfoResponse"
#define ACT_PS_SETOBJ_REQ     "urn:liberty:ps:2006-08:SetObjectInfoRequest"
#define ACT_PS_SETOBJ_RES     "urn:liberty:ps:2006-08:SetObjectInfoResponse"
#define ACT_PS_QUEOBJ_REQ     "urn:liberty:ps:2006-08:QueryObjectsRequest"
#define ACT_PS_QUEOBJ_RES     "urn:liberty:ps:2006-08:AueryObjectsResponse"
#define ACT_PS_TESTMEM_REQ    "urn:liberty:ps:2006-08:TestMembershipRequest"
#define ACT_PS_TESTMEM_RES    "urn:liberty:ps:2006-08:TestMembershipResponse"
#define ACT_PS_RSLVID_REQ     "urn:liberty:ps:2006-08:ResolveIdentifierRequest"
#define ACT_PS_RSLVID_RES     "urn:liberty:ps:2006-08:ResolveIdentifierResponse"
#define ACT_PS_NOTIFY         "urn:liberty:ps:2006-08:Notify"
#define ACT_PS_NOTIFY_RES     "urn:liberty:ps:2006-08:NotifyResponse"

/* SecMechs - Security Mechanisms */

#define XMLNS_SEC   "urn:liberty:security:2006-08"
#define TOKNUSG_SEC "urn:liberty:security:tokenusage:2006-08:SecurityToken"
#define TOKNUSG_TID "urn:liberty:security:tokenusage:2006-08:TargetIdentity"
#define TOKNUSG_IID "urn:liberty:security:tokenusage:2006-08:InvocationIdentity"
#define WSF10_SEC_MECH_NULL_BEARER  "urn:liberty:security:2004-04:null:Bearer"
#define WSF10_SEC_MECH_TLS_BEARER   "urn:liberty:security:2004-04:TLS:Bearer"
#define WSF11_SEC_MECH_NULL_NULL    "urn:liberty:security:2003-08:null:null"
#define WSF11_SEC_MECH_TLS_NULL     "urn:liberty:security:2003-08:TLS:null"
#define WSF11_SEC_MECH_CLTLS_NULL   "urn:liberty:security:2003-08:ClientTLS:null"
#define WSF11_SEC_MECH_NULL_BEARER  "urn:liberty:security:2005-02:null:Bearer"
#define WSF11_SEC_MECH_TLS_BEARER   "urn:liberty:security:2005-02:TLS:Bearer"
#define WSF11_SEC_MECH_CLTLS_BEARER "urn:liberty:security:2005-02:ClientTLS:Bearer"
#define WSF11_SEC_MECH_NULL_X509    "urn:liberty:security:2005-02:null:X509"
#define WSF11_SEC_MECH_TLS_X509     "urn:liberty:security:2005-02:TLS:X509"
#define WSF11_SEC_MECH_CLTLS_X509   "urn:liberty:security:2005-02:ClientTLS:X509"
#define WSF11_SEC_MECH_NULL_SAML    "urn:liberty:security:2005-02:null:SAML"
#define WSF11_SEC_MECH_TLS_SAML     "urn:liberty:security:2005-02:TLS:SAML"
#define WSF11_SEC_MECH_CLTLS_SAML   "urn:liberty:security:2005-02:ClientTLS:SAML"
#define WSF20_SEC_MECH_NULL_NULL    "urn:liberty:security:2005-02:null:null"
#define WSF20_SEC_MECH_TLS_NULL     "urn:liberty:security:2005-02:TLS:null"
#define WSF20_SEC_MECH_NULL_BEARER  "urn:liberty:security:2005-02:null:Bearer"
#define WSF20_SEC_MECH_TLS_BEARER   "urn:liberty:security:2005-02:TLS:Bearer"
#define WSF20_SEC_MECH_NULL_SAML2   "urn:liberty:security:2006-08:null:SAMLV2"
#define WSF20_SEC_MECH_TLS_SAML2    "urn:liberty:security:2006-08:TLS:SAMLV2"
#define WSF20_SEC_MECH_CLTLS_SAML2  "urn:liberty:security:2006-08:ClientTLS:SAMLV2"
#define WSF20_SEC_MECH_CLTLS_PEERS2 "urn:liberty:security:2006-08:ClientTLS:peerSAMLV2"

#define SAML2_TOK_PROFILE "http://docs.oasis-open.org/wss/oasis-wss-saml-token-profile-1.1#SAMLV2.0"
#define SAMLID_TOK_PROFILE "http://docs.oasis-open.org/wss/oasis-wss-saml-token-profile-1.1#SAMLID"
#define WSS_X509_TOKEN_PROFILE "http://docs.oasis-open.org/wss/2004/01/oasis-200401-wss-x509-token-profile-1.0#X509v3"

/* SOAP Binding */

#define SB_EPUPD_COMP  "urn:liberty:sb:2006-08:EndpointUpdate:Complete"
#define SB_EPUPD_PART  "urn:liberty:sb:2006-08:EndpointUpdate:Partial"
#define SB_EPUPD_NOCH  "urn:liberty:sb:2006-08:EndpointUpdate:NoChange"
#define A_ANON         "http://www.w3.org/2005/03/addressing/role/anonymous"

/* Misc */

#define XMLNS_CSM      "urn:liberty:id-sis-csm:2006-02"
#define XMLNS_LU   "urn:liberty:util:2006-08"
#define XMLNS_HLO     "urn:liberty:id-sis-hlo:2006-08:dst-2.1"
#define DST_ACC_CHALLENGE "urn:liberty:dst:acc:challenge"
#define XMLNS_CXP      "urn:liberty:id-sis-cxp:2005-10:dst-2.1"
#define XMLNS_LIB_MD "urn:liberty:metadata:2003-08"
#define XMLNS_LIB    "urn:liberty:iff:2003-08"
#define XMLNS_AC     "urn:liberty:ac:2003-08"
#define LIBERTY_NAMEID_FMT_FED "urn:liberty:iff:nameid:federated"
#define LIBERTY_NAMEID_FMT_ONE "urn:liberty:iff:nameid:one-time"
#define LIBERTY_NAMEID_FMT_ENC "urn:liberty:iff:nameid:encrypted"
#define LIBERTY_NAMEID_FMT_ENT "urn:liberty:iff:nameid:entityID"
#define XMLNS_PAOS   "urn:liberty:paos:2003-08"

#define PAOS_HDR "ver=\"urn:liberty:paos:2003-08\"; \"urn:oasis:names:tc:SAML:2.0:profiles:SSO:ecp\""
#define LIBERTY_ENA_HDR "LIBV=urn:liberty:iff:2003-08 http://projectliberty.org/specs/v1"

#define XMLNS_LIB   "urn:liberty:iff:2003-08"
#define XMLNS_AC    "urn:liberty:ac:2003-08"
#define LIBERTY_NAMEID_FMT_FED "urn:liberty:iff:nameid:federated"
#define LIBERTY_NAMEID_FMT_ONE "urn:liberty:iff:nameid:one-time"
#define LIBERTY_NAMEID_FMT_ENC "urn:liberty:iff:nameid:encrypted"
#define LIBERTY_NAMEID_FMT_ENT "urn:liberty:iff:nameid:entityID"
#define LIBERTY_CONSENT_OBTAINED "urn:liberty:consent:obtained"
#define XMLNS_DAP      "urn:liberty:id-sis-dap:2006-02:dst-2.1"

#endif
