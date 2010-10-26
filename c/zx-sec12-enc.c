/* c/zx-sec12-enc.c - WARNING: This file was automatically generated. DO NOT EDIT!
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
#include "c/zx-sec12-data.h"
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

#define EL_NAME   sec12_ProxyInfoConfirmationData
#define EL_STRUCT zx_sec12_ProxyInfoConfirmationData_s
#define EL_NS     sec12
#define EL_TAG    ProxyInfoConfirmationData

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

/* FUNC(zx_LEN_SO_sec12_ProxyInfoConfirmationData) */

/* Compute length of an element (and its subelements). The XML attributes
 * and elements are processed in schema order. */

/* Called by: */
int zx_LEN_SO_sec12_ProxyInfoConfirmationData(struct zx_ctx* c, struct zx_sec12_ProxyInfoConfirmationData_s* x )
{
  struct zx_ns_s* pop_seen = 0;
  struct zx_elem_s* se MAYBE_UNUSED;
#if 1 /* NORMALMODE */
  /* *** in simple_elem case should output ns prefix from ns node. */
  int len = sizeof("<sec12:ProxyInfoConfirmationData")-1 + 1 + sizeof("</sec12:ProxyInfoConfirmationData>")-1;
  if (c->inc_ns_len)
    len += zx_len_inc_ns(c, &pop_seen);
  len += zx_len_xmlns_if_not_seen(c, zx_ns_tab+zx_xmlns_ix_sec12, &pop_seen);

  len += zx_attr_so_len(c, x->id, sizeof("id")-1, &pop_seen);

#else
  /* root node has no begin tag */
  int len = 0;
#endif
  
  for (se = x->AssertionIDReference; se; se = (struct zx_elem_s*)se->g.n)
    len += zx_LEN_SO_simple_elem(c,se, sizeof("sa11:AssertionIDReference")-1, zx_ns_tab+zx_xmlns_ix_sa11);
  for (se = x->Issuer; se; se = (struct zx_elem_s*)se->g.n)
    len += zx_LEN_SO_simple_elem(c,se, sizeof("sec12:Issuer")-1, zx_ns_tab+zx_xmlns_ix_sec12);
  for (se = x->IssueInstant; se; se = (struct zx_elem_s*)se->g.n)
    len += zx_LEN_SO_simple_elem(c,se, sizeof("sec12:IssueInstant")-1, zx_ns_tab+zx_xmlns_ix_sec12);
  {
      struct zx_ds_Signature_s* e;
      for (e = x->Signature; e; e = (struct zx_ds_Signature_s*)e->gg.g.n)
	  if (e != c->exclude_sig)
              len += zx_LEN_SO_ds_Signature(c, e);
  }


  len += zx_len_so_common(c, &x->gg, &pop_seen);
  zx_pop_seen(pop_seen);
  ENC_LEN_DEBUG(x, "sec12:ProxyInfoConfirmationData", len);
  return len;
}

/* FUNC(zx_LEN_WO_sec12_ProxyInfoConfirmationData) */

/* Compute length of an element (and its subelements). The XML attributes
 * and elements are processed in wire order and no assumptions
 * are made about namespace prefixes. */

/* Called by: */
int zx_LEN_WO_sec12_ProxyInfoConfirmationData(struct zx_ctx* c, struct zx_sec12_ProxyInfoConfirmationData_s* x )
{
  struct zx_ns_s* pop_seen = 0;
  struct zx_elem_s* se MAYBE_UNUSED;
#if 1 /* NORMALMODE */
  int len = 1 + sizeof("ProxyInfoConfirmationData")-1 + 1 + 2 + sizeof("ProxyInfoConfirmationData")-1 + 1;
  
  if (x->gg.g.ns && x->gg.g.ns->prefix_len)
    len += (x->gg.g.ns->prefix_len + 1) * 2;
  if (c->inc_ns_len)
    len += zx_len_inc_ns(c, &pop_seen);
  len += zx_len_xmlns_if_not_seen(c, x->gg.g.ns, &pop_seen);

  len += zx_attr_wo_len(c, x->id, sizeof("id")-1, &pop_seen);

#else
  /* root node has no begin tag */
  int len = 0;
#endif
  
  for (se = x->AssertionIDReference; se; se = (struct zx_elem_s*)se->g.n)
    len += zx_LEN_WO_simple_elem(c, se, sizeof("AssertionIDReference")-1);
  for (se = x->Issuer; se; se = (struct zx_elem_s*)se->g.n)
    len += zx_LEN_WO_simple_elem(c, se, sizeof("Issuer")-1);
  for (se = x->IssueInstant; se; se = (struct zx_elem_s*)se->g.n)
    len += zx_LEN_WO_simple_elem(c, se, sizeof("IssueInstant")-1);
  {
      struct zx_ds_Signature_s* e;
      for (e = x->Signature; e; e = (struct zx_ds_Signature_s*)e->gg.g.n)
	  if (e != c->exclude_sig)
              len += zx_LEN_WO_ds_Signature(c, e);
  }


  len += zx_len_wo_common(c, &x->gg, &pop_seen); 
  zx_pop_seen(pop_seen);
  ENC_LEN_DEBUG(x, "sec12:ProxyInfoConfirmationData", len);
  return len;
}

/* FUNC(zx_ENC_SO_sec12_ProxyInfoConfirmationData) */

/* Render element into string. The XML attributes and elements are
 * processed in schema order. This is what you generally want for
 * rendering new data structure to a string. The wo pointers are not used. */

/* Called by: */
char* zx_ENC_SO_sec12_ProxyInfoConfirmationData(struct zx_ctx* c, struct zx_sec12_ProxyInfoConfirmationData_s* x, char* p )
{
  struct zx_elem_s* se MAYBE_UNUSED;
  struct zx_ns_s* pop_seen = 0;
  ENC_LEN_DEBUG_BASE;
#if 1 /* NORMALMODE */
  /* *** in simple_elem case should output ns prefix from ns node. */
  ZX_OUT_TAG(p, "<sec12:ProxyInfoConfirmationData");
  if (c->inc_ns)
    zx_add_inc_ns(c, &pop_seen);
  zx_add_xmlns_if_not_seen(c, zx_ns_tab+zx_xmlns_ix_sec12, &pop_seen);

  zx_see_unknown_attrs_ns(c, x->gg.any_attr, &pop_seen);
  p = zx_enc_seen(p, pop_seen); 
  p = zx_attr_so_enc(p, x->id, " id=\"", sizeof(" id=\"")-1);

  p = zx_enc_unknown_attrs(p, x->gg.any_attr);
#else
  /* root node has no begin tag */
#endif
  
  for (se = x->AssertionIDReference; se; se = (struct zx_elem_s*)se->g.n)
    p = zx_ENC_SO_simple_elem(c, se, p, "sa11:AssertionIDReference", sizeof("sa11:AssertionIDReference")-1, zx_ns_tab+zx_xmlns_ix_sa11);
  for (se = x->Issuer; se; se = (struct zx_elem_s*)se->g.n)
    p = zx_ENC_SO_simple_elem(c, se, p, "sec12:Issuer", sizeof("sec12:Issuer")-1, zx_ns_tab+zx_xmlns_ix_sec12);
  for (se = x->IssueInstant; se; se = (struct zx_elem_s*)se->g.n)
    p = zx_ENC_SO_simple_elem(c, se, p, "sec12:IssueInstant", sizeof("sec12:IssueInstant")-1, zx_ns_tab+zx_xmlns_ix_sec12);
  {
      struct zx_ds_Signature_s* e;
      for (e = x->Signature; e; e = (struct zx_ds_Signature_s*)e->gg.g.n)
	  if (e != c->exclude_sig)
              p = zx_ENC_SO_ds_Signature(c, e, p);
  }

  p = zx_enc_so_unknown_elems_and_content(c, p, &x->gg);
  
#if 1 /* NORMALMODE */
  ZX_OUT_CLOSE_TAG(p, "</sec12:ProxyInfoConfirmationData>");
  zx_pop_seen(pop_seen);
#else
  /* root node has no end tag either */
#endif
  ENC_LEN_DEBUG(x, "sec12:ProxyInfoConfirmationData", p-enc_base);
  return p;
}

/* FUNC(zx_ENC_WO_sec12_ProxyInfoConfirmationData) */

/* Render element into string. The XML attributes and elements are
 * processed in wire order by chasing wo pointers. This is what you want for
 * validating signatures on other people's XML documents. */

