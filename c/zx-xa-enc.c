/* c/zx-xa-enc.c - WARNING: This file was automatically generated. DO NOT EDIT!
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
#include "c/zx-xa-data.h"
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

#define EL_NAME   xa_Action
#define EL_STRUCT zx_xa_Action_s
#define EL_NS     xa
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

/* FUNC(zx_LEN_SO_xa_Action) */

/* Compute length of an element (and its subelements). The XML attributes
 * and elements are processed in schema order. */

/* Called by: */
int zx_LEN_SO_xa_Action(struct zx_ctx* c, struct zx_xa_Action_s* x )
{
  struct zx_ns_s* pop_seen = 0;
  struct zx_elem_s* se MAYBE_UNUSED;
#if 1 /* NORMALMODE */
  /* *** in simple_elem case should output ns prefix from ns node. */
  int len = sizeof("<xa:Action")-1 + 1 + sizeof("</xa:Action>")-1;
  if (c->inc_ns_len)
    len += zx_len_inc_ns(c, &pop_seen);
  len += zx_len_xmlns_if_not_seen(c, zx_ns_tab+zx_xmlns_ix_xa, &pop_seen);


#else
  /* root node has no begin tag */
  int len = 0;
#endif
  
  {
      struct zx_xa_ActionMatch_s* e;
      for (e = x->ActionMatch; e; e = (struct zx_xa_ActionMatch_s*)e->gg.g.n)
	  len += zx_LEN_SO_xa_ActionMatch(c, e);
  }


  len += zx_len_so_common(c, &x->gg);
  zx_pop_seen(pop_seen);
  ENC_LEN_DEBUG(x, "xa:Action", len);
  return len;
}

/* FUNC(zx_LEN_WO_xa_Action) */

/* Compute length of an element (and its subelements). The XML attributes
 * and elements are processed in wire order and no assumptions
 * are made about namespace prefixes. */

/* Called by: */
int zx_LEN_WO_xa_Action(struct zx_ctx* c, struct zx_xa_Action_s* x )
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
      struct zx_xa_ActionMatch_s* e;
      for (e = x->ActionMatch; e; e = (struct zx_xa_ActionMatch_s*)e->gg.g.n)
	  len += zx_LEN_WO_xa_ActionMatch(c, e);
  }


  len += zx_len_wo_common(c, &x->gg); 
  zx_pop_seen(pop_seen);
  ENC_LEN_DEBUG(x, "xa:Action", len);
  return len;
}

/* FUNC(zx_ENC_SO_xa_Action) */

/* Render element into string. The XML attributes and elements are
 * processed in schema order. This is what you generally want for
 * rendering new data structure to a string. The wo pointers are not used. */

/* Called by: */
char* zx_ENC_SO_xa_Action(struct zx_ctx* c, struct zx_xa_Action_s* x, char* p )
{
  struct zx_elem_s* se MAYBE_UNUSED;
  ENC_LEN_DEBUG_BASE;
#if 1 /* NORMALMODE */
  struct zx_ns_s* pop_seen = 0;
  /* *** in simple_elem case should output ns prefix from ns node. */
  ZX_OUT_TAG(p, "<xa:Action");
  if (c->inc_ns)
    p = zx_enc_inc_ns(c, p, &pop_seen);
  p = zx_enc_xmlns_if_not_seen(c, p, zx_ns_tab+zx_xmlns_ix_xa, &pop_seen);


  p = zx_enc_unknown_attrs(p, x->gg.any_attr);
#else
  /* root node has no begin tag */
#endif
  
  {
      struct zx_xa_ActionMatch_s* e;
      for (e = x->ActionMatch; e; e = (struct zx_xa_ActionMatch_s*)e->gg.g.n)
	  p = zx_ENC_SO_xa_ActionMatch(c, e, p);
  }

  p = zx_enc_so_unknown_elems_and_content(c, p, &x->gg);
  
#if 1 /* NORMALMODE */
  ZX_OUT_CLOSE_TAG(p, "</xa:Action>");
  zx_pop_seen(pop_seen);
#else
  /* root node has no end tag either */
#endif
  ENC_LEN_DEBUG(x, "xa:Action", p-enc_base);
  return p;
}

/* FUNC(zx_ENC_WO_xa_Action) */

/* Render element into string. The XML attributes and elements are
 * processed in wire order by chasing wo pointers. This is what you want for
 * validating signatures on other people's XML documents. */

/* Called by: */
char* zx_ENC_WO_xa_Action(struct zx_ctx* c, struct zx_xa_Action_s* x, char* p )
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
  ZX_OUT_MEM(p, "Action", sizeof("Action")-1);
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
  ENC_LEN_DEBUG(x, "xa:Action", p-enc_base);
  return p;
}

/* FUNC(zx_EASY_ENC_SO_xa_Action) */

/* Called by: */
struct zx_str* zx_EASY_ENC_SO_xa_Action(struct zx_ctx* c, struct zx_xa_Action_s* x )
{
  int len;
  char* buf;
  c->ns_tab = ZX_ALLOC(c, sizeof(zx_ns_tab));
  memcpy(c->ns_tab, zx_ns_tab, sizeof(zx_ns_tab));
  len = zx_LEN_SO_xa_Action(c, x );
  buf = ZX_ALLOC(c, len+1);
  return zx_easy_enc_common(c, zx_ENC_SO_xa_Action(c, x, buf ), buf, len);
}

/* FUNC(zx_EASY_ENC_WO_xa_Action) */

/* Called by: */
struct zx_str* zx_EASY_ENC_WO_xa_Action(struct zx_ctx* c, struct zx_xa_Action_s* x )
{
  int len;
  char* buf;
  c->ns_tab = ZX_ALLOC(c, sizeof(zx_ns_tab));
  memcpy(c->ns_tab, zx_ns_tab, sizeof(zx_ns_tab));
  len = zx_LEN_WO_xa_Action(c, x );
  buf = ZX_ALLOC(c, len+1);
  return zx_easy_enc_common(c, zx_ENC_WO_xa_Action(c, x, buf ), buf, len);
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

#define EL_NAME   xa_ActionAttributeDesignator
#define EL_STRUCT zx_xa_ActionAttributeDesignator_s
#define EL_NS     xa
#define EL_TAG    ActionAttributeDesignator

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

/* FUNC(zx_LEN_SO_xa_ActionAttributeDesignator) */

/* Compute length of an element (and its subelements). The XML attributes
 * and elements are processed in schema order. */

/* Called by: */
int zx_LEN_SO_xa_ActionAttributeDesignator(struct zx_ctx* c, struct zx_xa_ActionAttributeDesignator_s* x )
{
  struct zx_ns_s* pop_seen = 0;
  struct zx_elem_s* se MAYBE_UNUSED;
#if 1 /* NORMALMODE */
  /* *** in simple_elem case should output ns prefix from ns node. */
  int len = sizeof("<xa:ActionAttributeDesignator")-1 + 1 + sizeof("</xa:ActionAttributeDesignator>")-1;
  if (c->inc_ns_len)
    len += zx_len_inc_ns(c, &pop_seen);
  len += zx_len_xmlns_if_not_seen(c, zx_ns_tab+zx_xmlns_ix_xa, &pop_seen);

  len += zx_attr_so_len(x->AttributeId, sizeof("AttributeId")-1);
  len += zx_attr_so_len(x->DataType, sizeof("DataType")-1);
  len += zx_attr_so_len(x->Issuer, sizeof("Issuer")-1);
  len += zx_attr_so_len(x->MustBePresent, sizeof("MustBePresent")-1);

#else
  /* root node has no begin tag */
  int len = 0;
#endif
  


  len += zx_len_so_common(c, &x->gg);
  zx_pop_seen(pop_seen);
  ENC_LEN_DEBUG(x, "xa:ActionAttributeDesignator", len);
  return len;
}

/* FUNC(zx_LEN_WO_xa_ActionAttributeDesignator) */

/* Compute length of an element (and its subelements). The XML attributes
 * and elements are processed in wire order and no assumptions
 * are made about namespace prefixes. */

/* Called by: */
int zx_LEN_WO_xa_ActionAttributeDesignator(struct zx_ctx* c, struct zx_xa_ActionAttributeDesignator_s* x )
{
  struct zx_ns_s* pop_seen = 0;
  struct zx_elem_s* se MAYBE_UNUSED;
#if 1 /* NORMALMODE */
  int len = 1 + sizeof("ActionAttributeDesignator")-1 + 1 + 2 + sizeof("ActionAttributeDesignator")-1 + 1;
  
  if (x->gg.g.ns && x->gg.g.ns->prefix_len)
    len += (x->gg.g.ns->prefix_len + 1) * 2;
  if (c->inc_ns_len)
    len += zx_len_inc_ns(c, &pop_seen);
  len += zx_len_xmlns_if_not_seen(c, x->gg.g.ns, &pop_seen);

  len += zx_attr_wo_len(x->AttributeId, sizeof("AttributeId")-1);
  len += zx_attr_wo_len(x->DataType, sizeof("DataType")-1);
  len += zx_attr_wo_len(x->Issuer, sizeof("Issuer")-1);
  len += zx_attr_wo_len(x->MustBePresent, sizeof("MustBePresent")-1);

#else
  /* root node has no begin tag */
  int len = 0;
#endif
  


  len += zx_len_wo_common(c, &x->gg); 
  zx_pop_seen(pop_seen);
  ENC_LEN_DEBUG(x, "xa:ActionAttributeDesignator", len);
  return len;
}

/* FUNC(zx_ENC_SO_xa_ActionAttributeDesignator) */

/* Render element into string. The XML attributes and elements are
 * processed in schema order. This is what you generally want for
 * rendering new data structure to a string. The wo pointers are not used. */

/* Called by: */
char* zx_ENC_SO_xa_ActionAttributeDesignator(struct zx_ctx* c, struct zx_xa_ActionAttributeDesignator_s* x, char* p )
{
  struct zx_elem_s* se MAYBE_UNUSED;
  ENC_LEN_DEBUG_BASE;
#if 1 /* NORMALMODE */
  struct zx_ns_s* pop_seen = 0;
  /* *** in simple_elem case should output ns prefix from ns node. */
  ZX_OUT_TAG(p, "<xa:ActionAttributeDesignator");
  if (c->inc_ns)
    p = zx_enc_inc_ns(c, p, &pop_seen);
  p = zx_enc_xmlns_if_not_seen(c, p, zx_ns_tab+zx_xmlns_ix_xa, &pop_seen);

  p = zx_attr_so_enc(p, x->AttributeId, " AttributeId=\"", sizeof(" AttributeId=\"")-1);
  p = zx_attr_so_enc(p, x->DataType, " DataType=\"", sizeof(" DataType=\"")-1);
  p = zx_attr_so_enc(p, x->Issuer, " Issuer=\"", sizeof(" Issuer=\"")-1);
  p = zx_attr_so_enc(p, x->MustBePresent, " MustBePresent=\"", sizeof(" MustBePresent=\"")-1);

  p = zx_enc_unknown_attrs(p, x->gg.any_attr);
#else
  /* root node has no begin tag */
#endif
  

  p = zx_enc_so_unknown_elems_and_content(c, p, &x->gg);
  
#if 1 /* NORMALMODE */
  ZX_OUT_CLOSE_TAG(p, "</xa:ActionAttributeDesignator>");
  zx_pop_seen(pop_seen);
#else
  /* root node has no end tag either */
#endif
  ENC_LEN_DEBUG(x, "xa:ActionAttributeDesignator", p-enc_base);
  return p;
}

/* FUNC(zx_ENC_WO_xa_ActionAttributeDesignator) */

/* Render element into string. The XML attributes and elements are
 * processed in wire order by chasing wo pointers. This is what you want for
 * validating signatures on other people's XML documents. */

/* Called by: */
char* zx_ENC_WO_xa_ActionAttributeDesignator(struct zx_ctx* c, struct zx_xa_ActionAttributeDesignator_s* x, char* p )
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
  ZX_OUT_MEM(p, "ActionAttributeDesignator", sizeof("ActionAttributeDesignator")-1);
  qq = p;

  /* *** sort the namespaces */
  if (c->inc_ns)
    zx_add_inc_ns(c, &pop_seen);
  zx_add_xmlns_if_not_seen(c, x->gg.g.ns, &pop_seen);

  p = zx_enc_seen(p, pop_seen); 
  p = zx_attr_wo_enc(p, x->AttributeId, "AttributeId=\"", sizeof("AttributeId=\"")-1);
  p = zx_attr_wo_enc(p, x->DataType, "DataType=\"", sizeof("DataType=\"")-1);
  p = zx_attr_wo_enc(p, x->Issuer, "Issuer=\"", sizeof("Issuer=\"")-1);
  p = zx_attr_wo_enc(p, x->MustBePresent, "MustBePresent=\"", sizeof("MustBePresent=\"")-1);

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
  ENC_LEN_DEBUG(x, "xa:ActionAttributeDesignator", p-enc_base);
  return p;
}

/* FUNC(zx_EASY_ENC_SO_xa_ActionAttributeDesignator) */

/* Called by: */
struct zx_str* zx_EASY_ENC_SO_xa_ActionAttributeDesignator(struct zx_ctx* c, struct zx_xa_ActionAttributeDesignator_s* x )
{
  int len;
  char* buf;
  c->ns_tab = ZX_ALLOC(c, sizeof(zx_ns_tab));
  memcpy(c->ns_tab, zx_ns_tab, sizeof(zx_ns_tab));
  len = zx_LEN_SO_xa_ActionAttributeDesignator(c, x );
  buf = ZX_ALLOC(c, len+1);
  return zx_easy_enc_common(c, zx_ENC_SO_xa_ActionAttributeDesignator(c, x, buf ), buf, len);
}

/* FUNC(zx_EASY_ENC_WO_xa_ActionAttributeDesignator) */

/* Called by: */
struct zx_str* zx_EASY_ENC_WO_xa_ActionAttributeDesignator(struct zx_ctx* c, struct zx_xa_ActionAttributeDesignator_s* x )
{
  int len;
  char* buf;
  c->ns_tab = ZX_ALLOC(c, sizeof(zx_ns_tab));
  memcpy(c->ns_tab, zx_ns_tab, sizeof(zx_ns_tab));
  len = zx_LEN_WO_xa_ActionAttributeDesignator(c, x );
  buf = ZX_ALLOC(c, len+1);
  return zx_easy_enc_common(c, zx_ENC_WO_xa_ActionAttributeDesignator(c, x, buf ), buf, len);
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

#define EL_NAME   xa_ActionMatch
#define EL_STRUCT zx_xa_ActionMatch_s
#define EL_NS     xa
#define EL_TAG    ActionMatch

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

/* FUNC(zx_LEN_SO_xa_ActionMatch) */

/* Compute length of an element (and its subelements). The XML attributes
 * and elements are processed in schema order. */

/* Called by: */
int zx_LEN_SO_xa_ActionMatch(struct zx_ctx* c, struct zx_xa_ActionMatch_s* x )
{
  struct zx_ns_s* pop_seen = 0;
  struct zx_elem_s* se MAYBE_UNUSED;
#if 1 /* NORMALMODE */
  /* *** in simple_elem case should output ns prefix from ns node. */
  int len = sizeof("<xa:ActionMatch")-1 + 1 + sizeof("</xa:ActionMatch>")-1;
  if (c->inc_ns_len)
    len += zx_len_inc_ns(c, &pop_seen);
  len += zx_len_xmlns_if_not_seen(c, zx_ns_tab+zx_xmlns_ix_xa, &pop_seen);

  len += zx_attr_so_len(x->MatchId, sizeof("MatchId")-1);

#else
  /* root node has no begin tag */
  int len = 0;
#endif
  
  {
      struct zx_xa_AttributeValue_s* e;
      for (e = x->AttributeValue; e; e = (struct zx_xa_AttributeValue_s*)e->gg.g.n)
	  len += zx_LEN_SO_xa_AttributeValue(c, e);
  }
  {
      struct zx_xa_ActionAttributeDesignator_s* e;
      for (e = x->ActionAttributeDesignator; e; e = (struct zx_xa_ActionAttributeDesignator_s*)e->gg.g.n)
	  len += zx_LEN_SO_xa_ActionAttributeDesignator(c, e);
  }
  {
      struct zx_xa_AttributeSelector_s* e;
      for (e = x->AttributeSelector; e; e = (struct zx_xa_AttributeSelector_s*)e->gg.g.n)
	  len += zx_LEN_SO_xa_AttributeSelector(c, e);
  }


  len += zx_len_so_common(c, &x->gg);
  zx_pop_seen(pop_seen);
  ENC_LEN_DEBUG(x, "xa:ActionMatch", len);
  return len;
}

/* FUNC(zx_LEN_WO_xa_ActionMatch) */

/* Compute length of an element (and its subelements). The XML attributes
 * and elements are processed in wire order and no assumptions
 * are made about namespace prefixes. */

/* Called by: */
int zx_LEN_WO_xa_ActionMatch(struct zx_ctx* c, struct zx_xa_ActionMatch_s* x )
{
  struct zx_ns_s* pop_seen = 0;
  struct zx_elem_s* se MAYBE_UNUSED;
#if 1 /* NORMALMODE */
  int len = 1 + sizeof("ActionMatch")-1 + 1 + 2 + sizeof("ActionMatch")-1 + 1;
  
  if (x->gg.g.ns && x->gg.g.ns->prefix_len)
    len += (x->gg.g.ns->prefix_len + 1) * 2;
  if (c->inc_ns_len)
    len += zx_len_inc_ns(c, &pop_seen);
  len += zx_len_xmlns_if_not_seen(c, x->gg.g.ns, &pop_seen);

  len += zx_attr_wo_len(x->MatchId, sizeof("MatchId")-1);

#else
  /* root node has no begin tag */
  int len = 0;
#endif
  
  {
      struct zx_xa_AttributeValue_s* e;
      for (e = x->AttributeValue; e; e = (struct zx_xa_AttributeValue_s*)e->gg.g.n)
	  len += zx_LEN_WO_xa_AttributeValue(c, e);
  }
  {
      struct zx_xa_ActionAttributeDesignator_s* e;
      for (e = x->ActionAttributeDesignator; e; e = (struct zx_xa_ActionAttributeDesignator_s*)e->gg.g.n)
	  len += zx_LEN_WO_xa_ActionAttributeDesignator(c, e);
  }
  {
      struct zx_xa_AttributeSelector_s* e;
      for (e = x->AttributeSelector; e; e = (struct zx_xa_AttributeSelector_s*)e->gg.g.n)
	  len += zx_LEN_WO_xa_AttributeSelector(c, e);
  }


  len += zx_len_wo_common(c, &x->gg); 
  zx_pop_seen(pop_seen);
  ENC_LEN_DEBUG(x, "xa:ActionMatch", len);
  return len;
}

/* FUNC(zx_ENC_SO_xa_ActionMatch) */

/* Render element into string. The XML attributes and elements are
 * processed in schema order. This is what you generally want for
 * rendering new data structure to a string. The wo pointers are not used. */

/* Called by: */
char* zx_ENC_SO_xa_ActionMatch(struct zx_ctx* c, struct zx_xa_ActionMatch_s* x, char* p )
{
  struct zx_elem_s* se MAYBE_UNUSED;
  ENC_LEN_DEBUG_BASE;
#if 1 /* NORMALMODE */
  struct zx_ns_s* pop_seen = 0;
  /* *** in simple_elem case should output ns prefix from ns node. */
  ZX_OUT_TAG(p, "<xa:ActionMatch");
  if (c->inc_ns)
    p = zx_enc_inc_ns(c, p, &pop_seen);
  p = zx_enc_xmlns_if_not_seen(c, p, zx_ns_tab+zx_xmlns_ix_xa, &pop_seen);

  p = zx_attr_so_enc(p, x->MatchId, " MatchId=\"", sizeof(" MatchId=\"")-1);

  p = zx_enc_unknown_attrs(p, x->gg.any_attr);
#else
  /* root node has no begin tag */
#endif
  
  {
      struct zx_xa_AttributeValue_s* e;
      for (e = x->AttributeValue; e; e = (struct zx_xa_AttributeValue_s*)e->gg.g.n)
	  p = zx_ENC_SO_xa_AttributeValue(c, e, p);
  }
  {
      struct zx_xa_ActionAttributeDesignator_s* e;
      for (e = x->ActionAttributeDesignator; e; e = (struct zx_xa_ActionAttributeDesignator_s*)e->gg.g.n)
	  p = zx_ENC_SO_xa_ActionAttributeDesignator(c, e, p);
  }
  {
      struct zx_xa_AttributeSelector_s* e;
      for (e = x->AttributeSelector; e; e = (struct zx_xa_AttributeSelector_s*)e->gg.g.n)
	  p = zx_ENC_SO_xa_AttributeSelector(c, e, p);
  }

  p = zx_enc_so_unknown_elems_and_content(c, p, &x->gg);
  
#if 1 /* NORMALMODE */
  ZX_OUT_CLOSE_TAG(p, "</xa:ActionMatch>");
  zx_pop_seen(pop_seen);
#else
  /* root node has no end tag either */
#endif
  ENC_LEN_DEBUG(x, "xa:ActionMatch", p-enc_base);
  return p;
}

/* FUNC(zx_ENC_WO_xa_ActionMatch) */

/* Render element into string. The XML attributes and elements are
 * processed in wire order by chasing wo pointers. This is what you want for
 * validating signatures on other people's XML documents. */

/* Called by: */
char* zx_ENC_WO_xa_ActionMatch(struct zx_ctx* c, struct zx_xa_ActionMatch_s* x, char* p )
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
  ZX_OUT_MEM(p, "ActionMatch", sizeof("ActionMatch")-1);
  qq = p;

  /* *** sort the namespaces */
  if (c->inc_ns)
    zx_add_inc_ns(c, &pop_seen);
  zx_add_xmlns_if_not_seen(c, x->gg.g.ns, &pop_seen);

  p = zx_enc_seen(p, pop_seen); 
  p = zx_attr_wo_enc(p, x->MatchId, "MatchId=\"", sizeof("MatchId=\"")-1);

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
  ENC_LEN_DEBUG(x, "xa:ActionMatch", p-enc_base);
  return p;
}

/* FUNC(zx_EASY_ENC_SO_xa_ActionMatch) */

/* Called by: */
struct zx_str* zx_EASY_ENC_SO_xa_ActionMatch(struct zx_ctx* c, struct zx_xa_ActionMatch_s* x )
{
  int len;
  char* buf;
  c->ns_tab = ZX_ALLOC(c, sizeof(zx_ns_tab));
  memcpy(c->ns_tab, zx_ns_tab, sizeof(zx_ns_tab));
  len = zx_LEN_SO_xa_ActionMatch(c, x );
  buf = ZX_ALLOC(c, len+1);
  return zx_easy_enc_common(c, zx_ENC_SO_xa_ActionMatch(c, x, buf ), buf, len);
}

/* FUNC(zx_EASY_ENC_WO_xa_ActionMatch) */

/* Called by: */
struct zx_str* zx_EASY_ENC_WO_xa_ActionMatch(struct zx_ctx* c, struct zx_xa_ActionMatch_s* x )
{
  int len;
  char* buf;
  c->ns_tab = ZX_ALLOC(c, sizeof(zx_ns_tab));
  memcpy(c->ns_tab, zx_ns_tab, sizeof(zx_ns_tab));
  len = zx_LEN_WO_xa_ActionMatch(c, x );
  buf = ZX_ALLOC(c, len+1);
  return zx_easy_enc_common(c, zx_ENC_WO_xa_ActionMatch(c, x, buf ), buf, len);
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

#define EL_NAME   xa_Actions
#define EL_STRUCT zx_xa_Actions_s
#define EL_NS     xa
#define EL_TAG    Actions

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

/* FUNC(zx_LEN_SO_xa_Actions) */

/* Compute length of an element (and its subelements). The XML attributes
 * and elements are processed in schema order. */

/* Called by: */
int zx_LEN_SO_xa_Actions(struct zx_ctx* c, struct zx_xa_Actions_s* x )
{
  struct zx_ns_s* pop_seen = 0;
  struct zx_elem_s* se MAYBE_UNUSED;
#if 1 /* NORMALMODE */
  /* *** in simple_elem case should output ns prefix from ns node. */
  int len = sizeof("<xa:Actions")-1 + 1 + sizeof("</xa:Actions>")-1;
  if (c->inc_ns_len)
    len += zx_len_inc_ns(c, &pop_seen);
  len += zx_len_xmlns_if_not_seen(c, zx_ns_tab+zx_xmlns_ix_xa, &pop_seen);


#else
  /* root node has no begin tag */
  int len = 0;
#endif
  
  {
      struct zx_xa_Action_s* e;
      for (e = x->Action; e; e = (struct zx_xa_Action_s*)e->gg.g.n)
	  len += zx_LEN_SO_xa_Action(c, e);
  }


  len += zx_len_so_common(c, &x->gg);
  zx_pop_seen(pop_seen);
  ENC_LEN_DEBUG(x, "xa:Actions", len);
  return len;
}

/* FUNC(zx_LEN_WO_xa_Actions) */

/* Compute length of an element (and its subelements). The XML attributes
 * and elements are processed in wire order and no assumptions
 * are made about namespace prefixes. */

/* Called by: */
int zx_LEN_WO_xa_Actions(struct zx_ctx* c, struct zx_xa_Actions_s* x )
{
  struct zx_ns_s* pop_seen = 0;
  struct zx_elem_s* se MAYBE_UNUSED;
#if 1 /* NORMALMODE */
  int len = 1 + sizeof("Actions")-1 + 1 + 2 + sizeof("Actions")-1 + 1;
  
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
      struct zx_xa_Action_s* e;
      for (e = x->Action; e; e = (struct zx_xa_Action_s*)e->gg.g.n)
	  len += zx_LEN_WO_xa_Action(c, e);
  }


  len += zx_len_wo_common(c, &x->gg); 
  zx_pop_seen(pop_seen);
  ENC_LEN_DEBUG(x, "xa:Actions", len);
  return len;
}

/* FUNC(zx_ENC_SO_xa_Actions) */

/* Render element into string. The XML attributes and elements are
 * processed in schema order. This is what you generally want for
 * rendering new data structure to a string. The wo pointers are not used. */

/* Called by: */
char* zx_ENC_SO_xa_Actions(struct zx_ctx* c, struct zx_xa_Actions_s* x, char* p )
{
  struct zx_elem_s* se MAYBE_UNUSED;
  ENC_LEN_DEBUG_BASE;
#if 1 /* NORMALMODE */
  struct zx_ns_s* pop_seen = 0;
  /* *** in simple_elem case should output ns prefix from ns node. */
  ZX_OUT_TAG(p, "<xa:Actions");
  if (c->inc_ns)
    p = zx_enc_inc_ns(c, p, &pop_seen);
  p = zx_enc_xmlns_if_not_seen(c, p, zx_ns_tab+zx_xmlns_ix_xa, &pop_seen);


  p = zx_enc_unknown_attrs(p, x->gg.any_attr);
#else
  /* root node has no begin tag */
#endif
  
  {
      struct zx_xa_Action_s* e;
      for (e = x->Action; e; e = (struct zx_xa_Action_s*)e->gg.g.n)
	  p = zx_ENC_SO_xa_Action(c, e, p);
  }

  p = zx_enc_so_unknown_elems_and_content(c, p, &x->gg);
  
#if 1 /* NORMALMODE */
  ZX_OUT_CLOSE_TAG(p, "</xa:Actions>");
  zx_pop_seen(pop_seen);
#else
  /* root node has no end tag either */
#endif
  ENC_LEN_DEBUG(x, "xa:Actions", p-enc_base);
  return p;
}

/* FUNC(zx_ENC_WO_xa_Actions) */

/* Render element into string. The XML attributes and elements are
 * processed in wire order by chasing wo pointers. This is what you want for
 * validating signatures on other people's XML documents. */

/* Called by: */
char* zx_ENC_WO_xa_Actions(struct zx_ctx* c, struct zx_xa_Actions_s* x, char* p )
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
  ZX_OUT_MEM(p, "Actions", sizeof("Actions")-1);
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
  ENC_LEN_DEBUG(x, "xa:Actions", p-enc_base);
  return p;
}

/* FUNC(zx_EASY_ENC_SO_xa_Actions) */

/* Called by: */
struct zx_str* zx_EASY_ENC_SO_xa_Actions(struct zx_ctx* c, struct zx_xa_Actions_s* x )
{
  int len;
  char* buf;
  c->ns_tab = ZX_ALLOC(c, sizeof(zx_ns_tab));
  memcpy(c->ns_tab, zx_ns_tab, sizeof(zx_ns_tab));
  len = zx_LEN_SO_xa_Actions(c, x );
  buf = ZX_ALLOC(c, len+1);
  return zx_easy_enc_common(c, zx_ENC_SO_xa_Actions(c, x, buf ), buf, len);
}

/* FUNC(zx_EASY_ENC_WO_xa_Actions) */

/* Called by: */
struct zx_str* zx_EASY_ENC_WO_xa_Actions(struct zx_ctx* c, struct zx_xa_Actions_s* x )
{
  int len;
  char* buf;
  c->ns_tab = ZX_ALLOC(c, sizeof(zx_ns_tab));
  memcpy(c->ns_tab, zx_ns_tab, sizeof(zx_ns_tab));
  len = zx_LEN_WO_xa_Actions(c, x );
  buf = ZX_ALLOC(c, len+1);
  return zx_easy_enc_common(c, zx_ENC_WO_xa_Actions(c, x, buf ), buf, len);
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

#define EL_NAME   xa_Apply
#define EL_STRUCT zx_xa_Apply_s
#define EL_NS     xa
#define EL_TAG    Apply

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

/* FUNC(zx_LEN_SO_xa_Apply) */

/* Compute length of an element (and its subelements). The XML attributes
 * and elements are processed in schema order. */

/* Called by: */
int zx_LEN_SO_xa_Apply(struct zx_ctx* c, struct zx_xa_Apply_s* x )
{
  struct zx_ns_s* pop_seen = 0;
  struct zx_elem_s* se MAYBE_UNUSED;
#if 1 /* NORMALMODE */
  /* *** in simple_elem case should output ns prefix from ns node. */
  int len = sizeof("<xa:Apply")-1 + 1 + sizeof("</xa:Apply>")-1;
  if (c->inc_ns_len)
    len += zx_len_inc_ns(c, &pop_seen);
  len += zx_len_xmlns_if_not_seen(c, zx_ns_tab+zx_xmlns_ix_xa, &pop_seen);

  len += zx_attr_so_len(x->FunctionId, sizeof("FunctionId")-1);

#else
  /* root node has no begin tag */
  int len = 0;
#endif
  
  for (se = x->Expression; se; se = (struct zx_elem_s*)se->g.n)
    len += zx_LEN_SO_simple_elem(c,se, sizeof("xa:Expression")-1, zx_ns_tab+zx_xmlns_ix_xa);


  len += zx_len_so_common(c, &x->gg);
  zx_pop_seen(pop_seen);
  ENC_LEN_DEBUG(x, "xa:Apply", len);
  return len;
}

/* FUNC(zx_LEN_WO_xa_Apply) */

/* Compute length of an element (and its subelements). The XML attributes
 * and elements are processed in wire order and no assumptions
 * are made about namespace prefixes. */

/* Called by: */
int zx_LEN_WO_xa_Apply(struct zx_ctx* c, struct zx_xa_Apply_s* x )
{
  struct zx_ns_s* pop_seen = 0;
  struct zx_elem_s* se MAYBE_UNUSED;
#if 1 /* NORMALMODE */
  int len = 1 + sizeof("Apply")-1 + 1 + 2 + sizeof("Apply")-1 + 1;
  
  if (x->gg.g.ns && x->gg.g.ns->prefix_len)
    len += (x->gg.g.ns->prefix_len + 1) * 2;
  if (c->inc_ns_len)
    len += zx_len_inc_ns(c, &pop_seen);
  len += zx_len_xmlns_if_not_seen(c, x->gg.g.ns, &pop_seen);

  len += zx_attr_wo_len(x->FunctionId, sizeof("FunctionId")-1);

#else
  /* root node has no begin tag */
  int len = 0;
#endif
  
  for (se = x->Expression; se; se = (struct zx_elem_s*)se->g.n)
    len += zx_LEN_WO_simple_elem(c, se, sizeof("Expression")-1);


  len += zx_len_wo_common(c, &x->gg); 
  zx_pop_seen(pop_seen);
  ENC_LEN_DEBUG(x, "xa:Apply", len);
  return len;
}

/* FUNC(zx_ENC_SO_xa_Apply) */

/* Render element into string. The XML attributes and elements are
 * processed in schema order. This is what you generally want for
 * rendering new data structure to a string. The wo pointers are not used. */

/* Called by: */
char* zx_ENC_SO_xa_Apply(struct zx_ctx* c, struct zx_xa_Apply_s* x, char* p )
{
  struct zx_elem_s* se MAYBE_UNUSED;
  ENC_LEN_DEBUG_BASE;
#if 1 /* NORMALMODE */
  struct zx_ns_s* pop_seen = 0;
  /* *** in simple_elem case should output ns prefix from ns node. */
  ZX_OUT_TAG(p, "<xa:Apply");
  if (c->inc_ns)
    p = zx_enc_inc_ns(c, p, &pop_seen);
  p = zx_enc_xmlns_if_not_seen(c, p, zx_ns_tab+zx_xmlns_ix_xa, &pop_seen);

  p = zx_attr_so_enc(p, x->FunctionId, " FunctionId=\"", sizeof(" FunctionId=\"")-1);

  p = zx_enc_unknown_attrs(p, x->gg.any_attr);
#else
  /* root node has no begin tag */
#endif
  
  for (se = x->Expression; se; se = (struct zx_elem_s*)se->g.n)
    p = zx_ENC_SO_simple_elem(c, se, p, "xa:Expression", sizeof("xa:Expression")-1, zx_ns_tab+zx_xmlns_ix_xa);

  p = zx_enc_so_unknown_elems_and_content(c, p, &x->gg);
  
#if 1 /* NORMALMODE */
  ZX_OUT_CLOSE_TAG(p, "</xa:Apply>");
  zx_pop_seen(pop_seen);
#else
  /* root node has no end tag either */
#endif
  ENC_LEN_DEBUG(x, "xa:Apply", p-enc_base);
  return p;
}

/* FUNC(zx_ENC_WO_xa_Apply) */

/* Render element into string. The XML attributes and elements are
 * processed in wire order by chasing wo pointers. This is what you want for
 * validating signatures on other people's XML documents. */

/* Called by: */
char* zx_ENC_WO_xa_Apply(struct zx_ctx* c, struct zx_xa_Apply_s* x, char* p )
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
  ZX_OUT_MEM(p, "Apply", sizeof("Apply")-1);
  qq = p;

  /* *** sort the namespaces */
  if (c->inc_ns)
    zx_add_inc_ns(c, &pop_seen);
  zx_add_xmlns_if_not_seen(c, x->gg.g.ns, &pop_seen);

  p = zx_enc_seen(p, pop_seen); 
  p = zx_attr_wo_enc(p, x->FunctionId, "FunctionId=\"", sizeof("FunctionId=\"")-1);

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
  ENC_LEN_DEBUG(x, "xa:Apply", p-enc_base);
  return p;
}

/* FUNC(zx_EASY_ENC_SO_xa_Apply) */

/* Called by: */
struct zx_str* zx_EASY_ENC_SO_xa_Apply(struct zx_ctx* c, struct zx_xa_Apply_s* x )
{
  int len;
  char* buf;
  c->ns_tab = ZX_ALLOC(c, sizeof(zx_ns_tab));
  memcpy(c->ns_tab, zx_ns_tab, sizeof(zx_ns_tab));
  len = zx_LEN_SO_xa_Apply(c, x );
  buf = ZX_ALLOC(c, len+1);
  return zx_easy_enc_common(c, zx_ENC_SO_xa_Apply(c, x, buf ), buf, len);
}

/* FUNC(zx_EASY_ENC_WO_xa_Apply) */

