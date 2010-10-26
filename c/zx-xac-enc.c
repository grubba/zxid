/* c/zx-xac-enc.c - WARNING: This file was automatically generated. DO NOT EDIT!
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
#include "c/zx-xac-data.h"
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

#define EL_NAME   xac_Action
#define EL_STRUCT zx_xac_Action_s
#define EL_NS     xac
#define EL_TAG    Action

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

/* FUNC(zx_LEN_SO_xac_Action) */

/* Compute length of an element (and its subelements). The XML attributes
 * and elements are processed in schema order. */

/* Called by: */
int zx_LEN_SO_xac_Action(struct zx_ctx* c, struct zx_xac_Action_s* x )
{
  struct zx_ns_s* pop_seen = 0;
  struct zx_elem_s* se MAYBE_UNUSED;
#if 1 /* NORMALMODE */
  /* *** in simple_elem case should output ns prefix from ns node. */
  int len = sizeof("<xac:Action")-1 + 1 + sizeof("</xac:Action>")-1;
  if (c->inc_ns_len)
    len += zx_len_inc_ns(c, &pop_seen);
  len += zx_len_xmlns_if_not_seen(c, zx_ns_tab+zx_xmlns_ix_xac, &pop_seen);


#else
  /* root node has no begin tag */
  int len = 0;
#endif
  
  {
      struct zx_xac_Attribute_s* e;
      for (e = x->Attribute; e; e = (struct zx_xac_Attribute_s*)e->gg.g.n)
	  len += zx_LEN_SO_xac_Attribute(c, e);
  }


  len += zx_len_so_common(c, &x->gg, &pop_seen);
  zx_pop_seen(pop_seen);
  ENC_LEN_DEBUG(x, "xac:Action", len);
  return len;
}

/* FUNC(zx_LEN_WO_xac_Action) */

/* Compute length of an element (and its subelements). The XML attributes
 * and elements are processed in wire order and no assumptions
 * are made about namespace prefixes. */

/* Called by: */
int zx_LEN_WO_xac_Action(struct zx_ctx* c, struct zx_xac_Action_s* x )
{
  struct zx_ns_s* pop_seen = 0;
  struct zx_elem_s* se MAYBE_UNUSED;
#if 1 /* NORMALMODE */
  int len = 1 + sizeof("Action")-1 + 1 + 2 + sizeof("Action")-1 + 1;
  
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
      struct zx_xac_Attribute_s* e;
      for (e = x->Attribute; e; e = (struct zx_xac_Attribute_s*)e->gg.g.n)
	  len += zx_LEN_WO_xac_Attribute(c, e);
  }


  len += zx_len_wo_common(c, &x->gg, &pop_seen); 
  zx_pop_seen(pop_seen);
  ENC_LEN_DEBUG(x, "xac:Action", len);
  return len;
}

/* FUNC(zx_ENC_SO_xac_Action) */

/* Render element into string. The XML attributes and elements are
 * processed in schema order. This is what you generally want for
 * rendering new data structure to a string. The wo pointers are not used. */

/* Called by: */
char* zx_ENC_SO_xac_Action(struct zx_ctx* c, struct zx_xac_Action_s* x, char* p )
{
  struct zx_elem_s* se MAYBE_UNUSED;
  struct zx_ns_s* pop_seen = 0;
  ENC_LEN_DEBUG_BASE;
#if 1 /* NORMALMODE */
  /* *** in simple_elem case should output ns prefix from ns node. */
  ZX_OUT_TAG(p, "<xac:Action");
  if (c->inc_ns)
    zx_add_inc_ns(c, &pop_seen);
  zx_add_xmlns_if_not_seen(c, zx_ns_tab+zx_xmlns_ix_xac, &pop_seen);

  zx_see_unknown_attrs_ns(c, x->gg.any_attr, &pop_seen);
  p = zx_enc_seen(p, pop_seen); 

  p = zx_enc_unknown_attrs(p, x->gg.any_attr);
#else
  /* root node has no begin tag */
#endif
  
  {
      struct zx_xac_Attribute_s* e;
      for (e = x->Attribute; e; e = (struct zx_xac_Attribute_s*)e->gg.g.n)
	  p = zx_ENC_SO_xac_Attribute(c, e, p);
  }

  p = zx_enc_so_unknown_elems_and_content(c, p, &x->gg);
  
#if 1 /* NORMALMODE */
  ZX_OUT_CLOSE_TAG(p, "</xac:Action>");
  zx_pop_seen(pop_seen);
#else
  /* root node has no end tag either */
#endif
  ENC_LEN_DEBUG(x, "xac:Action", p-enc_base);
  return p;
}

/* FUNC(zx_ENC_WO_xac_Action) */

/* Render element into string. The XML attributes and elements are
 * processed in wire order by chasing wo pointers. This is what you want for
 * validating signatures on other people's XML documents. */

/* Called by: */
char* zx_ENC_WO_xac_Action(struct zx_ctx* c, struct zx_xac_Action_s* x, char* p )
{
  struct zx_elem_s* kid;
  struct zx_ns_s* pop_seen = 0;
  char* q;
  char* qq;
  ENC_LEN_DEBUG_BASE;
#if 1 /* NORMALMODE */
  ZX_OUT_CH(p, '<');
  q = p;
  if (x->gg.g.ns && x->gg.g.ns->prefix_len) {
    ZX_OUT_MEM(p, x->gg.g.ns->prefix, x->gg.g.ns->prefix_len);
    ZX_OUT_CH(p, ':');
  }
  ZX_OUT_MEM(p, "Action", sizeof("Action")-1);
  qq = p;

  if (c->inc_ns)
    zx_add_inc_ns(c, &pop_seen);
  zx_add_xmlns_if_not_seen(c, x->gg.g.ns, &pop_seen);

  zx_see_unknown_attrs_ns(c, x->gg.any_attr, &pop_seen);
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
  ENC_LEN_DEBUG(x, "xac:Action", p-enc_base);
  return p;
}

/* FUNC(zx_EASY_ENC_SO_xac_Action) */

/* Called by: */
struct zx_str* zx_EASY_ENC_SO_xac_Action(struct zx_ctx* c, struct zx_xac_Action_s* x )
{
  int len;
  char* buf;
  c->ns_tab = ZX_ALLOC(c, sizeof(zx_ns_tab));
  memcpy(c->ns_tab, zx_ns_tab, sizeof(zx_ns_tab));
  len = zx_LEN_SO_xac_Action(c, x );
  buf = ZX_ALLOC(c, len+1);
  return zx_easy_enc_common(c, zx_ENC_SO_xac_Action(c, x, buf ), buf, len);
}

/* FUNC(zx_EASY_ENC_WO_xac_Action) */

/* Called by: */
struct zx_str* zx_EASY_ENC_WO_xac_Action(struct zx_ctx* c, struct zx_xac_Action_s* x )
{
  int len;
  char* buf;
  c->ns_tab = ZX_ALLOC(c, sizeof(zx_ns_tab));
  memcpy(c->ns_tab, zx_ns_tab, sizeof(zx_ns_tab));
  len = zx_LEN_WO_xac_Action(c, x );
  buf = ZX_ALLOC(c, len+1);
  return zx_easy_enc_common(c, zx_ENC_WO_xac_Action(c, x, buf ), buf, len);
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

#define EL_NAME   xac_Attribute
#define EL_STRUCT zx_xac_Attribute_s
#define EL_NS     xac
#define EL_TAG    Attribute

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

/* FUNC(zx_LEN_SO_xac_Attribute) */

/* Compute length of an element (and its subelements). The XML attributes
 * and elements are processed in schema order. */

/* Called by: */
int zx_LEN_SO_xac_Attribute(struct zx_ctx* c, struct zx_xac_Attribute_s* x )
{
  struct zx_ns_s* pop_seen = 0;
  struct zx_elem_s* se MAYBE_UNUSED;
#if 1 /* NORMALMODE */
  /* *** in simple_elem case should output ns prefix from ns node. */
  int len = sizeof("<xac:Attribute")-1 + 1 + sizeof("</xac:Attribute>")-1;
  if (c->inc_ns_len)
    len += zx_len_inc_ns(c, &pop_seen);
  len += zx_len_xmlns_if_not_seen(c, zx_ns_tab+zx_xmlns_ix_xac, &pop_seen);

  len += zx_attr_so_len(c, x->AttributeId, sizeof("AttributeId")-1, &pop_seen);
  len += zx_attr_so_len(c, x->DataType, sizeof("DataType")-1, &pop_seen);
  len += zx_attr_so_len(c, x->Issuer, sizeof("Issuer")-1, &pop_seen);

#else
  /* root node has no begin tag */
  int len = 0;
#endif
  
  for (se = x->AttributeValue; se; se = (struct zx_elem_s*)se->g.n)
    len += zx_LEN_SO_simple_elem(c,se, sizeof("xac:AttributeValue")-1, zx_ns_tab+zx_xmlns_ix_xac);


  len += zx_len_so_common(c, &x->gg, &pop_seen);
  zx_pop_seen(pop_seen);
  ENC_LEN_DEBUG(x, "xac:Attribute", len);
  return len;
}

/* FUNC(zx_LEN_WO_xac_Attribute) */

/* Compute length of an element (and its subelements). The XML attributes
 * and elements are processed in wire order and no assumptions
 * are made about namespace prefixes. */

/* Called by: */
int zx_LEN_WO_xac_Attribute(struct zx_ctx* c, struct zx_xac_Attribute_s* x )
{
  struct zx_ns_s* pop_seen = 0;
  struct zx_elem_s* se MAYBE_UNUSED;
#if 1 /* NORMALMODE */
  int len = 1 + sizeof("Attribute")-1 + 1 + 2 + sizeof("Attribute")-1 + 1;
  
  if (x->gg.g.ns && x->gg.g.ns->prefix_len)
    len += (x->gg.g.ns->prefix_len + 1) * 2;
  if (c->inc_ns_len)
    len += zx_len_inc_ns(c, &pop_seen);
  len += zx_len_xmlns_if_not_seen(c, x->gg.g.ns, &pop_seen);

  len += zx_attr_wo_len(c, x->AttributeId, sizeof("AttributeId")-1, &pop_seen);
  len += zx_attr_wo_len(c, x->DataType, sizeof("DataType")-1, &pop_seen);
  len += zx_attr_wo_len(c, x->Issuer, sizeof("Issuer")-1, &pop_seen);

#else
  /* root node has no begin tag */
  int len = 0;
#endif
  
  for (se = x->AttributeValue; se; se = (struct zx_elem_s*)se->g.n)
    len += zx_LEN_WO_simple_elem(c, se, sizeof("AttributeValue")-1);


  len += zx_len_wo_common(c, &x->gg, &pop_seen); 
  zx_pop_seen(pop_seen);
  ENC_LEN_DEBUG(x, "xac:Attribute", len);
  return len;
}

/* FUNC(zx_ENC_SO_xac_Attribute) */

/* Render element into string. The XML attributes and elements are
 * processed in schema order. This is what you generally want for
 * rendering new data structure to a string. The wo pointers are not used. */

/* Called by: */
char* zx_ENC_SO_xac_Attribute(struct zx_ctx* c, struct zx_xac_Attribute_s* x, char* p )
{
  struct zx_elem_s* se MAYBE_UNUSED;
  struct zx_ns_s* pop_seen = 0;
  ENC_LEN_DEBUG_BASE;
#if 1 /* NORMALMODE */
  /* *** in simple_elem case should output ns prefix from ns node. */
  ZX_OUT_TAG(p, "<xac:Attribute");
  if (c->inc_ns)
    zx_add_inc_ns(c, &pop_seen);
  zx_add_xmlns_if_not_seen(c, zx_ns_tab+zx_xmlns_ix_xac, &pop_seen);

  zx_see_unknown_attrs_ns(c, x->gg.any_attr, &pop_seen);
  p = zx_enc_seen(p, pop_seen); 
  p = zx_attr_so_enc(p, x->AttributeId, " AttributeId=\"", sizeof(" AttributeId=\"")-1);
  p = zx_attr_so_enc(p, x->DataType, " DataType=\"", sizeof(" DataType=\"")-1);
  p = zx_attr_so_enc(p, x->Issuer, " Issuer=\"", sizeof(" Issuer=\"")-1);

  p = zx_enc_unknown_attrs(p, x->gg.any_attr);
#else
  /* root node has no begin tag */
#endif
  
  for (se = x->AttributeValue; se; se = (struct zx_elem_s*)se->g.n)
    p = zx_ENC_SO_simple_elem(c, se, p, "xac:AttributeValue", sizeof("xac:AttributeValue")-1, zx_ns_tab+zx_xmlns_ix_xac);

  p = zx_enc_so_unknown_elems_and_content(c, p, &x->gg);
  
#if 1 /* NORMALMODE */
  ZX_OUT_CLOSE_TAG(p, "</xac:Attribute>");
  zx_pop_seen(pop_seen);
#else
  /* root node has no end tag either */
#endif
  ENC_LEN_DEBUG(x, "xac:Attribute", p-enc_base);
  return p;
}

/* FUNC(zx_ENC_WO_xac_Attribute) */

/* Render element into string. The XML attributes and elements are
 * processed in wire order by chasing wo pointers. This is what you want for
 * validating signatures on other people's XML documents. */

/* Called by: */
char* zx_ENC_WO_xac_Attribute(struct zx_ctx* c, struct zx_xac_Attribute_s* x, char* p )
{
  struct zx_elem_s* kid;
  struct zx_ns_s* pop_seen = 0;
  char* q;
  char* qq;
  ENC_LEN_DEBUG_BASE;
#if 1 /* NORMALMODE */
  ZX_OUT_CH(p, '<');
  q = p;
  if (x->gg.g.ns && x->gg.g.ns->prefix_len) {
    ZX_OUT_MEM(p, x->gg.g.ns->prefix, x->gg.g.ns->prefix_len);
    ZX_OUT_CH(p, ':');
  }
  ZX_OUT_MEM(p, "Attribute", sizeof("Attribute")-1);
  qq = p;

  if (c->inc_ns)
    zx_add_inc_ns(c, &pop_seen);
  zx_add_xmlns_if_not_seen(c, x->gg.g.ns, &pop_seen);

  zx_see_unknown_attrs_ns(c, x->gg.any_attr, &pop_seen);
  p = zx_enc_seen(p, pop_seen); 
  p = zx_attr_wo_enc(p, x->AttributeId, "AttributeId=\"", sizeof("AttributeId=\"")-1);
  p = zx_attr_wo_enc(p, x->DataType, "DataType=\"", sizeof("DataType=\"")-1);
  p = zx_attr_wo_enc(p, x->Issuer, "Issuer=\"", sizeof("Issuer=\"")-1);

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
  ENC_LEN_DEBUG(x, "xac:Attribute", p-enc_base);
  return p;
}

/* FUNC(zx_EASY_ENC_SO_xac_Attribute) */

/* Called by: */
struct zx_str* zx_EASY_ENC_SO_xac_Attribute(struct zx_ctx* c, struct zx_xac_Attribute_s* x )
{
  int len;
  char* buf;
  c->ns_tab = ZX_ALLOC(c, sizeof(zx_ns_tab));
  memcpy(c->ns_tab, zx_ns_tab, sizeof(zx_ns_tab));
  len = zx_LEN_SO_xac_Attribute(c, x );
  buf = ZX_ALLOC(c, len+1);
  return zx_easy_enc_common(c, zx_ENC_SO_xac_Attribute(c, x, buf ), buf, len);
}

/* FUNC(zx_EASY_ENC_WO_xac_Attribute) */

/* Called by: */
struct zx_str* zx_EASY_ENC_WO_xac_Attribute(struct zx_ctx* c, struct zx_xac_Attribute_s* x )
{
  int len;
  char* buf;
  c->ns_tab = ZX_ALLOC(c, sizeof(zx_ns_tab));
  memcpy(c->ns_tab, zx_ns_tab, sizeof(zx_ns_tab));
  len = zx_LEN_WO_xac_Attribute(c, x );
  buf = ZX_ALLOC(c, len+1);
  return zx_easy_enc_common(c, zx_ENC_WO_xac_Attribute(c, x, buf ), buf, len);
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

#define EL_NAME   xac_Environment
#define EL_STRUCT zx_xac_Environment_s
#define EL_NS     xac
#define EL_TAG    Environment

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

/* FUNC(zx_LEN_SO_xac_Environment) */

/* Compute length of an element (and its subelements). The XML attributes
 * and elements are processed in schema order. */

/* Called by: */
int zx_LEN_SO_xac_Environment(struct zx_ctx* c, struct zx_xac_Environment_s* x )
{
  struct zx_ns_s* pop_seen = 0;
  struct zx_elem_s* se MAYBE_UNUSED;
#if 1 /* NORMALMODE */
  /* *** in simple_elem case should output ns prefix from ns node. */
  int len = sizeof("<xac:Environment")-1 + 1 + sizeof("</xac:Environment>")-1;
  if (c->inc_ns_len)
    len += zx_len_inc_ns(c, &pop_seen);
  len += zx_len_xmlns_if_not_seen(c, zx_ns_tab+zx_xmlns_ix_xac, &pop_seen);


#else
  /* root node has no begin tag */
  int len = 0;
#endif
  
  {
      struct zx_xac_Attribute_s* e;
      for (e = x->Attribute; e; e = (struct zx_xac_Attribute_s*)e->gg.g.n)
	  len += zx_LEN_SO_xac_Attribute(c, e);
  }


  len += zx_len_so_common(c, &x->gg, &pop_seen);
  zx_pop_seen(pop_seen);
  ENC_LEN_DEBUG(x, "xac:Environment", len);
  return len;
}

/* FUNC(zx_LEN_WO_xac_Environment) */

/* Compute length of an element (and its subelements). The XML attributes
 * and elements are processed in wire order and no assumptions
 * are made about namespace prefixes. */

/* Called by: */
int zx_LEN_WO_xac_Environment(struct zx_ctx* c, struct zx_xac_Environment_s* x )
{
  struct zx_ns_s* pop_seen = 0;
  struct zx_elem_s* se MAYBE_UNUSED;
#if 1 /* NORMALMODE */
  int len = 1 + sizeof("Environment")-1 + 1 + 2 + sizeof("Environment")-1 + 1;
  
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
      struct zx_xac_Attribute_s* e;
      for (e = x->Attribute; e; e = (struct zx_xac_Attribute_s*)e->gg.g.n)
	  len += zx_LEN_WO_xac_Attribute(c, e);
  }


