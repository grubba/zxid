/* zx.h  -  Common definitions for zx generated code (encoders, decoders, etc.)
 * Copyright (c) 2010 Sampo Kellomaki (sampo@iki.fi), All Rights Reserved.
 * Copyright (c) 2006-2009 Symlabs (symlabs@symlabs.com), All Rights Reserved.
 * Author: Sampo Kellomaki (sampo@iki.fi)
 * This is confidential unpublished proprietary source code of the author.
 * NO WARRANTY, not even implied warranties. Contains trade secrets.
 * Distribution prohibited unless authorized in writing.
 * Licensed under Apache License 2.0, see file COPYING.
 * $Id: zx.h,v 1.45 2009-11-29 12:23:06 sampo Exp $
 *
 * 28.5.2006, created --Sampo
 * 7.8.2006,  renamed from dec.h to zx.h and added comments --Sampo
 * 26.8.2006, some refactoring for CSE --Sampo
 * 23.9.2006, mild re-engineering for WO support --Sampo
 * 23.2.2008, added support for function pointers to malloc(),
 *            realloc(), and free() --Sampo
 *
 * This file is included from various generated grammar files.
 */

#ifndef _zx_h
#define _zx_h

#include <memory.h>
#include <string.h>
#include <stdarg.h>

#ifdef USE_OPENSSL
#include <openssl/x509.h>
#include <openssl/rsa.h>
#else
#define X509 void
#define RSA void
#endif

#ifdef MINGW
#include <windows.h>
#define pthread_mutex_t CRITICAL_SECTION
#define fdtype HANDLE
#else
#include <pthread.h>
#define fdtype int
#endif

//#ifndef const
//#define const  /* const causes swig java to break */
//#endif

