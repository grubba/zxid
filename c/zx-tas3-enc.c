/* c/zx-tas3-enc.c - WARNING: This file was automatically generated. DO NOT EDIT!
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
#include "c/zx-tas3-data.h"
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

#define EL_NAME   tas3_Credentials
#define EL_STRUCT zx_tas3_Credentials_s
#define EL_NS     tas3
#define EL_TAG    Credentials

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

/* FUNC(zx_LEN_SO_tas3_Credentials) */

/* Compute length of an element (and its subelements). The XML attributes
 * and elements are processed in schema order. */

/* Called by: */
int zx_LEN_SO_tas3_Credentials(struct zx_ctx* c, struct zx_tas3_Credentials_s* x )
{
  struct zx_ns_s* pop_seen = 0;
  struct zx_elem_s* se MAYBE_UNUSED;
#if 1 /* NORMALMODE */
  /* *** in simple_elem case should output ns prefix from ns node. */
  int len = sizeof("<tas3:Credentials")-1 + 1 + sizeof("</tas3:Credentials>")-1;
  if (c->inc_ns_len)
    len += zx_len_inc_ns(c, &pop_seen);
  if (x->actor || x->mustUnderstand)
    len += zx_len_xmlns_if_not_seen(c, zx_ns_tab+zx_xmlns_ix_e, &pop_seen);
  len += zx_len_xmlns_if_not_seen(c, zx_ns_tab+zx_xmlns_ix_tas3, &pop_seen);
  if (x->Id)
    len += zx_len_xmlns_if_not_seen(c, zx_ns_tab+zx_xmlns_ix_wsu, &pop_seen);

  len += zx_attr_so_len(x->id, sizeof("id")-1);
  len += zx_attr_so_len(x->usage, sizeof("usage")-1);
  len += zx_attr_so_len(x->Id, sizeof("wsu:Id")-1);
  len += zx_attr_so_len(x->actor, sizeof("e:actor")-1);
  len += zx_attr_so_len(x->mustUnderstand, sizeof("e:mustUnderstand")-1);

#else
  /* root node has no begin tag */
  int len = 0;
#endif
  
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
      struct zx_sa_Attribute_s* e;
      for (e = x->Attribute; e; e = (struct zx_sa_Attribute_s*)e->gg.g.n)
	  len += zx_LEN_SO_sa_Attribute(c, e);
  }
  {
      struct zx_sa_EncryptedAttribute_s* e;
      for (e = x->EncryptedAttribute; e; e = (struct zx_sa_EncryptedAttribute_s*)e->gg.g.n)
	  len += zx_LEN_SO_sa_EncryptedAttribute(c, e);
  }
  {
      struct zx_xac_Attribute_s* e;
      for (e = x->xac_Attribute; e; e = (struct zx_xac_Attribute_s*)e->gg.g.n)
	  len += zx_LEN_SO_xac_Attribute(c, e);
  }


  len += zx_len_so_common(c, &x->gg);
  zx_pop_seen(pop_seen);
  ENC_LEN_DEBUG(x, "tas3:Credentials", len);
  return len;
}

/* FUNC(zx_LEN_WO_tas3_Credentials) */

/* Compute length of an element (and its subelements). The XML attributes
 * and elements are processed in wire order and no assumptions
 * are made about namespace prefixes. */

/* Called by: */
int zx_LEN_WO_tas3_Credentials(struct zx_ctx* c, struct zx_tas3_Credentials_s* x )
{
  struct zx_ns_s* pop_seen = 0;
  struct zx_elem_s* se MAYBE_UNUSED;
#if 1 /* NORMALMODE */
  int len = 1 + sizeof("Credentials")-1 + 1 + 2 + sizeof("Credentials")-1 + 1;
  
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

  len += zx_attr_wo_len(x->id, sizeof("id")-1);
  len += zx_attr_wo_len(x->usage, sizeof("usage")-1);
  len += zx_attr_wo_len(x->Id, sizeof("Id")-1);
  len += zx_attr_wo_len(x->actor, sizeof("actor")-1);
  len += zx_attr_wo_len(x->mustUnderstand, sizeof("mustUnderstand")-1);

#else
  /* root node has no begin tag */
  int len = 0;
#endif
  
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
      struct zx_sa_Attribute_s* e;
      for (e = x->Attribute; e; e = (struct zx_sa_Attribute_s*)e->gg.g.n)
	  len += zx_LEN_WO_sa_Attribute(c, e);
  }
  {
      struct zx_sa_EncryptedAttribute_s* e;
      for (e = x->EncryptedAttribute; e; e = (struct zx_sa_EncryptedAttribute_s*)e->gg.g.n)
	  len += zx_LEN_WO_sa_EncryptedAttribute(c, e);
  }
  {
      struct zx_xac_Attribute_s* e;
      for (e = x->xac_Attribute; e; e = (struct zx_xac_Attribute_s*)e->gg.g.n)
	  len += zx_LEN_WO_xac_Attribute(c, e);
  }


  len += zx_len_wo_common(c, &x->gg); 
  zx_pop_seen(pop_seen);
  ENC_LEN_DEBUG(x, "tas3:Credentials", len);
  return len;
}

/* FUNC(zx_ENC_SO_tas3_Credentials) */

/* Render element into string. The XML attributes and elements are
 * processed in schema order. This is what you generally want for
 * rendering new data structure to a string. The wo pointers are not used. */

