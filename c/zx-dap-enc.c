/* c/zx-dap-enc.c - WARNING: This file was automatically generated. DO NOT EDIT!
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
#include "c/zx-dap-data.h"
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

#define EL_NAME   dap_Create
#define EL_STRUCT zx_dap_Create_s
#define EL_NS     dap
#define EL_TAG    Create

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

/* FUNC(zx_LEN_SO_dap_Create) */

/* Compute length of an element (and its subelements). The XML attributes
 * and elements are processed in schema order. */

/* Called by: */
int zx_LEN_SO_dap_Create(struct zx_ctx* c, struct zx_dap_Create_s* x )
{
  struct zx_ns_s* pop_seen = 0;
  struct zx_elem_s* se MAYBE_UNUSED;
#if 1 /* NORMALMODE */
  /* *** in simple_elem case should output ns prefix from ns node. */
  int len = sizeof("<dap:Create")-1 + 1 + sizeof("</dap:Create>")-1;
  if (c->inc_ns_len)
    len += zx_len_inc_ns(c, &pop_seen);
  len += zx_len_xmlns_if_not_seen(c, zx_ns_tab+zx_xmlns_ix_dap, &pop_seen);
  if (x->itemID)
    len += zx_len_xmlns_if_not_seen(c, zx_ns_tab+zx_xmlns_ix_dst, &pop_seen);

  len += zx_attr_so_len(x->itemID, sizeof("dst:itemID")-1);

#else
  /* root node has no begin tag */
  int len = 0;
#endif
  
  {
      struct zx_lu_Extension_s* e;
      for (e = x->Extension; e; e = (struct zx_lu_Extension_s*)e->gg.g.n)
	  len += zx_LEN_SO_lu_Extension(c, e);
  }
  {
      struct zx_dap_Subscription_s* e;
      for (e = x->Subscription; e; e = (struct zx_dap_Subscription_s*)e->gg.g.n)
	  len += zx_LEN_SO_dap_Subscription(c, e);
  }
  {
      struct zx_dap_CreateItem_s* e;
      for (e = x->CreateItem; e; e = (struct zx_dap_CreateItem_s*)e->gg.g.n)
	  len += zx_LEN_SO_dap_CreateItem(c, e);
  }
  {
      struct zx_dap_ResultQuery_s* e;
      for (e = x->ResultQuery; e; e = (struct zx_dap_ResultQuery_s*)e->gg.g.n)
	  len += zx_LEN_SO_dap_ResultQuery(c, e);
  }


  len += zx_len_so_common(c, &x->gg);
  zx_pop_seen(pop_seen);
  ENC_LEN_DEBUG(x, "dap:Create", len);
  return len;
}

/* FUNC(zx_LEN_WO_dap_Create) */

/* Compute length of an element (and its subelements). The XML attributes
 * and elements are processed in wire order and no assumptions
 * are made about namespace prefixes. */

/* Called by: */
int zx_LEN_WO_dap_Create(struct zx_ctx* c, struct zx_dap_Create_s* x )
{
  struct zx_ns_s* pop_seen = 0;
  struct zx_elem_s* se MAYBE_UNUSED;
#if 1 /* NORMALMODE */
  int len = 1 + sizeof("Create")-1 + 1 + 2 + sizeof("Create")-1 + 1;
  
  if (x->gg.g.ns && x->gg.g.ns->prefix_len)
    len += (x->gg.g.ns->prefix_len + 1) * 2;
  if (c->inc_ns_len)
    len += zx_len_inc_ns(c, &pop_seen);
  len += zx_len_xmlns_if_not_seen(c, x->gg.g.ns, &pop_seen);
  if (x->itemID)
    len += zx_len_xmlns_if_not_seen(c, x->itemID->g.ns, &pop_seen);

  len += zx_attr_wo_len(x->itemID, sizeof("itemID")-1);

#else
  /* root node has no begin tag */
  int len = 0;
#endif
  
  {
      struct zx_lu_Extension_s* e;
      for (e = x->Extension; e; e = (struct zx_lu_Extension_s*)e->gg.g.n)
	  len += zx_LEN_WO_lu_Extension(c, e);
  }
  {
      struct zx_dap_Subscription_s* e;
      for (e = x->Subscription; e; e = (struct zx_dap_Subscription_s*)e->gg.g.n)
	  len += zx_LEN_WO_dap_Subscription(c, e);
  }
  {
      struct zx_dap_CreateItem_s* e;
      for (e = x->CreateItem; e; e = (struct zx_dap_CreateItem_s*)e->gg.g.n)
	  len += zx_LEN_WO_dap_CreateItem(c, e);
  }
  {
      struct zx_dap_ResultQuery_s* e;
      for (e = x->ResultQuery; e; e = (struct zx_dap_ResultQuery_s*)e->gg.g.n)
	  len += zx_LEN_WO_dap_ResultQuery(c, e);
  }


  len += zx_len_wo_common(c, &x->gg); 
  zx_pop_seen(pop_seen);
  ENC_LEN_DEBUG(x, "dap:Create", len);
  return len;
}

/* FUNC(zx_ENC_SO_dap_Create) */

/* Render element into string. The XML attributes and elements are
 * processed in schema order. This is what you generally want for
 * rendering new data structure to a string. The wo pointers are not used. */

/* Called by: */
char* zx_ENC_SO_dap_Create(struct zx_ctx* c, struct zx_dap_Create_s* x, char* p )
{
  struct zx_elem_s* se MAYBE_UNUSED;
  ENC_LEN_DEBUG_BASE;
#if 1 /* NORMALMODE */
  struct zx_ns_s* pop_seen = 0;
  /* *** in simple_elem case should output ns prefix from ns node. */
  ZX_OUT_TAG(p, "<dap:Create");
  if (c->inc_ns)
    p = zx_enc_inc_ns(c, p, &pop_seen);
  p = zx_enc_xmlns_if_not_seen(c, p, zx_ns_tab+zx_xmlns_ix_dap, &pop_seen);
  if (x->itemID)
    p = zx_enc_xmlns_if_not_seen(c, p, zx_ns_tab+zx_xmlns_ix_dst, &pop_seen);

  p = zx_attr_so_enc(p, x->itemID, " dst:itemID=\"", sizeof(" dst:itemID=\"")-1);

  p = zx_enc_unknown_attrs(p, x->gg.any_attr);
#else
  /* root node has no begin tag */
#endif
  
  {
      struct zx_lu_Extension_s* e;
      for (e = x->Extension; e; e = (struct zx_lu_Extension_s*)e->gg.g.n)
	  p = zx_ENC_SO_lu_Extension(c, e, p);
  }
  {
      struct zx_dap_Subscription_s* e;
      for (e = x->Subscription; e; e = (struct zx_dap_Subscription_s*)e->gg.g.n)
	  p = zx_ENC_SO_dap_Subscription(c, e, p);
  }
  {
      struct zx_dap_CreateItem_s* e;
      for (e = x->CreateItem; e; e = (struct zx_dap_CreateItem_s*)e->gg.g.n)
	  p = zx_ENC_SO_dap_CreateItem(c, e, p);
  }
  {
      struct zx_dap_ResultQuery_s* e;
      for (e = x->ResultQuery; e; e = (struct zx_dap_ResultQuery_s*)e->gg.g.n)
	  p = zx_ENC_SO_dap_ResultQuery(c, e, p);
  }

  p = zx_enc_so_unknown_elems_and_content(c, p, &x->gg);
  
#if 1 /* NORMALMODE */
  ZX_OUT_CLOSE_TAG(p, "</dap:Create>");
  zx_pop_seen(pop_seen);
#else
  /* root node has no end tag either */
#endif
  ENC_LEN_DEBUG(x, "dap:Create", p-enc_base);
  return p;
}

/* FUNC(zx_ENC_WO_dap_Create) */

/* Render element into string. The XML attributes and elements are
 * processed in wire order by chasing wo pointers. This is what you want for
 * validating signatures on other people's XML documents. */

/* Called by: */
char* zx_ENC_WO_dap_Create(struct zx_ctx* c, struct zx_dap_Create_s* x, char* p )
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
  ZX_OUT_MEM(p, "Create", sizeof("Create")-1);
  qq = p;

  /* *** sort the namespaces */
  if (c->inc_ns)
    zx_add_inc_ns(c, &pop_seen);
  zx_add_xmlns_if_not_seen(c, x->gg.g.ns, &pop_seen);
  if (x->itemID)
    zx_add_xmlns_if_not_seen(c, x->itemID->g.ns, &pop_seen);

  p = zx_enc_seen(p, pop_seen); 
  p = zx_attr_wo_enc(p, x->itemID, "itemID=\"", sizeof("itemID=\"")-1);

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
  ENC_LEN_DEBUG(x, "dap:Create", p-enc_base);
  return p;
}

/* FUNC(zx_EASY_ENC_SO_dap_Create) */

/* Called by: */
struct zx_str* zx_EASY_ENC_SO_dap_Create(struct zx_ctx* c, struct zx_dap_Create_s* x )
{
  int len;
  char* buf;
  c->ns_tab = ZX_ALLOC(c, sizeof(zx_ns_tab));
  memcpy(c->ns_tab, zx_ns_tab, sizeof(zx_ns_tab));
  len = zx_LEN_SO_dap_Create(c, x );
  buf = ZX_ALLOC(c, len+1);
  return zx_easy_enc_common(c, zx_ENC_SO_dap_Create(c, x, buf ), buf, len);
}

/* FUNC(zx_EASY_ENC_WO_dap_Create) */

/* Called by: */
struct zx_str* zx_EASY_ENC_WO_dap_Create(struct zx_ctx* c, struct zx_dap_Create_s* x )
{
  int len;
  char* buf;
  c->ns_tab = ZX_ALLOC(c, sizeof(zx_ns_tab));
  memcpy(c->ns_tab, zx_ns_tab, sizeof(zx_ns_tab));
  len = zx_LEN_WO_dap_Create(c, x );
  buf = ZX_ALLOC(c, len+1);
  return zx_easy_enc_common(c, zx_ENC_WO_dap_Create(c, x, buf ), buf, len);
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

#define EL_NAME   dap_CreateItem
#define EL_STRUCT zx_dap_CreateItem_s
#define EL_NS     dap
#define EL_TAG    CreateItem

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

/* FUNC(zx_LEN_SO_dap_CreateItem) */

/* Compute length of an element (and its subelements). The XML attributes
 * and elements are processed in schema order. */

/* Called by: */
int zx_LEN_SO_dap_CreateItem(struct zx_ctx* c, struct zx_dap_CreateItem_s* x )
{
  struct zx_ns_s* pop_seen = 0;
  struct zx_elem_s* se MAYBE_UNUSED;
#if 1 /* NORMALMODE */
  /* *** in simple_elem case should output ns prefix from ns node. */
  int len = sizeof("<dap:CreateItem")-1 + 1 + sizeof("</dap:CreateItem>")-1;
  if (c->inc_ns_len)
    len += zx_len_inc_ns(c, &pop_seen);
  len += zx_len_xmlns_if_not_seen(c, zx_ns_tab+zx_xmlns_ix_dap, &pop_seen);
  if (x->itemID || x->objectType)
    len += zx_len_xmlns_if_not_seen(c, zx_ns_tab+zx_xmlns_ix_dst, &pop_seen);

  len += zx_attr_so_len(x->id, sizeof("id")-1);
  len += zx_attr_so_len(x->itemID, sizeof("dst:itemID")-1);
  len += zx_attr_so_len(x->objectType, sizeof("dst:objectType")-1);

#else
  /* root node has no begin tag */
  int len = 0;
#endif
  
  {
      struct zx_dap_NewData_s* e;
      for (e = x->NewData; e; e = (struct zx_dap_NewData_s*)e->gg.g.n)
	  len += zx_LEN_SO_dap_NewData(c, e);
  }


  len += zx_len_so_common(c, &x->gg);
  zx_pop_seen(pop_seen);
  ENC_LEN_DEBUG(x, "dap:CreateItem", len);
  return len;
}

/* FUNC(zx_LEN_WO_dap_CreateItem) */

/* Compute length of an element (and its subelements). The XML attributes
 * and elements are processed in wire order and no assumptions
 * are made about namespace prefixes. */

/* Called by: */
int zx_LEN_WO_dap_CreateItem(struct zx_ctx* c, struct zx_dap_CreateItem_s* x )
{
  struct zx_ns_s* pop_seen = 0;
  struct zx_elem_s* se MAYBE_UNUSED;
#if 1 /* NORMALMODE */
  int len = 1 + sizeof("CreateItem")-1 + 1 + 2 + sizeof("CreateItem")-1 + 1;
  
  if (x->gg.g.ns && x->gg.g.ns->prefix_len)
    len += (x->gg.g.ns->prefix_len + 1) * 2;
  if (c->inc_ns_len)
    len += zx_len_inc_ns(c, &pop_seen);
  len += zx_len_xmlns_if_not_seen(c, x->gg.g.ns, &pop_seen);
  if (x->itemID)
    len += zx_len_xmlns_if_not_seen(c, x->itemID->g.ns, &pop_seen);
  if (x->objectType)
    len += zx_len_xmlns_if_not_seen(c, x->objectType->g.ns, &pop_seen);

  len += zx_attr_wo_len(x->id, sizeof("id")-1);
  len += zx_attr_wo_len(x->itemID, sizeof("itemID")-1);
  len += zx_attr_wo_len(x->objectType, sizeof("objectType")-1);

#else
  /* root node has no begin tag */
  int len = 0;
#endif
  
  {
      struct zx_dap_NewData_s* e;
      for (e = x->NewData; e; e = (struct zx_dap_NewData_s*)e->gg.g.n)
	  len += zx_LEN_WO_dap_NewData(c, e);
  }


  len += zx_len_wo_common(c, &x->gg); 
  zx_pop_seen(pop_seen);
  ENC_LEN_DEBUG(x, "dap:CreateItem", len);
  return len;
}

/* FUNC(zx_ENC_SO_dap_CreateItem) */

/* Render element into string. The XML attributes and elements are
 * processed in schema order. This is what you generally want for
 * rendering new data structure to a string. The wo pointers are not used. */

/* Called by: */
char* zx_ENC_SO_dap_CreateItem(struct zx_ctx* c, struct zx_dap_CreateItem_s* x, char* p )
{
  struct zx_elem_s* se MAYBE_UNUSED;
  ENC_LEN_DEBUG_BASE;
#if 1 /* NORMALMODE */
  struct zx_ns_s* pop_seen = 0;
  /* *** in simple_elem case should output ns prefix from ns node. */
  ZX_OUT_TAG(p, "<dap:CreateItem");
  if (c->inc_ns)
    p = zx_enc_inc_ns(c, p, &pop_seen);
  p = zx_enc_xmlns_if_not_seen(c, p, zx_ns_tab+zx_xmlns_ix_dap, &pop_seen);
  if (x->itemID || x->objectType)
    p = zx_enc_xmlns_if_not_seen(c, p, zx_ns_tab+zx_xmlns_ix_dst, &pop_seen);

  p = zx_attr_so_enc(p, x->id, " id=\"", sizeof(" id=\"")-1);
  p = zx_attr_so_enc(p, x->itemID, " dst:itemID=\"", sizeof(" dst:itemID=\"")-1);
  p = zx_attr_so_enc(p, x->objectType, " dst:objectType=\"", sizeof(" dst:objectType=\"")-1);

  p = zx_enc_unknown_attrs(p, x->gg.any_attr);
#else
  /* root node has no begin tag */
#endif
  
  {
      struct zx_dap_NewData_s* e;
      for (e = x->NewData; e; e = (struct zx_dap_NewData_s*)e->gg.g.n)
	  p = zx_ENC_SO_dap_NewData(c, e, p);
  }

  p = zx_enc_so_unknown_elems_and_content(c, p, &x->gg);
  
#if 1 /* NORMALMODE */
  ZX_OUT_CLOSE_TAG(p, "</dap:CreateItem>");
  zx_pop_seen(pop_seen);
#else
  /* root node has no end tag either */
#endif
  ENC_LEN_DEBUG(x, "dap:CreateItem", p-enc_base);
  return p;
}

/* FUNC(zx_ENC_WO_dap_CreateItem) */

/* Render element into string. The XML attributes and elements are
 * processed in wire order by chasing wo pointers. This is what you want for
 * validating signatures on other people's XML documents. */

/* Called by: */
char* zx_ENC_WO_dap_CreateItem(struct zx_ctx* c, struct zx_dap_CreateItem_s* x, char* p )
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
  ZX_OUT_MEM(p, "CreateItem", sizeof("CreateItem")-1);
  qq = p;

  /* *** sort the namespaces */
  if (c->inc_ns)
    zx_add_inc_ns(c, &pop_seen);
  zx_add_xmlns_if_not_seen(c, x->gg.g.ns, &pop_seen);
  if (x->itemID)
    zx_add_xmlns_if_not_seen(c, x->itemID->g.ns, &pop_seen);
  if (x->objectType)
    zx_add_xmlns_if_not_seen(c, x->objectType->g.ns, &pop_seen);

  p = zx_enc_seen(p, pop_seen); 
  p = zx_attr_wo_enc(p, x->id, "id=\"", sizeof("id=\"")-1);
  p = zx_attr_wo_enc(p, x->itemID, "itemID=\"", sizeof("itemID=\"")-1);
  p = zx_attr_wo_enc(p, x->objectType, "objectType=\"", sizeof("objectType=\"")-1);

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
  ENC_LEN_DEBUG(x, "dap:CreateItem", p-enc_base);
  return p;
}

/* FUNC(zx_EASY_ENC_SO_dap_CreateItem) */

/* Called by: */
struct zx_str* zx_EASY_ENC_SO_dap_CreateItem(struct zx_ctx* c, struct zx_dap_CreateItem_s* x )
{
  int len;
  char* buf;
  c->ns_tab = ZX_ALLOC(c, sizeof(zx_ns_tab));
  memcpy(c->ns_tab, zx_ns_tab, sizeof(zx_ns_tab));
  len = zx_LEN_SO_dap_CreateItem(c, x );
  buf = ZX_ALLOC(c, len+1);
  return zx_easy_enc_common(c, zx_ENC_SO_dap_CreateItem(c, x, buf ), buf, len);
}

/* FUNC(zx_EASY_ENC_WO_dap_CreateItem) */

/* Called by: */
struct zx_str* zx_EASY_ENC_WO_dap_CreateItem(struct zx_ctx* c, struct zx_dap_CreateItem_s* x )
{
  int len;
  char* buf;
  c->ns_tab = ZX_ALLOC(c, sizeof(zx_ns_tab));
  memcpy(c->ns_tab, zx_ns_tab, sizeof(zx_ns_tab));
  len = zx_LEN_WO_dap_CreateItem(c, x );
  buf = ZX_ALLOC(c, len+1);
  return zx_easy_enc_common(c, zx_ENC_WO_dap_CreateItem(c, x, buf ), buf, len);
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

#define EL_NAME   dap_CreateResponse
#define EL_STRUCT zx_dap_CreateResponse_s
#define EL_NS     dap
#define EL_TAG    CreateResponse

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

/* FUNC(zx_LEN_SO_dap_CreateResponse) */

/* Compute length of an element (and its subelements). The XML attributes
 * and elements are processed in schema order. */

/* Called by: */
int zx_LEN_SO_dap_CreateResponse(struct zx_ctx* c, struct zx_dap_CreateResponse_s* x )
{
  struct zx_ns_s* pop_seen = 0;
  struct zx_elem_s* se MAYBE_UNUSED;
#if 1 /* NORMALMODE */
  /* *** in simple_elem case should output ns prefix from ns node. */
  int len = sizeof("<dap:CreateResponse")-1 + 1 + sizeof("</dap:CreateResponse>")-1;
  if (c->inc_ns_len)
    len += zx_len_inc_ns(c, &pop_seen);
  len += zx_len_xmlns_if_not_seen(c, zx_ns_tab+zx_xmlns_ix_dap, &pop_seen);
  if (x->itemIDRef)
    len += zx_len_xmlns_if_not_seen(c, zx_ns_tab+zx_xmlns_ix_dst, &pop_seen);

  len += zx_attr_so_len(x->timeStamp, sizeof("timeStamp")-1);
  len += zx_attr_so_len(x->itemIDRef, sizeof("dst:itemIDRef")-1);

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
      struct zx_lu_Extension_s* e;
      for (e = x->Extension; e; e = (struct zx_lu_Extension_s*)e->gg.g.n)
	  len += zx_LEN_SO_lu_Extension(c, e);
  }
  {
      struct zx_dap_ItemData_s* e;
      for (e = x->ItemData; e; e = (struct zx_dap_ItemData_s*)e->gg.g.n)
	  len += zx_LEN_SO_dap_ItemData(c, e);
  }


  len += zx_len_so_common(c, &x->gg);
  zx_pop_seen(pop_seen);
  ENC_LEN_DEBUG(x, "dap:CreateResponse", len);
  return len;
}

/* FUNC(zx_LEN_WO_dap_CreateResponse) */

/* Compute length of an element (and its subelements). The XML attributes
 * and elements are processed in wire order and no assumptions
 * are made about namespace prefixes. */

/* Called by: */
int zx_LEN_WO_dap_CreateResponse(struct zx_ctx* c, struct zx_dap_CreateResponse_s* x )
{
  struct zx_ns_s* pop_seen = 0;
  struct zx_elem_s* se MAYBE_UNUSED;
#if 1 /* NORMALMODE */
  int len = 1 + sizeof("CreateResponse")-1 + 1 + 2 + sizeof("CreateResponse")-1 + 1;
  
  if (x->gg.g.ns && x->gg.g.ns->prefix_len)
    len += (x->gg.g.ns->prefix_len + 1) * 2;
  if (c->inc_ns_len)
    len += zx_len_inc_ns(c, &pop_seen);
  len += zx_len_xmlns_if_not_seen(c, x->gg.g.ns, &pop_seen);
  if (x->itemIDRef)
    len += zx_len_xmlns_if_not_seen(c, x->itemIDRef->g.ns, &pop_seen);

  len += zx_attr_wo_len(x->timeStamp, sizeof("timeStamp")-1);
  len += zx_attr_wo_len(x->itemIDRef, sizeof("itemIDRef")-1);

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
      struct zx_lu_Extension_s* e;
      for (e = x->Extension; e; e = (struct zx_lu_Extension_s*)e->gg.g.n)
	  len += zx_LEN_WO_lu_Extension(c, e);
  }
  {
      struct zx_dap_ItemData_s* e;
      for (e = x->ItemData; e; e = (struct zx_dap_ItemData_s*)e->gg.g.n)
	  len += zx_LEN_WO_dap_ItemData(c, e);
  }


  len += zx_len_wo_common(c, &x->gg); 
  zx_pop_seen(pop_seen);
  ENC_LEN_DEBUG(x, "dap:CreateResponse", len);
  return len;
}

/* FUNC(zx_ENC_SO_dap_CreateResponse) */

/* Render element into string. The XML attributes and elements are
 * processed in schema order. This is what you generally want for
 * rendering new data structure to a string. The wo pointers are not used. */

/* Called by: */
char* zx_ENC_SO_dap_CreateResponse(struct zx_ctx* c, struct zx_dap_CreateResponse_s* x, char* p )
{
  struct zx_elem_s* se MAYBE_UNUSED;
  ENC_LEN_DEBUG_BASE;
#if 1 /* NORMALMODE */
  struct zx_ns_s* pop_seen = 0;
  /* *** in simple_elem case should output ns prefix from ns node. */
  ZX_OUT_TAG(p, "<dap:CreateResponse");
  if (c->inc_ns)
    p = zx_enc_inc_ns(c, p, &pop_seen);
  p = zx_enc_xmlns_if_not_seen(c, p, zx_ns_tab+zx_xmlns_ix_dap, &pop_seen);
  if (x->itemIDRef)
    p = zx_enc_xmlns_if_not_seen(c, p, zx_ns_tab+zx_xmlns_ix_dst, &pop_seen);

  p = zx_attr_so_enc(p, x->timeStamp, " timeStamp=\"", sizeof(" timeStamp=\"")-1);
  p = zx_attr_so_enc(p, x->itemIDRef, " dst:itemIDRef=\"", sizeof(" dst:itemIDRef=\"")-1);

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
      struct zx_lu_Extension_s* e;
      for (e = x->Extension; e; e = (struct zx_lu_Extension_s*)e->gg.g.n)
	  p = zx_ENC_SO_lu_Extension(c, e, p);
  }
  {
      struct zx_dap_ItemData_s* e;
      for (e = x->ItemData; e; e = (struct zx_dap_ItemData_s*)e->gg.g.n)
	  p = zx_ENC_SO_dap_ItemData(c, e, p);
  }

  p = zx_enc_so_unknown_elems_and_content(c, p, &x->gg);
  
#if 1 /* NORMALMODE */
  ZX_OUT_CLOSE_TAG(p, "</dap:CreateResponse>");
  zx_pop_seen(pop_seen);
#else
  /* root node has no end tag either */
#endif
  ENC_LEN_DEBUG(x, "dap:CreateResponse", p-enc_base);
  return p;
}

/* FUNC(zx_ENC_WO_dap_CreateResponse) */

/* Render element into string. The XML attributes and elements are
 * processed in wire order by chasing wo pointers. This is what you want for
 * validating signatures on other people's XML documents. */

/* Called by: */
char* zx_ENC_WO_dap_CreateResponse(struct zx_ctx* c, struct zx_dap_CreateResponse_s* x, char* p )
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
  ZX_OUT_MEM(p, "CreateResponse", sizeof("CreateResponse")-1);
  qq = p;

  /* *** sort the namespaces */
  if (c->inc_ns)
    zx_add_inc_ns(c, &pop_seen);
  zx_add_xmlns_if_not_seen(c, x->gg.g.ns, &pop_seen);
  if (x->itemIDRef)
    zx_add_xmlns_if_not_seen(c, x->itemIDRef->g.ns, &pop_seen);

  p = zx_enc_seen(p, pop_seen); 
  p = zx_attr_wo_enc(p, x->timeStamp, "timeStamp=\"", sizeof("timeStamp=\"")-1);
  p = zx_attr_wo_enc(p, x->itemIDRef, "itemIDRef=\"", sizeof("itemIDRef=\"")-1);

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
  ENC_LEN_DEBUG(x, "dap:CreateResponse", p-enc_base);
  return p;
}

/* FUNC(zx_EASY_ENC_SO_dap_CreateResponse) */

/* Called by: */
struct zx_str* zx_EASY_ENC_SO_dap_CreateResponse(struct zx_ctx* c, struct zx_dap_CreateResponse_s* x )
{
  int len;
  char* buf;
  c->ns_tab = ZX_ALLOC(c, sizeof(zx_ns_tab));
  memcpy(c->ns_tab, zx_ns_tab, sizeof(zx_ns_tab));
  len = zx_LEN_SO_dap_CreateResponse(c, x );
  buf = ZX_ALLOC(c, len+1);
  return zx_easy_enc_common(c, zx_ENC_SO_dap_CreateResponse(c, x, buf ), buf, len);
}

/* FUNC(zx_EASY_ENC_WO_dap_CreateResponse) */