/* Called by: */
char* zx_ENC_WO_sec12_ProxyInfoConfirmationData(struct zx_ctx* c, struct zx_sec12_ProxyInfoConfirmationData_s* x, char* p )
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
  ZX_OUT_MEM(p, "ProxyInfoConfirmationData", sizeof("ProxyInfoConfirmationData")-1);
  qq = p;

  if (c->inc_ns)
    zx_add_inc_ns(c, &pop_seen);
  zx_add_xmlns_if_not_seen(c, x->gg.g.ns, &pop_seen);

  zx_see_unknown_attrs_ns(c, x->gg.any_attr, &pop_seen);
  p = zx_enc_seen(p, pop_seen); 
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
  ENC_LEN_DEBUG(x, "sec12:ProxyInfoConfirmationData", p-enc_base);
  return p;
}

/* FUNC(zx_EASY_ENC_SO_sec12_ProxyInfoConfirmationData) */

/* Called by: */
struct zx_str* zx_EASY_ENC_SO_sec12_ProxyInfoConfirmationData(struct zx_ctx* c, struct zx_sec12_ProxyInfoConfirmationData_s* x )
{
  int len;
  char* buf;
  c->ns_tab = ZX_ALLOC(c, sizeof(zx_ns_tab));
  memcpy(c->ns_tab, zx_ns_tab, sizeof(zx_ns_tab));
  len = zx_LEN_SO_sec12_ProxyInfoConfirmationData(c, x );
  buf = ZX_ALLOC(c, len+1);
  return zx_easy_enc_common(c, zx_ENC_SO_sec12_ProxyInfoConfirmationData(c, x, buf ), buf, len);
}

/* FUNC(zx_EASY_ENC_WO_sec12_ProxyInfoConfirmationData) */

/* Called by: */
struct zx_str* zx_EASY_ENC_WO_sec12_ProxyInfoConfirmationData(struct zx_ctx* c, struct zx_sec12_ProxyInfoConfirmationData_s* x )
{
  int len;
  char* buf;
  c->ns_tab = ZX_ALLOC(c, sizeof(zx_ns_tab));
  memcpy(c->ns_tab, zx_ns_tab, sizeof(zx_ns_tab));
  len = zx_LEN_WO_sec12_ProxyInfoConfirmationData(c, x );
  buf = ZX_ALLOC(c, len+1);
  return zx_easy_enc_common(c, zx_ENC_WO_sec12_ProxyInfoConfirmationData(c, x, buf ), buf, len);
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

#define EL_NAME   sec12_ProxySubject
#define EL_STRUCT zx_sec12_ProxySubject_s
#define EL_NS     sec12
#define EL_TAG    ProxySubject

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

/* FUNC(zx_LEN_SO_sec12_ProxySubject) */

/* Compute length of an element (and its subelements). The XML attributes
 * and elements are processed in schema order. */

/* Called by: */
int zx_LEN_SO_sec12_ProxySubject(struct zx_ctx* c, struct zx_sec12_ProxySubject_s* x )
{
  struct zx_ns_s* pop_seen = 0;
  struct zx_elem_s* se MAYBE_UNUSED;
#if 1 /* NORMALMODE */
  /* *** in simple_elem case should output ns prefix from ns node. */
  int len = sizeof("<sec12:ProxySubject")-1 + 1 + sizeof("</sec12:ProxySubject>")-1;
  if (c->inc_ns_len)
    len += zx_len_inc_ns(c, &pop_seen);
  len += zx_len_xmlns_if_not_seen(c, zx_ns_tab+zx_xmlns_ix_sec12, &pop_seen);


#else
  /* root node has no begin tag */
  int len = 0;
#endif
  
  {
      struct zx_sa11_NameIdentifier_s* e;
      for (e = x->NameIdentifier; e; e = (struct zx_sa11_NameIdentifier_s*)e->gg.g.n)
	  len += zx_LEN_SO_sa11_NameIdentifier(c, e);
  }
  {
      struct zx_sa11_SubjectConfirmation_s* e;
      for (e = x->SubjectConfirmation; e; e = (struct zx_sa11_SubjectConfirmation_s*)e->gg.g.n)
	  len += zx_LEN_SO_sa11_SubjectConfirmation(c, e);
  }


  len += zx_len_so_common(c, &x->gg, &pop_seen);
  zx_pop_seen(pop_seen);
  ENC_LEN_DEBUG(x, "sec12:ProxySubject", len);
  return len;
}

/* FUNC(zx_LEN_WO_sec12_ProxySubject) */

/* Compute length of an element (and its subelements). The XML attributes
 * and elements are processed in wire order and no assumptions
 * are made about namespace prefixes. */

/* Called by: */
int zx_LEN_WO_sec12_ProxySubject(struct zx_ctx* c, struct zx_sec12_ProxySubject_s* x )
{
  struct zx_ns_s* pop_seen = 0;
  struct zx_elem_s* se MAYBE_UNUSED;
#if 1 /* NORMALMODE */
  int len = 1 + sizeof("ProxySubject")-1 + 1 + 2 + sizeof("ProxySubject")-1 + 1;
  
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
      struct zx_sa11_NameIdentifier_s* e;
      for (e = x->NameIdentifier; e; e = (struct zx_sa11_NameIdentifier_s*)e->gg.g.n)
	  len += zx_LEN_WO_sa11_NameIdentifier(c, e);
  }
  {
      struct zx_sa11_SubjectConfirmation_s* e;
      for (e = x->SubjectConfirmation; e; e = (struct zx_sa11_SubjectConfirmation_s*)e->gg.g.n)
	  len += zx_LEN_WO_sa11_SubjectConfirmation(c, e);
  }


  len += zx_len_wo_common(c, &x->gg, &pop_seen); 
  zx_pop_seen(pop_seen);
  ENC_LEN_DEBUG(x, "sec12:ProxySubject", len);
  return len;
}

/* FUNC(zx_ENC_SO_sec12_ProxySubject) */

/* Render element into string. The XML attributes and elements are
 * processed in schema order. This is what you generally want for
 * rendering new data structure to a string. The wo pointers are not used. */

/* Called by: */
char* zx_ENC_SO_sec12_ProxySubject(struct zx_ctx* c, struct zx_sec12_ProxySubject_s* x, char* p )
{
  struct zx_elem_s* se MAYBE_UNUSED;
  struct zx_ns_s* pop_seen = 0;
  ENC_LEN_DEBUG_BASE;
#if 1 /* NORMALMODE */
  /* *** in simple_elem case should output ns prefix from ns node. */
  ZX_OUT_TAG(p, "<sec12:ProxySubject");
  if (c->inc_ns)
    zx_add_inc_ns(c, &pop_seen);
  zx_add_xmlns_if_not_seen(c, zx_ns_tab+zx_xmlns_ix_sec12, &pop_seen);

  zx_see_unknown_attrs_ns(c, x->gg.any_attr, &pop_seen);
  p = zx_enc_seen(p, pop_seen); 

  p = zx_enc_unknown_attrs(p, x->gg.any_attr);
#else
  /* root node has no begin tag */
#endif
  
  {
      struct zx_sa11_NameIdentifier_s* e;
      for (e = x->NameIdentifier; e; e = (struct zx_sa11_NameIdentifier_s*)e->gg.g.n)
	  p = zx_ENC_SO_sa11_NameIdentifier(c, e, p);
  }
  {
      struct zx_sa11_SubjectConfirmation_s* e;
      for (e = x->SubjectConfirmation; e; e = (struct zx_sa11_SubjectConfirmation_s*)e->gg.g.n)
	  p = zx_ENC_SO_sa11_SubjectConfirmation(c, e, p);
  }

  p = zx_enc_so_unknown_elems_and_content(c, p, &x->gg);
  
#if 1 /* NORMALMODE */
  ZX_OUT_CLOSE_TAG(p, "</sec12:ProxySubject>");
  zx_pop_seen(pop_seen);
#else
  /* root node has no end tag either */
#endif
  ENC_LEN_DEBUG(x, "sec12:ProxySubject", p-enc_base);
  return p;
}

/* FUNC(zx_ENC_WO_sec12_ProxySubject) */

/* Render element into string. The XML attributes and elements are
 * processed in wire order by chasing wo pointers. This is what you want for
 * validating signatures on other people's XML documents. */

/* Called by: */
char* zx_ENC_WO_sec12_ProxySubject(struct zx_ctx* c, struct zx_sec12_ProxySubject_s* x, char* p )
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
  ZX_OUT_MEM(p, "ProxySubject", sizeof("ProxySubject")-1);
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
  ENC_LEN_DEBUG(x, "sec12:ProxySubject", p-enc_base);
  return p;
}

/* FUNC(zx_EASY_ENC_SO_sec12_ProxySubject) */

