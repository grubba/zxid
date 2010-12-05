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
 * 27.10.2010, re-engineered namespace handling --Sampo
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
#include "c/zx-ns.h"
#include "c/zx-data.h"

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

/* Called by:  zxid_add_a7n_at_to_pool x2, zxid_get_meta_ss, zxid_get_ses_sso_a7n, zxid_get_tas3_fault_actor, zxid_get_tas3_fault_comment, zxid_get_tas3_fault_ref, zxid_get_tas3_fault_sc1, zxid_get_tas3_fault_sc2, zxid_get_tas3_status_comment, zxid_get_tas3_status_ctlpt, zxid_get_tas3_status_ref, zxid_get_tas3_status_sc1, zxid_get_tas3_status_sc2, zxid_idp_sso, zxid_mk_ent x2, zxid_saml2_post_enc, zxid_simple_idp_show_an, zxid_sp_sso_finalize x3, zxid_wsc_call, zxid_wsc_validate_resp_env x2, zxid_wsf_validate_a7n x3, zxid_wsp_validate x3 */
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

/* Called by:  main, zx_free_elem, zxenc_privkey_dec, zxenc_pubkey_enc, zxenc_symkey_enc, zxid_addmd x3, zxid_anoint_a7n x5, zxid_anoint_sso_resp x4, zxid_az_soap x3, zxid_cache_epr, zxid_decode_redir_or_post, zxid_fed_mgmt_cf x3, zxid_idp_dispatch x2, zxid_idp_list_cf_cgi x3, zxid_idp_soap, zxid_idp_soap_dispatch x2, zxid_idp_sso x4, zxid_lecp_check, zxid_mgmt x3, zxid_mk_art_deref, zxid_mk_enc_a7n, zxid_mk_enc_id, zxid_mk_mni, zxid_psobj_dec, zxid_psobj_enc, zxid_reg_svc x3, zxid_saml2_post_enc x2, zxid_saml2_redir, zxid_saml2_redir_enc x2, zxid_saml2_redir_url, zxid_saml2_resp_redir, zxid_send_sp_meta, zxid_simple_idp_show_an, zxid_simple_no_ses_cf x3, zxid_simple_ses_active_cf, zxid_simple_show_page x3, zxid_slo_resp_redir, zxid_snarf_eprs_from_ses, zxid_soap_call_envelope, zxid_soap_call_hdr_body, zxid_soap_cgi_resp_body x2, zxid_sp_dispatch x2, zxid_sp_mni_soap, zxid_sp_slo_soap, zxid_sp_soap, zxid_sp_soap_dispatch x7, zxid_ssos_anreq, zxid_start_sso_location, zxid_user_sha1_name, zxid_write_ent_to_cache, zxsig_sign */
void zx_str_free(struct zx_ctx* c, struct zx_str* ss)
{
  if (ss->s)
    ZX_FREE(c, ss->s);
  ZX_FREE(c, ss);
}

/*() Construct zx_str from length and raw string data, which will be referenced, not copied. */

/* Called by:  zx_EASY_ENC_elem, zx_ref_len_elem, zx_ref_str, zx_strf, zxid_http_post_raw, zxid_saml2_redir_enc x2, zxlog_path */
struct zx_str* zx_ref_len_str(struct zx_ctx* c, int len, const char* s)
{
  struct zx_str* ss = ZX_ZALLOC(c, struct zx_str);
  ss->s = (char*)s;  /* ref points to underlying data */
  ss->len = len;
  return ss;
}

/*() Construct zx_str from C string, which will be referenced, not copied. */

/* Called by:  pool2apache x2, test_ibm_cert_problem_enc_dec, zxid_az_soap x8, zxid_ins_xacml_az_cd1_stmt, zxid_ins_xacml_az_stmt, zxid_mk_di_req_svc, zxid_org_desc x5, zxid_pepmap_extract x2, zxid_pool_to_json x2, zxid_pool_to_ldif x2, zxid_pool_to_qs x2, zxid_simple_ses_active_cf x2, zxid_wsf_decor x2 */
struct zx_str* zx_ref_str(struct zx_ctx* c, const char* s)
{
  if (!s)
    return 0;
  return zx_ref_len_str(c, strlen(s), s);
}

/*() Newly allocated string (node and data) of specified length, but uninitialized */

/* Called by:  zx_dup_len_str, zx_raw_cipher, zx_rsa_priv_dec, zx_rsa_priv_enc, zx_rsa_pub_dec, zx_rsa_pub_enc, zxenc_pubkey_enc, zxenc_symkey_enc, zxid_map_val x5, zxid_pool_to_json, zxid_pool_to_ldif, zxid_pool_to_qs, zxid_psobj_dec, zxid_psobj_enc, zxid_template_page_cf, zxsig_sign x2 */
struct zx_str* zx_new_len_str(struct zx_ctx* c, int len)
{
  struct zx_str* ss = ZX_ZALLOC(c, struct zx_str);
  ss->s = ZX_ALLOC(c, len+1);
  ss->s[len] = 0;
  ss->len = len;
  return ss;
}

/*() Construct zx_str by duplication of raw string data of given length. */

/* Called by:  zx_dup_len_elem, zx_dup_str, zxid_add_ldif_attrs_to_ses, zxid_parse_invite, zxid_parse_psobj */
struct zx_str* zx_dup_len_str(struct zx_ctx* c, int len, const char* s)
{
  struct zx_str* ss = zx_new_len_str(c, len);
  memcpy(ss->s, s, len);
  return ss;
}

/*() Construct zx_str by duplication of C string. */

