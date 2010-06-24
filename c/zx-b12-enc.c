/* c/zx-b12-enc.c - WARNING: This file was automatically generated. DO NOT EDIT!
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
#include "c/zx-b12-data.h"
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

#define EL_NAME   b12_Consent
#define EL_STRUCT zx_b12_Consent_s
#define EL_NS     b12
#define EL_TAG    Consent

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

/* FUNC(zx_LEN_SO_b12_Consent) */

/* Compute length of an element (and its subelements). The XML attributes
 * and elements are processed in schema order. */

/* Called by: */
int zx_LEN_SO_b12_Consent(struct zx_ctx* c, struct zx_b12_Consent_s* x )
{
  struct zx_ns_s* pop_seen = 0;
  struct zx_elem_s* se MAYBE_UNUSED;
#if 1 /* NORMALMODE */
  /* *** in simple_elem case should output ns prefix from ns node. */
  int len = sizeof("<b12:Consent")-1 + 1 + sizeof("</b12:Consent>")-1;
  if (c->inc_ns_len)
    len += zx_len_inc_ns(c, &pop_seen);
  len += zx_len_xmlns_if_not_seen(c, zx_ns_tab+zx_xmlns_ix_b12, &pop_seen);
  if (x->actor || x->mustUnderstand)
    len += zx_len_xmlns_if_not_seen(c, zx_ns_tab+zx_xmlns_ix_e, &pop_seen);

  len += zx_attr_so_len(x->id, sizeof("id")-1);
  len += zx_attr_so_len(x->timestamp, sizeof("timestamp")-1);
  len += zx_attr_so_len(x->uri, sizeof("uri")-1);
  len += zx_attr_so_len(x->actor, sizeof("e:actor")-1);
  len += zx_attr_so_len(x->mustUnderstand, sizeof("e:mustUnderstand")-1);

#else
  /* root node has no begin tag */
  int len = 0;
#endif
  


  len += zx_len_so_common(c, &x->gg);
  zx_pop_seen(pop_seen);
  ENC_LEN_DEBUG(x, "b12:Consent", len);
  return len;
}

/* FUNC(zx_LEN_WO_b12_Consent) */

/* Compute length of an element (and its subelements). The XML attributes
 * and elements are processed in wire order and no assumptions
 * are made about namespace prefixes. */

/* Called by: */
int zx_LEN_WO_b12_Consent(struct zx_ctx* c, struct zx_b12_Consent_s* x )
{
  struct zx_ns_s* pop_seen = 0;
  struct zx_elem_s* se MAYBE_UNUSED;
#if 1 /* NORMALMODE */
  int len = 1 + sizeof("Consent")-1 + 1 + 2 + sizeof("Consent")-1 + 1;
  
  if (x->gg.g.ns && x->gg.g.ns->prefix_len)
    len += (x->gg.g.ns->prefix_len + 1) * 2;
  if (c->inc_ns_len)
    len += zx_len_inc_ns(c, &pop_seen);
  len += zx_len_xmlns_if_not_seen(c, x->gg.g.ns, &pop_seen);
  if (x->actor)
    len += zx_len_xmlns_if_not_seen(c, x->actor->g.ns, &pop_seen);
  if (x->mustUnderstand)
    len += zx_len_xmlns_if_not_seen(c, x->mustUnderstand->g.ns, &pop_seen);

  len += zx_attr_wo_len(x->id, sizeof("id")-1);
  len += zx_attr_wo_len(x->timestamp, sizeof("timestamp")-1);
  len += zx_attr_wo_len(x->uri, sizeof("uri")-1);
  len += zx_attr_wo_len(x->actor, sizeof("actor")-1);
  len += zx_attr_wo_len(x->mustUnderstand, sizeof("mustUnderstand")-1);

#else
  /* root node has no begin tag */
  int len = 0;
#endif
  


  len += zx_len_wo_common(c, &x->gg); 
  zx_pop_seen(pop_seen);
  ENC_LEN_DEBUG(x, "b12:Consent", len);
  return len;
}

/* FUNC(zx_ENC_SO_b12_Consent) */

/* Render element into string. The XML attributes and elements are
 * processed in schema order. This is what you generally want for
 * rendering new data structure to a string. The wo pointers are not used. */

/* Called by: */
char* zx_ENC_SO_b12_Consent(struct zx_ctx* c, struct zx_b12_Consent_s* x, char* p )
{
  struct zx_elem_s* se MAYBE_UNUSED;
  ENC_LEN_DEBUG_BASE;
#if 1 /* NORMALMODE */
  struct zx_ns_s* pop_seen = 0;
  /* *** in simple_elem case should output ns prefix from ns node. */
  ZX_OUT_TAG(p, "<b12:Consent");
  if (c->inc_ns)
    p = zx_enc_inc_ns(c, p, &pop_seen);
  p = zx_enc_xmlns_if_not_seen(c, p, zx_ns_tab+zx_xmlns_ix_b12, &pop_seen);
  if (x->actor || x->mustUnderstand)
    p = zx_enc_xmlns_if_not_seen(c, p, zx_ns_tab+zx_xmlns_ix_e, &pop_seen);

  p = zx_attr_so_enc(p, x->id, " id=\"", sizeof(" id=\"")-1);
  p = zx_attr_so_enc(p, x->timestamp, " timestamp=\"", sizeof(" timestamp=\"")-1);
  p = zx_attr_so_enc(p, x->uri, " uri=\"", sizeof(" uri=\"")-1);
  p = zx_attr_so_enc(p, x->actor, " e:actor=\"", sizeof(" e:actor=\"")-1);
  p = zx_attr_so_enc(p, x->mustUnderstand, " e:mustUnderstand=\"", sizeof(" e:mustUnderstand=\"")-1);

  p = zx_enc_unknown_attrs(p, x->gg.any_attr);
#else
  /* root node has no begin tag */
#endif
  

  p = zx_enc_so_unknown_elems_and_content(c, p, &x->gg);
  
#if 1 /* NORMALMODE */
  ZX_OUT_CLOSE_TAG(p, "</b12:Consent>");
  zx_pop_seen(pop_seen);
#else
  /* root node has no end tag either */
#endif
  ENC_LEN_DEBUG(x, "b12:Consent", p-enc_base);
  return p;
}

