/* zxidconf.c  -  Handwritten functions for parsing ZXID configuration file
 * Copyright (c) 2009-2010 Sampo Kellomaki (sampo@iki.fi), All Rights Reserved.
 * Copyright (c) 2006-2009 Symlabs (symlabs@symlabs.com), All Rights Reserved.
 * Author: Sampo Kellomaki (sampo@iki.fi)
 * This is confidential unpublished proprietary source code of the author.
 * NO WARRANTY, not even implied warranties. Contains trade secrets.
 * Distribution prohibited unless authorized in writing.
 * Licensed under Apache License 2.0, see file COPYING.
 * $Id: zxidconf.c,v 1.51 2010-01-08 02:10:09 sampo Exp $
 *
 * 12.8.2006, created --Sampo
 * 16.1.2007, split from zxidlib.c --Sampo
 * 27.3.2007, lazy reading of certificates --Sampo
 * 22.2.2008, added path_supplied feature --Sampo
 * 7.10.2008, added documentation --Sampo
 * 29.8.2009, added Auto-Cert feature a.k.a. zxid_mk_self_signed_cert() --Sampo
 * 4.9.2009,  added NEED, WANT, INMAP, PEPMAP, OUTMAP, and ATTRSRC --Sampo
 * 15.11.2009, added SHOW_CONF (o=d) option --Sampo
 * 7.1.2010,  added WSC and WSP signing options --Sampo
 * 12.2.2010, added pthread locking --Sampo
 * 31.5.2010, added 4 web service call PEPs --Sampo
 */

#include "platform.h"  /* needed on Win32 for pthread_mutex_lock() et al. */

#include <memory.h>
#include <string.h>
#ifdef USE_CURL
#include <curl/curl.h>
#endif

#include "errmac.h"
#include "zxid.h"
#include "zxidconf.h"
#include "c/zxidvers.h"

/* ============== Configuration ============== */
/* Eventually configuration will be read from some file, but for
 * now, we settle for compilation time configuration, see zxidconf.h */

#ifdef USE_OPENSSL

#include <openssl/rand.h>
#include <openssl/x509.h>
#include <openssl/rsa.h>

#if 0
/*(-) Compute raw SHA1 digest hash over contents of a file.
 *
 * cf:: ZXID configuration object, used for deteminin path prefix and for memory allocation
 * name:: Name of the file (under hierarchy defined by PATH configuration option)
 * sha1:: A sha1 buffer which should be exactly 20 bytes (160 bits) long. The
 *     buffer will be modified in place by this function. */

/* Called by:  zxid_init_conf */
void zxid_sha1_file(zxid_conf* cf, char* name, char* sha1)
{
  int gotall;
  char* buf;
  ZERO(sha1, 20);
  buf = read_all_alloc(cf->ctx, "sha1_file", 1, &gotall, "%s%s", cf->path, name);
  if (!buf)
    return;
  SHA1(buf, gotall, sha1);
  ZX_FREE(cf->ctx, buf);
}
#endif

/*() Extract a certificate from PEM encoded string. */

/* Called by:  opt, test_mode, zxid_read_cert */
X509* zxid_extract_cert(char* buf, char* name)
{
  X509* x = 0;  /* Forces d2i_X509() to alloc the memory. */
  char* p;
  char* e;
  OpenSSL_add_all_algorithms();
  p = strstr(buf, PEM_CERT_START);
  if (!p) {
    ERR("No certificate found in file(%s)\n", name);
    return 0;
  }
  p += sizeof(PEM_CERT_START) - 1;
  if (*p == 0xd) ++p;
  if (*p != 0xa) return 0;
  ++p;
  
  e = strstr(buf, PEM_CERT_END);
  if (!e) return 0;
  
  p = unbase64_raw(p, e, buf, zx_std_index_64);
  if (!d2i_X509(&x, (const unsigned char**)&buf /* *** compile warning */, p-buf) || !x) {
    ERR("DER decoding of X509 certificate failed.\n%d", 0);
    return 0;
  }
  return x;
}

/*() Extract a private key from PEM encoded string. */

/* Called by:  opt, test_mode, zxid_read_private_key */
RSA* zxid_extract_private_key(char* buf, char* name)
{
  char* p;
  char* e;
  EVP_PKEY* pk = 0;  /* Forces d2i_PrivateKey() to alloc the memory. */
  RSA* rsa = 0;
  OpenSSL_add_all_algorithms();
  
  p = strstr(buf, PEM_RSA_PRIV_KEY_START);
  if (!p) {
    ERR("No private key found in file(%s)\n", name);
    return 0;
  }
  p += sizeof(PEM_RSA_PRIV_KEY_START) - 1;
  if (*p == 0xd) ++p;
  if (*p != 0xa) return 0;
  ++p;
  
  e = strstr(buf, PEM_RSA_PRIV_KEY_END);
  if (!e) return 0;
  
  p = unbase64_raw(p, e, buf, zx_std_index_64);
  if (!d2i_PrivateKey(EVP_PKEY_RSA, &pk, (const unsigned char**)&buf /* *** compile warning */, p-buf) || !pk) {
    ERR("DER decoding of private key failed.\n%d", 0);
    return 0;
  }
  rsa = EVP_PKEY_get1_RSA(pk);
  return rsa;
}

/*() Extract a certificate from PEM encoded file. */

/* Called by:  zxid_idp_sso_desc x2, zxid_init_conf x3, zxid_lazy_load_sign_cert_and_pkey, zxid_sp_sso_desc x2, zxlog_write_line */
X509* zxid_read_cert(zxid_conf* cf, char* name)
{
  char buf[4096];
  int got = read_all(sizeof(buf), buf, "read_cert", 1, "%s" ZXID_PEM_DIR "%s", cf->path, name);
  if (!got && cf->auto_cert)
     zxid_mk_self_sig_cert(cf, sizeof(buf), buf, "read_cert", name);
  return zxid_extract_cert(buf, name);
}

/*() Extract a private key from PEM encoded file. */

/* Called by:  test_ibm_cert_problem x2, test_ibm_cert_problem_enc_dec x2, zxenc_privkey_dec, zxid_init_conf x3, zxid_lazy_load_sign_cert_and_pkey, zxlog_write_line x2 */
RSA* zxid_read_private_key(zxid_conf* cf, char* name)
{
  char buf[4096];
  int got = read_all(sizeof(buf), buf, "read_private_key", 1, "%s" ZXID_PEM_DIR "%s", cf->path, name);
  if (!got && cf->auto_cert)
     zxid_mk_self_sig_cert(cf, sizeof(buf), buf, "read_private_key", name);
  return zxid_extract_private_key(buf, name);
}

/*() Lazy load signing certificate and private key. This reads them from disk
 * if needed. If they do not exist and auto_cert is enabled, they will be
 * generated on disk and the read. Once read from disk, they will be cached in
 * memory. */

/* Called by:  zxid_anoint_a7n, zxid_anoint_sso_resp, zxid_idp_soap_dispatch x2, zxid_idp_sso, zxid_mk_art_deref, zxid_pep_az_soap x3, zxid_saml2_post_enc, zxid_saml2_redir_enc, zxid_sp_mni_soap, zxid_sp_slo_soap, zxid_sp_soap_dispatch x6, zxid_wsf_sign */
int zxid_lazy_load_sign_cert_and_pkey(zxid_conf* cf, X509** cert, RSA** pkey, const char* logkey)
{
  LOCK(cf->mx, logkey);
  if (cert) {
    if (!(*cert = cf->sign_cert)) // Lazy load cert and private key
      *cert = cf->sign_cert = zxid_read_cert(cf, "sign-nopw-cert.pem");
  }
  if (!(*pkey = cf->sign_pkey))
    *pkey = cf->sign_pkey = zxid_read_private_key(cf, "sign-nopw-cert.pem");
  UNLOCK(cf->mx, logkey);
  if (cert && !*cert || !*pkey)
    return 0;
  return 1;
}
#endif

/*() Set obscure options of ZX and ZXID layers. Used to set debug options.
 * Generally setting these options is not supported, but this function
 * exists to avoid uncontrolled access to global variables. At least this
 * way the unsupported activity will happen in one controlled place where
 * it can be ignored, if need to be. You have been warned. */

/* Called by:  zxid_fed_mgmt_cf, zxid_idp_list_cf_cgi, zxid_simple_cf_ses */
int zxid_set_opt(zxid_conf* cf, int which, int val)
{
  switch (which) {
  case 1: zx_debug = val; return val;
  }
  return -1;
}

/*() Set obscure options of ZX and ZXID layers. Used to set debug options.
 * Generally setting these options is not supported, but this function
 * exists to avoid uncontrolled access to global variables. At least this
 * way the unsupported activity will happen in one controlled place where
 * it can be ignored, if need to be. You have been warned. */

/* Called by: */
char* zxid_set_opt_cstr(zxid_conf* cf, int which, char* val)
{
  switch (which) {
  case 2: strncpy(zx_instance, val, sizeof(zx_instance)); return zx_instance;
  case 3: D_INDENT(val); return zx_indent;
  case 4: D_DEDENT(val); return zx_indent;
  }
  return 0;
}

/*() Set the URL configuration variable. Usually you would use zxid_parse_conf()
 * to manipulate this and some other options. This function exists for some
 * special cases encountered in scripting language bindings. */

/* Called by:  main x2, zxidwspcgi_main */
void zxid_url_set(zxid_conf* cf, char* url)
{
  if (!cf || !url) {
    ERR("NULL pointer as cf or url argument cf=%p url=%p", cf, url);
    return;
  }
  D("Setting url(%s)", url);
  cf->url = zx_dup_cstr(cf->ctx, url);
}

pthread_mutex_t zxid_ent_cache_mx;
int zxid_ent_cache_mx_init = 0;

/*(i) Initialize configuration object, which must have already been
 * allocated, to factory defaults (i.e. compiled in defaults, see
 * zxidconf.h).
 *
 * cf:: Pointer to previously allocated configuration object
 * path:: Since this configuration option is so fundamental, it can
 *     be supplied directly as argument. However, unlike zxid_new_conf()
 *     this does not cause the config file to be read.
 * return:: 0 on success (currently, 2008, this function can not
 *     fail - thus it is common to ignore the return value)
 *
 * N.B. This function does NOT initialize the ZX context object although
 * it is a field of this object. You MUST separately initialize
 * the ZX context object, e.g. using zx_reset_ctx() or zx_init_ctx(),
 * before you can use ZXID configuration object in any memory allocation prone
 * activity (which is nearly every function in this API).
 */

