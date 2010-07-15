/* c/zx-sp11-enc.c - WARNING: This file was automatically generated. DO NOT EDIT!
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
#include "c/zx-sp11-data.h"
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

#define EL_NAME   sp11_AttributeQuery
#define EL_STRUCT zx_sp11_AttributeQuery_s
#define EL_NS     sp11
#define EL_TAG    AttributeQuery

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

/* FUNC(zx_LEN_SO_sp11_AttributeQuery) */

/* Compute length of an element (and its subelements). The XML attributes
 * and elements are processed in schema order. */

/* Called by: */
int zx_LEN_SO_sp11_AttributeQuery(struct zx_ctx* c, struct zx_sp11_AttributeQuery_s* x )
{
  struct zx_ns_s* pop_seen = 0;
  struct zx_elem_s* se MAYBE_UNUSED;
#if 1 /* NORMALMODE */
  /* *** in simple_elem case should output ns prefix from ns node. */
  int len = sizeof("<sp11:AttributeQuery")-1 + 1 + sizeof("</sp11:AttributeQuery>")-1;
  if (c->inc_ns_len)
    len += zx_len_inc_ns(c, &pop_seen);
  len += zx_len_xmlns_if_not_seen(c, zx_ns_tab+zx_xmlns_ix_sp11, &pop_seen);

  len += zx_attr_so_len(x->Resource, sizeof("Resource")-1);

#else
  /* root node has no begin tag */
  int len = 0;
#endif
  
  {
      struct zx_sa11_Subject_s* e;
      for (e = x->Subject; e; e = (struct zx_sa11_Subject_s*)e->gg.g.n)
	  len += zx_LEN_SO_sa11_Subject(c, e);
  }
  {
      struct zx_sa11_AttributeDesignator_s* e;
      for (e = x->AttributeDesignator; e; e = (struct zx_sa11_AttributeDesignator_s*)e->gg.g.n)
	  len += zx_LEN_SO_sa11_AttributeDesignator(c, e);
  }


  len += zx_len_so_common(c, &x->gg);
  zx_pop_seen(pop_seen);
  ENC_LEN_DEBUG(x, "sp11:AttributeQuery", len);
  return len;
}

/* FUNC(zx_LEN_WO_sp11_AttributeQuery) */

/* Compute length of an element (and its subelements). The XML attributes
 * and elements are processed in wire order and no assumptions
 * are made about namespace prefixes. */

/* Called by: */
int zx_LEN_WO_sp11_AttributeQuery(struct zx_ctx* c, struct zx_sp11_AttributeQuery_s* x )
{
  struct zx_ns_s* pop_seen = 0;
  struct zx_elem_s* se MAYBE_UNUSED;
#if 1 /* NORMALMODE */
  int len = 1 + sizeof("AttributeQuery")-1 + 1 + 2 + sizeof("AttributeQuery")-1 + 1;
  
  if (x->gg.g.ns && x->gg.g.ns->prefix_len)
    len += (x->gg.g.ns->prefix_len + 1) * 2;
  if (c->inc_ns_len)
    len += zx_len_inc_ns(c, &pop_seen);
  len += zx_len_xmlns_if_not_seen(c, x->gg.g.ns, &pop_seen);

  len += zx_attr_wo_len(x->Resource, sizeof("Resource")-1);

#else
  /* root node has no begin tag */
  int len = 0;
#endif
  
  {
      struct zx_sa11_Subject_s* e;
      for (e = x->Subject; e; e = (struct zx_sa11_Subject_s*)e->gg.g.n)
	  len += zx_LEN_WO_sa11_Subject(c, e);
  }
  {
      struct zx_sa11_AttributeDesignator_s* e;
      for (e = x->AttributeDesignator; e; e = (struct zx_sa11_AttributeDesignator_s*)e->gg.g.n)
	  len += zx_LEN_WO_sa11_AttributeDesignator(c, e);
  }


  len += zx_len_wo_common(c, &x->gg); 
  zx_pop_seen(pop_seen);
  ENC_LEN_DEBUG(x, "sp11:AttributeQuery", len);
  return len;
}

/* FUNC(zx_ENC_SO_sp11_AttributeQuery) */

/* Render element into string. The XML attributes and elements are
 * processed in schema order. This is what you generally want for
 * rendering new data structure to a string. The wo pointers are not used. */

/* Called by: */
char* zx_ENC_SO_sp11_AttributeQuery(struct zx_ctx* c, struct zx_sp11_AttributeQuery_s* x, char* p )
{
  struct zx_elem_s* se MAYBE_UNUSED;
  struct zx_ns_s* pop_seen = 0;
  ENC_LEN_DEBUG_BASE;
#if 1 /* NORMALMODE */
  /* *** in simple_elem case should output ns prefix from ns node. */
  ZX_OUT_TAG(p, "<sp11:AttributeQuery");
  if (c->inc_ns)
    p = zx_enc_inc_ns(c, p, &pop_seen);
  p = zx_enc_xmlns_if_not_seen(c, p, zx_ns_tab+zx_xmlns_ix_sp11, &pop_seen);

  p = zx_attr_so_enc(p, x->Resource, " Resource=\"", sizeof(" Resource=\"")-1);

  p = zx_enc_unknown_attrs(p, x->gg.any_attr);
#else
  /* root node has no begin tag */
#endif
  
  {
      struct zx_sa11_Subject_s* e;
      for (e = x->Subject; e; e = (struct zx_sa11_Subject_s*)e->gg.g.n)
	  p = zx_ENC_SO_sa11_Subject(c, e, p);
  }
  {
      struct zx_sa11_AttributeDesignator_s* e;
      for (e = x->AttributeDesignator; e; e = (struct zx_sa11_AttributeDesignator_s*)e->gg.g.n)
	  p = zx_ENC_SO_sa11_AttributeDesignator(c, e, p);
  }

  p = zx_enc_so_unknown_elems_and_content(c, p, &x->gg);
  
#if 1 /* NORMALMODE */
  ZX_OUT_CLOSE_TAG(p, "</sp11:AttributeQuery>");
  zx_pop_seen(pop_seen);
#else
  /* root node has no end tag either */
#endif
  ENC_LEN_DEBUG(x, "sp11:AttributeQuery", p-enc_base);
  return p;
}

/* FUNC(zx_ENC_WO_sp11_AttributeQuery) */

/* Render element into string. The XML attributes and elements are
 * processed in wire order by chasing wo pointers. This is what you want for
 * validating signatures on other people's XML documents. */

/* Called by: */
char* zx_ENC_WO_sp11_AttributeQuery(struct zx_ctx* c, struct zx_sp11_AttributeQuery_s* x, char* p )
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
  ZX_OUT_MEM(p, "AttributeQuery", sizeof("AttributeQuery")-1);
  qq = p;

  /* *** sort the namespaces */
  if (c->inc_ns)
    zx_add_inc_ns(c, &pop_seen);
  zx_add_xmlns_if_not_seen(c, x->gg.g.ns, &pop_seen);

  p = zx_enc_seen(p, pop_seen); 
  p = zx_attr_wo_enc(p, x->Resource, "Resource=\"", sizeof("Resource=\"")-1);

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
  ENC_LEN_DEBUG(x, "sp11:AttributeQuery", p-enc_base);
  return p;
}

/* FUNC(zx_EASY_ENC_SO_sp11_AttributeQuery) */

/* Called by: */
struct zx_str* zx_EASY_ENC_SO_sp11_AttributeQuery(struct zx_ctx* c, struct zx_sp11_AttributeQuery_s* x )
{
  int len;
  char* buf;
  c->ns_tab = ZX_ALLOC(c, sizeof(zx_ns_tab));
  memcpy(c->ns_tab, zx_ns_tab, sizeof(zx_ns_tab));
  len = zx_LEN_SO_sp11_AttributeQuery(c, x );
  buf = ZX_ALLOC(c, len+1);
  return zx_easy_enc_common(c, zx_ENC_SO_sp11_AttributeQuery(c, x, buf ), buf, len);
}

/* FUNC(zx_EASY_ENC_WO_sp11_AttributeQuery) */