/* Called by: */
char* zx_ENC_SO_tas3_Credentials(struct zx_ctx* c, struct zx_tas3_Credentials_s* x, char* p )
{
  struct zx_elem_s* se MAYBE_UNUSED;
  ENC_LEN_DEBUG_BASE;
#if 1 /* NORMALMODE */
  struct zx_ns_s* pop_seen = 0;
  /* *** in simple_elem case should output ns prefix from ns node. */
  ZX_OUT_TAG(p, "<tas3:Credentials");
  if (c->inc_ns)
    p = zx_enc_inc_ns(c, p, &pop_seen);
  if (x->actor || x->mustUnderstand)
    p = zx_enc_xmlns_if_not_seen(c, p, zx_ns_tab+zx_xmlns_ix_e, &pop_seen);
  p = zx_enc_xmlns_if_not_seen(c, p, zx_ns_tab+zx_xmlns_ix_tas3, &pop_seen);
  if (x->Id)
    p = zx_enc_xmlns_if_not_seen(c, p, zx_ns_tab+zx_xmlns_ix_wsu, &pop_seen);

  p = zx_attr_so_enc(p, x->id, " id=\"", sizeof(" id=\"")-1);
  p = zx_attr_so_enc(p, x->usage, " usage=\"", sizeof(" usage=\"")-1);
  p = zx_attr_so_enc(p, x->Id, " wsu:Id=\"", sizeof(" wsu:Id=\"")-1);
  p = zx_attr_so_enc(p, x->actor, " e:actor=\"", sizeof(" e:actor=\"")-1);
  p = zx_attr_so_enc(p, x->mustUnderstand, " e:mustUnderstand=\"", sizeof(" e:mustUnderstand=\"")-1);

  p = zx_enc_unknown_attrs(p, x->gg.any_attr);
#else
  /* root node has no begin tag */
#endif
  
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
      struct zx_sa_Attribute_s* e;
      for (e = x->Attribute; e; e = (struct zx_sa_Attribute_s*)e->gg.g.n)
	  p = zx_ENC_SO_sa_Attribute(c, e, p);
  }
  {
      struct zx_sa_EncryptedAttribute_s* e;
      for (e = x->EncryptedAttribute; e; e = (struct zx_sa_EncryptedAttribute_s*)e->gg.g.n)
	  p = zx_ENC_SO_sa_EncryptedAttribute(c, e, p);
  }
  {
      struct zx_xac_Attribute_s* e;
      for (e = x->xac_Attribute; e; e = (struct zx_xac_Attribute_s*)e->gg.g.n)
	  p = zx_ENC_SO_xac_Attribute(c, e, p);
  }

  p = zx_enc_so_unknown_elems_and_content(c, p, &x->gg);
  
#if 1 /* NORMALMODE */
  ZX_OUT_CLOSE_TAG(p, "</tas3:Credentials>");
  zx_pop_seen(pop_seen);
#else
  /* root node has no end tag either */
#endif
  ENC_LEN_DEBUG(x, "tas3:Credentials", p-enc_base);
  return p;
}

/* FUNC(zx_ENC_WO_tas3_Credentials) */

/* Render element into string. The XML attributes and elements are
 * processed in wire order by chasing wo pointers. This is what you want for
 * validating signatures on other people's XML documents. */

/* Called by: */
char* zx_ENC_WO_tas3_Credentials(struct zx_ctx* c, struct zx_tas3_Credentials_s* x, char* p )
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
  ZX_OUT_MEM(p, "Credentials", sizeof("Credentials")-1);
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
  p = zx_attr_wo_enc(p, x->id, "id=\"", sizeof("id=\"")-1);
  p = zx_attr_wo_enc(p, x->usage, "usage=\"", sizeof("usage=\"")-1);
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
  ENC_LEN_DEBUG(x, "tas3:Credentials", p-enc_base);
  return p;
}

/* FUNC(zx_EASY_ENC_SO_tas3_Credentials) */

/* Called by: */
struct zx_str* zx_EASY_ENC_SO_tas3_Credentials(struct zx_ctx* c, struct zx_tas3_Credentials_s* x )
{
  int len;
  char* buf;
  c->ns_tab = ZX_ALLOC(c, sizeof(zx_ns_tab));
  memcpy(c->ns_tab, zx_ns_tab, sizeof(zx_ns_tab));
  len = zx_LEN_SO_tas3_Credentials(c, x );
  buf = ZX_ALLOC(c, len+1);
  return zx_easy_enc_common(c, zx_ENC_SO_tas3_Credentials(c, x, buf ), buf, len);
}

/* FUNC(zx_EASY_ENC_WO_tas3_Credentials) */

