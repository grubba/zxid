/* zxid.h  -  Definitions for zxid CGI
 * Copyright (c) 2009-2010 Sampo Kellomaki (sampo@iki.fi), All Rights Reserved.
 * Copyright (c) 2006-2009 Symlabs (symlabs@symlabs.com), All Rights Reserved.
 * Author: Sampo Kellomaki (sampo@iki.fi)
 * This is confidential unpublished proprietary source code of the author.
 * NO WARRANTY, not even implied warranties. Contains trade secrets.
 * Distribution prohibited unless authorized in writing.
 * Licensed under Apache License 2.0, see file COPYING.
 * $Id: zxid.h,v 1.94 2010-01-08 02:10:09 sampo Exp $
 *
 * 12.8.2006,  created --Sampo
 * 18.11.2006, log signing support --Sampo
 * 12.10.2007, new conf options --Sampo
 * 22.2.2008,  added path_supplied feature --Sampo
 * 4.10.2008,  added documentation --Sampo
 * 29.9.2009,  added PDP_URL --Sampo
 * 7.1.2010,   added WSC and WSP signing options --Sampo
 * 26.5.2010,  reworked typedefs --Sampo
 * 31.5.2010,  eliminated many include dependencies from the public API --Sampo
 * 13.11.2010, added ZXID_DECL for benefit of the Windows port --Sampo
 */

#ifndef _zxid_h
#define _zxid_h

#include <memory.h>
#include <string.h>
#ifdef USE_CURL
#include <curl/curl.h>
#endif

#include <zx/zx.h>

/* ZXID_DECL allows all API functions to be qualified with a declatation, such
 * as relating to the calling convention (e.g. c-decl). Such qualification
 * is very important in the Windows environment. In such environment ZXID_DECL
 * will be defined in Makefile to cause the desired effect. */

#ifndef ZXID_DECL
#define ZXID_DECL
#endif

