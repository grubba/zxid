/* zxlib.c  -  Utility functions for generated (and other) code
 * Copyright (c) 2010 Sampo Kellomaki (sampo@iki.fi), All Rights Reserved.
 * Copyright (c) 2006-2009 Symlabs (symlabs@symlabs.com), All Rights Reserved.
 * Author: Sampo Kellomaki (sampo@iki.fi)
 * This is confidential unpublished proprietary source code of the author.
 * NO WARRANTY, not even implied warranties. Contains trade secrets.
 * Distribution prohibited unless authorized in writing.
 * Licensed under Apache License 2.0, see file COPYING.
 * $Id: zxlib.c,v 1.41 2009-11-24 23:53:40 sampo Exp $
 *
 * 28.5.2006, created --Sampo
 * 8.8.2006,  moved lookup functions to generated code --Sampo
 * 12.8.2006, added special scanning of xmlns to avoid backtracking elem recognition --Sampo
 * 26.8.2006, significant Common Subexpression Elimination (CSE) --Sampo
 * 30.9.2007, more CSE --Sampo
 * 7.10.2008, added documentation --Sampo
 * 26.5.2010, added XML parse error reporting --Sampo
 */

#include "platform.h"  /* needed on Win32 for snprintf(), va_copy() et al. */

//#include <pthread.h>
//#ifndef MACOSX
//#include <malloc.h>
//#endif
#include <memory.h>
#include <string.h>
#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>

#include "errmac.h"
#include "zx.h"
#include "c/zx-data.h"  /* Also generic zx_simple_elem, etc. */

/*() Format error message describing an XML parse error. The buf argument
 * should be at leaset 256 bytes for satisfactory results. */

/* Called by:  zxid_wsp_validate */
int zx_format_parse_error(struct zx_ctx* ctx, char* buf, int siz, char* logkey)
{
  int at, end, start, len;
  end = ctx->lim - ctx->bas;
  at = MIN(ctx->p - ctx->bas, end);
  start = MAX(0,at-30);
  len = MIN(at+30, end) - start;    
  len = snprintf(buf, siz, "%s: Parse error at char %d/%d (prev char, char, next char: 0x%02x 0x%02x 0x%02x)\n%.*s\n%.*s^\n", logkey, at, end, at > 0 ? ctx->p[-1]:0, ctx->p[0], at < end ? ctx->p[1]:0, len, ctx->bas + start, at-start, "-----------------------------------------------");
  buf[siz-1] = 0; /* must terminate manually as on win32 nul is not guaranteed */
  return len;
}

/*() ZX implementation of memmem(3) for platforms that do not have this. */

/* Called by:  zxid_map_sec_mech x3 */
char* zx_memmem(const char* haystack, int haystack_len, const char* needle, int needle_len)
{
  const char* lim = haystack + haystack_len - needle_len;
  for (; haystack < lim; ++haystack)
    if (!memcmp(haystack, needle, needle_len))
      return (char*)haystack; /* discards const qualifier, but is right if haystack was modifiable, as often is the case. */
  return 0;
}

/*() ZX memory allocator that does not zero the buffer. Allocation is
 * potentially done relative to ZX context <<italic: c>>, though
 * actual (2008) implementation simply uses malloc(3).
 *
 * Rather than reference this function directly, you should
 * use the ZX_ALLOC() macro as much as possible.
 *
 * Some implementations may take c->mx mutex lock. However, they will
 * do so such that no deadlock will result even if already taken. */

/* Called by:  zx_zalloc */
void* zx_alloc(struct zx_ctx* c, int size)
{
  char* p;
  p = malloc(size);
  DD("malloc %p size=%d", p, size);
  if (!p) {
    ERR("Out-of-memory(%d)", size);
    if (size < 0)
      DIE_ACTION(1);
    exit(1);
  }
  return p;
}

/*() ZX memory allocator that zeroes the buffer. Allocation is
 * potentially done relative to ZX context <<italic: c>>, though
 * actual (2008) implementation simply uses malloc(3).
 *
 * Rather than reference this function directly, you should
 * use the ZX_ALLOC() macro as much as possible. */

/* Called by:  zxid_parse_conf_raw */
void* zx_zalloc(struct zx_ctx* c, int size)
{
  char* p = zx_alloc(c, size);
  ZERO(p, size);
  return p;
}


/*() ZX memory free'er. Freeing is
 * potentially done relative to ZX context <<italic: c>>, though
 * actual (2008) implementation simply uses free(3).
 *
 * Rather than reference this function directly, you should
 * use the ZX_FREE() macro as much as possible. */

/* Called by: */
void* zx_free(struct zx_ctx* c, void* p)
{
  if (p)
    free(p);
  return 0;
}

/*() Convert zx_str to C string. The ZX context will provide the memory. */

/* Called by:  zxid_add_a7n_at_to_pool x2, zxid_get_meta_ss, zxid_get_ses_sso_a7n, zxid_get_tas3_fault_actor, zxid_get_tas3_fault_comment, zxid_get_tas3_fault_ref, zxid_get_tas3_fault_sc1, zxid_get_tas3_fault_sc2, zxid_get_tas3_status_comment, zxid_get_tas3_status_ctlpt, zxid_get_tas3_status_ref, zxid_get_tas3_status_sc1, zxid_get_tas3_status_sc2, zxid_idp_sso, zxid_mk_ent x2, zxid_simple_idp_show_an, zxid_sp_sso_finalize x3, zxid_wsf_validate_a7n x2, zxid_wsp_validate */
char* zx_str_to_c(struct zx_ctx* c, struct zx_str* ss)
{
  char* p = ZX_ALLOC(c, ss->len+1);
  memcpy(p, ss->s, ss->len);
  p[ss->len] = 0;
  return p;
}

/*() zx_str_conv() helps SWIG typemaps to achieve natural conversion
 * to native length + data representations of scripting languages.
 * Should not need to use directly. */