  len += zx_len_wo_common(c, &x->gg, &pop_seen); 
  zx_pop_seen(pop_seen);
  ENC_LEN_DEBUG(x, "xac:Environment", len);
  return len;
}

/* FUNC(zx_ENC_SO_xac_Environment) */

/* Render element into string. The XML attributes and elements are
 * processed in schema order. This is what you generally want for
 * rendering new data structure to a string. The wo pointers are not used. */

/* Called by: */
char* zx_ENC_SO_xac_Environment(struct zx_ctx* c, struct zx_xac_Environment_s* x, char* p )
{
  struct zx_elem_s* se MAYBE_UNUSED;
  struct zx_ns_s* pop_seen = 0;
  ENC_LEN_DEBUG_BASE;
#if 1 /* NORMALMODE */
  /* *** in simple_elem case should output ns prefix from ns node. */
  ZX_OUT_TAG(p, "<xac:Environment");
  if (c->inc_ns)
    zx_add_inc_ns(c, &pop_seen);
  zx_add_xmlns_if_not_seen(c, zx_ns_tab+zx_xmlns_ix_xac, &pop_seen);

  zx_see_unknown_attrs_ns(c, x->gg.any_attr, &pop_seen);
  p = zx_enc_seen(p, pop_seen); 

  p = zx_enc_unknown_attrs(p, x->gg.any_attr);
#else
  /* root node has no begin tag */
#endif
  
  {
      struct zx_xac_Attribute_s* e;
      for (e = x->Attribute; e; e = (struct zx_xac_Attribute_s*)e->gg.g.n)
	  p = zx_ENC_SO_xac_Attribute(c, e, p);
  }

  p = zx_enc_so_unknown_elems_and_content(c, p, &x->gg);
  
#if 1 /* NORMALMODE */
  ZX_OUT_CLOSE_TAG(p, "</xac:Environment>");
  zx_pop_seen(pop_seen);
#else
  /* root node has no end tag either */
#endif
  ENC_LEN_DEBUG(x, "xac:Environment", p-enc_base);
  return p;
}

/* FUNC(zx_ENC_WO_xac_Environment) */

/* Render element into string. The XML attributes and elements are
 * processed in wire order by chasing wo pointers. This is what you want for
 * validating signatures on other people's XML documents. */

/* Called by: */
char* zx_ENC_WO_xac_Environment(struct zx_ctx* c, struct zx_xac_Environment_s* x, char* p )
{
  struct zx_elem_s* kid;
  struct zx_ns_s* pop_seen = 0;
  char* q;
  char* qq;
  ENC_LEN_DEBUG_BASE;
#if 1 /* NORMALMODE */
  ZX_OUT_CH(p, '<');
  q = p;
  if (x->gg.g.ns && x->gg.g.ns->prefix_len) {
    ZX_OUT_MEM(p, x->gg.g.ns->prefix, x->gg.g.ns->prefix_len);
    ZX_OUT_CH(p, ':');
  }
  ZX_OUT_MEM(p, "Environment", sizeof("Environment")-1);
  qq = p;

  if (c->inc_ns)
    zx_add_inc_ns(c, &pop_seen);
  zx_add_xmlns_if_not_seen(c, x->gg.g.ns, &pop_seen);

  zx_see_unknown_attrs_ns(c, x->gg.any_attr, &pop_seen);
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
  ENC_LEN_DEBUG(x, "xac:Environment", p-enc_base);
  return p;
}

/* FUNC(zx_EASY_ENC_SO_xac_Environment) */

/* Called by: */
struct zx_str* zx_EASY_ENC_SO_xac_Environment(struct zx_ctx* c, struct zx_xac_Environment_s* x )
{
  int len;
  char* buf;
  c->ns_tab = ZX_ALLOC(c, sizeof(zx_ns_tab));
  memcpy(c->ns_tab, zx_ns_tab, sizeof(zx_ns_tab));
  len = zx_LEN_SO_xac_Environment(c, x );
  buf = ZX_ALLOC(c, len+1);
  return zx_easy_enc_common(c, zx_ENC_SO_xac_Environment(c, x, buf ), buf, len);
}

/* FUNC(zx_EASY_ENC_WO_xac_Environment) */

/* Called by: */
struct zx_str* zx_EASY_ENC_WO_xac_Environment(struct zx_ctx* c, struct zx_xac_Environment_s* x )
{
  int len;
  char* buf;
  c->ns_tab = ZX_ALLOC(c, sizeof(zx_ns_tab));
  memcpy(c->ns_tab, zx_ns_tab, sizeof(zx_ns_tab));
  len = zx_LEN_WO_xac_Environment(c, x );
  buf = ZX_ALLOC(c, len+1);
  return zx_easy_enc_common(c, zx_ENC_WO_xac_Environment(c, x, buf ), buf, len);
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

#define EL_NAME   xac_MissingAttributeDetail
#define EL_STRUCT zx_xac_MissingAttributeDetail_s
#define EL_NS     xac
#define EL_TAG    MissingAttributeDetail

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

/* FUNC(zx_LEN_SO_xac_MissingAttributeDetail) */

/* Compute length of an element (and its subelements). The XML attributes
 * and elements are processed in schema order. */

/* Called by: */
int zx_LEN_SO_xac_MissingAttributeDetail(struct zx_ctx* c, struct zx_xac_MissingAttributeDetail_s* x )
{
  struct zx_ns_s* pop_seen = 0;
  struct zx_elem_s* se MAYBE_UNUSED;
#if 1 /* NORMALMODE */
  /* *** in simple_elem case should output ns prefix from ns node. */
  int len = sizeof("<xac:MissingAttributeDetail")-1 + 1 + sizeof("</xac:MissingAttributeDetail>")-1;
  if (c->inc_ns_len)
    len += zx_len_inc_ns(c, &pop_seen);
  len += zx_len_xmlns_if_not_seen(c, zx_ns_tab+zx_xmlns_ix_xac, &pop_seen);

  len += zx_attr_so_len(c, x->AttributeId, sizeof("AttributeId")-1, &pop_seen);
  len += zx_attr_so_len(c, x->DataType, sizeof("DataType")-1, &pop_seen);
  len += zx_attr_so_len(c, x->Issuer, sizeof("Issuer")-1, &pop_seen);

#else
  /* root node has no begin tag */
  int len = 0;
#endif
  
  for (se = x->AttributeValue; se; se = (struct zx_elem_s*)se->g.n)
    len += zx_LEN_SO_simple_elem(c,se, sizeof("xac:AttributeValue")-1, zx_ns_tab+zx_xmlns_ix_xac);


  len += zx_len_so_common(c, &x->gg, &pop_seen);
  zx_pop_seen(pop_seen);
  ENC_LEN_DEBUG(x, "xac:MissingAttributeDetail", len);
  return len;
}

/* FUNC(zx_LEN_WO_xac_MissingAttributeDetail) */

/* Compute length of an element (and its subelements). The XML attributes
 * and elements are processed in wire order and no assumptions
 * are made about namespace prefixes. */

/* Called by: */
int zx_LEN_WO_xac_MissingAttributeDetail(struct zx_ctx* c, struct zx_xac_MissingAttributeDetail_s* x )
{
  struct zx_ns_s* pop_seen = 0;
  struct zx_elem_s* se MAYBE_UNUSED;
#if 1 /* NORMALMODE */
  int len = 1 + sizeof("MissingAttributeDetail")-1 + 1 + 2 + sizeof("MissingAttributeDetail")-1 + 1;
  
  if (x->gg.g.ns && x->gg.g.ns->prefix_len)
    len += (x->gg.g.ns->prefix_len + 1) * 2;
  if (c->inc_ns_len)
    len += zx_len_inc_ns(c, &pop_seen);
  len += zx_len_xmlns_if_not_seen(c, x->gg.g.ns, &pop_seen);

  len += zx_attr_wo_len(c, x->AttributeId, sizeof("AttributeId")-1, &pop_seen);
  len += zx_attr_wo_len(c, x->DataType, sizeof("DataType")-1, &pop_seen);
  len += zx_attr_wo_len(c, x->Issuer, sizeof("Issuer")-1, &pop_seen);

#else
  /* root node has no begin tag */
  int len = 0;
#endif
  
  for (se = x->AttributeValue; se; se = (struct zx_elem_s*)se->g.n)
    len += zx_LEN_WO_simple_elem(c, se, sizeof("AttributeValue")-1);


  len += zx_len_wo_common(c, &x->gg, &pop_seen); 
  zx_pop_seen(pop_seen);
  ENC_LEN_DEBUG(x, "xac:MissingAttributeDetail", len);
  return len;
}

/* FUNC(zx_ENC_SO_xac_MissingAttributeDetail) */

/* Render element into string. The XML attributes and elements are
 * processed in schema order. This is what you generally want for
 * rendering new data structure to a string. The wo pointers are not used. */

/* Called by: */
char* zx_ENC_SO_xac_MissingAttributeDetail(struct zx_ctx* c, struct zx_xac_MissingAttributeDetail_s* x, char* p )
{
  struct zx_elem_s* se MAYBE_UNUSED;
  struct zx_ns_s* pop_seen = 0;
  ENC_LEN_DEBUG_BASE;
#if 1 /* NORMALMODE */
  /* *** in simple_elem case should output ns prefix from ns node. */
  ZX_OUT_TAG(p, "<xac:MissingAttributeDetail");
  if (c->inc_ns)
    zx_add_inc_ns(c, &pop_seen);
  zx_add_xmlns_if_not_seen(c, zx_ns_tab+zx_xmlns_ix_xac, &pop_seen);

  zx_see_unknown_attrs_ns(c, x->gg.any_attr, &pop_seen);
  p = zx_enc_seen(p, pop_seen); 
  p = zx_attr_so_enc(p, x->AttributeId, " AttributeId=\"", sizeof(" AttributeId=\"")-1);
  p = zx_attr_so_enc(p, x->DataType, " DataType=\"", sizeof(" DataType=\"")-1);
  p = zx_attr_so_enc(p, x->Issuer, " Issuer=\"", sizeof(" Issuer=\"")-1);

  p = zx_enc_unknown_attrs(p, x->gg.any_attr);
#else
  /* root node has no begin tag */
#endif
  
  for (se = x->AttributeValue; se; se = (struct zx_elem_s*)se->g.n)
    p = zx_ENC_SO_simple_elem(c, se, p, "xac:AttributeValue", sizeof("xac:AttributeValue")-1, zx_ns_tab+zx_xmlns_ix_xac);

  p = zx_enc_so_unknown_elems_and_content(c, p, &x->gg);
  
#if 1 /* NORMALMODE */
  ZX_OUT_CLOSE_TAG(p, "</xac:MissingAttributeDetail>");
  zx_pop_seen(pop_seen);
#else
  /* root node has no end tag either */
#endif
  ENC_LEN_DEBUG(x, "xac:MissingAttributeDetail", p-enc_base);
  return p;
}

/* FUNC(zx_ENC_WO_xac_MissingAttributeDetail) */

/* Render element into string. The XML attributes and elements are
 * processed in wire order by chasing wo pointers. This is what you want for
 * validating signatures on other people's XML documents. */

/* Called by: */
char* zx_ENC_WO_xac_MissingAttributeDetail(struct zx_ctx* c, struct zx_xac_MissingAttributeDetail_s* x, char* p )
{
  struct zx_elem_s* kid;
  struct zx_ns_s* pop_seen = 0;
  char* q;
  char* qq;
  ENC_LEN_DEBUG_BASE;
#if 1 /* NORMALMODE */
  ZX_OUT_CH(p, '<');
  q = p;
  if (x->gg.g.ns && x->gg.g.ns->prefix_len) {
    ZX_OUT_MEM(p, x->gg.g.ns->prefix, x->gg.g.ns->prefix_len);
    ZX_OUT_CH(p, ':');
  }
  ZX_OUT_MEM(p, "MissingAttributeDetail", sizeof("MissingAttributeDetail")-1);
  qq = p;

  if (c->inc_ns)
    zx_add_inc_ns(c, &pop_seen);
  zx_add_xmlns_if_not_seen(c, x->gg.g.ns, &pop_seen);

  zx_see_unknown_attrs_ns(c, x->gg.any_attr, &pop_seen);
  p = zx_enc_seen(p, pop_seen); 
  p = zx_attr_wo_enc(p, x->AttributeId, "AttributeId=\"", sizeof("AttributeId=\"")-1);
  p = zx_attr_wo_enc(p, x->DataType, "DataType=\"", sizeof("DataType=\"")-1);
  p = zx_attr_wo_enc(p, x->Issuer, "Issuer=\"", sizeof("Issuer=\"")-1);

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
  ENC_LEN_DEBUG(x, "xac:MissingAttributeDetail", p-enc_base);
  return p;
}

/* FUNC(zx_EASY_ENC_SO_xac_MissingAttributeDetail) */

/* Called by: */
struct zx_str* zx_EASY_ENC_SO_xac_MissingAttributeDetail(struct zx_ctx* c, struct zx_xac_MissingAttributeDetail_s* x )
{
  int len;
  char* buf;
  c->ns_tab = ZX_ALLOC(c, sizeof(zx_ns_tab));
  memcpy(c->ns_tab, zx_ns_tab, sizeof(zx_ns_tab));
  len = zx_LEN_SO_xac_MissingAttributeDetail(c, x );
  buf = ZX_ALLOC(c, len+1);
  return zx_easy_enc_common(c, zx_ENC_SO_xac_MissingAttributeDetail(c, x, buf ), buf, len);
}

/* FUNC(zx_EASY_ENC_WO_xac_MissingAttributeDetail) */

/* Called by: */
struct zx_str* zx_EASY_ENC_WO_xac_MissingAttributeDetail(struct zx_ctx* c, struct zx_xac_MissingAttributeDetail_s* x )
{
  int len;
  char* buf;
  c->ns_tab = ZX_ALLOC(c, sizeof(zx_ns_tab));
  memcpy(c->ns_tab, zx_ns_tab, sizeof(zx_ns_tab));
  len = zx_LEN_WO_xac_MissingAttributeDetail(c, x );
  buf = ZX_ALLOC(c, len+1);
  return zx_easy_enc_common(c, zx_ENC_WO_xac_MissingAttributeDetail(c, x, buf ), buf, len);
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

#define EL_NAME   xac_Request
#define EL_STRUCT zx_xac_Request_s
#define EL_NS     xac
#define EL_TAG    Request

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

/* FUNC(zx_LEN_SO_xac_Request) */

/* Compute length of an element (and its subelements). The XML attributes
 * and elements are processed in schema order. */

/* Called by: */
int zx_LEN_SO_xac_Request(struct zx_ctx* c, struct zx_xac_Request_s* x )
{
  struct zx_ns_s* pop_seen = 0;
  struct zx_elem_s* se MAYBE_UNUSED;
#if 1 /* NORMALMODE */
  /* *** in simple_elem case should output ns prefix from ns node. */
  int len = sizeof("<xac:Request")-1 + 1 + sizeof("</xac:Request>")-1;
  if (c->inc_ns_len)
    len += zx_len_inc_ns(c, &pop_seen);
  len += zx_len_xmlns_if_not_seen(c, zx_ns_tab+zx_xmlns_ix_xac, &pop_seen);


#else
  /* root node has no begin tag */
  int len = 0;
#endif
  
  {
      struct zx_xac_Subject_s* e;
      for (e = x->Subject; e; e = (struct zx_xac_Subject_s*)e->gg.g.n)
	  len += zx_LEN_SO_xac_Subject(c, e);
  }
  {
      struct zx_xac_Resource_s* e;
      for (e = x->Resource; e; e = (struct zx_xac_Resource_s*)e->gg.g.n)
	  len += zx_LEN_SO_xac_Resource(c, e);
  }
  {
      struct zx_xac_Action_s* e;
      for (e = x->Action; e; e = (struct zx_xac_Action_s*)e->gg.g.n)
	  len += zx_LEN_SO_xac_Action(c, e);
  }
  {
      struct zx_xac_Environment_s* e;
      for (e = x->Environment; e; e = (struct zx_xac_Environment_s*)e->gg.g.n)
	  len += zx_LEN_SO_xac_Environment(c, e);
  }


  len += zx_len_so_common(c, &x->gg, &pop_seen);
  zx_pop_seen(pop_seen);
  ENC_LEN_DEBUG(x, "xac:Request", len);
  return len;
}

/* FUNC(zx_LEN_WO_xac_Request) */

/* Compute length of an element (and its subelements). The XML attributes
 * and elements are processed in wire order and no assumptions
 * are made about namespace prefixes. */

/* Called by: */
int zx_LEN_WO_xac_Request(struct zx_ctx* c, struct zx_xac_Request_s* x )
{
  struct zx_ns_s* pop_seen = 0;
  struct zx_elem_s* se MAYBE_UNUSED;
#if 1 /* NORMALMODE */
  int len = 1 + sizeof("Request")-1 + 1 + 2 + sizeof("Request")-1 + 1;
  
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
      struct zx_xac_Subject_s* e;
      for (e = x->Subject; e; e = (struct zx_xac_Subject_s*)e->gg.g.n)
	  len += zx_LEN_WO_xac_Subject(c, e);
  }
  {
      struct zx_xac_Resource_s* e;
      for (e = x->Resource; e; e = (struct zx_xac_Resource_s*)e->gg.g.n)
	  len += zx_LEN_WO_xac_Resource(c, e);
  }
  {
      struct zx_xac_Action_s* e;
      for (e = x->Action; e; e = (struct zx_xac_Action_s*)e->gg.g.n)
	  len += zx_LEN_WO_xac_Action(c, e);
  }
  {
      struct zx_xac_Environment_s* e;
      for (e = x->Environment; e; e = (struct zx_xac_Environment_s*)e->gg.g.n)
	  len += zx_LEN_WO_xac_Environment(c, e);
  }