/* Called by: */
struct zx_str* zx_EASY_ENC_WO_sp11_AttributeQuery(struct zx_ctx* c, struct zx_sp11_AttributeQuery_s* x )
{
  int len;
  char* buf;
  c->ns_tab = ZX_ALLOC(c, sizeof(zx_ns_tab));
  memcpy(c->ns_tab, zx_ns_tab, sizeof(zx_ns_tab));
  len = zx_LEN_WO_sp11_AttributeQuery(c, x );
  buf = ZX_ALLOC(c, len+1);
  return zx_easy_enc_common(c, zx_ENC_WO_sp11_AttributeQuery(c, x, buf ), buf, len);
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

#define EL_NAME   sp11_AuthenticationQuery
#define EL_STRUCT zx_sp11_AuthenticationQuery_s
#define EL_NS     sp11
#define EL_TAG    AuthenticationQuery

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

/* FUNC(zx_LEN_SO_sp11_AuthenticationQuery) */

/* Compute length of an element (and its subelements). The XML attributes
 * and elements are processed in schema order. */

/* Called by: */
int zx_LEN_SO_sp11_AuthenticationQuery(struct zx_ctx* c, struct zx_sp11_AuthenticationQuery_s* x )
{
  struct zx_ns_s* pop_seen = 0;
  struct zx_elem_s* se MAYBE_UNUSED;
#if 1 /* NORMALMODE */
  /* *** in simple_elem case should output ns prefix from ns node. */
  int len = sizeof("<sp11:AuthenticationQuery")-1 + 1 + sizeof("</sp11:AuthenticationQuery>")-1;
  if (c->inc_ns_len)
    len += zx_len_inc_ns(c, &pop_seen);
  len += zx_len_xmlns_if_not_seen(c, zx_ns_tab+zx_xmlns_ix_sp11, &pop_seen);

  len += zx_attr_so_len(x->AuthenticationMethod, sizeof("AuthenticationMethod")-1);

#else
  /* root node has no begin tag */
  int len = 0;
#endif
  
  {
      struct zx_sa11_Subject_s* e;
      for (e = x->Subject; e; e = (struct zx_sa11_Subject_s*)e->gg.g.n)
	  len += zx_LEN_SO_sa11_Subject(c, e);
  }


  len += zx_len_so_common(c, &x->gg);
  zx_pop_seen(pop_seen);
  ENC_LEN_DEBUG(x, "sp11:AuthenticationQuery", len);
  return len;
}

/* FUNC(zx_LEN_WO_sp11_AuthenticationQuery) */

/* Compute length of an element (and its subelements). The XML attributes
 * and elements are processed in wire order and no assumptions
 * are made about namespace prefixes. */

/* Called by: */
int zx_LEN_WO_sp11_AuthenticationQuery(struct zx_ctx* c, struct zx_sp11_AuthenticationQuery_s* x )
{
  struct zx_ns_s* pop_seen = 0;
  struct zx_elem_s* se MAYBE_UNUSED;
#if 1 /* NORMALMODE */
  int len = 1 + sizeof("AuthenticationQuery")-1 + 1 + 2 + sizeof("AuthenticationQuery")-1 + 1;
  
  if (x->gg.g.ns && x->gg.g.ns->prefix_len)
    len += (x->gg.g.ns->prefix_len + 1) * 2;
  if (c->inc_ns_len)
    len += zx_len_inc_ns(c, &pop_seen);
  len += zx_len_xmlns_if_not_seen(c, x->gg.g.ns, &pop_seen);

  len += zx_attr_wo_len(x->AuthenticationMethod, sizeof("AuthenticationMethod")-1);

#else
  /* root node has no begin tag */
  int len = 0;
#endif
  
  {
      struct zx_sa11_Subject_s* e;
      for (e = x->Subject; e; e = (struct zx_sa11_Subject_s*)e->gg.g.n)
	  len += zx_LEN_WO_sa11_Subject(c, e);
  }


  len += zx_len_wo_common(c, &x->gg); 
  zx_pop_seen(pop_seen);
  ENC_LEN_DEBUG(x, "sp11:AuthenticationQuery", len);
  return len;
}

/* FUNC(zx_ENC_SO_sp11_AuthenticationQuery) */

/* Render element into string. The XML attributes and elements are
 * processed in schema order. This is what you generally want for
 * rendering new data structure to a string. The wo pointers are not used. */

/* Called by: */
char* zx_ENC_SO_sp11_AuthenticationQuery(struct zx_ctx* c, struct zx_sp11_AuthenticationQuery_s* x, char* p )
{
  struct zx_elem_s* se MAYBE_UNUSED;
  struct zx_ns_s* pop_seen = 0;
  ENC_LEN_DEBUG_BASE;
#if 1 /* NORMALMODE */
  /* *** in simple_elem case should output ns prefix from ns node. */
  ZX_OUT_TAG(p, "<sp11:AuthenticationQuery");
  if (c->inc_ns)
    p = zx_enc_inc_ns(c, p, &pop_seen);
  p = zx_enc_xmlns_if_not_seen(c, p, zx_ns_tab+zx_xmlns_ix_sp11, &pop_seen);

  p = zx_attr_so_enc(p, x->AuthenticationMethod, " AuthenticationMethod=\"", sizeof(" AuthenticationMethod=\"")-1);

  p = zx_enc_unknown_attrs(p, x->gg.any_attr);
#else
  /* root node has no begin tag */
#endif
  
  {
      struct zx_sa11_Subject_s* e;
      for (e = x->Subject; e; e = (struct zx_sa11_Subject_s*)e->gg.g.n)
	  p = zx_ENC_SO_sa11_Subject(c, e, p);
  }

  p = zx_enc_so_unknown_elems_and_content(c, p, &x->gg);
  
#if 1 /* NORMALMODE */
  ZX_OUT_CLOSE_TAG(p, "</sp11:AuthenticationQuery>");
  zx_pop_seen(pop_seen);
#else
  /* root node has no end tag either */
#endif
  ENC_LEN_DEBUG(x, "sp11:AuthenticationQuery", p-enc_base);
  return p;
}

/* FUNC(zx_ENC_WO_sp11_AuthenticationQuery) */

/* Render element into string. The XML attributes and elements are
 * processed in wire order by chasing wo pointers. This is what you want for
 * validating signatures on other people's XML documents. */

/* Called by: */
char* zx_ENC_WO_sp11_AuthenticationQuery(struct zx_ctx* c, struct zx_sp11_AuthenticationQuery_s* x, char* p )
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
  ZX_OUT_MEM(p, "AuthenticationQuery", sizeof("AuthenticationQuery")-1);
  qq = p;

  /* *** sort the namespaces */
  if (c->inc_ns)
    zx_add_inc_ns(c, &pop_seen);
  zx_add_xmlns_if_not_seen(c, x->gg.g.ns, &pop_seen);

  p = zx_enc_seen(p, pop_seen); 
  p = zx_attr_wo_enc(p, x->AuthenticationMethod, "AuthenticationMethod=\"", sizeof("AuthenticationMethod=\"")-1);

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
  ENC_LEN_DEBUG(x, "sp11:AuthenticationQuery", p-enc_base);
  return p;
}

/* FUNC(zx_EASY_ENC_SO_sp11_AuthenticationQuery) */

/* Called by: */
struct zx_str* zx_EASY_ENC_SO_sp11_AuthenticationQuery(struct zx_ctx* c, struct zx_sp11_AuthenticationQuery_s* x )
{
  int len;
  char* buf;
  c->ns_tab = ZX_ALLOC(c, sizeof(zx_ns_tab));
  memcpy(c->ns_tab, zx_ns_tab, sizeof(zx_ns_tab));
  len = zx_LEN_SO_sp11_AuthenticationQuery(c, x );
  buf = ZX_ALLOC(c, len+1);
  return zx_easy_enc_common(c, zx_ENC_SO_sp11_AuthenticationQuery(c, x, buf ), buf, len);
}

/* FUNC(zx_EASY_ENC_WO_sp11_AuthenticationQuery) */

