/* c/zx-wst-enc.c - WARNING: This file was automatically generated. DO NOT EDIT!
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
#include "c/zx-wst-data.h"
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

#define EL_NAME   wst_Authenticator
#define EL_STRUCT zx_wst_Authenticator_s
#define EL_NS     wst
#define EL_TAG    Authenticator

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

/* FUNC(zx_LEN_SO_wst_Authenticator) */

/* Compute length of an element (and its subelements). The XML attributes
 * and elements are processed in schema order. */

/* Called by: */
int zx_LEN_SO_wst_Authenticator(struct zx_ctx* c, struct zx_wst_Authenticator_s* x )
{
  struct zx_ns_s* pop_seen = 0;
  struct zx_elem_s* se MAYBE_UNUSED;
#if 1 /* NORMALMODE */
  /* *** in simple_elem case should output ns prefix from ns node. */
  int len = sizeof("<wst:Authenticator")-1 + 1 + sizeof("</wst:Authenticator>")-1;
  if (c->inc_ns_len)
    len += zx_len_inc_ns(c, &pop_seen);
  len += zx_len_xmlns_if_not_seen(c, zx_ns_tab+zx_xmlns_ix_wst, &pop_seen);


#else
  /* root node has no begin tag */
  int len = 0;
#endif
  
  for (se = x->CombinedHash; se; se = (struct zx_elem_s*)se->g.n)
    len += zx_LEN_SO_simple_elem(c,se, sizeof("wst:CombinedHash")-1, zx_ns_tab+zx_xmlns_ix_wst);


  len += zx_len_so_common(c, &x->gg);
  zx_pop_seen(pop_seen);
  ENC_LEN_DEBUG(x, "wst:Authenticator", len);
  return len;
}

/* FUNC(zx_LEN_WO_wst_Authenticator) */

/* Compute length of an element (and its subelements). The XML attributes
 * and elements are processed in wire order and no assumptions
 * are made about namespace prefixes. */

/* Called by: */
int zx_LEN_WO_wst_Authenticator(struct zx_ctx* c, struct zx_wst_Authenticator_s* x )
{
  struct zx_ns_s* pop_seen = 0;
  struct zx_elem_s* se MAYBE_UNUSED;
#if 1 /* NORMALMODE */
  int len = 1 + sizeof("Authenticator")-1 + 1 + 2 + sizeof("Authenticator")-1 + 1;
  
  if (x->gg.g.ns && x->gg.g.ns->prefix_len)
    len += (x->gg.g.ns->prefix_len + 1) * 2;
  if (c->inc_ns_len)
    len += zx_len_inc_ns(c, &pop_seen);
  len += zx_len_xmlns_if_not_seen(c, x->gg.g.ns, &pop_seen);


#else
  /* root node has no begin tag */
  int len = 0;
#endif
  
  for (se = x->CombinedHash; se; se = (struct zx_elem_s*)se->g.n)
    len += zx_LEN_WO_simple_elem(c, se, sizeof("CombinedHash")-1);


  len += zx_len_wo_common(c, &x->gg); 
  zx_pop_seen(pop_seen);
  ENC_LEN_DEBUG(x, "wst:Authenticator", len);
  return len;
}

/* FUNC(zx_ENC_SO_wst_Authenticator) */

/* Render element into string. The XML attributes and elements are
 * processed in schema order. This is what you generally want for
 * rendering new data structure to a string. The wo pointers are not used. */

/* Called by: */
char* zx_ENC_SO_wst_Authenticator(struct zx_ctx* c, struct zx_wst_Authenticator_s* x, char* p )
{
  struct zx_elem_s* se MAYBE_UNUSED;
  ENC_LEN_DEBUG_BASE;
#if 1 /* NORMALMODE */
  struct zx_ns_s* pop_seen = 0;
  /* *** in simple_elem case should output ns prefix from ns node. */
  ZX_OUT_TAG(p, "<wst:Authenticator");
  if (c->inc_ns)
    p = zx_enc_inc_ns(c, p, &pop_seen);
  p = zx_enc_xmlns_if_not_seen(c, p, zx_ns_tab+zx_xmlns_ix_wst, &pop_seen);


  p = zx_enc_unknown_attrs(p, x->gg.any_attr);
#else
  /* root node has no begin tag */
#endif
  
  for (se = x->CombinedHash; se; se = (struct zx_elem_s*)se->g.n)
    p = zx_ENC_SO_simple_elem(c, se, p, "wst:CombinedHash", sizeof("wst:CombinedHash")-1, zx_ns_tab+zx_xmlns_ix_wst);

  p = zx_enc_so_unknown_elems_and_content(c, p, &x->gg);
  
#if 1 /* NORMALMODE */
  ZX_OUT_CLOSE_TAG(p, "</wst:Authenticator>");
  zx_pop_seen(pop_seen);
#else
  /* root node has no end tag either */
#endif
  ENC_LEN_DEBUG(x, "wst:Authenticator", p-enc_base);
  return p;
}

/* FUNC(zx_ENC_WO_wst_Authenticator) */

/* Render element into string. The XML attributes and elements are
 * processed in wire order by chasing wo pointers. This is what you want for
 * validating signatures on other people's XML documents. */

/* Called by: */
char* zx_ENC_WO_wst_Authenticator(struct zx_ctx* c, struct zx_wst_Authenticator_s* x, char* p )
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
  ZX_OUT_MEM(p, "Authenticator", sizeof("Authenticator")-1);
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
  ENC_LEN_DEBUG(x, "wst:Authenticator", p-enc_base);
  return p;
}

/* FUNC(zx_EASY_ENC_SO_wst_Authenticator) */

/* Called by: */
struct zx_str* zx_EASY_ENC_SO_wst_Authenticator(struct zx_ctx* c, struct zx_wst_Authenticator_s* x )
{
  int len;
  char* buf;
  c->ns_tab = ZX_ALLOC(c, sizeof(zx_ns_tab));
  memcpy(c->ns_tab, zx_ns_tab, sizeof(zx_ns_tab));
  len = zx_LEN_SO_wst_Authenticator(c, x );
  buf = ZX_ALLOC(c, len+1);
  return zx_easy_enc_common(c, zx_ENC_SO_wst_Authenticator(c, x, buf ), buf, len);
}

/* FUNC(zx_EASY_ENC_WO_wst_Authenticator) */

/* Called by: */
struct zx_str* zx_EASY_ENC_WO_wst_Authenticator(struct zx_ctx* c, struct zx_wst_Authenticator_s* x )
{
  int len;
  char* buf;
  c->ns_tab = ZX_ALLOC(c, sizeof(zx_ns_tab));
  memcpy(c->ns_tab, zx_ns_tab, sizeof(zx_ns_tab));
  len = zx_LEN_WO_wst_Authenticator(c, x );
  buf = ZX_ALLOC(c, len+1);
  return zx_easy_enc_common(c, zx_ENC_WO_wst_Authenticator(c, x, buf ), buf, len);
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

#define EL_NAME   wst_BinaryExchange
#define EL_STRUCT zx_wst_BinaryExchange_s
#define EL_NS     wst
#define EL_TAG    BinaryExchange

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

/* FUNC(zx_LEN_SO_wst_BinaryExchange) */

/* Compute length of an element (and its subelements). The XML attributes
 * and elements are processed in schema order. */

/* Called by: */
int zx_LEN_SO_wst_BinaryExchange(struct zx_ctx* c, struct zx_wst_BinaryExchange_s* x )
{
  struct zx_ns_s* pop_seen = 0;
  struct zx_elem_s* se MAYBE_UNUSED;
#if 1 /* NORMALMODE */
  /* *** in simple_elem case should output ns prefix from ns node. */
  int len = sizeof("<wst:BinaryExchange")-1 + 1 + sizeof("</wst:BinaryExchange>")-1;
  if (c->inc_ns_len)
    len += zx_len_inc_ns(c, &pop_seen);
  len += zx_len_xmlns_if_not_seen(c, zx_ns_tab+zx_xmlns_ix_wst, &pop_seen);

  len += zx_attr_so_len(x->EncodingType, sizeof("EncodingType")-1);
  len += zx_attr_so_len(x->ValueType, sizeof("ValueType")-1);

#else
  /* root node has no begin tag */
  int len = 0;
#endif
  


  len += zx_len_so_common(c, &x->gg);
  zx_pop_seen(pop_seen);
  ENC_LEN_DEBUG(x, "wst:BinaryExchange", len);
  return len;
}

/* FUNC(zx_LEN_WO_wst_BinaryExchange) */

/* Compute length of an element (and its subelements). The XML attributes
 * and elements are processed in wire order and no assumptions
 * are made about namespace prefixes. */

/* Called by: */
int zx_LEN_WO_wst_BinaryExchange(struct zx_ctx* c, struct zx_wst_BinaryExchange_s* x )
{
  struct zx_ns_s* pop_seen = 0;
  struct zx_elem_s* se MAYBE_UNUSED;
#if 1 /* NORMALMODE */
  int len = 1 + sizeof("BinaryExchange")-1 + 1 + 2 + sizeof("BinaryExchange")-1 + 1;
  
  if (x->gg.g.ns && x->gg.g.ns->prefix_len)
    len += (x->gg.g.ns->prefix_len + 1) * 2;
  if (c->inc_ns_len)
    len += zx_len_inc_ns(c, &pop_seen);
  len += zx_len_xmlns_if_not_seen(c, x->gg.g.ns, &pop_seen);

  len += zx_attr_wo_len(x->EncodingType, sizeof("EncodingType")-1);
  len += zx_attr_wo_len(x->ValueType, sizeof("ValueType")-1);

#else
  /* root node has no begin tag */
  int len = 0;
#endif
  


  len += zx_len_wo_common(c, &x->gg); 
  zx_pop_seen(pop_seen);
  ENC_LEN_DEBUG(x, "wst:BinaryExchange", len);
  return len;
}

/* FUNC(zx_ENC_SO_wst_BinaryExchange) */

/* Render element into string. The XML attributes and elements are
 * processed in schema order. This is what you generally want for
 * rendering new data structure to a string. The wo pointers are not used. */

/* Called by: */
char* zx_ENC_SO_wst_BinaryExchange(struct zx_ctx* c, struct zx_wst_BinaryExchange_s* x, char* p )
{
  struct zx_elem_s* se MAYBE_UNUSED;
  ENC_LEN_DEBUG_BASE;
#if 1 /* NORMALMODE */
  struct zx_ns_s* pop_seen = 0;
  /* *** in simple_elem case should output ns prefix from ns node. */
  ZX_OUT_TAG(p, "<wst:BinaryExchange");
  if (c->inc_ns)
    p = zx_enc_inc_ns(c, p, &pop_seen);
  p = zx_enc_xmlns_if_not_seen(c, p, zx_ns_tab+zx_xmlns_ix_wst, &pop_seen);

  p = zx_attr_so_enc(p, x->EncodingType, " EncodingType=\"", sizeof(" EncodingType=\"")-1);
  p = zx_attr_so_enc(p, x->ValueType, " ValueType=\"", sizeof(" ValueType=\"")-1);

  p = zx_enc_unknown_attrs(p, x->gg.any_attr);
#else
  /* root node has no begin tag */
#endif
  

  p = zx_enc_so_unknown_elems_and_content(c, p, &x->gg);
  
#if 1 /* NORMALMODE */
  ZX_OUT_CLOSE_TAG(p, "</wst:BinaryExchange>");
  zx_pop_seen(pop_seen);
#else
  /* root node has no end tag either */
#endif
  ENC_LEN_DEBUG(x, "wst:BinaryExchange", p-enc_base);
  return p;
}

/* FUNC(zx_ENC_WO_wst_BinaryExchange) */

/* Render element into string. The XML attributes and elements are
 * processed in wire order by chasing wo pointers. This is what you want for
 * validating signatures on other people's XML documents. */

/* Called by: */
char* zx_ENC_WO_wst_BinaryExchange(struct zx_ctx* c, struct zx_wst_BinaryExchange_s* x, char* p )
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
  ZX_OUT_MEM(p, "BinaryExchange", sizeof("BinaryExchange")-1);
  qq = p;

  /* *** sort the namespaces */
  if (c->inc_ns)
    zx_add_inc_ns(c, &pop_seen);
  zx_add_xmlns_if_not_seen(c, x->gg.g.ns, &pop_seen);

  p = zx_enc_seen(p, pop_seen); 
  p = zx_attr_wo_enc(p, x->EncodingType, "EncodingType=\"", sizeof("EncodingType=\"")-1);
  p = zx_attr_wo_enc(p, x->ValueType, "ValueType=\"", sizeof("ValueType=\"")-1);

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
  ENC_LEN_DEBUG(x, "wst:BinaryExchange", p-enc_base);
  return p;
}

/* FUNC(zx_EASY_ENC_SO_wst_BinaryExchange) */

/* Called by: */
struct zx_str* zx_EASY_ENC_SO_wst_BinaryExchange(struct zx_ctx* c, struct zx_wst_BinaryExchange_s* x )
{
  int len;
  char* buf;
  c->ns_tab = ZX_ALLOC(c, sizeof(zx_ns_tab));
  memcpy(c->ns_tab, zx_ns_tab, sizeof(zx_ns_tab));
  len = zx_LEN_SO_wst_BinaryExchange(c, x );
  buf = ZX_ALLOC(c, len+1);
  return zx_easy_enc_common(c, zx_ENC_SO_wst_BinaryExchange(c, x, buf ), buf, len);
}

/* FUNC(zx_EASY_ENC_WO_wst_BinaryExchange) */

/* Called by: */
struct zx_str* zx_EASY_ENC_WO_wst_BinaryExchange(struct zx_ctx* c, struct zx_wst_BinaryExchange_s* x )
{
  int len;
  char* buf;
  c->ns_tab = ZX_ALLOC(c, sizeof(zx_ns_tab));
  memcpy(c->ns_tab, zx_ns_tab, sizeof(zx_ns_tab));
  len = zx_LEN_WO_wst_BinaryExchange(c, x );
  buf = ZX_ALLOC(c, len+1);
  return zx_easy_enc_common(c, zx_ENC_WO_wst_BinaryExchange(c, x, buf ), buf, len);
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

#define EL_NAME   wst_BinarySecret
#define EL_STRUCT zx_wst_BinarySecret_s
#define EL_NS     wst
#define EL_TAG    BinarySecret

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

/* FUNC(zx_LEN_SO_wst_BinarySecret) */

/* Compute length of an element (and its subelements). The XML attributes
 * and elements are processed in schema order. */

/* Called by: */
int zx_LEN_SO_wst_BinarySecret(struct zx_ctx* c, struct zx_wst_BinarySecret_s* x )
{
  struct zx_ns_s* pop_seen = 0;
  struct zx_elem_s* se MAYBE_UNUSED;
#if 1 /* NORMALMODE */
  /* *** in simple_elem case should output ns prefix from ns node. */
  int len = sizeof("<wst:BinarySecret")-1 + 1 + sizeof("</wst:BinarySecret>")-1;
  if (c->inc_ns_len)
    len += zx_len_inc_ns(c, &pop_seen);
  len += zx_len_xmlns_if_not_seen(c, zx_ns_tab+zx_xmlns_ix_wst, &pop_seen);

  len += zx_attr_so_len(x->Type, sizeof("Type")-1);

#else
  /* root node has no begin tag */
  int len = 0;
#endif
  


  len += zx_len_so_common(c, &x->gg);
  zx_pop_seen(pop_seen);
  ENC_LEN_DEBUG(x, "wst:BinarySecret", len);
  return len;
}

/* FUNC(zx_LEN_WO_wst_BinarySecret) */

/* Compute length of an element (and its subelements). The XML attributes
 * and elements are processed in wire order and no assumptions
 * are made about namespace prefixes. */

/* Called by: */
int zx_LEN_WO_wst_BinarySecret(struct zx_ctx* c, struct zx_wst_BinarySecret_s* x )
{
  struct zx_ns_s* pop_seen = 0;
  struct zx_elem_s* se MAYBE_UNUSED;
#if 1 /* NORMALMODE */
  int len = 1 + sizeof("BinarySecret")-1 + 1 + 2 + sizeof("BinarySecret")-1 + 1;
  
  if (x->gg.g.ns && x->gg.g.ns->prefix_len)
    len += (x->gg.g.ns->prefix_len + 1) * 2;
  if (c->inc_ns_len)
    len += zx_len_inc_ns(c, &pop_seen);
  len += zx_len_xmlns_if_not_seen(c, x->gg.g.ns, &pop_seen);

  len += zx_attr_wo_len(x->Type, sizeof("Type")-1);

#else
  /* root node has no begin tag */
  int len = 0;
#endif
  


  len += zx_len_wo_common(c, &x->gg); 
  zx_pop_seen(pop_seen);
  ENC_LEN_DEBUG(x, "wst:BinarySecret", len);
  return len;
}

/* FUNC(zx_ENC_SO_wst_BinarySecret) */

/* Render element into string. The XML attributes and elements are
 * processed in schema order. This is what you generally want for
 * rendering new data structure to a string. The wo pointers are not used. */

/* Called by: */
char* zx_ENC_SO_wst_BinarySecret(struct zx_ctx* c, struct zx_wst_BinarySecret_s* x, char* p )
{
  struct zx_elem_s* se MAYBE_UNUSED;
  ENC_LEN_DEBUG_BASE;
#if 1 /* NORMALMODE */
  struct zx_ns_s* pop_seen = 0;
  /* *** in simple_elem case should output ns prefix from ns node. */
  ZX_OUT_TAG(p, "<wst:BinarySecret");
  if (c->inc_ns)
    p = zx_enc_inc_ns(c, p, &pop_seen);
  p = zx_enc_xmlns_if_not_seen(c, p, zx_ns_tab+zx_xmlns_ix_wst, &pop_seen);

  p = zx_attr_so_enc(p, x->Type, " Type=\"", sizeof(" Type=\"")-1);

  p = zx_enc_unknown_attrs(p, x->gg.any_attr);
#else
  /* root node has no begin tag */
#endif
  

  p = zx_enc_so_unknown_elems_and_content(c, p, &x->gg);
  
#if 1 /* NORMALMODE */
  ZX_OUT_CLOSE_TAG(p, "</wst:BinarySecret>");
  zx_pop_seen(pop_seen);
#else
  /* root node has no end tag either */
#endif
  ENC_LEN_DEBUG(x, "wst:BinarySecret", p-enc_base);
  return p;
}

/* FUNC(zx_ENC_WO_wst_BinarySecret) */

/* Render element into string. The XML attributes and elements are
 * processed in wire order by chasing wo pointers. This is what you want for
 * validating signatures on other people's XML documents. */

/* Called by: */
char* zx_ENC_WO_wst_BinarySecret(struct zx_ctx* c, struct zx_wst_BinarySecret_s* x, char* p )
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
  ZX_OUT_MEM(p, "BinarySecret", sizeof("BinarySecret")-1);
  qq = p;

  /* *** sort the namespaces */
  if (c->inc_ns)
    zx_add_inc_ns(c, &pop_seen);
  zx_add_xmlns_if_not_seen(c, x->gg.g.ns, &pop_seen);

  p = zx_enc_seen(p, pop_seen); 
  p = zx_attr_wo_enc(p, x->Type, "Type=\"", sizeof("Type=\"")-1);

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
  ENC_LEN_DEBUG(x, "wst:BinarySecret", p-enc_base);
  return p;
}

/* FUNC(zx_EASY_ENC_SO_wst_BinarySecret) */

/* Called by: */
struct zx_str* zx_EASY_ENC_SO_wst_BinarySecret(struct zx_ctx* c, struct zx_wst_BinarySecret_s* x )
{
  int len;
  char* buf;
  c->ns_tab = ZX_ALLOC(c, sizeof(zx_ns_tab));
  memcpy(c->ns_tab, zx_ns_tab, sizeof(zx_ns_tab));
  len = zx_LEN_SO_wst_BinarySecret(c, x );
  buf = ZX_ALLOC(c, len+1);
  return zx_easy_enc_common(c, zx_ENC_SO_wst_BinarySecret(c, x, buf ), buf, len);
}

/* FUNC(zx_EASY_ENC_WO_wst_BinarySecret) */

/* Called by: */
struct zx_str* zx_EASY_ENC_WO_wst_BinarySecret(struct zx_ctx* c, struct zx_wst_BinarySecret_s* x )
{
  int len;
  char* buf;
  c->ns_tab = ZX_ALLOC(c, sizeof(zx_ns_tab));
  memcpy(c->ns_tab, zx_ns_tab, sizeof(zx_ns_tab));
  len = zx_LEN_WO_wst_BinarySecret(c, x );
  buf = ZX_ALLOC(c, len+1);
  return zx_easy_enc_common(c, zx_ENC_WO_wst_BinarySecret(c, x, buf ), buf, len);
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

#define EL_NAME   wst_CancelTarget
#define EL_STRUCT zx_wst_CancelTarget_s
#define EL_NS     wst
#define EL_TAG    CancelTarget

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

/* FUNC(zx_LEN_SO_wst_CancelTarget) */

/* Compute length of an element (and its subelements). The XML attributes
 * and elements are processed in schema order. */

/* Called by: */
int zx_LEN_SO_wst_CancelTarget(struct zx_ctx* c, struct zx_wst_CancelTarget_s* x )
{
  struct zx_ns_s* pop_seen = 0;
  struct zx_elem_s* se MAYBE_UNUSED;
#if 1 /* NORMALMODE */
  /* *** in simple_elem case should output ns prefix from ns node. */
  int len = sizeof("<wst:CancelTarget")-1 + 1 + sizeof("</wst:CancelTarget>")-1;
  if (c->inc_ns_len)
    len += zx_len_inc_ns(c, &pop_seen);
  len += zx_len_xmlns_if_not_seen(c, zx_ns_tab+zx_xmlns_ix_wst, &pop_seen);


#else
  /* root node has no begin tag */
  int len = 0;
#endif
  


  len += zx_len_so_common(c, &x->gg);
  zx_pop_seen(pop_seen);
  ENC_LEN_DEBUG(x, "wst:CancelTarget", len);
  return len;
}

/* FUNC(zx_LEN_WO_wst_CancelTarget) */

/* Compute length of an element (and its subelements). The XML attributes
 * and elements are processed in wire order and no assumptions
 * are made about namespace prefixes. */

/* Called by: */
int zx_LEN_WO_wst_CancelTarget(struct zx_ctx* c, struct zx_wst_CancelTarget_s* x )
{
  struct zx_ns_s* pop_seen = 0;
  struct zx_elem_s* se MAYBE_UNUSED;
#if 1 /* NORMALMODE */
  int len = 1 + sizeof("CancelTarget")-1 + 1 + 2 + sizeof("CancelTarget")-1 + 1;
  
  if (x->gg.g.ns && x->gg.g.ns->prefix_len)
    len += (x->gg.g.ns->prefix_len + 1) * 2;
  if (c->inc_ns_len)
    len += zx_len_inc_ns(c, &pop_seen);
  len += zx_len_xmlns_if_not_seen(c, x->gg.g.ns, &pop_seen);


#else
  /* root node has no begin tag */
  int len = 0;
#endif
  


  len += zx_len_wo_common(c, &x->gg); 
  zx_pop_seen(pop_seen);
  ENC_LEN_DEBUG(x, "wst:CancelTarget", len);
  return len;
}

/* FUNC(zx_ENC_SO_wst_CancelTarget) */

/* Render element into string. The XML attributes and elements are
 * processed in schema order. This is what you generally want for
 * rendering new data structure to a string. The wo pointers are not used. */

/* Called by: */
char* zx_ENC_SO_wst_CancelTarget(struct zx_ctx* c, struct zx_wst_CancelTarget_s* x, char* p )
{
  struct zx_elem_s* se MAYBE_UNUSED;
  ENC_LEN_DEBUG_BASE;
#if 1 /* NORMALMODE */
  struct zx_ns_s* pop_seen = 0;
  /* *** in simple_elem case should output ns prefix from ns node. */
  ZX_OUT_TAG(p, "<wst:CancelTarget");
  if (c->inc_ns)
    p = zx_enc_inc_ns(c, p, &pop_seen);
  p = zx_enc_xmlns_if_not_seen(c, p, zx_ns_tab+zx_xmlns_ix_wst, &pop_seen);


  p = zx_enc_unknown_attrs(p, x->gg.any_attr);
#else
  /* root node has no begin tag */
#endif
  

  p = zx_enc_so_unknown_elems_and_content(c, p, &x->gg);
  
#if 1 /* NORMALMODE */
  ZX_OUT_CLOSE_TAG(p, "</wst:CancelTarget>");
  zx_pop_seen(pop_seen);
#else
  /* root node has no end tag either */
#endif
  ENC_LEN_DEBUG(x, "wst:CancelTarget", p-enc_base);
  return p;
}

/* FUNC(zx_ENC_WO_wst_CancelTarget) */

/* Render element into string. The XML attributes and elements are
 * processed in wire order by chasing wo pointers. This is what you want for
 * validating signatures on other people's XML documents. */

/* Called by: */
char* zx_ENC_WO_wst_CancelTarget(struct zx_ctx* c, struct zx_wst_CancelTarget_s* x, char* p )
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
  ZX_OUT_MEM(p, "CancelTarget", sizeof("CancelTarget")-1);
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
  ENC_LEN_DEBUG(x, "wst:CancelTarget", p-enc_base);
  return p;
}

/* FUNC(zx_EASY_ENC_SO_wst_CancelTarget) */

/* Called by: */
struct zx_str* zx_EASY_ENC_SO_wst_CancelTarget(struct zx_ctx* c, struct zx_wst_CancelTarget_s* x )
{
  int len;
  char* buf;
  c->ns_tab = ZX_ALLOC(c, sizeof(zx_ns_tab));
  memcpy(c->ns_tab, zx_ns_tab, sizeof(zx_ns_tab));
  len = zx_LEN_SO_wst_CancelTarget(c, x );
  buf = ZX_ALLOC(c, len+1);
  return zx_easy_enc_common(c, zx_ENC_SO_wst_CancelTarget(c, x, buf ), buf, len);
}

/* FUNC(zx_EASY_ENC_WO_wst_CancelTarget) */

/* Called by: */
struct zx_str* zx_EASY_ENC_WO_wst_CancelTarget(struct zx_ctx* c, struct zx_wst_CancelTarget_s* x )
{
  int len;
  char* buf;
  c->ns_tab = ZX_ALLOC(c, sizeof(zx_ns_tab));
  memcpy(c->ns_tab, zx_ns_tab, sizeof(zx_ns_tab));
  len = zx_LEN_WO_wst_CancelTarget(c, x );
  buf = ZX_ALLOC(c, len+1);
  return zx_easy_enc_common(c, zx_ENC_WO_wst_CancelTarget(c, x, buf ), buf, len);
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

#define EL_NAME   wst_Claims
#define EL_STRUCT zx_wst_Claims_s
#define EL_NS     wst
#define EL_TAG    Claims

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

/* FUNC(zx_LEN_SO_wst_Claims) */

/* Compute length of an element (and its subelements). The XML attributes
 * and elements are processed in schema order. */

/* Called by: */
int zx_LEN_SO_wst_Claims(struct zx_ctx* c, struct zx_wst_Claims_s* x )
{
  struct zx_ns_s* pop_seen = 0;
  struct zx_elem_s* se MAYBE_UNUSED;
#if 1 /* NORMALMODE */
  /* *** in simple_elem case should output ns prefix from ns node. */
  int len = sizeof("<wst:Claims")-1 + 1 + sizeof("</wst:Claims>")-1;
  if (c->inc_ns_len)
    len += zx_len_inc_ns(c, &pop_seen);
  len += zx_len_xmlns_if_not_seen(c, zx_ns_tab+zx_xmlns_ix_wst, &pop_seen);

  len += zx_attr_so_len(x->Dialect, sizeof("Dialect")-1);

#else
  /* root node has no begin tag */
  int len = 0;
#endif
  


  len += zx_len_so_common(c, &x->gg);
  zx_pop_seen(pop_seen);
  ENC_LEN_DEBUG(x, "wst:Claims", len);
  return len;
}

/* FUNC(zx_LEN_WO_wst_Claims) */

/* Compute length of an element (and its subelements). The XML attributes
 * and elements are processed in wire order and no assumptions
 * are made about namespace prefixes. */

/* Called by: */
int zx_LEN_WO_wst_Claims(struct zx_ctx* c, struct zx_wst_Claims_s* x )
{
  struct zx_ns_s* pop_seen = 0;
  struct zx_elem_s* se MAYBE_UNUSED;
#if 1 /* NORMALMODE */
  int len = 1 + sizeof("Claims")-1 + 1 + 2 + sizeof("Claims")-1 + 1;
  
  if (x->gg.g.ns && x->gg.g.ns->prefix_len)
    len += (x->gg.g.ns->prefix_len + 1) * 2;
  if (c->inc_ns_len)
    len += zx_len_inc_ns(c, &pop_seen);
  len += zx_len_xmlns_if_not_seen(c, x->gg.g.ns, &pop_seen);

  len += zx_attr_wo_len(x->Dialect, sizeof("Dialect")-1);

#else
  /* root node has no begin tag */
  int len = 0;
#endif
  


  len += zx_len_wo_common(c, &x->gg); 
  zx_pop_seen(pop_seen);
  ENC_LEN_DEBUG(x, "wst:Claims", len);
  return len;
}

/* FUNC(zx_ENC_SO_wst_Claims) */

/* Render element into string. The XML attributes and elements are
 * processed in schema order. This is what you generally want for
 * rendering new data structure to a string. The wo pointers are not used. */

/* Called by: */
char* zx_ENC_SO_wst_Claims(struct zx_ctx* c, struct zx_wst_Claims_s* x, char* p )
{
  struct zx_elem_s* se MAYBE_UNUSED;
  ENC_LEN_DEBUG_BASE;
#if 1 /* NORMALMODE */
  struct zx_ns_s* pop_seen = 0;
  /* *** in simple_elem case should output ns prefix from ns node. */
  ZX_OUT_TAG(p, "<wst:Claims");
  if (c->inc_ns)
    p = zx_enc_inc_ns(c, p, &pop_seen);
  p = zx_enc_xmlns_if_not_seen(c, p, zx_ns_tab+zx_xmlns_ix_wst, &pop_seen);

  p = zx_attr_so_enc(p, x->Dialect, " Dialect=\"", sizeof(" Dialect=\"")-1);

  p = zx_enc_unknown_attrs(p, x->gg.any_attr);
#else
  /* root node has no begin tag */
#endif
  

  p = zx_enc_so_unknown_elems_and_content(c, p, &x->gg);
  
#if 1 /* NORMALMODE */
  ZX_OUT_CLOSE_TAG(p, "</wst:Claims>");
  zx_pop_seen(pop_seen);
#else
  /* root node has no end tag either */
#endif
  ENC_LEN_DEBUG(x, "wst:Claims", p-enc_base);
  return p;
}

/* FUNC(zx_ENC_WO_wst_Claims) */

/* Render element into string. The XML attributes and elements are
 * processed in wire order by chasing wo pointers. This is what you want for
 * validating signatures on other people's XML documents. */

/* Called by: */
char* zx_ENC_WO_wst_Claims(struct zx_ctx* c, struct zx_wst_Claims_s* x, char* p )
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
  ZX_OUT_MEM(p, "Claims", sizeof("Claims")-1);
  qq = p;

  /* *** sort the namespaces */
  if (c->inc_ns)
    zx_add_inc_ns(c, &pop_seen);
  zx_add_xmlns_if_not_seen(c, x->gg.g.ns, &pop_seen);

  p = zx_enc_seen(p, pop_seen); 
  p = zx_attr_wo_enc(p, x->Dialect, "Dialect=\"", sizeof("Dialect=\"")-1);

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
  ENC_LEN_DEBUG(x, "wst:Claims", p-enc_base);
  return p;
}

/* FUNC(zx_EASY_ENC_SO_wst_Claims) */

