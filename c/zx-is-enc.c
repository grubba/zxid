/* c/zx-is-enc.c - WARNING: This file was automatically generated. DO NOT EDIT!
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
#include "c/zx-is-data.h"
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

#define EL_NAME   is_Confirm
#define EL_STRUCT zx_is_Confirm_s
#define EL_NS     is
#define EL_TAG    Confirm

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

/* FUNC(zx_LEN_SO_is_Confirm) */

/* Compute length of an element (and its subelements). The XML attributes
 * and elements are processed in schema order. */

/* Called by: */
int zx_LEN_SO_is_Confirm(struct zx_ctx* c, struct zx_is_Confirm_s* x )
{
  struct zx_ns_s* pop_seen = 0;
  struct zx_elem_s* se MAYBE_UNUSED;
#if 1 /* NORMALMODE */
  /* *** in simple_elem case should output ns prefix from ns node. */
  int len = sizeof("<is:Confirm")-1 + 1 + sizeof("</is:Confirm>")-1;
  if (c->inc_ns_len)
    len += zx_len_inc_ns(c, &pop_seen);
  len += zx_len_xmlns_if_not_seen(c, zx_ns_tab+zx_xmlns_ix_is, &pop_seen);

  len += zx_attr_so_len(c, x->name, sizeof("name")-1, &pop_seen);

#else
  /* root node has no begin tag */
  int len = 0;
#endif
  
  {
      struct zx_is_Help_s* e;
      for (e = x->Help; e; e = (struct zx_is_Help_s*)e->gg.g.n)
	  len += zx_LEN_SO_is_Help(c, e);
  }
  for (se = x->Hint; se; se = (struct zx_elem_s*)se->g.n)
    len += zx_LEN_SO_simple_elem(c,se, sizeof("is:Hint")-1, zx_ns_tab+zx_xmlns_ix_is);
  for (se = x->Label; se; se = (struct zx_elem_s*)se->g.n)
    len += zx_LEN_SO_simple_elem(c,se, sizeof("is:Label")-1, zx_ns_tab+zx_xmlns_ix_is);
  for (se = x->Value; se; se = (struct zx_elem_s*)se->g.n)
    len += zx_LEN_SO_simple_elem(c,se, sizeof("is:Value")-1, zx_ns_tab+zx_xmlns_ix_is);


  len += zx_len_so_common(c, &x->gg, &pop_seen);
  zx_pop_seen(pop_seen);
  ENC_LEN_DEBUG(x, "is:Confirm", len);
  return len;
}

/* FUNC(zx_LEN_WO_is_Confirm) */

/* Compute length of an element (and its subelements). The XML attributes
 * and elements are processed in wire order and no assumptions
 * are made about namespace prefixes. */

/* Called by: */
int zx_LEN_WO_is_Confirm(struct zx_ctx* c, struct zx_is_Confirm_s* x )
{
  struct zx_ns_s* pop_seen = 0;
  struct zx_elem_s* se MAYBE_UNUSED;
#if 1 /* NORMALMODE */
  int len = 1 + sizeof("Confirm")-1 + 1 + 2 + sizeof("Confirm")-1 + 1;
  
  if (x->gg.g.ns && x->gg.g.ns->prefix_len)
    len += (x->gg.g.ns->prefix_len + 1) * 2;
  if (c->inc_ns_len)
    len += zx_len_inc_ns(c, &pop_seen);
  len += zx_len_xmlns_if_not_seen(c, x->gg.g.ns, &pop_seen);

  len += zx_attr_wo_len(c, x->name, sizeof("name")-1, &pop_seen);

#else
  /* root node has no begin tag */
  int len = 0;
#endif
  
  {
      struct zx_is_Help_s* e;
      for (e = x->Help; e; e = (struct zx_is_Help_s*)e->gg.g.n)
	  len += zx_LEN_WO_is_Help(c, e);
  }
  for (se = x->Hint; se; se = (struct zx_elem_s*)se->g.n)
    len += zx_LEN_WO_simple_elem(c, se, sizeof("Hint")-1);
  for (se = x->Label; se; se = (struct zx_elem_s*)se->g.n)
    len += zx_LEN_WO_simple_elem(c, se, sizeof("Label")-1);
  for (se = x->Value; se; se = (struct zx_elem_s*)se->g.n)
    len += zx_LEN_WO_simple_elem(c, se, sizeof("Value")-1);


  len += zx_len_wo_common(c, &x->gg, &pop_seen); 
  zx_pop_seen(pop_seen);
  ENC_LEN_DEBUG(x, "is:Confirm", len);
  return len;
}

/* FUNC(zx_ENC_SO_is_Confirm) */

/* Render element into string. The XML attributes and elements are
 * processed in schema order. This is what you generally want for
 * rendering new data structure to a string. The wo pointers are not used. */

/* Called by: */
char* zx_ENC_SO_is_Confirm(struct zx_ctx* c, struct zx_is_Confirm_s* x, char* p )
{
  struct zx_elem_s* se MAYBE_UNUSED;
  struct zx_ns_s* pop_seen = 0;
  ENC_LEN_DEBUG_BASE;
#if 1 /* NORMALMODE */
  /* *** in simple_elem case should output ns prefix from ns node. */
  ZX_OUT_TAG(p, "<is:Confirm");
  if (c->inc_ns)
    zx_add_inc_ns(c, &pop_seen);
  zx_add_xmlns_if_not_seen(c, zx_ns_tab+zx_xmlns_ix_is, &pop_seen);

  zx_see_unknown_attrs_ns(c, x->gg.any_attr, &pop_seen);
  p = zx_enc_seen(p, pop_seen); 
  p = zx_attr_so_enc(p, x->name, " name=\"", sizeof(" name=\"")-1);

  p = zx_enc_unknown_attrs(p, x->gg.any_attr);
#else
  /* root node has no begin tag */
#endif
  
  {
      struct zx_is_Help_s* e;
      for (e = x->Help; e; e = (struct zx_is_Help_s*)e->gg.g.n)
	  p = zx_ENC_SO_is_Help(c, e, p);
  }
  for (se = x->Hint; se; se = (struct zx_elem_s*)se->g.n)
    p = zx_ENC_SO_simple_elem(c, se, p, "is:Hint", sizeof("is:Hint")-1, zx_ns_tab+zx_xmlns_ix_is);
  for (se = x->Label; se; se = (struct zx_elem_s*)se->g.n)
    p = zx_ENC_SO_simple_elem(c, se, p, "is:Label", sizeof("is:Label")-1, zx_ns_tab+zx_xmlns_ix_is);
  for (se = x->Value; se; se = (struct zx_elem_s*)se->g.n)
    p = zx_ENC_SO_simple_elem(c, se, p, "is:Value", sizeof("is:Value")-1, zx_ns_tab+zx_xmlns_ix_is);

  p = zx_enc_so_unknown_elems_and_content(c, p, &x->gg);
  
#if 1 /* NORMALMODE */
  ZX_OUT_CLOSE_TAG(p, "</is:Confirm>");
  zx_pop_seen(pop_seen);
#else
  /* root node has no end tag either */
#endif
  ENC_LEN_DEBUG(x, "is:Confirm", p-enc_base);
  return p;
}

/* FUNC(zx_ENC_WO_is_Confirm) */

/* Render element into string. The XML attributes and elements are
 * processed in wire order by chasing wo pointers. This is what you want for
 * validating signatures on other people's XML documents. */

/* Called by: */
char* zx_ENC_WO_is_Confirm(struct zx_ctx* c, struct zx_is_Confirm_s* x, char* p )
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
  ZX_OUT_MEM(p, "Confirm", sizeof("Confirm")-1);
  qq = p;

  if (c->inc_ns)
    zx_add_inc_ns(c, &pop_seen);
  zx_add_xmlns_if_not_seen(c, x->gg.g.ns, &pop_seen);

  zx_see_unknown_attrs_ns(c, x->gg.any_attr, &pop_seen);
  p = zx_enc_seen(p, pop_seen); 
  p = zx_attr_wo_enc(p, x->name, "name=\"", sizeof("name=\"")-1);

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
  ENC_LEN_DEBUG(x, "is:Confirm", p-enc_base);
  return p;
}

/* FUNC(zx_EASY_ENC_SO_is_Confirm) */

/* Called by: */
struct zx_str* zx_EASY_ENC_SO_is_Confirm(struct zx_ctx* c, struct zx_is_Confirm_s* x )
{
  int len;
  char* buf;
  c->ns_tab = ZX_ALLOC(c, sizeof(zx_ns_tab));
  memcpy(c->ns_tab, zx_ns_tab, sizeof(zx_ns_tab));
  len = zx_LEN_SO_is_Confirm(c, x );
  buf = ZX_ALLOC(c, len+1);
  return zx_easy_enc_common(c, zx_ENC_SO_is_Confirm(c, x, buf ), buf, len);
}

/* FUNC(zx_EASY_ENC_WO_is_Confirm) */

