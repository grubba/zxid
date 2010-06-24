/* c/zx-wsse-enc.c - WARNING: This file was automatically generated. DO NOT EDIT!
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
#include "c/zx-wsse-data.h"
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

#define EL_NAME   wsse_BinarySecurityToken
#define EL_STRUCT zx_wsse_BinarySecurityToken_s
#define EL_NS     wsse
#define EL_TAG    BinarySecurityToken

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

/* FUNC(zx_LEN_SO_wsse_BinarySecurityToken) */

/* Compute length of an element (and its subelements). The XML attributes
 * and elements are processed in schema order. */

/* Called by: */
int zx_LEN_SO_wsse_BinarySecurityToken(struct zx_ctx* c, struct zx_wsse_BinarySecurityToken_s* x )
{
  struct zx_ns_s* pop_seen = 0;
  struct zx_elem_s* se MAYBE_UNUSED;
#if 1 /* NORMALMODE */
  /* *** in simple_elem case should output ns prefix from ns node. */
  int len = sizeof("<wsse:BinarySecurityToken")-1 + 1 + sizeof("</wsse:BinarySecurityToken>")-1;
  if (c->inc_ns_len)
    len += zx_len_inc_ns(c, &pop_seen);
  len += zx_len_xmlns_if_not_seen(c, zx_ns_tab+zx_xmlns_ix_wsse, &pop_seen);
  if (x->Id)
    len += zx_len_xmlns_if_not_seen(c, zx_ns_tab+zx_xmlns_ix_wsu, &pop_seen);

  len += zx_attr_so_len(x->EncodingType, sizeof("EncodingType")-1);
  len += zx_attr_so_len(x->ValueType, sizeof("ValueType")-1);
  len += zx_attr_so_len(x->Id, sizeof("wsu:Id")-1);

#else
  /* root node has no begin tag */
  int len = 0;
#endif
  


  len += zx_len_so_common(c, &x->gg);
  zx_pop_seen(pop_seen);
  ENC_LEN_DEBUG(x, "wsse:BinarySecurityToken", len);
  return len;
}

/* FUNC(zx_LEN_WO_wsse_BinarySecurityToken) */

/* Compute length of an element (and its subelements). The XML attributes
 * and elements are processed in wire order and no assumptions
 * are made about namespace prefixes. */

/* Called by: */
int zx_LEN_WO_wsse_BinarySecurityToken(struct zx_ctx* c, struct zx_wsse_BinarySecurityToken_s* x )
{
  struct zx_ns_s* pop_seen = 0;
  struct zx_elem_s* se MAYBE_UNUSED;
#if 1 /* NORMALMODE */
  int len = 1 + sizeof("BinarySecurityToken")-1 + 1 + 2 + sizeof("BinarySecurityToken")-1 + 1;
  
  if (x->gg.g.ns && x->gg.g.ns->prefix_len)
    len += (x->gg.g.ns->prefix_len + 1) * 2;
  if (c->inc_ns_len)
    len += zx_len_inc_ns(c, &pop_seen);
  len += zx_len_xmlns_if_not_seen(c, x->gg.g.ns, &pop_seen);
  if (x->Id)
    len += zx_len_xmlns_if_not_seen(c, x->Id->g.ns, &pop_seen);

  len += zx_attr_wo_len(x->EncodingType, sizeof("EncodingType")-1);
  len += zx_attr_wo_len(x->ValueType, sizeof("ValueType")-1);
  len += zx_attr_wo_len(x->Id, sizeof("Id")-1);

#else
  /* root node has no begin tag */
  int len = 0;
#endif
  


  len += zx_len_wo_common(c, &x->gg); 
  zx_pop_seen(pop_seen);
  ENC_LEN_DEBUG(x, "wsse:BinarySecurityToken", len);
  return len;
}

/* FUNC(zx_ENC_SO_wsse_BinarySecurityToken) */

/* Render element into string. The XML attributes and elements are
 * processed in schema order. This is what you generally want for
 * rendering new data structure to a string. The wo pointers are not used. */

/* Called by: */
char* zx_ENC_SO_wsse_BinarySecurityToken(struct zx_ctx* c, struct zx_wsse_BinarySecurityToken_s* x, char* p )
{
  struct zx_elem_s* se MAYBE_UNUSED;
  ENC_LEN_DEBUG_BASE;
#if 1 /* NORMALMODE */
  struct zx_ns_s* pop_seen = 0;
  /* *** in simple_elem case should output ns prefix from ns node. */
  ZX_OUT_TAG(p, "<wsse:BinarySecurityToken");
  if (c->inc_ns)
    p = zx_enc_inc_ns(c, p, &pop_seen);
  p = zx_enc_xmlns_if_not_seen(c, p, zx_ns_tab+zx_xmlns_ix_wsse, &pop_seen);
  if (x->Id)
    p = zx_enc_xmlns_if_not_seen(c, p, zx_ns_tab+zx_xmlns_ix_wsu, &pop_seen);

  p = zx_attr_so_enc(p, x->EncodingType, " EncodingType=\"", sizeof(" EncodingType=\"")-1);
  p = zx_attr_so_enc(p, x->ValueType, " ValueType=\"", sizeof(" ValueType=\"")-1);
  p = zx_attr_so_enc(p, x->Id, " wsu:Id=\"", sizeof(" wsu:Id=\"")-1);

  p = zx_enc_unknown_attrs(p, x->gg.any_attr);
#else
  /* root node has no begin tag */
#endif
  

  p = zx_enc_so_unknown_elems_and_content(c, p, &x->gg);
  
#if 1 /* NORMALMODE */
  ZX_OUT_CLOSE_TAG(p, "</wsse:BinarySecurityToken>");
  zx_pop_seen(pop_seen);
#else
  /* root node has no end tag either */
#endif
  ENC_LEN_DEBUG(x, "wsse:BinarySecurityToken", p-enc_base);
  return p;
}

/* FUNC(zx_ENC_WO_wsse_BinarySecurityToken) */

/* Render element into string. The XML attributes and elements are
 * processed in wire order by chasing wo pointers. This is what you want for
 * validating signatures on other people's XML documents. */

/* Called by: */
char* zx_ENC_WO_wsse_BinarySecurityToken(struct zx_ctx* c, struct zx_wsse_BinarySecurityToken_s* x, char* p )
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
  ZX_OUT_MEM(p, "BinarySecurityToken", sizeof("BinarySecurityToken")-1);
  qq = p;

  /* *** sort the namespaces */
  if (c->inc_ns)
    zx_add_inc_ns(c, &pop_seen);
  zx_add_xmlns_if_not_seen(c, x->gg.g.ns, &pop_seen);
  if (x->Id)
    zx_add_xmlns_if_not_seen(c, x->Id->g.ns, &pop_seen);

  p = zx_enc_seen(p, pop_seen); 
  p = zx_attr_wo_enc(p, x->EncodingType, "EncodingType=\"", sizeof("EncodingType=\"")-1);
  p = zx_attr_wo_enc(p, x->ValueType, "ValueType=\"", sizeof("ValueType=\"")-1);
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
  ENC_LEN_DEBUG(x, "wsse:BinarySecurityToken", p-enc_base);
  return p;
}

/* FUNC(zx_EASY_ENC_SO_wsse_BinarySecurityToken) */

/* Called by: */
struct zx_str* zx_EASY_ENC_SO_wsse_BinarySecurityToken(struct zx_ctx* c, struct zx_wsse_BinarySecurityToken_s* x )
{
  int len;
  char* buf;
  c->ns_tab = ZX_ALLOC(c, sizeof(zx_ns_tab));
  memcpy(c->ns_tab, zx_ns_tab, sizeof(zx_ns_tab));
  len = zx_LEN_SO_wsse_BinarySecurityToken(c, x );
  buf = ZX_ALLOC(c, len+1);
  return zx_easy_enc_common(c, zx_ENC_SO_wsse_BinarySecurityToken(c, x, buf ), buf, len);
}

/* FUNC(zx_EASY_ENC_WO_wsse_BinarySecurityToken) */

/* Called by: */
struct zx_str* zx_EASY_ENC_WO_wsse_BinarySecurityToken(struct zx_ctx* c, struct zx_wsse_BinarySecurityToken_s* x )
{
  int len;
  char* buf;
  c->ns_tab = ZX_ALLOC(c, sizeof(zx_ns_tab));
  memcpy(c->ns_tab, zx_ns_tab, sizeof(zx_ns_tab));
  len = zx_LEN_WO_wsse_BinarySecurityToken(c, x );
  buf = ZX_ALLOC(c, len+1);
  return zx_easy_enc_common(c, zx_ENC_WO_wsse_BinarySecurityToken(c, x, buf ), buf, len);
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

#define EL_NAME   wsse_Embedded
#define EL_STRUCT zx_wsse_Embedded_s
#define EL_NS     wsse
#define EL_TAG    Embedded

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

/* FUNC(zx_LEN_SO_wsse_Embedded) */

/* Compute length of an element (and its subelements). The XML attributes
 * and elements are processed in schema order. */

/* Called by: */
int zx_LEN_SO_wsse_Embedded(struct zx_ctx* c, struct zx_wsse_Embedded_s* x )
{
  struct zx_ns_s* pop_seen = 0;
  struct zx_elem_s* se MAYBE_UNUSED;
#if 1 /* NORMALMODE */
  /* *** in simple_elem case should output ns prefix from ns node. */
  int len = sizeof("<wsse:Embedded")-1 + 1 + sizeof("</wsse:Embedded>")-1;
  if (c->inc_ns_len)
    len += zx_len_inc_ns(c, &pop_seen);
  len += zx_len_xmlns_if_not_seen(c, zx_ns_tab+zx_xmlns_ix_wsse, &pop_seen);

  len += zx_attr_so_len(x->ValueType, sizeof("ValueType")-1);

#else
  /* root node has no begin tag */
  int len = 0;
#endif
  


  len += zx_len_so_common(c, &x->gg);
  zx_pop_seen(pop_seen);
  ENC_LEN_DEBUG(x, "wsse:Embedded", len);
  return len;
}

/* FUNC(zx_LEN_WO_wsse_Embedded) */

/* Compute length of an element (and its subelements). The XML attributes
 * and elements are processed in wire order and no assumptions
 * are made about namespace prefixes. */

/* Called by: */
int zx_LEN_WO_wsse_Embedded(struct zx_ctx* c, struct zx_wsse_Embedded_s* x )
{
  struct zx_ns_s* pop_seen = 0;
  struct zx_elem_s* se MAYBE_UNUSED;
#if 1 /* NORMALMODE */
  int len = 1 + sizeof("Embedded")-1 + 1 + 2 + sizeof("Embedded")-1 + 1;
  
  if (x->gg.g.ns && x->gg.g.ns->prefix_len)
    len += (x->gg.g.ns->prefix_len + 1) * 2;
  if (c->inc_ns_len)
    len += zx_len_inc_ns(c, &pop_seen);
  len += zx_len_xmlns_if_not_seen(c, x->gg.g.ns, &pop_seen);

  len += zx_attr_wo_len(x->ValueType, sizeof("ValueType")-1);

#else
  /* root node has no begin tag */
  int len = 0;
#endif
  


  len += zx_len_wo_common(c, &x->gg); 
  zx_pop_seen(pop_seen);
  ENC_LEN_DEBUG(x, "wsse:Embedded", len);
  return len;
}

/* FUNC(zx_ENC_SO_wsse_Embedded) */

/* Render element into string. The XML attributes and elements are
 * processed in schema order. This is what you generally want for
 * rendering new data structure to a string. The wo pointers are not used. */

/* Called by: */
char* zx_ENC_SO_wsse_Embedded(struct zx_ctx* c, struct zx_wsse_Embedded_s* x, char* p )
{
  struct zx_elem_s* se MAYBE_UNUSED;
  ENC_LEN_DEBUG_BASE;
#if 1 /* NORMALMODE */
  struct zx_ns_s* pop_seen = 0;
  /* *** in simple_elem case should output ns prefix from ns node. */
  ZX_OUT_TAG(p, "<wsse:Embedded");
  if (c->inc_ns)
    p = zx_enc_inc_ns(c, p, &pop_seen);
  p = zx_enc_xmlns_if_not_seen(c, p, zx_ns_tab+zx_xmlns_ix_wsse, &pop_seen);

  p = zx_attr_so_enc(p, x->ValueType, " ValueType=\"", sizeof(" ValueType=\"")-1);

  p = zx_enc_unknown_attrs(p, x->gg.any_attr);
#else
  /* root node has no begin tag */
#endif
  

  p = zx_enc_so_unknown_elems_and_content(c, p, &x->gg);
  
#if 1 /* NORMALMODE */
  ZX_OUT_CLOSE_TAG(p, "</wsse:Embedded>");
  zx_pop_seen(pop_seen);
#else
  /* root node has no end tag either */
#endif
  ENC_LEN_DEBUG(x, "wsse:Embedded", p-enc_base);
  return p;
}

/* FUNC(zx_ENC_WO_wsse_Embedded) */

/* Render element into string. The XML attributes and elements are
 * processed in wire order by chasing wo pointers. This is what you want for
 * validating signatures on other people's XML documents. */

/* Called by: */
char* zx_ENC_WO_wsse_Embedded(struct zx_ctx* c, struct zx_wsse_Embedded_s* x, char* p )
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
  ZX_OUT_MEM(p, "Embedded", sizeof("Embedded")-1);
  qq = p;