/* Called by:  zxid_conf_to_cf_len, zxid_init_conf_ctx */
int zxid_init_conf(zxid_conf* cf, const char* zxid_path)
{
  DD("Initconf with path(%s)", zxid_path);
  cf->magic = ZXID_CONF_MAGIC;
  cf->path_len = zxid_path ? strlen(zxid_path) : 0;
  cf->path = ZX_ALLOC(cf->ctx, cf->path_len+1);
  memcpy(cf->path, zxid_path, cf->path_len);
  cf->path[cf->path_len] = 0;
  cf->nice_name = ZXID_NICE_NAME;
  cf->org_name = ZXID_ORG_NAME;
  cf->org_url = ZXID_ORG_URL;
  cf->locality = ZXID_LOCALITY;
  cf->state = ZXID_STATE;
  cf->country = ZXID_COUNTRY;
  cf->contact_org = ZXID_CONTACT_ORG;
  cf->contact_name = ZXID_CONTACT_NAME;
  cf->contact_email = ZXID_CONTACT_EMAIL;
  cf->contact_tel = ZXID_CONTACT_TEL;
  cf->fedusername_suffix = ZXID_FEDUSERNAME_SUFFIX;
  cf->url = ZXID_URL;
  cf->non_standard_entityid = ZXID_NON_STANDARD_ENTITYID;
  cf->redirect_hack_imposed_url = ZXID_REDIRECT_HACK_IMPOSED_URL;
  cf->redirect_hack_zxid_url = ZXID_REDIRECT_HACK_ZXID_URL;
  cf->cdc_url = ZXID_CDC_URL;
  cf->cdc_choice = ZXID_CDC_CHOICE;
  cf->authn_req_sign = ZXID_AUTHN_REQ_SIGN;
  cf->want_sso_a7n_signed = ZXID_WANT_SSO_A7N_SIGNED;
  cf->want_authn_req_signed = ZXID_WANT_AUTHN_REQ_SIGNED;
  cf->sso_soap_sign = ZXID_SSO_SOAP_SIGN;
  cf->sso_soap_resp_sign = ZXID_SSO_SOAP_RESP_SIGN;
  cf->sso_sign     = ZXID_SSO_SIGN;
  cf->wsc_sign     = ZXID_WSC_SIGN;
  cf->wsp_sign     = ZXID_WSP_SIGN;
  cf->wspcgicmd    = ZXID_WSPCGICMD;
  cf->nameid_enc   = ZXID_NAMEID_ENC;
  cf->post_a7n_enc = ZXID_POST_A7N_ENC;
  cf->canon_inopt  = ZXID_CANON_INOPT;
  if (cf->ctx) cf->ctx->canon_inopt = cf->canon_inopt;
  cf->enckey_opt   = ZXID_ENCKEY_OPT;
  cf->idpatopt     = ZXID_IDPATOPT;
  cf->idp_list_meth   = ZXID_IDP_LIST_METH;
  cf->di_allow_create = ZXID_DI_ALLOW_CREATE;
  cf->di_nid_fmt   = ZXID_DI_NID_FMT;
  cf->di_a7n_enc   = ZXID_DI_A7N_ENC;
  cf->bootstrap_level = ZXID_BOOTSTRAP_LEVEL;
  cf->show_conf    = ZXID_SHOW_CONF;
#ifdef USE_OPENSSL
  if (zxid_path) {
#if 0
    /* DO NOT ENABLE! The certificates and keys are read "just in time" if and when needed. */
    cf->sign_cert = zxid_read_cert(cf, "sign-nopw-cert.pem");
    cf->sign_pkey = zxid_read_private_key(cf, "sign-nopw-cert.pem");
    cf->enc_cert = zxid_read_cert(cf, "enc-nopw-cert.pem");
    cf->enc_pkey = zxid_read_private_key(cf, "enc-nopw-cert.pem");
    cf->log_sign_pkey = zxid_read_private_key(cf, "logsign-nopw-cert.pem");
    cf->log_enc_cert = zxid_read_cert(cf, "logenc-nopw-cert.pem");
    zxid_sha1_file(cf, "pem/logenc.key", cf->log_symkey);
#endif
  }
#else
  ERR("This copy of zxid was compiled to NOT use OpenSSL. Reading certificate and private key is not supported. Signing and signature verification are not supported either. Add -DUSE_OPENSSL and recompile. %d", 0);
#endif
  cf->md_fetch = ZXID_MD_FETCH;
  cf->md_populate_cache = ZXID_MD_POPULATE_CACHE;
  cf->md_cache_first    = ZXID_MD_CACHE_FIRST;
  cf->md_cache_last     = ZXID_MD_CACHE_LAST;
  cf->load_cot_cache    = ZXID_LOAD_COT_CACHE;
  cf->auto_cert         = ZXID_AUTO_CERT;
  cf->ses_arch_dir      = ZXID_SES_ARCH_DIR;
  cf->ses_cookie_name   = ZXID_SES_COOKIE_NAME;
  cf->user_local        = ZXID_USER_LOCAL;
  cf->idp_ena           = ZXID_IDP_ENA;
  cf->imps_ena          = ZXID_IMPS_ENA;
  cf->as_ena            = ZXID_AS_ENA;
  cf->pdp_ena           = ZXID_PDP_ENA;

  cf->loguser = ZXID_LOGUSER;
  cf->log_level = ZXLOG_LEVEL;
  cf->log_err = ZXLOG_ERR;      /* Log enables and signing and encryption flags (if USE_OPENSSL) */
  cf->log_act = ZXLOG_ACT;
  cf->log_issue_a7n  = ZXLOG_ISSUE_A7N;
  cf->log_issue_msg  = ZXLOG_ISSUE_MSG;
  cf->log_rely_a7n   = ZXLOG_RELY_A7N;
  cf->log_rely_msg   = ZXLOG_RELY_MSG;
  cf->log_err_in_act = ZXLOG_ERR_IN_ACT;
  cf->log_act_in_err = ZXLOG_ACT_IN_ERR;
  cf->log_sigfail_is_err = ZXLOG_SIGFAIL_IS_ERR;

  cf->sig_fatal      = ZXID_SIG_FATAL;
  cf->nosig_fatal    = ZXID_NOSIG_FATAL;
  cf->msg_sig_ok     = ZXID_MSG_SIG_OK;
  cf->timeout_fatal  = ZXID_TIMEOUT_FATAL;
  cf->audience_fatal = ZXID_AUDIENCE_FATAL;
  cf->dup_a7n_fatal  = ZXID_DUP_A7N_FATAL;
  cf->dup_msg_fatal  = ZXID_DUP_MSG_FATAL;
  cf->relto_fatal    = ZXID_RELTO_FATAL;
  cf->wsp_nosig_fatal = ZXID_WSP_NOSIG_FATAL;
  cf->notimestamp_fatal = ZXID_NOTIMESTAMP_FATAL;
  cf->anon_ok        = ZXID_ANON_OK;
  cf->required_authnctx = ZXID_REQUIRED_AUTHNCTX;
  cf->issue_authnctx_pw = ZXID_ISSUE_AUTHNCTX_PW;
  cf->idp_pref_acs_binding = ZXID_IDP_PREF_ACS_BINDING;
  cf->mandatory_attr = ZXID_MANDATORY_ATTR;

  cf->before_slop    = ZXID_BEFORE_SLOP;
  cf->after_slop     = ZXID_AFTER_SLOP;
  cf->timeskew       = ZXID_TIMESKEW;
  cf->a7nttl         = ZXID_A7NTTL;
  cf->pdp_url        = ZXID_PDP_URL;
  cf->pdp_call_url   = ZXID_PDP_CALL_URL;
  cf->xasp_vers      = ZXID_XASP_VERS;

  cf->need           = zxid_load_need(cf, 0, ZXID_NEED);
  cf->want           = zxid_load_need(cf, 0, ZXID_WANT);
  cf->attrsrc        = zxid_load_atsrc(cf, 0, ZXID_ATTRSRC);
  cf->inmap          = zxid_load_map(cf, 0, ZXID_INMAP);
  cf->outmap         = zxid_load_map(cf, 0, ZXID_OUTMAP);
  cf->pepmap         = zxid_load_map(cf, 0, ZXID_PEPMAP);
  cf->pepmap_rqout   = zxid_load_map(cf, 0, ZXID_PEPMAP_RQOUT);
  cf->pepmap_rqin    = zxid_load_map(cf, 0, ZXID_PEPMAP_RQIN);
  cf->pepmap_rsout   = zxid_load_map(cf, 0, ZXID_PEPMAP_RSOUT);
  cf->pepmap_rsin    = zxid_load_map(cf, 0, ZXID_PEPMAP_RSIN);

  cf->localpdp_role_permit    = zxid_load_cstr_list(cf, 0, ZXID_LOCALPDP_ROLE_PERMIT);
  cf->localpdp_role_deny      = zxid_load_cstr_list(cf, 0, ZXID_LOCALPDP_ROLE_DENY);
  cf->localpdp_idpnid_permit  = zxid_load_cstr_list(cf, 0, ZXID_LOCALPDP_IDPNID_PERMIT);
  cf->localpdp_idpnid_deny    = zxid_load_cstr_list(cf, 0, ZXID_LOCALPDP_IDPNID_DENY);

  cf->wsc_localpdp_obl_pledge = ZXID_WSC_LOCALPDP_OBL_PLEDGE;
  cf->wsp_localpdp_obl_req    = ZXID_WSP_LOCALPDP_OBL_REQ;
  cf->wsp_localpdp_obl_emit   = ZXID_WSP_LOCALPDP_OBL_EMIT;
  cf->wsc_localpdp_obl_accept = ZXID_WSC_LOCALPDP_OBL_ACCEPT;

  cf->redir_to_content  = ZXID_REDIR_TO_CONTENT;
  cf->remote_user_ena   = ZXID_REMOTE_USER_ENA;
  cf->max_soap_retry    = ZXID_MAX_SOAP_RETRY;
  cf->mod_saml_attr_prefix = ZXID_MOD_SAML_ATTR_PREFIX;

  cf->bare_url_entityid = ZXID_BARE_URL_ENTITYID;
  cf->show_tech         = ZXID_SHOW_TECH;
  cf->idp_sel_page      = ZXID_IDP_SEL_PAGE;
  cf->idp_sel_templ_file= ZXID_IDP_SEL_TEMPL_FILE;
  cf->idp_sel_templ     = ZXID_IDP_SEL_TEMPL;
#if 0
  cf->idp_sel_start     = ZXID_IDP_SEL_START;
  cf->idp_sel_new_idp   = ZXID_IDP_SEL_NEW_IDP;
  cf->idp_sel_our_eid   = ZXID_IDP_SEL_OUR_EID;
  cf->idp_sel_tech_user = ZXID_IDP_SEL_TECH_USER;
  cf->idp_sel_tech_site = ZXID_IDP_SEL_TECH_SITE;
  cf->idp_sel_footer    = ZXID_IDP_SEL_FOOTER;
  cf->idp_sel_end       = ZXID_IDP_SEL_END;
#endif

  cf->an_page           = ZXID_AN_PAGE;
  cf->an_templ_file     = ZXID_AN_TEMPL_FILE;
  cf->an_templ          = ZXID_AN_TEMPL;

  cf->post_templ_file   = ZXID_POST_TEMPL_FILE;
  cf->post_templ        = ZXID_POST_TEMPL;

  cf->err_page          = ZXID_ERR_PAGE;
  cf->err_templ_file    = ZXID_ERR_TEMPL_FILE;
  cf->err_templ         = ZXID_ERR_TEMPL;

  cf->new_user_page     = ZXID_NEW_USER_PAGE;
  cf->recover_passwd    = ZXID_RECOVER_PASSWD;
  cf->atsel_page        = ZXID_ATSEL_PAGE;

  cf->mgmt_start        = ZXID_MGMT_START;
  cf->mgmt_logout       = ZXID_MGMT_LOGOUT;
  cf->mgmt_defed        = ZXID_MGMT_DEFED;
  cf->mgmt_footer       = ZXID_MGMT_FOOTER;
  cf->mgmt_end          = ZXID_MGMT_END;
  
  LOCK_INIT(cf->mx);
  LOCK_INIT(cf->curl_mx);
  if (!zxid_ent_cache_mx_init) {
    LOCK_INIT(zxid_ent_cache_mx);
    zxid_ent_cache_mx_init = 1;
  }
  
#if 1
  DD("path(%.*s) cf->magic=%x", cf->path_len, cf->path, cf->magic);
#else
  fprintf(stderr, "t %9s:%-3d %-16s %s d " "path(%.*s) cf->magic=%x" "\n",
	  __FILE__, __LINE__, __FUNCTION__, ERRMAC_INSTANCE, cf->path_len, cf->path, cf->magic);
  fflush(stderr);
#endif
  return 0;
}

