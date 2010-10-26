/* c/zx-ff12-enc.c - WARNING: This file was automatically generated. DO NOT EDIT!
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
#include "c/zx-ff12-data.h"
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

#define EL_NAME   ff12_Assertion
#define EL_STRUCT zx_ff12_Assertion_s
#define EL_NS     ff12
#define EL_TAG    Assertion

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

/* FUNC(zx_LEN_SO_ff12_Assertion) */

/* Compute length of an element (and its subelements). The XML attributes
 * and elements are processed in schema order. */

/* Called by: */
int zx_LEN_SO_ff12_Assertion(struct zx_ctx* c, struct zx_ff12_Assertion_s* x )
{
  struct zx_ns_s* pop_seen = 0;
  struct zx_elem_s* se MAYBE_UNUSED;
#if 1 /* NORMALMODE */
  /* *** in simple_elem case should output ns prefix from ns node. */
  int len = sizeof("<ff12:Assertion")-1 + 1 + sizeof("</ff12:Assertion>")-1;
  if (c->inc_ns_len)
    len += zx_len_inc_ns(c, &pop_seen);
  len += zx_len_xmlns_if_not_seen(c, zx_ns_tab+zx_xmlns_ix_ff12, &pop_seen);

  len += zx_attr_so_len(c, x->AssertionID, sizeof("AssertionID")-1, &pop_seen);
  len += zx_attr_so_len(c, x->InResponseTo, sizeof("InResponseTo")-1, &pop_seen);
  len += zx_attr_so_len(c, x->IssueInstant, sizeof("IssueInstant")-1, &pop_seen);
  len += zx_attr_so_len(c, x->Issuer, sizeof("Issuer")-1, &pop_seen);
  len += zx_attr_so_len(c, x->MajorVersion, sizeof("MajorVersion")-1, &pop_seen);
  len += zx_attr_so_len(c, x->MinorVersion, sizeof("MinorVersion")-1, &pop_seen);

#else
  /* root node has no begin tag */
  int len = 0;
#endif
  
  {
      struct zx_sa11_Conditions_s* e;
      for (e = x->Conditions; e; e = (struct zx_sa11_Conditions_s*)e->gg.g.n)
	  len += zx_LEN_SO_sa11_Conditions(c, e);
  }
  {
      struct zx_sa11_Advice_s* e;
      for (e = x->Advice; e; e = (struct zx_sa11_Advice_s*)e->gg.g.n)
	  len += zx_LEN_SO_sa11_Advice(c, e);
  }
  for (se = x->Statement; se; se = (struct zx_elem_s*)se->g.n)
    len += zx_LEN_SO_simple_elem(c,se, sizeof("sa11:Statement")-1, zx_ns_tab+zx_xmlns_ix_sa11);
  {
      struct zx_sa11_SubjectStatement_s* e;
      for (e = x->SubjectStatement; e; e = (struct zx_sa11_SubjectStatement_s*)e->gg.g.n)
	  len += zx_LEN_SO_sa11_SubjectStatement(c, e);
  }
  {
      struct zx_sa11_AuthenticationStatement_s* e;
      for (e = x->AuthenticationStatement; e; e = (struct zx_sa11_AuthenticationStatement_s*)e->gg.g.n)
	  len += zx_LEN_SO_sa11_AuthenticationStatement(c, e);
  }
  {
      struct zx_sa11_AuthorizationDecisionStatement_s* e;
      for (e = x->AuthorizationDecisionStatement; e; e = (struct zx_sa11_AuthorizationDecisionStatement_s*)e->gg.g.n)
	  len += zx_LEN_SO_sa11_AuthorizationDecisionStatement(c, e);
  }
  {
      struct zx_sa11_AttributeStatement_s* e;
      for (e = x->AttributeStatement; e; e = (struct zx_sa11_AttributeStatement_s*)e->gg.g.n)
	  len += zx_LEN_SO_sa11_AttributeStatement(c, e);
  }
  {
      struct zx_xasa_XACMLAuthzDecisionStatement_s* e;
      for (e = x->XACMLAuthzDecisionStatement; e; e = (struct zx_xasa_XACMLAuthzDecisionStatement_s*)e->gg.g.n)
	  len += zx_LEN_SO_xasa_XACMLAuthzDecisionStatement(c, e);
  }
  {
      struct zx_xasa_XACMLPolicyStatement_s* e;
      for (e = x->XACMLPolicyStatement; e; e = (struct zx_xasa_XACMLPolicyStatement_s*)e->gg.g.n)
	  len += zx_LEN_SO_xasa_XACMLPolicyStatement(c, e);
  }
  {
      struct zx_xasacd1_XACMLAuthzDecisionStatement_s* e;
      for (e = x->xasacd1_XACMLAuthzDecisionStatement; e; e = (struct zx_xasacd1_XACMLAuthzDecisionStatement_s*)e->gg.g.n)
	  len += zx_LEN_SO_xasacd1_XACMLAuthzDecisionStatement(c, e);
  }
  {
      struct zx_xasacd1_XACMLPolicyStatement_s* e;
      for (e = x->xasacd1_XACMLPolicyStatement; e; e = (struct zx_xasacd1_XACMLPolicyStatement_s*)e->gg.g.n)
	  len += zx_LEN_SO_xasacd1_XACMLPolicyStatement(c, e);
  }
  {
      struct zx_ds_Signature_s* e;
      for (e = x->Signature; e; e = (struct zx_ds_Signature_s*)e->gg.g.n)
	  if (e != c->exclude_sig)
              len += zx_LEN_SO_ds_Signature(c, e);
  }


  len += zx_len_so_common(c, &x->gg, &pop_seen);
  zx_pop_seen(pop_seen);
  ENC_LEN_DEBUG(x, "ff12:Assertion", len);
  return len;
}

/* FUNC(zx_LEN_WO_ff12_Assertion) */

/* Compute length of an element (and its subelements). The XML attributes
 * and elements are processed in wire order and no assumptions
 * are made about namespace prefixes. */

/* Called by: */
int zx_LEN_WO_ff12_Assertion(struct zx_ctx* c, struct zx_ff12_Assertion_s* x )
{
  struct zx_ns_s* pop_seen = 0;
  struct zx_elem_s* se MAYBE_UNUSED;
#if 1 /* NORMALMODE */
  int len = 1 + sizeof("Assertion")-1 + 1 + 2 + sizeof("Assertion")-1 + 1;
  
  if (x->gg.g.ns && x->gg.g.ns->prefix_len)
    len += (x->gg.g.ns->prefix_len + 1) * 2;
  if (c->inc_ns_len)
    len += zx_len_inc_ns(c, &pop_seen);
  len += zx_len_xmlns_if_not_seen(c, x->gg.g.ns, &pop_seen);

  len += zx_attr_wo_len(c, x->AssertionID, sizeof("AssertionID")-1, &pop_seen);
  len += zx_attr_wo_len(c, x->InResponseTo, sizeof("InResponseTo")-1, &pop_seen);
  len += zx_attr_wo_len(c, x->IssueInstant, sizeof("IssueInstant")-1, &pop_seen);
  len += zx_attr_wo_len(c, x->Issuer, sizeof("Issuer")-1, &pop_seen);
  len += zx_attr_wo_len(c, x->MajorVersion, sizeof("MajorVersion")-1, &pop_seen);
  len += zx_attr_wo_len(c, x->MinorVersion, sizeof("MinorVersion")-1, &pop_seen);

#else
  /* root node has no begin tag */
  int len = 0;
#endif
  
  {
      struct zx_sa11_Conditions_s* e;
      for (e = x->Conditions; e; e = (struct zx_sa11_Conditions_s*)e->gg.g.n)
	  len += zx_LEN_WO_sa11_Conditions(c, e);
  }
  {
      struct zx_sa11_Advice_s* e;
      for (e = x->Advice; e; e = (struct zx_sa11_Advice_s*)e->gg.g.n)
	  len += zx_LEN_WO_sa11_Advice(c, e);
  }
  for (se = x->Statement; se; se = (struct zx_elem_s*)se->g.n)
    len += zx_LEN_WO_simple_elem(c, se, sizeof("Statement")-1);
  {
      struct zx_sa11_SubjectStatement_s* e;
      for (e = x->SubjectStatement; e; e = (struct zx_sa11_SubjectStatement_s*)e->gg.g.n)
	  len += zx_LEN_WO_sa11_SubjectStatement(c, e);
  }
  {
      struct zx_sa11_AuthenticationStatement_s* e;
      for (e = x->AuthenticationStatement; e; e = (struct zx_sa11_AuthenticationStatement_s*)e->gg.g.n)
	  len += zx_LEN_WO_sa11_AuthenticationStatement(c, e);
  }
  {
      struct zx_sa11_AuthorizationDecisionStatement_s* e;
      for (e = x->AuthorizationDecisionStatement; e; e = (struct zx_sa11_AuthorizationDecisionStatement_s*)e->gg.g.n)
	  len += zx_LEN_WO_sa11_AuthorizationDecisionStatement(c, e);
  }
  {
      struct zx_sa11_AttributeStatement_s* e;
      for (e = x->AttributeStatement; e; e = (struct zx_sa11_AttributeStatement_s*)e->gg.g.n)
	  len += zx_LEN_WO_sa11_AttributeStatement(c, e);
  }
  {
      struct zx_xasa_XACMLAuthzDecisionStatement_s* e;
      for (e = x->XACMLAuthzDecisionStatement; e; e = (struct zx_xasa_XACMLAuthzDecisionStatement_s*)e->gg.g.n)
	  len += zx_LEN_WO_xasa_XACMLAuthzDecisionStatement(c, e);
  }
  {
      struct zx_xasa_XACMLPolicyStatement_s* e;
      for (e = x->XACMLPolicyStatement; e; e = (struct zx_xasa_XACMLPolicyStatement_s*)e->gg.g.n)
	  len += zx_LEN_WO_xasa_XACMLPolicyStatement(c, e);
  }
  {
      struct zx_xasacd1_XACMLAuthzDecisionStatement_s* e;
      for (e = x->xasacd1_XACMLAuthzDecisionStatement; e; e = (struct zx_xasacd1_XACMLAuthzDecisionStatement_s*)e->gg.g.n)
	  len += zx_LEN_WO_xasacd1_XACMLAuthzDecisionStatement(c, e);
  }
  {
      struct zx_xasacd1_XACMLPolicyStatement_s* e;
      for (e = x->xasacd1_XACMLPolicyStatement; e; e = (struct zx_xasacd1_XACMLPolicyStatement_s*)e->gg.g.n)
	  len += zx_LEN_WO_xasacd1_XACMLPolicyStatement(c, e);
  }
  {
      struct zx_ds_Signature_s* e;
      for (e = x->Signature; e; e = (struct zx_ds_Signature_s*)e->gg.g.n)
	  if (e != c->exclude_sig)
              len += zx_LEN_WO_ds_Signature(c, e);
  }


  len += zx_len_wo_common(c, &x->gg, &pop_seen); 
  zx_pop_seen(pop_seen);
  ENC_LEN_DEBUG(x, "ff12:Assertion", len);
  return len;
}

/* FUNC(zx_ENC_SO_ff12_Assertion) */

/* Render element into string. The XML attributes and elements are
 * processed in schema order. This is what you generally want for
 * rendering new data structure to a string. The wo pointers are not used. */

/* Called by: */
char* zx_ENC_SO_ff12_Assertion(struct zx_ctx* c, struct zx_ff12_Assertion_s* x, char* p )
{
  struct zx_elem_s* se MAYBE_UNUSED;
  struct zx_ns_s* pop_seen = 0;
  ENC_LEN_DEBUG_BASE;
#if 1 /* NORMALMODE */
  /* *** in simple_elem case should output ns prefix from ns node. */
  ZX_OUT_TAG(p, "<ff12:Assertion");
  if (c->inc_ns)
    zx_add_inc_ns(c, &pop_seen);
  zx_add_xmlns_if_not_seen(c, zx_ns_tab+zx_xmlns_ix_ff12, &pop_seen);

  zx_see_unknown_attrs_ns(c, x->gg.any_attr, &pop_seen);
  p = zx_enc_seen(p, pop_seen); 
  p = zx_attr_so_enc(p, x->AssertionID, " AssertionID=\"", sizeof(" AssertionID=\"")-1);
  p = zx_attr_so_enc(p, x->InResponseTo, " InResponseTo=\"", sizeof(" InResponseTo=\"")-1);
  p = zx_attr_so_enc(p, x->IssueInstant, " IssueInstant=\"", sizeof(" IssueInstant=\"")-1);
  p = zx_attr_so_enc(p, x->Issuer, " Issuer=\"", sizeof(" Issuer=\"")-1);
  p = zx_attr_so_enc(p, x->MajorVersion, " MajorVersion=\"", sizeof(" MajorVersion=\"")-1);
  p = zx_attr_so_enc(p, x->MinorVersion, " MinorVersion=\"", sizeof(" MinorVersion=\"")-1);

  p = zx_enc_unknown_attrs(p, x->gg.any_attr);
#else
  /* root node has no begin tag */
#endif
  
  {
      struct zx_sa11_Conditions_s* e;
      for (e = x->Conditions; e; e = (struct zx_sa11_Conditions_s*)e->gg.g.n)
	  p = zx_ENC_SO_sa11_Conditions(c, e, p);
  }
  {
      struct zx_sa11_Advice_s* e;
      for (e = x->Advice; e; e = (struct zx_sa11_Advice_s*)e->gg.g.n)
	  p = zx_ENC_SO_sa11_Advice(c, e, p);
  }
  for (se = x->Statement; se; se = (struct zx_elem_s*)se->g.n)
    p = zx_ENC_SO_simple_elem(c, se, p, "sa11:Statement", sizeof("sa11:Statement")-1, zx_ns_tab+zx_xmlns_ix_sa11);
  {
      struct zx_sa11_SubjectStatement_s* e;
      for (e = x->SubjectStatement; e; e = (struct zx_sa11_SubjectStatement_s*)e->gg.g.n)
	  p = zx_ENC_SO_sa11_SubjectStatement(c, e, p);
  }
  {
      struct zx_sa11_AuthenticationStatement_s* e;
      for (e = x->AuthenticationStatement; e; e = (struct zx_sa11_AuthenticationStatement_s*)e->gg.g.n)
	  p = zx_ENC_SO_sa11_AuthenticationStatement(c, e, p);
  }
  {
      struct zx_sa11_AuthorizationDecisionStatement_s* e;
      for (e = x->AuthorizationDecisionStatement; e; e = (struct zx_sa11_AuthorizationDecisionStatement_s*)e->gg.g.n)
	  p = zx_ENC_SO_sa11_AuthorizationDecisionStatement(c, e, p);
  }
  {
      struct zx_sa11_AttributeStatement_s* e;
      for (e = x->AttributeStatement; e; e = (struct zx_sa11_AttributeStatement_s*)e->gg.g.n)
	  p = zx_ENC_SO_sa11_AttributeStatement(c, e, p);
  }
  {
      struct zx_xasa_XACMLAuthzDecisionStatement_s* e;
      for (e = x->XACMLAuthzDecisionStatement; e; e = (struct zx_xasa_XACMLAuthzDecisionStatement_s*)e->gg.g.n)
	  p = zx_ENC_SO_xasa_XACMLAuthzDecisionStatement(c, e, p);
  }
  {
      struct zx_xasa_XACMLPolicyStatement_s* e;
      for (e = x->XACMLPolicyStatement; e; e = (struct zx_xasa_XACMLPolicyStatement_s*)e->gg.g.n)
	  p = zx_ENC_SO_xasa_XACMLPolicyStatement(c, e, p);
  }
  {
      struct zx_xasacd1_XACMLAuthzDecisionStatement_s* e;
      for (e = x->xasacd1_XACMLAuthzDecisionStatement; e; e = (struct zx_xasacd1_XACMLAuthzDecisionStatement_s*)e->gg.g.n)
	  p = zx_ENC_SO_xasacd1_XACMLAuthzDecisionStatement(c, e, p);
  }
  {
      struct zx_xasacd1_XACMLPolicyStatement_s* e;
      for (e = x->xasacd1_XACMLPolicyStatement; e; e = (struct zx_xasacd1_XACMLPolicyStatement_s*)e->gg.g.n)
	  p = zx_ENC_SO_xasacd1_XACMLPolicyStatement(c, e, p);
  }
  {
      struct zx_ds_Signature_s* e;
      for (e = x->Signature; e; e = (struct zx_ds_Signature_s*)e->gg.g.n)
	  if (e != c->exclude_sig)
              p = zx_ENC_SO_ds_Signature(c, e, p);
  }

  p = zx_enc_so_unknown_elems_and_content(c, p, &x->gg);
  
#if 1 /* NORMALMODE */
  ZX_OUT_CLOSE_TAG(p, "</ff12:Assertion>");
  zx_pop_seen(pop_seen);
#else
  /* root node has no end tag either */
#endif
  ENC_LEN_DEBUG(x, "ff12:Assertion", p-enc_base);
  return p;
}

/* FUNC(zx_ENC_WO_ff12_Assertion) */

/* Render element into string. The XML attributes and elements are
 * processed in wire order by chasing wo pointers. This is what you want for
 * validating signatures on other people's XML documents. */

/* Called by: */
char* zx_ENC_WO_ff12_Assertion(struct zx_ctx* c, struct zx_ff12_Assertion_s* x, char* p )
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
  ZX_OUT_MEM(p, "Assertion", sizeof("Assertion")-1);
  qq = p;

  if (c->inc_ns)
    zx_add_inc_ns(c, &pop_seen);
  zx_add_xmlns_if_not_seen(c, x->gg.g.ns, &pop_seen);

  zx_see_unknown_attrs_ns(c, x->gg.any_attr, &pop_seen);
  p = zx_enc_seen(p, pop_seen); 
  p = zx_attr_wo_enc(p, x->AssertionID, "AssertionID=\"", sizeof("AssertionID=\"")-1);
  p = zx_attr_wo_enc(p, x->InResponseTo, "InResponseTo=\"", sizeof("InResponseTo=\"")-1);
  p = zx_attr_wo_enc(p, x->IssueInstant, "IssueInstant=\"", sizeof("IssueInstant=\"")-1);
  p = zx_attr_wo_enc(p, x->Issuer, "Issuer=\"", sizeof("Issuer=\"")-1);
  p = zx_attr_wo_enc(p, x->MajorVersion, "MajorVersion=\"", sizeof("MajorVersion=\"")-1);
  p = zx_attr_wo_enc(p, x->MinorVersion, "MinorVersion=\"", sizeof("MinorVersion=\"")-1);

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
  ENC_LEN_DEBUG(x, "ff12:Assertion", p-enc_base);
  return p;
}

/* FUNC(zx_EASY_ENC_SO_ff12_Assertion) */

/* Called by: */
struct zx_str* zx_EASY_ENC_SO_ff12_Assertion(struct zx_ctx* c, struct zx_ff12_Assertion_s* x )
{
  int len;
  char* buf;
  c->ns_tab = ZX_ALLOC(c, sizeof(zx_ns_tab));
  memcpy(c->ns_tab, zx_ns_tab, sizeof(zx_ns_tab));
  len = zx_LEN_SO_ff12_Assertion(c, x );
  buf = ZX_ALLOC(c, len+1);
  return zx_easy_enc_common(c, zx_ENC_SO_ff12_Assertion(c, x, buf ), buf, len);
}

/* FUNC(zx_EASY_ENC_WO_ff12_Assertion) */

/* Called by: */
struct zx_str* zx_EASY_ENC_WO_ff12_Assertion(struct zx_ctx* c, struct zx_ff12_Assertion_s* x )
{
  int len;
  char* buf;
  c->ns_tab = ZX_ALLOC(c, sizeof(zx_ns_tab));
  memcpy(c->ns_tab, zx_ns_tab, sizeof(zx_ns_tab));
  len = zx_LEN_WO_ff12_Assertion(c, x );
  buf = ZX_ALLOC(c, len+1);
  return zx_easy_enc_common(c, zx_ENC_WO_ff12_Assertion(c, x, buf ), buf, len);
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

#define EL_NAME   ff12_AuthenticationStatement
#define EL_STRUCT zx_ff12_AuthenticationStatement_s
#define EL_NS     ff12
#define EL_TAG    AuthenticationStatement

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

/* FUNC(zx_LEN_SO_ff12_AuthenticationStatement) */

/* Compute length of an element (and its subelements). The XML attributes
 * and elements are processed in schema order. */

/* Called by: */
int zx_LEN_SO_ff12_AuthenticationStatement(struct zx_ctx* c, struct zx_ff12_AuthenticationStatement_s* x )
{
  struct zx_ns_s* pop_seen = 0;
  struct zx_elem_s* se MAYBE_UNUSED;
#if 1 /* NORMALMODE */
  /* *** in simple_elem case should output ns prefix from ns node. */
  int len = sizeof("<ff12:AuthenticationStatement")-1 + 1 + sizeof("</ff12:AuthenticationStatement>")-1;
  if (c->inc_ns_len)
    len += zx_len_inc_ns(c, &pop_seen);
  len += zx_len_xmlns_if_not_seen(c, zx_ns_tab+zx_xmlns_ix_ff12, &pop_seen);

  len += zx_attr_so_len(c, x->AuthenticationInstant, sizeof("AuthenticationInstant")-1, &pop_seen);
  len += zx_attr_so_len(c, x->AuthenticationMethod, sizeof("AuthenticationMethod")-1, &pop_seen);
  len += zx_attr_so_len(c, x->ReauthenticateOnOrAfter, sizeof("ReauthenticateOnOrAfter")-1, &pop_seen);
  len += zx_attr_so_len(c, x->SessionIndex, sizeof("SessionIndex")-1, &pop_seen);

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
      struct zx_sa11_SubjectLocality_s* e;
      for (e = x->SubjectLocality; e; e = (struct zx_sa11_SubjectLocality_s*)e->gg.g.n)
	  len += zx_LEN_SO_sa11_SubjectLocality(c, e);
  }
  {
      struct zx_sa11_AuthorityBinding_s* e;
      for (e = x->AuthorityBinding; e; e = (struct zx_sa11_AuthorityBinding_s*)e->gg.g.n)
	  len += zx_LEN_SO_sa11_AuthorityBinding(c, e);
  }
  {
      struct zx_ff12_AuthnContext_s* e;
      for (e = x->AuthnContext; e; e = (struct zx_ff12_AuthnContext_s*)e->gg.g.n)
	  len += zx_LEN_SO_ff12_AuthnContext(c, e);
  }


  len += zx_len_so_common(c, &x->gg, &pop_seen);
  zx_pop_seen(pop_seen);
  ENC_LEN_DEBUG(x, "ff12:AuthenticationStatement", len);
  return len;
}

/* FUNC(zx_LEN_WO_ff12_AuthenticationStatement) */

/* Compute length of an element (and its subelements). The XML attributes
 * and elements are processed in wire order and no assumptions
 * are made about namespace prefixes. */

/* Called by: */
int zx_LEN_WO_ff12_AuthenticationStatement(struct zx_ctx* c, struct zx_ff12_AuthenticationStatement_s* x )
{
  struct zx_ns_s* pop_seen = 0;
  struct zx_elem_s* se MAYBE_UNUSED;
#if 1 /* NORMALMODE */
  int len = 1 + sizeof("AuthenticationStatement")-1 + 1 + 2 + sizeof("AuthenticationStatement")-1 + 1;
  
  if (x->gg.g.ns && x->gg.g.ns->prefix_len)
    len += (x->gg.g.ns->prefix_len + 1) * 2;
  if (c->inc_ns_len)
    len += zx_len_inc_ns(c, &pop_seen);
  len += zx_len_xmlns_if_not_seen(c, x->gg.g.ns, &pop_seen);

  len += zx_attr_wo_len(c, x->AuthenticationInstant, sizeof("AuthenticationInstant")-1, &pop_seen);
  len += zx_attr_wo_len(c, x->AuthenticationMethod, sizeof("AuthenticationMethod")-1, &pop_seen);
  len += zx_attr_wo_len(c, x->ReauthenticateOnOrAfter, sizeof("ReauthenticateOnOrAfter")-1, &pop_seen);
  len += zx_attr_wo_len(c, x->SessionIndex, sizeof("SessionIndex")-1, &pop_seen);

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
      struct zx_sa11_SubjectLocality_s* e;
      for (e = x->SubjectLocality; e; e = (struct zx_sa11_SubjectLocality_s*)e->gg.g.n)
	  len += zx_LEN_WO_sa11_SubjectLocality(c, e);
  }
  {
      struct zx_sa11_AuthorityBinding_s* e;
      for (e = x->AuthorityBinding; e; e = (struct zx_sa11_AuthorityBinding_s*)e->gg.g.n)
	  len += zx_LEN_WO_sa11_AuthorityBinding(c, e);
  }
  {
      struct zx_ff12_AuthnContext_s* e;
      for (e = x->AuthnContext; e; e = (struct zx_ff12_AuthnContext_s*)e->gg.g.n)
	  len += zx_LEN_WO_ff12_AuthnContext(c, e);
  }


  len += zx_len_wo_common(c, &x->gg, &pop_seen); 
  zx_pop_seen(pop_seen);
  ENC_LEN_DEBUG(x, "ff12:AuthenticationStatement", len);
  return len;
}

/* FUNC(zx_ENC_SO_ff12_AuthenticationStatement) */

/* Render element into string. The XML attributes and elements are
 * processed in schema order. This is what you generally want for
 * rendering new data structure to a string. The wo pointers are not used. */

/* Called by: */
char* zx_ENC_SO_ff12_AuthenticationStatement(struct zx_ctx* c, struct zx_ff12_AuthenticationStatement_s* x, char* p )
{
  struct zx_elem_s* se MAYBE_UNUSED;
  struct zx_ns_s* pop_seen = 0;
  ENC_LEN_DEBUG_BASE;
#if 1 /* NORMALMODE */
  /* *** in simple_elem case should output ns prefix from ns node. */
  ZX_OUT_TAG(p, "<ff12:AuthenticationStatement");
  if (c->inc_ns)
    zx_add_inc_ns(c, &pop_seen);
  zx_add_xmlns_if_not_seen(c, zx_ns_tab+zx_xmlns_ix_ff12, &pop_seen);

  zx_see_unknown_attrs_ns(c, x->gg.any_attr, &pop_seen);
  p = zx_enc_seen(p, pop_seen); 
  p = zx_attr_so_enc(p, x->AuthenticationInstant, " AuthenticationInstant=\"", sizeof(" AuthenticationInstant=\"")-1);
  p = zx_attr_so_enc(p, x->AuthenticationMethod, " AuthenticationMethod=\"", sizeof(" AuthenticationMethod=\"")-1);
  p = zx_attr_so_enc(p, x->ReauthenticateOnOrAfter, " ReauthenticateOnOrAfter=\"", sizeof(" ReauthenticateOnOrAfter=\"")-1);
  p = zx_attr_so_enc(p, x->SessionIndex, " SessionIndex=\"", sizeof(" SessionIndex=\"")-1);

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
      struct zx_sa11_SubjectLocality_s* e;
      for (e = x->SubjectLocality; e; e = (struct zx_sa11_SubjectLocality_s*)e->gg.g.n)
	  p = zx_ENC_SO_sa11_SubjectLocality(c, e, p);
  }
  {
      struct zx_sa11_AuthorityBinding_s* e;
      for (e = x->AuthorityBinding; e; e = (struct zx_sa11_AuthorityBinding_s*)e->gg.g.n)
	  p = zx_ENC_SO_sa11_AuthorityBinding(c, e, p);
  }
  {
      struct zx_ff12_AuthnContext_s* e;
      for (e = x->AuthnContext; e; e = (struct zx_ff12_AuthnContext_s*)e->gg.g.n)
	  p = zx_ENC_SO_ff12_AuthnContext(c, e, p);
  }

  p = zx_enc_so_unknown_elems_and_content(c, p, &x->gg);
  
#if 1 /* NORMALMODE */
  ZX_OUT_CLOSE_TAG(p, "</ff12:AuthenticationStatement>");
  zx_pop_seen(pop_seen);
#else
  /* root node has no end tag either */
#endif
  ENC_LEN_DEBUG(x, "ff12:AuthenticationStatement", p-enc_base);
  return p;
}

/* FUNC(zx_ENC_WO_ff12_AuthenticationStatement) */

/* Render element into string. The XML attributes and elements are
 * processed in wire order by chasing wo pointers. This is what you want for
 * validating signatures on other people's XML documents. */

/* Called by: */
char* zx_ENC_WO_ff12_AuthenticationStatement(struct zx_ctx* c, struct zx_ff12_AuthenticationStatement_s* x, char* p )
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
  ZX_OUT_MEM(p, "AuthenticationStatement", sizeof("AuthenticationStatement")-1);
  qq = p;

  if (c->inc_ns)
    zx_add_inc_ns(c, &pop_seen);
  zx_add_xmlns_if_not_seen(c, x->gg.g.ns, &pop_seen);

  zx_see_unknown_attrs_ns(c, x->gg.any_attr, &pop_seen);
  p = zx_enc_seen(p, pop_seen); 
  p = zx_attr_wo_enc(p, x->AuthenticationInstant, "AuthenticationInstant=\"", sizeof("AuthenticationInstant=\"")-1);
  p = zx_attr_wo_enc(p, x->AuthenticationMethod, "AuthenticationMethod=\"", sizeof("AuthenticationMethod=\"")-1);
  p = zx_attr_wo_enc(p, x->ReauthenticateOnOrAfter, "ReauthenticateOnOrAfter=\"", sizeof("ReauthenticateOnOrAfter=\"")-1);
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
  ENC_LEN_DEBUG(x, "ff12:AuthenticationStatement", p-enc_base);
  return p;
}

/* FUNC(zx_EASY_ENC_SO_ff12_AuthenticationStatement) */

/* Called by: */
struct zx_str* zx_EASY_ENC_SO_ff12_AuthenticationStatement(struct zx_ctx* c, struct zx_ff12_AuthenticationStatement_s* x )
{
  int len;
  char* buf;
  c->ns_tab = ZX_ALLOC(c, sizeof(zx_ns_tab));
  memcpy(c->ns_tab, zx_ns_tab, sizeof(zx_ns_tab));
  len = zx_LEN_SO_ff12_AuthenticationStatement(c, x );
  buf = ZX_ALLOC(c, len+1);
  return zx_easy_enc_common(c, zx_ENC_SO_ff12_AuthenticationStatement(c, x, buf ), buf, len);
}

/* FUNC(zx_EASY_ENC_WO_ff12_AuthenticationStatement) */