/* Called by: */
struct zx_str* zx_EASY_ENC_SO_sec12_ProxySubject(struct zx_ctx* c, struct zx_sec12_ProxySubject_s* x )
{
  int len;
  char* buf;
  c->ns_tab = ZX_ALLOC(c, sizeof(zx_ns_tab));
  memcpy(c->ns_tab, zx_ns_tab, sizeof(zx_ns_tab));
  len = zx_LEN_SO_sec12_ProxySubject(c, x );
  buf = ZX_ALLOC(c, len+1);
  return zx_easy_enc_common(c, zx_ENC_SO_sec12_ProxySubject(c, x, buf ), buf, len);
}

/* FUNC(zx_EASY_ENC_WO_sec12_ProxySubject) */

/* Called by: */
struct zx_str* zx_EASY_ENC_WO_sec12_ProxySubject(struct zx_ctx* c, struct zx_sec12_ProxySubject_s* x )
{
  int len;
  char* buf;
  c->ns_tab = ZX_ALLOC(c, sizeof(zx_ns_tab));
  memcpy(c->ns_tab, zx_ns_tab, sizeof(zx_ns_tab));
  len = zx_LEN_WO_sec12_ProxySubject(c, x );
  buf = ZX_ALLOC(c, len+1);
  return zx_easy_enc_common(c, zx_ENC_WO_sec12_ProxySubject(c, x, buf ), buf, len);
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

#define EL_NAME   sec12_ProxyTransitedStatement
#define EL_STRUCT zx_sec12_ProxyTransitedStatement_s
#define EL_NS     sec12
#define EL_TAG    ProxyTransitedStatement

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

/* FUNC(zx_LEN_SO_sec12_ProxyTransitedStatement) */

/* Compute length of an element (and its subelements). The XML attributes
 * and elements are processed in schema order. */

/* Called by: */
int zx_LEN_SO_sec12_ProxyTransitedStatement(struct zx_ctx* c, struct zx_sec12_ProxyTransitedStatement_s* x )
{
  struct zx_ns_s* pop_seen = 0;
  struct zx_elem_s* se MAYBE_UNUSED;
#if 1 /* NORMALMODE */
  /* *** in simple_elem case should output ns prefix from ns node. */
  int len = sizeof("<sec12:ProxyTransitedStatement")-1 + 1 + sizeof("</sec12:ProxyTransitedStatement>")-1;
  if (c->inc_ns_len)
    len += zx_len_inc_ns(c, &pop_seen);
  len += zx_len_xmlns_if_not_seen(c, zx_ns_tab+zx_xmlns_ix_sec12, &pop_seen);


#else
  /* root node has no begin tag */
  int len = 0;
#endif
  
  {
      struct zx_sa11_Subject_s* e;
      for (e = x->Subject; e; e = (struct zx_sa11_Subject_s*)e->gg.g.n)
	  len += zx_LEN_SO_sa11_Subject(c, e);
  }


  len += zx_len_so_common(c, &x->gg, &pop_seen);
  zx_pop_seen(pop_seen);
  ENC_LEN_DEBUG(x, "sec12:ProxyTransitedStatement", len);
  return len;
}

/* FUNC(zx_LEN_WO_sec12_ProxyTransitedStatement) */

/* Compute length of an element (and its subelements). The XML attributes
 * and elements are processed in wire order and no assumptions
 * are made about namespace prefixes. */

/* Called by: */
int zx_LEN_WO_sec12_ProxyTransitedStatement(struct zx_ctx* c, struct zx_sec12_ProxyTransitedStatement_s* x )
{
  struct zx_ns_s* pop_seen = 0;
  struct zx_elem_s* se MAYBE_UNUSED;
#if 1 /* NORMALMODE */
  int len = 1 + sizeof("ProxyTransitedStatement")-1 + 1 + 2 + sizeof("ProxyTransitedStatement")-1 + 1;
  
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


  len += zx_len_wo_common(c, &x->gg, &pop_seen); 
  zx_pop_seen(pop_seen);
  ENC_LEN_DEBUG(x, "sec12:ProxyTransitedStatement", len);
  return len;
}

/* FUNC(zx_ENC_SO_sec12_ProxyTransitedStatement) */

/* Render element into string. The XML attributes and elements are
 * processed in schema order. This is what you generally want for
 * rendering new data structure to a string. The wo pointers are not used. */

/* Called by: */
char* zx_ENC_SO_sec12_ProxyTransitedStatement(struct zx_ctx* c, struct zx_sec12_ProxyTransitedStatement_s* x, char* p )
{
  struct zx_elem_s* se MAYBE_UNUSED;
  struct zx_ns_s* pop_seen = 0;
  ENC_LEN_DEBUG_BASE;
#if 1 /* NORMALMODE */
  /* *** in simple_elem case should output ns prefix from ns node. */
  ZX_OUT_TAG(p, "<sec12:ProxyTransitedStatement");
  if (c->inc_ns)
    zx_add_inc_ns(c, &pop_seen);
  zx_add_xmlns_if_not_seen(c, zx_ns_tab+zx_xmlns_ix_sec12, &pop_seen);

  zx_see_unknown_attrs_ns(c, x->gg.any_attr, &pop_seen);
  p = zx_enc_seen(p, pop_seen); 

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
  ZX_OUT_CLOSE_TAG(p, "</sec12:ProxyTransitedStatement>");
  zx_pop_seen(pop_seen);
#else
  /* root node has no end tag either */
#endif
  ENC_LEN_DEBUG(x, "sec12:ProxyTransitedStatement", p-enc_base);
  return p;
}

/* FUNC(zx_ENC_WO_sec12_ProxyTransitedStatement) */

/* Render element into string. The XML attributes and elements are
 * processed in wire order by chasing wo pointers. This is what you want for
 * validating signatures on other people's XML documents. */

/* Called by: */
char* zx_ENC_WO_sec12_ProxyTransitedStatement(struct zx_ctx* c, struct zx_sec12_ProxyTransitedStatement_s* x, char* p )
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
  ZX_OUT_MEM(p, "ProxyTransitedStatement", sizeof("ProxyTransitedStatement")-1);
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
  ENC_LEN_DEBUG(x, "sec12:ProxyTransitedStatement", p-enc_base);
  return p;
}

/* FUNC(zx_EASY_ENC_SO_sec12_ProxyTransitedStatement) */

/* Called by: */
struct zx_str* zx_EASY_ENC_SO_sec12_ProxyTransitedStatement(struct zx_ctx* c, struct zx_sec12_ProxyTransitedStatement_s* x )
{
  int len;
  char* buf;
  c->ns_tab = ZX_ALLOC(c, sizeof(zx_ns_tab));
  memcpy(c->ns_tab, zx_ns_tab, sizeof(zx_ns_tab));
  len = zx_LEN_SO_sec12_ProxyTransitedStatement(c, x );
  buf = ZX_ALLOC(c, len+1);
  return zx_easy_enc_common(c, zx_ENC_SO_sec12_ProxyTransitedStatement(c, x, buf ), buf, len);
}

/* FUNC(zx_EASY_ENC_WO_sec12_ProxyTransitedStatement) */

/* Called by: */
struct zx_str* zx_EASY_ENC_WO_sec12_ProxyTransitedStatement(struct zx_ctx* c, struct zx_sec12_ProxyTransitedStatement_s* x )
{
  int len;
  char* buf;
  c->ns_tab = ZX_ALLOC(c, sizeof(zx_ns_tab));
  memcpy(c->ns_tab, zx_ns_tab, sizeof(zx_ns_tab));
  len = zx_LEN_WO_sec12_ProxyTransitedStatement(c, x );
  buf = ZX_ALLOC(c, len+1);
  return zx_easy_enc_common(c, zx_ENC_WO_sec12_ProxyTransitedStatement(c, x, buf ), buf, len);
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

#define EL_NAME   sec12_ResourceAccessStatement
#define EL_STRUCT zx_sec12_ResourceAccessStatement_s
#define EL_NS     sec12
#define EL_TAG    ResourceAccessStatement

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

/* FUNC(zx_LEN_SO_sec12_ResourceAccessStatement) */

/* Compute length of an element (and its subelements). The XML attributes
 * and elements are processed in schema order. */

/* Called by: */
int zx_LEN_SO_sec12_ResourceAccessStatement(struct zx_ctx* c, struct zx_sec12_ResourceAccessStatement_s* x )
{
  struct zx_ns_s* pop_seen = 0;
  struct zx_elem_s* se MAYBE_UNUSED;
#if 1 /* NORMALMODE */
  /* *** in simple_elem case should output ns prefix from ns node. */
  int len = sizeof("<sec12:ResourceAccessStatement")-1 + 1 + sizeof("</sec12:ResourceAccessStatement>")-1;
  if (c->inc_ns_len)
    len += zx_len_inc_ns(c, &pop_seen);
  len += zx_len_xmlns_if_not_seen(c, zx_ns_tab+zx_xmlns_ix_sec12, &pop_seen);


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
      struct zx_di12_ResourceID_s* e;
      for (e = x->ResourceID; e; e = (struct zx_di12_ResourceID_s*)e->gg.g.n)
	  len += zx_LEN_SO_di12_ResourceID(c, e);
  }
  {
      struct zx_di12_EncryptedResourceID_s* e;
      for (e = x->EncryptedResourceID; e; e = (struct zx_di12_EncryptedResourceID_s*)e->gg.g.n)
	  len += zx_LEN_SO_di12_EncryptedResourceID(c, e);
  }
  {
      struct zx_sec12_ProxySubject_s* e;
      for (e = x->ProxySubject; e; e = (struct zx_sec12_ProxySubject_s*)e->gg.g.n)
	  len += zx_LEN_SO_sec12_ProxySubject(c, e);
  }
  {
      struct zx_sec12_SessionContext_s* e;
      for (e = x->SessionContext; e; e = (struct zx_sec12_SessionContext_s*)e->gg.g.n)
	  len += zx_LEN_SO_sec12_SessionContext(c, e);
  }