/*() Reset the seen doubly linked list to empty and initialize memory
 * allocation related function pointers to system malloc(3). Without
 * such initialization, any meomory allocation activity as well as
 * any XML parsing activity is doomed to segmentation fault. */

/* Called by:  dirconf, main x2, zx_init_ctx, zxid_az, zxid_simple_len */
void zx_reset_ctx(struct zx_ctx* ctx)
{
  ZERO(ctx, sizeof(struct zx_ctx));
  LOCK_INIT(ctx->mx);
  ctx->guard_seen_n.seen_n = &ctx->guard_seen_p;
  ctx->guard_seen_p.seen_p = &ctx->guard_seen_n;
  ctx->malloc_func = &malloc;
  ctx->realloc_func = &realloc;
  ctx->free_func = &free;
}

/*() Allocate new ZX object and initialize it in standard
 * way, i.e. use malloc(3) for memory allocation. */

/* Called by:  zxid_conf_to_cf_len, zxid_init_conf_ctx */
struct zx_ctx* zx_init_ctx()
{
  struct zx_ctx* ctx;
  ctx = malloc(sizeof(struct zx_ctx));
  D("malloc %p size=%d", ctx, sizeof(struct zx_ctx));
  if (!ctx) {
    ERR("out-of-memory in ctx alloc sizeof=%d", sizeof(struct zx_ctx));
    return 0;
  }
  zx_reset_ctx(ctx);
  return ctx;
}

/*() Minimal initialization of
 * the context is performed. Certificate and key operations as well as
 * CURL initialization are omitted. However the zx_ctx is installed so
 * that memory allocation against the context should work.
 * Supplying zxid_path merely initializes the PATH config option,
 * but does not cause configuration file to be read.
 *
 * Just initializes the config object to factory defaults (see zxidconf.h).
 * Previous content of the config object is lost. */

/* Called by:  zxcot_main, zxid_conf_to_cf_len, zxid_new_conf */
zxid_conf* zxid_init_conf_ctx(zxid_conf* cf, const char* zxid_path)
{
#if 0
  fprintf(stderr, "Waiting 60 secs for gdb attach...\n");
  sleep(60);
#endif
  cf->ctx = zx_init_ctx();
  if (!cf->ctx)
    return 0;
  zxid_init_conf(cf, zxid_path);
#ifdef USE_CURL
  if (zxid_path) {
    cf->curl = curl_easy_init();
    if (!cf->curl) {
      ERR("Failed to initialize libcurl %d",0);
      exit(2);
    }
  }
#endif
  return cf;
}

/*() Allocate conf object and initialize it with default config or config file.
 * See zxid_new_conf_to_cf() for a more complete solution.
 * Just initializes the config object to factory defaults (see zxidconf.h).
 * Previous content of the config object is lost. */

/* Called by:  main x6, test_ibm_cert_problem, test_ibm_cert_problem_enc_dec, test_mode */
zxid_conf* zxid_new_conf(const char* zxid_path)
{
  /* *** unholy malloc()s: should use our own allocator! */
  zxid_conf* cf = malloc(sizeof(zxid_conf));
  if (!cf) {
    ERR("out-of-memory %d", sizeof(zxid_conf));
    exit(1);
  }
  return zxid_init_conf_ctx(cf, zxid_path);
}

/* ================== Attribute Broker Config ================*/

#define IS_RULE(rule, val) (!memcmp((rule), (val), sizeof(val)-1) && (rule)[sizeof(val)-1] == '$')

/*() Create new (common pool) attribute and add it to a linked list */

/* Called by:  zxid_add_at_values x3, zxid_add_attr_to_ses x2, zxid_add_qs_to_ses, zxid_load_atsrc, zxid_load_need */
struct zxid_attr* zxid_new_at(zxid_conf* cf, struct zxid_attr* at, int name_len, char* name, int val_len, char* val, char* lk)
{
  struct zxid_attr* aa = ZX_ZALLOC(cf->ctx, struct zxid_attr);
  aa->n = at;
  at = aa;
  COPYVAL(at->name, name, name+name_len);
  if (val)
    COPYVAL(at->val, val, val+val_len);
  D("%s:\tATTR name(%.*s) val(%.*s)", lk, name_len, name, val_len, STRNULLCHK(val));
  return aa;
}

/*() Parse map specification and add it to linked list
 * srcns$A$rule$b$ext;src$A$rule$b$ext;...
 */

/* Called by:  zxid_init_conf x3, zxid_parse_conf_raw x3 */
struct zxid_map* zxid_load_map(zxid_conf* cf, struct zxid_map* map, char* v)
{
  char* ns;
  char* A;
  char* rule;
  char* b;
  char* ext;
  char* p = v;
  struct zxid_map* mm;

  DD("v(%s)", v);

  while (p && *p) {
    ns = p;
    p = strchr(p, '$');
    if (!p) {
      ERR("Malformed MAP directive: source namespace missing at pos %d", p-v);
      return map;
    }

    A = ++p;
    p = strchr(p, '$');
    if (!p) {
      ERR("Malformed MAP directive: source attribute name missing at pos %d", p-v);
      return map;
    }

    rule = ++p;
    p = strchr(p, '$');
    if (!p) {
      ERR("Malformed MAP directive: rule missing at pos %d", p-v);
      return map;
    }

    b = ++p;
    p = strchr(p, '$');
    if (!p) {
      ERR("Malformed MAP directive: destination attribute name missing at pos %d", p-v);
      return map;
    }
    
    ext = ++p;
    p = strchr(p, ';');  /* Stanza ends in separator ; or end of string nul */
    if (!p)
      p = ext + strlen(ext);
    
    if (IS_RULE(rule, "reset")) {
      INFO("Reset map %p", map);
      for (; map; map = mm) {
	mm = map->n;
	ZX_FREE(cf->ctx, map);
      }
      if (!*p) break;
      ++p;
      continue;
    }
    
    mm = ZX_ZALLOC(cf->ctx, struct zxid_map);
    mm->n = map;
    map = mm;
    
    if (IS_RULE(rule, "") || IS_RULE(rule, "rename")) { mm->rule = ZXID_MAP_RULE_RENAME; }
    else if (IS_RULE(rule, "del"))        { mm->rule = ZXID_MAP_RULE_DEL; }
    else if (IS_RULE(rule, "feidedec"))   { mm->rule = ZXID_MAP_RULE_FEIDEDEC; }
    else if (IS_RULE(rule, "feideenc"))   { mm->rule = ZXID_MAP_RULE_FEIDEENC; }
    else if (IS_RULE(rule, "unsb64-inf")) { mm->rule = ZXID_MAP_RULE_UNSB64_INF; }
    else if (IS_RULE(rule, "def-sb64"))   { mm->rule = ZXID_MAP_RULE_DEF_SB64; }
    else if (IS_RULE(rule, "unsb64"))     { mm->rule = ZXID_MAP_RULE_UNSB64; }
    else if (IS_RULE(rule, "sb64"))       { mm->rule = ZXID_MAP_RULE_SB64; }
    else {
      ERR("Unknown map rule(%.*s)", b-rule, rule);
      //ERR("sizeof(rename)=%d cmp=%d c(%c)", sizeof("rename"), memcmp(rule, "rename", sizeof("rename")-1), rule[sizeof("rename")]);
    }

    COPYVAL(mm->ns,  ns,  A-1);
    COPYVAL(mm->src, A,   rule-1);
    COPYVAL(mm->dst, b,   ext-1);
    COPYVAL(mm->ext, ext, p);

    DD("map ns(%s) src(%s) rule=%d dst(%s) ext(%s)", mm->ns, mm->src, mm->rule, mm->dst, mm->ext);
    if (!*p) break;
    ++p;
  }

  return map;
}

/*() Parse need specification and add it to linked list
 * A,B$usage$retention$oblig$ext;A,B$usage$retention$oblig$ext;...
 */

/* Called by:  zxid_init_conf x2, zxid_parse_conf_raw x2 */
struct zxid_need* zxid_load_need(zxid_conf* cf, struct zxid_need* need, char* v)
{
  char* attrs;
  char* usage;
  char* retent;
  char* oblig;
  char* ext;
  char* p = v;
  char* a;
  int len;
  struct zxid_need* nn;