/* Called by: */
struct zx_str* zx_EASY_ENC_WO_sp11_AuthenticationQuery(struct zx_ctx* c, struct zx_sp11_AuthenticationQuery_s* x )
{
  int len;
  char* buf;
  c->ns_tab = ZX_ALLOC(c, sizeof(zx_ns_tab));
  memcpy(c->ns_tab, zx_ns_tab, sizeof(zx_ns_tab));
  len = zx_LEN_WO_sp11_AuthenticationQuery(c, x );
  buf = ZX_ALLOC(c, len+1);
  return zx_easy_enc_common(c, zx_ENC_WO_sp11_AuthenticationQuery(c, x, buf ), buf, len);
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

#define EL_NAME   sp11_AuthorizationDecisionQuery
#define EL_STRUCT zx_sp11_AuthorizationDecisionQuery_s
#define EL_NS     sp11
#define EL_TAG    AuthorizationDecisionQuery

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

/* FUNC(zx_LEN_SO_sp11_AuthorizationDecisionQuery) */

/* Compute length of an element (and its subelements). The XML attributes
 * and elements are processed in schema order. */

/* Called by: */
int zx_LEN_SO_sp11_AuthorizationDecisionQuery(struct zx_ctx* c, struct zx_sp11_AuthorizationDecisionQuery_s* x )
{
  struct zx_ns_s* pop_seen = 0;
  struct zx_elem_s* se MAYBE_UNUSED;
#if 1 /* NORMALMODE */
  /* *** in simple_elem case should output ns prefix from ns node. */
  int len = sizeof("<sp11:AuthorizationDecisionQuery")-1 + 1 + sizeof("</sp11:AuthorizationDecisionQuery>")-1;
  if (c->inc_ns_len)
    len += zx_len_inc_ns(c, &pop_seen);
  len += zx_len_xmlns_if_not_seen(c, zx_ns_tab+zx_xmlns_ix_sp11, &pop_seen);

  len += zx_attr_so_len(x->Resource, sizeof("Resource")-1);

#else
  /* root node has no begin tag */
  int len = 0;
#endif
  
  {
      struct zx_sa11_Subject_s* e;
      for (e = x->Subject; e; e = (struct zx_sa11_Subject_s*)e->gg.g.n)
	  len += zx_LEN_SO_sa11_Subject(c, e);
  }
  {
      struct zx_sa11_Action_s* e;
      for (e = x->Action; e; e = (struct zx_sa11_Action_s*)e->gg.g.n)
	  len += zx_LEN_SO_sa11_Action(c, e);
  }
  {
      struct zx_sa11_Evidence_s* e;
      for (e = x->Evidence; e; e = (struct zx_sa11_Evidence_s*)e->gg.g.n)
	  len += zx_LEN_SO_sa11_Evidence(c, e);
  }


  len += zx_len_so_common(c, &x->gg);
  zx_pop_seen(pop_seen);
  ENC_LEN_DEBUG(x, "sp11:AuthorizationDecisionQuery", len);
  return len;
}

/* FUNC(zx_LEN_WO_sp11_AuthorizationDecisionQuery) */

/* Compute length of an element (and its subelements). The XML attributes
 * and elements are processed in wire order and no assumptions
 * are made about namespace prefixes. */

/* Called by: */
int zx_LEN_WO_sp11_AuthorizationDecisionQuery(struct zx_ctx* c, struct zx_sp11_AuthorizationDecisionQuery_s* x )
{
  struct zx_ns_s* pop_seen = 0;
  struct zx_elem_s* se MAYBE_UNUSED;
#if 1 /* NORMALMODE */
  int len = 1 + sizeof("AuthorizationDecisionQuery")-1 + 1 + 2 + sizeof("AuthorizationDecisionQuery")-1 + 1;
  
  if (x->gg.g.ns && x->gg.g.ns->prefix_len)
    len += (x->gg.g.ns->prefix_len + 1) * 2;
  if (c->inc_ns_len)
    len += zx_len_inc_ns(c, &pop_seen);
  len += zx_len_xmlns_if_not_seen(c, x->gg.g.ns, &pop_seen);

  len += zx_attr_wo_len(x->Resource, sizeof("Resource")-1);

#else
  /* root node has no begin tag */
  int len = 0;
#endif
  
  {
      struct zx_sa11_Subject_s* e;
      for (e = x->Subject; e; e = (struct zx_sa11_Subject_s*)e->gg.g.n)
	  len += zx_LEN_WO_sa11_Subject(c, e);
  }
  {
      struct zx_sa11_Action_s* e;
      for (e = x->Action; e; e = (struct zx_sa11_Action_s*)e->gg.g.n)
	  len += zx_LEN_WO_sa11_Action(c, e);
  }
  {
      struct zx_sa11_Evidence_s* e;
      for (e = x->Evidence; e; e = (struct zx_sa11_Evidence_s*)e->gg.g.n)
	  len += zx_LEN_WO_sa11_Evidence(c, e);
  }


  len += zx_len_wo_common(c, &x->gg); 
  zx_pop_seen(pop_seen);
  ENC_LEN_DEBUG(x, "sp11:AuthorizationDecisionQuery", len);
  return len;
}

/* FUNC(zx_ENC_SO_sp11_AuthorizationDecisionQuery) */

/* Render element into string. The XML attributes and elements are
 * processed in schema order. This is what you generally want for
 * rendering new data structure to a string. The wo pointers are not used. */

/* Called by: */
char* zx_ENC_SO_sp11_AuthorizationDecisionQuery(struct zx_ctx* c, struct zx_sp11_AuthorizationDecisionQuery_s* x, char* p )
{
  struct zx_elem_s* se MAYBE_UNUSED;
  struct zx_ns_s* pop_seen = 0;
  ENC_LEN_DEBUG_BASE;
#if 1 /* NORMALMODE */
  /* *** in simple_elem case should output ns prefix from ns node. */
  ZX_OUT_TAG(p, "<sp11:AuthorizationDecisionQuery");
  if (c->inc_ns)
    p = zx_enc_inc_ns(c, p, &pop_seen);
  p = zx_enc_xmlns_if_not_seen(c, p, zx_ns_tab+zx_xmlns_ix_sp11, &pop_seen);

  p = zx_attr_so_enc(p, x->Resource, " Resource=\"", sizeof(" Resource=\"")-1);

  p = zx_enc_unknown_attrs(p, x->gg.any_attr);
#else
  /* root node has no begin tag */
#endif
  
  {
      struct zx_sa11_Subject_s* e;
      for (e = x->Subject; e; e = (struct zx_sa11_Subject_s*)e->gg.g.n)
	  p = zx_ENC_SO_sa11_Subject(c, e, p);
  }
  {
      struct zx_sa11_Action_s* e;
      for (e = x->Action; e; e = (struct zx_sa11_Action_s*)e->gg.g.n)
	  p = zx_ENC_SO_sa11_Action(c, e, p);
  }
  {
      struct zx_sa11_Evidence_s* e;
      for (e = x->Evidence; e; e = (struct zx_sa11_Evidence_s*)e->gg.g.n)
	  p = zx_ENC_SO_sa11_Evidence(c, e, p);
  }

  p = zx_enc_so_unknown_elems_and_content(c, p, &x->gg);
  
#if 1 /* NORMALMODE */
  ZX_OUT_CLOSE_TAG(p, "</sp11:AuthorizationDecisionQuery>");
  zx_pop_seen(pop_seen);
#else
  /* root node has no end tag either */
#endif
  ENC_LEN_DEBUG(x, "sp11:AuthorizationDecisionQuery", p-enc_base);
  return p;
}

/* FUNC(zx_ENC_WO_sp11_AuthorizationDecisionQuery) */

/* Render element into string. The XML attributes and elements are
 * processed in wire order by chasing wo pointers. This is what you want for
 * validating signatures on other people's XML documents. */

/* Called by: */
char* zx_ENC_WO_sp11_AuthorizationDecisionQuery(struct zx_ctx* c, struct zx_sp11_AuthorizationDecisionQuery_s* x, char* p )
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
  ZX_OUT_MEM(p, "AuthorizationDecisionQuery", sizeof("AuthorizationDecisionQuery")-1);
  qq = p;

  /* *** sort the namespaces */
  if (c->inc_ns)
    zx_add_inc_ns(c, &pop_seen);
  zx_add_xmlns_if_not_seen(c, x->gg.g.ns, &pop_seen);

  p = zx_enc_seen(p, pop_seen); 
  p = zx_attr_wo_enc(p, x->Resource, "Resource=\"", sizeof("Resource=\"")-1);

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
  ENC_LEN_DEBUG(x, "sp11:AuthorizationDecisionQuery", p-enc_base);
  return p;
}

/* FUNC(zx_EASY_ENC_SO_sp11_AuthorizationDecisionQuery) */

/* Called by: */
struct zx_str* zx_EASY_ENC_SO_sp11_AuthorizationDecisionQuery(struct zx_ctx* c, struct zx_sp11_AuthorizationDecisionQuery_s* x )
{
  int len;
  char* buf;
  c->ns_tab = ZX_ALLOC(c, sizeof(zx_ns_tab));
  memcpy(c->ns_tab, zx_ns_tab, sizeof(zx_ns_tab));
  len = zx_LEN_SO_sp11_AuthorizationDecisionQuery(c, x );
  buf = ZX_ALLOC(c, len+1);
  return zx_easy_enc_common(c, zx_ENC_SO_sp11_AuthorizationDecisionQuery(c, x, buf ), buf, len);
}

/* FUNC(zx_EASY_ENC_WO_sp11_AuthorizationDecisionQuery) */

/* Called by: */
struct zx_str* zx_EASY_ENC_WO_sp11_AuthorizationDecisionQuery(struct zx_ctx* c, struct zx_sp11_AuthorizationDecisionQuery_s* x )
{
  int len;
  char* buf;
  c->ns_tab = ZX_ALLOC(c, sizeof(zx_ns_tab));
  memcpy(c->ns_tab, zx_ns_tab, sizeof(zx_ns_tab));
  len = zx_LEN_WO_sp11_AuthorizationDecisionQuery(c, x );
  buf = ZX_ALLOC(c, len+1);
  return zx_easy_enc_common(c, zx_ENC_WO_sp11_AuthorizationDecisionQuery(c, x, buf ), buf, len);
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

#define EL_NAME   sp11_Request
#define EL_STRUCT zx_sp11_Request_s
#define EL_NS     sp11
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

/* FUNC(zx_LEN_SO_sp11_Request) */

/* Compute length of an element (and its subelements). The XML attributes
 * and elements are processed in schema order. */

/* Called by: */
int zx_LEN_SO_sp11_Request(struct zx_ctx* c, struct zx_sp11_Request_s* x )
{
  struct zx_ns_s* pop_seen = 0;
  struct zx_elem_s* se MAYBE_UNUSED;
#if 1 /* NORMALMODE */
  /* *** in simple_elem case should output ns prefix from ns node. */
  int len = sizeof("<sp11:Request")-1 + 1 + sizeof("</sp11:Request>")-1;
  if (c->inc_ns_len)
    len += zx_len_inc_ns(c, &pop_seen);
  len += zx_len_xmlns_if_not_seen(c, zx_ns_tab+zx_xmlns_ix_sp11, &pop_seen);

  len += zx_attr_so_len(x->IssueInstant, sizeof("IssueInstant")-1);
  len += zx_attr_so_len(x->MajorVersion, sizeof("MajorVersion")-1);
  len += zx_attr_so_len(x->MinorVersion, sizeof("MinorVersion")-1);
  len += zx_attr_so_len(x->RequestID, sizeof("RequestID")-1);

#else
  /* root node has no begin tag */
  int len = 0;
#endif
  
  for (se = x->RespondWith; se; se = (struct zx_elem_s*)se->g.n)
    len += zx_LEN_SO_simple_elem(c,se, sizeof("sp11:RespondWith")-1, zx_ns_tab+zx_xmlns_ix_sp11);
  {
      struct zx_ds_Signature_s* e;
      for (e = x->Signature; e; e = (struct zx_ds_Signature_s*)e->gg.g.n)
	  if (e != c->exclude_sig)
              len += zx_LEN_SO_ds_Signature(c, e);
  }
  for (se = x->Query; se; se = (struct zx_elem_s*)se->g.n)
    len += zx_LEN_SO_simple_elem(c,se, sizeof("sp11:Query")-1, zx_ns_tab+zx_xmlns_ix_sp11);
  {
      struct zx_sp11_SubjectQuery_s* e;
      for (e = x->SubjectQuery; e; e = (struct zx_sp11_SubjectQuery_s*)e->gg.g.n)
	  len += zx_LEN_SO_sp11_SubjectQuery(c, e);
  }
  {
      struct zx_sp11_AuthenticationQuery_s* e;
      for (e = x->AuthenticationQuery; e; e = (struct zx_sp11_AuthenticationQuery_s*)e->gg.g.n)
	  len += zx_LEN_SO_sp11_AuthenticationQuery(c, e);
  }
  {
      struct zx_sp11_AttributeQuery_s* e;
      for (e = x->AttributeQuery; e; e = (struct zx_sp11_AttributeQuery_s*)e->gg.g.n)
	  len += zx_LEN_SO_sp11_AttributeQuery(c, e);
  }
  {
      struct zx_sp11_AuthorizationDecisionQuery_s* e;
      for (e = x->AuthorizationDecisionQuery; e; e = (struct zx_sp11_AuthorizationDecisionQuery_s*)e->gg.g.n)
	  len += zx_LEN_SO_sp11_AuthorizationDecisionQuery(c, e);
  }
  for (se = x->AssertionIDReference; se; se = (struct zx_elem_s*)se->g.n)
    len += zx_LEN_SO_simple_elem(c,se, sizeof("sa11:AssertionIDReference")-1, zx_ns_tab+zx_xmlns_ix_sa11);
  for (se = x->AssertionArtifact; se; se = (struct zx_elem_s*)se->g.n)
    len += zx_LEN_SO_simple_elem(c,se, sizeof("sp11:AssertionArtifact")-1, zx_ns_tab+zx_xmlns_ix_sp11);


  len += zx_len_so_common(c, &x->gg);
  zx_pop_seen(pop_seen);
  ENC_LEN_DEBUG(x, "sp11:Request", len);
  return len;
}

/* FUNC(zx_LEN_WO_sp11_Request) */

/* Compute length of an element (and its subelements). The XML attributes
 * and elements are processed in wire order and no assumptions
 * are made about namespace prefixes. */

/* Called by: */
int zx_LEN_WO_sp11_Request(struct zx_ctx* c, struct zx_sp11_Request_s* x )
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