#ifdef __cplusplus
extern "C" {
#endif

/* Error Codes (low level or XML parsing) */

#define ZXERR_EOF             0x0001  /* return due to EOF condition */
#define ZXERR_MISMATCH_CLOSE  0x0002  /* mismatching close tag */
#define ZXERR_BAD_ATTR_NS     0x0004  /* namespace violation in attribute */
#define ZXERR_BAD_ELEM_NS     0x0008  /* namespace violation in element */
#define ZXERR_MISSING_ATTR    0x0010  /* mandatory attribute(s) missing */
#define ZXERR_EXTRA_ATTR      0x0020  /* unforeseen attribute(s) present */
#define ZXERR_MISSING_ELEM    0x0040  /* mandatory element(s) missing or of wrong cardinality */
#define ZXERR_EXTRA_ELEM      0x0080  /* unforeseen element(s) present */
#define ZXERR_ELEM_ORDER      0x0100  /* ordering of elements violates schema */
#define ZXERR_BAD_NS_PREFIX   0x0200  /* unknown namespace prefix has appeared */
#define ZXERR_TAG_NOT_CLOSED  0x0400  /* open tag seen, but eof seen before close */
#define ZXERR_MASK            0x7fff
#define ZXERR_ATTR_FLAG       0x8000  /* Not an error. Marker to distinguish elements from attributes. */

struct zx_any_elem_s;
struct zx_any_attr_s;

/*(s) Namespace management. The context references this table. The array is
 * terminated by an element with empty URL (url_len == 0). The elements
 * of the array are the official namespace prefixes derived from
 * target() directives in the .sg files. The linked list hanging from
 * n field contains a stack of runtime assigned namespace prefixes.
 * The empty marker element serves as a root for list holding namespace
 * prefixes of namespaces not understood by the system. */

struct zx_ns_s {
  struct zx_ns_s* n;        /* For holding runtime equivalences as a linked list. */
  struct zx_ns_s* m;        /* For a rt equivalence, pointer to the master entry. */
  struct zx_ns_s* seen;     /* Pointer to other "seen" namespaces with same prefix (stack) */
  struct zx_ns_s* seen_n;   /* Next prefix in seen structure (list) */
  struct zx_ns_s* seen_p;   /* Previous prefix in seen structure (list) */
  struct zx_ns_s* seen_pop; /* Pop list for seen stack (used in the end of an element). */
  struct zx_ns_s* inc_n;    /* Next link for InclusiveNamespaces */
#if 0
  char flags;               /* 0x01 == unknown */
  char pad1;
  char pad2;
  char pad3;
#endif
  int prefix_len;
  const char* prefix;
  int url_len;  /* 0 = end of nstab */
  const char* url;
};

/* Context tracks the input and namespaces. It is also passed to memory allocator. */

struct zx_ctx {
  const char* bas;   /* base is C# keyword :-( */
  const char* p;     /* Current scan pointer */
  const char* lim;
  struct zx_ns_s* ns_tab;      /* Array, such as zx_ns_tab, see zx_prepare_dec_ctx() */
  struct zx_ns_s* unknown_ns;  /* Linked list of unknown namespaces. */
  /* Namespace prefixes that have been "seen", each prefix is a stack.
   * We keep these prefixes in a doubly linked list so we can add and
   * remove in the middle. */
  struct zx_ns_s guard_seen_n;
  struct zx_ns_s guard_seen_p;
  void* exclude_sig;  /* If nonnull, causes specified signature to be
		       * excluded. This is needed to avoid the signature
		       * under verification in the canonicalization.
		       * See zxsig.c:zxsig_validate(). */
  struct zx_ns_s* inc_ns_len;  /* Derived from InclusiveNamespaces/@PrefixList,length computation phase, */
  struct zx_ns_s* inc_ns;  /* Encoding phase. See zxsig_validate(). */
  /* Allow ZX_ALLOC() layer to be adapted to custome allocators, like Apache pool allocator. */
  void* (*malloc_func)(size_t);
  void* (*realloc_func)(void*, size_t);
  void  (*free_func)(void*);
#ifdef USE_PTHREAD
  pthread_mutex_t mx;
#endif
  char canon_inopt;
  char pad1;
  char pad2;
  char pad3;
  char pad4;
  char pad5;
  char pad6;
  char pad7;
};

/* We arrange all structs to start with a common header (16 bytes on 32bit platforms) */

struct zx_node_s {
  struct zx_node_s* n;    /* next pointer for compile time construction of data structures */
  struct zx_node_s* wo;   /* next pointer for canonicalization order (wire order) */
  struct zx_ns_s* ns;     /* namespace of an element or attribute */
  short tok;              /* token number of the tag represented by this struct */
  short err;              /* error mask */
};

//#define ZX_NEXT(x) ((void*)((struct zx_node_s*)(x))->n)
//#define ZX_NEXT(x) ((void*)((x)->gg.g.n))
#define ZX_NEXT(x) ((x)->gg.g.n)

/* Simple elements, base type for complex elements. */

struct zx_elem_s {
  struct zx_node_s g;              /* Common fields for all nodes */
  struct zx_elem_s* kids;          /* root of wo list representing child elements */
  struct zx_any_attr_s* any_attr;  /* list of attributes not understood by parser */
  struct zx_any_elem_s* any_elem;  /* list of elements not understood by parser */
  struct zx_ns_s* xmlns;           /* xmlns declarations (for inc_ns processing) */
  struct zx_str* content;          /* non-element content, if any */
};

struct zx_elem_s* zx_new_simple_elem(struct zx_ctx* c, struct zx_str* ss);
struct zx_elem_s* zx_ref_len_simple_elem(struct zx_ctx* c, int len, const char* s);
struct zx_elem_s* zx_ref_simple_elem(struct zx_ctx* c, const char* s);
struct zx_elem_s* zx_dup_len_simple_elem(struct zx_ctx* c, int len, const char* s);
struct zx_elem_s* zx_dup_simple_elem(struct zx_ctx* c, const char* s);
#define ZX_SIMPLE_ELEM_CHK(el) ((el) && (el)->gg.content && (el)->gg.content->len && (el)->gg.content->s && (el)->gg.content->s[0])

/* All attributes are represented as a string, as follows. */

struct zx_str {
  struct zx_node_s g;
  int len;
  char* s;
};

struct zx_str* zx_ref_str(struct zx_ctx* c, const char* s);  /* ref points to underlying data */
struct zx_str* zx_ref_len_str(struct zx_ctx* c, int len, const char* s);
struct zx_str* zx_new_len_str(struct zx_ctx* c, int len);
struct zx_str* zx_dup_str(struct zx_ctx* c, const char* s);  /* data is new memory */
struct zx_str* zx_dup_len_str(struct zx_ctx* c, int len, const char* s);
char* zx_alloc_sprintf(struct zx_ctx* c, int* retlen, const char* f, ...);
struct zx_str* zx_strf(struct zx_ctx* c, const char* f, ...);  /* data is new memory */
void  zx_str_free(struct zx_ctx* c, struct zx_str* ss);   /* free both ss->s and ss */
char* zx_str_to_c(struct zx_ctx* c, struct zx_str* ss);
void  zx_str_conv(struct zx_str* ss, int* out_len, char** out_s);  /* SWIG typemap friendly */
int   zx_str_ends_in(struct zx_str* ss, int len, const char* suffix);
#define ZX_STRCMP(a, b) ((a)?((b)?((a)->len == (b)->len?memcmp((a)->s, (b)->s, (a)->len):(a)->len - (b)->len):1):((b)?-1:0))
#define ZX_STR_EQ(ss, cstr) ((ss) && (cstr) && (ss)->s && (ss)->len == strlen(cstr) && !memcmp((cstr), (ss)->s, (ss)->len))
#define ZX_STR_ENDS_IN_CONST(ss, suffix) zx_str_ends_in((ss), sizeof(suffix)-1, (suffix))
#define ZX_CONTENT_EQ_CONST(e, c) ((e) && (e)->content->len == sizeof(c)-1 && !memcmp((e)->content->s, (c), sizeof(c)-1))

/* Elements that are unforeseen (errornous or extensions). */

struct zx_any_elem_s {
  struct zx_elem_s gg;
  int name_len;
  char* name;
};

#define ZX_ANY_EL(x) ((struct zx_any_elem_s*)(x))

/* Attributes that are unforeseen (errornous or extensions). */

struct zx_any_attr_s {
  struct zx_str ss;
  int name_len;
  char* name;
};

#define ZX_ANY_AT(x) ((struct zx_any_attr_s*)(x))

#define ZX_ELEM_EXT struct zx_elem_s gg;

char* zx_memmem(const char* haystack, int haystack_len, const char* needle, int needle_len);
void* zx_alloc(struct zx_ctx* c, int size);
void* zx_zalloc(struct zx_ctx* c, int size);
void* zx_free(struct zx_ctx* c, void* p);
char* zx_dup_cstr(struct zx_ctx* c, const char* str);
#define ZX_ALLOC(c, size) zx_alloc((c), (size))
#define ZX_ZALLOC(c, typ) ((typ*)zx_zalloc((c), sizeof(typ)))
#define ZX_DUPALLOC(c, typ, n, o) (n) = (typ*)zx_alloc((c), sizeof(typ)); memcpy((n), (o), sizeof(typ))
#define ZX_FREE(c, p) zx_free((c), (p))

void  zx_reset_ctx(struct zx_ctx* ctx);
struct zx_ctx* zx_init_ctx();   /* from malloc(3) */

/* N.B. All string scanning assumes buffer is terminated with C string style nul byte. */
#define ZX_SKIP_WS_P(c,p,x) MB for (; ONE_OF_4(*(p), ' ', '\n', '\r', '\t'); ++(p)) ; if (!*(p)) return x; ME
#define ZX_SKIP_WS(c,x)     ZX_SKIP_WS_P((c),(c)->p,x)
#define ZX_LOOK_FOR_P(c,ch,p) MB char* pp = memchr((p), (ch), (c)->lim - (p)); if (!pp) goto look_for_not_found; else (p) = pp; ME
#define ZX_LOOK_FOR(c,ch)   ZX_LOOK_FOR_P((c),(ch),(c)->p)

#define ZX_OUT_CH(p, ch)        (*((p)++) = (ch))
#define ZX_OUT_MEM(p, mem, len) MB memcpy((p), (mem), (len)); (p) += (len); ME
#define ZX_OUT_STR(p, str) ZX_OUT_MEM(p, ((struct zx_str*)(x))->s, ((struct zx_str*)(x))->len)

#define ZX_OUT_TAG(p, tag) ZX_OUT_MEM(p, tag, sizeof(tag)-1)
#define ZX_OUT_CLOSE_TAG(p, tag) ZX_OUT_MEM(p, tag, sizeof(tag)-1)
#if 1
#define ZX_LEN_SIMPLE_TAG(tok, len, ns) (1 + ((tok == ZX_TOK_NOT_FOUND && ns && ns->prefix_len)?ns->prefix_len+1:0) + len)
#define ZX_OUT_SIMPLE_TAG(p, tok, tag, len, ns) MB ZX_OUT_CH(p, '<'); if (tok == ZX_TOK_NOT_FOUND && ns && ns->prefix_len) { ZX_OUT_MEM(p, ns->prefix, ns->prefix_len); ZX_OUT_CH(p, ':'); } ZX_OUT_MEM(p, tag, len); ME
#define ZX_OUT_SIMPLE_CLOSE_TAG(p, tok, tag, len, ns) MB ZX_OUT_CH(p, '<'); ZX_OUT_CH(p, '/');  if (tok == ZX_TOK_NOT_FOUND && ns && ns->prefix_len) { ZX_OUT_MEM(p, ns->prefix, ns->prefix_len); ZX_OUT_CH(p, ':'); } ZX_OUT_MEM(p, tag, len); ZX_OUT_CH(p, '>'); ME
#else
#define ZX_OUT_SIMPLE_TAG(p, tag, len, ns) MB ZX_OUT_CH(p, '<'); if (0&&ns) { ZX_OUT_MEM(p, ns->prefix, ns->prefix_len); ZX_OUT_CH(p, ':'); } ZX_OUT_MEM(p, tag, len); ME
#define ZX_OUT_SIMPLE_CLOSE_TAG(p, tag, len, ns) MB ZX_OUT_CH(p, '<'); ZX_OUT_CH(p, '/');  if (0&&ns) { ZX_OUT_MEM(p, ns->prefix, ns->prefix_len); ZX_OUT_CH(p, ':'); } ZX_OUT_MEM(p, tag, len); ZX_OUT_CH(p, '>'); ME
#endif

/* Special token values. */
#define ZX_TOK_XMLNS     (-4)
#define ZX_TOK_DATA      (-3)
#define ZX_TOK_NOT_FOUND (-2)
struct zx_tok { const char* name; const char* prefix; struct zx_ns_s* ns; };

/*struct zx_note_s* zx_clone_any(struct zx_ctx* c, struct zx_note_s* n, int dup_strs); TBD */
/*void zx_free_any(struct zx_ctx* c, struct zx_note_s* n, int free_strs); TBD */

int   zx_date_time_to_secs(const char* dt);
int   write2_or_append_lock_c_path(const char* c_path, int len1, const char* data1, int len2, const char* data2, const char* which, int seeky, int flag);
int   zx_report_openssl_error(const char* logkey);

#if 0
void  zx_fix_any_elem_dec(struct zx_ctx* c, struct zx_any_elem_s* x, const char* nam, int namlen);
int   zx_is_ns_prefix(struct zx_ns_s* ns, int len, const char* prefix);
#endif
int zx_dump_ns_tab(struct zx_ctx* c, int flags);
struct zx_ns_s* zx_new_ns(struct zx_ctx* c, int prefix_len, const char* prefix, int url_len, const char* url, int unknown);
struct zx_ns_s* zx_locate_ns_by_prefix(struct zx_ctx* c, int len, const char* prefix);
struct zx_ns_s* zx_prefix_seen(struct zx_ctx* c, int len, const char* prefix);
struct zx_ns_s* zx_prefix_seen_whine(struct zx_ctx* c, int len, const char* prefix, const char* logkey, int mk_dummy_ns);
struct zx_ns_s* zx_scan_xmlns(struct zx_ctx* c);
void  zx_see_elem_ns(struct zx_ctx* c, struct zx_ns_s** pop_seen, struct zx_elem_s* el);
void  zx_pop_seen(struct zx_ns_s* ns);
int zx_format_parse_error(struct zx_ctx* ctx, char* buf, int siz, char* logkey);

/* zxcrypto.c - Glue to OpenSSL low level */

char* zx_raw_digest2(struct zx_ctx* c, char* md, char* const algo, int len, const char* s, int len2, const char* s2);
struct zx_str* zx_raw_cipher(struct zx_ctx* c, const char* algo, int encflag, struct zx_str* key, int len, const char* s, int iv_len, const char* iv);
struct zx_str* zx_rsa_pub_enc(struct zx_ctx* c, struct zx_str* plain, RSA* rsa_pkey, int pad);
struct zx_str* zx_rsa_pub_dec(struct zx_ctx* c, struct zx_str* ciphered, RSA* rsa_pkey, int pad);
struct zx_str* zx_rsa_priv_dec(struct zx_ctx* c, struct zx_str* ciphered, RSA* rsa_pkey, int pad);
struct zx_str* zx_rsa_priv_enc(struct zx_ctx* c, struct zx_str* plain, RSA* rsa_pkey, int pad);
RSA*  zx_get_rsa_pub_from_cert(X509* cert, char* logkey);
void  zx_rand(char* buf, int n_bytes);
char* zx_md5_crypt(const char* pw, const char* salt, char* buf);

/* Common Subexpression Elimination (CSE) for generated code. */

const struct zx_tok* zx_tok_by_ns(const struct zx_tok* zt, const struct zx_tok* lim, int len, const char* name, struct zx_ns_s* ns);
int   zx_len_xmlns_if_not_seen(struct zx_ctx* c, struct zx_ns_s* ns, struct zx_ns_s** pop_seen);
void  zx_add_xmlns_if_not_seen(struct zx_ctx* c, struct zx_ns_s* ns, struct zx_ns_s** pop_seen);
char* zx_enc_seen(char* p, struct zx_ns_s* ns);
int   zx_len_so_common(struct zx_ctx* c, struct zx_elem_s* x, struct zx_ns_s** pop_seenp);
int   zx_len_wo_common(struct zx_ctx* c, struct zx_elem_s* x, struct zx_ns_s** pop_seenp);
void  zx_see_unknown_attrs_ns(struct zx_ctx* c, struct zx_any_attr_s* aa, struct zx_ns_s** pop_seenp);
char* zx_enc_unknown_attrs(char* p, struct zx_any_attr_s* aa);
char* zx_enc_so_unknown_elems_and_content(struct zx_ctx* c, char* p, struct zx_elem_s* x);
struct zx_str* zx_easy_enc_common(struct zx_ctx* c, char* p, char* buf, int len);
int   zx_attr_so_len(struct zx_ctx* c, struct zx_str* attr, int name_size, struct zx_ns_s** pop_seenp);
char* zx_attr_so_enc(char* p, struct zx_str* attr, char* name, int name_len);
int   zx_attr_wo_len(struct zx_ctx* c, struct zx_str* attr, int name_size, struct zx_ns_s** pop_seenp);
char* zx_attr_wo_enc(char* p, struct zx_str* attr, char* name, int name_len);
void  zx_free_attr(struct zx_ctx* c, struct zx_str* attr, int free_strs);
void  zx_free_elem_common(struct zx_ctx* c, struct zx_elem_s* x, int free_strs);
void  zx_free_simple_elems(struct zx_ctx* c, struct zx_elem_s* se, int free_strs);

#ifdef ZX_ENA_AUX
void  zx_dup_attr(struct zx_ctx* c, struct zx_str* attr);
struct zx_str* zx_clone_attr(struct zx_ctx* c, struct zx_str* attr);
struct zx_elem_s* zx_clone_elem_common(struct zx_ctx* c, struct zx_elem_s* x, int size, int dup_strs);
void  zx_dup_strs_common(struct zx_ctx* c, struct zx_elem_s* x);
int   zx_walk_so_unknown_attributes(struct zx_ctx* c, struct zx_elem_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx));
int   zx_walk_so_unknown_elems_and_content(struct zx_ctx* c, struct zx_elem_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx));
struct zx_elem_s* zx_deep_clone_simple_elems(struct zx_ctx* c, struct zx_elem_s* x, int dup_strs);
int   zx_walk_so_simple_elems(struct zx_ctx* c, struct zx_elem_s* se, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx));
void  zx_dup_strs_simple_elems(struct zx_ctx* c, struct zx_elem_s* se);
#endif