/* Called by:  zxid_add_attr_to_ses, zxid_add_qs_to_ses, zxid_anoint_a7n x2, zxid_anoint_sso_resp x3, zxid_attach_sol1_usage_directive, zxid_az_soap x4, zxid_call_epr, zxid_fed_mgmt_cf, zxid_get_at x2, zxid_idp_dispatch x8, zxid_idp_list_cf_cgi x2, zxid_idp_select_zxstr_cf_cgi, zxid_idp_sso x13, zxid_map_identity_token, zxid_map_val, zxid_mk_an_stmt, zxid_mk_attribute, zxid_mk_subj, zxid_mk_user_a7n_to_sp, zxid_new_epr, zxid_parse_invite x6, zxid_parse_mni, zxid_parse_psobj x7, zxid_pepmap_extract x7, zxid_saml2_redir, zxid_saml2_resp_redir, zxid_ses_to_pool x10, zxid_show_conf x3, zxid_show_cstr_list, zxid_show_map, zxid_show_need x2, zxid_simple_ab_pep x3, zxid_slo_resp_redir, zxid_sp_dispatch x15, zxid_sp_mni_redir x3, zxid_sp_slo_redir x3, zxid_start_sso_location, zxid_wsc_prep, zxid_wsc_prepare_call, zxid_wsc_validate_resp_env, zxid_wsp_decorate, zxid_wsp_validate */
struct zx_str* zx_dup_str(struct zx_ctx* c, const char* s)
{
  return zx_dup_len_str(c, strlen(s), s);
}

/*() ZX verion of strdup(). */

/* Called by:  chkuid x2, zxid_az_base_cf_ses, zxid_az_cf_ses, zxid_fed_mgmt_cf, zxid_get_ses, zxid_mk_user_a7n_to_sp x2, zxid_parse_invite, zxid_parse_psobj, zxid_simple_cf_ses x2, zxid_simple_no_ses_cf, zxid_simple_redir_page, zxid_simple_ses_active_cf, zxid_simple_show_page x2, zxid_url_set */
char* zx_dup_cstr(struct zx_ctx* c, const char* str)
{
  int len = strlen(str);
  char* s = ZX_ALLOC(c, len+1);
  memcpy(s, str, len+1);
  return s;
}

/* ------------------ ATTR ------------------ */

/*() Construct zx_attr_s from length and raw string data, which will be referenced, not copied. */

/* Called by:  zx_attrf, zx_ref_attr, zxenc_symkey_enc, zxid_check_fed, zxid_idp_sso, zxid_mk_an_stmt, zxid_mk_logout_resp, zxid_mk_mni_resp, zxid_mk_xacml_simple_at x3, zxid_mni_do_ss, zxid_ps_addent_invite, zxid_slo_resp_redir, zxid_sp_mni_redir, zxid_sp_slo_redir, zxid_sso_issue_a7n */
struct zx_attr_s* zx_ref_len_attr(struct zx_ctx* c, struct zx_elem_s* father, int tok, int len, const char* s)
{
  struct zx_attr_s* ss = ZX_ZALLOC(c, struct zx_attr_s);
  ss->g.s = (char*)s;  /* ref points to underlying data */
  ss->g.len = len;
  ss->g.tok = tok;
  if (father) {
    ss->g.n = &father->attr->g;
    father->attr = ss;
  }
  return ss;
}

/*() Construct zx_attr_s from C string, which will be referenced, not copied. */

/* Called by:  test_ibm_cert_problem_enc_dec x2, zxenc_pubkey_enc, zxenc_symkey_enc x3, zxid_ac_desc x2, zxid_add_header_refs x29, zxid_ar_desc, zxid_attach_sol1_usage_directive x5, zxid_az_soap x2, zxid_check_fed, zxid_contact_desc, zxid_idp_sso, zxid_idp_sso_desc x2, zxid_issuer, zxid_key_desc, zxid_map_identity_token x2, zxid_mk_Status x2, zxid_mk_art_deref, zxid_mk_authn_req x10, zxid_mk_az, zxid_mk_az_cd1, zxid_mk_dap_query, zxid_mk_dap_query_item x8, zxid_mk_dap_resquery x6, zxid_mk_dap_select x2, zxid_mk_dap_subscription x7, zxid_mk_dap_test_item x2, zxid_mk_dap_testop x2, zxid_mk_di_req_svc, zxid_mk_ecp_Request_hdr x2, zxid_mk_idp_list x2, zxid_mk_logout, zxid_mk_logout_resp, zxid_mk_mni, zxid_mk_mni_resp, zxid_mk_paos_Request_hdr x3, zxid_mk_tas3_status, zxid_mk_transient_nid, zxid_mk_user_a7n_to_sp, zxid_mk_xacml_resp, zxid_mni_desc, zxid_nimap_desc, zxid_org_desc x3, zxid_ps_addent_invite x2, zxid_slo_desc, zxid_sp_sso_desc x3, zxid_sso_desc, zxid_sso_issue_a7n, zxid_wsc_prep x8, zxid_wsc_prep_secmech, zxid_wsf_decor x24, zxid_wsf_sign x2, zxsig_sign x5 */
struct zx_attr_s* zx_ref_attr(struct zx_ctx* c, struct zx_elem_s* father, int tok, const char* s)
{
  if (!s)
    return 0;
  return zx_ref_len_attr(c, father, tok, strlen(s), s);
}

/*() Newly allocated attribute (node and data) of specified length, but uninitialized */