/* Called by: */
struct zx_str* zx_EASY_ENC_WO_is_Confirm(struct zx_ctx* c, struct zx_is_Confirm_s* x )
{
  int len;
  char* buf;
  c->ns_tab = ZX_ALLOC(c, sizeof(zx_ns_tab));
  memcpy(c->ns_tab, zx_ns_tab, sizeof(zx_ns_tab));
  len = zx_LEN_WO_is_Confirm(c, x );
  buf = ZX_ALLOC(c, len+1);
  return zx_easy_enc_common(c, zx_ENC_WO_is_Confirm(c, x, buf ), buf, len);
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

#define EL_NAME   is_Help
#define EL_STRUCT zx_is_Help_s
#define EL_NS     is
#define EL_TAG    Help

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

/* FUNC(zx_LEN_SO_is_Help) */

/* Compute length of an element (and its subelements). The XML attributes
 * and elements are processed in schema order. */

/* Called by: */
int zx_LEN_SO_is_Help(struct zx_ctx* c, struct zx_is_Help_s* x )
{
  struct zx_ns_s* pop_seen = 0;
  struct zx_elem_s* se MAYBE_UNUSED;
#if 1 /* NORMALMODE */
  /* *** in simple_elem case should output ns prefix from ns node. */
  int len = sizeof("<is:Help")-1 + 1 + sizeof("</is:Help>")-1;
  if (c->inc_ns_len)
    len += zx_len_inc_ns(c, &pop_seen);
  len += zx_len_xmlns_if_not_seen(c, zx_ns_tab+zx_xmlns_ix_is, &pop_seen);

  len += zx_attr_so_len(c, x->label, sizeof("label")-1, &pop_seen);
  len += zx_attr_so_len(c, x->link, sizeof("link")-1, &pop_seen);
  len += zx_attr_so_len(c, x->moreLink, sizeof("moreLink")-1, &pop_seen);

#else
  /* root node has no begin tag */
  int len = 0;
#endif
  


  len += zx_len_so_common(c, &x->gg, &pop_seen);
  zx_pop_seen(pop_seen);
  ENC_LEN_DEBUG(x, "is:Help", len);
  return len;
}

/* FUNC(zx_LEN_WO_is_Help) */

/* Compute length of an element (and its subelements). The XML attributes
 * and elements are processed in wire order and no assumptions
 * are made about namespace prefixes. */

/* Called by: */
int zx_LEN_WO_is_Help(struct zx_ctx* c, struct zx_is_Help_s* x )
{
  struct zx_ns_s* pop_seen = 0;
  struct zx_elem_s* se MAYBE_UNUSED;
#if 1 /* NORMALMODE */
  int len = 1 + sizeof("Help")-1 + 1 + 2 + sizeof("Help")-1 + 1;
  
  if (x->gg.g.ns && x->gg.g.ns->prefix_len)
    len += (x->gg.g.ns->prefix_len + 1) * 2;
  if (c->inc_ns_len)
    len += zx_len_inc_ns(c, &pop_seen);
  len += zx_len_xmlns_if_not_seen(c, x->gg.g.ns, &pop_seen);

  len += zx_attr_wo_len(c, x->label, sizeof("label")-1, &pop_seen);
  len += zx_attr_wo_len(c, x->link, sizeof("link")-1, &pop_seen);
  len += zx_attr_wo_len(c, x->moreLink, sizeof("moreLink")-1, &pop_seen);

#else
  /* root node has no begin tag */
  int len = 0;
#endif
  


  len += zx_len_wo_common(c, &x->gg, &pop_seen); 
  zx_pop_seen(pop_seen);
  ENC_LEN_DEBUG(x, "is:Help", len);
  return len;
}

/* FUNC(zx_ENC_SO_is_Help) */

/* Render element into string. The XML attributes and elements are
 * processed in schema order. This is what you generally want for
 * rendering new data structure to a string. The wo pointers are not used. */

/* Called by: */
char* zx_ENC_SO_is_Help(struct zx_ctx* c, struct zx_is_Help_s* x, char* p )
{
  struct zx_elem_s* se MAYBE_UNUSED;
  struct zx_ns_s* pop_seen = 0;
  ENC_LEN_DEBUG_BASE;
#if 1 /* NORMALMODE */
  /* *** in simple_elem case should output ns prefix from ns node. */
  ZX_OUT_TAG(p, "<is:Help");
  if (c->inc_ns)
    zx_add_inc_ns(c, &pop_seen);
  zx_add_xmlns_if_not_seen(c, zx_ns_tab+zx_xmlns_ix_is, &pop_seen);

  zx_see_unknown_attrs_ns(c, x->gg.any_attr, &pop_seen);
  p = zx_enc_seen(p, pop_seen); 
  p = zx_attr_so_enc(p, x->label, " label=\"", sizeof(" label=\"")-1);
  p = zx_attr_so_enc(p, x->link, " link=\"", sizeof(" link=\"")-1);
  p = zx_attr_so_enc(p, x->moreLink, " moreLink=\"", sizeof(" moreLink=\"")-1);

  p = zx_enc_unknown_attrs(p, x->gg.any_attr);
#else
  /* root node has no begin tag */
#endif
  

  p = zx_enc_so_unknown_elems_and_content(c, p, &x->gg);
  
#if 1 /* NORMALMODE */
  ZX_OUT_CLOSE_TAG(p, "</is:Help>");
  zx_pop_seen(pop_seen);
#else
  /* root node has no end tag either */
#endif
  ENC_LEN_DEBUG(x, "is:Help", p-enc_base);
  return p;
}

/* FUNC(zx_ENC_WO_is_Help) */

/* Render element into string. The XML attributes and elements are
 * processed in wire order by chasing wo pointers. This is what you want for
 * validating signatures on other people's XML documents. */

/* Called by: */
char* zx_ENC_WO_is_Help(struct zx_ctx* c, struct zx_is_Help_s* x, char* p )
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
  ZX_OUT_MEM(p, "Help", sizeof("Help")-1);
  qq = p;

  if (c->inc_ns)
    zx_add_inc_ns(c, &pop_seen);
  zx_add_xmlns_if_not_seen(c, x->gg.g.ns, &pop_seen);

  zx_see_unknown_attrs_ns(c, x->gg.any_attr, &pop_seen);
  p = zx_enc_seen(p, pop_seen); 
  p = zx_attr_wo_enc(p, x->label, "label=\"", sizeof("label=\"")-1);
  p = zx_attr_wo_enc(p, x->link, "link=\"", sizeof("link=\"")-1);
  p = zx_attr_wo_enc(p, x->moreLink, "moreLink=\"", sizeof("moreLink=\"")-1);

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
  ENC_LEN_DEBUG(x, "is:Help", p-enc_base);
  return p;
}

/* FUNC(zx_EASY_ENC_SO_is_Help) */

/* Called by: */
struct zx_str* zx_EASY_ENC_SO_is_Help(struct zx_ctx* c, struct zx_is_Help_s* x )
{
  int len;
  char* buf;
  c->ns_tab = ZX_ALLOC(c, sizeof(zx_ns_tab));
  memcpy(c->ns_tab, zx_ns_tab, sizeof(zx_ns_tab));
  len = zx_LEN_SO_is_Help(c, x );
  buf = ZX_ALLOC(c, len+1);
  return zx_easy_enc_common(c, zx_ENC_SO_is_Help(c, x, buf ), buf, len);
}

/* FUNC(zx_EASY_ENC_WO_is_Help) */

/* Called by: */
struct zx_str* zx_EASY_ENC_WO_is_Help(struct zx_ctx* c, struct zx_is_Help_s* x )
{
  int len;
  char* buf;
  c->ns_tab = ZX_ALLOC(c, sizeof(zx_ns_tab));
  memcpy(c->ns_tab, zx_ns_tab, sizeof(zx_ns_tab));
  len = zx_LEN_WO_is_Help(c, x );
  buf = ZX_ALLOC(c, len+1);
  return zx_easy_enc_common(c, zx_ENC_WO_is_Help(c, x, buf ), buf, len);
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

#define EL_NAME   is_Inquiry
#define EL_STRUCT zx_is_Inquiry_s
#define EL_NS     is
#define EL_TAG    Inquiry

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

/* FUNC(zx_LEN_SO_is_Inquiry) */

/* Compute length of an element (and its subelements). The XML attributes
 * and elements are processed in schema order. */

/* Called by: */
int zx_LEN_SO_is_Inquiry(struct zx_ctx* c, struct zx_is_Inquiry_s* x )
{
  struct zx_ns_s* pop_seen = 0;
  struct zx_elem_s* se MAYBE_UNUSED;
#if 1 /* NORMALMODE */
  /* *** in simple_elem case should output ns prefix from ns node. */
  int len = sizeof("<is:Inquiry")-1 + 1 + sizeof("</is:Inquiry>")-1;
  if (c->inc_ns_len)
    len += zx_len_inc_ns(c, &pop_seen);
  len += zx_len_xmlns_if_not_seen(c, zx_ns_tab+zx_xmlns_ix_is, &pop_seen);

  len += zx_attr_so_len(c, x->id, sizeof("id")-1, &pop_seen);
  len += zx_attr_so_len(c, x->title, sizeof("title")-1, &pop_seen);

#else
  /* root node has no begin tag */
  int len = 0;
#endif
  
  {
      struct zx_is_Help_s* e;
      for (e = x->Help; e; e = (struct zx_is_Help_s*)e->gg.g.n)
	  len += zx_LEN_SO_is_Help(c, e);
  }
  {
      struct zx_is_Select_s* e;
      for (e = x->Select; e; e = (struct zx_is_Select_s*)e->gg.g.n)
	  len += zx_LEN_SO_is_Select(c, e);
  }
  {
      struct zx_is_Confirm_s* e;
      for (e = x->Confirm; e; e = (struct zx_is_Confirm_s*)e->gg.g.n)
	  len += zx_LEN_SO_is_Confirm(c, e);
  }
  {
      struct zx_is_Text_s* e;
      for (e = x->Text; e; e = (struct zx_is_Text_s*)e->gg.g.n)
	  len += zx_LEN_SO_is_Text(c, e);
  }


  len += zx_len_so_common(c, &x->gg, &pop_seen);
  zx_pop_seen(pop_seen);
  ENC_LEN_DEBUG(x, "is:Inquiry", len);
  return len;
}

/* FUNC(zx_LEN_WO_is_Inquiry) */

/* Compute length of an element (and its subelements). The XML attributes
 * and elements are processed in wire order and no assumptions
 * are made about namespace prefixes. */

/* Called by: */
int zx_LEN_WO_is_Inquiry(struct zx_ctx* c, struct zx_is_Inquiry_s* x )
{
  struct zx_ns_s* pop_seen = 0;
  struct zx_elem_s* se MAYBE_UNUSED;
#if 1 /* NORMALMODE */
  int len = 1 + sizeof("Inquiry")-1 + 1 + 2 + sizeof("Inquiry")-1 + 1;
  
  if (x->gg.g.ns && x->gg.g.ns->prefix_len)
    len += (x->gg.g.ns->prefix_len + 1) * 2;
  if (c->inc_ns_len)
    len += zx_len_inc_ns(c, &pop_seen);
  len += zx_len_xmlns_if_not_seen(c, x->gg.g.ns, &pop_seen);

  len += zx_attr_wo_len(c, x->id, sizeof("id")-1, &pop_seen);
  len += zx_attr_wo_len(c, x->title, sizeof("title")-1, &pop_seen);

#else
  /* root node has no begin tag */
  int len = 0;
#endif
  
  {
      struct zx_is_Help_s* e;
      for (e = x->Help; e; e = (struct zx_is_Help_s*)e->gg.g.n)
	  len += zx_LEN_WO_is_Help(c, e);
  }
  {
      struct zx_is_Select_s* e;
      for (e = x->Select; e; e = (struct zx_is_Select_s*)e->gg.g.n)
	  len += zx_LEN_WO_is_Select(c, e);
  }
  {
      struct zx_is_Confirm_s* e;
      for (e = x->Confirm; e; e = (struct zx_is_Confirm_s*)e->gg.g.n)
	  len += zx_LEN_WO_is_Confirm(c, e);
  }
  {
      struct zx_is_Text_s* e;
      for (e = x->Text; e; e = (struct zx_is_Text_s*)e->gg.g.n)
	  len += zx_LEN_WO_is_Text(c, e);
  }


  len += zx_len_wo_common(c, &x->gg, &pop_seen); 
  zx_pop_seen(pop_seen);
  ENC_LEN_DEBUG(x, "is:Inquiry", len);
  return len;
}

/* FUNC(zx_ENC_SO_is_Inquiry) */

/* Render element into string. The XML attributes and elements are
 * processed in schema order. This is what you generally want for
 * rendering new data structure to a string. The wo pointers are not used. */

/* Called by: */
char* zx_ENC_SO_is_Inquiry(struct zx_ctx* c, struct zx_is_Inquiry_s* x, char* p )
{
  struct zx_elem_s* se MAYBE_UNUSED;
  struct zx_ns_s* pop_seen = 0;
  ENC_LEN_DEBUG_BASE;
#if 1 /* NORMALMODE */
  /* *** in simple_elem case should output ns prefix from ns node. */
  ZX_OUT_TAG(p, "<is:Inquiry");
  if (c->inc_ns)
    zx_add_inc_ns(c, &pop_seen);
  zx_add_xmlns_if_not_seen(c, zx_ns_tab+zx_xmlns_ix_is, &pop_seen);

  zx_see_unknown_attrs_ns(c, x->gg.any_attr, &pop_seen);
  p = zx_enc_seen(p, pop_seen); 
  p = zx_attr_so_enc(p, x->id, " id=\"", sizeof(" id=\"")-1);
  p = zx_attr_so_enc(p, x->title, " title=\"", sizeof(" title=\"")-1);

  p = zx_enc_unknown_attrs(p, x->gg.any_attr);
#else
  /* root node has no begin tag */
#endif
  
  {
      struct zx_is_Help_s* e;
      for (e = x->Help; e; e = (struct zx_is_Help_s*)e->gg.g.n)
	  p = zx_ENC_SO_is_Help(c, e, p);
  }
  {
      struct zx_is_Select_s* e;
      for (e = x->Select; e; e = (struct zx_is_Select_s*)e->gg.g.n)
	  p = zx_ENC_SO_is_Select(c, e, p);
  }
  {
      struct zx_is_Confirm_s* e;
      for (e = x->Confirm; e; e = (struct zx_is_Confirm_s*)e->gg.g.n)
	  p = zx_ENC_SO_is_Confirm(c, e, p);
  }
  {
      struct zx_is_Text_s* e;
      for (e = x->Text; e; e = (struct zx_is_Text_s*)e->gg.g.n)
	  p = zx_ENC_SO_is_Text(c, e, p);
  }

  p = zx_enc_so_unknown_elems_and_content(c, p, &x->gg);
  
#if 1 /* NORMALMODE */
  ZX_OUT_CLOSE_TAG(p, "</is:Inquiry>");
  zx_pop_seen(pop_seen);
#else
  /* root node has no end tag either */
#endif
  ENC_LEN_DEBUG(x, "is:Inquiry", p-enc_base);
  return p;
}

/* FUNC(zx_ENC_WO_is_Inquiry) */

/* Render element into string. The XML attributes and elements are
 * processed in wire order by chasing wo pointers. This is what you want for
 * validating signatures on other people's XML documents. */

/* Called by: */
char* zx_ENC_WO_is_Inquiry(struct zx_ctx* c, struct zx_is_Inquiry_s* x, char* p )
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
  ZX_OUT_MEM(p, "Inquiry", sizeof("Inquiry")-1);
  qq = p;