/* Called by: */
struct zx_str* zx_EASY_ENC_SO_wst_Claims(struct zx_ctx* c, struct zx_wst_Claims_s* x )
{
  int len;
  char* buf;
  c->ns_tab = ZX_ALLOC(c, sizeof(zx_ns_tab));
  memcpy(c->ns_tab, zx_ns_tab, sizeof(zx_ns_tab));
  len = zx_LEN_SO_wst_Claims(c, x );
  buf = ZX_ALLOC(c, len+1);
  return zx_easy_enc_common(c, zx_ENC_SO_wst_Claims(c, x, buf ), buf, len);
}

/* FUNC(zx_EASY_ENC_WO_wst_Claims) */

/* Called by: */
struct zx_str* zx_EASY_ENC_WO_wst_Claims(struct zx_ctx* c, struct zx_wst_Claims_s* x )
{
  int len;
  char* buf;
  c->ns_tab = ZX_ALLOC(c, sizeof(zx_ns_tab));
  memcpy(c->ns_tab, zx_ns_tab, sizeof(zx_ns_tab));
  len = zx_LEN_WO_wst_Claims(c, x );
  buf = ZX_ALLOC(c, len+1);
  return zx_easy_enc_common(c, zx_ENC_WO_wst_Claims(c, x, buf ), buf, len);
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

#define EL_NAME   wst_DelegateTo
#define EL_STRUCT zx_wst_DelegateTo_s
#define EL_NS     wst
#define EL_TAG    DelegateTo

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

/* FUNC(zx_LEN_SO_wst_DelegateTo) */

/* Compute length of an element (and its subelements). The XML attributes
 * and elements are processed in schema order. */

/* Called by: */
int zx_LEN_SO_wst_DelegateTo(struct zx_ctx* c, struct zx_wst_DelegateTo_s* x )
{
  struct zx_ns_s* pop_seen = 0;
  struct zx_elem_s* se MAYBE_UNUSED;
#if 1 /* NORMALMODE */
  /* *** in simple_elem case should output ns prefix from ns node. */
  int len = sizeof("<wst:DelegateTo")-1 + 1 + sizeof("</wst:DelegateTo>")-1;
  if (c->inc_ns_len)
    len += zx_len_inc_ns(c, &pop_seen);
  len += zx_len_xmlns_if_not_seen(c, zx_ns_tab+zx_xmlns_ix_wst, &pop_seen);


#else
  /* root node has no begin tag */
  int len = 0;
#endif
  


  len += zx_len_so_common(c, &x->gg);
  zx_pop_seen(pop_seen);
  ENC_LEN_DEBUG(x, "wst:DelegateTo", len);
  return len;
}

/* FUNC(zx_LEN_WO_wst_DelegateTo) */

/* Compute length of an element (and its subelements). The XML attributes
 * and elements are processed in wire order and no assumptions
 * are made about namespace prefixes. */

/* Called by: */
int zx_LEN_WO_wst_DelegateTo(struct zx_ctx* c, struct zx_wst_DelegateTo_s* x )
{
  struct zx_ns_s* pop_seen = 0;
  struct zx_elem_s* se MAYBE_UNUSED;
#if 1 /* NORMALMODE */
  int len = 1 + sizeof("DelegateTo")-1 + 1 + 2 + sizeof("DelegateTo")-1 + 1;
  
  if (x->gg.g.ns && x->gg.g.ns->prefix_len)
    len += (x->gg.g.ns->prefix_len + 1) * 2;
  if (c->inc_ns_len)
    len += zx_len_inc_ns(c, &pop_seen);
  len += zx_len_xmlns_if_not_seen(c, x->gg.g.ns, &pop_seen);


#else
  /* root node has no begin tag */
  int len = 0;
#endif
  


  len += zx_len_wo_common(c, &x->gg); 
  zx_pop_seen(pop_seen);
  ENC_LEN_DEBUG(x, "wst:DelegateTo", len);
  return len;
}

/* FUNC(zx_ENC_SO_wst_DelegateTo) */

/* Render element into string. The XML attributes and elements are
 * processed in schema order. This is what you generally want for
 * rendering new data structure to a string. The wo pointers are not used. */

/* Called by: */
char* zx_ENC_SO_wst_DelegateTo(struct zx_ctx* c, struct zx_wst_DelegateTo_s* x, char* p )
{
  struct zx_elem_s* se MAYBE_UNUSED;
  ENC_LEN_DEBUG_BASE;
#if 1 /* NORMALMODE */
  struct zx_ns_s* pop_seen = 0;
  /* *** in simple_elem case should output ns prefix from ns node. */
  ZX_OUT_TAG(p, "<wst:DelegateTo");
  if (c->inc_ns)
    p = zx_enc_inc_ns(c, p, &pop_seen);
  p = zx_enc_xmlns_if_not_seen(c, p, zx_ns_tab+zx_xmlns_ix_wst, &pop_seen);


  p = zx_enc_unknown_attrs(p, x->gg.any_attr);
#else
  /* root node has no begin tag */
#endif
  

  p = zx_enc_so_unknown_elems_and_content(c, p, &x->gg);
  
#if 1 /* NORMALMODE */
  ZX_OUT_CLOSE_TAG(p, "</wst:DelegateTo>");
  zx_pop_seen(pop_seen);
#else
  /* root node has no end tag either */
#endif
  ENC_LEN_DEBUG(x, "wst:DelegateTo", p-enc_base);
  return p;
}

/* FUNC(zx_ENC_WO_wst_DelegateTo) */

/* Render element into string. The XML attributes and elements are
 * processed in wire order by chasing wo pointers. This is what you want for
 * validating signatures on other people's XML documents. */

/* Called by: */
char* zx_ENC_WO_wst_DelegateTo(struct zx_ctx* c, struct zx_wst_DelegateTo_s* x, char* p )
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
  ZX_OUT_MEM(p, "DelegateTo", sizeof("DelegateTo")-1);
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
  ENC_LEN_DEBUG(x, "wst:DelegateTo", p-enc_base);
  return p;
}

/* FUNC(zx_EASY_ENC_SO_wst_DelegateTo) */

/* Called by: */
struct zx_str* zx_EASY_ENC_SO_wst_DelegateTo(struct zx_ctx* c, struct zx_wst_DelegateTo_s* x )
{
  int len;
  char* buf;
  c->ns_tab = ZX_ALLOC(c, sizeof(zx_ns_tab));
  memcpy(c->ns_tab, zx_ns_tab, sizeof(zx_ns_tab));
  len = zx_LEN_SO_wst_DelegateTo(c, x );
  buf = ZX_ALLOC(c, len+1);
  return zx_easy_enc_common(c, zx_ENC_SO_wst_DelegateTo(c, x, buf ), buf, len);
}

/* FUNC(zx_EASY_ENC_WO_wst_DelegateTo) */

/* Called by: */
struct zx_str* zx_EASY_ENC_WO_wst_DelegateTo(struct zx_ctx* c, struct zx_wst_DelegateTo_s* x )
{
  int len;
  char* buf;
  c->ns_tab = ZX_ALLOC(c, sizeof(zx_ns_tab));
  memcpy(c->ns_tab, zx_ns_tab, sizeof(zx_ns_tab));
  len = zx_LEN_WO_wst_DelegateTo(c, x );
  buf = ZX_ALLOC(c, len+1);
  return zx_easy_enc_common(c, zx_ENC_WO_wst_DelegateTo(c, x, buf ), buf, len);
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

#define EL_NAME   wst_Encryption
#define EL_STRUCT zx_wst_Encryption_s
#define EL_NS     wst
#define EL_TAG    Encryption

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

/* FUNC(zx_LEN_SO_wst_Encryption) */

/* Compute length of an element (and its subelements). The XML attributes
 * and elements are processed in schema order. */

/* Called by: */
int zx_LEN_SO_wst_Encryption(struct zx_ctx* c, struct zx_wst_Encryption_s* x )
{
  struct zx_ns_s* pop_seen = 0;
  struct zx_elem_s* se MAYBE_UNUSED;
#if 1 /* NORMALMODE */
  /* *** in simple_elem case should output ns prefix from ns node. */
  int len = sizeof("<wst:Encryption")-1 + 1 + sizeof("</wst:Encryption>")-1;
  if (c->inc_ns_len)
    len += zx_len_inc_ns(c, &pop_seen);
  len += zx_len_xmlns_if_not_seen(c, zx_ns_tab+zx_xmlns_ix_wst, &pop_seen);


#else
  /* root node has no begin tag */
  int len = 0;
#endif
  


  len += zx_len_so_common(c, &x->gg);
  zx_pop_seen(pop_seen);
  ENC_LEN_DEBUG(x, "wst:Encryption", len);
  return len;
}

/* FUNC(zx_LEN_WO_wst_Encryption) */

/* Compute length of an element (and its subelements). The XML attributes
 * and elements are processed in wire order and no assumptions
 * are made about namespace prefixes. */

/* Called by: */
int zx_LEN_WO_wst_Encryption(struct zx_ctx* c, struct zx_wst_Encryption_s* x )
{
  struct zx_ns_s* pop_seen = 0;
  struct zx_elem_s* se MAYBE_UNUSED;
#if 1 /* NORMALMODE */
  int len = 1 + sizeof("Encryption")-1 + 1 + 2 + sizeof("Encryption")-1 + 1;
  
  if (x->gg.g.ns && x->gg.g.ns->prefix_len)
    len += (x->gg.g.ns->prefix_len + 1) * 2;
  if (c->inc_ns_len)
    len += zx_len_inc_ns(c, &pop_seen);
  len += zx_len_xmlns_if_not_seen(c, x->gg.g.ns, &pop_seen);


#else
  /* root node has no begin tag */
  int len = 0;
#endif
  


  len += zx_len_wo_common(c, &x->gg); 
  zx_pop_seen(pop_seen);
  ENC_LEN_DEBUG(x, "wst:Encryption", len);
  return len;
}

/* FUNC(zx_ENC_SO_wst_Encryption) */

/* Render element into string. The XML attributes and elements are
 * processed in schema order. This is what you generally want for
 * rendering new data structure to a string. The wo pointers are not used. */

/* Called by: */
char* zx_ENC_SO_wst_Encryption(struct zx_ctx* c, struct zx_wst_Encryption_s* x, char* p )
{
  struct zx_elem_s* se MAYBE_UNUSED;
  ENC_LEN_DEBUG_BASE;
#if 1 /* NORMALMODE */
  struct zx_ns_s* pop_seen = 0;
  /* *** in simple_elem case should output ns prefix from ns node. */
  ZX_OUT_TAG(p, "<wst:Encryption");
  if (c->inc_ns)
    p = zx_enc_inc_ns(c, p, &pop_seen);
  p = zx_enc_xmlns_if_not_seen(c, p, zx_ns_tab+zx_xmlns_ix_wst, &pop_seen);


  p = zx_enc_unknown_attrs(p, x->gg.any_attr);
#else
  /* root node has no begin tag */
#endif
  

  p = zx_enc_so_unknown_elems_and_content(c, p, &x->gg);
  
#if 1 /* NORMALMODE */
  ZX_OUT_CLOSE_TAG(p, "</wst:Encryption>");
  zx_pop_seen(pop_seen);
#else
  /* root node has no end tag either */
#endif
  ENC_LEN_DEBUG(x, "wst:Encryption", p-enc_base);
  return p;
}

/* FUNC(zx_ENC_WO_wst_Encryption) */

/* Render element into string. The XML attributes and elements are
 * processed in wire order by chasing wo pointers. This is what you want for
 * validating signatures on other people's XML documents. */

/* Called by: */
char* zx_ENC_WO_wst_Encryption(struct zx_ctx* c, struct zx_wst_Encryption_s* x, char* p )
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
  ZX_OUT_MEM(p, "Encryption", sizeof("Encryption")-1);
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
  ENC_LEN_DEBUG(x, "wst:Encryption", p-enc_base);
  return p;
}

/* FUNC(zx_EASY_ENC_SO_wst_Encryption) */

/* Called by: */
struct zx_str* zx_EASY_ENC_SO_wst_Encryption(struct zx_ctx* c, struct zx_wst_Encryption_s* x )
{
  int len;
  char* buf;
  c->ns_tab = ZX_ALLOC(c, sizeof(zx_ns_tab));
  memcpy(c->ns_tab, zx_ns_tab, sizeof(zx_ns_tab));
  len = zx_LEN_SO_wst_Encryption(c, x );
  buf = ZX_ALLOC(c, len+1);
  return zx_easy_enc_common(c, zx_ENC_SO_wst_Encryption(c, x, buf ), buf, len);
}

/* FUNC(zx_EASY_ENC_WO_wst_Encryption) */

/* Called by: */
struct zx_str* zx_EASY_ENC_WO_wst_Encryption(struct zx_ctx* c, struct zx_wst_Encryption_s* x )
{
  int len;
  char* buf;
  c->ns_tab = ZX_ALLOC(c, sizeof(zx_ns_tab));
  memcpy(c->ns_tab, zx_ns_tab, sizeof(zx_ns_tab));
  len = zx_LEN_WO_wst_Encryption(c, x );
  buf = ZX_ALLOC(c, len+1);
  return zx_easy_enc_common(c, zx_ENC_WO_wst_Encryption(c, x, buf ), buf, len);
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

#define EL_NAME   wst_Entropy
#define EL_STRUCT zx_wst_Entropy_s
#define EL_NS     wst
#define EL_TAG    Entropy

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

/* FUNC(zx_LEN_SO_wst_Entropy) */

/* Compute length of an element (and its subelements). The XML attributes
 * and elements are processed in schema order. */

/* Called by: */
int zx_LEN_SO_wst_Entropy(struct zx_ctx* c, struct zx_wst_Entropy_s* x )
{
  struct zx_ns_s* pop_seen = 0;
  struct zx_elem_s* se MAYBE_UNUSED;
#if 1 /* NORMALMODE */
  /* *** in simple_elem case should output ns prefix from ns node. */
  int len = sizeof("<wst:Entropy")-1 + 1 + sizeof("</wst:Entropy>")-1;
  if (c->inc_ns_len)
    len += zx_len_inc_ns(c, &pop_seen);
  len += zx_len_xmlns_if_not_seen(c, zx_ns_tab+zx_xmlns_ix_wst, &pop_seen);


#else
  /* root node has no begin tag */
  int len = 0;
#endif
  


  len += zx_len_so_common(c, &x->gg);
  zx_pop_seen(pop_seen);
  ENC_LEN_DEBUG(x, "wst:Entropy", len);
  return len;
}

/* FUNC(zx_LEN_WO_wst_Entropy) */

/* Compute length of an element (and its subelements). The XML attributes
 * and elements are processed in wire order and no assumptions
 * are made about namespace prefixes. */

/* Called by: */
int zx_LEN_WO_wst_Entropy(struct zx_ctx* c, struct zx_wst_Entropy_s* x )
{
  struct zx_ns_s* pop_seen = 0;
  struct zx_elem_s* se MAYBE_UNUSED;
#if 1 /* NORMALMODE */
  int len = 1 + sizeof("Entropy")-1 + 1 + 2 + sizeof("Entropy")-1 + 1;
  
  if (x->gg.g.ns && x->gg.g.ns->prefix_len)
    len += (x->gg.g.ns->prefix_len + 1) * 2;
  if (c->inc_ns_len)
    len += zx_len_inc_ns(c, &pop_seen);
  len += zx_len_xmlns_if_not_seen(c, x->gg.g.ns, &pop_seen);


#else
  /* root node has no begin tag */
  int len = 0;
#endif
  


  len += zx_len_wo_common(c, &x->gg); 
  zx_pop_seen(pop_seen);
  ENC_LEN_DEBUG(x, "wst:Entropy", len);
  return len;
}

/* FUNC(zx_ENC_SO_wst_Entropy) */

/* Render element into string. The XML attributes and elements are
 * processed in schema order. This is what you generally want for
 * rendering new data structure to a string. The wo pointers are not used. */

/* Called by: */
char* zx_ENC_SO_wst_Entropy(struct zx_ctx* c, struct zx_wst_Entropy_s* x, char* p )
{
  struct zx_elem_s* se MAYBE_UNUSED;
  ENC_LEN_DEBUG_BASE;
#if 1 /* NORMALMODE */
  struct zx_ns_s* pop_seen = 0;
  /* *** in simple_elem case should output ns prefix from ns node. */
  ZX_OUT_TAG(p, "<wst:Entropy");
  if (c->inc_ns)
    p = zx_enc_inc_ns(c, p, &pop_seen);
  p = zx_enc_xmlns_if_not_seen(c, p, zx_ns_tab+zx_xmlns_ix_wst, &pop_seen);


  p = zx_enc_unknown_attrs(p, x->gg.any_attr);
#else
  /* root node has no begin tag */
#endif
  

  p = zx_enc_so_unknown_elems_and_content(c, p, &x->gg);
  
#if 1 /* NORMALMODE */
  ZX_OUT_CLOSE_TAG(p, "</wst:Entropy>");
  zx_pop_seen(pop_seen);
#else
  /* root node has no end tag either */
#endif
  ENC_LEN_DEBUG(x, "wst:Entropy", p-enc_base);
  return p;
}

/* FUNC(zx_ENC_WO_wst_Entropy) */

/* Render element into string. The XML attributes and elements are
 * processed in wire order by chasing wo pointers. This is what you want for
 * validating signatures on other people's XML documents. */

/* Called by: */
char* zx_ENC_WO_wst_Entropy(struct zx_ctx* c, struct zx_wst_Entropy_s* x, char* p )
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
  ZX_OUT_MEM(p, "Entropy", sizeof("Entropy")-1);
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
  ENC_LEN_DEBUG(x, "wst:Entropy", p-enc_base);
  return p;
}

/* FUNC(zx_EASY_ENC_SO_wst_Entropy) */

/* Called by: */
struct zx_str* zx_EASY_ENC_SO_wst_Entropy(struct zx_ctx* c, struct zx_wst_Entropy_s* x )
{
  int len;
  char* buf;
  c->ns_tab = ZX_ALLOC(c, sizeof(zx_ns_tab));
  memcpy(c->ns_tab, zx_ns_tab, sizeof(zx_ns_tab));
  len = zx_LEN_SO_wst_Entropy(c, x );
  buf = ZX_ALLOC(c, len+1);
  return zx_easy_enc_common(c, zx_ENC_SO_wst_Entropy(c, x, buf ), buf, len);
}

/* FUNC(zx_EASY_ENC_WO_wst_Entropy) */

/* Called by: */
struct zx_str* zx_EASY_ENC_WO_wst_Entropy(struct zx_ctx* c, struct zx_wst_Entropy_s* x )
{
  int len;
  char* buf;
  c->ns_tab = ZX_ALLOC(c, sizeof(zx_ns_tab));
  memcpy(c->ns_tab, zx_ns_tab, sizeof(zx_ns_tab));
  len = zx_LEN_WO_wst_Entropy(c, x );
  buf = ZX_ALLOC(c, len+1);
  return zx_easy_enc_common(c, zx_ENC_WO_wst_Entropy(c, x, buf ), buf, len);
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

#define EL_NAME   wst_IssuedTokens
#define EL_STRUCT zx_wst_IssuedTokens_s
#define EL_NS     wst
#define EL_TAG    IssuedTokens

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

/* FUNC(zx_LEN_SO_wst_IssuedTokens) */

/* Compute length of an element (and its subelements). The XML attributes
 * and elements are processed in schema order. */

/* Called by: */
int zx_LEN_SO_wst_IssuedTokens(struct zx_ctx* c, struct zx_wst_IssuedTokens_s* x )
{
  struct zx_ns_s* pop_seen = 0;
  struct zx_elem_s* se MAYBE_UNUSED;
#if 1 /* NORMALMODE */
  /* *** in simple_elem case should output ns prefix from ns node. */
  int len = sizeof("<wst:IssuedTokens")-1 + 1 + sizeof("</wst:IssuedTokens>")-1;
  if (c->inc_ns_len)
    len += zx_len_inc_ns(c, &pop_seen);
  len += zx_len_xmlns_if_not_seen(c, zx_ns_tab+zx_xmlns_ix_wst, &pop_seen);


#else
  /* root node has no begin tag */
  int len = 0;
#endif
  
  {
      struct zx_wst_RequestSecurityTokenResponse_s* e;
      for (e = x->RequestSecurityTokenResponse; e; e = (struct zx_wst_RequestSecurityTokenResponse_s*)e->gg.g.n)
	  len += zx_LEN_SO_wst_RequestSecurityTokenResponse(c, e);
  }


  len += zx_len_so_common(c, &x->gg);
  zx_pop_seen(pop_seen);
  ENC_LEN_DEBUG(x, "wst:IssuedTokens", len);
  return len;
}

/* FUNC(zx_LEN_WO_wst_IssuedTokens) */

/* Compute length of an element (and its subelements). The XML attributes
 * and elements are processed in wire order and no assumptions
 * are made about namespace prefixes. */

/* Called by: */
int zx_LEN_WO_wst_IssuedTokens(struct zx_ctx* c, struct zx_wst_IssuedTokens_s* x )
{
  struct zx_ns_s* pop_seen = 0;
  struct zx_elem_s* se MAYBE_UNUSED;
#if 1 /* NORMALMODE */
  int len = 1 + sizeof("IssuedTokens")-1 + 1 + 2 + sizeof("IssuedTokens")-1 + 1;
  
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
      struct zx_wst_RequestSecurityTokenResponse_s* e;
      for (e = x->RequestSecurityTokenResponse; e; e = (struct zx_wst_RequestSecurityTokenResponse_s*)e->gg.g.n)
	  len += zx_LEN_WO_wst_RequestSecurityTokenResponse(c, e);
  }


  len += zx_len_wo_common(c, &x->gg); 
  zx_pop_seen(pop_seen);
  ENC_LEN_DEBUG(x, "wst:IssuedTokens", len);
  return len;
}

/* FUNC(zx_ENC_SO_wst_IssuedTokens) */

/* Render element into string. The XML attributes and elements are
 * processed in schema order. This is what you generally want for
 * rendering new data structure to a string. The wo pointers are not used. */

/* Called by: */
char* zx_ENC_SO_wst_IssuedTokens(struct zx_ctx* c, struct zx_wst_IssuedTokens_s* x, char* p )
{
  struct zx_elem_s* se MAYBE_UNUSED;
  ENC_LEN_DEBUG_BASE;
#if 1 /* NORMALMODE */
  struct zx_ns_s* pop_seen = 0;
  /* *** in simple_elem case should output ns prefix from ns node. */
  ZX_OUT_TAG(p, "<wst:IssuedTokens");
  if (c->inc_ns)
    p = zx_enc_inc_ns(c, p, &pop_seen);
  p = zx_enc_xmlns_if_not_seen(c, p, zx_ns_tab+zx_xmlns_ix_wst, &pop_seen);


  p = zx_enc_unknown_attrs(p, x->gg.any_attr);
#else
  /* root node has no begin tag */
#endif
  
  {
      struct zx_wst_RequestSecurityTokenResponse_s* e;
      for (e = x->RequestSecurityTokenResponse; e; e = (struct zx_wst_RequestSecurityTokenResponse_s*)e->gg.g.n)
	  p = zx_ENC_SO_wst_RequestSecurityTokenResponse(c, e, p);
  }

  p = zx_enc_so_unknown_elems_and_content(c, p, &x->gg);
  
#if 1 /* NORMALMODE */
  ZX_OUT_CLOSE_TAG(p, "</wst:IssuedTokens>");
  zx_pop_seen(pop_seen);
#else
  /* root node has no end tag either */
#endif
  ENC_LEN_DEBUG(x, "wst:IssuedTokens", p-enc_base);
  return p;
}

/* FUNC(zx_ENC_WO_wst_IssuedTokens) */

/* Render element into string. The XML attributes and elements are
 * processed in wire order by chasing wo pointers. This is what you want for
 * validating signatures on other people's XML documents. */

/* Called by: */
char* zx_ENC_WO_wst_IssuedTokens(struct zx_ctx* c, struct zx_wst_IssuedTokens_s* x, char* p )
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
  ZX_OUT_MEM(p, "IssuedTokens", sizeof("IssuedTokens")-1);
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
  ENC_LEN_DEBUG(x, "wst:IssuedTokens", p-enc_base);
  return p;
}

/* FUNC(zx_EASY_ENC_SO_wst_IssuedTokens) */

/* Called by: */
struct zx_str* zx_EASY_ENC_SO_wst_IssuedTokens(struct zx_ctx* c, struct zx_wst_IssuedTokens_s* x )
{
  int len;
  char* buf;
  c->ns_tab = ZX_ALLOC(c, sizeof(zx_ns_tab));
  memcpy(c->ns_tab, zx_ns_tab, sizeof(zx_ns_tab));
  len = zx_LEN_SO_wst_IssuedTokens(c, x );
  buf = ZX_ALLOC(c, len+1);
  return zx_easy_enc_common(c, zx_ENC_SO_wst_IssuedTokens(c, x, buf ), buf, len);
}

/* FUNC(zx_EASY_ENC_WO_wst_IssuedTokens) */

/* Called by: */
struct zx_str* zx_EASY_ENC_WO_wst_IssuedTokens(struct zx_ctx* c, struct zx_wst_IssuedTokens_s* x )
{
  int len;
  char* buf;
  c->ns_tab = ZX_ALLOC(c, sizeof(zx_ns_tab));
  memcpy(c->ns_tab, zx_ns_tab, sizeof(zx_ns_tab));
  len = zx_LEN_WO_wst_IssuedTokens(c, x );
  buf = ZX_ALLOC(c, len+1);
  return zx_easy_enc_common(c, zx_ENC_WO_wst_IssuedTokens(c, x, buf ), buf, len);
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

#define EL_NAME   wst_Issuer
#define EL_STRUCT zx_wst_Issuer_s
#define EL_NS     wst
#define EL_TAG    Issuer

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

/* FUNC(zx_LEN_SO_wst_Issuer) */

/* Compute length of an element (and its subelements). The XML attributes
 * and elements are processed in schema order. */

/* Called by: */
int zx_LEN_SO_wst_Issuer(struct zx_ctx* c, struct zx_wst_Issuer_s* x )
{
  struct zx_ns_s* pop_seen = 0;
  struct zx_elem_s* se MAYBE_UNUSED;
#if 1 /* NORMALMODE */
  /* *** in simple_elem case should output ns prefix from ns node. */
  int len = sizeof("<wst:Issuer")-1 + 1 + sizeof("</wst:Issuer>")-1;
  if (c->inc_ns_len)
    len += zx_len_inc_ns(c, &pop_seen);
  if (x->actor || x->mustUnderstand)
    len += zx_len_xmlns_if_not_seen(c, zx_ns_tab+zx_xmlns_ix_e, &pop_seen);
  len += zx_len_xmlns_if_not_seen(c, zx_ns_tab+zx_xmlns_ix_wst, &pop_seen);
  if (x->Id)
    len += zx_len_xmlns_if_not_seen(c, zx_ns_tab+zx_xmlns_ix_wsu, &pop_seen);

  len += zx_attr_so_len(x->ID, sizeof("ID")-1);
  len += zx_attr_so_len(x->id, sizeof("id")-1);
  len += zx_attr_so_len(x->notOnOrAfter, sizeof("notOnOrAfter")-1);
  len += zx_attr_so_len(x->Id, sizeof("wsu:Id")-1);
  len += zx_attr_so_len(x->actor, sizeof("e:actor")-1);
  len += zx_attr_so_len(x->mustUnderstand, sizeof("e:mustUnderstand")-1);

#else
  /* root node has no begin tag */
  int len = 0;
#endif
  
  {
      struct zx_a_Address_s* e;
      for (e = x->Address; e; e = (struct zx_a_Address_s*)e->gg.g.n)
	  len += zx_LEN_SO_a_Address(c, e);
  }
  {
      struct zx_a_ReferenceParameters_s* e;
      for (e = x->ReferenceParameters; e; e = (struct zx_a_ReferenceParameters_s*)e->gg.g.n)
	  len += zx_LEN_SO_a_ReferenceParameters(c, e);
  }
  {
      struct zx_a_Metadata_s* e;
      for (e = x->Metadata; e; e = (struct zx_a_Metadata_s*)e->gg.g.n)
	  len += zx_LEN_SO_a_Metadata(c, e);
  }


  len += zx_len_so_common(c, &x->gg);
  zx_pop_seen(pop_seen);
  ENC_LEN_DEBUG(x, "wst:Issuer", len);
  return len;
}

/* FUNC(zx_LEN_WO_wst_Issuer) */

/* Compute length of an element (and its subelements). The XML attributes
 * and elements are processed in wire order and no assumptions
 * are made about namespace prefixes. */

/* Called by: */
int zx_LEN_WO_wst_Issuer(struct zx_ctx* c, struct zx_wst_Issuer_s* x )
{
  struct zx_ns_s* pop_seen = 0;
  struct zx_elem_s* se MAYBE_UNUSED;
#if 1 /* NORMALMODE */
  int len = 1 + sizeof("Issuer")-1 + 1 + 2 + sizeof("Issuer")-1 + 1;
  
  if (x->gg.g.ns && x->gg.g.ns->prefix_len)
    len += (x->gg.g.ns->prefix_len + 1) * 2;
  if (c->inc_ns_len)
    len += zx_len_inc_ns(c, &pop_seen);
  if (x->actor)
    len += zx_len_xmlns_if_not_seen(c, x->actor->g.ns, &pop_seen);
  if (x->mustUnderstand)
    len += zx_len_xmlns_if_not_seen(c, x->mustUnderstand->g.ns, &pop_seen);
  len += zx_len_xmlns_if_not_seen(c, x->gg.g.ns, &pop_seen);
  if (x->Id)
    len += zx_len_xmlns_if_not_seen(c, x->Id->g.ns, &pop_seen);

  len += zx_attr_wo_len(x->ID, sizeof("ID")-1);
  len += zx_attr_wo_len(x->id, sizeof("id")-1);
  len += zx_attr_wo_len(x->notOnOrAfter, sizeof("notOnOrAfter")-1);
  len += zx_attr_wo_len(x->Id, sizeof("Id")-1);
  len += zx_attr_wo_len(x->actor, sizeof("actor")-1);
  len += zx_attr_wo_len(x->mustUnderstand, sizeof("mustUnderstand")-1);

#else
  /* root node has no begin tag */
  int len = 0;
#endif
  
  {
      struct zx_a_Address_s* e;
      for (e = x->Address; e; e = (struct zx_a_Address_s*)e->gg.g.n)
	  len += zx_LEN_WO_a_Address(c, e);
  }
  {
      struct zx_a_ReferenceParameters_s* e;
      for (e = x->ReferenceParameters; e; e = (struct zx_a_ReferenceParameters_s*)e->gg.g.n)
	  len += zx_LEN_WO_a_ReferenceParameters(c, e);
  }
  {
      struct zx_a_Metadata_s* e;
      for (e = x->Metadata; e; e = (struct zx_a_Metadata_s*)e->gg.g.n)
	  len += zx_LEN_WO_a_Metadata(c, e);
  }


  len += zx_len_wo_common(c, &x->gg); 
  zx_pop_seen(pop_seen);
  ENC_LEN_DEBUG(x, "wst:Issuer", len);
  return len;
}

/* FUNC(zx_ENC_SO_wst_Issuer) */

/* Render element into string. The XML attributes and elements are
 * processed in schema order. This is what you generally want for
 * rendering new data structure to a string. The wo pointers are not used. */

/* Called by: */
char* zx_ENC_SO_wst_Issuer(struct zx_ctx* c, struct zx_wst_Issuer_s* x, char* p )
{
  struct zx_elem_s* se MAYBE_UNUSED;
  ENC_LEN_DEBUG_BASE;
#if 1 /* NORMALMODE */
  struct zx_ns_s* pop_seen = 0;
  /* *** in simple_elem case should output ns prefix from ns node. */
  ZX_OUT_TAG(p, "<wst:Issuer");
  if (c->inc_ns)
    p = zx_enc_inc_ns(c, p, &pop_seen);
  if (x->actor || x->mustUnderstand)
    p = zx_enc_xmlns_if_not_seen(c, p, zx_ns_tab+zx_xmlns_ix_e, &pop_seen);
  p = zx_enc_xmlns_if_not_seen(c, p, zx_ns_tab+zx_xmlns_ix_wst, &pop_seen);
  if (x->Id)
    p = zx_enc_xmlns_if_not_seen(c, p, zx_ns_tab+zx_xmlns_ix_wsu, &pop_seen);

  p = zx_attr_so_enc(p, x->ID, " ID=\"", sizeof(" ID=\"")-1);
  p = zx_attr_so_enc(p, x->id, " id=\"", sizeof(" id=\"")-1);
  p = zx_attr_so_enc(p, x->notOnOrAfter, " notOnOrAfter=\"", sizeof(" notOnOrAfter=\"")-1);
  p = zx_attr_so_enc(p, x->Id, " wsu:Id=\"", sizeof(" wsu:Id=\"")-1);
  p = zx_attr_so_enc(p, x->actor, " e:actor=\"", sizeof(" e:actor=\"")-1);
  p = zx_attr_so_enc(p, x->mustUnderstand, " e:mustUnderstand=\"", sizeof(" e:mustUnderstand=\"")-1);

  p = zx_enc_unknown_attrs(p, x->gg.any_attr);
#else
  /* root node has no begin tag */
#endif
  
  {
      struct zx_a_Address_s* e;
      for (e = x->Address; e; e = (struct zx_a_Address_s*)e->gg.g.n)
	  p = zx_ENC_SO_a_Address(c, e, p);
  }
  {
      struct zx_a_ReferenceParameters_s* e;
      for (e = x->ReferenceParameters; e; e = (struct zx_a_ReferenceParameters_s*)e->gg.g.n)
	  p = zx_ENC_SO_a_ReferenceParameters(c, e, p);
  }
  {
      struct zx_a_Metadata_s* e;
      for (e = x->Metadata; e; e = (struct zx_a_Metadata_s*)e->gg.g.n)
	  p = zx_ENC_SO_a_Metadata(c, e, p);
  }

  p = zx_enc_so_unknown_elems_and_content(c, p, &x->gg);
  
#if 1 /* NORMALMODE */
  ZX_OUT_CLOSE_TAG(p, "</wst:Issuer>");
  zx_pop_seen(pop_seen);
#else
  /* root node has no end tag either */
#endif
  ENC_LEN_DEBUG(x, "wst:Issuer", p-enc_base);
  return p;
}

/* FUNC(zx_ENC_WO_wst_Issuer) */

/* Render element into string. The XML attributes and elements are
 * processed in wire order by chasing wo pointers. This is what you want for
 * validating signatures on other people's XML documents. */

/* Called by: */
char* zx_ENC_WO_wst_Issuer(struct zx_ctx* c, struct zx_wst_Issuer_s* x, char* p )
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
  ZX_OUT_MEM(p, "Issuer", sizeof("Issuer")-1);
  qq = p;

