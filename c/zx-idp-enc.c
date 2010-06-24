/* c/zx-idp-enc.c - WARNING: This file was automatically generated. DO NOT EDIT!
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
#include "c/zx-idp-data.h"
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

#define EL_NAME   idp_AssertionItem
#define EL_STRUCT zx_idp_AssertionItem_s
#define EL_NS     idp
#define EL_TAG    AssertionItem

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

/* FUNC(zx_LEN_SO_idp_AssertionItem) */

/* Compute length of an element (and its subelements). The XML attributes
 * and elements are processed in schema order. */

/* Called by: */
int zx_LEN_SO_idp_AssertionItem(struct zx_ctx* c, struct zx_idp_AssertionItem_s* x )
{
  struct zx_ns_s* pop_seen = 0;
  struct zx_elem_s* se MAYBE_UNUSED;
#if 1 /* NORMALMODE */
  /* *** in simple_elem case should output ns prefix from ns node. */
  int len = sizeof("<idp:AssertionItem")-1 + 1 + sizeof("</idp:AssertionItem>")-1;
  if (c->inc_ns_len)
    len += zx_len_inc_ns(c, &pop_seen);
  len += zx_len_xmlns_if_not_seen(c, zx_ns_tab+zx_xmlns_ix_idp, &pop_seen);

  len += zx_attr_so_len(x->created, sizeof("created")-1);
  len += zx_attr_so_len(x->id, sizeof("id")-1);

#else
  /* root node has no begin tag */
  int len = 0;
#endif
  
  {
      struct zx_idp_MEDInfo_s* e;
      for (e = x->MEDInfo; e; e = (struct zx_idp_MEDInfo_s*)e->gg.g.n)
	  len += zx_LEN_SO_idp_MEDInfo(c, e);
  }
  {
      struct zx_sa_Assertion_s* e;
      for (e = x->Assertion; e; e = (struct zx_sa_Assertion_s*)e->gg.g.n)
	  len += zx_LEN_SO_sa_Assertion(c, e);
  }


  len += zx_len_so_common(c, &x->gg);
  zx_pop_seen(pop_seen);
  ENC_LEN_DEBUG(x, "idp:AssertionItem", len);
  return len;
}

/* FUNC(zx_LEN_WO_idp_AssertionItem) */

/* Compute length of an element (and its subelements). The XML attributes
 * and elements are processed in wire order and no assumptions
 * are made about namespace prefixes. */

/* Called by: */
int zx_LEN_WO_idp_AssertionItem(struct zx_ctx* c, struct zx_idp_AssertionItem_s* x )
{
  struct zx_ns_s* pop_seen = 0;
  struct zx_elem_s* se MAYBE_UNUSED;
#if 1 /* NORMALMODE */
  int len = 1 + sizeof("AssertionItem")-1 + 1 + 2 + sizeof("AssertionItem")-1 + 1;
  
  if (x->gg.g.ns && x->gg.g.ns->prefix_len)
    len += (x->gg.g.ns->prefix_len + 1) * 2;
  if (c->inc_ns_len)
    len += zx_len_inc_ns(c, &pop_seen);
  len += zx_len_xmlns_if_not_seen(c, x->gg.g.ns, &pop_seen);

  len += zx_attr_wo_len(x->created, sizeof("created")-1);
  len += zx_attr_wo_len(x->id, sizeof("id")-1);

#else
  /* root node has no begin tag */
  int len = 0;
#endif
  
  {
      struct zx_idp_MEDInfo_s* e;
      for (e = x->MEDInfo; e; e = (struct zx_idp_MEDInfo_s*)e->gg.g.n)
	  len += zx_LEN_WO_idp_MEDInfo(c, e);
  }
  {
      struct zx_sa_Assertion_s* e;
      for (e = x->Assertion; e; e = (struct zx_sa_Assertion_s*)e->gg.g.n)
	  len += zx_LEN_WO_sa_Assertion(c, e);
  }


  len += zx_len_wo_common(c, &x->gg); 
  zx_pop_seen(pop_seen);
  ENC_LEN_DEBUG(x, "idp:AssertionItem", len);
  return len;
}

/* FUNC(zx_ENC_SO_idp_AssertionItem) */

/* Render element into string. The XML attributes and elements are
 * processed in schema order. This is what you generally want for
 * rendering new data structure to a string. The wo pointers are not used. */

/* Called by: */
char* zx_ENC_SO_idp_AssertionItem(struct zx_ctx* c, struct zx_idp_AssertionItem_s* x, char* p )
{
  struct zx_elem_s* se MAYBE_UNUSED;
  ENC_LEN_DEBUG_BASE;
#if 1 /* NORMALMODE */
  struct zx_ns_s* pop_seen = 0;
  /* *** in simple_elem case should output ns prefix from ns node. */
  ZX_OUT_TAG(p, "<idp:AssertionItem");
  if (c->inc_ns)
    p = zx_enc_inc_ns(c, p, &pop_seen);
  p = zx_enc_xmlns_if_not_seen(c, p, zx_ns_tab+zx_xmlns_ix_idp, &pop_seen);

  p = zx_attr_so_enc(p, x->created, " created=\"", sizeof(" created=\"")-1);
  p = zx_attr_so_enc(p, x->id, " id=\"", sizeof(" id=\"")-1);

  p = zx_enc_unknown_attrs(p, x->gg.any_attr);
#else
  /* root node has no begin tag */
#endif
  
  {
      struct zx_idp_MEDInfo_s* e;
      for (e = x->MEDInfo; e; e = (struct zx_idp_MEDInfo_s*)e->gg.g.n)
	  p = zx_ENC_SO_idp_MEDInfo(c, e, p);
  }
  {
      struct zx_sa_Assertion_s* e;
      for (e = x->Assertion; e; e = (struct zx_sa_Assertion_s*)e->gg.g.n)
	  p = zx_ENC_SO_sa_Assertion(c, e, p);
  }

  p = zx_enc_so_unknown_elems_and_content(c, p, &x->gg);
  
#if 1 /* NORMALMODE */
  ZX_OUT_CLOSE_TAG(p, "</idp:AssertionItem>");
  zx_pop_seen(pop_seen);
#else
  /* root node has no end tag either */
#endif
  ENC_LEN_DEBUG(x, "idp:AssertionItem", p-enc_base);
  return p;
}

/* FUNC(zx_ENC_WO_idp_AssertionItem) */

/* Render element into string. The XML attributes and elements are
 * processed in wire order by chasing wo pointers. This is what you want for
 * validating signatures on other people's XML documents. */

/* Called by: */
char* zx_ENC_WO_idp_AssertionItem(struct zx_ctx* c, struct zx_idp_AssertionItem_s* x, char* p )
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
  ZX_OUT_MEM(p, "AssertionItem", sizeof("AssertionItem")-1);
  qq = p;

  /* *** sort the namespaces */
  if (c->inc_ns)
    zx_add_inc_ns(c, &pop_seen);
  zx_add_xmlns_if_not_seen(c, x->gg.g.ns, &pop_seen);

  p = zx_enc_seen(p, pop_seen); 
  p = zx_attr_wo_enc(p, x->created, "created=\"", sizeof("created=\"")-1);
  p = zx_attr_wo_enc(p, x->id, "id=\"", sizeof("id=\"")-1);

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
  ENC_LEN_DEBUG(x, "idp:AssertionItem", p-enc_base);
  return p;
}

/* FUNC(zx_EASY_ENC_SO_idp_AssertionItem) */

/* Called by: */
struct zx_str* zx_EASY_ENC_SO_idp_AssertionItem(struct zx_ctx* c, struct zx_idp_AssertionItem_s* x )
{
  int len;
  char* buf;
  c->ns_tab = ZX_ALLOC(c, sizeof(zx_ns_tab));
  memcpy(c->ns_tab, zx_ns_tab, sizeof(zx_ns_tab));
  len = zx_LEN_SO_idp_AssertionItem(c, x );
  buf = ZX_ALLOC(c, len+1);
  return zx_easy_enc_common(c, zx_ENC_SO_idp_AssertionItem(c, x, buf ), buf, len);
}

/* FUNC(zx_EASY_ENC_WO_idp_AssertionItem) */

/* Called by: */
struct zx_str* zx_EASY_ENC_WO_idp_AssertionItem(struct zx_ctx* c, struct zx_idp_AssertionItem_s* x )
{
  int len;
  char* buf;
  c->ns_tab = ZX_ALLOC(c, sizeof(zx_ns_tab));
  memcpy(c->ns_tab, zx_ns_tab, sizeof(zx_ns_tab));
  len = zx_LEN_WO_idp_AssertionItem(c, x );
  buf = ZX_ALLOC(c, len+1);
  return zx_easy_enc_common(c, zx_ENC_WO_idp_AssertionItem(c, x, buf ), buf, len);
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

#define EL_NAME   idp_AuthnContextRestriction
#define EL_STRUCT zx_idp_AuthnContextRestriction_s
#define EL_NS     idp
#define EL_TAG    AuthnContextRestriction

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

/* FUNC(zx_LEN_SO_idp_AuthnContextRestriction) */

/* Compute length of an element (and its subelements). The XML attributes
 * and elements are processed in schema order. */

/* Called by: */
int zx_LEN_SO_idp_AuthnContextRestriction(struct zx_ctx* c, struct zx_idp_AuthnContextRestriction_s* x )
{
  struct zx_ns_s* pop_seen = 0;
  struct zx_elem_s* se MAYBE_UNUSED;
#if 1 /* NORMALMODE */
  /* *** in simple_elem case should output ns prefix from ns node. */
  int len = sizeof("<idp:AuthnContextRestriction")-1 + 1 + sizeof("</idp:AuthnContextRestriction>")-1;
  if (c->inc_ns_len)
    len += zx_len_inc_ns(c, &pop_seen);
  len += zx_len_xmlns_if_not_seen(c, zx_ns_tab+zx_xmlns_ix_idp, &pop_seen);


#else
  /* root node has no begin tag */
  int len = 0;
#endif
  
  {
      struct zx_sa_AuthnContext_s* e;
      for (e = x->AuthnContext; e; e = (struct zx_sa_AuthnContext_s*)e->gg.g.n)
	  len += zx_LEN_SO_sa_AuthnContext(c, e);
  }


  len += zx_len_so_common(c, &x->gg);
  zx_pop_seen(pop_seen);
  ENC_LEN_DEBUG(x, "idp:AuthnContextRestriction", len);
  return len;
}

/* FUNC(zx_LEN_WO_idp_AuthnContextRestriction) */

/* Compute length of an element (and its subelements). The XML attributes
 * and elements are processed in wire order and no assumptions
 * are made about namespace prefixes. */

/* Called by: */
int zx_LEN_WO_idp_AuthnContextRestriction(struct zx_ctx* c, struct zx_idp_AuthnContextRestriction_s* x )
{
  struct zx_ns_s* pop_seen = 0;
  struct zx_elem_s* se MAYBE_UNUSED;
#if 1 /* NORMALMODE */
  int len = 1 + sizeof("AuthnContextRestriction")-1 + 1 + 2 + sizeof("AuthnContextRestriction")-1 + 1;
  
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
      struct zx_sa_AuthnContext_s* e;
      for (e = x->AuthnContext; e; e = (struct zx_sa_AuthnContext_s*)e->gg.g.n)
	  len += zx_LEN_WO_sa_AuthnContext(c, e);
  }


  len += zx_len_wo_common(c, &x->gg); 
  zx_pop_seen(pop_seen);
  ENC_LEN_DEBUG(x, "idp:AuthnContextRestriction", len);
  return len;
}

/* FUNC(zx_ENC_SO_idp_AuthnContextRestriction) */

/* Render element into string. The XML attributes and elements are
 * processed in schema order. This is what you generally want for
 * rendering new data structure to a string. The wo pointers are not used. */

