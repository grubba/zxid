/* c/zx-m20-enc.c - WARNING: This file was automatically generated. DO NOT EDIT!
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
#include "c/zx-m20-data.h"
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

#define EL_NAME   m20_AdditionalMetaLocation
#define EL_STRUCT zx_m20_AdditionalMetaLocation_s
#define EL_NS     m20
#define EL_TAG    AdditionalMetaLocation

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

/* FUNC(zx_LEN_SO_m20_AdditionalMetaLocation) */

/* Compute length of an element (and its subelements). The XML attributes
 * and elements are processed in schema order. */

/* Called by: */
int zx_LEN_SO_m20_AdditionalMetaLocation(struct zx_ctx* c, struct zx_m20_AdditionalMetaLocation_s* x )
{
  struct zx_ns_s* pop_seen = 0;
  struct zx_elem_s* se MAYBE_UNUSED;
#if 1 /* NORMALMODE */
  /* *** in simple_elem case should output ns prefix from ns node. */
  int len = sizeof("<m20:AdditionalMetaLocation")-1 + 1 + sizeof("</m20:AdditionalMetaLocation>")-1;
  if (c->inc_ns_len)
    len += zx_len_inc_ns(c, &pop_seen);
  len += zx_len_xmlns_if_not_seen(c, zx_ns_tab+zx_xmlns_ix_m20, &pop_seen);

  len += zx_attr_so_len(x->namespace_is_cxx_keyword, sizeof("namespace")-1);

#else
  /* root node has no begin tag */
  int len = 0;
#endif
  


  len += zx_len_so_common(c, &x->gg);
  zx_pop_seen(pop_seen);
  ENC_LEN_DEBUG(x, "m20:AdditionalMetaLocation", len);
  return len;
}

/* FUNC(zx_LEN_WO_m20_AdditionalMetaLocation) */

/* Compute length of an element (and its subelements). The XML attributes
 * and elements are processed in wire order and no assumptions
 * are made about namespace prefixes. */

/* Called by: */
int zx_LEN_WO_m20_AdditionalMetaLocation(struct zx_ctx* c, struct zx_m20_AdditionalMetaLocation_s* x )
{
  struct zx_ns_s* pop_seen = 0;
  struct zx_elem_s* se MAYBE_UNUSED;
#if 1 /* NORMALMODE */
  int len = 1 + sizeof("AdditionalMetaLocation")-1 + 1 + 2 + sizeof("AdditionalMetaLocation")-1 + 1;
  
  if (x->gg.g.ns && x->gg.g.ns->prefix_len)
    len += (x->gg.g.ns->prefix_len + 1) * 2;
  if (c->inc_ns_len)
    len += zx_len_inc_ns(c, &pop_seen);
  len += zx_len_xmlns_if_not_seen(c, x->gg.g.ns, &pop_seen);

  len += zx_attr_wo_len(x->namespace_is_cxx_keyword, sizeof("namespace")-1);

#else
  /* root node has no begin tag */
  int len = 0;
#endif
  


  len += zx_len_wo_common(c, &x->gg); 
  zx_pop_seen(pop_seen);
  ENC_LEN_DEBUG(x, "m20:AdditionalMetaLocation", len);
  return len;
}

/* FUNC(zx_ENC_SO_m20_AdditionalMetaLocation) */

/* Render element into string. The XML attributes and elements are
 * processed in schema order. This is what you generally want for
 * rendering new data structure to a string. The wo pointers are not used. */

/* Called by: */
char* zx_ENC_SO_m20_AdditionalMetaLocation(struct zx_ctx* c, struct zx_m20_AdditionalMetaLocation_s* x, char* p )
{
  struct zx_elem_s* se MAYBE_UNUSED;
  struct zx_ns_s* pop_seen = 0;
  ENC_LEN_DEBUG_BASE;
#if 1 /* NORMALMODE */
  /* *** in simple_elem case should output ns prefix from ns node. */
  ZX_OUT_TAG(p, "<m20:AdditionalMetaLocation");
  if (c->inc_ns)
    p = zx_enc_inc_ns(c, p, &pop_seen);
  p = zx_enc_xmlns_if_not_seen(c, p, zx_ns_tab+zx_xmlns_ix_m20, &pop_seen);

  p = zx_attr_so_enc(p, x->namespace_is_cxx_keyword, " namespace=\"", sizeof(" namespace=\"")-1);

  p = zx_enc_unknown_attrs(p, x->gg.any_attr);
#else
  /* root node has no begin tag */
#endif
  

  p = zx_enc_so_unknown_elems_and_content(c, p, &x->gg);
  
#if 1 /* NORMALMODE */
  ZX_OUT_CLOSE_TAG(p, "</m20:AdditionalMetaLocation>");
  zx_pop_seen(pop_seen);
#else
  /* root node has no end tag either */
#endif
  ENC_LEN_DEBUG(x, "m20:AdditionalMetaLocation", p-enc_base);
  return p;
}

/* FUNC(zx_ENC_WO_m20_AdditionalMetaLocation) */

/* Render element into string. The XML attributes and elements are
 * processed in wire order by chasing wo pointers. This is what you want for
 * validating signatures on other people's XML documents. */

/* Called by: */
char* zx_ENC_WO_m20_AdditionalMetaLocation(struct zx_ctx* c, struct zx_m20_AdditionalMetaLocation_s* x, char* p )
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
  ZX_OUT_MEM(p, "AdditionalMetaLocation", sizeof("AdditionalMetaLocation")-1);
  qq = p;

  /* *** sort the namespaces */
  if (c->inc_ns)
    zx_add_inc_ns(c, &pop_seen);
  zx_add_xmlns_if_not_seen(c, x->gg.g.ns, &pop_seen);

  p = zx_enc_seen(p, pop_seen); 
  p = zx_attr_wo_enc(p, x->namespace_is_cxx_keyword, "namespace=\"", sizeof("namespace=\"")-1);

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
  ENC_LEN_DEBUG(x, "m20:AdditionalMetaLocation", p-enc_base);
  return p;
}

/* FUNC(zx_EASY_ENC_SO_m20_AdditionalMetaLocation) */

/* Called by: */
struct zx_str* zx_EASY_ENC_SO_m20_AdditionalMetaLocation(struct zx_ctx* c, struct zx_m20_AdditionalMetaLocation_s* x )
{
  int len;
  char* buf;
  c->ns_tab = ZX_ALLOC(c, sizeof(zx_ns_tab));
  memcpy(c->ns_tab, zx_ns_tab, sizeof(zx_ns_tab));
  len = zx_LEN_SO_m20_AdditionalMetaLocation(c, x );
  buf = ZX_ALLOC(c, len+1);
  return zx_easy_enc_common(c, zx_ENC_SO_m20_AdditionalMetaLocation(c, x, buf ), buf, len);
}

/* FUNC(zx_EASY_ENC_WO_m20_AdditionalMetaLocation) */

/* Called by: */
struct zx_str* zx_EASY_ENC_WO_m20_AdditionalMetaLocation(struct zx_ctx* c, struct zx_m20_AdditionalMetaLocation_s* x )
{
  int len;
  char* buf;
  c->ns_tab = ZX_ALLOC(c, sizeof(zx_ns_tab));
  memcpy(c->ns_tab, zx_ns_tab, sizeof(zx_ns_tab));
  len = zx_LEN_WO_m20_AdditionalMetaLocation(c, x );
  buf = ZX_ALLOC(c, len+1);
  return zx_easy_enc_common(c, zx_ENC_WO_m20_AdditionalMetaLocation(c, x, buf ), buf, len);
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

#define EL_NAME   m20_AffiliationDescriptor
#define EL_STRUCT zx_m20_AffiliationDescriptor_s
#define EL_NS     m20
#define EL_TAG    AffiliationDescriptor

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

/* FUNC(zx_LEN_SO_m20_AffiliationDescriptor) */

/* Compute length of an element (and its subelements). The XML attributes
 * and elements are processed in schema order. */

/* Called by: */
int zx_LEN_SO_m20_AffiliationDescriptor(struct zx_ctx* c, struct zx_m20_AffiliationDescriptor_s* x )
{
  struct zx_ns_s* pop_seen = 0;
  struct zx_elem_s* se MAYBE_UNUSED;
#if 1 /* NORMALMODE */
  /* *** in simple_elem case should output ns prefix from ns node. */
  int len = sizeof("<m20:AffiliationDescriptor")-1 + 1 + sizeof("</m20:AffiliationDescriptor>")-1;
  if (c->inc_ns_len)
    len += zx_len_inc_ns(c, &pop_seen);
  len += zx_len_xmlns_if_not_seen(c, zx_ns_tab+zx_xmlns_ix_m20, &pop_seen);

  len += zx_attr_so_len(x->affiliationOwnerID, sizeof("affiliationOwnerID")-1);
  len += zx_attr_so_len(x->cacheDuration, sizeof("cacheDuration")-1);
  len += zx_attr_so_len(x->id, sizeof("id")-1);
  len += zx_attr_so_len(x->validUntil, sizeof("validUntil")-1);

#else
  /* root node has no begin tag */
  int len = 0;
#endif
  
  for (se = x->AffiliateMember; se; se = (struct zx_elem_s*)se->g.n)
    len += zx_LEN_SO_simple_elem(c,se, sizeof("m20:AffiliateMember")-1, zx_ns_tab+zx_xmlns_ix_m20);
  {
      struct zx_m20_Extension_s* e;
      for (e = x->Extension; e; e = (struct zx_m20_Extension_s*)e->gg.g.n)
	  len += zx_LEN_SO_m20_Extension(c, e);
  }
  {
      struct zx_m20_KeyDescriptor_s* e;
      for (e = x->KeyDescriptor; e; e = (struct zx_m20_KeyDescriptor_s*)e->gg.g.n)
	  len += zx_LEN_SO_m20_KeyDescriptor(c, e);
  }
  {
      struct zx_ds_Signature_s* e;
      for (e = x->Signature; e; e = (struct zx_ds_Signature_s*)e->gg.g.n)
	  if (e != c->exclude_sig)
              len += zx_LEN_SO_ds_Signature(c, e);
  }


  len += zx_len_so_common(c, &x->gg);
  zx_pop_seen(pop_seen);
  ENC_LEN_DEBUG(x, "m20:AffiliationDescriptor", len);
  return len;
}

/* FUNC(zx_LEN_WO_m20_AffiliationDescriptor) */

/* Compute length of an element (and its subelements). The XML attributes
 * and elements are processed in wire order and no assumptions
 * are made about namespace prefixes. */

/* Called by: */
int zx_LEN_WO_m20_AffiliationDescriptor(struct zx_ctx* c, struct zx_m20_AffiliationDescriptor_s* x )
{
  struct zx_ns_s* pop_seen = 0;
  struct zx_elem_s* se MAYBE_UNUSED;
#if 1 /* NORMALMODE */
  int len = 1 + sizeof("AffiliationDescriptor")-1 + 1 + 2 + sizeof("AffiliationDescriptor")-1 + 1;
  
  if (x->gg.g.ns && x->gg.g.ns->prefix_len)
    len += (x->gg.g.ns->prefix_len + 1) * 2;
  if (c->inc_ns_len)
    len += zx_len_inc_ns(c, &pop_seen);
  len += zx_len_xmlns_if_not_seen(c, x->gg.g.ns, &pop_seen);

  len += zx_attr_wo_len(x->affiliationOwnerID, sizeof("affiliationOwnerID")-1);
  len += zx_attr_wo_len(x->cacheDuration, sizeof("cacheDuration")-1);
  len += zx_attr_wo_len(x->id, sizeof("id")-1);
  len += zx_attr_wo_len(x->validUntil, sizeof("validUntil")-1);

#else
  /* root node has no begin tag */
  int len = 0;
#endif
  
  for (se = x->AffiliateMember; se; se = (struct zx_elem_s*)se->g.n)
    len += zx_LEN_WO_simple_elem(c, se, sizeof("AffiliateMember")-1);
  {
      struct zx_m20_Extension_s* e;
      for (e = x->Extension; e; e = (struct zx_m20_Extension_s*)e->gg.g.n)
	  len += zx_LEN_WO_m20_Extension(c, e);
  }
  {
      struct zx_m20_KeyDescriptor_s* e;
      for (e = x->KeyDescriptor; e; e = (struct zx_m20_KeyDescriptor_s*)e->gg.g.n)
	  len += zx_LEN_WO_m20_KeyDescriptor(c, e);
  }
  {
      struct zx_ds_Signature_s* e;
      for (e = x->Signature; e; e = (struct zx_ds_Signature_s*)e->gg.g.n)
	  if (e != c->exclude_sig)
              len += zx_LEN_WO_ds_Signature(c, e);
  }


  len += zx_len_wo_common(c, &x->gg); 
  zx_pop_seen(pop_seen);
  ENC_LEN_DEBUG(x, "m20:AffiliationDescriptor", len);
  return len;
}

/* FUNC(zx_ENC_SO_m20_AffiliationDescriptor) */

/* Render element into string. The XML attributes and elements are
 * processed in schema order. This is what you generally want for
 * rendering new data structure to a string. The wo pointers are not used. */

/* Called by: */
char* zx_ENC_SO_m20_AffiliationDescriptor(struct zx_ctx* c, struct zx_m20_AffiliationDescriptor_s* x, char* p )
{
  struct zx_elem_s* se MAYBE_UNUSED;
  struct zx_ns_s* pop_seen = 0;
  ENC_LEN_DEBUG_BASE;
#if 1 /* NORMALMODE */
  /* *** in simple_elem case should output ns prefix from ns node. */
  ZX_OUT_TAG(p, "<m20:AffiliationDescriptor");
  if (c->inc_ns)
    p = zx_enc_inc_ns(c, p, &pop_seen);
  p = zx_enc_xmlns_if_not_seen(c, p, zx_ns_tab+zx_xmlns_ix_m20, &pop_seen);

  p = zx_attr_so_enc(p, x->affiliationOwnerID, " affiliationOwnerID=\"", sizeof(" affiliationOwnerID=\"")-1);
  p = zx_attr_so_enc(p, x->cacheDuration, " cacheDuration=\"", sizeof(" cacheDuration=\"")-1);
  p = zx_attr_so_enc(p, x->id, " id=\"", sizeof(" id=\"")-1);
  p = zx_attr_so_enc(p, x->validUntil, " validUntil=\"", sizeof(" validUntil=\"")-1);

  p = zx_enc_unknown_attrs(p, x->gg.any_attr);
#else
  /* root node has no begin tag */
#endif
  
  for (se = x->AffiliateMember; se; se = (struct zx_elem_s*)se->g.n)
    p = zx_ENC_SO_simple_elem(c, se, p, "m20:AffiliateMember", sizeof("m20:AffiliateMember")-1, zx_ns_tab+zx_xmlns_ix_m20);
  {
      struct zx_m20_Extension_s* e;
      for (e = x->Extension; e; e = (struct zx_m20_Extension_s*)e->gg.g.n)
	  p = zx_ENC_SO_m20_Extension(c, e, p);
  }
  {
      struct zx_m20_KeyDescriptor_s* e;
      for (e = x->KeyDescriptor; e; e = (struct zx_m20_KeyDescriptor_s*)e->gg.g.n)
	  p = zx_ENC_SO_m20_KeyDescriptor(c, e, p);
  }
  {
      struct zx_ds_Signature_s* e;
      for (e = x->Signature; e; e = (struct zx_ds_Signature_s*)e->gg.g.n)
	  if (e != c->exclude_sig)
              p = zx_ENC_SO_ds_Signature(c, e, p);
  }

  p = zx_enc_so_unknown_elems_and_content(c, p, &x->gg);
  
#if 1 /* NORMALMODE */
  ZX_OUT_CLOSE_TAG(p, "</m20:AffiliationDescriptor>");
  zx_pop_seen(pop_seen);
#else
  /* root node has no end tag either */
#endif
  ENC_LEN_DEBUG(x, "m20:AffiliationDescriptor", p-enc_base);
  return p;
}

/* FUNC(zx_ENC_WO_m20_AffiliationDescriptor) */

/* Render element into string. The XML attributes and elements are
 * processed in wire order by chasing wo pointers. This is what you want for
 * validating signatures on other people's XML documents. */

/* Called by: */
char* zx_ENC_WO_m20_AffiliationDescriptor(struct zx_ctx* c, struct zx_m20_AffiliationDescriptor_s* x, char* p )
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
  ZX_OUT_MEM(p, "AffiliationDescriptor", sizeof("AffiliationDescriptor")-1);
  qq = p;

  /* *** sort the namespaces */
  if (c->inc_ns)
    zx_add_inc_ns(c, &pop_seen);
  zx_add_xmlns_if_not_seen(c, x->gg.g.ns, &pop_seen);

  p = zx_enc_seen(p, pop_seen); 
  p = zx_attr_wo_enc(p, x->affiliationOwnerID, "affiliationOwnerID=\"", sizeof("affiliationOwnerID=\"")-1);
  p = zx_attr_wo_enc(p, x->cacheDuration, "cacheDuration=\"", sizeof("cacheDuration=\"")-1);
  p = zx_attr_wo_enc(p, x->id, "id=\"", sizeof("id=\"")-1);
  p = zx_attr_wo_enc(p, x->validUntil, "validUntil=\"", sizeof("validUntil=\"")-1);

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
  ENC_LEN_DEBUG(x, "m20:AffiliationDescriptor", p-enc_base);
  return p;
}

/* FUNC(zx_EASY_ENC_SO_m20_AffiliationDescriptor) */

/* Called by: */
struct zx_str* zx_EASY_ENC_SO_m20_AffiliationDescriptor(struct zx_ctx* c, struct zx_m20_AffiliationDescriptor_s* x )
{
  int len;
  char* buf;
  c->ns_tab = ZX_ALLOC(c, sizeof(zx_ns_tab));
  memcpy(c->ns_tab, zx_ns_tab, sizeof(zx_ns_tab));
  len = zx_LEN_SO_m20_AffiliationDescriptor(c, x );
  buf = ZX_ALLOC(c, len+1);
  return zx_easy_enc_common(c, zx_ENC_SO_m20_AffiliationDescriptor(c, x, buf ), buf, len);
}

/* FUNC(zx_EASY_ENC_WO_m20_AffiliationDescriptor) */