/* Called by: */
struct zx_str* zx_EASY_ENC_WO_dap_CreateResponse(struct zx_ctx* c, struct zx_dap_CreateResponse_s* x )
{
  int len;
  char* buf;
  c->ns_tab = ZX_ALLOC(c, sizeof(zx_ns_tab));
  memcpy(c->ns_tab, zx_ns_tab, sizeof(zx_ns_tab));
  len = zx_LEN_WO_dap_CreateResponse(c, x );
  buf = ZX_ALLOC(c, len+1);
  return zx_easy_enc_common(c, zx_ENC_WO_dap_CreateResponse(c, x, buf ), buf, len);
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

#define EL_NAME   dap_Data
#define EL_STRUCT zx_dap_Data_s
#define EL_NS     dap
#define EL_TAG    Data

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

/* FUNC(zx_LEN_SO_dap_Data) */

/* Compute length of an element (and its subelements). The XML attributes
 * and elements are processed in schema order. */

/* Called by: */
int zx_LEN_SO_dap_Data(struct zx_ctx* c, struct zx_dap_Data_s* x )
{
  struct zx_ns_s* pop_seen = 0;
  struct zx_elem_s* se MAYBE_UNUSED;
#if 1 /* NORMALMODE */
  /* *** in simple_elem case should output ns prefix from ns node. */
  int len = sizeof("<dap:Data")-1 + 1 + sizeof("</dap:Data>")-1;
  if (c->inc_ns_len)
    len += zx_len_inc_ns(c, &pop_seen);
  len += zx_len_xmlns_if_not_seen(c, zx_ns_tab+zx_xmlns_ix_dap, &pop_seen);
  if (x->changeFormat || x->itemIDRef)
    len += zx_len_xmlns_if_not_seen(c, zx_ns_tab+zx_xmlns_ix_dst, &pop_seen);

  len += zx_attr_so_len(x->nextOffset, sizeof("nextOffset")-1);
  len += zx_attr_so_len(x->notSorted, sizeof("notSorted")-1);
  len += zx_attr_so_len(x->remaining, sizeof("remaining")-1);
  len += zx_attr_so_len(x->setID, sizeof("setID")-1);
  len += zx_attr_so_len(x->changeFormat, sizeof("dst:changeFormat")-1);
  len += zx_attr_so_len(x->itemIDRef, sizeof("dst:itemIDRef")-1);

#else
  /* root node has no begin tag */
  int len = 0;
#endif
  
  {
      struct zx_dap_LDIF_s* e;
      for (e = x->LDIF; e; e = (struct zx_dap_LDIF_s*)e->gg.g.n)
	  len += zx_LEN_SO_dap_LDIF(c, e);
  }
  {
      struct zx_dap_Subscription_s* e;
      for (e = x->Subscription; e; e = (struct zx_dap_Subscription_s*)e->gg.g.n)
	  len += zx_LEN_SO_dap_Subscription(c, e);
  }


  len += zx_len_so_common(c, &x->gg);
  zx_pop_seen(pop_seen);
  ENC_LEN_DEBUG(x, "dap:Data", len);
  return len;
}

/* FUNC(zx_LEN_WO_dap_Data) */

/* Compute length of an element (and its subelements). The XML attributes
 * and elements are processed in wire order and no assumptions
 * are made about namespace prefixes. */

/* Called by: */
int zx_LEN_WO_dap_Data(struct zx_ctx* c, struct zx_dap_Data_s* x )
{
  struct zx_ns_s* pop_seen = 0;
  struct zx_elem_s* se MAYBE_UNUSED;
#if 1 /* NORMALMODE */
  int len = 1 + sizeof("Data")-1 + 1 + 2 + sizeof("Data")-1 + 1;
  
  if (x->gg.g.ns && x->gg.g.ns->prefix_len)
    len += (x->gg.g.ns->prefix_len + 1) * 2;
  if (c->inc_ns_len)
    len += zx_len_inc_ns(c, &pop_seen);
  len += zx_len_xmlns_if_not_seen(c, x->gg.g.ns, &pop_seen);
  if (x->changeFormat)
    len += zx_len_xmlns_if_not_seen(c, x->changeFormat->g.ns, &pop_seen);
  if (x->itemIDRef)
    len += zx_len_xmlns_if_not_seen(c, x->itemIDRef->g.ns, &pop_seen);

  len += zx_attr_wo_len(x->nextOffset, sizeof("nextOffset")-1);
  len += zx_attr_wo_len(x->notSorted, sizeof("notSorted")-1);
  len += zx_attr_wo_len(x->remaining, sizeof("remaining")-1);
  len += zx_attr_wo_len(x->setID, sizeof("setID")-1);
  len += zx_attr_wo_len(x->changeFormat, sizeof("changeFormat")-1);
  len += zx_attr_wo_len(x->itemIDRef, sizeof("itemIDRef")-1);

#else
  /* root node has no begin tag */
  int len = 0;
#endif
  
  {
      struct zx_dap_LDIF_s* e;
      for (e = x->LDIF; e; e = (struct zx_dap_LDIF_s*)e->gg.g.n)
	  len += zx_LEN_WO_dap_LDIF(c, e);
  }
  {
      struct zx_dap_Subscription_s* e;
      for (e = x->Subscription; e; e = (struct zx_dap_Subscription_s*)e->gg.g.n)
	  len += zx_LEN_WO_dap_Subscription(c, e);
  }


  len += zx_len_wo_common(c, &x->gg); 
  zx_pop_seen(pop_seen);
  ENC_LEN_DEBUG(x, "dap:Data", len);
  return len;
}

/* FUNC(zx_ENC_SO_dap_Data) */

/* Render element into string. The XML attributes and elements are
 * processed in schema order. This is what you generally want for
 * rendering new data structure to a string. The wo pointers are not used. */

/* Called by: */
char* zx_ENC_SO_dap_Data(struct zx_ctx* c, struct zx_dap_Data_s* x, char* p )
{
  struct zx_elem_s* se MAYBE_UNUSED;
  ENC_LEN_DEBUG_BASE;
#if 1 /* NORMALMODE */
  struct zx_ns_s* pop_seen = 0;
  /* *** in simple_elem case should output ns prefix from ns node. */
  ZX_OUT_TAG(p, "<dap:Data");
  if (c->inc_ns)
    p = zx_enc_inc_ns(c, p, &pop_seen);
  p = zx_enc_xmlns_if_not_seen(c, p, zx_ns_tab+zx_xmlns_ix_dap, &pop_seen);
  if (x->changeFormat || x->itemIDRef)
    p = zx_enc_xmlns_if_not_seen(c, p, zx_ns_tab+zx_xmlns_ix_dst, &pop_seen);

  p = zx_attr_so_enc(p, x->nextOffset, " nextOffset=\"", sizeof(" nextOffset=\"")-1);
  p = zx_attr_so_enc(p, x->notSorted, " notSorted=\"", sizeof(" notSorted=\"")-1);
  p = zx_attr_so_enc(p, x->remaining, " remaining=\"", sizeof(" remaining=\"")-1);
  p = zx_attr_so_enc(p, x->setID, " setID=\"", sizeof(" setID=\"")-1);
  p = zx_attr_so_enc(p, x->changeFormat, " dst:changeFormat=\"", sizeof(" dst:changeFormat=\"")-1);
  p = zx_attr_so_enc(p, x->itemIDRef, " dst:itemIDRef=\"", sizeof(" dst:itemIDRef=\"")-1);

  p = zx_enc_unknown_attrs(p, x->gg.any_attr);
#else
  /* root node has no begin tag */
#endif
  
  {
      struct zx_dap_LDIF_s* e;
      for (e = x->LDIF; e; e = (struct zx_dap_LDIF_s*)e->gg.g.n)
	  p = zx_ENC_SO_dap_LDIF(c, e, p);
  }
  {
      struct zx_dap_Subscription_s* e;
      for (e = x->Subscription; e; e = (struct zx_dap_Subscription_s*)e->gg.g.n)
	  p = zx_ENC_SO_dap_Subscription(c, e, p);
  }

  p = zx_enc_so_unknown_elems_and_content(c, p, &x->gg);
  
#if 1 /* NORMALMODE */
  ZX_OUT_CLOSE_TAG(p, "</dap:Data>");
  zx_pop_seen(pop_seen);
#else
  /* root node has no end tag either */
#endif
  ENC_LEN_DEBUG(x, "dap:Data", p-enc_base);
  return p;
}

/* FUNC(zx_ENC_WO_dap_Data) */

/* Render element into string. The XML attributes and elements are
 * processed in wire order by chasing wo pointers. This is what you want for
 * validating signatures on other people's XML documents. */

/* Called by: */
char* zx_ENC_WO_dap_Data(struct zx_ctx* c, struct zx_dap_Data_s* x, char* p )
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
  ZX_OUT_MEM(p, "Data", sizeof("Data")-1);
  qq = p;

  /* *** sort the namespaces */
  if (c->inc_ns)
    zx_add_inc_ns(c, &pop_seen);
  zx_add_xmlns_if_not_seen(c, x->gg.g.ns, &pop_seen);
  if (x->changeFormat)
    zx_add_xmlns_if_not_seen(c, x->changeFormat->g.ns, &pop_seen);
  if (x->itemIDRef)
    zx_add_xmlns_if_not_seen(c, x->itemIDRef->g.ns, &pop_seen);

  p = zx_enc_seen(p, pop_seen); 
  p = zx_attr_wo_enc(p, x->nextOffset, "nextOffset=\"", sizeof("nextOffset=\"")-1);
  p = zx_attr_wo_enc(p, x->notSorted, "notSorted=\"", sizeof("notSorted=\"")-1);
  p = zx_attr_wo_enc(p, x->remaining, "remaining=\"", sizeof("remaining=\"")-1);
  p = zx_attr_wo_enc(p, x->setID, "setID=\"", sizeof("setID=\"")-1);
  p = zx_attr_wo_enc(p, x->changeFormat, "changeFormat=\"", sizeof("changeFormat=\"")-1);
  p = zx_attr_wo_enc(p, x->itemIDRef, "itemIDRef=\"", sizeof("itemIDRef=\"")-1);

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
  ENC_LEN_DEBUG(x, "dap:Data", p-enc_base);
  return p;
}

/* FUNC(zx_EASY_ENC_SO_dap_Data) */

/* Called by: */
struct zx_str* zx_EASY_ENC_SO_dap_Data(struct zx_ctx* c, struct zx_dap_Data_s* x )
{
  int len;
  char* buf;
  c->ns_tab = ZX_ALLOC(c, sizeof(zx_ns_tab));
  memcpy(c->ns_tab, zx_ns_tab, sizeof(zx_ns_tab));
  len = zx_LEN_SO_dap_Data(c, x );
  buf = ZX_ALLOC(c, len+1);
  return zx_easy_enc_common(c, zx_ENC_SO_dap_Data(c, x, buf ), buf, len);
}

/* FUNC(zx_EASY_ENC_WO_dap_Data) */

/* Called by: */
struct zx_str* zx_EASY_ENC_WO_dap_Data(struct zx_ctx* c, struct zx_dap_Data_s* x )
{
  int len;
  char* buf;
  c->ns_tab = ZX_ALLOC(c, sizeof(zx_ns_tab));
  memcpy(c->ns_tab, zx_ns_tab, sizeof(zx_ns_tab));
  len = zx_LEN_WO_dap_Data(c, x );
  buf = ZX_ALLOC(c, len+1);
  return zx_easy_enc_common(c, zx_ENC_WO_dap_Data(c, x, buf ), buf, len);
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

#define EL_NAME   dap_Delete
#define EL_STRUCT zx_dap_Delete_s
#define EL_NS     dap
#define EL_TAG    Delete

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

/* FUNC(zx_LEN_SO_dap_Delete) */

/* Compute length of an element (and its subelements). The XML attributes
 * and elements are processed in schema order. */

/* Called by: */
int zx_LEN_SO_dap_Delete(struct zx_ctx* c, struct zx_dap_Delete_s* x )
{
  struct zx_ns_s* pop_seen = 0;
  struct zx_elem_s* se MAYBE_UNUSED;
#if 1 /* NORMALMODE */
  /* *** in simple_elem case should output ns prefix from ns node. */
  int len = sizeof("<dap:Delete")-1 + 1 + sizeof("</dap:Delete>")-1;
  if (c->inc_ns_len)
    len += zx_len_inc_ns(c, &pop_seen);
  len += zx_len_xmlns_if_not_seen(c, zx_ns_tab+zx_xmlns_ix_dap, &pop_seen);
  if (x->itemID)
    len += zx_len_xmlns_if_not_seen(c, zx_ns_tab+zx_xmlns_ix_dst, &pop_seen);

  len += zx_attr_so_len(x->itemID, sizeof("dst:itemID")-1);

#else
  /* root node has no begin tag */
  int len = 0;
#endif
  
  {
      struct zx_lu_Extension_s* e;
      for (e = x->Extension; e; e = (struct zx_lu_Extension_s*)e->gg.g.n)
	  len += zx_LEN_SO_lu_Extension(c, e);
  }
  {
      struct zx_dap_DeleteItem_s* e;
      for (e = x->DeleteItem; e; e = (struct zx_dap_DeleteItem_s*)e->gg.g.n)
	  len += zx_LEN_SO_dap_DeleteItem(c, e);
  }


  len += zx_len_so_common(c, &x->gg);
  zx_pop_seen(pop_seen);
  ENC_LEN_DEBUG(x, "dap:Delete", len);
  return len;
}

/* FUNC(zx_LEN_WO_dap_Delete) */

/* Compute length of an element (and its subelements). The XML attributes
 * and elements are processed in wire order and no assumptions
 * are made about namespace prefixes. */

/* Called by: */
int zx_LEN_WO_dap_Delete(struct zx_ctx* c, struct zx_dap_Delete_s* x )
{
  struct zx_ns_s* pop_seen = 0;
  struct zx_elem_s* se MAYBE_UNUSED;
#if 1 /* NORMALMODE */
  int len = 1 + sizeof("Delete")-1 + 1 + 2 + sizeof("Delete")-1 + 1;
  
  if (x->gg.g.ns && x->gg.g.ns->prefix_len)
    len += (x->gg.g.ns->prefix_len + 1) * 2;
  if (c->inc_ns_len)
    len += zx_len_inc_ns(c, &pop_seen);
  len += zx_len_xmlns_if_not_seen(c, x->gg.g.ns, &pop_seen);
  if (x->itemID)
    len += zx_len_xmlns_if_not_seen(c, x->itemID->g.ns, &pop_seen);

  len += zx_attr_wo_len(x->itemID, sizeof("itemID")-1);

#else
  /* root node has no begin tag */
  int len = 0;
#endif
  
  {
      struct zx_lu_Extension_s* e;
      for (e = x->Extension; e; e = (struct zx_lu_Extension_s*)e->gg.g.n)
	  len += zx_LEN_WO_lu_Extension(c, e);
  }
  {
      struct zx_dap_DeleteItem_s* e;
      for (e = x->DeleteItem; e; e = (struct zx_dap_DeleteItem_s*)e->gg.g.n)
	  len += zx_LEN_WO_dap_DeleteItem(c, e);
  }


  len += zx_len_wo_common(c, &x->gg); 
  zx_pop_seen(pop_seen);
  ENC_LEN_DEBUG(x, "dap:Delete", len);
  return len;
}

/* FUNC(zx_ENC_SO_dap_Delete) */

/* Render element into string. The XML attributes and elements are
 * processed in schema order. This is what you generally want for
 * rendering new data structure to a string. The wo pointers are not used. */

/* Called by: */
char* zx_ENC_SO_dap_Delete(struct zx_ctx* c, struct zx_dap_Delete_s* x, char* p )
{
  struct zx_elem_s* se MAYBE_UNUSED;
  ENC_LEN_DEBUG_BASE;
#if 1 /* NORMALMODE */
  struct zx_ns_s* pop_seen = 0;
  /* *** in simple_elem case should output ns prefix from ns node. */
  ZX_OUT_TAG(p, "<dap:Delete");
  if (c->inc_ns)
    p = zx_enc_inc_ns(c, p, &pop_seen);
  p = zx_enc_xmlns_if_not_seen(c, p, zx_ns_tab+zx_xmlns_ix_dap, &pop_seen);
  if (x->itemID)
    p = zx_enc_xmlns_if_not_seen(c, p, zx_ns_tab+zx_xmlns_ix_dst, &pop_seen);

  p = zx_attr_so_enc(p, x->itemID, " dst:itemID=\"", sizeof(" dst:itemID=\"")-1);

  p = zx_enc_unknown_attrs(p, x->gg.any_attr);
#else
  /* root node has no begin tag */
#endif
  
  {
      struct zx_lu_Extension_s* e;
      for (e = x->Extension; e; e = (struct zx_lu_Extension_s*)e->gg.g.n)
	  p = zx_ENC_SO_lu_Extension(c, e, p);
  }
  {
      struct zx_dap_DeleteItem_s* e;
      for (e = x->DeleteItem; e; e = (struct zx_dap_DeleteItem_s*)e->gg.g.n)
	  p = zx_ENC_SO_dap_DeleteItem(c, e, p);
  }

  p = zx_enc_so_unknown_elems_and_content(c, p, &x->gg);
  
#if 1 /* NORMALMODE */
  ZX_OUT_CLOSE_TAG(p, "</dap:Delete>");
  zx_pop_seen(pop_seen);
#else
  /* root node has no end tag either */
#endif
  ENC_LEN_DEBUG(x, "dap:Delete", p-enc_base);
  return p;
}

/* FUNC(zx_ENC_WO_dap_Delete) */

/* Render element into string. The XML attributes and elements are
 * processed in wire order by chasing wo pointers. This is what you want for
 * validating signatures on other people's XML documents. */

/* Called by: */
char* zx_ENC_WO_dap_Delete(struct zx_ctx* c, struct zx_dap_Delete_s* x, char* p )
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
  ZX_OUT_MEM(p, "Delete", sizeof("Delete")-1);
  qq = p;

  /* *** sort the namespaces */
  if (c->inc_ns)
    zx_add_inc_ns(c, &pop_seen);
  zx_add_xmlns_if_not_seen(c, x->gg.g.ns, &pop_seen);
  if (x->itemID)
    zx_add_xmlns_if_not_seen(c, x->itemID->g.ns, &pop_seen);

  p = zx_enc_seen(p, pop_seen); 
  p = zx_attr_wo_enc(p, x->itemID, "itemID=\"", sizeof("itemID=\"")-1);

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
  ENC_LEN_DEBUG(x, "dap:Delete", p-enc_base);
  return p;
}

/* FUNC(zx_EASY_ENC_SO_dap_Delete) */

/* Called by: */
struct zx_str* zx_EASY_ENC_SO_dap_Delete(struct zx_ctx* c, struct zx_dap_Delete_s* x )
{
  int len;
  char* buf;
  c->ns_tab = ZX_ALLOC(c, sizeof(zx_ns_tab));
  memcpy(c->ns_tab, zx_ns_tab, sizeof(zx_ns_tab));
  len = zx_LEN_SO_dap_Delete(c, x );
  buf = ZX_ALLOC(c, len+1);
  return zx_easy_enc_common(c, zx_ENC_SO_dap_Delete(c, x, buf ), buf, len);
}

/* FUNC(zx_EASY_ENC_WO_dap_Delete) */

/* Called by: */
struct zx_str* zx_EASY_ENC_WO_dap_Delete(struct zx_ctx* c, struct zx_dap_Delete_s* x )
{
  int len;
  char* buf;
  c->ns_tab = ZX_ALLOC(c, sizeof(zx_ns_tab));
  memcpy(c->ns_tab, zx_ns_tab, sizeof(zx_ns_tab));
  len = zx_LEN_WO_dap_Delete(c, x );
  buf = ZX_ALLOC(c, len+1);
  return zx_easy_enc_common(c, zx_ENC_WO_dap_Delete(c, x, buf ), buf, len);
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

#define EL_NAME   dap_DeleteItem
#define EL_STRUCT zx_dap_DeleteItem_s
#define EL_NS     dap
#define EL_TAG    DeleteItem

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

/* FUNC(zx_LEN_SO_dap_DeleteItem) */

/* Compute length of an element (and its subelements). The XML attributes
 * and elements are processed in schema order. */

/* Called by: */
int zx_LEN_SO_dap_DeleteItem(struct zx_ctx* c, struct zx_dap_DeleteItem_s* x )
{
  struct zx_ns_s* pop_seen = 0;
  struct zx_elem_s* se MAYBE_UNUSED;
#if 1 /* NORMALMODE */
  /* *** in simple_elem case should output ns prefix from ns node. */
  int len = sizeof("<dap:DeleteItem")-1 + 1 + sizeof("</dap:DeleteItem>")-1;
  if (c->inc_ns_len)
    len += zx_len_inc_ns(c, &pop_seen);
  len += zx_len_xmlns_if_not_seen(c, zx_ns_tab+zx_xmlns_ix_dap, &pop_seen);
  if (x->itemID || x->objectType || x->predefined)
    len += zx_len_xmlns_if_not_seen(c, zx_ns_tab+zx_xmlns_ix_dst, &pop_seen);

  len += zx_attr_so_len(x->id, sizeof("id")-1);
  len += zx_attr_so_len(x->notChangedSince, sizeof("notChangedSince")-1);
  len += zx_attr_so_len(x->itemID, sizeof("dst:itemID")-1);
  len += zx_attr_so_len(x->objectType, sizeof("dst:objectType")-1);
  len += zx_attr_so_len(x->predefined, sizeof("dst:predefined")-1);

#else
  /* root node has no begin tag */
  int len = 0;
#endif
  
  {
      struct zx_dap_Select_s* e;
      for (e = x->Select; e; e = (struct zx_dap_Select_s*)e->gg.g.n)
	  len += zx_LEN_SO_dap_Select(c, e);
  }


  len += zx_len_so_common(c, &x->gg);
  zx_pop_seen(pop_seen);
  ENC_LEN_DEBUG(x, "dap:DeleteItem", len);
  return len;
}

/* FUNC(zx_LEN_WO_dap_DeleteItem) */

/* Compute length of an element (and its subelements). The XML attributes
 * and elements are processed in wire order and no assumptions
 * are made about namespace prefixes. */

/* Called by: */
int zx_LEN_WO_dap_DeleteItem(struct zx_ctx* c, struct zx_dap_DeleteItem_s* x )
{
  struct zx_ns_s* pop_seen = 0;
  struct zx_elem_s* se MAYBE_UNUSED;
#if 1 /* NORMALMODE */
  int len = 1 + sizeof("DeleteItem")-1 + 1 + 2 + sizeof("DeleteItem")-1 + 1;
  
  if (x->gg.g.ns && x->gg.g.ns->prefix_len)
    len += (x->gg.g.ns->prefix_len + 1) * 2;
  if (c->inc_ns_len)
    len += zx_len_inc_ns(c, &pop_seen);
  len += zx_len_xmlns_if_not_seen(c, x->gg.g.ns, &pop_seen);
  if (x->itemID)
    len += zx_len_xmlns_if_not_seen(c, x->itemID->g.ns, &pop_seen);
  if (x->objectType)
    len += zx_len_xmlns_if_not_seen(c, x->objectType->g.ns, &pop_seen);
  if (x->predefined)
    len += zx_len_xmlns_if_not_seen(c, x->predefined->g.ns, &pop_seen);

  len += zx_attr_wo_len(x->id, sizeof("id")-1);
  len += zx_attr_wo_len(x->notChangedSince, sizeof("notChangedSince")-1);
  len += zx_attr_wo_len(x->itemID, sizeof("itemID")-1);
  len += zx_attr_wo_len(x->objectType, sizeof("objectType")-1);
  len += zx_attr_wo_len(x->predefined, sizeof("predefined")-1);

#else
  /* root node has no begin tag */
  int len = 0;
#endif
  
  {
      struct zx_dap_Select_s* e;
      for (e = x->Select; e; e = (struct zx_dap_Select_s*)e->gg.g.n)
	  len += zx_LEN_WO_dap_Select(c, e);
  }


  len += zx_len_wo_common(c, &x->gg); 
  zx_pop_seen(pop_seen);
  ENC_LEN_DEBUG(x, "dap:DeleteItem", len);
  return len;
}

/* FUNC(zx_ENC_SO_dap_DeleteItem) */

/* Render element into string. The XML attributes and elements are
 * processed in schema order. This is what you generally want for
 * rendering new data structure to a string. The wo pointers are not used. */

/* Called by: */
char* zx_ENC_SO_dap_DeleteItem(struct zx_ctx* c, struct zx_dap_DeleteItem_s* x, char* p )
{
  struct zx_elem_s* se MAYBE_UNUSED;
  ENC_LEN_DEBUG_BASE;
#if 1 /* NORMALMODE */
  struct zx_ns_s* pop_seen = 0;
  /* *** in simple_elem case should output ns prefix from ns node. */
  ZX_OUT_TAG(p, "<dap:DeleteItem");
  if (c->inc_ns)
    p = zx_enc_inc_ns(c, p, &pop_seen);
  p = zx_enc_xmlns_if_not_seen(c, p, zx_ns_tab+zx_xmlns_ix_dap, &pop_seen);
  if (x->itemID || x->objectType || x->predefined)
    p = zx_enc_xmlns_if_not_seen(c, p, zx_ns_tab+zx_xmlns_ix_dst, &pop_seen);

  p = zx_attr_so_enc(p, x->id, " id=\"", sizeof(" id=\"")-1);
  p = zx_attr_so_enc(p, x->notChangedSince, " notChangedSince=\"", sizeof(" notChangedSince=\"")-1);
  p = zx_attr_so_enc(p, x->itemID, " dst:itemID=\"", sizeof(" dst:itemID=\"")-1);
  p = zx_attr_so_enc(p, x->objectType, " dst:objectType=\"", sizeof(" dst:objectType=\"")-1);
  p = zx_attr_so_enc(p, x->predefined, " dst:predefined=\"", sizeof(" dst:predefined=\"")-1);

  p = zx_enc_unknown_attrs(p, x->gg.any_attr);
#else
  /* root node has no begin tag */
#endif
  
  {
      struct zx_dap_Select_s* e;
      for (e = x->Select; e; e = (struct zx_dap_Select_s*)e->gg.g.n)
	  p = zx_ENC_SO_dap_Select(c, e, p);
  }

  p = zx_enc_so_unknown_elems_and_content(c, p, &x->gg);
  
#if 1 /* NORMALMODE */
  ZX_OUT_CLOSE_TAG(p, "</dap:DeleteItem>");
  zx_pop_seen(pop_seen);
#else
  /* root node has no end tag either */
#endif
  ENC_LEN_DEBUG(x, "dap:DeleteItem", p-enc_base);
  return p;
}

/* FUNC(zx_ENC_WO_dap_DeleteItem) */

/* Render element into string. The XML attributes and elements are
 * processed in wire order by chasing wo pointers. This is what you want for
 * validating signatures on other people's XML documents. */

/* Called by: */
char* zx_ENC_WO_dap_DeleteItem(struct zx_ctx* c, struct zx_dap_DeleteItem_s* x, char* p )
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
  ZX_OUT_MEM(p, "DeleteItem", sizeof("DeleteItem")-1);
  qq = p;

  /* *** sort the namespaces */
  if (c->inc_ns)
    zx_add_inc_ns(c, &pop_seen);
  zx_add_xmlns_if_not_seen(c, x->gg.g.ns, &pop_seen);
  if (x->itemID)
    zx_add_xmlns_if_not_seen(c, x->itemID->g.ns, &pop_seen);
  if (x->objectType)
    zx_add_xmlns_if_not_seen(c, x->objectType->g.ns, &pop_seen);
  if (x->predefined)
    zx_add_xmlns_if_not_seen(c, x->predefined->g.ns, &pop_seen);

  p = zx_enc_seen(p, pop_seen); 
  p = zx_attr_wo_enc(p, x->id, "id=\"", sizeof("id=\"")-1);
  p = zx_attr_wo_enc(p, x->notChangedSince, "notChangedSince=\"", sizeof("notChangedSince=\"")-1);
  p = zx_attr_wo_enc(p, x->itemID, "itemID=\"", sizeof("itemID=\"")-1);
  p = zx_attr_wo_enc(p, x->objectType, "objectType=\"", sizeof("objectType=\"")-1);
  p = zx_attr_wo_enc(p, x->predefined, "predefined=\"", sizeof("predefined=\"")-1);

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
  ENC_LEN_DEBUG(x, "dap:DeleteItem", p-enc_base);
  return p;
}

/* FUNC(zx_EASY_ENC_SO_dap_DeleteItem) */

/* Called by: */
struct zx_str* zx_EASY_ENC_SO_dap_DeleteItem(struct zx_ctx* c, struct zx_dap_DeleteItem_s* x )
{
  int len;
  char* buf;
  c->ns_tab = ZX_ALLOC(c, sizeof(zx_ns_tab));
  memcpy(c->ns_tab, zx_ns_tab, sizeof(zx_ns_tab));
  len = zx_LEN_SO_dap_DeleteItem(c, x );
  buf = ZX_ALLOC(c, len+1);
  return zx_easy_enc_common(c, zx_ENC_SO_dap_DeleteItem(c, x, buf ), buf, len);
}

/* FUNC(zx_EASY_ENC_WO_dap_DeleteItem) */

/* Called by: */
struct zx_str* zx_EASY_ENC_WO_dap_DeleteItem(struct zx_ctx* c, struct zx_dap_DeleteItem_s* x )
{
  int len;
  char* buf;
  c->ns_tab = ZX_ALLOC(c, sizeof(zx_ns_tab));
  memcpy(c->ns_tab, zx_ns_tab, sizeof(zx_ns_tab));
  len = zx_LEN_WO_dap_DeleteItem(c, x );
  buf = ZX_ALLOC(c, len+1);
  return zx_easy_enc_common(c, zx_ENC_WO_dap_DeleteItem(c, x, buf ), buf, len);
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

#define EL_NAME   dap_DeleteResponse
#define EL_STRUCT zx_dap_DeleteResponse_s
#define EL_NS     dap
#define EL_TAG    DeleteResponse

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

/* FUNC(zx_LEN_SO_dap_DeleteResponse) */

/* Compute length of an element (and its subelements). The XML attributes
 * and elements are processed in schema order. */

/* Called by: */
int zx_LEN_SO_dap_DeleteResponse(struct zx_ctx* c, struct zx_dap_DeleteResponse_s* x )
{
  struct zx_ns_s* pop_seen = 0;
  struct zx_elem_s* se MAYBE_UNUSED;
#if 1 /* NORMALMODE */
  /* *** in simple_elem case should output ns prefix from ns node. */
  int len = sizeof("<dap:DeleteResponse")-1 + 1 + sizeof("</dap:DeleteResponse>")-1;
  if (c->inc_ns_len)
    len += zx_len_inc_ns(c, &pop_seen);
  len += zx_len_xmlns_if_not_seen(c, zx_ns_tab+zx_xmlns_ix_dap, &pop_seen);

  len += zx_attr_so_len(x->itemIDRef, sizeof("itemIDRef")-1);

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
      struct zx_lu_Extension_s* e;
      for (e = x->Extension; e; e = (struct zx_lu_Extension_s*)e->gg.g.n)
	  len += zx_LEN_SO_lu_Extension(c, e);
  }


  len += zx_len_so_common(c, &x->gg);
  zx_pop_seen(pop_seen);
  ENC_LEN_DEBUG(x, "dap:DeleteResponse", len);
  return len;
}

/* FUNC(zx_LEN_WO_dap_DeleteResponse) */

/* Compute length of an element (and its subelements). The XML attributes
 * and elements are processed in wire order and no assumptions
 * are made about namespace prefixes. */

