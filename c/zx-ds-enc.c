/* c/zx-ds-enc.c - WARNING: This file was automatically generated. DO NOT EDIT!
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
#include "c/zx-ds-data.h"
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

#define EL_NAME   ds_CanonicalizationMethod
#define EL_STRUCT zx_ds_CanonicalizationMethod_s
#define EL_NS     ds
#define EL_TAG    CanonicalizationMethod

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

/* FUNC(zx_LEN_SO_ds_CanonicalizationMethod) */

/* Compute length of an element (and its subelements). The XML attributes
 * and elements are processed in schema order. */

/* Called by: */
int zx_LEN_SO_ds_CanonicalizationMethod(struct zx_ctx* c, struct zx_ds_CanonicalizationMethod_s* x )
{
  struct zx_ns_s* pop_seen = 0;
  struct zx_elem_s* se MAYBE_UNUSED;
#if 1 /* NORMALMODE */
  /* *** in simple_elem case should output ns prefix from ns node. */
  int len = sizeof("<ds:CanonicalizationMethod")-1 + 1 + sizeof("</ds:CanonicalizationMethod>")-1;
  if (c->inc_ns_len)
    len += zx_len_inc_ns(c, &pop_seen);
  len += zx_len_xmlns_if_not_seen(c, zx_ns_tab+zx_xmlns_ix_ds, &pop_seen);

  len += zx_attr_so_len(x->Algorithm, sizeof("Algorithm")-1);

#else
  /* root node has no begin tag */
  int len = 0;
#endif
  


  len += zx_len_so_common(c, &x->gg);
  zx_pop_seen(pop_seen);
  ENC_LEN_DEBUG(x, "ds:CanonicalizationMethod", len);
  return len;
}

/* FUNC(zx_LEN_WO_ds_CanonicalizationMethod) */

/* Compute length of an element (and its subelements). The XML attributes
 * and elements are processed in wire order and no assumptions
 * are made about namespace prefixes. */

/* Called by: */
int zx_LEN_WO_ds_CanonicalizationMethod(struct zx_ctx* c, struct zx_ds_CanonicalizationMethod_s* x )
{
  struct zx_ns_s* pop_seen = 0;
  struct zx_elem_s* se MAYBE_UNUSED;
#if 1 /* NORMALMODE */
  int len = 1 + sizeof("CanonicalizationMethod")-1 + 1 + 2 + sizeof("CanonicalizationMethod")-1 + 1;
  
  if (x->gg.g.ns && x->gg.g.ns->prefix_len)
    len += (x->gg.g.ns->prefix_len + 1) * 2;
  if (c->inc_ns_len)
    len += zx_len_inc_ns(c, &pop_seen);
  len += zx_len_xmlns_if_not_seen(c, x->gg.g.ns, &pop_seen);

  len += zx_attr_wo_len(x->Algorithm, sizeof("Algorithm")-1);

#else
  /* root node has no begin tag */
  int len = 0;
#endif
  


  len += zx_len_wo_common(c, &x->gg); 
  zx_pop_seen(pop_seen);
  ENC_LEN_DEBUG(x, "ds:CanonicalizationMethod", len);
  return len;
}

/* FUNC(zx_ENC_SO_ds_CanonicalizationMethod) */

/* Render element into string. The XML attributes and elements are
 * processed in schema order. This is what you generally want for
 * rendering new data structure to a string. The wo pointers are not used. */

/* Called by: */
char* zx_ENC_SO_ds_CanonicalizationMethod(struct zx_ctx* c, struct zx_ds_CanonicalizationMethod_s* x, char* p )
{
  struct zx_elem_s* se MAYBE_UNUSED;
  ENC_LEN_DEBUG_BASE;
#if 1 /* NORMALMODE */
  struct zx_ns_s* pop_seen = 0;
  /* *** in simple_elem case should output ns prefix from ns node. */
  ZX_OUT_TAG(p, "<ds:CanonicalizationMethod");
  if (c->inc_ns)
    p = zx_enc_inc_ns(c, p, &pop_seen);
  p = zx_enc_xmlns_if_not_seen(c, p, zx_ns_tab+zx_xmlns_ix_ds, &pop_seen);

  p = zx_attr_so_enc(p, x->Algorithm, " Algorithm=\"", sizeof(" Algorithm=\"")-1);

  p = zx_enc_unknown_attrs(p, x->gg.any_attr);
#else
  /* root node has no begin tag */
#endif
  

  p = zx_enc_so_unknown_elems_and_content(c, p, &x->gg);
  
#if 1 /* NORMALMODE */
  ZX_OUT_CLOSE_TAG(p, "</ds:CanonicalizationMethod>");
  zx_pop_seen(pop_seen);
#else
  /* root node has no end tag either */
#endif
  ENC_LEN_DEBUG(x, "ds:CanonicalizationMethod", p-enc_base);
  return p;
}

/* FUNC(zx_ENC_WO_ds_CanonicalizationMethod) */

/* Render element into string. The XML attributes and elements are
 * processed in wire order by chasing wo pointers. This is what you want for
 * validating signatures on other people's XML documents. */

/* Called by: */
char* zx_ENC_WO_ds_CanonicalizationMethod(struct zx_ctx* c, struct zx_ds_CanonicalizationMethod_s* x, char* p )
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
  ZX_OUT_MEM(p, "CanonicalizationMethod", sizeof("CanonicalizationMethod")-1);
  qq = p;

  /* *** sort the namespaces */
  if (c->inc_ns)
    zx_add_inc_ns(c, &pop_seen);
  zx_add_xmlns_if_not_seen(c, x->gg.g.ns, &pop_seen);

  p = zx_enc_seen(p, pop_seen); 
  p = zx_attr_wo_enc(p, x->Algorithm, "Algorithm=\"", sizeof("Algorithm=\"")-1);

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
  ENC_LEN_DEBUG(x, "ds:CanonicalizationMethod", p-enc_base);
  return p;
}

/* FUNC(zx_EASY_ENC_SO_ds_CanonicalizationMethod) */

/* Called by: */
struct zx_str* zx_EASY_ENC_SO_ds_CanonicalizationMethod(struct zx_ctx* c, struct zx_ds_CanonicalizationMethod_s* x )
{
  int len;
  char* buf;
  c->ns_tab = ZX_ALLOC(c, sizeof(zx_ns_tab));
  memcpy(c->ns_tab, zx_ns_tab, sizeof(zx_ns_tab));
  len = zx_LEN_SO_ds_CanonicalizationMethod(c, x );
  buf = ZX_ALLOC(c, len+1);
  return zx_easy_enc_common(c, zx_ENC_SO_ds_CanonicalizationMethod(c, x, buf ), buf, len);
}

/* FUNC(zx_EASY_ENC_WO_ds_CanonicalizationMethod) */

/* Called by: */
struct zx_str* zx_EASY_ENC_WO_ds_CanonicalizationMethod(struct zx_ctx* c, struct zx_ds_CanonicalizationMethod_s* x )
{
  int len;
  char* buf;
  c->ns_tab = ZX_ALLOC(c, sizeof(zx_ns_tab));
  memcpy(c->ns_tab, zx_ns_tab, sizeof(zx_ns_tab));
  len = zx_LEN_WO_ds_CanonicalizationMethod(c, x );
  buf = ZX_ALLOC(c, len+1);
  return zx_easy_enc_common(c, zx_ENC_WO_ds_CanonicalizationMethod(c, x, buf ), buf, len);
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

#define EL_NAME   ds_DSAKeyValue
#define EL_STRUCT zx_ds_DSAKeyValue_s
#define EL_NS     ds
#define EL_TAG    DSAKeyValue

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

/* FUNC(zx_LEN_SO_ds_DSAKeyValue) */

/* Compute length of an element (and its subelements). The XML attributes
 * and elements are processed in schema order. */

/* Called by: */
int zx_LEN_SO_ds_DSAKeyValue(struct zx_ctx* c, struct zx_ds_DSAKeyValue_s* x )
{
  struct zx_ns_s* pop_seen = 0;
  struct zx_elem_s* se MAYBE_UNUSED;
#if 1 /* NORMALMODE */
  /* *** in simple_elem case should output ns prefix from ns node. */
  int len = sizeof("<ds:DSAKeyValue")-1 + 1 + sizeof("</ds:DSAKeyValue>")-1;
  if (c->inc_ns_len)
    len += zx_len_inc_ns(c, &pop_seen);
  len += zx_len_xmlns_if_not_seen(c, zx_ns_tab+zx_xmlns_ix_ds, &pop_seen);


#else
  /* root node has no begin tag */
  int len = 0;
#endif
  
  for (se = x->P; se; se = (struct zx_elem_s*)se->g.n)
    len += zx_LEN_SO_simple_elem(c,se, sizeof("ds:P")-1, zx_ns_tab+zx_xmlns_ix_ds);
  for (se = x->Q; se; se = (struct zx_elem_s*)se->g.n)
    len += zx_LEN_SO_simple_elem(c,se, sizeof("ds:Q")-1, zx_ns_tab+zx_xmlns_ix_ds);
  for (se = x->G; se; se = (struct zx_elem_s*)se->g.n)
    len += zx_LEN_SO_simple_elem(c,se, sizeof("ds:G")-1, zx_ns_tab+zx_xmlns_ix_ds);
  for (se = x->Y; se; se = (struct zx_elem_s*)se->g.n)
    len += zx_LEN_SO_simple_elem(c,se, sizeof("ds:Y")-1, zx_ns_tab+zx_xmlns_ix_ds);
  for (se = x->J; se; se = (struct zx_elem_s*)se->g.n)
    len += zx_LEN_SO_simple_elem(c,se, sizeof("ds:J")-1, zx_ns_tab+zx_xmlns_ix_ds);
  for (se = x->Seed; se; se = (struct zx_elem_s*)se->g.n)
    len += zx_LEN_SO_simple_elem(c,se, sizeof("ds:Seed")-1, zx_ns_tab+zx_xmlns_ix_ds);
  for (se = x->PgenCounter; se; se = (struct zx_elem_s*)se->g.n)
    len += zx_LEN_SO_simple_elem(c,se, sizeof("ds:PgenCounter")-1, zx_ns_tab+zx_xmlns_ix_ds);


  len += zx_len_so_common(c, &x->gg);
  zx_pop_seen(pop_seen);
  ENC_LEN_DEBUG(x, "ds:DSAKeyValue", len);
  return len;
}

/* FUNC(zx_LEN_WO_ds_DSAKeyValue) */

/* Compute length of an element (and its subelements). The XML attributes
 * and elements are processed in wire order and no assumptions
 * are made about namespace prefixes. */

/* Called by: */
int zx_LEN_WO_ds_DSAKeyValue(struct zx_ctx* c, struct zx_ds_DSAKeyValue_s* x )
{
  struct zx_ns_s* pop_seen = 0;
  struct zx_elem_s* se MAYBE_UNUSED;
#if 1 /* NORMALMODE */
  int len = 1 + sizeof("DSAKeyValue")-1 + 1 + 2 + sizeof("DSAKeyValue")-1 + 1;
  
  if (x->gg.g.ns && x->gg.g.ns->prefix_len)
    len += (x->gg.g.ns->prefix_len + 1) * 2;
  if (c->inc_ns_len)
    len += zx_len_inc_ns(c, &pop_seen);
  len += zx_len_xmlns_if_not_seen(c, x->gg.g.ns, &pop_seen);


#else
  /* root node has no begin tag */
  int len = 0;
#endif
  
  for (se = x->P; se; se = (struct zx_elem_s*)se->g.n)
    len += zx_LEN_WO_simple_elem(c, se, sizeof("P")-1);
  for (se = x->Q; se; se = (struct zx_elem_s*)se->g.n)
    len += zx_LEN_WO_simple_elem(c, se, sizeof("Q")-1);
  for (se = x->G; se; se = (struct zx_elem_s*)se->g.n)
    len += zx_LEN_WO_simple_elem(c, se, sizeof("G")-1);
  for (se = x->Y; se; se = (struct zx_elem_s*)se->g.n)
    len += zx_LEN_WO_simple_elem(c, se, sizeof("Y")-1);
  for (se = x->J; se; se = (struct zx_elem_s*)se->g.n)
    len += zx_LEN_WO_simple_elem(c, se, sizeof("J")-1);
  for (se = x->Seed; se; se = (struct zx_elem_s*)se->g.n)
    len += zx_LEN_WO_simple_elem(c, se, sizeof("Seed")-1);
  for (se = x->PgenCounter; se; se = (struct zx_elem_s*)se->g.n)
    len += zx_LEN_WO_simple_elem(c, se, sizeof("PgenCounter")-1);


  len += zx_len_wo_common(c, &x->gg); 
  zx_pop_seen(pop_seen);
  ENC_LEN_DEBUG(x, "ds:DSAKeyValue", len);
  return len;
}

/* FUNC(zx_ENC_SO_ds_DSAKeyValue) */

/* Render element into string. The XML attributes and elements are
 * processed in schema order. This is what you generally want for
 * rendering new data structure to a string. The wo pointers are not used. */

/* Called by: */
char* zx_ENC_SO_ds_DSAKeyValue(struct zx_ctx* c, struct zx_ds_DSAKeyValue_s* x, char* p )
{
  struct zx_elem_s* se MAYBE_UNUSED;
  ENC_LEN_DEBUG_BASE;
#if 1 /* NORMALMODE */
  struct zx_ns_s* pop_seen = 0;
  /* *** in simple_elem case should output ns prefix from ns node. */
  ZX_OUT_TAG(p, "<ds:DSAKeyValue");
  if (c->inc_ns)
    p = zx_enc_inc_ns(c, p, &pop_seen);
  p = zx_enc_xmlns_if_not_seen(c, p, zx_ns_tab+zx_xmlns_ix_ds, &pop_seen);


  p = zx_enc_unknown_attrs(p, x->gg.any_attr);
#else
  /* root node has no begin tag */
#endif
  
  for (se = x->P; se; se = (struct zx_elem_s*)se->g.n)
    p = zx_ENC_SO_simple_elem(c, se, p, "ds:P", sizeof("ds:P")-1, zx_ns_tab+zx_xmlns_ix_ds);
  for (se = x->Q; se; se = (struct zx_elem_s*)se->g.n)
    p = zx_ENC_SO_simple_elem(c, se, p, "ds:Q", sizeof("ds:Q")-1, zx_ns_tab+zx_xmlns_ix_ds);
  for (se = x->G; se; se = (struct zx_elem_s*)se->g.n)
    p = zx_ENC_SO_simple_elem(c, se, p, "ds:G", sizeof("ds:G")-1, zx_ns_tab+zx_xmlns_ix_ds);
  for (se = x->Y; se; se = (struct zx_elem_s*)se->g.n)
    p = zx_ENC_SO_simple_elem(c, se, p, "ds:Y", sizeof("ds:Y")-1, zx_ns_tab+zx_xmlns_ix_ds);
  for (se = x->J; se; se = (struct zx_elem_s*)se->g.n)
    p = zx_ENC_SO_simple_elem(c, se, p, "ds:J", sizeof("ds:J")-1, zx_ns_tab+zx_xmlns_ix_ds);
  for (se = x->Seed; se; se = (struct zx_elem_s*)se->g.n)
    p = zx_ENC_SO_simple_elem(c, se, p, "ds:Seed", sizeof("ds:Seed")-1, zx_ns_tab+zx_xmlns_ix_ds);
  for (se = x->PgenCounter; se; se = (struct zx_elem_s*)se->g.n)
    p = zx_ENC_SO_simple_elem(c, se, p, "ds:PgenCounter", sizeof("ds:PgenCounter")-1, zx_ns_tab+zx_xmlns_ix_ds);

  p = zx_enc_so_unknown_elems_and_content(c, p, &x->gg);
  
#if 1 /* NORMALMODE */
  ZX_OUT_CLOSE_TAG(p, "</ds:DSAKeyValue>");
  zx_pop_seen(pop_seen);
#else
  /* root node has no end tag either */
#endif
  ENC_LEN_DEBUG(x, "ds:DSAKeyValue", p-enc_base);
  return p;
}

/* FUNC(zx_ENC_WO_ds_DSAKeyValue) */

/* Render element into string. The XML attributes and elements are
 * processed in wire order by chasing wo pointers. This is what you want for
 * validating signatures on other people's XML documents. */

/* Called by: */
char* zx_ENC_WO_ds_DSAKeyValue(struct zx_ctx* c, struct zx_ds_DSAKeyValue_s* x, char* p )
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
  ZX_OUT_MEM(p, "DSAKeyValue", sizeof("DSAKeyValue")-1);
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
  ENC_LEN_DEBUG(x, "ds:DSAKeyValue", p-enc_base);
  return p;
}

/* FUNC(zx_EASY_ENC_SO_ds_DSAKeyValue) */

/* Called by: */
struct zx_str* zx_EASY_ENC_SO_ds_DSAKeyValue(struct zx_ctx* c, struct zx_ds_DSAKeyValue_s* x )
{
  int len;
  char* buf;
  c->ns_tab = ZX_ALLOC(c, sizeof(zx_ns_tab));
  memcpy(c->ns_tab, zx_ns_tab, sizeof(zx_ns_tab));
  len = zx_LEN_SO_ds_DSAKeyValue(c, x );
  buf = ZX_ALLOC(c, len+1);
  return zx_easy_enc_common(c, zx_ENC_SO_ds_DSAKeyValue(c, x, buf ), buf, len);
}

/* FUNC(zx_EASY_ENC_WO_ds_DSAKeyValue) */

/* Called by: */
struct zx_str* zx_EASY_ENC_WO_ds_DSAKeyValue(struct zx_ctx* c, struct zx_ds_DSAKeyValue_s* x )
{
  int len;
  char* buf;
  c->ns_tab = ZX_ALLOC(c, sizeof(zx_ns_tab));
  memcpy(c->ns_tab, zx_ns_tab, sizeof(zx_ns_tab));
  len = zx_LEN_WO_ds_DSAKeyValue(c, x );
  buf = ZX_ALLOC(c, len+1);
  return zx_easy_enc_common(c, zx_ENC_WO_ds_DSAKeyValue(c, x, buf ), buf, len);
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

#define EL_NAME   ds_DigestMethod
#define EL_STRUCT zx_ds_DigestMethod_s
#define EL_NS     ds
#define EL_TAG    DigestMethod

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

/* FUNC(zx_LEN_SO_ds_DigestMethod) */

/* Compute length of an element (and its subelements). The XML attributes
 * and elements are processed in schema order. */

/* Called by: */
int zx_LEN_SO_ds_DigestMethod(struct zx_ctx* c, struct zx_ds_DigestMethod_s* x )
{
  struct zx_ns_s* pop_seen = 0;
  struct zx_elem_s* se MAYBE_UNUSED;
#if 1 /* NORMALMODE */
  /* *** in simple_elem case should output ns prefix from ns node. */
  int len = sizeof("<ds:DigestMethod")-1 + 1 + sizeof("</ds:DigestMethod>")-1;
  if (c->inc_ns_len)
    len += zx_len_inc_ns(c, &pop_seen);
  len += zx_len_xmlns_if_not_seen(c, zx_ns_tab+zx_xmlns_ix_ds, &pop_seen);

  len += zx_attr_so_len(x->Algorithm, sizeof("Algorithm")-1);

#else
  /* root node has no begin tag */
  int len = 0;
#endif
  


  len += zx_len_so_common(c, &x->gg);
  zx_pop_seen(pop_seen);
  ENC_LEN_DEBUG(x, "ds:DigestMethod", len);
  return len;
}

/* FUNC(zx_LEN_WO_ds_DigestMethod) */

/* Compute length of an element (and its subelements). The XML attributes
 * and elements are processed in wire order and no assumptions
 * are made about namespace prefixes. */

/* Called by: */
int zx_LEN_WO_ds_DigestMethod(struct zx_ctx* c, struct zx_ds_DigestMethod_s* x )
{
  struct zx_ns_s* pop_seen = 0;
  struct zx_elem_s* se MAYBE_UNUSED;
#if 1 /* NORMALMODE */
  int len = 1 + sizeof("DigestMethod")-1 + 1 + 2 + sizeof("DigestMethod")-1 + 1;
  
  if (x->gg.g.ns && x->gg.g.ns->prefix_len)
    len += (x->gg.g.ns->prefix_len + 1) * 2;
  if (c->inc_ns_len)
    len += zx_len_inc_ns(c, &pop_seen);
  len += zx_len_xmlns_if_not_seen(c, x->gg.g.ns, &pop_seen);

  len += zx_attr_wo_len(x->Algorithm, sizeof("Algorithm")-1);

#else
  /* root node has no begin tag */
  int len = 0;
#endif
  


  len += zx_len_wo_common(c, &x->gg); 
  zx_pop_seen(pop_seen);
  ENC_LEN_DEBUG(x, "ds:DigestMethod", len);
  return len;
}

/* FUNC(zx_ENC_SO_ds_DigestMethod) */

/* Render element into string. The XML attributes and elements are
 * processed in schema order. This is what you generally want for
 * rendering new data structure to a string. The wo pointers are not used. */

/* Called by: */
char* zx_ENC_SO_ds_DigestMethod(struct zx_ctx* c, struct zx_ds_DigestMethod_s* x, char* p )
{
  struct zx_elem_s* se MAYBE_UNUSED;
  ENC_LEN_DEBUG_BASE;
#if 1 /* NORMALMODE */
  struct zx_ns_s* pop_seen = 0;
  /* *** in simple_elem case should output ns prefix from ns node. */
  ZX_OUT_TAG(p, "<ds:DigestMethod");
  if (c->inc_ns)
    p = zx_enc_inc_ns(c, p, &pop_seen);
  p = zx_enc_xmlns_if_not_seen(c, p, zx_ns_tab+zx_xmlns_ix_ds, &pop_seen);

  p = zx_attr_so_enc(p, x->Algorithm, " Algorithm=\"", sizeof(" Algorithm=\"")-1);

  p = zx_enc_unknown_attrs(p, x->gg.any_attr);
#else
  /* root node has no begin tag */
#endif
  

  p = zx_enc_so_unknown_elems_and_content(c, p, &x->gg);
  
#if 1 /* NORMALMODE */
  ZX_OUT_CLOSE_TAG(p, "</ds:DigestMethod>");
  zx_pop_seen(pop_seen);
#else
  /* root node has no end tag either */
#endif
  ENC_LEN_DEBUG(x, "ds:DigestMethod", p-enc_base);
  return p;
}

/* FUNC(zx_ENC_WO_ds_DigestMethod) */

/* Render element into string. The XML attributes and elements are
 * processed in wire order by chasing wo pointers. This is what you want for
 * validating signatures on other people's XML documents. */

/* Called by: */
char* zx_ENC_WO_ds_DigestMethod(struct zx_ctx* c, struct zx_ds_DigestMethod_s* x, char* p )
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
  ZX_OUT_MEM(p, "DigestMethod", sizeof("DigestMethod")-1);
  qq = p;