void  zx_prepare_dec_ctx(struct zx_ctx* c, struct zx_ns_s* ns_tab, const char* start, const char* lim);
int   zx_scan_data(struct zx_ctx* c, struct zx_elem_s* el);
int   zx_scan_pi_or_comment(struct zx_ctx* c);
struct zx_str* zx_dec_unknown_attr(struct zx_ctx* c, struct zx_elem_s* el, const char* name, const char* data, int tok, int ctx_tok);
const char* zx_dec_attr_val(struct zx_ctx* c, const char** name, const char* func);
void zx_dec_reverse_lists(struct zx_elem_s* x);
void  zx_xml_parse_err(struct zx_ctx* c, char quote, const char* func, const char* msg);
void zx_xml_parse_err_mismatching_close_tag(struct zx_ctx* c, const char* func, const char* name, int tok);
const char* zx_scan_elem_start(struct zx_ctx* c, const char* func);

int   zx_len_inc_ns(struct zx_ctx* c, struct zx_ns_s** pop_seenp);
void  zx_add_inc_ns(struct zx_ctx* c, struct zx_ns_s** pop_seenp);

#if 0
#define ZX_DEC_TAG_NOT_YET_CLOSED(x) (x).err |= ZXERR_TAG_NOT_CLOSED
#define ZX_DEC_TAG_NOW_CLOSED(x)     (x).err &= ~ZXERR_TAG_NOT_CLOSED
#define ZX_DEC_TAG_MISMATCH_CLOSE(x) (x).err |= ZXERR_MISMATCH_CLOSE
#else
#define ZX_DEC_TAG_NOT_YET_CLOSED(x)
#define ZX_DEC_TAG_NOW_CLOSED(x)
#define ZX_DEC_TAG_MISMATCH_CLOSE(x)
#endif