  len += zx_attr_wo_len(x->IssueInstant, sizeof("IssueInstant")-1);
  len += zx_attr_wo_len(x->MajorVersion, sizeof("MajorVersion")-1);
  len += zx_attr_wo_len(x->MinorVersion, sizeof("MinorVersion")-1);
  len += zx_attr_wo_len(x->RequestID, sizeof("RequestID")-1);

#else
  /* root node has no begin tag */
  int len = 0;
#endif
  
  for (se = x->RespondWith; se; se = (struct zx_elem_s*)se->g.n)
    len += zx_LEN_WO_simple_elem(c, se, sizeof("RespondWith")-1);
  {
      struct zx_ds_Signature_s* e;
      for (e = x->Signature; e; e = (struct zx_ds_Signature_s*)e->gg.g.n)
	  if (e != c->exclude_sig)
              len += zx_LEN_WO_ds_Signature(c, e);
  }
  for (se = x->Query; se; se = (struct zx_elem_s*)se->g.n)
    len += zx_LEN_WO_simple_elem(c, se, sizeof("Query")-1);
  {
      struct zx_sp11_SubjectQuery_s* e;
      for (e = x->SubjectQuery; e; e = (struct zx_sp11_SubjectQuery_s*)e->gg.g.n)
	  len += zx_LEN_WO_sp11_SubjectQuery(c, e);
  }
  {
      struct zx_sp11_AuthenticationQuery_s* e;
      for (e = x->AuthenticationQuery; e; e = (struct zx_sp11_AuthenticationQuery_s*)e->gg.g.n)
	  len += zx_LEN_WO_sp11_AuthenticationQuery(c, e);
  }
  {
      struct zx_sp11_AttributeQuery_s* e;
      for (e = x->AttributeQuery; e; e = (struct zx_sp11_AttributeQuery_s*)e->gg.g.n)
	  len += zx_LEN_WO_sp11_AttributeQuery(c, e);
  }
  {
      struct zx_sp11_AuthorizationDecisionQuery_s* e;
      for (e = x->AuthorizationDecisionQuery; e; e = (struct zx_sp11_AuthorizationDecisionQuery_s*)e->gg.g.n)
	  len += zx_LEN_WO_sp11_AuthorizationDecisionQuery(c, e);
  }
  for (se = x->AssertionIDReference; se; se = (struct zx_elem_s*)se->g.n)
    len += zx_LEN_WO_simple_elem(c, se, sizeof("AssertionIDReference")-1);
  for (se = x->AssertionArtifact; se; se = (struct zx_elem_s*)se->g.n)
    len += zx_LEN_WO_simple_elem(c, se, sizeof("AssertionArtifact")-1);


  len += zx_len_wo_common(c, &x->gg); 
  zx_pop_seen(pop_seen);
  ENC_LEN_DEBUG(x, "sp11:Request", len);
  return len;
}

/* FUNC(zx_ENC_SO_sp11_Request) */

/* Render element into string. The XML attributes and elements are
 * processed in schema order. This is what you generally want for
 * rendering new data structure to a string. The wo pointers are not used. */

/* Called by: */
char* zx_ENC_SO_sp11_Request(struct zx_ctx* c, struct zx_sp11_Request_s* x, char* p )
{
  struct zx_elem_s* se MAYBE_UNUSED;
  struct zx_ns_s* pop_seen = 0;
  ENC_LEN_DEBUG_BASE;
#if 1 /* NORMALMODE */
  /* *** in simple_elem case should output ns prefix from ns node. */
  ZX_OUT_TAG(p, "<sp11:Request");
  if (c->inc_ns)
    p = zx_enc_inc_ns(c, p, &pop_seen);
  p = zx_enc_xmlns_if_not_seen(c, p, zx_ns_tab+zx_xmlns_ix_sp11, &pop_seen);

  p = zx_attr_so_enc(p, x->IssueInstant, " IssueInstant=\"", sizeof(" IssueInstant=\"")-1);
  p = zx_attr_so_enc(p, x->MajorVersion, " MajorVersion=\"", sizeof(" MajorVersion=\"")-1);
  p = zx_attr_so_enc(p, x->MinorVersion, " MinorVersion=\"", sizeof(" MinorVersion=\"")-1);
  p = zx_attr_so_enc(p, x->RequestID, " RequestID=\"", sizeof(" RequestID=\"")-1);

  p = zx_enc_unknown_attrs(p, x->gg.any_attr);
#else
  /* root node has no begin tag */
#endif
  
  for (se = x->RespondWith; se; se = (struct zx_elem_s*)se->g.n)
    p = zx_ENC_SO_simple_elem(c, se, p, "sp11:RespondWith", sizeof("sp11:RespondWith")-1, zx_ns_tab+zx_xmlns_ix_sp11);
  {
      struct zx_ds_Signature_s* e;
      for (e = x->Signature; e; e = (struct zx_ds_Signature_s*)e->gg.g.n)
	  if (e != c->exclude_sig)
              p = zx_ENC_SO_ds_Signature(c, e, p);
  }
  for (se = x->Query; se; se = (struct zx_elem_s*)se->g.n)
    p = zx_ENC_SO_simple_elem(c, se, p, "sp11:Query", sizeof("sp11:Query")-1, zx_ns_tab+zx_xmlns_ix_sp11);
  {
      struct zx_sp11_SubjectQuery_s* e;
      for (e = x->SubjectQuery; e; e = (struct zx_sp11_SubjectQuery_s*)e->gg.g.n)
	  p = zx_ENC_SO_sp11_SubjectQuery(c, e, p);
  }
  {
      struct zx_sp11_AuthenticationQuery_s* e;
      for (e = x->AuthenticationQuery; e; e = (struct zx_sp11_AuthenticationQuery_s*)e->gg.g.n)
	  p = zx_ENC_SO_sp11_AuthenticationQuery(c, e, p);
  }
  {
      struct zx_sp11_AttributeQuery_s* e;
      for (e = x->AttributeQuery; e; e = (struct zx_sp11_AttributeQuery_s*)e->gg.g.n)
	  p = zx_ENC_SO_sp11_AttributeQuery(c, e, p);
  }
  {
      struct zx_sp11_AuthorizationDecisionQuery_s* e;
      for (e = x->AuthorizationDecisionQuery; e; e = (struct zx_sp11_AuthorizationDecisionQuery_s*)e->gg.g.n)
	  p = zx_ENC_SO_sp11_AuthorizationDecisionQuery(c, e, p);
  }
  for (se = x->AssertionIDReference; se; se = (struct zx_elem_s*)se->g.n)
    p = zx_ENC_SO_simple_elem(c, se, p, "sa11:AssertionIDReference", sizeof("sa11:AssertionIDReference")-1, zx_ns_tab+zx_xmlns_ix_sa11);
  for (se = x->AssertionArtifact; se; se = (struct zx_elem_s*)se->g.n)
    p = zx_ENC_SO_simple_elem(c, se, p, "sp11:AssertionArtifact", sizeof("sp11:AssertionArtifact")-1, zx_ns_tab+zx_xmlns_ix_sp11);

  p = zx_enc_so_unknown_elems_and_content(c, p, &x->gg);
  
#if 1 /* NORMALMODE */
  ZX_OUT_CLOSE_TAG(p, "</sp11:Request>");
  zx_pop_seen(pop_seen);
#else
  /* root node has no end tag either */
#endif
  ENC_LEN_DEBUG(x, "sp11:Request", p-enc_base);
  return p;
}