/* Called by:  zx_dup_len_attr */
struct zx_attr_s* zx_new_len_attr(struct zx_ctx* c, struct zx_elem_s* father, int tok, int len)
{
  struct zx_attr_s* ss = ZX_ZALLOC(c, struct zx_attr_s);
  ss->g.s = ZX_ALLOC(c, len+1);
  ss->g.s[len] = 0;
  ss->g.len = len;
  ss->g.tok = tok;
  if (father) {
    ss->g.n = &father->attr->g;
    father->attr = ss;
  }
  return ss;
}

/*() Construct zx_str by duplication of raw string data of given length. */

/* Called by:  zx_dup_attr, zxid_imreq */
struct zx_attr_s* zx_dup_len_attr(struct zx_ctx* c, struct zx_elem_s* father, int tok, int len, const char* s)
{
  struct zx_attr_s* ss = zx_new_len_attr(c, father, tok, len);
  memcpy(ss->g.s, s, len);
  return ss;
}

/*() Construct zx_str by duplication of C string. */

/* Called by:  zxenc_pubkey_enc, zxid_as_call_ses, zxid_attach_sol1_usage_directive, zxid_idp_sso, zxid_map_identity_token x3, zxid_mk_a7n, zxid_mk_attribute, zxid_mk_authn_req, zxid_mk_lu_Status x3, zxid_mk_saml_resp, zxid_mk_tas3_status x4, zxid_parse_mni x3 */
struct zx_attr_s* zx_dup_attr(struct zx_ctx* c, struct zx_elem_s* father, int tok, const char* s)
{
  return zx_dup_len_attr(c, father, tok, strlen(s), s);
}

/*() vasprintf(3) implementation that will grab its memory from ZX memory allocator. */

/* Called by:  zx_alloc_sprintf, zx_attrf, zx_strf, zxid_callf, zxid_callf_epr, zxid_wsc_prepare_callf, zxid_wsp_decoratef */
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

/* Called by:  chkuid, zx_prefix_seen_whine, zxenc_pubkey_enc, zxid_date_time x2, zxid_decode_redir_or_post x5, zxid_fed_mgmt_cf x4, zxid_idp_list_cf_cgi x6, zxid_idp_select_zxstr_cf_cgi x3, zxid_idp_sso x3, zxid_lecp_check, zxid_mk_di_req_svc, zxid_mk_id, zxid_my_cdc_url, zxid_my_entity_id x3, zxid_ps_accept_invite, zxid_ps_addent_invite, zxid_ps_finalize_invite, zxid_saml2_post_enc x3, zxid_saml2_redir, zxid_saml2_redir_url, zxid_saml2_resp_redir, zxid_saml_ok, zxid_ses_to_pool x6, zxid_show_conf x5, zxid_show_cstr_list, zxid_show_map, zxid_show_need x2, zxid_simple_idp_an_ok_do_rest, zxid_simple_idp_new_user, zxid_simple_idp_recover_password, zxid_simple_idp_show_an x2, zxid_simple_no_ses_cf, zxid_simple_redir_page, zxid_simple_show_err, zxid_simple_show_page, zxid_sp_carml, zxid_start_sso_location, zxid_user_sha1_name, zxid_wsc_prep, zxid_wsf_decor */
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

/* Called by:  zxenc_pubkey_enc x2, zxenc_symkey_enc, zxid_ac_desc, zxid_ar_desc x2, zxid_date_time_attr x2, zxid_idp_sso_desc, zxid_mk_dap_query_item x2, zxid_mk_dap_select x4, zxid_mk_dap_testop x4, zxid_mk_id_attr, zxid_mk_paos_Request_hdr, zxid_mni_desc x2, zxid_my_entity_id_attr x3, zxid_nimap_desc x2, zxid_slo_desc x2, zxid_sp_sso_desc, zxid_sso_desc x2, zxsig_sign */
struct zx_attr_s* zx_attrf(struct zx_ctx* c, struct zx_elem_s* father, int tok, const char* f, ...)  /* data is new memory */
{
  va_list ap;
  int len;
  char* s;
  va_start(ap, f);
  s = zx_alloc_vasprintf(c, &len, f, ap);
  va_end(ap);
  return zx_ref_len_attr(c, father, tok, len, s);
}

/*() Check if string ends in suffix */

/* Called by: */
int zx_str_ends_in(struct zx_str* ss, int len, const char* suffix)
{
  return !memcmp(ss->s + ss->len - len, suffix, len);
}

/*() Add non-XML content to the kids list. These essentially appear as DATA items. */

/* Called by:  test_ibm_cert_problem_enc_dec, zx_new_str_elem, zxid_attach_sol1_usage_directive, zxid_az_soap x4, zxid_check_fed, zxid_issuer, zxid_mk_addr, zxid_mk_attribute, zxid_mk_subj, zxid_mk_transient_nid, zxid_new_epr, zxid_org_desc x5, zxid_parse_mni, zxid_ps_addent_invite x2, zxid_wsc_prep, zxid_wsc_prep_secmech x3, zxid_wsf_decor x4, zxsig_sign */
void zx_add_content(struct zx_ctx* c, struct zx_elem_s* x, struct zx_str* cont)
{
  if (!cont || !x) {
    ERR("Call to zx_add_content(c,%p,%p) with null values", x, cont);
    return;
  }
  cont->tok = ZX_TOK_DATA;
  cont->n = &x->kids->g;
  x->kids = (struct zx_elem_s*)cont;
}

/*() Add kid to head of kids list. Usually you should add in schema order
 * and in the end call zx_reverse_elem_lists() to make the list right order. */

