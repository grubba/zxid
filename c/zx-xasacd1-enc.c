/* c/zx-xasacd1-enc.c - WARNING: This file was automatically generated. DO NOT EDIT!
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
#include "c/zx-xasacd1-data.h"
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

#define EL_NAME   xasacd1_ReferencedPolicies
#define EL_STRUCT zx_xasacd1_ReferencedPolicies_s
#define EL_NS     xasacd1
#define EL_TAG    ReferencedPolicies

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

/* FUNC(zx_LEN_SO_xasacd1_ReferencedPolicies) */

/* Compute length of an element (and its subelements). The XML attributes
 * and elements are processed in schema order. */

/* Called by: */
int zx_LEN_SO_xasacd1_ReferencedPolicies(struct zx_ctx* c, struct zx_xasacd1_ReferencedPolicies_s* x )
{
  struct zx_ns_s* pop_seen = 0;
  struct zx_elem_s* se MAYBE_UNUSED;
#if 1 /* NORMALMODE */
  /* *** in simple_elem case should output ns prefix from ns node. */
  int len = sizeof("<xasacd1:ReferencedPolicies")-1 + 1 + sizeof("</xasacd1:ReferencedPolicies>")-1;
  if (c->inc_ns_len)
    len += zx_len_inc_ns(c, &pop_seen);
  len += zx_len_xmlns_if_not_seen(c, zx_ns_tab+zx_xmlns_ix_xasacd1, &pop_seen);


#else
  /* root node has no begin tag */
  int len = 0;
#endif
  
  {
      struct zx_xa_Policy_s* e;
      for (e = x->Policy; e; e = (struct zx_xa_Policy_s*)e->gg.g.n)
	  len += zx_LEN_SO_xa_Policy(c, e);
  }
  {
      struct zx_xa_PolicySet_s* e;
      for (e = x->PolicySet; e; e = (struct zx_xa_PolicySet_s*)e->gg.g.n)
	  len += zx_LEN_SO_xa_PolicySet(c, e);
  }


  len += zx_len_so_common(c, &x->gg, &pop_seen);
  zx_pop_seen(pop_seen);
  ENC_LEN_DEBUG(x, "xasacd1:ReferencedPolicies", len);
  return len;
}

/* FUNC(zx_LEN_WO_xasacd1_ReferencedPolicies) */

/* Compute length of an element (and its subelements). The XML attributes
 * and elements are processed in wire order and no assumptions
 * are made about namespace prefixes. */

/* Called by: */
int zx_LEN_WO_xasacd1_ReferencedPolicies(struct zx_ctx* c, struct zx_xasacd1_ReferencedPolicies_s* x )
{
  struct zx_ns_s* pop_seen = 0;
  struct zx_elem_s* se MAYBE_UNUSED;
#if 1 /* NORMALMODE */
  int len = 1 + sizeof("ReferencedPolicies")-1 + 1 + 2 + sizeof("ReferencedPolicies")-1 + 1;
  
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
      struct zx_xa_Policy_s* e;
      for (e = x->Policy; e; e = (struct zx_xa_Policy_s*)e->gg.g.n)
	  len += zx_LEN_WO_xa_Policy(c, e);
  }
  {
      struct zx_xa_PolicySet_s* e;
      for (e = x->PolicySet; e; e = (struct zx_xa_PolicySet_s*)e->gg.g.n)
	  len += zx_LEN_WO_xa_PolicySet(c, e);
  }


  len += zx_len_wo_common(c, &x->gg, &pop_seen); 
  zx_pop_seen(pop_seen);
  ENC_LEN_DEBUG(x, "xasacd1:ReferencedPolicies", len);
  return len;
}

/* FUNC(zx_ENC_SO_xasacd1_ReferencedPolicies) */

/* Render element into string. The XML attributes and elements are
 * processed in schema order. This is what you generally want for
 * rendering new data structure to a string. The wo pointers are not used. */