/* Called by: */
struct zx_str* zx_EASY_ENC_WO_xa_Apply(struct zx_ctx* c, struct zx_xa_Apply_s* x )
{
  int len;
  char* buf;
  c->ns_tab = ZX_ALLOC(c, sizeof(zx_ns_tab));
  memcpy(c->ns_tab, zx_ns_tab, sizeof(zx_ns_tab));
  len = zx_LEN_WO_xa_Apply(c, x );
  buf = ZX_ALLOC(c, len+1);
  return zx_easy_enc_common(c, zx_ENC_WO_xa_Apply(c, x, buf ), buf, len);
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

#define EL_NAME   xa_AttributeAssignment
#define EL_STRUCT zx_xa_AttributeAssignment_s
#define EL_NS     xa
#define EL_TAG    AttributeAssignment

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

/* FUNC(zx_LEN_SO_xa_AttributeAssignment) */

/* Compute length of an element (and its subelements). The XML attributes
 * and elements are processed in schema order. */

/* Called by: */
int zx_LEN_SO_xa_AttributeAssignment(struct zx_ctx* c, struct zx_xa_AttributeAssignment_s* x )
{
  struct zx_ns_s* pop_seen = 0;
  struct zx_elem_s* se MAYBE_UNUSED;
#if 1 /* NORMALMODE */
  /* *** in simple_elem case should output ns prefix from ns node. */
  int len = sizeof("<xa:AttributeAssignment")-1 + 1 + sizeof("</xa:AttributeAssignment>")-1;
  if (c->inc_ns_len)
    len += zx_len_inc_ns(c, &pop_seen);
  len += zx_len_xmlns_if_not_seen(c, zx_ns_tab+zx_xmlns_ix_xa, &pop_seen);

  len += zx_attr_so_len(x->AttributeId, sizeof("AttributeId")-1);
  len += zx_attr_so_len(x->DataType, sizeof("DataType")-1);

#else
  /* root node has no begin tag */
  int len = 0;
#endif
  


  len += zx_len_so_common(c, &x->gg);
  zx_pop_seen(pop_seen);
  ENC_LEN_DEBUG(x, "xa:AttributeAssignment", len);
  return len;
}

/* FUNC(zx_LEN_WO_xa_AttributeAssignment) */

/* Compute length of an element (and its subelements). The XML attributes
 * and elements are processed in wire order and no assumptions
 * are made about namespace prefixes. */

/* Called by: */
int zx_LEN_WO_xa_AttributeAssignment(struct zx_ctx* c, struct zx_xa_AttributeAssignment_s* x )
{
  struct zx_ns_s* pop_seen = 0;
  struct zx_elem_s* se MAYBE_UNUSED;
#if 1 /* NORMALMODE */
  int len = 1 + sizeof("AttributeAssignment")-1 + 1 + 2 + sizeof("AttributeAssignment")-1 + 1;
  
  if (x->gg.g.ns && x->gg.g.ns->prefix_len)
    len += (x->gg.g.ns->prefix_len + 1) * 2;
  if (c->inc_ns_len)
    len += zx_len_inc_ns(c, &pop_seen);
  len += zx_len_xmlns_if_not_seen(c, x->gg.g.ns, &pop_seen);

  len += zx_attr_wo_len(x->AttributeId, sizeof("AttributeId")-1);
  len += zx_attr_wo_len(x->DataType, sizeof("DataType")-1);

#else
  /* root node has no begin tag */
  int len = 0;
#endif
  


  len += zx_len_wo_common(c, &x->gg); 
  zx_pop_seen(pop_seen);
  ENC_LEN_DEBUG(x, "xa:AttributeAssignment", len);
  return len;
}

/* FUNC(zx_ENC_SO_xa_AttributeAssignment) */

/* Render element into string. The XML attributes and elements are
 * processed in schema order. This is what you generally want for
 * rendering new data structure to a string. The wo pointers are not used. */

/* Called by: */
char* zx_ENC_SO_xa_AttributeAssignment(struct zx_ctx* c, struct zx_xa_AttributeAssignment_s* x, char* p )
{
  struct zx_elem_s* se MAYBE_UNUSED;
  ENC_LEN_DEBUG_BASE;
#if 1 /* NORMALMODE */
  struct zx_ns_s* pop_seen = 0;
  /* *** in simple_elem case should output ns prefix from ns node. */
  ZX_OUT_TAG(p, "<xa:AttributeAssignment");
  if (c->inc_ns)
    p = zx_enc_inc_ns(c, p, &pop_seen);
  p = zx_enc_xmlns_if_not_seen(c, p, zx_ns_tab+zx_xmlns_ix_xa, &pop_seen);

  p = zx_attr_so_enc(p, x->AttributeId, " AttributeId=\"", sizeof(" AttributeId=\"")-1);
  p = zx_attr_so_enc(p, x->DataType, " DataType=\"", sizeof(" DataType=\"")-1);

  p = zx_enc_unknown_attrs(p, x->gg.any_attr);
#else
  /* root node has no begin tag */
#endif
  

  p = zx_enc_so_unknown_elems_and_content(c, p, &x->gg);
  
#if 1 /* NORMALMODE */
  ZX_OUT_CLOSE_TAG(p, "</xa:AttributeAssignment>");
  zx_pop_seen(pop_seen);
#else
  /* root node has no end tag either */
#endif
  ENC_LEN_DEBUG(x, "xa:AttributeAssignment", p-enc_base);
  return p;
}

/* FUNC(zx_ENC_WO_xa_AttributeAssignment) */

/* Render element into string. The XML attributes and elements are
 * processed in wire order by chasing wo pointers. This is what you want for
 * validating signatures on other people's XML documents. */

/* Called by: */
char* zx_ENC_WO_xa_AttributeAssignment(struct zx_ctx* c, struct zx_xa_AttributeAssignment_s* x, char* p )
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
  ZX_OUT_MEM(p, "AttributeAssignment", sizeof("AttributeAssignment")-1);
  qq = p;

  /* *** sort the namespaces */
  if (c->inc_ns)
    zx_add_inc_ns(c, &pop_seen);
  zx_add_xmlns_if_not_seen(c, x->gg.g.ns, &pop_seen);

  p = zx_enc_seen(p, pop_seen); 
  p = zx_attr_wo_enc(p, x->AttributeId, "AttributeId=\"", sizeof("AttributeId=\"")-1);
  p = zx_attr_wo_enc(p, x->DataType, "DataType=\"", sizeof("DataType=\"")-1);

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
  ENC_LEN_DEBUG(x, "xa:AttributeAssignment", p-enc_base);
  return p;
}

/* FUNC(zx_EASY_ENC_SO_xa_AttributeAssignment) */

/* Called by: */
struct zx_str* zx_EASY_ENC_SO_xa_AttributeAssignment(struct zx_ctx* c, struct zx_xa_AttributeAssignment_s* x )
{
  int len;
  char* buf;
  c->ns_tab = ZX_ALLOC(c, sizeof(zx_ns_tab));
  memcpy(c->ns_tab, zx_ns_tab, sizeof(zx_ns_tab));
  len = zx_LEN_SO_xa_AttributeAssignment(c, x );
  buf = ZX_ALLOC(c, len+1);
  return zx_easy_enc_common(c, zx_ENC_SO_xa_AttributeAssignment(c, x, buf ), buf, len);
}

/* FUNC(zx_EASY_ENC_WO_xa_AttributeAssignment) */

/* Called by: */
struct zx_str* zx_EASY_ENC_WO_xa_AttributeAssignment(struct zx_ctx* c, struct zx_xa_AttributeAssignment_s* x )
{
  int len;
  char* buf;
  c->ns_tab = ZX_ALLOC(c, sizeof(zx_ns_tab));
  memcpy(c->ns_tab, zx_ns_tab, sizeof(zx_ns_tab));
  len = zx_LEN_WO_xa_AttributeAssignment(c, x );
  buf = ZX_ALLOC(c, len+1);
  return zx_easy_enc_common(c, zx_ENC_WO_xa_AttributeAssignment(c, x, buf ), buf, len);
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

#define EL_NAME   xa_AttributeSelector
#define EL_STRUCT zx_xa_AttributeSelector_s
#define EL_NS     xa
#define EL_TAG    AttributeSelector

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

/* FUNC(zx_LEN_SO_xa_AttributeSelector) */

/* Compute length of an element (and its subelements). The XML attributes
 * and elements are processed in schema order. */

/* Called by: */
int zx_LEN_SO_xa_AttributeSelector(struct zx_ctx* c, struct zx_xa_AttributeSelector_s* x )
{
  struct zx_ns_s* pop_seen = 0;
  struct zx_elem_s* se MAYBE_UNUSED;
#if 1 /* NORMALMODE */
  /* *** in simple_elem case should output ns prefix from ns node. */
  int len = sizeof("<xa:AttributeSelector")-1 + 1 + sizeof("</xa:AttributeSelector>")-1;
  if (c->inc_ns_len)
    len += zx_len_inc_ns(c, &pop_seen);
  len += zx_len_xmlns_if_not_seen(c, zx_ns_tab+zx_xmlns_ix_xa, &pop_seen);

  len += zx_attr_so_len(x->DataType, sizeof("DataType")-1);
  len += zx_attr_so_len(x->MustBePresent, sizeof("MustBePresent")-1);
  len += zx_attr_so_len(x->RequestContextPath, sizeof("RequestContextPath")-1);

#else
  /* root node has no begin tag */
  int len = 0;
#endif
  


  len += zx_len_so_common(c, &x->gg);
  zx_pop_seen(pop_seen);
  ENC_LEN_DEBUG(x, "xa:AttributeSelector", len);
  return len;
}

/* FUNC(zx_LEN_WO_xa_AttributeSelector) */

/* Compute length of an element (and its subelements). The XML attributes
 * and elements are processed in wire order and no assumptions
 * are made about namespace prefixes. */

/* Called by: */
int zx_LEN_WO_xa_AttributeSelector(struct zx_ctx* c, struct zx_xa_AttributeSelector_s* x )
{
  struct zx_ns_s* pop_seen = 0;
  struct zx_elem_s* se MAYBE_UNUSED;
#if 1 /* NORMALMODE */
  int len = 1 + sizeof("AttributeSelector")-1 + 1 + 2 + sizeof("AttributeSelector")-1 + 1;
  
  if (x->gg.g.ns && x->gg.g.ns->prefix_len)
    len += (x->gg.g.ns->prefix_len + 1) * 2;
  if (c->inc_ns_len)
    len += zx_len_inc_ns(c, &pop_seen);
  len += zx_len_xmlns_if_not_seen(c, x->gg.g.ns, &pop_seen);

  len += zx_attr_wo_len(x->DataType, sizeof("DataType")-1);
  len += zx_attr_wo_len(x->MustBePresent, sizeof("MustBePresent")-1);
  len += zx_attr_wo_len(x->RequestContextPath, sizeof("RequestContextPath")-1);

#else
  /* root node has no begin tag */
  int len = 0;
#endif
  


  len += zx_len_wo_common(c, &x->gg); 
  zx_pop_seen(pop_seen);
  ENC_LEN_DEBUG(x, "xa:AttributeSelector", len);
  return len;
}

/* FUNC(zx_ENC_SO_xa_AttributeSelector) */

/* Render element into string. The XML attributes and elements are
 * processed in schema order. This is what you generally want for
 * rendering new data structure to a string. The wo pointers are not used. */

/* Called by: */
char* zx_ENC_SO_xa_AttributeSelector(struct zx_ctx* c, struct zx_xa_AttributeSelector_s* x, char* p )
{
  struct zx_elem_s* se MAYBE_UNUSED;
  ENC_LEN_DEBUG_BASE;
#if 1 /* NORMALMODE */
  struct zx_ns_s* pop_seen = 0;
  /* *** in simple_elem case should output ns prefix from ns node. */
  ZX_OUT_TAG(p, "<xa:AttributeSelector");
  if (c->inc_ns)
    p = zx_enc_inc_ns(c, p, &pop_seen);
  p = zx_enc_xmlns_if_not_seen(c, p, zx_ns_tab+zx_xmlns_ix_xa, &pop_seen);

  p = zx_attr_so_enc(p, x->DataType, " DataType=\"", sizeof(" DataType=\"")-1);
  p = zx_attr_so_enc(p, x->MustBePresent, " MustBePresent=\"", sizeof(" MustBePresent=\"")-1);
  p = zx_attr_so_enc(p, x->RequestContextPath, " RequestContextPath=\"", sizeof(" RequestContextPath=\"")-1);

  p = zx_enc_unknown_attrs(p, x->gg.any_attr);
#else
  /* root node has no begin tag */
#endif
  

  p = zx_enc_so_unknown_elems_and_content(c, p, &x->gg);
  
#if 1 /* NORMALMODE */
  ZX_OUT_CLOSE_TAG(p, "</xa:AttributeSelector>");
  zx_pop_seen(pop_seen);
#else
  /* root node has no end tag either */
#endif
  ENC_LEN_DEBUG(x, "xa:AttributeSelector", p-enc_base);
  return p;
}

/* FUNC(zx_ENC_WO_xa_AttributeSelector) */

/* Render element into string. The XML attributes and elements are
 * processed in wire order by chasing wo pointers. This is what you want for
 * validating signatures on other people's XML documents. */

/* Called by: */
char* zx_ENC_WO_xa_AttributeSelector(struct zx_ctx* c, struct zx_xa_AttributeSelector_s* x, char* p )
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
  ZX_OUT_MEM(p, "AttributeSelector", sizeof("AttributeSelector")-1);
  qq = p;

  /* *** sort the namespaces */
  if (c->inc_ns)
    zx_add_inc_ns(c, &pop_seen);
  zx_add_xmlns_if_not_seen(c, x->gg.g.ns, &pop_seen);

  p = zx_enc_seen(p, pop_seen); 
  p = zx_attr_wo_enc(p, x->DataType, "DataType=\"", sizeof("DataType=\"")-1);
  p = zx_attr_wo_enc(p, x->MustBePresent, "MustBePresent=\"", sizeof("MustBePresent=\"")-1);
  p = zx_attr_wo_enc(p, x->RequestContextPath, "RequestContextPath=\"", sizeof("RequestContextPath=\"")-1);

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
  ENC_LEN_DEBUG(x, "xa:AttributeSelector", p-enc_base);
  return p;
}

/* FUNC(zx_EASY_ENC_SO_xa_AttributeSelector) */

/* Called by: */
struct zx_str* zx_EASY_ENC_SO_xa_AttributeSelector(struct zx_ctx* c, struct zx_xa_AttributeSelector_s* x )
{
  int len;
  char* buf;
  c->ns_tab = ZX_ALLOC(c, sizeof(zx_ns_tab));
  memcpy(c->ns_tab, zx_ns_tab, sizeof(zx_ns_tab));
  len = zx_LEN_SO_xa_AttributeSelector(c, x );
  buf = ZX_ALLOC(c, len+1);
  return zx_easy_enc_common(c, zx_ENC_SO_xa_AttributeSelector(c, x, buf ), buf, len);
}

/* FUNC(zx_EASY_ENC_WO_xa_AttributeSelector) */

/* Called by: */
struct zx_str* zx_EASY_ENC_WO_xa_AttributeSelector(struct zx_ctx* c, struct zx_xa_AttributeSelector_s* x )
{
  int len;
  char* buf;
  c->ns_tab = ZX_ALLOC(c, sizeof(zx_ns_tab));
  memcpy(c->ns_tab, zx_ns_tab, sizeof(zx_ns_tab));
  len = zx_LEN_WO_xa_AttributeSelector(c, x );
  buf = ZX_ALLOC(c, len+1);
  return zx_easy_enc_common(c, zx_ENC_WO_xa_AttributeSelector(c, x, buf ), buf, len);
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

#define EL_NAME   xa_AttributeValue
#define EL_STRUCT zx_xa_AttributeValue_s
#define EL_NS     xa
#define EL_TAG    AttributeValue

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

/* FUNC(zx_LEN_SO_xa_AttributeValue) */

/* Compute length of an element (and its subelements). The XML attributes
 * and elements are processed in schema order. */

/* Called by: */
int zx_LEN_SO_xa_AttributeValue(struct zx_ctx* c, struct zx_xa_AttributeValue_s* x )
{
  struct zx_ns_s* pop_seen = 0;
  struct zx_elem_s* se MAYBE_UNUSED;
#if 1 /* NORMALMODE */
  /* *** in simple_elem case should output ns prefix from ns node. */
  int len = sizeof("<xa:AttributeValue")-1 + 1 + sizeof("</xa:AttributeValue>")-1;
  if (c->inc_ns_len)
    len += zx_len_inc_ns(c, &pop_seen);
  len += zx_len_xmlns_if_not_seen(c, zx_ns_tab+zx_xmlns_ix_xa, &pop_seen);

  len += zx_attr_so_len(x->DataType, sizeof("DataType")-1);

#else
  /* root node has no begin tag */
  int len = 0;
#endif
  


  len += zx_len_so_common(c, &x->gg);
  zx_pop_seen(pop_seen);
  ENC_LEN_DEBUG(x, "xa:AttributeValue", len);
  return len;
}

/* FUNC(zx_LEN_WO_xa_AttributeValue) */

/* Compute length of an element (and its subelements). The XML attributes
 * and elements are processed in wire order and no assumptions
 * are made about namespace prefixes. */

/* Called by: */
int zx_LEN_WO_xa_AttributeValue(struct zx_ctx* c, struct zx_xa_AttributeValue_s* x )
{
  struct zx_ns_s* pop_seen = 0;
  struct zx_elem_s* se MAYBE_UNUSED;
#if 1 /* NORMALMODE */
  int len = 1 + sizeof("AttributeValue")-1 + 1 + 2 + sizeof("AttributeValue")-1 + 1;
  
  if (x->gg.g.ns && x->gg.g.ns->prefix_len)
    len += (x->gg.g.ns->prefix_len + 1) * 2;
  if (c->inc_ns_len)
    len += zx_len_inc_ns(c, &pop_seen);
  len += zx_len_xmlns_if_not_seen(c, x->gg.g.ns, &pop_seen);

  len += zx_attr_wo_len(x->DataType, sizeof("DataType")-1);

#else
  /* root node has no begin tag */
  int len = 0;
#endif
  


  len += zx_len_wo_common(c, &x->gg); 
  zx_pop_seen(pop_seen);
  ENC_LEN_DEBUG(x, "xa:AttributeValue", len);
  return len;
}

/* FUNC(zx_ENC_SO_xa_AttributeValue) */

/* Render element into string. The XML attributes and elements are
 * processed in schema order. This is what you generally want for
 * rendering new data structure to a string. The wo pointers are not used. */

/* Called by: */
char* zx_ENC_SO_xa_AttributeValue(struct zx_ctx* c, struct zx_xa_AttributeValue_s* x, char* p )
{
  struct zx_elem_s* se MAYBE_UNUSED;
  ENC_LEN_DEBUG_BASE;
#if 1 /* NORMALMODE */
  struct zx_ns_s* pop_seen = 0;
  /* *** in simple_elem case should output ns prefix from ns node. */
  ZX_OUT_TAG(p, "<xa:AttributeValue");
  if (c->inc_ns)
    p = zx_enc_inc_ns(c, p, &pop_seen);
  p = zx_enc_xmlns_if_not_seen(c, p, zx_ns_tab+zx_xmlns_ix_xa, &pop_seen);

  p = zx_attr_so_enc(p, x->DataType, " DataType=\"", sizeof(" DataType=\"")-1);

  p = zx_enc_unknown_attrs(p, x->gg.any_attr);
#else
  /* root node has no begin tag */
#endif
  

  p = zx_enc_so_unknown_elems_and_content(c, p, &x->gg);
  
#if 1 /* NORMALMODE */
  ZX_OUT_CLOSE_TAG(p, "</xa:AttributeValue>");
  zx_pop_seen(pop_seen);
#else
  /* root node has no end tag either */
#endif
  ENC_LEN_DEBUG(x, "xa:AttributeValue", p-enc_base);
  return p;
}

/* FUNC(zx_ENC_WO_xa_AttributeValue) */

/* Render element into string. The XML attributes and elements are
 * processed in wire order by chasing wo pointers. This is what you want for
 * validating signatures on other people's XML documents. */

/* Called by: */
char* zx_ENC_WO_xa_AttributeValue(struct zx_ctx* c, struct zx_xa_AttributeValue_s* x, char* p )
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
  ZX_OUT_MEM(p, "AttributeValue", sizeof("AttributeValue")-1);
  qq = p;

  /* *** sort the namespaces */
  if (c->inc_ns)
    zx_add_inc_ns(c, &pop_seen);
  zx_add_xmlns_if_not_seen(c, x->gg.g.ns, &pop_seen);

  p = zx_enc_seen(p, pop_seen); 
  p = zx_attr_wo_enc(p, x->DataType, "DataType=\"", sizeof("DataType=\"")-1);

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
  ENC_LEN_DEBUG(x, "xa:AttributeValue", p-enc_base);
  return p;
}

/* FUNC(zx_EASY_ENC_SO_xa_AttributeValue) */

/* Called by: */
struct zx_str* zx_EASY_ENC_SO_xa_AttributeValue(struct zx_ctx* c, struct zx_xa_AttributeValue_s* x )
{
  int len;
  char* buf;
  c->ns_tab = ZX_ALLOC(c, sizeof(zx_ns_tab));
  memcpy(c->ns_tab, zx_ns_tab, sizeof(zx_ns_tab));
  len = zx_LEN_SO_xa_AttributeValue(c, x );
  buf = ZX_ALLOC(c, len+1);
  return zx_easy_enc_common(c, zx_ENC_SO_xa_AttributeValue(c, x, buf ), buf, len);
}

/* FUNC(zx_EASY_ENC_WO_xa_AttributeValue) */

/* Called by: */
struct zx_str* zx_EASY_ENC_WO_xa_AttributeValue(struct zx_ctx* c, struct zx_xa_AttributeValue_s* x )
{
  int len;
  char* buf;
  c->ns_tab = ZX_ALLOC(c, sizeof(zx_ns_tab));
  memcpy(c->ns_tab, zx_ns_tab, sizeof(zx_ns_tab));
  len = zx_LEN_WO_xa_AttributeValue(c, x );
  buf = ZX_ALLOC(c, len+1);
  return zx_easy_enc_common(c, zx_ENC_WO_xa_AttributeValue(c, x, buf ), buf, len);
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

#define EL_NAME   xa_CombinerParameter
#define EL_STRUCT zx_xa_CombinerParameter_s
#define EL_NS     xa
#define EL_TAG    CombinerParameter

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

/* FUNC(zx_LEN_SO_xa_CombinerParameter) */

/* Compute length of an element (and its subelements). The XML attributes
 * and elements are processed in schema order. */

/* Called by: */
int zx_LEN_SO_xa_CombinerParameter(struct zx_ctx* c, struct zx_xa_CombinerParameter_s* x )
{
  struct zx_ns_s* pop_seen = 0;
  struct zx_elem_s* se MAYBE_UNUSED;
#if 1 /* NORMALMODE */
  /* *** in simple_elem case should output ns prefix from ns node. */
  int len = sizeof("<xa:CombinerParameter")-1 + 1 + sizeof("</xa:CombinerParameter>")-1;
  if (c->inc_ns_len)
    len += zx_len_inc_ns(c, &pop_seen);
  len += zx_len_xmlns_if_not_seen(c, zx_ns_tab+zx_xmlns_ix_xa, &pop_seen);

  len += zx_attr_so_len(x->ParameterName, sizeof("ParameterName")-1);

#else
  /* root node has no begin tag */
  int len = 0;
#endif
  
  {
      struct zx_xa_AttributeValue_s* e;
      for (e = x->AttributeValue; e; e = (struct zx_xa_AttributeValue_s*)e->gg.g.n)
	  len += zx_LEN_SO_xa_AttributeValue(c, e);
  }


  len += zx_len_so_common(c, &x->gg);
  zx_pop_seen(pop_seen);
  ENC_LEN_DEBUG(x, "xa:CombinerParameter", len);
  return len;
}

/* FUNC(zx_LEN_WO_xa_CombinerParameter) */

/* Compute length of an element (and its subelements). The XML attributes
 * and elements are processed in wire order and no assumptions
 * are made about namespace prefixes. */

/* Called by: */
int zx_LEN_WO_xa_CombinerParameter(struct zx_ctx* c, struct zx_xa_CombinerParameter_s* x )
{
  struct zx_ns_s* pop_seen = 0;
  struct zx_elem_s* se MAYBE_UNUSED;
#if 1 /* NORMALMODE */
  int len = 1 + sizeof("CombinerParameter")-1 + 1 + 2 + sizeof("CombinerParameter")-1 + 1;
  
  if (x->gg.g.ns && x->gg.g.ns->prefix_len)
    len += (x->gg.g.ns->prefix_len + 1) * 2;
  if (c->inc_ns_len)
    len += zx_len_inc_ns(c, &pop_seen);
  len += zx_len_xmlns_if_not_seen(c, x->gg.g.ns, &pop_seen);

  len += zx_attr_wo_len(x->ParameterName, sizeof("ParameterName")-1);

#else
  /* root node has no begin tag */
  int len = 0;
#endif
  
  {
      struct zx_xa_AttributeValue_s* e;
      for (e = x->AttributeValue; e; e = (struct zx_xa_AttributeValue_s*)e->gg.g.n)
	  len += zx_LEN_WO_xa_AttributeValue(c, e);
  }


  len += zx_len_wo_common(c, &x->gg); 
  zx_pop_seen(pop_seen);
  ENC_LEN_DEBUG(x, "xa:CombinerParameter", len);
  return len;
}

/* FUNC(zx_ENC_SO_xa_CombinerParameter) */

/* Render element into string. The XML attributes and elements are
 * processed in schema order. This is what you generally want for
 * rendering new data structure to a string. The wo pointers are not used. */

/* Called by: */
char* zx_ENC_SO_xa_CombinerParameter(struct zx_ctx* c, struct zx_xa_CombinerParameter_s* x, char* p )
{
  struct zx_elem_s* se MAYBE_UNUSED;
  ENC_LEN_DEBUG_BASE;
#if 1 /* NORMALMODE */
  struct zx_ns_s* pop_seen = 0;
  /* *** in simple_elem case should output ns prefix from ns node. */
  ZX_OUT_TAG(p, "<xa:CombinerParameter");
  if (c->inc_ns)
    p = zx_enc_inc_ns(c, p, &pop_seen);
  p = zx_enc_xmlns_if_not_seen(c, p, zx_ns_tab+zx_xmlns_ix_xa, &pop_seen);

  p = zx_attr_so_enc(p, x->ParameterName, " ParameterName=\"", sizeof(" ParameterName=\"")-1);

  p = zx_enc_unknown_attrs(p, x->gg.any_attr);
#else
  /* root node has no begin tag */
#endif
  
  {
      struct zx_xa_AttributeValue_s* e;
      for (e = x->AttributeValue; e; e = (struct zx_xa_AttributeValue_s*)e->gg.g.n)
	  p = zx_ENC_SO_xa_AttributeValue(c, e, p);
  }

  p = zx_enc_so_unknown_elems_and_content(c, p, &x->gg);
  
#if 1 /* NORMALMODE */
  ZX_OUT_CLOSE_TAG(p, "</xa:CombinerParameter>");
  zx_pop_seen(pop_seen);
#else
  /* root node has no end tag either */
#endif
  ENC_LEN_DEBUG(x, "xa:CombinerParameter", p-enc_base);
  return p;
}

/* FUNC(zx_ENC_WO_xa_CombinerParameter) */

/* Render element into string. The XML attributes and elements are
 * processed in wire order by chasing wo pointers. This is what you want for
 * validating signatures on other people's XML documents. */

/* Called by: */
char* zx_ENC_WO_xa_CombinerParameter(struct zx_ctx* c, struct zx_xa_CombinerParameter_s* x, char* p )
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
  ZX_OUT_MEM(p, "CombinerParameter", sizeof("CombinerParameter")-1);
  qq = p;

  /* *** sort the namespaces */
  if (c->inc_ns)
    zx_add_inc_ns(c, &pop_seen);
  zx_add_xmlns_if_not_seen(c, x->gg.g.ns, &pop_seen);

  p = zx_enc_seen(p, pop_seen); 
  p = zx_attr_wo_enc(p, x->ParameterName, "ParameterName=\"", sizeof("ParameterName=\"")-1);

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
  ENC_LEN_DEBUG(x, "xa:CombinerParameter", p-enc_base);
  return p;
}

/* FUNC(zx_EASY_ENC_SO_xa_CombinerParameter) */

/* Called by: */
struct zx_str* zx_EASY_ENC_SO_xa_CombinerParameter(struct zx_ctx* c, struct zx_xa_CombinerParameter_s* x )
{
  int len;
  char* buf;
  c->ns_tab = ZX_ALLOC(c, sizeof(zx_ns_tab));
  memcpy(c->ns_tab, zx_ns_tab, sizeof(zx_ns_tab));
  len = zx_LEN_SO_xa_CombinerParameter(c, x );
  buf = ZX_ALLOC(c, len+1);
  return zx_easy_enc_common(c, zx_ENC_SO_xa_CombinerParameter(c, x, buf ), buf, len);
}

/* FUNC(zx_EASY_ENC_WO_xa_CombinerParameter) */

/* Called by: */
struct zx_str* zx_EASY_ENC_WO_xa_CombinerParameter(struct zx_ctx* c, struct zx_xa_CombinerParameter_s* x )
{
  int len;
  char* buf;
  c->ns_tab = ZX_ALLOC(c, sizeof(zx_ns_tab));
  memcpy(c->ns_tab, zx_ns_tab, sizeof(zx_ns_tab));
  len = zx_LEN_WO_xa_CombinerParameter(c, x );
  buf = ZX_ALLOC(c, len+1);
  return zx_easy_enc_common(c, zx_ENC_WO_xa_CombinerParameter(c, x, buf ), buf, len);
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

#define EL_NAME   xa_CombinerParameters
#define EL_STRUCT zx_xa_CombinerParameters_s
#define EL_NS     xa
#define EL_TAG    CombinerParameters

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

/* FUNC(zx_LEN_SO_xa_CombinerParameters) */

/* Compute length of an element (and its subelements). The XML attributes
 * and elements are processed in schema order. */

/* Called by: */
int zx_LEN_SO_xa_CombinerParameters(struct zx_ctx* c, struct zx_xa_CombinerParameters_s* x )
{
  struct zx_ns_s* pop_seen = 0;
  struct zx_elem_s* se MAYBE_UNUSED;
#if 1 /* NORMALMODE */
  /* *** in simple_elem case should output ns prefix from ns node. */
  int len = sizeof("<xa:CombinerParameters")-1 + 1 + sizeof("</xa:CombinerParameters>")-1;
  if (c->inc_ns_len)
    len += zx_len_inc_ns(c, &pop_seen);
  len += zx_len_xmlns_if_not_seen(c, zx_ns_tab+zx_xmlns_ix_xa, &pop_seen);


#else
  /* root node has no begin tag */
  int len = 0;
#endif
  
  {
      struct zx_xa_CombinerParameter_s* e;
      for (e = x->CombinerParameter; e; e = (struct zx_xa_CombinerParameter_s*)e->gg.g.n)
	  len += zx_LEN_SO_xa_CombinerParameter(c, e);
  }


  len += zx_len_so_common(c, &x->gg);
  zx_pop_seen(pop_seen);
  ENC_LEN_DEBUG(x, "xa:CombinerParameters", len);
  return len;
}

/* FUNC(zx_LEN_WO_xa_CombinerParameters) */

/* Compute length of an element (and its subelements). The XML attributes
 * and elements are processed in wire order and no assumptions
 * are made about namespace prefixes. */

/* Called by: */
int zx_LEN_WO_xa_CombinerParameters(struct zx_ctx* c, struct zx_xa_CombinerParameters_s* x )
{
  struct zx_ns_s* pop_seen = 0;
  struct zx_elem_s* se MAYBE_UNUSED;
#if 1 /* NORMALMODE */
  int len = 1 + sizeof("CombinerParameters")-1 + 1 + 2 + sizeof("CombinerParameters")-1 + 1;
  
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
      struct zx_xa_CombinerParameter_s* e;
      for (e = x->CombinerParameter; e; e = (struct zx_xa_CombinerParameter_s*)e->gg.g.n)
	  len += zx_LEN_WO_xa_CombinerParameter(c, e);
  }


  len += zx_len_wo_common(c, &x->gg); 
  zx_pop_seen(pop_seen);
  ENC_LEN_DEBUG(x, "xa:CombinerParameters", len);
  return len;
}

/* FUNC(zx_ENC_SO_xa_CombinerParameters) */

/* Render element into string. The XML attributes and elements are
 * processed in schema order. This is what you generally want for
 * rendering new data structure to a string. The wo pointers are not used. */

/* Called by: */
char* zx_ENC_SO_xa_CombinerParameters(struct zx_ctx* c, struct zx_xa_CombinerParameters_s* x, char* p )
{
  struct zx_elem_s* se MAYBE_UNUSED;
  ENC_LEN_DEBUG_BASE;
#if 1 /* NORMALMODE */
  struct zx_ns_s* pop_seen = 0;
  /* *** in simple_elem case should output ns prefix from ns node. */
  ZX_OUT_TAG(p, "<xa:CombinerParameters");
  if (c->inc_ns)
    p = zx_enc_inc_ns(c, p, &pop_seen);
  p = zx_enc_xmlns_if_not_seen(c, p, zx_ns_tab+zx_xmlns_ix_xa, &pop_seen);


  p = zx_enc_unknown_attrs(p, x->gg.any_attr);
#else
  /* root node has no begin tag */
#endif
  
  {
      struct zx_xa_CombinerParameter_s* e;
      for (e = x->CombinerParameter; e; e = (struct zx_xa_CombinerParameter_s*)e->gg.g.n)
	  p = zx_ENC_SO_xa_CombinerParameter(c, e, p);
  }

  p = zx_enc_so_unknown_elems_and_content(c, p, &x->gg);
  
#if 1 /* NORMALMODE */
  ZX_OUT_CLOSE_TAG(p, "</xa:CombinerParameters>");
  zx_pop_seen(pop_seen);
#else
  /* root node has no end tag either */
#endif
  ENC_LEN_DEBUG(x, "xa:CombinerParameters", p-enc_base);
  return p;
}

/* FUNC(zx_ENC_WO_xa_CombinerParameters) */

/* Render element into string. The XML attributes and elements are
 * processed in wire order by chasing wo pointers. This is what you want for
 * validating signatures on other people's XML documents. */

/* Called by: */
char* zx_ENC_WO_xa_CombinerParameters(struct zx_ctx* c, struct zx_xa_CombinerParameters_s* x, char* p )
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
  ZX_OUT_MEM(p, "CombinerParameters", sizeof("CombinerParameters")-1);
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
  ENC_LEN_DEBUG(x, "xa:CombinerParameters", p-enc_base);
  return p;
}

/* FUNC(zx_EASY_ENC_SO_xa_CombinerParameters) */

/* Called by: */
struct zx_str* zx_EASY_ENC_SO_xa_CombinerParameters(struct zx_ctx* c, struct zx_xa_CombinerParameters_s* x )
{
  int len;
  char* buf;
  c->ns_tab = ZX_ALLOC(c, sizeof(zx_ns_tab));
  memcpy(c->ns_tab, zx_ns_tab, sizeof(zx_ns_tab));
  len = zx_LEN_SO_xa_CombinerParameters(c, x );
  buf = ZX_ALLOC(c, len+1);
  return zx_easy_enc_common(c, zx_ENC_SO_xa_CombinerParameters(c, x, buf ), buf, len);
}

/* FUNC(zx_EASY_ENC_WO_xa_CombinerParameters) */

/* Called by: */
struct zx_str* zx_EASY_ENC_WO_xa_CombinerParameters(struct zx_ctx* c, struct zx_xa_CombinerParameters_s* x )
{
  int len;
  char* buf;
  c->ns_tab = ZX_ALLOC(c, sizeof(zx_ns_tab));
  memcpy(c->ns_tab, zx_ns_tab, sizeof(zx_ns_tab));
  len = zx_LEN_WO_xa_CombinerParameters(c, x );
  buf = ZX_ALLOC(c, len+1);
  return zx_easy_enc_common(c, zx_ENC_WO_xa_CombinerParameters(c, x, buf ), buf, len);
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

#define EL_NAME   xa_Condition
#define EL_STRUCT zx_xa_Condition_s
#define EL_NS     xa
#define EL_TAG    Condition

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

/* FUNC(zx_LEN_SO_xa_Condition) */

/* Compute length of an element (and its subelements). The XML attributes
 * and elements are processed in schema order. */

/* Called by: */
int zx_LEN_SO_xa_Condition(struct zx_ctx* c, struct zx_xa_Condition_s* x )
{
  struct zx_ns_s* pop_seen = 0;
  struct zx_elem_s* se MAYBE_UNUSED;
#if 1 /* NORMALMODE */
  /* *** in simple_elem case should output ns prefix from ns node. */
  int len = sizeof("<xa:Condition")-1 + 1 + sizeof("</xa:Condition>")-1;
  if (c->inc_ns_len)
    len += zx_len_inc_ns(c, &pop_seen);
  len += zx_len_xmlns_if_not_seen(c, zx_ns_tab+zx_xmlns_ix_xa, &pop_seen);


#else
  /* root node has no begin tag */
  int len = 0;
#endif
  
  for (se = x->Expression; se; se = (struct zx_elem_s*)se->g.n)
    len += zx_LEN_SO_simple_elem(c,se, sizeof("xa:Expression")-1, zx_ns_tab+zx_xmlns_ix_xa);


  len += zx_len_so_common(c, &x->gg);
  zx_pop_seen(pop_seen);
  ENC_LEN_DEBUG(x, "xa:Condition", len);
  return len;
}

/* FUNC(zx_LEN_WO_xa_Condition) */

/* Compute length of an element (and its subelements). The XML attributes
 * and elements are processed in wire order and no assumptions
 * are made about namespace prefixes. */

/* Called by: */
int zx_LEN_WO_xa_Condition(struct zx_ctx* c, struct zx_xa_Condition_s* x )
{
  struct zx_ns_s* pop_seen = 0;
  struct zx_elem_s* se MAYBE_UNUSED;
#if 1 /* NORMALMODE */
  int len = 1 + sizeof("Condition")-1 + 1 + 2 + sizeof("Condition")-1 + 1;
  
  if (x->gg.g.ns && x->gg.g.ns->prefix_len)
    len += (x->gg.g.ns->prefix_len + 1) * 2;
  if (c->inc_ns_len)
    len += zx_len_inc_ns(c, &pop_seen);
  len += zx_len_xmlns_if_not_seen(c, x->gg.g.ns, &pop_seen);


#else
  /* root node has no begin tag */
  int len = 0;
#endif
  
  for (se = x->Expression; se; se = (struct zx_elem_s*)se->g.n)
    len += zx_LEN_WO_simple_elem(c, se, sizeof("Expression")-1);


  len += zx_len_wo_common(c, &x->gg); 
  zx_pop_seen(pop_seen);
  ENC_LEN_DEBUG(x, "xa:Condition", len);
  return len;
}

/* FUNC(zx_ENC_SO_xa_Condition) */

/* Render element into string. The XML attributes and elements are
 * processed in schema order. This is what you generally want for
 * rendering new data structure to a string. The wo pointers are not used. */

/* Called by: */
char* zx_ENC_SO_xa_Condition(struct zx_ctx* c, struct zx_xa_Condition_s* x, char* p )
{
  struct zx_elem_s* se MAYBE_UNUSED;
  ENC_LEN_DEBUG_BASE;
#if 1 /* NORMALMODE */
  struct zx_ns_s* pop_seen = 0;
  /* *** in simple_elem case should output ns prefix from ns node. */
  ZX_OUT_TAG(p, "<xa:Condition");
  if (c->inc_ns)
    p = zx_enc_inc_ns(c, p, &pop_seen);
  p = zx_enc_xmlns_if_not_seen(c, p, zx_ns_tab+zx_xmlns_ix_xa, &pop_seen);


  p = zx_enc_unknown_attrs(p, x->gg.any_attr);
#else
  /* root node has no begin tag */
#endif
  
  for (se = x->Expression; se; se = (struct zx_elem_s*)se->g.n)
    p = zx_ENC_SO_simple_elem(c, se, p, "xa:Expression", sizeof("xa:Expression")-1, zx_ns_tab+zx_xmlns_ix_xa);

  p = zx_enc_so_unknown_elems_and_content(c, p, &x->gg);
  
#if 1 /* NORMALMODE */
  ZX_OUT_CLOSE_TAG(p, "</xa:Condition>");
  zx_pop_seen(pop_seen);
#else
  /* root node has no end tag either */
#endif
  ENC_LEN_DEBUG(x, "xa:Condition", p-enc_base);
  return p;
}

/* FUNC(zx_ENC_WO_xa_Condition) */

/* Render element into string. The XML attributes and elements are
 * processed in wire order by chasing wo pointers. This is what you want for
 * validating signatures on other people's XML documents. */

/* Called by: */
char* zx_ENC_WO_xa_Condition(struct zx_ctx* c, struct zx_xa_Condition_s* x, char* p )
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
  ZX_OUT_MEM(p, "Condition", sizeof("Condition")-1);
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
  ENC_LEN_DEBUG(x, "xa:Condition", p-enc_base);
  return p;
}