  /* *** sort the namespaces */
  if (c->inc_ns)
    zx_add_inc_ns(c, &pop_seen);
  if (x->actor)
    zx_add_xmlns_if_not_seen(c, x->actor->g.ns, &pop_seen);
  if (x->mustUnderstand)
    zx_add_xmlns_if_not_seen(c, x->mustUnderstand->g.ns, &pop_seen);
  zx_add_xmlns_if_not_seen(c, x->gg.g.ns, &pop_seen);
  if (x->Id)
    zx_add_xmlns_if_not_seen(c, x->Id->g.ns, &pop_seen);

  p = zx_enc_seen(p, pop_seen); 
  p = zx_attr_wo_enc(p, x->ID, "ID=\"", sizeof("ID=\"")-1);
  p = zx_attr_wo_enc(p, x->id, "id=\"", sizeof("id=\"")-1);
  p = zx_attr_wo_enc(p, x->notOnOrAfter, "notOnOrAfter=\"", sizeof("notOnOrAfter=\"")-1);
  p = zx_attr_wo_enc(p, x->Id, "Id=\"", sizeof("Id=\"")-1);
  p = zx_attr_wo_enc(p, x->actor, "actor=\"", sizeof("actor=\"")-1);
  p = zx_attr_wo_enc(p, x->mustUnderstand, "mustUnderstand=\"", sizeof("mustUnderstand=\"")-1);

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
  ENC_LEN_DEBUG(x, "wst:Issuer", p-enc_base);
  return p;
}

/* FUNC(zx_EASY_ENC_SO_wst_Issuer) */

/* Called by: */
struct zx_str* zx_EASY_ENC_SO_wst_Issuer(struct zx_ctx* c, struct zx_wst_Issuer_s* x )
{
  int len;
  char* buf;
  c->ns_tab = ZX_ALLOC(c, sizeof(zx_ns_tab));
  memcpy(c->ns_tab, zx_ns_tab, sizeof(zx_ns_tab));
  len = zx_LEN_SO_wst_Issuer(c, x );
  buf = ZX_ALLOC(c, len+1);
  return zx_easy_enc_common(c, zx_ENC_SO_wst_Issuer(c, x, buf ), buf, len);
}

/* FUNC(zx_EASY_ENC_WO_wst_Issuer) */

/* Called by: */
struct zx_str* zx_EASY_ENC_WO_wst_Issuer(struct zx_ctx* c, struct zx_wst_Issuer_s* x )
{
  int len;
  char* buf;
  c->ns_tab = ZX_ALLOC(c, sizeof(zx_ns_tab));
  memcpy(c->ns_tab, zx_ns_tab, sizeof(zx_ns_tab));
  len = zx_LEN_WO_wst_Issuer(c, x );
  buf = ZX_ALLOC(c, len+1);
  return zx_easy_enc_common(c, zx_ENC_WO_wst_Issuer(c, x, buf ), buf, len);
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

#define EL_NAME   wst_KeyExchangeToken
#define EL_STRUCT zx_wst_KeyExchangeToken_s
#define EL_NS     wst
#define EL_TAG    KeyExchangeToken

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

/* FUNC(zx_LEN_SO_wst_KeyExchangeToken) */

/* Compute length of an element (and its subelements). The XML attributes
 * and elements are processed in schema order. */

/* Called by: */
int zx_LEN_SO_wst_KeyExchangeToken(struct zx_ctx* c, struct zx_wst_KeyExchangeToken_s* x )
{
  struct zx_ns_s* pop_seen = 0;
  struct zx_elem_s* se MAYBE_UNUSED;
#if 1 /* NORMALMODE */
  /* *** in simple_elem case should output ns prefix from ns node. */
  int len = sizeof("<wst:KeyExchangeToken")-1 + 1 + sizeof("</wst:KeyExchangeToken>")-1;
  if (c->inc_ns_len)
    len += zx_len_inc_ns(c, &pop_seen);
  len += zx_len_xmlns_if_not_seen(c, zx_ns_tab+zx_xmlns_ix_wst, &pop_seen);


#else
  /* root node has no begin tag */
  int len = 0;
#endif
  


  len += zx_len_so_common(c, &x->gg);
  zx_pop_seen(pop_seen);
  ENC_LEN_DEBUG(x, "wst:KeyExchangeToken", len);
  return len;
}

/* FUNC(zx_LEN_WO_wst_KeyExchangeToken) */

/* Compute length of an element (and its subelements). The XML attributes
 * and elements are processed in wire order and no assumptions
 * are made about namespace prefixes. */

/* Called by: */
int zx_LEN_WO_wst_KeyExchangeToken(struct zx_ctx* c, struct zx_wst_KeyExchangeToken_s* x )
{
  struct zx_ns_s* pop_seen = 0;
  struct zx_elem_s* se MAYBE_UNUSED;
#if 1 /* NORMALMODE */
  int len = 1 + sizeof("KeyExchangeToken")-1 + 1 + 2 + sizeof("KeyExchangeToken")-1 + 1;
  
  if (x->gg.g.ns && x->gg.g.ns->prefix_len)
    len += (x->gg.g.ns->prefix_len + 1) * 2;
  if (c->inc_ns_len)
    len += zx_len_inc_ns(c, &pop_seen);
  len += zx_len_xmlns_if_not_seen(c, x->gg.g.ns, &pop_seen);


#else
  /* root node has no begin tag */
  int len = 0;
#endif
  


  len += zx_len_wo_common(c, &x->gg); 
  zx_pop_seen(pop_seen);
  ENC_LEN_DEBUG(x, "wst:KeyExchangeToken", len);
  return len;
}

/* FUNC(zx_ENC_SO_wst_KeyExchangeToken) */

/* Render element into string. The XML attributes and elements are
 * processed in schema order. This is what you generally want for
 * rendering new data structure to a string. The wo pointers are not used. */

/* Called by: */
char* zx_ENC_SO_wst_KeyExchangeToken(struct zx_ctx* c, struct zx_wst_KeyExchangeToken_s* x, char* p )
{
  struct zx_elem_s* se MAYBE_UNUSED;
  ENC_LEN_DEBUG_BASE;
#if 1 /* NORMALMODE */
  struct zx_ns_s* pop_seen = 0;
  /* *** in simple_elem case should output ns prefix from ns node. */
  ZX_OUT_TAG(p, "<wst:KeyExchangeToken");
  if (c->inc_ns)
    p = zx_enc_inc_ns(c, p, &pop_seen);
  p = zx_enc_xmlns_if_not_seen(c, p, zx_ns_tab+zx_xmlns_ix_wst, &pop_seen);


  p = zx_enc_unknown_attrs(p, x->gg.any_attr);
#else
  /* root node has no begin tag */
#endif
  

  p = zx_enc_so_unknown_elems_and_content(c, p, &x->gg);
  
#if 1 /* NORMALMODE */
  ZX_OUT_CLOSE_TAG(p, "</wst:KeyExchangeToken>");
  zx_pop_seen(pop_seen);
#else
  /* root node has no end tag either */
#endif
  ENC_LEN_DEBUG(x, "wst:KeyExchangeToken", p-enc_base);
  return p;
}

/* FUNC(zx_ENC_WO_wst_KeyExchangeToken) */

/* Render element into string. The XML attributes and elements are
 * processed in wire order by chasing wo pointers. This is what you want for
 * validating signatures on other people's XML documents. */

/* Called by: */
char* zx_ENC_WO_wst_KeyExchangeToken(struct zx_ctx* c, struct zx_wst_KeyExchangeToken_s* x, char* p )
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
  ZX_OUT_MEM(p, "KeyExchangeToken", sizeof("KeyExchangeToken")-1);
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
  ENC_LEN_DEBUG(x, "wst:KeyExchangeToken", p-enc_base);
  return p;
}

/* FUNC(zx_EASY_ENC_SO_wst_KeyExchangeToken) */

/* Called by: */
struct zx_str* zx_EASY_ENC_SO_wst_KeyExchangeToken(struct zx_ctx* c, struct zx_wst_KeyExchangeToken_s* x )
{
  int len;
  char* buf;
  c->ns_tab = ZX_ALLOC(c, sizeof(zx_ns_tab));
  memcpy(c->ns_tab, zx_ns_tab, sizeof(zx_ns_tab));
  len = zx_LEN_SO_wst_KeyExchangeToken(c, x );
  buf = ZX_ALLOC(c, len+1);
  return zx_easy_enc_common(c, zx_ENC_SO_wst_KeyExchangeToken(c, x, buf ), buf, len);
}

/* FUNC(zx_EASY_ENC_WO_wst_KeyExchangeToken) */

/* Called by: */
struct zx_str* zx_EASY_ENC_WO_wst_KeyExchangeToken(struct zx_ctx* c, struct zx_wst_KeyExchangeToken_s* x )
{
  int len;
  char* buf;
  c->ns_tab = ZX_ALLOC(c, sizeof(zx_ns_tab));
  memcpy(c->ns_tab, zx_ns_tab, sizeof(zx_ns_tab));
  len = zx_LEN_WO_wst_KeyExchangeToken(c, x );
  buf = ZX_ALLOC(c, len+1);
  return zx_easy_enc_common(c, zx_ENC_WO_wst_KeyExchangeToken(c, x, buf ), buf, len);
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

#define EL_NAME   wst_Lifetime
#define EL_STRUCT zx_wst_Lifetime_s
#define EL_NS     wst
#define EL_TAG    Lifetime

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

/* FUNC(zx_LEN_SO_wst_Lifetime) */

/* Compute length of an element (and its subelements). The XML attributes
 * and elements are processed in schema order. */

/* Called by: */
int zx_LEN_SO_wst_Lifetime(struct zx_ctx* c, struct zx_wst_Lifetime_s* x )
{
  struct zx_ns_s* pop_seen = 0;
  struct zx_elem_s* se MAYBE_UNUSED;
#if 1 /* NORMALMODE */
  /* *** in simple_elem case should output ns prefix from ns node. */
  int len = sizeof("<wst:Lifetime")-1 + 1 + sizeof("</wst:Lifetime>")-1;
  if (c->inc_ns_len)
    len += zx_len_inc_ns(c, &pop_seen);
  len += zx_len_xmlns_if_not_seen(c, zx_ns_tab+zx_xmlns_ix_wst, &pop_seen);


#else
  /* root node has no begin tag */
  int len = 0;
#endif
  
  {
      struct zx_wsu_Created_s* e;
      for (e = x->Created; e; e = (struct zx_wsu_Created_s*)e->gg.g.n)
	  len += zx_LEN_SO_wsu_Created(c, e);
  }
  {
      struct zx_wsu_Expires_s* e;
      for (e = x->Expires; e; e = (struct zx_wsu_Expires_s*)e->gg.g.n)
	  len += zx_LEN_SO_wsu_Expires(c, e);
  }


  len += zx_len_so_common(c, &x->gg);
  zx_pop_seen(pop_seen);
  ENC_LEN_DEBUG(x, "wst:Lifetime", len);
  return len;
}

/* FUNC(zx_LEN_WO_wst_Lifetime) */

/* Compute length of an element (and its subelements). The XML attributes
 * and elements are processed in wire order and no assumptions
 * are made about namespace prefixes. */

/* Called by: */
int zx_LEN_WO_wst_Lifetime(struct zx_ctx* c, struct zx_wst_Lifetime_s* x )
{
  struct zx_ns_s* pop_seen = 0;
  struct zx_elem_s* se MAYBE_UNUSED;
#if 1 /* NORMALMODE */
  int len = 1 + sizeof("Lifetime")-1 + 1 + 2 + sizeof("Lifetime")-1 + 1;
  
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
      struct zx_wsu_Created_s* e;
      for (e = x->Created; e; e = (struct zx_wsu_Created_s*)e->gg.g.n)
	  len += zx_LEN_WO_wsu_Created(c, e);
  }
  {
      struct zx_wsu_Expires_s* e;
      for (e = x->Expires; e; e = (struct zx_wsu_Expires_s*)e->gg.g.n)
	  len += zx_LEN_WO_wsu_Expires(c, e);
  }


  len += zx_len_wo_common(c, &x->gg); 
  zx_pop_seen(pop_seen);
  ENC_LEN_DEBUG(x, "wst:Lifetime", len);
  return len;
}

/* FUNC(zx_ENC_SO_wst_Lifetime) */

/* Render element into string. The XML attributes and elements are
 * processed in schema order. This is what you generally want for
 * rendering new data structure to a string. The wo pointers are not used. */

/* Called by: */
char* zx_ENC_SO_wst_Lifetime(struct zx_ctx* c, struct zx_wst_Lifetime_s* x, char* p )
{
  struct zx_elem_s* se MAYBE_UNUSED;
  ENC_LEN_DEBUG_BASE;
#if 1 /* NORMALMODE */
  struct zx_ns_s* pop_seen = 0;
  /* *** in simple_elem case should output ns prefix from ns node. */
  ZX_OUT_TAG(p, "<wst:Lifetime");
  if (c->inc_ns)
    p = zx_enc_inc_ns(c, p, &pop_seen);
  p = zx_enc_xmlns_if_not_seen(c, p, zx_ns_tab+zx_xmlns_ix_wst, &pop_seen);


  p = zx_enc_unknown_attrs(p, x->gg.any_attr);
#else
  /* root node has no begin tag */
#endif
  
  {
      struct zx_wsu_Created_s* e;
      for (e = x->Created; e; e = (struct zx_wsu_Created_s*)e->gg.g.n)
	  p = zx_ENC_SO_wsu_Created(c, e, p);
  }
  {
      struct zx_wsu_Expires_s* e;
      for (e = x->Expires; e; e = (struct zx_wsu_Expires_s*)e->gg.g.n)
	  p = zx_ENC_SO_wsu_Expires(c, e, p);
  }

  p = zx_enc_so_unknown_elems_and_content(c, p, &x->gg);
  
#if 1 /* NORMALMODE */
  ZX_OUT_CLOSE_TAG(p, "</wst:Lifetime>");
  zx_pop_seen(pop_seen);
#else
  /* root node has no end tag either */
#endif
  ENC_LEN_DEBUG(x, "wst:Lifetime", p-enc_base);
  return p;
}

/* FUNC(zx_ENC_WO_wst_Lifetime) */

/* Render element into string. The XML attributes and elements are
 * processed in wire order by chasing wo pointers. This is what you want for
 * validating signatures on other people's XML documents. */

/* Called by: */
char* zx_ENC_WO_wst_Lifetime(struct zx_ctx* c, struct zx_wst_Lifetime_s* x, char* p )
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
  ZX_OUT_MEM(p, "Lifetime", sizeof("Lifetime")-1);
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
  ENC_LEN_DEBUG(x, "wst:Lifetime", p-enc_base);
  return p;
}

/* FUNC(zx_EASY_ENC_SO_wst_Lifetime) */

/* Called by: */
struct zx_str* zx_EASY_ENC_SO_wst_Lifetime(struct zx_ctx* c, struct zx_wst_Lifetime_s* x )
{
  int len;
  char* buf;
  c->ns_tab = ZX_ALLOC(c, sizeof(zx_ns_tab));
  memcpy(c->ns_tab, zx_ns_tab, sizeof(zx_ns_tab));
  len = zx_LEN_SO_wst_Lifetime(c, x );
  buf = ZX_ALLOC(c, len+1);
  return zx_easy_enc_common(c, zx_ENC_SO_wst_Lifetime(c, x, buf ), buf, len);
}

/* FUNC(zx_EASY_ENC_WO_wst_Lifetime) */

/* Called by: */
struct zx_str* zx_EASY_ENC_WO_wst_Lifetime(struct zx_ctx* c, struct zx_wst_Lifetime_s* x )
{
  int len;
  char* buf;
  c->ns_tab = ZX_ALLOC(c, sizeof(zx_ns_tab));
  memcpy(c->ns_tab, zx_ns_tab, sizeof(zx_ns_tab));
  len = zx_LEN_WO_wst_Lifetime(c, x );
  buf = ZX_ALLOC(c, len+1);
  return zx_easy_enc_common(c, zx_ENC_WO_wst_Lifetime(c, x, buf ), buf, len);
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

#define EL_NAME   wst_OnBehalfOf
#define EL_STRUCT zx_wst_OnBehalfOf_s
#define EL_NS     wst
#define EL_TAG    OnBehalfOf

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

/* FUNC(zx_LEN_SO_wst_OnBehalfOf) */

/* Compute length of an element (and its subelements). The XML attributes
 * and elements are processed in schema order. */

/* Called by: */
int zx_LEN_SO_wst_OnBehalfOf(struct zx_ctx* c, struct zx_wst_OnBehalfOf_s* x )
{
  struct zx_ns_s* pop_seen = 0;
  struct zx_elem_s* se MAYBE_UNUSED;
#if 1 /* NORMALMODE */
  /* *** in simple_elem case should output ns prefix from ns node. */
  int len = sizeof("<wst:OnBehalfOf")-1 + 1 + sizeof("</wst:OnBehalfOf>")-1;
  if (c->inc_ns_len)
    len += zx_len_inc_ns(c, &pop_seen);
  len += zx_len_xmlns_if_not_seen(c, zx_ns_tab+zx_xmlns_ix_wst, &pop_seen);


#else
  /* root node has no begin tag */
  int len = 0;
#endif
  


  len += zx_len_so_common(c, &x->gg);
  zx_pop_seen(pop_seen);
  ENC_LEN_DEBUG(x, "wst:OnBehalfOf", len);
  return len;
}

/* FUNC(zx_LEN_WO_wst_OnBehalfOf) */

/* Compute length of an element (and its subelements). The XML attributes
 * and elements are processed in wire order and no assumptions
 * are made about namespace prefixes. */

/* Called by: */
int zx_LEN_WO_wst_OnBehalfOf(struct zx_ctx* c, struct zx_wst_OnBehalfOf_s* x )
{
  struct zx_ns_s* pop_seen = 0;
  struct zx_elem_s* se MAYBE_UNUSED;
#if 1 /* NORMALMODE */
  int len = 1 + sizeof("OnBehalfOf")-1 + 1 + 2 + sizeof("OnBehalfOf")-1 + 1;
  
  if (x->gg.g.ns && x->gg.g.ns->prefix_len)
    len += (x->gg.g.ns->prefix_len + 1) * 2;
  if (c->inc_ns_len)
    len += zx_len_inc_ns(c, &pop_seen);
  len += zx_len_xmlns_if_not_seen(c, x->gg.g.ns, &pop_seen);


#else
  /* root node has no begin tag */
  int len = 0;
#endif
  


  len += zx_len_wo_common(c, &x->gg); 
  zx_pop_seen(pop_seen);
  ENC_LEN_DEBUG(x, "wst:OnBehalfOf", len);
  return len;
}

/* FUNC(zx_ENC_SO_wst_OnBehalfOf) */

/* Render element into string. The XML attributes and elements are
 * processed in schema order. This is what you generally want for
 * rendering new data structure to a string. The wo pointers are not used. */

/* Called by: */
char* zx_ENC_SO_wst_OnBehalfOf(struct zx_ctx* c, struct zx_wst_OnBehalfOf_s* x, char* p )
{
  struct zx_elem_s* se MAYBE_UNUSED;
  ENC_LEN_DEBUG_BASE;
#if 1 /* NORMALMODE */
  struct zx_ns_s* pop_seen = 0;
  /* *** in simple_elem case should output ns prefix from ns node. */
  ZX_OUT_TAG(p, "<wst:OnBehalfOf");
  if (c->inc_ns)
    p = zx_enc_inc_ns(c, p, &pop_seen);
  p = zx_enc_xmlns_if_not_seen(c, p, zx_ns_tab+zx_xmlns_ix_wst, &pop_seen);


  p = zx_enc_unknown_attrs(p, x->gg.any_attr);
#else
  /* root node has no begin tag */
#endif
  

  p = zx_enc_so_unknown_elems_and_content(c, p, &x->gg);
  
#if 1 /* NORMALMODE */
  ZX_OUT_CLOSE_TAG(p, "</wst:OnBehalfOf>");
  zx_pop_seen(pop_seen);
#else
  /* root node has no end tag either */
#endif
  ENC_LEN_DEBUG(x, "wst:OnBehalfOf", p-enc_base);
  return p;
}

/* FUNC(zx_ENC_WO_wst_OnBehalfOf) */

/* Render element into string. The XML attributes and elements are
 * processed in wire order by chasing wo pointers. This is what you want for
 * validating signatures on other people's XML documents. */

/* Called by: */
char* zx_ENC_WO_wst_OnBehalfOf(struct zx_ctx* c, struct zx_wst_OnBehalfOf_s* x, char* p )
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
  ZX_OUT_MEM(p, "OnBehalfOf", sizeof("OnBehalfOf")-1);
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
  ENC_LEN_DEBUG(x, "wst:OnBehalfOf", p-enc_base);
  return p;
}

/* FUNC(zx_EASY_ENC_SO_wst_OnBehalfOf) */

/* Called by: */
struct zx_str* zx_EASY_ENC_SO_wst_OnBehalfOf(struct zx_ctx* c, struct zx_wst_OnBehalfOf_s* x )
{
  int len;
  char* buf;
  c->ns_tab = ZX_ALLOC(c, sizeof(zx_ns_tab));
  memcpy(c->ns_tab, zx_ns_tab, sizeof(zx_ns_tab));
  len = zx_LEN_SO_wst_OnBehalfOf(c, x );
  buf = ZX_ALLOC(c, len+1);
  return zx_easy_enc_common(c, zx_ENC_SO_wst_OnBehalfOf(c, x, buf ), buf, len);
}

/* FUNC(zx_EASY_ENC_WO_wst_OnBehalfOf) */

/* Called by: */
struct zx_str* zx_EASY_ENC_WO_wst_OnBehalfOf(struct zx_ctx* c, struct zx_wst_OnBehalfOf_s* x )
{
  int len;
  char* buf;
  c->ns_tab = ZX_ALLOC(c, sizeof(zx_ns_tab));
  memcpy(c->ns_tab, zx_ns_tab, sizeof(zx_ns_tab));
  len = zx_LEN_WO_wst_OnBehalfOf(c, x );
  buf = ZX_ALLOC(c, len+1);
  return zx_easy_enc_common(c, zx_ENC_WO_wst_OnBehalfOf(c, x, buf ), buf, len);
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

#define EL_NAME   wst_Participant
#define EL_STRUCT zx_wst_Participant_s
#define EL_NS     wst
#define EL_TAG    Participant

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

/* FUNC(zx_LEN_SO_wst_Participant) */

/* Compute length of an element (and its subelements). The XML attributes
 * and elements are processed in schema order. */

/* Called by: */
int zx_LEN_SO_wst_Participant(struct zx_ctx* c, struct zx_wst_Participant_s* x )
{
  struct zx_ns_s* pop_seen = 0;
  struct zx_elem_s* se MAYBE_UNUSED;
#if 1 /* NORMALMODE */
  /* *** in simple_elem case should output ns prefix from ns node. */
  int len = sizeof("<wst:Participant")-1 + 1 + sizeof("</wst:Participant>")-1;
  if (c->inc_ns_len)
    len += zx_len_inc_ns(c, &pop_seen);
  len += zx_len_xmlns_if_not_seen(c, zx_ns_tab+zx_xmlns_ix_wst, &pop_seen);


#else
  /* root node has no begin tag */
  int len = 0;
#endif
  


  len += zx_len_so_common(c, &x->gg);
  zx_pop_seen(pop_seen);
  ENC_LEN_DEBUG(x, "wst:Participant", len);
  return len;
}

/* FUNC(zx_LEN_WO_wst_Participant) */

/* Compute length of an element (and its subelements). The XML attributes
 * and elements are processed in wire order and no assumptions
 * are made about namespace prefixes. */

/* Called by: */
int zx_LEN_WO_wst_Participant(struct zx_ctx* c, struct zx_wst_Participant_s* x )
{
  struct zx_ns_s* pop_seen = 0;
  struct zx_elem_s* se MAYBE_UNUSED;
#if 1 /* NORMALMODE */
  int len = 1 + sizeof("Participant")-1 + 1 + 2 + sizeof("Participant")-1 + 1;
  
  if (x->gg.g.ns && x->gg.g.ns->prefix_len)
    len += (x->gg.g.ns->prefix_len + 1) * 2;
  if (c->inc_ns_len)
    len += zx_len_inc_ns(c, &pop_seen);
  len += zx_len_xmlns_if_not_seen(c, x->gg.g.ns, &pop_seen);


#else
  /* root node has no begin tag */
  int len = 0;
#endif
  


  len += zx_len_wo_common(c, &x->gg); 
  zx_pop_seen(pop_seen);
  ENC_LEN_DEBUG(x, "wst:Participant", len);
  return len;
}

/* FUNC(zx_ENC_SO_wst_Participant) */

/* Render element into string. The XML attributes and elements are
 * processed in schema order. This is what you generally want for
 * rendering new data structure to a string. The wo pointers are not used. */

/* Called by: */
char* zx_ENC_SO_wst_Participant(struct zx_ctx* c, struct zx_wst_Participant_s* x, char* p )
{
  struct zx_elem_s* se MAYBE_UNUSED;
  ENC_LEN_DEBUG_BASE;
#if 1 /* NORMALMODE */
  struct zx_ns_s* pop_seen = 0;
  /* *** in simple_elem case should output ns prefix from ns node. */
  ZX_OUT_TAG(p, "<wst:Participant");
  if (c->inc_ns)
    p = zx_enc_inc_ns(c, p, &pop_seen);
  p = zx_enc_xmlns_if_not_seen(c, p, zx_ns_tab+zx_xmlns_ix_wst, &pop_seen);


  p = zx_enc_unknown_attrs(p, x->gg.any_attr);
#else
  /* root node has no begin tag */
#endif
  

  p = zx_enc_so_unknown_elems_and_content(c, p, &x->gg);
  
#if 1 /* NORMALMODE */
  ZX_OUT_CLOSE_TAG(p, "</wst:Participant>");
  zx_pop_seen(pop_seen);
#else
  /* root node has no end tag either */
#endif
  ENC_LEN_DEBUG(x, "wst:Participant", p-enc_base);
  return p;
}

/* FUNC(zx_ENC_WO_wst_Participant) */

/* Render element into string. The XML attributes and elements are
 * processed in wire order by chasing wo pointers. This is what you want for
 * validating signatures on other people's XML documents. */

/* Called by: */
char* zx_ENC_WO_wst_Participant(struct zx_ctx* c, struct zx_wst_Participant_s* x, char* p )
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
  ZX_OUT_MEM(p, "Participant", sizeof("Participant")-1);
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
  ENC_LEN_DEBUG(x, "wst:Participant", p-enc_base);
  return p;
}

/* FUNC(zx_EASY_ENC_SO_wst_Participant) */

/* Called by: */
struct zx_str* zx_EASY_ENC_SO_wst_Participant(struct zx_ctx* c, struct zx_wst_Participant_s* x )
{
  int len;
  char* buf;
  c->ns_tab = ZX_ALLOC(c, sizeof(zx_ns_tab));
  memcpy(c->ns_tab, zx_ns_tab, sizeof(zx_ns_tab));
  len = zx_LEN_SO_wst_Participant(c, x );
  buf = ZX_ALLOC(c, len+1);
  return zx_easy_enc_common(c, zx_ENC_SO_wst_Participant(c, x, buf ), buf, len);
}

/* FUNC(zx_EASY_ENC_WO_wst_Participant) */

/* Called by: */
struct zx_str* zx_EASY_ENC_WO_wst_Participant(struct zx_ctx* c, struct zx_wst_Participant_s* x )
{
  int len;
  char* buf;
  c->ns_tab = ZX_ALLOC(c, sizeof(zx_ns_tab));
  memcpy(c->ns_tab, zx_ns_tab, sizeof(zx_ns_tab));
  len = zx_LEN_WO_wst_Participant(c, x );
  buf = ZX_ALLOC(c, len+1);
  return zx_easy_enc_common(c, zx_ENC_WO_wst_Participant(c, x, buf ), buf, len);
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

#define EL_NAME   wst_Participants
#define EL_STRUCT zx_wst_Participants_s
#define EL_NS     wst
#define EL_TAG    Participants

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

/* FUNC(zx_LEN_SO_wst_Participants) */

/* Compute length of an element (and its subelements). The XML attributes
 * and elements are processed in schema order. */

/* Called by: */
int zx_LEN_SO_wst_Participants(struct zx_ctx* c, struct zx_wst_Participants_s* x )
{
  struct zx_ns_s* pop_seen = 0;
  struct zx_elem_s* se MAYBE_UNUSED;
#if 1 /* NORMALMODE */
  /* *** in simple_elem case should output ns prefix from ns node. */
  int len = sizeof("<wst:Participants")-1 + 1 + sizeof("</wst:Participants>")-1;
  if (c->inc_ns_len)
    len += zx_len_inc_ns(c, &pop_seen);
  len += zx_len_xmlns_if_not_seen(c, zx_ns_tab+zx_xmlns_ix_wst, &pop_seen);


#else
  /* root node has no begin tag */
  int len = 0;
#endif
  
  {
      struct zx_wst_Primary_s* e;
      for (e = x->Primary; e; e = (struct zx_wst_Primary_s*)e->gg.g.n)
	  len += zx_LEN_SO_wst_Primary(c, e);
  }
  {
      struct zx_wst_Participant_s* e;
      for (e = x->Participant; e; e = (struct zx_wst_Participant_s*)e->gg.g.n)
	  len += zx_LEN_SO_wst_Participant(c, e);
  }


  len += zx_len_so_common(c, &x->gg);
  zx_pop_seen(pop_seen);
  ENC_LEN_DEBUG(x, "wst:Participants", len);
  return len;
}

/* FUNC(zx_LEN_WO_wst_Participants) */

/* Compute length of an element (and its subelements). The XML attributes
 * and elements are processed in wire order and no assumptions
 * are made about namespace prefixes. */

/* Called by: */
int zx_LEN_WO_wst_Participants(struct zx_ctx* c, struct zx_wst_Participants_s* x )
{
  struct zx_ns_s* pop_seen = 0;
  struct zx_elem_s* se MAYBE_UNUSED;
#if 1 /* NORMALMODE */
  int len = 1 + sizeof("Participants")-1 + 1 + 2 + sizeof("Participants")-1 + 1;
  
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
      struct zx_wst_Primary_s* e;
      for (e = x->Primary; e; e = (struct zx_wst_Primary_s*)e->gg.g.n)
	  len += zx_LEN_WO_wst_Primary(c, e);
  }
  {
      struct zx_wst_Participant_s* e;
      for (e = x->Participant; e; e = (struct zx_wst_Participant_s*)e->gg.g.n)
	  len += zx_LEN_WO_wst_Participant(c, e);
  }