/* Called by: */
struct zx_str* zx_EASY_ENC_WO_tas3_Credentials(struct zx_ctx* c, struct zx_tas3_Credentials_s* x )
{
  int len;
  char* buf;
  c->ns_tab = ZX_ALLOC(c, sizeof(zx_ns_tab));
  memcpy(c->ns_tab, zx_ns_tab, sizeof(zx_ns_tab));
  len = zx_LEN_WO_tas3_Credentials(c, x );
  buf = ZX_ALLOC(c, len+1);
  return zx_easy_enc_common(c, zx_ENC_WO_tas3_Credentials(c, x, buf ), buf, len);
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

#define EL_NAME   tas3_ESLApply
#define EL_STRUCT zx_tas3_ESLApply_s
#define EL_NS     tas3
#define EL_TAG    ESLApply

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

/* FUNC(zx_LEN_SO_tas3_ESLApply) */

/* Compute length of an element (and its subelements). The XML attributes
 * and elements are processed in schema order. */

/* Called by: */
int zx_LEN_SO_tas3_ESLApply(struct zx_ctx* c, struct zx_tas3_ESLApply_s* x )
{
  struct zx_ns_s* pop_seen = 0;
  struct zx_elem_s* se MAYBE_UNUSED;
#if 1 /* NORMALMODE */
  /* *** in simple_elem case should output ns prefix from ns node. */
  int len = sizeof("<tas3:ESLApply")-1 + 1 + sizeof("</tas3:ESLApply>")-1;
  if (c->inc_ns_len)
    len += zx_len_inc_ns(c, &pop_seen);
  len += zx_len_xmlns_if_not_seen(c, zx_ns_tab+zx_xmlns_ix_tas3, &pop_seen);


#else
  /* root node has no begin tag */
  int len = 0;
#endif
  
  {
      struct zx_tas3_ESLRef_s* e;
      for (e = x->ESLRef; e; e = (struct zx_tas3_ESLRef_s*)e->gg.g.n)
	  len += zx_LEN_SO_tas3_ESLRef(c, e);
  }
  {
      struct zx_xa_Obligation_s* e;
      for (e = x->Obligation; e; e = (struct zx_xa_Obligation_s*)e->gg.g.n)
	  len += zx_LEN_SO_xa_Obligation(c, e);
  }


  len += zx_len_so_common(c, &x->gg);
  zx_pop_seen(pop_seen);
  ENC_LEN_DEBUG(x, "tas3:ESLApply", len);
  return len;
}

/* FUNC(zx_LEN_WO_tas3_ESLApply) */

/* Compute length of an element (and its subelements). The XML attributes
 * and elements are processed in wire order and no assumptions
 * are made about namespace prefixes. */

/* Called by: */
int zx_LEN_WO_tas3_ESLApply(struct zx_ctx* c, struct zx_tas3_ESLApply_s* x )
{
  struct zx_ns_s* pop_seen = 0;
  struct zx_elem_s* se MAYBE_UNUSED;
#if 1 /* NORMALMODE */
  int len = 1 + sizeof("ESLApply")-1 + 1 + 2 + sizeof("ESLApply")-1 + 1;
  
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
      struct zx_tas3_ESLRef_s* e;
      for (e = x->ESLRef; e; e = (struct zx_tas3_ESLRef_s*)e->gg.g.n)
	  len += zx_LEN_WO_tas3_ESLRef(c, e);
  }
  {
      struct zx_xa_Obligation_s* e;
      for (e = x->Obligation; e; e = (struct zx_xa_Obligation_s*)e->gg.g.n)
	  len += zx_LEN_WO_xa_Obligation(c, e);
  }


  len += zx_len_wo_common(c, &x->gg); 
  zx_pop_seen(pop_seen);
  ENC_LEN_DEBUG(x, "tas3:ESLApply", len);
  return len;
}

/* FUNC(zx_ENC_SO_tas3_ESLApply) */

/* Render element into string. The XML attributes and elements are
 * processed in schema order. This is what you generally want for
 * rendering new data structure to a string. The wo pointers are not used. */

/* Called by: */
char* zx_ENC_SO_tas3_ESLApply(struct zx_ctx* c, struct zx_tas3_ESLApply_s* x, char* p )
{
  struct zx_elem_s* se MAYBE_UNUSED;
  ENC_LEN_DEBUG_BASE;
#if 1 /* NORMALMODE */
  struct zx_ns_s* pop_seen = 0;
  /* *** in simple_elem case should output ns prefix from ns node. */
  ZX_OUT_TAG(p, "<tas3:ESLApply");
  if (c->inc_ns)
    p = zx_enc_inc_ns(c, p, &pop_seen);
  p = zx_enc_xmlns_if_not_seen(c, p, zx_ns_tab+zx_xmlns_ix_tas3, &pop_seen);


  p = zx_enc_unknown_attrs(p, x->gg.any_attr);
#else
  /* root node has no begin tag */
#endif
  
  {
      struct zx_tas3_ESLRef_s* e;
      for (e = x->ESLRef; e; e = (struct zx_tas3_ESLRef_s*)e->gg.g.n)
	  p = zx_ENC_SO_tas3_ESLRef(c, e, p);
  }
  {
      struct zx_xa_Obligation_s* e;
      for (e = x->Obligation; e; e = (struct zx_xa_Obligation_s*)e->gg.g.n)
	  p = zx_ENC_SO_xa_Obligation(c, e, p);
  }

  p = zx_enc_so_unknown_elems_and_content(c, p, &x->gg);
  
#if 1 /* NORMALMODE */
  ZX_OUT_CLOSE_TAG(p, "</tas3:ESLApply>");
  zx_pop_seen(pop_seen);
#else
  /* root node has no end tag either */
#endif
  ENC_LEN_DEBUG(x, "tas3:ESLApply", p-enc_base);
  return p;
}

/* FUNC(zx_ENC_WO_tas3_ESLApply) */

/* Render element into string. The XML attributes and elements are
 * processed in wire order by chasing wo pointers. This is what you want for
 * validating signatures on other people's XML documents. */