  /* *** sort the namespaces */
  if (c->inc_ns)
    zx_add_inc_ns(c, &pop_seen);
  zx_add_xmlns_if_not_seen(c, x->gg.g.ns, &pop_seen);

  p = zx_enc_seen(p, pop_seen); 
  p = zx_attr_wo_enc(p, x->Algorithm, "Algorithm=\"", sizeof("Algorithm=\"")-1);

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
  ENC_LEN_DEBUG(x, "ds:DigestMethod", p-enc_base);
  return p;
}

/* FUNC(zx_EASY_ENC_SO_ds_DigestMethod) */

/* Called by: */
struct zx_str* zx_EASY_ENC_SO_ds_DigestMethod(struct zx_ctx* c, struct zx_ds_DigestMethod_s* x )
{
  int len;
  char* buf;
  c->ns_tab = ZX_ALLOC(c, sizeof(zx_ns_tab));
  memcpy(c->ns_tab, zx_ns_tab, sizeof(zx_ns_tab));
  len = zx_LEN_SO_ds_DigestMethod(c, x );
  buf = ZX_ALLOC(c, len+1);
  return zx_easy_enc_common(c, zx_ENC_SO_ds_DigestMethod(c, x, buf ), buf, len);
}

/* FUNC(zx_EASY_ENC_WO_ds_DigestMethod) */

/* Called by: */
struct zx_str* zx_EASY_ENC_WO_ds_DigestMethod(struct zx_ctx* c, struct zx_ds_DigestMethod_s* x )
{
  int len;
  char* buf;
  c->ns_tab = ZX_ALLOC(c, sizeof(zx_ns_tab));
  memcpy(c->ns_tab, zx_ns_tab, sizeof(zx_ns_tab));
  len = zx_LEN_WO_ds_DigestMethod(c, x );
  buf = ZX_ALLOC(c, len+1);
  return zx_easy_enc_common(c, zx_ENC_WO_ds_DigestMethod(c, x, buf ), buf, len);
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

#define EL_NAME   ds_KeyInfo
#define EL_STRUCT zx_ds_KeyInfo_s
#define EL_NS     ds
#define EL_TAG    KeyInfo

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

/* FUNC(zx_LEN_SO_ds_KeyInfo) */

/* Compute length of an element (and its subelements). The XML attributes
 * and elements are processed in schema order. */

/* Called by: */
int zx_LEN_SO_ds_KeyInfo(struct zx_ctx* c, struct zx_ds_KeyInfo_s* x )
{
  struct zx_ns_s* pop_seen = 0;
  struct zx_elem_s* se MAYBE_UNUSED;
#if 1 /* NORMALMODE */
  /* *** in simple_elem case should output ns prefix from ns node. */
  int len = sizeof("<ds:KeyInfo")-1 + 1 + sizeof("</ds:KeyInfo>")-1;
  if (c->inc_ns_len)
    len += zx_len_inc_ns(c, &pop_seen);
  len += zx_len_xmlns_if_not_seen(c, zx_ns_tab+zx_xmlns_ix_ds, &pop_seen);

  len += zx_attr_so_len(x->Id, sizeof("Id")-1);

#else
  /* root node has no begin tag */
  int len = 0;
#endif
  
  for (se = x->KeyName; se; se = (struct zx_elem_s*)se->g.n)
    len += zx_LEN_SO_simple_elem(c,se, sizeof("ds:KeyName")-1, zx_ns_tab+zx_xmlns_ix_ds);
  {
      struct zx_ds_KeyValue_s* e;
      for (e = x->KeyValue; e; e = (struct zx_ds_KeyValue_s*)e->gg.g.n)
	  len += zx_LEN_SO_ds_KeyValue(c, e);
  }
  {
      struct zx_ds_RetrievalMethod_s* e;
      for (e = x->RetrievalMethod; e; e = (struct zx_ds_RetrievalMethod_s*)e->gg.g.n)
	  len += zx_LEN_SO_ds_RetrievalMethod(c, e);
  }
  {
      struct zx_ds_X509Data_s* e;
      for (e = x->X509Data; e; e = (struct zx_ds_X509Data_s*)e->gg.g.n)
	  len += zx_LEN_SO_ds_X509Data(c, e);
  }
  {
      struct zx_ds_PGPData_s* e;
      for (e = x->PGPData; e; e = (struct zx_ds_PGPData_s*)e->gg.g.n)
	  len += zx_LEN_SO_ds_PGPData(c, e);
  }
  {
      struct zx_ds_SPKIData_s* e;
      for (e = x->SPKIData; e; e = (struct zx_ds_SPKIData_s*)e->gg.g.n)
	  len += zx_LEN_SO_ds_SPKIData(c, e);
  }
  for (se = x->MgmtData; se; se = (struct zx_elem_s*)se->g.n)
    len += zx_LEN_SO_simple_elem(c,se, sizeof("ds:MgmtData")-1, zx_ns_tab+zx_xmlns_ix_ds);
  {
      struct zx_xenc_EncryptedKey_s* e;
      for (e = x->EncryptedKey; e; e = (struct zx_xenc_EncryptedKey_s*)e->gg.g.n)
	  len += zx_LEN_SO_xenc_EncryptedKey(c, e);
  }


  len += zx_len_so_common(c, &x->gg);
  zx_pop_seen(pop_seen);
  ENC_LEN_DEBUG(x, "ds:KeyInfo", len);
  return len;
}

/* FUNC(zx_LEN_WO_ds_KeyInfo) */

/* Compute length of an element (and its subelements). The XML attributes
 * and elements are processed in wire order and no assumptions
 * are made about namespace prefixes. */

/* Called by: */
int zx_LEN_WO_ds_KeyInfo(struct zx_ctx* c, struct zx_ds_KeyInfo_s* x )
{
  struct zx_ns_s* pop_seen = 0;
  struct zx_elem_s* se MAYBE_UNUSED;
#if 1 /* NORMALMODE */
  int len = 1 + sizeof("KeyInfo")-1 + 1 + 2 + sizeof("KeyInfo")-1 + 1;
  
  if (x->gg.g.ns && x->gg.g.ns->prefix_len)
    len += (x->gg.g.ns->prefix_len + 1) * 2;
  if (c->inc_ns_len)
    len += zx_len_inc_ns(c, &pop_seen);
  len += zx_len_xmlns_if_not_seen(c, x->gg.g.ns, &pop_seen);

  len += zx_attr_wo_len(x->Id, sizeof("Id")-1);

#else
  /* root node has no begin tag */
  int len = 0;
#endif
  
  for (se = x->KeyName; se; se = (struct zx_elem_s*)se->g.n)
    len += zx_LEN_WO_simple_elem(c, se, sizeof("KeyName")-1);
  {
      struct zx_ds_KeyValue_s* e;
      for (e = x->KeyValue; e; e = (struct zx_ds_KeyValue_s*)e->gg.g.n)
	  len += zx_LEN_WO_ds_KeyValue(c, e);
  }
  {
      struct zx_ds_RetrievalMethod_s* e;
      for (e = x->RetrievalMethod; e; e = (struct zx_ds_RetrievalMethod_s*)e->gg.g.n)
	  len += zx_LEN_WO_ds_RetrievalMethod(c, e);
  }
  {
      struct zx_ds_X509Data_s* e;
      for (e = x->X509Data; e; e = (struct zx_ds_X509Data_s*)e->gg.g.n)
	  len += zx_LEN_WO_ds_X509Data(c, e);
  }
  {
      struct zx_ds_PGPData_s* e;
      for (e = x->PGPData; e; e = (struct zx_ds_PGPData_s*)e->gg.g.n)
	  len += zx_LEN_WO_ds_PGPData(c, e);
  }
  {
      struct zx_ds_SPKIData_s* e;
      for (e = x->SPKIData; e; e = (struct zx_ds_SPKIData_s*)e->gg.g.n)
	  len += zx_LEN_WO_ds_SPKIData(c, e);
  }
  for (se = x->MgmtData; se; se = (struct zx_elem_s*)se->g.n)
    len += zx_LEN_WO_simple_elem(c, se, sizeof("MgmtData")-1);
  {
      struct zx_xenc_EncryptedKey_s* e;
      for (e = x->EncryptedKey; e; e = (struct zx_xenc_EncryptedKey_s*)e->gg.g.n)
	  len += zx_LEN_WO_xenc_EncryptedKey(c, e);
  }


  len += zx_len_wo_common(c, &x->gg); 
  zx_pop_seen(pop_seen);
  ENC_LEN_DEBUG(x, "ds:KeyInfo", len);
  return len;
}

/* FUNC(zx_ENC_SO_ds_KeyInfo) */

/* Render element into string. The XML attributes and elements are
 * processed in schema order. This is what you generally want for
 * rendering new data structure to a string. The wo pointers are not used. */

/* Called by: */
char* zx_ENC_SO_ds_KeyInfo(struct zx_ctx* c, struct zx_ds_KeyInfo_s* x, char* p )
{
  struct zx_elem_s* se MAYBE_UNUSED;
  ENC_LEN_DEBUG_BASE;
#if 1 /* NORMALMODE */
  struct zx_ns_s* pop_seen = 0;
  /* *** in simple_elem case should output ns prefix from ns node. */
  ZX_OUT_TAG(p, "<ds:KeyInfo");
  if (c->inc_ns)
    p = zx_enc_inc_ns(c, p, &pop_seen);
  p = zx_enc_xmlns_if_not_seen(c, p, zx_ns_tab+zx_xmlns_ix_ds, &pop_seen);

  p = zx_attr_so_enc(p, x->Id, " Id=\"", sizeof(" Id=\"")-1);

  p = zx_enc_unknown_attrs(p, x->gg.any_attr);
#else
  /* root node has no begin tag */
#endif
  
  for (se = x->KeyName; se; se = (struct zx_elem_s*)se->g.n)
    p = zx_ENC_SO_simple_elem(c, se, p, "ds:KeyName", sizeof("ds:KeyName")-1, zx_ns_tab+zx_xmlns_ix_ds);
  {
      struct zx_ds_KeyValue_s* e;
      for (e = x->KeyValue; e; e = (struct zx_ds_KeyValue_s*)e->gg.g.n)
	  p = zx_ENC_SO_ds_KeyValue(c, e, p);
  }
  {
      struct zx_ds_RetrievalMethod_s* e;
      for (e = x->RetrievalMethod; e; e = (struct zx_ds_RetrievalMethod_s*)e->gg.g.n)
	  p = zx_ENC_SO_ds_RetrievalMethod(c, e, p);
  }
  {
      struct zx_ds_X509Data_s* e;
      for (e = x->X509Data; e; e = (struct zx_ds_X509Data_s*)e->gg.g.n)
	  p = zx_ENC_SO_ds_X509Data(c, e, p);
  }
  {
      struct zx_ds_PGPData_s* e;
      for (e = x->PGPData; e; e = (struct zx_ds_PGPData_s*)e->gg.g.n)
	  p = zx_ENC_SO_ds_PGPData(c, e, p);
  }
  {
      struct zx_ds_SPKIData_s* e;
      for (e = x->SPKIData; e; e = (struct zx_ds_SPKIData_s*)e->gg.g.n)
	  p = zx_ENC_SO_ds_SPKIData(c, e, p);
  }
  for (se = x->MgmtData; se; se = (struct zx_elem_s*)se->g.n)
    p = zx_ENC_SO_simple_elem(c, se, p, "ds:MgmtData", sizeof("ds:MgmtData")-1, zx_ns_tab+zx_xmlns_ix_ds);
  {
      struct zx_xenc_EncryptedKey_s* e;
      for (e = x->EncryptedKey; e; e = (struct zx_xenc_EncryptedKey_s*)e->gg.g.n)
	  p = zx_ENC_SO_xenc_EncryptedKey(c, e, p);
  }

  p = zx_enc_so_unknown_elems_and_content(c, p, &x->gg);
  
#if 1 /* NORMALMODE */
  ZX_OUT_CLOSE_TAG(p, "</ds:KeyInfo>");
  zx_pop_seen(pop_seen);
#else
  /* root node has no end tag either */
#endif
  ENC_LEN_DEBUG(x, "ds:KeyInfo", p-enc_base);
  return p;
}

/* FUNC(zx_ENC_WO_ds_KeyInfo) */

/* Render element into string. The XML attributes and elements are
 * processed in wire order by chasing wo pointers. This is what you want for
 * validating signatures on other people's XML documents. */

/* Called by: */
char* zx_ENC_WO_ds_KeyInfo(struct zx_ctx* c, struct zx_ds_KeyInfo_s* x, char* p )
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
  ZX_OUT_MEM(p, "KeyInfo", sizeof("KeyInfo")-1);
  qq = p;

  /* *** sort the namespaces */
  if (c->inc_ns)
    zx_add_inc_ns(c, &pop_seen);
  zx_add_xmlns_if_not_seen(c, x->gg.g.ns, &pop_seen);

  p = zx_enc_seen(p, pop_seen); 
  p = zx_attr_wo_enc(p, x->Id, "Id=\"", sizeof("Id=\"")-1);

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
  ENC_LEN_DEBUG(x, "ds:KeyInfo", p-enc_base);
  return p;
}

/* FUNC(zx_EASY_ENC_SO_ds_KeyInfo) */

/* Called by: */
struct zx_str* zx_EASY_ENC_SO_ds_KeyInfo(struct zx_ctx* c, struct zx_ds_KeyInfo_s* x )
{
  int len;
  char* buf;
  c->ns_tab = ZX_ALLOC(c, sizeof(zx_ns_tab));
  memcpy(c->ns_tab, zx_ns_tab, sizeof(zx_ns_tab));
  len = zx_LEN_SO_ds_KeyInfo(c, x );
  buf = ZX_ALLOC(c, len+1);
  return zx_easy_enc_common(c, zx_ENC_SO_ds_KeyInfo(c, x, buf ), buf, len);
}

/* FUNC(zx_EASY_ENC_WO_ds_KeyInfo) */

/* Called by: */
struct zx_str* zx_EASY_ENC_WO_ds_KeyInfo(struct zx_ctx* c, struct zx_ds_KeyInfo_s* x )
{
  int len;
  char* buf;
  c->ns_tab = ZX_ALLOC(c, sizeof(zx_ns_tab));
  memcpy(c->ns_tab, zx_ns_tab, sizeof(zx_ns_tab));
  len = zx_LEN_WO_ds_KeyInfo(c, x );
  buf = ZX_ALLOC(c, len+1);
  return zx_easy_enc_common(c, zx_ENC_WO_ds_KeyInfo(c, x, buf ), buf, len);
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

#define EL_NAME   ds_KeyValue
#define EL_STRUCT zx_ds_KeyValue_s
#define EL_NS     ds
#define EL_TAG    KeyValue

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

/* FUNC(zx_LEN_SO_ds_KeyValue) */

/* Compute length of an element (and its subelements). The XML attributes
 * and elements are processed in schema order. */

/* Called by: */
int zx_LEN_SO_ds_KeyValue(struct zx_ctx* c, struct zx_ds_KeyValue_s* x )
{
  struct zx_ns_s* pop_seen = 0;
  struct zx_elem_s* se MAYBE_UNUSED;
#if 1 /* NORMALMODE */
  /* *** in simple_elem case should output ns prefix from ns node. */
  int len = sizeof("<ds:KeyValue")-1 + 1 + sizeof("</ds:KeyValue>")-1;
  if (c->inc_ns_len)
    len += zx_len_inc_ns(c, &pop_seen);
  len += zx_len_xmlns_if_not_seen(c, zx_ns_tab+zx_xmlns_ix_ds, &pop_seen);


#else
  /* root node has no begin tag */
  int len = 0;
#endif
  
  {
      struct zx_ds_DSAKeyValue_s* e;
      for (e = x->DSAKeyValue; e; e = (struct zx_ds_DSAKeyValue_s*)e->gg.g.n)
	  len += zx_LEN_SO_ds_DSAKeyValue(c, e);
  }
  {
      struct zx_ds_RSAKeyValue_s* e;
      for (e = x->RSAKeyValue; e; e = (struct zx_ds_RSAKeyValue_s*)e->gg.g.n)
	  len += zx_LEN_SO_ds_RSAKeyValue(c, e);
  }


  len += zx_len_so_common(c, &x->gg);
  zx_pop_seen(pop_seen);
  ENC_LEN_DEBUG(x, "ds:KeyValue", len);
  return len;
}

/* FUNC(zx_LEN_WO_ds_KeyValue) */

/* Compute length of an element (and its subelements). The XML attributes
 * and elements are processed in wire order and no assumptions
 * are made about namespace prefixes. */

/* Called by: */
int zx_LEN_WO_ds_KeyValue(struct zx_ctx* c, struct zx_ds_KeyValue_s* x )
{
  struct zx_ns_s* pop_seen = 0;
  struct zx_elem_s* se MAYBE_UNUSED;
#if 1 /* NORMALMODE */
  int len = 1 + sizeof("KeyValue")-1 + 1 + 2 + sizeof("KeyValue")-1 + 1;
  
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
      struct zx_ds_DSAKeyValue_s* e;
      for (e = x->DSAKeyValue; e; e = (struct zx_ds_DSAKeyValue_s*)e->gg.g.n)
	  len += zx_LEN_WO_ds_DSAKeyValue(c, e);
  }
  {
      struct zx_ds_RSAKeyValue_s* e;
      for (e = x->RSAKeyValue; e; e = (struct zx_ds_RSAKeyValue_s*)e->gg.g.n)
	  len += zx_LEN_WO_ds_RSAKeyValue(c, e);
  }


  len += zx_len_wo_common(c, &x->gg); 
  zx_pop_seen(pop_seen);
  ENC_LEN_DEBUG(x, "ds:KeyValue", len);
  return len;
}

/* FUNC(zx_ENC_SO_ds_KeyValue) */

/* Render element into string. The XML attributes and elements are
 * processed in schema order. This is what you generally want for
 * rendering new data structure to a string. The wo pointers are not used. */

/* Called by: */
char* zx_ENC_SO_ds_KeyValue(struct zx_ctx* c, struct zx_ds_KeyValue_s* x, char* p )
{
  struct zx_elem_s* se MAYBE_UNUSED;
  ENC_LEN_DEBUG_BASE;
#if 1 /* NORMALMODE */
  struct zx_ns_s* pop_seen = 0;
  /* *** in simple_elem case should output ns prefix from ns node. */
  ZX_OUT_TAG(p, "<ds:KeyValue");
  if (c->inc_ns)
    p = zx_enc_inc_ns(c, p, &pop_seen);
  p = zx_enc_xmlns_if_not_seen(c, p, zx_ns_tab+zx_xmlns_ix_ds, &pop_seen);


  p = zx_enc_unknown_attrs(p, x->gg.any_attr);
#else
  /* root node has no begin tag */
#endif
  
  {
      struct zx_ds_DSAKeyValue_s* e;
      for (e = x->DSAKeyValue; e; e = (struct zx_ds_DSAKeyValue_s*)e->gg.g.n)
	  p = zx_ENC_SO_ds_DSAKeyValue(c, e, p);
  }
  {
      struct zx_ds_RSAKeyValue_s* e;
      for (e = x->RSAKeyValue; e; e = (struct zx_ds_RSAKeyValue_s*)e->gg.g.n)
	  p = zx_ENC_SO_ds_RSAKeyValue(c, e, p);
  }

  p = zx_enc_so_unknown_elems_and_content(c, p, &x->gg);
  
#if 1 /* NORMALMODE */
  ZX_OUT_CLOSE_TAG(p, "</ds:KeyValue>");
  zx_pop_seen(pop_seen);
#else
  /* root node has no end tag either */
#endif
  ENC_LEN_DEBUG(x, "ds:KeyValue", p-enc_base);
  return p;
}

/* FUNC(zx_ENC_WO_ds_KeyValue) */

/* Render element into string. The XML attributes and elements are
 * processed in wire order by chasing wo pointers. This is what you want for
 * validating signatures on other people's XML documents. */

/* Called by: */
char* zx_ENC_WO_ds_KeyValue(struct zx_ctx* c, struct zx_ds_KeyValue_s* x, char* p )
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
  ZX_OUT_MEM(p, "KeyValue", sizeof("KeyValue")-1);
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
  ENC_LEN_DEBUG(x, "ds:KeyValue", p-enc_base);
  return p;
}

/* FUNC(zx_EASY_ENC_SO_ds_KeyValue) */

/* Called by: */
struct zx_str* zx_EASY_ENC_SO_ds_KeyValue(struct zx_ctx* c, struct zx_ds_KeyValue_s* x )
{
  int len;
  char* buf;
  c->ns_tab = ZX_ALLOC(c, sizeof(zx_ns_tab));
  memcpy(c->ns_tab, zx_ns_tab, sizeof(zx_ns_tab));
  len = zx_LEN_SO_ds_KeyValue(c, x );
  buf = ZX_ALLOC(c, len+1);
  return zx_easy_enc_common(c, zx_ENC_SO_ds_KeyValue(c, x, buf ), buf, len);
}

/* FUNC(zx_EASY_ENC_WO_ds_KeyValue) */