/* Called by:  zx_add_kid_after_sa_Issuer, zxid_add_fed_tok2epr, zxid_az_soap, zxid_imreq, zxid_mk_a7n x3, zxid_mk_logout_resp, zxid_mk_mni_resp, zxid_mk_saml_resp, zxid_mk_xac_az x4, zxid_soap_call_hdr_body x2, zxid_sp_soap_dispatch, zxid_wsf_sign */
struct zx_elem_s* zx_add_kid(struct zx_elem_s* father, struct zx_elem_s* kid)
{
  if (father) {
    kid->g.n = &father->kids->g;
    father->kids = kid;
  }
  return kid;
}

/*() Add kid before another elem. This assumes father is already in
 * forward order, i.e. zx_reverse_elem_lists() was already called. */

/* Called by:  zxid_ins_xacml_az_cd1_stmt x2, zxid_ins_xacml_az_stmt x2 */
struct zx_elem_s* zx_add_kid_before(struct zx_elem_s* father, int before, struct zx_elem_s* kid)
{
  if (!father->kids) {
    father->kids = kid;
    return kid;
  }
  if (father->kids->g.tok == before) {
    kid->g.n = &father->kids->g;
    father->kids = kid;
    return kid;
  }
  for (father = father->kids;
       father->g.n && father->g.n->tok != before;
       father = (struct zx_elem_s*)father->g.n) ;

  kid->g.n = father->g.n;
  father->g.n = &kid->g;
  return kid;
}

/*() Add Signature right after sa:Issuer. This assumes father is
 * already in forward order (i.e. zx_reverse_elem_lists() was already
 * called. */

/* Called by:  zxid_anoint_a7n, zxid_anoint_sso_resp, zxid_az_soap x2, zxid_idp_soap_dispatch x2, zxid_idp_sso, zxid_mk_art_deref, zxid_sp_mni_soap, zxid_sp_slo_soap, zxid_sp_soap_dispatch x6, zxid_ssos_anreq */
struct zx_elem_s* zx_add_kid_after_sa_Issuer(struct zx_elem_s* father, struct zx_elem_s* kid)
{
  if (father->kids->g.tok == zx_sa_Issuer_ELEM) {
    father = father->kids;
    kid->g.n = father->g.n;
    father->g.n = &kid->g;
    return kid;
  }
  ERR("No <sa:Issuer> found. Adding signature at list head. %d", father->kids->g.tok);
  return zx_add_kid(father, kid);
}

/*() Replace kid element. */

struct zx_elem_s* zx_replace_kid(struct zx_elem_s* father, struct zx_elem_s* kid)
{
  if (!father->kids) {
    father->kids = kid;
    return kid;
  }
  if (father->kids->g.tok == kid->g.tok) {
    kid->g.n = &father->kids->g.n;
    father->kids = kid;
    return kid;
  }
  for (father = father->kids;
       father->g.n && father->g.n->tok != kid->g.tok;
       father = (struct zx_elem_s*)father->g.n) ;

  kid->g.n = father->g.n->n;
  father->g.n = &kid->g;
  return kid;
}

/*() Construct new simple element from zx_str by referencing, not copying, it. */

/* Called by:  main, zx_dup_len_elem, zx_ref_len_elem, zxenc_pubkey_enc, zxenc_symkey_enc, zxid_mk_a7n, zxid_mk_logout, zxid_mk_mni x4, zxid_mk_xacml_simple_at, zxid_ps_addent_invite x2, zxsig_sign */
struct zx_elem_s* zx_new_str_elem(struct zx_ctx* c, struct zx_elem_s* father, int tok, struct zx_str* ss)
{
  struct zx_elem_s* el;
  el = ZX_ZALLOC(c, struct zx_elem_s);
  el->g.tok = tok;
  if (father) {
    el->g.n = &father->kids->g;
    father->kids = el;
  }
  zx_add_content(c, el, ss);
  return el;
}

/*() Helper function for the zx_NEW_*() macros */

/* Called by: */
struct zx_elem_s* zx_new_elem(struct zx_ctx* c, struct zx_elem_s* father, int tok)
{
  const struct zx_el_desc* ed;
  struct zx_elem_s* el;
  ed = zx_el_desc_lookup(tok);
  if (ed) {
    el = ZX_ALLOC(c, ed->siz);
    ZERO(el, ed->siz);
  } else {
    INFO("Unknown element tok=%06x in tok=%06x", tok, father?father->g.tok:0);
    el = ZX_ZALLOC(c, struct zx_elem_s);
    tok = ZX_TOK_NOT_FOUND;
  }
  el->g.tok = tok;
  if (father) {
    el->g.n = &father->kids->g;
    father->kids = el;
  }
  return el;
}

/*() Construct new simple element by referencing, not copying, raw string data of given length. */

/* Called by:  zx_ref_elem, zxid_as_call_ses, zxid_key_info */
struct zx_elem_s* zx_ref_len_elem(struct zx_ctx* c, struct zx_elem_s* father, int tok, int len, const char* s)
{
  return zx_new_str_elem(c, father, tok, zx_ref_len_str(c, len, s));
}

/*() Construct new simple element by referencing, not copying, C string. */

/* Called by:  main, zxid_contact_desc x6, zxid_idp_sso_desc x2, zxid_mk_Status, zxid_mk_art_deref, zxid_mk_authn_req, zxid_mk_dap_query_item x4, zxid_mk_dap_resquery x4, zxid_mk_dap_select x2, zxid_mk_dap_subscription x2, zxid_mk_dap_testop x2, zxid_mk_di_req_svc x6, zxid_mk_xacml_resp, zxid_sp_sso_desc x2 */
struct zx_elem_s* zx_ref_elem(struct zx_ctx* c, struct zx_elem_s* father, int tok, const char* s)
{
  return zx_ref_len_elem(c, father, tok, strlen(s), s);
}