  if (c->inc_ns)
    zx_add_inc_ns(c, &pop_seen);
  zx_add_xmlns_if_not_seen(c, x->gg.g.ns, &pop_seen);

  zx_see_unknown_attrs_ns(c, x->gg.any_attr, &pop_seen);
  p = zx_enc_seen(p, pop_seen); 
  p = zx_attr_wo_enc(p, x->id, "id=\"", sizeof("id=\"")-1);
  p = zx_attr_wo_enc(p, x->title, "title=\"", sizeof("title=\"")-1);

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
  ENC_LEN_DEBUG(x, "is:Inquiry", p-enc_base);
  return p;
}

/* FUNC(zx_EASY_ENC_SO_is_Inquiry) */

/* Called by: */
struct zx_str* zx_EASY_ENC_SO_is_Inquiry(struct zx_ctx* c, struct zx_is_Inquiry_s* x )
{
  int len;
  char* buf;
  c->ns_tab = ZX_ALLOC(c, sizeof(zx_ns_tab));
  memcpy(c->ns_tab, zx_ns_tab, sizeof(zx_ns_tab));
  len = zx_LEN_SO_is_Inquiry(c, x );
  buf = ZX_ALLOC(c, len+1);
  return zx_easy_enc_common(c, zx_ENC_SO_is_Inquiry(c, x, buf ), buf, len);
}

/* FUNC(zx_EASY_ENC_WO_is_Inquiry) */

/* Called by: */
struct zx_str* zx_EASY_ENC_WO_is_Inquiry(struct zx_ctx* c, struct zx_is_Inquiry_s* x )
{
  int len;
  char* buf;
  c->ns_tab = ZX_ALLOC(c, sizeof(zx_ns_tab));
  memcpy(c->ns_tab, zx_ns_tab, sizeof(zx_ns_tab));
  len = zx_LEN_WO_is_Inquiry(c, x );
  buf = ZX_ALLOC(c, len+1);
  return zx_easy_enc_common(c, zx_ENC_WO_is_Inquiry(c, x, buf ), buf, len);
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

#define EL_NAME   is_InteractionRequest
#define EL_STRUCT zx_is_InteractionRequest_s
#define EL_NS     is
#define EL_TAG    InteractionRequest

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

/* FUNC(zx_LEN_SO_is_InteractionRequest) */

/* Compute length of an element (and its subelements). The XML attributes
 * and elements are processed in schema order. */

/* Called by: */
int zx_LEN_SO_is_InteractionRequest(struct zx_ctx* c, struct zx_is_InteractionRequest_s* x )
{
  struct zx_ns_s* pop_seen = 0;
  struct zx_elem_s* se MAYBE_UNUSED;
#if 1 /* NORMALMODE */
  /* *** in simple_elem case should output ns prefix from ns node. */
  int len = sizeof("<is:InteractionRequest")-1 + 1 + sizeof("</is:InteractionRequest>")-1;
  if (c->inc_ns_len)
    len += zx_len_inc_ns(c, &pop_seen);
  len += zx_len_xmlns_if_not_seen(c, zx_ns_tab+zx_xmlns_ix_is, &pop_seen);

  len += zx_attr_so_len(c, x->id, sizeof("id")-1, &pop_seen);
  len += zx_attr_so_len(c, x->language, sizeof("language")-1, &pop_seen);
  len += zx_attr_so_len(c, x->maxInteractTime, sizeof("maxInteractTime")-1, &pop_seen);
  len += zx_attr_so_len(c, x->signed_is_c_keyword, sizeof("signed")-1, &pop_seen);

#else
  /* root node has no begin tag */
  int len = 0;
#endif
  
  {
      struct zx_is_Inquiry_s* e;
      for (e = x->Inquiry; e; e = (struct zx_is_Inquiry_s*)e->gg.g.n)
	  len += zx_LEN_SO_is_Inquiry(c, e);
  }
  {
      struct zx_ds_KeyInfo_s* e;
      for (e = x->KeyInfo; e; e = (struct zx_ds_KeyInfo_s*)e->gg.g.n)
	  len += zx_LEN_SO_ds_KeyInfo(c, e);
  }


  len += zx_len_so_common(c, &x->gg, &pop_seen);
  zx_pop_seen(pop_seen);
  ENC_LEN_DEBUG(x, "is:InteractionRequest", len);
  return len;
}

/* FUNC(zx_LEN_WO_is_InteractionRequest) */

/* Compute length of an element (and its subelements). The XML attributes
 * and elements are processed in wire order and no assumptions
 * are made about namespace prefixes. */

/* Called by: */
int zx_LEN_WO_is_InteractionRequest(struct zx_ctx* c, struct zx_is_InteractionRequest_s* x )
{
  struct zx_ns_s* pop_seen = 0;
  struct zx_elem_s* se MAYBE_UNUSED;
#if 1 /* NORMALMODE */
  int len = 1 + sizeof("InteractionRequest")-1 + 1 + 2 + sizeof("InteractionRequest")-1 + 1;
  
  if (x->gg.g.ns && x->gg.g.ns->prefix_len)
    len += (x->gg.g.ns->prefix_len + 1) * 2;
  if (c->inc_ns_len)
    len += zx_len_inc_ns(c, &pop_seen);
  len += zx_len_xmlns_if_not_seen(c, x->gg.g.ns, &pop_seen);

  len += zx_attr_wo_len(c, x->id, sizeof("id")-1, &pop_seen);
  len += zx_attr_wo_len(c, x->language, sizeof("language")-1, &pop_seen);
  len += zx_attr_wo_len(c, x->maxInteractTime, sizeof("maxInteractTime")-1, &pop_seen);
  len += zx_attr_wo_len(c, x->signed_is_c_keyword, sizeof("signed")-1, &pop_seen);

#else
  /* root node has no begin tag */
  int len = 0;
#endif
  
  {
      struct zx_is_Inquiry_s* e;
      for (e = x->Inquiry; e; e = (struct zx_is_Inquiry_s*)e->gg.g.n)
	  len += zx_LEN_WO_is_Inquiry(c, e);
  }
  {
      struct zx_ds_KeyInfo_s* e;
      for (e = x->KeyInfo; e; e = (struct zx_ds_KeyInfo_s*)e->gg.g.n)
	  len += zx_LEN_WO_ds_KeyInfo(c, e);
  }


  len += zx_len_wo_common(c, &x->gg, &pop_seen); 
  zx_pop_seen(pop_seen);
  ENC_LEN_DEBUG(x, "is:InteractionRequest", len);
  return len;
}

/* FUNC(zx_ENC_SO_is_InteractionRequest) */

/* Render element into string. The XML attributes and elements are
 * processed in schema order. This is what you generally want for
 * rendering new data structure to a string. The wo pointers are not used. */

/* Called by: */
char* zx_ENC_SO_is_InteractionRequest(struct zx_ctx* c, struct zx_is_InteractionRequest_s* x, char* p )
{
  struct zx_elem_s* se MAYBE_UNUSED;
  struct zx_ns_s* pop_seen = 0;
  ENC_LEN_DEBUG_BASE;
#if 1 /* NORMALMODE */
  /* *** in simple_elem case should output ns prefix from ns node. */
  ZX_OUT_TAG(p, "<is:InteractionRequest");
  if (c->inc_ns)
    zx_add_inc_ns(c, &pop_seen);
  zx_add_xmlns_if_not_seen(c, zx_ns_tab+zx_xmlns_ix_is, &pop_seen);

  zx_see_unknown_attrs_ns(c, x->gg.any_attr, &pop_seen);
  p = zx_enc_seen(p, pop_seen); 
  p = zx_attr_so_enc(p, x->id, " id=\"", sizeof(" id=\"")-1);
  p = zx_attr_so_enc(p, x->language, " language=\"", sizeof(" language=\"")-1);
  p = zx_attr_so_enc(p, x->maxInteractTime, " maxInteractTime=\"", sizeof(" maxInteractTime=\"")-1);
  p = zx_attr_so_enc(p, x->signed_is_c_keyword, " signed=\"", sizeof(" signed=\"")-1);

  p = zx_enc_unknown_attrs(p, x->gg.any_attr);
#else
  /* root node has no begin tag */
#endif
  
  {
      struct zx_is_Inquiry_s* e;
      for (e = x->Inquiry; e; e = (struct zx_is_Inquiry_s*)e->gg.g.n)
	  p = zx_ENC_SO_is_Inquiry(c, e, p);
  }
  {
      struct zx_ds_KeyInfo_s* e;
      for (e = x->KeyInfo; e; e = (struct zx_ds_KeyInfo_s*)e->gg.g.n)
	  p = zx_ENC_SO_ds_KeyInfo(c, e, p);
  }

  p = zx_enc_so_unknown_elems_and_content(c, p, &x->gg);
  
#if 1 /* NORMALMODE */
  ZX_OUT_CLOSE_TAG(p, "</is:InteractionRequest>");
  zx_pop_seen(pop_seen);
#else
  /* root node has no end tag either */
#endif
  ENC_LEN_DEBUG(x, "is:InteractionRequest", p-enc_base);
  return p;
}

/* FUNC(zx_ENC_WO_is_InteractionRequest) */

/* Render element into string. The XML attributes and elements are
 * processed in wire order by chasing wo pointers. This is what you want for
 * validating signatures on other people's XML documents. */

/* Called by: */
char* zx_ENC_WO_is_InteractionRequest(struct zx_ctx* c, struct zx_is_InteractionRequest_s* x, char* p )
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
  ZX_OUT_MEM(p, "InteractionRequest", sizeof("InteractionRequest")-1);
  qq = p;