/* FUNC(zx_ENC_WO_b12_Consent) */

/* Render element into string. The XML attributes and elements are
 * processed in wire order by chasing wo pointers. This is what you want for
 * validating signatures on other people's XML documents. */

/* Called by: */
char* zx_ENC_WO_b12_Consent(struct zx_ctx* c, struct zx_b12_Consent_s* x, char* p )
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
  ZX_OUT_MEM(p, "Consent", sizeof("Consent")-1);
  qq = p;

  /* *** sort the namespaces */
  if (c->inc_ns)
    zx_add_inc_ns(c, &pop_seen);
  zx_add_xmlns_if_not_seen(c, x->gg.g.ns, &pop_seen);
  if (x->actor)
    zx_add_xmlns_if_not_seen(c, x->actor->g.ns, &pop_seen);
  if (x->mustUnderstand)
    zx_add_xmlns_if_not_seen(c, x->mustUnderstand->g.ns, &pop_seen);

  p = zx_enc_seen(p, pop_seen); 
  p = zx_attr_wo_enc(p, x->id, "id=\"", sizeof("id=\"")-1);
  p = zx_attr_wo_enc(p, x->timestamp, "timestamp=\"", sizeof("timestamp=\"")-1);
  p = zx_attr_wo_enc(p, x->uri, "uri=\"", sizeof("uri=\"")-1);
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
  ENC_LEN_DEBUG(x, "b12:Consent", p-enc_base);
  return p;
}

/* FUNC(zx_EASY_ENC_SO_b12_Consent) */

/* Called by: */
struct zx_str* zx_EASY_ENC_SO_b12_Consent(struct zx_ctx* c, struct zx_b12_Consent_s* x )
{
  int len;
  char* buf;
  c->ns_tab = ZX_ALLOC(c, sizeof(zx_ns_tab));
  memcpy(c->ns_tab, zx_ns_tab, sizeof(zx_ns_tab));
  len = zx_LEN_SO_b12_Consent(c, x );
  buf = ZX_ALLOC(c, len+1);
  return zx_easy_enc_common(c, zx_ENC_SO_b12_Consent(c, x, buf ), buf, len);
}

/* FUNC(zx_EASY_ENC_WO_b12_Consent) */