/* Called by: */
void zx_str_conv(struct zx_str* ss, int* out_len, char** out_s)  /* SWIG typemap friendly */
{
  *out_s = 0;
  *out_len = 0;
  if (!ss)
    return;
  *out_s = ss->s;
  *out_len = ss->len;
}

/*() Free both the zx_str node and the underlying string data */

/* Called by:  main, zxenc_privkey_dec, zxenc_pubkey_enc, zxenc_symkey_enc, zxid_addmd x3, zxid_anoint_a7n x5, zxid_anoint_sso_resp x4, zxid_cache_epr, zxid_decode_redir_or_post, zxid_fed_mgmt_cf x3, zxid_idp_dispatch x2, zxid_idp_list_cf_cgi x3, zxid_idp_soap, zxid_idp_soap_dispatch x2, zxid_idp_sso x4, zxid_lecp_check, zxid_mgmt x3, zxid_mk_art_deref, zxid_mk_enc_a7n, zxid_mk_enc_id, zxid_mk_mni, zxid_pep_az_soap x3, zxid_reg_svc x3, zxid_saml2_post_enc x2, zxid_saml2_redir, zxid_saml2_redir_enc x2, zxid_saml2_redir_url, zxid_saml2_resp_redir, zxid_send_sp_meta, zxid_simple_idp_show_an, zxid_simple_no_ses_cf x3, zxid_simple_ses_active_cf, zxid_simple_show_page x3, zxid_slo_resp_redir, zxid_snarf_eprs_from_ses, zxid_soap_call_envelope, zxid_soap_call_hdr_body, zxid_soap_cgi_resp_body x2, zxid_sp_dispatch x2, zxid_sp_mni_soap, zxid_sp_slo_soap, zxid_sp_soap, zxid_sp_soap_dispatch x6, zxid_start_sso_location, zxid_user_sha1_name, zxid_write_ent_to_cache, zxsig_sign */
void zx_str_free(struct zx_ctx* c, struct zx_str* ss)
{
  if (ss->s)
    ZX_FREE(c, ss->s);
  ZX_FREE(c, ss);
}

/*() Construct zx_str from length and raw string data, which will be referenced, not copied. */

/* Called by:  zx_easy_enc_common, zx_ref_len_simple_elem, zx_ref_str, zx_strf, zxid_http_post_raw, zxid_saml2_redir_enc x2, zxlog_path */
struct zx_str* zx_ref_len_str(struct zx_ctx* c, int len, const char* s)
{
  struct zx_str* ss = ZX_ZALLOC(c, struct zx_str);
  ss->s = (char*)s;  /* ref points to underlying data */
  ss->len = len;
  return ss;
}

/*() Construct zx_str from C string, which will be referenced, not copied. */

/* Called by:  pool2apache x2, test_ibm_cert_problem_enc_dec x3, zxenc_pubkey_enc, zxenc_symkey_enc x3, zxid_ac_desc x2, zxid_add_header_refs x29, zxid_ar_desc, zxid_check_fed, zxid_idp_sso_desc x2, zxid_ins_xacml_az_cd1_stmt, zxid_ins_xacml_az_stmt, zxid_issuer, zxid_key_desc x2, zxid_mk_Status x2, zxid_mk_art_deref, zxid_mk_authn_req x10, zxid_mk_az, zxid_mk_az_cd1, zxid_mk_dap_query, zxid_mk_dap_query_item x8, zxid_mk_dap_resquery x6, zxid_mk_dap_select x2, zxid_mk_dap_subscription x7, zxid_mk_dap_test_item x2, zxid_mk_dap_testop x2, zxid_mk_di_req_svc x2, zxid_mk_ecp_Request_hdr x2, zxid_mk_idp_list x2, zxid_mk_logout, zxid_mk_logout_resp, zxid_mk_mni, zxid_mk_mni_resp, zxid_mk_paos_Request_hdr x3, zxid_mk_xacml_resp, zxid_mni_desc, zxid_org_desc x8, zxid_pep_az_soap x10, zxid_pool_to_json x2, zxid_pool_to_ldif x2, zxid_pool_to_qs x2, zxid_simple_ses_active_cf x2, zxid_slo_desc, zxid_sp_sso_desc x3, zxid_sso_desc, zxid_wsc_prep x8, zxid_wsc_prep_secmech, zxid_wsf_decor x26, zxid_wsf_sign x2, zxsig_sign x5 */
struct zx_str* zx_ref_str(struct zx_ctx* c, const char* s)
{
  if (!s)
    return 0;
  return zx_ref_len_str(c, strlen(s), s);
}

/*() Newly allocated string (node and data) of specified length, but uninitialized */

/* Called by:  zx_EVP_CIPHER_key_length, zx_dup_len_str, zx_rsa_priv_dec, zx_rsa_priv_enc, zx_rsa_pub_dec, zx_rsa_pub_enc, zxenc_pubkey_enc, zxenc_symkey_enc, zxid_map_val x5, zxid_pool_to_json, zxid_pool_to_ldif, zxid_pool_to_qs, zxid_template_page_cf, zxsig_sign x2 */
struct zx_str* zx_new_len_str(struct zx_ctx* c, int len)
{
  struct zx_str* ss = ZX_ZALLOC(c, struct zx_str);
  ss->s = ZX_ALLOC(c, len+1);
  ss->s[len] = 0;
  ss->len = len;
  return ss;
}

/*() Construct zx_str by duplication of raw string data of given length. */

/* Called by:  zx_dup_len_simple_elem, zx_dup_str, zxid_add_ldif_attrs_to_ses */
struct zx_str* zx_dup_len_str(struct zx_ctx* c, int len, const char* s)
{
  struct zx_str* ss = zx_new_len_str(c, len);
  memcpy(ss->s, s, len);
  return ss;
}

/*() Construct zx_str by duplication of C string. */