/* Called by: */
int zx_LEN_WO_dap_DeleteResponse(struct zx_ctx* c, struct zx_dap_DeleteResponse_s* x )
{
  struct zx_ns_s* pop_seen = 0;
  struct zx_elem_s* se MAYBE_UNUSED;
#if 1 /* NORMALMODE */
  int len = 1 + sizeof("DeleteResponse")-1 + 1 + 2 + sizeof("DeleteResponse")-1 + 1;
  
  if (x->gg.g.ns && x->gg.g.ns->prefix_len)
    len += (x->gg.g.ns->prefix_len + 1) * 2;
  if (c->inc_ns_len)
    len += zx_len_inc_ns(c, &pop_seen);
  len += zx_len_xmlns_if_not_seen(c, x->gg.g.ns, &pop_seen);

  len += zx_attr_wo_len(x->itemIDRef, sizeof("itemIDRef")-1);

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
      struct zx_lu_Extension_s* e;
      for (e = x->Extension; e; e = (struct zx_lu_Extension_s*)e->gg.g.n)
	  len += zx_LEN_WO_lu_Extension(c, e);
  }


  len += zx_len_wo_common(c, &x->gg); 
  zx_pop_seen(pop_seen);
  ENC_LEN_DEBUG(x, "dap:DeleteResponse", len);
  return len;
}

/* FUNC(zx_ENC_SO_dap_DeleteResponse) */

/* Render element into string. The XML attributes and elements are
 * processed in schema order. This is what you generally want for
 * rendering new data structure to a string. The wo pointers are not used. */

/* Called by: */
char* zx_ENC_SO_dap_DeleteResponse(struct zx_ctx* c, struct zx_dap_DeleteResponse_s* x, char* p )
{
  struct zx_elem_s* se MAYBE_UNUSED;
  ENC_LEN_DEBUG_BASE;
#if 1 /* NORMALMODE */
  struct zx_ns_s* pop_seen = 0;
  /* *** in simple_elem case should output ns prefix from ns node. */
  ZX_OUT_TAG(p, "<dap:DeleteResponse");
  if (c->inc_ns)
    p = zx_enc_inc_ns(c, p, &pop_seen);
  p = zx_enc_xmlns_if_not_seen(c, p, zx_ns_tab+zx_xmlns_ix_dap, &pop_seen);

  p = zx_attr_so_enc(p, x->itemIDRef, " itemIDRef=\"", sizeof(" itemIDRef=\"")-1);

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
      struct zx_lu_Extension_s* e;
      for (e = x->Extension; e; e = (struct zx_lu_Extension_s*)e->gg.g.n)
	  p = zx_ENC_SO_lu_Extension(c, e, p);
  }

  p = zx_enc_so_unknown_elems_and_content(c, p, &x->gg);
  
#if 1 /* NORMALMODE */
  ZX_OUT_CLOSE_TAG(p, "</dap:DeleteResponse>");
  zx_pop_seen(pop_seen);
#else
  /* root node has no end tag either */
#endif
  ENC_LEN_DEBUG(x, "dap:DeleteResponse", p-enc_base);
  return p;
}

/* FUNC(zx_ENC_WO_dap_DeleteResponse) */

/* Render element into string. The XML attributes and elements are
 * processed in wire order by chasing wo pointers. This is what you want for
 * validating signatures on other people's XML documents. */

/* Called by: */
char* zx_ENC_WO_dap_DeleteResponse(struct zx_ctx* c, struct zx_dap_DeleteResponse_s* x, char* p )
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
  ZX_OUT_MEM(p, "DeleteResponse", sizeof("DeleteResponse")-1);
  qq = p;

  /* *** sort the namespaces */
  if (c->inc_ns)
    zx_add_inc_ns(c, &pop_seen);
  zx_add_xmlns_if_not_seen(c, x->gg.g.ns, &pop_seen);

  p = zx_enc_seen(p, pop_seen); 
  p = zx_attr_wo_enc(p, x->itemIDRef, "itemIDRef=\"", sizeof("itemIDRef=\"")-1);

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
  ENC_LEN_DEBUG(x, "dap:DeleteResponse", p-enc_base);
  return p;
}

/* FUNC(zx_EASY_ENC_SO_dap_DeleteResponse) */

/* Called by: */
struct zx_str* zx_EASY_ENC_SO_dap_DeleteResponse(struct zx_ctx* c, struct zx_dap_DeleteResponse_s* x )
{
  int len;
  char* buf;
  c->ns_tab = ZX_ALLOC(c, sizeof(zx_ns_tab));
  memcpy(c->ns_tab, zx_ns_tab, sizeof(zx_ns_tab));
  len = zx_LEN_SO_dap_DeleteResponse(c, x );
  buf = ZX_ALLOC(c, len+1);
  return zx_easy_enc_common(c, zx_ENC_SO_dap_DeleteResponse(c, x, buf ), buf, len);
}

/* FUNC(zx_EASY_ENC_WO_dap_DeleteResponse) */

/* Called by: */
struct zx_str* zx_EASY_ENC_WO_dap_DeleteResponse(struct zx_ctx* c, struct zx_dap_DeleteResponse_s* x )
{
  int len;
  char* buf;
  c->ns_tab = ZX_ALLOC(c, sizeof(zx_ns_tab));
  memcpy(c->ns_tab, zx_ns_tab, sizeof(zx_ns_tab));
  len = zx_LEN_WO_dap_DeleteResponse(c, x );
  buf = ZX_ALLOC(c, len+1);
  return zx_easy_enc_common(c, zx_ENC_WO_dap_DeleteResponse(c, x, buf ), buf, len);
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

#define EL_NAME   dap_ItemData
#define EL_STRUCT zx_dap_ItemData_s
#define EL_NS     dap
#define EL_TAG    ItemData

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

/* FUNC(zx_LEN_SO_dap_ItemData) */

/* Compute length of an element (and its subelements). The XML attributes
 * and elements are processed in schema order. */

/* Called by: */
int zx_LEN_SO_dap_ItemData(struct zx_ctx* c, struct zx_dap_ItemData_s* x )
{
  struct zx_ns_s* pop_seen = 0;
  struct zx_elem_s* se MAYBE_UNUSED;
#if 1 /* NORMALMODE */
  /* *** in simple_elem case should output ns prefix from ns node. */
  int len = sizeof("<dap:ItemData")-1 + 1 + sizeof("</dap:ItemData>")-1;
  if (c->inc_ns_len)
    len += zx_len_inc_ns(c, &pop_seen);
  len += zx_len_xmlns_if_not_seen(c, zx_ns_tab+zx_xmlns_ix_dap, &pop_seen);
  if (x->changeFormat || x->itemIDRef)
    len += zx_len_xmlns_if_not_seen(c, zx_ns_tab+zx_xmlns_ix_dst, &pop_seen);

  len += zx_attr_so_len(x->notSorted, sizeof("notSorted")-1);
  len += zx_attr_so_len(x->changeFormat, sizeof("dst:changeFormat")-1);
  len += zx_attr_so_len(x->itemIDRef, sizeof("dst:itemIDRef")-1);

#else
  /* root node has no begin tag */
  int len = 0;
#endif
  
  {
      struct zx_dap_LDIF_s* e;
      for (e = x->LDIF; e; e = (struct zx_dap_LDIF_s*)e->gg.g.n)
	  len += zx_LEN_SO_dap_LDIF(c, e);
  }
  {
      struct zx_dap_Subscription_s* e;
      for (e = x->Subscription; e; e = (struct zx_dap_Subscription_s*)e->gg.g.n)
	  len += zx_LEN_SO_dap_Subscription(c, e);
  }


  len += zx_len_so_common(c, &x->gg);
  zx_pop_seen(pop_seen);
  ENC_LEN_DEBUG(x, "dap:ItemData", len);
  return len;
}

/* FUNC(zx_LEN_WO_dap_ItemData) */

/* Compute length of an element (and its subelements). The XML attributes
 * and elements are processed in wire order and no assumptions
 * are made about namespace prefixes. */

/* Called by: */
int zx_LEN_WO_dap_ItemData(struct zx_ctx* c, struct zx_dap_ItemData_s* x )
{
  struct zx_ns_s* pop_seen = 0;
  struct zx_elem_s* se MAYBE_UNUSED;
#if 1 /* NORMALMODE */
  int len = 1 + sizeof("ItemData")-1 + 1 + 2 + sizeof("ItemData")-1 + 1;
  
  if (x->gg.g.ns && x->gg.g.ns->prefix_len)
    len += (x->gg.g.ns->prefix_len + 1) * 2;
  if (c->inc_ns_len)
    len += zx_len_inc_ns(c, &pop_seen);
  len += zx_len_xmlns_if_not_seen(c, x->gg.g.ns, &pop_seen);
  if (x->changeFormat)
    len += zx_len_xmlns_if_not_seen(c, x->changeFormat->g.ns, &pop_seen);
  if (x->itemIDRef)
    len += zx_len_xmlns_if_not_seen(c, x->itemIDRef->g.ns, &pop_seen);

  len += zx_attr_wo_len(x->notSorted, sizeof("notSorted")-1);
  len += zx_attr_wo_len(x->changeFormat, sizeof("changeFormat")-1);
  len += zx_attr_wo_len(x->itemIDRef, sizeof("itemIDRef")-1);

#else
  /* root node has no begin tag */
  int len = 0;
#endif
  
  {
      struct zx_dap_LDIF_s* e;
      for (e = x->LDIF; e; e = (struct zx_dap_LDIF_s*)e->gg.g.n)
	  len += zx_LEN_WO_dap_LDIF(c, e);
  }
  {
      struct zx_dap_Subscription_s* e;
      for (e = x->Subscription; e; e = (struct zx_dap_Subscription_s*)e->gg.g.n)
	  len += zx_LEN_WO_dap_Subscription(c, e);
  }


  len += zx_len_wo_common(c, &x->gg); 
  zx_pop_seen(pop_seen);
  ENC_LEN_DEBUG(x, "dap:ItemData", len);
  return len;
}

/* FUNC(zx_ENC_SO_dap_ItemData) */

/* Render element into string. The XML attributes and elements are
 * processed in schema order. This is what you generally want for
 * rendering new data structure to a string. The wo pointers are not used. */

/* Called by: */
char* zx_ENC_SO_dap_ItemData(struct zx_ctx* c, struct zx_dap_ItemData_s* x, char* p )
{
  struct zx_elem_s* se MAYBE_UNUSED;
  ENC_LEN_DEBUG_BASE;
#if 1 /* NORMALMODE */
  struct zx_ns_s* pop_seen = 0;
  /* *** in simple_elem case should output ns prefix from ns node. */
  ZX_OUT_TAG(p, "<dap:ItemData");
  if (c->inc_ns)
    p = zx_enc_inc_ns(c, p, &pop_seen);
  p = zx_enc_xmlns_if_not_seen(c, p, zx_ns_tab+zx_xmlns_ix_dap, &pop_seen);
  if (x->changeFormat || x->itemIDRef)
    p = zx_enc_xmlns_if_not_seen(c, p, zx_ns_tab+zx_xmlns_ix_dst, &pop_seen);

  p = zx_attr_so_enc(p, x->notSorted, " notSorted=\"", sizeof(" notSorted=\"")-1);
  p = zx_attr_so_enc(p, x->changeFormat, " dst:changeFormat=\"", sizeof(" dst:changeFormat=\"")-1);
  p = zx_attr_so_enc(p, x->itemIDRef, " dst:itemIDRef=\"", sizeof(" dst:itemIDRef=\"")-1);

  p = zx_enc_unknown_attrs(p, x->gg.any_attr);
#else
  /* root node has no begin tag */
#endif
  
  {
      struct zx_dap_LDIF_s* e;
      for (e = x->LDIF; e; e = (struct zx_dap_LDIF_s*)e->gg.g.n)
	  p = zx_ENC_SO_dap_LDIF(c, e, p);
  }
  {
      struct zx_dap_Subscription_s* e;
      for (e = x->Subscription; e; e = (struct zx_dap_Subscription_s*)e->gg.g.n)
	  p = zx_ENC_SO_dap_Subscription(c, e, p);
  }

  p = zx_enc_so_unknown_elems_and_content(c, p, &x->gg);
  
#if 1 /* NORMALMODE */
  ZX_OUT_CLOSE_TAG(p, "</dap:ItemData>");
  zx_pop_seen(pop_seen);
#else
  /* root node has no end tag either */
#endif
  ENC_LEN_DEBUG(x, "dap:ItemData", p-enc_base);
  return p;
}

/* FUNC(zx_ENC_WO_dap_ItemData) */

/* Render element into string. The XML attributes and elements are
 * processed in wire order by chasing wo pointers. This is what you want for
 * validating signatures on other people's XML documents. */

/* Called by: */
char* zx_ENC_WO_dap_ItemData(struct zx_ctx* c, struct zx_dap_ItemData_s* x, char* p )
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
  ZX_OUT_MEM(p, "ItemData", sizeof("ItemData")-1);
  qq = p;

  /* *** sort the namespaces */
  if (c->inc_ns)
    zx_add_inc_ns(c, &pop_seen);
  zx_add_xmlns_if_not_seen(c, x->gg.g.ns, &pop_seen);
  if (x->changeFormat)
    zx_add_xmlns_if_not_seen(c, x->changeFormat->g.ns, &pop_seen);
  if (x->itemIDRef)
    zx_add_xmlns_if_not_seen(c, x->itemIDRef->g.ns, &pop_seen);

  p = zx_enc_seen(p, pop_seen); 
  p = zx_attr_wo_enc(p, x->notSorted, "notSorted=\"", sizeof("notSorted=\"")-1);
  p = zx_attr_wo_enc(p, x->changeFormat, "changeFormat=\"", sizeof("changeFormat=\"")-1);
  p = zx_attr_wo_enc(p, x->itemIDRef, "itemIDRef=\"", sizeof("itemIDRef=\"")-1);

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
  ENC_LEN_DEBUG(x, "dap:ItemData", p-enc_base);
  return p;
}

/* FUNC(zx_EASY_ENC_SO_dap_ItemData) */

/* Called by: */
struct zx_str* zx_EASY_ENC_SO_dap_ItemData(struct zx_ctx* c, struct zx_dap_ItemData_s* x )
{
  int len;
  char* buf;
  c->ns_tab = ZX_ALLOC(c, sizeof(zx_ns_tab));
  memcpy(c->ns_tab, zx_ns_tab, sizeof(zx_ns_tab));
  len = zx_LEN_SO_dap_ItemData(c, x );
  buf = ZX_ALLOC(c, len+1);
  return zx_easy_enc_common(c, zx_ENC_SO_dap_ItemData(c, x, buf ), buf, len);
}

/* FUNC(zx_EASY_ENC_WO_dap_ItemData) */

/* Called by: */
struct zx_str* zx_EASY_ENC_WO_dap_ItemData(struct zx_ctx* c, struct zx_dap_ItemData_s* x )
{
  int len;
  char* buf;
  c->ns_tab = ZX_ALLOC(c, sizeof(zx_ns_tab));
  memcpy(c->ns_tab, zx_ns_tab, sizeof(zx_ns_tab));
  len = zx_LEN_WO_dap_ItemData(c, x );
  buf = ZX_ALLOC(c, len+1);
  return zx_easy_enc_common(c, zx_ENC_WO_dap_ItemData(c, x, buf ), buf, len);
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

#define EL_NAME   dap_LDIF
#define EL_STRUCT zx_dap_LDIF_s
#define EL_NS     dap
#define EL_TAG    LDIF

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

/* FUNC(zx_LEN_SO_dap_LDIF) */

/* Compute length of an element (and its subelements). The XML attributes
 * and elements are processed in schema order. */

/* Called by: */
int zx_LEN_SO_dap_LDIF(struct zx_ctx* c, struct zx_dap_LDIF_s* x )
{
  struct zx_ns_s* pop_seen = 0;
  struct zx_elem_s* se MAYBE_UNUSED;
#if 1 /* NORMALMODE */
  /* *** in simple_elem case should output ns prefix from ns node. */
  int len = sizeof("<dap:LDIF")-1 + 1 + sizeof("</dap:LDIF>")-1;
  if (c->inc_ns_len)
    len += zx_len_inc_ns(c, &pop_seen);
  len += zx_len_xmlns_if_not_seen(c, zx_ns_tab+zx_xmlns_ix_dap, &pop_seen);
  if (x->ACC || x->ACCTime || x->id || x->modificationTime || x->modifier || x->script)
    len += zx_len_xmlns_if_not_seen(c, zx_ns_tab+zx_xmlns_ix_dst, &pop_seen);
  if (x->lang)
    len += zx_len_xmlns_if_not_seen(c, zx_ns_tab+zx_xmlns_ix_xml, &pop_seen);

  len += zx_attr_so_len(x->lang, sizeof("xml:lang")-1);
  len += zx_attr_so_len(x->ACC, sizeof("dst:ACC")-1);
  len += zx_attr_so_len(x->ACCTime, sizeof("dst:ACCTime")-1);
  len += zx_attr_so_len(x->id, sizeof("dst:id")-1);
  len += zx_attr_so_len(x->modificationTime, sizeof("dst:modificationTime")-1);
  len += zx_attr_so_len(x->modifier, sizeof("dst:modifier")-1);
  len += zx_attr_so_len(x->script, sizeof("dst:script")-1);

#else
  /* root node has no begin tag */
  int len = 0;
#endif
  


  len += zx_len_so_common(c, &x->gg);
  zx_pop_seen(pop_seen);
  ENC_LEN_DEBUG(x, "dap:LDIF", len);
  return len;
}

/* FUNC(zx_LEN_WO_dap_LDIF) */

/* Compute length of an element (and its subelements). The XML attributes
 * and elements are processed in wire order and no assumptions
 * are made about namespace prefixes. */

/* Called by: */
int zx_LEN_WO_dap_LDIF(struct zx_ctx* c, struct zx_dap_LDIF_s* x )
{
  struct zx_ns_s* pop_seen = 0;
  struct zx_elem_s* se MAYBE_UNUSED;
#if 1 /* NORMALMODE */
  int len = 1 + sizeof("LDIF")-1 + 1 + 2 + sizeof("LDIF")-1 + 1;
  
  if (x->gg.g.ns && x->gg.g.ns->prefix_len)
    len += (x->gg.g.ns->prefix_len + 1) * 2;
  if (c->inc_ns_len)
    len += zx_len_inc_ns(c, &pop_seen);
  len += zx_len_xmlns_if_not_seen(c, x->gg.g.ns, &pop_seen);
  if (x->ACC)
    len += zx_len_xmlns_if_not_seen(c, x->ACC->g.ns, &pop_seen);
  if (x->ACCTime)
    len += zx_len_xmlns_if_not_seen(c, x->ACCTime->g.ns, &pop_seen);
  if (x->id)
    len += zx_len_xmlns_if_not_seen(c, x->id->g.ns, &pop_seen);
  if (x->modificationTime)
    len += zx_len_xmlns_if_not_seen(c, x->modificationTime->g.ns, &pop_seen);
  if (x->modifier)
    len += zx_len_xmlns_if_not_seen(c, x->modifier->g.ns, &pop_seen);
  if (x->script)
    len += zx_len_xmlns_if_not_seen(c, x->script->g.ns, &pop_seen);
  if (x->lang)
    len += zx_len_xmlns_if_not_seen(c, x->lang->g.ns, &pop_seen);

  len += zx_attr_wo_len(x->lang, sizeof("lang")-1);
  len += zx_attr_wo_len(x->ACC, sizeof("ACC")-1);
  len += zx_attr_wo_len(x->ACCTime, sizeof("ACCTime")-1);
  len += zx_attr_wo_len(x->id, sizeof("id")-1);
  len += zx_attr_wo_len(x->modificationTime, sizeof("modificationTime")-1);
  len += zx_attr_wo_len(x->modifier, sizeof("modifier")-1);
  len += zx_attr_wo_len(x->script, sizeof("script")-1);

#else
  /* root node has no begin tag */
  int len = 0;
#endif
  


  len += zx_len_wo_common(c, &x->gg); 
  zx_pop_seen(pop_seen);
  ENC_LEN_DEBUG(x, "dap:LDIF", len);
  return len;
}

/* FUNC(zx_ENC_SO_dap_LDIF) */

/* Render element into string. The XML attributes and elements are
 * processed in schema order. This is what you generally want for
 * rendering new data structure to a string. The wo pointers are not used. */

/* Called by: */
char* zx_ENC_SO_dap_LDIF(struct zx_ctx* c, struct zx_dap_LDIF_s* x, char* p )
{
  struct zx_elem_s* se MAYBE_UNUSED;
  ENC_LEN_DEBUG_BASE;
#if 1 /* NORMALMODE */
  struct zx_ns_s* pop_seen = 0;
  /* *** in simple_elem case should output ns prefix from ns node. */
  ZX_OUT_TAG(p, "<dap:LDIF");
  if (c->inc_ns)
    p = zx_enc_inc_ns(c, p, &pop_seen);
  p = zx_enc_xmlns_if_not_seen(c, p, zx_ns_tab+zx_xmlns_ix_dap, &pop_seen);
  if (x->ACC || x->ACCTime || x->id || x->modificationTime || x->modifier || x->script)
    p = zx_enc_xmlns_if_not_seen(c, p, zx_ns_tab+zx_xmlns_ix_dst, &pop_seen);
  if (x->lang)
    p = zx_enc_xmlns_if_not_seen(c, p, zx_ns_tab+zx_xmlns_ix_xml, &pop_seen);

  p = zx_attr_so_enc(p, x->lang, " xml:lang=\"", sizeof(" xml:lang=\"")-1);
  p = zx_attr_so_enc(p, x->ACC, " dst:ACC=\"", sizeof(" dst:ACC=\"")-1);
  p = zx_attr_so_enc(p, x->ACCTime, " dst:ACCTime=\"", sizeof(" dst:ACCTime=\"")-1);
  p = zx_attr_so_enc(p, x->id, " dst:id=\"", sizeof(" dst:id=\"")-1);
  p = zx_attr_so_enc(p, x->modificationTime, " dst:modificationTime=\"", sizeof(" dst:modificationTime=\"")-1);
  p = zx_attr_so_enc(p, x->modifier, " dst:modifier=\"", sizeof(" dst:modifier=\"")-1);
  p = zx_attr_so_enc(p, x->script, " dst:script=\"", sizeof(" dst:script=\"")-1);

  p = zx_enc_unknown_attrs(p, x->gg.any_attr);
#else
  /* root node has no begin tag */
#endif
  

  p = zx_enc_so_unknown_elems_and_content(c, p, &x->gg);
  
#if 1 /* NORMALMODE */
  ZX_OUT_CLOSE_TAG(p, "</dap:LDIF>");
  zx_pop_seen(pop_seen);
#else
  /* root node has no end tag either */
#endif
  ENC_LEN_DEBUG(x, "dap:LDIF", p-enc_base);
  return p;
}

/* FUNC(zx_ENC_WO_dap_LDIF) */

/* Render element into string. The XML attributes and elements are
 * processed in wire order by chasing wo pointers. This is what you want for
 * validating signatures on other people's XML documents. */

/* Called by: */
char* zx_ENC_WO_dap_LDIF(struct zx_ctx* c, struct zx_dap_LDIF_s* x, char* p )
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
  ZX_OUT_MEM(p, "LDIF", sizeof("LDIF")-1);
  qq = p;

  /* *** sort the namespaces */
  if (c->inc_ns)
    zx_add_inc_ns(c, &pop_seen);
  zx_add_xmlns_if_not_seen(c, x->gg.g.ns, &pop_seen);
  if (x->ACC)
    zx_add_xmlns_if_not_seen(c, x->ACC->g.ns, &pop_seen);
  if (x->ACCTime)
    zx_add_xmlns_if_not_seen(c, x->ACCTime->g.ns, &pop_seen);
  if (x->id)
    zx_add_xmlns_if_not_seen(c, x->id->g.ns, &pop_seen);
  if (x->modificationTime)
    zx_add_xmlns_if_not_seen(c, x->modificationTime->g.ns, &pop_seen);
  if (x->modifier)
    zx_add_xmlns_if_not_seen(c, x->modifier->g.ns, &pop_seen);
  if (x->script)
    zx_add_xmlns_if_not_seen(c, x->script->g.ns, &pop_seen);
  if (x->lang)
    zx_add_xmlns_if_not_seen(c, x->lang->g.ns, &pop_seen);

  p = zx_enc_seen(p, pop_seen); 
  p = zx_attr_wo_enc(p, x->lang, "lang=\"", sizeof("lang=\"")-1);
  p = zx_attr_wo_enc(p, x->ACC, "ACC=\"", sizeof("ACC=\"")-1);
  p = zx_attr_wo_enc(p, x->ACCTime, "ACCTime=\"", sizeof("ACCTime=\"")-1);
  p = zx_attr_wo_enc(p, x->id, "id=\"", sizeof("id=\"")-1);
  p = zx_attr_wo_enc(p, x->modificationTime, "modificationTime=\"", sizeof("modificationTime=\"")-1);
  p = zx_attr_wo_enc(p, x->modifier, "modifier=\"", sizeof("modifier=\"")-1);
  p = zx_attr_wo_enc(p, x->script, "script=\"", sizeof("script=\"")-1);

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
  ENC_LEN_DEBUG(x, "dap:LDIF", p-enc_base);
  return p;
}

/* FUNC(zx_EASY_ENC_SO_dap_LDIF) */

/* Called by: */
struct zx_str* zx_EASY_ENC_SO_dap_LDIF(struct zx_ctx* c, struct zx_dap_LDIF_s* x )
{
  int len;
  char* buf;
  c->ns_tab = ZX_ALLOC(c, sizeof(zx_ns_tab));
  memcpy(c->ns_tab, zx_ns_tab, sizeof(zx_ns_tab));
  len = zx_LEN_SO_dap_LDIF(c, x );
  buf = ZX_ALLOC(c, len+1);
  return zx_easy_enc_common(c, zx_ENC_SO_dap_LDIF(c, x, buf ), buf, len);
}

/* FUNC(zx_EASY_ENC_WO_dap_LDIF) */