/* Called by: */
struct zx_str* zx_EASY_ENC_WO_b12_Consent(struct zx_ctx* c, struct zx_b12_Consent_s* x )
{
  int len;
  char* buf;
  c->ns_tab = ZX_ALLOC(c, sizeof(zx_ns_tab));
  memcpy(c->ns_tab, zx_ns_tab, sizeof(zx_ns_tab));
  len = zx_LEN_WO_b12_Consent(c, x );
  buf = ZX_ALLOC(c, len+1);
  return zx_easy_enc_common(c, zx_ENC_WO_b12_Consent(c, x, buf ), buf, len);
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

#define EL_NAME   b12_Correlation
#define EL_STRUCT zx_b12_Correlation_s
#define EL_NS     b12
#define EL_TAG    Correlation

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

/* FUNC(zx_LEN_SO_b12_Correlation) */

/* Compute length of an element (and its subelements). The XML attributes
 * and elements are processed in schema order. */

/* Called by: */
int zx_LEN_SO_b12_Correlation(struct zx_ctx* c, struct zx_b12_Correlation_s* x )
{
  struct zx_ns_s* pop_seen = 0;
  struct zx_elem_s* se MAYBE_UNUSED;
#if 1 /* NORMALMODE */
  /* *** in simple_elem case should output ns prefix from ns node. */
  int len = sizeof("<b12:Correlation")-1 + 1 + sizeof("</b12:Correlation>")-1;
  if (c->inc_ns_len)
    len += zx_len_inc_ns(c, &pop_seen);
  len += zx_len_xmlns_if_not_seen(c, zx_ns_tab+zx_xmlns_ix_b12, &pop_seen);
  if (x->actor || x->mustUnderstand)
    len += zx_len_xmlns_if_not_seen(c, zx_ns_tab+zx_xmlns_ix_e, &pop_seen);

  len += zx_attr_so_len(x->id, sizeof("id")-1);
  len += zx_attr_so_len(x->messageID, sizeof("messageID")-1);
  len += zx_attr_so_len(x->refToMessageID, sizeof("refToMessageID")-1);
  len += zx_attr_so_len(x->timestamp, sizeof("timestamp")-1);
  len += zx_attr_so_len(x->actor, sizeof("e:actor")-1);
  len += zx_attr_so_len(x->mustUnderstand, sizeof("e:mustUnderstand")-1);

#else
  /* root node has no begin tag */
  int len = 0;
#endif
  


  len += zx_len_so_common(c, &x->gg);
  zx_pop_seen(pop_seen);
  ENC_LEN_DEBUG(x, "b12:Correlation", len);
  return len;
}

/* FUNC(zx_LEN_WO_b12_Correlation) */

/* Compute length of an element (and its subelements). The XML attributes
 * and elements are processed in wire order and no assumptions
 * are made about namespace prefixes. */

/* Called by: */
int zx_LEN_WO_b12_Correlation(struct zx_ctx* c, struct zx_b12_Correlation_s* x )
{
  struct zx_ns_s* pop_seen = 0;
  struct zx_elem_s* se MAYBE_UNUSED;
#if 1 /* NORMALMODE */
  int len = 1 + sizeof("Correlation")-1 + 1 + 2 + sizeof("Correlation")-1 + 1;
  
  if (x->gg.g.ns && x->gg.g.ns->prefix_len)
    len += (x->gg.g.ns->prefix_len + 1) * 2;
  if (c->inc_ns_len)
    len += zx_len_inc_ns(c, &pop_seen);
  len += zx_len_xmlns_if_not_seen(c, x->gg.g.ns, &pop_seen);
  if (x->actor)
    len += zx_len_xmlns_if_not_seen(c, x->actor->g.ns, &pop_seen);
  if (x->mustUnderstand)
    len += zx_len_xmlns_if_not_seen(c, x->mustUnderstand->g.ns, &pop_seen);

  len += zx_attr_wo_len(x->id, sizeof("id")-1);
  len += zx_attr_wo_len(x->messageID, sizeof("messageID")-1);
  len += zx_attr_wo_len(x->refToMessageID, sizeof("refToMessageID")-1);
  len += zx_attr_wo_len(x->timestamp, sizeof("timestamp")-1);
  len += zx_attr_wo_len(x->actor, sizeof("actor")-1);
  len += zx_attr_wo_len(x->mustUnderstand, sizeof("mustUnderstand")-1);

#else
  /* root node has no begin tag */
  int len = 0;
#endif
  


  len += zx_len_wo_common(c, &x->gg); 
  zx_pop_seen(pop_seen);
  ENC_LEN_DEBUG(x, "b12:Correlation", len);
  return len;
}

/* FUNC(zx_ENC_SO_b12_Correlation) */

/* Render element into string. The XML attributes and elements are
 * processed in schema order. This is what you generally want for
 * rendering new data structure to a string. The wo pointers are not used. */

/* Called by: */
char* zx_ENC_SO_b12_Correlation(struct zx_ctx* c, struct zx_b12_Correlation_s* x, char* p )
{
  struct zx_elem_s* se MAYBE_UNUSED;
  ENC_LEN_DEBUG_BASE;
#if 1 /* NORMALMODE */
  struct zx_ns_s* pop_seen = 0;
  /* *** in simple_elem case should output ns prefix from ns node. */
  ZX_OUT_TAG(p, "<b12:Correlation");
  if (c->inc_ns)
    p = zx_enc_inc_ns(c, p, &pop_seen);
  p = zx_enc_xmlns_if_not_seen(c, p, zx_ns_tab+zx_xmlns_ix_b12, &pop_seen);
  if (x->actor || x->mustUnderstand)
    p = zx_enc_xmlns_if_not_seen(c, p, zx_ns_tab+zx_xmlns_ix_e, &pop_seen);

  p = zx_attr_so_enc(p, x->id, " id=\"", sizeof(" id=\"")-1);
  p = zx_attr_so_enc(p, x->messageID, " messageID=\"", sizeof(" messageID=\"")-1);
  p = zx_attr_so_enc(p, x->refToMessageID, " refToMessageID=\"", sizeof(" refToMessageID=\"")-1);
  p = zx_attr_so_enc(p, x->timestamp, " timestamp=\"", sizeof(" timestamp=\"")-1);
  p = zx_attr_so_enc(p, x->actor, " e:actor=\"", sizeof(" e:actor=\"")-1);
  p = zx_attr_so_enc(p, x->mustUnderstand, " e:mustUnderstand=\"", sizeof(" e:mustUnderstand=\"")-1);

  p = zx_enc_unknown_attrs(p, x->gg.any_attr);
#else
  /* root node has no begin tag */
#endif
  

  p = zx_enc_so_unknown_elems_and_content(c, p, &x->gg);
  
#if 1 /* NORMALMODE */
  ZX_OUT_CLOSE_TAG(p, "</b12:Correlation>");
  zx_pop_seen(pop_seen);
#else
  /* root node has no end tag either */
#endif
  ENC_LEN_DEBUG(x, "b12:Correlation", p-enc_base);
  return p;
}

/* FUNC(zx_ENC_WO_b12_Correlation) */

/* Render element into string. The XML attributes and elements are
 * processed in wire order by chasing wo pointers. This is what you want for
 * validating signatures on other people's XML documents. */

/* Called by: */
char* zx_ENC_WO_b12_Correlation(struct zx_ctx* c, struct zx_b12_Correlation_s* x, char* p )
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
  ZX_OUT_MEM(p, "Correlation", sizeof("Correlation")-1);
  qq = p;

  /* *** sort the namespaces */
  if (c->inc_ns)
    zx_add_inc_ns(c, &pop_seen);
  zx_add_xmlns_if_not_seen(c, x->gg.g.ns, &pop_seen);
  if (x->actor)
    zx_add_xmlns_if_not_seen(c, x->actor->g.ns, &pop_seen);
  if (x->mustUnderstand)
    zx_add_xmlns_if_not_seen(c, x->mustUnderstand->g.ns, &pop_seen);