  if (c->inc_ns)
    zx_add_inc_ns(c, &pop_seen);
  zx_add_xmlns_if_not_seen(c, x->gg.g.ns, &pop_seen);

  zx_see_unknown_attrs_ns(c, x->gg.any_attr, &pop_seen);
  p = zx_enc_seen(p, pop_seen); 
  p = zx_attr_wo_enc(p, x->id, "id=\"", sizeof("id=\"")-1);
  p = zx_attr_wo_enc(p, x->language, "language=\"", sizeof("language=\"")-1);
  p = zx_attr_wo_enc(p, x->maxInteractTime, "maxInteractTime=\"", sizeof("maxInteractTime=\"")-1);
  p = zx_attr_wo_enc(p, x->signed_is_c_keyword, "signed=\"", sizeof("signed=\"")-1);

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
  ENC_LEN_DEBUG(x, "is:InteractionRequest", p-enc_base);
  return p;
}

/* FUNC(zx_EASY_ENC_SO_is_InteractionRequest) */

/* Called by: */
struct zx_str* zx_EASY_ENC_SO_is_InteractionRequest(struct zx_ctx* c, struct zx_is_InteractionRequest_s* x )
{
  int len;
  char* buf;
  c->ns_tab = ZX_ALLOC(c, sizeof(zx_ns_tab));
  memcpy(c->ns_tab, zx_ns_tab, sizeof(zx_ns_tab));
  len = zx_LEN_SO_is_InteractionRequest(c, x );
  buf = ZX_ALLOC(c, len+1);
  return zx_easy_enc_common(c, zx_ENC_SO_is_InteractionRequest(c, x, buf ), buf, len);
}

/* FUNC(zx_EASY_ENC_WO_is_InteractionRequest) */

/* Called by: */
struct zx_str* zx_EASY_ENC_WO_is_InteractionRequest(struct zx_ctx* c, struct zx_is_InteractionRequest_s* x )
{
  int len;
  char* buf;
  c->ns_tab = ZX_ALLOC(c, sizeof(zx_ns_tab));
  memcpy(c->ns_tab, zx_ns_tab, sizeof(zx_ns_tab));
  len = zx_LEN_WO_is_InteractionRequest(c, x );
  buf = ZX_ALLOC(c, len+1);
  return zx_easy_enc_common(c, zx_ENC_WO_is_InteractionRequest(c, x, buf ), buf, len);
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

#define EL_NAME   is_InteractionResponse
#define EL_STRUCT zx_is_InteractionResponse_s
#define EL_NS     is
#define EL_TAG    InteractionResponse

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

/* FUNC(zx_LEN_SO_is_InteractionResponse) */

/* Compute length of an element (and its subelements). The XML attributes
 * and elements are processed in schema order. */

/* Called by: */
int zx_LEN_SO_is_InteractionResponse(struct zx_ctx* c, struct zx_is_InteractionResponse_s* x )
{
  struct zx_ns_s* pop_seen = 0;
  struct zx_elem_s* se MAYBE_UNUSED;
#if 1 /* NORMALMODE */
  /* *** in simple_elem case should output ns prefix from ns node. */
  int len = sizeof("<is:InteractionResponse")-1 + 1 + sizeof("</is:InteractionResponse>")-1;
  if (c->inc_ns_len)
    len += zx_len_inc_ns(c, &pop_seen);
  len += zx_len_xmlns_if_not_seen(c, zx_ns_tab+zx_xmlns_ix_is, &pop_seen);


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
      struct zx_is_InteractionStatement_s* e;
      for (e = x->InteractionStatement; e; e = (struct zx_is_InteractionStatement_s*)e->gg.g.n)
	  len += zx_LEN_SO_is_InteractionStatement(c, e);
  }
  {
      struct zx_is_Parameter_s* e;
      for (e = x->Parameter; e; e = (struct zx_is_Parameter_s*)e->gg.g.n)
	  len += zx_LEN_SO_is_Parameter(c, e);
  }


  len += zx_len_so_common(c, &x->gg, &pop_seen);
  zx_pop_seen(pop_seen);
  ENC_LEN_DEBUG(x, "is:InteractionResponse", len);
  return len;
}

/* FUNC(zx_LEN_WO_is_InteractionResponse) */

/* Compute length of an element (and its subelements). The XML attributes
 * and elements are processed in wire order and no assumptions
 * are made about namespace prefixes. */

/* Called by: */
int zx_LEN_WO_is_InteractionResponse(struct zx_ctx* c, struct zx_is_InteractionResponse_s* x )
{
  struct zx_ns_s* pop_seen = 0;
  struct zx_elem_s* se MAYBE_UNUSED;
#if 1 /* NORMALMODE */
  int len = 1 + sizeof("InteractionResponse")-1 + 1 + 2 + sizeof("InteractionResponse")-1 + 1;
  
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
      struct zx_is_InteractionStatement_s* e;
      for (e = x->InteractionStatement; e; e = (struct zx_is_InteractionStatement_s*)e->gg.g.n)
	  len += zx_LEN_WO_is_InteractionStatement(c, e);
  }
  {
      struct zx_is_Parameter_s* e;
      for (e = x->Parameter; e; e = (struct zx_is_Parameter_s*)e->gg.g.n)
	  len += zx_LEN_WO_is_Parameter(c, e);
  }


  len += zx_len_wo_common(c, &x->gg, &pop_seen); 
  zx_pop_seen(pop_seen);
  ENC_LEN_DEBUG(x, "is:InteractionResponse", len);
  return len;
}

/* FUNC(zx_ENC_SO_is_InteractionResponse) */

/* Render element into string. The XML attributes and elements are
 * processed in schema order. This is what you generally want for
 * rendering new data structure to a string. The wo pointers are not used. */

/* Called by: */
char* zx_ENC_SO_is_InteractionResponse(struct zx_ctx* c, struct zx_is_InteractionResponse_s* x, char* p )
{
  struct zx_elem_s* se MAYBE_UNUSED;
  struct zx_ns_s* pop_seen = 0;
  ENC_LEN_DEBUG_BASE;
#if 1 /* NORMALMODE */
  /* *** in simple_elem case should output ns prefix from ns node. */
  ZX_OUT_TAG(p, "<is:InteractionResponse");
  if (c->inc_ns)
    zx_add_inc_ns(c, &pop_seen);
  zx_add_xmlns_if_not_seen(c, zx_ns_tab+zx_xmlns_ix_is, &pop_seen);

  zx_see_unknown_attrs_ns(c, x->gg.any_attr, &pop_seen);
  p = zx_enc_seen(p, pop_seen); 

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
      struct zx_is_InteractionStatement_s* e;
      for (e = x->InteractionStatement; e; e = (struct zx_is_InteractionStatement_s*)e->gg.g.n)
	  p = zx_ENC_SO_is_InteractionStatement(c, e, p);
  }
  {
      struct zx_is_Parameter_s* e;
      for (e = x->Parameter; e; e = (struct zx_is_Parameter_s*)e->gg.g.n)
	  p = zx_ENC_SO_is_Parameter(c, e, p);
  }

  p = zx_enc_so_unknown_elems_and_content(c, p, &x->gg);
  
#if 1 /* NORMALMODE */
  ZX_OUT_CLOSE_TAG(p, "</is:InteractionResponse>");
  zx_pop_seen(pop_seen);
#else
  /* root node has no end tag either */
#endif
  ENC_LEN_DEBUG(x, "is:InteractionResponse", p-enc_base);
  return p;
}

/* FUNC(zx_ENC_WO_is_InteractionResponse) */

/* Render element into string. The XML attributes and elements are
 * processed in wire order by chasing wo pointers. This is what you want for
 * validating signatures on other people's XML documents. */

/* Called by: */
char* zx_ENC_WO_is_InteractionResponse(struct zx_ctx* c, struct zx_is_InteractionResponse_s* x, char* p )
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
  ZX_OUT_MEM(p, "InteractionResponse", sizeof("InteractionResponse")-1);
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
  ENC_LEN_DEBUG(x, "is:InteractionResponse", p-enc_base);
  return p;
}

/* FUNC(zx_EASY_ENC_SO_is_InteractionResponse) */

/* Called by: */
struct zx_str* zx_EASY_ENC_SO_is_InteractionResponse(struct zx_ctx* c, struct zx_is_InteractionResponse_s* x )
{
  int len;
  char* buf;
  c->ns_tab = ZX_ALLOC(c, sizeof(zx_ns_tab));
  memcpy(c->ns_tab, zx_ns_tab, sizeof(zx_ns_tab));
  len = zx_LEN_SO_is_InteractionResponse(c, x );
  buf = ZX_ALLOC(c, len+1);
  return zx_easy_enc_common(c, zx_ENC_SO_is_InteractionResponse(c, x, buf ), buf, len);
}