  len += zx_len_so_common(c, &x->gg, &pop_seen);
  zx_pop_seen(pop_seen);
  ENC_LEN_DEBUG(x, "sec12:ResourceAccessStatement", len);
  return len;
}

/* FUNC(zx_LEN_WO_sec12_ResourceAccessStatement) */

/* Compute length of an element (and its subelements). The XML attributes
 * and elements are processed in wire order and no assumptions
 * are made about namespace prefixes. */

/* Called by: */
int zx_LEN_WO_sec12_ResourceAccessStatement(struct zx_ctx* c, struct zx_sec12_ResourceAccessStatement_s* x )
{
  struct zx_ns_s* pop_seen = 0;
  struct zx_elem_s* se MAYBE_UNUSED;
#if 1 /* NORMALMODE */
  int len = 1 + sizeof("ResourceAccessStatement")-1 + 1 + 2 + sizeof("ResourceAccessStatement")-1 + 1;
  
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
  {
      struct zx_di12_ResourceID_s* e;
      for (e = x->ResourceID; e; e = (struct zx_di12_ResourceID_s*)e->gg.g.n)
	  len += zx_LEN_WO_di12_ResourceID(c, e);
  }
  {
      struct zx_di12_EncryptedResourceID_s* e;
      for (e = x->EncryptedResourceID; e; e = (struct zx_di12_EncryptedResourceID_s*)e->gg.g.n)
	  len += zx_LEN_WO_di12_EncryptedResourceID(c, e);
  }
  {
      struct zx_sec12_ProxySubject_s* e;
      for (e = x->ProxySubject; e; e = (struct zx_sec12_ProxySubject_s*)e->gg.g.n)
	  len += zx_LEN_WO_sec12_ProxySubject(c, e);
  }
  {
      struct zx_sec12_SessionContext_s* e;
      for (e = x->SessionContext; e; e = (struct zx_sec12_SessionContext_s*)e->gg.g.n)
	  len += zx_LEN_WO_sec12_SessionContext(c, e);
  }


  len += zx_len_wo_common(c, &x->gg, &pop_seen); 
  zx_pop_seen(pop_seen);
  ENC_LEN_DEBUG(x, "sec12:ResourceAccessStatement", len);
  return len;
}

/* FUNC(zx_ENC_SO_sec12_ResourceAccessStatement) */

/* Render element into string. The XML attributes and elements are
 * processed in schema order. This is what you generally want for
 * rendering new data structure to a string. The wo pointers are not used. */

/* Called by: */
char* zx_ENC_SO_sec12_ResourceAccessStatement(struct zx_ctx* c, struct zx_sec12_ResourceAccessStatement_s* x, char* p )
{
  struct zx_elem_s* se MAYBE_UNUSED;
  struct zx_ns_s* pop_seen = 0;
  ENC_LEN_DEBUG_BASE;
#if 1 /* NORMALMODE */
  /* *** in simple_elem case should output ns prefix from ns node. */
  ZX_OUT_TAG(p, "<sec12:ResourceAccessStatement");
  if (c->inc_ns)
    zx_add_inc_ns(c, &pop_seen);
  zx_add_xmlns_if_not_seen(c, zx_ns_tab+zx_xmlns_ix_sec12, &pop_seen);

  zx_see_unknown_attrs_ns(c, x->gg.any_attr, &pop_seen);
  p = zx_enc_seen(p, pop_seen); 

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
      struct zx_di12_ResourceID_s* e;
      for (e = x->ResourceID; e; e = (struct zx_di12_ResourceID_s*)e->gg.g.n)
	  p = zx_ENC_SO_di12_ResourceID(c, e, p);
  }
  {
      struct zx_di12_EncryptedResourceID_s* e;
      for (e = x->EncryptedResourceID; e; e = (struct zx_di12_EncryptedResourceID_s*)e->gg.g.n)
	  p = zx_ENC_SO_di12_EncryptedResourceID(c, e, p);
  }
  {
      struct zx_sec12_ProxySubject_s* e;
      for (e = x->ProxySubject; e; e = (struct zx_sec12_ProxySubject_s*)e->gg.g.n)
	  p = zx_ENC_SO_sec12_ProxySubject(c, e, p);
  }
  {
      struct zx_sec12_SessionContext_s* e;
      for (e = x->SessionContext; e; e = (struct zx_sec12_SessionContext_s*)e->gg.g.n)
	  p = zx_ENC_SO_sec12_SessionContext(c, e, p);
  }

  p = zx_enc_so_unknown_elems_and_content(c, p, &x->gg);
  
#if 1 /* NORMALMODE */
  ZX_OUT_CLOSE_TAG(p, "</sec12:ResourceAccessStatement>");
  zx_pop_seen(pop_seen);
#else
  /* root node has no end tag either */
#endif
  ENC_LEN_DEBUG(x, "sec12:ResourceAccessStatement", p-enc_base);
  return p;
}

/* FUNC(zx_ENC_WO_sec12_ResourceAccessStatement) */

/* Render element into string. The XML attributes and elements are
 * processed in wire order by chasing wo pointers. This is what you want for
 * validating signatures on other people's XML documents. */

/* Called by: */
char* zx_ENC_WO_sec12_ResourceAccessStatement(struct zx_ctx* c, struct zx_sec12_ResourceAccessStatement_s* x, char* p )
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
  ZX_OUT_MEM(p, "ResourceAccessStatement", sizeof("ResourceAccessStatement")-1);
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
  ENC_LEN_DEBUG(x, "sec12:ResourceAccessStatement", p-enc_base);
  return p;
}

/* FUNC(zx_EASY_ENC_SO_sec12_ResourceAccessStatement) */

/* Called by: */
struct zx_str* zx_EASY_ENC_SO_sec12_ResourceAccessStatement(struct zx_ctx* c, struct zx_sec12_ResourceAccessStatement_s* x )
{
  int len;
  char* buf;
  c->ns_tab = ZX_ALLOC(c, sizeof(zx_ns_tab));
  memcpy(c->ns_tab, zx_ns_tab, sizeof(zx_ns_tab));
  len = zx_LEN_SO_sec12_ResourceAccessStatement(c, x );
  buf = ZX_ALLOC(c, len+1);
  return zx_easy_enc_common(c, zx_ENC_SO_sec12_ResourceAccessStatement(c, x, buf ), buf, len);
}

/* FUNC(zx_EASY_ENC_WO_sec12_ResourceAccessStatement) */