/* Called by: */
char* zx_ENC_SO_xasacd1_ReferencedPolicies(struct zx_ctx* c, struct zx_xasacd1_ReferencedPolicies_s* x, char* p )
{
  struct zx_elem_s* se MAYBE_UNUSED;
  struct zx_ns_s* pop_seen = 0;
  ENC_LEN_DEBUG_BASE;
#if 1 /* NORMALMODE */
  /* *** in simple_elem case should output ns prefix from ns node. */
  ZX_OUT_TAG(p, "<xasacd1:ReferencedPolicies");
  if (c->inc_ns)
    zx_add_inc_ns(c, &pop_seen);
  zx_add_xmlns_if_not_seen(c, zx_ns_tab+zx_xmlns_ix_xasacd1, &pop_seen);

  zx_see_unknown_attrs_ns(c, x->gg.any_attr, &pop_seen);
  p = zx_enc_seen(p, pop_seen); 

  p = zx_enc_unknown_attrs(p, x->gg.any_attr);
#else
  /* root node has no begin tag */
#endif
  
  {
      struct zx_xa_Policy_s* e;
      for (e = x->Policy; e; e = (struct zx_xa_Policy_s*)e->gg.g.n)
	  p = zx_ENC_SO_xa_Policy(c, e, p);
  }
  {
      struct zx_xa_PolicySet_s* e;
      for (e = x->PolicySet; e; e = (struct zx_xa_PolicySet_s*)e->gg.g.n)
	  p = zx_ENC_SO_xa_PolicySet(c, e, p);
  }

  p = zx_enc_so_unknown_elems_and_content(c, p, &x->gg);
  
#if 1 /* NORMALMODE */
  ZX_OUT_CLOSE_TAG(p, "</xasacd1:ReferencedPolicies>");
  zx_pop_seen(pop_seen);
#else
  /* root node has no end tag either */
#endif
  ENC_LEN_DEBUG(x, "xasacd1:ReferencedPolicies", p-enc_base);
  return p;
}

/* FUNC(zx_ENC_WO_xasacd1_ReferencedPolicies) */

/* Render element into string. The XML attributes and elements are
 * processed in wire order by chasing wo pointers. This is what you want for
 * validating signatures on other people's XML documents. */

/* Called by: */
char* zx_ENC_WO_xasacd1_ReferencedPolicies(struct zx_ctx* c, struct zx_xasacd1_ReferencedPolicies_s* x, char* p )
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
  ZX_OUT_MEM(p, "ReferencedPolicies", sizeof("ReferencedPolicies")-1);
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
  ENC_LEN_DEBUG(x, "xasacd1:ReferencedPolicies", p-enc_base);
  return p;
}

/* FUNC(zx_EASY_ENC_SO_xasacd1_ReferencedPolicies) */

/* Called by: */
struct zx_str* zx_EASY_ENC_SO_xasacd1_ReferencedPolicies(struct zx_ctx* c, struct zx_xasacd1_ReferencedPolicies_s* x )
{
  int len;
  char* buf;
  c->ns_tab = ZX_ALLOC(c, sizeof(zx_ns_tab));
  memcpy(c->ns_tab, zx_ns_tab, sizeof(zx_ns_tab));
  len = zx_LEN_SO_xasacd1_ReferencedPolicies(c, x );
  buf = ZX_ALLOC(c, len+1);
  return zx_easy_enc_common(c, zx_ENC_SO_xasacd1_ReferencedPolicies(c, x, buf ), buf, len);
}

/* FUNC(zx_EASY_ENC_WO_xasacd1_ReferencedPolicies) */