/* Called by: */
char* zx_ENC_WO_tas3_ESLApply(struct zx_ctx* c, struct zx_tas3_ESLApply_s* x, char* p )
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
  ZX_OUT_MEM(p, "ESLApply", sizeof("ESLApply")-1);
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
  ENC_LEN_DEBUG(x, "tas3:ESLApply", p-enc_base);
  return p;
}

/* FUNC(zx_EASY_ENC_SO_tas3_ESLApply) */

/* Called by: */
struct zx_str* zx_EASY_ENC_SO_tas3_ESLApply(struct zx_ctx* c, struct zx_tas3_ESLApply_s* x )
{
  int len;
  char* buf;
  c->ns_tab = ZX_ALLOC(c, sizeof(zx_ns_tab));
  memcpy(c->ns_tab, zx_ns_tab, sizeof(zx_ns_tab));
  len = zx_LEN_SO_tas3_ESLApply(c, x );
  buf = ZX_ALLOC(c, len+1);
  return zx_easy_enc_common(c, zx_ENC_SO_tas3_ESLApply(c, x, buf ), buf, len);
}

/* FUNC(zx_EASY_ENC_WO_tas3_ESLApply) */

/* Called by: */
struct zx_str* zx_EASY_ENC_WO_tas3_ESLApply(struct zx_ctx* c, struct zx_tas3_ESLApply_s* x )
{
  int len;
  char* buf;
  c->ns_tab = ZX_ALLOC(c, sizeof(zx_ns_tab));
  memcpy(c->ns_tab, zx_ns_tab, sizeof(zx_ns_tab));
  len = zx_LEN_WO_tas3_ESLApply(c, x );
  buf = ZX_ALLOC(c, len+1);
  return zx_easy_enc_common(c, zx_ENC_WO_tas3_ESLApply(c, x, buf ), buf, len);
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

#define EL_NAME   tas3_ESLPolicies
#define EL_STRUCT zx_tas3_ESLPolicies_s
#define EL_NS     tas3
#define EL_TAG    ESLPolicies

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

/* FUNC(zx_LEN_SO_tas3_ESLPolicies) */

/* Compute length of an element (and its subelements). The XML attributes
 * and elements are processed in schema order. */

/* Called by: */
int zx_LEN_SO_tas3_ESLPolicies(struct zx_ctx* c, struct zx_tas3_ESLPolicies_s* x )
{
  struct zx_ns_s* pop_seen = 0;
  struct zx_elem_s* se MAYBE_UNUSED;
#if 1 /* NORMALMODE */
  /* *** in simple_elem case should output ns prefix from ns node. */
  int len = sizeof("<tas3:ESLPolicies")-1 + 1 + sizeof("</tas3:ESLPolicies>")-1;
  if (c->inc_ns_len)
    len += zx_len_inc_ns(c, &pop_seen);
  if (x->actor || x->mustUnderstand)
    len += zx_len_xmlns_if_not_seen(c, zx_ns_tab+zx_xmlns_ix_e, &pop_seen);
  len += zx_len_xmlns_if_not_seen(c, zx_ns_tab+zx_xmlns_ix_tas3, &pop_seen);
  if (x->Id)
    len += zx_len_xmlns_if_not_seen(c, zx_ns_tab+zx_xmlns_ix_wsu, &pop_seen);

  len += zx_attr_so_len(x->id, sizeof("id")-1);
  len += zx_attr_so_len(x->usage, sizeof("usage")-1);
  len += zx_attr_so_len(x->Id, sizeof("wsu:Id")-1);
  len += zx_attr_so_len(x->actor, sizeof("e:actor")-1);
  len += zx_attr_so_len(x->mustUnderstand, sizeof("e:mustUnderstand")-1);

#else
  /* root node has no begin tag */
  int len = 0;
#endif
  
  {
      struct zx_tas3_ESLApply_s* e;
      for (e = x->ESLApply; e; e = (struct zx_tas3_ESLApply_s*)e->gg.g.n)
	  len += zx_LEN_SO_tas3_ESLApply(c, e);
  }


  len += zx_len_so_common(c, &x->gg);
  zx_pop_seen(pop_seen);
  ENC_LEN_DEBUG(x, "tas3:ESLPolicies", len);
  return len;
}

/* FUNC(zx_LEN_WO_tas3_ESLPolicies) */

/* Compute length of an element (and its subelements). The XML attributes
 * and elements are processed in wire order and no assumptions
 * are made about namespace prefixes. */

/* Called by: */
int zx_LEN_WO_tas3_ESLPolicies(struct zx_ctx* c, struct zx_tas3_ESLPolicies_s* x )
{
  struct zx_ns_s* pop_seen = 0;
  struct zx_elem_s* se MAYBE_UNUSED;
#if 1 /* NORMALMODE */
  int len = 1 + sizeof("ESLPolicies")-1 + 1 + 2 + sizeof("ESLPolicies")-1 + 1;
  
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

  len += zx_attr_wo_len(x->id, sizeof("id")-1);
  len += zx_attr_wo_len(x->usage, sizeof("usage")-1);
  len += zx_attr_wo_len(x->Id, sizeof("Id")-1);
  len += zx_attr_wo_len(x->actor, sizeof("actor")-1);
  len += zx_attr_wo_len(x->mustUnderstand, sizeof("mustUnderstand")-1);

#else
  /* root node has no begin tag */
  int len = 0;
#endif
  
  {
      struct zx_tas3_ESLApply_s* e;
      for (e = x->ESLApply; e; e = (struct zx_tas3_ESLApply_s*)e->gg.g.n)
	  len += zx_LEN_WO_tas3_ESLApply(c, e);
  }


  len += zx_len_wo_common(c, &x->gg); 
  zx_pop_seen(pop_seen);
  ENC_LEN_DEBUG(x, "tas3:ESLPolicies", len);
  return len;
}

/* FUNC(zx_ENC_SO_tas3_ESLPolicies) */

/* Render element into string. The XML attributes and elements are
 * processed in schema order. This is what you generally want for
 * rendering new data structure to a string. The wo pointers are not used. */

/* Called by: */
char* zx_ENC_SO_tas3_ESLPolicies(struct zx_ctx* c, struct zx_tas3_ESLPolicies_s* x, char* p )
{
  struct zx_elem_s* se MAYBE_UNUSED;
  ENC_LEN_DEBUG_BASE;
#if 1 /* NORMALMODE */
  struct zx_ns_s* pop_seen = 0;
  /* *** in simple_elem case should output ns prefix from ns node. */
  ZX_OUT_TAG(p, "<tas3:ESLPolicies");
  if (c->inc_ns)
    p = zx_enc_inc_ns(c, p, &pop_seen);
  if (x->actor || x->mustUnderstand)
    p = zx_enc_xmlns_if_not_seen(c, p, zx_ns_tab+zx_xmlns_ix_e, &pop_seen);
  p = zx_enc_xmlns_if_not_seen(c, p, zx_ns_tab+zx_xmlns_ix_tas3, &pop_seen);
  if (x->Id)
    p = zx_enc_xmlns_if_not_seen(c, p, zx_ns_tab+zx_xmlns_ix_wsu, &pop_seen);

  p = zx_attr_so_enc(p, x->id, " id=\"", sizeof(" id=\"")-1);
  p = zx_attr_so_enc(p, x->usage, " usage=\"", sizeof(" usage=\"")-1);
  p = zx_attr_so_enc(p, x->Id, " wsu:Id=\"", sizeof(" wsu:Id=\"")-1);
  p = zx_attr_so_enc(p, x->actor, " e:actor=\"", sizeof(" e:actor=\"")-1);
  p = zx_attr_so_enc(p, x->mustUnderstand, " e:mustUnderstand=\"", sizeof(" e:mustUnderstand=\"")-1);

  p = zx_enc_unknown_attrs(p, x->gg.any_attr);
#else
  /* root node has no begin tag */
#endif
  
  {
      struct zx_tas3_ESLApply_s* e;
      for (e = x->ESLApply; e; e = (struct zx_tas3_ESLApply_s*)e->gg.g.n)
	  p = zx_ENC_SO_tas3_ESLApply(c, e, p);
  }

  p = zx_enc_so_unknown_elems_and_content(c, p, &x->gg);
  
#if 1 /* NORMALMODE */
  ZX_OUT_CLOSE_TAG(p, "</tas3:ESLPolicies>");
  zx_pop_seen(pop_seen);
#else
  /* root node has no end tag either */
#endif
  ENC_LEN_DEBUG(x, "tas3:ESLPolicies", p-enc_base);
  return p;
}

/* FUNC(zx_ENC_WO_tas3_ESLPolicies) */

/* Render element into string. The XML attributes and elements are
 * processed in wire order by chasing wo pointers. This is what you want for
 * validating signatures on other people's XML documents. */

/* Called by: */
char* zx_ENC_WO_tas3_ESLPolicies(struct zx_ctx* c, struct zx_tas3_ESLPolicies_s* x, char* p )
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
  ZX_OUT_MEM(p, "ESLPolicies", sizeof("ESLPolicies")-1);
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
  p = zx_attr_wo_enc(p, x->id, "id=\"", sizeof("id=\"")-1);
  p = zx_attr_wo_enc(p, x->usage, "usage=\"", sizeof("usage=\"")-1);
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
  ENC_LEN_DEBUG(x, "tas3:ESLPolicies", p-enc_base);
  return p;
}