  p = zx_enc_seen(p, pop_seen); 
  p = zx_attr_wo_enc(p, x->id, "id=\"", sizeof("id=\"")-1);
  p = zx_attr_wo_enc(p, x->messageID, "messageID=\"", sizeof("messageID=\"")-1);
  p = zx_attr_wo_enc(p, x->refToMessageID, "refToMessageID=\"", sizeof("refToMessageID=\"")-1);
  p = zx_attr_wo_enc(p, x->timestamp, "timestamp=\"", sizeof("timestamp=\"")-1);
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
  ENC_LEN_DEBUG(x, "b12:Correlation", p-enc_base);
  return p;
}

/* FUNC(zx_EASY_ENC_SO_b12_Correlation) */

/* Called by: */
struct zx_str* zx_EASY_ENC_SO_b12_Correlation(struct zx_ctx* c, struct zx_b12_Correlation_s* x )
{
  int len;
  char* buf;
  c->ns_tab = ZX_ALLOC(c, sizeof(zx_ns_tab));
  memcpy(c->ns_tab, zx_ns_tab, sizeof(zx_ns_tab));
  len = zx_LEN_SO_b12_Correlation(c, x );
  buf = ZX_ALLOC(c, len+1);
  return zx_easy_enc_common(c, zx_ENC_SO_b12_Correlation(c, x, buf ), buf, len);
}

/* FUNC(zx_EASY_ENC_WO_b12_Correlation) */

/* Called by: */
struct zx_str* zx_EASY_ENC_WO_b12_Correlation(struct zx_ctx* c, struct zx_b12_Correlation_s* x )
{
  int len;
  char* buf;
  c->ns_tab = ZX_ALLOC(c, sizeof(zx_ns_tab));
  memcpy(c->ns_tab, zx_ns_tab, sizeof(zx_ns_tab));
  len = zx_LEN_WO_b12_Correlation(c, x );
  buf = ZX_ALLOC(c, len+1);
  return zx_easy_enc_common(c, zx_ENC_WO_b12_Correlation(c, x, buf ), buf, len);
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

#define EL_NAME   b12_ProcessingContext
#define EL_STRUCT zx_b12_ProcessingContext_s
#define EL_NS     b12
#define EL_TAG    ProcessingContext

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

/* FUNC(zx_LEN_SO_b12_ProcessingContext) */

/* Compute length of an element (and its subelements). The XML attributes
 * and elements are processed in schema order. */

/* Called by: */
int zx_LEN_SO_b12_ProcessingContext(struct zx_ctx* c, struct zx_b12_ProcessingContext_s* x )
{
  struct zx_ns_s* pop_seen = 0;
  struct zx_elem_s* se MAYBE_UNUSED;
#if 1 /* NORMALMODE */
  /* *** in simple_elem case should output ns prefix from ns node. */
  int len = sizeof("<b12:ProcessingContext")-1 + 1 + sizeof("</b12:ProcessingContext>")-1;
  if (c->inc_ns_len)
    len += zx_len_inc_ns(c, &pop_seen);
  len += zx_len_xmlns_if_not_seen(c, zx_ns_tab+zx_xmlns_ix_b12, &pop_seen);
  if (x->actor || x->mustUnderstand)
    len += zx_len_xmlns_if_not_seen(c, zx_ns_tab+zx_xmlns_ix_e, &pop_seen);

  len += zx_attr_so_len(x->id, sizeof("id")-1);
  len += zx_attr_so_len(x->actor, sizeof("e:actor")-1);
  len += zx_attr_so_len(x->mustUnderstand, sizeof("e:mustUnderstand")-1);

#else
  /* root node has no begin tag */
  int len = 0;
#endif
  


  len += zx_len_so_common(c, &x->gg);
  zx_pop_seen(pop_seen);
  ENC_LEN_DEBUG(x, "b12:ProcessingContext", len);
  return len;
}

/* FUNC(zx_LEN_WO_b12_ProcessingContext) */

/* Compute length of an element (and its subelements). The XML attributes
 * and elements are processed in wire order and no assumptions
 * are made about namespace prefixes. */

/* Called by: */
int zx_LEN_WO_b12_ProcessingContext(struct zx_ctx* c, struct zx_b12_ProcessingContext_s* x )
{
  struct zx_ns_s* pop_seen = 0;
  struct zx_elem_s* se MAYBE_UNUSED;
#if 1 /* NORMALMODE */
  int len = 1 + sizeof("ProcessingContext")-1 + 1 + 2 + sizeof("ProcessingContext")-1 + 1;
  
  if (x->gg.g.ns && x->gg.g.ns->prefix_len)
    len += (x->gg.g.ns->prefix_len + 1) * 2;
  if (c->inc_ns_len)
    len += zx_len_inc_ns(c, &pop_seen);
  len += zx_len_xmlns_if_not_seen(c, x->gg.g.ns, &pop_seen);
  if (x->actor)
    len += zx_len_xmlns_if_not_seen(c, x->actor->g.ns, &pop_seen);
  if (x->mustUnderstand)
    len += zx_len_xmlns_if_not_seen(c, x->mustUnderstand->g.ns, &pop_seen);

  len += zx_attr_wo_len(x->id, sizeof("id")-1);
  len += zx_attr_wo_len(x->actor, sizeof("actor")-1);
  len += zx_attr_wo_len(x->mustUnderstand, sizeof("mustUnderstand")-1);

#else
  /* root node has no begin tag */
  int len = 0;
#endif
  


  len += zx_len_wo_common(c, &x->gg); 
  zx_pop_seen(pop_seen);
  ENC_LEN_DEBUG(x, "b12:ProcessingContext", len);
  return len;
}

/* FUNC(zx_ENC_SO_b12_ProcessingContext) */

/* Render element into string. The XML attributes and elements are
 * processed in schema order. This is what you generally want for
 * rendering new data structure to a string. The wo pointers are not used. */

/* Called by: */
char* zx_ENC_SO_b12_ProcessingContext(struct zx_ctx* c, struct zx_b12_ProcessingContext_s* x, char* p )
{
  struct zx_elem_s* se MAYBE_UNUSED;
  ENC_LEN_DEBUG_BASE;
#if 1 /* NORMALMODE */
  struct zx_ns_s* pop_seen = 0;
  /* *** in simple_elem case should output ns prefix from ns node. */
  ZX_OUT_TAG(p, "<b12:ProcessingContext");
  if (c->inc_ns)
    p = zx_enc_inc_ns(c, p, &pop_seen);
  p = zx_enc_xmlns_if_not_seen(c, p, zx_ns_tab+zx_xmlns_ix_b12, &pop_seen);
  if (x->actor || x->mustUnderstand)
    p = zx_enc_xmlns_if_not_seen(c, p, zx_ns_tab+zx_xmlns_ix_e, &pop_seen);

  p = zx_attr_so_enc(p, x->id, " id=\"", sizeof(" id=\"")-1);
  p = zx_attr_so_enc(p, x->actor, " e:actor=\"", sizeof(" e:actor=\"")-1);
  p = zx_attr_so_enc(p, x->mustUnderstand, " e:mustUnderstand=\"", sizeof(" e:mustUnderstand=\"")-1);

  p = zx_enc_unknown_attrs(p, x->gg.any_attr);
#else
  /* root node has no begin tag */
#endif
  

  p = zx_enc_so_unknown_elems_and_content(c, p, &x->gg);
  
#if 1 /* NORMALMODE */
  ZX_OUT_CLOSE_TAG(p, "</b12:ProcessingContext>");
  zx_pop_seen(pop_seen);
#else
  /* root node has no end tag either */
#endif
  ENC_LEN_DEBUG(x, "b12:ProcessingContext", p-enc_base);
  return p;
}

/* FUNC(zx_ENC_WO_b12_ProcessingContext) */

/* Render element into string. The XML attributes and elements are
 * processed in wire order by chasing wo pointers. This is what you want for
 * validating signatures on other people's XML documents. */

/* Called by: */
char* zx_ENC_WO_b12_ProcessingContext(struct zx_ctx* c, struct zx_b12_ProcessingContext_s* x, char* p )
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
  ZX_OUT_MEM(p, "ProcessingContext", sizeof("ProcessingContext")-1);
  qq = p;