/* FUNC(zx_EASY_ENC_SO_xa_Condition) */

/* Called by: */
struct zx_str* zx_EASY_ENC_SO_xa_Condition(struct zx_ctx* c, struct zx_xa_Condition_s* x )
{
  int len;
  char* buf;
  c->ns_tab = ZX_ALLOC(c, sizeof(zx_ns_tab));
  memcpy(c->ns_tab, zx_ns_tab, sizeof(zx_ns_tab));
  len = zx_LEN_SO_xa_Condition(c, x );
  buf = ZX_ALLOC(c, len+1);
  return zx_easy_enc_common(c, zx_ENC_SO_xa_Condition(c, x, buf ), buf, len);
}

/* FUNC(zx_EASY_ENC_WO_xa_Condition) */

/* Called by: */
struct zx_str* zx_EASY_ENC_WO_xa_Condition(struct zx_ctx* c, struct zx_xa_Condition_s* x )
{
  int len;
  char* buf;
  c->ns_tab = ZX_ALLOC(c, sizeof(zx_ns_tab));
  memcpy(c->ns_tab, zx_ns_tab, sizeof(zx_ns_tab));
  len = zx_LEN_WO_xa_Condition(c, x );
  buf = ZX_ALLOC(c, len+1);
  return zx_easy_enc_common(c, zx_ENC_WO_xa_Condition(c, x, buf ), buf, len);
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

#define EL_NAME   xa_Environment
#define EL_STRUCT zx_xa_Environment_s
#define EL_NS     xa
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

/* FUNC(zx_LEN_SO_xa_Environment) */

/* Compute length of an element (and its subelements). The XML attributes
 * and elements are processed in schema order. */

/* Called by: */
int zx_LEN_SO_xa_Environment(struct zx_ctx* c, struct zx_xa_Environment_s* x )
{
  struct zx_ns_s* pop_seen = 0;
  struct zx_elem_s* se MAYBE_UNUSED;
#if 1 /* NORMALMODE */
  /* *** in simple_elem case should output ns prefix from ns node. */
  int len = sizeof("<xa:Environment")-1 + 1 + sizeof("</xa:Environment>")-1;
  if (c->inc_ns_len)
    len += zx_len_inc_ns(c, &pop_seen);
  len += zx_len_xmlns_if_not_seen(c, zx_ns_tab+zx_xmlns_ix_xa, &pop_seen);


#else
  /* root node has no begin tag */
  int len = 0;
#endif
  
  {
      struct zx_xa_EnvironmentMatch_s* e;
      for (e = x->EnvironmentMatch; e; e = (struct zx_xa_EnvironmentMatch_s*)e->gg.g.n)
	  len += zx_LEN_SO_xa_EnvironmentMatch(c, e);
  }


  len += zx_len_so_common(c, &x->gg);
  zx_pop_seen(pop_seen);
  ENC_LEN_DEBUG(x, "xa:Environment", len);
  return len;
}

/* FUNC(zx_LEN_WO_xa_Environment) */

/* Compute length of an element (and its subelements). The XML attributes
 * and elements are processed in wire order and no assumptions
 * are made about namespace prefixes. */

/* Called by: */
int zx_LEN_WO_xa_Environment(struct zx_ctx* c, struct zx_xa_Environment_s* x )
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
      struct zx_xa_EnvironmentMatch_s* e;
      for (e = x->EnvironmentMatch; e; e = (struct zx_xa_EnvironmentMatch_s*)e->gg.g.n)
	  len += zx_LEN_WO_xa_EnvironmentMatch(c, e);
  }


  len += zx_len_wo_common(c, &x->gg); 
  zx_pop_seen(pop_seen);
  ENC_LEN_DEBUG(x, "xa:Environment", len);
  return len;
}

/* FUNC(zx_ENC_SO_xa_Environment) */

/* Render element into string. The XML attributes and elements are
 * processed in schema order. This is what you generally want for
 * rendering new data structure to a string. The wo pointers are not used. */

/* Called by: */
char* zx_ENC_SO_xa_Environment(struct zx_ctx* c, struct zx_xa_Environment_s* x, char* p )
{
  struct zx_elem_s* se MAYBE_UNUSED;
  ENC_LEN_DEBUG_BASE;
#if 1 /* NORMALMODE */
  struct zx_ns_s* pop_seen = 0;
  /* *** in simple_elem case should output ns prefix from ns node. */
  ZX_OUT_TAG(p, "<xa:Environment");
  if (c->inc_ns)
    p = zx_enc_inc_ns(c, p, &pop_seen);
  p = zx_enc_xmlns_if_not_seen(c, p, zx_ns_tab+zx_xmlns_ix_xa, &pop_seen);


  p = zx_enc_unknown_attrs(p, x->gg.any_attr);
#else
  /* root node has no begin tag */
#endif
  
  {
      struct zx_xa_EnvironmentMatch_s* e;
      for (e = x->EnvironmentMatch; e; e = (struct zx_xa_EnvironmentMatch_s*)e->gg.g.n)
	  p = zx_ENC_SO_xa_EnvironmentMatch(c, e, p);
  }

  p = zx_enc_so_unknown_elems_and_content(c, p, &x->gg);
  
#if 1 /* NORMALMODE */
  ZX_OUT_CLOSE_TAG(p, "</xa:Environment>");
  zx_pop_seen(pop_seen);
#else
  /* root node has no end tag either */
#endif
  ENC_LEN_DEBUG(x, "xa:Environment", p-enc_base);
  return p;
}

/* FUNC(zx_ENC_WO_xa_Environment) */

/* Render element into string. The XML attributes and elements are
 * processed in wire order by chasing wo pointers. This is what you want for
 * validating signatures on other people's XML documents. */

/* Called by: */
char* zx_ENC_WO_xa_Environment(struct zx_ctx* c, struct zx_xa_Environment_s* x, char* p )
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
  ZX_OUT_MEM(p, "Environment", sizeof("Environment")-1);
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
  ENC_LEN_DEBUG(x, "xa:Environment", p-enc_base);
  return p;
}

/* FUNC(zx_EASY_ENC_SO_xa_Environment) */

/* Called by: */
struct zx_str* zx_EASY_ENC_SO_xa_Environment(struct zx_ctx* c, struct zx_xa_Environment_s* x )
{
  int len;
  char* buf;
  c->ns_tab = ZX_ALLOC(c, sizeof(zx_ns_tab));
  memcpy(c->ns_tab, zx_ns_tab, sizeof(zx_ns_tab));
  len = zx_LEN_SO_xa_Environment(c, x );
  buf = ZX_ALLOC(c, len+1);
  return zx_easy_enc_common(c, zx_ENC_SO_xa_Environment(c, x, buf ), buf, len);
}

/* FUNC(zx_EASY_ENC_WO_xa_Environment) */

/* Called by: */
struct zx_str* zx_EASY_ENC_WO_xa_Environment(struct zx_ctx* c, struct zx_xa_Environment_s* x )
{
  int len;
  char* buf;
  c->ns_tab = ZX_ALLOC(c, sizeof(zx_ns_tab));
  memcpy(c->ns_tab, zx_ns_tab, sizeof(zx_ns_tab));
  len = zx_LEN_WO_xa_Environment(c, x );
  buf = ZX_ALLOC(c, len+1);
  return zx_easy_enc_common(c, zx_ENC_WO_xa_Environment(c, x, buf ), buf, len);
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

#define EL_NAME   xa_EnvironmentAttributeDesignator
#define EL_STRUCT zx_xa_EnvironmentAttributeDesignator_s
#define EL_NS     xa
#define EL_TAG    EnvironmentAttributeDesignator

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

/* FUNC(zx_LEN_SO_xa_EnvironmentAttributeDesignator) */

/* Compute length of an element (and its subelements). The XML attributes
 * and elements are processed in schema order. */

/* Called by: */
int zx_LEN_SO_xa_EnvironmentAttributeDesignator(struct zx_ctx* c, struct zx_xa_EnvironmentAttributeDesignator_s* x )
{
  struct zx_ns_s* pop_seen = 0;
  struct zx_elem_s* se MAYBE_UNUSED;
#if 1 /* NORMALMODE */
  /* *** in simple_elem case should output ns prefix from ns node. */
  int len = sizeof("<xa:EnvironmentAttributeDesignator")-1 + 1 + sizeof("</xa:EnvironmentAttributeDesignator>")-1;
  if (c->inc_ns_len)
    len += zx_len_inc_ns(c, &pop_seen);
  len += zx_len_xmlns_if_not_seen(c, zx_ns_tab+zx_xmlns_ix_xa, &pop_seen);

  len += zx_attr_so_len(x->AttributeId, sizeof("AttributeId")-1);
  len += zx_attr_so_len(x->DataType, sizeof("DataType")-1);
  len += zx_attr_so_len(x->Issuer, sizeof("Issuer")-1);
  len += zx_attr_so_len(x->MustBePresent, sizeof("MustBePresent")-1);

#else
  /* root node has no begin tag */
  int len = 0;
#endif
  


  len += zx_len_so_common(c, &x->gg);
  zx_pop_seen(pop_seen);
  ENC_LEN_DEBUG(x, "xa:EnvironmentAttributeDesignator", len);
  return len;
}

/* FUNC(zx_LEN_WO_xa_EnvironmentAttributeDesignator) */

/* Compute length of an element (and its subelements). The XML attributes
 * and elements are processed in wire order and no assumptions
 * are made about namespace prefixes. */

/* Called by: */
int zx_LEN_WO_xa_EnvironmentAttributeDesignator(struct zx_ctx* c, struct zx_xa_EnvironmentAttributeDesignator_s* x )
{
  struct zx_ns_s* pop_seen = 0;
  struct zx_elem_s* se MAYBE_UNUSED;
#if 1 /* NORMALMODE */
  int len = 1 + sizeof("EnvironmentAttributeDesignator")-1 + 1 + 2 + sizeof("EnvironmentAttributeDesignator")-1 + 1;
  
  if (x->gg.g.ns && x->gg.g.ns->prefix_len)
    len += (x->gg.g.ns->prefix_len + 1) * 2;
  if (c->inc_ns_len)
    len += zx_len_inc_ns(c, &pop_seen);
  len += zx_len_xmlns_if_not_seen(c, x->gg.g.ns, &pop_seen);

  len += zx_attr_wo_len(x->AttributeId, sizeof("AttributeId")-1);
  len += zx_attr_wo_len(x->DataType, sizeof("DataType")-1);
  len += zx_attr_wo_len(x->Issuer, sizeof("Issuer")-1);
  len += zx_attr_wo_len(x->MustBePresent, sizeof("MustBePresent")-1);

#else
  /* root node has no begin tag */
  int len = 0;
#endif
  


  len += zx_len_wo_common(c, &x->gg); 
  zx_pop_seen(pop_seen);
  ENC_LEN_DEBUG(x, "xa:EnvironmentAttributeDesignator", len);
  return len;
}

/* FUNC(zx_ENC_SO_xa_EnvironmentAttributeDesignator) */

/* Render element into string. The XML attributes and elements are
 * processed in schema order. This is what you generally want for
 * rendering new data structure to a string. The wo pointers are not used. */

/* Called by: */
char* zx_ENC_SO_xa_EnvironmentAttributeDesignator(struct zx_ctx* c, struct zx_xa_EnvironmentAttributeDesignator_s* x, char* p )
{
  struct zx_elem_s* se MAYBE_UNUSED;
  ENC_LEN_DEBUG_BASE;
#if 1 /* NORMALMODE */
  struct zx_ns_s* pop_seen = 0;
  /* *** in simple_elem case should output ns prefix from ns node. */
  ZX_OUT_TAG(p, "<xa:EnvironmentAttributeDesignator");
  if (c->inc_ns)
    p = zx_enc_inc_ns(c, p, &pop_seen);
  p = zx_enc_xmlns_if_not_seen(c, p, zx_ns_tab+zx_xmlns_ix_xa, &pop_seen);

  p = zx_attr_so_enc(p, x->AttributeId, " AttributeId=\"", sizeof(" AttributeId=\"")-1);
  p = zx_attr_so_enc(p, x->DataType, " DataType=\"", sizeof(" DataType=\"")-1);
  p = zx_attr_so_enc(p, x->Issuer, " Issuer=\"", sizeof(" Issuer=\"")-1);
  p = zx_attr_so_enc(p, x->MustBePresent, " MustBePresent=\"", sizeof(" MustBePresent=\"")-1);

  p = zx_enc_unknown_attrs(p, x->gg.any_attr);
#else
  /* root node has no begin tag */
#endif
  

  p = zx_enc_so_unknown_elems_and_content(c, p, &x->gg);
  
#if 1 /* NORMALMODE */
  ZX_OUT_CLOSE_TAG(p, "</xa:EnvironmentAttributeDesignator>");
  zx_pop_seen(pop_seen);
#else
  /* root node has no end tag either */
#endif
  ENC_LEN_DEBUG(x, "xa:EnvironmentAttributeDesignator", p-enc_base);
  return p;
}

/* FUNC(zx_ENC_WO_xa_EnvironmentAttributeDesignator) */

/* Render element into string. The XML attributes and elements are
 * processed in wire order by chasing wo pointers. This is what you want for
 * validating signatures on other people's XML documents. */

/* Called by: */
char* zx_ENC_WO_xa_EnvironmentAttributeDesignator(struct zx_ctx* c, struct zx_xa_EnvironmentAttributeDesignator_s* x, char* p )
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
  ZX_OUT_MEM(p, "EnvironmentAttributeDesignator", sizeof("EnvironmentAttributeDesignator")-1);
  qq = p;

  /* *** sort the namespaces */
  if (c->inc_ns)
    zx_add_inc_ns(c, &pop_seen);
  zx_add_xmlns_if_not_seen(c, x->gg.g.ns, &pop_seen);

  p = zx_enc_seen(p, pop_seen); 
  p = zx_attr_wo_enc(p, x->AttributeId, "AttributeId=\"", sizeof("AttributeId=\"")-1);
  p = zx_attr_wo_enc(p, x->DataType, "DataType=\"", sizeof("DataType=\"")-1);
  p = zx_attr_wo_enc(p, x->Issuer, "Issuer=\"", sizeof("Issuer=\"")-1);
  p = zx_attr_wo_enc(p, x->MustBePresent, "MustBePresent=\"", sizeof("MustBePresent=\"")-1);

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
  ENC_LEN_DEBUG(x, "xa:EnvironmentAttributeDesignator", p-enc_base);
  return p;
}

/* FUNC(zx_EASY_ENC_SO_xa_EnvironmentAttributeDesignator) */

/* Called by: */
struct zx_str* zx_EASY_ENC_SO_xa_EnvironmentAttributeDesignator(struct zx_ctx* c, struct zx_xa_EnvironmentAttributeDesignator_s* x )
{
  int len;
  char* buf;
  c->ns_tab = ZX_ALLOC(c, sizeof(zx_ns_tab));
  memcpy(c->ns_tab, zx_ns_tab, sizeof(zx_ns_tab));
  len = zx_LEN_SO_xa_EnvironmentAttributeDesignator(c, x );
  buf = ZX_ALLOC(c, len+1);
  return zx_easy_enc_common(c, zx_ENC_SO_xa_EnvironmentAttributeDesignator(c, x, buf ), buf, len);
}

/* FUNC(zx_EASY_ENC_WO_xa_EnvironmentAttributeDesignator) */

/* Called by: */
struct zx_str* zx_EASY_ENC_WO_xa_EnvironmentAttributeDesignator(struct zx_ctx* c, struct zx_xa_EnvironmentAttributeDesignator_s* x )
{
  int len;
  char* buf;
  c->ns_tab = ZX_ALLOC(c, sizeof(zx_ns_tab));
  memcpy(c->ns_tab, zx_ns_tab, sizeof(zx_ns_tab));
  len = zx_LEN_WO_xa_EnvironmentAttributeDesignator(c, x );
  buf = ZX_ALLOC(c, len+1);
  return zx_easy_enc_common(c, zx_ENC_WO_xa_EnvironmentAttributeDesignator(c, x, buf ), buf, len);
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

#define EL_NAME   xa_EnvironmentMatch
#define EL_STRUCT zx_xa_EnvironmentMatch_s
#define EL_NS     xa
#define EL_TAG    EnvironmentMatch

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

/* FUNC(zx_LEN_SO_xa_EnvironmentMatch) */

/* Compute length of an element (and its subelements). The XML attributes
 * and elements are processed in schema order. */

/* Called by: */
int zx_LEN_SO_xa_EnvironmentMatch(struct zx_ctx* c, struct zx_xa_EnvironmentMatch_s* x )
{
  struct zx_ns_s* pop_seen = 0;
  struct zx_elem_s* se MAYBE_UNUSED;
#if 1 /* NORMALMODE */
  /* *** in simple_elem case should output ns prefix from ns node. */
  int len = sizeof("<xa:EnvironmentMatch")-1 + 1 + sizeof("</xa:EnvironmentMatch>")-1;
  if (c->inc_ns_len)
    len += zx_len_inc_ns(c, &pop_seen);
  len += zx_len_xmlns_if_not_seen(c, zx_ns_tab+zx_xmlns_ix_xa, &pop_seen);

  len += zx_attr_so_len(x->MatchId, sizeof("MatchId")-1);

#else
  /* root node has no begin tag */
  int len = 0;
#endif
  
  {
      struct zx_xa_AttributeValue_s* e;
      for (e = x->AttributeValue; e; e = (struct zx_xa_AttributeValue_s*)e->gg.g.n)
	  len += zx_LEN_SO_xa_AttributeValue(c, e);
  }
  {
      struct zx_xa_EnvironmentAttributeDesignator_s* e;
      for (e = x->EnvironmentAttributeDesignator; e; e = (struct zx_xa_EnvironmentAttributeDesignator_s*)e->gg.g.n)
	  len += zx_LEN_SO_xa_EnvironmentAttributeDesignator(c, e);
  }
  {
      struct zx_xa_AttributeSelector_s* e;
      for (e = x->AttributeSelector; e; e = (struct zx_xa_AttributeSelector_s*)e->gg.g.n)
	  len += zx_LEN_SO_xa_AttributeSelector(c, e);
  }


  len += zx_len_so_common(c, &x->gg);
  zx_pop_seen(pop_seen);
  ENC_LEN_DEBUG(x, "xa:EnvironmentMatch", len);
  return len;
}

/* FUNC(zx_LEN_WO_xa_EnvironmentMatch) */

/* Compute length of an element (and its subelements). The XML attributes
 * and elements are processed in wire order and no assumptions
 * are made about namespace prefixes. */

/* Called by: */
int zx_LEN_WO_xa_EnvironmentMatch(struct zx_ctx* c, struct zx_xa_EnvironmentMatch_s* x )
{
  struct zx_ns_s* pop_seen = 0;
  struct zx_elem_s* se MAYBE_UNUSED;
#if 1 /* NORMALMODE */
  int len = 1 + sizeof("EnvironmentMatch")-1 + 1 + 2 + sizeof("EnvironmentMatch")-1 + 1;
  
  if (x->gg.g.ns && x->gg.g.ns->prefix_len)
    len += (x->gg.g.ns->prefix_len + 1) * 2;
  if (c->inc_ns_len)
    len += zx_len_inc_ns(c, &pop_seen);
  len += zx_len_xmlns_if_not_seen(c, x->gg.g.ns, &pop_seen);

  len += zx_attr_wo_len(x->MatchId, sizeof("MatchId")-1);

#else
  /* root node has no begin tag */
  int len = 0;
#endif
  
  {
      struct zx_xa_AttributeValue_s* e;
      for (e = x->AttributeValue; e; e = (struct zx_xa_AttributeValue_s*)e->gg.g.n)
	  len += zx_LEN_WO_xa_AttributeValue(c, e);
  }
  {
      struct zx_xa_EnvironmentAttributeDesignator_s* e;
      for (e = x->EnvironmentAttributeDesignator; e; e = (struct zx_xa_EnvironmentAttributeDesignator_s*)e->gg.g.n)
	  len += zx_LEN_WO_xa_EnvironmentAttributeDesignator(c, e);
  }
  {
      struct zx_xa_AttributeSelector_s* e;
      for (e = x->AttributeSelector; e; e = (struct zx_xa_AttributeSelector_s*)e->gg.g.n)
	  len += zx_LEN_WO_xa_AttributeSelector(c, e);
  }


  len += zx_len_wo_common(c, &x->gg); 
  zx_pop_seen(pop_seen);
  ENC_LEN_DEBUG(x, "xa:EnvironmentMatch", len);
  return len;
}

/* FUNC(zx_ENC_SO_xa_EnvironmentMatch) */

/* Render element into string. The XML attributes and elements are
 * processed in schema order. This is what you generally want for
 * rendering new data structure to a string. The wo pointers are not used. */

/* Called by: */
char* zx_ENC_SO_xa_EnvironmentMatch(struct zx_ctx* c, struct zx_xa_EnvironmentMatch_s* x, char* p )
{
  struct zx_elem_s* se MAYBE_UNUSED;
  ENC_LEN_DEBUG_BASE;
#if 1 /* NORMALMODE */
  struct zx_ns_s* pop_seen = 0;
  /* *** in simple_elem case should output ns prefix from ns node. */
  ZX_OUT_TAG(p, "<xa:EnvironmentMatch");
  if (c->inc_ns)
    p = zx_enc_inc_ns(c, p, &pop_seen);
  p = zx_enc_xmlns_if_not_seen(c, p, zx_ns_tab+zx_xmlns_ix_xa, &pop_seen);

  p = zx_attr_so_enc(p, x->MatchId, " MatchId=\"", sizeof(" MatchId=\"")-1);

  p = zx_enc_unknown_attrs(p, x->gg.any_attr);
#else
  /* root node has no begin tag */
#endif
  
  {
      struct zx_xa_AttributeValue_s* e;
      for (e = x->AttributeValue; e; e = (struct zx_xa_AttributeValue_s*)e->gg.g.n)
	  p = zx_ENC_SO_xa_AttributeValue(c, e, p);
  }
  {
      struct zx_xa_EnvironmentAttributeDesignator_s* e;
      for (e = x->EnvironmentAttributeDesignator; e; e = (struct zx_xa_EnvironmentAttributeDesignator_s*)e->gg.g.n)
	  p = zx_ENC_SO_xa_EnvironmentAttributeDesignator(c, e, p);
  }
  {
      struct zx_xa_AttributeSelector_s* e;
      for (e = x->AttributeSelector; e; e = (struct zx_xa_AttributeSelector_s*)e->gg.g.n)
	  p = zx_ENC_SO_xa_AttributeSelector(c, e, p);
  }

  p = zx_enc_so_unknown_elems_and_content(c, p, &x->gg);
  
#if 1 /* NORMALMODE */
  ZX_OUT_CLOSE_TAG(p, "</xa:EnvironmentMatch>");
  zx_pop_seen(pop_seen);
#else
  /* root node has no end tag either */
#endif
  ENC_LEN_DEBUG(x, "xa:EnvironmentMatch", p-enc_base);
  return p;
}

/* FUNC(zx_ENC_WO_xa_EnvironmentMatch) */

/* Render element into string. The XML attributes and elements are
 * processed in wire order by chasing wo pointers. This is what you want for
 * validating signatures on other people's XML documents. */

/* Called by: */
char* zx_ENC_WO_xa_EnvironmentMatch(struct zx_ctx* c, struct zx_xa_EnvironmentMatch_s* x, char* p )
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
  ZX_OUT_MEM(p, "EnvironmentMatch", sizeof("EnvironmentMatch")-1);
  qq = p;

  /* *** sort the namespaces */
  if (c->inc_ns)
    zx_add_inc_ns(c, &pop_seen);
  zx_add_xmlns_if_not_seen(c, x->gg.g.ns, &pop_seen);

  p = zx_enc_seen(p, pop_seen); 
  p = zx_attr_wo_enc(p, x->MatchId, "MatchId=\"", sizeof("MatchId=\"")-1);

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
  ENC_LEN_DEBUG(x, "xa:EnvironmentMatch", p-enc_base);
  return p;
}

/* FUNC(zx_EASY_ENC_SO_xa_EnvironmentMatch) */

/* Called by: */
struct zx_str* zx_EASY_ENC_SO_xa_EnvironmentMatch(struct zx_ctx* c, struct zx_xa_EnvironmentMatch_s* x )
{
  int len;
  char* buf;
  c->ns_tab = ZX_ALLOC(c, sizeof(zx_ns_tab));
  memcpy(c->ns_tab, zx_ns_tab, sizeof(zx_ns_tab));
  len = zx_LEN_SO_xa_EnvironmentMatch(c, x );
  buf = ZX_ALLOC(c, len+1);
  return zx_easy_enc_common(c, zx_ENC_SO_xa_EnvironmentMatch(c, x, buf ), buf, len);
}

/* FUNC(zx_EASY_ENC_WO_xa_EnvironmentMatch) */

/* Called by: */
struct zx_str* zx_EASY_ENC_WO_xa_EnvironmentMatch(struct zx_ctx* c, struct zx_xa_EnvironmentMatch_s* x )
{
  int len;
  char* buf;
  c->ns_tab = ZX_ALLOC(c, sizeof(zx_ns_tab));
  memcpy(c->ns_tab, zx_ns_tab, sizeof(zx_ns_tab));
  len = zx_LEN_WO_xa_EnvironmentMatch(c, x );
  buf = ZX_ALLOC(c, len+1);
  return zx_easy_enc_common(c, zx_ENC_WO_xa_EnvironmentMatch(c, x, buf ), buf, len);
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

#define EL_NAME   xa_Environments
#define EL_STRUCT zx_xa_Environments_s
#define EL_NS     xa
#define EL_TAG    Environments

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

/* FUNC(zx_LEN_SO_xa_Environments) */

/* Compute length of an element (and its subelements). The XML attributes
 * and elements are processed in schema order. */

/* Called by: */
int zx_LEN_SO_xa_Environments(struct zx_ctx* c, struct zx_xa_Environments_s* x )
{
  struct zx_ns_s* pop_seen = 0;
  struct zx_elem_s* se MAYBE_UNUSED;
#if 1 /* NORMALMODE */
  /* *** in simple_elem case should output ns prefix from ns node. */
  int len = sizeof("<xa:Environments")-1 + 1 + sizeof("</xa:Environments>")-1;
  if (c->inc_ns_len)
    len += zx_len_inc_ns(c, &pop_seen);
  len += zx_len_xmlns_if_not_seen(c, zx_ns_tab+zx_xmlns_ix_xa, &pop_seen);


#else
  /* root node has no begin tag */
  int len = 0;
#endif
  
  {
      struct zx_xa_Environment_s* e;
      for (e = x->Environment; e; e = (struct zx_xa_Environment_s*)e->gg.g.n)
	  len += zx_LEN_SO_xa_Environment(c, e);
  }


  len += zx_len_so_common(c, &x->gg);
  zx_pop_seen(pop_seen);
  ENC_LEN_DEBUG(x, "xa:Environments", len);
  return len;
}

/* FUNC(zx_LEN_WO_xa_Environments) */

/* Compute length of an element (and its subelements). The XML attributes
 * and elements are processed in wire order and no assumptions
 * are made about namespace prefixes. */

/* Called by: */
int zx_LEN_WO_xa_Environments(struct zx_ctx* c, struct zx_xa_Environments_s* x )
{
  struct zx_ns_s* pop_seen = 0;
  struct zx_elem_s* se MAYBE_UNUSED;
#if 1 /* NORMALMODE */
  int len = 1 + sizeof("Environments")-1 + 1 + 2 + sizeof("Environments")-1 + 1;
  
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
      struct zx_xa_Environment_s* e;
      for (e = x->Environment; e; e = (struct zx_xa_Environment_s*)e->gg.g.n)
	  len += zx_LEN_WO_xa_Environment(c, e);
  }


  len += zx_len_wo_common(c, &x->gg); 
  zx_pop_seen(pop_seen);
  ENC_LEN_DEBUG(x, "xa:Environments", len);
  return len;
}

/* FUNC(zx_ENC_SO_xa_Environments) */

/* Render element into string. The XML attributes and elements are
 * processed in schema order. This is what you generally want for
 * rendering new data structure to a string. The wo pointers are not used. */

/* Called by: */
char* zx_ENC_SO_xa_Environments(struct zx_ctx* c, struct zx_xa_Environments_s* x, char* p )
{
  struct zx_elem_s* se MAYBE_UNUSED;
  ENC_LEN_DEBUG_BASE;
#if 1 /* NORMALMODE */
  struct zx_ns_s* pop_seen = 0;
  /* *** in simple_elem case should output ns prefix from ns node. */
  ZX_OUT_TAG(p, "<xa:Environments");
  if (c->inc_ns)
    p = zx_enc_inc_ns(c, p, &pop_seen);
  p = zx_enc_xmlns_if_not_seen(c, p, zx_ns_tab+zx_xmlns_ix_xa, &pop_seen);


  p = zx_enc_unknown_attrs(p, x->gg.any_attr);
#else
  /* root node has no begin tag */
#endif
  
  {
      struct zx_xa_Environment_s* e;
      for (e = x->Environment; e; e = (struct zx_xa_Environment_s*)e->gg.g.n)
	  p = zx_ENC_SO_xa_Environment(c, e, p);
  }

  p = zx_enc_so_unknown_elems_and_content(c, p, &x->gg);
  
#if 1 /* NORMALMODE */
  ZX_OUT_CLOSE_TAG(p, "</xa:Environments>");
  zx_pop_seen(pop_seen);
#else
  /* root node has no end tag either */
#endif
  ENC_LEN_DEBUG(x, "xa:Environments", p-enc_base);
  return p;
}

/* FUNC(zx_ENC_WO_xa_Environments) */

/* Render element into string. The XML attributes and elements are
 * processed in wire order by chasing wo pointers. This is what you want for
 * validating signatures on other people's XML documents. */

/* Called by: */
char* zx_ENC_WO_xa_Environments(struct zx_ctx* c, struct zx_xa_Environments_s* x, char* p )
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
  ZX_OUT_MEM(p, "Environments", sizeof("Environments")-1);
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
  ENC_LEN_DEBUG(x, "xa:Environments", p-enc_base);
  return p;
}

/* FUNC(zx_EASY_ENC_SO_xa_Environments) */

/* Called by: */
struct zx_str* zx_EASY_ENC_SO_xa_Environments(struct zx_ctx* c, struct zx_xa_Environments_s* x )
{
  int len;
  char* buf;
  c->ns_tab = ZX_ALLOC(c, sizeof(zx_ns_tab));
  memcpy(c->ns_tab, zx_ns_tab, sizeof(zx_ns_tab));
  len = zx_LEN_SO_xa_Environments(c, x );
  buf = ZX_ALLOC(c, len+1);
  return zx_easy_enc_common(c, zx_ENC_SO_xa_Environments(c, x, buf ), buf, len);
}

/* FUNC(zx_EASY_ENC_WO_xa_Environments) */

/* Called by: */
struct zx_str* zx_EASY_ENC_WO_xa_Environments(struct zx_ctx* c, struct zx_xa_Environments_s* x )
{
  int len;
  char* buf;
  c->ns_tab = ZX_ALLOC(c, sizeof(zx_ns_tab));
  memcpy(c->ns_tab, zx_ns_tab, sizeof(zx_ns_tab));
  len = zx_LEN_WO_xa_Environments(c, x );
  buf = ZX_ALLOC(c, len+1);
  return zx_easy_enc_common(c, zx_ENC_WO_xa_Environments(c, x, buf ), buf, len);
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

#define EL_NAME   xa_Function
#define EL_STRUCT zx_xa_Function_s
#define EL_NS     xa
#define EL_TAG    Function

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

/* FUNC(zx_LEN_SO_xa_Function) */

/* Compute length of an element (and its subelements). The XML attributes
 * and elements are processed in schema order. */

/* Called by: */
int zx_LEN_SO_xa_Function(struct zx_ctx* c, struct zx_xa_Function_s* x )
{
  struct zx_ns_s* pop_seen = 0;
  struct zx_elem_s* se MAYBE_UNUSED;
#if 1 /* NORMALMODE */
  /* *** in simple_elem case should output ns prefix from ns node. */
  int len = sizeof("<xa:Function")-1 + 1 + sizeof("</xa:Function>")-1;
  if (c->inc_ns_len)
    len += zx_len_inc_ns(c, &pop_seen);
  len += zx_len_xmlns_if_not_seen(c, zx_ns_tab+zx_xmlns_ix_xa, &pop_seen);

  len += zx_attr_so_len(x->FunctionId, sizeof("FunctionId")-1);

#else
  /* root node has no begin tag */
  int len = 0;
#endif
  


  len += zx_len_so_common(c, &x->gg);
  zx_pop_seen(pop_seen);
  ENC_LEN_DEBUG(x, "xa:Function", len);
  return len;
}

/* FUNC(zx_LEN_WO_xa_Function) */

/* Compute length of an element (and its subelements). The XML attributes
 * and elements are processed in wire order and no assumptions
 * are made about namespace prefixes. */

/* Called by: */
int zx_LEN_WO_xa_Function(struct zx_ctx* c, struct zx_xa_Function_s* x )
{
  struct zx_ns_s* pop_seen = 0;
  struct zx_elem_s* se MAYBE_UNUSED;
#if 1 /* NORMALMODE */
  int len = 1 + sizeof("Function")-1 + 1 + 2 + sizeof("Function")-1 + 1;
  
  if (x->gg.g.ns && x->gg.g.ns->prefix_len)
    len += (x->gg.g.ns->prefix_len + 1) * 2;
  if (c->inc_ns_len)
    len += zx_len_inc_ns(c, &pop_seen);
  len += zx_len_xmlns_if_not_seen(c, x->gg.g.ns, &pop_seen);

  len += zx_attr_wo_len(x->FunctionId, sizeof("FunctionId")-1);

#else
  /* root node has no begin tag */
  int len = 0;
#endif
  


  len += zx_len_wo_common(c, &x->gg); 
  zx_pop_seen(pop_seen);
  ENC_LEN_DEBUG(x, "xa:Function", len);
  return len;
}

/* FUNC(zx_ENC_SO_xa_Function) */

/* Render element into string. The XML attributes and elements are
 * processed in schema order. This is what you generally want for
 * rendering new data structure to a string. The wo pointers are not used. */

/* Called by: */
char* zx_ENC_SO_xa_Function(struct zx_ctx* c, struct zx_xa_Function_s* x, char* p )
{
  struct zx_elem_s* se MAYBE_UNUSED;
  ENC_LEN_DEBUG_BASE;
#if 1 /* NORMALMODE */
  struct zx_ns_s* pop_seen = 0;
  /* *** in simple_elem case should output ns prefix from ns node. */
  ZX_OUT_TAG(p, "<xa:Function");
  if (c->inc_ns)
    p = zx_enc_inc_ns(c, p, &pop_seen);
  p = zx_enc_xmlns_if_not_seen(c, p, zx_ns_tab+zx_xmlns_ix_xa, &pop_seen);

  p = zx_attr_so_enc(p, x->FunctionId, " FunctionId=\"", sizeof(" FunctionId=\"")-1);

  p = zx_enc_unknown_attrs(p, x->gg.any_attr);
#else
  /* root node has no begin tag */
#endif
  

  p = zx_enc_so_unknown_elems_and_content(c, p, &x->gg);
  
#if 1 /* NORMALMODE */
  ZX_OUT_CLOSE_TAG(p, "</xa:Function>");
  zx_pop_seen(pop_seen);
#else
  /* root node has no end tag either */
#endif
  ENC_LEN_DEBUG(x, "xa:Function", p-enc_base);
  return p;
}

/* FUNC(zx_ENC_WO_xa_Function) */

/* Render element into string. The XML attributes and elements are
 * processed in wire order by chasing wo pointers. This is what you want for
 * validating signatures on other people's XML documents. */

/* Called by: */
char* zx_ENC_WO_xa_Function(struct zx_ctx* c, struct zx_xa_Function_s* x, char* p )
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
  ZX_OUT_MEM(p, "Function", sizeof("Function")-1);
  qq = p;

  /* *** sort the namespaces */
  if (c->inc_ns)
    zx_add_inc_ns(c, &pop_seen);
  zx_add_xmlns_if_not_seen(c, x->gg.g.ns, &pop_seen);