/* FUNC(zx_EASY_ENC_SO_tas3_ESLPolicies) */

/* Called by: */
struct zx_str* zx_EASY_ENC_SO_tas3_ESLPolicies(struct zx_ctx* c, struct zx_tas3_ESLPolicies_s* x )
{
  int len;
  char* buf;
  c->ns_tab = ZX_ALLOC(c, sizeof(zx_ns_tab));
  memcpy(c->ns_tab, zx_ns_tab, sizeof(zx_ns_tab));
  len = zx_LEN_SO_tas3_ESLPolicies(c, x );
  buf = ZX_ALLOC(c, len+1);
  return zx_easy_enc_common(c, zx_ENC_SO_tas3_ESLPolicies(c, x, buf ), buf, len);
}

/* FUNC(zx_EASY_ENC_WO_tas3_ESLPolicies) */

/* Called by: */
struct zx_str* zx_EASY_ENC_WO_tas3_ESLPolicies(struct zx_ctx* c, struct zx_tas3_ESLPolicies_s* x )
{
  int len;
  char* buf;
  c->ns_tab = ZX_ALLOC(c, sizeof(zx_ns_tab));
  memcpy(c->ns_tab, zx_ns_tab, sizeof(zx_ns_tab));
  len = zx_LEN_WO_tas3_ESLPolicies(c, x );
  buf = ZX_ALLOC(c, len+1);
  return zx_easy_enc_common(c, zx_ENC_WO_tas3_ESLPolicies(c, x, buf ), buf, len);
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

#define EL_NAME   tas3_ESLRef
#define EL_STRUCT zx_tas3_ESLRef_s
#define EL_NS     tas3
#define EL_TAG    ESLRef

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

/* FUNC(zx_LEN_SO_tas3_ESLRef) */

/* Compute length of an element (and its subelements). The XML attributes
 * and elements are processed in schema order. */

/* Called by: */
int zx_LEN_SO_tas3_ESLRef(struct zx_ctx* c, struct zx_tas3_ESLRef_s* x )
{
  struct zx_ns_s* pop_seen = 0;
  struct zx_elem_s* se MAYBE_UNUSED;
#if 1 /* NORMALMODE */
  /* *** in simple_elem case should output ns prefix from ns node. */
  int len = sizeof("<tas3:ESLRef")-1 + 1 + sizeof("</tas3:ESLRef>")-1;
  if (c->inc_ns_len)
    len += zx_len_inc_ns(c, &pop_seen);
  len += zx_len_xmlns_if_not_seen(c, zx_ns_tab+zx_xmlns_ix_tas3, &pop_seen);

  len += zx_attr_so_len(x->ref, sizeof("ref")-1);
  len += zx_attr_so_len(x->xpath, sizeof("xpath")-1);

#else
  /* root node has no begin tag */
  int len = 0;
#endif
  


  len += zx_len_so_common(c, &x->gg);
  zx_pop_seen(pop_seen);
  ENC_LEN_DEBUG(x, "tas3:ESLRef", len);
  return len;
}

/* FUNC(zx_LEN_WO_tas3_ESLRef) */

/* Compute length of an element (and its subelements). The XML attributes
 * and elements are processed in wire order and no assumptions
 * are made about namespace prefixes. */

/* Called by: */
int zx_LEN_WO_tas3_ESLRef(struct zx_ctx* c, struct zx_tas3_ESLRef_s* x )
{
  struct zx_ns_s* pop_seen = 0;
  struct zx_elem_s* se MAYBE_UNUSED;
#if 1 /* NORMALMODE */
  int len = 1 + sizeof("ESLRef")-1 + 1 + 2 + sizeof("ESLRef")-1 + 1;
  
  if (x->gg.g.ns && x->gg.g.ns->prefix_len)
    len += (x->gg.g.ns->prefix_len + 1) * 2;
  if (c->inc_ns_len)
    len += zx_len_inc_ns(c, &pop_seen);
  len += zx_len_xmlns_if_not_seen(c, x->gg.g.ns, &pop_seen);

  len += zx_attr_wo_len(x->ref, sizeof("ref")-1);
  len += zx_attr_wo_len(x->xpath, sizeof("xpath")-1);

#else
  /* root node has no begin tag */
  int len = 0;
#endif
  


  len += zx_len_wo_common(c, &x->gg); 
  zx_pop_seen(pop_seen);
  ENC_LEN_DEBUG(x, "tas3:ESLRef", len);
  return len;
}

/* FUNC(zx_ENC_SO_tas3_ESLRef) */

/* Render element into string. The XML attributes and elements are
 * processed in schema order. This is what you generally want for
 * rendering new data structure to a string. The wo pointers are not used. */

/* Called by: */
char* zx_ENC_SO_tas3_ESLRef(struct zx_ctx* c, struct zx_tas3_ESLRef_s* x, char* p )
{
  struct zx_elem_s* se MAYBE_UNUSED;
  ENC_LEN_DEBUG_BASE;
#if 1 /* NORMALMODE */
  struct zx_ns_s* pop_seen = 0;
  /* *** in simple_elem case should output ns prefix from ns node. */
  ZX_OUT_TAG(p, "<tas3:ESLRef");
  if (c->inc_ns)
    p = zx_enc_inc_ns(c, p, &pop_seen);
  p = zx_enc_xmlns_if_not_seen(c, p, zx_ns_tab+zx_xmlns_ix_tas3, &pop_seen);

  p = zx_attr_so_enc(p, x->ref, " ref=\"", sizeof(" ref=\"")-1);
  p = zx_attr_so_enc(p, x->xpath, " xpath=\"", sizeof(" xpath=\"")-1);

  p = zx_enc_unknown_attrs(p, x->gg.any_attr);
#else
  /* root node has no begin tag */
#endif
  

  p = zx_enc_so_unknown_elems_and_content(c, p, &x->gg);
  
#if 1 /* NORMALMODE */
  ZX_OUT_CLOSE_TAG(p, "</tas3:ESLRef>");
  zx_pop_seen(pop_seen);
#else
  /* root node has no end tag either */
#endif
  ENC_LEN_DEBUG(x, "tas3:ESLRef", p-enc_base);
  return p;
}

/* FUNC(zx_ENC_WO_tas3_ESLRef) */

/* Render element into string. The XML attributes and elements are
 * processed in wire order by chasing wo pointers. This is what you want for
 * validating signatures on other people's XML documents. */

/* Called by: */
char* zx_ENC_WO_tas3_ESLRef(struct zx_ctx* c, struct zx_tas3_ESLRef_s* x, char* p )
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
  ZX_OUT_MEM(p, "ESLRef", sizeof("ESLRef")-1);
  qq = p;