/* Called by: */
struct zx_str* zx_EASY_ENC_WO_ff12_AuthenticationStatement(struct zx_ctx* c, struct zx_ff12_AuthenticationStatement_s* x )
{
  int len;
  char* buf;
  c->ns_tab = ZX_ALLOC(c, sizeof(zx_ns_tab));
  memcpy(c->ns_tab, zx_ns_tab, sizeof(zx_ns_tab));
  len = zx_LEN_WO_ff12_AuthenticationStatement(c, x );
  buf = ZX_ALLOC(c, len+1);
  return zx_easy_enc_common(c, zx_ENC_WO_ff12_AuthenticationStatement(c, x, buf ), buf, len);
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

#define EL_NAME   ff12_AuthnContext
#define EL_STRUCT zx_ff12_AuthnContext_s
#define EL_NS     ff12
#define EL_TAG    AuthnContext

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

/* FUNC(zx_LEN_SO_ff12_AuthnContext) */

/* Compute length of an element (and its subelements). The XML attributes
 * and elements are processed in schema order. */

/* Called by: */
int zx_LEN_SO_ff12_AuthnContext(struct zx_ctx* c, struct zx_ff12_AuthnContext_s* x )
{
  struct zx_ns_s* pop_seen = 0;
  struct zx_elem_s* se MAYBE_UNUSED;
#if 1 /* NORMALMODE */
  /* *** in simple_elem case should output ns prefix from ns node. */
  int len = sizeof("<ff12:AuthnContext")-1 + 1 + sizeof("</ff12:AuthnContext>")-1;
  if (c->inc_ns_len)
    len += zx_len_inc_ns(c, &pop_seen);
  len += zx_len_xmlns_if_not_seen(c, zx_ns_tab+zx_xmlns_ix_ff12, &pop_seen);


#else
  /* root node has no begin tag */
  int len = 0;
#endif
  
  for (se = x->AuthnContextClassRef; se; se = (struct zx_elem_s*)se->g.n)
    len += zx_LEN_SO_simple_elem(c,se, sizeof("ff12:AuthnContextClassRef")-1, zx_ns_tab+zx_xmlns_ix_ff12);
  {
      struct zx_ac_AuthenticationContextStatement_s* e;
      for (e = x->AuthenticationContextStatement; e; e = (struct zx_ac_AuthenticationContextStatement_s*)e->gg.g.n)
	  len += zx_LEN_SO_ac_AuthenticationContextStatement(c, e);
  }
  for (se = x->AuthnContextStatementRef; se; se = (struct zx_elem_s*)se->g.n)
    len += zx_LEN_SO_simple_elem(c,se, sizeof("ff12:AuthnContextStatementRef")-1, zx_ns_tab+zx_xmlns_ix_ff12);


  len += zx_len_so_common(c, &x->gg, &pop_seen);
  zx_pop_seen(pop_seen);
  ENC_LEN_DEBUG(x, "ff12:AuthnContext", len);
  return len;
}

/* FUNC(zx_LEN_WO_ff12_AuthnContext) */

/* Compute length of an element (and its subelements). The XML attributes
 * and elements are processed in wire order and no assumptions
 * are made about namespace prefixes. */

/* Called by: */
int zx_LEN_WO_ff12_AuthnContext(struct zx_ctx* c, struct zx_ff12_AuthnContext_s* x )
{
  struct zx_ns_s* pop_seen = 0;
  struct zx_elem_s* se MAYBE_UNUSED;
#if 1 /* NORMALMODE */
  int len = 1 + sizeof("AuthnContext")-1 + 1 + 2 + sizeof("AuthnContext")-1 + 1;
  
  if (x->gg.g.ns && x->gg.g.ns->prefix_len)
    len += (x->gg.g.ns->prefix_len + 1) * 2;
  if (c->inc_ns_len)
    len += zx_len_inc_ns(c, &pop_seen);
  len += zx_len_xmlns_if_not_seen(c, x->gg.g.ns, &pop_seen);


#else
  /* root node has no begin tag */
  int len = 0;
#endif
  
  for (se = x->AuthnContextClassRef; se; se = (struct zx_elem_s*)se->g.n)
    len += zx_LEN_WO_simple_elem(c, se, sizeof("AuthnContextClassRef")-1);
  {
      struct zx_ac_AuthenticationContextStatement_s* e;
      for (e = x->AuthenticationContextStatement; e; e = (struct zx_ac_AuthenticationContextStatement_s*)e->gg.g.n)
	  len += zx_LEN_WO_ac_AuthenticationContextStatement(c, e);
  }
  for (se = x->AuthnContextStatementRef; se; se = (struct zx_elem_s*)se->g.n)
    len += zx_LEN_WO_simple_elem(c, se, sizeof("AuthnContextStatementRef")-1);


  len += zx_len_wo_common(c, &x->gg, &pop_seen); 
  zx_pop_seen(pop_seen);
  ENC_LEN_DEBUG(x, "ff12:AuthnContext", len);
  return len;
}

/* FUNC(zx_ENC_SO_ff12_AuthnContext) */

/* Render element into string. The XML attributes and elements are
 * processed in schema order. This is what you generally want for
 * rendering new data structure to a string. The wo pointers are not used. */

/* Called by: */
char* zx_ENC_SO_ff12_AuthnContext(struct zx_ctx* c, struct zx_ff12_AuthnContext_s* x, char* p )
{
  struct zx_elem_s* se MAYBE_UNUSED;
  struct zx_ns_s* pop_seen = 0;
  ENC_LEN_DEBUG_BASE;
#if 1 /* NORMALMODE */
  /* *** in simple_elem case should output ns prefix from ns node. */
  ZX_OUT_TAG(p, "<ff12:AuthnContext");
  if (c->inc_ns)
    zx_add_inc_ns(c, &pop_seen);
  zx_add_xmlns_if_not_seen(c, zx_ns_tab+zx_xmlns_ix_ff12, &pop_seen);

  zx_see_unknown_attrs_ns(c, x->gg.any_attr, &pop_seen);
  p = zx_enc_seen(p, pop_seen); 

  p = zx_enc_unknown_attrs(p, x->gg.any_attr);
#else
  /* root node has no begin tag */
#endif
  
  for (se = x->AuthnContextClassRef; se; se = (struct zx_elem_s*)se->g.n)
    p = zx_ENC_SO_simple_elem(c, se, p, "ff12:AuthnContextClassRef", sizeof("ff12:AuthnContextClassRef")-1, zx_ns_tab+zx_xmlns_ix_ff12);
  {
      struct zx_ac_AuthenticationContextStatement_s* e;
      for (e = x->AuthenticationContextStatement; e; e = (struct zx_ac_AuthenticationContextStatement_s*)e->gg.g.n)
	  p = zx_ENC_SO_ac_AuthenticationContextStatement(c, e, p);
  }
  for (se = x->AuthnContextStatementRef; se; se = (struct zx_elem_s*)se->g.n)
    p = zx_ENC_SO_simple_elem(c, se, p, "ff12:AuthnContextStatementRef", sizeof("ff12:AuthnContextStatementRef")-1, zx_ns_tab+zx_xmlns_ix_ff12);

  p = zx_enc_so_unknown_elems_and_content(c, p, &x->gg);
  
#if 1 /* NORMALMODE */
  ZX_OUT_CLOSE_TAG(p, "</ff12:AuthnContext>");
  zx_pop_seen(pop_seen);
#else
  /* root node has no end tag either */
#endif
  ENC_LEN_DEBUG(x, "ff12:AuthnContext", p-enc_base);
  return p;
}

/* FUNC(zx_ENC_WO_ff12_AuthnContext) */

/* Render element into string. The XML attributes and elements are
 * processed in wire order by chasing wo pointers. This is what you want for
 * validating signatures on other people's XML documents. */

/* Called by: */
char* zx_ENC_WO_ff12_AuthnContext(struct zx_ctx* c, struct zx_ff12_AuthnContext_s* x, char* p )
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
  ZX_OUT_MEM(p, "AuthnContext", sizeof("AuthnContext")-1);
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
  ENC_LEN_DEBUG(x, "ff12:AuthnContext", p-enc_base);
  return p;
}

/* FUNC(zx_EASY_ENC_SO_ff12_AuthnContext) */

/* Called by: */
struct zx_str* zx_EASY_ENC_SO_ff12_AuthnContext(struct zx_ctx* c, struct zx_ff12_AuthnContext_s* x )
{
  int len;
  char* buf;
  c->ns_tab = ZX_ALLOC(c, sizeof(zx_ns_tab));
  memcpy(c->ns_tab, zx_ns_tab, sizeof(zx_ns_tab));
  len = zx_LEN_SO_ff12_AuthnContext(c, x );
  buf = ZX_ALLOC(c, len+1);
  return zx_easy_enc_common(c, zx_ENC_SO_ff12_AuthnContext(c, x, buf ), buf, len);
}

/* FUNC(zx_EASY_ENC_WO_ff12_AuthnContext) */

/* Called by: */
struct zx_str* zx_EASY_ENC_WO_ff12_AuthnContext(struct zx_ctx* c, struct zx_ff12_AuthnContext_s* x )
{
  int len;
  char* buf;
  c->ns_tab = ZX_ALLOC(c, sizeof(zx_ns_tab));
  memcpy(c->ns_tab, zx_ns_tab, sizeof(zx_ns_tab));
  len = zx_LEN_WO_ff12_AuthnContext(c, x );
  buf = ZX_ALLOC(c, len+1);
  return zx_easy_enc_common(c, zx_ENC_WO_ff12_AuthnContext(c, x, buf ), buf, len);
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

#define EL_NAME   ff12_AuthnRequest
#define EL_STRUCT zx_ff12_AuthnRequest_s
#define EL_NS     ff12
#define EL_TAG    AuthnRequest

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

/* FUNC(zx_LEN_SO_ff12_AuthnRequest) */

/* Compute length of an element (and its subelements). The XML attributes
 * and elements are processed in schema order. */

/* Called by: */
int zx_LEN_SO_ff12_AuthnRequest(struct zx_ctx* c, struct zx_ff12_AuthnRequest_s* x )
{
  struct zx_ns_s* pop_seen = 0;
  struct zx_elem_s* se MAYBE_UNUSED;
#if 1 /* NORMALMODE */
  /* *** in simple_elem case should output ns prefix from ns node. */
  int len = sizeof("<ff12:AuthnRequest")-1 + 1 + sizeof("</ff12:AuthnRequest>")-1;
  if (c->inc_ns_len)
    len += zx_len_inc_ns(c, &pop_seen);
  len += zx_len_xmlns_if_not_seen(c, zx_ns_tab+zx_xmlns_ix_ff12, &pop_seen);

  len += zx_attr_so_len(c, x->IssueInstant, sizeof("IssueInstant")-1, &pop_seen);
  len += zx_attr_so_len(c, x->MajorVersion, sizeof("MajorVersion")-1, &pop_seen);
  len += zx_attr_so_len(c, x->MinorVersion, sizeof("MinorVersion")-1, &pop_seen);
  len += zx_attr_so_len(c, x->RequestID, sizeof("RequestID")-1, &pop_seen);
  len += zx_attr_so_len(c, x->consent, sizeof("consent")-1, &pop_seen);

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
  {
      struct zx_ff12_Extension_s* e;
      for (e = x->Extension; e; e = (struct zx_ff12_Extension_s*)e->gg.g.n)
	  len += zx_LEN_SO_ff12_Extension(c, e);
  }
  for (se = x->ProviderID; se; se = (struct zx_elem_s*)se->g.n)
    len += zx_LEN_SO_simple_elem(c,se, sizeof("ff12:ProviderID")-1, zx_ns_tab+zx_xmlns_ix_ff12);
  for (se = x->AffiliationID; se; se = (struct zx_elem_s*)se->g.n)
    len += zx_LEN_SO_simple_elem(c,se, sizeof("ff12:AffiliationID")-1, zx_ns_tab+zx_xmlns_ix_ff12);
  for (se = x->NameIDPolicy; se; se = (struct zx_elem_s*)se->g.n)
    len += zx_LEN_SO_simple_elem(c,se, sizeof("ff12:NameIDPolicy")-1, zx_ns_tab+zx_xmlns_ix_ff12);
  for (se = x->ForceAuthn; se; se = (struct zx_elem_s*)se->g.n)
    len += zx_LEN_SO_simple_elem(c,se, sizeof("ff12:ForceAuthn")-1, zx_ns_tab+zx_xmlns_ix_ff12);
  for (se = x->IsPassive; se; se = (struct zx_elem_s*)se->g.n)
    len += zx_LEN_SO_simple_elem(c,se, sizeof("ff12:IsPassive")-1, zx_ns_tab+zx_xmlns_ix_ff12);
  for (se = x->ProtocolProfile; se; se = (struct zx_elem_s*)se->g.n)
    len += zx_LEN_SO_simple_elem(c,se, sizeof("ff12:ProtocolProfile")-1, zx_ns_tab+zx_xmlns_ix_ff12);
  for (se = x->AssertionConsumerServiceID; se; se = (struct zx_elem_s*)se->g.n)
    len += zx_LEN_SO_simple_elem(c,se, sizeof("ff12:AssertionConsumerServiceID")-1, zx_ns_tab+zx_xmlns_ix_ff12);
  {
      struct zx_ff12_RequestAuthnContext_s* e;
      for (e = x->RequestAuthnContext; e; e = (struct zx_ff12_RequestAuthnContext_s*)e->gg.g.n)
	  len += zx_LEN_SO_ff12_RequestAuthnContext(c, e);
  }
  for (se = x->RelayState; se; se = (struct zx_elem_s*)se->g.n)
    len += zx_LEN_SO_simple_elem(c,se, sizeof("ff12:RelayState")-1, zx_ns_tab+zx_xmlns_ix_ff12);
  {
      struct zx_ff12_Scoping_s* e;
      for (e = x->Scoping; e; e = (struct zx_ff12_Scoping_s*)e->gg.g.n)
	  len += zx_LEN_SO_ff12_Scoping(c, e);
  }


  len += zx_len_so_common(c, &x->gg, &pop_seen);
  zx_pop_seen(pop_seen);
  ENC_LEN_DEBUG(x, "ff12:AuthnRequest", len);
  return len;
}

/* FUNC(zx_LEN_WO_ff12_AuthnRequest) */

/* Compute length of an element (and its subelements). The XML attributes
 * and elements are processed in wire order and no assumptions
 * are made about namespace prefixes. */

/* Called by: */
int zx_LEN_WO_ff12_AuthnRequest(struct zx_ctx* c, struct zx_ff12_AuthnRequest_s* x )
{
  struct zx_ns_s* pop_seen = 0;
  struct zx_elem_s* se MAYBE_UNUSED;
#if 1 /* NORMALMODE */
  int len = 1 + sizeof("AuthnRequest")-1 + 1 + 2 + sizeof("AuthnRequest")-1 + 1;
  
  if (x->gg.g.ns && x->gg.g.ns->prefix_len)
    len += (x->gg.g.ns->prefix_len + 1) * 2;
  if (c->inc_ns_len)
    len += zx_len_inc_ns(c, &pop_seen);
  len += zx_len_xmlns_if_not_seen(c, x->gg.g.ns, &pop_seen);

  len += zx_attr_wo_len(c, x->IssueInstant, sizeof("IssueInstant")-1, &pop_seen);
  len += zx_attr_wo_len(c, x->MajorVersion, sizeof("MajorVersion")-1, &pop_seen);
  len += zx_attr_wo_len(c, x->MinorVersion, sizeof("MinorVersion")-1, &pop_seen);
  len += zx_attr_wo_len(c, x->RequestID, sizeof("RequestID")-1, &pop_seen);
  len += zx_attr_wo_len(c, x->consent, sizeof("consent")-1, &pop_seen);

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
  {
      struct zx_ff12_Extension_s* e;
      for (e = x->Extension; e; e = (struct zx_ff12_Extension_s*)e->gg.g.n)
	  len += zx_LEN_WO_ff12_Extension(c, e);
  }
  for (se = x->ProviderID; se; se = (struct zx_elem_s*)se->g.n)
    len += zx_LEN_WO_simple_elem(c, se, sizeof("ProviderID")-1);
  for (se = x->AffiliationID; se; se = (struct zx_elem_s*)se->g.n)
    len += zx_LEN_WO_simple_elem(c, se, sizeof("AffiliationID")-1);
  for (se = x->NameIDPolicy; se; se = (struct zx_elem_s*)se->g.n)
    len += zx_LEN_WO_simple_elem(c, se, sizeof("NameIDPolicy")-1);
  for (se = x->ForceAuthn; se; se = (struct zx_elem_s*)se->g.n)
    len += zx_LEN_WO_simple_elem(c, se, sizeof("ForceAuthn")-1);
  for (se = x->IsPassive; se; se = (struct zx_elem_s*)se->g.n)
    len += zx_LEN_WO_simple_elem(c, se, sizeof("IsPassive")-1);
  for (se = x->ProtocolProfile; se; se = (struct zx_elem_s*)se->g.n)
    len += zx_LEN_WO_simple_elem(c, se, sizeof("ProtocolProfile")-1);
  for (se = x->AssertionConsumerServiceID; se; se = (struct zx_elem_s*)se->g.n)
    len += zx_LEN_WO_simple_elem(c, se, sizeof("AssertionConsumerServiceID")-1);
  {
      struct zx_ff12_RequestAuthnContext_s* e;
      for (e = x->RequestAuthnContext; e; e = (struct zx_ff12_RequestAuthnContext_s*)e->gg.g.n)
	  len += zx_LEN_WO_ff12_RequestAuthnContext(c, e);
  }
  for (se = x->RelayState; se; se = (struct zx_elem_s*)se->g.n)
    len += zx_LEN_WO_simple_elem(c, se, sizeof("RelayState")-1);
  {
      struct zx_ff12_Scoping_s* e;
      for (e = x->Scoping; e; e = (struct zx_ff12_Scoping_s*)e->gg.g.n)
	  len += zx_LEN_WO_ff12_Scoping(c, e);
  }


  len += zx_len_wo_common(c, &x->gg, &pop_seen); 
  zx_pop_seen(pop_seen);
  ENC_LEN_DEBUG(x, "ff12:AuthnRequest", len);
  return len;
}

/* FUNC(zx_ENC_SO_ff12_AuthnRequest) */

/* Render element into string. The XML attributes and elements are
 * processed in schema order. This is what you generally want for
 * rendering new data structure to a string. The wo pointers are not used. */

/* Called by: */
char* zx_ENC_SO_ff12_AuthnRequest(struct zx_ctx* c, struct zx_ff12_AuthnRequest_s* x, char* p )
{
  struct zx_elem_s* se MAYBE_UNUSED;
  struct zx_ns_s* pop_seen = 0;
  ENC_LEN_DEBUG_BASE;
#if 1 /* NORMALMODE */
  /* *** in simple_elem case should output ns prefix from ns node. */
  ZX_OUT_TAG(p, "<ff12:AuthnRequest");
  if (c->inc_ns)
    zx_add_inc_ns(c, &pop_seen);
  zx_add_xmlns_if_not_seen(c, zx_ns_tab+zx_xmlns_ix_ff12, &pop_seen);

  zx_see_unknown_attrs_ns(c, x->gg.any_attr, &pop_seen);
  p = zx_enc_seen(p, pop_seen); 
  p = zx_attr_so_enc(p, x->IssueInstant, " IssueInstant=\"", sizeof(" IssueInstant=\"")-1);
  p = zx_attr_so_enc(p, x->MajorVersion, " MajorVersion=\"", sizeof(" MajorVersion=\"")-1);
  p = zx_attr_so_enc(p, x->MinorVersion, " MinorVersion=\"", sizeof(" MinorVersion=\"")-1);
  p = zx_attr_so_enc(p, x->RequestID, " RequestID=\"", sizeof(" RequestID=\"")-1);
  p = zx_attr_so_enc(p, x->consent, " consent=\"", sizeof(" consent=\"")-1);

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
  {
      struct zx_ff12_Extension_s* e;
      for (e = x->Extension; e; e = (struct zx_ff12_Extension_s*)e->gg.g.n)
	  p = zx_ENC_SO_ff12_Extension(c, e, p);
  }
  for (se = x->ProviderID; se; se = (struct zx_elem_s*)se->g.n)
    p = zx_ENC_SO_simple_elem(c, se, p, "ff12:ProviderID", sizeof("ff12:ProviderID")-1, zx_ns_tab+zx_xmlns_ix_ff12);
  for (se = x->AffiliationID; se; se = (struct zx_elem_s*)se->g.n)
    p = zx_ENC_SO_simple_elem(c, se, p, "ff12:AffiliationID", sizeof("ff12:AffiliationID")-1, zx_ns_tab+zx_xmlns_ix_ff12);
  for (se = x->NameIDPolicy; se; se = (struct zx_elem_s*)se->g.n)
    p = zx_ENC_SO_simple_elem(c, se, p, "ff12:NameIDPolicy", sizeof("ff12:NameIDPolicy")-1, zx_ns_tab+zx_xmlns_ix_ff12);
  for (se = x->ForceAuthn; se; se = (struct zx_elem_s*)se->g.n)
    p = zx_ENC_SO_simple_elem(c, se, p, "ff12:ForceAuthn", sizeof("ff12:ForceAuthn")-1, zx_ns_tab+zx_xmlns_ix_ff12);
  for (se = x->IsPassive; se; se = (struct zx_elem_s*)se->g.n)
    p = zx_ENC_SO_simple_elem(c, se, p, "ff12:IsPassive", sizeof("ff12:IsPassive")-1, zx_ns_tab+zx_xmlns_ix_ff12);
  for (se = x->ProtocolProfile; se; se = (struct zx_elem_s*)se->g.n)
    p = zx_ENC_SO_simple_elem(c, se, p, "ff12:ProtocolProfile", sizeof("ff12:ProtocolProfile")-1, zx_ns_tab+zx_xmlns_ix_ff12);
  for (se = x->AssertionConsumerServiceID; se; se = (struct zx_elem_s*)se->g.n)
    p = zx_ENC_SO_simple_elem(c, se, p, "ff12:AssertionConsumerServiceID", sizeof("ff12:AssertionConsumerServiceID")-1, zx_ns_tab+zx_xmlns_ix_ff12);
  {
      struct zx_ff12_RequestAuthnContext_s* e;
      for (e = x->RequestAuthnContext; e; e = (struct zx_ff12_RequestAuthnContext_s*)e->gg.g.n)
	  p = zx_ENC_SO_ff12_RequestAuthnContext(c, e, p);
  }
  for (se = x->RelayState; se; se = (struct zx_elem_s*)se->g.n)
    p = zx_ENC_SO_simple_elem(c, se, p, "ff12:RelayState", sizeof("ff12:RelayState")-1, zx_ns_tab+zx_xmlns_ix_ff12);
  {
      struct zx_ff12_Scoping_s* e;
      for (e = x->Scoping; e; e = (struct zx_ff12_Scoping_s*)e->gg.g.n)
	  p = zx_ENC_SO_ff12_Scoping(c, e, p);
  }

  p = zx_enc_so_unknown_elems_and_content(c, p, &x->gg);
  
#if 1 /* NORMALMODE */
  ZX_OUT_CLOSE_TAG(p, "</ff12:AuthnRequest>");
  zx_pop_seen(pop_seen);
#else
  /* root node has no end tag either */
#endif
  ENC_LEN_DEBUG(x, "ff12:AuthnRequest", p-enc_base);
  return p;
}

/* FUNC(zx_ENC_WO_ff12_AuthnRequest) */

/* Render element into string. The XML attributes and elements are
 * processed in wire order by chasing wo pointers. This is what you want for
 * validating signatures on other people's XML documents. */

/* Called by: */
char* zx_ENC_WO_ff12_AuthnRequest(struct zx_ctx* c, struct zx_ff12_AuthnRequest_s* x, char* p )
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
  ZX_OUT_MEM(p, "AuthnRequest", sizeof("AuthnRequest")-1);
  qq = p;

  if (c->inc_ns)
    zx_add_inc_ns(c, &pop_seen);
  zx_add_xmlns_if_not_seen(c, x->gg.g.ns, &pop_seen);

  zx_see_unknown_attrs_ns(c, x->gg.any_attr, &pop_seen);
  p = zx_enc_seen(p, pop_seen); 
  p = zx_attr_wo_enc(p, x->IssueInstant, "IssueInstant=\"", sizeof("IssueInstant=\"")-1);
  p = zx_attr_wo_enc(p, x->MajorVersion, "MajorVersion=\"", sizeof("MajorVersion=\"")-1);
  p = zx_attr_wo_enc(p, x->MinorVersion, "MinorVersion=\"", sizeof("MinorVersion=\"")-1);
  p = zx_attr_wo_enc(p, x->RequestID, "RequestID=\"", sizeof("RequestID=\"")-1);
  p = zx_attr_wo_enc(p, x->consent, "consent=\"", sizeof("consent=\"")-1);

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
  ENC_LEN_DEBUG(x, "ff12:AuthnRequest", p-enc_base);
  return p;
}

/* FUNC(zx_EASY_ENC_SO_ff12_AuthnRequest) */

/* Called by: */
struct zx_str* zx_EASY_ENC_SO_ff12_AuthnRequest(struct zx_ctx* c, struct zx_ff12_AuthnRequest_s* x )
{
  int len;
  char* buf;
  c->ns_tab = ZX_ALLOC(c, sizeof(zx_ns_tab));
  memcpy(c->ns_tab, zx_ns_tab, sizeof(zx_ns_tab));
  len = zx_LEN_SO_ff12_AuthnRequest(c, x );
  buf = ZX_ALLOC(c, len+1);
  return zx_easy_enc_common(c, zx_ENC_SO_ff12_AuthnRequest(c, x, buf ), buf, len);
}

/* FUNC(zx_EASY_ENC_WO_ff12_AuthnRequest) */

/* Called by: */
struct zx_str* zx_EASY_ENC_WO_ff12_AuthnRequest(struct zx_ctx* c, struct zx_ff12_AuthnRequest_s* x )
{
  int len;
  char* buf;
  c->ns_tab = ZX_ALLOC(c, sizeof(zx_ns_tab));
  memcpy(c->ns_tab, zx_ns_tab, sizeof(zx_ns_tab));
  len = zx_LEN_WO_ff12_AuthnRequest(c, x );
  buf = ZX_ALLOC(c, len+1);
  return zx_easy_enc_common(c, zx_ENC_WO_ff12_AuthnRequest(c, x, buf ), buf, len);
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

#define EL_NAME   ff12_AuthnRequestEnvelope
#define EL_STRUCT zx_ff12_AuthnRequestEnvelope_s
#define EL_NS     ff12
#define EL_TAG    AuthnRequestEnvelope

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

/* FUNC(zx_LEN_SO_ff12_AuthnRequestEnvelope) */

/* Compute length of an element (and its subelements). The XML attributes
 * and elements are processed in schema order. */

/* Called by: */
int zx_LEN_SO_ff12_AuthnRequestEnvelope(struct zx_ctx* c, struct zx_ff12_AuthnRequestEnvelope_s* x )
{
  struct zx_ns_s* pop_seen = 0;
  struct zx_elem_s* se MAYBE_UNUSED;
#if 1 /* NORMALMODE */
  /* *** in simple_elem case should output ns prefix from ns node. */
  int len = sizeof("<ff12:AuthnRequestEnvelope")-1 + 1 + sizeof("</ff12:AuthnRequestEnvelope>")-1;
  if (c->inc_ns_len)
    len += zx_len_inc_ns(c, &pop_seen);
  len += zx_len_xmlns_if_not_seen(c, zx_ns_tab+zx_xmlns_ix_ff12, &pop_seen);


#else
  /* root node has no begin tag */
  int len = 0;
#endif
  
  {
      struct zx_ff12_Extension_s* e;
      for (e = x->Extension; e; e = (struct zx_ff12_Extension_s*)e->gg.g.n)
	  len += zx_LEN_SO_ff12_Extension(c, e);
  }
  {
      struct zx_ff12_AuthnRequest_s* e;
      for (e = x->AuthnRequest; e; e = (struct zx_ff12_AuthnRequest_s*)e->gg.g.n)
	  len += zx_LEN_SO_ff12_AuthnRequest(c, e);
  }
  for (se = x->ProviderID; se; se = (struct zx_elem_s*)se->g.n)
    len += zx_LEN_SO_simple_elem(c,se, sizeof("ff12:ProviderID")-1, zx_ns_tab+zx_xmlns_ix_ff12);
  for (se = x->ProviderName; se; se = (struct zx_elem_s*)se->g.n)
    len += zx_LEN_SO_simple_elem(c,se, sizeof("ff12:ProviderName")-1, zx_ns_tab+zx_xmlns_ix_ff12);
  for (se = x->AssertionConsumerServiceURL; se; se = (struct zx_elem_s*)se->g.n)
    len += zx_LEN_SO_simple_elem(c,se, sizeof("ff12:AssertionConsumerServiceURL")-1, zx_ns_tab+zx_xmlns_ix_ff12);
  {
      struct zx_ff12_IDPList_s* e;
      for (e = x->IDPList; e; e = (struct zx_ff12_IDPList_s*)e->gg.g.n)
	  len += zx_LEN_SO_ff12_IDPList(c, e);
  }
  for (se = x->IsPassive; se; se = (struct zx_elem_s*)se->g.n)
    len += zx_LEN_SO_simple_elem(c,se, sizeof("ff12:IsPassive")-1, zx_ns_tab+zx_xmlns_ix_ff12);


  len += zx_len_so_common(c, &x->gg, &pop_seen);
  zx_pop_seen(pop_seen);
  ENC_LEN_DEBUG(x, "ff12:AuthnRequestEnvelope", len);
  return len;
}

/* FUNC(zx_LEN_WO_ff12_AuthnRequestEnvelope) */

/* Compute length of an element (and its subelements). The XML attributes
 * and elements are processed in wire order and no assumptions
 * are made about namespace prefixes. */

/* Called by: */
int zx_LEN_WO_ff12_AuthnRequestEnvelope(struct zx_ctx* c, struct zx_ff12_AuthnRequestEnvelope_s* x )
{
  struct zx_ns_s* pop_seen = 0;
  struct zx_elem_s* se MAYBE_UNUSED;
#if 1 /* NORMALMODE */
  int len = 1 + sizeof("AuthnRequestEnvelope")-1 + 1 + 2 + sizeof("AuthnRequestEnvelope")-1 + 1;
  
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
      struct zx_ff12_Extension_s* e;
      for (e = x->Extension; e; e = (struct zx_ff12_Extension_s*)e->gg.g.n)
	  len += zx_LEN_WO_ff12_Extension(c, e);
  }
  {
      struct zx_ff12_AuthnRequest_s* e;
      for (e = x->AuthnRequest; e; e = (struct zx_ff12_AuthnRequest_s*)e->gg.g.n)
	  len += zx_LEN_WO_ff12_AuthnRequest(c, e);
  }
  for (se = x->ProviderID; se; se = (struct zx_elem_s*)se->g.n)
    len += zx_LEN_WO_simple_elem(c, se, sizeof("ProviderID")-1);
  for (se = x->ProviderName; se; se = (struct zx_elem_s*)se->g.n)
    len += zx_LEN_WO_simple_elem(c, se, sizeof("ProviderName")-1);
  for (se = x->AssertionConsumerServiceURL; se; se = (struct zx_elem_s*)se->g.n)
    len += zx_LEN_WO_simple_elem(c, se, sizeof("AssertionConsumerServiceURL")-1);
  {
      struct zx_ff12_IDPList_s* e;
      for (e = x->IDPList; e; e = (struct zx_ff12_IDPList_s*)e->gg.g.n)
	  len += zx_LEN_WO_ff12_IDPList(c, e);
  }
  for (se = x->IsPassive; se; se = (struct zx_elem_s*)se->g.n)
    len += zx_LEN_WO_simple_elem(c, se, sizeof("IsPassive")-1);


  len += zx_len_wo_common(c, &x->gg, &pop_seen); 
  zx_pop_seen(pop_seen);
  ENC_LEN_DEBUG(x, "ff12:AuthnRequestEnvelope", len);
  return len;
}

/* FUNC(zx_ENC_SO_ff12_AuthnRequestEnvelope) */

/* Render element into string. The XML attributes and elements are
 * processed in schema order. This is what you generally want for
 * rendering new data structure to a string. The wo pointers are not used. */

/* Called by: */
char* zx_ENC_SO_ff12_AuthnRequestEnvelope(struct zx_ctx* c, struct zx_ff12_AuthnRequestEnvelope_s* x, char* p )
{
  struct zx_elem_s* se MAYBE_UNUSED;
  struct zx_ns_s* pop_seen = 0;
  ENC_LEN_DEBUG_BASE;
#if 1 /* NORMALMODE */
  /* *** in simple_elem case should output ns prefix from ns node. */
  ZX_OUT_TAG(p, "<ff12:AuthnRequestEnvelope");
  if (c->inc_ns)
    zx_add_inc_ns(c, &pop_seen);
  zx_add_xmlns_if_not_seen(c, zx_ns_tab+zx_xmlns_ix_ff12, &pop_seen);

  zx_see_unknown_attrs_ns(c, x->gg.any_attr, &pop_seen);
  p = zx_enc_seen(p, pop_seen); 

  p = zx_enc_unknown_attrs(p, x->gg.any_attr);
#else
  /* root node has no begin tag */
#endif
  
  {
      struct zx_ff12_Extension_s* e;
      for (e = x->Extension; e; e = (struct zx_ff12_Extension_s*)e->gg.g.n)
	  p = zx_ENC_SO_ff12_Extension(c, e, p);
  }
  {
      struct zx_ff12_AuthnRequest_s* e;
      for (e = x->AuthnRequest; e; e = (struct zx_ff12_AuthnRequest_s*)e->gg.g.n)
	  p = zx_ENC_SO_ff12_AuthnRequest(c, e, p);
  }
  for (se = x->ProviderID; se; se = (struct zx_elem_s*)se->g.n)
    p = zx_ENC_SO_simple_elem(c, se, p, "ff12:ProviderID", sizeof("ff12:ProviderID")-1, zx_ns_tab+zx_xmlns_ix_ff12);
  for (se = x->ProviderName; se; se = (struct zx_elem_s*)se->g.n)
    p = zx_ENC_SO_simple_elem(c, se, p, "ff12:ProviderName", sizeof("ff12:ProviderName")-1, zx_ns_tab+zx_xmlns_ix_ff12);
  for (se = x->AssertionConsumerServiceURL; se; se = (struct zx_elem_s*)se->g.n)
    p = zx_ENC_SO_simple_elem(c, se, p, "ff12:AssertionConsumerServiceURL", sizeof("ff12:AssertionConsumerServiceURL")-1, zx_ns_tab+zx_xmlns_ix_ff12);
  {
      struct zx_ff12_IDPList_s* e;
      for (e = x->IDPList; e; e = (struct zx_ff12_IDPList_s*)e->gg.g.n)
	  p = zx_ENC_SO_ff12_IDPList(c, e, p);
  }
  for (se = x->IsPassive; se; se = (struct zx_elem_s*)se->g.n)
    p = zx_ENC_SO_simple_elem(c, se, p, "ff12:IsPassive", sizeof("ff12:IsPassive")-1, zx_ns_tab+zx_xmlns_ix_ff12);

  p = zx_enc_so_unknown_elems_and_content(c, p, &x->gg);
  
#if 1 /* NORMALMODE */
  ZX_OUT_CLOSE_TAG(p, "</ff12:AuthnRequestEnvelope>");
  zx_pop_seen(pop_seen);
#else
  /* root node has no end tag either */
#endif
  ENC_LEN_DEBUG(x, "ff12:AuthnRequestEnvelope", p-enc_base);
  return p;
}