  len += zx_len_wo_common(c, &x->gg); 
  zx_pop_seen(pop_seen);
  ENC_LEN_DEBUG(x, "wst:Participants", len);
  return len;
}

/* FUNC(zx_ENC_SO_wst_Participants) */

/* Render element into string. The XML attributes and elements are
 * processed in schema order. This is what you generally want for
 * rendering new data structure to a string. The wo pointers are not used. */

/* Called by: */
char* zx_ENC_SO_wst_Participants(struct zx_ctx* c, struct zx_wst_Participants_s* x, char* p )
{
  struct zx_elem_s* se MAYBE_UNUSED;
  ENC_LEN_DEBUG_BASE;
#if 1 /* NORMALMODE */
  struct zx_ns_s* pop_seen = 0;
  /* *** in simple_elem case should output ns prefix from ns node. */
  ZX_OUT_TAG(p, "<wst:Participants");
  if (c->inc_ns)
    p = zx_enc_inc_ns(c, p, &pop_seen);
  p = zx_enc_xmlns_if_not_seen(c, p, zx_ns_tab+zx_xmlns_ix_wst, &pop_seen);


  p = zx_enc_unknown_attrs(p, x->gg.any_attr);
#else
  /* root node has no begin tag */
#endif
  
  {
      struct zx_wst_Primary_s* e;
      for (e = x->Primary; e; e = (struct zx_wst_Primary_s*)e->gg.g.n)
	  p = zx_ENC_SO_wst_Primary(c, e, p);
  }
  {
      struct zx_wst_Participant_s* e;
      for (e = x->Participant; e; e = (struct zx_wst_Participant_s*)e->gg.g.n)
	  p = zx_ENC_SO_wst_Participant(c, e, p);
  }

  p = zx_enc_so_unknown_elems_and_content(c, p, &x->gg);
  
#if 1 /* NORMALMODE */
  ZX_OUT_CLOSE_TAG(p, "</wst:Participants>");
  zx_pop_seen(pop_seen);
#else
  /* root node has no end tag either */
#endif
  ENC_LEN_DEBUG(x, "wst:Participants", p-enc_base);
  return p;
}

/* FUNC(zx_ENC_WO_wst_Participants) */

/* Render element into string. The XML attributes and elements are
 * processed in wire order by chasing wo pointers. This is what you want for
 * validating signatures on other people's XML documents. */

/* Called by: */
char* zx_ENC_WO_wst_Participants(struct zx_ctx* c, struct zx_wst_Participants_s* x, char* p )
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
  ZX_OUT_MEM(p, "Participants", sizeof("Participants")-1);
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
  ENC_LEN_DEBUG(x, "wst:Participants", p-enc_base);
  return p;
}

/* FUNC(zx_EASY_ENC_SO_wst_Participants) */

/* Called by: */
struct zx_str* zx_EASY_ENC_SO_wst_Participants(struct zx_ctx* c, struct zx_wst_Participants_s* x )
{
  int len;
  char* buf;
  c->ns_tab = ZX_ALLOC(c, sizeof(zx_ns_tab));
  memcpy(c->ns_tab, zx_ns_tab, sizeof(zx_ns_tab));
  len = zx_LEN_SO_wst_Participants(c, x );
  buf = ZX_ALLOC(c, len+1);
  return zx_easy_enc_common(c, zx_ENC_SO_wst_Participants(c, x, buf ), buf, len);
}

/* FUNC(zx_EASY_ENC_WO_wst_Participants) */

/* Called by: */
struct zx_str* zx_EASY_ENC_WO_wst_Participants(struct zx_ctx* c, struct zx_wst_Participants_s* x )
{
  int len;
  char* buf;
  c->ns_tab = ZX_ALLOC(c, sizeof(zx_ns_tab));
  memcpy(c->ns_tab, zx_ns_tab, sizeof(zx_ns_tab));
  len = zx_LEN_WO_wst_Participants(c, x );
  buf = ZX_ALLOC(c, len+1);
  return zx_easy_enc_common(c, zx_ENC_WO_wst_Participants(c, x, buf ), buf, len);
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

#define EL_NAME   wst_Primary
#define EL_STRUCT zx_wst_Primary_s
#define EL_NS     wst
#define EL_TAG    Primary

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

/* FUNC(zx_LEN_SO_wst_Primary) */

/* Compute length of an element (and its subelements). The XML attributes
 * and elements are processed in schema order. */

/* Called by: */
int zx_LEN_SO_wst_Primary(struct zx_ctx* c, struct zx_wst_Primary_s* x )
{
  struct zx_ns_s* pop_seen = 0;
  struct zx_elem_s* se MAYBE_UNUSED;
#if 1 /* NORMALMODE */
  /* *** in simple_elem case should output ns prefix from ns node. */
  int len = sizeof("<wst:Primary")-1 + 1 + sizeof("</wst:Primary>")-1;
  if (c->inc_ns_len)
    len += zx_len_inc_ns(c, &pop_seen);
  len += zx_len_xmlns_if_not_seen(c, zx_ns_tab+zx_xmlns_ix_wst, &pop_seen);


#else
  /* root node has no begin tag */
  int len = 0;
#endif
  


  len += zx_len_so_common(c, &x->gg);
  zx_pop_seen(pop_seen);
  ENC_LEN_DEBUG(x, "wst:Primary", len);
  return len;
}

/* FUNC(zx_LEN_WO_wst_Primary) */

/* Compute length of an element (and its subelements). The XML attributes
 * and elements are processed in wire order and no assumptions
 * are made about namespace prefixes. */

/* Called by: */
int zx_LEN_WO_wst_Primary(struct zx_ctx* c, struct zx_wst_Primary_s* x )
{
  struct zx_ns_s* pop_seen = 0;
  struct zx_elem_s* se MAYBE_UNUSED;
#if 1 /* NORMALMODE */
  int len = 1 + sizeof("Primary")-1 + 1 + 2 + sizeof("Primary")-1 + 1;
  
  if (x->gg.g.ns && x->gg.g.ns->prefix_len)
    len += (x->gg.g.ns->prefix_len + 1) * 2;
  if (c->inc_ns_len)
    len += zx_len_inc_ns(c, &pop_seen);
  len += zx_len_xmlns_if_not_seen(c, x->gg.g.ns, &pop_seen);


#else
  /* root node has no begin tag */
  int len = 0;
#endif
  


  len += zx_len_wo_common(c, &x->gg); 
  zx_pop_seen(pop_seen);
  ENC_LEN_DEBUG(x, "wst:Primary", len);
  return len;
}

/* FUNC(zx_ENC_SO_wst_Primary) */

/* Render element into string. The XML attributes and elements are
 * processed in schema order. This is what you generally want for
 * rendering new data structure to a string. The wo pointers are not used. */

/* Called by: */
char* zx_ENC_SO_wst_Primary(struct zx_ctx* c, struct zx_wst_Primary_s* x, char* p )
{
  struct zx_elem_s* se MAYBE_UNUSED;
  ENC_LEN_DEBUG_BASE;
#if 1 /* NORMALMODE */
  struct zx_ns_s* pop_seen = 0;
  /* *** in simple_elem case should output ns prefix from ns node. */
  ZX_OUT_TAG(p, "<wst:Primary");
  if (c->inc_ns)
    p = zx_enc_inc_ns(c, p, &pop_seen);
  p = zx_enc_xmlns_if_not_seen(c, p, zx_ns_tab+zx_xmlns_ix_wst, &pop_seen);


  p = zx_enc_unknown_attrs(p, x->gg.any_attr);
#else
  /* root node has no begin tag */
#endif
  

  p = zx_enc_so_unknown_elems_and_content(c, p, &x->gg);
  
#if 1 /* NORMALMODE */
  ZX_OUT_CLOSE_TAG(p, "</wst:Primary>");
  zx_pop_seen(pop_seen);
#else
  /* root node has no end tag either */
#endif
  ENC_LEN_DEBUG(x, "wst:Primary", p-enc_base);
  return p;
}

/* FUNC(zx_ENC_WO_wst_Primary) */

/* Render element into string. The XML attributes and elements are
 * processed in wire order by chasing wo pointers. This is what you want for
 * validating signatures on other people's XML documents. */

/* Called by: */
char* zx_ENC_WO_wst_Primary(struct zx_ctx* c, struct zx_wst_Primary_s* x, char* p )
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
  ZX_OUT_MEM(p, "Primary", sizeof("Primary")-1);
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
  ENC_LEN_DEBUG(x, "wst:Primary", p-enc_base);
  return p;
}

/* FUNC(zx_EASY_ENC_SO_wst_Primary) */

/* Called by: */
struct zx_str* zx_EASY_ENC_SO_wst_Primary(struct zx_ctx* c, struct zx_wst_Primary_s* x )
{
  int len;
  char* buf;
  c->ns_tab = ZX_ALLOC(c, sizeof(zx_ns_tab));
  memcpy(c->ns_tab, zx_ns_tab, sizeof(zx_ns_tab));
  len = zx_LEN_SO_wst_Primary(c, x );
  buf = ZX_ALLOC(c, len+1);
  return zx_easy_enc_common(c, zx_ENC_SO_wst_Primary(c, x, buf ), buf, len);
}

/* FUNC(zx_EASY_ENC_WO_wst_Primary) */

/* Called by: */
struct zx_str* zx_EASY_ENC_WO_wst_Primary(struct zx_ctx* c, struct zx_wst_Primary_s* x )
{
  int len;
  char* buf;
  c->ns_tab = ZX_ALLOC(c, sizeof(zx_ns_tab));
  memcpy(c->ns_tab, zx_ns_tab, sizeof(zx_ns_tab));
  len = zx_LEN_WO_wst_Primary(c, x );
  buf = ZX_ALLOC(c, len+1);
  return zx_easy_enc_common(c, zx_ENC_WO_wst_Primary(c, x, buf ), buf, len);
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

#define EL_NAME   wst_ProofEncryption
#define EL_STRUCT zx_wst_ProofEncryption_s
#define EL_NS     wst
#define EL_TAG    ProofEncryption

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

/* FUNC(zx_LEN_SO_wst_ProofEncryption) */

/* Compute length of an element (and its subelements). The XML attributes
 * and elements are processed in schema order. */

/* Called by: */
int zx_LEN_SO_wst_ProofEncryption(struct zx_ctx* c, struct zx_wst_ProofEncryption_s* x )
{
  struct zx_ns_s* pop_seen = 0;
  struct zx_elem_s* se MAYBE_UNUSED;
#if 1 /* NORMALMODE */
  /* *** in simple_elem case should output ns prefix from ns node. */
  int len = sizeof("<wst:ProofEncryption")-1 + 1 + sizeof("</wst:ProofEncryption>")-1;
  if (c->inc_ns_len)
    len += zx_len_inc_ns(c, &pop_seen);
  len += zx_len_xmlns_if_not_seen(c, zx_ns_tab+zx_xmlns_ix_wst, &pop_seen);


#else
  /* root node has no begin tag */
  int len = 0;
#endif
  


  len += zx_len_so_common(c, &x->gg);
  zx_pop_seen(pop_seen);
  ENC_LEN_DEBUG(x, "wst:ProofEncryption", len);
  return len;
}

/* FUNC(zx_LEN_WO_wst_ProofEncryption) */

/* Compute length of an element (and its subelements). The XML attributes
 * and elements are processed in wire order and no assumptions
 * are made about namespace prefixes. */

/* Called by: */
int zx_LEN_WO_wst_ProofEncryption(struct zx_ctx* c, struct zx_wst_ProofEncryption_s* x )
{
  struct zx_ns_s* pop_seen = 0;
  struct zx_elem_s* se MAYBE_UNUSED;
#if 1 /* NORMALMODE */
  int len = 1 + sizeof("ProofEncryption")-1 + 1 + 2 + sizeof("ProofEncryption")-1 + 1;
  
  if (x->gg.g.ns && x->gg.g.ns->prefix_len)
    len += (x->gg.g.ns->prefix_len + 1) * 2;
  if (c->inc_ns_len)
    len += zx_len_inc_ns(c, &pop_seen);
  len += zx_len_xmlns_if_not_seen(c, x->gg.g.ns, &pop_seen);


#else
  /* root node has no begin tag */
  int len = 0;
#endif
  


  len += zx_len_wo_common(c, &x->gg); 
  zx_pop_seen(pop_seen);
  ENC_LEN_DEBUG(x, "wst:ProofEncryption", len);
  return len;
}

/* FUNC(zx_ENC_SO_wst_ProofEncryption) */

/* Render element into string. The XML attributes and elements are
 * processed in schema order. This is what you generally want for
 * rendering new data structure to a string. The wo pointers are not used. */

/* Called by: */
char* zx_ENC_SO_wst_ProofEncryption(struct zx_ctx* c, struct zx_wst_ProofEncryption_s* x, char* p )
{
  struct zx_elem_s* se MAYBE_UNUSED;
  ENC_LEN_DEBUG_BASE;
#if 1 /* NORMALMODE */
  struct zx_ns_s* pop_seen = 0;
  /* *** in simple_elem case should output ns prefix from ns node. */
  ZX_OUT_TAG(p, "<wst:ProofEncryption");
  if (c->inc_ns)
    p = zx_enc_inc_ns(c, p, &pop_seen);
  p = zx_enc_xmlns_if_not_seen(c, p, zx_ns_tab+zx_xmlns_ix_wst, &pop_seen);


  p = zx_enc_unknown_attrs(p, x->gg.any_attr);
#else
  /* root node has no begin tag */
#endif
  

  p = zx_enc_so_unknown_elems_and_content(c, p, &x->gg);
  
#if 1 /* NORMALMODE */
  ZX_OUT_CLOSE_TAG(p, "</wst:ProofEncryption>");
  zx_pop_seen(pop_seen);
#else
  /* root node has no end tag either */
#endif
  ENC_LEN_DEBUG(x, "wst:ProofEncryption", p-enc_base);
  return p;
}

/* FUNC(zx_ENC_WO_wst_ProofEncryption) */

/* Render element into string. The XML attributes and elements are
 * processed in wire order by chasing wo pointers. This is what you want for
 * validating signatures on other people's XML documents. */

/* Called by: */
char* zx_ENC_WO_wst_ProofEncryption(struct zx_ctx* c, struct zx_wst_ProofEncryption_s* x, char* p )
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
  ZX_OUT_MEM(p, "ProofEncryption", sizeof("ProofEncryption")-1);
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
  ENC_LEN_DEBUG(x, "wst:ProofEncryption", p-enc_base);
  return p;
}

/* FUNC(zx_EASY_ENC_SO_wst_ProofEncryption) */

/* Called by: */
struct zx_str* zx_EASY_ENC_SO_wst_ProofEncryption(struct zx_ctx* c, struct zx_wst_ProofEncryption_s* x )
{
  int len;
  char* buf;
  c->ns_tab = ZX_ALLOC(c, sizeof(zx_ns_tab));
  memcpy(c->ns_tab, zx_ns_tab, sizeof(zx_ns_tab));
  len = zx_LEN_SO_wst_ProofEncryption(c, x );
  buf = ZX_ALLOC(c, len+1);
  return zx_easy_enc_common(c, zx_ENC_SO_wst_ProofEncryption(c, x, buf ), buf, len);
}

/* FUNC(zx_EASY_ENC_WO_wst_ProofEncryption) */

/* Called by: */
struct zx_str* zx_EASY_ENC_WO_wst_ProofEncryption(struct zx_ctx* c, struct zx_wst_ProofEncryption_s* x )
{
  int len;
  char* buf;
  c->ns_tab = ZX_ALLOC(c, sizeof(zx_ns_tab));
  memcpy(c->ns_tab, zx_ns_tab, sizeof(zx_ns_tab));
  len = zx_LEN_WO_wst_ProofEncryption(c, x );
  buf = ZX_ALLOC(c, len+1);
  return zx_easy_enc_common(c, zx_ENC_WO_wst_ProofEncryption(c, x, buf ), buf, len);
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

#define EL_NAME   wst_RenewTarget
#define EL_STRUCT zx_wst_RenewTarget_s
#define EL_NS     wst
#define EL_TAG    RenewTarget

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

/* FUNC(zx_LEN_SO_wst_RenewTarget) */

/* Compute length of an element (and its subelements). The XML attributes
 * and elements are processed in schema order. */

/* Called by: */
int zx_LEN_SO_wst_RenewTarget(struct zx_ctx* c, struct zx_wst_RenewTarget_s* x )
{
  struct zx_ns_s* pop_seen = 0;
  struct zx_elem_s* se MAYBE_UNUSED;
#if 1 /* NORMALMODE */
  /* *** in simple_elem case should output ns prefix from ns node. */
  int len = sizeof("<wst:RenewTarget")-1 + 1 + sizeof("</wst:RenewTarget>")-1;
  if (c->inc_ns_len)
    len += zx_len_inc_ns(c, &pop_seen);
  len += zx_len_xmlns_if_not_seen(c, zx_ns_tab+zx_xmlns_ix_wst, &pop_seen);


#else
  /* root node has no begin tag */
  int len = 0;
#endif
  


  len += zx_len_so_common(c, &x->gg);
  zx_pop_seen(pop_seen);
  ENC_LEN_DEBUG(x, "wst:RenewTarget", len);
  return len;
}

/* FUNC(zx_LEN_WO_wst_RenewTarget) */

/* Compute length of an element (and its subelements). The XML attributes
 * and elements are processed in wire order and no assumptions
 * are made about namespace prefixes. */

/* Called by: */
int zx_LEN_WO_wst_RenewTarget(struct zx_ctx* c, struct zx_wst_RenewTarget_s* x )
{
  struct zx_ns_s* pop_seen = 0;
  struct zx_elem_s* se MAYBE_UNUSED;
#if 1 /* NORMALMODE */
  int len = 1 + sizeof("RenewTarget")-1 + 1 + 2 + sizeof("RenewTarget")-1 + 1;
  
  if (x->gg.g.ns && x->gg.g.ns->prefix_len)
    len += (x->gg.g.ns->prefix_len + 1) * 2;
  if (c->inc_ns_len)
    len += zx_len_inc_ns(c, &pop_seen);
  len += zx_len_xmlns_if_not_seen(c, x->gg.g.ns, &pop_seen);


#else
  /* root node has no begin tag */
  int len = 0;
#endif
  


  len += zx_len_wo_common(c, &x->gg); 
  zx_pop_seen(pop_seen);
  ENC_LEN_DEBUG(x, "wst:RenewTarget", len);
  return len;
}

/* FUNC(zx_ENC_SO_wst_RenewTarget) */

/* Render element into string. The XML attributes and elements are
 * processed in schema order. This is what you generally want for
 * rendering new data structure to a string. The wo pointers are not used. */

/* Called by: */
char* zx_ENC_SO_wst_RenewTarget(struct zx_ctx* c, struct zx_wst_RenewTarget_s* x, char* p )
{
  struct zx_elem_s* se MAYBE_UNUSED;
  ENC_LEN_DEBUG_BASE;
#if 1 /* NORMALMODE */
  struct zx_ns_s* pop_seen = 0;
  /* *** in simple_elem case should output ns prefix from ns node. */
  ZX_OUT_TAG(p, "<wst:RenewTarget");
  if (c->inc_ns)
    p = zx_enc_inc_ns(c, p, &pop_seen);
  p = zx_enc_xmlns_if_not_seen(c, p, zx_ns_tab+zx_xmlns_ix_wst, &pop_seen);


  p = zx_enc_unknown_attrs(p, x->gg.any_attr);
#else
  /* root node has no begin tag */
#endif
  

  p = zx_enc_so_unknown_elems_and_content(c, p, &x->gg);
  
#if 1 /* NORMALMODE */
  ZX_OUT_CLOSE_TAG(p, "</wst:RenewTarget>");
  zx_pop_seen(pop_seen);
#else
  /* root node has no end tag either */
#endif
  ENC_LEN_DEBUG(x, "wst:RenewTarget", p-enc_base);
  return p;
}

/* FUNC(zx_ENC_WO_wst_RenewTarget) */

/* Render element into string. The XML attributes and elements are
 * processed in wire order by chasing wo pointers. This is what you want for
 * validating signatures on other people's XML documents. */

/* Called by: */
char* zx_ENC_WO_wst_RenewTarget(struct zx_ctx* c, struct zx_wst_RenewTarget_s* x, char* p )
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
  ZX_OUT_MEM(p, "RenewTarget", sizeof("RenewTarget")-1);
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
  ENC_LEN_DEBUG(x, "wst:RenewTarget", p-enc_base);
  return p;
}

/* FUNC(zx_EASY_ENC_SO_wst_RenewTarget) */

/* Called by: */
struct zx_str* zx_EASY_ENC_SO_wst_RenewTarget(struct zx_ctx* c, struct zx_wst_RenewTarget_s* x )
{
  int len;
  char* buf;
  c->ns_tab = ZX_ALLOC(c, sizeof(zx_ns_tab));
  memcpy(c->ns_tab, zx_ns_tab, sizeof(zx_ns_tab));
  len = zx_LEN_SO_wst_RenewTarget(c, x );
  buf = ZX_ALLOC(c, len+1);
  return zx_easy_enc_common(c, zx_ENC_SO_wst_RenewTarget(c, x, buf ), buf, len);
}

/* FUNC(zx_EASY_ENC_WO_wst_RenewTarget) */

/* Called by: */
struct zx_str* zx_EASY_ENC_WO_wst_RenewTarget(struct zx_ctx* c, struct zx_wst_RenewTarget_s* x )
{
  int len;
  char* buf;
  c->ns_tab = ZX_ALLOC(c, sizeof(zx_ns_tab));
  memcpy(c->ns_tab, zx_ns_tab, sizeof(zx_ns_tab));
  len = zx_LEN_WO_wst_RenewTarget(c, x );
  buf = ZX_ALLOC(c, len+1);
  return zx_easy_enc_common(c, zx_ENC_WO_wst_RenewTarget(c, x, buf ), buf, len);
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

#define EL_NAME   wst_Renewing
#define EL_STRUCT zx_wst_Renewing_s
#define EL_NS     wst
#define EL_TAG    Renewing

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

/* FUNC(zx_LEN_SO_wst_Renewing) */

/* Compute length of an element (and its subelements). The XML attributes
 * and elements are processed in schema order. */

/* Called by: */
int zx_LEN_SO_wst_Renewing(struct zx_ctx* c, struct zx_wst_Renewing_s* x )
{
  struct zx_ns_s* pop_seen = 0;
  struct zx_elem_s* se MAYBE_UNUSED;
#if 1 /* NORMALMODE */
  /* *** in simple_elem case should output ns prefix from ns node. */
  int len = sizeof("<wst:Renewing")-1 + 1 + sizeof("</wst:Renewing>")-1;
  if (c->inc_ns_len)
    len += zx_len_inc_ns(c, &pop_seen);
  len += zx_len_xmlns_if_not_seen(c, zx_ns_tab+zx_xmlns_ix_wst, &pop_seen);

  len += zx_attr_so_len(x->Allow, sizeof("Allow")-1);
  len += zx_attr_so_len(x->OK, sizeof("OK")-1);

#else
  /* root node has no begin tag */
  int len = 0;
#endif
  


  len += zx_len_so_common(c, &x->gg);
  zx_pop_seen(pop_seen);
  ENC_LEN_DEBUG(x, "wst:Renewing", len);
  return len;
}

/* FUNC(zx_LEN_WO_wst_Renewing) */

/* Compute length of an element (and its subelements). The XML attributes
 * and elements are processed in wire order and no assumptions
 * are made about namespace prefixes. */

/* Called by: */
int zx_LEN_WO_wst_Renewing(struct zx_ctx* c, struct zx_wst_Renewing_s* x )
{
  struct zx_ns_s* pop_seen = 0;
  struct zx_elem_s* se MAYBE_UNUSED;
#if 1 /* NORMALMODE */
  int len = 1 + sizeof("Renewing")-1 + 1 + 2 + sizeof("Renewing")-1 + 1;
  
  if (x->gg.g.ns && x->gg.g.ns->prefix_len)
    len += (x->gg.g.ns->prefix_len + 1) * 2;
  if (c->inc_ns_len)
    len += zx_len_inc_ns(c, &pop_seen);
  len += zx_len_xmlns_if_not_seen(c, x->gg.g.ns, &pop_seen);

  len += zx_attr_wo_len(x->Allow, sizeof("Allow")-1);
  len += zx_attr_wo_len(x->OK, sizeof("OK")-1);

#else
  /* root node has no begin tag */
  int len = 0;
#endif
  


  len += zx_len_wo_common(c, &x->gg); 
  zx_pop_seen(pop_seen);
  ENC_LEN_DEBUG(x, "wst:Renewing", len);
  return len;
}

/* FUNC(zx_ENC_SO_wst_Renewing) */

/* Render element into string. The XML attributes and elements are
 * processed in schema order. This is what you generally want for
 * rendering new data structure to a string. The wo pointers are not used. */

/* Called by: */
char* zx_ENC_SO_wst_Renewing(struct zx_ctx* c, struct zx_wst_Renewing_s* x, char* p )
{
  struct zx_elem_s* se MAYBE_UNUSED;
  ENC_LEN_DEBUG_BASE;
#if 1 /* NORMALMODE */
  struct zx_ns_s* pop_seen = 0;
  /* *** in simple_elem case should output ns prefix from ns node. */
  ZX_OUT_TAG(p, "<wst:Renewing");
  if (c->inc_ns)
    p = zx_enc_inc_ns(c, p, &pop_seen);
  p = zx_enc_xmlns_if_not_seen(c, p, zx_ns_tab+zx_xmlns_ix_wst, &pop_seen);

  p = zx_attr_so_enc(p, x->Allow, " Allow=\"", sizeof(" Allow=\"")-1);
  p = zx_attr_so_enc(p, x->OK, " OK=\"", sizeof(" OK=\"")-1);

  p = zx_enc_unknown_attrs(p, x->gg.any_attr);
#else
  /* root node has no begin tag */
#endif
  

  p = zx_enc_so_unknown_elems_and_content(c, p, &x->gg);
  
#if 1 /* NORMALMODE */
  ZX_OUT_CLOSE_TAG(p, "</wst:Renewing>");
  zx_pop_seen(pop_seen);
#else
  /* root node has no end tag either */
#endif
  ENC_LEN_DEBUG(x, "wst:Renewing", p-enc_base);
  return p;
}

/* FUNC(zx_ENC_WO_wst_Renewing) */

/* Render element into string. The XML attributes and elements are
 * processed in wire order by chasing wo pointers. This is what you want for
 * validating signatures on other people's XML documents. */

/* Called by: */
char* zx_ENC_WO_wst_Renewing(struct zx_ctx* c, struct zx_wst_Renewing_s* x, char* p )
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
  ZX_OUT_MEM(p, "Renewing", sizeof("Renewing")-1);
  qq = p;

  /* *** sort the namespaces */
  if (c->inc_ns)
    zx_add_inc_ns(c, &pop_seen);
  zx_add_xmlns_if_not_seen(c, x->gg.g.ns, &pop_seen);

  p = zx_enc_seen(p, pop_seen); 
  p = zx_attr_wo_enc(p, x->Allow, "Allow=\"", sizeof("Allow=\"")-1);
  p = zx_attr_wo_enc(p, x->OK, "OK=\"", sizeof("OK=\"")-1);

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
  ENC_LEN_DEBUG(x, "wst:Renewing", p-enc_base);
  return p;
}

/* FUNC(zx_EASY_ENC_SO_wst_Renewing) */

/* Called by: */
struct zx_str* zx_EASY_ENC_SO_wst_Renewing(struct zx_ctx* c, struct zx_wst_Renewing_s* x )
{
  int len;
  char* buf;
  c->ns_tab = ZX_ALLOC(c, sizeof(zx_ns_tab));
  memcpy(c->ns_tab, zx_ns_tab, sizeof(zx_ns_tab));
  len = zx_LEN_SO_wst_Renewing(c, x );
  buf = ZX_ALLOC(c, len+1);
  return zx_easy_enc_common(c, zx_ENC_SO_wst_Renewing(c, x, buf ), buf, len);
}

/* FUNC(zx_EASY_ENC_WO_wst_Renewing) */