  /* *** sort the namespaces */
  if (c->inc_ns)
    zx_add_inc_ns(c, &pop_seen);
  zx_add_xmlns_if_not_seen(c, x->gg.g.ns, &pop_seen);

  p = zx_enc_seen(p, pop_seen); 
  p = zx_attr_wo_enc(p, x->ref, "ref=\"", sizeof("ref=\"")-1);
  p = zx_attr_wo_enc(p, x->xpath, "xpath=\"", sizeof("xpath=\"")-1);

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
  ENC_LEN_DEBUG(x, "tas3:ESLRef", p-enc_base);
  return p;
}

/* FUNC(zx_EASY_ENC_SO_tas3_ESLRef) */

/* Called by: */
struct zx_str* zx_EASY_ENC_SO_tas3_ESLRef(struct zx_ctx* c, struct zx_tas3_ESLRef_s* x )
{
  int len;
  char* buf;
  c->ns_tab = ZX_ALLOC(c, sizeof(zx_ns_tab));
  memcpy(c->ns_tab, zx_ns_tab, sizeof(zx_ns_tab));
  len = zx_LEN_SO_tas3_ESLRef(c, x );
  buf = ZX_ALLOC(c, len+1);
  return zx_easy_enc_common(c, zx_ENC_SO_tas3_ESLRef(c, x, buf ), buf, len);
}