  /* *** sort the namespaces */
  if (c->inc_ns)
    zx_add_inc_ns(c, &pop_seen);
  zx_add_xmlns_if_not_seen(c, x->gg.g.ns, &pop_seen);
  if (x->actor)
    zx_add_xmlns_if_not_seen(c, x->actor->g.ns, &pop_seen);
  if (x->mustUnderstand)
    zx_add_xmlns_if_not_seen(c, x->mustUnderstand->g.ns, &pop_seen);

  p = zx_enc_seen(p, pop_seen); 
  p = zx_attr_wo_enc(p, x->id, "id=\"", sizeof("id=\"")-1);
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
  ENC_LEN_DEBUG(x, "b12:ProcessingContext", p-enc_base);
  return p;
}

/* FUNC(zx_EASY_ENC_SO_b12_ProcessingContext) */

/* Called by: */
struct zx_str* zx_EASY_ENC_SO_b12_ProcessingContext(struct zx_ctx* c, struct zx_b12_ProcessingContext_s* x )
{
  int len;
  char* buf;
  c->ns_tab = ZX_ALLOC(c, sizeof(zx_ns_tab));
  memcpy(c->ns_tab, zx_ns_tab, sizeof(zx_ns_tab));
  len = zx_LEN_SO_b12_ProcessingContext(c, x );
  buf = ZX_ALLOC(c, len+1);
  return zx_easy_enc_common(c, zx_ENC_SO_b12_ProcessingContext(c, x, buf ), buf, len);
}

/* FUNC(zx_EASY_ENC_WO_b12_ProcessingContext) */