  p = zx_enc_seen(p, pop_seen); 
  p = zx_attr_wo_enc(p, x->FunctionId, "FunctionId=\"", sizeof("FunctionId=\"")-1);

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
  ENC_LEN_DEBUG(x, "xa:Function", p-enc_base);
  return p;
}

/* FUNC(zx_EASY_ENC_SO_xa_Function) */

/* Called by: */
struct zx_str* zx_EASY_ENC_SO_xa_Function(struct zx_ctx* c, struct zx_xa_Function_s* x )
{
  int len;
  char* buf;
  c->ns_tab = ZX_ALLOC(c, sizeof(zx_ns_tab));
  memcpy(c->ns_tab, zx_ns_tab, sizeof(zx_ns_tab));
  len = zx_LEN_SO_xa_Function(c, x );
  buf = ZX_ALLOC(c, len+1);
  return zx_easy_enc_common(c, zx_ENC_SO_xa_Function(c, x, buf ), buf, len);
}

/* FUNC(zx_EASY_ENC_WO_xa_Function) */

/* Called by: */
struct zx_str* zx_EASY_ENC_WO_xa_Function(struct zx_ctx* c, struct zx_xa_Function_s* x )
{
  int len;
  char* buf;
  c->ns_tab = ZX_ALLOC(c, sizeof(zx_ns_tab));
  memcpy(c->ns_tab, zx_ns_tab, sizeof(zx_ns_tab));
  len = zx_LEN_WO_xa_Function(c, x );
  buf = ZX_ALLOC(c, len+1);
  return zx_easy_enc_common(c, zx_ENC_WO_xa_Function(c, x, buf ), buf, len);
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

#define EL_NAME   xa_Obligation
#define EL_STRUCT zx_xa_Obligation_s
#define EL_NS     xa
#define EL_TAG    Obligation

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

/* FUNC(zx_LEN_SO_xa_Obligation) */

/* Compute length of an element (and its subelements). The XML attributes
 * and elements are processed in schema order. */

/* Called by: */
int zx_LEN_SO_xa_Obligation(struct zx_ctx* c, struct zx_xa_Obligation_s* x )
{
  struct zx_ns_s* pop_seen = 0;
  struct zx_elem_s* se MAYBE_UNUSED;
#if 1 /* NORMALMODE */
  /* *** in simple_elem case should output ns prefix from ns node. */
  int len = sizeof("<xa:Obligation")-1 + 1 + sizeof("</xa:Obligation>")-1;
  if (c->inc_ns_len)
    len += zx_len_inc_ns(c, &pop_seen);
  len += zx_len_xmlns_if_not_seen(c, zx_ns_tab+zx_xmlns_ix_xa, &pop_seen);

  len += zx_attr_so_len(x->FulfillOn, sizeof("FulfillOn")-1);
  len += zx_attr_so_len(x->ObligationId, sizeof("ObligationId")-1);

#else
  /* root node has no begin tag */
  int len = 0;
#endif
  
  {
      struct zx_xa_AttributeAssignment_s* e;
      for (e = x->AttributeAssignment; e; e = (struct zx_xa_AttributeAssignment_s*)e->gg.g.n)
	  len += zx_LEN_SO_xa_AttributeAssignment(c, e);
  }


  len += zx_len_so_common(c, &x->gg);
  zx_pop_seen(pop_seen);
  ENC_LEN_DEBUG(x, "xa:Obligation", len);
  return len;
}

/* FUNC(zx_LEN_WO_xa_Obligation) */

/* Compute length of an element (and its subelements). The XML attributes
 * and elements are processed in wire order and no assumptions
 * are made about namespace prefixes. */

/* Called by: */
int zx_LEN_WO_xa_Obligation(struct zx_ctx* c, struct zx_xa_Obligation_s* x )
{
  struct zx_ns_s* pop_seen = 0;
  struct zx_elem_s* se MAYBE_UNUSED;
#if 1 /* NORMALMODE */
  int len = 1 + sizeof("Obligation")-1 + 1 + 2 + sizeof("Obligation")-1 + 1;
  
  if (x->gg.g.ns && x->gg.g.ns->prefix_len)
    len += (x->gg.g.ns->prefix_len + 1) * 2;
  if (c->inc_ns_len)
    len += zx_len_inc_ns(c, &pop_seen);
  len += zx_len_xmlns_if_not_seen(c, x->gg.g.ns, &pop_seen);

  len += zx_attr_wo_len(x->FulfillOn, sizeof("FulfillOn")-1);
  len += zx_attr_wo_len(x->ObligationId, sizeof("ObligationId")-1);

#else
  /* root node has no begin tag */
  int len = 0;
#endif
  
  {
      struct zx_xa_AttributeAssignment_s* e;
      for (e = x->AttributeAssignment; e; e = (struct zx_xa_AttributeAssignment_s*)e->gg.g.n)
	  len += zx_LEN_WO_xa_AttributeAssignment(c, e);
  }


  len += zx_len_wo_common(c, &x->gg); 
  zx_pop_seen(pop_seen);
  ENC_LEN_DEBUG(x, "xa:Obligation", len);
  return len;
}

/* FUNC(zx_ENC_SO_xa_Obligation) */

/* Render element into string. The XML attributes and elements are
 * processed in schema order. This is what you generally want for
 * rendering new data structure to a string. The wo pointers are not used. */

/* Called by: */
char* zx_ENC_SO_xa_Obligation(struct zx_ctx* c, struct zx_xa_Obligation_s* x, char* p )
{
  struct zx_elem_s* se MAYBE_UNUSED;
  ENC_LEN_DEBUG_BASE;
#if 1 /* NORMALMODE */
  struct zx_ns_s* pop_seen = 0;
  /* *** in simple_elem case should output ns prefix from ns node. */
  ZX_OUT_TAG(p, "<xa:Obligation");
  if (c->inc_ns)
    p = zx_enc_inc_ns(c, p, &pop_seen);
  p = zx_enc_xmlns_if_not_seen(c, p, zx_ns_tab+zx_xmlns_ix_xa, &pop_seen);

  p = zx_attr_so_enc(p, x->FulfillOn, " FulfillOn=\"", sizeof(" FulfillOn=\"")-1);
  p = zx_attr_so_enc(p, x->ObligationId, " ObligationId=\"", sizeof(" ObligationId=\"")-1);

  p = zx_enc_unknown_attrs(p, x->gg.any_attr);
#else
  /* root node has no begin tag */
#endif
  
  {
      struct zx_xa_AttributeAssignment_s* e;
      for (e = x->AttributeAssignment; e; e = (struct zx_xa_AttributeAssignment_s*)e->gg.g.n)
	  p = zx_ENC_SO_xa_AttributeAssignment(c, e, p);
  }

  p = zx_enc_so_unknown_elems_and_content(c, p, &x->gg);
  
#if 1 /* NORMALMODE */
  ZX_OUT_CLOSE_TAG(p, "</xa:Obligation>");
  zx_pop_seen(pop_seen);
#else
  /* root node has no end tag either */
#endif
  ENC_LEN_DEBUG(x, "xa:Obligation", p-enc_base);
  return p;
}

/* FUNC(zx_ENC_WO_xa_Obligation) */

/* Render element into string. The XML attributes and elements are
 * processed in wire order by chasing wo pointers. This is what you want for
 * validating signatures on other people's XML documents. */

/* Called by: */
char* zx_ENC_WO_xa_Obligation(struct zx_ctx* c, struct zx_xa_Obligation_s* x, char* p )
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
  ZX_OUT_MEM(p, "Obligation", sizeof("Obligation")-1);
  qq = p;

  /* *** sort the namespaces */
  if (c->inc_ns)
    zx_add_inc_ns(c, &pop_seen);
  zx_add_xmlns_if_not_seen(c, x->gg.g.ns, &pop_seen);

  p = zx_enc_seen(p, pop_seen); 
  p = zx_attr_wo_enc(p, x->FulfillOn, "FulfillOn=\"", sizeof("FulfillOn=\"")-1);
  p = zx_attr_wo_enc(p, x->ObligationId, "ObligationId=\"", sizeof("ObligationId=\"")-1);

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
  ENC_LEN_DEBUG(x, "xa:Obligation", p-enc_base);
  return p;
}

/* FUNC(zx_EASY_ENC_SO_xa_Obligation) */

/* Called by: */
struct zx_str* zx_EASY_ENC_SO_xa_Obligation(struct zx_ctx* c, struct zx_xa_Obligation_s* x )
{
  int len;
  char* buf;
  c->ns_tab = ZX_ALLOC(c, sizeof(zx_ns_tab));
  memcpy(c->ns_tab, zx_ns_tab, sizeof(zx_ns_tab));
  len = zx_LEN_SO_xa_Obligation(c, x );
  buf = ZX_ALLOC(c, len+1);
  return zx_easy_enc_common(c, zx_ENC_SO_xa_Obligation(c, x, buf ), buf, len);
}

/* FUNC(zx_EASY_ENC_WO_xa_Obligation) */

/* Called by: */
struct zx_str* zx_EASY_ENC_WO_xa_Obligation(struct zx_ctx* c, struct zx_xa_Obligation_s* x )
{
  int len;
  char* buf;
  c->ns_tab = ZX_ALLOC(c, sizeof(zx_ns_tab));
  memcpy(c->ns_tab, zx_ns_tab, sizeof(zx_ns_tab));
  len = zx_LEN_WO_xa_Obligation(c, x );
  buf = ZX_ALLOC(c, len+1);
  return zx_easy_enc_common(c, zx_ENC_WO_xa_Obligation(c, x, buf ), buf, len);
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

#define EL_NAME   xa_Obligations
#define EL_STRUCT zx_xa_Obligations_s
#define EL_NS     xa
#define EL_TAG    Obligations

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

/* FUNC(zx_LEN_SO_xa_Obligations) */

/* Compute length of an element (and its subelements). The XML attributes
 * and elements are processed in schema order. */

/* Called by: */
int zx_LEN_SO_xa_Obligations(struct zx_ctx* c, struct zx_xa_Obligations_s* x )
{
  struct zx_ns_s* pop_seen = 0;
  struct zx_elem_s* se MAYBE_UNUSED;
#if 1 /* NORMALMODE */
  /* *** in simple_elem case should output ns prefix from ns node. */
  int len = sizeof("<xa:Obligations")-1 + 1 + sizeof("</xa:Obligations>")-1;
  if (c->inc_ns_len)
    len += zx_len_inc_ns(c, &pop_seen);
  len += zx_len_xmlns_if_not_seen(c, zx_ns_tab+zx_xmlns_ix_xa, &pop_seen);


#else
  /* root node has no begin tag */
  int len = 0;
#endif
  
  {
      struct zx_xa_Obligation_s* e;
      for (e = x->Obligation; e; e = (struct zx_xa_Obligation_s*)e->gg.g.n)
	  len += zx_LEN_SO_xa_Obligation(c, e);
  }


  len += zx_len_so_common(c, &x->gg);
  zx_pop_seen(pop_seen);
  ENC_LEN_DEBUG(x, "xa:Obligations", len);
  return len;
}

/* FUNC(zx_LEN_WO_xa_Obligations) */

/* Compute length of an element (and its subelements). The XML attributes
 * and elements are processed in wire order and no assumptions
 * are made about namespace prefixes. */

/* Called by: */
int zx_LEN_WO_xa_Obligations(struct zx_ctx* c, struct zx_xa_Obligations_s* x )
{
  struct zx_ns_s* pop_seen = 0;
  struct zx_elem_s* se MAYBE_UNUSED;
#if 1 /* NORMALMODE */
  int len = 1 + sizeof("Obligations")-1 + 1 + 2 + sizeof("Obligations")-1 + 1;
  
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
      struct zx_xa_Obligation_s* e;
      for (e = x->Obligation; e; e = (struct zx_xa_Obligation_s*)e->gg.g.n)
	  len += zx_LEN_WO_xa_Obligation(c, e);
  }


  len += zx_len_wo_common(c, &x->gg); 
  zx_pop_seen(pop_seen);
  ENC_LEN_DEBUG(x, "xa:Obligations", len);
  return len;
}

/* FUNC(zx_ENC_SO_xa_Obligations) */

/* Render element into string. The XML attributes and elements are
 * processed in schema order. This is what you generally want for
 * rendering new data structure to a string. The wo pointers are not used. */

/* Called by: */
char* zx_ENC_SO_xa_Obligations(struct zx_ctx* c, struct zx_xa_Obligations_s* x, char* p )
{
  struct zx_elem_s* se MAYBE_UNUSED;
  ENC_LEN_DEBUG_BASE;
#if 1 /* NORMALMODE */
  struct zx_ns_s* pop_seen = 0;
  /* *** in simple_elem case should output ns prefix from ns node. */
  ZX_OUT_TAG(p, "<xa:Obligations");
  if (c->inc_ns)
    p = zx_enc_inc_ns(c, p, &pop_seen);
  p = zx_enc_xmlns_if_not_seen(c, p, zx_ns_tab+zx_xmlns_ix_xa, &pop_seen);


  p = zx_enc_unknown_attrs(p, x->gg.any_attr);
#else
  /* root node has no begin tag */
#endif
  
  {
      struct zx_xa_Obligation_s* e;
      for (e = x->Obligation; e; e = (struct zx_xa_Obligation_s*)e->gg.g.n)
	  p = zx_ENC_SO_xa_Obligation(c, e, p);
  }

  p = zx_enc_so_unknown_elems_and_content(c, p, &x->gg);
  
#if 1 /* NORMALMODE */
  ZX_OUT_CLOSE_TAG(p, "</xa:Obligations>");
  zx_pop_seen(pop_seen);
#else
  /* root node has no end tag either */
#endif
  ENC_LEN_DEBUG(x, "xa:Obligations", p-enc_base);
  return p;
}

/* FUNC(zx_ENC_WO_xa_Obligations) */

/* Render element into string. The XML attributes and elements are
 * processed in wire order by chasing wo pointers. This is what you want for
 * validating signatures on other people's XML documents. */

/* Called by: */
char* zx_ENC_WO_xa_Obligations(struct zx_ctx* c, struct zx_xa_Obligations_s* x, char* p )
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
  ZX_OUT_MEM(p, "Obligations", sizeof("Obligations")-1);
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
  ENC_LEN_DEBUG(x, "xa:Obligations", p-enc_base);
  return p;
}

/* FUNC(zx_EASY_ENC_SO_xa_Obligations) */

/* Called by: */
struct zx_str* zx_EASY_ENC_SO_xa_Obligations(struct zx_ctx* c, struct zx_xa_Obligations_s* x )
{
  int len;
  char* buf;
  c->ns_tab = ZX_ALLOC(c, sizeof(zx_ns_tab));
  memcpy(c->ns_tab, zx_ns_tab, sizeof(zx_ns_tab));
  len = zx_LEN_SO_xa_Obligations(c, x );
  buf = ZX_ALLOC(c, len+1);
  return zx_easy_enc_common(c, zx_ENC_SO_xa_Obligations(c, x, buf ), buf, len);
}

/* FUNC(zx_EASY_ENC_WO_xa_Obligations) */

/* Called by: */
struct zx_str* zx_EASY_ENC_WO_xa_Obligations(struct zx_ctx* c, struct zx_xa_Obligations_s* x )
{
  int len;
  char* buf;
  c->ns_tab = ZX_ALLOC(c, sizeof(zx_ns_tab));
  memcpy(c->ns_tab, zx_ns_tab, sizeof(zx_ns_tab));
  len = zx_LEN_WO_xa_Obligations(c, x );
  buf = ZX_ALLOC(c, len+1);
  return zx_easy_enc_common(c, zx_ENC_WO_xa_Obligations(c, x, buf ), buf, len);
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

#define EL_NAME   xa_Policy
#define EL_STRUCT zx_xa_Policy_s
#define EL_NS     xa
#define EL_TAG    Policy

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

/* FUNC(zx_LEN_SO_xa_Policy) */

/* Compute length of an element (and its subelements). The XML attributes
 * and elements are processed in schema order. */

/* Called by: */
int zx_LEN_SO_xa_Policy(struct zx_ctx* c, struct zx_xa_Policy_s* x )
{
  struct zx_ns_s* pop_seen = 0;
  struct zx_elem_s* se MAYBE_UNUSED;
#if 1 /* NORMALMODE */
  /* *** in simple_elem case should output ns prefix from ns node. */
  int len = sizeof("<xa:Policy")-1 + 1 + sizeof("</xa:Policy>")-1;
  if (c->inc_ns_len)
    len += zx_len_inc_ns(c, &pop_seen);
  len += zx_len_xmlns_if_not_seen(c, zx_ns_tab+zx_xmlns_ix_xa, &pop_seen);

  len += zx_attr_so_len(x->PolicyId, sizeof("PolicyId")-1);
  len += zx_attr_so_len(x->RuleCombiningAlgId, sizeof("RuleCombiningAlgId")-1);
  len += zx_attr_so_len(x->Version, sizeof("Version")-1);

#else
  /* root node has no begin tag */
  int len = 0;
#endif
  
  for (se = x->Description; se; se = (struct zx_elem_s*)se->g.n)
    len += zx_LEN_SO_simple_elem(c,se, sizeof("xa:Description")-1, zx_ns_tab+zx_xmlns_ix_xa);
  {
      struct zx_xa_PolicyDefaults_s* e;
      for (e = x->PolicyDefaults; e; e = (struct zx_xa_PolicyDefaults_s*)e->gg.g.n)
	  len += zx_LEN_SO_xa_PolicyDefaults(c, e);
  }
  {
      struct zx_xa_Target_s* e;
      for (e = x->Target; e; e = (struct zx_xa_Target_s*)e->gg.g.n)
	  len += zx_LEN_SO_xa_Target(c, e);
  }
  {
      struct zx_xa_CombinerParameters_s* e;
      for (e = x->CombinerParameters; e; e = (struct zx_xa_CombinerParameters_s*)e->gg.g.n)
	  len += zx_LEN_SO_xa_CombinerParameters(c, e);
  }
  {
      struct zx_xa_RuleCombinerParameters_s* e;
      for (e = x->RuleCombinerParameters; e; e = (struct zx_xa_RuleCombinerParameters_s*)e->gg.g.n)
	  len += zx_LEN_SO_xa_RuleCombinerParameters(c, e);
  }
  {
      struct zx_xa_VariableDefinition_s* e;
      for (e = x->VariableDefinition; e; e = (struct zx_xa_VariableDefinition_s*)e->gg.g.n)
	  len += zx_LEN_SO_xa_VariableDefinition(c, e);
  }
  {
      struct zx_xa_Rule_s* e;
      for (e = x->Rule; e; e = (struct zx_xa_Rule_s*)e->gg.g.n)
	  len += zx_LEN_SO_xa_Rule(c, e);
  }
  {
      struct zx_xa_Obligations_s* e;
      for (e = x->Obligations; e; e = (struct zx_xa_Obligations_s*)e->gg.g.n)
	  len += zx_LEN_SO_xa_Obligations(c, e);
  }


  len += zx_len_so_common(c, &x->gg);
  zx_pop_seen(pop_seen);
  ENC_LEN_DEBUG(x, "xa:Policy", len);
  return len;
}

/* FUNC(zx_LEN_WO_xa_Policy) */

/* Compute length of an element (and its subelements). The XML attributes
 * and elements are processed in wire order and no assumptions
 * are made about namespace prefixes. */

/* Called by: */
int zx_LEN_WO_xa_Policy(struct zx_ctx* c, struct zx_xa_Policy_s* x )
{
  struct zx_ns_s* pop_seen = 0;
  struct zx_elem_s* se MAYBE_UNUSED;
#if 1 /* NORMALMODE */
  int len = 1 + sizeof("Policy")-1 + 1 + 2 + sizeof("Policy")-1 + 1;
  
  if (x->gg.g.ns && x->gg.g.ns->prefix_len)
    len += (x->gg.g.ns->prefix_len + 1) * 2;
  if (c->inc_ns_len)
    len += zx_len_inc_ns(c, &pop_seen);
  len += zx_len_xmlns_if_not_seen(c, x->gg.g.ns, &pop_seen);

  len += zx_attr_wo_len(x->PolicyId, sizeof("PolicyId")-1);
  len += zx_attr_wo_len(x->RuleCombiningAlgId, sizeof("RuleCombiningAlgId")-1);
  len += zx_attr_wo_len(x->Version, sizeof("Version")-1);

#else
  /* root node has no begin tag */
  int len = 0;
#endif
  
  for (se = x->Description; se; se = (struct zx_elem_s*)se->g.n)
    len += zx_LEN_WO_simple_elem(c, se, sizeof("Description")-1);
  {
      struct zx_xa_PolicyDefaults_s* e;
      for (e = x->PolicyDefaults; e; e = (struct zx_xa_PolicyDefaults_s*)e->gg.g.n)
	  len += zx_LEN_WO_xa_PolicyDefaults(c, e);
  }
  {
      struct zx_xa_Target_s* e;
      for (e = x->Target; e; e = (struct zx_xa_Target_s*)e->gg.g.n)
	  len += zx_LEN_WO_xa_Target(c, e);
  }
  {
      struct zx_xa_CombinerParameters_s* e;
      for (e = x->CombinerParameters; e; e = (struct zx_xa_CombinerParameters_s*)e->gg.g.n)
	  len += zx_LEN_WO_xa_CombinerParameters(c, e);
  }
  {
      struct zx_xa_RuleCombinerParameters_s* e;
      for (e = x->RuleCombinerParameters; e; e = (struct zx_xa_RuleCombinerParameters_s*)e->gg.g.n)
	  len += zx_LEN_WO_xa_RuleCombinerParameters(c, e);
  }
  {
      struct zx_xa_VariableDefinition_s* e;
      for (e = x->VariableDefinition; e; e = (struct zx_xa_VariableDefinition_s*)e->gg.g.n)
	  len += zx_LEN_WO_xa_VariableDefinition(c, e);
  }
  {
      struct zx_xa_Rule_s* e;
      for (e = x->Rule; e; e = (struct zx_xa_Rule_s*)e->gg.g.n)
	  len += zx_LEN_WO_xa_Rule(c, e);
  }
  {
      struct zx_xa_Obligations_s* e;
      for (e = x->Obligations; e; e = (struct zx_xa_Obligations_s*)e->gg.g.n)
	  len += zx_LEN_WO_xa_Obligations(c, e);
  }


  len += zx_len_wo_common(c, &x->gg); 
  zx_pop_seen(pop_seen);
  ENC_LEN_DEBUG(x, "xa:Policy", len);
  return len;
}

/* FUNC(zx_ENC_SO_xa_Policy) */

/* Render element into string. The XML attributes and elements are
 * processed in schema order. This is what you generally want for
 * rendering new data structure to a string. The wo pointers are not used. */

/* Called by: */
char* zx_ENC_SO_xa_Policy(struct zx_ctx* c, struct zx_xa_Policy_s* x, char* p )
{
  struct zx_elem_s* se MAYBE_UNUSED;
  ENC_LEN_DEBUG_BASE;
#if 1 /* NORMALMODE */
  struct zx_ns_s* pop_seen = 0;
  /* *** in simple_elem case should output ns prefix from ns node. */
  ZX_OUT_TAG(p, "<xa:Policy");
  if (c->inc_ns)
    p = zx_enc_inc_ns(c, p, &pop_seen);
  p = zx_enc_xmlns_if_not_seen(c, p, zx_ns_tab+zx_xmlns_ix_xa, &pop_seen);

  p = zx_attr_so_enc(p, x->PolicyId, " PolicyId=\"", sizeof(" PolicyId=\"")-1);
  p = zx_attr_so_enc(p, x->RuleCombiningAlgId, " RuleCombiningAlgId=\"", sizeof(" RuleCombiningAlgId=\"")-1);
  p = zx_attr_so_enc(p, x->Version, " Version=\"", sizeof(" Version=\"")-1);

  p = zx_enc_unknown_attrs(p, x->gg.any_attr);
#else
  /* root node has no begin tag */
#endif
  
  for (se = x->Description; se; se = (struct zx_elem_s*)se->g.n)
    p = zx_ENC_SO_simple_elem(c, se, p, "xa:Description", sizeof("xa:Description")-1, zx_ns_tab+zx_xmlns_ix_xa);
  {
      struct zx_xa_PolicyDefaults_s* e;
      for (e = x->PolicyDefaults; e; e = (struct zx_xa_PolicyDefaults_s*)e->gg.g.n)
	  p = zx_ENC_SO_xa_PolicyDefaults(c, e, p);
  }
  {
      struct zx_xa_Target_s* e;
      for (e = x->Target; e; e = (struct zx_xa_Target_s*)e->gg.g.n)
	  p = zx_ENC_SO_xa_Target(c, e, p);
  }
  {
      struct zx_xa_CombinerParameters_s* e;
      for (e = x->CombinerParameters; e; e = (struct zx_xa_CombinerParameters_s*)e->gg.g.n)
	  p = zx_ENC_SO_xa_CombinerParameters(c, e, p);
  }
  {
      struct zx_xa_RuleCombinerParameters_s* e;
      for (e = x->RuleCombinerParameters; e; e = (struct zx_xa_RuleCombinerParameters_s*)e->gg.g.n)
	  p = zx_ENC_SO_xa_RuleCombinerParameters(c, e, p);
  }
  {
      struct zx_xa_VariableDefinition_s* e;
      for (e = x->VariableDefinition; e; e = (struct zx_xa_VariableDefinition_s*)e->gg.g.n)
	  p = zx_ENC_SO_xa_VariableDefinition(c, e, p);
  }
  {
      struct zx_xa_Rule_s* e;
      for (e = x->Rule; e; e = (struct zx_xa_Rule_s*)e->gg.g.n)
	  p = zx_ENC_SO_xa_Rule(c, e, p);
  }
  {
      struct zx_xa_Obligations_s* e;
      for (e = x->Obligations; e; e = (struct zx_xa_Obligations_s*)e->gg.g.n)
	  p = zx_ENC_SO_xa_Obligations(c, e, p);
  }

  p = zx_enc_so_unknown_elems_and_content(c, p, &x->gg);
  
#if 1 /* NORMALMODE */
  ZX_OUT_CLOSE_TAG(p, "</xa:Policy>");
  zx_pop_seen(pop_seen);
#else
  /* root node has no end tag either */
#endif
  ENC_LEN_DEBUG(x, "xa:Policy", p-enc_base);
  return p;
}

/* FUNC(zx_ENC_WO_xa_Policy) */

/* Render element into string. The XML attributes and elements are
 * processed in wire order by chasing wo pointers. This is what you want for
 * validating signatures on other people's XML documents. */

/* Called by: */
char* zx_ENC_WO_xa_Policy(struct zx_ctx* c, struct zx_xa_Policy_s* x, char* p )
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
  ZX_OUT_MEM(p, "Policy", sizeof("Policy")-1);
  qq = p;

  /* *** sort the namespaces */
  if (c->inc_ns)
    zx_add_inc_ns(c, &pop_seen);
  zx_add_xmlns_if_not_seen(c, x->gg.g.ns, &pop_seen);

  p = zx_enc_seen(p, pop_seen); 
  p = zx_attr_wo_enc(p, x->PolicyId, "PolicyId=\"", sizeof("PolicyId=\"")-1);
  p = zx_attr_wo_enc(p, x->RuleCombiningAlgId, "RuleCombiningAlgId=\"", sizeof("RuleCombiningAlgId=\"")-1);
  p = zx_attr_wo_enc(p, x->Version, "Version=\"", sizeof("Version=\"")-1);

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
  ENC_LEN_DEBUG(x, "xa:Policy", p-enc_base);
  return p;
}

/* FUNC(zx_EASY_ENC_SO_xa_Policy) */

/* Called by: */
struct zx_str* zx_EASY_ENC_SO_xa_Policy(struct zx_ctx* c, struct zx_xa_Policy_s* x )
{
  int len;
  char* buf;
  c->ns_tab = ZX_ALLOC(c, sizeof(zx_ns_tab));
  memcpy(c->ns_tab, zx_ns_tab, sizeof(zx_ns_tab));
  len = zx_LEN_SO_xa_Policy(c, x );
  buf = ZX_ALLOC(c, len+1);
  return zx_easy_enc_common(c, zx_ENC_SO_xa_Policy(c, x, buf ), buf, len);
}

/* FUNC(zx_EASY_ENC_WO_xa_Policy) */

/* Called by: */
struct zx_str* zx_EASY_ENC_WO_xa_Policy(struct zx_ctx* c, struct zx_xa_Policy_s* x )
{
  int len;
  char* buf;
  c->ns_tab = ZX_ALLOC(c, sizeof(zx_ns_tab));
  memcpy(c->ns_tab, zx_ns_tab, sizeof(zx_ns_tab));
  len = zx_LEN_WO_xa_Policy(c, x );
  buf = ZX_ALLOC(c, len+1);
  return zx_easy_enc_common(c, zx_ENC_WO_xa_Policy(c, x, buf ), buf, len);
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

#define EL_NAME   xa_PolicyCombinerParameters
#define EL_STRUCT zx_xa_PolicyCombinerParameters_s
#define EL_NS     xa
#define EL_TAG    PolicyCombinerParameters

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

/* FUNC(zx_LEN_SO_xa_PolicyCombinerParameters) */

/* Compute length of an element (and its subelements). The XML attributes
 * and elements are processed in schema order. */

/* Called by: */
int zx_LEN_SO_xa_PolicyCombinerParameters(struct zx_ctx* c, struct zx_xa_PolicyCombinerParameters_s* x )
{
  struct zx_ns_s* pop_seen = 0;
  struct zx_elem_s* se MAYBE_UNUSED;
#if 1 /* NORMALMODE */
  /* *** in simple_elem case should output ns prefix from ns node. */
  int len = sizeof("<xa:PolicyCombinerParameters")-1 + 1 + sizeof("</xa:PolicyCombinerParameters>")-1;
  if (c->inc_ns_len)
    len += zx_len_inc_ns(c, &pop_seen);
  len += zx_len_xmlns_if_not_seen(c, zx_ns_tab+zx_xmlns_ix_xa, &pop_seen);

  len += zx_attr_so_len(x->PolicyIdRef, sizeof("PolicyIdRef")-1);

#else
  /* root node has no begin tag */
  int len = 0;
#endif
  
  {
      struct zx_xa_CombinerParameter_s* e;
      for (e = x->CombinerParameter; e; e = (struct zx_xa_CombinerParameter_s*)e->gg.g.n)
	  len += zx_LEN_SO_xa_CombinerParameter(c, e);
  }


  len += zx_len_so_common(c, &x->gg);
  zx_pop_seen(pop_seen);
  ENC_LEN_DEBUG(x, "xa:PolicyCombinerParameters", len);
  return len;
}

/* FUNC(zx_LEN_WO_xa_PolicyCombinerParameters) */

/* Compute length of an element (and its subelements). The XML attributes
 * and elements are processed in wire order and no assumptions
 * are made about namespace prefixes. */

/* Called by: */
int zx_LEN_WO_xa_PolicyCombinerParameters(struct zx_ctx* c, struct zx_xa_PolicyCombinerParameters_s* x )
{
  struct zx_ns_s* pop_seen = 0;
  struct zx_elem_s* se MAYBE_UNUSED;
#if 1 /* NORMALMODE */
  int len = 1 + sizeof("PolicyCombinerParameters")-1 + 1 + 2 + sizeof("PolicyCombinerParameters")-1 + 1;
  
  if (x->gg.g.ns && x->gg.g.ns->prefix_len)
    len += (x->gg.g.ns->prefix_len + 1) * 2;
  if (c->inc_ns_len)
    len += zx_len_inc_ns(c, &pop_seen);
  len += zx_len_xmlns_if_not_seen(c, x->gg.g.ns, &pop_seen);

  len += zx_attr_wo_len(x->PolicyIdRef, sizeof("PolicyIdRef")-1);

#else
  /* root node has no begin tag */
  int len = 0;
#endif
  
  {
      struct zx_xa_CombinerParameter_s* e;
      for (e = x->CombinerParameter; e; e = (struct zx_xa_CombinerParameter_s*)e->gg.g.n)
	  len += zx_LEN_WO_xa_CombinerParameter(c, e);
  }


  len += zx_len_wo_common(c, &x->gg); 
  zx_pop_seen(pop_seen);
  ENC_LEN_DEBUG(x, "xa:PolicyCombinerParameters", len);
  return len;
}

/* FUNC(zx_ENC_SO_xa_PolicyCombinerParameters) */

/* Render element into string. The XML attributes and elements are
 * processed in schema order. This is what you generally want for
 * rendering new data structure to a string. The wo pointers are not used. */

/* Called by: */
char* zx_ENC_SO_xa_PolicyCombinerParameters(struct zx_ctx* c, struct zx_xa_PolicyCombinerParameters_s* x, char* p )
{
  struct zx_elem_s* se MAYBE_UNUSED;
  ENC_LEN_DEBUG_BASE;
#if 1 /* NORMALMODE */
  struct zx_ns_s* pop_seen = 0;
  /* *** in simple_elem case should output ns prefix from ns node. */
  ZX_OUT_TAG(p, "<xa:PolicyCombinerParameters");
  if (c->inc_ns)
    p = zx_enc_inc_ns(c, p, &pop_seen);
  p = zx_enc_xmlns_if_not_seen(c, p, zx_ns_tab+zx_xmlns_ix_xa, &pop_seen);

  p = zx_attr_so_enc(p, x->PolicyIdRef, " PolicyIdRef=\"", sizeof(" PolicyIdRef=\"")-1);

  p = zx_enc_unknown_attrs(p, x->gg.any_attr);
#else
  /* root node has no begin tag */
#endif
  
  {
      struct zx_xa_CombinerParameter_s* e;
      for (e = x->CombinerParameter; e; e = (struct zx_xa_CombinerParameter_s*)e->gg.g.n)
	  p = zx_ENC_SO_xa_CombinerParameter(c, e, p);
  }

  p = zx_enc_so_unknown_elems_and_content(c, p, &x->gg);
  
#if 1 /* NORMALMODE */
  ZX_OUT_CLOSE_TAG(p, "</xa:PolicyCombinerParameters>");
  zx_pop_seen(pop_seen);
#else
  /* root node has no end tag either */
#endif
  ENC_LEN_DEBUG(x, "xa:PolicyCombinerParameters", p-enc_base);
  return p;
}

/* FUNC(zx_ENC_WO_xa_PolicyCombinerParameters) */

/* Render element into string. The XML attributes and elements are
 * processed in wire order by chasing wo pointers. This is what you want for
 * validating signatures on other people's XML documents. */

/* Called by: */
char* zx_ENC_WO_xa_PolicyCombinerParameters(struct zx_ctx* c, struct zx_xa_PolicyCombinerParameters_s* x, char* p )
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
  ZX_OUT_MEM(p, "PolicyCombinerParameters", sizeof("PolicyCombinerParameters")-1);
  qq = p;

  /* *** sort the namespaces */
  if (c->inc_ns)
    zx_add_inc_ns(c, &pop_seen);
  zx_add_xmlns_if_not_seen(c, x->gg.g.ns, &pop_seen);

  p = zx_enc_seen(p, pop_seen); 
  p = zx_attr_wo_enc(p, x->PolicyIdRef, "PolicyIdRef=\"", sizeof("PolicyIdRef=\"")-1);

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
  ENC_LEN_DEBUG(x, "xa:PolicyCombinerParameters", p-enc_base);
  return p;
}

/* FUNC(zx_EASY_ENC_SO_xa_PolicyCombinerParameters) */

/* Called by: */
struct zx_str* zx_EASY_ENC_SO_xa_PolicyCombinerParameters(struct zx_ctx* c, struct zx_xa_PolicyCombinerParameters_s* x )
{
  int len;
  char* buf;
  c->ns_tab = ZX_ALLOC(c, sizeof(zx_ns_tab));
  memcpy(c->ns_tab, zx_ns_tab, sizeof(zx_ns_tab));
  len = zx_LEN_SO_xa_PolicyCombinerParameters(c, x );
  buf = ZX_ALLOC(c, len+1);
  return zx_easy_enc_common(c, zx_ENC_SO_xa_PolicyCombinerParameters(c, x, buf ), buf, len);
}

/* FUNC(zx_EASY_ENC_WO_xa_PolicyCombinerParameters) */