/* Called by: */
struct zx_str* zx_EASY_ENC_WO_sec12_ResourceAccessStatement(struct zx_ctx* c, struct zx_sec12_ResourceAccessStatement_s* x )
{
  int len;
  char* buf;
  c->ns_tab = ZX_ALLOC(c, sizeof(zx_ns_tab));
  memcpy(c->ns_tab, zx_ns_tab, sizeof(zx_ns_tab));
  len = zx_LEN_WO_sec12_ResourceAccessStatement(c, x );
  buf = ZX_ALLOC(c, len+1);
  return zx_easy_enc_common(c, zx_ENC_WO_sec12_ResourceAccessStatement(c, x, buf ), buf, len);
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

#define EL_NAME   sec12_SessionContext
#define EL_STRUCT zx_sec12_SessionContext_s
#define EL_NS     sec12
#define EL_TAG    SessionContext

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

/* FUNC(zx_LEN_SO_sec12_SessionContext) */

/* Compute length of an element (and its subelements). The XML attributes
 * and elements are processed in schema order. */

/* Called by: */
int zx_LEN_SO_sec12_SessionContext(struct zx_ctx* c, struct zx_sec12_SessionContext_s* x )
{
  struct zx_ns_s* pop_seen = 0;
  struct zx_elem_s* se MAYBE_UNUSED;
#if 1 /* NORMALMODE */
  /* *** in simple_elem case should output ns prefix from ns node. */
  int len = sizeof("<sec12:SessionContext")-1 + 1 + sizeof("</sec12:SessionContext>")-1;
  if (c->inc_ns_len)
    len += zx_len_inc_ns(c, &pop_seen);
  len += zx_len_xmlns_if_not_seen(c, zx_ns_tab+zx_xmlns_ix_sec12, &pop_seen);

  len += zx_attr_so_len(c, x->AssertionIssueInstant, sizeof("AssertionIssueInstant")-1, &pop_seen);
  len += zx_attr_so_len(c, x->AuthenticationInstant, sizeof("AuthenticationInstant")-1, &pop_seen);
  len += zx_attr_so_len(c, x->SessionIndex, sizeof("SessionIndex")-1, &pop_seen);

#else
  /* root node has no begin tag */
  int len = 0;
#endif
  
  {
      struct zx_sec12_SessionSubject_s* e;
      for (e = x->SessionSubject; e; e = (struct zx_sec12_SessionSubject_s*)e->gg.g.n)
	  len += zx_LEN_SO_sec12_SessionSubject(c, e);
  }
  for (se = x->ProviderID; se; se = (struct zx_elem_s*)se->g.n)
    len += zx_LEN_SO_simple_elem(c,se, sizeof("sec12:ProviderID")-1, zx_ns_tab+zx_xmlns_ix_sec12);
  {
      struct zx_ff12_RequestAuthnContext_s* e;
      for (e = x->RequestAuthnContext; e; e = (struct zx_ff12_RequestAuthnContext_s*)e->gg.g.n)
	  len += zx_LEN_SO_ff12_RequestAuthnContext(c, e);
  }


  len += zx_len_so_common(c, &x->gg, &pop_seen);
  zx_pop_seen(pop_seen);
  ENC_LEN_DEBUG(x, "sec12:SessionContext", len);
  return len;
}

/* FUNC(zx_LEN_WO_sec12_SessionContext) */

/* Compute length of an element (and its subelements). The XML attributes
 * and elements are processed in wire order and no assumptions
 * are made about namespace prefixes. */

/* Called by: */
int zx_LEN_WO_sec12_SessionContext(struct zx_ctx* c, struct zx_sec12_SessionContext_s* x )
{
  struct zx_ns_s* pop_seen = 0;
  struct zx_elem_s* se MAYBE_UNUSED;
#if 1 /* NORMALMODE */
  int len = 1 + sizeof("SessionContext")-1 + 1 + 2 + sizeof("SessionContext")-1 + 1;
  
  if (x->gg.g.ns && x->gg.g.ns->prefix_len)
    len += (x->gg.g.ns->prefix_len + 1) * 2;
  if (c->inc_ns_len)
    len += zx_len_inc_ns(c, &pop_seen);
  len += zx_len_xmlns_if_not_seen(c, x->gg.g.ns, &pop_seen);

  len += zx_attr_wo_len(c, x->AssertionIssueInstant, sizeof("AssertionIssueInstant")-1, &pop_seen);
  len += zx_attr_wo_len(c, x->AuthenticationInstant, sizeof("AuthenticationInstant")-1, &pop_seen);
  len += zx_attr_wo_len(c, x->SessionIndex, sizeof("SessionIndex")-1, &pop_seen);

#else
  /* root node has no begin tag */
  int len = 0;
#endif
  
  {
      struct zx_sec12_SessionSubject_s* e;
      for (e = x->SessionSubject; e; e = (struct zx_sec12_SessionSubject_s*)e->gg.g.n)
	  len += zx_LEN_WO_sec12_SessionSubject(c, e);
  }
  for (se = x->ProviderID; se; se = (struct zx_elem_s*)se->g.n)
    len += zx_LEN_WO_simple_elem(c, se, sizeof("ProviderID")-1);
  {
      struct zx_ff12_RequestAuthnContext_s* e;
      for (e = x->RequestAuthnContext; e; e = (struct zx_ff12_RequestAuthnContext_s*)e->gg.g.n)
	  len += zx_LEN_WO_ff12_RequestAuthnContext(c, e);
  }


  len += zx_len_wo_common(c, &x->gg, &pop_seen); 
  zx_pop_seen(pop_seen);
  ENC_LEN_DEBUG(x, "sec12:SessionContext", len);
  return len;
}

/* FUNC(zx_ENC_SO_sec12_SessionContext) */

/* Render element into string. The XML attributes and elements are
 * processed in schema order. This is what you generally want for
 * rendering new data structure to a string. The wo pointers are not used. */

/* Called by: */
char* zx_ENC_SO_sec12_SessionContext(struct zx_ctx* c, struct zx_sec12_SessionContext_s* x, char* p )
{
  struct zx_elem_s* se MAYBE_UNUSED;
  struct zx_ns_s* pop_seen = 0;
  ENC_LEN_DEBUG_BASE;
#if 1 /* NORMALMODE */
  /* *** in simple_elem case should output ns prefix from ns node. */
  ZX_OUT_TAG(p, "<sec12:SessionContext");
  if (c->inc_ns)
    zx_add_inc_ns(c, &pop_seen);
  zx_add_xmlns_if_not_seen(c, zx_ns_tab+zx_xmlns_ix_sec12, &pop_seen);

  zx_see_unknown_attrs_ns(c, x->gg.any_attr, &pop_seen);
  p = zx_enc_seen(p, pop_seen); 
  p = zx_attr_so_enc(p, x->AssertionIssueInstant, " AssertionIssueInstant=\"", sizeof(" AssertionIssueInstant=\"")-1);
  p = zx_attr_so_enc(p, x->AuthenticationInstant, " AuthenticationInstant=\"", sizeof(" AuthenticationInstant=\"")-1);
  p = zx_attr_so_enc(p, x->SessionIndex, " SessionIndex=\"", sizeof(" SessionIndex=\"")-1);

  p = zx_enc_unknown_attrs(p, x->gg.any_attr);
#else
  /* root node has no begin tag */
#endif
  
  {
      struct zx_sec12_SessionSubject_s* e;
      for (e = x->SessionSubject; e; e = (struct zx_sec12_SessionSubject_s*)e->gg.g.n)
	  p = zx_ENC_SO_sec12_SessionSubject(c, e, p);
  }
  for (se = x->ProviderID; se; se = (struct zx_elem_s*)se->g.n)
    p = zx_ENC_SO_simple_elem(c, se, p, "sec12:ProviderID", sizeof("sec12:ProviderID")-1, zx_ns_tab+zx_xmlns_ix_sec12);
  {
      struct zx_ff12_RequestAuthnContext_s* e;
      for (e = x->RequestAuthnContext; e; e = (struct zx_ff12_RequestAuthnContext_s*)e->gg.g.n)
	  p = zx_ENC_SO_ff12_RequestAuthnContext(c, e, p);
  }

  p = zx_enc_so_unknown_elems_and_content(c, p, &x->gg);
  
#if 1 /* NORMALMODE */
  ZX_OUT_CLOSE_TAG(p, "</sec12:SessionContext>");
  zx_pop_seen(pop_seen);
#else
  /* root node has no end tag either */
#endif
  ENC_LEN_DEBUG(x, "sec12:SessionContext", p-enc_base);
  return p;
}

/* FUNC(zx_ENC_WO_sec12_SessionContext) */

/* Render element into string. The XML attributes and elements are
 * processed in wire order by chasing wo pointers. This is what you want for
 * validating signatures on other people's XML documents. */

/* Called by: */
char* zx_ENC_WO_sec12_SessionContext(struct zx_ctx* c, struct zx_sec12_SessionContext_s* x, char* p )
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
  ZX_OUT_MEM(p, "SessionContext", sizeof("SessionContext")-1);
  qq = p;

  if (c->inc_ns)
    zx_add_inc_ns(c, &pop_seen);
  zx_add_xmlns_if_not_seen(c, x->gg.g.ns, &pop_seen);