/* FUNC(zx_ENC_WO_ff12_AuthnRequestEnvelope) */

/* Render element into string. The XML attributes and elements are
 * processed in wire order by chasing wo pointers. This is what you want for
 * validating signatures on other people's XML documents. */

/* Called by: */
char* zx_ENC_WO_ff12_AuthnRequestEnvelope(struct zx_ctx* c, struct zx_ff12_AuthnRequestEnvelope_s* x, char* p )
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
  ZX_OUT_MEM(p, "AuthnRequestEnvelope", sizeof("AuthnRequestEnvelope")-1);
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
  ENC_LEN_DEBUG(x, "ff12:AuthnRequestEnvelope", p-enc_base);
  return p;
}

/* FUNC(zx_EASY_ENC_SO_ff12_AuthnRequestEnvelope) */

/* Called by: */
struct zx_str* zx_EASY_ENC_SO_ff12_AuthnRequestEnvelope(struct zx_ctx* c, struct zx_ff12_AuthnRequestEnvelope_s* x )
{
  int len;
  char* buf;
  c->ns_tab = ZX_ALLOC(c, sizeof(zx_ns_tab));
  memcpy(c->ns_tab, zx_ns_tab, sizeof(zx_ns_tab));
  len = zx_LEN_SO_ff12_AuthnRequestEnvelope(c, x );
  buf = ZX_ALLOC(c, len+1);
  return zx_easy_enc_common(c, zx_ENC_SO_ff12_AuthnRequestEnvelope(c, x, buf ), buf, len);
}

/* FUNC(zx_EASY_ENC_WO_ff12_AuthnRequestEnvelope) */

/* Called by: */
struct zx_str* zx_EASY_ENC_WO_ff12_AuthnRequestEnvelope(struct zx_ctx* c, struct zx_ff12_AuthnRequestEnvelope_s* x )
{
  int len;
  char* buf;
  c->ns_tab = ZX_ALLOC(c, sizeof(zx_ns_tab));
  memcpy(c->ns_tab, zx_ns_tab, sizeof(zx_ns_tab));
  len = zx_LEN_WO_ff12_AuthnRequestEnvelope(c, x );
  buf = ZX_ALLOC(c, len+1);
  return zx_easy_enc_common(c, zx_ENC_WO_ff12_AuthnRequestEnvelope(c, x, buf ), buf, len);
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

#define EL_NAME   ff12_AuthnResponse
#define EL_STRUCT zx_ff12_AuthnResponse_s
#define EL_NS     ff12
#define EL_TAG    AuthnResponse

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

/* FUNC(zx_LEN_SO_ff12_AuthnResponse) */

/* Compute length of an element (and its subelements). The XML attributes
 * and elements are processed in schema order. */

/* Called by: */
int zx_LEN_SO_ff12_AuthnResponse(struct zx_ctx* c, struct zx_ff12_AuthnResponse_s* x )
{
  struct zx_ns_s* pop_seen = 0;
  struct zx_elem_s* se MAYBE_UNUSED;
#if 1 /* NORMALMODE */
  /* *** in simple_elem case should output ns prefix from ns node. */
  int len = sizeof("<ff12:AuthnResponse")-1 + 1 + sizeof("</ff12:AuthnResponse>")-1;
  if (c->inc_ns_len)
    len += zx_len_inc_ns(c, &pop_seen);
  len += zx_len_xmlns_if_not_seen(c, zx_ns_tab+zx_xmlns_ix_ff12, &pop_seen);

  len += zx_attr_so_len(c, x->InResponseTo, sizeof("InResponseTo")-1, &pop_seen);
  len += zx_attr_so_len(c, x->IssueInstant, sizeof("IssueInstant")-1, &pop_seen);
  len += zx_attr_so_len(c, x->MajorVersion, sizeof("MajorVersion")-1, &pop_seen);
  len += zx_attr_so_len(c, x->MinorVersion, sizeof("MinorVersion")-1, &pop_seen);
  len += zx_attr_so_len(c, x->Recipient, sizeof("Recipient")-1, &pop_seen);
  len += zx_attr_so_len(c, x->ResponseID, sizeof("ResponseID")-1, &pop_seen);
  len += zx_attr_so_len(c, x->consent, sizeof("consent")-1, &pop_seen);

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
  {
      struct zx_ff12_Extension_s* e;
      for (e = x->Extension; e; e = (struct zx_ff12_Extension_s*)e->gg.g.n)
	  len += zx_LEN_SO_ff12_Extension(c, e);
  }
  for (se = x->ProviderID; se; se = (struct zx_elem_s*)se->g.n)
    len += zx_LEN_SO_simple_elem(c,se, sizeof("ff12:ProviderID")-1, zx_ns_tab+zx_xmlns_ix_ff12);
  for (se = x->RelayState; se; se = (struct zx_elem_s*)se->g.n)
    len += zx_LEN_SO_simple_elem(c,se, sizeof("ff12:RelayState")-1, zx_ns_tab+zx_xmlns_ix_ff12);


  len += zx_len_so_common(c, &x->gg, &pop_seen);
  zx_pop_seen(pop_seen);
  ENC_LEN_DEBUG(x, "ff12:AuthnResponse", len);
  return len;
}

/* FUNC(zx_LEN_WO_ff12_AuthnResponse) */

/* Compute length of an element (and its subelements). The XML attributes
 * and elements are processed in wire order and no assumptions
 * are made about namespace prefixes. */

/* Called by: */
int zx_LEN_WO_ff12_AuthnResponse(struct zx_ctx* c, struct zx_ff12_AuthnResponse_s* x )
{
  struct zx_ns_s* pop_seen = 0;
  struct zx_elem_s* se MAYBE_UNUSED;
#if 1 /* NORMALMODE */
  int len = 1 + sizeof("AuthnResponse")-1 + 1 + 2 + sizeof("AuthnResponse")-1 + 1;
  
  if (x->gg.g.ns && x->gg.g.ns->prefix_len)
    len += (x->gg.g.ns->prefix_len + 1) * 2;
  if (c->inc_ns_len)
    len += zx_len_inc_ns(c, &pop_seen);
  len += zx_len_xmlns_if_not_seen(c, x->gg.g.ns, &pop_seen);

  len += zx_attr_wo_len(c, x->InResponseTo, sizeof("InResponseTo")-1, &pop_seen);
  len += zx_attr_wo_len(c, x->IssueInstant, sizeof("IssueInstant")-1, &pop_seen);
  len += zx_attr_wo_len(c, x->MajorVersion, sizeof("MajorVersion")-1, &pop_seen);
  len += zx_attr_wo_len(c, x->MinorVersion, sizeof("MinorVersion")-1, &pop_seen);
  len += zx_attr_wo_len(c, x->Recipient, sizeof("Recipient")-1, &pop_seen);
  len += zx_attr_wo_len(c, x->ResponseID, sizeof("ResponseID")-1, &pop_seen);
  len += zx_attr_wo_len(c, x->consent, sizeof("consent")-1, &pop_seen);

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
  {
      struct zx_ff12_Extension_s* e;
      for (e = x->Extension; e; e = (struct zx_ff12_Extension_s*)e->gg.g.n)
	  len += zx_LEN_WO_ff12_Extension(c, e);
  }
  for (se = x->ProviderID; se; se = (struct zx_elem_s*)se->g.n)
    len += zx_LEN_WO_simple_elem(c, se, sizeof("ProviderID")-1);
  for (se = x->RelayState; se; se = (struct zx_elem_s*)se->g.n)
    len += zx_LEN_WO_simple_elem(c, se, sizeof("RelayState")-1);


  len += zx_len_wo_common(c, &x->gg, &pop_seen); 
  zx_pop_seen(pop_seen);
  ENC_LEN_DEBUG(x, "ff12:AuthnResponse", len);
  return len;
}

/* FUNC(zx_ENC_SO_ff12_AuthnResponse) */

/* Render element into string. The XML attributes and elements are
 * processed in schema order. This is what you generally want for
 * rendering new data structure to a string. The wo pointers are not used. */

/* Called by: */
char* zx_ENC_SO_ff12_AuthnResponse(struct zx_ctx* c, struct zx_ff12_AuthnResponse_s* x, char* p )
{
  struct zx_elem_s* se MAYBE_UNUSED;
  struct zx_ns_s* pop_seen = 0;
  ENC_LEN_DEBUG_BASE;
#if 1 /* NORMALMODE */
  /* *** in simple_elem case should output ns prefix from ns node. */
  ZX_OUT_TAG(p, "<ff12:AuthnResponse");
  if (c->inc_ns)
    zx_add_inc_ns(c, &pop_seen);
  zx_add_xmlns_if_not_seen(c, zx_ns_tab+zx_xmlns_ix_ff12, &pop_seen);

  zx_see_unknown_attrs_ns(c, x->gg.any_attr, &pop_seen);
  p = zx_enc_seen(p, pop_seen); 
  p = zx_attr_so_enc(p, x->InResponseTo, " InResponseTo=\"", sizeof(" InResponseTo=\"")-1);
  p = zx_attr_so_enc(p, x->IssueInstant, " IssueInstant=\"", sizeof(" IssueInstant=\"")-1);
  p = zx_attr_so_enc(p, x->MajorVersion, " MajorVersion=\"", sizeof(" MajorVersion=\"")-1);
  p = zx_attr_so_enc(p, x->MinorVersion, " MinorVersion=\"", sizeof(" MinorVersion=\"")-1);
  p = zx_attr_so_enc(p, x->Recipient, " Recipient=\"", sizeof(" Recipient=\"")-1);
  p = zx_attr_so_enc(p, x->ResponseID, " ResponseID=\"", sizeof(" ResponseID=\"")-1);
  p = zx_attr_so_enc(p, x->consent, " consent=\"", sizeof(" consent=\"")-1);

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
  {
      struct zx_ff12_Extension_s* e;
      for (e = x->Extension; e; e = (struct zx_ff12_Extension_s*)e->gg.g.n)
	  p = zx_ENC_SO_ff12_Extension(c, e, p);
  }
  for (se = x->ProviderID; se; se = (struct zx_elem_s*)se->g.n)
    p = zx_ENC_SO_simple_elem(c, se, p, "ff12:ProviderID", sizeof("ff12:ProviderID")-1, zx_ns_tab+zx_xmlns_ix_ff12);
  for (se = x->RelayState; se; se = (struct zx_elem_s*)se->g.n)
    p = zx_ENC_SO_simple_elem(c, se, p, "ff12:RelayState", sizeof("ff12:RelayState")-1, zx_ns_tab+zx_xmlns_ix_ff12);

  p = zx_enc_so_unknown_elems_and_content(c, p, &x->gg);
  
#if 1 /* NORMALMODE */
  ZX_OUT_CLOSE_TAG(p, "</ff12:AuthnResponse>");
  zx_pop_seen(pop_seen);
#else
  /* root node has no end tag either */
#endif
  ENC_LEN_DEBUG(x, "ff12:AuthnResponse", p-enc_base);
  return p;
}

/* FUNC(zx_ENC_WO_ff12_AuthnResponse) */

/* Render element into string. The XML attributes and elements are
 * processed in wire order by chasing wo pointers. This is what you want for
 * validating signatures on other people's XML documents. */

/* Called by: */
char* zx_ENC_WO_ff12_AuthnResponse(struct zx_ctx* c, struct zx_ff12_AuthnResponse_s* x, char* p )
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
  ZX_OUT_MEM(p, "AuthnResponse", sizeof("AuthnResponse")-1);
  qq = p;

  if (c->inc_ns)
    zx_add_inc_ns(c, &pop_seen);
  zx_add_xmlns_if_not_seen(c, x->gg.g.ns, &pop_seen);

  zx_see_unknown_attrs_ns(c, x->gg.any_attr, &pop_seen);
  p = zx_enc_seen(p, pop_seen); 
  p = zx_attr_wo_enc(p, x->InResponseTo, "InResponseTo=\"", sizeof("InResponseTo=\"")-1);
  p = zx_attr_wo_enc(p, x->IssueInstant, "IssueInstant=\"", sizeof("IssueInstant=\"")-1);
  p = zx_attr_wo_enc(p, x->MajorVersion, "MajorVersion=\"", sizeof("MajorVersion=\"")-1);
  p = zx_attr_wo_enc(p, x->MinorVersion, "MinorVersion=\"", sizeof("MinorVersion=\"")-1);
  p = zx_attr_wo_enc(p, x->Recipient, "Recipient=\"", sizeof("Recipient=\"")-1);
  p = zx_attr_wo_enc(p, x->ResponseID, "ResponseID=\"", sizeof("ResponseID=\"")-1);
  p = zx_attr_wo_enc(p, x->consent, "consent=\"", sizeof("consent=\"")-1);

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
  ENC_LEN_DEBUG(x, "ff12:AuthnResponse", p-enc_base);
  return p;
}

/* FUNC(zx_EASY_ENC_SO_ff12_AuthnResponse) */

/* Called by: */
struct zx_str* zx_EASY_ENC_SO_ff12_AuthnResponse(struct zx_ctx* c, struct zx_ff12_AuthnResponse_s* x )
{
  int len;
  char* buf;
  c->ns_tab = ZX_ALLOC(c, sizeof(zx_ns_tab));
  memcpy(c->ns_tab, zx_ns_tab, sizeof(zx_ns_tab));
  len = zx_LEN_SO_ff12_AuthnResponse(c, x );
  buf = ZX_ALLOC(c, len+1);
  return zx_easy_enc_common(c, zx_ENC_SO_ff12_AuthnResponse(c, x, buf ), buf, len);
}

/* FUNC(zx_EASY_ENC_WO_ff12_AuthnResponse) */

/* Called by: */
struct zx_str* zx_EASY_ENC_WO_ff12_AuthnResponse(struct zx_ctx* c, struct zx_ff12_AuthnResponse_s* x )
{
  int len;
  char* buf;
  c->ns_tab = ZX_ALLOC(c, sizeof(zx_ns_tab));
  memcpy(c->ns_tab, zx_ns_tab, sizeof(zx_ns_tab));
  len = zx_LEN_WO_ff12_AuthnResponse(c, x );
  buf = ZX_ALLOC(c, len+1);
  return zx_easy_enc_common(c, zx_ENC_WO_ff12_AuthnResponse(c, x, buf ), buf, len);
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

#define EL_NAME   ff12_AuthnResponseEnvelope
#define EL_STRUCT zx_ff12_AuthnResponseEnvelope_s
#define EL_NS     ff12
#define EL_TAG    AuthnResponseEnvelope

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

/* FUNC(zx_LEN_SO_ff12_AuthnResponseEnvelope) */

/* Compute length of an element (and its subelements). The XML attributes
 * and elements are processed in schema order. */

/* Called by: */
int zx_LEN_SO_ff12_AuthnResponseEnvelope(struct zx_ctx* c, struct zx_ff12_AuthnResponseEnvelope_s* x )
{
  struct zx_ns_s* pop_seen = 0;
  struct zx_elem_s* se MAYBE_UNUSED;
#if 1 /* NORMALMODE */
  /* *** in simple_elem case should output ns prefix from ns node. */
  int len = sizeof("<ff12:AuthnResponseEnvelope")-1 + 1 + sizeof("</ff12:AuthnResponseEnvelope>")-1;
  if (c->inc_ns_len)
    len += zx_len_inc_ns(c, &pop_seen);
  len += zx_len_xmlns_if_not_seen(c, zx_ns_tab+zx_xmlns_ix_ff12, &pop_seen);


#else
  /* root node has no begin tag */
  int len = 0;
#endif
  
  {
      struct zx_ff12_Extension_s* e;
      for (e = x->Extension; e; e = (struct zx_ff12_Extension_s*)e->gg.g.n)
	  len += zx_LEN_SO_ff12_Extension(c, e);
  }
  {
      struct zx_ff12_AuthnResponse_s* e;
      for (e = x->AuthnResponse; e; e = (struct zx_ff12_AuthnResponse_s*)e->gg.g.n)
	  len += zx_LEN_SO_ff12_AuthnResponse(c, e);
  }
  for (se = x->AssertionConsumerServiceURL; se; se = (struct zx_elem_s*)se->g.n)
    len += zx_LEN_SO_simple_elem(c,se, sizeof("ff12:AssertionConsumerServiceURL")-1, zx_ns_tab+zx_xmlns_ix_ff12);


  len += zx_len_so_common(c, &x->gg, &pop_seen);
  zx_pop_seen(pop_seen);
  ENC_LEN_DEBUG(x, "ff12:AuthnResponseEnvelope", len);
  return len;
}

/* FUNC(zx_LEN_WO_ff12_AuthnResponseEnvelope) */

/* Compute length of an element (and its subelements). The XML attributes
 * and elements are processed in wire order and no assumptions
 * are made about namespace prefixes. */

/* Called by: */
int zx_LEN_WO_ff12_AuthnResponseEnvelope(struct zx_ctx* c, struct zx_ff12_AuthnResponseEnvelope_s* x )
{
  struct zx_ns_s* pop_seen = 0;
  struct zx_elem_s* se MAYBE_UNUSED;
#if 1 /* NORMALMODE */
  int len = 1 + sizeof("AuthnResponseEnvelope")-1 + 1 + 2 + sizeof("AuthnResponseEnvelope")-1 + 1;
  
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
      struct zx_ff12_Extension_s* e;
      for (e = x->Extension; e; e = (struct zx_ff12_Extension_s*)e->gg.g.n)
	  len += zx_LEN_WO_ff12_Extension(c, e);
  }
  {
      struct zx_ff12_AuthnResponse_s* e;
      for (e = x->AuthnResponse; e; e = (struct zx_ff12_AuthnResponse_s*)e->gg.g.n)
	  len += zx_LEN_WO_ff12_AuthnResponse(c, e);
  }
  for (se = x->AssertionConsumerServiceURL; se; se = (struct zx_elem_s*)se->g.n)
    len += zx_LEN_WO_simple_elem(c, se, sizeof("AssertionConsumerServiceURL")-1);


  len += zx_len_wo_common(c, &x->gg, &pop_seen); 
  zx_pop_seen(pop_seen);
  ENC_LEN_DEBUG(x, "ff12:AuthnResponseEnvelope", len);
  return len;
}

/* FUNC(zx_ENC_SO_ff12_AuthnResponseEnvelope) */

/* Render element into string. The XML attributes and elements are
 * processed in schema order. This is what you generally want for
 * rendering new data structure to a string. The wo pointers are not used. */

/* Called by: */
char* zx_ENC_SO_ff12_AuthnResponseEnvelope(struct zx_ctx* c, struct zx_ff12_AuthnResponseEnvelope_s* x, char* p )
{
  struct zx_elem_s* se MAYBE_UNUSED;
  struct zx_ns_s* pop_seen = 0;
  ENC_LEN_DEBUG_BASE;
#if 1 /* NORMALMODE */
  /* *** in simple_elem case should output ns prefix from ns node. */
  ZX_OUT_TAG(p, "<ff12:AuthnResponseEnvelope");
  if (c->inc_ns)
    zx_add_inc_ns(c, &pop_seen);
  zx_add_xmlns_if_not_seen(c, zx_ns_tab+zx_xmlns_ix_ff12, &pop_seen);

  zx_see_unknown_attrs_ns(c, x->gg.any_attr, &pop_seen);
  p = zx_enc_seen(p, pop_seen); 

  p = zx_enc_unknown_attrs(p, x->gg.any_attr);
#else
  /* root node has no begin tag */
#endif
  
  {
      struct zx_ff12_Extension_s* e;
      for (e = x->Extension; e; e = (struct zx_ff12_Extension_s*)e->gg.g.n)
	  p = zx_ENC_SO_ff12_Extension(c, e, p);
  }
  {
      struct zx_ff12_AuthnResponse_s* e;
      for (e = x->AuthnResponse; e; e = (struct zx_ff12_AuthnResponse_s*)e->gg.g.n)
	  p = zx_ENC_SO_ff12_AuthnResponse(c, e, p);
  }
  for (se = x->AssertionConsumerServiceURL; se; se = (struct zx_elem_s*)se->g.n)
    p = zx_ENC_SO_simple_elem(c, se, p, "ff12:AssertionConsumerServiceURL", sizeof("ff12:AssertionConsumerServiceURL")-1, zx_ns_tab+zx_xmlns_ix_ff12);

  p = zx_enc_so_unknown_elems_and_content(c, p, &x->gg);
  
#if 1 /* NORMALMODE */
  ZX_OUT_CLOSE_TAG(p, "</ff12:AuthnResponseEnvelope>");
  zx_pop_seen(pop_seen);
#else
  /* root node has no end tag either */
#endif
  ENC_LEN_DEBUG(x, "ff12:AuthnResponseEnvelope", p-enc_base);
  return p;
}

/* FUNC(zx_ENC_WO_ff12_AuthnResponseEnvelope) */

/* Render element into string. The XML attributes and elements are
 * processed in wire order by chasing wo pointers. This is what you want for
 * validating signatures on other people's XML documents. */

/* Called by: */
char* zx_ENC_WO_ff12_AuthnResponseEnvelope(struct zx_ctx* c, struct zx_ff12_AuthnResponseEnvelope_s* x, char* p )
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
  ZX_OUT_MEM(p, "AuthnResponseEnvelope", sizeof("AuthnResponseEnvelope")-1);
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
  ENC_LEN_DEBUG(x, "ff12:AuthnResponseEnvelope", p-enc_base);
  return p;
}

/* FUNC(zx_EASY_ENC_SO_ff12_AuthnResponseEnvelope) */

/* Called by: */
struct zx_str* zx_EASY_ENC_SO_ff12_AuthnResponseEnvelope(struct zx_ctx* c, struct zx_ff12_AuthnResponseEnvelope_s* x )
{
  int len;
  char* buf;
  c->ns_tab = ZX_ALLOC(c, sizeof(zx_ns_tab));
  memcpy(c->ns_tab, zx_ns_tab, sizeof(zx_ns_tab));
  len = zx_LEN_SO_ff12_AuthnResponseEnvelope(c, x );
  buf = ZX_ALLOC(c, len+1);
  return zx_easy_enc_common(c, zx_ENC_SO_ff12_AuthnResponseEnvelope(c, x, buf ), buf, len);
}

/* FUNC(zx_EASY_ENC_WO_ff12_AuthnResponseEnvelope) */

/* Called by: */
struct zx_str* zx_EASY_ENC_WO_ff12_AuthnResponseEnvelope(struct zx_ctx* c, struct zx_ff12_AuthnResponseEnvelope_s* x )
{
  int len;
  char* buf;
  c->ns_tab = ZX_ALLOC(c, sizeof(zx_ns_tab));
  memcpy(c->ns_tab, zx_ns_tab, sizeof(zx_ns_tab));
  len = zx_LEN_WO_ff12_AuthnResponseEnvelope(c, x );
  buf = ZX_ALLOC(c, len+1);
  return zx_easy_enc_common(c, zx_ENC_WO_ff12_AuthnResponseEnvelope(c, x, buf ), buf, len);
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

#define EL_NAME   ff12_EncryptableNameIdentifier
#define EL_STRUCT zx_ff12_EncryptableNameIdentifier_s
#define EL_NS     ff12
#define EL_TAG    EncryptableNameIdentifier

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

/* FUNC(zx_LEN_SO_ff12_EncryptableNameIdentifier) */

/* Compute length of an element (and its subelements). The XML attributes
 * and elements are processed in schema order. */

/* Called by: */
int zx_LEN_SO_ff12_EncryptableNameIdentifier(struct zx_ctx* c, struct zx_ff12_EncryptableNameIdentifier_s* x )
{
  struct zx_ns_s* pop_seen = 0;
  struct zx_elem_s* se MAYBE_UNUSED;
#if 1 /* NORMALMODE */
  /* *** in simple_elem case should output ns prefix from ns node. */
  int len = sizeof("<ff12:EncryptableNameIdentifier")-1 + 1 + sizeof("</ff12:EncryptableNameIdentifier>")-1;
  if (c->inc_ns_len)
    len += zx_len_inc_ns(c, &pop_seen);
  len += zx_len_xmlns_if_not_seen(c, zx_ns_tab+zx_xmlns_ix_ff12, &pop_seen);

  len += zx_attr_so_len(c, x->Format, sizeof("Format")-1, &pop_seen);
  len += zx_attr_so_len(c, x->IssueInstant, sizeof("IssueInstant")-1, &pop_seen);
  len += zx_attr_so_len(c, x->NameQualifier, sizeof("NameQualifier")-1, &pop_seen);
  len += zx_attr_so_len(c, x->Nonce, sizeof("Nonce")-1, &pop_seen);

#else
  /* root node has no begin tag */
  int len = 0;
#endif
  


  len += zx_len_so_common(c, &x->gg, &pop_seen);
  zx_pop_seen(pop_seen);
  ENC_LEN_DEBUG(x, "ff12:EncryptableNameIdentifier", len);
  return len;
}

/* FUNC(zx_LEN_WO_ff12_EncryptableNameIdentifier) */

/* Compute length of an element (and its subelements). The XML attributes
 * and elements are processed in wire order and no assumptions
 * are made about namespace prefixes. */

/* Called by: */
int zx_LEN_WO_ff12_EncryptableNameIdentifier(struct zx_ctx* c, struct zx_ff12_EncryptableNameIdentifier_s* x )
{
  struct zx_ns_s* pop_seen = 0;
  struct zx_elem_s* se MAYBE_UNUSED;
#if 1 /* NORMALMODE */
  int len = 1 + sizeof("EncryptableNameIdentifier")-1 + 1 + 2 + sizeof("EncryptableNameIdentifier")-1 + 1;
  
  if (x->gg.g.ns && x->gg.g.ns->prefix_len)
    len += (x->gg.g.ns->prefix_len + 1) * 2;
  if (c->inc_ns_len)
    len += zx_len_inc_ns(c, &pop_seen);
  len += zx_len_xmlns_if_not_seen(c, x->gg.g.ns, &pop_seen);

  len += zx_attr_wo_len(c, x->Format, sizeof("Format")-1, &pop_seen);
  len += zx_attr_wo_len(c, x->IssueInstant, sizeof("IssueInstant")-1, &pop_seen);
  len += zx_attr_wo_len(c, x->NameQualifier, sizeof("NameQualifier")-1, &pop_seen);
  len += zx_attr_wo_len(c, x->Nonce, sizeof("Nonce")-1, &pop_seen);

#else
  /* root node has no begin tag */
  int len = 0;
#endif
  


  len += zx_len_wo_common(c, &x->gg, &pop_seen); 
  zx_pop_seen(pop_seen);
  ENC_LEN_DEBUG(x, "ff12:EncryptableNameIdentifier", len);
  return len;
}

/* FUNC(zx_ENC_SO_ff12_EncryptableNameIdentifier) */

/* Render element into string. The XML attributes and elements are
 * processed in schema order. This is what you generally want for
 * rendering new data structure to a string. The wo pointers are not used. */

/* Called by: */
char* zx_ENC_SO_ff12_EncryptableNameIdentifier(struct zx_ctx* c, struct zx_ff12_EncryptableNameIdentifier_s* x, char* p )
{
  struct zx_elem_s* se MAYBE_UNUSED;
  struct zx_ns_s* pop_seen = 0;
  ENC_LEN_DEBUG_BASE;
#if 1 /* NORMALMODE */
  /* *** in simple_elem case should output ns prefix from ns node. */
  ZX_OUT_TAG(p, "<ff12:EncryptableNameIdentifier");
  if (c->inc_ns)
    zx_add_inc_ns(c, &pop_seen);
  zx_add_xmlns_if_not_seen(c, zx_ns_tab+zx_xmlns_ix_ff12, &pop_seen);

  zx_see_unknown_attrs_ns(c, x->gg.any_attr, &pop_seen);
  p = zx_enc_seen(p, pop_seen); 
  p = zx_attr_so_enc(p, x->Format, " Format=\"", sizeof(" Format=\"")-1);
  p = zx_attr_so_enc(p, x->IssueInstant, " IssueInstant=\"", sizeof(" IssueInstant=\"")-1);
  p = zx_attr_so_enc(p, x->NameQualifier, " NameQualifier=\"", sizeof(" NameQualifier=\"")-1);
  p = zx_attr_so_enc(p, x->Nonce, " Nonce=\"", sizeof(" Nonce=\"")-1);

  p = zx_enc_unknown_attrs(p, x->gg.any_attr);
#else
  /* root node has no begin tag */
#endif
  

  p = zx_enc_so_unknown_elems_and_content(c, p, &x->gg);
  
#if 1 /* NORMALMODE */
  ZX_OUT_CLOSE_TAG(p, "</ff12:EncryptableNameIdentifier>");
  zx_pop_seen(pop_seen);
#else
  /* root node has no end tag either */
#endif
  ENC_LEN_DEBUG(x, "ff12:EncryptableNameIdentifier", p-enc_base);
  return p;
}

/* FUNC(zx_ENC_WO_ff12_EncryptableNameIdentifier) */

/* Render element into string. The XML attributes and elements are
 * processed in wire order by chasing wo pointers. This is what you want for
 * validating signatures on other people's XML documents. */

/* Called by: */
char* zx_ENC_WO_ff12_EncryptableNameIdentifier(struct zx_ctx* c, struct zx_ff12_EncryptableNameIdentifier_s* x, char* p )
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
  ZX_OUT_MEM(p, "EncryptableNameIdentifier", sizeof("EncryptableNameIdentifier")-1);
  qq = p;

  if (c->inc_ns)
    zx_add_inc_ns(c, &pop_seen);
  zx_add_xmlns_if_not_seen(c, x->gg.g.ns, &pop_seen);

  zx_see_unknown_attrs_ns(c, x->gg.any_attr, &pop_seen);
  p = zx_enc_seen(p, pop_seen); 
  p = zx_attr_wo_enc(p, x->Format, "Format=\"", sizeof("Format=\"")-1);
  p = zx_attr_wo_enc(p, x->IssueInstant, "IssueInstant=\"", sizeof("IssueInstant=\"")-1);
  p = zx_attr_wo_enc(p, x->NameQualifier, "NameQualifier=\"", sizeof("NameQualifier=\"")-1);
  p = zx_attr_wo_enc(p, x->Nonce, "Nonce=\"", sizeof("Nonce=\"")-1);

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
  ENC_LEN_DEBUG(x, "ff12:EncryptableNameIdentifier", p-enc_base);
  return p;
}

/* FUNC(zx_EASY_ENC_SO_ff12_EncryptableNameIdentifier) */

/* Called by: */
struct zx_str* zx_EASY_ENC_SO_ff12_EncryptableNameIdentifier(struct zx_ctx* c, struct zx_ff12_EncryptableNameIdentifier_s* x )
{
  int len;
  char* buf;
  c->ns_tab = ZX_ALLOC(c, sizeof(zx_ns_tab));
  memcpy(c->ns_tab, zx_ns_tab, sizeof(zx_ns_tab));
  len = zx_LEN_SO_ff12_EncryptableNameIdentifier(c, x );
  buf = ZX_ALLOC(c, len+1);
  return zx_easy_enc_common(c, zx_ENC_SO_ff12_EncryptableNameIdentifier(c, x, buf ), buf, len);
}

/* FUNC(zx_EASY_ENC_WO_ff12_EncryptableNameIdentifier) */