/* Called by:  zxid_add_attr_to_ses, zxid_add_qs_to_ses, zxid_anoint_a7n x2, zxid_anoint_sso_resp x3, zxid_as_call_ses, zxid_fed_mgmt_cf, zxid_get_at x2, zxid_idp_dispatch x8, zxid_idp_list_cf_cgi x2, zxid_idp_select_zxstr_cf_cgi, zxid_idp_sso x15, zxid_map_val, zxid_mk_a7n, zxid_mk_an_stmt, zxid_mk_attribute x2, zxid_mk_authn_req, zxid_mk_lu_Status x3, zxid_mk_saml_resp, zxid_mk_subj, zxid_mk_tas3_Status x5, zxid_mk_transient_nid, zxid_mk_user_a7n_to_sp, zxid_new_epr, zxid_parse_mni x4, zxid_pep_az_soap x11, zxid_saml2_redir, zxid_saml2_resp_redir, zxid_ses_to_pool x10, zxid_show_conf x3, zxid_show_cstr_list, zxid_show_map, zxid_show_need x2, zxid_simple_ab_pep x3, zxid_slo_resp_redir, zxid_sp_dispatch x15, zxid_sp_mni_redir x3, zxid_sp_slo_redir x3, zxid_start_sso_location, zxid_wsc_prep */
struct zx_str* zx_dup_str(struct zx_ctx* c, const char* s)
{
  return zx_dup_len_str(c, strlen(s), s);
}

/*() ZX verion of strdup(). */

/* Called by:  chkuid x2, zxid_az_cf_ses, zxid_fed_mgmt_cf, zxid_get_ses, zxid_simple_cf_ses x2, zxid_simple_no_ses_cf, zxid_simple_redir_page, zxid_simple_ses_active_cf, zxid_simple_show_page x2, zxid_url_set */
char* zx_dup_cstr(struct zx_ctx* c, const char* str)
{
  int len = strlen(str);
  char* s = ZX_ALLOC(c, len+1);
  memcpy(s, str, len+1);
  return s;
}

/*() vasprintf(3) implementation that will grab its memory from ZX memory allocator. */

/* Called by:  zx_alloc_sprintf, zx_strf, zxid_callf, zxid_wsc_prepare_callf, zxid_wsp_decoratef */
char* zx_alloc_vasprintf(struct zx_ctx* c, int* retlen, const char* f, va_list ap) /* data is new memory */
{
  va_list ap2;
  int len;
  char* s;
  char buf[2]; 
  va_copy(ap2, ap);
  len = vsnprintf(buf, 1, f, ap2);
  va_end(ap2);
  if (len < 0) {
    perror("vsnprintf");
    D("Broken vsnprintf? Impossible to compute length of string. Be sure to `export LANG=C' if you get errors about multibyte characters. Length returned: %d", len);
    if (retlen)
      *retlen = 0;
    s = ZX_ALLOC(c, 1);
    s[0] = 0;
    return s;
  }
  s = ZX_ALLOC(c, len+1);
  vsnprintf(s, len+1, f, ap);
  s[len] = 0; /* must terminate manually as on win32 nul termination is not guaranteed */
  if (retlen)
    *retlen = len;
  return s;
}

/*() sprintf(3) implementation that will grab its memory from ZX memory allocator. */

/* Called by:  main x2, zxid_add_env_if_needed, zxid_pw_authn x2, zxid_simple_no_ses_cf x2 */
char* zx_alloc_sprintf(struct zx_ctx* c, int* retlen, const char* f, ...)  /* data is new memory */
{
  char* ret;
  va_list ap;
  va_start(ap, f);
  ret = zx_alloc_vasprintf(c, retlen, f, ap);
  va_end(ap);
  return ret;
}

/*(i) Construct zx_str given sprintf(3) format and grabbing memory from ZX memory allocator. */

/* Called by:  chkuid, zx_prefix_seen_whine, zxenc_pubkey_enc x3, zxenc_symkey_enc, zxid_ac_desc, zxid_ar_desc x2, zxid_date_time x2, zxid_decode_redir_or_post x5, zxid_fed_mgmt_cf x4, zxid_idp_list_cf_cgi x6, zxid_idp_select_zxstr_cf_cgi x3, zxid_idp_sso x3, zxid_idp_sso_desc, zxid_lecp_check, zxid_mk_dap_query_item x2, zxid_mk_dap_select x4, zxid_mk_dap_testop x4, zxid_mk_di_req_svc, zxid_mk_id, zxid_mk_paos_Request_hdr, zxid_mni_desc x2, zxid_my_cdc_url, zxid_my_entity_id x3, zxid_saml2_post_enc, zxid_saml2_redir, zxid_saml2_redir_url, zxid_saml2_resp_redir, zxid_saml_ok, zxid_ses_to_pool x5, zxid_show_conf x5, zxid_show_cstr_list, zxid_show_map, zxid_show_need x2, zxid_simple_idp_an_ok_do_rest, zxid_simple_idp_new_user, zxid_simple_idp_recover_password, zxid_simple_idp_show_an x2, zxid_simple_no_ses_cf, zxid_simple_redir_page, zxid_simple_show_page, zxid_slo_desc x2, zxid_sp_carml, zxid_sp_sso_desc, zxid_sso_desc x2, zxid_start_sso_location, zxid_user_sha1_name, zxid_wsc_prep, zxid_wsf_decor, zxsig_sign */
struct zx_str* zx_strf(struct zx_ctx* c, const char* f, ...)  /* data is new memory */
{
  va_list ap;
  int len;
  char* s;
  va_start(ap, f);
  s = zx_alloc_vasprintf(c, &len, f, ap);
  va_end(ap);
  return zx_ref_len_str(c, len, s);
}

/*() Check if string ends in suffix */

/* Called by: */
int zx_str_ends_in(struct zx_str* ss, int len, const char* suffix)
{
  return !memcmp(ss->s + ss->len - len, suffix, len);
}

/*() Construct new simple element from zx_str by referencing, not copying, it. */