/* Called by: */
struct zx_str* zx_EASY_ENC_WO_wst_Renewing(struct zx_ctx* c, struct zx_wst_Renewing_s* x )
{
  int len;
  char* buf;
  c->ns_tab = ZX_ALLOC(c, sizeof(zx_ns_tab));
  memcpy(c->ns_tab, zx_ns_tab, sizeof(zx_ns_tab));
  len = zx_LEN_WO_wst_Renewing(c, x );
  buf = ZX_ALLOC(c, len+1);
  return zx_easy_enc_common(c, zx_ENC_WO_wst_Renewing(c, x, buf ), buf, len);
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

#define EL_NAME   wst_RequestSecurityToken
#define EL_STRUCT zx_wst_RequestSecurityToken_s
#define EL_NS     wst
#define EL_TAG    RequestSecurityToken

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

/* FUNC(zx_LEN_SO_wst_RequestSecurityToken) */

/* Compute length of an element (and its subelements). The XML attributes
 * and elements are processed in schema order. */

/* Called by: */
int zx_LEN_SO_wst_RequestSecurityToken(struct zx_ctx* c, struct zx_wst_RequestSecurityToken_s* x )
{
  struct zx_ns_s* pop_seen = 0;
  struct zx_elem_s* se MAYBE_UNUSED;
#if 1 /* NORMALMODE */
  /* *** in simple_elem case should output ns prefix from ns node. */
  int len = sizeof("<wst:RequestSecurityToken")-1 + 1 + sizeof("</wst:RequestSecurityToken>")-1;
  if (c->inc_ns_len)
    len += zx_len_inc_ns(c, &pop_seen);
  len += zx_len_xmlns_if_not_seen(c, zx_ns_tab+zx_xmlns_ix_wst, &pop_seen);

  len += zx_attr_so_len(x->Context, sizeof("Context")-1);

#else
  /* root node has no begin tag */
  int len = 0;
#endif
  
  for (se = x->TokenType; se; se = (struct zx_elem_s*)se->g.n)
    len += zx_LEN_SO_simple_elem(c,se, sizeof("wst:TokenType")-1, zx_ns_tab+zx_xmlns_ix_wst);
  for (se = x->RequestType; se; se = (struct zx_elem_s*)se->g.n)
    len += zx_LEN_SO_simple_elem(c,se, sizeof("wst:RequestType")-1, zx_ns_tab+zx_xmlns_ix_wst);
  {
      struct zx_wsp_AppliesTo_s* e;
      for (e = x->AppliesTo; e; e = (struct zx_wsp_AppliesTo_s*)e->gg.g.n)
	  len += zx_LEN_SO_wsp_AppliesTo(c, e);
  }
  {
      struct zx_wst_Claims_s* e;
      for (e = x->Claims; e; e = (struct zx_wst_Claims_s*)e->gg.g.n)
	  len += zx_LEN_SO_wst_Claims(c, e);
  }
  {
      struct zx_wst_Entropy_s* e;
      for (e = x->Entropy; e; e = (struct zx_wst_Entropy_s*)e->gg.g.n)
	  len += zx_LEN_SO_wst_Entropy(c, e);
  }
  {
      struct zx_wst_Lifetime_s* e;
      for (e = x->Lifetime; e; e = (struct zx_wst_Lifetime_s*)e->gg.g.n)
	  len += zx_LEN_SO_wst_Lifetime(c, e);
  }
  for (se = x->AllowPostdating; se; se = (struct zx_elem_s*)se->g.n)
    len += zx_LEN_SO_simple_elem(c,se, sizeof("wst:AllowPostdating")-1, zx_ns_tab+zx_xmlns_ix_wst);
  {
      struct zx_wst_Renewing_s* e;
      for (e = x->Renewing; e; e = (struct zx_wst_Renewing_s*)e->gg.g.n)
	  len += zx_LEN_SO_wst_Renewing(c, e);
  }
  {
      struct zx_wst_OnBehalfOf_s* e;
      for (e = x->OnBehalfOf; e; e = (struct zx_wst_OnBehalfOf_s*)e->gg.g.n)
	  len += zx_LEN_SO_wst_OnBehalfOf(c, e);
  }
  {
      struct zx_wst_Issuer_s* e;
      for (e = x->Issuer; e; e = (struct zx_wst_Issuer_s*)e->gg.g.n)
	  len += zx_LEN_SO_wst_Issuer(c, e);
  }
  for (se = x->AuthenticationType; se; se = (struct zx_elem_s*)se->g.n)
    len += zx_LEN_SO_simple_elem(c,se, sizeof("wst:AuthenticationType")-1, zx_ns_tab+zx_xmlns_ix_wst);
  for (se = x->KeyType; se; se = (struct zx_elem_s*)se->g.n)
    len += zx_LEN_SO_simple_elem(c,se, sizeof("wst:KeyType")-1, zx_ns_tab+zx_xmlns_ix_wst);
  for (se = x->KeySize; se; se = (struct zx_elem_s*)se->g.n)
    len += zx_LEN_SO_simple_elem(c,se, sizeof("wst:KeySize")-1, zx_ns_tab+zx_xmlns_ix_wst);
  for (se = x->SignatureAlgorithm; se; se = (struct zx_elem_s*)se->g.n)
    len += zx_LEN_SO_simple_elem(c,se, sizeof("wst:SignatureAlgorithm")-1, zx_ns_tab+zx_xmlns_ix_wst);
  {
      struct zx_wst_Encryption_s* e;
      for (e = x->Encryption; e; e = (struct zx_wst_Encryption_s*)e->gg.g.n)
	  len += zx_LEN_SO_wst_Encryption(c, e);
  }
  for (se = x->EncryptionAlgorithm; se; se = (struct zx_elem_s*)se->g.n)
    len += zx_LEN_SO_simple_elem(c,se, sizeof("wst:EncryptionAlgorithm")-1, zx_ns_tab+zx_xmlns_ix_wst);
  for (se = x->CanonicalizationAlgorithm; se; se = (struct zx_elem_s*)se->g.n)
    len += zx_LEN_SO_simple_elem(c,se, sizeof("wst:CanonicalizationAlgorithm")-1, zx_ns_tab+zx_xmlns_ix_wst);
  {
      struct zx_wst_ProofEncryption_s* e;
      for (e = x->ProofEncryption; e; e = (struct zx_wst_ProofEncryption_s*)e->gg.g.n)
	  len += zx_LEN_SO_wst_ProofEncryption(c, e);
  }
  {
      struct zx_wst_UseKey_s* e;
      for (e = x->UseKey; e; e = (struct zx_wst_UseKey_s*)e->gg.g.n)
	  len += zx_LEN_SO_wst_UseKey(c, e);
  }
  for (se = x->SignWith; se; se = (struct zx_elem_s*)se->g.n)
    len += zx_LEN_SO_simple_elem(c,se, sizeof("wst:SignWith")-1, zx_ns_tab+zx_xmlns_ix_wst);
  for (se = x->EncryptWith; se; se = (struct zx_elem_s*)se->g.n)
    len += zx_LEN_SO_simple_elem(c,se, sizeof("wst:EncryptWith")-1, zx_ns_tab+zx_xmlns_ix_wst);
  {
      struct zx_wst_DelegateTo_s* e;
      for (e = x->DelegateTo; e; e = (struct zx_wst_DelegateTo_s*)e->gg.g.n)
	  len += zx_LEN_SO_wst_DelegateTo(c, e);
  }
  for (se = x->Forwardable; se; se = (struct zx_elem_s*)se->g.n)
    len += zx_LEN_SO_simple_elem(c,se, sizeof("wst:Forwardable")-1, zx_ns_tab+zx_xmlns_ix_wst);
  for (se = x->Delegatable; se; se = (struct zx_elem_s*)se->g.n)
    len += zx_LEN_SO_simple_elem(c,se, sizeof("wst:Delegatable")-1, zx_ns_tab+zx_xmlns_ix_wst);
  {
      struct zx_wsp_Policy_s* e;
      for (e = x->Policy; e; e = (struct zx_wsp_Policy_s*)e->gg.g.n)
	  len += zx_LEN_SO_wsp_Policy(c, e);
  }
  {
      struct zx_wsp_PolicyReference_s* e;
      for (e = x->PolicyReference; e; e = (struct zx_wsp_PolicyReference_s*)e->gg.g.n)
	  len += zx_LEN_SO_wsp_PolicyReference(c, e);
  }


  len += zx_len_so_common(c, &x->gg);
  zx_pop_seen(pop_seen);
  ENC_LEN_DEBUG(x, "wst:RequestSecurityToken", len);
  return len;
}

/* FUNC(zx_LEN_WO_wst_RequestSecurityToken) */

/* Compute length of an element (and its subelements). The XML attributes
 * and elements are processed in wire order and no assumptions
 * are made about namespace prefixes. */

/* Called by: */
int zx_LEN_WO_wst_RequestSecurityToken(struct zx_ctx* c, struct zx_wst_RequestSecurityToken_s* x )
{
  struct zx_ns_s* pop_seen = 0;
  struct zx_elem_s* se MAYBE_UNUSED;
#if 1 /* NORMALMODE */
  int len = 1 + sizeof("RequestSecurityToken")-1 + 1 + 2 + sizeof("RequestSecurityToken")-1 + 1;
  
  if (x->gg.g.ns && x->gg.g.ns->prefix_len)
    len += (x->gg.g.ns->prefix_len + 1) * 2;
  if (c->inc_ns_len)
    len += zx_len_inc_ns(c, &pop_seen);
  len += zx_len_xmlns_if_not_seen(c, x->gg.g.ns, &pop_seen);

  len += zx_attr_wo_len(x->Context, sizeof("Context")-1);

#else
  /* root node has no begin tag */
  int len = 0;
#endif
  
  for (se = x->TokenType; se; se = (struct zx_elem_s*)se->g.n)
    len += zx_LEN_WO_simple_elem(c, se, sizeof("TokenType")-1);
  for (se = x->RequestType; se; se = (struct zx_elem_s*)se->g.n)
    len += zx_LEN_WO_simple_elem(c, se, sizeof("RequestType")-1);
  {
      struct zx_wsp_AppliesTo_s* e;
      for (e = x->AppliesTo; e; e = (struct zx_wsp_AppliesTo_s*)e->gg.g.n)
	  len += zx_LEN_WO_wsp_AppliesTo(c, e);
  }
  {
      struct zx_wst_Claims_s* e;
      for (e = x->Claims; e; e = (struct zx_wst_Claims_s*)e->gg.g.n)
	  len += zx_LEN_WO_wst_Claims(c, e);
  }
  {
      struct zx_wst_Entropy_s* e;
      for (e = x->Entropy; e; e = (struct zx_wst_Entropy_s*)e->gg.g.n)
	  len += zx_LEN_WO_wst_Entropy(c, e);
  }
  {
      struct zx_wst_Lifetime_s* e;
      for (e = x->Lifetime; e; e = (struct zx_wst_Lifetime_s*)e->gg.g.n)
	  len += zx_LEN_WO_wst_Lifetime(c, e);
  }
  for (se = x->AllowPostdating; se; se = (struct zx_elem_s*)se->g.n)
    len += zx_LEN_WO_simple_elem(c, se, sizeof("AllowPostdating")-1);
  {
      struct zx_wst_Renewing_s* e;
      for (e = x->Renewing; e; e = (struct zx_wst_Renewing_s*)e->gg.g.n)
	  len += zx_LEN_WO_wst_Renewing(c, e);
  }
  {
      struct zx_wst_OnBehalfOf_s* e;
      for (e = x->OnBehalfOf; e; e = (struct zx_wst_OnBehalfOf_s*)e->gg.g.n)
	  len += zx_LEN_WO_wst_OnBehalfOf(c, e);
  }
  {
      struct zx_wst_Issuer_s* e;
      for (e = x->Issuer; e; e = (struct zx_wst_Issuer_s*)e->gg.g.n)
	  len += zx_LEN_WO_wst_Issuer(c, e);
  }
  for (se = x->AuthenticationType; se; se = (struct zx_elem_s*)se->g.n)
    len += zx_LEN_WO_simple_elem(c, se, sizeof("AuthenticationType")-1);
  for (se = x->KeyType; se; se = (struct zx_elem_s*)se->g.n)
    len += zx_LEN_WO_simple_elem(c, se, sizeof("KeyType")-1);
  for (se = x->KeySize; se; se = (struct zx_elem_s*)se->g.n)
    len += zx_LEN_WO_simple_elem(c, se, sizeof("KeySize")-1);
  for (se = x->SignatureAlgorithm; se; se = (struct zx_elem_s*)se->g.n)
    len += zx_LEN_WO_simple_elem(c, se, sizeof("SignatureAlgorithm")-1);
  {
      struct zx_wst_Encryption_s* e;
      for (e = x->Encryption; e; e = (struct zx_wst_Encryption_s*)e->gg.g.n)
	  len += zx_LEN_WO_wst_Encryption(c, e);
  }
  for (se = x->EncryptionAlgorithm; se; se = (struct zx_elem_s*)se->g.n)
    len += zx_LEN_WO_simple_elem(c, se, sizeof("EncryptionAlgorithm")-1);
  for (se = x->CanonicalizationAlgorithm; se; se = (struct zx_elem_s*)se->g.n)
    len += zx_LEN_WO_simple_elem(c, se, sizeof("CanonicalizationAlgorithm")-1);
  {
      struct zx_wst_ProofEncryption_s* e;
      for (e = x->ProofEncryption; e; e = (struct zx_wst_ProofEncryption_s*)e->gg.g.n)
	  len += zx_LEN_WO_wst_ProofEncryption(c, e);
  }
  {
      struct zx_wst_UseKey_s* e;
      for (e = x->UseKey; e; e = (struct zx_wst_UseKey_s*)e->gg.g.n)
	  len += zx_LEN_WO_wst_UseKey(c, e);
  }
  for (se = x->SignWith; se; se = (struct zx_elem_s*)se->g.n)
    len += zx_LEN_WO_simple_elem(c, se, sizeof("SignWith")-1);
  for (se = x->EncryptWith; se; se = (struct zx_elem_s*)se->g.n)
    len += zx_LEN_WO_simple_elem(c, se, sizeof("EncryptWith")-1);
  {
      struct zx_wst_DelegateTo_s* e;
      for (e = x->DelegateTo; e; e = (struct zx_wst_DelegateTo_s*)e->gg.g.n)
	  len += zx_LEN_WO_wst_DelegateTo(c, e);
  }
  for (se = x->Forwardable; se; se = (struct zx_elem_s*)se->g.n)
    len += zx_LEN_WO_simple_elem(c, se, sizeof("Forwardable")-1);
  for (se = x->Delegatable; se; se = (struct zx_elem_s*)se->g.n)
    len += zx_LEN_WO_simple_elem(c, se, sizeof("Delegatable")-1);
  {
      struct zx_wsp_Policy_s* e;
      for (e = x->Policy; e; e = (struct zx_wsp_Policy_s*)e->gg.g.n)
	  len += zx_LEN_WO_wsp_Policy(c, e);
  }
  {
      struct zx_wsp_PolicyReference_s* e;
      for (e = x->PolicyReference; e; e = (struct zx_wsp_PolicyReference_s*)e->gg.g.n)
	  len += zx_LEN_WO_wsp_PolicyReference(c, e);
  }


  len += zx_len_wo_common(c, &x->gg); 
  zx_pop_seen(pop_seen);
  ENC_LEN_DEBUG(x, "wst:RequestSecurityToken", len);
  return len;
}

/* FUNC(zx_ENC_SO_wst_RequestSecurityToken) */

/* Render element into string. The XML attributes and elements are
 * processed in schema order. This is what you generally want for
 * rendering new data structure to a string. The wo pointers are not used. */

/* Called by: */
char* zx_ENC_SO_wst_RequestSecurityToken(struct zx_ctx* c, struct zx_wst_RequestSecurityToken_s* x, char* p )
{
  struct zx_elem_s* se MAYBE_UNUSED;
  ENC_LEN_DEBUG_BASE;
#if 1 /* NORMALMODE */
  struct zx_ns_s* pop_seen = 0;
  /* *** in simple_elem case should output ns prefix from ns node. */
  ZX_OUT_TAG(p, "<wst:RequestSecurityToken");
  if (c->inc_ns)
    p = zx_enc_inc_ns(c, p, &pop_seen);
  p = zx_enc_xmlns_if_not_seen(c, p, zx_ns_tab+zx_xmlns_ix_wst, &pop_seen);

  p = zx_attr_so_enc(p, x->Context, " Context=\"", sizeof(" Context=\"")-1);

  p = zx_enc_unknown_attrs(p, x->gg.any_attr);
#else
  /* root node has no begin tag */
#endif
  
  for (se = x->TokenType; se; se = (struct zx_elem_s*)se->g.n)
    p = zx_ENC_SO_simple_elem(c, se, p, "wst:TokenType", sizeof("wst:TokenType")-1, zx_ns_tab+zx_xmlns_ix_wst);
  for (se = x->RequestType; se; se = (struct zx_elem_s*)se->g.n)
    p = zx_ENC_SO_simple_elem(c, se, p, "wst:RequestType", sizeof("wst:RequestType")-1, zx_ns_tab+zx_xmlns_ix_wst);
  {
      struct zx_wsp_AppliesTo_s* e;
      for (e = x->AppliesTo; e; e = (struct zx_wsp_AppliesTo_s*)e->gg.g.n)
	  p = zx_ENC_SO_wsp_AppliesTo(c, e, p);
  }
  {
      struct zx_wst_Claims_s* e;
      for (e = x->Claims; e; e = (struct zx_wst_Claims_s*)e->gg.g.n)
	  p = zx_ENC_SO_wst_Claims(c, e, p);
  }
  {
      struct zx_wst_Entropy_s* e;
      for (e = x->Entropy; e; e = (struct zx_wst_Entropy_s*)e->gg.g.n)
	  p = zx_ENC_SO_wst_Entropy(c, e, p);
  }
  {
      struct zx_wst_Lifetime_s* e;
      for (e = x->Lifetime; e; e = (struct zx_wst_Lifetime_s*)e->gg.g.n)
	  p = zx_ENC_SO_wst_Lifetime(c, e, p);
  }
  for (se = x->AllowPostdating; se; se = (struct zx_elem_s*)se->g.n)
    p = zx_ENC_SO_simple_elem(c, se, p, "wst:AllowPostdating", sizeof("wst:AllowPostdating")-1, zx_ns_tab+zx_xmlns_ix_wst);
  {
      struct zx_wst_Renewing_s* e;
      for (e = x->Renewing; e; e = (struct zx_wst_Renewing_s*)e->gg.g.n)
	  p = zx_ENC_SO_wst_Renewing(c, e, p);
  }
  {
      struct zx_wst_OnBehalfOf_s* e;
      for (e = x->OnBehalfOf; e; e = (struct zx_wst_OnBehalfOf_s*)e->gg.g.n)
	  p = zx_ENC_SO_wst_OnBehalfOf(c, e, p);
  }
  {
      struct zx_wst_Issuer_s* e;
      for (e = x->Issuer; e; e = (struct zx_wst_Issuer_s*)e->gg.g.n)
	  p = zx_ENC_SO_wst_Issuer(c, e, p);
  }
  for (se = x->AuthenticationType; se; se = (struct zx_elem_s*)se->g.n)
    p = zx_ENC_SO_simple_elem(c, se, p, "wst:AuthenticationType", sizeof("wst:AuthenticationType")-1, zx_ns_tab+zx_xmlns_ix_wst);
  for (se = x->KeyType; se; se = (struct zx_elem_s*)se->g.n)
    p = zx_ENC_SO_simple_elem(c, se, p, "wst:KeyType", sizeof("wst:KeyType")-1, zx_ns_tab+zx_xmlns_ix_wst);
  for (se = x->KeySize; se; se = (struct zx_elem_s*)se->g.n)
    p = zx_ENC_SO_simple_elem(c, se, p, "wst:KeySize", sizeof("wst:KeySize")-1, zx_ns_tab+zx_xmlns_ix_wst);
  for (se = x->SignatureAlgorithm; se; se = (struct zx_elem_s*)se->g.n)
    p = zx_ENC_SO_simple_elem(c, se, p, "wst:SignatureAlgorithm", sizeof("wst:SignatureAlgorithm")-1, zx_ns_tab+zx_xmlns_ix_wst);
  {
      struct zx_wst_Encryption_s* e;
      for (e = x->Encryption; e; e = (struct zx_wst_Encryption_s*)e->gg.g.n)
	  p = zx_ENC_SO_wst_Encryption(c, e, p);
  }
  for (se = x->EncryptionAlgorithm; se; se = (struct zx_elem_s*)se->g.n)
    p = zx_ENC_SO_simple_elem(c, se, p, "wst:EncryptionAlgorithm", sizeof("wst:EncryptionAlgorithm")-1, zx_ns_tab+zx_xmlns_ix_wst);
  for (se = x->CanonicalizationAlgorithm; se; se = (struct zx_elem_s*)se->g.n)
    p = zx_ENC_SO_simple_elem(c, se, p, "wst:CanonicalizationAlgorithm", sizeof("wst:CanonicalizationAlgorithm")-1, zx_ns_tab+zx_xmlns_ix_wst);
  {
      struct zx_wst_ProofEncryption_s* e;
      for (e = x->ProofEncryption; e; e = (struct zx_wst_ProofEncryption_s*)e->gg.g.n)
	  p = zx_ENC_SO_wst_ProofEncryption(c, e, p);
  }
  {
      struct zx_wst_UseKey_s* e;
      for (e = x->UseKey; e; e = (struct zx_wst_UseKey_s*)e->gg.g.n)
	  p = zx_ENC_SO_wst_UseKey(c, e, p);
  }
  for (se = x->SignWith; se; se = (struct zx_elem_s*)se->g.n)
    p = zx_ENC_SO_simple_elem(c, se, p, "wst:SignWith", sizeof("wst:SignWith")-1, zx_ns_tab+zx_xmlns_ix_wst);
  for (se = x->EncryptWith; se; se = (struct zx_elem_s*)se->g.n)
    p = zx_ENC_SO_simple_elem(c, se, p, "wst:EncryptWith", sizeof("wst:EncryptWith")-1, zx_ns_tab+zx_xmlns_ix_wst);
  {
      struct zx_wst_DelegateTo_s* e;
      for (e = x->DelegateTo; e; e = (struct zx_wst_DelegateTo_s*)e->gg.g.n)
	  p = zx_ENC_SO_wst_DelegateTo(c, e, p);
  }
  for (se = x->Forwardable; se; se = (struct zx_elem_s*)se->g.n)
    p = zx_ENC_SO_simple_elem(c, se, p, "wst:Forwardable", sizeof("wst:Forwardable")-1, zx_ns_tab+zx_xmlns_ix_wst);
  for (se = x->Delegatable; se; se = (struct zx_elem_s*)se->g.n)
    p = zx_ENC_SO_simple_elem(c, se, p, "wst:Delegatable", sizeof("wst:Delegatable")-1, zx_ns_tab+zx_xmlns_ix_wst);
  {
      struct zx_wsp_Policy_s* e;
      for (e = x->Policy; e; e = (struct zx_wsp_Policy_s*)e->gg.g.n)
	  p = zx_ENC_SO_wsp_Policy(c, e, p);
  }
  {
      struct zx_wsp_PolicyReference_s* e;
      for (e = x->PolicyReference; e; e = (struct zx_wsp_PolicyReference_s*)e->gg.g.n)
	  p = zx_ENC_SO_wsp_PolicyReference(c, e, p);
  }

  p = zx_enc_so_unknown_elems_and_content(c, p, &x->gg);
  
#if 1 /* NORMALMODE */
  ZX_OUT_CLOSE_TAG(p, "</wst:RequestSecurityToken>");
  zx_pop_seen(pop_seen);
#else
  /* root node has no end tag either */
#endif
  ENC_LEN_DEBUG(x, "wst:RequestSecurityToken", p-enc_base);
  return p;
}

/* FUNC(zx_ENC_WO_wst_RequestSecurityToken) */

/* Render element into string. The XML attributes and elements are
 * processed in wire order by chasing wo pointers. This is what you want for
 * validating signatures on other people's XML documents. */

/* Called by: */
char* zx_ENC_WO_wst_RequestSecurityToken(struct zx_ctx* c, struct zx_wst_RequestSecurityToken_s* x, char* p )
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
  ZX_OUT_MEM(p, "RequestSecurityToken", sizeof("RequestSecurityToken")-1);
  qq = p;

  /* *** sort the namespaces */
  if (c->inc_ns)
    zx_add_inc_ns(c, &pop_seen);
  zx_add_xmlns_if_not_seen(c, x->gg.g.ns, &pop_seen);

  p = zx_enc_seen(p, pop_seen); 
  p = zx_attr_wo_enc(p, x->Context, "Context=\"", sizeof("Context=\"")-1);

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
  ENC_LEN_DEBUG(x, "wst:RequestSecurityToken", p-enc_base);
  return p;
}

/* FUNC(zx_EASY_ENC_SO_wst_RequestSecurityToken) */

/* Called by: */
struct zx_str* zx_EASY_ENC_SO_wst_RequestSecurityToken(struct zx_ctx* c, struct zx_wst_RequestSecurityToken_s* x )
{
  int len;
  char* buf;
  c->ns_tab = ZX_ALLOC(c, sizeof(zx_ns_tab));
  memcpy(c->ns_tab, zx_ns_tab, sizeof(zx_ns_tab));
  len = zx_LEN_SO_wst_RequestSecurityToken(c, x );
  buf = ZX_ALLOC(c, len+1);
  return zx_easy_enc_common(c, zx_ENC_SO_wst_RequestSecurityToken(c, x, buf ), buf, len);
}

/* FUNC(zx_EASY_ENC_WO_wst_RequestSecurityToken) */

/* Called by: */
struct zx_str* zx_EASY_ENC_WO_wst_RequestSecurityToken(struct zx_ctx* c, struct zx_wst_RequestSecurityToken_s* x )
{
  int len;
  char* buf;
  c->ns_tab = ZX_ALLOC(c, sizeof(zx_ns_tab));
  memcpy(c->ns_tab, zx_ns_tab, sizeof(zx_ns_tab));
  len = zx_LEN_WO_wst_RequestSecurityToken(c, x );
  buf = ZX_ALLOC(c, len+1);
  return zx_easy_enc_common(c, zx_ENC_WO_wst_RequestSecurityToken(c, x, buf ), buf, len);
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

#define EL_NAME   wst_RequestSecurityTokenCollection
#define EL_STRUCT zx_wst_RequestSecurityTokenCollection_s
#define EL_NS     wst
#define EL_TAG    RequestSecurityTokenCollection

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

/* FUNC(zx_LEN_SO_wst_RequestSecurityTokenCollection) */

/* Compute length of an element (and its subelements). The XML attributes
 * and elements are processed in schema order. */

/* Called by: */
int zx_LEN_SO_wst_RequestSecurityTokenCollection(struct zx_ctx* c, struct zx_wst_RequestSecurityTokenCollection_s* x )
{
  struct zx_ns_s* pop_seen = 0;
  struct zx_elem_s* se MAYBE_UNUSED;
#if 1 /* NORMALMODE */
  /* *** in simple_elem case should output ns prefix from ns node. */
  int len = sizeof("<wst:RequestSecurityTokenCollection")-1 + 1 + sizeof("</wst:RequestSecurityTokenCollection>")-1;
  if (c->inc_ns_len)
    len += zx_len_inc_ns(c, &pop_seen);
  len += zx_len_xmlns_if_not_seen(c, zx_ns_tab+zx_xmlns_ix_wst, &pop_seen);


#else
  /* root node has no begin tag */
  int len = 0;
#endif
  
  {
      struct zx_wst_RequestSecurityToken_s* e;
      for (e = x->RequestSecurityToken; e; e = (struct zx_wst_RequestSecurityToken_s*)e->gg.g.n)
	  len += zx_LEN_SO_wst_RequestSecurityToken(c, e);
  }


  len += zx_len_so_common(c, &x->gg);
  zx_pop_seen(pop_seen);
  ENC_LEN_DEBUG(x, "wst:RequestSecurityTokenCollection", len);
  return len;
}

/* FUNC(zx_LEN_WO_wst_RequestSecurityTokenCollection) */

/* Compute length of an element (and its subelements). The XML attributes
 * and elements are processed in wire order and no assumptions
 * are made about namespace prefixes. */

/* Called by: */
int zx_LEN_WO_wst_RequestSecurityTokenCollection(struct zx_ctx* c, struct zx_wst_RequestSecurityTokenCollection_s* x )
{
  struct zx_ns_s* pop_seen = 0;
  struct zx_elem_s* se MAYBE_UNUSED;
#if 1 /* NORMALMODE */
  int len = 1 + sizeof("RequestSecurityTokenCollection")-1 + 1 + 2 + sizeof("RequestSecurityTokenCollection")-1 + 1;
  
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
      struct zx_wst_RequestSecurityToken_s* e;
      for (e = x->RequestSecurityToken; e; e = (struct zx_wst_RequestSecurityToken_s*)e->gg.g.n)
	  len += zx_LEN_WO_wst_RequestSecurityToken(c, e);
  }


  len += zx_len_wo_common(c, &x->gg); 
  zx_pop_seen(pop_seen);
  ENC_LEN_DEBUG(x, "wst:RequestSecurityTokenCollection", len);
  return len;
}

/* FUNC(zx_ENC_SO_wst_RequestSecurityTokenCollection) */

/* Render element into string. The XML attributes and elements are
 * processed in schema order. This is what you generally want for
 * rendering new data structure to a string. The wo pointers are not used. */

/* Called by: */
char* zx_ENC_SO_wst_RequestSecurityTokenCollection(struct zx_ctx* c, struct zx_wst_RequestSecurityTokenCollection_s* x, char* p )
{
  struct zx_elem_s* se MAYBE_UNUSED;
  ENC_LEN_DEBUG_BASE;
#if 1 /* NORMALMODE */
  struct zx_ns_s* pop_seen = 0;
  /* *** in simple_elem case should output ns prefix from ns node. */
  ZX_OUT_TAG(p, "<wst:RequestSecurityTokenCollection");
  if (c->inc_ns)
    p = zx_enc_inc_ns(c, p, &pop_seen);
  p = zx_enc_xmlns_if_not_seen(c, p, zx_ns_tab+zx_xmlns_ix_wst, &pop_seen);


  p = zx_enc_unknown_attrs(p, x->gg.any_attr);
#else
  /* root node has no begin tag */
#endif
  
  {
      struct zx_wst_RequestSecurityToken_s* e;
      for (e = x->RequestSecurityToken; e; e = (struct zx_wst_RequestSecurityToken_s*)e->gg.g.n)
	  p = zx_ENC_SO_wst_RequestSecurityToken(c, e, p);
  }

  p = zx_enc_so_unknown_elems_and_content(c, p, &x->gg);
  
#if 1 /* NORMALMODE */
  ZX_OUT_CLOSE_TAG(p, "</wst:RequestSecurityTokenCollection>");
  zx_pop_seen(pop_seen);
#else
  /* root node has no end tag either */
#endif
  ENC_LEN_DEBUG(x, "wst:RequestSecurityTokenCollection", p-enc_base);
  return p;
}

/* FUNC(zx_ENC_WO_wst_RequestSecurityTokenCollection) */

/* Render element into string. The XML attributes and elements are
 * processed in wire order by chasing wo pointers. This is what you want for
 * validating signatures on other people's XML documents. */

/* Called by: */
char* zx_ENC_WO_wst_RequestSecurityTokenCollection(struct zx_ctx* c, struct zx_wst_RequestSecurityTokenCollection_s* x, char* p )
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
  ZX_OUT_MEM(p, "RequestSecurityTokenCollection", sizeof("RequestSecurityTokenCollection")-1);
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
  ENC_LEN_DEBUG(x, "wst:RequestSecurityTokenCollection", p-enc_base);
  return p;
}

/* FUNC(zx_EASY_ENC_SO_wst_RequestSecurityTokenCollection) */

/* Called by: */
struct zx_str* zx_EASY_ENC_SO_wst_RequestSecurityTokenCollection(struct zx_ctx* c, struct zx_wst_RequestSecurityTokenCollection_s* x )
{
  int len;
  char* buf;
  c->ns_tab = ZX_ALLOC(c, sizeof(zx_ns_tab));
  memcpy(c->ns_tab, zx_ns_tab, sizeof(zx_ns_tab));
  len = zx_LEN_SO_wst_RequestSecurityTokenCollection(c, x );
  buf = ZX_ALLOC(c, len+1);
  return zx_easy_enc_common(c, zx_ENC_SO_wst_RequestSecurityTokenCollection(c, x, buf ), buf, len);
}

/* FUNC(zx_EASY_ENC_WO_wst_RequestSecurityTokenCollection) */