/* Called by: */
char* zx_ENC_SO_idp_AuthnContextRestriction(struct zx_ctx* c, struct zx_idp_AuthnContextRestriction_s* x, char* p )
{
  struct zx_elem_s* se MAYBE_UNUSED;
  ENC_LEN_DEBUG_BASE;
#if 1 /* NORMALMODE */
  struct zx_ns_s* pop_seen = 0;
  /* *** in simple_elem case should output ns prefix from ns node. */
  ZX_OUT_TAG(p, "<idp:AuthnContextRestriction");
  if (c->inc_ns)
    p = zx_enc_inc_ns(c, p, &pop_seen);
  p = zx_enc_xmlns_if_not_seen(c, p, zx_ns_tab+zx_xmlns_ix_idp, &pop_seen);


  p = zx_enc_unknown_attrs(p, x->gg.any_attr);
#else
  /* root node has no begin tag */
#endif
  
  {
      struct zx_sa_AuthnContext_s* e;
      for (e = x->AuthnContext; e; e = (struct zx_sa_AuthnContext_s*)e->gg.g.n)
	  p = zx_ENC_SO_sa_AuthnContext(c, e, p);
  }

  p = zx_enc_so_unknown_elems_and_content(c, p, &x->gg);
  
#if 1 /* NORMALMODE */
  ZX_OUT_CLOSE_TAG(p, "</idp:AuthnContextRestriction>");
  zx_pop_seen(pop_seen);
#else
  /* root node has no end tag either */
#endif
  ENC_LEN_DEBUG(x, "idp:AuthnContextRestriction", p-enc_base);
  return p;
}

/* FUNC(zx_ENC_WO_idp_AuthnContextRestriction) */

/* Render element into string. The XML attributes and elements are
 * processed in wire order by chasing wo pointers. This is what you want for
 * validating signatures on other people's XML documents. */

/* Called by: */
char* zx_ENC_WO_idp_AuthnContextRestriction(struct zx_ctx* c, struct zx_idp_AuthnContextRestriction_s* x, char* p )
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
  ZX_OUT_MEM(p, "AuthnContextRestriction", sizeof("AuthnContextRestriction")-1);
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
  ENC_LEN_DEBUG(x, "idp:AuthnContextRestriction", p-enc_base);
  return p;
}

/* FUNC(zx_EASY_ENC_SO_idp_AuthnContextRestriction) */

/* Called by: */
struct zx_str* zx_EASY_ENC_SO_idp_AuthnContextRestriction(struct zx_ctx* c, struct zx_idp_AuthnContextRestriction_s* x )
{
  int len;
  char* buf;
  c->ns_tab = ZX_ALLOC(c, sizeof(zx_ns_tab));
  memcpy(c->ns_tab, zx_ns_tab, sizeof(zx_ns_tab));
  len = zx_LEN_SO_idp_AuthnContextRestriction(c, x );
  buf = ZX_ALLOC(c, len+1);
  return zx_easy_enc_common(c, zx_ENC_SO_idp_AuthnContextRestriction(c, x, buf ), buf, len);
}

/* FUNC(zx_EASY_ENC_WO_idp_AuthnContextRestriction) */

/* Called by: */
struct zx_str* zx_EASY_ENC_WO_idp_AuthnContextRestriction(struct zx_ctx* c, struct zx_idp_AuthnContextRestriction_s* x )
{
  int len;
  char* buf;
  c->ns_tab = ZX_ALLOC(c, sizeof(zx_ns_tab));
  memcpy(c->ns_tab, zx_ns_tab, sizeof(zx_ns_tab));
  len = zx_LEN_WO_idp_AuthnContextRestriction(c, x );
  buf = ZX_ALLOC(c, len+1);
  return zx_easy_enc_common(c, zx_ENC_WO_idp_AuthnContextRestriction(c, x, buf ), buf, len);
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

#define EL_NAME   idp_CreatedStatus
#define EL_STRUCT zx_idp_CreatedStatus_s
#define EL_NS     idp
#define EL_TAG    CreatedStatus

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

/* FUNC(zx_LEN_SO_idp_CreatedStatus) */

/* Compute length of an element (and its subelements). The XML attributes
 * and elements are processed in schema order. */

/* Called by: */
int zx_LEN_SO_idp_CreatedStatus(struct zx_ctx* c, struct zx_idp_CreatedStatus_s* x )
{
  struct zx_ns_s* pop_seen = 0;
  struct zx_elem_s* se MAYBE_UNUSED;
#if 1 /* NORMALMODE */
  /* *** in simple_elem case should output ns prefix from ns node. */
  int len = sizeof("<idp:CreatedStatus")-1 + 1 + sizeof("</idp:CreatedStatus>")-1;
  if (c->inc_ns_len)
    len += zx_len_inc_ns(c, &pop_seen);
  len += zx_len_xmlns_if_not_seen(c, zx_ns_tab+zx_xmlns_ix_idp, &pop_seen);


#else
  /* root node has no begin tag */
  int len = 0;
#endif
  
  {
      struct zx_idp_CreatedStatusItem_s* e;
      for (e = x->CreatedStatusItem; e; e = (struct zx_idp_CreatedStatusItem_s*)e->gg.g.n)
	  len += zx_LEN_SO_idp_CreatedStatusItem(c, e);
  }


  len += zx_len_so_common(c, &x->gg);
  zx_pop_seen(pop_seen);
  ENC_LEN_DEBUG(x, "idp:CreatedStatus", len);
  return len;
}

/* FUNC(zx_LEN_WO_idp_CreatedStatus) */

/* Compute length of an element (and its subelements). The XML attributes
 * and elements are processed in wire order and no assumptions
 * are made about namespace prefixes. */

/* Called by: */
int zx_LEN_WO_idp_CreatedStatus(struct zx_ctx* c, struct zx_idp_CreatedStatus_s* x )
{
  struct zx_ns_s* pop_seen = 0;
  struct zx_elem_s* se MAYBE_UNUSED;
#if 1 /* NORMALMODE */
  int len = 1 + sizeof("CreatedStatus")-1 + 1 + 2 + sizeof("CreatedStatus")-1 + 1;
  
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
      struct zx_idp_CreatedStatusItem_s* e;
      for (e = x->CreatedStatusItem; e; e = (struct zx_idp_CreatedStatusItem_s*)e->gg.g.n)
	  len += zx_LEN_WO_idp_CreatedStatusItem(c, e);
  }


  len += zx_len_wo_common(c, &x->gg); 
  zx_pop_seen(pop_seen);
  ENC_LEN_DEBUG(x, "idp:CreatedStatus", len);
  return len;
}

/* FUNC(zx_ENC_SO_idp_CreatedStatus) */

/* Render element into string. The XML attributes and elements are
 * processed in schema order. This is what you generally want for
 * rendering new data structure to a string. The wo pointers are not used. */

/* Called by: */
char* zx_ENC_SO_idp_CreatedStatus(struct zx_ctx* c, struct zx_idp_CreatedStatus_s* x, char* p )
{
  struct zx_elem_s* se MAYBE_UNUSED;
  ENC_LEN_DEBUG_BASE;
#if 1 /* NORMALMODE */
  struct zx_ns_s* pop_seen = 0;
  /* *** in simple_elem case should output ns prefix from ns node. */
  ZX_OUT_TAG(p, "<idp:CreatedStatus");
  if (c->inc_ns)
    p = zx_enc_inc_ns(c, p, &pop_seen);
  p = zx_enc_xmlns_if_not_seen(c, p, zx_ns_tab+zx_xmlns_ix_idp, &pop_seen);


  p = zx_enc_unknown_attrs(p, x->gg.any_attr);
#else
  /* root node has no begin tag */
#endif
  
  {
      struct zx_idp_CreatedStatusItem_s* e;
      for (e = x->CreatedStatusItem; e; e = (struct zx_idp_CreatedStatusItem_s*)e->gg.g.n)
	  p = zx_ENC_SO_idp_CreatedStatusItem(c, e, p);
  }

  p = zx_enc_so_unknown_elems_and_content(c, p, &x->gg);
  
#if 1 /* NORMALMODE */
  ZX_OUT_CLOSE_TAG(p, "</idp:CreatedStatus>");
  zx_pop_seen(pop_seen);
#else
  /* root node has no end tag either */
#endif
  ENC_LEN_DEBUG(x, "idp:CreatedStatus", p-enc_base);
  return p;
}

/* FUNC(zx_ENC_WO_idp_CreatedStatus) */

/* Render element into string. The XML attributes and elements are
 * processed in wire order by chasing wo pointers. This is what you want for
 * validating signatures on other people's XML documents. */

/* Called by: */
char* zx_ENC_WO_idp_CreatedStatus(struct zx_ctx* c, struct zx_idp_CreatedStatus_s* x, char* p )
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
  ZX_OUT_MEM(p, "CreatedStatus", sizeof("CreatedStatus")-1);
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
  ENC_LEN_DEBUG(x, "idp:CreatedStatus", p-enc_base);
  return p;
}

/* FUNC(zx_EASY_ENC_SO_idp_CreatedStatus) */

/* Called by: */
struct zx_str* zx_EASY_ENC_SO_idp_CreatedStatus(struct zx_ctx* c, struct zx_idp_CreatedStatus_s* x )
{
  int len;
  char* buf;
  c->ns_tab = ZX_ALLOC(c, sizeof(zx_ns_tab));
  memcpy(c->ns_tab, zx_ns_tab, sizeof(zx_ns_tab));
  len = zx_LEN_SO_idp_CreatedStatus(c, x );
  buf = ZX_ALLOC(c, len+1);
  return zx_easy_enc_common(c, zx_ENC_SO_idp_CreatedStatus(c, x, buf ), buf, len);
}

/* FUNC(zx_EASY_ENC_WO_idp_CreatedStatus) */