/* Called by:  zx_dup_elem */
struct zx_elem_s* zx_dup_len_elem(struct zx_ctx* c, struct zx_elem_s* father, int tok, int len, const char* s)
{
  return zx_new_str_elem(c, father, tok, zx_dup_len_str(c, len, s));
}

/* Called by:  zxid_add_fed_tok2epr, zxid_mk_an_stmt, zxid_mk_fault x3, zxid_new_epr x3, zxid_set_epr_secmech x2 */
struct zx_elem_s* zx_dup_elem(struct zx_ctx* c, struct zx_elem_s* father, int tok, const char* s)
{
  return zx_dup_len_elem(c, father, tok, strlen(s), s);
}

/* ------------- Common Subexpression Elimination for generated code ------------- */

#define D_LEN_ENA 0
#if D_LEN_ENA
#define D_LEN(f,t,l) D(f,t,l)
#else
#define D_LEN(f,t,l)
#endif

/*() Compute length of an element (and its subelements). The XML attributes
 * and elements are processed in wire order and no assumptions
 * are made about namespace prefixes. */

/* Called by:  main x2, zx_EASY_ENC_elem, zx_LEN_WO_any_elem x2 */
int zx_LEN_WO_any_elem(struct zx_ctx* c, struct zx_elem_s* x)
{
  //const struct zx_el_desc* ed;
  struct zx_at_tok* at_tok;
  struct zx_el_tok* el_tok;
  struct zx_ns_s* pop_seen = 0;
  struct zx_attr_s* attr;
  struct zx_elem_s* kid;
  int ix;
  int len;
  //struct zx_elem_s* kid;
  switch (x->g.tok) {
  case zx_root_ELEM:
    len = 0;
    if (c->inc_ns_len)
      len += zx_len_inc_ns(c, &pop_seen);
    for (kid = x->kids; kid; kid = ((struct zx_elem_s*)(kid->g.n)))
      len += zx_LEN_WO_any_elem(c, kid);
    break;
  case ZX_TOK_DATA:
    return x->g.len;
  case zx_ds_Signature_ELEM:
    if (x == c->exclude_sig)
      return 0;
    /* fall thru */
  default:
    if (x->g.s) {
      /*    <   ns:elem    >   </  ns:elem    >  */
      len = 1 + x->g.len + 1 + 2 + x->g.len + 1;
    } else { /* Construct elem string from tok */
      ix = (x->g.tok >> ZX_TOK_NS_SHIFT)&(ZX_TOK_NS_MASK >> ZX_TOK_NS_SHIFT);
      if (ix >= zx__NS_MAX) {
	ERR("Namespace index of token(0x%06x) out of range(0x%02x)", x->g.tok, zx__NS_MAX);
	return 0;
      }
      x->ns = zx_ns_tab + ix;
      //ed = zx_el_desc_lookup(tok);
      ix = x->g.tok & ZX_TOK_TOK_MASK;
      if (ix >= zx__ELEM_MAX) {
	ERR("Element token(0x%06x) out of range(0x%04x)", x->g.tok, zx__ELEM_MAX);
	return 0;
      }
      el_tok = zx_el_tab + ix;
      len = strlen(el_tok->name);
      DD("ns prefix_len=%d el_len=%d", x->ns->prefix_len, len);
      /*    <   ns                  :   elem  >   </  ns                  :   elem  >  */
      len = 1 + x->ns->prefix_len + 1 + len + 1 + 2 + x->ns->prefix_len + 1 + len + 1;
    }
    D_LEN("%06x ** tag start: %d", x->g.tok, len);
    len += zx_len_xmlns_if_not_seen(c, x->ns, &pop_seen);
    D_LEN("%06x after xmlns: %d", x->g.tok, len);

    if (c->inc_ns_len)
      len += zx_len_inc_ns(c, &pop_seen);
    D_LEN("%06x after inc_ns: %d", x->g.tok, len);

    for (attr = x->attr; attr; attr = (struct zx_attr_s*)attr->g.n) {
      if (attr->name) {
	/*    sp   name             ="                "   */
	len += 1 + attr->name_len + 2 + attr->g.len + 1;
      } else { /* Construct elem string from tok */
	if (!attr->ns && IN_RANGE((attr->g.tok & ZX_TOK_NS_MASK) >> ZX_TOK_NS_SHIFT, 1, zx__NS_MAX))
	  attr->ns = zx_ns_tab + ((attr->g.tok & ZX_TOK_NS_MASK) >> ZX_TOK_NS_SHIFT);
	if (attr->ns)
	  len += attr->ns->prefix_len + 1;
	ix = attr->g.tok & ZX_TOK_TOK_MASK;
	if (ix >= zx__ATTR_MAX) {
	  ERR("Attribute token(0x%06x) out of range(0x%04x)", attr->g.tok, zx__ATTR_MAX);
	  return 0;
	}
	at_tok = zx_at_tab + ix;
	len += strlen(at_tok->name);
	/*     sp ="                "   */
	len += 1+ 2 + attr->g.len + 1;
      }
      len += zx_len_xmlns_if_not_seen(c, attr->ns, &pop_seen);
    }
    D_LEN("%06x after attrs: %d", x->g.tok, len);

    for (kid = x->kids; kid; kid = ((struct zx_elem_s*)(kid->g.n)))
      len += zx_LEN_WO_any_elem(c, kid);
    
    break;
  }
  zx_pop_seen(pop_seen);
  D_LEN("%06x final: %d", x->g.tok, len);
  return len;
}

