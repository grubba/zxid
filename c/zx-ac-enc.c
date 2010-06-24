/* c/zx-ac-enc.c - WARNING: This file was automatically generated. DO NOT EDIT!
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
#include "c/zx-ac-data.h"
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

#define EL_NAME   ac_ActivationLimit
#define EL_STRUCT zx_ac_ActivationLimit_s
#define EL_NS     ac
#define EL_TAG    ActivationLimit

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

/* FUNC(zx_LEN_SO_ac_ActivationLimit) */

/* Compute length of an element (and its subelements). The XML attributes
 * and elements are processed in schema order. */

/* Called by: */
int zx_LEN_SO_ac_ActivationLimit(struct zx_ctx* c, struct zx_ac_ActivationLimit_s* x )
{
  struct zx_ns_s* pop_seen = 0;
  struct zx_elem_s* se MAYBE_UNUSED;
#if 1 /* NORMALMODE */
  /* *** in simple_elem case should output ns prefix from ns node. */
  int len = sizeof("<ac:ActivationLimit")-1 + 1 + sizeof("</ac:ActivationLimit>")-1;
  if (c->inc_ns_len)
    len += zx_len_inc_ns(c, &pop_seen);
  len += zx_len_xmlns_if_not_seen(c, zx_ns_tab+zx_xmlns_ix_ac, &pop_seen);


#else
  /* root node has no begin tag */
  int len = 0;
#endif
  
  {
      struct zx_ac_ActivationLimitDuration_s* e;
      for (e = x->ActivationLimitDuration; e; e = (struct zx_ac_ActivationLimitDuration_s*)e->gg.g.n)
	  len += zx_LEN_SO_ac_ActivationLimitDuration(c, e);
  }
  {
      struct zx_ac_ActivationLimitUsages_s* e;
      for (e = x->ActivationLimitUsages; e; e = (struct zx_ac_ActivationLimitUsages_s*)e->gg.g.n)
	  len += zx_LEN_SO_ac_ActivationLimitUsages(c, e);
  }
  for (se = x->ActivationLimitSession; se; se = (struct zx_elem_s*)se->g.n)
    len += zx_LEN_SO_simple_elem(c,se, sizeof("ac:ActivationLimitSession")-1, zx_ns_tab+zx_xmlns_ix_ac);


  len += zx_len_so_common(c, &x->gg);
  zx_pop_seen(pop_seen);
  ENC_LEN_DEBUG(x, "ac:ActivationLimit", len);
  return len;
}

/* FUNC(zx_LEN_WO_ac_ActivationLimit) */

/* Compute length of an element (and its subelements). The XML attributes
 * and elements are processed in wire order and no assumptions
 * are made about namespace prefixes. */

/* Called by: */
int zx_LEN_WO_ac_ActivationLimit(struct zx_ctx* c, struct zx_ac_ActivationLimit_s* x )
{
  struct zx_ns_s* pop_seen = 0;
  struct zx_elem_s* se MAYBE_UNUSED;
#if 1 /* NORMALMODE */
  int len = 1 + sizeof("ActivationLimit")-1 + 1 + 2 + sizeof("ActivationLimit")-1 + 1;
  
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
      struct zx_ac_ActivationLimitDuration_s* e;
      for (e = x->ActivationLimitDuration; e; e = (struct zx_ac_ActivationLimitDuration_s*)e->gg.g.n)
	  len += zx_LEN_WO_ac_ActivationLimitDuration(c, e);
  }
  {
      struct zx_ac_ActivationLimitUsages_s* e;
      for (e = x->ActivationLimitUsages; e; e = (struct zx_ac_ActivationLimitUsages_s*)e->gg.g.n)
	  len += zx_LEN_WO_ac_ActivationLimitUsages(c, e);
  }
  for (se = x->ActivationLimitSession; se; se = (struct zx_elem_s*)se->g.n)
    len += zx_LEN_WO_simple_elem(c, se, sizeof("ActivationLimitSession")-1);


  len += zx_len_wo_common(c, &x->gg); 
  zx_pop_seen(pop_seen);
  ENC_LEN_DEBUG(x, "ac:ActivationLimit", len);
  return len;
}

/* FUNC(zx_ENC_SO_ac_ActivationLimit) */

/* Render element into string. The XML attributes and elements are
 * processed in schema order. This is what you generally want for
 * rendering new data structure to a string. The wo pointers are not used. */

/* Called by: */
char* zx_ENC_SO_ac_ActivationLimit(struct zx_ctx* c, struct zx_ac_ActivationLimit_s* x, char* p )
{
  struct zx_elem_s* se MAYBE_UNUSED;
  ENC_LEN_DEBUG_BASE;
#if 1 /* NORMALMODE */
  struct zx_ns_s* pop_seen = 0;
  /* *** in simple_elem case should output ns prefix from ns node. */
  ZX_OUT_TAG(p, "<ac:ActivationLimit");
  if (c->inc_ns)
    p = zx_enc_inc_ns(c, p, &pop_seen);
  p = zx_enc_xmlns_if_not_seen(c, p, zx_ns_tab+zx_xmlns_ix_ac, &pop_seen);


  p = zx_enc_unknown_attrs(p, x->gg.any_attr);
#else
  /* root node has no begin tag */
#endif
  
  {
      struct zx_ac_ActivationLimitDuration_s* e;
      for (e = x->ActivationLimitDuration; e; e = (struct zx_ac_ActivationLimitDuration_s*)e->gg.g.n)
	  p = zx_ENC_SO_ac_ActivationLimitDuration(c, e, p);
  }
  {
      struct zx_ac_ActivationLimitUsages_s* e;
      for (e = x->ActivationLimitUsages; e; e = (struct zx_ac_ActivationLimitUsages_s*)e->gg.g.n)
	  p = zx_ENC_SO_ac_ActivationLimitUsages(c, e, p);
  }
  for (se = x->ActivationLimitSession; se; se = (struct zx_elem_s*)se->g.n)
    p = zx_ENC_SO_simple_elem(c, se, p, "ac:ActivationLimitSession", sizeof("ac:ActivationLimitSession")-1, zx_ns_tab+zx_xmlns_ix_ac);

  p = zx_enc_so_unknown_elems_and_content(c, p, &x->gg);
  
#if 1 /* NORMALMODE */
  ZX_OUT_CLOSE_TAG(p, "</ac:ActivationLimit>");
  zx_pop_seen(pop_seen);
#else
  /* root node has no end tag either */
#endif
  ENC_LEN_DEBUG(x, "ac:ActivationLimit", p-enc_base);
  return p;
}

/* FUNC(zx_ENC_WO_ac_ActivationLimit) */

/* Render element into string. The XML attributes and elements are
 * processed in wire order by chasing wo pointers. This is what you want for
 * validating signatures on other people's XML documents. */

/* Called by: */
char* zx_ENC_WO_ac_ActivationLimit(struct zx_ctx* c, struct zx_ac_ActivationLimit_s* x, char* p )
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
  ZX_OUT_MEM(p, "ActivationLimit", sizeof("ActivationLimit")-1);
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
  ENC_LEN_DEBUG(x, "ac:ActivationLimit", p-enc_base);
  return p;
}

/* FUNC(zx_EASY_ENC_SO_ac_ActivationLimit) */

/* Called by: */
struct zx_str* zx_EASY_ENC_SO_ac_ActivationLimit(struct zx_ctx* c, struct zx_ac_ActivationLimit_s* x )
{
  int len;
  char* buf;
  c->ns_tab = ZX_ALLOC(c, sizeof(zx_ns_tab));
  memcpy(c->ns_tab, zx_ns_tab, sizeof(zx_ns_tab));
  len = zx_LEN_SO_ac_ActivationLimit(c, x );
  buf = ZX_ALLOC(c, len+1);
  return zx_easy_enc_common(c, zx_ENC_SO_ac_ActivationLimit(c, x, buf ), buf, len);
}

/* FUNC(zx_EASY_ENC_WO_ac_ActivationLimit) */

/* Called by: */
struct zx_str* zx_EASY_ENC_WO_ac_ActivationLimit(struct zx_ctx* c, struct zx_ac_ActivationLimit_s* x )
{
  int len;
  char* buf;
  c->ns_tab = ZX_ALLOC(c, sizeof(zx_ns_tab));
  memcpy(c->ns_tab, zx_ns_tab, sizeof(zx_ns_tab));
  len = zx_LEN_WO_ac_ActivationLimit(c, x );
  buf = ZX_ALLOC(c, len+1);
  return zx_easy_enc_common(c, zx_ENC_WO_ac_ActivationLimit(c, x, buf ), buf, len);
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

#define EL_NAME   ac_ActivationLimitDuration
#define EL_STRUCT zx_ac_ActivationLimitDuration_s
#define EL_NS     ac
#define EL_TAG    ActivationLimitDuration

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

/* FUNC(zx_LEN_SO_ac_ActivationLimitDuration) */

/* Compute length of an element (and its subelements). The XML attributes
 * and elements are processed in schema order. */

/* Called by: */
int zx_LEN_SO_ac_ActivationLimitDuration(struct zx_ctx* c, struct zx_ac_ActivationLimitDuration_s* x )
{
  struct zx_ns_s* pop_seen = 0;
  struct zx_elem_s* se MAYBE_UNUSED;
#if 1 /* NORMALMODE */
  /* *** in simple_elem case should output ns prefix from ns node. */
  int len = sizeof("<ac:ActivationLimitDuration")-1 + 1 + sizeof("</ac:ActivationLimitDuration>")-1;
  if (c->inc_ns_len)
    len += zx_len_inc_ns(c, &pop_seen);
  len += zx_len_xmlns_if_not_seen(c, zx_ns_tab+zx_xmlns_ix_ac, &pop_seen);

  len += zx_attr_so_len(x->duration, sizeof("duration")-1);

#else
  /* root node has no begin tag */
  int len = 0;
#endif
  


  len += zx_len_so_common(c, &x->gg);
  zx_pop_seen(pop_seen);
  ENC_LEN_DEBUG(x, "ac:ActivationLimitDuration", len);
  return len;
}

/* FUNC(zx_LEN_WO_ac_ActivationLimitDuration) */

/* Compute length of an element (and its subelements). The XML attributes
 * and elements are processed in wire order and no assumptions
 * are made about namespace prefixes. */

/* Called by: */
int zx_LEN_WO_ac_ActivationLimitDuration(struct zx_ctx* c, struct zx_ac_ActivationLimitDuration_s* x )
{
  struct zx_ns_s* pop_seen = 0;
  struct zx_elem_s* se MAYBE_UNUSED;
#if 1 /* NORMALMODE */
  int len = 1 + sizeof("ActivationLimitDuration")-1 + 1 + 2 + sizeof("ActivationLimitDuration")-1 + 1;
  
  if (x->gg.g.ns && x->gg.g.ns->prefix_len)
    len += (x->gg.g.ns->prefix_len + 1) * 2;
  if (c->inc_ns_len)
    len += zx_len_inc_ns(c, &pop_seen);
  len += zx_len_xmlns_if_not_seen(c, x->gg.g.ns, &pop_seen);

  len += zx_attr_wo_len(x->duration, sizeof("duration")-1);

#else
  /* root node has no begin tag */
  int len = 0;
#endif
  


  len += zx_len_wo_common(c, &x->gg); 
  zx_pop_seen(pop_seen);
  ENC_LEN_DEBUG(x, "ac:ActivationLimitDuration", len);
  return len;
}

/* FUNC(zx_ENC_SO_ac_ActivationLimitDuration) */

/* Render element into string. The XML attributes and elements are
 * processed in schema order. This is what you generally want for
 * rendering new data structure to a string. The wo pointers are not used. */

/* Called by: */
char* zx_ENC_SO_ac_ActivationLimitDuration(struct zx_ctx* c, struct zx_ac_ActivationLimitDuration_s* x, char* p )
{
  struct zx_elem_s* se MAYBE_UNUSED;
  ENC_LEN_DEBUG_BASE;
#if 1 /* NORMALMODE */
  struct zx_ns_s* pop_seen = 0;
  /* *** in simple_elem case should output ns prefix from ns node. */
  ZX_OUT_TAG(p, "<ac:ActivationLimitDuration");
  if (c->inc_ns)
    p = zx_enc_inc_ns(c, p, &pop_seen);
  p = zx_enc_xmlns_if_not_seen(c, p, zx_ns_tab+zx_xmlns_ix_ac, &pop_seen);

  p = zx_attr_so_enc(p, x->duration, " duration=\"", sizeof(" duration=\"")-1);

  p = zx_enc_unknown_attrs(p, x->gg.any_attr);
#else
  /* root node has no begin tag */
#endif
  

  p = zx_enc_so_unknown_elems_and_content(c, p, &x->gg);
  
#if 1 /* NORMALMODE */
  ZX_OUT_CLOSE_TAG(p, "</ac:ActivationLimitDuration>");
  zx_pop_seen(pop_seen);
#else
  /* root node has no end tag either */
#endif
  ENC_LEN_DEBUG(x, "ac:ActivationLimitDuration", p-enc_base);
  return p;
}

/* FUNC(zx_ENC_WO_ac_ActivationLimitDuration) */

/* Render element into string. The XML attributes and elements are
 * processed in wire order by chasing wo pointers. This is what you want for
 * validating signatures on other people's XML documents. */

/* Called by: */
char* zx_ENC_WO_ac_ActivationLimitDuration(struct zx_ctx* c, struct zx_ac_ActivationLimitDuration_s* x, char* p )
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
  ZX_OUT_MEM(p, "ActivationLimitDuration", sizeof("ActivationLimitDuration")-1);
  qq = p;

  /* *** sort the namespaces */
  if (c->inc_ns)
    zx_add_inc_ns(c, &pop_seen);
  zx_add_xmlns_if_not_seen(c, x->gg.g.ns, &pop_seen);

  p = zx_enc_seen(p, pop_seen); 
  p = zx_attr_wo_enc(p, x->duration, "duration=\"", sizeof("duration=\"")-1);

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
  ENC_LEN_DEBUG(x, "ac:ActivationLimitDuration", p-enc_base);
  return p;
}

/* FUNC(zx_EASY_ENC_SO_ac_ActivationLimitDuration) */

/* Called by: */
struct zx_str* zx_EASY_ENC_SO_ac_ActivationLimitDuration(struct zx_ctx* c, struct zx_ac_ActivationLimitDuration_s* x )
{
  int len;
  char* buf;
  c->ns_tab = ZX_ALLOC(c, sizeof(zx_ns_tab));
  memcpy(c->ns_tab, zx_ns_tab, sizeof(zx_ns_tab));
  len = zx_LEN_SO_ac_ActivationLimitDuration(c, x );
  buf = ZX_ALLOC(c, len+1);
  return zx_easy_enc_common(c, zx_ENC_SO_ac_ActivationLimitDuration(c, x, buf ), buf, len);
}

/* FUNC(zx_EASY_ENC_WO_ac_ActivationLimitDuration) */

/* Called by: */
struct zx_str* zx_EASY_ENC_WO_ac_ActivationLimitDuration(struct zx_ctx* c, struct zx_ac_ActivationLimitDuration_s* x )
{
  int len;
  char* buf;
  c->ns_tab = ZX_ALLOC(c, sizeof(zx_ns_tab));
  memcpy(c->ns_tab, zx_ns_tab, sizeof(zx_ns_tab));
  len = zx_LEN_WO_ac_ActivationLimitDuration(c, x );
  buf = ZX_ALLOC(c, len+1);
  return zx_easy_enc_common(c, zx_ENC_WO_ac_ActivationLimitDuration(c, x, buf ), buf, len);
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

#define EL_NAME   ac_ActivationLimitUsages
#define EL_STRUCT zx_ac_ActivationLimitUsages_s
#define EL_NS     ac
#define EL_TAG    ActivationLimitUsages

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

/* FUNC(zx_LEN_SO_ac_ActivationLimitUsages) */

/* Compute length of an element (and its subelements). The XML attributes
 * and elements are processed in schema order. */

/* Called by: */
int zx_LEN_SO_ac_ActivationLimitUsages(struct zx_ctx* c, struct zx_ac_ActivationLimitUsages_s* x )
{
  struct zx_ns_s* pop_seen = 0;
  struct zx_elem_s* se MAYBE_UNUSED;
#if 1 /* NORMALMODE */
  /* *** in simple_elem case should output ns prefix from ns node. */
  int len = sizeof("<ac:ActivationLimitUsages")-1 + 1 + sizeof("</ac:ActivationLimitUsages>")-1;
  if (c->inc_ns_len)
    len += zx_len_inc_ns(c, &pop_seen);
  len += zx_len_xmlns_if_not_seen(c, zx_ns_tab+zx_xmlns_ix_ac, &pop_seen);

  len += zx_attr_so_len(x->number, sizeof("number")-1);

#else
  /* root node has no begin tag */
  int len = 0;
#endif
  


  len += zx_len_so_common(c, &x->gg);
  zx_pop_seen(pop_seen);
  ENC_LEN_DEBUG(x, "ac:ActivationLimitUsages", len);
  return len;
}

/* FUNC(zx_LEN_WO_ac_ActivationLimitUsages) */

/* Compute length of an element (and its subelements). The XML attributes
 * and elements are processed in wire order and no assumptions
 * are made about namespace prefixes. */

/* Called by: */
int zx_LEN_WO_ac_ActivationLimitUsages(struct zx_ctx* c, struct zx_ac_ActivationLimitUsages_s* x )
{
  struct zx_ns_s* pop_seen = 0;
  struct zx_elem_s* se MAYBE_UNUSED;
#if 1 /* NORMALMODE */
  int len = 1 + sizeof("ActivationLimitUsages")-1 + 1 + 2 + sizeof("ActivationLimitUsages")-1 + 1;
  
  if (x->gg.g.ns && x->gg.g.ns->prefix_len)
    len += (x->gg.g.ns->prefix_len + 1) * 2;
  if (c->inc_ns_len)
    len += zx_len_inc_ns(c, &pop_seen);
  len += zx_len_xmlns_if_not_seen(c, x->gg.g.ns, &pop_seen);

  len += zx_attr_wo_len(x->number, sizeof("number")-1);

#else
  /* root node has no begin tag */
  int len = 0;
#endif
  


  len += zx_len_wo_common(c, &x->gg); 
  zx_pop_seen(pop_seen);
  ENC_LEN_DEBUG(x, "ac:ActivationLimitUsages", len);
  return len;
}

/* FUNC(zx_ENC_SO_ac_ActivationLimitUsages) */

/* Render element into string. The XML attributes and elements are
 * processed in schema order. This is what you generally want for
 * rendering new data structure to a string. The wo pointers are not used. */

/* Called by: */
char* zx_ENC_SO_ac_ActivationLimitUsages(struct zx_ctx* c, struct zx_ac_ActivationLimitUsages_s* x, char* p )
{
  struct zx_elem_s* se MAYBE_UNUSED;
  ENC_LEN_DEBUG_BASE;
#if 1 /* NORMALMODE */
  struct zx_ns_s* pop_seen = 0;
  /* *** in simple_elem case should output ns prefix from ns node. */
  ZX_OUT_TAG(p, "<ac:ActivationLimitUsages");
  if (c->inc_ns)
    p = zx_enc_inc_ns(c, p, &pop_seen);
  p = zx_enc_xmlns_if_not_seen(c, p, zx_ns_tab+zx_xmlns_ix_ac, &pop_seen);

  p = zx_attr_so_enc(p, x->number, " number=\"", sizeof(" number=\"")-1);

  p = zx_enc_unknown_attrs(p, x->gg.any_attr);
#else
  /* root node has no begin tag */
#endif
  

  p = zx_enc_so_unknown_elems_and_content(c, p, &x->gg);
  
#if 1 /* NORMALMODE */
  ZX_OUT_CLOSE_TAG(p, "</ac:ActivationLimitUsages>");
  zx_pop_seen(pop_seen);
#else
  /* root node has no end tag either */
#endif
  ENC_LEN_DEBUG(x, "ac:ActivationLimitUsages", p-enc_base);
  return p;
}

/* FUNC(zx_ENC_WO_ac_ActivationLimitUsages) */

/* Render element into string. The XML attributes and elements are
 * processed in wire order by chasing wo pointers. This is what you want for
 * validating signatures on other people's XML documents. */

/* Called by: */
char* zx_ENC_WO_ac_ActivationLimitUsages(struct zx_ctx* c, struct zx_ac_ActivationLimitUsages_s* x, char* p )
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
  ZX_OUT_MEM(p, "ActivationLimitUsages", sizeof("ActivationLimitUsages")-1);
  qq = p;

  /* *** sort the namespaces */
  if (c->inc_ns)
    zx_add_inc_ns(c, &pop_seen);
  zx_add_xmlns_if_not_seen(c, x->gg.g.ns, &pop_seen);

  p = zx_enc_seen(p, pop_seen); 
  p = zx_attr_wo_enc(p, x->number, "number=\"", sizeof("number=\"")-1);

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
  ENC_LEN_DEBUG(x, "ac:ActivationLimitUsages", p-enc_base);
  return p;
}

/* FUNC(zx_EASY_ENC_SO_ac_ActivationLimitUsages) */

/* Called by: */
struct zx_str* zx_EASY_ENC_SO_ac_ActivationLimitUsages(struct zx_ctx* c, struct zx_ac_ActivationLimitUsages_s* x )
{
  int len;
  char* buf;
  c->ns_tab = ZX_ALLOC(c, sizeof(zx_ns_tab));
  memcpy(c->ns_tab, zx_ns_tab, sizeof(zx_ns_tab));
  len = zx_LEN_SO_ac_ActivationLimitUsages(c, x );
  buf = ZX_ALLOC(c, len+1);
  return zx_easy_enc_common(c, zx_ENC_SO_ac_ActivationLimitUsages(c, x, buf ), buf, len);
}

/* FUNC(zx_EASY_ENC_WO_ac_ActivationLimitUsages) */

/* Called by: */
struct zx_str* zx_EASY_ENC_WO_ac_ActivationLimitUsages(struct zx_ctx* c, struct zx_ac_ActivationLimitUsages_s* x )
{
  int len;
  char* buf;
  c->ns_tab = ZX_ALLOC(c, sizeof(zx_ns_tab));
  memcpy(c->ns_tab, zx_ns_tab, sizeof(zx_ns_tab));
  len = zx_LEN_WO_ac_ActivationLimitUsages(c, x );
  buf = ZX_ALLOC(c, len+1);
  return zx_easy_enc_common(c, zx_ENC_WO_ac_ActivationLimitUsages(c, x, buf ), buf, len);
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

#define EL_NAME   ac_ActivationPin
#define EL_STRUCT zx_ac_ActivationPin_s
#define EL_NS     ac
#define EL_TAG    ActivationPin

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

/* FUNC(zx_LEN_SO_ac_ActivationPin) */

/* Compute length of an element (and its subelements). The XML attributes
 * and elements are processed in schema order. */

/* Called by: */
int zx_LEN_SO_ac_ActivationPin(struct zx_ctx* c, struct zx_ac_ActivationPin_s* x )
{
  struct zx_ns_s* pop_seen = 0;
  struct zx_elem_s* se MAYBE_UNUSED;
#if 1 /* NORMALMODE */
  /* *** in simple_elem case should output ns prefix from ns node. */
  int len = sizeof("<ac:ActivationPin")-1 + 1 + sizeof("</ac:ActivationPin>")-1;
  if (c->inc_ns_len)
    len += zx_len_inc_ns(c, &pop_seen);
  len += zx_len_xmlns_if_not_seen(c, zx_ns_tab+zx_xmlns_ix_ac, &pop_seen);


#else
  /* root node has no begin tag */
  int len = 0;
#endif
  
  {
      struct zx_ac_Length_s* e;
      for (e = x->Length; e; e = (struct zx_ac_Length_s*)e->gg.g.n)
	  len += zx_LEN_SO_ac_Length(c, e);
  }
  {
      struct zx_ac_Alphabet_s* e;
      for (e = x->Alphabet; e; e = (struct zx_ac_Alphabet_s*)e->gg.g.n)
	  len += zx_LEN_SO_ac_Alphabet(c, e);
  }
  {
      struct zx_ac_Generation_s* e;
      for (e = x->Generation; e; e = (struct zx_ac_Generation_s*)e->gg.g.n)
	  len += zx_LEN_SO_ac_Generation(c, e);
  }
  {
      struct zx_ac_ActivationLimit_s* e;
      for (e = x->ActivationLimit; e; e = (struct zx_ac_ActivationLimit_s*)e->gg.g.n)
	  len += zx_LEN_SO_ac_ActivationLimit(c, e);
  }
  {
      struct zx_ac_Extension_s* e;
      for (e = x->Extension; e; e = (struct zx_ac_Extension_s*)e->gg.g.n)
	  len += zx_LEN_SO_ac_Extension(c, e);
  }


  len += zx_len_so_common(c, &x->gg);
  zx_pop_seen(pop_seen);
  ENC_LEN_DEBUG(x, "ac:ActivationPin", len);
  return len;
}

/* FUNC(zx_LEN_WO_ac_ActivationPin) */

/* Compute length of an element (and its subelements). The XML attributes
 * and elements are processed in wire order and no assumptions
 * are made about namespace prefixes. */

/* Called by: */
int zx_LEN_WO_ac_ActivationPin(struct zx_ctx* c, struct zx_ac_ActivationPin_s* x )
{
  struct zx_ns_s* pop_seen = 0;
  struct zx_elem_s* se MAYBE_UNUSED;
#if 1 /* NORMALMODE */
  int len = 1 + sizeof("ActivationPin")-1 + 1 + 2 + sizeof("ActivationPin")-1 + 1;
  
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
      struct zx_ac_Length_s* e;
      for (e = x->Length; e; e = (struct zx_ac_Length_s*)e->gg.g.n)
	  len += zx_LEN_WO_ac_Length(c, e);
  }
  {
      struct zx_ac_Alphabet_s* e;
      for (e = x->Alphabet; e; e = (struct zx_ac_Alphabet_s*)e->gg.g.n)
	  len += zx_LEN_WO_ac_Alphabet(c, e);
  }
  {
      struct zx_ac_Generation_s* e;
      for (e = x->Generation; e; e = (struct zx_ac_Generation_s*)e->gg.g.n)
	  len += zx_LEN_WO_ac_Generation(c, e);
  }
  {
      struct zx_ac_ActivationLimit_s* e;
      for (e = x->ActivationLimit; e; e = (struct zx_ac_ActivationLimit_s*)e->gg.g.n)
	  len += zx_LEN_WO_ac_ActivationLimit(c, e);
  }
  {
      struct zx_ac_Extension_s* e;
      for (e = x->Extension; e; e = (struct zx_ac_Extension_s*)e->gg.g.n)
	  len += zx_LEN_WO_ac_Extension(c, e);
  }


  len += zx_len_wo_common(c, &x->gg); 
  zx_pop_seen(pop_seen);
  ENC_LEN_DEBUG(x, "ac:ActivationPin", len);
  return len;
}

/* FUNC(zx_ENC_SO_ac_ActivationPin) */

/* Render element into string. The XML attributes and elements are
 * processed in schema order. This is what you generally want for
 * rendering new data structure to a string. The wo pointers are not used. */

/* Called by: */
char* zx_ENC_SO_ac_ActivationPin(struct zx_ctx* c, struct zx_ac_ActivationPin_s* x, char* p )
{
  struct zx_elem_s* se MAYBE_UNUSED;
  ENC_LEN_DEBUG_BASE;
#if 1 /* NORMALMODE */
  struct zx_ns_s* pop_seen = 0;
  /* *** in simple_elem case should output ns prefix from ns node. */
  ZX_OUT_TAG(p, "<ac:ActivationPin");
  if (c->inc_ns)
    p = zx_enc_inc_ns(c, p, &pop_seen);
  p = zx_enc_xmlns_if_not_seen(c, p, zx_ns_tab+zx_xmlns_ix_ac, &pop_seen);


  p = zx_enc_unknown_attrs(p, x->gg.any_attr);
#else
  /* root node has no begin tag */
#endif
  
  {
      struct zx_ac_Length_s* e;
      for (e = x->Length; e; e = (struct zx_ac_Length_s*)e->gg.g.n)
	  p = zx_ENC_SO_ac_Length(c, e, p);
  }
  {
      struct zx_ac_Alphabet_s* e;
      for (e = x->Alphabet; e; e = (struct zx_ac_Alphabet_s*)e->gg.g.n)
	  p = zx_ENC_SO_ac_Alphabet(c, e, p);
  }
  {
      struct zx_ac_Generation_s* e;
      for (e = x->Generation; e; e = (struct zx_ac_Generation_s*)e->gg.g.n)
	  p = zx_ENC_SO_ac_Generation(c, e, p);
  }
  {
      struct zx_ac_ActivationLimit_s* e;
      for (e = x->ActivationLimit; e; e = (struct zx_ac_ActivationLimit_s*)e->gg.g.n)
	  p = zx_ENC_SO_ac_ActivationLimit(c, e, p);
  }
  {
      struct zx_ac_Extension_s* e;
      for (e = x->Extension; e; e = (struct zx_ac_Extension_s*)e->gg.g.n)
	  p = zx_ENC_SO_ac_Extension(c, e, p);
  }

  p = zx_enc_so_unknown_elems_and_content(c, p, &x->gg);
  
#if 1 /* NORMALMODE */
  ZX_OUT_CLOSE_TAG(p, "</ac:ActivationPin>");
  zx_pop_seen(pop_seen);
#else
  /* root node has no end tag either */
#endif
  ENC_LEN_DEBUG(x, "ac:ActivationPin", p-enc_base);
  return p;
}

/* FUNC(zx_ENC_WO_ac_ActivationPin) */

/* Render element into string. The XML attributes and elements are
 * processed in wire order by chasing wo pointers. This is what you want for
 * validating signatures on other people's XML documents. */

/* Called by: */
char* zx_ENC_WO_ac_ActivationPin(struct zx_ctx* c, struct zx_ac_ActivationPin_s* x, char* p )
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
  ZX_OUT_MEM(p, "ActivationPin", sizeof("ActivationPin")-1);
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
  ENC_LEN_DEBUG(x, "ac:ActivationPin", p-enc_base);
  return p;
}

/* FUNC(zx_EASY_ENC_SO_ac_ActivationPin) */

/* Called by: */
struct zx_str* zx_EASY_ENC_SO_ac_ActivationPin(struct zx_ctx* c, struct zx_ac_ActivationPin_s* x )
{
  int len;
  char* buf;
  c->ns_tab = ZX_ALLOC(c, sizeof(zx_ns_tab));
  memcpy(c->ns_tab, zx_ns_tab, sizeof(zx_ns_tab));
  len = zx_LEN_SO_ac_ActivationPin(c, x );
  buf = ZX_ALLOC(c, len+1);
  return zx_easy_enc_common(c, zx_ENC_SO_ac_ActivationPin(c, x, buf ), buf, len);
}

/* FUNC(zx_EASY_ENC_WO_ac_ActivationPin) */

/* Called by: */
struct zx_str* zx_EASY_ENC_WO_ac_ActivationPin(struct zx_ctx* c, struct zx_ac_ActivationPin_s* x )
{
  int len;
  char* buf;
  c->ns_tab = ZX_ALLOC(c, sizeof(zx_ns_tab));
  memcpy(c->ns_tab, zx_ns_tab, sizeof(zx_ns_tab));
  len = zx_LEN_WO_ac_ActivationPin(c, x );
  buf = ZX_ALLOC(c, len+1);
  return zx_easy_enc_common(c, zx_ENC_WO_ac_ActivationPin(c, x, buf ), buf, len);
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

#define EL_NAME   ac_Alphabet
#define EL_STRUCT zx_ac_Alphabet_s
#define EL_NS     ac
#define EL_TAG    Alphabet

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

/* FUNC(zx_LEN_SO_ac_Alphabet) */

/* Compute length of an element (and its subelements). The XML attributes
 * and elements are processed in schema order. */

/* Called by: */
int zx_LEN_SO_ac_Alphabet(struct zx_ctx* c, struct zx_ac_Alphabet_s* x )
{
  struct zx_ns_s* pop_seen = 0;
  struct zx_elem_s* se MAYBE_UNUSED;
#if 1 /* NORMALMODE */
  /* *** in simple_elem case should output ns prefix from ns node. */
  int len = sizeof("<ac:Alphabet")-1 + 1 + sizeof("</ac:Alphabet>")-1;
  if (c->inc_ns_len)
    len += zx_len_inc_ns(c, &pop_seen);
  len += zx_len_xmlns_if_not_seen(c, zx_ns_tab+zx_xmlns_ix_ac, &pop_seen);

  len += zx_attr_so_len(x->case_is_c_keyword, sizeof("case")-1);
  len += zx_attr_so_len(x->excludedChars, sizeof("excludedChars")-1);
  len += zx_attr_so_len(x->requiredChars, sizeof("requiredChars")-1);

#else
  /* root node has no begin tag */
  int len = 0;
#endif
  


  len += zx_len_so_common(c, &x->gg);
  zx_pop_seen(pop_seen);
  ENC_LEN_DEBUG(x, "ac:Alphabet", len);
  return len;
}

/* FUNC(zx_LEN_WO_ac_Alphabet) */

/* Compute length of an element (and its subelements). The XML attributes
 * and elements are processed in wire order and no assumptions
 * are made about namespace prefixes. */

/* Called by: */
int zx_LEN_WO_ac_Alphabet(struct zx_ctx* c, struct zx_ac_Alphabet_s* x )
{
  struct zx_ns_s* pop_seen = 0;
  struct zx_elem_s* se MAYBE_UNUSED;
#if 1 /* NORMALMODE */
  int len = 1 + sizeof("Alphabet")-1 + 1 + 2 + sizeof("Alphabet")-1 + 1;
  
  if (x->gg.g.ns && x->gg.g.ns->prefix_len)
    len += (x->gg.g.ns->prefix_len + 1) * 2;
  if (c->inc_ns_len)
    len += zx_len_inc_ns(c, &pop_seen);
  len += zx_len_xmlns_if_not_seen(c, x->gg.g.ns, &pop_seen);

  len += zx_attr_wo_len(x->case_is_c_keyword, sizeof("case")-1);
  len += zx_attr_wo_len(x->excludedChars, sizeof("excludedChars")-1);
  len += zx_attr_wo_len(x->requiredChars, sizeof("requiredChars")-1);

#else
  /* root node has no begin tag */
  int len = 0;
#endif
  


  len += zx_len_wo_common(c, &x->gg); 
  zx_pop_seen(pop_seen);
  ENC_LEN_DEBUG(x, "ac:Alphabet", len);
  return len;
}

/* FUNC(zx_ENC_SO_ac_Alphabet) */

/* Render element into string. The XML attributes and elements are
 * processed in schema order. This is what you generally want for
 * rendering new data structure to a string. The wo pointers are not used. */

/* Called by: */
char* zx_ENC_SO_ac_Alphabet(struct zx_ctx* c, struct zx_ac_Alphabet_s* x, char* p )
{
  struct zx_elem_s* se MAYBE_UNUSED;
  ENC_LEN_DEBUG_BASE;
#if 1 /* NORMALMODE */
  struct zx_ns_s* pop_seen = 0;
  /* *** in simple_elem case should output ns prefix from ns node. */
  ZX_OUT_TAG(p, "<ac:Alphabet");
  if (c->inc_ns)
    p = zx_enc_inc_ns(c, p, &pop_seen);
  p = zx_enc_xmlns_if_not_seen(c, p, zx_ns_tab+zx_xmlns_ix_ac, &pop_seen);

  p = zx_attr_so_enc(p, x->case_is_c_keyword, " case=\"", sizeof(" case=\"")-1);
  p = zx_attr_so_enc(p, x->excludedChars, " excludedChars=\"", sizeof(" excludedChars=\"")-1);
  p = zx_attr_so_enc(p, x->requiredChars, " requiredChars=\"", sizeof(" requiredChars=\"")-1);

  p = zx_enc_unknown_attrs(p, x->gg.any_attr);
#else
  /* root node has no begin tag */
#endif
  

  p = zx_enc_so_unknown_elems_and_content(c, p, &x->gg);
  
#if 1 /* NORMALMODE */
  ZX_OUT_CLOSE_TAG(p, "</ac:Alphabet>");
  zx_pop_seen(pop_seen);
#else
  /* root node has no end tag either */
#endif
  ENC_LEN_DEBUG(x, "ac:Alphabet", p-enc_base);
  return p;
}

/* FUNC(zx_ENC_WO_ac_Alphabet) */

/* Render element into string. The XML attributes and elements are
 * processed in wire order by chasing wo pointers. This is what you want for
 * validating signatures on other people's XML documents. */

/* Called by: */
char* zx_ENC_WO_ac_Alphabet(struct zx_ctx* c, struct zx_ac_Alphabet_s* x, char* p )
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
  ZX_OUT_MEM(p, "Alphabet", sizeof("Alphabet")-1);
  qq = p;

  /* *** sort the namespaces */
  if (c->inc_ns)
    zx_add_inc_ns(c, &pop_seen);
  zx_add_xmlns_if_not_seen(c, x->gg.g.ns, &pop_seen);

  p = zx_enc_seen(p, pop_seen); 
  p = zx_attr_wo_enc(p, x->case_is_c_keyword, "case=\"", sizeof("case=\"")-1);
  p = zx_attr_wo_enc(p, x->excludedChars, "excludedChars=\"", sizeof("excludedChars=\"")-1);
  p = zx_attr_wo_enc(p, x->requiredChars, "requiredChars=\"", sizeof("requiredChars=\"")-1);

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
  ENC_LEN_DEBUG(x, "ac:Alphabet", p-enc_base);
  return p;
}

/* FUNC(zx_EASY_ENC_SO_ac_Alphabet) */

/* Called by: */
struct zx_str* zx_EASY_ENC_SO_ac_Alphabet(struct zx_ctx* c, struct zx_ac_Alphabet_s* x )
{
  int len;
  char* buf;
  c->ns_tab = ZX_ALLOC(c, sizeof(zx_ns_tab));
  memcpy(c->ns_tab, zx_ns_tab, sizeof(zx_ns_tab));
  len = zx_LEN_SO_ac_Alphabet(c, x );
  buf = ZX_ALLOC(c, len+1);
  return zx_easy_enc_common(c, zx_ENC_SO_ac_Alphabet(c, x, buf ), buf, len);
}

/* FUNC(zx_EASY_ENC_WO_ac_Alphabet) */

/* Called by: */
struct zx_str* zx_EASY_ENC_WO_ac_Alphabet(struct zx_ctx* c, struct zx_ac_Alphabet_s* x )
{
  int len;
  char* buf;
  c->ns_tab = ZX_ALLOC(c, sizeof(zx_ns_tab));
  memcpy(c->ns_tab, zx_ns_tab, sizeof(zx_ns_tab));
  len = zx_LEN_WO_ac_Alphabet(c, x );
  buf = ZX_ALLOC(c, len+1);
  return zx_easy_enc_common(c, zx_ENC_WO_ac_Alphabet(c, x, buf ), buf, len);
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

#define EL_NAME   ac_AsymmetricDecryption
#define EL_STRUCT zx_ac_AsymmetricDecryption_s
#define EL_NS     ac
#define EL_TAG    AsymmetricDecryption

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

/* FUNC(zx_LEN_SO_ac_AsymmetricDecryption) */

/* Compute length of an element (and its subelements). The XML attributes
 * and elements are processed in schema order. */

/* Called by: */
int zx_LEN_SO_ac_AsymmetricDecryption(struct zx_ctx* c, struct zx_ac_AsymmetricDecryption_s* x )
{
  struct zx_ns_s* pop_seen = 0;
  struct zx_elem_s* se MAYBE_UNUSED;
#if 1 /* NORMALMODE */
  /* *** in simple_elem case should output ns prefix from ns node. */
  int len = sizeof("<ac:AsymmetricDecryption")-1 + 1 + sizeof("</ac:AsymmetricDecryption>")-1;
  if (c->inc_ns_len)
    len += zx_len_inc_ns(c, &pop_seen);
  len += zx_len_xmlns_if_not_seen(c, zx_ns_tab+zx_xmlns_ix_ac, &pop_seen);


#else
  /* root node has no begin tag */
  int len = 0;
#endif
  
  {
      struct zx_ac_Extension_s* e;
      for (e = x->Extension; e; e = (struct zx_ac_Extension_s*)e->gg.g.n)
	  len += zx_LEN_SO_ac_Extension(c, e);
  }


  len += zx_len_so_common(c, &x->gg);
  zx_pop_seen(pop_seen);
  ENC_LEN_DEBUG(x, "ac:AsymmetricDecryption", len);
  return len;
}

/* FUNC(zx_LEN_WO_ac_AsymmetricDecryption) */

/* Compute length of an element (and its subelements). The XML attributes
 * and elements are processed in wire order and no assumptions
 * are made about namespace prefixes. */

/* Called by: */
int zx_LEN_WO_ac_AsymmetricDecryption(struct zx_ctx* c, struct zx_ac_AsymmetricDecryption_s* x )
{
  struct zx_ns_s* pop_seen = 0;
  struct zx_elem_s* se MAYBE_UNUSED;
#if 1 /* NORMALMODE */
  int len = 1 + sizeof("AsymmetricDecryption")-1 + 1 + 2 + sizeof("AsymmetricDecryption")-1 + 1;
  
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
      struct zx_ac_Extension_s* e;
      for (e = x->Extension; e; e = (struct zx_ac_Extension_s*)e->gg.g.n)
	  len += zx_LEN_WO_ac_Extension(c, e);
  }


  len += zx_len_wo_common(c, &x->gg); 
  zx_pop_seen(pop_seen);
  ENC_LEN_DEBUG(x, "ac:AsymmetricDecryption", len);
  return len;
}

/* FUNC(zx_ENC_SO_ac_AsymmetricDecryption) */

/* Render element into string. The XML attributes and elements are
 * processed in schema order. This is what you generally want for
 * rendering new data structure to a string. The wo pointers are not used. */

/* Called by: */
char* zx_ENC_SO_ac_AsymmetricDecryption(struct zx_ctx* c, struct zx_ac_AsymmetricDecryption_s* x, char* p )
{
  struct zx_elem_s* se MAYBE_UNUSED;
  ENC_LEN_DEBUG_BASE;
#if 1 /* NORMALMODE */
  struct zx_ns_s* pop_seen = 0;
  /* *** in simple_elem case should output ns prefix from ns node. */
  ZX_OUT_TAG(p, "<ac:AsymmetricDecryption");
  if (c->inc_ns)
    p = zx_enc_inc_ns(c, p, &pop_seen);
  p = zx_enc_xmlns_if_not_seen(c, p, zx_ns_tab+zx_xmlns_ix_ac, &pop_seen);


  p = zx_enc_unknown_attrs(p, x->gg.any_attr);
#else
  /* root node has no begin tag */
#endif
  
  {
      struct zx_ac_Extension_s* e;
      for (e = x->Extension; e; e = (struct zx_ac_Extension_s*)e->gg.g.n)
	  p = zx_ENC_SO_ac_Extension(c, e, p);
  }

  p = zx_enc_so_unknown_elems_and_content(c, p, &x->gg);
  
#if 1 /* NORMALMODE */
  ZX_OUT_CLOSE_TAG(p, "</ac:AsymmetricDecryption>");
  zx_pop_seen(pop_seen);
#else
  /* root node has no end tag either */
#endif
  ENC_LEN_DEBUG(x, "ac:AsymmetricDecryption", p-enc_base);
  return p;
}

/* FUNC(zx_ENC_WO_ac_AsymmetricDecryption) */

/* Render element into string. The XML attributes and elements are
 * processed in wire order by chasing wo pointers. This is what you want for
 * validating signatures on other people's XML documents. */

/* Called by: */
char* zx_ENC_WO_ac_AsymmetricDecryption(struct zx_ctx* c, struct zx_ac_AsymmetricDecryption_s* x, char* p )
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
  ZX_OUT_MEM(p, "AsymmetricDecryption", sizeof("AsymmetricDecryption")-1);
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
  ENC_LEN_DEBUG(x, "ac:AsymmetricDecryption", p-enc_base);
  return p;
}

/* FUNC(zx_EASY_ENC_SO_ac_AsymmetricDecryption) */

/* Called by: */
struct zx_str* zx_EASY_ENC_SO_ac_AsymmetricDecryption(struct zx_ctx* c, struct zx_ac_AsymmetricDecryption_s* x )
{
  int len;
  char* buf;
  c->ns_tab = ZX_ALLOC(c, sizeof(zx_ns_tab));
  memcpy(c->ns_tab, zx_ns_tab, sizeof(zx_ns_tab));
  len = zx_LEN_SO_ac_AsymmetricDecryption(c, x );
  buf = ZX_ALLOC(c, len+1);
  return zx_easy_enc_common(c, zx_ENC_SO_ac_AsymmetricDecryption(c, x, buf ), buf, len);
}

/* FUNC(zx_EASY_ENC_WO_ac_AsymmetricDecryption) */

/* Called by: */
struct zx_str* zx_EASY_ENC_WO_ac_AsymmetricDecryption(struct zx_ctx* c, struct zx_ac_AsymmetricDecryption_s* x )
{
  int len;
  char* buf;
  c->ns_tab = ZX_ALLOC(c, sizeof(zx_ns_tab));
  memcpy(c->ns_tab, zx_ns_tab, sizeof(zx_ns_tab));
  len = zx_LEN_WO_ac_AsymmetricDecryption(c, x );
  buf = ZX_ALLOC(c, len+1);
  return zx_easy_enc_common(c, zx_ENC_WO_ac_AsymmetricDecryption(c, x, buf ), buf, len);
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

#define EL_NAME   ac_AsymmetricKeyAgreement
#define EL_STRUCT zx_ac_AsymmetricKeyAgreement_s
#define EL_NS     ac
#define EL_TAG    AsymmetricKeyAgreement

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

/* FUNC(zx_LEN_SO_ac_AsymmetricKeyAgreement) */

/* Compute length of an element (and its subelements). The XML attributes
 * and elements are processed in schema order. */

/* Called by: */
int zx_LEN_SO_ac_AsymmetricKeyAgreement(struct zx_ctx* c, struct zx_ac_AsymmetricKeyAgreement_s* x )
{
  struct zx_ns_s* pop_seen = 0;
  struct zx_elem_s* se MAYBE_UNUSED;
#if 1 /* NORMALMODE */
  /* *** in simple_elem case should output ns prefix from ns node. */
  int len = sizeof("<ac:AsymmetricKeyAgreement")-1 + 1 + sizeof("</ac:AsymmetricKeyAgreement>")-1;
  if (c->inc_ns_len)
    len += zx_len_inc_ns(c, &pop_seen);
  len += zx_len_xmlns_if_not_seen(c, zx_ns_tab+zx_xmlns_ix_ac, &pop_seen);


#else
  /* root node has no begin tag */
  int len = 0;
#endif
  
  {
      struct zx_ac_Extension_s* e;
      for (e = x->Extension; e; e = (struct zx_ac_Extension_s*)e->gg.g.n)
	  len += zx_LEN_SO_ac_Extension(c, e);
  }


  len += zx_len_so_common(c, &x->gg);
  zx_pop_seen(pop_seen);
  ENC_LEN_DEBUG(x, "ac:AsymmetricKeyAgreement", len);
  return len;
}

/* FUNC(zx_LEN_WO_ac_AsymmetricKeyAgreement) */

/* Compute length of an element (and its subelements). The XML attributes
 * and elements are processed in wire order and no assumptions
 * are made about namespace prefixes. */

/* Called by: */
int zx_LEN_WO_ac_AsymmetricKeyAgreement(struct zx_ctx* c, struct zx_ac_AsymmetricKeyAgreement_s* x )
{
  struct zx_ns_s* pop_seen = 0;
  struct zx_elem_s* se MAYBE_UNUSED;
#if 1 /* NORMALMODE */
  int len = 1 + sizeof("AsymmetricKeyAgreement")-1 + 1 + 2 + sizeof("AsymmetricKeyAgreement")-1 + 1;
  
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
      struct zx_ac_Extension_s* e;
      for (e = x->Extension; e; e = (struct zx_ac_Extension_s*)e->gg.g.n)
	  len += zx_LEN_WO_ac_Extension(c, e);
  }


  len += zx_len_wo_common(c, &x->gg); 
  zx_pop_seen(pop_seen);
  ENC_LEN_DEBUG(x, "ac:AsymmetricKeyAgreement", len);
  return len;
}

/* FUNC(zx_ENC_SO_ac_AsymmetricKeyAgreement) */

/* Render element into string. The XML attributes and elements are
 * processed in schema order. This is what you generally want for
 * rendering new data structure to a string. The wo pointers are not used. */

/* Called by: */
char* zx_ENC_SO_ac_AsymmetricKeyAgreement(struct zx_ctx* c, struct zx_ac_AsymmetricKeyAgreement_s* x, char* p )
{
  struct zx_elem_s* se MAYBE_UNUSED;
  ENC_LEN_DEBUG_BASE;
#if 1 /* NORMALMODE */
  struct zx_ns_s* pop_seen = 0;
  /* *** in simple_elem case should output ns prefix from ns node. */
  ZX_OUT_TAG(p, "<ac:AsymmetricKeyAgreement");
  if (c->inc_ns)
    p = zx_enc_inc_ns(c, p, &pop_seen);
  p = zx_enc_xmlns_if_not_seen(c, p, zx_ns_tab+zx_xmlns_ix_ac, &pop_seen);


  p = zx_enc_unknown_attrs(p, x->gg.any_attr);
#else
  /* root node has no begin tag */
#endif
  
  {
      struct zx_ac_Extension_s* e;
      for (e = x->Extension; e; e = (struct zx_ac_Extension_s*)e->gg.g.n)
	  p = zx_ENC_SO_ac_Extension(c, e, p);
  }

  p = zx_enc_so_unknown_elems_and_content(c, p, &x->gg);
  
#if 1 /* NORMALMODE */
  ZX_OUT_CLOSE_TAG(p, "</ac:AsymmetricKeyAgreement>");
  zx_pop_seen(pop_seen);
#else
  /* root node has no end tag either */
#endif
  ENC_LEN_DEBUG(x, "ac:AsymmetricKeyAgreement", p-enc_base);
  return p;
}

/* FUNC(zx_ENC_WO_ac_AsymmetricKeyAgreement) */

/* Render element into string. The XML attributes and elements are
 * processed in wire order by chasing wo pointers. This is what you want for
 * validating signatures on other people's XML documents. */

/* Called by: */
char* zx_ENC_WO_ac_AsymmetricKeyAgreement(struct zx_ctx* c, struct zx_ac_AsymmetricKeyAgreement_s* x, char* p )
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
  ZX_OUT_MEM(p, "AsymmetricKeyAgreement", sizeof("AsymmetricKeyAgreement")-1);
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
  ENC_LEN_DEBUG(x, "ac:AsymmetricKeyAgreement", p-enc_base);
  return p;
}

/* FUNC(zx_EASY_ENC_SO_ac_AsymmetricKeyAgreement) */

/* Called by: */
struct zx_str* zx_EASY_ENC_SO_ac_AsymmetricKeyAgreement(struct zx_ctx* c, struct zx_ac_AsymmetricKeyAgreement_s* x )
{
  int len;
  char* buf;
  c->ns_tab = ZX_ALLOC(c, sizeof(zx_ns_tab));
  memcpy(c->ns_tab, zx_ns_tab, sizeof(zx_ns_tab));
  len = zx_LEN_SO_ac_AsymmetricKeyAgreement(c, x );
  buf = ZX_ALLOC(c, len+1);
  return zx_easy_enc_common(c, zx_ENC_SO_ac_AsymmetricKeyAgreement(c, x, buf ), buf, len);
}

/* FUNC(zx_EASY_ENC_WO_ac_AsymmetricKeyAgreement) */

/* Called by: */
struct zx_str* zx_EASY_ENC_WO_ac_AsymmetricKeyAgreement(struct zx_ctx* c, struct zx_ac_AsymmetricKeyAgreement_s* x )
{
  int len;
  char* buf;
  c->ns_tab = ZX_ALLOC(c, sizeof(zx_ns_tab));
  memcpy(c->ns_tab, zx_ns_tab, sizeof(zx_ns_tab));
  len = zx_LEN_WO_ac_AsymmetricKeyAgreement(c, x );
  buf = ZX_ALLOC(c, len+1);
  return zx_easy_enc_common(c, zx_ENC_WO_ac_AsymmetricKeyAgreement(c, x, buf ), buf, len);
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

#define EL_NAME   ac_AuthenticatingAuthority
#define EL_STRUCT zx_ac_AuthenticatingAuthority_s
#define EL_NS     ac
#define EL_TAG    AuthenticatingAuthority

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

/* FUNC(zx_LEN_SO_ac_AuthenticatingAuthority) */

/* Compute length of an element (and its subelements). The XML attributes
 * and elements are processed in schema order. */

/* Called by: */
int zx_LEN_SO_ac_AuthenticatingAuthority(struct zx_ctx* c, struct zx_ac_AuthenticatingAuthority_s* x )
{
  struct zx_ns_s* pop_seen = 0;
  struct zx_elem_s* se MAYBE_UNUSED;
#if 1 /* NORMALMODE */
  /* *** in simple_elem case should output ns prefix from ns node. */
  int len = sizeof("<ac:AuthenticatingAuthority")-1 + 1 + sizeof("</ac:AuthenticatingAuthority>")-1;
  if (c->inc_ns_len)
    len += zx_len_inc_ns(c, &pop_seen);
  len += zx_len_xmlns_if_not_seen(c, zx_ns_tab+zx_xmlns_ix_ac, &pop_seen);

  len += zx_attr_so_len(x->ID, sizeof("ID")-1);

#else
  /* root node has no begin tag */
  int len = 0;
#endif
  
  {
      struct zx_ac_GoverningAgreements_s* e;
      for (e = x->GoverningAgreements; e; e = (struct zx_ac_GoverningAgreements_s*)e->gg.g.n)
	  len += zx_LEN_SO_ac_GoverningAgreements(c, e);
  }


  len += zx_len_so_common(c, &x->gg);
  zx_pop_seen(pop_seen);
  ENC_LEN_DEBUG(x, "ac:AuthenticatingAuthority", len);
  return len;
}

/* FUNC(zx_LEN_WO_ac_AuthenticatingAuthority) */

/* Compute length of an element (and its subelements). The XML attributes
 * and elements are processed in wire order and no assumptions
 * are made about namespace prefixes. */

/* Called by: */
int zx_LEN_WO_ac_AuthenticatingAuthority(struct zx_ctx* c, struct zx_ac_AuthenticatingAuthority_s* x )
{
  struct zx_ns_s* pop_seen = 0;
  struct zx_elem_s* se MAYBE_UNUSED;
#if 1 /* NORMALMODE */
  int len = 1 + sizeof("AuthenticatingAuthority")-1 + 1 + 2 + sizeof("AuthenticatingAuthority")-1 + 1;
  
  if (x->gg.g.ns && x->gg.g.ns->prefix_len)
    len += (x->gg.g.ns->prefix_len + 1) * 2;
  if (c->inc_ns_len)
    len += zx_len_inc_ns(c, &pop_seen);
  len += zx_len_xmlns_if_not_seen(c, x->gg.g.ns, &pop_seen);

  len += zx_attr_wo_len(x->ID, sizeof("ID")-1);

#else
  /* root node has no begin tag */
  int len = 0;
#endif
  
  {
      struct zx_ac_GoverningAgreements_s* e;
      for (e = x->GoverningAgreements; e; e = (struct zx_ac_GoverningAgreements_s*)e->gg.g.n)
	  len += zx_LEN_WO_ac_GoverningAgreements(c, e);
  }


  len += zx_len_wo_common(c, &x->gg); 
  zx_pop_seen(pop_seen);
  ENC_LEN_DEBUG(x, "ac:AuthenticatingAuthority", len);
  return len;
}

/* FUNC(zx_ENC_SO_ac_AuthenticatingAuthority) */

/* Render element into string. The XML attributes and elements are
 * processed in schema order. This is what you generally want for
 * rendering new data structure to a string. The wo pointers are not used. */

/* Called by: */
char* zx_ENC_SO_ac_AuthenticatingAuthority(struct zx_ctx* c, struct zx_ac_AuthenticatingAuthority_s* x, char* p )
{
  struct zx_elem_s* se MAYBE_UNUSED;
  ENC_LEN_DEBUG_BASE;
#if 1 /* NORMALMODE */
  struct zx_ns_s* pop_seen = 0;
  /* *** in simple_elem case should output ns prefix from ns node. */
  ZX_OUT_TAG(p, "<ac:AuthenticatingAuthority");
  if (c->inc_ns)
    p = zx_enc_inc_ns(c, p, &pop_seen);
  p = zx_enc_xmlns_if_not_seen(c, p, zx_ns_tab+zx_xmlns_ix_ac, &pop_seen);

  p = zx_attr_so_enc(p, x->ID, " ID=\"", sizeof(" ID=\"")-1);

  p = zx_enc_unknown_attrs(p, x->gg.any_attr);
#else
  /* root node has no begin tag */
#endif
  
  {
      struct zx_ac_GoverningAgreements_s* e;
      for (e = x->GoverningAgreements; e; e = (struct zx_ac_GoverningAgreements_s*)e->gg.g.n)
	  p = zx_ENC_SO_ac_GoverningAgreements(c, e, p);
  }

  p = zx_enc_so_unknown_elems_and_content(c, p, &x->gg);
  
#if 1 /* NORMALMODE */
  ZX_OUT_CLOSE_TAG(p, "</ac:AuthenticatingAuthority>");
  zx_pop_seen(pop_seen);
#else
  /* root node has no end tag either */
#endif
  ENC_LEN_DEBUG(x, "ac:AuthenticatingAuthority", p-enc_base);
  return p;
}

/* FUNC(zx_ENC_WO_ac_AuthenticatingAuthority) */

/* Render element into string. The XML attributes and elements are
 * processed in wire order by chasing wo pointers. This is what you want for
 * validating signatures on other people's XML documents. */

/* Called by: */
char* zx_ENC_WO_ac_AuthenticatingAuthority(struct zx_ctx* c, struct zx_ac_AuthenticatingAuthority_s* x, char* p )
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
  ZX_OUT_MEM(p, "AuthenticatingAuthority", sizeof("AuthenticatingAuthority")-1);
  qq = p;

  /* *** sort the namespaces */
  if (c->inc_ns)
    zx_add_inc_ns(c, &pop_seen);
  zx_add_xmlns_if_not_seen(c, x->gg.g.ns, &pop_seen);

  p = zx_enc_seen(p, pop_seen); 
  p = zx_attr_wo_enc(p, x->ID, "ID=\"", sizeof("ID=\"")-1);

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
  ENC_LEN_DEBUG(x, "ac:AuthenticatingAuthority", p-enc_base);
  return p;
}

/* FUNC(zx_EASY_ENC_SO_ac_AuthenticatingAuthority) */

/* Called by: */
struct zx_str* zx_EASY_ENC_SO_ac_AuthenticatingAuthority(struct zx_ctx* c, struct zx_ac_AuthenticatingAuthority_s* x )
{
  int len;
  char* buf;
  c->ns_tab = ZX_ALLOC(c, sizeof(zx_ns_tab));
  memcpy(c->ns_tab, zx_ns_tab, sizeof(zx_ns_tab));
  len = zx_LEN_SO_ac_AuthenticatingAuthority(c, x );
  buf = ZX_ALLOC(c, len+1);
  return zx_easy_enc_common(c, zx_ENC_SO_ac_AuthenticatingAuthority(c, x, buf ), buf, len);
}

/* FUNC(zx_EASY_ENC_WO_ac_AuthenticatingAuthority) */

/* Called by: */
struct zx_str* zx_EASY_ENC_WO_ac_AuthenticatingAuthority(struct zx_ctx* c, struct zx_ac_AuthenticatingAuthority_s* x )
{
  int len;
  char* buf;
  c->ns_tab = ZX_ALLOC(c, sizeof(zx_ns_tab));
  memcpy(c->ns_tab, zx_ns_tab, sizeof(zx_ns_tab));
  len = zx_LEN_WO_ac_AuthenticatingAuthority(c, x );
  buf = ZX_ALLOC(c, len+1);
  return zx_easy_enc_common(c, zx_ENC_WO_ac_AuthenticatingAuthority(c, x, buf ), buf, len);
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

#define EL_NAME   ac_AuthenticationContextStatement
#define EL_STRUCT zx_ac_AuthenticationContextStatement_s
#define EL_NS     ac
#define EL_TAG    AuthenticationContextStatement

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

/* FUNC(zx_LEN_SO_ac_AuthenticationContextStatement) */

/* Compute length of an element (and its subelements). The XML attributes
 * and elements are processed in schema order. */

/* Called by: */
int zx_LEN_SO_ac_AuthenticationContextStatement(struct zx_ctx* c, struct zx_ac_AuthenticationContextStatement_s* x )
{
  struct zx_ns_s* pop_seen = 0;
  struct zx_elem_s* se MAYBE_UNUSED;
#if 1 /* NORMALMODE */
  /* *** in simple_elem case should output ns prefix from ns node. */
  int len = sizeof("<ac:AuthenticationContextStatement")-1 + 1 + sizeof("</ac:AuthenticationContextStatement>")-1;
  if (c->inc_ns_len)
    len += zx_len_inc_ns(c, &pop_seen);
  len += zx_len_xmlns_if_not_seen(c, zx_ns_tab+zx_xmlns_ix_ac, &pop_seen);

  len += zx_attr_so_len(x->ID, sizeof("ID")-1);

#else
  /* root node has no begin tag */
  int len = 0;
#endif
  
  {
      struct zx_ac_Identification_s* e;
      for (e = x->Identification; e; e = (struct zx_ac_Identification_s*)e->gg.g.n)
	  len += zx_LEN_SO_ac_Identification(c, e);
  }
  {
      struct zx_ac_TechnicalProtection_s* e;
      for (e = x->TechnicalProtection; e; e = (struct zx_ac_TechnicalProtection_s*)e->gg.g.n)
	  len += zx_LEN_SO_ac_TechnicalProtection(c, e);
  }
  {
      struct zx_ac_OperationalProtection_s* e;
      for (e = x->OperationalProtection; e; e = (struct zx_ac_OperationalProtection_s*)e->gg.g.n)
	  len += zx_LEN_SO_ac_OperationalProtection(c, e);
  }
  {
      struct zx_ac_AuthenticationMethod_s* e;
      for (e = x->AuthenticationMethod; e; e = (struct zx_ac_AuthenticationMethod_s*)e->gg.g.n)
	  len += zx_LEN_SO_ac_AuthenticationMethod(c, e);
  }
  {
      struct zx_ac_GoverningAgreements_s* e;
      for (e = x->GoverningAgreements; e; e = (struct zx_ac_GoverningAgreements_s*)e->gg.g.n)
	  len += zx_LEN_SO_ac_GoverningAgreements(c, e);
  }
  {
      struct zx_ac_AuthenticatingAuthority_s* e;
      for (e = x->AuthenticatingAuthority; e; e = (struct zx_ac_AuthenticatingAuthority_s*)e->gg.g.n)
	  len += zx_LEN_SO_ac_AuthenticatingAuthority(c, e);
  }
  {
      struct zx_ac_Extension_s* e;
      for (e = x->Extension; e; e = (struct zx_ac_Extension_s*)e->gg.g.n)
	  len += zx_LEN_SO_ac_Extension(c, e);
  }


  len += zx_len_so_common(c, &x->gg);
  zx_pop_seen(pop_seen);
  ENC_LEN_DEBUG(x, "ac:AuthenticationContextStatement", len);
  return len;
}

/* FUNC(zx_LEN_WO_ac_AuthenticationContextStatement) */

/* Compute length of an element (and its subelements). The XML attributes
 * and elements are processed in wire order and no assumptions
 * are made about namespace prefixes. */

/* Called by: */
int zx_LEN_WO_ac_AuthenticationContextStatement(struct zx_ctx* c, struct zx_ac_AuthenticationContextStatement_s* x )
{
  struct zx_ns_s* pop_seen = 0;
  struct zx_elem_s* se MAYBE_UNUSED;
#if 1 /* NORMALMODE */
  int len = 1 + sizeof("AuthenticationContextStatement")-1 + 1 + 2 + sizeof("AuthenticationContextStatement")-1 + 1;
  
  if (x->gg.g.ns && x->gg.g.ns->prefix_len)
    len += (x->gg.g.ns->prefix_len + 1) * 2;
  if (c->inc_ns_len)
    len += zx_len_inc_ns(c, &pop_seen);
  len += zx_len_xmlns_if_not_seen(c, x->gg.g.ns, &pop_seen);

  len += zx_attr_wo_len(x->ID, sizeof("ID")-1);

#else
  /* root node has no begin tag */
  int len = 0;
#endif
  
  {
      struct zx_ac_Identification_s* e;
      for (e = x->Identification; e; e = (struct zx_ac_Identification_s*)e->gg.g.n)
	  len += zx_LEN_WO_ac_Identification(c, e);
  }
  {
      struct zx_ac_TechnicalProtection_s* e;
      for (e = x->TechnicalProtection; e; e = (struct zx_ac_TechnicalProtection_s*)e->gg.g.n)
	  len += zx_LEN_WO_ac_TechnicalProtection(c, e);
  }
  {
      struct zx_ac_OperationalProtection_s* e;
      for (e = x->OperationalProtection; e; e = (struct zx_ac_OperationalProtection_s*)e->gg.g.n)
	  len += zx_LEN_WO_ac_OperationalProtection(c, e);
  }
  {
      struct zx_ac_AuthenticationMethod_s* e;
      for (e = x->AuthenticationMethod; e; e = (struct zx_ac_AuthenticationMethod_s*)e->gg.g.n)
	  len += zx_LEN_WO_ac_AuthenticationMethod(c, e);
  }
  {
      struct zx_ac_GoverningAgreements_s* e;
      for (e = x->GoverningAgreements; e; e = (struct zx_ac_GoverningAgreements_s*)e->gg.g.n)
	  len += zx_LEN_WO_ac_GoverningAgreements(c, e);
  }
  {
      struct zx_ac_AuthenticatingAuthority_s* e;
      for (e = x->AuthenticatingAuthority; e; e = (struct zx_ac_AuthenticatingAuthority_s*)e->gg.g.n)
	  len += zx_LEN_WO_ac_AuthenticatingAuthority(c, e);
  }
  {
      struct zx_ac_Extension_s* e;
      for (e = x->Extension; e; e = (struct zx_ac_Extension_s*)e->gg.g.n)
	  len += zx_LEN_WO_ac_Extension(c, e);
  }


  len += zx_len_wo_common(c, &x->gg); 
  zx_pop_seen(pop_seen);
  ENC_LEN_DEBUG(x, "ac:AuthenticationContextStatement", len);
  return len;
}

/* FUNC(zx_ENC_SO_ac_AuthenticationContextStatement) */

/* Render element into string. The XML attributes and elements are
 * processed in schema order. This is what you generally want for
 * rendering new data structure to a string. The wo pointers are not used. */

/* Called by: */
char* zx_ENC_SO_ac_AuthenticationContextStatement(struct zx_ctx* c, struct zx_ac_AuthenticationContextStatement_s* x, char* p )
{
  struct zx_elem_s* se MAYBE_UNUSED;
  ENC_LEN_DEBUG_BASE;
#if 1 /* NORMALMODE */
  struct zx_ns_s* pop_seen = 0;
  /* *** in simple_elem case should output ns prefix from ns node. */
  ZX_OUT_TAG(p, "<ac:AuthenticationContextStatement");
  if (c->inc_ns)
    p = zx_enc_inc_ns(c, p, &pop_seen);
  p = zx_enc_xmlns_if_not_seen(c, p, zx_ns_tab+zx_xmlns_ix_ac, &pop_seen);

  p = zx_attr_so_enc(p, x->ID, " ID=\"", sizeof(" ID=\"")-1);

  p = zx_enc_unknown_attrs(p, x->gg.any_attr);
#else
  /* root node has no begin tag */
#endif
  
  {
      struct zx_ac_Identification_s* e;
      for (e = x->Identification; e; e = (struct zx_ac_Identification_s*)e->gg.g.n)
	  p = zx_ENC_SO_ac_Identification(c, e, p);
  }
  {
      struct zx_ac_TechnicalProtection_s* e;
      for (e = x->TechnicalProtection; e; e = (struct zx_ac_TechnicalProtection_s*)e->gg.g.n)
	  p = zx_ENC_SO_ac_TechnicalProtection(c, e, p);
  }
  {
      struct zx_ac_OperationalProtection_s* e;
      for (e = x->OperationalProtection; e; e = (struct zx_ac_OperationalProtection_s*)e->gg.g.n)
	  p = zx_ENC_SO_ac_OperationalProtection(c, e, p);
  }
  {
      struct zx_ac_AuthenticationMethod_s* e;
      for (e = x->AuthenticationMethod; e; e = (struct zx_ac_AuthenticationMethod_s*)e->gg.g.n)
	  p = zx_ENC_SO_ac_AuthenticationMethod(c, e, p);
  }
  {
      struct zx_ac_GoverningAgreements_s* e;
      for (e = x->GoverningAgreements; e; e = (struct zx_ac_GoverningAgreements_s*)e->gg.g.n)
	  p = zx_ENC_SO_ac_GoverningAgreements(c, e, p);
  }
  {
      struct zx_ac_AuthenticatingAuthority_s* e;
      for (e = x->AuthenticatingAuthority; e; e = (struct zx_ac_AuthenticatingAuthority_s*)e->gg.g.n)
	  p = zx_ENC_SO_ac_AuthenticatingAuthority(c, e, p);
  }
  {
      struct zx_ac_Extension_s* e;
      for (e = x->Extension; e; e = (struct zx_ac_Extension_s*)e->gg.g.n)
	  p = zx_ENC_SO_ac_Extension(c, e, p);
  }

  p = zx_enc_so_unknown_elems_and_content(c, p, &x->gg);
  
#if 1 /* NORMALMODE */
  ZX_OUT_CLOSE_TAG(p, "</ac:AuthenticationContextStatement>");
  zx_pop_seen(pop_seen);
#else
  /* root node has no end tag either */
#endif
  ENC_LEN_DEBUG(x, "ac:AuthenticationContextStatement", p-enc_base);
  return p;
}

/* FUNC(zx_ENC_WO_ac_AuthenticationContextStatement) */

/* Render element into string. The XML attributes and elements are
 * processed in wire order by chasing wo pointers. This is what you want for
 * validating signatures on other people's XML documents. */

/* Called by: */
char* zx_ENC_WO_ac_AuthenticationContextStatement(struct zx_ctx* c, struct zx_ac_AuthenticationContextStatement_s* x, char* p )
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
  ZX_OUT_MEM(p, "AuthenticationContextStatement", sizeof("AuthenticationContextStatement")-1);
  qq = p;

  /* *** sort the namespaces */
  if (c->inc_ns)
    zx_add_inc_ns(c, &pop_seen);
  zx_add_xmlns_if_not_seen(c, x->gg.g.ns, &pop_seen);

  p = zx_enc_seen(p, pop_seen); 
  p = zx_attr_wo_enc(p, x->ID, "ID=\"", sizeof("ID=\"")-1);

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
  ENC_LEN_DEBUG(x, "ac:AuthenticationContextStatement", p-enc_base);
  return p;
}

/* FUNC(zx_EASY_ENC_SO_ac_AuthenticationContextStatement) */

/* Called by: */
struct zx_str* zx_EASY_ENC_SO_ac_AuthenticationContextStatement(struct zx_ctx* c, struct zx_ac_AuthenticationContextStatement_s* x )
{
  int len;
  char* buf;
  c->ns_tab = ZX_ALLOC(c, sizeof(zx_ns_tab));
  memcpy(c->ns_tab, zx_ns_tab, sizeof(zx_ns_tab));
  len = zx_LEN_SO_ac_AuthenticationContextStatement(c, x );
  buf = ZX_ALLOC(c, len+1);
  return zx_easy_enc_common(c, zx_ENC_SO_ac_AuthenticationContextStatement(c, x, buf ), buf, len);
}

/* FUNC(zx_EASY_ENC_WO_ac_AuthenticationContextStatement) */

/* Called by: */
struct zx_str* zx_EASY_ENC_WO_ac_AuthenticationContextStatement(struct zx_ctx* c, struct zx_ac_AuthenticationContextStatement_s* x )
{
  int len;
  char* buf;
  c->ns_tab = ZX_ALLOC(c, sizeof(zx_ns_tab));
  memcpy(c->ns_tab, zx_ns_tab, sizeof(zx_ns_tab));
  len = zx_LEN_WO_ac_AuthenticationContextStatement(c, x );
  buf = ZX_ALLOC(c, len+1);
  return zx_easy_enc_common(c, zx_ENC_WO_ac_AuthenticationContextStatement(c, x, buf ), buf, len);
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

#define EL_NAME   ac_AuthenticationMethod
#define EL_STRUCT zx_ac_AuthenticationMethod_s
#define EL_NS     ac
#define EL_TAG    AuthenticationMethod

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

/* FUNC(zx_LEN_SO_ac_AuthenticationMethod) */

/* Compute length of an element (and its subelements). The XML attributes
 * and elements are processed in schema order. */

/* Called by: */
int zx_LEN_SO_ac_AuthenticationMethod(struct zx_ctx* c, struct zx_ac_AuthenticationMethod_s* x )
{
  struct zx_ns_s* pop_seen = 0;
  struct zx_elem_s* se MAYBE_UNUSED;
#if 1 /* NORMALMODE */
  /* *** in simple_elem case should output ns prefix from ns node. */
  int len = sizeof("<ac:AuthenticationMethod")-1 + 1 + sizeof("</ac:AuthenticationMethod>")-1;
  if (c->inc_ns_len)
    len += zx_len_inc_ns(c, &pop_seen);
  len += zx_len_xmlns_if_not_seen(c, zx_ns_tab+zx_xmlns_ix_ac, &pop_seen);


#else
  /* root node has no begin tag */
  int len = 0;
#endif
  
  {
      struct zx_ac_PrincipalAuthenticationMechanism_s* e;
      for (e = x->PrincipalAuthenticationMechanism; e; e = (struct zx_ac_PrincipalAuthenticationMechanism_s*)e->gg.g.n)
	  len += zx_LEN_SO_ac_PrincipalAuthenticationMechanism(c, e);
  }
  {
      struct zx_ac_Authenticator_s* e;
      for (e = x->Authenticator; e; e = (struct zx_ac_Authenticator_s*)e->gg.g.n)
	  len += zx_LEN_SO_ac_Authenticator(c, e);
  }
  {
      struct zx_ac_AuthenticatorTransportProtocol_s* e;
      for (e = x->AuthenticatorTransportProtocol; e; e = (struct zx_ac_AuthenticatorTransportProtocol_s*)e->gg.g.n)
	  len += zx_LEN_SO_ac_AuthenticatorTransportProtocol(c, e);
  }
  {
      struct zx_ac_Extension_s* e;
      for (e = x->Extension; e; e = (struct zx_ac_Extension_s*)e->gg.g.n)
	  len += zx_LEN_SO_ac_Extension(c, e);
  }


  len += zx_len_so_common(c, &x->gg);
  zx_pop_seen(pop_seen);
  ENC_LEN_DEBUG(x, "ac:AuthenticationMethod", len);
  return len;
}

/* FUNC(zx_LEN_WO_ac_AuthenticationMethod) */

/* Compute length of an element (and its subelements). The XML attributes
 * and elements are processed in wire order and no assumptions
 * are made about namespace prefixes. */

/* Called by: */
int zx_LEN_WO_ac_AuthenticationMethod(struct zx_ctx* c, struct zx_ac_AuthenticationMethod_s* x )
{
  struct zx_ns_s* pop_seen = 0;
  struct zx_elem_s* se MAYBE_UNUSED;
#if 1 /* NORMALMODE */
  int len = 1 + sizeof("AuthenticationMethod")-1 + 1 + 2 + sizeof("AuthenticationMethod")-1 + 1;
  
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
      struct zx_ac_PrincipalAuthenticationMechanism_s* e;
      for (e = x->PrincipalAuthenticationMechanism; e; e = (struct zx_ac_PrincipalAuthenticationMechanism_s*)e->gg.g.n)
	  len += zx_LEN_WO_ac_PrincipalAuthenticationMechanism(c, e);
  }
  {
      struct zx_ac_Authenticator_s* e;
      for (e = x->Authenticator; e; e = (struct zx_ac_Authenticator_s*)e->gg.g.n)
	  len += zx_LEN_WO_ac_Authenticator(c, e);
  }
  {
      struct zx_ac_AuthenticatorTransportProtocol_s* e;
      for (e = x->AuthenticatorTransportProtocol; e; e = (struct zx_ac_AuthenticatorTransportProtocol_s*)e->gg.g.n)
	  len += zx_LEN_WO_ac_AuthenticatorTransportProtocol(c, e);
  }
  {
      struct zx_ac_Extension_s* e;
      for (e = x->Extension; e; e = (struct zx_ac_Extension_s*)e->gg.g.n)
	  len += zx_LEN_WO_ac_Extension(c, e);
  }


  len += zx_len_wo_common(c, &x->gg); 
  zx_pop_seen(pop_seen);
  ENC_LEN_DEBUG(x, "ac:AuthenticationMethod", len);
  return len;
}

/* FUNC(zx_ENC_SO_ac_AuthenticationMethod) */

/* Render element into string. The XML attributes and elements are
 * processed in schema order. This is what you generally want for
 * rendering new data structure to a string. The wo pointers are not used. */

/* Called by: */
char* zx_ENC_SO_ac_AuthenticationMethod(struct zx_ctx* c, struct zx_ac_AuthenticationMethod_s* x, char* p )
{
  struct zx_elem_s* se MAYBE_UNUSED;
  ENC_LEN_DEBUG_BASE;
#if 1 /* NORMALMODE */
  struct zx_ns_s* pop_seen = 0;
  /* *** in simple_elem case should output ns prefix from ns node. */
  ZX_OUT_TAG(p, "<ac:AuthenticationMethod");
  if (c->inc_ns)
    p = zx_enc_inc_ns(c, p, &pop_seen);
  p = zx_enc_xmlns_if_not_seen(c, p, zx_ns_tab+zx_xmlns_ix_ac, &pop_seen);


  p = zx_enc_unknown_attrs(p, x->gg.any_attr);
#else
  /* root node has no begin tag */
#endif
  
  {
      struct zx_ac_PrincipalAuthenticationMechanism_s* e;
      for (e = x->PrincipalAuthenticationMechanism; e; e = (struct zx_ac_PrincipalAuthenticationMechanism_s*)e->gg.g.n)
	  p = zx_ENC_SO_ac_PrincipalAuthenticationMechanism(c, e, p);
  }
  {
      struct zx_ac_Authenticator_s* e;
      for (e = x->Authenticator; e; e = (struct zx_ac_Authenticator_s*)e->gg.g.n)
	  p = zx_ENC_SO_ac_Authenticator(c, e, p);
  }
  {
      struct zx_ac_AuthenticatorTransportProtocol_s* e;
      for (e = x->AuthenticatorTransportProtocol; e; e = (struct zx_ac_AuthenticatorTransportProtocol_s*)e->gg.g.n)
	  p = zx_ENC_SO_ac_AuthenticatorTransportProtocol(c, e, p);
  }
  {
      struct zx_ac_Extension_s* e;
      for (e = x->Extension; e; e = (struct zx_ac_Extension_s*)e->gg.g.n)
	  p = zx_ENC_SO_ac_Extension(c, e, p);
  }

  p = zx_enc_so_unknown_elems_and_content(c, p, &x->gg);
  
#if 1 /* NORMALMODE */
  ZX_OUT_CLOSE_TAG(p, "</ac:AuthenticationMethod>");
  zx_pop_seen(pop_seen);
#else
  /* root node has no end tag either */
#endif
  ENC_LEN_DEBUG(x, "ac:AuthenticationMethod", p-enc_base);
  return p;
}

/* FUNC(zx_ENC_WO_ac_AuthenticationMethod) */

/* Render element into string. The XML attributes and elements are
 * processed in wire order by chasing wo pointers. This is what you want for
 * validating signatures on other people's XML documents. */

/* Called by: */
char* zx_ENC_WO_ac_AuthenticationMethod(struct zx_ctx* c, struct zx_ac_AuthenticationMethod_s* x, char* p )
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
  ZX_OUT_MEM(p, "AuthenticationMethod", sizeof("AuthenticationMethod")-1);
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
  ENC_LEN_DEBUG(x, "ac:AuthenticationMethod", p-enc_base);
  return p;
}

/* FUNC(zx_EASY_ENC_SO_ac_AuthenticationMethod) */

/* Called by: */
struct zx_str* zx_EASY_ENC_SO_ac_AuthenticationMethod(struct zx_ctx* c, struct zx_ac_AuthenticationMethod_s* x )
{
  int len;
  char* buf;
  c->ns_tab = ZX_ALLOC(c, sizeof(zx_ns_tab));
  memcpy(c->ns_tab, zx_ns_tab, sizeof(zx_ns_tab));
  len = zx_LEN_SO_ac_AuthenticationMethod(c, x );
  buf = ZX_ALLOC(c, len+1);
  return zx_easy_enc_common(c, zx_ENC_SO_ac_AuthenticationMethod(c, x, buf ), buf, len);
}

/* FUNC(zx_EASY_ENC_WO_ac_AuthenticationMethod) */

/* Called by: */
struct zx_str* zx_EASY_ENC_WO_ac_AuthenticationMethod(struct zx_ctx* c, struct zx_ac_AuthenticationMethod_s* x )
{
  int len;
  char* buf;
  c->ns_tab = ZX_ALLOC(c, sizeof(zx_ns_tab));
  memcpy(c->ns_tab, zx_ns_tab, sizeof(zx_ns_tab));
  len = zx_LEN_WO_ac_AuthenticationMethod(c, x );
  buf = ZX_ALLOC(c, len+1);
  return zx_easy_enc_common(c, zx_ENC_WO_ac_AuthenticationMethod(c, x, buf ), buf, len);
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

#define EL_NAME   ac_Authenticator
#define EL_STRUCT zx_ac_Authenticator_s
#define EL_NS     ac
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

/* FUNC(zx_LEN_SO_ac_Authenticator) */

/* Compute length of an element (and its subelements). The XML attributes
 * and elements are processed in schema order. */

/* Called by: */
int zx_LEN_SO_ac_Authenticator(struct zx_ctx* c, struct zx_ac_Authenticator_s* x )
{
  struct zx_ns_s* pop_seen = 0;
  struct zx_elem_s* se MAYBE_UNUSED;
#if 1 /* NORMALMODE */
  /* *** in simple_elem case should output ns prefix from ns node. */
  int len = sizeof("<ac:Authenticator")-1 + 1 + sizeof("</ac:Authenticator>")-1;
  if (c->inc_ns_len)
    len += zx_len_inc_ns(c, &pop_seen);
  len += zx_len_xmlns_if_not_seen(c, zx_ns_tab+zx_xmlns_ix_ac, &pop_seen);


#else
  /* root node has no begin tag */
  int len = 0;
#endif
  
  {
      struct zx_ac_PreviousSession_s* e;
      for (e = x->PreviousSession; e; e = (struct zx_ac_PreviousSession_s*)e->gg.g.n)
	  len += zx_LEN_SO_ac_PreviousSession(c, e);
  }
  {
      struct zx_ac_ResumeSession_s* e;
      for (e = x->ResumeSession; e; e = (struct zx_ac_ResumeSession_s*)e->gg.g.n)
	  len += zx_LEN_SO_ac_ResumeSession(c, e);
  }
  {
      struct zx_ac_DigSig_s* e;
      for (e = x->DigSig; e; e = (struct zx_ac_DigSig_s*)e->gg.g.n)
	  len += zx_LEN_SO_ac_DigSig(c, e);
  }
  {
      struct zx_ac_Password_s* e;
      for (e = x->Password; e; e = (struct zx_ac_Password_s*)e->gg.g.n)
	  len += zx_LEN_SO_ac_Password(c, e);
  }
  {
      struct zx_ac_ZeroKnowledge_s* e;
      for (e = x->ZeroKnowledge; e; e = (struct zx_ac_ZeroKnowledge_s*)e->gg.g.n)
	  len += zx_LEN_SO_ac_ZeroKnowledge(c, e);
  }
  {
      struct zx_ac_SharedSecretChallengeResponse_s* e;
      for (e = x->SharedSecretChallengeResponse; e; e = (struct zx_ac_SharedSecretChallengeResponse_s*)e->gg.g.n)
	  len += zx_LEN_SO_ac_SharedSecretChallengeResponse(c, e);
  }
  {
      struct zx_ac_SharedSecretDynamicPlaintext_s* e;
      for (e = x->SharedSecretDynamicPlaintext; e; e = (struct zx_ac_SharedSecretDynamicPlaintext_s*)e->gg.g.n)
	  len += zx_LEN_SO_ac_SharedSecretDynamicPlaintext(c, e);
  }
  {
      struct zx_ac_IPAddress_s* e;
      for (e = x->IPAddress; e; e = (struct zx_ac_IPAddress_s*)e->gg.g.n)
	  len += zx_LEN_SO_ac_IPAddress(c, e);
  }
  {
      struct zx_ac_AsymmetricDecryption_s* e;
      for (e = x->AsymmetricDecryption; e; e = (struct zx_ac_AsymmetricDecryption_s*)e->gg.g.n)
	  len += zx_LEN_SO_ac_AsymmetricDecryption(c, e);
  }
  {
      struct zx_ac_AsymmetricKeyAgreement_s* e;
      for (e = x->AsymmetricKeyAgreement; e; e = (struct zx_ac_AsymmetricKeyAgreement_s*)e->gg.g.n)
	  len += zx_LEN_SO_ac_AsymmetricKeyAgreement(c, e);
  }
  {
      struct zx_ac_Extension_s* e;
      for (e = x->Extension; e; e = (struct zx_ac_Extension_s*)e->gg.g.n)
	  len += zx_LEN_SO_ac_Extension(c, e);
  }


  len += zx_len_so_common(c, &x->gg);
  zx_pop_seen(pop_seen);
  ENC_LEN_DEBUG(x, "ac:Authenticator", len);
  return len;
}

/* FUNC(zx_LEN_WO_ac_Authenticator) */

/* Compute length of an element (and its subelements). The XML attributes
 * and elements are processed in wire order and no assumptions
 * are made about namespace prefixes. */

/* Called by: */
int zx_LEN_WO_ac_Authenticator(struct zx_ctx* c, struct zx_ac_Authenticator_s* x )
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
  
  {
      struct zx_ac_PreviousSession_s* e;
      for (e = x->PreviousSession; e; e = (struct zx_ac_PreviousSession_s*)e->gg.g.n)
	  len += zx_LEN_WO_ac_PreviousSession(c, e);
  }
  {
      struct zx_ac_ResumeSession_s* e;
      for (e = x->ResumeSession; e; e = (struct zx_ac_ResumeSession_s*)e->gg.g.n)
	  len += zx_LEN_WO_ac_ResumeSession(c, e);
  }
  {
      struct zx_ac_DigSig_s* e;
      for (e = x->DigSig; e; e = (struct zx_ac_DigSig_s*)e->gg.g.n)
	  len += zx_LEN_WO_ac_DigSig(c, e);
  }
  {
      struct zx_ac_Password_s* e;
      for (e = x->Password; e; e = (struct zx_ac_Password_s*)e->gg.g.n)
	  len += zx_LEN_WO_ac_Password(c, e);
  }
  {
      struct zx_ac_ZeroKnowledge_s* e;
      for (e = x->ZeroKnowledge; e; e = (struct zx_ac_ZeroKnowledge_s*)e->gg.g.n)
	  len += zx_LEN_WO_ac_ZeroKnowledge(c, e);
  }
  {
      struct zx_ac_SharedSecretChallengeResponse_s* e;
      for (e = x->SharedSecretChallengeResponse; e; e = (struct zx_ac_SharedSecretChallengeResponse_s*)e->gg.g.n)
	  len += zx_LEN_WO_ac_SharedSecretChallengeResponse(c, e);
  }
  {
      struct zx_ac_SharedSecretDynamicPlaintext_s* e;
      for (e = x->SharedSecretDynamicPlaintext; e; e = (struct zx_ac_SharedSecretDynamicPlaintext_s*)e->gg.g.n)
	  len += zx_LEN_WO_ac_SharedSecretDynamicPlaintext(c, e);
  }
  {
      struct zx_ac_IPAddress_s* e;
      for (e = x->IPAddress; e; e = (struct zx_ac_IPAddress_s*)e->gg.g.n)
	  len += zx_LEN_WO_ac_IPAddress(c, e);
  }
  {
      struct zx_ac_AsymmetricDecryption_s* e;
      for (e = x->AsymmetricDecryption; e; e = (struct zx_ac_AsymmetricDecryption_s*)e->gg.g.n)
	  len += zx_LEN_WO_ac_AsymmetricDecryption(c, e);
  }
  {
      struct zx_ac_AsymmetricKeyAgreement_s* e;
      for (e = x->AsymmetricKeyAgreement; e; e = (struct zx_ac_AsymmetricKeyAgreement_s*)e->gg.g.n)
	  len += zx_LEN_WO_ac_AsymmetricKeyAgreement(c, e);
  }
  {
      struct zx_ac_Extension_s* e;
      for (e = x->Extension; e; e = (struct zx_ac_Extension_s*)e->gg.g.n)
	  len += zx_LEN_WO_ac_Extension(c, e);
  }


  len += zx_len_wo_common(c, &x->gg); 
  zx_pop_seen(pop_seen);
  ENC_LEN_DEBUG(x, "ac:Authenticator", len);
  return len;
}

/* FUNC(zx_ENC_SO_ac_Authenticator) */

/* Render element into string. The XML attributes and elements are
 * processed in schema order. This is what you generally want for
 * rendering new data structure to a string. The wo pointers are not used. */

/* Called by: */
char* zx_ENC_SO_ac_Authenticator(struct zx_ctx* c, struct zx_ac_Authenticator_s* x, char* p )
{
  struct zx_elem_s* se MAYBE_UNUSED;
  ENC_LEN_DEBUG_BASE;
#if 1 /* NORMALMODE */
  struct zx_ns_s* pop_seen = 0;
  /* *** in simple_elem case should output ns prefix from ns node. */
  ZX_OUT_TAG(p, "<ac:Authenticator");
  if (c->inc_ns)
    p = zx_enc_inc_ns(c, p, &pop_seen);
  p = zx_enc_xmlns_if_not_seen(c, p, zx_ns_tab+zx_xmlns_ix_ac, &pop_seen);


  p = zx_enc_unknown_attrs(p, x->gg.any_attr);
#else
  /* root node has no begin tag */
#endif
  
  {
      struct zx_ac_PreviousSession_s* e;
      for (e = x->PreviousSession; e; e = (struct zx_ac_PreviousSession_s*)e->gg.g.n)
	  p = zx_ENC_SO_ac_PreviousSession(c, e, p);
  }
  {
      struct zx_ac_ResumeSession_s* e;
      for (e = x->ResumeSession; e; e = (struct zx_ac_ResumeSession_s*)e->gg.g.n)
	  p = zx_ENC_SO_ac_ResumeSession(c, e, p);
  }
  {
      struct zx_ac_DigSig_s* e;
      for (e = x->DigSig; e; e = (struct zx_ac_DigSig_s*)e->gg.g.n)
	  p = zx_ENC_SO_ac_DigSig(c, e, p);
  }
  {
      struct zx_ac_Password_s* e;
      for (e = x->Password; e; e = (struct zx_ac_Password_s*)e->gg.g.n)
	  p = zx_ENC_SO_ac_Password(c, e, p);
  }
  {
      struct zx_ac_ZeroKnowledge_s* e;
      for (e = x->ZeroKnowledge; e; e = (struct zx_ac_ZeroKnowledge_s*)e->gg.g.n)
	  p = zx_ENC_SO_ac_ZeroKnowledge(c, e, p);
  }
  {
      struct zx_ac_SharedSecretChallengeResponse_s* e;
      for (e = x->SharedSecretChallengeResponse; e; e = (struct zx_ac_SharedSecretChallengeResponse_s*)e->gg.g.n)
	  p = zx_ENC_SO_ac_SharedSecretChallengeResponse(c, e, p);
  }
  {
      struct zx_ac_SharedSecretDynamicPlaintext_s* e;
      for (e = x->SharedSecretDynamicPlaintext; e; e = (struct zx_ac_SharedSecretDynamicPlaintext_s*)e->gg.g.n)
	  p = zx_ENC_SO_ac_SharedSecretDynamicPlaintext(c, e, p);
  }
  {
      struct zx_ac_IPAddress_s* e;
      for (e = x->IPAddress; e; e = (struct zx_ac_IPAddress_s*)e->gg.g.n)
	  p = zx_ENC_SO_ac_IPAddress(c, e, p);
  }
  {
      struct zx_ac_AsymmetricDecryption_s* e;
      for (e = x->AsymmetricDecryption; e; e = (struct zx_ac_AsymmetricDecryption_s*)e->gg.g.n)
	  p = zx_ENC_SO_ac_AsymmetricDecryption(c, e, p);
  }
  {
      struct zx_ac_AsymmetricKeyAgreement_s* e;
      for (e = x->AsymmetricKeyAgreement; e; e = (struct zx_ac_AsymmetricKeyAgreement_s*)e->gg.g.n)
	  p = zx_ENC_SO_ac_AsymmetricKeyAgreement(c, e, p);
  }
  {
      struct zx_ac_Extension_s* e;
      for (e = x->Extension; e; e = (struct zx_ac_Extension_s*)e->gg.g.n)
	  p = zx_ENC_SO_ac_Extension(c, e, p);
  }

  p = zx_enc_so_unknown_elems_and_content(c, p, &x->gg);
  
#if 1 /* NORMALMODE */
  ZX_OUT_CLOSE_TAG(p, "</ac:Authenticator>");
  zx_pop_seen(pop_seen);
#else
  /* root node has no end tag either */
#endif
  ENC_LEN_DEBUG(x, "ac:Authenticator", p-enc_base);
  return p;
}

/* FUNC(zx_ENC_WO_ac_Authenticator) */

/* Render element into string. The XML attributes and elements are
 * processed in wire order by chasing wo pointers. This is what you want for
 * validating signatures on other people's XML documents. */

/* Called by: */
char* zx_ENC_WO_ac_Authenticator(struct zx_ctx* c, struct zx_ac_Authenticator_s* x, char* p )
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
  ENC_LEN_DEBUG(x, "ac:Authenticator", p-enc_base);
  return p;
}

/* FUNC(zx_EASY_ENC_SO_ac_Authenticator) */

/* Called by: */
struct zx_str* zx_EASY_ENC_SO_ac_Authenticator(struct zx_ctx* c, struct zx_ac_Authenticator_s* x )
{
  int len;
  char* buf;
  c->ns_tab = ZX_ALLOC(c, sizeof(zx_ns_tab));
  memcpy(c->ns_tab, zx_ns_tab, sizeof(zx_ns_tab));
  len = zx_LEN_SO_ac_Authenticator(c, x );
  buf = ZX_ALLOC(c, len+1);
  return zx_easy_enc_common(c, zx_ENC_SO_ac_Authenticator(c, x, buf ), buf, len);
}

/* FUNC(zx_EASY_ENC_WO_ac_Authenticator) */

/* Called by: */
struct zx_str* zx_EASY_ENC_WO_ac_Authenticator(struct zx_ctx* c, struct zx_ac_Authenticator_s* x )
{
  int len;
  char* buf;
  c->ns_tab = ZX_ALLOC(c, sizeof(zx_ns_tab));
  memcpy(c->ns_tab, zx_ns_tab, sizeof(zx_ns_tab));
  len = zx_LEN_WO_ac_Authenticator(c, x );
  buf = ZX_ALLOC(c, len+1);
  return zx_easy_enc_common(c, zx_ENC_WO_ac_Authenticator(c, x, buf ), buf, len);
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

#define EL_NAME   ac_AuthenticatorTransportProtocol
#define EL_STRUCT zx_ac_AuthenticatorTransportProtocol_s
#define EL_NS     ac
#define EL_TAG    AuthenticatorTransportProtocol

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

/* FUNC(zx_LEN_SO_ac_AuthenticatorTransportProtocol) */

/* Compute length of an element (and its subelements). The XML attributes
 * and elements are processed in schema order. */

/* Called by: */
int zx_LEN_SO_ac_AuthenticatorTransportProtocol(struct zx_ctx* c, struct zx_ac_AuthenticatorTransportProtocol_s* x )
{
  struct zx_ns_s* pop_seen = 0;
  struct zx_elem_s* se MAYBE_UNUSED;
#if 1 /* NORMALMODE */
  /* *** in simple_elem case should output ns prefix from ns node. */
  int len = sizeof("<ac:AuthenticatorTransportProtocol")-1 + 1 + sizeof("</ac:AuthenticatorTransportProtocol>")-1;
  if (c->inc_ns_len)
    len += zx_len_inc_ns(c, &pop_seen);
  len += zx_len_xmlns_if_not_seen(c, zx_ns_tab+zx_xmlns_ix_ac, &pop_seen);


#else
  /* root node has no begin tag */
  int len = 0;
#endif
  
  {
      struct zx_ac_HTTP_s* e;
      for (e = x->HTTP; e; e = (struct zx_ac_HTTP_s*)e->gg.g.n)
	  len += zx_LEN_SO_ac_HTTP(c, e);
  }
  {
      struct zx_ac_SSL_s* e;
      for (e = x->SSL; e; e = (struct zx_ac_SSL_s*)e->gg.g.n)
	  len += zx_LEN_SO_ac_SSL(c, e);
  }
  {
      struct zx_ac_MobileNetworkNoEncryption_s* e;
      for (e = x->MobileNetworkNoEncryption; e; e = (struct zx_ac_MobileNetworkNoEncryption_s*)e->gg.g.n)
	  len += zx_LEN_SO_ac_MobileNetworkNoEncryption(c, e);
  }
  {
      struct zx_ac_MobileNetworkRadioEncryption_s* e;
      for (e = x->MobileNetworkRadioEncryption; e; e = (struct zx_ac_MobileNetworkRadioEncryption_s*)e->gg.g.n)
	  len += zx_LEN_SO_ac_MobileNetworkRadioEncryption(c, e);
  }
  {
      struct zx_ac_MobileNetworkEndToEndEncryption_s* e;
      for (e = x->MobileNetworkEndToEndEncryption; e; e = (struct zx_ac_MobileNetworkEndToEndEncryption_s*)e->gg.g.n)
	  len += zx_LEN_SO_ac_MobileNetworkEndToEndEncryption(c, e);
  }
  {
      struct zx_ac_WTLS_s* e;
      for (e = x->WTLS; e; e = (struct zx_ac_WTLS_s*)e->gg.g.n)
	  len += zx_LEN_SO_ac_WTLS(c, e);
  }
  {
      struct zx_ac_IPSec_s* e;
      for (e = x->IPSec; e; e = (struct zx_ac_IPSec_s*)e->gg.g.n)
	  len += zx_LEN_SO_ac_IPSec(c, e);
  }
  {
      struct zx_ac_Extension_s* e;
      for (e = x->Extension; e; e = (struct zx_ac_Extension_s*)e->gg.g.n)
	  len += zx_LEN_SO_ac_Extension(c, e);
  }


  len += zx_len_so_common(c, &x->gg);
  zx_pop_seen(pop_seen);
  ENC_LEN_DEBUG(x, "ac:AuthenticatorTransportProtocol", len);
  return len;
}

/* FUNC(zx_LEN_WO_ac_AuthenticatorTransportProtocol) */

/* Compute length of an element (and its subelements). The XML attributes
 * and elements are processed in wire order and no assumptions
 * are made about namespace prefixes. */

/* Called by: */
int zx_LEN_WO_ac_AuthenticatorTransportProtocol(struct zx_ctx* c, struct zx_ac_AuthenticatorTransportProtocol_s* x )
{
  struct zx_ns_s* pop_seen = 0;
  struct zx_elem_s* se MAYBE_UNUSED;
#if 1 /* NORMALMODE */
  int len = 1 + sizeof("AuthenticatorTransportProtocol")-1 + 1 + 2 + sizeof("AuthenticatorTransportProtocol")-1 + 1;
  
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
      struct zx_ac_HTTP_s* e;
      for (e = x->HTTP; e; e = (struct zx_ac_HTTP_s*)e->gg.g.n)
	  len += zx_LEN_WO_ac_HTTP(c, e);
  }
  {
      struct zx_ac_SSL_s* e;
      for (e = x->SSL; e; e = (struct zx_ac_SSL_s*)e->gg.g.n)
	  len += zx_LEN_WO_ac_SSL(c, e);
  }
  {
      struct zx_ac_MobileNetworkNoEncryption_s* e;
      for (e = x->MobileNetworkNoEncryption; e; e = (struct zx_ac_MobileNetworkNoEncryption_s*)e->gg.g.n)
	  len += zx_LEN_WO_ac_MobileNetworkNoEncryption(c, e);
  }
  {
      struct zx_ac_MobileNetworkRadioEncryption_s* e;
      for (e = x->MobileNetworkRadioEncryption; e; e = (struct zx_ac_MobileNetworkRadioEncryption_s*)e->gg.g.n)
	  len += zx_LEN_WO_ac_MobileNetworkRadioEncryption(c, e);
  }
  {
      struct zx_ac_MobileNetworkEndToEndEncryption_s* e;
      for (e = x->MobileNetworkEndToEndEncryption; e; e = (struct zx_ac_MobileNetworkEndToEndEncryption_s*)e->gg.g.n)
	  len += zx_LEN_WO_ac_MobileNetworkEndToEndEncryption(c, e);
  }
  {
      struct zx_ac_WTLS_s* e;
      for (e = x->WTLS; e; e = (struct zx_ac_WTLS_s*)e->gg.g.n)
	  len += zx_LEN_WO_ac_WTLS(c, e);
  }
  {
      struct zx_ac_IPSec_s* e;
      for (e = x->IPSec; e; e = (struct zx_ac_IPSec_s*)e->gg.g.n)
	  len += zx_LEN_WO_ac_IPSec(c, e);
  }
  {
      struct zx_ac_Extension_s* e;
      for (e = x->Extension; e; e = (struct zx_ac_Extension_s*)e->gg.g.n)
	  len += zx_LEN_WO_ac_Extension(c, e);
  }


  len += zx_len_wo_common(c, &x->gg); 
  zx_pop_seen(pop_seen);
  ENC_LEN_DEBUG(x, "ac:AuthenticatorTransportProtocol", len);
  return len;
}

/* FUNC(zx_ENC_SO_ac_AuthenticatorTransportProtocol) */

/* Render element into string. The XML attributes and elements are
 * processed in schema order. This is what you generally want for
 * rendering new data structure to a string. The wo pointers are not used. */

/* Called by: */
char* zx_ENC_SO_ac_AuthenticatorTransportProtocol(struct zx_ctx* c, struct zx_ac_AuthenticatorTransportProtocol_s* x, char* p )
{
  struct zx_elem_s* se MAYBE_UNUSED;
  ENC_LEN_DEBUG_BASE;
#if 1 /* NORMALMODE */
  struct zx_ns_s* pop_seen = 0;
  /* *** in simple_elem case should output ns prefix from ns node. */
  ZX_OUT_TAG(p, "<ac:AuthenticatorTransportProtocol");
  if (c->inc_ns)
    p = zx_enc_inc_ns(c, p, &pop_seen);
  p = zx_enc_xmlns_if_not_seen(c, p, zx_ns_tab+zx_xmlns_ix_ac, &pop_seen);


  p = zx_enc_unknown_attrs(p, x->gg.any_attr);
#else
  /* root node has no begin tag */
#endif
  
  {
      struct zx_ac_HTTP_s* e;
      for (e = x->HTTP; e; e = (struct zx_ac_HTTP_s*)e->gg.g.n)
	  p = zx_ENC_SO_ac_HTTP(c, e, p);
  }
  {
      struct zx_ac_SSL_s* e;
      for (e = x->SSL; e; e = (struct zx_ac_SSL_s*)e->gg.g.n)
	  p = zx_ENC_SO_ac_SSL(c, e, p);
  }
  {
      struct zx_ac_MobileNetworkNoEncryption_s* e;
      for (e = x->MobileNetworkNoEncryption; e; e = (struct zx_ac_MobileNetworkNoEncryption_s*)e->gg.g.n)
	  p = zx_ENC_SO_ac_MobileNetworkNoEncryption(c, e, p);
  }
  {
      struct zx_ac_MobileNetworkRadioEncryption_s* e;
      for (e = x->MobileNetworkRadioEncryption; e; e = (struct zx_ac_MobileNetworkRadioEncryption_s*)e->gg.g.n)
	  p = zx_ENC_SO_ac_MobileNetworkRadioEncryption(c, e, p);
  }
  {
      struct zx_ac_MobileNetworkEndToEndEncryption_s* e;
      for (e = x->MobileNetworkEndToEndEncryption; e; e = (struct zx_ac_MobileNetworkEndToEndEncryption_s*)e->gg.g.n)
	  p = zx_ENC_SO_ac_MobileNetworkEndToEndEncryption(c, e, p);
  }
  {
      struct zx_ac_WTLS_s* e;
      for (e = x->WTLS; e; e = (struct zx_ac_WTLS_s*)e->gg.g.n)
	  p = zx_ENC_SO_ac_WTLS(c, e, p);
  }
  {
      struct zx_ac_IPSec_s* e;
      for (e = x->IPSec; e; e = (struct zx_ac_IPSec_s*)e->gg.g.n)
	  p = zx_ENC_SO_ac_IPSec(c, e, p);
  }
  {
      struct zx_ac_Extension_s* e;
      for (e = x->Extension; e; e = (struct zx_ac_Extension_s*)e->gg.g.n)
	  p = zx_ENC_SO_ac_Extension(c, e, p);
  }

  p = zx_enc_so_unknown_elems_and_content(c, p, &x->gg);
  
#if 1 /* NORMALMODE */
  ZX_OUT_CLOSE_TAG(p, "</ac:AuthenticatorTransportProtocol>");
  zx_pop_seen(pop_seen);
#else
  /* root node has no end tag either */
#endif
  ENC_LEN_DEBUG(x, "ac:AuthenticatorTransportProtocol", p-enc_base);
  return p;
}

/* FUNC(zx_ENC_WO_ac_AuthenticatorTransportProtocol) */

/* Render element into string. The XML attributes and elements are
 * processed in wire order by chasing wo pointers. This is what you want for
 * validating signatures on other people's XML documents. */

/* Called by: */
char* zx_ENC_WO_ac_AuthenticatorTransportProtocol(struct zx_ctx* c, struct zx_ac_AuthenticatorTransportProtocol_s* x, char* p )
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
  ZX_OUT_MEM(p, "AuthenticatorTransportProtocol", sizeof("AuthenticatorTransportProtocol")-1);
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
  ENC_LEN_DEBUG(x, "ac:AuthenticatorTransportProtocol", p-enc_base);
  return p;
}

/* FUNC(zx_EASY_ENC_SO_ac_AuthenticatorTransportProtocol) */

/* Called by: */
struct zx_str* zx_EASY_ENC_SO_ac_AuthenticatorTransportProtocol(struct zx_ctx* c, struct zx_ac_AuthenticatorTransportProtocol_s* x )
{
  int len;
  char* buf;
  c->ns_tab = ZX_ALLOC(c, sizeof(zx_ns_tab));
  memcpy(c->ns_tab, zx_ns_tab, sizeof(zx_ns_tab));
  len = zx_LEN_SO_ac_AuthenticatorTransportProtocol(c, x );
  buf = ZX_ALLOC(c, len+1);
  return zx_easy_enc_common(c, zx_ENC_SO_ac_AuthenticatorTransportProtocol(c, x, buf ), buf, len);
}

/* FUNC(zx_EASY_ENC_WO_ac_AuthenticatorTransportProtocol) */

/* Called by: */
struct zx_str* zx_EASY_ENC_WO_ac_AuthenticatorTransportProtocol(struct zx_ctx* c, struct zx_ac_AuthenticatorTransportProtocol_s* x )
{
  int len;
  char* buf;
  c->ns_tab = ZX_ALLOC(c, sizeof(zx_ns_tab));
  memcpy(c->ns_tab, zx_ns_tab, sizeof(zx_ns_tab));
  len = zx_LEN_WO_ac_AuthenticatorTransportProtocol(c, x );
  buf = ZX_ALLOC(c, len+1);
  return zx_easy_enc_common(c, zx_ENC_WO_ac_AuthenticatorTransportProtocol(c, x, buf ), buf, len);
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

#define EL_NAME   ac_DeactivationCallCenter
#define EL_STRUCT zx_ac_DeactivationCallCenter_s
#define EL_NS     ac
#define EL_TAG    DeactivationCallCenter

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

/* FUNC(zx_LEN_SO_ac_DeactivationCallCenter) */

/* Compute length of an element (and its subelements). The XML attributes
 * and elements are processed in schema order. */

/* Called by: */
int zx_LEN_SO_ac_DeactivationCallCenter(struct zx_ctx* c, struct zx_ac_DeactivationCallCenter_s* x )
{
  struct zx_ns_s* pop_seen = 0;
  struct zx_elem_s* se MAYBE_UNUSED;
#if 1 /* NORMALMODE */
  /* *** in simple_elem case should output ns prefix from ns node. */
  int len = sizeof("<ac:DeactivationCallCenter")-1 + 1 + sizeof("</ac:DeactivationCallCenter>")-1;
  if (c->inc_ns_len)
    len += zx_len_inc_ns(c, &pop_seen);
  len += zx_len_xmlns_if_not_seen(c, zx_ns_tab+zx_xmlns_ix_ac, &pop_seen);


#else
  /* root node has no begin tag */
  int len = 0;
#endif
  
  {
      struct zx_ac_Extension_s* e;
      for (e = x->Extension; e; e = (struct zx_ac_Extension_s*)e->gg.g.n)
	  len += zx_LEN_SO_ac_Extension(c, e);
  }


  len += zx_len_so_common(c, &x->gg);
  zx_pop_seen(pop_seen);
  ENC_LEN_DEBUG(x, "ac:DeactivationCallCenter", len);
  return len;
}

/* FUNC(zx_LEN_WO_ac_DeactivationCallCenter) */

/* Compute length of an element (and its subelements). The XML attributes
 * and elements are processed in wire order and no assumptions
 * are made about namespace prefixes. */

/* Called by: */
int zx_LEN_WO_ac_DeactivationCallCenter(struct zx_ctx* c, struct zx_ac_DeactivationCallCenter_s* x )
{
  struct zx_ns_s* pop_seen = 0;
  struct zx_elem_s* se MAYBE_UNUSED;
#if 1 /* NORMALMODE */
  int len = 1 + sizeof("DeactivationCallCenter")-1 + 1 + 2 + sizeof("DeactivationCallCenter")-1 + 1;
  
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
      struct zx_ac_Extension_s* e;
      for (e = x->Extension; e; e = (struct zx_ac_Extension_s*)e->gg.g.n)
	  len += zx_LEN_WO_ac_Extension(c, e);
  }


  len += zx_len_wo_common(c, &x->gg); 
  zx_pop_seen(pop_seen);
  ENC_LEN_DEBUG(x, "ac:DeactivationCallCenter", len);
  return len;
}

/* FUNC(zx_ENC_SO_ac_DeactivationCallCenter) */

/* Render element into string. The XML attributes and elements are
 * processed in schema order. This is what you generally want for
 * rendering new data structure to a string. The wo pointers are not used. */

/* Called by: */
char* zx_ENC_SO_ac_DeactivationCallCenter(struct zx_ctx* c, struct zx_ac_DeactivationCallCenter_s* x, char* p )
{
  struct zx_elem_s* se MAYBE_UNUSED;
  ENC_LEN_DEBUG_BASE;
#if 1 /* NORMALMODE */
  struct zx_ns_s* pop_seen = 0;
  /* *** in simple_elem case should output ns prefix from ns node. */
  ZX_OUT_TAG(p, "<ac:DeactivationCallCenter");
  if (c->inc_ns)
    p = zx_enc_inc_ns(c, p, &pop_seen);
  p = zx_enc_xmlns_if_not_seen(c, p, zx_ns_tab+zx_xmlns_ix_ac, &pop_seen);


  p = zx_enc_unknown_attrs(p, x->gg.any_attr);
#else
  /* root node has no begin tag */
#endif
  
  {
      struct zx_ac_Extension_s* e;
      for (e = x->Extension; e; e = (struct zx_ac_Extension_s*)e->gg.g.n)
	  p = zx_ENC_SO_ac_Extension(c, e, p);
  }

  p = zx_enc_so_unknown_elems_and_content(c, p, &x->gg);
  
#if 1 /* NORMALMODE */
  ZX_OUT_CLOSE_TAG(p, "</ac:DeactivationCallCenter>");
  zx_pop_seen(pop_seen);
#else
  /* root node has no end tag either */
#endif
  ENC_LEN_DEBUG(x, "ac:DeactivationCallCenter", p-enc_base);
  return p;
}

/* FUNC(zx_ENC_WO_ac_DeactivationCallCenter) */

/* Render element into string. The XML attributes and elements are
 * processed in wire order by chasing wo pointers. This is what you want for
 * validating signatures on other people's XML documents. */

/* Called by: */
char* zx_ENC_WO_ac_DeactivationCallCenter(struct zx_ctx* c, struct zx_ac_DeactivationCallCenter_s* x, char* p )
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
  ZX_OUT_MEM(p, "DeactivationCallCenter", sizeof("DeactivationCallCenter")-1);
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
  ENC_LEN_DEBUG(x, "ac:DeactivationCallCenter", p-enc_base);
  return p;
}

/* FUNC(zx_EASY_ENC_SO_ac_DeactivationCallCenter) */

/* Called by: */
struct zx_str* zx_EASY_ENC_SO_ac_DeactivationCallCenter(struct zx_ctx* c, struct zx_ac_DeactivationCallCenter_s* x )
{
  int len;
  char* buf;
  c->ns_tab = ZX_ALLOC(c, sizeof(zx_ns_tab));
  memcpy(c->ns_tab, zx_ns_tab, sizeof(zx_ns_tab));
  len = zx_LEN_SO_ac_DeactivationCallCenter(c, x );
  buf = ZX_ALLOC(c, len+1);
  return zx_easy_enc_common(c, zx_ENC_SO_ac_DeactivationCallCenter(c, x, buf ), buf, len);
}

/* FUNC(zx_EASY_ENC_WO_ac_DeactivationCallCenter) */

/* Called by: */
struct zx_str* zx_EASY_ENC_WO_ac_DeactivationCallCenter(struct zx_ctx* c, struct zx_ac_DeactivationCallCenter_s* x )
{
  int len;
  char* buf;
  c->ns_tab = ZX_ALLOC(c, sizeof(zx_ns_tab));
  memcpy(c->ns_tab, zx_ns_tab, sizeof(zx_ns_tab));
  len = zx_LEN_WO_ac_DeactivationCallCenter(c, x );
  buf = ZX_ALLOC(c, len+1);
  return zx_easy_enc_common(c, zx_ENC_WO_ac_DeactivationCallCenter(c, x, buf ), buf, len);
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

#define EL_NAME   ac_DigSig
#define EL_STRUCT zx_ac_DigSig_s
#define EL_NS     ac
#define EL_TAG    DigSig

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

/* FUNC(zx_LEN_SO_ac_DigSig) */

/* Compute length of an element (and its subelements). The XML attributes
 * and elements are processed in schema order. */

/* Called by: */
int zx_LEN_SO_ac_DigSig(struct zx_ctx* c, struct zx_ac_DigSig_s* x )
{
  struct zx_ns_s* pop_seen = 0;
  struct zx_elem_s* se MAYBE_UNUSED;
#if 1 /* NORMALMODE */
  /* *** in simple_elem case should output ns prefix from ns node. */
  int len = sizeof("<ac:DigSig")-1 + 1 + sizeof("</ac:DigSig>")-1;
  if (c->inc_ns_len)
    len += zx_len_inc_ns(c, &pop_seen);
  len += zx_len_xmlns_if_not_seen(c, zx_ns_tab+zx_xmlns_ix_ac, &pop_seen);


#else
  /* root node has no begin tag */
  int len = 0;
#endif
  
  {
      struct zx_ac_Extension_s* e;
      for (e = x->Extension; e; e = (struct zx_ac_Extension_s*)e->gg.g.n)
	  len += zx_LEN_SO_ac_Extension(c, e);
  }


  len += zx_len_so_common(c, &x->gg);
  zx_pop_seen(pop_seen);
  ENC_LEN_DEBUG(x, "ac:DigSig", len);
  return len;
}

/* FUNC(zx_LEN_WO_ac_DigSig) */

/* Compute length of an element (and its subelements). The XML attributes
 * and elements are processed in wire order and no assumptions
 * are made about namespace prefixes. */

/* Called by: */
int zx_LEN_WO_ac_DigSig(struct zx_ctx* c, struct zx_ac_DigSig_s* x )
{
  struct zx_ns_s* pop_seen = 0;
  struct zx_elem_s* se MAYBE_UNUSED;
#if 1 /* NORMALMODE */
  int len = 1 + sizeof("DigSig")-1 + 1 + 2 + sizeof("DigSig")-1 + 1;
  
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
      struct zx_ac_Extension_s* e;
      for (e = x->Extension; e; e = (struct zx_ac_Extension_s*)e->gg.g.n)
	  len += zx_LEN_WO_ac_Extension(c, e);
  }


  len += zx_len_wo_common(c, &x->gg); 
  zx_pop_seen(pop_seen);
  ENC_LEN_DEBUG(x, "ac:DigSig", len);
  return len;
}

/* FUNC(zx_ENC_SO_ac_DigSig) */

/* Render element into string. The XML attributes and elements are
 * processed in schema order. This is what you generally want for
 * rendering new data structure to a string. The wo pointers are not used. */

/* Called by: */
char* zx_ENC_SO_ac_DigSig(struct zx_ctx* c, struct zx_ac_DigSig_s* x, char* p )
{
  struct zx_elem_s* se MAYBE_UNUSED;
  ENC_LEN_DEBUG_BASE;
#if 1 /* NORMALMODE */
  struct zx_ns_s* pop_seen = 0;
  /* *** in simple_elem case should output ns prefix from ns node. */
  ZX_OUT_TAG(p, "<ac:DigSig");
  if (c->inc_ns)
    p = zx_enc_inc_ns(c, p, &pop_seen);
  p = zx_enc_xmlns_if_not_seen(c, p, zx_ns_tab+zx_xmlns_ix_ac, &pop_seen);


  p = zx_enc_unknown_attrs(p, x->gg.any_attr);
#else
  /* root node has no begin tag */
#endif
  
  {
      struct zx_ac_Extension_s* e;
      for (e = x->Extension; e; e = (struct zx_ac_Extension_s*)e->gg.g.n)
	  p = zx_ENC_SO_ac_Extension(c, e, p);
  }

  p = zx_enc_so_unknown_elems_and_content(c, p, &x->gg);
  
#if 1 /* NORMALMODE */
  ZX_OUT_CLOSE_TAG(p, "</ac:DigSig>");
  zx_pop_seen(pop_seen);
#else
  /* root node has no end tag either */
#endif
  ENC_LEN_DEBUG(x, "ac:DigSig", p-enc_base);
  return p;
}

/* FUNC(zx_ENC_WO_ac_DigSig) */

/* Render element into string. The XML attributes and elements are
 * processed in wire order by chasing wo pointers. This is what you want for
 * validating signatures on other people's XML documents. */

/* Called by: */
char* zx_ENC_WO_ac_DigSig(struct zx_ctx* c, struct zx_ac_DigSig_s* x, char* p )
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
  ZX_OUT_MEM(p, "DigSig", sizeof("DigSig")-1);
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
  ENC_LEN_DEBUG(x, "ac:DigSig", p-enc_base);
  return p;
}

/* FUNC(zx_EASY_ENC_SO_ac_DigSig) */

/* Called by: */
struct zx_str* zx_EASY_ENC_SO_ac_DigSig(struct zx_ctx* c, struct zx_ac_DigSig_s* x )
{
  int len;
  char* buf;
  c->ns_tab = ZX_ALLOC(c, sizeof(zx_ns_tab));
  memcpy(c->ns_tab, zx_ns_tab, sizeof(zx_ns_tab));
  len = zx_LEN_SO_ac_DigSig(c, x );
  buf = ZX_ALLOC(c, len+1);
  return zx_easy_enc_common(c, zx_ENC_SO_ac_DigSig(c, x, buf ), buf, len);
}

/* FUNC(zx_EASY_ENC_WO_ac_DigSig) */

/* Called by: */
struct zx_str* zx_EASY_ENC_WO_ac_DigSig(struct zx_ctx* c, struct zx_ac_DigSig_s* x )
{
  int len;
  char* buf;
  c->ns_tab = ZX_ALLOC(c, sizeof(zx_ns_tab));
  memcpy(c->ns_tab, zx_ns_tab, sizeof(zx_ns_tab));
  len = zx_LEN_WO_ac_DigSig(c, x );
  buf = ZX_ALLOC(c, len+1);
  return zx_easy_enc_common(c, zx_ENC_WO_ac_DigSig(c, x, buf ), buf, len);
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

#define EL_NAME   ac_Extension
#define EL_STRUCT zx_ac_Extension_s
#define EL_NS     ac
#define EL_TAG    Extension

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

/* FUNC(zx_LEN_SO_ac_Extension) */

/* Compute length of an element (and its subelements). The XML attributes
 * and elements are processed in schema order. */

/* Called by: */
int zx_LEN_SO_ac_Extension(struct zx_ctx* c, struct zx_ac_Extension_s* x )
{
  struct zx_ns_s* pop_seen = 0;
  struct zx_elem_s* se MAYBE_UNUSED;
#if 1 /* NORMALMODE */
  /* *** in simple_elem case should output ns prefix from ns node. */
  int len = sizeof("<ac:Extension")-1 + 1 + sizeof("</ac:Extension>")-1;
  if (c->inc_ns_len)
    len += zx_len_inc_ns(c, &pop_seen);
  len += zx_len_xmlns_if_not_seen(c, zx_ns_tab+zx_xmlns_ix_ac, &pop_seen);


#else
  /* root node has no begin tag */
  int len = 0;
#endif
  


  len += zx_len_so_common(c, &x->gg);
  zx_pop_seen(pop_seen);
  ENC_LEN_DEBUG(x, "ac:Extension", len);
  return len;
}

/* FUNC(zx_LEN_WO_ac_Extension) */

/* Compute length of an element (and its subelements). The XML attributes
 * and elements are processed in wire order and no assumptions
 * are made about namespace prefixes. */

/* Called by: */
int zx_LEN_WO_ac_Extension(struct zx_ctx* c, struct zx_ac_Extension_s* x )
{
  struct zx_ns_s* pop_seen = 0;
  struct zx_elem_s* se MAYBE_UNUSED;
#if 1 /* NORMALMODE */
  int len = 1 + sizeof("Extension")-1 + 1 + 2 + sizeof("Extension")-1 + 1;
  
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
  ENC_LEN_DEBUG(x, "ac:Extension", len);
  return len;
}

/* FUNC(zx_ENC_SO_ac_Extension) */

/* Render element into string. The XML attributes and elements are
 * processed in schema order. This is what you generally want for
 * rendering new data structure to a string. The wo pointers are not used. */

/* Called by: */
char* zx_ENC_SO_ac_Extension(struct zx_ctx* c, struct zx_ac_Extension_s* x, char* p )
{
  struct zx_elem_s* se MAYBE_UNUSED;
  ENC_LEN_DEBUG_BASE;
#if 1 /* NORMALMODE */
  struct zx_ns_s* pop_seen = 0;
  /* *** in simple_elem case should output ns prefix from ns node. */
  ZX_OUT_TAG(p, "<ac:Extension");
  if (c->inc_ns)
    p = zx_enc_inc_ns(c, p, &pop_seen);
  p = zx_enc_xmlns_if_not_seen(c, p, zx_ns_tab+zx_xmlns_ix_ac, &pop_seen);


  p = zx_enc_unknown_attrs(p, x->gg.any_attr);
#else
  /* root node has no begin tag */
#endif
  

  p = zx_enc_so_unknown_elems_and_content(c, p, &x->gg);
  
#if 1 /* NORMALMODE */
  ZX_OUT_CLOSE_TAG(p, "</ac:Extension>");
  zx_pop_seen(pop_seen);
#else
  /* root node has no end tag either */
#endif
  ENC_LEN_DEBUG(x, "ac:Extension", p-enc_base);
  return p;
}

/* FUNC(zx_ENC_WO_ac_Extension) */

/* Render element into string. The XML attributes and elements are
 * processed in wire order by chasing wo pointers. This is what you want for
 * validating signatures on other people's XML documents. */

/* Called by: */
char* zx_ENC_WO_ac_Extension(struct zx_ctx* c, struct zx_ac_Extension_s* x, char* p )
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
  ZX_OUT_MEM(p, "Extension", sizeof("Extension")-1);
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
  ENC_LEN_DEBUG(x, "ac:Extension", p-enc_base);
  return p;
}

/* FUNC(zx_EASY_ENC_SO_ac_Extension) */

/* Called by: */
struct zx_str* zx_EASY_ENC_SO_ac_Extension(struct zx_ctx* c, struct zx_ac_Extension_s* x )
{
  int len;
  char* buf;
  c->ns_tab = ZX_ALLOC(c, sizeof(zx_ns_tab));
  memcpy(c->ns_tab, zx_ns_tab, sizeof(zx_ns_tab));
  len = zx_LEN_SO_ac_Extension(c, x );
  buf = ZX_ALLOC(c, len+1);
  return zx_easy_enc_common(c, zx_ENC_SO_ac_Extension(c, x, buf ), buf, len);
}

/* FUNC(zx_EASY_ENC_WO_ac_Extension) */

/* Called by: */
struct zx_str* zx_EASY_ENC_WO_ac_Extension(struct zx_ctx* c, struct zx_ac_Extension_s* x )
{
  int len;
  char* buf;
  c->ns_tab = ZX_ALLOC(c, sizeof(zx_ns_tab));
  memcpy(c->ns_tab, zx_ns_tab, sizeof(zx_ns_tab));
  len = zx_LEN_WO_ac_Extension(c, x );
  buf = ZX_ALLOC(c, len+1);
  return zx_easy_enc_common(c, zx_ENC_WO_ac_Extension(c, x, buf ), buf, len);
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

#define EL_NAME   ac_Generation
#define EL_STRUCT zx_ac_Generation_s
#define EL_NS     ac
#define EL_TAG    Generation

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

/* FUNC(zx_LEN_SO_ac_Generation) */

/* Compute length of an element (and its subelements). The XML attributes
 * and elements are processed in schema order. */

/* Called by: */
int zx_LEN_SO_ac_Generation(struct zx_ctx* c, struct zx_ac_Generation_s* x )
{
  struct zx_ns_s* pop_seen = 0;
  struct zx_elem_s* se MAYBE_UNUSED;
#if 1 /* NORMALMODE */
  /* *** in simple_elem case should output ns prefix from ns node. */
  int len = sizeof("<ac:Generation")-1 + 1 + sizeof("</ac:Generation>")-1;
  if (c->inc_ns_len)
    len += zx_len_inc_ns(c, &pop_seen);
  len += zx_len_xmlns_if_not_seen(c, zx_ns_tab+zx_xmlns_ix_ac, &pop_seen);

  len += zx_attr_so_len(x->mechanism, sizeof("mechanism")-1);

#else
  /* root node has no begin tag */
  int len = 0;
#endif
  


  len += zx_len_so_common(c, &x->gg);
  zx_pop_seen(pop_seen);
  ENC_LEN_DEBUG(x, "ac:Generation", len);
  return len;
}

/* FUNC(zx_LEN_WO_ac_Generation) */

/* Compute length of an element (and its subelements). The XML attributes
 * and elements are processed in wire order and no assumptions
 * are made about namespace prefixes. */

/* Called by: */
int zx_LEN_WO_ac_Generation(struct zx_ctx* c, struct zx_ac_Generation_s* x )
{
  struct zx_ns_s* pop_seen = 0;
  struct zx_elem_s* se MAYBE_UNUSED;
#if 1 /* NORMALMODE */
  int len = 1 + sizeof("Generation")-1 + 1 + 2 + sizeof("Generation")-1 + 1;
  
  if (x->gg.g.ns && x->gg.g.ns->prefix_len)
    len += (x->gg.g.ns->prefix_len + 1) * 2;
  if (c->inc_ns_len)
    len += zx_len_inc_ns(c, &pop_seen);
  len += zx_len_xmlns_if_not_seen(c, x->gg.g.ns, &pop_seen);

  len += zx_attr_wo_len(x->mechanism, sizeof("mechanism")-1);

#else
  /* root node has no begin tag */
  int len = 0;
#endif
  


  len += zx_len_wo_common(c, &x->gg); 
  zx_pop_seen(pop_seen);
  ENC_LEN_DEBUG(x, "ac:Generation", len);
  return len;
}

/* FUNC(zx_ENC_SO_ac_Generation) */

/* Render element into string. The XML attributes and elements are
 * processed in schema order. This is what you generally want for
 * rendering new data structure to a string. The wo pointers are not used. */

/* Called by: */
char* zx_ENC_SO_ac_Generation(struct zx_ctx* c, struct zx_ac_Generation_s* x, char* p )
{
  struct zx_elem_s* se MAYBE_UNUSED;
  ENC_LEN_DEBUG_BASE;
#if 1 /* NORMALMODE */
  struct zx_ns_s* pop_seen = 0;
  /* *** in simple_elem case should output ns prefix from ns node. */
  ZX_OUT_TAG(p, "<ac:Generation");
  if (c->inc_ns)
    p = zx_enc_inc_ns(c, p, &pop_seen);
  p = zx_enc_xmlns_if_not_seen(c, p, zx_ns_tab+zx_xmlns_ix_ac, &pop_seen);

  p = zx_attr_so_enc(p, x->mechanism, " mechanism=\"", sizeof(" mechanism=\"")-1);

  p = zx_enc_unknown_attrs(p, x->gg.any_attr);
#else
  /* root node has no begin tag */
#endif
  

  p = zx_enc_so_unknown_elems_and_content(c, p, &x->gg);
  
#if 1 /* NORMALMODE */
  ZX_OUT_CLOSE_TAG(p, "</ac:Generation>");
  zx_pop_seen(pop_seen);
#else
  /* root node has no end tag either */
#endif
  ENC_LEN_DEBUG(x, "ac:Generation", p-enc_base);
  return p;
}

/* FUNC(zx_ENC_WO_ac_Generation) */

/* Render element into string. The XML attributes and elements are
 * processed in wire order by chasing wo pointers. This is what you want for
 * validating signatures on other people's XML documents. */

/* Called by: */
char* zx_ENC_WO_ac_Generation(struct zx_ctx* c, struct zx_ac_Generation_s* x, char* p )
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
  ZX_OUT_MEM(p, "Generation", sizeof("Generation")-1);
  qq = p;

  /* *** sort the namespaces */
  if (c->inc_ns)
    zx_add_inc_ns(c, &pop_seen);
  zx_add_xmlns_if_not_seen(c, x->gg.g.ns, &pop_seen);

  p = zx_enc_seen(p, pop_seen); 
  p = zx_attr_wo_enc(p, x->mechanism, "mechanism=\"", sizeof("mechanism=\"")-1);

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
  ENC_LEN_DEBUG(x, "ac:Generation", p-enc_base);
  return p;
}

/* FUNC(zx_EASY_ENC_SO_ac_Generation) */

/* Called by: */
struct zx_str* zx_EASY_ENC_SO_ac_Generation(struct zx_ctx* c, struct zx_ac_Generation_s* x )
{
  int len;
  char* buf;
  c->ns_tab = ZX_ALLOC(c, sizeof(zx_ns_tab));
  memcpy(c->ns_tab, zx_ns_tab, sizeof(zx_ns_tab));
  len = zx_LEN_SO_ac_Generation(c, x );
  buf = ZX_ALLOC(c, len+1);
  return zx_easy_enc_common(c, zx_ENC_SO_ac_Generation(c, x, buf ), buf, len);
}

/* FUNC(zx_EASY_ENC_WO_ac_Generation) */

/* Called by: */
struct zx_str* zx_EASY_ENC_WO_ac_Generation(struct zx_ctx* c, struct zx_ac_Generation_s* x )
{
  int len;
  char* buf;
  c->ns_tab = ZX_ALLOC(c, sizeof(zx_ns_tab));
  memcpy(c->ns_tab, zx_ns_tab, sizeof(zx_ns_tab));
  len = zx_LEN_WO_ac_Generation(c, x );
  buf = ZX_ALLOC(c, len+1);
  return zx_easy_enc_common(c, zx_ENC_WO_ac_Generation(c, x, buf ), buf, len);
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

#define EL_NAME   ac_GoverningAgreementRef
#define EL_STRUCT zx_ac_GoverningAgreementRef_s
#define EL_NS     ac
#define EL_TAG    GoverningAgreementRef

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

/* FUNC(zx_LEN_SO_ac_GoverningAgreementRef) */

/* Compute length of an element (and its subelements). The XML attributes
 * and elements are processed in schema order. */

/* Called by: */
int zx_LEN_SO_ac_GoverningAgreementRef(struct zx_ctx* c, struct zx_ac_GoverningAgreementRef_s* x )
{
  struct zx_ns_s* pop_seen = 0;
  struct zx_elem_s* se MAYBE_UNUSED;
#if 1 /* NORMALMODE */
  /* *** in simple_elem case should output ns prefix from ns node. */
  int len = sizeof("<ac:GoverningAgreementRef")-1 + 1 + sizeof("</ac:GoverningAgreementRef>")-1;
  if (c->inc_ns_len)
    len += zx_len_inc_ns(c, &pop_seen);
  len += zx_len_xmlns_if_not_seen(c, zx_ns_tab+zx_xmlns_ix_ac, &pop_seen);

  len += zx_attr_so_len(x->governingAgreementRef, sizeof("governingAgreementRef")-1);

#else
  /* root node has no begin tag */
  int len = 0;
#endif
  


  len += zx_len_so_common(c, &x->gg);
  zx_pop_seen(pop_seen);
  ENC_LEN_DEBUG(x, "ac:GoverningAgreementRef", len);
  return len;
}

/* FUNC(zx_LEN_WO_ac_GoverningAgreementRef) */

/* Compute length of an element (and its subelements). The XML attributes
 * and elements are processed in wire order and no assumptions
 * are made about namespace prefixes. */

/* Called by: */
int zx_LEN_WO_ac_GoverningAgreementRef(struct zx_ctx* c, struct zx_ac_GoverningAgreementRef_s* x )
{
  struct zx_ns_s* pop_seen = 0;
  struct zx_elem_s* se MAYBE_UNUSED;
#if 1 /* NORMALMODE */
  int len = 1 + sizeof("GoverningAgreementRef")-1 + 1 + 2 + sizeof("GoverningAgreementRef")-1 + 1;
  
  if (x->gg.g.ns && x->gg.g.ns->prefix_len)
    len += (x->gg.g.ns->prefix_len + 1) * 2;
  if (c->inc_ns_len)
    len += zx_len_inc_ns(c, &pop_seen);
  len += zx_len_xmlns_if_not_seen(c, x->gg.g.ns, &pop_seen);

  len += zx_attr_wo_len(x->governingAgreementRef, sizeof("governingAgreementRef")-1);

#else
  /* root node has no begin tag */
  int len = 0;
#endif
  


  len += zx_len_wo_common(c, &x->gg); 
  zx_pop_seen(pop_seen);
  ENC_LEN_DEBUG(x, "ac:GoverningAgreementRef", len);
  return len;
}

/* FUNC(zx_ENC_SO_ac_GoverningAgreementRef) */

/* Render element into string. The XML attributes and elements are
 * processed in schema order. This is what you generally want for
 * rendering new data structure to a string. The wo pointers are not used. */

/* Called by: */
char* zx_ENC_SO_ac_GoverningAgreementRef(struct zx_ctx* c, struct zx_ac_GoverningAgreementRef_s* x, char* p )
{
  struct zx_elem_s* se MAYBE_UNUSED;
  ENC_LEN_DEBUG_BASE;
#if 1 /* NORMALMODE */
  struct zx_ns_s* pop_seen = 0;
  /* *** in simple_elem case should output ns prefix from ns node. */
  ZX_OUT_TAG(p, "<ac:GoverningAgreementRef");
  if (c->inc_ns)
    p = zx_enc_inc_ns(c, p, &pop_seen);
  p = zx_enc_xmlns_if_not_seen(c, p, zx_ns_tab+zx_xmlns_ix_ac, &pop_seen);

  p = zx_attr_so_enc(p, x->governingAgreementRef, " governingAgreementRef=\"", sizeof(" governingAgreementRef=\"")-1);

  p = zx_enc_unknown_attrs(p, x->gg.any_attr);
#else
  /* root node has no begin tag */
#endif
  

  p = zx_enc_so_unknown_elems_and_content(c, p, &x->gg);
  
#if 1 /* NORMALMODE */
  ZX_OUT_CLOSE_TAG(p, "</ac:GoverningAgreementRef>");
  zx_pop_seen(pop_seen);
#else
  /* root node has no end tag either */
#endif
  ENC_LEN_DEBUG(x, "ac:GoverningAgreementRef", p-enc_base);
  return p;
}

/* FUNC(zx_ENC_WO_ac_GoverningAgreementRef) */

/* Render element into string. The XML attributes and elements are
 * processed in wire order by chasing wo pointers. This is what you want for
 * validating signatures on other people's XML documents. */

/* Called by: */
char* zx_ENC_WO_ac_GoverningAgreementRef(struct zx_ctx* c, struct zx_ac_GoverningAgreementRef_s* x, char* p )
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
  ZX_OUT_MEM(p, "GoverningAgreementRef", sizeof("GoverningAgreementRef")-1);
  qq = p;

  /* *** sort the namespaces */
  if (c->inc_ns)
    zx_add_inc_ns(c, &pop_seen);
  zx_add_xmlns_if_not_seen(c, x->gg.g.ns, &pop_seen);

  p = zx_enc_seen(p, pop_seen); 
  p = zx_attr_wo_enc(p, x->governingAgreementRef, "governingAgreementRef=\"", sizeof("governingAgreementRef=\"")-1);

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
  ENC_LEN_DEBUG(x, "ac:GoverningAgreementRef", p-enc_base);
  return p;
}

/* FUNC(zx_EASY_ENC_SO_ac_GoverningAgreementRef) */

/* Called by: */
struct zx_str* zx_EASY_ENC_SO_ac_GoverningAgreementRef(struct zx_ctx* c, struct zx_ac_GoverningAgreementRef_s* x )
{
  int len;
  char* buf;
  c->ns_tab = ZX_ALLOC(c, sizeof(zx_ns_tab));
  memcpy(c->ns_tab, zx_ns_tab, sizeof(zx_ns_tab));
  len = zx_LEN_SO_ac_GoverningAgreementRef(c, x );
  buf = ZX_ALLOC(c, len+1);
  return zx_easy_enc_common(c, zx_ENC_SO_ac_GoverningAgreementRef(c, x, buf ), buf, len);
}

/* FUNC(zx_EASY_ENC_WO_ac_GoverningAgreementRef) */

/* Called by: */
struct zx_str* zx_EASY_ENC_WO_ac_GoverningAgreementRef(struct zx_ctx* c, struct zx_ac_GoverningAgreementRef_s* x )
{
  int len;
  char* buf;
  c->ns_tab = ZX_ALLOC(c, sizeof(zx_ns_tab));
  memcpy(c->ns_tab, zx_ns_tab, sizeof(zx_ns_tab));
  len = zx_LEN_WO_ac_GoverningAgreementRef(c, x );
  buf = ZX_ALLOC(c, len+1);
  return zx_easy_enc_common(c, zx_ENC_WO_ac_GoverningAgreementRef(c, x, buf ), buf, len);
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

#define EL_NAME   ac_GoverningAgreements
#define EL_STRUCT zx_ac_GoverningAgreements_s
#define EL_NS     ac
#define EL_TAG    GoverningAgreements

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

/* FUNC(zx_LEN_SO_ac_GoverningAgreements) */

/* Compute length of an element (and its subelements). The XML attributes
 * and elements are processed in schema order. */

/* Called by: */
int zx_LEN_SO_ac_GoverningAgreements(struct zx_ctx* c, struct zx_ac_GoverningAgreements_s* x )
{
  struct zx_ns_s* pop_seen = 0;
  struct zx_elem_s* se MAYBE_UNUSED;
#if 1 /* NORMALMODE */
  /* *** in simple_elem case should output ns prefix from ns node. */
  int len = sizeof("<ac:GoverningAgreements")-1 + 1 + sizeof("</ac:GoverningAgreements>")-1;
  if (c->inc_ns_len)
    len += zx_len_inc_ns(c, &pop_seen);
  len += zx_len_xmlns_if_not_seen(c, zx_ns_tab+zx_xmlns_ix_ac, &pop_seen);


#else
  /* root node has no begin tag */
  int len = 0;
#endif
  
  {
      struct zx_ac_GoverningAgreementRef_s* e;
      for (e = x->GoverningAgreementRef; e; e = (struct zx_ac_GoverningAgreementRef_s*)e->gg.g.n)
	  len += zx_LEN_SO_ac_GoverningAgreementRef(c, e);
  }


  len += zx_len_so_common(c, &x->gg);
  zx_pop_seen(pop_seen);
  ENC_LEN_DEBUG(x, "ac:GoverningAgreements", len);
  return len;
}

/* FUNC(zx_LEN_WO_ac_GoverningAgreements) */

/* Compute length of an element (and its subelements). The XML attributes
 * and elements are processed in wire order and no assumptions
 * are made about namespace prefixes. */

/* Called by: */
int zx_LEN_WO_ac_GoverningAgreements(struct zx_ctx* c, struct zx_ac_GoverningAgreements_s* x )
{
  struct zx_ns_s* pop_seen = 0;
  struct zx_elem_s* se MAYBE_UNUSED;
#if 1 /* NORMALMODE */
  int len = 1 + sizeof("GoverningAgreements")-1 + 1 + 2 + sizeof("GoverningAgreements")-1 + 1;
  
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
      struct zx_ac_GoverningAgreementRef_s* e;
      for (e = x->GoverningAgreementRef; e; e = (struct zx_ac_GoverningAgreementRef_s*)e->gg.g.n)
	  len += zx_LEN_WO_ac_GoverningAgreementRef(c, e);
  }


  len += zx_len_wo_common(c, &x->gg); 
  zx_pop_seen(pop_seen);
  ENC_LEN_DEBUG(x, "ac:GoverningAgreements", len);
  return len;
}

/* FUNC(zx_ENC_SO_ac_GoverningAgreements) */

/* Render element into string. The XML attributes and elements are
 * processed in schema order. This is what you generally want for
 * rendering new data structure to a string. The wo pointers are not used. */

/* Called by: */
char* zx_ENC_SO_ac_GoverningAgreements(struct zx_ctx* c, struct zx_ac_GoverningAgreements_s* x, char* p )
{
  struct zx_elem_s* se MAYBE_UNUSED;
  ENC_LEN_DEBUG_BASE;
#if 1 /* NORMALMODE */
  struct zx_ns_s* pop_seen = 0;
  /* *** in simple_elem case should output ns prefix from ns node. */
  ZX_OUT_TAG(p, "<ac:GoverningAgreements");
  if (c->inc_ns)
    p = zx_enc_inc_ns(c, p, &pop_seen);
  p = zx_enc_xmlns_if_not_seen(c, p, zx_ns_tab+zx_xmlns_ix_ac, &pop_seen);


  p = zx_enc_unknown_attrs(p, x->gg.any_attr);
#else
  /* root node has no begin tag */
#endif
  
  {
      struct zx_ac_GoverningAgreementRef_s* e;
      for (e = x->GoverningAgreementRef; e; e = (struct zx_ac_GoverningAgreementRef_s*)e->gg.g.n)
	  p = zx_ENC_SO_ac_GoverningAgreementRef(c, e, p);
  }

  p = zx_enc_so_unknown_elems_and_content(c, p, &x->gg);
  
#if 1 /* NORMALMODE */
  ZX_OUT_CLOSE_TAG(p, "</ac:GoverningAgreements>");
  zx_pop_seen(pop_seen);
#else
  /* root node has no end tag either */
#endif
  ENC_LEN_DEBUG(x, "ac:GoverningAgreements", p-enc_base);
  return p;
}

/* FUNC(zx_ENC_WO_ac_GoverningAgreements) */

/* Render element into string. The XML attributes and elements are
 * processed in wire order by chasing wo pointers. This is what you want for
 * validating signatures on other people's XML documents. */

/* Called by: */
char* zx_ENC_WO_ac_GoverningAgreements(struct zx_ctx* c, struct zx_ac_GoverningAgreements_s* x, char* p )
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
  ZX_OUT_MEM(p, "GoverningAgreements", sizeof("GoverningAgreements")-1);
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
  ENC_LEN_DEBUG(x, "ac:GoverningAgreements", p-enc_base);
  return p;
}

/* FUNC(zx_EASY_ENC_SO_ac_GoverningAgreements) */

/* Called by: */
struct zx_str* zx_EASY_ENC_SO_ac_GoverningAgreements(struct zx_ctx* c, struct zx_ac_GoverningAgreements_s* x )
{
  int len;
  char* buf;
  c->ns_tab = ZX_ALLOC(c, sizeof(zx_ns_tab));
  memcpy(c->ns_tab, zx_ns_tab, sizeof(zx_ns_tab));
  len = zx_LEN_SO_ac_GoverningAgreements(c, x );
  buf = ZX_ALLOC(c, len+1);
  return zx_easy_enc_common(c, zx_ENC_SO_ac_GoverningAgreements(c, x, buf ), buf, len);
}

/* FUNC(zx_EASY_ENC_WO_ac_GoverningAgreements) */

/* Called by: */
struct zx_str* zx_EASY_ENC_WO_ac_GoverningAgreements(struct zx_ctx* c, struct zx_ac_GoverningAgreements_s* x )
{
  int len;
  char* buf;
  c->ns_tab = ZX_ALLOC(c, sizeof(zx_ns_tab));
  memcpy(c->ns_tab, zx_ns_tab, sizeof(zx_ns_tab));
  len = zx_LEN_WO_ac_GoverningAgreements(c, x );
  buf = ZX_ALLOC(c, len+1);
  return zx_easy_enc_common(c, zx_ENC_WO_ac_GoverningAgreements(c, x, buf ), buf, len);
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

#define EL_NAME   ac_HTTP
#define EL_STRUCT zx_ac_HTTP_s
#define EL_NS     ac
#define EL_TAG    HTTP

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

/* FUNC(zx_LEN_SO_ac_HTTP) */

/* Compute length of an element (and its subelements). The XML attributes
 * and elements are processed in schema order. */

/* Called by: */
int zx_LEN_SO_ac_HTTP(struct zx_ctx* c, struct zx_ac_HTTP_s* x )
{
  struct zx_ns_s* pop_seen = 0;
  struct zx_elem_s* se MAYBE_UNUSED;
#if 1 /* NORMALMODE */
  /* *** in simple_elem case should output ns prefix from ns node. */
  int len = sizeof("<ac:HTTP")-1 + 1 + sizeof("</ac:HTTP>")-1;
  if (c->inc_ns_len)
    len += zx_len_inc_ns(c, &pop_seen);
  len += zx_len_xmlns_if_not_seen(c, zx_ns_tab+zx_xmlns_ix_ac, &pop_seen);


#else
  /* root node has no begin tag */
  int len = 0;
#endif
  
  {
      struct zx_ac_Extension_s* e;
      for (e = x->Extension; e; e = (struct zx_ac_Extension_s*)e->gg.g.n)
	  len += zx_LEN_SO_ac_Extension(c, e);
  }


  len += zx_len_so_common(c, &x->gg);
  zx_pop_seen(pop_seen);
  ENC_LEN_DEBUG(x, "ac:HTTP", len);
  return len;
}

/* FUNC(zx_LEN_WO_ac_HTTP) */

/* Compute length of an element (and its subelements). The XML attributes
 * and elements are processed in wire order and no assumptions
 * are made about namespace prefixes. */

/* Called by: */
int zx_LEN_WO_ac_HTTP(struct zx_ctx* c, struct zx_ac_HTTP_s* x )
{
  struct zx_ns_s* pop_seen = 0;
  struct zx_elem_s* se MAYBE_UNUSED;
#if 1 /* NORMALMODE */
  int len = 1 + sizeof("HTTP")-1 + 1 + 2 + sizeof("HTTP")-1 + 1;
  
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
      struct zx_ac_Extension_s* e;
      for (e = x->Extension; e; e = (struct zx_ac_Extension_s*)e->gg.g.n)
	  len += zx_LEN_WO_ac_Extension(c, e);
  }


  len += zx_len_wo_common(c, &x->gg); 
  zx_pop_seen(pop_seen);
  ENC_LEN_DEBUG(x, "ac:HTTP", len);
  return len;
}

/* FUNC(zx_ENC_SO_ac_HTTP) */

/* Render element into string. The XML attributes and elements are
 * processed in schema order. This is what you generally want for
 * rendering new data structure to a string. The wo pointers are not used. */

/* Called by: */
char* zx_ENC_SO_ac_HTTP(struct zx_ctx* c, struct zx_ac_HTTP_s* x, char* p )
{
  struct zx_elem_s* se MAYBE_UNUSED;
  ENC_LEN_DEBUG_BASE;
#if 1 /* NORMALMODE */
  struct zx_ns_s* pop_seen = 0;
  /* *** in simple_elem case should output ns prefix from ns node. */
  ZX_OUT_TAG(p, "<ac:HTTP");
  if (c->inc_ns)
    p = zx_enc_inc_ns(c, p, &pop_seen);
  p = zx_enc_xmlns_if_not_seen(c, p, zx_ns_tab+zx_xmlns_ix_ac, &pop_seen);


  p = zx_enc_unknown_attrs(p, x->gg.any_attr);
#else
  /* root node has no begin tag */
#endif
  
  {
      struct zx_ac_Extension_s* e;
      for (e = x->Extension; e; e = (struct zx_ac_Extension_s*)e->gg.g.n)
	  p = zx_ENC_SO_ac_Extension(c, e, p);
  }

  p = zx_enc_so_unknown_elems_and_content(c, p, &x->gg);
  
#if 1 /* NORMALMODE */
  ZX_OUT_CLOSE_TAG(p, "</ac:HTTP>");
  zx_pop_seen(pop_seen);
#else
  /* root node has no end tag either */
#endif
  ENC_LEN_DEBUG(x, "ac:HTTP", p-enc_base);
  return p;
}

/* FUNC(zx_ENC_WO_ac_HTTP) */

/* Render element into string. The XML attributes and elements are
 * processed in wire order by chasing wo pointers. This is what you want for
 * validating signatures on other people's XML documents. */

/* Called by: */
char* zx_ENC_WO_ac_HTTP(struct zx_ctx* c, struct zx_ac_HTTP_s* x, char* p )
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
  ZX_OUT_MEM(p, "HTTP", sizeof("HTTP")-1);
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
  ENC_LEN_DEBUG(x, "ac:HTTP", p-enc_base);
  return p;
}

/* FUNC(zx_EASY_ENC_SO_ac_HTTP) */

/* Called by: */
struct zx_str* zx_EASY_ENC_SO_ac_HTTP(struct zx_ctx* c, struct zx_ac_HTTP_s* x )
{
  int len;
  char* buf;
  c->ns_tab = ZX_ALLOC(c, sizeof(zx_ns_tab));
  memcpy(c->ns_tab, zx_ns_tab, sizeof(zx_ns_tab));
  len = zx_LEN_SO_ac_HTTP(c, x );
  buf = ZX_ALLOC(c, len+1);
  return zx_easy_enc_common(c, zx_ENC_SO_ac_HTTP(c, x, buf ), buf, len);
}

/* FUNC(zx_EASY_ENC_WO_ac_HTTP) */

/* Called by: */
struct zx_str* zx_EASY_ENC_WO_ac_HTTP(struct zx_ctx* c, struct zx_ac_HTTP_s* x )
{
  int len;
  char* buf;
  c->ns_tab = ZX_ALLOC(c, sizeof(zx_ns_tab));
  memcpy(c->ns_tab, zx_ns_tab, sizeof(zx_ns_tab));
  len = zx_LEN_WO_ac_HTTP(c, x );
  buf = ZX_ALLOC(c, len+1);
  return zx_easy_enc_common(c, zx_ENC_WO_ac_HTTP(c, x, buf ), buf, len);
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

#define EL_NAME   ac_IPAddress
#define EL_STRUCT zx_ac_IPAddress_s
#define EL_NS     ac
#define EL_TAG    IPAddress

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

/* FUNC(zx_LEN_SO_ac_IPAddress) */

/* Compute length of an element (and its subelements). The XML attributes
 * and elements are processed in schema order. */

/* Called by: */
int zx_LEN_SO_ac_IPAddress(struct zx_ctx* c, struct zx_ac_IPAddress_s* x )
{
  struct zx_ns_s* pop_seen = 0;
  struct zx_elem_s* se MAYBE_UNUSED;
#if 1 /* NORMALMODE */
  /* *** in simple_elem case should output ns prefix from ns node. */
  int len = sizeof("<ac:IPAddress")-1 + 1 + sizeof("</ac:IPAddress>")-1;
  if (c->inc_ns_len)
    len += zx_len_inc_ns(c, &pop_seen);
  len += zx_len_xmlns_if_not_seen(c, zx_ns_tab+zx_xmlns_ix_ac, &pop_seen);


#else
  /* root node has no begin tag */
  int len = 0;
#endif
  
  {
      struct zx_ac_Extension_s* e;
      for (e = x->Extension; e; e = (struct zx_ac_Extension_s*)e->gg.g.n)
	  len += zx_LEN_SO_ac_Extension(c, e);
  }


  len += zx_len_so_common(c, &x->gg);
  zx_pop_seen(pop_seen);
  ENC_LEN_DEBUG(x, "ac:IPAddress", len);
  return len;
}

/* FUNC(zx_LEN_WO_ac_IPAddress) */

/* Compute length of an element (and its subelements). The XML attributes
 * and elements are processed in wire order and no assumptions
 * are made about namespace prefixes. */

/* Called by: */
int zx_LEN_WO_ac_IPAddress(struct zx_ctx* c, struct zx_ac_IPAddress_s* x )
{
  struct zx_ns_s* pop_seen = 0;
  struct zx_elem_s* se MAYBE_UNUSED;
#if 1 /* NORMALMODE */
  int len = 1 + sizeof("IPAddress")-1 + 1 + 2 + sizeof("IPAddress")-1 + 1;
  
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
      struct zx_ac_Extension_s* e;
      for (e = x->Extension; e; e = (struct zx_ac_Extension_s*)e->gg.g.n)
	  len += zx_LEN_WO_ac_Extension(c, e);
  }


  len += zx_len_wo_common(c, &x->gg); 
  zx_pop_seen(pop_seen);
  ENC_LEN_DEBUG(x, "ac:IPAddress", len);
  return len;
}

/* FUNC(zx_ENC_SO_ac_IPAddress) */

/* Render element into string. The XML attributes and elements are
 * processed in schema order. This is what you generally want for
 * rendering new data structure to a string. The wo pointers are not used. */

/* Called by: */
char* zx_ENC_SO_ac_IPAddress(struct zx_ctx* c, struct zx_ac_IPAddress_s* x, char* p )
{
  struct zx_elem_s* se MAYBE_UNUSED;
  ENC_LEN_DEBUG_BASE;
#if 1 /* NORMALMODE */
  struct zx_ns_s* pop_seen = 0;
  /* *** in simple_elem case should output ns prefix from ns node. */
  ZX_OUT_TAG(p, "<ac:IPAddress");
  if (c->inc_ns)
    p = zx_enc_inc_ns(c, p, &pop_seen);
  p = zx_enc_xmlns_if_not_seen(c, p, zx_ns_tab+zx_xmlns_ix_ac, &pop_seen);


  p = zx_enc_unknown_attrs(p, x->gg.any_attr);
#else
  /* root node has no begin tag */
#endif
  
  {
      struct zx_ac_Extension_s* e;
      for (e = x->Extension; e; e = (struct zx_ac_Extension_s*)e->gg.g.n)
	  p = zx_ENC_SO_ac_Extension(c, e, p);
  }

  p = zx_enc_so_unknown_elems_and_content(c, p, &x->gg);
  
#if 1 /* NORMALMODE */
  ZX_OUT_CLOSE_TAG(p, "</ac:IPAddress>");
  zx_pop_seen(pop_seen);
#else
  /* root node has no end tag either */
#endif
  ENC_LEN_DEBUG(x, "ac:IPAddress", p-enc_base);
  return p;
}

/* FUNC(zx_ENC_WO_ac_IPAddress) */

/* Render element into string. The XML attributes and elements are
 * processed in wire order by chasing wo pointers. This is what you want for
 * validating signatures on other people's XML documents. */

/* Called by: */
char* zx_ENC_WO_ac_IPAddress(struct zx_ctx* c, struct zx_ac_IPAddress_s* x, char* p )
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
  ZX_OUT_MEM(p, "IPAddress", sizeof("IPAddress")-1);
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
  ENC_LEN_DEBUG(x, "ac:IPAddress", p-enc_base);
  return p;
}

/* FUNC(zx_EASY_ENC_SO_ac_IPAddress) */

/* Called by: */
struct zx_str* zx_EASY_ENC_SO_ac_IPAddress(struct zx_ctx* c, struct zx_ac_IPAddress_s* x )
{
  int len;
  char* buf;
  c->ns_tab = ZX_ALLOC(c, sizeof(zx_ns_tab));
  memcpy(c->ns_tab, zx_ns_tab, sizeof(zx_ns_tab));
  len = zx_LEN_SO_ac_IPAddress(c, x );
  buf = ZX_ALLOC(c, len+1);
  return zx_easy_enc_common(c, zx_ENC_SO_ac_IPAddress(c, x, buf ), buf, len);
}

/* FUNC(zx_EASY_ENC_WO_ac_IPAddress) */

/* Called by: */
struct zx_str* zx_EASY_ENC_WO_ac_IPAddress(struct zx_ctx* c, struct zx_ac_IPAddress_s* x )
{
  int len;
  char* buf;
  c->ns_tab = ZX_ALLOC(c, sizeof(zx_ns_tab));
  memcpy(c->ns_tab, zx_ns_tab, sizeof(zx_ns_tab));
  len = zx_LEN_WO_ac_IPAddress(c, x );
  buf = ZX_ALLOC(c, len+1);
  return zx_easy_enc_common(c, zx_ENC_WO_ac_IPAddress(c, x, buf ), buf, len);
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

#define EL_NAME   ac_IPSec
#define EL_STRUCT zx_ac_IPSec_s
#define EL_NS     ac
#define EL_TAG    IPSec

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

/* FUNC(zx_LEN_SO_ac_IPSec) */

/* Compute length of an element (and its subelements). The XML attributes
 * and elements are processed in schema order. */

/* Called by: */
int zx_LEN_SO_ac_IPSec(struct zx_ctx* c, struct zx_ac_IPSec_s* x )
{
  struct zx_ns_s* pop_seen = 0;
  struct zx_elem_s* se MAYBE_UNUSED;
#if 1 /* NORMALMODE */
  /* *** in simple_elem case should output ns prefix from ns node. */
  int len = sizeof("<ac:IPSec")-1 + 1 + sizeof("</ac:IPSec>")-1;
  if (c->inc_ns_len)
    len += zx_len_inc_ns(c, &pop_seen);
  len += zx_len_xmlns_if_not_seen(c, zx_ns_tab+zx_xmlns_ix_ac, &pop_seen);


#else
  /* root node has no begin tag */
  int len = 0;
#endif
  
  {
      struct zx_ac_Extension_s* e;
      for (e = x->Extension; e; e = (struct zx_ac_Extension_s*)e->gg.g.n)
	  len += zx_LEN_SO_ac_Extension(c, e);
  }


  len += zx_len_so_common(c, &x->gg);
  zx_pop_seen(pop_seen);
  ENC_LEN_DEBUG(x, "ac:IPSec", len);
  return len;
}

/* FUNC(zx_LEN_WO_ac_IPSec) */

/* Compute length of an element (and its subelements). The XML attributes
 * and elements are processed in wire order and no assumptions
 * are made about namespace prefixes. */

/* Called by: */
int zx_LEN_WO_ac_IPSec(struct zx_ctx* c, struct zx_ac_IPSec_s* x )
{
  struct zx_ns_s* pop_seen = 0;
  struct zx_elem_s* se MAYBE_UNUSED;
#if 1 /* NORMALMODE */
  int len = 1 + sizeof("IPSec")-1 + 1 + 2 + sizeof("IPSec")-1 + 1;
  
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
      struct zx_ac_Extension_s* e;
      for (e = x->Extension; e; e = (struct zx_ac_Extension_s*)e->gg.g.n)
	  len += zx_LEN_WO_ac_Extension(c, e);
  }


  len += zx_len_wo_common(c, &x->gg); 
  zx_pop_seen(pop_seen);
  ENC_LEN_DEBUG(x, "ac:IPSec", len);
  return len;
}

/* FUNC(zx_ENC_SO_ac_IPSec) */

/* Render element into string. The XML attributes and elements are
 * processed in schema order. This is what you generally want for
 * rendering new data structure to a string. The wo pointers are not used. */

/* Called by: */
char* zx_ENC_SO_ac_IPSec(struct zx_ctx* c, struct zx_ac_IPSec_s* x, char* p )
{
  struct zx_elem_s* se MAYBE_UNUSED;
  ENC_LEN_DEBUG_BASE;
#if 1 /* NORMALMODE */
  struct zx_ns_s* pop_seen = 0;
  /* *** in simple_elem case should output ns prefix from ns node. */
  ZX_OUT_TAG(p, "<ac:IPSec");
  if (c->inc_ns)
    p = zx_enc_inc_ns(c, p, &pop_seen);
  p = zx_enc_xmlns_if_not_seen(c, p, zx_ns_tab+zx_xmlns_ix_ac, &pop_seen);


  p = zx_enc_unknown_attrs(p, x->gg.any_attr);
#else
  /* root node has no begin tag */
#endif
  
  {
      struct zx_ac_Extension_s* e;
      for (e = x->Extension; e; e = (struct zx_ac_Extension_s*)e->gg.g.n)
	  p = zx_ENC_SO_ac_Extension(c, e, p);
  }

  p = zx_enc_so_unknown_elems_and_content(c, p, &x->gg);
  
#if 1 /* NORMALMODE */
  ZX_OUT_CLOSE_TAG(p, "</ac:IPSec>");
  zx_pop_seen(pop_seen);
#else
  /* root node has no end tag either */
#endif
  ENC_LEN_DEBUG(x, "ac:IPSec", p-enc_base);
  return p;
}

/* FUNC(zx_ENC_WO_ac_IPSec) */

/* Render element into string. The XML attributes and elements are
 * processed in wire order by chasing wo pointers. This is what you want for
 * validating signatures on other people's XML documents. */

/* Called by: */
char* zx_ENC_WO_ac_IPSec(struct zx_ctx* c, struct zx_ac_IPSec_s* x, char* p )
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
  ZX_OUT_MEM(p, "IPSec", sizeof("IPSec")-1);
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
  ENC_LEN_DEBUG(x, "ac:IPSec", p-enc_base);
  return p;
}

/* FUNC(zx_EASY_ENC_SO_ac_IPSec) */

/* Called by: */
struct zx_str* zx_EASY_ENC_SO_ac_IPSec(struct zx_ctx* c, struct zx_ac_IPSec_s* x )
{
  int len;
  char* buf;
  c->ns_tab = ZX_ALLOC(c, sizeof(zx_ns_tab));
  memcpy(c->ns_tab, zx_ns_tab, sizeof(zx_ns_tab));
  len = zx_LEN_SO_ac_IPSec(c, x );
  buf = ZX_ALLOC(c, len+1);
  return zx_easy_enc_common(c, zx_ENC_SO_ac_IPSec(c, x, buf ), buf, len);
}

/* FUNC(zx_EASY_ENC_WO_ac_IPSec) */

/* Called by: */
struct zx_str* zx_EASY_ENC_WO_ac_IPSec(struct zx_ctx* c, struct zx_ac_IPSec_s* x )
{
  int len;
  char* buf;
  c->ns_tab = ZX_ALLOC(c, sizeof(zx_ns_tab));
  memcpy(c->ns_tab, zx_ns_tab, sizeof(zx_ns_tab));
  len = zx_LEN_WO_ac_IPSec(c, x );
  buf = ZX_ALLOC(c, len+1);
  return zx_easy_enc_common(c, zx_ENC_WO_ac_IPSec(c, x, buf ), buf, len);
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

#define EL_NAME   ac_Identification
#define EL_STRUCT zx_ac_Identification_s
#define EL_NS     ac
#define EL_TAG    Identification

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

/* FUNC(zx_LEN_SO_ac_Identification) */

/* Compute length of an element (and its subelements). The XML attributes
 * and elements are processed in schema order. */

/* Called by: */
int zx_LEN_SO_ac_Identification(struct zx_ctx* c, struct zx_ac_Identification_s* x )
{
  struct zx_ns_s* pop_seen = 0;
  struct zx_elem_s* se MAYBE_UNUSED;
#if 1 /* NORMALMODE */
  /* *** in simple_elem case should output ns prefix from ns node. */
  int len = sizeof("<ac:Identification")-1 + 1 + sizeof("</ac:Identification>")-1;
  if (c->inc_ns_len)
    len += zx_len_inc_ns(c, &pop_seen);
  len += zx_len_xmlns_if_not_seen(c, zx_ns_tab+zx_xmlns_ix_ac, &pop_seen);

  len += zx_attr_so_len(x->nym, sizeof("nym")-1);

#else
  /* root node has no begin tag */
  int len = 0;
#endif
  
  {
      struct zx_ac_PhysicalVerification_s* e;
      for (e = x->PhysicalVerification; e; e = (struct zx_ac_PhysicalVerification_s*)e->gg.g.n)
	  len += zx_LEN_SO_ac_PhysicalVerification(c, e);
  }
  {
      struct zx_ac_WrittenConsent_s* e;
      for (e = x->WrittenConsent; e; e = (struct zx_ac_WrittenConsent_s*)e->gg.g.n)
	  len += zx_LEN_SO_ac_WrittenConsent(c, e);
  }
  {
      struct zx_ac_Extension_s* e;
      for (e = x->Extension; e; e = (struct zx_ac_Extension_s*)e->gg.g.n)
	  len += zx_LEN_SO_ac_Extension(c, e);
  }


  len += zx_len_so_common(c, &x->gg);
  zx_pop_seen(pop_seen);
  ENC_LEN_DEBUG(x, "ac:Identification", len);
  return len;
}

/* FUNC(zx_LEN_WO_ac_Identification) */

/* Compute length of an element (and its subelements). The XML attributes
 * and elements are processed in wire order and no assumptions
 * are made about namespace prefixes. */

/* Called by: */
int zx_LEN_WO_ac_Identification(struct zx_ctx* c, struct zx_ac_Identification_s* x )
{
  struct zx_ns_s* pop_seen = 0;
  struct zx_elem_s* se MAYBE_UNUSED;
#if 1 /* NORMALMODE */
  int len = 1 + sizeof("Identification")-1 + 1 + 2 + sizeof("Identification")-1 + 1;
  
  if (x->gg.g.ns && x->gg.g.ns->prefix_len)
    len += (x->gg.g.ns->prefix_len + 1) * 2;
  if (c->inc_ns_len)
    len += zx_len_inc_ns(c, &pop_seen);
  len += zx_len_xmlns_if_not_seen(c, x->gg.g.ns, &pop_seen);

  len += zx_attr_wo_len(x->nym, sizeof("nym")-1);

#else
  /* root node has no begin tag */
  int len = 0;
#endif
  
  {
      struct zx_ac_PhysicalVerification_s* e;
      for (e = x->PhysicalVerification; e; e = (struct zx_ac_PhysicalVerification_s*)e->gg.g.n)
	  len += zx_LEN_WO_ac_PhysicalVerification(c, e);
  }
  {
      struct zx_ac_WrittenConsent_s* e;
      for (e = x->WrittenConsent; e; e = (struct zx_ac_WrittenConsent_s*)e->gg.g.n)
	  len += zx_LEN_WO_ac_WrittenConsent(c, e);
  }
  {
      struct zx_ac_Extension_s* e;
      for (e = x->Extension; e; e = (struct zx_ac_Extension_s*)e->gg.g.n)
	  len += zx_LEN_WO_ac_Extension(c, e);
  }


  len += zx_len_wo_common(c, &x->gg); 
  zx_pop_seen(pop_seen);
  ENC_LEN_DEBUG(x, "ac:Identification", len);
  return len;
}

/* FUNC(zx_ENC_SO_ac_Identification) */

/* Render element into string. The XML attributes and elements are
 * processed in schema order. This is what you generally want for
 * rendering new data structure to a string. The wo pointers are not used. */

/* Called by: */
char* zx_ENC_SO_ac_Identification(struct zx_ctx* c, struct zx_ac_Identification_s* x, char* p )
{
  struct zx_elem_s* se MAYBE_UNUSED;
  ENC_LEN_DEBUG_BASE;
#if 1 /* NORMALMODE */
  struct zx_ns_s* pop_seen = 0;
  /* *** in simple_elem case should output ns prefix from ns node. */
  ZX_OUT_TAG(p, "<ac:Identification");
  if (c->inc_ns)
    p = zx_enc_inc_ns(c, p, &pop_seen);
  p = zx_enc_xmlns_if_not_seen(c, p, zx_ns_tab+zx_xmlns_ix_ac, &pop_seen);

  p = zx_attr_so_enc(p, x->nym, " nym=\"", sizeof(" nym=\"")-1);

  p = zx_enc_unknown_attrs(p, x->gg.any_attr);
#else
  /* root node has no begin tag */
#endif
  
  {
      struct zx_ac_PhysicalVerification_s* e;
      for (e = x->PhysicalVerification; e; e = (struct zx_ac_PhysicalVerification_s*)e->gg.g.n)
	  p = zx_ENC_SO_ac_PhysicalVerification(c, e, p);
  }
  {
      struct zx_ac_WrittenConsent_s* e;
      for (e = x->WrittenConsent; e; e = (struct zx_ac_WrittenConsent_s*)e->gg.g.n)
	  p = zx_ENC_SO_ac_WrittenConsent(c, e, p);
  }
  {
      struct zx_ac_Extension_s* e;
      for (e = x->Extension; e; e = (struct zx_ac_Extension_s*)e->gg.g.n)
	  p = zx_ENC_SO_ac_Extension(c, e, p);
  }

  p = zx_enc_so_unknown_elems_and_content(c, p, &x->gg);
  
#if 1 /* NORMALMODE */
  ZX_OUT_CLOSE_TAG(p, "</ac:Identification>");
  zx_pop_seen(pop_seen);
#else
  /* root node has no end tag either */
#endif
  ENC_LEN_DEBUG(x, "ac:Identification", p-enc_base);
  return p;
}

/* FUNC(zx_ENC_WO_ac_Identification) */

/* Render element into string. The XML attributes and elements are
 * processed in wire order by chasing wo pointers. This is what you want for
 * validating signatures on other people's XML documents. */

/* Called by: */
char* zx_ENC_WO_ac_Identification(struct zx_ctx* c, struct zx_ac_Identification_s* x, char* p )
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
  ZX_OUT_MEM(p, "Identification", sizeof("Identification")-1);
  qq = p;

  /* *** sort the namespaces */
  if (c->inc_ns)
    zx_add_inc_ns(c, &pop_seen);
  zx_add_xmlns_if_not_seen(c, x->gg.g.ns, &pop_seen);

  p = zx_enc_seen(p, pop_seen); 
  p = zx_attr_wo_enc(p, x->nym, "nym=\"", sizeof("nym=\"")-1);

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
  ENC_LEN_DEBUG(x, "ac:Identification", p-enc_base);
  return p;
}

/* FUNC(zx_EASY_ENC_SO_ac_Identification) */

/* Called by: */
struct zx_str* zx_EASY_ENC_SO_ac_Identification(struct zx_ctx* c, struct zx_ac_Identification_s* x )
{
  int len;
  char* buf;
  c->ns_tab = ZX_ALLOC(c, sizeof(zx_ns_tab));
  memcpy(c->ns_tab, zx_ns_tab, sizeof(zx_ns_tab));
  len = zx_LEN_SO_ac_Identification(c, x );
  buf = ZX_ALLOC(c, len+1);
  return zx_easy_enc_common(c, zx_ENC_SO_ac_Identification(c, x, buf ), buf, len);
}

/* FUNC(zx_EASY_ENC_WO_ac_Identification) */

/* Called by: */
struct zx_str* zx_EASY_ENC_WO_ac_Identification(struct zx_ctx* c, struct zx_ac_Identification_s* x )
{
  int len;
  char* buf;
  c->ns_tab = ZX_ALLOC(c, sizeof(zx_ns_tab));
  memcpy(c->ns_tab, zx_ns_tab, sizeof(zx_ns_tab));
  len = zx_LEN_WO_ac_Identification(c, x );
  buf = ZX_ALLOC(c, len+1);
  return zx_easy_enc_common(c, zx_ENC_WO_ac_Identification(c, x, buf ), buf, len);
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

#define EL_NAME   ac_KeyActivation
#define EL_STRUCT zx_ac_KeyActivation_s
#define EL_NS     ac
#define EL_TAG    KeyActivation

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

/* FUNC(zx_LEN_SO_ac_KeyActivation) */

/* Compute length of an element (and its subelements). The XML attributes
 * and elements are processed in schema order. */

/* Called by: */
int zx_LEN_SO_ac_KeyActivation(struct zx_ctx* c, struct zx_ac_KeyActivation_s* x )
{
  struct zx_ns_s* pop_seen = 0;
  struct zx_elem_s* se MAYBE_UNUSED;
#if 1 /* NORMALMODE */
  /* *** in simple_elem case should output ns prefix from ns node. */
  int len = sizeof("<ac:KeyActivation")-1 + 1 + sizeof("</ac:KeyActivation>")-1;
  if (c->inc_ns_len)
    len += zx_len_inc_ns(c, &pop_seen);
  len += zx_len_xmlns_if_not_seen(c, zx_ns_tab+zx_xmlns_ix_ac, &pop_seen);


#else
  /* root node has no begin tag */
  int len = 0;
#endif
  
  {
      struct zx_ac_ActivationPin_s* e;
      for (e = x->ActivationPin; e; e = (struct zx_ac_ActivationPin_s*)e->gg.g.n)
	  len += zx_LEN_SO_ac_ActivationPin(c, e);
  }
  {
      struct zx_ac_Extension_s* e;
      for (e = x->Extension; e; e = (struct zx_ac_Extension_s*)e->gg.g.n)
	  len += zx_LEN_SO_ac_Extension(c, e);
  }


  len += zx_len_so_common(c, &x->gg);
  zx_pop_seen(pop_seen);
  ENC_LEN_DEBUG(x, "ac:KeyActivation", len);
  return len;
}

/* FUNC(zx_LEN_WO_ac_KeyActivation) */

/* Compute length of an element (and its subelements). The XML attributes
 * and elements are processed in wire order and no assumptions
 * are made about namespace prefixes. */

/* Called by: */
int zx_LEN_WO_ac_KeyActivation(struct zx_ctx* c, struct zx_ac_KeyActivation_s* x )
{
  struct zx_ns_s* pop_seen = 0;
  struct zx_elem_s* se MAYBE_UNUSED;
#if 1 /* NORMALMODE */
  int len = 1 + sizeof("KeyActivation")-1 + 1 + 2 + sizeof("KeyActivation")-1 + 1;
  
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
      struct zx_ac_ActivationPin_s* e;
      for (e = x->ActivationPin; e; e = (struct zx_ac_ActivationPin_s*)e->gg.g.n)
	  len += zx_LEN_WO_ac_ActivationPin(c, e);
  }
  {
      struct zx_ac_Extension_s* e;
      for (e = x->Extension; e; e = (struct zx_ac_Extension_s*)e->gg.g.n)
	  len += zx_LEN_WO_ac_Extension(c, e);
  }


  len += zx_len_wo_common(c, &x->gg); 
  zx_pop_seen(pop_seen);
  ENC_LEN_DEBUG(x, "ac:KeyActivation", len);
  return len;
}

/* FUNC(zx_ENC_SO_ac_KeyActivation) */

/* Render element into string. The XML attributes and elements are
 * processed in schema order. This is what you generally want for
 * rendering new data structure to a string. The wo pointers are not used. */

/* Called by: */
char* zx_ENC_SO_ac_KeyActivation(struct zx_ctx* c, struct zx_ac_KeyActivation_s* x, char* p )
{
  struct zx_elem_s* se MAYBE_UNUSED;
  ENC_LEN_DEBUG_BASE;
#if 1 /* NORMALMODE */
  struct zx_ns_s* pop_seen = 0;
  /* *** in simple_elem case should output ns prefix from ns node. */
  ZX_OUT_TAG(p, "<ac:KeyActivation");
  if (c->inc_ns)
    p = zx_enc_inc_ns(c, p, &pop_seen);
  p = zx_enc_xmlns_if_not_seen(c, p, zx_ns_tab+zx_xmlns_ix_ac, &pop_seen);


  p = zx_enc_unknown_attrs(p, x->gg.any_attr);
#else
  /* root node has no begin tag */
#endif
  
  {
      struct zx_ac_ActivationPin_s* e;
      for (e = x->ActivationPin; e; e = (struct zx_ac_ActivationPin_s*)e->gg.g.n)
	  p = zx_ENC_SO_ac_ActivationPin(c, e, p);
  }
  {
      struct zx_ac_Extension_s* e;
      for (e = x->Extension; e; e = (struct zx_ac_Extension_s*)e->gg.g.n)
	  p = zx_ENC_SO_ac_Extension(c, e, p);
  }

  p = zx_enc_so_unknown_elems_and_content(c, p, &x->gg);
  
#if 1 /* NORMALMODE */
  ZX_OUT_CLOSE_TAG(p, "</ac:KeyActivation>");
  zx_pop_seen(pop_seen);
#else
  /* root node has no end tag either */
#endif
  ENC_LEN_DEBUG(x, "ac:KeyActivation", p-enc_base);
  return p;
}

/* FUNC(zx_ENC_WO_ac_KeyActivation) */

/* Render element into string. The XML attributes and elements are
 * processed in wire order by chasing wo pointers. This is what you want for
 * validating signatures on other people's XML documents. */

/* Called by: */
char* zx_ENC_WO_ac_KeyActivation(struct zx_ctx* c, struct zx_ac_KeyActivation_s* x, char* p )
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
  ZX_OUT_MEM(p, "KeyActivation", sizeof("KeyActivation")-1);
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
  ENC_LEN_DEBUG(x, "ac:KeyActivation", p-enc_base);
  return p;
}

/* FUNC(zx_EASY_ENC_SO_ac_KeyActivation) */

/* Called by: */
struct zx_str* zx_EASY_ENC_SO_ac_KeyActivation(struct zx_ctx* c, struct zx_ac_KeyActivation_s* x )
{
  int len;
  char* buf;
  c->ns_tab = ZX_ALLOC(c, sizeof(zx_ns_tab));
  memcpy(c->ns_tab, zx_ns_tab, sizeof(zx_ns_tab));
  len = zx_LEN_SO_ac_KeyActivation(c, x );
  buf = ZX_ALLOC(c, len+1);
  return zx_easy_enc_common(c, zx_ENC_SO_ac_KeyActivation(c, x, buf ), buf, len);
}

/* FUNC(zx_EASY_ENC_WO_ac_KeyActivation) */

/* Called by: */
struct zx_str* zx_EASY_ENC_WO_ac_KeyActivation(struct zx_ctx* c, struct zx_ac_KeyActivation_s* x )
{
  int len;
  char* buf;
  c->ns_tab = ZX_ALLOC(c, sizeof(zx_ns_tab));
  memcpy(c->ns_tab, zx_ns_tab, sizeof(zx_ns_tab));
  len = zx_LEN_WO_ac_KeyActivation(c, x );
  buf = ZX_ALLOC(c, len+1);
  return zx_easy_enc_common(c, zx_ENC_WO_ac_KeyActivation(c, x, buf ), buf, len);
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

#define EL_NAME   ac_KeySharing
#define EL_STRUCT zx_ac_KeySharing_s
#define EL_NS     ac
#define EL_TAG    KeySharing

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

/* FUNC(zx_LEN_SO_ac_KeySharing) */

/* Compute length of an element (and its subelements). The XML attributes
 * and elements are processed in schema order. */

/* Called by: */
int zx_LEN_SO_ac_KeySharing(struct zx_ctx* c, struct zx_ac_KeySharing_s* x )
{
  struct zx_ns_s* pop_seen = 0;
  struct zx_elem_s* se MAYBE_UNUSED;
#if 1 /* NORMALMODE */
  /* *** in simple_elem case should output ns prefix from ns node. */
  int len = sizeof("<ac:KeySharing")-1 + 1 + sizeof("</ac:KeySharing>")-1;
  if (c->inc_ns_len)
    len += zx_len_inc_ns(c, &pop_seen);
  len += zx_len_xmlns_if_not_seen(c, zx_ns_tab+zx_xmlns_ix_ac, &pop_seen);

  len += zx_attr_so_len(x->sharing, sizeof("sharing")-1);

#else
  /* root node has no begin tag */
  int len = 0;
#endif
  


  len += zx_len_so_common(c, &x->gg);
  zx_pop_seen(pop_seen);
  ENC_LEN_DEBUG(x, "ac:KeySharing", len);
  return len;
}

/* FUNC(zx_LEN_WO_ac_KeySharing) */

/* Compute length of an element (and its subelements). The XML attributes
 * and elements are processed in wire order and no assumptions
 * are made about namespace prefixes. */

/* Called by: */
int zx_LEN_WO_ac_KeySharing(struct zx_ctx* c, struct zx_ac_KeySharing_s* x )
{
  struct zx_ns_s* pop_seen = 0;
  struct zx_elem_s* se MAYBE_UNUSED;
#if 1 /* NORMALMODE */
  int len = 1 + sizeof("KeySharing")-1 + 1 + 2 + sizeof("KeySharing")-1 + 1;
  
  if (x->gg.g.ns && x->gg.g.ns->prefix_len)
    len += (x->gg.g.ns->prefix_len + 1) * 2;
  if (c->inc_ns_len)
    len += zx_len_inc_ns(c, &pop_seen);
  len += zx_len_xmlns_if_not_seen(c, x->gg.g.ns, &pop_seen);

  len += zx_attr_wo_len(x->sharing, sizeof("sharing")-1);

#else
  /* root node has no begin tag */
  int len = 0;
#endif
  


  len += zx_len_wo_common(c, &x->gg); 
  zx_pop_seen(pop_seen);
  ENC_LEN_DEBUG(x, "ac:KeySharing", len);
  return len;
}

/* FUNC(zx_ENC_SO_ac_KeySharing) */

/* Render element into string. The XML attributes and elements are
 * processed in schema order. This is what you generally want for
 * rendering new data structure to a string. The wo pointers are not used. */

/* Called by: */
char* zx_ENC_SO_ac_KeySharing(struct zx_ctx* c, struct zx_ac_KeySharing_s* x, char* p )
{
  struct zx_elem_s* se MAYBE_UNUSED;
  ENC_LEN_DEBUG_BASE;
#if 1 /* NORMALMODE */
  struct zx_ns_s* pop_seen = 0;
  /* *** in simple_elem case should output ns prefix from ns node. */
  ZX_OUT_TAG(p, "<ac:KeySharing");
  if (c->inc_ns)
    p = zx_enc_inc_ns(c, p, &pop_seen);
  p = zx_enc_xmlns_if_not_seen(c, p, zx_ns_tab+zx_xmlns_ix_ac, &pop_seen);

  p = zx_attr_so_enc(p, x->sharing, " sharing=\"", sizeof(" sharing=\"")-1);

  p = zx_enc_unknown_attrs(p, x->gg.any_attr);
#else
  /* root node has no begin tag */
#endif
  

  p = zx_enc_so_unknown_elems_and_content(c, p, &x->gg);
  
#if 1 /* NORMALMODE */
  ZX_OUT_CLOSE_TAG(p, "</ac:KeySharing>");
  zx_pop_seen(pop_seen);
#else
  /* root node has no end tag either */
#endif
  ENC_LEN_DEBUG(x, "ac:KeySharing", p-enc_base);
  return p;
}

/* FUNC(zx_ENC_WO_ac_KeySharing) */

/* Render element into string. The XML attributes and elements are
 * processed in wire order by chasing wo pointers. This is what you want for
 * validating signatures on other people's XML documents. */

/* Called by: */
char* zx_ENC_WO_ac_KeySharing(struct zx_ctx* c, struct zx_ac_KeySharing_s* x, char* p )
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
  ZX_OUT_MEM(p, "KeySharing", sizeof("KeySharing")-1);
  qq = p;

  /* *** sort the namespaces */
  if (c->inc_ns)
    zx_add_inc_ns(c, &pop_seen);
  zx_add_xmlns_if_not_seen(c, x->gg.g.ns, &pop_seen);

  p = zx_enc_seen(p, pop_seen); 
  p = zx_attr_wo_enc(p, x->sharing, "sharing=\"", sizeof("sharing=\"")-1);

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
  ENC_LEN_DEBUG(x, "ac:KeySharing", p-enc_base);
  return p;
}

/* FUNC(zx_EASY_ENC_SO_ac_KeySharing) */

/* Called by: */
struct zx_str* zx_EASY_ENC_SO_ac_KeySharing(struct zx_ctx* c, struct zx_ac_KeySharing_s* x )
{
  int len;
  char* buf;
  c->ns_tab = ZX_ALLOC(c, sizeof(zx_ns_tab));
  memcpy(c->ns_tab, zx_ns_tab, sizeof(zx_ns_tab));
  len = zx_LEN_SO_ac_KeySharing(c, x );
  buf = ZX_ALLOC(c, len+1);
  return zx_easy_enc_common(c, zx_ENC_SO_ac_KeySharing(c, x, buf ), buf, len);
}

/* FUNC(zx_EASY_ENC_WO_ac_KeySharing) */

/* Called by: */
struct zx_str* zx_EASY_ENC_WO_ac_KeySharing(struct zx_ctx* c, struct zx_ac_KeySharing_s* x )
{
  int len;
  char* buf;
  c->ns_tab = ZX_ALLOC(c, sizeof(zx_ns_tab));
  memcpy(c->ns_tab, zx_ns_tab, sizeof(zx_ns_tab));
  len = zx_LEN_WO_ac_KeySharing(c, x );
  buf = ZX_ALLOC(c, len+1);
  return zx_easy_enc_common(c, zx_ENC_WO_ac_KeySharing(c, x, buf ), buf, len);
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

#define EL_NAME   ac_KeyStorage
#define EL_STRUCT zx_ac_KeyStorage_s
#define EL_NS     ac
#define EL_TAG    KeyStorage

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

/* FUNC(zx_LEN_SO_ac_KeyStorage) */

/* Compute length of an element (and its subelements). The XML attributes
 * and elements are processed in schema order. */

/* Called by: */
int zx_LEN_SO_ac_KeyStorage(struct zx_ctx* c, struct zx_ac_KeyStorage_s* x )
{
  struct zx_ns_s* pop_seen = 0;
  struct zx_elem_s* se MAYBE_UNUSED;
#if 1 /* NORMALMODE */
  /* *** in simple_elem case should output ns prefix from ns node. */
  int len = sizeof("<ac:KeyStorage")-1 + 1 + sizeof("</ac:KeyStorage>")-1;
  if (c->inc_ns_len)
    len += zx_len_inc_ns(c, &pop_seen);
  len += zx_len_xmlns_if_not_seen(c, zx_ns_tab+zx_xmlns_ix_ac, &pop_seen);

  len += zx_attr_so_len(x->medium, sizeof("medium")-1);

#else
  /* root node has no begin tag */
  int len = 0;
#endif
  


  len += zx_len_so_common(c, &x->gg);
  zx_pop_seen(pop_seen);
  ENC_LEN_DEBUG(x, "ac:KeyStorage", len);
  return len;
}

/* FUNC(zx_LEN_WO_ac_KeyStorage) */

/* Compute length of an element (and its subelements). The XML attributes
 * and elements are processed in wire order and no assumptions
 * are made about namespace prefixes. */

/* Called by: */
int zx_LEN_WO_ac_KeyStorage(struct zx_ctx* c, struct zx_ac_KeyStorage_s* x )
{
  struct zx_ns_s* pop_seen = 0;
  struct zx_elem_s* se MAYBE_UNUSED;
#if 1 /* NORMALMODE */
  int len = 1 + sizeof("KeyStorage")-1 + 1 + 2 + sizeof("KeyStorage")-1 + 1;
  
  if (x->gg.g.ns && x->gg.g.ns->prefix_len)
    len += (x->gg.g.ns->prefix_len + 1) * 2;
  if (c->inc_ns_len)
    len += zx_len_inc_ns(c, &pop_seen);
  len += zx_len_xmlns_if_not_seen(c, x->gg.g.ns, &pop_seen);

  len += zx_attr_wo_len(x->medium, sizeof("medium")-1);

#else
  /* root node has no begin tag */
  int len = 0;
#endif
  


  len += zx_len_wo_common(c, &x->gg); 
  zx_pop_seen(pop_seen);
  ENC_LEN_DEBUG(x, "ac:KeyStorage", len);
  return len;
}

/* FUNC(zx_ENC_SO_ac_KeyStorage) */

/* Render element into string. The XML attributes and elements are
 * processed in schema order. This is what you generally want for
 * rendering new data structure to a string. The wo pointers are not used. */

/* Called by: */
char* zx_ENC_SO_ac_KeyStorage(struct zx_ctx* c, struct zx_ac_KeyStorage_s* x, char* p )
{
  struct zx_elem_s* se MAYBE_UNUSED;
  ENC_LEN_DEBUG_BASE;
#if 1 /* NORMALMODE */
  struct zx_ns_s* pop_seen = 0;
  /* *** in simple_elem case should output ns prefix from ns node. */
  ZX_OUT_TAG(p, "<ac:KeyStorage");
  if (c->inc_ns)
    p = zx_enc_inc_ns(c, p, &pop_seen);
  p = zx_enc_xmlns_if_not_seen(c, p, zx_ns_tab+zx_xmlns_ix_ac, &pop_seen);

  p = zx_attr_so_enc(p, x->medium, " medium=\"", sizeof(" medium=\"")-1);

  p = zx_enc_unknown_attrs(p, x->gg.any_attr);
#else
  /* root node has no begin tag */
#endif
  

  p = zx_enc_so_unknown_elems_and_content(c, p, &x->gg);
  
#if 1 /* NORMALMODE */
  ZX_OUT_CLOSE_TAG(p, "</ac:KeyStorage>");
  zx_pop_seen(pop_seen);
#else
  /* root node has no end tag either */
#endif
  ENC_LEN_DEBUG(x, "ac:KeyStorage", p-enc_base);
  return p;
}

/* FUNC(zx_ENC_WO_ac_KeyStorage) */

/* Render element into string. The XML attributes and elements are
 * processed in wire order by chasing wo pointers. This is what you want for
 * validating signatures on other people's XML documents. */

/* Called by: */
char* zx_ENC_WO_ac_KeyStorage(struct zx_ctx* c, struct zx_ac_KeyStorage_s* x, char* p )
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
  ZX_OUT_MEM(p, "KeyStorage", sizeof("KeyStorage")-1);
  qq = p;

  /* *** sort the namespaces */
  if (c->inc_ns)
    zx_add_inc_ns(c, &pop_seen);
  zx_add_xmlns_if_not_seen(c, x->gg.g.ns, &pop_seen);

  p = zx_enc_seen(p, pop_seen); 
  p = zx_attr_wo_enc(p, x->medium, "medium=\"", sizeof("medium=\"")-1);

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
  ENC_LEN_DEBUG(x, "ac:KeyStorage", p-enc_base);
  return p;
}

/* FUNC(zx_EASY_ENC_SO_ac_KeyStorage) */

/* Called by: */
struct zx_str* zx_EASY_ENC_SO_ac_KeyStorage(struct zx_ctx* c, struct zx_ac_KeyStorage_s* x )
{
  int len;
  char* buf;
  c->ns_tab = ZX_ALLOC(c, sizeof(zx_ns_tab));
  memcpy(c->ns_tab, zx_ns_tab, sizeof(zx_ns_tab));
  len = zx_LEN_SO_ac_KeyStorage(c, x );
  buf = ZX_ALLOC(c, len+1);
  return zx_easy_enc_common(c, zx_ENC_SO_ac_KeyStorage(c, x, buf ), buf, len);
}

/* FUNC(zx_EASY_ENC_WO_ac_KeyStorage) */

/* Called by: */
struct zx_str* zx_EASY_ENC_WO_ac_KeyStorage(struct zx_ctx* c, struct zx_ac_KeyStorage_s* x )
{
  int len;
  char* buf;
  c->ns_tab = ZX_ALLOC(c, sizeof(zx_ns_tab));
  memcpy(c->ns_tab, zx_ns_tab, sizeof(zx_ns_tab));
  len = zx_LEN_WO_ac_KeyStorage(c, x );
  buf = ZX_ALLOC(c, len+1);
  return zx_easy_enc_common(c, zx_ENC_WO_ac_KeyStorage(c, x, buf ), buf, len);
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

#define EL_NAME   ac_Length
#define EL_STRUCT zx_ac_Length_s
#define EL_NS     ac
#define EL_TAG    Length

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

/* FUNC(zx_LEN_SO_ac_Length) */

/* Compute length of an element (and its subelements). The XML attributes
 * and elements are processed in schema order. */

/* Called by: */
int zx_LEN_SO_ac_Length(struct zx_ctx* c, struct zx_ac_Length_s* x )
{
  struct zx_ns_s* pop_seen = 0;
  struct zx_elem_s* se MAYBE_UNUSED;
#if 1 /* NORMALMODE */
  /* *** in simple_elem case should output ns prefix from ns node. */
  int len = sizeof("<ac:Length")-1 + 1 + sizeof("</ac:Length>")-1;
  if (c->inc_ns_len)
    len += zx_len_inc_ns(c, &pop_seen);
  len += zx_len_xmlns_if_not_seen(c, zx_ns_tab+zx_xmlns_ix_ac, &pop_seen);

  len += zx_attr_so_len(x->max, sizeof("max")-1);
  len += zx_attr_so_len(x->min, sizeof("min")-1);

#else
  /* root node has no begin tag */
  int len = 0;
#endif
  


  len += zx_len_so_common(c, &x->gg);
  zx_pop_seen(pop_seen);
  ENC_LEN_DEBUG(x, "ac:Length", len);
  return len;
}

/* FUNC(zx_LEN_WO_ac_Length) */

/* Compute length of an element (and its subelements). The XML attributes
 * and elements are processed in wire order and no assumptions
 * are made about namespace prefixes. */

/* Called by: */
int zx_LEN_WO_ac_Length(struct zx_ctx* c, struct zx_ac_Length_s* x )
{
  struct zx_ns_s* pop_seen = 0;
  struct zx_elem_s* se MAYBE_UNUSED;
#if 1 /* NORMALMODE */
  int len = 1 + sizeof("Length")-1 + 1 + 2 + sizeof("Length")-1 + 1;
  
  if (x->gg.g.ns && x->gg.g.ns->prefix_len)
    len += (x->gg.g.ns->prefix_len + 1) * 2;
  if (c->inc_ns_len)
    len += zx_len_inc_ns(c, &pop_seen);
  len += zx_len_xmlns_if_not_seen(c, x->gg.g.ns, &pop_seen);

  len += zx_attr_wo_len(x->max, sizeof("max")-1);
  len += zx_attr_wo_len(x->min, sizeof("min")-1);

#else
  /* root node has no begin tag */
  int len = 0;
#endif
  


  len += zx_len_wo_common(c, &x->gg); 
  zx_pop_seen(pop_seen);
  ENC_LEN_DEBUG(x, "ac:Length", len);
  return len;
}

/* FUNC(zx_ENC_SO_ac_Length) */

/* Render element into string. The XML attributes and elements are
 * processed in schema order. This is what you generally want for
 * rendering new data structure to a string. The wo pointers are not used. */

/* Called by: */
char* zx_ENC_SO_ac_Length(struct zx_ctx* c, struct zx_ac_Length_s* x, char* p )
{
  struct zx_elem_s* se MAYBE_UNUSED;
  ENC_LEN_DEBUG_BASE;
#if 1 /* NORMALMODE */
  struct zx_ns_s* pop_seen = 0;
  /* *** in simple_elem case should output ns prefix from ns node. */
  ZX_OUT_TAG(p, "<ac:Length");
  if (c->inc_ns)
    p = zx_enc_inc_ns(c, p, &pop_seen);
  p = zx_enc_xmlns_if_not_seen(c, p, zx_ns_tab+zx_xmlns_ix_ac, &pop_seen);

  p = zx_attr_so_enc(p, x->max, " max=\"", sizeof(" max=\"")-1);
  p = zx_attr_so_enc(p, x->min, " min=\"", sizeof(" min=\"")-1);

  p = zx_enc_unknown_attrs(p, x->gg.any_attr);
#else
  /* root node has no begin tag */
#endif
  

  p = zx_enc_so_unknown_elems_and_content(c, p, &x->gg);
  
#if 1 /* NORMALMODE */
  ZX_OUT_CLOSE_TAG(p, "</ac:Length>");
  zx_pop_seen(pop_seen);
#else
  /* root node has no end tag either */
#endif
  ENC_LEN_DEBUG(x, "ac:Length", p-enc_base);
  return p;
}

/* FUNC(zx_ENC_WO_ac_Length) */

/* Render element into string. The XML attributes and elements are
 * processed in wire order by chasing wo pointers. This is what you want for
 * validating signatures on other people's XML documents. */

/* Called by: */
char* zx_ENC_WO_ac_Length(struct zx_ctx* c, struct zx_ac_Length_s* x, char* p )
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
  ZX_OUT_MEM(p, "Length", sizeof("Length")-1);
  qq = p;

  /* *** sort the namespaces */
  if (c->inc_ns)
    zx_add_inc_ns(c, &pop_seen);
  zx_add_xmlns_if_not_seen(c, x->gg.g.ns, &pop_seen);

  p = zx_enc_seen(p, pop_seen); 
  p = zx_attr_wo_enc(p, x->max, "max=\"", sizeof("max=\"")-1);
  p = zx_attr_wo_enc(p, x->min, "min=\"", sizeof("min=\"")-1);

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
  ENC_LEN_DEBUG(x, "ac:Length", p-enc_base);
  return p;
}

/* FUNC(zx_EASY_ENC_SO_ac_Length) */

/* Called by: */
struct zx_str* zx_EASY_ENC_SO_ac_Length(struct zx_ctx* c, struct zx_ac_Length_s* x )
{
  int len;
  char* buf;
  c->ns_tab = ZX_ALLOC(c, sizeof(zx_ns_tab));
  memcpy(c->ns_tab, zx_ns_tab, sizeof(zx_ns_tab));
  len = zx_LEN_SO_ac_Length(c, x );
  buf = ZX_ALLOC(c, len+1);
  return zx_easy_enc_common(c, zx_ENC_SO_ac_Length(c, x, buf ), buf, len);
}

/* FUNC(zx_EASY_ENC_WO_ac_Length) */

/* Called by: */
struct zx_str* zx_EASY_ENC_WO_ac_Length(struct zx_ctx* c, struct zx_ac_Length_s* x )
{
  int len;
  char* buf;
  c->ns_tab = ZX_ALLOC(c, sizeof(zx_ns_tab));
  memcpy(c->ns_tab, zx_ns_tab, sizeof(zx_ns_tab));
  len = zx_LEN_WO_ac_Length(c, x );
  buf = ZX_ALLOC(c, len+1);
  return zx_easy_enc_common(c, zx_ENC_WO_ac_Length(c, x, buf ), buf, len);
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

#define EL_NAME   ac_MobileNetworkEndToEndEncryption
#define EL_STRUCT zx_ac_MobileNetworkEndToEndEncryption_s
#define EL_NS     ac
#define EL_TAG    MobileNetworkEndToEndEncryption

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

/* FUNC(zx_LEN_SO_ac_MobileNetworkEndToEndEncryption) */

/* Compute length of an element (and its subelements). The XML attributes
 * and elements are processed in schema order. */

/* Called by: */
int zx_LEN_SO_ac_MobileNetworkEndToEndEncryption(struct zx_ctx* c, struct zx_ac_MobileNetworkEndToEndEncryption_s* x )
{
  struct zx_ns_s* pop_seen = 0;
  struct zx_elem_s* se MAYBE_UNUSED;
#if 1 /* NORMALMODE */
  /* *** in simple_elem case should output ns prefix from ns node. */
  int len = sizeof("<ac:MobileNetworkEndToEndEncryption")-1 + 1 + sizeof("</ac:MobileNetworkEndToEndEncryption>")-1;
  if (c->inc_ns_len)
    len += zx_len_inc_ns(c, &pop_seen);
  len += zx_len_xmlns_if_not_seen(c, zx_ns_tab+zx_xmlns_ix_ac, &pop_seen);


#else
  /* root node has no begin tag */
  int len = 0;
#endif
  
  {
      struct zx_ac_Extension_s* e;
      for (e = x->Extension; e; e = (struct zx_ac_Extension_s*)e->gg.g.n)
	  len += zx_LEN_SO_ac_Extension(c, e);
  }


  len += zx_len_so_common(c, &x->gg);
  zx_pop_seen(pop_seen);
  ENC_LEN_DEBUG(x, "ac:MobileNetworkEndToEndEncryption", len);
  return len;
}

/* FUNC(zx_LEN_WO_ac_MobileNetworkEndToEndEncryption) */

/* Compute length of an element (and its subelements). The XML attributes
 * and elements are processed in wire order and no assumptions
 * are made about namespace prefixes. */

/* Called by: */
int zx_LEN_WO_ac_MobileNetworkEndToEndEncryption(struct zx_ctx* c, struct zx_ac_MobileNetworkEndToEndEncryption_s* x )
{
  struct zx_ns_s* pop_seen = 0;
  struct zx_elem_s* se MAYBE_UNUSED;
#if 1 /* NORMALMODE */
  int len = 1 + sizeof("MobileNetworkEndToEndEncryption")-1 + 1 + 2 + sizeof("MobileNetworkEndToEndEncryption")-1 + 1;
  
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
      struct zx_ac_Extension_s* e;
      for (e = x->Extension; e; e = (struct zx_ac_Extension_s*)e->gg.g.n)
	  len += zx_LEN_WO_ac_Extension(c, e);
  }


  len += zx_len_wo_common(c, &x->gg); 
  zx_pop_seen(pop_seen);
  ENC_LEN_DEBUG(x, "ac:MobileNetworkEndToEndEncryption", len);
  return len;
}

/* FUNC(zx_ENC_SO_ac_MobileNetworkEndToEndEncryption) */

/* Render element into string. The XML attributes and elements are
 * processed in schema order. This is what you generally want for
 * rendering new data structure to a string. The wo pointers are not used. */

/* Called by: */
char* zx_ENC_SO_ac_MobileNetworkEndToEndEncryption(struct zx_ctx* c, struct zx_ac_MobileNetworkEndToEndEncryption_s* x, char* p )
{
  struct zx_elem_s* se MAYBE_UNUSED;
  ENC_LEN_DEBUG_BASE;
#if 1 /* NORMALMODE */
  struct zx_ns_s* pop_seen = 0;
  /* *** in simple_elem case should output ns prefix from ns node. */
  ZX_OUT_TAG(p, "<ac:MobileNetworkEndToEndEncryption");
  if (c->inc_ns)
    p = zx_enc_inc_ns(c, p, &pop_seen);
  p = zx_enc_xmlns_if_not_seen(c, p, zx_ns_tab+zx_xmlns_ix_ac, &pop_seen);


  p = zx_enc_unknown_attrs(p, x->gg.any_attr);
#else
  /* root node has no begin tag */
#endif
  
  {
      struct zx_ac_Extension_s* e;
      for (e = x->Extension; e; e = (struct zx_ac_Extension_s*)e->gg.g.n)
	  p = zx_ENC_SO_ac_Extension(c, e, p);
  }

  p = zx_enc_so_unknown_elems_and_content(c, p, &x->gg);
  
#if 1 /* NORMALMODE */
  ZX_OUT_CLOSE_TAG(p, "</ac:MobileNetworkEndToEndEncryption>");
  zx_pop_seen(pop_seen);
#else
  /* root node has no end tag either */
#endif
  ENC_LEN_DEBUG(x, "ac:MobileNetworkEndToEndEncryption", p-enc_base);
  return p;
}

/* FUNC(zx_ENC_WO_ac_MobileNetworkEndToEndEncryption) */

/* Render element into string. The XML attributes and elements are
 * processed in wire order by chasing wo pointers. This is what you want for
 * validating signatures on other people's XML documents. */

/* Called by: */
char* zx_ENC_WO_ac_MobileNetworkEndToEndEncryption(struct zx_ctx* c, struct zx_ac_MobileNetworkEndToEndEncryption_s* x, char* p )
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
  ZX_OUT_MEM(p, "MobileNetworkEndToEndEncryption", sizeof("MobileNetworkEndToEndEncryption")-1);
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
  ENC_LEN_DEBUG(x, "ac:MobileNetworkEndToEndEncryption", p-enc_base);
  return p;
}

/* FUNC(zx_EASY_ENC_SO_ac_MobileNetworkEndToEndEncryption) */

/* Called by: */
struct zx_str* zx_EASY_ENC_SO_ac_MobileNetworkEndToEndEncryption(struct zx_ctx* c, struct zx_ac_MobileNetworkEndToEndEncryption_s* x )
{
  int len;
  char* buf;
  c->ns_tab = ZX_ALLOC(c, sizeof(zx_ns_tab));
  memcpy(c->ns_tab, zx_ns_tab, sizeof(zx_ns_tab));
  len = zx_LEN_SO_ac_MobileNetworkEndToEndEncryption(c, x );
  buf = ZX_ALLOC(c, len+1);
  return zx_easy_enc_common(c, zx_ENC_SO_ac_MobileNetworkEndToEndEncryption(c, x, buf ), buf, len);
}

/* FUNC(zx_EASY_ENC_WO_ac_MobileNetworkEndToEndEncryption) */

/* Called by: */
struct zx_str* zx_EASY_ENC_WO_ac_MobileNetworkEndToEndEncryption(struct zx_ctx* c, struct zx_ac_MobileNetworkEndToEndEncryption_s* x )
{
  int len;
  char* buf;
  c->ns_tab = ZX_ALLOC(c, sizeof(zx_ns_tab));
  memcpy(c->ns_tab, zx_ns_tab, sizeof(zx_ns_tab));
  len = zx_LEN_WO_ac_MobileNetworkEndToEndEncryption(c, x );
  buf = ZX_ALLOC(c, len+1);
  return zx_easy_enc_common(c, zx_ENC_WO_ac_MobileNetworkEndToEndEncryption(c, x, buf ), buf, len);
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

#define EL_NAME   ac_MobileNetworkNoEncryption
#define EL_STRUCT zx_ac_MobileNetworkNoEncryption_s
#define EL_NS     ac
#define EL_TAG    MobileNetworkNoEncryption

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

/* FUNC(zx_LEN_SO_ac_MobileNetworkNoEncryption) */

/* Compute length of an element (and its subelements). The XML attributes
 * and elements are processed in schema order. */

/* Called by: */
int zx_LEN_SO_ac_MobileNetworkNoEncryption(struct zx_ctx* c, struct zx_ac_MobileNetworkNoEncryption_s* x )
{
  struct zx_ns_s* pop_seen = 0;
  struct zx_elem_s* se MAYBE_UNUSED;
#if 1 /* NORMALMODE */
  /* *** in simple_elem case should output ns prefix from ns node. */
  int len = sizeof("<ac:MobileNetworkNoEncryption")-1 + 1 + sizeof("</ac:MobileNetworkNoEncryption>")-1;
  if (c->inc_ns_len)
    len += zx_len_inc_ns(c, &pop_seen);
  len += zx_len_xmlns_if_not_seen(c, zx_ns_tab+zx_xmlns_ix_ac, &pop_seen);


#else
  /* root node has no begin tag */
  int len = 0;
#endif
  
  {
      struct zx_ac_Extension_s* e;
      for (e = x->Extension; e; e = (struct zx_ac_Extension_s*)e->gg.g.n)
	  len += zx_LEN_SO_ac_Extension(c, e);
  }


  len += zx_len_so_common(c, &x->gg);
  zx_pop_seen(pop_seen);
  ENC_LEN_DEBUG(x, "ac:MobileNetworkNoEncryption", len);
  return len;
}

/* FUNC(zx_LEN_WO_ac_MobileNetworkNoEncryption) */

/* Compute length of an element (and its subelements). The XML attributes
 * and elements are processed in wire order and no assumptions
 * are made about namespace prefixes. */

/* Called by: */
int zx_LEN_WO_ac_MobileNetworkNoEncryption(struct zx_ctx* c, struct zx_ac_MobileNetworkNoEncryption_s* x )
{
  struct zx_ns_s* pop_seen = 0;
  struct zx_elem_s* se MAYBE_UNUSED;
#if 1 /* NORMALMODE */
  int len = 1 + sizeof("MobileNetworkNoEncryption")-1 + 1 + 2 + sizeof("MobileNetworkNoEncryption")-1 + 1;
  
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
      struct zx_ac_Extension_s* e;
      for (e = x->Extension; e; e = (struct zx_ac_Extension_s*)e->gg.g.n)
	  len += zx_LEN_WO_ac_Extension(c, e);
  }


  len += zx_len_wo_common(c, &x->gg); 
  zx_pop_seen(pop_seen);
  ENC_LEN_DEBUG(x, "ac:MobileNetworkNoEncryption", len);
  return len;
}

/* FUNC(zx_ENC_SO_ac_MobileNetworkNoEncryption) */

/* Render element into string. The XML attributes and elements are
 * processed in schema order. This is what you generally want for
 * rendering new data structure to a string. The wo pointers are not used. */

/* Called by: */
char* zx_ENC_SO_ac_MobileNetworkNoEncryption(struct zx_ctx* c, struct zx_ac_MobileNetworkNoEncryption_s* x, char* p )
{
  struct zx_elem_s* se MAYBE_UNUSED;
  ENC_LEN_DEBUG_BASE;
#if 1 /* NORMALMODE */
  struct zx_ns_s* pop_seen = 0;
  /* *** in simple_elem case should output ns prefix from ns node. */
  ZX_OUT_TAG(p, "<ac:MobileNetworkNoEncryption");
  if (c->inc_ns)
    p = zx_enc_inc_ns(c, p, &pop_seen);
  p = zx_enc_xmlns_if_not_seen(c, p, zx_ns_tab+zx_xmlns_ix_ac, &pop_seen);


  p = zx_enc_unknown_attrs(p, x->gg.any_attr);
#else
  /* root node has no begin tag */
#endif
  
  {
      struct zx_ac_Extension_s* e;
      for (e = x->Extension; e; e = (struct zx_ac_Extension_s*)e->gg.g.n)
	  p = zx_ENC_SO_ac_Extension(c, e, p);
  }

  p = zx_enc_so_unknown_elems_and_content(c, p, &x->gg);
  
#if 1 /* NORMALMODE */
  ZX_OUT_CLOSE_TAG(p, "</ac:MobileNetworkNoEncryption>");
  zx_pop_seen(pop_seen);
#else
  /* root node has no end tag either */
#endif
  ENC_LEN_DEBUG(x, "ac:MobileNetworkNoEncryption", p-enc_base);
  return p;
}

/* FUNC(zx_ENC_WO_ac_MobileNetworkNoEncryption) */

/* Render element into string. The XML attributes and elements are
 * processed in wire order by chasing wo pointers. This is what you want for
 * validating signatures on other people's XML documents. */

/* Called by: */
char* zx_ENC_WO_ac_MobileNetworkNoEncryption(struct zx_ctx* c, struct zx_ac_MobileNetworkNoEncryption_s* x, char* p )
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
  ZX_OUT_MEM(p, "MobileNetworkNoEncryption", sizeof("MobileNetworkNoEncryption")-1);
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
  ENC_LEN_DEBUG(x, "ac:MobileNetworkNoEncryption", p-enc_base);
  return p;
}

/* FUNC(zx_EASY_ENC_SO_ac_MobileNetworkNoEncryption) */

/* Called by: */
struct zx_str* zx_EASY_ENC_SO_ac_MobileNetworkNoEncryption(struct zx_ctx* c, struct zx_ac_MobileNetworkNoEncryption_s* x )
{
  int len;
  char* buf;
  c->ns_tab = ZX_ALLOC(c, sizeof(zx_ns_tab));
  memcpy(c->ns_tab, zx_ns_tab, sizeof(zx_ns_tab));
  len = zx_LEN_SO_ac_MobileNetworkNoEncryption(c, x );
  buf = ZX_ALLOC(c, len+1);
  return zx_easy_enc_common(c, zx_ENC_SO_ac_MobileNetworkNoEncryption(c, x, buf ), buf, len);
}

/* FUNC(zx_EASY_ENC_WO_ac_MobileNetworkNoEncryption) */

/* Called by: */
struct zx_str* zx_EASY_ENC_WO_ac_MobileNetworkNoEncryption(struct zx_ctx* c, struct zx_ac_MobileNetworkNoEncryption_s* x )
{
  int len;
  char* buf;
  c->ns_tab = ZX_ALLOC(c, sizeof(zx_ns_tab));
  memcpy(c->ns_tab, zx_ns_tab, sizeof(zx_ns_tab));
  len = zx_LEN_WO_ac_MobileNetworkNoEncryption(c, x );
  buf = ZX_ALLOC(c, len+1);
  return zx_easy_enc_common(c, zx_ENC_WO_ac_MobileNetworkNoEncryption(c, x, buf ), buf, len);
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

#define EL_NAME   ac_MobileNetworkRadioEncryption
#define EL_STRUCT zx_ac_MobileNetworkRadioEncryption_s
#define EL_NS     ac
#define EL_TAG    MobileNetworkRadioEncryption

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

/* FUNC(zx_LEN_SO_ac_MobileNetworkRadioEncryption) */

/* Compute length of an element (and its subelements). The XML attributes
 * and elements are processed in schema order. */

/* Called by: */
int zx_LEN_SO_ac_MobileNetworkRadioEncryption(struct zx_ctx* c, struct zx_ac_MobileNetworkRadioEncryption_s* x )
{
  struct zx_ns_s* pop_seen = 0;
  struct zx_elem_s* se MAYBE_UNUSED;
#if 1 /* NORMALMODE */
  /* *** in simple_elem case should output ns prefix from ns node. */
  int len = sizeof("<ac:MobileNetworkRadioEncryption")-1 + 1 + sizeof("</ac:MobileNetworkRadioEncryption>")-1;
  if (c->inc_ns_len)
    len += zx_len_inc_ns(c, &pop_seen);
  len += zx_len_xmlns_if_not_seen(c, zx_ns_tab+zx_xmlns_ix_ac, &pop_seen);


#else
  /* root node has no begin tag */
  int len = 0;
#endif
  
  {
      struct zx_ac_Extension_s* e;
      for (e = x->Extension; e; e = (struct zx_ac_Extension_s*)e->gg.g.n)
	  len += zx_LEN_SO_ac_Extension(c, e);
  }


  len += zx_len_so_common(c, &x->gg);
  zx_pop_seen(pop_seen);
  ENC_LEN_DEBUG(x, "ac:MobileNetworkRadioEncryption", len);
  return len;
}

/* FUNC(zx_LEN_WO_ac_MobileNetworkRadioEncryption) */

/* Compute length of an element (and its subelements). The XML attributes
 * and elements are processed in wire order and no assumptions
 * are made about namespace prefixes. */

/* Called by: */
int zx_LEN_WO_ac_MobileNetworkRadioEncryption(struct zx_ctx* c, struct zx_ac_MobileNetworkRadioEncryption_s* x )
{
  struct zx_ns_s* pop_seen = 0;
  struct zx_elem_s* se MAYBE_UNUSED;
#if 1 /* NORMALMODE */
  int len = 1 + sizeof("MobileNetworkRadioEncryption")-1 + 1 + 2 + sizeof("MobileNetworkRadioEncryption")-1 + 1;
  
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
      struct zx_ac_Extension_s* e;
      for (e = x->Extension; e; e = (struct zx_ac_Extension_s*)e->gg.g.n)
	  len += zx_LEN_WO_ac_Extension(c, e);
  }


  len += zx_len_wo_common(c, &x->gg); 
  zx_pop_seen(pop_seen);
  ENC_LEN_DEBUG(x, "ac:MobileNetworkRadioEncryption", len);
  return len;
}

/* FUNC(zx_ENC_SO_ac_MobileNetworkRadioEncryption) */

/* Render element into string. The XML attributes and elements are
 * processed in schema order. This is what you generally want for
 * rendering new data structure to a string. The wo pointers are not used. */

/* Called by: */
char* zx_ENC_SO_ac_MobileNetworkRadioEncryption(struct zx_ctx* c, struct zx_ac_MobileNetworkRadioEncryption_s* x, char* p )
{
  struct zx_elem_s* se MAYBE_UNUSED;
  ENC_LEN_DEBUG_BASE;
#if 1 /* NORMALMODE */
  struct zx_ns_s* pop_seen = 0;
  /* *** in simple_elem case should output ns prefix from ns node. */
  ZX_OUT_TAG(p, "<ac:MobileNetworkRadioEncryption");
  if (c->inc_ns)
    p = zx_enc_inc_ns(c, p, &pop_seen);
  p = zx_enc_xmlns_if_not_seen(c, p, zx_ns_tab+zx_xmlns_ix_ac, &pop_seen);


  p = zx_enc_unknown_attrs(p, x->gg.any_attr);
#else
  /* root node has no begin tag */
#endif
  
  {
      struct zx_ac_Extension_s* e;
      for (e = x->Extension; e; e = (struct zx_ac_Extension_s*)e->gg.g.n)
	  p = zx_ENC_SO_ac_Extension(c, e, p);
  }

  p = zx_enc_so_unknown_elems_and_content(c, p, &x->gg);
  
#if 1 /* NORMALMODE */
  ZX_OUT_CLOSE_TAG(p, "</ac:MobileNetworkRadioEncryption>");
  zx_pop_seen(pop_seen);
#else
  /* root node has no end tag either */
#endif
  ENC_LEN_DEBUG(x, "ac:MobileNetworkRadioEncryption", p-enc_base);
  return p;
}

/* FUNC(zx_ENC_WO_ac_MobileNetworkRadioEncryption) */

/* Render element into string. The XML attributes and elements are
 * processed in wire order by chasing wo pointers. This is what you want for
 * validating signatures on other people's XML documents. */

/* Called by: */
char* zx_ENC_WO_ac_MobileNetworkRadioEncryption(struct zx_ctx* c, struct zx_ac_MobileNetworkRadioEncryption_s* x, char* p )
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
  ZX_OUT_MEM(p, "MobileNetworkRadioEncryption", sizeof("MobileNetworkRadioEncryption")-1);
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
  ENC_LEN_DEBUG(x, "ac:MobileNetworkRadioEncryption", p-enc_base);
  return p;
}

/* FUNC(zx_EASY_ENC_SO_ac_MobileNetworkRadioEncryption) */

/* Called by: */
struct zx_str* zx_EASY_ENC_SO_ac_MobileNetworkRadioEncryption(struct zx_ctx* c, struct zx_ac_MobileNetworkRadioEncryption_s* x )
{
  int len;
  char* buf;
  c->ns_tab = ZX_ALLOC(c, sizeof(zx_ns_tab));
  memcpy(c->ns_tab, zx_ns_tab, sizeof(zx_ns_tab));
  len = zx_LEN_SO_ac_MobileNetworkRadioEncryption(c, x );
  buf = ZX_ALLOC(c, len+1);
  return zx_easy_enc_common(c, zx_ENC_SO_ac_MobileNetworkRadioEncryption(c, x, buf ), buf, len);
}

/* FUNC(zx_EASY_ENC_WO_ac_MobileNetworkRadioEncryption) */

/* Called by: */
struct zx_str* zx_EASY_ENC_WO_ac_MobileNetworkRadioEncryption(struct zx_ctx* c, struct zx_ac_MobileNetworkRadioEncryption_s* x )
{
  int len;
  char* buf;
  c->ns_tab = ZX_ALLOC(c, sizeof(zx_ns_tab));
  memcpy(c->ns_tab, zx_ns_tab, sizeof(zx_ns_tab));
  len = zx_LEN_WO_ac_MobileNetworkRadioEncryption(c, x );
  buf = ZX_ALLOC(c, len+1);
  return zx_easy_enc_common(c, zx_ENC_WO_ac_MobileNetworkRadioEncryption(c, x, buf ), buf, len);
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

#define EL_NAME   ac_OperationalProtection
#define EL_STRUCT zx_ac_OperationalProtection_s
#define EL_NS     ac
#define EL_TAG    OperationalProtection

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

/* FUNC(zx_LEN_SO_ac_OperationalProtection) */

/* Compute length of an element (and its subelements). The XML attributes
 * and elements are processed in schema order. */

/* Called by: */
int zx_LEN_SO_ac_OperationalProtection(struct zx_ctx* c, struct zx_ac_OperationalProtection_s* x )
{
  struct zx_ns_s* pop_seen = 0;
  struct zx_elem_s* se MAYBE_UNUSED;
#if 1 /* NORMALMODE */
  /* *** in simple_elem case should output ns prefix from ns node. */
  int len = sizeof("<ac:OperationalProtection")-1 + 1 + sizeof("</ac:OperationalProtection>")-1;
  if (c->inc_ns_len)
    len += zx_len_inc_ns(c, &pop_seen);
  len += zx_len_xmlns_if_not_seen(c, zx_ns_tab+zx_xmlns_ix_ac, &pop_seen);


#else
  /* root node has no begin tag */
  int len = 0;
#endif
  
  {
      struct zx_ac_SecurityAudit_s* e;
      for (e = x->SecurityAudit; e; e = (struct zx_ac_SecurityAudit_s*)e->gg.g.n)
	  len += zx_LEN_SO_ac_SecurityAudit(c, e);
  }
  {
      struct zx_ac_DeactivationCallCenter_s* e;
      for (e = x->DeactivationCallCenter; e; e = (struct zx_ac_DeactivationCallCenter_s*)e->gg.g.n)
	  len += zx_LEN_SO_ac_DeactivationCallCenter(c, e);
  }
  {
      struct zx_ac_Extension_s* e;
      for (e = x->Extension; e; e = (struct zx_ac_Extension_s*)e->gg.g.n)
	  len += zx_LEN_SO_ac_Extension(c, e);
  }


  len += zx_len_so_common(c, &x->gg);
  zx_pop_seen(pop_seen);
  ENC_LEN_DEBUG(x, "ac:OperationalProtection", len);
  return len;
}

/* FUNC(zx_LEN_WO_ac_OperationalProtection) */

/* Compute length of an element (and its subelements). The XML attributes
 * and elements are processed in wire order and no assumptions
 * are made about namespace prefixes. */

/* Called by: */
int zx_LEN_WO_ac_OperationalProtection(struct zx_ctx* c, struct zx_ac_OperationalProtection_s* x )
{
  struct zx_ns_s* pop_seen = 0;
  struct zx_elem_s* se MAYBE_UNUSED;
#if 1 /* NORMALMODE */
  int len = 1 + sizeof("OperationalProtection")-1 + 1 + 2 + sizeof("OperationalProtection")-1 + 1;
  
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
      struct zx_ac_SecurityAudit_s* e;
      for (e = x->SecurityAudit; e; e = (struct zx_ac_SecurityAudit_s*)e->gg.g.n)
	  len += zx_LEN_WO_ac_SecurityAudit(c, e);
  }
  {
      struct zx_ac_DeactivationCallCenter_s* e;
      for (e = x->DeactivationCallCenter; e; e = (struct zx_ac_DeactivationCallCenter_s*)e->gg.g.n)
	  len += zx_LEN_WO_ac_DeactivationCallCenter(c, e);
  }
  {
      struct zx_ac_Extension_s* e;
      for (e = x->Extension; e; e = (struct zx_ac_Extension_s*)e->gg.g.n)
	  len += zx_LEN_WO_ac_Extension(c, e);
  }


  len += zx_len_wo_common(c, &x->gg); 
  zx_pop_seen(pop_seen);
  ENC_LEN_DEBUG(x, "ac:OperationalProtection", len);
  return len;
}

/* FUNC(zx_ENC_SO_ac_OperationalProtection) */

/* Render element into string. The XML attributes and elements are
 * processed in schema order. This is what you generally want for
 * rendering new data structure to a string. The wo pointers are not used. */

/* Called by: */
char* zx_ENC_SO_ac_OperationalProtection(struct zx_ctx* c, struct zx_ac_OperationalProtection_s* x, char* p )
{
  struct zx_elem_s* se MAYBE_UNUSED;
  ENC_LEN_DEBUG_BASE;
#if 1 /* NORMALMODE */
  struct zx_ns_s* pop_seen = 0;
  /* *** in simple_elem case should output ns prefix from ns node. */
  ZX_OUT_TAG(p, "<ac:OperationalProtection");
  if (c->inc_ns)
    p = zx_enc_inc_ns(c, p, &pop_seen);
  p = zx_enc_xmlns_if_not_seen(c, p, zx_ns_tab+zx_xmlns_ix_ac, &pop_seen);


  p = zx_enc_unknown_attrs(p, x->gg.any_attr);
#else
  /* root node has no begin tag */
#endif
  
  {
      struct zx_ac_SecurityAudit_s* e;
      for (e = x->SecurityAudit; e; e = (struct zx_ac_SecurityAudit_s*)e->gg.g.n)
	  p = zx_ENC_SO_ac_SecurityAudit(c, e, p);
  }
  {
      struct zx_ac_DeactivationCallCenter_s* e;
      for (e = x->DeactivationCallCenter; e; e = (struct zx_ac_DeactivationCallCenter_s*)e->gg.g.n)
	  p = zx_ENC_SO_ac_DeactivationCallCenter(c, e, p);
  }
  {
      struct zx_ac_Extension_s* e;
      for (e = x->Extension; e; e = (struct zx_ac_Extension_s*)e->gg.g.n)
	  p = zx_ENC_SO_ac_Extension(c, e, p);
  }

  p = zx_enc_so_unknown_elems_and_content(c, p, &x->gg);
  
#if 1 /* NORMALMODE */
  ZX_OUT_CLOSE_TAG(p, "</ac:OperationalProtection>");
  zx_pop_seen(pop_seen);
#else
  /* root node has no end tag either */
#endif
  ENC_LEN_DEBUG(x, "ac:OperationalProtection", p-enc_base);
  return p;
}

/* FUNC(zx_ENC_WO_ac_OperationalProtection) */

/* Render element into string. The XML attributes and elements are
 * processed in wire order by chasing wo pointers. This is what you want for
 * validating signatures on other people's XML documents. */

/* Called by: */
char* zx_ENC_WO_ac_OperationalProtection(struct zx_ctx* c, struct zx_ac_OperationalProtection_s* x, char* p )
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
  ZX_OUT_MEM(p, "OperationalProtection", sizeof("OperationalProtection")-1);
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
  ENC_LEN_DEBUG(x, "ac:OperationalProtection", p-enc_base);
  return p;
}

/* FUNC(zx_EASY_ENC_SO_ac_OperationalProtection) */

/* Called by: */
struct zx_str* zx_EASY_ENC_SO_ac_OperationalProtection(struct zx_ctx* c, struct zx_ac_OperationalProtection_s* x )
{
  int len;
  char* buf;
  c->ns_tab = ZX_ALLOC(c, sizeof(zx_ns_tab));
  memcpy(c->ns_tab, zx_ns_tab, sizeof(zx_ns_tab));
  len = zx_LEN_SO_ac_OperationalProtection(c, x );
  buf = ZX_ALLOC(c, len+1);
  return zx_easy_enc_common(c, zx_ENC_SO_ac_OperationalProtection(c, x, buf ), buf, len);
}

/* FUNC(zx_EASY_ENC_WO_ac_OperationalProtection) */

/* Called by: */
struct zx_str* zx_EASY_ENC_WO_ac_OperationalProtection(struct zx_ctx* c, struct zx_ac_OperationalProtection_s* x )
{
  int len;
  char* buf;
  c->ns_tab = ZX_ALLOC(c, sizeof(zx_ns_tab));
  memcpy(c->ns_tab, zx_ns_tab, sizeof(zx_ns_tab));
  len = zx_LEN_WO_ac_OperationalProtection(c, x );
  buf = ZX_ALLOC(c, len+1);
  return zx_easy_enc_common(c, zx_ENC_WO_ac_OperationalProtection(c, x, buf ), buf, len);
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

#define EL_NAME   ac_Password
#define EL_STRUCT zx_ac_Password_s
#define EL_NS     ac
#define EL_TAG    Password

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

/* FUNC(zx_LEN_SO_ac_Password) */

/* Compute length of an element (and its subelements). The XML attributes
 * and elements are processed in schema order. */

/* Called by: */
int zx_LEN_SO_ac_Password(struct zx_ctx* c, struct zx_ac_Password_s* x )
{
  struct zx_ns_s* pop_seen = 0;
  struct zx_elem_s* se MAYBE_UNUSED;
#if 1 /* NORMALMODE */
  /* *** in simple_elem case should output ns prefix from ns node. */
  int len = sizeof("<ac:Password")-1 + 1 + sizeof("</ac:Password>")-1;
  if (c->inc_ns_len)
    len += zx_len_inc_ns(c, &pop_seen);
  len += zx_len_xmlns_if_not_seen(c, zx_ns_tab+zx_xmlns_ix_ac, &pop_seen);


#else
  /* root node has no begin tag */
  int len = 0;
#endif
  
  {
      struct zx_ac_Length_s* e;
      for (e = x->Length; e; e = (struct zx_ac_Length_s*)e->gg.g.n)
	  len += zx_LEN_SO_ac_Length(c, e);
  }
  {
      struct zx_ac_Alphabet_s* e;
      for (e = x->Alphabet; e; e = (struct zx_ac_Alphabet_s*)e->gg.g.n)
	  len += zx_LEN_SO_ac_Alphabet(c, e);
  }
  {
      struct zx_ac_Generation_s* e;
      for (e = x->Generation; e; e = (struct zx_ac_Generation_s*)e->gg.g.n)
	  len += zx_LEN_SO_ac_Generation(c, e);
  }
  {
      struct zx_ac_Extension_s* e;
      for (e = x->Extension; e; e = (struct zx_ac_Extension_s*)e->gg.g.n)
	  len += zx_LEN_SO_ac_Extension(c, e);
  }


  len += zx_len_so_common(c, &x->gg);
  zx_pop_seen(pop_seen);
  ENC_LEN_DEBUG(x, "ac:Password", len);
  return len;
}

/* FUNC(zx_LEN_WO_ac_Password) */

/* Compute length of an element (and its subelements). The XML attributes
 * and elements are processed in wire order and no assumptions
 * are made about namespace prefixes. */

/* Called by: */
int zx_LEN_WO_ac_Password(struct zx_ctx* c, struct zx_ac_Password_s* x )
{
  struct zx_ns_s* pop_seen = 0;
  struct zx_elem_s* se MAYBE_UNUSED;
#if 1 /* NORMALMODE */
  int len = 1 + sizeof("Password")-1 + 1 + 2 + sizeof("Password")-1 + 1;
  
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
      struct zx_ac_Length_s* e;
      for (e = x->Length; e; e = (struct zx_ac_Length_s*)e->gg.g.n)
	  len += zx_LEN_WO_ac_Length(c, e);
  }
  {
      struct zx_ac_Alphabet_s* e;
      for (e = x->Alphabet; e; e = (struct zx_ac_Alphabet_s*)e->gg.g.n)
	  len += zx_LEN_WO_ac_Alphabet(c, e);
  }
  {
      struct zx_ac_Generation_s* e;
      for (e = x->Generation; e; e = (struct zx_ac_Generation_s*)e->gg.g.n)
	  len += zx_LEN_WO_ac_Generation(c, e);
  }
  {
      struct zx_ac_Extension_s* e;
      for (e = x->Extension; e; e = (struct zx_ac_Extension_s*)e->gg.g.n)
	  len += zx_LEN_WO_ac_Extension(c, e);
  }


  len += zx_len_wo_common(c, &x->gg); 
  zx_pop_seen(pop_seen);
  ENC_LEN_DEBUG(x, "ac:Password", len);
  return len;
}

/* FUNC(zx_ENC_SO_ac_Password) */

/* Render element into string. The XML attributes and elements are
 * processed in schema order. This is what you generally want for
 * rendering new data structure to a string. The wo pointers are not used. */

/* Called by: */
char* zx_ENC_SO_ac_Password(struct zx_ctx* c, struct zx_ac_Password_s* x, char* p )
{
  struct zx_elem_s* se MAYBE_UNUSED;
  ENC_LEN_DEBUG_BASE;
#if 1 /* NORMALMODE */
  struct zx_ns_s* pop_seen = 0;
  /* *** in simple_elem case should output ns prefix from ns node. */
  ZX_OUT_TAG(p, "<ac:Password");
  if (c->inc_ns)
    p = zx_enc_inc_ns(c, p, &pop_seen);
  p = zx_enc_xmlns_if_not_seen(c, p, zx_ns_tab+zx_xmlns_ix_ac, &pop_seen);


  p = zx_enc_unknown_attrs(p, x->gg.any_attr);
#else
  /* root node has no begin tag */
#endif
  
  {
      struct zx_ac_Length_s* e;
      for (e = x->Length; e; e = (struct zx_ac_Length_s*)e->gg.g.n)
	  p = zx_ENC_SO_ac_Length(c, e, p);
  }
  {
      struct zx_ac_Alphabet_s* e;
      for (e = x->Alphabet; e; e = (struct zx_ac_Alphabet_s*)e->gg.g.n)
	  p = zx_ENC_SO_ac_Alphabet(c, e, p);
  }
  {
      struct zx_ac_Generation_s* e;
      for (e = x->Generation; e; e = (struct zx_ac_Generation_s*)e->gg.g.n)
	  p = zx_ENC_SO_ac_Generation(c, e, p);
  }
  {
      struct zx_ac_Extension_s* e;
      for (e = x->Extension; e; e = (struct zx_ac_Extension_s*)e->gg.g.n)
	  p = zx_ENC_SO_ac_Extension(c, e, p);
  }

  p = zx_enc_so_unknown_elems_and_content(c, p, &x->gg);
  
#if 1 /* NORMALMODE */
  ZX_OUT_CLOSE_TAG(p, "</ac:Password>");
  zx_pop_seen(pop_seen);
#else
  /* root node has no end tag either */
#endif
  ENC_LEN_DEBUG(x, "ac:Password", p-enc_base);
  return p;
}

/* FUNC(zx_ENC_WO_ac_Password) */

/* Render element into string. The XML attributes and elements are
 * processed in wire order by chasing wo pointers. This is what you want for
 * validating signatures on other people's XML documents. */

/* Called by: */
char* zx_ENC_WO_ac_Password(struct zx_ctx* c, struct zx_ac_Password_s* x, char* p )
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
  ZX_OUT_MEM(p, "Password", sizeof("Password")-1);
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
  ENC_LEN_DEBUG(x, "ac:Password", p-enc_base);
  return p;
}

/* FUNC(zx_EASY_ENC_SO_ac_Password) */

/* Called by: */
struct zx_str* zx_EASY_ENC_SO_ac_Password(struct zx_ctx* c, struct zx_ac_Password_s* x )
{
  int len;
  char* buf;
  c->ns_tab = ZX_ALLOC(c, sizeof(zx_ns_tab));
  memcpy(c->ns_tab, zx_ns_tab, sizeof(zx_ns_tab));
  len = zx_LEN_SO_ac_Password(c, x );
  buf = ZX_ALLOC(c, len+1);
  return zx_easy_enc_common(c, zx_ENC_SO_ac_Password(c, x, buf ), buf, len);
}

/* FUNC(zx_EASY_ENC_WO_ac_Password) */

/* Called by: */
struct zx_str* zx_EASY_ENC_WO_ac_Password(struct zx_ctx* c, struct zx_ac_Password_s* x )
{
  int len;
  char* buf;
  c->ns_tab = ZX_ALLOC(c, sizeof(zx_ns_tab));
  memcpy(c->ns_tab, zx_ns_tab, sizeof(zx_ns_tab));
  len = zx_LEN_WO_ac_Password(c, x );
  buf = ZX_ALLOC(c, len+1);
  return zx_easy_enc_common(c, zx_ENC_WO_ac_Password(c, x, buf ), buf, len);
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

#define EL_NAME   ac_PhysicalVerification
#define EL_STRUCT zx_ac_PhysicalVerification_s
#define EL_NS     ac
#define EL_TAG    PhysicalVerification

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

/* FUNC(zx_LEN_SO_ac_PhysicalVerification) */

/* Compute length of an element (and its subelements). The XML attributes
 * and elements are processed in schema order. */

/* Called by: */
int zx_LEN_SO_ac_PhysicalVerification(struct zx_ctx* c, struct zx_ac_PhysicalVerification_s* x )
{
  struct zx_ns_s* pop_seen = 0;
  struct zx_elem_s* se MAYBE_UNUSED;
#if 1 /* NORMALMODE */
  /* *** in simple_elem case should output ns prefix from ns node. */
  int len = sizeof("<ac:PhysicalVerification")-1 + 1 + sizeof("</ac:PhysicalVerification>")-1;
  if (c->inc_ns_len)
    len += zx_len_inc_ns(c, &pop_seen);
  len += zx_len_xmlns_if_not_seen(c, zx_ns_tab+zx_xmlns_ix_ac, &pop_seen);

  len += zx_attr_so_len(x->credentialLevel, sizeof("credentialLevel")-1);

#else
  /* root node has no begin tag */
  int len = 0;
#endif
  


  len += zx_len_so_common(c, &x->gg);
  zx_pop_seen(pop_seen);
  ENC_LEN_DEBUG(x, "ac:PhysicalVerification", len);
  return len;
}

/* FUNC(zx_LEN_WO_ac_PhysicalVerification) */

/* Compute length of an element (and its subelements). The XML attributes
 * and elements are processed in wire order and no assumptions
 * are made about namespace prefixes. */

/* Called by: */
int zx_LEN_WO_ac_PhysicalVerification(struct zx_ctx* c, struct zx_ac_PhysicalVerification_s* x )
{
  struct zx_ns_s* pop_seen = 0;
  struct zx_elem_s* se MAYBE_UNUSED;
#if 1 /* NORMALMODE */
  int len = 1 + sizeof("PhysicalVerification")-1 + 1 + 2 + sizeof("PhysicalVerification")-1 + 1;
  
  if (x->gg.g.ns && x->gg.g.ns->prefix_len)
    len += (x->gg.g.ns->prefix_len + 1) * 2;
  if (c->inc_ns_len)
    len += zx_len_inc_ns(c, &pop_seen);
  len += zx_len_xmlns_if_not_seen(c, x->gg.g.ns, &pop_seen);

  len += zx_attr_wo_len(x->credentialLevel, sizeof("credentialLevel")-1);

#else
  /* root node has no begin tag */
  int len = 0;
#endif
  


  len += zx_len_wo_common(c, &x->gg); 
  zx_pop_seen(pop_seen);
  ENC_LEN_DEBUG(x, "ac:PhysicalVerification", len);
  return len;
}

/* FUNC(zx_ENC_SO_ac_PhysicalVerification) */

/* Render element into string. The XML attributes and elements are
 * processed in schema order. This is what you generally want for
 * rendering new data structure to a string. The wo pointers are not used. */

/* Called by: */
char* zx_ENC_SO_ac_PhysicalVerification(struct zx_ctx* c, struct zx_ac_PhysicalVerification_s* x, char* p )
{
  struct zx_elem_s* se MAYBE_UNUSED;
  ENC_LEN_DEBUG_BASE;
#if 1 /* NORMALMODE */
  struct zx_ns_s* pop_seen = 0;
  /* *** in simple_elem case should output ns prefix from ns node. */
  ZX_OUT_TAG(p, "<ac:PhysicalVerification");
  if (c->inc_ns)
    p = zx_enc_inc_ns(c, p, &pop_seen);
  p = zx_enc_xmlns_if_not_seen(c, p, zx_ns_tab+zx_xmlns_ix_ac, &pop_seen);

  p = zx_attr_so_enc(p, x->credentialLevel, " credentialLevel=\"", sizeof(" credentialLevel=\"")-1);

  p = zx_enc_unknown_attrs(p, x->gg.any_attr);
#else
  /* root node has no begin tag */
#endif
  

  p = zx_enc_so_unknown_elems_and_content(c, p, &x->gg);
  
#if 1 /* NORMALMODE */
  ZX_OUT_CLOSE_TAG(p, "</ac:PhysicalVerification>");
  zx_pop_seen(pop_seen);
#else
  /* root node has no end tag either */
#endif
  ENC_LEN_DEBUG(x, "ac:PhysicalVerification", p-enc_base);
  return p;
}

/* FUNC(zx_ENC_WO_ac_PhysicalVerification) */

/* Render element into string. The XML attributes and elements are
 * processed in wire order by chasing wo pointers. This is what you want for
 * validating signatures on other people's XML documents. */

/* Called by: */
char* zx_ENC_WO_ac_PhysicalVerification(struct zx_ctx* c, struct zx_ac_PhysicalVerification_s* x, char* p )
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
  ZX_OUT_MEM(p, "PhysicalVerification", sizeof("PhysicalVerification")-1);
  qq = p;

  /* *** sort the namespaces */
  if (c->inc_ns)
    zx_add_inc_ns(c, &pop_seen);
  zx_add_xmlns_if_not_seen(c, x->gg.g.ns, &pop_seen);

  p = zx_enc_seen(p, pop_seen); 
  p = zx_attr_wo_enc(p, x->credentialLevel, "credentialLevel=\"", sizeof("credentialLevel=\"")-1);

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
  ENC_LEN_DEBUG(x, "ac:PhysicalVerification", p-enc_base);
  return p;
}

/* FUNC(zx_EASY_ENC_SO_ac_PhysicalVerification) */

/* Called by: */
struct zx_str* zx_EASY_ENC_SO_ac_PhysicalVerification(struct zx_ctx* c, struct zx_ac_PhysicalVerification_s* x )
{
  int len;
  char* buf;
  c->ns_tab = ZX_ALLOC(c, sizeof(zx_ns_tab));
  memcpy(c->ns_tab, zx_ns_tab, sizeof(zx_ns_tab));
  len = zx_LEN_SO_ac_PhysicalVerification(c, x );
  buf = ZX_ALLOC(c, len+1);
  return zx_easy_enc_common(c, zx_ENC_SO_ac_PhysicalVerification(c, x, buf ), buf, len);
}

/* FUNC(zx_EASY_ENC_WO_ac_PhysicalVerification) */

/* Called by: */
struct zx_str* zx_EASY_ENC_WO_ac_PhysicalVerification(struct zx_ctx* c, struct zx_ac_PhysicalVerification_s* x )
{
  int len;
  char* buf;
  c->ns_tab = ZX_ALLOC(c, sizeof(zx_ns_tab));
  memcpy(c->ns_tab, zx_ns_tab, sizeof(zx_ns_tab));
  len = zx_LEN_WO_ac_PhysicalVerification(c, x );
  buf = ZX_ALLOC(c, len+1);
  return zx_easy_enc_common(c, zx_ENC_WO_ac_PhysicalVerification(c, x, buf ), buf, len);
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

#define EL_NAME   ac_PreviousSession
#define EL_STRUCT zx_ac_PreviousSession_s
#define EL_NS     ac
#define EL_TAG    PreviousSession

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

/* FUNC(zx_LEN_SO_ac_PreviousSession) */

/* Compute length of an element (and its subelements). The XML attributes
 * and elements are processed in schema order. */

/* Called by: */
int zx_LEN_SO_ac_PreviousSession(struct zx_ctx* c, struct zx_ac_PreviousSession_s* x )
{
  struct zx_ns_s* pop_seen = 0;
  struct zx_elem_s* se MAYBE_UNUSED;
#if 1 /* NORMALMODE */
  /* *** in simple_elem case should output ns prefix from ns node. */
  int len = sizeof("<ac:PreviousSession")-1 + 1 + sizeof("</ac:PreviousSession>")-1;
  if (c->inc_ns_len)
    len += zx_len_inc_ns(c, &pop_seen);
  len += zx_len_xmlns_if_not_seen(c, zx_ns_tab+zx_xmlns_ix_ac, &pop_seen);


#else
  /* root node has no begin tag */
  int len = 0;
#endif
  
  {
      struct zx_ac_Extension_s* e;
      for (e = x->Extension; e; e = (struct zx_ac_Extension_s*)e->gg.g.n)
	  len += zx_LEN_SO_ac_Extension(c, e);
  }


  len += zx_len_so_common(c, &x->gg);
  zx_pop_seen(pop_seen);
  ENC_LEN_DEBUG(x, "ac:PreviousSession", len);
  return len;
}

/* FUNC(zx_LEN_WO_ac_PreviousSession) */

/* Compute length of an element (and its subelements). The XML attributes
 * and elements are processed in wire order and no assumptions
 * are made about namespace prefixes. */

/* Called by: */
int zx_LEN_WO_ac_PreviousSession(struct zx_ctx* c, struct zx_ac_PreviousSession_s* x )
{
  struct zx_ns_s* pop_seen = 0;
  struct zx_elem_s* se MAYBE_UNUSED;
#if 1 /* NORMALMODE */
  int len = 1 + sizeof("PreviousSession")-1 + 1 + 2 + sizeof("PreviousSession")-1 + 1;
  
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
      struct zx_ac_Extension_s* e;
      for (e = x->Extension; e; e = (struct zx_ac_Extension_s*)e->gg.g.n)
	  len += zx_LEN_WO_ac_Extension(c, e);
  }


  len += zx_len_wo_common(c, &x->gg); 
  zx_pop_seen(pop_seen);
  ENC_LEN_DEBUG(x, "ac:PreviousSession", len);
  return len;
}

/* FUNC(zx_ENC_SO_ac_PreviousSession) */

/* Render element into string. The XML attributes and elements are
 * processed in schema order. This is what you generally want for
 * rendering new data structure to a string. The wo pointers are not used. */

/* Called by: */
char* zx_ENC_SO_ac_PreviousSession(struct zx_ctx* c, struct zx_ac_PreviousSession_s* x, char* p )
{
  struct zx_elem_s* se MAYBE_UNUSED;
  ENC_LEN_DEBUG_BASE;
#if 1 /* NORMALMODE */
  struct zx_ns_s* pop_seen = 0;
  /* *** in simple_elem case should output ns prefix from ns node. */
  ZX_OUT_TAG(p, "<ac:PreviousSession");
  if (c->inc_ns)
    p = zx_enc_inc_ns(c, p, &pop_seen);
  p = zx_enc_xmlns_if_not_seen(c, p, zx_ns_tab+zx_xmlns_ix_ac, &pop_seen);


  p = zx_enc_unknown_attrs(p, x->gg.any_attr);
#else
  /* root node has no begin tag */
#endif
  
  {
      struct zx_ac_Extension_s* e;
      for (e = x->Extension; e; e = (struct zx_ac_Extension_s*)e->gg.g.n)
	  p = zx_ENC_SO_ac_Extension(c, e, p);
  }

  p = zx_enc_so_unknown_elems_and_content(c, p, &x->gg);
  
#if 1 /* NORMALMODE */
  ZX_OUT_CLOSE_TAG(p, "</ac:PreviousSession>");
  zx_pop_seen(pop_seen);
#else
  /* root node has no end tag either */
#endif
  ENC_LEN_DEBUG(x, "ac:PreviousSession", p-enc_base);
  return p;
}

/* FUNC(zx_ENC_WO_ac_PreviousSession) */

/* Render element into string. The XML attributes and elements are
 * processed in wire order by chasing wo pointers. This is what you want for
 * validating signatures on other people's XML documents. */

/* Called by: */
char* zx_ENC_WO_ac_PreviousSession(struct zx_ctx* c, struct zx_ac_PreviousSession_s* x, char* p )
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
  ZX_OUT_MEM(p, "PreviousSession", sizeof("PreviousSession")-1);
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
  ENC_LEN_DEBUG(x, "ac:PreviousSession", p-enc_base);
  return p;
}

/* FUNC(zx_EASY_ENC_SO_ac_PreviousSession) */

/* Called by: */
struct zx_str* zx_EASY_ENC_SO_ac_PreviousSession(struct zx_ctx* c, struct zx_ac_PreviousSession_s* x )
{
  int len;
  char* buf;
  c->ns_tab = ZX_ALLOC(c, sizeof(zx_ns_tab));
  memcpy(c->ns_tab, zx_ns_tab, sizeof(zx_ns_tab));
  len = zx_LEN_SO_ac_PreviousSession(c, x );
  buf = ZX_ALLOC(c, len+1);
  return zx_easy_enc_common(c, zx_ENC_SO_ac_PreviousSession(c, x, buf ), buf, len);
}

/* FUNC(zx_EASY_ENC_WO_ac_PreviousSession) */

/* Called by: */
struct zx_str* zx_EASY_ENC_WO_ac_PreviousSession(struct zx_ctx* c, struct zx_ac_PreviousSession_s* x )
{
  int len;
  char* buf;
  c->ns_tab = ZX_ALLOC(c, sizeof(zx_ns_tab));
  memcpy(c->ns_tab, zx_ns_tab, sizeof(zx_ns_tab));
  len = zx_LEN_WO_ac_PreviousSession(c, x );
  buf = ZX_ALLOC(c, len+1);
  return zx_easy_enc_common(c, zx_ENC_WO_ac_PreviousSession(c, x, buf ), buf, len);
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

#define EL_NAME   ac_PrincipalAuthenticationMechanism
#define EL_STRUCT zx_ac_PrincipalAuthenticationMechanism_s
#define EL_NS     ac
#define EL_TAG    PrincipalAuthenticationMechanism

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

/* FUNC(zx_LEN_SO_ac_PrincipalAuthenticationMechanism) */

/* Compute length of an element (and its subelements). The XML attributes
 * and elements are processed in schema order. */

/* Called by: */
int zx_LEN_SO_ac_PrincipalAuthenticationMechanism(struct zx_ctx* c, struct zx_ac_PrincipalAuthenticationMechanism_s* x )
{
  struct zx_ns_s* pop_seen = 0;
  struct zx_elem_s* se MAYBE_UNUSED;
#if 1 /* NORMALMODE */
  /* *** in simple_elem case should output ns prefix from ns node. */
  int len = sizeof("<ac:PrincipalAuthenticationMechanism")-1 + 1 + sizeof("</ac:PrincipalAuthenticationMechanism>")-1;
  if (c->inc_ns_len)
    len += zx_len_inc_ns(c, &pop_seen);
  len += zx_len_xmlns_if_not_seen(c, zx_ns_tab+zx_xmlns_ix_ac, &pop_seen);


#else
  /* root node has no begin tag */
  int len = 0;
#endif
  
  {
      struct zx_ac_Password_s* e;
      for (e = x->Password; e; e = (struct zx_ac_Password_s*)e->gg.g.n)
	  len += zx_LEN_SO_ac_Password(c, e);
  }
  {
      struct zx_ac_Token_s* e;
      for (e = x->Token; e; e = (struct zx_ac_Token_s*)e->gg.g.n)
	  len += zx_LEN_SO_ac_Token(c, e);
  }
  {
      struct zx_ac_Smartcard_s* e;
      for (e = x->Smartcard; e; e = (struct zx_ac_Smartcard_s*)e->gg.g.n)
	  len += zx_LEN_SO_ac_Smartcard(c, e);
  }
  {
      struct zx_ac_ActivationPin_s* e;
      for (e = x->ActivationPin; e; e = (struct zx_ac_ActivationPin_s*)e->gg.g.n)
	  len += zx_LEN_SO_ac_ActivationPin(c, e);
  }
  {
      struct zx_ac_Extension_s* e;
      for (e = x->Extension; e; e = (struct zx_ac_Extension_s*)e->gg.g.n)
	  len += zx_LEN_SO_ac_Extension(c, e);
  }


  len += zx_len_so_common(c, &x->gg);
  zx_pop_seen(pop_seen);
  ENC_LEN_DEBUG(x, "ac:PrincipalAuthenticationMechanism", len);
  return len;
}

/* FUNC(zx_LEN_WO_ac_PrincipalAuthenticationMechanism) */

/* Compute length of an element (and its subelements). The XML attributes
 * and elements are processed in wire order and no assumptions
 * are made about namespace prefixes. */

/* Called by: */
int zx_LEN_WO_ac_PrincipalAuthenticationMechanism(struct zx_ctx* c, struct zx_ac_PrincipalAuthenticationMechanism_s* x )
{
  struct zx_ns_s* pop_seen = 0;
  struct zx_elem_s* se MAYBE_UNUSED;
#if 1 /* NORMALMODE */
  int len = 1 + sizeof("PrincipalAuthenticationMechanism")-1 + 1 + 2 + sizeof("PrincipalAuthenticationMechanism")-1 + 1;
  
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
      struct zx_ac_Password_s* e;
      for (e = x->Password; e; e = (struct zx_ac_Password_s*)e->gg.g.n)
	  len += zx_LEN_WO_ac_Password(c, e);
  }
  {
      struct zx_ac_Token_s* e;
      for (e = x->Token; e; e = (struct zx_ac_Token_s*)e->gg.g.n)
	  len += zx_LEN_WO_ac_Token(c, e);
  }
  {
      struct zx_ac_Smartcard_s* e;
      for (e = x->Smartcard; e; e = (struct zx_ac_Smartcard_s*)e->gg.g.n)
	  len += zx_LEN_WO_ac_Smartcard(c, e);
  }
  {
      struct zx_ac_ActivationPin_s* e;
      for (e = x->ActivationPin; e; e = (struct zx_ac_ActivationPin_s*)e->gg.g.n)
	  len += zx_LEN_WO_ac_ActivationPin(c, e);
  }
  {
      struct zx_ac_Extension_s* e;
      for (e = x->Extension; e; e = (struct zx_ac_Extension_s*)e->gg.g.n)
	  len += zx_LEN_WO_ac_Extension(c, e);
  }


  len += zx_len_wo_common(c, &x->gg); 
  zx_pop_seen(pop_seen);
  ENC_LEN_DEBUG(x, "ac:PrincipalAuthenticationMechanism", len);
  return len;
}

/* FUNC(zx_ENC_SO_ac_PrincipalAuthenticationMechanism) */

/* Render element into string. The XML attributes and elements are
 * processed in schema order. This is what you generally want for
 * rendering new data structure to a string. The wo pointers are not used. */

/* Called by: */
char* zx_ENC_SO_ac_PrincipalAuthenticationMechanism(struct zx_ctx* c, struct zx_ac_PrincipalAuthenticationMechanism_s* x, char* p )
{
  struct zx_elem_s* se MAYBE_UNUSED;
  ENC_LEN_DEBUG_BASE;
#if 1 /* NORMALMODE */
  struct zx_ns_s* pop_seen = 0;
  /* *** in simple_elem case should output ns prefix from ns node. */
  ZX_OUT_TAG(p, "<ac:PrincipalAuthenticationMechanism");
  if (c->inc_ns)
    p = zx_enc_inc_ns(c, p, &pop_seen);
  p = zx_enc_xmlns_if_not_seen(c, p, zx_ns_tab+zx_xmlns_ix_ac, &pop_seen);


  p = zx_enc_unknown_attrs(p, x->gg.any_attr);
#else
  /* root node has no begin tag */
#endif
  
  {
      struct zx_ac_Password_s* e;
      for (e = x->Password; e; e = (struct zx_ac_Password_s*)e->gg.g.n)
	  p = zx_ENC_SO_ac_Password(c, e, p);
  }
  {
      struct zx_ac_Token_s* e;
      for (e = x->Token; e; e = (struct zx_ac_Token_s*)e->gg.g.n)
	  p = zx_ENC_SO_ac_Token(c, e, p);
  }
  {
      struct zx_ac_Smartcard_s* e;
      for (e = x->Smartcard; e; e = (struct zx_ac_Smartcard_s*)e->gg.g.n)
	  p = zx_ENC_SO_ac_Smartcard(c, e, p);
  }
  {
      struct zx_ac_ActivationPin_s* e;
      for (e = x->ActivationPin; e; e = (struct zx_ac_ActivationPin_s*)e->gg.g.n)
	  p = zx_ENC_SO_ac_ActivationPin(c, e, p);
  }
  {
      struct zx_ac_Extension_s* e;
      for (e = x->Extension; e; e = (struct zx_ac_Extension_s*)e->gg.g.n)
	  p = zx_ENC_SO_ac_Extension(c, e, p);
  }

  p = zx_enc_so_unknown_elems_and_content(c, p, &x->gg);
  
#if 1 /* NORMALMODE */
  ZX_OUT_CLOSE_TAG(p, "</ac:PrincipalAuthenticationMechanism>");
  zx_pop_seen(pop_seen);
#else
  /* root node has no end tag either */
#endif
  ENC_LEN_DEBUG(x, "ac:PrincipalAuthenticationMechanism", p-enc_base);
  return p;
}

/* FUNC(zx_ENC_WO_ac_PrincipalAuthenticationMechanism) */

/* Render element into string. The XML attributes and elements are
 * processed in wire order by chasing wo pointers. This is what you want for
 * validating signatures on other people's XML documents. */

/* Called by: */
char* zx_ENC_WO_ac_PrincipalAuthenticationMechanism(struct zx_ctx* c, struct zx_ac_PrincipalAuthenticationMechanism_s* x, char* p )
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
  ZX_OUT_MEM(p, "PrincipalAuthenticationMechanism", sizeof("PrincipalAuthenticationMechanism")-1);
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
  ENC_LEN_DEBUG(x, "ac:PrincipalAuthenticationMechanism", p-enc_base);
  return p;
}

/* FUNC(zx_EASY_ENC_SO_ac_PrincipalAuthenticationMechanism) */

/* Called by: */
struct zx_str* zx_EASY_ENC_SO_ac_PrincipalAuthenticationMechanism(struct zx_ctx* c, struct zx_ac_PrincipalAuthenticationMechanism_s* x )
{
  int len;
  char* buf;
  c->ns_tab = ZX_ALLOC(c, sizeof(zx_ns_tab));
  memcpy(c->ns_tab, zx_ns_tab, sizeof(zx_ns_tab));
  len = zx_LEN_SO_ac_PrincipalAuthenticationMechanism(c, x );
  buf = ZX_ALLOC(c, len+1);
  return zx_easy_enc_common(c, zx_ENC_SO_ac_PrincipalAuthenticationMechanism(c, x, buf ), buf, len);
}

/* FUNC(zx_EASY_ENC_WO_ac_PrincipalAuthenticationMechanism) */

/* Called by: */
struct zx_str* zx_EASY_ENC_WO_ac_PrincipalAuthenticationMechanism(struct zx_ctx* c, struct zx_ac_PrincipalAuthenticationMechanism_s* x )
{
  int len;
  char* buf;
  c->ns_tab = ZX_ALLOC(c, sizeof(zx_ns_tab));
  memcpy(c->ns_tab, zx_ns_tab, sizeof(zx_ns_tab));
  len = zx_LEN_WO_ac_PrincipalAuthenticationMechanism(c, x );
  buf = ZX_ALLOC(c, len+1);
  return zx_easy_enc_common(c, zx_ENC_WO_ac_PrincipalAuthenticationMechanism(c, x, buf ), buf, len);
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

#define EL_NAME   ac_PrivateKeyProtection
#define EL_STRUCT zx_ac_PrivateKeyProtection_s
#define EL_NS     ac
#define EL_TAG    PrivateKeyProtection

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

/* FUNC(zx_LEN_SO_ac_PrivateKeyProtection) */

/* Compute length of an element (and its subelements). The XML attributes
 * and elements are processed in schema order. */

/* Called by: */
int zx_LEN_SO_ac_PrivateKeyProtection(struct zx_ctx* c, struct zx_ac_PrivateKeyProtection_s* x )
{
  struct zx_ns_s* pop_seen = 0;
  struct zx_elem_s* se MAYBE_UNUSED;
#if 1 /* NORMALMODE */
  /* *** in simple_elem case should output ns prefix from ns node. */
  int len = sizeof("<ac:PrivateKeyProtection")-1 + 1 + sizeof("</ac:PrivateKeyProtection>")-1;
  if (c->inc_ns_len)
    len += zx_len_inc_ns(c, &pop_seen);
  len += zx_len_xmlns_if_not_seen(c, zx_ns_tab+zx_xmlns_ix_ac, &pop_seen);


#else
  /* root node has no begin tag */
  int len = 0;
#endif
  
  {
      struct zx_ac_KeyActivation_s* e;
      for (e = x->KeyActivation; e; e = (struct zx_ac_KeyActivation_s*)e->gg.g.n)
	  len += zx_LEN_SO_ac_KeyActivation(c, e);
  }
  {
      struct zx_ac_KeyStorage_s* e;
      for (e = x->KeyStorage; e; e = (struct zx_ac_KeyStorage_s*)e->gg.g.n)
	  len += zx_LEN_SO_ac_KeyStorage(c, e);
  }
  {
      struct zx_ac_KeySharing_s* e;
      for (e = x->KeySharing; e; e = (struct zx_ac_KeySharing_s*)e->gg.g.n)
	  len += zx_LEN_SO_ac_KeySharing(c, e);
  }
  {
      struct zx_ac_Extension_s* e;
      for (e = x->Extension; e; e = (struct zx_ac_Extension_s*)e->gg.g.n)
	  len += zx_LEN_SO_ac_Extension(c, e);
  }


  len += zx_len_so_common(c, &x->gg);
  zx_pop_seen(pop_seen);
  ENC_LEN_DEBUG(x, "ac:PrivateKeyProtection", len);
  return len;
}

/* FUNC(zx_LEN_WO_ac_PrivateKeyProtection) */

/* Compute length of an element (and its subelements). The XML attributes
 * and elements are processed in wire order and no assumptions
 * are made about namespace prefixes. */

/* Called by: */
int zx_LEN_WO_ac_PrivateKeyProtection(struct zx_ctx* c, struct zx_ac_PrivateKeyProtection_s* x )
{
  struct zx_ns_s* pop_seen = 0;
  struct zx_elem_s* se MAYBE_UNUSED;
#if 1 /* NORMALMODE */
  int len = 1 + sizeof("PrivateKeyProtection")-1 + 1 + 2 + sizeof("PrivateKeyProtection")-1 + 1;
  
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
      struct zx_ac_KeyActivation_s* e;
      for (e = x->KeyActivation; e; e = (struct zx_ac_KeyActivation_s*)e->gg.g.n)
	  len += zx_LEN_WO_ac_KeyActivation(c, e);
  }
  {
      struct zx_ac_KeyStorage_s* e;
      for (e = x->KeyStorage; e; e = (struct zx_ac_KeyStorage_s*)e->gg.g.n)
	  len += zx_LEN_WO_ac_KeyStorage(c, e);
  }
  {
      struct zx_ac_KeySharing_s* e;
      for (e = x->KeySharing; e; e = (struct zx_ac_KeySharing_s*)e->gg.g.n)
	  len += zx_LEN_WO_ac_KeySharing(c, e);
  }
  {
      struct zx_ac_Extension_s* e;
      for (e = x->Extension; e; e = (struct zx_ac_Extension_s*)e->gg.g.n)
	  len += zx_LEN_WO_ac_Extension(c, e);
  }


  len += zx_len_wo_common(c, &x->gg); 
  zx_pop_seen(pop_seen);
  ENC_LEN_DEBUG(x, "ac:PrivateKeyProtection", len);
  return len;
}

/* FUNC(zx_ENC_SO_ac_PrivateKeyProtection) */

/* Render element into string. The XML attributes and elements are
 * processed in schema order. This is what you generally want for
 * rendering new data structure to a string. The wo pointers are not used. */

/* Called by: */
char* zx_ENC_SO_ac_PrivateKeyProtection(struct zx_ctx* c, struct zx_ac_PrivateKeyProtection_s* x, char* p )
{
  struct zx_elem_s* se MAYBE_UNUSED;
  ENC_LEN_DEBUG_BASE;
#if 1 /* NORMALMODE */
  struct zx_ns_s* pop_seen = 0;
  /* *** in simple_elem case should output ns prefix from ns node. */
  ZX_OUT_TAG(p, "<ac:PrivateKeyProtection");
  if (c->inc_ns)
    p = zx_enc_inc_ns(c, p, &pop_seen);
  p = zx_enc_xmlns_if_not_seen(c, p, zx_ns_tab+zx_xmlns_ix_ac, &pop_seen);


  p = zx_enc_unknown_attrs(p, x->gg.any_attr);
#else
  /* root node has no begin tag */
#endif
  
  {
      struct zx_ac_KeyActivation_s* e;
      for (e = x->KeyActivation; e; e = (struct zx_ac_KeyActivation_s*)e->gg.g.n)
	  p = zx_ENC_SO_ac_KeyActivation(c, e, p);
  }
  {
      struct zx_ac_KeyStorage_s* e;
      for (e = x->KeyStorage; e; e = (struct zx_ac_KeyStorage_s*)e->gg.g.n)
	  p = zx_ENC_SO_ac_KeyStorage(c, e, p);
  }
  {
      struct zx_ac_KeySharing_s* e;
      for (e = x->KeySharing; e; e = (struct zx_ac_KeySharing_s*)e->gg.g.n)
	  p = zx_ENC_SO_ac_KeySharing(c, e, p);
  }
  {
      struct zx_ac_Extension_s* e;
      for (e = x->Extension; e; e = (struct zx_ac_Extension_s*)e->gg.g.n)
	  p = zx_ENC_SO_ac_Extension(c, e, p);
  }

  p = zx_enc_so_unknown_elems_and_content(c, p, &x->gg);
  
#if 1 /* NORMALMODE */
  ZX_OUT_CLOSE_TAG(p, "</ac:PrivateKeyProtection>");
  zx_pop_seen(pop_seen);
#else
  /* root node has no end tag either */
#endif
  ENC_LEN_DEBUG(x, "ac:PrivateKeyProtection", p-enc_base);
  return p;
}

/* FUNC(zx_ENC_WO_ac_PrivateKeyProtection) */

/* Render element into string. The XML attributes and elements are
 * processed in wire order by chasing wo pointers. This is what you want for
 * validating signatures on other people's XML documents. */

/* Called by: */
char* zx_ENC_WO_ac_PrivateKeyProtection(struct zx_ctx* c, struct zx_ac_PrivateKeyProtection_s* x, char* p )
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
  ZX_OUT_MEM(p, "PrivateKeyProtection", sizeof("PrivateKeyProtection")-1);
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
  ENC_LEN_DEBUG(x, "ac:PrivateKeyProtection", p-enc_base);
  return p;
}

/* FUNC(zx_EASY_ENC_SO_ac_PrivateKeyProtection) */

/* Called by: */
struct zx_str* zx_EASY_ENC_SO_ac_PrivateKeyProtection(struct zx_ctx* c, struct zx_ac_PrivateKeyProtection_s* x )
{
  int len;
  char* buf;
  c->ns_tab = ZX_ALLOC(c, sizeof(zx_ns_tab));
  memcpy(c->ns_tab, zx_ns_tab, sizeof(zx_ns_tab));
  len = zx_LEN_SO_ac_PrivateKeyProtection(c, x );
  buf = ZX_ALLOC(c, len+1);
  return zx_easy_enc_common(c, zx_ENC_SO_ac_PrivateKeyProtection(c, x, buf ), buf, len);
}

/* FUNC(zx_EASY_ENC_WO_ac_PrivateKeyProtection) */

/* Called by: */
struct zx_str* zx_EASY_ENC_WO_ac_PrivateKeyProtection(struct zx_ctx* c, struct zx_ac_PrivateKeyProtection_s* x )
{
  int len;
  char* buf;
  c->ns_tab = ZX_ALLOC(c, sizeof(zx_ns_tab));
  memcpy(c->ns_tab, zx_ns_tab, sizeof(zx_ns_tab));
  len = zx_LEN_WO_ac_PrivateKeyProtection(c, x );
  buf = ZX_ALLOC(c, len+1);
  return zx_easy_enc_common(c, zx_ENC_WO_ac_PrivateKeyProtection(c, x, buf ), buf, len);
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

#define EL_NAME   ac_ResumeSession
#define EL_STRUCT zx_ac_ResumeSession_s
#define EL_NS     ac
#define EL_TAG    ResumeSession

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

/* FUNC(zx_LEN_SO_ac_ResumeSession) */

/* Compute length of an element (and its subelements). The XML attributes
 * and elements are processed in schema order. */

/* Called by: */
int zx_LEN_SO_ac_ResumeSession(struct zx_ctx* c, struct zx_ac_ResumeSession_s* x )
{
  struct zx_ns_s* pop_seen = 0;
  struct zx_elem_s* se MAYBE_UNUSED;
#if 1 /* NORMALMODE */
  /* *** in simple_elem case should output ns prefix from ns node. */
  int len = sizeof("<ac:ResumeSession")-1 + 1 + sizeof("</ac:ResumeSession>")-1;
  if (c->inc_ns_len)
    len += zx_len_inc_ns(c, &pop_seen);
  len += zx_len_xmlns_if_not_seen(c, zx_ns_tab+zx_xmlns_ix_ac, &pop_seen);


#else
  /* root node has no begin tag */
  int len = 0;
#endif
  
  {
      struct zx_ac_Extension_s* e;
      for (e = x->Extension; e; e = (struct zx_ac_Extension_s*)e->gg.g.n)
	  len += zx_LEN_SO_ac_Extension(c, e);
  }


  len += zx_len_so_common(c, &x->gg);
  zx_pop_seen(pop_seen);
  ENC_LEN_DEBUG(x, "ac:ResumeSession", len);
  return len;
}

/* FUNC(zx_LEN_WO_ac_ResumeSession) */

/* Compute length of an element (and its subelements). The XML attributes
 * and elements are processed in wire order and no assumptions
 * are made about namespace prefixes. */

/* Called by: */
int zx_LEN_WO_ac_ResumeSession(struct zx_ctx* c, struct zx_ac_ResumeSession_s* x )
{
  struct zx_ns_s* pop_seen = 0;
  struct zx_elem_s* se MAYBE_UNUSED;
#if 1 /* NORMALMODE */
  int len = 1 + sizeof("ResumeSession")-1 + 1 + 2 + sizeof("ResumeSession")-1 + 1;
  
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
      struct zx_ac_Extension_s* e;
      for (e = x->Extension; e; e = (struct zx_ac_Extension_s*)e->gg.g.n)
	  len += zx_LEN_WO_ac_Extension(c, e);
  }


  len += zx_len_wo_common(c, &x->gg); 
  zx_pop_seen(pop_seen);
  ENC_LEN_DEBUG(x, "ac:ResumeSession", len);
  return len;
}

/* FUNC(zx_ENC_SO_ac_ResumeSession) */

/* Render element into string. The XML attributes and elements are
 * processed in schema order. This is what you generally want for
 * rendering new data structure to a string. The wo pointers are not used. */

/* Called by: */
char* zx_ENC_SO_ac_ResumeSession(struct zx_ctx* c, struct zx_ac_ResumeSession_s* x, char* p )
{
  struct zx_elem_s* se MAYBE_UNUSED;
  ENC_LEN_DEBUG_BASE;
#if 1 /* NORMALMODE */
  struct zx_ns_s* pop_seen = 0;
  /* *** in simple_elem case should output ns prefix from ns node. */
  ZX_OUT_TAG(p, "<ac:ResumeSession");
  if (c->inc_ns)
    p = zx_enc_inc_ns(c, p, &pop_seen);
  p = zx_enc_xmlns_if_not_seen(c, p, zx_ns_tab+zx_xmlns_ix_ac, &pop_seen);


  p = zx_enc_unknown_attrs(p, x->gg.any_attr);
#else
  /* root node has no begin tag */
#endif
  
  {
      struct zx_ac_Extension_s* e;
      for (e = x->Extension; e; e = (struct zx_ac_Extension_s*)e->gg.g.n)
	  p = zx_ENC_SO_ac_Extension(c, e, p);
  }

  p = zx_enc_so_unknown_elems_and_content(c, p, &x->gg);
  
#if 1 /* NORMALMODE */
  ZX_OUT_CLOSE_TAG(p, "</ac:ResumeSession>");
  zx_pop_seen(pop_seen);
#else
  /* root node has no end tag either */
#endif
  ENC_LEN_DEBUG(x, "ac:ResumeSession", p-enc_base);
  return p;
}

/* FUNC(zx_ENC_WO_ac_ResumeSession) */

/* Render element into string. The XML attributes and elements are
 * processed in wire order by chasing wo pointers. This is what you want for
 * validating signatures on other people's XML documents. */

/* Called by: */
char* zx_ENC_WO_ac_ResumeSession(struct zx_ctx* c, struct zx_ac_ResumeSession_s* x, char* p )
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
  ZX_OUT_MEM(p, "ResumeSession", sizeof("ResumeSession")-1);
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
  ENC_LEN_DEBUG(x, "ac:ResumeSession", p-enc_base);
  return p;
}

/* FUNC(zx_EASY_ENC_SO_ac_ResumeSession) */

/* Called by: */
struct zx_str* zx_EASY_ENC_SO_ac_ResumeSession(struct zx_ctx* c, struct zx_ac_ResumeSession_s* x )
{
  int len;
  char* buf;
  c->ns_tab = ZX_ALLOC(c, sizeof(zx_ns_tab));
  memcpy(c->ns_tab, zx_ns_tab, sizeof(zx_ns_tab));
  len = zx_LEN_SO_ac_ResumeSession(c, x );
  buf = ZX_ALLOC(c, len+1);
  return zx_easy_enc_common(c, zx_ENC_SO_ac_ResumeSession(c, x, buf ), buf, len);
}

/* FUNC(zx_EASY_ENC_WO_ac_ResumeSession) */

/* Called by: */
struct zx_str* zx_EASY_ENC_WO_ac_ResumeSession(struct zx_ctx* c, struct zx_ac_ResumeSession_s* x )
{
  int len;
  char* buf;
  c->ns_tab = ZX_ALLOC(c, sizeof(zx_ns_tab));
  memcpy(c->ns_tab, zx_ns_tab, sizeof(zx_ns_tab));
  len = zx_LEN_WO_ac_ResumeSession(c, x );
  buf = ZX_ALLOC(c, len+1);
  return zx_easy_enc_common(c, zx_ENC_WO_ac_ResumeSession(c, x, buf ), buf, len);
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

#define EL_NAME   ac_SSL
#define EL_STRUCT zx_ac_SSL_s
#define EL_NS     ac
#define EL_TAG    SSL

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

/* FUNC(zx_LEN_SO_ac_SSL) */

/* Compute length of an element (and its subelements). The XML attributes
 * and elements are processed in schema order. */

/* Called by: */
int zx_LEN_SO_ac_SSL(struct zx_ctx* c, struct zx_ac_SSL_s* x )
{
  struct zx_ns_s* pop_seen = 0;
  struct zx_elem_s* se MAYBE_UNUSED;
#if 1 /* NORMALMODE */
  /* *** in simple_elem case should output ns prefix from ns node. */
  int len = sizeof("<ac:SSL")-1 + 1 + sizeof("</ac:SSL>")-1;
  if (c->inc_ns_len)
    len += zx_len_inc_ns(c, &pop_seen);
  len += zx_len_xmlns_if_not_seen(c, zx_ns_tab+zx_xmlns_ix_ac, &pop_seen);


#else
  /* root node has no begin tag */
  int len = 0;
#endif
  
  {
      struct zx_ac_Extension_s* e;
      for (e = x->Extension; e; e = (struct zx_ac_Extension_s*)e->gg.g.n)
	  len += zx_LEN_SO_ac_Extension(c, e);
  }


  len += zx_len_so_common(c, &x->gg);
  zx_pop_seen(pop_seen);
  ENC_LEN_DEBUG(x, "ac:SSL", len);
  return len;
}

/* FUNC(zx_LEN_WO_ac_SSL) */

/* Compute length of an element (and its subelements). The XML attributes
 * and elements are processed in wire order and no assumptions
 * are made about namespace prefixes. */

/* Called by: */
int zx_LEN_WO_ac_SSL(struct zx_ctx* c, struct zx_ac_SSL_s* x )
{
  struct zx_ns_s* pop_seen = 0;
  struct zx_elem_s* se MAYBE_UNUSED;
#if 1 /* NORMALMODE */
  int len = 1 + sizeof("SSL")-1 + 1 + 2 + sizeof("SSL")-1 + 1;
  
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
      struct zx_ac_Extension_s* e;
      for (e = x->Extension; e; e = (struct zx_ac_Extension_s*)e->gg.g.n)
	  len += zx_LEN_WO_ac_Extension(c, e);
  }


  len += zx_len_wo_common(c, &x->gg); 
  zx_pop_seen(pop_seen);
  ENC_LEN_DEBUG(x, "ac:SSL", len);
  return len;
}

/* FUNC(zx_ENC_SO_ac_SSL) */

/* Render element into string. The XML attributes and elements are
 * processed in schema order. This is what you generally want for
 * rendering new data structure to a string. The wo pointers are not used. */

/* Called by: */
char* zx_ENC_SO_ac_SSL(struct zx_ctx* c, struct zx_ac_SSL_s* x, char* p )
{
  struct zx_elem_s* se MAYBE_UNUSED;
  ENC_LEN_DEBUG_BASE;
#if 1 /* NORMALMODE */
  struct zx_ns_s* pop_seen = 0;
  /* *** in simple_elem case should output ns prefix from ns node. */
  ZX_OUT_TAG(p, "<ac:SSL");
  if (c->inc_ns)
    p = zx_enc_inc_ns(c, p, &pop_seen);
  p = zx_enc_xmlns_if_not_seen(c, p, zx_ns_tab+zx_xmlns_ix_ac, &pop_seen);


  p = zx_enc_unknown_attrs(p, x->gg.any_attr);
#else
  /* root node has no begin tag */
#endif
  
  {
      struct zx_ac_Extension_s* e;
      for (e = x->Extension; e; e = (struct zx_ac_Extension_s*)e->gg.g.n)
	  p = zx_ENC_SO_ac_Extension(c, e, p);
  }

  p = zx_enc_so_unknown_elems_and_content(c, p, &x->gg);
  
#if 1 /* NORMALMODE */
  ZX_OUT_CLOSE_TAG(p, "</ac:SSL>");
  zx_pop_seen(pop_seen);
#else
  /* root node has no end tag either */
#endif
  ENC_LEN_DEBUG(x, "ac:SSL", p-enc_base);
  return p;
}

/* FUNC(zx_ENC_WO_ac_SSL) */

/* Render element into string. The XML attributes and elements are
 * processed in wire order by chasing wo pointers. This is what you want for
 * validating signatures on other people's XML documents. */

/* Called by: */
char* zx_ENC_WO_ac_SSL(struct zx_ctx* c, struct zx_ac_SSL_s* x, char* p )
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
  ZX_OUT_MEM(p, "SSL", sizeof("SSL")-1);
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
  ENC_LEN_DEBUG(x, "ac:SSL", p-enc_base);
  return p;
}

/* FUNC(zx_EASY_ENC_SO_ac_SSL) */

/* Called by: */
struct zx_str* zx_EASY_ENC_SO_ac_SSL(struct zx_ctx* c, struct zx_ac_SSL_s* x )
{
  int len;
  char* buf;
  c->ns_tab = ZX_ALLOC(c, sizeof(zx_ns_tab));
  memcpy(c->ns_tab, zx_ns_tab, sizeof(zx_ns_tab));
  len = zx_LEN_SO_ac_SSL(c, x );
  buf = ZX_ALLOC(c, len+1);
  return zx_easy_enc_common(c, zx_ENC_SO_ac_SSL(c, x, buf ), buf, len);
}

/* FUNC(zx_EASY_ENC_WO_ac_SSL) */

/* Called by: */
struct zx_str* zx_EASY_ENC_WO_ac_SSL(struct zx_ctx* c, struct zx_ac_SSL_s* x )
{
  int len;
  char* buf;
  c->ns_tab = ZX_ALLOC(c, sizeof(zx_ns_tab));
  memcpy(c->ns_tab, zx_ns_tab, sizeof(zx_ns_tab));
  len = zx_LEN_WO_ac_SSL(c, x );
  buf = ZX_ALLOC(c, len+1);
  return zx_easy_enc_common(c, zx_ENC_WO_ac_SSL(c, x, buf ), buf, len);
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

#define EL_NAME   ac_SecretKeyProtection
#define EL_STRUCT zx_ac_SecretKeyProtection_s
#define EL_NS     ac
#define EL_TAG    SecretKeyProtection

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

/* FUNC(zx_LEN_SO_ac_SecretKeyProtection) */

/* Compute length of an element (and its subelements). The XML attributes
 * and elements are processed in schema order. */

/* Called by: */
int zx_LEN_SO_ac_SecretKeyProtection(struct zx_ctx* c, struct zx_ac_SecretKeyProtection_s* x )
{
  struct zx_ns_s* pop_seen = 0;
  struct zx_elem_s* se MAYBE_UNUSED;
#if 1 /* NORMALMODE */
  /* *** in simple_elem case should output ns prefix from ns node. */
  int len = sizeof("<ac:SecretKeyProtection")-1 + 1 + sizeof("</ac:SecretKeyProtection>")-1;
  if (c->inc_ns_len)
    len += zx_len_inc_ns(c, &pop_seen);
  len += zx_len_xmlns_if_not_seen(c, zx_ns_tab+zx_xmlns_ix_ac, &pop_seen);


#else
  /* root node has no begin tag */
  int len = 0;
#endif
  
  {
      struct zx_ac_KeyActivation_s* e;
      for (e = x->KeyActivation; e; e = (struct zx_ac_KeyActivation_s*)e->gg.g.n)
	  len += zx_LEN_SO_ac_KeyActivation(c, e);
  }
  {
      struct zx_ac_KeyStorage_s* e;
      for (e = x->KeyStorage; e; e = (struct zx_ac_KeyStorage_s*)e->gg.g.n)
	  len += zx_LEN_SO_ac_KeyStorage(c, e);
  }
  {
      struct zx_ac_Extension_s* e;
      for (e = x->Extension; e; e = (struct zx_ac_Extension_s*)e->gg.g.n)
	  len += zx_LEN_SO_ac_Extension(c, e);
  }


  len += zx_len_so_common(c, &x->gg);
  zx_pop_seen(pop_seen);
  ENC_LEN_DEBUG(x, "ac:SecretKeyProtection", len);
  return len;
}

/* FUNC(zx_LEN_WO_ac_SecretKeyProtection) */

/* Compute length of an element (and its subelements). The XML attributes
 * and elements are processed in wire order and no assumptions
 * are made about namespace prefixes. */

/* Called by: */
int zx_LEN_WO_ac_SecretKeyProtection(struct zx_ctx* c, struct zx_ac_SecretKeyProtection_s* x )
{
  struct zx_ns_s* pop_seen = 0;
  struct zx_elem_s* se MAYBE_UNUSED;
#if 1 /* NORMALMODE */
  int len = 1 + sizeof("SecretKeyProtection")-1 + 1 + 2 + sizeof("SecretKeyProtection")-1 + 1;
  
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
      struct zx_ac_KeyActivation_s* e;
      for (e = x->KeyActivation; e; e = (struct zx_ac_KeyActivation_s*)e->gg.g.n)
	  len += zx_LEN_WO_ac_KeyActivation(c, e);
  }
  {
      struct zx_ac_KeyStorage_s* e;
      for (e = x->KeyStorage; e; e = (struct zx_ac_KeyStorage_s*)e->gg.g.n)
	  len += zx_LEN_WO_ac_KeyStorage(c, e);
  }
  {
      struct zx_ac_Extension_s* e;
      for (e = x->Extension; e; e = (struct zx_ac_Extension_s*)e->gg.g.n)
	  len += zx_LEN_WO_ac_Extension(c, e);
  }


  len += zx_len_wo_common(c, &x->gg); 
  zx_pop_seen(pop_seen);
  ENC_LEN_DEBUG(x, "ac:SecretKeyProtection", len);
  return len;
}

/* FUNC(zx_ENC_SO_ac_SecretKeyProtection) */

/* Render element into string. The XML attributes and elements are
 * processed in schema order. This is what you generally want for
 * rendering new data structure to a string. The wo pointers are not used. */

/* Called by: */
char* zx_ENC_SO_ac_SecretKeyProtection(struct zx_ctx* c, struct zx_ac_SecretKeyProtection_s* x, char* p )
{
  struct zx_elem_s* se MAYBE_UNUSED;
  ENC_LEN_DEBUG_BASE;
#if 1 /* NORMALMODE */
  struct zx_ns_s* pop_seen = 0;
  /* *** in simple_elem case should output ns prefix from ns node. */
  ZX_OUT_TAG(p, "<ac:SecretKeyProtection");
  if (c->inc_ns)
    p = zx_enc_inc_ns(c, p, &pop_seen);
  p = zx_enc_xmlns_if_not_seen(c, p, zx_ns_tab+zx_xmlns_ix_ac, &pop_seen);


  p = zx_enc_unknown_attrs(p, x->gg.any_attr);
#else
  /* root node has no begin tag */
#endif
  
  {
      struct zx_ac_KeyActivation_s* e;
      for (e = x->KeyActivation; e; e = (struct zx_ac_KeyActivation_s*)e->gg.g.n)
	  p = zx_ENC_SO_ac_KeyActivation(c, e, p);
  }
  {
      struct zx_ac_KeyStorage_s* e;
      for (e = x->KeyStorage; e; e = (struct zx_ac_KeyStorage_s*)e->gg.g.n)
	  p = zx_ENC_SO_ac_KeyStorage(c, e, p);
  }
  {
      struct zx_ac_Extension_s* e;
      for (e = x->Extension; e; e = (struct zx_ac_Extension_s*)e->gg.g.n)
	  p = zx_ENC_SO_ac_Extension(c, e, p);
  }

  p = zx_enc_so_unknown_elems_and_content(c, p, &x->gg);
  
#if 1 /* NORMALMODE */
  ZX_OUT_CLOSE_TAG(p, "</ac:SecretKeyProtection>");
  zx_pop_seen(pop_seen);
#else
  /* root node has no end tag either */
#endif
  ENC_LEN_DEBUG(x, "ac:SecretKeyProtection", p-enc_base);
  return p;
}

/* FUNC(zx_ENC_WO_ac_SecretKeyProtection) */

/* Render element into string. The XML attributes and elements are
 * processed in wire order by chasing wo pointers. This is what you want for
 * validating signatures on other people's XML documents. */

/* Called by: */
char* zx_ENC_WO_ac_SecretKeyProtection(struct zx_ctx* c, struct zx_ac_SecretKeyProtection_s* x, char* p )
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
  ZX_OUT_MEM(p, "SecretKeyProtection", sizeof("SecretKeyProtection")-1);
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
  ENC_LEN_DEBUG(x, "ac:SecretKeyProtection", p-enc_base);
  return p;
}

/* FUNC(zx_EASY_ENC_SO_ac_SecretKeyProtection) */

/* Called by: */
struct zx_str* zx_EASY_ENC_SO_ac_SecretKeyProtection(struct zx_ctx* c, struct zx_ac_SecretKeyProtection_s* x )
{
  int len;
  char* buf;
  c->ns_tab = ZX_ALLOC(c, sizeof(zx_ns_tab));
  memcpy(c->ns_tab, zx_ns_tab, sizeof(zx_ns_tab));
  len = zx_LEN_SO_ac_SecretKeyProtection(c, x );
  buf = ZX_ALLOC(c, len+1);
  return zx_easy_enc_common(c, zx_ENC_SO_ac_SecretKeyProtection(c, x, buf ), buf, len);
}

/* FUNC(zx_EASY_ENC_WO_ac_SecretKeyProtection) */

/* Called by: */
struct zx_str* zx_EASY_ENC_WO_ac_SecretKeyProtection(struct zx_ctx* c, struct zx_ac_SecretKeyProtection_s* x )
{
  int len;
  char* buf;
  c->ns_tab = ZX_ALLOC(c, sizeof(zx_ns_tab));
  memcpy(c->ns_tab, zx_ns_tab, sizeof(zx_ns_tab));
  len = zx_LEN_WO_ac_SecretKeyProtection(c, x );
  buf = ZX_ALLOC(c, len+1);
  return zx_easy_enc_common(c, zx_ENC_WO_ac_SecretKeyProtection(c, x, buf ), buf, len);
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

#define EL_NAME   ac_SecurityAudit
#define EL_STRUCT zx_ac_SecurityAudit_s
#define EL_NS     ac
#define EL_TAG    SecurityAudit

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

/* FUNC(zx_LEN_SO_ac_SecurityAudit) */

/* Compute length of an element (and its subelements). The XML attributes
 * and elements are processed in schema order. */

/* Called by: */
int zx_LEN_SO_ac_SecurityAudit(struct zx_ctx* c, struct zx_ac_SecurityAudit_s* x )
{
  struct zx_ns_s* pop_seen = 0;
  struct zx_elem_s* se MAYBE_UNUSED;
#if 1 /* NORMALMODE */
  /* *** in simple_elem case should output ns prefix from ns node. */
  int len = sizeof("<ac:SecurityAudit")-1 + 1 + sizeof("</ac:SecurityAudit>")-1;
  if (c->inc_ns_len)
    len += zx_len_inc_ns(c, &pop_seen);
  len += zx_len_xmlns_if_not_seen(c, zx_ns_tab+zx_xmlns_ix_ac, &pop_seen);


#else
  /* root node has no begin tag */
  int len = 0;
#endif
  
  {
      struct zx_ac_SwitchAudit_s* e;
      for (e = x->SwitchAudit; e; e = (struct zx_ac_SwitchAudit_s*)e->gg.g.n)
	  len += zx_LEN_SO_ac_SwitchAudit(c, e);
  }
  {
      struct zx_ac_Extension_s* e;
      for (e = x->Extension; e; e = (struct zx_ac_Extension_s*)e->gg.g.n)
	  len += zx_LEN_SO_ac_Extension(c, e);
  }


  len += zx_len_so_common(c, &x->gg);
  zx_pop_seen(pop_seen);
  ENC_LEN_DEBUG(x, "ac:SecurityAudit", len);
  return len;
}

/* FUNC(zx_LEN_WO_ac_SecurityAudit) */

/* Compute length of an element (and its subelements). The XML attributes
 * and elements are processed in wire order and no assumptions
 * are made about namespace prefixes. */

/* Called by: */
int zx_LEN_WO_ac_SecurityAudit(struct zx_ctx* c, struct zx_ac_SecurityAudit_s* x )
{
  struct zx_ns_s* pop_seen = 0;
  struct zx_elem_s* se MAYBE_UNUSED;
#if 1 /* NORMALMODE */
  int len = 1 + sizeof("SecurityAudit")-1 + 1 + 2 + sizeof("SecurityAudit")-1 + 1;
  
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
      struct zx_ac_SwitchAudit_s* e;
      for (e = x->SwitchAudit; e; e = (struct zx_ac_SwitchAudit_s*)e->gg.g.n)
	  len += zx_LEN_WO_ac_SwitchAudit(c, e);
  }
  {
      struct zx_ac_Extension_s* e;
      for (e = x->Extension; e; e = (struct zx_ac_Extension_s*)e->gg.g.n)
	  len += zx_LEN_WO_ac_Extension(c, e);
  }


  len += zx_len_wo_common(c, &x->gg); 
  zx_pop_seen(pop_seen);
  ENC_LEN_DEBUG(x, "ac:SecurityAudit", len);
  return len;
}

/* FUNC(zx_ENC_SO_ac_SecurityAudit) */

/* Render element into string. The XML attributes and elements are
 * processed in schema order. This is what you generally want for
 * rendering new data structure to a string. The wo pointers are not used. */

/* Called by: */
char* zx_ENC_SO_ac_SecurityAudit(struct zx_ctx* c, struct zx_ac_SecurityAudit_s* x, char* p )
{
  struct zx_elem_s* se MAYBE_UNUSED;
  ENC_LEN_DEBUG_BASE;
#if 1 /* NORMALMODE */
  struct zx_ns_s* pop_seen = 0;
  /* *** in simple_elem case should output ns prefix from ns node. */
  ZX_OUT_TAG(p, "<ac:SecurityAudit");
  if (c->inc_ns)
    p = zx_enc_inc_ns(c, p, &pop_seen);
  p = zx_enc_xmlns_if_not_seen(c, p, zx_ns_tab+zx_xmlns_ix_ac, &pop_seen);


  p = zx_enc_unknown_attrs(p, x->gg.any_attr);
#else
  /* root node has no begin tag */
#endif
  
  {
      struct zx_ac_SwitchAudit_s* e;
      for (e = x->SwitchAudit; e; e = (struct zx_ac_SwitchAudit_s*)e->gg.g.n)
	  p = zx_ENC_SO_ac_SwitchAudit(c, e, p);
  }
  {
      struct zx_ac_Extension_s* e;
      for (e = x->Extension; e; e = (struct zx_ac_Extension_s*)e->gg.g.n)
	  p = zx_ENC_SO_ac_Extension(c, e, p);
  }

  p = zx_enc_so_unknown_elems_and_content(c, p, &x->gg);
  
#if 1 /* NORMALMODE */
  ZX_OUT_CLOSE_TAG(p, "</ac:SecurityAudit>");
  zx_pop_seen(pop_seen);
#else
  /* root node has no end tag either */
#endif
  ENC_LEN_DEBUG(x, "ac:SecurityAudit", p-enc_base);
  return p;
}

/* FUNC(zx_ENC_WO_ac_SecurityAudit) */

/* Render element into string. The XML attributes and elements are
 * processed in wire order by chasing wo pointers. This is what you want for
 * validating signatures on other people's XML documents. */

/* Called by: */
char* zx_ENC_WO_ac_SecurityAudit(struct zx_ctx* c, struct zx_ac_SecurityAudit_s* x, char* p )
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
  ZX_OUT_MEM(p, "SecurityAudit", sizeof("SecurityAudit")-1);
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
  ENC_LEN_DEBUG(x, "ac:SecurityAudit", p-enc_base);
  return p;
}

/* FUNC(zx_EASY_ENC_SO_ac_SecurityAudit) */

/* Called by: */
struct zx_str* zx_EASY_ENC_SO_ac_SecurityAudit(struct zx_ctx* c, struct zx_ac_SecurityAudit_s* x )
{
  int len;
  char* buf;
  c->ns_tab = ZX_ALLOC(c, sizeof(zx_ns_tab));
  memcpy(c->ns_tab, zx_ns_tab, sizeof(zx_ns_tab));
  len = zx_LEN_SO_ac_SecurityAudit(c, x );
  buf = ZX_ALLOC(c, len+1);
  return zx_easy_enc_common(c, zx_ENC_SO_ac_SecurityAudit(c, x, buf ), buf, len);
}

/* FUNC(zx_EASY_ENC_WO_ac_SecurityAudit) */

/* Called by: */
struct zx_str* zx_EASY_ENC_WO_ac_SecurityAudit(struct zx_ctx* c, struct zx_ac_SecurityAudit_s* x )
{
  int len;
  char* buf;
  c->ns_tab = ZX_ALLOC(c, sizeof(zx_ns_tab));
  memcpy(c->ns_tab, zx_ns_tab, sizeof(zx_ns_tab));
  len = zx_LEN_WO_ac_SecurityAudit(c, x );
  buf = ZX_ALLOC(c, len+1);
  return zx_easy_enc_common(c, zx_ENC_WO_ac_SecurityAudit(c, x, buf ), buf, len);
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

#define EL_NAME   ac_SharedSecretChallengeResponse
#define EL_STRUCT zx_ac_SharedSecretChallengeResponse_s
#define EL_NS     ac
#define EL_TAG    SharedSecretChallengeResponse

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

/* FUNC(zx_LEN_SO_ac_SharedSecretChallengeResponse) */

/* Compute length of an element (and its subelements). The XML attributes
 * and elements are processed in schema order. */

/* Called by: */
int zx_LEN_SO_ac_SharedSecretChallengeResponse(struct zx_ctx* c, struct zx_ac_SharedSecretChallengeResponse_s* x )
{
  struct zx_ns_s* pop_seen = 0;
  struct zx_elem_s* se MAYBE_UNUSED;
#if 1 /* NORMALMODE */
  /* *** in simple_elem case should output ns prefix from ns node. */
  int len = sizeof("<ac:SharedSecretChallengeResponse")-1 + 1 + sizeof("</ac:SharedSecretChallengeResponse>")-1;
  if (c->inc_ns_len)
    len += zx_len_inc_ns(c, &pop_seen);
  len += zx_len_xmlns_if_not_seen(c, zx_ns_tab+zx_xmlns_ix_ac, &pop_seen);


#else
  /* root node has no begin tag */
  int len = 0;
#endif
  
  {
      struct zx_ac_Extension_s* e;
      for (e = x->Extension; e; e = (struct zx_ac_Extension_s*)e->gg.g.n)
	  len += zx_LEN_SO_ac_Extension(c, e);
  }


  len += zx_len_so_common(c, &x->gg);
  zx_pop_seen(pop_seen);
  ENC_LEN_DEBUG(x, "ac:SharedSecretChallengeResponse", len);
  return len;
}

/* FUNC(zx_LEN_WO_ac_SharedSecretChallengeResponse) */

/* Compute length of an element (and its subelements). The XML attributes
 * and elements are processed in wire order and no assumptions
 * are made about namespace prefixes. */

/* Called by: */
int zx_LEN_WO_ac_SharedSecretChallengeResponse(struct zx_ctx* c, struct zx_ac_SharedSecretChallengeResponse_s* x )
{
  struct zx_ns_s* pop_seen = 0;
  struct zx_elem_s* se MAYBE_UNUSED;
#if 1 /* NORMALMODE */
  int len = 1 + sizeof("SharedSecretChallengeResponse")-1 + 1 + 2 + sizeof("SharedSecretChallengeResponse")-1 + 1;
  
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
      struct zx_ac_Extension_s* e;
      for (e = x->Extension; e; e = (struct zx_ac_Extension_s*)e->gg.g.n)
	  len += zx_LEN_WO_ac_Extension(c, e);
  }


  len += zx_len_wo_common(c, &x->gg); 
  zx_pop_seen(pop_seen);
  ENC_LEN_DEBUG(x, "ac:SharedSecretChallengeResponse", len);
  return len;
}

/* FUNC(zx_ENC_SO_ac_SharedSecretChallengeResponse) */

/* Render element into string. The XML attributes and elements are
 * processed in schema order. This is what you generally want for
 * rendering new data structure to a string. The wo pointers are not used. */

/* Called by: */
char* zx_ENC_SO_ac_SharedSecretChallengeResponse(struct zx_ctx* c, struct zx_ac_SharedSecretChallengeResponse_s* x, char* p )
{
  struct zx_elem_s* se MAYBE_UNUSED;
  ENC_LEN_DEBUG_BASE;
#if 1 /* NORMALMODE */
  struct zx_ns_s* pop_seen = 0;
  /* *** in simple_elem case should output ns prefix from ns node. */
  ZX_OUT_TAG(p, "<ac:SharedSecretChallengeResponse");
  if (c->inc_ns)
    p = zx_enc_inc_ns(c, p, &pop_seen);
  p = zx_enc_xmlns_if_not_seen(c, p, zx_ns_tab+zx_xmlns_ix_ac, &pop_seen);


  p = zx_enc_unknown_attrs(p, x->gg.any_attr);
#else
  /* root node has no begin tag */
#endif
  
  {
      struct zx_ac_Extension_s* e;
      for (e = x->Extension; e; e = (struct zx_ac_Extension_s*)e->gg.g.n)
	  p = zx_ENC_SO_ac_Extension(c, e, p);
  }

  p = zx_enc_so_unknown_elems_and_content(c, p, &x->gg);
  
#if 1 /* NORMALMODE */
  ZX_OUT_CLOSE_TAG(p, "</ac:SharedSecretChallengeResponse>");
  zx_pop_seen(pop_seen);
#else
  /* root node has no end tag either */
#endif
  ENC_LEN_DEBUG(x, "ac:SharedSecretChallengeResponse", p-enc_base);
  return p;
}

/* FUNC(zx_ENC_WO_ac_SharedSecretChallengeResponse) */

/* Render element into string. The XML attributes and elements are
 * processed in wire order by chasing wo pointers. This is what you want for
 * validating signatures on other people's XML documents. */

/* Called by: */
char* zx_ENC_WO_ac_SharedSecretChallengeResponse(struct zx_ctx* c, struct zx_ac_SharedSecretChallengeResponse_s* x, char* p )
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
  ZX_OUT_MEM(p, "SharedSecretChallengeResponse", sizeof("SharedSecretChallengeResponse")-1);
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
  ENC_LEN_DEBUG(x, "ac:SharedSecretChallengeResponse", p-enc_base);
  return p;
}

/* FUNC(zx_EASY_ENC_SO_ac_SharedSecretChallengeResponse) */

/* Called by: */
struct zx_str* zx_EASY_ENC_SO_ac_SharedSecretChallengeResponse(struct zx_ctx* c, struct zx_ac_SharedSecretChallengeResponse_s* x )
{
  int len;
  char* buf;
  c->ns_tab = ZX_ALLOC(c, sizeof(zx_ns_tab));
  memcpy(c->ns_tab, zx_ns_tab, sizeof(zx_ns_tab));
  len = zx_LEN_SO_ac_SharedSecretChallengeResponse(c, x );
  buf = ZX_ALLOC(c, len+1);
  return zx_easy_enc_common(c, zx_ENC_SO_ac_SharedSecretChallengeResponse(c, x, buf ), buf, len);
}

/* FUNC(zx_EASY_ENC_WO_ac_SharedSecretChallengeResponse) */

/* Called by: */
struct zx_str* zx_EASY_ENC_WO_ac_SharedSecretChallengeResponse(struct zx_ctx* c, struct zx_ac_SharedSecretChallengeResponse_s* x )
{
  int len;
  char* buf;
  c->ns_tab = ZX_ALLOC(c, sizeof(zx_ns_tab));
  memcpy(c->ns_tab, zx_ns_tab, sizeof(zx_ns_tab));
  len = zx_LEN_WO_ac_SharedSecretChallengeResponse(c, x );
  buf = ZX_ALLOC(c, len+1);
  return zx_easy_enc_common(c, zx_ENC_WO_ac_SharedSecretChallengeResponse(c, x, buf ), buf, len);
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

#define EL_NAME   ac_SharedSecretDynamicPlaintext
#define EL_STRUCT zx_ac_SharedSecretDynamicPlaintext_s
#define EL_NS     ac
#define EL_TAG    SharedSecretDynamicPlaintext

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

/* FUNC(zx_LEN_SO_ac_SharedSecretDynamicPlaintext) */

/* Compute length of an element (and its subelements). The XML attributes
 * and elements are processed in schema order. */

/* Called by: */
int zx_LEN_SO_ac_SharedSecretDynamicPlaintext(struct zx_ctx* c, struct zx_ac_SharedSecretDynamicPlaintext_s* x )
{
  struct zx_ns_s* pop_seen = 0;
  struct zx_elem_s* se MAYBE_UNUSED;
#if 1 /* NORMALMODE */
  /* *** in simple_elem case should output ns prefix from ns node. */
  int len = sizeof("<ac:SharedSecretDynamicPlaintext")-1 + 1 + sizeof("</ac:SharedSecretDynamicPlaintext>")-1;
  if (c->inc_ns_len)
    len += zx_len_inc_ns(c, &pop_seen);
  len += zx_len_xmlns_if_not_seen(c, zx_ns_tab+zx_xmlns_ix_ac, &pop_seen);


#else
  /* root node has no begin tag */
  int len = 0;
#endif
  
  {
      struct zx_ac_Extension_s* e;
      for (e = x->Extension; e; e = (struct zx_ac_Extension_s*)e->gg.g.n)
	  len += zx_LEN_SO_ac_Extension(c, e);
  }


  len += zx_len_so_common(c, &x->gg);
  zx_pop_seen(pop_seen);
  ENC_LEN_DEBUG(x, "ac:SharedSecretDynamicPlaintext", len);
  return len;
}

/* FUNC(zx_LEN_WO_ac_SharedSecretDynamicPlaintext) */

/* Compute length of an element (and its subelements). The XML attributes
 * and elements are processed in wire order and no assumptions
 * are made about namespace prefixes. */

/* Called by: */
int zx_LEN_WO_ac_SharedSecretDynamicPlaintext(struct zx_ctx* c, struct zx_ac_SharedSecretDynamicPlaintext_s* x )
{
  struct zx_ns_s* pop_seen = 0;
  struct zx_elem_s* se MAYBE_UNUSED;
#if 1 /* NORMALMODE */
  int len = 1 + sizeof("SharedSecretDynamicPlaintext")-1 + 1 + 2 + sizeof("SharedSecretDynamicPlaintext")-1 + 1;
  
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
      struct zx_ac_Extension_s* e;
      for (e = x->Extension; e; e = (struct zx_ac_Extension_s*)e->gg.g.n)
	  len += zx_LEN_WO_ac_Extension(c, e);
  }


  len += zx_len_wo_common(c, &x->gg); 
  zx_pop_seen(pop_seen);
  ENC_LEN_DEBUG(x, "ac:SharedSecretDynamicPlaintext", len);
  return len;
}

/* FUNC(zx_ENC_SO_ac_SharedSecretDynamicPlaintext) */

/* Render element into string. The XML attributes and elements are
 * processed in schema order. This is what you generally want for
 * rendering new data structure to a string. The wo pointers are not used. */

/* Called by: */
char* zx_ENC_SO_ac_SharedSecretDynamicPlaintext(struct zx_ctx* c, struct zx_ac_SharedSecretDynamicPlaintext_s* x, char* p )
{
  struct zx_elem_s* se MAYBE_UNUSED;
  ENC_LEN_DEBUG_BASE;
#if 1 /* NORMALMODE */
  struct zx_ns_s* pop_seen = 0;
  /* *** in simple_elem case should output ns prefix from ns node. */
  ZX_OUT_TAG(p, "<ac:SharedSecretDynamicPlaintext");
  if (c->inc_ns)
    p = zx_enc_inc_ns(c, p, &pop_seen);
  p = zx_enc_xmlns_if_not_seen(c, p, zx_ns_tab+zx_xmlns_ix_ac, &pop_seen);


  p = zx_enc_unknown_attrs(p, x->gg.any_attr);
#else
  /* root node has no begin tag */
#endif
  
  {
      struct zx_ac_Extension_s* e;
      for (e = x->Extension; e; e = (struct zx_ac_Extension_s*)e->gg.g.n)
	  p = zx_ENC_SO_ac_Extension(c, e, p);
  }

  p = zx_enc_so_unknown_elems_and_content(c, p, &x->gg);
  
#if 1 /* NORMALMODE */
  ZX_OUT_CLOSE_TAG(p, "</ac:SharedSecretDynamicPlaintext>");
  zx_pop_seen(pop_seen);
#else
  /* root node has no end tag either */
#endif
  ENC_LEN_DEBUG(x, "ac:SharedSecretDynamicPlaintext", p-enc_base);
  return p;
}

/* FUNC(zx_ENC_WO_ac_SharedSecretDynamicPlaintext) */

/* Render element into string. The XML attributes and elements are
 * processed in wire order by chasing wo pointers. This is what you want for
 * validating signatures on other people's XML documents. */

/* Called by: */
char* zx_ENC_WO_ac_SharedSecretDynamicPlaintext(struct zx_ctx* c, struct zx_ac_SharedSecretDynamicPlaintext_s* x, char* p )
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
  ZX_OUT_MEM(p, "SharedSecretDynamicPlaintext", sizeof("SharedSecretDynamicPlaintext")-1);
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
  ENC_LEN_DEBUG(x, "ac:SharedSecretDynamicPlaintext", p-enc_base);
  return p;
}

/* FUNC(zx_EASY_ENC_SO_ac_SharedSecretDynamicPlaintext) */

/* Called by: */
struct zx_str* zx_EASY_ENC_SO_ac_SharedSecretDynamicPlaintext(struct zx_ctx* c, struct zx_ac_SharedSecretDynamicPlaintext_s* x )
{
  int len;
  char* buf;
  c->ns_tab = ZX_ALLOC(c, sizeof(zx_ns_tab));
  memcpy(c->ns_tab, zx_ns_tab, sizeof(zx_ns_tab));
  len = zx_LEN_SO_ac_SharedSecretDynamicPlaintext(c, x );
  buf = ZX_ALLOC(c, len+1);
  return zx_easy_enc_common(c, zx_ENC_SO_ac_SharedSecretDynamicPlaintext(c, x, buf ), buf, len);
}

/* FUNC(zx_EASY_ENC_WO_ac_SharedSecretDynamicPlaintext) */

/* Called by: */
struct zx_str* zx_EASY_ENC_WO_ac_SharedSecretDynamicPlaintext(struct zx_ctx* c, struct zx_ac_SharedSecretDynamicPlaintext_s* x )
{
  int len;
  char* buf;
  c->ns_tab = ZX_ALLOC(c, sizeof(zx_ns_tab));
  memcpy(c->ns_tab, zx_ns_tab, sizeof(zx_ns_tab));
  len = zx_LEN_WO_ac_SharedSecretDynamicPlaintext(c, x );
  buf = ZX_ALLOC(c, len+1);
  return zx_easy_enc_common(c, zx_ENC_WO_ac_SharedSecretDynamicPlaintext(c, x, buf ), buf, len);
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

#define EL_NAME   ac_Smartcard
#define EL_STRUCT zx_ac_Smartcard_s
#define EL_NS     ac
#define EL_TAG    Smartcard

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

/* FUNC(zx_LEN_SO_ac_Smartcard) */

/* Compute length of an element (and its subelements). The XML attributes
 * and elements are processed in schema order. */

/* Called by: */
int zx_LEN_SO_ac_Smartcard(struct zx_ctx* c, struct zx_ac_Smartcard_s* x )
{
  struct zx_ns_s* pop_seen = 0;
  struct zx_elem_s* se MAYBE_UNUSED;
#if 1 /* NORMALMODE */
  /* *** in simple_elem case should output ns prefix from ns node. */
  int len = sizeof("<ac:Smartcard")-1 + 1 + sizeof("</ac:Smartcard>")-1;
  if (c->inc_ns_len)
    len += zx_len_inc_ns(c, &pop_seen);
  len += zx_len_xmlns_if_not_seen(c, zx_ns_tab+zx_xmlns_ix_ac, &pop_seen);


#else
  /* root node has no begin tag */
  int len = 0;
#endif
  
  {
      struct zx_ac_Extension_s* e;
      for (e = x->Extension; e; e = (struct zx_ac_Extension_s*)e->gg.g.n)
	  len += zx_LEN_SO_ac_Extension(c, e);
  }


  len += zx_len_so_common(c, &x->gg);
  zx_pop_seen(pop_seen);
  ENC_LEN_DEBUG(x, "ac:Smartcard", len);
  return len;
}

/* FUNC(zx_LEN_WO_ac_Smartcard) */

/* Compute length of an element (and its subelements). The XML attributes
 * and elements are processed in wire order and no assumptions
 * are made about namespace prefixes. */

/* Called by: */
int zx_LEN_WO_ac_Smartcard(struct zx_ctx* c, struct zx_ac_Smartcard_s* x )
{
  struct zx_ns_s* pop_seen = 0;
  struct zx_elem_s* se MAYBE_UNUSED;
#if 1 /* NORMALMODE */
  int len = 1 + sizeof("Smartcard")-1 + 1 + 2 + sizeof("Smartcard")-1 + 1;
  
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
      struct zx_ac_Extension_s* e;
      for (e = x->Extension; e; e = (struct zx_ac_Extension_s*)e->gg.g.n)
	  len += zx_LEN_WO_ac_Extension(c, e);
  }


  len += zx_len_wo_common(c, &x->gg); 
  zx_pop_seen(pop_seen);
  ENC_LEN_DEBUG(x, "ac:Smartcard", len);
  return len;
}

/* FUNC(zx_ENC_SO_ac_Smartcard) */

/* Render element into string. The XML attributes and elements are
 * processed in schema order. This is what you generally want for
 * rendering new data structure to a string. The wo pointers are not used. */

/* Called by: */
char* zx_ENC_SO_ac_Smartcard(struct zx_ctx* c, struct zx_ac_Smartcard_s* x, char* p )
{
  struct zx_elem_s* se MAYBE_UNUSED;
  ENC_LEN_DEBUG_BASE;
#if 1 /* NORMALMODE */
  struct zx_ns_s* pop_seen = 0;
  /* *** in simple_elem case should output ns prefix from ns node. */
  ZX_OUT_TAG(p, "<ac:Smartcard");
  if (c->inc_ns)
    p = zx_enc_inc_ns(c, p, &pop_seen);
  p = zx_enc_xmlns_if_not_seen(c, p, zx_ns_tab+zx_xmlns_ix_ac, &pop_seen);


  p = zx_enc_unknown_attrs(p, x->gg.any_attr);
#else
  /* root node has no begin tag */
#endif
  
  {
      struct zx_ac_Extension_s* e;
      for (e = x->Extension; e; e = (struct zx_ac_Extension_s*)e->gg.g.n)
	  p = zx_ENC_SO_ac_Extension(c, e, p);
  }

  p = zx_enc_so_unknown_elems_and_content(c, p, &x->gg);
  
#if 1 /* NORMALMODE */
  ZX_OUT_CLOSE_TAG(p, "</ac:Smartcard>");
  zx_pop_seen(pop_seen);
#else
  /* root node has no end tag either */
#endif
  ENC_LEN_DEBUG(x, "ac:Smartcard", p-enc_base);
  return p;
}

/* FUNC(zx_ENC_WO_ac_Smartcard) */

/* Render element into string. The XML attributes and elements are
 * processed in wire order by chasing wo pointers. This is what you want for
 * validating signatures on other people's XML documents. */

/* Called by: */
char* zx_ENC_WO_ac_Smartcard(struct zx_ctx* c, struct zx_ac_Smartcard_s* x, char* p )
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
  ZX_OUT_MEM(p, "Smartcard", sizeof("Smartcard")-1);
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
  ENC_LEN_DEBUG(x, "ac:Smartcard", p-enc_base);
  return p;
}

/* FUNC(zx_EASY_ENC_SO_ac_Smartcard) */

/* Called by: */
struct zx_str* zx_EASY_ENC_SO_ac_Smartcard(struct zx_ctx* c, struct zx_ac_Smartcard_s* x )
{
  int len;
  char* buf;
  c->ns_tab = ZX_ALLOC(c, sizeof(zx_ns_tab));
  memcpy(c->ns_tab, zx_ns_tab, sizeof(zx_ns_tab));
  len = zx_LEN_SO_ac_Smartcard(c, x );
  buf = ZX_ALLOC(c, len+1);
  return zx_easy_enc_common(c, zx_ENC_SO_ac_Smartcard(c, x, buf ), buf, len);
}

/* FUNC(zx_EASY_ENC_WO_ac_Smartcard) */

/* Called by: */
struct zx_str* zx_EASY_ENC_WO_ac_Smartcard(struct zx_ctx* c, struct zx_ac_Smartcard_s* x )
{
  int len;
  char* buf;
  c->ns_tab = ZX_ALLOC(c, sizeof(zx_ns_tab));
  memcpy(c->ns_tab, zx_ns_tab, sizeof(zx_ns_tab));
  len = zx_LEN_WO_ac_Smartcard(c, x );
  buf = ZX_ALLOC(c, len+1);
  return zx_easy_enc_common(c, zx_ENC_WO_ac_Smartcard(c, x, buf ), buf, len);
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

#define EL_NAME   ac_SwitchAudit
#define EL_STRUCT zx_ac_SwitchAudit_s
#define EL_NS     ac
#define EL_TAG    SwitchAudit

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

/* FUNC(zx_LEN_SO_ac_SwitchAudit) */

/* Compute length of an element (and its subelements). The XML attributes
 * and elements are processed in schema order. */

/* Called by: */
int zx_LEN_SO_ac_SwitchAudit(struct zx_ctx* c, struct zx_ac_SwitchAudit_s* x )
{
  struct zx_ns_s* pop_seen = 0;
  struct zx_elem_s* se MAYBE_UNUSED;
#if 1 /* NORMALMODE */
  /* *** in simple_elem case should output ns prefix from ns node. */
  int len = sizeof("<ac:SwitchAudit")-1 + 1 + sizeof("</ac:SwitchAudit>")-1;
  if (c->inc_ns_len)
    len += zx_len_inc_ns(c, &pop_seen);
  len += zx_len_xmlns_if_not_seen(c, zx_ns_tab+zx_xmlns_ix_ac, &pop_seen);


#else
  /* root node has no begin tag */
  int len = 0;
#endif
  
  {
      struct zx_ac_Extension_s* e;
      for (e = x->Extension; e; e = (struct zx_ac_Extension_s*)e->gg.g.n)
	  len += zx_LEN_SO_ac_Extension(c, e);
  }


  len += zx_len_so_common(c, &x->gg);
  zx_pop_seen(pop_seen);
  ENC_LEN_DEBUG(x, "ac:SwitchAudit", len);
  return len;
}

/* FUNC(zx_LEN_WO_ac_SwitchAudit) */

/* Compute length of an element (and its subelements). The XML attributes
 * and elements are processed in wire order and no assumptions
 * are made about namespace prefixes. */

/* Called by: */
int zx_LEN_WO_ac_SwitchAudit(struct zx_ctx* c, struct zx_ac_SwitchAudit_s* x )
{
  struct zx_ns_s* pop_seen = 0;
  struct zx_elem_s* se MAYBE_UNUSED;
#if 1 /* NORMALMODE */
  int len = 1 + sizeof("SwitchAudit")-1 + 1 + 2 + sizeof("SwitchAudit")-1 + 1;
  
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
      struct zx_ac_Extension_s* e;
      for (e = x->Extension; e; e = (struct zx_ac_Extension_s*)e->gg.g.n)
	  len += zx_LEN_WO_ac_Extension(c, e);
  }


  len += zx_len_wo_common(c, &x->gg); 
  zx_pop_seen(pop_seen);
  ENC_LEN_DEBUG(x, "ac:SwitchAudit", len);
  return len;
}

/* FUNC(zx_ENC_SO_ac_SwitchAudit) */

/* Render element into string. The XML attributes and elements are
 * processed in schema order. This is what you generally want for
 * rendering new data structure to a string. The wo pointers are not used. */

/* Called by: */
char* zx_ENC_SO_ac_SwitchAudit(struct zx_ctx* c, struct zx_ac_SwitchAudit_s* x, char* p )
{
  struct zx_elem_s* se MAYBE_UNUSED;
  ENC_LEN_DEBUG_BASE;
#if 1 /* NORMALMODE */
  struct zx_ns_s* pop_seen = 0;
  /* *** in simple_elem case should output ns prefix from ns node. */
  ZX_OUT_TAG(p, "<ac:SwitchAudit");
  if (c->inc_ns)
    p = zx_enc_inc_ns(c, p, &pop_seen);
  p = zx_enc_xmlns_if_not_seen(c, p, zx_ns_tab+zx_xmlns_ix_ac, &pop_seen);


  p = zx_enc_unknown_attrs(p, x->gg.any_attr);
#else
  /* root node has no begin tag */
#endif
  
  {
      struct zx_ac_Extension_s* e;
      for (e = x->Extension; e; e = (struct zx_ac_Extension_s*)e->gg.g.n)
	  p = zx_ENC_SO_ac_Extension(c, e, p);
  }

  p = zx_enc_so_unknown_elems_and_content(c, p, &x->gg);
  
#if 1 /* NORMALMODE */
  ZX_OUT_CLOSE_TAG(p, "</ac:SwitchAudit>");
  zx_pop_seen(pop_seen);
#else
  /* root node has no end tag either */
#endif
  ENC_LEN_DEBUG(x, "ac:SwitchAudit", p-enc_base);
  return p;
}

/* FUNC(zx_ENC_WO_ac_SwitchAudit) */

/* Render element into string. The XML attributes and elements are
 * processed in wire order by chasing wo pointers. This is what you want for
 * validating signatures on other people's XML documents. */

/* Called by: */
char* zx_ENC_WO_ac_SwitchAudit(struct zx_ctx* c, struct zx_ac_SwitchAudit_s* x, char* p )
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
  ZX_OUT_MEM(p, "SwitchAudit", sizeof("SwitchAudit")-1);
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
  ENC_LEN_DEBUG(x, "ac:SwitchAudit", p-enc_base);
  return p;
}

/* FUNC(zx_EASY_ENC_SO_ac_SwitchAudit) */

/* Called by: */
struct zx_str* zx_EASY_ENC_SO_ac_SwitchAudit(struct zx_ctx* c, struct zx_ac_SwitchAudit_s* x )
{
  int len;
  char* buf;
  c->ns_tab = ZX_ALLOC(c, sizeof(zx_ns_tab));
  memcpy(c->ns_tab, zx_ns_tab, sizeof(zx_ns_tab));
  len = zx_LEN_SO_ac_SwitchAudit(c, x );
  buf = ZX_ALLOC(c, len+1);
  return zx_easy_enc_common(c, zx_ENC_SO_ac_SwitchAudit(c, x, buf ), buf, len);
}

/* FUNC(zx_EASY_ENC_WO_ac_SwitchAudit) */

/* Called by: */
struct zx_str* zx_EASY_ENC_WO_ac_SwitchAudit(struct zx_ctx* c, struct zx_ac_SwitchAudit_s* x )
{
  int len;
  char* buf;
  c->ns_tab = ZX_ALLOC(c, sizeof(zx_ns_tab));
  memcpy(c->ns_tab, zx_ns_tab, sizeof(zx_ns_tab));
  len = zx_LEN_WO_ac_SwitchAudit(c, x );
  buf = ZX_ALLOC(c, len+1);
  return zx_easy_enc_common(c, zx_ENC_WO_ac_SwitchAudit(c, x, buf ), buf, len);
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

#define EL_NAME   ac_TechnicalProtection
#define EL_STRUCT zx_ac_TechnicalProtection_s
#define EL_NS     ac
#define EL_TAG    TechnicalProtection

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

/* FUNC(zx_LEN_SO_ac_TechnicalProtection) */

/* Compute length of an element (and its subelements). The XML attributes
 * and elements are processed in schema order. */

/* Called by: */
int zx_LEN_SO_ac_TechnicalProtection(struct zx_ctx* c, struct zx_ac_TechnicalProtection_s* x )
{
  struct zx_ns_s* pop_seen = 0;
  struct zx_elem_s* se MAYBE_UNUSED;
#if 1 /* NORMALMODE */
  /* *** in simple_elem case should output ns prefix from ns node. */
  int len = sizeof("<ac:TechnicalProtection")-1 + 1 + sizeof("</ac:TechnicalProtection>")-1;
  if (c->inc_ns_len)
    len += zx_len_inc_ns(c, &pop_seen);
  len += zx_len_xmlns_if_not_seen(c, zx_ns_tab+zx_xmlns_ix_ac, &pop_seen);


#else
  /* root node has no begin tag */
  int len = 0;
#endif
  
  {
      struct zx_ac_PrivateKeyProtection_s* e;
      for (e = x->PrivateKeyProtection; e; e = (struct zx_ac_PrivateKeyProtection_s*)e->gg.g.n)
	  len += zx_LEN_SO_ac_PrivateKeyProtection(c, e);
  }
  {
      struct zx_ac_SecretKeyProtection_s* e;
      for (e = x->SecretKeyProtection; e; e = (struct zx_ac_SecretKeyProtection_s*)e->gg.g.n)
	  len += zx_LEN_SO_ac_SecretKeyProtection(c, e);
  }
  {
      struct zx_ac_Extension_s* e;
      for (e = x->Extension; e; e = (struct zx_ac_Extension_s*)e->gg.g.n)
	  len += zx_LEN_SO_ac_Extension(c, e);
  }


  len += zx_len_so_common(c, &x->gg);
  zx_pop_seen(pop_seen);
  ENC_LEN_DEBUG(x, "ac:TechnicalProtection", len);
  return len;
}

/* FUNC(zx_LEN_WO_ac_TechnicalProtection) */

/* Compute length of an element (and its subelements). The XML attributes
 * and elements are processed in wire order and no assumptions
 * are made about namespace prefixes. */

/* Called by: */
int zx_LEN_WO_ac_TechnicalProtection(struct zx_ctx* c, struct zx_ac_TechnicalProtection_s* x )
{
  struct zx_ns_s* pop_seen = 0;
  struct zx_elem_s* se MAYBE_UNUSED;
#if 1 /* NORMALMODE */
  int len = 1 + sizeof("TechnicalProtection")-1 + 1 + 2 + sizeof("TechnicalProtection")-1 + 1;
  
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
      struct zx_ac_PrivateKeyProtection_s* e;
      for (e = x->PrivateKeyProtection; e; e = (struct zx_ac_PrivateKeyProtection_s*)e->gg.g.n)
	  len += zx_LEN_WO_ac_PrivateKeyProtection(c, e);
  }
  {
      struct zx_ac_SecretKeyProtection_s* e;
      for (e = x->SecretKeyProtection; e; e = (struct zx_ac_SecretKeyProtection_s*)e->gg.g.n)
	  len += zx_LEN_WO_ac_SecretKeyProtection(c, e);
  }
  {
      struct zx_ac_Extension_s* e;
      for (e = x->Extension; e; e = (struct zx_ac_Extension_s*)e->gg.g.n)
	  len += zx_LEN_WO_ac_Extension(c, e);
  }


  len += zx_len_wo_common(c, &x->gg); 
  zx_pop_seen(pop_seen);
  ENC_LEN_DEBUG(x, "ac:TechnicalProtection", len);
  return len;
}

/* FUNC(zx_ENC_SO_ac_TechnicalProtection) */

/* Render element into string. The XML attributes and elements are
 * processed in schema order. This is what you generally want for
 * rendering new data structure to a string. The wo pointers are not used. */

/* Called by: */
char* zx_ENC_SO_ac_TechnicalProtection(struct zx_ctx* c, struct zx_ac_TechnicalProtection_s* x, char* p )
{
  struct zx_elem_s* se MAYBE_UNUSED;
  ENC_LEN_DEBUG_BASE;
#if 1 /* NORMALMODE */
  struct zx_ns_s* pop_seen = 0;
  /* *** in simple_elem case should output ns prefix from ns node. */
  ZX_OUT_TAG(p, "<ac:TechnicalProtection");
  if (c->inc_ns)
    p = zx_enc_inc_ns(c, p, &pop_seen);
  p = zx_enc_xmlns_if_not_seen(c, p, zx_ns_tab+zx_xmlns_ix_ac, &pop_seen);


  p = zx_enc_unknown_attrs(p, x->gg.any_attr);
#else
  /* root node has no begin tag */
#endif
  
  {
      struct zx_ac_PrivateKeyProtection_s* e;
      for (e = x->PrivateKeyProtection; e; e = (struct zx_ac_PrivateKeyProtection_s*)e->gg.g.n)
	  p = zx_ENC_SO_ac_PrivateKeyProtection(c, e, p);
  }
  {
      struct zx_ac_SecretKeyProtection_s* e;
      for (e = x->SecretKeyProtection; e; e = (struct zx_ac_SecretKeyProtection_s*)e->gg.g.n)
	  p = zx_ENC_SO_ac_SecretKeyProtection(c, e, p);
  }
  {
      struct zx_ac_Extension_s* e;
      for (e = x->Extension; e; e = (struct zx_ac_Extension_s*)e->gg.g.n)
	  p = zx_ENC_SO_ac_Extension(c, e, p);
  }

  p = zx_enc_so_unknown_elems_and_content(c, p, &x->gg);
  
#if 1 /* NORMALMODE */
  ZX_OUT_CLOSE_TAG(p, "</ac:TechnicalProtection>");
  zx_pop_seen(pop_seen);
#else
  /* root node has no end tag either */
#endif
  ENC_LEN_DEBUG(x, "ac:TechnicalProtection", p-enc_base);
  return p;
}

/* FUNC(zx_ENC_WO_ac_TechnicalProtection) */

/* Render element into string. The XML attributes and elements are
 * processed in wire order by chasing wo pointers. This is what you want for
 * validating signatures on other people's XML documents. */

/* Called by: */
char* zx_ENC_WO_ac_TechnicalProtection(struct zx_ctx* c, struct zx_ac_TechnicalProtection_s* x, char* p )
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
  ZX_OUT_MEM(p, "TechnicalProtection", sizeof("TechnicalProtection")-1);
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
  ENC_LEN_DEBUG(x, "ac:TechnicalProtection", p-enc_base);
  return p;
}

/* FUNC(zx_EASY_ENC_SO_ac_TechnicalProtection) */

/* Called by: */
struct zx_str* zx_EASY_ENC_SO_ac_TechnicalProtection(struct zx_ctx* c, struct zx_ac_TechnicalProtection_s* x )
{
  int len;
  char* buf;
  c->ns_tab = ZX_ALLOC(c, sizeof(zx_ns_tab));
  memcpy(c->ns_tab, zx_ns_tab, sizeof(zx_ns_tab));
  len = zx_LEN_SO_ac_TechnicalProtection(c, x );
  buf = ZX_ALLOC(c, len+1);
  return zx_easy_enc_common(c, zx_ENC_SO_ac_TechnicalProtection(c, x, buf ), buf, len);
}

/* FUNC(zx_EASY_ENC_WO_ac_TechnicalProtection) */

/* Called by: */
struct zx_str* zx_EASY_ENC_WO_ac_TechnicalProtection(struct zx_ctx* c, struct zx_ac_TechnicalProtection_s* x )
{
  int len;
  char* buf;
  c->ns_tab = ZX_ALLOC(c, sizeof(zx_ns_tab));
  memcpy(c->ns_tab, zx_ns_tab, sizeof(zx_ns_tab));
  len = zx_LEN_WO_ac_TechnicalProtection(c, x );
  buf = ZX_ALLOC(c, len+1);
  return zx_easy_enc_common(c, zx_ENC_WO_ac_TechnicalProtection(c, x, buf ), buf, len);
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

#define EL_NAME   ac_TimeSyncToken
#define EL_STRUCT zx_ac_TimeSyncToken_s
#define EL_NS     ac
#define EL_TAG    TimeSyncToken

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

/* FUNC(zx_LEN_SO_ac_TimeSyncToken) */

/* Compute length of an element (and its subelements). The XML attributes
 * and elements are processed in schema order. */

/* Called by: */
int zx_LEN_SO_ac_TimeSyncToken(struct zx_ctx* c, struct zx_ac_TimeSyncToken_s* x )
{
  struct zx_ns_s* pop_seen = 0;
  struct zx_elem_s* se MAYBE_UNUSED;
#if 1 /* NORMALMODE */
  /* *** in simple_elem case should output ns prefix from ns node. */
  int len = sizeof("<ac:TimeSyncToken")-1 + 1 + sizeof("</ac:TimeSyncToken>")-1;
  if (c->inc_ns_len)
    len += zx_len_inc_ns(c, &pop_seen);
  len += zx_len_xmlns_if_not_seen(c, zx_ns_tab+zx_xmlns_ix_ac, &pop_seen);

  len += zx_attr_so_len(x->DeviceInHand, sizeof("DeviceInHand")-1);
  len += zx_attr_so_len(x->DeviceType, sizeof("DeviceType")-1);
  len += zx_attr_so_len(x->SeedLength, sizeof("SeedLength")-1);

#else
  /* root node has no begin tag */
  int len = 0;
#endif
  


  len += zx_len_so_common(c, &x->gg);
  zx_pop_seen(pop_seen);
  ENC_LEN_DEBUG(x, "ac:TimeSyncToken", len);
  return len;
}

/* FUNC(zx_LEN_WO_ac_TimeSyncToken) */

/* Compute length of an element (and its subelements). The XML attributes
 * and elements are processed in wire order and no assumptions
 * are made about namespace prefixes. */

/* Called by: */
int zx_LEN_WO_ac_TimeSyncToken(struct zx_ctx* c, struct zx_ac_TimeSyncToken_s* x )
{
  struct zx_ns_s* pop_seen = 0;
  struct zx_elem_s* se MAYBE_UNUSED;
#if 1 /* NORMALMODE */
  int len = 1 + sizeof("TimeSyncToken")-1 + 1 + 2 + sizeof("TimeSyncToken")-1 + 1;
  
  if (x->gg.g.ns && x->gg.g.ns->prefix_len)
    len += (x->gg.g.ns->prefix_len + 1) * 2;
  if (c->inc_ns_len)
    len += zx_len_inc_ns(c, &pop_seen);
  len += zx_len_xmlns_if_not_seen(c, x->gg.g.ns, &pop_seen);

  len += zx_attr_wo_len(x->DeviceInHand, sizeof("DeviceInHand")-1);
  len += zx_attr_wo_len(x->DeviceType, sizeof("DeviceType")-1);
  len += zx_attr_wo_len(x->SeedLength, sizeof("SeedLength")-1);

#else
  /* root node has no begin tag */
  int len = 0;
#endif
  


  len += zx_len_wo_common(c, &x->gg); 
  zx_pop_seen(pop_seen);
  ENC_LEN_DEBUG(x, "ac:TimeSyncToken", len);
  return len;
}

/* FUNC(zx_ENC_SO_ac_TimeSyncToken) */

/* Render element into string. The XML attributes and elements are
 * processed in schema order. This is what you generally want for
 * rendering new data structure to a string. The wo pointers are not used. */

/* Called by: */
char* zx_ENC_SO_ac_TimeSyncToken(struct zx_ctx* c, struct zx_ac_TimeSyncToken_s* x, char* p )
{
  struct zx_elem_s* se MAYBE_UNUSED;
  ENC_LEN_DEBUG_BASE;
#if 1 /* NORMALMODE */
  struct zx_ns_s* pop_seen = 0;
  /* *** in simple_elem case should output ns prefix from ns node. */
  ZX_OUT_TAG(p, "<ac:TimeSyncToken");
  if (c->inc_ns)
    p = zx_enc_inc_ns(c, p, &pop_seen);
  p = zx_enc_xmlns_if_not_seen(c, p, zx_ns_tab+zx_xmlns_ix_ac, &pop_seen);

  p = zx_attr_so_enc(p, x->DeviceInHand, " DeviceInHand=\"", sizeof(" DeviceInHand=\"")-1);
  p = zx_attr_so_enc(p, x->DeviceType, " DeviceType=\"", sizeof(" DeviceType=\"")-1);
  p = zx_attr_so_enc(p, x->SeedLength, " SeedLength=\"", sizeof(" SeedLength=\"")-1);

  p = zx_enc_unknown_attrs(p, x->gg.any_attr);
#else
  /* root node has no begin tag */
#endif
  

  p = zx_enc_so_unknown_elems_and_content(c, p, &x->gg);
  
#if 1 /* NORMALMODE */
  ZX_OUT_CLOSE_TAG(p, "</ac:TimeSyncToken>");
  zx_pop_seen(pop_seen);
#else
  /* root node has no end tag either */
#endif
  ENC_LEN_DEBUG(x, "ac:TimeSyncToken", p-enc_base);
  return p;
}

/* FUNC(zx_ENC_WO_ac_TimeSyncToken) */

/* Render element into string. The XML attributes and elements are
 * processed in wire order by chasing wo pointers. This is what you want for
 * validating signatures on other people's XML documents. */

/* Called by: */
char* zx_ENC_WO_ac_TimeSyncToken(struct zx_ctx* c, struct zx_ac_TimeSyncToken_s* x, char* p )
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
  ZX_OUT_MEM(p, "TimeSyncToken", sizeof("TimeSyncToken")-1);
  qq = p;

  /* *** sort the namespaces */
  if (c->inc_ns)
    zx_add_inc_ns(c, &pop_seen);
  zx_add_xmlns_if_not_seen(c, x->gg.g.ns, &pop_seen);

  p = zx_enc_seen(p, pop_seen); 
  p = zx_attr_wo_enc(p, x->DeviceInHand, "DeviceInHand=\"", sizeof("DeviceInHand=\"")-1);
  p = zx_attr_wo_enc(p, x->DeviceType, "DeviceType=\"", sizeof("DeviceType=\"")-1);
  p = zx_attr_wo_enc(p, x->SeedLength, "SeedLength=\"", sizeof("SeedLength=\"")-1);

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
  ENC_LEN_DEBUG(x, "ac:TimeSyncToken", p-enc_base);
  return p;
}

/* FUNC(zx_EASY_ENC_SO_ac_TimeSyncToken) */

/* Called by: */
struct zx_str* zx_EASY_ENC_SO_ac_TimeSyncToken(struct zx_ctx* c, struct zx_ac_TimeSyncToken_s* x )
{
  int len;
  char* buf;
  c->ns_tab = ZX_ALLOC(c, sizeof(zx_ns_tab));
  memcpy(c->ns_tab, zx_ns_tab, sizeof(zx_ns_tab));
  len = zx_LEN_SO_ac_TimeSyncToken(c, x );
  buf = ZX_ALLOC(c, len+1);
  return zx_easy_enc_common(c, zx_ENC_SO_ac_TimeSyncToken(c, x, buf ), buf, len);
}

/* FUNC(zx_EASY_ENC_WO_ac_TimeSyncToken) */

/* Called by: */
struct zx_str* zx_EASY_ENC_WO_ac_TimeSyncToken(struct zx_ctx* c, struct zx_ac_TimeSyncToken_s* x )
{
  int len;
  char* buf;
  c->ns_tab = ZX_ALLOC(c, sizeof(zx_ns_tab));
  memcpy(c->ns_tab, zx_ns_tab, sizeof(zx_ns_tab));
  len = zx_LEN_WO_ac_TimeSyncToken(c, x );
  buf = ZX_ALLOC(c, len+1);
  return zx_easy_enc_common(c, zx_ENC_WO_ac_TimeSyncToken(c, x, buf ), buf, len);
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

#define EL_NAME   ac_Token
#define EL_STRUCT zx_ac_Token_s
#define EL_NS     ac
#define EL_TAG    Token

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

/* FUNC(zx_LEN_SO_ac_Token) */

/* Compute length of an element (and its subelements). The XML attributes
 * and elements are processed in schema order. */

/* Called by: */
int zx_LEN_SO_ac_Token(struct zx_ctx* c, struct zx_ac_Token_s* x )
{
  struct zx_ns_s* pop_seen = 0;
  struct zx_elem_s* se MAYBE_UNUSED;
#if 1 /* NORMALMODE */
  /* *** in simple_elem case should output ns prefix from ns node. */
  int len = sizeof("<ac:Token")-1 + 1 + sizeof("</ac:Token>")-1;
  if (c->inc_ns_len)
    len += zx_len_inc_ns(c, &pop_seen);
  len += zx_len_xmlns_if_not_seen(c, zx_ns_tab+zx_xmlns_ix_ac, &pop_seen);


#else
  /* root node has no begin tag */
  int len = 0;
#endif
  
  {
      struct zx_ac_TimeSyncToken_s* e;
      for (e = x->TimeSyncToken; e; e = (struct zx_ac_TimeSyncToken_s*)e->gg.g.n)
	  len += zx_LEN_SO_ac_TimeSyncToken(c, e);
  }
  {
      struct zx_ac_Extension_s* e;
      for (e = x->Extension; e; e = (struct zx_ac_Extension_s*)e->gg.g.n)
	  len += zx_LEN_SO_ac_Extension(c, e);
  }


  len += zx_len_so_common(c, &x->gg);
  zx_pop_seen(pop_seen);
  ENC_LEN_DEBUG(x, "ac:Token", len);
  return len;
}

/* FUNC(zx_LEN_WO_ac_Token) */

/* Compute length of an element (and its subelements). The XML attributes
 * and elements are processed in wire order and no assumptions
 * are made about namespace prefixes. */

/* Called by: */
int zx_LEN_WO_ac_Token(struct zx_ctx* c, struct zx_ac_Token_s* x )
{
  struct zx_ns_s* pop_seen = 0;
  struct zx_elem_s* se MAYBE_UNUSED;
#if 1 /* NORMALMODE */
  int len = 1 + sizeof("Token")-1 + 1 + 2 + sizeof("Token")-1 + 1;
  
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
      struct zx_ac_TimeSyncToken_s* e;
      for (e = x->TimeSyncToken; e; e = (struct zx_ac_TimeSyncToken_s*)e->gg.g.n)
	  len += zx_LEN_WO_ac_TimeSyncToken(c, e);
  }
  {
      struct zx_ac_Extension_s* e;
      for (e = x->Extension; e; e = (struct zx_ac_Extension_s*)e->gg.g.n)
	  len += zx_LEN_WO_ac_Extension(c, e);
  }


  len += zx_len_wo_common(c, &x->gg); 
  zx_pop_seen(pop_seen);
  ENC_LEN_DEBUG(x, "ac:Token", len);
  return len;
}

/* FUNC(zx_ENC_SO_ac_Token) */

/* Render element into string. The XML attributes and elements are
 * processed in schema order. This is what you generally want for
 * rendering new data structure to a string. The wo pointers are not used. */

/* Called by: */
char* zx_ENC_SO_ac_Token(struct zx_ctx* c, struct zx_ac_Token_s* x, char* p )
{
  struct zx_elem_s* se MAYBE_UNUSED;
  ENC_LEN_DEBUG_BASE;
#if 1 /* NORMALMODE */
  struct zx_ns_s* pop_seen = 0;
  /* *** in simple_elem case should output ns prefix from ns node. */
  ZX_OUT_TAG(p, "<ac:Token");
  if (c->inc_ns)
    p = zx_enc_inc_ns(c, p, &pop_seen);
  p = zx_enc_xmlns_if_not_seen(c, p, zx_ns_tab+zx_xmlns_ix_ac, &pop_seen);


  p = zx_enc_unknown_attrs(p, x->gg.any_attr);
#else
  /* root node has no begin tag */
#endif
  
  {
      struct zx_ac_TimeSyncToken_s* e;
      for (e = x->TimeSyncToken; e; e = (struct zx_ac_TimeSyncToken_s*)e->gg.g.n)
	  p = zx_ENC_SO_ac_TimeSyncToken(c, e, p);
  }
  {
      struct zx_ac_Extension_s* e;
      for (e = x->Extension; e; e = (struct zx_ac_Extension_s*)e->gg.g.n)
	  p = zx_ENC_SO_ac_Extension(c, e, p);
  }

  p = zx_enc_so_unknown_elems_and_content(c, p, &x->gg);
  
#if 1 /* NORMALMODE */
  ZX_OUT_CLOSE_TAG(p, "</ac:Token>");
  zx_pop_seen(pop_seen);
#else
  /* root node has no end tag either */
#endif
  ENC_LEN_DEBUG(x, "ac:Token", p-enc_base);
  return p;
}

/* FUNC(zx_ENC_WO_ac_Token) */

/* Render element into string. The XML attributes and elements are
 * processed in wire order by chasing wo pointers. This is what you want for
 * validating signatures on other people's XML documents. */

/* Called by: */
char* zx_ENC_WO_ac_Token(struct zx_ctx* c, struct zx_ac_Token_s* x, char* p )
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
  ZX_OUT_MEM(p, "Token", sizeof("Token")-1);
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
  ENC_LEN_DEBUG(x, "ac:Token", p-enc_base);
  return p;
}

/* FUNC(zx_EASY_ENC_SO_ac_Token) */

/* Called by: */
struct zx_str* zx_EASY_ENC_SO_ac_Token(struct zx_ctx* c, struct zx_ac_Token_s* x )
{
  int len;
  char* buf;
  c->ns_tab = ZX_ALLOC(c, sizeof(zx_ns_tab));
  memcpy(c->ns_tab, zx_ns_tab, sizeof(zx_ns_tab));
  len = zx_LEN_SO_ac_Token(c, x );
  buf = ZX_ALLOC(c, len+1);
  return zx_easy_enc_common(c, zx_ENC_SO_ac_Token(c, x, buf ), buf, len);
}

/* FUNC(zx_EASY_ENC_WO_ac_Token) */

/* Called by: */
struct zx_str* zx_EASY_ENC_WO_ac_Token(struct zx_ctx* c, struct zx_ac_Token_s* x )
{
  int len;
  char* buf;
  c->ns_tab = ZX_ALLOC(c, sizeof(zx_ns_tab));
  memcpy(c->ns_tab, zx_ns_tab, sizeof(zx_ns_tab));
  len = zx_LEN_WO_ac_Token(c, x );
  buf = ZX_ALLOC(c, len+1);
  return zx_easy_enc_common(c, zx_ENC_WO_ac_Token(c, x, buf ), buf, len);
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

#define EL_NAME   ac_WTLS
#define EL_STRUCT zx_ac_WTLS_s
#define EL_NS     ac
#define EL_TAG    WTLS

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

/* FUNC(zx_LEN_SO_ac_WTLS) */

/* Compute length of an element (and its subelements). The XML attributes
 * and elements are processed in schema order. */

/* Called by: */
int zx_LEN_SO_ac_WTLS(struct zx_ctx* c, struct zx_ac_WTLS_s* x )
{
  struct zx_ns_s* pop_seen = 0;
  struct zx_elem_s* se MAYBE_UNUSED;
#if 1 /* NORMALMODE */
  /* *** in simple_elem case should output ns prefix from ns node. */
  int len = sizeof("<ac:WTLS")-1 + 1 + sizeof("</ac:WTLS>")-1;
  if (c->inc_ns_len)
    len += zx_len_inc_ns(c, &pop_seen);
  len += zx_len_xmlns_if_not_seen(c, zx_ns_tab+zx_xmlns_ix_ac, &pop_seen);


#else
  /* root node has no begin tag */
  int len = 0;
#endif
  
  {
      struct zx_ac_Extension_s* e;
      for (e = x->Extension; e; e = (struct zx_ac_Extension_s*)e->gg.g.n)
	  len += zx_LEN_SO_ac_Extension(c, e);
  }


  len += zx_len_so_common(c, &x->gg);
  zx_pop_seen(pop_seen);
  ENC_LEN_DEBUG(x, "ac:WTLS", len);
  return len;
}

/* FUNC(zx_LEN_WO_ac_WTLS) */

/* Compute length of an element (and its subelements). The XML attributes
 * and elements are processed in wire order and no assumptions
 * are made about namespace prefixes. */

/* Called by: */
int zx_LEN_WO_ac_WTLS(struct zx_ctx* c, struct zx_ac_WTLS_s* x )
{
  struct zx_ns_s* pop_seen = 0;
  struct zx_elem_s* se MAYBE_UNUSED;
#if 1 /* NORMALMODE */
  int len = 1 + sizeof("WTLS")-1 + 1 + 2 + sizeof("WTLS")-1 + 1;
  
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
      struct zx_ac_Extension_s* e;
      for (e = x->Extension; e; e = (struct zx_ac_Extension_s*)e->gg.g.n)
	  len += zx_LEN_WO_ac_Extension(c, e);
  }


  len += zx_len_wo_common(c, &x->gg); 
  zx_pop_seen(pop_seen);
  ENC_LEN_DEBUG(x, "ac:WTLS", len);
  return len;
}

/* FUNC(zx_ENC_SO_ac_WTLS) */

/* Render element into string. The XML attributes and elements are
 * processed in schema order. This is what you generally want for
 * rendering new data structure to a string. The wo pointers are not used. */

/* Called by: */
char* zx_ENC_SO_ac_WTLS(struct zx_ctx* c, struct zx_ac_WTLS_s* x, char* p )
{
  struct zx_elem_s* se MAYBE_UNUSED;
  ENC_LEN_DEBUG_BASE;
#if 1 /* NORMALMODE */
  struct zx_ns_s* pop_seen = 0;
  /* *** in simple_elem case should output ns prefix from ns node. */
  ZX_OUT_TAG(p, "<ac:WTLS");
  if (c->inc_ns)
    p = zx_enc_inc_ns(c, p, &pop_seen);
  p = zx_enc_xmlns_if_not_seen(c, p, zx_ns_tab+zx_xmlns_ix_ac, &pop_seen);


  p = zx_enc_unknown_attrs(p, x->gg.any_attr);
#else
  /* root node has no begin tag */
#endif
  
  {
      struct zx_ac_Extension_s* e;
      for (e = x->Extension; e; e = (struct zx_ac_Extension_s*)e->gg.g.n)
	  p = zx_ENC_SO_ac_Extension(c, e, p);
  }

  p = zx_enc_so_unknown_elems_and_content(c, p, &x->gg);
  
#if 1 /* NORMALMODE */
  ZX_OUT_CLOSE_TAG(p, "</ac:WTLS>");
  zx_pop_seen(pop_seen);
#else
  /* root node has no end tag either */
#endif
  ENC_LEN_DEBUG(x, "ac:WTLS", p-enc_base);
  return p;
}

/* FUNC(zx_ENC_WO_ac_WTLS) */

/* Render element into string. The XML attributes and elements are
 * processed in wire order by chasing wo pointers. This is what you want for
 * validating signatures on other people's XML documents. */

/* Called by: */
char* zx_ENC_WO_ac_WTLS(struct zx_ctx* c, struct zx_ac_WTLS_s* x, char* p )
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
  ZX_OUT_MEM(p, "WTLS", sizeof("WTLS")-1);
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
  ENC_LEN_DEBUG(x, "ac:WTLS", p-enc_base);
  return p;
}

/* FUNC(zx_EASY_ENC_SO_ac_WTLS) */

/* Called by: */
struct zx_str* zx_EASY_ENC_SO_ac_WTLS(struct zx_ctx* c, struct zx_ac_WTLS_s* x )
{
  int len;
  char* buf;
  c->ns_tab = ZX_ALLOC(c, sizeof(zx_ns_tab));
  memcpy(c->ns_tab, zx_ns_tab, sizeof(zx_ns_tab));
  len = zx_LEN_SO_ac_WTLS(c, x );
  buf = ZX_ALLOC(c, len+1);
  return zx_easy_enc_common(c, zx_ENC_SO_ac_WTLS(c, x, buf ), buf, len);
}

/* FUNC(zx_EASY_ENC_WO_ac_WTLS) */

/* Called by: */
struct zx_str* zx_EASY_ENC_WO_ac_WTLS(struct zx_ctx* c, struct zx_ac_WTLS_s* x )
{
  int len;
  char* buf;
  c->ns_tab = ZX_ALLOC(c, sizeof(zx_ns_tab));
  memcpy(c->ns_tab, zx_ns_tab, sizeof(zx_ns_tab));
  len = zx_LEN_WO_ac_WTLS(c, x );
  buf = ZX_ALLOC(c, len+1);
  return zx_easy_enc_common(c, zx_ENC_WO_ac_WTLS(c, x, buf ), buf, len);
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

#define EL_NAME   ac_WrittenConsent
#define EL_STRUCT zx_ac_WrittenConsent_s
#define EL_NS     ac
#define EL_TAG    WrittenConsent

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

/* FUNC(zx_LEN_SO_ac_WrittenConsent) */

/* Compute length of an element (and its subelements). The XML attributes
 * and elements are processed in schema order. */

/* Called by: */
int zx_LEN_SO_ac_WrittenConsent(struct zx_ctx* c, struct zx_ac_WrittenConsent_s* x )
{
  struct zx_ns_s* pop_seen = 0;
  struct zx_elem_s* se MAYBE_UNUSED;
#if 1 /* NORMALMODE */
  /* *** in simple_elem case should output ns prefix from ns node. */
  int len = sizeof("<ac:WrittenConsent")-1 + 1 + sizeof("</ac:WrittenConsent>")-1;
  if (c->inc_ns_len)
    len += zx_len_inc_ns(c, &pop_seen);
  len += zx_len_xmlns_if_not_seen(c, zx_ns_tab+zx_xmlns_ix_ac, &pop_seen);


#else
  /* root node has no begin tag */
  int len = 0;
#endif
  
  {
      struct zx_ac_Extension_s* e;
      for (e = x->Extension; e; e = (struct zx_ac_Extension_s*)e->gg.g.n)
	  len += zx_LEN_SO_ac_Extension(c, e);
  }


  len += zx_len_so_common(c, &x->gg);
  zx_pop_seen(pop_seen);
  ENC_LEN_DEBUG(x, "ac:WrittenConsent", len);
  return len;
}

/* FUNC(zx_LEN_WO_ac_WrittenConsent) */

/* Compute length of an element (and its subelements). The XML attributes
 * and elements are processed in wire order and no assumptions
 * are made about namespace prefixes. */

/* Called by: */
int zx_LEN_WO_ac_WrittenConsent(struct zx_ctx* c, struct zx_ac_WrittenConsent_s* x )
{
  struct zx_ns_s* pop_seen = 0;
  struct zx_elem_s* se MAYBE_UNUSED;
#if 1 /* NORMALMODE */
  int len = 1 + sizeof("WrittenConsent")-1 + 1 + 2 + sizeof("WrittenConsent")-1 + 1;
  
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
      struct zx_ac_Extension_s* e;
      for (e = x->Extension; e; e = (struct zx_ac_Extension_s*)e->gg.g.n)
	  len += zx_LEN_WO_ac_Extension(c, e);
  }


  len += zx_len_wo_common(c, &x->gg); 
  zx_pop_seen(pop_seen);
  ENC_LEN_DEBUG(x, "ac:WrittenConsent", len);
  return len;
}

/* FUNC(zx_ENC_SO_ac_WrittenConsent) */

/* Render element into string. The XML attributes and elements are
 * processed in schema order. This is what you generally want for
 * rendering new data structure to a string. The wo pointers are not used. */

/* Called by: */
char* zx_ENC_SO_ac_WrittenConsent(struct zx_ctx* c, struct zx_ac_WrittenConsent_s* x, char* p )
{
  struct zx_elem_s* se MAYBE_UNUSED;
  ENC_LEN_DEBUG_BASE;
#if 1 /* NORMALMODE */
  struct zx_ns_s* pop_seen = 0;
  /* *** in simple_elem case should output ns prefix from ns node. */
  ZX_OUT_TAG(p, "<ac:WrittenConsent");
  if (c->inc_ns)
    p = zx_enc_inc_ns(c, p, &pop_seen);
  p = zx_enc_xmlns_if_not_seen(c, p, zx_ns_tab+zx_xmlns_ix_ac, &pop_seen);


  p = zx_enc_unknown_attrs(p, x->gg.any_attr);
#else
  /* root node has no begin tag */
#endif
  
  {
      struct zx_ac_Extension_s* e;
      for (e = x->Extension; e; e = (struct zx_ac_Extension_s*)e->gg.g.n)
	  p = zx_ENC_SO_ac_Extension(c, e, p);
  }

  p = zx_enc_so_unknown_elems_and_content(c, p, &x->gg);
  
#if 1 /* NORMALMODE */
  ZX_OUT_CLOSE_TAG(p, "</ac:WrittenConsent>");
  zx_pop_seen(pop_seen);
#else
  /* root node has no end tag either */
#endif
  ENC_LEN_DEBUG(x, "ac:WrittenConsent", p-enc_base);
  return p;
}

/* FUNC(zx_ENC_WO_ac_WrittenConsent) */

/* Render element into string. The XML attributes and elements are
 * processed in wire order by chasing wo pointers. This is what you want for
 * validating signatures on other people's XML documents. */

/* Called by: */
char* zx_ENC_WO_ac_WrittenConsent(struct zx_ctx* c, struct zx_ac_WrittenConsent_s* x, char* p )
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
  ZX_OUT_MEM(p, "WrittenConsent", sizeof("WrittenConsent")-1);
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
  ENC_LEN_DEBUG(x, "ac:WrittenConsent", p-enc_base);
  return p;
}

/* FUNC(zx_EASY_ENC_SO_ac_WrittenConsent) */

/* Called by: */
struct zx_str* zx_EASY_ENC_SO_ac_WrittenConsent(struct zx_ctx* c, struct zx_ac_WrittenConsent_s* x )
{
  int len;
  char* buf;
  c->ns_tab = ZX_ALLOC(c, sizeof(zx_ns_tab));
  memcpy(c->ns_tab, zx_ns_tab, sizeof(zx_ns_tab));
  len = zx_LEN_SO_ac_WrittenConsent(c, x );
  buf = ZX_ALLOC(c, len+1);
  return zx_easy_enc_common(c, zx_ENC_SO_ac_WrittenConsent(c, x, buf ), buf, len);
}

/* FUNC(zx_EASY_ENC_WO_ac_WrittenConsent) */

/* Called by: */
struct zx_str* zx_EASY_ENC_WO_ac_WrittenConsent(struct zx_ctx* c, struct zx_ac_WrittenConsent_s* x )
{
  int len;
  char* buf;
  c->ns_tab = ZX_ALLOC(c, sizeof(zx_ns_tab));
  memcpy(c->ns_tab, zx_ns_tab, sizeof(zx_ns_tab));
  len = zx_LEN_WO_ac_WrittenConsent(c, x );
  buf = ZX_ALLOC(c, len+1);
  return zx_easy_enc_common(c, zx_ENC_WO_ac_WrittenConsent(c, x, buf ), buf, len);
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

#define EL_NAME   ac_ZeroKnowledge
#define EL_STRUCT zx_ac_ZeroKnowledge_s
#define EL_NS     ac
#define EL_TAG    ZeroKnowledge

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

/* FUNC(zx_LEN_SO_ac_ZeroKnowledge) */

/* Compute length of an element (and its subelements). The XML attributes
 * and elements are processed in schema order. */

/* Called by: */
int zx_LEN_SO_ac_ZeroKnowledge(struct zx_ctx* c, struct zx_ac_ZeroKnowledge_s* x )
{
  struct zx_ns_s* pop_seen = 0;
  struct zx_elem_s* se MAYBE_UNUSED;
#if 1 /* NORMALMODE */
  /* *** in simple_elem case should output ns prefix from ns node. */
  int len = sizeof("<ac:ZeroKnowledge")-1 + 1 + sizeof("</ac:ZeroKnowledge>")-1;
  if (c->inc_ns_len)
    len += zx_len_inc_ns(c, &pop_seen);
  len += zx_len_xmlns_if_not_seen(c, zx_ns_tab+zx_xmlns_ix_ac, &pop_seen);


#else
  /* root node has no begin tag */
  int len = 0;
#endif
  
  {
      struct zx_ac_Extension_s* e;
      for (e = x->Extension; e; e = (struct zx_ac_Extension_s*)e->gg.g.n)
	  len += zx_LEN_SO_ac_Extension(c, e);
  }


  len += zx_len_so_common(c, &x->gg);
  zx_pop_seen(pop_seen);
  ENC_LEN_DEBUG(x, "ac:ZeroKnowledge", len);
  return len;
}

/* FUNC(zx_LEN_WO_ac_ZeroKnowledge) */

/* Compute length of an element (and its subelements). The XML attributes
 * and elements are processed in wire order and no assumptions
 * are made about namespace prefixes. */

/* Called by: */
int zx_LEN_WO_ac_ZeroKnowledge(struct zx_ctx* c, struct zx_ac_ZeroKnowledge_s* x )
{
  struct zx_ns_s* pop_seen = 0;
  struct zx_elem_s* se MAYBE_UNUSED;
#if 1 /* NORMALMODE */
  int len = 1 + sizeof("ZeroKnowledge")-1 + 1 + 2 + sizeof("ZeroKnowledge")-1 + 1;
  
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
      struct zx_ac_Extension_s* e;
      for (e = x->Extension; e; e = (struct zx_ac_Extension_s*)e->gg.g.n)
	  len += zx_LEN_WO_ac_Extension(c, e);
  }


  len += zx_len_wo_common(c, &x->gg); 
  zx_pop_seen(pop_seen);
  ENC_LEN_DEBUG(x, "ac:ZeroKnowledge", len);
  return len;
}

/* FUNC(zx_ENC_SO_ac_ZeroKnowledge) */

/* Render element into string. The XML attributes and elements are
 * processed in schema order. This is what you generally want for
 * rendering new data structure to a string. The wo pointers are not used. */

/* Called by: */
char* zx_ENC_SO_ac_ZeroKnowledge(struct zx_ctx* c, struct zx_ac_ZeroKnowledge_s* x, char* p )
{
  struct zx_elem_s* se MAYBE_UNUSED;
  ENC_LEN_DEBUG_BASE;
#if 1 /* NORMALMODE */
  struct zx_ns_s* pop_seen = 0;
  /* *** in simple_elem case should output ns prefix from ns node. */
  ZX_OUT_TAG(p, "<ac:ZeroKnowledge");
  if (c->inc_ns)
    p = zx_enc_inc_ns(c, p, &pop_seen);
  p = zx_enc_xmlns_if_not_seen(c, p, zx_ns_tab+zx_xmlns_ix_ac, &pop_seen);


  p = zx_enc_unknown_attrs(p, x->gg.any_attr);
#else
  /* root node has no begin tag */
#endif
  
  {
      struct zx_ac_Extension_s* e;
      for (e = x->Extension; e; e = (struct zx_ac_Extension_s*)e->gg.g.n)
	  p = zx_ENC_SO_ac_Extension(c, e, p);
  }

  p = zx_enc_so_unknown_elems_and_content(c, p, &x->gg);
  
#if 1 /* NORMALMODE */
  ZX_OUT_CLOSE_TAG(p, "</ac:ZeroKnowledge>");
  zx_pop_seen(pop_seen);
#else
  /* root node has no end tag either */
#endif
  ENC_LEN_DEBUG(x, "ac:ZeroKnowledge", p-enc_base);
  return p;
}

/* FUNC(zx_ENC_WO_ac_ZeroKnowledge) */

/* Render element into string. The XML attributes and elements are
 * processed in wire order by chasing wo pointers. This is what you want for
 * validating signatures on other people's XML documents. */

/* Called by: */
char* zx_ENC_WO_ac_ZeroKnowledge(struct zx_ctx* c, struct zx_ac_ZeroKnowledge_s* x, char* p )
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
  ZX_OUT_MEM(p, "ZeroKnowledge", sizeof("ZeroKnowledge")-1);
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
  ENC_LEN_DEBUG(x, "ac:ZeroKnowledge", p-enc_base);
  return p;
}

/* FUNC(zx_EASY_ENC_SO_ac_ZeroKnowledge) */

/* Called by: */
struct zx_str* zx_EASY_ENC_SO_ac_ZeroKnowledge(struct zx_ctx* c, struct zx_ac_ZeroKnowledge_s* x )
{
  int len;
  char* buf;
  c->ns_tab = ZX_ALLOC(c, sizeof(zx_ns_tab));
  memcpy(c->ns_tab, zx_ns_tab, sizeof(zx_ns_tab));
  len = zx_LEN_SO_ac_ZeroKnowledge(c, x );
  buf = ZX_ALLOC(c, len+1);
  return zx_easy_enc_common(c, zx_ENC_SO_ac_ZeroKnowledge(c, x, buf ), buf, len);
}

/* FUNC(zx_EASY_ENC_WO_ac_ZeroKnowledge) */

/* Called by: */
struct zx_str* zx_EASY_ENC_WO_ac_ZeroKnowledge(struct zx_ctx* c, struct zx_ac_ZeroKnowledge_s* x )
{
  int len;
  char* buf;
  c->ns_tab = ZX_ALLOC(c, sizeof(zx_ns_tab));
  memcpy(c->ns_tab, zx_ns_tab, sizeof(zx_ns_tab));
  len = zx_LEN_WO_ac_ZeroKnowledge(c, x );
  buf = ZX_ALLOC(c, len+1);
  return zx_easy_enc_common(c, zx_ENC_WO_ac_ZeroKnowledge(c, x, buf ), buf, len);
}




/* EOF -- c/zx-ac-enc.c */