  /* *** sort the namespaces */
  if (c->inc_ns)
    zx_add_inc_ns(c, &pop_seen);
  zx_add_xmlns_if_not_seen(c, x->gg.g.ns, &pop_seen);

  p = zx_enc_seen(p, pop_seen); 
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
  ENC_LEN_DEBUG(x, "wsse:Embedded", p-enc_base);
  return p;
}

/* FUNC(zx_EASY_ENC_SO_wsse_Embedded) */

/* Called by: */
struct zx_str* zx_EASY_ENC_SO_wsse_Embedded(struct zx_ctx* c, struct zx_wsse_Embedded_s* x )
{
  int len;
  char* buf;
  c->ns_tab = ZX_ALLOC(c, sizeof(zx_ns_tab));
  memcpy(c->ns_tab, zx_ns_tab, sizeof(zx_ns_tab));
  len = zx_LEN_SO_wsse_Embedded(c, x );
  buf = ZX_ALLOC(c, len+1);
  return zx_easy_enc_common(c, zx_ENC_SO_wsse_Embedded(c, x, buf ), buf, len);
}

/* FUNC(zx_EASY_ENC_WO_wsse_Embedded) */

/* Called by: */
struct zx_str* zx_EASY_ENC_WO_wsse_Embedded(struct zx_ctx* c, struct zx_wsse_Embedded_s* x )
{
  int len;
  char* buf;
  c->ns_tab = ZX_ALLOC(c, sizeof(zx_ns_tab));
  memcpy(c->ns_tab, zx_ns_tab, sizeof(zx_ns_tab));
  len = zx_LEN_WO_wsse_Embedded(c, x );
  buf = ZX_ALLOC(c, len+1);
  return zx_easy_enc_common(c, zx_ENC_WO_wsse_Embedded(c, x, buf ), buf, len);
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

#define EL_NAME   wsse_KeyIdentifier
#define EL_STRUCT zx_wsse_KeyIdentifier_s
#define EL_NS     wsse
#define EL_TAG    KeyIdentifier

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

/* FUNC(zx_LEN_SO_wsse_KeyIdentifier) */

/* Compute length of an element (and its subelements). The XML attributes
 * and elements are processed in schema order. */

/* Called by: */
int zx_LEN_SO_wsse_KeyIdentifier(struct zx_ctx* c, struct zx_wsse_KeyIdentifier_s* x )
{
  struct zx_ns_s* pop_seen = 0;
  struct zx_elem_s* se MAYBE_UNUSED;
#if 1 /* NORMALMODE */
  /* *** in simple_elem case should output ns prefix from ns node. */
  int len = sizeof("<wsse:KeyIdentifier")-1 + 1 + sizeof("</wsse:KeyIdentifier>")-1;
  if (c->inc_ns_len)
    len += zx_len_inc_ns(c, &pop_seen);
  len += zx_len_xmlns_if_not_seen(c, zx_ns_tab+zx_xmlns_ix_wsse, &pop_seen);
  if (x->Id)
    len += zx_len_xmlns_if_not_seen(c, zx_ns_tab+zx_xmlns_ix_wsu, &pop_seen);

  len += zx_attr_so_len(x->EncodingType, sizeof("EncodingType")-1);
  len += zx_attr_so_len(x->ValueType, sizeof("ValueType")-1);
  len += zx_attr_so_len(x->Id, sizeof("wsu:Id")-1);

#else
  /* root node has no begin tag */
  int len = 0;
#endif
  


  len += zx_len_so_common(c, &x->gg);
  zx_pop_seen(pop_seen);
  ENC_LEN_DEBUG(x, "wsse:KeyIdentifier", len);
  return len;
}

/* FUNC(zx_LEN_WO_wsse_KeyIdentifier) */

/* Compute length of an element (and its subelements). The XML attributes
 * and elements are processed in wire order and no assumptions
 * are made about namespace prefixes. */

/* Called by: */
int zx_LEN_WO_wsse_KeyIdentifier(struct zx_ctx* c, struct zx_wsse_KeyIdentifier_s* x )
{
  struct zx_ns_s* pop_seen = 0;
  struct zx_elem_s* se MAYBE_UNUSED;
#if 1 /* NORMALMODE */
  int len = 1 + sizeof("KeyIdentifier")-1 + 1 + 2 + sizeof("KeyIdentifier")-1 + 1;
  
  if (x->gg.g.ns && x->gg.g.ns->prefix_len)
    len += (x->gg.g.ns->prefix_len + 1) * 2;
  if (c->inc_ns_len)
    len += zx_len_inc_ns(c, &pop_seen);
  len += zx_len_xmlns_if_not_seen(c, x->gg.g.ns, &pop_seen);
  if (x->Id)
    len += zx_len_xmlns_if_not_seen(c, x->Id->g.ns, &pop_seen);

  len += zx_attr_wo_len(x->EncodingType, sizeof("EncodingType")-1);
  len += zx_attr_wo_len(x->ValueType, sizeof("ValueType")-1);
  len += zx_attr_wo_len(x->Id, sizeof("Id")-1);

#else
  /* root node has no begin tag */
  int len = 0;
#endif
  


  len += zx_len_wo_common(c, &x->gg); 
  zx_pop_seen(pop_seen);
  ENC_LEN_DEBUG(x, "wsse:KeyIdentifier", len);
  return len;
}

/* FUNC(zx_ENC_SO_wsse_KeyIdentifier) */

/* Render element into string. The XML attributes and elements are
 * processed in schema order. This is what you generally want for
 * rendering new data structure to a string. The wo pointers are not used. */

/* Called by: */
char* zx_ENC_SO_wsse_KeyIdentifier(struct zx_ctx* c, struct zx_wsse_KeyIdentifier_s* x, char* p )
{
  struct zx_elem_s* se MAYBE_UNUSED;
  ENC_LEN_DEBUG_BASE;
#if 1 /* NORMALMODE */
  struct zx_ns_s* pop_seen = 0;
  /* *** in simple_elem case should output ns prefix from ns node. */
  ZX_OUT_TAG(p, "<wsse:KeyIdentifier");
  if (c->inc_ns)
    p = zx_enc_inc_ns(c, p, &pop_seen);
  p = zx_enc_xmlns_if_not_seen(c, p, zx_ns_tab+zx_xmlns_ix_wsse, &pop_seen);
  if (x->Id)
    p = zx_enc_xmlns_if_not_seen(c, p, zx_ns_tab+zx_xmlns_ix_wsu, &pop_seen);

  p = zx_attr_so_enc(p, x->EncodingType, " EncodingType=\"", sizeof(" EncodingType=\"")-1);
  p = zx_attr_so_enc(p, x->ValueType, " ValueType=\"", sizeof(" ValueType=\"")-1);
  p = zx_attr_so_enc(p, x->Id, " wsu:Id=\"", sizeof(" wsu:Id=\"")-1);

  p = zx_enc_unknown_attrs(p, x->gg.any_attr);
#else
  /* root node has no begin tag */
#endif
  

  p = zx_enc_so_unknown_elems_and_content(c, p, &x->gg);
  
#if 1 /* NORMALMODE */
  ZX_OUT_CLOSE_TAG(p, "</wsse:KeyIdentifier>");
  zx_pop_seen(pop_seen);
#else
  /* root node has no end tag either */
#endif
  ENC_LEN_DEBUG(x, "wsse:KeyIdentifier", p-enc_base);
  return p;
}

/* FUNC(zx_ENC_WO_wsse_KeyIdentifier) */

/* Render element into string. The XML attributes and elements are
 * processed in wire order by chasing wo pointers. This is what you want for
 * validating signatures on other people's XML documents. */

/* Called by: */
char* zx_ENC_WO_wsse_KeyIdentifier(struct zx_ctx* c, struct zx_wsse_KeyIdentifier_s* x, char* p )
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
  ZX_OUT_MEM(p, "KeyIdentifier", sizeof("KeyIdentifier")-1);
  qq = p;

  /* *** sort the namespaces */
  if (c->inc_ns)
    zx_add_inc_ns(c, &pop_seen);
  zx_add_xmlns_if_not_seen(c, x->gg.g.ns, &pop_seen);
  if (x->Id)
    zx_add_xmlns_if_not_seen(c, x->Id->g.ns, &pop_seen);