/* Called by: */
struct zx_str* zx_EASY_ENC_WO_xasacd1_ReferencedPolicies(struct zx_ctx* c, struct zx_xasacd1_ReferencedPolicies_s* x )
{
  int len;
  char* buf;
  c->ns_tab = ZX_ALLOC(c, sizeof(zx_ns_tab));
  memcpy(c->ns_tab, zx_ns_tab, sizeof(zx_ns_tab));
  len = zx_LEN_WO_xasacd1_ReferencedPolicies(c, x );
  buf = ZX_ALLOC(c, len+1);
  return zx_easy_enc_common(c, zx_ENC_WO_xasacd1_ReferencedPolicies(c, x, buf ), buf, len);
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

#define EL_NAME   xasacd1_XACMLAuthzDecisionStatement
#define EL_STRUCT zx_xasacd1_XACMLAuthzDecisionStatement_s
#define EL_NS     xasacd1
#define EL_TAG    XACMLAuthzDecisionStatement

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

/* FUNC(zx_LEN_SO_xasacd1_XACMLAuthzDecisionStatement) */

/* Compute length of an element (and its subelements). The XML attributes
 * and elements are processed in schema order. */

/* Called by: */
int zx_LEN_SO_xasacd1_XACMLAuthzDecisionStatement(struct zx_ctx* c, struct zx_xasacd1_XACMLAuthzDecisionStatement_s* x )
{
  struct zx_ns_s* pop_seen = 0;
  struct zx_elem_s* se MAYBE_UNUSED;
#if 1 /* NORMALMODE */
  /* *** in simple_elem case should output ns prefix from ns node. */
  int len = sizeof("<xasacd1:XACMLAuthzDecisionStatement")-1 + 1 + sizeof("</xasacd1:XACMLAuthzDecisionStatement>")-1;
  if (c->inc_ns_len)
    len += zx_len_inc_ns(c, &pop_seen);
  len += zx_len_xmlns_if_not_seen(c, zx_ns_tab+zx_xmlns_ix_xasacd1, &pop_seen);


#else
  /* root node has no begin tag */
  int len = 0;
#endif
  
  {
      struct zx_xac_Response_s* e;
      for (e = x->Response; e; e = (struct zx_xac_Response_s*)e->gg.g.n)
	  len += zx_LEN_SO_xac_Response(c, e);
  }
  {
      struct zx_xac_Request_s* e;
      for (e = x->Request; e; e = (struct zx_xac_Request_s*)e->gg.g.n)
	  len += zx_LEN_SO_xac_Request(c, e);
  }


  len += zx_len_so_common(c, &x->gg, &pop_seen);
  zx_pop_seen(pop_seen);
  ENC_LEN_DEBUG(x, "xasacd1:XACMLAuthzDecisionStatement", len);
  return len;
}

/* FUNC(zx_LEN_WO_xasacd1_XACMLAuthzDecisionStatement) */

/* Compute length of an element (and its subelements). The XML attributes
 * and elements are processed in wire order and no assumptions
 * are made about namespace prefixes. */

/* Called by: */
int zx_LEN_WO_xasacd1_XACMLAuthzDecisionStatement(struct zx_ctx* c, struct zx_xasacd1_XACMLAuthzDecisionStatement_s* x )
{
  struct zx_ns_s* pop_seen = 0;
  struct zx_elem_s* se MAYBE_UNUSED;
#if 1 /* NORMALMODE */
  int len = 1 + sizeof("XACMLAuthzDecisionStatement")-1 + 1 + 2 + sizeof("XACMLAuthzDecisionStatement")-1 + 1;
  
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
      struct zx_xac_Response_s* e;
      for (e = x->Response; e; e = (struct zx_xac_Response_s*)e->gg.g.n)
	  len += zx_LEN_WO_xac_Response(c, e);
  }
  {
      struct zx_xac_Request_s* e;
      for (e = x->Request; e; e = (struct zx_xac_Request_s*)e->gg.g.n)
	  len += zx_LEN_WO_xac_Request(c, e);
  }


  len += zx_len_wo_common(c, &x->gg, &pop_seen); 
  zx_pop_seen(pop_seen);
  ENC_LEN_DEBUG(x, "xasacd1:XACMLAuthzDecisionStatement", len);
  return len;
}

/* FUNC(zx_ENC_SO_xasacd1_XACMLAuthzDecisionStatement) */

/* Render element into string. The XML attributes and elements are
 * processed in schema order. This is what you generally want for
 * rendering new data structure to a string. The wo pointers are not used. */

