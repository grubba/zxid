/* c/zx-md-enc.c - WARNING: This file was automatically generated. DO NOT EDIT!
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
#include "c/zx-md-data.h"
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

#define EL_NAME   md_AdditionalMetadataLocation
#define EL_STRUCT zx_md_AdditionalMetadataLocation_s
#define EL_NS     md
#define EL_TAG    AdditionalMetadataLocation

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

/* FUNC(zx_LEN_SO_md_AdditionalMetadataLocation) */

/* Compute length of an element (and its subelements). The XML attributes
 * and elements are processed in schema order. */

/* Called by: */
int zx_LEN_SO_md_AdditionalMetadataLocation(struct zx_ctx* c, struct zx_md_AdditionalMetadataLocation_s* x )
{
  struct zx_ns_s* pop_seen = 0;
  struct zx_elem_s* se MAYBE_UNUSED;
#if 1 /* NORMALMODE */
  /* *** in simple_elem case should output ns prefix from ns node. */
  int len = sizeof("<md:AdditionalMetadataLocation")-1 + 1 + sizeof("</md:AdditionalMetadataLocation>")-1;
  if (c->inc_ns_len)
    len += zx_len_inc_ns(c, &pop_seen);
  len += zx_len_xmlns_if_not_seen(c, zx_ns_tab+zx_xmlns_ix_md, &pop_seen);

  len += zx_attr_so_len(x->namespace_is_cxx_keyword, sizeof("namespace")-1);

#else
  /* root node has no begin tag */
  int len = 0;
#endif
  


  len += zx_len_so_common(c, &x->gg);
  zx_pop_seen(pop_seen);
  ENC_LEN_DEBUG(x, "md:AdditionalMetadataLocation", len);
  return len;
}

/* FUNC(zx_LEN_WO_md_AdditionalMetadataLocation) */

/* Compute length of an element (and its subelements). The XML attributes
 * and elements are processed in wire order and no assumptions
 * are made about namespace prefixes. */

/* Called by: */
int zx_LEN_WO_md_AdditionalMetadataLocation(struct zx_ctx* c, struct zx_md_AdditionalMetadataLocation_s* x )
{
  struct zx_ns_s* pop_seen = 0;
  struct zx_elem_s* se MAYBE_UNUSED;
#if 1 /* NORMALMODE */
  int len = 1 + sizeof("AdditionalMetadataLocation")-1 + 1 + 2 + sizeof("AdditionalMetadataLocation")-1 + 1;
  
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
  ENC_LEN_DEBUG(x, "md:AdditionalMetadataLocation", len);
  return len;
}

/* FUNC(zx_ENC_SO_md_AdditionalMetadataLocation) */

/* Render element into string. The XML attributes and elements are
 * processed in schema order. This is what you generally want for
 * rendering new data structure to a string. The wo pointers are not used. */

/* Called by: */
char* zx_ENC_SO_md_AdditionalMetadataLocation(struct zx_ctx* c, struct zx_md_AdditionalMetadataLocation_s* x, char* p )
{
  struct zx_elem_s* se MAYBE_UNUSED;
  struct zx_ns_s* pop_seen = 0;
  ENC_LEN_DEBUG_BASE;
#if 1 /* NORMALMODE */
  /* *** in simple_elem case should output ns prefix from ns node. */
  ZX_OUT_TAG(p, "<md:AdditionalMetadataLocation");
  if (c->inc_ns)
    p = zx_enc_inc_ns(c, p, &pop_seen);
  p = zx_enc_xmlns_if_not_seen(c, p, zx_ns_tab+zx_xmlns_ix_md, &pop_seen);

  p = zx_attr_so_enc(p, x->namespace_is_cxx_keyword, " namespace=\"", sizeof(" namespace=\"")-1);

  p = zx_enc_unknown_attrs(p, x->gg.any_attr);
#else
  /* root node has no begin tag */
#endif
  

  p = zx_enc_so_unknown_elems_and_content(c, p, &x->gg);
  
#if 1 /* NORMALMODE */
  ZX_OUT_CLOSE_TAG(p, "</md:AdditionalMetadataLocation>");
  zx_pop_seen(pop_seen);
#else
  /* root node has no end tag either */
#endif
  ENC_LEN_DEBUG(x, "md:AdditionalMetadataLocation", p-enc_base);
  return p;
}

/* FUNC(zx_ENC_WO_md_AdditionalMetadataLocation) */

/* Render element into string. The XML attributes and elements are
 * processed in wire order by chasing wo pointers. This is what you want for
 * validating signatures on other people's XML documents. */

/* Called by: */
char* zx_ENC_WO_md_AdditionalMetadataLocation(struct zx_ctx* c, struct zx_md_AdditionalMetadataLocation_s* x, char* p )
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
  ZX_OUT_MEM(p, "AdditionalMetadataLocation", sizeof("AdditionalMetadataLocation")-1);
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
  ENC_LEN_DEBUG(x, "md:AdditionalMetadataLocation", p-enc_base);
  return p;
}

/* FUNC(zx_EASY_ENC_SO_md_AdditionalMetadataLocation) */

/* Called by: */
struct zx_str* zx_EASY_ENC_SO_md_AdditionalMetadataLocation(struct zx_ctx* c, struct zx_md_AdditionalMetadataLocation_s* x )
{
  int len;
  char* buf;
  c->ns_tab = ZX_ALLOC(c, sizeof(zx_ns_tab));
  memcpy(c->ns_tab, zx_ns_tab, sizeof(zx_ns_tab));
  len = zx_LEN_SO_md_AdditionalMetadataLocation(c, x );
  buf = ZX_ALLOC(c, len+1);
  return zx_easy_enc_common(c, zx_ENC_SO_md_AdditionalMetadataLocation(c, x, buf ), buf, len);
}

/* FUNC(zx_EASY_ENC_WO_md_AdditionalMetadataLocation) */

/* Called by: */
struct zx_str* zx_EASY_ENC_WO_md_AdditionalMetadataLocation(struct zx_ctx* c, struct zx_md_AdditionalMetadataLocation_s* x )
{
  int len;
  char* buf;
  c->ns_tab = ZX_ALLOC(c, sizeof(zx_ns_tab));
  memcpy(c->ns_tab, zx_ns_tab, sizeof(zx_ns_tab));
  len = zx_LEN_WO_md_AdditionalMetadataLocation(c, x );
  buf = ZX_ALLOC(c, len+1);
  return zx_easy_enc_common(c, zx_ENC_WO_md_AdditionalMetadataLocation(c, x, buf ), buf, len);
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

#define EL_NAME   md_AffiliationDescriptor
#define EL_STRUCT zx_md_AffiliationDescriptor_s
#define EL_NS     md
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

/* FUNC(zx_LEN_SO_md_AffiliationDescriptor) */

/* Compute length of an element (and its subelements). The XML attributes
 * and elements are processed in schema order. */

/* Called by: */
int zx_LEN_SO_md_AffiliationDescriptor(struct zx_ctx* c, struct zx_md_AffiliationDescriptor_s* x )
{
  struct zx_ns_s* pop_seen = 0;
  struct zx_elem_s* se MAYBE_UNUSED;
#if 1 /* NORMALMODE */
  /* *** in simple_elem case should output ns prefix from ns node. */
  int len = sizeof("<md:AffiliationDescriptor")-1 + 1 + sizeof("</md:AffiliationDescriptor>")-1;
  if (c->inc_ns_len)
    len += zx_len_inc_ns(c, &pop_seen);
  len += zx_len_xmlns_if_not_seen(c, zx_ns_tab+zx_xmlns_ix_md, &pop_seen);

  len += zx_attr_so_len(x->ID, sizeof("ID")-1);
  len += zx_attr_so_len(x->affiliationOwnerID, sizeof("affiliationOwnerID")-1);
  len += zx_attr_so_len(x->cacheDuration, sizeof("cacheDuration")-1);
  len += zx_attr_so_len(x->validUntil, sizeof("validUntil")-1);

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
      struct zx_md_Extensions_s* e;
      for (e = x->Extensions; e; e = (struct zx_md_Extensions_s*)e->gg.g.n)
	  len += zx_LEN_SO_md_Extensions(c, e);
  }
  for (se = x->AffiliateMember; se; se = (struct zx_elem_s*)se->g.n)
    len += zx_LEN_SO_simple_elem(c,se, sizeof("md:AffiliateMember")-1, zx_ns_tab+zx_xmlns_ix_md);
  {
      struct zx_md_KeyDescriptor_s* e;
      for (e = x->KeyDescriptor; e; e = (struct zx_md_KeyDescriptor_s*)e->gg.g.n)
	  len += zx_LEN_SO_md_KeyDescriptor(c, e);
  }


  len += zx_len_so_common(c, &x->gg);
  zx_pop_seen(pop_seen);
  ENC_LEN_DEBUG(x, "md:AffiliationDescriptor", len);
  return len;
}

/* FUNC(zx_LEN_WO_md_AffiliationDescriptor) */

/* Compute length of an element (and its subelements). The XML attributes
 * and elements are processed in wire order and no assumptions
 * are made about namespace prefixes. */

/* Called by: */
int zx_LEN_WO_md_AffiliationDescriptor(struct zx_ctx* c, struct zx_md_AffiliationDescriptor_s* x )
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

  len += zx_attr_wo_len(x->ID, sizeof("ID")-1);
  len += zx_attr_wo_len(x->affiliationOwnerID, sizeof("affiliationOwnerID")-1);
  len += zx_attr_wo_len(x->cacheDuration, sizeof("cacheDuration")-1);
  len += zx_attr_wo_len(x->validUntil, sizeof("validUntil")-1);

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
      struct zx_md_Extensions_s* e;
      for (e = x->Extensions; e; e = (struct zx_md_Extensions_s*)e->gg.g.n)
	  len += zx_LEN_WO_md_Extensions(c, e);
  }
  for (se = x->AffiliateMember; se; se = (struct zx_elem_s*)se->g.n)
    len += zx_LEN_WO_simple_elem(c, se, sizeof("AffiliateMember")-1);
  {
      struct zx_md_KeyDescriptor_s* e;
      for (e = x->KeyDescriptor; e; e = (struct zx_md_KeyDescriptor_s*)e->gg.g.n)
	  len += zx_LEN_WO_md_KeyDescriptor(c, e);
  }


  len += zx_len_wo_common(c, &x->gg); 
  zx_pop_seen(pop_seen);
  ENC_LEN_DEBUG(x, "md:AffiliationDescriptor", len);
  return len;
}

/* FUNC(zx_ENC_SO_md_AffiliationDescriptor) */

/* Render element into string. The XML attributes and elements are
 * processed in schema order. This is what you generally want for
 * rendering new data structure to a string. The wo pointers are not used. */

/* Called by: */
char* zx_ENC_SO_md_AffiliationDescriptor(struct zx_ctx* c, struct zx_md_AffiliationDescriptor_s* x, char* p )
{
  struct zx_elem_s* se MAYBE_UNUSED;
  struct zx_ns_s* pop_seen = 0;
  ENC_LEN_DEBUG_BASE;
#if 1 /* NORMALMODE */
  /* *** in simple_elem case should output ns prefix from ns node. */
  ZX_OUT_TAG(p, "<md:AffiliationDescriptor");
  if (c->inc_ns)
    p = zx_enc_inc_ns(c, p, &pop_seen);
  p = zx_enc_xmlns_if_not_seen(c, p, zx_ns_tab+zx_xmlns_ix_md, &pop_seen);

  p = zx_attr_so_enc(p, x->ID, " ID=\"", sizeof(" ID=\"")-1);
  p = zx_attr_so_enc(p, x->affiliationOwnerID, " affiliationOwnerID=\"", sizeof(" affiliationOwnerID=\"")-1);
  p = zx_attr_so_enc(p, x->cacheDuration, " cacheDuration=\"", sizeof(" cacheDuration=\"")-1);
  p = zx_attr_so_enc(p, x->validUntil, " validUntil=\"", sizeof(" validUntil=\"")-1);

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
      struct zx_md_Extensions_s* e;
      for (e = x->Extensions; e; e = (struct zx_md_Extensions_s*)e->gg.g.n)
	  p = zx_ENC_SO_md_Extensions(c, e, p);
  }
  for (se = x->AffiliateMember; se; se = (struct zx_elem_s*)se->g.n)
    p = zx_ENC_SO_simple_elem(c, se, p, "md:AffiliateMember", sizeof("md:AffiliateMember")-1, zx_ns_tab+zx_xmlns_ix_md);
  {
      struct zx_md_KeyDescriptor_s* e;
      for (e = x->KeyDescriptor; e; e = (struct zx_md_KeyDescriptor_s*)e->gg.g.n)
	  p = zx_ENC_SO_md_KeyDescriptor(c, e, p);
  }

  p = zx_enc_so_unknown_elems_and_content(c, p, &x->gg);
  
#if 1 /* NORMALMODE */
  ZX_OUT_CLOSE_TAG(p, "</md:AffiliationDescriptor>");
  zx_pop_seen(pop_seen);
#else
  /* root node has no end tag either */
#endif
  ENC_LEN_DEBUG(x, "md:AffiliationDescriptor", p-enc_base);
  return p;
}

/* FUNC(zx_ENC_WO_md_AffiliationDescriptor) */

/* Render element into string. The XML attributes and elements are
 * processed in wire order by chasing wo pointers. This is what you want for
 * validating signatures on other people's XML documents. */

/* Called by: */
char* zx_ENC_WO_md_AffiliationDescriptor(struct zx_ctx* c, struct zx_md_AffiliationDescriptor_s* x, char* p )
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
  p = zx_attr_wo_enc(p, x->ID, "ID=\"", sizeof("ID=\"")-1);
  p = zx_attr_wo_enc(p, x->affiliationOwnerID, "affiliationOwnerID=\"", sizeof("affiliationOwnerID=\"")-1);
  p = zx_attr_wo_enc(p, x->cacheDuration, "cacheDuration=\"", sizeof("cacheDuration=\"")-1);
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
  ENC_LEN_DEBUG(x, "md:AffiliationDescriptor", p-enc_base);
  return p;
}

/* FUNC(zx_EASY_ENC_SO_md_AffiliationDescriptor) */

/* Called by: */
struct zx_str* zx_EASY_ENC_SO_md_AffiliationDescriptor(struct zx_ctx* c, struct zx_md_AffiliationDescriptor_s* x )
{
  int len;
  char* buf;
  c->ns_tab = ZX_ALLOC(c, sizeof(zx_ns_tab));
  memcpy(c->ns_tab, zx_ns_tab, sizeof(zx_ns_tab));
  len = zx_LEN_SO_md_AffiliationDescriptor(c, x );
  buf = ZX_ALLOC(c, len+1);
  return zx_easy_enc_common(c, zx_ENC_SO_md_AffiliationDescriptor(c, x, buf ), buf, len);
}

/* FUNC(zx_EASY_ENC_WO_md_AffiliationDescriptor) */

/* Called by: */
struct zx_str* zx_EASY_ENC_WO_md_AffiliationDescriptor(struct zx_ctx* c, struct zx_md_AffiliationDescriptor_s* x )
{
  int len;
  char* buf;
  c->ns_tab = ZX_ALLOC(c, sizeof(zx_ns_tab));
  memcpy(c->ns_tab, zx_ns_tab, sizeof(zx_ns_tab));
  len = zx_LEN_WO_md_AffiliationDescriptor(c, x );
  buf = ZX_ALLOC(c, len+1);
  return zx_easy_enc_common(c, zx_ENC_WO_md_AffiliationDescriptor(c, x, buf ), buf, len);
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

#define EL_NAME   md_ArtifactResolutionService
#define EL_STRUCT zx_md_ArtifactResolutionService_s
#define EL_NS     md
#define EL_TAG    ArtifactResolutionService

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

/* FUNC(zx_LEN_SO_md_ArtifactResolutionService) */

/* Compute length of an element (and its subelements). The XML attributes
 * and elements are processed in schema order. */

/* Called by: */
int zx_LEN_SO_md_ArtifactResolutionService(struct zx_ctx* c, struct zx_md_ArtifactResolutionService_s* x )
{
  struct zx_ns_s* pop_seen = 0;
  struct zx_elem_s* se MAYBE_UNUSED;
#if 1 /* NORMALMODE */
  /* *** in simple_elem case should output ns prefix from ns node. */
  int len = sizeof("<md:ArtifactResolutionService")-1 + 1 + sizeof("</md:ArtifactResolutionService>")-1;
  if (c->inc_ns_len)
    len += zx_len_inc_ns(c, &pop_seen);
  len += zx_len_xmlns_if_not_seen(c, zx_ns_tab+zx_xmlns_ix_md, &pop_seen);

  len += zx_attr_so_len(x->Binding, sizeof("Binding")-1);
  len += zx_attr_so_len(x->Location, sizeof("Location")-1);
  len += zx_attr_so_len(x->ResponseLocation, sizeof("ResponseLocation")-1);
  len += zx_attr_so_len(x->index, sizeof("index")-1);
  len += zx_attr_so_len(x->isDefault, sizeof("isDefault")-1);

#else
  /* root node has no begin tag */
  int len = 0;
#endif
  


  len += zx_len_so_common(c, &x->gg);
  zx_pop_seen(pop_seen);
  ENC_LEN_DEBUG(x, "md:ArtifactResolutionService", len);
  return len;
}

/* FUNC(zx_LEN_WO_md_ArtifactResolutionService) */

/* Compute length of an element (and its subelements). The XML attributes
 * and elements are processed in wire order and no assumptions
 * are made about namespace prefixes. */

/* Called by: */
int zx_LEN_WO_md_ArtifactResolutionService(struct zx_ctx* c, struct zx_md_ArtifactResolutionService_s* x )
{
  struct zx_ns_s* pop_seen = 0;
  struct zx_elem_s* se MAYBE_UNUSED;
#if 1 /* NORMALMODE */
  int len = 1 + sizeof("ArtifactResolutionService")-1 + 1 + 2 + sizeof("ArtifactResolutionService")-1 + 1;
  
  if (x->gg.g.ns && x->gg.g.ns->prefix_len)
    len += (x->gg.g.ns->prefix_len + 1) * 2;
  if (c->inc_ns_len)
    len += zx_len_inc_ns(c, &pop_seen);
  len += zx_len_xmlns_if_not_seen(c, x->gg.g.ns, &pop_seen);

  len += zx_attr_wo_len(x->Binding, sizeof("Binding")-1);
  len += zx_attr_wo_len(x->Location, sizeof("Location")-1);
  len += zx_attr_wo_len(x->ResponseLocation, sizeof("ResponseLocation")-1);
  len += zx_attr_wo_len(x->index, sizeof("index")-1);
  len += zx_attr_wo_len(x->isDefault, sizeof("isDefault")-1);

#else
  /* root node has no begin tag */
  int len = 0;
#endif
  


  len += zx_len_wo_common(c, &x->gg); 
  zx_pop_seen(pop_seen);
  ENC_LEN_DEBUG(x, "md:ArtifactResolutionService", len);
  return len;
}

/* FUNC(zx_ENC_SO_md_ArtifactResolutionService) */

/* Render element into string. The XML attributes and elements are
 * processed in schema order. This is what you generally want for
 * rendering new data structure to a string. The wo pointers are not used. */

/* Called by: */
char* zx_ENC_SO_md_ArtifactResolutionService(struct zx_ctx* c, struct zx_md_ArtifactResolutionService_s* x, char* p )
{
  struct zx_elem_s* se MAYBE_UNUSED;
  struct zx_ns_s* pop_seen = 0;
  ENC_LEN_DEBUG_BASE;
#if 1 /* NORMALMODE */
  /* *** in simple_elem case should output ns prefix from ns node. */
  ZX_OUT_TAG(p, "<md:ArtifactResolutionService");
  if (c->inc_ns)
    p = zx_enc_inc_ns(c, p, &pop_seen);
  p = zx_enc_xmlns_if_not_seen(c, p, zx_ns_tab+zx_xmlns_ix_md, &pop_seen);

  p = zx_attr_so_enc(p, x->Binding, " Binding=\"", sizeof(" Binding=\"")-1);
  p = zx_attr_so_enc(p, x->Location, " Location=\"", sizeof(" Location=\"")-1);
  p = zx_attr_so_enc(p, x->ResponseLocation, " ResponseLocation=\"", sizeof(" ResponseLocation=\"")-1);
  p = zx_attr_so_enc(p, x->index, " index=\"", sizeof(" index=\"")-1);
  p = zx_attr_so_enc(p, x->isDefault, " isDefault=\"", sizeof(" isDefault=\"")-1);

  p = zx_enc_unknown_attrs(p, x->gg.any_attr);
#else
  /* root node has no begin tag */
#endif
  

  p = zx_enc_so_unknown_elems_and_content(c, p, &x->gg);
  
#if 1 /* NORMALMODE */
  ZX_OUT_CLOSE_TAG(p, "</md:ArtifactResolutionService>");
  zx_pop_seen(pop_seen);
#else
  /* root node has no end tag either */
#endif
  ENC_LEN_DEBUG(x, "md:ArtifactResolutionService", p-enc_base);
  return p;
}

/* FUNC(zx_ENC_WO_md_ArtifactResolutionService) */

/* Render element into string. The XML attributes and elements are
 * processed in wire order by chasing wo pointers. This is what you want for
 * validating signatures on other people's XML documents. */

/* Called by: */
char* zx_ENC_WO_md_ArtifactResolutionService(struct zx_ctx* c, struct zx_md_ArtifactResolutionService_s* x, char* p )
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
  ZX_OUT_MEM(p, "ArtifactResolutionService", sizeof("ArtifactResolutionService")-1);
  qq = p;

  /* *** sort the namespaces */
  if (c->inc_ns)
    zx_add_inc_ns(c, &pop_seen);
  zx_add_xmlns_if_not_seen(c, x->gg.g.ns, &pop_seen);

  p = zx_enc_seen(p, pop_seen); 
  p = zx_attr_wo_enc(p, x->Binding, "Binding=\"", sizeof("Binding=\"")-1);
  p = zx_attr_wo_enc(p, x->Location, "Location=\"", sizeof("Location=\"")-1);
  p = zx_attr_wo_enc(p, x->ResponseLocation, "ResponseLocation=\"", sizeof("ResponseLocation=\"")-1);
  p = zx_attr_wo_enc(p, x->index, "index=\"", sizeof("index=\"")-1);
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
  ENC_LEN_DEBUG(x, "md:ArtifactResolutionService", p-enc_base);
  return p;
}

/* FUNC(zx_EASY_ENC_SO_md_ArtifactResolutionService) */

/* Called by: */
struct zx_str* zx_EASY_ENC_SO_md_ArtifactResolutionService(struct zx_ctx* c, struct zx_md_ArtifactResolutionService_s* x )
{
  int len;
  char* buf;
  c->ns_tab = ZX_ALLOC(c, sizeof(zx_ns_tab));
  memcpy(c->ns_tab, zx_ns_tab, sizeof(zx_ns_tab));
  len = zx_LEN_SO_md_ArtifactResolutionService(c, x );
  buf = ZX_ALLOC(c, len+1);
  return zx_easy_enc_common(c, zx_ENC_SO_md_ArtifactResolutionService(c, x, buf ), buf, len);
}

/* FUNC(zx_EASY_ENC_WO_md_ArtifactResolutionService) */

/* Called by: */
struct zx_str* zx_EASY_ENC_WO_md_ArtifactResolutionService(struct zx_ctx* c, struct zx_md_ArtifactResolutionService_s* x )
{
  int len;
  char* buf;
  c->ns_tab = ZX_ALLOC(c, sizeof(zx_ns_tab));
  memcpy(c->ns_tab, zx_ns_tab, sizeof(zx_ns_tab));
  len = zx_LEN_WO_md_ArtifactResolutionService(c, x );
  buf = ZX_ALLOC(c, len+1);
  return zx_easy_enc_common(c, zx_ENC_WO_md_ArtifactResolutionService(c, x, buf ), buf, len);
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

#define EL_NAME   md_AssertionConsumerService
#define EL_STRUCT zx_md_AssertionConsumerService_s
#define EL_NS     md
#define EL_TAG    AssertionConsumerService

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

/* FUNC(zx_LEN_SO_md_AssertionConsumerService) */

/* Compute length of an element (and its subelements). The XML attributes
 * and elements are processed in schema order. */

/* Called by: */
int zx_LEN_SO_md_AssertionConsumerService(struct zx_ctx* c, struct zx_md_AssertionConsumerService_s* x )
{
  struct zx_ns_s* pop_seen = 0;
  struct zx_elem_s* se MAYBE_UNUSED;
#if 1 /* NORMALMODE */
  /* *** in simple_elem case should output ns prefix from ns node. */
  int len = sizeof("<md:AssertionConsumerService")-1 + 1 + sizeof("</md:AssertionConsumerService>")-1;
  if (c->inc_ns_len)
    len += zx_len_inc_ns(c, &pop_seen);
  len += zx_len_xmlns_if_not_seen(c, zx_ns_tab+zx_xmlns_ix_md, &pop_seen);

  len += zx_attr_so_len(x->Binding, sizeof("Binding")-1);
  len += zx_attr_so_len(x->Location, sizeof("Location")-1);
  len += zx_attr_so_len(x->ResponseLocation, sizeof("ResponseLocation")-1);
  len += zx_attr_so_len(x->index, sizeof("index")-1);
  len += zx_attr_so_len(x->isDefault, sizeof("isDefault")-1);

#else
  /* root node has no begin tag */
  int len = 0;
#endif
  


  len += zx_len_so_common(c, &x->gg);
  zx_pop_seen(pop_seen);
  ENC_LEN_DEBUG(x, "md:AssertionConsumerService", len);
  return len;
}

/* FUNC(zx_LEN_WO_md_AssertionConsumerService) */

/* Compute length of an element (and its subelements). The XML attributes
 * and elements are processed in wire order and no assumptions
 * are made about namespace prefixes. */

/* Called by: */
int zx_LEN_WO_md_AssertionConsumerService(struct zx_ctx* c, struct zx_md_AssertionConsumerService_s* x )
{
  struct zx_ns_s* pop_seen = 0;
  struct zx_elem_s* se MAYBE_UNUSED;
#if 1 /* NORMALMODE */
  int len = 1 + sizeof("AssertionConsumerService")-1 + 1 + 2 + sizeof("AssertionConsumerService")-1 + 1;
  
  if (x->gg.g.ns && x->gg.g.ns->prefix_len)
    len += (x->gg.g.ns->prefix_len + 1) * 2;
  if (c->inc_ns_len)
    len += zx_len_inc_ns(c, &pop_seen);
  len += zx_len_xmlns_if_not_seen(c, x->gg.g.ns, &pop_seen);

  len += zx_attr_wo_len(x->Binding, sizeof("Binding")-1);
  len += zx_attr_wo_len(x->Location, sizeof("Location")-1);
  len += zx_attr_wo_len(x->ResponseLocation, sizeof("ResponseLocation")-1);
  len += zx_attr_wo_len(x->index, sizeof("index")-1);
  len += zx_attr_wo_len(x->isDefault, sizeof("isDefault")-1);

#else
  /* root node has no begin tag */
  int len = 0;
#endif
  


  len += zx_len_wo_common(c, &x->gg); 
  zx_pop_seen(pop_seen);
  ENC_LEN_DEBUG(x, "md:AssertionConsumerService", len);
  return len;
}

/* FUNC(zx_ENC_SO_md_AssertionConsumerService) */

/* Render element into string. The XML attributes and elements are
 * processed in schema order. This is what you generally want for
 * rendering new data structure to a string. The wo pointers are not used. */

/* Called by: */
char* zx_ENC_SO_md_AssertionConsumerService(struct zx_ctx* c, struct zx_md_AssertionConsumerService_s* x, char* p )
{
  struct zx_elem_s* se MAYBE_UNUSED;
  struct zx_ns_s* pop_seen = 0;
  ENC_LEN_DEBUG_BASE;
#if 1 /* NORMALMODE */
  /* *** in simple_elem case should output ns prefix from ns node. */
  ZX_OUT_TAG(p, "<md:AssertionConsumerService");
  if (c->inc_ns)
    p = zx_enc_inc_ns(c, p, &pop_seen);
  p = zx_enc_xmlns_if_not_seen(c, p, zx_ns_tab+zx_xmlns_ix_md, &pop_seen);

  p = zx_attr_so_enc(p, x->Binding, " Binding=\"", sizeof(" Binding=\"")-1);
  p = zx_attr_so_enc(p, x->Location, " Location=\"", sizeof(" Location=\"")-1);
  p = zx_attr_so_enc(p, x->ResponseLocation, " ResponseLocation=\"", sizeof(" ResponseLocation=\"")-1);
  p = zx_attr_so_enc(p, x->index, " index=\"", sizeof(" index=\"")-1);
  p = zx_attr_so_enc(p, x->isDefault, " isDefault=\"", sizeof(" isDefault=\"")-1);

  p = zx_enc_unknown_attrs(p, x->gg.any_attr);
#else
  /* root node has no begin tag */
#endif
  

  p = zx_enc_so_unknown_elems_and_content(c, p, &x->gg);
  
#if 1 /* NORMALMODE */
  ZX_OUT_CLOSE_TAG(p, "</md:AssertionConsumerService>");
  zx_pop_seen(pop_seen);
#else
  /* root node has no end tag either */
#endif
  ENC_LEN_DEBUG(x, "md:AssertionConsumerService", p-enc_base);
  return p;
}

/* FUNC(zx_ENC_WO_md_AssertionConsumerService) */

/* Render element into string. The XML attributes and elements are
 * processed in wire order by chasing wo pointers. This is what you want for
 * validating signatures on other people's XML documents. */

/* Called by: */
char* zx_ENC_WO_md_AssertionConsumerService(struct zx_ctx* c, struct zx_md_AssertionConsumerService_s* x, char* p )
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
  ZX_OUT_MEM(p, "AssertionConsumerService", sizeof("AssertionConsumerService")-1);
  qq = p;

  /* *** sort the namespaces */
  if (c->inc_ns)
    zx_add_inc_ns(c, &pop_seen);
  zx_add_xmlns_if_not_seen(c, x->gg.g.ns, &pop_seen);

  p = zx_enc_seen(p, pop_seen); 
  p = zx_attr_wo_enc(p, x->Binding, "Binding=\"", sizeof("Binding=\"")-1);
  p = zx_attr_wo_enc(p, x->Location, "Location=\"", sizeof("Location=\"")-1);
  p = zx_attr_wo_enc(p, x->ResponseLocation, "ResponseLocation=\"", sizeof("ResponseLocation=\"")-1);
  p = zx_attr_wo_enc(p, x->index, "index=\"", sizeof("index=\"")-1);
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
  ENC_LEN_DEBUG(x, "md:AssertionConsumerService", p-enc_base);
  return p;
}

/* FUNC(zx_EASY_ENC_SO_md_AssertionConsumerService) */

/* Called by: */
struct zx_str* zx_EASY_ENC_SO_md_AssertionConsumerService(struct zx_ctx* c, struct zx_md_AssertionConsumerService_s* x )
{
  int len;
  char* buf;
  c->ns_tab = ZX_ALLOC(c, sizeof(zx_ns_tab));
  memcpy(c->ns_tab, zx_ns_tab, sizeof(zx_ns_tab));
  len = zx_LEN_SO_md_AssertionConsumerService(c, x );
  buf = ZX_ALLOC(c, len+1);
  return zx_easy_enc_common(c, zx_ENC_SO_md_AssertionConsumerService(c, x, buf ), buf, len);
}

/* FUNC(zx_EASY_ENC_WO_md_AssertionConsumerService) */

/* Called by: */
struct zx_str* zx_EASY_ENC_WO_md_AssertionConsumerService(struct zx_ctx* c, struct zx_md_AssertionConsumerService_s* x )
{
  int len;
  char* buf;
  c->ns_tab = ZX_ALLOC(c, sizeof(zx_ns_tab));
  memcpy(c->ns_tab, zx_ns_tab, sizeof(zx_ns_tab));
  len = zx_LEN_WO_md_AssertionConsumerService(c, x );
  buf = ZX_ALLOC(c, len+1);
  return zx_easy_enc_common(c, zx_ENC_WO_md_AssertionConsumerService(c, x, buf ), buf, len);
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

#define EL_NAME   md_AssertionIDRequestService
#define EL_STRUCT zx_md_AssertionIDRequestService_s
#define EL_NS     md
#define EL_TAG    AssertionIDRequestService

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

/* FUNC(zx_LEN_SO_md_AssertionIDRequestService) */

/* Compute length of an element (and its subelements). The XML attributes
 * and elements are processed in schema order. */

/* Called by: */
int zx_LEN_SO_md_AssertionIDRequestService(struct zx_ctx* c, struct zx_md_AssertionIDRequestService_s* x )
{
  struct zx_ns_s* pop_seen = 0;
  struct zx_elem_s* se MAYBE_UNUSED;
#if 1 /* NORMALMODE */
  /* *** in simple_elem case should output ns prefix from ns node. */
  int len = sizeof("<md:AssertionIDRequestService")-1 + 1 + sizeof("</md:AssertionIDRequestService>")-1;
  if (c->inc_ns_len)
    len += zx_len_inc_ns(c, &pop_seen);
  len += zx_len_xmlns_if_not_seen(c, zx_ns_tab+zx_xmlns_ix_md, &pop_seen);

  len += zx_attr_so_len(x->Binding, sizeof("Binding")-1);
  len += zx_attr_so_len(x->Location, sizeof("Location")-1);
  len += zx_attr_so_len(x->ResponseLocation, sizeof("ResponseLocation")-1);
  len += zx_attr_so_len(x->index, sizeof("index")-1);
  len += zx_attr_so_len(x->isDefault, sizeof("isDefault")-1);

#else
  /* root node has no begin tag */
  int len = 0;
#endif
  


  len += zx_len_so_common(c, &x->gg);
  zx_pop_seen(pop_seen);
  ENC_LEN_DEBUG(x, "md:AssertionIDRequestService", len);
  return len;
}

/* FUNC(zx_LEN_WO_md_AssertionIDRequestService) */

/* Compute length of an element (and its subelements). The XML attributes
 * and elements are processed in wire order and no assumptions
 * are made about namespace prefixes. */

/* Called by: */
int zx_LEN_WO_md_AssertionIDRequestService(struct zx_ctx* c, struct zx_md_AssertionIDRequestService_s* x )
{
  struct zx_ns_s* pop_seen = 0;
  struct zx_elem_s* se MAYBE_UNUSED;
#if 1 /* NORMALMODE */
  int len = 1 + sizeof("AssertionIDRequestService")-1 + 1 + 2 + sizeof("AssertionIDRequestService")-1 + 1;
  
  if (x->gg.g.ns && x->gg.g.ns->prefix_len)
    len += (x->gg.g.ns->prefix_len + 1) * 2;
  if (c->inc_ns_len)
    len += zx_len_inc_ns(c, &pop_seen);
  len += zx_len_xmlns_if_not_seen(c, x->gg.g.ns, &pop_seen);

  len += zx_attr_wo_len(x->Binding, sizeof("Binding")-1);
  len += zx_attr_wo_len(x->Location, sizeof("Location")-1);
  len += zx_attr_wo_len(x->ResponseLocation, sizeof("ResponseLocation")-1);
  len += zx_attr_wo_len(x->index, sizeof("index")-1);
  len += zx_attr_wo_len(x->isDefault, sizeof("isDefault")-1);

#else
  /* root node has no begin tag */
  int len = 0;
#endif
  


  len += zx_len_wo_common(c, &x->gg); 
  zx_pop_seen(pop_seen);
  ENC_LEN_DEBUG(x, "md:AssertionIDRequestService", len);
  return len;
}

/* FUNC(zx_ENC_SO_md_AssertionIDRequestService) */

/* Render element into string. The XML attributes and elements are
 * processed in schema order. This is what you generally want for
 * rendering new data structure to a string. The wo pointers are not used. */

/* Called by: */
char* zx_ENC_SO_md_AssertionIDRequestService(struct zx_ctx* c, struct zx_md_AssertionIDRequestService_s* x, char* p )
{
  struct zx_elem_s* se MAYBE_UNUSED;
  struct zx_ns_s* pop_seen = 0;
  ENC_LEN_DEBUG_BASE;
#if 1 /* NORMALMODE */
  /* *** in simple_elem case should output ns prefix from ns node. */
  ZX_OUT_TAG(p, "<md:AssertionIDRequestService");
  if (c->inc_ns)
    p = zx_enc_inc_ns(c, p, &pop_seen);
  p = zx_enc_xmlns_if_not_seen(c, p, zx_ns_tab+zx_xmlns_ix_md, &pop_seen);

  p = zx_attr_so_enc(p, x->Binding, " Binding=\"", sizeof(" Binding=\"")-1);
  p = zx_attr_so_enc(p, x->Location, " Location=\"", sizeof(" Location=\"")-1);
  p = zx_attr_so_enc(p, x->ResponseLocation, " ResponseLocation=\"", sizeof(" ResponseLocation=\"")-1);
  p = zx_attr_so_enc(p, x->index, " index=\"", sizeof(" index=\"")-1);
  p = zx_attr_so_enc(p, x->isDefault, " isDefault=\"", sizeof(" isDefault=\"")-1);

  p = zx_enc_unknown_attrs(p, x->gg.any_attr);
#else
  /* root node has no begin tag */
#endif
  

  p = zx_enc_so_unknown_elems_and_content(c, p, &x->gg);
  
#if 1 /* NORMALMODE */
  ZX_OUT_CLOSE_TAG(p, "</md:AssertionIDRequestService>");
  zx_pop_seen(pop_seen);
#else
  /* root node has no end tag either */
#endif
  ENC_LEN_DEBUG(x, "md:AssertionIDRequestService", p-enc_base);
  return p;
}

/* FUNC(zx_ENC_WO_md_AssertionIDRequestService) */

/* Render element into string. The XML attributes and elements are
 * processed in wire order by chasing wo pointers. This is what you want for
 * validating signatures on other people's XML documents. */

/* Called by: */
char* zx_ENC_WO_md_AssertionIDRequestService(struct zx_ctx* c, struct zx_md_AssertionIDRequestService_s* x, char* p )
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
  ZX_OUT_MEM(p, "AssertionIDRequestService", sizeof("AssertionIDRequestService")-1);
  qq = p;