  p = zx_enc_seen(p, pop_seen); 
  p = zx_attr_wo_enc(p, x->EncodingType, "EncodingType=\"", sizeof("EncodingType=\"")-1);
  p = zx_attr_wo_enc(p, x->ValueType, "ValueType=\"", sizeof("ValueType=\"")-1);
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
  ENC_LEN_DEBUG(x, "wsse:KeyIdentifier", p-enc_base);
  return p;
}

/* FUNC(zx_EASY_ENC_SO_wsse_KeyIdentifier) */

/* Called by: */
struct zx_str* zx_EASY_ENC_SO_wsse_KeyIdentifier(struct zx_ctx* c, struct zx_wsse_KeyIdentifier_s* x )
{
  int len;
  char* buf;
  c->ns_tab = ZX_ALLOC(c, sizeof(zx_ns_tab));
  memcpy(c->ns_tab, zx_ns_tab, sizeof(zx_ns_tab));
  len = zx_LEN_SO_wsse_KeyIdentifier(c, x );
  buf = ZX_ALLOC(c, len+1);
  return zx_easy_enc_common(c, zx_ENC_SO_wsse_KeyIdentifier(c, x, buf ), buf, len);
}

/* FUNC(zx_EASY_ENC_WO_wsse_KeyIdentifier) */

/* Called by: */
struct zx_str* zx_EASY_ENC_WO_wsse_KeyIdentifier(struct zx_ctx* c, struct zx_wsse_KeyIdentifier_s* x )
{
  int len;
  char* buf;
  c->ns_tab = ZX_ALLOC(c, sizeof(zx_ns_tab));
  memcpy(c->ns_tab, zx_ns_tab, sizeof(zx_ns_tab));
  len = zx_LEN_WO_wsse_KeyIdentifier(c, x );
  buf = ZX_ALLOC(c, len+1);
  return zx_easy_enc_common(c, zx_ENC_WO_wsse_KeyIdentifier(c, x, buf ), buf, len);
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

#define EL_NAME   wsse_Nonce
#define EL_STRUCT zx_wsse_Nonce_s
#define EL_NS     wsse
#define EL_TAG    Nonce

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

/* FUNC(zx_LEN_SO_wsse_Nonce) */

/* Compute length of an element (and its subelements). The XML attributes
 * and elements are processed in schema order. */

/* Called by: */
int zx_LEN_SO_wsse_Nonce(struct zx_ctx* c, struct zx_wsse_Nonce_s* x )
{
  struct zx_ns_s* pop_seen = 0;
  struct zx_elem_s* se MAYBE_UNUSED;
#if 1 /* NORMALMODE */
  /* *** in simple_elem case should output ns prefix from ns node. */
  int len = sizeof("<wsse:Nonce")-1 + 1 + sizeof("</wsse:Nonce>")-1;
  if (c->inc_ns_len)
    len += zx_len_inc_ns(c, &pop_seen);
  len += zx_len_xmlns_if_not_seen(c, zx_ns_tab+zx_xmlns_ix_wsse, &pop_seen);
  if (x->Id)
    len += zx_len_xmlns_if_not_seen(c, zx_ns_tab+zx_xmlns_ix_wsu, &pop_seen);

  len += zx_attr_so_len(x->EncodingType, sizeof("EncodingType")-1);
  len += zx_attr_so_len(x->Id, sizeof("wsu:Id")-1);

#else
  /* root node has no begin tag */
  int len = 0;
#endif
  


  len += zx_len_so_common(c, &x->gg);
  zx_pop_seen(pop_seen);
  ENC_LEN_DEBUG(x, "wsse:Nonce", len);
  return len;
}

/* FUNC(zx_LEN_WO_wsse_Nonce) */

/* Compute length of an element (and its subelements). The XML attributes
 * and elements are processed in wire order and no assumptions
 * are made about namespace prefixes. */

/* Called by: */
int zx_LEN_WO_wsse_Nonce(struct zx_ctx* c, struct zx_wsse_Nonce_s* x )
{
  struct zx_ns_s* pop_seen = 0;
  struct zx_elem_s* se MAYBE_UNUSED;
#if 1 /* NORMALMODE */
  int len = 1 + sizeof("Nonce")-1 + 1 + 2 + sizeof("Nonce")-1 + 1;
  
  if (x->gg.g.ns && x->gg.g.ns->prefix_len)
    len += (x->gg.g.ns->prefix_len + 1) * 2;
  if (c->inc_ns_len)
    len += zx_len_inc_ns(c, &pop_seen);
  len += zx_len_xmlns_if_not_seen(c, x->gg.g.ns, &pop_seen);
  if (x->Id)
    len += zx_len_xmlns_if_not_seen(c, x->Id->g.ns, &pop_seen);

  len += zx_attr_wo_len(x->EncodingType, sizeof("EncodingType")-1);
  len += zx_attr_wo_len(x->Id, sizeof("Id")-1);

#else
  /* root node has no begin tag */
  int len = 0;
#endif
  


  len += zx_len_wo_common(c, &x->gg); 
  zx_pop_seen(pop_seen);
  ENC_LEN_DEBUG(x, "wsse:Nonce", len);
  return len;
}

/* FUNC(zx_ENC_SO_wsse_Nonce) */

/* Render element into string. The XML attributes and elements are
 * processed in schema order. This is what you generally want for
 * rendering new data structure to a string. The wo pointers are not used. */

/* Called by: */
char* zx_ENC_SO_wsse_Nonce(struct zx_ctx* c, struct zx_wsse_Nonce_s* x, char* p )
{
  struct zx_elem_s* se MAYBE_UNUSED;
  ENC_LEN_DEBUG_BASE;
#if 1 /* NORMALMODE */
  struct zx_ns_s* pop_seen = 0;
  /* *** in simple_elem case should output ns prefix from ns node. */
  ZX_OUT_TAG(p, "<wsse:Nonce");
  if (c->inc_ns)
    p = zx_enc_inc_ns(c, p, &pop_seen);
  p = zx_enc_xmlns_if_not_seen(c, p, zx_ns_tab+zx_xmlns_ix_wsse, &pop_seen);
  if (x->Id)
    p = zx_enc_xmlns_if_not_seen(c, p, zx_ns_tab+zx_xmlns_ix_wsu, &pop_seen);

  p = zx_attr_so_enc(p, x->EncodingType, " EncodingType=\"", sizeof(" EncodingType=\"")-1);
  p = zx_attr_so_enc(p, x->Id, " wsu:Id=\"", sizeof(" wsu:Id=\"")-1);

  p = zx_enc_unknown_attrs(p, x->gg.any_attr);
#else
  /* root node has no begin tag */
#endif
  

  p = zx_enc_so_unknown_elems_and_content(c, p, &x->gg);
  
#if 1 /* NORMALMODE */
  ZX_OUT_CLOSE_TAG(p, "</wsse:Nonce>");
  zx_pop_seen(pop_seen);
#else
  /* root node has no end tag either */
#endif
  ENC_LEN_DEBUG(x, "wsse:Nonce", p-enc_base);
  return p;
}

/* FUNC(zx_ENC_WO_wsse_Nonce) */

/* Render element into string. The XML attributes and elements are
 * processed in wire order by chasing wo pointers. This is what you want for
 * validating signatures on other people's XML documents. */

/* Called by: */
char* zx_ENC_WO_wsse_Nonce(struct zx_ctx* c, struct zx_wsse_Nonce_s* x, char* p )
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
  ZX_OUT_MEM(p, "Nonce", sizeof("Nonce")-1);
  qq = p;

  /* *** sort the namespaces */
  if (c->inc_ns)
    zx_add_inc_ns(c, &pop_seen);
  zx_add_xmlns_if_not_seen(c, x->gg.g.ns, &pop_seen);
  if (x->Id)
    zx_add_xmlns_if_not_seen(c, x->Id->g.ns, &pop_seen);

  p = zx_enc_seen(p, pop_seen); 
  p = zx_attr_wo_enc(p, x->EncodingType, "EncodingType=\"", sizeof("EncodingType=\"")-1);
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
  ENC_LEN_DEBUG(x, "wsse:Nonce", p-enc_base);
  return p;
}

/* FUNC(zx_EASY_ENC_SO_wsse_Nonce) */

/* Called by: */
struct zx_str* zx_EASY_ENC_SO_wsse_Nonce(struct zx_ctx* c, struct zx_wsse_Nonce_s* x )
{
  int len;
  char* buf;
  c->ns_tab = ZX_ALLOC(c, sizeof(zx_ns_tab));
  memcpy(c->ns_tab, zx_ns_tab, sizeof(zx_ns_tab));
  len = zx_LEN_SO_wsse_Nonce(c, x );
  buf = ZX_ALLOC(c, len+1);
  return zx_easy_enc_common(c, zx_ENC_SO_wsse_Nonce(c, x, buf ), buf, len);
}

/* FUNC(zx_EASY_ENC_WO_wsse_Nonce) */

/* Called by: */
struct zx_str* zx_EASY_ENC_WO_wsse_Nonce(struct zx_ctx* c, struct zx_wsse_Nonce_s* x )
{
  int len;
  char* buf;
  c->ns_tab = ZX_ALLOC(c, sizeof(zx_ns_tab));
  memcpy(c->ns_tab, zx_ns_tab, sizeof(zx_ns_tab));
  len = zx_LEN_WO_wsse_Nonce(c, x );
  buf = ZX_ALLOC(c, len+1);
  return zx_easy_enc_common(c, zx_ENC_WO_wsse_Nonce(c, x, buf ), buf, len);
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

#define EL_NAME   wsse_Password
#define EL_STRUCT zx_wsse_Password_s
#define EL_NS     wsse
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

/* FUNC(zx_LEN_SO_wsse_Password) */

/* Compute length of an element (and its subelements). The XML attributes
 * and elements are processed in schema order. */

/* Called by: */
int zx_LEN_SO_wsse_Password(struct zx_ctx* c, struct zx_wsse_Password_s* x )
{
  struct zx_ns_s* pop_seen = 0;
  struct zx_elem_s* se MAYBE_UNUSED;
#if 1 /* NORMALMODE */
  /* *** in simple_elem case should output ns prefix from ns node. */
  int len = sizeof("<wsse:Password")-1 + 1 + sizeof("</wsse:Password>")-1;
  if (c->inc_ns_len)
    len += zx_len_inc_ns(c, &pop_seen);
  len += zx_len_xmlns_if_not_seen(c, zx_ns_tab+zx_xmlns_ix_wsse, &pop_seen);
  if (x->Id)
    len += zx_len_xmlns_if_not_seen(c, zx_ns_tab+zx_xmlns_ix_wsu, &pop_seen);

  len += zx_attr_so_len(x->Type, sizeof("Type")-1);
  len += zx_attr_so_len(x->Id, sizeof("wsu:Id")-1);

#else
  /* root node has no begin tag */
  int len = 0;
#endif
  


  len += zx_len_so_common(c, &x->gg);
  zx_pop_seen(pop_seen);
  ENC_LEN_DEBUG(x, "wsse:Password", len);
  return len;
}

/* FUNC(zx_LEN_WO_wsse_Password) */

/* Compute length of an element (and its subelements). The XML attributes
 * and elements are processed in wire order and no assumptions
 * are made about namespace prefixes. */

/* Called by: */
int zx_LEN_WO_wsse_Password(struct zx_ctx* c, struct zx_wsse_Password_s* x )
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
  if (x->Id)
    len += zx_len_xmlns_if_not_seen(c, x->Id->g.ns, &pop_seen);