/* Called by: */
struct zx_str* zx_EASY_ENC_WO_m20_AffiliationDescriptor(struct zx_ctx* c, struct zx_m20_AffiliationDescriptor_s* x )
{
  int len;
  char* buf;
  c->ns_tab = ZX_ALLOC(c, sizeof(zx_ns_tab));
  memcpy(c->ns_tab, zx_ns_tab, sizeof(zx_ns_tab));
  len = zx_LEN_WO_m20_AffiliationDescriptor(c, x );
  buf = ZX_ALLOC(c, len+1);
  return zx_easy_enc_common(c, zx_ENC_WO_m20_AffiliationDescriptor(c, x, buf ), buf, len);
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

#define EL_NAME   m20_AssertionConsumerServiceURL
#define EL_STRUCT zx_m20_AssertionConsumerServiceURL_s
#define EL_NS     m20
#define EL_TAG    AssertionConsumerServiceURL

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

/* FUNC(zx_LEN_SO_m20_AssertionConsumerServiceURL) */

/* Compute length of an element (and its subelements). The XML attributes
 * and elements are processed in schema order. */

/* Called by: */
int zx_LEN_SO_m20_AssertionConsumerServiceURL(struct zx_ctx* c, struct zx_m20_AssertionConsumerServiceURL_s* x )
{
  struct zx_ns_s* pop_seen = 0;
  struct zx_elem_s* se MAYBE_UNUSED;
#if 1 /* NORMALMODE */
  /* *** in simple_elem case should output ns prefix from ns node. */
  int len = sizeof("<m20:AssertionConsumerServiceURL")-1 + 1 + sizeof("</m20:AssertionConsumerServiceURL>")-1;
  if (c->inc_ns_len)
    len += zx_len_inc_ns(c, &pop_seen);
  len += zx_len_xmlns_if_not_seen(c, zx_ns_tab+zx_xmlns_ix_m20, &pop_seen);

  len += zx_attr_so_len(x->id, sizeof("id")-1);
  len += zx_attr_so_len(x->isDefault, sizeof("isDefault")-1);

#else
  /* root node has no begin tag */
  int len = 0;
#endif
  


  len += zx_len_so_common(c, &x->gg);
  zx_pop_seen(pop_seen);
  ENC_LEN_DEBUG(x, "m20:AssertionConsumerServiceURL", len);
  return len;
}

/* FUNC(zx_LEN_WO_m20_AssertionConsumerServiceURL) */

/* Compute length of an element (and its subelements). The XML attributes
 * and elements are processed in wire order and no assumptions
 * are made about namespace prefixes. */

/* Called by: */
int zx_LEN_WO_m20_AssertionConsumerServiceURL(struct zx_ctx* c, struct zx_m20_AssertionConsumerServiceURL_s* x )
{
  struct zx_ns_s* pop_seen = 0;
  struct zx_elem_s* se MAYBE_UNUSED;
#if 1 /* NORMALMODE */
  int len = 1 + sizeof("AssertionConsumerServiceURL")-1 + 1 + 2 + sizeof("AssertionConsumerServiceURL")-1 + 1;
  
  if (x->gg.g.ns && x->gg.g.ns->prefix_len)
    len += (x->gg.g.ns->prefix_len + 1) * 2;
  if (c->inc_ns_len)
    len += zx_len_inc_ns(c, &pop_seen);
  len += zx_len_xmlns_if_not_seen(c, x->gg.g.ns, &pop_seen);

  len += zx_attr_wo_len(x->id, sizeof("id")-1);
  len += zx_attr_wo_len(x->isDefault, sizeof("isDefault")-1);

#else
  /* root node has no begin tag */
  int len = 0;
#endif
  


  len += zx_len_wo_common(c, &x->gg); 
  zx_pop_seen(pop_seen);
  ENC_LEN_DEBUG(x, "m20:AssertionConsumerServiceURL", len);
  return len;
}

/* FUNC(zx_ENC_SO_m20_AssertionConsumerServiceURL) */

/* Render element into string. The XML attributes and elements are
 * processed in schema order. This is what you generally want for
 * rendering new data structure to a string. The wo pointers are not used. */

/* Called by: */
char* zx_ENC_SO_m20_AssertionConsumerServiceURL(struct zx_ctx* c, struct zx_m20_AssertionConsumerServiceURL_s* x, char* p )
{
  struct zx_elem_s* se MAYBE_UNUSED;
  struct zx_ns_s* pop_seen = 0;
  ENC_LEN_DEBUG_BASE;
#if 1 /* NORMALMODE */
  /* *** in simple_elem case should output ns prefix from ns node. */
  ZX_OUT_TAG(p, "<m20:AssertionConsumerServiceURL");
  if (c->inc_ns)
    p = zx_enc_inc_ns(c, p, &pop_seen);
  p = zx_enc_xmlns_if_not_seen(c, p, zx_ns_tab+zx_xmlns_ix_m20, &pop_seen);

  p = zx_attr_so_enc(p, x->id, " id=\"", sizeof(" id=\"")-1);
  p = zx_attr_so_enc(p, x->isDefault, " isDefault=\"", sizeof(" isDefault=\"")-1);

  p = zx_enc_unknown_attrs(p, x->gg.any_attr);
#else
  /* root node has no begin tag */
#endif
  

  p = zx_enc_so_unknown_elems_and_content(c, p, &x->gg);
  
#if 1 /* NORMALMODE */
  ZX_OUT_CLOSE_TAG(p, "</m20:AssertionConsumerServiceURL>");
  zx_pop_seen(pop_seen);
#else
  /* root node has no end tag either */
#endif
  ENC_LEN_DEBUG(x, "m20:AssertionConsumerServiceURL", p-enc_base);
  return p;
}

/* FUNC(zx_ENC_WO_m20_AssertionConsumerServiceURL) */

/* Render element into string. The XML attributes and elements are
 * processed in wire order by chasing wo pointers. This is what you want for
 * validating signatures on other people's XML documents. */

/* Called by: */
char* zx_ENC_WO_m20_AssertionConsumerServiceURL(struct zx_ctx* c, struct zx_m20_AssertionConsumerServiceURL_s* x, char* p )
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
  ZX_OUT_MEM(p, "AssertionConsumerServiceURL", sizeof("AssertionConsumerServiceURL")-1);
  qq = p;

  /* *** sort the namespaces */
  if (c->inc_ns)
    zx_add_inc_ns(c, &pop_seen);
  zx_add_xmlns_if_not_seen(c, x->gg.g.ns, &pop_seen);

  p = zx_enc_seen(p, pop_seen); 
  p = zx_attr_wo_enc(p, x->id, "id=\"", sizeof("id=\"")-1);
  p = zx_attr_wo_enc(p, x->isDefault, "isDefault=\"", sizeof("isDefault=\"")-1);

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
  ENC_LEN_DEBUG(x, "m20:AssertionConsumerServiceURL", p-enc_base);
  return p;
}

/* FUNC(zx_EASY_ENC_SO_m20_AssertionConsumerServiceURL) */

/* Called by: */
struct zx_str* zx_EASY_ENC_SO_m20_AssertionConsumerServiceURL(struct zx_ctx* c, struct zx_m20_AssertionConsumerServiceURL_s* x )
{
  int len;
  char* buf;
  c->ns_tab = ZX_ALLOC(c, sizeof(zx_ns_tab));
  memcpy(c->ns_tab, zx_ns_tab, sizeof(zx_ns_tab));
  len = zx_LEN_SO_m20_AssertionConsumerServiceURL(c, x );
  buf = ZX_ALLOC(c, len+1);
  return zx_easy_enc_common(c, zx_ENC_SO_m20_AssertionConsumerServiceURL(c, x, buf ), buf, len);
}

/* FUNC(zx_EASY_ENC_WO_m20_AssertionConsumerServiceURL) */

/* Called by: */
struct zx_str* zx_EASY_ENC_WO_m20_AssertionConsumerServiceURL(struct zx_ctx* c, struct zx_m20_AssertionConsumerServiceURL_s* x )
{
  int len;
  char* buf;
  c->ns_tab = ZX_ALLOC(c, sizeof(zx_ns_tab));
  memcpy(c->ns_tab, zx_ns_tab, sizeof(zx_ns_tab));
  len = zx_LEN_WO_m20_AssertionConsumerServiceURL(c, x );
  buf = ZX_ALLOC(c, len+1);
  return zx_easy_enc_common(c, zx_ENC_WO_m20_AssertionConsumerServiceURL(c, x, buf ), buf, len);
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

#define EL_NAME   m20_ContactPerson
#define EL_STRUCT zx_m20_ContactPerson_s
#define EL_NS     m20
#define EL_TAG    ContactPerson

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

/* FUNC(zx_LEN_SO_m20_ContactPerson) */

/* Compute length of an element (and its subelements). The XML attributes
 * and elements are processed in schema order. */

/* Called by: */
int zx_LEN_SO_m20_ContactPerson(struct zx_ctx* c, struct zx_m20_ContactPerson_s* x )
{
  struct zx_ns_s* pop_seen = 0;
  struct zx_elem_s* se MAYBE_UNUSED;
#if 1 /* NORMALMODE */
  /* *** in simple_elem case should output ns prefix from ns node. */
  int len = sizeof("<m20:ContactPerson")-1 + 1 + sizeof("</m20:ContactPerson>")-1;
  if (c->inc_ns_len)
    len += zx_len_inc_ns(c, &pop_seen);
  len += zx_len_xmlns_if_not_seen(c, zx_ns_tab+zx_xmlns_ix_m20, &pop_seen);

  len += zx_attr_so_len(x->contactType, sizeof("contactType")-1);
  len += zx_attr_so_len(x->libertyPrincipalIdentifier, sizeof("libertyPrincipalIdentifier")-1);

#else
  /* root node has no begin tag */
  int len = 0;
#endif
  
  for (se = x->Company; se; se = (struct zx_elem_s*)se->g.n)
    len += zx_LEN_SO_simple_elem(c,se, sizeof("m20:Company")-1, zx_ns_tab+zx_xmlns_ix_m20);
  for (se = x->GivenName; se; se = (struct zx_elem_s*)se->g.n)
    len += zx_LEN_SO_simple_elem(c,se, sizeof("m20:GivenName")-1, zx_ns_tab+zx_xmlns_ix_m20);
  for (se = x->SurName; se; se = (struct zx_elem_s*)se->g.n)
    len += zx_LEN_SO_simple_elem(c,se, sizeof("m20:SurName")-1, zx_ns_tab+zx_xmlns_ix_m20);
  for (se = x->EmailAddress; se; se = (struct zx_elem_s*)se->g.n)
    len += zx_LEN_SO_simple_elem(c,se, sizeof("m20:EmailAddress")-1, zx_ns_tab+zx_xmlns_ix_m20);
  for (se = x->TelephoneNumber; se; se = (struct zx_elem_s*)se->g.n)
    len += zx_LEN_SO_simple_elem(c,se, sizeof("m20:TelephoneNumber")-1, zx_ns_tab+zx_xmlns_ix_m20);
  {
      struct zx_m20_Extension_s* e;
      for (e = x->Extension; e; e = (struct zx_m20_Extension_s*)e->gg.g.n)
	  len += zx_LEN_SO_m20_Extension(c, e);
  }


  len += zx_len_so_common(c, &x->gg);
  zx_pop_seen(pop_seen);
  ENC_LEN_DEBUG(x, "m20:ContactPerson", len);
  return len;
}

/* FUNC(zx_LEN_WO_m20_ContactPerson) */

/* Compute length of an element (and its subelements). The XML attributes
 * and elements are processed in wire order and no assumptions
 * are made about namespace prefixes. */

/* Called by: */
int zx_LEN_WO_m20_ContactPerson(struct zx_ctx* c, struct zx_m20_ContactPerson_s* x )
{
  struct zx_ns_s* pop_seen = 0;
  struct zx_elem_s* se MAYBE_UNUSED;
#if 1 /* NORMALMODE */
  int len = 1 + sizeof("ContactPerson")-1 + 1 + 2 + sizeof("ContactPerson")-1 + 1;
  
  if (x->gg.g.ns && x->gg.g.ns->prefix_len)
    len += (x->gg.g.ns->prefix_len + 1) * 2;
  if (c->inc_ns_len)
    len += zx_len_inc_ns(c, &pop_seen);
  len += zx_len_xmlns_if_not_seen(c, x->gg.g.ns, &pop_seen);

  len += zx_attr_wo_len(x->contactType, sizeof("contactType")-1);
  len += zx_attr_wo_len(x->libertyPrincipalIdentifier, sizeof("libertyPrincipalIdentifier")-1);

#else
  /* root node has no begin tag */
  int len = 0;
#endif
  
  for (se = x->Company; se; se = (struct zx_elem_s*)se->g.n)
    len += zx_LEN_WO_simple_elem(c, se, sizeof("Company")-1);
  for (se = x->GivenName; se; se = (struct zx_elem_s*)se->g.n)
    len += zx_LEN_WO_simple_elem(c, se, sizeof("GivenName")-1);
  for (se = x->SurName; se; se = (struct zx_elem_s*)se->g.n)
    len += zx_LEN_WO_simple_elem(c, se, sizeof("SurName")-1);
  for (se = x->EmailAddress; se; se = (struct zx_elem_s*)se->g.n)
    len += zx_LEN_WO_simple_elem(c, se, sizeof("EmailAddress")-1);
  for (se = x->TelephoneNumber; se; se = (struct zx_elem_s*)se->g.n)
    len += zx_LEN_WO_simple_elem(c, se, sizeof("TelephoneNumber")-1);
  {
      struct zx_m20_Extension_s* e;
      for (e = x->Extension; e; e = (struct zx_m20_Extension_s*)e->gg.g.n)
	  len += zx_LEN_WO_m20_Extension(c, e);
  }


  len += zx_len_wo_common(c, &x->gg); 
  zx_pop_seen(pop_seen);
  ENC_LEN_DEBUG(x, "m20:ContactPerson", len);
  return len;
}

/* FUNC(zx_ENC_SO_m20_ContactPerson) */

/* Render element into string. The XML attributes and elements are
 * processed in schema order. This is what you generally want for
 * rendering new data structure to a string. The wo pointers are not used. */

/* Called by: */
char* zx_ENC_SO_m20_ContactPerson(struct zx_ctx* c, struct zx_m20_ContactPerson_s* x, char* p )
{
  struct zx_elem_s* se MAYBE_UNUSED;
  struct zx_ns_s* pop_seen = 0;
  ENC_LEN_DEBUG_BASE;
#if 1 /* NORMALMODE */
  /* *** in simple_elem case should output ns prefix from ns node. */
  ZX_OUT_TAG(p, "<m20:ContactPerson");
  if (c->inc_ns)
    p = zx_enc_inc_ns(c, p, &pop_seen);
  p = zx_enc_xmlns_if_not_seen(c, p, zx_ns_tab+zx_xmlns_ix_m20, &pop_seen);

  p = zx_attr_so_enc(p, x->contactType, " contactType=\"", sizeof(" contactType=\"")-1);
  p = zx_attr_so_enc(p, x->libertyPrincipalIdentifier, " libertyPrincipalIdentifier=\"", sizeof(" libertyPrincipalIdentifier=\"")-1);

  p = zx_enc_unknown_attrs(p, x->gg.any_attr);
#else
  /* root node has no begin tag */
#endif
  
  for (se = x->Company; se; se = (struct zx_elem_s*)se->g.n)
    p = zx_ENC_SO_simple_elem(c, se, p, "m20:Company", sizeof("m20:Company")-1, zx_ns_tab+zx_xmlns_ix_m20);
  for (se = x->GivenName; se; se = (struct zx_elem_s*)se->g.n)
    p = zx_ENC_SO_simple_elem(c, se, p, "m20:GivenName", sizeof("m20:GivenName")-1, zx_ns_tab+zx_xmlns_ix_m20);
  for (se = x->SurName; se; se = (struct zx_elem_s*)se->g.n)
    p = zx_ENC_SO_simple_elem(c, se, p, "m20:SurName", sizeof("m20:SurName")-1, zx_ns_tab+zx_xmlns_ix_m20);
  for (se = x->EmailAddress; se; se = (struct zx_elem_s*)se->g.n)
    p = zx_ENC_SO_simple_elem(c, se, p, "m20:EmailAddress", sizeof("m20:EmailAddress")-1, zx_ns_tab+zx_xmlns_ix_m20);
  for (se = x->TelephoneNumber; se; se = (struct zx_elem_s*)se->g.n)
    p = zx_ENC_SO_simple_elem(c, se, p, "m20:TelephoneNumber", sizeof("m20:TelephoneNumber")-1, zx_ns_tab+zx_xmlns_ix_m20);
  {
      struct zx_m20_Extension_s* e;
      for (e = x->Extension; e; e = (struct zx_m20_Extension_s*)e->gg.g.n)
	  p = zx_ENC_SO_m20_Extension(c, e, p);
  }

  p = zx_enc_so_unknown_elems_and_content(c, p, &x->gg);
  
#if 1 /* NORMALMODE */
  ZX_OUT_CLOSE_TAG(p, "</m20:ContactPerson>");
  zx_pop_seen(pop_seen);
#else
  /* root node has no end tag either */
#endif
  ENC_LEN_DEBUG(x, "m20:ContactPerson", p-enc_base);
  return p;
}

/* FUNC(zx_ENC_WO_m20_ContactPerson) */

/* Render element into string. The XML attributes and elements are
 * processed in wire order by chasing wo pointers. This is what you want for
 * validating signatures on other people's XML documents. */

/* Called by: */
char* zx_ENC_WO_m20_ContactPerson(struct zx_ctx* c, struct zx_m20_ContactPerson_s* x, char* p )
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
  ZX_OUT_MEM(p, "ContactPerson", sizeof("ContactPerson")-1);
  qq = p;

  /* *** sort the namespaces */
  if (c->inc_ns)
    zx_add_inc_ns(c, &pop_seen);
  zx_add_xmlns_if_not_seen(c, x->gg.g.ns, &pop_seen);

  p = zx_enc_seen(p, pop_seen); 
  p = zx_attr_wo_enc(p, x->contactType, "contactType=\"", sizeof("contactType=\"")-1);
  p = zx_attr_wo_enc(p, x->libertyPrincipalIdentifier, "libertyPrincipalIdentifier=\"", sizeof("libertyPrincipalIdentifier=\"")-1);

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
  ENC_LEN_DEBUG(x, "m20:ContactPerson", p-enc_base);
  return p;
}

/* FUNC(zx_EASY_ENC_SO_m20_ContactPerson) */

/* Called by: */
struct zx_str* zx_EASY_ENC_SO_m20_ContactPerson(struct zx_ctx* c, struct zx_m20_ContactPerson_s* x )
{
  int len;
  char* buf;
  c->ns_tab = ZX_ALLOC(c, sizeof(zx_ns_tab));
  memcpy(c->ns_tab, zx_ns_tab, sizeof(zx_ns_tab));
  len = zx_LEN_SO_m20_ContactPerson(c, x );
  buf = ZX_ALLOC(c, len+1);
  return zx_easy_enc_common(c, zx_ENC_SO_m20_ContactPerson(c, x, buf ), buf, len);
}

/* FUNC(zx_EASY_ENC_WO_m20_ContactPerson) */