/* Called by: */
struct zx_str* zx_EASY_ENC_WO_xa_PolicyCombinerParameters(struct zx_ctx* c, struct zx_xa_PolicyCombinerParameters_s* x )
{
  int len;
  char* buf;
  c->ns_tab = ZX_ALLOC(c, sizeof(zx_ns_tab));
  memcpy(c->ns_tab, zx_ns_tab, sizeof(zx_ns_tab));
  len = zx_LEN_WO_xa_PolicyCombinerParameters(c, x );
  buf = ZX_ALLOC(c, len+1);
  return zx_easy_enc_common(c, zx_ENC_WO_xa_PolicyCombinerParameters(c, x, buf ), buf, len);
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

#define EL_NAME   xa_PolicyDefaults
#define EL_STRUCT zx_xa_PolicyDefaults_s
#define EL_NS     xa
#define EL_TAG    PolicyDefaults

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

/* FUNC(zx_LEN_SO_xa_PolicyDefaults) */

/* Compute length of an element (and its subelements). The XML attributes
 * and elements are processed in schema order. */

/* Called by: */
int zx_LEN_SO_xa_PolicyDefaults(struct zx_ctx* c, struct zx_xa_PolicyDefaults_s* x )
{
  struct zx_ns_s* pop_seen = 0;
  struct zx_elem_s* se MAYBE_UNUSED;
#if 1 /* NORMALMODE */
  /* *** in simple_elem case should output ns prefix from ns node. */
  int len = sizeof("<xa:PolicyDefaults")-1 + 1 + sizeof("</xa:PolicyDefaults>")-1;
  if (c->inc_ns_len)
    len += zx_len_inc_ns(c, &pop_seen);
  len += zx_len_xmlns_if_not_seen(c, zx_ns_tab+zx_xmlns_ix_xa, &pop_seen);


#else
  /* root node has no begin tag */
  int len = 0;
#endif
  
  for (se = x->XPathVersion; se; se = (struct zx_elem_s*)se->g.n)
    len += zx_LEN_SO_simple_elem(c,se, sizeof("xa:XPathVersion")-1, zx_ns_tab+zx_xmlns_ix_xa);


  len += zx_len_so_common(c, &x->gg);
  zx_pop_seen(pop_seen);
  ENC_LEN_DEBUG(x, "xa:PolicyDefaults", len);
  return len;
}

/* FUNC(zx_LEN_WO_xa_PolicyDefaults) */

/* Compute length of an element (and its subelements). The XML attributes
 * and elements are processed in wire order and no assumptions
 * are made about namespace prefixes. */

/* Called by: */
int zx_LEN_WO_xa_PolicyDefaults(struct zx_ctx* c, struct zx_xa_PolicyDefaults_s* x )
{
  struct zx_ns_s* pop_seen = 0;
  struct zx_elem_s* se MAYBE_UNUSED;
#if 1 /* NORMALMODE */
  int len = 1 + sizeof("PolicyDefaults")-1 + 1 + 2 + sizeof("PolicyDefaults")-1 + 1;
  
  if (x->gg.g.ns && x->gg.g.ns->prefix_len)
    len += (x->gg.g.ns->prefix_len + 1) * 2;
  if (c->inc_ns_len)
    len += zx_len_inc_ns(c, &pop_seen);
  len += zx_len_xmlns_if_not_seen(c, x->gg.g.ns, &pop_seen);


#else
  /* root node has no begin tag */
  int len = 0;
#endif
  
  for (se = x->XPathVersion; se; se = (struct zx_elem_s*)se->g.n)
    len += zx_LEN_WO_simple_elem(c, se, sizeof("XPathVersion")-1);


  len += zx_len_wo_common(c, &x->gg); 
  zx_pop_seen(pop_seen);
  ENC_LEN_DEBUG(x, "xa:PolicyDefaults", len);
  return len;
}

/* FUNC(zx_ENC_SO_xa_PolicyDefaults) */

/* Render element into string. The XML attributes and elements are
 * processed in schema order. This is what you generally want for
 * rendering new data structure to a string. The wo pointers are not used. */

/* Called by: */
char* zx_ENC_SO_xa_PolicyDefaults(struct zx_ctx* c, struct zx_xa_PolicyDefaults_s* x, char* p )
{
  struct zx_elem_s* se MAYBE_UNUSED;
  ENC_LEN_DEBUG_BASE;
#if 1 /* NORMALMODE */
  struct zx_ns_s* pop_seen = 0;
  /* *** in simple_elem case should output ns prefix from ns node. */
  ZX_OUT_TAG(p, "<xa:PolicyDefaults");
  if (c->inc_ns)
    p = zx_enc_inc_ns(c, p, &pop_seen);
  p = zx_enc_xmlns_if_not_seen(c, p, zx_ns_tab+zx_xmlns_ix_xa, &pop_seen);


  p = zx_enc_unknown_attrs(p, x->gg.any_attr);
#else
  /* root node has no begin tag */
#endif
  
  for (se = x->XPathVersion; se; se = (struct zx_elem_s*)se->g.n)
    p = zx_ENC_SO_simple_elem(c, se, p, "xa:XPathVersion", sizeof("xa:XPathVersion")-1, zx_ns_tab+zx_xmlns_ix_xa);

  p = zx_enc_so_unknown_elems_and_content(c, p, &x->gg);
  
#if 1 /* NORMALMODE */
  ZX_OUT_CLOSE_TAG(p, "</xa:PolicyDefaults>");
  zx_pop_seen(pop_seen);
#else
  /* root node has no end tag either */
#endif
  ENC_LEN_DEBUG(x, "xa:PolicyDefaults", p-enc_base);
  return p;
}

/* FUNC(zx_ENC_WO_xa_PolicyDefaults) */

/* Render element into string. The XML attributes and elements are
 * processed in wire order by chasing wo pointers. This is what you want for
 * validating signatures on other people's XML documents. */

/* Called by: */
char* zx_ENC_WO_xa_PolicyDefaults(struct zx_ctx* c, struct zx_xa_PolicyDefaults_s* x, char* p )
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
  ZX_OUT_MEM(p, "PolicyDefaults", sizeof("PolicyDefaults")-1);
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
  ENC_LEN_DEBUG(x, "xa:PolicyDefaults", p-enc_base);
  return p;
}

/* FUNC(zx_EASY_ENC_SO_xa_PolicyDefaults) */

/* Called by: */
struct zx_str* zx_EASY_ENC_SO_xa_PolicyDefaults(struct zx_ctx* c, struct zx_xa_PolicyDefaults_s* x )
{
  int len;
  char* buf;
  c->ns_tab = ZX_ALLOC(c, sizeof(zx_ns_tab));
  memcpy(c->ns_tab, zx_ns_tab, sizeof(zx_ns_tab));
  len = zx_LEN_SO_xa_PolicyDefaults(c, x );
  buf = ZX_ALLOC(c, len+1);
  return zx_easy_enc_common(c, zx_ENC_SO_xa_PolicyDefaults(c, x, buf ), buf, len);
}

/* FUNC(zx_EASY_ENC_WO_xa_PolicyDefaults) */

/* Called by: */
struct zx_str* zx_EASY_ENC_WO_xa_PolicyDefaults(struct zx_ctx* c, struct zx_xa_PolicyDefaults_s* x )
{
  int len;
  char* buf;
  c->ns_tab = ZX_ALLOC(c, sizeof(zx_ns_tab));
  memcpy(c->ns_tab, zx_ns_tab, sizeof(zx_ns_tab));
  len = zx_LEN_WO_xa_PolicyDefaults(c, x );
  buf = ZX_ALLOC(c, len+1);
  return zx_easy_enc_common(c, zx_ENC_WO_xa_PolicyDefaults(c, x, buf ), buf, len);
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

#define EL_NAME   xa_PolicyIdReference
#define EL_STRUCT zx_xa_PolicyIdReference_s
#define EL_NS     xa
#define EL_TAG    PolicyIdReference

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

/* FUNC(zx_LEN_SO_xa_PolicyIdReference) */

/* Compute length of an element (and its subelements). The XML attributes
 * and elements are processed in schema order. */

/* Called by: */
int zx_LEN_SO_xa_PolicyIdReference(struct zx_ctx* c, struct zx_xa_PolicyIdReference_s* x )
{
  struct zx_ns_s* pop_seen = 0;
  struct zx_elem_s* se MAYBE_UNUSED;
#if 1 /* NORMALMODE */
  /* *** in simple_elem case should output ns prefix from ns node. */
  int len = sizeof("<xa:PolicyIdReference")-1 + 1 + sizeof("</xa:PolicyIdReference>")-1;
  if (c->inc_ns_len)
    len += zx_len_inc_ns(c, &pop_seen);
  len += zx_len_xmlns_if_not_seen(c, zx_ns_tab+zx_xmlns_ix_xa, &pop_seen);

  len += zx_attr_so_len(x->EarliestVersion, sizeof("EarliestVersion")-1);
  len += zx_attr_so_len(x->LatestVersion, sizeof("LatestVersion")-1);
  len += zx_attr_so_len(x->Version, sizeof("Version")-1);

#else
  /* root node has no begin tag */
  int len = 0;
#endif
  


  len += zx_len_so_common(c, &x->gg);
  zx_pop_seen(pop_seen);
  ENC_LEN_DEBUG(x, "xa:PolicyIdReference", len);
  return len;
}

/* FUNC(zx_LEN_WO_xa_PolicyIdReference) */

/* Compute length of an element (and its subelements). The XML attributes
 * and elements are processed in wire order and no assumptions
 * are made about namespace prefixes. */

/* Called by: */
int zx_LEN_WO_xa_PolicyIdReference(struct zx_ctx* c, struct zx_xa_PolicyIdReference_s* x )
{
  struct zx_ns_s* pop_seen = 0;
  struct zx_elem_s* se MAYBE_UNUSED;
#if 1 /* NORMALMODE */
  int len = 1 + sizeof("PolicyIdReference")-1 + 1 + 2 + sizeof("PolicyIdReference")-1 + 1;
  
  if (x->gg.g.ns && x->gg.g.ns->prefix_len)
    len += (x->gg.g.ns->prefix_len + 1) * 2;
  if (c->inc_ns_len)
    len += zx_len_inc_ns(c, &pop_seen);
  len += zx_len_xmlns_if_not_seen(c, x->gg.g.ns, &pop_seen);

  len += zx_attr_wo_len(x->EarliestVersion, sizeof("EarliestVersion")-1);
  len += zx_attr_wo_len(x->LatestVersion, sizeof("LatestVersion")-1);
  len += zx_attr_wo_len(x->Version, sizeof("Version")-1);

#else
  /* root node has no begin tag */
  int len = 0;
#endif
  


  len += zx_len_wo_common(c, &x->gg); 
  zx_pop_seen(pop_seen);
  ENC_LEN_DEBUG(x, "xa:PolicyIdReference", len);
  return len;
}

/* FUNC(zx_ENC_SO_xa_PolicyIdReference) */

/* Render element into string. The XML attributes and elements are
 * processed in schema order. This is what you generally want for
 * rendering new data structure to a string. The wo pointers are not used. */

/* Called by: */
char* zx_ENC_SO_xa_PolicyIdReference(struct zx_ctx* c, struct zx_xa_PolicyIdReference_s* x, char* p )
{
  struct zx_elem_s* se MAYBE_UNUSED;
  ENC_LEN_DEBUG_BASE;
#if 1 /* NORMALMODE */
  struct zx_ns_s* pop_seen = 0;
  /* *** in simple_elem case should output ns prefix from ns node. */
  ZX_OUT_TAG(p, "<xa:PolicyIdReference");
  if (c->inc_ns)
    p = zx_enc_inc_ns(c, p, &pop_seen);
  p = zx_enc_xmlns_if_not_seen(c, p, zx_ns_tab+zx_xmlns_ix_xa, &pop_seen);

  p = zx_attr_so_enc(p, x->EarliestVersion, " EarliestVersion=\"", sizeof(" EarliestVersion=\"")-1);
  p = zx_attr_so_enc(p, x->LatestVersion, " LatestVersion=\"", sizeof(" LatestVersion=\"")-1);
  p = zx_attr_so_enc(p, x->Version, " Version=\"", sizeof(" Version=\"")-1);

  p = zx_enc_unknown_attrs(p, x->gg.any_attr);
#else
  /* root node has no begin tag */
#endif
  

  p = zx_enc_so_unknown_elems_and_content(c, p, &x->gg);
  
#if 1 /* NORMALMODE */
  ZX_OUT_CLOSE_TAG(p, "</xa:PolicyIdReference>");
  zx_pop_seen(pop_seen);
#else
  /* root node has no end tag either */
#endif
  ENC_LEN_DEBUG(x, "xa:PolicyIdReference", p-enc_base);
  return p;
}

/* FUNC(zx_ENC_WO_xa_PolicyIdReference) */

/* Render element into string. The XML attributes and elements are
 * processed in wire order by chasing wo pointers. This is what you want for
 * validating signatures on other people's XML documents. */

/* Called by: */
char* zx_ENC_WO_xa_PolicyIdReference(struct zx_ctx* c, struct zx_xa_PolicyIdReference_s* x, char* p )
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
  ZX_OUT_MEM(p, "PolicyIdReference", sizeof("PolicyIdReference")-1);
  qq = p;

  /* *** sort the namespaces */
  if (c->inc_ns)
    zx_add_inc_ns(c, &pop_seen);
  zx_add_xmlns_if_not_seen(c, x->gg.g.ns, &pop_seen);

  p = zx_enc_seen(p, pop_seen); 
  p = zx_attr_wo_enc(p, x->EarliestVersion, "EarliestVersion=\"", sizeof("EarliestVersion=\"")-1);
  p = zx_attr_wo_enc(p, x->LatestVersion, "LatestVersion=\"", sizeof("LatestVersion=\"")-1);
  p = zx_attr_wo_enc(p, x->Version, "Version=\"", sizeof("Version=\"")-1);

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
  ENC_LEN_DEBUG(x, "xa:PolicyIdReference", p-enc_base);
  return p;
}

/* FUNC(zx_EASY_ENC_SO_xa_PolicyIdReference) */

/* Called by: */
struct zx_str* zx_EASY_ENC_SO_xa_PolicyIdReference(struct zx_ctx* c, struct zx_xa_PolicyIdReference_s* x )
{
  int len;
  char* buf;
  c->ns_tab = ZX_ALLOC(c, sizeof(zx_ns_tab));
  memcpy(c->ns_tab, zx_ns_tab, sizeof(zx_ns_tab));
  len = zx_LEN_SO_xa_PolicyIdReference(c, x );
  buf = ZX_ALLOC(c, len+1);
  return zx_easy_enc_common(c, zx_ENC_SO_xa_PolicyIdReference(c, x, buf ), buf, len);
}

/* FUNC(zx_EASY_ENC_WO_xa_PolicyIdReference) */

/* Called by: */
struct zx_str* zx_EASY_ENC_WO_xa_PolicyIdReference(struct zx_ctx* c, struct zx_xa_PolicyIdReference_s* x )
{
  int len;
  char* buf;
  c->ns_tab = ZX_ALLOC(c, sizeof(zx_ns_tab));
  memcpy(c->ns_tab, zx_ns_tab, sizeof(zx_ns_tab));
  len = zx_LEN_WO_xa_PolicyIdReference(c, x );
  buf = ZX_ALLOC(c, len+1);
  return zx_easy_enc_common(c, zx_ENC_WO_xa_PolicyIdReference(c, x, buf ), buf, len);
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

#define EL_NAME   xa_PolicySet
#define EL_STRUCT zx_xa_PolicySet_s
#define EL_NS     xa
#define EL_TAG    PolicySet

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

/* FUNC(zx_LEN_SO_xa_PolicySet) */

/* Compute length of an element (and its subelements). The XML attributes
 * and elements are processed in schema order. */

/* Called by: */
int zx_LEN_SO_xa_PolicySet(struct zx_ctx* c, struct zx_xa_PolicySet_s* x )
{
  struct zx_ns_s* pop_seen = 0;
  struct zx_elem_s* se MAYBE_UNUSED;
#if 1 /* NORMALMODE */
  /* *** in simple_elem case should output ns prefix from ns node. */
  int len = sizeof("<xa:PolicySet")-1 + 1 + sizeof("</xa:PolicySet>")-1;
  if (c->inc_ns_len)
    len += zx_len_inc_ns(c, &pop_seen);
  len += zx_len_xmlns_if_not_seen(c, zx_ns_tab+zx_xmlns_ix_xa, &pop_seen);

  len += zx_attr_so_len(x->PolicyCombiningAlgId, sizeof("PolicyCombiningAlgId")-1);
  len += zx_attr_so_len(x->PolicySetId, sizeof("PolicySetId")-1);
  len += zx_attr_so_len(x->Version, sizeof("Version")-1);

#else
  /* root node has no begin tag */
  int len = 0;
#endif
  
  for (se = x->Description; se; se = (struct zx_elem_s*)se->g.n)
    len += zx_LEN_SO_simple_elem(c,se, sizeof("xa:Description")-1, zx_ns_tab+zx_xmlns_ix_xa);
  {
      struct zx_xa_PolicySetDefaults_s* e;
      for (e = x->PolicySetDefaults; e; e = (struct zx_xa_PolicySetDefaults_s*)e->gg.g.n)
	  len += zx_LEN_SO_xa_PolicySetDefaults(c, e);
  }
  {
      struct zx_xa_Target_s* e;
      for (e = x->Target; e; e = (struct zx_xa_Target_s*)e->gg.g.n)
	  len += zx_LEN_SO_xa_Target(c, e);
  }
  {
      struct zx_xa_PolicySet_s* e;
      for (e = x->PolicySet; e; e = (struct zx_xa_PolicySet_s*)e->gg.g.n)
	  len += zx_LEN_SO_xa_PolicySet(c, e);
  }
  {
      struct zx_xa_Policy_s* e;
      for (e = x->Policy; e; e = (struct zx_xa_Policy_s*)e->gg.g.n)
	  len += zx_LEN_SO_xa_Policy(c, e);
  }
  {
      struct zx_xa_PolicySetIdReference_s* e;
      for (e = x->PolicySetIdReference; e; e = (struct zx_xa_PolicySetIdReference_s*)e->gg.g.n)
	  len += zx_LEN_SO_xa_PolicySetIdReference(c, e);
  }
  {
      struct zx_xa_PolicyIdReference_s* e;
      for (e = x->PolicyIdReference; e; e = (struct zx_xa_PolicyIdReference_s*)e->gg.g.n)
	  len += zx_LEN_SO_xa_PolicyIdReference(c, e);
  }
  {
      struct zx_xa_CombinerParameters_s* e;
      for (e = x->CombinerParameters; e; e = (struct zx_xa_CombinerParameters_s*)e->gg.g.n)
	  len += zx_LEN_SO_xa_CombinerParameters(c, e);
  }
  {
      struct zx_xa_PolicyCombinerParameters_s* e;
      for (e = x->PolicyCombinerParameters; e; e = (struct zx_xa_PolicyCombinerParameters_s*)e->gg.g.n)
	  len += zx_LEN_SO_xa_PolicyCombinerParameters(c, e);
  }
  {
      struct zx_xa_PolicySetCombinerParameters_s* e;
      for (e = x->PolicySetCombinerParameters; e; e = (struct zx_xa_PolicySetCombinerParameters_s*)e->gg.g.n)
	  len += zx_LEN_SO_xa_PolicySetCombinerParameters(c, e);
  }
  {
      struct zx_xa_Obligations_s* e;
      for (e = x->Obligations; e; e = (struct zx_xa_Obligations_s*)e->gg.g.n)
	  len += zx_LEN_SO_xa_Obligations(c, e);
  }


  len += zx_len_so_common(c, &x->gg);
  zx_pop_seen(pop_seen);
  ENC_LEN_DEBUG(x, "xa:PolicySet", len);
  return len;
}

/* FUNC(zx_LEN_WO_xa_PolicySet) */

/* Compute length of an element (and its subelements). The XML attributes
 * and elements are processed in wire order and no assumptions
 * are made about namespace prefixes. */

/* Called by: */
int zx_LEN_WO_xa_PolicySet(struct zx_ctx* c, struct zx_xa_PolicySet_s* x )
{
  struct zx_ns_s* pop_seen = 0;
  struct zx_elem_s* se MAYBE_UNUSED;
#if 1 /* NORMALMODE */
  int len = 1 + sizeof("PolicySet")-1 + 1 + 2 + sizeof("PolicySet")-1 + 1;
  
  if (x->gg.g.ns && x->gg.g.ns->prefix_len)
    len += (x->gg.g.ns->prefix_len + 1) * 2;
  if (c->inc_ns_len)
    len += zx_len_inc_ns(c, &pop_seen);
  len += zx_len_xmlns_if_not_seen(c, x->gg.g.ns, &pop_seen);

  len += zx_attr_wo_len(x->PolicyCombiningAlgId, sizeof("PolicyCombiningAlgId")-1);
  len += zx_attr_wo_len(x->PolicySetId, sizeof("PolicySetId")-1);
  len += zx_attr_wo_len(x->Version, sizeof("Version")-1);

#else
  /* root node has no begin tag */
  int len = 0;
#endif
  
  for (se = x->Description; se; se = (struct zx_elem_s*)se->g.n)
    len += zx_LEN_WO_simple_elem(c, se, sizeof("Description")-1);
  {
      struct zx_xa_PolicySetDefaults_s* e;
      for (e = x->PolicySetDefaults; e; e = (struct zx_xa_PolicySetDefaults_s*)e->gg.g.n)
	  len += zx_LEN_WO_xa_PolicySetDefaults(c, e);
  }
  {
      struct zx_xa_Target_s* e;
      for (e = x->Target; e; e = (struct zx_xa_Target_s*)e->gg.g.n)
	  len += zx_LEN_WO_xa_Target(c, e);
  }
  {
      struct zx_xa_PolicySet_s* e;
      for (e = x->PolicySet; e; e = (struct zx_xa_PolicySet_s*)e->gg.g.n)
	  len += zx_LEN_WO_xa_PolicySet(c, e);
  }
  {
      struct zx_xa_Policy_s* e;
      for (e = x->Policy; e; e = (struct zx_xa_Policy_s*)e->gg.g.n)
	  len += zx_LEN_WO_xa_Policy(c, e);
  }
  {
      struct zx_xa_PolicySetIdReference_s* e;
      for (e = x->PolicySetIdReference; e; e = (struct zx_xa_PolicySetIdReference_s*)e->gg.g.n)
	  len += zx_LEN_WO_xa_PolicySetIdReference(c, e);
  }
  {
      struct zx_xa_PolicyIdReference_s* e;
      for (e = x->PolicyIdReference; e; e = (struct zx_xa_PolicyIdReference_s*)e->gg.g.n)
	  len += zx_LEN_WO_xa_PolicyIdReference(c, e);
  }
  {
      struct zx_xa_CombinerParameters_s* e;
      for (e = x->CombinerParameters; e; e = (struct zx_xa_CombinerParameters_s*)e->gg.g.n)
	  len += zx_LEN_WO_xa_CombinerParameters(c, e);
  }
  {
      struct zx_xa_PolicyCombinerParameters_s* e;
      for (e = x->PolicyCombinerParameters; e; e = (struct zx_xa_PolicyCombinerParameters_s*)e->gg.g.n)
	  len += zx_LEN_WO_xa_PolicyCombinerParameters(c, e);
  }
  {
      struct zx_xa_PolicySetCombinerParameters_s* e;
      for (e = x->PolicySetCombinerParameters; e; e = (struct zx_xa_PolicySetCombinerParameters_s*)e->gg.g.n)
	  len += zx_LEN_WO_xa_PolicySetCombinerParameters(c, e);
  }
  {
      struct zx_xa_Obligations_s* e;
      for (e = x->Obligations; e; e = (struct zx_xa_Obligations_s*)e->gg.g.n)
	  len += zx_LEN_WO_xa_Obligations(c, e);
  }


  len += zx_len_wo_common(c, &x->gg); 
  zx_pop_seen(pop_seen);
  ENC_LEN_DEBUG(x, "xa:PolicySet", len);
  return len;
}

/* FUNC(zx_ENC_SO_xa_PolicySet) */

/* Render element into string. The XML attributes and elements are
 * processed in schema order. This is what you generally want for
 * rendering new data structure to a string. The wo pointers are not used. */

/* Called by: */
char* zx_ENC_SO_xa_PolicySet(struct zx_ctx* c, struct zx_xa_PolicySet_s* x, char* p )
{
  struct zx_elem_s* se MAYBE_UNUSED;
  ENC_LEN_DEBUG_BASE;
#if 1 /* NORMALMODE */
  struct zx_ns_s* pop_seen = 0;
  /* *** in simple_elem case should output ns prefix from ns node. */
  ZX_OUT_TAG(p, "<xa:PolicySet");
  if (c->inc_ns)
    p = zx_enc_inc_ns(c, p, &pop_seen);
  p = zx_enc_xmlns_if_not_seen(c, p, zx_ns_tab+zx_xmlns_ix_xa, &pop_seen);

  p = zx_attr_so_enc(p, x->PolicyCombiningAlgId, " PolicyCombiningAlgId=\"", sizeof(" PolicyCombiningAlgId=\"")-1);
  p = zx_attr_so_enc(p, x->PolicySetId, " PolicySetId=\"", sizeof(" PolicySetId=\"")-1);
  p = zx_attr_so_enc(p, x->Version, " Version=\"", sizeof(" Version=\"")-1);

  p = zx_enc_unknown_attrs(p, x->gg.any_attr);
#else
  /* root node has no begin tag */
#endif
  
  for (se = x->Description; se; se = (struct zx_elem_s*)se->g.n)
    p = zx_ENC_SO_simple_elem(c, se, p, "xa:Description", sizeof("xa:Description")-1, zx_ns_tab+zx_xmlns_ix_xa);
  {
      struct zx_xa_PolicySetDefaults_s* e;
      for (e = x->PolicySetDefaults; e; e = (struct zx_xa_PolicySetDefaults_s*)e->gg.g.n)
	  p = zx_ENC_SO_xa_PolicySetDefaults(c, e, p);
  }
  {
      struct zx_xa_Target_s* e;
      for (e = x->Target; e; e = (struct zx_xa_Target_s*)e->gg.g.n)
	  p = zx_ENC_SO_xa_Target(c, e, p);
  }
  {
      struct zx_xa_PolicySet_s* e;
      for (e = x->PolicySet; e; e = (struct zx_xa_PolicySet_s*)e->gg.g.n)
	  p = zx_ENC_SO_xa_PolicySet(c, e, p);
  }
  {
      struct zx_xa_Policy_s* e;
      for (e = x->Policy; e; e = (struct zx_xa_Policy_s*)e->gg.g.n)
	  p = zx_ENC_SO_xa_Policy(c, e, p);
  }
  {
      struct zx_xa_PolicySetIdReference_s* e;
      for (e = x->PolicySetIdReference; e; e = (struct zx_xa_PolicySetIdReference_s*)e->gg.g.n)
	  p = zx_ENC_SO_xa_PolicySetIdReference(c, e, p);
  }
  {
      struct zx_xa_PolicyIdReference_s* e;
      for (e = x->PolicyIdReference; e; e = (struct zx_xa_PolicyIdReference_s*)e->gg.g.n)
	  p = zx_ENC_SO_xa_PolicyIdReference(c, e, p);
  }
  {
      struct zx_xa_CombinerParameters_s* e;
      for (e = x->CombinerParameters; e; e = (struct zx_xa_CombinerParameters_s*)e->gg.g.n)
	  p = zx_ENC_SO_xa_CombinerParameters(c, e, p);
  }
  {
      struct zx_xa_PolicyCombinerParameters_s* e;
      for (e = x->PolicyCombinerParameters; e; e = (struct zx_xa_PolicyCombinerParameters_s*)e->gg.g.n)
	  p = zx_ENC_SO_xa_PolicyCombinerParameters(c, e, p);
  }
  {
      struct zx_xa_PolicySetCombinerParameters_s* e;
      for (e = x->PolicySetCombinerParameters; e; e = (struct zx_xa_PolicySetCombinerParameters_s*)e->gg.g.n)
	  p = zx_ENC_SO_xa_PolicySetCombinerParameters(c, e, p);
  }
  {
      struct zx_xa_Obligations_s* e;
      for (e = x->Obligations; e; e = (struct zx_xa_Obligations_s*)e->gg.g.n)
	  p = zx_ENC_SO_xa_Obligations(c, e, p);
  }

  p = zx_enc_so_unknown_elems_and_content(c, p, &x->gg);
  
#if 1 /* NORMALMODE */
  ZX_OUT_CLOSE_TAG(p, "</xa:PolicySet>");
  zx_pop_seen(pop_seen);
#else
  /* root node has no end tag either */
#endif
  ENC_LEN_DEBUG(x, "xa:PolicySet", p-enc_base);
  return p;
}

/* FUNC(zx_ENC_WO_xa_PolicySet) */

/* Render element into string. The XML attributes and elements are
 * processed in wire order by chasing wo pointers. This is what you want for
 * validating signatures on other people's XML documents. */

/* Called by: */
char* zx_ENC_WO_xa_PolicySet(struct zx_ctx* c, struct zx_xa_PolicySet_s* x, char* p )
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
  ZX_OUT_MEM(p, "PolicySet", sizeof("PolicySet")-1);
  qq = p;

  /* *** sort the namespaces */
  if (c->inc_ns)
    zx_add_inc_ns(c, &pop_seen);
  zx_add_xmlns_if_not_seen(c, x->gg.g.ns, &pop_seen);

  p = zx_enc_seen(p, pop_seen); 
  p = zx_attr_wo_enc(p, x->PolicyCombiningAlgId, "PolicyCombiningAlgId=\"", sizeof("PolicyCombiningAlgId=\"")-1);
  p = zx_attr_wo_enc(p, x->PolicySetId, "PolicySetId=\"", sizeof("PolicySetId=\"")-1);
  p = zx_attr_wo_enc(p, x->Version, "Version=\"", sizeof("Version=\"")-1);

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
  ENC_LEN_DEBUG(x, "xa:PolicySet", p-enc_base);
  return p;
}

/* FUNC(zx_EASY_ENC_SO_xa_PolicySet) */

/* Called by: */
struct zx_str* zx_EASY_ENC_SO_xa_PolicySet(struct zx_ctx* c, struct zx_xa_PolicySet_s* x )
{
  int len;
  char* buf;
  c->ns_tab = ZX_ALLOC(c, sizeof(zx_ns_tab));
  memcpy(c->ns_tab, zx_ns_tab, sizeof(zx_ns_tab));
  len = zx_LEN_SO_xa_PolicySet(c, x );
  buf = ZX_ALLOC(c, len+1);
  return zx_easy_enc_common(c, zx_ENC_SO_xa_PolicySet(c, x, buf ), buf, len);
}

/* FUNC(zx_EASY_ENC_WO_xa_PolicySet) */

/* Called by: */
struct zx_str* zx_EASY_ENC_WO_xa_PolicySet(struct zx_ctx* c, struct zx_xa_PolicySet_s* x )
{
  int len;
  char* buf;
  c->ns_tab = ZX_ALLOC(c, sizeof(zx_ns_tab));
  memcpy(c->ns_tab, zx_ns_tab, sizeof(zx_ns_tab));
  len = zx_LEN_WO_xa_PolicySet(c, x );
  buf = ZX_ALLOC(c, len+1);
  return zx_easy_enc_common(c, zx_ENC_WO_xa_PolicySet(c, x, buf ), buf, len);
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

#define EL_NAME   xa_PolicySetCombinerParameters
#define EL_STRUCT zx_xa_PolicySetCombinerParameters_s
#define EL_NS     xa
#define EL_TAG    PolicySetCombinerParameters

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

/* FUNC(zx_LEN_SO_xa_PolicySetCombinerParameters) */

/* Compute length of an element (and its subelements). The XML attributes
 * and elements are processed in schema order. */

/* Called by: */
int zx_LEN_SO_xa_PolicySetCombinerParameters(struct zx_ctx* c, struct zx_xa_PolicySetCombinerParameters_s* x )
{
  struct zx_ns_s* pop_seen = 0;
  struct zx_elem_s* se MAYBE_UNUSED;
#if 1 /* NORMALMODE */
  /* *** in simple_elem case should output ns prefix from ns node. */
  int len = sizeof("<xa:PolicySetCombinerParameters")-1 + 1 + sizeof("</xa:PolicySetCombinerParameters>")-1;
  if (c->inc_ns_len)
    len += zx_len_inc_ns(c, &pop_seen);
  len += zx_len_xmlns_if_not_seen(c, zx_ns_tab+zx_xmlns_ix_xa, &pop_seen);

  len += zx_attr_so_len(x->PolicySetIdRef, sizeof("PolicySetIdRef")-1);

#else
  /* root node has no begin tag */
  int len = 0;
#endif
  
  {
      struct zx_xa_CombinerParameter_s* e;
      for (e = x->CombinerParameter; e; e = (struct zx_xa_CombinerParameter_s*)e->gg.g.n)
	  len += zx_LEN_SO_xa_CombinerParameter(c, e);
  }


  len += zx_len_so_common(c, &x->gg);
  zx_pop_seen(pop_seen);
  ENC_LEN_DEBUG(x, "xa:PolicySetCombinerParameters", len);
  return len;
}

/* FUNC(zx_LEN_WO_xa_PolicySetCombinerParameters) */

/* Compute length of an element (and its subelements). The XML attributes
 * and elements are processed in wire order and no assumptions
 * are made about namespace prefixes. */

/* Called by: */
int zx_LEN_WO_xa_PolicySetCombinerParameters(struct zx_ctx* c, struct zx_xa_PolicySetCombinerParameters_s* x )
{
  struct zx_ns_s* pop_seen = 0;
  struct zx_elem_s* se MAYBE_UNUSED;
#if 1 /* NORMALMODE */
  int len = 1 + sizeof("PolicySetCombinerParameters")-1 + 1 + 2 + sizeof("PolicySetCombinerParameters")-1 + 1;
  
  if (x->gg.g.ns && x->gg.g.ns->prefix_len)
    len += (x->gg.g.ns->prefix_len + 1) * 2;
  if (c->inc_ns_len)
    len += zx_len_inc_ns(c, &pop_seen);
  len += zx_len_xmlns_if_not_seen(c, x->gg.g.ns, &pop_seen);

  len += zx_attr_wo_len(x->PolicySetIdRef, sizeof("PolicySetIdRef")-1);

#else
  /* root node has no begin tag */
  int len = 0;
#endif
  
  {
      struct zx_xa_CombinerParameter_s* e;
      for (e = x->CombinerParameter; e; e = (struct zx_xa_CombinerParameter_s*)e->gg.g.n)
	  len += zx_LEN_WO_xa_CombinerParameter(c, e);
  }


  len += zx_len_wo_common(c, &x->gg); 
  zx_pop_seen(pop_seen);
  ENC_LEN_DEBUG(x, "xa:PolicySetCombinerParameters", len);
  return len;
}

/* FUNC(zx_ENC_SO_xa_PolicySetCombinerParameters) */

/* Render element into string. The XML attributes and elements are
 * processed in schema order. This is what you generally want for
 * rendering new data structure to a string. The wo pointers are not used. */

/* Called by: */
char* zx_ENC_SO_xa_PolicySetCombinerParameters(struct zx_ctx* c, struct zx_xa_PolicySetCombinerParameters_s* x, char* p )
{
  struct zx_elem_s* se MAYBE_UNUSED;
  ENC_LEN_DEBUG_BASE;
#if 1 /* NORMALMODE */
  struct zx_ns_s* pop_seen = 0;
  /* *** in simple_elem case should output ns prefix from ns node. */
  ZX_OUT_TAG(p, "<xa:PolicySetCombinerParameters");
  if (c->inc_ns)
    p = zx_enc_inc_ns(c, p, &pop_seen);
  p = zx_enc_xmlns_if_not_seen(c, p, zx_ns_tab+zx_xmlns_ix_xa, &pop_seen);

  p = zx_attr_so_enc(p, x->PolicySetIdRef, " PolicySetIdRef=\"", sizeof(" PolicySetIdRef=\"")-1);

  p = zx_enc_unknown_attrs(p, x->gg.any_attr);
#else
  /* root node has no begin tag */
#endif
  
  {
      struct zx_xa_CombinerParameter_s* e;
      for (e = x->CombinerParameter; e; e = (struct zx_xa_CombinerParameter_s*)e->gg.g.n)
	  p = zx_ENC_SO_xa_CombinerParameter(c, e, p);
  }

  p = zx_enc_so_unknown_elems_and_content(c, p, &x->gg);
  
#if 1 /* NORMALMODE */
  ZX_OUT_CLOSE_TAG(p, "</xa:PolicySetCombinerParameters>");
  zx_pop_seen(pop_seen);
#else
  /* root node has no end tag either */
#endif
  ENC_LEN_DEBUG(x, "xa:PolicySetCombinerParameters", p-enc_base);
  return p;
}

/* FUNC(zx_ENC_WO_xa_PolicySetCombinerParameters) */

/* Render element into string. The XML attributes and elements are
 * processed in wire order by chasing wo pointers. This is what you want for
 * validating signatures on other people's XML documents. */

/* Called by: */
char* zx_ENC_WO_xa_PolicySetCombinerParameters(struct zx_ctx* c, struct zx_xa_PolicySetCombinerParameters_s* x, char* p )
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
  ZX_OUT_MEM(p, "PolicySetCombinerParameters", sizeof("PolicySetCombinerParameters")-1);
  qq = p;

  /* *** sort the namespaces */
  if (c->inc_ns)
    zx_add_inc_ns(c, &pop_seen);
  zx_add_xmlns_if_not_seen(c, x->gg.g.ns, &pop_seen);

  p = zx_enc_seen(p, pop_seen); 
  p = zx_attr_wo_enc(p, x->PolicySetIdRef, "PolicySetIdRef=\"", sizeof("PolicySetIdRef=\"")-1);

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
  ENC_LEN_DEBUG(x, "xa:PolicySetCombinerParameters", p-enc_base);
  return p;
}

/* FUNC(zx_EASY_ENC_SO_xa_PolicySetCombinerParameters) */

/* Called by: */
struct zx_str* zx_EASY_ENC_SO_xa_PolicySetCombinerParameters(struct zx_ctx* c, struct zx_xa_PolicySetCombinerParameters_s* x )
{
  int len;
  char* buf;
  c->ns_tab = ZX_ALLOC(c, sizeof(zx_ns_tab));
  memcpy(c->ns_tab, zx_ns_tab, sizeof(zx_ns_tab));
  len = zx_LEN_SO_xa_PolicySetCombinerParameters(c, x );
  buf = ZX_ALLOC(c, len+1);
  return zx_easy_enc_common(c, zx_ENC_SO_xa_PolicySetCombinerParameters(c, x, buf ), buf, len);
}

/* FUNC(zx_EASY_ENC_WO_xa_PolicySetCombinerParameters) */