/* Called by: */
struct zx_str* zx_EASY_ENC_WO_ds_KeyValue(struct zx_ctx* c, struct zx_ds_KeyValue_s* x )
{
  int len;
  char* buf;
  c->ns_tab = ZX_ALLOC(c, sizeof(zx_ns_tab));
  memcpy(c->ns_tab, zx_ns_tab, sizeof(zx_ns_tab));
  len = zx_LEN_WO_ds_KeyValue(c, x );
  buf = ZX_ALLOC(c, len+1);
  return zx_easy_enc_common(c, zx_ENC_WO_ds_KeyValue(c, x, buf ), buf, len);
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

#define EL_NAME   ds_Manifest
#define EL_STRUCT zx_ds_Manifest_s
#define EL_NS     ds
#define EL_TAG    Manifest

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

/* FUNC(zx_LEN_SO_ds_Manifest) */

/* Compute length of an element (and its subelements). The XML attributes
 * and elements are processed in schema order. */

/* Called by: */
int zx_LEN_SO_ds_Manifest(struct zx_ctx* c, struct zx_ds_Manifest_s* x )
{
  struct zx_ns_s* pop_seen = 0;
  struct zx_elem_s* se MAYBE_UNUSED;
#if 1 /* NORMALMODE */
  /* *** in simple_elem case should output ns prefix from ns node. */
  int len = sizeof("<ds:Manifest")-1 + 1 + sizeof("</ds:Manifest>")-1;
  if (c->inc_ns_len)
    len += zx_len_inc_ns(c, &pop_seen);
  len += zx_len_xmlns_if_not_seen(c, zx_ns_tab+zx_xmlns_ix_ds, &pop_seen);

  len += zx_attr_so_len(x->Id, sizeof("Id")-1);

#else
  /* root node has no begin tag */
  int len = 0;
#endif
  
  {
      struct zx_ds_Reference_s* e;
      for (e = x->Reference; e; e = (struct zx_ds_Reference_s*)e->gg.g.n)
	  len += zx_LEN_SO_ds_Reference(c, e);
  }


  len += zx_len_so_common(c, &x->gg);
  zx_pop_seen(pop_seen);
  ENC_LEN_DEBUG(x, "ds:Manifest", len);
  return len;
}

/* FUNC(zx_LEN_WO_ds_Manifest) */

/* Compute length of an element (and its subelements). The XML attributes
 * and elements are processed in wire order and no assumptions
 * are made about namespace prefixes. */

/* Called by: */
int zx_LEN_WO_ds_Manifest(struct zx_ctx* c, struct zx_ds_Manifest_s* x )
{
  struct zx_ns_s* pop_seen = 0;
  struct zx_elem_s* se MAYBE_UNUSED;
#if 1 /* NORMALMODE */
  int len = 1 + sizeof("Manifest")-1 + 1 + 2 + sizeof("Manifest")-1 + 1;
  
  if (x->gg.g.ns && x->gg.g.ns->prefix_len)
    len += (x->gg.g.ns->prefix_len + 1) * 2;
  if (c->inc_ns_len)
    len += zx_len_inc_ns(c, &pop_seen);
  len += zx_len_xmlns_if_not_seen(c, x->gg.g.ns, &pop_seen);

  len += zx_attr_wo_len(x->Id, sizeof("Id")-1);

#else
  /* root node has no begin tag */
  int len = 0;
#endif
  
  {
      struct zx_ds_Reference_s* e;
      for (e = x->Reference; e; e = (struct zx_ds_Reference_s*)e->gg.g.n)
	  len += zx_LEN_WO_ds_Reference(c, e);
  }


  len += zx_len_wo_common(c, &x->gg); 
  zx_pop_seen(pop_seen);
  ENC_LEN_DEBUG(x, "ds:Manifest", len);
  return len;
}

/* FUNC(zx_ENC_SO_ds_Manifest) */

/* Render element into string. The XML attributes and elements are
 * processed in schema order. This is what you generally want for
 * rendering new data structure to a string. The wo pointers are not used. */

/* Called by: */
char* zx_ENC_SO_ds_Manifest(struct zx_ctx* c, struct zx_ds_Manifest_s* x, char* p )
{
  struct zx_elem_s* se MAYBE_UNUSED;
  ENC_LEN_DEBUG_BASE;
#if 1 /* NORMALMODE */
  struct zx_ns_s* pop_seen = 0;
  /* *** in simple_elem case should output ns prefix from ns node. */
  ZX_OUT_TAG(p, "<ds:Manifest");
  if (c->inc_ns)
    p = zx_enc_inc_ns(c, p, &pop_seen);
  p = zx_enc_xmlns_if_not_seen(c, p, zx_ns_tab+zx_xmlns_ix_ds, &pop_seen);

  p = zx_attr_so_enc(p, x->Id, " Id=\"", sizeof(" Id=\"")-1);

  p = zx_enc_unknown_attrs(p, x->gg.any_attr);
#else
  /* root node has no begin tag */
#endif
  
  {
      struct zx_ds_Reference_s* e;
      for (e = x->Reference; e; e = (struct zx_ds_Reference_s*)e->gg.g.n)
	  p = zx_ENC_SO_ds_Reference(c, e, p);
  }

  p = zx_enc_so_unknown_elems_and_content(c, p, &x->gg);
  
#if 1 /* NORMALMODE */
  ZX_OUT_CLOSE_TAG(p, "</ds:Manifest>");
  zx_pop_seen(pop_seen);
#else
  /* root node has no end tag either */
#endif
  ENC_LEN_DEBUG(x, "ds:Manifest", p-enc_base);
  return p;
}

/* FUNC(zx_ENC_WO_ds_Manifest) */

/* Render element into string. The XML attributes and elements are
 * processed in wire order by chasing wo pointers. This is what you want for
 * validating signatures on other people's XML documents. */

/* Called by: */
char* zx_ENC_WO_ds_Manifest(struct zx_ctx* c, struct zx_ds_Manifest_s* x, char* p )
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
  ZX_OUT_MEM(p, "Manifest", sizeof("Manifest")-1);
  qq = p;

  /* *** sort the namespaces */
  if (c->inc_ns)
    zx_add_inc_ns(c, &pop_seen);
  zx_add_xmlns_if_not_seen(c, x->gg.g.ns, &pop_seen);

  p = zx_enc_seen(p, pop_seen); 
  p = zx_attr_wo_enc(p, x->Id, "Id=\"", sizeof("Id=\"")-1);

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
  ENC_LEN_DEBUG(x, "ds:Manifest", p-enc_base);
  return p;
}

/* FUNC(zx_EASY_ENC_SO_ds_Manifest) */

/* Called by: */
struct zx_str* zx_EASY_ENC_SO_ds_Manifest(struct zx_ctx* c, struct zx_ds_Manifest_s* x )
{
  int len;
  char* buf;
  c->ns_tab = ZX_ALLOC(c, sizeof(zx_ns_tab));
  memcpy(c->ns_tab, zx_ns_tab, sizeof(zx_ns_tab));
  len = zx_LEN_SO_ds_Manifest(c, x );
  buf = ZX_ALLOC(c, len+1);
  return zx_easy_enc_common(c, zx_ENC_SO_ds_Manifest(c, x, buf ), buf, len);
}

/* FUNC(zx_EASY_ENC_WO_ds_Manifest) */

/* Called by: */
struct zx_str* zx_EASY_ENC_WO_ds_Manifest(struct zx_ctx* c, struct zx_ds_Manifest_s* x )
{
  int len;
  char* buf;
  c->ns_tab = ZX_ALLOC(c, sizeof(zx_ns_tab));
  memcpy(c->ns_tab, zx_ns_tab, sizeof(zx_ns_tab));
  len = zx_LEN_WO_ds_Manifest(c, x );
  buf = ZX_ALLOC(c, len+1);
  return zx_easy_enc_common(c, zx_ENC_WO_ds_Manifest(c, x, buf ), buf, len);
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

#define EL_NAME   ds_Object
#define EL_STRUCT zx_ds_Object_s
#define EL_NS     ds
#define EL_TAG    Object

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

/* FUNC(zx_LEN_SO_ds_Object) */

/* Compute length of an element (and its subelements). The XML attributes
 * and elements are processed in schema order. */

/* Called by: */
int zx_LEN_SO_ds_Object(struct zx_ctx* c, struct zx_ds_Object_s* x )
{
  struct zx_ns_s* pop_seen = 0;
  struct zx_elem_s* se MAYBE_UNUSED;
#if 1 /* NORMALMODE */
  /* *** in simple_elem case should output ns prefix from ns node. */
  int len = sizeof("<ds:Object")-1 + 1 + sizeof("</ds:Object>")-1;
  if (c->inc_ns_len)
    len += zx_len_inc_ns(c, &pop_seen);
  len += zx_len_xmlns_if_not_seen(c, zx_ns_tab+zx_xmlns_ix_ds, &pop_seen);

  len += zx_attr_so_len(x->Encoding, sizeof("Encoding")-1);
  len += zx_attr_so_len(x->Id, sizeof("Id")-1);
  len += zx_attr_so_len(x->MimeType, sizeof("MimeType")-1);

#else
  /* root node has no begin tag */
  int len = 0;
#endif
  


  len += zx_len_so_common(c, &x->gg);
  zx_pop_seen(pop_seen);
  ENC_LEN_DEBUG(x, "ds:Object", len);
  return len;
}

/* FUNC(zx_LEN_WO_ds_Object) */

/* Compute length of an element (and its subelements). The XML attributes
 * and elements are processed in wire order and no assumptions
 * are made about namespace prefixes. */

/* Called by: */
int zx_LEN_WO_ds_Object(struct zx_ctx* c, struct zx_ds_Object_s* x )
{
  struct zx_ns_s* pop_seen = 0;
  struct zx_elem_s* se MAYBE_UNUSED;
#if 1 /* NORMALMODE */
  int len = 1 + sizeof("Object")-1 + 1 + 2 + sizeof("Object")-1 + 1;
  
  if (x->gg.g.ns && x->gg.g.ns->prefix_len)
    len += (x->gg.g.ns->prefix_len + 1) * 2;
  if (c->inc_ns_len)
    len += zx_len_inc_ns(c, &pop_seen);
  len += zx_len_xmlns_if_not_seen(c, x->gg.g.ns, &pop_seen);

  len += zx_attr_wo_len(x->Encoding, sizeof("Encoding")-1);
  len += zx_attr_wo_len(x->Id, sizeof("Id")-1);
  len += zx_attr_wo_len(x->MimeType, sizeof("MimeType")-1);

#else
  /* root node has no begin tag */
  int len = 0;
#endif
  


  len += zx_len_wo_common(c, &x->gg); 
  zx_pop_seen(pop_seen);
  ENC_LEN_DEBUG(x, "ds:Object", len);
  return len;
}

/* FUNC(zx_ENC_SO_ds_Object) */

/* Render element into string. The XML attributes and elements are
 * processed in schema order. This is what you generally want for
 * rendering new data structure to a string. The wo pointers are not used. */

/* Called by: */
char* zx_ENC_SO_ds_Object(struct zx_ctx* c, struct zx_ds_Object_s* x, char* p )
{
  struct zx_elem_s* se MAYBE_UNUSED;
  ENC_LEN_DEBUG_BASE;
#if 1 /* NORMALMODE */
  struct zx_ns_s* pop_seen = 0;
  /* *** in simple_elem case should output ns prefix from ns node. */
  ZX_OUT_TAG(p, "<ds:Object");
  if (c->inc_ns)
    p = zx_enc_inc_ns(c, p, &pop_seen);
  p = zx_enc_xmlns_if_not_seen(c, p, zx_ns_tab+zx_xmlns_ix_ds, &pop_seen);

  p = zx_attr_so_enc(p, x->Encoding, " Encoding=\"", sizeof(" Encoding=\"")-1);
  p = zx_attr_so_enc(p, x->Id, " Id=\"", sizeof(" Id=\"")-1);
  p = zx_attr_so_enc(p, x->MimeType, " MimeType=\"", sizeof(" MimeType=\"")-1);

  p = zx_enc_unknown_attrs(p, x->gg.any_attr);
#else
  /* root node has no begin tag */
#endif
  

  p = zx_enc_so_unknown_elems_and_content(c, p, &x->gg);
  
#if 1 /* NORMALMODE */
  ZX_OUT_CLOSE_TAG(p, "</ds:Object>");
  zx_pop_seen(pop_seen);
#else
  /* root node has no end tag either */
#endif
  ENC_LEN_DEBUG(x, "ds:Object", p-enc_base);
  return p;
}

/* FUNC(zx_ENC_WO_ds_Object) */

/* Render element into string. The XML attributes and elements are
 * processed in wire order by chasing wo pointers. This is what you want for
 * validating signatures on other people's XML documents. */

/* Called by: */
char* zx_ENC_WO_ds_Object(struct zx_ctx* c, struct zx_ds_Object_s* x, char* p )
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
  ZX_OUT_MEM(p, "Object", sizeof("Object")-1);
  qq = p;

  /* *** sort the namespaces */
  if (c->inc_ns)
    zx_add_inc_ns(c, &pop_seen);
  zx_add_xmlns_if_not_seen(c, x->gg.g.ns, &pop_seen);

  p = zx_enc_seen(p, pop_seen); 
  p = zx_attr_wo_enc(p, x->Encoding, "Encoding=\"", sizeof("Encoding=\"")-1);
  p = zx_attr_wo_enc(p, x->Id, "Id=\"", sizeof("Id=\"")-1);
  p = zx_attr_wo_enc(p, x->MimeType, "MimeType=\"", sizeof("MimeType=\"")-1);

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
  ENC_LEN_DEBUG(x, "ds:Object", p-enc_base);
  return p;
}

/* FUNC(zx_EASY_ENC_SO_ds_Object) */

/* Called by: */
struct zx_str* zx_EASY_ENC_SO_ds_Object(struct zx_ctx* c, struct zx_ds_Object_s* x )
{
  int len;
  char* buf;
  c->ns_tab = ZX_ALLOC(c, sizeof(zx_ns_tab));
  memcpy(c->ns_tab, zx_ns_tab, sizeof(zx_ns_tab));
  len = zx_LEN_SO_ds_Object(c, x );
  buf = ZX_ALLOC(c, len+1);
  return zx_easy_enc_common(c, zx_ENC_SO_ds_Object(c, x, buf ), buf, len);
}

/* FUNC(zx_EASY_ENC_WO_ds_Object) */

/* Called by: */
struct zx_str* zx_EASY_ENC_WO_ds_Object(struct zx_ctx* c, struct zx_ds_Object_s* x )
{
  int len;
  char* buf;
  c->ns_tab = ZX_ALLOC(c, sizeof(zx_ns_tab));
  memcpy(c->ns_tab, zx_ns_tab, sizeof(zx_ns_tab));
  len = zx_LEN_WO_ds_Object(c, x );
  buf = ZX_ALLOC(c, len+1);
  return zx_easy_enc_common(c, zx_ENC_WO_ds_Object(c, x, buf ), buf, len);
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

#define EL_NAME   ds_PGPData
#define EL_STRUCT zx_ds_PGPData_s
#define EL_NS     ds
#define EL_TAG    PGPData

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

/* FUNC(zx_LEN_SO_ds_PGPData) */

/* Compute length of an element (and its subelements). The XML attributes
 * and elements are processed in schema order. */

/* Called by: */
int zx_LEN_SO_ds_PGPData(struct zx_ctx* c, struct zx_ds_PGPData_s* x )
{
  struct zx_ns_s* pop_seen = 0;
  struct zx_elem_s* se MAYBE_UNUSED;
#if 1 /* NORMALMODE */
  /* *** in simple_elem case should output ns prefix from ns node. */
  int len = sizeof("<ds:PGPData")-1 + 1 + sizeof("</ds:PGPData>")-1;
  if (c->inc_ns_len)
    len += zx_len_inc_ns(c, &pop_seen);
  len += zx_len_xmlns_if_not_seen(c, zx_ns_tab+zx_xmlns_ix_ds, &pop_seen);


#else
  /* root node has no begin tag */
  int len = 0;
#endif
  
  for (se = x->PGPKeyID; se; se = (struct zx_elem_s*)se->g.n)
    len += zx_LEN_SO_simple_elem(c,se, sizeof("ds:PGPKeyID")-1, zx_ns_tab+zx_xmlns_ix_ds);
  for (se = x->PGPKeyPacket; se; se = (struct zx_elem_s*)se->g.n)
    len += zx_LEN_SO_simple_elem(c,se, sizeof("ds:PGPKeyPacket")-1, zx_ns_tab+zx_xmlns_ix_ds);


  len += zx_len_so_common(c, &x->gg);
  zx_pop_seen(pop_seen);
  ENC_LEN_DEBUG(x, "ds:PGPData", len);
  return len;
}

/* FUNC(zx_LEN_WO_ds_PGPData) */

/* Compute length of an element (and its subelements). The XML attributes
 * and elements are processed in wire order and no assumptions
 * are made about namespace prefixes. */

/* Called by: */
int zx_LEN_WO_ds_PGPData(struct zx_ctx* c, struct zx_ds_PGPData_s* x )
{
  struct zx_ns_s* pop_seen = 0;
  struct zx_elem_s* se MAYBE_UNUSED;
#if 1 /* NORMALMODE */
  int len = 1 + sizeof("PGPData")-1 + 1 + 2 + sizeof("PGPData")-1 + 1;
  
  if (x->gg.g.ns && x->gg.g.ns->prefix_len)
    len += (x->gg.g.ns->prefix_len + 1) * 2;
  if (c->inc_ns_len)
    len += zx_len_inc_ns(c, &pop_seen);
  len += zx_len_xmlns_if_not_seen(c, x->gg.g.ns, &pop_seen);


#else
  /* root node has no begin tag */
  int len = 0;
#endif
  
  for (se = x->PGPKeyID; se; se = (struct zx_elem_s*)se->g.n)
    len += zx_LEN_WO_simple_elem(c, se, sizeof("PGPKeyID")-1);
  for (se = x->PGPKeyPacket; se; se = (struct zx_elem_s*)se->g.n)
    len += zx_LEN_WO_simple_elem(c, se, sizeof("PGPKeyPacket")-1);


  len += zx_len_wo_common(c, &x->gg); 
  zx_pop_seen(pop_seen);
  ENC_LEN_DEBUG(x, "ds:PGPData", len);
  return len;
}

/* FUNC(zx_ENC_SO_ds_PGPData) */

/* Render element into string. The XML attributes and elements are
 * processed in schema order. This is what you generally want for
 * rendering new data structure to a string. The wo pointers are not used. */

/* Called by: */
char* zx_ENC_SO_ds_PGPData(struct zx_ctx* c, struct zx_ds_PGPData_s* x, char* p )
{
  struct zx_elem_s* se MAYBE_UNUSED;
  ENC_LEN_DEBUG_BASE;
#if 1 /* NORMALMODE */
  struct zx_ns_s* pop_seen = 0;
  /* *** in simple_elem case should output ns prefix from ns node. */
  ZX_OUT_TAG(p, "<ds:PGPData");
  if (c->inc_ns)
    p = zx_enc_inc_ns(c, p, &pop_seen);
  p = zx_enc_xmlns_if_not_seen(c, p, zx_ns_tab+zx_xmlns_ix_ds, &pop_seen);


  p = zx_enc_unknown_attrs(p, x->gg.any_attr);
#else
  /* root node has no begin tag */
#endif
  
  for (se = x->PGPKeyID; se; se = (struct zx_elem_s*)se->g.n)
    p = zx_ENC_SO_simple_elem(c, se, p, "ds:PGPKeyID", sizeof("ds:PGPKeyID")-1, zx_ns_tab+zx_xmlns_ix_ds);
  for (se = x->PGPKeyPacket; se; se = (struct zx_elem_s*)se->g.n)
    p = zx_ENC_SO_simple_elem(c, se, p, "ds:PGPKeyPacket", sizeof("ds:PGPKeyPacket")-1, zx_ns_tab+zx_xmlns_ix_ds);

  p = zx_enc_so_unknown_elems_and_content(c, p, &x->gg);
  
#if 1 /* NORMALMODE */
  ZX_OUT_CLOSE_TAG(p, "</ds:PGPData>");
  zx_pop_seen(pop_seen);
#else
  /* root node has no end tag either */
#endif
  ENC_LEN_DEBUG(x, "ds:PGPData", p-enc_base);
  return p;
}

/* FUNC(zx_ENC_WO_ds_PGPData) */

/* Render element into string. The XML attributes and elements are
 * processed in wire order by chasing wo pointers. This is what you want for
 * validating signatures on other people's XML documents. */

/* Called by: */
char* zx_ENC_WO_ds_PGPData(struct zx_ctx* c, struct zx_ds_PGPData_s* x, char* p )
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
  ZX_OUT_MEM(p, "PGPData", sizeof("PGPData")-1);
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
  ENC_LEN_DEBUG(x, "ds:PGPData", p-enc_base);
  return p;
}

/* FUNC(zx_EASY_ENC_SO_ds_PGPData) */

/* Called by: */
struct zx_str* zx_EASY_ENC_SO_ds_PGPData(struct zx_ctx* c, struct zx_ds_PGPData_s* x )
{
  int len;
  char* buf;
  c->ns_tab = ZX_ALLOC(c, sizeof(zx_ns_tab));
  memcpy(c->ns_tab, zx_ns_tab, sizeof(zx_ns_tab));
  len = zx_LEN_SO_ds_PGPData(c, x );
  buf = ZX_ALLOC(c, len+1);
  return zx_easy_enc_common(c, zx_ENC_SO_ds_PGPData(c, x, buf ), buf, len);
}

/* FUNC(zx_EASY_ENC_WO_ds_PGPData) */