/* Called by: */
struct zx_str* zx_EASY_ENC_WO_ff12_EncryptableNameIdentifier(struct zx_ctx* c, struct zx_ff12_EncryptableNameIdentifier_s* x )
{
  int len;
  char* buf;
  c->ns_tab = ZX_ALLOC(c, sizeof(zx_ns_tab));
  memcpy(c->ns_tab, zx_ns_tab, sizeof(zx_ns_tab));
  len = zx_LEN_WO_ff12_EncryptableNameIdentifier(c, x );
  buf = ZX_ALLOC(c, len+1);
  return zx_easy_enc_common(c, zx_ENC_WO_ff12_EncryptableNameIdentifier(c, x, buf ), buf, len);
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

#define EL_NAME   ff12_EncryptedNameIdentifier
#define EL_STRUCT zx_ff12_EncryptedNameIdentifier_s
#define EL_NS     ff12
#define EL_TAG    EncryptedNameIdentifier

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

/* FUNC(zx_LEN_SO_ff12_EncryptedNameIdentifier) */

/* Compute length of an element (and its subelements). The XML attributes
 * and elements are processed in schema order. */

/* Called by: */
int zx_LEN_SO_ff12_EncryptedNameIdentifier(struct zx_ctx* c, struct zx_ff12_EncryptedNameIdentifier_s* x )
{
  struct zx_ns_s* pop_seen = 0;
  struct zx_elem_s* se MAYBE_UNUSED;
#if 1 /* NORMALMODE */
  /* *** in simple_elem case should output ns prefix from ns node. */
  int len = sizeof("<ff12:EncryptedNameIdentifier")-1 + 1 + sizeof("</ff12:EncryptedNameIdentifier>")-1;
  if (c->inc_ns_len)
    len += zx_len_inc_ns(c, &pop_seen);
  len += zx_len_xmlns_if_not_seen(c, zx_ns_tab+zx_xmlns_ix_ff12, &pop_seen);


#else
  /* root node has no begin tag */
  int len = 0;
#endif
  
  {
      struct zx_xenc_EncryptedData_s* e;
      for (e = x->EncryptedData; e; e = (struct zx_xenc_EncryptedData_s*)e->gg.g.n)
	  len += zx_LEN_SO_xenc_EncryptedData(c, e);
  }
  {
      struct zx_xenc_EncryptedKey_s* e;
      for (e = x->EncryptedKey; e; e = (struct zx_xenc_EncryptedKey_s*)e->gg.g.n)
	  len += zx_LEN_SO_xenc_EncryptedKey(c, e);
  }


  len += zx_len_so_common(c, &x->gg, &pop_seen);
  zx_pop_seen(pop_seen);
  ENC_LEN_DEBUG(x, "ff12:EncryptedNameIdentifier", len);
  return len;
}

/* FUNC(zx_LEN_WO_ff12_EncryptedNameIdentifier) */

/* Compute length of an element (and its subelements). The XML attributes
 * and elements are processed in wire order and no assumptions
 * are made about namespace prefixes. */

/* Called by: */
int zx_LEN_WO_ff12_EncryptedNameIdentifier(struct zx_ctx* c, struct zx_ff12_EncryptedNameIdentifier_s* x )
{
  struct zx_ns_s* pop_seen = 0;
  struct zx_elem_s* se MAYBE_UNUSED;
#if 1 /* NORMALMODE */
  int len = 1 + sizeof("EncryptedNameIdentifier")-1 + 1 + 2 + sizeof("EncryptedNameIdentifier")-1 + 1;
  
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
      struct zx_xenc_EncryptedData_s* e;
      for (e = x->EncryptedData; e; e = (struct zx_xenc_EncryptedData_s*)e->gg.g.n)
	  len += zx_LEN_WO_xenc_EncryptedData(c, e);
  }
  {
      struct zx_xenc_EncryptedKey_s* e;
      for (e = x->EncryptedKey; e; e = (struct zx_xenc_EncryptedKey_s*)e->gg.g.n)
	  len += zx_LEN_WO_xenc_EncryptedKey(c, e);
  }


  len += zx_len_wo_common(c, &x->gg, &pop_seen); 
  zx_pop_seen(pop_seen);
  ENC_LEN_DEBUG(x, "ff12:EncryptedNameIdentifier", len);
  return len;
}

/* FUNC(zx_ENC_SO_ff12_EncryptedNameIdentifier) */

/* Render element into string. The XML attributes and elements are
 * processed in schema order. This is what you generally want for
 * rendering new data structure to a string. The wo pointers are not used. */

/* Called by: */
char* zx_ENC_SO_ff12_EncryptedNameIdentifier(struct zx_ctx* c, struct zx_ff12_EncryptedNameIdentifier_s* x, char* p )
{
  struct zx_elem_s* se MAYBE_UNUSED;
  struct zx_ns_s* pop_seen = 0;
  ENC_LEN_DEBUG_BASE;
#if 1 /* NORMALMODE */
  /* *** in simple_elem case should output ns prefix from ns node. */
  ZX_OUT_TAG(p, "<ff12:EncryptedNameIdentifier");
  if (c->inc_ns)
    zx_add_inc_ns(c, &pop_seen);
  zx_add_xmlns_if_not_seen(c, zx_ns_tab+zx_xmlns_ix_ff12, &pop_seen);

  zx_see_unknown_attrs_ns(c, x->gg.any_attr, &pop_seen);
  p = zx_enc_seen(p, pop_seen); 

  p = zx_enc_unknown_attrs(p, x->gg.any_attr);
#else
  /* root node has no begin tag */
#endif
  
  {
      struct zx_xenc_EncryptedData_s* e;
      for (e = x->EncryptedData; e; e = (struct zx_xenc_EncryptedData_s*)e->gg.g.n)
	  p = zx_ENC_SO_xenc_EncryptedData(c, e, p);
  }
  {
      struct zx_xenc_EncryptedKey_s* e;
      for (e = x->EncryptedKey; e; e = (struct zx_xenc_EncryptedKey_s*)e->gg.g.n)
	  p = zx_ENC_SO_xenc_EncryptedKey(c, e, p);
  }

  p = zx_enc_so_unknown_elems_and_content(c, p, &x->gg);
  
#if 1 /* NORMALMODE */
  ZX_OUT_CLOSE_TAG(p, "</ff12:EncryptedNameIdentifier>");
  zx_pop_seen(pop_seen);
#else
  /* root node has no end tag either */
#endif
  ENC_LEN_DEBUG(x, "ff12:EncryptedNameIdentifier", p-enc_base);
  return p;
}

/* FUNC(zx_ENC_WO_ff12_EncryptedNameIdentifier) */

/* Render element into string. The XML attributes and elements are
 * processed in wire order by chasing wo pointers. This is what you want for
 * validating signatures on other people's XML documents. */

/* Called by: */
char* zx_ENC_WO_ff12_EncryptedNameIdentifier(struct zx_ctx* c, struct zx_ff12_EncryptedNameIdentifier_s* x, char* p )
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
  ZX_OUT_MEM(p, "EncryptedNameIdentifier", sizeof("EncryptedNameIdentifier")-1);
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
  ENC_LEN_DEBUG(x, "ff12:EncryptedNameIdentifier", p-enc_base);
  return p;
}

/* FUNC(zx_EASY_ENC_SO_ff12_EncryptedNameIdentifier) */

/* Called by: */
struct zx_str* zx_EASY_ENC_SO_ff12_EncryptedNameIdentifier(struct zx_ctx* c, struct zx_ff12_EncryptedNameIdentifier_s* x )
{
  int len;
  char* buf;
  c->ns_tab = ZX_ALLOC(c, sizeof(zx_ns_tab));
  memcpy(c->ns_tab, zx_ns_tab, sizeof(zx_ns_tab));
  len = zx_LEN_SO_ff12_EncryptedNameIdentifier(c, x );
  buf = ZX_ALLOC(c, len+1);
  return zx_easy_enc_common(c, zx_ENC_SO_ff12_EncryptedNameIdentifier(c, x, buf ), buf, len);
}

/* FUNC(zx_EASY_ENC_WO_ff12_EncryptedNameIdentifier) */

/* Called by: */
struct zx_str* zx_EASY_ENC_WO_ff12_EncryptedNameIdentifier(struct zx_ctx* c, struct zx_ff12_EncryptedNameIdentifier_s* x )
{
  int len;
  char* buf;
  c->ns_tab = ZX_ALLOC(c, sizeof(zx_ns_tab));
  memcpy(c->ns_tab, zx_ns_tab, sizeof(zx_ns_tab));
  len = zx_LEN_WO_ff12_EncryptedNameIdentifier(c, x );
  buf = ZX_ALLOC(c, len+1);
  return zx_easy_enc_common(c, zx_ENC_WO_ff12_EncryptedNameIdentifier(c, x, buf ), buf, len);
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

#define EL_NAME   ff12_Extension
#define EL_STRUCT zx_ff12_Extension_s
#define EL_NS     ff12
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

/* FUNC(zx_LEN_SO_ff12_Extension) */

/* Compute length of an element (and its subelements). The XML attributes
 * and elements are processed in schema order. */

/* Called by: */
int zx_LEN_SO_ff12_Extension(struct zx_ctx* c, struct zx_ff12_Extension_s* x )
{
  struct zx_ns_s* pop_seen = 0;
  struct zx_elem_s* se MAYBE_UNUSED;
#if 1 /* NORMALMODE */
  /* *** in simple_elem case should output ns prefix from ns node. */
  int len = sizeof("<ff12:Extension")-1 + 1 + sizeof("</ff12:Extension>")-1;
  if (c->inc_ns_len)
    len += zx_len_inc_ns(c, &pop_seen);
  len += zx_len_xmlns_if_not_seen(c, zx_ns_tab+zx_xmlns_ix_ff12, &pop_seen);


#else
  /* root node has no begin tag */
  int len = 0;
#endif
  


  len += zx_len_so_common(c, &x->gg, &pop_seen);
  zx_pop_seen(pop_seen);
  ENC_LEN_DEBUG(x, "ff12:Extension", len);
  return len;
}

/* FUNC(zx_LEN_WO_ff12_Extension) */

/* Compute length of an element (and its subelements). The XML attributes
 * and elements are processed in wire order and no assumptions
 * are made about namespace prefixes. */

/* Called by: */
int zx_LEN_WO_ff12_Extension(struct zx_ctx* c, struct zx_ff12_Extension_s* x )
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
  


  len += zx_len_wo_common(c, &x->gg, &pop_seen); 
  zx_pop_seen(pop_seen);
  ENC_LEN_DEBUG(x, "ff12:Extension", len);
  return len;
}

/* FUNC(zx_ENC_SO_ff12_Extension) */

/* Render element into string. The XML attributes and elements are
 * processed in schema order. This is what you generally want for
 * rendering new data structure to a string. The wo pointers are not used. */

/* Called by: */
char* zx_ENC_SO_ff12_Extension(struct zx_ctx* c, struct zx_ff12_Extension_s* x, char* p )
{
  struct zx_elem_s* se MAYBE_UNUSED;
  struct zx_ns_s* pop_seen = 0;
  ENC_LEN_DEBUG_BASE;
#if 1 /* NORMALMODE */
  /* *** in simple_elem case should output ns prefix from ns node. */
  ZX_OUT_TAG(p, "<ff12:Extension");
  if (c->inc_ns)
    zx_add_inc_ns(c, &pop_seen);
  zx_add_xmlns_if_not_seen(c, zx_ns_tab+zx_xmlns_ix_ff12, &pop_seen);

  zx_see_unknown_attrs_ns(c, x->gg.any_attr, &pop_seen);
  p = zx_enc_seen(p, pop_seen); 

  p = zx_enc_unknown_attrs(p, x->gg.any_attr);
#else
  /* root node has no begin tag */
#endif
  

  p = zx_enc_so_unknown_elems_and_content(c, p, &x->gg);
  
#if 1 /* NORMALMODE */
  ZX_OUT_CLOSE_TAG(p, "</ff12:Extension>");
  zx_pop_seen(pop_seen);
#else
  /* root node has no end tag either */
#endif
  ENC_LEN_DEBUG(x, "ff12:Extension", p-enc_base);
  return p;
}

/* FUNC(zx_ENC_WO_ff12_Extension) */

/* Render element into string. The XML attributes and elements are
 * processed in wire order by chasing wo pointers. This is what you want for
 * validating signatures on other people's XML documents. */

/* Called by: */
char* zx_ENC_WO_ff12_Extension(struct zx_ctx* c, struct zx_ff12_Extension_s* x, char* p )
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
  ZX_OUT_MEM(p, "Extension", sizeof("Extension")-1);
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
  ENC_LEN_DEBUG(x, "ff12:Extension", p-enc_base);
  return p;
}

/* FUNC(zx_EASY_ENC_SO_ff12_Extension) */

/* Called by: */
struct zx_str* zx_EASY_ENC_SO_ff12_Extension(struct zx_ctx* c, struct zx_ff12_Extension_s* x )
{
  int len;
  char* buf;
  c->ns_tab = ZX_ALLOC(c, sizeof(zx_ns_tab));
  memcpy(c->ns_tab, zx_ns_tab, sizeof(zx_ns_tab));
  len = zx_LEN_SO_ff12_Extension(c, x );
  buf = ZX_ALLOC(c, len+1);
  return zx_easy_enc_common(c, zx_ENC_SO_ff12_Extension(c, x, buf ), buf, len);
}

/* FUNC(zx_EASY_ENC_WO_ff12_Extension) */

/* Called by: */
struct zx_str* zx_EASY_ENC_WO_ff12_Extension(struct zx_ctx* c, struct zx_ff12_Extension_s* x )
{
  int len;
  char* buf;
  c->ns_tab = ZX_ALLOC(c, sizeof(zx_ns_tab));
  memcpy(c->ns_tab, zx_ns_tab, sizeof(zx_ns_tab));
  len = zx_LEN_WO_ff12_Extension(c, x );
  buf = ZX_ALLOC(c, len+1);
  return zx_easy_enc_common(c, zx_ENC_WO_ff12_Extension(c, x, buf ), buf, len);
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

#define EL_NAME   ff12_FederationTerminationNotification
#define EL_STRUCT zx_ff12_FederationTerminationNotification_s
#define EL_NS     ff12
#define EL_TAG    FederationTerminationNotification

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

/* FUNC(zx_LEN_SO_ff12_FederationTerminationNotification) */

/* Compute length of an element (and its subelements). The XML attributes
 * and elements are processed in schema order. */

/* Called by: */
int zx_LEN_SO_ff12_FederationTerminationNotification(struct zx_ctx* c, struct zx_ff12_FederationTerminationNotification_s* x )
{
  struct zx_ns_s* pop_seen = 0;
  struct zx_elem_s* se MAYBE_UNUSED;
#if 1 /* NORMALMODE */
  /* *** in simple_elem case should output ns prefix from ns node. */
  int len = sizeof("<ff12:FederationTerminationNotification")-1 + 1 + sizeof("</ff12:FederationTerminationNotification>")-1;
  if (c->inc_ns_len)
    len += zx_len_inc_ns(c, &pop_seen);
  len += zx_len_xmlns_if_not_seen(c, zx_ns_tab+zx_xmlns_ix_ff12, &pop_seen);

  len += zx_attr_so_len(c, x->IssueInstant, sizeof("IssueInstant")-1, &pop_seen);
  len += zx_attr_so_len(c, x->MajorVersion, sizeof("MajorVersion")-1, &pop_seen);
  len += zx_attr_so_len(c, x->MinorVersion, sizeof("MinorVersion")-1, &pop_seen);
  len += zx_attr_so_len(c, x->RequestID, sizeof("RequestID")-1, &pop_seen);
  len += zx_attr_so_len(c, x->consent, sizeof("consent")-1, &pop_seen);

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
  {
      struct zx_ff12_Extension_s* e;
      for (e = x->Extension; e; e = (struct zx_ff12_Extension_s*)e->gg.g.n)
	  len += zx_LEN_SO_ff12_Extension(c, e);
  }
  for (se = x->ProviderID; se; se = (struct zx_elem_s*)se->g.n)
    len += zx_LEN_SO_simple_elem(c,se, sizeof("ff12:ProviderID")-1, zx_ns_tab+zx_xmlns_ix_ff12);
  {
      struct zx_sa11_NameIdentifier_s* e;
      for (e = x->NameIdentifier; e; e = (struct zx_sa11_NameIdentifier_s*)e->gg.g.n)
	  len += zx_LEN_SO_sa11_NameIdentifier(c, e);
  }


  len += zx_len_so_common(c, &x->gg, &pop_seen);
  zx_pop_seen(pop_seen);
  ENC_LEN_DEBUG(x, "ff12:FederationTerminationNotification", len);
  return len;
}

/* FUNC(zx_LEN_WO_ff12_FederationTerminationNotification) */

/* Compute length of an element (and its subelements). The XML attributes
 * and elements are processed in wire order and no assumptions
 * are made about namespace prefixes. */

/* Called by: */
int zx_LEN_WO_ff12_FederationTerminationNotification(struct zx_ctx* c, struct zx_ff12_FederationTerminationNotification_s* x )
{
  struct zx_ns_s* pop_seen = 0;
  struct zx_elem_s* se MAYBE_UNUSED;
#if 1 /* NORMALMODE */
  int len = 1 + sizeof("FederationTerminationNotification")-1 + 1 + 2 + sizeof("FederationTerminationNotification")-1 + 1;
  
  if (x->gg.g.ns && x->gg.g.ns->prefix_len)
    len += (x->gg.g.ns->prefix_len + 1) * 2;
  if (c->inc_ns_len)
    len += zx_len_inc_ns(c, &pop_seen);
  len += zx_len_xmlns_if_not_seen(c, x->gg.g.ns, &pop_seen);

  len += zx_attr_wo_len(c, x->IssueInstant, sizeof("IssueInstant")-1, &pop_seen);
  len += zx_attr_wo_len(c, x->MajorVersion, sizeof("MajorVersion")-1, &pop_seen);
  len += zx_attr_wo_len(c, x->MinorVersion, sizeof("MinorVersion")-1, &pop_seen);
  len += zx_attr_wo_len(c, x->RequestID, sizeof("RequestID")-1, &pop_seen);
  len += zx_attr_wo_len(c, x->consent, sizeof("consent")-1, &pop_seen);

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
  {
      struct zx_ff12_Extension_s* e;
      for (e = x->Extension; e; e = (struct zx_ff12_Extension_s*)e->gg.g.n)
	  len += zx_LEN_WO_ff12_Extension(c, e);
  }
  for (se = x->ProviderID; se; se = (struct zx_elem_s*)se->g.n)
    len += zx_LEN_WO_simple_elem(c, se, sizeof("ProviderID")-1);
  {
      struct zx_sa11_NameIdentifier_s* e;
      for (e = x->NameIdentifier; e; e = (struct zx_sa11_NameIdentifier_s*)e->gg.g.n)
	  len += zx_LEN_WO_sa11_NameIdentifier(c, e);
  }


  len += zx_len_wo_common(c, &x->gg, &pop_seen); 
  zx_pop_seen(pop_seen);
  ENC_LEN_DEBUG(x, "ff12:FederationTerminationNotification", len);
  return len;
}

/* FUNC(zx_ENC_SO_ff12_FederationTerminationNotification) */

/* Render element into string. The XML attributes and elements are
 * processed in schema order. This is what you generally want for
 * rendering new data structure to a string. The wo pointers are not used. */

/* Called by: */
char* zx_ENC_SO_ff12_FederationTerminationNotification(struct zx_ctx* c, struct zx_ff12_FederationTerminationNotification_s* x, char* p )
{
  struct zx_elem_s* se MAYBE_UNUSED;
  struct zx_ns_s* pop_seen = 0;
  ENC_LEN_DEBUG_BASE;
#if 1 /* NORMALMODE */
  /* *** in simple_elem case should output ns prefix from ns node. */
  ZX_OUT_TAG(p, "<ff12:FederationTerminationNotification");
  if (c->inc_ns)
    zx_add_inc_ns(c, &pop_seen);
  zx_add_xmlns_if_not_seen(c, zx_ns_tab+zx_xmlns_ix_ff12, &pop_seen);

  zx_see_unknown_attrs_ns(c, x->gg.any_attr, &pop_seen);
  p = zx_enc_seen(p, pop_seen); 
  p = zx_attr_so_enc(p, x->IssueInstant, " IssueInstant=\"", sizeof(" IssueInstant=\"")-1);
  p = zx_attr_so_enc(p, x->MajorVersion, " MajorVersion=\"", sizeof(" MajorVersion=\"")-1);
  p = zx_attr_so_enc(p, x->MinorVersion, " MinorVersion=\"", sizeof(" MinorVersion=\"")-1);
  p = zx_attr_so_enc(p, x->RequestID, " RequestID=\"", sizeof(" RequestID=\"")-1);
  p = zx_attr_so_enc(p, x->consent, " consent=\"", sizeof(" consent=\"")-1);

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
  {
      struct zx_ff12_Extension_s* e;
      for (e = x->Extension; e; e = (struct zx_ff12_Extension_s*)e->gg.g.n)
	  p = zx_ENC_SO_ff12_Extension(c, e, p);
  }
  for (se = x->ProviderID; se; se = (struct zx_elem_s*)se->g.n)
    p = zx_ENC_SO_simple_elem(c, se, p, "ff12:ProviderID", sizeof("ff12:ProviderID")-1, zx_ns_tab+zx_xmlns_ix_ff12);
  {
      struct zx_sa11_NameIdentifier_s* e;
      for (e = x->NameIdentifier; e; e = (struct zx_sa11_NameIdentifier_s*)e->gg.g.n)
	  p = zx_ENC_SO_sa11_NameIdentifier(c, e, p);
  }

  p = zx_enc_so_unknown_elems_and_content(c, p, &x->gg);
  
#if 1 /* NORMALMODE */
  ZX_OUT_CLOSE_TAG(p, "</ff12:FederationTerminationNotification>");
  zx_pop_seen(pop_seen);
#else
  /* root node has no end tag either */
#endif
  ENC_LEN_DEBUG(x, "ff12:FederationTerminationNotification", p-enc_base);
  return p;
}

/* FUNC(zx_ENC_WO_ff12_FederationTerminationNotification) */

/* Render element into string. The XML attributes and elements are
 * processed in wire order by chasing wo pointers. This is what you want for
 * validating signatures on other people's XML documents. */

/* Called by: */
char* zx_ENC_WO_ff12_FederationTerminationNotification(struct zx_ctx* c, struct zx_ff12_FederationTerminationNotification_s* x, char* p )
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
  ZX_OUT_MEM(p, "FederationTerminationNotification", sizeof("FederationTerminationNotification")-1);
  qq = p;

  if (c->inc_ns)
    zx_add_inc_ns(c, &pop_seen);
  zx_add_xmlns_if_not_seen(c, x->gg.g.ns, &pop_seen);

  zx_see_unknown_attrs_ns(c, x->gg.any_attr, &pop_seen);
  p = zx_enc_seen(p, pop_seen); 
  p = zx_attr_wo_enc(p, x->IssueInstant, "IssueInstant=\"", sizeof("IssueInstant=\"")-1);
  p = zx_attr_wo_enc(p, x->MajorVersion, "MajorVersion=\"", sizeof("MajorVersion=\"")-1);
  p = zx_attr_wo_enc(p, x->MinorVersion, "MinorVersion=\"", sizeof("MinorVersion=\"")-1);
  p = zx_attr_wo_enc(p, x->RequestID, "RequestID=\"", sizeof("RequestID=\"")-1);
  p = zx_attr_wo_enc(p, x->consent, "consent=\"", sizeof("consent=\"")-1);

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
  ENC_LEN_DEBUG(x, "ff12:FederationTerminationNotification", p-enc_base);
  return p;
}

/* FUNC(zx_EASY_ENC_SO_ff12_FederationTerminationNotification) */

/* Called by: */
struct zx_str* zx_EASY_ENC_SO_ff12_FederationTerminationNotification(struct zx_ctx* c, struct zx_ff12_FederationTerminationNotification_s* x )
{
  int len;
  char* buf;
  c->ns_tab = ZX_ALLOC(c, sizeof(zx_ns_tab));
  memcpy(c->ns_tab, zx_ns_tab, sizeof(zx_ns_tab));
  len = zx_LEN_SO_ff12_FederationTerminationNotification(c, x );
  buf = ZX_ALLOC(c, len+1);
  return zx_easy_enc_common(c, zx_ENC_SO_ff12_FederationTerminationNotification(c, x, buf ), buf, len);
}

/* FUNC(zx_EASY_ENC_WO_ff12_FederationTerminationNotification) */

/* Called by: */
struct zx_str* zx_EASY_ENC_WO_ff12_FederationTerminationNotification(struct zx_ctx* c, struct zx_ff12_FederationTerminationNotification_s* x )
{
  int len;
  char* buf;
  c->ns_tab = ZX_ALLOC(c, sizeof(zx_ns_tab));
  memcpy(c->ns_tab, zx_ns_tab, sizeof(zx_ns_tab));
  len = zx_LEN_WO_ff12_FederationTerminationNotification(c, x );
  buf = ZX_ALLOC(c, len+1);
  return zx_easy_enc_common(c, zx_ENC_WO_ff12_FederationTerminationNotification(c, x, buf ), buf, len);
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

#define EL_NAME   ff12_IDPEntries
#define EL_STRUCT zx_ff12_IDPEntries_s
#define EL_NS     ff12
#define EL_TAG    IDPEntries

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

/* FUNC(zx_LEN_SO_ff12_IDPEntries) */

/* Compute length of an element (and its subelements). The XML attributes
 * and elements are processed in schema order. */

/* Called by: */
int zx_LEN_SO_ff12_IDPEntries(struct zx_ctx* c, struct zx_ff12_IDPEntries_s* x )
{
  struct zx_ns_s* pop_seen = 0;
  struct zx_elem_s* se MAYBE_UNUSED;
#if 1 /* NORMALMODE */
  /* *** in simple_elem case should output ns prefix from ns node. */
  int len = sizeof("<ff12:IDPEntries")-1 + 1 + sizeof("</ff12:IDPEntries>")-1;
  if (c->inc_ns_len)
    len += zx_len_inc_ns(c, &pop_seen);
  len += zx_len_xmlns_if_not_seen(c, zx_ns_tab+zx_xmlns_ix_ff12, &pop_seen);


#else
  /* root node has no begin tag */
  int len = 0;
#endif
  
  {
      struct zx_ff12_IDPEntry_s* e;
      for (e = x->IDPEntry; e; e = (struct zx_ff12_IDPEntry_s*)e->gg.g.n)
	  len += zx_LEN_SO_ff12_IDPEntry(c, e);
  }


  len += zx_len_so_common(c, &x->gg, &pop_seen);
  zx_pop_seen(pop_seen);
  ENC_LEN_DEBUG(x, "ff12:IDPEntries", len);
  return len;
}

/* FUNC(zx_LEN_WO_ff12_IDPEntries) */

/* Compute length of an element (and its subelements). The XML attributes
 * and elements are processed in wire order and no assumptions
 * are made about namespace prefixes. */

/* Called by: */
int zx_LEN_WO_ff12_IDPEntries(struct zx_ctx* c, struct zx_ff12_IDPEntries_s* x )
{
  struct zx_ns_s* pop_seen = 0;
  struct zx_elem_s* se MAYBE_UNUSED;
#if 1 /* NORMALMODE */
  int len = 1 + sizeof("IDPEntries")-1 + 1 + 2 + sizeof("IDPEntries")-1 + 1;
  
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
      struct zx_ff12_IDPEntry_s* e;
      for (e = x->IDPEntry; e; e = (struct zx_ff12_IDPEntry_s*)e->gg.g.n)
	  len += zx_LEN_WO_ff12_IDPEntry(c, e);
  }


  len += zx_len_wo_common(c, &x->gg, &pop_seen); 
  zx_pop_seen(pop_seen);
  ENC_LEN_DEBUG(x, "ff12:IDPEntries", len);
  return len;
}

/* FUNC(zx_ENC_SO_ff12_IDPEntries) */

/* Render element into string. The XML attributes and elements are
 * processed in schema order. This is what you generally want for
 * rendering new data structure to a string. The wo pointers are not used. */

/* Called by: */
char* zx_ENC_SO_ff12_IDPEntries(struct zx_ctx* c, struct zx_ff12_IDPEntries_s* x, char* p )
{
  struct zx_elem_s* se MAYBE_UNUSED;
  struct zx_ns_s* pop_seen = 0;
  ENC_LEN_DEBUG_BASE;
#if 1 /* NORMALMODE */
  /* *** in simple_elem case should output ns prefix from ns node. */
  ZX_OUT_TAG(p, "<ff12:IDPEntries");
  if (c->inc_ns)
    zx_add_inc_ns(c, &pop_seen);
  zx_add_xmlns_if_not_seen(c, zx_ns_tab+zx_xmlns_ix_ff12, &pop_seen);

  zx_see_unknown_attrs_ns(c, x->gg.any_attr, &pop_seen);
  p = zx_enc_seen(p, pop_seen); 

  p = zx_enc_unknown_attrs(p, x->gg.any_attr);
#else
  /* root node has no begin tag */
#endif
  
  {
      struct zx_ff12_IDPEntry_s* e;
      for (e = x->IDPEntry; e; e = (struct zx_ff12_IDPEntry_s*)e->gg.g.n)
	  p = zx_ENC_SO_ff12_IDPEntry(c, e, p);
  }

  p = zx_enc_so_unknown_elems_and_content(c, p, &x->gg);
  
#if 1 /* NORMALMODE */
  ZX_OUT_CLOSE_TAG(p, "</ff12:IDPEntries>");
  zx_pop_seen(pop_seen);
#else
  /* root node has no end tag either */
#endif
  ENC_LEN_DEBUG(x, "ff12:IDPEntries", p-enc_base);
  return p;
}

/* FUNC(zx_ENC_WO_ff12_IDPEntries) */

/* Render element into string. The XML attributes and elements are
 * processed in wire order by chasing wo pointers. This is what you want for
 * validating signatures on other people's XML documents. */

/* Called by: */
char* zx_ENC_WO_ff12_IDPEntries(struct zx_ctx* c, struct zx_ff12_IDPEntries_s* x, char* p )
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
  ZX_OUT_MEM(p, "IDPEntries", sizeof("IDPEntries")-1);
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
  ENC_LEN_DEBUG(x, "ff12:IDPEntries", p-enc_base);
  return p;
}

/* FUNC(zx_EASY_ENC_SO_ff12_IDPEntries) */

/* Called by: */
struct zx_str* zx_EASY_ENC_SO_ff12_IDPEntries(struct zx_ctx* c, struct zx_ff12_IDPEntries_s* x )
{
  int len;
  char* buf;
  c->ns_tab = ZX_ALLOC(c, sizeof(zx_ns_tab));
  memcpy(c->ns_tab, zx_ns_tab, sizeof(zx_ns_tab));
  len = zx_LEN_SO_ff12_IDPEntries(c, x );
  buf = ZX_ALLOC(c, len+1);
  return zx_easy_enc_common(c, zx_ENC_SO_ff12_IDPEntries(c, x, buf ), buf, len);
}

/* FUNC(zx_EASY_ENC_WO_ff12_IDPEntries) */