/* Called by: */
struct zx_str* zx_EASY_ENC_WO_m20_ContactPerson(struct zx_ctx* c, struct zx_m20_ContactPerson_s* x )
{
  int len;
  char* buf;
  c->ns_tab = ZX_ALLOC(c, sizeof(zx_ns_tab));
  memcpy(c->ns_tab, zx_ns_tab, sizeof(zx_ns_tab));
  len = zx_LEN_WO_m20_ContactPerson(c, x );
  buf = ZX_ALLOC(c, len+1);
  return zx_easy_enc_common(c, zx_ENC_WO_m20_ContactPerson(c, x, buf ), buf, len);
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

#define EL_NAME   m20_EntitiesDescriptor
#define EL_STRUCT zx_m20_EntitiesDescriptor_s
#define EL_NS     m20
#define EL_TAG    EntitiesDescriptor

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

/* FUNC(zx_LEN_SO_m20_EntitiesDescriptor) */

/* Compute length of an element (and its subelements). The XML attributes
 * and elements are processed in schema order. */

/* Called by: */
int zx_LEN_SO_m20_EntitiesDescriptor(struct zx_ctx* c, struct zx_m20_EntitiesDescriptor_s* x )
{
  struct zx_ns_s* pop_seen = 0;
  struct zx_elem_s* se MAYBE_UNUSED;
#if 1 /* NORMALMODE */
  /* *** in simple_elem case should output ns prefix from ns node. */
  int len = sizeof("<m20:EntitiesDescriptor")-1 + 1 + sizeof("</m20:EntitiesDescriptor>")-1;
  if (c->inc_ns_len)
    len += zx_len_inc_ns(c, &pop_seen);
  len += zx_len_xmlns_if_not_seen(c, zx_ns_tab+zx_xmlns_ix_m20, &pop_seen);


#else
  /* root node has no begin tag */
  int len = 0;
#endif
  
  {
      struct zx_m20_EntityDescriptor_s* e;
      for (e = x->EntityDescriptor; e; e = (struct zx_m20_EntityDescriptor_s*)e->gg.g.n)
	  len += zx_LEN_SO_m20_EntityDescriptor(c, e);
  }


  len += zx_len_so_common(c, &x->gg);
  zx_pop_seen(pop_seen);
  ENC_LEN_DEBUG(x, "m20:EntitiesDescriptor", len);
  return len;
}

/* FUNC(zx_LEN_WO_m20_EntitiesDescriptor) */

/* Compute length of an element (and its subelements). The XML attributes
 * and elements are processed in wire order and no assumptions
 * are made about namespace prefixes. */

/* Called by: */
int zx_LEN_WO_m20_EntitiesDescriptor(struct zx_ctx* c, struct zx_m20_EntitiesDescriptor_s* x )
{
  struct zx_ns_s* pop_seen = 0;
  struct zx_elem_s* se MAYBE_UNUSED;
#if 1 /* NORMALMODE */
  int len = 1 + sizeof("EntitiesDescriptor")-1 + 1 + 2 + sizeof("EntitiesDescriptor")-1 + 1;
  
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
      struct zx_m20_EntityDescriptor_s* e;
      for (e = x->EntityDescriptor; e; e = (struct zx_m20_EntityDescriptor_s*)e->gg.g.n)
	  len += zx_LEN_WO_m20_EntityDescriptor(c, e);
  }


  len += zx_len_wo_common(c, &x->gg); 
  zx_pop_seen(pop_seen);
  ENC_LEN_DEBUG(x, "m20:EntitiesDescriptor", len);
  return len;
}

/* FUNC(zx_ENC_SO_m20_EntitiesDescriptor) */

/* Render element into string. The XML attributes and elements are
 * processed in schema order. This is what you generally want for
 * rendering new data structure to a string. The wo pointers are not used. */

/* Called by: */
char* zx_ENC_SO_m20_EntitiesDescriptor(struct zx_ctx* c, struct zx_m20_EntitiesDescriptor_s* x, char* p )
{
  struct zx_elem_s* se MAYBE_UNUSED;
  struct zx_ns_s* pop_seen = 0;
  ENC_LEN_DEBUG_BASE;
#if 1 /* NORMALMODE */
  /* *** in simple_elem case should output ns prefix from ns node. */
  ZX_OUT_TAG(p, "<m20:EntitiesDescriptor");
  if (c->inc_ns)
    p = zx_enc_inc_ns(c, p, &pop_seen);
  p = zx_enc_xmlns_if_not_seen(c, p, zx_ns_tab+zx_xmlns_ix_m20, &pop_seen);


  p = zx_enc_unknown_attrs(p, x->gg.any_attr);
#else
  /* root node has no begin tag */
#endif
  
  {
      struct zx_m20_EntityDescriptor_s* e;
      for (e = x->EntityDescriptor; e; e = (struct zx_m20_EntityDescriptor_s*)e->gg.g.n)
	  p = zx_ENC_SO_m20_EntityDescriptor(c, e, p);
  }

  p = zx_enc_so_unknown_elems_and_content(c, p, &x->gg);
  
#if 1 /* NORMALMODE */
  ZX_OUT_CLOSE_TAG(p, "</m20:EntitiesDescriptor>");
  zx_pop_seen(pop_seen);
#else
  /* root node has no end tag either */
#endif
  ENC_LEN_DEBUG(x, "m20:EntitiesDescriptor", p-enc_base);
  return p;
}

/* FUNC(zx_ENC_WO_m20_EntitiesDescriptor) */

/* Render element into string. The XML attributes and elements are
 * processed in wire order by chasing wo pointers. This is what you want for
 * validating signatures on other people's XML documents. */

/* Called by: */
char* zx_ENC_WO_m20_EntitiesDescriptor(struct zx_ctx* c, struct zx_m20_EntitiesDescriptor_s* x, char* p )
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
  ZX_OUT_MEM(p, "EntitiesDescriptor", sizeof("EntitiesDescriptor")-1);
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
  ENC_LEN_DEBUG(x, "m20:EntitiesDescriptor", p-enc_base);
  return p;
}

/* FUNC(zx_EASY_ENC_SO_m20_EntitiesDescriptor) */

/* Called by: */
struct zx_str* zx_EASY_ENC_SO_m20_EntitiesDescriptor(struct zx_ctx* c, struct zx_m20_EntitiesDescriptor_s* x )
{
  int len;
  char* buf;
  c->ns_tab = ZX_ALLOC(c, sizeof(zx_ns_tab));
  memcpy(c->ns_tab, zx_ns_tab, sizeof(zx_ns_tab));
  len = zx_LEN_SO_m20_EntitiesDescriptor(c, x );
  buf = ZX_ALLOC(c, len+1);
  return zx_easy_enc_common(c, zx_ENC_SO_m20_EntitiesDescriptor(c, x, buf ), buf, len);
}

/* FUNC(zx_EASY_ENC_WO_m20_EntitiesDescriptor) */

/* Called by: */
struct zx_str* zx_EASY_ENC_WO_m20_EntitiesDescriptor(struct zx_ctx* c, struct zx_m20_EntitiesDescriptor_s* x )
{
  int len;
  char* buf;
  c->ns_tab = ZX_ALLOC(c, sizeof(zx_ns_tab));
  memcpy(c->ns_tab, zx_ns_tab, sizeof(zx_ns_tab));
  len = zx_LEN_WO_m20_EntitiesDescriptor(c, x );
  buf = ZX_ALLOC(c, len+1);
  return zx_easy_enc_common(c, zx_ENC_WO_m20_EntitiesDescriptor(c, x, buf ), buf, len);
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

#define EL_NAME   m20_EntityDescriptor
#define EL_STRUCT zx_m20_EntityDescriptor_s
#define EL_NS     m20
#define EL_TAG    EntityDescriptor

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

/* FUNC(zx_LEN_SO_m20_EntityDescriptor) */

/* Compute length of an element (and its subelements). The XML attributes
 * and elements are processed in schema order. */

/* Called by: */
int zx_LEN_SO_m20_EntityDescriptor(struct zx_ctx* c, struct zx_m20_EntityDescriptor_s* x )
{
  struct zx_ns_s* pop_seen = 0;
  struct zx_elem_s* se MAYBE_UNUSED;
#if 1 /* NORMALMODE */
  /* *** in simple_elem case should output ns prefix from ns node. */
  int len = sizeof("<m20:EntityDescriptor")-1 + 1 + sizeof("</m20:EntityDescriptor>")-1;
  if (c->inc_ns_len)
    len += zx_len_inc_ns(c, &pop_seen);
  len += zx_len_xmlns_if_not_seen(c, zx_ns_tab+zx_xmlns_ix_m20, &pop_seen);

  len += zx_attr_so_len(x->cacheDuration, sizeof("cacheDuration")-1);
  len += zx_attr_so_len(x->id, sizeof("id")-1);
  len += zx_attr_so_len(x->providerID, sizeof("providerID")-1);
  len += zx_attr_so_len(x->validUntil, sizeof("validUntil")-1);

#else
  /* root node has no begin tag */
  int len = 0;
#endif
  
  {
      struct zx_m20_IDPDescriptor_s* e;
      for (e = x->IDPDescriptor; e; e = (struct zx_m20_IDPDescriptor_s*)e->gg.g.n)
	  len += zx_LEN_SO_m20_IDPDescriptor(c, e);
  }
  {
      struct zx_m20_SPDescriptor_s* e;
      for (e = x->SPDescriptor; e; e = (struct zx_m20_SPDescriptor_s*)e->gg.g.n)
	  len += zx_LEN_SO_m20_SPDescriptor(c, e);
  }
  {
      struct zx_m20_AffiliationDescriptor_s* e;
      for (e = x->AffiliationDescriptor; e; e = (struct zx_m20_AffiliationDescriptor_s*)e->gg.g.n)
	  len += zx_LEN_SO_m20_AffiliationDescriptor(c, e);
  }
  {
      struct zx_m20_ContactPerson_s* e;
      for (e = x->ContactPerson; e; e = (struct zx_m20_ContactPerson_s*)e->gg.g.n)
	  len += zx_LEN_SO_m20_ContactPerson(c, e);
  }
  {
      struct zx_m20_Organization_s* e;
      for (e = x->Organization; e; e = (struct zx_m20_Organization_s*)e->gg.g.n)
	  len += zx_LEN_SO_m20_Organization(c, e);
  }
  {
      struct zx_m20_Extension_s* e;
      for (e = x->Extension; e; e = (struct zx_m20_Extension_s*)e->gg.g.n)
	  len += zx_LEN_SO_m20_Extension(c, e);
  }
  {
      struct zx_ds_Signature_s* e;
      for (e = x->Signature; e; e = (struct zx_ds_Signature_s*)e->gg.g.n)
	  if (e != c->exclude_sig)
              len += zx_LEN_SO_ds_Signature(c, e);
  }


  len += zx_len_so_common(c, &x->gg);
  zx_pop_seen(pop_seen);
  ENC_LEN_DEBUG(x, "m20:EntityDescriptor", len);
  return len;
}

/* FUNC(zx_LEN_WO_m20_EntityDescriptor) */

/* Compute length of an element (and its subelements). The XML attributes
 * and elements are processed in wire order and no assumptions
 * are made about namespace prefixes. */

/* Called by: */
int zx_LEN_WO_m20_EntityDescriptor(struct zx_ctx* c, struct zx_m20_EntityDescriptor_s* x )
{
  struct zx_ns_s* pop_seen = 0;
  struct zx_elem_s* se MAYBE_UNUSED;
#if 1 /* NORMALMODE */
  int len = 1 + sizeof("EntityDescriptor")-1 + 1 + 2 + sizeof("EntityDescriptor")-1 + 1;
  
  if (x->gg.g.ns && x->gg.g.ns->prefix_len)
    len += (x->gg.g.ns->prefix_len + 1) * 2;
  if (c->inc_ns_len)
    len += zx_len_inc_ns(c, &pop_seen);
  len += zx_len_xmlns_if_not_seen(c, x->gg.g.ns, &pop_seen);

  len += zx_attr_wo_len(x->cacheDuration, sizeof("cacheDuration")-1);
  len += zx_attr_wo_len(x->id, sizeof("id")-1);
  len += zx_attr_wo_len(x->providerID, sizeof("providerID")-1);
  len += zx_attr_wo_len(x->validUntil, sizeof("validUntil")-1);

#else
  /* root node has no begin tag */
  int len = 0;
#endif
  
  {
      struct zx_m20_IDPDescriptor_s* e;
      for (e = x->IDPDescriptor; e; e = (struct zx_m20_IDPDescriptor_s*)e->gg.g.n)
	  len += zx_LEN_WO_m20_IDPDescriptor(c, e);
  }
  {
      struct zx_m20_SPDescriptor_s* e;
      for (e = x->SPDescriptor; e; e = (struct zx_m20_SPDescriptor_s*)e->gg.g.n)
	  len += zx_LEN_WO_m20_SPDescriptor(c, e);
  }
  {
      struct zx_m20_AffiliationDescriptor_s* e;
      for (e = x->AffiliationDescriptor; e; e = (struct zx_m20_AffiliationDescriptor_s*)e->gg.g.n)
	  len += zx_LEN_WO_m20_AffiliationDescriptor(c, e);
  }
  {
      struct zx_m20_ContactPerson_s* e;
      for (e = x->ContactPerson; e; e = (struct zx_m20_ContactPerson_s*)e->gg.g.n)
	  len += zx_LEN_WO_m20_ContactPerson(c, e);
  }
  {
      struct zx_m20_Organization_s* e;
      for (e = x->Organization; e; e = (struct zx_m20_Organization_s*)e->gg.g.n)
	  len += zx_LEN_WO_m20_Organization(c, e);
  }
  {
      struct zx_m20_Extension_s* e;
      for (e = x->Extension; e; e = (struct zx_m20_Extension_s*)e->gg.g.n)
	  len += zx_LEN_WO_m20_Extension(c, e);
  }
  {
      struct zx_ds_Signature_s* e;
      for (e = x->Signature; e; e = (struct zx_ds_Signature_s*)e->gg.g.n)
	  if (e != c->exclude_sig)
              len += zx_LEN_WO_ds_Signature(c, e);
  }


  len += zx_len_wo_common(c, &x->gg); 
  zx_pop_seen(pop_seen);
  ENC_LEN_DEBUG(x, "m20:EntityDescriptor", len);
  return len;
}

/* FUNC(zx_ENC_SO_m20_EntityDescriptor) */

/* Render element into string. The XML attributes and elements are
 * processed in schema order. This is what you generally want for
 * rendering new data structure to a string. The wo pointers are not used. */

/* Called by: */
char* zx_ENC_SO_m20_EntityDescriptor(struct zx_ctx* c, struct zx_m20_EntityDescriptor_s* x, char* p )
{
  struct zx_elem_s* se MAYBE_UNUSED;
  struct zx_ns_s* pop_seen = 0;
  ENC_LEN_DEBUG_BASE;
#if 1 /* NORMALMODE */
  /* *** in simple_elem case should output ns prefix from ns node. */
  ZX_OUT_TAG(p, "<m20:EntityDescriptor");
  if (c->inc_ns)
    p = zx_enc_inc_ns(c, p, &pop_seen);
  p = zx_enc_xmlns_if_not_seen(c, p, zx_ns_tab+zx_xmlns_ix_m20, &pop_seen);

  p = zx_attr_so_enc(p, x->cacheDuration, " cacheDuration=\"", sizeof(" cacheDuration=\"")-1);
  p = zx_attr_so_enc(p, x->id, " id=\"", sizeof(" id=\"")-1);
  p = zx_attr_so_enc(p, x->providerID, " providerID=\"", sizeof(" providerID=\"")-1);
  p = zx_attr_so_enc(p, x->validUntil, " validUntil=\"", sizeof(" validUntil=\"")-1);

  p = zx_enc_unknown_attrs(p, x->gg.any_attr);
#else
  /* root node has no begin tag */
#endif
  
  {
      struct zx_m20_IDPDescriptor_s* e;
      for (e = x->IDPDescriptor; e; e = (struct zx_m20_IDPDescriptor_s*)e->gg.g.n)
	  p = zx_ENC_SO_m20_IDPDescriptor(c, e, p);
  }
  {
      struct zx_m20_SPDescriptor_s* e;
      for (e = x->SPDescriptor; e; e = (struct zx_m20_SPDescriptor_s*)e->gg.g.n)
	  p = zx_ENC_SO_m20_SPDescriptor(c, e, p);
  }
  {
      struct zx_m20_AffiliationDescriptor_s* e;
      for (e = x->AffiliationDescriptor; e; e = (struct zx_m20_AffiliationDescriptor_s*)e->gg.g.n)
	  p = zx_ENC_SO_m20_AffiliationDescriptor(c, e, p);
  }
  {
      struct zx_m20_ContactPerson_s* e;
      for (e = x->ContactPerson; e; e = (struct zx_m20_ContactPerson_s*)e->gg.g.n)
	  p = zx_ENC_SO_m20_ContactPerson(c, e, p);
  }
  {
      struct zx_m20_Organization_s* e;
      for (e = x->Organization; e; e = (struct zx_m20_Organization_s*)e->gg.g.n)
	  p = zx_ENC_SO_m20_Organization(c, e, p);
  }
  {
      struct zx_m20_Extension_s* e;
      for (e = x->Extension; e; e = (struct zx_m20_Extension_s*)e->gg.g.n)
	  p = zx_ENC_SO_m20_Extension(c, e, p);
  }
  {
      struct zx_ds_Signature_s* e;
      for (e = x->Signature; e; e = (struct zx_ds_Signature_s*)e->gg.g.n)
	  if (e != c->exclude_sig)
              p = zx_ENC_SO_ds_Signature(c, e, p);
  }

  p = zx_enc_so_unknown_elems_and_content(c, p, &x->gg);
  
#if 1 /* NORMALMODE */
  ZX_OUT_CLOSE_TAG(p, "</m20:EntityDescriptor>");
  zx_pop_seen(pop_seen);
#else
  /* root node has no end tag either */
#endif
  ENC_LEN_DEBUG(x, "m20:EntityDescriptor", p-enc_base);
  return p;
}

/* FUNC(zx_ENC_WO_m20_EntityDescriptor) */

/* Render element into string. The XML attributes and elements are
 * processed in wire order by chasing wo pointers. This is what you want for
 * validating signatures on other people's XML documents. */

/* Called by: */
char* zx_ENC_WO_m20_EntityDescriptor(struct zx_ctx* c, struct zx_m20_EntityDescriptor_s* x, char* p )
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
  ZX_OUT_MEM(p, "EntityDescriptor", sizeof("EntityDescriptor")-1);
  qq = p;

  /* *** sort the namespaces */
  if (c->inc_ns)
    zx_add_inc_ns(c, &pop_seen);
  zx_add_xmlns_if_not_seen(c, x->gg.g.ns, &pop_seen);

  p = zx_enc_seen(p, pop_seen); 
  p = zx_attr_wo_enc(p, x->cacheDuration, "cacheDuration=\"", sizeof("cacheDuration=\"")-1);
  p = zx_attr_wo_enc(p, x->id, "id=\"", sizeof("id=\"")-1);
  p = zx_attr_wo_enc(p, x->providerID, "providerID=\"", sizeof("providerID=\"")-1);
  p = zx_attr_wo_enc(p, x->validUntil, "validUntil=\"", sizeof("validUntil=\"")-1);

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
  ENC_LEN_DEBUG(x, "m20:EntityDescriptor", p-enc_base);
  return p;
}

/* FUNC(zx_EASY_ENC_SO_m20_EntityDescriptor) */

/* Called by: */
struct zx_str* zx_EASY_ENC_SO_m20_EntityDescriptor(struct zx_ctx* c, struct zx_m20_EntityDescriptor_s* x )
{
  int len;
  char* buf;
  c->ns_tab = ZX_ALLOC(c, sizeof(zx_ns_tab));
  memcpy(c->ns_tab, zx_ns_tab, sizeof(zx_ns_tab));
  len = zx_LEN_SO_m20_EntityDescriptor(c, x );
  buf = ZX_ALLOC(c, len+1);
  return zx_easy_enc_common(c, zx_ENC_SO_m20_EntityDescriptor(c, x, buf ), buf, len);
}