  len += zx_len_wo_common(c, &x->gg, &pop_seen); 
  zx_pop_seen(pop_seen);
  ENC_LEN_DEBUG(x, "xac:Request", len);
  return len;
}

/* FUNC(zx_ENC_SO_xac_Request) */

/* Render element into string. The XML attributes and elements are
 * processed in schema order. This is what you generally want for
 * rendering new data structure to a string. The wo pointers are not used. */

/* Called by: */
char* zx_ENC_SO_xac_Request(struct zx_ctx* c, struct zx_xac_Request_s* x, char* p )
{
  struct zx_elem_s* se MAYBE_UNUSED;
  struct zx_ns_s* pop_seen = 0;
  ENC_LEN_DEBUG_BASE;
#if 1 /* NORMALMODE */
  /* *** in simple_elem case should output ns prefix from ns node. */
  ZX_OUT_TAG(p, "<xac:Request");
  if (c->inc_ns)
    zx_add_inc_ns(c, &pop_seen);
  zx_add_xmlns_if_not_seen(c, zx_ns_tab+zx_xmlns_ix_xac, &pop_seen);

  zx_see_unknown_attrs_ns(c, x->gg.any_attr, &pop_seen);
  p = zx_enc_seen(p, pop_seen); 

  p = zx_enc_unknown_attrs(p, x->gg.any_attr);
#else
  /* root node has no begin tag */
#endif
  
  {
      struct zx_xac_Subject_s* e;
      for (e = x->Subject; e; e = (struct zx_xac_Subject_s*)e->gg.g.n)
	  p = zx_ENC_SO_xac_Subject(c, e, p);
  }
  {
      struct zx_xac_Resource_s* e;
      for (e = x->Resource; e; e = (struct zx_xac_Resource_s*)e->gg.g.n)
	  p = zx_ENC_SO_xac_Resource(c, e, p);
  }
  {
      struct zx_xac_Action_s* e;
      for (e = x->Action; e; e = (struct zx_xac_Action_s*)e->gg.g.n)
	  p = zx_ENC_SO_xac_Action(c, e, p);
  }
  {
      struct zx_xac_Environment_s* e;
      for (e = x->Environment; e; e = (struct zx_xac_Environment_s*)e->gg.g.n)
	  p = zx_ENC_SO_xac_Environment(c, e, p);
  }

  p = zx_enc_so_unknown_elems_and_content(c, p, &x->gg);
  
#if 1 /* NORMALMODE */
  ZX_OUT_CLOSE_TAG(p, "</xac:Request>");
  zx_pop_seen(pop_seen);
#else
  /* root node has no end tag either */
#endif
  ENC_LEN_DEBUG(x, "xac:Request", p-enc_base);
  return p;
}

/* FUNC(zx_ENC_WO_xac_Request) */

/* Render element into string. The XML attributes and elements are
 * processed in wire order by chasing wo pointers. This is what you want for
 * validating signatures on other people's XML documents. */

/* Called by: */
char* zx_ENC_WO_xac_Request(struct zx_ctx* c, struct zx_xac_Request_s* x, char* p )
{
  struct zx_elem_s* kid;
  struct zx_ns_s* pop_seen = 0;
  char* q;
  char* qq;
  ENC_LEN_DEBUG_BASE;
#if 1 /* NORMALMODE */
  ZX_OUT_CH(p, '<');
  q = p;
  if (x->gg.g.ns && x->gg.g.ns->prefix_len) {
    ZX_OUT_MEM(p, x->gg.g.ns->prefix, x->gg.g.ns->prefix_len);
    ZX_OUT_CH(p, ':');
  }
  ZX_OUT_MEM(p, "Request", sizeof("Request")-1);
  qq = p;

  if (c->inc_ns)
    zx_add_inc_ns(c, &pop_seen);
  zx_add_xmlns_if_not_seen(c, x->gg.g.ns, &pop_seen);

  zx_see_unknown_attrs_ns(c, x->gg.any_attr, &pop_seen);
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
  ENC_LEN_DEBUG(x, "xac:Request", p-enc_base);
  return p;
}

/* FUNC(zx_EASY_ENC_SO_xac_Request) */

/* Called by: */
struct zx_str* zx_EASY_ENC_SO_xac_Request(struct zx_ctx* c, struct zx_xac_Request_s* x )
{
  int len;
  char* buf;
  c->ns_tab = ZX_ALLOC(c, sizeof(zx_ns_tab));
  memcpy(c->ns_tab, zx_ns_tab, sizeof(zx_ns_tab));
  len = zx_LEN_SO_xac_Request(c, x );
  buf = ZX_ALLOC(c, len+1);
  return zx_easy_enc_common(c, zx_ENC_SO_xac_Request(c, x, buf ), buf, len);
}

/* FUNC(zx_EASY_ENC_WO_xac_Request) */

/* Called by: */
struct zx_str* zx_EASY_ENC_WO_xac_Request(struct zx_ctx* c, struct zx_xac_Request_s* x )
{
  int len;
  char* buf;
  c->ns_tab = ZX_ALLOC(c, sizeof(zx_ns_tab));
  memcpy(c->ns_tab, zx_ns_tab, sizeof(zx_ns_tab));
  len = zx_LEN_WO_xac_Request(c, x );
  buf = ZX_ALLOC(c, len+1);
  return zx_easy_enc_common(c, zx_ENC_WO_xac_Request(c, x, buf ), buf, len);
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

#define EL_NAME   xac_Resource
#define EL_STRUCT zx_xac_Resource_s
#define EL_NS     xac
#define EL_TAG    Resource

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

/* FUNC(zx_LEN_SO_xac_Resource) */

/* Compute length of an element (and its subelements). The XML attributes
 * and elements are processed in schema order. */

/* Called by: */
int zx_LEN_SO_xac_Resource(struct zx_ctx* c, struct zx_xac_Resource_s* x )
{
  struct zx_ns_s* pop_seen = 0;
  struct zx_elem_s* se MAYBE_UNUSED;
#if 1 /* NORMALMODE */
  /* *** in simple_elem case should output ns prefix from ns node. */
  int len = sizeof("<xac:Resource")-1 + 1 + sizeof("</xac:Resource>")-1;
  if (c->inc_ns_len)
    len += zx_len_inc_ns(c, &pop_seen);
  len += zx_len_xmlns_if_not_seen(c, zx_ns_tab+zx_xmlns_ix_xac, &pop_seen);


#else
  /* root node has no begin tag */
  int len = 0;
#endif
  
  {
      struct zx_xac_ResourceContent_s* e;
      for (e = x->ResourceContent; e; e = (struct zx_xac_ResourceContent_s*)e->gg.g.n)
	  len += zx_LEN_SO_xac_ResourceContent(c, e);
  }
  {
      struct zx_xac_Attribute_s* e;
      for (e = x->Attribute; e; e = (struct zx_xac_Attribute_s*)e->gg.g.n)
	  len += zx_LEN_SO_xac_Attribute(c, e);
  }


  len += zx_len_so_common(c, &x->gg, &pop_seen);
  zx_pop_seen(pop_seen);
  ENC_LEN_DEBUG(x, "xac:Resource", len);
  return len;
}

/* FUNC(zx_LEN_WO_xac_Resource) */

/* Compute length of an element (and its subelements). The XML attributes
 * and elements are processed in wire order and no assumptions
 * are made about namespace prefixes. */

/* Called by: */
int zx_LEN_WO_xac_Resource(struct zx_ctx* c, struct zx_xac_Resource_s* x )
{
  struct zx_ns_s* pop_seen = 0;
  struct zx_elem_s* se MAYBE_UNUSED;
#if 1 /* NORMALMODE */
  int len = 1 + sizeof("Resource")-1 + 1 + 2 + sizeof("Resource")-1 + 1;
  
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
      struct zx_xac_ResourceContent_s* e;
      for (e = x->ResourceContent; e; e = (struct zx_xac_ResourceContent_s*)e->gg.g.n)
	  len += zx_LEN_WO_xac_ResourceContent(c, e);
  }
  {
      struct zx_xac_Attribute_s* e;
      for (e = x->Attribute; e; e = (struct zx_xac_Attribute_s*)e->gg.g.n)
	  len += zx_LEN_WO_xac_Attribute(c, e);
  }