/* Called by:  TXENC_SO_ELNAME, zx_ENC_WO_any_elem */
char* zx_attr_wo_enc(char* p, struct zx_attr_s* attr)
{
  struct zx_at_tok* at_tok;
  int ix;
  ZX_OUT_CH(p, ' ');
  if (attr->name) {
    ZX_OUT_MEM(p, attr->name, attr->name_len);
  } else { /* Construct elem string from tok */
    if (!attr->ns && IN_RANGE((attr->g.tok & ZX_TOK_NS_MASK) >> ZX_TOK_NS_SHIFT, 1, zx__NS_MAX))
      attr->ns = zx_ns_tab + ((attr->g.tok & ZX_TOK_NS_MASK) >> ZX_TOK_NS_SHIFT);
    if (attr->ns) {
      ZX_OUT_MEM(p, attr->ns->prefix, attr->ns->prefix_len);
      ZX_OUT_CH(p, ':');
    }
    ix = attr->g.tok & ZX_TOK_TOK_MASK;
    if (ix >= zx__ATTR_MAX) {
      ERR("Attribute token(0x%06x) out of range(0x%04x)", attr->g.tok, zx__ATTR_MAX);
      return p;
    }
    at_tok = zx_at_tab + ix;
    ZX_OUT_MEM(p, at_tok->name, strlen(at_tok->name));
  }
  ZX_OUT_CH(p, '=');
  ZX_OUT_CH(p, '"');
  ZX_OUT_MEM(p, attr->g.s, attr->g.len);
  ZX_OUT_CH(p, '"');
  return p;
}

/* Add inclusive namespaces. */

/* Called by:  TXLEN_SO_ELNAME, zx_LEN_WO_any_elem x2 */
int zx_len_inc_ns(struct zx_ctx* c, struct zx_ns_s** pop_seenp)
{
  int len = 0;
  struct zx_ns_s* ns;
  for (ns = c->inc_ns; ns; ns = ns->inc_n)
    len += zx_len_xmlns_if_not_seen(c, ns, pop_seenp);
  /*c->inc_ns_len = 0;  needs to be processed at every level */
  return len;
}

/* Called by:  TXENC_SO_ELNAME, zx_ENC_WO_any_elem x2 */
void zx_add_inc_ns(struct zx_ctx* c, struct zx_ns_s** pop_seenp)
{
  struct zx_ns_s* ns;
  for (ns = c->inc_ns; ns; ns = ns->inc_n)
    zx_add_xmlns_if_not_seen(c, ns, pop_seenp);
  /*c->inc_ns = 0;  needs to be processed at every level */
}

/*() Check if a namespace is already in inclusive namespaces so we do not need to add it again. */

/* Called by:  zxsig_validate */
int zx_in_inc_ns(struct zx_ctx* c, struct zx_ns_s* new_ns)
{
  struct zx_ns_s* ns;
  for (ns = c->inc_ns; ns; ns = ns->inc_n)
    if (new_ns == ns)
      return 1;
  return 0;
}

/* Called by:  TXENC_SO_ELNAME, zx_ENC_WO_any_elem */
void zx_see_attr_ns(struct zx_ctx* c, struct zx_attr_s* aa, struct zx_ns_s** pop_seenp)
{
  for (; aa; aa = (struct zx_attr_s*)aa->g.n) {
     zx_add_xmlns_if_not_seen(c, aa->ns, pop_seenp);
  }
}

/*() Render element into string. The XML attributes and elements are
 * processed in wire order by chasing wo pointers. This is what you want for
 * validating signatures on other people's XML documents. */

/* Called by:  main x2, zx_EASY_ENC_elem, zx_ENC_WO_any_elem x2 */
char* zx_ENC_WO_any_elem(struct zx_ctx* c, struct zx_elem_s* x, char* p)
{
  //const struct zx_el_desc* ed;
  struct zx_el_tok* el_tok;
  struct zx_ns_s* pop_seen = 0;
  struct zx_attr_s* attr;
  struct zx_elem_s* kid;
  int ix;
#if D_LEN_ENA
  char* b = p;
#endif
  switch (x->g.tok) {
  case zx_root_ELEM:
    if (c->inc_ns)
      zx_add_inc_ns(c, &pop_seen);
    p = zx_enc_seen(p, pop_seen);
    for (kid = x->kids; kid; kid = (struct zx_elem_s*)kid->g.n)
      p = zx_ENC_WO_any_elem(c, kid, p);
    break;
  case ZX_TOK_DATA:
    ZX_OUT_STR(p, x);
    break;
  case zx_ds_Signature_ELEM:
    if (x == c->exclude_sig)
      return p;
    /* fall thru */
  default:
    ZX_OUT_CH(p, '<');
    if (x->g.s) {
      ZX_OUT_MEM(p, x->g.s, x->g.len);
    } else { /* Construct elem string from tok */
      if (!x->ns) {
	ix = (x->g.tok >> ZX_TOK_NS_SHIFT)&(ZX_TOK_NS_MASK >> ZX_TOK_NS_SHIFT);
	if (ix >= zx__NS_MAX) {
	  ERR("Namespace index of token(0x%06x) out of range(0x%02x)", x->g.tok, zx__NS_MAX);
	  return p;
	}
	x->ns = zx_ns_tab + ix;
      }
      //ed = zx_el_desc_lookup(tok);
      ix = x->g.tok & ZX_TOK_TOK_MASK;
      if (ix >= zx__ELEM_MAX) {
	ERR("Element token(0x%06x) out of range(0x%04x)", x->g.tok, zx__ELEM_MAX);
	return p;
      }
      el_tok = zx_el_tab + ix;
      ZX_OUT_MEM(p, x->ns->prefix, x->ns->prefix_len);
      ZX_OUT_CH(p, ':');
      ZX_OUT_MEM(p, el_tok->name, strlen(el_tok->name));
    }
    D_LEN("%06x   ** tag start: %d", x->g.tok, p-b);
    zx_add_xmlns_if_not_seen(c, x->ns, &pop_seen);
    if (c->inc_ns)
      zx_add_inc_ns(c, &pop_seen);
    D_LEN("%06x   after inc_ns: %d", x->g.tok, p-b);
    zx_see_attr_ns(c, x->attr, &pop_seen);
    p = zx_enc_seen(p, pop_seen);
    D_LEN("%06x   after seen ns: %d", x->g.tok, p-b);

    for (attr = x->attr; attr; attr = (struct zx_attr_s*)attr->g.n)
      p = zx_attr_wo_enc(p, attr);
    ZX_OUT_CH(p, '>');
    D_LEN("%06x   after attrs: %d", x->g.tok, p-b);
    
    for (kid = x->kids; kid; kid = (struct zx_elem_s*)kid->g.n)
      p = zx_ENC_WO_any_elem(c, kid, p);
    D_LEN("%06x   after kids: %d", x->g.tok, p-b);
    
    ZX_OUT_CH(p, '<');
    ZX_OUT_CH(p, '/');
    if (x->g.s) {
      ZX_OUT_MEM(p, x->g.s, x->g.len);
    } else { /* Construct elem string from tok */
      ZX_OUT_MEM(p, x->ns->prefix, x->ns->prefix_len);
      ZX_OUT_CH(p, ':');
      ZX_OUT_MEM(p, el_tok->name, strlen(el_tok->name));
    }
    ZX_OUT_CH(p, '>');
  }
  zx_pop_seen(pop_seen);
  D_LEN("%06x   final: %d", x->g.tok, p-b);
  return p;
}