/* FUNC(zx_EASY_ENC_WO_m20_EntityDescriptor) */

/* Called by: */
struct zx_str* zx_EASY_ENC_WO_m20_EntityDescriptor(struct zx_ctx* c, struct zx_m20_EntityDescriptor_s* x )
{
  int len;
  char* buf;
  c->ns_tab = ZX_ALLOC(c, sizeof(zx_ns_tab));
  memcpy(c->ns_tab, zx_ns_tab, sizeof(zx_ns_tab));
  len = zx_LEN_WO_m20_EntityDescriptor(c, x );
  buf = ZX_ALLOC(c, len+1);
  return zx_easy_enc_common(c, zx_ENC_WO_m20_EntityDescriptor(c, x, buf ), buf, len);
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

#define EL_NAME   m20_Extension
#define EL_STRUCT zx_m20_Extension_s
#define EL_NS     m20
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

/* FUNC(zx_LEN_SO_m20_Extension) */

/* Compute length of an element (and its subelements). The XML attributes
 * and elements are processed in schema order. */

/* Called by: */
int zx_LEN_SO_m20_Extension(struct zx_ctx* c, struct zx_m20_Extension_s* x )
{
  struct zx_ns_s* pop_seen = 0;
  struct zx_elem_s* se MAYBE_UNUSED;
#if 1 /* NORMALMODE */
  /* *** in simple_elem case should output ns prefix from ns node. */
  int len = sizeof("<m20:Extension")-1 + 1 + sizeof("</m20:Extension>")-1;
  if (c->inc_ns_len)
    len += zx_len_inc_ns(c, &pop_seen);
  len += zx_len_xmlns_if_not_seen(c, zx_ns_tab+zx_xmlns_ix_m20, &pop_seen);


#else
  /* root node has no begin tag */
  int len = 0;
#endif
  


  len += zx_len_so_common(c, &x->gg);
  zx_pop_seen(pop_seen);
  ENC_LEN_DEBUG(x, "m20:Extension", len);
  return len;
}

/* FUNC(zx_LEN_WO_m20_Extension) */

/* Compute length of an element (and its subelements). The XML attributes
 * and elements are processed in wire order and no assumptions
 * are made about namespace prefixes. */

/* Called by: */
int zx_LEN_WO_m20_Extension(struct zx_ctx* c, struct zx_m20_Extension_s* x )
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
  


  len += zx_len_wo_common(c, &x->gg); 
  zx_pop_seen(pop_seen);
  ENC_LEN_DEBUG(x, "m20:Extension", len);
  return len;
}

/* FUNC(zx_ENC_SO_m20_Extension) */

/* Render element into string. The XML attributes and elements are
 * processed in schema order. This is what you generally want for
 * rendering new data structure to a string. The wo pointers are not used. */

/* Called by: */
char* zx_ENC_SO_m20_Extension(struct zx_ctx* c, struct zx_m20_Extension_s* x, char* p )
{
  struct zx_elem_s* se MAYBE_UNUSED;
  struct zx_ns_s* pop_seen = 0;
  ENC_LEN_DEBUG_BASE;
#if 1 /* NORMALMODE */
  /* *** in simple_elem case should output ns prefix from ns node. */
  ZX_OUT_TAG(p, "<m20:Extension");
  if (c->inc_ns)
    p = zx_enc_inc_ns(c, p, &pop_seen);
  p = zx_enc_xmlns_if_not_seen(c, p, zx_ns_tab+zx_xmlns_ix_m20, &pop_seen);


  p = zx_enc_unknown_attrs(p, x->gg.any_attr);
#else
  /* root node has no begin tag */
#endif
  

  p = zx_enc_so_unknown_elems_and_content(c, p, &x->gg);
  
#if 1 /* NORMALMODE */
  ZX_OUT_CLOSE_TAG(p, "</m20:Extension>");
  zx_pop_seen(pop_seen);
#else
  /* root node has no end tag either */
#endif
  ENC_LEN_DEBUG(x, "m20:Extension", p-enc_base);
  return p;
}

/* FUNC(zx_ENC_WO_m20_Extension) */

/* Render element into string. The XML attributes and elements are
 * processed in wire order by chasing wo pointers. This is what you want for
 * validating signatures on other people's XML documents. */

/* Called by: */
char* zx_ENC_WO_m20_Extension(struct zx_ctx* c, struct zx_m20_Extension_s* x, char* p )
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
  ENC_LEN_DEBUG(x, "m20:Extension", p-enc_base);
  return p;
}

/* FUNC(zx_EASY_ENC_SO_m20_Extension) */

/* Called by: */
struct zx_str* zx_EASY_ENC_SO_m20_Extension(struct zx_ctx* c, struct zx_m20_Extension_s* x )
{
  int len;
  char* buf;
  c->ns_tab = ZX_ALLOC(c, sizeof(zx_ns_tab));
  memcpy(c->ns_tab, zx_ns_tab, sizeof(zx_ns_tab));
  len = zx_LEN_SO_m20_Extension(c, x );
  buf = ZX_ALLOC(c, len+1);
  return zx_easy_enc_common(c, zx_ENC_SO_m20_Extension(c, x, buf ), buf, len);
}

/* FUNC(zx_EASY_ENC_WO_m20_Extension) */

/* Called by: */
struct zx_str* zx_EASY_ENC_WO_m20_Extension(struct zx_ctx* c, struct zx_m20_Extension_s* x )
{
  int len;
  char* buf;
  c->ns_tab = ZX_ALLOC(c, sizeof(zx_ns_tab));
  memcpy(c->ns_tab, zx_ns_tab, sizeof(zx_ns_tab));
  len = zx_LEN_WO_m20_Extension(c, x );
  buf = ZX_ALLOC(c, len+1);
  return zx_easy_enc_common(c, zx_ENC_WO_m20_Extension(c, x, buf ), buf, len);
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

#define EL_NAME   m20_IDPDescriptor
#define EL_STRUCT zx_m20_IDPDescriptor_s
#define EL_NS     m20
#define EL_TAG    IDPDescriptor

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

/* FUNC(zx_LEN_SO_m20_IDPDescriptor) */

/* Compute length of an element (and its subelements). The XML attributes
 * and elements are processed in schema order. */

/* Called by: */
int zx_LEN_SO_m20_IDPDescriptor(struct zx_ctx* c, struct zx_m20_IDPDescriptor_s* x )
{
  struct zx_ns_s* pop_seen = 0;
  struct zx_elem_s* se MAYBE_UNUSED;
#if 1 /* NORMALMODE */
  /* *** in simple_elem case should output ns prefix from ns node. */
  int len = sizeof("<m20:IDPDescriptor")-1 + 1 + sizeof("</m20:IDPDescriptor>")-1;
  if (c->inc_ns_len)
    len += zx_len_inc_ns(c, &pop_seen);
  len += zx_len_xmlns_if_not_seen(c, zx_ns_tab+zx_xmlns_ix_m20, &pop_seen);

  len += zx_attr_so_len(x->cacheDuration, sizeof("cacheDuration")-1);
  len += zx_attr_so_len(x->id, sizeof("id")-1);
  len += zx_attr_so_len(x->protocolSupportEnumeration, sizeof("protocolSupportEnumeration")-1);
  len += zx_attr_so_len(x->validUntil, sizeof("validUntil")-1);

#else
  /* root node has no begin tag */
  int len = 0;
#endif
  
  {
      struct zx_m20_KeyDescriptor_s* e;
      for (e = x->KeyDescriptor; e; e = (struct zx_m20_KeyDescriptor_s*)e->gg.g.n)
	  len += zx_LEN_SO_m20_KeyDescriptor(c, e);
  }
  for (se = x->SoapEndpoint; se; se = (struct zx_elem_s*)se->g.n)
    len += zx_LEN_SO_simple_elem(c,se, sizeof("m20:SoapEndpoint")-1, zx_ns_tab+zx_xmlns_ix_m20);
  for (se = x->SingleLogoutServiceURL; se; se = (struct zx_elem_s*)se->g.n)
    len += zx_LEN_SO_simple_elem(c,se, sizeof("m20:SingleLogoutServiceURL")-1, zx_ns_tab+zx_xmlns_ix_m20);
  for (se = x->SingleLogoutServiceReturnURL; se; se = (struct zx_elem_s*)se->g.n)
    len += zx_LEN_SO_simple_elem(c,se, sizeof("m20:SingleLogoutServiceReturnURL")-1, zx_ns_tab+zx_xmlns_ix_m20);
  for (se = x->FederationTerminationServiceURL; se; se = (struct zx_elem_s*)se->g.n)
    len += zx_LEN_SO_simple_elem(c,se, sizeof("m20:FederationTerminationServiceURL")-1, zx_ns_tab+zx_xmlns_ix_m20);
  for (se = x->FederationTerminationServiceReturnURL; se; se = (struct zx_elem_s*)se->g.n)
    len += zx_LEN_SO_simple_elem(c,se, sizeof("m20:FederationTerminationServiceReturnURL")-1, zx_ns_tab+zx_xmlns_ix_m20);
  for (se = x->FederationTerminationNotificationProtocolProfile; se; se = (struct zx_elem_s*)se->g.n)
    len += zx_LEN_SO_simple_elem(c,se, sizeof("m20:FederationTerminationNotificationProtocolProfile")-1, zx_ns_tab+zx_xmlns_ix_m20);
  for (se = x->SingleLogoutProtocolProfile; se; se = (struct zx_elem_s*)se->g.n)
    len += zx_LEN_SO_simple_elem(c,se, sizeof("m20:SingleLogoutProtocolProfile")-1, zx_ns_tab+zx_xmlns_ix_m20);
  for (se = x->RegisterNameIdentifierProtocolProfile; se; se = (struct zx_elem_s*)se->g.n)
    len += zx_LEN_SO_simple_elem(c,se, sizeof("m20:RegisterNameIdentifierProtocolProfile")-1, zx_ns_tab+zx_xmlns_ix_m20);
  for (se = x->RegisterNameIdentifierServiceURL; se; se = (struct zx_elem_s*)se->g.n)
    len += zx_LEN_SO_simple_elem(c,se, sizeof("m20:RegisterNameIdentifierServiceURL")-1, zx_ns_tab+zx_xmlns_ix_m20);
  for (se = x->RegisterNameIdentifierServiceReturnURL; se; se = (struct zx_elem_s*)se->g.n)
    len += zx_LEN_SO_simple_elem(c,se, sizeof("m20:RegisterNameIdentifierServiceReturnURL")-1, zx_ns_tab+zx_xmlns_ix_m20);
  for (se = x->NameIdentifierMappingProtocolProfile; se; se = (struct zx_elem_s*)se->g.n)
    len += zx_LEN_SO_simple_elem(c,se, sizeof("m20:NameIdentifierMappingProtocolProfile")-1, zx_ns_tab+zx_xmlns_ix_m20);
  for (se = x->NameIdentifierMappingEncryptionProfile; se; se = (struct zx_elem_s*)se->g.n)
    len += zx_LEN_SO_simple_elem(c,se, sizeof("m20:NameIdentifierMappingEncryptionProfile")-1, zx_ns_tab+zx_xmlns_ix_m20);
  {
      struct zx_m20_Organization_s* e;
      for (e = x->Organization; e; e = (struct zx_m20_Organization_s*)e->gg.g.n)
	  len += zx_LEN_SO_m20_Organization(c, e);
  }
  {
      struct zx_m20_ContactPerson_s* e;
      for (e = x->ContactPerson; e; e = (struct zx_m20_ContactPerson_s*)e->gg.g.n)
	  len += zx_LEN_SO_m20_ContactPerson(c, e);
  }
  {
      struct zx_m20_AdditionalMetaLocation_s* e;
      for (e = x->AdditionalMetaLocation; e; e = (struct zx_m20_AdditionalMetaLocation_s*)e->gg.g.n)
	  len += zx_LEN_SO_m20_AdditionalMetaLocation(c, e);
  }
  {
      struct zx_m20_Extension_s* e;
      for (e = x->Extension; e; e = (struct zx_m20_Extension_s*)e->gg.g.n)
	  len += zx_LEN_SO_m20_Extension(c, e);
  }
  {
      struct zx_ds_Signature_s* e;
      for (e = x->Signature; e; e = (struct zx_ds_Signature_s*)e->gg.g.n)
	  if (e != c->exclude_sig)
              len += zx_LEN_SO_ds_Signature(c, e);
  }
  for (se = x->SingleSignOnServiceURL; se; se = (struct zx_elem_s*)se->g.n)
    len += zx_LEN_SO_simple_elem(c,se, sizeof("m20:SingleSignOnServiceURL")-1, zx_ns_tab+zx_xmlns_ix_m20);
  for (se = x->SingleSignOnProtocolProfile; se; se = (struct zx_elem_s*)se->g.n)
    len += zx_LEN_SO_simple_elem(c,se, sizeof("m20:SingleSignOnProtocolProfile")-1, zx_ns_tab+zx_xmlns_ix_m20);
  for (se = x->AuthnServiceURL; se; se = (struct zx_elem_s*)se->g.n)
    len += zx_LEN_SO_simple_elem(c,se, sizeof("m20:AuthnServiceURL")-1, zx_ns_tab+zx_xmlns_ix_m20);


  len += zx_len_so_common(c, &x->gg);
  zx_pop_seen(pop_seen);
  ENC_LEN_DEBUG(x, "m20:IDPDescriptor", len);
  return len;
}

/* FUNC(zx_LEN_WO_m20_IDPDescriptor) */

/* Compute length of an element (and its subelements). The XML attributes
 * and elements are processed in wire order and no assumptions
 * are made about namespace prefixes. */

/* Called by: */
int zx_LEN_WO_m20_IDPDescriptor(struct zx_ctx* c, struct zx_m20_IDPDescriptor_s* x )
{
  struct zx_ns_s* pop_seen = 0;
  struct zx_elem_s* se MAYBE_UNUSED;
#if 1 /* NORMALMODE */
  int len = 1 + sizeof("IDPDescriptor")-1 + 1 + 2 + sizeof("IDPDescriptor")-1 + 1;
  
  if (x->gg.g.ns && x->gg.g.ns->prefix_len)
    len += (x->gg.g.ns->prefix_len + 1) * 2;
  if (c->inc_ns_len)
    len += zx_len_inc_ns(c, &pop_seen);
  len += zx_len_xmlns_if_not_seen(c, x->gg.g.ns, &pop_seen);

  len += zx_attr_wo_len(x->cacheDuration, sizeof("cacheDuration")-1);
  len += zx_attr_wo_len(x->id, sizeof("id")-1);
  len += zx_attr_wo_len(x->protocolSupportEnumeration, sizeof("protocolSupportEnumeration")-1);
  len += zx_attr_wo_len(x->validUntil, sizeof("validUntil")-1);

#else
  /* root node has no begin tag */
  int len = 0;
#endif
  
  {
      struct zx_m20_KeyDescriptor_s* e;
      for (e = x->KeyDescriptor; e; e = (struct zx_m20_KeyDescriptor_s*)e->gg.g.n)
	  len += zx_LEN_WO_m20_KeyDescriptor(c, e);
  }
  for (se = x->SoapEndpoint; se; se = (struct zx_elem_s*)se->g.n)
    len += zx_LEN_WO_simple_elem(c, se, sizeof("SoapEndpoint")-1);
  for (se = x->SingleLogoutServiceURL; se; se = (struct zx_elem_s*)se->g.n)
    len += zx_LEN_WO_simple_elem(c, se, sizeof("SingleLogoutServiceURL")-1);
  for (se = x->SingleLogoutServiceReturnURL; se; se = (struct zx_elem_s*)se->g.n)
    len += zx_LEN_WO_simple_elem(c, se, sizeof("SingleLogoutServiceReturnURL")-1);
  for (se = x->FederationTerminationServiceURL; se; se = (struct zx_elem_s*)se->g.n)
    len += zx_LEN_WO_simple_elem(c, se, sizeof("FederationTerminationServiceURL")-1);
  for (se = x->FederationTerminationServiceReturnURL; se; se = (struct zx_elem_s*)se->g.n)
    len += zx_LEN_WO_simple_elem(c, se, sizeof("FederationTerminationServiceReturnURL")-1);
  for (se = x->FederationTerminationNotificationProtocolProfile; se; se = (struct zx_elem_s*)se->g.n)
    len += zx_LEN_WO_simple_elem(c, se, sizeof("FederationTerminationNotificationProtocolProfile")-1);
  for (se = x->SingleLogoutProtocolProfile; se; se = (struct zx_elem_s*)se->g.n)
    len += zx_LEN_WO_simple_elem(c, se, sizeof("SingleLogoutProtocolProfile")-1);
  for (se = x->RegisterNameIdentifierProtocolProfile; se; se = (struct zx_elem_s*)se->g.n)
    len += zx_LEN_WO_simple_elem(c, se, sizeof("RegisterNameIdentifierProtocolProfile")-1);
  for (se = x->RegisterNameIdentifierServiceURL; se; se = (struct zx_elem_s*)se->g.n)
    len += zx_LEN_WO_simple_elem(c, se, sizeof("RegisterNameIdentifierServiceURL")-1);
  for (se = x->RegisterNameIdentifierServiceReturnURL; se; se = (struct zx_elem_s*)se->g.n)
    len += zx_LEN_WO_simple_elem(c, se, sizeof("RegisterNameIdentifierServiceReturnURL")-1);
  for (se = x->NameIdentifierMappingProtocolProfile; se; se = (struct zx_elem_s*)se->g.n)
    len += zx_LEN_WO_simple_elem(c, se, sizeof("NameIdentifierMappingProtocolProfile")-1);
  for (se = x->NameIdentifierMappingEncryptionProfile; se; se = (struct zx_elem_s*)se->g.n)
    len += zx_LEN_WO_simple_elem(c, se, sizeof("NameIdentifierMappingEncryptionProfile")-1);
  {
      struct zx_m20_Organization_s* e;
      for (e = x->Organization; e; e = (struct zx_m20_Organization_s*)e->gg.g.n)
	  len += zx_LEN_WO_m20_Organization(c, e);
  }
  {
      struct zx_m20_ContactPerson_s* e;
      for (e = x->ContactPerson; e; e = (struct zx_m20_ContactPerson_s*)e->gg.g.n)
	  len += zx_LEN_WO_m20_ContactPerson(c, e);
  }
  {
      struct zx_m20_AdditionalMetaLocation_s* e;
      for (e = x->AdditionalMetaLocation; e; e = (struct zx_m20_AdditionalMetaLocation_s*)e->gg.g.n)
	  len += zx_LEN_WO_m20_AdditionalMetaLocation(c, e);
  }
  {
      struct zx_m20_Extension_s* e;
      for (e = x->Extension; e; e = (struct zx_m20_Extension_s*)e->gg.g.n)
	  len += zx_LEN_WO_m20_Extension(c, e);
  }
  {
      struct zx_ds_Signature_s* e;
      for (e = x->Signature; e; e = (struct zx_ds_Signature_s*)e->gg.g.n)
	  if (e != c->exclude_sig)
              len += zx_LEN_WO_ds_Signature(c, e);
  }
  for (se = x->SingleSignOnServiceURL; se; se = (struct zx_elem_s*)se->g.n)
    len += zx_LEN_WO_simple_elem(c, se, sizeof("SingleSignOnServiceURL")-1);
  for (se = x->SingleSignOnProtocolProfile; se; se = (struct zx_elem_s*)se->g.n)
    len += zx_LEN_WO_simple_elem(c, se, sizeof("SingleSignOnProtocolProfile")-1);
  for (se = x->AuthnServiceURL; se; se = (struct zx_elem_s*)se->g.n)
    len += zx_LEN_WO_simple_elem(c, se, sizeof("AuthnServiceURL")-1);


  len += zx_len_wo_common(c, &x->gg); 
  zx_pop_seen(pop_seen);
  ENC_LEN_DEBUG(x, "m20:IDPDescriptor", len);
  return len;
}

/* FUNC(zx_ENC_SO_m20_IDPDescriptor) */

/* Render element into string. The XML attributes and elements are
 * processed in schema order. This is what you generally want for
 * rendering new data structure to a string. The wo pointers are not used. */

/* Called by: */
char* zx_ENC_SO_m20_IDPDescriptor(struct zx_ctx* c, struct zx_m20_IDPDescriptor_s* x, char* p )
{
  struct zx_elem_s* se MAYBE_UNUSED;
  struct zx_ns_s* pop_seen = 0;
  ENC_LEN_DEBUG_BASE;
#if 1 /* NORMALMODE */
  /* *** in simple_elem case should output ns prefix from ns node. */
  ZX_OUT_TAG(p, "<m20:IDPDescriptor");
  if (c->inc_ns)
    p = zx_enc_inc_ns(c, p, &pop_seen);
  p = zx_enc_xmlns_if_not_seen(c, p, zx_ns_tab+zx_xmlns_ix_m20, &pop_seen);

  p = zx_attr_so_enc(p, x->cacheDuration, " cacheDuration=\"", sizeof(" cacheDuration=\"")-1);
  p = zx_attr_so_enc(p, x->id, " id=\"", sizeof(" id=\"")-1);
  p = zx_attr_so_enc(p, x->protocolSupportEnumeration, " protocolSupportEnumeration=\"", sizeof(" protocolSupportEnumeration=\"")-1);
  p = zx_attr_so_enc(p, x->validUntil, " validUntil=\"", sizeof(" validUntil=\"")-1);

  p = zx_enc_unknown_attrs(p, x->gg.any_attr);
#else
  /* root node has no begin tag */
#endif
  
  {
      struct zx_m20_KeyDescriptor_s* e;
      for (e = x->KeyDescriptor; e; e = (struct zx_m20_KeyDescriptor_s*)e->gg.g.n)
	  p = zx_ENC_SO_m20_KeyDescriptor(c, e, p);
  }
  for (se = x->SoapEndpoint; se; se = (struct zx_elem_s*)se->g.n)
    p = zx_ENC_SO_simple_elem(c, se, p, "m20:SoapEndpoint", sizeof("m20:SoapEndpoint")-1, zx_ns_tab+zx_xmlns_ix_m20);
  for (se = x->SingleLogoutServiceURL; se; se = (struct zx_elem_s*)se->g.n)
    p = zx_ENC_SO_simple_elem(c, se, p, "m20:SingleLogoutServiceURL", sizeof("m20:SingleLogoutServiceURL")-1, zx_ns_tab+zx_xmlns_ix_m20);
  for (se = x->SingleLogoutServiceReturnURL; se; se = (struct zx_elem_s*)se->g.n)
    p = zx_ENC_SO_simple_elem(c, se, p, "m20:SingleLogoutServiceReturnURL", sizeof("m20:SingleLogoutServiceReturnURL")-1, zx_ns_tab+zx_xmlns_ix_m20);
  for (se = x->FederationTerminationServiceURL; se; se = (struct zx_elem_s*)se->g.n)
    p = zx_ENC_SO_simple_elem(c, se, p, "m20:FederationTerminationServiceURL", sizeof("m20:FederationTerminationServiceURL")-1, zx_ns_tab+zx_xmlns_ix_m20);
  for (se = x->FederationTerminationServiceReturnURL; se; se = (struct zx_elem_s*)se->g.n)
    p = zx_ENC_SO_simple_elem(c, se, p, "m20:FederationTerminationServiceReturnURL", sizeof("m20:FederationTerminationServiceReturnURL")-1, zx_ns_tab+zx_xmlns_ix_m20);
  for (se = x->FederationTerminationNotificationProtocolProfile; se; se = (struct zx_elem_s*)se->g.n)
    p = zx_ENC_SO_simple_elem(c, se, p, "m20:FederationTerminationNotificationProtocolProfile", sizeof("m20:FederationTerminationNotificationProtocolProfile")-1, zx_ns_tab+zx_xmlns_ix_m20);
  for (se = x->SingleLogoutProtocolProfile; se; se = (struct zx_elem_s*)se->g.n)
    p = zx_ENC_SO_simple_elem(c, se, p, "m20:SingleLogoutProtocolProfile", sizeof("m20:SingleLogoutProtocolProfile")-1, zx_ns_tab+zx_xmlns_ix_m20);
  for (se = x->RegisterNameIdentifierProtocolProfile; se; se = (struct zx_elem_s*)se->g.n)
    p = zx_ENC_SO_simple_elem(c, se, p, "m20:RegisterNameIdentifierProtocolProfile", sizeof("m20:RegisterNameIdentifierProtocolProfile")-1, zx_ns_tab+zx_xmlns_ix_m20);
  for (se = x->RegisterNameIdentifierServiceURL; se; se = (struct zx_elem_s*)se->g.n)
    p = zx_ENC_SO_simple_elem(c, se, p, "m20:RegisterNameIdentifierServiceURL", sizeof("m20:RegisterNameIdentifierServiceURL")-1, zx_ns_tab+zx_xmlns_ix_m20);
  for (se = x->RegisterNameIdentifierServiceReturnURL; se; se = (struct zx_elem_s*)se->g.n)
    p = zx_ENC_SO_simple_elem(c, se, p, "m20:RegisterNameIdentifierServiceReturnURL", sizeof("m20:RegisterNameIdentifierServiceReturnURL")-1, zx_ns_tab+zx_xmlns_ix_m20);
  for (se = x->NameIdentifierMappingProtocolProfile; se; se = (struct zx_elem_s*)se->g.n)
    p = zx_ENC_SO_simple_elem(c, se, p, "m20:NameIdentifierMappingProtocolProfile", sizeof("m20:NameIdentifierMappingProtocolProfile")-1, zx_ns_tab+zx_xmlns_ix_m20);
  for (se = x->NameIdentifierMappingEncryptionProfile; se; se = (struct zx_elem_s*)se->g.n)
    p = zx_ENC_SO_simple_elem(c, se, p, "m20:NameIdentifierMappingEncryptionProfile", sizeof("m20:NameIdentifierMappingEncryptionProfile")-1, zx_ns_tab+zx_xmlns_ix_m20);
  {
      struct zx_m20_Organization_s* e;
      for (e = x->Organization; e; e = (struct zx_m20_Organization_s*)e->gg.g.n)
	  p = zx_ENC_SO_m20_Organization(c, e, p);
  }
  {
      struct zx_m20_ContactPerson_s* e;
      for (e = x->ContactPerson; e; e = (struct zx_m20_ContactPerson_s*)e->gg.g.n)
	  p = zx_ENC_SO_m20_ContactPerson(c, e, p);
  }
  {
      struct zx_m20_AdditionalMetaLocation_s* e;
      for (e = x->AdditionalMetaLocation; e; e = (struct zx_m20_AdditionalMetaLocation_s*)e->gg.g.n)
	  p = zx_ENC_SO_m20_AdditionalMetaLocation(c, e, p);
  }
  {
      struct zx_m20_Extension_s* e;
      for (e = x->Extension; e; e = (struct zx_m20_Extension_s*)e->gg.g.n)
	  p = zx_ENC_SO_m20_Extension(c, e, p);
  }
  {
      struct zx_ds_Signature_s* e;
      for (e = x->Signature; e; e = (struct zx_ds_Signature_s*)e->gg.g.n)
	  if (e != c->exclude_sig)
              p = zx_ENC_SO_ds_Signature(c, e, p);
  }
  for (se = x->SingleSignOnServiceURL; se; se = (struct zx_elem_s*)se->g.n)
    p = zx_ENC_SO_simple_elem(c, se, p, "m20:SingleSignOnServiceURL", sizeof("m20:SingleSignOnServiceURL")-1, zx_ns_tab+zx_xmlns_ix_m20);
  for (se = x->SingleSignOnProtocolProfile; se; se = (struct zx_elem_s*)se->g.n)
    p = zx_ENC_SO_simple_elem(c, se, p, "m20:SingleSignOnProtocolProfile", sizeof("m20:SingleSignOnProtocolProfile")-1, zx_ns_tab+zx_xmlns_ix_m20);
  for (se = x->AuthnServiceURL; se; se = (struct zx_elem_s*)se->g.n)
    p = zx_ENC_SO_simple_elem(c, se, p, "m20:AuthnServiceURL", sizeof("m20:AuthnServiceURL")-1, zx_ns_tab+zx_xmlns_ix_m20);

  p = zx_enc_so_unknown_elems_and_content(c, p, &x->gg);
  
#if 1 /* NORMALMODE */
  ZX_OUT_CLOSE_TAG(p, "</m20:IDPDescriptor>");
  zx_pop_seen(pop_seen);
#else
  /* root node has no end tag either */
#endif
  ENC_LEN_DEBUG(x, "m20:IDPDescriptor", p-enc_base);
  return p;
}

/* FUNC(zx_ENC_WO_m20_IDPDescriptor) */

/* Render element into string. The XML attributes and elements are
 * processed in wire order by chasing wo pointers. This is what you want for
 * validating signatures on other people's XML documents. */

/* Called by: */
char* zx_ENC_WO_m20_IDPDescriptor(struct zx_ctx* c, struct zx_m20_IDPDescriptor_s* x, char* p )
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
  ZX_OUT_MEM(p, "IDPDescriptor", sizeof("IDPDescriptor")-1);
  qq = p;