  len += zx_attr_wo_len(x->Type, sizeof("Type")-1);
  len += zx_attr_wo_len(x->Id, sizeof("Id")-1);

#else
  /* root node has no begin tag */
  int len = 0;
#endif
  


  len += zx_len_wo_common(c, &x->gg); 
  zx_pop_seen(pop_seen);
  ENC_LEN_DEBUG(x, "wsse:Password", len);
  return len;
}

/* FUNC(zx_ENC_SO_wsse_Password) */

/* Render element into string. The XML attributes and elements are
 * processed in schema order. This is what you generally want for
 * rendering new data structure to a string. The wo pointers are not used. */

/* Called by: */
char* zx_ENC_SO_wsse_Password(struct zx_ctx* c, struct zx_wsse_Password_s* x, char* p )
{
  struct zx_elem_s* se MAYBE_UNUSED;
  ENC_LEN_DEBUG_BASE;
#if 1 /* NORMALMODE */
  struct zx_ns_s* pop_seen = 0;
  /* *** in simple_elem case should output ns prefix from ns node. */
  ZX_OUT_TAG(p, "<wsse:Password");
  if (c->inc_ns)
    p = zx_enc_inc_ns(c, p, &pop_seen);
  p = zx_enc_xmlns_if_not_seen(c, p, zx_ns_tab+zx_xmlns_ix_wsse, &pop_seen);
  if (x->Id)
    p = zx_enc_xmlns_if_not_seen(c, p, zx_ns_tab+zx_xmlns_ix_wsu, &pop_seen);

  p = zx_attr_so_enc(p, x->Type, " Type=\"", sizeof(" Type=\"")-1);
  p = zx_attr_so_enc(p, x->Id, " wsu:Id=\"", sizeof(" wsu:Id=\"")-1);

  p = zx_enc_unknown_attrs(p, x->gg.any_attr);
#else
  /* root node has no begin tag */
#endif
  

  p = zx_enc_so_unknown_elems_and_content(c, p, &x->gg);
  
#if 1 /* NORMALMODE */
  ZX_OUT_CLOSE_TAG(p, "</wsse:Password>");
  zx_pop_seen(pop_seen);
#else
  /* root node has no end tag either */
#endif
  ENC_LEN_DEBUG(x, "wsse:Password", p-enc_base);
  return p;
}

/* FUNC(zx_ENC_WO_wsse_Password) */

/* Render element into string. The XML attributes and elements are
 * processed in wire order by chasing wo pointers. This is what you want for
 * validating signatures on other people's XML documents. */

/* Called by: */
char* zx_ENC_WO_wsse_Password(struct zx_ctx* c, struct zx_wsse_Password_s* x, char* p )
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
  if (x->Id)
    zx_add_xmlns_if_not_seen(c, x->Id->g.ns, &pop_seen);

  p = zx_enc_seen(p, pop_seen); 
  p = zx_attr_wo_enc(p, x->Type, "Type=\"", sizeof("Type=\"")-1);
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
  ENC_LEN_DEBUG(x, "wsse:Password", p-enc_base);
  return p;
}

/* FUNC(zx_EASY_ENC_SO_wsse_Password) */

/* Called by: */
struct zx_str* zx_EASY_ENC_SO_wsse_Password(struct zx_ctx* c, struct zx_wsse_Password_s* x )
{
  int len;
  char* buf;
  c->ns_tab = ZX_ALLOC(c, sizeof(zx_ns_tab));
  memcpy(c->ns_tab, zx_ns_tab, sizeof(zx_ns_tab));
  len = zx_LEN_SO_wsse_Password(c, x );
  buf = ZX_ALLOC(c, len+1);
  return zx_easy_enc_common(c, zx_ENC_SO_wsse_Password(c, x, buf ), buf, len);
}

/* FUNC(zx_EASY_ENC_WO_wsse_Password) */

/* Called by: */
struct zx_str* zx_EASY_ENC_WO_wsse_Password(struct zx_ctx* c, struct zx_wsse_Password_s* x )
{
  int len;
  char* buf;
  c->ns_tab = ZX_ALLOC(c, sizeof(zx_ns_tab));
  memcpy(c->ns_tab, zx_ns_tab, sizeof(zx_ns_tab));
  len = zx_LEN_WO_wsse_Password(c, x );
  buf = ZX_ALLOC(c, len+1);
  return zx_easy_enc_common(c, zx_ENC_WO_wsse_Password(c, x, buf ), buf, len);
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

#define EL_NAME   wsse_Reference
#define EL_STRUCT zx_wsse_Reference_s
#define EL_NS     wsse
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

/* FUNC(zx_LEN_SO_wsse_Reference) */

/* Compute length of an element (and its subelements). The XML attributes
 * and elements are processed in schema order. */

/* Called by: */
int zx_LEN_SO_wsse_Reference(struct zx_ctx* c, struct zx_wsse_Reference_s* x )
{
  struct zx_ns_s* pop_seen = 0;
  struct zx_elem_s* se MAYBE_UNUSED;
#if 1 /* NORMALMODE */
  /* *** in simple_elem case should output ns prefix from ns node. */
  int len = sizeof("<wsse:Reference")-1 + 1 + sizeof("</wsse:Reference>")-1;
  if (c->inc_ns_len)
    len += zx_len_inc_ns(c, &pop_seen);
  len += zx_len_xmlns_if_not_seen(c, zx_ns_tab+zx_xmlns_ix_wsse, &pop_seen);

  len += zx_attr_so_len(x->URI, sizeof("URI")-1);
  len += zx_attr_so_len(x->ValueType, sizeof("ValueType")-1);

#else
  /* root node has no begin tag */
  int len = 0;
#endif
  


  len += zx_len_so_common(c, &x->gg);
  zx_pop_seen(pop_seen);
  ENC_LEN_DEBUG(x, "wsse:Reference", len);
  return len;
}

/* FUNC(zx_LEN_WO_wsse_Reference) */

/* Compute length of an element (and its subelements). The XML attributes
 * and elements are processed in wire order and no assumptions
 * are made about namespace prefixes. */

/* Called by: */
int zx_LEN_WO_wsse_Reference(struct zx_ctx* c, struct zx_wsse_Reference_s* x )
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

  len += zx_attr_wo_len(x->URI, sizeof("URI")-1);
  len += zx_attr_wo_len(x->ValueType, sizeof("ValueType")-1);

#else
  /* root node has no begin tag */
  int len = 0;
#endif
  


  len += zx_len_wo_common(c, &x->gg); 
  zx_pop_seen(pop_seen);
  ENC_LEN_DEBUG(x, "wsse:Reference", len);
  return len;
}

/* FUNC(zx_ENC_SO_wsse_Reference) */

/* Render element into string. The XML attributes and elements are
 * processed in schema order. This is what you generally want for
 * rendering new data structure to a string. The wo pointers are not used. */

/* Called by: */
char* zx_ENC_SO_wsse_Reference(struct zx_ctx* c, struct zx_wsse_Reference_s* x, char* p )
{
  struct zx_elem_s* se MAYBE_UNUSED;
  ENC_LEN_DEBUG_BASE;
#if 1 /* NORMALMODE */
  struct zx_ns_s* pop_seen = 0;
  /* *** in simple_elem case should output ns prefix from ns node. */
  ZX_OUT_TAG(p, "<wsse:Reference");
  if (c->inc_ns)
    p = zx_enc_inc_ns(c, p, &pop_seen);
  p = zx_enc_xmlns_if_not_seen(c, p, zx_ns_tab+zx_xmlns_ix_wsse, &pop_seen);

  p = zx_attr_so_enc(p, x->URI, " URI=\"", sizeof(" URI=\"")-1);
  p = zx_attr_so_enc(p, x->ValueType, " ValueType=\"", sizeof(" ValueType=\"")-1);

  p = zx_enc_unknown_attrs(p, x->gg.any_attr);
#else
  /* root node has no begin tag */
#endif
  

  p = zx_enc_so_unknown_elems_and_content(c, p, &x->gg);
  
#if 1 /* NORMALMODE */
  ZX_OUT_CLOSE_TAG(p, "</wsse:Reference>");
  zx_pop_seen(pop_seen);
#else
  /* root node has no end tag either */
#endif
  ENC_LEN_DEBUG(x, "wsse:Reference", p-enc_base);
  return p;
}

/* FUNC(zx_ENC_WO_wsse_Reference) */

/* Render element into string. The XML attributes and elements are
 * processed in wire order by chasing wo pointers. This is what you want for
 * validating signatures on other people's XML documents. */

/* Called by: */
char* zx_ENC_WO_wsse_Reference(struct zx_ctx* c, struct zx_wsse_Reference_s* x, char* p )
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
  p = zx_attr_wo_enc(p, x->URI, "URI=\"", sizeof("URI=\"")-1);
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
  ENC_LEN_DEBUG(x, "wsse:Reference", p-enc_base);
  return p;
}

/* FUNC(zx_EASY_ENC_SO_wsse_Reference) */

/* Called by: */
struct zx_str* zx_EASY_ENC_SO_wsse_Reference(struct zx_ctx* c, struct zx_wsse_Reference_s* x )
{
  int len;
  char* buf;
  c->ns_tab = ZX_ALLOC(c, sizeof(zx_ns_tab));
  memcpy(c->ns_tab, zx_ns_tab, sizeof(zx_ns_tab));
  len = zx_LEN_SO_wsse_Reference(c, x );
  buf = ZX_ALLOC(c, len+1);
  return zx_easy_enc_common(c, zx_ENC_SO_wsse_Reference(c, x, buf ), buf, len);
}

/* FUNC(zx_EASY_ENC_WO_wsse_Reference) */