/* FUNC(zx_ENC_WO_sp11_Request) */

/* Render element into string. The XML attributes and elements are
 * processed in wire order by chasing wo pointers. This is what you want for
 * validating signatures on other people's XML documents. */

/* Called by: */
char* zx_ENC_WO_sp11_Request(struct zx_ctx* c, struct zx_sp11_Request_s* x, char* p )
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

  /* *** sort the namespaces */
  if (c->inc_ns)
    zx_add_inc_ns(c, &pop_seen);
  zx_add_xmlns_if_not_seen(c, x->gg.g.ns, &pop_seen);

  p = zx_enc_seen(p, pop_seen); 
  p = zx_attr_wo_enc(p, x->IssueInstant, "IssueInstant=\"", sizeof("IssueInstant=\"")-1);
  p = zx_attr_wo_enc(p, x->MajorVersion, "MajorVersion=\"", sizeof("MajorVersion=\"")-1);
  p = zx_attr_wo_enc(p, x->MinorVersion, "MinorVersion=\"", sizeof("MinorVersion=\"")-1);
  p = zx_attr_wo_enc(p, x->RequestID, "RequestID=\"", sizeof("RequestID=\"")-1);

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
  ENC_LEN_DEBUG(x, "sp11:Request", p-enc_base);
  return p;
}

/* FUNC(zx_EASY_ENC_SO_sp11_Request) */

/* Called by: */
struct zx_str* zx_EASY_ENC_SO_sp11_Request(struct zx_ctx* c, struct zx_sp11_Request_s* x )
{
  int len;
  char* buf;
  c->ns_tab = ZX_ALLOC(c, sizeof(zx_ns_tab));
  memcpy(c->ns_tab, zx_ns_tab, sizeof(zx_ns_tab));
  len = zx_LEN_SO_sp11_Request(c, x );
  buf = ZX_ALLOC(c, len+1);
  return zx_easy_enc_common(c, zx_ENC_SO_sp11_Request(c, x, buf ), buf, len);
}

/* FUNC(zx_EASY_ENC_WO_sp11_Request) */

/* Called by: */
struct zx_str* zx_EASY_ENC_WO_sp11_Request(struct zx_ctx* c, struct zx_sp11_Request_s* x )
{
  int len;
  char* buf;
  c->ns_tab = ZX_ALLOC(c, sizeof(zx_ns_tab));
  memcpy(c->ns_tab, zx_ns_tab, sizeof(zx_ns_tab));
  len = zx_LEN_WO_sp11_Request(c, x );
  buf = ZX_ALLOC(c, len+1);
  return zx_easy_enc_common(c, zx_ENC_WO_sp11_Request(c, x, buf ), buf, len);
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

#define EL_NAME   sp11_Response
#define EL_STRUCT zx_sp11_Response_s
#define EL_NS     sp11
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

/* FUNC(zx_LEN_SO_sp11_Response) */

/* Compute length of an element (and its subelements). The XML attributes
 * and elements are processed in schema order. */

/* Called by: */
int zx_LEN_SO_sp11_Response(struct zx_ctx* c, struct zx_sp11_Response_s* x )
{
  struct zx_ns_s* pop_seen = 0;
  struct zx_elem_s* se MAYBE_UNUSED;
#if 1 /* NORMALMODE */
  /* *** in simple_elem case should output ns prefix from ns node. */
  int len = sizeof("<sp11:Response")-1 + 1 + sizeof("</sp11:Response>")-1;
  if (c->inc_ns_len)
    len += zx_len_inc_ns(c, &pop_seen);
  len += zx_len_xmlns_if_not_seen(c, zx_ns_tab+zx_xmlns_ix_sp11, &pop_seen);

  len += zx_attr_so_len(x->InResponseTo, sizeof("InResponseTo")-1);
  len += zx_attr_so_len(x->IssueInstant, sizeof("IssueInstant")-1);
  len += zx_attr_so_len(x->MajorVersion, sizeof("MajorVersion")-1);
  len += zx_attr_so_len(x->MinorVersion, sizeof("MinorVersion")-1);
  len += zx_attr_so_len(x->Recipient, sizeof("Recipient")-1);
  len += zx_attr_so_len(x->ResponseID, sizeof("ResponseID")-1);

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
      struct zx_sp11_Status_s* e;
      for (e = x->Status; e; e = (struct zx_sp11_Status_s*)e->gg.g.n)
	  len += zx_LEN_SO_sp11_Status(c, e);
  }
  {
      struct zx_sa11_Assertion_s* e;
      for (e = x->Assertion; e; e = (struct zx_sa11_Assertion_s*)e->gg.g.n)
	  len += zx_LEN_SO_sa11_Assertion(c, e);
  }


  len += zx_len_so_common(c, &x->gg);
  zx_pop_seen(pop_seen);
  ENC_LEN_DEBUG(x, "sp11:Response", len);
  return len;
}

/* FUNC(zx_LEN_WO_sp11_Response) */

/* Compute length of an element (and its subelements). The XML attributes
 * and elements are processed in wire order and no assumptions
 * are made about namespace prefixes. */

/* Called by: */
int zx_LEN_WO_sp11_Response(struct zx_ctx* c, struct zx_sp11_Response_s* x )
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

  len += zx_attr_wo_len(x->InResponseTo, sizeof("InResponseTo")-1);
  len += zx_attr_wo_len(x->IssueInstant, sizeof("IssueInstant")-1);
  len += zx_attr_wo_len(x->MajorVersion, sizeof("MajorVersion")-1);
  len += zx_attr_wo_len(x->MinorVersion, sizeof("MinorVersion")-1);
  len += zx_attr_wo_len(x->Recipient, sizeof("Recipient")-1);
  len += zx_attr_wo_len(x->ResponseID, sizeof("ResponseID")-1);

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
      struct zx_sp11_Status_s* e;
      for (e = x->Status; e; e = (struct zx_sp11_Status_s*)e->gg.g.n)
	  len += zx_LEN_WO_sp11_Status(c, e);
  }
  {
      struct zx_sa11_Assertion_s* e;
      for (e = x->Assertion; e; e = (struct zx_sa11_Assertion_s*)e->gg.g.n)
	  len += zx_LEN_WO_sa11_Assertion(c, e);
  }


  len += zx_len_wo_common(c, &x->gg); 
  zx_pop_seen(pop_seen);
  ENC_LEN_DEBUG(x, "sp11:Response", len);
  return len;
}

/* FUNC(zx_ENC_SO_sp11_Response) */

/* Render element into string. The XML attributes and elements are
 * processed in schema order. This is what you generally want for
 * rendering new data structure to a string. The wo pointers are not used. */

/* Called by: */
char* zx_ENC_SO_sp11_Response(struct zx_ctx* c, struct zx_sp11_Response_s* x, char* p )
{
  struct zx_elem_s* se MAYBE_UNUSED;
  struct zx_ns_s* pop_seen = 0;
  ENC_LEN_DEBUG_BASE;
#if 1 /* NORMALMODE */
  /* *** in simple_elem case should output ns prefix from ns node. */
  ZX_OUT_TAG(p, "<sp11:Response");
  if (c->inc_ns)
    p = zx_enc_inc_ns(c, p, &pop_seen);
  p = zx_enc_xmlns_if_not_seen(c, p, zx_ns_tab+zx_xmlns_ix_sp11, &pop_seen);

  p = zx_attr_so_enc(p, x->InResponseTo, " InResponseTo=\"", sizeof(" InResponseTo=\"")-1);
  p = zx_attr_so_enc(p, x->IssueInstant, " IssueInstant=\"", sizeof(" IssueInstant=\"")-1);
  p = zx_attr_so_enc(p, x->MajorVersion, " MajorVersion=\"", sizeof(" MajorVersion=\"")-1);
  p = zx_attr_so_enc(p, x->MinorVersion, " MinorVersion=\"", sizeof(" MinorVersion=\"")-1);
  p = zx_attr_so_enc(p, x->Recipient, " Recipient=\"", sizeof(" Recipient=\"")-1);
  p = zx_attr_so_enc(p, x->ResponseID, " ResponseID=\"", sizeof(" ResponseID=\"")-1);

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
      struct zx_sp11_Status_s* e;
      for (e = x->Status; e; e = (struct zx_sp11_Status_s*)e->gg.g.n)
	  p = zx_ENC_SO_sp11_Status(c, e, p);
  }
  {
      struct zx_sa11_Assertion_s* e;
      for (e = x->Assertion; e; e = (struct zx_sa11_Assertion_s*)e->gg.g.n)
	  p = zx_ENC_SO_sa11_Assertion(c, e, p);
  }

  p = zx_enc_so_unknown_elems_and_content(c, p, &x->gg);
  
#if 1 /* NORMALMODE */
  ZX_OUT_CLOSE_TAG(p, "</sp11:Response>");
  zx_pop_seen(pop_seen);
#else
  /* root node has no end tag either */
#endif
  ENC_LEN_DEBUG(x, "sp11:Response", p-enc_base);
  return p;
}

/* FUNC(zx_ENC_WO_sp11_Response) */

/* Render element into string. The XML attributes and elements are
 * processed in wire order by chasing wo pointers. This is what you want for
 * validating signatures on other people's XML documents. */