  /* *** sort the namespaces */
  if (c->inc_ns)
    zx_add_inc_ns(c, &pop_seen);
  zx_add_xmlns_if_not_seen(c, x->gg.g.ns, &pop_seen);

  p = zx_enc_seen(p, pop_seen); 
  p = zx_attr_wo_enc(p, x->Binding, "Binding=\"", sizeof("Binding=\"")-1);
  p = zx_attr_wo_enc(p, x->Location, "Location=\"", sizeof("Location=\"")-1);
  p = zx_attr_wo_enc(p, x->ResponseLocation, "ResponseLocation=\"", sizeof("ResponseLocation=\"")-1);
  p = zx_attr_wo_enc(p, x->index, "index=\"", sizeof("index=\"")-1);
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
  ENC_LEN_DEBUG(x, "md:AssertionIDRequestService", p-enc_base);
  return p;
}

/* FUNC(zx_EASY_ENC_SO_md_AssertionIDRequestService) */

/* Called by: */
struct zx_str* zx_EASY_ENC_SO_md_AssertionIDRequestService(struct zx_ctx* c, struct zx_md_AssertionIDRequestService_s* x )
{
  int len;
  char* buf;
  c->ns_tab = ZX_ALLOC(c, sizeof(zx_ns_tab));
  memcpy(c->ns_tab, zx_ns_tab, sizeof(zx_ns_tab));
  len = zx_LEN_SO_md_AssertionIDRequestService(c, x );
  buf = ZX_ALLOC(c, len+1);
  return zx_easy_enc_common(c, zx_ENC_SO_md_AssertionIDRequestService(c, x, buf ), buf, len);
}

/* FUNC(zx_EASY_ENC_WO_md_AssertionIDRequestService) */

/* Called by: */
struct zx_str* zx_EASY_ENC_WO_md_AssertionIDRequestService(struct zx_ctx* c, struct zx_md_AssertionIDRequestService_s* x )
{
  int len;
  char* buf;
  c->ns_tab = ZX_ALLOC(c, sizeof(zx_ns_tab));
  memcpy(c->ns_tab, zx_ns_tab, sizeof(zx_ns_tab));
  len = zx_LEN_WO_md_AssertionIDRequestService(c, x );
  buf = ZX_ALLOC(c, len+1);
  return zx_easy_enc_common(c, zx_ENC_WO_md_AssertionIDRequestService(c, x, buf ), buf, len);
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

#define EL_NAME   md_AttributeAuthorityDescriptor
#define EL_STRUCT zx_md_AttributeAuthorityDescriptor_s
#define EL_NS     md
#define EL_TAG    AttributeAuthorityDescriptor

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

/* FUNC(zx_LEN_SO_md_AttributeAuthorityDescriptor) */

/* Compute length of an element (and its subelements). The XML attributes
 * and elements are processed in schema order. */

/* Called by: */
int zx_LEN_SO_md_AttributeAuthorityDescriptor(struct zx_ctx* c, struct zx_md_AttributeAuthorityDescriptor_s* x )
{
  struct zx_ns_s* pop_seen = 0;
  struct zx_elem_s* se MAYBE_UNUSED;
#if 1 /* NORMALMODE */
  /* *** in simple_elem case should output ns prefix from ns node. */
  int len = sizeof("<md:AttributeAuthorityDescriptor")-1 + 1 + sizeof("</md:AttributeAuthorityDescriptor>")-1;
  if (c->inc_ns_len)
    len += zx_len_inc_ns(c, &pop_seen);
  len += zx_len_xmlns_if_not_seen(c, zx_ns_tab+zx_xmlns_ix_md, &pop_seen);

  len += zx_attr_so_len(x->ID, sizeof("ID")-1);
  len += zx_attr_so_len(x->cacheDuration, sizeof("cacheDuration")-1);
  len += zx_attr_so_len(x->errorURL, sizeof("errorURL")-1);
  len += zx_attr_so_len(x->protocolSupportEnumeration, sizeof("protocolSupportEnumeration")-1);
  len += zx_attr_so_len(x->validUntil, sizeof("validUntil")-1);

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
      struct zx_md_Extensions_s* e;
      for (e = x->Extensions; e; e = (struct zx_md_Extensions_s*)e->gg.g.n)
	  len += zx_LEN_SO_md_Extensions(c, e);
  }
  {
      struct zx_md_KeyDescriptor_s* e;
      for (e = x->KeyDescriptor; e; e = (struct zx_md_KeyDescriptor_s*)e->gg.g.n)
	  len += zx_LEN_SO_md_KeyDescriptor(c, e);
  }
  {
      struct zx_md_Organization_s* e;
      for (e = x->Organization; e; e = (struct zx_md_Organization_s*)e->gg.g.n)
	  len += zx_LEN_SO_md_Organization(c, e);
  }
  {
      struct zx_md_ContactPerson_s* e;
      for (e = x->ContactPerson; e; e = (struct zx_md_ContactPerson_s*)e->gg.g.n)
	  len += zx_LEN_SO_md_ContactPerson(c, e);
  }
  {
      struct zx_md_AttributeService_s* e;
      for (e = x->AttributeService; e; e = (struct zx_md_AttributeService_s*)e->gg.g.n)
	  len += zx_LEN_SO_md_AttributeService(c, e);
  }
  {
      struct zx_md_AssertionIDRequestService_s* e;
      for (e = x->AssertionIDRequestService; e; e = (struct zx_md_AssertionIDRequestService_s*)e->gg.g.n)
	  len += zx_LEN_SO_md_AssertionIDRequestService(c, e);
  }
  for (se = x->NameIDFormat; se; se = (struct zx_elem_s*)se->g.n)
    len += zx_LEN_SO_simple_elem(c,se, sizeof("md:NameIDFormat")-1, zx_ns_tab+zx_xmlns_ix_md);
  for (se = x->AttributeProfile; se; se = (struct zx_elem_s*)se->g.n)
    len += zx_LEN_SO_simple_elem(c,se, sizeof("md:AttributeProfile")-1, zx_ns_tab+zx_xmlns_ix_md);
  {
      struct zx_sa_Attribute_s* e;
      for (e = x->Attribute; e; e = (struct zx_sa_Attribute_s*)e->gg.g.n)
	  len += zx_LEN_SO_sa_Attribute(c, e);
  }


  len += zx_len_so_common(c, &x->gg);
  zx_pop_seen(pop_seen);
  ENC_LEN_DEBUG(x, "md:AttributeAuthorityDescriptor", len);
  return len;
}

/* FUNC(zx_LEN_WO_md_AttributeAuthorityDescriptor) */

/* Compute length of an element (and its subelements). The XML attributes
 * and elements are processed in wire order and no assumptions
 * are made about namespace prefixes. */

/* Called by: */
int zx_LEN_WO_md_AttributeAuthorityDescriptor(struct zx_ctx* c, struct zx_md_AttributeAuthorityDescriptor_s* x )
{
  struct zx_ns_s* pop_seen = 0;
  struct zx_elem_s* se MAYBE_UNUSED;
#if 1 /* NORMALMODE */
  int len = 1 + sizeof("AttributeAuthorityDescriptor")-1 + 1 + 2 + sizeof("AttributeAuthorityDescriptor")-1 + 1;
  
  if (x->gg.g.ns && x->gg.g.ns->prefix_len)
    len += (x->gg.g.ns->prefix_len + 1) * 2;
  if (c->inc_ns_len)
    len += zx_len_inc_ns(c, &pop_seen);
  len += zx_len_xmlns_if_not_seen(c, x->gg.g.ns, &pop_seen);

  len += zx_attr_wo_len(x->ID, sizeof("ID")-1);
  len += zx_attr_wo_len(x->cacheDuration, sizeof("cacheDuration")-1);
  len += zx_attr_wo_len(x->errorURL, sizeof("errorURL")-1);
  len += zx_attr_wo_len(x->protocolSupportEnumeration, sizeof("protocolSupportEnumeration")-1);
  len += zx_attr_wo_len(x->validUntil, sizeof("validUntil")-1);

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
      struct zx_md_Extensions_s* e;
      for (e = x->Extensions; e; e = (struct zx_md_Extensions_s*)e->gg.g.n)
	  len += zx_LEN_WO_md_Extensions(c, e);
  }
  {
      struct zx_md_KeyDescriptor_s* e;
      for (e = x->KeyDescriptor; e; e = (struct zx_md_KeyDescriptor_s*)e->gg.g.n)
	  len += zx_LEN_WO_md_KeyDescriptor(c, e);
  }
  {
      struct zx_md_Organization_s* e;
      for (e = x->Organization; e; e = (struct zx_md_Organization_s*)e->gg.g.n)
	  len += zx_LEN_WO_md_Organization(c, e);
  }
  {
      struct zx_md_ContactPerson_s* e;
      for (e = x->ContactPerson; e; e = (struct zx_md_ContactPerson_s*)e->gg.g.n)
	  len += zx_LEN_WO_md_ContactPerson(c, e);
  }
  {
      struct zx_md_AttributeService_s* e;
      for (e = x->AttributeService; e; e = (struct zx_md_AttributeService_s*)e->gg.g.n)
	  len += zx_LEN_WO_md_AttributeService(c, e);
  }
  {
      struct zx_md_AssertionIDRequestService_s* e;
      for (e = x->AssertionIDRequestService; e; e = (struct zx_md_AssertionIDRequestService_s*)e->gg.g.n)
	  len += zx_LEN_WO_md_AssertionIDRequestService(c, e);
  }
  for (se = x->NameIDFormat; se; se = (struct zx_elem_s*)se->g.n)
    len += zx_LEN_WO_simple_elem(c, se, sizeof("NameIDFormat")-1);
  for (se = x->AttributeProfile; se; se = (struct zx_elem_s*)se->g.n)
    len += zx_LEN_WO_simple_elem(c, se, sizeof("AttributeProfile")-1);
  {
      struct zx_sa_Attribute_s* e;
      for (e = x->Attribute; e; e = (struct zx_sa_Attribute_s*)e->gg.g.n)
	  len += zx_LEN_WO_sa_Attribute(c, e);
  }


  len += zx_len_wo_common(c, &x->gg); 
  zx_pop_seen(pop_seen);
  ENC_LEN_DEBUG(x, "md:AttributeAuthorityDescriptor", len);
  return len;
}

/* FUNC(zx_ENC_SO_md_AttributeAuthorityDescriptor) */

/* Render element into string. The XML attributes and elements are
 * processed in schema order. This is what you generally want for
 * rendering new data structure to a string. The wo pointers are not used. */

/* Called by: */
char* zx_ENC_SO_md_AttributeAuthorityDescriptor(struct zx_ctx* c, struct zx_md_AttributeAuthorityDescriptor_s* x, char* p )
{
  struct zx_elem_s* se MAYBE_UNUSED;
  struct zx_ns_s* pop_seen = 0;
  ENC_LEN_DEBUG_BASE;
#if 1 /* NORMALMODE */
  /* *** in simple_elem case should output ns prefix from ns node. */
  ZX_OUT_TAG(p, "<md:AttributeAuthorityDescriptor");
  if (c->inc_ns)
    p = zx_enc_inc_ns(c, p, &pop_seen);
  p = zx_enc_xmlns_if_not_seen(c, p, zx_ns_tab+zx_xmlns_ix_md, &pop_seen);

  p = zx_attr_so_enc(p, x->ID, " ID=\"", sizeof(" ID=\"")-1);
  p = zx_attr_so_enc(p, x->cacheDuration, " cacheDuration=\"", sizeof(" cacheDuration=\"")-1);
  p = zx_attr_so_enc(p, x->errorURL, " errorURL=\"", sizeof(" errorURL=\"")-1);
  p = zx_attr_so_enc(p, x->protocolSupportEnumeration, " protocolSupportEnumeration=\"", sizeof(" protocolSupportEnumeration=\"")-1);
  p = zx_attr_so_enc(p, x->validUntil, " validUntil=\"", sizeof(" validUntil=\"")-1);

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
      struct zx_md_Extensions_s* e;
      for (e = x->Extensions; e; e = (struct zx_md_Extensions_s*)e->gg.g.n)
	  p = zx_ENC_SO_md_Extensions(c, e, p);
  }
  {
      struct zx_md_KeyDescriptor_s* e;
      for (e = x->KeyDescriptor; e; e = (struct zx_md_KeyDescriptor_s*)e->gg.g.n)
	  p = zx_ENC_SO_md_KeyDescriptor(c, e, p);
  }
  {
      struct zx_md_Organization_s* e;
      for (e = x->Organization; e; e = (struct zx_md_Organization_s*)e->gg.g.n)
	  p = zx_ENC_SO_md_Organization(c, e, p);
  }
  {
      struct zx_md_ContactPerson_s* e;
      for (e = x->ContactPerson; e; e = (struct zx_md_ContactPerson_s*)e->gg.g.n)
	  p = zx_ENC_SO_md_ContactPerson(c, e, p);
  }
  {
      struct zx_md_AttributeService_s* e;
      for (e = x->AttributeService; e; e = (struct zx_md_AttributeService_s*)e->gg.g.n)
	  p = zx_ENC_SO_md_AttributeService(c, e, p);
  }
  {
      struct zx_md_AssertionIDRequestService_s* e;
      for (e = x->AssertionIDRequestService; e; e = (struct zx_md_AssertionIDRequestService_s*)e->gg.g.n)
	  p = zx_ENC_SO_md_AssertionIDRequestService(c, e, p);
  }
  for (se = x->NameIDFormat; se; se = (struct zx_elem_s*)se->g.n)
    p = zx_ENC_SO_simple_elem(c, se, p, "md:NameIDFormat", sizeof("md:NameIDFormat")-1, zx_ns_tab+zx_xmlns_ix_md);
  for (se = x->AttributeProfile; se; se = (struct zx_elem_s*)se->g.n)
    p = zx_ENC_SO_simple_elem(c, se, p, "md:AttributeProfile", sizeof("md:AttributeProfile")-1, zx_ns_tab+zx_xmlns_ix_md);
  {
      struct zx_sa_Attribute_s* e;
      for (e = x->Attribute; e; e = (struct zx_sa_Attribute_s*)e->gg.g.n)
	  p = zx_ENC_SO_sa_Attribute(c, e, p);
  }

  p = zx_enc_so_unknown_elems_and_content(c, p, &x->gg);
  
#if 1 /* NORMALMODE */
  ZX_OUT_CLOSE_TAG(p, "</md:AttributeAuthorityDescriptor>");
  zx_pop_seen(pop_seen);
#else
  /* root node has no end tag either */
#endif
  ENC_LEN_DEBUG(x, "md:AttributeAuthorityDescriptor", p-enc_base);
  return p;
}

/* FUNC(zx_ENC_WO_md_AttributeAuthorityDescriptor) */

/* Render element into string. The XML attributes and elements are
 * processed in wire order by chasing wo pointers. This is what you want for
 * validating signatures on other people's XML documents. */

/* Called by: */
char* zx_ENC_WO_md_AttributeAuthorityDescriptor(struct zx_ctx* c, struct zx_md_AttributeAuthorityDescriptor_s* x, char* p )
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
  ZX_OUT_MEM(p, "AttributeAuthorityDescriptor", sizeof("AttributeAuthorityDescriptor")-1);
  qq = p;

  /* *** sort the namespaces */
  if (c->inc_ns)
    zx_add_inc_ns(c, &pop_seen);
  zx_add_xmlns_if_not_seen(c, x->gg.g.ns, &pop_seen);

  p = zx_enc_seen(p, pop_seen); 
  p = zx_attr_wo_enc(p, x->ID, "ID=\"", sizeof("ID=\"")-1);
  p = zx_attr_wo_enc(p, x->cacheDuration, "cacheDuration=\"", sizeof("cacheDuration=\"")-1);
  p = zx_attr_wo_enc(p, x->errorURL, "errorURL=\"", sizeof("errorURL=\"")-1);
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
  ENC_LEN_DEBUG(x, "md:AttributeAuthorityDescriptor", p-enc_base);
  return p;
}

/* FUNC(zx_EASY_ENC_SO_md_AttributeAuthorityDescriptor) */

/* Called by: */
struct zx_str* zx_EASY_ENC_SO_md_AttributeAuthorityDescriptor(struct zx_ctx* c, struct zx_md_AttributeAuthorityDescriptor_s* x )
{
  int len;
  char* buf;
  c->ns_tab = ZX_ALLOC(c, sizeof(zx_ns_tab));
  memcpy(c->ns_tab, zx_ns_tab, sizeof(zx_ns_tab));
  len = zx_LEN_SO_md_AttributeAuthorityDescriptor(c, x );
  buf = ZX_ALLOC(c, len+1);
  return zx_easy_enc_common(c, zx_ENC_SO_md_AttributeAuthorityDescriptor(c, x, buf ), buf, len);
}

/* FUNC(zx_EASY_ENC_WO_md_AttributeAuthorityDescriptor) */

/* Called by: */
struct zx_str* zx_EASY_ENC_WO_md_AttributeAuthorityDescriptor(struct zx_ctx* c, struct zx_md_AttributeAuthorityDescriptor_s* x )
{
  int len;
  char* buf;
  c->ns_tab = ZX_ALLOC(c, sizeof(zx_ns_tab));
  memcpy(c->ns_tab, zx_ns_tab, sizeof(zx_ns_tab));
  len = zx_LEN_WO_md_AttributeAuthorityDescriptor(c, x );
  buf = ZX_ALLOC(c, len+1);
  return zx_easy_enc_common(c, zx_ENC_WO_md_AttributeAuthorityDescriptor(c, x, buf ), buf, len);
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

#define EL_NAME   md_AttributeConsumingService
#define EL_STRUCT zx_md_AttributeConsumingService_s
#define EL_NS     md
#define EL_TAG    AttributeConsumingService

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

/* FUNC(zx_LEN_SO_md_AttributeConsumingService) */

/* Compute length of an element (and its subelements). The XML attributes
 * and elements are processed in schema order. */

/* Called by: */
int zx_LEN_SO_md_AttributeConsumingService(struct zx_ctx* c, struct zx_md_AttributeConsumingService_s* x )
{
  struct zx_ns_s* pop_seen = 0;
  struct zx_elem_s* se MAYBE_UNUSED;
#if 1 /* NORMALMODE */
  /* *** in simple_elem case should output ns prefix from ns node. */
  int len = sizeof("<md:AttributeConsumingService")-1 + 1 + sizeof("</md:AttributeConsumingService>")-1;
  if (c->inc_ns_len)
    len += zx_len_inc_ns(c, &pop_seen);
  len += zx_len_xmlns_if_not_seen(c, zx_ns_tab+zx_xmlns_ix_md, &pop_seen);

  len += zx_attr_so_len(x->index, sizeof("index")-1);
  len += zx_attr_so_len(x->isDefault, sizeof("isDefault")-1);

#else
  /* root node has no begin tag */
  int len = 0;
#endif
  
  {
      struct zx_md_ServiceName_s* e;
      for (e = x->ServiceName; e; e = (struct zx_md_ServiceName_s*)e->gg.g.n)
	  len += zx_LEN_SO_md_ServiceName(c, e);
  }
  {
      struct zx_md_ServiceDescription_s* e;
      for (e = x->ServiceDescription; e; e = (struct zx_md_ServiceDescription_s*)e->gg.g.n)
	  len += zx_LEN_SO_md_ServiceDescription(c, e);
  }
  {
      struct zx_md_RequestedAttribute_s* e;
      for (e = x->RequestedAttribute; e; e = (struct zx_md_RequestedAttribute_s*)e->gg.g.n)
	  len += zx_LEN_SO_md_RequestedAttribute(c, e);
  }


  len += zx_len_so_common(c, &x->gg);
  zx_pop_seen(pop_seen);
  ENC_LEN_DEBUG(x, "md:AttributeConsumingService", len);
  return len;
}

/* FUNC(zx_LEN_WO_md_AttributeConsumingService) */

/* Compute length of an element (and its subelements). The XML attributes
 * and elements are processed in wire order and no assumptions
 * are made about namespace prefixes. */

/* Called by: */
int zx_LEN_WO_md_AttributeConsumingService(struct zx_ctx* c, struct zx_md_AttributeConsumingService_s* x )
{
  struct zx_ns_s* pop_seen = 0;
  struct zx_elem_s* se MAYBE_UNUSED;
#if 1 /* NORMALMODE */
  int len = 1 + sizeof("AttributeConsumingService")-1 + 1 + 2 + sizeof("AttributeConsumingService")-1 + 1;
  
  if (x->gg.g.ns && x->gg.g.ns->prefix_len)
    len += (x->gg.g.ns->prefix_len + 1) * 2;
  if (c->inc_ns_len)
    len += zx_len_inc_ns(c, &pop_seen);
  len += zx_len_xmlns_if_not_seen(c, x->gg.g.ns, &pop_seen);

  len += zx_attr_wo_len(x->index, sizeof("index")-1);
  len += zx_attr_wo_len(x->isDefault, sizeof("isDefault")-1);

#else
  /* root node has no begin tag */
  int len = 0;
#endif
  
  {
      struct zx_md_ServiceName_s* e;
      for (e = x->ServiceName; e; e = (struct zx_md_ServiceName_s*)e->gg.g.n)
	  len += zx_LEN_WO_md_ServiceName(c, e);
  }
  {
      struct zx_md_ServiceDescription_s* e;
      for (e = x->ServiceDescription; e; e = (struct zx_md_ServiceDescription_s*)e->gg.g.n)
	  len += zx_LEN_WO_md_ServiceDescription(c, e);
  }
  {
      struct zx_md_RequestedAttribute_s* e;
      for (e = x->RequestedAttribute; e; e = (struct zx_md_RequestedAttribute_s*)e->gg.g.n)
	  len += zx_LEN_WO_md_RequestedAttribute(c, e);
  }


  len += zx_len_wo_common(c, &x->gg); 
  zx_pop_seen(pop_seen);
  ENC_LEN_DEBUG(x, "md:AttributeConsumingService", len);
  return len;
}

/* FUNC(zx_ENC_SO_md_AttributeConsumingService) */

/* Render element into string. The XML attributes and elements are
 * processed in schema order. This is what you generally want for
 * rendering new data structure to a string. The wo pointers are not used. */

/* Called by: */
char* zx_ENC_SO_md_AttributeConsumingService(struct zx_ctx* c, struct zx_md_AttributeConsumingService_s* x, char* p )
{
  struct zx_elem_s* se MAYBE_UNUSED;
  struct zx_ns_s* pop_seen = 0;
  ENC_LEN_DEBUG_BASE;
#if 1 /* NORMALMODE */
  /* *** in simple_elem case should output ns prefix from ns node. */
  ZX_OUT_TAG(p, "<md:AttributeConsumingService");
  if (c->inc_ns)
    p = zx_enc_inc_ns(c, p, &pop_seen);
  p = zx_enc_xmlns_if_not_seen(c, p, zx_ns_tab+zx_xmlns_ix_md, &pop_seen);

  p = zx_attr_so_enc(p, x->index, " index=\"", sizeof(" index=\"")-1);
  p = zx_attr_so_enc(p, x->isDefault, " isDefault=\"", sizeof(" isDefault=\"")-1);

  p = zx_enc_unknown_attrs(p, x->gg.any_attr);
#else
  /* root node has no begin tag */
#endif
  
  {
      struct zx_md_ServiceName_s* e;
      for (e = x->ServiceName; e; e = (struct zx_md_ServiceName_s*)e->gg.g.n)
	  p = zx_ENC_SO_md_ServiceName(c, e, p);
  }
  {
      struct zx_md_ServiceDescription_s* e;
      for (e = x->ServiceDescription; e; e = (struct zx_md_ServiceDescription_s*)e->gg.g.n)
	  p = zx_ENC_SO_md_ServiceDescription(c, e, p);
  }
  {
      struct zx_md_RequestedAttribute_s* e;
      for (e = x->RequestedAttribute; e; e = (struct zx_md_RequestedAttribute_s*)e->gg.g.n)
	  p = zx_ENC_SO_md_RequestedAttribute(c, e, p);
  }

  p = zx_enc_so_unknown_elems_and_content(c, p, &x->gg);
  
#if 1 /* NORMALMODE */
  ZX_OUT_CLOSE_TAG(p, "</md:AttributeConsumingService>");
  zx_pop_seen(pop_seen);
#else
  /* root node has no end tag either */
#endif
  ENC_LEN_DEBUG(x, "md:AttributeConsumingService", p-enc_base);
  return p;
}

/* FUNC(zx_ENC_WO_md_AttributeConsumingService) */

/* Render element into string. The XML attributes and elements are
 * processed in wire order by chasing wo pointers. This is what you want for
 * validating signatures on other people's XML documents. */

/* Called by: */
char* zx_ENC_WO_md_AttributeConsumingService(struct zx_ctx* c, struct zx_md_AttributeConsumingService_s* x, char* p )
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
  ZX_OUT_MEM(p, "AttributeConsumingService", sizeof("AttributeConsumingService")-1);
  qq = p;

  /* *** sort the namespaces */
  if (c->inc_ns)
    zx_add_inc_ns(c, &pop_seen);
  zx_add_xmlns_if_not_seen(c, x->gg.g.ns, &pop_seen);

  p = zx_enc_seen(p, pop_seen); 
  p = zx_attr_wo_enc(p, x->index, "index=\"", sizeof("index=\"")-1);
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
  ENC_LEN_DEBUG(x, "md:AttributeConsumingService", p-enc_base);
  return p;
}

/* FUNC(zx_EASY_ENC_SO_md_AttributeConsumingService) */

/* Called by: */
struct zx_str* zx_EASY_ENC_SO_md_AttributeConsumingService(struct zx_ctx* c, struct zx_md_AttributeConsumingService_s* x )
{
  int len;
  char* buf;
  c->ns_tab = ZX_ALLOC(c, sizeof(zx_ns_tab));
  memcpy(c->ns_tab, zx_ns_tab, sizeof(zx_ns_tab));
  len = zx_LEN_SO_md_AttributeConsumingService(c, x );
  buf = ZX_ALLOC(c, len+1);
  return zx_easy_enc_common(c, zx_ENC_SO_md_AttributeConsumingService(c, x, buf ), buf, len);
}

/* FUNC(zx_EASY_ENC_WO_md_AttributeConsumingService) */

/* Called by: */
struct zx_str* zx_EASY_ENC_WO_md_AttributeConsumingService(struct zx_ctx* c, struct zx_md_AttributeConsumingService_s* x )
{
  int len;
  char* buf;
  c->ns_tab = ZX_ALLOC(c, sizeof(zx_ns_tab));
  memcpy(c->ns_tab, zx_ns_tab, sizeof(zx_ns_tab));
  len = zx_LEN_WO_md_AttributeConsumingService(c, x );
  buf = ZX_ALLOC(c, len+1);
  return zx_easy_enc_common(c, zx_ENC_WO_md_AttributeConsumingService(c, x, buf ), buf, len);
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

#define EL_NAME   md_AttributeService
#define EL_STRUCT zx_md_AttributeService_s
#define EL_NS     md
#define EL_TAG    AttributeService

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

/* FUNC(zx_LEN_SO_md_AttributeService) */

/* Compute length of an element (and its subelements). The XML attributes
 * and elements are processed in schema order. */

/* Called by: */
int zx_LEN_SO_md_AttributeService(struct zx_ctx* c, struct zx_md_AttributeService_s* x )
{
  struct zx_ns_s* pop_seen = 0;
  struct zx_elem_s* se MAYBE_UNUSED;
#if 1 /* NORMALMODE */
  /* *** in simple_elem case should output ns prefix from ns node. */
  int len = sizeof("<md:AttributeService")-1 + 1 + sizeof("</md:AttributeService>")-1;
  if (c->inc_ns_len)
    len += zx_len_inc_ns(c, &pop_seen);
  len += zx_len_xmlns_if_not_seen(c, zx_ns_tab+zx_xmlns_ix_md, &pop_seen);

  len += zx_attr_so_len(x->Binding, sizeof("Binding")-1);
  len += zx_attr_so_len(x->Location, sizeof("Location")-1);
  len += zx_attr_so_len(x->ResponseLocation, sizeof("ResponseLocation")-1);
  len += zx_attr_so_len(x->index, sizeof("index")-1);
  len += zx_attr_so_len(x->isDefault, sizeof("isDefault")-1);

#else
  /* root node has no begin tag */
  int len = 0;
#endif
  


  len += zx_len_so_common(c, &x->gg);
  zx_pop_seen(pop_seen);
  ENC_LEN_DEBUG(x, "md:AttributeService", len);
  return len;
}

/* FUNC(zx_LEN_WO_md_AttributeService) */

/* Compute length of an element (and its subelements). The XML attributes
 * and elements are processed in wire order and no assumptions
 * are made about namespace prefixes. */

/* Called by: */
int zx_LEN_WO_md_AttributeService(struct zx_ctx* c, struct zx_md_AttributeService_s* x )
{
  struct zx_ns_s* pop_seen = 0;
  struct zx_elem_s* se MAYBE_UNUSED;
#if 1 /* NORMALMODE */
  int len = 1 + sizeof("AttributeService")-1 + 1 + 2 + sizeof("AttributeService")-1 + 1;
  
  if (x->gg.g.ns && x->gg.g.ns->prefix_len)
    len += (x->gg.g.ns->prefix_len + 1) * 2;
  if (c->inc_ns_len)
    len += zx_len_inc_ns(c, &pop_seen);
  len += zx_len_xmlns_if_not_seen(c, x->gg.g.ns, &pop_seen);

  len += zx_attr_wo_len(x->Binding, sizeof("Binding")-1);
  len += zx_attr_wo_len(x->Location, sizeof("Location")-1);
  len += zx_attr_wo_len(x->ResponseLocation, sizeof("ResponseLocation")-1);
  len += zx_attr_wo_len(x->index, sizeof("index")-1);
  len += zx_attr_wo_len(x->isDefault, sizeof("isDefault")-1);

#else
  /* root node has no begin tag */
  int len = 0;
#endif
  


  len += zx_len_wo_common(c, &x->gg); 
  zx_pop_seen(pop_seen);
  ENC_LEN_DEBUG(x, "md:AttributeService", len);
  return len;
}

/* FUNC(zx_ENC_SO_md_AttributeService) */

/* Render element into string. The XML attributes and elements are
 * processed in schema order. This is what you generally want for
 * rendering new data structure to a string. The wo pointers are not used. */

/* Called by: */
char* zx_ENC_SO_md_AttributeService(struct zx_ctx* c, struct zx_md_AttributeService_s* x, char* p )
{
  struct zx_elem_s* se MAYBE_UNUSED;
  struct zx_ns_s* pop_seen = 0;
  ENC_LEN_DEBUG_BASE;
#if 1 /* NORMALMODE */
  /* *** in simple_elem case should output ns prefix from ns node. */
  ZX_OUT_TAG(p, "<md:AttributeService");
  if (c->inc_ns)
    p = zx_enc_inc_ns(c, p, &pop_seen);
  p = zx_enc_xmlns_if_not_seen(c, p, zx_ns_tab+zx_xmlns_ix_md, &pop_seen);

  p = zx_attr_so_enc(p, x->Binding, " Binding=\"", sizeof(" Binding=\"")-1);
  p = zx_attr_so_enc(p, x->Location, " Location=\"", sizeof(" Location=\"")-1);
  p = zx_attr_so_enc(p, x->ResponseLocation, " ResponseLocation=\"", sizeof(" ResponseLocation=\"")-1);
  p = zx_attr_so_enc(p, x->index, " index=\"", sizeof(" index=\"")-1);
  p = zx_attr_so_enc(p, x->isDefault, " isDefault=\"", sizeof(" isDefault=\"")-1);

  p = zx_enc_unknown_attrs(p, x->gg.any_attr);
#else
  /* root node has no begin tag */
#endif
  

  p = zx_enc_so_unknown_elems_and_content(c, p, &x->gg);
  
#if 1 /* NORMALMODE */
  ZX_OUT_CLOSE_TAG(p, "</md:AttributeService>");
  zx_pop_seen(pop_seen);
#else
  /* root node has no end tag either */
#endif
  ENC_LEN_DEBUG(x, "md:AttributeService", p-enc_base);
  return p;
}

/* FUNC(zx_ENC_WO_md_AttributeService) */

/* Render element into string. The XML attributes and elements are
 * processed in wire order by chasing wo pointers. This is what you want for
 * validating signatures on other people's XML documents. */

/* Called by: */
char* zx_ENC_WO_md_AttributeService(struct zx_ctx* c, struct zx_md_AttributeService_s* x, char* p )
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
  ZX_OUT_MEM(p, "AttributeService", sizeof("AttributeService")-1);
  qq = p;

  /* *** sort the namespaces */
  if (c->inc_ns)
    zx_add_inc_ns(c, &pop_seen);
  zx_add_xmlns_if_not_seen(c, x->gg.g.ns, &pop_seen);

  p = zx_enc_seen(p, pop_seen); 
  p = zx_attr_wo_enc(p, x->Binding, "Binding=\"", sizeof("Binding=\"")-1);
  p = zx_attr_wo_enc(p, x->Location, "Location=\"", sizeof("Location=\"")-1);
  p = zx_attr_wo_enc(p, x->ResponseLocation, "ResponseLocation=\"", sizeof("ResponseLocation=\"")-1);
  p = zx_attr_wo_enc(p, x->index, "index=\"", sizeof("index=\"")-1);
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
  ENC_LEN_DEBUG(x, "md:AttributeService", p-enc_base);
  return p;
}

/* FUNC(zx_EASY_ENC_SO_md_AttributeService) */

/* Called by: */
struct zx_str* zx_EASY_ENC_SO_md_AttributeService(struct zx_ctx* c, struct zx_md_AttributeService_s* x )
{
  int len;
  char* buf;
  c->ns_tab = ZX_ALLOC(c, sizeof(zx_ns_tab));
  memcpy(c->ns_tab, zx_ns_tab, sizeof(zx_ns_tab));
  len = zx_LEN_SO_md_AttributeService(c, x );
  buf = ZX_ALLOC(c, len+1);
  return zx_easy_enc_common(c, zx_ENC_SO_md_AttributeService(c, x, buf ), buf, len);
}

/* FUNC(zx_EASY_ENC_WO_md_AttributeService) */

/* Called by: */
struct zx_str* zx_EASY_ENC_WO_md_AttributeService(struct zx_ctx* c, struct zx_md_AttributeService_s* x )
{
  int len;
  char* buf;
  c->ns_tab = ZX_ALLOC(c, sizeof(zx_ns_tab));
  memcpy(c->ns_tab, zx_ns_tab, sizeof(zx_ns_tab));
  len = zx_LEN_WO_md_AttributeService(c, x );
  buf = ZX_ALLOC(c, len+1);
  return zx_easy_enc_common(c, zx_ENC_WO_md_AttributeService(c, x, buf ), buf, len);
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

#define EL_NAME   md_AuthnAuthorityDescriptor
#define EL_STRUCT zx_md_AuthnAuthorityDescriptor_s
#define EL_NS     md
#define EL_TAG    AuthnAuthorityDescriptor

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

/* FUNC(zx_LEN_SO_md_AuthnAuthorityDescriptor) */

/* Compute length of an element (and its subelements). The XML attributes
 * and elements are processed in schema order. */

/* Called by: */
int zx_LEN_SO_md_AuthnAuthorityDescriptor(struct zx_ctx* c, struct zx_md_AuthnAuthorityDescriptor_s* x )
{
  struct zx_ns_s* pop_seen = 0;
  struct zx_elem_s* se MAYBE_UNUSED;
#if 1 /* NORMALMODE */
  /* *** in simple_elem case should output ns prefix from ns node. */
  int len = sizeof("<md:AuthnAuthorityDescriptor")-1 + 1 + sizeof("</md:AuthnAuthorityDescriptor>")-1;
  if (c->inc_ns_len)
    len += zx_len_inc_ns(c, &pop_seen);
  len += zx_len_xmlns_if_not_seen(c, zx_ns_tab+zx_xmlns_ix_md, &pop_seen);

  len += zx_attr_so_len(x->ID, sizeof("ID")-1);
  len += zx_attr_so_len(x->cacheDuration, sizeof("cacheDuration")-1);
  len += zx_attr_so_len(x->errorURL, sizeof("errorURL")-1);
  len += zx_attr_so_len(x->protocolSupportEnumeration, sizeof("protocolSupportEnumeration")-1);
  len += zx_attr_so_len(x->validUntil, sizeof("validUntil")-1);

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
      struct zx_md_Extensions_s* e;
      for (e = x->Extensions; e; e = (struct zx_md_Extensions_s*)e->gg.g.n)
	  len += zx_LEN_SO_md_Extensions(c, e);
  }
  {
      struct zx_md_KeyDescriptor_s* e;
      for (e = x->KeyDescriptor; e; e = (struct zx_md_KeyDescriptor_s*)e->gg.g.n)
	  len += zx_LEN_SO_md_KeyDescriptor(c, e);
  }
  {
      struct zx_md_Organization_s* e;
      for (e = x->Organization; e; e = (struct zx_md_Organization_s*)e->gg.g.n)
	  len += zx_LEN_SO_md_Organization(c, e);
  }
  {
      struct zx_md_ContactPerson_s* e;
      for (e = x->ContactPerson; e; e = (struct zx_md_ContactPerson_s*)e->gg.g.n)
	  len += zx_LEN_SO_md_ContactPerson(c, e);
  }
  {
      struct zx_md_AuthnQueryService_s* e;
      for (e = x->AuthnQueryService; e; e = (struct zx_md_AuthnQueryService_s*)e->gg.g.n)
	  len += zx_LEN_SO_md_AuthnQueryService(c, e);
  }
  {
      struct zx_md_AssertionIDRequestService_s* e;
      for (e = x->AssertionIDRequestService; e; e = (struct zx_md_AssertionIDRequestService_s*)e->gg.g.n)
	  len += zx_LEN_SO_md_AssertionIDRequestService(c, e);
  }
  for (se = x->NameIDFormat; se; se = (struct zx_elem_s*)se->g.n)
    len += zx_LEN_SO_simple_elem(c,se, sizeof("md:NameIDFormat")-1, zx_ns_tab+zx_xmlns_ix_md);