/* FUNC(zx_EASY_ENC_WO_is_InteractionResponse) */

/* Called by: */
struct zx_str* zx_EASY_ENC_WO_is_InteractionResponse(struct zx_ctx* c, struct zx_is_InteractionResponse_s* x )
{
  int len;
  char* buf;
  c->ns_tab = ZX_ALLOC(c, sizeof(zx_ns_tab));
  memcpy(c->ns_tab, zx_ns_tab, sizeof(zx_ns_tab));
  len = zx_LEN_WO_is_InteractionResponse(c, x );
  buf = ZX_ALLOC(c, len+1);
  return zx_easy_enc_common(c, zx_ENC_WO_is_InteractionResponse(c, x, buf ), buf, len);
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

#define EL_NAME   is_InteractionStatement
#define EL_STRUCT zx_is_InteractionStatement_s
#define EL_NS     is
#define EL_TAG    InteractionStatement

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

/* FUNC(zx_LEN_SO_is_InteractionStatement) */

/* Compute length of an element (and its subelements). The XML attributes
 * and elements are processed in schema order. */

/* Called by: */
int zx_LEN_SO_is_InteractionStatement(struct zx_ctx* c, struct zx_is_InteractionStatement_s* x )
{
  struct zx_ns_s* pop_seen = 0;
  struct zx_elem_s* se MAYBE_UNUSED;
#if 1 /* NORMALMODE */
  /* *** in simple_elem case should output ns prefix from ns node. */
  int len = sizeof("<is:InteractionStatement")-1 + 1 + sizeof("</is:InteractionStatement>")-1;
  if (c->inc_ns_len)
    len += zx_len_inc_ns(c, &pop_seen);
  len += zx_len_xmlns_if_not_seen(c, zx_ns_tab+zx_xmlns_ix_is, &pop_seen);


#else
  /* root node has no begin tag */
  int len = 0;
#endif
  
  {
      struct zx_is_Inquiry_s* e;
      for (e = x->Inquiry; e; e = (struct zx_is_Inquiry_s*)e->gg.g.n)
	  len += zx_LEN_SO_is_Inquiry(c, e);
  }
  {
      struct zx_ds_Signature_s* e;
      for (e = x->Signature; e; e = (struct zx_ds_Signature_s*)e->gg.g.n)
	  if (e != c->exclude_sig)
              len += zx_LEN_SO_ds_Signature(c, e);
  }


  len += zx_len_so_common(c, &x->gg, &pop_seen);
  zx_pop_seen(pop_seen);
  ENC_LEN_DEBUG(x, "is:InteractionStatement", len);
  return len;
}

/* FUNC(zx_LEN_WO_is_InteractionStatement) */

/* Compute length of an element (and its subelements). The XML attributes
 * and elements are processed in wire order and no assumptions
 * are made about namespace prefixes. */

/* Called by: */
int zx_LEN_WO_is_InteractionStatement(struct zx_ctx* c, struct zx_is_InteractionStatement_s* x )
{
  struct zx_ns_s* pop_seen = 0;
  struct zx_elem_s* se MAYBE_UNUSED;
#if 1 /* NORMALMODE */
  int len = 1 + sizeof("InteractionStatement")-1 + 1 + 2 + sizeof("InteractionStatement")-1 + 1;
  
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
      struct zx_is_Inquiry_s* e;
      for (e = x->Inquiry; e; e = (struct zx_is_Inquiry_s*)e->gg.g.n)
	  len += zx_LEN_WO_is_Inquiry(c, e);
  }
  {
      struct zx_ds_Signature_s* e;
      for (e = x->Signature; e; e = (struct zx_ds_Signature_s*)e->gg.g.n)
	  if (e != c->exclude_sig)
              len += zx_LEN_WO_ds_Signature(c, e);
  }


  len += zx_len_wo_common(c, &x->gg, &pop_seen); 
  zx_pop_seen(pop_seen);
  ENC_LEN_DEBUG(x, "is:InteractionStatement", len);
  return len;
}

/* FUNC(zx_ENC_SO_is_InteractionStatement) */

/* Render element into string. The XML attributes and elements are
 * processed in schema order. This is what you generally want for
 * rendering new data structure to a string. The wo pointers are not used. */

/* Called by: */
char* zx_ENC_SO_is_InteractionStatement(struct zx_ctx* c, struct zx_is_InteractionStatement_s* x, char* p )
{
  struct zx_elem_s* se MAYBE_UNUSED;
  struct zx_ns_s* pop_seen = 0;
  ENC_LEN_DEBUG_BASE;
#if 1 /* NORMALMODE */
  /* *** in simple_elem case should output ns prefix from ns node. */
  ZX_OUT_TAG(p, "<is:InteractionStatement");
  if (c->inc_ns)
    zx_add_inc_ns(c, &pop_seen);
  zx_add_xmlns_if_not_seen(c, zx_ns_tab+zx_xmlns_ix_is, &pop_seen);

  zx_see_unknown_attrs_ns(c, x->gg.any_attr, &pop_seen);
  p = zx_enc_seen(p, pop_seen); 

  p = zx_enc_unknown_attrs(p, x->gg.any_attr);
#else
  /* root node has no begin tag */
#endif
  
  {
      struct zx_is_Inquiry_s* e;
      for (e = x->Inquiry; e; e = (struct zx_is_Inquiry_s*)e->gg.g.n)
	  p = zx_ENC_SO_is_Inquiry(c, e, p);
  }
  {
      struct zx_ds_Signature_s* e;
      for (e = x->Signature; e; e = (struct zx_ds_Signature_s*)e->gg.g.n)
	  if (e != c->exclude_sig)
              p = zx_ENC_SO_ds_Signature(c, e, p);
  }

  p = zx_enc_so_unknown_elems_and_content(c, p, &x->gg);
  
#if 1 /* NORMALMODE */
  ZX_OUT_CLOSE_TAG(p, "</is:InteractionStatement>");
  zx_pop_seen(pop_seen);
#else
  /* root node has no end tag either */
#endif
  ENC_LEN_DEBUG(x, "is:InteractionStatement", p-enc_base);
  return p;
}

/* FUNC(zx_ENC_WO_is_InteractionStatement) */

/* Render element into string. The XML attributes and elements are
 * processed in wire order by chasing wo pointers. This is what you want for
 * validating signatures on other people's XML documents. */

/* Called by: */
char* zx_ENC_WO_is_InteractionStatement(struct zx_ctx* c, struct zx_is_InteractionStatement_s* x, char* p )
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
  ZX_OUT_MEM(p, "InteractionStatement", sizeof("InteractionStatement")-1);
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
  ENC_LEN_DEBUG(x, "is:InteractionStatement", p-enc_base);
  return p;
}

/* FUNC(zx_EASY_ENC_SO_is_InteractionStatement) */

/* Called by: */
struct zx_str* zx_EASY_ENC_SO_is_InteractionStatement(struct zx_ctx* c, struct zx_is_InteractionStatement_s* x )
{
  int len;
  char* buf;
  c->ns_tab = ZX_ALLOC(c, sizeof(zx_ns_tab));
  memcpy(c->ns_tab, zx_ns_tab, sizeof(zx_ns_tab));
  len = zx_LEN_SO_is_InteractionStatement(c, x );
  buf = ZX_ALLOC(c, len+1);
  return zx_easy_enc_common(c, zx_ENC_SO_is_InteractionStatement(c, x, buf ), buf, len);
}

/* FUNC(zx_EASY_ENC_WO_is_InteractionStatement) */

/* Called by: */
struct zx_str* zx_EASY_ENC_WO_is_InteractionStatement(struct zx_ctx* c, struct zx_is_InteractionStatement_s* x )
{
  int len;
  char* buf;
  c->ns_tab = ZX_ALLOC(c, sizeof(zx_ns_tab));
  memcpy(c->ns_tab, zx_ns_tab, sizeof(zx_ns_tab));
  len = zx_LEN_WO_is_InteractionStatement(c, x );
  buf = ZX_ALLOC(c, len+1);
  return zx_easy_enc_common(c, zx_ENC_WO_is_InteractionStatement(c, x, buf ), buf, len);
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

#define EL_NAME   is_Item
#define EL_STRUCT zx_is_Item_s
#define EL_NS     is
#define EL_TAG    Item

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

/* FUNC(zx_LEN_SO_is_Item) */

/* Compute length of an element (and its subelements). The XML attributes
 * and elements are processed in schema order. */

/* Called by: */
int zx_LEN_SO_is_Item(struct zx_ctx* c, struct zx_is_Item_s* x )
{
  struct zx_ns_s* pop_seen = 0;
  struct zx_elem_s* se MAYBE_UNUSED;
#if 1 /* NORMALMODE */
  /* *** in simple_elem case should output ns prefix from ns node. */
  int len = sizeof("<is:Item")-1 + 1 + sizeof("</is:Item>")-1;
  if (c->inc_ns_len)
    len += zx_len_inc_ns(c, &pop_seen);
  len += zx_len_xmlns_if_not_seen(c, zx_ns_tab+zx_xmlns_ix_is, &pop_seen);

  len += zx_attr_so_len(c, x->label, sizeof("label")-1, &pop_seen);
  len += zx_attr_so_len(c, x->value, sizeof("value")-1, &pop_seen);

#else
  /* root node has no begin tag */
  int len = 0;
#endif
  
  for (se = x->Hint; se; se = (struct zx_elem_s*)se->g.n)
    len += zx_LEN_SO_simple_elem(c,se, sizeof("is:Hint")-1, zx_ns_tab+zx_xmlns_ix_is);


  len += zx_len_so_common(c, &x->gg, &pop_seen);
  zx_pop_seen(pop_seen);
  ENC_LEN_DEBUG(x, "is:Item", len);
  return len;
}

/* FUNC(zx_LEN_WO_is_Item) */

/* Compute length of an element (and its subelements). The XML attributes
 * and elements are processed in wire order and no assumptions
 * are made about namespace prefixes. */

/* Called by: */
int zx_LEN_WO_is_Item(struct zx_ctx* c, struct zx_is_Item_s* x )
{
  struct zx_ns_s* pop_seen = 0;
  struct zx_elem_s* se MAYBE_UNUSED;
#if 1 /* NORMALMODE */
  int len = 1 + sizeof("Item")-1 + 1 + 2 + sizeof("Item")-1 + 1;
  
  if (x->gg.g.ns && x->gg.g.ns->prefix_len)
    len += (x->gg.g.ns->prefix_len + 1) * 2;
  if (c->inc_ns_len)
    len += zx_len_inc_ns(c, &pop_seen);
  len += zx_len_xmlns_if_not_seen(c, x->gg.g.ns, &pop_seen);

  len += zx_attr_wo_len(c, x->label, sizeof("label")-1, &pop_seen);
  len += zx_attr_wo_len(c, x->value, sizeof("value")-1, &pop_seen);

#else
  /* root node has no begin tag */
  int len = 0;
#endif
  
  for (se = x->Hint; se; se = (struct zx_elem_s*)se->g.n)
    len += zx_LEN_WO_simple_elem(c, se, sizeof("Hint")-1);


  len += zx_len_wo_common(c, &x->gg, &pop_seen); 
  zx_pop_seen(pop_seen);
  ENC_LEN_DEBUG(x, "is:Item", len);
  return len;
}

/* FUNC(zx_ENC_SO_is_Item) */

/* Render element into string. The XML attributes and elements are
 * processed in schema order. This is what you generally want for
 * rendering new data structure to a string. The wo pointers are not used. */

/* Called by: */
char* zx_ENC_SO_is_Item(struct zx_ctx* c, struct zx_is_Item_s* x, char* p )
{
  struct zx_elem_s* se MAYBE_UNUSED;
  struct zx_ns_s* pop_seen = 0;
  ENC_LEN_DEBUG_BASE;
#if 1 /* NORMALMODE */
  /* *** in simple_elem case should output ns prefix from ns node. */
  ZX_OUT_TAG(p, "<is:Item");
  if (c->inc_ns)
    zx_add_inc_ns(c, &pop_seen);
  zx_add_xmlns_if_not_seen(c, zx_ns_tab+zx_xmlns_ix_is, &pop_seen);

  zx_see_unknown_attrs_ns(c, x->gg.any_attr, &pop_seen);
  p = zx_enc_seen(p, pop_seen); 
  p = zx_attr_so_enc(p, x->label, " label=\"", sizeof(" label=\"")-1);
  p = zx_attr_so_enc(p, x->value, " value=\"", sizeof(" value=\"")-1);

  p = zx_enc_unknown_attrs(p, x->gg.any_attr);
#else
  /* root node has no begin tag */
#endif
  
  for (se = x->Hint; se; se = (struct zx_elem_s*)se->g.n)
    p = zx_ENC_SO_simple_elem(c, se, p, "is:Hint", sizeof("is:Hint")-1, zx_ns_tab+zx_xmlns_ix_is);

  p = zx_enc_so_unknown_elems_and_content(c, p, &x->gg);
  
#if 1 /* NORMALMODE */
  ZX_OUT_CLOSE_TAG(p, "</is:Item>");
  zx_pop_seen(pop_seen);
#else
  /* root node has no end tag either */
#endif
  ENC_LEN_DEBUG(x, "is:Item", p-enc_base);
  return p;
}

/* FUNC(zx_ENC_WO_is_Item) */

/* Render element into string. The XML attributes and elements are
 * processed in wire order by chasing wo pointers. This is what you want for
 * validating signatures on other people's XML documents. */

/* Called by: */
char* zx_ENC_WO_is_Item(struct zx_ctx* c, struct zx_is_Item_s* x, char* p )
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
  ZX_OUT_MEM(p, "Item", sizeof("Item")-1);
  qq = p;