/*(i) Render any element in wire order, as often needed in validating canonicalizations. */

/* Called by:  main x3, so_enc_dec, zxid_a7n2str, zxid_add_header_refs x29, zxid_addmd, zxid_anoint_a7n x2, zxid_anoint_sso_resp x2, zxid_az_soap x2, zxid_cache_epr, zxid_call_epr, zxid_idp_sso x2, zxid_lecp_check, zxid_mk_art_deref, zxid_mk_enc_a7n, zxid_mk_enc_id, zxid_mk_mni, zxid_mni_do_ss, zxid_nid2str, zxid_pep_az_base_soap_pepmap x3, zxid_pep_az_soap_pepmap x3, zxid_reg_svc, zxid_slo_resp_redir, zxid_snarf_eprs_from_ses, zxid_soap_call_envelope, zxid_soap_call_hdr_body, zxid_soap_cgi_resp_body, zxid_sp_meta, zxid_sp_mni_redir, zxid_sp_mni_soap, zxid_sp_slo_redir, zxid_sp_slo_soap, zxid_sp_soap_dispatch x5, zxid_sp_sso_finalize, zxid_ssos_anreq, zxid_start_sso_url, zxid_token2str, zxid_write_ent_to_cache, zxid_wsc_prepare_call, zxid_wsf_sign x2, zxid_wsf_validate_a7n, zxid_wsp_decorate, zxsig_sign, zxsig_validate x2 */
struct zx_str* zx_EASY_ENC_elem(struct zx_ctx* c, struct zx_elem_s* x)
{
  int len = zx_LEN_WO_any_elem(c, x);
  char* buf = ZX_ALLOC(c, len+1);
  char* p = zx_ENC_WO_any_elem(c, x, buf);
  if (p != buf+len) {
    ERR("Encoded length(%d) does not match computed length(%d). ED(%.*s)", p-buf, len, p-buf, buf);
    len = p-buf;
  }
  buf[len] = 0;
  return zx_ref_len_str(c, len, buf);
}

/* ----------- F r e e ----------- */

/* Called by:  zx_free_elem */
void zx_free_attr(struct zx_ctx* c, struct zx_attr_s* aa, int free_strs)
{
  struct zx_attr_s* aan;
  for (; aa; aa = aan) {      /* attributes */
    aan = (struct zx_attr_s*)aa->g.n;
    if (free_strs && aa->name)
      ZX_FREE(c, aa->name);
    if (free_strs && aa->g.s)
      ZX_FREE(c, aa->g.s);
    ZX_FREE(c, aa);
  }
}

/*() Free element and its attributes, child elements, and content.
 * Depth first traversal of data structure to free it and its subelements. Simple
 * strings are handled as a special case according to the free_strs flag. This
 * is useful if the strings point to underlying data from the wire that was
 * allocated differently. */

/* Called by:  main, zx_free_elem, zxid_mk_mni, zxid_parse_meta, zxid_set_fault, zxid_set_tas3_status */
void zx_free_elem(struct zx_ctx* c, struct zx_elem_s* x, int free_strs)
{
  struct zx_elem_s* ae;
  struct zx_elem_s* aen;
  
  if (x->g.tok == ZX_TOK_NOT_FOUND && free_strs) {
    ae = x;
    if (ae->g.s)
      ZX_FREE(c, ae->g.s);
  }
  zx_free_attr(c, x->attr, free_strs);

  for (ae = x->kids; ae; ae = aen) {      /* elements */
    aen = (struct zx_elem_s*)ae->g.n;
    switch (ae->g.tok) {
    case ZX_TOK_DATA:
      if (free_strs)
	zx_str_free(c, &ae->g);
      else
	ZX_FREE(c, ae);
      break;
    default:
      zx_free_elem(c, ae, free_strs);
      //zx_FREE_elem(c, ae, free_strs);
    }
  }
  ZX_FREE(c, x);
}