/* Called by: */
struct zx_str* zx_EASY_ENC_WO_wst_RequestSecurityTokenCollection(struct zx_ctx* c, struct zx_wst_RequestSecurityTokenCollection_s* x )
{
  int len;
  char* buf;
  c->ns_tab = ZX_ALLOC(c, sizeof(zx_ns_tab));
  memcpy(c->ns_tab, zx_ns_tab, sizeof(zx_ns_tab));
  len = zx_LEN_WO_wst_RequestSecurityTokenCollection(c, x );
  buf = ZX_ALLOC(c, len+1);
  return zx_easy_enc_common(c, zx_ENC_WO_wst_RequestSecurityTokenCollection(c, x, buf ), buf, len);
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

#define EL_NAME   wst_RequestSecurityTokenResponse
#define EL_STRUCT zx_wst_RequestSecurityTokenResponse_s
#define EL_NS     wst
#define EL_TAG    RequestSecurityTokenResponse

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

/* FUNC(zx_LEN_SO_wst_RequestSecurityTokenResponse) */

/* Compute length of an element (and its subelements). The XML attributes
 * and elements are processed in schema order. */

/* Called by: */
int zx_LEN_SO_wst_RequestSecurityTokenResponse(struct zx_ctx* c, struct zx_wst_RequestSecurityTokenResponse_s* x )
{
  struct zx_ns_s* pop_seen = 0;
  struct zx_elem_s* se MAYBE_UNUSED;
#if 1 /* NORMALMODE */
  /* *** in simple_elem case should output ns prefix from ns node. */
  int len = sizeof("<wst:RequestSecurityTokenResponse")-1 + 1 + sizeof("</wst:RequestSecurityTokenResponse>")-1;
  if (c->inc_ns_len)
    len += zx_len_inc_ns(c, &pop_seen);
  len += zx_len_xmlns_if_not_seen(c, zx_ns_tab+zx_xmlns_ix_wst, &pop_seen);

  len += zx_attr_so_len(x->Context, sizeof("Context")-1);

#else
  /* root node has no begin tag */
  int len = 0;
#endif
  
  for (se = x->TokenType; se; se = (struct zx_elem_s*)se->g.n)
    len += zx_LEN_SO_simple_elem(c,se, sizeof("wst:TokenType")-1, zx_ns_tab+zx_xmlns_ix_wst);
  for (se = x->RequestType; se; se = (struct zx_elem_s*)se->g.n)
    len += zx_LEN_SO_simple_elem(c,se, sizeof("wst:RequestType")-1, zx_ns_tab+zx_xmlns_ix_wst);
  {
      struct zx_wst_RequestedSecurityToken_s* e;
      for (e = x->RequestedSecurityToken; e; e = (struct zx_wst_RequestedSecurityToken_s*)e->gg.g.n)
	  len += zx_LEN_SO_wst_RequestedSecurityToken(c, e);
  }
  {
      struct zx_wsp_AppliesTo_s* e;
      for (e = x->AppliesTo; e; e = (struct zx_wsp_AppliesTo_s*)e->gg.g.n)
	  len += zx_LEN_SO_wsp_AppliesTo(c, e);
  }
  {
      struct zx_wst_RequestedAttachedReference_s* e;
      for (e = x->RequestedAttachedReference; e; e = (struct zx_wst_RequestedAttachedReference_s*)e->gg.g.n)
	  len += zx_LEN_SO_wst_RequestedAttachedReference(c, e);
  }
  {
      struct zx_wst_RequestedUnattachedReference_s* e;
      for (e = x->RequestedUnattachedReference; e; e = (struct zx_wst_RequestedUnattachedReference_s*)e->gg.g.n)
	  len += zx_LEN_SO_wst_RequestedUnattachedReference(c, e);
  }
  {
      struct zx_wst_RequestedProofToken_s* e;
      for (e = x->RequestedProofToken; e; e = (struct zx_wst_RequestedProofToken_s*)e->gg.g.n)
	  len += zx_LEN_SO_wst_RequestedProofToken(c, e);
  }
  {
      struct zx_wst_Entropy_s* e;
      for (e = x->Entropy; e; e = (struct zx_wst_Entropy_s*)e->gg.g.n)
	  len += zx_LEN_SO_wst_Entropy(c, e);
  }
  {
      struct zx_wst_Lifetime_s* e;
      for (e = x->Lifetime; e; e = (struct zx_wst_Lifetime_s*)e->gg.g.n)
	  len += zx_LEN_SO_wst_Lifetime(c, e);
  }
  {
      struct zx_wst_Status_s* e;
      for (e = x->Status; e; e = (struct zx_wst_Status_s*)e->gg.g.n)
	  len += zx_LEN_SO_wst_Status(c, e);
  }
  for (se = x->AllowPostdating; se; se = (struct zx_elem_s*)se->g.n)
    len += zx_LEN_SO_simple_elem(c,se, sizeof("wst:AllowPostdating")-1, zx_ns_tab+zx_xmlns_ix_wst);
  {
      struct zx_wst_Renewing_s* e;
      for (e = x->Renewing; e; e = (struct zx_wst_Renewing_s*)e->gg.g.n)
	  len += zx_LEN_SO_wst_Renewing(c, e);
  }
  {
      struct zx_wst_OnBehalfOf_s* e;
      for (e = x->OnBehalfOf; e; e = (struct zx_wst_OnBehalfOf_s*)e->gg.g.n)
	  len += zx_LEN_SO_wst_OnBehalfOf(c, e);
  }
  {
      struct zx_wst_Issuer_s* e;
      for (e = x->Issuer; e; e = (struct zx_wst_Issuer_s*)e->gg.g.n)
	  len += zx_LEN_SO_wst_Issuer(c, e);
  }
  for (se = x->AuthenticationType; se; se = (struct zx_elem_s*)se->g.n)
    len += zx_LEN_SO_simple_elem(c,se, sizeof("wst:AuthenticationType")-1, zx_ns_tab+zx_xmlns_ix_wst);
  {
      struct zx_wst_Authenticator_s* e;
      for (e = x->Authenticator; e; e = (struct zx_wst_Authenticator_s*)e->gg.g.n)
	  len += zx_LEN_SO_wst_Authenticator(c, e);
  }
  for (se = x->KeyType; se; se = (struct zx_elem_s*)se->g.n)
    len += zx_LEN_SO_simple_elem(c,se, sizeof("wst:KeyType")-1, zx_ns_tab+zx_xmlns_ix_wst);
  for (se = x->KeySize; se; se = (struct zx_elem_s*)se->g.n)
    len += zx_LEN_SO_simple_elem(c,se, sizeof("wst:KeySize")-1, zx_ns_tab+zx_xmlns_ix_wst);
  for (se = x->SignatureAlgorithm; se; se = (struct zx_elem_s*)se->g.n)
    len += zx_LEN_SO_simple_elem(c,se, sizeof("wst:SignatureAlgorithm")-1, zx_ns_tab+zx_xmlns_ix_wst);
  {
      struct zx_wst_Encryption_s* e;
      for (e = x->Encryption; e; e = (struct zx_wst_Encryption_s*)e->gg.g.n)
	  len += zx_LEN_SO_wst_Encryption(c, e);
  }
  for (se = x->EncryptionAlgorithm; se; se = (struct zx_elem_s*)se->g.n)
    len += zx_LEN_SO_simple_elem(c,se, sizeof("wst:EncryptionAlgorithm")-1, zx_ns_tab+zx_xmlns_ix_wst);
  for (se = x->CanonicalizationAlgorithm; se; se = (struct zx_elem_s*)se->g.n)
    len += zx_LEN_SO_simple_elem(c,se, sizeof("wst:CanonicalizationAlgorithm")-1, zx_ns_tab+zx_xmlns_ix_wst);
  {
      struct zx_wst_ProofEncryption_s* e;
      for (e = x->ProofEncryption; e; e = (struct zx_wst_ProofEncryption_s*)e->gg.g.n)
	  len += zx_LEN_SO_wst_ProofEncryption(c, e);
  }
  {
      struct zx_wst_UseKey_s* e;
      for (e = x->UseKey; e; e = (struct zx_wst_UseKey_s*)e->gg.g.n)
	  len += zx_LEN_SO_wst_UseKey(c, e);
  }
  for (se = x->SignWith; se; se = (struct zx_elem_s*)se->g.n)
    len += zx_LEN_SO_simple_elem(c,se, sizeof("wst:SignWith")-1, zx_ns_tab+zx_xmlns_ix_wst);
  for (se = x->EncryptWith; se; se = (struct zx_elem_s*)se->g.n)
    len += zx_LEN_SO_simple_elem(c,se, sizeof("wst:EncryptWith")-1, zx_ns_tab+zx_xmlns_ix_wst);
  {
      struct zx_wst_DelegateTo_s* e;
      for (e = x->DelegateTo; e; e = (struct zx_wst_DelegateTo_s*)e->gg.g.n)
	  len += zx_LEN_SO_wst_DelegateTo(c, e);
  }
  for (se = x->Forwardable; se; se = (struct zx_elem_s*)se->g.n)
    len += zx_LEN_SO_simple_elem(c,se, sizeof("wst:Forwardable")-1, zx_ns_tab+zx_xmlns_ix_wst);
  for (se = x->Delegatable; se; se = (struct zx_elem_s*)se->g.n)
    len += zx_LEN_SO_simple_elem(c,se, sizeof("wst:Delegatable")-1, zx_ns_tab+zx_xmlns_ix_wst);
  {
      struct zx_wsp_Policy_s* e;
      for (e = x->Policy; e; e = (struct zx_wsp_Policy_s*)e->gg.g.n)
	  len += zx_LEN_SO_wsp_Policy(c, e);
  }
  {
      struct zx_wsp_PolicyReference_s* e;
      for (e = x->PolicyReference; e; e = (struct zx_wsp_PolicyReference_s*)e->gg.g.n)
	  len += zx_LEN_SO_wsp_PolicyReference(c, e);
  }


  len += zx_len_so_common(c, &x->gg);
  zx_pop_seen(pop_seen);
  ENC_LEN_DEBUG(x, "wst:RequestSecurityTokenResponse", len);
  return len;
}

/* FUNC(zx_LEN_WO_wst_RequestSecurityTokenResponse) */

/* Compute length of an element (and its subelements). The XML attributes
 * and elements are processed in wire order and no assumptions
 * are made about namespace prefixes. */

/* Called by: */
int zx_LEN_WO_wst_RequestSecurityTokenResponse(struct zx_ctx* c, struct zx_wst_RequestSecurityTokenResponse_s* x )
{
  struct zx_ns_s* pop_seen = 0;
  struct zx_elem_s* se MAYBE_UNUSED;
#if 1 /* NORMALMODE */
  int len = 1 + sizeof("RequestSecurityTokenResponse")-1 + 1 + 2 + sizeof("RequestSecurityTokenResponse")-1 + 1;
  
  if (x->gg.g.ns && x->gg.g.ns->prefix_len)
    len += (x->gg.g.ns->prefix_len + 1) * 2;
  if (c->inc_ns_len)
    len += zx_len_inc_ns(c, &pop_seen);
  len += zx_len_xmlns_if_not_seen(c, x->gg.g.ns, &pop_seen);

  len += zx_attr_wo_len(x->Context, sizeof("Context")-1);

#else
  /* root node has no begin tag */
  int len = 0;
#endif
  
  for (se = x->TokenType; se; se = (struct zx_elem_s*)se->g.n)
    len += zx_LEN_WO_simple_elem(c, se, sizeof("TokenType")-1);
  for (se = x->RequestType; se; se = (struct zx_elem_s*)se->g.n)
    len += zx_LEN_WO_simple_elem(c, se, sizeof("RequestType")-1);
  {
      struct zx_wst_RequestedSecurityToken_s* e;
      for (e = x->RequestedSecurityToken; e; e = (struct zx_wst_RequestedSecurityToken_s*)e->gg.g.n)
	  len += zx_LEN_WO_wst_RequestedSecurityToken(c, e);
  }
  {
      struct zx_wsp_AppliesTo_s* e;
      for (e = x->AppliesTo; e; e = (struct zx_wsp_AppliesTo_s*)e->gg.g.n)
	  len += zx_LEN_WO_wsp_AppliesTo(c, e);
  }
  {
      struct zx_wst_RequestedAttachedReference_s* e;
      for (e = x->RequestedAttachedReference; e; e = (struct zx_wst_RequestedAttachedReference_s*)e->gg.g.n)
	  len += zx_LEN_WO_wst_RequestedAttachedReference(c, e);
  }
  {
      struct zx_wst_RequestedUnattachedReference_s* e;
      for (e = x->RequestedUnattachedReference; e; e = (struct zx_wst_RequestedUnattachedReference_s*)e->gg.g.n)
	  len += zx_LEN_WO_wst_RequestedUnattachedReference(c, e);
  }
  {
      struct zx_wst_RequestedProofToken_s* e;
      for (e = x->RequestedProofToken; e; e = (struct zx_wst_RequestedProofToken_s*)e->gg.g.n)
	  len += zx_LEN_WO_wst_RequestedProofToken(c, e);
  }
  {
      struct zx_wst_Entropy_s* e;
      for (e = x->Entropy; e; e = (struct zx_wst_Entropy_s*)e->gg.g.n)
	  len += zx_LEN_WO_wst_Entropy(c, e);
  }
  {
      struct zx_wst_Lifetime_s* e;
      for (e = x->Lifetime; e; e = (struct zx_wst_Lifetime_s*)e->gg.g.n)
	  len += zx_LEN_WO_wst_Lifetime(c, e);
  }
  {
      struct zx_wst_Status_s* e;
      for (e = x->Status; e; e = (struct zx_wst_Status_s*)e->gg.g.n)
	  len += zx_LEN_WO_wst_Status(c, e);
  }
  for (se = x->AllowPostdating; se; se = (struct zx_elem_s*)se->g.n)
    len += zx_LEN_WO_simple_elem(c, se, sizeof("AllowPostdating")-1);
  {
      struct zx_wst_Renewing_s* e;
      for (e = x->Renewing; e; e = (struct zx_wst_Renewing_s*)e->gg.g.n)
	  len += zx_LEN_WO_wst_Renewing(c, e);
  }
  {
      struct zx_wst_OnBehalfOf_s* e;
      for (e = x->OnBehalfOf; e; e = (struct zx_wst_OnBehalfOf_s*)e->gg.g.n)
	  len += zx_LEN_WO_wst_OnBehalfOf(c, e);
  }
  {
      struct zx_wst_Issuer_s* e;
      for (e = x->Issuer; e; e = (struct zx_wst_Issuer_s*)e->gg.g.n)
	  len += zx_LEN_WO_wst_Issuer(c, e);
  }
  for (se = x->AuthenticationType; se; se = (struct zx_elem_s*)se->g.n)
    len += zx_LEN_WO_simple_elem(c, se, sizeof("AuthenticationType")-1);
  {
      struct zx_wst_Authenticator_s* e;
      for (e = x->Authenticator; e; e = (struct zx_wst_Authenticator_s*)e->gg.g.n)
	  len += zx_LEN_WO_wst_Authenticator(c, e);
  }
  for (se = x->KeyType; se; se = (struct zx_elem_s*)se->g.n)
    len += zx_LEN_WO_simple_elem(c, se, sizeof("KeyType")-1);
  for (se = x->KeySize; se; se = (struct zx_elem_s*)se->g.n)
    len += zx_LEN_WO_simple_elem(c, se, sizeof("KeySize")-1);
  for (se = x->SignatureAlgorithm; se; se = (struct zx_elem_s*)se->g.n)
    len += zx_LEN_WO_simple_elem(c, se, sizeof("SignatureAlgorithm")-1);
  {
      struct zx_wst_Encryption_s* e;
      for (e = x->Encryption; e; e = (struct zx_wst_Encryption_s*)e->gg.g.n)
	  len += zx_LEN_WO_wst_Encryption(c, e);
  }
  for (se = x->EncryptionAlgorithm; se; se = (struct zx_elem_s*)se->g.n)
    len += zx_LEN_WO_simple_elem(c, se, sizeof("EncryptionAlgorithm")-1);
  for (se = x->CanonicalizationAlgorithm; se; se = (struct zx_elem_s*)se->g.n)
    len += zx_LEN_WO_simple_elem(c, se, sizeof("CanonicalizationAlgorithm")-1);
  {
      struct zx_wst_ProofEncryption_s* e;
      for (e = x->ProofEncryption; e; e = (struct zx_wst_ProofEncryption_s*)e->gg.g.n)
	  len += zx_LEN_WO_wst_ProofEncryption(c, e);
  }
  {
      struct zx_wst_UseKey_s* e;
      for (e = x->UseKey; e; e = (struct zx_wst_UseKey_s*)e->gg.g.n)
	  len += zx_LEN_WO_wst_UseKey(c, e);
  }
  for (se = x->SignWith; se; se = (struct zx_elem_s*)se->g.n)
    len += zx_LEN_WO_simple_elem(c, se, sizeof("SignWith")-1);
  for (se = x->EncryptWith; se; se = (struct zx_elem_s*)se->g.n)
    len += zx_LEN_WO_simple_elem(c, se, sizeof("EncryptWith")-1);
  {
      struct zx_wst_DelegateTo_s* e;
      for (e = x->DelegateTo; e; e = (struct zx_wst_DelegateTo_s*)e->gg.g.n)
	  len += zx_LEN_WO_wst_DelegateTo(c, e);
  }
  for (se = x->Forwardable; se; se = (struct zx_elem_s*)se->g.n)
    len += zx_LEN_WO_simple_elem(c, se, sizeof("Forwardable")-1);
  for (se = x->Delegatable; se; se = (struct zx_elem_s*)se->g.n)
    len += zx_LEN_WO_simple_elem(c, se, sizeof("Delegatable")-1);
  {
      struct zx_wsp_Policy_s* e;
      for (e = x->Policy; e; e = (struct zx_wsp_Policy_s*)e->gg.g.n)
	  len += zx_LEN_WO_wsp_Policy(c, e);
  }
  {
      struct zx_wsp_PolicyReference_s* e;
      for (e = x->PolicyReference; e; e = (struct zx_wsp_PolicyReference_s*)e->gg.g.n)
	  len += zx_LEN_WO_wsp_PolicyReference(c, e);
  }


  len += zx_len_wo_common(c, &x->gg); 
  zx_pop_seen(pop_seen);
  ENC_LEN_DEBUG(x, "wst:RequestSecurityTokenResponse", len);
  return len;
}

/* FUNC(zx_ENC_SO_wst_RequestSecurityTokenResponse) */

/* Render element into string. The XML attributes and elements are
 * processed in schema order. This is what you generally want for
 * rendering new data structure to a string. The wo pointers are not used. */

/* Called by: */
char* zx_ENC_SO_wst_RequestSecurityTokenResponse(struct zx_ctx* c, struct zx_wst_RequestSecurityTokenResponse_s* x, char* p )
{
  struct zx_elem_s* se MAYBE_UNUSED;
  ENC_LEN_DEBUG_BASE;
#if 1 /* NORMALMODE */
  struct zx_ns_s* pop_seen = 0;
  /* *** in simple_elem case should output ns prefix from ns node. */
  ZX_OUT_TAG(p, "<wst:RequestSecurityTokenResponse");
  if (c->inc_ns)
    p = zx_enc_inc_ns(c, p, &pop_seen);
  p = zx_enc_xmlns_if_not_seen(c, p, zx_ns_tab+zx_xmlns_ix_wst, &pop_seen);

  p = zx_attr_so_enc(p, x->Context, " Context=\"", sizeof(" Context=\"")-1);

  p = zx_enc_unknown_attrs(p, x->gg.any_attr);
#else
  /* root node has no begin tag */
#endif
  
  for (se = x->TokenType; se; se = (struct zx_elem_s*)se->g.n)
    p = zx_ENC_SO_simple_elem(c, se, p, "wst:TokenType", sizeof("wst:TokenType")-1, zx_ns_tab+zx_xmlns_ix_wst);
  for (se = x->RequestType; se; se = (struct zx_elem_s*)se->g.n)
    p = zx_ENC_SO_simple_elem(c, se, p, "wst:RequestType", sizeof("wst:RequestType")-1, zx_ns_tab+zx_xmlns_ix_wst);
  {
      struct zx_wst_RequestedSecurityToken_s* e;
      for (e = x->RequestedSecurityToken; e; e = (struct zx_wst_RequestedSecurityToken_s*)e->gg.g.n)
	  p = zx_ENC_SO_wst_RequestedSecurityToken(c, e, p);
  }
  {
      struct zx_wsp_AppliesTo_s* e;
      for (e = x->AppliesTo; e; e = (struct zx_wsp_AppliesTo_s*)e->gg.g.n)
	  p = zx_ENC_SO_wsp_AppliesTo(c, e, p);
  }
  {
      struct zx_wst_RequestedAttachedReference_s* e;
      for (e = x->RequestedAttachedReference; e; e = (struct zx_wst_RequestedAttachedReference_s*)e->gg.g.n)
	  p = zx_ENC_SO_wst_RequestedAttachedReference(c, e, p);
  }
  {
      struct zx_wst_RequestedUnattachedReference_s* e;
      for (e = x->RequestedUnattachedReference; e; e = (struct zx_wst_RequestedUnattachedReference_s*)e->gg.g.n)
	  p = zx_ENC_SO_wst_RequestedUnattachedReference(c, e, p);
  }
  {
      struct zx_wst_RequestedProofToken_s* e;
      for (e = x->RequestedProofToken; e; e = (struct zx_wst_RequestedProofToken_s*)e->gg.g.n)
	  p = zx_ENC_SO_wst_RequestedProofToken(c, e, p);
  }
  {
      struct zx_wst_Entropy_s* e;
      for (e = x->Entropy; e; e = (struct zx_wst_Entropy_s*)e->gg.g.n)
	  p = zx_ENC_SO_wst_Entropy(c, e, p);
  }
  {
      struct zx_wst_Lifetime_s* e;
      for (e = x->Lifetime; e; e = (struct zx_wst_Lifetime_s*)e->gg.g.n)
	  p = zx_ENC_SO_wst_Lifetime(c, e, p);
  }
  {
      struct zx_wst_Status_s* e;
      for (e = x->Status; e; e = (struct zx_wst_Status_s*)e->gg.g.n)
	  p = zx_ENC_SO_wst_Status(c, e, p);
  }
  for (se = x->AllowPostdating; se; se = (struct zx_elem_s*)se->g.n)
    p = zx_ENC_SO_simple_elem(c, se, p, "wst:AllowPostdating", sizeof("wst:AllowPostdating")-1, zx_ns_tab+zx_xmlns_ix_wst);
  {
      struct zx_wst_Renewing_s* e;
      for (e = x->Renewing; e; e = (struct zx_wst_Renewing_s*)e->gg.g.n)
	  p = zx_ENC_SO_wst_Renewing(c, e, p);
  }
  {
      struct zx_wst_OnBehalfOf_s* e;
      for (e = x->OnBehalfOf; e; e = (struct zx_wst_OnBehalfOf_s*)e->gg.g.n)
	  p = zx_ENC_SO_wst_OnBehalfOf(c, e, p);
  }
  {
      struct zx_wst_Issuer_s* e;
      for (e = x->Issuer; e; e = (struct zx_wst_Issuer_s*)e->gg.g.n)
	  p = zx_ENC_SO_wst_Issuer(c, e, p);
  }
  for (se = x->AuthenticationType; se; se = (struct zx_elem_s*)se->g.n)
    p = zx_ENC_SO_simple_elem(c, se, p, "wst:AuthenticationType", sizeof("wst:AuthenticationType")-1, zx_ns_tab+zx_xmlns_ix_wst);
  {
      struct zx_wst_Authenticator_s* e;
      for (e = x->Authenticator; e; e = (struct zx_wst_Authenticator_s*)e->gg.g.n)
	  p = zx_ENC_SO_wst_Authenticator(c, e, p);
  }
  for (se = x->KeyType; se; se = (struct zx_elem_s*)se->g.n)
    p = zx_ENC_SO_simple_elem(c, se, p, "wst:KeyType", sizeof("wst:KeyType")-1, zx_ns_tab+zx_xmlns_ix_wst);
  for (se = x->KeySize; se; se = (struct zx_elem_s*)se->g.n)
    p = zx_ENC_SO_simple_elem(c, se, p, "wst:KeySize", sizeof("wst:KeySize")-1, zx_ns_tab+zx_xmlns_ix_wst);
  for (se = x->SignatureAlgorithm; se; se = (struct zx_elem_s*)se->g.n)
    p = zx_ENC_SO_simple_elem(c, se, p, "wst:SignatureAlgorithm", sizeof("wst:SignatureAlgorithm")-1, zx_ns_tab+zx_xmlns_ix_wst);
  {
      struct zx_wst_Encryption_s* e;
      for (e = x->Encryption; e; e = (struct zx_wst_Encryption_s*)e->gg.g.n)
	  p = zx_ENC_SO_wst_Encryption(c, e, p);
  }
  for (se = x->EncryptionAlgorithm; se; se = (struct zx_elem_s*)se->g.n)
    p = zx_ENC_SO_simple_elem(c, se, p, "wst:EncryptionAlgorithm", sizeof("wst:EncryptionAlgorithm")-1, zx_ns_tab+zx_xmlns_ix_wst);
  for (se = x->CanonicalizationAlgorithm; se; se = (struct zx_elem_s*)se->g.n)
    p = zx_ENC_SO_simple_elem(c, se, p, "wst:CanonicalizationAlgorithm", sizeof("wst:CanonicalizationAlgorithm")-1, zx_ns_tab+zx_xmlns_ix_wst);
  {
      struct zx_wst_ProofEncryption_s* e;
      for (e = x->ProofEncryption; e; e = (struct zx_wst_ProofEncryption_s*)e->gg.g.n)
	  p = zx_ENC_SO_wst_ProofEncryption(c, e, p);
  }
  {
      struct zx_wst_UseKey_s* e;
      for (e = x->UseKey; e; e = (struct zx_wst_UseKey_s*)e->gg.g.n)
	  p = zx_ENC_SO_wst_UseKey(c, e, p);
  }
  for (se = x->SignWith; se; se = (struct zx_elem_s*)se->g.n)
    p = zx_ENC_SO_simple_elem(c, se, p, "wst:SignWith", sizeof("wst:SignWith")-1, zx_ns_tab+zx_xmlns_ix_wst);
  for (se = x->EncryptWith; se; se = (struct zx_elem_s*)se->g.n)
    p = zx_ENC_SO_simple_elem(c, se, p, "wst:EncryptWith", sizeof("wst:EncryptWith")-1, zx_ns_tab+zx_xmlns_ix_wst);
  {
      struct zx_wst_DelegateTo_s* e;
      for (e = x->DelegateTo; e; e = (struct zx_wst_DelegateTo_s*)e->gg.g.n)
	  p = zx_ENC_SO_wst_DelegateTo(c, e, p);
  }
  for (se = x->Forwardable; se; se = (struct zx_elem_s*)se->g.n)
    p = zx_ENC_SO_simple_elem(c, se, p, "wst:Forwardable", sizeof("wst:Forwardable")-1, zx_ns_tab+zx_xmlns_ix_wst);
  for (se = x->Delegatable; se; se = (struct zx_elem_s*)se->g.n)
    p = zx_ENC_SO_simple_elem(c, se, p, "wst:Delegatable", sizeof("wst:Delegatable")-1, zx_ns_tab+zx_xmlns_ix_wst);
  {
      struct zx_wsp_Policy_s* e;
      for (e = x->Policy; e; e = (struct zx_wsp_Policy_s*)e->gg.g.n)
	  p = zx_ENC_SO_wsp_Policy(c, e, p);
  }
  {
      struct zx_wsp_PolicyReference_s* e;
      for (e = x->PolicyReference; e; e = (struct zx_wsp_PolicyReference_s*)e->gg.g.n)
	  p = zx_ENC_SO_wsp_PolicyReference(c, e, p);
  }

  p = zx_enc_so_unknown_elems_and_content(c, p, &x->gg);
  
#if 1 /* NORMALMODE */
  ZX_OUT_CLOSE_TAG(p, "</wst:RequestSecurityTokenResponse>");
  zx_pop_seen(pop_seen);
#else
  /* root node has no end tag either */
#endif
  ENC_LEN_DEBUG(x, "wst:RequestSecurityTokenResponse", p-enc_base);
  return p;
}

/* FUNC(zx_ENC_WO_wst_RequestSecurityTokenResponse) */

/* Render element into string. The XML attributes and elements are
 * processed in wire order by chasing wo pointers. This is what you want for
 * validating signatures on other people's XML documents. */

/* Called by: */
char* zx_ENC_WO_wst_RequestSecurityTokenResponse(struct zx_ctx* c, struct zx_wst_RequestSecurityTokenResponse_s* x, char* p )
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
  ZX_OUT_MEM(p, "RequestSecurityTokenResponse", sizeof("RequestSecurityTokenResponse")-1);
  qq = p;

  /* *** sort the namespaces */
  if (c->inc_ns)
    zx_add_inc_ns(c, &pop_seen);
  zx_add_xmlns_if_not_seen(c, x->gg.g.ns, &pop_seen);

  p = zx_enc_seen(p, pop_seen); 
  p = zx_attr_wo_enc(p, x->Context, "Context=\"", sizeof("Context=\"")-1);

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
  ENC_LEN_DEBUG(x, "wst:RequestSecurityTokenResponse", p-enc_base);
  return p;
}

/* FUNC(zx_EASY_ENC_SO_wst_RequestSecurityTokenResponse) */

/* Called by: */
struct zx_str* zx_EASY_ENC_SO_wst_RequestSecurityTokenResponse(struct zx_ctx* c, struct zx_wst_RequestSecurityTokenResponse_s* x )
{
  int len;
  char* buf;
  c->ns_tab = ZX_ALLOC(c, sizeof(zx_ns_tab));
  memcpy(c->ns_tab, zx_ns_tab, sizeof(zx_ns_tab));
  len = zx_LEN_SO_wst_RequestSecurityTokenResponse(c, x );
  buf = ZX_ALLOC(c, len+1);
  return zx_easy_enc_common(c, zx_ENC_SO_wst_RequestSecurityTokenResponse(c, x, buf ), buf, len);
}

/* FUNC(zx_EASY_ENC_WO_wst_RequestSecurityTokenResponse) */

/* Called by: */
struct zx_str* zx_EASY_ENC_WO_wst_RequestSecurityTokenResponse(struct zx_ctx* c, struct zx_wst_RequestSecurityTokenResponse_s* x )
{
  int len;
  char* buf;
  c->ns_tab = ZX_ALLOC(c, sizeof(zx_ns_tab));
  memcpy(c->ns_tab, zx_ns_tab, sizeof(zx_ns_tab));
  len = zx_LEN_WO_wst_RequestSecurityTokenResponse(c, x );
  buf = ZX_ALLOC(c, len+1);
  return zx_easy_enc_common(c, zx_ENC_WO_wst_RequestSecurityTokenResponse(c, x, buf ), buf, len);
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

#define EL_NAME   wst_RequestSecurityTokenResponseCollection
#define EL_STRUCT zx_wst_RequestSecurityTokenResponseCollection_s
#define EL_NS     wst
#define EL_TAG    RequestSecurityTokenResponseCollection

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

/* FUNC(zx_LEN_SO_wst_RequestSecurityTokenResponseCollection) */

/* Compute length of an element (and its subelements). The XML attributes
 * and elements are processed in schema order. */

/* Called by: */
int zx_LEN_SO_wst_RequestSecurityTokenResponseCollection(struct zx_ctx* c, struct zx_wst_RequestSecurityTokenResponseCollection_s* x )
{
  struct zx_ns_s* pop_seen = 0;
  struct zx_elem_s* se MAYBE_UNUSED;
#if 1 /* NORMALMODE */
  /* *** in simple_elem case should output ns prefix from ns node. */
  int len = sizeof("<wst:RequestSecurityTokenResponseCollection")-1 + 1 + sizeof("</wst:RequestSecurityTokenResponseCollection>")-1;
  if (c->inc_ns_len)
    len += zx_len_inc_ns(c, &pop_seen);
  len += zx_len_xmlns_if_not_seen(c, zx_ns_tab+zx_xmlns_ix_wst, &pop_seen);


#else
  /* root node has no begin tag */
  int len = 0;
#endif
  
  {
      struct zx_wst_RequestSecurityTokenResponse_s* e;
      for (e = x->RequestSecurityTokenResponse; e; e = (struct zx_wst_RequestSecurityTokenResponse_s*)e->gg.g.n)
	  len += zx_LEN_SO_wst_RequestSecurityTokenResponse(c, e);
  }


  len += zx_len_so_common(c, &x->gg);
  zx_pop_seen(pop_seen);
  ENC_LEN_DEBUG(x, "wst:RequestSecurityTokenResponseCollection", len);
  return len;
}

/* FUNC(zx_LEN_WO_wst_RequestSecurityTokenResponseCollection) */

/* Compute length of an element (and its subelements). The XML attributes
 * and elements are processed in wire order and no assumptions
 * are made about namespace prefixes. */

/* Called by: */
int zx_LEN_WO_wst_RequestSecurityTokenResponseCollection(struct zx_ctx* c, struct zx_wst_RequestSecurityTokenResponseCollection_s* x )
{
  struct zx_ns_s* pop_seen = 0;
  struct zx_elem_s* se MAYBE_UNUSED;
#if 1 /* NORMALMODE */
  int len = 1 + sizeof("RequestSecurityTokenResponseCollection")-1 + 1 + 2 + sizeof("RequestSecurityTokenResponseCollection")-1 + 1;
  
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
      struct zx_wst_RequestSecurityTokenResponse_s* e;
      for (e = x->RequestSecurityTokenResponse; e; e = (struct zx_wst_RequestSecurityTokenResponse_s*)e->gg.g.n)
	  len += zx_LEN_WO_wst_RequestSecurityTokenResponse(c, e);
  }