  /* *** sort the namespaces */
  if (c->inc_ns)
    zx_add_inc_ns(c, &pop_seen);
  zx_add_xmlns_if_not_seen(c, x->gg.g.ns, &pop_seen);

  p = zx_enc_seen(p, pop_seen); 
  p = zx_attr_wo_enc(p, x->cacheDuration, "cacheDuration=\"", sizeof("cacheDuration=\"")-1);
  p = zx_attr_wo_enc(p, x->id, "id=\"", sizeof("id=\"")-1);
  p = zx_attr_wo_enc(p, x->protocolSupportEnumeration, "protocolSupportEnumeration=\"", sizeof("protocolSupportEnumeration=\"")-1);
  p = zx_attr_wo_enc(p, x->validUntil, "validUntil=\"", sizeof("validUntil=\"")-1);

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
  ENC_LEN_DEBUG(x, "m20:IDPDescriptor", p-enc_base);
  return p;
}

/* FUNC(zx_EASY_ENC_SO_m20_IDPDescriptor) */

/* Called by: */
struct zx_str* zx_EASY_ENC_SO_m20_IDPDescriptor(struct zx_ctx* c, struct zx_m20_IDPDescriptor_s* x )
{
  int len;
  char* buf;
  c->ns_tab = ZX_ALLOC(c, sizeof(zx_ns_tab));
  memcpy(c->ns_tab, zx_ns_tab, sizeof(zx_ns_tab));
  len = zx_LEN_SO_m20_IDPDescriptor(c, x );
  buf = ZX_ALLOC(c, len+1);
  return zx_easy_enc_common(c, zx_ENC_SO_m20_IDPDescriptor(c, x, buf ), buf, len);
}

/* FUNC(zx_EASY_ENC_WO_m20_IDPDescriptor) */

/* Called by: */
struct zx_str* zx_EASY_ENC_WO_m20_IDPDescriptor(struct zx_ctx* c, struct zx_m20_IDPDescriptor_s* x )
{
  int len;
  char* buf;
  c->ns_tab = ZX_ALLOC(c, sizeof(zx_ns_tab));
  memcpy(c->ns_tab, zx_ns_tab, sizeof(zx_ns_tab));
  len = zx_LEN_WO_m20_IDPDescriptor(c, x );
  buf = ZX_ALLOC(c, len+1);
  return zx_easy_enc_common(c, zx_ENC_WO_m20_IDPDescriptor(c, x, buf ), buf, len);
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

#define EL_NAME   m20_KeyDescriptor
#define EL_STRUCT zx_m20_KeyDescriptor_s
#define EL_NS     m20
#define EL_TAG    KeyDescriptor

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

/* FUNC(zx_LEN_SO_m20_KeyDescriptor) */

/* Compute length of an element (and its subelements). The XML attributes
 * and elements are processed in schema order. */

/* Called by: */
int zx_LEN_SO_m20_KeyDescriptor(struct zx_ctx* c, struct zx_m20_KeyDescriptor_s* x )
{
  struct zx_ns_s* pop_seen = 0;
  struct zx_elem_s* se MAYBE_UNUSED;
#if 1 /* NORMALMODE */
  /* *** in simple_elem case should output ns prefix from ns node. */
  int len = sizeof("<m20:KeyDescriptor")-1 + 1 + sizeof("</m20:KeyDescriptor>")-1;
  if (c->inc_ns_len)
    len += zx_len_inc_ns(c, &pop_seen);
  len += zx_len_xmlns_if_not_seen(c, zx_ns_tab+zx_xmlns_ix_m20, &pop_seen);

  len += zx_attr_so_len(x->use, sizeof("use")-1);

#else
  /* root node has no begin tag */
  int len = 0;
#endif
  
  for (se = x->EncryptionMethod; se; se = (struct zx_elem_s*)se->g.n)
    len += zx_LEN_SO_simple_elem(c,se, sizeof("m20:EncryptionMethod")-1, zx_ns_tab+zx_xmlns_ix_m20);
  for (se = x->KeySize; se; se = (struct zx_elem_s*)se->g.n)
    len += zx_LEN_SO_simple_elem(c,se, sizeof("m20:KeySize")-1, zx_ns_tab+zx_xmlns_ix_m20);
  {
      struct zx_ds_KeyInfo_s* e;
      for (e = x->KeyInfo; e; e = (struct zx_ds_KeyInfo_s*)e->gg.g.n)
	  len += zx_LEN_SO_ds_KeyInfo(c, e);
  }
  {
      struct zx_m20_Extension_s* e;
      for (e = x->Extension; e; e = (struct zx_m20_Extension_s*)e->gg.g.n)
	  len += zx_LEN_SO_m20_Extension(c, e);
  }


  len += zx_len_so_common(c, &x->gg);
  zx_pop_seen(pop_seen);
  ENC_LEN_DEBUG(x, "m20:KeyDescriptor", len);
  return len;
}

/* FUNC(zx_LEN_WO_m20_KeyDescriptor) */

/* Compute length of an element (and its subelements). The XML attributes
 * and elements are processed in wire order and no assumptions
 * are made about namespace prefixes. */

/* Called by: */
int zx_LEN_WO_m20_KeyDescriptor(struct zx_ctx* c, struct zx_m20_KeyDescriptor_s* x )
{
  struct zx_ns_s* pop_seen = 0;
  struct zx_elem_s* se MAYBE_UNUSED;
#if 1 /* NORMALMODE */
  int len = 1 + sizeof("KeyDescriptor")-1 + 1 + 2 + sizeof("KeyDescriptor")-1 + 1;
  
  if (x->gg.g.ns && x->gg.g.ns->prefix_len)
    len += (x->gg.g.ns->prefix_len + 1) * 2;
  if (c->inc_ns_len)
    len += zx_len_inc_ns(c, &pop_seen);
  len += zx_len_xmlns_if_not_seen(c, x->gg.g.ns, &pop_seen);

  len += zx_attr_wo_len(x->use, sizeof("use")-1);

#else
  /* root node has no begin tag */
  int len = 0;
#endif
  
  for (se = x->EncryptionMethod; se; se = (struct zx_elem_s*)se->g.n)
    len += zx_LEN_WO_simple_elem(c, se, sizeof("EncryptionMethod")-1);
  for (se = x->KeySize; se; se = (struct zx_elem_s*)se->g.n)
    len += zx_LEN_WO_simple_elem(c, se, sizeof("KeySize")-1);
  {
      struct zx_ds_KeyInfo_s* e;
      for (e = x->KeyInfo; e; e = (struct zx_ds_KeyInfo_s*)e->gg.g.n)
	  len += zx_LEN_WO_ds_KeyInfo(c, e);
  }
  {
      struct zx_m20_Extension_s* e;
      for (e = x->Extension; e; e = (struct zx_m20_Extension_s*)e->gg.g.n)
	  len += zx_LEN_WO_m20_Extension(c, e);
  }


  len += zx_len_wo_common(c, &x->gg); 
  zx_pop_seen(pop_seen);
  ENC_LEN_DEBUG(x, "m20:KeyDescriptor", len);
  return len;
}

/* FUNC(zx_ENC_SO_m20_KeyDescriptor) */

/* Render element into string. The XML attributes and elements are
 * processed in schema order. This is what you generally want for
 * rendering new data structure to a string. The wo pointers are not used. */

/* Called by: */
char* zx_ENC_SO_m20_KeyDescriptor(struct zx_ctx* c, struct zx_m20_KeyDescriptor_s* x, char* p )
{
  struct zx_elem_s* se MAYBE_UNUSED;
  struct zx_ns_s* pop_seen = 0;
  ENC_LEN_DEBUG_BASE;
#if 1 /* NORMALMODE */
  /* *** in simple_elem case should output ns prefix from ns node. */
  ZX_OUT_TAG(p, "<m20:KeyDescriptor");
  if (c->inc_ns)
    p = zx_enc_inc_ns(c, p, &pop_seen);
  p = zx_enc_xmlns_if_not_seen(c, p, zx_ns_tab+zx_xmlns_ix_m20, &pop_seen);

  p = zx_attr_so_enc(p, x->use, " use=\"", sizeof(" use=\"")-1);

  p = zx_enc_unknown_attrs(p, x->gg.any_attr);
#else
  /* root node has no begin tag */
#endif
  
  for (se = x->EncryptionMethod; se; se = (struct zx_elem_s*)se->g.n)
    p = zx_ENC_SO_simple_elem(c, se, p, "m20:EncryptionMethod", sizeof("m20:EncryptionMethod")-1, zx_ns_tab+zx_xmlns_ix_m20);
  for (se = x->KeySize; se; se = (struct zx_elem_s*)se->g.n)
    p = zx_ENC_SO_simple_elem(c, se, p, "m20:KeySize", sizeof("m20:KeySize")-1, zx_ns_tab+zx_xmlns_ix_m20);
  {
      struct zx_ds_KeyInfo_s* e;
      for (e = x->KeyInfo; e; e = (struct zx_ds_KeyInfo_s*)e->gg.g.n)
	  p = zx_ENC_SO_ds_KeyInfo(c, e, p);
  }
  {
      struct zx_m20_Extension_s* e;
      for (e = x->Extension; e; e = (struct zx_m20_Extension_s*)e->gg.g.n)
	  p = zx_ENC_SO_m20_Extension(c, e, p);
  }

  p = zx_enc_so_unknown_elems_and_content(c, p, &x->gg);
  
#if 1 /* NORMALMODE */
  ZX_OUT_CLOSE_TAG(p, "</m20:KeyDescriptor>");
  zx_pop_seen(pop_seen);
#else
  /* root node has no end tag either */
#endif
  ENC_LEN_DEBUG(x, "m20:KeyDescriptor", p-enc_base);
  return p;
}

/* FUNC(zx_ENC_WO_m20_KeyDescriptor) */

/* Render element into string. The XML attributes and elements are
 * processed in wire order by chasing wo pointers. This is what you want for
 * validating signatures on other people's XML documents. */

/* Called by: */
char* zx_ENC_WO_m20_KeyDescriptor(struct zx_ctx* c, struct zx_m20_KeyDescriptor_s* x, char* p )
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
  ZX_OUT_MEM(p, "KeyDescriptor", sizeof("KeyDescriptor")-1);
  qq = p;