/* Called by: */
struct zx_str* zx_EASY_ENC_WO_idp_CreatedStatus(struct zx_ctx* c, struct zx_idp_CreatedStatus_s* x )
{
  int len;
  char* buf;
  c->ns_tab = ZX_ALLOC(c, sizeof(zx_ns_tab));
  memcpy(c->ns_tab, zx_ns_tab, sizeof(zx_ns_tab));
  len = zx_LEN_WO_idp_CreatedStatus(c, x );
  buf = ZX_ALLOC(c, len+1);
  return zx_easy_enc_common(c, zx_ENC_WO_idp_CreatedStatus(c, x, buf ), buf, len);
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

#define EL_NAME   idp_CreatedStatusItem
#define EL_STRUCT zx_idp_CreatedStatusItem_s
#define EL_NS     idp
#define EL_TAG    CreatedStatusItem

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

/* FUNC(zx_LEN_SO_idp_CreatedStatusItem) */

/* Compute length of an element (and its subelements). The XML attributes
 * and elements are processed in schema order. */

/* Called by: */
int zx_LEN_SO_idp_CreatedStatusItem(struct zx_ctx* c, struct zx_idp_CreatedStatusItem_s* x )
{
  struct zx_ns_s* pop_seen = 0;
  struct zx_elem_s* se MAYBE_UNUSED;
#if 1 /* NORMALMODE */
  /* *** in simple_elem case should output ns prefix from ns node. */
  int len = sizeof("<idp:CreatedStatusItem")-1 + 1 + sizeof("</idp:CreatedStatusItem>")-1;
  if (c->inc_ns_len)
    len += zx_len_inc_ns(c, &pop_seen);
  len += zx_len_xmlns_if_not_seen(c, zx_ns_tab+zx_xmlns_ix_idp, &pop_seen);

  len += zx_attr_so_len(x->firstUsed, sizeof("firstUsed")-1);
  len += zx_attr_so_len(x->ref, sizeof("ref")-1);
  len += zx_attr_so_len(x->used, sizeof("used")-1);

#else
  /* root node has no begin tag */
  int len = 0;
#endif
  


  len += zx_len_so_common(c, &x->gg);
  zx_pop_seen(pop_seen);
  ENC_LEN_DEBUG(x, "idp:CreatedStatusItem", len);
  return len;
}

/* FUNC(zx_LEN_WO_idp_CreatedStatusItem) */

/* Compute length of an element (and its subelements). The XML attributes
 * and elements are processed in wire order and no assumptions
 * are made about namespace prefixes. */

/* Called by: */
int zx_LEN_WO_idp_CreatedStatusItem(struct zx_ctx* c, struct zx_idp_CreatedStatusItem_s* x )
{
  struct zx_ns_s* pop_seen = 0;
  struct zx_elem_s* se MAYBE_UNUSED;
#if 1 /* NORMALMODE */
  int len = 1 + sizeof("CreatedStatusItem")-1 + 1 + 2 + sizeof("CreatedStatusItem")-1 + 1;
  
  if (x->gg.g.ns && x->gg.g.ns->prefix_len)
    len += (x->gg.g.ns->prefix_len + 1) * 2;
  if (c->inc_ns_len)
    len += zx_len_inc_ns(c, &pop_seen);
  len += zx_len_xmlns_if_not_seen(c, x->gg.g.ns, &pop_seen);

  len += zx_attr_wo_len(x->firstUsed, sizeof("firstUsed")-1);
  len += zx_attr_wo_len(x->ref, sizeof("ref")-1);
  len += zx_attr_wo_len(x->used, sizeof("used")-1);

#else
  /* root node has no begin tag */
  int len = 0;
#endif
  


  len += zx_len_wo_common(c, &x->gg); 
  zx_pop_seen(pop_seen);
  ENC_LEN_DEBUG(x, "idp:CreatedStatusItem", len);
  return len;
}

/* FUNC(zx_ENC_SO_idp_CreatedStatusItem) */

/* Render element into string. The XML attributes and elements are
 * processed in schema order. This is what you generally want for
 * rendering new data structure to a string. The wo pointers are not used. */

/* Called by: */
char* zx_ENC_SO_idp_CreatedStatusItem(struct zx_ctx* c, struct zx_idp_CreatedStatusItem_s* x, char* p )
{
  struct zx_elem_s* se MAYBE_UNUSED;
  ENC_LEN_DEBUG_BASE;
#if 1 /* NORMALMODE */
  struct zx_ns_s* pop_seen = 0;
  /* *** in simple_elem case should output ns prefix from ns node. */
  ZX_OUT_TAG(p, "<idp:CreatedStatusItem");
  if (c->inc_ns)
    p = zx_enc_inc_ns(c, p, &pop_seen);
  p = zx_enc_xmlns_if_not_seen(c, p, zx_ns_tab+zx_xmlns_ix_idp, &pop_seen);

  p = zx_attr_so_enc(p, x->firstUsed, " firstUsed=\"", sizeof(" firstUsed=\"")-1);
  p = zx_attr_so_enc(p, x->ref, " ref=\"", sizeof(" ref=\"")-1);
  p = zx_attr_so_enc(p, x->used, " used=\"", sizeof(" used=\"")-1);

  p = zx_enc_unknown_attrs(p, x->gg.any_attr);
#else
  /* root node has no begin tag */
#endif
  

  p = zx_enc_so_unknown_elems_and_content(c, p, &x->gg);
  
#if 1 /* NORMALMODE */
  ZX_OUT_CLOSE_TAG(p, "</idp:CreatedStatusItem>");
  zx_pop_seen(pop_seen);
#else
  /* root node has no end tag either */
#endif
  ENC_LEN_DEBUG(x, "idp:CreatedStatusItem", p-enc_base);
  return p;
}

/* FUNC(zx_ENC_WO_idp_CreatedStatusItem) */

/* Render element into string. The XML attributes and elements are
 * processed in wire order by chasing wo pointers. This is what you want for
 * validating signatures on other people's XML documents. */

/* Called by: */
char* zx_ENC_WO_idp_CreatedStatusItem(struct zx_ctx* c, struct zx_idp_CreatedStatusItem_s* x, char* p )
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
  ZX_OUT_MEM(p, "CreatedStatusItem", sizeof("CreatedStatusItem")-1);
  qq = p;

  /* *** sort the namespaces */
  if (c->inc_ns)
    zx_add_inc_ns(c, &pop_seen);
  zx_add_xmlns_if_not_seen(c, x->gg.g.ns, &pop_seen);

  p = zx_enc_seen(p, pop_seen); 
  p = zx_attr_wo_enc(p, x->firstUsed, "firstUsed=\"", sizeof("firstUsed=\"")-1);
  p = zx_attr_wo_enc(p, x->ref, "ref=\"", sizeof("ref=\"")-1);
  p = zx_attr_wo_enc(p, x->used, "used=\"", sizeof("used=\"")-1);

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
  ENC_LEN_DEBUG(x, "idp:CreatedStatusItem", p-enc_base);
  return p;
}

/* FUNC(zx_EASY_ENC_SO_idp_CreatedStatusItem) */

/* Called by: */
struct zx_str* zx_EASY_ENC_SO_idp_CreatedStatusItem(struct zx_ctx* c, struct zx_idp_CreatedStatusItem_s* x )
{
  int len;
  char* buf;
  c->ns_tab = ZX_ALLOC(c, sizeof(zx_ns_tab));
  memcpy(c->ns_tab, zx_ns_tab, sizeof(zx_ns_tab));
  len = zx_LEN_SO_idp_CreatedStatusItem(c, x );
  buf = ZX_ALLOC(c, len+1);
  return zx_easy_enc_common(c, zx_ENC_SO_idp_CreatedStatusItem(c, x, buf ), buf, len);
}

/* FUNC(zx_EASY_ENC_WO_idp_CreatedStatusItem) */

/* Called by: */
struct zx_str* zx_EASY_ENC_WO_idp_CreatedStatusItem(struct zx_ctx* c, struct zx_idp_CreatedStatusItem_s* x )
{
  int len;
  char* buf;
  c->ns_tab = ZX_ALLOC(c, sizeof(zx_ns_tab));
  memcpy(c->ns_tab, zx_ns_tab, sizeof(zx_ns_tab));
  len = zx_LEN_WO_idp_CreatedStatusItem(c, x );
  buf = ZX_ALLOC(c, len+1);
  return zx_easy_enc_common(c, zx_ENC_WO_idp_CreatedStatusItem(c, x, buf ), buf, len);
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

#define EL_NAME   idp_CreatedStatusResponse
#define EL_STRUCT zx_idp_CreatedStatusResponse_s
#define EL_NS     idp
#define EL_TAG    CreatedStatusResponse

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

/* FUNC(zx_LEN_SO_idp_CreatedStatusResponse) */

/* Compute length of an element (and its subelements). The XML attributes
 * and elements are processed in schema order. */

/* Called by: */
int zx_LEN_SO_idp_CreatedStatusResponse(struct zx_ctx* c, struct zx_idp_CreatedStatusResponse_s* x )
{
  struct zx_ns_s* pop_seen = 0;
  struct zx_elem_s* se MAYBE_UNUSED;
#if 1 /* NORMALMODE */
  /* *** in simple_elem case should output ns prefix from ns node. */
  int len = sizeof("<idp:CreatedStatusResponse")-1 + 1 + sizeof("</idp:CreatedStatusResponse>")-1;
  if (c->inc_ns_len)
    len += zx_len_inc_ns(c, &pop_seen);
  len += zx_len_xmlns_if_not_seen(c, zx_ns_tab+zx_xmlns_ix_idp, &pop_seen);


#else
  /* root node has no begin tag */
  int len = 0;
#endif
  
  {
      struct zx_lu_Status_s* e;
      for (e = x->Status; e; e = (struct zx_lu_Status_s*)e->gg.g.n)
	  len += zx_LEN_SO_lu_Status(c, e);
  }


  len += zx_len_so_common(c, &x->gg);
  zx_pop_seen(pop_seen);
  ENC_LEN_DEBUG(x, "idp:CreatedStatusResponse", len);
  return len;
}

/* FUNC(zx_LEN_WO_idp_CreatedStatusResponse) */

/* Compute length of an element (and its subelements). The XML attributes
 * and elements are processed in wire order and no assumptions
 * are made about namespace prefixes. */

/* Called by: */
int zx_LEN_WO_idp_CreatedStatusResponse(struct zx_ctx* c, struct zx_idp_CreatedStatusResponse_s* x )
{
  struct zx_ns_s* pop_seen = 0;
  struct zx_elem_s* se MAYBE_UNUSED;
#if 1 /* NORMALMODE */
  int len = 1 + sizeof("CreatedStatusResponse")-1 + 1 + 2 + sizeof("CreatedStatusResponse")-1 + 1;
  
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
      struct zx_lu_Status_s* e;
      for (e = x->Status; e; e = (struct zx_lu_Status_s*)e->gg.g.n)
	  len += zx_LEN_WO_lu_Status(c, e);
  }


  len += zx_len_wo_common(c, &x->gg); 
  zx_pop_seen(pop_seen);
  ENC_LEN_DEBUG(x, "idp:CreatedStatusResponse", len);
  return len;
}

/* FUNC(zx_ENC_SO_idp_CreatedStatusResponse) */

/* Render element into string. The XML attributes and elements are
 * processed in schema order. This is what you generally want for
 * rendering new data structure to a string. The wo pointers are not used. */

/* Called by: */
char* zx_ENC_SO_idp_CreatedStatusResponse(struct zx_ctx* c, struct zx_idp_CreatedStatusResponse_s* x, char* p )
{
  struct zx_elem_s* se MAYBE_UNUSED;
  ENC_LEN_DEBUG_BASE;
#if 1 /* NORMALMODE */
  struct zx_ns_s* pop_seen = 0;
  /* *** in simple_elem case should output ns prefix from ns node. */
  ZX_OUT_TAG(p, "<idp:CreatedStatusResponse");
  if (c->inc_ns)
    p = zx_enc_inc_ns(c, p, &pop_seen);
  p = zx_enc_xmlns_if_not_seen(c, p, zx_ns_tab+zx_xmlns_ix_idp, &pop_seen);


  p = zx_enc_unknown_attrs(p, x->gg.any_attr);
#else
  /* root node has no begin tag */
#endif
  
  {
      struct zx_lu_Status_s* e;
      for (e = x->Status; e; e = (struct zx_lu_Status_s*)e->gg.g.n)
	  p = zx_ENC_SO_lu_Status(c, e, p);
  }

  p = zx_enc_so_unknown_elems_and_content(c, p, &x->gg);
  
#if 1 /* NORMALMODE */
  ZX_OUT_CLOSE_TAG(p, "</idp:CreatedStatusResponse>");
  zx_pop_seen(pop_seen);
#else
  /* root node has no end tag either */
#endif
  ENC_LEN_DEBUG(x, "idp:CreatedStatusResponse", p-enc_base);
  return p;
}

/* FUNC(zx_ENC_WO_idp_CreatedStatusResponse) */

/* Render element into string. The XML attributes and elements are
 * processed in wire order by chasing wo pointers. This is what you want for
 * validating signatures on other people's XML documents. */

/* Called by: */
char* zx_ENC_WO_idp_CreatedStatusResponse(struct zx_ctx* c, struct zx_idp_CreatedStatusResponse_s* x, char* p )
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
  ZX_OUT_MEM(p, "CreatedStatusResponse", sizeof("CreatedStatusResponse")-1);
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
  ENC_LEN_DEBUG(x, "idp:CreatedStatusResponse", p-enc_base);
  return p;
}

/* FUNC(zx_EASY_ENC_SO_idp_CreatedStatusResponse) */

/* Called by: */
struct zx_str* zx_EASY_ENC_SO_idp_CreatedStatusResponse(struct zx_ctx* c, struct zx_idp_CreatedStatusResponse_s* x )
{
  int len;
  char* buf;
  c->ns_tab = ZX_ALLOC(c, sizeof(zx_ns_tab));
  memcpy(c->ns_tab, zx_ns_tab, sizeof(zx_ns_tab));
  len = zx_LEN_SO_idp_CreatedStatusResponse(c, x );
  buf = ZX_ALLOC(c, len+1);
  return zx_easy_enc_common(c, zx_ENC_SO_idp_CreatedStatusResponse(c, x, buf ), buf, len);
}

/* FUNC(zx_EASY_ENC_WO_idp_CreatedStatusResponse) */