/* Called by: */
struct zx_str* zx_EASY_ENC_WO_dap_LDIF(struct zx_ctx* c, struct zx_dap_LDIF_s* x )
{
  int len;
  char* buf;
  c->ns_tab = ZX_ALLOC(c, sizeof(zx_ns_tab));
  memcpy(c->ns_tab, zx_ns_tab, sizeof(zx_ns_tab));
  len = zx_LEN_WO_dap_LDIF(c, x );
  buf = ZX_ALLOC(c, len+1);
  return zx_easy_enc_common(c, zx_ENC_WO_dap_LDIF(c, x, buf ), buf, len);
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

#define EL_NAME   dap_Modify
#define EL_STRUCT zx_dap_Modify_s
#define EL_NS     dap
#define EL_TAG    Modify

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

/* FUNC(zx_LEN_SO_dap_Modify) */

/* Compute length of an element (and its subelements). The XML attributes
 * and elements are processed in schema order. */

/* Called by: */
int zx_LEN_SO_dap_Modify(struct zx_ctx* c, struct zx_dap_Modify_s* x )
{
  struct zx_ns_s* pop_seen = 0;
  struct zx_elem_s* se MAYBE_UNUSED;
#if 1 /* NORMALMODE */
  /* *** in simple_elem case should output ns prefix from ns node. */
  int len = sizeof("<dap:Modify")-1 + 1 + sizeof("</dap:Modify>")-1;
  if (c->inc_ns_len)
    len += zx_len_inc_ns(c, &pop_seen);
  len += zx_len_xmlns_if_not_seen(c, zx_ns_tab+zx_xmlns_ix_dap, &pop_seen);
  if (x->itemID)
    len += zx_len_xmlns_if_not_seen(c, zx_ns_tab+zx_xmlns_ix_dst, &pop_seen);

  len += zx_attr_so_len(x->itemID, sizeof("dst:itemID")-1);

#else
  /* root node has no begin tag */
  int len = 0;
#endif
  
  {
      struct zx_lu_Extension_s* e;
      for (e = x->Extension; e; e = (struct zx_lu_Extension_s*)e->gg.g.n)
	  len += zx_LEN_SO_lu_Extension(c, e);
  }
  {
      struct zx_dap_Subscription_s* e;
      for (e = x->Subscription; e; e = (struct zx_dap_Subscription_s*)e->gg.g.n)
	  len += zx_LEN_SO_dap_Subscription(c, e);
  }
  {
      struct zx_dap_ModifyItem_s* e;
      for (e = x->ModifyItem; e; e = (struct zx_dap_ModifyItem_s*)e->gg.g.n)
	  len += zx_LEN_SO_dap_ModifyItem(c, e);
  }
  {
      struct zx_dap_ResultQuery_s* e;
      for (e = x->ResultQuery; e; e = (struct zx_dap_ResultQuery_s*)e->gg.g.n)
	  len += zx_LEN_SO_dap_ResultQuery(c, e);
  }


  len += zx_len_so_common(c, &x->gg);
  zx_pop_seen(pop_seen);
  ENC_LEN_DEBUG(x, "dap:Modify", len);
  return len;
}

/* FUNC(zx_LEN_WO_dap_Modify) */

/* Compute length of an element (and its subelements). The XML attributes
 * and elements are processed in wire order and no assumptions
 * are made about namespace prefixes. */

/* Called by: */
int zx_LEN_WO_dap_Modify(struct zx_ctx* c, struct zx_dap_Modify_s* x )
{
  struct zx_ns_s* pop_seen = 0;
  struct zx_elem_s* se MAYBE_UNUSED;
#if 1 /* NORMALMODE */
  int len = 1 + sizeof("Modify")-1 + 1 + 2 + sizeof("Modify")-1 + 1;
  
  if (x->gg.g.ns && x->gg.g.ns->prefix_len)
    len += (x->gg.g.ns->prefix_len + 1) * 2;
  if (c->inc_ns_len)
    len += zx_len_inc_ns(c, &pop_seen);
  len += zx_len_xmlns_if_not_seen(c, x->gg.g.ns, &pop_seen);
  if (x->itemID)
    len += zx_len_xmlns_if_not_seen(c, x->itemID->g.ns, &pop_seen);

  len += zx_attr_wo_len(x->itemID, sizeof("itemID")-1);

#else
  /* root node has no begin tag */
  int len = 0;
#endif
  
  {
      struct zx_lu_Extension_s* e;
      for (e = x->Extension; e; e = (struct zx_lu_Extension_s*)e->gg.g.n)
	  len += zx_LEN_WO_lu_Extension(c, e);
  }
  {
      struct zx_dap_Subscription_s* e;
      for (e = x->Subscription; e; e = (struct zx_dap_Subscription_s*)e->gg.g.n)
	  len += zx_LEN_WO_dap_Subscription(c, e);
  }
  {
      struct zx_dap_ModifyItem_s* e;
      for (e = x->ModifyItem; e; e = (struct zx_dap_ModifyItem_s*)e->gg.g.n)
	  len += zx_LEN_WO_dap_ModifyItem(c, e);
  }
  {
      struct zx_dap_ResultQuery_s* e;
      for (e = x->ResultQuery; e; e = (struct zx_dap_ResultQuery_s*)e->gg.g.n)
	  len += zx_LEN_WO_dap_ResultQuery(c, e);
  }


  len += zx_len_wo_common(c, &x->gg); 
  zx_pop_seen(pop_seen);
  ENC_LEN_DEBUG(x, "dap:Modify", len);
  return len;
}

/* FUNC(zx_ENC_SO_dap_Modify) */

/* Render element into string. The XML attributes and elements are
 * processed in schema order. This is what you generally want for
 * rendering new data structure to a string. The wo pointers are not used. */

/* Called by: */
char* zx_ENC_SO_dap_Modify(struct zx_ctx* c, struct zx_dap_Modify_s* x, char* p )
{
  struct zx_elem_s* se MAYBE_UNUSED;
  ENC_LEN_DEBUG_BASE;
#if 1 /* NORMALMODE */
  struct zx_ns_s* pop_seen = 0;
  /* *** in simple_elem case should output ns prefix from ns node. */
  ZX_OUT_TAG(p, "<dap:Modify");
  if (c->inc_ns)
    p = zx_enc_inc_ns(c, p, &pop_seen);
  p = zx_enc_xmlns_if_not_seen(c, p, zx_ns_tab+zx_xmlns_ix_dap, &pop_seen);
  if (x->itemID)
    p = zx_enc_xmlns_if_not_seen(c, p, zx_ns_tab+zx_xmlns_ix_dst, &pop_seen);

  p = zx_attr_so_enc(p, x->itemID, " dst:itemID=\"", sizeof(" dst:itemID=\"")-1);

  p = zx_enc_unknown_attrs(p, x->gg.any_attr);
#else
  /* root node has no begin tag */
#endif
  
  {
      struct zx_lu_Extension_s* e;
      for (e = x->Extension; e; e = (struct zx_lu_Extension_s*)e->gg.g.n)
	  p = zx_ENC_SO_lu_Extension(c, e, p);
  }
  {
      struct zx_dap_Subscription_s* e;
      for (e = x->Subscription; e; e = (struct zx_dap_Subscription_s*)e->gg.g.n)
	  p = zx_ENC_SO_dap_Subscription(c, e, p);
  }
  {
      struct zx_dap_ModifyItem_s* e;
      for (e = x->ModifyItem; e; e = (struct zx_dap_ModifyItem_s*)e->gg.g.n)
	  p = zx_ENC_SO_dap_ModifyItem(c, e, p);
  }
  {
      struct zx_dap_ResultQuery_s* e;
      for (e = x->ResultQuery; e; e = (struct zx_dap_ResultQuery_s*)e->gg.g.n)
	  p = zx_ENC_SO_dap_ResultQuery(c, e, p);
  }

  p = zx_enc_so_unknown_elems_and_content(c, p, &x->gg);
  
#if 1 /* NORMALMODE */
  ZX_OUT_CLOSE_TAG(p, "</dap:Modify>");
  zx_pop_seen(pop_seen);
#else
  /* root node has no end tag either */
#endif
  ENC_LEN_DEBUG(x, "dap:Modify", p-enc_base);
  return p;
}

/* FUNC(zx_ENC_WO_dap_Modify) */

/* Render element into string. The XML attributes and elements are
 * processed in wire order by chasing wo pointers. This is what you want for
 * validating signatures on other people's XML documents. */

/* Called by: */
char* zx_ENC_WO_dap_Modify(struct zx_ctx* c, struct zx_dap_Modify_s* x, char* p )
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
  ZX_OUT_MEM(p, "Modify", sizeof("Modify")-1);
  qq = p;

  /* *** sort the namespaces */
  if (c->inc_ns)
    zx_add_inc_ns(c, &pop_seen);
  zx_add_xmlns_if_not_seen(c, x->gg.g.ns, &pop_seen);
  if (x->itemID)
    zx_add_xmlns_if_not_seen(c, x->itemID->g.ns, &pop_seen);

  p = zx_enc_seen(p, pop_seen); 
  p = zx_attr_wo_enc(p, x->itemID, "itemID=\"", sizeof("itemID=\"")-1);

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
  ENC_LEN_DEBUG(x, "dap:Modify", p-enc_base);
  return p;
}

/* FUNC(zx_EASY_ENC_SO_dap_Modify) */

/* Called by: */
struct zx_str* zx_EASY_ENC_SO_dap_Modify(struct zx_ctx* c, struct zx_dap_Modify_s* x )
{
  int len;
  char* buf;
  c->ns_tab = ZX_ALLOC(c, sizeof(zx_ns_tab));
  memcpy(c->ns_tab, zx_ns_tab, sizeof(zx_ns_tab));
  len = zx_LEN_SO_dap_Modify(c, x );
  buf = ZX_ALLOC(c, len+1);
  return zx_easy_enc_common(c, zx_ENC_SO_dap_Modify(c, x, buf ), buf, len);
}

/* FUNC(zx_EASY_ENC_WO_dap_Modify) */

/* Called by: */
struct zx_str* zx_EASY_ENC_WO_dap_Modify(struct zx_ctx* c, struct zx_dap_Modify_s* x )
{
  int len;
  char* buf;
  c->ns_tab = ZX_ALLOC(c, sizeof(zx_ns_tab));
  memcpy(c->ns_tab, zx_ns_tab, sizeof(zx_ns_tab));
  len = zx_LEN_WO_dap_Modify(c, x );
  buf = ZX_ALLOC(c, len+1);
  return zx_easy_enc_common(c, zx_ENC_WO_dap_Modify(c, x, buf ), buf, len);
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

#define EL_NAME   dap_ModifyItem
#define EL_STRUCT zx_dap_ModifyItem_s
#define EL_NS     dap
#define EL_TAG    ModifyItem

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

/* FUNC(zx_LEN_SO_dap_ModifyItem) */

/* Compute length of an element (and its subelements). The XML attributes
 * and elements are processed in schema order. */

/* Called by: */
int zx_LEN_SO_dap_ModifyItem(struct zx_ctx* c, struct zx_dap_ModifyItem_s* x )
{
  struct zx_ns_s* pop_seen = 0;
  struct zx_elem_s* se MAYBE_UNUSED;
#if 1 /* NORMALMODE */
  /* *** in simple_elem case should output ns prefix from ns node. */
  int len = sizeof("<dap:ModifyItem")-1 + 1 + sizeof("</dap:ModifyItem>")-1;
  if (c->inc_ns_len)
    len += zx_len_inc_ns(c, &pop_seen);
  len += zx_len_xmlns_if_not_seen(c, zx_ns_tab+zx_xmlns_ix_dap, &pop_seen);
  if (x->itemID || x->objectType || x->predefined)
    len += zx_len_xmlns_if_not_seen(c, zx_ns_tab+zx_xmlns_ix_dst, &pop_seen);

  len += zx_attr_so_len(x->id, sizeof("id")-1);
  len += zx_attr_so_len(x->notChangedSince, sizeof("notChangedSince")-1);
  len += zx_attr_so_len(x->overrideAllowed, sizeof("overrideAllowed")-1);
  len += zx_attr_so_len(x->itemID, sizeof("dst:itemID")-1);
  len += zx_attr_so_len(x->objectType, sizeof("dst:objectType")-1);
  len += zx_attr_so_len(x->predefined, sizeof("dst:predefined")-1);

#else
  /* root node has no begin tag */
  int len = 0;
#endif
  
  {
      struct zx_dap_Select_s* e;
      for (e = x->Select; e; e = (struct zx_dap_Select_s*)e->gg.g.n)
	  len += zx_LEN_SO_dap_Select(c, e);
  }
  {
      struct zx_dap_NewData_s* e;
      for (e = x->NewData; e; e = (struct zx_dap_NewData_s*)e->gg.g.n)
	  len += zx_LEN_SO_dap_NewData(c, e);
  }


  len += zx_len_so_common(c, &x->gg);
  zx_pop_seen(pop_seen);
  ENC_LEN_DEBUG(x, "dap:ModifyItem", len);
  return len;
}

/* FUNC(zx_LEN_WO_dap_ModifyItem) */

/* Compute length of an element (and its subelements). The XML attributes
 * and elements are processed in wire order and no assumptions
 * are made about namespace prefixes. */

/* Called by: */
int zx_LEN_WO_dap_ModifyItem(struct zx_ctx* c, struct zx_dap_ModifyItem_s* x )
{
  struct zx_ns_s* pop_seen = 0;
  struct zx_elem_s* se MAYBE_UNUSED;
#if 1 /* NORMALMODE */
  int len = 1 + sizeof("ModifyItem")-1 + 1 + 2 + sizeof("ModifyItem")-1 + 1;
  
  if (x->gg.g.ns && x->gg.g.ns->prefix_len)
    len += (x->gg.g.ns->prefix_len + 1) * 2;
  if (c->inc_ns_len)
    len += zx_len_inc_ns(c, &pop_seen);
  len += zx_len_xmlns_if_not_seen(c, x->gg.g.ns, &pop_seen);
  if (x->itemID)
    len += zx_len_xmlns_if_not_seen(c, x->itemID->g.ns, &pop_seen);
  if (x->objectType)
    len += zx_len_xmlns_if_not_seen(c, x->objectType->g.ns, &pop_seen);
  if (x->predefined)
    len += zx_len_xmlns_if_not_seen(c, x->predefined->g.ns, &pop_seen);

  len += zx_attr_wo_len(x->id, sizeof("id")-1);
  len += zx_attr_wo_len(x->notChangedSince, sizeof("notChangedSince")-1);
  len += zx_attr_wo_len(x->overrideAllowed, sizeof("overrideAllowed")-1);
  len += zx_attr_wo_len(x->itemID, sizeof("itemID")-1);
  len += zx_attr_wo_len(x->objectType, sizeof("objectType")-1);
  len += zx_attr_wo_len(x->predefined, sizeof("predefined")-1);

#else
  /* root node has no begin tag */
  int len = 0;
#endif
  
  {
      struct zx_dap_Select_s* e;
      for (e = x->Select; e; e = (struct zx_dap_Select_s*)e->gg.g.n)
	  len += zx_LEN_WO_dap_Select(c, e);
  }
  {
      struct zx_dap_NewData_s* e;
      for (e = x->NewData; e; e = (struct zx_dap_NewData_s*)e->gg.g.n)
	  len += zx_LEN_WO_dap_NewData(c, e);
  }


  len += zx_len_wo_common(c, &x->gg); 
  zx_pop_seen(pop_seen);
  ENC_LEN_DEBUG(x, "dap:ModifyItem", len);
  return len;
}

/* FUNC(zx_ENC_SO_dap_ModifyItem) */

/* Render element into string. The XML attributes and elements are
 * processed in schema order. This is what you generally want for
 * rendering new data structure to a string. The wo pointers are not used. */

/* Called by: */
char* zx_ENC_SO_dap_ModifyItem(struct zx_ctx* c, struct zx_dap_ModifyItem_s* x, char* p )
{
  struct zx_elem_s* se MAYBE_UNUSED;
  ENC_LEN_DEBUG_BASE;
#if 1 /* NORMALMODE */
  struct zx_ns_s* pop_seen = 0;
  /* *** in simple_elem case should output ns prefix from ns node. */
  ZX_OUT_TAG(p, "<dap:ModifyItem");
  if (c->inc_ns)
    p = zx_enc_inc_ns(c, p, &pop_seen);
  p = zx_enc_xmlns_if_not_seen(c, p, zx_ns_tab+zx_xmlns_ix_dap, &pop_seen);
  if (x->itemID || x->objectType || x->predefined)
    p = zx_enc_xmlns_if_not_seen(c, p, zx_ns_tab+zx_xmlns_ix_dst, &pop_seen);

  p = zx_attr_so_enc(p, x->id, " id=\"", sizeof(" id=\"")-1);
  p = zx_attr_so_enc(p, x->notChangedSince, " notChangedSince=\"", sizeof(" notChangedSince=\"")-1);
  p = zx_attr_so_enc(p, x->overrideAllowed, " overrideAllowed=\"", sizeof(" overrideAllowed=\"")-1);
  p = zx_attr_so_enc(p, x->itemID, " dst:itemID=\"", sizeof(" dst:itemID=\"")-1);
  p = zx_attr_so_enc(p, x->objectType, " dst:objectType=\"", sizeof(" dst:objectType=\"")-1);
  p = zx_attr_so_enc(p, x->predefined, " dst:predefined=\"", sizeof(" dst:predefined=\"")-1);

  p = zx_enc_unknown_attrs(p, x->gg.any_attr);
#else
  /* root node has no begin tag */
#endif
  
  {
      struct zx_dap_Select_s* e;
      for (e = x->Select; e; e = (struct zx_dap_Select_s*)e->gg.g.n)
	  p = zx_ENC_SO_dap_Select(c, e, p);
  }
  {
      struct zx_dap_NewData_s* e;
      for (e = x->NewData; e; e = (struct zx_dap_NewData_s*)e->gg.g.n)
	  p = zx_ENC_SO_dap_NewData(c, e, p);
  }

  p = zx_enc_so_unknown_elems_and_content(c, p, &x->gg);
  
#if 1 /* NORMALMODE */
  ZX_OUT_CLOSE_TAG(p, "</dap:ModifyItem>");
  zx_pop_seen(pop_seen);
#else
  /* root node has no end tag either */
#endif
  ENC_LEN_DEBUG(x, "dap:ModifyItem", p-enc_base);
  return p;
}

/* FUNC(zx_ENC_WO_dap_ModifyItem) */

/* Render element into string. The XML attributes and elements are
 * processed in wire order by chasing wo pointers. This is what you want for
 * validating signatures on other people's XML documents. */

/* Called by: */
char* zx_ENC_WO_dap_ModifyItem(struct zx_ctx* c, struct zx_dap_ModifyItem_s* x, char* p )
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
  ZX_OUT_MEM(p, "ModifyItem", sizeof("ModifyItem")-1);
  qq = p;

  /* *** sort the namespaces */
  if (c->inc_ns)
    zx_add_inc_ns(c, &pop_seen);
  zx_add_xmlns_if_not_seen(c, x->gg.g.ns, &pop_seen);
  if (x->itemID)
    zx_add_xmlns_if_not_seen(c, x->itemID->g.ns, &pop_seen);
  if (x->objectType)
    zx_add_xmlns_if_not_seen(c, x->objectType->g.ns, &pop_seen);
  if (x->predefined)
    zx_add_xmlns_if_not_seen(c, x->predefined->g.ns, &pop_seen);

  p = zx_enc_seen(p, pop_seen); 
  p = zx_attr_wo_enc(p, x->id, "id=\"", sizeof("id=\"")-1);
  p = zx_attr_wo_enc(p, x->notChangedSince, "notChangedSince=\"", sizeof("notChangedSince=\"")-1);
  p = zx_attr_wo_enc(p, x->overrideAllowed, "overrideAllowed=\"", sizeof("overrideAllowed=\"")-1);
  p = zx_attr_wo_enc(p, x->itemID, "itemID=\"", sizeof("itemID=\"")-1);
  p = zx_attr_wo_enc(p, x->objectType, "objectType=\"", sizeof("objectType=\"")-1);
  p = zx_attr_wo_enc(p, x->predefined, "predefined=\"", sizeof("predefined=\"")-1);

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
  ENC_LEN_DEBUG(x, "dap:ModifyItem", p-enc_base);
  return p;
}

/* FUNC(zx_EASY_ENC_SO_dap_ModifyItem) */

/* Called by: */
struct zx_str* zx_EASY_ENC_SO_dap_ModifyItem(struct zx_ctx* c, struct zx_dap_ModifyItem_s* x )
{
  int len;
  char* buf;
  c->ns_tab = ZX_ALLOC(c, sizeof(zx_ns_tab));
  memcpy(c->ns_tab, zx_ns_tab, sizeof(zx_ns_tab));
  len = zx_LEN_SO_dap_ModifyItem(c, x );
  buf = ZX_ALLOC(c, len+1);
  return zx_easy_enc_common(c, zx_ENC_SO_dap_ModifyItem(c, x, buf ), buf, len);
}

/* FUNC(zx_EASY_ENC_WO_dap_ModifyItem) */

/* Called by: */
struct zx_str* zx_EASY_ENC_WO_dap_ModifyItem(struct zx_ctx* c, struct zx_dap_ModifyItem_s* x )
{
  int len;
  char* buf;
  c->ns_tab = ZX_ALLOC(c, sizeof(zx_ns_tab));
  memcpy(c->ns_tab, zx_ns_tab, sizeof(zx_ns_tab));
  len = zx_LEN_WO_dap_ModifyItem(c, x );
  buf = ZX_ALLOC(c, len+1);
  return zx_easy_enc_common(c, zx_ENC_WO_dap_ModifyItem(c, x, buf ), buf, len);
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

#define EL_NAME   dap_ModifyResponse
#define EL_STRUCT zx_dap_ModifyResponse_s
#define EL_NS     dap
#define EL_TAG    ModifyResponse

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

/* FUNC(zx_LEN_SO_dap_ModifyResponse) */

/* Compute length of an element (and its subelements). The XML attributes
 * and elements are processed in schema order. */

/* Called by: */
int zx_LEN_SO_dap_ModifyResponse(struct zx_ctx* c, struct zx_dap_ModifyResponse_s* x )
{
  struct zx_ns_s* pop_seen = 0;
  struct zx_elem_s* se MAYBE_UNUSED;
#if 1 /* NORMALMODE */
  /* *** in simple_elem case should output ns prefix from ns node. */
  int len = sizeof("<dap:ModifyResponse")-1 + 1 + sizeof("</dap:ModifyResponse>")-1;
  if (c->inc_ns_len)
    len += zx_len_inc_ns(c, &pop_seen);
  len += zx_len_xmlns_if_not_seen(c, zx_ns_tab+zx_xmlns_ix_dap, &pop_seen);
  if (x->itemIDRef)
    len += zx_len_xmlns_if_not_seen(c, zx_ns_tab+zx_xmlns_ix_dst, &pop_seen);

  len += zx_attr_so_len(x->timeStamp, sizeof("timeStamp")-1);
  len += zx_attr_so_len(x->itemIDRef, sizeof("dst:itemIDRef")-1);

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
      struct zx_lu_Extension_s* e;
      for (e = x->Extension; e; e = (struct zx_lu_Extension_s*)e->gg.g.n)
	  len += zx_LEN_SO_lu_Extension(c, e);
  }
  {
      struct zx_dap_ItemData_s* e;
      for (e = x->ItemData; e; e = (struct zx_dap_ItemData_s*)e->gg.g.n)
	  len += zx_LEN_SO_dap_ItemData(c, e);
  }


  len += zx_len_so_common(c, &x->gg);
  zx_pop_seen(pop_seen);
  ENC_LEN_DEBUG(x, "dap:ModifyResponse", len);
  return len;
}

/* FUNC(zx_LEN_WO_dap_ModifyResponse) */

/* Compute length of an element (and its subelements). The XML attributes
 * and elements are processed in wire order and no assumptions
 * are made about namespace prefixes. */

/* Called by: */
int zx_LEN_WO_dap_ModifyResponse(struct zx_ctx* c, struct zx_dap_ModifyResponse_s* x )
{
  struct zx_ns_s* pop_seen = 0;
  struct zx_elem_s* se MAYBE_UNUSED;
#if 1 /* NORMALMODE */
  int len = 1 + sizeof("ModifyResponse")-1 + 1 + 2 + sizeof("ModifyResponse")-1 + 1;
  
  if (x->gg.g.ns && x->gg.g.ns->prefix_len)
    len += (x->gg.g.ns->prefix_len + 1) * 2;
  if (c->inc_ns_len)
    len += zx_len_inc_ns(c, &pop_seen);
  len += zx_len_xmlns_if_not_seen(c, x->gg.g.ns, &pop_seen);
  if (x->itemIDRef)
    len += zx_len_xmlns_if_not_seen(c, x->itemIDRef->g.ns, &pop_seen);

  len += zx_attr_wo_len(x->timeStamp, sizeof("timeStamp")-1);
  len += zx_attr_wo_len(x->itemIDRef, sizeof("itemIDRef")-1);

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
      struct zx_lu_Extension_s* e;
      for (e = x->Extension; e; e = (struct zx_lu_Extension_s*)e->gg.g.n)
	  len += zx_LEN_WO_lu_Extension(c, e);
  }
  {
      struct zx_dap_ItemData_s* e;
      for (e = x->ItemData; e; e = (struct zx_dap_ItemData_s*)e->gg.g.n)
	  len += zx_LEN_WO_dap_ItemData(c, e);
  }


  len += zx_len_wo_common(c, &x->gg); 
  zx_pop_seen(pop_seen);
  ENC_LEN_DEBUG(x, "dap:ModifyResponse", len);
  return len;
}

/* FUNC(zx_ENC_SO_dap_ModifyResponse) */

/* Render element into string. The XML attributes and elements are
 * processed in schema order. This is what you generally want for
 * rendering new data structure to a string. The wo pointers are not used. */

/* Called by: */
char* zx_ENC_SO_dap_ModifyResponse(struct zx_ctx* c, struct zx_dap_ModifyResponse_s* x, char* p )
{
  struct zx_elem_s* se MAYBE_UNUSED;
  ENC_LEN_DEBUG_BASE;
#if 1 /* NORMALMODE */
  struct zx_ns_s* pop_seen = 0;
  /* *** in simple_elem case should output ns prefix from ns node. */
  ZX_OUT_TAG(p, "<dap:ModifyResponse");
  if (c->inc_ns)
    p = zx_enc_inc_ns(c, p, &pop_seen);
  p = zx_enc_xmlns_if_not_seen(c, p, zx_ns_tab+zx_xmlns_ix_dap, &pop_seen);
  if (x->itemIDRef)
    p = zx_enc_xmlns_if_not_seen(c, p, zx_ns_tab+zx_xmlns_ix_dst, &pop_seen);

  p = zx_attr_so_enc(p, x->timeStamp, " timeStamp=\"", sizeof(" timeStamp=\"")-1);
  p = zx_attr_so_enc(p, x->itemIDRef, " dst:itemIDRef=\"", sizeof(" dst:itemIDRef=\"")-1);

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
      struct zx_lu_Extension_s* e;
      for (e = x->Extension; e; e = (struct zx_lu_Extension_s*)e->gg.g.n)
	  p = zx_ENC_SO_lu_Extension(c, e, p);
  }
  {
      struct zx_dap_ItemData_s* e;
      for (e = x->ItemData; e; e = (struct zx_dap_ItemData_s*)e->gg.g.n)
	  p = zx_ENC_SO_dap_ItemData(c, e, p);
  }

  p = zx_enc_so_unknown_elems_and_content(c, p, &x->gg);
  
#if 1 /* NORMALMODE */
  ZX_OUT_CLOSE_TAG(p, "</dap:ModifyResponse>");
  zx_pop_seen(pop_seen);
#else
  /* root node has no end tag either */
#endif
  ENC_LEN_DEBUG(x, "dap:ModifyResponse", p-enc_base);
  return p;
}

/* FUNC(zx_ENC_WO_dap_ModifyResponse) */

/* Render element into string. The XML attributes and elements are
 * processed in wire order by chasing wo pointers. This is what you want for
 * validating signatures on other people's XML documents. */

/* Called by: */
char* zx_ENC_WO_dap_ModifyResponse(struct zx_ctx* c, struct zx_dap_ModifyResponse_s* x, char* p )
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
  ZX_OUT_MEM(p, "ModifyResponse", sizeof("ModifyResponse")-1);
  qq = p;

  /* *** sort the namespaces */
  if (c->inc_ns)
    zx_add_inc_ns(c, &pop_seen);
  zx_add_xmlns_if_not_seen(c, x->gg.g.ns, &pop_seen);
  if (x->itemIDRef)
    zx_add_xmlns_if_not_seen(c, x->itemIDRef->g.ns, &pop_seen);

  p = zx_enc_seen(p, pop_seen); 
  p = zx_attr_wo_enc(p, x->timeStamp, "timeStamp=\"", sizeof("timeStamp=\"")-1);
  p = zx_attr_wo_enc(p, x->itemIDRef, "itemIDRef=\"", sizeof("itemIDRef=\"")-1);

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
  ENC_LEN_DEBUG(x, "dap:ModifyResponse", p-enc_base);
  return p;
}

/* FUNC(zx_EASY_ENC_SO_dap_ModifyResponse) */

/* Called by: */
struct zx_str* zx_EASY_ENC_SO_dap_ModifyResponse(struct zx_ctx* c, struct zx_dap_ModifyResponse_s* x )
{
  int len;
  char* buf;
  c->ns_tab = ZX_ALLOC(c, sizeof(zx_ns_tab));
  memcpy(c->ns_tab, zx_ns_tab, sizeof(zx_ns_tab));
  len = zx_LEN_SO_dap_ModifyResponse(c, x );
  buf = ZX_ALLOC(c, len+1);
  return zx_easy_enc_common(c, zx_ENC_SO_dap_ModifyResponse(c, x, buf ), buf, len);
}

/* FUNC(zx_EASY_ENC_WO_dap_ModifyResponse) */

/* Called by: */
struct zx_str* zx_EASY_ENC_WO_dap_ModifyResponse(struct zx_ctx* c, struct zx_dap_ModifyResponse_s* x )
{
  int len;
  char* buf;
  c->ns_tab = ZX_ALLOC(c, sizeof(zx_ns_tab));
  memcpy(c->ns_tab, zx_ns_tab, sizeof(zx_ns_tab));
  len = zx_LEN_WO_dap_ModifyResponse(c, x );
  buf = ZX_ALLOC(c, len+1);
  return zx_easy_enc_common(c, zx_ENC_WO_dap_ModifyResponse(c, x, buf ), buf, len);
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

#define EL_NAME   dap_NewData
#define EL_STRUCT zx_dap_NewData_s
#define EL_NS     dap
#define EL_TAG    NewData

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

/* FUNC(zx_LEN_SO_dap_NewData) */

/* Compute length of an element (and its subelements). The XML attributes
 * and elements are processed in schema order. */

/* Called by: */
int zx_LEN_SO_dap_NewData(struct zx_ctx* c, struct zx_dap_NewData_s* x )
{
  struct zx_ns_s* pop_seen = 0;
  struct zx_elem_s* se MAYBE_UNUSED;
#if 1 /* NORMALMODE */
  /* *** in simple_elem case should output ns prefix from ns node. */
  int len = sizeof("<dap:NewData")-1 + 1 + sizeof("</dap:NewData>")-1;
  if (c->inc_ns_len)
    len += zx_len_inc_ns(c, &pop_seen);
  len += zx_len_xmlns_if_not_seen(c, zx_ns_tab+zx_xmlns_ix_dap, &pop_seen);


#else
  /* root node has no begin tag */
  int len = 0;
#endif
  
  {
      struct zx_dap_LDIF_s* e;
      for (e = x->LDIF; e; e = (struct zx_dap_LDIF_s*)e->gg.g.n)
	  len += zx_LEN_SO_dap_LDIF(c, e);
  }
  {
      struct zx_dap_Subscription_s* e;
      for (e = x->Subscription; e; e = (struct zx_dap_Subscription_s*)e->gg.g.n)
	  len += zx_LEN_SO_dap_Subscription(c, e);
  }


  len += zx_len_so_common(c, &x->gg);
  zx_pop_seen(pop_seen);
  ENC_LEN_DEBUG(x, "dap:NewData", len);
  return len;
}

/* FUNC(zx_LEN_WO_dap_NewData) */

/* Compute length of an element (and its subelements). The XML attributes
 * and elements are processed in wire order and no assumptions
 * are made about namespace prefixes. */

/* Called by: */
int zx_LEN_WO_dap_NewData(struct zx_ctx* c, struct zx_dap_NewData_s* x )
{
  struct zx_ns_s* pop_seen = 0;
  struct zx_elem_s* se MAYBE_UNUSED;
#if 1 /* NORMALMODE */
  int len = 1 + sizeof("NewData")-1 + 1 + 2 + sizeof("NewData")-1 + 1;
  
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
      struct zx_dap_LDIF_s* e;
      for (e = x->LDIF; e; e = (struct zx_dap_LDIF_s*)e->gg.g.n)
	  len += zx_LEN_WO_dap_LDIF(c, e);
  }
  {
      struct zx_dap_Subscription_s* e;
      for (e = x->Subscription; e; e = (struct zx_dap_Subscription_s*)e->gg.g.n)
	  len += zx_LEN_WO_dap_Subscription(c, e);
  }