  while (p && *p) {
    attrs = p;
    p = strchr(p, '$');
    if (!p) {
      ERR("Malformed NEED or WANT directive: attribute list at pos %d", p-v);
      return need;
    }

    usage = ++p;
    p = strchr(p, '$');
    if (!p) {
      ERR("Malformed NEED or WANT directive: usage missing at pos %d", p-v);
      return need;
    }

    retent = ++p;
    p = strchr(p, '$');
    if (!p) {
      ERR("Malformed NEED or WANT directive: retention missing at pos %d", p-v);
      return need;
    }

    oblig = ++p;
    p = strchr(p, '$');
    if (!p) {
      ERR("Malformed NEED or WANT directive: obligations missing at pos %d", p-v);
      return need;
    }
    
    ext = ++p;
    p = strchr(p, ';');  /* Stanza ends in separator ; or end of string nul */
    if (!p)
      p = ext + strlen(ext);
    
    if (IS_RULE(usage, "reset")) {
      INFO("Reset need %p", need);
      for (; need; need = nn) {
	nn = need->n;
	ZX_FREE(cf->ctx, need);
      }
      if (!*p) break;
      ++p;
      continue;
    }
    
    nn = ZX_ZALLOC(cf->ctx, struct zxid_need);
    nn->n = need;
    need = nn;

    COPYVAL(nn->usage,  usage,  retent-1);
    COPYVAL(nn->retent, retent, oblig-1);
    COPYVAL(nn->oblig,  oblig,  ext-1);
    COPYVAL(nn->ext,    ext,    p);

    DD("need attrs(%.*s) usage(%s) retent(%s) oblig(%s) ext(%s)", usage-attrs-1, attrs, nn->usage, nn->retent, nn->oblig, nn->ext);

    for (a = attrs; ; a += len+1) {
      len = strcspn(a, ",$");
      nn->at = zxid_new_at(cf, nn->at, len, a, 0,0, "need/want");
      if (a[len] == '$')
	break;
    }
    if (!*p) break;
    ++p;
  }

  return need;
}

/*() Parse ATTRSRC specification and add it to linked list
 * namespace$A,B$weight$accessparamURL$AAPMLref$otherLim$ext;namespace$A,B$weight$accessparamURL$AAPMLref$otherLim$ext;...
 */

/* Called by:  zxid_init_conf x4, zxid_parse_conf_raw x4 */
struct zxid_cstr_list* zxid_load_cstr_list(zxid_conf* cf, struct zxid_cstr_list* l, char* p)
{
  char* q;
  struct zxid_cstr_list* cs;

  for (; p && *p;) {
    q = p;
    p = strchr(p, ',');
    if (!p)
      p = q + strlen(q);
    cs = ZX_ZALLOC(cf->ctx, struct zxid_cstr_list);
    cs->n = l;
    l = cs;
    COPYVAL(cs->s, q, p);    
  }
  return l;
}

/*() Parse ATTRSRC specification and add it to linked list
 * namespace$A,B$weight$accessparamURL$AAPMLref$otherLim$ext;namespace$A,B$weight$accessparamURL$AAPMLref$otherLim$ext;...
 */

/* Called by:  zxid_init_conf, zxid_parse_conf_raw */
struct zxid_atsrc* zxid_load_atsrc(zxid_conf* cf, struct zxid_atsrc* atsrc, char* v)
{
  char* ns;
  char* attrs;
  char* weight;
  char* url;
  char* aapml;
  char* otherlim;
  char* ext;
  char* p = v;
  char* a;
  int len;
  struct zxid_atsrc* as;

  while (p && *p) {
    ns = p;
    p = strchr(p, '$');
    if (!p) {
      ERR("Malformed ATSRC directive: namespace missing at pos %d", p-v);
      return atsrc;
    }

    attrs = ++p;
    p = strchr(p, '$');
    if (!p) {
      ERR("Malformed ATSRC directive: attribute list missing at pos %d", p-v);
      return atsrc;
    }

    weight = ++p;
    p = strchr(p, '$');
    if (!p) {
      ERR("Malformed ATSRC directive: weight missing at pos %d", p-v);
      return atsrc;
    }

    url = ++p;
    p = strchr(p, '$');
    if (!p) {
      ERR("Malformed ATSRC directive: url missing at pos %d", p-v);
      return atsrc;
    }

    aapml = ++p;
    p = strchr(p, '$');
    if (!p) {
      ERR("Malformed ATSRC directive: aapml ref missing at pos %d", p-v);
      return atsrc;
    }
    
    otherlim = ++p;
    p = strchr(p, '$');
    if (!p) {
      ERR("Malformed ATSRC directive: otherlim missing at pos %d", p-v);
      return atsrc;
    }
    
    ext = ++p;
    p = strchr(p, ';');  /* Stanza ends in separator ; or end of string nul */
    if (!p)
      p = ext + strlen(ext);
    
    if (IS_RULE(url, "reset")) {
      INFO("Reset atsrc %p", atsrc);
      for (; atsrc; atsrc = as) {
	as = atsrc->n;
	ZX_FREE(cf->ctx, atsrc);
      }
      if (!*p) break;
      ++p;
      continue;
    }
    
    as = ZX_ZALLOC(cf->ctx, struct zxid_atsrc);
    as->n = atsrc;
    atsrc = as;

    COPYVAL(as->ns,       ns,        attrs-1);
    COPYVAL(as->weight,   weight,    url-1);
    COPYVAL(as->url,      url,       aapml-1);
    COPYVAL(as->aapml,    aapml,     otherlim-1);
    COPYVAL(as->otherlim, otherlim,  ext-1);
    COPYVAL(as->ext,      ext,       p);

    D("atsrc ns(%s) attrs(%.*s) weight(%s) url(%s) aapml(%s) otherlim(%s) ext(%s)", as->ns, weight-attrs-1, attrs, as->weight, as->url, as->aapml, as->otherlim, as->ext);

    for (a = attrs; ; a += len+1) {
      len = strcspn(a, ",$");
      as->at = zxid_new_at(cf, as->at, len, a, 0,0, "atsrc");
      if (a[len] == '$')
	break;
    }
    if (!*p) break;
    ++p;
  }

  return atsrc;
}

/*() Check whether attribute is in a (needed or wanted) list. Just a linear
 * scan as it is simple and good enough for handful of attributes. */

/* Called by:  zxid_add_at_values x2, zxid_add_attr_to_ses x2 */
struct zxid_need* zxid_is_needed(struct zxid_need* need, char* name)
{
  struct zxid_attr* at;
  if (!name || !*name)
    return 0;
  for (; need; need = need->n)
    for (at = need->at; at; at = at->n)
      if (at->name[0] == '*' && !at->name[1]   /* Wild card */
	  || !strcmp(at->name, name)) /* Match! */
	return need;
  return 0;
}

/*() Check whether attribute is in a (needed or wanted) list. Just a linear
 * scan as it is simple and good enough for handful of attributes. */

/* Called by:  pool2apache, zxid_add_at_values, zxid_add_attr_to_ses, zxid_pep_az_soap, zxid_pool_to_json x2, zxid_pool_to_ldif x2, zxid_pool_to_qs x2 */
struct zxid_map* zxid_find_map(struct zxid_map* map, char* name)
{
  if (!name || !*name)
    return 0;
  for (; map; map = map->n)
    if (map->src[0] == '*' && !map->src[1] /* Wild card (only sensible for del and data xform) */
	|| !strcmp(map->src, name)) /* Match! */
      return map;
  return 0;
}

/*() Check whether name is in the list. Used for Local PDP wite and black lists. */

/* Called by:  zxid_localpdp x4 */
struct zxid_cstr_list* zxid_find_cstr_list(struct zxid_cstr_list* cs, char* name)
{
  if (!name || !*name)
    return 0;
  for (; cs; cs = cs->n)
    if (cs->s[0] == '*' && !cs->s[1] /* Wild card */
	|| !strcmp(cs->s, name))     /* Match! */
      return cs;
  return 0;
}

/*() Check whether attribute is in pool. */

/* Called by:  zxid_localpdp x2 */
struct zxid_attr* zxid_find_at(struct zxid_attr* pool, char* name)
{
  if (!name || !*name)
    return 0;
  for (; pool; pool = pool->n)
    if (!strcmp(pool->name, name))     /* Match! */
      return pool;
  return 0;
}

/*() Given URL, return a newly allocated string corresponding
 * to the domain name part of the URL. Used to grab fedusername_suffix
 * from the url config option. */

static char* zxid_grab_domain_name(zxid_conf* cf, char* url)
{
  char* dom;
  char* p;
  int len;
  if (!url || !*url)
    return 0;
  dom = strchr(url, ':');
  if (!dom || dom[1] != '/' || dom[2] != '/')
    return 0;
  dom += 3;
  /* After shipping https:// scan for domain name allowable characters. */
  len = strspn(dom, ".abcdefghijklmnopqrstuvwxyz0123456789-ABCDEFGHIJKLMNOPQRSTUVWXYZ");
  p = ZX_ALLOC(cf->ctx, len+1);
  memcpy(p, dom, len);
  p[len] = 0;
  return p;
}

/* ======================= CONF PARSING ======================== */

#if defined(ZXID_CONF_FILE) || defined(ZXID_CONF_FLAG)

#define SCAN_INT(v, lval) sscanf(v,"%i",&i); lval=i /* Safe for char, too */

/*(i) Parse partial configuration specifications, such as may occur
 * on command line or in a configuration file.
 *
 * Generally you should
 * call first zxid_new_conf(), or at least zxid_init_conf(), and
 * then call this function to apply modifications over the defaults.
 * The configuration options are named after the config options
 * that appear in zxidconf.h, except that prefix ZXID_ is removed.
 *
 * N.B. The qs memory must come from static or permanently allocated
 * source as direct pointers to inside it will be taken. The memory
 * will be modified to add nul terminations. Do not use stack based
 * memory like local variable (unless local of main()).
 * Do consider strdup() or similar before calling this function.
 *
 * cf:: Previously allocated and initialized ZXID configuration object
 * qs_len:: Query String length. -1 means nul terminated C string
 * qs:: Configuration data in extended CGI Query String format. "extended"
 *     means newline can be used as separator, in addition to ampersand ("&")
 *     This argument is modified in place, changing separators to nul string
 *     terminations.
 * return:: -1 on failure, 0 on success */