/* Called by: */
struct zx_str* zx_EASY_ENC_WO_b12_ProcessingContext(struct zx_ctx* c, struct zx_b12_ProcessingContext_s* x )
{
  int len;
  char* buf;
  c->ns_tab = ZX_ALLOC(c, sizeof(zx_ns_tab));
  memcpy(c->ns_tab, zx_ns_tab, sizeof(zx_ns_tab));
  len = zx_LEN_WO_b12_ProcessingContext(c, x );
  buf = ZX_ALLOC(c, len+1);
  return zx_easy_enc_common(c, zx_ENC_WO_b12_ProcessingContext(c, x, buf ), buf, len);
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

#define EL_NAME   b12_Provider
#define EL_STRUCT zx_b12_Provider_s
#define EL_NS     b12
#define EL_TAG    Provider

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

/* FUNC(zx_LEN_SO_b12_Provider) */

/* Compute length of an element (and its subelements). The XML attributes
 * and elements are processed in schema order. */

/* Called by: */
int zx_LEN_SO_b12_Provider(struct zx_ctx* c, struct zx_b12_Provider_s* x )
{
  struct zx_ns_s* pop_seen = 0;
  struct zx_elem_s* se MAYBE_UNUSED;
#if 1 /* NORMALMODE */
  /* *** in simple_elem case should output ns prefix from ns node. */
  int len = sizeof("<b12:Provider")-1 + 1 + sizeof("</b12:Provider>")-1;
  if (c->inc_ns_len)
    len += zx_len_inc_ns(c, &pop_seen);
  len += zx_len_xmlns_if_not_seen(c, zx_ns_tab+zx_xmlns_ix_b12, &pop_seen);
  if (x->actor || x->mustUnderstand)
    len += zx_len_xmlns_if_not_seen(c, zx_ns_tab+zx_xmlns_ix_e, &pop_seen);

  len += zx_attr_so_len(x->affiliationID, sizeof("affiliationID")-1);
  len += zx_attr_so_len(x->id, sizeof("id")-1);
  len += zx_attr_so_len(x->providerID, sizeof("providerID")-1);
  len += zx_attr_so_len(x->actor, sizeof("e:actor")-1);
  len += zx_attr_so_len(x->mustUnderstand, sizeof("e:mustUnderstand")-1);

#else
  /* root node has no begin tag */
  int len = 0;
#endif
  


  len += zx_len_so_common(c, &x->gg);
  zx_pop_seen(pop_seen);
  ENC_LEN_DEBUG(x, "b12:Provider", len);
  return len;
}

/* FUNC(zx_LEN_WO_b12_Provider) */

/* Compute length of an element (and its subelements). The XML attributes
 * and elements are processed in wire order and no assumptions
 * are made about namespace prefixes. */

/* Called by: */
int zx_LEN_WO_b12_Provider(struct zx_ctx* c, struct zx_b12_Provider_s* x )
{
  struct zx_ns_s* pop_seen = 0;
  struct zx_elem_s* se MAYBE_UNUSED;
#if 1 /* NORMALMODE */
  int len = 1 + sizeof("Provider")-1 + 1 + 2 + sizeof("Provider")-1 + 1;
  
  if (x->gg.g.ns && x->gg.g.ns->prefix_len)
    len += (x->gg.g.ns->prefix_len + 1) * 2;
  if (c->inc_ns_len)
    len += zx_len_inc_ns(c, &pop_seen);
  len += zx_len_xmlns_if_not_seen(c, x->gg.g.ns, &pop_seen);
  if (x->actor)
    len += zx_len_xmlns_if_not_seen(c, x->actor->g.ns, &pop_seen);
  if (x->mustUnderstand)
    len += zx_len_xmlns_if_not_seen(c, x->mustUnderstand->g.ns, &pop_seen);

  len += zx_attr_wo_len(x->affiliationID, sizeof("affiliationID")-1);
  len += zx_attr_wo_len(x->id, sizeof("id")-1);
  len += zx_attr_wo_len(x->providerID, sizeof("providerID")-1);
  len += zx_attr_wo_len(x->actor, sizeof("actor")-1);
  len += zx_attr_wo_len(x->mustUnderstand, sizeof("mustUnderstand")-1);

#else
  /* root node has no begin tag */
  int len = 0;
#endif
  


  len += zx_len_wo_common(c, &x->gg); 
  zx_pop_seen(pop_seen);
  ENC_LEN_DEBUG(x, "b12:Provider", len);
  return len;
}

/* FUNC(zx_ENC_SO_b12_Provider) */

/* Render element into string. The XML attributes and elements are
 * processed in schema order. This is what you generally want for
 * rendering new data structure to a string. The wo pointers are not used. */

/* Called by: */
char* zx_ENC_SO_b12_Provider(struct zx_ctx* c, struct zx_b12_Provider_s* x, char* p )
{
  struct zx_elem_s* se MAYBE_UNUSED;
  ENC_LEN_DEBUG_BASE;
#if 1 /* NORMALMODE */
  struct zx_ns_s* pop_seen = 0;
  /* *** in simple_elem case should output ns prefix from ns node. */
  ZX_OUT_TAG(p, "<b12:Provider");
  if (c->inc_ns)
    p = zx_enc_inc_ns(c, p, &pop_seen);
  p = zx_enc_xmlns_if_not_seen(c, p, zx_ns_tab+zx_xmlns_ix_b12, &pop_seen);
  if (x->actor || x->mustUnderstand)
    p = zx_enc_xmlns_if_not_seen(c, p, zx_ns_tab+zx_xmlns_ix_e, &pop_seen);

  p = zx_attr_so_enc(p, x->affiliationID, " affiliationID=\"", sizeof(" affiliationID=\"")-1);
  p = zx_attr_so_enc(p, x->id, " id=\"", sizeof(" id=\"")-1);
  p = zx_attr_so_enc(p, x->providerID, " providerID=\"", sizeof(" providerID=\"")-1);
  p = zx_attr_so_enc(p, x->actor, " e:actor=\"", sizeof(" e:actor=\"")-1);
  p = zx_attr_so_enc(p, x->mustUnderstand, " e:mustUnderstand=\"", sizeof(" e:mustUnderstand=\"")-1);

  p = zx_enc_unknown_attrs(p, x->gg.any_attr);
#else
  /* root node has no begin tag */
#endif
  

  p = zx_enc_so_unknown_elems_and_content(c, p, &x->gg);
  
#if 1 /* NORMALMODE */
  ZX_OUT_CLOSE_TAG(p, "</b12:Provider>");
  zx_pop_seen(pop_seen);
#else
  /* root node has no end tag either */
#endif
  ENC_LEN_DEBUG(x, "b12:Provider", p-enc_base);
  return p;
}

/* FUNC(zx_ENC_WO_b12_Provider) */

/* Render element into string. The XML attributes and elements are
 * processed in wire order by chasing wo pointers. This is what you want for
 * validating signatures on other people's XML documents. */

/* Called by: */
char* zx_ENC_WO_b12_Provider(struct zx_ctx* c, struct zx_b12_Provider_s* x, char* p )
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
  ZX_OUT_MEM(p, "Provider", sizeof("Provider")-1);
  qq = p;