  len += zx_len_wo_common(c, &x->gg); 
  zx_pop_seen(pop_seen);
  ENC_LEN_DEBUG(x, "dap:NewData", len);
  return len;
}

/* FUNC(zx_ENC_SO_dap_NewData) */

/* Render element into string. The XML attributes and elements are
 * processed in schema order. This is what you generally want for
 * rendering new data structure to a string. The wo pointers are not used. */

/* Called by: */
char* zx_ENC_SO_dap_NewData(struct zx_ctx* c, struct zx_dap_NewData_s* x, char* p )
{
  struct zx_elem_s* se MAYBE_UNUSED;
  ENC_LEN_DEBUG_BASE;
#if 1 /* NORMALMODE */
  struct zx_ns_s* pop_seen = 0;
  /* *** in simple_elem case should output ns prefix from ns node. */
  ZX_OUT_TAG(p, "<dap:NewData");
  if (c->inc_ns)
    p = zx_enc_inc_ns(c, p, &pop_seen);
  p = zx_enc_xmlns_if_not_seen(c, p, zx_ns_tab+zx_xmlns_ix_dap, &pop_seen);


  p = zx_enc_unknown_attrs(p, x->gg.any_attr);
#else
  /* root node has no begin tag */
#endif
  
  {
      struct zx_dap_LDIF_s* e;
      for (e = x->LDIF; e; e = (struct zx_dap_LDIF_s*)e->gg.g.n)
	  p = zx_ENC_SO_dap_LDIF(c, e, p);
  }
  {
      struct zx_dap_Subscription_s* e;
      for (e = x->Subscription; e; e = (struct zx_dap_Subscription_s*)e->gg.g.n)
	  p = zx_ENC_SO_dap_Subscription(c, e, p);
  }

  p = zx_enc_so_unknown_elems_and_content(c, p, &x->gg);
  
#if 1 /* NORMALMODE */
  ZX_OUT_CLOSE_TAG(p, "</dap:NewData>");
  zx_pop_seen(pop_seen);
#else
  /* root node has no end tag either */
#endif
  ENC_LEN_DEBUG(x, "dap:NewData", p-enc_base);
  return p;
}

/* FUNC(zx_ENC_WO_dap_NewData) */

/* Render element into string. The XML attributes and elements are
 * processed in wire order by chasing wo pointers. This is what you want for
 * validating signatures on other people's XML documents. */

/* Called by: */
char* zx_ENC_WO_dap_NewData(struct zx_ctx* c, struct zx_dap_NewData_s* x, char* p )
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
  ZX_OUT_MEM(p, "NewData", sizeof("NewData")-1);
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
  ENC_LEN_DEBUG(x, "dap:NewData", p-enc_base);
  return p;
}

/* FUNC(zx_EASY_ENC_SO_dap_NewData) */

/* Called by: */
struct zx_str* zx_EASY_ENC_SO_dap_NewData(struct zx_ctx* c, struct zx_dap_NewData_s* x )
{
  int len;
  char* buf;
  c->ns_tab = ZX_ALLOC(c, sizeof(zx_ns_tab));
  memcpy(c->ns_tab, zx_ns_tab, sizeof(zx_ns_tab));
  len = zx_LEN_SO_dap_NewData(c, x );
  buf = ZX_ALLOC(c, len+1);
  return zx_easy_enc_common(c, zx_ENC_SO_dap_NewData(c, x, buf ), buf, len);
}

/* FUNC(zx_EASY_ENC_WO_dap_NewData) */

/* Called by: */
struct zx_str* zx_EASY_ENC_WO_dap_NewData(struct zx_ctx* c, struct zx_dap_NewData_s* x )
{
  int len;
  char* buf;
  c->ns_tab = ZX_ALLOC(c, sizeof(zx_ns_tab));
  memcpy(c->ns_tab, zx_ns_tab, sizeof(zx_ns_tab));
  len = zx_LEN_WO_dap_NewData(c, x );
  buf = ZX_ALLOC(c, len+1);
  return zx_easy_enc_common(c, zx_ENC_WO_dap_NewData(c, x, buf ), buf, len);
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

#define EL_NAME   dap_Notification
#define EL_STRUCT zx_dap_Notification_s
#define EL_NS     dap
#define EL_TAG    Notification

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

/* FUNC(zx_LEN_SO_dap_Notification) */

/* Compute length of an element (and its subelements). The XML attributes
 * and elements are processed in schema order. */

/* Called by: */
int zx_LEN_SO_dap_Notification(struct zx_ctx* c, struct zx_dap_Notification_s* x )
{
  struct zx_ns_s* pop_seen = 0;
  struct zx_elem_s* se MAYBE_UNUSED;
#if 1 /* NORMALMODE */
  /* *** in simple_elem case should output ns prefix from ns node. */
  int len = sizeof("<dap:Notification")-1 + 1 + sizeof("</dap:Notification>")-1;
  if (c->inc_ns_len)
    len += zx_len_inc_ns(c, &pop_seen);
  len += zx_len_xmlns_if_not_seen(c, zx_ns_tab+zx_xmlns_ix_dap, &pop_seen);

  len += zx_attr_so_len(x->endReason, sizeof("endReason")-1);
  len += zx_attr_so_len(x->expires, sizeof("expires")-1);
  len += zx_attr_so_len(x->id, sizeof("id")-1);
  len += zx_attr_so_len(x->subscriptionID, sizeof("subscriptionID")-1);

#else
  /* root node has no begin tag */
  int len = 0;
#endif
  
  {
      struct zx_lu_TestResult_s* e;
      for (e = x->TestResult; e; e = (struct zx_lu_TestResult_s*)e->gg.g.n)
	  len += zx_LEN_SO_lu_TestResult(c, e);
  }
  {
      struct zx_dap_ItemData_s* e;
      for (e = x->ItemData; e; e = (struct zx_dap_ItemData_s*)e->gg.g.n)
	  len += zx_LEN_SO_dap_ItemData(c, e);
  }


  len += zx_len_so_common(c, &x->gg);
  zx_pop_seen(pop_seen);
  ENC_LEN_DEBUG(x, "dap:Notification", len);
  return len;
}

/* FUNC(zx_LEN_WO_dap_Notification) */

/* Compute length of an element (and its subelements). The XML attributes
 * and elements are processed in wire order and no assumptions
 * are made about namespace prefixes. */

/* Called by: */
int zx_LEN_WO_dap_Notification(struct zx_ctx* c, struct zx_dap_Notification_s* x )
{
  struct zx_ns_s* pop_seen = 0;
  struct zx_elem_s* se MAYBE_UNUSED;
#if 1 /* NORMALMODE */
  int len = 1 + sizeof("Notification")-1 + 1 + 2 + sizeof("Notification")-1 + 1;
  
  if (x->gg.g.ns && x->gg.g.ns->prefix_len)
    len += (x->gg.g.ns->prefix_len + 1) * 2;
  if (c->inc_ns_len)
    len += zx_len_inc_ns(c, &pop_seen);
  len += zx_len_xmlns_if_not_seen(c, x->gg.g.ns, &pop_seen);

  len += zx_attr_wo_len(x->endReason, sizeof("endReason")-1);
  len += zx_attr_wo_len(x->expires, sizeof("expires")-1);
  len += zx_attr_wo_len(x->id, sizeof("id")-1);
  len += zx_attr_wo_len(x->subscriptionID, sizeof("subscriptionID")-1);

#else
  /* root node has no begin tag */
  int len = 0;
#endif
  
  {
      struct zx_lu_TestResult_s* e;
      for (e = x->TestResult; e; e = (struct zx_lu_TestResult_s*)e->gg.g.n)
	  len += zx_LEN_WO_lu_TestResult(c, e);
  }
  {
      struct zx_dap_ItemData_s* e;
      for (e = x->ItemData; e; e = (struct zx_dap_ItemData_s*)e->gg.g.n)
	  len += zx_LEN_WO_dap_ItemData(c, e);
  }


  len += zx_len_wo_common(c, &x->gg); 
  zx_pop_seen(pop_seen);
  ENC_LEN_DEBUG(x, "dap:Notification", len);
  return len;
}

/* FUNC(zx_ENC_SO_dap_Notification) */

/* Render element into string. The XML attributes and elements are
 * processed in schema order. This is what you generally want for
 * rendering new data structure to a string. The wo pointers are not used. */

/* Called by: */
char* zx_ENC_SO_dap_Notification(struct zx_ctx* c, struct zx_dap_Notification_s* x, char* p )
{
  struct zx_elem_s* se MAYBE_UNUSED;
  ENC_LEN_DEBUG_BASE;
#if 1 /* NORMALMODE */
  struct zx_ns_s* pop_seen = 0;
  /* *** in simple_elem case should output ns prefix from ns node. */
  ZX_OUT_TAG(p, "<dap:Notification");
  if (c->inc_ns)
    p = zx_enc_inc_ns(c, p, &pop_seen);
  p = zx_enc_xmlns_if_not_seen(c, p, zx_ns_tab+zx_xmlns_ix_dap, &pop_seen);

  p = zx_attr_so_enc(p, x->endReason, " endReason=\"", sizeof(" endReason=\"")-1);
  p = zx_attr_so_enc(p, x->expires, " expires=\"", sizeof(" expires=\"")-1);
  p = zx_attr_so_enc(p, x->id, " id=\"", sizeof(" id=\"")-1);
  p = zx_attr_so_enc(p, x->subscriptionID, " subscriptionID=\"", sizeof(" subscriptionID=\"")-1);

  p = zx_enc_unknown_attrs(p, x->gg.any_attr);
#else
  /* root node has no begin tag */
#endif
  
  {
      struct zx_lu_TestResult_s* e;
      for (e = x->TestResult; e; e = (struct zx_lu_TestResult_s*)e->gg.g.n)
	  p = zx_ENC_SO_lu_TestResult(c, e, p);
  }
  {
      struct zx_dap_ItemData_s* e;
      for (e = x->ItemData; e; e = (struct zx_dap_ItemData_s*)e->gg.g.n)
	  p = zx_ENC_SO_dap_ItemData(c, e, p);
  }

  p = zx_enc_so_unknown_elems_and_content(c, p, &x->gg);
  
#if 1 /* NORMALMODE */
  ZX_OUT_CLOSE_TAG(p, "</dap:Notification>");
  zx_pop_seen(pop_seen);
#else
  /* root node has no end tag either */
#endif
  ENC_LEN_DEBUG(x, "dap:Notification", p-enc_base);
  return p;
}

/* FUNC(zx_ENC_WO_dap_Notification) */

/* Render element into string. The XML attributes and elements are
 * processed in wire order by chasing wo pointers. This is what you want for
 * validating signatures on other people's XML documents. */

/* Called by: */
char* zx_ENC_WO_dap_Notification(struct zx_ctx* c, struct zx_dap_Notification_s* x, char* p )
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
  ZX_OUT_MEM(p, "Notification", sizeof("Notification")-1);
  qq = p;

  /* *** sort the namespaces */
  if (c->inc_ns)
    zx_add_inc_ns(c, &pop_seen);
  zx_add_xmlns_if_not_seen(c, x->gg.g.ns, &pop_seen);

  p = zx_enc_seen(p, pop_seen); 
  p = zx_attr_wo_enc(p, x->endReason, "endReason=\"", sizeof("endReason=\"")-1);
  p = zx_attr_wo_enc(p, x->expires, "expires=\"", sizeof("expires=\"")-1);
  p = zx_attr_wo_enc(p, x->id, "id=\"", sizeof("id=\"")-1);
  p = zx_attr_wo_enc(p, x->subscriptionID, "subscriptionID=\"", sizeof("subscriptionID=\"")-1);

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
  ENC_LEN_DEBUG(x, "dap:Notification", p-enc_base);
  return p;
}

/* FUNC(zx_EASY_ENC_SO_dap_Notification) */

/* Called by: */
struct zx_str* zx_EASY_ENC_SO_dap_Notification(struct zx_ctx* c, struct zx_dap_Notification_s* x )
{
  int len;
  char* buf;
  c->ns_tab = ZX_ALLOC(c, sizeof(zx_ns_tab));
  memcpy(c->ns_tab, zx_ns_tab, sizeof(zx_ns_tab));
  len = zx_LEN_SO_dap_Notification(c, x );
  buf = ZX_ALLOC(c, len+1);
  return zx_easy_enc_common(c, zx_ENC_SO_dap_Notification(c, x, buf ), buf, len);
}

/* FUNC(zx_EASY_ENC_WO_dap_Notification) */

/* Called by: */
struct zx_str* zx_EASY_ENC_WO_dap_Notification(struct zx_ctx* c, struct zx_dap_Notification_s* x )
{
  int len;
  char* buf;
  c->ns_tab = ZX_ALLOC(c, sizeof(zx_ns_tab));
  memcpy(c->ns_tab, zx_ns_tab, sizeof(zx_ns_tab));
  len = zx_LEN_WO_dap_Notification(c, x );
  buf = ZX_ALLOC(c, len+1);
  return zx_easy_enc_common(c, zx_ENC_WO_dap_Notification(c, x, buf ), buf, len);
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

#define EL_NAME   dap_Notify
#define EL_STRUCT zx_dap_Notify_s
#define EL_NS     dap
#define EL_TAG    Notify

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

/* FUNC(zx_LEN_SO_dap_Notify) */

/* Compute length of an element (and its subelements). The XML attributes
 * and elements are processed in schema order. */

/* Called by: */
int zx_LEN_SO_dap_Notify(struct zx_ctx* c, struct zx_dap_Notify_s* x )
{
  struct zx_ns_s* pop_seen = 0;
  struct zx_elem_s* se MAYBE_UNUSED;
#if 1 /* NORMALMODE */
  /* *** in simple_elem case should output ns prefix from ns node. */
  int len = sizeof("<dap:Notify")-1 + 1 + sizeof("</dap:Notify>")-1;
  if (c->inc_ns_len)
    len += zx_len_inc_ns(c, &pop_seen);
  len += zx_len_xmlns_if_not_seen(c, zx_ns_tab+zx_xmlns_ix_dap, &pop_seen);
  if (x->itemID)
    len += zx_len_xmlns_if_not_seen(c, zx_ns_tab+zx_xmlns_ix_dst, &pop_seen);

  len += zx_attr_so_len(x->timeStamp, sizeof("timeStamp")-1);
  len += zx_attr_so_len(x->itemID, sizeof("dst:itemID")-1);

#else
  /* root node has no begin tag */
  int len = 0;
#endif
  
  {
      struct zx_lu_Extension_s* e;
      for (e = x->Extension; e; e = (struct zx_lu_Extension_s*)e->gg.g.n)
	  len += zx_LEN_SO_lu_Extension(c, e);
  }
  {
      struct zx_dap_Notification_s* e;
      for (e = x->Notification; e; e = (struct zx_dap_Notification_s*)e->gg.g.n)
	  len += zx_LEN_SO_dap_Notification(c, e);
  }


  len += zx_len_so_common(c, &x->gg);
  zx_pop_seen(pop_seen);
  ENC_LEN_DEBUG(x, "dap:Notify", len);
  return len;
}

/* FUNC(zx_LEN_WO_dap_Notify) */

/* Compute length of an element (and its subelements). The XML attributes
 * and elements are processed in wire order and no assumptions
 * are made about namespace prefixes. */

/* Called by: */
int zx_LEN_WO_dap_Notify(struct zx_ctx* c, struct zx_dap_Notify_s* x )
{
  struct zx_ns_s* pop_seen = 0;
  struct zx_elem_s* se MAYBE_UNUSED;
#if 1 /* NORMALMODE */
  int len = 1 + sizeof("Notify")-1 + 1 + 2 + sizeof("Notify")-1 + 1;
  
  if (x->gg.g.ns && x->gg.g.ns->prefix_len)
    len += (x->gg.g.ns->prefix_len + 1) * 2;
  if (c->inc_ns_len)
    len += zx_len_inc_ns(c, &pop_seen);
  len += zx_len_xmlns_if_not_seen(c, x->gg.g.ns, &pop_seen);
  if (x->itemID)
    len += zx_len_xmlns_if_not_seen(c, x->itemID->g.ns, &pop_seen);

  len += zx_attr_wo_len(x->timeStamp, sizeof("timeStamp")-1);
  len += zx_attr_wo_len(x->itemID, sizeof("itemID")-1);

#else
  /* root node has no begin tag */
  int len = 0;
#endif
  
  {
      struct zx_lu_Extension_s* e;
      for (e = x->Extension; e; e = (struct zx_lu_Extension_s*)e->gg.g.n)
	  len += zx_LEN_WO_lu_Extension(c, e);
  }
  {
      struct zx_dap_Notification_s* e;
      for (e = x->Notification; e; e = (struct zx_dap_Notification_s*)e->gg.g.n)
	  len += zx_LEN_WO_dap_Notification(c, e);
  }


  len += zx_len_wo_common(c, &x->gg); 
  zx_pop_seen(pop_seen);
  ENC_LEN_DEBUG(x, "dap:Notify", len);
  return len;
}

/* FUNC(zx_ENC_SO_dap_Notify) */

/* Render element into string. The XML attributes and elements are
 * processed in schema order. This is what you generally want for
 * rendering new data structure to a string. The wo pointers are not used. */

/* Called by: */
char* zx_ENC_SO_dap_Notify(struct zx_ctx* c, struct zx_dap_Notify_s* x, char* p )
{
  struct zx_elem_s* se MAYBE_UNUSED;
  ENC_LEN_DEBUG_BASE;
#if 1 /* NORMALMODE */
  struct zx_ns_s* pop_seen = 0;
  /* *** in simple_elem case should output ns prefix from ns node. */
  ZX_OUT_TAG(p, "<dap:Notify");
  if (c->inc_ns)
    p = zx_enc_inc_ns(c, p, &pop_seen);
  p = zx_enc_xmlns_if_not_seen(c, p, zx_ns_tab+zx_xmlns_ix_dap, &pop_seen);
  if (x->itemID)
    p = zx_enc_xmlns_if_not_seen(c, p, zx_ns_tab+zx_xmlns_ix_dst, &pop_seen);

  p = zx_attr_so_enc(p, x->timeStamp, " timeStamp=\"", sizeof(" timeStamp=\"")-1);
  p = zx_attr_so_enc(p, x->itemID, " dst:itemID=\"", sizeof(" dst:itemID=\"")-1);

  p = zx_enc_unknown_attrs(p, x->gg.any_attr);
#else
  /* root node has no begin tag */
#endif
  
  {
      struct zx_lu_Extension_s* e;
      for (e = x->Extension; e; e = (struct zx_lu_Extension_s*)e->gg.g.n)
	  p = zx_ENC_SO_lu_Extension(c, e, p);
  }
  {
      struct zx_dap_Notification_s* e;
      for (e = x->Notification; e; e = (struct zx_dap_Notification_s*)e->gg.g.n)
	  p = zx_ENC_SO_dap_Notification(c, e, p);
  }

  p = zx_enc_so_unknown_elems_and_content(c, p, &x->gg);
  
#if 1 /* NORMALMODE */
  ZX_OUT_CLOSE_TAG(p, "</dap:Notify>");
  zx_pop_seen(pop_seen);
#else
  /* root node has no end tag either */
#endif
  ENC_LEN_DEBUG(x, "dap:Notify", p-enc_base);
  return p;
}

/* FUNC(zx_ENC_WO_dap_Notify) */

/* Render element into string. The XML attributes and elements are
 * processed in wire order by chasing wo pointers. This is what you want for
 * validating signatures on other people's XML documents. */

/* Called by: */
char* zx_ENC_WO_dap_Notify(struct zx_ctx* c, struct zx_dap_Notify_s* x, char* p )
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
  ZX_OUT_MEM(p, "Notify", sizeof("Notify")-1);
  qq = p;

  /* *** sort the namespaces */
  if (c->inc_ns)
    zx_add_inc_ns(c, &pop_seen);
  zx_add_xmlns_if_not_seen(c, x->gg.g.ns, &pop_seen);
  if (x->itemID)
    zx_add_xmlns_if_not_seen(c, x->itemID->g.ns, &pop_seen);

  p = zx_enc_seen(p, pop_seen); 
  p = zx_attr_wo_enc(p, x->timeStamp, "timeStamp=\"", sizeof("timeStamp=\"")-1);
  p = zx_attr_wo_enc(p, x->itemID, "itemID=\"", sizeof("itemID=\"")-1);

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
  ENC_LEN_DEBUG(x, "dap:Notify", p-enc_base);
  return p;
}

/* FUNC(zx_EASY_ENC_SO_dap_Notify) */

/* Called by: */
struct zx_str* zx_EASY_ENC_SO_dap_Notify(struct zx_ctx* c, struct zx_dap_Notify_s* x )
{
  int len;
  char* buf;
  c->ns_tab = ZX_ALLOC(c, sizeof(zx_ns_tab));
  memcpy(c->ns_tab, zx_ns_tab, sizeof(zx_ns_tab));
  len = zx_LEN_SO_dap_Notify(c, x );
  buf = ZX_ALLOC(c, len+1);
  return zx_easy_enc_common(c, zx_ENC_SO_dap_Notify(c, x, buf ), buf, len);
}

/* FUNC(zx_EASY_ENC_WO_dap_Notify) */

/* Called by: */
struct zx_str* zx_EASY_ENC_WO_dap_Notify(struct zx_ctx* c, struct zx_dap_Notify_s* x )
{
  int len;
  char* buf;
  c->ns_tab = ZX_ALLOC(c, sizeof(zx_ns_tab));
  memcpy(c->ns_tab, zx_ns_tab, sizeof(zx_ns_tab));
  len = zx_LEN_WO_dap_Notify(c, x );
  buf = ZX_ALLOC(c, len+1);
  return zx_easy_enc_common(c, zx_ENC_WO_dap_Notify(c, x, buf ), buf, len);
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

#define EL_NAME   dap_NotifyResponse
#define EL_STRUCT zx_dap_NotifyResponse_s
#define EL_NS     dap
#define EL_TAG    NotifyResponse

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

/* FUNC(zx_LEN_SO_dap_NotifyResponse) */

/* Compute length of an element (and its subelements). The XML attributes
 * and elements are processed in schema order. */

/* Called by: */
int zx_LEN_SO_dap_NotifyResponse(struct zx_ctx* c, struct zx_dap_NotifyResponse_s* x )
{
  struct zx_ns_s* pop_seen = 0;
  struct zx_elem_s* se MAYBE_UNUSED;
#if 1 /* NORMALMODE */
  /* *** in simple_elem case should output ns prefix from ns node. */
  int len = sizeof("<dap:NotifyResponse")-1 + 1 + sizeof("</dap:NotifyResponse>")-1;
  if (c->inc_ns_len)
    len += zx_len_inc_ns(c, &pop_seen);
  len += zx_len_xmlns_if_not_seen(c, zx_ns_tab+zx_xmlns_ix_dap, &pop_seen);

  len += zx_attr_so_len(x->itemIDRef, sizeof("itemIDRef")-1);

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
      struct zx_lu_Extension_s* e;
      for (e = x->Extension; e; e = (struct zx_lu_Extension_s*)e->gg.g.n)
	  len += zx_LEN_SO_lu_Extension(c, e);
  }


  len += zx_len_so_common(c, &x->gg);
  zx_pop_seen(pop_seen);
  ENC_LEN_DEBUG(x, "dap:NotifyResponse", len);
  return len;
}

/* FUNC(zx_LEN_WO_dap_NotifyResponse) */

/* Compute length of an element (and its subelements). The XML attributes
 * and elements are processed in wire order and no assumptions
 * are made about namespace prefixes. */

/* Called by: */
int zx_LEN_WO_dap_NotifyResponse(struct zx_ctx* c, struct zx_dap_NotifyResponse_s* x )
{
  struct zx_ns_s* pop_seen = 0;
  struct zx_elem_s* se MAYBE_UNUSED;
#if 1 /* NORMALMODE */
  int len = 1 + sizeof("NotifyResponse")-1 + 1 + 2 + sizeof("NotifyResponse")-1 + 1;
  
  if (x->gg.g.ns && x->gg.g.ns->prefix_len)
    len += (x->gg.g.ns->prefix_len + 1) * 2;
  if (c->inc_ns_len)
    len += zx_len_inc_ns(c, &pop_seen);
  len += zx_len_xmlns_if_not_seen(c, x->gg.g.ns, &pop_seen);

  len += zx_attr_wo_len(x->itemIDRef, sizeof("itemIDRef")-1);

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
      struct zx_lu_Extension_s* e;
      for (e = x->Extension; e; e = (struct zx_lu_Extension_s*)e->gg.g.n)
	  len += zx_LEN_WO_lu_Extension(c, e);
  }


  len += zx_len_wo_common(c, &x->gg); 
  zx_pop_seen(pop_seen);
  ENC_LEN_DEBUG(x, "dap:NotifyResponse", len);
  return len;
}

/* FUNC(zx_ENC_SO_dap_NotifyResponse) */

/* Render element into string. The XML attributes and elements are
 * processed in schema order. This is what you generally want for
 * rendering new data structure to a string. The wo pointers are not used. */

/* Called by: */
char* zx_ENC_SO_dap_NotifyResponse(struct zx_ctx* c, struct zx_dap_NotifyResponse_s* x, char* p )
{
  struct zx_elem_s* se MAYBE_UNUSED;
  ENC_LEN_DEBUG_BASE;
#if 1 /* NORMALMODE */
  struct zx_ns_s* pop_seen = 0;
  /* *** in simple_elem case should output ns prefix from ns node. */
  ZX_OUT_TAG(p, "<dap:NotifyResponse");
  if (c->inc_ns)
    p = zx_enc_inc_ns(c, p, &pop_seen);
  p = zx_enc_xmlns_if_not_seen(c, p, zx_ns_tab+zx_xmlns_ix_dap, &pop_seen);

  p = zx_attr_so_enc(p, x->itemIDRef, " itemIDRef=\"", sizeof(" itemIDRef=\"")-1);

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
      struct zx_lu_Extension_s* e;
      for (e = x->Extension; e; e = (struct zx_lu_Extension_s*)e->gg.g.n)
	  p = zx_ENC_SO_lu_Extension(c, e, p);
  }

  p = zx_enc_so_unknown_elems_and_content(c, p, &x->gg);
  
#if 1 /* NORMALMODE */
  ZX_OUT_CLOSE_TAG(p, "</dap:NotifyResponse>");
  zx_pop_seen(pop_seen);
#else
  /* root node has no end tag either */
#endif
  ENC_LEN_DEBUG(x, "dap:NotifyResponse", p-enc_base);
  return p;
}

/* FUNC(zx_ENC_WO_dap_NotifyResponse) */

/* Render element into string. The XML attributes and elements are
 * processed in wire order by chasing wo pointers. This is what you want for
 * validating signatures on other people's XML documents. */

/* Called by: */
char* zx_ENC_WO_dap_NotifyResponse(struct zx_ctx* c, struct zx_dap_NotifyResponse_s* x, char* p )
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
  ZX_OUT_MEM(p, "NotifyResponse", sizeof("NotifyResponse")-1);
  qq = p;

  /* *** sort the namespaces */
  if (c->inc_ns)
    zx_add_inc_ns(c, &pop_seen);
  zx_add_xmlns_if_not_seen(c, x->gg.g.ns, &pop_seen);

  p = zx_enc_seen(p, pop_seen); 
  p = zx_attr_wo_enc(p, x->itemIDRef, "itemIDRef=\"", sizeof("itemIDRef=\"")-1);

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
  ENC_LEN_DEBUG(x, "dap:NotifyResponse", p-enc_base);
  return p;
}

/* FUNC(zx_EASY_ENC_SO_dap_NotifyResponse) */

/* Called by: */
struct zx_str* zx_EASY_ENC_SO_dap_NotifyResponse(struct zx_ctx* c, struct zx_dap_NotifyResponse_s* x )
{
  int len;
  char* buf;
  c->ns_tab = ZX_ALLOC(c, sizeof(zx_ns_tab));
  memcpy(c->ns_tab, zx_ns_tab, sizeof(zx_ns_tab));
  len = zx_LEN_SO_dap_NotifyResponse(c, x );
  buf = ZX_ALLOC(c, len+1);
  return zx_easy_enc_common(c, zx_ENC_SO_dap_NotifyResponse(c, x, buf ), buf, len);
}

/* FUNC(zx_EASY_ENC_WO_dap_NotifyResponse) */