/* Called by:  zxid_conf_to_cf_len x2, zxid_parse_conf, zxid_parse_conf_raw */
int zxid_parse_conf_raw(zxid_conf* cf, int qs_len, char* qs)
{
  int i, len;
  char *p, *n, *v, *val, *name, *buf;
  if (qs_len != -1 && qs[qs_len]) {  /* *** access one past end of buffer */
    ERR("LIMITATION: The configuration strings MUST be nul terminated (even when length is supplied explicitly). qs_len=%d qs(%.*s)", qs_len, qs_len, qs);
    return -1;
  }
  while (*qs) {
    qs += strspn(qs, "& \n\t\r"); /* Skip over & or &&, or line end */
    if (!*qs) break;
    if (*qs == '#')
      goto scan_end;
    
    qs = strchr(name = qs, '=');  /* Scan name (until '=') */
    if (!qs) break;               /* No = ever found and at EOF. No value avail. */
    if (qs == name) {             /* Key was an empty string: skip it */
scan_end:
      qs += strcspn(qs, "&\n\r"); /* Scan value (until '&') */
      continue;
    }
    n = p = name;
    URL_DECODE(p, name, qs);
    *p = 0;
    
    qs += strcspn(val = ++qs, "&\n\r"); /* Skip over = and scan val */
    v = p = val;
    URL_DECODE(p, val, qs);
    if (*qs)
      ++qs;
    *p = 0;
    
    switch (n[0]) {
    case 'A':  /* AUTHN_REQ_SIGN, ACT, AUDIENCE_FATAL, AFTER_SLOP */
      if (!strcmp(n, "AUTO_CERT"))       { SCAN_INT(v, cf->auto_cert); break; }
      if (!strcmp(n, "AUTHN_REQ_SIGN"))  { SCAN_INT(v, cf->authn_req_sign); break; }
      if (!strcmp(n, "ACT"))             { SCAN_INT(v, cf->log_act); break; }
      if (!strcmp(n, "ACT_IN_ERR"))      { SCAN_INT(v, cf->log_err_in_act); break; }
      if (!strcmp(n, "AUDIENCE_FATAL"))  { SCAN_INT(v, cf->audience_fatal); break; }
      if (!strcmp(n, "AFTER_SLOP"))      { SCAN_INT(v, cf->after_slop); break; }
      if (!strcmp(n, "ANON_OK"))         { cf->anon_ok = v; D("anon_ok(%s)", cf->anon_ok); break; }
      if (!strcmp(n, "AN_PAGE"))         { cf->an_page = v; break; }
      if (!strcmp(n, "AN_TEMPL_FILE"))   { cf->an_templ_file = v; break; }
      if (!strcmp(n, "AN_TEMPL"))        { cf->an_templ = v; break; }
      if (!strcmp(n, "ATSEL_PAGE"))      { cf->atsel_page = v; break; }
      if (!strcmp(n, "ATTRSRC"))     { cf->attrsrc = zxid_load_atsrc(cf, cf->attrsrc, v); break; }
      if (!strcmp(n, "A7NTTL"))          { SCAN_INT(v, cf->a7nttl); break; }
      if (!strcmp(n, "AS_ENA"))          { SCAN_INT(v, cf->as_ena); break; }
      goto badcf;
    case 'B':  /* BEFORE_SLOP */
      if (!strcmp(n, "BEFORE_SLOP"))       { SCAN_INT(v, cf->before_slop); break; }
      if (!strcmp(n, "BOOTSTRAP_LEVEL"))   { SCAN_INT(v, cf->bootstrap_level); break; }
      if (!strcmp(n, "BARE_URL_ENTITYID")) { SCAN_INT(v, cf->bare_url_entityid); break; }
      goto badcf;
    case 'C':  /* CDC_URL, CDC_CHOICE */
      if (!strcmp(n, "CDC_URL"))         { cf->cdc_url = v; break; }
      if (!strcmp(n, "CDC_CHOICE"))      { SCAN_INT(v, cf->cdc_choice); break; }
      if (!strcmp(n, "CONTACT_ORG"))     { cf->contact_org = v; break; }
      if (!strcmp(n, "CONTACT_NAME"))    { cf->contact_name = v; break; }
      if (!strcmp(n, "CONTACT_EMAIL"))   { cf->contact_email = v; break; }
      if (!strcmp(n, "CONTACT_TEL"))     { cf->contact_tel = v; break; }
      if (!strcmp(n, "COUNTRY"))         { cf->country = v; break; }
      if (!strcmp(n, "CANON_INOPT"))     { SCAN_INT(v, cf->canon_inopt); if (cf->ctx) cf->ctx->canon_inopt = cf->canon_inopt; break; }
      goto badcf;
    case 'D':  /* DUP_A7N_FATAL, DUP_MSG_FATAL */
      if (!strcmp(n, "DEFAULTQS"))       { cf->defaultqs = v; break; }
      if (!strcmp(n, "DUP_A7N_FATAL"))   { SCAN_INT(v, cf->dup_a7n_fatal); break; }
      if (!strcmp(n, "DUP_MSG_FATAL"))   { SCAN_INT(v, cf->dup_msg_fatal); break; }
      if (!strcmp(n, "DI_ALLOW_CREATE")) { cf->di_allow_create = *v; break; }
      if (!strcmp(n, "DI_NID_FMT"))      { SCAN_INT(v, cf->di_nid_fmt); break; }
      if (!strcmp(n, "DI_A7N_ENC"))      { SCAN_INT(v, cf->di_a7n_enc); break; }
      goto badcf;
    case 'E':  /* ERR, ERR_IN_ACT */
      if (!strcmp(n, "ERR"))             { SCAN_INT(v, cf->log_err); break; }
      if (!strcmp(n, "ERR_IN_ACT"))      { SCAN_INT(v, cf->log_err_in_act); break; }
      if (!strcmp(n, "ENCKEY_OPT"))      { SCAN_INT(v, cf->enckey_opt); break; }
      if (!strcmp(n, "ERR_PAGE"))        { cf->err_page = v; break; }
      if (!strcmp(n, "ERR_TEMPL_FILE"))  { cf->err_templ_file = v; break; }
      if (!strcmp(n, "ERR_TEMPL"))       { cf->err_templ = v; break; }
      goto badcf;
    case 'F':
      if (!strcmp(n, "FEDUSERNAME_SUFFIX")) { cf->fedusername_suffix = v; break; }
      goto badcf;
    case 'I':  /* ISSUE_A7N, ISSUE_MSG */
      if (!strcmp(n, "ISSUE_A7N"))       { SCAN_INT(v, cf->log_issue_a7n); break; }
      if (!strcmp(n, "ISSUE_MSG"))       { SCAN_INT(v, cf->log_issue_msg); break; }
      if (!strcmp(n, "ISSUE_AUTHNCTX_PW")) { cf->issue_authnctx_pw = v; break; }
#if 0
      if (!strcmp(n, "IDP_SEL_START"))   { cf->idp_sel_start = v; break; }
      if (!strcmp(n, "IDP_SEL_NEW_IDP")) { cf->idp_sel_new_idp = v; break; }
      if (!strcmp(n, "IDP_SEL_OUR_EID")) { cf->idp_sel_our_eid = v; break; }
      if (!strcmp(n, "IDP_SEL_TECH_USER")) { cf->idp_sel_tech_user =v; break; }
      if (!strcmp(n, "IDP_SEL_TECH_SITE")) { cf->idp_sel_tech_site =v; break; }
      if (!strcmp(n, "IDP_SEL_FOOTER"))  { cf->idp_sel_footer = v; break; }
      if (!strcmp(n, "IDP_SEL_END"))     { cf->idp_sel_end = v; break; }
#endif
      if (!strcmp(n, "IDP_SEL_PAGE"))    { cf->idp_sel_page = v; break; }
      if (!strcmp(n, "IDP_SEL_TEMPL_FILE")) { cf->idp_sel_templ_file = v; break; }
      if (!strcmp(n, "IDP_SEL_TEMPL"))   { cf->idp_sel_templ = v; break; }
      if (!strcmp(n, "IDP_ENA"))         { SCAN_INT(v, cf->idp_ena); break; }
      if (!strcmp(n, "IMPS_ENA"))        { SCAN_INT(v, cf->imps_ena); break; }
      if (!strcmp(n, "IDP_PREF_ACS_BINDING")) { cf->idp_pref_acs_binding = v; break; }
      if (!strcmp(n, "IDPATOPT"))        { SCAN_INT(v, cf->idpatopt); break; }
      if (!strcmp(n, "IDP_LIST_METH"))   { SCAN_INT(v, cf->idp_list_meth); break; }
      if (!strcmp(n, "INMAP"))           { cf->inmap = zxid_load_map(cf, cf->inmap, v); break; }
      goto badcf;
    case 'L':  /* LEVEL (log level) */
      if (!strcmp(n, "LEVEL"))     { SCAN_INT(v, cf->log_level); break; }
      if (!strcmp(n, "LOGUSER"))   { SCAN_INT(v, cf->loguser); break; }
      if (!strcmp(n, "LOCALPDP_ROLE_PERMIT"))   { cf->localpdp_role_permit   = zxid_load_cstr_list(cf, cf->localpdp_role_permit, v);   break; }
      if (!strcmp(n, "LOCALPDP_ROLE_DENY"))     { cf->localpdp_role_deny     = zxid_load_cstr_list(cf, cf->localpdp_role_deny, v);     break; }
      if (!strcmp(n, "LOCALPDP_IDPNID_PERMIT")) { cf->localpdp_idpnid_permit = zxid_load_cstr_list(cf, cf->localpdp_idpnid_permit, v); break; }
      if (!strcmp(n, "LOCALPDP_IDPNID_DENY"))   { cf->localpdp_idpnid_deny   = zxid_load_cstr_list(cf, cf->localpdp_idpnid_deny, v);   break; }
      if (!strcmp(n, "LOAD_COT_CACHE"))  { cf->load_cot_cache = v; break; }
      if (!strcmp(n, "LOCALITY"))        { cf->locality = v; break; }
      goto badcf;
    case 'M':  /* MD_FETCH, MD_POPULATE_CACHE, MD_CACHE_FIRST, MD_CACHE_LAST */
      if (!strcmp(n, "MANDATORY_ATTR"))    { cf->mandatory_attr = v; break; }
      if (!strcmp(n, "MD_FETCH"))          { SCAN_INT(v, cf->md_fetch); break; }
      if (!strcmp(n, "MD_POPULATE_CACHE")) { SCAN_INT(v, cf->md_populate_cache); break; }
      if (!strcmp(n, "MD_CACHE_FIRST"))    { SCAN_INT(v, cf->md_cache_first); break; }
      if (!strcmp(n, "MD_CACHE_LAST"))     { SCAN_INT(v, cf->md_cache_last); break; }
      if (!strcmp(n, "MGMT_START"))   { cf->mgmt_start = v; break; }
      if (!strcmp(n, "MGMT_LOGOUT"))  { cf->mgmt_logout = v; break; }
      if (!strcmp(n, "MGMT_DEFED"))   { cf->mgmt_defed = v; break; }
      if (!strcmp(n, "MGMT_FOOTER"))  { cf->mgmt_footer = v; break; }
      if (!strcmp(n, "MGMT_END"))     { cf->mgmt_end = v; break; }
      if (!strcmp(n, "MSG_SIG_OK"))   { SCAN_INT(v, cf->msg_sig_ok); break; }
      if (!strcmp(n, "MAX_SOAP_RETRY"))        { SCAN_INT(v, cf->max_soap_retry); break; }
      if (!strcmp(n, "MOD_SAML_ATTR_PREFIX"))  { cf->mod_saml_attr_prefix = v; break; }

      goto badcf;
    case 'N':  /* NAMEID_ENC, NICE_NAME, NOSIG_FATAL */
      if (!strcmp(n, "NAMEID_ENC"))     { SCAN_INT(v, cf->nameid_enc); break; }
      if (!strcmp(n, "NICE_NAME"))      { cf->nice_name = v; break; }
      if (!strcmp(n, "NON_STANDARD_ENTITYID")) { cf->non_standard_entityid = v; break; }
      if (!strcmp(n, "NOSIG_FATAL"))    { SCAN_INT(v, cf->nosig_fatal); break; }
      if (!strcmp(n, "NOTIMESTAMP_FATAL")) { SCAN_INT(v, cf->notimestamp_fatal); break; }
      if (!strcmp(n, "NEED"))           { cf->need = zxid_load_need(cf, cf->need, v); break; }
      if (!strcmp(n, "NEW_USER_PAGE"))  { cf->new_user_page = v; break; }
      goto badcf;
    case 'O':  /* OUTMAP */
      if (!strcmp(n, "OUTMAP"))         { cf->outmap = zxid_load_map(cf, cf->outmap, v); break; }
      if (!strcmp(n, "ORG_NAME"))       { cf->org_name = v; break; }
      if (!strcmp(n, "ORG_URL"))        { cf->org_url = v; break; }
      goto badcf;
    case 'P':  /* PATH (e.g. /var/zxid) */
      DD("PATH maybe n(%s)=v(%s)", n, v);
      if (!strcmp(n, "PATH")) {
	DD("PATH inside file(%.*s) %d new(%s)", cf->path_len, cf->path, cf->path_supplied, v);
	if (cf->path_supplied && !memcmp(cf->path, v, cf->path_len) || cf->path_supplied > 5) {
	  D("Skipping PATH inside file(%.*s) %d", cf->path_len, cf->path, cf->path_supplied);
	  break;
	}
	cf->path = v;
	cf->path_len = strlen(v);
	++cf->path_supplied;
	buf = read_all_alloc(cf->ctx, "-conf_to_cf", 1, &len, "%szxid.conf", cf->path);
	if (buf && len)
	  zxid_parse_conf_raw(cf, len, buf);  /* Recurse */
	break;
      }
      if (!strcmp(n, "PDP_ENA"))        { SCAN_INT(v, cf->pdp_ena); break; }
      if (!strcmp(n, "PDP_URL"))        { cf->pdp_url = v; break; }
      if (!strcmp(n, "PDP_CALL_URL"))   { cf->pdp_call_url = v; break; }
      if (!strcmp(n, "PEPMAP"))         { cf->pepmap = zxid_load_map(cf, cf->pepmap, v); break; }
      if (!strcmp(n, "PEPMAP_RQOUT"))   { cf->pepmap_rqout = zxid_load_map(cf, cf->pepmap_rqout, v); break; }
      if (!strcmp(n, "PEPMAP_RQIN"))    { cf->pepmap_rqin  = zxid_load_map(cf, cf->pepmap_rqin,  v); break; }
      if (!strcmp(n, "PEPMAP_RSOUT"))   { cf->pepmap_rsout = zxid_load_map(cf, cf->pepmap_rsout, v); break; }
      if (!strcmp(n, "PEPMAP_RSIN"))    { cf->pepmap_rsin  = zxid_load_map(cf, cf->pepmap_rsin,  v); break; }
      if (!strcmp(n, "POST_A7N_ENC"))   { SCAN_INT(v, cf->post_a7n_enc); break; }
      if (!strcmp(n, "POST_TEMPL_FILE"))   { cf->post_templ_file = v; break; }
      if (!strcmp(n, "POST_TEMPL"))        { cf->post_templ = v; break; }
      goto badcf;
    case 'R':  /* RELY_A7N, RELY_MSG */
      if (!strcmp(n, "REDIRECT_HACK_IMPOSED_URL")) { cf->redirect_hack_imposed_url = v; break; }
      if (!strcmp(n, "REDIRECT_HACK_ZXID_URL")) {
	cf->redirect_hack_zxid_url = v;
	p = strchr(v, '?');
	if (p) {
	  *p = 0;
	  cf->redirect_hack_zxid_qs = p+1;
	}
	break;
      }
      if (!strcmp(n, "REDIR_TO_CONTENT")) { SCAN_INT(v, cf->redir_to_content); break; }
      if (!strcmp(n, "REMOTE_USER_ENA"))  { SCAN_INT(v, cf->remote_user_ena); break; }
      if (!strcmp(n, "RELY_A7N"))       { SCAN_INT(v, cf->log_rely_a7n); break; }
      if (!strcmp(n, "RELY_MSG"))       { SCAN_INT(v, cf->log_rely_msg); break; }
      if (!strcmp(n, "REQUIRED_AUTHNCTX")) {
	/* Count how many */
        for (i=2, p=v; *p; ++p)
	  if (*p == '$')
	    ++i;
	cf->required_authnctx = zx_zalloc(cf->ctx, sizeof(char*) * i);
	/* Populate array with strings, stomping the separator char $ to nul termination. */
        for (i=0, p=v; *p; ++i) {
	  cf->required_authnctx[i] = p;
	  p = strchr(p, '$');
	  if (!p)
	    break;
	  *p++ = 0;
	}
	break;
      }
      if (!strcmp(n, "RECOVER_PASSWD")) { cf->recover_passwd = v; break; }
      if (!strcmp(n, "RELTO_FATAL"))    { SCAN_INT(v, cf->relto_fatal); break; }
      goto badcf;
    case 'S':  /* SES_ARCH_DIR, SIGFAIL_IS_ERR, SIG_FATAL */
      if (!strcmp(n, "SES_ARCH_DIR"))   { cf->ses_arch_dir = (v[0]=='0' && !v[1]) ? 0 : v; break; }
      if (!strcmp(n, "SES_COOKIE_NAME")) { cf->ses_cookie_name = (v[0]=='0' && !v[1]) ? 0 : v; break; }
      if (!strcmp(n, "SIGFAIL_IS_ERR")) { SCAN_INT(v, cf->log_sigfail_is_err); break; }
      if (!strcmp(n, "SIG_FATAL"))      { SCAN_INT(v, cf->sig_fatal); break; }
      if (!strcmp(n, "SSO_SIGN"))       { SCAN_INT(v, cf->sso_sign); break; }
      if (!strcmp(n, "SSO_SOAP_SIGN"))  { SCAN_INT(v, cf->sso_soap_sign); break; }
      if (!strcmp(n, "SSO_SOAP_RESP_SIGN"))  { SCAN_INT(v, cf->sso_soap_resp_sign); break; }
      if (!strcmp(n, "SHOW_CONF"))      { SCAN_INT(v, cf->show_conf); break; }
      if (!strcmp(n, "SHOW_TECH"))      { SCAN_INT(v, cf->show_tech); break; }
      if (!strcmp(n, "STATE"))          { cf->state = v; break; }
      goto badcf;
    case 'T':  /* TIMEOUT_FATAL */
      if (!strcmp(n, "TIMEOUT_FATAL"))  { SCAN_INT(v, cf->timeout_fatal); break; }
      if (!strcmp(n, "TIMESKEW"))       { SCAN_INT(v, cf->timeskew); break; }
      goto badcf;
    case 'U':  /* URL, USER_LOCAL */
      if (!strcmp(n, "URL"))            { cf->url = v; cf->fedusername_suffix = zxid_grab_domain_name(cf, cf->url); break; }
      if (!strcmp(n, "USER_LOCAL"))     { SCAN_INT(v, cf->user_local); break; }
      goto badcf;
    case 'W':  /* WANT_SSO_A7N_SIGNED */
      if (!strcmp(n, "WANT"))           { cf->want = zxid_load_need(cf, cf->want, v); break; }
      if (!strcmp(n, "WANT_SSO_A7N_SIGNED"))   { SCAN_INT(v, cf->want_sso_a7n_signed); break; }
      if (!strcmp(n, "WANT_AUTHN_REQ_SIGNED")) { SCAN_INT(v, cf->want_authn_req_signed); break; }
      if (!strcmp(n, "WSC_SIGN"))       { SCAN_INT(v, cf->wsc_sign); break; }
      if (!strcmp(n, "WSP_SIGN"))       { SCAN_INT(v, cf->wsp_sign); break; }
      if (!strcmp(n, "WSPCGICMD"))      { cf->wspcgicmd = v; break; }
      if (!strcmp(n, "WSP_NOSIG_FATAL")) { SCAN_INT(v, cf->wsp_nosig_fatal); break; }
      if (!strcmp(n, "WSC_LOCALPDP_OBL_PLEDGE"))  { cf->wsc_localpdp_obl_pledge = v;   break; }
      if (!strcmp(n, "WSP_LOCALPDP_OBL_REQ"))     { cf->wsp_localpdp_obl_req    = v;   break; }
      if (!strcmp(n, "WSP_LOCALPDP_OBL_EMIT"))    { cf->wsp_localpdp_obl_emit   = v;   break; }
      if (!strcmp(n, "WSC_LOCALPDP_OBL_ACCEPT"))  { cf->wsc_localpdp_obl_accept = v;   break; }
      goto badcf;
    case 'X':  /* XASP_VERS */
      if (!strcmp(n, "XASP_VERS"))      { cf->xasp_vers = v; break; }
      goto badcf;
    default:
    badcf:
      ERR("Unknown config option(%s) val(%s), ignored.", n, v);
      zxlog(cf, 0, 0, 0, 0, 0, 0, 0, "N", "S", "BADCF", n, 0);
    }
  }
  return 0;
}