  len += zx_len_wo_common(c, &x->gg, &pop_seen); 
  zx_pop_seen(pop_seen);
  ENC_LEN_DEBUG(x, "xac:Resource", len);
  return len;
}

/* FUNC(zx_ENC_SO_xac_Resource) */

/* Render element into string. The XML attributes and elements are
 * processed in schema order. This is what you generally want for
 * rendering new data structure to a string. The wo pointers are not used. */

/* Called by: */
char* zx_ENC_SO_xac_Resource(struct zx_ctx* c, struct zx_xac_Resource_s* x, char* p )
{
  struct zx_elem_s* se MAYBE_UNUSED;
  struct zx_ns_s* pop_seen = 0;
  ENC_LEN_DEBUG_BASE;
#if 1 /* NORMALMODE */
  /* *** in simple_elem case should output ns prefix from ns node. */
  ZX_OUT_TAG(p, "<xac:Resource");
  if (c->inc_ns)
    zx_add_inc_ns(c, &pop_seen);
  zx_add_xmlns_if_not_seen(c, zx_ns_tab+zx_xmlns_ix_xac, &pop_seen);

  zx_see_unknown_attrs_ns(c, x->gg.any_attr, &pop_seen);
  p = zx_enc_seen(p, pop_seen); 

  p = zx_enc_unknown_attrs(p, x->gg.any_attr);
#else
  /* root node has no begin tag */
#endif
  
  {
      struct zx_xac_ResourceContent_s* e;
      for (e = x->ResourceContent; e; e = (struct zx_xac_ResourceContent_s*)e->gg.g.n)
	  p = zx_ENC_SO_xac_ResourceContent(c, e, p);
  }
  {
      struct zx_xac_Attribute_s* e;
      for (e = x->Attribute; e; e = (struct zx_xac_Attribute_s*)e->gg.g.n)
	  p = zx_ENC_SO_xac_Attribute(c, e, p);
  }

  p = zx_enc_so_unknown_elems_and_content(c, p, &x->gg);
  
#if 1 /* NORMALMODE */
  ZX_OUT_CLOSE_TAG(p, "</xac:Resource>");
  zx_pop_seen(pop_seen);
#else
  /* root node has no end tag either */
#endif
  ENC_LEN_DEBUG(x, "xac:Resource", p-enc_base);
  return p;
}

/* FUNC(zx_ENC_WO_xac_Resource) */

/* Render element into string. The XML attributes and elements are
 * processed in wire order by chasing wo pointers. This is what you want for
 * validating signatures on other people's XML documents. */

/* Called by: */
char* zx_ENC_WO_xac_Resource(struct zx_ctx* c, struct zx_xac_Resource_s* x, char* p )
{
  struct zx_elem_s* kid;
  struct zx_ns_s* pop_seen = 0;
  char* q;
  char* qq;
  ENC_LEN_DEBUG_BASE;
#if 1 /* NORMALMODE */
  ZX_OUT_CH(p, '<');
  q = p;
  if (x->gg.g.ns && x->gg.g.ns->prefix_len) {
    ZX_OUT_MEM(p, x->gg.g.ns->prefix, x->gg.g.ns->prefix_len);
    ZX_OUT_CH(p, ':');
  }
  ZX_OUT_MEM(p, "Resource", sizeof("Resource")-1);
  qq = p;

  if (c->inc_ns)
    zx_add_inc_ns(c, &pop_seen);
  zx_add_xmlns_if_not_seen(c, x->gg.g.ns, &pop_seen);

  zx_see_unknown_attrs_ns(c, x->gg.any_attr, &pop_seen);
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
  ENC_LEN_DEBUG(x, "xac:Resource", p-enc_base);
  return p;
}

/* FUNC(zx_EASY_ENC_SO_xac_Resource) */

/* Called by: */
struct zx_str* zx_EASY_ENC_SO_xac_Resource(struct zx_ctx* c, struct zx_xac_Resource_s* x )
{
  int len;
  char* buf;
  c->ns_tab = ZX_ALLOC(c, sizeof(zx_ns_tab));
  memcpy(c->ns_tab, zx_ns_tab, sizeof(zx_ns_tab));
  len = zx_LEN_SO_xac_Resource(c, x );
  buf = ZX_ALLOC(c, len+1);
  return zx_easy_enc_common(c, zx_ENC_SO_xac_Resource(c, x, buf ), buf, len);
}

/* FUNC(zx_EASY_ENC_WO_xac_Resource) */

/* Called by: */
struct zx_str* zx_EASY_ENC_WO_xac_Resource(struct zx_ctx* c, struct zx_xac_Resource_s* x )
{
  int len;
  char* buf;
  c->ns_tab = ZX_ALLOC(c, sizeof(zx_ns_tab));
  memcpy(c->ns_tab, zx_ns_tab, sizeof(zx_ns_tab));
  len = zx_LEN_WO_xac_Resource(c, x );
  buf = ZX_ALLOC(c, len+1);
  return zx_easy_enc_common(c, zx_ENC_WO_xac_Resource(c, x, buf ), buf, len);
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

#define EL_NAME   xac_ResourceContent
#define EL_STRUCT zx_xac_ResourceContent_s
#define EL_NS     xac
#define EL_TAG    ResourceContent

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

/* FUNC(zx_LEN_SO_xac_ResourceContent) */

/* Compute length of an element (and its subelements). The XML attributes
 * and elements are processed in schema order. */

/* Called by: */
int zx_LEN_SO_xac_ResourceContent(struct zx_ctx* c, struct zx_xac_ResourceContent_s* x )
{
  struct zx_ns_s* pop_seen = 0;
  struct zx_elem_s* se MAYBE_UNUSED;
#if 1 /* NORMALMODE */
  /* *** in simple_elem case should output ns prefix from ns node. */
  int len = sizeof("<xac:ResourceContent")-1 + 1 + sizeof("</xac:ResourceContent>")-1;
  if (c->inc_ns_len)
    len += zx_len_inc_ns(c, &pop_seen);
  len += zx_len_xmlns_if_not_seen(c, zx_ns_tab+zx_xmlns_ix_xac, &pop_seen);


#else
  /* root node has no begin tag */
  int len = 0;
#endif
  


  len += zx_len_so_common(c, &x->gg, &pop_seen);
  zx_pop_seen(pop_seen);
  ENC_LEN_DEBUG(x, "xac:ResourceContent", len);
  return len;
}

/* FUNC(zx_LEN_WO_xac_ResourceContent) */

/* Compute length of an element (and its subelements). The XML attributes
 * and elements are processed in wire order and no assumptions
 * are made about namespace prefixes. */

/* Called by: */
int zx_LEN_WO_xac_ResourceContent(struct zx_ctx* c, struct zx_xac_ResourceContent_s* x )
{
  struct zx_ns_s* pop_seen = 0;
  struct zx_elem_s* se MAYBE_UNUSED;
#if 1 /* NORMALMODE */
  int len = 1 + sizeof("ResourceContent")-1 + 1 + 2 + sizeof("ResourceContent")-1 + 1;
  
  if (x->gg.g.ns && x->gg.g.ns->prefix_len)
    len += (x->gg.g.ns->prefix_len + 1) * 2;
  if (c->inc_ns_len)
    len += zx_len_inc_ns(c, &pop_seen);
  len += zx_len_xmlns_if_not_seen(c, x->gg.g.ns, &pop_seen);


#else
  /* root node has no begin tag */
  int len = 0;
#endif
  


  len += zx_len_wo_common(c, &x->gg, &pop_seen); 
  zx_pop_seen(pop_seen);
  ENC_LEN_DEBUG(x, "xac:ResourceContent", len);
  return len;
}

/* FUNC(zx_ENC_SO_xac_ResourceContent) */

/* Render element into string. The XML attributes and elements are
 * processed in schema order. This is what you generally want for
 * rendering new data structure to a string. The wo pointers are not used. */

/* Called by: */
char* zx_ENC_SO_xac_ResourceContent(struct zx_ctx* c, struct zx_xac_ResourceContent_s* x, char* p )
{
  struct zx_elem_s* se MAYBE_UNUSED;
  struct zx_ns_s* pop_seen = 0;
  ENC_LEN_DEBUG_BASE;
#if 1 /* NORMALMODE */
  /* *** in simple_elem case should output ns prefix from ns node. */
  ZX_OUT_TAG(p, "<xac:ResourceContent");
  if (c->inc_ns)
    zx_add_inc_ns(c, &pop_seen);
  zx_add_xmlns_if_not_seen(c, zx_ns_tab+zx_xmlns_ix_xac, &pop_seen);

  zx_see_unknown_attrs_ns(c, x->gg.any_attr, &pop_seen);
  p = zx_enc_seen(p, pop_seen); 

  p = zx_enc_unknown_attrs(p, x->gg.any_attr);
#else
  /* root node has no begin tag */
#endif
  

  p = zx_enc_so_unknown_elems_and_content(c, p, &x->gg);
  
#if 1 /* NORMALMODE */
  ZX_OUT_CLOSE_TAG(p, "</xac:ResourceContent>");
  zx_pop_seen(pop_seen);
#else
  /* root node has no end tag either */
#endif
  ENC_LEN_DEBUG(x, "xac:ResourceContent", p-enc_base);
  return p;
}

/* FUNC(zx_ENC_WO_xac_ResourceContent) */

/* Render element into string. The XML attributes and elements are
 * processed in wire order by chasing wo pointers. This is what you want for
 * validating signatures on other people's XML documents. */

/* Called by: */
char* zx_ENC_WO_xac_ResourceContent(struct zx_ctx* c, struct zx_xac_ResourceContent_s* x, char* p )
{
  struct zx_elem_s* kid;
  struct zx_ns_s* pop_seen = 0;
  char* q;
  char* qq;
  ENC_LEN_DEBUG_BASE;
#if 1 /* NORMALMODE */
  ZX_OUT_CH(p, '<');
  q = p;
  if (x->gg.g.ns && x->gg.g.ns->prefix_len) {
    ZX_OUT_MEM(p, x->gg.g.ns->prefix, x->gg.g.ns->prefix_len);
    ZX_OUT_CH(p, ':');
  }
  ZX_OUT_MEM(p, "ResourceContent", sizeof("ResourceContent")-1);
  qq = p;

  if (c->inc_ns)
    zx_add_inc_ns(c, &pop_seen);
  zx_add_xmlns_if_not_seen(c, x->gg.g.ns, &pop_seen);

  zx_see_unknown_attrs_ns(c, x->gg.any_attr, &pop_seen);
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
  ENC_LEN_DEBUG(x, "xac:ResourceContent", p-enc_base);
  return p;
}

/* FUNC(zx_EASY_ENC_SO_xac_ResourceContent) */

/* Called by: */
struct zx_str* zx_EASY_ENC_SO_xac_ResourceContent(struct zx_ctx* c, struct zx_xac_ResourceContent_s* x )
{
  int len;
  char* buf;
  c->ns_tab = ZX_ALLOC(c, sizeof(zx_ns_tab));
  memcpy(c->ns_tab, zx_ns_tab, sizeof(zx_ns_tab));
  len = zx_LEN_SO_xac_ResourceContent(c, x );
  buf = ZX_ALLOC(c, len+1);
  return zx_easy_enc_common(c, zx_ENC_SO_xac_ResourceContent(c, x, buf ), buf, len);
}

/* FUNC(zx_EASY_ENC_WO_xac_ResourceContent) */

/* Called by: */
struct zx_str* zx_EASY_ENC_WO_xac_ResourceContent(struct zx_ctx* c, struct zx_xac_ResourceContent_s* x )
{
  int len;
  char* buf;
  c->ns_tab = ZX_ALLOC(c, sizeof(zx_ns_tab));
  memcpy(c->ns_tab, zx_ns_tab, sizeof(zx_ns_tab));
  len = zx_LEN_WO_xac_ResourceContent(c, x );
  buf = ZX_ALLOC(c, len+1);
  return zx_easy_enc_common(c, zx_ENC_WO_xac_ResourceContent(c, x, buf ), buf, len);
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

#define EL_NAME   xac_Response
#define EL_STRUCT zx_xac_Response_s
#define EL_NS     xac
#define EL_TAG    Response

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

/* FUNC(zx_LEN_SO_xac_Response) */

/* Compute length of an element (and its subelements). The XML attributes
 * and elements are processed in schema order. */

/* Called by: */
int zx_LEN_SO_xac_Response(struct zx_ctx* c, struct zx_xac_Response_s* x )
{
  struct zx_ns_s* pop_seen = 0;
  struct zx_elem_s* se MAYBE_UNUSED;
#if 1 /* NORMALMODE */
  /* *** in simple_elem case should output ns prefix from ns node. */
  int len = sizeof("<xac:Response")-1 + 1 + sizeof("</xac:Response>")-1;
  if (c->inc_ns_len)
    len += zx_len_inc_ns(c, &pop_seen);
  len += zx_len_xmlns_if_not_seen(c, zx_ns_tab+zx_xmlns_ix_xac, &pop_seen);


#else
  /* root node has no begin tag */
  int len = 0;
#endif
  
  {
      struct zx_xac_Result_s* e;
      for (e = x->Result; e; e = (struct zx_xac_Result_s*)e->gg.g.n)
	  len += zx_LEN_SO_xac_Result(c, e);
  }


  len += zx_len_so_common(c, &x->gg, &pop_seen);
  zx_pop_seen(pop_seen);
  ENC_LEN_DEBUG(x, "xac:Response", len);
  return len;
}

/* FUNC(zx_LEN_WO_xac_Response) */

/* Compute length of an element (and its subelements). The XML attributes
 * and elements are processed in wire order and no assumptions
 * are made about namespace prefixes. */

/* Called by: */
int zx_LEN_WO_xac_Response(struct zx_ctx* c, struct zx_xac_Response_s* x )
{
  struct zx_ns_s* pop_seen = 0;
  struct zx_elem_s* se MAYBE_UNUSED;
#if 1 /* NORMALMODE */
  int len = 1 + sizeof("Response")-1 + 1 + 2 + sizeof("Response")-1 + 1;
  
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
      struct zx_xac_Result_s* e;
      for (e = x->Result; e; e = (struct zx_xac_Result_s*)e->gg.g.n)
	  len += zx_LEN_WO_xac_Result(c, e);
  }