/* Called by: */
struct zx_str* zx_EASY_ENC_WO_ff12_IDPEntries(struct zx_ctx* c, struct zx_ff12_IDPEntries_s* x )
{
  int len;
  char* buf;
  c->ns_tab = ZX_ALLOC(c, sizeof(zx_ns_tab));
  memcpy(c->ns_tab, zx_ns_tab, sizeof(zx_ns_tab));
  len = zx_LEN_WO_ff12_IDPEntries(c, x );
  buf = ZX_ALLOC(c, len+1);
  return zx_easy_enc_common(c, zx_ENC_WO_ff12_IDPEntries(c, x, buf ), buf, len);
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

#define EL_NAME   ff12_IDPEntry
#define EL_STRUCT zx_ff12_IDPEntry_s
#define EL_NS     ff12
#define EL_TAG    IDPEntry

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

/* FUNC(zx_LEN_SO_ff12_IDPEntry) */

/* Compute length of an element (and its subelements). The XML attributes
 * and elements are processed in schema order. */

/* Called by: */
int zx_LEN_SO_ff12_IDPEntry(struct zx_ctx* c, struct zx_ff12_IDPEntry_s* x )
{
  struct zx_ns_s* pop_seen = 0;
  struct zx_elem_s* se MAYBE_UNUSED;
#if 1 /* NORMALMODE */
  /* *** in simple_elem case should output ns prefix from ns node. */
  int len = sizeof("<ff12:IDPEntry")-1 + 1 + sizeof("</ff12:IDPEntry>")-1;
  if (c->inc_ns_len)
    len += zx_len_inc_ns(c, &pop_seen);
  len += zx_len_xmlns_if_not_seen(c, zx_ns_tab+zx_xmlns_ix_ff12, &pop_seen);


#else
  /* root node has no begin tag */
  int len = 0;
#endif
  
  for (se = x->ProviderID; se; se = (struct zx_elem_s*)se->g.n)
    len += zx_LEN_SO_simple_elem(c,se, sizeof("ff12:ProviderID")-1, zx_ns_tab+zx_xmlns_ix_ff12);
  for (se = x->ProviderName; se; se = (struct zx_elem_s*)se->g.n)
    len += zx_LEN_SO_simple_elem(c,se, sizeof("ff12:ProviderName")-1, zx_ns_tab+zx_xmlns_ix_ff12);
  for (se = x->Loc; se; se = (struct zx_elem_s*)se->g.n)
    len += zx_LEN_SO_simple_elem(c,se, sizeof("ff12:Loc")-1, zx_ns_tab+zx_xmlns_ix_ff12);


  len += zx_len_so_common(c, &x->gg, &pop_seen);
  zx_pop_seen(pop_seen);
  ENC_LEN_DEBUG(x, "ff12:IDPEntry", len);
  return len;
}

/* FUNC(zx_LEN_WO_ff12_IDPEntry) */

/* Compute length of an element (and its subelements). The XML attributes
 * and elements are processed in wire order and no assumptions
 * are made about namespace prefixes. */

/* Called by: */
int zx_LEN_WO_ff12_IDPEntry(struct zx_ctx* c, struct zx_ff12_IDPEntry_s* x )
{
  struct zx_ns_s* pop_seen = 0;
  struct zx_elem_s* se MAYBE_UNUSED;
#if 1 /* NORMALMODE */
  int len = 1 + sizeof("IDPEntry")-1 + 1 + 2 + sizeof("IDPEntry")-1 + 1;
  
  if (x->gg.g.ns && x->gg.g.ns->prefix_len)
    len += (x->gg.g.ns->prefix_len + 1) * 2;
  if (c->inc_ns_len)
    len += zx_len_inc_ns(c, &pop_seen);
  len += zx_len_xmlns_if_not_seen(c, x->gg.g.ns, &pop_seen);


#else
  /* root node has no begin tag */
  int len = 0;
#endif
  
  for (se = x->ProviderID; se; se = (struct zx_elem_s*)se->g.n)
    len += zx_LEN_WO_simple_elem(c, se, sizeof("ProviderID")-1);
  for (se = x->ProviderName; se; se = (struct zx_elem_s*)se->g.n)
    len += zx_LEN_WO_simple_elem(c, se, sizeof("ProviderName")-1);
  for (se = x->Loc; se; se = (struct zx_elem_s*)se->g.n)
    len += zx_LEN_WO_simple_elem(c, se, sizeof("Loc")-1);


  len += zx_len_wo_common(c, &x->gg, &pop_seen); 
  zx_pop_seen(pop_seen);
  ENC_LEN_DEBUG(x, "ff12:IDPEntry", len);
  return len;
}

/* FUNC(zx_ENC_SO_ff12_IDPEntry) */

/* Render element into string. The XML attributes and elements are
 * processed in schema order. This is what you generally want for
 * rendering new data structure to a string. The wo pointers are not used. */

/* Called by: */
char* zx_ENC_SO_ff12_IDPEntry(struct zx_ctx* c, struct zx_ff12_IDPEntry_s* x, char* p )
{
  struct zx_elem_s* se MAYBE_UNUSED;
  struct zx_ns_s* pop_seen = 0;
  ENC_LEN_DEBUG_BASE;
#if 1 /* NORMALMODE */
  /* *** in simple_elem case should output ns prefix from ns node. */
  ZX_OUT_TAG(p, "<ff12:IDPEntry");
  if (c->inc_ns)
    zx_add_inc_ns(c, &pop_seen);
  zx_add_xmlns_if_not_seen(c, zx_ns_tab+zx_xmlns_ix_ff12, &pop_seen);

  zx_see_unknown_attrs_ns(c, x->gg.any_attr, &pop_seen);
  p = zx_enc_seen(p, pop_seen); 

  p = zx_enc_unknown_attrs(p, x->gg.any_attr);
#else
  /* root node has no begin tag */
#endif
  
  for (se = x->ProviderID; se; se = (struct zx_elem_s*)se->g.n)
    p = zx_ENC_SO_simple_elem(c, se, p, "ff12:ProviderID", sizeof("ff12:ProviderID")-1, zx_ns_tab+zx_xmlns_ix_ff12);
  for (se = x->ProviderName; se; se = (struct zx_elem_s*)se->g.n)
    p = zx_ENC_SO_simple_elem(c, se, p, "ff12:ProviderName", sizeof("ff12:ProviderName")-1, zx_ns_tab+zx_xmlns_ix_ff12);
  for (se = x->Loc; se; se = (struct zx_elem_s*)se->g.n)
    p = zx_ENC_SO_simple_elem(c, se, p, "ff12:Loc", sizeof("ff12:Loc")-1, zx_ns_tab+zx_xmlns_ix_ff12);

  p = zx_enc_so_unknown_elems_and_content(c, p, &x->gg);
  
#if 1 /* NORMALMODE */
  ZX_OUT_CLOSE_TAG(p, "</ff12:IDPEntry>");
  zx_pop_seen(pop_seen);
#else
  /* root node has no end tag either */
#endif
  ENC_LEN_DEBUG(x, "ff12:IDPEntry", p-enc_base);
  return p;
}

/* FUNC(zx_ENC_WO_ff12_IDPEntry) */

/* Render element into string. The XML attributes and elements are
 * processed in wire order by chasing wo pointers. This is what you want for
 * validating signatures on other people's XML documents. */

/* Called by: */
char* zx_ENC_WO_ff12_IDPEntry(struct zx_ctx* c, struct zx_ff12_IDPEntry_s* x, char* p )
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
  ZX_OUT_MEM(p, "IDPEntry", sizeof("IDPEntry")-1);
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
  ENC_LEN_DEBUG(x, "ff12:IDPEntry", p-enc_base);
  return p;
}

/* FUNC(zx_EASY_ENC_SO_ff12_IDPEntry) */

/* Called by: */
struct zx_str* zx_EASY_ENC_SO_ff12_IDPEntry(struct zx_ctx* c, struct zx_ff12_IDPEntry_s* x )
{
  int len;
  char* buf;
  c->ns_tab = ZX_ALLOC(c, sizeof(zx_ns_tab));
  memcpy(c->ns_tab, zx_ns_tab, sizeof(zx_ns_tab));
  len = zx_LEN_SO_ff12_IDPEntry(c, x );
  buf = ZX_ALLOC(c, len+1);
  return zx_easy_enc_common(c, zx_ENC_SO_ff12_IDPEntry(c, x, buf ), buf, len);
}

/* FUNC(zx_EASY_ENC_WO_ff12_IDPEntry) */

/* Called by: */
struct zx_str* zx_EASY_ENC_WO_ff12_IDPEntry(struct zx_ctx* c, struct zx_ff12_IDPEntry_s* x )
{
  int len;
  char* buf;
  c->ns_tab = ZX_ALLOC(c, sizeof(zx_ns_tab));
  memcpy(c->ns_tab, zx_ns_tab, sizeof(zx_ns_tab));
  len = zx_LEN_WO_ff12_IDPEntry(c, x );
  buf = ZX_ALLOC(c, len+1);
  return zx_easy_enc_common(c, zx_ENC_WO_ff12_IDPEntry(c, x, buf ), buf, len);
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

#define EL_NAME   ff12_IDPList
#define EL_STRUCT zx_ff12_IDPList_s
#define EL_NS     ff12
#define EL_TAG    IDPList

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

/* FUNC(zx_LEN_SO_ff12_IDPList) */

/* Compute length of an element (and its subelements). The XML attributes
 * and elements are processed in schema order. */

/* Called by: */
int zx_LEN_SO_ff12_IDPList(struct zx_ctx* c, struct zx_ff12_IDPList_s* x )
{
  struct zx_ns_s* pop_seen = 0;
  struct zx_elem_s* se MAYBE_UNUSED;
#if 1 /* NORMALMODE */
  /* *** in simple_elem case should output ns prefix from ns node. */
  int len = sizeof("<ff12:IDPList")-1 + 1 + sizeof("</ff12:IDPList>")-1;
  if (c->inc_ns_len)
    len += zx_len_inc_ns(c, &pop_seen);
  len += zx_len_xmlns_if_not_seen(c, zx_ns_tab+zx_xmlns_ix_ff12, &pop_seen);


#else
  /* root node has no begin tag */
  int len = 0;
#endif
  
  {
      struct zx_ff12_IDPEntries_s* e;
      for (e = x->IDPEntries; e; e = (struct zx_ff12_IDPEntries_s*)e->gg.g.n)
	  len += zx_LEN_SO_ff12_IDPEntries(c, e);
  }
  for (se = x->GetComplete; se; se = (struct zx_elem_s*)se->g.n)
    len += zx_LEN_SO_simple_elem(c,se, sizeof("ff12:GetComplete")-1, zx_ns_tab+zx_xmlns_ix_ff12);


  len += zx_len_so_common(c, &x->gg, &pop_seen);
  zx_pop_seen(pop_seen);
  ENC_LEN_DEBUG(x, "ff12:IDPList", len);
  return len;
}

/* FUNC(zx_LEN_WO_ff12_IDPList) */

/* Compute length of an element (and its subelements). The XML attributes
 * and elements are processed in wire order and no assumptions
 * are made about namespace prefixes. */

/* Called by: */
int zx_LEN_WO_ff12_IDPList(struct zx_ctx* c, struct zx_ff12_IDPList_s* x )
{
  struct zx_ns_s* pop_seen = 0;
  struct zx_elem_s* se MAYBE_UNUSED;
#if 1 /* NORMALMODE */
  int len = 1 + sizeof("IDPList")-1 + 1 + 2 + sizeof("IDPList")-1 + 1;
  
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
      struct zx_ff12_IDPEntries_s* e;
      for (e = x->IDPEntries; e; e = (struct zx_ff12_IDPEntries_s*)e->gg.g.n)
	  len += zx_LEN_WO_ff12_IDPEntries(c, e);
  }
  for (se = x->GetComplete; se; se = (struct zx_elem_s*)se->g.n)
    len += zx_LEN_WO_simple_elem(c, se, sizeof("GetComplete")-1);


  len += zx_len_wo_common(c, &x->gg, &pop_seen); 
  zx_pop_seen(pop_seen);
  ENC_LEN_DEBUG(x, "ff12:IDPList", len);
  return len;
}

/* FUNC(zx_ENC_SO_ff12_IDPList) */

/* Render element into string. The XML attributes and elements are
 * processed in schema order. This is what you generally want for
 * rendering new data structure to a string. The wo pointers are not used. */

/* Called by: */
char* zx_ENC_SO_ff12_IDPList(struct zx_ctx* c, struct zx_ff12_IDPList_s* x, char* p )
{
  struct zx_elem_s* se MAYBE_UNUSED;
  struct zx_ns_s* pop_seen = 0;
  ENC_LEN_DEBUG_BASE;
#if 1 /* NORMALMODE */
  /* *** in simple_elem case should output ns prefix from ns node. */
  ZX_OUT_TAG(p, "<ff12:IDPList");
  if (c->inc_ns)
    zx_add_inc_ns(c, &pop_seen);
  zx_add_xmlns_if_not_seen(c, zx_ns_tab+zx_xmlns_ix_ff12, &pop_seen);

  zx_see_unknown_attrs_ns(c, x->gg.any_attr, &pop_seen);
  p = zx_enc_seen(p, pop_seen); 

  p = zx_enc_unknown_attrs(p, x->gg.any_attr);
#else
  /* root node has no begin tag */
#endif
  
  {
      struct zx_ff12_IDPEntries_s* e;
      for (e = x->IDPEntries; e; e = (struct zx_ff12_IDPEntries_s*)e->gg.g.n)
	  p = zx_ENC_SO_ff12_IDPEntries(c, e, p);
  }
  for (se = x->GetComplete; se; se = (struct zx_elem_s*)se->g.n)
    p = zx_ENC_SO_simple_elem(c, se, p, "ff12:GetComplete", sizeof("ff12:GetComplete")-1, zx_ns_tab+zx_xmlns_ix_ff12);

  p = zx_enc_so_unknown_elems_and_content(c, p, &x->gg);
  
#if 1 /* NORMALMODE */
  ZX_OUT_CLOSE_TAG(p, "</ff12:IDPList>");
  zx_pop_seen(pop_seen);
#else
  /* root node has no end tag either */
#endif
  ENC_LEN_DEBUG(x, "ff12:IDPList", p-enc_base);
  return p;
}

/* FUNC(zx_ENC_WO_ff12_IDPList) */

/* Render element into string. The XML attributes and elements are
 * processed in wire order by chasing wo pointers. This is what you want for
 * validating signatures on other people's XML documents. */

/* Called by: */
char* zx_ENC_WO_ff12_IDPList(struct zx_ctx* c, struct zx_ff12_IDPList_s* x, char* p )
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
  ZX_OUT_MEM(p, "IDPList", sizeof("IDPList")-1);
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
  ENC_LEN_DEBUG(x, "ff12:IDPList", p-enc_base);
  return p;
}

/* FUNC(zx_EASY_ENC_SO_ff12_IDPList) */

/* Called by: */
struct zx_str* zx_EASY_ENC_SO_ff12_IDPList(struct zx_ctx* c, struct zx_ff12_IDPList_s* x )
{
  int len;
  char* buf;
  c->ns_tab = ZX_ALLOC(c, sizeof(zx_ns_tab));
  memcpy(c->ns_tab, zx_ns_tab, sizeof(zx_ns_tab));
  len = zx_LEN_SO_ff12_IDPList(c, x );
  buf = ZX_ALLOC(c, len+1);
  return zx_easy_enc_common(c, zx_ENC_SO_ff12_IDPList(c, x, buf ), buf, len);
}

/* FUNC(zx_EASY_ENC_WO_ff12_IDPList) */

/* Called by: */
struct zx_str* zx_EASY_ENC_WO_ff12_IDPList(struct zx_ctx* c, struct zx_ff12_IDPList_s* x )
{
  int len;
  char* buf;
  c->ns_tab = ZX_ALLOC(c, sizeof(zx_ns_tab));
  memcpy(c->ns_tab, zx_ns_tab, sizeof(zx_ns_tab));
  len = zx_LEN_WO_ff12_IDPList(c, x );
  buf = ZX_ALLOC(c, len+1);
  return zx_easy_enc_common(c, zx_ENC_WO_ff12_IDPList(c, x, buf ), buf, len);
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

#define EL_NAME   ff12_IDPProvidedNameIdentifier
#define EL_STRUCT zx_ff12_IDPProvidedNameIdentifier_s
#define EL_NS     ff12
#define EL_TAG    IDPProvidedNameIdentifier

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

/* FUNC(zx_LEN_SO_ff12_IDPProvidedNameIdentifier) */

/* Compute length of an element (and its subelements). The XML attributes
 * and elements are processed in schema order. */

/* Called by: */
int zx_LEN_SO_ff12_IDPProvidedNameIdentifier(struct zx_ctx* c, struct zx_ff12_IDPProvidedNameIdentifier_s* x )
{
  struct zx_ns_s* pop_seen = 0;
  struct zx_elem_s* se MAYBE_UNUSED;
#if 1 /* NORMALMODE */
  /* *** in simple_elem case should output ns prefix from ns node. */
  int len = sizeof("<ff12:IDPProvidedNameIdentifier")-1 + 1 + sizeof("</ff12:IDPProvidedNameIdentifier>")-1;
  if (c->inc_ns_len)
    len += zx_len_inc_ns(c, &pop_seen);
  len += zx_len_xmlns_if_not_seen(c, zx_ns_tab+zx_xmlns_ix_ff12, &pop_seen);

  len += zx_attr_so_len(c, x->Format, sizeof("Format")-1, &pop_seen);
  len += zx_attr_so_len(c, x->NameQualifier, sizeof("NameQualifier")-1, &pop_seen);

#else
  /* root node has no begin tag */
  int len = 0;
#endif
  


  len += zx_len_so_common(c, &x->gg, &pop_seen);
  zx_pop_seen(pop_seen);
  ENC_LEN_DEBUG(x, "ff12:IDPProvidedNameIdentifier", len);
  return len;
}

/* FUNC(zx_LEN_WO_ff12_IDPProvidedNameIdentifier) */

/* Compute length of an element (and its subelements). The XML attributes
 * and elements are processed in wire order and no assumptions
 * are made about namespace prefixes. */

/* Called by: */
int zx_LEN_WO_ff12_IDPProvidedNameIdentifier(struct zx_ctx* c, struct zx_ff12_IDPProvidedNameIdentifier_s* x )
{
  struct zx_ns_s* pop_seen = 0;
  struct zx_elem_s* se MAYBE_UNUSED;
#if 1 /* NORMALMODE */
  int len = 1 + sizeof("IDPProvidedNameIdentifier")-1 + 1 + 2 + sizeof("IDPProvidedNameIdentifier")-1 + 1;
  
  if (x->gg.g.ns && x->gg.g.ns->prefix_len)
    len += (x->gg.g.ns->prefix_len + 1) * 2;
  if (c->inc_ns_len)
    len += zx_len_inc_ns(c, &pop_seen);
  len += zx_len_xmlns_if_not_seen(c, x->gg.g.ns, &pop_seen);

  len += zx_attr_wo_len(c, x->Format, sizeof("Format")-1, &pop_seen);
  len += zx_attr_wo_len(c, x->NameQualifier, sizeof("NameQualifier")-1, &pop_seen);

#else
  /* root node has no begin tag */
  int len = 0;
#endif
  


  len += zx_len_wo_common(c, &x->gg, &pop_seen); 
  zx_pop_seen(pop_seen);
  ENC_LEN_DEBUG(x, "ff12:IDPProvidedNameIdentifier", len);
  return len;
}

/* FUNC(zx_ENC_SO_ff12_IDPProvidedNameIdentifier) */

/* Render element into string. The XML attributes and elements are
 * processed in schema order. This is what you generally want for
 * rendering new data structure to a string. The wo pointers are not used. */

/* Called by: */
char* zx_ENC_SO_ff12_IDPProvidedNameIdentifier(struct zx_ctx* c, struct zx_ff12_IDPProvidedNameIdentifier_s* x, char* p )
{
  struct zx_elem_s* se MAYBE_UNUSED;
  struct zx_ns_s* pop_seen = 0;
  ENC_LEN_DEBUG_BASE;
#if 1 /* NORMALMODE */
  /* *** in simple_elem case should output ns prefix from ns node. */
  ZX_OUT_TAG(p, "<ff12:IDPProvidedNameIdentifier");
  if (c->inc_ns)
    zx_add_inc_ns(c, &pop_seen);
  zx_add_xmlns_if_not_seen(c, zx_ns_tab+zx_xmlns_ix_ff12, &pop_seen);

  zx_see_unknown_attrs_ns(c, x->gg.any_attr, &pop_seen);
  p = zx_enc_seen(p, pop_seen); 
  p = zx_attr_so_enc(p, x->Format, " Format=\"", sizeof(" Format=\"")-1);
  p = zx_attr_so_enc(p, x->NameQualifier, " NameQualifier=\"", sizeof(" NameQualifier=\"")-1);

  p = zx_enc_unknown_attrs(p, x->gg.any_attr);
#else
  /* root node has no begin tag */
#endif
  

  p = zx_enc_so_unknown_elems_and_content(c, p, &x->gg);
  
#if 1 /* NORMALMODE */
  ZX_OUT_CLOSE_TAG(p, "</ff12:IDPProvidedNameIdentifier>");
  zx_pop_seen(pop_seen);
#else
  /* root node has no end tag either */
#endif
  ENC_LEN_DEBUG(x, "ff12:IDPProvidedNameIdentifier", p-enc_base);
  return p;
}

/* FUNC(zx_ENC_WO_ff12_IDPProvidedNameIdentifier) */

/* Render element into string. The XML attributes and elements are
 * processed in wire order by chasing wo pointers. This is what you want for
 * validating signatures on other people's XML documents. */

/* Called by: */
char* zx_ENC_WO_ff12_IDPProvidedNameIdentifier(struct zx_ctx* c, struct zx_ff12_IDPProvidedNameIdentifier_s* x, char* p )
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
  ZX_OUT_MEM(p, "IDPProvidedNameIdentifier", sizeof("IDPProvidedNameIdentifier")-1);
  qq = p;

  if (c->inc_ns)
    zx_add_inc_ns(c, &pop_seen);
  zx_add_xmlns_if_not_seen(c, x->gg.g.ns, &pop_seen);

  zx_see_unknown_attrs_ns(c, x->gg.any_attr, &pop_seen);
  p = zx_enc_seen(p, pop_seen); 
  p = zx_attr_wo_enc(p, x->Format, "Format=\"", sizeof("Format=\"")-1);
  p = zx_attr_wo_enc(p, x->NameQualifier, "NameQualifier=\"", sizeof("NameQualifier=\"")-1);

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
  ENC_LEN_DEBUG(x, "ff12:IDPProvidedNameIdentifier", p-enc_base);
  return p;
}

/* FUNC(zx_EASY_ENC_SO_ff12_IDPProvidedNameIdentifier) */

/* Called by: */
struct zx_str* zx_EASY_ENC_SO_ff12_IDPProvidedNameIdentifier(struct zx_ctx* c, struct zx_ff12_IDPProvidedNameIdentifier_s* x )
{
  int len;
  char* buf;
  c->ns_tab = ZX_ALLOC(c, sizeof(zx_ns_tab));
  memcpy(c->ns_tab, zx_ns_tab, sizeof(zx_ns_tab));
  len = zx_LEN_SO_ff12_IDPProvidedNameIdentifier(c, x );
  buf = ZX_ALLOC(c, len+1);
  return zx_easy_enc_common(c, zx_ENC_SO_ff12_IDPProvidedNameIdentifier(c, x, buf ), buf, len);
}

/* FUNC(zx_EASY_ENC_WO_ff12_IDPProvidedNameIdentifier) */

/* Called by: */
struct zx_str* zx_EASY_ENC_WO_ff12_IDPProvidedNameIdentifier(struct zx_ctx* c, struct zx_ff12_IDPProvidedNameIdentifier_s* x )
{
  int len;
  char* buf;
  c->ns_tab = ZX_ALLOC(c, sizeof(zx_ns_tab));
  memcpy(c->ns_tab, zx_ns_tab, sizeof(zx_ns_tab));
  len = zx_LEN_WO_ff12_IDPProvidedNameIdentifier(c, x );
  buf = ZX_ALLOC(c, len+1);
  return zx_easy_enc_common(c, zx_ENC_WO_ff12_IDPProvidedNameIdentifier(c, x, buf ), buf, len);
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

#define EL_NAME   ff12_LogoutRequest
#define EL_STRUCT zx_ff12_LogoutRequest_s
#define EL_NS     ff12
#define EL_TAG    LogoutRequest

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

/* FUNC(zx_LEN_SO_ff12_LogoutRequest) */

/* Compute length of an element (and its subelements). The XML attributes
 * and elements are processed in schema order. */

/* Called by: */
int zx_LEN_SO_ff12_LogoutRequest(struct zx_ctx* c, struct zx_ff12_LogoutRequest_s* x )
{
  struct zx_ns_s* pop_seen = 0;
  struct zx_elem_s* se MAYBE_UNUSED;
#if 1 /* NORMALMODE */
  /* *** in simple_elem case should output ns prefix from ns node. */
  int len = sizeof("<ff12:LogoutRequest")-1 + 1 + sizeof("</ff12:LogoutRequest>")-1;
  if (c->inc_ns_len)
    len += zx_len_inc_ns(c, &pop_seen);
  len += zx_len_xmlns_if_not_seen(c, zx_ns_tab+zx_xmlns_ix_ff12, &pop_seen);

  len += zx_attr_so_len(c, x->IssueInstant, sizeof("IssueInstant")-1, &pop_seen);
  len += zx_attr_so_len(c, x->MajorVersion, sizeof("MajorVersion")-1, &pop_seen);
  len += zx_attr_so_len(c, x->MinorVersion, sizeof("MinorVersion")-1, &pop_seen);
  len += zx_attr_so_len(c, x->NotOnOrAfter, sizeof("NotOnOrAfter")-1, &pop_seen);
  len += zx_attr_so_len(c, x->RequestID, sizeof("RequestID")-1, &pop_seen);
  len += zx_attr_so_len(c, x->consent, sizeof("consent")-1, &pop_seen);

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
  {
      struct zx_ff12_Extension_s* e;
      for (e = x->Extension; e; e = (struct zx_ff12_Extension_s*)e->gg.g.n)
	  len += zx_LEN_SO_ff12_Extension(c, e);
  }
  for (se = x->ProviderID; se; se = (struct zx_elem_s*)se->g.n)
    len += zx_LEN_SO_simple_elem(c,se, sizeof("ff12:ProviderID")-1, zx_ns_tab+zx_xmlns_ix_ff12);
  {
      struct zx_sa11_NameIdentifier_s* e;
      for (e = x->NameIdentifier; e; e = (struct zx_sa11_NameIdentifier_s*)e->gg.g.n)
	  len += zx_LEN_SO_sa11_NameIdentifier(c, e);
  }
  for (se = x->SessionIndex; se; se = (struct zx_elem_s*)se->g.n)
    len += zx_LEN_SO_simple_elem(c,se, sizeof("ff12:SessionIndex")-1, zx_ns_tab+zx_xmlns_ix_ff12);
  for (se = x->RelayState; se; se = (struct zx_elem_s*)se->g.n)
    len += zx_LEN_SO_simple_elem(c,se, sizeof("ff12:RelayState")-1, zx_ns_tab+zx_xmlns_ix_ff12);


  len += zx_len_so_common(c, &x->gg, &pop_seen);
  zx_pop_seen(pop_seen);
  ENC_LEN_DEBUG(x, "ff12:LogoutRequest", len);
  return len;
}

/* FUNC(zx_LEN_WO_ff12_LogoutRequest) */

/* Compute length of an element (and its subelements). The XML attributes
 * and elements are processed in wire order and no assumptions
 * are made about namespace prefixes. */

/* Called by: */
int zx_LEN_WO_ff12_LogoutRequest(struct zx_ctx* c, struct zx_ff12_LogoutRequest_s* x )
{
  struct zx_ns_s* pop_seen = 0;
  struct zx_elem_s* se MAYBE_UNUSED;
#if 1 /* NORMALMODE */
  int len = 1 + sizeof("LogoutRequest")-1 + 1 + 2 + sizeof("LogoutRequest")-1 + 1;
  
  if (x->gg.g.ns && x->gg.g.ns->prefix_len)
    len += (x->gg.g.ns->prefix_len + 1) * 2;
  if (c->inc_ns_len)
    len += zx_len_inc_ns(c, &pop_seen);
  len += zx_len_xmlns_if_not_seen(c, x->gg.g.ns, &pop_seen);

  len += zx_attr_wo_len(c, x->IssueInstant, sizeof("IssueInstant")-1, &pop_seen);
  len += zx_attr_wo_len(c, x->MajorVersion, sizeof("MajorVersion")-1, &pop_seen);
  len += zx_attr_wo_len(c, x->MinorVersion, sizeof("MinorVersion")-1, &pop_seen);
  len += zx_attr_wo_len(c, x->NotOnOrAfter, sizeof("NotOnOrAfter")-1, &pop_seen);
  len += zx_attr_wo_len(c, x->RequestID, sizeof("RequestID")-1, &pop_seen);
  len += zx_attr_wo_len(c, x->consent, sizeof("consent")-1, &pop_seen);

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
  {
      struct zx_ff12_Extension_s* e;
      for (e = x->Extension; e; e = (struct zx_ff12_Extension_s*)e->gg.g.n)
	  len += zx_LEN_WO_ff12_Extension(c, e);
  }
  for (se = x->ProviderID; se; se = (struct zx_elem_s*)se->g.n)
    len += zx_LEN_WO_simple_elem(c, se, sizeof("ProviderID")-1);
  {
      struct zx_sa11_NameIdentifier_s* e;
      for (e = x->NameIdentifier; e; e = (struct zx_sa11_NameIdentifier_s*)e->gg.g.n)
	  len += zx_LEN_WO_sa11_NameIdentifier(c, e);
  }
  for (se = x->SessionIndex; se; se = (struct zx_elem_s*)se->g.n)
    len += zx_LEN_WO_simple_elem(c, se, sizeof("SessionIndex")-1);
  for (se = x->RelayState; se; se = (struct zx_elem_s*)se->g.n)
    len += zx_LEN_WO_simple_elem(c, se, sizeof("RelayState")-1);


  len += zx_len_wo_common(c, &x->gg, &pop_seen); 
  zx_pop_seen(pop_seen);
  ENC_LEN_DEBUG(x, "ff12:LogoutRequest", len);
  return len;
}

/* FUNC(zx_ENC_SO_ff12_LogoutRequest) */

/* Render element into string. The XML attributes and elements are
 * processed in schema order. This is what you generally want for
 * rendering new data structure to a string. The wo pointers are not used. */

/* Called by: */
char* zx_ENC_SO_ff12_LogoutRequest(struct zx_ctx* c, struct zx_ff12_LogoutRequest_s* x, char* p )
{
  struct zx_elem_s* se MAYBE_UNUSED;
  struct zx_ns_s* pop_seen = 0;
  ENC_LEN_DEBUG_BASE;
#if 1 /* NORMALMODE */
  /* *** in simple_elem case should output ns prefix from ns node. */
  ZX_OUT_TAG(p, "<ff12:LogoutRequest");
  if (c->inc_ns)
    zx_add_inc_ns(c, &pop_seen);
  zx_add_xmlns_if_not_seen(c, zx_ns_tab+zx_xmlns_ix_ff12, &pop_seen);

  zx_see_unknown_attrs_ns(c, x->gg.any_attr, &pop_seen);
  p = zx_enc_seen(p, pop_seen); 
  p = zx_attr_so_enc(p, x->IssueInstant, " IssueInstant=\"", sizeof(" IssueInstant=\"")-1);
  p = zx_attr_so_enc(p, x->MajorVersion, " MajorVersion=\"", sizeof(" MajorVersion=\"")-1);
  p = zx_attr_so_enc(p, x->MinorVersion, " MinorVersion=\"", sizeof(" MinorVersion=\"")-1);
  p = zx_attr_so_enc(p, x->NotOnOrAfter, " NotOnOrAfter=\"", sizeof(" NotOnOrAfter=\"")-1);
  p = zx_attr_so_enc(p, x->RequestID, " RequestID=\"", sizeof(" RequestID=\"")-1);
  p = zx_attr_so_enc(p, x->consent, " consent=\"", sizeof(" consent=\"")-1);

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
  {
      struct zx_ff12_Extension_s* e;
      for (e = x->Extension; e; e = (struct zx_ff12_Extension_s*)e->gg.g.n)
	  p = zx_ENC_SO_ff12_Extension(c, e, p);
  }
  for (se = x->ProviderID; se; se = (struct zx_elem_s*)se->g.n)
    p = zx_ENC_SO_simple_elem(c, se, p, "ff12:ProviderID", sizeof("ff12:ProviderID")-1, zx_ns_tab+zx_xmlns_ix_ff12);
  {
      struct zx_sa11_NameIdentifier_s* e;
      for (e = x->NameIdentifier; e; e = (struct zx_sa11_NameIdentifier_s*)e->gg.g.n)
	  p = zx_ENC_SO_sa11_NameIdentifier(c, e, p);
  }
  for (se = x->SessionIndex; se; se = (struct zx_elem_s*)se->g.n)
    p = zx_ENC_SO_simple_elem(c, se, p, "ff12:SessionIndex", sizeof("ff12:SessionIndex")-1, zx_ns_tab+zx_xmlns_ix_ff12);
  for (se = x->RelayState; se; se = (struct zx_elem_s*)se->g.n)
    p = zx_ENC_SO_simple_elem(c, se, p, "ff12:RelayState", sizeof("ff12:RelayState")-1, zx_ns_tab+zx_xmlns_ix_ff12);

  p = zx_enc_so_unknown_elems_and_content(c, p, &x->gg);
  
#if 1 /* NORMALMODE */
  ZX_OUT_CLOSE_TAG(p, "</ff12:LogoutRequest>");
  zx_pop_seen(pop_seen);
#else
  /* root node has no end tag either */
#endif
  ENC_LEN_DEBUG(x, "ff12:LogoutRequest", p-enc_base);
  return p;
}

/* FUNC(zx_ENC_WO_ff12_LogoutRequest) */

/* Render element into string. The XML attributes and elements are
 * processed in wire order by chasing wo pointers. This is what you want for
 * validating signatures on other people's XML documents. */

/* Called by: */
char* zx_ENC_WO_ff12_LogoutRequest(struct zx_ctx* c, struct zx_ff12_LogoutRequest_s* x, char* p )
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
  ZX_OUT_MEM(p, "LogoutRequest", sizeof("LogoutRequest")-1);
  qq = p;