/* Called by: */
struct zx_str* zx_EASY_ENC_WO_xa_PolicySetCombinerParameters(struct zx_ctx* c, struct zx_xa_PolicySetCombinerParameters_s* x )
{
  int len;
  char* buf;
  c->ns_tab = ZX_ALLOC(c, sizeof(zx_ns_tab));
  memcpy(c->ns_tab, zx_ns_tab, sizeof(zx_ns_tab));
  len = zx_LEN_WO_xa_PolicySetCombinerParameters(c, x );
  buf = ZX_ALLOC(c, len+1);
  return zx_easy_enc_common(c, zx_ENC_WO_xa_PolicySetCombinerParameters(c, x, buf ), buf, len);
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

#define EL_NAME   xa_PolicySetDefaults
#define EL_STRUCT zx_xa_PolicySetDefaults_s
#define EL_NS     xa
#define EL_TAG    PolicySetDefaults

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

/* FUNC(zx_LEN_SO_xa_PolicySetDefaults) */

/* Compute length of an element (and its subelements). The XML attributes
 * and elements are processed in schema order. */

/* Called by: */
int zx_LEN_SO_xa_PolicySetDefaults(struct zx_ctx* c, struct zx_xa_PolicySetDefaults_s* x )
{
  struct zx_ns_s* pop_seen = 0;
  struct zx_elem_s* se MAYBE_UNUSED;
#if 1 /* NORMALMODE */
  /* *** in simple_elem case should output ns prefix from ns node. */
  int len = sizeof("<xa:PolicySetDefaults")-1 + 1 + sizeof("</xa:PolicySetDefaults>")-1;
  if (c->inc_ns_len)
    len += zx_len_inc_ns(c, &pop_seen);
  len += zx_len_xmlns_if_not_seen(c, zx_ns_tab+zx_xmlns_ix_xa, &pop_seen);


#else
  /* root node has no begin tag */
  int len = 0;
#endif
  
  for (se = x->XPathVersion; se; se = (struct zx_elem_s*)se->g.n)
    len += zx_LEN_SO_simple_elem(c,se, sizeof("xa:XPathVersion")-1, zx_ns_tab+zx_xmlns_ix_xa);


  len += zx_len_so_common(c, &x->gg);
  zx_pop_seen(pop_seen);
  ENC_LEN_DEBUG(x, "xa:PolicySetDefaults", len);
  return len;
}

/* FUNC(zx_LEN_WO_xa_PolicySetDefaults) */

/* Compute length of an element (and its subelements). The XML attributes
 * and elements are processed in wire order and no assumptions
 * are made about namespace prefixes. */

/* Called by: */
int zx_LEN_WO_xa_PolicySetDefaults(struct zx_ctx* c, struct zx_xa_PolicySetDefaults_s* x )
{
  struct zx_ns_s* pop_seen = 0;
  struct zx_elem_s* se MAYBE_UNUSED;
#if 1 /* NORMALMODE */
  int len = 1 + sizeof("PolicySetDefaults")-1 + 1 + 2 + sizeof("PolicySetDefaults")-1 + 1;
  
  if (x->gg.g.ns && x->gg.g.ns->prefix_len)
    len += (x->gg.g.ns->prefix_len + 1) * 2;
  if (c->inc_ns_len)
    len += zx_len_inc_ns(c, &pop_seen);
  len += zx_len_xmlns_if_not_seen(c, x->gg.g.ns, &pop_seen);


#else
  /* root node has no begin tag */
  int len = 0;
#endif
  
  for (se = x->XPathVersion; se; se = (struct zx_elem_s*)se->g.n)
    len += zx_LEN_WO_simple_elem(c, se, sizeof("XPathVersion")-1);


  len += zx_len_wo_common(c, &x->gg); 
  zx_pop_seen(pop_seen);
  ENC_LEN_DEBUG(x, "xa:PolicySetDefaults", len);
  return len;
}

/* FUNC(zx_ENC_SO_xa_PolicySetDefaults) */

/* Render element into string. The XML attributes and elements are
 * processed in schema order. This is what you generally want for
 * rendering new data structure to a string. The wo pointers are not used. */

/* Called by: */
char* zx_ENC_SO_xa_PolicySetDefaults(struct zx_ctx* c, struct zx_xa_PolicySetDefaults_s* x, char* p )
{
  struct zx_elem_s* se MAYBE_UNUSED;
  ENC_LEN_DEBUG_BASE;
#if 1 /* NORMALMODE */
  struct zx_ns_s* pop_seen = 0;
  /* *** in simple_elem case should output ns prefix from ns node. */
  ZX_OUT_TAG(p, "<xa:PolicySetDefaults");
  if (c->inc_ns)
    p = zx_enc_inc_ns(c, p, &pop_seen);
  p = zx_enc_xmlns_if_not_seen(c, p, zx_ns_tab+zx_xmlns_ix_xa, &pop_seen);


  p = zx_enc_unknown_attrs(p, x->gg.any_attr);
#else
  /* root node has no begin tag */
#endif
  
  for (se = x->XPathVersion; se; se = (struct zx_elem_s*)se->g.n)
    p = zx_ENC_SO_simple_elem(c, se, p, "xa:XPathVersion", sizeof("xa:XPathVersion")-1, zx_ns_tab+zx_xmlns_ix_xa);

  p = zx_enc_so_unknown_elems_and_content(c, p, &x->gg);
  
#if 1 /* NORMALMODE */
  ZX_OUT_CLOSE_TAG(p, "</xa:PolicySetDefaults>");
  zx_pop_seen(pop_seen);
#else
  /* root node has no end tag either */
#endif
  ENC_LEN_DEBUG(x, "xa:PolicySetDefaults", p-enc_base);
  return p;
}

/* FUNC(zx_ENC_WO_xa_PolicySetDefaults) */

/* Render element into string. The XML attributes and elements are
 * processed in wire order by chasing wo pointers. This is what you want for
 * validating signatures on other people's XML documents. */

/* Called by: */
char* zx_ENC_WO_xa_PolicySetDefaults(struct zx_ctx* c, struct zx_xa_PolicySetDefaults_s* x, char* p )
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
  ZX_OUT_MEM(p, "PolicySetDefaults", sizeof("PolicySetDefaults")-1);
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
  ENC_LEN_DEBUG(x, "xa:PolicySetDefaults", p-enc_base);
  return p;
}

/* FUNC(zx_EASY_ENC_SO_xa_PolicySetDefaults) */

/* Called by: */
struct zx_str* zx_EASY_ENC_SO_xa_PolicySetDefaults(struct zx_ctx* c, struct zx_xa_PolicySetDefaults_s* x )
{
  int len;
  char* buf;
  c->ns_tab = ZX_ALLOC(c, sizeof(zx_ns_tab));
  memcpy(c->ns_tab, zx_ns_tab, sizeof(zx_ns_tab));
  len = zx_LEN_SO_xa_PolicySetDefaults(c, x );
  buf = ZX_ALLOC(c, len+1);
  return zx_easy_enc_common(c, zx_ENC_SO_xa_PolicySetDefaults(c, x, buf ), buf, len);
}

/* FUNC(zx_EASY_ENC_WO_xa_PolicySetDefaults) */

/* Called by: */
struct zx_str* zx_EASY_ENC_WO_xa_PolicySetDefaults(struct zx_ctx* c, struct zx_xa_PolicySetDefaults_s* x )
{
  int len;
  char* buf;
  c->ns_tab = ZX_ALLOC(c, sizeof(zx_ns_tab));
  memcpy(c->ns_tab, zx_ns_tab, sizeof(zx_ns_tab));
  len = zx_LEN_WO_xa_PolicySetDefaults(c, x );
  buf = ZX_ALLOC(c, len+1);
  return zx_easy_enc_common(c, zx_ENC_WO_xa_PolicySetDefaults(c, x, buf ), buf, len);
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

#define EL_NAME   xa_PolicySetIdReference
#define EL_STRUCT zx_xa_PolicySetIdReference_s
#define EL_NS     xa
#define EL_TAG    PolicySetIdReference

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

/* FUNC(zx_LEN_SO_xa_PolicySetIdReference) */

/* Compute length of an element (and its subelements). The XML attributes
 * and elements are processed in schema order. */

/* Called by: */
int zx_LEN_SO_xa_PolicySetIdReference(struct zx_ctx* c, struct zx_xa_PolicySetIdReference_s* x )
{
  struct zx_ns_s* pop_seen = 0;
  struct zx_elem_s* se MAYBE_UNUSED;
#if 1 /* NORMALMODE */
  /* *** in simple_elem case should output ns prefix from ns node. */
  int len = sizeof("<xa:PolicySetIdReference")-1 + 1 + sizeof("</xa:PolicySetIdReference>")-1;
  if (c->inc_ns_len)
    len += zx_len_inc_ns(c, &pop_seen);
  len += zx_len_xmlns_if_not_seen(c, zx_ns_tab+zx_xmlns_ix_xa, &pop_seen);

  len += zx_attr_so_len(x->EarliestVersion, sizeof("EarliestVersion")-1);
  len += zx_attr_so_len(x->LatestVersion, sizeof("LatestVersion")-1);
  len += zx_attr_so_len(x->Version, sizeof("Version")-1);

#else
  /* root node has no begin tag */
  int len = 0;
#endif
  


  len += zx_len_so_common(c, &x->gg);
  zx_pop_seen(pop_seen);
  ENC_LEN_DEBUG(x, "xa:PolicySetIdReference", len);
  return len;
}

/* FUNC(zx_LEN_WO_xa_PolicySetIdReference) */

/* Compute length of an element (and its subelements). The XML attributes
 * and elements are processed in wire order and no assumptions
 * are made about namespace prefixes. */

/* Called by: */
int zx_LEN_WO_xa_PolicySetIdReference(struct zx_ctx* c, struct zx_xa_PolicySetIdReference_s* x )
{
  struct zx_ns_s* pop_seen = 0;
  struct zx_elem_s* se MAYBE_UNUSED;
#if 1 /* NORMALMODE */
  int len = 1 + sizeof("PolicySetIdReference")-1 + 1 + 2 + sizeof("PolicySetIdReference")-1 + 1;
  
  if (x->gg.g.ns && x->gg.g.ns->prefix_len)
    len += (x->gg.g.ns->prefix_len + 1) * 2;
  if (c->inc_ns_len)
    len += zx_len_inc_ns(c, &pop_seen);
  len += zx_len_xmlns_if_not_seen(c, x->gg.g.ns, &pop_seen);

  len += zx_attr_wo_len(x->EarliestVersion, sizeof("EarliestVersion")-1);
  len += zx_attr_wo_len(x->LatestVersion, sizeof("LatestVersion")-1);
  len += zx_attr_wo_len(x->Version, sizeof("Version")-1);

#else
  /* root node has no begin tag */
  int len = 0;
#endif
  


  len += zx_len_wo_common(c, &x->gg); 
  zx_pop_seen(pop_seen);
  ENC_LEN_DEBUG(x, "xa:PolicySetIdReference", len);
  return len;
}

/* FUNC(zx_ENC_SO_xa_PolicySetIdReference) */

/* Render element into string. The XML attributes and elements are
 * processed in schema order. This is what you generally want for
 * rendering new data structure to a string. The wo pointers are not used. */

/* Called by: */
char* zx_ENC_SO_xa_PolicySetIdReference(struct zx_ctx* c, struct zx_xa_PolicySetIdReference_s* x, char* p )
{
  struct zx_elem_s* se MAYBE_UNUSED;
  ENC_LEN_DEBUG_BASE;
#if 1 /* NORMALMODE */
  struct zx_ns_s* pop_seen = 0;
  /* *** in simple_elem case should output ns prefix from ns node. */
  ZX_OUT_TAG(p, "<xa:PolicySetIdReference");
  if (c->inc_ns)
    p = zx_enc_inc_ns(c, p, &pop_seen);
  p = zx_enc_xmlns_if_not_seen(c, p, zx_ns_tab+zx_xmlns_ix_xa, &pop_seen);

  p = zx_attr_so_enc(p, x->EarliestVersion, " EarliestVersion=\"", sizeof(" EarliestVersion=\"")-1);
  p = zx_attr_so_enc(p, x->LatestVersion, " LatestVersion=\"", sizeof(" LatestVersion=\"")-1);
  p = zx_attr_so_enc(p, x->Version, " Version=\"", sizeof(" Version=\"")-1);

  p = zx_enc_unknown_attrs(p, x->gg.any_attr);
#else
  /* root node has no begin tag */
#endif
  

  p = zx_enc_so_unknown_elems_and_content(c, p, &x->gg);
  
#if 1 /* NORMALMODE */
  ZX_OUT_CLOSE_TAG(p, "</xa:PolicySetIdReference>");
  zx_pop_seen(pop_seen);
#else
  /* root node has no end tag either */
#endif
  ENC_LEN_DEBUG(x, "xa:PolicySetIdReference", p-enc_base);
  return p;
}

/* FUNC(zx_ENC_WO_xa_PolicySetIdReference) */

/* Render element into string. The XML attributes and elements are
 * processed in wire order by chasing wo pointers. This is what you want for
 * validating signatures on other people's XML documents. */

/* Called by: */
char* zx_ENC_WO_xa_PolicySetIdReference(struct zx_ctx* c, struct zx_xa_PolicySetIdReference_s* x, char* p )
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
  ZX_OUT_MEM(p, "PolicySetIdReference", sizeof("PolicySetIdReference")-1);
  qq = p;

  /* *** sort the namespaces */
  if (c->inc_ns)
    zx_add_inc_ns(c, &pop_seen);
  zx_add_xmlns_if_not_seen(c, x->gg.g.ns, &pop_seen);

  p = zx_enc_seen(p, pop_seen); 
  p = zx_attr_wo_enc(p, x->EarliestVersion, "EarliestVersion=\"", sizeof("EarliestVersion=\"")-1);
  p = zx_attr_wo_enc(p, x->LatestVersion, "LatestVersion=\"", sizeof("LatestVersion=\"")-1);
  p = zx_attr_wo_enc(p, x->Version, "Version=\"", sizeof("Version=\"")-1);

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
  ENC_LEN_DEBUG(x, "xa:PolicySetIdReference", p-enc_base);
  return p;
}

/* FUNC(zx_EASY_ENC_SO_xa_PolicySetIdReference) */

/* Called by: */
struct zx_str* zx_EASY_ENC_SO_xa_PolicySetIdReference(struct zx_ctx* c, struct zx_xa_PolicySetIdReference_s* x )
{
  int len;
  char* buf;
  c->ns_tab = ZX_ALLOC(c, sizeof(zx_ns_tab));
  memcpy(c->ns_tab, zx_ns_tab, sizeof(zx_ns_tab));
  len = zx_LEN_SO_xa_PolicySetIdReference(c, x );
  buf = ZX_ALLOC(c, len+1);
  return zx_easy_enc_common(c, zx_ENC_SO_xa_PolicySetIdReference(c, x, buf ), buf, len);
}

/* FUNC(zx_EASY_ENC_WO_xa_PolicySetIdReference) */

/* Called by: */
struct zx_str* zx_EASY_ENC_WO_xa_PolicySetIdReference(struct zx_ctx* c, struct zx_xa_PolicySetIdReference_s* x )
{
  int len;
  char* buf;
  c->ns_tab = ZX_ALLOC(c, sizeof(zx_ns_tab));
  memcpy(c->ns_tab, zx_ns_tab, sizeof(zx_ns_tab));
  len = zx_LEN_WO_xa_PolicySetIdReference(c, x );
  buf = ZX_ALLOC(c, len+1);
  return zx_easy_enc_common(c, zx_ENC_WO_xa_PolicySetIdReference(c, x, buf ), buf, len);
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

#define EL_NAME   xa_Resource
#define EL_STRUCT zx_xa_Resource_s
#define EL_NS     xa
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

/* FUNC(zx_LEN_SO_xa_Resource) */

/* Compute length of an element (and its subelements). The XML attributes
 * and elements are processed in schema order. */

/* Called by: */
int zx_LEN_SO_xa_Resource(struct zx_ctx* c, struct zx_xa_Resource_s* x )
{
  struct zx_ns_s* pop_seen = 0;
  struct zx_elem_s* se MAYBE_UNUSED;
#if 1 /* NORMALMODE */
  /* *** in simple_elem case should output ns prefix from ns node. */
  int len = sizeof("<xa:Resource")-1 + 1 + sizeof("</xa:Resource>")-1;
  if (c->inc_ns_len)
    len += zx_len_inc_ns(c, &pop_seen);
  len += zx_len_xmlns_if_not_seen(c, zx_ns_tab+zx_xmlns_ix_xa, &pop_seen);


#else
  /* root node has no begin tag */
  int len = 0;
#endif
  
  {
      struct zx_xa_ResourceMatch_s* e;
      for (e = x->ResourceMatch; e; e = (struct zx_xa_ResourceMatch_s*)e->gg.g.n)
	  len += zx_LEN_SO_xa_ResourceMatch(c, e);
  }


  len += zx_len_so_common(c, &x->gg);
  zx_pop_seen(pop_seen);
  ENC_LEN_DEBUG(x, "xa:Resource", len);
  return len;
}

/* FUNC(zx_LEN_WO_xa_Resource) */

/* Compute length of an element (and its subelements). The XML attributes
 * and elements are processed in wire order and no assumptions
 * are made about namespace prefixes. */

/* Called by: */
int zx_LEN_WO_xa_Resource(struct zx_ctx* c, struct zx_xa_Resource_s* x )
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
      struct zx_xa_ResourceMatch_s* e;
      for (e = x->ResourceMatch; e; e = (struct zx_xa_ResourceMatch_s*)e->gg.g.n)
	  len += zx_LEN_WO_xa_ResourceMatch(c, e);
  }


  len += zx_len_wo_common(c, &x->gg); 
  zx_pop_seen(pop_seen);
  ENC_LEN_DEBUG(x, "xa:Resource", len);
  return len;
}

/* FUNC(zx_ENC_SO_xa_Resource) */

/* Render element into string. The XML attributes and elements are
 * processed in schema order. This is what you generally want for
 * rendering new data structure to a string. The wo pointers are not used. */

/* Called by: */
char* zx_ENC_SO_xa_Resource(struct zx_ctx* c, struct zx_xa_Resource_s* x, char* p )
{
  struct zx_elem_s* se MAYBE_UNUSED;
  ENC_LEN_DEBUG_BASE;
#if 1 /* NORMALMODE */
  struct zx_ns_s* pop_seen = 0;
  /* *** in simple_elem case should output ns prefix from ns node. */
  ZX_OUT_TAG(p, "<xa:Resource");
  if (c->inc_ns)
    p = zx_enc_inc_ns(c, p, &pop_seen);
  p = zx_enc_xmlns_if_not_seen(c, p, zx_ns_tab+zx_xmlns_ix_xa, &pop_seen);


  p = zx_enc_unknown_attrs(p, x->gg.any_attr);
#else
  /* root node has no begin tag */
#endif
  
  {
      struct zx_xa_ResourceMatch_s* e;
      for (e = x->ResourceMatch; e; e = (struct zx_xa_ResourceMatch_s*)e->gg.g.n)
	  p = zx_ENC_SO_xa_ResourceMatch(c, e, p);
  }

  p = zx_enc_so_unknown_elems_and_content(c, p, &x->gg);
  
#if 1 /* NORMALMODE */
  ZX_OUT_CLOSE_TAG(p, "</xa:Resource>");
  zx_pop_seen(pop_seen);
#else
  /* root node has no end tag either */
#endif
  ENC_LEN_DEBUG(x, "xa:Resource", p-enc_base);
  return p;
}

/* FUNC(zx_ENC_WO_xa_Resource) */

/* Render element into string. The XML attributes and elements are
 * processed in wire order by chasing wo pointers. This is what you want for
 * validating signatures on other people's XML documents. */

/* Called by: */
char* zx_ENC_WO_xa_Resource(struct zx_ctx* c, struct zx_xa_Resource_s* x, char* p )
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
  ZX_OUT_MEM(p, "Resource", sizeof("Resource")-1);
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
  ENC_LEN_DEBUG(x, "xa:Resource", p-enc_base);
  return p;
}

/* FUNC(zx_EASY_ENC_SO_xa_Resource) */

/* Called by: */
struct zx_str* zx_EASY_ENC_SO_xa_Resource(struct zx_ctx* c, struct zx_xa_Resource_s* x )
{
  int len;
  char* buf;
  c->ns_tab = ZX_ALLOC(c, sizeof(zx_ns_tab));
  memcpy(c->ns_tab, zx_ns_tab, sizeof(zx_ns_tab));
  len = zx_LEN_SO_xa_Resource(c, x );
  buf = ZX_ALLOC(c, len+1);
  return zx_easy_enc_common(c, zx_ENC_SO_xa_Resource(c, x, buf ), buf, len);
}

/* FUNC(zx_EASY_ENC_WO_xa_Resource) */

/* Called by: */
struct zx_str* zx_EASY_ENC_WO_xa_Resource(struct zx_ctx* c, struct zx_xa_Resource_s* x )
{
  int len;
  char* buf;
  c->ns_tab = ZX_ALLOC(c, sizeof(zx_ns_tab));
  memcpy(c->ns_tab, zx_ns_tab, sizeof(zx_ns_tab));
  len = zx_LEN_WO_xa_Resource(c, x );
  buf = ZX_ALLOC(c, len+1);
  return zx_easy_enc_common(c, zx_ENC_WO_xa_Resource(c, x, buf ), buf, len);
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

#define EL_NAME   xa_ResourceAttributeDesignator
#define EL_STRUCT zx_xa_ResourceAttributeDesignator_s
#define EL_NS     xa
#define EL_TAG    ResourceAttributeDesignator

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

/* FUNC(zx_LEN_SO_xa_ResourceAttributeDesignator) */

/* Compute length of an element (and its subelements). The XML attributes
 * and elements are processed in schema order. */

/* Called by: */
int zx_LEN_SO_xa_ResourceAttributeDesignator(struct zx_ctx* c, struct zx_xa_ResourceAttributeDesignator_s* x )
{
  struct zx_ns_s* pop_seen = 0;
  struct zx_elem_s* se MAYBE_UNUSED;
#if 1 /* NORMALMODE */
  /* *** in simple_elem case should output ns prefix from ns node. */
  int len = sizeof("<xa:ResourceAttributeDesignator")-1 + 1 + sizeof("</xa:ResourceAttributeDesignator>")-1;
  if (c->inc_ns_len)
    len += zx_len_inc_ns(c, &pop_seen);
  len += zx_len_xmlns_if_not_seen(c, zx_ns_tab+zx_xmlns_ix_xa, &pop_seen);

  len += zx_attr_so_len(x->AttributeId, sizeof("AttributeId")-1);
  len += zx_attr_so_len(x->DataType, sizeof("DataType")-1);
  len += zx_attr_so_len(x->Issuer, sizeof("Issuer")-1);
  len += zx_attr_so_len(x->MustBePresent, sizeof("MustBePresent")-1);

#else
  /* root node has no begin tag */
  int len = 0;
#endif
  


  len += zx_len_so_common(c, &x->gg);
  zx_pop_seen(pop_seen);
  ENC_LEN_DEBUG(x, "xa:ResourceAttributeDesignator", len);
  return len;
}

/* FUNC(zx_LEN_WO_xa_ResourceAttributeDesignator) */

/* Compute length of an element (and its subelements). The XML attributes
 * and elements are processed in wire order and no assumptions
 * are made about namespace prefixes. */

/* Called by: */
int zx_LEN_WO_xa_ResourceAttributeDesignator(struct zx_ctx* c, struct zx_xa_ResourceAttributeDesignator_s* x )
{
  struct zx_ns_s* pop_seen = 0;
  struct zx_elem_s* se MAYBE_UNUSED;
#if 1 /* NORMALMODE */
  int len = 1 + sizeof("ResourceAttributeDesignator")-1 + 1 + 2 + sizeof("ResourceAttributeDesignator")-1 + 1;
  
  if (x->gg.g.ns && x->gg.g.ns->prefix_len)
    len += (x->gg.g.ns->prefix_len + 1) * 2;
  if (c->inc_ns_len)
    len += zx_len_inc_ns(c, &pop_seen);
  len += zx_len_xmlns_if_not_seen(c, x->gg.g.ns, &pop_seen);

  len += zx_attr_wo_len(x->AttributeId, sizeof("AttributeId")-1);
  len += zx_attr_wo_len(x->DataType, sizeof("DataType")-1);
  len += zx_attr_wo_len(x->Issuer, sizeof("Issuer")-1);
  len += zx_attr_wo_len(x->MustBePresent, sizeof("MustBePresent")-1);

#else
  /* root node has no begin tag */
  int len = 0;
#endif
  


  len += zx_len_wo_common(c, &x->gg); 
  zx_pop_seen(pop_seen);
  ENC_LEN_DEBUG(x, "xa:ResourceAttributeDesignator", len);
  return len;
}

/* FUNC(zx_ENC_SO_xa_ResourceAttributeDesignator) */

/* Render element into string. The XML attributes and elements are
 * processed in schema order. This is what you generally want for
 * rendering new data structure to a string. The wo pointers are not used. */

/* Called by: */
char* zx_ENC_SO_xa_ResourceAttributeDesignator(struct zx_ctx* c, struct zx_xa_ResourceAttributeDesignator_s* x, char* p )
{
  struct zx_elem_s* se MAYBE_UNUSED;
  ENC_LEN_DEBUG_BASE;
#if 1 /* NORMALMODE */
  struct zx_ns_s* pop_seen = 0;
  /* *** in simple_elem case should output ns prefix from ns node. */
  ZX_OUT_TAG(p, "<xa:ResourceAttributeDesignator");
  if (c->inc_ns)
    p = zx_enc_inc_ns(c, p, &pop_seen);
  p = zx_enc_xmlns_if_not_seen(c, p, zx_ns_tab+zx_xmlns_ix_xa, &pop_seen);

  p = zx_attr_so_enc(p, x->AttributeId, " AttributeId=\"", sizeof(" AttributeId=\"")-1);
  p = zx_attr_so_enc(p, x->DataType, " DataType=\"", sizeof(" DataType=\"")-1);
  p = zx_attr_so_enc(p, x->Issuer, " Issuer=\"", sizeof(" Issuer=\"")-1);
  p = zx_attr_so_enc(p, x->MustBePresent, " MustBePresent=\"", sizeof(" MustBePresent=\"")-1);

  p = zx_enc_unknown_attrs(p, x->gg.any_attr);
#else
  /* root node has no begin tag */
#endif
  

  p = zx_enc_so_unknown_elems_and_content(c, p, &x->gg);
  
#if 1 /* NORMALMODE */
  ZX_OUT_CLOSE_TAG(p, "</xa:ResourceAttributeDesignator>");
  zx_pop_seen(pop_seen);
#else
  /* root node has no end tag either */
#endif
  ENC_LEN_DEBUG(x, "xa:ResourceAttributeDesignator", p-enc_base);
  return p;
}

/* FUNC(zx_ENC_WO_xa_ResourceAttributeDesignator) */

/* Render element into string. The XML attributes and elements are
 * processed in wire order by chasing wo pointers. This is what you want for
 * validating signatures on other people's XML documents. */

/* Called by: */
char* zx_ENC_WO_xa_ResourceAttributeDesignator(struct zx_ctx* c, struct zx_xa_ResourceAttributeDesignator_s* x, char* p )
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
  ZX_OUT_MEM(p, "ResourceAttributeDesignator", sizeof("ResourceAttributeDesignator")-1);
  qq = p;

  /* *** sort the namespaces */
  if (c->inc_ns)
    zx_add_inc_ns(c, &pop_seen);
  zx_add_xmlns_if_not_seen(c, x->gg.g.ns, &pop_seen);

  p = zx_enc_seen(p, pop_seen); 
  p = zx_attr_wo_enc(p, x->AttributeId, "AttributeId=\"", sizeof("AttributeId=\"")-1);
  p = zx_attr_wo_enc(p, x->DataType, "DataType=\"", sizeof("DataType=\"")-1);
  p = zx_attr_wo_enc(p, x->Issuer, "Issuer=\"", sizeof("Issuer=\"")-1);
  p = zx_attr_wo_enc(p, x->MustBePresent, "MustBePresent=\"", sizeof("MustBePresent=\"")-1);

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
  ENC_LEN_DEBUG(x, "xa:ResourceAttributeDesignator", p-enc_base);
  return p;
}

/* FUNC(zx_EASY_ENC_SO_xa_ResourceAttributeDesignator) */

/* Called by: */
struct zx_str* zx_EASY_ENC_SO_xa_ResourceAttributeDesignator(struct zx_ctx* c, struct zx_xa_ResourceAttributeDesignator_s* x )
{
  int len;
  char* buf;
  c->ns_tab = ZX_ALLOC(c, sizeof(zx_ns_tab));
  memcpy(c->ns_tab, zx_ns_tab, sizeof(zx_ns_tab));
  len = zx_LEN_SO_xa_ResourceAttributeDesignator(c, x );
  buf = ZX_ALLOC(c, len+1);
  return zx_easy_enc_common(c, zx_ENC_SO_xa_ResourceAttributeDesignator(c, x, buf ), buf, len);
}

/* FUNC(zx_EASY_ENC_WO_xa_ResourceAttributeDesignator) */

/* Called by: */
struct zx_str* zx_EASY_ENC_WO_xa_ResourceAttributeDesignator(struct zx_ctx* c, struct zx_xa_ResourceAttributeDesignator_s* x )
{
  int len;
  char* buf;
  c->ns_tab = ZX_ALLOC(c, sizeof(zx_ns_tab));
  memcpy(c->ns_tab, zx_ns_tab, sizeof(zx_ns_tab));
  len = zx_LEN_WO_xa_ResourceAttributeDesignator(c, x );
  buf = ZX_ALLOC(c, len+1);
  return zx_easy_enc_common(c, zx_ENC_WO_xa_ResourceAttributeDesignator(c, x, buf ), buf, len);
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

#define EL_NAME   xa_ResourceMatch
#define EL_STRUCT zx_xa_ResourceMatch_s
#define EL_NS     xa
#define EL_TAG    ResourceMatch

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

/* FUNC(zx_LEN_SO_xa_ResourceMatch) */

/* Compute length of an element (and its subelements). The XML attributes
 * and elements are processed in schema order. */

/* Called by: */
int zx_LEN_SO_xa_ResourceMatch(struct zx_ctx* c, struct zx_xa_ResourceMatch_s* x )
{
  struct zx_ns_s* pop_seen = 0;
  struct zx_elem_s* se MAYBE_UNUSED;
#if 1 /* NORMALMODE */
  /* *** in simple_elem case should output ns prefix from ns node. */
  int len = sizeof("<xa:ResourceMatch")-1 + 1 + sizeof("</xa:ResourceMatch>")-1;
  if (c->inc_ns_len)
    len += zx_len_inc_ns(c, &pop_seen);
  len += zx_len_xmlns_if_not_seen(c, zx_ns_tab+zx_xmlns_ix_xa, &pop_seen);

  len += zx_attr_so_len(x->MatchId, sizeof("MatchId")-1);

#else
  /* root node has no begin tag */
  int len = 0;
#endif
  
  {
      struct zx_xa_AttributeValue_s* e;
      for (e = x->AttributeValue; e; e = (struct zx_xa_AttributeValue_s*)e->gg.g.n)
	  len += zx_LEN_SO_xa_AttributeValue(c, e);
  }
  {
      struct zx_xa_ResourceAttributeDesignator_s* e;
      for (e = x->ResourceAttributeDesignator; e; e = (struct zx_xa_ResourceAttributeDesignator_s*)e->gg.g.n)
	  len += zx_LEN_SO_xa_ResourceAttributeDesignator(c, e);
  }
  {
      struct zx_xa_AttributeSelector_s* e;
      for (e = x->AttributeSelector; e; e = (struct zx_xa_AttributeSelector_s*)e->gg.g.n)
	  len += zx_LEN_SO_xa_AttributeSelector(c, e);
  }


  len += zx_len_so_common(c, &x->gg);
  zx_pop_seen(pop_seen);
  ENC_LEN_DEBUG(x, "xa:ResourceMatch", len);
  return len;
}

/* FUNC(zx_LEN_WO_xa_ResourceMatch) */

/* Compute length of an element (and its subelements). The XML attributes
 * and elements are processed in wire order and no assumptions
 * are made about namespace prefixes. */

/* Called by: */
int zx_LEN_WO_xa_ResourceMatch(struct zx_ctx* c, struct zx_xa_ResourceMatch_s* x )
{
  struct zx_ns_s* pop_seen = 0;
  struct zx_elem_s* se MAYBE_UNUSED;
#if 1 /* NORMALMODE */
  int len = 1 + sizeof("ResourceMatch")-1 + 1 + 2 + sizeof("ResourceMatch")-1 + 1;
  
  if (x->gg.g.ns && x->gg.g.ns->prefix_len)
    len += (x->gg.g.ns->prefix_len + 1) * 2;
  if (c->inc_ns_len)
    len += zx_len_inc_ns(c, &pop_seen);
  len += zx_len_xmlns_if_not_seen(c, x->gg.g.ns, &pop_seen);

  len += zx_attr_wo_len(x->MatchId, sizeof("MatchId")-1);

#else
  /* root node has no begin tag */
  int len = 0;
#endif
  
  {
      struct zx_xa_AttributeValue_s* e;
      for (e = x->AttributeValue; e; e = (struct zx_xa_AttributeValue_s*)e->gg.g.n)
	  len += zx_LEN_WO_xa_AttributeValue(c, e);
  }
  {
      struct zx_xa_ResourceAttributeDesignator_s* e;
      for (e = x->ResourceAttributeDesignator; e; e = (struct zx_xa_ResourceAttributeDesignator_s*)e->gg.g.n)
	  len += zx_LEN_WO_xa_ResourceAttributeDesignator(c, e);
  }
  {
      struct zx_xa_AttributeSelector_s* e;
      for (e = x->AttributeSelector; e; e = (struct zx_xa_AttributeSelector_s*)e->gg.g.n)
	  len += zx_LEN_WO_xa_AttributeSelector(c, e);
  }


  len += zx_len_wo_common(c, &x->gg); 
  zx_pop_seen(pop_seen);
  ENC_LEN_DEBUG(x, "xa:ResourceMatch", len);
  return len;
}

/* FUNC(zx_ENC_SO_xa_ResourceMatch) */

/* Render element into string. The XML attributes and elements are
 * processed in schema order. This is what you generally want for
 * rendering new data structure to a string. The wo pointers are not used. */

/* Called by: */
char* zx_ENC_SO_xa_ResourceMatch(struct zx_ctx* c, struct zx_xa_ResourceMatch_s* x, char* p )
{
  struct zx_elem_s* se MAYBE_UNUSED;
  ENC_LEN_DEBUG_BASE;
#if 1 /* NORMALMODE */
  struct zx_ns_s* pop_seen = 0;
  /* *** in simple_elem case should output ns prefix from ns node. */
  ZX_OUT_TAG(p, "<xa:ResourceMatch");
  if (c->inc_ns)
    p = zx_enc_inc_ns(c, p, &pop_seen);
  p = zx_enc_xmlns_if_not_seen(c, p, zx_ns_tab+zx_xmlns_ix_xa, &pop_seen);

  p = zx_attr_so_enc(p, x->MatchId, " MatchId=\"", sizeof(" MatchId=\"")-1);

  p = zx_enc_unknown_attrs(p, x->gg.any_attr);
#else
  /* root node has no begin tag */
#endif
  
  {
      struct zx_xa_AttributeValue_s* e;
      for (e = x->AttributeValue; e; e = (struct zx_xa_AttributeValue_s*)e->gg.g.n)
	  p = zx_ENC_SO_xa_AttributeValue(c, e, p);
  }
  {
      struct zx_xa_ResourceAttributeDesignator_s* e;
      for (e = x->ResourceAttributeDesignator; e; e = (struct zx_xa_ResourceAttributeDesignator_s*)e->gg.g.n)
	  p = zx_ENC_SO_xa_ResourceAttributeDesignator(c, e, p);
  }
  {
      struct zx_xa_AttributeSelector_s* e;
      for (e = x->AttributeSelector; e; e = (struct zx_xa_AttributeSelector_s*)e->gg.g.n)
	  p = zx_ENC_SO_xa_AttributeSelector(c, e, p);
  }

  p = zx_enc_so_unknown_elems_and_content(c, p, &x->gg);
  
#if 1 /* NORMALMODE */
  ZX_OUT_CLOSE_TAG(p, "</xa:ResourceMatch>");
  zx_pop_seen(pop_seen);
#else
  /* root node has no end tag either */
#endif
  ENC_LEN_DEBUG(x, "xa:ResourceMatch", p-enc_base);
  return p;
}

/* FUNC(zx_ENC_WO_xa_ResourceMatch) */

/* Render element into string. The XML attributes and elements are
 * processed in wire order by chasing wo pointers. This is what you want for
 * validating signatures on other people's XML documents. */

/* Called by: */
char* zx_ENC_WO_xa_ResourceMatch(struct zx_ctx* c, struct zx_xa_ResourceMatch_s* x, char* p )
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
  ZX_OUT_MEM(p, "ResourceMatch", sizeof("ResourceMatch")-1);
  qq = p;

  /* *** sort the namespaces */
  if (c->inc_ns)
    zx_add_inc_ns(c, &pop_seen);
  zx_add_xmlns_if_not_seen(c, x->gg.g.ns, &pop_seen);

  p = zx_enc_seen(p, pop_seen); 
  p = zx_attr_wo_enc(p, x->MatchId, "MatchId=\"", sizeof("MatchId=\"")-1);

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
  ENC_LEN_DEBUG(x, "xa:ResourceMatch", p-enc_base);
  return p;
}

/* FUNC(zx_EASY_ENC_SO_xa_ResourceMatch) */

/* Called by: */
struct zx_str* zx_EASY_ENC_SO_xa_ResourceMatch(struct zx_ctx* c, struct zx_xa_ResourceMatch_s* x )
{
  int len;
  char* buf;
  c->ns_tab = ZX_ALLOC(c, sizeof(zx_ns_tab));
  memcpy(c->ns_tab, zx_ns_tab, sizeof(zx_ns_tab));
  len = zx_LEN_SO_xa_ResourceMatch(c, x );
  buf = ZX_ALLOC(c, len+1);
  return zx_easy_enc_common(c, zx_ENC_SO_xa_ResourceMatch(c, x, buf ), buf, len);
}