  len += zx_len_wo_common(c, &x->gg, &pop_seen); 
  zx_pop_seen(pop_seen);
  ENC_LEN_DEBUG(x, "xac:Response", len);
  return len;
}

/* FUNC(zx_ENC_SO_xac_Response) */

/* Render element into string. The XML attributes and elements are
 * processed in schema order. This is what you generally want for
 * rendering new data structure to a string. The wo pointers are not used. */

/* Called by: */
char* zx_ENC_SO_xac_Response(struct zx_ctx* c, struct zx_xac_Response_s* x, char* p )
{
  struct zx_elem_s* se MAYBE_UNUSED;
  struct zx_ns_s* pop_seen = 0;
  ENC_LEN_DEBUG_BASE;
#if 1 /* NORMALMODE */
  /* *** in simple_elem case should output ns prefix from ns node. */
  ZX_OUT_TAG(p, "<xac:Response");
  if (c->inc_ns)
    zx_add_inc_ns(c, &pop_seen);
  zx_add_xmlns_if_not_seen(c, zx_ns_tab+zx_xmlns_ix_xac, &pop_seen);

  zx_see_unknown_attrs_ns(c, x->gg.any_attr, &pop_seen);
  p = zx_enc_seen(p, pop_seen); 

  p = zx_enc_unknown_attrs(p, x->gg.any_attr);
#else
  /* root node has no begin tag */
#endif
  
  {
      struct zx_xac_Result_s* e;
      for (e = x->Result; e; e = (struct zx_xac_Result_s*)e->gg.g.n)
	  p = zx_ENC_SO_xac_Result(c, e, p);
  }

  p = zx_enc_so_unknown_elems_and_content(c, p, &x->gg);
  
#if 1 /* NORMALMODE */
  ZX_OUT_CLOSE_TAG(p, "</xac:Response>");
  zx_pop_seen(pop_seen);
#else
  /* root node has no end tag either */
#endif
  ENC_LEN_DEBUG(x, "xac:Response", p-enc_base);
  return p;
}

/* FUNC(zx_ENC_WO_xac_Response) */

/* Render element into string. The XML attributes and elements are
 * processed in wire order by chasing wo pointers. This is what you want for
 * validating signatures on other people's XML documents. */

/* Called by: */
char* zx_ENC_WO_xac_Response(struct zx_ctx* c, struct zx_xac_Response_s* x, char* p )
{
  struct zx_elem_s* kid;
  struct zx_ns_s* pop_seen = 0;
  char* q;
  char* qq;
  ENC_LEN_DEBUG_BASE;
#if 1 /* NORMALMODE */
  ZX_OUT_CH(p, '<');
  q = p;
  if (x->gg.g.ns && x->gg.g.ns->prefix_len) {
    ZX_OUT_MEM(p, x->gg.g.ns->prefix, x->gg.g.ns->prefix_len);
    ZX_OUT_CH(p, ':');
  }
  ZX_OUT_MEM(p, "Response", sizeof("Response")-1);
  qq = p;

  if (c->inc_ns)
    zx_add_inc_ns(c, &pop_seen);
  zx_add_xmlns_if_not_seen(c, x->gg.g.ns, &pop_seen);

  zx_see_unknown_attrs_ns(c, x->gg.any_attr, &pop_seen);
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
  ENC_LEN_DEBUG(x, "xac:Response", p-enc_base);
  return p;
}

/* FUNC(zx_EASY_ENC_SO_xac_Response) */

/* Called by: */
struct zx_str* zx_EASY_ENC_SO_xac_Response(struct zx_ctx* c, struct zx_xac_Response_s* x )
{
  int len;
  char* buf;
  c->ns_tab = ZX_ALLOC(c, sizeof(zx_ns_tab));
  memcpy(c->ns_tab, zx_ns_tab, sizeof(zx_ns_tab));
  len = zx_LEN_SO_xac_Response(c, x );
  buf = ZX_ALLOC(c, len+1);
  return zx_easy_enc_common(c, zx_ENC_SO_xac_Response(c, x, buf ), buf, len);
}

/* FUNC(zx_EASY_ENC_WO_xac_Response) */

/* Called by: */
struct zx_str* zx_EASY_ENC_WO_xac_Response(struct zx_ctx* c, struct zx_xac_Response_s* x )
{
  int len;
  char* buf;
  c->ns_tab = ZX_ALLOC(c, sizeof(zx_ns_tab));
  memcpy(c->ns_tab, zx_ns_tab, sizeof(zx_ns_tab));
  len = zx_LEN_WO_xac_Response(c, x );
  buf = ZX_ALLOC(c, len+1);
  return zx_easy_enc_common(c, zx_ENC_WO_xac_Response(c, x, buf ), buf, len);
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

#define EL_NAME   xac_Result
#define EL_STRUCT zx_xac_Result_s
#define EL_NS     xac
#define EL_TAG    Result

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

/* FUNC(zx_LEN_SO_xac_Result) */

/* Compute length of an element (and its subelements). The XML attributes
 * and elements are processed in schema order. */

/* Called by: */
int zx_LEN_SO_xac_Result(struct zx_ctx* c, struct zx_xac_Result_s* x )
{
  struct zx_ns_s* pop_seen = 0;
  struct zx_elem_s* se MAYBE_UNUSED;
#if 1 /* NORMALMODE */
  /* *** in simple_elem case should output ns prefix from ns node. */
  int len = sizeof("<xac:Result")-1 + 1 + sizeof("</xac:Result>")-1;
  if (c->inc_ns_len)
    len += zx_len_inc_ns(c, &pop_seen);
  len += zx_len_xmlns_if_not_seen(c, zx_ns_tab+zx_xmlns_ix_xac, &pop_seen);

  len += zx_attr_so_len(c, x->ResourceId, sizeof("ResourceId")-1, &pop_seen);

#else
  /* root node has no begin tag */
  int len = 0;
#endif
  
  for (se = x->Decision; se; se = (struct zx_elem_s*)se->g.n)
    len += zx_LEN_SO_simple_elem(c,se, sizeof("xac:Decision")-1, zx_ns_tab+zx_xmlns_ix_xac);
  {
      struct zx_xac_Status_s* e;
      for (e = x->Status; e; e = (struct zx_xac_Status_s*)e->gg.g.n)
	  len += zx_LEN_SO_xac_Status(c, e);
  }
  {
      struct zx_xa_Obligations_s* e;
      for (e = x->Obligations; e; e = (struct zx_xa_Obligations_s*)e->gg.g.n)
	  len += zx_LEN_SO_xa_Obligations(c, e);
  }


  len += zx_len_so_common(c, &x->gg, &pop_seen);
  zx_pop_seen(pop_seen);
  ENC_LEN_DEBUG(x, "xac:Result", len);
  return len;
}

/* FUNC(zx_LEN_WO_xac_Result) */

/* Compute length of an element (and its subelements). The XML attributes
 * and elements are processed in wire order and no assumptions
 * are made about namespace prefixes. */

/* Called by: */
int zx_LEN_WO_xac_Result(struct zx_ctx* c, struct zx_xac_Result_s* x )
{
  struct zx_ns_s* pop_seen = 0;
  struct zx_elem_s* se MAYBE_UNUSED;
#if 1 /* NORMALMODE */
  int len = 1 + sizeof("Result")-1 + 1 + 2 + sizeof("Result")-1 + 1;
  
  if (x->gg.g.ns && x->gg.g.ns->prefix_len)
    len += (x->gg.g.ns->prefix_len + 1) * 2;
  if (c->inc_ns_len)
    len += zx_len_inc_ns(c, &pop_seen);
  len += zx_len_xmlns_if_not_seen(c, x->gg.g.ns, &pop_seen);

  len += zx_attr_wo_len(c, x->ResourceId, sizeof("ResourceId")-1, &pop_seen);

#else
  /* root node has no begin tag */
  int len = 0;
#endif
  
  for (se = x->Decision; se; se = (struct zx_elem_s*)se->g.n)
    len += zx_LEN_WO_simple_elem(c, se, sizeof("Decision")-1);
  {
      struct zx_xac_Status_s* e;
      for (e = x->Status; e; e = (struct zx_xac_Status_s*)e->gg.g.n)
	  len += zx_LEN_WO_xac_Status(c, e);
  }
  {
      struct zx_xa_Obligations_s* e;
      for (e = x->Obligations; e; e = (struct zx_xa_Obligations_s*)e->gg.g.n)
	  len += zx_LEN_WO_xa_Obligations(c, e);
  }


  len += zx_len_wo_common(c, &x->gg, &pop_seen); 
  zx_pop_seen(pop_seen);
  ENC_LEN_DEBUG(x, "xac:Result", len);
  return len;
}

/* FUNC(zx_ENC_SO_xac_Result) */

/* Render element into string. The XML attributes and elements are
 * processed in schema order. This is what you generally want for
 * rendering new data structure to a string. The wo pointers are not used. */

/* Called by: */
char* zx_ENC_SO_xac_Result(struct zx_ctx* c, struct zx_xac_Result_s* x, char* p )
{
  struct zx_elem_s* se MAYBE_UNUSED;
  struct zx_ns_s* pop_seen = 0;
  ENC_LEN_DEBUG_BASE;
#if 1 /* NORMALMODE */
  /* *** in simple_elem case should output ns prefix from ns node. */
  ZX_OUT_TAG(p, "<xac:Result");
  if (c->inc_ns)
    zx_add_inc_ns(c, &pop_seen);
  zx_add_xmlns_if_not_seen(c, zx_ns_tab+zx_xmlns_ix_xac, &pop_seen);

  zx_see_unknown_attrs_ns(c, x->gg.any_attr, &pop_seen);
  p = zx_enc_seen(p, pop_seen); 
  p = zx_attr_so_enc(p, x->ResourceId, " ResourceId=\"", sizeof(" ResourceId=\"")-1);

  p = zx_enc_unknown_attrs(p, x->gg.any_attr);
#else
  /* root node has no begin tag */
#endif
  
  for (se = x->Decision; se; se = (struct zx_elem_s*)se->g.n)
    p = zx_ENC_SO_simple_elem(c, se, p, "xac:Decision", sizeof("xac:Decision")-1, zx_ns_tab+zx_xmlns_ix_xac);
  {
      struct zx_xac_Status_s* e;
      for (e = x->Status; e; e = (struct zx_xac_Status_s*)e->gg.g.n)
	  p = zx_ENC_SO_xac_Status(c, e, p);
  }
  {
      struct zx_xa_Obligations_s* e;
      for (e = x->Obligations; e; e = (struct zx_xa_Obligations_s*)e->gg.g.n)
	  p = zx_ENC_SO_xa_Obligations(c, e, p);
  }

  p = zx_enc_so_unknown_elems_and_content(c, p, &x->gg);
  
#if 1 /* NORMALMODE */
  ZX_OUT_CLOSE_TAG(p, "</xac:Result>");
  zx_pop_seen(pop_seen);
#else
  /* root node has no end tag either */
#endif
  ENC_LEN_DEBUG(x, "xac:Result", p-enc_base);
  return p;
}

/* FUNC(zx_ENC_WO_xac_Result) */

/* Render element into string. The XML attributes and elements are
 * processed in wire order by chasing wo pointers. This is what you want for
 * validating signatures on other people's XML documents. */

/* Called by: */
char* zx_ENC_WO_xac_Result(struct zx_ctx* c, struct zx_xac_Result_s* x, char* p )
{
  struct zx_elem_s* kid;
  struct zx_ns_s* pop_seen = 0;
  char* q;
  char* qq;
  ENC_LEN_DEBUG_BASE;
#if 1 /* NORMALMODE */
  ZX_OUT_CH(p, '<');
  q = p;
  if (x->gg.g.ns && x->gg.g.ns->prefix_len) {
    ZX_OUT_MEM(p, x->gg.g.ns->prefix, x->gg.g.ns->prefix_len);
    ZX_OUT_CH(p, ':');
  }
  ZX_OUT_MEM(p, "Result", sizeof("Result")-1);
  qq = p;

  if (c->inc_ns)
    zx_add_inc_ns(c, &pop_seen);
  zx_add_xmlns_if_not_seen(c, x->gg.g.ns, &pop_seen);

  zx_see_unknown_attrs_ns(c, x->gg.any_attr, &pop_seen);
  p = zx_enc_seen(p, pop_seen); 
  p = zx_attr_wo_enc(p, x->ResourceId, "ResourceId=\"", sizeof("ResourceId=\"")-1);

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
  ENC_LEN_DEBUG(x, "xac:Result", p-enc_base);
  return p;
}

/* FUNC(zx_EASY_ENC_SO_xac_Result) */

/* Called by: */
struct zx_str* zx_EASY_ENC_SO_xac_Result(struct zx_ctx* c, struct zx_xac_Result_s* x )
{
  int len;
  char* buf;
  c->ns_tab = ZX_ALLOC(c, sizeof(zx_ns_tab));
  memcpy(c->ns_tab, zx_ns_tab, sizeof(zx_ns_tab));
  len = zx_LEN_SO_xac_Result(c, x );
  buf = ZX_ALLOC(c, len+1);
  return zx_easy_enc_common(c, zx_ENC_SO_xac_Result(c, x, buf ), buf, len);
}

/* FUNC(zx_EASY_ENC_WO_xac_Result) */

/* Called by: */
struct zx_str* zx_EASY_ENC_WO_xac_Result(struct zx_ctx* c, struct zx_xac_Result_s* x )
{
  int len;
  char* buf;
  c->ns_tab = ZX_ALLOC(c, sizeof(zx_ns_tab));
  memcpy(c->ns_tab, zx_ns_tab, sizeof(zx_ns_tab));
  len = zx_LEN_WO_xac_Result(c, x );
  buf = ZX_ALLOC(c, len+1);
  return zx_easy_enc_common(c, zx_ENC_WO_xac_Result(c, x, buf ), buf, len);
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

#define EL_NAME   xac_Status
#define EL_STRUCT zx_xac_Status_s
#define EL_NS     xac
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

/* FUNC(zx_LEN_SO_xac_Status) */

/* Compute length of an element (and its subelements). The XML attributes
 * and elements are processed in schema order. */

/* Called by: */
int zx_LEN_SO_xac_Status(struct zx_ctx* c, struct zx_xac_Status_s* x )
{
  struct zx_ns_s* pop_seen = 0;
  struct zx_elem_s* se MAYBE_UNUSED;
#if 1 /* NORMALMODE */
  /* *** in simple_elem case should output ns prefix from ns node. */
  int len = sizeof("<xac:Status")-1 + 1 + sizeof("</xac:Status>")-1;
  if (c->inc_ns_len)
    len += zx_len_inc_ns(c, &pop_seen);
  len += zx_len_xmlns_if_not_seen(c, zx_ns_tab+zx_xmlns_ix_xac, &pop_seen);


#else
  /* root node has no begin tag */
  int len = 0;
#endif
  
  {
      struct zx_xac_StatusCode_s* e;
      for (e = x->StatusCode; e; e = (struct zx_xac_StatusCode_s*)e->gg.g.n)
	  len += zx_LEN_SO_xac_StatusCode(c, e);
  }
  for (se = x->StatusMessage; se; se = (struct zx_elem_s*)se->g.n)
    len += zx_LEN_SO_simple_elem(c,se, sizeof("xac:StatusMessage")-1, zx_ns_tab+zx_xmlns_ix_xac);
  {
      struct zx_xac_StatusDetail_s* e;
      for (e = x->StatusDetail; e; e = (struct zx_xac_StatusDetail_s*)e->gg.g.n)
	  len += zx_LEN_SO_xac_StatusDetail(c, e);
  }


  len += zx_len_so_common(c, &x->gg, &pop_seen);
  zx_pop_seen(pop_seen);
  ENC_LEN_DEBUG(x, "xac:Status", len);
  return len;
}

/* FUNC(zx_LEN_WO_xac_Status) */

/* Compute length of an element (and its subelements). The XML attributes
 * and elements are processed in wire order and no assumptions
 * are made about namespace prefixes. */

/* Called by: */
int zx_LEN_WO_xac_Status(struct zx_ctx* c, struct zx_xac_Status_s* x )
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
  