  len += zx_len_so_common(c, &x->gg);
  zx_pop_seen(pop_seen);
  ENC_LEN_DEBUG(x, "md:AuthnAuthorityDescriptor", len);
  return len;
}

/* FUNC(zx_LEN_WO_md_AuthnAuthorityDescriptor) */

/* Compute length of an element (and its subelements). The XML attributes
 * and elements are processed in wire order and no assumptions
 * are made about namespace prefixes. */

/* Called by: */
int zx_LEN_WO_md_AuthnAuthorityDescriptor(struct zx_ctx* c, struct zx_md_AuthnAuthorityDescriptor_s* x )
{
  struct zx_ns_s* pop_seen = 0;
  struct zx_elem_s* se MAYBE_UNUSED;
#if 1 /* NORMALMODE */
  int len = 1 + sizeof("AuthnAuthorityDescriptor")-1 + 1 + 2 + sizeof("AuthnAuthorityDescriptor")-1 + 1;
  
  if (x->gg.g.ns && x->gg.g.ns->prefix_len)
    len += (x->gg.g.ns->prefix_len + 1) * 2;
  if (c->inc_ns_len)
    len += zx_len_inc_ns(c, &pop_seen);
  len += zx_len_xmlns_if_not_seen(c, x->gg.g.ns, &pop_seen);

  len += zx_attr_wo_len(x->ID, sizeof("ID")-1);
  len += zx_attr_wo_len(x->cacheDuration, sizeof("cacheDuration")-1);
  len += zx_attr_wo_len(x->errorURL, sizeof("errorURL")-1);
  len += zx_attr_wo_len(x->protocolSupportEnumeration, sizeof("protocolSupportEnumeration")-1);
  len += zx_attr_wo_len(x->validUntil, sizeof("validUntil")-1);

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
      struct zx_md_Extensions_s* e;
      for (e = x->Extensions; e; e = (struct zx_md_Extensions_s*)e->gg.g.n)
	  len += zx_LEN_WO_md_Extensions(c, e);
  }
  {
      struct zx_md_KeyDescriptor_s* e;
      for (e = x->KeyDescriptor; e; e = (struct zx_md_KeyDescriptor_s*)e->gg.g.n)
	  len += zx_LEN_WO_md_KeyDescriptor(c, e);
  }
  {
      struct zx_md_Organization_s* e;
      for (e = x->Organization; e; e = (struct zx_md_Organization_s*)e->gg.g.n)
	  len += zx_LEN_WO_md_Organization(c, e);
  }
  {
      struct zx_md_ContactPerson_s* e;
      for (e = x->ContactPerson; e; e = (struct zx_md_ContactPerson_s*)e->gg.g.n)
	  len += zx_LEN_WO_md_ContactPerson(c, e);
  }
  {
      struct zx_md_AuthnQueryService_s* e;
      for (e = x->AuthnQueryService; e; e = (struct zx_md_AuthnQueryService_s*)e->gg.g.n)
	  len += zx_LEN_WO_md_AuthnQueryService(c, e);
  }
  {
      struct zx_md_AssertionIDRequestService_s* e;
      for (e = x->AssertionIDRequestService; e; e = (struct zx_md_AssertionIDRequestService_s*)e->gg.g.n)
	  len += zx_LEN_WO_md_AssertionIDRequestService(c, e);
  }
  for (se = x->NameIDFormat; se; se = (struct zx_elem_s*)se->g.n)
    len += zx_LEN_WO_simple_elem(c, se, sizeof("NameIDFormat")-1);


  len += zx_len_wo_common(c, &x->gg); 
  zx_pop_seen(pop_seen);
  ENC_LEN_DEBUG(x, "md:AuthnAuthorityDescriptor", len);
  return len;
}

/* FUNC(zx_ENC_SO_md_AuthnAuthorityDescriptor) */

/* Render element into string. The XML attributes and elements are
 * processed in schema order. This is what you generally want for
 * rendering new data structure to a string. The wo pointers are not used. */

/* Called by: */
char* zx_ENC_SO_md_AuthnAuthorityDescriptor(struct zx_ctx* c, struct zx_md_AuthnAuthorityDescriptor_s* x, char* p )
{
  struct zx_elem_s* se MAYBE_UNUSED;
  struct zx_ns_s* pop_seen = 0;
  ENC_LEN_DEBUG_BASE;
#if 1 /* NORMALMODE */
  /* *** in simple_elem case should output ns prefix from ns node. */
  ZX_OUT_TAG(p, "<md:AuthnAuthorityDescriptor");
  if (c->inc_ns)
    p = zx_enc_inc_ns(c, p, &pop_seen);
  p = zx_enc_xmlns_if_not_seen(c, p, zx_ns_tab+zx_xmlns_ix_md, &pop_seen);

  p = zx_attr_so_enc(p, x->ID, " ID=\"", sizeof(" ID=\"")-1);
  p = zx_attr_so_enc(p, x->cacheDuration, " cacheDuration=\"", sizeof(" cacheDuration=\"")-1);
  p = zx_attr_so_enc(p, x->errorURL, " errorURL=\"", sizeof(" errorURL=\"")-1);
  p = zx_attr_so_enc(p, x->protocolSupportEnumeration, " protocolSupportEnumeration=\"", sizeof(" protocolSupportEnumeration=\"")-1);
  p = zx_attr_so_enc(p, x->validUntil, " validUntil=\"", sizeof(" validUntil=\"")-1);

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
      struct zx_md_Extensions_s* e;
      for (e = x->Extensions; e; e = (struct zx_md_Extensions_s*)e->gg.g.n)
	  p = zx_ENC_SO_md_Extensions(c, e, p);
  }
  {
      struct zx_md_KeyDescriptor_s* e;
      for (e = x->KeyDescriptor; e; e = (struct zx_md_KeyDescriptor_s*)e->gg.g.n)
	  p = zx_ENC_SO_md_KeyDescriptor(c, e, p);
  }
  {
      struct zx_md_Organization_s* e;
      for (e = x->Organization; e; e = (struct zx_md_Organization_s*)e->gg.g.n)
	  p = zx_ENC_SO_md_Organization(c, e, p);
  }
  {
      struct zx_md_ContactPerson_s* e;
      for (e = x->ContactPerson; e; e = (struct zx_md_ContactPerson_s*)e->gg.g.n)
	  p = zx_ENC_SO_md_ContactPerson(c, e, p);
  }
  {
      struct zx_md_AuthnQueryService_s* e;
      for (e = x->AuthnQueryService; e; e = (struct zx_md_AuthnQueryService_s*)e->gg.g.n)
	  p = zx_ENC_SO_md_AuthnQueryService(c, e, p);
  }
  {
      struct zx_md_AssertionIDRequestService_s* e;
      for (e = x->AssertionIDRequestService; e; e = (struct zx_md_AssertionIDRequestService_s*)e->gg.g.n)
	  p = zx_ENC_SO_md_AssertionIDRequestService(c, e, p);
  }
  for (se = x->NameIDFormat; se; se = (struct zx_elem_s*)se->g.n)
    p = zx_ENC_SO_simple_elem(c, se, p, "md:NameIDFormat", sizeof("md:NameIDFormat")-1, zx_ns_tab+zx_xmlns_ix_md);

  p = zx_enc_so_unknown_elems_and_content(c, p, &x->gg);
  
#if 1 /* NORMALMODE */
  ZX_OUT_CLOSE_TAG(p, "</md:AuthnAuthorityDescriptor>");
  zx_pop_seen(pop_seen);
#else
  /* root node has no end tag either */
#endif
  ENC_LEN_DEBUG(x, "md:AuthnAuthorityDescriptor", p-enc_base);
  return p;
}

/* FUNC(zx_ENC_WO_md_AuthnAuthorityDescriptor) */

/* Render element into string. The XML attributes and elements are
 * processed in wire order by chasing wo pointers. This is what you want for
 * validating signatures on other people's XML documents. */

/* Called by: */
char* zx_ENC_WO_md_AuthnAuthorityDescriptor(struct zx_ctx* c, struct zx_md_AuthnAuthorityDescriptor_s* x, char* p )
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
  ZX_OUT_MEM(p, "AuthnAuthorityDescriptor", sizeof("AuthnAuthorityDescriptor")-1);
  qq = p;

  /* *** sort the namespaces */
  if (c->inc_ns)
    zx_add_inc_ns(c, &pop_seen);
  zx_add_xmlns_if_not_seen(c, x->gg.g.ns, &pop_seen);

  p = zx_enc_seen(p, pop_seen); 
  p = zx_attr_wo_enc(p, x->ID, "ID=\"", sizeof("ID=\"")-1);
  p = zx_attr_wo_enc(p, x->cacheDuration, "cacheDuration=\"", sizeof("cacheDuration=\"")-1);
  p = zx_attr_wo_enc(p, x->errorURL, "errorURL=\"", sizeof("errorURL=\"")-1);
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
  ENC_LEN_DEBUG(x, "md:AuthnAuthorityDescriptor", p-enc_base);
  return p;
}

/* FUNC(zx_EASY_ENC_SO_md_AuthnAuthorityDescriptor) */

/* Called by: */
struct zx_str* zx_EASY_ENC_SO_md_AuthnAuthorityDescriptor(struct zx_ctx* c, struct zx_md_AuthnAuthorityDescriptor_s* x )
{
  int len;
  char* buf;
  c->ns_tab = ZX_ALLOC(c, sizeof(zx_ns_tab));
  memcpy(c->ns_tab, zx_ns_tab, sizeof(zx_ns_tab));
  len = zx_LEN_SO_md_AuthnAuthorityDescriptor(c, x );
  buf = ZX_ALLOC(c, len+1);
  return zx_easy_enc_common(c, zx_ENC_SO_md_AuthnAuthorityDescriptor(c, x, buf ), buf, len);
}

/* FUNC(zx_EASY_ENC_WO_md_AuthnAuthorityDescriptor) */

/* Called by: */
struct zx_str* zx_EASY_ENC_WO_md_AuthnAuthorityDescriptor(struct zx_ctx* c, struct zx_md_AuthnAuthorityDescriptor_s* x )
{
  int len;
  char* buf;
  c->ns_tab = ZX_ALLOC(c, sizeof(zx_ns_tab));
  memcpy(c->ns_tab, zx_ns_tab, sizeof(zx_ns_tab));
  len = zx_LEN_WO_md_AuthnAuthorityDescriptor(c, x );
  buf = ZX_ALLOC(c, len+1);
  return zx_easy_enc_common(c, zx_ENC_WO_md_AuthnAuthorityDescriptor(c, x, buf ), buf, len);
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

#define EL_NAME   md_AuthnQueryService
#define EL_STRUCT zx_md_AuthnQueryService_s
#define EL_NS     md
#define EL_TAG    AuthnQueryService

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

/* FUNC(zx_LEN_SO_md_AuthnQueryService) */

/* Compute length of an element (and its subelements). The XML attributes
 * and elements are processed in schema order. */

/* Called by: */
int zx_LEN_SO_md_AuthnQueryService(struct zx_ctx* c, struct zx_md_AuthnQueryService_s* x )
{
  struct zx_ns_s* pop_seen = 0;
  struct zx_elem_s* se MAYBE_UNUSED;
#if 1 /* NORMALMODE */
  /* *** in simple_elem case should output ns prefix from ns node. */
  int len = sizeof("<md:AuthnQueryService")-1 + 1 + sizeof("</md:AuthnQueryService>")-1;
  if (c->inc_ns_len)
    len += zx_len_inc_ns(c, &pop_seen);
  len += zx_len_xmlns_if_not_seen(c, zx_ns_tab+zx_xmlns_ix_md, &pop_seen);

  len += zx_attr_so_len(x->Binding, sizeof("Binding")-1);
  len += zx_attr_so_len(x->Location, sizeof("Location")-1);
  len += zx_attr_so_len(x->ResponseLocation, sizeof("ResponseLocation")-1);
  len += zx_attr_so_len(x->index, sizeof("index")-1);
  len += zx_attr_so_len(x->isDefault, sizeof("isDefault")-1);

#else
  /* root node has no begin tag */
  int len = 0;
#endif
  


  len += zx_len_so_common(c, &x->gg);
  zx_pop_seen(pop_seen);
  ENC_LEN_DEBUG(x, "md:AuthnQueryService", len);
  return len;
}

/* FUNC(zx_LEN_WO_md_AuthnQueryService) */

/* Compute length of an element (and its subelements). The XML attributes
 * and elements are processed in wire order and no assumptions
 * are made about namespace prefixes. */

/* Called by: */
int zx_LEN_WO_md_AuthnQueryService(struct zx_ctx* c, struct zx_md_AuthnQueryService_s* x )
{
  struct zx_ns_s* pop_seen = 0;
  struct zx_elem_s* se MAYBE_UNUSED;
#if 1 /* NORMALMODE */
  int len = 1 + sizeof("AuthnQueryService")-1 + 1 + 2 + sizeof("AuthnQueryService")-1 + 1;
  
  if (x->gg.g.ns && x->gg.g.ns->prefix_len)
    len += (x->gg.g.ns->prefix_len + 1) * 2;
  if (c->inc_ns_len)
    len += zx_len_inc_ns(c, &pop_seen);
  len += zx_len_xmlns_if_not_seen(c, x->gg.g.ns, &pop_seen);

  len += zx_attr_wo_len(x->Binding, sizeof("Binding")-1);
  len += zx_attr_wo_len(x->Location, sizeof("Location")-1);
  len += zx_attr_wo_len(x->ResponseLocation, sizeof("ResponseLocation")-1);
  len += zx_attr_wo_len(x->index, sizeof("index")-1);
  len += zx_attr_wo_len(x->isDefault, sizeof("isDefault")-1);

#else
  /* root node has no begin tag */
  int len = 0;
#endif
  


  len += zx_len_wo_common(c, &x->gg); 
  zx_pop_seen(pop_seen);
  ENC_LEN_DEBUG(x, "md:AuthnQueryService", len);
  return len;
}

/* FUNC(zx_ENC_SO_md_AuthnQueryService) */

/* Render element into string. The XML attributes and elements are
 * processed in schema order. This is what you generally want for
 * rendering new data structure to a string. The wo pointers are not used. */

/* Called by: */
char* zx_ENC_SO_md_AuthnQueryService(struct zx_ctx* c, struct zx_md_AuthnQueryService_s* x, char* p )
{
  struct zx_elem_s* se MAYBE_UNUSED;
  struct zx_ns_s* pop_seen = 0;
  ENC_LEN_DEBUG_BASE;
#if 1 /* NORMALMODE */
  /* *** in simple_elem case should output ns prefix from ns node. */
  ZX_OUT_TAG(p, "<md:AuthnQueryService");
  if (c->inc_ns)
    p = zx_enc_inc_ns(c, p, &pop_seen);
  p = zx_enc_xmlns_if_not_seen(c, p, zx_ns_tab+zx_xmlns_ix_md, &pop_seen);

  p = zx_attr_so_enc(p, x->Binding, " Binding=\"", sizeof(" Binding=\"")-1);
  p = zx_attr_so_enc(p, x->Location, " Location=\"", sizeof(" Location=\"")-1);
  p = zx_attr_so_enc(p, x->ResponseLocation, " ResponseLocation=\"", sizeof(" ResponseLocation=\"")-1);
  p = zx_attr_so_enc(p, x->index, " index=\"", sizeof(" index=\"")-1);
  p = zx_attr_so_enc(p, x->isDefault, " isDefault=\"", sizeof(" isDefault=\"")-1);

  p = zx_enc_unknown_attrs(p, x->gg.any_attr);
#else
  /* root node has no begin tag */
#endif
  

  p = zx_enc_so_unknown_elems_and_content(c, p, &x->gg);
  
#if 1 /* NORMALMODE */
  ZX_OUT_CLOSE_TAG(p, "</md:AuthnQueryService>");
  zx_pop_seen(pop_seen);
#else
  /* root node has no end tag either */
#endif
  ENC_LEN_DEBUG(x, "md:AuthnQueryService", p-enc_base);
  return p;
}

/* FUNC(zx_ENC_WO_md_AuthnQueryService) */

/* Render element into string. The XML attributes and elements are
 * processed in wire order by chasing wo pointers. This is what you want for
 * validating signatures on other people's XML documents. */

/* Called by: */
char* zx_ENC_WO_md_AuthnQueryService(struct zx_ctx* c, struct zx_md_AuthnQueryService_s* x, char* p )
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
  ZX_OUT_MEM(p, "AuthnQueryService", sizeof("AuthnQueryService")-1);
  qq = p;

  /* *** sort the namespaces */
  if (c->inc_ns)
    zx_add_inc_ns(c, &pop_seen);
  zx_add_xmlns_if_not_seen(c, x->gg.g.ns, &pop_seen);

  p = zx_enc_seen(p, pop_seen); 
  p = zx_attr_wo_enc(p, x->Binding, "Binding=\"", sizeof("Binding=\"")-1);
  p = zx_attr_wo_enc(p, x->Location, "Location=\"", sizeof("Location=\"")-1);
  p = zx_attr_wo_enc(p, x->ResponseLocation, "ResponseLocation=\"", sizeof("ResponseLocation=\"")-1);
  p = zx_attr_wo_enc(p, x->index, "index=\"", sizeof("index=\"")-1);
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
  ENC_LEN_DEBUG(x, "md:AuthnQueryService", p-enc_base);
  return p;
}

/* FUNC(zx_EASY_ENC_SO_md_AuthnQueryService) */

/* Called by: */
struct zx_str* zx_EASY_ENC_SO_md_AuthnQueryService(struct zx_ctx* c, struct zx_md_AuthnQueryService_s* x )
{
  int len;
  char* buf;
  c->ns_tab = ZX_ALLOC(c, sizeof(zx_ns_tab));
  memcpy(c->ns_tab, zx_ns_tab, sizeof(zx_ns_tab));
  len = zx_LEN_SO_md_AuthnQueryService(c, x );
  buf = ZX_ALLOC(c, len+1);
  return zx_easy_enc_common(c, zx_ENC_SO_md_AuthnQueryService(c, x, buf ), buf, len);
}

/* FUNC(zx_EASY_ENC_WO_md_AuthnQueryService) */

/* Called by: */
struct zx_str* zx_EASY_ENC_WO_md_AuthnQueryService(struct zx_ctx* c, struct zx_md_AuthnQueryService_s* x )
{
  int len;
  char* buf;
  c->ns_tab = ZX_ALLOC(c, sizeof(zx_ns_tab));
  memcpy(c->ns_tab, zx_ns_tab, sizeof(zx_ns_tab));
  len = zx_LEN_WO_md_AuthnQueryService(c, x );
  buf = ZX_ALLOC(c, len+1);
  return zx_easy_enc_common(c, zx_ENC_WO_md_AuthnQueryService(c, x, buf ), buf, len);
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

#define EL_NAME   md_AuthzService
#define EL_STRUCT zx_md_AuthzService_s
#define EL_NS     md
#define EL_TAG    AuthzService

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

/* FUNC(zx_LEN_SO_md_AuthzService) */

/* Compute length of an element (and its subelements). The XML attributes
 * and elements are processed in schema order. */

/* Called by: */
int zx_LEN_SO_md_AuthzService(struct zx_ctx* c, struct zx_md_AuthzService_s* x )
{
  struct zx_ns_s* pop_seen = 0;
  struct zx_elem_s* se MAYBE_UNUSED;
#if 1 /* NORMALMODE */
  /* *** in simple_elem case should output ns prefix from ns node. */
  int len = sizeof("<md:AuthzService")-1 + 1 + sizeof("</md:AuthzService>")-1;
  if (c->inc_ns_len)
    len += zx_len_inc_ns(c, &pop_seen);
  len += zx_len_xmlns_if_not_seen(c, zx_ns_tab+zx_xmlns_ix_md, &pop_seen);

  len += zx_attr_so_len(x->Binding, sizeof("Binding")-1);
  len += zx_attr_so_len(x->Location, sizeof("Location")-1);
  len += zx_attr_so_len(x->ResponseLocation, sizeof("ResponseLocation")-1);
  len += zx_attr_so_len(x->index, sizeof("index")-1);
  len += zx_attr_so_len(x->isDefault, sizeof("isDefault")-1);

#else
  /* root node has no begin tag */
  int len = 0;
#endif
  


  len += zx_len_so_common(c, &x->gg);
  zx_pop_seen(pop_seen);
  ENC_LEN_DEBUG(x, "md:AuthzService", len);
  return len;
}

/* FUNC(zx_LEN_WO_md_AuthzService) */

/* Compute length of an element (and its subelements). The XML attributes
 * and elements are processed in wire order and no assumptions
 * are made about namespace prefixes. */

/* Called by: */
int zx_LEN_WO_md_AuthzService(struct zx_ctx* c, struct zx_md_AuthzService_s* x )
{
  struct zx_ns_s* pop_seen = 0;
  struct zx_elem_s* se MAYBE_UNUSED;
#if 1 /* NORMALMODE */
  int len = 1 + sizeof("AuthzService")-1 + 1 + 2 + sizeof("AuthzService")-1 + 1;
  
  if (x->gg.g.ns && x->gg.g.ns->prefix_len)
    len += (x->gg.g.ns->prefix_len + 1) * 2;
  if (c->inc_ns_len)
    len += zx_len_inc_ns(c, &pop_seen);
  len += zx_len_xmlns_if_not_seen(c, x->gg.g.ns, &pop_seen);

  len += zx_attr_wo_len(x->Binding, sizeof("Binding")-1);
  len += zx_attr_wo_len(x->Location, sizeof("Location")-1);
  len += zx_attr_wo_len(x->ResponseLocation, sizeof("ResponseLocation")-1);
  len += zx_attr_wo_len(x->index, sizeof("index")-1);
  len += zx_attr_wo_len(x->isDefault, sizeof("isDefault")-1);

#else
  /* root node has no begin tag */
  int len = 0;
#endif
  


  len += zx_len_wo_common(c, &x->gg); 
  zx_pop_seen(pop_seen);
  ENC_LEN_DEBUG(x, "md:AuthzService", len);
  return len;
}

/* FUNC(zx_ENC_SO_md_AuthzService) */

/* Render element into string. The XML attributes and elements are
 * processed in schema order. This is what you generally want for
 * rendering new data structure to a string. The wo pointers are not used. */

/* Called by: */
char* zx_ENC_SO_md_AuthzService(struct zx_ctx* c, struct zx_md_AuthzService_s* x, char* p )
{
  struct zx_elem_s* se MAYBE_UNUSED;
  struct zx_ns_s* pop_seen = 0;
  ENC_LEN_DEBUG_BASE;
#if 1 /* NORMALMODE */
  /* *** in simple_elem case should output ns prefix from ns node. */
  ZX_OUT_TAG(p, "<md:AuthzService");
  if (c->inc_ns)
    p = zx_enc_inc_ns(c, p, &pop_seen);
  p = zx_enc_xmlns_if_not_seen(c, p, zx_ns_tab+zx_xmlns_ix_md, &pop_seen);

  p = zx_attr_so_enc(p, x->Binding, " Binding=\"", sizeof(" Binding=\"")-1);
  p = zx_attr_so_enc(p, x->Location, " Location=\"", sizeof(" Location=\"")-1);
  p = zx_attr_so_enc(p, x->ResponseLocation, " ResponseLocation=\"", sizeof(" ResponseLocation=\"")-1);
  p = zx_attr_so_enc(p, x->index, " index=\"", sizeof(" index=\"")-1);
  p = zx_attr_so_enc(p, x->isDefault, " isDefault=\"", sizeof(" isDefault=\"")-1);

  p = zx_enc_unknown_attrs(p, x->gg.any_attr);
#else
  /* root node has no begin tag */
#endif
  

  p = zx_enc_so_unknown_elems_and_content(c, p, &x->gg);
  
#if 1 /* NORMALMODE */
  ZX_OUT_CLOSE_TAG(p, "</md:AuthzService>");
  zx_pop_seen(pop_seen);
#else
  /* root node has no end tag either */
#endif
  ENC_LEN_DEBUG(x, "md:AuthzService", p-enc_base);
  return p;
}

/* FUNC(zx_ENC_WO_md_AuthzService) */

/* Render element into string. The XML attributes and elements are
 * processed in wire order by chasing wo pointers. This is what you want for
 * validating signatures on other people's XML documents. */

/* Called by: */
char* zx_ENC_WO_md_AuthzService(struct zx_ctx* c, struct zx_md_AuthzService_s* x, char* p )
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
  ZX_OUT_MEM(p, "AuthzService", sizeof("AuthzService")-1);
  qq = p;

  /* *** sort the namespaces */
  if (c->inc_ns)
    zx_add_inc_ns(c, &pop_seen);
  zx_add_xmlns_if_not_seen(c, x->gg.g.ns, &pop_seen);

  p = zx_enc_seen(p, pop_seen); 
  p = zx_attr_wo_enc(p, x->Binding, "Binding=\"", sizeof("Binding=\"")-1);
  p = zx_attr_wo_enc(p, x->Location, "Location=\"", sizeof("Location=\"")-1);
  p = zx_attr_wo_enc(p, x->ResponseLocation, "ResponseLocation=\"", sizeof("ResponseLocation=\"")-1);
  p = zx_attr_wo_enc(p, x->index, "index=\"", sizeof("index=\"")-1);
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
  ENC_LEN_DEBUG(x, "md:AuthzService", p-enc_base);
  return p;
}

/* FUNC(zx_EASY_ENC_SO_md_AuthzService) */

/* Called by: */
struct zx_str* zx_EASY_ENC_SO_md_AuthzService(struct zx_ctx* c, struct zx_md_AuthzService_s* x )
{
  int len;
  char* buf;
  c->ns_tab = ZX_ALLOC(c, sizeof(zx_ns_tab));
  memcpy(c->ns_tab, zx_ns_tab, sizeof(zx_ns_tab));
  len = zx_LEN_SO_md_AuthzService(c, x );
  buf = ZX_ALLOC(c, len+1);
  return zx_easy_enc_common(c, zx_ENC_SO_md_AuthzService(c, x, buf ), buf, len);
}

/* FUNC(zx_EASY_ENC_WO_md_AuthzService) */

/* Called by: */
struct zx_str* zx_EASY_ENC_WO_md_AuthzService(struct zx_ctx* c, struct zx_md_AuthzService_s* x )
{
  int len;
  char* buf;
  c->ns_tab = ZX_ALLOC(c, sizeof(zx_ns_tab));
  memcpy(c->ns_tab, zx_ns_tab, sizeof(zx_ns_tab));
  len = zx_LEN_WO_md_AuthzService(c, x );
  buf = ZX_ALLOC(c, len+1);
  return zx_easy_enc_common(c, zx_ENC_WO_md_AuthzService(c, x, buf ), buf, len);
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

#define EL_NAME   md_ContactPerson
#define EL_STRUCT zx_md_ContactPerson_s
#define EL_NS     md
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

/* FUNC(zx_LEN_SO_md_ContactPerson) */

/* Compute length of an element (and its subelements). The XML attributes
 * and elements are processed in schema order. */

/* Called by: */
int zx_LEN_SO_md_ContactPerson(struct zx_ctx* c, struct zx_md_ContactPerson_s* x )
{
  struct zx_ns_s* pop_seen = 0;
  struct zx_elem_s* se MAYBE_UNUSED;
#if 1 /* NORMALMODE */
  /* *** in simple_elem case should output ns prefix from ns node. */
  int len = sizeof("<md:ContactPerson")-1 + 1 + sizeof("</md:ContactPerson>")-1;
  if (c->inc_ns_len)
    len += zx_len_inc_ns(c, &pop_seen);
  len += zx_len_xmlns_if_not_seen(c, zx_ns_tab+zx_xmlns_ix_md, &pop_seen);

  len += zx_attr_so_len(x->contactType, sizeof("contactType")-1);

#else
  /* root node has no begin tag */
  int len = 0;
#endif
  
  {
      struct zx_md_Extensions_s* e;
      for (e = x->Extensions; e; e = (struct zx_md_Extensions_s*)e->gg.g.n)
	  len += zx_LEN_SO_md_Extensions(c, e);
  }
  for (se = x->Company; se; se = (struct zx_elem_s*)se->g.n)
    len += zx_LEN_SO_simple_elem(c,se, sizeof("md:Company")-1, zx_ns_tab+zx_xmlns_ix_md);
  for (se = x->GivenName; se; se = (struct zx_elem_s*)se->g.n)
    len += zx_LEN_SO_simple_elem(c,se, sizeof("md:GivenName")-1, zx_ns_tab+zx_xmlns_ix_md);
  for (se = x->SurName; se; se = (struct zx_elem_s*)se->g.n)
    len += zx_LEN_SO_simple_elem(c,se, sizeof("md:SurName")-1, zx_ns_tab+zx_xmlns_ix_md);
  for (se = x->EmailAddress; se; se = (struct zx_elem_s*)se->g.n)
    len += zx_LEN_SO_simple_elem(c,se, sizeof("md:EmailAddress")-1, zx_ns_tab+zx_xmlns_ix_md);
  for (se = x->TelephoneNumber; se; se = (struct zx_elem_s*)se->g.n)
    len += zx_LEN_SO_simple_elem(c,se, sizeof("md:TelephoneNumber")-1, zx_ns_tab+zx_xmlns_ix_md);


  len += zx_len_so_common(c, &x->gg);
  zx_pop_seen(pop_seen);
  ENC_LEN_DEBUG(x, "md:ContactPerson", len);
  return len;
}

/* FUNC(zx_LEN_WO_md_ContactPerson) */

/* Compute length of an element (and its subelements). The XML attributes
 * and elements are processed in wire order and no assumptions
 * are made about namespace prefixes. */

/* Called by: */
int zx_LEN_WO_md_ContactPerson(struct zx_ctx* c, struct zx_md_ContactPerson_s* x )
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

#else
  /* root node has no begin tag */
  int len = 0;
#endif
  
  {
      struct zx_md_Extensions_s* e;
      for (e = x->Extensions; e; e = (struct zx_md_Extensions_s*)e->gg.g.n)
	  len += zx_LEN_WO_md_Extensions(c, e);
  }
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


  len += zx_len_wo_common(c, &x->gg); 
  zx_pop_seen(pop_seen);
  ENC_LEN_DEBUG(x, "md:ContactPerson", len);
  return len;
}

/* FUNC(zx_ENC_SO_md_ContactPerson) */

/* Render element into string. The XML attributes and elements are
 * processed in schema order. This is what you generally want for
 * rendering new data structure to a string. The wo pointers are not used. */

/* Called by: */
char* zx_ENC_SO_md_ContactPerson(struct zx_ctx* c, struct zx_md_ContactPerson_s* x, char* p )
{
  struct zx_elem_s* se MAYBE_UNUSED;
  struct zx_ns_s* pop_seen = 0;
  ENC_LEN_DEBUG_BASE;
#if 1 /* NORMALMODE */
  /* *** in simple_elem case should output ns prefix from ns node. */
  ZX_OUT_TAG(p, "<md:ContactPerson");
  if (c->inc_ns)
    p = zx_enc_inc_ns(c, p, &pop_seen);
  p = zx_enc_xmlns_if_not_seen(c, p, zx_ns_tab+zx_xmlns_ix_md, &pop_seen);

  p = zx_attr_so_enc(p, x->contactType, " contactType=\"", sizeof(" contactType=\"")-1);

  p = zx_enc_unknown_attrs(p, x->gg.any_attr);
#else
  /* root node has no begin tag */
#endif
  
  {
      struct zx_md_Extensions_s* e;
      for (e = x->Extensions; e; e = (struct zx_md_Extensions_s*)e->gg.g.n)
	  p = zx_ENC_SO_md_Extensions(c, e, p);
  }
  for (se = x->Company; se; se = (struct zx_elem_s*)se->g.n)
    p = zx_ENC_SO_simple_elem(c, se, p, "md:Company", sizeof("md:Company")-1, zx_ns_tab+zx_xmlns_ix_md);
  for (se = x->GivenName; se; se = (struct zx_elem_s*)se->g.n)
    p = zx_ENC_SO_simple_elem(c, se, p, "md:GivenName", sizeof("md:GivenName")-1, zx_ns_tab+zx_xmlns_ix_md);
  for (se = x->SurName; se; se = (struct zx_elem_s*)se->g.n)
    p = zx_ENC_SO_simple_elem(c, se, p, "md:SurName", sizeof("md:SurName")-1, zx_ns_tab+zx_xmlns_ix_md);
  for (se = x->EmailAddress; se; se = (struct zx_elem_s*)se->g.n)
    p = zx_ENC_SO_simple_elem(c, se, p, "md:EmailAddress", sizeof("md:EmailAddress")-1, zx_ns_tab+zx_xmlns_ix_md);
  for (se = x->TelephoneNumber; se; se = (struct zx_elem_s*)se->g.n)
    p = zx_ENC_SO_simple_elem(c, se, p, "md:TelephoneNumber", sizeof("md:TelephoneNumber")-1, zx_ns_tab+zx_xmlns_ix_md);

  p = zx_enc_so_unknown_elems_and_content(c, p, &x->gg);
  
#if 1 /* NORMALMODE */
  ZX_OUT_CLOSE_TAG(p, "</md:ContactPerson>");
  zx_pop_seen(pop_seen);
#else
  /* root node has no end tag either */
#endif
  ENC_LEN_DEBUG(x, "md:ContactPerson", p-enc_base);
  return p;
}

/* FUNC(zx_ENC_WO_md_ContactPerson) */

/* Render element into string. The XML attributes and elements are
 * processed in wire order by chasing wo pointers. This is what you want for
 * validating signatures on other people's XML documents. */

/* Called by: */
char* zx_ENC_WO_md_ContactPerson(struct zx_ctx* c, struct zx_md_ContactPerson_s* x, char* p )
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
  ENC_LEN_DEBUG(x, "md:ContactPerson", p-enc_base);
  return p;
}

/* FUNC(zx_EASY_ENC_SO_md_ContactPerson) */

/* Called by: */
struct zx_str* zx_EASY_ENC_SO_md_ContactPerson(struct zx_ctx* c, struct zx_md_ContactPerson_s* x )
{
  int len;
  char* buf;
  c->ns_tab = ZX_ALLOC(c, sizeof(zx_ns_tab));
  memcpy(c->ns_tab, zx_ns_tab, sizeof(zx_ns_tab));
  len = zx_LEN_SO_md_ContactPerson(c, x );
  buf = ZX_ALLOC(c, len+1);
  return zx_easy_enc_common(c, zx_ENC_SO_md_ContactPerson(c, x, buf ), buf, len);
}

/* FUNC(zx_EASY_ENC_WO_md_ContactPerson) */