/*() Wrapper with initial error checking for zxid_parse_conf_raw(), which see. */

/* Called by:  opt x7, set_zxid_conf */
int zxid_parse_conf(zxid_conf* cf, char* qs)
{
  if (!cf || !qs)
    return -1;
  return zxid_parse_conf_raw(cf, strlen(qs), qs);
}

#endif

/*() Pretty print need or want chain. */

/* Called by:  zxid_show_conf x2 */
static struct zx_str* zxid_show_need(zxid_conf* cf, struct zxid_need* np)
{
  struct zxid_attr* ap;
  struct zx_str* ss;
  struct zx_str* need = zx_dup_str(cf->ctx, "");
  for (; np; np = np->n) {
    ss = zx_dup_str(cf->ctx, "");
    for (ap = np->at; ap; ap = ap->n) {
      ss = zx_strf(cf->ctx, "%s,%.*s", STRNULLCHK(ap->name), ss->len, ss->s);
    }
    if (ss->len) {  /* chop off last comma separator */
      ss->len -= 1;
      ss->s[ss->len] = 0;
    }
    need = zx_strf(cf->ctx, "  attrs(%s)\n    usage(%s)\n    retent(%s)\n    oblig(%s)\n    ext(%s)$\n%.*s", ss->s, STRNULLCHK(np->usage), STRNULLCHK(np->retent), STRNULLCHK(np->oblig), STRNULLCHK(np->ext),
		   need->len, need->s);
  }
  if (need->len) {  /* chop off last dollar separator */
    need->len -= 2;
    need->s[need->len] = 0;
  }
  return need;
}