/* FUNC(zx_EASY_ENC_WO_xa_ResourceMatch) */

/* Called by: */
struct zx_str* zx_EASY_ENC_WO_xa_ResourceMatch(struct zx_ctx* c, struct zx_xa_ResourceMatch_s* x )
{
  int len;
  char* buf;
  c->ns_tab = ZX_ALLOC(c, sizeof(zx_ns_tab));
  memcpy(c->ns_tab, zx_ns_tab, sizeof(zx_ns_tab));
  len = zx_LEN_WO_xa_ResourceMatch(c, x );
  buf = ZX_ALLOC(c, len+1);
  return zx_easy_enc_common(c, zx_ENC_WO_xa_ResourceMatch(c, x, buf ), buf, len);
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

#define EL_NAME   xa_Resources
#define EL_STRUCT zx_xa_Resources_s
#define EL_NS     xa
#define EL_TAG    Resources

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

/* FUNC(zx_LEN_SO_xa_Resources) */

/* Compute length of an element (and its subelements). The XML attributes
 * and elements are processed in schema order. */

/* Called by: */
int zx_LEN_SO_xa_Resources(struct zx_ctx* c, struct zx_xa_Resources_s* x )
{
  struct zx_ns_s* pop_seen = 0;
  struct zx_elem_s* se MAYBE_UNUSED;
#if 1 /* NORMALMODE */
  /* *** in simple_elem case should output ns prefix from ns node. */
  int len = sizeof("<xa:Resources")-1 + 1 + sizeof("</xa:Resources>")-1;
  if (c->inc_ns_len)
    len += zx_len_inc_ns(c, &pop_seen);
  len += zx_len_xmlns_if_not_seen(c, zx_ns_tab+zx_xmlns_ix_xa, &pop_seen);


#else
  /* root node has no begin tag */
  int len = 0;
#endif
  
  {
      struct zx_xa_Resource_s* e;
      for (e = x->Resource; e; e = (struct zx_xa_Resource_s*)e->gg.g.n)
	  len += zx_LEN_SO_xa_Resource(c, e);
  }


  len += zx_len_so_common(c, &x->gg);
  zx_pop_seen(pop_seen);
  ENC_LEN_DEBUG(x, "xa:Resources", len);
  return len;
}

/* FUNC(zx_LEN_WO_xa_Resources) */

/* Compute length of an element (and its subelements). The XML attributes
 * and elements are processed in wire order and no assumptions
 * are made about namespace prefixes. */

/* Called by: */
int zx_LEN_WO_xa_Resources(struct zx_ctx* c, struct zx_xa_Resources_s* x )
{
  struct zx_ns_s* pop_seen = 0;
  struct zx_elem_s* se MAYBE_UNUSED;
#if 1 /* NORMALMODE */
  int len = 1 + sizeof("Resources")-1 + 1 + 2 + sizeof("Resources")-1 + 1;
  
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
      struct zx_xa_Resource_s* e;
      for (e = x->Resource; e; e = (struct zx_xa_Resource_s*)e->gg.g.n)
	  len += zx_LEN_WO_xa_Resource(c, e);
  }


  len += zx_len_wo_common(c, &x->gg); 
  zx_pop_seen(pop_seen);
  ENC_LEN_DEBUG(x, "xa:Resources", len);
  return len;
}

/* FUNC(zx_ENC_SO_xa_Resources) */

/* Render element into string. The XML attributes and elements are
 * processed in schema order. This is what you generally want for
 * rendering new data structure to a string. The wo pointers are not used. */

/* Called by: */
char* zx_ENC_SO_xa_Resources(struct zx_ctx* c, struct zx_xa_Resources_s* x, char* p )
{
  struct zx_elem_s* se MAYBE_UNUSED;
  ENC_LEN_DEBUG_BASE;
#if 1 /* NORMALMODE */
  struct zx_ns_s* pop_seen = 0;
  /* *** in simple_elem case should output ns prefix from ns node. */
  ZX_OUT_TAG(p, "<xa:Resources");
  if (c->inc_ns)
    p = zx_enc_inc_ns(c, p, &pop_seen);
  p = zx_enc_xmlns_if_not_seen(c, p, zx_ns_tab+zx_xmlns_ix_xa, &pop_seen);


  p = zx_enc_unknown_attrs(p, x->gg.any_attr);
#else
  /* root node has no begin tag */
#endif
  
  {
      struct zx_xa_Resource_s* e;
      for (e = x->Resource; e; e = (struct zx_xa_Resource_s*)e->gg.g.n)
	  p = zx_ENC_SO_xa_Resource(c, e, p);
  }

  p = zx_enc_so_unknown_elems_and_content(c, p, &x->gg);
  
#if 1 /* NORMALMODE */
  ZX_OUT_CLOSE_TAG(p, "</xa:Resources>");
  zx_pop_seen(pop_seen);
#else
  /* root node has no end tag either */
#endif
  ENC_LEN_DEBUG(x, "xa:Resources", p-enc_base);
  return p;
}

/* FUNC(zx_ENC_WO_xa_Resources) */

/* Render element into string. The XML attributes and elements are
 * processed in wire order by chasing wo pointers. This is what you want for
 * validating signatures on other people's XML documents. */

/* Called by: */
char* zx_ENC_WO_xa_Resources(struct zx_ctx* c, struct zx_xa_Resources_s* x, char* p )
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
  ZX_OUT_MEM(p, "Resources", sizeof("Resources")-1);
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
  ENC_LEN_DEBUG(x, "xa:Resources", p-enc_base);
  return p;
}

/* FUNC(zx_EASY_ENC_SO_xa_Resources) */

/* Called by: */
struct zx_str* zx_EASY_ENC_SO_xa_Resources(struct zx_ctx* c, struct zx_xa_Resources_s* x )
{
  int len;
  char* buf;
  c->ns_tab = ZX_ALLOC(c, sizeof(zx_ns_tab));
  memcpy(c->ns_tab, zx_ns_tab, sizeof(zx_ns_tab));
  len = zx_LEN_SO_xa_Resources(c, x );
  buf = ZX_ALLOC(c, len+1);
  return zx_easy_enc_common(c, zx_ENC_SO_xa_Resources(c, x, buf ), buf, len);
}

/* FUNC(zx_EASY_ENC_WO_xa_Resources) */

/* Called by: */
struct zx_str* zx_EASY_ENC_WO_xa_Resources(struct zx_ctx* c, struct zx_xa_Resources_s* x )
{
  int len;
  char* buf;
  c->ns_tab = ZX_ALLOC(c, sizeof(zx_ns_tab));
  memcpy(c->ns_tab, zx_ns_tab, sizeof(zx_ns_tab));
  len = zx_LEN_WO_xa_Resources(c, x );
  buf = ZX_ALLOC(c, len+1);
  return zx_easy_enc_common(c, zx_ENC_WO_xa_Resources(c, x, buf ), buf, len);
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

#define EL_NAME   xa_Rule
#define EL_STRUCT zx_xa_Rule_s
#define EL_NS     xa
#define EL_TAG    Rule

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

/* FUNC(zx_LEN_SO_xa_Rule) */

/* Compute length of an element (and its subelements). The XML attributes
 * and elements are processed in schema order. */

/* Called by: */
int zx_LEN_SO_xa_Rule(struct zx_ctx* c, struct zx_xa_Rule_s* x )
{
  struct zx_ns_s* pop_seen = 0;
  struct zx_elem_s* se MAYBE_UNUSED;
#if 1 /* NORMALMODE */
  /* *** in simple_elem case should output ns prefix from ns node. */
  int len = sizeof("<xa:Rule")-1 + 1 + sizeof("</xa:Rule>")-1;
  if (c->inc_ns_len)
    len += zx_len_inc_ns(c, &pop_seen);
  len += zx_len_xmlns_if_not_seen(c, zx_ns_tab+zx_xmlns_ix_xa, &pop_seen);

  len += zx_attr_so_len(x->Effect, sizeof("Effect")-1);
  len += zx_attr_so_len(x->RuleId, sizeof("RuleId")-1);

#else
  /* root node has no begin tag */
  int len = 0;
#endif
  
  for (se = x->Description; se; se = (struct zx_elem_s*)se->g.n)
    len += zx_LEN_SO_simple_elem(c,se, sizeof("xa:Description")-1, zx_ns_tab+zx_xmlns_ix_xa);
  {
      struct zx_xa_Target_s* e;
      for (e = x->Target; e; e = (struct zx_xa_Target_s*)e->gg.g.n)
	  len += zx_LEN_SO_xa_Target(c, e);
  }
  {
      struct zx_xa_Condition_s* e;
      for (e = x->Condition; e; e = (struct zx_xa_Condition_s*)e->gg.g.n)
	  len += zx_LEN_SO_xa_Condition(c, e);
  }


  len += zx_len_so_common(c, &x->gg);
  zx_pop_seen(pop_seen);
  ENC_LEN_DEBUG(x, "xa:Rule", len);
  return len;
}

/* FUNC(zx_LEN_WO_xa_Rule) */

/* Compute length of an element (and its subelements). The XML attributes
 * and elements are processed in wire order and no assumptions
 * are made about namespace prefixes. */

/* Called by: */
int zx_LEN_WO_xa_Rule(struct zx_ctx* c, struct zx_xa_Rule_s* x )
{
  struct zx_ns_s* pop_seen = 0;
  struct zx_elem_s* se MAYBE_UNUSED;
#if 1 /* NORMALMODE */
  int len = 1 + sizeof("Rule")-1 + 1 + 2 + sizeof("Rule")-1 + 1;
  
  if (x->gg.g.ns && x->gg.g.ns->prefix_len)
    len += (x->gg.g.ns->prefix_len + 1) * 2;
  if (c->inc_ns_len)
    len += zx_len_inc_ns(c, &pop_seen);
  len += zx_len_xmlns_if_not_seen(c, x->gg.g.ns, &pop_seen);

  len += zx_attr_wo_len(x->Effect, sizeof("Effect")-1);
  len += zx_attr_wo_len(x->RuleId, sizeof("RuleId")-1);

#else
  /* root node has no begin tag */
  int len = 0;
#endif
  
  for (se = x->Description; se; se = (struct zx_elem_s*)se->g.n)
    len += zx_LEN_WO_simple_elem(c, se, sizeof("Description")-1);
  {
      struct zx_xa_Target_s* e;
      for (e = x->Target; e; e = (struct zx_xa_Target_s*)e->gg.g.n)
	  len += zx_LEN_WO_xa_Target(c, e);
  }
  {
      struct zx_xa_Condition_s* e;
      for (e = x->Condition; e; e = (struct zx_xa_Condition_s*)e->gg.g.n)
	  len += zx_LEN_WO_xa_Condition(c, e);
  }


  len += zx_len_wo_common(c, &x->gg); 
  zx_pop_seen(pop_seen);
  ENC_LEN_DEBUG(x, "xa:Rule", len);
  return len;
}

/* FUNC(zx_ENC_SO_xa_Rule) */

/* Render element into string. The XML attributes and elements are
 * processed in schema order. This is what you generally want for
 * rendering new data structure to a string. The wo pointers are not used. */

/* Called by: */
char* zx_ENC_SO_xa_Rule(struct zx_ctx* c, struct zx_xa_Rule_s* x, char* p )
{
  struct zx_elem_s* se MAYBE_UNUSED;
  ENC_LEN_DEBUG_BASE;
#if 1 /* NORMALMODE */
  struct zx_ns_s* pop_seen = 0;
  /* *** in simple_elem case should output ns prefix from ns node. */
  ZX_OUT_TAG(p, "<xa:Rule");
  if (c->inc_ns)
    p = zx_enc_inc_ns(c, p, &pop_seen);
  p = zx_enc_xmlns_if_not_seen(c, p, zx_ns_tab+zx_xmlns_ix_xa, &pop_seen);

  p = zx_attr_so_enc(p, x->Effect, " Effect=\"", sizeof(" Effect=\"")-1);
  p = zx_attr_so_enc(p, x->RuleId, " RuleId=\"", sizeof(" RuleId=\"")-1);

  p = zx_enc_unknown_attrs(p, x->gg.any_attr);
#else
  /* root node has no begin tag */
#endif
  
  for (se = x->Description; se; se = (struct zx_elem_s*)se->g.n)
    p = zx_ENC_SO_simple_elem(c, se, p, "xa:Description", sizeof("xa:Description")-1, zx_ns_tab+zx_xmlns_ix_xa);
  {
      struct zx_xa_Target_s* e;
      for (e = x->Target; e; e = (struct zx_xa_Target_s*)e->gg.g.n)
	  p = zx_ENC_SO_xa_Target(c, e, p);
  }
  {
      struct zx_xa_Condition_s* e;
      for (e = x->Condition; e; e = (struct zx_xa_Condition_s*)e->gg.g.n)
	  p = zx_ENC_SO_xa_Condition(c, e, p);
  }

  p = zx_enc_so_unknown_elems_and_content(c, p, &x->gg);
  
#if 1 /* NORMALMODE */
  ZX_OUT_CLOSE_TAG(p, "</xa:Rule>");
  zx_pop_seen(pop_seen);
#else
  /* root node has no end tag either */
#endif
  ENC_LEN_DEBUG(x, "xa:Rule", p-enc_base);
  return p;
}

/* FUNC(zx_ENC_WO_xa_Rule) */

/* Render element into string. The XML attributes and elements are
 * processed in wire order by chasing wo pointers. This is what you want for
 * validating signatures on other people's XML documents. */

/* Called by: */
char* zx_ENC_WO_xa_Rule(struct zx_ctx* c, struct zx_xa_Rule_s* x, char* p )
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
  ZX_OUT_MEM(p, "Rule", sizeof("Rule")-1);
  qq = p;

  /* *** sort the namespaces */
  if (c->inc_ns)
    zx_add_inc_ns(c, &pop_seen);
  zx_add_xmlns_if_not_seen(c, x->gg.g.ns, &pop_seen);

  p = zx_enc_seen(p, pop_seen); 
  p = zx_attr_wo_enc(p, x->Effect, "Effect=\"", sizeof("Effect=\"")-1);
  p = zx_attr_wo_enc(p, x->RuleId, "RuleId=\"", sizeof("RuleId=\"")-1);

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
  ENC_LEN_DEBUG(x, "xa:Rule", p-enc_base);
  return p;
}

/* FUNC(zx_EASY_ENC_SO_xa_Rule) */

/* Called by: */
struct zx_str* zx_EASY_ENC_SO_xa_Rule(struct zx_ctx* c, struct zx_xa_Rule_s* x )
{
  int len;
  char* buf;
  c->ns_tab = ZX_ALLOC(c, sizeof(zx_ns_tab));
  memcpy(c->ns_tab, zx_ns_tab, sizeof(zx_ns_tab));
  len = zx_LEN_SO_xa_Rule(c, x );
  buf = ZX_ALLOC(c, len+1);
  return zx_easy_enc_common(c, zx_ENC_SO_xa_Rule(c, x, buf ), buf, len);
}

/* FUNC(zx_EASY_ENC_WO_xa_Rule) */

/* Called by: */
struct zx_str* zx_EASY_ENC_WO_xa_Rule(struct zx_ctx* c, struct zx_xa_Rule_s* x )
{
  int len;
  char* buf;
  c->ns_tab = ZX_ALLOC(c, sizeof(zx_ns_tab));
  memcpy(c->ns_tab, zx_ns_tab, sizeof(zx_ns_tab));
  len = zx_LEN_WO_xa_Rule(c, x );
  buf = ZX_ALLOC(c, len+1);
  return zx_easy_enc_common(c, zx_ENC_WO_xa_Rule(c, x, buf ), buf, len);
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

#define EL_NAME   xa_RuleCombinerParameters
#define EL_STRUCT zx_xa_RuleCombinerParameters_s
#define EL_NS     xa
#define EL_TAG    RuleCombinerParameters

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

/* FUNC(zx_LEN_SO_xa_RuleCombinerParameters) */

/* Compute length of an element (and its subelements). The XML attributes
 * and elements are processed in schema order. */

/* Called by: */
int zx_LEN_SO_xa_RuleCombinerParameters(struct zx_ctx* c, struct zx_xa_RuleCombinerParameters_s* x )
{
  struct zx_ns_s* pop_seen = 0;
  struct zx_elem_s* se MAYBE_UNUSED;
#if 1 /* NORMALMODE */
  /* *** in simple_elem case should output ns prefix from ns node. */
  int len = sizeof("<xa:RuleCombinerParameters")-1 + 1 + sizeof("</xa:RuleCombinerParameters>")-1;
  if (c->inc_ns_len)
    len += zx_len_inc_ns(c, &pop_seen);
  len += zx_len_xmlns_if_not_seen(c, zx_ns_tab+zx_xmlns_ix_xa, &pop_seen);

  len += zx_attr_so_len(x->RuleIdRef, sizeof("RuleIdRef")-1);

#else
  /* root node has no begin tag */
  int len = 0;
#endif
  
  {
      struct zx_xa_CombinerParameter_s* e;
      for (e = x->CombinerParameter; e; e = (struct zx_xa_CombinerParameter_s*)e->gg.g.n)
	  len += zx_LEN_SO_xa_CombinerParameter(c, e);
  }


  len += zx_len_so_common(c, &x->gg);
  zx_pop_seen(pop_seen);
  ENC_LEN_DEBUG(x, "xa:RuleCombinerParameters", len);
  return len;
}

/* FUNC(zx_LEN_WO_xa_RuleCombinerParameters) */

/* Compute length of an element (and its subelements). The XML attributes
 * and elements are processed in wire order and no assumptions
 * are made about namespace prefixes. */

/* Called by: */
int zx_LEN_WO_xa_RuleCombinerParameters(struct zx_ctx* c, struct zx_xa_RuleCombinerParameters_s* x )
{
  struct zx_ns_s* pop_seen = 0;
  struct zx_elem_s* se MAYBE_UNUSED;
#if 1 /* NORMALMODE */
  int len = 1 + sizeof("RuleCombinerParameters")-1 + 1 + 2 + sizeof("RuleCombinerParameters")-1 + 1;
  
  if (x->gg.g.ns && x->gg.g.ns->prefix_len)
    len += (x->gg.g.ns->prefix_len + 1) * 2;
  if (c->inc_ns_len)
    len += zx_len_inc_ns(c, &pop_seen);
  len += zx_len_xmlns_if_not_seen(c, x->gg.g.ns, &pop_seen);

  len += zx_attr_wo_len(x->RuleIdRef, sizeof("RuleIdRef")-1);

#else
  /* root node has no begin tag */
  int len = 0;
#endif
  
  {
      struct zx_xa_CombinerParameter_s* e;
      for (e = x->CombinerParameter; e; e = (struct zx_xa_CombinerParameter_s*)e->gg.g.n)
	  len += zx_LEN_WO_xa_CombinerParameter(c, e);
  }


  len += zx_len_wo_common(c, &x->gg); 
  zx_pop_seen(pop_seen);
  ENC_LEN_DEBUG(x, "xa:RuleCombinerParameters", len);
  return len;
}

/* FUNC(zx_ENC_SO_xa_RuleCombinerParameters) */

/* Render element into string. The XML attributes and elements are
 * processed in schema order. This is what you generally want for
 * rendering new data structure to a string. The wo pointers are not used. */

/* Called by: */
char* zx_ENC_SO_xa_RuleCombinerParameters(struct zx_ctx* c, struct zx_xa_RuleCombinerParameters_s* x, char* p )
{
  struct zx_elem_s* se MAYBE_UNUSED;
  ENC_LEN_DEBUG_BASE;
#if 1 /* NORMALMODE */
  struct zx_ns_s* pop_seen = 0;
  /* *** in simple_elem case should output ns prefix from ns node. */
  ZX_OUT_TAG(p, "<xa:RuleCombinerParameters");
  if (c->inc_ns)
    p = zx_enc_inc_ns(c, p, &pop_seen);
  p = zx_enc_xmlns_if_not_seen(c, p, zx_ns_tab+zx_xmlns_ix_xa, &pop_seen);

  p = zx_attr_so_enc(p, x->RuleIdRef, " RuleIdRef=\"", sizeof(" RuleIdRef=\"")-1);

  p = zx_enc_unknown_attrs(p, x->gg.any_attr);
#else
  /* root node has no begin tag */
#endif
  
  {
      struct zx_xa_CombinerParameter_s* e;
      for (e = x->CombinerParameter; e; e = (struct zx_xa_CombinerParameter_s*)e->gg.g.n)
	  p = zx_ENC_SO_xa_CombinerParameter(c, e, p);
  }

  p = zx_enc_so_unknown_elems_and_content(c, p, &x->gg);
  
#if 1 /* NORMALMODE */
  ZX_OUT_CLOSE_TAG(p, "</xa:RuleCombinerParameters>");
  zx_pop_seen(pop_seen);
#else
  /* root node has no end tag either */
#endif
  ENC_LEN_DEBUG(x, "xa:RuleCombinerParameters", p-enc_base);
  return p;
}

/* FUNC(zx_ENC_WO_xa_RuleCombinerParameters) */

/* Render element into string. The XML attributes and elements are
 * processed in wire order by chasing wo pointers. This is what you want for
 * validating signatures on other people's XML documents. */

/* Called by: */
char* zx_ENC_WO_xa_RuleCombinerParameters(struct zx_ctx* c, struct zx_xa_RuleCombinerParameters_s* x, char* p )
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
  ZX_OUT_MEM(p, "RuleCombinerParameters", sizeof("RuleCombinerParameters")-1);
  qq = p;

  /* *** sort the namespaces */
  if (c->inc_ns)
    zx_add_inc_ns(c, &pop_seen);
  zx_add_xmlns_if_not_seen(c, x->gg.g.ns, &pop_seen);

  p = zx_enc_seen(p, pop_seen); 
  p = zx_attr_wo_enc(p, x->RuleIdRef, "RuleIdRef=\"", sizeof("RuleIdRef=\"")-1);

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
  ENC_LEN_DEBUG(x, "xa:RuleCombinerParameters", p-enc_base);
  return p;
}

/* FUNC(zx_EASY_ENC_SO_xa_RuleCombinerParameters) */

/* Called by: */
struct zx_str* zx_EASY_ENC_SO_xa_RuleCombinerParameters(struct zx_ctx* c, struct zx_xa_RuleCombinerParameters_s* x )
{
  int len;
  char* buf;
  c->ns_tab = ZX_ALLOC(c, sizeof(zx_ns_tab));
  memcpy(c->ns_tab, zx_ns_tab, sizeof(zx_ns_tab));
  len = zx_LEN_SO_xa_RuleCombinerParameters(c, x );
  buf = ZX_ALLOC(c, len+1);
  return zx_easy_enc_common(c, zx_ENC_SO_xa_RuleCombinerParameters(c, x, buf ), buf, len);
}

/* FUNC(zx_EASY_ENC_WO_xa_RuleCombinerParameters) */

/* Called by: */
struct zx_str* zx_EASY_ENC_WO_xa_RuleCombinerParameters(struct zx_ctx* c, struct zx_xa_RuleCombinerParameters_s* x )
{
  int len;
  char* buf;
  c->ns_tab = ZX_ALLOC(c, sizeof(zx_ns_tab));
  memcpy(c->ns_tab, zx_ns_tab, sizeof(zx_ns_tab));
  len = zx_LEN_WO_xa_RuleCombinerParameters(c, x );
  buf = ZX_ALLOC(c, len+1);
  return zx_easy_enc_common(c, zx_ENC_WO_xa_RuleCombinerParameters(c, x, buf ), buf, len);
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

#define EL_NAME   xa_Subject
#define EL_STRUCT zx_xa_Subject_s
#define EL_NS     xa
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

/* FUNC(zx_LEN_SO_xa_Subject) */

/* Compute length of an element (and its subelements). The XML attributes
 * and elements are processed in schema order. */

/* Called by: */
int zx_LEN_SO_xa_Subject(struct zx_ctx* c, struct zx_xa_Subject_s* x )
{
  struct zx_ns_s* pop_seen = 0;
  struct zx_elem_s* se MAYBE_UNUSED;
#if 1 /* NORMALMODE */
  /* *** in simple_elem case should output ns prefix from ns node. */
  int len = sizeof("<xa:Subject")-1 + 1 + sizeof("</xa:Subject>")-1;
  if (c->inc_ns_len)
    len += zx_len_inc_ns(c, &pop_seen);
  len += zx_len_xmlns_if_not_seen(c, zx_ns_tab+zx_xmlns_ix_xa, &pop_seen);


#else
  /* root node has no begin tag */
  int len = 0;
#endif
  
  {
      struct zx_xa_SubjectMatch_s* e;
      for (e = x->SubjectMatch; e; e = (struct zx_xa_SubjectMatch_s*)e->gg.g.n)
	  len += zx_LEN_SO_xa_SubjectMatch(c, e);
  }


  len += zx_len_so_common(c, &x->gg);
  zx_pop_seen(pop_seen);
  ENC_LEN_DEBUG(x, "xa:Subject", len);
  return len;
}

/* FUNC(zx_LEN_WO_xa_Subject) */

/* Compute length of an element (and its subelements). The XML attributes
 * and elements are processed in wire order and no assumptions
 * are made about namespace prefixes. */

/* Called by: */
int zx_LEN_WO_xa_Subject(struct zx_ctx* c, struct zx_xa_Subject_s* x )
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


#else
  /* root node has no begin tag */
  int len = 0;
#endif
  
  {
      struct zx_xa_SubjectMatch_s* e;
      for (e = x->SubjectMatch; e; e = (struct zx_xa_SubjectMatch_s*)e->gg.g.n)
	  len += zx_LEN_WO_xa_SubjectMatch(c, e);
  }


  len += zx_len_wo_common(c, &x->gg); 
  zx_pop_seen(pop_seen);
  ENC_LEN_DEBUG(x, "xa:Subject", len);
  return len;
}

/* FUNC(zx_ENC_SO_xa_Subject) */

/* Render element into string. The XML attributes and elements are
 * processed in schema order. This is what you generally want for
 * rendering new data structure to a string. The wo pointers are not used. */

/* Called by: */
char* zx_ENC_SO_xa_Subject(struct zx_ctx* c, struct zx_xa_Subject_s* x, char* p )
{
  struct zx_elem_s* se MAYBE_UNUSED;
  ENC_LEN_DEBUG_BASE;
#if 1 /* NORMALMODE */
  struct zx_ns_s* pop_seen = 0;
  /* *** in simple_elem case should output ns prefix from ns node. */
  ZX_OUT_TAG(p, "<xa:Subject");
  if (c->inc_ns)
    p = zx_enc_inc_ns(c, p, &pop_seen);
  p = zx_enc_xmlns_if_not_seen(c, p, zx_ns_tab+zx_xmlns_ix_xa, &pop_seen);


  p = zx_enc_unknown_attrs(p, x->gg.any_attr);
#else
  /* root node has no begin tag */
#endif
  
  {
      struct zx_xa_SubjectMatch_s* e;
      for (e = x->SubjectMatch; e; e = (struct zx_xa_SubjectMatch_s*)e->gg.g.n)
	  p = zx_ENC_SO_xa_SubjectMatch(c, e, p);
  }

  p = zx_enc_so_unknown_elems_and_content(c, p, &x->gg);
  
#if 1 /* NORMALMODE */
  ZX_OUT_CLOSE_TAG(p, "</xa:Subject>");
  zx_pop_seen(pop_seen);
#else
  /* root node has no end tag either */
#endif
  ENC_LEN_DEBUG(x, "xa:Subject", p-enc_base);
  return p;
}

/* FUNC(zx_ENC_WO_xa_Subject) */

/* Render element into string. The XML attributes and elements are
 * processed in wire order by chasing wo pointers. This is what you want for
 * validating signatures on other people's XML documents. */

/* Called by: */
char* zx_ENC_WO_xa_Subject(struct zx_ctx* c, struct zx_xa_Subject_s* x, char* p )
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
  ZX_OUT_MEM(p, "Subject", sizeof("Subject")-1);
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
  ENC_LEN_DEBUG(x, "xa:Subject", p-enc_base);
  return p;
}

/* FUNC(zx_EASY_ENC_SO_xa_Subject) */

/* Called by: */
struct zx_str* zx_EASY_ENC_SO_xa_Subject(struct zx_ctx* c, struct zx_xa_Subject_s* x )
{
  int len;
  char* buf;
  c->ns_tab = ZX_ALLOC(c, sizeof(zx_ns_tab));
  memcpy(c->ns_tab, zx_ns_tab, sizeof(zx_ns_tab));
  len = zx_LEN_SO_xa_Subject(c, x );
  buf = ZX_ALLOC(c, len+1);
  return zx_easy_enc_common(c, zx_ENC_SO_xa_Subject(c, x, buf ), buf, len);
}

/* FUNC(zx_EASY_ENC_WO_xa_Subject) */

/* Called by: */
struct zx_str* zx_EASY_ENC_WO_xa_Subject(struct zx_ctx* c, struct zx_xa_Subject_s* x )
{
  int len;
  char* buf;
  c->ns_tab = ZX_ALLOC(c, sizeof(zx_ns_tab));
  memcpy(c->ns_tab, zx_ns_tab, sizeof(zx_ns_tab));
  len = zx_LEN_WO_xa_Subject(c, x );
  buf = ZX_ALLOC(c, len+1);
  return zx_easy_enc_common(c, zx_ENC_WO_xa_Subject(c, x, buf ), buf, len);
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

#define EL_NAME   xa_SubjectAttributeDesignator
#define EL_STRUCT zx_xa_SubjectAttributeDesignator_s
#define EL_NS     xa
#define EL_TAG    SubjectAttributeDesignator

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

/* FUNC(zx_LEN_SO_xa_SubjectAttributeDesignator) */

/* Compute length of an element (and its subelements). The XML attributes
 * and elements are processed in schema order. */

/* Called by: */
int zx_LEN_SO_xa_SubjectAttributeDesignator(struct zx_ctx* c, struct zx_xa_SubjectAttributeDesignator_s* x )
{
  struct zx_ns_s* pop_seen = 0;
  struct zx_elem_s* se MAYBE_UNUSED;
#if 1 /* NORMALMODE */
  /* *** in simple_elem case should output ns prefix from ns node. */
  int len = sizeof("<xa:SubjectAttributeDesignator")-1 + 1 + sizeof("</xa:SubjectAttributeDesignator>")-1;
  if (c->inc_ns_len)
    len += zx_len_inc_ns(c, &pop_seen);
  len += zx_len_xmlns_if_not_seen(c, zx_ns_tab+zx_xmlns_ix_xa, &pop_seen);

  len += zx_attr_so_len(x->AttributeId, sizeof("AttributeId")-1);
  len += zx_attr_so_len(x->DataType, sizeof("DataType")-1);
  len += zx_attr_so_len(x->Issuer, sizeof("Issuer")-1);
  len += zx_attr_so_len(x->MustBePresent, sizeof("MustBePresent")-1);
  len += zx_attr_so_len(x->SubjectCategory, sizeof("SubjectCategory")-1);

#else
  /* root node has no begin tag */
  int len = 0;
#endif
  


  len += zx_len_so_common(c, &x->gg);
  zx_pop_seen(pop_seen);
  ENC_LEN_DEBUG(x, "xa:SubjectAttributeDesignator", len);
  return len;
}

/* FUNC(zx_LEN_WO_xa_SubjectAttributeDesignator) */

/* Compute length of an element (and its subelements). The XML attributes
 * and elements are processed in wire order and no assumptions
 * are made about namespace prefixes. */

/* Called by: */
int zx_LEN_WO_xa_SubjectAttributeDesignator(struct zx_ctx* c, struct zx_xa_SubjectAttributeDesignator_s* x )
{
  struct zx_ns_s* pop_seen = 0;
  struct zx_elem_s* se MAYBE_UNUSED;
#if 1 /* NORMALMODE */
  int len = 1 + sizeof("SubjectAttributeDesignator")-1 + 1 + 2 + sizeof("SubjectAttributeDesignator")-1 + 1;
  
  if (x->gg.g.ns && x->gg.g.ns->prefix_len)
    len += (x->gg.g.ns->prefix_len + 1) * 2;
  if (c->inc_ns_len)
    len += zx_len_inc_ns(c, &pop_seen);
  len += zx_len_xmlns_if_not_seen(c, x->gg.g.ns, &pop_seen);

  len += zx_attr_wo_len(x->AttributeId, sizeof("AttributeId")-1);
  len += zx_attr_wo_len(x->DataType, sizeof("DataType")-1);
  len += zx_attr_wo_len(x->Issuer, sizeof("Issuer")-1);
  len += zx_attr_wo_len(x->MustBePresent, sizeof("MustBePresent")-1);
  len += zx_attr_wo_len(x->SubjectCategory, sizeof("SubjectCategory")-1);

#else
  /* root node has no begin tag */
  int len = 0;
#endif
  


  len += zx_len_wo_common(c, &x->gg); 
  zx_pop_seen(pop_seen);
  ENC_LEN_DEBUG(x, "xa:SubjectAttributeDesignator", len);
  return len;
}

/* FUNC(zx_ENC_SO_xa_SubjectAttributeDesignator) */

/* Render element into string. The XML attributes and elements are
 * processed in schema order. This is what you generally want for
 * rendering new data structure to a string. The wo pointers are not used. */

/* Called by: */
char* zx_ENC_SO_xa_SubjectAttributeDesignator(struct zx_ctx* c, struct zx_xa_SubjectAttributeDesignator_s* x, char* p )
{
  struct zx_elem_s* se MAYBE_UNUSED;
  ENC_LEN_DEBUG_BASE;
#if 1 /* NORMALMODE */
  struct zx_ns_s* pop_seen = 0;
  /* *** in simple_elem case should output ns prefix from ns node. */
  ZX_OUT_TAG(p, "<xa:SubjectAttributeDesignator");
  if (c->inc_ns)
    p = zx_enc_inc_ns(c, p, &pop_seen);
  p = zx_enc_xmlns_if_not_seen(c, p, zx_ns_tab+zx_xmlns_ix_xa, &pop_seen);

  p = zx_attr_so_enc(p, x->AttributeId, " AttributeId=\"", sizeof(" AttributeId=\"")-1);
  p = zx_attr_so_enc(p, x->DataType, " DataType=\"", sizeof(" DataType=\"")-1);
  p = zx_attr_so_enc(p, x->Issuer, " Issuer=\"", sizeof(" Issuer=\"")-1);
  p = zx_attr_so_enc(p, x->MustBePresent, " MustBePresent=\"", sizeof(" MustBePresent=\"")-1);
  p = zx_attr_so_enc(p, x->SubjectCategory, " SubjectCategory=\"", sizeof(" SubjectCategory=\"")-1);

  p = zx_enc_unknown_attrs(p, x->gg.any_attr);
#else
  /* root node has no begin tag */
#endif
  

  p = zx_enc_so_unknown_elems_and_content(c, p, &x->gg);
  
#if 1 /* NORMALMODE */
  ZX_OUT_CLOSE_TAG(p, "</xa:SubjectAttributeDesignator>");
  zx_pop_seen(pop_seen);
#else
  /* root node has no end tag either */
#endif
  ENC_LEN_DEBUG(x, "xa:SubjectAttributeDesignator", p-enc_base);
  return p;
}

/* FUNC(zx_ENC_WO_xa_SubjectAttributeDesignator) */

/* Render element into string. The XML attributes and elements are
 * processed in wire order by chasing wo pointers. This is what you want for
 * validating signatures on other people's XML documents. */

/* Called by: */
char* zx_ENC_WO_xa_SubjectAttributeDesignator(struct zx_ctx* c, struct zx_xa_SubjectAttributeDesignator_s* x, char* p )
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
  ZX_OUT_MEM(p, "SubjectAttributeDesignator", sizeof("SubjectAttributeDesignator")-1);
  qq = p;

  /* *** sort the namespaces */
  if (c->inc_ns)
    zx_add_inc_ns(c, &pop_seen);
  zx_add_xmlns_if_not_seen(c, x->gg.g.ns, &pop_seen);

  p = zx_enc_seen(p, pop_seen); 
  p = zx_attr_wo_enc(p, x->AttributeId, "AttributeId=\"", sizeof("AttributeId=\"")-1);
  p = zx_attr_wo_enc(p, x->DataType, "DataType=\"", sizeof("DataType=\"")-1);
  p = zx_attr_wo_enc(p, x->Issuer, "Issuer=\"", sizeof("Issuer=\"")-1);
  p = zx_attr_wo_enc(p, x->MustBePresent, "MustBePresent=\"", sizeof("MustBePresent=\"")-1);
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
  ENC_LEN_DEBUG(x, "xa:SubjectAttributeDesignator", p-enc_base);
  return p;
}

/* FUNC(zx_EASY_ENC_SO_xa_SubjectAttributeDesignator) */

/* Called by: */
struct zx_str* zx_EASY_ENC_SO_xa_SubjectAttributeDesignator(struct zx_ctx* c, struct zx_xa_SubjectAttributeDesignator_s* x )
{
  int len;
  char* buf;
  c->ns_tab = ZX_ALLOC(c, sizeof(zx_ns_tab));
  memcpy(c->ns_tab, zx_ns_tab, sizeof(zx_ns_tab));
  len = zx_LEN_SO_xa_SubjectAttributeDesignator(c, x );
  buf = ZX_ALLOC(c, len+1);
  return zx_easy_enc_common(c, zx_ENC_SO_xa_SubjectAttributeDesignator(c, x, buf ), buf, len);
}

/* FUNC(zx_EASY_ENC_WO_xa_SubjectAttributeDesignator) */