/* Called by: */
struct zx_str* zx_EASY_ENC_WO_md_ContactPerson(struct zx_ctx* c, struct zx_md_ContactPerson_s* x )
{
  int len;
  char* buf;
  c->ns_tab = ZX_ALLOC(c, sizeof(zx_ns_tab));
  memcpy(c->ns_tab, zx_ns_tab, sizeof(zx_ns_tab));
  len = zx_LEN_WO_md_ContactPerson(c, x );
  buf = ZX_ALLOC(c, len+1);
  return zx_easy_enc_common(c, zx_ENC_WO_md_ContactPerson(c, x, buf ), buf, len);
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

#define EL_NAME   md_EncryptionMethod
#define EL_STRUCT zx_md_EncryptionMethod_s
#define EL_NS     md
#define EL_TAG    EncryptionMethod

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

/* FUNC(zx_LEN_SO_md_EncryptionMethod) */

/* Compute length of an element (and its subelements). The XML attributes
 * and elements are processed in schema order. */

/* Called by: */
int zx_LEN_SO_md_EncryptionMethod(struct zx_ctx* c, struct zx_md_EncryptionMethod_s* x )
{
  struct zx_ns_s* pop_seen = 0;
  struct zx_elem_s* se MAYBE_UNUSED;
#if 1 /* NORMALMODE */
  /* *** in simple_elem case should output ns prefix from ns node. */
  int len = sizeof("<md:EncryptionMethod")-1 + 1 + sizeof("</md:EncryptionMethod>")-1;
  if (c->inc_ns_len)
    len += zx_len_inc_ns(c, &pop_seen);
  len += zx_len_xmlns_if_not_seen(c, zx_ns_tab+zx_xmlns_ix_md, &pop_seen);

  len += zx_attr_so_len(x->Algorithm, sizeof("Algorithm")-1);

#else
  /* root node has no begin tag */
  int len = 0;
#endif
  
  for (se = x->KeySize; se; se = (struct zx_elem_s*)se->g.n)
    len += zx_LEN_SO_simple_elem(c,se, sizeof("xenc:KeySize")-1, zx_ns_tab+zx_xmlns_ix_xenc);
  for (se = x->OAEPparams; se; se = (struct zx_elem_s*)se->g.n)
    len += zx_LEN_SO_simple_elem(c,se, sizeof("xenc:OAEPparams")-1, zx_ns_tab+zx_xmlns_ix_xenc);


  len += zx_len_so_common(c, &x->gg);
  zx_pop_seen(pop_seen);
  ENC_LEN_DEBUG(x, "md:EncryptionMethod", len);
  return len;
}

/* FUNC(zx_LEN_WO_md_EncryptionMethod) */

/* Compute length of an element (and its subelements). The XML attributes
 * and elements are processed in wire order and no assumptions
 * are made about namespace prefixes. */

/* Called by: */
int zx_LEN_WO_md_EncryptionMethod(struct zx_ctx* c, struct zx_md_EncryptionMethod_s* x )
{
  struct zx_ns_s* pop_seen = 0;
  struct zx_elem_s* se MAYBE_UNUSED;
#if 1 /* NORMALMODE */
  int len = 1 + sizeof("EncryptionMethod")-1 + 1 + 2 + sizeof("EncryptionMethod")-1 + 1;
  
  if (x->gg.g.ns && x->gg.g.ns->prefix_len)
    len += (x->gg.g.ns->prefix_len + 1) * 2;
  if (c->inc_ns_len)
    len += zx_len_inc_ns(c, &pop_seen);
  len += zx_len_xmlns_if_not_seen(c, x->gg.g.ns, &pop_seen);

  len += zx_attr_wo_len(x->Algorithm, sizeof("Algorithm")-1);

#else
  /* root node has no begin tag */
  int len = 0;
#endif
  
  for (se = x->KeySize; se; se = (struct zx_elem_s*)se->g.n)
    len += zx_LEN_WO_simple_elem(c, se, sizeof("KeySize")-1);
  for (se = x->OAEPparams; se; se = (struct zx_elem_s*)se->g.n)
    len += zx_LEN_WO_simple_elem(c, se, sizeof("OAEPparams")-1);


  len += zx_len_wo_common(c, &x->gg); 
  zx_pop_seen(pop_seen);
  ENC_LEN_DEBUG(x, "md:EncryptionMethod", len);
  return len;
}

/* FUNC(zx_ENC_SO_md_EncryptionMethod) */

/* Render element into string. The XML attributes and elements are
 * processed in schema order. This is what you generally want for
 * rendering new data structure to a string. The wo pointers are not used. */

/* Called by: */
char* zx_ENC_SO_md_EncryptionMethod(struct zx_ctx* c, struct zx_md_EncryptionMethod_s* x, char* p )
{
  struct zx_elem_s* se MAYBE_UNUSED;
  struct zx_ns_s* pop_seen = 0;
  ENC_LEN_DEBUG_BASE;
#if 1 /* NORMALMODE */
  /* *** in simple_elem case should output ns prefix from ns node. */
  ZX_OUT_TAG(p, "<md:EncryptionMethod");
  if (c->inc_ns)
    p = zx_enc_inc_ns(c, p, &pop_seen);
  p = zx_enc_xmlns_if_not_seen(c, p, zx_ns_tab+zx_xmlns_ix_md, &pop_seen);

  p = zx_attr_so_enc(p, x->Algorithm, " Algorithm=\"", sizeof(" Algorithm=\"")-1);

  p = zx_enc_unknown_attrs(p, x->gg.any_attr);
#else
  /* root node has no begin tag */
#endif
  
  for (se = x->KeySize; se; se = (struct zx_elem_s*)se->g.n)
    p = zx_ENC_SO_simple_elem(c, se, p, "xenc:KeySize", sizeof("xenc:KeySize")-1, zx_ns_tab+zx_xmlns_ix_xenc);
  for (se = x->OAEPparams; se; se = (struct zx_elem_s*)se->g.n)
    p = zx_ENC_SO_simple_elem(c, se, p, "xenc:OAEPparams", sizeof("xenc:OAEPparams")-1, zx_ns_tab+zx_xmlns_ix_xenc);

  p = zx_enc_so_unknown_elems_and_content(c, p, &x->gg);
  
#if 1 /* NORMALMODE */
  ZX_OUT_CLOSE_TAG(p, "</md:EncryptionMethod>");
  zx_pop_seen(pop_seen);
#else
  /* root node has no end tag either */
#endif
  ENC_LEN_DEBUG(x, "md:EncryptionMethod", p-enc_base);
  return p;
}

/* FUNC(zx_ENC_WO_md_EncryptionMethod) */

/* Render element into string. The XML attributes and elements are
 * processed in wire order by chasing wo pointers. This is what you want for
 * validating signatures on other people's XML documents. */

/* Called by: */
char* zx_ENC_WO_md_EncryptionMethod(struct zx_ctx* c, struct zx_md_EncryptionMethod_s* x, char* p )
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
  ZX_OUT_MEM(p, "EncryptionMethod", sizeof("EncryptionMethod")-1);
  qq = p;

  /* *** sort the namespaces */
  if (c->inc_ns)
    zx_add_inc_ns(c, &pop_seen);
  zx_add_xmlns_if_not_seen(c, x->gg.g.ns, &pop_seen);

  p = zx_enc_seen(p, pop_seen); 
  p = zx_attr_wo_enc(p, x->Algorithm, "Algorithm=\"", sizeof("Algorithm=\"")-1);

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
  ENC_LEN_DEBUG(x, "md:EncryptionMethod", p-enc_base);
  return p;
}

/* FUNC(zx_EASY_ENC_SO_md_EncryptionMethod) */

/* Called by: */
struct zx_str* zx_EASY_ENC_SO_md_EncryptionMethod(struct zx_ctx* c, struct zx_md_EncryptionMethod_s* x )
{
  int len;
  char* buf;
  c->ns_tab = ZX_ALLOC(c, sizeof(zx_ns_tab));
  memcpy(c->ns_tab, zx_ns_tab, sizeof(zx_ns_tab));
  len = zx_LEN_SO_md_EncryptionMethod(c, x );
  buf = ZX_ALLOC(c, len+1);
  return zx_easy_enc_common(c, zx_ENC_SO_md_EncryptionMethod(c, x, buf ), buf, len);
}

/* FUNC(zx_EASY_ENC_WO_md_EncryptionMethod) */

/* Called by: */
struct zx_str* zx_EASY_ENC_WO_md_EncryptionMethod(struct zx_ctx* c, struct zx_md_EncryptionMethod_s* x )
{
  int len;
  char* buf;
  c->ns_tab = ZX_ALLOC(c, sizeof(zx_ns_tab));
  memcpy(c->ns_tab, zx_ns_tab, sizeof(zx_ns_tab));
  len = zx_LEN_WO_md_EncryptionMethod(c, x );
  buf = ZX_ALLOC(c, len+1);
  return zx_easy_enc_common(c, zx_ENC_WO_md_EncryptionMethod(c, x, buf ), buf, len);
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

#define EL_NAME   md_EntitiesDescriptor
#define EL_STRUCT zx_md_EntitiesDescriptor_s
#define EL_NS     md
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

/* FUNC(zx_LEN_SO_md_EntitiesDescriptor) */

/* Compute length of an element (and its subelements). The XML attributes
 * and elements are processed in schema order. */

/* Called by: */
int zx_LEN_SO_md_EntitiesDescriptor(struct zx_ctx* c, struct zx_md_EntitiesDescriptor_s* x )
{
  struct zx_ns_s* pop_seen = 0;
  struct zx_elem_s* se MAYBE_UNUSED;
#if 1 /* NORMALMODE */
  /* *** in simple_elem case should output ns prefix from ns node. */
  int len = sizeof("<md:EntitiesDescriptor")-1 + 1 + sizeof("</md:EntitiesDescriptor>")-1;
  if (c->inc_ns_len)
    len += zx_len_inc_ns(c, &pop_seen);
  len += zx_len_xmlns_if_not_seen(c, zx_ns_tab+zx_xmlns_ix_md, &pop_seen);

  len += zx_attr_so_len(x->ID, sizeof("ID")-1);
  len += zx_attr_so_len(x->Name, sizeof("Name")-1);
  len += zx_attr_so_len(x->cacheDuration, sizeof("cacheDuration")-1);
  len += zx_attr_so_len(x->validUntil, sizeof("validUntil")-1);

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
      struct zx_md_Extensions_s* e;
      for (e = x->Extensions; e; e = (struct zx_md_Extensions_s*)e->gg.g.n)
	  len += zx_LEN_SO_md_Extensions(c, e);
  }
  {
      struct zx_md_EntityDescriptor_s* e;
      for (e = x->EntityDescriptor; e; e = (struct zx_md_EntityDescriptor_s*)e->gg.g.n)
	  len += zx_LEN_SO_md_EntityDescriptor(c, e);
  }
  {
      struct zx_md_EntitiesDescriptor_s* e;
      for (e = x->EntitiesDescriptor; e; e = (struct zx_md_EntitiesDescriptor_s*)e->gg.g.n)
	  len += zx_LEN_SO_md_EntitiesDescriptor(c, e);
  }


  len += zx_len_so_common(c, &x->gg);
  zx_pop_seen(pop_seen);
  ENC_LEN_DEBUG(x, "md:EntitiesDescriptor", len);
  return len;
}

/* FUNC(zx_LEN_WO_md_EntitiesDescriptor) */

/* Compute length of an element (and its subelements). The XML attributes
 * and elements are processed in wire order and no assumptions
 * are made about namespace prefixes. */

/* Called by: */
int zx_LEN_WO_md_EntitiesDescriptor(struct zx_ctx* c, struct zx_md_EntitiesDescriptor_s* x )
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

  len += zx_attr_wo_len(x->ID, sizeof("ID")-1);
  len += zx_attr_wo_len(x->Name, sizeof("Name")-1);
  len += zx_attr_wo_len(x->cacheDuration, sizeof("cacheDuration")-1);
  len += zx_attr_wo_len(x->validUntil, sizeof("validUntil")-1);

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
      struct zx_md_Extensions_s* e;
      for (e = x->Extensions; e; e = (struct zx_md_Extensions_s*)e->gg.g.n)
	  len += zx_LEN_WO_md_Extensions(c, e);
  }
  {
      struct zx_md_EntityDescriptor_s* e;
      for (e = x->EntityDescriptor; e; e = (struct zx_md_EntityDescriptor_s*)e->gg.g.n)
	  len += zx_LEN_WO_md_EntityDescriptor(c, e);
  }
  {
      struct zx_md_EntitiesDescriptor_s* e;
      for (e = x->EntitiesDescriptor; e; e = (struct zx_md_EntitiesDescriptor_s*)e->gg.g.n)
	  len += zx_LEN_WO_md_EntitiesDescriptor(c, e);
  }


  len += zx_len_wo_common(c, &x->gg); 
  zx_pop_seen(pop_seen);
  ENC_LEN_DEBUG(x, "md:EntitiesDescriptor", len);
  return len;
}

/* FUNC(zx_ENC_SO_md_EntitiesDescriptor) */

/* Render element into string. The XML attributes and elements are
 * processed in schema order. This is what you generally want for
 * rendering new data structure to a string. The wo pointers are not used. */

/* Called by: */
char* zx_ENC_SO_md_EntitiesDescriptor(struct zx_ctx* c, struct zx_md_EntitiesDescriptor_s* x, char* p )
{
  struct zx_elem_s* se MAYBE_UNUSED;
  struct zx_ns_s* pop_seen = 0;
  ENC_LEN_DEBUG_BASE;
#if 1 /* NORMALMODE */
  /* *** in simple_elem case should output ns prefix from ns node. */
  ZX_OUT_TAG(p, "<md:EntitiesDescriptor");
  if (c->inc_ns)
    p = zx_enc_inc_ns(c, p, &pop_seen);
  p = zx_enc_xmlns_if_not_seen(c, p, zx_ns_tab+zx_xmlns_ix_md, &pop_seen);

  p = zx_attr_so_enc(p, x->ID, " ID=\"", sizeof(" ID=\"")-1);
  p = zx_attr_so_enc(p, x->Name, " Name=\"", sizeof(" Name=\"")-1);
  p = zx_attr_so_enc(p, x->cacheDuration, " cacheDuration=\"", sizeof(" cacheDuration=\"")-1);
  p = zx_attr_so_enc(p, x->validUntil, " validUntil=\"", sizeof(" validUntil=\"")-1);

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
      struct zx_md_Extensions_s* e;
      for (e = x->Extensions; e; e = (struct zx_md_Extensions_s*)e->gg.g.n)
	  p = zx_ENC_SO_md_Extensions(c, e, p);
  }
  {
      struct zx_md_EntityDescriptor_s* e;
      for (e = x->EntityDescriptor; e; e = (struct zx_md_EntityDescriptor_s*)e->gg.g.n)
	  p = zx_ENC_SO_md_EntityDescriptor(c, e, p);
  }
  {
      struct zx_md_EntitiesDescriptor_s* e;
      for (e = x->EntitiesDescriptor; e; e = (struct zx_md_EntitiesDescriptor_s*)e->gg.g.n)
	  p = zx_ENC_SO_md_EntitiesDescriptor(c, e, p);
  }

  p = zx_enc_so_unknown_elems_and_content(c, p, &x->gg);
  
#if 1 /* NORMALMODE */
  ZX_OUT_CLOSE_TAG(p, "</md:EntitiesDescriptor>");
  zx_pop_seen(pop_seen);
#else
  /* root node has no end tag either */
#endif
  ENC_LEN_DEBUG(x, "md:EntitiesDescriptor", p-enc_base);
  return p;
}

/* FUNC(zx_ENC_WO_md_EntitiesDescriptor) */

/* Render element into string. The XML attributes and elements are
 * processed in wire order by chasing wo pointers. This is what you want for
 * validating signatures on other people's XML documents. */

/* Called by: */
char* zx_ENC_WO_md_EntitiesDescriptor(struct zx_ctx* c, struct zx_md_EntitiesDescriptor_s* x, char* p )
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
  p = zx_attr_wo_enc(p, x->ID, "ID=\"", sizeof("ID=\"")-1);
  p = zx_attr_wo_enc(p, x->Name, "Name=\"", sizeof("Name=\"")-1);
  p = zx_attr_wo_enc(p, x->cacheDuration, "cacheDuration=\"", sizeof("cacheDuration=\"")-1);
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
  ENC_LEN_DEBUG(x, "md:EntitiesDescriptor", p-enc_base);
  return p;
}

/* FUNC(zx_EASY_ENC_SO_md_EntitiesDescriptor) */

/* Called by: */
struct zx_str* zx_EASY_ENC_SO_md_EntitiesDescriptor(struct zx_ctx* c, struct zx_md_EntitiesDescriptor_s* x )
{
  int len;
  char* buf;
  c->ns_tab = ZX_ALLOC(c, sizeof(zx_ns_tab));
  memcpy(c->ns_tab, zx_ns_tab, sizeof(zx_ns_tab));
  len = zx_LEN_SO_md_EntitiesDescriptor(c, x );
  buf = ZX_ALLOC(c, len+1);
  return zx_easy_enc_common(c, zx_ENC_SO_md_EntitiesDescriptor(c, x, buf ), buf, len);
}

/* FUNC(zx_EASY_ENC_WO_md_EntitiesDescriptor) */

/* Called by: */
struct zx_str* zx_EASY_ENC_WO_md_EntitiesDescriptor(struct zx_ctx* c, struct zx_md_EntitiesDescriptor_s* x )
{
  int len;
  char* buf;
  c->ns_tab = ZX_ALLOC(c, sizeof(zx_ns_tab));
  memcpy(c->ns_tab, zx_ns_tab, sizeof(zx_ns_tab));
  len = zx_LEN_WO_md_EntitiesDescriptor(c, x );
  buf = ZX_ALLOC(c, len+1);
  return zx_easy_enc_common(c, zx_ENC_WO_md_EntitiesDescriptor(c, x, buf ), buf, len);
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

#define EL_NAME   md_EntityDescriptor
#define EL_STRUCT zx_md_EntityDescriptor_s
#define EL_NS     md
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

/* FUNC(zx_LEN_SO_md_EntityDescriptor) */

/* Compute length of an element (and its subelements). The XML attributes
 * and elements are processed in schema order. */

/* Called by: */
int zx_LEN_SO_md_EntityDescriptor(struct zx_ctx* c, struct zx_md_EntityDescriptor_s* x )
{
  struct zx_ns_s* pop_seen = 0;
  struct zx_elem_s* se MAYBE_UNUSED;
#if 1 /* NORMALMODE */
  /* *** in simple_elem case should output ns prefix from ns node. */
  int len = sizeof("<md:EntityDescriptor")-1 + 1 + sizeof("</md:EntityDescriptor>")-1;
  if (c->inc_ns_len)
    len += zx_len_inc_ns(c, &pop_seen);
  len += zx_len_xmlns_if_not_seen(c, zx_ns_tab+zx_xmlns_ix_md, &pop_seen);

  len += zx_attr_so_len(x->ID, sizeof("ID")-1);
  len += zx_attr_so_len(x->cacheDuration, sizeof("cacheDuration")-1);
  len += zx_attr_so_len(x->entityID, sizeof("entityID")-1);
  len += zx_attr_so_len(x->validUntil, sizeof("validUntil")-1);

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
      struct zx_md_Extensions_s* e;
      for (e = x->Extensions; e; e = (struct zx_md_Extensions_s*)e->gg.g.n)
	  len += zx_LEN_SO_md_Extensions(c, e);
  }
  {
      struct zx_md_RoleDescriptor_s* e;
      for (e = x->RoleDescriptor; e; e = (struct zx_md_RoleDescriptor_s*)e->gg.g.n)
	  len += zx_LEN_SO_md_RoleDescriptor(c, e);
  }
  {
      struct zx_md_IDPSSODescriptor_s* e;
      for (e = x->IDPSSODescriptor; e; e = (struct zx_md_IDPSSODescriptor_s*)e->gg.g.n)
	  len += zx_LEN_SO_md_IDPSSODescriptor(c, e);
  }
  {
      struct zx_md_SPSSODescriptor_s* e;
      for (e = x->SPSSODescriptor; e; e = (struct zx_md_SPSSODescriptor_s*)e->gg.g.n)
	  len += zx_LEN_SO_md_SPSSODescriptor(c, e);
  }
  {
      struct zx_md_AuthnAuthorityDescriptor_s* e;
      for (e = x->AuthnAuthorityDescriptor; e; e = (struct zx_md_AuthnAuthorityDescriptor_s*)e->gg.g.n)
	  len += zx_LEN_SO_md_AuthnAuthorityDescriptor(c, e);
  }
  {
      struct zx_md_AttributeAuthorityDescriptor_s* e;
      for (e = x->AttributeAuthorityDescriptor; e; e = (struct zx_md_AttributeAuthorityDescriptor_s*)e->gg.g.n)
	  len += zx_LEN_SO_md_AttributeAuthorityDescriptor(c, e);
  }
  {
      struct zx_md_PDPDescriptor_s* e;
      for (e = x->PDPDescriptor; e; e = (struct zx_md_PDPDescriptor_s*)e->gg.g.n)
	  len += zx_LEN_SO_md_PDPDescriptor(c, e);
  }
  {
      struct zx_md_AffiliationDescriptor_s* e;
      for (e = x->AffiliationDescriptor; e; e = (struct zx_md_AffiliationDescriptor_s*)e->gg.g.n)
	  len += zx_LEN_SO_md_AffiliationDescriptor(c, e);
  }
  {
      struct zx_md_Organization_s* e;
      for (e = x->Organization; e; e = (struct zx_md_Organization_s*)e->gg.g.n)
	  len += zx_LEN_SO_md_Organization(c, e);
  }
  {
      struct zx_md_ContactPerson_s* e;
      for (e = x->ContactPerson; e; e = (struct zx_md_ContactPerson_s*)e->gg.g.n)
	  len += zx_LEN_SO_md_ContactPerson(c, e);
  }
  {
      struct zx_md_AdditionalMetadataLocation_s* e;
      for (e = x->AdditionalMetadataLocation; e; e = (struct zx_md_AdditionalMetadataLocation_s*)e->gg.g.n)
	  len += zx_LEN_SO_md_AdditionalMetadataLocation(c, e);
  }


  len += zx_len_so_common(c, &x->gg);
  zx_pop_seen(pop_seen);
  ENC_LEN_DEBUG(x, "md:EntityDescriptor", len);
  return len;
}

/* FUNC(zx_LEN_WO_md_EntityDescriptor) */

/* Compute length of an element (and its subelements). The XML attributes
 * and elements are processed in wire order and no assumptions
 * are made about namespace prefixes. */

/* Called by: */
int zx_LEN_WO_md_EntityDescriptor(struct zx_ctx* c, struct zx_md_EntityDescriptor_s* x )
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

  len += zx_attr_wo_len(x->ID, sizeof("ID")-1);
  len += zx_attr_wo_len(x->cacheDuration, sizeof("cacheDuration")-1);
  len += zx_attr_wo_len(x->entityID, sizeof("entityID")-1);
  len += zx_attr_wo_len(x->validUntil, sizeof("validUntil")-1);

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
      struct zx_md_Extensions_s* e;
      for (e = x->Extensions; e; e = (struct zx_md_Extensions_s*)e->gg.g.n)
	  len += zx_LEN_WO_md_Extensions(c, e);
  }
  {
      struct zx_md_RoleDescriptor_s* e;
      for (e = x->RoleDescriptor; e; e = (struct zx_md_RoleDescriptor_s*)e->gg.g.n)
	  len += zx_LEN_WO_md_RoleDescriptor(c, e);
  }
  {
      struct zx_md_IDPSSODescriptor_s* e;
      for (e = x->IDPSSODescriptor; e; e = (struct zx_md_IDPSSODescriptor_s*)e->gg.g.n)
	  len += zx_LEN_WO_md_IDPSSODescriptor(c, e);
  }
  {
      struct zx_md_SPSSODescriptor_s* e;
      for (e = x->SPSSODescriptor; e; e = (struct zx_md_SPSSODescriptor_s*)e->gg.g.n)
	  len += zx_LEN_WO_md_SPSSODescriptor(c, e);
  }
  {
      struct zx_md_AuthnAuthorityDescriptor_s* e;
      for (e = x->AuthnAuthorityDescriptor; e; e = (struct zx_md_AuthnAuthorityDescriptor_s*)e->gg.g.n)
	  len += zx_LEN_WO_md_AuthnAuthorityDescriptor(c, e);
  }
  {
      struct zx_md_AttributeAuthorityDescriptor_s* e;
      for (e = x->AttributeAuthorityDescriptor; e; e = (struct zx_md_AttributeAuthorityDescriptor_s*)e->gg.g.n)
	  len += zx_LEN_WO_md_AttributeAuthorityDescriptor(c, e);
  }
  {
      struct zx_md_PDPDescriptor_s* e;
      for (e = x->PDPDescriptor; e; e = (struct zx_md_PDPDescriptor_s*)e->gg.g.n)
	  len += zx_LEN_WO_md_PDPDescriptor(c, e);
  }
  {
      struct zx_md_AffiliationDescriptor_s* e;
      for (e = x->AffiliationDescriptor; e; e = (struct zx_md_AffiliationDescriptor_s*)e->gg.g.n)
	  len += zx_LEN_WO_md_AffiliationDescriptor(c, e);
  }
  {
      struct zx_md_Organization_s* e;
      for (e = x->Organization; e; e = (struct zx_md_Organization_s*)e->gg.g.n)
	  len += zx_LEN_WO_md_Organization(c, e);
  }
  {
      struct zx_md_ContactPerson_s* e;
      for (e = x->ContactPerson; e; e = (struct zx_md_ContactPerson_s*)e->gg.g.n)
	  len += zx_LEN_WO_md_ContactPerson(c, e);
  }
  {
      struct zx_md_AdditionalMetadataLocation_s* e;
      for (e = x->AdditionalMetadataLocation; e; e = (struct zx_md_AdditionalMetadataLocation_s*)e->gg.g.n)
	  len += zx_LEN_WO_md_AdditionalMetadataLocation(c, e);
  }


  len += zx_len_wo_common(c, &x->gg); 
  zx_pop_seen(pop_seen);
  ENC_LEN_DEBUG(x, "md:EntityDescriptor", len);
  return len;
}

/* FUNC(zx_ENC_SO_md_EntityDescriptor) */

/* Render element into string. The XML attributes and elements are
 * processed in schema order. This is what you generally want for
 * rendering new data structure to a string. The wo pointers are not used. */

/* Called by: */
char* zx_ENC_SO_md_EntityDescriptor(struct zx_ctx* c, struct zx_md_EntityDescriptor_s* x, char* p )
{
  struct zx_elem_s* se MAYBE_UNUSED;
  struct zx_ns_s* pop_seen = 0;
  ENC_LEN_DEBUG_BASE;
#if 1 /* NORMALMODE */
  /* *** in simple_elem case should output ns prefix from ns node. */
  ZX_OUT_TAG(p, "<md:EntityDescriptor");
  if (c->inc_ns)
    p = zx_enc_inc_ns(c, p, &pop_seen);
  p = zx_enc_xmlns_if_not_seen(c, p, zx_ns_tab+zx_xmlns_ix_md, &pop_seen);

  p = zx_attr_so_enc(p, x->ID, " ID=\"", sizeof(" ID=\"")-1);
  p = zx_attr_so_enc(p, x->cacheDuration, " cacheDuration=\"", sizeof(" cacheDuration=\"")-1);
  p = zx_attr_so_enc(p, x->entityID, " entityID=\"", sizeof(" entityID=\"")-1);
  p = zx_attr_so_enc(p, x->validUntil, " validUntil=\"", sizeof(" validUntil=\"")-1);

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
      struct zx_md_Extensions_s* e;
      for (e = x->Extensions; e; e = (struct zx_md_Extensions_s*)e->gg.g.n)
	  p = zx_ENC_SO_md_Extensions(c, e, p);
  }
  {
      struct zx_md_RoleDescriptor_s* e;
      for (e = x->RoleDescriptor; e; e = (struct zx_md_RoleDescriptor_s*)e->gg.g.n)
	  p = zx_ENC_SO_md_RoleDescriptor(c, e, p);
  }
  {
      struct zx_md_IDPSSODescriptor_s* e;
      for (e = x->IDPSSODescriptor; e; e = (struct zx_md_IDPSSODescriptor_s*)e->gg.g.n)
	  p = zx_ENC_SO_md_IDPSSODescriptor(c, e, p);
  }
  {
      struct zx_md_SPSSODescriptor_s* e;
      for (e = x->SPSSODescriptor; e; e = (struct zx_md_SPSSODescriptor_s*)e->gg.g.n)
	  p = zx_ENC_SO_md_SPSSODescriptor(c, e, p);
  }
  {
      struct zx_md_AuthnAuthorityDescriptor_s* e;
      for (e = x->AuthnAuthorityDescriptor; e; e = (struct zx_md_AuthnAuthorityDescriptor_s*)e->gg.g.n)
	  p = zx_ENC_SO_md_AuthnAuthorityDescriptor(c, e, p);
  }
  {
      struct zx_md_AttributeAuthorityDescriptor_s* e;
      for (e = x->AttributeAuthorityDescriptor; e; e = (struct zx_md_AttributeAuthorityDescriptor_s*)e->gg.g.n)
	  p = zx_ENC_SO_md_AttributeAuthorityDescriptor(c, e, p);
  }
  {
      struct zx_md_PDPDescriptor_s* e;
      for (e = x->PDPDescriptor; e; e = (struct zx_md_PDPDescriptor_s*)e->gg.g.n)
	  p = zx_ENC_SO_md_PDPDescriptor(c, e, p);
  }
  {
      struct zx_md_AffiliationDescriptor_s* e;
      for (e = x->AffiliationDescriptor; e; e = (struct zx_md_AffiliationDescriptor_s*)e->gg.g.n)
	  p = zx_ENC_SO_md_AffiliationDescriptor(c, e, p);
  }
  {
      struct zx_md_Organization_s* e;
      for (e = x->Organization; e; e = (struct zx_md_Organization_s*)e->gg.g.n)
	  p = zx_ENC_SO_md_Organization(c, e, p);
  }
  {
      struct zx_md_ContactPerson_s* e;
      for (e = x->ContactPerson; e; e = (struct zx_md_ContactPerson_s*)e->gg.g.n)
	  p = zx_ENC_SO_md_ContactPerson(c, e, p);
  }
  {
      struct zx_md_AdditionalMetadataLocation_s* e;
      for (e = x->AdditionalMetadataLocation; e; e = (struct zx_md_AdditionalMetadataLocation_s*)e->gg.g.n)
	  p = zx_ENC_SO_md_AdditionalMetadataLocation(c, e, p);
  }

  p = zx_enc_so_unknown_elems_and_content(c, p, &x->gg);
  
#if 1 /* NORMALMODE */
  ZX_OUT_CLOSE_TAG(p, "</md:EntityDescriptor>");
  zx_pop_seen(pop_seen);
#else
  /* root node has no end tag either */
#endif
  ENC_LEN_DEBUG(x, "md:EntityDescriptor", p-enc_base);
  return p;
}

/* FUNC(zx_ENC_WO_md_EntityDescriptor) */

/* Render element into string. The XML attributes and elements are
 * processed in wire order by chasing wo pointers. This is what you want for
 * validating signatures on other people's XML documents. */

/* Called by: */
char* zx_ENC_WO_md_EntityDescriptor(struct zx_ctx* c, struct zx_md_EntityDescriptor_s* x, char* p )
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
  p = zx_attr_wo_enc(p, x->ID, "ID=\"", sizeof("ID=\"")-1);
  p = zx_attr_wo_enc(p, x->cacheDuration, "cacheDuration=\"", sizeof("cacheDuration=\"")-1);
  p = zx_attr_wo_enc(p, x->entityID, "entityID=\"", sizeof("entityID=\"")-1);
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
  ENC_LEN_DEBUG(x, "md:EntityDescriptor", p-enc_base);
  return p;
}

/* FUNC(zx_EASY_ENC_SO_md_EntityDescriptor) */

/* Called by: */
struct zx_str* zx_EASY_ENC_SO_md_EntityDescriptor(struct zx_ctx* c, struct zx_md_EntityDescriptor_s* x )
{
  int len;
  char* buf;
  c->ns_tab = ZX_ALLOC(c, sizeof(zx_ns_tab));
  memcpy(c->ns_tab, zx_ns_tab, sizeof(zx_ns_tab));
  len = zx_LEN_SO_md_EntityDescriptor(c, x );
  buf = ZX_ALLOC(c, len+1);
  return zx_easy_enc_common(c, zx_ENC_SO_md_EntityDescriptor(c, x, buf ), buf, len);
}

/* FUNC(zx_EASY_ENC_WO_md_EntityDescriptor) */

/* Called by: */
struct zx_str* zx_EASY_ENC_WO_md_EntityDescriptor(struct zx_ctx* c, struct zx_md_EntityDescriptor_s* x )
{
  int len;
  char* buf;
  c->ns_tab = ZX_ALLOC(c, sizeof(zx_ns_tab));
  memcpy(c->ns_tab, zx_ns_tab, sizeof(zx_ns_tab));
  len = zx_LEN_WO_md_EntityDescriptor(c, x );
  buf = ZX_ALLOC(c, len+1);
  return zx_easy_enc_common(c, zx_ENC_WO_md_EntityDescriptor(c, x, buf ), buf, len);
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

#define EL_NAME   md_Extensions
#define EL_STRUCT zx_md_Extensions_s
#define EL_NS     md
#define EL_TAG    Extensions

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

/* FUNC(zx_LEN_SO_md_Extensions) */

/* Compute length of an element (and its subelements). The XML attributes
 * and elements are processed in schema order. */

/* Called by: */
int zx_LEN_SO_md_Extensions(struct zx_ctx* c, struct zx_md_Extensions_s* x )
{
  struct zx_ns_s* pop_seen = 0;
  struct zx_elem_s* se MAYBE_UNUSED;
#if 1 /* NORMALMODE */
  /* *** in simple_elem case should output ns prefix from ns node. */
  int len = sizeof("<md:Extensions")-1 + 1 + sizeof("</md:Extensions>")-1;
  if (c->inc_ns_len)
    len += zx_len_inc_ns(c, &pop_seen);
  len += zx_len_xmlns_if_not_seen(c, zx_ns_tab+zx_xmlns_ix_md, &pop_seen);


#else
  /* root node has no begin tag */
  int len = 0;
#endif
  
  {
      struct zx_shibmd_Scope_s* e;
      for (e = x->Scope; e; e = (struct zx_shibmd_Scope_s*)e->gg.g.n)
	  len += zx_LEN_SO_shibmd_Scope(c, e);
  }
  {
      struct zx_shibmd_KeyAuthority_s* e;
      for (e = x->KeyAuthority; e; e = (struct zx_shibmd_KeyAuthority_s*)e->gg.g.n)
	  len += zx_LEN_SO_shibmd_KeyAuthority(c, e);
  }
  {
      struct zx_idpdisc_DiscoveryResponse_s* e;
      for (e = x->DiscoveryResponse; e; e = (struct zx_idpdisc_DiscoveryResponse_s*)e->gg.g.n)
	  len += zx_LEN_SO_idpdisc_DiscoveryResponse(c, e);
  }


  len += zx_len_so_common(c, &x->gg);
  zx_pop_seen(pop_seen);
  ENC_LEN_DEBUG(x, "md:Extensions", len);
  return len;
}

/* FUNC(zx_LEN_WO_md_Extensions) */

/* Compute length of an element (and its subelements). The XML attributes
 * and elements are processed in wire order and no assumptions
 * are made about namespace prefixes. */

/* Called by: */
int zx_LEN_WO_md_Extensions(struct zx_ctx* c, struct zx_md_Extensions_s* x )
{
  struct zx_ns_s* pop_seen = 0;
  struct zx_elem_s* se MAYBE_UNUSED;
#if 1 /* NORMALMODE */
  int len = 1 + sizeof("Extensions")-1 + 1 + 2 + sizeof("Extensions")-1 + 1;
  
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
      struct zx_shibmd_Scope_s* e;
      for (e = x->Scope; e; e = (struct zx_shibmd_Scope_s*)e->gg.g.n)
	  len += zx_LEN_WO_shibmd_Scope(c, e);
  }
  {
      struct zx_shibmd_KeyAuthority_s* e;
      for (e = x->KeyAuthority; e; e = (struct zx_shibmd_KeyAuthority_s*)e->gg.g.n)
	  len += zx_LEN_WO_shibmd_KeyAuthority(c, e);
  }
  {
      struct zx_idpdisc_DiscoveryResponse_s* e;
      for (e = x->DiscoveryResponse; e; e = (struct zx_idpdisc_DiscoveryResponse_s*)e->gg.g.n)
	  len += zx_LEN_WO_idpdisc_DiscoveryResponse(c, e);
  }


  len += zx_len_wo_common(c, &x->gg); 
  zx_pop_seen(pop_seen);
  ENC_LEN_DEBUG(x, "md:Extensions", len);
  return len;
}

/* FUNC(zx_ENC_SO_md_Extensions) */

/* Render element into string. The XML attributes and elements are
 * processed in schema order. This is what you generally want for
 * rendering new data structure to a string. The wo pointers are not used. */

/* Called by: */
char* zx_ENC_SO_md_Extensions(struct zx_ctx* c, struct zx_md_Extensions_s* x, char* p )
{
  struct zx_elem_s* se MAYBE_UNUSED;
  struct zx_ns_s* pop_seen = 0;
  ENC_LEN_DEBUG_BASE;
#if 1 /* NORMALMODE */
  /* *** in simple_elem case should output ns prefix from ns node. */
  ZX_OUT_TAG(p, "<md:Extensions");
  if (c->inc_ns)
    p = zx_enc_inc_ns(c, p, &pop_seen);
  p = zx_enc_xmlns_if_not_seen(c, p, zx_ns_tab+zx_xmlns_ix_md, &pop_seen);


  p = zx_enc_unknown_attrs(p, x->gg.any_attr);
#else
  /* root node has no begin tag */
#endif
  
  {
      struct zx_shibmd_Scope_s* e;
      for (e = x->Scope; e; e = (struct zx_shibmd_Scope_s*)e->gg.g.n)
	  p = zx_ENC_SO_shibmd_Scope(c, e, p);
  }
  {
      struct zx_shibmd_KeyAuthority_s* e;
      for (e = x->KeyAuthority; e; e = (struct zx_shibmd_KeyAuthority_s*)e->gg.g.n)
	  p = zx_ENC_SO_shibmd_KeyAuthority(c, e, p);
  }
  {
      struct zx_idpdisc_DiscoveryResponse_s* e;
      for (e = x->DiscoveryResponse; e; e = (struct zx_idpdisc_DiscoveryResponse_s*)e->gg.g.n)
	  p = zx_ENC_SO_idpdisc_DiscoveryResponse(c, e, p);
  }

  p = zx_enc_so_unknown_elems_and_content(c, p, &x->gg);
  
#if 1 /* NORMALMODE */
  ZX_OUT_CLOSE_TAG(p, "</md:Extensions>");
  zx_pop_seen(pop_seen);
#else
  /* root node has no end tag either */
#endif
  ENC_LEN_DEBUG(x, "md:Extensions", p-enc_base);
  return p;
}

/* FUNC(zx_ENC_WO_md_Extensions) */