/* FUNC(zx_EASY_ENC_WO_tas3_ESLRef) */

/* Called by: */
struct zx_str* zx_EASY_ENC_WO_tas3_ESLRef(struct zx_ctx* c, struct zx_tas3_ESLRef_s* x )
{
  int len;
  char* buf;
  c->ns_tab = ZX_ALLOC(c, sizeof(zx_ns_tab));
  memcpy(c->ns_tab, zx_ns_tab, sizeof(zx_ns_tab));
  len = zx_LEN_WO_tas3_ESLRef(c, x );
  buf = ZX_ALLOC(c, len+1);
  return zx_easy_enc_common(c, zx_ENC_WO_tas3_ESLRef(c, x, buf ), buf, len);
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

#define EL_NAME   tas3_Status
#define EL_STRUCT zx_tas3_Status_s
#define EL_NS     tas3
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

/* FUNC(zx_LEN_SO_tas3_Status) */

/* Compute length of an element (and its subelements). The XML attributes
 * and elements are processed in schema order. */

/* Called by: */
int zx_LEN_SO_tas3_Status(struct zx_ctx* c, struct zx_tas3_Status_s* x )
{
  struct zx_ns_s* pop_seen = 0;
  struct zx_elem_s* se MAYBE_UNUSED;
#if 1 /* NORMALMODE */
  /* *** in simple_elem case should output ns prefix from ns node. */
  int len = sizeof("<tas3:Status")-1 + 1 + sizeof("</tas3:Status>")-1;
  if (c->inc_ns_len)
    len += zx_len_inc_ns(c, &pop_seen);
  if (x->actor || x->mustUnderstand)
    len += zx_len_xmlns_if_not_seen(c, zx_ns_tab+zx_xmlns_ix_e, &pop_seen);
  len += zx_len_xmlns_if_not_seen(c, zx_ns_tab+zx_xmlns_ix_tas3, &pop_seen);
  if (x->Id)
    len += zx_len_xmlns_if_not_seen(c, zx_ns_tab+zx_xmlns_ix_wsu, &pop_seen);

  len += zx_attr_so_len(x->code, sizeof("code")-1);
  len += zx_attr_so_len(x->comment, sizeof("comment")-1);
  len += zx_attr_so_len(x->ctlpt, sizeof("ctlpt")-1);
  len += zx_attr_so_len(x->id, sizeof("id")-1);
  len += zx_attr_so_len(x->ref, sizeof("ref")-1);
  len += zx_attr_so_len(x->Id, sizeof("wsu:Id")-1);
  len += zx_attr_so_len(x->actor, sizeof("e:actor")-1);
  len += zx_attr_so_len(x->mustUnderstand, sizeof("e:mustUnderstand")-1);

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
  ENC_LEN_DEBUG(x, "tas3:Status", len);
  return len;
}

/* FUNC(zx_LEN_WO_tas3_Status) */

/* Compute length of an element (and its subelements). The XML attributes
 * and elements are processed in wire order and no assumptions
 * are made about namespace prefixes. */

/* Called by: */
int zx_LEN_WO_tas3_Status(struct zx_ctx* c, struct zx_tas3_Status_s* x )
{
  struct zx_ns_s* pop_seen = 0;
  struct zx_elem_s* se MAYBE_UNUSED;
#if 1 /* NORMALMODE */
  int len = 1 + sizeof("Status")-1 + 1 + 2 + sizeof("Status")-1 + 1;
  
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

  len += zx_attr_wo_len(x->code, sizeof("code")-1);
  len += zx_attr_wo_len(x->comment, sizeof("comment")-1);
  len += zx_attr_wo_len(x->ctlpt, sizeof("ctlpt")-1);
  len += zx_attr_wo_len(x->id, sizeof("id")-1);
  len += zx_attr_wo_len(x->ref, sizeof("ref")-1);
  len += zx_attr_wo_len(x->Id, sizeof("Id")-1);
  len += zx_attr_wo_len(x->actor, sizeof("actor")-1);
  len += zx_attr_wo_len(x->mustUnderstand, sizeof("mustUnderstand")-1);

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
  ENC_LEN_DEBUG(x, "tas3:Status", len);
  return len;
}

/* FUNC(zx_ENC_SO_tas3_Status) */

/* Render element into string. The XML attributes and elements are
 * processed in schema order. This is what you generally want for
 * rendering new data structure to a string. The wo pointers are not used. */

/* Called by: */
char* zx_ENC_SO_tas3_Status(struct zx_ctx* c, struct zx_tas3_Status_s* x, char* p )
{
  struct zx_elem_s* se MAYBE_UNUSED;
  ENC_LEN_DEBUG_BASE;
#if 1 /* NORMALMODE */
  struct zx_ns_s* pop_seen = 0;
  /* *** in simple_elem case should output ns prefix from ns node. */
  ZX_OUT_TAG(p, "<tas3:Status");
  if (c->inc_ns)
    p = zx_enc_inc_ns(c, p, &pop_seen);
  if (x->actor || x->mustUnderstand)
    p = zx_enc_xmlns_if_not_seen(c, p, zx_ns_tab+zx_xmlns_ix_e, &pop_seen);
  p = zx_enc_xmlns_if_not_seen(c, p, zx_ns_tab+zx_xmlns_ix_tas3, &pop_seen);
  if (x->Id)
    p = zx_enc_xmlns_if_not_seen(c, p, zx_ns_tab+zx_xmlns_ix_wsu, &pop_seen);

  p = zx_attr_so_enc(p, x->code, " code=\"", sizeof(" code=\"")-1);
  p = zx_attr_so_enc(p, x->comment, " comment=\"", sizeof(" comment=\"")-1);
  p = zx_attr_so_enc(p, x->ctlpt, " ctlpt=\"", sizeof(" ctlpt=\"")-1);
  p = zx_attr_so_enc(p, x->id, " id=\"", sizeof(" id=\"")-1);
  p = zx_attr_so_enc(p, x->ref, " ref=\"", sizeof(" ref=\"")-1);
  p = zx_attr_so_enc(p, x->Id, " wsu:Id=\"", sizeof(" wsu:Id=\"")-1);
  p = zx_attr_so_enc(p, x->actor, " e:actor=\"", sizeof(" e:actor=\"")-1);
  p = zx_attr_so_enc(p, x->mustUnderstand, " e:mustUnderstand=\"", sizeof(" e:mustUnderstand=\"")-1);

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
  ZX_OUT_CLOSE_TAG(p, "</tas3:Status>");
  zx_pop_seen(pop_seen);
#else
  /* root node has no end tag either */
#endif
  ENC_LEN_DEBUG(x, "tas3:Status", p-enc_base);
  return p;
}

/* FUNC(zx_ENC_WO_tas3_Status) */

/* Render element into string. The XML attributes and elements are
 * processed in wire order by chasing wo pointers. This is what you want for
 * validating signatures on other people's XML documents. */

/* Called by: */
char* zx_ENC_WO_tas3_Status(struct zx_ctx* c, struct zx_tas3_Status_s* x, char* p )
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
  ZX_OUT_MEM(p, "Status", sizeof("Status")-1);
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
  p = zx_attr_wo_enc(p, x->code, "code=\"", sizeof("code=\"")-1);
  p = zx_attr_wo_enc(p, x->comment, "comment=\"", sizeof("comment=\"")-1);
  p = zx_attr_wo_enc(p, x->ctlpt, "ctlpt=\"", sizeof("ctlpt=\"")-1);
  p = zx_attr_wo_enc(p, x->id, "id=\"", sizeof("id=\"")-1);
  p = zx_attr_wo_enc(p, x->ref, "ref=\"", sizeof("ref=\"")-1);
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
  ENC_LEN_DEBUG(x, "tas3:Status", p-enc_base);
  return p;
}