/* Called by: */
char* zx_ENC_SO_xasacd1_XACMLAuthzDecisionStatement(struct zx_ctx* c, struct zx_xasacd1_XACMLAuthzDecisionStatement_s* x, char* p )
{
  struct zx_elem_s* se MAYBE_UNUSED;
  struct zx_ns_s* pop_seen = 0;
  ENC_LEN_DEBUG_BASE;
#if 1 /* NORMALMODE */
  /* *** in simple_elem case should output ns prefix from ns node. */
  ZX_OUT_TAG(p, "<xasacd1:XACMLAuthzDecisionStatement");
  if (c->inc_ns)
    zx_add_inc_ns(c, &pop_seen);
  zx_add_xmlns_if_not_seen(c, zx_ns_tab+zx_xmlns_ix_xasacd1, &pop_seen);

  zx_see_unknown_attrs_ns(c, x->gg.any_attr, &pop_seen);
  p = zx_enc_seen(p, pop_seen); 

  p = zx_enc_unknown_attrs(p, x->gg.any_attr);
#else
  /* root node has no begin tag */
#endif
  
  {
      struct zx_xac_Response_s* e;
      for (e = x->Response; e; e = (struct zx_xac_Response_s*)e->gg.g.n)
	  p = zx_ENC_SO_xac_Response(c, e, p);
  }
  {
      struct zx_xac_Request_s* e;
      for (e = x->Request; e; e = (struct zx_xac_Request_s*)e->gg.g.n)
	  p = zx_ENC_SO_xac_Request(c, e, p);
  }

  p = zx_enc_so_unknown_elems_and_content(c, p, &x->gg);
  
#if 1 /* NORMALMODE */
  ZX_OUT_CLOSE_TAG(p, "</xasacd1:XACMLAuthzDecisionStatement>");
  zx_pop_seen(pop_seen);
#else
  /* root node has no end tag either */
#endif
  ENC_LEN_DEBUG(x, "xasacd1:XACMLAuthzDecisionStatement", p-enc_base);
  return p;
}

/* FUNC(zx_ENC_WO_xasacd1_XACMLAuthzDecisionStatement) */

/* Render element into string. The XML attributes and elements are
 * processed in wire order by chasing wo pointers. This is what you want for
 * validating signatures on other people's XML documents. */

/* Called by: */
char* zx_ENC_WO_xasacd1_XACMLAuthzDecisionStatement(struct zx_ctx* c, struct zx_xasacd1_XACMLAuthzDecisionStatement_s* x, char* p )
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
  ZX_OUT_MEM(p, "XACMLAuthzDecisionStatement", sizeof("XACMLAuthzDecisionStatement")-1);
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
  ENC_LEN_DEBUG(x, "xasacd1:XACMLAuthzDecisionStatement", p-enc_base);
  return p;
}

/* FUNC(zx_EASY_ENC_SO_xasacd1_XACMLAuthzDecisionStatement) */

/* Called by: */
struct zx_str* zx_EASY_ENC_SO_xasacd1_XACMLAuthzDecisionStatement(struct zx_ctx* c, struct zx_xasacd1_XACMLAuthzDecisionStatement_s* x )
{
  int len;
  char* buf;
  c->ns_tab = ZX_ALLOC(c, sizeof(zx_ns_tab));
  memcpy(c->ns_tab, zx_ns_tab, sizeof(zx_ns_tab));
  len = zx_LEN_SO_xasacd1_XACMLAuthzDecisionStatement(c, x );
  buf = ZX_ALLOC(c, len+1);
  return zx_easy_enc_common(c, zx_ENC_SO_xasacd1_XACMLAuthzDecisionStatement(c, x, buf ), buf, len);
}

/* FUNC(zx_EASY_ENC_WO_xasacd1_XACMLAuthzDecisionStatement) */