/* Called by: */
struct zx_str* zx_EASY_ENC_WO_ds_PGPData(struct zx_ctx* c, struct zx_ds_PGPData_s* x )
{
  int len;
  char* buf;
  c->ns_tab = ZX_ALLOC(c, sizeof(zx_ns_tab));
  memcpy(c->ns_tab, zx_ns_tab, sizeof(zx_ns_tab));
  len = zx_LEN_WO_ds_PGPData(c, x );
  buf = ZX_ALLOC(c, len+1);
  return zx_easy_enc_common(c, zx_ENC_WO_ds_PGPData(c, x, buf ), buf, len);
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

#define EL_NAME   ds_RSAKeyValue
#define EL_STRUCT zx_ds_RSAKeyValue_s
#define EL_NS     ds
#define EL_TAG    RSAKeyValue

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

/* FUNC(zx_LEN_SO_ds_RSAKeyValue) */

/* Compute length of an element (and its subelements). The XML attributes
 * and elements are processed in schema order. */

/* Called by: */
int zx_LEN_SO_ds_RSAKeyValue(struct zx_ctx* c, struct zx_ds_RSAKeyValue_s* x )
{
  struct zx_ns_s* pop_seen = 0;
  struct zx_elem_s* se MAYBE_UNUSED;
#if 1 /* NORMALMODE */
  /* *** in simple_elem case should output ns prefix from ns node. */
  int len = sizeof("<ds:RSAKeyValue")-1 + 1 + sizeof("</ds:RSAKeyValue>")-1;
  if (c->inc_ns_len)
    len += zx_len_inc_ns(c, &pop_seen);
  len += zx_len_xmlns_if_not_seen(c, zx_ns_tab+zx_xmlns_ix_ds, &pop_seen);


#else
  /* root node has no begin tag */
  int len = 0;
#endif
  
  for (se = x->Modulus; se; se = (struct zx_elem_s*)se->g.n)
    len += zx_LEN_SO_simple_elem(c,se, sizeof("ds:Modulus")-1, zx_ns_tab+zx_xmlns_ix_ds);
  for (se = x->Exponent; se; se = (struct zx_elem_s*)se->g.n)
    len += zx_LEN_SO_simple_elem(c,se, sizeof("ds:Exponent")-1, zx_ns_tab+zx_xmlns_ix_ds);


  len += zx_len_so_common(c, &x->gg);
  zx_pop_seen(pop_seen);
  ENC_LEN_DEBUG(x, "ds:RSAKeyValue", len);
  return len;
}

/* FUNC(zx_LEN_WO_ds_RSAKeyValue) */

/* Compute length of an element (and its subelements). The XML attributes
 * and elements are processed in wire order and no assumptions
 * are made about namespace prefixes. */

/* Called by: */
int zx_LEN_WO_ds_RSAKeyValue(struct zx_ctx* c, struct zx_ds_RSAKeyValue_s* x )
{
  struct zx_ns_s* pop_seen = 0;
  struct zx_elem_s* se MAYBE_UNUSED;
#if 1 /* NORMALMODE */
  int len = 1 + sizeof("RSAKeyValue")-1 + 1 + 2 + sizeof("RSAKeyValue")-1 + 1;
  
  if (x->gg.g.ns && x->gg.g.ns->prefix_len)
    len += (x->gg.g.ns->prefix_len + 1) * 2;
  if (c->inc_ns_len)
    len += zx_len_inc_ns(c, &pop_seen);
  len += zx_len_xmlns_if_not_seen(c, x->gg.g.ns, &pop_seen);


#else
  /* root node has no begin tag */
  int len = 0;
#endif
  
  for (se = x->Modulus; se; se = (struct zx_elem_s*)se->g.n)
    len += zx_LEN_WO_simple_elem(c, se, sizeof("Modulus")-1);
  for (se = x->Exponent; se; se = (struct zx_elem_s*)se->g.n)
    len += zx_LEN_WO_simple_elem(c, se, sizeof("Exponent")-1);


  len += zx_len_wo_common(c, &x->gg); 
  zx_pop_seen(pop_seen);
  ENC_LEN_DEBUG(x, "ds:RSAKeyValue", len);
  return len;
}

/* FUNC(zx_ENC_SO_ds_RSAKeyValue) */

/* Render element into string. The XML attributes and elements are
 * processed in schema order. This is what you generally want for
 * rendering new data structure to a string. The wo pointers are not used. */

/* Called by: */
char* zx_ENC_SO_ds_RSAKeyValue(struct zx_ctx* c, struct zx_ds_RSAKeyValue_s* x, char* p )
{
  struct zx_elem_s* se MAYBE_UNUSED;
  ENC_LEN_DEBUG_BASE;
#if 1 /* NORMALMODE */
  struct zx_ns_s* pop_seen = 0;
  /* *** in simple_elem case should output ns prefix from ns node. */
  ZX_OUT_TAG(p, "<ds:RSAKeyValue");
  if (c->inc_ns)
    p = zx_enc_inc_ns(c, p, &pop_seen);
  p = zx_enc_xmlns_if_not_seen(c, p, zx_ns_tab+zx_xmlns_ix_ds, &pop_seen);


  p = zx_enc_unknown_attrs(p, x->gg.any_attr);
#else
  /* root node has no begin tag */
#endif
  
  for (se = x->Modulus; se; se = (struct zx_elem_s*)se->g.n)
    p = zx_ENC_SO_simple_elem(c, se, p, "ds:Modulus", sizeof("ds:Modulus")-1, zx_ns_tab+zx_xmlns_ix_ds);
  for (se = x->Exponent; se; se = (struct zx_elem_s*)se->g.n)
    p = zx_ENC_SO_simple_elem(c, se, p, "ds:Exponent", sizeof("ds:Exponent")-1, zx_ns_tab+zx_xmlns_ix_ds);

  p = zx_enc_so_unknown_elems_and_content(c, p, &x->gg);
  
#if 1 /* NORMALMODE */
  ZX_OUT_CLOSE_TAG(p, "</ds:RSAKeyValue>");
  zx_pop_seen(pop_seen);
#else
  /* root node has no end tag either */
#endif
  ENC_LEN_DEBUG(x, "ds:RSAKeyValue", p-enc_base);
  return p;
}

/* FUNC(zx_ENC_WO_ds_RSAKeyValue) */

/* Render element into string. The XML attributes and elements are
 * processed in wire order by chasing wo pointers. This is what you want for
 * validating signatures on other people's XML documents. */

/* Called by: */
char* zx_ENC_WO_ds_RSAKeyValue(struct zx_ctx* c, struct zx_ds_RSAKeyValue_s* x, char* p )
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
  ZX_OUT_MEM(p, "RSAKeyValue", sizeof("RSAKeyValue")-1);
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
  ENC_LEN_DEBUG(x, "ds:RSAKeyValue", p-enc_base);
  return p;
}

/* FUNC(zx_EASY_ENC_SO_ds_RSAKeyValue) */

/* Called by: */
struct zx_str* zx_EASY_ENC_SO_ds_RSAKeyValue(struct zx_ctx* c, struct zx_ds_RSAKeyValue_s* x )
{
  int len;
  char* buf;
  c->ns_tab = ZX_ALLOC(c, sizeof(zx_ns_tab));
  memcpy(c->ns_tab, zx_ns_tab, sizeof(zx_ns_tab));
  len = zx_LEN_SO_ds_RSAKeyValue(c, x );
  buf = ZX_ALLOC(c, len+1);
  return zx_easy_enc_common(c, zx_ENC_SO_ds_RSAKeyValue(c, x, buf ), buf, len);
}

/* FUNC(zx_EASY_ENC_WO_ds_RSAKeyValue) */

/* Called by: */
struct zx_str* zx_EASY_ENC_WO_ds_RSAKeyValue(struct zx_ctx* c, struct zx_ds_RSAKeyValue_s* x )
{
  int len;
  char* buf;
  c->ns_tab = ZX_ALLOC(c, sizeof(zx_ns_tab));
  memcpy(c->ns_tab, zx_ns_tab, sizeof(zx_ns_tab));
  len = zx_LEN_WO_ds_RSAKeyValue(c, x );
  buf = ZX_ALLOC(c, len+1);
  return zx_easy_enc_common(c, zx_ENC_WO_ds_RSAKeyValue(c, x, buf ), buf, len);
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

#define EL_NAME   ds_Reference
#define EL_STRUCT zx_ds_Reference_s
#define EL_NS     ds
#define EL_TAG    Reference

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

/* FUNC(zx_LEN_SO_ds_Reference) */

/* Compute length of an element (and its subelements). The XML attributes
 * and elements are processed in schema order. */

/* Called by: */
int zx_LEN_SO_ds_Reference(struct zx_ctx* c, struct zx_ds_Reference_s* x )
{
  struct zx_ns_s* pop_seen = 0;
  struct zx_elem_s* se MAYBE_UNUSED;
#if 1 /* NORMALMODE */
  /* *** in simple_elem case should output ns prefix from ns node. */
  int len = sizeof("<ds:Reference")-1 + 1 + sizeof("</ds:Reference>")-1;
  if (c->inc_ns_len)
    len += zx_len_inc_ns(c, &pop_seen);
  len += zx_len_xmlns_if_not_seen(c, zx_ns_tab+zx_xmlns_ix_ds, &pop_seen);

  len += zx_attr_so_len(x->Id, sizeof("Id")-1);
  len += zx_attr_so_len(x->Type, sizeof("Type")-1);
  len += zx_attr_so_len(x->URI, sizeof("URI")-1);

#else
  /* root node has no begin tag */
  int len = 0;
#endif
  
  {
      struct zx_ds_Transforms_s* e;
      for (e = x->Transforms; e; e = (struct zx_ds_Transforms_s*)e->gg.g.n)
	  len += zx_LEN_SO_ds_Transforms(c, e);
  }
  {
      struct zx_ds_DigestMethod_s* e;
      for (e = x->DigestMethod; e; e = (struct zx_ds_DigestMethod_s*)e->gg.g.n)
	  len += zx_LEN_SO_ds_DigestMethod(c, e);
  }
  for (se = x->DigestValue; se; se = (struct zx_elem_s*)se->g.n)
    len += zx_LEN_SO_simple_elem(c,se, sizeof("ds:DigestValue")-1, zx_ns_tab+zx_xmlns_ix_ds);


  len += zx_len_so_common(c, &x->gg);
  zx_pop_seen(pop_seen);
  ENC_LEN_DEBUG(x, "ds:Reference", len);
  return len;
}

/* FUNC(zx_LEN_WO_ds_Reference) */

/* Compute length of an element (and its subelements). The XML attributes
 * and elements are processed in wire order and no assumptions
 * are made about namespace prefixes. */

/* Called by: */
int zx_LEN_WO_ds_Reference(struct zx_ctx* c, struct zx_ds_Reference_s* x )
{
  struct zx_ns_s* pop_seen = 0;
  struct zx_elem_s* se MAYBE_UNUSED;
#if 1 /* NORMALMODE */
  int len = 1 + sizeof("Reference")-1 + 1 + 2 + sizeof("Reference")-1 + 1;
  
  if (x->gg.g.ns && x->gg.g.ns->prefix_len)
    len += (x->gg.g.ns->prefix_len + 1) * 2;
  if (c->inc_ns_len)
    len += zx_len_inc_ns(c, &pop_seen);
  len += zx_len_xmlns_if_not_seen(c, x->gg.g.ns, &pop_seen);

  len += zx_attr_wo_len(x->Id, sizeof("Id")-1);
  len += zx_attr_wo_len(x->Type, sizeof("Type")-1);
  len += zx_attr_wo_len(x->URI, sizeof("URI")-1);

#else
  /* root node has no begin tag */
  int len = 0;
#endif
  
  {
      struct zx_ds_Transforms_s* e;
      for (e = x->Transforms; e; e = (struct zx_ds_Transforms_s*)e->gg.g.n)
	  len += zx_LEN_WO_ds_Transforms(c, e);
  }
  {
      struct zx_ds_DigestMethod_s* e;
      for (e = x->DigestMethod; e; e = (struct zx_ds_DigestMethod_s*)e->gg.g.n)
	  len += zx_LEN_WO_ds_DigestMethod(c, e);
  }
  for (se = x->DigestValue; se; se = (struct zx_elem_s*)se->g.n)
    len += zx_LEN_WO_simple_elem(c, se, sizeof("DigestValue")-1);


  len += zx_len_wo_common(c, &x->gg); 
  zx_pop_seen(pop_seen);
  ENC_LEN_DEBUG(x, "ds:Reference", len);
  return len;
}

/* FUNC(zx_ENC_SO_ds_Reference) */

/* Render element into string. The XML attributes and elements are
 * processed in schema order. This is what you generally want for
 * rendering new data structure to a string. The wo pointers are not used. */

/* Called by: */
char* zx_ENC_SO_ds_Reference(struct zx_ctx* c, struct zx_ds_Reference_s* x, char* p )
{
  struct zx_elem_s* se MAYBE_UNUSED;
  ENC_LEN_DEBUG_BASE;
#if 1 /* NORMALMODE */
  struct zx_ns_s* pop_seen = 0;
  /* *** in simple_elem case should output ns prefix from ns node. */
  ZX_OUT_TAG(p, "<ds:Reference");
  if (c->inc_ns)
    p = zx_enc_inc_ns(c, p, &pop_seen);
  p = zx_enc_xmlns_if_not_seen(c, p, zx_ns_tab+zx_xmlns_ix_ds, &pop_seen);

  p = zx_attr_so_enc(p, x->Id, " Id=\"", sizeof(" Id=\"")-1);
  p = zx_attr_so_enc(p, x->Type, " Type=\"", sizeof(" Type=\"")-1);
  p = zx_attr_so_enc(p, x->URI, " URI=\"", sizeof(" URI=\"")-1);

  p = zx_enc_unknown_attrs(p, x->gg.any_attr);
#else
  /* root node has no begin tag */
#endif
  
  {
      struct zx_ds_Transforms_s* e;
      for (e = x->Transforms; e; e = (struct zx_ds_Transforms_s*)e->gg.g.n)
	  p = zx_ENC_SO_ds_Transforms(c, e, p);
  }
  {
      struct zx_ds_DigestMethod_s* e;
      for (e = x->DigestMethod; e; e = (struct zx_ds_DigestMethod_s*)e->gg.g.n)
	  p = zx_ENC_SO_ds_DigestMethod(c, e, p);
  }
  for (se = x->DigestValue; se; se = (struct zx_elem_s*)se->g.n)
    p = zx_ENC_SO_simple_elem(c, se, p, "ds:DigestValue", sizeof("ds:DigestValue")-1, zx_ns_tab+zx_xmlns_ix_ds);

  p = zx_enc_so_unknown_elems_and_content(c, p, &x->gg);
  
#if 1 /* NORMALMODE */
  ZX_OUT_CLOSE_TAG(p, "</ds:Reference>");
  zx_pop_seen(pop_seen);
#else
  /* root node has no end tag either */
#endif
  ENC_LEN_DEBUG(x, "ds:Reference", p-enc_base);
  return p;
}

/* FUNC(zx_ENC_WO_ds_Reference) */

/* Render element into string. The XML attributes and elements are
 * processed in wire order by chasing wo pointers. This is what you want for
 * validating signatures on other people's XML documents. */

/* Called by: */
char* zx_ENC_WO_ds_Reference(struct zx_ctx* c, struct zx_ds_Reference_s* x, char* p )
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
  ZX_OUT_MEM(p, "Reference", sizeof("Reference")-1);
  qq = p;

  /* *** sort the namespaces */
  if (c->inc_ns)
    zx_add_inc_ns(c, &pop_seen);
  zx_add_xmlns_if_not_seen(c, x->gg.g.ns, &pop_seen);

  p = zx_enc_seen(p, pop_seen); 
  p = zx_attr_wo_enc(p, x->Id, "Id=\"", sizeof("Id=\"")-1);
  p = zx_attr_wo_enc(p, x->Type, "Type=\"", sizeof("Type=\"")-1);
  p = zx_attr_wo_enc(p, x->URI, "URI=\"", sizeof("URI=\"")-1);

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
  ENC_LEN_DEBUG(x, "ds:Reference", p-enc_base);
  return p;
}

/* FUNC(zx_EASY_ENC_SO_ds_Reference) */

/* Called by: */
struct zx_str* zx_EASY_ENC_SO_ds_Reference(struct zx_ctx* c, struct zx_ds_Reference_s* x )
{
  int len;
  char* buf;
  c->ns_tab = ZX_ALLOC(c, sizeof(zx_ns_tab));
  memcpy(c->ns_tab, zx_ns_tab, sizeof(zx_ns_tab));
  len = zx_LEN_SO_ds_Reference(c, x );
  buf = ZX_ALLOC(c, len+1);
  return zx_easy_enc_common(c, zx_ENC_SO_ds_Reference(c, x, buf ), buf, len);
}

/* FUNC(zx_EASY_ENC_WO_ds_Reference) */

/* Called by: */
struct zx_str* zx_EASY_ENC_WO_ds_Reference(struct zx_ctx* c, struct zx_ds_Reference_s* x )
{
  int len;
  char* buf;
  c->ns_tab = ZX_ALLOC(c, sizeof(zx_ns_tab));
  memcpy(c->ns_tab, zx_ns_tab, sizeof(zx_ns_tab));
  len = zx_LEN_WO_ds_Reference(c, x );
  buf = ZX_ALLOC(c, len+1);
  return zx_easy_enc_common(c, zx_ENC_WO_ds_Reference(c, x, buf ), buf, len);
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

#define EL_NAME   ds_RetrievalMethod
#define EL_STRUCT zx_ds_RetrievalMethod_s
#define EL_NS     ds
#define EL_TAG    RetrievalMethod

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

/* FUNC(zx_LEN_SO_ds_RetrievalMethod) */

/* Compute length of an element (and its subelements). The XML attributes
 * and elements are processed in schema order. */

/* Called by: */
int zx_LEN_SO_ds_RetrievalMethod(struct zx_ctx* c, struct zx_ds_RetrievalMethod_s* x )
{
  struct zx_ns_s* pop_seen = 0;
  struct zx_elem_s* se MAYBE_UNUSED;
#if 1 /* NORMALMODE */
  /* *** in simple_elem case should output ns prefix from ns node. */
  int len = sizeof("<ds:RetrievalMethod")-1 + 1 + sizeof("</ds:RetrievalMethod>")-1;
  if (c->inc_ns_len)
    len += zx_len_inc_ns(c, &pop_seen);
  len += zx_len_xmlns_if_not_seen(c, zx_ns_tab+zx_xmlns_ix_ds, &pop_seen);

  len += zx_attr_so_len(x->Type, sizeof("Type")-1);
  len += zx_attr_so_len(x->URI, sizeof("URI")-1);

#else
  /* root node has no begin tag */
  int len = 0;
#endif
  
  {
      struct zx_ds_Transforms_s* e;
      for (e = x->Transforms; e; e = (struct zx_ds_Transforms_s*)e->gg.g.n)
	  len += zx_LEN_SO_ds_Transforms(c, e);
  }


  len += zx_len_so_common(c, &x->gg);
  zx_pop_seen(pop_seen);
  ENC_LEN_DEBUG(x, "ds:RetrievalMethod", len);
  return len;
}

/* FUNC(zx_LEN_WO_ds_RetrievalMethod) */

/* Compute length of an element (and its subelements). The XML attributes
 * and elements are processed in wire order and no assumptions
 * are made about namespace prefixes. */

/* Called by: */
int zx_LEN_WO_ds_RetrievalMethod(struct zx_ctx* c, struct zx_ds_RetrievalMethod_s* x )
{
  struct zx_ns_s* pop_seen = 0;
  struct zx_elem_s* se MAYBE_UNUSED;
#if 1 /* NORMALMODE */
  int len = 1 + sizeof("RetrievalMethod")-1 + 1 + 2 + sizeof("RetrievalMethod")-1 + 1;
  
  if (x->gg.g.ns && x->gg.g.ns->prefix_len)
    len += (x->gg.g.ns->prefix_len + 1) * 2;
  if (c->inc_ns_len)
    len += zx_len_inc_ns(c, &pop_seen);
  len += zx_len_xmlns_if_not_seen(c, x->gg.g.ns, &pop_seen);

  len += zx_attr_wo_len(x->Type, sizeof("Type")-1);
  len += zx_attr_wo_len(x->URI, sizeof("URI")-1);

#else
  /* root node has no begin tag */
  int len = 0;
#endif
  
  {
      struct zx_ds_Transforms_s* e;
      for (e = x->Transforms; e; e = (struct zx_ds_Transforms_s*)e->gg.g.n)
	  len += zx_LEN_WO_ds_Transforms(c, e);
  }


  len += zx_len_wo_common(c, &x->gg); 
  zx_pop_seen(pop_seen);
  ENC_LEN_DEBUG(x, "ds:RetrievalMethod", len);
  return len;
}

/* FUNC(zx_ENC_SO_ds_RetrievalMethod) */

/* Render element into string. The XML attributes and elements are
 * processed in schema order. This is what you generally want for
 * rendering new data structure to a string. The wo pointers are not used. */

/* Called by: */
char* zx_ENC_SO_ds_RetrievalMethod(struct zx_ctx* c, struct zx_ds_RetrievalMethod_s* x, char* p )
{
  struct zx_elem_s* se MAYBE_UNUSED;
  ENC_LEN_DEBUG_BASE;
#if 1 /* NORMALMODE */
  struct zx_ns_s* pop_seen = 0;
  /* *** in simple_elem case should output ns prefix from ns node. */
  ZX_OUT_TAG(p, "<ds:RetrievalMethod");
  if (c->inc_ns)
    p = zx_enc_inc_ns(c, p, &pop_seen);
  p = zx_enc_xmlns_if_not_seen(c, p, zx_ns_tab+zx_xmlns_ix_ds, &pop_seen);

  p = zx_attr_so_enc(p, x->Type, " Type=\"", sizeof(" Type=\"")-1);
  p = zx_attr_so_enc(p, x->URI, " URI=\"", sizeof(" URI=\"")-1);

  p = zx_enc_unknown_attrs(p, x->gg.any_attr);
#else
  /* root node has no begin tag */
#endif
  
  {
      struct zx_ds_Transforms_s* e;
      for (e = x->Transforms; e; e = (struct zx_ds_Transforms_s*)e->gg.g.n)
	  p = zx_ENC_SO_ds_Transforms(c, e, p);
  }

  p = zx_enc_so_unknown_elems_and_content(c, p, &x->gg);
  
#if 1 /* NORMALMODE */
  ZX_OUT_CLOSE_TAG(p, "</ds:RetrievalMethod>");
  zx_pop_seen(pop_seen);
#else
  /* root node has no end tag either */
#endif
  ENC_LEN_DEBUG(x, "ds:RetrievalMethod", p-enc_base);
  return p;
}

/* FUNC(zx_ENC_WO_ds_RetrievalMethod) */

/* Render element into string. The XML attributes and elements are
 * processed in wire order by chasing wo pointers. This is what you want for
 * validating signatures on other people's XML documents. */

/* Called by: */
char* zx_ENC_WO_ds_RetrievalMethod(struct zx_ctx* c, struct zx_ds_RetrievalMethod_s* x, char* p )
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
  ZX_OUT_MEM(p, "RetrievalMethod", sizeof("RetrievalMethod")-1);
  qq = p;