/* Called by: */
struct zx_str* zx_EASY_ENC_WO_dap_NotifyResponse(struct zx_ctx* c, struct zx_dap_NotifyResponse_s* x )
{
  int len;
  char* buf;
  c->ns_tab = ZX_ALLOC(c, sizeof(zx_ns_tab));
  memcpy(c->ns_tab, zx_ns_tab, sizeof(zx_ns_tab));
  len = zx_LEN_WO_dap_NotifyResponse(c, x );
  buf = ZX_ALLOC(c, len+1);
  return zx_easy_enc_common(c, zx_ENC_WO_dap_NotifyResponse(c, x, buf ), buf, len);
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

#define EL_NAME   dap_Query
#define EL_STRUCT zx_dap_Query_s
#define EL_NS     dap
#define EL_TAG    Query

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

/* FUNC(zx_LEN_SO_dap_Query) */

/* Compute length of an element (and its subelements). The XML attributes
 * and elements are processed in schema order. */

/* Called by: */
int zx_LEN_SO_dap_Query(struct zx_ctx* c, struct zx_dap_Query_s* x )
{
  struct zx_ns_s* pop_seen = 0;
  struct zx_elem_s* se MAYBE_UNUSED;
#if 1 /* NORMALMODE */
  /* *** in simple_elem case should output ns prefix from ns node. */
  int len = sizeof("<dap:Query")-1 + 1 + sizeof("</dap:Query>")-1;
  if (c->inc_ns_len)
    len += zx_len_inc_ns(c, &pop_seen);
  len += zx_len_xmlns_if_not_seen(c, zx_ns_tab+zx_xmlns_ix_dap, &pop_seen);
  if (x->itemID)
    len += zx_len_xmlns_if_not_seen(c, zx_ns_tab+zx_xmlns_ix_dst, &pop_seen);

  len += zx_attr_so_len(x->itemID, sizeof("dst:itemID")-1);

#else
  /* root node has no begin tag */
  int len = 0;
#endif
  
  {
      struct zx_lu_Extension_s* e;
      for (e = x->Extension; e; e = (struct zx_lu_Extension_s*)e->gg.g.n)
	  len += zx_LEN_SO_lu_Extension(c, e);
  }
  {
      struct zx_dap_TestItem_s* e;
      for (e = x->TestItem; e; e = (struct zx_dap_TestItem_s*)e->gg.g.n)
	  len += zx_LEN_SO_dap_TestItem(c, e);
  }
  {
      struct zx_dap_QueryItem_s* e;
      for (e = x->QueryItem; e; e = (struct zx_dap_QueryItem_s*)e->gg.g.n)
	  len += zx_LEN_SO_dap_QueryItem(c, e);
  }
  {
      struct zx_dap_Subscription_s* e;
      for (e = x->Subscription; e; e = (struct zx_dap_Subscription_s*)e->gg.g.n)
	  len += zx_LEN_SO_dap_Subscription(c, e);
  }


  len += zx_len_so_common(c, &x->gg);
  zx_pop_seen(pop_seen);
  ENC_LEN_DEBUG(x, "dap:Query", len);
  return len;
}

/* FUNC(zx_LEN_WO_dap_Query) */

/* Compute length of an element (and its subelements). The XML attributes
 * and elements are processed in wire order and no assumptions
 * are made about namespace prefixes. */

/* Called by: */
int zx_LEN_WO_dap_Query(struct zx_ctx* c, struct zx_dap_Query_s* x )
{
  struct zx_ns_s* pop_seen = 0;
  struct zx_elem_s* se MAYBE_UNUSED;
#if 1 /* NORMALMODE */
  int len = 1 + sizeof("Query")-1 + 1 + 2 + sizeof("Query")-1 + 1;
  
  if (x->gg.g.ns && x->gg.g.ns->prefix_len)
    len += (x->gg.g.ns->prefix_len + 1) * 2;
  if (c->inc_ns_len)
    len += zx_len_inc_ns(c, &pop_seen);
  len += zx_len_xmlns_if_not_seen(c, x->gg.g.ns, &pop_seen);
  if (x->itemID)
    len += zx_len_xmlns_if_not_seen(c, x->itemID->g.ns, &pop_seen);

  len += zx_attr_wo_len(x->itemID, sizeof("itemID")-1);

#else
  /* root node has no begin tag */
  int len = 0;
#endif
  
  {
      struct zx_lu_Extension_s* e;
      for (e = x->Extension; e; e = (struct zx_lu_Extension_s*)e->gg.g.n)
	  len += zx_LEN_WO_lu_Extension(c, e);
  }
  {
      struct zx_dap_TestItem_s* e;
      for (e = x->TestItem; e; e = (struct zx_dap_TestItem_s*)e->gg.g.n)
	  len += zx_LEN_WO_dap_TestItem(c, e);
  }
  {
      struct zx_dap_QueryItem_s* e;
      for (e = x->QueryItem; e; e = (struct zx_dap_QueryItem_s*)e->gg.g.n)
	  len += zx_LEN_WO_dap_QueryItem(c, e);
  }
  {
      struct zx_dap_Subscription_s* e;
      for (e = x->Subscription; e; e = (struct zx_dap_Subscription_s*)e->gg.g.n)
	  len += zx_LEN_WO_dap_Subscription(c, e);
  }


  len += zx_len_wo_common(c, &x->gg); 
  zx_pop_seen(pop_seen);
  ENC_LEN_DEBUG(x, "dap:Query", len);
  return len;
}

/* FUNC(zx_ENC_SO_dap_Query) */

/* Render element into string. The XML attributes and elements are
 * processed in schema order. This is what you generally want for
 * rendering new data structure to a string. The wo pointers are not used. */

/* Called by: */
char* zx_ENC_SO_dap_Query(struct zx_ctx* c, struct zx_dap_Query_s* x, char* p )
{
  struct zx_elem_s* se MAYBE_UNUSED;
  ENC_LEN_DEBUG_BASE;
#if 1 /* NORMALMODE */
  struct zx_ns_s* pop_seen = 0;
  /* *** in simple_elem case should output ns prefix from ns node. */
  ZX_OUT_TAG(p, "<dap:Query");
  if (c->inc_ns)
    p = zx_enc_inc_ns(c, p, &pop_seen);
  p = zx_enc_xmlns_if_not_seen(c, p, zx_ns_tab+zx_xmlns_ix_dap, &pop_seen);
  if (x->itemID)
    p = zx_enc_xmlns_if_not_seen(c, p, zx_ns_tab+zx_xmlns_ix_dst, &pop_seen);

  p = zx_attr_so_enc(p, x->itemID, " dst:itemID=\"", sizeof(" dst:itemID=\"")-1);

  p = zx_enc_unknown_attrs(p, x->gg.any_attr);
#else
  /* root node has no begin tag */
#endif
  
  {
      struct zx_lu_Extension_s* e;
      for (e = x->Extension; e; e = (struct zx_lu_Extension_s*)e->gg.g.n)
	  p = zx_ENC_SO_lu_Extension(c, e, p);
  }
  {
      struct zx_dap_TestItem_s* e;
      for (e = x->TestItem; e; e = (struct zx_dap_TestItem_s*)e->gg.g.n)
	  p = zx_ENC_SO_dap_TestItem(c, e, p);
  }
  {
      struct zx_dap_QueryItem_s* e;
      for (e = x->QueryItem; e; e = (struct zx_dap_QueryItem_s*)e->gg.g.n)
	  p = zx_ENC_SO_dap_QueryItem(c, e, p);
  }
  {
      struct zx_dap_Subscription_s* e;
      for (e = x->Subscription; e; e = (struct zx_dap_Subscription_s*)e->gg.g.n)
	  p = zx_ENC_SO_dap_Subscription(c, e, p);
  }

  p = zx_enc_so_unknown_elems_and_content(c, p, &x->gg);
  
#if 1 /* NORMALMODE */
  ZX_OUT_CLOSE_TAG(p, "</dap:Query>");
  zx_pop_seen(pop_seen);
#else
  /* root node has no end tag either */
#endif
  ENC_LEN_DEBUG(x, "dap:Query", p-enc_base);
  return p;
}

/* FUNC(zx_ENC_WO_dap_Query) */

/* Render element into string. The XML attributes and elements are
 * processed in wire order by chasing wo pointers. This is what you want for
 * validating signatures on other people's XML documents. */

/* Called by: */
char* zx_ENC_WO_dap_Query(struct zx_ctx* c, struct zx_dap_Query_s* x, char* p )
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
  ZX_OUT_MEM(p, "Query", sizeof("Query")-1);
  qq = p;

  /* *** sort the namespaces */
  if (c->inc_ns)
    zx_add_inc_ns(c, &pop_seen);
  zx_add_xmlns_if_not_seen(c, x->gg.g.ns, &pop_seen);
  if (x->itemID)
    zx_add_xmlns_if_not_seen(c, x->itemID->g.ns, &pop_seen);

  p = zx_enc_seen(p, pop_seen); 
  p = zx_attr_wo_enc(p, x->itemID, "itemID=\"", sizeof("itemID=\"")-1);

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
  ENC_LEN_DEBUG(x, "dap:Query", p-enc_base);
  return p;
}

/* FUNC(zx_EASY_ENC_SO_dap_Query) */

/* Called by: */
struct zx_str* zx_EASY_ENC_SO_dap_Query(struct zx_ctx* c, struct zx_dap_Query_s* x )
{
  int len;
  char* buf;
  c->ns_tab = ZX_ALLOC(c, sizeof(zx_ns_tab));
  memcpy(c->ns_tab, zx_ns_tab, sizeof(zx_ns_tab));
  len = zx_LEN_SO_dap_Query(c, x );
  buf = ZX_ALLOC(c, len+1);
  return zx_easy_enc_common(c, zx_ENC_SO_dap_Query(c, x, buf ), buf, len);
}

/* FUNC(zx_EASY_ENC_WO_dap_Query) */

/* Called by: */
struct zx_str* zx_EASY_ENC_WO_dap_Query(struct zx_ctx* c, struct zx_dap_Query_s* x )
{
  int len;
  char* buf;
  c->ns_tab = ZX_ALLOC(c, sizeof(zx_ns_tab));
  memcpy(c->ns_tab, zx_ns_tab, sizeof(zx_ns_tab));
  len = zx_LEN_WO_dap_Query(c, x );
  buf = ZX_ALLOC(c, len+1);
  return zx_easy_enc_common(c, zx_ENC_WO_dap_Query(c, x, buf ), buf, len);
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

#define EL_NAME   dap_QueryItem
#define EL_STRUCT zx_dap_QueryItem_s
#define EL_NS     dap
#define EL_TAG    QueryItem

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

/* FUNC(zx_LEN_SO_dap_QueryItem) */

/* Compute length of an element (and its subelements). The XML attributes
 * and elements are processed in schema order. */

/* Called by: */
int zx_LEN_SO_dap_QueryItem(struct zx_ctx* c, struct zx_dap_QueryItem_s* x )
{
  struct zx_ns_s* pop_seen = 0;
  struct zx_elem_s* se MAYBE_UNUSED;
#if 1 /* NORMALMODE */
  /* *** in simple_elem case should output ns prefix from ns node. */
  int len = sizeof("<dap:QueryItem")-1 + 1 + sizeof("</dap:QueryItem>")-1;
  if (c->inc_ns_len)
    len += zx_len_inc_ns(c, &pop_seen);
  len += zx_len_xmlns_if_not_seen(c, zx_ns_tab+zx_xmlns_ix_dap, &pop_seen);
  if (x->itemID || x->itemIDRef || x->objectType || x->predefined)
    len += zx_len_xmlns_if_not_seen(c, zx_ns_tab+zx_xmlns_ix_dst, &pop_seen);

  len += zx_attr_so_len(x->changedSince, sizeof("changedSince")-1);
  len += zx_attr_so_len(x->contingency, sizeof("contingency")-1);
  len += zx_attr_so_len(x->count, sizeof("count")-1);
  len += zx_attr_so_len(x->includeCommonAttributes, sizeof("includeCommonAttributes")-1);
  len += zx_attr_so_len(x->offset, sizeof("offset")-1);
  len += zx_attr_so_len(x->setID, sizeof("setID")-1);
  len += zx_attr_so_len(x->setReq, sizeof("setReq")-1);
  len += zx_attr_so_len(x->itemID, sizeof("dst:itemID")-1);
  len += zx_attr_so_len(x->itemIDRef, sizeof("dst:itemIDRef")-1);
  len += zx_attr_so_len(x->objectType, sizeof("dst:objectType")-1);
  len += zx_attr_so_len(x->predefined, sizeof("dst:predefined")-1);

#else
  /* root node has no begin tag */
  int len = 0;
#endif
  
  for (se = x->ChangeFormat; se; se = (struct zx_elem_s*)se->g.n)
    len += zx_LEN_SO_simple_elem(c,se, sizeof("dst:ChangeFormat")-1, zx_ns_tab+zx_xmlns_ix_dst);
  {
      struct zx_dap_Select_s* e;
      for (e = x->Select; e; e = (struct zx_dap_Select_s*)e->gg.g.n)
	  len += zx_LEN_SO_dap_Select(c, e);
  }
  for (se = x->Sort; se; se = (struct zx_elem_s*)se->g.n)
    len += zx_LEN_SO_simple_elem(c,se, sizeof("dap:Sort")-1, zx_ns_tab+zx_xmlns_ix_dap);


  len += zx_len_so_common(c, &x->gg);
  zx_pop_seen(pop_seen);
  ENC_LEN_DEBUG(x, "dap:QueryItem", len);
  return len;
}

/* FUNC(zx_LEN_WO_dap_QueryItem) */

/* Compute length of an element (and its subelements). The XML attributes
 * and elements are processed in wire order and no assumptions
 * are made about namespace prefixes. */

/* Called by: */
int zx_LEN_WO_dap_QueryItem(struct zx_ctx* c, struct zx_dap_QueryItem_s* x )
{
  struct zx_ns_s* pop_seen = 0;
  struct zx_elem_s* se MAYBE_UNUSED;
#if 1 /* NORMALMODE */
  int len = 1 + sizeof("QueryItem")-1 + 1 + 2 + sizeof("QueryItem")-1 + 1;
  
  if (x->gg.g.ns && x->gg.g.ns->prefix_len)
    len += (x->gg.g.ns->prefix_len + 1) * 2;
  if (c->inc_ns_len)
    len += zx_len_inc_ns(c, &pop_seen);
  len += zx_len_xmlns_if_not_seen(c, x->gg.g.ns, &pop_seen);
  if (x->itemID)
    len += zx_len_xmlns_if_not_seen(c, x->itemID->g.ns, &pop_seen);
  if (x->itemIDRef)
    len += zx_len_xmlns_if_not_seen(c, x->itemIDRef->g.ns, &pop_seen);
  if (x->objectType)
    len += zx_len_xmlns_if_not_seen(c, x->objectType->g.ns, &pop_seen);
  if (x->predefined)
    len += zx_len_xmlns_if_not_seen(c, x->predefined->g.ns, &pop_seen);

  len += zx_attr_wo_len(x->changedSince, sizeof("changedSince")-1);
  len += zx_attr_wo_len(x->contingency, sizeof("contingency")-1);
  len += zx_attr_wo_len(x->count, sizeof("count")-1);
  len += zx_attr_wo_len(x->includeCommonAttributes, sizeof("includeCommonAttributes")-1);
  len += zx_attr_wo_len(x->offset, sizeof("offset")-1);
  len += zx_attr_wo_len(x->setID, sizeof("setID")-1);
  len += zx_attr_wo_len(x->setReq, sizeof("setReq")-1);
  len += zx_attr_wo_len(x->itemID, sizeof("itemID")-1);
  len += zx_attr_wo_len(x->itemIDRef, sizeof("itemIDRef")-1);
  len += zx_attr_wo_len(x->objectType, sizeof("objectType")-1);
  len += zx_attr_wo_len(x->predefined, sizeof("predefined")-1);

#else
  /* root node has no begin tag */
  int len = 0;
#endif
  
  for (se = x->ChangeFormat; se; se = (struct zx_elem_s*)se->g.n)
    len += zx_LEN_WO_simple_elem(c, se, sizeof("ChangeFormat")-1);
  {
      struct zx_dap_Select_s* e;
      for (e = x->Select; e; e = (struct zx_dap_Select_s*)e->gg.g.n)
	  len += zx_LEN_WO_dap_Select(c, e);
  }
  for (se = x->Sort; se; se = (struct zx_elem_s*)se->g.n)
    len += zx_LEN_WO_simple_elem(c, se, sizeof("Sort")-1);


  len += zx_len_wo_common(c, &x->gg); 
  zx_pop_seen(pop_seen);
  ENC_LEN_DEBUG(x, "dap:QueryItem", len);
  return len;
}

/* FUNC(zx_ENC_SO_dap_QueryItem) */

/* Render element into string. The XML attributes and elements are
 * processed in schema order. This is what you generally want for
 * rendering new data structure to a string. The wo pointers are not used. */

/* Called by: */
char* zx_ENC_SO_dap_QueryItem(struct zx_ctx* c, struct zx_dap_QueryItem_s* x, char* p )
{
  struct zx_elem_s* se MAYBE_UNUSED;
  ENC_LEN_DEBUG_BASE;
#if 1 /* NORMALMODE */
  struct zx_ns_s* pop_seen = 0;
  /* *** in simple_elem case should output ns prefix from ns node. */
  ZX_OUT_TAG(p, "<dap:QueryItem");
  if (c->inc_ns)
    p = zx_enc_inc_ns(c, p, &pop_seen);
  p = zx_enc_xmlns_if_not_seen(c, p, zx_ns_tab+zx_xmlns_ix_dap, &pop_seen);
  if (x->itemID || x->itemIDRef || x->objectType || x->predefined)
    p = zx_enc_xmlns_if_not_seen(c, p, zx_ns_tab+zx_xmlns_ix_dst, &pop_seen);

  p = zx_attr_so_enc(p, x->changedSince, " changedSince=\"", sizeof(" changedSince=\"")-1);
  p = zx_attr_so_enc(p, x->contingency, " contingency=\"", sizeof(" contingency=\"")-1);
  p = zx_attr_so_enc(p, x->count, " count=\"", sizeof(" count=\"")-1);
  p = zx_attr_so_enc(p, x->includeCommonAttributes, " includeCommonAttributes=\"", sizeof(" includeCommonAttributes=\"")-1);
  p = zx_attr_so_enc(p, x->offset, " offset=\"", sizeof(" offset=\"")-1);
  p = zx_attr_so_enc(p, x->setID, " setID=\"", sizeof(" setID=\"")-1);
  p = zx_attr_so_enc(p, x->setReq, " setReq=\"", sizeof(" setReq=\"")-1);
  p = zx_attr_so_enc(p, x->itemID, " dst:itemID=\"", sizeof(" dst:itemID=\"")-1);
  p = zx_attr_so_enc(p, x->itemIDRef, " dst:itemIDRef=\"", sizeof(" dst:itemIDRef=\"")-1);
  p = zx_attr_so_enc(p, x->objectType, " dst:objectType=\"", sizeof(" dst:objectType=\"")-1);
  p = zx_attr_so_enc(p, x->predefined, " dst:predefined=\"", sizeof(" dst:predefined=\"")-1);

  p = zx_enc_unknown_attrs(p, x->gg.any_attr);
#else
  /* root node has no begin tag */
#endif
  
  for (se = x->ChangeFormat; se; se = (struct zx_elem_s*)se->g.n)
    p = zx_ENC_SO_simple_elem(c, se, p, "dst:ChangeFormat", sizeof("dst:ChangeFormat")-1, zx_ns_tab+zx_xmlns_ix_dst);
  {
      struct zx_dap_Select_s* e;
      for (e = x->Select; e; e = (struct zx_dap_Select_s*)e->gg.g.n)
	  p = zx_ENC_SO_dap_Select(c, e, p);
  }
  for (se = x->Sort; se; se = (struct zx_elem_s*)se->g.n)
    p = zx_ENC_SO_simple_elem(c, se, p, "dap:Sort", sizeof("dap:Sort")-1, zx_ns_tab+zx_xmlns_ix_dap);

  p = zx_enc_so_unknown_elems_and_content(c, p, &x->gg);
  
#if 1 /* NORMALMODE */
  ZX_OUT_CLOSE_TAG(p, "</dap:QueryItem>");
  zx_pop_seen(pop_seen);
#else
  /* root node has no end tag either */
#endif
  ENC_LEN_DEBUG(x, "dap:QueryItem", p-enc_base);
  return p;
}

/* FUNC(zx_ENC_WO_dap_QueryItem) */

/* Render element into string. The XML attributes and elements are
 * processed in wire order by chasing wo pointers. This is what you want for
 * validating signatures on other people's XML documents. */

/* Called by: */
char* zx_ENC_WO_dap_QueryItem(struct zx_ctx* c, struct zx_dap_QueryItem_s* x, char* p )
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
  ZX_OUT_MEM(p, "QueryItem", sizeof("QueryItem")-1);
  qq = p;

  /* *** sort the namespaces */
  if (c->inc_ns)
    zx_add_inc_ns(c, &pop_seen);
  zx_add_xmlns_if_not_seen(c, x->gg.g.ns, &pop_seen);
  if (x->itemID)
    zx_add_xmlns_if_not_seen(c, x->itemID->g.ns, &pop_seen);
  if (x->itemIDRef)
    zx_add_xmlns_if_not_seen(c, x->itemIDRef->g.ns, &pop_seen);
  if (x->objectType)
    zx_add_xmlns_if_not_seen(c, x->objectType->g.ns, &pop_seen);
  if (x->predefined)
    zx_add_xmlns_if_not_seen(c, x->predefined->g.ns, &pop_seen);

  p = zx_enc_seen(p, pop_seen); 
  p = zx_attr_wo_enc(p, x->changedSince, "changedSince=\"", sizeof("changedSince=\"")-1);
  p = zx_attr_wo_enc(p, x->contingency, "contingency=\"", sizeof("contingency=\"")-1);
  p = zx_attr_wo_enc(p, x->count, "count=\"", sizeof("count=\"")-1);
  p = zx_attr_wo_enc(p, x->includeCommonAttributes, "includeCommonAttributes=\"", sizeof("includeCommonAttributes=\"")-1);
  p = zx_attr_wo_enc(p, x->offset, "offset=\"", sizeof("offset=\"")-1);
  p = zx_attr_wo_enc(p, x->setID, "setID=\"", sizeof("setID=\"")-1);
  p = zx_attr_wo_enc(p, x->setReq, "setReq=\"", sizeof("setReq=\"")-1);
  p = zx_attr_wo_enc(p, x->itemID, "itemID=\"", sizeof("itemID=\"")-1);
  p = zx_attr_wo_enc(p, x->itemIDRef, "itemIDRef=\"", sizeof("itemIDRef=\"")-1);
  p = zx_attr_wo_enc(p, x->objectType, "objectType=\"", sizeof("objectType=\"")-1);
  p = zx_attr_wo_enc(p, x->predefined, "predefined=\"", sizeof("predefined=\"")-1);

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
  ENC_LEN_DEBUG(x, "dap:QueryItem", p-enc_base);
  return p;
}

/* FUNC(zx_EASY_ENC_SO_dap_QueryItem) */

/* Called by: */
struct zx_str* zx_EASY_ENC_SO_dap_QueryItem(struct zx_ctx* c, struct zx_dap_QueryItem_s* x )
{
  int len;
  char* buf;
  c->ns_tab = ZX_ALLOC(c, sizeof(zx_ns_tab));
  memcpy(c->ns_tab, zx_ns_tab, sizeof(zx_ns_tab));
  len = zx_LEN_SO_dap_QueryItem(c, x );
  buf = ZX_ALLOC(c, len+1);
  return zx_easy_enc_common(c, zx_ENC_SO_dap_QueryItem(c, x, buf ), buf, len);
}

/* FUNC(zx_EASY_ENC_WO_dap_QueryItem) */

/* Called by: */
struct zx_str* zx_EASY_ENC_WO_dap_QueryItem(struct zx_ctx* c, struct zx_dap_QueryItem_s* x )
{
  int len;
  char* buf;
  c->ns_tab = ZX_ALLOC(c, sizeof(zx_ns_tab));
  memcpy(c->ns_tab, zx_ns_tab, sizeof(zx_ns_tab));
  len = zx_LEN_WO_dap_QueryItem(c, x );
  buf = ZX_ALLOC(c, len+1);
  return zx_easy_enc_common(c, zx_ENC_WO_dap_QueryItem(c, x, buf ), buf, len);
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

#define EL_NAME   dap_QueryResponse
#define EL_STRUCT zx_dap_QueryResponse_s
#define EL_NS     dap
#define EL_TAG    QueryResponse

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

/* FUNC(zx_LEN_SO_dap_QueryResponse) */

/* Compute length of an element (and its subelements). The XML attributes
 * and elements are processed in schema order. */

/* Called by: */
int zx_LEN_SO_dap_QueryResponse(struct zx_ctx* c, struct zx_dap_QueryResponse_s* x )
{
  struct zx_ns_s* pop_seen = 0;
  struct zx_elem_s* se MAYBE_UNUSED;
#if 1 /* NORMALMODE */
  /* *** in simple_elem case should output ns prefix from ns node. */
  int len = sizeof("<dap:QueryResponse")-1 + 1 + sizeof("</dap:QueryResponse>")-1;
  if (c->inc_ns_len)
    len += zx_len_inc_ns(c, &pop_seen);
  len += zx_len_xmlns_if_not_seen(c, zx_ns_tab+zx_xmlns_ix_dap, &pop_seen);
  if (x->itemIDRef)
    len += zx_len_xmlns_if_not_seen(c, zx_ns_tab+zx_xmlns_ix_dst, &pop_seen);

  len += zx_attr_so_len(x->timeStamp, sizeof("timeStamp")-1);
  len += zx_attr_so_len(x->itemIDRef, sizeof("dst:itemIDRef")-1);

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
      struct zx_lu_Extension_s* e;
      for (e = x->Extension; e; e = (struct zx_lu_Extension_s*)e->gg.g.n)
	  len += zx_LEN_SO_lu_Extension(c, e);
  }
  {
      struct zx_dst_TestResult_s* e;
      for (e = x->TestResult; e; e = (struct zx_dst_TestResult_s*)e->gg.g.n)
	  len += zx_LEN_SO_dst_TestResult(c, e);
  }
  {
      struct zx_dap_Data_s* e;
      for (e = x->Data; e; e = (struct zx_dap_Data_s*)e->gg.g.n)
	  len += zx_LEN_SO_dap_Data(c, e);
  }


  len += zx_len_so_common(c, &x->gg);
  zx_pop_seen(pop_seen);
  ENC_LEN_DEBUG(x, "dap:QueryResponse", len);
  return len;
}

/* FUNC(zx_LEN_WO_dap_QueryResponse) */

/* Compute length of an element (and its subelements). The XML attributes
 * and elements are processed in wire order and no assumptions
 * are made about namespace prefixes. */

/* Called by: */
int zx_LEN_WO_dap_QueryResponse(struct zx_ctx* c, struct zx_dap_QueryResponse_s* x )
{
  struct zx_ns_s* pop_seen = 0;
  struct zx_elem_s* se MAYBE_UNUSED;
#if 1 /* NORMALMODE */
  int len = 1 + sizeof("QueryResponse")-1 + 1 + 2 + sizeof("QueryResponse")-1 + 1;
  
  if (x->gg.g.ns && x->gg.g.ns->prefix_len)
    len += (x->gg.g.ns->prefix_len + 1) * 2;
  if (c->inc_ns_len)
    len += zx_len_inc_ns(c, &pop_seen);
  len += zx_len_xmlns_if_not_seen(c, x->gg.g.ns, &pop_seen);
  if (x->itemIDRef)
    len += zx_len_xmlns_if_not_seen(c, x->itemIDRef->g.ns, &pop_seen);

  len += zx_attr_wo_len(x->timeStamp, sizeof("timeStamp")-1);
  len += zx_attr_wo_len(x->itemIDRef, sizeof("itemIDRef")-1);

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
      struct zx_lu_Extension_s* e;
      for (e = x->Extension; e; e = (struct zx_lu_Extension_s*)e->gg.g.n)
	  len += zx_LEN_WO_lu_Extension(c, e);
  }
  {
      struct zx_dst_TestResult_s* e;
      for (e = x->TestResult; e; e = (struct zx_dst_TestResult_s*)e->gg.g.n)
	  len += zx_LEN_WO_dst_TestResult(c, e);
  }
  {
      struct zx_dap_Data_s* e;
      for (e = x->Data; e; e = (struct zx_dap_Data_s*)e->gg.g.n)
	  len += zx_LEN_WO_dap_Data(c, e);
  }


  len += zx_len_wo_common(c, &x->gg); 
  zx_pop_seen(pop_seen);
  ENC_LEN_DEBUG(x, "dap:QueryResponse", len);
  return len;
}

/* FUNC(zx_ENC_SO_dap_QueryResponse) */

/* Render element into string. The XML attributes and elements are
 * processed in schema order. This is what you generally want for
 * rendering new data structure to a string. The wo pointers are not used. */