  if (c->inc_ns)
    zx_add_inc_ns(c, &pop_seen);
  zx_add_xmlns_if_not_seen(c, x->gg.g.ns, &pop_seen);

  zx_see_unknown_attrs_ns(c, x->gg.any_attr, &pop_seen);
  p = zx_enc_seen(p, pop_seen); 
  p = zx_attr_wo_enc(p, x->label, "label=\"", sizeof("label=\"")-1);
  p = zx_attr_wo_enc(p, x->value, "value=\"", sizeof("value=\"")-1);

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
  ENC_LEN_DEBUG(x, "is:Item", p-enc_base);
  return p;
}

/* FUNC(zx_EASY_ENC_SO_is_Item) */

/* Called by: */
struct zx_str* zx_EASY_ENC_SO_is_Item(struct zx_ctx* c, struct zx_is_Item_s* x )
{
  int len;
  char* buf;
  c->ns_tab = ZX_ALLOC(c, sizeof(zx_ns_tab));
  memcpy(c->ns_tab, zx_ns_tab, sizeof(zx_ns_tab));
  len = zx_LEN_SO_is_Item(c, x );
  buf = ZX_ALLOC(c, len+1);
  return zx_easy_enc_common(c, zx_ENC_SO_is_Item(c, x, buf ), buf, len);
}

/* FUNC(zx_EASY_ENC_WO_is_Item) */

/* Called by: */
struct zx_str* zx_EASY_ENC_WO_is_Item(struct zx_ctx* c, struct zx_is_Item_s* x )
{
  int len;
  char* buf;
  c->ns_tab = ZX_ALLOC(c, sizeof(zx_ns_tab));
  memcpy(c->ns_tab, zx_ns_tab, sizeof(zx_ns_tab));
  len = zx_LEN_WO_is_Item(c, x );
  buf = ZX_ALLOC(c, len+1);
  return zx_easy_enc_common(c, zx_ENC_WO_is_Item(c, x, buf ), buf, len);
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

#define EL_NAME   is_Parameter
#define EL_STRUCT zx_is_Parameter_s
#define EL_NS     is
#define EL_TAG    Parameter

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

/* FUNC(zx_LEN_SO_is_Parameter) */

/* Compute length of an element (and its subelements). The XML attributes
 * and elements are processed in schema order. */

/* Called by: */
int zx_LEN_SO_is_Parameter(struct zx_ctx* c, struct zx_is_Parameter_s* x )
{
  struct zx_ns_s* pop_seen = 0;
  struct zx_elem_s* se MAYBE_UNUSED;
#if 1 /* NORMALMODE */
  /* *** in simple_elem case should output ns prefix from ns node. */
  int len = sizeof("<is:Parameter")-1 + 1 + sizeof("</is:Parameter>")-1;
  if (c->inc_ns_len)
    len += zx_len_inc_ns(c, &pop_seen);
  len += zx_len_xmlns_if_not_seen(c, zx_ns_tab+zx_xmlns_ix_is, &pop_seen);

  len += zx_attr_so_len(c, x->name, sizeof("name")-1, &pop_seen);
  len += zx_attr_so_len(c, x->value, sizeof("value")-1, &pop_seen);

#else
  /* root node has no begin tag */
  int len = 0;
#endif
  


  len += zx_len_so_common(c, &x->gg, &pop_seen);
  zx_pop_seen(pop_seen);
  ENC_LEN_DEBUG(x, "is:Parameter", len);
  return len;
}

/* FUNC(zx_LEN_WO_is_Parameter) */

/* Compute length of an element (and its subelements). The XML attributes
 * and elements are processed in wire order and no assumptions
 * are made about namespace prefixes. */

/* Called by: */
int zx_LEN_WO_is_Parameter(struct zx_ctx* c, struct zx_is_Parameter_s* x )
{
  struct zx_ns_s* pop_seen = 0;
  struct zx_elem_s* se MAYBE_UNUSED;
#if 1 /* NORMALMODE */
  int len = 1 + sizeof("Parameter")-1 + 1 + 2 + sizeof("Parameter")-1 + 1;
  
  if (x->gg.g.ns && x->gg.g.ns->prefix_len)
    len += (x->gg.g.ns->prefix_len + 1) * 2;
  if (c->inc_ns_len)
    len += zx_len_inc_ns(c, &pop_seen);
  len += zx_len_xmlns_if_not_seen(c, x->gg.g.ns, &pop_seen);

  len += zx_attr_wo_len(c, x->name, sizeof("name")-1, &pop_seen);
  len += zx_attr_wo_len(c, x->value, sizeof("value")-1, &pop_seen);

#else
  /* root node has no begin tag */
  int len = 0;
#endif
  


  len += zx_len_wo_common(c, &x->gg, &pop_seen); 
  zx_pop_seen(pop_seen);
  ENC_LEN_DEBUG(x, "is:Parameter", len);
  return len;
}

/* FUNC(zx_ENC_SO_is_Parameter) */

/* Render element into string. The XML attributes and elements are
 * processed in schema order. This is what you generally want for
 * rendering new data structure to a string. The wo pointers are not used. */

/* Called by: */
char* zx_ENC_SO_is_Parameter(struct zx_ctx* c, struct zx_is_Parameter_s* x, char* p )
{
  struct zx_elem_s* se MAYBE_UNUSED;
  struct zx_ns_s* pop_seen = 0;
  ENC_LEN_DEBUG_BASE;
#if 1 /* NORMALMODE */
  /* *** in simple_elem case should output ns prefix from ns node. */
  ZX_OUT_TAG(p, "<is:Parameter");
  if (c->inc_ns)
    zx_add_inc_ns(c, &pop_seen);
  zx_add_xmlns_if_not_seen(c, zx_ns_tab+zx_xmlns_ix_is, &pop_seen);

  zx_see_unknown_attrs_ns(c, x->gg.any_attr, &pop_seen);
  p = zx_enc_seen(p, pop_seen); 
  p = zx_attr_so_enc(p, x->name, " name=\"", sizeof(" name=\"")-1);
  p = zx_attr_so_enc(p, x->value, " value=\"", sizeof(" value=\"")-1);

  p = zx_enc_unknown_attrs(p, x->gg.any_attr);
#else
  /* root node has no begin tag */
#endif
  

  p = zx_enc_so_unknown_elems_and_content(c, p, &x->gg);
  
#if 1 /* NORMALMODE */
  ZX_OUT_CLOSE_TAG(p, "</is:Parameter>");
  zx_pop_seen(pop_seen);
#else
  /* root node has no end tag either */
#endif
  ENC_LEN_DEBUG(x, "is:Parameter", p-enc_base);
  return p;
}

/* FUNC(zx_ENC_WO_is_Parameter) */

/* Render element into string. The XML attributes and elements are
 * processed in wire order by chasing wo pointers. This is what you want for
 * validating signatures on other people's XML documents. */

/* Called by: */
char* zx_ENC_WO_is_Parameter(struct zx_ctx* c, struct zx_is_Parameter_s* x, char* p )
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
  ZX_OUT_MEM(p, "Parameter", sizeof("Parameter")-1);
  qq = p;

  if (c->inc_ns)
    zx_add_inc_ns(c, &pop_seen);
  zx_add_xmlns_if_not_seen(c, x->gg.g.ns, &pop_seen);

  zx_see_unknown_attrs_ns(c, x->gg.any_attr, &pop_seen);
  p = zx_enc_seen(p, pop_seen); 
  p = zx_attr_wo_enc(p, x->name, "name=\"", sizeof("name=\"")-1);
  p = zx_attr_wo_enc(p, x->value, "value=\"", sizeof("value=\"")-1);

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
  ENC_LEN_DEBUG(x, "is:Parameter", p-enc_base);
  return p;
}