#define SIG_ALGO_RSA_SHA1  "http://www.w3.org/2000/09/xmldsig#rsa-sha1"
#define SIG_ALGO_DSA_SHA1  "http://www.w3.org/2000/09/xmldsig#dsa-sha1"
#define SIG_ALGO    SIG_ALGO_RSA_SHA1
#define DIGEST_ALGO        "http://www.w3.org/2000/09/xmldsig#sha1"
#define CANON_ALGO         "http://www.w3.org/2001/10/xml-exc-c14n#"
#define ENVELOPED_ALGO     "http://www.w3.org/2000/09/xmldsig#enveloped-signature"
#define ENC_ALGO_TRIPLEDES_CBC "http://www.w3.org/2001/04/xmlenc#tripledes-cbc"
#define ENC_ALGO_AES128_CBC    "http://www.w3.org/2001/04/xmlenc#aes128-cbc"
#define ENC_ALGO_AES192_CBC    "http://www.w3.org/2001/04/xmlenc#aes192-cbc"
#define ENC_ALGO_AES256_CBC    "http://www.w3.org/2001/04/xmlenc#aes256-cbc"
#define ENC_ALGO               ENC_ALGO_AES128_CBC

/* The ENC_KEYTRAN_ALGO setting must agree with setting in zxenc_pubkey_enc() */

#define ENC_KEYTRAN_RSA_1_5    "http://www.w3.org/2001/04/xmlenc#rsa-1_5"
#define ENC_KEYTRAN_RSA_OAEP   "http://www.w3.org/2001/04/xmlenc#rsa-oaep-mgf1p"
#define ENC_KEYTRAN_ALGO       ENC_KEYTRAN_RSA_1_5

#define ENC_ENCKEY_METH        "http://www.w3.org/2001/04/xmlenc#EncryptedKey"
#define ENC_TYPE_ELEMENT       "http://www.w3.org/2001/04/xmlenc#Element"
#define ENC_TYPE_CONTENT       "http://www.w3.org/2001/04/xmlenc#Content"

#ifdef __cplusplus
} // extern "C"
#endif

#endif