  zx_see_unknown_attrs_ns(c, x->gg.any_attr, &pop_seen);
  p = zx_enc_seen(p, pop_seen); 
  p = zx_attr_wo_enc(p, x->AssertionIssueInstant, "AssertionIssueInstant=\"", sizeof("AssertionIssueInstant=\"")-1);
  p = zx_attr_wo_enc(p, x->AuthenticationInstant, "AuthenticationInstant=\"", sizeof("AuthenticationInstant=\"")-1);
  p = zx_attr_wo_enc(p, x->SessionIndex, "SessionIndex=\"", sizeof("SessionIndex=\"")-1);

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
  ENC_LEN_DEBUG(x, "sec12:SessionContext", p-enc_base);
  return p;
}

/* FUNC(zx_EASY_ENC_SO_sec12_SessionContext) */

/* Called by: */
struct zx_str* zx_EASY_ENC_SO_sec12_SessionContext(struct zx_ctx* c, struct zx_sec12_SessionContext_s* x )
{
  int len;
  char* buf;
  c->ns_tab = ZX_ALLOC(c, sizeof(zx_ns_tab));
  memcpy(c->ns_tab, zx_ns_tab, sizeof(zx_ns_tab));
  len = zx_LEN_SO_sec12_SessionContext(c, x );
  buf = ZX_ALLOC(c, len+1);
  return zx_easy_enc_common(c, zx_ENC_SO_sec12_SessionContext(c, x, buf ), buf, len);
}

/* FUNC(zx_EASY_ENC_WO_sec12_SessionContext) */

/* Called by: */
struct zx_str* zx_EASY_ENC_WO_sec12_SessionContext(struct zx_ctx* c, struct zx_sec12_SessionContext_s* x )
{
  int len;
  char* buf;
  c->ns_tab = ZX_ALLOC(c, sizeof(zx_ns_tab));
  memcpy(c->ns_tab, zx_ns_tab, sizeof(zx_ns_tab));
  len = zx_LEN_WO_sec12_SessionContext(c, x );
  buf = ZX_ALLOC(c, len+1);
  return zx_easy_enc_common(c, zx_ENC_WO_sec12_SessionContext(c, x, buf ), buf, len);
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

#define EL_NAME   sec12_SessionContextStatement
#define EL_STRUCT zx_sec12_SessionContextStatement_s
#define EL_NS     sec12
#define EL_TAG    SessionContextStatement

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

/* FUNC(zx_LEN_SO_sec12_SessionContextStatement) */

/* Compute length of an element (and its subelements). The XML attributes
 * and elements are processed in schema order. */

/* Called by: */
int zx_LEN_SO_sec12_SessionContextStatement(struct zx_ctx* c, struct zx_sec12_SessionContextStatement_s* x )
{
  struct zx_ns_s* pop_seen = 0;
  struct zx_elem_s* se MAYBE_UNUSED;
#if 1 /* NORMALMODE */
  /* *** in simple_elem case should output ns prefix from ns node. */
  int len = sizeof("<sec12:SessionContextStatement")-1 + 1 + sizeof("</sec12:SessionContextStatement>")-1;
  if (c->inc_ns_len)
    len += zx_len_inc_ns(c, &pop_seen);
  len += zx_len_xmlns_if_not_seen(c, zx_ns_tab+zx_xmlns_ix_sec12, &pop_seen);


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
      struct zx_sec12_ProxySubject_s* e;
      for (e = x->ProxySubject; e; e = (struct zx_sec12_ProxySubject_s*)e->gg.g.n)
	  len += zx_LEN_SO_sec12_ProxySubject(c, e);
  }
  {
      struct zx_sec12_SessionContext_s* e;
      for (e = x->SessionContext; e; e = (struct zx_sec12_SessionContext_s*)e->gg.g.n)
	  len += zx_LEN_SO_sec12_SessionContext(c, e);
  }


  len += zx_len_so_common(c, &x->gg, &pop_seen);
  zx_pop_seen(pop_seen);
  ENC_LEN_DEBUG(x, "sec12:SessionContextStatement", len);
  return len;
}

/* FUNC(zx_LEN_WO_sec12_SessionContextStatement) */

/* Compute length of an element (and its subelements). The XML attributes
 * and elements are processed in wire order and no assumptions
 * are made about namespace prefixes. */

/* Called by: */
int zx_LEN_WO_sec12_SessionContextStatement(struct zx_ctx* c, struct zx_sec12_SessionContextStatement_s* x )
{
  struct zx_ns_s* pop_seen = 0;
  struct zx_elem_s* se MAYBE_UNUSED;
#if 1 /* NORMALMODE */
  int len = 1 + sizeof("SessionContextStatement")-1 + 1 + 2 + sizeof("SessionContextStatement")-1 + 1;
  
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
  {
      struct zx_sec12_ProxySubject_s* e;
      for (e = x->ProxySubject; e; e = (struct zx_sec12_ProxySubject_s*)e->gg.g.n)
	  len += zx_LEN_WO_sec12_ProxySubject(c, e);
  }
  {
      struct zx_sec12_SessionContext_s* e;
      for (e = x->SessionContext; e; e = (struct zx_sec12_SessionContext_s*)e->gg.g.n)
	  len += zx_LEN_WO_sec12_SessionContext(c, e);
  }


  len += zx_len_wo_common(c, &x->gg, &pop_seen); 
  zx_pop_seen(pop_seen);
  ENC_LEN_DEBUG(x, "sec12:SessionContextStatement", len);
  return len;
}

/* FUNC(zx_ENC_SO_sec12_SessionContextStatement) */

/* Render element into string. The XML attributes and elements are
 * processed in schema order. This is what you generally want for
 * rendering new data structure to a string. The wo pointers are not used. */

/* Called by: */
char* zx_ENC_SO_sec12_SessionContextStatement(struct zx_ctx* c, struct zx_sec12_SessionContextStatement_s* x, char* p )
{
  struct zx_elem_s* se MAYBE_UNUSED;
  struct zx_ns_s* pop_seen = 0;
  ENC_LEN_DEBUG_BASE;
#if 1 /* NORMALMODE */
  /* *** in simple_elem case should output ns prefix from ns node. */
  ZX_OUT_TAG(p, "<sec12:SessionContextStatement");
  if (c->inc_ns)
    zx_add_inc_ns(c, &pop_seen);
  zx_add_xmlns_if_not_seen(c, zx_ns_tab+zx_xmlns_ix_sec12, &pop_seen);

  zx_see_unknown_attrs_ns(c, x->gg.any_attr, &pop_seen);
  p = zx_enc_seen(p, pop_seen); 

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
      struct zx_sec12_ProxySubject_s* e;
      for (e = x->ProxySubject; e; e = (struct zx_sec12_ProxySubject_s*)e->gg.g.n)
	  p = zx_ENC_SO_sec12_ProxySubject(c, e, p);
  }
  {
      struct zx_sec12_SessionContext_s* e;
      for (e = x->SessionContext; e; e = (struct zx_sec12_SessionContext_s*)e->gg.g.n)
	  p = zx_ENC_SO_sec12_SessionContext(c, e, p);
  }

  p = zx_enc_so_unknown_elems_and_content(c, p, &x->gg);
  
#if 1 /* NORMALMODE */
  ZX_OUT_CLOSE_TAG(p, "</sec12:SessionContextStatement>");
  zx_pop_seen(pop_seen);
#else
  /* root node has no end tag either */
#endif
  ENC_LEN_DEBUG(x, "sec12:SessionContextStatement", p-enc_base);
  return p;
}

/* FUNC(zx_ENC_WO_sec12_SessionContextStatement) */

/* Render element into string. The XML attributes and elements are
 * processed in wire order by chasing wo pointers. This is what you want for
 * validating signatures on other people's XML documents. */

/* Called by: */
char* zx_ENC_WO_sec12_SessionContextStatement(struct zx_ctx* c, struct zx_sec12_SessionContextStatement_s* x, char* p )
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
  ZX_OUT_MEM(p, "SessionContextStatement", sizeof("SessionContextStatement")-1);
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
  ENC_LEN_DEBUG(x, "sec12:SessionContextStatement", p-enc_base);
  return p;
}

/* FUNC(zx_EASY_ENC_SO_sec12_SessionContextStatement) */

/* Called by: */
struct zx_str* zx_EASY_ENC_SO_sec12_SessionContextStatement(struct zx_ctx* c, struct zx_sec12_SessionContextStatement_s* x )
{
  int len;
  char* buf;
  c->ns_tab = ZX_ALLOC(c, sizeof(zx_ns_tab));
  memcpy(c->ns_tab, zx_ns_tab, sizeof(zx_ns_tab));
  len = zx_LEN_SO_sec12_SessionContextStatement(c, x );
  buf = ZX_ALLOC(c, len+1);
  return zx_easy_enc_common(c, zx_ENC_SO_sec12_SessionContextStatement(c, x, buf ), buf, len);
}