  if (c->inc_ns)
    zx_add_inc_ns(c, &pop_seen);
  zx_add_xmlns_if_not_seen(c, x->gg.g.ns, &pop_seen);

  zx_see_unknown_attrs_ns(c, x->gg.any_attr, &pop_seen);
  p = zx_enc_seen(p, pop_seen); 
  p = zx_attr_wo_enc(p, x->IssueInstant, "IssueInstant=\"", sizeof("IssueInstant=\"")-1);
  p = zx_attr_wo_enc(p, x->MajorVersion, "MajorVersion=\"", sizeof("MajorVersion=\"")-1);
  p = zx_attr_wo_enc(p, x->MinorVersion, "MinorVersion=\"", sizeof("MinorVersion=\"")-1);
  p = zx_attr_wo_enc(p, x->NotOnOrAfter, "NotOnOrAfter=\"", sizeof("NotOnOrAfter=\"")-1);
  p = zx_attr_wo_enc(p, x->RequestID, "RequestID=\"", sizeof("RequestID=\"")-1);
  p = zx_attr_wo_enc(p, x->consent, "consent=\"", sizeof("consent=\"")-1);

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
  ENC_LEN_DEBUG(x, "ff12:LogoutRequest", p-enc_base);
  return p;
}

/* FUNC(zx_EASY_ENC_SO_ff12_LogoutRequest) */

/* Called by: */
struct zx_str* zx_EASY_ENC_SO_ff12_LogoutRequest(struct zx_ctx* c, struct zx_ff12_LogoutRequest_s* x )
{
  int len;
  char* buf;
  c->ns_tab = ZX_ALLOC(c, sizeof(zx_ns_tab));
  memcpy(c->ns_tab, zx_ns_tab, sizeof(zx_ns_tab));
  len = zx_LEN_SO_ff12_LogoutRequest(c, x );
  buf = ZX_ALLOC(c, len+1);
  return zx_easy_enc_common(c, zx_ENC_SO_ff12_LogoutRequest(c, x, buf ), buf, len);
}

/* FUNC(zx_EASY_ENC_WO_ff12_LogoutRequest) */

/* Called by: */
struct zx_str* zx_EASY_ENC_WO_ff12_LogoutRequest(struct zx_ctx* c, struct zx_ff12_LogoutRequest_s* x )
{
  int len;
  char* buf;
  c->ns_tab = ZX_ALLOC(c, sizeof(zx_ns_tab));
  memcpy(c->ns_tab, zx_ns_tab, sizeof(zx_ns_tab));
  len = zx_LEN_WO_ff12_LogoutRequest(c, x );
  buf = ZX_ALLOC(c, len+1);
  return zx_easy_enc_common(c, zx_ENC_WO_ff12_LogoutRequest(c, x, buf ), buf, len);
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

#define EL_NAME   ff12_LogoutResponse
#define EL_STRUCT zx_ff12_LogoutResponse_s
#define EL_NS     ff12
#define EL_TAG    LogoutResponse

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

/* FUNC(zx_LEN_SO_ff12_LogoutResponse) */

/* Compute length of an element (and its subelements). The XML attributes
 * and elements are processed in schema order. */

/* Called by: */
int zx_LEN_SO_ff12_LogoutResponse(struct zx_ctx* c, struct zx_ff12_LogoutResponse_s* x )
{
  struct zx_ns_s* pop_seen = 0;
  struct zx_elem_s* se MAYBE_UNUSED;
#if 1 /* NORMALMODE */
  /* *** in simple_elem case should output ns prefix from ns node. */
  int len = sizeof("<ff12:LogoutResponse")-1 + 1 + sizeof("</ff12:LogoutResponse>")-1;
  if (c->inc_ns_len)
    len += zx_len_inc_ns(c, &pop_seen);
  len += zx_len_xmlns_if_not_seen(c, zx_ns_tab+zx_xmlns_ix_ff12, &pop_seen);

  len += zx_attr_so_len(c, x->InResponseTo, sizeof("InResponseTo")-1, &pop_seen);
  len += zx_attr_so_len(c, x->IssueInstant, sizeof("IssueInstant")-1, &pop_seen);
  len += zx_attr_so_len(c, x->MajorVersion, sizeof("MajorVersion")-1, &pop_seen);
  len += zx_attr_so_len(c, x->MinorVersion, sizeof("MinorVersion")-1, &pop_seen);
  len += zx_attr_so_len(c, x->Recipient, sizeof("Recipient")-1, &pop_seen);
  len += zx_attr_so_len(c, x->ResponseID, sizeof("ResponseID")-1, &pop_seen);

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
      struct zx_ff12_Extension_s* e;
      for (e = x->Extension; e; e = (struct zx_ff12_Extension_s*)e->gg.g.n)
	  len += zx_LEN_SO_ff12_Extension(c, e);
  }
  for (se = x->ProviderID; se; se = (struct zx_elem_s*)se->g.n)
    len += zx_LEN_SO_simple_elem(c,se, sizeof("ff12:ProviderID")-1, zx_ns_tab+zx_xmlns_ix_ff12);
  {
      struct zx_sp11_Status_s* e;
      for (e = x->Status; e; e = (struct zx_sp11_Status_s*)e->gg.g.n)
	  len += zx_LEN_SO_sp11_Status(c, e);
  }
  for (se = x->RelayState; se; se = (struct zx_elem_s*)se->g.n)
    len += zx_LEN_SO_simple_elem(c,se, sizeof("ff12:RelayState")-1, zx_ns_tab+zx_xmlns_ix_ff12);


  len += zx_len_so_common(c, &x->gg, &pop_seen);
  zx_pop_seen(pop_seen);
  ENC_LEN_DEBUG(x, "ff12:LogoutResponse", len);
  return len;
}

/* FUNC(zx_LEN_WO_ff12_LogoutResponse) */

/* Compute length of an element (and its subelements). The XML attributes
 * and elements are processed in wire order and no assumptions
 * are made about namespace prefixes. */

/* Called by: */
int zx_LEN_WO_ff12_LogoutResponse(struct zx_ctx* c, struct zx_ff12_LogoutResponse_s* x )
{
  struct zx_ns_s* pop_seen = 0;
  struct zx_elem_s* se MAYBE_UNUSED;
#if 1 /* NORMALMODE */
  int len = 1 + sizeof("LogoutResponse")-1 + 1 + 2 + sizeof("LogoutResponse")-1 + 1;
  
  if (x->gg.g.ns && x->gg.g.ns->prefix_len)
    len += (x->gg.g.ns->prefix_len + 1) * 2;
  if (c->inc_ns_len)
    len += zx_len_inc_ns(c, &pop_seen);
  len += zx_len_xmlns_if_not_seen(c, x->gg.g.ns, &pop_seen);

  len += zx_attr_wo_len(c, x->InResponseTo, sizeof("InResponseTo")-1, &pop_seen);
  len += zx_attr_wo_len(c, x->IssueInstant, sizeof("IssueInstant")-1, &pop_seen);
  len += zx_attr_wo_len(c, x->MajorVersion, sizeof("MajorVersion")-1, &pop_seen);
  len += zx_attr_wo_len(c, x->MinorVersion, sizeof("MinorVersion")-1, &pop_seen);
  len += zx_attr_wo_len(c, x->Recipient, sizeof("Recipient")-1, &pop_seen);
  len += zx_attr_wo_len(c, x->ResponseID, sizeof("ResponseID")-1, &pop_seen);

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
      struct zx_ff12_Extension_s* e;
      for (e = x->Extension; e; e = (struct zx_ff12_Extension_s*)e->gg.g.n)
	  len += zx_LEN_WO_ff12_Extension(c, e);
  }
  for (se = x->ProviderID; se; se = (struct zx_elem_s*)se->g.n)
    len += zx_LEN_WO_simple_elem(c, se, sizeof("ProviderID")-1);
  {
      struct zx_sp11_Status_s* e;
      for (e = x->Status; e; e = (struct zx_sp11_Status_s*)e->gg.g.n)
	  len += zx_LEN_WO_sp11_Status(c, e);
  }
  for (se = x->RelayState; se; se = (struct zx_elem_s*)se->g.n)
    len += zx_LEN_WO_simple_elem(c, se, sizeof("RelayState")-1);


  len += zx_len_wo_common(c, &x->gg, &pop_seen); 
  zx_pop_seen(pop_seen);
  ENC_LEN_DEBUG(x, "ff12:LogoutResponse", len);
  return len;
}

/* FUNC(zx_ENC_SO_ff12_LogoutResponse) */

/* Render element into string. The XML attributes and elements are
 * processed in schema order. This is what you generally want for
 * rendering new data structure to a string. The wo pointers are not used. */

/* Called by: */
char* zx_ENC_SO_ff12_LogoutResponse(struct zx_ctx* c, struct zx_ff12_LogoutResponse_s* x, char* p )
{
  struct zx_elem_s* se MAYBE_UNUSED;
  struct zx_ns_s* pop_seen = 0;
  ENC_LEN_DEBUG_BASE;
#if 1 /* NORMALMODE */
  /* *** in simple_elem case should output ns prefix from ns node. */
  ZX_OUT_TAG(p, "<ff12:LogoutResponse");
  if (c->inc_ns)
    zx_add_inc_ns(c, &pop_seen);
  zx_add_xmlns_if_not_seen(c, zx_ns_tab+zx_xmlns_ix_ff12, &pop_seen);

  zx_see_unknown_attrs_ns(c, x->gg.any_attr, &pop_seen);
  p = zx_enc_seen(p, pop_seen); 
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
      struct zx_ff12_Extension_s* e;
      for (e = x->Extension; e; e = (struct zx_ff12_Extension_s*)e->gg.g.n)
	  p = zx_ENC_SO_ff12_Extension(c, e, p);
  }
  for (se = x->ProviderID; se; se = (struct zx_elem_s*)se->g.n)
    p = zx_ENC_SO_simple_elem(c, se, p, "ff12:ProviderID", sizeof("ff12:ProviderID")-1, zx_ns_tab+zx_xmlns_ix_ff12);
  {
      struct zx_sp11_Status_s* e;
      for (e = x->Status; e; e = (struct zx_sp11_Status_s*)e->gg.g.n)
	  p = zx_ENC_SO_sp11_Status(c, e, p);
  }
  for (se = x->RelayState; se; se = (struct zx_elem_s*)se->g.n)
    p = zx_ENC_SO_simple_elem(c, se, p, "ff12:RelayState", sizeof("ff12:RelayState")-1, zx_ns_tab+zx_xmlns_ix_ff12);

  p = zx_enc_so_unknown_elems_and_content(c, p, &x->gg);
  
#if 1 /* NORMALMODE */
  ZX_OUT_CLOSE_TAG(p, "</ff12:LogoutResponse>");
  zx_pop_seen(pop_seen);
#else
  /* root node has no end tag either */
#endif
  ENC_LEN_DEBUG(x, "ff12:LogoutResponse", p-enc_base);
  return p;
}

/* FUNC(zx_ENC_WO_ff12_LogoutResponse) */

/* Render element into string. The XML attributes and elements are
 * processed in wire order by chasing wo pointers. This is what you want for
 * validating signatures on other people's XML documents. */

/* Called by: */
char* zx_ENC_WO_ff12_LogoutResponse(struct zx_ctx* c, struct zx_ff12_LogoutResponse_s* x, char* p )
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
  ZX_OUT_MEM(p, "LogoutResponse", sizeof("LogoutResponse")-1);
  qq = p;

  if (c->inc_ns)
    zx_add_inc_ns(c, &pop_seen);
  zx_add_xmlns_if_not_seen(c, x->gg.g.ns, &pop_seen);

  zx_see_unknown_attrs_ns(c, x->gg.any_attr, &pop_seen);
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
  ENC_LEN_DEBUG(x, "ff12:LogoutResponse", p-enc_base);
  return p;
}

/* FUNC(zx_EASY_ENC_SO_ff12_LogoutResponse) */

/* Called by: */
struct zx_str* zx_EASY_ENC_SO_ff12_LogoutResponse(struct zx_ctx* c, struct zx_ff12_LogoutResponse_s* x )
{
  int len;
  char* buf;
  c->ns_tab = ZX_ALLOC(c, sizeof(zx_ns_tab));
  memcpy(c->ns_tab, zx_ns_tab, sizeof(zx_ns_tab));
  len = zx_LEN_SO_ff12_LogoutResponse(c, x );
  buf = ZX_ALLOC(c, len+1);
  return zx_easy_enc_common(c, zx_ENC_SO_ff12_LogoutResponse(c, x, buf ), buf, len);
}

/* FUNC(zx_EASY_ENC_WO_ff12_LogoutResponse) */

/* Called by: */
struct zx_str* zx_EASY_ENC_WO_ff12_LogoutResponse(struct zx_ctx* c, struct zx_ff12_LogoutResponse_s* x )
{
  int len;
  char* buf;
  c->ns_tab = ZX_ALLOC(c, sizeof(zx_ns_tab));
  memcpy(c->ns_tab, zx_ns_tab, sizeof(zx_ns_tab));
  len = zx_LEN_WO_ff12_LogoutResponse(c, x );
  buf = ZX_ALLOC(c, len+1);
  return zx_easy_enc_common(c, zx_ENC_WO_ff12_LogoutResponse(c, x, buf ), buf, len);
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

#define EL_NAME   ff12_NameIdentifierMappingRequest
#define EL_STRUCT zx_ff12_NameIdentifierMappingRequest_s
#define EL_NS     ff12
#define EL_TAG    NameIdentifierMappingRequest

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

/* FUNC(zx_LEN_SO_ff12_NameIdentifierMappingRequest) */

/* Compute length of an element (and its subelements). The XML attributes
 * and elements are processed in schema order. */

/* Called by: */
int zx_LEN_SO_ff12_NameIdentifierMappingRequest(struct zx_ctx* c, struct zx_ff12_NameIdentifierMappingRequest_s* x )
{
  struct zx_ns_s* pop_seen = 0;
  struct zx_elem_s* se MAYBE_UNUSED;
#if 1 /* NORMALMODE */
  /* *** in simple_elem case should output ns prefix from ns node. */
  int len = sizeof("<ff12:NameIdentifierMappingRequest")-1 + 1 + sizeof("</ff12:NameIdentifierMappingRequest>")-1;
  if (c->inc_ns_len)
    len += zx_len_inc_ns(c, &pop_seen);
  len += zx_len_xmlns_if_not_seen(c, zx_ns_tab+zx_xmlns_ix_ff12, &pop_seen);

  len += zx_attr_so_len(c, x->IssueInstant, sizeof("IssueInstant")-1, &pop_seen);
  len += zx_attr_so_len(c, x->MajorVersion, sizeof("MajorVersion")-1, &pop_seen);
  len += zx_attr_so_len(c, x->MinorVersion, sizeof("MinorVersion")-1, &pop_seen);
  len += zx_attr_so_len(c, x->RequestID, sizeof("RequestID")-1, &pop_seen);
  len += zx_attr_so_len(c, x->consent, sizeof("consent")-1, &pop_seen);

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
  {
      struct zx_ff12_Extension_s* e;
      for (e = x->Extension; e; e = (struct zx_ff12_Extension_s*)e->gg.g.n)
	  len += zx_LEN_SO_ff12_Extension(c, e);
  }
  for (se = x->ProviderID; se; se = (struct zx_elem_s*)se->g.n)
    len += zx_LEN_SO_simple_elem(c,se, sizeof("ff12:ProviderID")-1, zx_ns_tab+zx_xmlns_ix_ff12);
  {
      struct zx_sa11_NameIdentifier_s* e;
      for (e = x->NameIdentifier; e; e = (struct zx_sa11_NameIdentifier_s*)e->gg.g.n)
	  len += zx_LEN_SO_sa11_NameIdentifier(c, e);
  }
  for (se = x->TargetNamespace; se; se = (struct zx_elem_s*)se->g.n)
    len += zx_LEN_SO_simple_elem(c,se, sizeof("ff12:TargetNamespace")-1, zx_ns_tab+zx_xmlns_ix_ff12);


  len += zx_len_so_common(c, &x->gg, &pop_seen);
  zx_pop_seen(pop_seen);
  ENC_LEN_DEBUG(x, "ff12:NameIdentifierMappingRequest", len);
  return len;
}

/* FUNC(zx_LEN_WO_ff12_NameIdentifierMappingRequest) */

/* Compute length of an element (and its subelements). The XML attributes
 * and elements are processed in wire order and no assumptions
 * are made about namespace prefixes. */

/* Called by: */
int zx_LEN_WO_ff12_NameIdentifierMappingRequest(struct zx_ctx* c, struct zx_ff12_NameIdentifierMappingRequest_s* x )
{
  struct zx_ns_s* pop_seen = 0;
  struct zx_elem_s* se MAYBE_UNUSED;
#if 1 /* NORMALMODE */
  int len = 1 + sizeof("NameIdentifierMappingRequest")-1 + 1 + 2 + sizeof("NameIdentifierMappingRequest")-1 + 1;
  
  if (x->gg.g.ns && x->gg.g.ns->prefix_len)
    len += (x->gg.g.ns->prefix_len + 1) * 2;
  if (c->inc_ns_len)
    len += zx_len_inc_ns(c, &pop_seen);
  len += zx_len_xmlns_if_not_seen(c, x->gg.g.ns, &pop_seen);

  len += zx_attr_wo_len(c, x->IssueInstant, sizeof("IssueInstant")-1, &pop_seen);
  len += zx_attr_wo_len(c, x->MajorVersion, sizeof("MajorVersion")-1, &pop_seen);
  len += zx_attr_wo_len(c, x->MinorVersion, sizeof("MinorVersion")-1, &pop_seen);
  len += zx_attr_wo_len(c, x->RequestID, sizeof("RequestID")-1, &pop_seen);
  len += zx_attr_wo_len(c, x->consent, sizeof("consent")-1, &pop_seen);

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
  {
      struct zx_ff12_Extension_s* e;
      for (e = x->Extension; e; e = (struct zx_ff12_Extension_s*)e->gg.g.n)
	  len += zx_LEN_WO_ff12_Extension(c, e);
  }
  for (se = x->ProviderID; se; se = (struct zx_elem_s*)se->g.n)
    len += zx_LEN_WO_simple_elem(c, se, sizeof("ProviderID")-1);
  {
      struct zx_sa11_NameIdentifier_s* e;
      for (e = x->NameIdentifier; e; e = (struct zx_sa11_NameIdentifier_s*)e->gg.g.n)
	  len += zx_LEN_WO_sa11_NameIdentifier(c, e);
  }
  for (se = x->TargetNamespace; se; se = (struct zx_elem_s*)se->g.n)
    len += zx_LEN_WO_simple_elem(c, se, sizeof("TargetNamespace")-1);


  len += zx_len_wo_common(c, &x->gg, &pop_seen); 
  zx_pop_seen(pop_seen);
  ENC_LEN_DEBUG(x, "ff12:NameIdentifierMappingRequest", len);
  return len;
}

/* FUNC(zx_ENC_SO_ff12_NameIdentifierMappingRequest) */

/* Render element into string. The XML attributes and elements are
 * processed in schema order. This is what you generally want for
 * rendering new data structure to a string. The wo pointers are not used. */

/* Called by: */
char* zx_ENC_SO_ff12_NameIdentifierMappingRequest(struct zx_ctx* c, struct zx_ff12_NameIdentifierMappingRequest_s* x, char* p )
{
  struct zx_elem_s* se MAYBE_UNUSED;
  struct zx_ns_s* pop_seen = 0;
  ENC_LEN_DEBUG_BASE;
#if 1 /* NORMALMODE */
  /* *** in simple_elem case should output ns prefix from ns node. */
  ZX_OUT_TAG(p, "<ff12:NameIdentifierMappingRequest");
  if (c->inc_ns)
    zx_add_inc_ns(c, &pop_seen);
  zx_add_xmlns_if_not_seen(c, zx_ns_tab+zx_xmlns_ix_ff12, &pop_seen);

  zx_see_unknown_attrs_ns(c, x->gg.any_attr, &pop_seen);
  p = zx_enc_seen(p, pop_seen); 
  p = zx_attr_so_enc(p, x->IssueInstant, " IssueInstant=\"", sizeof(" IssueInstant=\"")-1);
  p = zx_attr_so_enc(p, x->MajorVersion, " MajorVersion=\"", sizeof(" MajorVersion=\"")-1);
  p = zx_attr_so_enc(p, x->MinorVersion, " MinorVersion=\"", sizeof(" MinorVersion=\"")-1);
  p = zx_attr_so_enc(p, x->RequestID, " RequestID=\"", sizeof(" RequestID=\"")-1);
  p = zx_attr_so_enc(p, x->consent, " consent=\"", sizeof(" consent=\"")-1);

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
  {
      struct zx_ff12_Extension_s* e;
      for (e = x->Extension; e; e = (struct zx_ff12_Extension_s*)e->gg.g.n)
	  p = zx_ENC_SO_ff12_Extension(c, e, p);
  }
  for (se = x->ProviderID; se; se = (struct zx_elem_s*)se->g.n)
    p = zx_ENC_SO_simple_elem(c, se, p, "ff12:ProviderID", sizeof("ff12:ProviderID")-1, zx_ns_tab+zx_xmlns_ix_ff12);
  {
      struct zx_sa11_NameIdentifier_s* e;
      for (e = x->NameIdentifier; e; e = (struct zx_sa11_NameIdentifier_s*)e->gg.g.n)
	  p = zx_ENC_SO_sa11_NameIdentifier(c, e, p);
  }
  for (se = x->TargetNamespace; se; se = (struct zx_elem_s*)se->g.n)
    p = zx_ENC_SO_simple_elem(c, se, p, "ff12:TargetNamespace", sizeof("ff12:TargetNamespace")-1, zx_ns_tab+zx_xmlns_ix_ff12);

  p = zx_enc_so_unknown_elems_and_content(c, p, &x->gg);
  
#if 1 /* NORMALMODE */
  ZX_OUT_CLOSE_TAG(p, "</ff12:NameIdentifierMappingRequest>");
  zx_pop_seen(pop_seen);
#else
  /* root node has no end tag either */
#endif
  ENC_LEN_DEBUG(x, "ff12:NameIdentifierMappingRequest", p-enc_base);
  return p;
}

/* FUNC(zx_ENC_WO_ff12_NameIdentifierMappingRequest) */

/* Render element into string. The XML attributes and elements are
 * processed in wire order by chasing wo pointers. This is what you want for
 * validating signatures on other people's XML documents. */

/* Called by: */
char* zx_ENC_WO_ff12_NameIdentifierMappingRequest(struct zx_ctx* c, struct zx_ff12_NameIdentifierMappingRequest_s* x, char* p )
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
  ZX_OUT_MEM(p, "NameIdentifierMappingRequest", sizeof("NameIdentifierMappingRequest")-1);
  qq = p;

  if (c->inc_ns)
    zx_add_inc_ns(c, &pop_seen);
  zx_add_xmlns_if_not_seen(c, x->gg.g.ns, &pop_seen);

  zx_see_unknown_attrs_ns(c, x->gg.any_attr, &pop_seen);
  p = zx_enc_seen(p, pop_seen); 
  p = zx_attr_wo_enc(p, x->IssueInstant, "IssueInstant=\"", sizeof("IssueInstant=\"")-1);
  p = zx_attr_wo_enc(p, x->MajorVersion, "MajorVersion=\"", sizeof("MajorVersion=\"")-1);
  p = zx_attr_wo_enc(p, x->MinorVersion, "MinorVersion=\"", sizeof("MinorVersion=\"")-1);
  p = zx_attr_wo_enc(p, x->RequestID, "RequestID=\"", sizeof("RequestID=\"")-1);
  p = zx_attr_wo_enc(p, x->consent, "consent=\"", sizeof("consent=\"")-1);

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
  ENC_LEN_DEBUG(x, "ff12:NameIdentifierMappingRequest", p-enc_base);
  return p;
}

/* FUNC(zx_EASY_ENC_SO_ff12_NameIdentifierMappingRequest) */

/* Called by: */
struct zx_str* zx_EASY_ENC_SO_ff12_NameIdentifierMappingRequest(struct zx_ctx* c, struct zx_ff12_NameIdentifierMappingRequest_s* x )
{
  int len;
  char* buf;
  c->ns_tab = ZX_ALLOC(c, sizeof(zx_ns_tab));
  memcpy(c->ns_tab, zx_ns_tab, sizeof(zx_ns_tab));
  len = zx_LEN_SO_ff12_NameIdentifierMappingRequest(c, x );
  buf = ZX_ALLOC(c, len+1);
  return zx_easy_enc_common(c, zx_ENC_SO_ff12_NameIdentifierMappingRequest(c, x, buf ), buf, len);
}

/* FUNC(zx_EASY_ENC_WO_ff12_NameIdentifierMappingRequest) */

/* Called by: */
struct zx_str* zx_EASY_ENC_WO_ff12_NameIdentifierMappingRequest(struct zx_ctx* c, struct zx_ff12_NameIdentifierMappingRequest_s* x )
{
  int len;
  char* buf;
  c->ns_tab = ZX_ALLOC(c, sizeof(zx_ns_tab));
  memcpy(c->ns_tab, zx_ns_tab, sizeof(zx_ns_tab));
  len = zx_LEN_WO_ff12_NameIdentifierMappingRequest(c, x );
  buf = ZX_ALLOC(c, len+1);
  return zx_easy_enc_common(c, zx_ENC_WO_ff12_NameIdentifierMappingRequest(c, x, buf ), buf, len);
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

#define EL_NAME   ff12_NameIdentifierMappingResponse
#define EL_STRUCT zx_ff12_NameIdentifierMappingResponse_s
#define EL_NS     ff12
#define EL_TAG    NameIdentifierMappingResponse

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

/* FUNC(zx_LEN_SO_ff12_NameIdentifierMappingResponse) */

/* Compute length of an element (and its subelements). The XML attributes
 * and elements are processed in schema order. */

/* Called by: */
int zx_LEN_SO_ff12_NameIdentifierMappingResponse(struct zx_ctx* c, struct zx_ff12_NameIdentifierMappingResponse_s* x )
{
  struct zx_ns_s* pop_seen = 0;
  struct zx_elem_s* se MAYBE_UNUSED;
#if 1 /* NORMALMODE */
  /* *** in simple_elem case should output ns prefix from ns node. */
  int len = sizeof("<ff12:NameIdentifierMappingResponse")-1 + 1 + sizeof("</ff12:NameIdentifierMappingResponse>")-1;
  if (c->inc_ns_len)
    len += zx_len_inc_ns(c, &pop_seen);
  len += zx_len_xmlns_if_not_seen(c, zx_ns_tab+zx_xmlns_ix_ff12, &pop_seen);

  len += zx_attr_so_len(c, x->InResponseTo, sizeof("InResponseTo")-1, &pop_seen);
  len += zx_attr_so_len(c, x->IssueInstant, sizeof("IssueInstant")-1, &pop_seen);
  len += zx_attr_so_len(c, x->MajorVersion, sizeof("MajorVersion")-1, &pop_seen);
  len += zx_attr_so_len(c, x->MinorVersion, sizeof("MinorVersion")-1, &pop_seen);
  len += zx_attr_so_len(c, x->Recipient, sizeof("Recipient")-1, &pop_seen);
  len += zx_attr_so_len(c, x->ResponseID, sizeof("ResponseID")-1, &pop_seen);

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
      struct zx_ff12_Extension_s* e;
      for (e = x->Extension; e; e = (struct zx_ff12_Extension_s*)e->gg.g.n)
	  len += zx_LEN_SO_ff12_Extension(c, e);
  }
  for (se = x->ProviderID; se; se = (struct zx_elem_s*)se->g.n)
    len += zx_LEN_SO_simple_elem(c,se, sizeof("ff12:ProviderID")-1, zx_ns_tab+zx_xmlns_ix_ff12);
  {
      struct zx_sp11_Status_s* e;
      for (e = x->Status; e; e = (struct zx_sp11_Status_s*)e->gg.g.n)
	  len += zx_LEN_SO_sp11_Status(c, e);
  }
  {
      struct zx_sa11_NameIdentifier_s* e;
      for (e = x->NameIdentifier; e; e = (struct zx_sa11_NameIdentifier_s*)e->gg.g.n)
	  len += zx_LEN_SO_sa11_NameIdentifier(c, e);
  }


  len += zx_len_so_common(c, &x->gg, &pop_seen);
  zx_pop_seen(pop_seen);
  ENC_LEN_DEBUG(x, "ff12:NameIdentifierMappingResponse", len);
  return len;
}

/* FUNC(zx_LEN_WO_ff12_NameIdentifierMappingResponse) */

/* Compute length of an element (and its subelements). The XML attributes
 * and elements are processed in wire order and no assumptions
 * are made about namespace prefixes. */

/* Called by: */
int zx_LEN_WO_ff12_NameIdentifierMappingResponse(struct zx_ctx* c, struct zx_ff12_NameIdentifierMappingResponse_s* x )
{
  struct zx_ns_s* pop_seen = 0;
  struct zx_elem_s* se MAYBE_UNUSED;
#if 1 /* NORMALMODE */
  int len = 1 + sizeof("NameIdentifierMappingResponse")-1 + 1 + 2 + sizeof("NameIdentifierMappingResponse")-1 + 1;
  
  if (x->gg.g.ns && x->gg.g.ns->prefix_len)
    len += (x->gg.g.ns->prefix_len + 1) * 2;
  if (c->inc_ns_len)
    len += zx_len_inc_ns(c, &pop_seen);
  len += zx_len_xmlns_if_not_seen(c, x->gg.g.ns, &pop_seen);

  len += zx_attr_wo_len(c, x->InResponseTo, sizeof("InResponseTo")-1, &pop_seen);
  len += zx_attr_wo_len(c, x->IssueInstant, sizeof("IssueInstant")-1, &pop_seen);
  len += zx_attr_wo_len(c, x->MajorVersion, sizeof("MajorVersion")-1, &pop_seen);
  len += zx_attr_wo_len(c, x->MinorVersion, sizeof("MinorVersion")-1, &pop_seen);
  len += zx_attr_wo_len(c, x->Recipient, sizeof("Recipient")-1, &pop_seen);
  len += zx_attr_wo_len(c, x->ResponseID, sizeof("ResponseID")-1, &pop_seen);

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
      struct zx_ff12_Extension_s* e;
      for (e = x->Extension; e; e = (struct zx_ff12_Extension_s*)e->gg.g.n)
	  len += zx_LEN_WO_ff12_Extension(c, e);
  }
  for (se = x->ProviderID; se; se = (struct zx_elem_s*)se->g.n)
    len += zx_LEN_WO_simple_elem(c, se, sizeof("ProviderID")-1);
  {
      struct zx_sp11_Status_s* e;
      for (e = x->Status; e; e = (struct zx_sp11_Status_s*)e->gg.g.n)
	  len += zx_LEN_WO_sp11_Status(c, e);
  }
  {
      struct zx_sa11_NameIdentifier_s* e;
      for (e = x->NameIdentifier; e; e = (struct zx_sa11_NameIdentifier_s*)e->gg.g.n)
	  len += zx_LEN_WO_sa11_NameIdentifier(c, e);
  }


  len += zx_len_wo_common(c, &x->gg, &pop_seen); 
  zx_pop_seen(pop_seen);
  ENC_LEN_DEBUG(x, "ff12:NameIdentifierMappingResponse", len);
  return len;
}

/* FUNC(zx_ENC_SO_ff12_NameIdentifierMappingResponse) */

/* Render element into string. The XML attributes and elements are
 * processed in schema order. This is what you generally want for
 * rendering new data structure to a string. The wo pointers are not used. */