  /* *** sort the namespaces */
  if (c->inc_ns)
    zx_add_inc_ns(c, &pop_seen);
  zx_add_xmlns_if_not_seen(c, x->gg.g.ns, &pop_seen);

  p = zx_enc_seen(p, pop_seen); 
  p = zx_attr_wo_enc(p, x->Type, "Type=\"", sizeof("Type=\"")-1);
  p = zx_attr_wo_enc(p, x->URI, "URI=\"", sizeof("URI=\"")-1);

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
  ENC_LEN_DEBUG(x, "ds:RetrievalMethod", p-enc_base);
  return p;
}

/* FUNC(zx_EASY_ENC_SO_ds_RetrievalMethod) */

/* Called by: */
struct zx_str* zx_EASY_ENC_SO_ds_RetrievalMethod(struct zx_ctx* c, struct zx_ds_RetrievalMethod_s* x )
{
  int len;
  char* buf;
  c->ns_tab = ZX_ALLOC(c, sizeof(zx_ns_tab));
  memcpy(c->ns_tab, zx_ns_tab, sizeof(zx_ns_tab));
  len = zx_LEN_SO_ds_RetrievalMethod(c, x );
  buf = ZX_ALLOC(c, len+1);
  return zx_easy_enc_common(c, zx_ENC_SO_ds_RetrievalMethod(c, x, buf ), buf, len);
}

/* FUNC(zx_EASY_ENC_WO_ds_RetrievalMethod) */

/* Called by: */
struct zx_str* zx_EASY_ENC_WO_ds_RetrievalMethod(struct zx_ctx* c, struct zx_ds_RetrievalMethod_s* x )
{
  int len;
  char* buf;
  c->ns_tab = ZX_ALLOC(c, sizeof(zx_ns_tab));
  memcpy(c->ns_tab, zx_ns_tab, sizeof(zx_ns_tab));
  len = zx_LEN_WO_ds_RetrievalMethod(c, x );
  buf = ZX_ALLOC(c, len+1);
  return zx_easy_enc_common(c, zx_ENC_WO_ds_RetrievalMethod(c, x, buf ), buf, len);
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

#define EL_NAME   ds_SPKIData
#define EL_STRUCT zx_ds_SPKIData_s
#define EL_NS     ds
#define EL_TAG    SPKIData

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

/* FUNC(zx_LEN_SO_ds_SPKIData) */

/* Compute length of an element (and its subelements). The XML attributes
 * and elements are processed in schema order. */

/* Called by: */
int zx_LEN_SO_ds_SPKIData(struct zx_ctx* c, struct zx_ds_SPKIData_s* x )
{
  struct zx_ns_s* pop_seen = 0;
  struct zx_elem_s* se MAYBE_UNUSED;
#if 1 /* NORMALMODE */
  /* *** in simple_elem case should output ns prefix from ns node. */
  int len = sizeof("<ds:SPKIData")-1 + 1 + sizeof("</ds:SPKIData>")-1;
  if (c->inc_ns_len)
    len += zx_len_inc_ns(c, &pop_seen);
  len += zx_len_xmlns_if_not_seen(c, zx_ns_tab+zx_xmlns_ix_ds, &pop_seen);


#else
  /* root node has no begin tag */
  int len = 0;
#endif
  
  for (se = x->SPKISexp; se; se = (struct zx_elem_s*)se->g.n)
    len += zx_LEN_SO_simple_elem(c,se, sizeof("ds:SPKISexp")-1, zx_ns_tab+zx_xmlns_ix_ds);


  len += zx_len_so_common(c, &x->gg);
  zx_pop_seen(pop_seen);
  ENC_LEN_DEBUG(x, "ds:SPKIData", len);
  return len;
}

/* FUNC(zx_LEN_WO_ds_SPKIData) */

/* Compute length of an element (and its subelements). The XML attributes
 * and elements are processed in wire order and no assumptions
 * are made about namespace prefixes. */

/* Called by: */
int zx_LEN_WO_ds_SPKIData(struct zx_ctx* c, struct zx_ds_SPKIData_s* x )
{
  struct zx_ns_s* pop_seen = 0;
  struct zx_elem_s* se MAYBE_UNUSED;
#if 1 /* NORMALMODE */
  int len = 1 + sizeof("SPKIData")-1 + 1 + 2 + sizeof("SPKIData")-1 + 1;
  
  if (x->gg.g.ns && x->gg.g.ns->prefix_len)
    len += (x->gg.g.ns->prefix_len + 1) * 2;
  if (c->inc_ns_len)
    len += zx_len_inc_ns(c, &pop_seen);
  len += zx_len_xmlns_if_not_seen(c, x->gg.g.ns, &pop_seen);


#else
  /* root node has no begin tag */
  int len = 0;
#endif
  
  for (se = x->SPKISexp; se; se = (struct zx_elem_s*)se->g.n)
    len += zx_LEN_WO_simple_elem(c, se, sizeof("SPKISexp")-1);


  len += zx_len_wo_common(c, &x->gg); 
  zx_pop_seen(pop_seen);
  ENC_LEN_DEBUG(x, "ds:SPKIData", len);
  return len;
}

/* FUNC(zx_ENC_SO_ds_SPKIData) */

/* Render element into string. The XML attributes and elements are
 * processed in schema order. This is what you generally want for
 * rendering new data structure to a string. The wo pointers are not used. */

/* Called by: */
char* zx_ENC_SO_ds_SPKIData(struct zx_ctx* c, struct zx_ds_SPKIData_s* x, char* p )
{
  struct zx_elem_s* se MAYBE_UNUSED;
  ENC_LEN_DEBUG_BASE;
#if 1 /* NORMALMODE */
  struct zx_ns_s* pop_seen = 0;
  /* *** in simple_elem case should output ns prefix from ns node. */
  ZX_OUT_TAG(p, "<ds:SPKIData");
  if (c->inc_ns)
    p = zx_enc_inc_ns(c, p, &pop_seen);
  p = zx_enc_xmlns_if_not_seen(c, p, zx_ns_tab+zx_xmlns_ix_ds, &pop_seen);


  p = zx_enc_unknown_attrs(p, x->gg.any_attr);
#else
  /* root node has no begin tag */
#endif
  
  for (se = x->SPKISexp; se; se = (struct zx_elem_s*)se->g.n)
    p = zx_ENC_SO_simple_elem(c, se, p, "ds:SPKISexp", sizeof("ds:SPKISexp")-1, zx_ns_tab+zx_xmlns_ix_ds);

  p = zx_enc_so_unknown_elems_and_content(c, p, &x->gg);
  
#if 1 /* NORMALMODE */
  ZX_OUT_CLOSE_TAG(p, "</ds:SPKIData>");
  zx_pop_seen(pop_seen);
#else
  /* root node has no end tag either */
#endif
  ENC_LEN_DEBUG(x, "ds:SPKIData", p-enc_base);
  return p;
}

/* FUNC(zx_ENC_WO_ds_SPKIData) */

/* Render element into string. The XML attributes and elements are
 * processed in wire order by chasing wo pointers. This is what you want for
 * validating signatures on other people's XML documents. */

/* Called by: */
char* zx_ENC_WO_ds_SPKIData(struct zx_ctx* c, struct zx_ds_SPKIData_s* x, char* p )
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
  ZX_OUT_MEM(p, "SPKIData", sizeof("SPKIData")-1);
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
  ENC_LEN_DEBUG(x, "ds:SPKIData", p-enc_base);
  return p;
}

/* FUNC(zx_EASY_ENC_SO_ds_SPKIData) */

/* Called by: */
struct zx_str* zx_EASY_ENC_SO_ds_SPKIData(struct zx_ctx* c, struct zx_ds_SPKIData_s* x )
{
  int len;
  char* buf;
  c->ns_tab = ZX_ALLOC(c, sizeof(zx_ns_tab));
  memcpy(c->ns_tab, zx_ns_tab, sizeof(zx_ns_tab));
  len = zx_LEN_SO_ds_SPKIData(c, x );
  buf = ZX_ALLOC(c, len+1);
  return zx_easy_enc_common(c, zx_ENC_SO_ds_SPKIData(c, x, buf ), buf, len);
}

/* FUNC(zx_EASY_ENC_WO_ds_SPKIData) */

/* Called by: */
struct zx_str* zx_EASY_ENC_WO_ds_SPKIData(struct zx_ctx* c, struct zx_ds_SPKIData_s* x )
{
  int len;
  char* buf;
  c->ns_tab = ZX_ALLOC(c, sizeof(zx_ns_tab));
  memcpy(c->ns_tab, zx_ns_tab, sizeof(zx_ns_tab));
  len = zx_LEN_WO_ds_SPKIData(c, x );
  buf = ZX_ALLOC(c, len+1);
  return zx_easy_enc_common(c, zx_ENC_WO_ds_SPKIData(c, x, buf ), buf, len);
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

#define EL_NAME   ds_Signature
#define EL_STRUCT zx_ds_Signature_s
#define EL_NS     ds
#define EL_TAG    Signature

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

/* FUNC(zx_LEN_SO_ds_Signature) */

/* Compute length of an element (and its subelements). The XML attributes
 * and elements are processed in schema order. */

/* Called by: */
int zx_LEN_SO_ds_Signature(struct zx_ctx* c, struct zx_ds_Signature_s* x )
{
  struct zx_ns_s* pop_seen = 0;
  struct zx_elem_s* se MAYBE_UNUSED;
#if 1 /* NORMALMODE */
  /* *** in simple_elem case should output ns prefix from ns node. */
  int len = sizeof("<ds:Signature")-1 + 1 + sizeof("</ds:Signature>")-1;
  if (c->inc_ns_len)
    len += zx_len_inc_ns(c, &pop_seen);
  len += zx_len_xmlns_if_not_seen(c, zx_ns_tab+zx_xmlns_ix_ds, &pop_seen);

  len += zx_attr_so_len(x->Id, sizeof("Id")-1);

#else
  /* root node has no begin tag */
  int len = 0;
#endif
  
  {
      struct zx_ds_SignedInfo_s* e;
      for (e = x->SignedInfo; e; e = (struct zx_ds_SignedInfo_s*)e->gg.g.n)
	  len += zx_LEN_SO_ds_SignedInfo(c, e);
  }
  {
      struct zx_ds_SignatureValue_s* e;
      for (e = x->SignatureValue; e; e = (struct zx_ds_SignatureValue_s*)e->gg.g.n)
	  len += zx_LEN_SO_ds_SignatureValue(c, e);
  }
  {
      struct zx_ds_KeyInfo_s* e;
      for (e = x->KeyInfo; e; e = (struct zx_ds_KeyInfo_s*)e->gg.g.n)
	  len += zx_LEN_SO_ds_KeyInfo(c, e);
  }
  {
      struct zx_ds_Object_s* e;
      for (e = x->Object; e; e = (struct zx_ds_Object_s*)e->gg.g.n)
	  len += zx_LEN_SO_ds_Object(c, e);
  }


  len += zx_len_so_common(c, &x->gg);
  zx_pop_seen(pop_seen);
  ENC_LEN_DEBUG(x, "ds:Signature", len);
  return len;
}

/* FUNC(zx_LEN_WO_ds_Signature) */

/* Compute length of an element (and its subelements). The XML attributes
 * and elements are processed in wire order and no assumptions
 * are made about namespace prefixes. */

/* Called by: */
int zx_LEN_WO_ds_Signature(struct zx_ctx* c, struct zx_ds_Signature_s* x )
{
  struct zx_ns_s* pop_seen = 0;
  struct zx_elem_s* se MAYBE_UNUSED;
#if 1 /* NORMALMODE */
  int len = 1 + sizeof("Signature")-1 + 1 + 2 + sizeof("Signature")-1 + 1;
  
  if (x->gg.g.ns && x->gg.g.ns->prefix_len)
    len += (x->gg.g.ns->prefix_len + 1) * 2;
  if (c->inc_ns_len)
    len += zx_len_inc_ns(c, &pop_seen);
  len += zx_len_xmlns_if_not_seen(c, x->gg.g.ns, &pop_seen);

  len += zx_attr_wo_len(x->Id, sizeof("Id")-1);

#else
  /* root node has no begin tag */
  int len = 0;
#endif
  
  {
      struct zx_ds_SignedInfo_s* e;
      for (e = x->SignedInfo; e; e = (struct zx_ds_SignedInfo_s*)e->gg.g.n)
	  len += zx_LEN_WO_ds_SignedInfo(c, e);
  }
  {
      struct zx_ds_SignatureValue_s* e;
      for (e = x->SignatureValue; e; e = (struct zx_ds_SignatureValue_s*)e->gg.g.n)
	  len += zx_LEN_WO_ds_SignatureValue(c, e);
  }
  {
      struct zx_ds_KeyInfo_s* e;
      for (e = x->KeyInfo; e; e = (struct zx_ds_KeyInfo_s*)e->gg.g.n)
	  len += zx_LEN_WO_ds_KeyInfo(c, e);
  }
  {
      struct zx_ds_Object_s* e;
      for (e = x->Object; e; e = (struct zx_ds_Object_s*)e->gg.g.n)
	  len += zx_LEN_WO_ds_Object(c, e);
  }


  len += zx_len_wo_common(c, &x->gg); 
  zx_pop_seen(pop_seen);
  ENC_LEN_DEBUG(x, "ds:Signature", len);
  return len;
}

/* FUNC(zx_ENC_SO_ds_Signature) */

/* Render element into string. The XML attributes and elements are
 * processed in schema order. This is what you generally want for
 * rendering new data structure to a string. The wo pointers are not used. */

/* Called by: */
char* zx_ENC_SO_ds_Signature(struct zx_ctx* c, struct zx_ds_Signature_s* x, char* p )
{
  struct zx_elem_s* se MAYBE_UNUSED;
  ENC_LEN_DEBUG_BASE;
#if 1 /* NORMALMODE */
  struct zx_ns_s* pop_seen = 0;
  /* *** in simple_elem case should output ns prefix from ns node. */
  ZX_OUT_TAG(p, "<ds:Signature");
  if (c->inc_ns)
    p = zx_enc_inc_ns(c, p, &pop_seen);
  p = zx_enc_xmlns_if_not_seen(c, p, zx_ns_tab+zx_xmlns_ix_ds, &pop_seen);

  p = zx_attr_so_enc(p, x->Id, " Id=\"", sizeof(" Id=\"")-1);

  p = zx_enc_unknown_attrs(p, x->gg.any_attr);
#else
  /* root node has no begin tag */
#endif
  
  {
      struct zx_ds_SignedInfo_s* e;
      for (e = x->SignedInfo; e; e = (struct zx_ds_SignedInfo_s*)e->gg.g.n)
	  p = zx_ENC_SO_ds_SignedInfo(c, e, p);
  }
  {
      struct zx_ds_SignatureValue_s* e;
      for (e = x->SignatureValue; e; e = (struct zx_ds_SignatureValue_s*)e->gg.g.n)
	  p = zx_ENC_SO_ds_SignatureValue(c, e, p);
  }
  {
      struct zx_ds_KeyInfo_s* e;
      for (e = x->KeyInfo; e; e = (struct zx_ds_KeyInfo_s*)e->gg.g.n)
	  p = zx_ENC_SO_ds_KeyInfo(c, e, p);
  }
  {
      struct zx_ds_Object_s* e;
      for (e = x->Object; e; e = (struct zx_ds_Object_s*)e->gg.g.n)
	  p = zx_ENC_SO_ds_Object(c, e, p);
  }

  p = zx_enc_so_unknown_elems_and_content(c, p, &x->gg);
  
#if 1 /* NORMALMODE */
  ZX_OUT_CLOSE_TAG(p, "</ds:Signature>");
  zx_pop_seen(pop_seen);
#else
  /* root node has no end tag either */
#endif
  ENC_LEN_DEBUG(x, "ds:Signature", p-enc_base);
  return p;
}

/* FUNC(zx_ENC_WO_ds_Signature) */

/* Render element into string. The XML attributes and elements are
 * processed in wire order by chasing wo pointers. This is what you want for
 * validating signatures on other people's XML documents. */

/* Called by: */
char* zx_ENC_WO_ds_Signature(struct zx_ctx* c, struct zx_ds_Signature_s* x, char* p )
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
  ZX_OUT_MEM(p, "Signature", sizeof("Signature")-1);
  qq = p;

  /* *** sort the namespaces */
  if (c->inc_ns)
    zx_add_inc_ns(c, &pop_seen);
  zx_add_xmlns_if_not_seen(c, x->gg.g.ns, &pop_seen);

  p = zx_enc_seen(p, pop_seen); 
  p = zx_attr_wo_enc(p, x->Id, "Id=\"", sizeof("Id=\"")-1);

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
  ENC_LEN_DEBUG(x, "ds:Signature", p-enc_base);
  return p;
}

/* FUNC(zx_EASY_ENC_SO_ds_Signature) */

/* Called by: */
struct zx_str* zx_EASY_ENC_SO_ds_Signature(struct zx_ctx* c, struct zx_ds_Signature_s* x )
{
  int len;
  char* buf;
  c->ns_tab = ZX_ALLOC(c, sizeof(zx_ns_tab));
  memcpy(c->ns_tab, zx_ns_tab, sizeof(zx_ns_tab));
  len = zx_LEN_SO_ds_Signature(c, x );
  buf = ZX_ALLOC(c, len+1);
  return zx_easy_enc_common(c, zx_ENC_SO_ds_Signature(c, x, buf ), buf, len);
}

/* FUNC(zx_EASY_ENC_WO_ds_Signature) */

/* Called by: */
struct zx_str* zx_EASY_ENC_WO_ds_Signature(struct zx_ctx* c, struct zx_ds_Signature_s* x )
{
  int len;
  char* buf;
  c->ns_tab = ZX_ALLOC(c, sizeof(zx_ns_tab));
  memcpy(c->ns_tab, zx_ns_tab, sizeof(zx_ns_tab));
  len = zx_LEN_WO_ds_Signature(c, x );
  buf = ZX_ALLOC(c, len+1);
  return zx_easy_enc_common(c, zx_ENC_WO_ds_Signature(c, x, buf ), buf, len);
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

#define EL_NAME   ds_SignatureMethod
#define EL_STRUCT zx_ds_SignatureMethod_s
#define EL_NS     ds
#define EL_TAG    SignatureMethod

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

/* FUNC(zx_LEN_SO_ds_SignatureMethod) */

/* Compute length of an element (and its subelements). The XML attributes
 * and elements are processed in schema order. */

/* Called by: */
int zx_LEN_SO_ds_SignatureMethod(struct zx_ctx* c, struct zx_ds_SignatureMethod_s* x )
{
  struct zx_ns_s* pop_seen = 0;
  struct zx_elem_s* se MAYBE_UNUSED;
#if 1 /* NORMALMODE */
  /* *** in simple_elem case should output ns prefix from ns node. */
  int len = sizeof("<ds:SignatureMethod")-1 + 1 + sizeof("</ds:SignatureMethod>")-1;
  if (c->inc_ns_len)
    len += zx_len_inc_ns(c, &pop_seen);
  len += zx_len_xmlns_if_not_seen(c, zx_ns_tab+zx_xmlns_ix_ds, &pop_seen);

  len += zx_attr_so_len(x->Algorithm, sizeof("Algorithm")-1);

#else
  /* root node has no begin tag */
  int len = 0;
#endif
  
  for (se = x->HMACOutputLength; se; se = (struct zx_elem_s*)se->g.n)
    len += zx_LEN_SO_simple_elem(c,se, sizeof("ds:HMACOutputLength")-1, zx_ns_tab+zx_xmlns_ix_ds);


  len += zx_len_so_common(c, &x->gg);
  zx_pop_seen(pop_seen);
  ENC_LEN_DEBUG(x, "ds:SignatureMethod", len);
  return len;
}

/* FUNC(zx_LEN_WO_ds_SignatureMethod) */

/* Compute length of an element (and its subelements). The XML attributes
 * and elements are processed in wire order and no assumptions
 * are made about namespace prefixes. */

/* Called by: */
int zx_LEN_WO_ds_SignatureMethod(struct zx_ctx* c, struct zx_ds_SignatureMethod_s* x )
{
  struct zx_ns_s* pop_seen = 0;
  struct zx_elem_s* se MAYBE_UNUSED;
#if 1 /* NORMALMODE */
  int len = 1 + sizeof("SignatureMethod")-1 + 1 + 2 + sizeof("SignatureMethod")-1 + 1;
  
  if (x->gg.g.ns && x->gg.g.ns->prefix_len)
    len += (x->gg.g.ns->prefix_len + 1) * 2;
  if (c->inc_ns_len)
    len += zx_len_inc_ns(c, &pop_seen);
  len += zx_len_xmlns_if_not_seen(c, x->gg.g.ns, &pop_seen);

  len += zx_attr_wo_len(x->Algorithm, sizeof("Algorithm")-1);

#else
  /* root node has no begin tag */
  int len = 0;
#endif
  
  for (se = x->HMACOutputLength; se; se = (struct zx_elem_s*)se->g.n)
    len += zx_LEN_WO_simple_elem(c, se, sizeof("HMACOutputLength")-1);


  len += zx_len_wo_common(c, &x->gg); 
  zx_pop_seen(pop_seen);
  ENC_LEN_DEBUG(x, "ds:SignatureMethod", len);
  return len;
}

/* FUNC(zx_ENC_SO_ds_SignatureMethod) */

/* Render element into string. The XML attributes and elements are
 * processed in schema order. This is what you generally want for
 * rendering new data structure to a string. The wo pointers are not used. */

/* Called by: */
char* zx_ENC_SO_ds_SignatureMethod(struct zx_ctx* c, struct zx_ds_SignatureMethod_s* x, char* p )
{
  struct zx_elem_s* se MAYBE_UNUSED;
  ENC_LEN_DEBUG_BASE;
#if 1 /* NORMALMODE */
  struct zx_ns_s* pop_seen = 0;
  /* *** in simple_elem case should output ns prefix from ns node. */
  ZX_OUT_TAG(p, "<ds:SignatureMethod");
  if (c->inc_ns)
    p = zx_enc_inc_ns(c, p, &pop_seen);
  p = zx_enc_xmlns_if_not_seen(c, p, zx_ns_tab+zx_xmlns_ix_ds, &pop_seen);

  p = zx_attr_so_enc(p, x->Algorithm, " Algorithm=\"", sizeof(" Algorithm=\"")-1);

  p = zx_enc_unknown_attrs(p, x->gg.any_attr);
#else
  /* root node has no begin tag */
#endif
  
  for (se = x->HMACOutputLength; se; se = (struct zx_elem_s*)se->g.n)
    p = zx_ENC_SO_simple_elem(c, se, p, "ds:HMACOutputLength", sizeof("ds:HMACOutputLength")-1, zx_ns_tab+zx_xmlns_ix_ds);

  p = zx_enc_so_unknown_elems_and_content(c, p, &x->gg);
  
#if 1 /* NORMALMODE */
  ZX_OUT_CLOSE_TAG(p, "</ds:SignatureMethod>");
  zx_pop_seen(pop_seen);
#else
  /* root node has no end tag either */
#endif
  ENC_LEN_DEBUG(x, "ds:SignatureMethod", p-enc_base);
  return p;
}

/* FUNC(zx_ENC_WO_ds_SignatureMethod) */

/* Render element into string. The XML attributes and elements are
 * processed in wire order by chasing wo pointers. This is what you want for
 * validating signatures on other people's XML documents. */

/* Called by: */
char* zx_ENC_WO_ds_SignatureMethod(struct zx_ctx* c, struct zx_ds_SignatureMethod_s* x, char* p )
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
  ZX_OUT_MEM(p, "SignatureMethod", sizeof("SignatureMethod")-1);
  qq = p;