#ifdef __cplusplus
extern "C" {
#endif

#ifdef ZXID_FULL_HEADERS
#include "c/zx-data.h"  /* Generated. If missing, run `make dep ENA_GEN=1' */
#else
/* Since we only need pointers to these generated structures, we do not
 * really need to include (or ship) c/zx-data.h. Just forward declare
 * them here. */
struct zx_root_s;
struct zx_e_Envelope_s;
struct zx_e_Header_s;
struct zx_e_Body_s;
struct zx_e_Fault_s;
struct zx_tas3_Status_s;
struct zx_a_EndpointReference_s;
struct zx_a_Address_s;
struct zx_sa_EncryptedAssertion_s;
struct zx_sa_Assertion_s;
struct zx_sa_NameID_s;
struct zx_sa_Issuer_s;
struct zx_sa_Attribute_s;
struct zx_sa_EncryptedID_s;
struct zx_sa_Subject_s;
struct zx_sa_AuthnStatement_s;
struct zx_sa_AttributeStatement_s;
struct zx_sec_Token_s;
struct zx_sp_Response_s;
struct zx_sp_Status_s;
struct zx_sp_NewEncryptedID_s;
struct zx_sp_AuthnRequest_s;
struct zx_sp_ArtifactResolve_s;
struct zx_sp_LogoutRequest_s;
struct zx_sp_LogoutResponse_s;
struct zx_sp_ManageNameIDRequest_s;
struct zx_sp_ManageNameIDResponse_s;
struct zx_sp_NameIDMappingRequest_s;
struct zx_sp_NameIDMappingResponse_s;
struct zx_sa11_Assertion_s;
struct zx_sa11_Assertion_s;
struct zx_ff12_Assertion_s;
struct zx_ff12_Assertion_s;
struct zx_ds_Signature_s;
struct zx_ds_Reference_s;
struct zx_ds_KeyInfo_s;
struct zx_xenc_EncryptedData_s;
struct zx_xenc_EncryptedKey_s;
struct zx_md_KeyDescriptor_s;
struct zx_md_ArtifactResolutionService_s;
struct zx_md_SingleSignOnService_s;
struct zx_md_SingleLogoutService_s;
struct zx_md_ManageNameIDService_s;
struct zx_md_AssertionConsumerService_s;
struct zx_md_IDPSSODescriptor_s;
struct zx_md_SPSSODescriptor_s;
struct zx_md_EntityDescriptor_s;
struct zx_xasa_XACMLAuthzDecisionStatement_s;
struct zx_xac_Response_s;
struct zx_xac_Attribute_s;
struct zx_xasp_XACMLAuthzDecisionQuery_s;
struct zx_xaspcd1_XACMLAuthzDecisionQuery_s;
struct zx_as_SASLRequest_s;
struct zx_di_Query_s;
struct zx_di_QueryResponse_s;
struct zx_im_IdentityMappingRequest_s;
struct zx_im_IdentityMappingResponse_s;
struct zx_ps_AddEntityRequest_s;
struct zx_ps_AddEntityResponse_s;
struct zx_ps_ResolveIdentifierRequest_s;
struct zx_ps_ResolveIdentifierResponse_s;
struct zx_lu_Status_s;
struct zx_wsu_Timestamp_s;
struct zx_wsse_Security_s;
struct zx_wsse_SecurityTokenReference_s;
struct zx_dap_Select_s;
struct zx_dap_QueryItem_s;
struct zx_dap_TestOp_s;
struct zx_dap_TestItem_s;
struct zx_dap_ResultQuery_s;
struct zx_dap_Subscription_s;
struct zx_dap_Query_s;
#endif

#define ZXID_CONF_MAGIC 0x900dc07f
#define ZXID_CGI_MAGIC  0x900d0c91
#define ZXID_SES_MAGIC  0x900d05e5

/*(s) Entity or Provider, as identified by an Entity ID or Provider ID. */

struct zxid_entity {
  struct zxid_entity* n;
  struct zxid_entity* n_cdc;  /* *** not thread safe */
  char* eid;            /* Entity ID. Always nul terminated. */
  char* dpy_name;       /* OrganizationDisplayName. Always nul terminated. */
  char  sha1_name[28];  /* 27 chars (+1 that is overwritten with nul) */
  struct zx_md_EntityDescriptor_s* ed;  /* Metadata */
#ifdef USE_OPENSSL
  X509* tls_cert;
  X509* sign_cert;
  X509* enc_cert;
#endif
};

typedef struct zxid_entity zxid_entity;
typedef struct zx_sa_NameID_s    zxid_nid;
typedef struct zx_sa_Assertion_s zxid_a7n;
typedef struct zx_sec_Token_s    zxid_tok;
typedef struct zx_a_EndpointReference_s zxid_epr; /* Nice name for EPR. May eventually evolve to struct */
typedef struct zx_tas3_Status_s zxid_tas3_status; /* Nice name for TAS3 status */
typedef struct zx_e_Fault_s zxid_fault;           /* Nice name for SOAP faults */
typedef struct zxid_conf   zxid_conf;
typedef struct zxid_cgi    zxid_cgi;
typedef struct zxid_ses    zxid_ses;

/*(s) The zxid_conf structure is passed, as cf argument, to nearly every
 * function in zxid API. It is effectively used as "global" storage
 * for ZXID, facilitating thread safe operation.  In particular, it
 * contains the ZX context that is used for thread safe memory
 * allocation.  However, ZXID itself does not perform any locking
 * around zxid_conf. If you write multithreaded program and your
 * design allows same configuration to be accessed from multiple
 * threads (sometimes you can design your program so that this simply
 * does not happen - each one has its own configuration),
 * then you must perform locking. Often this would
 * mean bracketing every call to zxid API function with lock-unlock.
 *
 * zxid_conf also contains "cache" of the entity's own certificates
 * and private keys. If your program handles multiple entities, you
 * should have one zxid_conf object for each entity.
 *
 * Most of the other fields of zxid_conf are simply configuration
 * options. See <<see: zxidconf.h>> for their documentation. */

struct zxid_conf {
  unsigned int magic;
  struct zx_ctx* ctx;        /* ZX parsing context. Usually used for memory allocation. */
  zxid_entity* cot;   /* Linked list of metadata for CoT partners (in-memory CoT cache) */
  int path_supplied;         /* FLAG: If config variable PATH is supplied, it may trigger reading config file from the supplied location. */
  int path_len;
  char* path;
  char* url;
  char* non_standard_entityid;
  char* redirect_hack_imposed_url;
  char* redirect_hack_zxid_url;
  char* redirect_hack_zxid_qs;
  char* cdc_url;

  char  cdc_choice;
  char  md_fetch;            /* Auto-CoT */
  char  md_populate_cache;
  char  md_cache_first;
  char  md_cache_last;
  char  auto_cert;
  char  idp_ena;
  char  imps_ena;

  char  as_ena;
  char  pdp_ena;
  char  authn_req_sign;
  char  want_authn_req_signed;
  char  want_sso_a7n_signed;
  char  sso_soap_sign;
  char  sso_soap_resp_sign;
  char  sso_sign;            /* Which components should be signed in SSO Response and Assertion */

  char  wsc_sign;            /* Which parts of a web service request to sign */
  char  wsp_sign;            /* Which parts of a web service response to sig */
  char  nameid_enc;          /* Should NameID be encrypted in SLO and MNI requests. */
  char  post_a7n_enc;
  char  di_allow_create;
  char  di_nid_fmt;
  char  di_a7n_enc;
  char  show_conf;

  char  sig_fatal;
  char  nosig_fatal;
  char  msg_sig_ok;
  char  timeout_fatal;
  char  audience_fatal;
  char  dup_a7n_fatal;
  char  dup_msg_fatal;
  char  relto_fatal;

  char  wsp_nosig_fatal;
  char  notimestamp_fatal;
  char  canon_inopt;
  char  enckey_opt;
  char  idpatopt;
  char  idp_list_meth;
  char  pad7;
  char  pad8;
  
  char* affiliation;
  char* nice_name;           /* Human readable "nice" name. Used in AuthnReq->ProviderName */
  char* org_name;
  char* org_url;
  char* locality;            /* Used for CSR locality (L) field. */
  char* state;               /* Used for CSR state (ST) field. */
  char* country;             /* Used for CSR country (C) field. */
  char* contact_org;
  char* contact_name;
  char* contact_email;
  char* contact_tel;
  char* fedusername_suffix;  /* Default is computed from url domain name part when url is set. */
  char* ses_arch_dir;        /* Place where dead sessions go. 0=rm */
  char* ses_cookie_name;
  char* ipport;              /* Source IP and port for logging, e.g: "1.2.3.4:5" */
    
  char* load_cot_cache;
  char* wspcgicmd;
  char* anon_ok;
  char** required_authnctx;  /* Array of acceptable authentication context class refs */
  char* issue_authnctx_pw;   /* What authentication context IdP issues for password authent. */
  char* idp_pref_acs_binding;
  char* mandatory_attr;
  int   before_slop;
  int   after_slop;
  int   timeskew;
  int   a7nttl;
  char* pdp_url;             /* If non-NULL, the inline PEP is enabled and PDP at URL is called. */
  char* pdp_call_url;        /* PDP URL for zxid_az() API */
  char* xasp_vers;
  char* defaultqs;
  char* mod_saml_attr_prefix;  /* Prefix for req variables in mod_auth_saml */

  struct zxid_need*  need;
  struct zxid_need*  want;
  struct zxid_atsrc* attrsrc;
  struct zxid_map*   inmap;
  struct zxid_map*   outmap;
  struct zxid_map*   pepmap;
  struct zxid_map*   pepmap_rqout;
  struct zxid_map*   pepmap_rqin;
  struct zxid_map*   pepmap_rsout;
  struct zxid_map*   pepmap_rsin;

  struct zxid_cstr_list* localpdp_role_permit;
  struct zxid_cstr_list* localpdp_role_deny;
  struct zxid_cstr_list* localpdp_idpnid_permit;
  struct zxid_cstr_list* localpdp_idpnid_deny;

  char* wsc_localpdp_obl_pledge;
  char* wsp_localpdp_obl_req;
  char* wsp_localpdp_obl_emit;
  char* wsc_localpdp_obl_accept;
  
  int   bootstrap_level;     /* How many layers of bootstraps are generated. */
  int   max_soap_retry;      /* How many times a ID-WSF SOAP call can be retried (update EPR) */

  char* idp_sel_start;       /* HTML headers, start of page, side bars */
  char* idp_sel_new_idp;     /* Auto-CoT fields */
  char* idp_sel_our_eid;     /* Our EID advice */
  char* idp_sel_tech_user;   /* Technical options user might choose */
  char* idp_sel_tech_site;   /* Technical options site admin sets (hidden) */
  char* idp_sel_footer;      /* End of page stuff, after form */
  char* idp_sel_end;         /* End of page, after version string */
  char* idp_sel_page;        /* URL for IdP selection Page. */
  char* idp_sel_templ_file;  /* Path to template, e.g. idp-sel.html */
  char* idp_sel_templ;       /* Default template used in case template at path can not be found. */

  char* an_page;         /* URL for Authentication Page. */
  char* an_templ_file;   /* Path to template, e.g. an-main.html */
  char* an_templ;        /* Default template used in case template at path can not be found. */

  char* post_templ_file; /* Path to template, e.g. post.html */
  char* post_templ;      /* Default template used in case template at path can not be found. */

  char* err_page;        /* URL for Error Message Page. */
  char* err_templ_file;  /* Path to template, e.g. err.html */
  char* err_templ;       /* Default template used in case template at path can not be found. */

  char* new_user_page;   /* URL to redirect to for new user creation */
  char* recover_passwd;
  char* atsel_page;

  char* mgmt_start;    /* HTML headers, start of page, side bars */
  char* mgmt_logout;   /* Logout buttons */
  char* mgmt_defed;    /* Defederation buttons */
  char* mgmt_footer;   /* End of page stuff, after form */
  char* mgmt_end;      /* End of page, after version string */

  char* dbg;           /* Debug message that may be shown. */

  char  log_err;             /* Log enables and signing and encryption flags (if USE_OPENSSL) */
  char  log_act;
  char  log_issue_a7n;
  char  log_issue_msg;
  char  log_rely_a7n;
  char  log_rely_msg;
  char  log_err_in_act;      /* Log errors to action log flag (may also log to error log) */
  char  log_act_in_err;      /* Log actions to error log flag (may also log to action log) */
  char  log_sigfail_is_err;  /* Log signature failures to error log */
  char  log_level;           /* act log level: 0=audit, 1=audit+extio, 2=audit+extio+events */
  char  user_local;          /* Whether local user accounts should be maintained. */
  char  redir_to_content;    /* Should explicit redirect to content be used (vs. internal redir) */
  char  remote_user_ena;
  char  show_tech;
  char  bare_url_entityid;
  char  loguser;

#ifdef USE_CURL
  CURL* curl;
#endif
#ifdef USE_PTHREAD
  pthread_mutex_t mx;
  pthread_mutex_t curl_mx;   /* Avoid holding the main lock for duration of HTTP request */
#endif
#ifdef USE_OPENSSL
  RSA*  sign_pkey;
  X509* sign_cert;
  RSA*  enc_pkey;
  X509* enc_cert;

  char  psobj_symkey[20];    /* sha1 hash of key data */
  char  log_symkey[20];      /* sha1 hash of key data */
  RSA*  log_sign_pkey;
  X509* log_enc_cert;
#endif
};

/*(s) Query string, or post, is parsed into the following structure. If a variable
 * is not present, it will be left as NULL. Note that this structure
 * mixes fields from all forms that ZXID might display or process. ZXID ignores
 * any field that is not explicitly foreseen here and in zxidcgi.c, i.e.
 * there is no generic hash structure. */

struct zxid_cgi {
  unsigned int magic;
  char  op;            /* o=  What should be done now. */
  char  pr_ix;         /* i=  Index to protocol profile (typically for login) */
  char  allow_create;  /* fc= Is federation permitted (allow creation of new federation) */
  char  ispassive;     /* fp= Whether IdP is allowed to seize user interface (e.g. ask password) */
  char  force_authn;   /* ff= Whether IdP SHOULD authenticate the user anew. */
  char  enc_hint;      /* Hint: Should NID be encrypted in SLO and MNI, see also cf->nameid_enc */
  char  atselafter;    /* at= Attribute selection requested checkbox. */
  char  pad7;
  char* sid;           /* If session is already active, the session ID. */
  char* nid;           /* NameID of the user. */
  char* uid;           /* au= Form field for user. */
  char* pw;            /* ap= Form field for password. */
  char* ssoreq;        /* ar= Used for conveying original AuthnReq through authn phase. */
  char* cdc;           /* c=  Common Domain Cookie as returned by the CDC reader */
  char* eid;           /* e=, d= Entity ID of an IdP (typically for login) */
  char* nid_fmt;       /* fn= Name ID format */
  char* affil;         /* fq= SP NameQualifier (such as in affiliation of SPs) */
  char* consent;       /* fy= Whether user consented to the operation and how. */
  char* matching_rule; /* fm= How authn_ctx is to be matched by IdP. */
  char* authn_ctx;     /* fa= What kind of authentication the IdP should assert towards SP. */
  char* pxy_count;     /* ProxyCount for triggering IdP proxying */
  char* get_complete;  /* GetComplete URL for IdP proxying */
  char* idppxylist;    /* IDPList for IdP proxying */
  char* rs;            /* RelayState in redirect profile. mod_auth_saml: uri to access after SSO */
  char* newnym;        /* New NameID for MNI/nireg. Empty for federation termination. */
  char* saml_art;      /* SAMLart=... artifact, as in artifact consumer URL. */
  char* saml_resp;     /* SAMLResponse=... in redirect profile */
  char* saml_req;      /* SAMLRequest=... in redirect profile */
  char* sigalg;        /* SigAlg=... in redirect profile */
  char* sig;           /* Signature=... in redirect profile */
  char* sigval;        /* Signature validation code (as logged, VVV in zxid-log.pd, section "Log Line Format") */
  char* sigmsg;        /* Signature validation message */
  char* err;           /* When rendering screens: used to put error message to screen. */
  char* msg;           /* When rendering screens: used to put info message to screen. */
  char* dbg;           /* When rendering screens: used to put debug message to screen. */
  char* zxapp;         /* Deployment specific application parameter passed in some querystrings. */
  char* zxrfr;         /* ZX Referer. Indicates to some external pages why user was redirected. */
  char* ok;            /* Ok button in some forms */
  char* sp_eid;        /* IdP An for to generate page */
  char* sp_dpy_name;
  char* inv;           /* Invitation ID */
  char* action_url;    /* action URL in some forms, such as post.html */
  zxid_entity* idp_list;   /* IdPs from CDC */
};

/*(s) Session is parsed into following structure. */

struct zxid_ses {
  unsigned int magic;
  char* sid;
  char* uid;           /* Local uid (only if local login, like in IdP) */
  char* nid;           /* String representation of Subject NameID. See also nameid. */
  char* tgt;           /* String representation of Target NameID. See also nameid. */
  char* sesix;         /* SessionIndex */
  char* wsc_msgid;     /* Request MessageID, to facilitate Response RelatesTo validation at WSC. */
  char* wsp_msgid;     /* Request MessageID, to facilitate Response RelatesTo generation at WSP. */
  char* an_ctx;        /* Authentication Context (esp in IdP. On SP look inside a7n). */
  char  nidfmt;        /* Subject nameid format: 0=tmp NameID, 1=persistent */
  char  tgtfmt;        /* Target nameid format: 0=tmp NameID, 1=persistent */
  char  sigres;        /* Signature validation code */
  char  ssores;        /* Overall success of SSO 0==OK */
  char* sso_a7n_path;  /* Reference to the SSO assertion (needed for SLO) */
  char* tgt_a7n_path;  /* Reference to target identity assertion */
  char* setcookie;     /* If set, the content rendering should include set-cookie header. */
  char* cookie;        /* Cookie seen by downstream internal requests after SSO. */
  char* rs;            /* RelayState at SSO. mod_auth_saml uses this as URI after SSO. */
  char* rcvd_usagedir; /* Received Usage Directives. Populated by zxid_wsc_validate_resp_env() */
  long an_instant;     /* IdP: Unix seconds when authentication was performed. Used in an_stmt */
  zxid_nid* nameid;    /* From a7n or EncryptedID */
  zxid_nid* tgtnameid; /* From a7n or EncryptedID */
  zxid_a7n* a7n;       /* SAML 2.0 for Subject */
  zxid_a7n* tgta7n;    /* SAML 2.0 for Target */
  struct zx_sa11_Assertion_s* a7n11;
  struct zx_sa11_Assertion_s* tgta7n11;
  struct zx_ff12_Assertion_s* a7n12;
  struct zx_ff12_Assertion_s* tgta7n12;
  zxid_tok* call_invoktok; /* If set, see zxid_map_identity_token(), use as wsse */
  zxid_tok* call_tgttok;   /* If set, use as TargetIdentity token */
  zxid_epr* deleg_di_epr;  /* If set, see zxid_set_delegated_discovery_epr(), used for disco. */
  zxid_fault* curflt;  /* SOAP fault, if any, reported by zxid_wsp_validate() */
  zxid_tas3_status* curstatus;  /* TAS3 status header, if any. */
  char* sesbuf;
  char* sso_a7n_buf;
  struct zxid_attr* at; /* Attributes extracted from a7n and translated using inmap. Linked list */
#ifdef USE_PTHREAD
  pthread_mutex_t mx;
#endif
};

/*(s) Attribute node */

struct zxid_attr {
  struct zxid_attr* n;  /* Next attribute */
  struct zxid_attr* nv; /* Next value, if multivalued */
  char* name;
  char* val;
  struct zx_str* map_val;          /* Value after outmap (cached from length compute to render) */
  struct zx_sa_Attribute_s* orig;  /* Pointer to original attribute, if any */
  struct zx_str* issuer;           /* Issuer EntityID, if any */
};

/*(s) The need nodes are used for storing parsed NEED and WANT directives. */

struct zxid_need {
  struct zxid_need* n;
  struct zxid_attr* at; /* List of needed/wanted attributes (with value fields empty) */
  char* usage;          /* How do we promise to use attribute */
  char* retent;         /* How long will we retain it */
  char* oblig;          /* Obligations we are willing or able to honour */
  char* ext;
};

/*(s) Attribute mapping used in INMAP, PEPMAP, and OUTMAP directives. */

struct zxid_map {
  struct zxid_map* n;
  int   rule;
  char* ns;   /* Namespace of the source attribute */
  char* src;  /* Source attribute */
  char* dst;  /* Destination attribute */
  char* ext;
};

/*(s) Used for maintaining whitelists and blacklists */

struct zxid_cstr_list {
  struct zxid_cstr_list* n;
  char* s;
};

#define ZXID_MAP_RULE_RENAME     0
#define ZXID_MAP_RULE_DEL        1  /* Filter attribute out */
#define ZXID_MAP_RULE_RESET      2  /* Reset the map, dropping previous config. */
#define ZXID_MAP_RULE_FEIDEDEC   3  /* Norway */
#define ZXID_MAP_RULE_FEIDEENC   4  /* Norway */
#define ZXID_MAP_RULE_UNSB64_INF 5  /* Decode safebase64-inflate ([RFC3548], [RFC1951]) */
#define ZXID_MAP_RULE_DEF_SB64   6  /* Encode deflate-safebase64 ([RFC1951], [RFC3548]) */
#define ZXID_MAP_RULE_UNSB64     7  /* NZ: Decode safebase64 ([RFC3548]) */
#define ZXID_MAP_RULE_SB64       8  /* NZ: Encode safebase64 ([RFC3548]) */

/*(s) Attribute source definition */

struct zxid_atsrc {
  struct zxid_atsrc* n;
  struct zxid_attr* at; /* List of available attributes (with value fields empty) */
  char* ns;             /* Namespace, typically Entity ID of the source. */
  char* weight;
  char* url;            /* URL or other access parameters */
  char* aapml;
  char* otherlim;
  char* ext;
};

/*(s) Permission object (for PS and DI) */

struct zxid_perm {
  struct zxid_perm* n;
  struct zx_str* eid;
  struct zx_str* qs;
};

/*(s) People Service Object */

struct zxid_psobj {
  struct zx_str*  psobj;     /* ObjectID */
  char*           uid;       /* uid of the owner of the object */
  struct zx_str*  idpnid;    /* NameID of the buddy */
  struct zx_str*  dispname;
  struct zx_str*  tags;
  struct zx_str*  invids;
  struct zxid_perm* perms;   /* List of permissions associated with the buddy */
  struct zxid_psobj* child; /* In case of colletion, the members of the group, e.g. ObjectRefs. */
  int nodetype;  /* 0=buddy, 1=collection */
  int create_secs;
  int mod_secs;
};

#define ZXID_PSOBJ_BUDDY 0
#define ZXID_PSOBJ_COLLECTION 1

/*(s) Invitation object */

struct zxid_invite {
  struct zx_str*  invid;
  char*           uid;      /* Invitation by */
  struct zx_str*  desc;
  struct zx_str*  psobj;
  struct zx_str*  ps2spredir;
  struct zxid_psobj* obj;
  struct zxid_perm* perms;  /* List of permissions associated with the invitation */
  int maxusage;
  int usage;
  int starts;     /* Unix seconds since epoch */
  int expires;    /* Unix seconds since epoch */
};

#define ZXID_SES_DIR  "ses/"
#define ZXID_USER_DIR "user/"
#define ZXID_UID_DIR  "uid/"
#define ZXID_NID_DIR  "nid/"
#define ZXID_PEM_DIR  "pem/"
#define ZXID_COT_DIR  "cot/"
#define ZXID_DIMD_DIR "dimd/"
#define ZXID_INV_DIR  "inv/"
#define ZXID_MAX_USER (256)  /* Maximum size of .mni or user file */
#define ZXID_INIT_MD_BUF   (8*1024-1)  /* Initial size, will automatically reallocate. */
#define ZXID_INIT_SOAP_BUF (8*1024-1)  /* Initial size, will automatically reallocate. */
#define ZXID_MAX_CURL_BUF  (10*1024*1024-1)  /* Buffer reallocation will not grow beyond this. */
#define ZXID_MAX_EID  (1024)
#define ZXID_MAX_DIR  (4*1024)

/* --------------- zxid_simple() API (see zxidsimp.c) --------------- */

#define ZXID_AUTO_EXIT    0x01 /* Do not call exit(2), return "n" instead */
#define ZXID_AUTO_REDIR   0x02 /* Autoredirs, assume CGI, calls exit(2) */
#define ZXID_AUTO_SOAPC   0x04 /* SOAP resp content */
#define ZXID_AUTO_SOAPH   0x08 /* SOAP resp headers */
#define ZXID_AUTO_METAC   0x10 /* metadata content */
#define ZXID_AUTO_METAH   0x20 /* metadata headers*/
#define ZXID_AUTO_LOGINC  0x40 /* login page content */
#define ZXID_AUTO_LOGINH  0x80 /* login page headers */
#define ZXID_AUTO_MGMTC  0x100 /* mgmt page content */
#define ZXID_AUTO_MGMTH  0x200 /* mgmt page headers */
#define ZXID_AUTO_FORMF  0x400 /* Wrap the output in <form> tag. Full page HTML. */
#define ZXID_AUTO_FORMT  0x800 /* Wrap the output in <form> tag. */
#define ZXID_AUTO_ALL    0xfff /* Enable all automatic behaviour. (4095) */
#define ZXID_AUTO_DEBUG 0x1000 /* Enable debugging output to stderr. */
#define ZXID_AUTO_FMTQ  0x2000 /* Output Format Query String */
#define ZXID_AUTO_FMTJ  0x4000 /* Output Format JSON */

ZXID_DECL char* zxid_simple(char* conf, char* qs, int auto_flags);
ZXID_DECL char* zxid_idp_list(char* conf, int auto_flags);
ZXID_DECL char* zxid_idp_select(char* conf, int auto_flags);
ZXID_DECL char* zxid_fed_mgmt(char* conf, char* sid, int auto_flags);

ZXID_DECL zxid_conf* zxid_new_conf_to_cf(const char* conf);
ZXID_DECL char* zxid_simple_cf(zxid_conf* cf, int qs_len, char* qs, int* res_len, int auto_flags);
ZXID_DECL char* zxid_idp_list_cf(zxid_conf* cf, int* res_len, int auto_flags);
ZXID_DECL char* zxid_idp_select_cf(zxid_conf* cf, int* res_len, int auto_flags);
ZXID_DECL char* zxid_fed_mgmt_cf(zxid_conf* cf, int* res_len, int sid_len, char* sid, int auto_flags);

ZXID_DECL int zxid_conf_to_cf_len(zxid_conf* cf, int conf_len, const char* conf);
ZXID_DECL char* zxid_simple_len(int conf_len, char* conf, int qs_len, char* qs, int* res_len, int auto_flags);
ZXID_DECL char* zxid_simple_show_idp_sel(zxid_conf* cf, zxid_cgi* cgi, int* res_len, int auto_flags);
ZXID_DECL char* zxid_idp_list_len(int conf_len, char* conf, int* res_len, int auto_flags);
ZXID_DECL char* zxid_idp_list_cf_cgi(zxid_conf* cf, zxid_cgi* cgi, int* res_len, int auto_flags);
ZXID_DECL char* zxid_idp_select_len(int conf_len, char* conf, int* res_len, int auto_flags);
ZXID_DECL char* zxid_fed_mgmt_len(int conf_len, char* conf, int* res_len, char* sid, int auto_flags);
ZXID_DECL struct zx_str* zxid_idp_select_zxstr_cf(zxid_conf* cf, int auto_flags);

ZXID_DECL char* zxid_simple_show_err(zxid_conf* cf, zxid_cgi* cgi, int* res_len, int auto_flags);

ZXID_DECL char* zxid_simple_ses_active_cf(zxid_conf* cf, zxid_cgi* cgi, zxid_ses* ses, int* res_len, int auto_flags);
ZXID_DECL char* zxid_simple_no_ses_cf(zxid_conf* cf, zxid_cgi* cgi, zxid_ses* ses, int* res_len, int auto_flags);
ZXID_DECL char* zxid_simple_cf_ses(zxid_conf* cf, int qs_len, char* qs, zxid_ses* ses, int* res_len, int auto_flags);
ZXID_DECL struct zx_str* zxid_template_page_cf(zxid_conf* cf, zxid_cgi* cgi, const char* templ_path, const char* default_templ, int size_hint, int auto_flags);

/* --------------- Full API --------------- */

/* Signatures */

#define ZXID_SSO_SIGN_A7N  0x01
#define ZXID_SSO_SIGN_RESP 0x02
#define ZXID_SSO_SIGN_A7N_SIMPLE  0x04  /* N.B. Usually not as Simple Sig message sig is enough. */

#define ZXID_SIGN_HDR  0x01  /* Sign ID-WSF relevant SOAP Headers */
#define ZXID_SIGN_BDY  0x02  /* Sign SOAP Body */

struct zxsig_ref {
  struct zx_ds_Reference_s* sref;  /* Reference for validation */
  struct zx_elem_s* blob;          /* XML data structure for validation */
  struct zx_str* id;               /* ID attribute of element to sign */
  struct zx_str* canon;            /* String representing canonicalization for signing */
  struct zx_ns_s* pop_seen;        /* Namespaces from outer layers for inc_ns processing */
};

#define ZXSIG_OK         0
#define ZXSIG_BAD_DALGO  1  /* A Unsupported digest algorithm. */
#define ZXSIG_DIGEST_LEN 2  /* G Wrong digest length. */
#define ZXSIG_BAD_DIGEST 3  /* G Digest value does not match. */
#define ZXSIG_BAD_SALGO  4  /* A Unsupported signature algorithm. */
#define ZXSIG_BAD_CERT   5  /* I Extraction of public key from certificate failed. */
#define ZXSIG_VFY_FAIL   6  /* R Verification of signature failed. */
#define ZXSIG_NO_SIG     7  /* N No signature found. */
#define ZXSIG_TIMEOUT    8  /* V Validity time has expired. */
#define ZXSIG_AUDIENCE   9  /* V Assertion has wrong audience. */

#ifdef USE_OPENSSL
ZXID_DECL struct zx_ds_Signature_s* zxsig_sign(struct zx_ctx* c, int n, struct zxsig_ref* sref, X509* cert, RSA* priv_key);
ZXID_DECL int zxsig_validate(struct zx_ctx* c, X509* cert, struct zx_ds_Signature_s* sig, int n, struct zxsig_ref* refs);
ZXID_DECL int zxsig_data_rsa_sha1(struct zx_ctx* c, int len, const char* d, char** sig, RSA* priv_key, const char* lk);
ZXID_DECL int zxsig_verify_data_rsa_sha1(int len, char* data, int siglen, char* sig, X509* cert, char* lk);
ZXID_DECL struct zx_xenc_EncryptedData_s* zxenc_pubkey_enc(zxid_conf* cf, struct zx_str* data, struct zx_xenc_EncryptedKey_s** ekp, X509* cert, char* idsuffix, zxid_entity* meta);
#endif
ZXID_DECL struct zx_str* zxenc_privkey_dec(zxid_conf* cf, struct zx_xenc_EncryptedData_s* ed, struct zx_xenc_EncryptedKey_s* ek);
ZXID_DECL struct zx_xenc_EncryptedData_s* zxenc_symkey_enc(zxid_conf* cf, struct zx_str* data, struct zx_str* ed_id, struct zx_str* symkey, struct zx_xenc_EncryptedKey_s* ek);
ZXID_DECL struct zx_str* zxenc_symkey_dec(zxid_conf* cf, struct zx_xenc_EncryptedData_s* ed, struct zx_str* symkey);

/* zxlog (see logging chapter in README.zxid) */

/*  /var/zxid/log/rely/ISSUER-SHA1-NAME/a7n/A7N-ID-AS-SHA1 */
#define ZXLOG_RELY_DIR  "rely/"
#define ZXLOG_ISSUE_DIR "issue/"
#define ZXLOG_A7N_KIND  "/a7n/"
#define ZXLOG_MSG_KIND  "/msg/"
#define ZXLOG_WIR_KIND  "/wir/"

ZXID_DECL void zxlog_write_line(zxid_conf* cf, char* c_path, int encflags, int n, const char* logbuf);
ZXID_DECL struct zx_str* zxlog_path(zxid_conf* cf, struct zx_str* entid, struct zx_str* objid, const char* dir, const char* kind, int create_dirs);
ZXID_DECL int zxlog_dup_check(zxid_conf* cf, struct zx_str* path, const char* logkey);
ZXID_DECL int zxlog_blob(zxid_conf* cf, int logflag, struct zx_str* path, struct zx_str* blob, const char* lk);
ZXID_DECL int zxlog(zxid_conf* cf, struct timeval* ourts, struct timeval* srcts, const char* ipport, struct zx_str* entid, struct zx_str* msgid, struct zx_str* a7nid, struct zx_str* nid, const char* sigval, const char* res, const char* op, const char* arg, const char* fmt, ...);
ZXID_DECL int zxlogusr(zxid_conf* cf, const char* uid, struct timeval* ourts, struct timeval* srcts, const char* ipport, struct zx_str* entid, struct zx_str* msgid, struct zx_str* a7nid, struct zx_str* nid, const char* sigval, const char* res, const char* op, const char* arg, const char* fmt, ...);

/* zxidmeta */

ZXID_DECL zxid_entity* zxid_get_ent_file(zxid_conf* cf, char* sha1_name);
ZXID_DECL zxid_entity* zxid_get_ent_cache(zxid_conf* cf, struct zx_str* eid);
ZXID_DECL int zxid_write_ent_to_cache(zxid_conf* cf, zxid_entity* ent);
ZXID_DECL zxid_entity* zxid_parse_meta(zxid_conf* cf, char** md, char* lim);
ZXID_DECL zxid_entity* zxid_get_meta_ss(zxid_conf* cf, struct zx_str* url);
ZXID_DECL zxid_entity* zxid_get_meta(zxid_conf* cf, const char* url);
ZXID_DECL zxid_entity* zxid_get_ent_ss(zxid_conf* cf, struct zx_str* eid);
ZXID_DECL zxid_entity* zxid_get_ent(zxid_conf* cf, char* eid);
ZXID_DECL zxid_entity* zxid_get_ent_by_succinct_id(zxid_conf* cf, char* raw_succinct_id);
ZXID_DECL zxid_entity* zxid_get_ent_by_sha1_name(zxid_conf* cf, char* sha1_name);
ZXID_DECL zxid_entity* zxid_load_cot_cache(zxid_conf* cf);

#ifdef USE_OPENSSL
ZXID_DECL struct zx_ds_KeyInfo_s* zxid_key_info(zxid_conf* cf, struct zx_elem_s* father, X509* x);
ZXID_DECL struct zx_md_KeyDescriptor_s* zxid_key_desc(zxid_conf* cf, struct zx_elem_s* father, char* use, X509* cert);
#endif
ZXID_DECL struct zx_md_ArtifactResolutionService_s* zxid_ar_desc(zxid_conf* cf, struct zx_elem_s* father, char* binding, char* loc, char* resp_loc);
ZXID_DECL struct zx_md_SingleSignOnService_s* zxid_sso_desc(zxid_conf* cf, struct zx_elem_s* father, char* binding, char* loc, char* resp_loc);
ZXID_DECL struct zx_md_SingleLogoutService_s* zxid_slo_desc(zxid_conf* cf, struct zx_elem_s* father, char* binding, char* loc, char* resp_loc);
ZXID_DECL struct zx_md_ManageNameIDService_s* zxid_mni_desc(zxid_conf* cf, struct zx_elem_s* father, char* binding, char* loc, char* resp_loc);
ZXID_DECL struct zx_md_AssertionConsumerService_s* zxid_ac_desc(zxid_conf* cf, struct zx_elem_s* father, char* binding, char* loc, char* index);
ZXID_DECL struct zx_md_IDPSSODescriptor_s* zxid_idp_sso_desc(zxid_conf* cf, struct zx_elem_s* father);
ZXID_DECL struct zx_md_SPSSODescriptor_s* zxid_sp_sso_desc(zxid_conf* cf, struct zx_elem_s* father);
ZXID_DECL struct zx_str* zxid_sp_meta(zxid_conf* cf, zxid_cgi* cgi);
ZXID_DECL int zxid_send_sp_meta(zxid_conf* cf, zxid_cgi* cgi);
ZXID_DECL struct zx_str* zxid_sp_carml(zxid_conf* cf);
ZXID_DECL struct zx_str* zxid_my_entity_id(zxid_conf* cf);
ZXID_DECL struct zx_attr_s* zxid_my_entity_id_attr(zxid_conf* cf, struct zx_elem_s* father, int tok);
ZXID_DECL struct zx_str* zxid_my_cdc_url(zxid_conf* cf);
ZXID_DECL struct zx_sa_Issuer_s* zxid_my_issuer(zxid_conf* cf, struct zx_elem_s* father);
ZXID_DECL struct zx_sa_Issuer_s* zxid_issuer(zxid_conf* cf, struct zx_elem_s* father, struct zx_str* nameid, char* affiliation);

/* zxidconf */

#ifdef USE_OPENSSL
ZXID_DECL X509* zxid_extract_cert(char* buf, char* name);
ZXID_DECL RSA*  zxid_extract_private_key(char* buf, char* name);
ZXID_DECL X509* zxid_read_cert(zxid_conf* cf, char* name);
ZXID_DECL RSA*  zxid_read_private_key(zxid_conf* cf, char* name);
ZXID_DECL int zxid_lazy_load_sign_cert_and_pkey(zxid_conf* cf, X509** cert, RSA** pkey, const char* logkey);
#endif
ZXID_DECL int   zxid_set_opt(zxid_conf* cf, int which, int val);
ZXID_DECL char* zxid_set_opt_cstr(zxid_conf* cf, int which, char* val);
ZXID_DECL void  zxid_url_set(zxid_conf* cf, char* url);
ZXID_DECL int   zxid_init_conf(zxid_conf* cf, const char* conf_dir);
ZXID_DECL zxid_conf* zxid_init_conf_ctx(zxid_conf* cf, const char* zxid_path);
ZXID_DECL zxid_conf* zxid_new_conf(const char* zxid_path);
ZXID_DECL int   zxid_parse_conf_raw(zxid_conf* cf, int qs_len, char* qs);
ZXID_DECL int   zxid_parse_conf(zxid_conf* cf, char* qs);
ZXID_DECL int   zxid_mk_self_sig_cert(zxid_conf* cf, int buflen, char* buf, char* lk, char* name);
ZXID_DECL struct zxid_map*   zxid_load_map(zxid_conf* cf, struct zxid_map* map, char* v);
ZXID_DECL struct zxid_need*  zxid_load_need(zxid_conf* cf, struct zxid_need* need, char* v);
ZXID_DECL struct zxid_atsrc* zxid_load_atsrc(zxid_conf* cf, struct zxid_atsrc* atsrc, char* v);
ZXID_DECL struct zxid_attr*  zxid_new_at(zxid_conf* cf, struct zxid_attr* at, int name_len, char* name, int val_len, char* val, char* lk);
ZXID_DECL struct zxid_cstr_list* zxid_load_cstr_list(zxid_conf* cf, struct zxid_cstr_list* lst, char* v);
ZXID_DECL struct zxid_need*  zxid_is_needed(struct zxid_need* need, char* name);
ZXID_DECL struct zxid_map*   zxid_find_map(struct zxid_map* map, char* name);
ZXID_DECL struct zxid_cstr_list* zxid_find_cstr_list(struct zxid_cstr_list* lst, char* name);
ZXID_DECL struct zxid_attr* zxid_find_at(struct zxid_attr* pool, char* name);
ZXID_DECL struct zx_str* zxid_show_conf(zxid_conf* cf);

/* zxidcgi */

ZXID_DECL int zxid_parse_cgi(zxid_cgi* cgi, char* qs);
ZXID_DECL zxid_cgi* zxid_new_cgi(zxid_conf* cf, char* qs);
ZXID_DECL void zxid_get_sid_from_cookie(zxid_conf* cf, zxid_cgi* cgi, const char* cookie);

/* zxidses */

ZXID_DECL zxid_ses* zxid_alloc_ses(zxid_conf* cf);
ZXID_DECL zxid_ses* zxid_fetch_ses(zxid_conf* cf, const char* sid);
ZXID_DECL int zxid_get_ses(zxid_conf* cf, zxid_ses* ses, const char* sid);
ZXID_DECL int zxid_put_ses(zxid_conf* cf, zxid_ses* ses);
ZXID_DECL int zxid_del_ses(zxid_conf* cf, zxid_ses* ses);
ZXID_DECL int zxid_get_ses_sso_a7n(zxid_conf* cf, zxid_ses* ses);
ZXID_DECL zxid_entity* zxid_get_ses_idp(zxid_conf* cf, zxid_ses* ses);
ZXID_DECL int zxid_find_ses(zxid_conf* cf, zxid_ses* ses, struct zx_str* ses_ix, struct zx_str* nid);

/* zxidpool */

//ZXID_DECL struct zx_str* zxid_ses_to_ldif(zxid_conf* cf, zxid_ses* ses);
ZXID_DECL struct zx_str* zxid_ses_to_ldif(zxid_conf* cf, zxid_ses* ses);
ZXID_DECL struct zx_str* zxid_ses_to_json(zxid_conf* cf, zxid_ses* ses);
ZXID_DECL struct zx_str* zxid_ses_to_qs(zxid_conf* cf, zxid_ses* ses);
ZXID_DECL void zxid_ses_to_pool(zxid_conf* cf, zxid_ses* ses);
ZXID_DECL void zxid_add_attr_to_ses(zxid_conf* cf, zxid_ses* ses, char* at_name, struct zx_str* val);
ZXID_DECL int zxid_add_qs_to_ses(zxid_conf* cf, zxid_ses* ses, char* qs, int apply_map);

/* zxiduser */

ZXID_DECL zxid_nid* zxid_parse_mni(zxid_conf* cf, char* buf, char** pmniptr);
ZXID_DECL void zxid_user_sha1_name(zxid_conf* cf, struct zx_str* qualif, struct zx_str* nid, char* sha1_name);
ZXID_DECL int zxid_put_user(zxid_conf* cf, struct zx_str* nidfmt, struct zx_str* idpent, struct zx_str* spqual, struct zx_str* idpnid, char* mniptr);
ZXID_DECL zxid_nid* zxid_get_user_nameid(zxid_conf* cf, zxid_nid* oldnid);
ZXID_DECL void zxid_user_change_nameid(zxid_conf* cf, zxid_nid* oldnid, struct zx_str* newnym);
ZXID_DECL int zxid_pw_authn(zxid_conf* cf, zxid_cgi* cgi, zxid_ses* ses);

/* zxidlib */

ZXID_DECL int   zxid_version();
ZXID_DECL char* zxid_version_str();

ZXID_DECL struct zx_str* zxid_date_time(zxid_conf* cf, time_t secs);
ZXID_DECL struct zx_str* zxid_mk_id(zxid_conf* cf, char* prefix, int bits); /* pseudo random ident. */

ZXID_DECL struct zx_attr_s* zxid_date_time_attr(zxid_conf* cf, struct zx_elem_s* father, int tok, time_t secs);
ZXID_DECL struct zx_attr_s* zxid_mk_id_attr(zxid_conf* cf, struct zx_elem_s* father, int tok, char* prefix, int bits);

ZXID_DECL struct zx_str* zxid_http_post_raw(zxid_conf* cf, int url_len, const char* url, int len, const char* data);
ZXID_DECL struct zx_root_s* zxid_soap_call_raw(zxid_conf* cf, struct zx_str* url, struct zx_str* data, char** ret_enve);
ZXID_DECL struct zx_str* zxid_lecp_check(zxid_conf* cf, zxid_cgi* cgi);
ZXID_DECL int zxid_cdc_read(zxid_conf* cf, zxid_cgi* cgi);
ZXID_DECL int zxid_cdc_check(zxid_conf* cf, zxid_cgi* cgi);
ZXID_DECL struct zx_root_s* zxid_soap_call_envelope(zxid_conf* cf, struct zx_str* url, struct zx_e_Envelope_s* env, char** ret_enve);
ZXID_DECL struct zx_root_s* zxid_soap_call_hdr_body(zxid_conf* cf, struct zx_str* url, struct zx_e_Header_s* hdr, struct zx_e_Body_s* body);
ZXID_DECL struct zx_root_s* zxid_soap_call_body(zxid_conf* cf, struct zx_str* url, struct zx_e_Body_s* body);
ZXID_DECL int zxid_soap_cgi_resp_body(zxid_conf* cf, struct zx_e_Body_s* body, struct zx_str* entid);

ZXID_DECL struct zx_str* zxid_saml2_post_enc(zxid_conf* cf, char* field, struct zx_str* payload, char* relay_state, int sign, struct zx_str* action_url);
ZXID_DECL struct zx_str* zxid_saml2_redir_enc(zxid_conf* cf, char* cgivar, struct zx_str* pay_load, char* relay_state);
ZXID_DECL struct zx_str* zxid_saml2_redir_url(zxid_conf* cf, struct zx_str* loc, struct zx_str* pay_load, char* relay_state);
ZXID_DECL struct zx_str* zxid_saml2_redir(zxid_conf* cf, struct zx_str* loc, struct zx_str* pay_load, char* relay_state);
ZXID_DECL struct zx_str* zxid_saml2_resp_redir(zxid_conf* cf, struct zx_str* loc, struct zx_str* pay_load, char* relay_state);

ZXID_DECL int zxid_saml_ok(zxid_conf* cf, zxid_cgi* cgi, struct zx_sp_Status_s* st, char* what);
ZXID_DECL zxid_nid* zxid_decrypt_nameid(zxid_conf* cf, zxid_nid* nid, struct zx_sa_EncryptedID_s* encid);
ZXID_DECL struct zx_str* zxid_decrypt_newnym(zxid_conf* cf, struct zx_str* newnym, struct zx_sp_NewEncryptedID_s* encid);

ZXID_DECL int zxid_chk_sig(zxid_conf* cf, zxid_cgi* cgi, zxid_ses* ses, struct zx_elem_s* elem, struct zx_ds_Signature_s* sig, struct zx_sa_Issuer_s* issue_ent, struct zx_ns_s* pop_seen, const char* lk);

ZXID_DECL struct zx_str* zxid_map_val(zxid_conf* cf, struct zxid_map* map, struct zx_str* val);
ZXID_DECL char* zxid_extract_body(zxid_conf* cf, char* enve);

ZXID_DECL char* zx_get_symkey(zxid_conf* cf, const char* keyname, char* symkey);

/* zxidloc */

ZXID_DECL struct zx_str* zxid_idp_loc_raw(zxid_conf* cf, zxid_cgi* cgi, zxid_entity* idp_meta, int svc_type, char* binding, int req);
ZXID_DECL struct zx_str* zxid_idp_loc(zxid_conf* cf, zxid_cgi* cgi, zxid_ses* ses, zxid_entity* idp_meta, int svc_type, char* binding);
ZXID_DECL struct zx_root_s* zxid_idp_soap(zxid_conf* cf, zxid_cgi* cgi, zxid_ses* ses, zxid_entity* idp_meta, int svc_type, struct zx_e_Body_s* body);

ZXID_DECL struct zx_str* zxid_sp_loc_by_index_raw(zxid_conf* cf, zxid_cgi* cgi, zxid_entity* sp_meta, int svc_type,struct zx_str* ix, int* binding);
ZXID_DECL struct zx_str* zxid_sp_loc_raw(zxid_conf* cf, zxid_cgi* cgi, zxid_entity* sp_meta, int svc_type, char* binding, int req);
ZXID_DECL struct zx_str* zxid_sp_loc(zxid_conf* cf, zxid_cgi* cgi, zxid_ses* ses, zxid_entity* sp_meta, int svc_type, char* binding);
ZXID_DECL struct zx_root_s* zxid_sp_soap(zxid_conf* cf, zxid_cgi* cgi, zxid_ses* ses, zxid_entity* sp_meta, int svc_type, struct zx_e_Body_s* body);

/* zxiddec */

ZXID_DECL struct zx_sa_Issuer_s* zxid_extract_issuer(zxid_conf* cf, zxid_cgi* cgi, zxid_ses* ses, struct zx_root_s* r);
ZXID_DECL struct zx_root_s* zxid_decode_redir_or_post(zxid_conf* cf, zxid_cgi* cgi, zxid_ses* ses, int chk_dup);

/* zxidspx */

ZXID_DECL struct zx_str* zxid_sp_dispatch(zxid_conf* cf, zxid_cgi* cgi, zxid_ses* ses);
ZXID_DECL int zxid_sp_soap_dispatch(zxid_conf* cf, zxid_cgi* cgi, zxid_ses* ses, struct zx_root_s* r);
ZXID_DECL int zxid_sp_soap_parse(zxid_conf* cf, zxid_cgi* cgi, zxid_ses* ses, int len, char* buf);
ZXID_DECL zxid_a7n* zxid_dec_a7n(zxid_conf* cf, zxid_a7n* a7n, struct zx_sa_EncryptedAssertion_s* enca7n);

/* zxididpx */

ZXID_DECL struct zx_str* zxid_idp_dispatch(zxid_conf* cf, zxid_cgi* cgi, zxid_ses* ses, int chk_dup);

/* zxidpsso - IdP side of SSO: generating A7N */

ZXID_DECL void zxid_mk_transient_nid(zxid_conf* cf, zxid_nid* nameid, const char* sp_name_buf, const char* uid);
ZXID_DECL int zxid_anoint_a7n(zxid_conf* cf, int sign, zxid_a7n* a7n, struct zx_str* issued_to, const char* lk, const char* uid);
ZXID_DECL struct zx_str* zxid_anoint_sso_resp(zxid_conf* cf, int sign, struct zx_sp_Response_s* resp, struct zx_sp_AuthnRequest_s* ar);
ZXID_DECL zxid_a7n* zxid_sso_issue_a7n(zxid_conf* cf, zxid_cgi* cgi, zxid_ses* ses, struct timeval* srcts, zxid_entity* sp_meta, struct zx_str* acsurl, zxid_nid** nameid, char** logop, struct zx_sp_AuthnRequest_s* ar);
ZXID_DECL void zxid_add_ldif_attrs(zxid_conf* cf, struct zx_elem_s* father, char* p, char* lk);
ZXID_DECL void zxid_gen_boots(zxid_conf* cf, struct zx_sa_AttributeStatement_s* father, const char* uid, char* path, int add_bs_lvl);
ZXID_DECL zxid_a7n* zxid_mk_user_a7n_to_sp(zxid_conf* cf, zxid_ses* ses, const char* uid, zxid_nid* nameid, zxid_entity* sp_meta, const char* sp_name_buf, int add_bs_lvl);
ZXID_DECL zxid_nid* zxid_check_fed(zxid_conf* cf, struct zx_str* affil, const char* uid, char allow_create, struct timeval* srcts, struct zx_str* issuer, struct zx_str* req_id, const char* sp_name_buf);
ZXID_DECL char* zxid_add_fed_tok2epr(zxid_conf* cf, zxid_epr* epr, const char* uid,int add_bs_lvl);
ZXID_DECL struct zx_str* zxid_idp_sso(zxid_conf* cf, zxid_cgi* cgi, zxid_ses* ses, struct zx_sp_AuthnRequest_s* ar);
ZXID_DECL struct zx_as_SASLResponse_s* zxid_idp_as_do(zxid_conf* cf, struct zx_as_SASLRequest_s* req);

/* zxidsso - SP side of SSO: consuming A7N */

ZXID_DECL int zxid_pick_sso_profile(zxid_conf* cf, zxid_cgi* cgi, zxid_entity* idp_met);
ZXID_DECL int zxid_start_sso(zxid_conf* cf, zxid_cgi* cgi);
ZXID_DECL struct zx_str* zxid_start_sso_url(zxid_conf* cf, zxid_cgi* cgi);
ZXID_DECL struct zx_str* zxid_start_sso_location(zxid_conf* cf, zxid_cgi* cgi);
ZXID_DECL int zxid_sp_deref_art(zxid_conf* cf, zxid_cgi* cgi, zxid_ses* ses);
ZXID_DECL int zxid_sp_sso_finalize(zxid_conf* cf, zxid_cgi* cgi, zxid_ses* ses, zxid_a7n* a7n, struct zx_ns_s* pop_seen);
ZXID_DECL int zxid_sp_anon_finalize(zxid_conf* cf, zxid_cgi* cgi, zxid_ses* ses);

ZXID_DECL const char* zxid_saml2_map_nid_fmt(const char* f);
ZXID_DECL const char* zxid_saml2_map_protocol_binding(const char* b);
ZXID_DECL int zxid_protocol_binding_map_saml2(struct zx_str* b);
ZXID_DECL char* zxid_saml2_map_authn_ctx(char* c);

ZXID_DECL void zxid_sigres_map(int sigres, char** sigval, char** sigmsg);
ZXID_DECL int zxid_validate_cond(zxid_conf* cf, zxid_cgi* cgi, zxid_ses* ses, zxid_a7n* a7n, struct zx_str* myentid, struct timeval* ourts, char** err);

ZXID_DECL int zxid_as_call_ses(zxid_conf* cf, zxid_entity* idp_meta, zxid_cgi* cgi, zxid_ses* ses);
ZXID_DECL zxid_ses* zxid_as_call(zxid_conf* cf, zxid_entity* idp_meta, const char* user, const char* pw);

/* zxidslo */

ZXID_DECL int zxid_sp_slo_soap(zxid_conf* cf, zxid_cgi* cgi, zxid_ses* ses);
ZXID_DECL struct zx_str* zxid_sp_slo_redir(zxid_conf* cf, zxid_cgi* cgi, zxid_ses* ses);
ZXID_DECL int zxid_sp_slo_do(zxid_conf* cf, zxid_cgi* cgi, zxid_ses* ses, struct zx_sp_LogoutRequest_s* req);
ZXID_DECL int zxid_idp_slo_do(zxid_conf* cf, zxid_cgi* cgi, zxid_ses* ses, struct zx_sp_LogoutRequest_s* req);
ZXID_DECL struct zx_str* zxid_slo_resp_redir(zxid_conf* cf, zxid_cgi* cgi, struct zx_sp_LogoutRequest_s* req);

/* zxidmni */

ZXID_DECL int zxid_sp_mni_soap(zxid_conf* cf, zxid_cgi* cgi, zxid_ses* ses, struct zx_str* new_nym);
ZXID_DECL struct zx_str* zxid_sp_mni_redir(zxid_conf* cf, zxid_cgi* cgi, zxid_ses* ses, struct zx_str* new_nym);

ZXID_DECL struct zx_sp_ManageNameIDResponse_s* zxid_mni_do(zxid_conf* cf, zxid_cgi* cgi, zxid_ses* ses, struct zx_sp_ManageNameIDRequest_s* mni);
ZXID_DECL struct zx_str* zxid_mni_do_ss(zxid_conf* cf, zxid_cgi* cgi, zxid_ses* ses, struct zx_sp_ManageNameIDRequest_s* mni, struct zx_str* loc);

/* zxidpep */

ZXID_DECL char* zxid_pep_az_soap_pepmap(zxid_conf* cf, zxid_cgi* cgi, zxid_ses* ses, const char* pdp_url, struct zxid_map* pepmap);
ZXID_DECL char* zxid_pep_az_soap(zxid_conf* cf, zxid_cgi* cgi, zxid_ses* ses, const char* pdp_url);
ZXID_DECL char* zxid_az_cf_ses(zxid_conf* cf, const char* qs, zxid_ses* ses);
ZXID_DECL char* zxid_az_cf(zxid_conf* cf, const char* qs, const char* sid);
ZXID_DECL char* zxid_az(const char* conf, const char* qs, const char* sid);

ZXID_DECL char* zxid_pep_az_base_soap_pepmap(zxid_conf* cf, zxid_cgi* cgi, zxid_ses* ses, const char* pdp_url, struct zxid_map* pepmap);
ZXID_DECL char* zxid_pep_az_base_soap(zxid_conf* cf, zxid_cgi* cgi, zxid_ses* ses, const char* pdp_url);
ZXID_DECL char* zxid_az_base_cf_ses(zxid_conf* cf, const char* qs, zxid_ses* ses);
ZXID_DECL char* zxid_az_base_cf(zxid_conf* cf, const char* qs, const char* sid);
ZXID_DECL char* zxid_az_base(const char* conf, const char* qs, const char* sid);

/* zxidpdp */

ZXID_DECL int zxid_localpdp(zxid_conf* cf, zxid_ses* ses);
ZXID_DECL char* zxid_simple_ab_pep(zxid_conf* cf, zxid_ses* ses, int* res_len, int auto_flags);

/* zxida7n */

ZXID_DECL struct zx_sa_Attribute_s* zxid_find_attribute(zxid_a7n* a7n, int nfmt_len, char* nfmt, int name_len, char* name, int friendly_len, char* friendly, int n);

/* zxidmk */

ZXID_DECL struct zx_sp_AuthnRequest_s* zxid_mk_authn_req(zxid_conf* cf, zxid_cgi* cgi);
ZXID_DECL struct zx_sp_ArtifactResolve_s* zxid_mk_art_deref(zxid_conf* cf, zxid_entity* idp_meta, char* artifact);

ZXID_DECL struct zx_sp_Status_s* zxid_mk_Status(zxid_conf* cf, struct zx_elem_s* father, char* sc1, char* sc2, char* msg);
ZXID_DECL struct zx_sp_Status_s* zxid_OK(zxid_conf* cf, struct zx_elem_s* father);
ZXID_DECL struct zx_sa_EncryptedID_s* zxid_mk_enc_id(zxid_conf* cf, struct zx_elem_s* father, zxid_nid* nid, zxid_entity* meta);
ZXID_DECL struct zx_sa_EncryptedAssertion_s* zxid_mk_enc_a7n(zxid_conf* cf, struct zx_elem_s* father, zxid_a7n* a7n, zxid_entity* meta);

ZXID_DECL struct zx_sp_LogoutRequest_s* zxid_mk_logout(zxid_conf* cf, zxid_nid* nid, struct zx_str* ses_ix, zxid_entity* idp);
ZXID_DECL struct zx_sp_LogoutResponse_s* zxid_mk_logout_resp(zxid_conf* cf, struct zx_sp_Status_s* st, struct zx_str* req_id);
ZXID_DECL struct zx_sp_ManageNameIDRequest_s* zxid_mk_mni(zxid_conf* cf, zxid_nid* nid, struct zx_str* new_nym, zxid_entity* idp);
ZXID_DECL struct zx_sp_ManageNameIDResponse_s* zxid_mk_mni_resp(zxid_conf* cf, struct zx_sp_Status_s* st, struct zx_str* req_id);

ZXID_DECL zxid_a7n* zxid_mk_a7n(zxid_conf* cf, struct zx_str* audience, struct zx_sa_Subject_s* subj, struct zx_sa_AuthnStatement_s* an_stmt, struct zx_sa_AttributeStatement_s* at_stmt);
ZXID_DECL struct zx_sa_Subject_s* zxid_mk_subj(zxid_conf* cf, struct zx_elem_s* father, zxid_entity* sp_meta, zxid_nid* nid);
ZXID_DECL struct zx_sa_AuthnStatement_s* zxid_mk_an_stmt(zxid_conf* cf, zxid_ses* ses, struct zx_elem_s* father, const char* eid);
ZXID_DECL struct zx_sp_Response_s* zxid_mk_saml_resp(zxid_conf* cf, zxid_a7n* a7n, zxid_entity* enc_meta);
ZXID_DECL struct zx_xac_Response_s* zxid_mk_xacml_resp(zxid_conf* cf, char* decision);
ZXID_DECL struct zx_xac_Attribute_s* zxid_mk_xacml_simple_at(zxid_conf* cf, struct zx_elem_s* father, struct zx_str* atid, struct zx_str* attype, struct zx_str* atissuer, struct zx_str* atvalue);
ZXID_DECL struct zx_xac_Request_s* zxid_mk_xac_az(zxid_conf* cf, struct zx_elem_s* father, struct zx_xac_Attribute_s* subj, struct zx_xac_Attribute_s* rsrc, struct zx_xac_Attribute_s* act, struct zx_xac_Attribute_s* env);
ZXID_DECL struct zx_xasp_XACMLAuthzDecisionQuery_s* zxid_mk_az(zxid_conf* cf, struct zx_xac_Attribute_s* subj, struct zx_xac_Attribute_s* rsrc, struct zx_xac_Attribute_s* act, struct zx_xac_Attribute_s* env);
ZXID_DECL struct zx_xaspcd1_XACMLAuthzDecisionQuery_s* zxid_mk_az_cd1(zxid_conf* cf, struct zx_xac_Attribute_s* subj, struct zx_xac_Attribute_s* rsrc, struct zx_xac_Attribute_s* act, struct zx_xac_Attribute_s* env);
struct zx_sa_Attribute_s* zxid_mk_attribute(zxid_conf* cf, struct zx_elem_s* father, char* name, char* val);

/* zxidmkwsf */

ZXID_DECL struct zx_lu_Status_s* zxid_mk_lu_Status(zxid_conf* cf, struct zx_elem_s* father, const char* sc1, const char* sc2, const char* msg, const char* ref);
ZXID_DECL zxid_tas3_status* zxid_mk_tas3_status(zxid_conf* cf, struct zx_elem_s* father, const char* ctlpt, const char* sc1, const char* sc2, const char* msg, const char* ref);
ZXID_DECL zxid_fault* zxid_mk_fault(zxid_conf* cf, struct zx_elem_s* father, const char* fa, const char* fc, const char* fs, const char* sc1, const char* sc2, const char* msg, const char* ref);

ZXID_DECL void zxid_set_fault(zxid_conf* cf, zxid_ses* ses, zxid_fault* flt);
ZXID_DECL zxid_fault*  zxid_get_fault(zxid_conf* cf, zxid_ses* ses);

ZXID_DECL char* zxid_get_tas3_fault_sc1(zxid_conf* cf, zxid_fault* flt);
ZXID_DECL char* zxid_get_tas3_fault_sc2(zxid_conf* cf, zxid_fault* flt);
ZXID_DECL char* zxid_get_tas3_fault_comment(zxid_conf* cf, zxid_fault* flt);
ZXID_DECL char* zxid_get_tas3_fault_ref(zxid_conf* cf, zxid_fault* flt);
ZXID_DECL char* zxid_get_tas3_fault_actor(zxid_conf* cf, zxid_fault* flt);

ZXID_DECL zxid_tas3_status* zxid_get_fault_status(zxid_conf* cf, zxid_fault* flt);

ZXID_DECL void zxid_set_tas3_status(zxid_conf* cf, zxid_ses* ses, zxid_tas3_status* status);
ZXID_DECL zxid_tas3_status* zxid_get_tas3_status(zxid_conf* cf, zxid_ses* ses);

ZXID_DECL char* zxid_get_tas3_status_sc1(zxid_conf* cf, zxid_tas3_status* st);
ZXID_DECL char* zxid_get_tas3_status_sc2(zxid_conf* cf, zxid_tas3_status* st);
ZXID_DECL char* zxid_get_tas3_status_comment(zxid_conf* cf, zxid_tas3_status* st);
ZXID_DECL char* zxid_get_tas3_status_ref(zxid_conf* cf, zxid_tas3_status* st);
ZXID_DECL char* zxid_get_tas3_status_ctlpt(zxid_conf* cf, zxid_tas3_status* st);

ZXID_DECL struct zx_di_Query_s* zxid_mk_di_query(zxid_conf* cf, struct zx_elem_s* father, const char* svc_type, const char* url, const char* di_opt, const char* action);
ZXID_DECL struct zx_a_Address_s* zxid_mk_addr(zxid_conf* cf, struct zx_elem_s* father, struct zx_str* url);

ZXID_DECL struct zx_dap_Select_s* zxid_mk_dap_select(zxid_conf* cf, struct zx_elem_s* father, char* dn, char* filter, char* attributes, int deref_aliases, int scope, int sizelimit, int timelimit, int typesonly);
ZXID_DECL struct zx_dap_QueryItem_s* zxid_mk_dap_query_item(zxid_conf* cf, struct zx_elem_s* father, struct zx_dap_Select_s* sel, char* objtype, char* predef, char* sort, char* changed_since, int incl_common_attrs, int offset, int count, char* setreq, char* setid, char* contingent_itemidref);
ZXID_DECL struct zx_dap_TestOp_s* zxid_mk_dap_testop(zxid_conf* cf, struct zx_elem_s* father, char* dn, char* filter, char* attributes, int deref_aliases, int scope, int sizelimit, int timelimit, int typesonly);
ZXID_DECL struct zx_dap_TestItem_s* zxid_mk_dap_test_item(zxid_conf* cf, struct zx_elem_s* father, struct zx_dap_TestOp_s* top, char* objtype, char* predef);
ZXID_DECL struct zx_dap_ResultQuery_s* zxid_mk_dap_resquery(zxid_conf* cf, struct zx_elem_s* father, struct zx_dap_Select_s* sel, char* objtype, char* predef, char* sort, char* changed_since, int incl_common_attr, char* contingent_itemidref);
ZXID_DECL struct zx_dap_Subscription_s* zxid_mk_dap_subscription(zxid_conf* cf, struct zx_elem_s* father, char* subsID, char* itemidref, struct zx_dap_ResultQuery_s* rq, char* aggreg, char* trig, char* starts, char* expires, int incl_data, char* admin_notif, char* notify_ref);
ZXID_DECL struct zx_dap_Query_s* zxid_mk_dap_query(zxid_conf* cf, struct zx_elem_s* father, struct zx_dap_TestItem_s* tis, struct zx_dap_QueryItem_s* qis, struct zx_dap_Subscription_s* subs);

/* zxidwsf */

#define ZXID_N_WSF_SIGNED_HEADERS 40  /* Max number of signed SOAP headers. */

ZXID_DECL int zxid_map_sec_mech(zxid_epr* epr);
ZXID_DECL int zxid_hunt_sig_parts(zxid_conf* cf, int n_refs, struct zxsig_ref* refs, struct zx_ds_Reference_s* sref, struct zx_e_Header_s* hdr, struct zx_e_Body_s* bdy);
ZXID_DECL int zxid_add_header_refs(zxid_conf* cf, int n_refs, struct zxsig_ref* refs, struct zx_e_Header_s* hdr);
ZXID_DECL void zxid_wsf_sign(zxid_conf* cf, int sign_flags, struct zx_wsse_Security_s* sec, struct zx_wsse_SecurityTokenReference_s* str, struct zx_e_Header_s* hdr, struct zx_e_Body_s* bdy);
ZXID_DECL int zxid_wsf_timestamp_check(zxid_conf* cf, zxid_ses* ses, struct zx_wsu_Timestamp_s* ts, struct timeval* ourts, struct timeval* srcts, const char* ctlpt, const char* faultactor);
ZXID_DECL void zxid_attach_sol1_usage_directive(zxid_conf* cf, zxid_ses* ses, struct zx_e_Envelope_s* env, const char* attrid, const char* obl);

/* zxidwsp */

ZXID_DECL char* zxid_wsp_validate(zxid_conf* cf, zxid_ses* ses, const char* az_cred, const char* enve);
ZXID_DECL struct zx_str* zxid_wsp_decorate(zxid_conf* cf, zxid_ses* ses, const char* az_cred, const char* enve);
ZXID_DECL struct zx_str* zxid_wsp_decoratef(zxid_conf* cf, zxid_ses* ses, const char* az_cred, const char* env_f, ...);
ZXID_DECL int zxid_wsf_decor(zxid_conf* cf, zxid_ses* ses, struct zx_e_Envelope_s* env, int is_resp);

/* zxidwsc */

ZXID_DECL struct zx_e_Envelope_s* zxid_add_env_if_needed(zxid_conf* cf, const char* enve);
ZXID_DECL struct zx_e_Envelope_s* zxid_wsc_call(zxid_conf* cf, zxid_ses* ses, zxid_epr* epr, struct zx_e_Envelope_s* env, char** ret_enve);
ZXID_DECL struct zx_str* zxid_call(zxid_conf* cf, zxid_ses* ses, const char* svctype, const char* url, const char* di_opt, const char* az_cred, const char* enve);
ZXID_DECL struct zx_str* zxid_callf(zxid_conf* cf, zxid_ses* ses, const char* svctype, const char* url, const char* di_opt, const char* az_cred, const char* env_f, ...);
ZXID_DECL struct zx_str* zxid_call_epr(zxid_conf* cf, zxid_ses* ses, zxid_epr* epr, const char* az_cred, const char* enve);
ZXID_DECL struct zx_str* zxid_callf_epr(zxid_conf* cf, zxid_ses* ses, zxid_epr* epr, const char* az_cred, const char* env_f, ...);
ZXID_DECL struct zx_str* zxid_wsc_prepare_call(zxid_conf* cf, zxid_ses* ses, zxid_epr* epr, const char* az_cred, const char* enve);
ZXID_DECL struct zx_str* zxid_wsc_prepare_callf(zxid_conf* cf, zxid_ses* ses, zxid_epr* epr, const char* az_cred, const char* env_f, ...);
ZXID_DECL int zxid_wsc_valid_resp(zxid_conf* cf, zxid_ses* ses, const char* az_cred, const char* enve);

#define ZXID_RESP_ENV(cf, tag, status_code, status_comment) zxid_new_envf((cf), "<%s><lu:Status code=\"%s\" comment=\"%s\"></lu:Status></%s>", (tag), (status_code), (status_comment), (tag))

/*() Most SOAP messages (at least in Liberty based web services) have
 * the status field in same place, but they all have different data
 * types. Given the similarity it is desireable to have common
 * "function" for checking status, but due to the type problem it has
 * to be done with a macro (dynamically typed language would make this easy). */

#define ZXID_CHK_STATUS(env, field, abort_action) MB struct zx_str* ss; if (!(env)) abort_action; \
  if (!env->Body->field) { ERR("Body is missing " #field " element. %p", env); abort_action; } \
  if (!env->Body->field->Status) { ERR( #field " is missing Status. %p", env); abort_action; } \
  if (!env->Body->field->Status->code) { ERR( #field "->Status is missing code. %p", env); abort_action; } \
  if (!env->Body->field->Status->code->s) { ERR( #field "->Status->code empty. %p", env); abort_action; } \
  if (!memcmp(env->Body->field->Status->code->s, "OK", 2)) { \
       ss = env->Body->field->Status->comment; \
       D(#field ": Status OK (%.*s)", ss?ss->len:0, ss?ss->s:""); \
    } else { \
       ss = env->Body->field->Status->comment; \
       ERR("FAIL: " #field ": Status %.*s (%.*s)", \
         env->Body->field->Status->code->len, env->Body->field->Status->code->s, \
         ss?ss->len:0, ss?ss->s:""); \
      abort_action; \
    } \
  ME

/* zxidepr */

ZXID_DECL int zxid_nice_sha1(zxid_conf* cf, char* buf, int buf_len, struct zx_str* name, struct zx_str* contint, int ign_prefix);
ZXID_DECL void zxid_fold_svc(char* path, int len);
ZXID_DECL int zxid_epr_path(zxid_conf* cf, char* dir, char* sid, char* buf, int buf_len, struct zx_str* svc, struct zx_str* cont);
ZXID_DECL zxid_epr* zxid_get_epr(zxid_conf* cf, zxid_ses* ses, const char* svc, const char* url, const char* di_opt, const char* action, int n);
ZXID_DECL zxid_epr* zxid_find_epr(zxid_conf* cf, zxid_ses* ses, const char* svc, const char* url, const char* di_opt, const char* action, int n);
ZXID_DECL int zxid_cache_epr(zxid_conf* cf, zxid_ses* ses, zxid_epr* epr);
ZXID_DECL void zxid_snarf_eprs(zxid_conf* cf, zxid_ses* ses, zxid_epr* epr);
ZXID_DECL void zxid_snarf_eprs_from_ses(zxid_conf* cf, zxid_ses* ses);
ZXID_DECL struct zx_str* zxid_get_epr_address(zxid_conf* cf, zxid_epr* epr);
ZXID_DECL struct zx_str* zxid_get_epr_entid(zxid_conf* cf, zxid_epr* epr);
ZXID_DECL struct zx_str* zxid_get_epr_desc(zxid_conf* cf, zxid_epr* epr);
ZXID_DECL struct zx_str* zxid_get_epr_secmech(zxid_conf* cf, zxid_epr* epr);
ZXID_DECL void zxid_set_epr_secmech(zxid_conf* cf, zxid_epr* epr, const char* secmec);
ZXID_DECL zxid_tok* zxid_get_epr_token(zxid_conf* cf, zxid_epr* epr);
ZXID_DECL void zxid_set_epr_token(zxid_conf* cf, zxid_epr* epr, zxid_tok* tok);
ZXID_DECL zxid_epr* zxid_new_epr(zxid_conf* cf, char* address, char* desc, char* entid, char* svctype);
ZXID_DECL zxid_epr* zxid_get_delegated_discovery_epr(zxid_conf* cf, zxid_ses* ses);
ZXID_DECL void zxid_set_delegated_discovery_epr(zxid_conf* cf, zxid_ses* ses, zxid_epr* epr);

ZXID_DECL zxid_tok* zxid_get_call_invoktok(zxid_conf* cf, zxid_ses* ses);
ZXID_DECL void zxid_set_call_invoktok(zxid_conf* cf, zxid_ses* ses, zxid_tok* tok);
ZXID_DECL zxid_tok* zxid_get_call_tgttok(zxid_conf* cf, zxid_ses* ses);
ZXID_DECL void zxid_set_call_tgttok(zxid_conf* cf, zxid_ses* ses, zxid_tok* tok);
ZXID_DECL struct zx_str* zxid_token2str(zxid_conf* cf, zxid_tok* tok);
ZXID_DECL zxid_tok* zxid_str2token(zxid_conf* cf, struct zx_str* ss);
ZXID_DECL struct zx_str* zxid_a7n2str(zxid_conf* cf, zxid_a7n* a7n);
ZXID_DECL zxid_a7n* zxid_str2a7n(zxid_conf* cf, struct zx_str* ss);
ZXID_DECL struct zx_str* zxid_nid2str(zxid_conf* cf, zxid_nid* nid);
ZXID_DECL zxid_nid* zxid_str2nid(zxid_conf* cf, struct zx_str* ss);
ZXID_DECL zxid_nid* zxid_get_nameid(zxid_conf* cf, zxid_ses* ses);
ZXID_DECL void zxid_set_nameid(zxid_conf* cf, zxid_ses* ses, zxid_nid* nid);
ZXID_DECL zxid_nid* zxid_get_tgtnameid(zxid_conf* cf, zxid_ses* ses);
ZXID_DECL void zxid_set_tgtnameid(zxid_conf* cf, zxid_ses* ses, zxid_nid* nid);
ZXID_DECL zxid_a7n* zxid_get_a7n(zxid_conf* cf, zxid_ses* ses);
ZXID_DECL void zxid_set_a7n(zxid_conf* cf, zxid_ses* ses, zxid_a7n* a7n);
ZXID_DECL zxid_a7n* zxid_get_tgta7n(zxid_conf* cf, zxid_ses* ses);
ZXID_DECL void zxid_set_tgta7n(zxid_conf* cf, zxid_ses* ses, zxid_a7n* a7n);

/* zxiddi -  Discovery Service */

ZXID_DECL int zxid_idp_map_nid2uid(zxid_conf* cf, int len, char* uid, zxid_a7n* a7n, struct zx_lu_Status_s** stp, zxid_nid** nameidp);

ZXID_DECL struct zx_di_QueryResponse_s* zxid_di_query(zxid_conf* cf, zxid_a7n* a7n, struct zx_di_Query_s* req, struct zx_str* issuer);

/* zxidim -  Identity Mapping Service, Single Sign-On Service (SSOS) */

ZXID_DECL struct zx_sp_Response_s* zxid_ssos_anreq(zxid_conf* cf, zxid_a7n* a7n, struct zx_sp_AuthnRequest_s* req, struct zx_str* issuer);
ZXID_DECL zxid_tok* zxid_map_identity_token(zxid_conf* cf, zxid_ses* ses, const char* at_eid, int how);
ZXID_DECL struct zx_im_IdentityMappingResponse_s* zxid_imreq(zxid_conf* cf, zxid_a7n* a7n, struct zx_im_IdentityMappingRequest_s* req, struct zx_str* issuer);

ZXID_DECL struct zx_sp_NameIDMappingResponse_s* zxid_nidmap_do(zxid_conf* cf, struct zx_sp_NameIDMappingRequest_s* req);

/* zxidps -  People Service (and delegation) */

ZXID_DECL struct zx_str* zxid_psobj_enc(zxid_conf* cf, struct zx_str* eid, const char* prefix, struct zx_str* psobj);
ZXID_DECL struct zx_str* zxid_psobj_dec(zxid_conf* cf, struct zx_str* eid, const char* prefix, struct zx_str* psobj);

ZXID_DECL char* zxid_ps_accept_invite(zxid_conf* cf, zxid_cgi* cgi, zxid_ses* ses, int* res_len, int auto_flags);
ZXID_DECL char* zxid_ps_finalize_invite(zxid_conf* cf, zxid_cgi* cgi, zxid_ses* ses, int* res_len, int auto_flags);
ZXID_DECL struct zx_ps_AddEntityResponse_s* zxid_ps_addent_invite(zxid_conf* cf, zxid_a7n* a7n, struct zx_ps_AddEntityRequest_s* req, struct zx_str* issuer);
ZXID_DECL struct zx_ps_ResolveIdentifierResponse_s* zxid_ps_resolv_id(zxid_conf* cf, zxid_a7n* a7n, struct zx_ps_ResolveIdentifierRequest_s* req, struct zx_str* issuer);

/* DAP scope constants are same as for LDAP, see RFC2251 */

#define ZXID_DAP_SCOPE_BASE    0  /* Only what is pointed to by DN, e.g. one entry. The default. */
#define ZXID_DAP_SCOPE_SINGLE  1  /* Single level of directory right under DN. */
#define ZXID_DAP_SCOPE_SUBTREE 2  /* Full subtree search under the DN. */

/* If CDC is not present, the user interface is always offered. */

#define ZXID_CDC_CHOICE_ALWAYS_FIRST 1  /* Do not offer UI, always pick first on CDC list. */
#define ZXID_CDC_CHOICE_ALWAYS_LAST  2  /* Do not offer UI, always pick last on CDC list. */
#define ZXID_CDC_CHOICE_ALWAYS_ONLY  3  /* If CDC has only one IdP, always pick it. */
#define ZXID_CDC_CHOICE_UI_PREF      4  /* Offer UI with the CDC designated IdPs first. */
#define ZXID_CDC_CHOICE_UI_NOPREF    5  /* Offer UI. Do not give preference to CDC IdPs. */
#define ZXID_CDC_CHOICE_UI_ONLY_CDC  6  /* Offer UI. If CDC was set, only show IdPs from CDC. Otherwise show all IdPs. */

#define ZXID_SAML2_ART   1
#define ZXID_SAML2_POST  2
#define ZXID_SAML2_PAOS  3
#define ZXID_SAML2_SOAP  4
#define ZXID_SAML2_POST_SIMPLE_SIGN  5
#define ZXID_SAML2_REDIR 6   /* for function of same name, see */
#define ZXID_SAML2_URI   7

#define ZXID_SLO_SVC 1
#define ZXID_MNI_SVC 2
#define ZXID_ACS_SVC 3

/* Broad categories of secmechs. Specific secmechs are mapped to these to abstract similarity. */

#define ZXID_SEC_MECH_NULL   1
#define ZXID_SEC_MECH_BEARER 2
#define ZXID_SEC_MECH_SAML   3
#define ZXID_SEC_MECH_X509   4
#define ZXID_SEC_MECH_PEERS  5

/* Common status codes: usually tested without comparison to constant, i.e.
 * return value of functions (which can only fail or succeed) is directly
 * used in conditional test. You will see base 0's and 1's in code.
 * Usually 1 means event was fully handled and no fall thru behaviour
 * is desired. 0 usually means the fal thru default should happen. */
#define ZXID_FAIL     0  /* Fall thru to default behaviour. */
#define ZXID_OK       1  /* Don't fall thru, event fully handled. */
#define ZXID_REDIR_OK 2  /* Don't fall thru, event fully handled. */
#define ZXID_SSO_OK   3  /* Special case for SSO completed situation. Use as switch case. */
#define ZXID_IDP_REQ  4  /* Used by SP dispatch to punt the message to IdP processing. */

#if 1
#define ZXID_TRUE  "1"
#define ZXID_FALSE "0"
#else
#define ZXID_TRUE  "true"
#define ZXID_FALSE "false"
#endif

/* Test XML boolean field (zx_str) for XML valid "true" values */
#define ZXID_XML_TRUE_TEST(x) ((x) && (x)->s && (((x)->len == 1 && (x)->s[0] == '1') || ((x)->len == 4 && !memcmp((x)->s, "true", 4))))

/* Define this so it results CR (0xd) and LF (0xa) on your platform. N.B. \n is not always 0xa! */
#define CRLF "\015\012"
#define CRLF2 CRLF CRLF

#define COPYVAL(to,what,lim) MB (to) = ZX_ALLOC(cf->ctx, (lim)-(what)+1); memcpy((to), (what),  (lim)-(what)); (to)[(lim)-(what)] = 0; ME

extern char std_basis_64[64];
extern char safe_basis_64[64];
extern unsigned char zx_std_index_64[256];

ZXID_DECL char* base64_fancy_raw(const char* p, int len, char* r, const char* basis_64, int line_len, int eol_len, const char* eol, char eq_pad);
ZXID_DECL char* unbase64_raw(const char* p, const char* lim, char* r, const unsigned char* index_64);
ZXID_DECL char* sha1_safe_base64(char* out_buf, int len, const char* data);
ZXID_DECL char* zx_zlib_raw_deflate(struct zx_ctx* c, int in_len, const char* in, int* out_len);  /* gzip */
ZXID_DECL char* zx_zlib_raw_inflate(struct zx_ctx* c, int in_len, const char* in, int* out_len);  /* gunzip */
ZXID_DECL int   zx_url_encode_len(int in_len, char* in);
ZXID_DECL char* zx_url_encode_raw(int in_len, char* in, char* out);
ZXID_DECL char* zx_url_encode(struct zx_ctx* c, int in_len, char* in, int* out_len);
ZXID_DECL extern const unsigned char const * hex_trans;
ZXID_DECL extern const unsigned char const * ykmodhex_trans;
ZXID_DECL char* zx_hexdec(char* dst, char* src, int len, const unsigned char* trans);

ZXID_DECL int get_file_size(fdtype fd);
ZXID_DECL char* read_all_alloc(struct zx_ctx* c, const char* logkey, int reperr, int* lenp, const char* name_fmt, ...);
ZXID_DECL int read_all(int maxlen, char* buf, const char* logkey, int reperr, const char* name_fmt, ...);
ZXID_DECL int name_from_path(char* buf, int buf_len, const char* name_fmt, ...);
ZXID_DECL fdtype open_fd_from_path(int flags, int mode, const char* logkey, int reperr, const char* name_fmt, ...);
ZXID_DECL int read_all_fd(fdtype fd, char* p, int want, int* got_all);
ZXID_DECL int write_all_fd(fdtype fd, const char* p, int pending);
ZXID_DECL int write_all_path_fmt(const char* logkey, int len, char* buf, const char* path_fmt, const char* prepath, const char* postpath, const char* data_fmt, ...);
ZXID_DECL int copy_file(const char* from, const char* to, const char* logkey, int may_link);
ZXID_DECL int close_file(fdtype fd, const char* logkey);

struct zxid_curl_ctx {
  char* p;
  char* buf;
  char* lim;
};

ZXID_DECL size_t zxid_curl_write_data(void *buffer, size_t size, size_t nmemb, void *userp);
ZXID_DECL size_t zxid_curl_read_data(void *buffer, size_t size, size_t nmemb, void *userp);

#include <zx/zxidnoswig.h>

#ifdef __cplusplus
} // extern "C"
#endif

#endif