/* Called by: */
char* zx_ENC_SO_dap_QueryResponse(struct zx_ctx* c, struct zx_dap_QueryResponse_s* x, char* p )
{
  struct zx_elem_s* se MAYBE_UNUSED;
  ENC_LEN_DEBUG_BASE;
#if 1 /* NORMALMODE */
  struct zx_ns_s* pop_seen = 0;
  /* *** in simple_elem case should output ns prefix from ns node. */
  ZX_OUT_TAG(p, "<dap:QueryResponse");
  if (c->inc_ns)
    p = zx_enc_inc_ns(c, p, &pop_seen);
  p = zx_enc_xmlns_if_not_seen(c, p, zx_ns_tab+zx_xmlns_ix_dap, &pop_seen);
  if (x->itemIDRef)
    p = zx_enc_xmlns_if_not_seen(c, p, zx_ns_tab+zx_xmlns_ix_dst, &pop_seen);

  p = zx_attr_so_enc(p, x->timeStamp, " timeStamp=\"", sizeof(" timeStamp=\"")-1);
  p = zx_attr_so_enc(p, x->itemIDRef, " dst:itemIDRef=\"", sizeof(" dst:itemIDRef=\"")-1);

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
      struct zx_lu_Extension_s* e;
      for (e = x->Extension; e; e = (struct zx_lu_Extension_s*)e->gg.g.n)
	  p = zx_ENC_SO_lu_Extension(c, e, p);
  }
  {
      struct zx_dst_TestResult_s* e;
      for (e = x->TestResult; e; e = (struct zx_dst_TestResult_s*)e->gg.g.n)
	  p = zx_ENC_SO_dst_TestResult(c, e, p);
  }
  {
      struct zx_dap_Data_s* e;
      for (e = x->Data; e; e = (struct zx_dap_Data_s*)e->gg.g.n)
	  p = zx_ENC_SO_dap_Data(c, e, p);
  }

  p = zx_enc_so_unknown_elems_and_content(c, p, &x->gg);
  
#if 1 /* NORMALMODE */
  ZX_OUT_CLOSE_TAG(p, "</dap:QueryResponse>");
  zx_pop_seen(pop_seen);
#else
  /* root node has no end tag either */
#endif
  ENC_LEN_DEBUG(x, "dap:QueryResponse", p-enc_base);
  return p;
}

/* FUNC(zx_ENC_WO_dap_QueryResponse) */

/* Render element into string. The XML attributes and elements are
 * processed in wire order by chasing wo pointers. This is what you want for
 * validating signatures on other people's XML documents. */

/* Called by: */
char* zx_ENC_WO_dap_QueryResponse(struct zx_ctx* c, struct zx_dap_QueryResponse_s* x, char* p )
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
  ZX_OUT_MEM(p, "QueryResponse", sizeof("QueryResponse")-1);
  qq = p;

  /* *** sort the namespaces */
  if (c->inc_ns)
    zx_add_inc_ns(c, &pop_seen);
  zx_add_xmlns_if_not_seen(c, x->gg.g.ns, &pop_seen);
  if (x->itemIDRef)
    zx_add_xmlns_if_not_seen(c, x->itemIDRef->g.ns, &pop_seen);

  p = zx_enc_seen(p, pop_seen); 
  p = zx_attr_wo_enc(p, x->timeStamp, "timeStamp=\"", sizeof("timeStamp=\"")-1);
  p = zx_attr_wo_enc(p, x->itemIDRef, "itemIDRef=\"", sizeof("itemIDRef=\"")-1);

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
  ENC_LEN_DEBUG(x, "dap:QueryResponse", p-enc_base);
  return p;
}

/* FUNC(zx_EASY_ENC_SO_dap_QueryResponse) */

/* Called by: */
struct zx_str* zx_EASY_ENC_SO_dap_QueryResponse(struct zx_ctx* c, struct zx_dap_QueryResponse_s* x )
{
  int len;
  char* buf;
  c->ns_tab = ZX_ALLOC(c, sizeof(zx_ns_tab));
  memcpy(c->ns_tab, zx_ns_tab, sizeof(zx_ns_tab));
  len = zx_LEN_SO_dap_QueryResponse(c, x );
  buf = ZX_ALLOC(c, len+1);
  return zx_easy_enc_common(c, zx_ENC_SO_dap_QueryResponse(c, x, buf ), buf, len);
}

/* FUNC(zx_EASY_ENC_WO_dap_QueryResponse) */

/* Called by: */
struct zx_str* zx_EASY_ENC_WO_dap_QueryResponse(struct zx_ctx* c, struct zx_dap_QueryResponse_s* x )
{
  int len;
  char* buf;
  c->ns_tab = ZX_ALLOC(c, sizeof(zx_ns_tab));
  memcpy(c->ns_tab, zx_ns_tab, sizeof(zx_ns_tab));
  len = zx_LEN_WO_dap_QueryResponse(c, x );
  buf = ZX_ALLOC(c, len+1);
  return zx_easy_enc_common(c, zx_ENC_WO_dap_QueryResponse(c, x, buf ), buf, len);
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

#define EL_NAME   dap_ResultQuery
#define EL_STRUCT zx_dap_ResultQuery_s
#define EL_NS     dap
#define EL_TAG    ResultQuery

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

/* FUNC(zx_LEN_SO_dap_ResultQuery) */

/* Compute length of an element (and its subelements). The XML attributes
 * and elements are processed in schema order. */

/* Called by: */
int zx_LEN_SO_dap_ResultQuery(struct zx_ctx* c, struct zx_dap_ResultQuery_s* x )
{
  struct zx_ns_s* pop_seen = 0;
  struct zx_elem_s* se MAYBE_UNUSED;
#if 1 /* NORMALMODE */
  /* *** in simple_elem case should output ns prefix from ns node. */
  int len = sizeof("<dap:ResultQuery")-1 + 1 + sizeof("</dap:ResultQuery>")-1;
  if (c->inc_ns_len)
    len += zx_len_inc_ns(c, &pop_seen);
  len += zx_len_xmlns_if_not_seen(c, zx_ns_tab+zx_xmlns_ix_dap, &pop_seen);
  if (x->itemID || x->itemIDRef || x->objectType || x->predefined)
    len += zx_len_xmlns_if_not_seen(c, zx_ns_tab+zx_xmlns_ix_dst, &pop_seen);

  len += zx_attr_so_len(x->changedSince, sizeof("changedSince")-1);
  len += zx_attr_so_len(x->contingency, sizeof("contingency")-1);
  len += zx_attr_so_len(x->includeCommonAttributes, sizeof("includeCommonAttributes")-1);
  len += zx_attr_so_len(x->itemID, sizeof("dst:itemID")-1);
  len += zx_attr_so_len(x->itemIDRef, sizeof("dst:itemIDRef")-1);
  len += zx_attr_so_len(x->objectType, sizeof("dst:objectType")-1);
  len += zx_attr_so_len(x->predefined, sizeof("dst:predefined")-1);

#else
  /* root node has no begin tag */
  int len = 0;
#endif
  
  for (se = x->ChangeFormat; se; se = (struct zx_elem_s*)se->g.n)
    len += zx_LEN_SO_simple_elem(c,se, sizeof("dst:ChangeFormat")-1, zx_ns_tab+zx_xmlns_ix_dst);
  {
      struct zx_dap_Select_s* e;
      for (e = x->Select; e; e = (struct zx_dap_Select_s*)e->gg.g.n)
	  len += zx_LEN_SO_dap_Select(c, e);
  }
  for (se = x->Sort; se; se = (struct zx_elem_s*)se->g.n)
    len += zx_LEN_SO_simple_elem(c,se, sizeof("dap:Sort")-1, zx_ns_tab+zx_xmlns_ix_dap);


  len += zx_len_so_common(c, &x->gg);
  zx_pop_seen(pop_seen);
  ENC_LEN_DEBUG(x, "dap:ResultQuery", len);
  return len;
}

/* FUNC(zx_LEN_WO_dap_ResultQuery) */

/* Compute length of an element (and its subelements). The XML attributes
 * and elements are processed in wire order and no assumptions
 * are made about namespace prefixes. */

/* Called by: */
int zx_LEN_WO_dap_ResultQuery(struct zx_ctx* c, struct zx_dap_ResultQuery_s* x )
{
  struct zx_ns_s* pop_seen = 0;
  struct zx_elem_s* se MAYBE_UNUSED;
#if 1 /* NORMALMODE */
  int len = 1 + sizeof("ResultQuery")-1 + 1 + 2 + sizeof("ResultQuery")-1 + 1;
  
  if (x->gg.g.ns && x->gg.g.ns->prefix_len)
    len += (x->gg.g.ns->prefix_len + 1) * 2;
  if (c->inc_ns_len)
    len += zx_len_inc_ns(c, &pop_seen);
  len += zx_len_xmlns_if_not_seen(c, x->gg.g.ns, &pop_seen);
  if (x->itemID)
    len += zx_len_xmlns_if_not_seen(c, x->itemID->g.ns, &pop_seen);
  if (x->itemIDRef)
    len += zx_len_xmlns_if_not_seen(c, x->itemIDRef->g.ns, &pop_seen);
  if (x->objectType)
    len += zx_len_xmlns_if_not_seen(c, x->objectType->g.ns, &pop_seen);
  if (x->predefined)
    len += zx_len_xmlns_if_not_seen(c, x->predefined->g.ns, &pop_seen);

  len += zx_attr_wo_len(x->changedSince, sizeof("changedSince")-1);
  len += zx_attr_wo_len(x->contingency, sizeof("contingency")-1);
  len += zx_attr_wo_len(x->includeCommonAttributes, sizeof("includeCommonAttributes")-1);
  len += zx_attr_wo_len(x->itemID, sizeof("itemID")-1);
  len += zx_attr_wo_len(x->itemIDRef, sizeof("itemIDRef")-1);
  len += zx_attr_wo_len(x->objectType, sizeof("objectType")-1);
  len += zx_attr_wo_len(x->predefined, sizeof("predefined")-1);

#else
  /* root node has no begin tag */
  int len = 0;
#endif
  
  for (se = x->ChangeFormat; se; se = (struct zx_elem_s*)se->g.n)
    len += zx_LEN_WO_simple_elem(c, se, sizeof("ChangeFormat")-1);
  {
      struct zx_dap_Select_s* e;
      for (e = x->Select; e; e = (struct zx_dap_Select_s*)e->gg.g.n)
	  len += zx_LEN_WO_dap_Select(c, e);
  }
  for (se = x->Sort; se; se = (struct zx_elem_s*)se->g.n)
    len += zx_LEN_WO_simple_elem(c, se, sizeof("Sort")-1);


  len += zx_len_wo_common(c, &x->gg); 
  zx_pop_seen(pop_seen);
  ENC_LEN_DEBUG(x, "dap:ResultQuery", len);
  return len;
}

/* FUNC(zx_ENC_SO_dap_ResultQuery) */

/* Render element into string. The XML attributes and elements are
 * processed in schema order. This is what you generally want for
 * rendering new data structure to a string. The wo pointers are not used. */

/* Called by: */
char* zx_ENC_SO_dap_ResultQuery(struct zx_ctx* c, struct zx_dap_ResultQuery_s* x, char* p )
{
  struct zx_elem_s* se MAYBE_UNUSED;
  ENC_LEN_DEBUG_BASE;
#if 1 /* NORMALMODE */
  struct zx_ns_s* pop_seen = 0;
  /* *** in simple_elem case should output ns prefix from ns node. */
  ZX_OUT_TAG(p, "<dap:ResultQuery");
  if (c->inc_ns)
    p = zx_enc_inc_ns(c, p, &pop_seen);
  p = zx_enc_xmlns_if_not_seen(c, p, zx_ns_tab+zx_xmlns_ix_dap, &pop_seen);
  if (x->itemID || x->itemIDRef || x->objectType || x->predefined)
    p = zx_enc_xmlns_if_not_seen(c, p, zx_ns_tab+zx_xmlns_ix_dst, &pop_seen);

  p = zx_attr_so_enc(p, x->changedSince, " changedSince=\"", sizeof(" changedSince=\"")-1);
  p = zx_attr_so_enc(p, x->contingency, " contingency=\"", sizeof(" contingency=\"")-1);
  p = zx_attr_so_enc(p, x->includeCommonAttributes, " includeCommonAttributes=\"", sizeof(" includeCommonAttributes=\"")-1);
  p = zx_attr_so_enc(p, x->itemID, " dst:itemID=\"", sizeof(" dst:itemID=\"")-1);
  p = zx_attr_so_enc(p, x->itemIDRef, " dst:itemIDRef=\"", sizeof(" dst:itemIDRef=\"")-1);
  p = zx_attr_so_enc(p, x->objectType, " dst:objectType=\"", sizeof(" dst:objectType=\"")-1);
  p = zx_attr_so_enc(p, x->predefined, " dst:predefined=\"", sizeof(" dst:predefined=\"")-1);

  p = zx_enc_unknown_attrs(p, x->gg.any_attr);
#else
  /* root node has no begin tag */
#endif
  
  for (se = x->ChangeFormat; se; se = (struct zx_elem_s*)se->g.n)
    p = zx_ENC_SO_simple_elem(c, se, p, "dst:ChangeFormat", sizeof("dst:ChangeFormat")-1, zx_ns_tab+zx_xmlns_ix_dst);
  {
      struct zx_dap_Select_s* e;
      for (e = x->Select; e; e = (struct zx_dap_Select_s*)e->gg.g.n)
	  p = zx_ENC_SO_dap_Select(c, e, p);
  }
  for (se = x->Sort; se; se = (struct zx_elem_s*)se->g.n)
    p = zx_ENC_SO_simple_elem(c, se, p, "dap:Sort", sizeof("dap:Sort")-1, zx_ns_tab+zx_xmlns_ix_dap);

  p = zx_enc_so_unknown_elems_and_content(c, p, &x->gg);
  
#if 1 /* NORMALMODE */
  ZX_OUT_CLOSE_TAG(p, "</dap:ResultQuery>");
  zx_pop_seen(pop_seen);
#else
  /* root node has no end tag either */
#endif
  ENC_LEN_DEBUG(x, "dap:ResultQuery", p-enc_base);
  return p;
}

/* FUNC(zx_ENC_WO_dap_ResultQuery) */

/* Render element into string. The XML attributes and elements are
 * processed in wire order by chasing wo pointers. This is what you want for
 * validating signatures on other people's XML documents. */

/* Called by: */
char* zx_ENC_WO_dap_ResultQuery(struct zx_ctx* c, struct zx_dap_ResultQuery_s* x, char* p )
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
  ZX_OUT_MEM(p, "ResultQuery", sizeof("ResultQuery")-1);
  qq = p;

  /* *** sort the namespaces */
  if (c->inc_ns)
    zx_add_inc_ns(c, &pop_seen);
  zx_add_xmlns_if_not_seen(c, x->gg.g.ns, &pop_seen);
  if (x->itemID)
    zx_add_xmlns_if_not_seen(c, x->itemID->g.ns, &pop_seen);
  if (x->itemIDRef)
    zx_add_xmlns_if_not_seen(c, x->itemIDRef->g.ns, &pop_seen);
  if (x->objectType)
    zx_add_xmlns_if_not_seen(c, x->objectType->g.ns, &pop_seen);
  if (x->predefined)
    zx_add_xmlns_if_not_seen(c, x->predefined->g.ns, &pop_seen);

  p = zx_enc_seen(p, pop_seen); 
  p = zx_attr_wo_enc(p, x->changedSince, "changedSince=\"", sizeof("changedSince=\"")-1);
  p = zx_attr_wo_enc(p, x->contingency, "contingency=\"", sizeof("contingency=\"")-1);
  p = zx_attr_wo_enc(p, x->includeCommonAttributes, "includeCommonAttributes=\"", sizeof("includeCommonAttributes=\"")-1);
  p = zx_attr_wo_enc(p, x->itemID, "itemID=\"", sizeof("itemID=\"")-1);
  p = zx_attr_wo_enc(p, x->itemIDRef, "itemIDRef=\"", sizeof("itemIDRef=\"")-1);
  p = zx_attr_wo_enc(p, x->objectType, "objectType=\"", sizeof("objectType=\"")-1);
  p = zx_attr_wo_enc(p, x->predefined, "predefined=\"", sizeof("predefined=\"")-1);

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
  ENC_LEN_DEBUG(x, "dap:ResultQuery", p-enc_base);
  return p;
}

/* FUNC(zx_EASY_ENC_SO_dap_ResultQuery) */

/* Called by: */
struct zx_str* zx_EASY_ENC_SO_dap_ResultQuery(struct zx_ctx* c, struct zx_dap_ResultQuery_s* x )
{
  int len;
  char* buf;
  c->ns_tab = ZX_ALLOC(c, sizeof(zx_ns_tab));
  memcpy(c->ns_tab, zx_ns_tab, sizeof(zx_ns_tab));
  len = zx_LEN_SO_dap_ResultQuery(c, x );
  buf = ZX_ALLOC(c, len+1);
  return zx_easy_enc_common(c, zx_ENC_SO_dap_ResultQuery(c, x, buf ), buf, len);
}

/* FUNC(zx_EASY_ENC_WO_dap_ResultQuery) */

/* Called by: */
struct zx_str* zx_EASY_ENC_WO_dap_ResultQuery(struct zx_ctx* c, struct zx_dap_ResultQuery_s* x )
{
  int len;
  char* buf;
  c->ns_tab = ZX_ALLOC(c, sizeof(zx_ns_tab));
  memcpy(c->ns_tab, zx_ns_tab, sizeof(zx_ns_tab));
  len = zx_LEN_WO_dap_ResultQuery(c, x );
  buf = ZX_ALLOC(c, len+1);
  return zx_easy_enc_common(c, zx_ENC_WO_dap_ResultQuery(c, x, buf ), buf, len);
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

#define EL_NAME   dap_Select
#define EL_STRUCT zx_dap_Select_s
#define EL_NS     dap
#define EL_TAG    Select

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

/* FUNC(zx_LEN_SO_dap_Select) */

/* Compute length of an element (and its subelements). The XML attributes
 * and elements are processed in schema order. */

/* Called by: */
int zx_LEN_SO_dap_Select(struct zx_ctx* c, struct zx_dap_Select_s* x )
{
  struct zx_ns_s* pop_seen = 0;
  struct zx_elem_s* se MAYBE_UNUSED;
#if 1 /* NORMALMODE */
  /* *** in simple_elem case should output ns prefix from ns node. */
  int len = sizeof("<dap:Select")-1 + 1 + sizeof("</dap:Select>")-1;
  if (c->inc_ns_len)
    len += zx_len_inc_ns(c, &pop_seen);
  len += zx_len_xmlns_if_not_seen(c, zx_ns_tab+zx_xmlns_ix_dap, &pop_seen);

  len += zx_attr_so_len(x->attributes, sizeof("attributes")-1);
  len += zx_attr_so_len(x->derefaliases, sizeof("derefaliases")-1);
  len += zx_attr_so_len(x->scope, sizeof("scope")-1);
  len += zx_attr_so_len(x->sizelimit, sizeof("sizelimit")-1);
  len += zx_attr_so_len(x->timelimit, sizeof("timelimit")-1);
  len += zx_attr_so_len(x->typesonly, sizeof("typesonly")-1);

#else
  /* root node has no begin tag */
  int len = 0;
#endif
  
  for (se = x->dn; se; se = (struct zx_elem_s*)se->g.n)
    len += zx_LEN_SO_simple_elem(c,se, sizeof("dap:dn")-1, zx_ns_tab+zx_xmlns_ix_dap);
  for (se = x->filter; se; se = (struct zx_elem_s*)se->g.n)
    len += zx_LEN_SO_simple_elem(c,se, sizeof("dap:filter")-1, zx_ns_tab+zx_xmlns_ix_dap);


  len += zx_len_so_common(c, &x->gg);
  zx_pop_seen(pop_seen);
  ENC_LEN_DEBUG(x, "dap:Select", len);
  return len;
}

/* FUNC(zx_LEN_WO_dap_Select) */

/* Compute length of an element (and its subelements). The XML attributes
 * and elements are processed in wire order and no assumptions
 * are made about namespace prefixes. */

/* Called by: */
int zx_LEN_WO_dap_Select(struct zx_ctx* c, struct zx_dap_Select_s* x )
{
  struct zx_ns_s* pop_seen = 0;
  struct zx_elem_s* se MAYBE_UNUSED;
#if 1 /* NORMALMODE */
  int len = 1 + sizeof("Select")-1 + 1 + 2 + sizeof("Select")-1 + 1;
  
  if (x->gg.g.ns && x->gg.g.ns->prefix_len)
    len += (x->gg.g.ns->prefix_len + 1) * 2;
  if (c->inc_ns_len)
    len += zx_len_inc_ns(c, &pop_seen);
  len += zx_len_xmlns_if_not_seen(c, x->gg.g.ns, &pop_seen);

  len += zx_attr_wo_len(x->attributes, sizeof("attributes")-1);
  len += zx_attr_wo_len(x->derefaliases, sizeof("derefaliases")-1);
  len += zx_attr_wo_len(x->scope, sizeof("scope")-1);
  len += zx_attr_wo_len(x->sizelimit, sizeof("sizelimit")-1);
  len += zx_attr_wo_len(x->timelimit, sizeof("timelimit")-1);
  len += zx_attr_wo_len(x->typesonly, sizeof("typesonly")-1);

#else
  /* root node has no begin tag */
  int len = 0;
#endif
  
  for (se = x->dn; se; se = (struct zx_elem_s*)se->g.n)
    len += zx_LEN_WO_simple_elem(c, se, sizeof("dn")-1);
  for (se = x->filter; se; se = (struct zx_elem_s*)se->g.n)
    len += zx_LEN_WO_simple_elem(c, se, sizeof("filter")-1);


  len += zx_len_wo_common(c, &x->gg); 
  zx_pop_seen(pop_seen);
  ENC_LEN_DEBUG(x, "dap:Select", len);
  return len;
}

/* FUNC(zx_ENC_SO_dap_Select) */

/* Render element into string. The XML attributes and elements are
 * processed in schema order. This is what you generally want for
 * rendering new data structure to a string. The wo pointers are not used. */

/* Called by: */
char* zx_ENC_SO_dap_Select(struct zx_ctx* c, struct zx_dap_Select_s* x, char* p )
{
  struct zx_elem_s* se MAYBE_UNUSED;
  ENC_LEN_DEBUG_BASE;
#if 1 /* NORMALMODE */
  struct zx_ns_s* pop_seen = 0;
  /* *** in simple_elem case should output ns prefix from ns node. */
  ZX_OUT_TAG(p, "<dap:Select");
  if (c->inc_ns)
    p = zx_enc_inc_ns(c, p, &pop_seen);
  p = zx_enc_xmlns_if_not_seen(c, p, zx_ns_tab+zx_xmlns_ix_dap, &pop_seen);

  p = zx_attr_so_enc(p, x->attributes, " attributes=\"", sizeof(" attributes=\"")-1);
  p = zx_attr_so_enc(p, x->derefaliases, " derefaliases=\"", sizeof(" derefaliases=\"")-1);
  p = zx_attr_so_enc(p, x->scope, " scope=\"", sizeof(" scope=\"")-1);
  p = zx_attr_so_enc(p, x->sizelimit, " sizelimit=\"", sizeof(" sizelimit=\"")-1);
  p = zx_attr_so_enc(p, x->timelimit, " timelimit=\"", sizeof(" timelimit=\"")-1);
  p = zx_attr_so_enc(p, x->typesonly, " typesonly=\"", sizeof(" typesonly=\"")-1);

  p = zx_enc_unknown_attrs(p, x->gg.any_attr);
#else
  /* root node has no begin tag */
#endif
  
  for (se = x->dn; se; se = (struct zx_elem_s*)se->g.n)
    p = zx_ENC_SO_simple_elem(c, se, p, "dap:dn", sizeof("dap:dn")-1, zx_ns_tab+zx_xmlns_ix_dap);
  for (se = x->filter; se; se = (struct zx_elem_s*)se->g.n)
    p = zx_ENC_SO_simple_elem(c, se, p, "dap:filter", sizeof("dap:filter")-1, zx_ns_tab+zx_xmlns_ix_dap);

  p = zx_enc_so_unknown_elems_and_content(c, p, &x->gg);
  
#if 1 /* NORMALMODE */
  ZX_OUT_CLOSE_TAG(p, "</dap:Select>");
  zx_pop_seen(pop_seen);
#else
  /* root node has no end tag either */
#endif
  ENC_LEN_DEBUG(x, "dap:Select", p-enc_base);
  return p;
}

/* FUNC(zx_ENC_WO_dap_Select) */

/* Render element into string. The XML attributes and elements are
 * processed in wire order by chasing wo pointers. This is what you want for
 * validating signatures on other people's XML documents. */

/* Called by: */
char* zx_ENC_WO_dap_Select(struct zx_ctx* c, struct zx_dap_Select_s* x, char* p )
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
  ZX_OUT_MEM(p, "Select", sizeof("Select")-1);
  qq = p;

  /* *** sort the namespaces */
  if (c->inc_ns)
    zx_add_inc_ns(c, &pop_seen);
  zx_add_xmlns_if_not_seen(c, x->gg.g.ns, &pop_seen);

  p = zx_enc_seen(p, pop_seen); 
  p = zx_attr_wo_enc(p, x->attributes, "attributes=\"", sizeof("attributes=\"")-1);
  p = zx_attr_wo_enc(p, x->derefaliases, "derefaliases=\"", sizeof("derefaliases=\"")-1);
  p = zx_attr_wo_enc(p, x->scope, "scope=\"", sizeof("scope=\"")-1);
  p = zx_attr_wo_enc(p, x->sizelimit, "sizelimit=\"", sizeof("sizelimit=\"")-1);
  p = zx_attr_wo_enc(p, x->timelimit, "timelimit=\"", sizeof("timelimit=\"")-1);
  p = zx_attr_wo_enc(p, x->typesonly, "typesonly=\"", sizeof("typesonly=\"")-1);

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
  ENC_LEN_DEBUG(x, "dap:Select", p-enc_base);
  return p;
}

/* FUNC(zx_EASY_ENC_SO_dap_Select) */

/* Called by: */
struct zx_str* zx_EASY_ENC_SO_dap_Select(struct zx_ctx* c, struct zx_dap_Select_s* x )
{
  int len;
  char* buf;
  c->ns_tab = ZX_ALLOC(c, sizeof(zx_ns_tab));
  memcpy(c->ns_tab, zx_ns_tab, sizeof(zx_ns_tab));
  len = zx_LEN_SO_dap_Select(c, x );
  buf = ZX_ALLOC(c, len+1);
  return zx_easy_enc_common(c, zx_ENC_SO_dap_Select(c, x, buf ), buf, len);
}

/* FUNC(zx_EASY_ENC_WO_dap_Select) */