/* Called by: */
char* zx_ENC_SO_ff12_NameIdentifierMappingResponse(struct zx_ctx* c, struct zx_ff12_NameIdentifierMappingResponse_s* x, char* p )
{
  struct zx_elem_s* se MAYBE_UNUSED;
  struct zx_ns_s* pop_seen = 0;
  ENC_LEN_DEBUG_BASE;
#if 1 /* NORMALMODE */
  /* *** in simple_elem case should output ns prefix from ns node. */
  ZX_OUT_TAG(p, "<ff12:NameIdentifierMappingResponse");
  if (c->inc_ns)
    zx_add_inc_ns(c, &pop_seen);
  zx_add_xmlns_if_not_seen(c, zx_ns_tab+zx_xmlns_ix_ff12, &pop_seen);

  zx_see_unknown_attrs_ns(c, x->gg.any_attr, &pop_seen);
  p = zx_enc_seen(p, pop_seen); 
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
      struct zx_ff12_Extension_s* e;
      for (e = x->Extension; e; e = (struct zx_ff12_Extension_s*)e->gg.g.n)
	  p = zx_ENC_SO_ff12_Extension(c, e, p);
  }
  for (se = x->ProviderID; se; se = (struct zx_elem_s*)se->g.n)
    p = zx_ENC_SO_simple_elem(c, se, p, "ff12:ProviderID", sizeof("ff12:ProviderID")-1, zx_ns_tab+zx_xmlns_ix_ff12);
  {
      struct zx_sp11_Status_s* e;
      for (e = x->Status; e; e = (struct zx_sp11_Status_s*)e->gg.g.n)
	  p = zx_ENC_SO_sp11_Status(c, e, p);
  }
  {
      struct zx_sa11_NameIdentifier_s* e;
      for (e = x->NameIdentifier; e; e = (struct zx_sa11_NameIdentifier_s*)e->gg.g.n)
	  p = zx_ENC_SO_sa11_NameIdentifier(c, e, p);
  }

  p = zx_enc_so_unknown_elems_and_content(c, p, &x->gg);
  
#if 1 /* NORMALMODE */
  ZX_OUT_CLOSE_TAG(p, "</ff12:NameIdentifierMappingResponse>");
  zx_pop_seen(pop_seen);
#else
  /* root node has no end tag either */
#endif
  ENC_LEN_DEBUG(x, "ff12:NameIdentifierMappingResponse", p-enc_base);
  return p;
}

/* FUNC(zx_ENC_WO_ff12_NameIdentifierMappingResponse) */

/* Render element into string. The XML attributes and elements are
 * processed in wire order by chasing wo pointers. This is what you want for
 * validating signatures on other people's XML documents. */

/* Called by: */
char* zx_ENC_WO_ff12_NameIdentifierMappingResponse(struct zx_ctx* c, struct zx_ff12_NameIdentifierMappingResponse_s* x, char* p )
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
  ZX_OUT_MEM(p, "NameIdentifierMappingResponse", sizeof("NameIdentifierMappingResponse")-1);
  qq = p;

  if (c->inc_ns)
    zx_add_inc_ns(c, &pop_seen);
  zx_add_xmlns_if_not_seen(c, x->gg.g.ns, &pop_seen);

  zx_see_unknown_attrs_ns(c, x->gg.any_attr, &pop_seen);
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
  ENC_LEN_DEBUG(x, "ff12:NameIdentifierMappingResponse", p-enc_base);
  return p;
}

/* FUNC(zx_EASY_ENC_SO_ff12_NameIdentifierMappingResponse) */

/* Called by: */
struct zx_str* zx_EASY_ENC_SO_ff12_NameIdentifierMappingResponse(struct zx_ctx* c, struct zx_ff12_NameIdentifierMappingResponse_s* x )
{
  int len;
  char* buf;
  c->ns_tab = ZX_ALLOC(c, sizeof(zx_ns_tab));
  memcpy(c->ns_tab, zx_ns_tab, sizeof(zx_ns_tab));
  len = zx_LEN_SO_ff12_NameIdentifierMappingResponse(c, x );
  buf = ZX_ALLOC(c, len+1);
  return zx_easy_enc_common(c, zx_ENC_SO_ff12_NameIdentifierMappingResponse(c, x, buf ), buf, len);
}

/* FUNC(zx_EASY_ENC_WO_ff12_NameIdentifierMappingResponse) */

/* Called by: */
struct zx_str* zx_EASY_ENC_WO_ff12_NameIdentifierMappingResponse(struct zx_ctx* c, struct zx_ff12_NameIdentifierMappingResponse_s* x )
{
  int len;
  char* buf;
  c->ns_tab = ZX_ALLOC(c, sizeof(zx_ns_tab));
  memcpy(c->ns_tab, zx_ns_tab, sizeof(zx_ns_tab));
  len = zx_LEN_WO_ff12_NameIdentifierMappingResponse(c, x );
  buf = ZX_ALLOC(c, len+1);
  return zx_easy_enc_common(c, zx_ENC_WO_ff12_NameIdentifierMappingResponse(c, x, buf ), buf, len);
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

#define EL_NAME   ff12_OldProvidedNameIdentifier
#define EL_STRUCT zx_ff12_OldProvidedNameIdentifier_s
#define EL_NS     ff12
#define EL_TAG    OldProvidedNameIdentifier

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

/* FUNC(zx_LEN_SO_ff12_OldProvidedNameIdentifier) */

/* Compute length of an element (and its subelements). The XML attributes
 * and elements are processed in schema order. */

/* Called by: */
int zx_LEN_SO_ff12_OldProvidedNameIdentifier(struct zx_ctx* c, struct zx_ff12_OldProvidedNameIdentifier_s* x )
{
  struct zx_ns_s* pop_seen = 0;
  struct zx_elem_s* se MAYBE_UNUSED;
#if 1 /* NORMALMODE */
  /* *** in simple_elem case should output ns prefix from ns node. */
  int len = sizeof("<ff12:OldProvidedNameIdentifier")-1 + 1 + sizeof("</ff12:OldProvidedNameIdentifier>")-1;
  if (c->inc_ns_len)
    len += zx_len_inc_ns(c, &pop_seen);
  len += zx_len_xmlns_if_not_seen(c, zx_ns_tab+zx_xmlns_ix_ff12, &pop_seen);

  len += zx_attr_so_len(c, x->Format, sizeof("Format")-1, &pop_seen);
  len += zx_attr_so_len(c, x->NameQualifier, sizeof("NameQualifier")-1, &pop_seen);

#else
  /* root node has no begin tag */
  int len = 0;
#endif
  


  len += zx_len_so_common(c, &x->gg, &pop_seen);
  zx_pop_seen(pop_seen);
  ENC_LEN_DEBUG(x, "ff12:OldProvidedNameIdentifier", len);
  return len;
}

/* FUNC(zx_LEN_WO_ff12_OldProvidedNameIdentifier) */

/* Compute length of an element (and its subelements). The XML attributes
 * and elements are processed in wire order and no assumptions
 * are made about namespace prefixes. */

/* Called by: */
int zx_LEN_WO_ff12_OldProvidedNameIdentifier(struct zx_ctx* c, struct zx_ff12_OldProvidedNameIdentifier_s* x )
{
  struct zx_ns_s* pop_seen = 0;
  struct zx_elem_s* se MAYBE_UNUSED;
#if 1 /* NORMALMODE */
  int len = 1 + sizeof("OldProvidedNameIdentifier")-1 + 1 + 2 + sizeof("OldProvidedNameIdentifier")-1 + 1;
  
  if (x->gg.g.ns && x->gg.g.ns->prefix_len)
    len += (x->gg.g.ns->prefix_len + 1) * 2;
  if (c->inc_ns_len)
    len += zx_len_inc_ns(c, &pop_seen);
  len += zx_len_xmlns_if_not_seen(c, x->gg.g.ns, &pop_seen);

  len += zx_attr_wo_len(c, x->Format, sizeof("Format")-1, &pop_seen);
  len += zx_attr_wo_len(c, x->NameQualifier, sizeof("NameQualifier")-1, &pop_seen);

#else
  /* root node has no begin tag */
  int len = 0;
#endif
  


  len += zx_len_wo_common(c, &x->gg, &pop_seen); 
  zx_pop_seen(pop_seen);
  ENC_LEN_DEBUG(x, "ff12:OldProvidedNameIdentifier", len);
  return len;
}

/* FUNC(zx_ENC_SO_ff12_OldProvidedNameIdentifier) */

/* Render element into string. The XML attributes and elements are
 * processed in schema order. This is what you generally want for
 * rendering new data structure to a string. The wo pointers are not used. */

/* Called by: */
char* zx_ENC_SO_ff12_OldProvidedNameIdentifier(struct zx_ctx* c, struct zx_ff12_OldProvidedNameIdentifier_s* x, char* p )
{
  struct zx_elem_s* se MAYBE_UNUSED;
  struct zx_ns_s* pop_seen = 0;
  ENC_LEN_DEBUG_BASE;
#if 1 /* NORMALMODE */
  /* *** in simple_elem case should output ns prefix from ns node. */
  ZX_OUT_TAG(p, "<ff12:OldProvidedNameIdentifier");
  if (c->inc_ns)
    zx_add_inc_ns(c, &pop_seen);
  zx_add_xmlns_if_not_seen(c, zx_ns_tab+zx_xmlns_ix_ff12, &pop_seen);

  zx_see_unknown_attrs_ns(c, x->gg.any_attr, &pop_seen);
  p = zx_enc_seen(p, pop_seen); 
  p = zx_attr_so_enc(p, x->Format, " Format=\"", sizeof(" Format=\"")-1);
  p = zx_attr_so_enc(p, x->NameQualifier, " NameQualifier=\"", sizeof(" NameQualifier=\"")-1);

  p = zx_enc_unknown_attrs(p, x->gg.any_attr);
#else
  /* root node has no begin tag */
#endif
  

  p = zx_enc_so_unknown_elems_and_content(c, p, &x->gg);
  
#if 1 /* NORMALMODE */
  ZX_OUT_CLOSE_TAG(p, "</ff12:OldProvidedNameIdentifier>");
  zx_pop_seen(pop_seen);
#else
  /* root node has no end tag either */
#endif
  ENC_LEN_DEBUG(x, "ff12:OldProvidedNameIdentifier", p-enc_base);
  return p;
}

/* FUNC(zx_ENC_WO_ff12_OldProvidedNameIdentifier) */

/* Render element into string. The XML attributes and elements are
 * processed in wire order by chasing wo pointers. This is what you want for
 * validating signatures on other people's XML documents. */

/* Called by: */
char* zx_ENC_WO_ff12_OldProvidedNameIdentifier(struct zx_ctx* c, struct zx_ff12_OldProvidedNameIdentifier_s* x, char* p )
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
  ZX_OUT_MEM(p, "OldProvidedNameIdentifier", sizeof("OldProvidedNameIdentifier")-1);
  qq = p;

  if (c->inc_ns)
    zx_add_inc_ns(c, &pop_seen);
  zx_add_xmlns_if_not_seen(c, x->gg.g.ns, &pop_seen);

  zx_see_unknown_attrs_ns(c, x->gg.any_attr, &pop_seen);
  p = zx_enc_seen(p, pop_seen); 
  p = zx_attr_wo_enc(p, x->Format, "Format=\"", sizeof("Format=\"")-1);
  p = zx_attr_wo_enc(p, x->NameQualifier, "NameQualifier=\"", sizeof("NameQualifier=\"")-1);

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
  ENC_LEN_DEBUG(x, "ff12:OldProvidedNameIdentifier", p-enc_base);
  return p;
}

/* FUNC(zx_EASY_ENC_SO_ff12_OldProvidedNameIdentifier) */

/* Called by: */
struct zx_str* zx_EASY_ENC_SO_ff12_OldProvidedNameIdentifier(struct zx_ctx* c, struct zx_ff12_OldProvidedNameIdentifier_s* x )
{
  int len;
  char* buf;
  c->ns_tab = ZX_ALLOC(c, sizeof(zx_ns_tab));
  memcpy(c->ns_tab, zx_ns_tab, sizeof(zx_ns_tab));
  len = zx_LEN_SO_ff12_OldProvidedNameIdentifier(c, x );
  buf = ZX_ALLOC(c, len+1);
  return zx_easy_enc_common(c, zx_ENC_SO_ff12_OldProvidedNameIdentifier(c, x, buf ), buf, len);
}

/* FUNC(zx_EASY_ENC_WO_ff12_OldProvidedNameIdentifier) */

/* Called by: */
struct zx_str* zx_EASY_ENC_WO_ff12_OldProvidedNameIdentifier(struct zx_ctx* c, struct zx_ff12_OldProvidedNameIdentifier_s* x )
{
  int len;
  char* buf;
  c->ns_tab = ZX_ALLOC(c, sizeof(zx_ns_tab));
  memcpy(c->ns_tab, zx_ns_tab, sizeof(zx_ns_tab));
  len = zx_LEN_WO_ff12_OldProvidedNameIdentifier(c, x );
  buf = ZX_ALLOC(c, len+1);
  return zx_easy_enc_common(c, zx_ENC_WO_ff12_OldProvidedNameIdentifier(c, x, buf ), buf, len);
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

#define EL_NAME   ff12_RegisterNameIdentifierRequest
#define EL_STRUCT zx_ff12_RegisterNameIdentifierRequest_s
#define EL_NS     ff12
#define EL_TAG    RegisterNameIdentifierRequest

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

/* FUNC(zx_LEN_SO_ff12_RegisterNameIdentifierRequest) */

/* Compute length of an element (and its subelements). The XML attributes
 * and elements are processed in schema order. */

/* Called by: */
int zx_LEN_SO_ff12_RegisterNameIdentifierRequest(struct zx_ctx* c, struct zx_ff12_RegisterNameIdentifierRequest_s* x )
{
  struct zx_ns_s* pop_seen = 0;
  struct zx_elem_s* se MAYBE_UNUSED;
#if 1 /* NORMALMODE */
  /* *** in simple_elem case should output ns prefix from ns node. */
  int len = sizeof("<ff12:RegisterNameIdentifierRequest")-1 + 1 + sizeof("</ff12:RegisterNameIdentifierRequest>")-1;
  if (c->inc_ns_len)
    len += zx_len_inc_ns(c, &pop_seen);
  len += zx_len_xmlns_if_not_seen(c, zx_ns_tab+zx_xmlns_ix_ff12, &pop_seen);

  len += zx_attr_so_len(c, x->IssueInstant, sizeof("IssueInstant")-1, &pop_seen);
  len += zx_attr_so_len(c, x->MajorVersion, sizeof("MajorVersion")-1, &pop_seen);
  len += zx_attr_so_len(c, x->MinorVersion, sizeof("MinorVersion")-1, &pop_seen);
  len += zx_attr_so_len(c, x->RequestID, sizeof("RequestID")-1, &pop_seen);

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
  {
      struct zx_ff12_Extension_s* e;
      for (e = x->Extension; e; e = (struct zx_ff12_Extension_s*)e->gg.g.n)
	  len += zx_LEN_SO_ff12_Extension(c, e);
  }
  for (se = x->ProviderID; se; se = (struct zx_elem_s*)se->g.n)
    len += zx_LEN_SO_simple_elem(c,se, sizeof("ff12:ProviderID")-1, zx_ns_tab+zx_xmlns_ix_ff12);
  {
      struct zx_ff12_IDPProvidedNameIdentifier_s* e;
      for (e = x->IDPProvidedNameIdentifier; e; e = (struct zx_ff12_IDPProvidedNameIdentifier_s*)e->gg.g.n)
	  len += zx_LEN_SO_ff12_IDPProvidedNameIdentifier(c, e);
  }
  {
      struct zx_ff12_SPProvidedNameIdentifier_s* e;
      for (e = x->SPProvidedNameIdentifier; e; e = (struct zx_ff12_SPProvidedNameIdentifier_s*)e->gg.g.n)
	  len += zx_LEN_SO_ff12_SPProvidedNameIdentifier(c, e);
  }
  {
      struct zx_ff12_OldProvidedNameIdentifier_s* e;
      for (e = x->OldProvidedNameIdentifier; e; e = (struct zx_ff12_OldProvidedNameIdentifier_s*)e->gg.g.n)
	  len += zx_LEN_SO_ff12_OldProvidedNameIdentifier(c, e);
  }
  for (se = x->RelayState; se; se = (struct zx_elem_s*)se->g.n)
    len += zx_LEN_SO_simple_elem(c,se, sizeof("ff12:RelayState")-1, zx_ns_tab+zx_xmlns_ix_ff12);


  len += zx_len_so_common(c, &x->gg, &pop_seen);
  zx_pop_seen(pop_seen);
  ENC_LEN_DEBUG(x, "ff12:RegisterNameIdentifierRequest", len);
  return len;
}

/* FUNC(zx_LEN_WO_ff12_RegisterNameIdentifierRequest) */

/* Compute length of an element (and its subelements). The XML attributes
 * and elements are processed in wire order and no assumptions
 * are made about namespace prefixes. */

/* Called by: */
int zx_LEN_WO_ff12_RegisterNameIdentifierRequest(struct zx_ctx* c, struct zx_ff12_RegisterNameIdentifierRequest_s* x )
{
  struct zx_ns_s* pop_seen = 0;
  struct zx_elem_s* se MAYBE_UNUSED;
#if 1 /* NORMALMODE */
  int len = 1 + sizeof("RegisterNameIdentifierRequest")-1 + 1 + 2 + sizeof("RegisterNameIdentifierRequest")-1 + 1;
  
  if (x->gg.g.ns && x->gg.g.ns->prefix_len)
    len += (x->gg.g.ns->prefix_len + 1) * 2;
  if (c->inc_ns_len)
    len += zx_len_inc_ns(c, &pop_seen);
  len += zx_len_xmlns_if_not_seen(c, x->gg.g.ns, &pop_seen);

  len += zx_attr_wo_len(c, x->IssueInstant, sizeof("IssueInstant")-1, &pop_seen);
  len += zx_attr_wo_len(c, x->MajorVersion, sizeof("MajorVersion")-1, &pop_seen);
  len += zx_attr_wo_len(c, x->MinorVersion, sizeof("MinorVersion")-1, &pop_seen);
  len += zx_attr_wo_len(c, x->RequestID, sizeof("RequestID")-1, &pop_seen);

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
  {
      struct zx_ff12_Extension_s* e;
      for (e = x->Extension; e; e = (struct zx_ff12_Extension_s*)e->gg.g.n)
	  len += zx_LEN_WO_ff12_Extension(c, e);
  }
  for (se = x->ProviderID; se; se = (struct zx_elem_s*)se->g.n)
    len += zx_LEN_WO_simple_elem(c, se, sizeof("ProviderID")-1);
  {
      struct zx_ff12_IDPProvidedNameIdentifier_s* e;
      for (e = x->IDPProvidedNameIdentifier; e; e = (struct zx_ff12_IDPProvidedNameIdentifier_s*)e->gg.g.n)
	  len += zx_LEN_WO_ff12_IDPProvidedNameIdentifier(c, e);
  }
  {
      struct zx_ff12_SPProvidedNameIdentifier_s* e;
      for (e = x->SPProvidedNameIdentifier; e; e = (struct zx_ff12_SPProvidedNameIdentifier_s*)e->gg.g.n)
	  len += zx_LEN_WO_ff12_SPProvidedNameIdentifier(c, e);
  }
  {
      struct zx_ff12_OldProvidedNameIdentifier_s* e;
      for (e = x->OldProvidedNameIdentifier; e; e = (struct zx_ff12_OldProvidedNameIdentifier_s*)e->gg.g.n)
	  len += zx_LEN_WO_ff12_OldProvidedNameIdentifier(c, e);
  }
  for (se = x->RelayState; se; se = (struct zx_elem_s*)se->g.n)
    len += zx_LEN_WO_simple_elem(c, se, sizeof("RelayState")-1);


  len += zx_len_wo_common(c, &x->gg, &pop_seen); 
  zx_pop_seen(pop_seen);
  ENC_LEN_DEBUG(x, "ff12:RegisterNameIdentifierRequest", len);
  return len;
}

/* FUNC(zx_ENC_SO_ff12_RegisterNameIdentifierRequest) */

/* Render element into string. The XML attributes and elements are
 * processed in schema order. This is what you generally want for
 * rendering new data structure to a string. The wo pointers are not used. */

/* Called by: */
char* zx_ENC_SO_ff12_RegisterNameIdentifierRequest(struct zx_ctx* c, struct zx_ff12_RegisterNameIdentifierRequest_s* x, char* p )
{
  struct zx_elem_s* se MAYBE_UNUSED;
  struct zx_ns_s* pop_seen = 0;
  ENC_LEN_DEBUG_BASE;
#if 1 /* NORMALMODE */
  /* *** in simple_elem case should output ns prefix from ns node. */
  ZX_OUT_TAG(p, "<ff12:RegisterNameIdentifierRequest");
  if (c->inc_ns)
    zx_add_inc_ns(c, &pop_seen);
  zx_add_xmlns_if_not_seen(c, zx_ns_tab+zx_xmlns_ix_ff12, &pop_seen);

  zx_see_unknown_attrs_ns(c, x->gg.any_attr, &pop_seen);
  p = zx_enc_seen(p, pop_seen); 
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
  {
      struct zx_ff12_Extension_s* e;
      for (e = x->Extension; e; e = (struct zx_ff12_Extension_s*)e->gg.g.n)
	  p = zx_ENC_SO_ff12_Extension(c, e, p);
  }
  for (se = x->ProviderID; se; se = (struct zx_elem_s*)se->g.n)
    p = zx_ENC_SO_simple_elem(c, se, p, "ff12:ProviderID", sizeof("ff12:ProviderID")-1, zx_ns_tab+zx_xmlns_ix_ff12);
  {
      struct zx_ff12_IDPProvidedNameIdentifier_s* e;
      for (e = x->IDPProvidedNameIdentifier; e; e = (struct zx_ff12_IDPProvidedNameIdentifier_s*)e->gg.g.n)
	  p = zx_ENC_SO_ff12_IDPProvidedNameIdentifier(c, e, p);
  }
  {
      struct zx_ff12_SPProvidedNameIdentifier_s* e;
      for (e = x->SPProvidedNameIdentifier; e; e = (struct zx_ff12_SPProvidedNameIdentifier_s*)e->gg.g.n)
	  p = zx_ENC_SO_ff12_SPProvidedNameIdentifier(c, e, p);
  }
  {
      struct zx_ff12_OldProvidedNameIdentifier_s* e;
      for (e = x->OldProvidedNameIdentifier; e; e = (struct zx_ff12_OldProvidedNameIdentifier_s*)e->gg.g.n)
	  p = zx_ENC_SO_ff12_OldProvidedNameIdentifier(c, e, p);
  }
  for (se = x->RelayState; se; se = (struct zx_elem_s*)se->g.n)
    p = zx_ENC_SO_simple_elem(c, se, p, "ff12:RelayState", sizeof("ff12:RelayState")-1, zx_ns_tab+zx_xmlns_ix_ff12);

  p = zx_enc_so_unknown_elems_and_content(c, p, &x->gg);
  
#if 1 /* NORMALMODE */
  ZX_OUT_CLOSE_TAG(p, "</ff12:RegisterNameIdentifierRequest>");
  zx_pop_seen(pop_seen);
#else
  /* root node has no end tag either */
#endif
  ENC_LEN_DEBUG(x, "ff12:RegisterNameIdentifierRequest", p-enc_base);
  return p;
}

/* FUNC(zx_ENC_WO_ff12_RegisterNameIdentifierRequest) */

/* Render element into string. The XML attributes and elements are
 * processed in wire order by chasing wo pointers. This is what you want for
 * validating signatures on other people's XML documents. */

/* Called by: */
char* zx_ENC_WO_ff12_RegisterNameIdentifierRequest(struct zx_ctx* c, struct zx_ff12_RegisterNameIdentifierRequest_s* x, char* p )
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
  ZX_OUT_MEM(p, "RegisterNameIdentifierRequest", sizeof("RegisterNameIdentifierRequest")-1);
  qq = p;

  if (c->inc_ns)
    zx_add_inc_ns(c, &pop_seen);
  zx_add_xmlns_if_not_seen(c, x->gg.g.ns, &pop_seen);

  zx_see_unknown_attrs_ns(c, x->gg.any_attr, &pop_seen);
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
  ENC_LEN_DEBUG(x, "ff12:RegisterNameIdentifierRequest", p-enc_base);
  return p;
}

/* FUNC(zx_EASY_ENC_SO_ff12_RegisterNameIdentifierRequest) */

/* Called by: */
struct zx_str* zx_EASY_ENC_SO_ff12_RegisterNameIdentifierRequest(struct zx_ctx* c, struct zx_ff12_RegisterNameIdentifierRequest_s* x )
{
  int len;
  char* buf;
  c->ns_tab = ZX_ALLOC(c, sizeof(zx_ns_tab));
  memcpy(c->ns_tab, zx_ns_tab, sizeof(zx_ns_tab));
  len = zx_LEN_SO_ff12_RegisterNameIdentifierRequest(c, x );
  buf = ZX_ALLOC(c, len+1);
  return zx_easy_enc_common(c, zx_ENC_SO_ff12_RegisterNameIdentifierRequest(c, x, buf ), buf, len);
}

/* FUNC(zx_EASY_ENC_WO_ff12_RegisterNameIdentifierRequest) */

/* Called by: */
struct zx_str* zx_EASY_ENC_WO_ff12_RegisterNameIdentifierRequest(struct zx_ctx* c, struct zx_ff12_RegisterNameIdentifierRequest_s* x )
{
  int len;
  char* buf;
  c->ns_tab = ZX_ALLOC(c, sizeof(zx_ns_tab));
  memcpy(c->ns_tab, zx_ns_tab, sizeof(zx_ns_tab));
  len = zx_LEN_WO_ff12_RegisterNameIdentifierRequest(c, x );
  buf = ZX_ALLOC(c, len+1);
  return zx_easy_enc_common(c, zx_ENC_WO_ff12_RegisterNameIdentifierRequest(c, x, buf ), buf, len);
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

#define EL_NAME   ff12_RegisterNameIdentifierResponse
#define EL_STRUCT zx_ff12_RegisterNameIdentifierResponse_s
#define EL_NS     ff12
#define EL_TAG    RegisterNameIdentifierResponse

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

/* FUNC(zx_LEN_SO_ff12_RegisterNameIdentifierResponse) */

/* Compute length of an element (and its subelements). The XML attributes
 * and elements are processed in schema order. */

/* Called by: */
int zx_LEN_SO_ff12_RegisterNameIdentifierResponse(struct zx_ctx* c, struct zx_ff12_RegisterNameIdentifierResponse_s* x )
{
  struct zx_ns_s* pop_seen = 0;
  struct zx_elem_s* se MAYBE_UNUSED;
#if 1 /* NORMALMODE */
  /* *** in simple_elem case should output ns prefix from ns node. */
  int len = sizeof("<ff12:RegisterNameIdentifierResponse")-1 + 1 + sizeof("</ff12:RegisterNameIdentifierResponse>")-1;
  if (c->inc_ns_len)
    len += zx_len_inc_ns(c, &pop_seen);
  len += zx_len_xmlns_if_not_seen(c, zx_ns_tab+zx_xmlns_ix_ff12, &pop_seen);

  len += zx_attr_so_len(c, x->InResponseTo, sizeof("InResponseTo")-1, &pop_seen);
  len += zx_attr_so_len(c, x->IssueInstant, sizeof("IssueInstant")-1, &pop_seen);
  len += zx_attr_so_len(c, x->MajorVersion, sizeof("MajorVersion")-1, &pop_seen);
  len += zx_attr_so_len(c, x->MinorVersion, sizeof("MinorVersion")-1, &pop_seen);
  len += zx_attr_so_len(c, x->Recipient, sizeof("Recipient")-1, &pop_seen);
  len += zx_attr_so_len(c, x->ResponseID, sizeof("ResponseID")-1, &pop_seen);

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
      struct zx_ff12_Extension_s* e;
      for (e = x->Extension; e; e = (struct zx_ff12_Extension_s*)e->gg.g.n)
	  len += zx_LEN_SO_ff12_Extension(c, e);
  }
  for (se = x->ProviderID; se; se = (struct zx_elem_s*)se->g.n)
    len += zx_LEN_SO_simple_elem(c,se, sizeof("ff12:ProviderID")-1, zx_ns_tab+zx_xmlns_ix_ff12);
  {
      struct zx_sp11_Status_s* e;
      for (e = x->Status; e; e = (struct zx_sp11_Status_s*)e->gg.g.n)
	  len += zx_LEN_SO_sp11_Status(c, e);
  }
  for (se = x->RelayState; se; se = (struct zx_elem_s*)se->g.n)
    len += zx_LEN_SO_simple_elem(c,se, sizeof("ff12:RelayState")-1, zx_ns_tab+zx_xmlns_ix_ff12);


  len += zx_len_so_common(c, &x->gg, &pop_seen);
  zx_pop_seen(pop_seen);
  ENC_LEN_DEBUG(x, "ff12:RegisterNameIdentifierResponse", len);
  return len;
}

/* FUNC(zx_LEN_WO_ff12_RegisterNameIdentifierResponse) */

/* Compute length of an element (and its subelements). The XML attributes
 * and elements are processed in wire order and no assumptions
 * are made about namespace prefixes. */

/* Called by: */
int zx_LEN_WO_ff12_RegisterNameIdentifierResponse(struct zx_ctx* c, struct zx_ff12_RegisterNameIdentifierResponse_s* x )
{
  struct zx_ns_s* pop_seen = 0;
  struct zx_elem_s* se MAYBE_UNUSED;
#if 1 /* NORMALMODE */
  int len = 1 + sizeof("RegisterNameIdentifierResponse")-1 + 1 + 2 + sizeof("RegisterNameIdentifierResponse")-1 + 1;
  
  if (x->gg.g.ns && x->gg.g.ns->prefix_len)
    len += (x->gg.g.ns->prefix_len + 1) * 2;
  if (c->inc_ns_len)
    len += zx_len_inc_ns(c, &pop_seen);
  len += zx_len_xmlns_if_not_seen(c, x->gg.g.ns, &pop_seen);

  len += zx_attr_wo_len(c, x->InResponseTo, sizeof("InResponseTo")-1, &pop_seen);
  len += zx_attr_wo_len(c, x->IssueInstant, sizeof("IssueInstant")-1, &pop_seen);
  len += zx_attr_wo_len(c, x->MajorVersion, sizeof("MajorVersion")-1, &pop_seen);
  len += zx_attr_wo_len(c, x->MinorVersion, sizeof("MinorVersion")-1, &pop_seen);
  len += zx_attr_wo_len(c, x->Recipient, sizeof("Recipient")-1, &pop_seen);
  len += zx_attr_wo_len(c, x->ResponseID, sizeof("ResponseID")-1, &pop_seen);

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
      struct zx_ff12_Extension_s* e;
      for (e = x->Extension; e; e = (struct zx_ff12_Extension_s*)e->gg.g.n)
	  len += zx_LEN_WO_ff12_Extension(c, e);
  }
  for (se = x->ProviderID; se; se = (struct zx_elem_s*)se->g.n)
    len += zx_LEN_WO_simple_elem(c, se, sizeof("ProviderID")-1);
  {
      struct zx_sp11_Status_s* e;
      for (e = x->Status; e; e = (struct zx_sp11_Status_s*)e->gg.g.n)
	  len += zx_LEN_WO_sp11_Status(c, e);
  }
  for (se = x->RelayState; se; se = (struct zx_elem_s*)se->g.n)
    len += zx_LEN_WO_simple_elem(c, se, sizeof("RelayState")-1);


  len += zx_len_wo_common(c, &x->gg, &pop_seen); 
  zx_pop_seen(pop_seen);
  ENC_LEN_DEBUG(x, "ff12:RegisterNameIdentifierResponse", len);
  return len;
}

/* FUNC(zx_ENC_SO_ff12_RegisterNameIdentifierResponse) */

/* Render element into string. The XML attributes and elements are
 * processed in schema order. This is what you generally want for
 * rendering new data structure to a string. The wo pointers are not used. */

/* Called by: */
char* zx_ENC_SO_ff12_RegisterNameIdentifierResponse(struct zx_ctx* c, struct zx_ff12_RegisterNameIdentifierResponse_s* x, char* p )
{
  struct zx_elem_s* se MAYBE_UNUSED;
  struct zx_ns_s* pop_seen = 0;
  ENC_LEN_DEBUG_BASE;
#if 1 /* NORMALMODE */
  /* *** in simple_elem case should output ns prefix from ns node. */
  ZX_OUT_TAG(p, "<ff12:RegisterNameIdentifierResponse");
  if (c->inc_ns)
    zx_add_inc_ns(c, &pop_seen);
  zx_add_xmlns_if_not_seen(c, zx_ns_tab+zx_xmlns_ix_ff12, &pop_seen);

  zx_see_unknown_attrs_ns(c, x->gg.any_attr, &pop_seen);
  p = zx_enc_seen(p, pop_seen); 
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
      struct zx_ff12_Extension_s* e;
      for (e = x->Extension; e; e = (struct zx_ff12_Extension_s*)e->gg.g.n)
	  p = zx_ENC_SO_ff12_Extension(c, e, p);
  }
  for (se = x->ProviderID; se; se = (struct zx_elem_s*)se->g.n)
    p = zx_ENC_SO_simple_elem(c, se, p, "ff12:ProviderID", sizeof("ff12:ProviderID")-1, zx_ns_tab+zx_xmlns_ix_ff12);
  {
      struct zx_sp11_Status_s* e;
      for (e = x->Status; e; e = (struct zx_sp11_Status_s*)e->gg.g.n)
	  p = zx_ENC_SO_sp11_Status(c, e, p);
  }
  for (se = x->RelayState; se; se = (struct zx_elem_s*)se->g.n)
    p = zx_ENC_SO_simple_elem(c, se, p, "ff12:RelayState", sizeof("ff12:RelayState")-1, zx_ns_tab+zx_xmlns_ix_ff12);

  p = zx_enc_so_unknown_elems_and_content(c, p, &x->gg);
  