/* FUNC(zx_EASY_ENC_SO_is_Parameter) */

/* Called by: */
struct zx_str* zx_EASY_ENC_SO_is_Parameter(struct zx_ctx* c, struct zx_is_Parameter_s* x )
{
  int len;
  char* buf;
  c->ns_tab = ZX_ALLOC(c, sizeof(zx_ns_tab));
  memcpy(c->ns_tab, zx_ns_tab, sizeof(zx_ns_tab));
  len = zx_LEN_SO_is_Parameter(c, x );
  buf = ZX_ALLOC(c, len+1);
  return zx_easy_enc_common(c, zx_ENC_SO_is_Parameter(c, x, buf ), buf, len);
}

/* FUNC(zx_EASY_ENC_WO_is_Parameter) */

/* Called by: */
struct zx_str* zx_EASY_ENC_WO_is_Parameter(struct zx_ctx* c, struct zx_is_Parameter_s* x )
{
  int len;
  char* buf;
  c->ns_tab = ZX_ALLOC(c, sizeof(zx_ns_tab));
  memcpy(c->ns_tab, zx_ns_tab, sizeof(zx_ns_tab));
  len = zx_LEN_WO_is_Parameter(c, x );
  buf = ZX_ALLOC(c, len+1);
  return zx_easy_enc_common(c, zx_ENC_WO_is_Parameter(c, x, buf ), buf, len);
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

#define EL_NAME   is_Select
#define EL_STRUCT zx_is_Select_s
#define EL_NS     is
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

/* FUNC(zx_LEN_SO_is_Select) */

/* Compute length of an element (and its subelements). The XML attributes
 * and elements are processed in schema order. */

/* Called by: */
int zx_LEN_SO_is_Select(struct zx_ctx* c, struct zx_is_Select_s* x )
{
  struct zx_ns_s* pop_seen = 0;
  struct zx_elem_s* se MAYBE_UNUSED;
#if 1 /* NORMALMODE */
  /* *** in simple_elem case should output ns prefix from ns node. */
  int len = sizeof("<is:Select")-1 + 1 + sizeof("</is:Select>")-1;
  if (c->inc_ns_len)
    len += zx_len_inc_ns(c, &pop_seen);
  len += zx_len_xmlns_if_not_seen(c, zx_ns_tab+zx_xmlns_ix_is, &pop_seen);

  len += zx_attr_so_len(c, x->multiple, sizeof("multiple")-1, &pop_seen);
  len += zx_attr_so_len(c, x->name, sizeof("name")-1, &pop_seen);

#else
  /* root node has no begin tag */
  int len = 0;
#endif
  
  {
      struct zx_is_Help_s* e;
      for (e = x->Help; e; e = (struct zx_is_Help_s*)e->gg.g.n)
	  len += zx_LEN_SO_is_Help(c, e);
  }
  for (se = x->Hint; se; se = (struct zx_elem_s*)se->g.n)
    len += zx_LEN_SO_simple_elem(c,se, sizeof("is:Hint")-1, zx_ns_tab+zx_xmlns_ix_is);
  for (se = x->Label; se; se = (struct zx_elem_s*)se->g.n)
    len += zx_LEN_SO_simple_elem(c,se, sizeof("is:Label")-1, zx_ns_tab+zx_xmlns_ix_is);
  for (se = x->Value; se; se = (struct zx_elem_s*)se->g.n)
    len += zx_LEN_SO_simple_elem(c,se, sizeof("is:Value")-1, zx_ns_tab+zx_xmlns_ix_is);
  {
      struct zx_is_Item_s* e;
      for (e = x->Item; e; e = (struct zx_is_Item_s*)e->gg.g.n)
	  len += zx_LEN_SO_is_Item(c, e);
  }


  len += zx_len_so_common(c, &x->gg, &pop_seen);
  zx_pop_seen(pop_seen);
  ENC_LEN_DEBUG(x, "is:Select", len);
  return len;
}

/* FUNC(zx_LEN_WO_is_Select) */

/* Compute length of an element (and its subelements). The XML attributes
 * and elements are processed in wire order and no assumptions
 * are made about namespace prefixes. */

/* Called by: */
int zx_LEN_WO_is_Select(struct zx_ctx* c, struct zx_is_Select_s* x )
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

  len += zx_attr_wo_len(c, x->multiple, sizeof("multiple")-1, &pop_seen);
  len += zx_attr_wo_len(c, x->name, sizeof("name")-1, &pop_seen);

#else
  /* root node has no begin tag */
  int len = 0;
#endif
  
  {
      struct zx_is_Help_s* e;
      for (e = x->Help; e; e = (struct zx_is_Help_s*)e->gg.g.n)
	  len += zx_LEN_WO_is_Help(c, e);
  }
  for (se = x->Hint; se; se = (struct zx_elem_s*)se->g.n)
    len += zx_LEN_WO_simple_elem(c, se, sizeof("Hint")-1);
  for (se = x->Label; se; se = (struct zx_elem_s*)se->g.n)
    len += zx_LEN_WO_simple_elem(c, se, sizeof("Label")-1);
  for (se = x->Value; se; se = (struct zx_elem_s*)se->g.n)
    len += zx_LEN_WO_simple_elem(c, se, sizeof("Value")-1);
  {
      struct zx_is_Item_s* e;
      for (e = x->Item; e; e = (struct zx_is_Item_s*)e->gg.g.n)
	  len += zx_LEN_WO_is_Item(c, e);
  }


  len += zx_len_wo_common(c, &x->gg, &pop_seen); 
  zx_pop_seen(pop_seen);
  ENC_LEN_DEBUG(x, "is:Select", len);
  return len;
}

/* FUNC(zx_ENC_SO_is_Select) */

/* Render element into string. The XML attributes and elements are
 * processed in schema order. This is what you generally want for
 * rendering new data structure to a string. The wo pointers are not used. */

/* Called by: */
char* zx_ENC_SO_is_Select(struct zx_ctx* c, struct zx_is_Select_s* x, char* p )
{
  struct zx_elem_s* se MAYBE_UNUSED;
  struct zx_ns_s* pop_seen = 0;
  ENC_LEN_DEBUG_BASE;
#if 1 /* NORMALMODE */
  /* *** in simple_elem case should output ns prefix from ns node. */
  ZX_OUT_TAG(p, "<is:Select");
  if (c->inc_ns)
    zx_add_inc_ns(c, &pop_seen);
  zx_add_xmlns_if_not_seen(c, zx_ns_tab+zx_xmlns_ix_is, &pop_seen);

  zx_see_unknown_attrs_ns(c, x->gg.any_attr, &pop_seen);
  p = zx_enc_seen(p, pop_seen); 
  p = zx_attr_so_enc(p, x->multiple, " multiple=\"", sizeof(" multiple=\"")-1);
  p = zx_attr_so_enc(p, x->name, " name=\"", sizeof(" name=\"")-1);

  p = zx_enc_unknown_attrs(p, x->gg.any_attr);
#else
  /* root node has no begin tag */
#endif
  
  {
      struct zx_is_Help_s* e;
      for (e = x->Help; e; e = (struct zx_is_Help_s*)e->gg.g.n)
	  p = zx_ENC_SO_is_Help(c, e, p);
  }
  for (se = x->Hint; se; se = (struct zx_elem_s*)se->g.n)
    p = zx_ENC_SO_simple_elem(c, se, p, "is:Hint", sizeof("is:Hint")-1, zx_ns_tab+zx_xmlns_ix_is);
  for (se = x->Label; se; se = (struct zx_elem_s*)se->g.n)
    p = zx_ENC_SO_simple_elem(c, se, p, "is:Label", sizeof("is:Label")-1, zx_ns_tab+zx_xmlns_ix_is);
  for (se = x->Value; se; se = (struct zx_elem_s*)se->g.n)
    p = zx_ENC_SO_simple_elem(c, se, p, "is:Value", sizeof("is:Value")-1, zx_ns_tab+zx_xmlns_ix_is);
  {
      struct zx_is_Item_s* e;
      for (e = x->Item; e; e = (struct zx_is_Item_s*)e->gg.g.n)
	  p = zx_ENC_SO_is_Item(c, e, p);
  }

  p = zx_enc_so_unknown_elems_and_content(c, p, &x->gg);
  
#if 1 /* NORMALMODE */
  ZX_OUT_CLOSE_TAG(p, "</is:Select>");
  zx_pop_seen(pop_seen);
#else
  /* root node has no end tag either */
#endif
  ENC_LEN_DEBUG(x, "is:Select", p-enc_base);
  return p;
}

/* FUNC(zx_ENC_WO_is_Select) */

/* Render element into string. The XML attributes and elements are
 * processed in wire order by chasing wo pointers. This is what you want for
 * validating signatures on other people's XML documents. */

/* Called by: */
char* zx_ENC_WO_is_Select(struct zx_ctx* c, struct zx_is_Select_s* x, char* p )
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
  ZX_OUT_MEM(p, "Select", sizeof("Select")-1);
  qq = p;

  if (c->inc_ns)
    zx_add_inc_ns(c, &pop_seen);
  zx_add_xmlns_if_not_seen(c, x->gg.g.ns, &pop_seen);

  zx_see_unknown_attrs_ns(c, x->gg.any_attr, &pop_seen);
  p = zx_enc_seen(p, pop_seen); 
  p = zx_attr_wo_enc(p, x->multiple, "multiple=\"", sizeof("multiple=\"")-1);
  p = zx_attr_wo_enc(p, x->name, "name=\"", sizeof("name=\"")-1);

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
  ENC_LEN_DEBUG(x, "is:Select", p-enc_base);
  return p;
}

/* FUNC(zx_EASY_ENC_SO_is_Select) */

/* Called by: */
struct zx_str* zx_EASY_ENC_SO_is_Select(struct zx_ctx* c, struct zx_is_Select_s* x )
{
  int len;
  char* buf;
  c->ns_tab = ZX_ALLOC(c, sizeof(zx_ns_tab));
  memcpy(c->ns_tab, zx_ns_tab, sizeof(zx_ns_tab));
  len = zx_LEN_SO_is_Select(c, x );
  buf = ZX_ALLOC(c, len+1);
  return zx_easy_enc_common(c, zx_ENC_SO_is_Select(c, x, buf ), buf, len);
}

/* FUNC(zx_EASY_ENC_WO_is_Select) */