/* Called by: */
struct zx_str* zx_EASY_ENC_WO_xa_SubjectAttributeDesignator(struct zx_ctx* c, struct zx_xa_SubjectAttributeDesignator_s* x )
{
  int len;
  char* buf;
  c->ns_tab = ZX_ALLOC(c, sizeof(zx_ns_tab));
  memcpy(c->ns_tab, zx_ns_tab, sizeof(zx_ns_tab));
  len = zx_LEN_WO_xa_SubjectAttributeDesignator(c, x );
  buf = ZX_ALLOC(c, len+1);
  return zx_easy_enc_common(c, zx_ENC_WO_xa_SubjectAttributeDesignator(c, x, buf ), buf, len);
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

#define EL_NAME   xa_SubjectMatch
#define EL_STRUCT zx_xa_SubjectMatch_s
#define EL_NS     xa
#define EL_TAG    SubjectMatch

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

/* FUNC(zx_LEN_SO_xa_SubjectMatch) */

/* Compute length of an element (and its subelements). The XML attributes
 * and elements are processed in schema order. */

/* Called by: */
int zx_LEN_SO_xa_SubjectMatch(struct zx_ctx* c, struct zx_xa_SubjectMatch_s* x )
{
  struct zx_ns_s* pop_seen = 0;
  struct zx_elem_s* se MAYBE_UNUSED;
#if 1 /* NORMALMODE */
  /* *** in simple_elem case should output ns prefix from ns node. */
  int len = sizeof("<xa:SubjectMatch")-1 + 1 + sizeof("</xa:SubjectMatch>")-1;
  if (c->inc_ns_len)
    len += zx_len_inc_ns(c, &pop_seen);
  len += zx_len_xmlns_if_not_seen(c, zx_ns_tab+zx_xmlns_ix_xa, &pop_seen);

  len += zx_attr_so_len(x->MatchId, sizeof("MatchId")-1);

#else
  /* root node has no begin tag */
  int len = 0;
#endif
  
  {
      struct zx_xa_AttributeValue_s* e;
      for (e = x->AttributeValue; e; e = (struct zx_xa_AttributeValue_s*)e->gg.g.n)
	  len += zx_LEN_SO_xa_AttributeValue(c, e);
  }
  {
      struct zx_xa_SubjectAttributeDesignator_s* e;
      for (e = x->SubjectAttributeDesignator; e; e = (struct zx_xa_SubjectAttributeDesignator_s*)e->gg.g.n)
	  len += zx_LEN_SO_xa_SubjectAttributeDesignator(c, e);
  }
  {
      struct zx_xa_AttributeSelector_s* e;
      for (e = x->AttributeSelector; e; e = (struct zx_xa_AttributeSelector_s*)e->gg.g.n)
	  len += zx_LEN_SO_xa_AttributeSelector(c, e);
  }


  len += zx_len_so_common(c, &x->gg);
  zx_pop_seen(pop_seen);
  ENC_LEN_DEBUG(x, "xa:SubjectMatch", len);
  return len;
}

/* FUNC(zx_LEN_WO_xa_SubjectMatch) */

/* Compute length of an element (and its subelements). The XML attributes
 * and elements are processed in wire order and no assumptions
 * are made about namespace prefixes. */

/* Called by: */
int zx_LEN_WO_xa_SubjectMatch(struct zx_ctx* c, struct zx_xa_SubjectMatch_s* x )
{
  struct zx_ns_s* pop_seen = 0;
  struct zx_elem_s* se MAYBE_UNUSED;
#if 1 /* NORMALMODE */
  int len = 1 + sizeof("SubjectMatch")-1 + 1 + 2 + sizeof("SubjectMatch")-1 + 1;
  
  if (x->gg.g.ns && x->gg.g.ns->prefix_len)
    len += (x->gg.g.ns->prefix_len + 1) * 2;
  if (c->inc_ns_len)
    len += zx_len_inc_ns(c, &pop_seen);
  len += zx_len_xmlns_if_not_seen(c, x->gg.g.ns, &pop_seen);

  len += zx_attr_wo_len(x->MatchId, sizeof("MatchId")-1);

#else
  /* root node has no begin tag */
  int len = 0;
#endif
  
  {
      struct zx_xa_AttributeValue_s* e;
      for (e = x->AttributeValue; e; e = (struct zx_xa_AttributeValue_s*)e->gg.g.n)
	  len += zx_LEN_WO_xa_AttributeValue(c, e);
  }
  {
      struct zx_xa_SubjectAttributeDesignator_s* e;
      for (e = x->SubjectAttributeDesignator; e; e = (struct zx_xa_SubjectAttributeDesignator_s*)e->gg.g.n)
	  len += zx_LEN_WO_xa_SubjectAttributeDesignator(c, e);
  }
  {
      struct zx_xa_AttributeSelector_s* e;
      for (e = x->AttributeSelector; e; e = (struct zx_xa_AttributeSelector_s*)e->gg.g.n)
	  len += zx_LEN_WO_xa_AttributeSelector(c, e);
  }


  len += zx_len_wo_common(c, &x->gg); 
  zx_pop_seen(pop_seen);
  ENC_LEN_DEBUG(x, "xa:SubjectMatch", len);
  return len;
}

/* FUNC(zx_ENC_SO_xa_SubjectMatch) */

/* Render element into string. The XML attributes and elements are
 * processed in schema order. This is what you generally want for
 * rendering new data structure to a string. The wo pointers are not used. */

/* Called by: */
char* zx_ENC_SO_xa_SubjectMatch(struct zx_ctx* c, struct zx_xa_SubjectMatch_s* x, char* p )
{
  struct zx_elem_s* se MAYBE_UNUSED;
  ENC_LEN_DEBUG_BASE;
#if 1 /* NORMALMODE */
  struct zx_ns_s* pop_seen = 0;
  /* *** in simple_elem case should output ns prefix from ns node. */
  ZX_OUT_TAG(p, "<xa:SubjectMatch");
  if (c->inc_ns)
    p = zx_enc_inc_ns(c, p, &pop_seen);
  p = zx_enc_xmlns_if_not_seen(c, p, zx_ns_tab+zx_xmlns_ix_xa, &pop_seen);

  p = zx_attr_so_enc(p, x->MatchId, " MatchId=\"", sizeof(" MatchId=\"")-1);

  p = zx_enc_unknown_attrs(p, x->gg.any_attr);
#else
  /* root node has no begin tag */
#endif
  
  {
      struct zx_xa_AttributeValue_s* e;
      for (e = x->AttributeValue; e; e = (struct zx_xa_AttributeValue_s*)e->gg.g.n)
	  p = zx_ENC_SO_xa_AttributeValue(c, e, p);
  }
  {
      struct zx_xa_SubjectAttributeDesignator_s* e;
      for (e = x->SubjectAttributeDesignator; e; e = (struct zx_xa_SubjectAttributeDesignator_s*)e->gg.g.n)
	  p = zx_ENC_SO_xa_SubjectAttributeDesignator(c, e, p);
  }
  {
      struct zx_xa_AttributeSelector_s* e;
      for (e = x->AttributeSelector; e; e = (struct zx_xa_AttributeSelector_s*)e->gg.g.n)
	  p = zx_ENC_SO_xa_AttributeSelector(c, e, p);
  }

  p = zx_enc_so_unknown_elems_and_content(c, p, &x->gg);
  
#if 1 /* NORMALMODE */
  ZX_OUT_CLOSE_TAG(p, "</xa:SubjectMatch>");
  zx_pop_seen(pop_seen);
#else
  /* root node has no end tag either */
#endif
  ENC_LEN_DEBUG(x, "xa:SubjectMatch", p-enc_base);
  return p;
}

/* FUNC(zx_ENC_WO_xa_SubjectMatch) */

/* Render element into string. The XML attributes and elements are
 * processed in wire order by chasing wo pointers. This is what you want for
 * validating signatures on other people's XML documents. */

/* Called by: */
char* zx_ENC_WO_xa_SubjectMatch(struct zx_ctx* c, struct zx_xa_SubjectMatch_s* x, char* p )
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
  ZX_OUT_MEM(p, "SubjectMatch", sizeof("SubjectMatch")-1);
  qq = p;

  /* *** sort the namespaces */
  if (c->inc_ns)
    zx_add_inc_ns(c, &pop_seen);
  zx_add_xmlns_if_not_seen(c, x->gg.g.ns, &pop_seen);

  p = zx_enc_seen(p, pop_seen); 
  p = zx_attr_wo_enc(p, x->MatchId, "MatchId=\"", sizeof("MatchId=\"")-1);

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
  ENC_LEN_DEBUG(x, "xa:SubjectMatch", p-enc_base);
  return p;
}

/* FUNC(zx_EASY_ENC_SO_xa_SubjectMatch) */

/* Called by: */
struct zx_str* zx_EASY_ENC_SO_xa_SubjectMatch(struct zx_ctx* c, struct zx_xa_SubjectMatch_s* x )
{
  int len;
  char* buf;
  c->ns_tab = ZX_ALLOC(c, sizeof(zx_ns_tab));
  memcpy(c->ns_tab, zx_ns_tab, sizeof(zx_ns_tab));
  len = zx_LEN_SO_xa_SubjectMatch(c, x );
  buf = ZX_ALLOC(c, len+1);
  return zx_easy_enc_common(c, zx_ENC_SO_xa_SubjectMatch(c, x, buf ), buf, len);
}

/* FUNC(zx_EASY_ENC_WO_xa_SubjectMatch) */

/* Called by: */
struct zx_str* zx_EASY_ENC_WO_xa_SubjectMatch(struct zx_ctx* c, struct zx_xa_SubjectMatch_s* x )
{
  int len;
  char* buf;
  c->ns_tab = ZX_ALLOC(c, sizeof(zx_ns_tab));
  memcpy(c->ns_tab, zx_ns_tab, sizeof(zx_ns_tab));
  len = zx_LEN_WO_xa_SubjectMatch(c, x );
  buf = ZX_ALLOC(c, len+1);
  return zx_easy_enc_common(c, zx_ENC_WO_xa_SubjectMatch(c, x, buf ), buf, len);
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

#define EL_NAME   xa_Subjects
#define EL_STRUCT zx_xa_Subjects_s
#define EL_NS     xa
#define EL_TAG    Subjects

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

/* FUNC(zx_LEN_SO_xa_Subjects) */

/* Compute length of an element (and its subelements). The XML attributes
 * and elements are processed in schema order. */

/* Called by: */
int zx_LEN_SO_xa_Subjects(struct zx_ctx* c, struct zx_xa_Subjects_s* x )
{
  struct zx_ns_s* pop_seen = 0;
  struct zx_elem_s* se MAYBE_UNUSED;
#if 1 /* NORMALMODE */
  /* *** in simple_elem case should output ns prefix from ns node. */
  int len = sizeof("<xa:Subjects")-1 + 1 + sizeof("</xa:Subjects>")-1;
  if (c->inc_ns_len)
    len += zx_len_inc_ns(c, &pop_seen);
  len += zx_len_xmlns_if_not_seen(c, zx_ns_tab+zx_xmlns_ix_xa, &pop_seen);


#else
  /* root node has no begin tag */
  int len = 0;
#endif
  
  {
      struct zx_xa_Subject_s* e;
      for (e = x->Subject; e; e = (struct zx_xa_Subject_s*)e->gg.g.n)
	  len += zx_LEN_SO_xa_Subject(c, e);
  }


  len += zx_len_so_common(c, &x->gg);
  zx_pop_seen(pop_seen);
  ENC_LEN_DEBUG(x, "xa:Subjects", len);
  return len;
}

/* FUNC(zx_LEN_WO_xa_Subjects) */

/* Compute length of an element (and its subelements). The XML attributes
 * and elements are processed in wire order and no assumptions
 * are made about namespace prefixes. */

/* Called by: */
int zx_LEN_WO_xa_Subjects(struct zx_ctx* c, struct zx_xa_Subjects_s* x )
{
  struct zx_ns_s* pop_seen = 0;
  struct zx_elem_s* se MAYBE_UNUSED;
#if 1 /* NORMALMODE */
  int len = 1 + sizeof("Subjects")-1 + 1 + 2 + sizeof("Subjects")-1 + 1;
  
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
      struct zx_xa_Subject_s* e;
      for (e = x->Subject; e; e = (struct zx_xa_Subject_s*)e->gg.g.n)
	  len += zx_LEN_WO_xa_Subject(c, e);
  }


  len += zx_len_wo_common(c, &x->gg); 
  zx_pop_seen(pop_seen);
  ENC_LEN_DEBUG(x, "xa:Subjects", len);
  return len;
}

/* FUNC(zx_ENC_SO_xa_Subjects) */

/* Render element into string. The XML attributes and elements are
 * processed in schema order. This is what you generally want for
 * rendering new data structure to a string. The wo pointers are not used. */

/* Called by: */
char* zx_ENC_SO_xa_Subjects(struct zx_ctx* c, struct zx_xa_Subjects_s* x, char* p )
{
  struct zx_elem_s* se MAYBE_UNUSED;
  ENC_LEN_DEBUG_BASE;
#if 1 /* NORMALMODE */
  struct zx_ns_s* pop_seen = 0;
  /* *** in simple_elem case should output ns prefix from ns node. */
  ZX_OUT_TAG(p, "<xa:Subjects");
  if (c->inc_ns)
    p = zx_enc_inc_ns(c, p, &pop_seen);
  p = zx_enc_xmlns_if_not_seen(c, p, zx_ns_tab+zx_xmlns_ix_xa, &pop_seen);


  p = zx_enc_unknown_attrs(p, x->gg.any_attr);
#else
  /* root node has no begin tag */
#endif
  
  {
      struct zx_xa_Subject_s* e;
      for (e = x->Subject; e; e = (struct zx_xa_Subject_s*)e->gg.g.n)
	  p = zx_ENC_SO_xa_Subject(c, e, p);
  }

  p = zx_enc_so_unknown_elems_and_content(c, p, &x->gg);
  
#if 1 /* NORMALMODE */
  ZX_OUT_CLOSE_TAG(p, "</xa:Subjects>");
  zx_pop_seen(pop_seen);
#else
  /* root node has no end tag either */
#endif
  ENC_LEN_DEBUG(x, "xa:Subjects", p-enc_base);
  return p;
}

/* FUNC(zx_ENC_WO_xa_Subjects) */

/* Render element into string. The XML attributes and elements are
 * processed in wire order by chasing wo pointers. This is what you want for
 * validating signatures on other people's XML documents. */

/* Called by: */
char* zx_ENC_WO_xa_Subjects(struct zx_ctx* c, struct zx_xa_Subjects_s* x, char* p )
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
  ZX_OUT_MEM(p, "Subjects", sizeof("Subjects")-1);
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
  ENC_LEN_DEBUG(x, "xa:Subjects", p-enc_base);
  return p;
}

/* FUNC(zx_EASY_ENC_SO_xa_Subjects) */

/* Called by: */
struct zx_str* zx_EASY_ENC_SO_xa_Subjects(struct zx_ctx* c, struct zx_xa_Subjects_s* x )
{
  int len;
  char* buf;
  c->ns_tab = ZX_ALLOC(c, sizeof(zx_ns_tab));
  memcpy(c->ns_tab, zx_ns_tab, sizeof(zx_ns_tab));
  len = zx_LEN_SO_xa_Subjects(c, x );
  buf = ZX_ALLOC(c, len+1);
  return zx_easy_enc_common(c, zx_ENC_SO_xa_Subjects(c, x, buf ), buf, len);
}

/* FUNC(zx_EASY_ENC_WO_xa_Subjects) */

/* Called by: */
struct zx_str* zx_EASY_ENC_WO_xa_Subjects(struct zx_ctx* c, struct zx_xa_Subjects_s* x )
{
  int len;
  char* buf;
  c->ns_tab = ZX_ALLOC(c, sizeof(zx_ns_tab));
  memcpy(c->ns_tab, zx_ns_tab, sizeof(zx_ns_tab));
  len = zx_LEN_WO_xa_Subjects(c, x );
  buf = ZX_ALLOC(c, len+1);
  return zx_easy_enc_common(c, zx_ENC_WO_xa_Subjects(c, x, buf ), buf, len);
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

#define EL_NAME   xa_Target
#define EL_STRUCT zx_xa_Target_s
#define EL_NS     xa
#define EL_TAG    Target

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

/* FUNC(zx_LEN_SO_xa_Target) */

/* Compute length of an element (and its subelements). The XML attributes
 * and elements are processed in schema order. */

/* Called by: */
int zx_LEN_SO_xa_Target(struct zx_ctx* c, struct zx_xa_Target_s* x )
{
  struct zx_ns_s* pop_seen = 0;
  struct zx_elem_s* se MAYBE_UNUSED;
#if 1 /* NORMALMODE */
  /* *** in simple_elem case should output ns prefix from ns node. */
  int len = sizeof("<xa:Target")-1 + 1 + sizeof("</xa:Target>")-1;
  if (c->inc_ns_len)
    len += zx_len_inc_ns(c, &pop_seen);
  len += zx_len_xmlns_if_not_seen(c, zx_ns_tab+zx_xmlns_ix_xa, &pop_seen);


#else
  /* root node has no begin tag */
  int len = 0;
#endif
  
  {
      struct zx_xa_Subjects_s* e;
      for (e = x->Subjects; e; e = (struct zx_xa_Subjects_s*)e->gg.g.n)
	  len += zx_LEN_SO_xa_Subjects(c, e);
  }
  {
      struct zx_xa_Resources_s* e;
      for (e = x->Resources; e; e = (struct zx_xa_Resources_s*)e->gg.g.n)
	  len += zx_LEN_SO_xa_Resources(c, e);
  }
  {
      struct zx_xa_Actions_s* e;
      for (e = x->Actions; e; e = (struct zx_xa_Actions_s*)e->gg.g.n)
	  len += zx_LEN_SO_xa_Actions(c, e);
  }
  {
      struct zx_xa_Environments_s* e;
      for (e = x->Environments; e; e = (struct zx_xa_Environments_s*)e->gg.g.n)
	  len += zx_LEN_SO_xa_Environments(c, e);
  }


  len += zx_len_so_common(c, &x->gg);
  zx_pop_seen(pop_seen);
  ENC_LEN_DEBUG(x, "xa:Target", len);
  return len;
}

/* FUNC(zx_LEN_WO_xa_Target) */

/* Compute length of an element (and its subelements). The XML attributes
 * and elements are processed in wire order and no assumptions
 * are made about namespace prefixes. */

/* Called by: */
int zx_LEN_WO_xa_Target(struct zx_ctx* c, struct zx_xa_Target_s* x )
{
  struct zx_ns_s* pop_seen = 0;
  struct zx_elem_s* se MAYBE_UNUSED;
#if 1 /* NORMALMODE */
  int len = 1 + sizeof("Target")-1 + 1 + 2 + sizeof("Target")-1 + 1;
  
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
      struct zx_xa_Subjects_s* e;
      for (e = x->Subjects; e; e = (struct zx_xa_Subjects_s*)e->gg.g.n)
	  len += zx_LEN_WO_xa_Subjects(c, e);
  }
  {
      struct zx_xa_Resources_s* e;
      for (e = x->Resources; e; e = (struct zx_xa_Resources_s*)e->gg.g.n)
	  len += zx_LEN_WO_xa_Resources(c, e);
  }
  {
      struct zx_xa_Actions_s* e;
      for (e = x->Actions; e; e = (struct zx_xa_Actions_s*)e->gg.g.n)
	  len += zx_LEN_WO_xa_Actions(c, e);
  }
  {
      struct zx_xa_Environments_s* e;
      for (e = x->Environments; e; e = (struct zx_xa_Environments_s*)e->gg.g.n)
	  len += zx_LEN_WO_xa_Environments(c, e);
  }


  len += zx_len_wo_common(c, &x->gg); 
  zx_pop_seen(pop_seen);
  ENC_LEN_DEBUG(x, "xa:Target", len);
  return len;
}

/* FUNC(zx_ENC_SO_xa_Target) */

/* Render element into string. The XML attributes and elements are
 * processed in schema order. This is what you generally want for
 * rendering new data structure to a string. The wo pointers are not used. */

/* Called by: */
char* zx_ENC_SO_xa_Target(struct zx_ctx* c, struct zx_xa_Target_s* x, char* p )
{
  struct zx_elem_s* se MAYBE_UNUSED;
  ENC_LEN_DEBUG_BASE;
#if 1 /* NORMALMODE */
  struct zx_ns_s* pop_seen = 0;
  /* *** in simple_elem case should output ns prefix from ns node. */
  ZX_OUT_TAG(p, "<xa:Target");
  if (c->inc_ns)
    p = zx_enc_inc_ns(c, p, &pop_seen);
  p = zx_enc_xmlns_if_not_seen(c, p, zx_ns_tab+zx_xmlns_ix_xa, &pop_seen);


  p = zx_enc_unknown_attrs(p, x->gg.any_attr);
#else
  /* root node has no begin tag */
#endif
  
  {
      struct zx_xa_Subjects_s* e;
      for (e = x->Subjects; e; e = (struct zx_xa_Subjects_s*)e->gg.g.n)
	  p = zx_ENC_SO_xa_Subjects(c, e, p);
  }
  {
      struct zx_xa_Resources_s* e;
      for (e = x->Resources; e; e = (struct zx_xa_Resources_s*)e->gg.g.n)
	  p = zx_ENC_SO_xa_Resources(c, e, p);
  }
  {
      struct zx_xa_Actions_s* e;
      for (e = x->Actions; e; e = (struct zx_xa_Actions_s*)e->gg.g.n)
	  p = zx_ENC_SO_xa_Actions(c, e, p);
  }
  {
      struct zx_xa_Environments_s* e;
      for (e = x->Environments; e; e = (struct zx_xa_Environments_s*)e->gg.g.n)
	  p = zx_ENC_SO_xa_Environments(c, e, p);
  }

  p = zx_enc_so_unknown_elems_and_content(c, p, &x->gg);
  
#if 1 /* NORMALMODE */
  ZX_OUT_CLOSE_TAG(p, "</xa:Target>");
  zx_pop_seen(pop_seen);
#else
  /* root node has no end tag either */
#endif
  ENC_LEN_DEBUG(x, "xa:Target", p-enc_base);
  return p;
}

/* FUNC(zx_ENC_WO_xa_Target) */

/* Render element into string. The XML attributes and elements are
 * processed in wire order by chasing wo pointers. This is what you want for
 * validating signatures on other people's XML documents. */

/* Called by: */
char* zx_ENC_WO_xa_Target(struct zx_ctx* c, struct zx_xa_Target_s* x, char* p )
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
  ZX_OUT_MEM(p, "Target", sizeof("Target")-1);
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
  ENC_LEN_DEBUG(x, "xa:Target", p-enc_base);
  return p;
}

/* FUNC(zx_EASY_ENC_SO_xa_Target) */

/* Called by: */
struct zx_str* zx_EASY_ENC_SO_xa_Target(struct zx_ctx* c, struct zx_xa_Target_s* x )
{
  int len;
  char* buf;
  c->ns_tab = ZX_ALLOC(c, sizeof(zx_ns_tab));
  memcpy(c->ns_tab, zx_ns_tab, sizeof(zx_ns_tab));
  len = zx_LEN_SO_xa_Target(c, x );
  buf = ZX_ALLOC(c, len+1);
  return zx_easy_enc_common(c, zx_ENC_SO_xa_Target(c, x, buf ), buf, len);
}

/* FUNC(zx_EASY_ENC_WO_xa_Target) */

/* Called by: */
struct zx_str* zx_EASY_ENC_WO_xa_Target(struct zx_ctx* c, struct zx_xa_Target_s* x )
{
  int len;
  char* buf;
  c->ns_tab = ZX_ALLOC(c, sizeof(zx_ns_tab));
  memcpy(c->ns_tab, zx_ns_tab, sizeof(zx_ns_tab));
  len = zx_LEN_WO_xa_Target(c, x );
  buf = ZX_ALLOC(c, len+1);
  return zx_easy_enc_common(c, zx_ENC_WO_xa_Target(c, x, buf ), buf, len);
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

#define EL_NAME   xa_VariableDefinition
#define EL_STRUCT zx_xa_VariableDefinition_s
#define EL_NS     xa
#define EL_TAG    VariableDefinition

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

/* FUNC(zx_LEN_SO_xa_VariableDefinition) */

/* Compute length of an element (and its subelements). The XML attributes
 * and elements are processed in schema order. */

/* Called by: */
int zx_LEN_SO_xa_VariableDefinition(struct zx_ctx* c, struct zx_xa_VariableDefinition_s* x )
{
  struct zx_ns_s* pop_seen = 0;
  struct zx_elem_s* se MAYBE_UNUSED;
#if 1 /* NORMALMODE */
  /* *** in simple_elem case should output ns prefix from ns node. */
  int len = sizeof("<xa:VariableDefinition")-1 + 1 + sizeof("</xa:VariableDefinition>")-1;
  if (c->inc_ns_len)
    len += zx_len_inc_ns(c, &pop_seen);
  len += zx_len_xmlns_if_not_seen(c, zx_ns_tab+zx_xmlns_ix_xa, &pop_seen);

  len += zx_attr_so_len(x->VariableId, sizeof("VariableId")-1);

#else
  /* root node has no begin tag */
  int len = 0;
#endif
  
  for (se = x->Expression; se; se = (struct zx_elem_s*)se->g.n)
    len += zx_LEN_SO_simple_elem(c,se, sizeof("xa:Expression")-1, zx_ns_tab+zx_xmlns_ix_xa);


  len += zx_len_so_common(c, &x->gg);
  zx_pop_seen(pop_seen);
  ENC_LEN_DEBUG(x, "xa:VariableDefinition", len);
  return len;
}

/* FUNC(zx_LEN_WO_xa_VariableDefinition) */

/* Compute length of an element (and its subelements). The XML attributes
 * and elements are processed in wire order and no assumptions
 * are made about namespace prefixes. */

/* Called by: */
int zx_LEN_WO_xa_VariableDefinition(struct zx_ctx* c, struct zx_xa_VariableDefinition_s* x )
{
  struct zx_ns_s* pop_seen = 0;
  struct zx_elem_s* se MAYBE_UNUSED;
#if 1 /* NORMALMODE */
  int len = 1 + sizeof("VariableDefinition")-1 + 1 + 2 + sizeof("VariableDefinition")-1 + 1;
  
  if (x->gg.g.ns && x->gg.g.ns->prefix_len)
    len += (x->gg.g.ns->prefix_len + 1) * 2;
  if (c->inc_ns_len)
    len += zx_len_inc_ns(c, &pop_seen);
  len += zx_len_xmlns_if_not_seen(c, x->gg.g.ns, &pop_seen);

  len += zx_attr_wo_len(x->VariableId, sizeof("VariableId")-1);

#else
  /* root node has no begin tag */
  int len = 0;
#endif
  
  for (se = x->Expression; se; se = (struct zx_elem_s*)se->g.n)
    len += zx_LEN_WO_simple_elem(c, se, sizeof("Expression")-1);


  len += zx_len_wo_common(c, &x->gg); 
  zx_pop_seen(pop_seen);
  ENC_LEN_DEBUG(x, "xa:VariableDefinition", len);
  return len;
}

/* FUNC(zx_ENC_SO_xa_VariableDefinition) */

/* Render element into string. The XML attributes and elements are
 * processed in schema order. This is what you generally want for
 * rendering new data structure to a string. The wo pointers are not used. */

/* Called by: */
char* zx_ENC_SO_xa_VariableDefinition(struct zx_ctx* c, struct zx_xa_VariableDefinition_s* x, char* p )
{
  struct zx_elem_s* se MAYBE_UNUSED;
  ENC_LEN_DEBUG_BASE;
#if 1 /* NORMALMODE */
  struct zx_ns_s* pop_seen = 0;
  /* *** in simple_elem case should output ns prefix from ns node. */
  ZX_OUT_TAG(p, "<xa:VariableDefinition");
  if (c->inc_ns)
    p = zx_enc_inc_ns(c, p, &pop_seen);
  p = zx_enc_xmlns_if_not_seen(c, p, zx_ns_tab+zx_xmlns_ix_xa, &pop_seen);

  p = zx_attr_so_enc(p, x->VariableId, " VariableId=\"", sizeof(" VariableId=\"")-1);

  p = zx_enc_unknown_attrs(p, x->gg.any_attr);
#else
  /* root node has no begin tag */
#endif
  
  for (se = x->Expression; se; se = (struct zx_elem_s*)se->g.n)
    p = zx_ENC_SO_simple_elem(c, se, p, "xa:Expression", sizeof("xa:Expression")-1, zx_ns_tab+zx_xmlns_ix_xa);

  p = zx_enc_so_unknown_elems_and_content(c, p, &x->gg);
  
#if 1 /* NORMALMODE */
  ZX_OUT_CLOSE_TAG(p, "</xa:VariableDefinition>");
  zx_pop_seen(pop_seen);
#else
  /* root node has no end tag either */
#endif
  ENC_LEN_DEBUG(x, "xa:VariableDefinition", p-enc_base);
  return p;
}

/* FUNC(zx_ENC_WO_xa_VariableDefinition) */

/* Render element into string. The XML attributes and elements are
 * processed in wire order by chasing wo pointers. This is what you want for
 * validating signatures on other people's XML documents. */

/* Called by: */
char* zx_ENC_WO_xa_VariableDefinition(struct zx_ctx* c, struct zx_xa_VariableDefinition_s* x, char* p )
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
  ZX_OUT_MEM(p, "VariableDefinition", sizeof("VariableDefinition")-1);
  qq = p;

  /* *** sort the namespaces */
  if (c->inc_ns)
    zx_add_inc_ns(c, &pop_seen);
  zx_add_xmlns_if_not_seen(c, x->gg.g.ns, &pop_seen);

  p = zx_enc_seen(p, pop_seen); 
  p = zx_attr_wo_enc(p, x->VariableId, "VariableId=\"", sizeof("VariableId=\"")-1);

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
  ENC_LEN_DEBUG(x, "xa:VariableDefinition", p-enc_base);
  return p;
}

/* FUNC(zx_EASY_ENC_SO_xa_VariableDefinition) */

/* Called by: */
struct zx_str* zx_EASY_ENC_SO_xa_VariableDefinition(struct zx_ctx* c, struct zx_xa_VariableDefinition_s* x )
{
  int len;
  char* buf;
  c->ns_tab = ZX_ALLOC(c, sizeof(zx_ns_tab));
  memcpy(c->ns_tab, zx_ns_tab, sizeof(zx_ns_tab));
  len = zx_LEN_SO_xa_VariableDefinition(c, x );
  buf = ZX_ALLOC(c, len+1);
  return zx_easy_enc_common(c, zx_ENC_SO_xa_VariableDefinition(c, x, buf ), buf, len);
}

/* FUNC(zx_EASY_ENC_WO_xa_VariableDefinition) */

/* Called by: */
struct zx_str* zx_EASY_ENC_WO_xa_VariableDefinition(struct zx_ctx* c, struct zx_xa_VariableDefinition_s* x )
{
  int len;
  char* buf;
  c->ns_tab = ZX_ALLOC(c, sizeof(zx_ns_tab));
  memcpy(c->ns_tab, zx_ns_tab, sizeof(zx_ns_tab));
  len = zx_LEN_WO_xa_VariableDefinition(c, x );
  buf = ZX_ALLOC(c, len+1);
  return zx_easy_enc_common(c, zx_ENC_WO_xa_VariableDefinition(c, x, buf ), buf, len);
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

#define EL_NAME   xa_VariableReference
#define EL_STRUCT zx_xa_VariableReference_s
#define EL_NS     xa
#define EL_TAG    VariableReference

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

/* FUNC(zx_LEN_SO_xa_VariableReference) */

/* Compute length of an element (and its subelements). The XML attributes
 * and elements are processed in schema order. */

/* Called by: */
int zx_LEN_SO_xa_VariableReference(struct zx_ctx* c, struct zx_xa_VariableReference_s* x )
{
  struct zx_ns_s* pop_seen = 0;
  struct zx_elem_s* se MAYBE_UNUSED;
#if 1 /* NORMALMODE */
  /* *** in simple_elem case should output ns prefix from ns node. */
  int len = sizeof("<xa:VariableReference")-1 + 1 + sizeof("</xa:VariableReference>")-1;
  if (c->inc_ns_len)
    len += zx_len_inc_ns(c, &pop_seen);
  len += zx_len_xmlns_if_not_seen(c, zx_ns_tab+zx_xmlns_ix_xa, &pop_seen);

  len += zx_attr_so_len(x->VariableId, sizeof("VariableId")-1);

#else
  /* root node has no begin tag */
  int len = 0;
#endif
  


  len += zx_len_so_common(c, &x->gg);
  zx_pop_seen(pop_seen);
  ENC_LEN_DEBUG(x, "xa:VariableReference", len);
  return len;
}

/* FUNC(zx_LEN_WO_xa_VariableReference) */

/* Compute length of an element (and its subelements). The XML attributes
 * and elements are processed in wire order and no assumptions
 * are made about namespace prefixes. */

/* Called by: */
int zx_LEN_WO_xa_VariableReference(struct zx_ctx* c, struct zx_xa_VariableReference_s* x )
{
  struct zx_ns_s* pop_seen = 0;
  struct zx_elem_s* se MAYBE_UNUSED;
#if 1 /* NORMALMODE */
  int len = 1 + sizeof("VariableReference")-1 + 1 + 2 + sizeof("VariableReference")-1 + 1;
  
  if (x->gg.g.ns && x->gg.g.ns->prefix_len)
    len += (x->gg.g.ns->prefix_len + 1) * 2;
  if (c->inc_ns_len)
    len += zx_len_inc_ns(c, &pop_seen);
  len += zx_len_xmlns_if_not_seen(c, x->gg.g.ns, &pop_seen);

  len += zx_attr_wo_len(x->VariableId, sizeof("VariableId")-1);

#else
  /* root node has no begin tag */
  int len = 0;
#endif
  


  len += zx_len_wo_common(c, &x->gg); 
  zx_pop_seen(pop_seen);
  ENC_LEN_DEBUG(x, "xa:VariableReference", len);
  return len;
}

/* FUNC(zx_ENC_SO_xa_VariableReference) */

/* Render element into string. The XML attributes and elements are
 * processed in schema order. This is what you generally want for
 * rendering new data structure to a string. The wo pointers are not used. */

/* Called by: */
char* zx_ENC_SO_xa_VariableReference(struct zx_ctx* c, struct zx_xa_VariableReference_s* x, char* p )
{
  struct zx_elem_s* se MAYBE_UNUSED;
  ENC_LEN_DEBUG_BASE;
#if 1 /* NORMALMODE */
  struct zx_ns_s* pop_seen = 0;
  /* *** in simple_elem case should output ns prefix from ns node. */
  ZX_OUT_TAG(p, "<xa:VariableReference");
  if (c->inc_ns)
    p = zx_enc_inc_ns(c, p, &pop_seen);
  p = zx_enc_xmlns_if_not_seen(c, p, zx_ns_tab+zx_xmlns_ix_xa, &pop_seen);

  p = zx_attr_so_enc(p, x->VariableId, " VariableId=\"", sizeof(" VariableId=\"")-1);

  p = zx_enc_unknown_attrs(p, x->gg.any_attr);
#else
  /* root node has no begin tag */
#endif
  

  p = zx_enc_so_unknown_elems_and_content(c, p, &x->gg);
  
#if 1 /* NORMALMODE */
  ZX_OUT_CLOSE_TAG(p, "</xa:VariableReference>");
  zx_pop_seen(pop_seen);
#else
  /* root node has no end tag either */
#endif
  ENC_LEN_DEBUG(x, "xa:VariableReference", p-enc_base);
  return p;
}

/* FUNC(zx_ENC_WO_xa_VariableReference) */

/* Render element into string. The XML attributes and elements are
 * processed in wire order by chasing wo pointers. This is what you want for
 * validating signatures on other people's XML documents. */

/* Called by: */
char* zx_ENC_WO_xa_VariableReference(struct zx_ctx* c, struct zx_xa_VariableReference_s* x, char* p )
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
  ZX_OUT_MEM(p, "VariableReference", sizeof("VariableReference")-1);
  qq = p;

  /* *** sort the namespaces */
  if (c->inc_ns)
    zx_add_inc_ns(c, &pop_seen);
  zx_add_xmlns_if_not_seen(c, x->gg.g.ns, &pop_seen);

  p = zx_enc_seen(p, pop_seen); 
  p = zx_attr_wo_enc(p, x->VariableId, "VariableId=\"", sizeof("VariableId=\"")-1);

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
  ENC_LEN_DEBUG(x, "xa:VariableReference", p-enc_base);
  return p;
}

/* FUNC(zx_EASY_ENC_SO_xa_VariableReference) */

/* Called by: */
struct zx_str* zx_EASY_ENC_SO_xa_VariableReference(struct zx_ctx* c, struct zx_xa_VariableReference_s* x )
{
  int len;
  char* buf;
  c->ns_tab = ZX_ALLOC(c, sizeof(zx_ns_tab));
  memcpy(c->ns_tab, zx_ns_tab, sizeof(zx_ns_tab));
  len = zx_LEN_SO_xa_VariableReference(c, x );
  buf = ZX_ALLOC(c, len+1);
  return zx_easy_enc_common(c, zx_ENC_SO_xa_VariableReference(c, x, buf ), buf, len);
}

/* FUNC(zx_EASY_ENC_WO_xa_VariableReference) */

/* Called by: */
struct zx_str* zx_EASY_ENC_WO_xa_VariableReference(struct zx_ctx* c, struct zx_xa_VariableReference_s* x )
{
  int len;
  char* buf;
  c->ns_tab = ZX_ALLOC(c, sizeof(zx_ns_tab));
  memcpy(c->ns_tab, zx_ns_tab, sizeof(zx_ns_tab));
  len = zx_LEN_WO_xa_VariableReference(c, x );
  buf = ZX_ALLOC(c, len+1);
  return zx_easy_enc_common(c, zx_ENC_WO_xa_VariableReference(c, x, buf ), buf, len);
}




/* EOF -- c/zx-xa-enc.c */