  /* *** sort the namespaces */
  if (c->inc_ns)
    zx_add_inc_ns(c, &pop_seen);
  zx_add_xmlns_if_not_seen(c, x->gg.g.ns, &pop_seen);

  p = zx_enc_seen(p, pop_seen); 
  p = zx_attr_wo_enc(p, x->Algorithm, "Algorithm=\"", sizeof("Algorithm=\"")-1);

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
  ENC_LEN_DEBUG(x, "ds:SignatureMethod", p-enc_base);
  return p;
}

/* FUNC(zx_EASY_ENC_SO_ds_SignatureMethod) */

/* Called by: */
struct zx_str* zx_EASY_ENC_SO_ds_SignatureMethod(struct zx_ctx* c, struct zx_ds_SignatureMethod_s* x )
{
  int len;
  char* buf;
  c->ns_tab = ZX_ALLOC(c, sizeof(zx_ns_tab));
  memcpy(c->ns_tab, zx_ns_tab, sizeof(zx_ns_tab));
  len = zx_LEN_SO_ds_SignatureMethod(c, x );
  buf = ZX_ALLOC(c, len+1);
  return zx_easy_enc_common(c, zx_ENC_SO_ds_SignatureMethod(c, x, buf ), buf, len);
}

/* FUNC(zx_EASY_ENC_WO_ds_SignatureMethod) */

/* Called by: */
struct zx_str* zx_EASY_ENC_WO_ds_SignatureMethod(struct zx_ctx* c, struct zx_ds_SignatureMethod_s* x )
{
  int len;
  char* buf;
  c->ns_tab = ZX_ALLOC(c, sizeof(zx_ns_tab));
  memcpy(c->ns_tab, zx_ns_tab, sizeof(zx_ns_tab));
  len = zx_LEN_WO_ds_SignatureMethod(c, x );
  buf = ZX_ALLOC(c, len+1);
  return zx_easy_enc_common(c, zx_ENC_WO_ds_SignatureMethod(c, x, buf ), buf, len);
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

#define EL_NAME   ds_SignatureProperties
#define EL_STRUCT zx_ds_SignatureProperties_s
#define EL_NS     ds
#define EL_TAG    SignatureProperties

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

/* FUNC(zx_LEN_SO_ds_SignatureProperties) */

/* Compute length of an element (and its subelements). The XML attributes
 * and elements are processed in schema order. */

/* Called by: */
int zx_LEN_SO_ds_SignatureProperties(struct zx_ctx* c, struct zx_ds_SignatureProperties_s* x )
{
  struct zx_ns_s* pop_seen = 0;
  struct zx_elem_s* se MAYBE_UNUSED;
#if 1 /* NORMALMODE */
  /* *** in simple_elem case should output ns prefix from ns node. */
  int len = sizeof("<ds:SignatureProperties")-1 + 1 + sizeof("</ds:SignatureProperties>")-1;
  if (c->inc_ns_len)
    len += zx_len_inc_ns(c, &pop_seen);
  len += zx_len_xmlns_if_not_seen(c, zx_ns_tab+zx_xmlns_ix_ds, &pop_seen);

  len += zx_attr_so_len(x->Id, sizeof("Id")-1);

#else
  /* root node has no begin tag */
  int len = 0;
#endif
  
  {
      struct zx_ds_SignatureProperty_s* e;
      for (e = x->SignatureProperty; e; e = (struct zx_ds_SignatureProperty_s*)e->gg.g.n)
	  len += zx_LEN_SO_ds_SignatureProperty(c, e);
  }


  len += zx_len_so_common(c, &x->gg);
  zx_pop_seen(pop_seen);
  ENC_LEN_DEBUG(x, "ds:SignatureProperties", len);
  return len;
}

/* FUNC(zx_LEN_WO_ds_SignatureProperties) */

/* Compute length of an element (and its subelements). The XML attributes
 * and elements are processed in wire order and no assumptions
 * are made about namespace prefixes. */

/* Called by: */
int zx_LEN_WO_ds_SignatureProperties(struct zx_ctx* c, struct zx_ds_SignatureProperties_s* x )
{
  struct zx_ns_s* pop_seen = 0;
  struct zx_elem_s* se MAYBE_UNUSED;
#if 1 /* NORMALMODE */
  int len = 1 + sizeof("SignatureProperties")-1 + 1 + 2 + sizeof("SignatureProperties")-1 + 1;
  
  if (x->gg.g.ns && x->gg.g.ns->prefix_len)
    len += (x->gg.g.ns->prefix_len + 1) * 2;
  if (c->inc_ns_len)
    len += zx_len_inc_ns(c, &pop_seen);
  len += zx_len_xmlns_if_not_seen(c, x->gg.g.ns, &pop_seen);

  len += zx_attr_wo_len(x->Id, sizeof("Id")-1);

#else
  /* root node has no begin tag */
  int len = 0;
#endif
  
  {
      struct zx_ds_SignatureProperty_s* e;
      for (e = x->SignatureProperty; e; e = (struct zx_ds_SignatureProperty_s*)e->gg.g.n)
	  len += zx_LEN_WO_ds_SignatureProperty(c, e);
  }


  len += zx_len_wo_common(c, &x->gg); 
  zx_pop_seen(pop_seen);
  ENC_LEN_DEBUG(x, "ds:SignatureProperties", len);
  return len;
}

/* FUNC(zx_ENC_SO_ds_SignatureProperties) */

/* Render element into string. The XML attributes and elements are
 * processed in schema order. This is what you generally want for
 * rendering new data structure to a string. The wo pointers are not used. */

/* Called by: */
char* zx_ENC_SO_ds_SignatureProperties(struct zx_ctx* c, struct zx_ds_SignatureProperties_s* x, char* p )
{
  struct zx_elem_s* se MAYBE_UNUSED;
  ENC_LEN_DEBUG_BASE;
#if 1 /* NORMALMODE */
  struct zx_ns_s* pop_seen = 0;
  /* *** in simple_elem case should output ns prefix from ns node. */
  ZX_OUT_TAG(p, "<ds:SignatureProperties");
  if (c->inc_ns)
    p = zx_enc_inc_ns(c, p, &pop_seen);
  p = zx_enc_xmlns_if_not_seen(c, p, zx_ns_tab+zx_xmlns_ix_ds, &pop_seen);

  p = zx_attr_so_enc(p, x->Id, " Id=\"", sizeof(" Id=\"")-1);

  p = zx_enc_unknown_attrs(p, x->gg.any_attr);
#else
  /* root node has no begin tag */
#endif
  
  {
      struct zx_ds_SignatureProperty_s* e;
      for (e = x->SignatureProperty; e; e = (struct zx_ds_SignatureProperty_s*)e->gg.g.n)
	  p = zx_ENC_SO_ds_SignatureProperty(c, e, p);
  }

  p = zx_enc_so_unknown_elems_and_content(c, p, &x->gg);
  
#if 1 /* NORMALMODE */
  ZX_OUT_CLOSE_TAG(p, "</ds:SignatureProperties>");
  zx_pop_seen(pop_seen);
#else
  /* root node has no end tag either */
#endif
  ENC_LEN_DEBUG(x, "ds:SignatureProperties", p-enc_base);
  return p;
}

/* FUNC(zx_ENC_WO_ds_SignatureProperties) */

/* Render element into string. The XML attributes and elements are
 * processed in wire order by chasing wo pointers. This is what you want for
 * validating signatures on other people's XML documents. */

/* Called by: */
char* zx_ENC_WO_ds_SignatureProperties(struct zx_ctx* c, struct zx_ds_SignatureProperties_s* x, char* p )
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
  ZX_OUT_MEM(p, "SignatureProperties", sizeof("SignatureProperties")-1);
  qq = p;

  /* *** sort the namespaces */
  if (c->inc_ns)
    zx_add_inc_ns(c, &pop_seen);
  zx_add_xmlns_if_not_seen(c, x->gg.g.ns, &pop_seen);

  p = zx_enc_seen(p, pop_seen); 
  p = zx_attr_wo_enc(p, x->Id, "Id=\"", sizeof("Id=\"")-1);

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
  ENC_LEN_DEBUG(x, "ds:SignatureProperties", p-enc_base);
  return p;
}

/* FUNC(zx_EASY_ENC_SO_ds_SignatureProperties) */

/* Called by: */
struct zx_str* zx_EASY_ENC_SO_ds_SignatureProperties(struct zx_ctx* c, struct zx_ds_SignatureProperties_s* x )
{
  int len;
  char* buf;
  c->ns_tab = ZX_ALLOC(c, sizeof(zx_ns_tab));
  memcpy(c->ns_tab, zx_ns_tab, sizeof(zx_ns_tab));
  len = zx_LEN_SO_ds_SignatureProperties(c, x );
  buf = ZX_ALLOC(c, len+1);
  return zx_easy_enc_common(c, zx_ENC_SO_ds_SignatureProperties(c, x, buf ), buf, len);
}

/* FUNC(zx_EASY_ENC_WO_ds_SignatureProperties) */

/* Called by: */
struct zx_str* zx_EASY_ENC_WO_ds_SignatureProperties(struct zx_ctx* c, struct zx_ds_SignatureProperties_s* x )
{
  int len;
  char* buf;
  c->ns_tab = ZX_ALLOC(c, sizeof(zx_ns_tab));
  memcpy(c->ns_tab, zx_ns_tab, sizeof(zx_ns_tab));
  len = zx_LEN_WO_ds_SignatureProperties(c, x );
  buf = ZX_ALLOC(c, len+1);
  return zx_easy_enc_common(c, zx_ENC_WO_ds_SignatureProperties(c, x, buf ), buf, len);
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

#define EL_NAME   ds_SignatureProperty
#define EL_STRUCT zx_ds_SignatureProperty_s
#define EL_NS     ds
#define EL_TAG    SignatureProperty

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

/* FUNC(zx_LEN_SO_ds_SignatureProperty) */

/* Compute length of an element (and its subelements). The XML attributes
 * and elements are processed in schema order. */

/* Called by: */
int zx_LEN_SO_ds_SignatureProperty(struct zx_ctx* c, struct zx_ds_SignatureProperty_s* x )
{
  struct zx_ns_s* pop_seen = 0;
  struct zx_elem_s* se MAYBE_UNUSED;
#if 1 /* NORMALMODE */
  /* *** in simple_elem case should output ns prefix from ns node. */
  int len = sizeof("<ds:SignatureProperty")-1 + 1 + sizeof("</ds:SignatureProperty>")-1;
  if (c->inc_ns_len)
    len += zx_len_inc_ns(c, &pop_seen);
  len += zx_len_xmlns_if_not_seen(c, zx_ns_tab+zx_xmlns_ix_ds, &pop_seen);

  len += zx_attr_so_len(x->Id, sizeof("Id")-1);
  len += zx_attr_so_len(x->Target, sizeof("Target")-1);

#else
  /* root node has no begin tag */
  int len = 0;
#endif
  


  len += zx_len_so_common(c, &x->gg);
  zx_pop_seen(pop_seen);
  ENC_LEN_DEBUG(x, "ds:SignatureProperty", len);
  return len;
}

/* FUNC(zx_LEN_WO_ds_SignatureProperty) */

/* Compute length of an element (and its subelements). The XML attributes
 * and elements are processed in wire order and no assumptions
 * are made about namespace prefixes. */

/* Called by: */
int zx_LEN_WO_ds_SignatureProperty(struct zx_ctx* c, struct zx_ds_SignatureProperty_s* x )
{
  struct zx_ns_s* pop_seen = 0;
  struct zx_elem_s* se MAYBE_UNUSED;
#if 1 /* NORMALMODE */
  int len = 1 + sizeof("SignatureProperty")-1 + 1 + 2 + sizeof("SignatureProperty")-1 + 1;
  
  if (x->gg.g.ns && x->gg.g.ns->prefix_len)
    len += (x->gg.g.ns->prefix_len + 1) * 2;
  if (c->inc_ns_len)
    len += zx_len_inc_ns(c, &pop_seen);
  len += zx_len_xmlns_if_not_seen(c, x->gg.g.ns, &pop_seen);

  len += zx_attr_wo_len(x->Id, sizeof("Id")-1);
  len += zx_attr_wo_len(x->Target, sizeof("Target")-1);

#else
  /* root node has no begin tag */
  int len = 0;
#endif
  


  len += zx_len_wo_common(c, &x->gg); 
  zx_pop_seen(pop_seen);
  ENC_LEN_DEBUG(x, "ds:SignatureProperty", len);
  return len;
}

/* FUNC(zx_ENC_SO_ds_SignatureProperty) */

/* Render element into string. The XML attributes and elements are
 * processed in schema order. This is what you generally want for
 * rendering new data structure to a string. The wo pointers are not used. */

/* Called by: */
char* zx_ENC_SO_ds_SignatureProperty(struct zx_ctx* c, struct zx_ds_SignatureProperty_s* x, char* p )
{
  struct zx_elem_s* se MAYBE_UNUSED;
  ENC_LEN_DEBUG_BASE;
#if 1 /* NORMALMODE */
  struct zx_ns_s* pop_seen = 0;
  /* *** in simple_elem case should output ns prefix from ns node. */
  ZX_OUT_TAG(p, "<ds:SignatureProperty");
  if (c->inc_ns)
    p = zx_enc_inc_ns(c, p, &pop_seen);
  p = zx_enc_xmlns_if_not_seen(c, p, zx_ns_tab+zx_xmlns_ix_ds, &pop_seen);

  p = zx_attr_so_enc(p, x->Id, " Id=\"", sizeof(" Id=\"")-1);
  p = zx_attr_so_enc(p, x->Target, " Target=\"", sizeof(" Target=\"")-1);

  p = zx_enc_unknown_attrs(p, x->gg.any_attr);
#else
  /* root node has no begin tag */
#endif
  

  p = zx_enc_so_unknown_elems_and_content(c, p, &x->gg);
  
#if 1 /* NORMALMODE */
  ZX_OUT_CLOSE_TAG(p, "</ds:SignatureProperty>");
  zx_pop_seen(pop_seen);
#else
  /* root node has no end tag either */
#endif
  ENC_LEN_DEBUG(x, "ds:SignatureProperty", p-enc_base);
  return p;
}

/* FUNC(zx_ENC_WO_ds_SignatureProperty) */

/* Render element into string. The XML attributes and elements are
 * processed in wire order by chasing wo pointers. This is what you want for
 * validating signatures on other people's XML documents. */

/* Called by: */
char* zx_ENC_WO_ds_SignatureProperty(struct zx_ctx* c, struct zx_ds_SignatureProperty_s* x, char* p )
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
  ZX_OUT_MEM(p, "SignatureProperty", sizeof("SignatureProperty")-1);
  qq = p;

  /* *** sort the namespaces */
  if (c->inc_ns)
    zx_add_inc_ns(c, &pop_seen);
  zx_add_xmlns_if_not_seen(c, x->gg.g.ns, &pop_seen);

  p = zx_enc_seen(p, pop_seen); 
  p = zx_attr_wo_enc(p, x->Id, "Id=\"", sizeof("Id=\"")-1);
  p = zx_attr_wo_enc(p, x->Target, "Target=\"", sizeof("Target=\"")-1);

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
  ENC_LEN_DEBUG(x, "ds:SignatureProperty", p-enc_base);
  return p;
}

/* FUNC(zx_EASY_ENC_SO_ds_SignatureProperty) */

/* Called by: */
struct zx_str* zx_EASY_ENC_SO_ds_SignatureProperty(struct zx_ctx* c, struct zx_ds_SignatureProperty_s* x )
{
  int len;
  char* buf;
  c->ns_tab = ZX_ALLOC(c, sizeof(zx_ns_tab));
  memcpy(c->ns_tab, zx_ns_tab, sizeof(zx_ns_tab));
  len = zx_LEN_SO_ds_SignatureProperty(c, x );
  buf = ZX_ALLOC(c, len+1);
  return zx_easy_enc_common(c, zx_ENC_SO_ds_SignatureProperty(c, x, buf ), buf, len);
}

/* FUNC(zx_EASY_ENC_WO_ds_SignatureProperty) */

/* Called by: */
struct zx_str* zx_EASY_ENC_WO_ds_SignatureProperty(struct zx_ctx* c, struct zx_ds_SignatureProperty_s* x )
{
  int len;
  char* buf;
  c->ns_tab = ZX_ALLOC(c, sizeof(zx_ns_tab));
  memcpy(c->ns_tab, zx_ns_tab, sizeof(zx_ns_tab));
  len = zx_LEN_WO_ds_SignatureProperty(c, x );
  buf = ZX_ALLOC(c, len+1);
  return zx_easy_enc_common(c, zx_ENC_WO_ds_SignatureProperty(c, x, buf ), buf, len);
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

#define EL_NAME   ds_SignatureValue
#define EL_STRUCT zx_ds_SignatureValue_s
#define EL_NS     ds
#define EL_TAG    SignatureValue

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

/* FUNC(zx_LEN_SO_ds_SignatureValue) */

/* Compute length of an element (and its subelements). The XML attributes
 * and elements are processed in schema order. */

/* Called by: */
int zx_LEN_SO_ds_SignatureValue(struct zx_ctx* c, struct zx_ds_SignatureValue_s* x )
{
  struct zx_ns_s* pop_seen = 0;
  struct zx_elem_s* se MAYBE_UNUSED;
#if 1 /* NORMALMODE */
  /* *** in simple_elem case should output ns prefix from ns node. */
  int len = sizeof("<ds:SignatureValue")-1 + 1 + sizeof("</ds:SignatureValue>")-1;
  if (c->inc_ns_len)
    len += zx_len_inc_ns(c, &pop_seen);
  len += zx_len_xmlns_if_not_seen(c, zx_ns_tab+zx_xmlns_ix_ds, &pop_seen);

  len += zx_attr_so_len(x->Id, sizeof("Id")-1);

#else
  /* root node has no begin tag */
  int len = 0;
#endif
  


  len += zx_len_so_common(c, &x->gg);
  zx_pop_seen(pop_seen);
  ENC_LEN_DEBUG(x, "ds:SignatureValue", len);
  return len;
}

/* FUNC(zx_LEN_WO_ds_SignatureValue) */

/* Compute length of an element (and its subelements). The XML attributes
 * and elements are processed in wire order and no assumptions
 * are made about namespace prefixes. */

/* Called by: */
int zx_LEN_WO_ds_SignatureValue(struct zx_ctx* c, struct zx_ds_SignatureValue_s* x )
{
  struct zx_ns_s* pop_seen = 0;
  struct zx_elem_s* se MAYBE_UNUSED;
#if 1 /* NORMALMODE */
  int len = 1 + sizeof("SignatureValue")-1 + 1 + 2 + sizeof("SignatureValue")-1 + 1;
  
  if (x->gg.g.ns && x->gg.g.ns->prefix_len)
    len += (x->gg.g.ns->prefix_len + 1) * 2;
  if (c->inc_ns_len)
    len += zx_len_inc_ns(c, &pop_seen);
  len += zx_len_xmlns_if_not_seen(c, x->gg.g.ns, &pop_seen);

  len += zx_attr_wo_len(x->Id, sizeof("Id")-1);

#else
  /* root node has no begin tag */
  int len = 0;
#endif
  


  len += zx_len_wo_common(c, &x->gg); 
  zx_pop_seen(pop_seen);
  ENC_LEN_DEBUG(x, "ds:SignatureValue", len);
  return len;
}

/* FUNC(zx_ENC_SO_ds_SignatureValue) */

/* Render element into string. The XML attributes and elements are
 * processed in schema order. This is what you generally want for
 * rendering new data structure to a string. The wo pointers are not used. */

/* Called by: */
char* zx_ENC_SO_ds_SignatureValue(struct zx_ctx* c, struct zx_ds_SignatureValue_s* x, char* p )
{
  struct zx_elem_s* se MAYBE_UNUSED;
  ENC_LEN_DEBUG_BASE;
#if 1 /* NORMALMODE */
  struct zx_ns_s* pop_seen = 0;
  /* *** in simple_elem case should output ns prefix from ns node. */
  ZX_OUT_TAG(p, "<ds:SignatureValue");
  if (c->inc_ns)
    p = zx_enc_inc_ns(c, p, &pop_seen);
  p = zx_enc_xmlns_if_not_seen(c, p, zx_ns_tab+zx_xmlns_ix_ds, &pop_seen);

  p = zx_attr_so_enc(p, x->Id, " Id=\"", sizeof(" Id=\"")-1);

  p = zx_enc_unknown_attrs(p, x->gg.any_attr);
#else
  /* root node has no begin tag */
#endif
  

  p = zx_enc_so_unknown_elems_and_content(c, p, &x->gg);
  
#if 1 /* NORMALMODE */
  ZX_OUT_CLOSE_TAG(p, "</ds:SignatureValue>");
  zx_pop_seen(pop_seen);
#else
  /* root node has no end tag either */
#endif
  ENC_LEN_DEBUG(x, "ds:SignatureValue", p-enc_base);
  return p;
}

/* FUNC(zx_ENC_WO_ds_SignatureValue) */

/* Render element into string. The XML attributes and elements are
 * processed in wire order by chasing wo pointers. This is what you want for
 * validating signatures on other people's XML documents. */

/* Called by: */
char* zx_ENC_WO_ds_SignatureValue(struct zx_ctx* c, struct zx_ds_SignatureValue_s* x, char* p )
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
  ZX_OUT_MEM(p, "SignatureValue", sizeof("SignatureValue")-1);
  qq = p;