/* Called by:  main, zx_dup_len_simple_elem, zx_ref_len_simple_elem, zxenc_pubkey_enc, zxenc_symkey_enc, zxid_mk_a7n, zxid_mk_logout, zxid_mk_mni x4, zxid_mk_xacml_simple_at, zxsig_sign */
struct zx_elem_s* zx_new_simple_elem(struct zx_ctx* c, struct zx_str* ss)
{
  struct zx_elem_s* el;
  el = ZX_ZALLOC(c, struct zx_elem_s);
  el->content = ss;
  return el;
}

/*() Construct new simple element by referencing, not copying, raw string data of given length. */

/* Called by:  zx_ref_simple_elem, zxid_as_call_ses, zxid_key_desc, zxid_key_info */
struct zx_elem_s* zx_ref_len_simple_elem(struct zx_ctx* c, int len, const char* s)
{
  return zx_new_simple_elem(c, zx_ref_len_str(c, len, s));
}

/*() Construct new simple element by referencing, not copying, C string. */

/* Called by:  main, zxid_contact_desc x6, zxid_idp_sso_desc x2, zxid_mk_Status, zxid_mk_art_deref, zxid_mk_authn_req, zxid_mk_dap_query_item x4, zxid_mk_dap_resquery x4, zxid_mk_dap_select x2, zxid_mk_dap_subscription x2, zxid_mk_dap_testop x2, zxid_mk_di_req_svc x6, zxid_mk_xacml_resp, zxid_sp_sso_desc x2 */
struct zx_elem_s* zx_ref_simple_elem(struct zx_ctx* c, const char* s)
{
  return zx_ref_len_simple_elem(c, strlen(s), s);
}

/* Called by:  zx_dup_simple_elem */
struct zx_elem_s* zx_dup_len_simple_elem(struct zx_ctx* c, int len, const char* s)
{
  return zx_new_simple_elem(c, zx_dup_len_str(c, len, s));
}

/* Called by:  zxid_add_fed_tok_to_epr, zxid_mk_an_stmt, zxid_mk_fault x3, zxid_new_epr x3 */
struct zx_elem_s* zx_dup_simple_elem(struct zx_ctx* c, const char* s)
{
  return zx_dup_len_simple_elem(c, strlen(s), s);
}

/* ------------- Common Subexpression Elimination for generated code ------------- */

/*() Render the unknown attributes list. CSE for almost all tags. */

/* Called by:  TXLEN_SO_ELNAME */
int zx_len_so_common(struct zx_ctx* c, struct zx_elem_s* x, struct zx_ns_s** pop_seenp)
{
  int len = 0;
  struct zx_str* ss;
  struct zx_any_attr_s* aa;
  struct zx_any_elem_s* ae;
  
  for (aa = x->any_attr; aa; aa = (struct zx_any_attr_s*)aa->ss.g.n) {  /* unknown attributes */
    if (aa->ss.g.ns && aa->ss.g.ns->prefix_len)
      len += aa->ss.g.ns->prefix_len + 1;
    len += 1 + aa->name_len + 1 + 1 + aa->ss.len + 1;  /* attr="val" */
    len += zx_len_xmlns_if_not_seen(c, aa->ss.g.ns, pop_seenp);
  }

  for (ae = x->any_elem; ae; ae = (struct zx_any_elem_s*)ae->gg.g.n)    /* unknown elements */
    len += zx_LEN_SO_simple_elem(c, &ae->gg, ae->name_len, ae->gg.g.ns);
  
  for (ss = x->content; ss; ss = (struct zx_str*)ss->g.n)             /* content */
    len += ss->len;
  
  return len;
}

/* Called by:  TXLEN_WO_ELNAME, TXLEN_WO_any_elem */
int zx_len_wo_common(struct zx_ctx* c, struct zx_elem_s* x, struct zx_ns_s** pop_seenp)
{
  int len = 0;
  struct zx_str* ss;
  struct zx_any_attr_s* aa;
  struct zx_any_elem_s* ae;
  
  for (aa = x->any_attr; aa; aa = (struct zx_any_attr_s*)aa->ss.g.n) {  /* unknown attributes */
    if (aa->ss.g.ns && aa->ss.g.ns->prefix_len)
      len += aa->ss.g.ns->prefix_len + 1;
    len += 1 + aa->name_len + 1 + 1 + aa->ss.len + 1;  /* attr="val" */
    len += zx_len_xmlns_if_not_seen(c, aa->ss.g.ns, pop_seenp);
  }

  for (ae = x->any_elem; ae; ae = (struct zx_any_elem_s*)ae->gg.g.n)    /* unknown elements */
    len += zx_LEN_WO_simple_elem(c, &ae->gg, ae->name_len);
  
  for (ss = x->content; ss; ss = (struct zx_str*)ss->g.n)             /* content */
    len += ss->len;
  
  return len;
}

void zx_see_unknown_attrs_ns(struct zx_ctx* c, struct zx_any_attr_s* aa, struct zx_ns_s** pop_seenp)
{
  for (; aa; aa = (struct zx_any_attr_s*)aa->ss.g.n) {  /* unknown attributes */
     zx_add_xmlns_if_not_seen(c, aa->ss.g.ns, pop_seenp);
  }
}

/* Called by:  TXENC_SO_ELNAME, TXENC_WO_ELNAME, TXENC_WO_any_elem */
char* zx_enc_unknown_attrs(char* p, struct zx_any_attr_s* aa)
{
  for (; aa; aa = (struct zx_any_attr_s*)aa->ss.g.n) {  /* unknown attributes */
    ZX_OUT_CH(p, ' ');
    if (aa->ss.g.ns && aa->ss.g.ns->prefix_len) {
      ZX_OUT_MEM(p, aa->ss.g.ns->prefix, aa->ss.g.ns->prefix_len);
      ZX_OUT_CH(p, ':');
    }
    
    ZX_OUT_MEM(p, aa->name, aa->name_len);
    ZX_OUT_CH(p, '=');
    ZX_OUT_CH(p, '"');
    ZX_OUT_MEM(p, aa->ss.s, aa->ss.len);
    ZX_OUT_CH(p, '"');
  }
  ZX_OUT_CH(p, '>');
  return p;
}