/* Called by: */
struct zx_str* zx_EASY_ENC_WO_idp_CreatedStatusResponse(struct zx_ctx* c, struct zx_idp_CreatedStatusResponse_s* x )
{
  int len;
  char* buf;
  c->ns_tab = ZX_ALLOC(c, sizeof(zx_ns_tab));
  memcpy(c->ns_tab, zx_ns_tab, sizeof(zx_ns_tab));
  len = zx_LEN_WO_idp_CreatedStatusResponse(c, x );
  buf = ZX_ALLOC(c, len+1);
  return zx_easy_enc_common(c, zx_ENC_WO_idp_CreatedStatusResponse(c, x, buf ), buf, len);
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

#define EL_NAME   idp_GetAssertion
#define EL_STRUCT zx_idp_GetAssertion_s
#define EL_NS     idp
#define EL_TAG    GetAssertion

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

/* FUNC(zx_LEN_SO_idp_GetAssertion) */

/* Compute length of an element (and its subelements). The XML attributes
 * and elements are processed in schema order. */

/* Called by: */
int zx_LEN_SO_idp_GetAssertion(struct zx_ctx* c, struct zx_idp_GetAssertion_s* x )
{
  struct zx_ns_s* pop_seen = 0;
  struct zx_elem_s* se MAYBE_UNUSED;
#if 1 /* NORMALMODE */
  /* *** in simple_elem case should output ns prefix from ns node. */
  int len = sizeof("<idp:GetAssertion")-1 + 1 + sizeof("</idp:GetAssertion>")-1;
  if (c->inc_ns_len)
    len += zx_len_inc_ns(c, &pop_seen);
  len += zx_len_xmlns_if_not_seen(c, zx_ns_tab+zx_xmlns_ix_idp, &pop_seen);

  len += zx_attr_so_len(x->purpose, sizeof("purpose")-1);

#else
  /* root node has no begin tag */
  int len = 0;
#endif
  
  {
      struct zx_sp_AuthnRequest_s* e;
      for (e = x->AuthnRequest; e; e = (struct zx_sp_AuthnRequest_s*)e->gg.g.n)
	  len += zx_LEN_SO_sp_AuthnRequest(c, e);
  }


  len += zx_len_so_common(c, &x->gg);
  zx_pop_seen(pop_seen);
  ENC_LEN_DEBUG(x, "idp:GetAssertion", len);
  return len;
}

/* FUNC(zx_LEN_WO_idp_GetAssertion) */

/* Compute length of an element (and its subelements). The XML attributes
 * and elements are processed in wire order and no assumptions
 * are made about namespace prefixes. */

/* Called by: */
int zx_LEN_WO_idp_GetAssertion(struct zx_ctx* c, struct zx_idp_GetAssertion_s* x )
{
  struct zx_ns_s* pop_seen = 0;
  struct zx_elem_s* se MAYBE_UNUSED;
#if 1 /* NORMALMODE */
  int len = 1 + sizeof("GetAssertion")-1 + 1 + 2 + sizeof("GetAssertion")-1 + 1;
  
  if (x->gg.g.ns && x->gg.g.ns->prefix_len)
    len += (x->gg.g.ns->prefix_len + 1) * 2;
  if (c->inc_ns_len)
    len += zx_len_inc_ns(c, &pop_seen);
  len += zx_len_xmlns_if_not_seen(c, x->gg.g.ns, &pop_seen);

  len += zx_attr_wo_len(x->purpose, sizeof("purpose")-1);

#else
  /* root node has no begin tag */
  int len = 0;
#endif
  
  {
      struct zx_sp_AuthnRequest_s* e;
      for (e = x->AuthnRequest; e; e = (struct zx_sp_AuthnRequest_s*)e->gg.g.n)
	  len += zx_LEN_WO_sp_AuthnRequest(c, e);
  }


  len += zx_len_wo_common(c, &x->gg); 
  zx_pop_seen(pop_seen);
  ENC_LEN_DEBUG(x, "idp:GetAssertion", len);
  return len;
}

/* FUNC(zx_ENC_SO_idp_GetAssertion) */

/* Render element into string. The XML attributes and elements are
 * processed in schema order. This is what you generally want for
 * rendering new data structure to a string. The wo pointers are not used. */

/* Called by: */
char* zx_ENC_SO_idp_GetAssertion(struct zx_ctx* c, struct zx_idp_GetAssertion_s* x, char* p )
{
  struct zx_elem_s* se MAYBE_UNUSED;
  ENC_LEN_DEBUG_BASE;
#if 1 /* NORMALMODE */
  struct zx_ns_s* pop_seen = 0;
  /* *** in simple_elem case should output ns prefix from ns node. */
  ZX_OUT_TAG(p, "<idp:GetAssertion");
  if (c->inc_ns)
    p = zx_enc_inc_ns(c, p, &pop_seen);
  p = zx_enc_xmlns_if_not_seen(c, p, zx_ns_tab+zx_xmlns_ix_idp, &pop_seen);

  p = zx_attr_so_enc(p, x->purpose, " purpose=\"", sizeof(" purpose=\"")-1);

  p = zx_enc_unknown_attrs(p, x->gg.any_attr);
#else
  /* root node has no begin tag */
#endif
  
  {
      struct zx_sp_AuthnRequest_s* e;
      for (e = x->AuthnRequest; e; e = (struct zx_sp_AuthnRequest_s*)e->gg.g.n)
	  p = zx_ENC_SO_sp_AuthnRequest(c, e, p);
  }

  p = zx_enc_so_unknown_elems_and_content(c, p, &x->gg);
  
#if 1 /* NORMALMODE */
  ZX_OUT_CLOSE_TAG(p, "</idp:GetAssertion>");
  zx_pop_seen(pop_seen);
#else
  /* root node has no end tag either */
#endif
  ENC_LEN_DEBUG(x, "idp:GetAssertion", p-enc_base);
  return p;
}

/* FUNC(zx_ENC_WO_idp_GetAssertion) */

/* Render element into string. The XML attributes and elements are
 * processed in wire order by chasing wo pointers. This is what you want for
 * validating signatures on other people's XML documents. */

/* Called by: */
char* zx_ENC_WO_idp_GetAssertion(struct zx_ctx* c, struct zx_idp_GetAssertion_s* x, char* p )
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
  ZX_OUT_MEM(p, "GetAssertion", sizeof("GetAssertion")-1);
  qq = p;

  /* *** sort the namespaces */
  if (c->inc_ns)
    zx_add_inc_ns(c, &pop_seen);
  zx_add_xmlns_if_not_seen(c, x->gg.g.ns, &pop_seen);

  p = zx_enc_seen(p, pop_seen); 
  p = zx_attr_wo_enc(p, x->purpose, "purpose=\"", sizeof("purpose=\"")-1);

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
  ENC_LEN_DEBUG(x, "idp:GetAssertion", p-enc_base);
  return p;
}

/* FUNC(zx_EASY_ENC_SO_idp_GetAssertion) */

/* Called by: */
struct zx_str* zx_EASY_ENC_SO_idp_GetAssertion(struct zx_ctx* c, struct zx_idp_GetAssertion_s* x )
{
  int len;
  char* buf;
  c->ns_tab = ZX_ALLOC(c, sizeof(zx_ns_tab));
  memcpy(c->ns_tab, zx_ns_tab, sizeof(zx_ns_tab));
  len = zx_LEN_SO_idp_GetAssertion(c, x );
  buf = ZX_ALLOC(c, len+1);
  return zx_easy_enc_common(c, zx_ENC_SO_idp_GetAssertion(c, x, buf ), buf, len);
}

/* FUNC(zx_EASY_ENC_WO_idp_GetAssertion) */

/* Called by: */
struct zx_str* zx_EASY_ENC_WO_idp_GetAssertion(struct zx_ctx* c, struct zx_idp_GetAssertion_s* x )
{
  int len;
  char* buf;
  c->ns_tab = ZX_ALLOC(c, sizeof(zx_ns_tab));
  memcpy(c->ns_tab, zx_ns_tab, sizeof(zx_ns_tab));
  len = zx_LEN_WO_idp_GetAssertion(c, x );
  buf = ZX_ALLOC(c, len+1);
  return zx_easy_enc_common(c, zx_ENC_WO_idp_GetAssertion(c, x, buf ), buf, len);
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

#define EL_NAME   idp_GetAssertionResponse
#define EL_STRUCT zx_idp_GetAssertionResponse_s
#define EL_NS     idp
#define EL_TAG    GetAssertionResponse

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

/* FUNC(zx_LEN_SO_idp_GetAssertionResponse) */

/* Compute length of an element (and its subelements). The XML attributes
 * and elements are processed in schema order. */

/* Called by: */
int zx_LEN_SO_idp_GetAssertionResponse(struct zx_ctx* c, struct zx_idp_GetAssertionResponse_s* x )
{
  struct zx_ns_s* pop_seen = 0;
  struct zx_elem_s* se MAYBE_UNUSED;
#if 1 /* NORMALMODE */
  /* *** in simple_elem case should output ns prefix from ns node. */
  int len = sizeof("<idp:GetAssertionResponse")-1 + 1 + sizeof("</idp:GetAssertionResponse>")-1;
  if (c->inc_ns_len)
    len += zx_len_inc_ns(c, &pop_seen);
  len += zx_len_xmlns_if_not_seen(c, zx_ns_tab+zx_xmlns_ix_idp, &pop_seen);


#else
  /* root node has no begin tag */
  int len = 0;
#endif
  
  {
      struct zx_lu_Status_s* e;
      for (e = x->Status; e; e = (struct zx_lu_Status_s*)e->gg.g.n)
	  len += zx_LEN_SO_lu_Status(c, e);
  }
  {
      struct zx_idp_GetAssertionResponseItem_s* e;
      for (e = x->GetAssertionResponseItem; e; e = (struct zx_idp_GetAssertionResponseItem_s*)e->gg.g.n)
	  len += zx_LEN_SO_idp_GetAssertionResponseItem(c, e);
  }


  len += zx_len_so_common(c, &x->gg);
  zx_pop_seen(pop_seen);
  ENC_LEN_DEBUG(x, "idp:GetAssertionResponse", len);
  return len;
}

/* FUNC(zx_LEN_WO_idp_GetAssertionResponse) */

/* Compute length of an element (and its subelements). The XML attributes
 * and elements are processed in wire order and no assumptions
 * are made about namespace prefixes. */

/* Called by: */
int zx_LEN_WO_idp_GetAssertionResponse(struct zx_ctx* c, struct zx_idp_GetAssertionResponse_s* x )
{
  struct zx_ns_s* pop_seen = 0;
  struct zx_elem_s* se MAYBE_UNUSED;
#if 1 /* NORMALMODE */
  int len = 1 + sizeof("GetAssertionResponse")-1 + 1 + 2 + sizeof("GetAssertionResponse")-1 + 1;
  
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
      struct zx_lu_Status_s* e;
      for (e = x->Status; e; e = (struct zx_lu_Status_s*)e->gg.g.n)
	  len += zx_LEN_WO_lu_Status(c, e);
  }
  {
      struct zx_idp_GetAssertionResponseItem_s* e;
      for (e = x->GetAssertionResponseItem; e; e = (struct zx_idp_GetAssertionResponseItem_s*)e->gg.g.n)
	  len += zx_LEN_WO_idp_GetAssertionResponseItem(c, e);
  }


  len += zx_len_wo_common(c, &x->gg); 
  zx_pop_seen(pop_seen);
  ENC_LEN_DEBUG(x, "idp:GetAssertionResponse", len);
  return len;
}

/* FUNC(zx_ENC_SO_idp_GetAssertionResponse) */

/* Render element into string. The XML attributes and elements are
 * processed in schema order. This is what you generally want for
 * rendering new data structure to a string. The wo pointers are not used. */