/* Called by: */
struct zx_str* zx_EASY_ENC_WO_wsse_Reference(struct zx_ctx* c, struct zx_wsse_Reference_s* x )
{
  int len;
  char* buf;
  c->ns_tab = ZX_ALLOC(c, sizeof(zx_ns_tab));
  memcpy(c->ns_tab, zx_ns_tab, sizeof(zx_ns_tab));
  len = zx_LEN_WO_wsse_Reference(c, x );
  buf = ZX_ALLOC(c, len+1);
  return zx_easy_enc_common(c, zx_ENC_WO_wsse_Reference(c, x, buf ), buf, len);
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

#define EL_NAME   wsse_Security
#define EL_STRUCT zx_wsse_Security_s
#define EL_NS     wsse
#define EL_TAG    Security

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

/* FUNC(zx_LEN_SO_wsse_Security) */

/* Compute length of an element (and its subelements). The XML attributes
 * and elements are processed in schema order. */

/* Called by: */
int zx_LEN_SO_wsse_Security(struct zx_ctx* c, struct zx_wsse_Security_s* x )
{
  struct zx_ns_s* pop_seen = 0;
  struct zx_elem_s* se MAYBE_UNUSED;
#if 1 /* NORMALMODE */
  /* *** in simple_elem case should output ns prefix from ns node. */
  int len = sizeof("<wsse:Security")-1 + 1 + sizeof("</wsse:Security>")-1;
  if (c->inc_ns_len)
    len += zx_len_inc_ns(c, &pop_seen);
  if (x->actor || x->mustUnderstand)
    len += zx_len_xmlns_if_not_seen(c, zx_ns_tab+zx_xmlns_ix_e, &pop_seen);
  len += zx_len_xmlns_if_not_seen(c, zx_ns_tab+zx_xmlns_ix_wsse, &pop_seen);
  if (x->Id)
    len += zx_len_xmlns_if_not_seen(c, zx_ns_tab+zx_xmlns_ix_wsu, &pop_seen);

  len += zx_attr_so_len(x->Id, sizeof("wsu:Id")-1);
  len += zx_attr_so_len(x->actor, sizeof("e:actor")-1);
  len += zx_attr_so_len(x->mustUnderstand, sizeof("e:mustUnderstand")-1);

#else
  /* root node has no begin tag */
  int len = 0;
#endif
  
  {
      struct zx_ds_Signature_s* e;
      for (e = x->Signature; e; e = (struct zx_ds_Signature_s*)e->gg.g.n)
	  if (e != c->exclude_sig)
              len += zx_LEN_SO_ds_Signature(c, e);
  }
  {
      struct zx_sa_Assertion_s* e;
      for (e = x->Assertion; e; e = (struct zx_sa_Assertion_s*)e->gg.g.n)
	  len += zx_LEN_SO_sa_Assertion(c, e);
  }
  {
      struct zx_sa_EncryptedAssertion_s* e;
      for (e = x->EncryptedAssertion; e; e = (struct zx_sa_EncryptedAssertion_s*)e->gg.g.n)
	  len += zx_LEN_SO_sa_EncryptedAssertion(c, e);
  }
  {
      struct zx_sa11_Assertion_s* e;
      for (e = x->sa11_Assertion; e; e = (struct zx_sa11_Assertion_s*)e->gg.g.n)
	  len += zx_LEN_SO_sa11_Assertion(c, e);
  }
  {
      struct zx_ff12_Assertion_s* e;
      for (e = x->ff12_Assertion; e; e = (struct zx_ff12_Assertion_s*)e->gg.g.n)
	  len += zx_LEN_SO_ff12_Assertion(c, e);
  }
  {
      struct zx_wsse_BinarySecurityToken_s* e;
      for (e = x->BinarySecurityToken; e; e = (struct zx_wsse_BinarySecurityToken_s*)e->gg.g.n)
	  len += zx_LEN_SO_wsse_BinarySecurityToken(c, e);
  }
  {
      struct zx_wsse_SecurityTokenReference_s* e;
      for (e = x->SecurityTokenReference; e; e = (struct zx_wsse_SecurityTokenReference_s*)e->gg.g.n)
	  len += zx_LEN_SO_wsse_SecurityTokenReference(c, e);
  }
  {
      struct zx_wsu_Timestamp_s* e;
      for (e = x->Timestamp; e; e = (struct zx_wsu_Timestamp_s*)e->gg.g.n)
	  len += zx_LEN_SO_wsu_Timestamp(c, e);
  }


  len += zx_len_so_common(c, &x->gg);
  zx_pop_seen(pop_seen);
  ENC_LEN_DEBUG(x, "wsse:Security", len);
  return len;
}

/* FUNC(zx_LEN_WO_wsse_Security) */

/* Compute length of an element (and its subelements). The XML attributes
 * and elements are processed in wire order and no assumptions
 * are made about namespace prefixes. */

/* Called by: */
int zx_LEN_WO_wsse_Security(struct zx_ctx* c, struct zx_wsse_Security_s* x )
{
  struct zx_ns_s* pop_seen = 0;
  struct zx_elem_s* se MAYBE_UNUSED;
#if 1 /* NORMALMODE */
  int len = 1 + sizeof("Security")-1 + 1 + 2 + sizeof("Security")-1 + 1;
  
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

  len += zx_attr_wo_len(x->Id, sizeof("Id")-1);
  len += zx_attr_wo_len(x->actor, sizeof("actor")-1);
  len += zx_attr_wo_len(x->mustUnderstand, sizeof("mustUnderstand")-1);

#else
  /* root node has no begin tag */
  int len = 0;
#endif
  
  {
      struct zx_ds_Signature_s* e;
      for (e = x->Signature; e; e = (struct zx_ds_Signature_s*)e->gg.g.n)
	  if (e != c->exclude_sig)
              len += zx_LEN_WO_ds_Signature(c, e);
  }
  {
      struct zx_sa_Assertion_s* e;
      for (e = x->Assertion; e; e = (struct zx_sa_Assertion_s*)e->gg.g.n)
	  len += zx_LEN_WO_sa_Assertion(c, e);
  }
  {
      struct zx_sa_EncryptedAssertion_s* e;
      for (e = x->EncryptedAssertion; e; e = (struct zx_sa_EncryptedAssertion_s*)e->gg.g.n)
	  len += zx_LEN_WO_sa_EncryptedAssertion(c, e);
  }
  {
      struct zx_sa11_Assertion_s* e;
      for (e = x->sa11_Assertion; e; e = (struct zx_sa11_Assertion_s*)e->gg.g.n)
	  len += zx_LEN_WO_sa11_Assertion(c, e);
  }
  {
      struct zx_ff12_Assertion_s* e;
      for (e = x->ff12_Assertion; e; e = (struct zx_ff12_Assertion_s*)e->gg.g.n)
	  len += zx_LEN_WO_ff12_Assertion(c, e);
  }
  {
      struct zx_wsse_BinarySecurityToken_s* e;
      for (e = x->BinarySecurityToken; e; e = (struct zx_wsse_BinarySecurityToken_s*)e->gg.g.n)
	  len += zx_LEN_WO_wsse_BinarySecurityToken(c, e);
  }
  {
      struct zx_wsse_SecurityTokenReference_s* e;
      for (e = x->SecurityTokenReference; e; e = (struct zx_wsse_SecurityTokenReference_s*)e->gg.g.n)
	  len += zx_LEN_WO_wsse_SecurityTokenReference(c, e);
  }
  {
      struct zx_wsu_Timestamp_s* e;
      for (e = x->Timestamp; e; e = (struct zx_wsu_Timestamp_s*)e->gg.g.n)
	  len += zx_LEN_WO_wsu_Timestamp(c, e);
  }


  len += zx_len_wo_common(c, &x->gg); 
  zx_pop_seen(pop_seen);
  ENC_LEN_DEBUG(x, "wsse:Security", len);
  return len;
}

/* FUNC(zx_ENC_SO_wsse_Security) */

/* Render element into string. The XML attributes and elements are
 * processed in schema order. This is what you generally want for
 * rendering new data structure to a string. The wo pointers are not used. */

/* Called by: */
char* zx_ENC_SO_wsse_Security(struct zx_ctx* c, struct zx_wsse_Security_s* x, char* p )
{
  struct zx_elem_s* se MAYBE_UNUSED;
  ENC_LEN_DEBUG_BASE;
#if 1 /* NORMALMODE */
  struct zx_ns_s* pop_seen = 0;
  /* *** in simple_elem case should output ns prefix from ns node. */
  ZX_OUT_TAG(p, "<wsse:Security");
  if (c->inc_ns)
    p = zx_enc_inc_ns(c, p, &pop_seen);
  if (x->actor || x->mustUnderstand)
    p = zx_enc_xmlns_if_not_seen(c, p, zx_ns_tab+zx_xmlns_ix_e, &pop_seen);
  p = zx_enc_xmlns_if_not_seen(c, p, zx_ns_tab+zx_xmlns_ix_wsse, &pop_seen);
  if (x->Id)
    p = zx_enc_xmlns_if_not_seen(c, p, zx_ns_tab+zx_xmlns_ix_wsu, &pop_seen);

  p = zx_attr_so_enc(p, x->Id, " wsu:Id=\"", sizeof(" wsu:Id=\"")-1);
  p = zx_attr_so_enc(p, x->actor, " e:actor=\"", sizeof(" e:actor=\"")-1);
  p = zx_attr_so_enc(p, x->mustUnderstand, " e:mustUnderstand=\"", sizeof(" e:mustUnderstand=\"")-1);

  p = zx_enc_unknown_attrs(p, x->gg.any_attr);
#else
  /* root node has no begin tag */
#endif
  
  {
      struct zx_ds_Signature_s* e;
      for (e = x->Signature; e; e = (struct zx_ds_Signature_s*)e->gg.g.n)
	  if (e != c->exclude_sig)
              p = zx_ENC_SO_ds_Signature(c, e, p);
  }
  {
      struct zx_sa_Assertion_s* e;
      for (e = x->Assertion; e; e = (struct zx_sa_Assertion_s*)e->gg.g.n)
	  p = zx_ENC_SO_sa_Assertion(c, e, p);
  }
  {
      struct zx_sa_EncryptedAssertion_s* e;
      for (e = x->EncryptedAssertion; e; e = (struct zx_sa_EncryptedAssertion_s*)e->gg.g.n)
	  p = zx_ENC_SO_sa_EncryptedAssertion(c, e, p);
  }
  {
      struct zx_sa11_Assertion_s* e;
      for (e = x->sa11_Assertion; e; e = (struct zx_sa11_Assertion_s*)e->gg.g.n)
	  p = zx_ENC_SO_sa11_Assertion(c, e, p);
  }
  {
      struct zx_ff12_Assertion_s* e;
      for (e = x->ff12_Assertion; e; e = (struct zx_ff12_Assertion_s*)e->gg.g.n)
	  p = zx_ENC_SO_ff12_Assertion(c, e, p);
  }
  {
      struct zx_wsse_BinarySecurityToken_s* e;
      for (e = x->BinarySecurityToken; e; e = (struct zx_wsse_BinarySecurityToken_s*)e->gg.g.n)
	  p = zx_ENC_SO_wsse_BinarySecurityToken(c, e, p);
  }
  {
      struct zx_wsse_SecurityTokenReference_s* e;
      for (e = x->SecurityTokenReference; e; e = (struct zx_wsse_SecurityTokenReference_s*)e->gg.g.n)
	  p = zx_ENC_SO_wsse_SecurityTokenReference(c, e, p);
  }
  {
      struct zx_wsu_Timestamp_s* e;
      for (e = x->Timestamp; e; e = (struct zx_wsu_Timestamp_s*)e->gg.g.n)
	  p = zx_ENC_SO_wsu_Timestamp(c, e, p);
  }

  p = zx_enc_so_unknown_elems_and_content(c, p, &x->gg);
  
#if 1 /* NORMALMODE */
  ZX_OUT_CLOSE_TAG(p, "</wsse:Security>");
  zx_pop_seen(pop_seen);
#else
  /* root node has no end tag either */
#endif
  ENC_LEN_DEBUG(x, "wsse:Security", p-enc_base);
  return p;
}

/* FUNC(zx_ENC_WO_wsse_Security) */

/* Render element into string. The XML attributes and elements are
 * processed in wire order by chasing wo pointers. This is what you want for
 * validating signatures on other people's XML documents. */

/* Called by: */
char* zx_ENC_WO_wsse_Security(struct zx_ctx* c, struct zx_wsse_Security_s* x, char* p )
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
  ZX_OUT_MEM(p, "Security", sizeof("Security")-1);
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
  ENC_LEN_DEBUG(x, "wsse:Security", p-enc_base);
  return p;
}