/* Called by: */
struct zx_str* zx_EASY_ENC_WO_is_Select(struct zx_ctx* c, struct zx_is_Select_s* x )
{
  int len;
  char* buf;
  c->ns_tab = ZX_ALLOC(c, sizeof(zx_ns_tab));
  memcpy(c->ns_tab, zx_ns_tab, sizeof(zx_ns_tab));
  len = zx_LEN_WO_is_Select(c, x );
  buf = ZX_ALLOC(c, len+1);
  return zx_easy_enc_common(c, zx_ENC_WO_is_Select(c, x, buf ), buf, len);
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

#define EL_NAME   is_Text
#define EL_STRUCT zx_is_Text_s
#define EL_NS     is
#define EL_TAG    Text

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

/* FUNC(zx_LEN_SO_is_Text) */

/* Compute length of an element (and its subelements). The XML attributes
 * and elements are processed in schema order. */

/* Called by: */
int zx_LEN_SO_is_Text(struct zx_ctx* c, struct zx_is_Text_s* x )
{
  struct zx_ns_s* pop_seen = 0;
  struct zx_elem_s* se MAYBE_UNUSED;
#if 1 /* NORMALMODE */
  /* *** in simple_elem case should output ns prefix from ns node. */
  int len = sizeof("<is:Text")-1 + 1 + sizeof("</is:Text>")-1;
  if (c->inc_ns_len)
    len += zx_len_inc_ns(c, &pop_seen);
  len += zx_len_xmlns_if_not_seen(c, zx_ns_tab+zx_xmlns_ix_is, &pop_seen);

  len += zx_attr_so_len(c, x->format, sizeof("format")-1, &pop_seen);
  len += zx_attr_so_len(c, x->maxChars, sizeof("maxChars")-1, &pop_seen);
  len += zx_attr_so_len(c, x->minChars, sizeof("minChars")-1, &pop_seen);
  len += zx_attr_so_len(c, x->name, sizeof("name")-1, &pop_seen);

#else
  /* root node has no begin tag */
  int len = 0;
#endif
  
  {
      struct zx_is_Help_s* e;
      for (e = x->Help; e; e = (struct zx_is_Help_s*)e->gg.g.n)
	  len += zx_LEN_SO_is_Help(c, e);
  }
  for (se = x->Hint; se; se = (struct zx_elem_s*)se->g.n)
    len += zx_LEN_SO_simple_elem(c,se, sizeof("is:Hint")-1, zx_ns_tab+zx_xmlns_ix_is);
  for (se = x->Label; se; se = (struct zx_elem_s*)se->g.n)
    len += zx_LEN_SO_simple_elem(c,se, sizeof("is:Label")-1, zx_ns_tab+zx_xmlns_ix_is);
  for (se = x->Value; se; se = (struct zx_elem_s*)se->g.n)
    len += zx_LEN_SO_simple_elem(c,se, sizeof("is:Value")-1, zx_ns_tab+zx_xmlns_ix_is);


  len += zx_len_so_common(c, &x->gg, &pop_seen);
  zx_pop_seen(pop_seen);
  ENC_LEN_DEBUG(x, "is:Text", len);
  return len;
}

/* FUNC(zx_LEN_WO_is_Text) */

/* Compute length of an element (and its subelements). The XML attributes
 * and elements are processed in wire order and no assumptions
 * are made about namespace prefixes. */

/* Called by: */
int zx_LEN_WO_is_Text(struct zx_ctx* c, struct zx_is_Text_s* x )
{
  struct zx_ns_s* pop_seen = 0;
  struct zx_elem_s* se MAYBE_UNUSED;
#if 1 /* NORMALMODE */
  int len = 1 + sizeof("Text")-1 + 1 + 2 + sizeof("Text")-1 + 1;
  
  if (x->gg.g.ns && x->gg.g.ns->prefix_len)
    len += (x->gg.g.ns->prefix_len + 1) * 2;
  if (c->inc_ns_len)
    len += zx_len_inc_ns(c, &pop_seen);
  len += zx_len_xmlns_if_not_seen(c, x->gg.g.ns, &pop_seen);

  len += zx_attr_wo_len(c, x->format, sizeof("format")-1, &pop_seen);
  len += zx_attr_wo_len(c, x->maxChars, sizeof("maxChars")-1, &pop_seen);
  len += zx_attr_wo_len(c, x->minChars, sizeof("minChars")-1, &pop_seen);
  len += zx_attr_wo_len(c, x->name, sizeof("name")-1, &pop_seen);

#else
  /* root node has no begin tag */
  int len = 0;
#endif
  
  {
      struct zx_is_Help_s* e;
      for (e = x->Help; e; e = (struct zx_is_Help_s*)e->gg.g.n)
	  len += zx_LEN_WO_is_Help(c, e);
  }
  for (se = x->Hint; se; se = (struct zx_elem_s*)se->g.n)
    len += zx_LEN_WO_simple_elem(c, se, sizeof("Hint")-1);
  for (se = x->Label; se; se = (struct zx_elem_s*)se->g.n)
    len += zx_LEN_WO_simple_elem(c, se, sizeof("Label")-1);
  for (se = x->Value; se; se = (struct zx_elem_s*)se->g.n)
    len += zx_LEN_WO_simple_elem(c, se, sizeof("Value")-1);


  len += zx_len_wo_common(c, &x->gg, &pop_seen); 
  zx_pop_seen(pop_seen);
  ENC_LEN_DEBUG(x, "is:Text", len);
  return len;
}

/* FUNC(zx_ENC_SO_is_Text) */

/* Render element into string. The XML attributes and elements are
 * processed in schema order. This is what you generally want for
 * rendering new data structure to a string. The wo pointers are not used. */

/* Called by: */
char* zx_ENC_SO_is_Text(struct zx_ctx* c, struct zx_is_Text_s* x, char* p )
{
  struct zx_elem_s* se MAYBE_UNUSED;
  struct zx_ns_s* pop_seen = 0;
  ENC_LEN_DEBUG_BASE;
#if 1 /* NORMALMODE */
  /* *** in simple_elem case should output ns prefix from ns node. */
  ZX_OUT_TAG(p, "<is:Text");
  if (c->inc_ns)
    zx_add_inc_ns(c, &pop_seen);
  zx_add_xmlns_if_not_seen(c, zx_ns_tab+zx_xmlns_ix_is, &pop_seen);

  zx_see_unknown_attrs_ns(c, x->gg.any_attr, &pop_seen);
  p = zx_enc_seen(p, pop_seen); 
  p = zx_attr_so_enc(p, x->format, " format=\"", sizeof(" format=\"")-1);
  p = zx_attr_so_enc(p, x->maxChars, " maxChars=\"", sizeof(" maxChars=\"")-1);
  p = zx_attr_so_enc(p, x->minChars, " minChars=\"", sizeof(" minChars=\"")-1);
  p = zx_attr_so_enc(p, x->name, " name=\"", sizeof(" name=\"")-1);

  p = zx_enc_unknown_attrs(p, x->gg.any_attr);
#else
  /* root node has no begin tag */
#endif
  
  {
      struct zx_is_Help_s* e;
      for (e = x->Help; e; e = (struct zx_is_Help_s*)e->gg.g.n)
	  p = zx_ENC_SO_is_Help(c, e, p);
  }
  for (se = x->Hint; se; se = (struct zx_elem_s*)se->g.n)
    p = zx_ENC_SO_simple_elem(c, se, p, "is:Hint", sizeof("is:Hint")-1, zx_ns_tab+zx_xmlns_ix_is);
  for (se = x->Label; se; se = (struct zx_elem_s*)se->g.n)
    p = zx_ENC_SO_simple_elem(c, se, p, "is:Label", sizeof("is:Label")-1, zx_ns_tab+zx_xmlns_ix_is);
  for (se = x->Value; se; se = (struct zx_elem_s*)se->g.n)
    p = zx_ENC_SO_simple_elem(c, se, p, "is:Value", sizeof("is:Value")-1, zx_ns_tab+zx_xmlns_ix_is);

  p = zx_enc_so_unknown_elems_and_content(c, p, &x->gg);
  
#if 1 /* NORMALMODE */
  ZX_OUT_CLOSE_TAG(p, "</is:Text>");
  zx_pop_seen(pop_seen);
#else
  /* root node has no end tag either */
#endif
  ENC_LEN_DEBUG(x, "is:Text", p-enc_base);
  return p;
}

/* FUNC(zx_ENC_WO_is_Text) */

/* Render element into string. The XML attributes and elements are
 * processed in wire order by chasing wo pointers. This is what you want for
 * validating signatures on other people's XML documents. */

/* Called by: */
char* zx_ENC_WO_is_Text(struct zx_ctx* c, struct zx_is_Text_s* x, char* p )
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
  ZX_OUT_MEM(p, "Text", sizeof("Text")-1);
  qq = p;

  if (c->inc_ns)
    zx_add_inc_ns(c, &pop_seen);
  zx_add_xmlns_if_not_seen(c, x->gg.g.ns, &pop_seen);

  zx_see_unknown_attrs_ns(c, x->gg.any_attr, &pop_seen);
  p = zx_enc_seen(p, pop_seen); 
  p = zx_attr_wo_enc(p, x->format, "format=\"", sizeof("format=\"")-1);
  p = zx_attr_wo_enc(p, x->maxChars, "maxChars=\"", sizeof("maxChars=\"")-1);
  p = zx_attr_wo_enc(p, x->minChars, "minChars=\"", sizeof("minChars=\"")-1);
  p = zx_attr_wo_enc(p, x->name, "name=\"", sizeof("name=\"")-1);

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
  ENC_LEN_DEBUG(x, "is:Text", p-enc_base);
  return p;
}

/* FUNC(zx_EASY_ENC_SO_is_Text) */

/* Called by: */
struct zx_str* zx_EASY_ENC_SO_is_Text(struct zx_ctx* c, struct zx_is_Text_s* x )
{
  int len;
  char* buf;
  c->ns_tab = ZX_ALLOC(c, sizeof(zx_ns_tab));
  memcpy(c->ns_tab, zx_ns_tab, sizeof(zx_ns_tab));
  len = zx_LEN_SO_is_Text(c, x );
  buf = ZX_ALLOC(c, len+1);
  return zx_easy_enc_common(c, zx_ENC_SO_is_Text(c, x, buf ), buf, len);
}

/* FUNC(zx_EASY_ENC_WO_is_Text) */

/* Called by: */
struct zx_str* zx_EASY_ENC_WO_is_Text(struct zx_ctx* c, struct zx_is_Text_s* x )
{
  int len;
  char* buf;
  c->ns_tab = ZX_ALLOC(c, sizeof(zx_ns_tab));
  memcpy(c->ns_tab, zx_ns_tab, sizeof(zx_ns_tab));
  len = zx_LEN_WO_is_Text(c, x );
  buf = ZX_ALLOC(c, len+1);
  return zx_easy_enc_common(c, zx_ENC_WO_is_Text(c, x, buf ), buf, len);
}




/* EOF -- c/zx-is-enc.c */