/* Called by: */
char* zx_ENC_SO_idp_GetAssertionResponse(struct zx_ctx* c, struct zx_idp_GetAssertionResponse_s* x, char* p )
{
  struct zx_elem_s* se MAYBE_UNUSED;
  ENC_LEN_DEBUG_BASE;
#if 1 /* NORMALMODE */
  struct zx_ns_s* pop_seen = 0;
  /* *** in simple_elem case should output ns prefix from ns node. */
  ZX_OUT_TAG(p, "<idp:GetAssertionResponse");
  if (c->inc_ns)
    p = zx_enc_inc_ns(c, p, &pop_seen);
  p = zx_enc_xmlns_if_not_seen(c, p, zx_ns_tab+zx_xmlns_ix_idp, &pop_seen);


  p = zx_enc_unknown_attrs(p, x->gg.any_attr);
#else
  /* root node has no begin tag */
#endif
  
  {
      struct zx_lu_Status_s* e;
      for (e = x->Status; e; e = (struct zx_lu_Status_s*)e->gg.g.n)
	  p = zx_ENC_SO_lu_Status(c, e, p);
  }
  {
      struct zx_idp_GetAssertionResponseItem_s* e;
      for (e = x->GetAssertionResponseItem; e; e = (struct zx_idp_GetAssertionResponseItem_s*)e->gg.g.n)
	  p = zx_ENC_SO_idp_GetAssertionResponseItem(c, e, p);
  }

  p = zx_enc_so_unknown_elems_and_content(c, p, &x->gg);
  
#if 1 /* NORMALMODE */
  ZX_OUT_CLOSE_TAG(p, "</idp:GetAssertionResponse>");
  zx_pop_seen(pop_seen);
#else
  /* root node has no end tag either */
#endif
  ENC_LEN_DEBUG(x, "idp:GetAssertionResponse", p-enc_base);
  return p;
}

/* FUNC(zx_ENC_WO_idp_GetAssertionResponse) */

/* Render element into string. The XML attributes and elements are
 * processed in wire order by chasing wo pointers. This is what you want for
 * validating signatures on other people's XML documents. */

/* Called by: */
char* zx_ENC_WO_idp_GetAssertionResponse(struct zx_ctx* c, struct zx_idp_GetAssertionResponse_s* x, char* p )
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
  ZX_OUT_MEM(p, "GetAssertionResponse", sizeof("GetAssertionResponse")-1);
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
  ENC_LEN_DEBUG(x, "idp:GetAssertionResponse", p-enc_base);
  return p;
}

/* FUNC(zx_EASY_ENC_SO_idp_GetAssertionResponse) */

/* Called by: */
struct zx_str* zx_EASY_ENC_SO_idp_GetAssertionResponse(struct zx_ctx* c, struct zx_idp_GetAssertionResponse_s* x )
{
  int len;
  char* buf;
  c->ns_tab = ZX_ALLOC(c, sizeof(zx_ns_tab));
  memcpy(c->ns_tab, zx_ns_tab, sizeof(zx_ns_tab));
  len = zx_LEN_SO_idp_GetAssertionResponse(c, x );
  buf = ZX_ALLOC(c, len+1);
  return zx_easy_enc_common(c, zx_ENC_SO_idp_GetAssertionResponse(c, x, buf ), buf, len);
}

/* FUNC(zx_EASY_ENC_WO_idp_GetAssertionResponse) */

/* Called by: */
struct zx_str* zx_EASY_ENC_WO_idp_GetAssertionResponse(struct zx_ctx* c, struct zx_idp_GetAssertionResponse_s* x )
{
  int len;
  char* buf;
  c->ns_tab = ZX_ALLOC(c, sizeof(zx_ns_tab));
  memcpy(c->ns_tab, zx_ns_tab, sizeof(zx_ns_tab));
  len = zx_LEN_WO_idp_GetAssertionResponse(c, x );
  buf = ZX_ALLOC(c, len+1);
  return zx_easy_enc_common(c, zx_ENC_WO_idp_GetAssertionResponse(c, x, buf ), buf, len);
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

#define EL_NAME   idp_GetAssertionResponseItem
#define EL_STRUCT zx_idp_GetAssertionResponseItem_s
#define EL_NS     idp
#define EL_TAG    GetAssertionResponseItem

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

/* FUNC(zx_LEN_SO_idp_GetAssertionResponseItem) */

/* Compute length of an element (and its subelements). The XML attributes
 * and elements are processed in schema order. */

/* Called by: */
int zx_LEN_SO_idp_GetAssertionResponseItem(struct zx_ctx* c, struct zx_idp_GetAssertionResponseItem_s* x )
{
  struct zx_ns_s* pop_seen = 0;
  struct zx_elem_s* se MAYBE_UNUSED;
#if 1 /* NORMALMODE */
  /* *** in simple_elem case should output ns prefix from ns node. */
  int len = sizeof("<idp:GetAssertionResponseItem")-1 + 1 + sizeof("</idp:GetAssertionResponseItem>")-1;
  if (c->inc_ns_len)
    len += zx_len_inc_ns(c, &pop_seen);
  len += zx_len_xmlns_if_not_seen(c, zx_ns_tab+zx_xmlns_ix_idp, &pop_seen);

  len += zx_attr_so_len(x->id, sizeof("id")-1);
  len += zx_attr_so_len(x->ref, sizeof("ref")-1);

#else
  /* root node has no begin tag */
  int len = 0;
#endif
  
  {
      struct zx_idp_AssertionItem_s* e;
      for (e = x->AssertionItem; e; e = (struct zx_idp_AssertionItem_s*)e->gg.g.n)
	  len += zx_LEN_SO_idp_AssertionItem(c, e);
  }


  len += zx_len_so_common(c, &x->gg);
  zx_pop_seen(pop_seen);
  ENC_LEN_DEBUG(x, "idp:GetAssertionResponseItem", len);
  return len;
}

/* FUNC(zx_LEN_WO_idp_GetAssertionResponseItem) */

/* Compute length of an element (and its subelements). The XML attributes
 * and elements are processed in wire order and no assumptions
 * are made about namespace prefixes. */

/* Called by: */
int zx_LEN_WO_idp_GetAssertionResponseItem(struct zx_ctx* c, struct zx_idp_GetAssertionResponseItem_s* x )
{
  struct zx_ns_s* pop_seen = 0;
  struct zx_elem_s* se MAYBE_UNUSED;
#if 1 /* NORMALMODE */
  int len = 1 + sizeof("GetAssertionResponseItem")-1 + 1 + 2 + sizeof("GetAssertionResponseItem")-1 + 1;
  
  if (x->gg.g.ns && x->gg.g.ns->prefix_len)
    len += (x->gg.g.ns->prefix_len + 1) * 2;
  if (c->inc_ns_len)
    len += zx_len_inc_ns(c, &pop_seen);
  len += zx_len_xmlns_if_not_seen(c, x->gg.g.ns, &pop_seen);

  len += zx_attr_wo_len(x->id, sizeof("id")-1);
  len += zx_attr_wo_len(x->ref, sizeof("ref")-1);

#else
  /* root node has no begin tag */
  int len = 0;
#endif
  
  {
      struct zx_idp_AssertionItem_s* e;
      for (e = x->AssertionItem; e; e = (struct zx_idp_AssertionItem_s*)e->gg.g.n)
	  len += zx_LEN_WO_idp_AssertionItem(c, e);
  }


  len += zx_len_wo_common(c, &x->gg); 
  zx_pop_seen(pop_seen);
  ENC_LEN_DEBUG(x, "idp:GetAssertionResponseItem", len);
  return len;
}

/* FUNC(zx_ENC_SO_idp_GetAssertionResponseItem) */

/* Render element into string. The XML attributes and elements are
 * processed in schema order. This is what you generally want for
 * rendering new data structure to a string. The wo pointers are not used. */

/* Called by: */
char* zx_ENC_SO_idp_GetAssertionResponseItem(struct zx_ctx* c, struct zx_idp_GetAssertionResponseItem_s* x, char* p )
{
  struct zx_elem_s* se MAYBE_UNUSED;
  ENC_LEN_DEBUG_BASE;
#if 1 /* NORMALMODE */
  struct zx_ns_s* pop_seen = 0;
  /* *** in simple_elem case should output ns prefix from ns node. */
  ZX_OUT_TAG(p, "<idp:GetAssertionResponseItem");
  if (c->inc_ns)
    p = zx_enc_inc_ns(c, p, &pop_seen);
  p = zx_enc_xmlns_if_not_seen(c, p, zx_ns_tab+zx_xmlns_ix_idp, &pop_seen);

  p = zx_attr_so_enc(p, x->id, " id=\"", sizeof(" id=\"")-1);
  p = zx_attr_so_enc(p, x->ref, " ref=\"", sizeof(" ref=\"")-1);

  p = zx_enc_unknown_attrs(p, x->gg.any_attr);
#else
  /* root node has no begin tag */
#endif
  
  {
      struct zx_idp_AssertionItem_s* e;
      for (e = x->AssertionItem; e; e = (struct zx_idp_AssertionItem_s*)e->gg.g.n)
	  p = zx_ENC_SO_idp_AssertionItem(c, e, p);
  }

  p = zx_enc_so_unknown_elems_and_content(c, p, &x->gg);
  
#if 1 /* NORMALMODE */
  ZX_OUT_CLOSE_TAG(p, "</idp:GetAssertionResponseItem>");
  zx_pop_seen(pop_seen);
#else
  /* root node has no end tag either */
#endif
  ENC_LEN_DEBUG(x, "idp:GetAssertionResponseItem", p-enc_base);
  return p;
}

/* FUNC(zx_ENC_WO_idp_GetAssertionResponseItem) */

/* Render element into string. The XML attributes and elements are
 * processed in wire order by chasing wo pointers. This is what you want for
 * validating signatures on other people's XML documents. */

/* Called by: */
char* zx_ENC_WO_idp_GetAssertionResponseItem(struct zx_ctx* c, struct zx_idp_GetAssertionResponseItem_s* x, char* p )
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
  ZX_OUT_MEM(p, "GetAssertionResponseItem", sizeof("GetAssertionResponseItem")-1);
  qq = p;

  /* *** sort the namespaces */
  if (c->inc_ns)
    zx_add_inc_ns(c, &pop_seen);
  zx_add_xmlns_if_not_seen(c, x->gg.g.ns, &pop_seen);

  p = zx_enc_seen(p, pop_seen); 
  p = zx_attr_wo_enc(p, x->id, "id=\"", sizeof("id=\"")-1);
  p = zx_attr_wo_enc(p, x->ref, "ref=\"", sizeof("ref=\"")-1);

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
  ENC_LEN_DEBUG(x, "idp:GetAssertionResponseItem", p-enc_base);
  return p;
}

/* FUNC(zx_EASY_ENC_SO_idp_GetAssertionResponseItem) */

/* Called by: */
struct zx_str* zx_EASY_ENC_SO_idp_GetAssertionResponseItem(struct zx_ctx* c, struct zx_idp_GetAssertionResponseItem_s* x )
{
  int len;
  char* buf;
  c->ns_tab = ZX_ALLOC(c, sizeof(zx_ns_tab));
  memcpy(c->ns_tab, zx_ns_tab, sizeof(zx_ns_tab));
  len = zx_LEN_SO_idp_GetAssertionResponseItem(c, x );
  buf = ZX_ALLOC(c, len+1);
  return zx_easy_enc_common(c, zx_ENC_SO_idp_GetAssertionResponseItem(c, x, buf ), buf, len);
}

/* FUNC(zx_EASY_ENC_WO_idp_GetAssertionResponseItem) */