/* Render element into string. The XML attributes and elements are
 * processed in wire order by chasing wo pointers. This is what you want for
 * validating signatures on other people's XML documents. */

/* Called by: */
char* zx_ENC_WO_md_Extensions(struct zx_ctx* c, struct zx_md_Extensions_s* x, char* p )
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
  ZX_OUT_MEM(p, "Extensions", sizeof("Extensions")-1);
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
  ENC_LEN_DEBUG(x, "md:Extensions", p-enc_base);
  return p;
}

/* FUNC(zx_EASY_ENC_SO_md_Extensions) */

/* Called by: */
struct zx_str* zx_EASY_ENC_SO_md_Extensions(struct zx_ctx* c, struct zx_md_Extensions_s* x )
{
  int len;
  char* buf;
  c->ns_tab = ZX_ALLOC(c, sizeof(zx_ns_tab));
  memcpy(c->ns_tab, zx_ns_tab, sizeof(zx_ns_tab));
  len = zx_LEN_SO_md_Extensions(c, x );
  buf = ZX_ALLOC(c, len+1);
  return zx_easy_enc_common(c, zx_ENC_SO_md_Extensions(c, x, buf ), buf, len);
}

/* FUNC(zx_EASY_ENC_WO_md_Extensions) */

/* Called by: */
struct zx_str* zx_EASY_ENC_WO_md_Extensions(struct zx_ctx* c, struct zx_md_Extensions_s* x )
{
  int len;
  char* buf;
  c->ns_tab = ZX_ALLOC(c, sizeof(zx_ns_tab));
  memcpy(c->ns_tab, zx_ns_tab, sizeof(zx_ns_tab));
  len = zx_LEN_WO_md_Extensions(c, x );
  buf = ZX_ALLOC(c, len+1);
  return zx_easy_enc_common(c, zx_ENC_WO_md_Extensions(c, x, buf ), buf, len);
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

#define EL_NAME   md_IDPSSODescriptor
#define EL_STRUCT zx_md_IDPSSODescriptor_s
#define EL_NS     md
#define EL_TAG    IDPSSODescriptor

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

/* FUNC(zx_LEN_SO_md_IDPSSODescriptor) */

/* Compute length of an element (and its subelements). The XML attributes
 * and elements are processed in schema order. */

/* Called by: */
int zx_LEN_SO_md_IDPSSODescriptor(struct zx_ctx* c, struct zx_md_IDPSSODescriptor_s* x )
{
  struct zx_ns_s* pop_seen = 0;
  struct zx_elem_s* se MAYBE_UNUSED;
#if 1 /* NORMALMODE */
  /* *** in simple_elem case should output ns prefix from ns node. */
  int len = sizeof("<md:IDPSSODescriptor")-1 + 1 + sizeof("</md:IDPSSODescriptor>")-1;
  if (c->inc_ns_len)
    len += zx_len_inc_ns(c, &pop_seen);
  len += zx_len_xmlns_if_not_seen(c, zx_ns_tab+zx_xmlns_ix_md, &pop_seen);

  len += zx_attr_so_len(x->ID, sizeof("ID")-1);
  len += zx_attr_so_len(x->WantAuthnRequestsSigned, sizeof("WantAuthnRequestsSigned")-1);
  len += zx_attr_so_len(x->cacheDuration, sizeof("cacheDuration")-1);
  len += zx_attr_so_len(x->errorURL, sizeof("errorURL")-1);
  len += zx_attr_so_len(x->protocolSupportEnumeration, sizeof("protocolSupportEnumeration")-1);
  len += zx_attr_so_len(x->validUntil, sizeof("validUntil")-1);

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
      struct zx_md_Extensions_s* e;
      for (e = x->Extensions; e; e = (struct zx_md_Extensions_s*)e->gg.g.n)
	  len += zx_LEN_SO_md_Extensions(c, e);
  }
  {
      struct zx_md_KeyDescriptor_s* e;
      for (e = x->KeyDescriptor; e; e = (struct zx_md_KeyDescriptor_s*)e->gg.g.n)
	  len += zx_LEN_SO_md_KeyDescriptor(c, e);
  }
  {
      struct zx_md_Organization_s* e;
      for (e = x->Organization; e; e = (struct zx_md_Organization_s*)e->gg.g.n)
	  len += zx_LEN_SO_md_Organization(c, e);
  }
  {
      struct zx_md_ContactPerson_s* e;
      for (e = x->ContactPerson; e; e = (struct zx_md_ContactPerson_s*)e->gg.g.n)
	  len += zx_LEN_SO_md_ContactPerson(c, e);
  }
  {
      struct zx_md_ArtifactResolutionService_s* e;
      for (e = x->ArtifactResolutionService; e; e = (struct zx_md_ArtifactResolutionService_s*)e->gg.g.n)
	  len += zx_LEN_SO_md_ArtifactResolutionService(c, e);
  }
  {
      struct zx_md_SingleLogoutService_s* e;
      for (e = x->SingleLogoutService; e; e = (struct zx_md_SingleLogoutService_s*)e->gg.g.n)
	  len += zx_LEN_SO_md_SingleLogoutService(c, e);
  }
  {
      struct zx_md_ManageNameIDService_s* e;
      for (e = x->ManageNameIDService; e; e = (struct zx_md_ManageNameIDService_s*)e->gg.g.n)
	  len += zx_LEN_SO_md_ManageNameIDService(c, e);
  }
  for (se = x->NameIDFormat; se; se = (struct zx_elem_s*)se->g.n)
    len += zx_LEN_SO_simple_elem(c,se, sizeof("md:NameIDFormat")-1, zx_ns_tab+zx_xmlns_ix_md);
  {
      struct zx_md_SingleSignOnService_s* e;
      for (e = x->SingleSignOnService; e; e = (struct zx_md_SingleSignOnService_s*)e->gg.g.n)
	  len += zx_LEN_SO_md_SingleSignOnService(c, e);
  }
  {
      struct zx_md_NameIDMappingService_s* e;
      for (e = x->NameIDMappingService; e; e = (struct zx_md_NameIDMappingService_s*)e->gg.g.n)
	  len += zx_LEN_SO_md_NameIDMappingService(c, e);
  }
  {
      struct zx_md_AssertionIDRequestService_s* e;
      for (e = x->AssertionIDRequestService; e; e = (struct zx_md_AssertionIDRequestService_s*)e->gg.g.n)
	  len += zx_LEN_SO_md_AssertionIDRequestService(c, e);
  }
  for (se = x->AttributeProfile; se; se = (struct zx_elem_s*)se->g.n)
    len += zx_LEN_SO_simple_elem(c,se, sizeof("md:AttributeProfile")-1, zx_ns_tab+zx_xmlns_ix_md);
  {
      struct zx_sa_Attribute_s* e;
      for (e = x->Attribute; e; e = (struct zx_sa_Attribute_s*)e->gg.g.n)
	  len += zx_LEN_SO_sa_Attribute(c, e);
  }


  len += zx_len_so_common(c, &x->gg);
  zx_pop_seen(pop_seen);
  ENC_LEN_DEBUG(x, "md:IDPSSODescriptor", len);
  return len;
}

/* FUNC(zx_LEN_WO_md_IDPSSODescriptor) */

/* Compute length of an element (and its subelements). The XML attributes
 * and elements are processed in wire order and no assumptions
 * are made about namespace prefixes. */

/* Called by: */
int zx_LEN_WO_md_IDPSSODescriptor(struct zx_ctx* c, struct zx_md_IDPSSODescriptor_s* x )
{
  struct zx_ns_s* pop_seen = 0;
  struct zx_elem_s* se MAYBE_UNUSED;
#if 1 /* NORMALMODE */
  int len = 1 + sizeof("IDPSSODescriptor")-1 + 1 + 2 + sizeof("IDPSSODescriptor")-1 + 1;
  
  if (x->gg.g.ns && x->gg.g.ns->prefix_len)
    len += (x->gg.g.ns->prefix_len + 1) * 2;
  if (c->inc_ns_len)
    len += zx_len_inc_ns(c, &pop_seen);
  len += zx_len_xmlns_if_not_seen(c, x->gg.g.ns, &pop_seen);

  len += zx_attr_wo_len(x->ID, sizeof("ID")-1);
  len += zx_attr_wo_len(x->WantAuthnRequestsSigned, sizeof("WantAuthnRequestsSigned")-1);
  len += zx_attr_wo_len(x->cacheDuration, sizeof("cacheDuration")-1);
  len += zx_attr_wo_len(x->errorURL, sizeof("errorURL")-1);
  len += zx_attr_wo_len(x->protocolSupportEnumeration, sizeof("protocolSupportEnumeration")-1);
  len += zx_attr_wo_len(x->validUntil, sizeof("validUntil")-1);

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
      struct zx_md_Extensions_s* e;
      for (e = x->Extensions; e; e = (struct zx_md_Extensions_s*)e->gg.g.n)
	  len += zx_LEN_WO_md_Extensions(c, e);
  }
  {
      struct zx_md_KeyDescriptor_s* e;
      for (e = x->KeyDescriptor; e; e = (struct zx_md_KeyDescriptor_s*)e->gg.g.n)
	  len += zx_LEN_WO_md_KeyDescriptor(c, e);
  }
  {
      struct zx_md_Organization_s* e;
      for (e = x->Organization; e; e = (struct zx_md_Organization_s*)e->gg.g.n)
	  len += zx_LEN_WO_md_Organization(c, e);
  }
  {
      struct zx_md_ContactPerson_s* e;
      for (e = x->ContactPerson; e; e = (struct zx_md_ContactPerson_s*)e->gg.g.n)
	  len += zx_LEN_WO_md_ContactPerson(c, e);
  }
  {
      struct zx_md_ArtifactResolutionService_s* e;
      for (e = x->ArtifactResolutionService; e; e = (struct zx_md_ArtifactResolutionService_s*)e->gg.g.n)
	  len += zx_LEN_WO_md_ArtifactResolutionService(c, e);
  }
  {
      struct zx_md_SingleLogoutService_s* e;
      for (e = x->SingleLogoutService; e; e = (struct zx_md_SingleLogoutService_s*)e->gg.g.n)
	  len += zx_LEN_WO_md_SingleLogoutService(c, e);
  }
  {
      struct zx_md_ManageNameIDService_s* e;
      for (e = x->ManageNameIDService; e; e = (struct zx_md_ManageNameIDService_s*)e->gg.g.n)
	  len += zx_LEN_WO_md_ManageNameIDService(c, e);
  }
  for (se = x->NameIDFormat; se; se = (struct zx_elem_s*)se->g.n)
    len += zx_LEN_WO_simple_elem(c, se, sizeof("NameIDFormat")-1);
  {
      struct zx_md_SingleSignOnService_s* e;
      for (e = x->SingleSignOnService; e; e = (struct zx_md_SingleSignOnService_s*)e->gg.g.n)
	  len += zx_LEN_WO_md_SingleSignOnService(c, e);
  }
  {
      struct zx_md_NameIDMappingService_s* e;
      for (e = x->NameIDMappingService; e; e = (struct zx_md_NameIDMappingService_s*)e->gg.g.n)
	  len += zx_LEN_WO_md_NameIDMappingService(c, e);
  }
  {
      struct zx_md_AssertionIDRequestService_s* e;
      for (e = x->AssertionIDRequestService; e; e = (struct zx_md_AssertionIDRequestService_s*)e->gg.g.n)
	  len += zx_LEN_WO_md_AssertionIDRequestService(c, e);
  }
  for (se = x->AttributeProfile; se; se = (struct zx_elem_s*)se->g.n)
    len += zx_LEN_WO_simple_elem(c, se, sizeof("AttributeProfile")-1);
  {
      struct zx_sa_Attribute_s* e;
      for (e = x->Attribute; e; e = (struct zx_sa_Attribute_s*)e->gg.g.n)
	  len += zx_LEN_WO_sa_Attribute(c, e);
  }


  len += zx_len_wo_common(c, &x->gg); 
  zx_pop_seen(pop_seen);
  ENC_LEN_DEBUG(x, "md:IDPSSODescriptor", len);
  return len;
}

/* FUNC(zx_ENC_SO_md_IDPSSODescriptor) */

/* Render element into string. The XML attributes and elements are
 * processed in schema order. This is what you generally want for
 * rendering new data structure to a string. The wo pointers are not used. */

/* Called by: */
char* zx_ENC_SO_md_IDPSSODescriptor(struct zx_ctx* c, struct zx_md_IDPSSODescriptor_s* x, char* p )
{
  struct zx_elem_s* se MAYBE_UNUSED;
  struct zx_ns_s* pop_seen = 0;
  ENC_LEN_DEBUG_BASE;
#if 1 /* NORMALMODE */
  /* *** in simple_elem case should output ns prefix from ns node. */
  ZX_OUT_TAG(p, "<md:IDPSSODescriptor");
  if (c->inc_ns)
    p = zx_enc_inc_ns(c, p, &pop_seen);
  p = zx_enc_xmlns_if_not_seen(c, p, zx_ns_tab+zx_xmlns_ix_md, &pop_seen);

  p = zx_attr_so_enc(p, x->ID, " ID=\"", sizeof(" ID=\"")-1);
  p = zx_attr_so_enc(p, x->WantAuthnRequestsSigned, " WantAuthnRequestsSigned=\"", sizeof(" WantAuthnRequestsSigned=\"")-1);
  p = zx_attr_so_enc(p, x->cacheDuration, " cacheDuration=\"", sizeof(" cacheDuration=\"")-1);
  p = zx_attr_so_enc(p, x->errorURL, " errorURL=\"", sizeof(" errorURL=\"")-1);
  p = zx_attr_so_enc(p, x->protocolSupportEnumeration, " protocolSupportEnumeration=\"", sizeof(" protocolSupportEnumeration=\"")-1);
  p = zx_attr_so_enc(p, x->validUntil, " validUntil=\"", sizeof(" validUntil=\"")-1);

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
      struct zx_md_Extensions_s* e;
      for (e = x->Extensions; e; e = (struct zx_md_Extensions_s*)e->gg.g.n)
	  p = zx_ENC_SO_md_Extensions(c, e, p);
  }
  {
      struct zx_md_KeyDescriptor_s* e;
      for (e = x->KeyDescriptor; e; e = (struct zx_md_KeyDescriptor_s*)e->gg.g.n)
	  p = zx_ENC_SO_md_KeyDescriptor(c, e, p);
  }
  {
      struct zx_md_Organization_s* e;
      for (e = x->Organization; e; e = (struct zx_md_Organization_s*)e->gg.g.n)
	  p = zx_ENC_SO_md_Organization(c, e, p);
  }
  {
      struct zx_md_ContactPerson_s* e;
      for (e = x->ContactPerson; e; e = (struct zx_md_ContactPerson_s*)e->gg.g.n)
	  p = zx_ENC_SO_md_ContactPerson(c, e, p);
  }
  {
      struct zx_md_ArtifactResolutionService_s* e;
      for (e = x->ArtifactResolutionService; e; e = (struct zx_md_ArtifactResolutionService_s*)e->gg.g.n)
	  p = zx_ENC_SO_md_ArtifactResolutionService(c, e, p);
  }
  {
      struct zx_md_SingleLogoutService_s* e;
      for (e = x->SingleLogoutService; e; e = (struct zx_md_SingleLogoutService_s*)e->gg.g.n)
	  p = zx_ENC_SO_md_SingleLogoutService(c, e, p);
  }
  {
      struct zx_md_ManageNameIDService_s* e;
      for (e = x->ManageNameIDService; e; e = (struct zx_md_ManageNameIDService_s*)e->gg.g.n)
	  p = zx_ENC_SO_md_ManageNameIDService(c, e, p);
  }
  for (se = x->NameIDFormat; se; se = (struct zx_elem_s*)se->g.n)
    p = zx_ENC_SO_simple_elem(c, se, p, "md:NameIDFormat", sizeof("md:NameIDFormat")-1, zx_ns_tab+zx_xmlns_ix_md);
  {
      struct zx_md_SingleSignOnService_s* e;
      for (e = x->SingleSignOnService; e; e = (struct zx_md_SingleSignOnService_s*)e->gg.g.n)
	  p = zx_ENC_SO_md_SingleSignOnService(c, e, p);
  }
  {
      struct zx_md_NameIDMappingService_s* e;
      for (e = x->NameIDMappingService; e; e = (struct zx_md_NameIDMappingService_s*)e->gg.g.n)
	  p = zx_ENC_SO_md_NameIDMappingService(c, e, p);
  }
  {
      struct zx_md_AssertionIDRequestService_s* e;
      for (e = x->AssertionIDRequestService; e; e = (struct zx_md_AssertionIDRequestService_s*)e->gg.g.n)
	  p = zx_ENC_SO_md_AssertionIDRequestService(c, e, p);
  }
  for (se = x->AttributeProfile; se; se = (struct zx_elem_s*)se->g.n)
    p = zx_ENC_SO_simple_elem(c, se, p, "md:AttributeProfile", sizeof("md:AttributeProfile")-1, zx_ns_tab+zx_xmlns_ix_md);
  {
      struct zx_sa_Attribute_s* e;
      for (e = x->Attribute; e; e = (struct zx_sa_Attribute_s*)e->gg.g.n)
	  p = zx_ENC_SO_sa_Attribute(c, e, p);
  }

  p = zx_enc_so_unknown_elems_and_content(c, p, &x->gg);
  
#if 1 /* NORMALMODE */
  ZX_OUT_CLOSE_TAG(p, "</md:IDPSSODescriptor>");
  zx_pop_seen(pop_seen);
#else
  /* root node has no end tag either */
#endif
  ENC_LEN_DEBUG(x, "md:IDPSSODescriptor", p-enc_base);
  return p;
}

/* FUNC(zx_ENC_WO_md_IDPSSODescriptor) */

/* Render element into string. The XML attributes and elements are
 * processed in wire order by chasing wo pointers. This is what you want for
 * validating signatures on other people's XML documents. */

/* Called by: */
char* zx_ENC_WO_md_IDPSSODescriptor(struct zx_ctx* c, struct zx_md_IDPSSODescriptor_s* x, char* p )
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
  ZX_OUT_MEM(p, "IDPSSODescriptor", sizeof("IDPSSODescriptor")-1);
  qq = p;

  /* *** sort the namespaces */
  if (c->inc_ns)
    zx_add_inc_ns(c, &pop_seen);
  zx_add_xmlns_if_not_seen(c, x->gg.g.ns, &pop_seen);

  p = zx_enc_seen(p, pop_seen); 
  p = zx_attr_wo_enc(p, x->ID, "ID=\"", sizeof("ID=\"")-1);
  p = zx_attr_wo_enc(p, x->WantAuthnRequestsSigned, "WantAuthnRequestsSigned=\"", sizeof("WantAuthnRequestsSigned=\"")-1);
  p = zx_attr_wo_enc(p, x->cacheDuration, "cacheDuration=\"", sizeof("cacheDuration=\"")-1);
  p = zx_attr_wo_enc(p, x->errorURL, "errorURL=\"", sizeof("errorURL=\"")-1);
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
  ENC_LEN_DEBUG(x, "md:IDPSSODescriptor", p-enc_base);
  return p;
}

/* FUNC(zx_EASY_ENC_SO_md_IDPSSODescriptor) */

/* Called by: */
struct zx_str* zx_EASY_ENC_SO_md_IDPSSODescriptor(struct zx_ctx* c, struct zx_md_IDPSSODescriptor_s* x )
{
  int len;
  char* buf;
  c->ns_tab = ZX_ALLOC(c, sizeof(zx_ns_tab));
  memcpy(c->ns_tab, zx_ns_tab, sizeof(zx_ns_tab));
  len = zx_LEN_SO_md_IDPSSODescriptor(c, x );
  buf = ZX_ALLOC(c, len+1);
  return zx_easy_enc_common(c, zx_ENC_SO_md_IDPSSODescriptor(c, x, buf ), buf, len);
}

/* FUNC(zx_EASY_ENC_WO_md_IDPSSODescriptor) */

/* Called by: */
struct zx_str* zx_EASY_ENC_WO_md_IDPSSODescriptor(struct zx_ctx* c, struct zx_md_IDPSSODescriptor_s* x )
{
  int len;
  char* buf;
  c->ns_tab = ZX_ALLOC(c, sizeof(zx_ns_tab));
  memcpy(c->ns_tab, zx_ns_tab, sizeof(zx_ns_tab));
  len = zx_LEN_WO_md_IDPSSODescriptor(c, x );
  buf = ZX_ALLOC(c, len+1);
  return zx_easy_enc_common(c, zx_ENC_WO_md_IDPSSODescriptor(c, x, buf ), buf, len);
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

#define EL_NAME   md_KeyDescriptor
#define EL_STRUCT zx_md_KeyDescriptor_s
#define EL_NS     md
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

/* FUNC(zx_LEN_SO_md_KeyDescriptor) */

/* Compute length of an element (and its subelements). The XML attributes
 * and elements are processed in schema order. */

/* Called by: */
int zx_LEN_SO_md_KeyDescriptor(struct zx_ctx* c, struct zx_md_KeyDescriptor_s* x )
{
  struct zx_ns_s* pop_seen = 0;
  struct zx_elem_s* se MAYBE_UNUSED;
#if 1 /* NORMALMODE */
  /* *** in simple_elem case should output ns prefix from ns node. */
  int len = sizeof("<md:KeyDescriptor")-1 + 1 + sizeof("</md:KeyDescriptor>")-1;
  if (c->inc_ns_len)
    len += zx_len_inc_ns(c, &pop_seen);
  len += zx_len_xmlns_if_not_seen(c, zx_ns_tab+zx_xmlns_ix_md, &pop_seen);

  len += zx_attr_so_len(x->use, sizeof("use")-1);

#else
  /* root node has no begin tag */
  int len = 0;
#endif
  
  {
      struct zx_ds_KeyInfo_s* e;
      for (e = x->KeyInfo; e; e = (struct zx_ds_KeyInfo_s*)e->gg.g.n)
	  len += zx_LEN_SO_ds_KeyInfo(c, e);
  }
  {
      struct zx_md_EncryptionMethod_s* e;
      for (e = x->EncryptionMethod; e; e = (struct zx_md_EncryptionMethod_s*)e->gg.g.n)
	  len += zx_LEN_SO_md_EncryptionMethod(c, e);
  }


  len += zx_len_so_common(c, &x->gg);
  zx_pop_seen(pop_seen);
  ENC_LEN_DEBUG(x, "md:KeyDescriptor", len);
  return len;
}

/* FUNC(zx_LEN_WO_md_KeyDescriptor) */

/* Compute length of an element (and its subelements). The XML attributes
 * and elements are processed in wire order and no assumptions
 * are made about namespace prefixes. */

/* Called by: */
int zx_LEN_WO_md_KeyDescriptor(struct zx_ctx* c, struct zx_md_KeyDescriptor_s* x )
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
  
  {
      struct zx_ds_KeyInfo_s* e;
      for (e = x->KeyInfo; e; e = (struct zx_ds_KeyInfo_s*)e->gg.g.n)
	  len += zx_LEN_WO_ds_KeyInfo(c, e);
  }
  {
      struct zx_md_EncryptionMethod_s* e;
      for (e = x->EncryptionMethod; e; e = (struct zx_md_EncryptionMethod_s*)e->gg.g.n)
	  len += zx_LEN_WO_md_EncryptionMethod(c, e);
  }


  len += zx_len_wo_common(c, &x->gg); 
  zx_pop_seen(pop_seen);
  ENC_LEN_DEBUG(x, "md:KeyDescriptor", len);
  return len;
}

/* FUNC(zx_ENC_SO_md_KeyDescriptor) */

/* Render element into string. The XML attributes and elements are
 * processed in schema order. This is what you generally want for
 * rendering new data structure to a string. The wo pointers are not used. */

/* Called by: */
char* zx_ENC_SO_md_KeyDescriptor(struct zx_ctx* c, struct zx_md_KeyDescriptor_s* x, char* p )
{
  struct zx_elem_s* se MAYBE_UNUSED;
  struct zx_ns_s* pop_seen = 0;
  ENC_LEN_DEBUG_BASE;
#if 1 /* NORMALMODE */
  /* *** in simple_elem case should output ns prefix from ns node. */
  ZX_OUT_TAG(p, "<md:KeyDescriptor");
  if (c->inc_ns)
    p = zx_enc_inc_ns(c, p, &pop_seen);
  p = zx_enc_xmlns_if_not_seen(c, p, zx_ns_tab+zx_xmlns_ix_md, &pop_seen);

  p = zx_attr_so_enc(p, x->use, " use=\"", sizeof(" use=\"")-1);

  p = zx_enc_unknown_attrs(p, x->gg.any_attr);
#else
  /* root node has no begin tag */
#endif
  
  {
      struct zx_ds_KeyInfo_s* e;
      for (e = x->KeyInfo; e; e = (struct zx_ds_KeyInfo_s*)e->gg.g.n)
	  p = zx_ENC_SO_ds_KeyInfo(c, e, p);
  }
  {
      struct zx_md_EncryptionMethod_s* e;
      for (e = x->EncryptionMethod; e; e = (struct zx_md_EncryptionMethod_s*)e->gg.g.n)
	  p = zx_ENC_SO_md_EncryptionMethod(c, e, p);
  }

  p = zx_enc_so_unknown_elems_and_content(c, p, &x->gg);
  
#if 1 /* NORMALMODE */
  ZX_OUT_CLOSE_TAG(p, "</md:KeyDescriptor>");
  zx_pop_seen(pop_seen);
#else
  /* root node has no end tag either */
#endif
  ENC_LEN_DEBUG(x, "md:KeyDescriptor", p-enc_base);
  return p;
}

/* FUNC(zx_ENC_WO_md_KeyDescriptor) */

/* Render element into string. The XML attributes and elements are
 * processed in wire order by chasing wo pointers. This is what you want for
 * validating signatures on other people's XML documents. */

/* Called by: */
char* zx_ENC_WO_md_KeyDescriptor(struct zx_ctx* c, struct zx_md_KeyDescriptor_s* x, char* p )
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
  ENC_LEN_DEBUG(x, "md:KeyDescriptor", p-enc_base);
  return p;
}

/* FUNC(zx_EASY_ENC_SO_md_KeyDescriptor) */

/* Called by: */
struct zx_str* zx_EASY_ENC_SO_md_KeyDescriptor(struct zx_ctx* c, struct zx_md_KeyDescriptor_s* x )
{
  int len;
  char* buf;
  c->ns_tab = ZX_ALLOC(c, sizeof(zx_ns_tab));
  memcpy(c->ns_tab, zx_ns_tab, sizeof(zx_ns_tab));
  len = zx_LEN_SO_md_KeyDescriptor(c, x );
  buf = ZX_ALLOC(c, len+1);
  return zx_easy_enc_common(c, zx_ENC_SO_md_KeyDescriptor(c, x, buf ), buf, len);
}

/* FUNC(zx_EASY_ENC_WO_md_KeyDescriptor) */

/* Called by: */
struct zx_str* zx_EASY_ENC_WO_md_KeyDescriptor(struct zx_ctx* c, struct zx_md_KeyDescriptor_s* x )
{
  int len;
  char* buf;
  c->ns_tab = ZX_ALLOC(c, sizeof(zx_ns_tab));
  memcpy(c->ns_tab, zx_ns_tab, sizeof(zx_ns_tab));
  len = zx_LEN_WO_md_KeyDescriptor(c, x );
  buf = ZX_ALLOC(c, len+1);
  return zx_easy_enc_common(c, zx_ENC_WO_md_KeyDescriptor(c, x, buf ), buf, len);
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

#define EL_NAME   md_ManageNameIDService
#define EL_STRUCT zx_md_ManageNameIDService_s
#define EL_NS     md
#define EL_TAG    ManageNameIDService

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

/* FUNC(zx_LEN_SO_md_ManageNameIDService) */

/* Compute length of an element (and its subelements). The XML attributes
 * and elements are processed in schema order. */

/* Called by: */
int zx_LEN_SO_md_ManageNameIDService(struct zx_ctx* c, struct zx_md_ManageNameIDService_s* x )
{
  struct zx_ns_s* pop_seen = 0;
  struct zx_elem_s* se MAYBE_UNUSED;
#if 1 /* NORMALMODE */
  /* *** in simple_elem case should output ns prefix from ns node. */
  int len = sizeof("<md:ManageNameIDService")-1 + 1 + sizeof("</md:ManageNameIDService>")-1;
  if (c->inc_ns_len)
    len += zx_len_inc_ns(c, &pop_seen);
  len += zx_len_xmlns_if_not_seen(c, zx_ns_tab+zx_xmlns_ix_md, &pop_seen);

  len += zx_attr_so_len(x->Binding, sizeof("Binding")-1);
  len += zx_attr_so_len(x->Location, sizeof("Location")-1);
  len += zx_attr_so_len(x->ResponseLocation, sizeof("ResponseLocation")-1);
  len += zx_attr_so_len(x->index, sizeof("index")-1);
  len += zx_attr_so_len(x->isDefault, sizeof("isDefault")-1);

#else
  /* root node has no begin tag */
  int len = 0;
#endif
  


  len += zx_len_so_common(c, &x->gg);
  zx_pop_seen(pop_seen);
  ENC_LEN_DEBUG(x, "md:ManageNameIDService", len);
  return len;
}

/* FUNC(zx_LEN_WO_md_ManageNameIDService) */

/* Compute length of an element (and its subelements). The XML attributes
 * and elements are processed in wire order and no assumptions
 * are made about namespace prefixes. */

/* Called by: */
int zx_LEN_WO_md_ManageNameIDService(struct zx_ctx* c, struct zx_md_ManageNameIDService_s* x )
{
  struct zx_ns_s* pop_seen = 0;
  struct zx_elem_s* se MAYBE_UNUSED;
#if 1 /* NORMALMODE */
  int len = 1 + sizeof("ManageNameIDService")-1 + 1 + 2 + sizeof("ManageNameIDService")-1 + 1;
  
  if (x->gg.g.ns && x->gg.g.ns->prefix_len)
    len += (x->gg.g.ns->prefix_len + 1) * 2;
  if (c->inc_ns_len)
    len += zx_len_inc_ns(c, &pop_seen);
  len += zx_len_xmlns_if_not_seen(c, x->gg.g.ns, &pop_seen);

  len += zx_attr_wo_len(x->Binding, sizeof("Binding")-1);
  len += zx_attr_wo_len(x->Location, sizeof("Location")-1);
  len += zx_attr_wo_len(x->ResponseLocation, sizeof("ResponseLocation")-1);
  len += zx_attr_wo_len(x->index, sizeof("index")-1);
  len += zx_attr_wo_len(x->isDefault, sizeof("isDefault")-1);

#else
  /* root node has no begin tag */
  int len = 0;
#endif
  


  len += zx_len_wo_common(c, &x->gg); 
  zx_pop_seen(pop_seen);
  ENC_LEN_DEBUG(x, "md:ManageNameIDService", len);
  return len;
}

/* FUNC(zx_ENC_SO_md_ManageNameIDService) */

/* Render element into string. The XML attributes and elements are
 * processed in schema order. This is what you generally want for
 * rendering new data structure to a string. The wo pointers are not used. */

/* Called by: */
char* zx_ENC_SO_md_ManageNameIDService(struct zx_ctx* c, struct zx_md_ManageNameIDService_s* x, char* p )
{
  struct zx_elem_s* se MAYBE_UNUSED;
  struct zx_ns_s* pop_seen = 0;
  ENC_LEN_DEBUG_BASE;
#if 1 /* NORMALMODE */
  /* *** in simple_elem case should output ns prefix from ns node. */
  ZX_OUT_TAG(p, "<md:ManageNameIDService");
  if (c->inc_ns)
    p = zx_enc_inc_ns(c, p, &pop_seen);
  p = zx_enc_xmlns_if_not_seen(c, p, zx_ns_tab+zx_xmlns_ix_md, &pop_seen);

  p = zx_attr_so_enc(p, x->Binding, " Binding=\"", sizeof(" Binding=\"")-1);
  p = zx_attr_so_enc(p, x->Location, " Location=\"", sizeof(" Location=\"")-1);
  p = zx_attr_so_enc(p, x->ResponseLocation, " ResponseLocation=\"", sizeof(" ResponseLocation=\"")-1);
  p = zx_attr_so_enc(p, x->index, " index=\"", sizeof(" index=\"")-1);
  p = zx_attr_so_enc(p, x->isDefault, " isDefault=\"", sizeof(" isDefault=\"")-1);

  p = zx_enc_unknown_attrs(p, x->gg.any_attr);
#else
  /* root node has no begin tag */
#endif
  

  p = zx_enc_so_unknown_elems_and_content(c, p, &x->gg);
  
#if 1 /* NORMALMODE */
  ZX_OUT_CLOSE_TAG(p, "</md:ManageNameIDService>");
  zx_pop_seen(pop_seen);
#else
  /* root node has no end tag either */
#endif
  ENC_LEN_DEBUG(x, "md:ManageNameIDService", p-enc_base);
  return p;
}

/* FUNC(zx_ENC_WO_md_ManageNameIDService) */

/* Render element into string. The XML attributes and elements are
 * processed in wire order by chasing wo pointers. This is what you want for
 * validating signatures on other people's XML documents. */

/* Called by: */
char* zx_ENC_WO_md_ManageNameIDService(struct zx_ctx* c, struct zx_md_ManageNameIDService_s* x, char* p )
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
  ZX_OUT_MEM(p, "ManageNameIDService", sizeof("ManageNameIDService")-1);
  qq = p;

  /* *** sort the namespaces */
  if (c->inc_ns)
    zx_add_inc_ns(c, &pop_seen);
  zx_add_xmlns_if_not_seen(c, x->gg.g.ns, &pop_seen);

  p = zx_enc_seen(p, pop_seen); 
  p = zx_attr_wo_enc(p, x->Binding, "Binding=\"", sizeof("Binding=\"")-1);
  p = zx_attr_wo_enc(p, x->Location, "Location=\"", sizeof("Location=\"")-1);
  p = zx_attr_wo_enc(p, x->ResponseLocation, "ResponseLocation=\"", sizeof("ResponseLocation=\"")-1);
  p = zx_attr_wo_enc(p, x->index, "index=\"", sizeof("index=\"")-1);
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
  ENC_LEN_DEBUG(x, "md:ManageNameIDService", p-enc_base);
  return p;
}

/* FUNC(zx_EASY_ENC_SO_md_ManageNameIDService) */

/* Called by: */
struct zx_str* zx_EASY_ENC_SO_md_ManageNameIDService(struct zx_ctx* c, struct zx_md_ManageNameIDService_s* x )
{
  int len;
  char* buf;
  c->ns_tab = ZX_ALLOC(c, sizeof(zx_ns_tab));
  memcpy(c->ns_tab, zx_ns_tab, sizeof(zx_ns_tab));
  len = zx_LEN_SO_md_ManageNameIDService(c, x );
  buf = ZX_ALLOC(c, len+1);
  return zx_easy_enc_common(c, zx_ENC_SO_md_ManageNameIDService(c, x, buf ), buf, len);
}

/* FUNC(zx_EASY_ENC_WO_md_ManageNameIDService) */