/* FUNC(zx_EASY_ENC_WO_sec12_SessionContextStatement) */

/* Called by: */
struct zx_str* zx_EASY_ENC_WO_sec12_SessionContextStatement(struct zx_ctx* c, struct zx_sec12_SessionContextStatement_s* x )
{
  int len;
  char* buf;
  c->ns_tab = ZX_ALLOC(c, sizeof(zx_ns_tab));
  memcpy(c->ns_tab, zx_ns_tab, sizeof(zx_ns_tab));
  len = zx_LEN_WO_sec12_SessionContextStatement(c, x );
  buf = ZX_ALLOC(c, len+1);
  return zx_easy_enc_common(c, zx_ENC_WO_sec12_SessionContextStatement(c, x, buf ), buf, len);
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

#define EL_NAME   sec12_SessionSubject
#define EL_STRUCT zx_sec12_SessionSubject_s
#define EL_NS     sec12
#define EL_TAG    SessionSubject

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

/* FUNC(zx_LEN_SO_sec12_SessionSubject) */

/* Compute length of an element (and its subelements). The XML attributes
 * and elements are processed in schema order. */

/* Called by: */
int zx_LEN_SO_sec12_SessionSubject(struct zx_ctx* c, struct zx_sec12_SessionSubject_s* x )
{
  struct zx_ns_s* pop_seen = 0;
  struct zx_elem_s* se MAYBE_UNUSED;
#if 1 /* NORMALMODE */
  /* *** in simple_elem case should output ns prefix from ns node. */
  int len = sizeof("<sec12:SessionSubject")-1 + 1 + sizeof("</sec12:SessionSubject>")-1;
  if (c->inc_ns_len)
    len += zx_len_inc_ns(c, &pop_seen);
  len += zx_len_xmlns_if_not_seen(c, zx_ns_tab+zx_xmlns_ix_sec12, &pop_seen);


#else
  /* root node has no begin tag */
  int len = 0;
#endif
  
  {
      struct zx_sa11_NameIdentifier_s* e;
      for (e = x->NameIdentifier; e; e = (struct zx_sa11_NameIdentifier_s*)e->gg.g.n)
	  len += zx_LEN_SO_sa11_NameIdentifier(c, e);
  }
  {
      struct zx_sa11_SubjectConfirmation_s* e;
      for (e = x->SubjectConfirmation; e; e = (struct zx_sa11_SubjectConfirmation_s*)e->gg.g.n)
	  len += zx_LEN_SO_sa11_SubjectConfirmation(c, e);
  }
  {
      struct zx_ff12_IDPProvidedNameIdentifier_s* e;
      for (e = x->IDPProvidedNameIdentifier; e; e = (struct zx_ff12_IDPProvidedNameIdentifier_s*)e->gg.g.n)
	  len += zx_LEN_SO_ff12_IDPProvidedNameIdentifier(c, e);
  }


  len += zx_len_so_common(c, &x->gg, &pop_seen);
  zx_pop_seen(pop_seen);
  ENC_LEN_DEBUG(x, "sec12:SessionSubject", len);
  return len;
}

/* FUNC(zx_LEN_WO_sec12_SessionSubject) */

/* Compute length of an element (and its subelements). The XML attributes
 * and elements are processed in wire order and no assumptions
 * are made about namespace prefixes. */

/* Called by: */
int zx_LEN_WO_sec12_SessionSubject(struct zx_ctx* c, struct zx_sec12_SessionSubject_s* x )
{
  struct zx_ns_s* pop_seen = 0;
  struct zx_elem_s* se MAYBE_UNUSED;
#if 1 /* NORMALMODE */
  int len = 1 + sizeof("SessionSubject")-1 + 1 + 2 + sizeof("SessionSubject")-1 + 1;
  
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
      struct zx_sa11_NameIdentifier_s* e;
      for (e = x->NameIdentifier; e; e = (struct zx_sa11_NameIdentifier_s*)e->gg.g.n)
	  len += zx_LEN_WO_sa11_NameIdentifier(c, e);
  }
  {
      struct zx_sa11_SubjectConfirmation_s* e;
      for (e = x->SubjectConfirmation; e; e = (struct zx_sa11_SubjectConfirmation_s*)e->gg.g.n)
	  len += zx_LEN_WO_sa11_SubjectConfirmation(c, e);
  }
  {
      struct zx_ff12_IDPProvidedNameIdentifier_s* e;
      for (e = x->IDPProvidedNameIdentifier; e; e = (struct zx_ff12_IDPProvidedNameIdentifier_s*)e->gg.g.n)
	  len += zx_LEN_WO_ff12_IDPProvidedNameIdentifier(c, e);
  }


  len += zx_len_wo_common(c, &x->gg, &pop_seen); 
  zx_pop_seen(pop_seen);
  ENC_LEN_DEBUG(x, "sec12:SessionSubject", len);
  return len;
}

/* FUNC(zx_ENC_SO_sec12_SessionSubject) */

/* Render element into string. The XML attributes and elements are
 * processed in schema order. This is what you generally want for
 * rendering new data structure to a string. The wo pointers are not used. */

/* Called by: */
char* zx_ENC_SO_sec12_SessionSubject(struct zx_ctx* c, struct zx_sec12_SessionSubject_s* x, char* p )
{
  struct zx_elem_s* se MAYBE_UNUSED;
  struct zx_ns_s* pop_seen = 0;
  ENC_LEN_DEBUG_BASE;
#if 1 /* NORMALMODE */
  /* *** in simple_elem case should output ns prefix from ns node. */
  ZX_OUT_TAG(p, "<sec12:SessionSubject");
  if (c->inc_ns)
    zx_add_inc_ns(c, &pop_seen);
  zx_add_xmlns_if_not_seen(c, zx_ns_tab+zx_xmlns_ix_sec12, &pop_seen);

  zx_see_unknown_attrs_ns(c, x->gg.any_attr, &pop_seen);
  p = zx_enc_seen(p, pop_seen); 

  p = zx_enc_unknown_attrs(p, x->gg.any_attr);
#else
  /* root node has no begin tag */
#endif
  
  {
      struct zx_sa11_NameIdentifier_s* e;
      for (e = x->NameIdentifier; e; e = (struct zx_sa11_NameIdentifier_s*)e->gg.g.n)
	  p = zx_ENC_SO_sa11_NameIdentifier(c, e, p);
  }
  {
      struct zx_sa11_SubjectConfirmation_s* e;
      for (e = x->SubjectConfirmation; e; e = (struct zx_sa11_SubjectConfirmation_s*)e->gg.g.n)
	  p = zx_ENC_SO_sa11_SubjectConfirmation(c, e, p);
  }
  {
      struct zx_ff12_IDPProvidedNameIdentifier_s* e;
      for (e = x->IDPProvidedNameIdentifier; e; e = (struct zx_ff12_IDPProvidedNameIdentifier_s*)e->gg.g.n)
	  p = zx_ENC_SO_ff12_IDPProvidedNameIdentifier(c, e, p);
  }

  p = zx_enc_so_unknown_elems_and_content(c, p, &x->gg);
  
#if 1 /* NORMALMODE */
  ZX_OUT_CLOSE_TAG(p, "</sec12:SessionSubject>");
  zx_pop_seen(pop_seen);
#else
  /* root node has no end tag either */
#endif
  ENC_LEN_DEBUG(x, "sec12:SessionSubject", p-enc_base);
  return p;
}

/* FUNC(zx_ENC_WO_sec12_SessionSubject) */

/* Render element into string. The XML attributes and elements are
 * processed in wire order by chasing wo pointers. This is what you want for
 * validating signatures on other people's XML documents. */

/* Called by: */
char* zx_ENC_WO_sec12_SessionSubject(struct zx_ctx* c, struct zx_sec12_SessionSubject_s* x, char* p )
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
  ZX_OUT_MEM(p, "SessionSubject", sizeof("SessionSubject")-1);
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
  ENC_LEN_DEBUG(x, "sec12:SessionSubject", p-enc_base);
  return p;
}

/* FUNC(zx_EASY_ENC_SO_sec12_SessionSubject) */

/* Called by: */
struct zx_str* zx_EASY_ENC_SO_sec12_SessionSubject(struct zx_ctx* c, struct zx_sec12_SessionSubject_s* x )
{
  int len;
  char* buf;
  c->ns_tab = ZX_ALLOC(c, sizeof(zx_ns_tab));
  memcpy(c->ns_tab, zx_ns_tab, sizeof(zx_ns_tab));
  len = zx_LEN_SO_sec12_SessionSubject(c, x );
  buf = ZX_ALLOC(c, len+1);
  return zx_easy_enc_common(c, zx_ENC_SO_sec12_SessionSubject(c, x, buf ), buf, len);
}