/* FUNC(zx_EASY_ENC_SO_wsse_Security) */

/* Called by: */
struct zx_str* zx_EASY_ENC_SO_wsse_Security(struct zx_ctx* c, struct zx_wsse_Security_s* x )
{
  int len;
  char* buf;
  c->ns_tab = ZX_ALLOC(c, sizeof(zx_ns_tab));
  memcpy(c->ns_tab, zx_ns_tab, sizeof(zx_ns_tab));
  len = zx_LEN_SO_wsse_Security(c, x );
  buf = ZX_ALLOC(c, len+1);
  return zx_easy_enc_common(c, zx_ENC_SO_wsse_Security(c, x, buf ), buf, len);
}

/* FUNC(zx_EASY_ENC_WO_wsse_Security) */

/* Called by: */
struct zx_str* zx_EASY_ENC_WO_wsse_Security(struct zx_ctx* c, struct zx_wsse_Security_s* x )
{
  int len;
  char* buf;
  c->ns_tab = ZX_ALLOC(c, sizeof(zx_ns_tab));
  memcpy(c->ns_tab, zx_ns_tab, sizeof(zx_ns_tab));
  len = zx_LEN_WO_wsse_Security(c, x );
  buf = ZX_ALLOC(c, len+1);
  return zx_easy_enc_common(c, zx_ENC_WO_wsse_Security(c, x, buf ), buf, len);
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

#define EL_NAME   wsse_SecurityTokenReference
#define EL_STRUCT zx_wsse_SecurityTokenReference_s
#define EL_NS     wsse
#define EL_TAG    SecurityTokenReference

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

/* FUNC(zx_LEN_SO_wsse_SecurityTokenReference) */

/* Compute length of an element (and its subelements). The XML attributes
 * and elements are processed in schema order. */

/* Called by: */
int zx_LEN_SO_wsse_SecurityTokenReference(struct zx_ctx* c, struct zx_wsse_SecurityTokenReference_s* x )
{
  struct zx_ns_s* pop_seen = 0;
  struct zx_elem_s* se MAYBE_UNUSED;
#if 1 /* NORMALMODE */
  /* *** in simple_elem case should output ns prefix from ns node. */
  int len = sizeof("<wsse:SecurityTokenReference")-1 + 1 + sizeof("</wsse:SecurityTokenReference>")-1;
  if (c->inc_ns_len)
    len += zx_len_inc_ns(c, &pop_seen);
  if (x->Usage)
    len += zx_len_xmlns_if_not_seen(c, zx_ns_tab+zx_xmlns_ix_wsse, &pop_seen);
  if (x->Id)
    len += zx_len_xmlns_if_not_seen(c, zx_ns_tab+zx_xmlns_ix_wsu, &pop_seen);

  len += zx_attr_so_len(x->Usage, sizeof("wsse:Usage")-1);
  len += zx_attr_so_len(x->Id, sizeof("wsu:Id")-1);

#else
  /* root node has no begin tag */
  int len = 0;
#endif
  
  {
      struct zx_wsse_KeyIdentifier_s* e;
      for (e = x->KeyIdentifier; e; e = (struct zx_wsse_KeyIdentifier_s*)e->gg.g.n)
	  len += zx_LEN_SO_wsse_KeyIdentifier(c, e);
  }


  len += zx_len_so_common(c, &x->gg);
  zx_pop_seen(pop_seen);
  ENC_LEN_DEBUG(x, "wsse:SecurityTokenReference", len);
  return len;
}

/* FUNC(zx_LEN_WO_wsse_SecurityTokenReference) */

/* Compute length of an element (and its subelements). The XML attributes
 * and elements are processed in wire order and no assumptions
 * are made about namespace prefixes. */

/* Called by: */
int zx_LEN_WO_wsse_SecurityTokenReference(struct zx_ctx* c, struct zx_wsse_SecurityTokenReference_s* x )
{
  struct zx_ns_s* pop_seen = 0;
  struct zx_elem_s* se MAYBE_UNUSED;
#if 1 /* NORMALMODE */
  int len = 1 + sizeof("SecurityTokenReference")-1 + 1 + 2 + sizeof("SecurityTokenReference")-1 + 1;
  
  if (x->gg.g.ns && x->gg.g.ns->prefix_len)
    len += (x->gg.g.ns->prefix_len + 1) * 2;
  if (c->inc_ns_len)
    len += zx_len_inc_ns(c, &pop_seen);
  if (x->Usage)
    len += zx_len_xmlns_if_not_seen(c, x->Usage->g.ns, &pop_seen);
  if (x->Id)
    len += zx_len_xmlns_if_not_seen(c, x->Id->g.ns, &pop_seen);

  len += zx_attr_wo_len(x->Usage, sizeof("Usage")-1);
  len += zx_attr_wo_len(x->Id, sizeof("Id")-1);

#else
  /* root node has no begin tag */
  int len = 0;
#endif
  
  {
      struct zx_wsse_KeyIdentifier_s* e;
      for (e = x->KeyIdentifier; e; e = (struct zx_wsse_KeyIdentifier_s*)e->gg.g.n)
	  len += zx_LEN_WO_wsse_KeyIdentifier(c, e);
  }


  len += zx_len_wo_common(c, &x->gg); 
  zx_pop_seen(pop_seen);
  ENC_LEN_DEBUG(x, "wsse:SecurityTokenReference", len);
  return len;
}

/* FUNC(zx_ENC_SO_wsse_SecurityTokenReference) */

/* Render element into string. The XML attributes and elements are
 * processed in schema order. This is what you generally want for
 * rendering new data structure to a string. The wo pointers are not used. */

/* Called by: */
char* zx_ENC_SO_wsse_SecurityTokenReference(struct zx_ctx* c, struct zx_wsse_SecurityTokenReference_s* x, char* p )
{
  struct zx_elem_s* se MAYBE_UNUSED;
  ENC_LEN_DEBUG_BASE;
#if 1 /* NORMALMODE */
  struct zx_ns_s* pop_seen = 0;
  /* *** in simple_elem case should output ns prefix from ns node. */
  ZX_OUT_TAG(p, "<wsse:SecurityTokenReference");
  if (c->inc_ns)
    p = zx_enc_inc_ns(c, p, &pop_seen);
  if (x->Usage)
    p = zx_enc_xmlns_if_not_seen(c, p, zx_ns_tab+zx_xmlns_ix_wsse, &pop_seen);
  if (x->Id)
    p = zx_enc_xmlns_if_not_seen(c, p, zx_ns_tab+zx_xmlns_ix_wsu, &pop_seen);

  p = zx_attr_so_enc(p, x->Usage, " wsse:Usage=\"", sizeof(" wsse:Usage=\"")-1);
  p = zx_attr_so_enc(p, x->Id, " wsu:Id=\"", sizeof(" wsu:Id=\"")-1);

  p = zx_enc_unknown_attrs(p, x->gg.any_attr);
#else
  /* root node has no begin tag */
#endif
  
  {
      struct zx_wsse_KeyIdentifier_s* e;
      for (e = x->KeyIdentifier; e; e = (struct zx_wsse_KeyIdentifier_s*)e->gg.g.n)
	  p = zx_ENC_SO_wsse_KeyIdentifier(c, e, p);
  }

  p = zx_enc_so_unknown_elems_and_content(c, p, &x->gg);
  
#if 1 /* NORMALMODE */
  ZX_OUT_CLOSE_TAG(p, "</wsse:SecurityTokenReference>");
  zx_pop_seen(pop_seen);
#else
  /* root node has no end tag either */
#endif
  ENC_LEN_DEBUG(x, "wsse:SecurityTokenReference", p-enc_base);
  return p;
}

/* FUNC(zx_ENC_WO_wsse_SecurityTokenReference) */

/* Render element into string. The XML attributes and elements are
 * processed in wire order by chasing wo pointers. This is what you want for
 * validating signatures on other people's XML documents. */

/* Called by: */
char* zx_ENC_WO_wsse_SecurityTokenReference(struct zx_ctx* c, struct zx_wsse_SecurityTokenReference_s* x, char* p )
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
  ZX_OUT_MEM(p, "SecurityTokenReference", sizeof("SecurityTokenReference")-1);
  qq = p;

  /* *** sort the namespaces */
  if (c->inc_ns)
    zx_add_inc_ns(c, &pop_seen);
  if (x->Usage)
    zx_add_xmlns_if_not_seen(c, x->Usage->g.ns, &pop_seen);
  if (x->Id)
    zx_add_xmlns_if_not_seen(c, x->Id->g.ns, &pop_seen);

  p = zx_enc_seen(p, pop_seen); 
  p = zx_attr_wo_enc(p, x->Usage, "Usage=\"", sizeof("Usage=\"")-1);
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
  ENC_LEN_DEBUG(x, "wsse:SecurityTokenReference", p-enc_base);
  return p;
}

/* FUNC(zx_EASY_ENC_SO_wsse_SecurityTokenReference) */

/* Called by: */
struct zx_str* zx_EASY_ENC_SO_wsse_SecurityTokenReference(struct zx_ctx* c, struct zx_wsse_SecurityTokenReference_s* x )
{
  int len;
  char* buf;
  c->ns_tab = ZX_ALLOC(c, sizeof(zx_ns_tab));
  memcpy(c->ns_tab, zx_ns_tab, sizeof(zx_ns_tab));
  len = zx_LEN_SO_wsse_SecurityTokenReference(c, x );
  buf = ZX_ALLOC(c, len+1);
  return zx_easy_enc_common(c, zx_ENC_SO_wsse_SecurityTokenReference(c, x, buf ), buf, len);
}