/* Called by:  TXENC_SO_ELNAME */
char* zx_enc_so_unknown_elems_and_content(struct zx_ctx* c, char* p, struct zx_elem_s* x)
{
  struct zx_str* ss;
  struct zx_any_elem_s* ae;
  
  for (ae = x->any_elem; ae; ae = (struct zx_any_elem_s*)ae->gg.g.n)    /* unknown elements */
    p = zx_ENC_SO_simple_elem(c, &ae->gg, p, ae->name, ae->name_len, ae->gg.g.ns);
  
  for (ss = x->content; ss; ss = (struct zx_str*)ss->g.n)             /* content */
    ZX_OUT_MEM(p, ss->s, ss->len);
  
  return p;
}

/* Called by:  TXEASY_ENC_SO_ELNAME, TXEASY_ENC_WO_ELNAME, TXEASY_ENC_WO_any_elem */
struct zx_str* zx_easy_enc_common(struct zx_ctx* c, char* p, char* buf, int len)
{
  if (p != buf+len) {
    ERR("Encoded length(%d) does not match computed length(%d). ED(%.*s)", p-buf, len, p-buf, buf);
    len = p-buf;
  }
  buf[len] = 0;
  return zx_ref_len_str(c, len, buf);
}

/* Called by: */
int zx_attr_so_len(struct zx_ctx* c, struct zx_str* attr, int name_size, struct zx_ns_s** pop_seenp)
{
  int len = 0;
  if (attr)
    len += zx_len_xmlns_if_not_seen(c, attr->g.ns, pop_seenp);
  /* In legal XML there should really be just one attribute, but we accommodate multioccurances. */
  for (; attr; attr = (struct zx_str*)attr->g.n)
    len += 1 + name_size + 1 + 1 + attr->len + 1;
  return len;
}

/* Both attribute name and the namespace prefix are known at compile time
 * and are passed in in name and name_len. */
/* Called by: */
char* zx_attr_so_enc(char* p, struct zx_str* attr, char* name, int name_len)
{
  /* In legal XML there should really be just one attribute, but we accommodate multioccurances. */
  for (; attr; attr = (struct zx_str*)attr->g.n) {
    ZX_OUT_MEM(p, name, name_len);
    ZX_OUT_MEM(p, attr->s, attr->len);
    ZX_OUT_CH(p, '"');
  }
  return p;
}

/* Called by: */
int zx_attr_wo_len(struct zx_ctx* c, struct zx_str* attr, int name_size, struct zx_ns_s** pop_seenp)
{
  int len = 0;
  if (attr)
    len += zx_len_xmlns_if_not_seen(c, attr->g.ns, pop_seenp);
  /* In legal XML there should really be just one attribute, but we accommodate multioccurances. */
  for (; attr; attr = (struct zx_str*)attr->g.n) {
    if (attr->g.ns && attr->g.ns->prefix_len)
      len += attr->g.ns->prefix_len + 1;
    len += 1 + name_size + 1 + 1 + attr->len + 1;
  }
  return len;
}

/* The attribute name is known at compile time and passed as name and name_len, but
 * the namespace prefix is only known at runtime and has to be fished out of attr->g.ns */
/* Called by: */
char* zx_attr_wo_enc(char* p, struct zx_str* attr, char* name, int name_len)
{
  /* In legal XML there should really be just one attribute, but we accommodate multioccurances. */
  for (; attr; attr = (struct zx_str*)attr->g.n) {
    ZX_OUT_CH(p, ' ');
    if (attr->g.ns && attr->g.ns->prefix_len) {
      ZX_OUT_MEM(p, attr->g.ns->prefix, attr->g.ns->prefix_len);
      ZX_OUT_CH(p, ':');
    }
    ZX_OUT_MEM(p, name, name_len);
    ZX_OUT_MEM(p, attr->s, attr->len);
    ZX_OUT_CH(p, '"');
  }
  return p;
}

/* Called by: */
void zx_free_attr(struct zx_ctx* c, struct zx_str* attr, int free_strs)
{
  struct zx_str* attrn;
  for (; attr; attr = attrn) {
    attrn = (struct zx_str*)attr->g.n;
    if (free_strs && attr->s)
	ZX_FREE(c, attr->s);
    ZX_FREE(c, attr);
  }
}

/* Called by:  TXFREE_ELNAME */
void zx_free_elem_common(struct zx_ctx* c, struct zx_elem_s* x, int free_strs)
{
  struct zx_str* ss;
  struct zx_any_attr_s* aa;
  struct zx_any_elem_s* ae;
  struct zx_str* ssn;
  struct zx_any_attr_s* aan;
  struct zx_any_elem_s* aen;
  
  if (x->g.tok == ZX_TOK_NOT_FOUND && free_strs) {
    ae = (struct zx_any_elem_s*)x;
    if (ae->name)
      ZX_FREE(c, ae->name);
  }
  for (aa = x->any_attr; aa; aa = aan) {   /* unknown attributes */
    aan = (struct zx_any_attr_s*)aa->ss.g.n;
    if (free_strs && aa->name)
      ZX_FREE(c, aa->name);
    if (free_strs && aa->ss.s)
      ZX_FREE(c, aa->ss.s);
    ZX_FREE(c, aa);
  }
  for (ae = x->any_elem; ae; ae = aen) {  /* unknown elements */
    aen = (struct zx_any_elem_s*)ae->gg.g.n;
    zx_FREE_simple_elem(c, &ae->gg, free_strs);
  }
  for (ss = x->content; ss; ss = ssn) {   /* content */
    ssn = (struct zx_str*)ss->g.n;
    if (free_strs && ss->s)
      ZX_FREE(c, ss->s);
  }
  ZX_FREE(c, x);
}