/* Called by: */
struct zx_str* zx_EASY_ENC_WO_dap_Select(struct zx_ctx* c, struct zx_dap_Select_s* x )
{
  int len;
  char* buf;
  c->ns_tab = ZX_ALLOC(c, sizeof(zx_ns_tab));
  memcpy(c->ns_tab, zx_ns_tab, sizeof(zx_ns_tab));
  len = zx_LEN_WO_dap_Select(c, x );
  buf = ZX_ALLOC(c, len+1);
  return zx_easy_enc_common(c, zx_ENC_WO_dap_Select(c, x, buf ), buf, len);
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

#define EL_NAME   dap_Subscription
#define EL_STRUCT zx_dap_Subscription_s
#define EL_NS     dap
#define EL_TAG    Subscription

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

/* FUNC(zx_LEN_SO_dap_Subscription) */

/* Compute length of an element (and its subelements). The XML attributes
 * and elements are processed in schema order. */

/* Called by: */
int zx_LEN_SO_dap_Subscription(struct zx_ctx* c, struct zx_dap_Subscription_s* x )
{
  struct zx_ns_s* pop_seen = 0;
  struct zx_elem_s* se MAYBE_UNUSED;
#if 1 /* NORMALMODE */
  /* *** in simple_elem case should output ns prefix from ns node. */
  int len = sizeof("<dap:Subscription")-1 + 1 + sizeof("</dap:Subscription>")-1;
  if (c->inc_ns_len)
    len += zx_len_inc_ns(c, &pop_seen);
  len += zx_len_xmlns_if_not_seen(c, zx_ns_tab+zx_xmlns_ix_dap, &pop_seen);

  len += zx_attr_so_len(x->adminNotifyToRef, sizeof("adminNotifyToRef")-1);
  len += zx_attr_so_len(x->expires, sizeof("expires")-1);
  len += zx_attr_so_len(x->id, sizeof("id")-1);
  len += zx_attr_so_len(x->includeData, sizeof("includeData")-1);
  len += zx_attr_so_len(x->notifyToRef, sizeof("notifyToRef")-1);
  len += zx_attr_so_len(x->starts, sizeof("starts")-1);
  len += zx_attr_so_len(x->subscriptionID, sizeof("subscriptionID")-1);

#else
  /* root node has no begin tag */
  int len = 0;
#endif
  
  {
      struct zx_subs_RefItem_s* e;
      for (e = x->RefItem; e; e = (struct zx_subs_RefItem_s*)e->gg.g.n)
	  len += zx_LEN_SO_subs_RefItem(c, e);
  }
  {
      struct zx_lu_Extension_s* e;
      for (e = x->Extension; e; e = (struct zx_lu_Extension_s*)e->gg.g.n)
	  len += zx_LEN_SO_lu_Extension(c, e);
  }
  {
      struct zx_dap_ResultQuery_s* e;
      for (e = x->ResultQuery; e; e = (struct zx_dap_ResultQuery_s*)e->gg.g.n)
	  len += zx_LEN_SO_dap_ResultQuery(c, e);
  }
  for (se = x->Aggregation; se; se = (struct zx_elem_s*)se->g.n)
    len += zx_LEN_SO_simple_elem(c,se, sizeof("dap:Aggregation")-1, zx_ns_tab+zx_xmlns_ix_dap);
  for (se = x->Trigger; se; se = (struct zx_elem_s*)se->g.n)
    len += zx_LEN_SO_simple_elem(c,se, sizeof("dap:Trigger")-1, zx_ns_tab+zx_xmlns_ix_dap);


  len += zx_len_so_common(c, &x->gg);
  zx_pop_seen(pop_seen);
  ENC_LEN_DEBUG(x, "dap:Subscription", len);
  return len;
}

/* FUNC(zx_LEN_WO_dap_Subscription) */

/* Compute length of an element (and its subelements). The XML attributes
 * and elements are processed in wire order and no assumptions
 * are made about namespace prefixes. */

/* Called by: */
int zx_LEN_WO_dap_Subscription(struct zx_ctx* c, struct zx_dap_Subscription_s* x )
{
  struct zx_ns_s* pop_seen = 0;
  struct zx_elem_s* se MAYBE_UNUSED;
#if 1 /* NORMALMODE */
  int len = 1 + sizeof("Subscription")-1 + 1 + 2 + sizeof("Subscription")-1 + 1;
  
  if (x->gg.g.ns && x->gg.g.ns->prefix_len)
    len += (x->gg.g.ns->prefix_len + 1) * 2;
  if (c->inc_ns_len)
    len += zx_len_inc_ns(c, &pop_seen);
  len += zx_len_xmlns_if_not_seen(c, x->gg.g.ns, &pop_seen);

  len += zx_attr_wo_len(x->adminNotifyToRef, sizeof("adminNotifyToRef")-1);
  len += zx_attr_wo_len(x->expires, sizeof("expires")-1);
  len += zx_attr_wo_len(x->id, sizeof("id")-1);
  len += zx_attr_wo_len(x->includeData, sizeof("includeData")-1);
  len += zx_attr_wo_len(x->notifyToRef, sizeof("notifyToRef")-1);
  len += zx_attr_wo_len(x->starts, sizeof("starts")-1);
  len += zx_attr_wo_len(x->subscriptionID, sizeof("subscriptionID")-1);

#else
  /* root node has no begin tag */
  int len = 0;
#endif
  
  {
      struct zx_subs_RefItem_s* e;
      for (e = x->RefItem; e; e = (struct zx_subs_RefItem_s*)e->gg.g.n)
	  len += zx_LEN_WO_subs_RefItem(c, e);
  }
  {
      struct zx_lu_Extension_s* e;
      for (e = x->Extension; e; e = (struct zx_lu_Extension_s*)e->gg.g.n)
	  len += zx_LEN_WO_lu_Extension(c, e);
  }
  {
      struct zx_dap_ResultQuery_s* e;
      for (e = x->ResultQuery; e; e = (struct zx_dap_ResultQuery_s*)e->gg.g.n)
	  len += zx_LEN_WO_dap_ResultQuery(c, e);
  }
  for (se = x->Aggregation; se; se = (struct zx_elem_s*)se->g.n)
    len += zx_LEN_WO_simple_elem(c, se, sizeof("Aggregation")-1);
  for (se = x->Trigger; se; se = (struct zx_elem_s*)se->g.n)
    len += zx_LEN_WO_simple_elem(c, se, sizeof("Trigger")-1);


  len += zx_len_wo_common(c, &x->gg); 
  zx_pop_seen(pop_seen);
  ENC_LEN_DEBUG(x, "dap:Subscription", len);
  return len;
}

/* FUNC(zx_ENC_SO_dap_Subscription) */

/* Render element into string. The XML attributes and elements are
 * processed in schema order. This is what you generally want for
 * rendering new data structure to a string. The wo pointers are not used. */

/* Called by: */
char* zx_ENC_SO_dap_Subscription(struct zx_ctx* c, struct zx_dap_Subscription_s* x, char* p )
{
  struct zx_elem_s* se MAYBE_UNUSED;
  ENC_LEN_DEBUG_BASE;
#if 1 /* NORMALMODE */
  struct zx_ns_s* pop_seen = 0;
  /* *** in simple_elem case should output ns prefix from ns node. */
  ZX_OUT_TAG(p, "<dap:Subscription");
  if (c->inc_ns)
    p = zx_enc_inc_ns(c, p, &pop_seen);
  p = zx_enc_xmlns_if_not_seen(c, p, zx_ns_tab+zx_xmlns_ix_dap, &pop_seen);

  p = zx_attr_so_enc(p, x->adminNotifyToRef, " adminNotifyToRef=\"", sizeof(" adminNotifyToRef=\"")-1);
  p = zx_attr_so_enc(p, x->expires, " expires=\"", sizeof(" expires=\"")-1);
  p = zx_attr_so_enc(p, x->id, " id=\"", sizeof(" id=\"")-1);
  p = zx_attr_so_enc(p, x->includeData, " includeData=\"", sizeof(" includeData=\"")-1);
  p = zx_attr_so_enc(p, x->notifyToRef, " notifyToRef=\"", sizeof(" notifyToRef=\"")-1);
  p = zx_attr_so_enc(p, x->starts, " starts=\"", sizeof(" starts=\"")-1);
  p = zx_attr_so_enc(p, x->subscriptionID, " subscriptionID=\"", sizeof(" subscriptionID=\"")-1);

  p = zx_enc_unknown_attrs(p, x->gg.any_attr);
#else
  /* root node has no begin tag */
#endif
  
  {
      struct zx_subs_RefItem_s* e;
      for (e = x->RefItem; e; e = (struct zx_subs_RefItem_s*)e->gg.g.n)
	  p = zx_ENC_SO_subs_RefItem(c, e, p);
  }
  {
      struct zx_lu_Extension_s* e;
      for (e = x->Extension; e; e = (struct zx_lu_Extension_s*)e->gg.g.n)
	  p = zx_ENC_SO_lu_Extension(c, e, p);
  }
  {
      struct zx_dap_ResultQuery_s* e;
      for (e = x->ResultQuery; e; e = (struct zx_dap_ResultQuery_s*)e->gg.g.n)
	  p = zx_ENC_SO_dap_ResultQuery(c, e, p);
  }
  for (se = x->Aggregation; se; se = (struct zx_elem_s*)se->g.n)
    p = zx_ENC_SO_simple_elem(c, se, p, "dap:Aggregation", sizeof("dap:Aggregation")-1, zx_ns_tab+zx_xmlns_ix_dap);
  for (se = x->Trigger; se; se = (struct zx_elem_s*)se->g.n)
    p = zx_ENC_SO_simple_elem(c, se, p, "dap:Trigger", sizeof("dap:Trigger")-1, zx_ns_tab+zx_xmlns_ix_dap);

  p = zx_enc_so_unknown_elems_and_content(c, p, &x->gg);
  
#if 1 /* NORMALMODE */
  ZX_OUT_CLOSE_TAG(p, "</dap:Subscription>");
  zx_pop_seen(pop_seen);
#else
  /* root node has no end tag either */
#endif
  ENC_LEN_DEBUG(x, "dap:Subscription", p-enc_base);
  return p;
}

/* FUNC(zx_ENC_WO_dap_Subscription) */

/* Render element into string. The XML attributes and elements are
 * processed in wire order by chasing wo pointers. This is what you want for
 * validating signatures on other people's XML documents. */

/* Called by: */
char* zx_ENC_WO_dap_Subscription(struct zx_ctx* c, struct zx_dap_Subscription_s* x, char* p )
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
  ZX_OUT_MEM(p, "Subscription", sizeof("Subscription")-1);
  qq = p;

  /* *** sort the namespaces */
  if (c->inc_ns)
    zx_add_inc_ns(c, &pop_seen);
  zx_add_xmlns_if_not_seen(c, x->gg.g.ns, &pop_seen);

  p = zx_enc_seen(p, pop_seen); 
  p = zx_attr_wo_enc(p, x->adminNotifyToRef, "adminNotifyToRef=\"", sizeof("adminNotifyToRef=\"")-1);
  p = zx_attr_wo_enc(p, x->expires, "expires=\"", sizeof("expires=\"")-1);
  p = zx_attr_wo_enc(p, x->id, "id=\"", sizeof("id=\"")-1);
  p = zx_attr_wo_enc(p, x->includeData, "includeData=\"", sizeof("includeData=\"")-1);
  p = zx_attr_wo_enc(p, x->notifyToRef, "notifyToRef=\"", sizeof("notifyToRef=\"")-1);
  p = zx_attr_wo_enc(p, x->starts, "starts=\"", sizeof("starts=\"")-1);
  p = zx_attr_wo_enc(p, x->subscriptionID, "subscriptionID=\"", sizeof("subscriptionID=\"")-1);

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
  ENC_LEN_DEBUG(x, "dap:Subscription", p-enc_base);
  return p;
}

/* FUNC(zx_EASY_ENC_SO_dap_Subscription) */

/* Called by: */
struct zx_str* zx_EASY_ENC_SO_dap_Subscription(struct zx_ctx* c, struct zx_dap_Subscription_s* x )
{
  int len;
  char* buf;
  c->ns_tab = ZX_ALLOC(c, sizeof(zx_ns_tab));
  memcpy(c->ns_tab, zx_ns_tab, sizeof(zx_ns_tab));
  len = zx_LEN_SO_dap_Subscription(c, x );
  buf = ZX_ALLOC(c, len+1);
  return zx_easy_enc_common(c, zx_ENC_SO_dap_Subscription(c, x, buf ), buf, len);
}

/* FUNC(zx_EASY_ENC_WO_dap_Subscription) */

/* Called by: */
struct zx_str* zx_EASY_ENC_WO_dap_Subscription(struct zx_ctx* c, struct zx_dap_Subscription_s* x )
{
  int len;
  char* buf;
  c->ns_tab = ZX_ALLOC(c, sizeof(zx_ns_tab));
  memcpy(c->ns_tab, zx_ns_tab, sizeof(zx_ns_tab));
  len = zx_LEN_WO_dap_Subscription(c, x );
  buf = ZX_ALLOC(c, len+1);
  return zx_easy_enc_common(c, zx_ENC_WO_dap_Subscription(c, x, buf ), buf, len);
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

#define EL_NAME   dap_TestItem
#define EL_STRUCT zx_dap_TestItem_s
#define EL_NS     dap
#define EL_TAG    TestItem

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

/* FUNC(zx_LEN_SO_dap_TestItem) */

/* Compute length of an element (and its subelements). The XML attributes
 * and elements are processed in schema order. */

/* Called by: */
int zx_LEN_SO_dap_TestItem(struct zx_ctx* c, struct zx_dap_TestItem_s* x )
{
  struct zx_ns_s* pop_seen = 0;
  struct zx_elem_s* se MAYBE_UNUSED;
#if 1 /* NORMALMODE */
  /* *** in simple_elem case should output ns prefix from ns node. */
  int len = sizeof("<dap:TestItem")-1 + 1 + sizeof("</dap:TestItem>")-1;
  if (c->inc_ns_len)
    len += zx_len_inc_ns(c, &pop_seen);
  len += zx_len_xmlns_if_not_seen(c, zx_ns_tab+zx_xmlns_ix_dap, &pop_seen);
  if (x->itemID || x->objectType || x->predefined)
    len += zx_len_xmlns_if_not_seen(c, zx_ns_tab+zx_xmlns_ix_dst, &pop_seen);

  len += zx_attr_so_len(x->id, sizeof("id")-1);
  len += zx_attr_so_len(x->itemID, sizeof("dst:itemID")-1);
  len += zx_attr_so_len(x->objectType, sizeof("dst:objectType")-1);
  len += zx_attr_so_len(x->predefined, sizeof("dst:predefined")-1);

#else
  /* root node has no begin tag */
  int len = 0;
#endif
  
  {
      struct zx_dap_TestOp_s* e;
      for (e = x->TestOp; e; e = (struct zx_dap_TestOp_s*)e->gg.g.n)
	  len += zx_LEN_SO_dap_TestOp(c, e);
  }


  len += zx_len_so_common(c, &x->gg);
  zx_pop_seen(pop_seen);
  ENC_LEN_DEBUG(x, "dap:TestItem", len);
  return len;
}

/* FUNC(zx_LEN_WO_dap_TestItem) */

/* Compute length of an element (and its subelements). The XML attributes
 * and elements are processed in wire order and no assumptions
 * are made about namespace prefixes. */

/* Called by: */
int zx_LEN_WO_dap_TestItem(struct zx_ctx* c, struct zx_dap_TestItem_s* x )
{
  struct zx_ns_s* pop_seen = 0;
  struct zx_elem_s* se MAYBE_UNUSED;
#if 1 /* NORMALMODE */
  int len = 1 + sizeof("TestItem")-1 + 1 + 2 + sizeof("TestItem")-1 + 1;
  
  if (x->gg.g.ns && x->gg.g.ns->prefix_len)
    len += (x->gg.g.ns->prefix_len + 1) * 2;
  if (c->inc_ns_len)
    len += zx_len_inc_ns(c, &pop_seen);
  len += zx_len_xmlns_if_not_seen(c, x->gg.g.ns, &pop_seen);
  if (x->itemID)
    len += zx_len_xmlns_if_not_seen(c, x->itemID->g.ns, &pop_seen);
  if (x->objectType)
    len += zx_len_xmlns_if_not_seen(c, x->objectType->g.ns, &pop_seen);
  if (x->predefined)
    len += zx_len_xmlns_if_not_seen(c, x->predefined->g.ns, &pop_seen);

  len += zx_attr_wo_len(x->id, sizeof("id")-1);
  len += zx_attr_wo_len(x->itemID, sizeof("itemID")-1);
  len += zx_attr_wo_len(x->objectType, sizeof("objectType")-1);
  len += zx_attr_wo_len(x->predefined, sizeof("predefined")-1);

#else
  /* root node has no begin tag */
  int len = 0;
#endif
  
  {
      struct zx_dap_TestOp_s* e;
      for (e = x->TestOp; e; e = (struct zx_dap_TestOp_s*)e->gg.g.n)
	  len += zx_LEN_WO_dap_TestOp(c, e);
  }


  len += zx_len_wo_common(c, &x->gg); 
  zx_pop_seen(pop_seen);
  ENC_LEN_DEBUG(x, "dap:TestItem", len);
  return len;
}

/* FUNC(zx_ENC_SO_dap_TestItem) */

/* Render element into string. The XML attributes and elements are
 * processed in schema order. This is what you generally want for
 * rendering new data structure to a string. The wo pointers are not used. */

/* Called by: */
char* zx_ENC_SO_dap_TestItem(struct zx_ctx* c, struct zx_dap_TestItem_s* x, char* p )
{
  struct zx_elem_s* se MAYBE_UNUSED;
  ENC_LEN_DEBUG_BASE;
#if 1 /* NORMALMODE */
  struct zx_ns_s* pop_seen = 0;
  /* *** in simple_elem case should output ns prefix from ns node. */
  ZX_OUT_TAG(p, "<dap:TestItem");
  if (c->inc_ns)
    p = zx_enc_inc_ns(c, p, &pop_seen);
  p = zx_enc_xmlns_if_not_seen(c, p, zx_ns_tab+zx_xmlns_ix_dap, &pop_seen);
  if (x->itemID || x->objectType || x->predefined)
    p = zx_enc_xmlns_if_not_seen(c, p, zx_ns_tab+zx_xmlns_ix_dst, &pop_seen);

  p = zx_attr_so_enc(p, x->id, " id=\"", sizeof(" id=\"")-1);
  p = zx_attr_so_enc(p, x->itemID, " dst:itemID=\"", sizeof(" dst:itemID=\"")-1);
  p = zx_attr_so_enc(p, x->objectType, " dst:objectType=\"", sizeof(" dst:objectType=\"")-1);
  p = zx_attr_so_enc(p, x->predefined, " dst:predefined=\"", sizeof(" dst:predefined=\"")-1);

  p = zx_enc_unknown_attrs(p, x->gg.any_attr);
#else
  /* root node has no begin tag */
#endif
  
  {
      struct zx_dap_TestOp_s* e;
      for (e = x->TestOp; e; e = (struct zx_dap_TestOp_s*)e->gg.g.n)
	  p = zx_ENC_SO_dap_TestOp(c, e, p);
  }

  p = zx_enc_so_unknown_elems_and_content(c, p, &x->gg);
  
#if 1 /* NORMALMODE */
  ZX_OUT_CLOSE_TAG(p, "</dap:TestItem>");
  zx_pop_seen(pop_seen);
#else
  /* root node has no end tag either */
#endif
  ENC_LEN_DEBUG(x, "dap:TestItem", p-enc_base);
  return p;
}

/* FUNC(zx_ENC_WO_dap_TestItem) */

/* Render element into string. The XML attributes and elements are
 * processed in wire order by chasing wo pointers. This is what you want for
 * validating signatures on other people's XML documents. */

/* Called by: */
char* zx_ENC_WO_dap_TestItem(struct zx_ctx* c, struct zx_dap_TestItem_s* x, char* p )
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
  ZX_OUT_MEM(p, "TestItem", sizeof("TestItem")-1);
  qq = p;

  /* *** sort the namespaces */
  if (c->inc_ns)
    zx_add_inc_ns(c, &pop_seen);
  zx_add_xmlns_if_not_seen(c, x->gg.g.ns, &pop_seen);
  if (x->itemID)
    zx_add_xmlns_if_not_seen(c, x->itemID->g.ns, &pop_seen);
  if (x->objectType)
    zx_add_xmlns_if_not_seen(c, x->objectType->g.ns, &pop_seen);
  if (x->predefined)
    zx_add_xmlns_if_not_seen(c, x->predefined->g.ns, &pop_seen);

  p = zx_enc_seen(p, pop_seen); 
  p = zx_attr_wo_enc(p, x->id, "id=\"", sizeof("id=\"")-1);
  p = zx_attr_wo_enc(p, x->itemID, "itemID=\"", sizeof("itemID=\"")-1);
  p = zx_attr_wo_enc(p, x->objectType, "objectType=\"", sizeof("objectType=\"")-1);
  p = zx_attr_wo_enc(p, x->predefined, "predefined=\"", sizeof("predefined=\"")-1);

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
  ENC_LEN_DEBUG(x, "dap:TestItem", p-enc_base);
  return p;
}

/* FUNC(zx_EASY_ENC_SO_dap_TestItem) */

/* Called by: */
struct zx_str* zx_EASY_ENC_SO_dap_TestItem(struct zx_ctx* c, struct zx_dap_TestItem_s* x )
{
  int len;
  char* buf;
  c->ns_tab = ZX_ALLOC(c, sizeof(zx_ns_tab));
  memcpy(c->ns_tab, zx_ns_tab, sizeof(zx_ns_tab));
  len = zx_LEN_SO_dap_TestItem(c, x );
  buf = ZX_ALLOC(c, len+1);
  return zx_easy_enc_common(c, zx_ENC_SO_dap_TestItem(c, x, buf ), buf, len);
}

/* FUNC(zx_EASY_ENC_WO_dap_TestItem) */

/* Called by: */
struct zx_str* zx_EASY_ENC_WO_dap_TestItem(struct zx_ctx* c, struct zx_dap_TestItem_s* x )
{
  int len;
  char* buf;
  c->ns_tab = ZX_ALLOC(c, sizeof(zx_ns_tab));
  memcpy(c->ns_tab, zx_ns_tab, sizeof(zx_ns_tab));
  len = zx_LEN_WO_dap_TestItem(c, x );
  buf = ZX_ALLOC(c, len+1);
  return zx_easy_enc_common(c, zx_ENC_WO_dap_TestItem(c, x, buf ), buf, len);
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

#define EL_NAME   dap_TestOp
#define EL_STRUCT zx_dap_TestOp_s
#define EL_NS     dap
#define EL_TAG    TestOp

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

/* FUNC(zx_LEN_SO_dap_TestOp) */

/* Compute length of an element (and its subelements). The XML attributes
 * and elements are processed in schema order. */

/* Called by: */
int zx_LEN_SO_dap_TestOp(struct zx_ctx* c, struct zx_dap_TestOp_s* x )
{
  struct zx_ns_s* pop_seen = 0;
  struct zx_elem_s* se MAYBE_UNUSED;
#if 1 /* NORMALMODE */
  /* *** in simple_elem case should output ns prefix from ns node. */
  int len = sizeof("<dap:TestOp")-1 + 1 + sizeof("</dap:TestOp>")-1;
  if (c->inc_ns_len)
    len += zx_len_inc_ns(c, &pop_seen);
  len += zx_len_xmlns_if_not_seen(c, zx_ns_tab+zx_xmlns_ix_dap, &pop_seen);

  len += zx_attr_so_len(x->attributes, sizeof("attributes")-1);
  len += zx_attr_so_len(x->derefaliases, sizeof("derefaliases")-1);
  len += zx_attr_so_len(x->scope, sizeof("scope")-1);
  len += zx_attr_so_len(x->sizelimit, sizeof("sizelimit")-1);
  len += zx_attr_so_len(x->timelimit, sizeof("timelimit")-1);
  len += zx_attr_so_len(x->typesonly, sizeof("typesonly")-1);

#else
  /* root node has no begin tag */
  int len = 0;
#endif
  
  for (se = x->dn; se; se = (struct zx_elem_s*)se->g.n)
    len += zx_LEN_SO_simple_elem(c,se, sizeof("dap:dn")-1, zx_ns_tab+zx_xmlns_ix_dap);
  for (se = x->filter; se; se = (struct zx_elem_s*)se->g.n)
    len += zx_LEN_SO_simple_elem(c,se, sizeof("dap:filter")-1, zx_ns_tab+zx_xmlns_ix_dap);


  len += zx_len_so_common(c, &x->gg);
  zx_pop_seen(pop_seen);
  ENC_LEN_DEBUG(x, "dap:TestOp", len);
  return len;
}

/* FUNC(zx_LEN_WO_dap_TestOp) */

/* Compute length of an element (and its subelements). The XML attributes
 * and elements are processed in wire order and no assumptions
 * are made about namespace prefixes. */

/* Called by: */
int zx_LEN_WO_dap_TestOp(struct zx_ctx* c, struct zx_dap_TestOp_s* x )
{
  struct zx_ns_s* pop_seen = 0;
  struct zx_elem_s* se MAYBE_UNUSED;
#if 1 /* NORMALMODE */
  int len = 1 + sizeof("TestOp")-1 + 1 + 2 + sizeof("TestOp")-1 + 1;
  
  if (x->gg.g.ns && x->gg.g.ns->prefix_len)
    len += (x->gg.g.ns->prefix_len + 1) * 2;
  if (c->inc_ns_len)
    len += zx_len_inc_ns(c, &pop_seen);
  len += zx_len_xmlns_if_not_seen(c, x->gg.g.ns, &pop_seen);

  len += zx_attr_wo_len(x->attributes, sizeof("attributes")-1);
  len += zx_attr_wo_len(x->derefaliases, sizeof("derefaliases")-1);
  len += zx_attr_wo_len(x->scope, sizeof("scope")-1);
  len += zx_attr_wo_len(x->sizelimit, sizeof("sizelimit")-1);
  len += zx_attr_wo_len(x->timelimit, sizeof("timelimit")-1);
  len += zx_attr_wo_len(x->typesonly, sizeof("typesonly")-1);

#else
  /* root node has no begin tag */
  int len = 0;
#endif
  
  for (se = x->dn; se; se = (struct zx_elem_s*)se->g.n)
    len += zx_LEN_WO_simple_elem(c, se, sizeof("dn")-1);
  for (se = x->filter; se; se = (struct zx_elem_s*)se->g.n)
    len += zx_LEN_WO_simple_elem(c, se, sizeof("filter")-1);


  len += zx_len_wo_common(c, &x->gg); 
  zx_pop_seen(pop_seen);
  ENC_LEN_DEBUG(x, "dap:TestOp", len);
  return len;
}

/* FUNC(zx_ENC_SO_dap_TestOp) */

/* Render element into string. The XML attributes and elements are
 * processed in schema order. This is what you generally want for
 * rendering new data structure to a string. The wo pointers are not used. */

/* Called by: */
char* zx_ENC_SO_dap_TestOp(struct zx_ctx* c, struct zx_dap_TestOp_s* x, char* p )
{
  struct zx_elem_s* se MAYBE_UNUSED;
  ENC_LEN_DEBUG_BASE;
#if 1 /* NORMALMODE */
  struct zx_ns_s* pop_seen = 0;
  /* *** in simple_elem case should output ns prefix from ns node. */
  ZX_OUT_TAG(p, "<dap:TestOp");
  if (c->inc_ns)
    p = zx_enc_inc_ns(c, p, &pop_seen);
  p = zx_enc_xmlns_if_not_seen(c, p, zx_ns_tab+zx_xmlns_ix_dap, &pop_seen);

  p = zx_attr_so_enc(p, x->attributes, " attributes=\"", sizeof(" attributes=\"")-1);
  p = zx_attr_so_enc(p, x->derefaliases, " derefaliases=\"", sizeof(" derefaliases=\"")-1);
  p = zx_attr_so_enc(p, x->scope, " scope=\"", sizeof(" scope=\"")-1);
  p = zx_attr_so_enc(p, x->sizelimit, " sizelimit=\"", sizeof(" sizelimit=\"")-1);
  p = zx_attr_so_enc(p, x->timelimit, " timelimit=\"", sizeof(" timelimit=\"")-1);
  p = zx_attr_so_enc(p, x->typesonly, " typesonly=\"", sizeof(" typesonly=\"")-1);

  p = zx_enc_unknown_attrs(p, x->gg.any_attr);
#else
  /* root node has no begin tag */
#endif
  
  for (se = x->dn; se; se = (struct zx_elem_s*)se->g.n)
    p = zx_ENC_SO_simple_elem(c, se, p, "dap:dn", sizeof("dap:dn")-1, zx_ns_tab+zx_xmlns_ix_dap);
  for (se = x->filter; se; se = (struct zx_elem_s*)se->g.n)
    p = zx_ENC_SO_simple_elem(c, se, p, "dap:filter", sizeof("dap:filter")-1, zx_ns_tab+zx_xmlns_ix_dap);

  p = zx_enc_so_unknown_elems_and_content(c, p, &x->gg);
  
#if 1 /* NORMALMODE */
  ZX_OUT_CLOSE_TAG(p, "</dap:TestOp>");
  zx_pop_seen(pop_seen);
#else
  /* root node has no end tag either */
#endif
  ENC_LEN_DEBUG(x, "dap:TestOp", p-enc_base);
  return p;
}

/* FUNC(zx_ENC_WO_dap_TestOp) */

/* Render element into string. The XML attributes and elements are
 * processed in wire order by chasing wo pointers. This is what you want for
 * validating signatures on other people's XML documents. */

/* Called by: */
char* zx_ENC_WO_dap_TestOp(struct zx_ctx* c, struct zx_dap_TestOp_s* x, char* p )
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
  ZX_OUT_MEM(p, "TestOp", sizeof("TestOp")-1);
  qq = p;

  /* *** sort the namespaces */
  if (c->inc_ns)
    zx_add_inc_ns(c, &pop_seen);
  zx_add_xmlns_if_not_seen(c, x->gg.g.ns, &pop_seen);

  p = zx_enc_seen(p, pop_seen); 
  p = zx_attr_wo_enc(p, x->attributes, "attributes=\"", sizeof("attributes=\"")-1);
  p = zx_attr_wo_enc(p, x->derefaliases, "derefaliases=\"", sizeof("derefaliases=\"")-1);
  p = zx_attr_wo_enc(p, x->scope, "scope=\"", sizeof("scope=\"")-1);
  p = zx_attr_wo_enc(p, x->sizelimit, "sizelimit=\"", sizeof("sizelimit=\"")-1);
  p = zx_attr_wo_enc(p, x->timelimit, "timelimit=\"", sizeof("timelimit=\"")-1);
  p = zx_attr_wo_enc(p, x->typesonly, "typesonly=\"", sizeof("typesonly=\"")-1);

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
  ENC_LEN_DEBUG(x, "dap:TestOp", p-enc_base);
  return p;
}

/* FUNC(zx_EASY_ENC_SO_dap_TestOp) */

/* Called by: */
struct zx_str* zx_EASY_ENC_SO_dap_TestOp(struct zx_ctx* c, struct zx_dap_TestOp_s* x )
{
  int len;
  char* buf;
  c->ns_tab = ZX_ALLOC(c, sizeof(zx_ns_tab));
  memcpy(c->ns_tab, zx_ns_tab, sizeof(zx_ns_tab));
  len = zx_LEN_SO_dap_TestOp(c, x );
  buf = ZX_ALLOC(c, len+1);
  return zx_easy_enc_common(c, zx_ENC_SO_dap_TestOp(c, x, buf ), buf, len);
}

/* FUNC(zx_EASY_ENC_WO_dap_TestOp) */

/* Called by: */
struct zx_str* zx_EASY_ENC_WO_dap_TestOp(struct zx_ctx* c, struct zx_dap_TestOp_s* x )
{
  int len;
  char* buf;
  c->ns_tab = ZX_ALLOC(c, sizeof(zx_ns_tab));
  memcpy(c->ns_tab, zx_ns_tab, sizeof(zx_ns_tab));
  len = zx_LEN_WO_dap_TestOp(c, x );
  buf = ZX_ALLOC(c, len+1);
  return zx_easy_enc_common(c, zx_ENC_WO_dap_TestOp(c, x, buf ), buf, len);
}




/* EOF -- c/zx-dap-enc.c */