/* Called by: */
struct zx_str* zx_EASY_ENC_WO_md_ManageNameIDService(struct zx_ctx* c, struct zx_md_ManageNameIDService_s* x )
{
  int len;
  char* buf;
  c->ns_tab = ZX_ALLOC(c, sizeof(zx_ns_tab));
  memcpy(c->ns_tab, zx_ns_tab, sizeof(zx_ns_tab));
  len = zx_LEN_WO_md_ManageNameIDService(c, x );
  buf = ZX_ALLOC(c, len+1);
  return zx_easy_enc_common(c, zx_ENC_WO_md_ManageNameIDService(c, x, buf ), buf, len);
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

#define EL_NAME   md_NameIDMappingService
#define EL_STRUCT zx_md_NameIDMappingService_s
#define EL_NS     md
#define EL_TAG    NameIDMappingService

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

/* FUNC(zx_LEN_SO_md_NameIDMappingService) */

/* Compute length of an element (and its subelements). The XML attributes
 * and elements are processed in schema order. */

/* Called by: */
int zx_LEN_SO_md_NameIDMappingService(struct zx_ctx* c, struct zx_md_NameIDMappingService_s* x )
{
  struct zx_ns_s* pop_seen = 0;
  struct zx_elem_s* se MAYBE_UNUSED;
#if 1 /* NORMALMODE */
  /* *** in simple_elem case should output ns prefix from ns node. */
  int len = sizeof("<md:NameIDMappingService")-1 + 1 + sizeof("</md:NameIDMappingService>")-1;
  if (c->inc_ns_len)
    len += zx_len_inc_ns(c, &pop_seen);
  len += zx_len_xmlns_if_not_seen(c, zx_ns_tab+zx_xmlns_ix_md, &pop_seen);

  len += zx_attr_so_len(x->Binding, sizeof("Binding")-1);
  len += zx_attr_so_len(x->Location, sizeof("Location")-1);
  len += zx_attr_so_len(x->ResponseLocation, sizeof("ResponseLocation")-1);
  len += zx_attr_so_len(x->index, sizeof("index")-1);
  len += zx_attr_so_len(x->isDefault, sizeof("isDefault")-1);

#else
  /* root node has no begin tag */
  int len = 0;
#endif
  


  len += zx_len_so_common(c, &x->gg);
  zx_pop_seen(pop_seen);
  ENC_LEN_DEBUG(x, "md:NameIDMappingService", len);
  return len;
}

/* FUNC(zx_LEN_WO_md_NameIDMappingService) */

/* Compute length of an element (and its subelements). The XML attributes
 * and elements are processed in wire order and no assumptions
 * are made about namespace prefixes. */

/* Called by: */
int zx_LEN_WO_md_NameIDMappingService(struct zx_ctx* c, struct zx_md_NameIDMappingService_s* x )
{
  struct zx_ns_s* pop_seen = 0;
  struct zx_elem_s* se MAYBE_UNUSED;
#if 1 /* NORMALMODE */
  int len = 1 + sizeof("NameIDMappingService")-1 + 1 + 2 + sizeof("NameIDMappingService")-1 + 1;
  
  if (x->gg.g.ns && x->gg.g.ns->prefix_len)
    len += (x->gg.g.ns->prefix_len + 1) * 2;
  if (c->inc_ns_len)
    len += zx_len_inc_ns(c, &pop_seen);
  len += zx_len_xmlns_if_not_seen(c, x->gg.g.ns, &pop_seen);

  len += zx_attr_wo_len(x->Binding, sizeof("Binding")-1);
  len += zx_attr_wo_len(x->Location, sizeof("Location")-1);
  len += zx_attr_wo_len(x->ResponseLocation, sizeof("ResponseLocation")-1);
  len += zx_attr_wo_len(x->index, sizeof("index")-1);
  len += zx_attr_wo_len(x->isDefault, sizeof("isDefault")-1);

#else
  /* root node has no begin tag */
  int len = 0;
#endif
  


  len += zx_len_wo_common(c, &x->gg); 
  zx_pop_seen(pop_seen);
  ENC_LEN_DEBUG(x, "md:NameIDMappingService", len);
  return len;
}

/* FUNC(zx_ENC_SO_md_NameIDMappingService) */

/* Render element into string. The XML attributes and elements are
 * processed in schema order. This is what you generally want for
 * rendering new data structure to a string. The wo pointers are not used. */

/* Called by: */
char* zx_ENC_SO_md_NameIDMappingService(struct zx_ctx* c, struct zx_md_NameIDMappingService_s* x, char* p )
{
  struct zx_elem_s* se MAYBE_UNUSED;
  struct zx_ns_s* pop_seen = 0;
  ENC_LEN_DEBUG_BASE;
#if 1 /* NORMALMODE */
  /* *** in simple_elem case should output ns prefix from ns node. */
  ZX_OUT_TAG(p, "<md:NameIDMappingService");
  if (c->inc_ns)
    p = zx_enc_inc_ns(c, p, &pop_seen);
  p = zx_enc_xmlns_if_not_seen(c, p, zx_ns_tab+zx_xmlns_ix_md, &pop_seen);

  p = zx_attr_so_enc(p, x->Binding, " Binding=\"", sizeof(" Binding=\"")-1);
  p = zx_attr_so_enc(p, x->Location, " Location=\"", sizeof(" Location=\"")-1);
  p = zx_attr_so_enc(p, x->ResponseLocation, " ResponseLocation=\"", sizeof(" ResponseLocation=\"")-1);
  p = zx_attr_so_enc(p, x->index, " index=\"", sizeof(" index=\"")-1);
  p = zx_attr_so_enc(p, x->isDefault, " isDefault=\"", sizeof(" isDefault=\"")-1);

  p = zx_enc_unknown_attrs(p, x->gg.any_attr);
#else
  /* root node has no begin tag */
#endif
  

  p = zx_enc_so_unknown_elems_and_content(c, p, &x->gg);
  
#if 1 /* NORMALMODE */
  ZX_OUT_CLOSE_TAG(p, "</md:NameIDMappingService>");
  zx_pop_seen(pop_seen);
#else
  /* root node has no end tag either */
#endif
  ENC_LEN_DEBUG(x, "md:NameIDMappingService", p-enc_base);
  return p;
}

/* FUNC(zx_ENC_WO_md_NameIDMappingService) */

/* Render element into string. The XML attributes and elements are
 * processed in wire order by chasing wo pointers. This is what you want for
 * validating signatures on other people's XML documents. */

/* Called by: */
char* zx_ENC_WO_md_NameIDMappingService(struct zx_ctx* c, struct zx_md_NameIDMappingService_s* x, char* p )
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
  ZX_OUT_MEM(p, "NameIDMappingService", sizeof("NameIDMappingService")-1);
  qq = p;

  /* *** sort the namespaces */
  if (c->inc_ns)
    zx_add_inc_ns(c, &pop_seen);
  zx_add_xmlns_if_not_seen(c, x->gg.g.ns, &pop_seen);

  p = zx_enc_seen(p, pop_seen); 
  p = zx_attr_wo_enc(p, x->Binding, "Binding=\"", sizeof("Binding=\"")-1);
  p = zx_attr_wo_enc(p, x->Location, "Location=\"", sizeof("Location=\"")-1);
  p = zx_attr_wo_enc(p, x->ResponseLocation, "ResponseLocation=\"", sizeof("ResponseLocation=\"")-1);
  p = zx_attr_wo_enc(p, x->index, "index=\"", sizeof("index=\"")-1);
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
  ENC_LEN_DEBUG(x, "md:NameIDMappingService", p-enc_base);
  return p;
}

/* FUNC(zx_EASY_ENC_SO_md_NameIDMappingService) */

/* Called by: */
struct zx_str* zx_EASY_ENC_SO_md_NameIDMappingService(struct zx_ctx* c, struct zx_md_NameIDMappingService_s* x )
{
  int len;
  char* buf;
  c->ns_tab = ZX_ALLOC(c, sizeof(zx_ns_tab));
  memcpy(c->ns_tab, zx_ns_tab, sizeof(zx_ns_tab));
  len = zx_LEN_SO_md_NameIDMappingService(c, x );
  buf = ZX_ALLOC(c, len+1);
  return zx_easy_enc_common(c, zx_ENC_SO_md_NameIDMappingService(c, x, buf ), buf, len);
}

/* FUNC(zx_EASY_ENC_WO_md_NameIDMappingService) */

/* Called by: */
struct zx_str* zx_EASY_ENC_WO_md_NameIDMappingService(struct zx_ctx* c, struct zx_md_NameIDMappingService_s* x )
{
  int len;
  char* buf;
  c->ns_tab = ZX_ALLOC(c, sizeof(zx_ns_tab));
  memcpy(c->ns_tab, zx_ns_tab, sizeof(zx_ns_tab));
  len = zx_LEN_WO_md_NameIDMappingService(c, x );
  buf = ZX_ALLOC(c, len+1);
  return zx_easy_enc_common(c, zx_ENC_WO_md_NameIDMappingService(c, x, buf ), buf, len);
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

#define EL_NAME   md_Organization
#define EL_STRUCT zx_md_Organization_s
#define EL_NS     md
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

/* FUNC(zx_LEN_SO_md_Organization) */

/* Compute length of an element (and its subelements). The XML attributes
 * and elements are processed in schema order. */

/* Called by: */
int zx_LEN_SO_md_Organization(struct zx_ctx* c, struct zx_md_Organization_s* x )
{
  struct zx_ns_s* pop_seen = 0;
  struct zx_elem_s* se MAYBE_UNUSED;
#if 1 /* NORMALMODE */
  /* *** in simple_elem case should output ns prefix from ns node. */
  int len = sizeof("<md:Organization")-1 + 1 + sizeof("</md:Organization>")-1;
  if (c->inc_ns_len)
    len += zx_len_inc_ns(c, &pop_seen);
  len += zx_len_xmlns_if_not_seen(c, zx_ns_tab+zx_xmlns_ix_md, &pop_seen);


#else
  /* root node has no begin tag */
  int len = 0;
#endif
  
  {
      struct zx_md_Extensions_s* e;
      for (e = x->Extensions; e; e = (struct zx_md_Extensions_s*)e->gg.g.n)
	  len += zx_LEN_SO_md_Extensions(c, e);
  }
  {
      struct zx_md_OrganizationName_s* e;
      for (e = x->OrganizationName; e; e = (struct zx_md_OrganizationName_s*)e->gg.g.n)
	  len += zx_LEN_SO_md_OrganizationName(c, e);
  }
  {
      struct zx_md_OrganizationDisplayName_s* e;
      for (e = x->OrganizationDisplayName; e; e = (struct zx_md_OrganizationDisplayName_s*)e->gg.g.n)
	  len += zx_LEN_SO_md_OrganizationDisplayName(c, e);
  }
  {
      struct zx_md_OrganizationURL_s* e;
      for (e = x->OrganizationURL; e; e = (struct zx_md_OrganizationURL_s*)e->gg.g.n)
	  len += zx_LEN_SO_md_OrganizationURL(c, e);
  }


  len += zx_len_so_common(c, &x->gg);
  zx_pop_seen(pop_seen);
  ENC_LEN_DEBUG(x, "md:Organization", len);
  return len;
}

/* FUNC(zx_LEN_WO_md_Organization) */

/* Compute length of an element (and its subelements). The XML attributes
 * and elements are processed in wire order and no assumptions
 * are made about namespace prefixes. */

/* Called by: */
int zx_LEN_WO_md_Organization(struct zx_ctx* c, struct zx_md_Organization_s* x )
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
      struct zx_md_Extensions_s* e;
      for (e = x->Extensions; e; e = (struct zx_md_Extensions_s*)e->gg.g.n)
	  len += zx_LEN_WO_md_Extensions(c, e);
  }
  {
      struct zx_md_OrganizationName_s* e;
      for (e = x->OrganizationName; e; e = (struct zx_md_OrganizationName_s*)e->gg.g.n)
	  len += zx_LEN_WO_md_OrganizationName(c, e);
  }
  {
      struct zx_md_OrganizationDisplayName_s* e;
      for (e = x->OrganizationDisplayName; e; e = (struct zx_md_OrganizationDisplayName_s*)e->gg.g.n)
	  len += zx_LEN_WO_md_OrganizationDisplayName(c, e);
  }
  {
      struct zx_md_OrganizationURL_s* e;
      for (e = x->OrganizationURL; e; e = (struct zx_md_OrganizationURL_s*)e->gg.g.n)
	  len += zx_LEN_WO_md_OrganizationURL(c, e);
  }


  len += zx_len_wo_common(c, &x->gg); 
  zx_pop_seen(pop_seen);
  ENC_LEN_DEBUG(x, "md:Organization", len);
  return len;
}

/* FUNC(zx_ENC_SO_md_Organization) */

/* Render element into string. The XML attributes and elements are
 * processed in schema order. This is what you generally want for
 * rendering new data structure to a string. The wo pointers are not used. */

/* Called by: */
char* zx_ENC_SO_md_Organization(struct zx_ctx* c, struct zx_md_Organization_s* x, char* p )
{
  struct zx_elem_s* se MAYBE_UNUSED;
  struct zx_ns_s* pop_seen = 0;
  ENC_LEN_DEBUG_BASE;
#if 1 /* NORMALMODE */
  /* *** in simple_elem case should output ns prefix from ns node. */
  ZX_OUT_TAG(p, "<md:Organization");
  if (c->inc_ns)
    p = zx_enc_inc_ns(c, p, &pop_seen);
  p = zx_enc_xmlns_if_not_seen(c, p, zx_ns_tab+zx_xmlns_ix_md, &pop_seen);


  p = zx_enc_unknown_attrs(p, x->gg.any_attr);
#else
  /* root node has no begin tag */
#endif
  
  {
      struct zx_md_Extensions_s* e;
      for (e = x->Extensions; e; e = (struct zx_md_Extensions_s*)e->gg.g.n)
	  p = zx_ENC_SO_md_Extensions(c, e, p);
  }
  {
      struct zx_md_OrganizationName_s* e;
      for (e = x->OrganizationName; e; e = (struct zx_md_OrganizationName_s*)e->gg.g.n)
	  p = zx_ENC_SO_md_OrganizationName(c, e, p);
  }
  {
      struct zx_md_OrganizationDisplayName_s* e;
      for (e = x->OrganizationDisplayName; e; e = (struct zx_md_OrganizationDisplayName_s*)e->gg.g.n)
	  p = zx_ENC_SO_md_OrganizationDisplayName(c, e, p);
  }
  {
      struct zx_md_OrganizationURL_s* e;
      for (e = x->OrganizationURL; e; e = (struct zx_md_OrganizationURL_s*)e->gg.g.n)
	  p = zx_ENC_SO_md_OrganizationURL(c, e, p);
  }

  p = zx_enc_so_unknown_elems_and_content(c, p, &x->gg);
  
#if 1 /* NORMALMODE */
  ZX_OUT_CLOSE_TAG(p, "</md:Organization>");
  zx_pop_seen(pop_seen);
#else
  /* root node has no end tag either */
#endif
  ENC_LEN_DEBUG(x, "md:Organization", p-enc_base);
  return p;
}

/* FUNC(zx_ENC_WO_md_Organization) */

/* Render element into string. The XML attributes and elements are
 * processed in wire order by chasing wo pointers. This is what you want for
 * validating signatures on other people's XML documents. */

/* Called by: */
char* zx_ENC_WO_md_Organization(struct zx_ctx* c, struct zx_md_Organization_s* x, char* p )
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
  ENC_LEN_DEBUG(x, "md:Organization", p-enc_base);
  return p;
}

/* FUNC(zx_EASY_ENC_SO_md_Organization) */

/* Called by: */
struct zx_str* zx_EASY_ENC_SO_md_Organization(struct zx_ctx* c, struct zx_md_Organization_s* x )
{
  int len;
  char* buf;
  c->ns_tab = ZX_ALLOC(c, sizeof(zx_ns_tab));
  memcpy(c->ns_tab, zx_ns_tab, sizeof(zx_ns_tab));
  len = zx_LEN_SO_md_Organization(c, x );
  buf = ZX_ALLOC(c, len+1);
  return zx_easy_enc_common(c, zx_ENC_SO_md_Organization(c, x, buf ), buf, len);
}

/* FUNC(zx_EASY_ENC_WO_md_Organization) */

/* Called by: */
struct zx_str* zx_EASY_ENC_WO_md_Organization(struct zx_ctx* c, struct zx_md_Organization_s* x )
{
  int len;
  char* buf;
  c->ns_tab = ZX_ALLOC(c, sizeof(zx_ns_tab));
  memcpy(c->ns_tab, zx_ns_tab, sizeof(zx_ns_tab));
  len = zx_LEN_WO_md_Organization(c, x );
  buf = ZX_ALLOC(c, len+1);
  return zx_easy_enc_common(c, zx_ENC_WO_md_Organization(c, x, buf ), buf, len);
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

#define EL_NAME   md_OrganizationDisplayName
#define EL_STRUCT zx_md_OrganizationDisplayName_s
#define EL_NS     md
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

/* FUNC(zx_LEN_SO_md_OrganizationDisplayName) */

/* Compute length of an element (and its subelements). The XML attributes
 * and elements are processed in schema order. */

/* Called by: */
int zx_LEN_SO_md_OrganizationDisplayName(struct zx_ctx* c, struct zx_md_OrganizationDisplayName_s* x )
{
  struct zx_ns_s* pop_seen = 0;
  struct zx_elem_s* se MAYBE_UNUSED;
#if 1 /* NORMALMODE */
  /* *** in simple_elem case should output ns prefix from ns node. */
  int len = sizeof("<md:OrganizationDisplayName")-1 + 1 + sizeof("</md:OrganizationDisplayName>")-1;
  if (c->inc_ns_len)
    len += zx_len_inc_ns(c, &pop_seen);
  len += zx_len_xmlns_if_not_seen(c, zx_ns_tab+zx_xmlns_ix_md, &pop_seen);
  if (x->lang)
    len += zx_len_xmlns_if_not_seen(c, zx_ns_tab+zx_xmlns_ix_xml, &pop_seen);

  len += zx_attr_so_len(x->lang, sizeof("xml:lang")-1);

#else
  /* root node has no begin tag */
  int len = 0;
#endif
  


  len += zx_len_so_common(c, &x->gg);
  zx_pop_seen(pop_seen);
  ENC_LEN_DEBUG(x, "md:OrganizationDisplayName", len);
  return len;
}

/* FUNC(zx_LEN_WO_md_OrganizationDisplayName) */

/* Compute length of an element (and its subelements). The XML attributes
 * and elements are processed in wire order and no assumptions
 * are made about namespace prefixes. */

/* Called by: */
int zx_LEN_WO_md_OrganizationDisplayName(struct zx_ctx* c, struct zx_md_OrganizationDisplayName_s* x )
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
  if (x->lang)
    len += zx_len_xmlns_if_not_seen(c, x->lang->g.ns, &pop_seen);

  len += zx_attr_wo_len(x->lang, sizeof("lang")-1);

#else
  /* root node has no begin tag */
  int len = 0;
#endif
  


  len += zx_len_wo_common(c, &x->gg); 
  zx_pop_seen(pop_seen);
  ENC_LEN_DEBUG(x, "md:OrganizationDisplayName", len);
  return len;
}

/* FUNC(zx_ENC_SO_md_OrganizationDisplayName) */

/* Render element into string. The XML attributes and elements are
 * processed in schema order. This is what you generally want for
 * rendering new data structure to a string. The wo pointers are not used. */

/* Called by: */
char* zx_ENC_SO_md_OrganizationDisplayName(struct zx_ctx* c, struct zx_md_OrganizationDisplayName_s* x, char* p )
{
  struct zx_elem_s* se MAYBE_UNUSED;
  struct zx_ns_s* pop_seen = 0;
  ENC_LEN_DEBUG_BASE;
#if 1 /* NORMALMODE */
  /* *** in simple_elem case should output ns prefix from ns node. */
  ZX_OUT_TAG(p, "<md:OrganizationDisplayName");
  if (c->inc_ns)
    p = zx_enc_inc_ns(c, p, &pop_seen);
  p = zx_enc_xmlns_if_not_seen(c, p, zx_ns_tab+zx_xmlns_ix_md, &pop_seen);
  if (x->lang)
    p = zx_enc_xmlns_if_not_seen(c, p, zx_ns_tab+zx_xmlns_ix_xml, &pop_seen);

  p = zx_attr_so_enc(p, x->lang, " xml:lang=\"", sizeof(" xml:lang=\"")-1);

  p = zx_enc_unknown_attrs(p, x->gg.any_attr);
#else
  /* root node has no begin tag */
#endif
  

  p = zx_enc_so_unknown_elems_and_content(c, p, &x->gg);
  
#if 1 /* NORMALMODE */
  ZX_OUT_CLOSE_TAG(p, "</md:OrganizationDisplayName>");
  zx_pop_seen(pop_seen);
#else
  /* root node has no end tag either */
#endif
  ENC_LEN_DEBUG(x, "md:OrganizationDisplayName", p-enc_base);
  return p;
}

/* FUNC(zx_ENC_WO_md_OrganizationDisplayName) */

/* Render element into string. The XML attributes and elements are
 * processed in wire order by chasing wo pointers. This is what you want for
 * validating signatures on other people's XML documents. */

/* Called by: */
char* zx_ENC_WO_md_OrganizationDisplayName(struct zx_ctx* c, struct zx_md_OrganizationDisplayName_s* x, char* p )
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
  if (x->lang)
    zx_add_xmlns_if_not_seen(c, x->lang->g.ns, &pop_seen);

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
  ENC_LEN_DEBUG(x, "md:OrganizationDisplayName", p-enc_base);
  return p;
}

/* FUNC(zx_EASY_ENC_SO_md_OrganizationDisplayName) */

/* Called by: */
struct zx_str* zx_EASY_ENC_SO_md_OrganizationDisplayName(struct zx_ctx* c, struct zx_md_OrganizationDisplayName_s* x )
{
  int len;
  char* buf;
  c->ns_tab = ZX_ALLOC(c, sizeof(zx_ns_tab));
  memcpy(c->ns_tab, zx_ns_tab, sizeof(zx_ns_tab));
  len = zx_LEN_SO_md_OrganizationDisplayName(c, x );
  buf = ZX_ALLOC(c, len+1);
  return zx_easy_enc_common(c, zx_ENC_SO_md_OrganizationDisplayName(c, x, buf ), buf, len);
}

/* FUNC(zx_EASY_ENC_WO_md_OrganizationDisplayName) */

/* Called by: */
struct zx_str* zx_EASY_ENC_WO_md_OrganizationDisplayName(struct zx_ctx* c, struct zx_md_OrganizationDisplayName_s* x )
{
  int len;
  char* buf;
  c->ns_tab = ZX_ALLOC(c, sizeof(zx_ns_tab));
  memcpy(c->ns_tab, zx_ns_tab, sizeof(zx_ns_tab));
  len = zx_LEN_WO_md_OrganizationDisplayName(c, x );
  buf = ZX_ALLOC(c, len+1);
  return zx_easy_enc_common(c, zx_ENC_WO_md_OrganizationDisplayName(c, x, buf ), buf, len);
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

#define EL_NAME   md_OrganizationName
#define EL_STRUCT zx_md_OrganizationName_s
#define EL_NS     md
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

/* FUNC(zx_LEN_SO_md_OrganizationName) */

/* Compute length of an element (and its subelements). The XML attributes
 * and elements are processed in schema order. */

/* Called by: */
int zx_LEN_SO_md_OrganizationName(struct zx_ctx* c, struct zx_md_OrganizationName_s* x )
{
  struct zx_ns_s* pop_seen = 0;
  struct zx_elem_s* se MAYBE_UNUSED;
#if 1 /* NORMALMODE */
  /* *** in simple_elem case should output ns prefix from ns node. */
  int len = sizeof("<md:OrganizationName")-1 + 1 + sizeof("</md:OrganizationName>")-1;
  if (c->inc_ns_len)
    len += zx_len_inc_ns(c, &pop_seen);
  len += zx_len_xmlns_if_not_seen(c, zx_ns_tab+zx_xmlns_ix_md, &pop_seen);
  if (x->lang)
    len += zx_len_xmlns_if_not_seen(c, zx_ns_tab+zx_xmlns_ix_xml, &pop_seen);

  len += zx_attr_so_len(x->lang, sizeof("xml:lang")-1);

#else
  /* root node has no begin tag */
  int len = 0;
#endif
  


  len += zx_len_so_common(c, &x->gg);
  zx_pop_seen(pop_seen);
  ENC_LEN_DEBUG(x, "md:OrganizationName", len);
  return len;
}

/* FUNC(zx_LEN_WO_md_OrganizationName) */

/* Compute length of an element (and its subelements). The XML attributes
 * and elements are processed in wire order and no assumptions
 * are made about namespace prefixes. */

/* Called by: */
int zx_LEN_WO_md_OrganizationName(struct zx_ctx* c, struct zx_md_OrganizationName_s* x )
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
  if (x->lang)
    len += zx_len_xmlns_if_not_seen(c, x->lang->g.ns, &pop_seen);

  len += zx_attr_wo_len(x->lang, sizeof("lang")-1);

#else
  /* root node has no begin tag */
  int len = 0;
#endif
  


  len += zx_len_wo_common(c, &x->gg); 
  zx_pop_seen(pop_seen);
  ENC_LEN_DEBUG(x, "md:OrganizationName", len);
  return len;
}

/* FUNC(zx_ENC_SO_md_OrganizationName) */

/* Render element into string. The XML attributes and elements are
 * processed in schema order. This is what you generally want for
 * rendering new data structure to a string. The wo pointers are not used. */

/* Called by: */
char* zx_ENC_SO_md_OrganizationName(struct zx_ctx* c, struct zx_md_OrganizationName_s* x, char* p )
{
  struct zx_elem_s* se MAYBE_UNUSED;
  struct zx_ns_s* pop_seen = 0;
  ENC_LEN_DEBUG_BASE;
#if 1 /* NORMALMODE */
  /* *** in simple_elem case should output ns prefix from ns node. */
  ZX_OUT_TAG(p, "<md:OrganizationName");
  if (c->inc_ns)
    p = zx_enc_inc_ns(c, p, &pop_seen);
  p = zx_enc_xmlns_if_not_seen(c, p, zx_ns_tab+zx_xmlns_ix_md, &pop_seen);
  if (x->lang)
    p = zx_enc_xmlns_if_not_seen(c, p, zx_ns_tab+zx_xmlns_ix_xml, &pop_seen);

  p = zx_attr_so_enc(p, x->lang, " xml:lang=\"", sizeof(" xml:lang=\"")-1);

  p = zx_enc_unknown_attrs(p, x->gg.any_attr);
#else
  /* root node has no begin tag */
#endif
  

  p = zx_enc_so_unknown_elems_and_content(c, p, &x->gg);
  
#if 1 /* NORMALMODE */
  ZX_OUT_CLOSE_TAG(p, "</md:OrganizationName>");
  zx_pop_seen(pop_seen);
#else
  /* root node has no end tag either */
#endif
  ENC_LEN_DEBUG(x, "md:OrganizationName", p-enc_base);
  return p;
}

/* FUNC(zx_ENC_WO_md_OrganizationName) */

/* Render element into string. The XML attributes and elements are
 * processed in wire order by chasing wo pointers. This is what you want for
 * validating signatures on other people's XML documents. */

/* Called by: */
char* zx_ENC_WO_md_OrganizationName(struct zx_ctx* c, struct zx_md_OrganizationName_s* x, char* p )
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
  if (x->lang)
    zx_add_xmlns_if_not_seen(c, x->lang->g.ns, &pop_seen);

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
  ENC_LEN_DEBUG(x, "md:OrganizationName", p-enc_base);
  return p;
}

/* FUNC(zx_EASY_ENC_SO_md_OrganizationName) */

/* Called by: */
struct zx_str* zx_EASY_ENC_SO_md_OrganizationName(struct zx_ctx* c, struct zx_md_OrganizationName_s* x )
{
  int len;
  char* buf;
  c->ns_tab = ZX_ALLOC(c, sizeof(zx_ns_tab));
  memcpy(c->ns_tab, zx_ns_tab, sizeof(zx_ns_tab));
  len = zx_LEN_SO_md_OrganizationName(c, x );
  buf = ZX_ALLOC(c, len+1);
  return zx_easy_enc_common(c, zx_ENC_SO_md_OrganizationName(c, x, buf ), buf, len);
}

/* FUNC(zx_EASY_ENC_WO_md_OrganizationName) */

/* Called by: */
struct zx_str* zx_EASY_ENC_WO_md_OrganizationName(struct zx_ctx* c, struct zx_md_OrganizationName_s* x )
{
  int len;
  char* buf;
  c->ns_tab = ZX_ALLOC(c, sizeof(zx_ns_tab));
  memcpy(c->ns_tab, zx_ns_tab, sizeof(zx_ns_tab));
  len = zx_LEN_WO_md_OrganizationName(c, x );
  buf = ZX_ALLOC(c, len+1);
  return zx_easy_enc_common(c, zx_ENC_WO_md_OrganizationName(c, x, buf ), buf, len);
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

#define EL_NAME   md_OrganizationURL
#define EL_STRUCT zx_md_OrganizationURL_s
#define EL_NS     md
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

/* FUNC(zx_LEN_SO_md_OrganizationURL) */

/* Compute length of an element (and its subelements). The XML attributes
 * and elements are processed in schema order. */

/* Called by: */
int zx_LEN_SO_md_OrganizationURL(struct zx_ctx* c, struct zx_md_OrganizationURL_s* x )
{
  struct zx_ns_s* pop_seen = 0;
  struct zx_elem_s* se MAYBE_UNUSED;
#if 1 /* NORMALMODE */
  /* *** in simple_elem case should output ns prefix from ns node. */
  int len = sizeof("<md:OrganizationURL")-1 + 1 + sizeof("</md:OrganizationURL>")-1;
  if (c->inc_ns_len)
    len += zx_len_inc_ns(c, &pop_seen);
  len += zx_len_xmlns_if_not_seen(c, zx_ns_tab+zx_xmlns_ix_md, &pop_seen);
  if (x->lang)
    len += zx_len_xmlns_if_not_seen(c, zx_ns_tab+zx_xmlns_ix_xml, &pop_seen);

  len += zx_attr_so_len(x->lang, sizeof("xml:lang")-1);

#else
  /* root node has no begin tag */
  int len = 0;
#endif
  


  len += zx_len_so_common(c, &x->gg);
  zx_pop_seen(pop_seen);
  ENC_LEN_DEBUG(x, "md:OrganizationURL", len);
  return len;
}

/* FUNC(zx_LEN_WO_md_OrganizationURL) */

/* Compute length of an element (and its subelements). The XML attributes
 * and elements are processed in wire order and no assumptions
 * are made about namespace prefixes. */

/* Called by: */
int zx_LEN_WO_md_OrganizationURL(struct zx_ctx* c, struct zx_md_OrganizationURL_s* x )
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
  if (x->lang)
    len += zx_len_xmlns_if_not_seen(c, x->lang->g.ns, &pop_seen);

  len += zx_attr_wo_len(x->lang, sizeof("lang")-1);

#else
  /* root node has no begin tag */
  int len = 0;
#endif
  


  len += zx_len_wo_common(c, &x->gg); 
  zx_pop_seen(pop_seen);
  ENC_LEN_DEBUG(x, "md:OrganizationURL", len);
  return len;
}

/* FUNC(zx_ENC_SO_md_OrganizationURL) */

/* Render element into string. The XML attributes and elements are
 * processed in schema order. This is what you generally want for
 * rendering new data structure to a string. The wo pointers are not used. */

/* Called by: */
char* zx_ENC_SO_md_OrganizationURL(struct zx_ctx* c, struct zx_md_OrganizationURL_s* x, char* p )
{
  struct zx_elem_s* se MAYBE_UNUSED;
  struct zx_ns_s* pop_seen = 0;
  ENC_LEN_DEBUG_BASE;
#if 1 /* NORMALMODE */
  /* *** in simple_elem case should output ns prefix from ns node. */
  ZX_OUT_TAG(p, "<md:OrganizationURL");
  if (c->inc_ns)
    p = zx_enc_inc_ns(c, p, &pop_seen);
  p = zx_enc_xmlns_if_not_seen(c, p, zx_ns_tab+zx_xmlns_ix_md, &pop_seen);
  if (x->lang)
    p = zx_enc_xmlns_if_not_seen(c, p, zx_ns_tab+zx_xmlns_ix_xml, &pop_seen);

  p = zx_attr_so_enc(p, x->lang, " xml:lang=\"", sizeof(" xml:lang=\"")-1);

  p = zx_enc_unknown_attrs(p, x->gg.any_attr);
#else
  /* root node has no begin tag */
#endif
  

  p = zx_enc_so_unknown_elems_and_content(c, p, &x->gg);
  
#if 1 /* NORMALMODE */
  ZX_OUT_CLOSE_TAG(p, "</md:OrganizationURL>");
  zx_pop_seen(pop_seen);
#else
  /* root node has no end tag either */
#endif
  ENC_LEN_DEBUG(x, "md:OrganizationURL", p-enc_base);
  return p;
}

/* FUNC(zx_ENC_WO_md_OrganizationURL) */

/* Render element into string. The XML attributes and elements are
 * processed in wire order by chasing wo pointers. This is what you want for
 * validating signatures on other people's XML documents. */

/* Called by: */
char* zx_ENC_WO_md_OrganizationURL(struct zx_ctx* c, struct zx_md_OrganizationURL_s* x, char* p )
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
  if (x->lang)
    zx_add_xmlns_if_not_seen(c, x->lang->g.ns, &pop_seen);

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
  ENC_LEN_DEBUG(x, "md:OrganizationURL", p-enc_base);
  return p;
}

/* FUNC(zx_EASY_ENC_SO_md_OrganizationURL) */

/* Called by: */
struct zx_str* zx_EASY_ENC_SO_md_OrganizationURL(struct zx_ctx* c, struct zx_md_OrganizationURL_s* x )
{
  int len;
  char* buf;
  c->ns_tab = ZX_ALLOC(c, sizeof(zx_ns_tab));
  memcpy(c->ns_tab, zx_ns_tab, sizeof(zx_ns_tab));
  len = zx_LEN_SO_md_OrganizationURL(c, x );
  buf = ZX_ALLOC(c, len+1);
  return zx_easy_enc_common(c, zx_ENC_SO_md_OrganizationURL(c, x, buf ), buf, len);
}

/* FUNC(zx_EASY_ENC_WO_md_OrganizationURL) */

/* Called by: */
struct zx_str* zx_EASY_ENC_WO_md_OrganizationURL(struct zx_ctx* c, struct zx_md_OrganizationURL_s* x )
{
  int len;
  char* buf;
  c->ns_tab = ZX_ALLOC(c, sizeof(zx_ns_tab));
  memcpy(c->ns_tab, zx_ns_tab, sizeof(zx_ns_tab));
  len = zx_LEN_WO_md_OrganizationURL(c, x );
  buf = ZX_ALLOC(c, len+1);
  return zx_easy_enc_common(c, zx_ENC_WO_md_OrganizationURL(c, x, buf ), buf, len);
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

#define EL_NAME   md_PDPDescriptor
#define EL_STRUCT zx_md_PDPDescriptor_s
#define EL_NS     md
#define EL_TAG    PDPDescriptor

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

/* FUNC(zx_LEN_SO_md_PDPDescriptor) */

/* Compute length of an element (and its subelements). The XML attributes
 * and elements are processed in schema order. */

/* Called by: */
int zx_LEN_SO_md_PDPDescriptor(struct zx_ctx* c, struct zx_md_PDPDescriptor_s* x )
{
  struct zx_ns_s* pop_seen = 0;
  struct zx_elem_s* se MAYBE_UNUSED;
#if 1 /* NORMALMODE */
  /* *** in simple_elem case should output ns prefix from ns node. */
  int len = sizeof("<md:PDPDescriptor")-1 + 1 + sizeof("</md:PDPDescriptor>")-1;
  if (c->inc_ns_len)
    len += zx_len_inc_ns(c, &pop_seen);
  len += zx_len_xmlns_if_not_seen(c, zx_ns_tab+zx_xmlns_ix_md, &pop_seen);

  len += zx_attr_so_len(x->ID, sizeof("ID")-1);
  len += zx_attr_so_len(x->cacheDuration, sizeof("cacheDuration")-1);
  len += zx_attr_so_len(x->errorURL, sizeof("errorURL")-1);
  len += zx_attr_so_len(x->protocolSupportEnumeration, sizeof("protocolSupportEnumeration")-1);
  len += zx_attr_so_len(x->validUntil, sizeof("validUntil")-1);

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
      struct zx_md_Extensions_s* e;
      for (e = x->Extensions; e; e = (struct zx_md_Extensions_s*)e->gg.g.n)
	  len += zx_LEN_SO_md_Extensions(c, e);
  }
  {
      struct zx_md_KeyDescriptor_s* e;
      for (e = x->KeyDescriptor; e; e = (struct zx_md_KeyDescriptor_s*)e->gg.g.n)
	  len += zx_LEN_SO_md_KeyDescriptor(c, e);
  }
  {
      struct zx_md_Organization_s* e;
      for (e = x->Organization; e; e = (struct zx_md_Organization_s*)e->gg.g.n)
	  len += zx_LEN_SO_md_Organization(c, e);
  }
  {
      struct zx_md_ContactPerson_s* e;
      for (e = x->ContactPerson; e; e = (struct zx_md_ContactPerson_s*)e->gg.g.n)
	  len += zx_LEN_SO_md_ContactPerson(c, e);
  }
  {
      struct zx_md_AuthzService_s* e;
      for (e = x->AuthzService; e; e = (struct zx_md_AuthzService_s*)e->gg.g.n)
	  len += zx_LEN_SO_md_AuthzService(c, e);
  }
  {
      struct zx_md_AssertionIDRequestService_s* e;
      for (e = x->AssertionIDRequestService; e; e = (struct zx_md_AssertionIDRequestService_s*)e->gg.g.n)
	  len += zx_LEN_SO_md_AssertionIDRequestService(c, e);
  }
  for (se = x->NameIDFormat; se; se = (struct zx_elem_s*)se->g.n)
    len += zx_LEN_SO_simple_elem(c,se, sizeof("md:NameIDFormat")-1, zx_ns_tab+zx_xmlns_ix_md);


  len += zx_len_so_common(c, &x->gg);
  zx_pop_seen(pop_seen);
  ENC_LEN_DEBUG(x, "md:PDPDescriptor", len);
  return len;
}

/* FUNC(zx_LEN_WO_md_PDPDescriptor) */

/* Compute length of an element (and its subelements). The XML attributes
 * and elements are processed in wire order and no assumptions
 * are made about namespace prefixes. */