/* FUNC(zx_EASY_ENC_WO_wsse_SecurityTokenReference) */

/* Called by: */
struct zx_str* zx_EASY_ENC_WO_wsse_SecurityTokenReference(struct zx_ctx* c, struct zx_wsse_SecurityTokenReference_s* x )
{
  int len;
  char* buf;
  c->ns_tab = ZX_ALLOC(c, sizeof(zx_ns_tab));
  memcpy(c->ns_tab, zx_ns_tab, sizeof(zx_ns_tab));
  len = zx_LEN_WO_wsse_SecurityTokenReference(c, x );
  buf = ZX_ALLOC(c, len+1);
  return zx_easy_enc_common(c, zx_ENC_WO_wsse_SecurityTokenReference(c, x, buf ), buf, len);
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

#define EL_NAME   wsse_TransformationParameters
#define EL_STRUCT zx_wsse_TransformationParameters_s
#define EL_NS     wsse
#define EL_TAG    TransformationParameters

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

/* FUNC(zx_LEN_SO_wsse_TransformationParameters) */

/* Compute length of an element (and its subelements). The XML attributes
 * and elements are processed in schema order. */

/* Called by: */
int zx_LEN_SO_wsse_TransformationParameters(struct zx_ctx* c, struct zx_wsse_TransformationParameters_s* x )
{
  struct zx_ns_s* pop_seen = 0;
  struct zx_elem_s* se MAYBE_UNUSED;
#if 1 /* NORMALMODE */
  /* *** in simple_elem case should output ns prefix from ns node. */
  int len = sizeof("<wsse:TransformationParameters")-1 + 1 + sizeof("</wsse:TransformationParameters>")-1;
  if (c->inc_ns_len)
    len += zx_len_inc_ns(c, &pop_seen);
  len += zx_len_xmlns_if_not_seen(c, zx_ns_tab+zx_xmlns_ix_wsse, &pop_seen);


#else
  /* root node has no begin tag */
  int len = 0;
#endif
  


  len += zx_len_so_common(c, &x->gg);
  zx_pop_seen(pop_seen);
  ENC_LEN_DEBUG(x, "wsse:TransformationParameters", len);
  return len;
}

/* FUNC(zx_LEN_WO_wsse_TransformationParameters) */

/* Compute length of an element (and its subelements). The XML attributes
 * and elements are processed in wire order and no assumptions
 * are made about namespace prefixes. */

/* Called by: */
int zx_LEN_WO_wsse_TransformationParameters(struct zx_ctx* c, struct zx_wsse_TransformationParameters_s* x )
{
  struct zx_ns_s* pop_seen = 0;
  struct zx_elem_s* se MAYBE_UNUSED;
#if 1 /* NORMALMODE */
  int len = 1 + sizeof("TransformationParameters")-1 + 1 + 2 + sizeof("TransformationParameters")-1 + 1;
  
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
  ENC_LEN_DEBUG(x, "wsse:TransformationParameters", len);
  return len;
}

/* FUNC(zx_ENC_SO_wsse_TransformationParameters) */

/* Render element into string. The XML attributes and elements are
 * processed in schema order. This is what you generally want for
 * rendering new data structure to a string. The wo pointers are not used. */

/* Called by: */
char* zx_ENC_SO_wsse_TransformationParameters(struct zx_ctx* c, struct zx_wsse_TransformationParameters_s* x, char* p )
{
  struct zx_elem_s* se MAYBE_UNUSED;
  ENC_LEN_DEBUG_BASE;
#if 1 /* NORMALMODE */
  struct zx_ns_s* pop_seen = 0;
  /* *** in simple_elem case should output ns prefix from ns node. */
  ZX_OUT_TAG(p, "<wsse:TransformationParameters");
  if (c->inc_ns)
    p = zx_enc_inc_ns(c, p, &pop_seen);
  p = zx_enc_xmlns_if_not_seen(c, p, zx_ns_tab+zx_xmlns_ix_wsse, &pop_seen);


  p = zx_enc_unknown_attrs(p, x->gg.any_attr);
#else
  /* root node has no begin tag */
#endif
  

  p = zx_enc_so_unknown_elems_and_content(c, p, &x->gg);
  
#if 1 /* NORMALMODE */
  ZX_OUT_CLOSE_TAG(p, "</wsse:TransformationParameters>");
  zx_pop_seen(pop_seen);
#else
  /* root node has no end tag either */
#endif
  ENC_LEN_DEBUG(x, "wsse:TransformationParameters", p-enc_base);
  return p;
}

/* FUNC(zx_ENC_WO_wsse_TransformationParameters) */

/* Render element into string. The XML attributes and elements are
 * processed in wire order by chasing wo pointers. This is what you want for
 * validating signatures on other people's XML documents. */

/* Called by: */
char* zx_ENC_WO_wsse_TransformationParameters(struct zx_ctx* c, struct zx_wsse_TransformationParameters_s* x, char* p )
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
  ZX_OUT_MEM(p, "TransformationParameters", sizeof("TransformationParameters")-1);
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
  ENC_LEN_DEBUG(x, "wsse:TransformationParameters", p-enc_base);
  return p;
}

/* FUNC(zx_EASY_ENC_SO_wsse_TransformationParameters) */

/* Called by: */
struct zx_str* zx_EASY_ENC_SO_wsse_TransformationParameters(struct zx_ctx* c, struct zx_wsse_TransformationParameters_s* x )
{
  int len;
  char* buf;
  c->ns_tab = ZX_ALLOC(c, sizeof(zx_ns_tab));
  memcpy(c->ns_tab, zx_ns_tab, sizeof(zx_ns_tab));
  len = zx_LEN_SO_wsse_TransformationParameters(c, x );
  buf = ZX_ALLOC(c, len+1);
  return zx_easy_enc_common(c, zx_ENC_SO_wsse_TransformationParameters(c, x, buf ), buf, len);
}

/* FUNC(zx_EASY_ENC_WO_wsse_TransformationParameters) */

/* Called by: */
struct zx_str* zx_EASY_ENC_WO_wsse_TransformationParameters(struct zx_ctx* c, struct zx_wsse_TransformationParameters_s* x )
{
  int len;
  char* buf;
  c->ns_tab = ZX_ALLOC(c, sizeof(zx_ns_tab));
  memcpy(c->ns_tab, zx_ns_tab, sizeof(zx_ns_tab));
  len = zx_LEN_WO_wsse_TransformationParameters(c, x );
  buf = ZX_ALLOC(c, len+1);
  return zx_easy_enc_common(c, zx_ENC_WO_wsse_TransformationParameters(c, x, buf ), buf, len);
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

#define EL_NAME   wsse_Username
#define EL_STRUCT zx_wsse_Username_s
#define EL_NS     wsse
#define EL_TAG    Username

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

/* FUNC(zx_LEN_SO_wsse_Username) */

/* Compute length of an element (and its subelements). The XML attributes
 * and elements are processed in schema order. */

/* Called by: */
int zx_LEN_SO_wsse_Username(struct zx_ctx* c, struct zx_wsse_Username_s* x )
{
  struct zx_ns_s* pop_seen = 0;
  struct zx_elem_s* se MAYBE_UNUSED;
#if 1 /* NORMALMODE */
  /* *** in simple_elem case should output ns prefix from ns node. */
  int len = sizeof("<wsse:Username")-1 + 1 + sizeof("</wsse:Username>")-1;
  if (c->inc_ns_len)
    len += zx_len_inc_ns(c, &pop_seen);
  len += zx_len_xmlns_if_not_seen(c, zx_ns_tab+zx_xmlns_ix_wsse, &pop_seen);
  if (x->Id)
    len += zx_len_xmlns_if_not_seen(c, zx_ns_tab+zx_xmlns_ix_wsu, &pop_seen);

  len += zx_attr_so_len(x->Id, sizeof("wsu:Id")-1);

#else
  /* root node has no begin tag */
  int len = 0;
#endif
  


  len += zx_len_so_common(c, &x->gg);
  zx_pop_seen(pop_seen);
  ENC_LEN_DEBUG(x, "wsse:Username", len);
  return len;
}

/* FUNC(zx_LEN_WO_wsse_Username) */

/* Compute length of an element (and its subelements). The XML attributes
 * and elements are processed in wire order and no assumptions
 * are made about namespace prefixes. */

/* Called by: */
int zx_LEN_WO_wsse_Username(struct zx_ctx* c, struct zx_wsse_Username_s* x )
{
  struct zx_ns_s* pop_seen = 0;
  struct zx_elem_s* se MAYBE_UNUSED;
#if 1 /* NORMALMODE */
  int len = 1 + sizeof("Username")-1 + 1 + 2 + sizeof("Username")-1 + 1;
  
  if (x->gg.g.ns && x->gg.g.ns->prefix_len)
    len += (x->gg.g.ns->prefix_len + 1) * 2;
  if (c->inc_ns_len)
    len += zx_len_inc_ns(c, &pop_seen);
  len += zx_len_xmlns_if_not_seen(c, x->gg.g.ns, &pop_seen);
  if (x->Id)
    len += zx_len_xmlns_if_not_seen(c, x->Id->g.ns, &pop_seen);

  len += zx_attr_wo_len(x->Id, sizeof("Id")-1);

#else
  /* root node has no begin tag */
  int len = 0;
#endif
  


  len += zx_len_wo_common(c, &x->gg); 
  zx_pop_seen(pop_seen);
  ENC_LEN_DEBUG(x, "wsse:Username", len);
  return len;
}

/* FUNC(zx_ENC_SO_wsse_Username) */

/* Render element into string. The XML attributes and elements are
 * processed in schema order. This is what you generally want for
 * rendering new data structure to a string. The wo pointers are not used. */

/* Called by: */
char* zx_ENC_SO_wsse_Username(struct zx_ctx* c, struct zx_wsse_Username_s* x, char* p )
{
  struct zx_elem_s* se MAYBE_UNUSED;
  ENC_LEN_DEBUG_BASE;
#if 1 /* NORMALMODE */
  struct zx_ns_s* pop_seen = 0;
  /* *** in simple_elem case should output ns prefix from ns node. */
  ZX_OUT_TAG(p, "<wsse:Username");
  if (c->inc_ns)
    p = zx_enc_inc_ns(c, p, &pop_seen);
  p = zx_enc_xmlns_if_not_seen(c, p, zx_ns_tab+zx_xmlns_ix_wsse, &pop_seen);
  if (x->Id)
    p = zx_enc_xmlns_if_not_seen(c, p, zx_ns_tab+zx_xmlns_ix_wsu, &pop_seen);

  p = zx_attr_so_enc(p, x->Id, " wsu:Id=\"", sizeof(" wsu:Id=\"")-1);

  p = zx_enc_unknown_attrs(p, x->gg.any_attr);
#else
  /* root node has no begin tag */
#endif
  

  p = zx_enc_so_unknown_elems_and_content(c, p, &x->gg);
  
#if 1 /* NORMALMODE */
  ZX_OUT_CLOSE_TAG(p, "</wsse:Username>");
  zx_pop_seen(pop_seen);
#else
  /* root node has no end tag either */
#endif
  ENC_LEN_DEBUG(x, "wsse:Username", p-enc_base);
  return p;
}

/* FUNC(zx_ENC_WO_wsse_Username) */

/* Render element into string. The XML attributes and elements are
 * processed in wire order by chasing wo pointers. This is what you want for
 * validating signatures on other people's XML documents. */

/* Called by: */
char* zx_ENC_WO_wsse_Username(struct zx_ctx* c, struct zx_wsse_Username_s* x, char* p )
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
  ZX_OUT_MEM(p, "Username", sizeof("Username")-1);
  qq = p;