/* Called by: */
struct zx_str* zx_EASY_ENC_WO_xasacd1_XACMLAuthzDecisionStatement(struct zx_ctx* c, struct zx_xasacd1_XACMLAuthzDecisionStatement_s* x )
{
  int len;
  char* buf;
  c->ns_tab = ZX_ALLOC(c, sizeof(zx_ns_tab));
  memcpy(c->ns_tab, zx_ns_tab, sizeof(zx_ns_tab));
  len = zx_LEN_WO_xasacd1_XACMLAuthzDecisionStatement(c, x );
  buf = ZX_ALLOC(c, len+1);
  return zx_easy_enc_common(c, zx_ENC_WO_xasacd1_XACMLAuthzDecisionStatement(c, x, buf ), buf, len);
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

#define EL_NAME   xasacd1_XACMLPolicyStatement
#define EL_STRUCT zx_xasacd1_XACMLPolicyStatement_s
#define EL_NS     xasacd1
#define EL_TAG    XACMLPolicyStatement

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

/* FUNC(zx_LEN_SO_xasacd1_XACMLPolicyStatement) */

/* Compute length of an element (and its subelements). The XML attributes
 * and elements are processed in schema order. */

/* Called by: */
int zx_LEN_SO_xasacd1_XACMLPolicyStatement(struct zx_ctx* c, struct zx_xasacd1_XACMLPolicyStatement_s* x )
{
  struct zx_ns_s* pop_seen = 0;
  struct zx_elem_s* se MAYBE_UNUSED;
#if 1 /* NORMALMODE */
  /* *** in simple_elem case should output ns prefix from ns node. */
  int len = sizeof("<xasacd1:XACMLPolicyStatement")-1 + 1 + sizeof("</xasacd1:XACMLPolicyStatement>")-1;
  if (c->inc_ns_len)
    len += zx_len_inc_ns(c, &pop_seen);
  len += zx_len_xmlns_if_not_seen(c, zx_ns_tab+zx_xmlns_ix_xasacd1, &pop_seen);


#else
  /* root node has no begin tag */
  int len = 0;
#endif
  
  {
      struct zx_xa_Policy_s* e;
      for (e = x->Policy; e; e = (struct zx_xa_Policy_s*)e->gg.g.n)
	  len += zx_LEN_SO_xa_Policy(c, e);
  }
  {
      struct zx_xa_PolicySet_s* e;
      for (e = x->PolicySet; e; e = (struct zx_xa_PolicySet_s*)e->gg.g.n)
	  len += zx_LEN_SO_xa_PolicySet(c, e);
  }
  {
      struct zx_xasacd1_ReferencedPolicies_s* e;
      for (e = x->ReferencedPolicies; e; e = (struct zx_xasacd1_ReferencedPolicies_s*)e->gg.g.n)
	  len += zx_LEN_SO_xasacd1_ReferencedPolicies(c, e);
  }


  len += zx_len_so_common(c, &x->gg, &pop_seen);
  zx_pop_seen(pop_seen);
  ENC_LEN_DEBUG(x, "xasacd1:XACMLPolicyStatement", len);
  return len;
}

/* FUNC(zx_LEN_WO_xasacd1_XACMLPolicyStatement) */

/* Compute length of an element (and its subelements). The XML attributes
 * and elements are processed in wire order and no assumptions
 * are made about namespace prefixes. */

/* Called by: */
int zx_LEN_WO_xasacd1_XACMLPolicyStatement(struct zx_ctx* c, struct zx_xasacd1_XACMLPolicyStatement_s* x )
{
  struct zx_ns_s* pop_seen = 0;
  struct zx_elem_s* se MAYBE_UNUSED;
#if 1 /* NORMALMODE */
  int len = 1 + sizeof("XACMLPolicyStatement")-1 + 1 + 2 + sizeof("XACMLPolicyStatement")-1 + 1;
  
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
      struct zx_xa_Policy_s* e;
      for (e = x->Policy; e; e = (struct zx_xa_Policy_s*)e->gg.g.n)
	  len += zx_LEN_WO_xa_Policy(c, e);
  }
  {
      struct zx_xa_PolicySet_s* e;
      for (e = x->PolicySet; e; e = (struct zx_xa_PolicySet_s*)e->gg.g.n)
	  len += zx_LEN_WO_xa_PolicySet(c, e);
  }
  {
      struct zx_xasacd1_ReferencedPolicies_s* e;
      for (e = x->ReferencedPolicies; e; e = (struct zx_xasacd1_ReferencedPolicies_s*)e->gg.g.n)
	  len += zx_LEN_WO_xasacd1_ReferencedPolicies(c, e);
  }


  len += zx_len_wo_common(c, &x->gg, &pop_seen); 
  zx_pop_seen(pop_seen);
  ENC_LEN_DEBUG(x, "xasacd1:XACMLPolicyStatement", len);
  return len;
}

/* FUNC(zx_ENC_SO_xasacd1_XACMLPolicyStatement) */

/* Render element into string. The XML attributes and elements are
 * processed in schema order. This is what you generally want for
 * rendering new data structure to a string. The wo pointers are not used. */