/* Called by: */
char* zx_ENC_WO_sp11_Response(struct zx_ctx* c, struct zx_sp11_Response_s* x, char* p )
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

  /* *** sort the namespaces */
  if (c->inc_ns)
    zx_add_inc_ns(c, &pop_seen);
  zx_add_xmlns_if_not_seen(c, x->gg.g.ns, &pop_seen);

  p = zx_enc_seen(p, pop_seen); 
  p = zx_attr_wo_enc(p, x->InResponseTo, "InResponseTo=\"", sizeof("InResponseTo=\"")-1);
  p = zx_attr_wo_enc(p, x->IssueInstant, "IssueInstant=\"", sizeof("IssueInstant=\"")-1);
  p = zx_attr_wo_enc(p, x->MajorVersion, "MajorVersion=\"", sizeof("MajorVersion=\"")-1);
  p = zx_attr_wo_enc(p, x->MinorVersion, "MinorVersion=\"", sizeof("MinorVersion=\"")-1);
  p = zx_attr_wo_enc(p, x->Recipient, "Recipient=\"", sizeof("Recipient=\"")-1);
  p = zx_attr_wo_enc(p, x->ResponseID, "ResponseID=\"", sizeof("ResponseID=\"")-1);

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
  ENC_LEN_DEBUG(x, "sp11:Response", p-enc_base);
  return p;
}

/* FUNC(zx_EASY_ENC_SO_sp11_Response) */

/* Called by: */
struct zx_str* zx_EASY_ENC_SO_sp11_Response(struct zx_ctx* c, struct zx_sp11_Response_s* x )
{
  int len;
  char* buf;
  c->ns_tab = ZX_ALLOC(c, sizeof(zx_ns_tab));
  memcpy(c->ns_tab, zx_ns_tab, sizeof(zx_ns_tab));
  len = zx_LEN_SO_sp11_Response(c, x );
  buf = ZX_ALLOC(c, len+1);
  return zx_easy_enc_common(c, zx_ENC_SO_sp11_Response(c, x, buf ), buf, len);
}

/* FUNC(zx_EASY_ENC_WO_sp11_Response) */

/* Called by: */
struct zx_str* zx_EASY_ENC_WO_sp11_Response(struct zx_ctx* c, struct zx_sp11_Response_s* x )
{
  int len;
  char* buf;
  c->ns_tab = ZX_ALLOC(c, sizeof(zx_ns_tab));
  memcpy(c->ns_tab, zx_ns_tab, sizeof(zx_ns_tab));
  len = zx_LEN_WO_sp11_Response(c, x );
  buf = ZX_ALLOC(c, len+1);
  return zx_easy_enc_common(c, zx_ENC_WO_sp11_Response(c, x, buf ), buf, len);
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

#define EL_NAME   sp11_Status
#define EL_STRUCT zx_sp11_Status_s
#define EL_NS     sp11
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

/* FUNC(zx_LEN_SO_sp11_Status) */

/* Compute length of an element (and its subelements). The XML attributes
 * and elements are processed in schema order. */

/* Called by: */
int zx_LEN_SO_sp11_Status(struct zx_ctx* c, struct zx_sp11_Status_s* x )
{
  struct zx_ns_s* pop_seen = 0;
  struct zx_elem_s* se MAYBE_UNUSED;
#if 1 /* NORMALMODE */
  /* *** in simple_elem case should output ns prefix from ns node. */
  int len = sizeof("<sp11:Status")-1 + 1 + sizeof("</sp11:Status>")-1;
  if (c->inc_ns_len)
    len += zx_len_inc_ns(c, &pop_seen);
  len += zx_len_xmlns_if_not_seen(c, zx_ns_tab+zx_xmlns_ix_sp11, &pop_seen);


#else
  /* root node has no begin tag */
  int len = 0;
#endif
  
  {
      struct zx_sp11_StatusCode_s* e;
      for (e = x->StatusCode; e; e = (struct zx_sp11_StatusCode_s*)e->gg.g.n)
	  len += zx_LEN_SO_sp11_StatusCode(c, e);
  }
  for (se = x->StatusMessage; se; se = (struct zx_elem_s*)se->g.n)
    len += zx_LEN_SO_simple_elem(c,se, sizeof("sp11:StatusMessage")-1, zx_ns_tab+zx_xmlns_ix_sp11);
  {
      struct zx_sp11_StatusDetail_s* e;
      for (e = x->StatusDetail; e; e = (struct zx_sp11_StatusDetail_s*)e->gg.g.n)
	  len += zx_LEN_SO_sp11_StatusDetail(c, e);
  }


  len += zx_len_so_common(c, &x->gg);
  zx_pop_seen(pop_seen);
  ENC_LEN_DEBUG(x, "sp11:Status", len);
  return len;
}

/* FUNC(zx_LEN_WO_sp11_Status) */

/* Compute length of an element (and its subelements). The XML attributes
 * and elements are processed in wire order and no assumptions
 * are made about namespace prefixes. */

/* Called by: */
int zx_LEN_WO_sp11_Status(struct zx_ctx* c, struct zx_sp11_Status_s* x )
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
      struct zx_sp11_StatusCode_s* e;
      for (e = x->StatusCode; e; e = (struct zx_sp11_StatusCode_s*)e->gg.g.n)
	  len += zx_LEN_WO_sp11_StatusCode(c, e);
  }
  for (se = x->StatusMessage; se; se = (struct zx_elem_s*)se->g.n)
    len += zx_LEN_WO_simple_elem(c, se, sizeof("StatusMessage")-1);
  {
      struct zx_sp11_StatusDetail_s* e;
      for (e = x->StatusDetail; e; e = (struct zx_sp11_StatusDetail_s*)e->gg.g.n)
	  len += zx_LEN_WO_sp11_StatusDetail(c, e);
  }


  len += zx_len_wo_common(c, &x->gg); 
  zx_pop_seen(pop_seen);
  ENC_LEN_DEBUG(x, "sp11:Status", len);
  return len;
}

/* FUNC(zx_ENC_SO_sp11_Status) */

/* Render element into string. The XML attributes and elements are
 * processed in schema order. This is what you generally want for
 * rendering new data structure to a string. The wo pointers are not used. */

/* Called by: */
char* zx_ENC_SO_sp11_Status(struct zx_ctx* c, struct zx_sp11_Status_s* x, char* p )
{
  struct zx_elem_s* se MAYBE_UNUSED;
  struct zx_ns_s* pop_seen = 0;
  ENC_LEN_DEBUG_BASE;
#if 1 /* NORMALMODE */
  /* *** in simple_elem case should output ns prefix from ns node. */
  ZX_OUT_TAG(p, "<sp11:Status");
  if (c->inc_ns)
    p = zx_enc_inc_ns(c, p, &pop_seen);
  p = zx_enc_xmlns_if_not_seen(c, p, zx_ns_tab+zx_xmlns_ix_sp11, &pop_seen);


  p = zx_enc_unknown_attrs(p, x->gg.any_attr);
#else
  /* root node has no begin tag */
#endif
  
  {
      struct zx_sp11_StatusCode_s* e;
      for (e = x->StatusCode; e; e = (struct zx_sp11_StatusCode_s*)e->gg.g.n)
	  p = zx_ENC_SO_sp11_StatusCode(c, e, p);
  }
  for (se = x->StatusMessage; se; se = (struct zx_elem_s*)se->g.n)
    p = zx_ENC_SO_simple_elem(c, se, p, "sp11:StatusMessage", sizeof("sp11:StatusMessage")-1, zx_ns_tab+zx_xmlns_ix_sp11);
  {
      struct zx_sp11_StatusDetail_s* e;
      for (e = x->StatusDetail; e; e = (struct zx_sp11_StatusDetail_s*)e->gg.g.n)
	  p = zx_ENC_SO_sp11_StatusDetail(c, e, p);
  }

  p = zx_enc_so_unknown_elems_and_content(c, p, &x->gg);
  
#if 1 /* NORMALMODE */
  ZX_OUT_CLOSE_TAG(p, "</sp11:Status>");
  zx_pop_seen(pop_seen);
#else
  /* root node has no end tag either */
#endif
  ENC_LEN_DEBUG(x, "sp11:Status", p-enc_base);
  return p;
}

/* FUNC(zx_ENC_WO_sp11_Status) */

/* Render element into string. The XML attributes and elements are
 * processed in wire order by chasing wo pointers. This is what you want for
 * validating signatures on other people's XML documents. */

/* Called by: */
char* zx_ENC_WO_sp11_Status(struct zx_ctx* c, struct zx_sp11_Status_s* x, char* p )
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
  ENC_LEN_DEBUG(x, "sp11:Status", p-enc_base);
  return p;
}

/* FUNC(zx_EASY_ENC_SO_sp11_Status) */

/* Called by: */
struct zx_str* zx_EASY_ENC_SO_sp11_Status(struct zx_ctx* c, struct zx_sp11_Status_s* x )
{
  int len;
  char* buf;
  c->ns_tab = ZX_ALLOC(c, sizeof(zx_ns_tab));
  memcpy(c->ns_tab, zx_ns_tab, sizeof(zx_ns_tab));
  len = zx_LEN_SO_sp11_Status(c, x );
  buf = ZX_ALLOC(c, len+1);
  return zx_easy_enc_common(c, zx_ENC_SO_sp11_Status(c, x, buf ), buf, len);
}

/* FUNC(zx_EASY_ENC_WO_sp11_Status) */