#ifdef ZX_ENA_AUX

/* *** clone code has not been updated since great namespace reform */

/* Called by:  zxenc_pubkey_enc, zxid_as_call_ses, zxid_attach_sol1_usage_directive, zxid_idp_sso, zxid_map_identity_token x3, zxid_mk_a7n, zxid_mk_attribute, zxid_mk_authn_req, zxid_mk_lu_Status x3, zxid_mk_saml_resp, zxid_mk_tas3_status x4, zxid_parse_mni x3 */
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
  struct zx_attr_s* aa;
  struct zx_elem_s* ae;
  struct zx_attr_s* aan;
  struct zx_elem_s* aen;
  struct zx_attr_s* aann;
  struct zx_elem_s* aenn;
  char* p;

  if (x->g.tok == ZX_TOK_NOT_FOUND) {
    ae = (struct zx_elem_s*)x;
    ZX_DUPALLOC(c, struct zx_elem_s, aen, ae);
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
  
  for (aann = 0, aa = x->attr; aa; aa = (struct zx_attr_s*)aa->ss.g.n) {  /* unknown attributes */
    ZX_DUPALLOC(c, struct zx_attr_s, aan, aa);
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
  
  for (aenn = 0, ae = x->kids; ae; ae = (struct zx_elem_s*)ae->gg.g.n) {  /* unknown elements */
    switch (ae->g.tok) {
    case ZX_TOK_DATA:
      ZX_DUPALLOC(c, struct zx_str, aen, ae);
      if (aen->g.s) {
	p = ZX_ALLOC(c, aen->g.len);
	memcpy(p, aen->g.s, aen->g.len);
	aen->s = p;
      }
      break;
    default:
      aen = (struct zx_elem_s*)zx_DEEP_CLONE_elem(c, &ae->gg, dup_strs);
    }
    if (!aenn)
      x->kids = aen;
    else
      aenn->gg.g.n = &aen->gg.g;
    aenn = aen;
  }
  return x;
}

/* Called by:  TXDUP_STRS_ELNAME */
void zx_dup_strs_common(struct zx_ctx* c, struct zx_elem_s* x)
{
  struct zx_attr_s* aa;
  struct zx_elem_s* ae;
  char* p;
  
  if (x->g.tok == ZX_TOK_NOT_FOUND) {
    ae = (struct zx_elem_s*)x;
    p = ZX_ALLOC(c, ae->name_len);
    memcpy(p, ae->name, ae->name_len);
    ae->name = p;
  }
  
  /* *** deal with xmlns specifications in exc c14n way */

  for (aa = x->attr; aa; aa = (struct zx_attr_s*)aa->ss.g.n) {  /* unknown attributes */
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

  for (ae = x->kids; ae; ae = (struct zx_elem_s*)ae->gg.g.n)   /* unknown elements */
    switch (ae->g.tok) {
    case ZX_TOK_DATA:
      if (ae->g.s) {
	p = ZX_ALLOC(c, ae->g.len);
	memcpy(p, ae->g.s, ae->g.len);
	ss->s = p;
      }
      break;
    default:
      zx_DUP_STRS_elem(c, &ae->gg);
    }
}

int zx_walk_so_unknown_attributes(struct zx_ctx* c, struct zx_elem_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
{
  struct zx_attr_s* aa;
  int ret;
  
  for (aa = x->attr; aa; aa = (struct zx_attr_s*)aa->ss.g.n) {  /* unknown attributes */
    ret = callback(&aa->ss.g, ctx);
    if (ret)
      return ret;
  }
  return 0;
}

int zx_walk_so_unknown_elems_and_content(struct zx_ctx* c, struct zx_elem_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
{
  struct zx_elem_s* ae;
  int ret;
  
  for (ae = x->kids; ae; ae = (struct zx_elem_s*)ae->gg.g.n) {  /* unknown elements */
    switch (ae->g.tok) {
    case ZX_TOK_DATA:
      ret = callback(ae, ctx);
      break;
    default:
      ret = zx_WALK_SO_elem(c, ae, ctx, callback);
    }
    if (ret)
      return ret;
  }
  return 0;
}

/* Called by: */
struct zx_elem_s* zx_deep_clone_elems(struct zx_ctx* c, struct zx_elem_s* x, int dup_strs)
{
  struct zx_elem_s* se;
  struct zx_elem_s* sen;
  struct zx_elem_s* senn;
  
  for (senn = 0, se = x; se; se = (struct zx_elem_s*)se->g.n) {
    sen = zx_DEEP_CLONE_elem(c, se, dup_strs);
    if (!senn)
      x = sen;
    else
      senn->g.n = &sen->g;
    senn = sen;
  }
  return x;
}


int zx_walk_so_elems(struct zx_ctx* c, struct zx_elem_s* se, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
{
  int ret;

  for (; se; se = (struct zx_elem_s*)se->g.n) {
    ret = zx_WALK_SO_elem(c, se, ctx, callback);
    if (ret)
      return ret;
  }
  return 0;
}

/* Called by: */
void zx_dup_strs_elems(struct zx_ctx* c, struct zx_elem_s* se)
{
  for (; se; se = (struct zx_elem_s*)se->g.n)
    zx_DUP_STRS_elem(c, se);
}

#endif  /* end ZX_ENA_AUX */

/* EOF -- zxlib.c */