/* Called by: */
void zx_free_simple_elems(struct zx_ctx* c, struct zx_elem_s* se, int free_strs)
{
  struct zx_elem_s* sen;
  for (; se; se = sen) {
    sen = (struct zx_elem_s*)se->g.n;
    zx_FREE_simple_elem(c, se, free_strs);
  }
}

#ifdef ZX_ENA_AUX

/* Called by: */
void zx_dup_attr(struct zx_ctx* c, struct zx_str* attr)
{
  char* p;
  for (; attr; attr = (struct zx_str*)attr->g.n)
    if (attr->s) {
      p = ZX_ALLOC(c, attr->len);
      memcpy(p, attr->s, attr->len);
      attr->s = p;
    }
}

/* Called by: */
struct zx_str* zx_clone_attr(struct zx_ctx* c, struct zx_str* attr)
{
  struct zx_str* ret;
  struct zx_str* attrnn;
  struct zx_str* attrn;
  char* p;
  for (attrnn = 0; attr; attr = (struct zx_str*)attr->g.n) {
    ZX_DUPALLOC(c, struct zx_str, attrn, attr);
    if (!attrnn)
      ret = attrn;
    else
      attrnn->g.n = &attrn->g;
    attrnn = attrn;
    if (attrn->s) {
      p = ZX_ALLOC(c, attrn->len);
      memcpy(p, attrn->s, attrn->len);
      attrn->s = p;
    }
  }
  return ret;
}

/* Called by:  TXDEEP_CLONE_ELNAME */
struct zx_elem_s* zx_clone_elem_common(struct zx_ctx* c, struct zx_elem_s* x, int size, int dup_strs)
{
  struct zx_str* ss;
  struct zx_any_attr_s* aa;
  struct zx_any_elem_s* ae;
  struct zx_str* ssn;
  struct zx_any_attr_s* aan;
  struct zx_any_elem_s* aen;
  struct zx_str* ssnn;
  struct zx_any_attr_s* aann;
  struct zx_any_elem_s* aenn;
  char* p;

  if (x->g.tok == ZX_TOK_NOT_FOUND) {
    ae = (struct zx_any_elem_s*)x;
    ZX_DUPALLOC(c, struct zx_any_elem_s, aen, ae);
    if (dup_strs) {
      aen->name = ZX_ALLOC(c, ae->name_len);
      memcpy(aen->name, ae->name, ae->name_len);
    }
    x = &aen->gg;
  } else {
    struct zx_elem_s* xx = (struct zx_elem_s*)ZX_ALLOC(c, size);
    memcpy(xx, x, size);
    x = xx;
  }
  
  /* *** deal with xmlns specifications in exc c14n way */
  
  for (aann = 0, aa = x->any_attr; aa; aa = (struct zx_any_attr_s*)aa->ss.g.n) {  /* unknown attributes */
    ZX_DUPALLOC(c, struct zx_any_attr_s, aan, aa);
    if (!aann)
      x->any_attr = aan;
    else
      aann->ss.g.n = &aan->ss.g;
    aann = aan;
    
    if (dup_strs && aan->name) {
      p = ZX_ALLOC(c, aan->name_len);
      memcpy(p, aan->name, aan->name_len);
      aan->name = p;
    }
    if (dup_strs && aan->ss.s) {
      p = ZX_ALLOC(c, aan->ss.len);
      memcpy(p, aan->ss.s, aan->ss.len);
      aan->ss.s = p;
    }
  }
  
  for (aenn = 0, ae = x->any_elem; ae; ae = (struct zx_any_elem_s*)ae->gg.g.n) {  /* unknown elements */
    aen = (struct zx_any_elem_s*)zx_DEEP_CLONE_simple_elem(c, &ae->gg, dup_strs);
    if (!aenn)
      x->any_elem = aen;
    else
      aenn->gg.g.n = &aen->gg.g;
    aenn = aen;
  }
  
  for (ssnn = 0, ss = x->content; ss; ss = (struct zx_str*)ss->g.n) {   /* content */
    ZX_DUPALLOC(c, struct zx_str, ssn, ss);
    if (!ssnn)
      x->content = ssn;
    else
      ssnn->g.n = &ssn->g;
    ssnn = ssn;
    if (ssn->s) {
      p = ZX_ALLOC(c, ssn->len);
      memcpy(p, ssn->s, ssn->len);
      ssn->s = p;
    }
  }
  
  return x;
}

/* Called by:  TXDUP_STRS_ELNAME */
void zx_dup_strs_common(struct zx_ctx* c, struct zx_elem_s* x)
{
  struct zx_str* ss;
  struct zx_any_attr_s* aa;
  struct zx_any_elem_s* ae;
  char* p;
  
  if (x->g.tok == ZX_TOK_NOT_FOUND) {
    ae = (struct zx_any_elem_s*)x;
    p = ZX_ALLOC(c, ae->name_len);
    memcpy(p, ae->name, ae->name_len);
    ae->name = p;
  }
  
  /* *** deal with xmlns specifications in exc c14n way */

  for (aa = x->any_attr; aa; aa = (struct zx_any_attr_s*)aa->ss.g.n) {  /* unknown attributes */
    if (aa->name) {
      p = ZX_ALLOC(c, aa->name_len);
      memcpy(p, aa->name, aa->name_len);
      aa->name = p;
    }
    if (aa->ss.s) {
      p = ZX_ALLOC(c, aa->ss.len);
      memcpy(p, aa->ss.s, aa->ss.len);
      aa->ss.s = p;
    }
  }

  for (ae = x->any_elem; ae; ae = (struct zx_any_elem_s*)ae->gg.g.n)   /* unknown elements */
    zx_DUP_STRS_simple_elem(c, &ae->gg);

  for (ss = x->content; ss; ss = (struct zx_str*)ss->g.n)    /* content */
    if (ss->s) {
      p = ZX_ALLOC(c, ss->len);
      memcpy(p, ss->s, ss->len);
      ss->s = p;
    }
}