  /* *** sort the namespaces */
  if (c->inc_ns)
    zx_add_inc_ns(c, &pop_seen);
  zx_add_xmlns_if_not_seen(c, x->gg.g.ns, &pop_seen);

  p = zx_enc_seen(p, pop_seen); 
  p = zx_attr_wo_enc(p, x->Id, "Id=\"", sizeof("Id=\"")-1);

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
  ENC_LEN_DEBUG(x, "ds:SignatureValue", p-enc_base);
  return p;
}

/* FUNC(zx_EASY_ENC_SO_ds_SignatureValue) */

/* Called by: */
struct zx_str* zx_EASY_ENC_SO_ds_SignatureValue(struct zx_ctx* c, struct zx_ds_SignatureValue_s* x )
{
  int len;
  char* buf;
  c->ns_tab = ZX_ALLOC(c, sizeof(zx_ns_tab));
  memcpy(c->ns_tab, zx_ns_tab, sizeof(zx_ns_tab));
  len = zx_LEN_SO_ds_SignatureValue(c, x );
  buf = ZX_ALLOC(c, len+1);
  return zx_easy_enc_common(c, zx_ENC_SO_ds_SignatureValue(c, x, buf ), buf, len);
}

/* FUNC(zx_EASY_ENC_WO_ds_SignatureValue) */

/* Called by: */
struct zx_str* zx_EASY_ENC_WO_ds_SignatureValue(struct zx_ctx* c, struct zx_ds_SignatureValue_s* x )
{
  int len;
  char* buf;
  c->ns_tab = ZX_ALLOC(c, sizeof(zx_ns_tab));
  memcpy(c->ns_tab, zx_ns_tab, sizeof(zx_ns_tab));
  len = zx_LEN_WO_ds_SignatureValue(c, x );
  buf = ZX_ALLOC(c, len+1);
  return zx_easy_enc_common(c, zx_ENC_WO_ds_SignatureValue(c, x, buf ), buf, len);
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

#define EL_NAME   ds_SignedInfo
#define EL_STRUCT zx_ds_SignedInfo_s
#define EL_NS     ds
#define EL_TAG    SignedInfo

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

/* FUNC(zx_LEN_SO_ds_SignedInfo) */

/* Compute length of an element (and its subelements). The XML attributes
 * and elements are processed in schema order. */

/* Called by: */
int zx_LEN_SO_ds_SignedInfo(struct zx_ctx* c, struct zx_ds_SignedInfo_s* x )
{
  struct zx_ns_s* pop_seen = 0;
  struct zx_elem_s* se MAYBE_UNUSED;
#if 1 /* NORMALMODE */
  /* *** in simple_elem case should output ns prefix from ns node. */
  int len = sizeof("<ds:SignedInfo")-1 + 1 + sizeof("</ds:SignedInfo>")-1;
  if (c->inc_ns_len)
    len += zx_len_inc_ns(c, &pop_seen);
  len += zx_len_xmlns_if_not_seen(c, zx_ns_tab+zx_xmlns_ix_ds, &pop_seen);

  len += zx_attr_so_len(x->Id, sizeof("Id")-1);

#else
  /* root node has no begin tag */
  int len = 0;
#endif
  
  {
      struct zx_ds_CanonicalizationMethod_s* e;
      for (e = x->CanonicalizationMethod; e; e = (struct zx_ds_CanonicalizationMethod_s*)e->gg.g.n)
	  len += zx_LEN_SO_ds_CanonicalizationMethod(c, e);
  }
  {
      struct zx_ds_SignatureMethod_s* e;
      for (e = x->SignatureMethod; e; e = (struct zx_ds_SignatureMethod_s*)e->gg.g.n)
	  len += zx_LEN_SO_ds_SignatureMethod(c, e);
  }
  {
      struct zx_ds_Reference_s* e;
      for (e = x->Reference; e; e = (struct zx_ds_Reference_s*)e->gg.g.n)
	  len += zx_LEN_SO_ds_Reference(c, e);
  }


  len += zx_len_so_common(c, &x->gg);
  zx_pop_seen(pop_seen);
  ENC_LEN_DEBUG(x, "ds:SignedInfo", len);
  return len;
}

/* FUNC(zx_LEN_WO_ds_SignedInfo) */

/* Compute length of an element (and its subelements). The XML attributes
 * and elements are processed in wire order and no assumptions
 * are made about namespace prefixes. */

/* Called by: */
int zx_LEN_WO_ds_SignedInfo(struct zx_ctx* c, struct zx_ds_SignedInfo_s* x )
{
  struct zx_ns_s* pop_seen = 0;
  struct zx_elem_s* se MAYBE_UNUSED;
#if 1 /* NORMALMODE */
  int len = 1 + sizeof("SignedInfo")-1 + 1 + 2 + sizeof("SignedInfo")-1 + 1;
  
  if (x->gg.g.ns && x->gg.g.ns->prefix_len)
    len += (x->gg.g.ns->prefix_len + 1) * 2;
  if (c->inc_ns_len)
    len += zx_len_inc_ns(c, &pop_seen);
  len += zx_len_xmlns_if_not_seen(c, x->gg.g.ns, &pop_seen);

  len += zx_attr_wo_len(x->Id, sizeof("Id")-1);

#else
  /* root node has no begin tag */
  int len = 0;
#endif
  
  {
      struct zx_ds_CanonicalizationMethod_s* e;
      for (e = x->CanonicalizationMethod; e; e = (struct zx_ds_CanonicalizationMethod_s*)e->gg.g.n)
	  len += zx_LEN_WO_ds_CanonicalizationMethod(c, e);
  }
  {
      struct zx_ds_SignatureMethod_s* e;
      for (e = x->SignatureMethod; e; e = (struct zx_ds_SignatureMethod_s*)e->gg.g.n)
	  len += zx_LEN_WO_ds_SignatureMethod(c, e);
  }
  {
      struct zx_ds_Reference_s* e;
      for (e = x->Reference; e; e = (struct zx_ds_Reference_s*)e->gg.g.n)
	  len += zx_LEN_WO_ds_Reference(c, e);
  }


  len += zx_len_wo_common(c, &x->gg); 
  zx_pop_seen(pop_seen);
  ENC_LEN_DEBUG(x, "ds:SignedInfo", len);
  return len;
}

/* FUNC(zx_ENC_SO_ds_SignedInfo) */

/* Render element into string. The XML attributes and elements are
 * processed in schema order. This is what you generally want for
 * rendering new data structure to a string. The wo pointers are not used. */

/* Called by: */
char* zx_ENC_SO_ds_SignedInfo(struct zx_ctx* c, struct zx_ds_SignedInfo_s* x, char* p )
{
  struct zx_elem_s* se MAYBE_UNUSED;
  ENC_LEN_DEBUG_BASE;
#if 1 /* NORMALMODE */
  struct zx_ns_s* pop_seen = 0;
  /* *** in simple_elem case should output ns prefix from ns node. */
  ZX_OUT_TAG(p, "<ds:SignedInfo");
  if (c->inc_ns)
    p = zx_enc_inc_ns(c, p, &pop_seen);
  p = zx_enc_xmlns_if_not_seen(c, p, zx_ns_tab+zx_xmlns_ix_ds, &pop_seen);

  p = zx_attr_so_enc(p, x->Id, " Id=\"", sizeof(" Id=\"")-1);

  p = zx_enc_unknown_attrs(p, x->gg.any_attr);
#else
  /* root node has no begin tag */
#endif
  
  {
      struct zx_ds_CanonicalizationMethod_s* e;
      for (e = x->CanonicalizationMethod; e; e = (struct zx_ds_CanonicalizationMethod_s*)e->gg.g.n)
	  p = zx_ENC_SO_ds_CanonicalizationMethod(c, e, p);
  }
  {
      struct zx_ds_SignatureMethod_s* e;
      for (e = x->SignatureMethod; e; e = (struct zx_ds_SignatureMethod_s*)e->gg.g.n)
	  p = zx_ENC_SO_ds_SignatureMethod(c, e, p);
  }
  {
      struct zx_ds_Reference_s* e;
      for (e = x->Reference; e; e = (struct zx_ds_Reference_s*)e->gg.g.n)
	  p = zx_ENC_SO_ds_Reference(c, e, p);
  }

  p = zx_enc_so_unknown_elems_and_content(c, p, &x->gg);
  
#if 1 /* NORMALMODE */
  ZX_OUT_CLOSE_TAG(p, "</ds:SignedInfo>");
  zx_pop_seen(pop_seen);
#else
  /* root node has no end tag either */
#endif
  ENC_LEN_DEBUG(x, "ds:SignedInfo", p-enc_base);
  return p;
}

/* FUNC(zx_ENC_WO_ds_SignedInfo) */

/* Render element into string. The XML attributes and elements are
 * processed in wire order by chasing wo pointers. This is what you want for
 * validating signatures on other people's XML documents. */

/* Called by: */
char* zx_ENC_WO_ds_SignedInfo(struct zx_ctx* c, struct zx_ds_SignedInfo_s* x, char* p )
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
  ZX_OUT_MEM(p, "SignedInfo", sizeof("SignedInfo")-1);
  qq = p;

  /* *** sort the namespaces */
  if (c->inc_ns)
    zx_add_inc_ns(c, &pop_seen);
  zx_add_xmlns_if_not_seen(c, x->gg.g.ns, &pop_seen);

  p = zx_enc_seen(p, pop_seen); 
  p = zx_attr_wo_enc(p, x->Id, "Id=\"", sizeof("Id=\"")-1);

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
  ENC_LEN_DEBUG(x, "ds:SignedInfo", p-enc_base);
  return p;
}

/* FUNC(zx_EASY_ENC_SO_ds_SignedInfo) */

/* Called by: */
struct zx_str* zx_EASY_ENC_SO_ds_SignedInfo(struct zx_ctx* c, struct zx_ds_SignedInfo_s* x )
{
  int len;
  char* buf;
  c->ns_tab = ZX_ALLOC(c, sizeof(zx_ns_tab));
  memcpy(c->ns_tab, zx_ns_tab, sizeof(zx_ns_tab));
  len = zx_LEN_SO_ds_SignedInfo(c, x );
  buf = ZX_ALLOC(c, len+1);
  return zx_easy_enc_common(c, zx_ENC_SO_ds_SignedInfo(c, x, buf ), buf, len);
}

/* FUNC(zx_EASY_ENC_WO_ds_SignedInfo) */

/* Called by: */
struct zx_str* zx_EASY_ENC_WO_ds_SignedInfo(struct zx_ctx* c, struct zx_ds_SignedInfo_s* x )
{
  int len;
  char* buf;
  c->ns_tab = ZX_ALLOC(c, sizeof(zx_ns_tab));
  memcpy(c->ns_tab, zx_ns_tab, sizeof(zx_ns_tab));
  len = zx_LEN_WO_ds_SignedInfo(c, x );
  buf = ZX_ALLOC(c, len+1);
  return zx_easy_enc_common(c, zx_ENC_WO_ds_SignedInfo(c, x, buf ), buf, len);
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

#define EL_NAME   ds_Transform
#define EL_STRUCT zx_ds_Transform_s
#define EL_NS     ds
#define EL_TAG    Transform

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

/* FUNC(zx_LEN_SO_ds_Transform) */

/* Compute length of an element (and its subelements). The XML attributes
 * and elements are processed in schema order. */

/* Called by: */
int zx_LEN_SO_ds_Transform(struct zx_ctx* c, struct zx_ds_Transform_s* x )
{
  struct zx_ns_s* pop_seen = 0;
  struct zx_elem_s* se MAYBE_UNUSED;
#if 1 /* NORMALMODE */
  /* *** in simple_elem case should output ns prefix from ns node. */
  int len = sizeof("<ds:Transform")-1 + 1 + sizeof("</ds:Transform>")-1;
  if (c->inc_ns_len)
    len += zx_len_inc_ns(c, &pop_seen);
  len += zx_len_xmlns_if_not_seen(c, zx_ns_tab+zx_xmlns_ix_ds, &pop_seen);

  len += zx_attr_so_len(x->Algorithm, sizeof("Algorithm")-1);

#else
  /* root node has no begin tag */
  int len = 0;
#endif
  
  for (se = x->XPath; se; se = (struct zx_elem_s*)se->g.n)
    len += zx_LEN_SO_simple_elem(c,se, sizeof("ds:XPath")-1, zx_ns_tab+zx_xmlns_ix_ds);
  {
      struct zx_exca_InclusiveNamespaces_s* e;
      for (e = x->InclusiveNamespaces; e; e = (struct zx_exca_InclusiveNamespaces_s*)e->gg.g.n)
	  len += zx_LEN_SO_exca_InclusiveNamespaces(c, e);
  }


  len += zx_len_so_common(c, &x->gg);
  zx_pop_seen(pop_seen);
  ENC_LEN_DEBUG(x, "ds:Transform", len);
  return len;
}

/* FUNC(zx_LEN_WO_ds_Transform) */

/* Compute length of an element (and its subelements). The XML attributes
 * and elements are processed in wire order and no assumptions
 * are made about namespace prefixes. */

/* Called by: */
int zx_LEN_WO_ds_Transform(struct zx_ctx* c, struct zx_ds_Transform_s* x )
{
  struct zx_ns_s* pop_seen = 0;
  struct zx_elem_s* se MAYBE_UNUSED;
#if 1 /* NORMALMODE */
  int len = 1 + sizeof("Transform")-1 + 1 + 2 + sizeof("Transform")-1 + 1;
  
  if (x->gg.g.ns && x->gg.g.ns->prefix_len)
    len += (x->gg.g.ns->prefix_len + 1) * 2;
  if (c->inc_ns_len)
    len += zx_len_inc_ns(c, &pop_seen);
  len += zx_len_xmlns_if_not_seen(c, x->gg.g.ns, &pop_seen);

  len += zx_attr_wo_len(x->Algorithm, sizeof("Algorithm")-1);

#else
  /* root node has no begin tag */
  int len = 0;
#endif
  
  for (se = x->XPath; se; se = (struct zx_elem_s*)se->g.n)
    len += zx_LEN_WO_simple_elem(c, se, sizeof("XPath")-1);
  {
      struct zx_exca_InclusiveNamespaces_s* e;
      for (e = x->InclusiveNamespaces; e; e = (struct zx_exca_InclusiveNamespaces_s*)e->gg.g.n)
	  len += zx_LEN_WO_exca_InclusiveNamespaces(c, e);
  }


  len += zx_len_wo_common(c, &x->gg); 
  zx_pop_seen(pop_seen);
  ENC_LEN_DEBUG(x, "ds:Transform", len);
  return len;
}

/* FUNC(zx_ENC_SO_ds_Transform) */

/* Render element into string. The XML attributes and elements are
 * processed in schema order. This is what you generally want for
 * rendering new data structure to a string. The wo pointers are not used. */

/* Called by: */
char* zx_ENC_SO_ds_Transform(struct zx_ctx* c, struct zx_ds_Transform_s* x, char* p )
{
  struct zx_elem_s* se MAYBE_UNUSED;
  ENC_LEN_DEBUG_BASE;
#if 1 /* NORMALMODE */
  struct zx_ns_s* pop_seen = 0;
  /* *** in simple_elem case should output ns prefix from ns node. */
  ZX_OUT_TAG(p, "<ds:Transform");
  if (c->inc_ns)
    p = zx_enc_inc_ns(c, p, &pop_seen);
  p = zx_enc_xmlns_if_not_seen(c, p, zx_ns_tab+zx_xmlns_ix_ds, &pop_seen);

  p = zx_attr_so_enc(p, x->Algorithm, " Algorithm=\"", sizeof(" Algorithm=\"")-1);

  p = zx_enc_unknown_attrs(p, x->gg.any_attr);
#else
  /* root node has no begin tag */
#endif
  
  for (se = x->XPath; se; se = (struct zx_elem_s*)se->g.n)
    p = zx_ENC_SO_simple_elem(c, se, p, "ds:XPath", sizeof("ds:XPath")-1, zx_ns_tab+zx_xmlns_ix_ds);
  {
      struct zx_exca_InclusiveNamespaces_s* e;
      for (e = x->InclusiveNamespaces; e; e = (struct zx_exca_InclusiveNamespaces_s*)e->gg.g.n)
	  p = zx_ENC_SO_exca_InclusiveNamespaces(c, e, p);
  }

  p = zx_enc_so_unknown_elems_and_content(c, p, &x->gg);
  
#if 1 /* NORMALMODE */
  ZX_OUT_CLOSE_TAG(p, "</ds:Transform>");
  zx_pop_seen(pop_seen);
#else
  /* root node has no end tag either */
#endif
  ENC_LEN_DEBUG(x, "ds:Transform", p-enc_base);
  return p;
}

/* FUNC(zx_ENC_WO_ds_Transform) */

/* Render element into string. The XML attributes and elements are
 * processed in wire order by chasing wo pointers. This is what you want for
 * validating signatures on other people's XML documents. */

/* Called by: */
char* zx_ENC_WO_ds_Transform(struct zx_ctx* c, struct zx_ds_Transform_s* x, char* p )
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
  ZX_OUT_MEM(p, "Transform", sizeof("Transform")-1);
  qq = p;

  /* *** sort the namespaces */
  if (c->inc_ns)
    zx_add_inc_ns(c, &pop_seen);
  zx_add_xmlns_if_not_seen(c, x->gg.g.ns, &pop_seen);

  p = zx_enc_seen(p, pop_seen); 
  p = zx_attr_wo_enc(p, x->Algorithm, "Algorithm=\"", sizeof("Algorithm=\"")-1);

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
  ENC_LEN_DEBUG(x, "ds:Transform", p-enc_base);
  return p;
}

/* FUNC(zx_EASY_ENC_SO_ds_Transform) */

/* Called by: */
struct zx_str* zx_EASY_ENC_SO_ds_Transform(struct zx_ctx* c, struct zx_ds_Transform_s* x )
{
  int len;
  char* buf;
  c->ns_tab = ZX_ALLOC(c, sizeof(zx_ns_tab));
  memcpy(c->ns_tab, zx_ns_tab, sizeof(zx_ns_tab));
  len = zx_LEN_SO_ds_Transform(c, x );
  buf = ZX_ALLOC(c, len+1);
  return zx_easy_enc_common(c, zx_ENC_SO_ds_Transform(c, x, buf ), buf, len);
}

/* FUNC(zx_EASY_ENC_WO_ds_Transform) */

/* Called by: */
struct zx_str* zx_EASY_ENC_WO_ds_Transform(struct zx_ctx* c, struct zx_ds_Transform_s* x )
{
  int len;
  char* buf;
  c->ns_tab = ZX_ALLOC(c, sizeof(zx_ns_tab));
  memcpy(c->ns_tab, zx_ns_tab, sizeof(zx_ns_tab));
  len = zx_LEN_WO_ds_Transform(c, x );
  buf = ZX_ALLOC(c, len+1);
  return zx_easy_enc_common(c, zx_ENC_WO_ds_Transform(c, x, buf ), buf, len);
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

#define EL_NAME   ds_Transforms
#define EL_STRUCT zx_ds_Transforms_s
#define EL_NS     ds
#define EL_TAG    Transforms

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

/* FUNC(zx_LEN_SO_ds_Transforms) */

/* Compute length of an element (and its subelements). The XML attributes
 * and elements are processed in schema order. */

/* Called by: */
int zx_LEN_SO_ds_Transforms(struct zx_ctx* c, struct zx_ds_Transforms_s* x )
{
  struct zx_ns_s* pop_seen = 0;
  struct zx_elem_s* se MAYBE_UNUSED;
#if 1 /* NORMALMODE */
  /* *** in simple_elem case should output ns prefix from ns node. */
  int len = sizeof("<ds:Transforms")-1 + 1 + sizeof("</ds:Transforms>")-1;
  if (c->inc_ns_len)
    len += zx_len_inc_ns(c, &pop_seen);
  len += zx_len_xmlns_if_not_seen(c, zx_ns_tab+zx_xmlns_ix_ds, &pop_seen);


#else
  /* root node has no begin tag */
  int len = 0;
#endif
  
  {
      struct zx_ds_Transform_s* e;
      for (e = x->Transform; e; e = (struct zx_ds_Transform_s*)e->gg.g.n)
	  len += zx_LEN_SO_ds_Transform(c, e);
  }


  len += zx_len_so_common(c, &x->gg);
  zx_pop_seen(pop_seen);
  ENC_LEN_DEBUG(x, "ds:Transforms", len);
  return len;
}

/* FUNC(zx_LEN_WO_ds_Transforms) */

/* Compute length of an element (and its subelements). The XML attributes
 * and elements are processed in wire order and no assumptions
 * are made about namespace prefixes. */

/* Called by: */
int zx_LEN_WO_ds_Transforms(struct zx_ctx* c, struct zx_ds_Transforms_s* x )
{
  struct zx_ns_s* pop_seen = 0;
  struct zx_elem_s* se MAYBE_UNUSED;
#if 1 /* NORMALMODE */
  int len = 1 + sizeof("Transforms")-1 + 1 + 2 + sizeof("Transforms")-1 + 1;
  
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
      struct zx_ds_Transform_s* e;
      for (e = x->Transform; e; e = (struct zx_ds_Transform_s*)e->gg.g.n)
	  len += zx_LEN_WO_ds_Transform(c, e);
  }