  /* *** sort the namespaces */
  if (c->inc_ns)
    zx_add_inc_ns(c, &pop_seen);
  zx_add_xmlns_if_not_seen(c, x->gg.g.ns, &pop_seen);

  p = zx_enc_seen(p, pop_seen); 
  p = zx_attr_wo_enc(p, x->use, "use=\"", sizeof("use=\"")-1);

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
  ENC_LEN_DEBUG(x, "m20:KeyDescriptor", p-enc_base);
  return p;
}

/* FUNC(zx_EASY_ENC_SO_m20_KeyDescriptor) */

/* Called by: */
struct zx_str* zx_EASY_ENC_SO_m20_KeyDescriptor(struct zx_ctx* c, struct zx_m20_KeyDescriptor_s* x )
{
  int len;
  char* buf;
  c->ns_tab = ZX_ALLOC(c, sizeof(zx_ns_tab));
  memcpy(c->ns_tab, zx_ns_tab, sizeof(zx_ns_tab));
  len = zx_LEN_SO_m20_KeyDescriptor(c, x );
  buf = ZX_ALLOC(c, len+1);
  return zx_easy_enc_common(c, zx_ENC_SO_m20_KeyDescriptor(c, x, buf ), buf, len);
}

/* FUNC(zx_EASY_ENC_WO_m20_KeyDescriptor) */

/* Called by: */
struct zx_str* zx_EASY_ENC_WO_m20_KeyDescriptor(struct zx_ctx* c, struct zx_m20_KeyDescriptor_s* x )
{
  int len;
  char* buf;
  c->ns_tab = ZX_ALLOC(c, sizeof(zx_ns_tab));
  memcpy(c->ns_tab, zx_ns_tab, sizeof(zx_ns_tab));
  len = zx_LEN_WO_m20_KeyDescriptor(c, x );
  buf = ZX_ALLOC(c, len+1);
  return zx_easy_enc_common(c, zx_ENC_WO_m20_KeyDescriptor(c, x, buf ), buf, len);
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

#define EL_NAME   m20_Organization
#define EL_STRUCT zx_m20_Organization_s
#define EL_NS     m20
#define EL_TAG    Organization

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

/* FUNC(zx_LEN_SO_m20_Organization) */

/* Compute length of an element (and its subelements). The XML attributes
 * and elements are processed in schema order. */

/* Called by: */
int zx_LEN_SO_m20_Organization(struct zx_ctx* c, struct zx_m20_Organization_s* x )
{
  struct zx_ns_s* pop_seen = 0;
  struct zx_elem_s* se MAYBE_UNUSED;
#if 1 /* NORMALMODE */
  /* *** in simple_elem case should output ns prefix from ns node. */
  int len = sizeof("<m20:Organization")-1 + 1 + sizeof("</m20:Organization>")-1;
  if (c->inc_ns_len)
    len += zx_len_inc_ns(c, &pop_seen);
  len += zx_len_xmlns_if_not_seen(c, zx_ns_tab+zx_xmlns_ix_m20, &pop_seen);


#else
  /* root node has no begin tag */
  int len = 0;
#endif
  
  {
      struct zx_m20_OrganizationName_s* e;
      for (e = x->OrganizationName; e; e = (struct zx_m20_OrganizationName_s*)e->gg.g.n)
	  len += zx_LEN_SO_m20_OrganizationName(c, e);
  }
  {
      struct zx_m20_OrganizationDisplayName_s* e;
      for (e = x->OrganizationDisplayName; e; e = (struct zx_m20_OrganizationDisplayName_s*)e->gg.g.n)
	  len += zx_LEN_SO_m20_OrganizationDisplayName(c, e);
  }
  {
      struct zx_m20_OrganizationURL_s* e;
      for (e = x->OrganizationURL; e; e = (struct zx_m20_OrganizationURL_s*)e->gg.g.n)
	  len += zx_LEN_SO_m20_OrganizationURL(c, e);
  }
  {
      struct zx_m20_Extension_s* e;
      for (e = x->Extension; e; e = (struct zx_m20_Extension_s*)e->gg.g.n)
	  len += zx_LEN_SO_m20_Extension(c, e);
  }


  len += zx_len_so_common(c, &x->gg);
  zx_pop_seen(pop_seen);
  ENC_LEN_DEBUG(x, "m20:Organization", len);
  return len;
}

/* FUNC(zx_LEN_WO_m20_Organization) */

/* Compute length of an element (and its subelements). The XML attributes
 * and elements are processed in wire order and no assumptions
 * are made about namespace prefixes. */

/* Called by: */
int zx_LEN_WO_m20_Organization(struct zx_ctx* c, struct zx_m20_Organization_s* x )
{
  struct zx_ns_s* pop_seen = 0;
  struct zx_elem_s* se MAYBE_UNUSED;
#if 1 /* NORMALMODE */
  int len = 1 + sizeof("Organization")-1 + 1 + 2 + sizeof("Organization")-1 + 1;
  
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
      struct zx_m20_OrganizationName_s* e;
      for (e = x->OrganizationName; e; e = (struct zx_m20_OrganizationName_s*)e->gg.g.n)
	  len += zx_LEN_WO_m20_OrganizationName(c, e);
  }
  {
      struct zx_m20_OrganizationDisplayName_s* e;
      for (e = x->OrganizationDisplayName; e; e = (struct zx_m20_OrganizationDisplayName_s*)e->gg.g.n)
	  len += zx_LEN_WO_m20_OrganizationDisplayName(c, e);
  }
  {
      struct zx_m20_OrganizationURL_s* e;
      for (e = x->OrganizationURL; e; e = (struct zx_m20_OrganizationURL_s*)e->gg.g.n)
	  len += zx_LEN_WO_m20_OrganizationURL(c, e);
  }
  {
      struct zx_m20_Extension_s* e;
      for (e = x->Extension; e; e = (struct zx_m20_Extension_s*)e->gg.g.n)
	  len += zx_LEN_WO_m20_Extension(c, e);
  }


  len += zx_len_wo_common(c, &x->gg); 
  zx_pop_seen(pop_seen);
  ENC_LEN_DEBUG(x, "m20:Organization", len);
  return len;
}

/* FUNC(zx_ENC_SO_m20_Organization) */

/* Render element into string. The XML attributes and elements are
 * processed in schema order. This is what you generally want for
 * rendering new data structure to a string. The wo pointers are not used. */

/* Called by: */
char* zx_ENC_SO_m20_Organization(struct zx_ctx* c, struct zx_m20_Organization_s* x, char* p )
{
  struct zx_elem_s* se MAYBE_UNUSED;
  struct zx_ns_s* pop_seen = 0;
  ENC_LEN_DEBUG_BASE;
#if 1 /* NORMALMODE */
  /* *** in simple_elem case should output ns prefix from ns node. */
  ZX_OUT_TAG(p, "<m20:Organization");
  if (c->inc_ns)
    p = zx_enc_inc_ns(c, p, &pop_seen);
  p = zx_enc_xmlns_if_not_seen(c, p, zx_ns_tab+zx_xmlns_ix_m20, &pop_seen);


  p = zx_enc_unknown_attrs(p, x->gg.any_attr);
#else
  /* root node has no begin tag */
#endif
  
  {
      struct zx_m20_OrganizationName_s* e;
      for (e = x->OrganizationName; e; e = (struct zx_m20_OrganizationName_s*)e->gg.g.n)
	  p = zx_ENC_SO_m20_OrganizationName(c, e, p);
  }
  {
      struct zx_m20_OrganizationDisplayName_s* e;
      for (e = x->OrganizationDisplayName; e; e = (struct zx_m20_OrganizationDisplayName_s*)e->gg.g.n)
	  p = zx_ENC_SO_m20_OrganizationDisplayName(c, e, p);
  }
  {
      struct zx_m20_OrganizationURL_s* e;
      for (e = x->OrganizationURL; e; e = (struct zx_m20_OrganizationURL_s*)e->gg.g.n)
	  p = zx_ENC_SO_m20_OrganizationURL(c, e, p);
  }
  {
      struct zx_m20_Extension_s* e;
      for (e = x->Extension; e; e = (struct zx_m20_Extension_s*)e->gg.g.n)
	  p = zx_ENC_SO_m20_Extension(c, e, p);
  }

  p = zx_enc_so_unknown_elems_and_content(c, p, &x->gg);
  
#if 1 /* NORMALMODE */
  ZX_OUT_CLOSE_TAG(p, "</m20:Organization>");
  zx_pop_seen(pop_seen);
#else
  /* root node has no end tag either */
#endif
  ENC_LEN_DEBUG(x, "m20:Organization", p-enc_base);
  return p;
}

/* FUNC(zx_ENC_WO_m20_Organization) */

/* Render element into string. The XML attributes and elements are
 * processed in wire order by chasing wo pointers. This is what you want for
 * validating signatures on other people's XML documents. */

/* Called by: */
char* zx_ENC_WO_m20_Organization(struct zx_ctx* c, struct zx_m20_Organization_s* x, char* p )
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
  ZX_OUT_MEM(p, "Organization", sizeof("Organization")-1);
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
  ENC_LEN_DEBUG(x, "m20:Organization", p-enc_base);
  return p;
}

/* FUNC(zx_EASY_ENC_SO_m20_Organization) */

/* Called by: */
struct zx_str* zx_EASY_ENC_SO_m20_Organization(struct zx_ctx* c, struct zx_m20_Organization_s* x )
{
  int len;
  char* buf;
  c->ns_tab = ZX_ALLOC(c, sizeof(zx_ns_tab));
  memcpy(c->ns_tab, zx_ns_tab, sizeof(zx_ns_tab));
  len = zx_LEN_SO_m20_Organization(c, x );
  buf = ZX_ALLOC(c, len+1);
  return zx_easy_enc_common(c, zx_ENC_SO_m20_Organization(c, x, buf ), buf, len);
}

/* FUNC(zx_EASY_ENC_WO_m20_Organization) */

/* Called by: */
struct zx_str* zx_EASY_ENC_WO_m20_Organization(struct zx_ctx* c, struct zx_m20_Organization_s* x )
{
  int len;
  char* buf;
  c->ns_tab = ZX_ALLOC(c, sizeof(zx_ns_tab));
  memcpy(c->ns_tab, zx_ns_tab, sizeof(zx_ns_tab));
  len = zx_LEN_WO_m20_Organization(c, x );
  buf = ZX_ALLOC(c, len+1);
  return zx_easy_enc_common(c, zx_ENC_WO_m20_Organization(c, x, buf ), buf, len);
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

#define EL_NAME   m20_OrganizationDisplayName
#define EL_STRUCT zx_m20_OrganizationDisplayName_s
#define EL_NS     m20
#define EL_TAG    OrganizationDisplayName

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

/* FUNC(zx_LEN_SO_m20_OrganizationDisplayName) */

/* Compute length of an element (and its subelements). The XML attributes
 * and elements are processed in schema order. */

/* Called by: */
int zx_LEN_SO_m20_OrganizationDisplayName(struct zx_ctx* c, struct zx_m20_OrganizationDisplayName_s* x )
{
  struct zx_ns_s* pop_seen = 0;
  struct zx_elem_s* se MAYBE_UNUSED;
#if 1 /* NORMALMODE */
  /* *** in simple_elem case should output ns prefix from ns node. */
  int len = sizeof("<m20:OrganizationDisplayName")-1 + 1 + sizeof("</m20:OrganizationDisplayName>")-1;
  if (c->inc_ns_len)
    len += zx_len_inc_ns(c, &pop_seen);
  len += zx_len_xmlns_if_not_seen(c, zx_ns_tab+zx_xmlns_ix_m20, &pop_seen);

  len += zx_attr_so_len(x->lang, sizeof("lang")-1);

#else
  /* root node has no begin tag */
  int len = 0;
#endif
  


  len += zx_len_so_common(c, &x->gg);
  zx_pop_seen(pop_seen);
  ENC_LEN_DEBUG(x, "m20:OrganizationDisplayName", len);
  return len;
}

/* FUNC(zx_LEN_WO_m20_OrganizationDisplayName) */

/* Compute length of an element (and its subelements). The XML attributes
 * and elements are processed in wire order and no assumptions
 * are made about namespace prefixes. */

/* Called by: */
int zx_LEN_WO_m20_OrganizationDisplayName(struct zx_ctx* c, struct zx_m20_OrganizationDisplayName_s* x )
{
  struct zx_ns_s* pop_seen = 0;
  struct zx_elem_s* se MAYBE_UNUSED;
#if 1 /* NORMALMODE */
  int len = 1 + sizeof("OrganizationDisplayName")-1 + 1 + 2 + sizeof("OrganizationDisplayName")-1 + 1;
  
  if (x->gg.g.ns && x->gg.g.ns->prefix_len)
    len += (x->gg.g.ns->prefix_len + 1) * 2;
  if (c->inc_ns_len)
    len += zx_len_inc_ns(c, &pop_seen);
  len += zx_len_xmlns_if_not_seen(c, x->gg.g.ns, &pop_seen);

  len += zx_attr_wo_len(x->lang, sizeof("lang")-1);

#else
  /* root node has no begin tag */
  int len = 0;
#endif
  


  len += zx_len_wo_common(c, &x->gg); 
  zx_pop_seen(pop_seen);
  ENC_LEN_DEBUG(x, "m20:OrganizationDisplayName", len);
  return len;
}

/* FUNC(zx_ENC_SO_m20_OrganizationDisplayName) */

/* Render element into string. The XML attributes and elements are
 * processed in schema order. This is what you generally want for
 * rendering new data structure to a string. The wo pointers are not used. */

/* Called by: */
char* zx_ENC_SO_m20_OrganizationDisplayName(struct zx_ctx* c, struct zx_m20_OrganizationDisplayName_s* x, char* p )
{
  struct zx_elem_s* se MAYBE_UNUSED;
  struct zx_ns_s* pop_seen = 0;
  ENC_LEN_DEBUG_BASE;
#if 1 /* NORMALMODE */
  /* *** in simple_elem case should output ns prefix from ns node. */
  ZX_OUT_TAG(p, "<m20:OrganizationDisplayName");
  if (c->inc_ns)
    p = zx_enc_inc_ns(c, p, &pop_seen);
  p = zx_enc_xmlns_if_not_seen(c, p, zx_ns_tab+zx_xmlns_ix_m20, &pop_seen);

  p = zx_attr_so_enc(p, x->lang, " lang=\"", sizeof(" lang=\"")-1);

  p = zx_enc_unknown_attrs(p, x->gg.any_attr);
#else
  /* root node has no begin tag */
#endif
  

  p = zx_enc_so_unknown_elems_and_content(c, p, &x->gg);
  
#if 1 /* NORMALMODE */
  ZX_OUT_CLOSE_TAG(p, "</m20:OrganizationDisplayName>");
  zx_pop_seen(pop_seen);
#else
  /* root node has no end tag either */
#endif
  ENC_LEN_DEBUG(x, "m20:OrganizationDisplayName", p-enc_base);
  return p;
}

/* FUNC(zx_ENC_WO_m20_OrganizationDisplayName) */

/* Render element into string. The XML attributes and elements are
 * processed in wire order by chasing wo pointers. This is what you want for
 * validating signatures on other people's XML documents. */

/* Called by: */
char* zx_ENC_WO_m20_OrganizationDisplayName(struct zx_ctx* c, struct zx_m20_OrganizationDisplayName_s* x, char* p )
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
  ZX_OUT_MEM(p, "OrganizationDisplayName", sizeof("OrganizationDisplayName")-1);
  qq = p;

  /* *** sort the namespaces */
  if (c->inc_ns)
    zx_add_inc_ns(c, &pop_seen);
  zx_add_xmlns_if_not_seen(c, x->gg.g.ns, &pop_seen);

  p = zx_enc_seen(p, pop_seen); 
  p = zx_attr_wo_enc(p, x->lang, "lang=\"", sizeof("lang=\"")-1);

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
  ENC_LEN_DEBUG(x, "m20:OrganizationDisplayName", p-enc_base);
  return p;
}

/* FUNC(zx_EASY_ENC_SO_m20_OrganizationDisplayName) */

/* Called by: */
struct zx_str* zx_EASY_ENC_SO_m20_OrganizationDisplayName(struct zx_ctx* c, struct zx_m20_OrganizationDisplayName_s* x )
{
  int len;
  char* buf;
  c->ns_tab = ZX_ALLOC(c, sizeof(zx_ns_tab));
  memcpy(c->ns_tab, zx_ns_tab, sizeof(zx_ns_tab));
  len = zx_LEN_SO_m20_OrganizationDisplayName(c, x );
  buf = ZX_ALLOC(c, len+1);
  return zx_easy_enc_common(c, zx_ENC_SO_m20_OrganizationDisplayName(c, x, buf ), buf, len);
}

/* FUNC(zx_EASY_ENC_WO_m20_OrganizationDisplayName) */