/* FUNC(zx_EASY_ENC_SO_tas3_Status) */

/* Called by: */
struct zx_str* zx_EASY_ENC_SO_tas3_Status(struct zx_ctx* c, struct zx_tas3_Status_s* x )
{
  int len;
  char* buf;
  c->ns_tab = ZX_ALLOC(c, sizeof(zx_ns_tab));
  memcpy(c->ns_tab, zx_ns_tab, sizeof(zx_ns_tab));
  len = zx_LEN_SO_tas3_Status(c, x );
  buf = ZX_ALLOC(c, len+1);
  return zx_easy_enc_common(c, zx_ENC_SO_tas3_Status(c, x, buf ), buf, len);
}

/* FUNC(zx_EASY_ENC_WO_tas3_Status) */

/* Called by: */
struct zx_str* zx_EASY_ENC_WO_tas3_Status(struct zx_ctx* c, struct zx_tas3_Status_s* x )
{
  int len;
  char* buf;
  c->ns_tab = ZX_ALLOC(c, sizeof(zx_ns_tab));
  memcpy(c->ns_tab, zx_ns_tab, sizeof(zx_ns_tab));
  len = zx_LEN_WO_tas3_Status(c, x );
  buf = ZX_ALLOC(c, len+1);
  return zx_easy_enc_common(c, zx_ENC_WO_tas3_Status(c, x, buf ), buf, len);
}




/* EOF -- c/zx-tas3-enc.c */