/* Called by: */
struct zx_str* zx_EASY_ENC_WO_idp_GetAssertionResponseItem(struct zx_ctx* c, struct zx_idp_GetAssertionResponseItem_s* x )
{
  int len;
  char* buf;
  c->ns_tab = ZX_ALLOC(c, sizeof(zx_ns_tab));
  memcpy(c->ns_tab, zx_ns_tab, sizeof(zx_ns_tab));
  len = zx_LEN_WO_idp_GetAssertionResponseItem(c, x );
  buf = ZX_ALLOC(c, len+1);
  return zx_easy_enc_common(c, zx_ENC_WO_idp_GetAssertionResponseItem(c, x, buf ), buf, len);
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

#define EL_NAME   idp_GetProviderInfo
#define EL_STRUCT zx_idp_GetProviderInfo_s
#define EL_NS     idp
#define EL_TAG    GetProviderInfo

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

/* FUNC(zx_LEN_SO_idp_GetProviderInfo) */

/* Compute length of an element (and its subelements). The XML attributes
 * and elements are processed in schema order. */

/* Called by: */
int zx_LEN_SO_idp_GetProviderInfo(struct zx_ctx* c, struct zx_idp_GetProviderInfo_s* x )
{
  struct zx_ns_s* pop_seen = 0;
  struct zx_elem_s* se MAYBE_UNUSED;
#if 1 /* NORMALMODE */
  /* *** in simple_elem case should output ns prefix from ns node. */
  int len = sizeof("<idp:GetProviderInfo")-1 + 1 + sizeof("</idp:GetProviderInfo>")-1;
  if (c->inc_ns_len)
    len += zx_len_inc_ns(c, &pop_seen);
  len += zx_len_xmlns_if_not_seen(c, zx_ns_tab+zx_xmlns_ix_idp, &pop_seen);

  len += zx_attr_so_len(x->all, sizeof("all")-1);

#else
  /* root node has no begin tag */
  int len = 0;
#endif
  
  for (se = x->ProviderID; se; se = (struct zx_elem_s*)se->g.n)
    len += zx_LEN_SO_simple_elem(c,se, sizeof("idp:ProviderID")-1, zx_ns_tab+zx_xmlns_ix_idp);


  len += zx_len_so_common(c, &x->gg);
  zx_pop_seen(pop_seen);
  ENC_LEN_DEBUG(x, "idp:GetProviderInfo", len);
  return len;
}

/* FUNC(zx_LEN_WO_idp_GetProviderInfo) */

/* Compute length of an element (and its subelements). The XML attributes
 * and elements are processed in wire order and no assumptions
 * are made about namespace prefixes. */

/* Called by: */
int zx_LEN_WO_idp_GetProviderInfo(struct zx_ctx* c, struct zx_idp_GetProviderInfo_s* x )
{
  struct zx_ns_s* pop_seen = 0;
  struct zx_elem_s* se MAYBE_UNUSED;
#if 1 /* NORMALMODE */
  int len = 1 + sizeof("GetProviderInfo")-1 + 1 + 2 + sizeof("GetProviderInfo")-1 + 1;
  
  if (x->gg.g.ns && x->gg.g.ns->prefix_len)
    len += (x->gg.g.ns->prefix_len + 1) * 2;
  if (c->inc_ns_len)
    len += zx_len_inc_ns(c, &pop_seen);
  len += zx_len_xmlns_if_not_seen(c, x->gg.g.ns, &pop_seen);

  len += zx_attr_wo_len(x->all, sizeof("all")-1);

#else
  /* root node has no begin tag */
  int len = 0;
#endif
  
  for (se = x->ProviderID; se; se = (struct zx_elem_s*)se->g.n)
    len += zx_LEN_WO_simple_elem(c, se, sizeof("ProviderID")-1);


  len += zx_len_wo_common(c, &x->gg); 
  zx_pop_seen(pop_seen);
  ENC_LEN_DEBUG(x, "idp:GetProviderInfo", len);
  return len;
}

/* FUNC(zx_ENC_SO_idp_GetProviderInfo) */

/* Render element into string. The XML attributes and elements are
 * processed in schema order. This is what you generally want for
 * rendering new data structure to a string. The wo pointers are not used. */

/* Called by: */
char* zx_ENC_SO_idp_GetProviderInfo(struct zx_ctx* c, struct zx_idp_GetProviderInfo_s* x, char* p )
{
  struct zx_elem_s* se MAYBE_UNUSED;
  ENC_LEN_DEBUG_BASE;
#if 1 /* NORMALMODE */
  struct zx_ns_s* pop_seen = 0;
  /* *** in simple_elem case should output ns prefix from ns node. */
  ZX_OUT_TAG(p, "<idp:GetProviderInfo");
  if (c->inc_ns)
    p = zx_enc_inc_ns(c, p, &pop_seen);
  p = zx_enc_xmlns_if_not_seen(c, p, zx_ns_tab+zx_xmlns_ix_idp, &pop_seen);

  p = zx_attr_so_enc(p, x->all, " all=\"", sizeof(" all=\"")-1);

  p = zx_enc_unknown_attrs(p, x->gg.any_attr);
#else
  /* root node has no begin tag */
#endif
  
  for (se = x->ProviderID; se; se = (struct zx_elem_s*)se->g.n)
    p = zx_ENC_SO_simple_elem(c, se, p, "idp:ProviderID", sizeof("idp:ProviderID")-1, zx_ns_tab+zx_xmlns_ix_idp);

  p = zx_enc_so_unknown_elems_and_content(c, p, &x->gg);
  
#if 1 /* NORMALMODE */
  ZX_OUT_CLOSE_TAG(p, "</idp:GetProviderInfo>");
  zx_pop_seen(pop_seen);
#else
  /* root node has no end tag either */
#endif
  ENC_LEN_DEBUG(x, "idp:GetProviderInfo", p-enc_base);
  return p;
}

/* FUNC(zx_ENC_WO_idp_GetProviderInfo) */

/* Render element into string. The XML attributes and elements are
 * processed in wire order by chasing wo pointers. This is what you want for
 * validating signatures on other people's XML documents. */

/* Called by: */
char* zx_ENC_WO_idp_GetProviderInfo(struct zx_ctx* c, struct zx_idp_GetProviderInfo_s* x, char* p )
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
  ZX_OUT_MEM(p, "GetProviderInfo", sizeof("GetProviderInfo")-1);
  qq = p;

  /* *** sort the namespaces */
  if (c->inc_ns)
    zx_add_inc_ns(c, &pop_seen);
  zx_add_xmlns_if_not_seen(c, x->gg.g.ns, &pop_seen);

  p = zx_enc_seen(p, pop_seen); 
  p = zx_attr_wo_enc(p, x->all, "all=\"", sizeof("all=\"")-1);

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
  ENC_LEN_DEBUG(x, "idp:GetProviderInfo", p-enc_base);
  return p;
}

/* FUNC(zx_EASY_ENC_SO_idp_GetProviderInfo) */

/* Called by: */
struct zx_str* zx_EASY_ENC_SO_idp_GetProviderInfo(struct zx_ctx* c, struct zx_idp_GetProviderInfo_s* x )
{
  int len;
  char* buf;
  c->ns_tab = ZX_ALLOC(c, sizeof(zx_ns_tab));
  memcpy(c->ns_tab, zx_ns_tab, sizeof(zx_ns_tab));
  len = zx_LEN_SO_idp_GetProviderInfo(c, x );
  buf = ZX_ALLOC(c, len+1);
  return zx_easy_enc_common(c, zx_ENC_SO_idp_GetProviderInfo(c, x, buf ), buf, len);
}

/* FUNC(zx_EASY_ENC_WO_idp_GetProviderInfo) */

/* Called by: */
struct zx_str* zx_EASY_ENC_WO_idp_GetProviderInfo(struct zx_ctx* c, struct zx_idp_GetProviderInfo_s* x )
{
  int len;
  char* buf;
  c->ns_tab = ZX_ALLOC(c, sizeof(zx_ns_tab));
  memcpy(c->ns_tab, zx_ns_tab, sizeof(zx_ns_tab));
  len = zx_LEN_WO_idp_GetProviderInfo(c, x );
  buf = ZX_ALLOC(c, len+1);
  return zx_easy_enc_common(c, zx_ENC_WO_idp_GetProviderInfo(c, x, buf ), buf, len);
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

#define EL_NAME   idp_GetProviderInfoResponse
#define EL_STRUCT zx_idp_GetProviderInfoResponse_s
#define EL_NS     idp
#define EL_TAG    GetProviderInfoResponse

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

/* FUNC(zx_LEN_SO_idp_GetProviderInfoResponse) */

/* Compute length of an element (and its subelements). The XML attributes
 * and elements are processed in schema order. */

/* Called by: */
int zx_LEN_SO_idp_GetProviderInfoResponse(struct zx_ctx* c, struct zx_idp_GetProviderInfoResponse_s* x )
{
  struct zx_ns_s* pop_seen = 0;
  struct zx_elem_s* se MAYBE_UNUSED;
#if 1 /* NORMALMODE */
  /* *** in simple_elem case should output ns prefix from ns node. */
  int len = sizeof("<idp:GetProviderInfoResponse")-1 + 1 + sizeof("</idp:GetProviderInfoResponse>")-1;
  if (c->inc_ns_len)
    len += zx_len_inc_ns(c, &pop_seen);
  len += zx_len_xmlns_if_not_seen(c, zx_ns_tab+zx_xmlns_ix_idp, &pop_seen);


#else
  /* root node has no begin tag */
  int len = 0;
#endif
  
  {
      struct zx_lu_Status_s* e;
      for (e = x->Status; e; e = (struct zx_lu_Status_s*)e->gg.g.n)
	  len += zx_LEN_SO_lu_Status(c, e);
  }
  {
      struct zx_idp_ProviderInfo_s* e;
      for (e = x->ProviderInfo; e; e = (struct zx_idp_ProviderInfo_s*)e->gg.g.n)
	  len += zx_LEN_SO_idp_ProviderInfo(c, e);
  }


  len += zx_len_so_common(c, &x->gg);
  zx_pop_seen(pop_seen);
  ENC_LEN_DEBUG(x, "idp:GetProviderInfoResponse", len);
  return len;
}

/* FUNC(zx_LEN_WO_idp_GetProviderInfoResponse) */

/* Compute length of an element (and its subelements). The XML attributes
 * and elements are processed in wire order and no assumptions
 * are made about namespace prefixes. */

/* Called by: */
int zx_LEN_WO_idp_GetProviderInfoResponse(struct zx_ctx* c, struct zx_idp_GetProviderInfoResponse_s* x )
{
  struct zx_ns_s* pop_seen = 0;
  struct zx_elem_s* se MAYBE_UNUSED;
#if 1 /* NORMALMODE */
  int len = 1 + sizeof("GetProviderInfoResponse")-1 + 1 + 2 + sizeof("GetProviderInfoResponse")-1 + 1;
  
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
      struct zx_lu_Status_s* e;
      for (e = x->Status; e; e = (struct zx_lu_Status_s*)e->gg.g.n)
	  len += zx_LEN_WO_lu_Status(c, e);
  }
  {
      struct zx_idp_ProviderInfo_s* e;
      for (e = x->ProviderInfo; e; e = (struct zx_idp_ProviderInfo_s*)e->gg.g.n)
	  len += zx_LEN_WO_idp_ProviderInfo(c, e);
  }


  len += zx_len_wo_common(c, &x->gg); 
  zx_pop_seen(pop_seen);
  ENC_LEN_DEBUG(x, "idp:GetProviderInfoResponse", len);
  return len;
}

/* FUNC(zx_ENC_SO_idp_GetProviderInfoResponse) */

/* Render element into string. The XML attributes and elements are
 * processed in schema order. This is what you generally want for
 * rendering new data structure to a string. The wo pointers are not used. */

/* Called by: */
char* zx_ENC_SO_idp_GetProviderInfoResponse(struct zx_ctx* c, struct zx_idp_GetProviderInfoResponse_s* x, char* p )
{
  struct zx_elem_s* se MAYBE_UNUSED;
  ENC_LEN_DEBUG_BASE;
#if 1 /* NORMALMODE */
  struct zx_ns_s* pop_seen = 0;
  /* *** in simple_elem case should output ns prefix from ns node. */
  ZX_OUT_TAG(p, "<idp:GetProviderInfoResponse");
  if (c->inc_ns)
    p = zx_enc_inc_ns(c, p, &pop_seen);
  p = zx_enc_xmlns_if_not_seen(c, p, zx_ns_tab+zx_xmlns_ix_idp, &pop_seen);


  p = zx_enc_unknown_attrs(p, x->gg.any_attr);
#else
  /* root node has no begin tag */
#endif
  
  {
      struct zx_lu_Status_s* e;
      for (e = x->Status; e; e = (struct zx_lu_Status_s*)e->gg.g.n)
	  p = zx_ENC_SO_lu_Status(c, e, p);
  }
  {
      struct zx_idp_ProviderInfo_s* e;
      for (e = x->ProviderInfo; e; e = (struct zx_idp_ProviderInfo_s*)e->gg.g.n)
	  p = zx_ENC_SO_idp_ProviderInfo(c, e, p);
  }

  p = zx_enc_so_unknown_elems_and_content(c, p, &x->gg);
  
#if 1 /* NORMALMODE */
  ZX_OUT_CLOSE_TAG(p, "</idp:GetProviderInfoResponse>");
  zx_pop_seen(pop_seen);
#else
  /* root node has no end tag either */
#endif
  ENC_LEN_DEBUG(x, "idp:GetProviderInfoResponse", p-enc_base);
  return p;
}