/* Called by: */
struct zx_str* zx_EASY_ENC_WO_m20_OrganizationDisplayName(struct zx_ctx* c, struct zx_m20_OrganizationDisplayName_s* x )
{
  int len;
  char* buf;
  c->ns_tab = ZX_ALLOC(c, sizeof(zx_ns_tab));
  memcpy(c->ns_tab, zx_ns_tab, sizeof(zx_ns_tab));
  len = zx_LEN_WO_m20_OrganizationDisplayName(c, x );
  buf = ZX_ALLOC(c, len+1);
  return zx_easy_enc_common(c, zx_ENC_WO_m20_OrganizationDisplayName(c, x, buf ), buf, len);
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

#define EL_NAME   m20_OrganizationName
#define EL_STRUCT zx_m20_OrganizationName_s
#define EL_NS     m20
#define EL_TAG    OrganizationName

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

/* FUNC(zx_LEN_SO_m20_OrganizationName) */

/* Compute length of an element (and its subelements). The XML attributes
 * and elements are processed in schema order. */

/* Called by: */
int zx_LEN_SO_m20_OrganizationName(struct zx_ctx* c, struct zx_m20_OrganizationName_s* x )
{
  struct zx_ns_s* pop_seen = 0;
  struct zx_elem_s* se MAYBE_UNUSED;
#if 1 /* NORMALMODE */
  /* *** in simple_elem case should output ns prefix from ns node. */
  int len = sizeof("<m20:OrganizationName")-1 + 1 + sizeof("</m20:OrganizationName>")-1;
  if (c->inc_ns_len)
    len += zx_len_inc_ns(c, &pop_seen);
  len += zx_len_xmlns_if_not_seen(c, zx_ns_tab+zx_xmlns_ix_m20, &pop_seen);

  len += zx_attr_so_len(x->lang, sizeof("lang")-1);

#else
  /* root node has no begin tag */
  int len = 0;
#endif
  


  len += zx_len_so_common(c, &x->gg);
  zx_pop_seen(pop_seen);
  ENC_LEN_DEBUG(x, "m20:OrganizationName", len);
  return len;
}

/* FUNC(zx_LEN_WO_m20_OrganizationName) */

/* Compute length of an element (and its subelements). The XML attributes
 * and elements are processed in wire order and no assumptions
 * are made about namespace prefixes. */

/* Called by: */
int zx_LEN_WO_m20_OrganizationName(struct zx_ctx* c, struct zx_m20_OrganizationName_s* x )
{
  struct zx_ns_s* pop_seen = 0;
  struct zx_elem_s* se MAYBE_UNUSED;
#if 1 /* NORMALMODE */
  int len = 1 + sizeof("OrganizationName")-1 + 1 + 2 + sizeof("OrganizationName")-1 + 1;
  
  if (x->gg.g.ns && x->gg.g.ns->prefix_len)
    len += (x->gg.g.ns->prefix_len + 1) * 2;
  if (c->inc_ns_len)
    len += zx_len_inc_ns(c, &pop_seen);
  len += zx_len_xmlns_if_not_seen(c, x->gg.g.ns, &pop_seen);

  len += zx_attr_wo_len(x->lang, sizeof("lang")-1);

#else
  /* root node has no begin tag */
  int len = 0;
#endif
  


  len += zx_len_wo_common(c, &x->gg); 
  zx_pop_seen(pop_seen);
  ENC_LEN_DEBUG(x, "m20:OrganizationName", len);
  return len;
}

/* FUNC(zx_ENC_SO_m20_OrganizationName) */

/* Render element into string. The XML attributes and elements are
 * processed in schema order. This is what you generally want for
 * rendering new data structure to a string. The wo pointers are not used. */

/* Called by: */
char* zx_ENC_SO_m20_OrganizationName(struct zx_ctx* c, struct zx_m20_OrganizationName_s* x, char* p )
{
  struct zx_elem_s* se MAYBE_UNUSED;
  struct zx_ns_s* pop_seen = 0;
  ENC_LEN_DEBUG_BASE;
#if 1 /* NORMALMODE */
  /* *** in simple_elem case should output ns prefix from ns node. */
  ZX_OUT_TAG(p, "<m20:OrganizationName");
  if (c->inc_ns)
    p = zx_enc_inc_ns(c, p, &pop_seen);
  p = zx_enc_xmlns_if_not_seen(c, p, zx_ns_tab+zx_xmlns_ix_m20, &pop_seen);

  p = zx_attr_so_enc(p, x->lang, " lang=\"", sizeof(" lang=\"")-1);

  p = zx_enc_unknown_attrs(p, x->gg.any_attr);
#else
  /* root node has no begin tag */
#endif
  

  p = zx_enc_so_unknown_elems_and_content(c, p, &x->gg);
  
#if 1 /* NORMALMODE */
  ZX_OUT_CLOSE_TAG(p, "</m20:OrganizationName>");
  zx_pop_seen(pop_seen);
#else
  /* root node has no end tag either */
#endif
  ENC_LEN_DEBUG(x, "m20:OrganizationName", p-enc_base);
  return p;
}

/* FUNC(zx_ENC_WO_m20_OrganizationName) */

/* Render element into string. The XML attributes and elements are
 * processed in wire order by chasing wo pointers. This is what you want for
 * validating signatures on other people's XML documents. */

/* Called by: */
char* zx_ENC_WO_m20_OrganizationName(struct zx_ctx* c, struct zx_m20_OrganizationName_s* x, char* p )
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
  ZX_OUT_MEM(p, "OrganizationName", sizeof("OrganizationName")-1);
  qq = p;

  /* *** sort the namespaces */
  if (c->inc_ns)
    zx_add_inc_ns(c, &pop_seen);
  zx_add_xmlns_if_not_seen(c, x->gg.g.ns, &pop_seen);

  p = zx_enc_seen(p, pop_seen); 
  p = zx_attr_wo_enc(p, x->lang, "lang=\"", sizeof("lang=\"")-1);

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
  ENC_LEN_DEBUG(x, "m20:OrganizationName", p-enc_base);
  return p;
}

/* FUNC(zx_EASY_ENC_SO_m20_OrganizationName) */

/* Called by: */
struct zx_str* zx_EASY_ENC_SO_m20_OrganizationName(struct zx_ctx* c, struct zx_m20_OrganizationName_s* x )
{
  int len;
  char* buf;
  c->ns_tab = ZX_ALLOC(c, sizeof(zx_ns_tab));
  memcpy(c->ns_tab, zx_ns_tab, sizeof(zx_ns_tab));
  len = zx_LEN_SO_m20_OrganizationName(c, x );
  buf = ZX_ALLOC(c, len+1);
  return zx_easy_enc_common(c, zx_ENC_SO_m20_OrganizationName(c, x, buf ), buf, len);
}

/* FUNC(zx_EASY_ENC_WO_m20_OrganizationName) */

/* Called by: */
struct zx_str* zx_EASY_ENC_WO_m20_OrganizationName(struct zx_ctx* c, struct zx_m20_OrganizationName_s* x )
{
  int len;
  char* buf;
  c->ns_tab = ZX_ALLOC(c, sizeof(zx_ns_tab));
  memcpy(c->ns_tab, zx_ns_tab, sizeof(zx_ns_tab));
  len = zx_LEN_WO_m20_OrganizationName(c, x );
  buf = ZX_ALLOC(c, len+1);
  return zx_easy_enc_common(c, zx_ENC_WO_m20_OrganizationName(c, x, buf ), buf, len);
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

#define EL_NAME   m20_OrganizationURL
#define EL_STRUCT zx_m20_OrganizationURL_s
#define EL_NS     m20
#define EL_TAG    OrganizationURL

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

/* FUNC(zx_LEN_SO_m20_OrganizationURL) */

/* Compute length of an element (and its subelements). The XML attributes
 * and elements are processed in schema order. */

/* Called by: */
int zx_LEN_SO_m20_OrganizationURL(struct zx_ctx* c, struct zx_m20_OrganizationURL_s* x )
{
  struct zx_ns_s* pop_seen = 0;
  struct zx_elem_s* se MAYBE_UNUSED;
#if 1 /* NORMALMODE */
  /* *** in simple_elem case should output ns prefix from ns node. */
  int len = sizeof("<m20:OrganizationURL")-1 + 1 + sizeof("</m20:OrganizationURL>")-1;
  if (c->inc_ns_len)
    len += zx_len_inc_ns(c, &pop_seen);
  len += zx_len_xmlns_if_not_seen(c, zx_ns_tab+zx_xmlns_ix_m20, &pop_seen);

  len += zx_attr_so_len(x->lang, sizeof("lang")-1);

#else
  /* root node has no begin tag */
  int len = 0;
#endif
  


  len += zx_len_so_common(c, &x->gg);
  zx_pop_seen(pop_seen);
  ENC_LEN_DEBUG(x, "m20:OrganizationURL", len);
  return len;
}

/* FUNC(zx_LEN_WO_m20_OrganizationURL) */

/* Compute length of an element (and its subelements). The XML attributes
 * and elements are processed in wire order and no assumptions
 * are made about namespace prefixes. */

/* Called by: */
int zx_LEN_WO_m20_OrganizationURL(struct zx_ctx* c, struct zx_m20_OrganizationURL_s* x )
{
  struct zx_ns_s* pop_seen = 0;
  struct zx_elem_s* se MAYBE_UNUSED;
#if 1 /* NORMALMODE */
  int len = 1 + sizeof("OrganizationURL")-1 + 1 + 2 + sizeof("OrganizationURL")-1 + 1;
  
  if (x->gg.g.ns && x->gg.g.ns->prefix_len)
    len += (x->gg.g.ns->prefix_len + 1) * 2;
  if (c->inc_ns_len)
    len += zx_len_inc_ns(c, &pop_seen);
  len += zx_len_xmlns_if_not_seen(c, x->gg.g.ns, &pop_seen);

  len += zx_attr_wo_len(x->lang, sizeof("lang")-1);

#else
  /* root node has no begin tag */
  int len = 0;
#endif
  


  len += zx_len_wo_common(c, &x->gg); 
  zx_pop_seen(pop_seen);
  ENC_LEN_DEBUG(x, "m20:OrganizationURL", len);
  return len;
}

/* FUNC(zx_ENC_SO_m20_OrganizationURL) */

/* Render element into string. The XML attributes and elements are
 * processed in schema order. This is what you generally want for
 * rendering new data structure to a string. The wo pointers are not used. */

/* Called by: */
char* zx_ENC_SO_m20_OrganizationURL(struct zx_ctx* c, struct zx_m20_OrganizationURL_s* x, char* p )
{
  struct zx_elem_s* se MAYBE_UNUSED;
  struct zx_ns_s* pop_seen = 0;
  ENC_LEN_DEBUG_BASE;
#if 1 /* NORMALMODE */
  /* *** in simple_elem case should output ns prefix from ns node. */
  ZX_OUT_TAG(p, "<m20:OrganizationURL");
  if (c->inc_ns)
    p = zx_enc_inc_ns(c, p, &pop_seen);
  p = zx_enc_xmlns_if_not_seen(c, p, zx_ns_tab+zx_xmlns_ix_m20, &pop_seen);

  p = zx_attr_so_enc(p, x->lang, " lang=\"", sizeof(" lang=\"")-1);

  p = zx_enc_unknown_attrs(p, x->gg.any_attr);
#else
  /* root node has no begin tag */
#endif
  

  p = zx_enc_so_unknown_elems_and_content(c, p, &x->gg);
  
#if 1 /* NORMALMODE */
  ZX_OUT_CLOSE_TAG(p, "</m20:OrganizationURL>");
  zx_pop_seen(pop_seen);
#else
  /* root node has no end tag either */
#endif
  ENC_LEN_DEBUG(x, "m20:OrganizationURL", p-enc_base);
  return p;
}

/* FUNC(zx_ENC_WO_m20_OrganizationURL) */

/* Render element into string. The XML attributes and elements are
 * processed in wire order by chasing wo pointers. This is what you want for
 * validating signatures on other people's XML documents. */

/* Called by: */
char* zx_ENC_WO_m20_OrganizationURL(struct zx_ctx* c, struct zx_m20_OrganizationURL_s* x, char* p )
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
  ZX_OUT_MEM(p, "OrganizationURL", sizeof("OrganizationURL")-1);
  qq = p;

  /* *** sort the namespaces */
  if (c->inc_ns)
    zx_add_inc_ns(c, &pop_seen);
  zx_add_xmlns_if_not_seen(c, x->gg.g.ns, &pop_seen);

  p = zx_enc_seen(p, pop_seen); 
  p = zx_attr_wo_enc(p, x->lang, "lang=\"", sizeof("lang=\"")-1);

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
  ENC_LEN_DEBUG(x, "m20:OrganizationURL", p-enc_base);
  return p;
}

/* FUNC(zx_EASY_ENC_SO_m20_OrganizationURL) */

/* Called by: */
struct zx_str* zx_EASY_ENC_SO_m20_OrganizationURL(struct zx_ctx* c, struct zx_m20_OrganizationURL_s* x )
{
  int len;
  char* buf;
  c->ns_tab = ZX_ALLOC(c, sizeof(zx_ns_tab));
  memcpy(c->ns_tab, zx_ns_tab, sizeof(zx_ns_tab));
  len = zx_LEN_SO_m20_OrganizationURL(c, x );
  buf = ZX_ALLOC(c, len+1);
  return zx_easy_enc_common(c, zx_ENC_SO_m20_OrganizationURL(c, x, buf ), buf, len);
}

/* FUNC(zx_EASY_ENC_WO_m20_OrganizationURL) */