  {
      struct zx_xac_StatusCode_s* e;
      for (e = x->StatusCode; e; e = (struct zx_xac_StatusCode_s*)e->gg.g.n)
	  len += zx_LEN_WO_xac_StatusCode(c, e);
  }
  for (se = x->StatusMessage; se; se = (struct zx_elem_s*)se->g.n)
    len += zx_LEN_WO_simple_elem(c, se, sizeof("StatusMessage")-1);
  {
      struct zx_xac_StatusDetail_s* e;
      for (e = x->StatusDetail; e; e = (struct zx_xac_StatusDetail_s*)e->gg.g.n)
	  len += zx_LEN_WO_xac_StatusDetail(c, e);
  }


  len += zx_len_wo_common(c, &x->gg, &pop_seen); 
  zx_pop_seen(pop_seen);
  ENC_LEN_DEBUG(x, "xac:Status", len);
  return len;
}

/* FUNC(zx_ENC_SO_xac_Status) */

/* Render element into string. The XML attributes and elements are
 * processed in schema order. This is what you generally want for
 * rendering new data structure to a string. The wo pointers are not used. */

/* Called by: */
char* zx_ENC_SO_xac_Status(struct zx_ctx* c, struct zx_xac_Status_s* x, char* p )
{
  struct zx_elem_s* se MAYBE_UNUSED;
  struct zx_ns_s* pop_seen = 0;
  ENC_LEN_DEBUG_BASE;
#if 1 /* NORMALMODE */
  /* *** in simple_elem case should output ns prefix from ns node. */
  ZX_OUT_TAG(p, "<xac:Status");
  if (c->inc_ns)
    zx_add_inc_ns(c, &pop_seen);
  zx_add_xmlns_if_not_seen(c, zx_ns_tab+zx_xmlns_ix_xac, &pop_seen);

  zx_see_unknown_attrs_ns(c, x->gg.any_attr, &pop_seen);
  p = zx_enc_seen(p, pop_seen); 

  p = zx_enc_unknown_attrs(p, x->gg.any_attr);
#else
  /* root node has no begin tag */
#endif
  
  {
      struct zx_xac_StatusCode_s* e;
      for (e = x->StatusCode; e; e = (struct zx_xac_StatusCode_s*)e->gg.g.n)
	  p = zx_ENC_SO_xac_StatusCode(c, e, p);
  }
  for (se = x->StatusMessage; se; se = (struct zx_elem_s*)se->g.n)
    p = zx_ENC_SO_simple_elem(c, se, p, "xac:StatusMessage", sizeof("xac:StatusMessage")-1, zx_ns_tab+zx_xmlns_ix_xac);
  {
      struct zx_xac_StatusDetail_s* e;
      for (e = x->StatusDetail; e; e = (struct zx_xac_StatusDetail_s*)e->gg.g.n)
	  p = zx_ENC_SO_xac_StatusDetail(c, e, p);
  }

  p = zx_enc_so_unknown_elems_and_content(c, p, &x->gg);
  
#if 1 /* NORMALMODE */
  ZX_OUT_CLOSE_TAG(p, "</xac:Status>");
  zx_pop_seen(pop_seen);
#else
  /* root node has no end tag either */
#endif
  ENC_LEN_DEBUG(x, "xac:Status", p-enc_base);
  return p;
}

/* FUNC(zx_ENC_WO_xac_Status) */

/* Render element into string. The XML attributes and elements are
 * processed in wire order by chasing wo pointers. This is what you want for
 * validating signatures on other people's XML documents. */

/* Called by: */
char* zx_ENC_WO_xac_Status(struct zx_ctx* c, struct zx_xac_Status_s* x, char* p )
{
  struct zx_elem_s* kid;
  struct zx_ns_s* pop_seen = 0;
  char* q;
  char* qq;
  ENC_LEN_DEBUG_BASE;
#if 1 /* NORMALMODE */
  ZX_OUT_CH(p, '<');
  q = p;
  if (x->gg.g.ns && x->gg.g.ns->prefix_len) {
    ZX_OUT_MEM(p, x->gg.g.ns->prefix, x->gg.g.ns->prefix_len);
    ZX_OUT_CH(p, ':');
  }
  ZX_OUT_MEM(p, "Status", sizeof("Status")-1);
  qq = p;

  if (c->inc_ns)
    zx_add_inc_ns(c, &pop_seen);
  zx_add_xmlns_if_not_seen(c, x->gg.g.ns, &pop_seen);

  zx_see_unknown_attrs_ns(c, x->gg.any_attr, &pop_seen);
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
  ENC_LEN_DEBUG(x, "xac:Status", p-enc_base);
  return p;
}

/* FUNC(zx_EASY_ENC_SO_xac_Status) */

/* Called by: */
struct zx_str* zx_EASY_ENC_SO_xac_Status(struct zx_ctx* c, struct zx_xac_Status_s* x )
{
  int len;
  char* buf;
  c->ns_tab = ZX_ALLOC(c, sizeof(zx_ns_tab));
  memcpy(c->ns_tab, zx_ns_tab, sizeof(zx_ns_tab));
  len = zx_LEN_SO_xac_Status(c, x );
  buf = ZX_ALLOC(c, len+1);
  return zx_easy_enc_common(c, zx_ENC_SO_xac_Status(c, x, buf ), buf, len);
}

/* FUNC(zx_EASY_ENC_WO_xac_Status) */

/* Called by: */
struct zx_str* zx_EASY_ENC_WO_xac_Status(struct zx_ctx* c, struct zx_xac_Status_s* x )
{
  int len;
  char* buf;
  c->ns_tab = ZX_ALLOC(c, sizeof(zx_ns_tab));
  memcpy(c->ns_tab, zx_ns_tab, sizeof(zx_ns_tab));
  len = zx_LEN_WO_xac_Status(c, x );
  buf = ZX_ALLOC(c, len+1);
  return zx_easy_enc_common(c, zx_ENC_WO_xac_Status(c, x, buf ), buf, len);
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

#define EL_NAME   xac_StatusCode
#define EL_STRUCT zx_xac_StatusCode_s
#define EL_NS     xac
#define EL_TAG    StatusCode

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

/* FUNC(zx_LEN_SO_xac_StatusCode) */

/* Compute length of an element (and its subelements). The XML attributes
 * and elements are processed in schema order. */

/* Called by: */
int zx_LEN_SO_xac_StatusCode(struct zx_ctx* c, struct zx_xac_StatusCode_s* x )
{
  struct zx_ns_s* pop_seen = 0;
  struct zx_elem_s* se MAYBE_UNUSED;
#if 1 /* NORMALMODE */
  /* *** in simple_elem case should output ns prefix from ns node. */
  int len = sizeof("<xac:StatusCode")-1 + 1 + sizeof("</xac:StatusCode>")-1;
  if (c->inc_ns_len)
    len += zx_len_inc_ns(c, &pop_seen);
  len += zx_len_xmlns_if_not_seen(c, zx_ns_tab+zx_xmlns_ix_xac, &pop_seen);

  len += zx_attr_so_len(c, x->Value, sizeof("Value")-1, &pop_seen);

#else
  /* root node has no begin tag */
  int len = 0;
#endif
  
  {
      struct zx_xac_StatusCode_s* e;
      for (e = x->StatusCode; e; e = (struct zx_xac_StatusCode_s*)e->gg.g.n)
	  len += zx_LEN_SO_xac_StatusCode(c, e);
  }


  len += zx_len_so_common(c, &x->gg, &pop_seen);
  zx_pop_seen(pop_seen);
  ENC_LEN_DEBUG(x, "xac:StatusCode", len);
  return len;
}

/* FUNC(zx_LEN_WO_xac_StatusCode) */

/* Compute length of an element (and its subelements). The XML attributes
 * and elements are processed in wire order and no assumptions
 * are made about namespace prefixes. */

/* Called by: */
int zx_LEN_WO_xac_StatusCode(struct zx_ctx* c, struct zx_xac_StatusCode_s* x )
{
  struct zx_ns_s* pop_seen = 0;
  struct zx_elem_s* se MAYBE_UNUSED;
#if 1 /* NORMALMODE */
  int len = 1 + sizeof("StatusCode")-1 + 1 + 2 + sizeof("StatusCode")-1 + 1;
  
  if (x->gg.g.ns && x->gg.g.ns->prefix_len)
    len += (x->gg.g.ns->prefix_len + 1) * 2;
  if (c->inc_ns_len)
    len += zx_len_inc_ns(c, &pop_seen);
  len += zx_len_xmlns_if_not_seen(c, x->gg.g.ns, &pop_seen);

  len += zx_attr_wo_len(c, x->Value, sizeof("Value")-1, &pop_seen);

#else
  /* root node has no begin tag */
  int len = 0;
#endif
  
  {
      struct zx_xac_StatusCode_s* e;
      for (e = x->StatusCode; e; e = (struct zx_xac_StatusCode_s*)e->gg.g.n)
	  len += zx_LEN_WO_xac_StatusCode(c, e);
  }


  len += zx_len_wo_common(c, &x->gg, &pop_seen); 
  zx_pop_seen(pop_seen);
  ENC_LEN_DEBUG(x, "xac:StatusCode", len);
  return len;
}

/* FUNC(zx_ENC_SO_xac_StatusCode) */

/* Render element into string. The XML attributes and elements are
 * processed in schema order. This is what you generally want for
 * rendering new data structure to a string. The wo pointers are not used. */

/* Called by: */
char* zx_ENC_SO_xac_StatusCode(struct zx_ctx* c, struct zx_xac_StatusCode_s* x, char* p )
{
  struct zx_elem_s* se MAYBE_UNUSED;
  struct zx_ns_s* pop_seen = 0;
  ENC_LEN_DEBUG_BASE;
#if 1 /* NORMALMODE */
  /* *** in simple_elem case should output ns prefix from ns node. */
  ZX_OUT_TAG(p, "<xac:StatusCode");
  if (c->inc_ns)
    zx_add_inc_ns(c, &pop_seen);
  zx_add_xmlns_if_not_seen(c, zx_ns_tab+zx_xmlns_ix_xac, &pop_seen);

  zx_see_unknown_attrs_ns(c, x->gg.any_attr, &pop_seen);
  p = zx_enc_seen(p, pop_seen); 
  p = zx_attr_so_enc(p, x->Value, " Value=\"", sizeof(" Value=\"")-1);

  p = zx_enc_unknown_attrs(p, x->gg.any_attr);
#else
  /* root node has no begin tag */
#endif
  
  {
      struct zx_xac_StatusCode_s* e;
      for (e = x->StatusCode; e; e = (struct zx_xac_StatusCode_s*)e->gg.g.n)
	  p = zx_ENC_SO_xac_StatusCode(c, e, p);
  }

  p = zx_enc_so_unknown_elems_and_content(c, p, &x->gg);
  
#if 1 /* NORMALMODE */
  ZX_OUT_CLOSE_TAG(p, "</xac:StatusCode>");
  zx_pop_seen(pop_seen);
#else
  /* root node has no end tag either */
#endif
  ENC_LEN_DEBUG(x, "xac:StatusCode", p-enc_base);
  return p;
}

/* FUNC(zx_ENC_WO_xac_StatusCode) */

/* Render element into string. The XML attributes and elements are
 * processed in wire order by chasing wo pointers. This is what you want for
 * validating signatures on other people's XML documents. */

/* Called by: */
char* zx_ENC_WO_xac_StatusCode(struct zx_ctx* c, struct zx_xac_StatusCode_s* x, char* p )
{
  struct zx_elem_s* kid;
  struct zx_ns_s* pop_seen = 0;
  char* q;
  char* qq;
  ENC_LEN_DEBUG_BASE;
#if 1 /* NORMALMODE */
  ZX_OUT_CH(p, '<');
  q = p;
  if (x->gg.g.ns && x->gg.g.ns->prefix_len) {
    ZX_OUT_MEM(p, x->gg.g.ns->prefix, x->gg.g.ns->prefix_len);
    ZX_OUT_CH(p, ':');
  }
  ZX_OUT_MEM(p, "StatusCode", sizeof("StatusCode")-1);
  qq = p;

  if (c->inc_ns)
    zx_add_inc_ns(c, &pop_seen);
  zx_add_xmlns_if_not_seen(c, x->gg.g.ns, &pop_seen);

  zx_see_unknown_attrs_ns(c, x->gg.any_attr, &pop_seen);
  p = zx_enc_seen(p, pop_seen); 
  p = zx_attr_wo_enc(p, x->Value, "Value=\"", sizeof("Value=\"")-1);

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
  ENC_LEN_DEBUG(x, "xac:StatusCode", p-enc_base);
  return p;
}

/* FUNC(zx_EASY_ENC_SO_xac_StatusCode) */

/* Called by: */
struct zx_str* zx_EASY_ENC_SO_xac_StatusCode(struct zx_ctx* c, struct zx_xac_StatusCode_s* x )
{
  int len;
  char* buf;
  c->ns_tab = ZX_ALLOC(c, sizeof(zx_ns_tab));
  memcpy(c->ns_tab, zx_ns_tab, sizeof(zx_ns_tab));
  len = zx_LEN_SO_xac_StatusCode(c, x );
  buf = ZX_ALLOC(c, len+1);
  return zx_easy_enc_common(c, zx_ENC_SO_xac_StatusCode(c, x, buf ), buf, len);
}

/* FUNC(zx_EASY_ENC_WO_xac_StatusCode) */

/* Called by: */
struct zx_str* zx_EASY_ENC_WO_xac_StatusCode(struct zx_ctx* c, struct zx_xac_StatusCode_s* x )
{
  int len;
  char* buf;
  c->ns_tab = ZX_ALLOC(c, sizeof(zx_ns_tab));
  memcpy(c->ns_tab, zx_ns_tab, sizeof(zx_ns_tab));
  len = zx_LEN_WO_xac_StatusCode(c, x );
  buf = ZX_ALLOC(c, len+1);
  return zx_easy_enc_common(c, zx_ENC_WO_xac_StatusCode(c, x, buf ), buf, len);
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

#define EL_NAME   xac_StatusDetail
#define EL_STRUCT zx_xac_StatusDetail_s
#define EL_NS     xac
#define EL_TAG    StatusDetail

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

/* FUNC(zx_LEN_SO_xac_StatusDetail) */

/* Compute length of an element (and its subelements). The XML attributes
 * and elements are processed in schema order. */

/* Called by: */
int zx_LEN_SO_xac_StatusDetail(struct zx_ctx* c, struct zx_xac_StatusDetail_s* x )
{
  struct zx_ns_s* pop_seen = 0;
  struct zx_elem_s* se MAYBE_UNUSED;
#if 1 /* NORMALMODE */
  /* *** in simple_elem case should output ns prefix from ns node. */
  int len = sizeof("<xac:StatusDetail")-1 + 1 + sizeof("</xac:StatusDetail>")-1;
  if (c->inc_ns_len)
    len += zx_len_inc_ns(c, &pop_seen);
  len += zx_len_xmlns_if_not_seen(c, zx_ns_tab+zx_xmlns_ix_xac, &pop_seen);


#else
  /* root node has no begin tag */
  int len = 0;
#endif
  


  len += zx_len_so_common(c, &x->gg, &pop_seen);
  zx_pop_seen(pop_seen);
  ENC_LEN_DEBUG(x, "xac:StatusDetail", len);
  return len;
}

/* FUNC(zx_LEN_WO_xac_StatusDetail) */

/* Compute length of an element (and its subelements). The XML attributes
 * and elements are processed in wire order and no assumptions
 * are made about namespace prefixes. */

/* Called by: */
int zx_LEN_WO_xac_StatusDetail(struct zx_ctx* c, struct zx_xac_StatusDetail_s* x )
{
  struct zx_ns_s* pop_seen = 0;
  struct zx_elem_s* se MAYBE_UNUSED;
#if 1 /* NORMALMODE */
  int len = 1 + sizeof("StatusDetail")-1 + 1 + 2 + sizeof("StatusDetail")-1 + 1;
  
  if (x->gg.g.ns && x->gg.g.ns->prefix_len)
    len += (x->gg.g.ns->prefix_len + 1) * 2;
  if (c->inc_ns_len)
    len += zx_len_inc_ns(c, &pop_seen);
  len += zx_len_xmlns_if_not_seen(c, x->gg.g.ns, &pop_seen);


#else
  /* root node has no begin tag */
  int len = 0;
#endif
  


  len += zx_len_wo_common(c, &x->gg, &pop_seen); 
  zx_pop_seen(pop_seen);
  ENC_LEN_DEBUG(x, "xac:StatusDetail", len);
  return len;
}

/* FUNC(zx_ENC_SO_xac_StatusDetail) */

/* Render element into string. The XML attributes and elements are
 * processed in schema order. This is what you generally want for
 * rendering new data structure to a string. The wo pointers are not used. */

/* Called by: */
char* zx_ENC_SO_xac_StatusDetail(struct zx_ctx* c, struct zx_xac_StatusDetail_s* x, char* p )
{
  struct zx_elem_s* se MAYBE_UNUSED;
  struct zx_ns_s* pop_seen = 0;
  ENC_LEN_DEBUG_BASE;
#if 1 /* NORMALMODE */
  /* *** in simple_elem case should output ns prefix from ns node. */
  ZX_OUT_TAG(p, "<xac:StatusDetail");
  if (c->inc_ns)
    zx_add_inc_ns(c, &pop_seen);
  zx_add_xmlns_if_not_seen(c, zx_ns_tab+zx_xmlns_ix_xac, &pop_seen);

  zx_see_unknown_attrs_ns(c, x->gg.any_attr, &pop_seen);
  p = zx_enc_seen(p, pop_seen); 

  p = zx_enc_unknown_attrs(p, x->gg.any_attr);
#else
  /* root node has no begin tag */
#endif
  

  p = zx_enc_so_unknown_elems_and_content(c, p, &x->gg);
  
#if 1 /* NORMALMODE */
  ZX_OUT_CLOSE_TAG(p, "</xac:StatusDetail>");
  zx_pop_seen(pop_seen);
#else
  /* root node has no end tag either */
#endif
  ENC_LEN_DEBUG(x, "xac:StatusDetail", p-enc_base);
  return p;
}

/* FUNC(zx_ENC_WO_xac_StatusDetail) */

/* Render element into string. The XML attributes and elements are
 * processed in wire order by chasing wo pointers. This is what you want for
 * validating signatures on other people's XML documents. */

/* Called by: */
char* zx_ENC_WO_xac_StatusDetail(struct zx_ctx* c, struct zx_xac_StatusDetail_s* x, char* p )
{
  struct zx_elem_s* kid;
  struct zx_ns_s* pop_seen = 0;
  char* q;
  char* qq;
  ENC_LEN_DEBUG_BASE;
#if 1 /* NORMALMODE */
  ZX_OUT_CH(p, '<');
  q = p;
  if (x->gg.g.ns && x->gg.g.ns->prefix_len) {
    ZX_OUT_MEM(p, x->gg.g.ns->prefix, x->gg.g.ns->prefix_len);
    ZX_OUT_CH(p, ':');
  }
  ZX_OUT_MEM(p, "StatusDetail", sizeof("StatusDetail")-1);
  qq = p;

  if (c->inc_ns)
    zx_add_inc_ns(c, &pop_seen);
  zx_add_xmlns_if_not_seen(c, x->gg.g.ns, &pop_seen);

  zx_see_unknown_attrs_ns(c, x->gg.any_attr, &pop_seen);
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
  ENC_LEN_DEBUG(x, "xac:StatusDetail", p-enc_base);
  return p;
}

/* FUNC(zx_EASY_ENC_SO_xac_StatusDetail) */

/* Called by: */
struct zx_str* zx_EASY_ENC_SO_xac_StatusDetail(struct zx_ctx* c, struct zx_xac_StatusDetail_s* x )
{
  int len;
  char* buf;
  c->ns_tab = ZX_ALLOC(c, sizeof(zx_ns_tab));
  memcpy(c->ns_tab, zx_ns_tab, sizeof(zx_ns_tab));
  len = zx_LEN_SO_xac_StatusDetail(c, x );
  buf = ZX_ALLOC(c, len+1);
  return zx_easy_enc_common(c, zx_ENC_SO_xac_StatusDetail(c, x, buf ), buf, len);
}

/* FUNC(zx_EASY_ENC_WO_xac_StatusDetail) */

/* Called by: */
struct zx_str* zx_EASY_ENC_WO_xac_StatusDetail(struct zx_ctx* c, struct zx_xac_StatusDetail_s* x )
{
  int len;
  char* buf;
  c->ns_tab = ZX_ALLOC(c, sizeof(zx_ns_tab));
  memcpy(c->ns_tab, zx_ns_tab, sizeof(zx_ns_tab));
  len = zx_LEN_WO_xac_StatusDetail(c, x );
  buf = ZX_ALLOC(c, len+1);
  return zx_easy_enc_common(c, zx_ENC_WO_xac_StatusDetail(c, x, buf ), buf, len);
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

#define EL_NAME   xac_Subject
#define EL_STRUCT zx_xac_Subject_s
#define EL_NS     xac
#define EL_TAG    Subject

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

/* FUNC(zx_LEN_SO_xac_Subject) */

/* Compute length of an element (and its subelements). The XML attributes
 * and elements are processed in schema order. */

/* Called by: */
int zx_LEN_SO_xac_Subject(struct zx_ctx* c, struct zx_xac_Subject_s* x )
{
  struct zx_ns_s* pop_seen = 0;
  struct zx_elem_s* se MAYBE_UNUSED;
#if 1 /* NORMALMODE */
  /* *** in simple_elem case should output ns prefix from ns node. */
  int len = sizeof("<xac:Subject")-1 + 1 + sizeof("</xac:Subject>")-1;
  if (c->inc_ns_len)
    len += zx_len_inc_ns(c, &pop_seen);
  len += zx_len_xmlns_if_not_seen(c, zx_ns_tab+zx_xmlns_ix_xac, &pop_seen);

  len += zx_attr_so_len(c, x->SubjectCategory, sizeof("SubjectCategory")-1, &pop_seen);

#else
  /* root node has no begin tag */
  int len = 0;
#endif
  
  {
      struct zx_xac_Attribute_s* e;
      for (e = x->Attribute; e; e = (struct zx_xac_Attribute_s*)e->gg.g.n)
	  len += zx_LEN_SO_xac_Attribute(c, e);
  }


  len += zx_len_so_common(c, &x->gg, &pop_seen);
  zx_pop_seen(pop_seen);
  ENC_LEN_DEBUG(x, "xac:Subject", len);
  return len;
}

/* FUNC(zx_LEN_WO_xac_Subject) */

/* Compute length of an element (and its subelements). The XML attributes
 * and elements are processed in wire order and no assumptions
 * are made about namespace prefixes. */

/* Called by: */
int zx_LEN_WO_xac_Subject(struct zx_ctx* c, struct zx_xac_Subject_s* x )
{
  struct zx_ns_s* pop_seen = 0;
  struct zx_elem_s* se MAYBE_UNUSED;
#if 1 /* NORMALMODE */
  int len = 1 + sizeof("Subject")-1 + 1 + 2 + sizeof("Subject")-1 + 1;
  
  if (x->gg.g.ns && x->gg.g.ns->prefix_len)
    len += (x->gg.g.ns->prefix_len + 1) * 2;
  if (c->inc_ns_len)
    len += zx_len_inc_ns(c, &pop_seen);
  len += zx_len_xmlns_if_not_seen(c, x->gg.g.ns, &pop_seen);

  len += zx_attr_wo_len(c, x->SubjectCategory, sizeof("SubjectCategory")-1, &pop_seen);

#else
  /* root node has no begin tag */
  int len = 0;
#endif
  
  {
      struct zx_xac_Attribute_s* e;
      for (e = x->Attribute; e; e = (struct zx_xac_Attribute_s*)e->gg.g.n)
	  len += zx_LEN_WO_xac_Attribute(c, e);
  }


  len += zx_len_wo_common(c, &x->gg, &pop_seen); 
  zx_pop_seen(pop_seen);
  ENC_LEN_DEBUG(x, "xac:Subject", len);
  return len;
}

/* FUNC(zx_ENC_SO_xac_Subject) */

/* Render element into string. The XML attributes and elements are
 * processed in schema order. This is what you generally want for
 * rendering new data structure to a string. The wo pointers are not used. */

/* Called by: */
char* zx_ENC_SO_xac_Subject(struct zx_ctx* c, struct zx_xac_Subject_s* x, char* p )
{
  struct zx_elem_s* se MAYBE_UNUSED;
  struct zx_ns_s* pop_seen = 0;
  ENC_LEN_DEBUG_BASE;
#if 1 /* NORMALMODE */
  /* *** in simple_elem case should output ns prefix from ns node. */
  ZX_OUT_TAG(p, "<xac:Subject");
  if (c->inc_ns)
    zx_add_inc_ns(c, &pop_seen);
  zx_add_xmlns_if_not_seen(c, zx_ns_tab+zx_xmlns_ix_xac, &pop_seen);

  zx_see_unknown_attrs_ns(c, x->gg.any_attr, &pop_seen);
  p = zx_enc_seen(p, pop_seen); 
  p = zx_attr_so_enc(p, x->SubjectCategory, " SubjectCategory=\"", sizeof(" SubjectCategory=\"")-1);

  p = zx_enc_unknown_attrs(p, x->gg.any_attr);
#else
  /* root node has no begin tag */
#endif
  
  {
      struct zx_xac_Attribute_s* e;
      for (e = x->Attribute; e; e = (struct zx_xac_Attribute_s*)e->gg.g.n)
	  p = zx_ENC_SO_xac_Attribute(c, e, p);
  }

  p = zx_enc_so_unknown_elems_and_content(c, p, &x->gg);
  
#if 1 /* NORMALMODE */
  ZX_OUT_CLOSE_TAG(p, "</xac:Subject>");
  zx_pop_seen(pop_seen);
#else
  /* root node has no end tag either */
#endif
  ENC_LEN_DEBUG(x, "xac:Subject", p-enc_base);
  return p;
}

/* FUNC(zx_ENC_WO_xac_Subject) */

/* Render element into string. The XML attributes and elements are
 * processed in wire order by chasing wo pointers. This is what you want for
 * validating signatures on other people's XML documents. */

/* Called by: */
char* zx_ENC_WO_xac_Subject(struct zx_ctx* c, struct zx_xac_Subject_s* x, char* p )
{
  struct zx_elem_s* kid;
  struct zx_ns_s* pop_seen = 0;
  char* q;
  char* qq;
  ENC_LEN_DEBUG_BASE;
#if 1 /* NORMALMODE */
  ZX_OUT_CH(p, '<');
  q = p;
  if (x->gg.g.ns && x->gg.g.ns->prefix_len) {
    ZX_OUT_MEM(p, x->gg.g.ns->prefix, x->gg.g.ns->prefix_len);
    ZX_OUT_CH(p, ':');
  }
  ZX_OUT_MEM(p, "Subject", sizeof("Subject")-1);
  qq = p;

  if (c->inc_ns)
    zx_add_inc_ns(c, &pop_seen);
  zx_add_xmlns_if_not_seen(c, x->gg.g.ns, &pop_seen);

  zx_see_unknown_attrs_ns(c, x->gg.any_attr, &pop_seen);
  p = zx_enc_seen(p, pop_seen); 
  p = zx_attr_wo_enc(p, x->SubjectCategory, "SubjectCategory=\"", sizeof("SubjectCategory=\"")-1);

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
  ENC_LEN_DEBUG(x, "xac:Subject", p-enc_base);
  return p;
}

/* FUNC(zx_EASY_ENC_SO_xac_Subject) */

/* Called by: */
struct zx_str* zx_EASY_ENC_SO_xac_Subject(struct zx_ctx* c, struct zx_xac_Subject_s* x )
{
  int len;
  char* buf;
  c->ns_tab = ZX_ALLOC(c, sizeof(zx_ns_tab));
  memcpy(c->ns_tab, zx_ns_tab, sizeof(zx_ns_tab));
  len = zx_LEN_SO_xac_Subject(c, x );
  buf = ZX_ALLOC(c, len+1);
  return zx_easy_enc_common(c, zx_ENC_SO_xac_Subject(c, x, buf ), buf, len);
}

/* FUNC(zx_EASY_ENC_WO_xac_Subject) */

/* Called by: */
struct zx_str* zx_EASY_ENC_WO_xac_Subject(struct zx_ctx* c, struct zx_xac_Subject_s* x )
{
  int len;
  char* buf;
  c->ns_tab = ZX_ALLOC(c, sizeof(zx_ns_tab));
  memcpy(c->ns_tab, zx_ns_tab, sizeof(zx_ns_tab));
  len = zx_LEN_WO_xac_Subject(c, x );
  buf = ZX_ALLOC(c, len+1);
  return zx_easy_enc_common(c, zx_ENC_WO_xac_Subject(c, x, buf ), buf, len);
}




/* EOF -- c/zx-xac-enc.c */