/* Called by: */
struct zx_str* zx_EASY_ENC_WO_sp11_Status(struct zx_ctx* c, struct zx_sp11_Status_s* x )
{
  int len;
  char* buf;
  c->ns_tab = ZX_ALLOC(c, sizeof(zx_ns_tab));
  memcpy(c->ns_tab, zx_ns_tab, sizeof(zx_ns_tab));
  len = zx_LEN_WO_sp11_Status(c, x );
  buf = ZX_ALLOC(c, len+1);
  return zx_easy_enc_common(c, zx_ENC_WO_sp11_Status(c, x, buf ), buf, len);
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

#define EL_NAME   sp11_StatusCode
#define EL_STRUCT zx_sp11_StatusCode_s
#define EL_NS     sp11
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

/* FUNC(zx_LEN_SO_sp11_StatusCode) */

/* Compute length of an element (and its subelements). The XML attributes
 * and elements are processed in schema order. */

/* Called by: */
int zx_LEN_SO_sp11_StatusCode(struct zx_ctx* c, struct zx_sp11_StatusCode_s* x )
{
  struct zx_ns_s* pop_seen = 0;
  struct zx_elem_s* se MAYBE_UNUSED;
#if 1 /* NORMALMODE */
  /* *** in simple_elem case should output ns prefix from ns node. */
  int len = sizeof("<sp11:StatusCode")-1 + 1 + sizeof("</sp11:StatusCode>")-1;
  if (c->inc_ns_len)
    len += zx_len_inc_ns(c, &pop_seen);
  len += zx_len_xmlns_if_not_seen(c, zx_ns_tab+zx_xmlns_ix_sp11, &pop_seen);

  len += zx_attr_so_len(x->Value, sizeof("Value")-1);

#else
  /* root node has no begin tag */
  int len = 0;
#endif
  
  {
      struct zx_sp11_StatusCode_s* e;
      for (e = x->StatusCode; e; e = (struct zx_sp11_StatusCode_s*)e->gg.g.n)
	  len += zx_LEN_SO_sp11_StatusCode(c, e);
  }


  len += zx_len_so_common(c, &x->gg);
  zx_pop_seen(pop_seen);
  ENC_LEN_DEBUG(x, "sp11:StatusCode", len);
  return len;
}

/* FUNC(zx_LEN_WO_sp11_StatusCode) */

/* Compute length of an element (and its subelements). The XML attributes
 * and elements are processed in wire order and no assumptions
 * are made about namespace prefixes. */

/* Called by: */
int zx_LEN_WO_sp11_StatusCode(struct zx_ctx* c, struct zx_sp11_StatusCode_s* x )
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

  len += zx_attr_wo_len(x->Value, sizeof("Value")-1);

#else
  /* root node has no begin tag */
  int len = 0;
#endif
  
  {
      struct zx_sp11_StatusCode_s* e;
      for (e = x->StatusCode; e; e = (struct zx_sp11_StatusCode_s*)e->gg.g.n)
	  len += zx_LEN_WO_sp11_StatusCode(c, e);
  }


  len += zx_len_wo_common(c, &x->gg); 
  zx_pop_seen(pop_seen);
  ENC_LEN_DEBUG(x, "sp11:StatusCode", len);
  return len;
}

/* FUNC(zx_ENC_SO_sp11_StatusCode) */

/* Render element into string. The XML attributes and elements are
 * processed in schema order. This is what you generally want for
 * rendering new data structure to a string. The wo pointers are not used. */

/* Called by: */
char* zx_ENC_SO_sp11_StatusCode(struct zx_ctx* c, struct zx_sp11_StatusCode_s* x, char* p )
{
  struct zx_elem_s* se MAYBE_UNUSED;
  struct zx_ns_s* pop_seen = 0;
  ENC_LEN_DEBUG_BASE;
#if 1 /* NORMALMODE */
  /* *** in simple_elem case should output ns prefix from ns node. */
  ZX_OUT_TAG(p, "<sp11:StatusCode");
  if (c->inc_ns)
    p = zx_enc_inc_ns(c, p, &pop_seen);
  p = zx_enc_xmlns_if_not_seen(c, p, zx_ns_tab+zx_xmlns_ix_sp11, &pop_seen);

  p = zx_attr_so_enc(p, x->Value, " Value=\"", sizeof(" Value=\"")-1);

  p = zx_enc_unknown_attrs(p, x->gg.any_attr);
#else
  /* root node has no begin tag */
#endif
  
  {
      struct zx_sp11_StatusCode_s* e;
      for (e = x->StatusCode; e; e = (struct zx_sp11_StatusCode_s*)e->gg.g.n)
	  p = zx_ENC_SO_sp11_StatusCode(c, e, p);
  }

  p = zx_enc_so_unknown_elems_and_content(c, p, &x->gg);
  
#if 1 /* NORMALMODE */
  ZX_OUT_CLOSE_TAG(p, "</sp11:StatusCode>");
  zx_pop_seen(pop_seen);
#else
  /* root node has no end tag either */
#endif
  ENC_LEN_DEBUG(x, "sp11:StatusCode", p-enc_base);
  return p;
}

/* FUNC(zx_ENC_WO_sp11_StatusCode) */

/* Render element into string. The XML attributes and elements are
 * processed in wire order by chasing wo pointers. This is what you want for
 * validating signatures on other people's XML documents. */

/* Called by: */
char* zx_ENC_WO_sp11_StatusCode(struct zx_ctx* c, struct zx_sp11_StatusCode_s* x, char* p )
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

  /* *** sort the namespaces */
  if (c->inc_ns)
    zx_add_inc_ns(c, &pop_seen);
  zx_add_xmlns_if_not_seen(c, x->gg.g.ns, &pop_seen);

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
  ENC_LEN_DEBUG(x, "sp11:StatusCode", p-enc_base);
  return p;
}

/* FUNC(zx_EASY_ENC_SO_sp11_StatusCode) */

/* Called by: */
struct zx_str* zx_EASY_ENC_SO_sp11_StatusCode(struct zx_ctx* c, struct zx_sp11_StatusCode_s* x )
{
  int len;
  char* buf;
  c->ns_tab = ZX_ALLOC(c, sizeof(zx_ns_tab));
  memcpy(c->ns_tab, zx_ns_tab, sizeof(zx_ns_tab));
  len = zx_LEN_SO_sp11_StatusCode(c, x );
  buf = ZX_ALLOC(c, len+1);
  return zx_easy_enc_common(c, zx_ENC_SO_sp11_StatusCode(c, x, buf ), buf, len);
}

/* FUNC(zx_EASY_ENC_WO_sp11_StatusCode) */

/* Called by: */
struct zx_str* zx_EASY_ENC_WO_sp11_StatusCode(struct zx_ctx* c, struct zx_sp11_StatusCode_s* x )
{
  int len;
  char* buf;
  c->ns_tab = ZX_ALLOC(c, sizeof(zx_ns_tab));
  memcpy(c->ns_tab, zx_ns_tab, sizeof(zx_ns_tab));
  len = zx_LEN_WO_sp11_StatusCode(c, x );
  buf = ZX_ALLOC(c, len+1);
  return zx_easy_enc_common(c, zx_ENC_WO_sp11_StatusCode(c, x, buf ), buf, len);
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

#define EL_NAME   sp11_StatusDetail
#define EL_STRUCT zx_sp11_StatusDetail_s
#define EL_NS     sp11
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

/* FUNC(zx_LEN_SO_sp11_StatusDetail) */

/* Compute length of an element (and its subelements). The XML attributes
 * and elements are processed in schema order. */

/* Called by: */
int zx_LEN_SO_sp11_StatusDetail(struct zx_ctx* c, struct zx_sp11_StatusDetail_s* x )
{
  struct zx_ns_s* pop_seen = 0;
  struct zx_elem_s* se MAYBE_UNUSED;
#if 1 /* NORMALMODE */
  /* *** in simple_elem case should output ns prefix from ns node. */
  int len = sizeof("<sp11:StatusDetail")-1 + 1 + sizeof("</sp11:StatusDetail>")-1;
  if (c->inc_ns_len)
    len += zx_len_inc_ns(c, &pop_seen);
  len += zx_len_xmlns_if_not_seen(c, zx_ns_tab+zx_xmlns_ix_sp11, &pop_seen);


#else
  /* root node has no begin tag */
  int len = 0;
#endif
  


  len += zx_len_so_common(c, &x->gg);
  zx_pop_seen(pop_seen);
  ENC_LEN_DEBUG(x, "sp11:StatusDetail", len);
  return len;
}

/* FUNC(zx_LEN_WO_sp11_StatusDetail) */

/* Compute length of an element (and its subelements). The XML attributes
 * and elements are processed in wire order and no assumptions
 * are made about namespace prefixes. */

/* Called by: */
int zx_LEN_WO_sp11_StatusDetail(struct zx_ctx* c, struct zx_sp11_StatusDetail_s* x )
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
  


  len += zx_len_wo_common(c, &x->gg); 
  zx_pop_seen(pop_seen);
  ENC_LEN_DEBUG(x, "sp11:StatusDetail", len);
  return len;
}

/* FUNC(zx_ENC_SO_sp11_StatusDetail) */

/* Render element into string. The XML attributes and elements are
 * processed in schema order. This is what you generally want for
 * rendering new data structure to a string. The wo pointers are not used. */