  /* *** sort the namespaces */
  if (c->inc_ns)
    zx_add_inc_ns(c, &pop_seen);
  zx_add_xmlns_if_not_seen(c, x->gg.g.ns, &pop_seen);
  if (x->actor)
    zx_add_xmlns_if_not_seen(c, x->actor->g.ns, &pop_seen);
  if (x->mustUnderstand)
    zx_add_xmlns_if_not_seen(c, x->mustUnderstand->g.ns, &pop_seen);

  p = zx_enc_seen(p, pop_seen); 
  p = zx_attr_wo_enc(p, x->affiliationID, "affiliationID=\"", sizeof("affiliationID=\"")-1);
  p = zx_attr_wo_enc(p, x->id, "id=\"", sizeof("id=\"")-1);
  p = zx_attr_wo_enc(p, x->providerID, "providerID=\"", sizeof("providerID=\"")-1);
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
  ENC_LEN_DEBUG(x, "b12:Provider", p-enc_base);
  return p;
}

/* FUNC(zx_EASY_ENC_SO_b12_Provider) */

/* Called by: */
struct zx_str* zx_EASY_ENC_SO_b12_Provider(struct zx_ctx* c, struct zx_b12_Provider_s* x )
{
  int len;
  char* buf;
  c->ns_tab = ZX_ALLOC(c, sizeof(zx_ns_tab));
  memcpy(c->ns_tab, zx_ns_tab, sizeof(zx_ns_tab));
  len = zx_LEN_SO_b12_Provider(c, x );
  buf = ZX_ALLOC(c, len+1);
  return zx_easy_enc_common(c, zx_ENC_SO_b12_Provider(c, x, buf ), buf, len);
}

/* FUNC(zx_EASY_ENC_WO_b12_Provider) */

/* Called by: */
struct zx_str* zx_EASY_ENC_WO_b12_Provider(struct zx_ctx* c, struct zx_b12_Provider_s* x )
{
  int len;
  char* buf;
  c->ns_tab = ZX_ALLOC(c, sizeof(zx_ns_tab));
  memcpy(c->ns_tab, zx_ns_tab, sizeof(zx_ns_tab));
  len = zx_LEN_WO_b12_Provider(c, x );
  buf = ZX_ALLOC(c, len+1);
  return zx_easy_enc_common(c, zx_ENC_WO_b12_Provider(c, x, buf ), buf, len);
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

#define EL_NAME   b12_UsageDirective
#define EL_STRUCT zx_b12_UsageDirective_s
#define EL_NS     b12
#define EL_TAG    UsageDirective

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

/* FUNC(zx_LEN_SO_b12_UsageDirective) */

/* Compute length of an element (and its subelements). The XML attributes
 * and elements are processed in schema order. */

/* Called by: */
int zx_LEN_SO_b12_UsageDirective(struct zx_ctx* c, struct zx_b12_UsageDirective_s* x )
{
  struct zx_ns_s* pop_seen = 0;
  struct zx_elem_s* se MAYBE_UNUSED;
#if 1 /* NORMALMODE */
  /* *** in simple_elem case should output ns prefix from ns node. */
  int len = sizeof("<b12:UsageDirective")-1 + 1 + sizeof("</b12:UsageDirective>")-1;
  if (c->inc_ns_len)
    len += zx_len_inc_ns(c, &pop_seen);
  len += zx_len_xmlns_if_not_seen(c, zx_ns_tab+zx_xmlns_ix_b12, &pop_seen);
  if (x->actor || x->mustUnderstand)
    len += zx_len_xmlns_if_not_seen(c, zx_ns_tab+zx_xmlns_ix_e, &pop_seen);

  len += zx_attr_so_len(x->id, sizeof("id")-1);
  len += zx_attr_so_len(x->ref, sizeof("ref")-1);
  len += zx_attr_so_len(x->actor, sizeof("e:actor")-1);
  len += zx_attr_so_len(x->mustUnderstand, sizeof("e:mustUnderstand")-1);

#else
  /* root node has no begin tag */
  int len = 0;
#endif
  


  len += zx_len_so_common(c, &x->gg);
  zx_pop_seen(pop_seen);
  ENC_LEN_DEBUG(x, "b12:UsageDirective", len);
  return len;
}

/* FUNC(zx_LEN_WO_b12_UsageDirective) */

/* Compute length of an element (and its subelements). The XML attributes
 * and elements are processed in wire order and no assumptions
 * are made about namespace prefixes. */

/* Called by: */
int zx_LEN_WO_b12_UsageDirective(struct zx_ctx* c, struct zx_b12_UsageDirective_s* x )
{
  struct zx_ns_s* pop_seen = 0;
  struct zx_elem_s* se MAYBE_UNUSED;
#if 1 /* NORMALMODE */
  int len = 1 + sizeof("UsageDirective")-1 + 1 + 2 + sizeof("UsageDirective")-1 + 1;
  
  if (x->gg.g.ns && x->gg.g.ns->prefix_len)
    len += (x->gg.g.ns->prefix_len + 1) * 2;
  if (c->inc_ns_len)
    len += zx_len_inc_ns(c, &pop_seen);
  len += zx_len_xmlns_if_not_seen(c, x->gg.g.ns, &pop_seen);
  if (x->actor)
    len += zx_len_xmlns_if_not_seen(c, x->actor->g.ns, &pop_seen);
  if (x->mustUnderstand)
    len += zx_len_xmlns_if_not_seen(c, x->mustUnderstand->g.ns, &pop_seen);

  len += zx_attr_wo_len(x->id, sizeof("id")-1);
  len += zx_attr_wo_len(x->ref, sizeof("ref")-1);
  len += zx_attr_wo_len(x->actor, sizeof("actor")-1);
  len += zx_attr_wo_len(x->mustUnderstand, sizeof("mustUnderstand")-1);

#else
  /* root node has no begin tag */
  int len = 0;
#endif
  


  len += zx_len_wo_common(c, &x->gg); 
  zx_pop_seen(pop_seen);
  ENC_LEN_DEBUG(x, "b12:UsageDirective", len);
  return len;
}

/* FUNC(zx_ENC_SO_b12_UsageDirective) */

/* Render element into string. The XML attributes and elements are
 * processed in schema order. This is what you generally want for
 * rendering new data structure to a string. The wo pointers are not used. */

/* Called by: */
char* zx_ENC_SO_b12_UsageDirective(struct zx_ctx* c, struct zx_b12_UsageDirective_s* x, char* p )
{
  struct zx_elem_s* se MAYBE_UNUSED;
  ENC_LEN_DEBUG_BASE;
#if 1 /* NORMALMODE */
  struct zx_ns_s* pop_seen = 0;
  /* *** in simple_elem case should output ns prefix from ns node. */
  ZX_OUT_TAG(p, "<b12:UsageDirective");
  if (c->inc_ns)
    p = zx_enc_inc_ns(c, p, &pop_seen);
  p = zx_enc_xmlns_if_not_seen(c, p, zx_ns_tab+zx_xmlns_ix_b12, &pop_seen);
  if (x->actor || x->mustUnderstand)
    p = zx_enc_xmlns_if_not_seen(c, p, zx_ns_tab+zx_xmlns_ix_e, &pop_seen);

  p = zx_attr_so_enc(p, x->id, " id=\"", sizeof(" id=\"")-1);
  p = zx_attr_so_enc(p, x->ref, " ref=\"", sizeof(" ref=\"")-1);
  p = zx_attr_so_enc(p, x->actor, " e:actor=\"", sizeof(" e:actor=\"")-1);
  p = zx_attr_so_enc(p, x->mustUnderstand, " e:mustUnderstand=\"", sizeof(" e:mustUnderstand=\"")-1);

  p = zx_enc_unknown_attrs(p, x->gg.any_attr);
#else
  /* root node has no begin tag */
#endif
  

  p = zx_enc_so_unknown_elems_and_content(c, p, &x->gg);
  
#if 1 /* NORMALMODE */
  ZX_OUT_CLOSE_TAG(p, "</b12:UsageDirective>");
  zx_pop_seen(pop_seen);
#else
  /* root node has no end tag either */
#endif
  ENC_LEN_DEBUG(x, "b12:UsageDirective", p-enc_base);
  return p;
}

/* FUNC(zx_ENC_WO_b12_UsageDirective) */

/* Render element into string. The XML attributes and elements are
 * processed in wire order by chasing wo pointers. This is what you want for
 * validating signatures on other people's XML documents. */

/* Called by: */
char* zx_ENC_WO_b12_UsageDirective(struct zx_ctx* c, struct zx_b12_UsageDirective_s* x, char* p )
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
  ZX_OUT_MEM(p, "UsageDirective", sizeof("UsageDirective")-1);
  qq = p;