  /* *** sort the namespaces */
  if (c->inc_ns)
    zx_add_inc_ns(c, &pop_seen);
  zx_add_xmlns_if_not_seen(c, x->gg.g.ns, &pop_seen);
  if (x->Id)
    zx_add_xmlns_if_not_seen(c, x->Id->g.ns, &pop_seen);

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
  ENC_LEN_DEBUG(x, "wsse:Username", p-enc_base);
  return p;
}

/* FUNC(zx_EASY_ENC_SO_wsse_Username) */

/* Called by: */
struct zx_str* zx_EASY_ENC_SO_wsse_Username(struct zx_ctx* c, struct zx_wsse_Username_s* x )
{
  int len;
  char* buf;
  c->ns_tab = ZX_ALLOC(c, sizeof(zx_ns_tab));
  memcpy(c->ns_tab, zx_ns_tab, sizeof(zx_ns_tab));
  len = zx_LEN_SO_wsse_Username(c, x );
  buf = ZX_ALLOC(c, len+1);
  return zx_easy_enc_common(c, zx_ENC_SO_wsse_Username(c, x, buf ), buf, len);
}

/* FUNC(zx_EASY_ENC_WO_wsse_Username) */

/* Called by: */
struct zx_str* zx_EASY_ENC_WO_wsse_Username(struct zx_ctx* c, struct zx_wsse_Username_s* x )
{
  int len;
  char* buf;
  c->ns_tab = ZX_ALLOC(c, sizeof(zx_ns_tab));
  memcpy(c->ns_tab, zx_ns_tab, sizeof(zx_ns_tab));
  len = zx_LEN_WO_wsse_Username(c, x );
  buf = ZX_ALLOC(c, len+1);
  return zx_easy_enc_common(c, zx_ENC_WO_wsse_Username(c, x, buf ), buf, len);
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

#define EL_NAME   wsse_UsernameToken
#define EL_STRUCT zx_wsse_UsernameToken_s
#define EL_NS     wsse
#define EL_TAG    UsernameToken

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

/* FUNC(zx_LEN_SO_wsse_UsernameToken) */

/* Compute length of an element (and its subelements). The XML attributes
 * and elements are processed in schema order. */

/* Called by: */
int zx_LEN_SO_wsse_UsernameToken(struct zx_ctx* c, struct zx_wsse_UsernameToken_s* x )
{
  struct zx_ns_s* pop_seen = 0;
  struct zx_elem_s* se MAYBE_UNUSED;
#if 1 /* NORMALMODE */
  /* *** in simple_elem case should output ns prefix from ns node. */
  int len = sizeof("<wsse:UsernameToken")-1 + 1 + sizeof("</wsse:UsernameToken>")-1;
  if (c->inc_ns_len)
    len += zx_len_inc_ns(c, &pop_seen);
  len += zx_len_xmlns_if_not_seen(c, zx_ns_tab+zx_xmlns_ix_wsse, &pop_seen);
  if (x->Id)
    len += zx_len_xmlns_if_not_seen(c, zx_ns_tab+zx_xmlns_ix_wsu, &pop_seen);

  len += zx_attr_so_len(x->Id, sizeof("wsu:Id")-1);

#else
  /* root node has no begin tag */
  int len = 0;
#endif
  
  {
      struct zx_wsse_Username_s* e;
      for (e = x->Username; e; e = (struct zx_wsse_Username_s*)e->gg.g.n)
	  len += zx_LEN_SO_wsse_Username(c, e);
  }


  len += zx_len_so_common(c, &x->gg);
  zx_pop_seen(pop_seen);
  ENC_LEN_DEBUG(x, "wsse:UsernameToken", len);
  return len;
}

/* FUNC(zx_LEN_WO_wsse_UsernameToken) */

/* Compute length of an element (and its subelements). The XML attributes
 * and elements are processed in wire order and no assumptions
 * are made about namespace prefixes. */

/* Called by: */
int zx_LEN_WO_wsse_UsernameToken(struct zx_ctx* c, struct zx_wsse_UsernameToken_s* x )
{
  struct zx_ns_s* pop_seen = 0;
  struct zx_elem_s* se MAYBE_UNUSED;
#if 1 /* NORMALMODE */
  int len = 1 + sizeof("UsernameToken")-1 + 1 + 2 + sizeof("UsernameToken")-1 + 1;
  
  if (x->gg.g.ns && x->gg.g.ns->prefix_len)
    len += (x->gg.g.ns->prefix_len + 1) * 2;
  if (c->inc_ns_len)
    len += zx_len_inc_ns(c, &pop_seen);
  len += zx_len_xmlns_if_not_seen(c, x->gg.g.ns, &pop_seen);
  if (x->Id)
    len += zx_len_xmlns_if_not_seen(c, x->Id->g.ns, &pop_seen);

  len += zx_attr_wo_len(x->Id, sizeof("Id")-1);

#else
  /* root node has no begin tag */
  int len = 0;
#endif
  
  {
      struct zx_wsse_Username_s* e;
      for (e = x->Username; e; e = (struct zx_wsse_Username_s*)e->gg.g.n)
	  len += zx_LEN_WO_wsse_Username(c, e);
  }


  len += zx_len_wo_common(c, &x->gg); 
  zx_pop_seen(pop_seen);
  ENC_LEN_DEBUG(x, "wsse:UsernameToken", len);
  return len;
}

/* FUNC(zx_ENC_SO_wsse_UsernameToken) */

/* Render element into string. The XML attributes and elements are
 * processed in schema order. This is what you generally want for
 * rendering new data structure to a string. The wo pointers are not used. */

/* Called by: */
char* zx_ENC_SO_wsse_UsernameToken(struct zx_ctx* c, struct zx_wsse_UsernameToken_s* x, char* p )
{
  struct zx_elem_s* se MAYBE_UNUSED;
  ENC_LEN_DEBUG_BASE;
#if 1 /* NORMALMODE */
  struct zx_ns_s* pop_seen = 0;
  /* *** in simple_elem case should output ns prefix from ns node. */
  ZX_OUT_TAG(p, "<wsse:UsernameToken");
  if (c->inc_ns)
    p = zx_enc_inc_ns(c, p, &pop_seen);
  p = zx_enc_xmlns_if_not_seen(c, p, zx_ns_tab+zx_xmlns_ix_wsse, &pop_seen);
  if (x->Id)
    p = zx_enc_xmlns_if_not_seen(c, p, zx_ns_tab+zx_xmlns_ix_wsu, &pop_seen);

  p = zx_attr_so_enc(p, x->Id, " wsu:Id=\"", sizeof(" wsu:Id=\"")-1);

  p = zx_enc_unknown_attrs(p, x->gg.any_attr);
#else
  /* root node has no begin tag */
#endif
  
  {
      struct zx_wsse_Username_s* e;
      for (e = x->Username; e; e = (struct zx_wsse_Username_s*)e->gg.g.n)
	  p = zx_ENC_SO_wsse_Username(c, e, p);
  }

  p = zx_enc_so_unknown_elems_and_content(c, p, &x->gg);
  
#if 1 /* NORMALMODE */
  ZX_OUT_CLOSE_TAG(p, "</wsse:UsernameToken>");
  zx_pop_seen(pop_seen);
#else
  /* root node has no end tag either */
#endif
  ENC_LEN_DEBUG(x, "wsse:UsernameToken", p-enc_base);
  return p;
}

/* FUNC(zx_ENC_WO_wsse_UsernameToken) */

/* Render element into string. The XML attributes and elements are
 * processed in wire order by chasing wo pointers. This is what you want for
 * validating signatures on other people's XML documents. */

/* Called by: */
char* zx_ENC_WO_wsse_UsernameToken(struct zx_ctx* c, struct zx_wsse_UsernameToken_s* x, char* p )
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
  ZX_OUT_MEM(p, "UsernameToken", sizeof("UsernameToken")-1);
  qq = p;

  /* *** sort the namespaces */
  if (c->inc_ns)
    zx_add_inc_ns(c, &pop_seen);
  zx_add_xmlns_if_not_seen(c, x->gg.g.ns, &pop_seen);
  if (x->Id)
    zx_add_xmlns_if_not_seen(c, x->Id->g.ns, &pop_seen);

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
  ENC_LEN_DEBUG(x, "wsse:UsernameToken", p-enc_base);
  return p;
}

/* FUNC(zx_EASY_ENC_SO_wsse_UsernameToken) */

/* Called by: */
struct zx_str* zx_EASY_ENC_SO_wsse_UsernameToken(struct zx_ctx* c, struct zx_wsse_UsernameToken_s* x )
{
  int len;
  char* buf;
  c->ns_tab = ZX_ALLOC(c, sizeof(zx_ns_tab));
  memcpy(c->ns_tab, zx_ns_tab, sizeof(zx_ns_tab));
  len = zx_LEN_SO_wsse_UsernameToken(c, x );
  buf = ZX_ALLOC(c, len+1);
  return zx_easy_enc_common(c, zx_ENC_SO_wsse_UsernameToken(c, x, buf ), buf, len);
}

/* FUNC(zx_EASY_ENC_WO_wsse_UsernameToken) */

/* Called by: */
struct zx_str* zx_EASY_ENC_WO_wsse_UsernameToken(struct zx_ctx* c, struct zx_wsse_UsernameToken_s* x )
{
  int len;
  char* buf;
  c->ns_tab = ZX_ALLOC(c, sizeof(zx_ns_tab));
  memcpy(c->ns_tab, zx_ns_tab, sizeof(zx_ns_tab));
  len = zx_LEN_WO_wsse_UsernameToken(c, x );
  buf = ZX_ALLOC(c, len+1);
  return zx_easy_enc_common(c, zx_ENC_WO_wsse_UsernameToken(c, x, buf ), buf, len);
}




/* EOF -- c/zx-wsse-enc.c */