/* FUNC(zx_EASY_ENC_WO_sec12_SessionSubject) */

/* Called by: */
struct zx_str* zx_EASY_ENC_WO_sec12_SessionSubject(struct zx_ctx* c, struct zx_sec12_SessionSubject_s* x )
{
  int len;
  char* buf;
  c->ns_tab = ZX_ALLOC(c, sizeof(zx_ns_tab));
  memcpy(c->ns_tab, zx_ns_tab, sizeof(zx_ns_tab));
  len = zx_LEN_WO_sec12_SessionSubject(c, x );
  buf = ZX_ALLOC(c, len+1);
  return zx_easy_enc_common(c, zx_ENC_WO_sec12_SessionSubject(c, x, buf ), buf, len);
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

#define EL_NAME   sec12_ValidityRestrictionCondition
#define EL_STRUCT zx_sec12_ValidityRestrictionCondition_s
#define EL_NS     sec12
#define EL_TAG    ValidityRestrictionCondition

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

/* FUNC(zx_LEN_SO_sec12_ValidityRestrictionCondition) */

/* Compute length of an element (and its subelements). The XML attributes
 * and elements are processed in schema order. */

/* Called by: */
int zx_LEN_SO_sec12_ValidityRestrictionCondition(struct zx_ctx* c, struct zx_sec12_ValidityRestrictionCondition_s* x )
{
  struct zx_ns_s* pop_seen = 0;
  struct zx_elem_s* se MAYBE_UNUSED;
#if 1 /* NORMALMODE */
  /* *** in simple_elem case should output ns prefix from ns node. */
  int len = sizeof("<sec12:ValidityRestrictionCondition")-1 + 1 + sizeof("</sec12:ValidityRestrictionCondition>")-1;
  if (c->inc_ns_len)
    len += zx_len_inc_ns(c, &pop_seen);
  len += zx_len_xmlns_if_not_seen(c, zx_ns_tab+zx_xmlns_ix_sec12, &pop_seen);


#else
  /* root node has no begin tag */
  int len = 0;
#endif
  
  for (se = x->NumberOfUses; se; se = (struct zx_elem_s*)se->g.n)
    len += zx_LEN_SO_simple_elem(c,se, sizeof("sec12:NumberOfUses")-1, zx_ns_tab+zx_xmlns_ix_sec12);


  len += zx_len_so_common(c, &x->gg, &pop_seen);
  zx_pop_seen(pop_seen);
  ENC_LEN_DEBUG(x, "sec12:ValidityRestrictionCondition", len);
  return len;
}

/* FUNC(zx_LEN_WO_sec12_ValidityRestrictionCondition) */

/* Compute length of an element (and its subelements). The XML attributes
 * and elements are processed in wire order and no assumptions
 * are made about namespace prefixes. */

/* Called by: */
int zx_LEN_WO_sec12_ValidityRestrictionCondition(struct zx_ctx* c, struct zx_sec12_ValidityRestrictionCondition_s* x )
{
  struct zx_ns_s* pop_seen = 0;
  struct zx_elem_s* se MAYBE_UNUSED;
#if 1 /* NORMALMODE */
  int len = 1 + sizeof("ValidityRestrictionCondition")-1 + 1 + 2 + sizeof("ValidityRestrictionCondition")-1 + 1;
  
  if (x->gg.g.ns && x->gg.g.ns->prefix_len)
    len += (x->gg.g.ns->prefix_len + 1) * 2;
  if (c->inc_ns_len)
    len += zx_len_inc_ns(c, &pop_seen);
  len += zx_len_xmlns_if_not_seen(c, x->gg.g.ns, &pop_seen);


#else
  /* root node has no begin tag */
  int len = 0;
#endif
  
  for (se = x->NumberOfUses; se; se = (struct zx_elem_s*)se->g.n)
    len += zx_LEN_WO_simple_elem(c, se, sizeof("NumberOfUses")-1);


  len += zx_len_wo_common(c, &x->gg, &pop_seen); 
  zx_pop_seen(pop_seen);
  ENC_LEN_DEBUG(x, "sec12:ValidityRestrictionCondition", len);
  return len;
}

/* FUNC(zx_ENC_SO_sec12_ValidityRestrictionCondition) */

/* Render element into string. The XML attributes and elements are
 * processed in schema order. This is what you generally want for
 * rendering new data structure to a string. The wo pointers are not used. */

/* Called by: */
char* zx_ENC_SO_sec12_ValidityRestrictionCondition(struct zx_ctx* c, struct zx_sec12_ValidityRestrictionCondition_s* x, char* p )
{
  struct zx_elem_s* se MAYBE_UNUSED;
  struct zx_ns_s* pop_seen = 0;
  ENC_LEN_DEBUG_BASE;
#if 1 /* NORMALMODE */
  /* *** in simple_elem case should output ns prefix from ns node. */
  ZX_OUT_TAG(p, "<sec12:ValidityRestrictionCondition");
  if (c->inc_ns)
    zx_add_inc_ns(c, &pop_seen);
  zx_add_xmlns_if_not_seen(c, zx_ns_tab+zx_xmlns_ix_sec12, &pop_seen);

  zx_see_unknown_attrs_ns(c, x->gg.any_attr, &pop_seen);
  p = zx_enc_seen(p, pop_seen); 

  p = zx_enc_unknown_attrs(p, x->gg.any_attr);
#else
  /* root node has no begin tag */
#endif
  
  for (se = x->NumberOfUses; se; se = (struct zx_elem_s*)se->g.n)
    p = zx_ENC_SO_simple_elem(c, se, p, "sec12:NumberOfUses", sizeof("sec12:NumberOfUses")-1, zx_ns_tab+zx_xmlns_ix_sec12);

  p = zx_enc_so_unknown_elems_and_content(c, p, &x->gg);
  
#if 1 /* NORMALMODE */
  ZX_OUT_CLOSE_TAG(p, "</sec12:ValidityRestrictionCondition>");
  zx_pop_seen(pop_seen);
#else
  /* root node has no end tag either */
#endif
  ENC_LEN_DEBUG(x, "sec12:ValidityRestrictionCondition", p-enc_base);
  return p;
}

/* FUNC(zx_ENC_WO_sec12_ValidityRestrictionCondition) */

/* Render element into string. The XML attributes and elements are
 * processed in wire order by chasing wo pointers. This is what you want for
 * validating signatures on other people's XML documents. */

/* Called by: */
char* zx_ENC_WO_sec12_ValidityRestrictionCondition(struct zx_ctx* c, struct zx_sec12_ValidityRestrictionCondition_s* x, char* p )
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
  ZX_OUT_MEM(p, "ValidityRestrictionCondition", sizeof("ValidityRestrictionCondition")-1);
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
  ENC_LEN_DEBUG(x, "sec12:ValidityRestrictionCondition", p-enc_base);
  return p;
}

/* FUNC(zx_EASY_ENC_SO_sec12_ValidityRestrictionCondition) */

/* Called by: */
struct zx_str* zx_EASY_ENC_SO_sec12_ValidityRestrictionCondition(struct zx_ctx* c, struct zx_sec12_ValidityRestrictionCondition_s* x )
{
  int len;
  char* buf;
  c->ns_tab = ZX_ALLOC(c, sizeof(zx_ns_tab));
  memcpy(c->ns_tab, zx_ns_tab, sizeof(zx_ns_tab));
  len = zx_LEN_SO_sec12_ValidityRestrictionCondition(c, x );
  buf = ZX_ALLOC(c, len+1);
  return zx_easy_enc_common(c, zx_ENC_SO_sec12_ValidityRestrictionCondition(c, x, buf ), buf, len);
}

/* FUNC(zx_EASY_ENC_WO_sec12_ValidityRestrictionCondition) */

/* Called by: */
struct zx_str* zx_EASY_ENC_WO_sec12_ValidityRestrictionCondition(struct zx_ctx* c, struct zx_sec12_ValidityRestrictionCondition_s* x )
{
  int len;
  char* buf;
  c->ns_tab = ZX_ALLOC(c, sizeof(zx_ns_tab));
  memcpy(c->ns_tab, zx_ns_tab, sizeof(zx_ns_tab));
  len = zx_LEN_WO_sec12_ValidityRestrictionCondition(c, x );
  buf = ZX_ALLOC(c, len+1);
  return zx_easy_enc_common(c, zx_ENC_WO_sec12_ValidityRestrictionCondition(c, x, buf ), buf, len);
}




/* EOF -- c/zx-sec12-enc.c */