/* Called by: */
char* zx_ENC_SO_sp11_StatusDetail(struct zx_ctx* c, struct zx_sp11_StatusDetail_s* x, char* p )
{
  struct zx_elem_s* se MAYBE_UNUSED;
  struct zx_ns_s* pop_seen = 0;
  ENC_LEN_DEBUG_BASE;
#if 1 /* NORMALMODE */
  /* *** in simple_elem case should output ns prefix from ns node. */
  ZX_OUT_TAG(p, "<sp11:StatusDetail");
  if (c->inc_ns)
    p = zx_enc_inc_ns(c, p, &pop_seen);
  p = zx_enc_xmlns_if_not_seen(c, p, zx_ns_tab+zx_xmlns_ix_sp11, &pop_seen);


  p = zx_enc_unknown_attrs(p, x->gg.any_attr);
#else
  /* root node has no begin tag */
#endif
  

  p = zx_enc_so_unknown_elems_and_content(c, p, &x->gg);
  
#if 1 /* NORMALMODE */
  ZX_OUT_CLOSE_TAG(p, "</sp11:StatusDetail>");
  zx_pop_seen(pop_seen);
#else
  /* root node has no end tag either */
#endif
  ENC_LEN_DEBUG(x, "sp11:StatusDetail", p-enc_base);
  return p;
}

/* FUNC(zx_ENC_WO_sp11_StatusDetail) */

/* Render element into string. The XML attributes and elements are
 * processed in wire order by chasing wo pointers. This is what you want for
 * validating signatures on other people's XML documents. */

/* Called by: */
char* zx_ENC_WO_sp11_StatusDetail(struct zx_ctx* c, struct zx_sp11_StatusDetail_s* x, char* p )
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
  ENC_LEN_DEBUG(x, "sp11:StatusDetail", p-enc_base);
  return p;
}

/* FUNC(zx_EASY_ENC_SO_sp11_StatusDetail) */

/* Called by: */
struct zx_str* zx_EASY_ENC_SO_sp11_StatusDetail(struct zx_ctx* c, struct zx_sp11_StatusDetail_s* x )
{
  int len;
  char* buf;
  c->ns_tab = ZX_ALLOC(c, sizeof(zx_ns_tab));
  memcpy(c->ns_tab, zx_ns_tab, sizeof(zx_ns_tab));
  len = zx_LEN_SO_sp11_StatusDetail(c, x );
  buf = ZX_ALLOC(c, len+1);
  return zx_easy_enc_common(c, zx_ENC_SO_sp11_StatusDetail(c, x, buf ), buf, len);
}

/* FUNC(zx_EASY_ENC_WO_sp11_StatusDetail) */

/* Called by: */
struct zx_str* zx_EASY_ENC_WO_sp11_StatusDetail(struct zx_ctx* c, struct zx_sp11_StatusDetail_s* x )
{
  int len;
  char* buf;
  c->ns_tab = ZX_ALLOC(c, sizeof(zx_ns_tab));
  memcpy(c->ns_tab, zx_ns_tab, sizeof(zx_ns_tab));
  len = zx_LEN_WO_sp11_StatusDetail(c, x );
  buf = ZX_ALLOC(c, len+1);
  return zx_easy_enc_common(c, zx_ENC_WO_sp11_StatusDetail(c, x, buf ), buf, len);
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

#define EL_NAME   sp11_SubjectQuery
#define EL_STRUCT zx_sp11_SubjectQuery_s
#define EL_NS     sp11
#define EL_TAG    SubjectQuery

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

/* FUNC(zx_LEN_SO_sp11_SubjectQuery) */

/* Compute length of an element (and its subelements). The XML attributes
 * and elements are processed in schema order. */

/* Called by: */
int zx_LEN_SO_sp11_SubjectQuery(struct zx_ctx* c, struct zx_sp11_SubjectQuery_s* x )
{
  struct zx_ns_s* pop_seen = 0;
  struct zx_elem_s* se MAYBE_UNUSED;
#if 1 /* NORMALMODE */
  /* *** in simple_elem case should output ns prefix from ns node. */
  int len = sizeof("<sp11:SubjectQuery")-1 + 1 + sizeof("</sp11:SubjectQuery>")-1;
  if (c->inc_ns_len)
    len += zx_len_inc_ns(c, &pop_seen);
  len += zx_len_xmlns_if_not_seen(c, zx_ns_tab+zx_xmlns_ix_sp11, &pop_seen);


#else
  /* root node has no begin tag */
  int len = 0;
#endif
  
  {
      struct zx_sa11_Subject_s* e;
      for (e = x->Subject; e; e = (struct zx_sa11_Subject_s*)e->gg.g.n)
	  len += zx_LEN_SO_sa11_Subject(c, e);
  }


  len += zx_len_so_common(c, &x->gg);
  zx_pop_seen(pop_seen);
  ENC_LEN_DEBUG(x, "sp11:SubjectQuery", len);
  return len;
}

/* FUNC(zx_LEN_WO_sp11_SubjectQuery) */

/* Compute length of an element (and its subelements). The XML attributes
 * and elements are processed in wire order and no assumptions
 * are made about namespace prefixes. */

/* Called by: */
int zx_LEN_WO_sp11_SubjectQuery(struct zx_ctx* c, struct zx_sp11_SubjectQuery_s* x )
{
  struct zx_ns_s* pop_seen = 0;
  struct zx_elem_s* se MAYBE_UNUSED;
#if 1 /* NORMALMODE */
  int len = 1 + sizeof("SubjectQuery")-1 + 1 + 2 + sizeof("SubjectQuery")-1 + 1;
  
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
      struct zx_sa11_Subject_s* e;
      for (e = x->Subject; e; e = (struct zx_sa11_Subject_s*)e->gg.g.n)
	  len += zx_LEN_WO_sa11_Subject(c, e);
  }


  len += zx_len_wo_common(c, &x->gg); 
  zx_pop_seen(pop_seen);
  ENC_LEN_DEBUG(x, "sp11:SubjectQuery", len);
  return len;
}

/* FUNC(zx_ENC_SO_sp11_SubjectQuery) */

/* Render element into string. The XML attributes and elements are
 * processed in schema order. This is what you generally want for
 * rendering new data structure to a string. The wo pointers are not used. */

/* Called by: */
char* zx_ENC_SO_sp11_SubjectQuery(struct zx_ctx* c, struct zx_sp11_SubjectQuery_s* x, char* p )
{
  struct zx_elem_s* se MAYBE_UNUSED;
  struct zx_ns_s* pop_seen = 0;
  ENC_LEN_DEBUG_BASE;
#if 1 /* NORMALMODE */
  /* *** in simple_elem case should output ns prefix from ns node. */
  ZX_OUT_TAG(p, "<sp11:SubjectQuery");
  if (c->inc_ns)
    p = zx_enc_inc_ns(c, p, &pop_seen);
  p = zx_enc_xmlns_if_not_seen(c, p, zx_ns_tab+zx_xmlns_ix_sp11, &pop_seen);


  p = zx_enc_unknown_attrs(p, x->gg.any_attr);
#else
  /* root node has no begin tag */
#endif
  
  {
      struct zx_sa11_Subject_s* e;
      for (e = x->Subject; e; e = (struct zx_sa11_Subject_s*)e->gg.g.n)
	  p = zx_ENC_SO_sa11_Subject(c, e, p);
  }

  p = zx_enc_so_unknown_elems_and_content(c, p, &x->gg);
  
#if 1 /* NORMALMODE */
  ZX_OUT_CLOSE_TAG(p, "</sp11:SubjectQuery>");
  zx_pop_seen(pop_seen);
#else
  /* root node has no end tag either */
#endif
  ENC_LEN_DEBUG(x, "sp11:SubjectQuery", p-enc_base);
  return p;
}

/* FUNC(zx_ENC_WO_sp11_SubjectQuery) */

/* Render element into string. The XML attributes and elements are
 * processed in wire order by chasing wo pointers. This is what you want for
 * validating signatures on other people's XML documents. */

/* Called by: */
char* zx_ENC_WO_sp11_SubjectQuery(struct zx_ctx* c, struct zx_sp11_SubjectQuery_s* x, char* p )
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
  ZX_OUT_MEM(p, "SubjectQuery", sizeof("SubjectQuery")-1);
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
  ENC_LEN_DEBUG(x, "sp11:SubjectQuery", p-enc_base);
  return p;
}

/* FUNC(zx_EASY_ENC_SO_sp11_SubjectQuery) */

/* Called by: */
struct zx_str* zx_EASY_ENC_SO_sp11_SubjectQuery(struct zx_ctx* c, struct zx_sp11_SubjectQuery_s* x )
{
  int len;
  char* buf;
  c->ns_tab = ZX_ALLOC(c, sizeof(zx_ns_tab));
  memcpy(c->ns_tab, zx_ns_tab, sizeof(zx_ns_tab));
  len = zx_LEN_SO_sp11_SubjectQuery(c, x );
  buf = ZX_ALLOC(c, len+1);
  return zx_easy_enc_common(c, zx_ENC_SO_sp11_SubjectQuery(c, x, buf ), buf, len);
}

/* FUNC(zx_EASY_ENC_WO_sp11_SubjectQuery) */

/* Called by: */
struct zx_str* zx_EASY_ENC_WO_sp11_SubjectQuery(struct zx_ctx* c, struct zx_sp11_SubjectQuery_s* x )
{
  int len;
  char* buf;
  c->ns_tab = ZX_ALLOC(c, sizeof(zx_ns_tab));
  memcpy(c->ns_tab, zx_ns_tab, sizeof(zx_ns_tab));
  len = zx_LEN_WO_sp11_SubjectQuery(c, x );
  buf = ZX_ALLOC(c, len+1);
  return zx_easy_enc_common(c, zx_ENC_WO_sp11_SubjectQuery(c, x, buf ), buf, len);
}




/* EOF -- c/zx-sp11-enc.c */