/* Called by: */
int zx_LEN_WO_md_PDPDescriptor(struct zx_ctx* c, struct zx_md_PDPDescriptor_s* x )
{
  struct zx_ns_s* pop_seen = 0;
  struct zx_elem_s* se MAYBE_UNUSED;
#if 1 /* NORMALMODE */
  int len = 1 + sizeof("PDPDescriptor")-1 + 1 + 2 + sizeof("PDPDescriptor")-1 + 1;
  
  if (x->gg.g.ns && x->gg.g.ns->prefix_len)
    len += (x->gg.g.ns->prefix_len + 1) * 2;
  if (c->inc_ns_len)
    len += zx_len_inc_ns(c, &pop_seen);
  len += zx_len_xmlns_if_not_seen(c, x->gg.g.ns, &pop_seen);

  len += zx_attr_wo_len(x->ID, sizeof("ID")-1);
  len += zx_attr_wo_len(x->cacheDuration, sizeof("cacheDuration")-1);
  len += zx_attr_wo_len(x->errorURL, sizeof("errorURL")-1);
  len += zx_attr_wo_len(x->protocolSupportEnumeration, sizeof("protocolSupportEnumeration")-1);
  len += zx_attr_wo_len(x->validUntil, sizeof("validUntil")-1);

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
      struct zx_md_Extensions_s* e;
      for (e = x->Extensions; e; e = (struct zx_md_Extensions_s*)e->gg.g.n)
	  len += zx_LEN_WO_md_Extensions(c, e);
  }
  {
      struct zx_md_KeyDescriptor_s* e;
      for (e = x->KeyDescriptor; e; e = (struct zx_md_KeyDescriptor_s*)e->gg.g.n)
	  len += zx_LEN_WO_md_KeyDescriptor(c, e);
  }
  {
      struct zx_md_Organization_s* e;
      for (e = x->Organization; e; e = (struct zx_md_Organization_s*)e->gg.g.n)
	  len += zx_LEN_WO_md_Organization(c, e);
  }
  {
      struct zx_md_ContactPerson_s* e;
      for (e = x->ContactPerson; e; e = (struct zx_md_ContactPerson_s*)e->gg.g.n)
	  len += zx_LEN_WO_md_ContactPerson(c, e);
  }
  {
      struct zx_md_AuthzService_s* e;
      for (e = x->AuthzService; e; e = (struct zx_md_AuthzService_s*)e->gg.g.n)
	  len += zx_LEN_WO_md_AuthzService(c, e);
  }
  {
      struct zx_md_AssertionIDRequestService_s* e;
      for (e = x->AssertionIDRequestService; e; e = (struct zx_md_AssertionIDRequestService_s*)e->gg.g.n)
	  len += zx_LEN_WO_md_AssertionIDRequestService(c, e);
  }
  for (se = x->NameIDFormat; se; se = (struct zx_elem_s*)se->g.n)
    len += zx_LEN_WO_simple_elem(c, se, sizeof("NameIDFormat")-1);


  len += zx_len_wo_common(c, &x->gg); 
  zx_pop_seen(pop_seen);
  ENC_LEN_DEBUG(x, "md:PDPDescriptor", len);
  return len;
}

/* FUNC(zx_ENC_SO_md_PDPDescriptor) */

/* Render element into string. The XML attributes and elements are
 * processed in schema order. This is what you generally want for
 * rendering new data structure to a string. The wo pointers are not used. */

/* Called by: */
char* zx_ENC_SO_md_PDPDescriptor(struct zx_ctx* c, struct zx_md_PDPDescriptor_s* x, char* p )
{
  struct zx_elem_s* se MAYBE_UNUSED;
  struct zx_ns_s* pop_seen = 0;
  ENC_LEN_DEBUG_BASE;
#if 1 /* NORMALMODE */
  /* *** in simple_elem case should output ns prefix from ns node. */
  ZX_OUT_TAG(p, "<md:PDPDescriptor");
  if (c->inc_ns)
    p = zx_enc_inc_ns(c, p, &pop_seen);
  p = zx_enc_xmlns_if_not_seen(c, p, zx_ns_tab+zx_xmlns_ix_md, &pop_seen);

  p = zx_attr_so_enc(p, x->ID, " ID=\"", sizeof(" ID=\"")-1);
  p = zx_attr_so_enc(p, x->cacheDuration, " cacheDuration=\"", sizeof(" cacheDuration=\"")-1);
  p = zx_attr_so_enc(p, x->errorURL, " errorURL=\"", sizeof(" errorURL=\"")-1);
  p = zx_attr_so_enc(p, x->protocolSupportEnumeration, " protocolSupportEnumeration=\"", sizeof(" protocolSupportEnumeration=\"")-1);
  p = zx_attr_so_enc(p, x->validUntil, " validUntil=\"", sizeof(" validUntil=\"")-1);

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
      struct zx_md_Extensions_s* e;
      for (e = x->Extensions; e; e = (struct zx_md_Extensions_s*)e->gg.g.n)
	  p = zx_ENC_SO_md_Extensions(c, e, p);
  }
  {
      struct zx_md_KeyDescriptor_s* e;
      for (e = x->KeyDescriptor; e; e = (struct zx_md_KeyDescriptor_s*)e->gg.g.n)
	  p = zx_ENC_SO_md_KeyDescriptor(c, e, p);
  }
  {
      struct zx_md_Organization_s* e;
      for (e = x->Organization; e; e = (struct zx_md_Organization_s*)e->gg.g.n)
	  p = zx_ENC_SO_md_Organization(c, e, p);
  }
  {
      struct zx_md_ContactPerson_s* e;
      for (e = x->ContactPerson; e; e = (struct zx_md_ContactPerson_s*)e->gg.g.n)
	  p = zx_ENC_SO_md_ContactPerson(c, e, p);
  }
  {
      struct zx_md_AuthzService_s* e;
      for (e = x->AuthzService; e; e = (struct zx_md_AuthzService_s*)e->gg.g.n)
	  p = zx_ENC_SO_md_AuthzService(c, e, p);
  }
  {
      struct zx_md_AssertionIDRequestService_s* e;
      for (e = x->AssertionIDRequestService; e; e = (struct zx_md_AssertionIDRequestService_s*)e->gg.g.n)
	  p = zx_ENC_SO_md_AssertionIDRequestService(c, e, p);
  }
  for (se = x->NameIDFormat; se; se = (struct zx_elem_s*)se->g.n)
    p = zx_ENC_SO_simple_elem(c, se, p, "md:NameIDFormat", sizeof("md:NameIDFormat")-1, zx_ns_tab+zx_xmlns_ix_md);

  p = zx_enc_so_unknown_elems_and_content(c, p, &x->gg);
  
#if 1 /* NORMALMODE */
  ZX_OUT_CLOSE_TAG(p, "</md:PDPDescriptor>");
  zx_pop_seen(pop_seen);
#else
  /* root node has no end tag either */
#endif
  ENC_LEN_DEBUG(x, "md:PDPDescriptor", p-enc_base);
  return p;
}

/* FUNC(zx_ENC_WO_md_PDPDescriptor) */

/* Render element into string. The XML attributes and elements are
 * processed in wire order by chasing wo pointers. This is what you want for
 * validating signatures on other people's XML documents. */

/* Called by: */
char* zx_ENC_WO_md_PDPDescriptor(struct zx_ctx* c, struct zx_md_PDPDescriptor_s* x, char* p )
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
  ZX_OUT_MEM(p, "PDPDescriptor", sizeof("PDPDescriptor")-1);
  qq = p;

  /* *** sort the namespaces */
  if (c->inc_ns)
    zx_add_inc_ns(c, &pop_seen);
  zx_add_xmlns_if_not_seen(c, x->gg.g.ns, &pop_seen);

  p = zx_enc_seen(p, pop_seen); 
  p = zx_attr_wo_enc(p, x->ID, "ID=\"", sizeof("ID=\"")-1);
  p = zx_attr_wo_enc(p, x->cacheDuration, "cacheDuration=\"", sizeof("cacheDuration=\"")-1);
  p = zx_attr_wo_enc(p, x->errorURL, "errorURL=\"", sizeof("errorURL=\"")-1);
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
  ENC_LEN_DEBUG(x, "md:PDPDescriptor", p-enc_base);
  return p;
}

/* FUNC(zx_EASY_ENC_SO_md_PDPDescriptor) */

/* Called by: */
struct zx_str* zx_EASY_ENC_SO_md_PDPDescriptor(struct zx_ctx* c, struct zx_md_PDPDescriptor_s* x )
{
  int len;
  char* buf;
  c->ns_tab = ZX_ALLOC(c, sizeof(zx_ns_tab));
  memcpy(c->ns_tab, zx_ns_tab, sizeof(zx_ns_tab));
  len = zx_LEN_SO_md_PDPDescriptor(c, x );
  buf = ZX_ALLOC(c, len+1);
  return zx_easy_enc_common(c, zx_ENC_SO_md_PDPDescriptor(c, x, buf ), buf, len);
}

/* FUNC(zx_EASY_ENC_WO_md_PDPDescriptor) */

/* Called by: */
struct zx_str* zx_EASY_ENC_WO_md_PDPDescriptor(struct zx_ctx* c, struct zx_md_PDPDescriptor_s* x )
{
  int len;
  char* buf;
  c->ns_tab = ZX_ALLOC(c, sizeof(zx_ns_tab));
  memcpy(c->ns_tab, zx_ns_tab, sizeof(zx_ns_tab));
  len = zx_LEN_WO_md_PDPDescriptor(c, x );
  buf = ZX_ALLOC(c, len+1);
  return zx_easy_enc_common(c, zx_ENC_WO_md_PDPDescriptor(c, x, buf ), buf, len);
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

#define EL_NAME   md_RequestedAttribute
#define EL_STRUCT zx_md_RequestedAttribute_s
#define EL_NS     md
#define EL_TAG    RequestedAttribute

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

/* FUNC(zx_LEN_SO_md_RequestedAttribute) */

/* Compute length of an element (and its subelements). The XML attributes
 * and elements are processed in schema order. */

/* Called by: */
int zx_LEN_SO_md_RequestedAttribute(struct zx_ctx* c, struct zx_md_RequestedAttribute_s* x )
{
  struct zx_ns_s* pop_seen = 0;
  struct zx_elem_s* se MAYBE_UNUSED;
#if 1 /* NORMALMODE */
  /* *** in simple_elem case should output ns prefix from ns node. */
  int len = sizeof("<md:RequestedAttribute")-1 + 1 + sizeof("</md:RequestedAttribute>")-1;
  if (c->inc_ns_len)
    len += zx_len_inc_ns(c, &pop_seen);
  len += zx_len_xmlns_if_not_seen(c, zx_ns_tab+zx_xmlns_ix_md, &pop_seen);

  len += zx_attr_so_len(x->FriendlyName, sizeof("FriendlyName")-1);
  len += zx_attr_so_len(x->Name, sizeof("Name")-1);
  len += zx_attr_so_len(x->NameFormat, sizeof("NameFormat")-1);
  len += zx_attr_so_len(x->isRequired, sizeof("isRequired")-1);

#else
  /* root node has no begin tag */
  int len = 0;
#endif
  
  {
      struct zx_sa_AttributeValue_s* e;
      for (e = x->AttributeValue; e; e = (struct zx_sa_AttributeValue_s*)e->gg.g.n)
	  len += zx_LEN_SO_sa_AttributeValue(c, e);
  }


  len += zx_len_so_common(c, &x->gg);
  zx_pop_seen(pop_seen);
  ENC_LEN_DEBUG(x, "md:RequestedAttribute", len);
  return len;
}

/* FUNC(zx_LEN_WO_md_RequestedAttribute) */

/* Compute length of an element (and its subelements). The XML attributes
 * and elements are processed in wire order and no assumptions
 * are made about namespace prefixes. */

/* Called by: */
int zx_LEN_WO_md_RequestedAttribute(struct zx_ctx* c, struct zx_md_RequestedAttribute_s* x )
{
  struct zx_ns_s* pop_seen = 0;
  struct zx_elem_s* se MAYBE_UNUSED;
#if 1 /* NORMALMODE */
  int len = 1 + sizeof("RequestedAttribute")-1 + 1 + 2 + sizeof("RequestedAttribute")-1 + 1;
  
  if (x->gg.g.ns && x->gg.g.ns->prefix_len)
    len += (x->gg.g.ns->prefix_len + 1) * 2;
  if (c->inc_ns_len)
    len += zx_len_inc_ns(c, &pop_seen);
  len += zx_len_xmlns_if_not_seen(c, x->gg.g.ns, &pop_seen);

  len += zx_attr_wo_len(x->FriendlyName, sizeof("FriendlyName")-1);
  len += zx_attr_wo_len(x->Name, sizeof("Name")-1);
  len += zx_attr_wo_len(x->NameFormat, sizeof("NameFormat")-1);
  len += zx_attr_wo_len(x->isRequired, sizeof("isRequired")-1);

#else
  /* root node has no begin tag */
  int len = 0;
#endif
  
  {
      struct zx_sa_AttributeValue_s* e;
      for (e = x->AttributeValue; e; e = (struct zx_sa_AttributeValue_s*)e->gg.g.n)
	  len += zx_LEN_WO_sa_AttributeValue(c, e);
  }


  len += zx_len_wo_common(c, &x->gg); 
  zx_pop_seen(pop_seen);
  ENC_LEN_DEBUG(x, "md:RequestedAttribute", len);
  return len;
}

/* FUNC(zx_ENC_SO_md_RequestedAttribute) */

/* Render element into string. The XML attributes and elements are
 * processed in schema order. This is what you generally want for
 * rendering new data structure to a string. The wo pointers are not used. */

/* Called by: */
char* zx_ENC_SO_md_RequestedAttribute(struct zx_ctx* c, struct zx_md_RequestedAttribute_s* x, char* p )
{
  struct zx_elem_s* se MAYBE_UNUSED;
  struct zx_ns_s* pop_seen = 0;
  ENC_LEN_DEBUG_BASE;
#if 1 /* NORMALMODE */
  /* *** in simple_elem case should output ns prefix from ns node. */
  ZX_OUT_TAG(p, "<md:RequestedAttribute");
  if (c->inc_ns)
    p = zx_enc_inc_ns(c, p, &pop_seen);
  p = zx_enc_xmlns_if_not_seen(c, p, zx_ns_tab+zx_xmlns_ix_md, &pop_seen);

  p = zx_attr_so_enc(p, x->FriendlyName, " FriendlyName=\"", sizeof(" FriendlyName=\"")-1);
  p = zx_attr_so_enc(p, x->Name, " Name=\"", sizeof(" Name=\"")-1);
  p = zx_attr_so_enc(p, x->NameFormat, " NameFormat=\"", sizeof(" NameFormat=\"")-1);
  p = zx_attr_so_enc(p, x->isRequired, " isRequired=\"", sizeof(" isRequired=\"")-1);

  p = zx_enc_unknown_attrs(p, x->gg.any_attr);
#else
  /* root node has no begin tag */
#endif
  
  {
      struct zx_sa_AttributeValue_s* e;
      for (e = x->AttributeValue; e; e = (struct zx_sa_AttributeValue_s*)e->gg.g.n)
	  p = zx_ENC_SO_sa_AttributeValue(c, e, p);
  }

  p = zx_enc_so_unknown_elems_and_content(c, p, &x->gg);
  
#if 1 /* NORMALMODE */
  ZX_OUT_CLOSE_TAG(p, "</md:RequestedAttribute>");
  zx_pop_seen(pop_seen);
#else
  /* root node has no end tag either */
#endif
  ENC_LEN_DEBUG(x, "md:RequestedAttribute", p-enc_base);
  return p;
}

/* FUNC(zx_ENC_WO_md_RequestedAttribute) */

/* Render element into string. The XML attributes and elements are
 * processed in wire order by chasing wo pointers. This is what you want for
 * validating signatures on other people's XML documents. */

/* Called by: */
char* zx_ENC_WO_md_RequestedAttribute(struct zx_ctx* c, struct zx_md_RequestedAttribute_s* x, char* p )
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
  ZX_OUT_MEM(p, "RequestedAttribute", sizeof("RequestedAttribute")-1);
  qq = p;

  /* *** sort the namespaces */
  if (c->inc_ns)
    zx_add_inc_ns(c, &pop_seen);
  zx_add_xmlns_if_not_seen(c, x->gg.g.ns, &pop_seen);

  p = zx_enc_seen(p, pop_seen); 
  p = zx_attr_wo_enc(p, x->FriendlyName, "FriendlyName=\"", sizeof("FriendlyName=\"")-1);
  p = zx_attr_wo_enc(p, x->Name, "Name=\"", sizeof("Name=\"")-1);
  p = zx_attr_wo_enc(p, x->NameFormat, "NameFormat=\"", sizeof("NameFormat=\"")-1);
  p = zx_attr_wo_enc(p, x->isRequired, "isRequired=\"", sizeof("isRequired=\"")-1);

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
  ENC_LEN_DEBUG(x, "md:RequestedAttribute", p-enc_base);
  return p;
}

/* FUNC(zx_EASY_ENC_SO_md_RequestedAttribute) */

/* Called by: */
struct zx_str* zx_EASY_ENC_SO_md_RequestedAttribute(struct zx_ctx* c, struct zx_md_RequestedAttribute_s* x )
{
  int len;
  char* buf;
  c->ns_tab = ZX_ALLOC(c, sizeof(zx_ns_tab));
  memcpy(c->ns_tab, zx_ns_tab, sizeof(zx_ns_tab));
  len = zx_LEN_SO_md_RequestedAttribute(c, x );
  buf = ZX_ALLOC(c, len+1);
  return zx_easy_enc_common(c, zx_ENC_SO_md_RequestedAttribute(c, x, buf ), buf, len);
}

/* FUNC(zx_EASY_ENC_WO_md_RequestedAttribute) */

/* Called by: */
struct zx_str* zx_EASY_ENC_WO_md_RequestedAttribute(struct zx_ctx* c, struct zx_md_RequestedAttribute_s* x )
{
  int len;
  char* buf;
  c->ns_tab = ZX_ALLOC(c, sizeof(zx_ns_tab));
  memcpy(c->ns_tab, zx_ns_tab, sizeof(zx_ns_tab));
  len = zx_LEN_WO_md_RequestedAttribute(c, x );
  buf = ZX_ALLOC(c, len+1);
  return zx_easy_enc_common(c, zx_ENC_WO_md_RequestedAttribute(c, x, buf ), buf, len);
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

#define EL_NAME   md_RoleDescriptor
#define EL_STRUCT zx_md_RoleDescriptor_s
#define EL_NS     md
#define EL_TAG    RoleDescriptor

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

/* FUNC(zx_LEN_SO_md_RoleDescriptor) */

/* Compute length of an element (and its subelements). The XML attributes
 * and elements are processed in schema order. */

/* Called by: */
int zx_LEN_SO_md_RoleDescriptor(struct zx_ctx* c, struct zx_md_RoleDescriptor_s* x )
{
  struct zx_ns_s* pop_seen = 0;
  struct zx_elem_s* se MAYBE_UNUSED;
#if 1 /* NORMALMODE */
  /* *** in simple_elem case should output ns prefix from ns node. */
  int len = sizeof("<md:RoleDescriptor")-1 + 1 + sizeof("</md:RoleDescriptor>")-1;
  if (c->inc_ns_len)
    len += zx_len_inc_ns(c, &pop_seen);
  len += zx_len_xmlns_if_not_seen(c, zx_ns_tab+zx_xmlns_ix_md, &pop_seen);

  len += zx_attr_so_len(x->ID, sizeof("ID")-1);
  len += zx_attr_so_len(x->cacheDuration, sizeof("cacheDuration")-1);
  len += zx_attr_so_len(x->errorURL, sizeof("errorURL")-1);
  len += zx_attr_so_len(x->protocolSupportEnumeration, sizeof("protocolSupportEnumeration")-1);
  len += zx_attr_so_len(x->validUntil, sizeof("validUntil")-1);

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
      struct zx_md_Extensions_s* e;
      for (e = x->Extensions; e; e = (struct zx_md_Extensions_s*)e->gg.g.n)
	  len += zx_LEN_SO_md_Extensions(c, e);
  }
  {
      struct zx_md_KeyDescriptor_s* e;
      for (e = x->KeyDescriptor; e; e = (struct zx_md_KeyDescriptor_s*)e->gg.g.n)
	  len += zx_LEN_SO_md_KeyDescriptor(c, e);
  }
  {
      struct zx_md_Organization_s* e;
      for (e = x->Organization; e; e = (struct zx_md_Organization_s*)e->gg.g.n)
	  len += zx_LEN_SO_md_Organization(c, e);
  }
  {
      struct zx_md_ContactPerson_s* e;
      for (e = x->ContactPerson; e; e = (struct zx_md_ContactPerson_s*)e->gg.g.n)
	  len += zx_LEN_SO_md_ContactPerson(c, e);
  }


  len += zx_len_so_common(c, &x->gg);
  zx_pop_seen(pop_seen);
  ENC_LEN_DEBUG(x, "md:RoleDescriptor", len);
  return len;
}

/* FUNC(zx_LEN_WO_md_RoleDescriptor) */

/* Compute length of an element (and its subelements). The XML attributes
 * and elements are processed in wire order and no assumptions
 * are made about namespace prefixes. */

/* Called by: */
int zx_LEN_WO_md_RoleDescriptor(struct zx_ctx* c, struct zx_md_RoleDescriptor_s* x )
{
  struct zx_ns_s* pop_seen = 0;
  struct zx_elem_s* se MAYBE_UNUSED;
#if 1 /* NORMALMODE */
  int len = 1 + sizeof("RoleDescriptor")-1 + 1 + 2 + sizeof("RoleDescriptor")-1 + 1;
  
  if (x->gg.g.ns && x->gg.g.ns->prefix_len)
    len += (x->gg.g.ns->prefix_len + 1) * 2;
  if (c->inc_ns_len)
    len += zx_len_inc_ns(c, &pop_seen);
  len += zx_len_xmlns_if_not_seen(c, x->gg.g.ns, &pop_seen);

  len += zx_attr_wo_len(x->ID, sizeof("ID")-1);
  len += zx_attr_wo_len(x->cacheDuration, sizeof("cacheDuration")-1);
  len += zx_attr_wo_len(x->errorURL, sizeof("errorURL")-1);
  len += zx_attr_wo_len(x->protocolSupportEnumeration, sizeof("protocolSupportEnumeration")-1);
  len += zx_attr_wo_len(x->validUntil, sizeof("validUntil")-1);

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
      struct zx_md_Extensions_s* e;
      for (e = x->Extensions; e; e = (struct zx_md_Extensions_s*)e->gg.g.n)
	  len += zx_LEN_WO_md_Extensions(c, e);
  }
  {
      struct zx_md_KeyDescriptor_s* e;
      for (e = x->KeyDescriptor; e; e = (struct zx_md_KeyDescriptor_s*)e->gg.g.n)
	  len += zx_LEN_WO_md_KeyDescriptor(c, e);
  }
  {
      struct zx_md_Organization_s* e;
      for (e = x->Organization; e; e = (struct zx_md_Organization_s*)e->gg.g.n)
	  len += zx_LEN_WO_md_Organization(c, e);
  }
  {
      struct zx_md_ContactPerson_s* e;
      for (e = x->ContactPerson; e; e = (struct zx_md_ContactPerson_s*)e->gg.g.n)
	  len += zx_LEN_WO_md_ContactPerson(c, e);
  }


  len += zx_len_wo_common(c, &x->gg); 
  zx_pop_seen(pop_seen);
  ENC_LEN_DEBUG(x, "md:RoleDescriptor", len);
  return len;
}

/* FUNC(zx_ENC_SO_md_RoleDescriptor) */

/* Render element into string. The XML attributes and elements are
 * processed in schema order. This is what you generally want for
 * rendering new data structure to a string. The wo pointers are not used. */

/* Called by: */
char* zx_ENC_SO_md_RoleDescriptor(struct zx_ctx* c, struct zx_md_RoleDescriptor_s* x, char* p )
{
  struct zx_elem_s* se MAYBE_UNUSED;
  struct zx_ns_s* pop_seen = 0;
  ENC_LEN_DEBUG_BASE;
#if 1 /* NORMALMODE */
  /* *** in simple_elem case should output ns prefix from ns node. */
  ZX_OUT_TAG(p, "<md:RoleDescriptor");
  if (c->inc_ns)
    p = zx_enc_inc_ns(c, p, &pop_seen);
  p = zx_enc_xmlns_if_not_seen(c, p, zx_ns_tab+zx_xmlns_ix_md, &pop_seen);

  p = zx_attr_so_enc(p, x->ID, " ID=\"", sizeof(" ID=\"")-1);
  p = zx_attr_so_enc(p, x->cacheDuration, " cacheDuration=\"", sizeof(" cacheDuration=\"")-1);
  p = zx_attr_so_enc(p, x->errorURL, " errorURL=\"", sizeof(" errorURL=\"")-1);
  p = zx_attr_so_enc(p, x->protocolSupportEnumeration, " protocolSupportEnumeration=\"", sizeof(" protocolSupportEnumeration=\"")-1);
  p = zx_attr_so_enc(p, x->validUntil, " validUntil=\"", sizeof(" validUntil=\"")-1);

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
      struct zx_md_Extensions_s* e;
      for (e = x->Extensions; e; e = (struct zx_md_Extensions_s*)e->gg.g.n)
	  p = zx_ENC_SO_md_Extensions(c, e, p);
  }
  {
      struct zx_md_KeyDescriptor_s* e;
      for (e = x->KeyDescriptor; e; e = (struct zx_md_KeyDescriptor_s*)e->gg.g.n)
	  p = zx_ENC_SO_md_KeyDescriptor(c, e, p);
  }
  {
      struct zx_md_Organization_s* e;
      for (e = x->Organization; e; e = (struct zx_md_Organization_s*)e->gg.g.n)
	  p = zx_ENC_SO_md_Organization(c, e, p);
  }
  {
      struct zx_md_ContactPerson_s* e;
      for (e = x->ContactPerson; e; e = (struct zx_md_ContactPerson_s*)e->gg.g.n)
	  p = zx_ENC_SO_md_ContactPerson(c, e, p);
  }

  p = zx_enc_so_unknown_elems_and_content(c, p, &x->gg);
  
#if 1 /* NORMALMODE */
  ZX_OUT_CLOSE_TAG(p, "</md:RoleDescriptor>");
  zx_pop_seen(pop_seen);
#else
  /* root node has no end tag either */
#endif
  ENC_LEN_DEBUG(x, "md:RoleDescriptor", p-enc_base);
  return p;
}

/* FUNC(zx_ENC_WO_md_RoleDescriptor) */

/* Render element into string. The XML attributes and elements are
 * processed in wire order by chasing wo pointers. This is what you want for
 * validating signatures on other people's XML documents. */

/* Called by: */
char* zx_ENC_WO_md_RoleDescriptor(struct zx_ctx* c, struct zx_md_RoleDescriptor_s* x, char* p )
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
  ZX_OUT_MEM(p, "RoleDescriptor", sizeof("RoleDescriptor")-1);
  qq = p;

  /* *** sort the namespaces */
  if (c->inc_ns)
    zx_add_inc_ns(c, &pop_seen);
  zx_add_xmlns_if_not_seen(c, x->gg.g.ns, &pop_seen);

  p = zx_enc_seen(p, pop_seen); 
  p = zx_attr_wo_enc(p, x->ID, "ID=\"", sizeof("ID=\"")-1);
  p = zx_attr_wo_enc(p, x->cacheDuration, "cacheDuration=\"", sizeof("cacheDuration=\"")-1);
  p = zx_attr_wo_enc(p, x->errorURL, "errorURL=\"", sizeof("errorURL=\"")-1);
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
  ENC_LEN_DEBUG(x, "md:RoleDescriptor", p-enc_base);
  return p;
}

/* FUNC(zx_EASY_ENC_SO_md_RoleDescriptor) */

/* Called by: */
struct zx_str* zx_EASY_ENC_SO_md_RoleDescriptor(struct zx_ctx* c, struct zx_md_RoleDescriptor_s* x )
{
  int len;
  char* buf;
  c->ns_tab = ZX_ALLOC(c, sizeof(zx_ns_tab));
  memcpy(c->ns_tab, zx_ns_tab, sizeof(zx_ns_tab));
  len = zx_LEN_SO_md_RoleDescriptor(c, x );
  buf = ZX_ALLOC(c, len+1);
  return zx_easy_enc_common(c, zx_ENC_SO_md_RoleDescriptor(c, x, buf ), buf, len);
}

/* FUNC(zx_EASY_ENC_WO_md_RoleDescriptor) */

/* Called by: */
struct zx_str* zx_EASY_ENC_WO_md_RoleDescriptor(struct zx_ctx* c, struct zx_md_RoleDescriptor_s* x )
{
  int len;
  char* buf;
  c->ns_tab = ZX_ALLOC(c, sizeof(zx_ns_tab));
  memcpy(c->ns_tab, zx_ns_tab, sizeof(zx_ns_tab));
  len = zx_LEN_WO_md_RoleDescriptor(c, x );
  buf = ZX_ALLOC(c, len+1);
  return zx_easy_enc_common(c, zx_ENC_WO_md_RoleDescriptor(c, x, buf ), buf, len);
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

#define EL_NAME   md_SPSSODescriptor
#define EL_STRUCT zx_md_SPSSODescriptor_s
#define EL_NS     md
#define EL_TAG    SPSSODescriptor

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

/* FUNC(zx_LEN_SO_md_SPSSODescriptor) */

/* Compute length of an element (and its subelements). The XML attributes
 * and elements are processed in schema order. */

/* Called by: */
int zx_LEN_SO_md_SPSSODescriptor(struct zx_ctx* c, struct zx_md_SPSSODescriptor_s* x )
{
  struct zx_ns_s* pop_seen = 0;
  struct zx_elem_s* se MAYBE_UNUSED;
#if 1 /* NORMALMODE */
  /* *** in simple_elem case should output ns prefix from ns node. */
  int len = sizeof("<md:SPSSODescriptor")-1 + 1 + sizeof("</md:SPSSODescriptor>")-1;
  if (c->inc_ns_len)
    len += zx_len_inc_ns(c, &pop_seen);
  len += zx_len_xmlns_if_not_seen(c, zx_ns_tab+zx_xmlns_ix_md, &pop_seen);

  len += zx_attr_so_len(x->AuthnRequestsSigned, sizeof("AuthnRequestsSigned")-1);
  len += zx_attr_so_len(x->ID, sizeof("ID")-1);
  len += zx_attr_so_len(x->WantAssertionsSigned, sizeof("WantAssertionsSigned")-1);
  len += zx_attr_so_len(x->cacheDuration, sizeof("cacheDuration")-1);
  len += zx_attr_so_len(x->errorURL, sizeof("errorURL")-1);
  len += zx_attr_so_len(x->protocolSupportEnumeration, sizeof("protocolSupportEnumeration")-1);
  len += zx_attr_so_len(x->validUntil, sizeof("validUntil")-1);

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
      struct zx_md_Extensions_s* e;
      for (e = x->Extensions; e; e = (struct zx_md_Extensions_s*)e->gg.g.n)
	  len += zx_LEN_SO_md_Extensions(c, e);
  }
  {
      struct zx_md_KeyDescriptor_s* e;
      for (e = x->KeyDescriptor; e; e = (struct zx_md_KeyDescriptor_s*)e->gg.g.n)
	  len += zx_LEN_SO_md_KeyDescriptor(c, e);
  }
  {
      struct zx_md_Organization_s* e;
      for (e = x->Organization; e; e = (struct zx_md_Organization_s*)e->gg.g.n)
	  len += zx_LEN_SO_md_Organization(c, e);
  }
  {
      struct zx_md_ContactPerson_s* e;
      for (e = x->ContactPerson; e; e = (struct zx_md_ContactPerson_s*)e->gg.g.n)
	  len += zx_LEN_SO_md_ContactPerson(c, e);
  }
  {
      struct zx_md_ArtifactResolutionService_s* e;
      for (e = x->ArtifactResolutionService; e; e = (struct zx_md_ArtifactResolutionService_s*)e->gg.g.n)
	  len += zx_LEN_SO_md_ArtifactResolutionService(c, e);
  }
  {
      struct zx_md_SingleLogoutService_s* e;
      for (e = x->SingleLogoutService; e; e = (struct zx_md_SingleLogoutService_s*)e->gg.g.n)
	  len += zx_LEN_SO_md_SingleLogoutService(c, e);
  }
  {
      struct zx_md_ManageNameIDService_s* e;
      for (e = x->ManageNameIDService; e; e = (struct zx_md_ManageNameIDService_s*)e->gg.g.n)
	  len += zx_LEN_SO_md_ManageNameIDService(c, e);
  }
  for (se = x->NameIDFormat; se; se = (struct zx_elem_s*)se->g.n)
    len += zx_LEN_SO_simple_elem(c,se, sizeof("md:NameIDFormat")-1, zx_ns_tab+zx_xmlns_ix_md);
  {
      struct zx_md_AssertionConsumerService_s* e;
      for (e = x->AssertionConsumerService; e; e = (struct zx_md_AssertionConsumerService_s*)e->gg.g.n)
	  len += zx_LEN_SO_md_AssertionConsumerService(c, e);
  }
  {
      struct zx_md_AttributeConsumingService_s* e;
      for (e = x->AttributeConsumingService; e; e = (struct zx_md_AttributeConsumingService_s*)e->gg.g.n)
	  len += zx_LEN_SO_md_AttributeConsumingService(c, e);
  }


  len += zx_len_so_common(c, &x->gg);
  zx_pop_seen(pop_seen);
  ENC_LEN_DEBUG(x, "md:SPSSODescriptor", len);
  return len;
}

/* FUNC(zx_LEN_WO_md_SPSSODescriptor) */

/* Compute length of an element (and its subelements). The XML attributes
 * and elements are processed in wire order and no assumptions
 * are made about namespace prefixes. */

/* Called by: */
int zx_LEN_WO_md_SPSSODescriptor(struct zx_ctx* c, struct zx_md_SPSSODescriptor_s* x )
{
  struct zx_ns_s* pop_seen = 0;
  struct zx_elem_s* se MAYBE_UNUSED;
#if 1 /* NORMALMODE */
  int len = 1 + sizeof("SPSSODescriptor")-1 + 1 + 2 + sizeof("SPSSODescriptor")-1 + 1;
  
  if (x->gg.g.ns && x->gg.g.ns->prefix_len)
    len += (x->gg.g.ns->prefix_len + 1) * 2;
  if (c->inc_ns_len)
    len += zx_len_inc_ns(c, &pop_seen);
  len += zx_len_xmlns_if_not_seen(c, x->gg.g.ns, &pop_seen);

  len += zx_attr_wo_len(x->AuthnRequestsSigned, sizeof("AuthnRequestsSigned")-1);
  len += zx_attr_wo_len(x->ID, sizeof("ID")-1);
  len += zx_attr_wo_len(x->WantAssertionsSigned, sizeof("WantAssertionsSigned")-1);
  len += zx_attr_wo_len(x->cacheDuration, sizeof("cacheDuration")-1);
  len += zx_attr_wo_len(x->errorURL, sizeof("errorURL")-1);
  len += zx_attr_wo_len(x->protocolSupportEnumeration, sizeof("protocolSupportEnumeration")-1);
  len += zx_attr_wo_len(x->validUntil, sizeof("validUntil")-1);

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
      struct zx_md_Extensions_s* e;
      for (e = x->Extensions; e; e = (struct zx_md_Extensions_s*)e->gg.g.n)
	  len += zx_LEN_WO_md_Extensions(c, e);
  }
  {
      struct zx_md_KeyDescriptor_s* e;
      for (e = x->KeyDescriptor; e; e = (struct zx_md_KeyDescriptor_s*)e->gg.g.n)
	  len += zx_LEN_WO_md_KeyDescriptor(c, e);
  }
  {
      struct zx_md_Organization_s* e;
      for (e = x->Organization; e; e = (struct zx_md_Organization_s*)e->gg.g.n)
	  len += zx_LEN_WO_md_Organization(c, e);
  }
  {
      struct zx_md_ContactPerson_s* e;
      for (e = x->ContactPerson; e; e = (struct zx_md_ContactPerson_s*)e->gg.g.n)
	  len += zx_LEN_WO_md_ContactPerson(c, e);
  }
  {
      struct zx_md_ArtifactResolutionService_s* e;
      for (e = x->ArtifactResolutionService; e; e = (struct zx_md_ArtifactResolutionService_s*)e->gg.g.n)
	  len += zx_LEN_WO_md_ArtifactResolutionService(c, e);
  }
  {
      struct zx_md_SingleLogoutService_s* e;
      for (e = x->SingleLogoutService; e; e = (struct zx_md_SingleLogoutService_s*)e->gg.g.n)
	  len += zx_LEN_WO_md_SingleLogoutService(c, e);
  }
  {
      struct zx_md_ManageNameIDService_s* e;
      for (e = x->ManageNameIDService; e; e = (struct zx_md_ManageNameIDService_s*)e->gg.g.n)
	  len += zx_LEN_WO_md_ManageNameIDService(c, e);
  }
  for (se = x->NameIDFormat; se; se = (struct zx_elem_s*)se->g.n)
    len += zx_LEN_WO_simple_elem(c, se, sizeof("NameIDFormat")-1);
  {
      struct zx_md_AssertionConsumerService_s* e;
      for (e = x->AssertionConsumerService; e; e = (struct zx_md_AssertionConsumerService_s*)e->gg.g.n)
	  len += zx_LEN_WO_md_AssertionConsumerService(c, e);
  }
  {
      struct zx_md_AttributeConsumingService_s* e;
      for (e = x->AttributeConsumingService; e; e = (struct zx_md_AttributeConsumingService_s*)e->gg.g.n)
	  len += zx_LEN_WO_md_AttributeConsumingService(c, e);
  }


  len += zx_len_wo_common(c, &x->gg); 
  zx_pop_seen(pop_seen);
  ENC_LEN_DEBUG(x, "md:SPSSODescriptor", len);
  return len;
}

/* FUNC(zx_ENC_SO_md_SPSSODescriptor) */

/* Render element into string. The XML attributes and elements are
 * processed in schema order. This is what you generally want for
 * rendering new data structure to a string. The wo pointers are not used. */