/* Called by: */
char* zx_ENC_SO_xasacd1_XACMLPolicyStatement(struct zx_ctx* c, struct zx_xasacd1_XACMLPolicyStatement_s* x, char* p )
{
  struct zx_elem_s* se MAYBE_UNUSED;
  struct zx_ns_s* pop_seen = 0;
  ENC_LEN_DEBUG_BASE;
#if 1 /* NORMALMODE */
  /* *** in simple_elem case should output ns prefix from ns node. */
  ZX_OUT_TAG(p, "<xasacd1:XACMLPolicyStatement");
  if (c->inc_ns)
    zx_add_inc_ns(c, &pop_seen);
  zx_add_xmlns_if_not_seen(c, zx_ns_tab+zx_xmlns_ix_xasacd1, &pop_seen);

  zx_see_unknown_attrs_ns(c, x->gg.any_attr, &pop_seen);
  p = zx_enc_seen(p, pop_seen); 

  p = zx_enc_unknown_attrs(p, x->gg.any_attr);
#else
  /* root node has no begin tag */
#endif
  
  {
      struct zx_xa_Policy_s* e;
      for (e = x->Policy; e; e = (struct zx_xa_Policy_s*)e->gg.g.n)
	  p = zx_ENC_SO_xa_Policy(c, e, p);
  }
  {
      struct zx_xa_PolicySet_s* e;
      for (e = x->PolicySet; e; e = (struct zx_xa_PolicySet_s*)e->gg.g.n)
	  p = zx_ENC_SO_xa_PolicySet(c, e, p);
  }
  {
      struct zx_xasacd1_ReferencedPolicies_s* e;
      for (e = x->ReferencedPolicies; e; e = (struct zx_xasacd1_ReferencedPolicies_s*)e->gg.g.n)
	  p = zx_ENC_SO_xasacd1_ReferencedPolicies(c, e, p);
  }

  p = zx_enc_so_unknown_elems_and_content(c, p, &x->gg);
  
#if 1 /* NORMALMODE */
  ZX_OUT_CLOSE_TAG(p, "</xasacd1:XACMLPolicyStatement>");
  zx_pop_seen(pop_seen);
#else
  /* root node has no end tag either */
#endif
  ENC_LEN_DEBUG(x, "xasacd1:XACMLPolicyStatement", p-enc_base);
  return p;
}

/* FUNC(zx_ENC_WO_xasacd1_XACMLPolicyStatement) */

/* Render element into string. The XML attributes and elements are
 * processed in wire order by chasing wo pointers. This is what you want for
 * validating signatures on other people's XML documents. */

/* Called by: */
char* zx_ENC_WO_xasacd1_XACMLPolicyStatement(struct zx_ctx* c, struct zx_xasacd1_XACMLPolicyStatement_s* x, char* p )
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
  ZX_OUT_MEM(p, "XACMLPolicyStatement", sizeof("XACMLPolicyStatement")-1);
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
  ENC_LEN_DEBUG(x, "xasacd1:XACMLPolicyStatement", p-enc_base);
  return p;
}

/* FUNC(zx_EASY_ENC_SO_xasacd1_XACMLPolicyStatement) */

/* Called by: */
struct zx_str* zx_EASY_ENC_SO_xasacd1_XACMLPolicyStatement(struct zx_ctx* c, struct zx_xasacd1_XACMLPolicyStatement_s* x )
{
  int len;
  char* buf;
  c->ns_tab = ZX_ALLOC(c, sizeof(zx_ns_tab));
  memcpy(c->ns_tab, zx_ns_tab, sizeof(zx_ns_tab));
  len = zx_LEN_SO_xasacd1_XACMLPolicyStatement(c, x );
  buf = ZX_ALLOC(c, len+1);
  return zx_easy_enc_common(c, zx_ENC_SO_xasacd1_XACMLPolicyStatement(c, x, buf ), buf, len);
}

/* FUNC(zx_EASY_ENC_WO_xasacd1_XACMLPolicyStatement) */

/* Called by: */
struct zx_str* zx_EASY_ENC_WO_xasacd1_XACMLPolicyStatement(struct zx_ctx* c, struct zx_xasacd1_XACMLPolicyStatement_s* x )
{
  int len;
  char* buf;
  c->ns_tab = ZX_ALLOC(c, sizeof(zx_ns_tab));
  memcpy(c->ns_tab, zx_ns_tab, sizeof(zx_ns_tab));
  len = zx_LEN_WO_xasacd1_XACMLPolicyStatement(c, x );
  buf = ZX_ALLOC(c, len+1);
  return zx_easy_enc_common(c, zx_ENC_WO_xasacd1_XACMLPolicyStatement(c, x, buf ), buf, len);
}




/* EOF -- c/zx-xasacd1-enc.c */