  len += zx_len_wo_common(c, &x->gg); 
  zx_pop_seen(pop_seen);
  ENC_LEN_DEBUG(x, "ds:Transforms", len);
  return len;
}

/* FUNC(zx_ENC_SO_ds_Transforms) */

/* Render element into string. The XML attributes and elements are
 * processed in schema order. This is what you generally want for
 * rendering new data structure to a string. The wo pointers are not used. */

/* Called by: */
char* zx_ENC_SO_ds_Transforms(struct zx_ctx* c, struct zx_ds_Transforms_s* x, char* p )
{
  struct zx_elem_s* se MAYBE_UNUSED;
  ENC_LEN_DEBUG_BASE;
#if 1 /* NORMALMODE */
  struct zx_ns_s* pop_seen = 0;
  /* *** in simple_elem case should output ns prefix from ns node. */
  ZX_OUT_TAG(p, "<ds:Transforms");
  if (c->inc_ns)
    p = zx_enc_inc_ns(c, p, &pop_seen);
  p = zx_enc_xmlns_if_not_seen(c, p, zx_ns_tab+zx_xmlns_ix_ds, &pop_seen);


  p = zx_enc_unknown_attrs(p, x->gg.any_attr);
#else
  /* root node has no begin tag */
#endif
  
  {
      struct zx_ds_Transform_s* e;
      for (e = x->Transform; e; e = (struct zx_ds_Transform_s*)e->gg.g.n)
	  p = zx_ENC_SO_ds_Transform(c, e, p);
  }

  p = zx_enc_so_unknown_elems_and_content(c, p, &x->gg);
  
#if 1 /* NORMALMODE */
  ZX_OUT_CLOSE_TAG(p, "</ds:Transforms>");
  zx_pop_seen(pop_seen);
#else
  /* root node has no end tag either */
#endif
  ENC_LEN_DEBUG(x, "ds:Transforms", p-enc_base);
  return p;
}

/* FUNC(zx_ENC_WO_ds_Transforms) */

/* Render element into string. The XML attributes and elements are
 * processed in wire order by chasing wo pointers. This is what you want for
 * validating signatures on other people's XML documents. */

/* Called by: */
char* zx_ENC_WO_ds_Transforms(struct zx_ctx* c, struct zx_ds_Transforms_s* x, char* p )
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
  ZX_OUT_MEM(p, "Transforms", sizeof("Transforms")-1);
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
  ENC_LEN_DEBUG(x, "ds:Transforms", p-enc_base);
  return p;
}

/* FUNC(zx_EASY_ENC_SO_ds_Transforms) */

/* Called by: */
struct zx_str* zx_EASY_ENC_SO_ds_Transforms(struct zx_ctx* c, struct zx_ds_Transforms_s* x )
{
  int len;
  char* buf;
  c->ns_tab = ZX_ALLOC(c, sizeof(zx_ns_tab));
  memcpy(c->ns_tab, zx_ns_tab, sizeof(zx_ns_tab));
  len = zx_LEN_SO_ds_Transforms(c, x );
  buf = ZX_ALLOC(c, len+1);
  return zx_easy_enc_common(c, zx_ENC_SO_ds_Transforms(c, x, buf ), buf, len);
}

/* FUNC(zx_EASY_ENC_WO_ds_Transforms) */

/* Called by: */
struct zx_str* zx_EASY_ENC_WO_ds_Transforms(struct zx_ctx* c, struct zx_ds_Transforms_s* x )
{
  int len;
  char* buf;
  c->ns_tab = ZX_ALLOC(c, sizeof(zx_ns_tab));
  memcpy(c->ns_tab, zx_ns_tab, sizeof(zx_ns_tab));
  len = zx_LEN_WO_ds_Transforms(c, x );
  buf = ZX_ALLOC(c, len+1);
  return zx_easy_enc_common(c, zx_ENC_WO_ds_Transforms(c, x, buf ), buf, len);
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

#define EL_NAME   ds_X509Data
#define EL_STRUCT zx_ds_X509Data_s
#define EL_NS     ds
#define EL_TAG    X509Data

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

/* FUNC(zx_LEN_SO_ds_X509Data) */

/* Compute length of an element (and its subelements). The XML attributes
 * and elements are processed in schema order. */

/* Called by: */
int zx_LEN_SO_ds_X509Data(struct zx_ctx* c, struct zx_ds_X509Data_s* x )
{
  struct zx_ns_s* pop_seen = 0;
  struct zx_elem_s* se MAYBE_UNUSED;
#if 1 /* NORMALMODE */
  /* *** in simple_elem case should output ns prefix from ns node. */
  int len = sizeof("<ds:X509Data")-1 + 1 + sizeof("</ds:X509Data>")-1;
  if (c->inc_ns_len)
    len += zx_len_inc_ns(c, &pop_seen);
  len += zx_len_xmlns_if_not_seen(c, zx_ns_tab+zx_xmlns_ix_ds, &pop_seen);


#else
  /* root node has no begin tag */
  int len = 0;
#endif
  
  {
      struct zx_ds_X509IssuerSerial_s* e;
      for (e = x->X509IssuerSerial; e; e = (struct zx_ds_X509IssuerSerial_s*)e->gg.g.n)
	  len += zx_LEN_SO_ds_X509IssuerSerial(c, e);
  }
  for (se = x->X509SKI; se; se = (struct zx_elem_s*)se->g.n)
    len += zx_LEN_SO_simple_elem(c,se, sizeof("ds:X509SKI")-1, zx_ns_tab+zx_xmlns_ix_ds);
  for (se = x->X509SubjectName; se; se = (struct zx_elem_s*)se->g.n)
    len += zx_LEN_SO_simple_elem(c,se, sizeof("ds:X509SubjectName")-1, zx_ns_tab+zx_xmlns_ix_ds);
  for (se = x->X509Certificate; se; se = (struct zx_elem_s*)se->g.n)
    len += zx_LEN_SO_simple_elem(c,se, sizeof("ds:X509Certificate")-1, zx_ns_tab+zx_xmlns_ix_ds);
  for (se = x->X509CRL; se; se = (struct zx_elem_s*)se->g.n)
    len += zx_LEN_SO_simple_elem(c,se, sizeof("ds:X509CRL")-1, zx_ns_tab+zx_xmlns_ix_ds);


  len += zx_len_so_common(c, &x->gg);
  zx_pop_seen(pop_seen);
  ENC_LEN_DEBUG(x, "ds:X509Data", len);
  return len;
}

/* FUNC(zx_LEN_WO_ds_X509Data) */

/* Compute length of an element (and its subelements). The XML attributes
 * and elements are processed in wire order and no assumptions
 * are made about namespace prefixes. */

/* Called by: */
int zx_LEN_WO_ds_X509Data(struct zx_ctx* c, struct zx_ds_X509Data_s* x )
{
  struct zx_ns_s* pop_seen = 0;
  struct zx_elem_s* se MAYBE_UNUSED;
#if 1 /* NORMALMODE */
  int len = 1 + sizeof("X509Data")-1 + 1 + 2 + sizeof("X509Data")-1 + 1;
  
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
      struct zx_ds_X509IssuerSerial_s* e;
      for (e = x->X509IssuerSerial; e; e = (struct zx_ds_X509IssuerSerial_s*)e->gg.g.n)
	  len += zx_LEN_WO_ds_X509IssuerSerial(c, e);
  }
  for (se = x->X509SKI; se; se = (struct zx_elem_s*)se->g.n)
    len += zx_LEN_WO_simple_elem(c, se, sizeof("X509SKI")-1);
  for (se = x->X509SubjectName; se; se = (struct zx_elem_s*)se->g.n)
    len += zx_LEN_WO_simple_elem(c, se, sizeof("X509SubjectName")-1);
  for (se = x->X509Certificate; se; se = (struct zx_elem_s*)se->g.n)
    len += zx_LEN_WO_simple_elem(c, se, sizeof("X509Certificate")-1);
  for (se = x->X509CRL; se; se = (struct zx_elem_s*)se->g.n)
    len += zx_LEN_WO_simple_elem(c, se, sizeof("X509CRL")-1);


  len += zx_len_wo_common(c, &x->gg); 
  zx_pop_seen(pop_seen);
  ENC_LEN_DEBUG(x, "ds:X509Data", len);
  return len;
}

/* FUNC(zx_ENC_SO_ds_X509Data) */

/* Render element into string. The XML attributes and elements are
 * processed in schema order. This is what you generally want for
 * rendering new data structure to a string. The wo pointers are not used. */

/* Called by: */
char* zx_ENC_SO_ds_X509Data(struct zx_ctx* c, struct zx_ds_X509Data_s* x, char* p )
{
  struct zx_elem_s* se MAYBE_UNUSED;
  ENC_LEN_DEBUG_BASE;
#if 1 /* NORMALMODE */
  struct zx_ns_s* pop_seen = 0;
  /* *** in simple_elem case should output ns prefix from ns node. */
  ZX_OUT_TAG(p, "<ds:X509Data");
  if (c->inc_ns)
    p = zx_enc_inc_ns(c, p, &pop_seen);
  p = zx_enc_xmlns_if_not_seen(c, p, zx_ns_tab+zx_xmlns_ix_ds, &pop_seen);


  p = zx_enc_unknown_attrs(p, x->gg.any_attr);
#else
  /* root node has no begin tag */
#endif
  
  {
      struct zx_ds_X509IssuerSerial_s* e;
      for (e = x->X509IssuerSerial; e; e = (struct zx_ds_X509IssuerSerial_s*)e->gg.g.n)
	  p = zx_ENC_SO_ds_X509IssuerSerial(c, e, p);
  }
  for (se = x->X509SKI; se; se = (struct zx_elem_s*)se->g.n)
    p = zx_ENC_SO_simple_elem(c, se, p, "ds:X509SKI", sizeof("ds:X509SKI")-1, zx_ns_tab+zx_xmlns_ix_ds);
  for (se = x->X509SubjectName; se; se = (struct zx_elem_s*)se->g.n)
    p = zx_ENC_SO_simple_elem(c, se, p, "ds:X509SubjectName", sizeof("ds:X509SubjectName")-1, zx_ns_tab+zx_xmlns_ix_ds);
  for (se = x->X509Certificate; se; se = (struct zx_elem_s*)se->g.n)
    p = zx_ENC_SO_simple_elem(c, se, p, "ds:X509Certificate", sizeof("ds:X509Certificate")-1, zx_ns_tab+zx_xmlns_ix_ds);
  for (se = x->X509CRL; se; se = (struct zx_elem_s*)se->g.n)
    p = zx_ENC_SO_simple_elem(c, se, p, "ds:X509CRL", sizeof("ds:X509CRL")-1, zx_ns_tab+zx_xmlns_ix_ds);

  p = zx_enc_so_unknown_elems_and_content(c, p, &x->gg);
  
#if 1 /* NORMALMODE */
  ZX_OUT_CLOSE_TAG(p, "</ds:X509Data>");
  zx_pop_seen(pop_seen);
#else
  /* root node has no end tag either */
#endif
  ENC_LEN_DEBUG(x, "ds:X509Data", p-enc_base);
  return p;
}

/* FUNC(zx_ENC_WO_ds_X509Data) */

/* Render element into string. The XML attributes and elements are
 * processed in wire order by chasing wo pointers. This is what you want for
 * validating signatures on other people's XML documents. */

/* Called by: */
char* zx_ENC_WO_ds_X509Data(struct zx_ctx* c, struct zx_ds_X509Data_s* x, char* p )
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
  ZX_OUT_MEM(p, "X509Data", sizeof("X509Data")-1);
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
  ENC_LEN_DEBUG(x, "ds:X509Data", p-enc_base);
  return p;
}

/* FUNC(zx_EASY_ENC_SO_ds_X509Data) */

/* Called by: */
struct zx_str* zx_EASY_ENC_SO_ds_X509Data(struct zx_ctx* c, struct zx_ds_X509Data_s* x )
{
  int len;
  char* buf;
  c->ns_tab = ZX_ALLOC(c, sizeof(zx_ns_tab));
  memcpy(c->ns_tab, zx_ns_tab, sizeof(zx_ns_tab));
  len = zx_LEN_SO_ds_X509Data(c, x );
  buf = ZX_ALLOC(c, len+1);
  return zx_easy_enc_common(c, zx_ENC_SO_ds_X509Data(c, x, buf ), buf, len);
}

/* FUNC(zx_EASY_ENC_WO_ds_X509Data) */

/* Called by: */
struct zx_str* zx_EASY_ENC_WO_ds_X509Data(struct zx_ctx* c, struct zx_ds_X509Data_s* x )
{
  int len;
  char* buf;
  c->ns_tab = ZX_ALLOC(c, sizeof(zx_ns_tab));
  memcpy(c->ns_tab, zx_ns_tab, sizeof(zx_ns_tab));
  len = zx_LEN_WO_ds_X509Data(c, x );
  buf = ZX_ALLOC(c, len+1);
  return zx_easy_enc_common(c, zx_ENC_WO_ds_X509Data(c, x, buf ), buf, len);
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

#define EL_NAME   ds_X509IssuerSerial
#define EL_STRUCT zx_ds_X509IssuerSerial_s
#define EL_NS     ds
#define EL_TAG    X509IssuerSerial

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

/* FUNC(zx_LEN_SO_ds_X509IssuerSerial) */

/* Compute length of an element (and its subelements). The XML attributes
 * and elements are processed in schema order. */

/* Called by: */
int zx_LEN_SO_ds_X509IssuerSerial(struct zx_ctx* c, struct zx_ds_X509IssuerSerial_s* x )
{
  struct zx_ns_s* pop_seen = 0;
  struct zx_elem_s* se MAYBE_UNUSED;
#if 1 /* NORMALMODE */
  /* *** in simple_elem case should output ns prefix from ns node. */
  int len = sizeof("<ds:X509IssuerSerial")-1 + 1 + sizeof("</ds:X509IssuerSerial>")-1;
  if (c->inc_ns_len)
    len += zx_len_inc_ns(c, &pop_seen);
  len += zx_len_xmlns_if_not_seen(c, zx_ns_tab+zx_xmlns_ix_ds, &pop_seen);


#else
  /* root node has no begin tag */
  int len = 0;
#endif
  
  for (se = x->X509IssuerName; se; se = (struct zx_elem_s*)se->g.n)
    len += zx_LEN_SO_simple_elem(c,se, sizeof("ds:X509IssuerName")-1, zx_ns_tab+zx_xmlns_ix_ds);
  for (se = x->X509SerialNumber; se; se = (struct zx_elem_s*)se->g.n)
    len += zx_LEN_SO_simple_elem(c,se, sizeof("ds:X509SerialNumber")-1, zx_ns_tab+zx_xmlns_ix_ds);


  len += zx_len_so_common(c, &x->gg);
  zx_pop_seen(pop_seen);
  ENC_LEN_DEBUG(x, "ds:X509IssuerSerial", len);
  return len;
}

/* FUNC(zx_LEN_WO_ds_X509IssuerSerial) */

/* Compute length of an element (and its subelements). The XML attributes
 * and elements are processed in wire order and no assumptions
 * are made about namespace prefixes. */

/* Called by: */
int zx_LEN_WO_ds_X509IssuerSerial(struct zx_ctx* c, struct zx_ds_X509IssuerSerial_s* x )
{
  struct zx_ns_s* pop_seen = 0;
  struct zx_elem_s* se MAYBE_UNUSED;
#if 1 /* NORMALMODE */
  int len = 1 + sizeof("X509IssuerSerial")-1 + 1 + 2 + sizeof("X509IssuerSerial")-1 + 1;
  
  if (x->gg.g.ns && x->gg.g.ns->prefix_len)
    len += (x->gg.g.ns->prefix_len + 1) * 2;
  if (c->inc_ns_len)
    len += zx_len_inc_ns(c, &pop_seen);
  len += zx_len_xmlns_if_not_seen(c, x->gg.g.ns, &pop_seen);


#else
  /* root node has no begin tag */
  int len = 0;
#endif
  
  for (se = x->X509IssuerName; se; se = (struct zx_elem_s*)se->g.n)
    len += zx_LEN_WO_simple_elem(c, se, sizeof("X509IssuerName")-1);
  for (se = x->X509SerialNumber; se; se = (struct zx_elem_s*)se->g.n)
    len += zx_LEN_WO_simple_elem(c, se, sizeof("X509SerialNumber")-1);


  len += zx_len_wo_common(c, &x->gg); 
  zx_pop_seen(pop_seen);
  ENC_LEN_DEBUG(x, "ds:X509IssuerSerial", len);
  return len;
}

/* FUNC(zx_ENC_SO_ds_X509IssuerSerial) */

/* Render element into string. The XML attributes and elements are
 * processed in schema order. This is what you generally want for
 * rendering new data structure to a string. The wo pointers are not used. */

/* Called by: */
char* zx_ENC_SO_ds_X509IssuerSerial(struct zx_ctx* c, struct zx_ds_X509IssuerSerial_s* x, char* p )
{
  struct zx_elem_s* se MAYBE_UNUSED;
  ENC_LEN_DEBUG_BASE;
#if 1 /* NORMALMODE */
  struct zx_ns_s* pop_seen = 0;
  /* *** in simple_elem case should output ns prefix from ns node. */
  ZX_OUT_TAG(p, "<ds:X509IssuerSerial");
  if (c->inc_ns)
    p = zx_enc_inc_ns(c, p, &pop_seen);
  p = zx_enc_xmlns_if_not_seen(c, p, zx_ns_tab+zx_xmlns_ix_ds, &pop_seen);


  p = zx_enc_unknown_attrs(p, x->gg.any_attr);
#else
  /* root node has no begin tag */
#endif
  
  for (se = x->X509IssuerName; se; se = (struct zx_elem_s*)se->g.n)
    p = zx_ENC_SO_simple_elem(c, se, p, "ds:X509IssuerName", sizeof("ds:X509IssuerName")-1, zx_ns_tab+zx_xmlns_ix_ds);
  for (se = x->X509SerialNumber; se; se = (struct zx_elem_s*)se->g.n)
    p = zx_ENC_SO_simple_elem(c, se, p, "ds:X509SerialNumber", sizeof("ds:X509SerialNumber")-1, zx_ns_tab+zx_xmlns_ix_ds);

  p = zx_enc_so_unknown_elems_and_content(c, p, &x->gg);
  
#if 1 /* NORMALMODE */
  ZX_OUT_CLOSE_TAG(p, "</ds:X509IssuerSerial>");
  zx_pop_seen(pop_seen);
#else
  /* root node has no end tag either */
#endif
  ENC_LEN_DEBUG(x, "ds:X509IssuerSerial", p-enc_base);
  return p;
}

/* FUNC(zx_ENC_WO_ds_X509IssuerSerial) */

/* Render element into string. The XML attributes and elements are
 * processed in wire order by chasing wo pointers. This is what you want for
 * validating signatures on other people's XML documents. */

/* Called by: */
char* zx_ENC_WO_ds_X509IssuerSerial(struct zx_ctx* c, struct zx_ds_X509IssuerSerial_s* x, char* p )
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
  ZX_OUT_MEM(p, "X509IssuerSerial", sizeof("X509IssuerSerial")-1);
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
  ENC_LEN_DEBUG(x, "ds:X509IssuerSerial", p-enc_base);
  return p;
}

/* FUNC(zx_EASY_ENC_SO_ds_X509IssuerSerial) */

/* Called by: */
struct zx_str* zx_EASY_ENC_SO_ds_X509IssuerSerial(struct zx_ctx* c, struct zx_ds_X509IssuerSerial_s* x )
{
  int len;
  char* buf;
  c->ns_tab = ZX_ALLOC(c, sizeof(zx_ns_tab));
  memcpy(c->ns_tab, zx_ns_tab, sizeof(zx_ns_tab));
  len = zx_LEN_SO_ds_X509IssuerSerial(c, x );
  buf = ZX_ALLOC(c, len+1);
  return zx_easy_enc_common(c, zx_ENC_SO_ds_X509IssuerSerial(c, x, buf ), buf, len);
}

/* FUNC(zx_EASY_ENC_WO_ds_X509IssuerSerial) */

/* Called by: */
struct zx_str* zx_EASY_ENC_WO_ds_X509IssuerSerial(struct zx_ctx* c, struct zx_ds_X509IssuerSerial_s* x )
{
  int len;
  char* buf;
  c->ns_tab = ZX_ALLOC(c, sizeof(zx_ns_tab));
  memcpy(c->ns_tab, zx_ns_tab, sizeof(zx_ns_tab));
  len = zx_LEN_WO_ds_X509IssuerSerial(c, x );
  buf = ZX_ALLOC(c, len+1);
  return zx_easy_enc_common(c, zx_ENC_WO_ds_X509IssuerSerial(c, x, buf ), buf, len);
}




/* EOF -- c/zx-ds-enc.c */