  len += zx_len_wo_common(c, &x->gg); 
  zx_pop_seen(pop_seen);
  ENC_LEN_DEBUG(x, "wst:RequestSecurityTokenResponseCollection", len);
  return len;
}

/* FUNC(zx_ENC_SO_wst_RequestSecurityTokenResponseCollection) */

/* Render element into string. The XML attributes and elements are
 * processed in schema order. This is what you generally want for
 * rendering new data structure to a string. The wo pointers are not used. */

/* Called by: */
char* zx_ENC_SO_wst_RequestSecurityTokenResponseCollection(struct zx_ctx* c, struct zx_wst_RequestSecurityTokenResponseCollection_s* x, char* p )
{
  struct zx_elem_s* se MAYBE_UNUSED;
  ENC_LEN_DEBUG_BASE;
#if 1 /* NORMALMODE */
  struct zx_ns_s* pop_seen = 0;
  /* *** in simple_elem case should output ns prefix from ns node. */
  ZX_OUT_TAG(p, "<wst:RequestSecurityTokenResponseCollection");
  if (c->inc_ns)
    p = zx_enc_inc_ns(c, p, &pop_seen);
  p = zx_enc_xmlns_if_not_seen(c, p, zx_ns_tab+zx_xmlns_ix_wst, &pop_seen);


  p = zx_enc_unknown_attrs(p, x->gg.any_attr);
#else
  /* root node has no begin tag */
#endif
  
  {
      struct zx_wst_RequestSecurityTokenResponse_s* e;
      for (e = x->RequestSecurityTokenResponse; e; e = (struct zx_wst_RequestSecurityTokenResponse_s*)e->gg.g.n)
	  p = zx_ENC_SO_wst_RequestSecurityTokenResponse(c, e, p);
  }

  p = zx_enc_so_unknown_elems_and_content(c, p, &x->gg);
  
#if 1 /* NORMALMODE */
  ZX_OUT_CLOSE_TAG(p, "</wst:RequestSecurityTokenResponseCollection>");
  zx_pop_seen(pop_seen);
#else
  /* root node has no end tag either */
#endif
  ENC_LEN_DEBUG(x, "wst:RequestSecurityTokenResponseCollection", p-enc_base);
  return p;
}

/* FUNC(zx_ENC_WO_wst_RequestSecurityTokenResponseCollection) */

/* Render element into string. The XML attributes and elements are
 * processed in wire order by chasing wo pointers. This is what you want for
 * validating signatures on other people's XML documents. */

/* Called by: */
char* zx_ENC_WO_wst_RequestSecurityTokenResponseCollection(struct zx_ctx* c, struct zx_wst_RequestSecurityTokenResponseCollection_s* x, char* p )
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
  ZX_OUT_MEM(p, "RequestSecurityTokenResponseCollection", sizeof("RequestSecurityTokenResponseCollection")-1);
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
  ENC_LEN_DEBUG(x, "wst:RequestSecurityTokenResponseCollection", p-enc_base);
  return p;
}

/* FUNC(zx_EASY_ENC_SO_wst_RequestSecurityTokenResponseCollection) */

/* Called by: */
struct zx_str* zx_EASY_ENC_SO_wst_RequestSecurityTokenResponseCollection(struct zx_ctx* c, struct zx_wst_RequestSecurityTokenResponseCollection_s* x )
{
  int len;
  char* buf;
  c->ns_tab = ZX_ALLOC(c, sizeof(zx_ns_tab));
  memcpy(c->ns_tab, zx_ns_tab, sizeof(zx_ns_tab));
  len = zx_LEN_SO_wst_RequestSecurityTokenResponseCollection(c, x );
  buf = ZX_ALLOC(c, len+1);
  return zx_easy_enc_common(c, zx_ENC_SO_wst_RequestSecurityTokenResponseCollection(c, x, buf ), buf, len);
}

/* FUNC(zx_EASY_ENC_WO_wst_RequestSecurityTokenResponseCollection) */

/* Called by: */
struct zx_str* zx_EASY_ENC_WO_wst_RequestSecurityTokenResponseCollection(struct zx_ctx* c, struct zx_wst_RequestSecurityTokenResponseCollection_s* x )
{
  int len;
  char* buf;
  c->ns_tab = ZX_ALLOC(c, sizeof(zx_ns_tab));
  memcpy(c->ns_tab, zx_ns_tab, sizeof(zx_ns_tab));
  len = zx_LEN_WO_wst_RequestSecurityTokenResponseCollection(c, x );
  buf = ZX_ALLOC(c, len+1);
  return zx_easy_enc_common(c, zx_ENC_WO_wst_RequestSecurityTokenResponseCollection(c, x, buf ), buf, len);
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

#define EL_NAME   wst_RequestedAttachedReference
#define EL_STRUCT zx_wst_RequestedAttachedReference_s
#define EL_NS     wst
#define EL_TAG    RequestedAttachedReference

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

/* FUNC(zx_LEN_SO_wst_RequestedAttachedReference) */

/* Compute length of an element (and its subelements). The XML attributes
 * and elements are processed in schema order. */

/* Called by: */
int zx_LEN_SO_wst_RequestedAttachedReference(struct zx_ctx* c, struct zx_wst_RequestedAttachedReference_s* x )
{
  struct zx_ns_s* pop_seen = 0;
  struct zx_elem_s* se MAYBE_UNUSED;
#if 1 /* NORMALMODE */
  /* *** in simple_elem case should output ns prefix from ns node. */
  int len = sizeof("<wst:RequestedAttachedReference")-1 + 1 + sizeof("</wst:RequestedAttachedReference>")-1;
  if (c->inc_ns_len)
    len += zx_len_inc_ns(c, &pop_seen);
  len += zx_len_xmlns_if_not_seen(c, zx_ns_tab+zx_xmlns_ix_wst, &pop_seen);


#else
  /* root node has no begin tag */
  int len = 0;
#endif
  
  {
      struct zx_wsse_SecurityTokenReference_s* e;
      for (e = x->SecurityTokenReference; e; e = (struct zx_wsse_SecurityTokenReference_s*)e->gg.g.n)
	  len += zx_LEN_SO_wsse_SecurityTokenReference(c, e);
  }


  len += zx_len_so_common(c, &x->gg);
  zx_pop_seen(pop_seen);
  ENC_LEN_DEBUG(x, "wst:RequestedAttachedReference", len);
  return len;
}

/* FUNC(zx_LEN_WO_wst_RequestedAttachedReference) */

/* Compute length of an element (and its subelements). The XML attributes
 * and elements are processed in wire order and no assumptions
 * are made about namespace prefixes. */

/* Called by: */
int zx_LEN_WO_wst_RequestedAttachedReference(struct zx_ctx* c, struct zx_wst_RequestedAttachedReference_s* x )
{
  struct zx_ns_s* pop_seen = 0;
  struct zx_elem_s* se MAYBE_UNUSED;
#if 1 /* NORMALMODE */
  int len = 1 + sizeof("RequestedAttachedReference")-1 + 1 + 2 + sizeof("RequestedAttachedReference")-1 + 1;
  
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
      struct zx_wsse_SecurityTokenReference_s* e;
      for (e = x->SecurityTokenReference; e; e = (struct zx_wsse_SecurityTokenReference_s*)e->gg.g.n)
	  len += zx_LEN_WO_wsse_SecurityTokenReference(c, e);
  }


  len += zx_len_wo_common(c, &x->gg); 
  zx_pop_seen(pop_seen);
  ENC_LEN_DEBUG(x, "wst:RequestedAttachedReference", len);
  return len;
}

/* FUNC(zx_ENC_SO_wst_RequestedAttachedReference) */

/* Render element into string. The XML attributes and elements are
 * processed in schema order. This is what you generally want for
 * rendering new data structure to a string. The wo pointers are not used. */

/* Called by: */
char* zx_ENC_SO_wst_RequestedAttachedReference(struct zx_ctx* c, struct zx_wst_RequestedAttachedReference_s* x, char* p )
{
  struct zx_elem_s* se MAYBE_UNUSED;
  ENC_LEN_DEBUG_BASE;
#if 1 /* NORMALMODE */
  struct zx_ns_s* pop_seen = 0;
  /* *** in simple_elem case should output ns prefix from ns node. */
  ZX_OUT_TAG(p, "<wst:RequestedAttachedReference");
  if (c->inc_ns)
    p = zx_enc_inc_ns(c, p, &pop_seen);
  p = zx_enc_xmlns_if_not_seen(c, p, zx_ns_tab+zx_xmlns_ix_wst, &pop_seen);


  p = zx_enc_unknown_attrs(p, x->gg.any_attr);
#else
  /* root node has no begin tag */
#endif
  
  {
      struct zx_wsse_SecurityTokenReference_s* e;
      for (e = x->SecurityTokenReference; e; e = (struct zx_wsse_SecurityTokenReference_s*)e->gg.g.n)
	  p = zx_ENC_SO_wsse_SecurityTokenReference(c, e, p);
  }

  p = zx_enc_so_unknown_elems_and_content(c, p, &x->gg);
  
#if 1 /* NORMALMODE */
  ZX_OUT_CLOSE_TAG(p, "</wst:RequestedAttachedReference>");
  zx_pop_seen(pop_seen);
#else
  /* root node has no end tag either */
#endif
  ENC_LEN_DEBUG(x, "wst:RequestedAttachedReference", p-enc_base);
  return p;
}

/* FUNC(zx_ENC_WO_wst_RequestedAttachedReference) */

/* Render element into string. The XML attributes and elements are
 * processed in wire order by chasing wo pointers. This is what you want for
 * validating signatures on other people's XML documents. */

/* Called by: */
char* zx_ENC_WO_wst_RequestedAttachedReference(struct zx_ctx* c, struct zx_wst_RequestedAttachedReference_s* x, char* p )
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
  ZX_OUT_MEM(p, "RequestedAttachedReference", sizeof("RequestedAttachedReference")-1);
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
  ENC_LEN_DEBUG(x, "wst:RequestedAttachedReference", p-enc_base);
  return p;
}

/* FUNC(zx_EASY_ENC_SO_wst_RequestedAttachedReference) */

/* Called by: */
struct zx_str* zx_EASY_ENC_SO_wst_RequestedAttachedReference(struct zx_ctx* c, struct zx_wst_RequestedAttachedReference_s* x )
{
  int len;
  char* buf;
  c->ns_tab = ZX_ALLOC(c, sizeof(zx_ns_tab));
  memcpy(c->ns_tab, zx_ns_tab, sizeof(zx_ns_tab));
  len = zx_LEN_SO_wst_RequestedAttachedReference(c, x );
  buf = ZX_ALLOC(c, len+1);
  return zx_easy_enc_common(c, zx_ENC_SO_wst_RequestedAttachedReference(c, x, buf ), buf, len);
}

/* FUNC(zx_EASY_ENC_WO_wst_RequestedAttachedReference) */

/* Called by: */
struct zx_str* zx_EASY_ENC_WO_wst_RequestedAttachedReference(struct zx_ctx* c, struct zx_wst_RequestedAttachedReference_s* x )
{
  int len;
  char* buf;
  c->ns_tab = ZX_ALLOC(c, sizeof(zx_ns_tab));
  memcpy(c->ns_tab, zx_ns_tab, sizeof(zx_ns_tab));
  len = zx_LEN_WO_wst_RequestedAttachedReference(c, x );
  buf = ZX_ALLOC(c, len+1);
  return zx_easy_enc_common(c, zx_ENC_WO_wst_RequestedAttachedReference(c, x, buf ), buf, len);
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

#define EL_NAME   wst_RequestedProofToken
#define EL_STRUCT zx_wst_RequestedProofToken_s
#define EL_NS     wst
#define EL_TAG    RequestedProofToken

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

/* FUNC(zx_LEN_SO_wst_RequestedProofToken) */

/* Compute length of an element (and its subelements). The XML attributes
 * and elements are processed in schema order. */

/* Called by: */
int zx_LEN_SO_wst_RequestedProofToken(struct zx_ctx* c, struct zx_wst_RequestedProofToken_s* x )
{
  struct zx_ns_s* pop_seen = 0;
  struct zx_elem_s* se MAYBE_UNUSED;
#if 1 /* NORMALMODE */
  /* *** in simple_elem case should output ns prefix from ns node. */
  int len = sizeof("<wst:RequestedProofToken")-1 + 1 + sizeof("</wst:RequestedProofToken>")-1;
  if (c->inc_ns_len)
    len += zx_len_inc_ns(c, &pop_seen);
  len += zx_len_xmlns_if_not_seen(c, zx_ns_tab+zx_xmlns_ix_wst, &pop_seen);


#else
  /* root node has no begin tag */
  int len = 0;
#endif
  


  len += zx_len_so_common(c, &x->gg);
  zx_pop_seen(pop_seen);
  ENC_LEN_DEBUG(x, "wst:RequestedProofToken", len);
  return len;
}

/* FUNC(zx_LEN_WO_wst_RequestedProofToken) */

/* Compute length of an element (and its subelements). The XML attributes
 * and elements are processed in wire order and no assumptions
 * are made about namespace prefixes. */

/* Called by: */
int zx_LEN_WO_wst_RequestedProofToken(struct zx_ctx* c, struct zx_wst_RequestedProofToken_s* x )
{
  struct zx_ns_s* pop_seen = 0;
  struct zx_elem_s* se MAYBE_UNUSED;
#if 1 /* NORMALMODE */
  int len = 1 + sizeof("RequestedProofToken")-1 + 1 + 2 + sizeof("RequestedProofToken")-1 + 1;
  
  if (x->gg.g.ns && x->gg.g.ns->prefix_len)
    len += (x->gg.g.ns->prefix_len + 1) * 2;
  if (c->inc_ns_len)
    len += zx_len_inc_ns(c, &pop_seen);
  len += zx_len_xmlns_if_not_seen(c, x->gg.g.ns, &pop_seen);


#else
  /* root node has no begin tag */
  int len = 0;
#endif
  


  len += zx_len_wo_common(c, &x->gg); 
  zx_pop_seen(pop_seen);
  ENC_LEN_DEBUG(x, "wst:RequestedProofToken", len);
  return len;
}

/* FUNC(zx_ENC_SO_wst_RequestedProofToken) */

/* Render element into string. The XML attributes and elements are
 * processed in schema order. This is what you generally want for
 * rendering new data structure to a string. The wo pointers are not used. */

/* Called by: */
char* zx_ENC_SO_wst_RequestedProofToken(struct zx_ctx* c, struct zx_wst_RequestedProofToken_s* x, char* p )
{
  struct zx_elem_s* se MAYBE_UNUSED;
  ENC_LEN_DEBUG_BASE;
#if 1 /* NORMALMODE */
  struct zx_ns_s* pop_seen = 0;
  /* *** in simple_elem case should output ns prefix from ns node. */
  ZX_OUT_TAG(p, "<wst:RequestedProofToken");
  if (c->inc_ns)
    p = zx_enc_inc_ns(c, p, &pop_seen);
  p = zx_enc_xmlns_if_not_seen(c, p, zx_ns_tab+zx_xmlns_ix_wst, &pop_seen);


  p = zx_enc_unknown_attrs(p, x->gg.any_attr);
#else
  /* root node has no begin tag */
#endif
  

  p = zx_enc_so_unknown_elems_and_content(c, p, &x->gg);
  
#if 1 /* NORMALMODE */
  ZX_OUT_CLOSE_TAG(p, "</wst:RequestedProofToken>");
  zx_pop_seen(pop_seen);
#else
  /* root node has no end tag either */
#endif
  ENC_LEN_DEBUG(x, "wst:RequestedProofToken", p-enc_base);
  return p;
}

/* FUNC(zx_ENC_WO_wst_RequestedProofToken) */

/* Render element into string. The XML attributes and elements are
 * processed in wire order by chasing wo pointers. This is what you want for
 * validating signatures on other people's XML documents. */

/* Called by: */
char* zx_ENC_WO_wst_RequestedProofToken(struct zx_ctx* c, struct zx_wst_RequestedProofToken_s* x, char* p )
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
  ZX_OUT_MEM(p, "RequestedProofToken", sizeof("RequestedProofToken")-1);
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
  ENC_LEN_DEBUG(x, "wst:RequestedProofToken", p-enc_base);
  return p;
}

/* FUNC(zx_EASY_ENC_SO_wst_RequestedProofToken) */

/* Called by: */
struct zx_str* zx_EASY_ENC_SO_wst_RequestedProofToken(struct zx_ctx* c, struct zx_wst_RequestedProofToken_s* x )
{
  int len;
  char* buf;
  c->ns_tab = ZX_ALLOC(c, sizeof(zx_ns_tab));
  memcpy(c->ns_tab, zx_ns_tab, sizeof(zx_ns_tab));
  len = zx_LEN_SO_wst_RequestedProofToken(c, x );
  buf = ZX_ALLOC(c, len+1);
  return zx_easy_enc_common(c, zx_ENC_SO_wst_RequestedProofToken(c, x, buf ), buf, len);
}

/* FUNC(zx_EASY_ENC_WO_wst_RequestedProofToken) */

/* Called by: */
struct zx_str* zx_EASY_ENC_WO_wst_RequestedProofToken(struct zx_ctx* c, struct zx_wst_RequestedProofToken_s* x )
{
  int len;
  char* buf;
  c->ns_tab = ZX_ALLOC(c, sizeof(zx_ns_tab));
  memcpy(c->ns_tab, zx_ns_tab, sizeof(zx_ns_tab));
  len = zx_LEN_WO_wst_RequestedProofToken(c, x );
  buf = ZX_ALLOC(c, len+1);
  return zx_easy_enc_common(c, zx_ENC_WO_wst_RequestedProofToken(c, x, buf ), buf, len);
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

#define EL_NAME   wst_RequestedSecurityToken
#define EL_STRUCT zx_wst_RequestedSecurityToken_s
#define EL_NS     wst
#define EL_TAG    RequestedSecurityToken

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

/* FUNC(zx_LEN_SO_wst_RequestedSecurityToken) */

/* Compute length of an element (and its subelements). The XML attributes
 * and elements are processed in schema order. */

/* Called by: */
int zx_LEN_SO_wst_RequestedSecurityToken(struct zx_ctx* c, struct zx_wst_RequestedSecurityToken_s* x )
{
  struct zx_ns_s* pop_seen = 0;
  struct zx_elem_s* se MAYBE_UNUSED;
#if 1 /* NORMALMODE */
  /* *** in simple_elem case should output ns prefix from ns node. */
  int len = sizeof("<wst:RequestedSecurityToken")-1 + 1 + sizeof("</wst:RequestedSecurityToken>")-1;
  if (c->inc_ns_len)
    len += zx_len_inc_ns(c, &pop_seen);
  len += zx_len_xmlns_if_not_seen(c, zx_ns_tab+zx_xmlns_ix_wst, &pop_seen);


#else
  /* root node has no begin tag */
  int len = 0;
#endif
  


  len += zx_len_so_common(c, &x->gg);
  zx_pop_seen(pop_seen);
  ENC_LEN_DEBUG(x, "wst:RequestedSecurityToken", len);
  return len;
}

/* FUNC(zx_LEN_WO_wst_RequestedSecurityToken) */

/* Compute length of an element (and its subelements). The XML attributes
 * and elements are processed in wire order and no assumptions
 * are made about namespace prefixes. */

/* Called by: */
int zx_LEN_WO_wst_RequestedSecurityToken(struct zx_ctx* c, struct zx_wst_RequestedSecurityToken_s* x )
{
  struct zx_ns_s* pop_seen = 0;
  struct zx_elem_s* se MAYBE_UNUSED;
#if 1 /* NORMALMODE */
  int len = 1 + sizeof("RequestedSecurityToken")-1 + 1 + 2 + sizeof("RequestedSecurityToken")-1 + 1;
  
  if (x->gg.g.ns && x->gg.g.ns->prefix_len)
    len += (x->gg.g.ns->prefix_len + 1) * 2;
  if (c->inc_ns_len)
    len += zx_len_inc_ns(c, &pop_seen);
  len += zx_len_xmlns_if_not_seen(c, x->gg.g.ns, &pop_seen);


#else
  /* root node has no begin tag */
  int len = 0;
#endif
  


  len += zx_len_wo_common(c, &x->gg); 
  zx_pop_seen(pop_seen);
  ENC_LEN_DEBUG(x, "wst:RequestedSecurityToken", len);
  return len;
}

/* FUNC(zx_ENC_SO_wst_RequestedSecurityToken) */

/* Render element into string. The XML attributes and elements are
 * processed in schema order. This is what you generally want for
 * rendering new data structure to a string. The wo pointers are not used. */

/* Called by: */
char* zx_ENC_SO_wst_RequestedSecurityToken(struct zx_ctx* c, struct zx_wst_RequestedSecurityToken_s* x, char* p )
{
  struct zx_elem_s* se MAYBE_UNUSED;
  ENC_LEN_DEBUG_BASE;
#if 1 /* NORMALMODE */
  struct zx_ns_s* pop_seen = 0;
  /* *** in simple_elem case should output ns prefix from ns node. */
  ZX_OUT_TAG(p, "<wst:RequestedSecurityToken");
  if (c->inc_ns)
    p = zx_enc_inc_ns(c, p, &pop_seen);
  p = zx_enc_xmlns_if_not_seen(c, p, zx_ns_tab+zx_xmlns_ix_wst, &pop_seen);


  p = zx_enc_unknown_attrs(p, x->gg.any_attr);
#else
  /* root node has no begin tag */
#endif
  

  p = zx_enc_so_unknown_elems_and_content(c, p, &x->gg);
  
#if 1 /* NORMALMODE */
  ZX_OUT_CLOSE_TAG(p, "</wst:RequestedSecurityToken>");
  zx_pop_seen(pop_seen);
#else
  /* root node has no end tag either */
#endif
  ENC_LEN_DEBUG(x, "wst:RequestedSecurityToken", p-enc_base);
  return p;
}

/* FUNC(zx_ENC_WO_wst_RequestedSecurityToken) */

/* Render element into string. The XML attributes and elements are
 * processed in wire order by chasing wo pointers. This is what you want for
 * validating signatures on other people's XML documents. */

/* Called by: */
char* zx_ENC_WO_wst_RequestedSecurityToken(struct zx_ctx* c, struct zx_wst_RequestedSecurityToken_s* x, char* p )
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
  ZX_OUT_MEM(p, "RequestedSecurityToken", sizeof("RequestedSecurityToken")-1);
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
  ENC_LEN_DEBUG(x, "wst:RequestedSecurityToken", p-enc_base);
  return p;
}

/* FUNC(zx_EASY_ENC_SO_wst_RequestedSecurityToken) */

/* Called by: */
struct zx_str* zx_EASY_ENC_SO_wst_RequestedSecurityToken(struct zx_ctx* c, struct zx_wst_RequestedSecurityToken_s* x )
{
  int len;
  char* buf;
  c->ns_tab = ZX_ALLOC(c, sizeof(zx_ns_tab));
  memcpy(c->ns_tab, zx_ns_tab, sizeof(zx_ns_tab));
  len = zx_LEN_SO_wst_RequestedSecurityToken(c, x );
  buf = ZX_ALLOC(c, len+1);
  return zx_easy_enc_common(c, zx_ENC_SO_wst_RequestedSecurityToken(c, x, buf ), buf, len);
}

/* FUNC(zx_EASY_ENC_WO_wst_RequestedSecurityToken) */

/* Called by: */
struct zx_str* zx_EASY_ENC_WO_wst_RequestedSecurityToken(struct zx_ctx* c, struct zx_wst_RequestedSecurityToken_s* x )
{
  int len;
  char* buf;
  c->ns_tab = ZX_ALLOC(c, sizeof(zx_ns_tab));
  memcpy(c->ns_tab, zx_ns_tab, sizeof(zx_ns_tab));
  len = zx_LEN_WO_wst_RequestedSecurityToken(c, x );
  buf = ZX_ALLOC(c, len+1);
  return zx_easy_enc_common(c, zx_ENC_WO_wst_RequestedSecurityToken(c, x, buf ), buf, len);
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

#define EL_NAME   wst_RequestedUnattachedReference
#define EL_STRUCT zx_wst_RequestedUnattachedReference_s
#define EL_NS     wst
#define EL_TAG    RequestedUnattachedReference

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

/* FUNC(zx_LEN_SO_wst_RequestedUnattachedReference) */

/* Compute length of an element (and its subelements). The XML attributes
 * and elements are processed in schema order. */

/* Called by: */
int zx_LEN_SO_wst_RequestedUnattachedReference(struct zx_ctx* c, struct zx_wst_RequestedUnattachedReference_s* x )
{
  struct zx_ns_s* pop_seen = 0;
  struct zx_elem_s* se MAYBE_UNUSED;
#if 1 /* NORMALMODE */
  /* *** in simple_elem case should output ns prefix from ns node. */
  int len = sizeof("<wst:RequestedUnattachedReference")-1 + 1 + sizeof("</wst:RequestedUnattachedReference>")-1;
  if (c->inc_ns_len)
    len += zx_len_inc_ns(c, &pop_seen);
  len += zx_len_xmlns_if_not_seen(c, zx_ns_tab+zx_xmlns_ix_wst, &pop_seen);


#else
  /* root node has no begin tag */
  int len = 0;
#endif
  
  {
      struct zx_wsse_SecurityTokenReference_s* e;
      for (e = x->SecurityTokenReference; e; e = (struct zx_wsse_SecurityTokenReference_s*)e->gg.g.n)
	  len += zx_LEN_SO_wsse_SecurityTokenReference(c, e);
  }


  len += zx_len_so_common(c, &x->gg);
  zx_pop_seen(pop_seen);
  ENC_LEN_DEBUG(x, "wst:RequestedUnattachedReference", len);
  return len;
}

/* FUNC(zx_LEN_WO_wst_RequestedUnattachedReference) */

/* Compute length of an element (and its subelements). The XML attributes
 * and elements are processed in wire order and no assumptions
 * are made about namespace prefixes. */

/* Called by: */
int zx_LEN_WO_wst_RequestedUnattachedReference(struct zx_ctx* c, struct zx_wst_RequestedUnattachedReference_s* x )
{
  struct zx_ns_s* pop_seen = 0;
  struct zx_elem_s* se MAYBE_UNUSED;
#if 1 /* NORMALMODE */
  int len = 1 + sizeof("RequestedUnattachedReference")-1 + 1 + 2 + sizeof("RequestedUnattachedReference")-1 + 1;
  
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
      struct zx_wsse_SecurityTokenReference_s* e;
      for (e = x->SecurityTokenReference; e; e = (struct zx_wsse_SecurityTokenReference_s*)e->gg.g.n)
	  len += zx_LEN_WO_wsse_SecurityTokenReference(c, e);
  }


  len += zx_len_wo_common(c, &x->gg); 
  zx_pop_seen(pop_seen);
  ENC_LEN_DEBUG(x, "wst:RequestedUnattachedReference", len);
  return len;
}

/* FUNC(zx_ENC_SO_wst_RequestedUnattachedReference) */

/* Render element into string. The XML attributes and elements are
 * processed in schema order. This is what you generally want for
 * rendering new data structure to a string. The wo pointers are not used. */

/* Called by: */
char* zx_ENC_SO_wst_RequestedUnattachedReference(struct zx_ctx* c, struct zx_wst_RequestedUnattachedReference_s* x, char* p )
{
  struct zx_elem_s* se MAYBE_UNUSED;
  ENC_LEN_DEBUG_BASE;
#if 1 /* NORMALMODE */
  struct zx_ns_s* pop_seen = 0;
  /* *** in simple_elem case should output ns prefix from ns node. */
  ZX_OUT_TAG(p, "<wst:RequestedUnattachedReference");
  if (c->inc_ns)
    p = zx_enc_inc_ns(c, p, &pop_seen);
  p = zx_enc_xmlns_if_not_seen(c, p, zx_ns_tab+zx_xmlns_ix_wst, &pop_seen);


  p = zx_enc_unknown_attrs(p, x->gg.any_attr);
#else
  /* root node has no begin tag */
#endif
  
  {
      struct zx_wsse_SecurityTokenReference_s* e;
      for (e = x->SecurityTokenReference; e; e = (struct zx_wsse_SecurityTokenReference_s*)e->gg.g.n)
	  p = zx_ENC_SO_wsse_SecurityTokenReference(c, e, p);
  }

  p = zx_enc_so_unknown_elems_and_content(c, p, &x->gg);
  
#if 1 /* NORMALMODE */
  ZX_OUT_CLOSE_TAG(p, "</wst:RequestedUnattachedReference>");
  zx_pop_seen(pop_seen);
#else
  /* root node has no end tag either */
#endif
  ENC_LEN_DEBUG(x, "wst:RequestedUnattachedReference", p-enc_base);
  return p;
}

/* FUNC(zx_ENC_WO_wst_RequestedUnattachedReference) */

/* Render element into string. The XML attributes and elements are
 * processed in wire order by chasing wo pointers. This is what you want for
 * validating signatures on other people's XML documents. */

/* Called by: */
char* zx_ENC_WO_wst_RequestedUnattachedReference(struct zx_ctx* c, struct zx_wst_RequestedUnattachedReference_s* x, char* p )
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
  ZX_OUT_MEM(p, "RequestedUnattachedReference", sizeof("RequestedUnattachedReference")-1);
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
  ENC_LEN_DEBUG(x, "wst:RequestedUnattachedReference", p-enc_base);
  return p;
}

/* FUNC(zx_EASY_ENC_SO_wst_RequestedUnattachedReference) */

/* Called by: */
struct zx_str* zx_EASY_ENC_SO_wst_RequestedUnattachedReference(struct zx_ctx* c, struct zx_wst_RequestedUnattachedReference_s* x )
{
  int len;
  char* buf;
  c->ns_tab = ZX_ALLOC(c, sizeof(zx_ns_tab));
  memcpy(c->ns_tab, zx_ns_tab, sizeof(zx_ns_tab));
  len = zx_LEN_SO_wst_RequestedUnattachedReference(c, x );
  buf = ZX_ALLOC(c, len+1);
  return zx_easy_enc_common(c, zx_ENC_SO_wst_RequestedUnattachedReference(c, x, buf ), buf, len);
}

/* FUNC(zx_EASY_ENC_WO_wst_RequestedUnattachedReference) */