/* Called by: */
char* zx_ENC_SO_md_SPSSODescriptor(struct zx_ctx* c, struct zx_md_SPSSODescriptor_s* x, char* p )
{
  struct zx_elem_s* se MAYBE_UNUSED;
  struct zx_ns_s* pop_seen = 0;
  ENC_LEN_DEBUG_BASE;
#if 1 /* NORMALMODE */
  /* *** in simple_elem case should output ns prefix from ns node. */
  ZX_OUT_TAG(p, "<md:SPSSODescriptor");
  if (c->inc_ns)
    p = zx_enc_inc_ns(c, p, &pop_seen);
  p = zx_enc_xmlns_if_not_seen(c, p, zx_ns_tab+zx_xmlns_ix_md, &pop_seen);

  p = zx_attr_so_enc(p, x->AuthnRequestsSigned, " AuthnRequestsSigned=\"", sizeof(" AuthnRequestsSigned=\"")-1);
  p = zx_attr_so_enc(p, x->ID, " ID=\"", sizeof(" ID=\"")-1);
  p = zx_attr_so_enc(p, x->WantAssertionsSigned, " WantAssertionsSigned=\"", sizeof(" WantAssertionsSigned=\"")-1);
  p = zx_attr_so_enc(p, x->cacheDuration, " cacheDuration=\"", sizeof(" cacheDuration=\"")-1);
  p = zx_attr_so_enc(p, x->errorURL, " errorURL=\"", sizeof(" errorURL=\"")-1);
  p = zx_attr_so_enc(p, x->protocolSupportEnumeration, " protocolSupportEnumeration=\"", sizeof(" protocolSupportEnumeration=\"")-1);
  p = zx_attr_so_enc(p, x->validUntil, " validUntil=\"", sizeof(" validUntil=\"")-1);

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
      struct zx_md_Extensions_s* e;
      for (e = x->Extensions; e; e = (struct zx_md_Extensions_s*)e->gg.g.n)
	  p = zx_ENC_SO_md_Extensions(c, e, p);
  }
  {
      struct zx_md_KeyDescriptor_s* e;
      for (e = x->KeyDescriptor; e; e = (struct zx_md_KeyDescriptor_s*)e->gg.g.n)
	  p = zx_ENC_SO_md_KeyDescriptor(c, e, p);
  }
  {
      struct zx_md_Organization_s* e;
      for (e = x->Organization; e; e = (struct zx_md_Organization_s*)e->gg.g.n)
	  p = zx_ENC_SO_md_Organization(c, e, p);
  }
  {
      struct zx_md_ContactPerson_s* e;
      for (e = x->ContactPerson; e; e = (struct zx_md_ContactPerson_s*)e->gg.g.n)
	  p = zx_ENC_SO_md_ContactPerson(c, e, p);
  }
  {
      struct zx_md_ArtifactResolutionService_s* e;
      for (e = x->ArtifactResolutionService; e; e = (struct zx_md_ArtifactResolutionService_s*)e->gg.g.n)
	  p = zx_ENC_SO_md_ArtifactResolutionService(c, e, p);
  }
  {
      struct zx_md_SingleLogoutService_s* e;
      for (e = x->SingleLogoutService; e; e = (struct zx_md_SingleLogoutService_s*)e->gg.g.n)
	  p = zx_ENC_SO_md_SingleLogoutService(c, e, p);
  }
  {
      struct zx_md_ManageNameIDService_s* e;
      for (e = x->ManageNameIDService; e; e = (struct zx_md_ManageNameIDService_s*)e->gg.g.n)
	  p = zx_ENC_SO_md_ManageNameIDService(c, e, p);
  }
  for (se = x->NameIDFormat; se; se = (struct zx_elem_s*)se->g.n)
    p = zx_ENC_SO_simple_elem(c, se, p, "md:NameIDFormat", sizeof("md:NameIDFormat")-1, zx_ns_tab+zx_xmlns_ix_md);
  {
      struct zx_md_AssertionConsumerService_s* e;
      for (e = x->AssertionConsumerService; e; e = (struct zx_md_AssertionConsumerService_s*)e->gg.g.n)
	  p = zx_ENC_SO_md_AssertionConsumerService(c, e, p);
  }
  {
      struct zx_md_AttributeConsumingService_s* e;
      for (e = x->AttributeConsumingService; e; e = (struct zx_md_AttributeConsumingService_s*)e->gg.g.n)
	  p = zx_ENC_SO_md_AttributeConsumingService(c, e, p);
  }

  p = zx_enc_so_unknown_elems_and_content(c, p, &x->gg);
  
#if 1 /* NORMALMODE */
  ZX_OUT_CLOSE_TAG(p, "</md:SPSSODescriptor>");
  zx_pop_seen(pop_seen);
#else
  /* root node has no end tag either */
#endif
  ENC_LEN_DEBUG(x, "md:SPSSODescriptor", p-enc_base);
  return p;
}

/* FUNC(zx_ENC_WO_md_SPSSODescriptor) */

/* Render element into string. The XML attributes and elements are
 * processed in wire order by chasing wo pointers. This is what you want for
 * validating signatures on other people's XML documents. */

/* Called by: */
char* zx_ENC_WO_md_SPSSODescriptor(struct zx_ctx* c, struct zx_md_SPSSODescriptor_s* x, char* p )
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
  ZX_OUT_MEM(p, "SPSSODescriptor", sizeof("SPSSODescriptor")-1);
  qq = p;

  /* *** sort the namespaces */
  if (c->inc_ns)
    zx_add_inc_ns(c, &pop_seen);
  zx_add_xmlns_if_not_seen(c, x->gg.g.ns, &pop_seen);

  p = zx_enc_seen(p, pop_seen); 
  p = zx_attr_wo_enc(p, x->AuthnRequestsSigned, "AuthnRequestsSigned=\"", sizeof("AuthnRequestsSigned=\"")-1);
  p = zx_attr_wo_enc(p, x->ID, "ID=\"", sizeof("ID=\"")-1);
  p = zx_attr_wo_enc(p, x->WantAssertionsSigned, "WantAssertionsSigned=\"", sizeof("WantAssertionsSigned=\"")-1);
  p = zx_attr_wo_enc(p, x->cacheDuration, "cacheDuration=\"", sizeof("cacheDuration=\"")-1);
  p = zx_attr_wo_enc(p, x->errorURL, "errorURL=\"", sizeof("errorURL=\"")-1);
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
  ENC_LEN_DEBUG(x, "md:SPSSODescriptor", p-enc_base);
  return p;
}

/* FUNC(zx_EASY_ENC_SO_md_SPSSODescriptor) */

/* Called by: */
struct zx_str* zx_EASY_ENC_SO_md_SPSSODescriptor(struct zx_ctx* c, struct zx_md_SPSSODescriptor_s* x )
{
  int len;
  char* buf;
  c->ns_tab = ZX_ALLOC(c, sizeof(zx_ns_tab));
  memcpy(c->ns_tab, zx_ns_tab, sizeof(zx_ns_tab));
  len = zx_LEN_SO_md_SPSSODescriptor(c, x );
  buf = ZX_ALLOC(c, len+1);
  return zx_easy_enc_common(c, zx_ENC_SO_md_SPSSODescriptor(c, x, buf ), buf, len);
}

/* FUNC(zx_EASY_ENC_WO_md_SPSSODescriptor) */

/* Called by: */
struct zx_str* zx_EASY_ENC_WO_md_SPSSODescriptor(struct zx_ctx* c, struct zx_md_SPSSODescriptor_s* x )
{
  int len;
  char* buf;
  c->ns_tab = ZX_ALLOC(c, sizeof(zx_ns_tab));
  memcpy(c->ns_tab, zx_ns_tab, sizeof(zx_ns_tab));
  len = zx_LEN_WO_md_SPSSODescriptor(c, x );
  buf = ZX_ALLOC(c, len+1);
  return zx_easy_enc_common(c, zx_ENC_WO_md_SPSSODescriptor(c, x, buf ), buf, len);
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

#define EL_NAME   md_ServiceDescription
#define EL_STRUCT zx_md_ServiceDescription_s
#define EL_NS     md
#define EL_TAG    ServiceDescription

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

/* FUNC(zx_LEN_SO_md_ServiceDescription) */

/* Compute length of an element (and its subelements). The XML attributes
 * and elements are processed in schema order. */

/* Called by: */
int zx_LEN_SO_md_ServiceDescription(struct zx_ctx* c, struct zx_md_ServiceDescription_s* x )
{
  struct zx_ns_s* pop_seen = 0;
  struct zx_elem_s* se MAYBE_UNUSED;
#if 1 /* NORMALMODE */
  /* *** in simple_elem case should output ns prefix from ns node. */
  int len = sizeof("<md:ServiceDescription")-1 + 1 + sizeof("</md:ServiceDescription>")-1;
  if (c->inc_ns_len)
    len += zx_len_inc_ns(c, &pop_seen);
  len += zx_len_xmlns_if_not_seen(c, zx_ns_tab+zx_xmlns_ix_md, &pop_seen);
  if (x->lang)
    len += zx_len_xmlns_if_not_seen(c, zx_ns_tab+zx_xmlns_ix_xml, &pop_seen);

  len += zx_attr_so_len(x->lang, sizeof("xml:lang")-1);

#else
  /* root node has no begin tag */
  int len = 0;
#endif
  


  len += zx_len_so_common(c, &x->gg);
  zx_pop_seen(pop_seen);
  ENC_LEN_DEBUG(x, "md:ServiceDescription", len);
  return len;
}

/* FUNC(zx_LEN_WO_md_ServiceDescription) */

/* Compute length of an element (and its subelements). The XML attributes
 * and elements are processed in wire order and no assumptions
 * are made about namespace prefixes. */

/* Called by: */
int zx_LEN_WO_md_ServiceDescription(struct zx_ctx* c, struct zx_md_ServiceDescription_s* x )
{
  struct zx_ns_s* pop_seen = 0;
  struct zx_elem_s* se MAYBE_UNUSED;
#if 1 /* NORMALMODE */
  int len = 1 + sizeof("ServiceDescription")-1 + 1 + 2 + sizeof("ServiceDescription")-1 + 1;
  
  if (x->gg.g.ns && x->gg.g.ns->prefix_len)
    len += (x->gg.g.ns->prefix_len + 1) * 2;
  if (c->inc_ns_len)
    len += zx_len_inc_ns(c, &pop_seen);
  len += zx_len_xmlns_if_not_seen(c, x->gg.g.ns, &pop_seen);
  if (x->lang)
    len += zx_len_xmlns_if_not_seen(c, x->lang->g.ns, &pop_seen);

  len += zx_attr_wo_len(x->lang, sizeof("lang")-1);

#else
  /* root node has no begin tag */
  int len = 0;
#endif
  


  len += zx_len_wo_common(c, &x->gg); 
  zx_pop_seen(pop_seen);
  ENC_LEN_DEBUG(x, "md:ServiceDescription", len);
  return len;
}

/* FUNC(zx_ENC_SO_md_ServiceDescription) */

/* Render element into string. The XML attributes and elements are
 * processed in schema order. This is what you generally want for
 * rendering new data structure to a string. The wo pointers are not used. */

/* Called by: */
char* zx_ENC_SO_md_ServiceDescription(struct zx_ctx* c, struct zx_md_ServiceDescription_s* x, char* p )
{
  struct zx_elem_s* se MAYBE_UNUSED;
  struct zx_ns_s* pop_seen = 0;
  ENC_LEN_DEBUG_BASE;
#if 1 /* NORMALMODE */
  /* *** in simple_elem case should output ns prefix from ns node. */
  ZX_OUT_TAG(p, "<md:ServiceDescription");
  if (c->inc_ns)
    p = zx_enc_inc_ns(c, p, &pop_seen);
  p = zx_enc_xmlns_if_not_seen(c, p, zx_ns_tab+zx_xmlns_ix_md, &pop_seen);
  if (x->lang)
    p = zx_enc_xmlns_if_not_seen(c, p, zx_ns_tab+zx_xmlns_ix_xml, &pop_seen);

  p = zx_attr_so_enc(p, x->lang, " xml:lang=\"", sizeof(" xml:lang=\"")-1);

  p = zx_enc_unknown_attrs(p, x->gg.any_attr);
#else
  /* root node has no begin tag */
#endif
  

  p = zx_enc_so_unknown_elems_and_content(c, p, &x->gg);
  
#if 1 /* NORMALMODE */
  ZX_OUT_CLOSE_TAG(p, "</md:ServiceDescription>");
  zx_pop_seen(pop_seen);
#else
  /* root node has no end tag either */
#endif
  ENC_LEN_DEBUG(x, "md:ServiceDescription", p-enc_base);
  return p;
}

/* FUNC(zx_ENC_WO_md_ServiceDescription) */

/* Render element into string. The XML attributes and elements are
 * processed in wire order by chasing wo pointers. This is what you want for
 * validating signatures on other people's XML documents. */

/* Called by: */
char* zx_ENC_WO_md_ServiceDescription(struct zx_ctx* c, struct zx_md_ServiceDescription_s* x, char* p )
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
  ZX_OUT_MEM(p, "ServiceDescription", sizeof("ServiceDescription")-1);
  qq = p;

  /* *** sort the namespaces */
  if (c->inc_ns)
    zx_add_inc_ns(c, &pop_seen);
  zx_add_xmlns_if_not_seen(c, x->gg.g.ns, &pop_seen);
  if (x->lang)
    zx_add_xmlns_if_not_seen(c, x->lang->g.ns, &pop_seen);

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
  ENC_LEN_DEBUG(x, "md:ServiceDescription", p-enc_base);
  return p;
}

/* FUNC(zx_EASY_ENC_SO_md_ServiceDescription) */

/* Called by: */
struct zx_str* zx_EASY_ENC_SO_md_ServiceDescription(struct zx_ctx* c, struct zx_md_ServiceDescription_s* x )
{
  int len;
  char* buf;
  c->ns_tab = ZX_ALLOC(c, sizeof(zx_ns_tab));
  memcpy(c->ns_tab, zx_ns_tab, sizeof(zx_ns_tab));
  len = zx_LEN_SO_md_ServiceDescription(c, x );
  buf = ZX_ALLOC(c, len+1);
  return zx_easy_enc_common(c, zx_ENC_SO_md_ServiceDescription(c, x, buf ), buf, len);
}

/* FUNC(zx_EASY_ENC_WO_md_ServiceDescription) */

/* Called by: */
struct zx_str* zx_EASY_ENC_WO_md_ServiceDescription(struct zx_ctx* c, struct zx_md_ServiceDescription_s* x )
{
  int len;
  char* buf;
  c->ns_tab = ZX_ALLOC(c, sizeof(zx_ns_tab));
  memcpy(c->ns_tab, zx_ns_tab, sizeof(zx_ns_tab));
  len = zx_LEN_WO_md_ServiceDescription(c, x );
  buf = ZX_ALLOC(c, len+1);
  return zx_easy_enc_common(c, zx_ENC_WO_md_ServiceDescription(c, x, buf ), buf, len);
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

#define EL_NAME   md_ServiceName
#define EL_STRUCT zx_md_ServiceName_s
#define EL_NS     md
#define EL_TAG    ServiceName

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

/* FUNC(zx_LEN_SO_md_ServiceName) */

/* Compute length of an element (and its subelements). The XML attributes
 * and elements are processed in schema order. */

/* Called by: */
int zx_LEN_SO_md_ServiceName(struct zx_ctx* c, struct zx_md_ServiceName_s* x )
{
  struct zx_ns_s* pop_seen = 0;
  struct zx_elem_s* se MAYBE_UNUSED;
#if 1 /* NORMALMODE */
  /* *** in simple_elem case should output ns prefix from ns node. */
  int len = sizeof("<md:ServiceName")-1 + 1 + sizeof("</md:ServiceName>")-1;
  if (c->inc_ns_len)
    len += zx_len_inc_ns(c, &pop_seen);
  len += zx_len_xmlns_if_not_seen(c, zx_ns_tab+zx_xmlns_ix_md, &pop_seen);
  if (x->lang)
    len += zx_len_xmlns_if_not_seen(c, zx_ns_tab+zx_xmlns_ix_xml, &pop_seen);

  len += zx_attr_so_len(x->lang, sizeof("xml:lang")-1);

#else
  /* root node has no begin tag */
  int len = 0;
#endif
  


  len += zx_len_so_common(c, &x->gg);
  zx_pop_seen(pop_seen);
  ENC_LEN_DEBUG(x, "md:ServiceName", len);
  return len;
}

/* FUNC(zx_LEN_WO_md_ServiceName) */

/* Compute length of an element (and its subelements). The XML attributes
 * and elements are processed in wire order and no assumptions
 * are made about namespace prefixes. */

/* Called by: */
int zx_LEN_WO_md_ServiceName(struct zx_ctx* c, struct zx_md_ServiceName_s* x )
{
  struct zx_ns_s* pop_seen = 0;
  struct zx_elem_s* se MAYBE_UNUSED;
#if 1 /* NORMALMODE */
  int len = 1 + sizeof("ServiceName")-1 + 1 + 2 + sizeof("ServiceName")-1 + 1;
  
  if (x->gg.g.ns && x->gg.g.ns->prefix_len)
    len += (x->gg.g.ns->prefix_len + 1) * 2;
  if (c->inc_ns_len)
    len += zx_len_inc_ns(c, &pop_seen);
  len += zx_len_xmlns_if_not_seen(c, x->gg.g.ns, &pop_seen);
  if (x->lang)
    len += zx_len_xmlns_if_not_seen(c, x->lang->g.ns, &pop_seen);

  len += zx_attr_wo_len(x->lang, sizeof("lang")-1);

#else
  /* root node has no begin tag */
  int len = 0;
#endif
  


  len += zx_len_wo_common(c, &x->gg); 
  zx_pop_seen(pop_seen);
  ENC_LEN_DEBUG(x, "md:ServiceName", len);
  return len;
}

/* FUNC(zx_ENC_SO_md_ServiceName) */

/* Render element into string. The XML attributes and elements are
 * processed in schema order. This is what you generally want for
 * rendering new data structure to a string. The wo pointers are not used. */

/* Called by: */
char* zx_ENC_SO_md_ServiceName(struct zx_ctx* c, struct zx_md_ServiceName_s* x, char* p )
{
  struct zx_elem_s* se MAYBE_UNUSED;
  struct zx_ns_s* pop_seen = 0;
  ENC_LEN_DEBUG_BASE;
#if 1 /* NORMALMODE */
  /* *** in simple_elem case should output ns prefix from ns node. */
  ZX_OUT_TAG(p, "<md:ServiceName");
  if (c->inc_ns)
    p = zx_enc_inc_ns(c, p, &pop_seen);
  p = zx_enc_xmlns_if_not_seen(c, p, zx_ns_tab+zx_xmlns_ix_md, &pop_seen);
  if (x->lang)
    p = zx_enc_xmlns_if_not_seen(c, p, zx_ns_tab+zx_xmlns_ix_xml, &pop_seen);

  p = zx_attr_so_enc(p, x->lang, " xml:lang=\"", sizeof(" xml:lang=\"")-1);

  p = zx_enc_unknown_attrs(p, x->gg.any_attr);
#else
  /* root node has no begin tag */
#endif
  

  p = zx_enc_so_unknown_elems_and_content(c, p, &x->gg);
  
#if 1 /* NORMALMODE */
  ZX_OUT_CLOSE_TAG(p, "</md:ServiceName>");
  zx_pop_seen(pop_seen);
#else
  /* root node has no end tag either */
#endif
  ENC_LEN_DEBUG(x, "md:ServiceName", p-enc_base);
  return p;
}

/* FUNC(zx_ENC_WO_md_ServiceName) */

/* Render element into string. The XML attributes and elements are
 * processed in wire order by chasing wo pointers. This is what you want for
 * validating signatures on other people's XML documents. */

/* Called by: */
char* zx_ENC_WO_md_ServiceName(struct zx_ctx* c, struct zx_md_ServiceName_s* x, char* p )
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
  ZX_OUT_MEM(p, "ServiceName", sizeof("ServiceName")-1);
  qq = p;

  /* *** sort the namespaces */
  if (c->inc_ns)
    zx_add_inc_ns(c, &pop_seen);
  zx_add_xmlns_if_not_seen(c, x->gg.g.ns, &pop_seen);
  if (x->lang)
    zx_add_xmlns_if_not_seen(c, x->lang->g.ns, &pop_seen);

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
  ENC_LEN_DEBUG(x, "md:ServiceName", p-enc_base);
  return p;
}

/* FUNC(zx_EASY_ENC_SO_md_ServiceName) */

/* Called by: */
struct zx_str* zx_EASY_ENC_SO_md_ServiceName(struct zx_ctx* c, struct zx_md_ServiceName_s* x )
{
  int len;
  char* buf;
  c->ns_tab = ZX_ALLOC(c, sizeof(zx_ns_tab));
  memcpy(c->ns_tab, zx_ns_tab, sizeof(zx_ns_tab));
  len = zx_LEN_SO_md_ServiceName(c, x );
  buf = ZX_ALLOC(c, len+1);
  return zx_easy_enc_common(c, zx_ENC_SO_md_ServiceName(c, x, buf ), buf, len);
}

/* FUNC(zx_EASY_ENC_WO_md_ServiceName) */

/* Called by: */
struct zx_str* zx_EASY_ENC_WO_md_ServiceName(struct zx_ctx* c, struct zx_md_ServiceName_s* x )
{
  int len;
  char* buf;
  c->ns_tab = ZX_ALLOC(c, sizeof(zx_ns_tab));
  memcpy(c->ns_tab, zx_ns_tab, sizeof(zx_ns_tab));
  len = zx_LEN_WO_md_ServiceName(c, x );
  buf = ZX_ALLOC(c, len+1);
  return zx_easy_enc_common(c, zx_ENC_WO_md_ServiceName(c, x, buf ), buf, len);
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

#define EL_NAME   md_SingleLogoutService
#define EL_STRUCT zx_md_SingleLogoutService_s
#define EL_NS     md
#define EL_TAG    SingleLogoutService

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

/* FUNC(zx_LEN_SO_md_SingleLogoutService) */

/* Compute length of an element (and its subelements). The XML attributes
 * and elements are processed in schema order. */

/* Called by: */
int zx_LEN_SO_md_SingleLogoutService(struct zx_ctx* c, struct zx_md_SingleLogoutService_s* x )
{
  struct zx_ns_s* pop_seen = 0;
  struct zx_elem_s* se MAYBE_UNUSED;
#if 1 /* NORMALMODE */
  /* *** in simple_elem case should output ns prefix from ns node. */
  int len = sizeof("<md:SingleLogoutService")-1 + 1 + sizeof("</md:SingleLogoutService>")-1;
  if (c->inc_ns_len)
    len += zx_len_inc_ns(c, &pop_seen);
  len += zx_len_xmlns_if_not_seen(c, zx_ns_tab+zx_xmlns_ix_md, &pop_seen);

  len += zx_attr_so_len(x->Binding, sizeof("Binding")-1);
  len += zx_attr_so_len(x->Location, sizeof("Location")-1);
  len += zx_attr_so_len(x->ResponseLocation, sizeof("ResponseLocation")-1);
  len += zx_attr_so_len(x->index, sizeof("index")-1);
  len += zx_attr_so_len(x->isDefault, sizeof("isDefault")-1);

#else
  /* root node has no begin tag */
  int len = 0;
#endif
  


  len += zx_len_so_common(c, &x->gg);
  zx_pop_seen(pop_seen);
  ENC_LEN_DEBUG(x, "md:SingleLogoutService", len);
  return len;
}

/* FUNC(zx_LEN_WO_md_SingleLogoutService) */

/* Compute length of an element (and its subelements). The XML attributes
 * and elements are processed in wire order and no assumptions
 * are made about namespace prefixes. */

/* Called by: */
int zx_LEN_WO_md_SingleLogoutService(struct zx_ctx* c, struct zx_md_SingleLogoutService_s* x )
{
  struct zx_ns_s* pop_seen = 0;
  struct zx_elem_s* se MAYBE_UNUSED;
#if 1 /* NORMALMODE */
  int len = 1 + sizeof("SingleLogoutService")-1 + 1 + 2 + sizeof("SingleLogoutService")-1 + 1;
  
  if (x->gg.g.ns && x->gg.g.ns->prefix_len)
    len += (x->gg.g.ns->prefix_len + 1) * 2;
  if (c->inc_ns_len)
    len += zx_len_inc_ns(c, &pop_seen);
  len += zx_len_xmlns_if_not_seen(c, x->gg.g.ns, &pop_seen);

  len += zx_attr_wo_len(x->Binding, sizeof("Binding")-1);
  len += zx_attr_wo_len(x->Location, sizeof("Location")-1);
  len += zx_attr_wo_len(x->ResponseLocation, sizeof("ResponseLocation")-1);
  len += zx_attr_wo_len(x->index, sizeof("index")-1);
  len += zx_attr_wo_len(x->isDefault, sizeof("isDefault")-1);

#else
  /* root node has no begin tag */
  int len = 0;
#endif
  


  len += zx_len_wo_common(c, &x->gg); 
  zx_pop_seen(pop_seen);
  ENC_LEN_DEBUG(x, "md:SingleLogoutService", len);
  return len;
}

/* FUNC(zx_ENC_SO_md_SingleLogoutService) */

/* Render element into string. The XML attributes and elements are
 * processed in schema order. This is what you generally want for
 * rendering new data structure to a string. The wo pointers are not used. */

/* Called by: */
char* zx_ENC_SO_md_SingleLogoutService(struct zx_ctx* c, struct zx_md_SingleLogoutService_s* x, char* p )
{
  struct zx_elem_s* se MAYBE_UNUSED;
  struct zx_ns_s* pop_seen = 0;
  ENC_LEN_DEBUG_BASE;
#if 1 /* NORMALMODE */
  /* *** in simple_elem case should output ns prefix from ns node. */
  ZX_OUT_TAG(p, "<md:SingleLogoutService");
  if (c->inc_ns)
    p = zx_enc_inc_ns(c, p, &pop_seen);
  p = zx_enc_xmlns_if_not_seen(c, p, zx_ns_tab+zx_xmlns_ix_md, &pop_seen);

  p = zx_attr_so_enc(p, x->Binding, " Binding=\"", sizeof(" Binding=\"")-1);
  p = zx_attr_so_enc(p, x->Location, " Location=\"", sizeof(" Location=\"")-1);
  p = zx_attr_so_enc(p, x->ResponseLocation, " ResponseLocation=\"", sizeof(" ResponseLocation=\"")-1);
  p = zx_attr_so_enc(p, x->index, " index=\"", sizeof(" index=\"")-1);
  p = zx_attr_so_enc(p, x->isDefault, " isDefault=\"", sizeof(" isDefault=\"")-1);

  p = zx_enc_unknown_attrs(p, x->gg.any_attr);
#else
  /* root node has no begin tag */
#endif
  

  p = zx_enc_so_unknown_elems_and_content(c, p, &x->gg);
  
#if 1 /* NORMALMODE */
  ZX_OUT_CLOSE_TAG(p, "</md:SingleLogoutService>");
  zx_pop_seen(pop_seen);
#else
  /* root node has no end tag either */
#endif
  ENC_LEN_DEBUG(x, "md:SingleLogoutService", p-enc_base);
  return p;
}

/* FUNC(zx_ENC_WO_md_SingleLogoutService) */

/* Render element into string. The XML attributes and elements are
 * processed in wire order by chasing wo pointers. This is what you want for
 * validating signatures on other people's XML documents. */

/* Called by: */
char* zx_ENC_WO_md_SingleLogoutService(struct zx_ctx* c, struct zx_md_SingleLogoutService_s* x, char* p )
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
  ZX_OUT_MEM(p, "SingleLogoutService", sizeof("SingleLogoutService")-1);
  qq = p;

  /* *** sort the namespaces */
  if (c->inc_ns)
    zx_add_inc_ns(c, &pop_seen);
  zx_add_xmlns_if_not_seen(c, x->gg.g.ns, &pop_seen);

  p = zx_enc_seen(p, pop_seen); 
  p = zx_attr_wo_enc(p, x->Binding, "Binding=\"", sizeof("Binding=\"")-1);
  p = zx_attr_wo_enc(p, x->Location, "Location=\"", sizeof("Location=\"")-1);
  p = zx_attr_wo_enc(p, x->ResponseLocation, "ResponseLocation=\"", sizeof("ResponseLocation=\"")-1);
  p = zx_attr_wo_enc(p, x->index, "index=\"", sizeof("index=\"")-1);
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
  ENC_LEN_DEBUG(x, "md:SingleLogoutService", p-enc_base);
  return p;
}

/* FUNC(zx_EASY_ENC_SO_md_SingleLogoutService) */

/* Called by: */
struct zx_str* zx_EASY_ENC_SO_md_SingleLogoutService(struct zx_ctx* c, struct zx_md_SingleLogoutService_s* x )
{
  int len;
  char* buf;
  c->ns_tab = ZX_ALLOC(c, sizeof(zx_ns_tab));
  memcpy(c->ns_tab, zx_ns_tab, sizeof(zx_ns_tab));
  len = zx_LEN_SO_md_SingleLogoutService(c, x );
  buf = ZX_ALLOC(c, len+1);
  return zx_easy_enc_common(c, zx_ENC_SO_md_SingleLogoutService(c, x, buf ), buf, len);
}

/* FUNC(zx_EASY_ENC_WO_md_SingleLogoutService) */

/* Called by: */
struct zx_str* zx_EASY_ENC_WO_md_SingleLogoutService(struct zx_ctx* c, struct zx_md_SingleLogoutService_s* x )
{
  int len;
  char* buf;
  c->ns_tab = ZX_ALLOC(c, sizeof(zx_ns_tab));
  memcpy(c->ns_tab, zx_ns_tab, sizeof(zx_ns_tab));
  len = zx_LEN_WO_md_SingleLogoutService(c, x );
  buf = ZX_ALLOC(c, len+1);
  return zx_easy_enc_common(c, zx_ENC_WO_md_SingleLogoutService(c, x, buf ), buf, len);
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

#define EL_NAME   md_SingleSignOnService
#define EL_STRUCT zx_md_SingleSignOnService_s
#define EL_NS     md
#define EL_TAG    SingleSignOnService

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

/* FUNC(zx_LEN_SO_md_SingleSignOnService) */

/* Compute length of an element (and its subelements). The XML attributes
 * and elements are processed in schema order. */

/* Called by: */
int zx_LEN_SO_md_SingleSignOnService(struct zx_ctx* c, struct zx_md_SingleSignOnService_s* x )
{
  struct zx_ns_s* pop_seen = 0;
  struct zx_elem_s* se MAYBE_UNUSED;
#if 1 /* NORMALMODE */
  /* *** in simple_elem case should output ns prefix from ns node. */
  int len = sizeof("<md:SingleSignOnService")-1 + 1 + sizeof("</md:SingleSignOnService>")-1;
  if (c->inc_ns_len)
    len += zx_len_inc_ns(c, &pop_seen);
  len += zx_len_xmlns_if_not_seen(c, zx_ns_tab+zx_xmlns_ix_md, &pop_seen);

  len += zx_attr_so_len(x->Binding, sizeof("Binding")-1);
  len += zx_attr_so_len(x->Location, sizeof("Location")-1);
  len += zx_attr_so_len(x->ResponseLocation, sizeof("ResponseLocation")-1);
  len += zx_attr_so_len(x->index, sizeof("index")-1);
  len += zx_attr_so_len(x->isDefault, sizeof("isDefault")-1);

#else
  /* root node has no begin tag */
  int len = 0;
#endif
  


  len += zx_len_so_common(c, &x->gg);
  zx_pop_seen(pop_seen);
  ENC_LEN_DEBUG(x, "md:SingleSignOnService", len);
  return len;
}

/* FUNC(zx_LEN_WO_md_SingleSignOnService) */

/* Compute length of an element (and its subelements). The XML attributes
 * and elements are processed in wire order and no assumptions
 * are made about namespace prefixes. */

/* Called by: */
int zx_LEN_WO_md_SingleSignOnService(struct zx_ctx* c, struct zx_md_SingleSignOnService_s* x )
{
  struct zx_ns_s* pop_seen = 0;
  struct zx_elem_s* se MAYBE_UNUSED;
#if 1 /* NORMALMODE */
  int len = 1 + sizeof("SingleSignOnService")-1 + 1 + 2 + sizeof("SingleSignOnService")-1 + 1;
  
  if (x->gg.g.ns && x->gg.g.ns->prefix_len)
    len += (x->gg.g.ns->prefix_len + 1) * 2;
  if (c->inc_ns_len)
    len += zx_len_inc_ns(c, &pop_seen);
  len += zx_len_xmlns_if_not_seen(c, x->gg.g.ns, &pop_seen);

  len += zx_attr_wo_len(x->Binding, sizeof("Binding")-1);
  len += zx_attr_wo_len(x->Location, sizeof("Location")-1);
  len += zx_attr_wo_len(x->ResponseLocation, sizeof("ResponseLocation")-1);
  len += zx_attr_wo_len(x->index, sizeof("index")-1);
  len += zx_attr_wo_len(x->isDefault, sizeof("isDefault")-1);

#else
  /* root node has no begin tag */
  int len = 0;
#endif
  


  len += zx_len_wo_common(c, &x->gg); 
  zx_pop_seen(pop_seen);
  ENC_LEN_DEBUG(x, "md:SingleSignOnService", len);
  return len;
}

/* FUNC(zx_ENC_SO_md_SingleSignOnService) */

/* Render element into string. The XML attributes and elements are
 * processed in schema order. This is what you generally want for
 * rendering new data structure to a string. The wo pointers are not used. */

/* Called by: */
char* zx_ENC_SO_md_SingleSignOnService(struct zx_ctx* c, struct zx_md_SingleSignOnService_s* x, char* p )
{
  struct zx_elem_s* se MAYBE_UNUSED;
  struct zx_ns_s* pop_seen = 0;
  ENC_LEN_DEBUG_BASE;
#if 1 /* NORMALMODE */
  /* *** in simple_elem case should output ns prefix from ns node. */
  ZX_OUT_TAG(p, "<md:SingleSignOnService");
  if (c->inc_ns)
    p = zx_enc_inc_ns(c, p, &pop_seen);
  p = zx_enc_xmlns_if_not_seen(c, p, zx_ns_tab+zx_xmlns_ix_md, &pop_seen);

  p = zx_attr_so_enc(p, x->Binding, " Binding=\"", sizeof(" Binding=\"")-1);
  p = zx_attr_so_enc(p, x->Location, " Location=\"", sizeof(" Location=\"")-1);
  p = zx_attr_so_enc(p, x->ResponseLocation, " ResponseLocation=\"", sizeof(" ResponseLocation=\"")-1);
  p = zx_attr_so_enc(p, x->index, " index=\"", sizeof(" index=\"")-1);
  p = zx_attr_so_enc(p, x->isDefault, " isDefault=\"", sizeof(" isDefault=\"")-1);

  p = zx_enc_unknown_attrs(p, x->gg.any_attr);
#else
  /* root node has no begin tag */
#endif
  

  p = zx_enc_so_unknown_elems_and_content(c, p, &x->gg);
  
#if 1 /* NORMALMODE */
  ZX_OUT_CLOSE_TAG(p, "</md:SingleSignOnService>");
  zx_pop_seen(pop_seen);
#else
  /* root node has no end tag either */
#endif
  ENC_LEN_DEBUG(x, "md:SingleSignOnService", p-enc_base);
  return p;
}

/* FUNC(zx_ENC_WO_md_SingleSignOnService) */

/* Render element into string. The XML attributes and elements are
 * processed in wire order by chasing wo pointers. This is what you want for
 * validating signatures on other people's XML documents. */

/* Called by: */
char* zx_ENC_WO_md_SingleSignOnService(struct zx_ctx* c, struct zx_md_SingleSignOnService_s* x, char* p )
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
  ZX_OUT_MEM(p, "SingleSignOnService", sizeof("SingleSignOnService")-1);
  qq = p;

  /* *** sort the namespaces */
  if (c->inc_ns)
    zx_add_inc_ns(c, &pop_seen);
  zx_add_xmlns_if_not_seen(c, x->gg.g.ns, &pop_seen);

  p = zx_enc_seen(p, pop_seen); 
  p = zx_attr_wo_enc(p, x->Binding, "Binding=\"", sizeof("Binding=\"")-1);
  p = zx_attr_wo_enc(p, x->Location, "Location=\"", sizeof("Location=\"")-1);
  p = zx_attr_wo_enc(p, x->ResponseLocation, "ResponseLocation=\"", sizeof("ResponseLocation=\"")-1);
  p = zx_attr_wo_enc(p, x->index, "index=\"", sizeof("index=\"")-1);
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
  ENC_LEN_DEBUG(x, "md:SingleSignOnService", p-enc_base);
  return p;
}

/* FUNC(zx_EASY_ENC_SO_md_SingleSignOnService) */

/* Called by: */
struct zx_str* zx_EASY_ENC_SO_md_SingleSignOnService(struct zx_ctx* c, struct zx_md_SingleSignOnService_s* x )
{
  int len;
  char* buf;
  c->ns_tab = ZX_ALLOC(c, sizeof(zx_ns_tab));
  memcpy(c->ns_tab, zx_ns_tab, sizeof(zx_ns_tab));
  len = zx_LEN_SO_md_SingleSignOnService(c, x );
  buf = ZX_ALLOC(c, len+1);
  return zx_easy_enc_common(c, zx_ENC_SO_md_SingleSignOnService(c, x, buf ), buf, len);
}

/* FUNC(zx_EASY_ENC_WO_md_SingleSignOnService) */

/* Called by: */
struct zx_str* zx_EASY_ENC_WO_md_SingleSignOnService(struct zx_ctx* c, struct zx_md_SingleSignOnService_s* x )
{
  int len;
  char* buf;
  c->ns_tab = ZX_ALLOC(c, sizeof(zx_ns_tab));
  memcpy(c->ns_tab, zx_ns_tab, sizeof(zx_ns_tab));
  len = zx_LEN_WO_md_SingleSignOnService(c, x );
  buf = ZX_ALLOC(c, len+1);
  return zx_easy_enc_common(c, zx_ENC_WO_md_SingleSignOnService(c, x, buf ), buf, len);
}




/* EOF -- c/zx-md-enc.c */