  /* *** sort the namespaces */
  if (c->inc_ns)
    zx_add_inc_ns(c, &pop_seen);
  zx_add_xmlns_if_not_seen(c, x->gg.g.ns, &pop_seen);
  if (x->actor)
    zx_add_xmlns_if_not_seen(c, x->actor->g.ns, &pop_seen);
  if (x->mustUnderstand)
    zx_add_xmlns_if_not_seen(c, x->mustUnderstand->g.ns, &pop_seen);

  p = zx_enc_seen(p, pop_seen); 
  p = zx_attr_wo_enc(p, x->id, "id=\"", sizeof("id=\"")-1);
  p = zx_attr_wo_enc(p, x->ref, "ref=\"", sizeof("ref=\"")-1);
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
  ENC_LEN_DEBUG(x, "b12:UsageDirective", p-enc_base);
  return p;
}

/* FUNC(zx_EASY_ENC_SO_b12_UsageDirective) */

/* Called by: */
struct zx_str* zx_EASY_ENC_SO_b12_UsageDirective(struct zx_ctx* c, struct zx_b12_UsageDirective_s* x )
{
  int len;
  char* buf;
  c->ns_tab = ZX_ALLOC(c, sizeof(zx_ns_tab));
  memcpy(c->ns_tab, zx_ns_tab, sizeof(zx_ns_tab));
  len = zx_LEN_SO_b12_UsageDirective(c, x );
  buf = ZX_ALLOC(c, len+1);
  return zx_easy_enc_common(c, zx_ENC_SO_b12_UsageDirective(c, x, buf ), buf, len);
}

/* FUNC(zx_EASY_ENC_WO_b12_UsageDirective) */

/* Called by: */
struct zx_str* zx_EASY_ENC_WO_b12_UsageDirective(struct zx_ctx* c, struct zx_b12_UsageDirective_s* x )
{
  int len;
  char* buf;
  c->ns_tab = ZX_ALLOC(c, sizeof(zx_ns_tab));
  memcpy(c->ns_tab, zx_ns_tab, sizeof(zx_ns_tab));
  len = zx_LEN_WO_b12_UsageDirective(c, x );
  buf = ZX_ALLOC(c, len+1);
  return zx_easy_enc_common(c, zx_ENC_WO_b12_UsageDirective(c, x, buf ), buf, len);
}




/* EOF -- c/zx-b12-enc.c */