/*() Pretty print map chain. */

/* Called by:  zxid_show_conf x3 */
static struct zx_str* zxid_show_map(zxid_conf* cf, struct zxid_map* mp)
{
  struct zx_str* inmap = zx_dup_str(cf->ctx, "");
  for (; mp; mp = mp->n) {
    inmap = zx_strf(cf->ctx, "  rule=%d$ ns(%s)$ src(%s)$ dst(%s)$ ext(%s);\n%.*s", mp->rule, STRNULLCHK(mp->ns), STRNULLCHK(mp->src), STRNULLCHK(mp->dst), STRNULLCHK(mp->ext), inmap->len, inmap->s);
  }
  if (inmap->len) {  /* chop off last semicolon separator */
    inmap->len -= 2;
    inmap->s[inmap->len] = 0;
  }
  return inmap;
}


/*() Pretty print cstr list as used in local PDP. */

/* Called by:  zxid_show_conf x4 */
static struct zx_str* zxid_show_cstr_list(zxid_conf* cf, struct zxid_cstr_list* cp)
{
  struct zx_str* ss = zx_dup_str(cf->ctx, "");
  for (; cp; cp = cp->n) {
    ss = zx_strf(cf->ctx, "  %s,\n%.*s", STRNULLCHK(cp->s), ss->len, ss->s);
  }
  if (ss->len) {  /* chop off last comma separator */
    ss->len -= 2;
    ss->s[ss->len] = 0;
  }
  return ss;
}

/*() Generate our SP CARML and return it as a string. */

/* Called by:  opt, zxid_simple_show_conf */
struct zx_str* zxid_show_conf(zxid_conf* cf)
{
  char* p;
  struct zxid_attr* ap;
  struct zxid_atsrc* sp;
  struct zx_str* ss;
  struct zx_str* required_authnctx;
  struct zx_str* need;
  struct zx_str* want;
  struct zx_str* attrsrc;
  struct zx_str* inmap;
  struct zx_str* outmap;
  struct zx_str* pepmap;
  struct zx_str* pepmap_rqout;
  struct zx_str* pepmap_rqin;
  struct zx_str* pepmap_rsout;
  struct zx_str* pepmap_rsin;
  struct zx_str* localpdp_role_permit;
  struct zx_str* localpdp_role_deny;
  struct zx_str* localpdp_idpnid_permit;
  struct zx_str* localpdp_idpnid_deny;
  if (cf->log_level>0)
    zxlog(cf, 0, 0, 0, 0, 0, 0, 0, "N", "W", "MYCONF", 0, 0);

  if (!cf->show_conf) {
    return zx_strf(cf->ctx, "<title>ZXID Conf disabled</title><body bgcolor=white>ZXID Conf viewing disabled using SHOW_CONF=0 option.");
  }

  /* N.B. The following way of "concatenating" strings leaks memory of the intermediate
   * results. We can't be bothered as the o=d is just a debug page. */

  required_authnctx = zx_dup_str(cf->ctx, "");
  for (p = cf->required_authnctx ? *cf->required_authnctx:0; p; ++p) {
    required_authnctx = zx_strf(cf->ctx, "  %s$\n%.*s", p, required_authnctx->len, required_authnctx->s);
  }
  if (required_authnctx->len) {  /* chop off last dollar separator */
    required_authnctx->len -= 2;
    required_authnctx->s[required_authnctx->len] = 0;
  }

  need = zxid_show_need(cf, cf->need);
  want = zxid_show_need(cf, cf->want);

  attrsrc = zx_dup_str(cf->ctx, "");
  for (sp = cf->attrsrc; sp; sp = sp->n) {
    ss = zx_dup_str(cf->ctx, "");
    for (ap = sp->at; ap; ap = ap->n) {
      ss = zx_strf(cf->ctx, "%s,%.*s", STRNULLCHK(ap->name), ss->len, ss->s);
    }
    if (ss->len) {  /* chop off last dollar separator */
      ss->len -= 1;
      ss->s[ss->len] = 0;
    }
    attrsrc = zx_strf(cf->ctx, "  attrs(%s)\n    ns(%s)\n    weight(%s)\n    url(%s)\n    aapml(%s)\n    otherlim(%s)\n    ext(%s)$\n%.*s", ss->s, STRNULLCHK(sp->ns), STRNULLCHK(sp->weight), STRNULLCHK(sp->url), STRNULLCHK(sp->aapml), STRNULLCHK(sp->otherlim), STRNULLCHK(sp->ext),
		   attrsrc->len, attrsrc->s);
  }
  if (attrsrc->len) {  /* chop off last dollar separator */
    attrsrc->len -= 2;
    attrsrc->s[attrsrc->len] = 0;
  }

  inmap = zxid_show_map(cf, cf->inmap);
  outmap = zxid_show_map(cf, cf->outmap);
  pepmap = zxid_show_map(cf, cf->pepmap);
  pepmap_rqout = zxid_show_map(cf, cf->pepmap_rqout);
  pepmap_rqin  = zxid_show_map(cf, cf->pepmap_rqin);
  pepmap_rsout = zxid_show_map(cf, cf->pepmap_rsout);
  pepmap_rsin  = zxid_show_map(cf, cf->pepmap_rsin);

  localpdp_role_permit   = zxid_show_cstr_list(cf, cf->localpdp_role_permit);
  localpdp_role_deny     = zxid_show_cstr_list(cf, cf->localpdp_role_deny);
  localpdp_idpnid_permit = zxid_show_cstr_list(cf, cf->localpdp_idpnid_permit);
  localpdp_idpnid_deny   = zxid_show_cstr_list(cf, cf->localpdp_idpnid_deny);

  ss = zxid_my_entity_id(cf);