/* FUNC(zx_ENC_WO_idp_GetProviderInfoResponse) */

/* Render element into string. The XML attributes and elements are
 * processed in wire order by chasing wo pointers. This is what you want for
 * validating signatures on other people's XML documents. */

/* Called by: */
char* zx_ENC_WO_idp_GetProviderInfoResponse(struct zx_ctx* c, struct zx_idp_GetProviderInfoResponse_s* x, char* p )
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
  ZX_OUT_MEM(p, "GetProviderInfoResponse", sizeof("GetProviderInfoResponse")-1);
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
  ENC_LEN_DEBUG(x, "idp:GetProviderInfoResponse", p-enc_base);
  return p;
}

/* FUNC(zx_EASY_ENC_SO_idp_GetProviderInfoResponse) */

/* Called by: */
struct zx_str* zx_EASY_ENC_SO_idp_GetProviderInfoResponse(struct zx_ctx* c, struct zx_idp_GetProviderInfoResponse_s* x )
{
  int len;
  char* buf;
  c->ns_tab = ZX_ALLOC(c, sizeof(zx_ns_tab));
  memcpy(c->ns_tab, zx_ns_tab, sizeof(zx_ns_tab));
  len = zx_LEN_SO_idp_GetProviderInfoResponse(c, x );
  buf = ZX_ALLOC(c, len+1);
  return zx_easy_enc_common(c, zx_ENC_SO_idp_GetProviderInfoResponse(c, x, buf ), buf, len);
}

/* FUNC(zx_EASY_ENC_WO_idp_GetProviderInfoResponse) */

/* Called by: */
struct zx_str* zx_EASY_ENC_WO_idp_GetProviderInfoResponse(struct zx_ctx* c, struct zx_idp_GetProviderInfoResponse_s* x )
{
  int len;
  char* buf;
  c->ns_tab = ZX_ALLOC(c, sizeof(zx_ns_tab));
  memcpy(c->ns_tab, zx_ns_tab, sizeof(zx_ns_tab));
  len = zx_LEN_WO_idp_GetProviderInfoResponse(c, x );
  buf = ZX_ALLOC(c, len+1);
  return zx_easy_enc_common(c, zx_ENC_WO_idp_GetProviderInfoResponse(c, x, buf ), buf, len);
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

#define EL_NAME   idp_MEDInfo
#define EL_STRUCT zx_idp_MEDInfo_s
#define EL_NS     idp
#define EL_TAG    MEDInfo

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

/* FUNC(zx_LEN_SO_idp_MEDInfo) */

/* Compute length of an element (and its subelements). The XML attributes
 * and elements are processed in schema order. */

/* Called by: */
int zx_LEN_SO_idp_MEDInfo(struct zx_ctx* c, struct zx_idp_MEDInfo_s* x )
{
  struct zx_ns_s* pop_seen = 0;
  struct zx_elem_s* se MAYBE_UNUSED;
#if 1 /* NORMALMODE */
  /* *** in simple_elem case should output ns prefix from ns node. */
  int len = sizeof("<idp:MEDInfo")-1 + 1 + sizeof("</idp:MEDInfo>")-1;
  if (c->inc_ns_len)
    len += zx_len_inc_ns(c, &pop_seen);
  len += zx_len_xmlns_if_not_seen(c, zx_ns_tab+zx_xmlns_ix_idp, &pop_seen);


#else
  /* root node has no begin tag */
  int len = 0;
#endif
  
  {
      struct zx_sa_NameID_s* e;
      for (e = x->NameID; e; e = (struct zx_sa_NameID_s*)e->gg.g.n)
	  len += zx_LEN_SO_sa_NameID(c, e);
  }
  {
      struct zx_sa_AttributeStatement_s* e;
      for (e = x->AttributeStatement; e; e = (struct zx_sa_AttributeStatement_s*)e->gg.g.n)
	  len += zx_LEN_SO_sa_AttributeStatement(c, e);
  }


  len += zx_len_so_common(c, &x->gg);
  zx_pop_seen(pop_seen);
  ENC_LEN_DEBUG(x, "idp:MEDInfo", len);
  return len;
}

/* FUNC(zx_LEN_WO_idp_MEDInfo) */

/* Compute length of an element (and its subelements). The XML attributes
 * and elements are processed in wire order and no assumptions
 * are made about namespace prefixes. */

/* Called by: */
int zx_LEN_WO_idp_MEDInfo(struct zx_ctx* c, struct zx_idp_MEDInfo_s* x )
{
  struct zx_ns_s* pop_seen = 0;
  struct zx_elem_s* se MAYBE_UNUSED;
#if 1 /* NORMALMODE */
  int len = 1 + sizeof("MEDInfo")-1 + 1 + 2 + sizeof("MEDInfo")-1 + 1;
  
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
      struct zx_sa_NameID_s* e;
      for (e = x->NameID; e; e = (struct zx_sa_NameID_s*)e->gg.g.n)
	  len += zx_LEN_WO_sa_NameID(c, e);
  }
  {
      struct zx_sa_AttributeStatement_s* e;
      for (e = x->AttributeStatement; e; e = (struct zx_sa_AttributeStatement_s*)e->gg.g.n)
	  len += zx_LEN_WO_sa_AttributeStatement(c, e);
  }


  len += zx_len_wo_common(c, &x->gg); 
  zx_pop_seen(pop_seen);
  ENC_LEN_DEBUG(x, "idp:MEDInfo", len);
  return len;
}

/* FUNC(zx_ENC_SO_idp_MEDInfo) */

/* Render element into string. The XML attributes and elements are
 * processed in schema order. This is what you generally want for
 * rendering new data structure to a string. The wo pointers are not used. */

/* Called by: */
char* zx_ENC_SO_idp_MEDInfo(struct zx_ctx* c, struct zx_idp_MEDInfo_s* x, char* p )
{
  struct zx_elem_s* se MAYBE_UNUSED;
  ENC_LEN_DEBUG_BASE;
#if 1 /* NORMALMODE */
  struct zx_ns_s* pop_seen = 0;
  /* *** in simple_elem case should output ns prefix from ns node. */
  ZX_OUT_TAG(p, "<idp:MEDInfo");
  if (c->inc_ns)
    p = zx_enc_inc_ns(c, p, &pop_seen);
  p = zx_enc_xmlns_if_not_seen(c, p, zx_ns_tab+zx_xmlns_ix_idp, &pop_seen);


  p = zx_enc_unknown_attrs(p, x->gg.any_attr);
#else
  /* root node has no begin tag */
#endif
  
  {
      struct zx_sa_NameID_s* e;
      for (e = x->NameID; e; e = (struct zx_sa_NameID_s*)e->gg.g.n)
	  p = zx_ENC_SO_sa_NameID(c, e, p);
  }
  {
      struct zx_sa_AttributeStatement_s* e;
      for (e = x->AttributeStatement; e; e = (struct zx_sa_AttributeStatement_s*)e->gg.g.n)
	  p = zx_ENC_SO_sa_AttributeStatement(c, e, p);
  }

  p = zx_enc_so_unknown_elems_and_content(c, p, &x->gg);
  
#if 1 /* NORMALMODE */
  ZX_OUT_CLOSE_TAG(p, "</idp:MEDInfo>");
  zx_pop_seen(pop_seen);
#else
  /* root node has no end tag either */
#endif
  ENC_LEN_DEBUG(x, "idp:MEDInfo", p-enc_base);
  return p;
}

/* FUNC(zx_ENC_WO_idp_MEDInfo) */

/* Render element into string. The XML attributes and elements are
 * processed in wire order by chasing wo pointers. This is what you want for
 * validating signatures on other people's XML documents. */

/* Called by: */
char* zx_ENC_WO_idp_MEDInfo(struct zx_ctx* c, struct zx_idp_MEDInfo_s* x, char* p )
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
  ZX_OUT_MEM(p, "MEDInfo", sizeof("MEDInfo")-1);
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
  ENC_LEN_DEBUG(x, "idp:MEDInfo", p-enc_base);
  return p;
}

/* FUNC(zx_EASY_ENC_SO_idp_MEDInfo) */

/* Called by: */
struct zx_str* zx_EASY_ENC_SO_idp_MEDInfo(struct zx_ctx* c, struct zx_idp_MEDInfo_s* x )
{
  int len;
  char* buf;
  c->ns_tab = ZX_ALLOC(c, sizeof(zx_ns_tab));
  memcpy(c->ns_tab, zx_ns_tab, sizeof(zx_ns_tab));
  len = zx_LEN_SO_idp_MEDInfo(c, x );
  buf = ZX_ALLOC(c, len+1);
  return zx_easy_enc_common(c, zx_ENC_SO_idp_MEDInfo(c, x, buf ), buf, len);
}

/* FUNC(zx_EASY_ENC_WO_idp_MEDInfo) */