int zx_walk_so_unknown_attributes(struct zx_ctx* c, struct zx_elem_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
{
  struct zx_any_attr_s* aa;
  int ret;
  
  for (aa = x->any_attr; aa; aa = (struct zx_any_attr_s*)aa->ss.g.n) {  /* unknown attributes */
    ret = callback(&aa->ss.g, ctx);
    if (ret)
      return ret;
  }
  return 0;
}

int zx_walk_so_unknown_elems_and_content(struct zx_ctx* c, struct zx_elem_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
{
  struct zx_str* ss;
  struct zx_any_elem_s* ae;
  int ret;
  
  for (ae = x->any_elem; ae; ae = (struct zx_any_elem_s*)ae->gg.g.n) {  /* unknown elements */
    ret = zx_WALK_SO_simple_elem(c, &ae->gg, ctx, callback);
    if (ret)
      return ret;
  }
  
  for (ss = x->content; ss; ss = (struct zx_str*)ss->g.n) {   /* content */
    ret = callback(&ss->g, ctx);
    if (ret)
      return ret;
  }
  return 0;
}

/* Called by: */
struct zx_elem_s* zx_deep_clone_simple_elems(struct zx_ctx* c, struct zx_elem_s* x, int dup_strs)
{
  struct zx_elem_s* se;
  struct zx_elem_s* sen;
  struct zx_elem_s* senn;
  
  for (senn = 0, se = x; se; se = (struct zx_elem_s*)se->g.n) {
    sen = zx_DEEP_CLONE_simple_elem(c, se, dup_strs);
    if (!senn)
      x = sen;
    else
      senn->g.n = &sen->g;
    senn = sen;
  }
  return x;
}


int zx_walk_so_simple_elems(struct zx_ctx* c, struct zx_elem_s* se, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
{
  int ret;

  for (; se; se = (struct zx_elem_s*)se->g.n) {
    ret = zx_WALK_SO_simple_elem(c, se, ctx, callback);
    if (ret)
      return ret;
  }
  return 0;
}

/* Called by: */
void zx_dup_strs_simple_elems(struct zx_ctx* c, struct zx_elem_s* se)
{
  for (; se; se = (struct zx_elem_s*)se->g.n)
    zx_DUP_STRS_simple_elem(c, se);
}

#endif

#if 0
/* In ionterest of efficiency, we leave these inlined. */
/* Called by: */
int zx_len_simple_elems(struct zx_ctx* c, struct zx_elem_s* se, int siz)
{
  int len = 0;
  for (; se; se = (struct zx_elem_s*)se->g.n)
    len += zx_LEN_so_simple_elem(se, siz);
  return len;
}

/* Called by: */
char* zx_enc_so_simple_elems(struct zx_ctx* c, struct zx_elem_s* se, char* p, char* name, int len)
{
  for (; se; se = (struct zx_elem_s*)se->g.n)
    p = zx_ENC_SO_simple_elem(se, p, name, len);
  return p;
}
#endif

/*() Prepare a context for decoding XML. The decoding operation will not
 * alter the underlying data (e.g. no nuls are inserted, not even temporarily).
 * N.B. Often you would wrap this in locks, like
 *   LOCK(cf->ctx->mx, "valid");
 *   zx_prepare_dec_ctx(cf->ctx, zx_ns_tab, ss->s, ss->s + ss->len);
 *   r = zx_DEC_root(cf->ctx, 0, 1);
 *   UNLOCK(cf->ctx->mx, "valid");
 */

/* Called by:  main x7, test_ibm_cert_problem, zxid_add_env_if_needed x2, zxid_dec_a7n, zxid_decode_redir_or_post, zxid_decrypt_nameid, zxid_decrypt_newnym, zxid_di_query, zxid_find_epr, zxid_gen_boots, zxid_get_ses_sso_a7n x2, zxid_idp_soap_parse, zxid_parse_meta, zxid_reg_svc, zxid_soap_call_raw, zxid_sp_soap_parse, zxid_wsp_validate */
void zx_prepare_dec_ctx(struct zx_ctx* c, struct zx_ns_s* ns_tab, const char* start, const char* lim)
{
  c->guard_seen_n.seen_n = &c->guard_seen_p;
  c->guard_seen_p.seen_p = &c->guard_seen_n;
  c->ns_tab = ns_tab;
  c->bas = c->p = start;
  c->lim = lim;
}

/* Called by:  TXDEC_ELNAME */
int zx_scan_data(struct zx_ctx* c, struct zx_elem_s* el)
{
  struct zx_str* ss;
  const char* d = c->p;
  if (c->p) ZX_LOOK_FOR(c,'<');
  ss = ZX_ZALLOC(c, struct zx_str);
  ss->len = c->p - d;
  ss->s = (char*)d;
  ss->g.tok = ZX_TOK_DATA;
  ss->g.n = &el->content->g;
  el->content = ss;
  ss->g.wo = &el->kids->g;
  el->kids = (struct zx_elem_s*)ss;
  return 1;

 look_for_not_found:
  /*zx_xml_parse_err(c, '<', (const char*)__FUNCTION__, "look for not found");  -- Causes bogus warning in end of buffer. */
  return 0;
}

/* Called by:  TXDEC_ELNAME */
int zx_scan_pi_or_comment(struct zx_ctx* c)
{
  const char* name;
  char quote;

  switch (*c->p) {
  case '?':  /* processing instruction <?xml ... ?> */
    name = c->p-1;
    DD("Processing Instruction detected (%.*s)", 5, name);
    while (1) {
      quote = '>';
      ZX_LOOK_FOR(c,'>');
      if (c->p[-1] == '?')
	break;
    }
    ++c->p;
    DD("Processing Instruction scanned (%.*s)", c->p-name, name);
    /*ZX_PI_DEC_EXT(pi);*/
    return 0;
  case '!':  /* comment <!-- ... --> or <!DOCTYPE...> */
    name = c->p-1;
    if (!memcmp(c->p+1, "DOCTYPE", sizeof("DOCTYPE")-1)) {
      D("DOCTYPE detected (%.*s)", 60, c->p-1);
      ZX_LOOK_FOR(c,'>');
      ++c->p;
      D("DOCTYPE scanned (%.*s)", c->p-name, name);
      return 0;
    }
    c->p += 2;
    if (c->p[-1] != '-' || c->p[0] != '-') {
      c->p -= 3;
      return 1;
    }
    D("Comment detected (%.*s)", 8, name);
    c->p += 2;
    while (1) {
      quote = '>';
      ZX_LOOK_FOR(c,'>');
      if (c->p[-2] == '-' && c->p[-1] == '-') {
	break;
      }
    }
    ++c->p;
    D("Comment scanned (%.*s)", c->p-name, name);
    /*ZX_COMMENT_DEC_EXT(comment);*/
    return 0;
  }
  return 1;
 look_for_not_found:
  zx_xml_parse_err(c, quote, (const char*)__FUNCTION__, "look for not found");
  return 1;
}

/* Called by:  TXDEC_ELNAME */
struct zx_str* zx_dec_unknown_attr(struct zx_ctx* c, struct zx_elem_s* el, const char* name, const char* data, int tok, int ctx_tok)
{
  const char* p;
  int namlen = data - name - 2;
  struct zx_any_attr_s* attr = ZX_ZALLOC(c, struct zx_any_attr_s);
  
  if (tok == ZX_TOK_NOT_FOUND) {
    D("Unknown attribute(%.*s) in context(%d)", namlen, name, ctx_tok);
  } else {
    D("Known attribute(%.*s) tok(%d) in wrong context(%d)", namlen, name, tok, ctx_tok);
    tok = ZX_TOK_NOT_FOUND;
  }

  p = memchr(name, ':', namlen);   /* namespace check */
  if (p) {
    namlen -= 1+p-name;
    name = p+1;
  }
  attr->name_len = namlen;
  attr->name = (char*)name;
  attr->ss.g.n = &el->any_attr->ss.g;
  el->any_attr = attr;
  /*ZX_UNKNOWN_ATTR_DEC_EXT(attr);*/
  return &attr->ss;
}

/*() Called from dec-templ.c for CSE elimination. */

/* Called by:  TXDEC_ELNAME */
const char* zx_dec_attr_val(struct zx_ctx* c, const char** name, const char* func)
{
  const char* data;
  char quote;
  *name = c->p;
  quote = '=';
  ZX_LOOK_FOR(c,'=');
  
  ++c->p;
  if (!ONE_OF_2(*c->p, '"', '\'')) {
    zx_xml_parse_err(c, *c->p, func, "zx_dec_attr_val: Did not find expected quote char (single or double), saw");
    return 0;
  }
  quote = *c->p;
  ++c->p;
  data = c->p;	
  
  ZX_LOOK_FOR(c, quote);
  return data;
 look_for_not_found:
  zx_xml_parse_err(c, quote, func, "zx_dev_attr_val: char not found");
  return 0;
}

/*() Called from dec-templ.c for CSE elimination. */

void zx_dec_reverse_lists(struct zx_elem_s* x)
{
  struct zx_elem_s* iternode;
  struct zx_str* ss;
  iternode = x->kids;
  REVERSE_LIST_NEXT(x->kids, iternode, g.wo);
  iternode = (struct zx_elem_s*)(x->any_elem);
  REVERSE_LIST_NEXT(x->any_elem, iternode, g.n);
  ss = (struct zx_str*)(x->any_attr);
  REVERSE_LIST_NEXT(x->any_attr, ss, g.n);
}

/* Called by:  TXDEC_ELNAME x2, zx_dec_attr_val x2, zx_scan_pi_or_comment, zx_scan_xmlns x2 */
void zx_xml_parse_err(struct zx_ctx* c, char quote, const char* func, const char* msg)
{
  const char* errloc = MAX(c->p - 20, c->bas);
  ERR("%s: %s: char(%c) pos=%d (%.*s)", func, msg, quote,
      c->p - c->bas, MIN(c->lim - errloc, 40), errloc);
}

/*() This is very special error handler called from innards for dec-templ.c for CSE. */

void zx_xml_parse_err_mismatching_close_tag(struct zx_ctx* c, const char* func, const char* name, int tok)
{
  const char* errloc = MAX(c->p - 20, c->bas);
  ERR("%s: Mismatching close tag(%.*s) tok=%d pos=%d (%.*s)", func, c->p-name, name, tok, c->p - c->bas, MIN(c->lim - errloc, 40), errloc);
  ++c->p;
}

/*() Called from innards for dec-templ.c for CSE. */

const char* zx_scan_elem_start(struct zx_ctx* c, const char* func)
{
  const char* name = c->p;
  for (++c->p; *c->p && !ONE_OF_6(*c->p, ' ', '>', '/', '\n', '\r', '\t'); ++c->p) ;
  if (*c->p)
    return name;
  D("%s: Incomplete %s", func, name);
  return 0;
}

/* Add inclusive namespaces. */

/* Called by:  TXLEN_SO_ELNAME, TXLEN_WO_ELNAME */
int zx_len_inc_ns(struct zx_ctx* c, struct zx_ns_s** pop_seenp)
{
  int len = 0;
  struct zx_ns_s* ns;
  for (ns = c->inc_ns; ns; ns = ns->inc_n)
    len += zx_len_xmlns_if_not_seen(c, ns, pop_seenp);
  /*c->inc_ns_len = 0;  needs to be processed at every level */
  return len;
}

/* Called by:  TXENC_WO_ELNAME */
void zx_add_inc_ns(struct zx_ctx* c, struct zx_ns_s** pop_seenp)
{
  struct zx_ns_s* ns;
  for (ns = c->inc_ns; ns; ns = ns->inc_n)
    zx_add_xmlns_if_not_seen(c, ns, pop_seenp);
  /*c->inc_ns = 0;  needs to be processed at every level */
}

/* EOF -- zxlib.c */