  return zx_strf(cf->ctx,
"<title>ZXID Conf for %s</title><body bgcolor=white><h1>ZXID Conf for %s</h1>"
"<p>Please see config file in %szxid.conf, and documentation in zxid-conf.pd and zxidconf.h\n"
"<p>[ <a href=\"?o=B\">Metadata</a> | <a href=\"?o=c\">CARML</a> | <a href=\"?o=d\">This Conf Dump</a> ]\n"
"<p>Version: R" ZXID_REL " (" ZXID_COMPILE_DATE ")\n"

"<pre>"
"PATH=%s\n"
"URL=%s\n"
"AFFILIATION=%s\n"
"NICE_NAME=%s\n"
"ORG_NAME=%s\n"
"ORG_URL=%s\n"
"LOCALITY=%s\n"
"STATE=%s\n"
"COUNTRY=%s\n"
"CONTACT_ORG=%s\n"
"CONTACT_NAME=%s\n"
"CONTACT_EMAIL=%s\n"
"CONTACT_TEL=%s\n"
"FEDUSERNAME_SUFFIX=%s\n"
"#ZXID_CONF_FILE=%d (compile)\n"
"#ZXID_CONF_FLAG=%d (compile)\n"
"NON_STANDARD_ENTITYID=%s\n"
"REDIRECT_HACK_IMPOSED_URL=%s\n"
"REDIRECT_HACK_ZXID_URL=%s\n"
"REDIRECT_HACK_ZXID_QS=%s\n"
"DEFAULTQS=%s\n"
"CDC_URL=%s\n"
"CDC_CHOICE=%d\n"

"LOAD_COT_CACHE=%s\n"
"MD_FETCH=%d\n"
"MD_POPULATE_CACHE=%d\n"
"MD_CACHE_FIRST=%d\n"
"MD_CACHE_LAST=%d\n"

"AUTO_CERT=%d\n"
"AUTHN_REQ_SIGN=%d\n"
"WANT_AUTHN_REQ_SIGNED=%d\n"
"WANT_SSO_A7N_SIGNED=%d\n"
"SSO_SOAP_SIGN=%d\n"
"SSO_SOAP_RESP_SIGN=%d\n"
"SSO_SIGN=%x\n"
"WSC_SIGN=%x\n"
"WSP_SIGN=%x\n"
"WSPCGICMD=%s\n"
"NAMEID_ENC=%x\n"
"POST_A7N_ENC=%d\n"
"CANON_INOPT=%x\n"
"ENCKEY_OPT=%d\n"
"IDPATOPT=%d\n"
"DI_ALLOW_CREATE=%d\n"
"DI_NID_FMT=%d\n"
"DI_A7N_ENC=%d\n"
"BOOTSTRAP_LEVEL=%d\n"
"SHOW_CONF=%x\n"
"#ZXID_ID_BITS=%d (compile)\n"
"#ZXID_ID_MAX_BITS=%d (compile)\n"
"#ZXID_TRUE_RAND=%d (compile)\n"
"SES_ARCH_DIR=%s\n"
"SES_COOKIE_NAME=%s\n"
"IPPORT=%s\n"
"USER_LOCAL=%d\n"
"IDP_ENA=%d\n"
"IMPS_ENA=%d\n"
"AS_ENA=%d\n"
"PDP_ENA=%d\n"
"#ZXID_MAX_BUF=%d (compile)\n"

"LOG_ERR=%d\n"
"LOG_ACT=%d\n"
"LOG_ISSUE_A7N=%d\n"
"LOG_ISSUE_MSG=%d\n"
"LOG_RELY_A7N=%d\n"
"LOG_RELY_MSG=%d\n"
"LOG_ERR_IN_ACT=%d\n"
"LOG_ACT_IN_ERR=%d\n"
"LOG_SIGFAIL_IS_ERR=%d\n"
"LOG_LEVEL=%d\n"
"LOGUSER=%d\n"

"SIG_FATAL=%d\n"
"NOSIG_FATAL=%d\n"
"MSG_SIG_OK=%d\n"
"TIMEOUT_FATAL=%d\n"
"AUDIENCE_FATAL=%d\n"
"DUP_A7N_FATAL=%d\n"
"DUP_MSG_FATAL=%d\n"
"RELTO_FATAL=%d\n"
"WSP_NOSIG_FATAL=%d\n"
"NOTIMESTAMP_FATAL=%d\n"
"REDIR_TO_CONTENT=%d\n"
"REMOTE_USER_ENA=%d\n"
"MAX_SOAP_RETRY=%d\n"

"BEFORE_SLOP=%d\n"
"AFTER_SLOP=%d\n"
"TIMESKEW=%d\n"
"A7NTTL=%d\n"

"ANON_OK=%s\n"
"ISSUE_AUTHNCTX_PW=%s\n"
"IDP_PREF_ACS_BINDING=%s\n"
"MANDATORY_ATTR=%s\n"
"PDP_URL=%s\n"
"PDP_CALL_URL=%s\n"
"XASP_VERS=%s\n"
"MOD_SAML_ATTR_PREFIX=%s\n"
"BARE_URL_ENTITYID=%d\n"
"SHOW_TECH=%d\n"

"IDP_LIST_METH=%d\n"
"IDP_SEL_PAGE=%s\n"
"IDP_SEL_TEMPL_FILE=%s\n"
"</pre>"
"<textarea cols=100 rows=20>"
"IDP_SEL_TEMPL=%s\n"
#if 0
"IDP_SEL_START=%s\n"
"IDP_SEL_NEW_IDP=%s\n"
"IDP_SEL_OUR_EID=%s\n"
"IDP_SEL_TECH_USER=%s\n"
"IDP_SEL_TECH_SITE=%s\n"
"IDP_SEL_FOOTER=%s\n"
"IDP_SEL_END=%s\n"
#endif
"</textarea><pre>\n"

"AN_PAGE=%s\n"
"AN_TEMPL_FILE=%s\n"
"</pre><textarea cols=100 rows=20>"
"AN_TEMPL=%s\n"
"</textarea><pre>\n"

"POST_TEMPL_FILE=%s\n"
"</pre><textarea cols=100 rows=7>"
"POST_TEMPL=%s\n"
"</textarea><pre>\n"

"ERR_PAGE=%s\n"
"ERR_TEMPL_FILE=%s\n"
"</pre><textarea cols=100 rows=7>"
"ERR_TEMPL=%s\n"
"</textarea><pre>\n"

"NEW_USER_PAGE=%s\n"
"RECOVER_PASSWD=%s\n"
"ATSEL_PAGE=%s\n"

"</pre><textarea cols=100 rows=15>"
"MGMT_START=%s\n"
"MGMT_LOGOUT=%s\n"
"MGMT_DEFED=%s\n"
"MGMT_FOOTER=%s\n"
"MGMT_END=%s\n"
"</textarea>"

"<pre>\n"
"DBG=%s\n"

"REQUIRED_AUTHN_CTX=\n%s\n"
"NEED=\n%s\n"
"WANT=\n%s\n"
"ATTRSRC=\n%s\n"
"INMAP=\n%s\n"
"OUTMAP=\n%s\n"
"PEPMAP=\n%s\n"
"PEPMAP_RQOUT=\n%s\n"
"PEPMAP_RQIN=\n%s\n"
"PEPMAP_RSOUT=\n%s\n"
"PEPMAP_RSIN=\n%s\n"
"LOCALPDP_ROLE_PERMIT=\n%s\n"
"LOCALPDP_ROLE_DENY=\n%s\n"
"LOCALPDP_IDPNID_PERMIT=\n%s\n"
"LOCALPDP_IDPNID_DENY=\n%s\n"
"WSC_LOCALPDP_OBL_PLEDGE=%s\n"
"WSP_LOCALPDP_OBL_REQ=%s\n"
"WSP_LOCALPDP_OBL_EMIT=%s\n"
"WSC_LOCALPDP_OBL_ACCEPT=%s\n"
"</pre>",
		 cf->url, ss->s,
		 cf->path,

		 cf->path,
		 cf->url,
		 STRNULLCHK(cf->affiliation),
		 STRNULLCHK(cf->nice_name),
		 STRNULLCHK(cf->org_name),
		 STRNULLCHK(cf->org_url),
		 STRNULLCHK(cf->locality),
		 STRNULLCHK(cf->state),
		 STRNULLCHK(cf->country),
		 STRNULLCHK(cf->contact_org),
		 STRNULLCHK(cf->contact_name),
		 STRNULLCHK(cf->contact_email),
		 STRNULLCHK(cf->contact_tel),
		 STRNULLCHK(cf->fedusername_suffix),
		 ZXID_CONF_FILE,
		 ZXID_CONF_FLAG,
		 STRNULLCHK(cf->non_standard_entityid),
		 STRNULLCHK(cf->redirect_hack_imposed_url),
		 STRNULLCHK(cf->redirect_hack_zxid_url),
		 STRNULLCHK(cf->redirect_hack_zxid_qs),
		 STRNULLCHK(cf->defaultqs),
		 STRNULLCHK(cf->cdc_url),
		 cf->cdc_choice,

		 STRNULLCHK(cf->load_cot_cache),
		 cf->md_fetch,
		 cf->md_populate_cache,
		 cf->md_cache_first,
		 cf->md_cache_last,

		 cf->auto_cert,
		 cf->authn_req_sign,
		 cf->want_authn_req_signed,
		 cf->want_sso_a7n_signed,
		 cf->sso_soap_sign,
		 cf->sso_soap_resp_sign,
		 cf->sso_sign,
		 cf->wsc_sign,
		 cf->wsp_sign,
		 cf->wspcgicmd,
		 cf->nameid_enc,
		 cf->post_a7n_enc,
		 cf->canon_inopt,
		 cf->enckey_opt,
		 cf->idpatopt,
		 cf->di_allow_create,
		 cf->di_nid_fmt,
		 cf->di_a7n_enc,
		 cf->bootstrap_level,
		 cf->show_conf,
		 ZXID_ID_BITS,
		 ZXID_ID_MAX_BITS,
		 ZXID_TRUE_RAND,
		 STRNULLCHK(cf->ses_arch_dir),
		 STRNULLCHK(cf->ses_cookie_name),
		 STRNULLCHK(cf->ipport),
		 cf->user_local,
		 cf->idp_ena,
		 cf->imps_ena,
		 cf->as_ena,
		 cf->pdp_ena,
		 ZXID_MAX_BUF,

		 cf->log_err,
		 cf->log_act,
		 cf->log_issue_a7n,
		 cf->log_issue_msg,
		 cf->log_rely_a7n,
		 cf->log_rely_msg,
		 cf->log_err_in_act,
		 cf->log_act_in_err,
		 cf->log_sigfail_is_err,
		 cf->log_level,
		 cf->loguser,
  
		 cf->sig_fatal,
		 cf->nosig_fatal,
		 cf->msg_sig_ok,
		 cf->timeout_fatal,
		 cf->audience_fatal,
		 cf->dup_a7n_fatal,
		 cf->dup_msg_fatal,
		 cf->relto_fatal,
		 cf->wsp_nosig_fatal,
		 cf->notimestamp_fatal,
		 cf->redir_to_content,
		 cf->remote_user_ena,
		 cf->max_soap_retry,

		 cf->before_slop,
		 cf->after_slop,
		 cf->timeskew,
		 cf->a7nttl,

		 STRNULLCHK(cf->anon_ok),
		 STRNULLCHK(cf->issue_authnctx_pw),
		 STRNULLCHK(cf->idp_pref_acs_binding),
		 STRNULLCHK(cf->mandatory_attr),
		 STRNULLCHK(cf->pdp_url),
		 STRNULLCHK(cf->pdp_call_url),
		 STRNULLCHK(cf->xasp_vers),
		 STRNULLCHK(cf->mod_saml_attr_prefix),
		 cf->bare_url_entityid,
		 cf->show_tech,

		 cf->idp_list_meth,
		 STRNULLCHK(cf->idp_sel_page),
		 STRNULLCHK(cf->idp_sel_templ_file),
		 STRNULLCHK(cf->idp_sel_templ),
#if 0
		 STRNULLCHK(cf->idp_sel_start),
		 STRNULLCHK(cf->idp_sel_new_idp),
		 STRNULLCHK(cf->idp_sel_our_eid),
		 STRNULLCHK(cf->idp_sel_tech_user),
		 STRNULLCHK(cf->idp_sel_tech_site),
		 STRNULLCHK(cf->idp_sel_footer),
		 STRNULLCHK(cf->idp_sel_end),
#endif
		 STRNULLCHK(cf->an_page),
		 STRNULLCHK(cf->an_templ_file),
		 STRNULLCHK(cf->an_templ),

		 STRNULLCHK(cf->post_templ_file),
		 STRNULLCHK(cf->post_templ),

		 STRNULLCHK(cf->err_page),
		 STRNULLCHK(cf->err_templ_file),
		 STRNULLCHK(cf->err_templ),

		 STRNULLCHK(cf->new_user_page),
		 STRNULLCHK(cf->recover_passwd),
		 STRNULLCHK(cf->atsel_page),

		 STRNULLCHK(cf->mgmt_start),
		 STRNULLCHK(cf->mgmt_logout),
		 STRNULLCHK(cf->mgmt_defed),
		 STRNULLCHK(cf->mgmt_footer),
		 STRNULLCHK(cf->mgmt_end),

		 STRNULLCHK(cf->dbg),

		 required_authnctx->s,
		 need->s,
		 want->s,
		 attrsrc->s,
		 inmap->s,
		 outmap->s,
		 pepmap->s,
		 pepmap_rqout->s,
		 pepmap_rqin->s,
		 pepmap_rsout->s,
		 pepmap_rsin->s,
		 localpdp_role_permit->s,
		 localpdp_role_deny->s,
		 localpdp_idpnid_permit->s,
		 localpdp_idpnid_deny->s,
		 STRNULLCHK(cf->wsc_localpdp_obl_pledge),
		 STRNULLCHK(cf->wsp_localpdp_obl_req),
		 STRNULLCHK(cf->wsp_localpdp_obl_emit),
		 STRNULLCHK(cf->wsc_localpdp_obl_accept)
	 );
}

/* EOF  --  zxidconf.c */