/* Called by: */
struct zx_str* zx_EASY_ENC_WO_wst_RequestedUnattachedReference(struct zx_ctx* c, struct zx_wst_RequestedUnattachedReference_s* x )
{
  int len;
  char* buf;
  c->ns_tab = ZX_ALLOC(c, sizeof(zx_ns_tab));
  memcpy(c->ns_tab, zx_ns_tab, sizeof(zx_ns_tab));
  len = zx_LEN_WO_wst_RequestedUnattachedReference(c, x );
  buf = ZX_ALLOC(c, len+1);
  return zx_easy_enc_common(c, zx_ENC_WO_wst_RequestedUnattachedReference(c, x, buf ), buf, len);
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

#define EL_NAME   wst_SignChallenge
#define EL_STRUCT zx_wst_SignChallenge_s
#define EL_NS     wst
#define EL_TAG    SignChallenge

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

/* FUNC(zx_LEN_SO_wst_SignChallenge) */

/* Compute length of an element (and its subelements). The XML attributes
 * and elements are processed in schema order. */

/* Called by: */
int zx_LEN_SO_wst_SignChallenge(struct zx_ctx* c, struct zx_wst_SignChallenge_s* x )
{
  struct zx_ns_s* pop_seen = 0;
  struct zx_elem_s* se MAYBE_UNUSED;
#if 1 /* NORMALMODE */
  /* *** in simple_elem case should output ns prefix from ns node. */
  int len = sizeof("<wst:SignChallenge")-1 + 1 + sizeof("</wst:SignChallenge>")-1;
  if (c->inc_ns_len)
    len += zx_len_inc_ns(c, &pop_seen);
  len += zx_len_xmlns_if_not_seen(c, zx_ns_tab+zx_xmlns_ix_wst, &pop_seen);


#else
  /* root node has no begin tag */
  int len = 0;
#endif
  
  for (se = x->Challenge; se; se = (struct zx_elem_s*)se->g.n)
    len += zx_LEN_SO_simple_elem(c,se, sizeof("wst:Challenge")-1, zx_ns_tab+zx_xmlns_ix_wst);


  len += zx_len_so_common(c, &x->gg);
  zx_pop_seen(pop_seen);
  ENC_LEN_DEBUG(x, "wst:SignChallenge", len);
  return len;
}

/* FUNC(zx_LEN_WO_wst_SignChallenge) */

/* Compute length of an element (and its subelements). The XML attributes
 * and elements are processed in wire order and no assumptions
 * are made about namespace prefixes. */

/* Called by: */
int zx_LEN_WO_wst_SignChallenge(struct zx_ctx* c, struct zx_wst_SignChallenge_s* x )
{
  struct zx_ns_s* pop_seen = 0;
  struct zx_elem_s* se MAYBE_UNUSED;
#if 1 /* NORMALMODE */
  int len = 1 + sizeof("SignChallenge")-1 + 1 + 2 + sizeof("SignChallenge")-1 + 1;
  
  if (x->gg.g.ns && x->gg.g.ns->prefix_len)
    len += (x->gg.g.ns->prefix_len + 1) * 2;
  if (c->inc_ns_len)
    len += zx_len_inc_ns(c, &pop_seen);
  len += zx_len_xmlns_if_not_seen(c, x->gg.g.ns, &pop_seen);


#else
  /* root node has no begin tag */
  int len = 0;
#endif
  
  for (se = x->Challenge; se; se = (struct zx_elem_s*)se->g.n)
    len += zx_LEN_WO_simple_elem(c, se, sizeof("Challenge")-1);


  len += zx_len_wo_common(c, &x->gg); 
  zx_pop_seen(pop_seen);
  ENC_LEN_DEBUG(x, "wst:SignChallenge", len);
  return len;
}

/* FUNC(zx_ENC_SO_wst_SignChallenge) */

/* Render element into string. The XML attributes and elements are
 * processed in schema order. This is what you generally want for
 * rendering new data structure to a string. The wo pointers are not used. */

/* Called by: */
char* zx_ENC_SO_wst_SignChallenge(struct zx_ctx* c, struct zx_wst_SignChallenge_s* x, char* p )
{
  struct zx_elem_s* se MAYBE_UNUSED;
  ENC_LEN_DEBUG_BASE;
#if 1 /* NORMALMODE */
  struct zx_ns_s* pop_seen = 0;
  /* *** in simple_elem case should output ns prefix from ns node. */
  ZX_OUT_TAG(p, "<wst:SignChallenge");
  if (c->inc_ns)
    p = zx_enc_inc_ns(c, p, &pop_seen);
  p = zx_enc_xmlns_if_not_seen(c, p, zx_ns_tab+zx_xmlns_ix_wst, &pop_seen);


  p = zx_enc_unknown_attrs(p, x->gg.any_attr);
#else
  /* root node has no begin tag */
#endif
  
  for (se = x->Challenge; se; se = (struct zx_elem_s*)se->g.n)
    p = zx_ENC_SO_simple_elem(c, se, p, "wst:Challenge", sizeof("wst:Challenge")-1, zx_ns_tab+zx_xmlns_ix_wst);

  p = zx_enc_so_unknown_elems_and_content(c, p, &x->gg);
  
#if 1 /* NORMALMODE */
  ZX_OUT_CLOSE_TAG(p, "</wst:SignChallenge>");
  zx_pop_seen(pop_seen);
#else
  /* root node has no end tag either */
#endif
  ENC_LEN_DEBUG(x, "wst:SignChallenge", p-enc_base);
  return p;
}

/* FUNC(zx_ENC_WO_wst_SignChallenge) */

/* Render element into string. The XML attributes and elements are
 * processed in wire order by chasing wo pointers. This is what you want for
 * validating signatures on other people's XML documents. */

/* Called by: */
char* zx_ENC_WO_wst_SignChallenge(struct zx_ctx* c, struct zx_wst_SignChallenge_s* x, char* p )
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
  ZX_OUT_MEM(p, "SignChallenge", sizeof("SignChallenge")-1);
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
  ENC_LEN_DEBUG(x, "wst:SignChallenge", p-enc_base);
  return p;
}

/* FUNC(zx_EASY_ENC_SO_wst_SignChallenge) */

/* Called by: */
struct zx_str* zx_EASY_ENC_SO_wst_SignChallenge(struct zx_ctx* c, struct zx_wst_SignChallenge_s* x )
{
  int len;
  char* buf;
  c->ns_tab = ZX_ALLOC(c, sizeof(zx_ns_tab));
  memcpy(c->ns_tab, zx_ns_tab, sizeof(zx_ns_tab));
  len = zx_LEN_SO_wst_SignChallenge(c, x );
  buf = ZX_ALLOC(c, len+1);
  return zx_easy_enc_common(c, zx_ENC_SO_wst_SignChallenge(c, x, buf ), buf, len);
}

/* FUNC(zx_EASY_ENC_WO_wst_SignChallenge) */

/* Called by: */
struct zx_str* zx_EASY_ENC_WO_wst_SignChallenge(struct zx_ctx* c, struct zx_wst_SignChallenge_s* x )
{
  int len;
  char* buf;
  c->ns_tab = ZX_ALLOC(c, sizeof(zx_ns_tab));
  memcpy(c->ns_tab, zx_ns_tab, sizeof(zx_ns_tab));
  len = zx_LEN_WO_wst_SignChallenge(c, x );
  buf = ZX_ALLOC(c, len+1);
  return zx_easy_enc_common(c, zx_ENC_WO_wst_SignChallenge(c, x, buf ), buf, len);
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

#define EL_NAME   wst_SignChallengeResponse
#define EL_STRUCT zx_wst_SignChallengeResponse_s
#define EL_NS     wst
#define EL_TAG    SignChallengeResponse

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

/* FUNC(zx_LEN_SO_wst_SignChallengeResponse) */

/* Compute length of an element (and its subelements). The XML attributes
 * and elements are processed in schema order. */

/* Called by: */
int zx_LEN_SO_wst_SignChallengeResponse(struct zx_ctx* c, struct zx_wst_SignChallengeResponse_s* x )
{
  struct zx_ns_s* pop_seen = 0;
  struct zx_elem_s* se MAYBE_UNUSED;
#if 1 /* NORMALMODE */
  /* *** in simple_elem case should output ns prefix from ns node. */
  int len = sizeof("<wst:SignChallengeResponse")-1 + 1 + sizeof("</wst:SignChallengeResponse>")-1;
  if (c->inc_ns_len)
    len += zx_len_inc_ns(c, &pop_seen);
  len += zx_len_xmlns_if_not_seen(c, zx_ns_tab+zx_xmlns_ix_wst, &pop_seen);


#else
  /* root node has no begin tag */
  int len = 0;
#endif
  
  for (se = x->Challenge; se; se = (struct zx_elem_s*)se->g.n)
    len += zx_LEN_SO_simple_elem(c,se, sizeof("wst:Challenge")-1, zx_ns_tab+zx_xmlns_ix_wst);


  len += zx_len_so_common(c, &x->gg);
  zx_pop_seen(pop_seen);
  ENC_LEN_DEBUG(x, "wst:SignChallengeResponse", len);
  return len;
}

/* FUNC(zx_LEN_WO_wst_SignChallengeResponse) */

/* Compute length of an element (and its subelements). The XML attributes
 * and elements are processed in wire order and no assumptions
 * are made about namespace prefixes. */

/* Called by: */
int zx_LEN_WO_wst_SignChallengeResponse(struct zx_ctx* c, struct zx_wst_SignChallengeResponse_s* x )
{
  struct zx_ns_s* pop_seen = 0;
  struct zx_elem_s* se MAYBE_UNUSED;
#if 1 /* NORMALMODE */
  int len = 1 + sizeof("SignChallengeResponse")-1 + 1 + 2 + sizeof("SignChallengeResponse")-1 + 1;
  
  if (x->gg.g.ns && x->gg.g.ns->prefix_len)
    len += (x->gg.g.ns->prefix_len + 1) * 2;
  if (c->inc_ns_len)
    len += zx_len_inc_ns(c, &pop_seen);
  len += zx_len_xmlns_if_not_seen(c, x->gg.g.ns, &pop_seen);


#else
  /* root node has no begin tag */
  int len = 0;
#endif
  
  for (se = x->Challenge; se; se = (struct zx_elem_s*)se->g.n)
    len += zx_LEN_WO_simple_elem(c, se, sizeof("Challenge")-1);


  len += zx_len_wo_common(c, &x->gg); 
  zx_pop_seen(pop_seen);
  ENC_LEN_DEBUG(x, "wst:SignChallengeResponse", len);
  return len;
}

/* FUNC(zx_ENC_SO_wst_SignChallengeResponse) */

/* Render element into string. The XML attributes and elements are
 * processed in schema order. This is what you generally want for
 * rendering new data structure to a string. The wo pointers are not used. */

/* Called by: */
char* zx_ENC_SO_wst_SignChallengeResponse(struct zx_ctx* c, struct zx_wst_SignChallengeResponse_s* x, char* p )
{
  struct zx_elem_s* se MAYBE_UNUSED;
  ENC_LEN_DEBUG_BASE;
#if 1 /* NORMALMODE */
  struct zx_ns_s* pop_seen = 0;
  /* *** in simple_elem case should output ns prefix from ns node. */
  ZX_OUT_TAG(p, "<wst:SignChallengeResponse");
  if (c->inc_ns)
    p = zx_enc_inc_ns(c, p, &pop_seen);
  p = zx_enc_xmlns_if_not_seen(c, p, zx_ns_tab+zx_xmlns_ix_wst, &pop_seen);


  p = zx_enc_unknown_attrs(p, x->gg.any_attr);
#else
  /* root node has no begin tag */
#endif
  
  for (se = x->Challenge; se; se = (struct zx_elem_s*)se->g.n)
    p = zx_ENC_SO_simple_elem(c, se, p, "wst:Challenge", sizeof("wst:Challenge")-1, zx_ns_tab+zx_xmlns_ix_wst);

  p = zx_enc_so_unknown_elems_and_content(c, p, &x->gg);
  
#if 1 /* NORMALMODE */
  ZX_OUT_CLOSE_TAG(p, "</wst:SignChallengeResponse>");
  zx_pop_seen(pop_seen);
#else
  /* root node has no end tag either */
#endif
  ENC_LEN_DEBUG(x, "wst:SignChallengeResponse", p-enc_base);
  return p;
}

/* FUNC(zx_ENC_WO_wst_SignChallengeResponse) */

/* Render element into string. The XML attributes and elements are
 * processed in wire order by chasing wo pointers. This is what you want for
 * validating signatures on other people's XML documents. */

/* Called by: */
char* zx_ENC_WO_wst_SignChallengeResponse(struct zx_ctx* c, struct zx_wst_SignChallengeResponse_s* x, char* p )
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
  ZX_OUT_MEM(p, "SignChallengeResponse", sizeof("SignChallengeResponse")-1);
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
  ENC_LEN_DEBUG(x, "wst:SignChallengeResponse", p-enc_base);
  return p;
}

/* FUNC(zx_EASY_ENC_SO_wst_SignChallengeResponse) */

/* Called by: */
struct zx_str* zx_EASY_ENC_SO_wst_SignChallengeResponse(struct zx_ctx* c, struct zx_wst_SignChallengeResponse_s* x )
{
  int len;
  char* buf;
  c->ns_tab = ZX_ALLOC(c, sizeof(zx_ns_tab));
  memcpy(c->ns_tab, zx_ns_tab, sizeof(zx_ns_tab));
  len = zx_LEN_SO_wst_SignChallengeResponse(c, x );
  buf = ZX_ALLOC(c, len+1);
  return zx_easy_enc_common(c, zx_ENC_SO_wst_SignChallengeResponse(c, x, buf ), buf, len);
}

/* FUNC(zx_EASY_ENC_WO_wst_SignChallengeResponse) */

/* Called by: */
struct zx_str* zx_EASY_ENC_WO_wst_SignChallengeResponse(struct zx_ctx* c, struct zx_wst_SignChallengeResponse_s* x )
{
  int len;
  char* buf;
  c->ns_tab = ZX_ALLOC(c, sizeof(zx_ns_tab));
  memcpy(c->ns_tab, zx_ns_tab, sizeof(zx_ns_tab));
  len = zx_LEN_WO_wst_SignChallengeResponse(c, x );
  buf = ZX_ALLOC(c, len+1);
  return zx_easy_enc_common(c, zx_ENC_WO_wst_SignChallengeResponse(c, x, buf ), buf, len);
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

#define EL_NAME   wst_Status
#define EL_STRUCT zx_wst_Status_s
#define EL_NS     wst
#define EL_TAG    Status

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

/* FUNC(zx_LEN_SO_wst_Status) */

/* Compute length of an element (and its subelements). The XML attributes
 * and elements are processed in schema order. */

/* Called by: */
int zx_LEN_SO_wst_Status(struct zx_ctx* c, struct zx_wst_Status_s* x )
{
  struct zx_ns_s* pop_seen = 0;
  struct zx_elem_s* se MAYBE_UNUSED;
#if 1 /* NORMALMODE */
  /* *** in simple_elem case should output ns prefix from ns node. */
  int len = sizeof("<wst:Status")-1 + 1 + sizeof("</wst:Status>")-1;
  if (c->inc_ns_len)
    len += zx_len_inc_ns(c, &pop_seen);
  len += zx_len_xmlns_if_not_seen(c, zx_ns_tab+zx_xmlns_ix_wst, &pop_seen);


#else
  /* root node has no begin tag */
  int len = 0;
#endif
  
  for (se = x->Code; se; se = (struct zx_elem_s*)se->g.n)
    len += zx_LEN_SO_simple_elem(c,se, sizeof("wst:Code")-1, zx_ns_tab+zx_xmlns_ix_wst);
  for (se = x->Reason; se; se = (struct zx_elem_s*)se->g.n)
    len += zx_LEN_SO_simple_elem(c,se, sizeof("wst:Reason")-1, zx_ns_tab+zx_xmlns_ix_wst);


  len += zx_len_so_common(c, &x->gg);
  zx_pop_seen(pop_seen);
  ENC_LEN_DEBUG(x, "wst:Status", len);
  return len;
}

/* FUNC(zx_LEN_WO_wst_Status) */

/* Compute length of an element (and its subelements). The XML attributes
 * and elements are processed in wire order and no assumptions
 * are made about namespace prefixes. */

/* Called by: */
int zx_LEN_WO_wst_Status(struct zx_ctx* c, struct zx_wst_Status_s* x )
{
  struct zx_ns_s* pop_seen = 0;
  struct zx_elem_s* se MAYBE_UNUSED;
#if 1 /* NORMALMODE */
  int len = 1 + sizeof("Status")-1 + 1 + 2 + sizeof("Status")-1 + 1;
  
  if (x->gg.g.ns && x->gg.g.ns->prefix_len)
    len += (x->gg.g.ns->prefix_len + 1) * 2;
  if (c->inc_ns_len)
    len += zx_len_inc_ns(c, &pop_seen);
  len += zx_len_xmlns_if_not_seen(c, x->gg.g.ns, &pop_seen);


#else
  /* root node has no begin tag */
  int len = 0;
#endif
  
  for (se = x->Code; se; se = (struct zx_elem_s*)se->g.n)
    len += zx_LEN_WO_simple_elem(c, se, sizeof("Code")-1);
  for (se = x->Reason; se; se = (struct zx_elem_s*)se->g.n)
    len += zx_LEN_WO_simple_elem(c, se, sizeof("Reason")-1);


  len += zx_len_wo_common(c, &x->gg); 
  zx_pop_seen(pop_seen);
  ENC_LEN_DEBUG(x, "wst:Status", len);
  return len;
}

/* FUNC(zx_ENC_SO_wst_Status) */

/* Render element into string. The XML attributes and elements are
 * processed in schema order. This is what you generally want for
 * rendering new data structure to a string. The wo pointers are not used. */

/* Called by: */
char* zx_ENC_SO_wst_Status(struct zx_ctx* c, struct zx_wst_Status_s* x, char* p )
{
  struct zx_elem_s* se MAYBE_UNUSED;
  ENC_LEN_DEBUG_BASE;
#if 1 /* NORMALMODE */
  struct zx_ns_s* pop_seen = 0;
  /* *** in simple_elem case should output ns prefix from ns node. */
  ZX_OUT_TAG(p, "<wst:Status");
  if (c->inc_ns)
    p = zx_enc_inc_ns(c, p, &pop_seen);
  p = zx_enc_xmlns_if_not_seen(c, p, zx_ns_tab+zx_xmlns_ix_wst, &pop_seen);


  p = zx_enc_unknown_attrs(p, x->gg.any_attr);
#else
  /* root node has no begin tag */
#endif
  
  for (se = x->Code; se; se = (struct zx_elem_s*)se->g.n)
    p = zx_ENC_SO_simple_elem(c, se, p, "wst:Code", sizeof("wst:Code")-1, zx_ns_tab+zx_xmlns_ix_wst);
  for (se = x->Reason; se; se = (struct zx_elem_s*)se->g.n)
    p = zx_ENC_SO_simple_elem(c, se, p, "wst:Reason", sizeof("wst:Reason")-1, zx_ns_tab+zx_xmlns_ix_wst);

  p = zx_enc_so_unknown_elems_and_content(c, p, &x->gg);
  
#if 1 /* NORMALMODE */
  ZX_OUT_CLOSE_TAG(p, "</wst:Status>");
  zx_pop_seen(pop_seen);
#else
  /* root node has no end tag either */
#endif
  ENC_LEN_DEBUG(x, "wst:Status", p-enc_base);
  return p;
}

/* FUNC(zx_ENC_WO_wst_Status) */

/* Render element into string. The XML attributes and elements are
 * processed in wire order by chasing wo pointers. This is what you want for
 * validating signatures on other people's XML documents. */

/* Called by: */
char* zx_ENC_WO_wst_Status(struct zx_ctx* c, struct zx_wst_Status_s* x, char* p )
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
  ZX_OUT_MEM(p, "Status", sizeof("Status")-1);
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
  ENC_LEN_DEBUG(x, "wst:Status", p-enc_base);
  return p;
}

/* FUNC(zx_EASY_ENC_SO_wst_Status) */

/* Called by: */
struct zx_str* zx_EASY_ENC_SO_wst_Status(struct zx_ctx* c, struct zx_wst_Status_s* x )
{
  int len;
  char* buf;
  c->ns_tab = ZX_ALLOC(c, sizeof(zx_ns_tab));
  memcpy(c->ns_tab, zx_ns_tab, sizeof(zx_ns_tab));
  len = zx_LEN_SO_wst_Status(c, x );
  buf = ZX_ALLOC(c, len+1);
  return zx_easy_enc_common(c, zx_ENC_SO_wst_Status(c, x, buf ), buf, len);
}

/* FUNC(zx_EASY_ENC_WO_wst_Status) */

/* Called by: */
struct zx_str* zx_EASY_ENC_WO_wst_Status(struct zx_ctx* c, struct zx_wst_Status_s* x )
{
  int len;
  char* buf;
  c->ns_tab = ZX_ALLOC(c, sizeof(zx_ns_tab));
  memcpy(c->ns_tab, zx_ns_tab, sizeof(zx_ns_tab));
  len = zx_LEN_WO_wst_Status(c, x );
  buf = ZX_ALLOC(c, len+1);
  return zx_easy_enc_common(c, zx_ENC_WO_wst_Status(c, x, buf ), buf, len);
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

#define EL_NAME   wst_UseKey
#define EL_STRUCT zx_wst_UseKey_s
#define EL_NS     wst
#define EL_TAG    UseKey

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

/* FUNC(zx_LEN_SO_wst_UseKey) */

/* Compute length of an element (and its subelements). The XML attributes
 * and elements are processed in schema order. */

/* Called by: */
int zx_LEN_SO_wst_UseKey(struct zx_ctx* c, struct zx_wst_UseKey_s* x )
{
  struct zx_ns_s* pop_seen = 0;
  struct zx_elem_s* se MAYBE_UNUSED;
#if 1 /* NORMALMODE */
  /* *** in simple_elem case should output ns prefix from ns node. */
  int len = sizeof("<wst:UseKey")-1 + 1 + sizeof("</wst:UseKey>")-1;
  if (c->inc_ns_len)
    len += zx_len_inc_ns(c, &pop_seen);
  len += zx_len_xmlns_if_not_seen(c, zx_ns_tab+zx_xmlns_ix_wst, &pop_seen);

  len += zx_attr_so_len(x->Sig, sizeof("Sig")-1);

#else
  /* root node has no begin tag */
  int len = 0;
#endif
  


  len += zx_len_so_common(c, &x->gg);
  zx_pop_seen(pop_seen);
  ENC_LEN_DEBUG(x, "wst:UseKey", len);
  return len;
}

/* FUNC(zx_LEN_WO_wst_UseKey) */

/* Compute length of an element (and its subelements). The XML attributes
 * and elements are processed in wire order and no assumptions
 * are made about namespace prefixes. */

/* Called by: */
int zx_LEN_WO_wst_UseKey(struct zx_ctx* c, struct zx_wst_UseKey_s* x )
{
  struct zx_ns_s* pop_seen = 0;
  struct zx_elem_s* se MAYBE_UNUSED;
#if 1 /* NORMALMODE */
  int len = 1 + sizeof("UseKey")-1 + 1 + 2 + sizeof("UseKey")-1 + 1;
  
  if (x->gg.g.ns && x->gg.g.ns->prefix_len)
    len += (x->gg.g.ns->prefix_len + 1) * 2;
  if (c->inc_ns_len)
    len += zx_len_inc_ns(c, &pop_seen);
  len += zx_len_xmlns_if_not_seen(c, x->gg.g.ns, &pop_seen);

  len += zx_attr_wo_len(x->Sig, sizeof("Sig")-1);

#else
  /* root node has no begin tag */
  int len = 0;
#endif
  


  len += zx_len_wo_common(c, &x->gg); 
  zx_pop_seen(pop_seen);
  ENC_LEN_DEBUG(x, "wst:UseKey", len);
  return len;
}

/* FUNC(zx_ENC_SO_wst_UseKey) */

/* Render element into string. The XML attributes and elements are
 * processed in schema order. This is what you generally want for
 * rendering new data structure to a string. The wo pointers are not used. */

/* Called by: */
char* zx_ENC_SO_wst_UseKey(struct zx_ctx* c, struct zx_wst_UseKey_s* x, char* p )
{
  struct zx_elem_s* se MAYBE_UNUSED;
  ENC_LEN_DEBUG_BASE;
#if 1 /* NORMALMODE */
  struct zx_ns_s* pop_seen = 0;
  /* *** in simple_elem case should output ns prefix from ns node. */
  ZX_OUT_TAG(p, "<wst:UseKey");
  if (c->inc_ns)
    p = zx_enc_inc_ns(c, p, &pop_seen);
  p = zx_enc_xmlns_if_not_seen(c, p, zx_ns_tab+zx_xmlns_ix_wst, &pop_seen);

  p = zx_attr_so_enc(p, x->Sig, " Sig=\"", sizeof(" Sig=\"")-1);

  p = zx_enc_unknown_attrs(p, x->gg.any_attr);
#else
  /* root node has no begin tag */
#endif
  

  p = zx_enc_so_unknown_elems_and_content(c, p, &x->gg);
  
#if 1 /* NORMALMODE */
  ZX_OUT_CLOSE_TAG(p, "</wst:UseKey>");
  zx_pop_seen(pop_seen);
#else
  /* root node has no end tag either */
#endif
  ENC_LEN_DEBUG(x, "wst:UseKey", p-enc_base);
  return p;
}

/* FUNC(zx_ENC_WO_wst_UseKey) */

/* Render element into string. The XML attributes and elements are
 * processed in wire order by chasing wo pointers. This is what you want for
 * validating signatures on other people's XML documents. */

/* Called by: */
char* zx_ENC_WO_wst_UseKey(struct zx_ctx* c, struct zx_wst_UseKey_s* x, char* p )
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
  ZX_OUT_MEM(p, "UseKey", sizeof("UseKey")-1);
  qq = p;

  /* *** sort the namespaces */
  if (c->inc_ns)
    zx_add_inc_ns(c, &pop_seen);
  zx_add_xmlns_if_not_seen(c, x->gg.g.ns, &pop_seen);

  p = zx_enc_seen(p, pop_seen); 
  p = zx_attr_wo_enc(p, x->Sig, "Sig=\"", sizeof("Sig=\"")-1);

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
  ENC_LEN_DEBUG(x, "wst:UseKey", p-enc_base);
  return p;
}

/* FUNC(zx_EASY_ENC_SO_wst_UseKey) */

/* Called by: */
struct zx_str* zx_EASY_ENC_SO_wst_UseKey(struct zx_ctx* c, struct zx_wst_UseKey_s* x )
{
  int len;
  char* buf;
  c->ns_tab = ZX_ALLOC(c, sizeof(zx_ns_tab));
  memcpy(c->ns_tab, zx_ns_tab, sizeof(zx_ns_tab));
  len = zx_LEN_SO_wst_UseKey(c, x );
  buf = ZX_ALLOC(c, len+1);
  return zx_easy_enc_common(c, zx_ENC_SO_wst_UseKey(c, x, buf ), buf, len);
}

/* FUNC(zx_EASY_ENC_WO_wst_UseKey) */

/* Called by: */
struct zx_str* zx_EASY_ENC_WO_wst_UseKey(struct zx_ctx* c, struct zx_wst_UseKey_s* x )
{
  int len;
  char* buf;
  c->ns_tab = ZX_ALLOC(c, sizeof(zx_ns_tab));
  memcpy(c->ns_tab, zx_ns_tab, sizeof(zx_ns_tab));
  len = zx_LEN_WO_wst_UseKey(c, x );
  buf = ZX_ALLOC(c, len+1);
  return zx_easy_enc_common(c, zx_ENC_WO_wst_UseKey(c, x, buf ), buf, len);
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

#define EL_NAME   wst_ValidateTarget
#define EL_STRUCT zx_wst_ValidateTarget_s
#define EL_NS     wst
#define EL_TAG    ValidateTarget

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

/* FUNC(zx_LEN_SO_wst_ValidateTarget) */

/* Compute length of an element (and its subelements). The XML attributes
 * and elements are processed in schema order. */

/* Called by: */
int zx_LEN_SO_wst_ValidateTarget(struct zx_ctx* c, struct zx_wst_ValidateTarget_s* x )
{
  struct zx_ns_s* pop_seen = 0;
  struct zx_elem_s* se MAYBE_UNUSED;
#if 1 /* NORMALMODE */
  /* *** in simple_elem case should output ns prefix from ns node. */
  int len = sizeof("<wst:ValidateTarget")-1 + 1 + sizeof("</wst:ValidateTarget>")-1;
  if (c->inc_ns_len)
    len += zx_len_inc_ns(c, &pop_seen);
  len += zx_len_xmlns_if_not_seen(c, zx_ns_tab+zx_xmlns_ix_wst, &pop_seen);


#else
  /* root node has no begin tag */
  int len = 0;
#endif
  


  len += zx_len_so_common(c, &x->gg);
  zx_pop_seen(pop_seen);
  ENC_LEN_DEBUG(x, "wst:ValidateTarget", len);
  return len;
}

/* FUNC(zx_LEN_WO_wst_ValidateTarget) */

/* Compute length of an element (and its subelements). The XML attributes
 * and elements are processed in wire order and no assumptions
 * are made about namespace prefixes. */

/* Called by: */
int zx_LEN_WO_wst_ValidateTarget(struct zx_ctx* c, struct zx_wst_ValidateTarget_s* x )
{
  struct zx_ns_s* pop_seen = 0;
  struct zx_elem_s* se MAYBE_UNUSED;
#if 1 /* NORMALMODE */
  int len = 1 + sizeof("ValidateTarget")-1 + 1 + 2 + sizeof("ValidateTarget")-1 + 1;
  
  if (x->gg.g.ns && x->gg.g.ns->prefix_len)
    len += (x->gg.g.ns->prefix_len + 1) * 2;
  if (c->inc_ns_len)
    len += zx_len_inc_ns(c, &pop_seen);
  len += zx_len_xmlns_if_not_seen(c, x->gg.g.ns, &pop_seen);


#else
  /* root node has no begin tag */
  int len = 0;
#endif
  


  len += zx_len_wo_common(c, &x->gg); 
  zx_pop_seen(pop_seen);
  ENC_LEN_DEBUG(x, "wst:ValidateTarget", len);
  return len;
}

/* FUNC(zx_ENC_SO_wst_ValidateTarget) */

/* Render element into string. The XML attributes and elements are
 * processed in schema order. This is what you generally want for
 * rendering new data structure to a string. The wo pointers are not used. */

/* Called by: */
char* zx_ENC_SO_wst_ValidateTarget(struct zx_ctx* c, struct zx_wst_ValidateTarget_s* x, char* p )
{
  struct zx_elem_s* se MAYBE_UNUSED;
  ENC_LEN_DEBUG_BASE;
#if 1 /* NORMALMODE */
  struct zx_ns_s* pop_seen = 0;
  /* *** in simple_elem case should output ns prefix from ns node. */
  ZX_OUT_TAG(p, "<wst:ValidateTarget");
  if (c->inc_ns)
    p = zx_enc_inc_ns(c, p, &pop_seen);
  p = zx_enc_xmlns_if_not_seen(c, p, zx_ns_tab+zx_xmlns_ix_wst, &pop_seen);


  p = zx_enc_unknown_attrs(p, x->gg.any_attr);
#else
  /* root node has no begin tag */
#endif
  

  p = zx_enc_so_unknown_elems_and_content(c, p, &x->gg);
  
#if 1 /* NORMALMODE */
  ZX_OUT_CLOSE_TAG(p, "</wst:ValidateTarget>");
  zx_pop_seen(pop_seen);
#else
  /* root node has no end tag either */
#endif
  ENC_LEN_DEBUG(x, "wst:ValidateTarget", p-enc_base);
  return p;
}

/* FUNC(zx_ENC_WO_wst_ValidateTarget) */

/* Render element into string. The XML attributes and elements are
 * processed in wire order by chasing wo pointers. This is what you want for
 * validating signatures on other people's XML documents. */

/* Called by: */
char* zx_ENC_WO_wst_ValidateTarget(struct zx_ctx* c, struct zx_wst_ValidateTarget_s* x, char* p )
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
  ZX_OUT_MEM(p, "ValidateTarget", sizeof("ValidateTarget")-1);
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
  ENC_LEN_DEBUG(x, "wst:ValidateTarget", p-enc_base);
  return p;
}

/* FUNC(zx_EASY_ENC_SO_wst_ValidateTarget) */

/* Called by: */
struct zx_str* zx_EASY_ENC_SO_wst_ValidateTarget(struct zx_ctx* c, struct zx_wst_ValidateTarget_s* x )
{
  int len;
  char* buf;
  c->ns_tab = ZX_ALLOC(c, sizeof(zx_ns_tab));
  memcpy(c->ns_tab, zx_ns_tab, sizeof(zx_ns_tab));
  len = zx_LEN_SO_wst_ValidateTarget(c, x );
  buf = ZX_ALLOC(c, len+1);
  return zx_easy_enc_common(c, zx_ENC_SO_wst_ValidateTarget(c, x, buf ), buf, len);
}

/* FUNC(zx_EASY_ENC_WO_wst_ValidateTarget) */

/* Called by: */
struct zx_str* zx_EASY_ENC_WO_wst_ValidateTarget(struct zx_ctx* c, struct zx_wst_ValidateTarget_s* x )
{
  int len;
  char* buf;
  c->ns_tab = ZX_ALLOC(c, sizeof(zx_ns_tab));
  memcpy(c->ns_tab, zx_ns_tab, sizeof(zx_ns_tab));
  len = zx_LEN_WO_wst_ValidateTarget(c, x );
  buf = ZX_ALLOC(c, len+1);
  return zx_easy_enc_common(c, zx_ENC_WO_wst_ValidateTarget(c, x, buf ), buf, len);
}




/* EOF -- c/zx-wst-enc.c */