/* Called by: */
struct zx_str* zx_EASY_ENC_WO_idp_MEDInfo(struct zx_ctx* c, struct zx_idp_MEDInfo_s* x )
{
  int len;
  char* buf;
  c->ns_tab = ZX_ALLOC(c, sizeof(zx_ns_tab));
  memcpy(c->ns_tab, zx_ns_tab, sizeof(zx_ns_tab));
  len = zx_LEN_WO_idp_MEDInfo(c, x );
  buf = ZX_ALLOC(c, len+1);
  return zx_easy_enc_common(c, zx_ENC_WO_idp_MEDInfo(c, x, buf ), buf, len);
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

#define EL_NAME   idp_ProviderInfo
#define EL_STRUCT zx_idp_ProviderInfo_s
#define EL_NS     idp
#define EL_TAG    ProviderInfo

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

/* FUNC(zx_LEN_SO_idp_ProviderInfo) */

/* Compute length of an element (and its subelements). The XML attributes
 * and elements are processed in schema order. */

/* Called by: */
int zx_LEN_SO_idp_ProviderInfo(struct zx_ctx* c, struct zx_idp_ProviderInfo_s* x )
{
  struct zx_ns_s* pop_seen = 0;
  struct zx_elem_s* se MAYBE_UNUSED;
#if 1 /* NORMALMODE */
  /* *** in simple_elem case should output ns prefix from ns node. */
  int len = sizeof("<idp:ProviderInfo")-1 + 1 + sizeof("</idp:ProviderInfo>")-1;
  if (c->inc_ns_len)
    len += zx_len_inc_ns(c, &pop_seen);
  len += zx_len_xmlns_if_not_seen(c, zx_ns_tab+zx_xmlns_ix_idp, &pop_seen);

  len += zx_attr_so_len(x->name, sizeof("name")-1);
  len += zx_attr_so_len(x->providerID, sizeof("providerID")-1);

#else
  /* root node has no begin tag */
  int len = 0;
#endif
  


  len += zx_len_so_common(c, &x->gg);
  zx_pop_seen(pop_seen);
  ENC_LEN_DEBUG(x, "idp:ProviderInfo", len);
  return len;
}

/* FUNC(zx_LEN_WO_idp_ProviderInfo) */

/* Compute length of an element (and its subelements). The XML attributes
 * and elements are processed in wire order and no assumptions
 * are made about namespace prefixes. */

/* Called by: */
int zx_LEN_WO_idp_ProviderInfo(struct zx_ctx* c, struct zx_idp_ProviderInfo_s* x )
{
  struct zx_ns_s* pop_seen = 0;
  struct zx_elem_s* se MAYBE_UNUSED;
#if 1 /* NORMALMODE */
  int len = 1 + sizeof("ProviderInfo")-1 + 1 + 2 + sizeof("ProviderInfo")-1 + 1;
  
  if (x->gg.g.ns && x->gg.g.ns->prefix_len)
    len += (x->gg.g.ns->prefix_len + 1) * 2;
  if (c->inc_ns_len)
    len += zx_len_inc_ns(c, &pop_seen);
  len += zx_len_xmlns_if_not_seen(c, x->gg.g.ns, &pop_seen);

  len += zx_attr_wo_len(x->name, sizeof("name")-1);
  len += zx_attr_wo_len(x->providerID, sizeof("providerID")-1);

#else
  /* root node has no begin tag */
  int len = 0;
#endif
  


  len += zx_len_wo_common(c, &x->gg); 
  zx_pop_seen(pop_seen);
  ENC_LEN_DEBUG(x, "idp:ProviderInfo", len);
  return len;
}

/* FUNC(zx_ENC_SO_idp_ProviderInfo) */

/* Render element into string. The XML attributes and elements are
 * processed in schema order. This is what you generally want for
 * rendering new data structure to a string. The wo pointers are not used. */

/* Called by: */
char* zx_ENC_SO_idp_ProviderInfo(struct zx_ctx* c, struct zx_idp_ProviderInfo_s* x, char* p )
{
  struct zx_elem_s* se MAYBE_UNUSED;
  ENC_LEN_DEBUG_BASE;
#if 1 /* NORMALMODE */
  struct zx_ns_s* pop_seen = 0;
  /* *** in simple_elem case should output ns prefix from ns node. */
  ZX_OUT_TAG(p, "<idp:ProviderInfo");
  if (c->inc_ns)
    p = zx_enc_inc_ns(c, p, &pop_seen);
  p = zx_enc_xmlns_if_not_seen(c, p, zx_ns_tab+zx_xmlns_ix_idp, &pop_seen);

  p = zx_attr_so_enc(p, x->name, " name=\"", sizeof(" name=\"")-1);
  p = zx_attr_so_enc(p, x->providerID, " providerID=\"", sizeof(" providerID=\"")-1);

  p = zx_enc_unknown_attrs(p, x->gg.any_attr);
#else
  /* root node has no begin tag */
#endif
  

  p = zx_enc_so_unknown_elems_and_content(c, p, &x->gg);
  
#if 1 /* NORMALMODE */
  ZX_OUT_CLOSE_TAG(p, "</idp:ProviderInfo>");
  zx_pop_seen(pop_seen);
#else
  /* root node has no end tag either */
#endif
  ENC_LEN_DEBUG(x, "idp:ProviderInfo", p-enc_base);
  return p;
}

/* FUNC(zx_ENC_WO_idp_ProviderInfo) */

/* Render element into string. The XML attributes and elements are
 * processed in wire order by chasing wo pointers. This is what you want for
 * validating signatures on other people's XML documents. */

/* Called by: */
char* zx_ENC_WO_idp_ProviderInfo(struct zx_ctx* c, struct zx_idp_ProviderInfo_s* x, char* p )
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
  ZX_OUT_MEM(p, "ProviderInfo", sizeof("ProviderInfo")-1);
  qq = p;

  /* *** sort the namespaces */
  if (c->inc_ns)
    zx_add_inc_ns(c, &pop_seen);
  zx_add_xmlns_if_not_seen(c, x->gg.g.ns, &pop_seen);

  p = zx_enc_seen(p, pop_seen); 
  p = zx_attr_wo_enc(p, x->name, "name=\"", sizeof("name=\"")-1);
  p = zx_attr_wo_enc(p, x->providerID, "providerID=\"", sizeof("providerID=\"")-1);

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
  ENC_LEN_DEBUG(x, "idp:ProviderInfo", p-enc_base);
  return p;
}

/* FUNC(zx_EASY_ENC_SO_idp_ProviderInfo) */

/* Called by: */
struct zx_str* zx_EASY_ENC_SO_idp_ProviderInfo(struct zx_ctx* c, struct zx_idp_ProviderInfo_s* x )
{
  int len;
  char* buf;
  c->ns_tab = ZX_ALLOC(c, sizeof(zx_ns_tab));
  memcpy(c->ns_tab, zx_ns_tab, sizeof(zx_ns_tab));
  len = zx_LEN_SO_idp_ProviderInfo(c, x );
  buf = ZX_ALLOC(c, len+1);
  return zx_easy_enc_common(c, zx_ENC_SO_idp_ProviderInfo(c, x, buf ), buf, len);
}

/* FUNC(zx_EASY_ENC_WO_idp_ProviderInfo) */

/* Called by: */
struct zx_str* zx_EASY_ENC_WO_idp_ProviderInfo(struct zx_ctx* c, struct zx_idp_ProviderInfo_s* x )
{
  int len;
  char* buf;
  c->ns_tab = ZX_ALLOC(c, sizeof(zx_ns_tab));
  memcpy(c->ns_tab, zx_ns_tab, sizeof(zx_ns_tab));
  len = zx_LEN_WO_idp_ProviderInfo(c, x );
  buf = ZX_ALLOC(c, len+1);
  return zx_easy_enc_common(c, zx_ENC_WO_idp_ProviderInfo(c, x, buf ), buf, len);
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

#define EL_NAME   idp_SubjectRestriction
#define EL_STRUCT zx_idp_SubjectRestriction_s
#define EL_NS     idp
#define EL_TAG    SubjectRestriction

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

/* FUNC(zx_LEN_SO_idp_SubjectRestriction) */

/* Compute length of an element (and its subelements). The XML attributes
 * and elements are processed in schema order. */

/* Called by: */
int zx_LEN_SO_idp_SubjectRestriction(struct zx_ctx* c, struct zx_idp_SubjectRestriction_s* x )
{
  struct zx_ns_s* pop_seen = 0;
  struct zx_elem_s* se MAYBE_UNUSED;
#if 1 /* NORMALMODE */
  /* *** in simple_elem case should output ns prefix from ns node. */
  int len = sizeof("<idp:SubjectRestriction")-1 + 1 + sizeof("</idp:SubjectRestriction>")-1;
  if (c->inc_ns_len)
    len += zx_len_inc_ns(c, &pop_seen);
  len += zx_len_xmlns_if_not_seen(c, zx_ns_tab+zx_xmlns_ix_idp, &pop_seen);


#else
  /* root node has no begin tag */
  int len = 0;
#endif
  
  {
      struct zx_sa_Subject_s* e;
      for (e = x->Subject; e; e = (struct zx_sa_Subject_s*)e->gg.g.n)
	  len += zx_LEN_SO_sa_Subject(c, e);
  }


  len += zx_len_so_common(c, &x->gg);
  zx_pop_seen(pop_seen);
  ENC_LEN_DEBUG(x, "idp:SubjectRestriction", len);
  return len;
}

/* FUNC(zx_LEN_WO_idp_SubjectRestriction) */

/* Compute length of an element (and its subelements). The XML attributes
 * and elements are processed in wire order and no assumptions
 * are made about namespace prefixes. */

/* Called by: */
int zx_LEN_WO_idp_SubjectRestriction(struct zx_ctx* c, struct zx_idp_SubjectRestriction_s* x )
{
  struct zx_ns_s* pop_seen = 0;
  struct zx_elem_s* se MAYBE_UNUSED;
#if 1 /* NORMALMODE */
  int len = 1 + sizeof("SubjectRestriction")-1 + 1 + 2 + sizeof("SubjectRestriction")-1 + 1;
  
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
      struct zx_sa_Subject_s* e;
      for (e = x->Subject; e; e = (struct zx_sa_Subject_s*)e->gg.g.n)
	  len += zx_LEN_WO_sa_Subject(c, e);
  }


  len += zx_len_wo_common(c, &x->gg); 
  zx_pop_seen(pop_seen);
  ENC_LEN_DEBUG(x, "idp:SubjectRestriction", len);
  return len;
}

/* FUNC(zx_ENC_SO_idp_SubjectRestriction) */

/* Render element into string. The XML attributes and elements are
 * processed in schema order. This is what you generally want for
 * rendering new data structure to a string. The wo pointers are not used. */

/* Called by: */
char* zx_ENC_SO_idp_SubjectRestriction(struct zx_ctx* c, struct zx_idp_SubjectRestriction_s* x, char* p )
{
  struct zx_elem_s* se MAYBE_UNUSED;
  ENC_LEN_DEBUG_BASE;
#if 1 /* NORMALMODE */
  struct zx_ns_s* pop_seen = 0;
  /* *** in simple_elem case should output ns prefix from ns node. */
  ZX_OUT_TAG(p, "<idp:SubjectRestriction");
  if (c->inc_ns)
    p = zx_enc_inc_ns(c, p, &pop_seen);
  p = zx_enc_xmlns_if_not_seen(c, p, zx_ns_tab+zx_xmlns_ix_idp, &pop_seen);


  p = zx_enc_unknown_attrs(p, x->gg.any_attr);
#else
  /* root node has no begin tag */
#endif
  
  {
      struct zx_sa_Subject_s* e;
      for (e = x->Subject; e; e = (struct zx_sa_Subject_s*)e->gg.g.n)
	  p = zx_ENC_SO_sa_Subject(c, e, p);
  }

  p = zx_enc_so_unknown_elems_and_content(c, p, &x->gg);
  
#if 1 /* NORMALMODE */
  ZX_OUT_CLOSE_TAG(p, "</idp:SubjectRestriction>");
  zx_pop_seen(pop_seen);
#else
  /* root node has no end tag either */
#endif
  ENC_LEN_DEBUG(x, "idp:SubjectRestriction", p-enc_base);
  return p;
}

/* FUNC(zx_ENC_WO_idp_SubjectRestriction) */

/* Render element into string. The XML attributes and elements are
 * processed in wire order by chasing wo pointers. This is what you want for
 * validating signatures on other people's XML documents. */

/* Called by: */
char* zx_ENC_WO_idp_SubjectRestriction(struct zx_ctx* c, struct zx_idp_SubjectRestriction_s* x, char* p )
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
  ZX_OUT_MEM(p, "SubjectRestriction", sizeof("SubjectRestriction")-1);
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
  ENC_LEN_DEBUG(x, "idp:SubjectRestriction", p-enc_base);
  return p;
}

/* FUNC(zx_EASY_ENC_SO_idp_SubjectRestriction) */

/* Called by: */
struct zx_str* zx_EASY_ENC_SO_idp_SubjectRestriction(struct zx_ctx* c, struct zx_idp_SubjectRestriction_s* x )
{
  int len;
  char* buf;
  c->ns_tab = ZX_ALLOC(c, sizeof(zx_ns_tab));
  memcpy(c->ns_tab, zx_ns_tab, sizeof(zx_ns_tab));
  len = zx_LEN_SO_idp_SubjectRestriction(c, x );
  buf = ZX_ALLOC(c, len+1);
  return zx_easy_enc_common(c, zx_ENC_SO_idp_SubjectRestriction(c, x, buf ), buf, len);
}

/* FUNC(zx_EASY_ENC_WO_idp_SubjectRestriction) */

/* Called by: */
struct zx_str* zx_EASY_ENC_WO_idp_SubjectRestriction(struct zx_ctx* c, struct zx_idp_SubjectRestriction_s* x )
{
  int len;
  char* buf;
  c->ns_tab = ZX_ALLOC(c, sizeof(zx_ns_tab));
  memcpy(c->ns_tab, zx_ns_tab, sizeof(zx_ns_tab));
  len = zx_LEN_WO_idp_SubjectRestriction(c, x );
  buf = ZX_ALLOC(c, len+1);
  return zx_easy_enc_common(c, zx_ENC_WO_idp_SubjectRestriction(c, x, buf ), buf, len);
}




/* EOF -- c/zx-idp-enc.c */