#if 1 /* NORMALMODE */
  ZX_OUT_CLOSE_TAG(p, "</ff12:RegisterNameIdentifierResponse>");
  zx_pop_seen(pop_seen);
#else
  /* root node has no end tag either */
#endif
  ENC_LEN_DEBUG(x, "ff12:RegisterNameIdentifierResponse", p-enc_base);
  return p;
}

/* FUNC(zx_ENC_WO_ff12_RegisterNameIdentifierResponse) */

/* Render element into string. The XML attributes and elements are
 * processed in wire order by chasing wo pointers. This is what you want for
 * validating signatures on other people's XML documents. */

/* Called by: */
char* zx_ENC_WO_ff12_RegisterNameIdentifierResponse(struct zx_ctx* c, struct zx_ff12_RegisterNameIdentifierResponse_s* x, char* p )
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
  ZX_OUT_MEM(p, "RegisterNameIdentifierResponse", sizeof("RegisterNameIdentifierResponse")-1);
  qq = p;

  if (c->inc_ns)
    zx_add_inc_ns(c, &pop_seen);
  zx_add_xmlns_if_not_seen(c, x->gg.g.ns, &pop_seen);

  zx_see_unknown_attrs_ns(c, x->gg.any_attr, &pop_seen);
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
  ENC_LEN_DEBUG(x, "ff12:RegisterNameIdentifierResponse", p-enc_base);
  return p;
}

/* FUNC(zx_EASY_ENC_SO_ff12_RegisterNameIdentifierResponse) */

/* Called by: */
struct zx_str* zx_EASY_ENC_SO_ff12_RegisterNameIdentifierResponse(struct zx_ctx* c, struct zx_ff12_RegisterNameIdentifierResponse_s* x )
{
  int len;
  char* buf;
  c->ns_tab = ZX_ALLOC(c, sizeof(zx_ns_tab));
  memcpy(c->ns_tab, zx_ns_tab, sizeof(zx_ns_tab));
  len = zx_LEN_SO_ff12_RegisterNameIdentifierResponse(c, x );
  buf = ZX_ALLOC(c, len+1);
  return zx_easy_enc_common(c, zx_ENC_SO_ff12_RegisterNameIdentifierResponse(c, x, buf ), buf, len);
}

/* FUNC(zx_EASY_ENC_WO_ff12_RegisterNameIdentifierResponse) */

/* Called by: */
struct zx_str* zx_EASY_ENC_WO_ff12_RegisterNameIdentifierResponse(struct zx_ctx* c, struct zx_ff12_RegisterNameIdentifierResponse_s* x )
{
  int len;
  char* buf;
  c->ns_tab = ZX_ALLOC(c, sizeof(zx_ns_tab));
  memcpy(c->ns_tab, zx_ns_tab, sizeof(zx_ns_tab));
  len = zx_LEN_WO_ff12_RegisterNameIdentifierResponse(c, x );
  buf = ZX_ALLOC(c, len+1);
  return zx_easy_enc_common(c, zx_ENC_WO_ff12_RegisterNameIdentifierResponse(c, x, buf ), buf, len);
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

#define EL_NAME   ff12_RequestAuthnContext
#define EL_STRUCT zx_ff12_RequestAuthnContext_s
#define EL_NS     ff12
#define EL_TAG    RequestAuthnContext

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

/* FUNC(zx_LEN_SO_ff12_RequestAuthnContext) */

/* Compute length of an element (and its subelements). The XML attributes
 * and elements are processed in schema order. */

/* Called by: */
int zx_LEN_SO_ff12_RequestAuthnContext(struct zx_ctx* c, struct zx_ff12_RequestAuthnContext_s* x )
{
  struct zx_ns_s* pop_seen = 0;
  struct zx_elem_s* se MAYBE_UNUSED;
#if 1 /* NORMALMODE */
  /* *** in simple_elem case should output ns prefix from ns node. */
  int len = sizeof("<ff12:RequestAuthnContext")-1 + 1 + sizeof("</ff12:RequestAuthnContext>")-1;
  if (c->inc_ns_len)
    len += zx_len_inc_ns(c, &pop_seen);
  len += zx_len_xmlns_if_not_seen(c, zx_ns_tab+zx_xmlns_ix_ff12, &pop_seen);


#else
  /* root node has no begin tag */
  int len = 0;
#endif
  
  for (se = x->AuthnContextClassRef; se; se = (struct zx_elem_s*)se->g.n)
    len += zx_LEN_SO_simple_elem(c,se, sizeof("ff12:AuthnContextClassRef")-1, zx_ns_tab+zx_xmlns_ix_ff12);
  for (se = x->AuthnContextStatementRef; se; se = (struct zx_elem_s*)se->g.n)
    len += zx_LEN_SO_simple_elem(c,se, sizeof("ff12:AuthnContextStatementRef")-1, zx_ns_tab+zx_xmlns_ix_ff12);
  for (se = x->AuthnContextComparison; se; se = (struct zx_elem_s*)se->g.n)
    len += zx_LEN_SO_simple_elem(c,se, sizeof("ff12:AuthnContextComparison")-1, zx_ns_tab+zx_xmlns_ix_ff12);


  len += zx_len_so_common(c, &x->gg, &pop_seen);
  zx_pop_seen(pop_seen);
  ENC_LEN_DEBUG(x, "ff12:RequestAuthnContext", len);
  return len;
}

/* FUNC(zx_LEN_WO_ff12_RequestAuthnContext) */

/* Compute length of an element (and its subelements). The XML attributes
 * and elements are processed in wire order and no assumptions
 * are made about namespace prefixes. */

/* Called by: */
int zx_LEN_WO_ff12_RequestAuthnContext(struct zx_ctx* c, struct zx_ff12_RequestAuthnContext_s* x )
{
  struct zx_ns_s* pop_seen = 0;
  struct zx_elem_s* se MAYBE_UNUSED;
#if 1 /* NORMALMODE */
  int len = 1 + sizeof("RequestAuthnContext")-1 + 1 + 2 + sizeof("RequestAuthnContext")-1 + 1;
  
  if (x->gg.g.ns && x->gg.g.ns->prefix_len)
    len += (x->gg.g.ns->prefix_len + 1) * 2;
  if (c->inc_ns_len)
    len += zx_len_inc_ns(c, &pop_seen);
  len += zx_len_xmlns_if_not_seen(c, x->gg.g.ns, &pop_seen);


#else
  /* root node has no begin tag */
  int len = 0;
#endif
  
  for (se = x->AuthnContextClassRef; se; se = (struct zx_elem_s*)se->g.n)
    len += zx_LEN_WO_simple_elem(c, se, sizeof("AuthnContextClassRef")-1);
  for (se = x->AuthnContextStatementRef; se; se = (struct zx_elem_s*)se->g.n)
    len += zx_LEN_WO_simple_elem(c, se, sizeof("AuthnContextStatementRef")-1);
  for (se = x->AuthnContextComparison; se; se = (struct zx_elem_s*)se->g.n)
    len += zx_LEN_WO_simple_elem(c, se, sizeof("AuthnContextComparison")-1);


  len += zx_len_wo_common(c, &x->gg, &pop_seen); 
  zx_pop_seen(pop_seen);
  ENC_LEN_DEBUG(x, "ff12:RequestAuthnContext", len);
  return len;
}

/* FUNC(zx_ENC_SO_ff12_RequestAuthnContext) */

/* Render element into string. The XML attributes and elements are
 * processed in schema order. This is what you generally want for
 * rendering new data structure to a string. The wo pointers are not used. */

/* Called by: */
char* zx_ENC_SO_ff12_RequestAuthnContext(struct zx_ctx* c, struct zx_ff12_RequestAuthnContext_s* x, char* p )
{
  struct zx_elem_s* se MAYBE_UNUSED;
  struct zx_ns_s* pop_seen = 0;
  ENC_LEN_DEBUG_BASE;
#if 1 /* NORMALMODE */
  /* *** in simple_elem case should output ns prefix from ns node. */
  ZX_OUT_TAG(p, "<ff12:RequestAuthnContext");
  if (c->inc_ns)
    zx_add_inc_ns(c, &pop_seen);
  zx_add_xmlns_if_not_seen(c, zx_ns_tab+zx_xmlns_ix_ff12, &pop_seen);

  zx_see_unknown_attrs_ns(c, x->gg.any_attr, &pop_seen);
  p = zx_enc_seen(p, pop_seen); 

  p = zx_enc_unknown_attrs(p, x->gg.any_attr);
#else
  /* root node has no begin tag */
#endif
  
  for (se = x->AuthnContextClassRef; se; se = (struct zx_elem_s*)se->g.n)
    p = zx_ENC_SO_simple_elem(c, se, p, "ff12:AuthnContextClassRef", sizeof("ff12:AuthnContextClassRef")-1, zx_ns_tab+zx_xmlns_ix_ff12);
  for (se = x->AuthnContextStatementRef; se; se = (struct zx_elem_s*)se->g.n)
    p = zx_ENC_SO_simple_elem(c, se, p, "ff12:AuthnContextStatementRef", sizeof("ff12:AuthnContextStatementRef")-1, zx_ns_tab+zx_xmlns_ix_ff12);
  for (se = x->AuthnContextComparison; se; se = (struct zx_elem_s*)se->g.n)
    p = zx_ENC_SO_simple_elem(c, se, p, "ff12:AuthnContextComparison", sizeof("ff12:AuthnContextComparison")-1, zx_ns_tab+zx_xmlns_ix_ff12);

  p = zx_enc_so_unknown_elems_and_content(c, p, &x->gg);
  
#if 1 /* NORMALMODE */
  ZX_OUT_CLOSE_TAG(p, "</ff12:RequestAuthnContext>");
  zx_pop_seen(pop_seen);
#else
  /* root node has no end tag either */
#endif
  ENC_LEN_DEBUG(x, "ff12:RequestAuthnContext", p-enc_base);
  return p;
}

/* FUNC(zx_ENC_WO_ff12_RequestAuthnContext) */

/* Render element into string. The XML attributes and elements are
 * processed in wire order by chasing wo pointers. This is what you want for
 * validating signatures on other people's XML documents. */

/* Called by: */
char* zx_ENC_WO_ff12_RequestAuthnContext(struct zx_ctx* c, struct zx_ff12_RequestAuthnContext_s* x, char* p )
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
  ZX_OUT_MEM(p, "RequestAuthnContext", sizeof("RequestAuthnContext")-1);
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
  ENC_LEN_DEBUG(x, "ff12:RequestAuthnContext", p-enc_base);
  return p;
}

/* FUNC(zx_EASY_ENC_SO_ff12_RequestAuthnContext) */

/* Called by: */
struct zx_str* zx_EASY_ENC_SO_ff12_RequestAuthnContext(struct zx_ctx* c, struct zx_ff12_RequestAuthnContext_s* x )
{
  int len;
  char* buf;
  c->ns_tab = ZX_ALLOC(c, sizeof(zx_ns_tab));
  memcpy(c->ns_tab, zx_ns_tab, sizeof(zx_ns_tab));
  len = zx_LEN_SO_ff12_RequestAuthnContext(c, x );
  buf = ZX_ALLOC(c, len+1);
  return zx_easy_enc_common(c, zx_ENC_SO_ff12_RequestAuthnContext(c, x, buf ), buf, len);
}

/* FUNC(zx_EASY_ENC_WO_ff12_RequestAuthnContext) */

/* Called by: */
struct zx_str* zx_EASY_ENC_WO_ff12_RequestAuthnContext(struct zx_ctx* c, struct zx_ff12_RequestAuthnContext_s* x )
{
  int len;
  char* buf;
  c->ns_tab = ZX_ALLOC(c, sizeof(zx_ns_tab));
  memcpy(c->ns_tab, zx_ns_tab, sizeof(zx_ns_tab));
  len = zx_LEN_WO_ff12_RequestAuthnContext(c, x );
  buf = ZX_ALLOC(c, len+1);
  return zx_easy_enc_common(c, zx_ENC_WO_ff12_RequestAuthnContext(c, x, buf ), buf, len);
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

#define EL_NAME   ff12_SPProvidedNameIdentifier
#define EL_STRUCT zx_ff12_SPProvidedNameIdentifier_s
#define EL_NS     ff12
#define EL_TAG    SPProvidedNameIdentifier

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

/* FUNC(zx_LEN_SO_ff12_SPProvidedNameIdentifier) */

/* Compute length of an element (and its subelements). The XML attributes
 * and elements are processed in schema order. */

/* Called by: */
int zx_LEN_SO_ff12_SPProvidedNameIdentifier(struct zx_ctx* c, struct zx_ff12_SPProvidedNameIdentifier_s* x )
{
  struct zx_ns_s* pop_seen = 0;
  struct zx_elem_s* se MAYBE_UNUSED;
#if 1 /* NORMALMODE */
  /* *** in simple_elem case should output ns prefix from ns node. */
  int len = sizeof("<ff12:SPProvidedNameIdentifier")-1 + 1 + sizeof("</ff12:SPProvidedNameIdentifier>")-1;
  if (c->inc_ns_len)
    len += zx_len_inc_ns(c, &pop_seen);
  len += zx_len_xmlns_if_not_seen(c, zx_ns_tab+zx_xmlns_ix_ff12, &pop_seen);

  len += zx_attr_so_len(c, x->Format, sizeof("Format")-1, &pop_seen);
  len += zx_attr_so_len(c, x->NameQualifier, sizeof("NameQualifier")-1, &pop_seen);

#else
  /* root node has no begin tag */
  int len = 0;
#endif
  


  len += zx_len_so_common(c, &x->gg, &pop_seen);
  zx_pop_seen(pop_seen);
  ENC_LEN_DEBUG(x, "ff12:SPProvidedNameIdentifier", len);
  return len;
}

/* FUNC(zx_LEN_WO_ff12_SPProvidedNameIdentifier) */

/* Compute length of an element (and its subelements). The XML attributes
 * and elements are processed in wire order and no assumptions
 * are made about namespace prefixes. */

/* Called by: */
int zx_LEN_WO_ff12_SPProvidedNameIdentifier(struct zx_ctx* c, struct zx_ff12_SPProvidedNameIdentifier_s* x )
{
  struct zx_ns_s* pop_seen = 0;
  struct zx_elem_s* se MAYBE_UNUSED;
#if 1 /* NORMALMODE */
  int len = 1 + sizeof("SPProvidedNameIdentifier")-1 + 1 + 2 + sizeof("SPProvidedNameIdentifier")-1 + 1;
  
  if (x->gg.g.ns && x->gg.g.ns->prefix_len)
    len += (x->gg.g.ns->prefix_len + 1) * 2;
  if (c->inc_ns_len)
    len += zx_len_inc_ns(c, &pop_seen);
  len += zx_len_xmlns_if_not_seen(c, x->gg.g.ns, &pop_seen);

  len += zx_attr_wo_len(c, x->Format, sizeof("Format")-1, &pop_seen);
  len += zx_attr_wo_len(c, x->NameQualifier, sizeof("NameQualifier")-1, &pop_seen);

#else
  /* root node has no begin tag */
  int len = 0;
#endif
  


  len += zx_len_wo_common(c, &x->gg, &pop_seen); 
  zx_pop_seen(pop_seen);
  ENC_LEN_DEBUG(x, "ff12:SPProvidedNameIdentifier", len);
  return len;
}

/* FUNC(zx_ENC_SO_ff12_SPProvidedNameIdentifier) */

/* Render element into string. The XML attributes and elements are
 * processed in schema order. This is what you generally want for
 * rendering new data structure to a string. The wo pointers are not used. */

/* Called by: */
char* zx_ENC_SO_ff12_SPProvidedNameIdentifier(struct zx_ctx* c, struct zx_ff12_SPProvidedNameIdentifier_s* x, char* p )
{
  struct zx_elem_s* se MAYBE_UNUSED;
  struct zx_ns_s* pop_seen = 0;
  ENC_LEN_DEBUG_BASE;
#if 1 /* NORMALMODE */
  /* *** in simple_elem case should output ns prefix from ns node. */
  ZX_OUT_TAG(p, "<ff12:SPProvidedNameIdentifier");
  if (c->inc_ns)
    zx_add_inc_ns(c, &pop_seen);
  zx_add_xmlns_if_not_seen(c, zx_ns_tab+zx_xmlns_ix_ff12, &pop_seen);

  zx_see_unknown_attrs_ns(c, x->gg.any_attr, &pop_seen);
  p = zx_enc_seen(p, pop_seen); 
  p = zx_attr_so_enc(p, x->Format, " Format=\"", sizeof(" Format=\"")-1);
  p = zx_attr_so_enc(p, x->NameQualifier, " NameQualifier=\"", sizeof(" NameQualifier=\"")-1);

  p = zx_enc_unknown_attrs(p, x->gg.any_attr);
#else
  /* root node has no begin tag */
#endif
  

  p = zx_enc_so_unknown_elems_and_content(c, p, &x->gg);
  
#if 1 /* NORMALMODE */
  ZX_OUT_CLOSE_TAG(p, "</ff12:SPProvidedNameIdentifier>");
  zx_pop_seen(pop_seen);
#else
  /* root node has no end tag either */
#endif
  ENC_LEN_DEBUG(x, "ff12:SPProvidedNameIdentifier", p-enc_base);
  return p;
}

/* FUNC(zx_ENC_WO_ff12_SPProvidedNameIdentifier) */

/* Render element into string. The XML attributes and elements are
 * processed in wire order by chasing wo pointers. This is what you want for
 * validating signatures on other people's XML documents. */

/* Called by: */
char* zx_ENC_WO_ff12_SPProvidedNameIdentifier(struct zx_ctx* c, struct zx_ff12_SPProvidedNameIdentifier_s* x, char* p )
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
  ZX_OUT_MEM(p, "SPProvidedNameIdentifier", sizeof("SPProvidedNameIdentifier")-1);
  qq = p;

  if (c->inc_ns)
    zx_add_inc_ns(c, &pop_seen);
  zx_add_xmlns_if_not_seen(c, x->gg.g.ns, &pop_seen);

  zx_see_unknown_attrs_ns(c, x->gg.any_attr, &pop_seen);
  p = zx_enc_seen(p, pop_seen); 
  p = zx_attr_wo_enc(p, x->Format, "Format=\"", sizeof("Format=\"")-1);
  p = zx_attr_wo_enc(p, x->NameQualifier, "NameQualifier=\"", sizeof("NameQualifier=\"")-1);

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
  ENC_LEN_DEBUG(x, "ff12:SPProvidedNameIdentifier", p-enc_base);
  return p;
}

/* FUNC(zx_EASY_ENC_SO_ff12_SPProvidedNameIdentifier) */

/* Called by: */
struct zx_str* zx_EASY_ENC_SO_ff12_SPProvidedNameIdentifier(struct zx_ctx* c, struct zx_ff12_SPProvidedNameIdentifier_s* x )
{
  int len;
  char* buf;
  c->ns_tab = ZX_ALLOC(c, sizeof(zx_ns_tab));
  memcpy(c->ns_tab, zx_ns_tab, sizeof(zx_ns_tab));
  len = zx_LEN_SO_ff12_SPProvidedNameIdentifier(c, x );
  buf = ZX_ALLOC(c, len+1);
  return zx_easy_enc_common(c, zx_ENC_SO_ff12_SPProvidedNameIdentifier(c, x, buf ), buf, len);
}

/* FUNC(zx_EASY_ENC_WO_ff12_SPProvidedNameIdentifier) */

/* Called by: */
struct zx_str* zx_EASY_ENC_WO_ff12_SPProvidedNameIdentifier(struct zx_ctx* c, struct zx_ff12_SPProvidedNameIdentifier_s* x )
{
  int len;
  char* buf;
  c->ns_tab = ZX_ALLOC(c, sizeof(zx_ns_tab));
  memcpy(c->ns_tab, zx_ns_tab, sizeof(zx_ns_tab));
  len = zx_LEN_WO_ff12_SPProvidedNameIdentifier(c, x );
  buf = ZX_ALLOC(c, len+1);
  return zx_easy_enc_common(c, zx_ENC_WO_ff12_SPProvidedNameIdentifier(c, x, buf ), buf, len);
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

#define EL_NAME   ff12_Scoping
#define EL_STRUCT zx_ff12_Scoping_s
#define EL_NS     ff12
#define EL_TAG    Scoping

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

/* FUNC(zx_LEN_SO_ff12_Scoping) */

/* Compute length of an element (and its subelements). The XML attributes
 * and elements are processed in schema order. */

/* Called by: */
int zx_LEN_SO_ff12_Scoping(struct zx_ctx* c, struct zx_ff12_Scoping_s* x )
{
  struct zx_ns_s* pop_seen = 0;
  struct zx_elem_s* se MAYBE_UNUSED;
#if 1 /* NORMALMODE */
  /* *** in simple_elem case should output ns prefix from ns node. */
  int len = sizeof("<ff12:Scoping")-1 + 1 + sizeof("</ff12:Scoping>")-1;
  if (c->inc_ns_len)
    len += zx_len_inc_ns(c, &pop_seen);
  len += zx_len_xmlns_if_not_seen(c, zx_ns_tab+zx_xmlns_ix_ff12, &pop_seen);


#else
  /* root node has no begin tag */
  int len = 0;
#endif
  
  for (se = x->ProxyCount; se; se = (struct zx_elem_s*)se->g.n)
    len += zx_LEN_SO_simple_elem(c,se, sizeof("ff12:ProxyCount")-1, zx_ns_tab+zx_xmlns_ix_ff12);
  {
      struct zx_ff12_IDPList_s* e;
      for (e = x->IDPList; e; e = (struct zx_ff12_IDPList_s*)e->gg.g.n)
	  len += zx_LEN_SO_ff12_IDPList(c, e);
  }


  len += zx_len_so_common(c, &x->gg, &pop_seen);
  zx_pop_seen(pop_seen);
  ENC_LEN_DEBUG(x, "ff12:Scoping", len);
  return len;
}

/* FUNC(zx_LEN_WO_ff12_Scoping) */

/* Compute length of an element (and its subelements). The XML attributes
 * and elements are processed in wire order and no assumptions
 * are made about namespace prefixes. */

/* Called by: */
int zx_LEN_WO_ff12_Scoping(struct zx_ctx* c, struct zx_ff12_Scoping_s* x )
{
  struct zx_ns_s* pop_seen = 0;
  struct zx_elem_s* se MAYBE_UNUSED;
#if 1 /* NORMALMODE */
  int len = 1 + sizeof("Scoping")-1 + 1 + 2 + sizeof("Scoping")-1 + 1;
  
  if (x->gg.g.ns && x->gg.g.ns->prefix_len)
    len += (x->gg.g.ns->prefix_len + 1) * 2;
  if (c->inc_ns_len)
    len += zx_len_inc_ns(c, &pop_seen);
  len += zx_len_xmlns_if_not_seen(c, x->gg.g.ns, &pop_seen);


#else
  /* root node has no begin tag */
  int len = 0;
#endif
  
  for (se = x->ProxyCount; se; se = (struct zx_elem_s*)se->g.n)
    len += zx_LEN_WO_simple_elem(c, se, sizeof("ProxyCount")-1);
  {
      struct zx_ff12_IDPList_s* e;
      for (e = x->IDPList; e; e = (struct zx_ff12_IDPList_s*)e->gg.g.n)
	  len += zx_LEN_WO_ff12_IDPList(c, e);
  }


  len += zx_len_wo_common(c, &x->gg, &pop_seen); 
  zx_pop_seen(pop_seen);
  ENC_LEN_DEBUG(x, "ff12:Scoping", len);
  return len;
}

/* FUNC(zx_ENC_SO_ff12_Scoping) */

/* Render element into string. The XML attributes and elements are
 * processed in schema order. This is what you generally want for
 * rendering new data structure to a string. The wo pointers are not used. */

/* Called by: */
char* zx_ENC_SO_ff12_Scoping(struct zx_ctx* c, struct zx_ff12_Scoping_s* x, char* p )
{
  struct zx_elem_s* se MAYBE_UNUSED;
  struct zx_ns_s* pop_seen = 0;
  ENC_LEN_DEBUG_BASE;
#if 1 /* NORMALMODE */
  /* *** in simple_elem case should output ns prefix from ns node. */
  ZX_OUT_TAG(p, "<ff12:Scoping");
  if (c->inc_ns)
    zx_add_inc_ns(c, &pop_seen);
  zx_add_xmlns_if_not_seen(c, zx_ns_tab+zx_xmlns_ix_ff12, &pop_seen);

  zx_see_unknown_attrs_ns(c, x->gg.any_attr, &pop_seen);
  p = zx_enc_seen(p, pop_seen); 

  p = zx_enc_unknown_attrs(p, x->gg.any_attr);
#else
  /* root node has no begin tag */
#endif
  
  for (se = x->ProxyCount; se; se = (struct zx_elem_s*)se->g.n)
    p = zx_ENC_SO_simple_elem(c, se, p, "ff12:ProxyCount", sizeof("ff12:ProxyCount")-1, zx_ns_tab+zx_xmlns_ix_ff12);
  {
      struct zx_ff12_IDPList_s* e;
      for (e = x->IDPList; e; e = (struct zx_ff12_IDPList_s*)e->gg.g.n)
	  p = zx_ENC_SO_ff12_IDPList(c, e, p);
  }

  p = zx_enc_so_unknown_elems_and_content(c, p, &x->gg);
  
#if 1 /* NORMALMODE */
  ZX_OUT_CLOSE_TAG(p, "</ff12:Scoping>");
  zx_pop_seen(pop_seen);
#else
  /* root node has no end tag either */
#endif
  ENC_LEN_DEBUG(x, "ff12:Scoping", p-enc_base);
  return p;
}

/* FUNC(zx_ENC_WO_ff12_Scoping) */

/* Render element into string. The XML attributes and elements are
 * processed in wire order by chasing wo pointers. This is what you want for
 * validating signatures on other people's XML documents. */

/* Called by: */
char* zx_ENC_WO_ff12_Scoping(struct zx_ctx* c, struct zx_ff12_Scoping_s* x, char* p )
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
  ZX_OUT_MEM(p, "Scoping", sizeof("Scoping")-1);
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
  ENC_LEN_DEBUG(x, "ff12:Scoping", p-enc_base);
  return p;
}

/* FUNC(zx_EASY_ENC_SO_ff12_Scoping) */

/* Called by: */
struct zx_str* zx_EASY_ENC_SO_ff12_Scoping(struct zx_ctx* c, struct zx_ff12_Scoping_s* x )
{
  int len;
  char* buf;
  c->ns_tab = ZX_ALLOC(c, sizeof(zx_ns_tab));
  memcpy(c->ns_tab, zx_ns_tab, sizeof(zx_ns_tab));
  len = zx_LEN_SO_ff12_Scoping(c, x );
  buf = ZX_ALLOC(c, len+1);
  return zx_easy_enc_common(c, zx_ENC_SO_ff12_Scoping(c, x, buf ), buf, len);
}

/* FUNC(zx_EASY_ENC_WO_ff12_Scoping) */

/* Called by: */
struct zx_str* zx_EASY_ENC_WO_ff12_Scoping(struct zx_ctx* c, struct zx_ff12_Scoping_s* x )
{
  int len;
  char* buf;
  c->ns_tab = ZX_ALLOC(c, sizeof(zx_ns_tab));
  memcpy(c->ns_tab, zx_ns_tab, sizeof(zx_ns_tab));
  len = zx_LEN_WO_ff12_Scoping(c, x );
  buf = ZX_ALLOC(c, len+1);
  return zx_easy_enc_common(c, zx_ENC_WO_ff12_Scoping(c, x, buf ), buf, len);
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

#define EL_NAME   ff12_Subject
#define EL_STRUCT zx_ff12_Subject_s
#define EL_NS     ff12
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

/* FUNC(zx_LEN_SO_ff12_Subject) */

/* Compute length of an element (and its subelements). The XML attributes
 * and elements are processed in schema order. */

/* Called by: */
int zx_LEN_SO_ff12_Subject(struct zx_ctx* c, struct zx_ff12_Subject_s* x )
{
  struct zx_ns_s* pop_seen = 0;
  struct zx_elem_s* se MAYBE_UNUSED;
#if 1 /* NORMALMODE */
  /* *** in simple_elem case should output ns prefix from ns node. */
  int len = sizeof("<ff12:Subject")-1 + 1 + sizeof("</ff12:Subject>")-1;
  if (c->inc_ns_len)
    len += zx_len_inc_ns(c, &pop_seen);
  len += zx_len_xmlns_if_not_seen(c, zx_ns_tab+zx_xmlns_ix_ff12, &pop_seen);


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
  ENC_LEN_DEBUG(x, "ff12:Subject", len);
  return len;
}

/* FUNC(zx_LEN_WO_ff12_Subject) */

/* Compute length of an element (and its subelements). The XML attributes
 * and elements are processed in wire order and no assumptions
 * are made about namespace prefixes. */

/* Called by: */
int zx_LEN_WO_ff12_Subject(struct zx_ctx* c, struct zx_ff12_Subject_s* x )
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
  ENC_LEN_DEBUG(x, "ff12:Subject", len);
  return len;
}

/* FUNC(zx_ENC_SO_ff12_Subject) */

/* Render element into string. The XML attributes and elements are
 * processed in schema order. This is what you generally want for
 * rendering new data structure to a string. The wo pointers are not used. */

/* Called by: */
char* zx_ENC_SO_ff12_Subject(struct zx_ctx* c, struct zx_ff12_Subject_s* x, char* p )
{
  struct zx_elem_s* se MAYBE_UNUSED;
  struct zx_ns_s* pop_seen = 0;
  ENC_LEN_DEBUG_BASE;
#if 1 /* NORMALMODE */
  /* *** in simple_elem case should output ns prefix from ns node. */
  ZX_OUT_TAG(p, "<ff12:Subject");
  if (c->inc_ns)
    zx_add_inc_ns(c, &pop_seen);
  zx_add_xmlns_if_not_seen(c, zx_ns_tab+zx_xmlns_ix_ff12, &pop_seen);

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
  ZX_OUT_CLOSE_TAG(p, "</ff12:Subject>");
  zx_pop_seen(pop_seen);
#else
  /* root node has no end tag either */
#endif
  ENC_LEN_DEBUG(x, "ff12:Subject", p-enc_base);
  return p;
}

/* FUNC(zx_ENC_WO_ff12_Subject) */

/* Render element into string. The XML attributes and elements are
 * processed in wire order by chasing wo pointers. This is what you want for
 * validating signatures on other people's XML documents. */

/* Called by: */
char* zx_ENC_WO_ff12_Subject(struct zx_ctx* c, struct zx_ff12_Subject_s* x, char* p )
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
  ENC_LEN_DEBUG(x, "ff12:Subject", p-enc_base);
  return p;
}

/* FUNC(zx_EASY_ENC_SO_ff12_Subject) */

/* Called by: */
struct zx_str* zx_EASY_ENC_SO_ff12_Subject(struct zx_ctx* c, struct zx_ff12_Subject_s* x )
{
  int len;
  char* buf;
  c->ns_tab = ZX_ALLOC(c, sizeof(zx_ns_tab));
  memcpy(c->ns_tab, zx_ns_tab, sizeof(zx_ns_tab));
  len = zx_LEN_SO_ff12_Subject(c, x );
  buf = ZX_ALLOC(c, len+1);
  return zx_easy_enc_common(c, zx_ENC_SO_ff12_Subject(c, x, buf ), buf, len);
}

/* FUNC(zx_EASY_ENC_WO_ff12_Subject) */

/* Called by: */
struct zx_str* zx_EASY_ENC_WO_ff12_Subject(struct zx_ctx* c, struct zx_ff12_Subject_s* x )
{
  int len;
  char* buf;
  c->ns_tab = ZX_ALLOC(c, sizeof(zx_ns_tab));
  memcpy(c->ns_tab, zx_ns_tab, sizeof(zx_ns_tab));
  len = zx_LEN_WO_ff12_Subject(c, x );
  buf = ZX_ALLOC(c, len+1);
  return zx_easy_enc_common(c, zx_ENC_WO_ff12_Subject(c, x, buf ), buf, len);
}




/* EOF -- c/zx-ff12-enc.c */