/* Called by: */
struct zx_str* zx_EASY_ENC_WO_m20_OrganizationURL(struct zx_ctx* c, struct zx_m20_OrganizationURL_s* x )
{
  int len;
  char* buf;
  c->ns_tab = ZX_ALLOC(c, sizeof(zx_ns_tab));
  memcpy(c->ns_tab, zx_ns_tab, sizeof(zx_ns_tab));
  len = zx_LEN_WO_m20_OrganizationURL(c, x );
  buf = ZX_ALLOC(c, len+1);
  return zx_easy_enc_common(c, zx_ENC_WO_m20_OrganizationURL(c, x, buf ), buf, len);
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

#define EL_NAME   m20_SPDescriptor
#define EL_STRUCT zx_m20_SPDescriptor_s
#define EL_NS     m20
#define EL_TAG    SPDescriptor

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

/* FUNC(zx_LEN_SO_m20_SPDescriptor) */

/* Compute length of an element (and its subelements). The XML attributes
 * and elements are processed in schema order. */

/* Called by: */
int zx_LEN_SO_m20_SPDescriptor(struct zx_ctx* c, struct zx_m20_SPDescriptor_s* x )
{
  struct zx_ns_s* pop_seen = 0;
  struct zx_elem_s* se MAYBE_UNUSED;
#if 1 /* NORMALMODE */
  /* *** in simple_elem case should output ns prefix from ns node. */
  int len = sizeof("<m20:SPDescriptor")-1 + 1 + sizeof("</m20:SPDescriptor>")-1;
  if (c->inc_ns_len)
    len += zx_len_inc_ns(c, &pop_seen);
  len += zx_len_xmlns_if_not_seen(c, zx_ns_tab+zx_xmlns_ix_m20, &pop_seen);

  len += zx_attr_so_len(x->cacheDuration, sizeof("cacheDuration")-1);
  len += zx_attr_so_len(x->id, sizeof("id")-1);
  len += zx_attr_so_len(x->protocolSupportEnumeration, sizeof("protocolSupportEnumeration")-1);
  len += zx_attr_so_len(x->validUntil, sizeof("validUntil")-1);

#else
  /* root node has no begin tag */
  int len = 0;
#endif
  
  {
      struct zx_m20_KeyDescriptor_s* e;
      for (e = x->KeyDescriptor; e; e = (struct zx_m20_KeyDescriptor_s*)e->gg.g.n)
	  len += zx_LEN_SO_m20_KeyDescriptor(c, e);
  }
  for (se = x->SoapEndpoint; se; se = (struct zx_elem_s*)se->g.n)
    len += zx_LEN_SO_simple_elem(c,se, sizeof("m20:SoapEndpoint")-1, zx_ns_tab+zx_xmlns_ix_m20);
  for (se = x->SingleLogoutServiceURL; se; se = (struct zx_elem_s*)se->g.n)
    len += zx_LEN_SO_simple_elem(c,se, sizeof("m20:SingleLogoutServiceURL")-1, zx_ns_tab+zx_xmlns_ix_m20);
  for (se = x->SingleLogoutServiceReturnURL; se; se = (struct zx_elem_s*)se->g.n)
    len += zx_LEN_SO_simple_elem(c,se, sizeof("m20:SingleLogoutServiceReturnURL")-1, zx_ns_tab+zx_xmlns_ix_m20);
  for (se = x->FederationTerminationServiceURL; se; se = (struct zx_elem_s*)se->g.n)
    len += zx_LEN_SO_simple_elem(c,se, sizeof("m20:FederationTerminationServiceURL")-1, zx_ns_tab+zx_xmlns_ix_m20);
  for (se = x->FederationTerminationServiceReturnURL; se; se = (struct zx_elem_s*)se->g.n)
    len += zx_LEN_SO_simple_elem(c,se, sizeof("m20:FederationTerminationServiceReturnURL")-1, zx_ns_tab+zx_xmlns_ix_m20);
  for (se = x->FederationTerminationNotificationProtocolProfile; se; se = (struct zx_elem_s*)se->g.n)
    len += zx_LEN_SO_simple_elem(c,se, sizeof("m20:FederationTerminationNotificationProtocolProfile")-1, zx_ns_tab+zx_xmlns_ix_m20);
  for (se = x->SingleLogoutProtocolProfile; se; se = (struct zx_elem_s*)se->g.n)
    len += zx_LEN_SO_simple_elem(c,se, sizeof("m20:SingleLogoutProtocolProfile")-1, zx_ns_tab+zx_xmlns_ix_m20);
  for (se = x->RegisterNameIdentifierProtocolProfile; se; se = (struct zx_elem_s*)se->g.n)
    len += zx_LEN_SO_simple_elem(c,se, sizeof("m20:RegisterNameIdentifierProtocolProfile")-1, zx_ns_tab+zx_xmlns_ix_m20);
  for (se = x->RegisterNameIdentifierServiceURL; se; se = (struct zx_elem_s*)se->g.n)
    len += zx_LEN_SO_simple_elem(c,se, sizeof("m20:RegisterNameIdentifierServiceURL")-1, zx_ns_tab+zx_xmlns_ix_m20);
  for (se = x->RegisterNameIdentifierServiceReturnURL; se; se = (struct zx_elem_s*)se->g.n)
    len += zx_LEN_SO_simple_elem(c,se, sizeof("m20:RegisterNameIdentifierServiceReturnURL")-1, zx_ns_tab+zx_xmlns_ix_m20);
  for (se = x->NameIdentifierMappingProtocolProfile; se; se = (struct zx_elem_s*)se->g.n)
    len += zx_LEN_SO_simple_elem(c,se, sizeof("m20:NameIdentifierMappingProtocolProfile")-1, zx_ns_tab+zx_xmlns_ix_m20);
  for (se = x->NameIdentifierMappingEncryptionProfile; se; se = (struct zx_elem_s*)se->g.n)
    len += zx_LEN_SO_simple_elem(c,se, sizeof("m20:NameIdentifierMappingEncryptionProfile")-1, zx_ns_tab+zx_xmlns_ix_m20);
  {
      struct zx_m20_Organization_s* e;
      for (e = x->Organization; e; e = (struct zx_m20_Organization_s*)e->gg.g.n)
	  len += zx_LEN_SO_m20_Organization(c, e);
  }
  {
      struct zx_m20_ContactPerson_s* e;
      for (e = x->ContactPerson; e; e = (struct zx_m20_ContactPerson_s*)e->gg.g.n)
	  len += zx_LEN_SO_m20_ContactPerson(c, e);
  }
  {
      struct zx_m20_AdditionalMetaLocation_s* e;
      for (e = x->AdditionalMetaLocation; e; e = (struct zx_m20_AdditionalMetaLocation_s*)e->gg.g.n)
	  len += zx_LEN_SO_m20_AdditionalMetaLocation(c, e);
  }
  {
      struct zx_m20_Extension_s* e;
      for (e = x->Extension; e; e = (struct zx_m20_Extension_s*)e->gg.g.n)
	  len += zx_LEN_SO_m20_Extension(c, e);
  }
  {
      struct zx_ds_Signature_s* e;
      for (e = x->Signature; e; e = (struct zx_ds_Signature_s*)e->gg.g.n)
	  if (e != c->exclude_sig)
              len += zx_LEN_SO_ds_Signature(c, e);
  }
  {
      struct zx_m20_AssertionConsumerServiceURL_s* e;
      for (e = x->AssertionConsumerServiceURL; e; e = (struct zx_m20_AssertionConsumerServiceURL_s*)e->gg.g.n)
	  len += zx_LEN_SO_m20_AssertionConsumerServiceURL(c, e);
  }
  for (se = x->AuthnRequestsSigned; se; se = (struct zx_elem_s*)se->g.n)
    len += zx_LEN_SO_simple_elem(c,se, sizeof("m20:AuthnRequestsSigned")-1, zx_ns_tab+zx_xmlns_ix_m20);


  len += zx_len_so_common(c, &x->gg);
  zx_pop_seen(pop_seen);
  ENC_LEN_DEBUG(x, "m20:SPDescriptor", len);
  return len;
}

/* FUNC(zx_LEN_WO_m20_SPDescriptor) */

/* Compute length of an element (and its subelements). The XML attributes
 * and elements are processed in wire order and no assumptions
 * are made about namespace prefixes. */

/* Called by: */
int zx_LEN_WO_m20_SPDescriptor(struct zx_ctx* c, struct zx_m20_SPDescriptor_s* x )
{
  struct zx_ns_s* pop_seen = 0;
  struct zx_elem_s* se MAYBE_UNUSED;
#if 1 /* NORMALMODE */
  int len = 1 + sizeof("SPDescriptor")-1 + 1 + 2 + sizeof("SPDescriptor")-1 + 1;
  
  if (x->gg.g.ns && x->gg.g.ns->prefix_len)
    len += (x->gg.g.ns->prefix_len + 1) * 2;
  if (c->inc_ns_len)
    len += zx_len_inc_ns(c, &pop_seen);
  len += zx_len_xmlns_if_not_seen(c, x->gg.g.ns, &pop_seen);

  len += zx_attr_wo_len(x->cacheDuration, sizeof("cacheDuration")-1);
  len += zx_attr_wo_len(x->id, sizeof("id")-1);
  len += zx_attr_wo_len(x->protocolSupportEnumeration, sizeof("protocolSupportEnumeration")-1);
  len += zx_attr_wo_len(x->validUntil, sizeof("validUntil")-1);

#else
  /* root node has no begin tag */
  int len = 0;
#endif
  
  {
      struct zx_m20_KeyDescriptor_s* e;
      for (e = x->KeyDescriptor; e; e = (struct zx_m20_KeyDescriptor_s*)e->gg.g.n)
	  len += zx_LEN_WO_m20_KeyDescriptor(c, e);
  }
  for (se = x->SoapEndpoint; se; se = (struct zx_elem_s*)se->g.n)
    len += zx_LEN_WO_simple_elem(c, se, sizeof("SoapEndpoint")-1);
  for (se = x->SingleLogoutServiceURL; se; se = (struct zx_elem_s*)se->g.n)
    len += zx_LEN_WO_simple_elem(c, se, sizeof("SingleLogoutServiceURL")-1);
  for (se = x->SingleLogoutServiceReturnURL; se; se = (struct zx_elem_s*)se->g.n)
    len += zx_LEN_WO_simple_elem(c, se, sizeof("SingleLogoutServiceReturnURL")-1);
  for (se = x->FederationTerminationServiceURL; se; se = (struct zx_elem_s*)se->g.n)
    len += zx_LEN_WO_simple_elem(c, se, sizeof("FederationTerminationServiceURL")-1);
  for (se = x->FederationTerminationServiceReturnURL; se; se = (struct zx_elem_s*)se->g.n)
    len += zx_LEN_WO_simple_elem(c, se, sizeof("FederationTerminationServiceReturnURL")-1);
  for (se = x->FederationTerminationNotificationProtocolProfile; se; se = (struct zx_elem_s*)se->g.n)
    len += zx_LEN_WO_simple_elem(c, se, sizeof("FederationTerminationNotificationProtocolProfile")-1);
  for (se = x->SingleLogoutProtocolProfile; se; se = (struct zx_elem_s*)se->g.n)
    len += zx_LEN_WO_simple_elem(c, se, sizeof("SingleLogoutProtocolProfile")-1);
  for (se = x->RegisterNameIdentifierProtocolProfile; se; se = (struct zx_elem_s*)se->g.n)
    len += zx_LEN_WO_simple_elem(c, se, sizeof("RegisterNameIdentifierProtocolProfile")-1);
  for (se = x->RegisterNameIdentifierServiceURL; se; se = (struct zx_elem_s*)se->g.n)
    len += zx_LEN_WO_simple_elem(c, se, sizeof("RegisterNameIdentifierServiceURL")-1);
  for (se = x->RegisterNameIdentifierServiceReturnURL; se; se = (struct zx_elem_s*)se->g.n)
    len += zx_LEN_WO_simple_elem(c, se, sizeof("RegisterNameIdentifierServiceReturnURL")-1);
  for (se = x->NameIdentifierMappingProtocolProfile; se; se = (struct zx_elem_s*)se->g.n)
    len += zx_LEN_WO_simple_elem(c, se, sizeof("NameIdentifierMappingProtocolProfile")-1);
  for (se = x->NameIdentifierMappingEncryptionProfile; se; se = (struct zx_elem_s*)se->g.n)
    len += zx_LEN_WO_simple_elem(c, se, sizeof("NameIdentifierMappingEncryptionProfile")-1);
  {
      struct zx_m20_Organization_s* e;
      for (e = x->Organization; e; e = (struct zx_m20_Organization_s*)e->gg.g.n)
	  len += zx_LEN_WO_m20_Organization(c, e);
  }
  {
      struct zx_m20_ContactPerson_s* e;
      for (e = x->ContactPerson; e; e = (struct zx_m20_ContactPerson_s*)e->gg.g.n)
	  len += zx_LEN_WO_m20_ContactPerson(c, e);
  }
  {
      struct zx_m20_AdditionalMetaLocation_s* e;
      for (e = x->AdditionalMetaLocation; e; e = (struct zx_m20_AdditionalMetaLocation_s*)e->gg.g.n)
	  len += zx_LEN_WO_m20_AdditionalMetaLocation(c, e);
  }
  {
      struct zx_m20_Extension_s* e;
      for (e = x->Extension; e; e = (struct zx_m20_Extension_s*)e->gg.g.n)
	  len += zx_LEN_WO_m20_Extension(c, e);
  }
  {
      struct zx_ds_Signature_s* e;
      for (e = x->Signature; e; e = (struct zx_ds_Signature_s*)e->gg.g.n)
	  if (e != c->exclude_sig)
              len += zx_LEN_WO_ds_Signature(c, e);
  }
  {
      struct zx_m20_AssertionConsumerServiceURL_s* e;
      for (e = x->AssertionConsumerServiceURL; e; e = (struct zx_m20_AssertionConsumerServiceURL_s*)e->gg.g.n)
	  len += zx_LEN_WO_m20_AssertionConsumerServiceURL(c, e);
  }
  for (se = x->AuthnRequestsSigned; se; se = (struct zx_elem_s*)se->g.n)
    len += zx_LEN_WO_simple_elem(c, se, sizeof("AuthnRequestsSigned")-1);


  len += zx_len_wo_common(c, &x->gg); 
  zx_pop_seen(pop_seen);
  ENC_LEN_DEBUG(x, "m20:SPDescriptor", len);
  return len;
}

/* FUNC(zx_ENC_SO_m20_SPDescriptor) */

/* Render element into string. The XML attributes and elements are
 * processed in schema order. This is what you generally want for
 * rendering new data structure to a string. The wo pointers are not used. */

/* Called by: */
char* zx_ENC_SO_m20_SPDescriptor(struct zx_ctx* c, struct zx_m20_SPDescriptor_s* x, char* p )
{
  struct zx_elem_s* se MAYBE_UNUSED;
  struct zx_ns_s* pop_seen = 0;
  ENC_LEN_DEBUG_BASE;
#if 1 /* NORMALMODE */
  /* *** in simple_elem case should output ns prefix from ns node. */
  ZX_OUT_TAG(p, "<m20:SPDescriptor");
  if (c->inc_ns)
    p = zx_enc_inc_ns(c, p, &pop_seen);
  p = zx_enc_xmlns_if_not_seen(c, p, zx_ns_tab+zx_xmlns_ix_m20, &pop_seen);

  p = zx_attr_so_enc(p, x->cacheDuration, " cacheDuration=\"", sizeof(" cacheDuration=\"")-1);
  p = zx_attr_so_enc(p, x->id, " id=\"", sizeof(" id=\"")-1);
  p = zx_attr_so_enc(p, x->protocolSupportEnumeration, " protocolSupportEnumeration=\"", sizeof(" protocolSupportEnumeration=\"")-1);
  p = zx_attr_so_enc(p, x->validUntil, " validUntil=\"", sizeof(" validUntil=\"")-1);

  p = zx_enc_unknown_attrs(p, x->gg.any_attr);
#else
  /* root node has no begin tag */
#endif
  
  {
      struct zx_m20_KeyDescriptor_s* e;
      for (e = x->KeyDescriptor; e; e = (struct zx_m20_KeyDescriptor_s*)e->gg.g.n)
	  p = zx_ENC_SO_m20_KeyDescriptor(c, e, p);
  }
  for (se = x->SoapEndpoint; se; se = (struct zx_elem_s*)se->g.n)
    p = zx_ENC_SO_simple_elem(c, se, p, "m20:SoapEndpoint", sizeof("m20:SoapEndpoint")-1, zx_ns_tab+zx_xmlns_ix_m20);
  for (se = x->SingleLogoutServiceURL; se; se = (struct zx_elem_s*)se->g.n)
    p = zx_ENC_SO_simple_elem(c, se, p, "m20:SingleLogoutServiceURL", sizeof("m20:SingleLogoutServiceURL")-1, zx_ns_tab+zx_xmlns_ix_m20);
  for (se = x->SingleLogoutServiceReturnURL; se; se = (struct zx_elem_s*)se->g.n)
    p = zx_ENC_SO_simple_elem(c, se, p, "m20:SingleLogoutServiceReturnURL", sizeof("m20:SingleLogoutServiceReturnURL")-1, zx_ns_tab+zx_xmlns_ix_m20);
  for (se = x->FederationTerminationServiceURL; se; se = (struct zx_elem_s*)se->g.n)
    p = zx_ENC_SO_simple_elem(c, se, p, "m20:FederationTerminationServiceURL", sizeof("m20:FederationTerminationServiceURL")-1, zx_ns_tab+zx_xmlns_ix_m20);
  for (se = x->FederationTerminationServiceReturnURL; se; se = (struct zx_elem_s*)se->g.n)
    p = zx_ENC_SO_simple_elem(c, se, p, "m20:FederationTerminationServiceReturnURL", sizeof("m20:FederationTerminationServiceReturnURL")-1, zx_ns_tab+zx_xmlns_ix_m20);
  for (se = x->FederationTerminationNotificationProtocolProfile; se; se = (struct zx_elem_s*)se->g.n)
    p = zx_ENC_SO_simple_elem(c, se, p, "m20:FederationTerminationNotificationProtocolProfile", sizeof("m20:FederationTerminationNotificationProtocolProfile")-1, zx_ns_tab+zx_xmlns_ix_m20);
  for (se = x->SingleLogoutProtocolProfile; se; se = (struct zx_elem_s*)se->g.n)
    p = zx_ENC_SO_simple_elem(c, se, p, "m20:SingleLogoutProtocolProfile", sizeof("m20:SingleLogoutProtocolProfile")-1, zx_ns_tab+zx_xmlns_ix_m20);
  for (se = x->RegisterNameIdentifierProtocolProfile; se; se = (struct zx_elem_s*)se->g.n)
    p = zx_ENC_SO_simple_elem(c, se, p, "m20:RegisterNameIdentifierProtocolProfile", sizeof("m20:RegisterNameIdentifierProtocolProfile")-1, zx_ns_tab+zx_xmlns_ix_m20);
  for (se = x->RegisterNameIdentifierServiceURL; se; se = (struct zx_elem_s*)se->g.n)
    p = zx_ENC_SO_simple_elem(c, se, p, "m20:RegisterNameIdentifierServiceURL", sizeof("m20:RegisterNameIdentifierServiceURL")-1, zx_ns_tab+zx_xmlns_ix_m20);
  for (se = x->RegisterNameIdentifierServiceReturnURL; se; se = (struct zx_elem_s*)se->g.n)
    p = zx_ENC_SO_simple_elem(c, se, p, "m20:RegisterNameIdentifierServiceReturnURL", sizeof("m20:RegisterNameIdentifierServiceReturnURL")-1, zx_ns_tab+zx_xmlns_ix_m20);
  for (se = x->NameIdentifierMappingProtocolProfile; se; se = (struct zx_elem_s*)se->g.n)
    p = zx_ENC_SO_simple_elem(c, se, p, "m20:NameIdentifierMappingProtocolProfile", sizeof("m20:NameIdentifierMappingProtocolProfile")-1, zx_ns_tab+zx_xmlns_ix_m20);
  for (se = x->NameIdentifierMappingEncryptionProfile; se; se = (struct zx_elem_s*)se->g.n)
    p = zx_ENC_SO_simple_elem(c, se, p, "m20:NameIdentifierMappingEncryptionProfile", sizeof("m20:NameIdentifierMappingEncryptionProfile")-1, zx_ns_tab+zx_xmlns_ix_m20);
  {
      struct zx_m20_Organization_s* e;
      for (e = x->Organization; e; e = (struct zx_m20_Organization_s*)e->gg.g.n)
	  p = zx_ENC_SO_m20_Organization(c, e, p);
  }
  {
      struct zx_m20_ContactPerson_s* e;
      for (e = x->ContactPerson; e; e = (struct zx_m20_ContactPerson_s*)e->gg.g.n)
	  p = zx_ENC_SO_m20_ContactPerson(c, e, p);
  }
  {
      struct zx_m20_AdditionalMetaLocation_s* e;
      for (e = x->AdditionalMetaLocation; e; e = (struct zx_m20_AdditionalMetaLocation_s*)e->gg.g.n)
	  p = zx_ENC_SO_m20_AdditionalMetaLocation(c, e, p);
  }
  {
      struct zx_m20_Extension_s* e;
      for (e = x->Extension; e; e = (struct zx_m20_Extension_s*)e->gg.g.n)
	  p = zx_ENC_SO_m20_Extension(c, e, p);
  }
  {
      struct zx_ds_Signature_s* e;
      for (e = x->Signature; e; e = (struct zx_ds_Signature_s*)e->gg.g.n)
	  if (e != c->exclude_sig)
              p = zx_ENC_SO_ds_Signature(c, e, p);
  }
  {
      struct zx_m20_AssertionConsumerServiceURL_s* e;
      for (e = x->AssertionConsumerServiceURL; e; e = (struct zx_m20_AssertionConsumerServiceURL_s*)e->gg.g.n)
	  p = zx_ENC_SO_m20_AssertionConsumerServiceURL(c, e, p);
  }
  for (se = x->AuthnRequestsSigned; se; se = (struct zx_elem_s*)se->g.n)
    p = zx_ENC_SO_simple_elem(c, se, p, "m20:AuthnRequestsSigned", sizeof("m20:AuthnRequestsSigned")-1, zx_ns_tab+zx_xmlns_ix_m20);

  p = zx_enc_so_unknown_elems_and_content(c, p, &x->gg);
  
#if 1 /* NORMALMODE */
  ZX_OUT_CLOSE_TAG(p, "</m20:SPDescriptor>");
  zx_pop_seen(pop_seen);
#else
  /* root node has no end tag either */
#endif
  ENC_LEN_DEBUG(x, "m20:SPDescriptor", p-enc_base);
  return p;
}

/* FUNC(zx_ENC_WO_m20_SPDescriptor) */

/* Render element into string. The XML attributes and elements are
 * processed in wire order by chasing wo pointers. This is what you want for
 * validating signatures on other people's XML documents. */

/* Called by: */
char* zx_ENC_WO_m20_SPDescriptor(struct zx_ctx* c, struct zx_m20_SPDescriptor_s* x, char* p )
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
  ZX_OUT_MEM(p, "SPDescriptor", sizeof("SPDescriptor")-1);
  qq = p;

  /* *** sort the namespaces */
  if (c->inc_ns)
    zx_add_inc_ns(c, &pop_seen);
  zx_add_xmlns_if_not_seen(c, x->gg.g.ns, &pop_seen);

  p = zx_enc_seen(p, pop_seen); 
  p = zx_attr_wo_enc(p, x->cacheDuration, "cacheDuration=\"", sizeof("cacheDuration=\"")-1);
  p = zx_attr_wo_enc(p, x->id, "id=\"", sizeof("id=\"")-1);
  p = zx_attr_wo_enc(p, x->protocolSupportEnumeration, "protocolSupportEnumeration=\"", sizeof("protocolSupportEnumeration=\"")-1);
  p = zx_attr_wo_enc(p, x->validUntil, "validUntil=\"", sizeof("validUntil=\"")-1);

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
  ENC_LEN_DEBUG(x, "m20:SPDescriptor", p-enc_base);
  return p;
}

/* FUNC(zx_EASY_ENC_SO_m20_SPDescriptor) */

/* Called by: */
struct zx_str* zx_EASY_ENC_SO_m20_SPDescriptor(struct zx_ctx* c, struct zx_m20_SPDescriptor_s* x )
{
  int len;
  char* buf;
  c->ns_tab = ZX_ALLOC(c, sizeof(zx_ns_tab));
  memcpy(c->ns_tab, zx_ns_tab, sizeof(zx_ns_tab));
  len = zx_LEN_SO_m20_SPDescriptor(c, x );
  buf = ZX_ALLOC(c, len+1);
  return zx_easy_enc_common(c, zx_ENC_SO_m20_SPDescriptor(c, x, buf ), buf, len);
}

/* FUNC(zx_EASY_ENC_WO_m20_SPDescriptor) */

/* Called by: */
struct zx_str* zx_EASY_ENC_WO_m20_SPDescriptor(struct zx_ctx* c, struct zx_m20_SPDescriptor_s* x )
{
  int len;
  char* buf;
  c->ns_tab = ZX_ALLOC(c, sizeof(zx_ns_tab));
  memcpy(c->ns_tab, zx_ns_tab, sizeof(zx_ns_tab));
  len = zx_LEN_WO_m20_SPDescriptor(c, x );
  buf = ZX_ALLOC(c, len+1);
  return zx_easy_enc_common(c, zx_ENC_WO_m20_SPDescriptor(c, x, buf ), buf, len);
}




/* EOF -- c/zx-m20-enc.c */
