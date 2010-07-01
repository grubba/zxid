/* c/zx-gl-enc.c - WARNING: This file was automatically generated. DO NOT EDIT!
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
#include "c/zx-gl-data.h"
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

#define EL_NAME   gl_AreaComparison
#define EL_STRUCT zx_gl_AreaComparison_s
#define EL_NS     gl
#define EL_TAG    AreaComparison

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

/* FUNC(zx_LEN_SO_gl_AreaComparison) */

/* Compute length of an element (and its subelements). The XML attributes
 * and elements are processed in schema order. */

/* Called by: */
int zx_LEN_SO_gl_AreaComparison(struct zx_ctx* c, struct zx_gl_AreaComparison_s* x )
{
  struct zx_ns_s* pop_seen = 0;
  struct zx_elem_s* se MAYBE_UNUSED;
#if 1 /* NORMALMODE */
  /* *** in simple_elem case should output ns prefix from ns node. */
  int len = sizeof("<gl:AreaComparison")-1 + 1 + sizeof("</gl:AreaComparison>")-1;
  if (c->inc_ns_len)
    len += zx_len_inc_ns(c, &pop_seen);
  len += zx_len_xmlns_if_not_seen(c, zx_ns_tab+zx_xmlns_ix_gl, &pop_seen);

  len += zx_attr_so_len(x->itemID, sizeof("itemID")-1);
  len += zx_attr_so_len(x->returnLocation, sizeof("returnLocation")-1);

#else
  /* root node has no begin tag */
  int len = 0;
#endif
  
  {
      struct zx_gl_CivilData_s* e;
      for (e = x->CivilData; e; e = (struct zx_gl_CivilData_s*)e->gg.g.n)
	  len += zx_LEN_SO_gl_CivilData(c, e);
  }
  {
      struct zx_gl_shape_s* e;
      for (e = x->shape; e; e = (struct zx_gl_shape_s*)e->gg.g.n)
	  len += zx_LEN_SO_gl_shape(c, e);
  }
  {
      struct zx_gl_Extension_s* e;
      for (e = x->Extension; e; e = (struct zx_gl_Extension_s*)e->gg.g.n)
	  len += zx_LEN_SO_gl_Extension(c, e);
  }


  len += zx_len_so_common(c, &x->gg);
  zx_pop_seen(pop_seen);
  ENC_LEN_DEBUG(x, "gl:AreaComparison", len);
  return len;
}

/* FUNC(zx_LEN_WO_gl_AreaComparison) */

/* Compute length of an element (and its subelements). The XML attributes
 * and elements are processed in wire order and no assumptions
 * are made about namespace prefixes. */

/* Called by: */
int zx_LEN_WO_gl_AreaComparison(struct zx_ctx* c, struct zx_gl_AreaComparison_s* x )
{
  struct zx_ns_s* pop_seen = 0;
  struct zx_elem_s* se MAYBE_UNUSED;
#if 1 /* NORMALMODE */
  int len = 1 + sizeof("AreaComparison")-1 + 1 + 2 + sizeof("AreaComparison")-1 + 1;
  
  if (x->gg.g.ns && x->gg.g.ns->prefix_len)
    len += (x->gg.g.ns->prefix_len + 1) * 2;
  if (c->inc_ns_len)
    len += zx_len_inc_ns(c, &pop_seen);
  len += zx_len_xmlns_if_not_seen(c, x->gg.g.ns, &pop_seen);

  len += zx_attr_wo_len(x->itemID, sizeof("itemID")-1);
  len += zx_attr_wo_len(x->returnLocation, sizeof("returnLocation")-1);

#else
  /* root node has no begin tag */
  int len = 0;
#endif
  
  {
      struct zx_gl_CivilData_s* e;
      for (e = x->CivilData; e; e = (struct zx_gl_CivilData_s*)e->gg.g.n)
	  len += zx_LEN_WO_gl_CivilData(c, e);
  }
  {
      struct zx_gl_shape_s* e;
      for (e = x->shape; e; e = (struct zx_gl_shape_s*)e->gg.g.n)
	  len += zx_LEN_WO_gl_shape(c, e);
  }
  {
      struct zx_gl_Extension_s* e;
      for (e = x->Extension; e; e = (struct zx_gl_Extension_s*)e->gg.g.n)
	  len += zx_LEN_WO_gl_Extension(c, e);
  }


  len += zx_len_wo_common(c, &x->gg); 
  zx_pop_seen(pop_seen);
  ENC_LEN_DEBUG(x, "gl:AreaComparison", len);
  return len;
}

/* FUNC(zx_ENC_SO_gl_AreaComparison) */

/* Render element into string. The XML attributes and elements are
 * processed in schema order. This is what you generally want for
 * rendering new data structure to a string. The wo pointers are not used. */

/* Called by: */
char* zx_ENC_SO_gl_AreaComparison(struct zx_ctx* c, struct zx_gl_AreaComparison_s* x, char* p )
{
  struct zx_elem_s* se MAYBE_UNUSED;
  struct zx_ns_s* pop_seen = 0;
  ENC_LEN_DEBUG_BASE;
#if 1 /* NORMALMODE */
  /* *** in simple_elem case should output ns prefix from ns node. */
  ZX_OUT_TAG(p, "<gl:AreaComparison");
  if (c->inc_ns)
    p = zx_enc_inc_ns(c, p, &pop_seen);
  p = zx_enc_xmlns_if_not_seen(c, p, zx_ns_tab+zx_xmlns_ix_gl, &pop_seen);

  p = zx_attr_so_enc(p, x->itemID, " itemID=\"", sizeof(" itemID=\"")-1);
  p = zx_attr_so_enc(p, x->returnLocation, " returnLocation=\"", sizeof(" returnLocation=\"")-1);

  p = zx_enc_unknown_attrs(p, x->gg.any_attr);
#else
  /* root node has no begin tag */
#endif
  
  {
      struct zx_gl_CivilData_s* e;
      for (e = x->CivilData; e; e = (struct zx_gl_CivilData_s*)e->gg.g.n)
	  p = zx_ENC_SO_gl_CivilData(c, e, p);
  }
  {
      struct zx_gl_shape_s* e;
      for (e = x->shape; e; e = (struct zx_gl_shape_s*)e->gg.g.n)
	  p = zx_ENC_SO_gl_shape(c, e, p);
  }
  {
      struct zx_gl_Extension_s* e;
      for (e = x->Extension; e; e = (struct zx_gl_Extension_s*)e->gg.g.n)
	  p = zx_ENC_SO_gl_Extension(c, e, p);
  }

  p = zx_enc_so_unknown_elems_and_content(c, p, &x->gg);
  
#if 1 /* NORMALMODE */
  ZX_OUT_CLOSE_TAG(p, "</gl:AreaComparison>");
  zx_pop_seen(pop_seen);
#else
  /* root node has no end tag either */
#endif
  ENC_LEN_DEBUG(x, "gl:AreaComparison", p-enc_base);
  return p;
}

/* FUNC(zx_ENC_WO_gl_AreaComparison) */

/* Render element into string. The XML attributes and elements are
 * processed in wire order by chasing wo pointers. This is what you want for
 * validating signatures on other people's XML documents. */

/* Called by: */
char* zx_ENC_WO_gl_AreaComparison(struct zx_ctx* c, struct zx_gl_AreaComparison_s* x, char* p )
{
  struct zx_elem_s* kid;
  struct zx_ns_s* pop_seen = 0;
  ENC_LEN_DEBUG_BASE;
#if 1 /* NORMALMODE */
  char* q;
  char* qq;
  ZX_OUT_CH(p, '<');
  q = p;
  if (x->gg.g.ns && x->gg.g.ns->prefix_len) {
    ZX_OUT_MEM(p, x->gg.g.ns->prefix, x->gg.g.ns->prefix_len);
    ZX_OUT_CH(p, ':');
  }
  ZX_OUT_MEM(p, "AreaComparison", sizeof("AreaComparison")-1);
  qq = p;

  /* *** sort the namespaces */
  if (c->inc_ns)
    zx_add_inc_ns(c, &pop_seen);
  zx_add_xmlns_if_not_seen(c, x->gg.g.ns, &pop_seen);

  p = zx_enc_seen(p, pop_seen); 
  p = zx_attr_wo_enc(p, x->itemID, "itemID=\"", sizeof("itemID=\"")-1);
  p = zx_attr_wo_enc(p, x->returnLocation, "returnLocation=\"", sizeof("returnLocation=\"")-1);

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
  ENC_LEN_DEBUG(x, "gl:AreaComparison", p-enc_base);
  return p;
}

/* FUNC(zx_EASY_ENC_SO_gl_AreaComparison) */

/* Called by: */
struct zx_str* zx_EASY_ENC_SO_gl_AreaComparison(struct zx_ctx* c, struct zx_gl_AreaComparison_s* x )
{
  int len;
  char* buf;
  c->ns_tab = ZX_ALLOC(c, sizeof(zx_ns_tab));
  memcpy(c->ns_tab, zx_ns_tab, sizeof(zx_ns_tab));
  len = zx_LEN_SO_gl_AreaComparison(c, x );
  buf = ZX_ALLOC(c, len+1);
  return zx_easy_enc_common(c, zx_ENC_SO_gl_AreaComparison(c, x, buf ), buf, len);
}

/* FUNC(zx_EASY_ENC_WO_gl_AreaComparison) */

/* Called by: */
struct zx_str* zx_EASY_ENC_WO_gl_AreaComparison(struct zx_ctx* c, struct zx_gl_AreaComparison_s* x )
{
  int len;
  char* buf;
  c->ns_tab = ZX_ALLOC(c, sizeof(zx_ns_tab));
  memcpy(c->ns_tab, zx_ns_tab, sizeof(zx_ns_tab));
  len = zx_LEN_WO_gl_AreaComparison(c, x );
  buf = ZX_ALLOC(c, len+1);
  return zx_easy_enc_common(c, zx_ENC_WO_gl_AreaComparison(c, x, buf ), buf, len);
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

#define EL_NAME   gl_Box
#define EL_STRUCT zx_gl_Box_s
#define EL_NS     gl
#define EL_TAG    Box

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

/* FUNC(zx_LEN_SO_gl_Box) */

/* Compute length of an element (and its subelements). The XML attributes
 * and elements are processed in schema order. */

/* Called by: */
int zx_LEN_SO_gl_Box(struct zx_ctx* c, struct zx_gl_Box_s* x )
{
  struct zx_ns_s* pop_seen = 0;
  struct zx_elem_s* se MAYBE_UNUSED;
#if 1 /* NORMALMODE */
  /* *** in simple_elem case should output ns prefix from ns node. */
  int len = sizeof("<gl:Box")-1 + 1 + sizeof("</gl:Box>")-1;
  if (c->inc_ns_len)
    len += zx_len_inc_ns(c, &pop_seen);
  len += zx_len_xmlns_if_not_seen(c, zx_ns_tab+zx_xmlns_ix_gl, &pop_seen);

  len += zx_attr_so_len(x->gid, sizeof("gid")-1);
  len += zx_attr_so_len(x->srsName, sizeof("srsName")-1);

#else
  /* root node has no begin tag */
  int len = 0;
#endif
  
  {
      struct zx_gl_coord_s* e;
      for (e = x->coord; e; e = (struct zx_gl_coord_s*)e->gg.g.n)
	  len += zx_LEN_SO_gl_coord(c, e);
  }


  len += zx_len_so_common(c, &x->gg);
  zx_pop_seen(pop_seen);
  ENC_LEN_DEBUG(x, "gl:Box", len);
  return len;
}

/* FUNC(zx_LEN_WO_gl_Box) */

/* Compute length of an element (and its subelements). The XML attributes
 * and elements are processed in wire order and no assumptions
 * are made about namespace prefixes. */

/* Called by: */
int zx_LEN_WO_gl_Box(struct zx_ctx* c, struct zx_gl_Box_s* x )
{
  struct zx_ns_s* pop_seen = 0;
  struct zx_elem_s* se MAYBE_UNUSED;
#if 1 /* NORMALMODE */
  int len = 1 + sizeof("Box")-1 + 1 + 2 + sizeof("Box")-1 + 1;
  
  if (x->gg.g.ns && x->gg.g.ns->prefix_len)
    len += (x->gg.g.ns->prefix_len + 1) * 2;
  if (c->inc_ns_len)
    len += zx_len_inc_ns(c, &pop_seen);
  len += zx_len_xmlns_if_not_seen(c, x->gg.g.ns, &pop_seen);

  len += zx_attr_wo_len(x->gid, sizeof("gid")-1);
  len += zx_attr_wo_len(x->srsName, sizeof("srsName")-1);

#else
  /* root node has no begin tag */
  int len = 0;
#endif
  
  {
      struct zx_gl_coord_s* e;
      for (e = x->coord; e; e = (struct zx_gl_coord_s*)e->gg.g.n)
	  len += zx_LEN_WO_gl_coord(c, e);
  }


  len += zx_len_wo_common(c, &x->gg); 
  zx_pop_seen(pop_seen);
  ENC_LEN_DEBUG(x, "gl:Box", len);
  return len;
}

/* FUNC(zx_ENC_SO_gl_Box) */

/* Render element into string. The XML attributes and elements are
 * processed in schema order. This is what you generally want for
 * rendering new data structure to a string. The wo pointers are not used. */

/* Called by: */
char* zx_ENC_SO_gl_Box(struct zx_ctx* c, struct zx_gl_Box_s* x, char* p )
{
  struct zx_elem_s* se MAYBE_UNUSED;
  struct zx_ns_s* pop_seen = 0;
  ENC_LEN_DEBUG_BASE;
#if 1 /* NORMALMODE */
  /* *** in simple_elem case should output ns prefix from ns node. */
  ZX_OUT_TAG(p, "<gl:Box");
  if (c->inc_ns)
    p = zx_enc_inc_ns(c, p, &pop_seen);
  p = zx_enc_xmlns_if_not_seen(c, p, zx_ns_tab+zx_xmlns_ix_gl, &pop_seen);

  p = zx_attr_so_enc(p, x->gid, " gid=\"", sizeof(" gid=\"")-1);
  p = zx_attr_so_enc(p, x->srsName, " srsName=\"", sizeof(" srsName=\"")-1);

  p = zx_enc_unknown_attrs(p, x->gg.any_attr);
#else
  /* root node has no begin tag */
#endif
  
  {
      struct zx_gl_coord_s* e;
      for (e = x->coord; e; e = (struct zx_gl_coord_s*)e->gg.g.n)
	  p = zx_ENC_SO_gl_coord(c, e, p);
  }

  p = zx_enc_so_unknown_elems_and_content(c, p, &x->gg);
  
#if 1 /* NORMALMODE */
  ZX_OUT_CLOSE_TAG(p, "</gl:Box>");
  zx_pop_seen(pop_seen);
#else
  /* root node has no end tag either */
#endif
  ENC_LEN_DEBUG(x, "gl:Box", p-enc_base);
  return p;
}

/* FUNC(zx_ENC_WO_gl_Box) */

/* Render element into string. The XML attributes and elements are
 * processed in wire order by chasing wo pointers. This is what you want for
 * validating signatures on other people's XML documents. */

/* Called by: */
char* zx_ENC_WO_gl_Box(struct zx_ctx* c, struct zx_gl_Box_s* x, char* p )
{
  struct zx_elem_s* kid;
  struct zx_ns_s* pop_seen = 0;
  ENC_LEN_DEBUG_BASE;
#if 1 /* NORMALMODE */
  char* q;
  char* qq;
  ZX_OUT_CH(p, '<');
  q = p;
  if (x->gg.g.ns && x->gg.g.ns->prefix_len) {
    ZX_OUT_MEM(p, x->gg.g.ns->prefix, x->gg.g.ns->prefix_len);
    ZX_OUT_CH(p, ':');
  }
  ZX_OUT_MEM(p, "Box", sizeof("Box")-1);
  qq = p;

  /* *** sort the namespaces */
  if (c->inc_ns)
    zx_add_inc_ns(c, &pop_seen);
  zx_add_xmlns_if_not_seen(c, x->gg.g.ns, &pop_seen);

  p = zx_enc_seen(p, pop_seen); 
  p = zx_attr_wo_enc(p, x->gid, "gid=\"", sizeof("gid=\"")-1);
  p = zx_attr_wo_enc(p, x->srsName, "srsName=\"", sizeof("srsName=\"")-1);

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
  ENC_LEN_DEBUG(x, "gl:Box", p-enc_base);
  return p;
}

/* FUNC(zx_EASY_ENC_SO_gl_Box) */

/* Called by: */
struct zx_str* zx_EASY_ENC_SO_gl_Box(struct zx_ctx* c, struct zx_gl_Box_s* x )
{
  int len;
  char* buf;
  c->ns_tab = ZX_ALLOC(c, sizeof(zx_ns_tab));
  memcpy(c->ns_tab, zx_ns_tab, sizeof(zx_ns_tab));
  len = zx_LEN_SO_gl_Box(c, x );
  buf = ZX_ALLOC(c, len+1);
  return zx_easy_enc_common(c, zx_ENC_SO_gl_Box(c, x, buf ), buf, len);
}

/* FUNC(zx_EASY_ENC_WO_gl_Box) */

/* Called by: */
struct zx_str* zx_EASY_ENC_WO_gl_Box(struct zx_ctx* c, struct zx_gl_Box_s* x )
{
  int len;
  char* buf;
  c->ns_tab = ZX_ALLOC(c, sizeof(zx_ns_tab));
  memcpy(c->ns_tab, zx_ns_tab, sizeof(zx_ns_tab));
  len = zx_LEN_WO_gl_Box(c, x );
  buf = ZX_ALLOC(c, len+1);
  return zx_easy_enc_common(c, zx_ENC_WO_gl_Box(c, x, buf ), buf, len);
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

#define EL_NAME   gl_ChangeArea
#define EL_STRUCT zx_gl_ChangeArea_s
#define EL_NS     gl
#define EL_TAG    ChangeArea

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

/* FUNC(zx_LEN_SO_gl_ChangeArea) */

/* Compute length of an element (and its subelements). The XML attributes
 * and elements are processed in schema order. */

/* Called by: */
int zx_LEN_SO_gl_ChangeArea(struct zx_ctx* c, struct zx_gl_ChangeArea_s* x )
{
  struct zx_ns_s* pop_seen = 0;
  struct zx_elem_s* se MAYBE_UNUSED;
#if 1 /* NORMALMODE */
  /* *** in simple_elem case should output ns prefix from ns node. */
  int len = sizeof("<gl:ChangeArea")-1 + 1 + sizeof("</gl:ChangeArea>")-1;
  if (c->inc_ns_len)
    len += zx_len_inc_ns(c, &pop_seen);
  len += zx_len_xmlns_if_not_seen(c, zx_ns_tab+zx_xmlns_ix_gl, &pop_seen);

  len += zx_attr_so_len(x->event, sizeof("event")-1);

#else
  /* root node has no begin tag */
  int len = 0;
#endif
  
  {
      struct zx_gl_CivilData_s* e;
      for (e = x->CivilData; e; e = (struct zx_gl_CivilData_s*)e->gg.g.n)
	  len += zx_LEN_SO_gl_CivilData(c, e);
  }
  {
      struct zx_gl_shape_s* e;
      for (e = x->shape; e; e = (struct zx_gl_shape_s*)e->gg.g.n)
	  len += zx_LEN_SO_gl_shape(c, e);
  }
  {
      struct zx_gl_Extension_s* e;
      for (e = x->Extension; e; e = (struct zx_gl_Extension_s*)e->gg.g.n)
	  len += zx_LEN_SO_gl_Extension(c, e);
  }


  len += zx_len_so_common(c, &x->gg);
  zx_pop_seen(pop_seen);
  ENC_LEN_DEBUG(x, "gl:ChangeArea", len);
  return len;
}

/* FUNC(zx_LEN_WO_gl_ChangeArea) */

/* Compute length of an element (and its subelements). The XML attributes
 * and elements are processed in wire order and no assumptions
 * are made about namespace prefixes. */

/* Called by: */
int zx_LEN_WO_gl_ChangeArea(struct zx_ctx* c, struct zx_gl_ChangeArea_s* x )
{
  struct zx_ns_s* pop_seen = 0;
  struct zx_elem_s* se MAYBE_UNUSED;
#if 1 /* NORMALMODE */
  int len = 1 + sizeof("ChangeArea")-1 + 1 + 2 + sizeof("ChangeArea")-1 + 1;
  
  if (x->gg.g.ns && x->gg.g.ns->prefix_len)
    len += (x->gg.g.ns->prefix_len + 1) * 2;
  if (c->inc_ns_len)
    len += zx_len_inc_ns(c, &pop_seen);
  len += zx_len_xmlns_if_not_seen(c, x->gg.g.ns, &pop_seen);

  len += zx_attr_wo_len(x->event, sizeof("event")-1);

#else
  /* root node has no begin tag */
  int len = 0;
#endif
  
  {
      struct zx_gl_CivilData_s* e;
      for (e = x->CivilData; e; e = (struct zx_gl_CivilData_s*)e->gg.g.n)
	  len += zx_LEN_WO_gl_CivilData(c, e);
  }
  {
      struct zx_gl_shape_s* e;
      for (e = x->shape; e; e = (struct zx_gl_shape_s*)e->gg.g.n)
	  len += zx_LEN_WO_gl_shape(c, e);
  }
  {
      struct zx_gl_Extension_s* e;
      for (e = x->Extension; e; e = (struct zx_gl_Extension_s*)e->gg.g.n)
	  len += zx_LEN_WO_gl_Extension(c, e);
  }


  len += zx_len_wo_common(c, &x->gg); 
  zx_pop_seen(pop_seen);
  ENC_LEN_DEBUG(x, "gl:ChangeArea", len);
  return len;
}

/* FUNC(zx_ENC_SO_gl_ChangeArea) */

/* Render element into string. The XML attributes and elements are
 * processed in schema order. This is what you generally want for
 * rendering new data structure to a string. The wo pointers are not used. */

/* Called by: */
char* zx_ENC_SO_gl_ChangeArea(struct zx_ctx* c, struct zx_gl_ChangeArea_s* x, char* p )
{
  struct zx_elem_s* se MAYBE_UNUSED;
  struct zx_ns_s* pop_seen = 0;
  ENC_LEN_DEBUG_BASE;
#if 1 /* NORMALMODE */
  /* *** in simple_elem case should output ns prefix from ns node. */
  ZX_OUT_TAG(p, "<gl:ChangeArea");
  if (c->inc_ns)
    p = zx_enc_inc_ns(c, p, &pop_seen);
  p = zx_enc_xmlns_if_not_seen(c, p, zx_ns_tab+zx_xmlns_ix_gl, &pop_seen);

  p = zx_attr_so_enc(p, x->event, " event=\"", sizeof(" event=\"")-1);

  p = zx_enc_unknown_attrs(p, x->gg.any_attr);
#else
  /* root node has no begin tag */
#endif
  
  {
      struct zx_gl_CivilData_s* e;
      for (e = x->CivilData; e; e = (struct zx_gl_CivilData_s*)e->gg.g.n)
	  p = zx_ENC_SO_gl_CivilData(c, e, p);
  }
  {
      struct zx_gl_shape_s* e;
      for (e = x->shape; e; e = (struct zx_gl_shape_s*)e->gg.g.n)
	  p = zx_ENC_SO_gl_shape(c, e, p);
  }
  {
      struct zx_gl_Extension_s* e;
      for (e = x->Extension; e; e = (struct zx_gl_Extension_s*)e->gg.g.n)
	  p = zx_ENC_SO_gl_Extension(c, e, p);
  }

  p = zx_enc_so_unknown_elems_and_content(c, p, &x->gg);
  
#if 1 /* NORMALMODE */
  ZX_OUT_CLOSE_TAG(p, "</gl:ChangeArea>");
  zx_pop_seen(pop_seen);
#else
  /* root node has no end tag either */
#endif
  ENC_LEN_DEBUG(x, "gl:ChangeArea", p-enc_base);
  return p;
}

/* FUNC(zx_ENC_WO_gl_ChangeArea) */

/* Render element into string. The XML attributes and elements are
 * processed in wire order by chasing wo pointers. This is what you want for
 * validating signatures on other people's XML documents. */

/* Called by: */
char* zx_ENC_WO_gl_ChangeArea(struct zx_ctx* c, struct zx_gl_ChangeArea_s* x, char* p )
{
  struct zx_elem_s* kid;
  struct zx_ns_s* pop_seen = 0;
  ENC_LEN_DEBUG_BASE;
#if 1 /* NORMALMODE */
  char* q;
  char* qq;
  ZX_OUT_CH(p, '<');
  q = p;
  if (x->gg.g.ns && x->gg.g.ns->prefix_len) {
    ZX_OUT_MEM(p, x->gg.g.ns->prefix, x->gg.g.ns->prefix_len);
    ZX_OUT_CH(p, ':');
  }
  ZX_OUT_MEM(p, "ChangeArea", sizeof("ChangeArea")-1);
  qq = p;

  /* *** sort the namespaces */
  if (c->inc_ns)
    zx_add_inc_ns(c, &pop_seen);
  zx_add_xmlns_if_not_seen(c, x->gg.g.ns, &pop_seen);

  p = zx_enc_seen(p, pop_seen); 
  p = zx_attr_wo_enc(p, x->event, "event=\"", sizeof("event=\"")-1);

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
  ENC_LEN_DEBUG(x, "gl:ChangeArea", p-enc_base);
  return p;
}

/* FUNC(zx_EASY_ENC_SO_gl_ChangeArea) */

/* Called by: */
struct zx_str* zx_EASY_ENC_SO_gl_ChangeArea(struct zx_ctx* c, struct zx_gl_ChangeArea_s* x )
{
  int len;
  char* buf;
  c->ns_tab = ZX_ALLOC(c, sizeof(zx_ns_tab));
  memcpy(c->ns_tab, zx_ns_tab, sizeof(zx_ns_tab));
  len = zx_LEN_SO_gl_ChangeArea(c, x );
  buf = ZX_ALLOC(c, len+1);
  return zx_easy_enc_common(c, zx_ENC_SO_gl_ChangeArea(c, x, buf ), buf, len);
}

/* FUNC(zx_EASY_ENC_WO_gl_ChangeArea) */

/* Called by: */
struct zx_str* zx_EASY_ENC_WO_gl_ChangeArea(struct zx_ctx* c, struct zx_gl_ChangeArea_s* x )
{
  int len;
  char* buf;
  c->ns_tab = ZX_ALLOC(c, sizeof(zx_ns_tab));
  memcpy(c->ns_tab, zx_ns_tab, sizeof(zx_ns_tab));
  len = zx_LEN_WO_gl_ChangeArea(c, x );
  buf = ZX_ALLOC(c, len+1);
  return zx_easy_enc_common(c, zx_ENC_WO_gl_ChangeArea(c, x, buf ), buf, len);
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

#define EL_NAME   gl_CircularArcArea
#define EL_STRUCT zx_gl_CircularArcArea_s
#define EL_NS     gl
#define EL_TAG    CircularArcArea

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

/* FUNC(zx_LEN_SO_gl_CircularArcArea) */

/* Compute length of an element (and its subelements). The XML attributes
 * and elements are processed in schema order. */

/* Called by: */
int zx_LEN_SO_gl_CircularArcArea(struct zx_ctx* c, struct zx_gl_CircularArcArea_s* x )
{
  struct zx_ns_s* pop_seen = 0;
  struct zx_elem_s* se MAYBE_UNUSED;
#if 1 /* NORMALMODE */
  /* *** in simple_elem case should output ns prefix from ns node. */
  int len = sizeof("<gl:CircularArcArea")-1 + 1 + sizeof("</gl:CircularArcArea>")-1;
  if (c->inc_ns_len)
    len += zx_len_inc_ns(c, &pop_seen);
  len += zx_len_xmlns_if_not_seen(c, zx_ns_tab+zx_xmlns_ix_gl, &pop_seen);

  len += zx_attr_so_len(x->gid, sizeof("gid")-1);
  len += zx_attr_so_len(x->srsName, sizeof("srsName")-1);

#else
  /* root node has no begin tag */
  int len = 0;
#endif
  
  {
      struct zx_gl_coord_s* e;
      for (e = x->coord; e; e = (struct zx_gl_coord_s*)e->gg.g.n)
	  len += zx_LEN_SO_gl_coord(c, e);
  }
  for (se = x->inRadius; se; se = (struct zx_elem_s*)se->g.n)
    len += zx_LEN_SO_simple_elem(c,se, sizeof("gl:inRadius")-1, zx_ns_tab+zx_xmlns_ix_gl);
  for (se = x->outRadius; se; se = (struct zx_elem_s*)se->g.n)
    len += zx_LEN_SO_simple_elem(c,se, sizeof("gl:outRadius")-1, zx_ns_tab+zx_xmlns_ix_gl);
  for (se = x->startAngle; se; se = (struct zx_elem_s*)se->g.n)
    len += zx_LEN_SO_simple_elem(c,se, sizeof("gl:startAngle")-1, zx_ns_tab+zx_xmlns_ix_gl);
  for (se = x->stopAngle; se; se = (struct zx_elem_s*)se->g.n)
    len += zx_LEN_SO_simple_elem(c,se, sizeof("gl:stopAngle")-1, zx_ns_tab+zx_xmlns_ix_gl);
  for (se = x->angularUnit; se; se = (struct zx_elem_s*)se->g.n)
    len += zx_LEN_SO_simple_elem(c,se, sizeof("gl:angularUnit")-1, zx_ns_tab+zx_xmlns_ix_gl);
  for (se = x->distanceUnit; se; se = (struct zx_elem_s*)se->g.n)
    len += zx_LEN_SO_simple_elem(c,se, sizeof("gl:distanceUnit")-1, zx_ns_tab+zx_xmlns_ix_gl);


  len += zx_len_so_common(c, &x->gg);
  zx_pop_seen(pop_seen);
  ENC_LEN_DEBUG(x, "gl:CircularArcArea", len);
  return len;
}

/* FUNC(zx_LEN_WO_gl_CircularArcArea) */

/* Compute length of an element (and its subelements). The XML attributes
 * and elements are processed in wire order and no assumptions
 * are made about namespace prefixes. */

/* Called by: */
int zx_LEN_WO_gl_CircularArcArea(struct zx_ctx* c, struct zx_gl_CircularArcArea_s* x )
{
  struct zx_ns_s* pop_seen = 0;
  struct zx_elem_s* se MAYBE_UNUSED;
#if 1 /* NORMALMODE */
  int len = 1 + sizeof("CircularArcArea")-1 + 1 + 2 + sizeof("CircularArcArea")-1 + 1;
  
  if (x->gg.g.ns && x->gg.g.ns->prefix_len)
    len += (x->gg.g.ns->prefix_len + 1) * 2;
  if (c->inc_ns_len)
    len += zx_len_inc_ns(c, &pop_seen);
  len += zx_len_xmlns_if_not_seen(c, x->gg.g.ns, &pop_seen);

  len += zx_attr_wo_len(x->gid, sizeof("gid")-1);
  len += zx_attr_wo_len(x->srsName, sizeof("srsName")-1);

#else
  /* root node has no begin tag */
  int len = 0;
#endif
  
  {
      struct zx_gl_coord_s* e;
      for (e = x->coord; e; e = (struct zx_gl_coord_s*)e->gg.g.n)
	  len += zx_LEN_WO_gl_coord(c, e);
  }
  for (se = x->inRadius; se; se = (struct zx_elem_s*)se->g.n)
    len += zx_LEN_WO_simple_elem(c, se, sizeof("inRadius")-1);
  for (se = x->outRadius; se; se = (struct zx_elem_s*)se->g.n)
    len += zx_LEN_WO_simple_elem(c, se, sizeof("outRadius")-1);
  for (se = x->startAngle; se; se = (struct zx_elem_s*)se->g.n)
    len += zx_LEN_WO_simple_elem(c, se, sizeof("startAngle")-1);
  for (se = x->stopAngle; se; se = (struct zx_elem_s*)se->g.n)
    len += zx_LEN_WO_simple_elem(c, se, sizeof("stopAngle")-1);
  for (se = x->angularUnit; se; se = (struct zx_elem_s*)se->g.n)
    len += zx_LEN_WO_simple_elem(c, se, sizeof("angularUnit")-1);
  for (se = x->distanceUnit; se; se = (struct zx_elem_s*)se->g.n)
    len += zx_LEN_WO_simple_elem(c, se, sizeof("distanceUnit")-1);


  len += zx_len_wo_common(c, &x->gg); 
  zx_pop_seen(pop_seen);
  ENC_LEN_DEBUG(x, "gl:CircularArcArea", len);
  return len;
}

/* FUNC(zx_ENC_SO_gl_CircularArcArea) */

/* Render element into string. The XML attributes and elements are
 * processed in schema order. This is what you generally want for
 * rendering new data structure to a string. The wo pointers are not used. */

/* Called by: */
char* zx_ENC_SO_gl_CircularArcArea(struct zx_ctx* c, struct zx_gl_CircularArcArea_s* x, char* p )
{
  struct zx_elem_s* se MAYBE_UNUSED;
  struct zx_ns_s* pop_seen = 0;
  ENC_LEN_DEBUG_BASE;
#if 1 /* NORMALMODE */
  /* *** in simple_elem case should output ns prefix from ns node. */
  ZX_OUT_TAG(p, "<gl:CircularArcArea");
  if (c->inc_ns)
    p = zx_enc_inc_ns(c, p, &pop_seen);
  p = zx_enc_xmlns_if_not_seen(c, p, zx_ns_tab+zx_xmlns_ix_gl, &pop_seen);

  p = zx_attr_so_enc(p, x->gid, " gid=\"", sizeof(" gid=\"")-1);
  p = zx_attr_so_enc(p, x->srsName, " srsName=\"", sizeof(" srsName=\"")-1);

  p = zx_enc_unknown_attrs(p, x->gg.any_attr);
#else
  /* root node has no begin tag */
#endif
  
  {
      struct zx_gl_coord_s* e;
      for (e = x->coord; e; e = (struct zx_gl_coord_s*)e->gg.g.n)
	  p = zx_ENC_SO_gl_coord(c, e, p);
  }
  for (se = x->inRadius; se; se = (struct zx_elem_s*)se->g.n)
    p = zx_ENC_SO_simple_elem(c, se, p, "gl:inRadius", sizeof("gl:inRadius")-1, zx_ns_tab+zx_xmlns_ix_gl);
  for (se = x->outRadius; se; se = (struct zx_elem_s*)se->g.n)
    p = zx_ENC_SO_simple_elem(c, se, p, "gl:outRadius", sizeof("gl:outRadius")-1, zx_ns_tab+zx_xmlns_ix_gl);
  for (se = x->startAngle; se; se = (struct zx_elem_s*)se->g.n)
    p = zx_ENC_SO_simple_elem(c, se, p, "gl:startAngle", sizeof("gl:startAngle")-1, zx_ns_tab+zx_xmlns_ix_gl);
  for (se = x->stopAngle; se; se = (struct zx_elem_s*)se->g.n)
    p = zx_ENC_SO_simple_elem(c, se, p, "gl:stopAngle", sizeof("gl:stopAngle")-1, zx_ns_tab+zx_xmlns_ix_gl);
  for (se = x->angularUnit; se; se = (struct zx_elem_s*)se->g.n)
    p = zx_ENC_SO_simple_elem(c, se, p, "gl:angularUnit", sizeof("gl:angularUnit")-1, zx_ns_tab+zx_xmlns_ix_gl);
  for (se = x->distanceUnit; se; se = (struct zx_elem_s*)se->g.n)
    p = zx_ENC_SO_simple_elem(c, se, p, "gl:distanceUnit", sizeof("gl:distanceUnit")-1, zx_ns_tab+zx_xmlns_ix_gl);

  p = zx_enc_so_unknown_elems_and_content(c, p, &x->gg);
  
#if 1 /* NORMALMODE */
  ZX_OUT_CLOSE_TAG(p, "</gl:CircularArcArea>");
  zx_pop_seen(pop_seen);
#else
  /* root node has no end tag either */
#endif
  ENC_LEN_DEBUG(x, "gl:CircularArcArea", p-enc_base);
  return p;
}

/* FUNC(zx_ENC_WO_gl_CircularArcArea) */

/* Render element into string. The XML attributes and elements are
 * processed in wire order by chasing wo pointers. This is what you want for
 * validating signatures on other people's XML documents. */

/* Called by: */
char* zx_ENC_WO_gl_CircularArcArea(struct zx_ctx* c, struct zx_gl_CircularArcArea_s* x, char* p )
{
  struct zx_elem_s* kid;
  struct zx_ns_s* pop_seen = 0;
  ENC_LEN_DEBUG_BASE;
#if 1 /* NORMALMODE */
  char* q;
  char* qq;
  ZX_OUT_CH(p, '<');
  q = p;
  if (x->gg.g.ns && x->gg.g.ns->prefix_len) {
    ZX_OUT_MEM(p, x->gg.g.ns->prefix, x->gg.g.ns->prefix_len);
    ZX_OUT_CH(p, ':');
  }
  ZX_OUT_MEM(p, "CircularArcArea", sizeof("CircularArcArea")-1);
  qq = p;

  /* *** sort the namespaces */
  if (c->inc_ns)
    zx_add_inc_ns(c, &pop_seen);
  zx_add_xmlns_if_not_seen(c, x->gg.g.ns, &pop_seen);

  p = zx_enc_seen(p, pop_seen); 
  p = zx_attr_wo_enc(p, x->gid, "gid=\"", sizeof("gid=\"")-1);
  p = zx_attr_wo_enc(p, x->srsName, "srsName=\"", sizeof("srsName=\"")-1);

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
  ENC_LEN_DEBUG(x, "gl:CircularArcArea", p-enc_base);
  return p;
}

/* FUNC(zx_EASY_ENC_SO_gl_CircularArcArea) */

/* Called by: */
struct zx_str* zx_EASY_ENC_SO_gl_CircularArcArea(struct zx_ctx* c, struct zx_gl_CircularArcArea_s* x )
{
  int len;
  char* buf;
  c->ns_tab = ZX_ALLOC(c, sizeof(zx_ns_tab));
  memcpy(c->ns_tab, zx_ns_tab, sizeof(zx_ns_tab));
  len = zx_LEN_SO_gl_CircularArcArea(c, x );
  buf = ZX_ALLOC(c, len+1);
  return zx_easy_enc_common(c, zx_ENC_SO_gl_CircularArcArea(c, x, buf ), buf, len);
}

/* FUNC(zx_EASY_ENC_WO_gl_CircularArcArea) */

/* Called by: */
struct zx_str* zx_EASY_ENC_WO_gl_CircularArcArea(struct zx_ctx* c, struct zx_gl_CircularArcArea_s* x )
{
  int len;
  char* buf;
  c->ns_tab = ZX_ALLOC(c, sizeof(zx_ns_tab));
  memcpy(c->ns_tab, zx_ns_tab, sizeof(zx_ns_tab));
  len = zx_LEN_WO_gl_CircularArcArea(c, x );
  buf = ZX_ALLOC(c, len+1);
  return zx_easy_enc_common(c, zx_ENC_WO_gl_CircularArcArea(c, x, buf ), buf, len);
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

#define EL_NAME   gl_CircularArea
#define EL_STRUCT zx_gl_CircularArea_s
#define EL_NS     gl
#define EL_TAG    CircularArea

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

/* FUNC(zx_LEN_SO_gl_CircularArea) */

/* Compute length of an element (and its subelements). The XML attributes
 * and elements are processed in schema order. */

/* Called by: */
int zx_LEN_SO_gl_CircularArea(struct zx_ctx* c, struct zx_gl_CircularArea_s* x )
{
  struct zx_ns_s* pop_seen = 0;
  struct zx_elem_s* se MAYBE_UNUSED;
#if 1 /* NORMALMODE */
  /* *** in simple_elem case should output ns prefix from ns node. */
  int len = sizeof("<gl:CircularArea")-1 + 1 + sizeof("</gl:CircularArea>")-1;
  if (c->inc_ns_len)
    len += zx_len_inc_ns(c, &pop_seen);
  len += zx_len_xmlns_if_not_seen(c, zx_ns_tab+zx_xmlns_ix_gl, &pop_seen);

  len += zx_attr_so_len(x->gid, sizeof("gid")-1);
  len += zx_attr_so_len(x->srsName, sizeof("srsName")-1);

#else
  /* root node has no begin tag */
  int len = 0;
#endif
  
  {
      struct zx_gl_coord_s* e;
      for (e = x->coord; e; e = (struct zx_gl_coord_s*)e->gg.g.n)
	  len += zx_LEN_SO_gl_coord(c, e);
  }
  for (se = x->radius; se; se = (struct zx_elem_s*)se->g.n)
    len += zx_LEN_SO_simple_elem(c,se, sizeof("gl:radius")-1, zx_ns_tab+zx_xmlns_ix_gl);
  for (se = x->distanceUnit; se; se = (struct zx_elem_s*)se->g.n)
    len += zx_LEN_SO_simple_elem(c,se, sizeof("gl:distanceUnit")-1, zx_ns_tab+zx_xmlns_ix_gl);


  len += zx_len_so_common(c, &x->gg);
  zx_pop_seen(pop_seen);
  ENC_LEN_DEBUG(x, "gl:CircularArea", len);
  return len;
}

/* FUNC(zx_LEN_WO_gl_CircularArea) */

/* Compute length of an element (and its subelements). The XML attributes
 * and elements are processed in wire order and no assumptions
 * are made about namespace prefixes. */

/* Called by: */
int zx_LEN_WO_gl_CircularArea(struct zx_ctx* c, struct zx_gl_CircularArea_s* x )
{
  struct zx_ns_s* pop_seen = 0;
  struct zx_elem_s* se MAYBE_UNUSED;
#if 1 /* NORMALMODE */
  int len = 1 + sizeof("CircularArea")-1 + 1 + 2 + sizeof("CircularArea")-1 + 1;
  
  if (x->gg.g.ns && x->gg.g.ns->prefix_len)
    len += (x->gg.g.ns->prefix_len + 1) * 2;
  if (c->inc_ns_len)
    len += zx_len_inc_ns(c, &pop_seen);
  len += zx_len_xmlns_if_not_seen(c, x->gg.g.ns, &pop_seen);

  len += zx_attr_wo_len(x->gid, sizeof("gid")-1);
  len += zx_attr_wo_len(x->srsName, sizeof("srsName")-1);

#else
  /* root node has no begin tag */
  int len = 0;
#endif
  
  {
      struct zx_gl_coord_s* e;
      for (e = x->coord; e; e = (struct zx_gl_coord_s*)e->gg.g.n)
	  len += zx_LEN_WO_gl_coord(c, e);
  }
  for (se = x->radius; se; se = (struct zx_elem_s*)se->g.n)
    len += zx_LEN_WO_simple_elem(c, se, sizeof("radius")-1);
  for (se = x->distanceUnit; se; se = (struct zx_elem_s*)se->g.n)
    len += zx_LEN_WO_simple_elem(c, se, sizeof("distanceUnit")-1);


  len += zx_len_wo_common(c, &x->gg); 
  zx_pop_seen(pop_seen);
  ENC_LEN_DEBUG(x, "gl:CircularArea", len);
  return len;
}

/* FUNC(zx_ENC_SO_gl_CircularArea) */

/* Render element into string. The XML attributes and elements are
 * processed in schema order. This is what you generally want for
 * rendering new data structure to a string. The wo pointers are not used. */

/* Called by: */
char* zx_ENC_SO_gl_CircularArea(struct zx_ctx* c, struct zx_gl_CircularArea_s* x, char* p )
{
  struct zx_elem_s* se MAYBE_UNUSED;
  struct zx_ns_s* pop_seen = 0;
  ENC_LEN_DEBUG_BASE;
#if 1 /* NORMALMODE */
  /* *** in simple_elem case should output ns prefix from ns node. */
  ZX_OUT_TAG(p, "<gl:CircularArea");
  if (c->inc_ns)
    p = zx_enc_inc_ns(c, p, &pop_seen);
  p = zx_enc_xmlns_if_not_seen(c, p, zx_ns_tab+zx_xmlns_ix_gl, &pop_seen);

  p = zx_attr_so_enc(p, x->gid, " gid=\"", sizeof(" gid=\"")-1);
  p = zx_attr_so_enc(p, x->srsName, " srsName=\"", sizeof(" srsName=\"")-1);

  p = zx_enc_unknown_attrs(p, x->gg.any_attr);
#else
  /* root node has no begin tag */
#endif
  
  {
      struct zx_gl_coord_s* e;
      for (e = x->coord; e; e = (struct zx_gl_coord_s*)e->gg.g.n)
	  p = zx_ENC_SO_gl_coord(c, e, p);
  }
  for (se = x->radius; se; se = (struct zx_elem_s*)se->g.n)
    p = zx_ENC_SO_simple_elem(c, se, p, "gl:radius", sizeof("gl:radius")-1, zx_ns_tab+zx_xmlns_ix_gl);
  for (se = x->distanceUnit; se; se = (struct zx_elem_s*)se->g.n)
    p = zx_ENC_SO_simple_elem(c, se, p, "gl:distanceUnit", sizeof("gl:distanceUnit")-1, zx_ns_tab+zx_xmlns_ix_gl);

  p = zx_enc_so_unknown_elems_and_content(c, p, &x->gg);
  
#if 1 /* NORMALMODE */
  ZX_OUT_CLOSE_TAG(p, "</gl:CircularArea>");
  zx_pop_seen(pop_seen);
#else
  /* root node has no end tag either */
#endif
  ENC_LEN_DEBUG(x, "gl:CircularArea", p-enc_base);
  return p;
}

/* FUNC(zx_ENC_WO_gl_CircularArea) */

/* Render element into string. The XML attributes and elements are
 * processed in wire order by chasing wo pointers. This is what you want for
 * validating signatures on other people's XML documents. */

/* Called by: */
char* zx_ENC_WO_gl_CircularArea(struct zx_ctx* c, struct zx_gl_CircularArea_s* x, char* p )
{
  struct zx_elem_s* kid;
  struct zx_ns_s* pop_seen = 0;
  ENC_LEN_DEBUG_BASE;
#if 1 /* NORMALMODE */
  char* q;
  char* qq;
  ZX_OUT_CH(p, '<');
  q = p;
  if (x->gg.g.ns && x->gg.g.ns->prefix_len) {
    ZX_OUT_MEM(p, x->gg.g.ns->prefix, x->gg.g.ns->prefix_len);
    ZX_OUT_CH(p, ':');
  }
  ZX_OUT_MEM(p, "CircularArea", sizeof("CircularArea")-1);
  qq = p;

  /* *** sort the namespaces */
  if (c->inc_ns)
    zx_add_inc_ns(c, &pop_seen);
  zx_add_xmlns_if_not_seen(c, x->gg.g.ns, &pop_seen);

  p = zx_enc_seen(p, pop_seen); 
  p = zx_attr_wo_enc(p, x->gid, "gid=\"", sizeof("gid=\"")-1);
  p = zx_attr_wo_enc(p, x->srsName, "srsName=\"", sizeof("srsName=\"")-1);

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
  ENC_LEN_DEBUG(x, "gl:CircularArea", p-enc_base);
  return p;
}

/* FUNC(zx_EASY_ENC_SO_gl_CircularArea) */

/* Called by: */
struct zx_str* zx_EASY_ENC_SO_gl_CircularArea(struct zx_ctx* c, struct zx_gl_CircularArea_s* x )
{
  int len;
  char* buf;
  c->ns_tab = ZX_ALLOC(c, sizeof(zx_ns_tab));
  memcpy(c->ns_tab, zx_ns_tab, sizeof(zx_ns_tab));
  len = zx_LEN_SO_gl_CircularArea(c, x );
  buf = ZX_ALLOC(c, len+1);
  return zx_easy_enc_common(c, zx_ENC_SO_gl_CircularArea(c, x, buf ), buf, len);
}

/* FUNC(zx_EASY_ENC_WO_gl_CircularArea) */

/* Called by: */
struct zx_str* zx_EASY_ENC_WO_gl_CircularArea(struct zx_ctx* c, struct zx_gl_CircularArea_s* x )
{
  int len;
  char* buf;
  c->ns_tab = ZX_ALLOC(c, sizeof(zx_ns_tab));
  memcpy(c->ns_tab, zx_ns_tab, sizeof(zx_ns_tab));
  len = zx_LEN_WO_gl_CircularArea(c, x );
  buf = ZX_ALLOC(c, len+1);
  return zx_easy_enc_common(c, zx_ENC_WO_gl_CircularArea(c, x, buf ), buf, len);
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

#define EL_NAME   gl_CivilData
#define EL_STRUCT zx_gl_CivilData_s
#define EL_NS     gl
#define EL_TAG    CivilData

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

/* FUNC(zx_LEN_SO_gl_CivilData) */

/* Compute length of an element (and its subelements). The XML attributes
 * and elements are processed in schema order. */

/* Called by: */
int zx_LEN_SO_gl_CivilData(struct zx_ctx* c, struct zx_gl_CivilData_s* x )
{
  struct zx_ns_s* pop_seen = 0;
  struct zx_elem_s* se MAYBE_UNUSED;
#if 1 /* NORMALMODE */
  /* *** in simple_elem case should output ns prefix from ns node. */
  int len = sizeof("<gl:CivilData")-1 + 1 + sizeof("</gl:CivilData>")-1;
  if (c->inc_ns_len)
    len += zx_len_inc_ns(c, &pop_seen);
  len += zx_len_xmlns_if_not_seen(c, zx_ns_tab+zx_xmlns_ix_gl, &pop_seen);


#else
  /* root node has no begin tag */
  int len = 0;
#endif
  
  for (se = x->PostalAddress; se; se = (struct zx_elem_s*)se->g.n)
    len += zx_LEN_SO_simple_elem(c,se, sizeof("gl:PostalAddress")-1, zx_ns_tab+zx_xmlns_ix_gl);
  {
      struct zx_gl_LPostalAddress_s* e;
      for (e = x->LPostalAddress; e; e = (struct zx_gl_LPostalAddress_s*)e->gg.g.n)
	  len += zx_LEN_SO_gl_LPostalAddress(c, e);
  }
  for (se = x->PostalCode; se; se = (struct zx_elem_s*)se->g.n)
    len += zx_LEN_SO_simple_elem(c,se, sizeof("gl:PostalCode")-1, zx_ns_tab+zx_xmlns_ix_gl);
  for (se = x->L; se; se = (struct zx_elem_s*)se->g.n)
    len += zx_LEN_SO_simple_elem(c,se, sizeof("gl:L")-1, zx_ns_tab+zx_xmlns_ix_gl);
  {
      struct zx_gl_LL_s* e;
      for (e = x->LL; e; e = (struct zx_gl_LL_s*)e->gg.g.n)
	  len += zx_LEN_SO_gl_LL(c, e);
  }
  for (se = x->St; se; se = (struct zx_elem_s*)se->g.n)
    len += zx_LEN_SO_simple_elem(c,se, sizeof("gl:St")-1, zx_ns_tab+zx_xmlns_ix_gl);
  {
      struct zx_gl_LSt_s* e;
      for (e = x->LSt; e; e = (struct zx_gl_LSt_s*)e->gg.g.n)
	  len += zx_LEN_SO_gl_LSt(c, e);
  }
  for (se = x->C; se; se = (struct zx_elem_s*)se->g.n)
    len += zx_LEN_SO_simple_elem(c,se, sizeof("gl:C")-1, zx_ns_tab+zx_xmlns_ix_gl);
  for (se = x->MNC; se; se = (struct zx_elem_s*)se->g.n)
    len += zx_LEN_SO_simple_elem(c,se, sizeof("gl:MNC")-1, zx_ns_tab+zx_xmlns_ix_gl);
  {
      struct zx_gl_Extension_s* e;
      for (e = x->Extension; e; e = (struct zx_gl_Extension_s*)e->gg.g.n)
	  len += zx_LEN_SO_gl_Extension(c, e);
  }


  len += zx_len_so_common(c, &x->gg);
  zx_pop_seen(pop_seen);
  ENC_LEN_DEBUG(x, "gl:CivilData", len);
  return len;
}

/* FUNC(zx_LEN_WO_gl_CivilData) */

/* Compute length of an element (and its subelements). The XML attributes
 * and elements are processed in wire order and no assumptions
 * are made about namespace prefixes. */

/* Called by: */
int zx_LEN_WO_gl_CivilData(struct zx_ctx* c, struct zx_gl_CivilData_s* x )
{
  struct zx_ns_s* pop_seen = 0;
  struct zx_elem_s* se MAYBE_UNUSED;
#if 1 /* NORMALMODE */
  int len = 1 + sizeof("CivilData")-1 + 1 + 2 + sizeof("CivilData")-1 + 1;
  
  if (x->gg.g.ns && x->gg.g.ns->prefix_len)
    len += (x->gg.g.ns->prefix_len + 1) * 2;
  if (c->inc_ns_len)
    len += zx_len_inc_ns(c, &pop_seen);
  len += zx_len_xmlns_if_not_seen(c, x->gg.g.ns, &pop_seen);


#else
  /* root node has no begin tag */
  int len = 0;
#endif
  
  for (se = x->PostalAddress; se; se = (struct zx_elem_s*)se->g.n)
    len += zx_LEN_WO_simple_elem(c, se, sizeof("PostalAddress")-1);
  {
      struct zx_gl_LPostalAddress_s* e;
      for (e = x->LPostalAddress; e; e = (struct zx_gl_LPostalAddress_s*)e->gg.g.n)
	  len += zx_LEN_WO_gl_LPostalAddress(c, e);
  }
  for (se = x->PostalCode; se; se = (struct zx_elem_s*)se->g.n)
    len += zx_LEN_WO_simple_elem(c, se, sizeof("PostalCode")-1);
  for (se = x->L; se; se = (struct zx_elem_s*)se->g.n)
    len += zx_LEN_WO_simple_elem(c, se, sizeof("L")-1);
  {
      struct zx_gl_LL_s* e;
      for (e = x->LL; e; e = (struct zx_gl_LL_s*)e->gg.g.n)
	  len += zx_LEN_WO_gl_LL(c, e);
  }
  for (se = x->St; se; se = (struct zx_elem_s*)se->g.n)
    len += zx_LEN_WO_simple_elem(c, se, sizeof("St")-1);
  {
      struct zx_gl_LSt_s* e;
      for (e = x->LSt; e; e = (struct zx_gl_LSt_s*)e->gg.g.n)
	  len += zx_LEN_WO_gl_LSt(c, e);
  }
  for (se = x->C; se; se = (struct zx_elem_s*)se->g.n)
    len += zx_LEN_WO_simple_elem(c, se, sizeof("C")-1);
  for (se = x->MNC; se; se = (struct zx_elem_s*)se->g.n)
    len += zx_LEN_WO_simple_elem(c, se, sizeof("MNC")-1);
  {
      struct zx_gl_Extension_s* e;
      for (e = x->Extension; e; e = (struct zx_gl_Extension_s*)e->gg.g.n)
	  len += zx_LEN_WO_gl_Extension(c, e);
  }


  len += zx_len_wo_common(c, &x->gg); 
  zx_pop_seen(pop_seen);
  ENC_LEN_DEBUG(x, "gl:CivilData", len);
  return len;
}

/* FUNC(zx_ENC_SO_gl_CivilData) */

/* Render element into string. The XML attributes and elements are
 * processed in schema order. This is what you generally want for
 * rendering new data structure to a string. The wo pointers are not used. */

/* Called by: */
char* zx_ENC_SO_gl_CivilData(struct zx_ctx* c, struct zx_gl_CivilData_s* x, char* p )
{
  struct zx_elem_s* se MAYBE_UNUSED;
  struct zx_ns_s* pop_seen = 0;
  ENC_LEN_DEBUG_BASE;
#if 1 /* NORMALMODE */
  /* *** in simple_elem case should output ns prefix from ns node. */
  ZX_OUT_TAG(p, "<gl:CivilData");
  if (c->inc_ns)
    p = zx_enc_inc_ns(c, p, &pop_seen);
  p = zx_enc_xmlns_if_not_seen(c, p, zx_ns_tab+zx_xmlns_ix_gl, &pop_seen);


  p = zx_enc_unknown_attrs(p, x->gg.any_attr);
#else
  /* root node has no begin tag */
#endif
  
  for (se = x->PostalAddress; se; se = (struct zx_elem_s*)se->g.n)
    p = zx_ENC_SO_simple_elem(c, se, p, "gl:PostalAddress", sizeof("gl:PostalAddress")-1, zx_ns_tab+zx_xmlns_ix_gl);
  {
      struct zx_gl_LPostalAddress_s* e;
      for (e = x->LPostalAddress; e; e = (struct zx_gl_LPostalAddress_s*)e->gg.g.n)
	  p = zx_ENC_SO_gl_LPostalAddress(c, e, p);
  }
  for (se = x->PostalCode; se; se = (struct zx_elem_s*)se->g.n)
    p = zx_ENC_SO_simple_elem(c, se, p, "gl:PostalCode", sizeof("gl:PostalCode")-1, zx_ns_tab+zx_xmlns_ix_gl);
  for (se = x->L; se; se = (struct zx_elem_s*)se->g.n)
    p = zx_ENC_SO_simple_elem(c, se, p, "gl:L", sizeof("gl:L")-1, zx_ns_tab+zx_xmlns_ix_gl);
  {
      struct zx_gl_LL_s* e;
      for (e = x->LL; e; e = (struct zx_gl_LL_s*)e->gg.g.n)
	  p = zx_ENC_SO_gl_LL(c, e, p);
  }
  for (se = x->St; se; se = (struct zx_elem_s*)se->g.n)
    p = zx_ENC_SO_simple_elem(c, se, p, "gl:St", sizeof("gl:St")-1, zx_ns_tab+zx_xmlns_ix_gl);
  {
      struct zx_gl_LSt_s* e;
      for (e = x->LSt; e; e = (struct zx_gl_LSt_s*)e->gg.g.n)
	  p = zx_ENC_SO_gl_LSt(c, e, p);
  }
  for (se = x->C; se; se = (struct zx_elem_s*)se->g.n)
    p = zx_ENC_SO_simple_elem(c, se, p, "gl:C", sizeof("gl:C")-1, zx_ns_tab+zx_xmlns_ix_gl);
  for (se = x->MNC; se; se = (struct zx_elem_s*)se->g.n)
    p = zx_ENC_SO_simple_elem(c, se, p, "gl:MNC", sizeof("gl:MNC")-1, zx_ns_tab+zx_xmlns_ix_gl);
  {
      struct zx_gl_Extension_s* e;
      for (e = x->Extension; e; e = (struct zx_gl_Extension_s*)e->gg.g.n)
	  p = zx_ENC_SO_gl_Extension(c, e, p);
  }

  p = zx_enc_so_unknown_elems_and_content(c, p, &x->gg);
  
#if 1 /* NORMALMODE */
  ZX_OUT_CLOSE_TAG(p, "</gl:CivilData>");
  zx_pop_seen(pop_seen);
#else
  /* root node has no end tag either */
#endif
  ENC_LEN_DEBUG(x, "gl:CivilData", p-enc_base);
  return p;
}

/* FUNC(zx_ENC_WO_gl_CivilData) */

/* Render element into string. The XML attributes and elements are
 * processed in wire order by chasing wo pointers. This is what you want for
 * validating signatures on other people's XML documents. */

/* Called by: */
char* zx_ENC_WO_gl_CivilData(struct zx_ctx* c, struct zx_gl_CivilData_s* x, char* p )
{
  struct zx_elem_s* kid;
  struct zx_ns_s* pop_seen = 0;
  ENC_LEN_DEBUG_BASE;
#if 1 /* NORMALMODE */
  char* q;
  char* qq;
  ZX_OUT_CH(p, '<');
  q = p;
  if (x->gg.g.ns && x->gg.g.ns->prefix_len) {
    ZX_OUT_MEM(p, x->gg.g.ns->prefix, x->gg.g.ns->prefix_len);
    ZX_OUT_CH(p, ':');
  }
  ZX_OUT_MEM(p, "CivilData", sizeof("CivilData")-1);
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
  ENC_LEN_DEBUG(x, "gl:CivilData", p-enc_base);
  return p;
}

/* FUNC(zx_EASY_ENC_SO_gl_CivilData) */

/* Called by: */
struct zx_str* zx_EASY_ENC_SO_gl_CivilData(struct zx_ctx* c, struct zx_gl_CivilData_s* x )
{
  int len;
  char* buf;
  c->ns_tab = ZX_ALLOC(c, sizeof(zx_ns_tab));
  memcpy(c->ns_tab, zx_ns_tab, sizeof(zx_ns_tab));
  len = zx_LEN_SO_gl_CivilData(c, x );
  buf = ZX_ALLOC(c, len+1);
  return zx_easy_enc_common(c, zx_ENC_SO_gl_CivilData(c, x, buf ), buf, len);
}

/* FUNC(zx_EASY_ENC_WO_gl_CivilData) */

/* Called by: */
struct zx_str* zx_EASY_ENC_WO_gl_CivilData(struct zx_ctx* c, struct zx_gl_CivilData_s* x )
{
  int len;
  char* buf;
  c->ns_tab = ZX_ALLOC(c, sizeof(zx_ns_tab));
  memcpy(c->ns_tab, zx_ns_tab, sizeof(zx_ns_tab));
  len = zx_LEN_WO_gl_CivilData(c, x );
  buf = ZX_ALLOC(c, len+1);
  return zx_easy_enc_common(c, zx_ENC_WO_gl_CivilData(c, x, buf ), buf, len);
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

#define EL_NAME   gl_ComparisonResult
#define EL_STRUCT zx_gl_ComparisonResult_s
#define EL_NS     gl
#define EL_TAG    ComparisonResult

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

/* FUNC(zx_LEN_SO_gl_ComparisonResult) */

/* Compute length of an element (and its subelements). The XML attributes
 * and elements are processed in schema order. */

/* Called by: */
int zx_LEN_SO_gl_ComparisonResult(struct zx_ctx* c, struct zx_gl_ComparisonResult_s* x )
{
  struct zx_ns_s* pop_seen = 0;
  struct zx_elem_s* se MAYBE_UNUSED;
#if 1 /* NORMALMODE */
  /* *** in simple_elem case should output ns prefix from ns node. */
  int len = sizeof("<gl:ComparisonResult")-1 + 1 + sizeof("</gl:ComparisonResult>")-1;
  if (c->inc_ns_len)
    len += zx_len_inc_ns(c, &pop_seen);
  len += zx_len_xmlns_if_not_seen(c, zx_ns_tab+zx_xmlns_ix_gl, &pop_seen);

  len += zx_attr_so_len(x->ItemIDRef, sizeof("ItemIDRef")-1);

#else
  /* root node has no begin tag */
  int len = 0;
#endif
  


  len += zx_len_so_common(c, &x->gg);
  zx_pop_seen(pop_seen);
  ENC_LEN_DEBUG(x, "gl:ComparisonResult", len);
  return len;
}

/* FUNC(zx_LEN_WO_gl_ComparisonResult) */

/* Compute length of an element (and its subelements). The XML attributes
 * and elements are processed in wire order and no assumptions
 * are made about namespace prefixes. */

/* Called by: */
int zx_LEN_WO_gl_ComparisonResult(struct zx_ctx* c, struct zx_gl_ComparisonResult_s* x )
{
  struct zx_ns_s* pop_seen = 0;
  struct zx_elem_s* se MAYBE_UNUSED;
#if 1 /* NORMALMODE */
  int len = 1 + sizeof("ComparisonResult")-1 + 1 + 2 + sizeof("ComparisonResult")-1 + 1;
  
  if (x->gg.g.ns && x->gg.g.ns->prefix_len)
    len += (x->gg.g.ns->prefix_len + 1) * 2;
  if (c->inc_ns_len)
    len += zx_len_inc_ns(c, &pop_seen);
  len += zx_len_xmlns_if_not_seen(c, x->gg.g.ns, &pop_seen);

  len += zx_attr_wo_len(x->ItemIDRef, sizeof("ItemIDRef")-1);

#else
  /* root node has no begin tag */
  int len = 0;
#endif
  


  len += zx_len_wo_common(c, &x->gg); 
  zx_pop_seen(pop_seen);
  ENC_LEN_DEBUG(x, "gl:ComparisonResult", len);
  return len;
}

/* FUNC(zx_ENC_SO_gl_ComparisonResult) */

/* Render element into string. The XML attributes and elements are
 * processed in schema order. This is what you generally want for
 * rendering new data structure to a string. The wo pointers are not used. */

/* Called by: */
char* zx_ENC_SO_gl_ComparisonResult(struct zx_ctx* c, struct zx_gl_ComparisonResult_s* x, char* p )
{
  struct zx_elem_s* se MAYBE_UNUSED;
  struct zx_ns_s* pop_seen = 0;
  ENC_LEN_DEBUG_BASE;
#if 1 /* NORMALMODE */
  /* *** in simple_elem case should output ns prefix from ns node. */
  ZX_OUT_TAG(p, "<gl:ComparisonResult");
  if (c->inc_ns)
    p = zx_enc_inc_ns(c, p, &pop_seen);
  p = zx_enc_xmlns_if_not_seen(c, p, zx_ns_tab+zx_xmlns_ix_gl, &pop_seen);

  p = zx_attr_so_enc(p, x->ItemIDRef, " ItemIDRef=\"", sizeof(" ItemIDRef=\"")-1);

  p = zx_enc_unknown_attrs(p, x->gg.any_attr);
#else
  /* root node has no begin tag */
#endif
  

  p = zx_enc_so_unknown_elems_and_content(c, p, &x->gg);
  
#if 1 /* NORMALMODE */
  ZX_OUT_CLOSE_TAG(p, "</gl:ComparisonResult>");
  zx_pop_seen(pop_seen);
#else
  /* root node has no end tag either */
#endif
  ENC_LEN_DEBUG(x, "gl:ComparisonResult", p-enc_base);
  return p;
}

/* FUNC(zx_ENC_WO_gl_ComparisonResult) */

/* Render element into string. The XML attributes and elements are
 * processed in wire order by chasing wo pointers. This is what you want for
 * validating signatures on other people's XML documents. */

/* Called by: */
char* zx_ENC_WO_gl_ComparisonResult(struct zx_ctx* c, struct zx_gl_ComparisonResult_s* x, char* p )
{
  struct zx_elem_s* kid;
  struct zx_ns_s* pop_seen = 0;
  ENC_LEN_DEBUG_BASE;
#if 1 /* NORMALMODE */
  char* q;
  char* qq;
  ZX_OUT_CH(p, '<');
  q = p;
  if (x->gg.g.ns && x->gg.g.ns->prefix_len) {
    ZX_OUT_MEM(p, x->gg.g.ns->prefix, x->gg.g.ns->prefix_len);
    ZX_OUT_CH(p, ':');
  }
  ZX_OUT_MEM(p, "ComparisonResult", sizeof("ComparisonResult")-1);
  qq = p;

  /* *** sort the namespaces */
  if (c->inc_ns)
    zx_add_inc_ns(c, &pop_seen);
  zx_add_xmlns_if_not_seen(c, x->gg.g.ns, &pop_seen);

  p = zx_enc_seen(p, pop_seen); 
  p = zx_attr_wo_enc(p, x->ItemIDRef, "ItemIDRef=\"", sizeof("ItemIDRef=\"")-1);

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
  ENC_LEN_DEBUG(x, "gl:ComparisonResult", p-enc_base);
  return p;
}

/* FUNC(zx_EASY_ENC_SO_gl_ComparisonResult) */

/* Called by: */
struct zx_str* zx_EASY_ENC_SO_gl_ComparisonResult(struct zx_ctx* c, struct zx_gl_ComparisonResult_s* x )
{
  int len;
  char* buf;
  c->ns_tab = ZX_ALLOC(c, sizeof(zx_ns_tab));
  memcpy(c->ns_tab, zx_ns_tab, sizeof(zx_ns_tab));
  len = zx_LEN_SO_gl_ComparisonResult(c, x );
  buf = ZX_ALLOC(c, len+1);
  return zx_easy_enc_common(c, zx_ENC_SO_gl_ComparisonResult(c, x, buf ), buf, len);
}

/* FUNC(zx_EASY_ENC_WO_gl_ComparisonResult) */

/* Called by: */
struct zx_str* zx_EASY_ENC_WO_gl_ComparisonResult(struct zx_ctx* c, struct zx_gl_ComparisonResult_s* x )
{
  int len;
  char* buf;
  c->ns_tab = ZX_ALLOC(c, sizeof(zx_ns_tab));
  memcpy(c->ns_tab, zx_ns_tab, sizeof(zx_ns_tab));
  len = zx_LEN_WO_gl_ComparisonResult(c, x );
  buf = ZX_ALLOC(c, len+1);
  return zx_easy_enc_common(c, zx_ENC_WO_gl_ComparisonResult(c, x, buf ), buf, len);
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

#define EL_NAME   gl_CoordinateReferenceSystem
#define EL_STRUCT zx_gl_CoordinateReferenceSystem_s
#define EL_NS     gl
#define EL_TAG    CoordinateReferenceSystem

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

/* FUNC(zx_LEN_SO_gl_CoordinateReferenceSystem) */

/* Compute length of an element (and its subelements). The XML attributes
 * and elements are processed in schema order. */

/* Called by: */
int zx_LEN_SO_gl_CoordinateReferenceSystem(struct zx_ctx* c, struct zx_gl_CoordinateReferenceSystem_s* x )
{
  struct zx_ns_s* pop_seen = 0;
  struct zx_elem_s* se MAYBE_UNUSED;
#if 1 /* NORMALMODE */
  /* *** in simple_elem case should output ns prefix from ns node. */
  int len = sizeof("<gl:CoordinateReferenceSystem")-1 + 1 + sizeof("</gl:CoordinateReferenceSystem>")-1;
  if (c->inc_ns_len)
    len += zx_len_inc_ns(c, &pop_seen);
  len += zx_len_xmlns_if_not_seen(c, zx_ns_tab+zx_xmlns_ix_gl, &pop_seen);


#else
  /* root node has no begin tag */
  int len = 0;
#endif
  
  {
      struct zx_gl_Identifier_s* e;
      for (e = x->Identifier; e; e = (struct zx_gl_Identifier_s*)e->gg.g.n)
	  len += zx_LEN_SO_gl_Identifier(c, e);
  }


  len += zx_len_so_common(c, &x->gg);
  zx_pop_seen(pop_seen);
  ENC_LEN_DEBUG(x, "gl:CoordinateReferenceSystem", len);
  return len;
}

/* FUNC(zx_LEN_WO_gl_CoordinateReferenceSystem) */

/* Compute length of an element (and its subelements). The XML attributes
 * and elements are processed in wire order and no assumptions
 * are made about namespace prefixes. */

/* Called by: */
int zx_LEN_WO_gl_CoordinateReferenceSystem(struct zx_ctx* c, struct zx_gl_CoordinateReferenceSystem_s* x )
{
  struct zx_ns_s* pop_seen = 0;
  struct zx_elem_s* se MAYBE_UNUSED;
#if 1 /* NORMALMODE */
  int len = 1 + sizeof("CoordinateReferenceSystem")-1 + 1 + 2 + sizeof("CoordinateReferenceSystem")-1 + 1;
  
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
      struct zx_gl_Identifier_s* e;
      for (e = x->Identifier; e; e = (struct zx_gl_Identifier_s*)e->gg.g.n)
	  len += zx_LEN_WO_gl_Identifier(c, e);
  }


  len += zx_len_wo_common(c, &x->gg); 
  zx_pop_seen(pop_seen);
  ENC_LEN_DEBUG(x, "gl:CoordinateReferenceSystem", len);
  return len;
}

/* FUNC(zx_ENC_SO_gl_CoordinateReferenceSystem) */

/* Render element into string. The XML attributes and elements are
 * processed in schema order. This is what you generally want for
 * rendering new data structure to a string. The wo pointers are not used. */

/* Called by: */
char* zx_ENC_SO_gl_CoordinateReferenceSystem(struct zx_ctx* c, struct zx_gl_CoordinateReferenceSystem_s* x, char* p )
{
  struct zx_elem_s* se MAYBE_UNUSED;
  struct zx_ns_s* pop_seen = 0;
  ENC_LEN_DEBUG_BASE;
#if 1 /* NORMALMODE */
  /* *** in simple_elem case should output ns prefix from ns node. */
  ZX_OUT_TAG(p, "<gl:CoordinateReferenceSystem");
  if (c->inc_ns)
    p = zx_enc_inc_ns(c, p, &pop_seen);
  p = zx_enc_xmlns_if_not_seen(c, p, zx_ns_tab+zx_xmlns_ix_gl, &pop_seen);


  p = zx_enc_unknown_attrs(p, x->gg.any_attr);
#else
  /* root node has no begin tag */
#endif
  
  {
      struct zx_gl_Identifier_s* e;
      for (e = x->Identifier; e; e = (struct zx_gl_Identifier_s*)e->gg.g.n)
	  p = zx_ENC_SO_gl_Identifier(c, e, p);
  }

  p = zx_enc_so_unknown_elems_and_content(c, p, &x->gg);
  
#if 1 /* NORMALMODE */
  ZX_OUT_CLOSE_TAG(p, "</gl:CoordinateReferenceSystem>");
  zx_pop_seen(pop_seen);
#else
  /* root node has no end tag either */
#endif
  ENC_LEN_DEBUG(x, "gl:CoordinateReferenceSystem", p-enc_base);
  return p;
}

/* FUNC(zx_ENC_WO_gl_CoordinateReferenceSystem) */

/* Render element into string. The XML attributes and elements are
 * processed in wire order by chasing wo pointers. This is what you want for
 * validating signatures on other people's XML documents. */

/* Called by: */
char* zx_ENC_WO_gl_CoordinateReferenceSystem(struct zx_ctx* c, struct zx_gl_CoordinateReferenceSystem_s* x, char* p )
{
  struct zx_elem_s* kid;
  struct zx_ns_s* pop_seen = 0;
  ENC_LEN_DEBUG_BASE;
#if 1 /* NORMALMODE */
  char* q;
  char* qq;
  ZX_OUT_CH(p, '<');
  q = p;
  if (x->gg.g.ns && x->gg.g.ns->prefix_len) {
    ZX_OUT_MEM(p, x->gg.g.ns->prefix, x->gg.g.ns->prefix_len);
    ZX_OUT_CH(p, ':');
  }
  ZX_OUT_MEM(p, "CoordinateReferenceSystem", sizeof("CoordinateReferenceSystem")-1);
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
  ENC_LEN_DEBUG(x, "gl:CoordinateReferenceSystem", p-enc_base);
  return p;
}

/* FUNC(zx_EASY_ENC_SO_gl_CoordinateReferenceSystem) */

/* Called by: */
struct zx_str* zx_EASY_ENC_SO_gl_CoordinateReferenceSystem(struct zx_ctx* c, struct zx_gl_CoordinateReferenceSystem_s* x )
{
  int len;
  char* buf;
  c->ns_tab = ZX_ALLOC(c, sizeof(zx_ns_tab));
  memcpy(c->ns_tab, zx_ns_tab, sizeof(zx_ns_tab));
  len = zx_LEN_SO_gl_CoordinateReferenceSystem(c, x );
  buf = ZX_ALLOC(c, len+1);
  return zx_easy_enc_common(c, zx_ENC_SO_gl_CoordinateReferenceSystem(c, x, buf ), buf, len);
}

/* FUNC(zx_EASY_ENC_WO_gl_CoordinateReferenceSystem) */

/* Called by: */
struct zx_str* zx_EASY_ENC_WO_gl_CoordinateReferenceSystem(struct zx_ctx* c, struct zx_gl_CoordinateReferenceSystem_s* x )
{
  int len;
  char* buf;
  c->ns_tab = ZX_ALLOC(c, sizeof(zx_ns_tab));
  memcpy(c->ns_tab, zx_ns_tab, sizeof(zx_ns_tab));
  len = zx_LEN_WO_gl_CoordinateReferenceSystem(c, x );
  buf = ZX_ALLOC(c, len+1);
  return zx_easy_enc_common(c, zx_ENC_WO_gl_CoordinateReferenceSystem(c, x, buf ), buf, len);
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

#define EL_NAME   gl_Create
#define EL_STRUCT zx_gl_Create_s
#define EL_NS     gl
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

/* FUNC(zx_LEN_SO_gl_Create) */

/* Compute length of an element (and its subelements). The XML attributes
 * and elements are processed in schema order. */

/* Called by: */
int zx_LEN_SO_gl_Create(struct zx_ctx* c, struct zx_gl_Create_s* x )
{
  struct zx_ns_s* pop_seen = 0;
  struct zx_elem_s* se MAYBE_UNUSED;
#if 1 /* NORMALMODE */
  /* *** in simple_elem case should output ns prefix from ns node. */
  int len = sizeof("<gl:Create")-1 + 1 + sizeof("</gl:Create>")-1;
  if (c->inc_ns_len)
    len += zx_len_inc_ns(c, &pop_seen);
  len += zx_len_xmlns_if_not_seen(c, zx_ns_tab+zx_xmlns_ix_gl, &pop_seen);

  len += zx_attr_so_len(x->id, sizeof("id")-1);

#else
  /* root node has no begin tag */
  int len = 0;
#endif
  
  {
      struct zx_gl_ResourceID_s* e;
      for (e = x->ResourceID; e; e = (struct zx_gl_ResourceID_s*)e->gg.g.n)
	  len += zx_LEN_SO_gl_ResourceID(c, e);
  }
  {
      struct zx_gl_EncryptedResourceID_s* e;
      for (e = x->EncryptedResourceID; e; e = (struct zx_gl_EncryptedResourceID_s*)e->gg.g.n)
	  len += zx_LEN_SO_gl_EncryptedResourceID(c, e);
  }
  {
      struct zx_gl_Subscription_s* e;
      for (e = x->Subscription; e; e = (struct zx_gl_Subscription_s*)e->gg.g.n)
	  len += zx_LEN_SO_gl_Subscription(c, e);
  }
  {
      struct zx_gl_CreateItem_s* e;
      for (e = x->CreateItem; e; e = (struct zx_gl_CreateItem_s*)e->gg.g.n)
	  len += zx_LEN_SO_gl_CreateItem(c, e);
  }
  {
      struct zx_gl_ItemSelection_s* e;
      for (e = x->ItemSelection; e; e = (struct zx_gl_ItemSelection_s*)e->gg.g.n)
	  len += zx_LEN_SO_gl_ItemSelection(c, e);
  }
  {
      struct zx_gl_Extension_s* e;
      for (e = x->Extension; e; e = (struct zx_gl_Extension_s*)e->gg.g.n)
	  len += zx_LEN_SO_gl_Extension(c, e);
  }


  len += zx_len_so_common(c, &x->gg);
  zx_pop_seen(pop_seen);
  ENC_LEN_DEBUG(x, "gl:Create", len);
  return len;
}

/* FUNC(zx_LEN_WO_gl_Create) */

/* Compute length of an element (and its subelements). The XML attributes
 * and elements are processed in wire order and no assumptions
 * are made about namespace prefixes. */

/* Called by: */
int zx_LEN_WO_gl_Create(struct zx_ctx* c, struct zx_gl_Create_s* x )
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

  len += zx_attr_wo_len(x->id, sizeof("id")-1);

#else
  /* root node has no begin tag */
  int len = 0;
#endif
  
  {
      struct zx_gl_ResourceID_s* e;
      for (e = x->ResourceID; e; e = (struct zx_gl_ResourceID_s*)e->gg.g.n)
	  len += zx_LEN_WO_gl_ResourceID(c, e);
  }
  {
      struct zx_gl_EncryptedResourceID_s* e;
      for (e = x->EncryptedResourceID; e; e = (struct zx_gl_EncryptedResourceID_s*)e->gg.g.n)
	  len += zx_LEN_WO_gl_EncryptedResourceID(c, e);
  }
  {
      struct zx_gl_Subscription_s* e;
      for (e = x->Subscription; e; e = (struct zx_gl_Subscription_s*)e->gg.g.n)
	  len += zx_LEN_WO_gl_Subscription(c, e);
  }
  {
      struct zx_gl_CreateItem_s* e;
      for (e = x->CreateItem; e; e = (struct zx_gl_CreateItem_s*)e->gg.g.n)
	  len += zx_LEN_WO_gl_CreateItem(c, e);
  }
  {
      struct zx_gl_ItemSelection_s* e;
      for (e = x->ItemSelection; e; e = (struct zx_gl_ItemSelection_s*)e->gg.g.n)
	  len += zx_LEN_WO_gl_ItemSelection(c, e);
  }
  {
      struct zx_gl_Extension_s* e;
      for (e = x->Extension; e; e = (struct zx_gl_Extension_s*)e->gg.g.n)
	  len += zx_LEN_WO_gl_Extension(c, e);
  }


  len += zx_len_wo_common(c, &x->gg); 
  zx_pop_seen(pop_seen);
  ENC_LEN_DEBUG(x, "gl:Create", len);
  return len;
}

/* FUNC(zx_ENC_SO_gl_Create) */

/* Render element into string. The XML attributes and elements are
 * processed in schema order. This is what you generally want for
 * rendering new data structure to a string. The wo pointers are not used. */

/* Called by: */
char* zx_ENC_SO_gl_Create(struct zx_ctx* c, struct zx_gl_Create_s* x, char* p )
{
  struct zx_elem_s* se MAYBE_UNUSED;
  struct zx_ns_s* pop_seen = 0;
  ENC_LEN_DEBUG_BASE;
#if 1 /* NORMALMODE */
  /* *** in simple_elem case should output ns prefix from ns node. */
  ZX_OUT_TAG(p, "<gl:Create");
  if (c->inc_ns)
    p = zx_enc_inc_ns(c, p, &pop_seen);
  p = zx_enc_xmlns_if_not_seen(c, p, zx_ns_tab+zx_xmlns_ix_gl, &pop_seen);

  p = zx_attr_so_enc(p, x->id, " id=\"", sizeof(" id=\"")-1);

  p = zx_enc_unknown_attrs(p, x->gg.any_attr);
#else
  /* root node has no begin tag */
#endif
  
  {
      struct zx_gl_ResourceID_s* e;
      for (e = x->ResourceID; e; e = (struct zx_gl_ResourceID_s*)e->gg.g.n)
	  p = zx_ENC_SO_gl_ResourceID(c, e, p);
  }
  {
      struct zx_gl_EncryptedResourceID_s* e;
      for (e = x->EncryptedResourceID; e; e = (struct zx_gl_EncryptedResourceID_s*)e->gg.g.n)
	  p = zx_ENC_SO_gl_EncryptedResourceID(c, e, p);
  }
  {
      struct zx_gl_Subscription_s* e;
      for (e = x->Subscription; e; e = (struct zx_gl_Subscription_s*)e->gg.g.n)
	  p = zx_ENC_SO_gl_Subscription(c, e, p);
  }
  {
      struct zx_gl_CreateItem_s* e;
      for (e = x->CreateItem; e; e = (struct zx_gl_CreateItem_s*)e->gg.g.n)
	  p = zx_ENC_SO_gl_CreateItem(c, e, p);
  }
  {
      struct zx_gl_ItemSelection_s* e;
      for (e = x->ItemSelection; e; e = (struct zx_gl_ItemSelection_s*)e->gg.g.n)
	  p = zx_ENC_SO_gl_ItemSelection(c, e, p);
  }
  {
      struct zx_gl_Extension_s* e;
      for (e = x->Extension; e; e = (struct zx_gl_Extension_s*)e->gg.g.n)
	  p = zx_ENC_SO_gl_Extension(c, e, p);
  }

  p = zx_enc_so_unknown_elems_and_content(c, p, &x->gg);
  
#if 1 /* NORMALMODE */
  ZX_OUT_CLOSE_TAG(p, "</gl:Create>");
  zx_pop_seen(pop_seen);
#else
  /* root node has no end tag either */
#endif
  ENC_LEN_DEBUG(x, "gl:Create", p-enc_base);
  return p;
}

/* FUNC(zx_ENC_WO_gl_Create) */

/* Render element into string. The XML attributes and elements are
 * processed in wire order by chasing wo pointers. This is what you want for
 * validating signatures on other people's XML documents. */

/* Called by: */
char* zx_ENC_WO_gl_Create(struct zx_ctx* c, struct zx_gl_Create_s* x, char* p )
{
  struct zx_elem_s* kid;
  struct zx_ns_s* pop_seen = 0;
  ENC_LEN_DEBUG_BASE;
#if 1 /* NORMALMODE */
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
  ENC_LEN_DEBUG(x, "gl:Create", p-enc_base);
  return p;
}

/* FUNC(zx_EASY_ENC_SO_gl_Create) */

/* Called by: */
struct zx_str* zx_EASY_ENC_SO_gl_Create(struct zx_ctx* c, struct zx_gl_Create_s* x )
{
  int len;
  char* buf;
  c->ns_tab = ZX_ALLOC(c, sizeof(zx_ns_tab));
  memcpy(c->ns_tab, zx_ns_tab, sizeof(zx_ns_tab));
  len = zx_LEN_SO_gl_Create(c, x );
  buf = ZX_ALLOC(c, len+1);
  return zx_easy_enc_common(c, zx_ENC_SO_gl_Create(c, x, buf ), buf, len);
}

/* FUNC(zx_EASY_ENC_WO_gl_Create) */

/* Called by: */
struct zx_str* zx_EASY_ENC_WO_gl_Create(struct zx_ctx* c, struct zx_gl_Create_s* x )
{
  int len;
  char* buf;
  c->ns_tab = ZX_ALLOC(c, sizeof(zx_ns_tab));
  memcpy(c->ns_tab, zx_ns_tab, sizeof(zx_ns_tab));
  len = zx_LEN_WO_gl_Create(c, x );
  buf = ZX_ALLOC(c, len+1);
  return zx_easy_enc_common(c, zx_ENC_WO_gl_Create(c, x, buf ), buf, len);
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

#define EL_NAME   gl_CreateItem
#define EL_STRUCT zx_gl_CreateItem_s
#define EL_NS     gl
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

/* FUNC(zx_LEN_SO_gl_CreateItem) */

/* Compute length of an element (and its subelements). The XML attributes
 * and elements are processed in schema order. */

/* Called by: */
int zx_LEN_SO_gl_CreateItem(struct zx_ctx* c, struct zx_gl_CreateItem_s* x )
{
  struct zx_ns_s* pop_seen = 0;
  struct zx_elem_s* se MAYBE_UNUSED;
#if 1 /* NORMALMODE */
  /* *** in simple_elem case should output ns prefix from ns node. */
  int len = sizeof("<gl:CreateItem")-1 + 1 + sizeof("</gl:CreateItem>")-1;
  if (c->inc_ns_len)
    len += zx_len_inc_ns(c, &pop_seen);
  len += zx_len_xmlns_if_not_seen(c, zx_ns_tab+zx_xmlns_ix_gl, &pop_seen);

  len += zx_attr_so_len(x->id, sizeof("id")-1);
  len += zx_attr_so_len(x->itemID, sizeof("itemID")-1);
  len += zx_attr_so_len(x->objectType, sizeof("objectType")-1);

#else
  /* root node has no begin tag */
  int len = 0;
#endif
  
  {
      struct zx_gl_NewData_s* e;
      for (e = x->NewData; e; e = (struct zx_gl_NewData_s*)e->gg.g.n)
	  len += zx_LEN_SO_gl_NewData(c, e);
  }


  len += zx_len_so_common(c, &x->gg);
  zx_pop_seen(pop_seen);
  ENC_LEN_DEBUG(x, "gl:CreateItem", len);
  return len;
}

/* FUNC(zx_LEN_WO_gl_CreateItem) */

/* Compute length of an element (and its subelements). The XML attributes
 * and elements are processed in wire order and no assumptions
 * are made about namespace prefixes. */

/* Called by: */
int zx_LEN_WO_gl_CreateItem(struct zx_ctx* c, struct zx_gl_CreateItem_s* x )
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

  len += zx_attr_wo_len(x->id, sizeof("id")-1);
  len += zx_attr_wo_len(x->itemID, sizeof("itemID")-1);
  len += zx_attr_wo_len(x->objectType, sizeof("objectType")-1);

#else
  /* root node has no begin tag */
  int len = 0;
#endif
  
  {
      struct zx_gl_NewData_s* e;
      for (e = x->NewData; e; e = (struct zx_gl_NewData_s*)e->gg.g.n)
	  len += zx_LEN_WO_gl_NewData(c, e);
  }


  len += zx_len_wo_common(c, &x->gg); 
  zx_pop_seen(pop_seen);
  ENC_LEN_DEBUG(x, "gl:CreateItem", len);
  return len;
}

/* FUNC(zx_ENC_SO_gl_CreateItem) */

/* Render element into string. The XML attributes and elements are
 * processed in schema order. This is what you generally want for
 * rendering new data structure to a string. The wo pointers are not used. */

/* Called by: */
char* zx_ENC_SO_gl_CreateItem(struct zx_ctx* c, struct zx_gl_CreateItem_s* x, char* p )
{
  struct zx_elem_s* se MAYBE_UNUSED;
  struct zx_ns_s* pop_seen = 0;
  ENC_LEN_DEBUG_BASE;
#if 1 /* NORMALMODE */
  /* *** in simple_elem case should output ns prefix from ns node. */
  ZX_OUT_TAG(p, "<gl:CreateItem");
  if (c->inc_ns)
    p = zx_enc_inc_ns(c, p, &pop_seen);
  p = zx_enc_xmlns_if_not_seen(c, p, zx_ns_tab+zx_xmlns_ix_gl, &pop_seen);

  p = zx_attr_so_enc(p, x->id, " id=\"", sizeof(" id=\"")-1);
  p = zx_attr_so_enc(p, x->itemID, " itemID=\"", sizeof(" itemID=\"")-1);
  p = zx_attr_so_enc(p, x->objectType, " objectType=\"", sizeof(" objectType=\"")-1);

  p = zx_enc_unknown_attrs(p, x->gg.any_attr);
#else
  /* root node has no begin tag */
#endif
  
  {
      struct zx_gl_NewData_s* e;
      for (e = x->NewData; e; e = (struct zx_gl_NewData_s*)e->gg.g.n)
	  p = zx_ENC_SO_gl_NewData(c, e, p);
  }

  p = zx_enc_so_unknown_elems_and_content(c, p, &x->gg);
  
#if 1 /* NORMALMODE */
  ZX_OUT_CLOSE_TAG(p, "</gl:CreateItem>");
  zx_pop_seen(pop_seen);
#else
  /* root node has no end tag either */
#endif
  ENC_LEN_DEBUG(x, "gl:CreateItem", p-enc_base);
  return p;
}

/* FUNC(zx_ENC_WO_gl_CreateItem) */

/* Render element into string. The XML attributes and elements are
 * processed in wire order by chasing wo pointers. This is what you want for
 * validating signatures on other people's XML documents. */

/* Called by: */
char* zx_ENC_WO_gl_CreateItem(struct zx_ctx* c, struct zx_gl_CreateItem_s* x, char* p )
{
  struct zx_elem_s* kid;
  struct zx_ns_s* pop_seen = 0;
  ENC_LEN_DEBUG_BASE;
#if 1 /* NORMALMODE */
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
  ENC_LEN_DEBUG(x, "gl:CreateItem", p-enc_base);
  return p;
}

/* FUNC(zx_EASY_ENC_SO_gl_CreateItem) */

/* Called by: */
struct zx_str* zx_EASY_ENC_SO_gl_CreateItem(struct zx_ctx* c, struct zx_gl_CreateItem_s* x )
{
  int len;
  char* buf;
  c->ns_tab = ZX_ALLOC(c, sizeof(zx_ns_tab));
  memcpy(c->ns_tab, zx_ns_tab, sizeof(zx_ns_tab));
  len = zx_LEN_SO_gl_CreateItem(c, x );
  buf = ZX_ALLOC(c, len+1);
  return zx_easy_enc_common(c, zx_ENC_SO_gl_CreateItem(c, x, buf ), buf, len);
}

/* FUNC(zx_EASY_ENC_WO_gl_CreateItem) */

/* Called by: */
struct zx_str* zx_EASY_ENC_WO_gl_CreateItem(struct zx_ctx* c, struct zx_gl_CreateItem_s* x )
{
  int len;
  char* buf;
  c->ns_tab = ZX_ALLOC(c, sizeof(zx_ns_tab));
  memcpy(c->ns_tab, zx_ns_tab, sizeof(zx_ns_tab));
  len = zx_LEN_WO_gl_CreateItem(c, x );
  buf = ZX_ALLOC(c, len+1);
  return zx_easy_enc_common(c, zx_ENC_WO_gl_CreateItem(c, x, buf ), buf, len);
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

#define EL_NAME   gl_CreateResponse
#define EL_STRUCT zx_gl_CreateResponse_s
#define EL_NS     gl
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

/* FUNC(zx_LEN_SO_gl_CreateResponse) */

/* Compute length of an element (and its subelements). The XML attributes
 * and elements are processed in schema order. */

/* Called by: */
int zx_LEN_SO_gl_CreateResponse(struct zx_ctx* c, struct zx_gl_CreateResponse_s* x )
{
  struct zx_ns_s* pop_seen = 0;
  struct zx_elem_s* se MAYBE_UNUSED;
#if 1 /* NORMALMODE */
  /* *** in simple_elem case should output ns prefix from ns node. */
  int len = sizeof("<gl:CreateResponse")-1 + 1 + sizeof("</gl:CreateResponse>")-1;
  if (c->inc_ns_len)
    len += zx_len_inc_ns(c, &pop_seen);
  len += zx_len_xmlns_if_not_seen(c, zx_ns_tab+zx_xmlns_ix_gl, &pop_seen);

  len += zx_attr_so_len(x->id, sizeof("id")-1);
  len += zx_attr_so_len(x->timeStamp, sizeof("timeStamp")-1);

#else
  /* root node has no begin tag */
  int len = 0;
#endif
  
  {
      struct zx_gl_Status_s* e;
      for (e = x->Status; e; e = (struct zx_gl_Status_s*)e->gg.g.n)
	  len += zx_LEN_SO_gl_Status(c, e);
  }
  {
      struct zx_gl_ItemData_s* e;
      for (e = x->ItemData; e; e = (struct zx_gl_ItemData_s*)e->gg.g.n)
	  len += zx_LEN_SO_gl_ItemData(c, e);
  }
  {
      struct zx_gl_Extension_s* e;
      for (e = x->Extension; e; e = (struct zx_gl_Extension_s*)e->gg.g.n)
	  len += zx_LEN_SO_gl_Extension(c, e);
  }


  len += zx_len_so_common(c, &x->gg);
  zx_pop_seen(pop_seen);
  ENC_LEN_DEBUG(x, "gl:CreateResponse", len);
  return len;
}

/* FUNC(zx_LEN_WO_gl_CreateResponse) */

/* Compute length of an element (and its subelements). The XML attributes
 * and elements are processed in wire order and no assumptions
 * are made about namespace prefixes. */

/* Called by: */
int zx_LEN_WO_gl_CreateResponse(struct zx_ctx* c, struct zx_gl_CreateResponse_s* x )
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

  len += zx_attr_wo_len(x->id, sizeof("id")-1);
  len += zx_attr_wo_len(x->timeStamp, sizeof("timeStamp")-1);

#else
  /* root node has no begin tag */
  int len = 0;
#endif
  
  {
      struct zx_gl_Status_s* e;
      for (e = x->Status; e; e = (struct zx_gl_Status_s*)e->gg.g.n)
	  len += zx_LEN_WO_gl_Status(c, e);
  }
  {
      struct zx_gl_ItemData_s* e;
      for (e = x->ItemData; e; e = (struct zx_gl_ItemData_s*)e->gg.g.n)
	  len += zx_LEN_WO_gl_ItemData(c, e);
  }
  {
      struct zx_gl_Extension_s* e;
      for (e = x->Extension; e; e = (struct zx_gl_Extension_s*)e->gg.g.n)
	  len += zx_LEN_WO_gl_Extension(c, e);
  }


  len += zx_len_wo_common(c, &x->gg); 
  zx_pop_seen(pop_seen);
  ENC_LEN_DEBUG(x, "gl:CreateResponse", len);
  return len;
}

/* FUNC(zx_ENC_SO_gl_CreateResponse) */

/* Render element into string. The XML attributes and elements are
 * processed in schema order. This is what you generally want for
 * rendering new data structure to a string. The wo pointers are not used. */

/* Called by: */
char* zx_ENC_SO_gl_CreateResponse(struct zx_ctx* c, struct zx_gl_CreateResponse_s* x, char* p )
{
  struct zx_elem_s* se MAYBE_UNUSED;
  struct zx_ns_s* pop_seen = 0;
  ENC_LEN_DEBUG_BASE;
#if 1 /* NORMALMODE */
  /* *** in simple_elem case should output ns prefix from ns node. */
  ZX_OUT_TAG(p, "<gl:CreateResponse");
  if (c->inc_ns)
    p = zx_enc_inc_ns(c, p, &pop_seen);
  p = zx_enc_xmlns_if_not_seen(c, p, zx_ns_tab+zx_xmlns_ix_gl, &pop_seen);

  p = zx_attr_so_enc(p, x->id, " id=\"", sizeof(" id=\"")-1);
  p = zx_attr_so_enc(p, x->timeStamp, " timeStamp=\"", sizeof(" timeStamp=\"")-1);

  p = zx_enc_unknown_attrs(p, x->gg.any_attr);
#else
  /* root node has no begin tag */
#endif
  
  {
      struct zx_gl_Status_s* e;
      for (e = x->Status; e; e = (struct zx_gl_Status_s*)e->gg.g.n)
	  p = zx_ENC_SO_gl_Status(c, e, p);
  }
  {
      struct zx_gl_ItemData_s* e;
      for (e = x->ItemData; e; e = (struct zx_gl_ItemData_s*)e->gg.g.n)
	  p = zx_ENC_SO_gl_ItemData(c, e, p);
  }
  {
      struct zx_gl_Extension_s* e;
      for (e = x->Extension; e; e = (struct zx_gl_Extension_s*)e->gg.g.n)
	  p = zx_ENC_SO_gl_Extension(c, e, p);
  }

  p = zx_enc_so_unknown_elems_and_content(c, p, &x->gg);
  
#if 1 /* NORMALMODE */
  ZX_OUT_CLOSE_TAG(p, "</gl:CreateResponse>");
  zx_pop_seen(pop_seen);
#else
  /* root node has no end tag either */
#endif
  ENC_LEN_DEBUG(x, "gl:CreateResponse", p-enc_base);
  return p;
}

/* FUNC(zx_ENC_WO_gl_CreateResponse) */

/* Render element into string. The XML attributes and elements are
 * processed in wire order by chasing wo pointers. This is what you want for
 * validating signatures on other people's XML documents. */

/* Called by: */
char* zx_ENC_WO_gl_CreateResponse(struct zx_ctx* c, struct zx_gl_CreateResponse_s* x, char* p )
{
  struct zx_elem_s* kid;
  struct zx_ns_s* pop_seen = 0;
  ENC_LEN_DEBUG_BASE;
#if 1 /* NORMALMODE */
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

  p = zx_enc_seen(p, pop_seen); 
  p = zx_attr_wo_enc(p, x->id, "id=\"", sizeof("id=\"")-1);
  p = zx_attr_wo_enc(p, x->timeStamp, "timeStamp=\"", sizeof("timeStamp=\"")-1);

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
  ENC_LEN_DEBUG(x, "gl:CreateResponse", p-enc_base);
  return p;
}

/* FUNC(zx_EASY_ENC_SO_gl_CreateResponse) */

/* Called by: */
struct zx_str* zx_EASY_ENC_SO_gl_CreateResponse(struct zx_ctx* c, struct zx_gl_CreateResponse_s* x )
{
  int len;
  char* buf;
  c->ns_tab = ZX_ALLOC(c, sizeof(zx_ns_tab));
  memcpy(c->ns_tab, zx_ns_tab, sizeof(zx_ns_tab));
  len = zx_LEN_SO_gl_CreateResponse(c, x );
  buf = ZX_ALLOC(c, len+1);
  return zx_easy_enc_common(c, zx_ENC_SO_gl_CreateResponse(c, x, buf ), buf, len);
}

/* FUNC(zx_EASY_ENC_WO_gl_CreateResponse) */

/* Called by: */
struct zx_str* zx_EASY_ENC_WO_gl_CreateResponse(struct zx_ctx* c, struct zx_gl_CreateResponse_s* x )
{
  int len;
  char* buf;
  c->ns_tab = ZX_ALLOC(c, sizeof(zx_ns_tab));
  memcpy(c->ns_tab, zx_ns_tab, sizeof(zx_ns_tab));
  len = zx_LEN_WO_gl_CreateResponse(c, x );
  buf = ZX_ALLOC(c, len+1);
  return zx_easy_enc_common(c, zx_ENC_WO_gl_CreateResponse(c, x, buf ), buf, len);
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

#define EL_NAME   gl_Credential
#define EL_STRUCT zx_gl_Credential_s
#define EL_NS     gl
#define EL_TAG    Credential

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

/* FUNC(zx_LEN_SO_gl_Credential) */

/* Compute length of an element (and its subelements). The XML attributes
 * and elements are processed in schema order. */

/* Called by: */
int zx_LEN_SO_gl_Credential(struct zx_ctx* c, struct zx_gl_Credential_s* x )
{
  struct zx_ns_s* pop_seen = 0;
  struct zx_elem_s* se MAYBE_UNUSED;
#if 1 /* NORMALMODE */
  /* *** in simple_elem case should output ns prefix from ns node. */
  int len = sizeof("<gl:Credential")-1 + 1 + sizeof("</gl:Credential>")-1;
  if (c->inc_ns_len)
    len += zx_len_inc_ns(c, &pop_seen);
  len += zx_len_xmlns_if_not_seen(c, zx_ns_tab+zx_xmlns_ix_gl, &pop_seen);

  len += zx_attr_so_len(x->notOnOrAfter, sizeof("notOnOrAfter")-1);

#else
  /* root node has no begin tag */
  int len = 0;
#endif
  
  {
      struct zx_sa_Assertion_s* e;
      for (e = x->Assertion; e; e = (struct zx_sa_Assertion_s*)e->gg.g.n)
	  len += zx_LEN_SO_sa_Assertion(c, e);
  }


  len += zx_len_so_common(c, &x->gg);
  zx_pop_seen(pop_seen);
  ENC_LEN_DEBUG(x, "gl:Credential", len);
  return len;
}

/* FUNC(zx_LEN_WO_gl_Credential) */

/* Compute length of an element (and its subelements). The XML attributes
 * and elements are processed in wire order and no assumptions
 * are made about namespace prefixes. */

/* Called by: */
int zx_LEN_WO_gl_Credential(struct zx_ctx* c, struct zx_gl_Credential_s* x )
{
  struct zx_ns_s* pop_seen = 0;
  struct zx_elem_s* se MAYBE_UNUSED;
#if 1 /* NORMALMODE */
  int len = 1 + sizeof("Credential")-1 + 1 + 2 + sizeof("Credential")-1 + 1;
  
  if (x->gg.g.ns && x->gg.g.ns->prefix_len)
    len += (x->gg.g.ns->prefix_len + 1) * 2;
  if (c->inc_ns_len)
    len += zx_len_inc_ns(c, &pop_seen);
  len += zx_len_xmlns_if_not_seen(c, x->gg.g.ns, &pop_seen);

  len += zx_attr_wo_len(x->notOnOrAfter, sizeof("notOnOrAfter")-1);

#else
  /* root node has no begin tag */
  int len = 0;
#endif
  
  {
      struct zx_sa_Assertion_s* e;
      for (e = x->Assertion; e; e = (struct zx_sa_Assertion_s*)e->gg.g.n)
	  len += zx_LEN_WO_sa_Assertion(c, e);
  }


  len += zx_len_wo_common(c, &x->gg); 
  zx_pop_seen(pop_seen);
  ENC_LEN_DEBUG(x, "gl:Credential", len);
  return len;
}

/* FUNC(zx_ENC_SO_gl_Credential) */

/* Render element into string. The XML attributes and elements are
 * processed in schema order. This is what you generally want for
 * rendering new data structure to a string. The wo pointers are not used. */

/* Called by: */
char* zx_ENC_SO_gl_Credential(struct zx_ctx* c, struct zx_gl_Credential_s* x, char* p )
{
  struct zx_elem_s* se MAYBE_UNUSED;
  struct zx_ns_s* pop_seen = 0;
  ENC_LEN_DEBUG_BASE;
#if 1 /* NORMALMODE */
  /* *** in simple_elem case should output ns prefix from ns node. */
  ZX_OUT_TAG(p, "<gl:Credential");
  if (c->inc_ns)
    p = zx_enc_inc_ns(c, p, &pop_seen);
  p = zx_enc_xmlns_if_not_seen(c, p, zx_ns_tab+zx_xmlns_ix_gl, &pop_seen);

  p = zx_attr_so_enc(p, x->notOnOrAfter, " notOnOrAfter=\"", sizeof(" notOnOrAfter=\"")-1);

  p = zx_enc_unknown_attrs(p, x->gg.any_attr);
#else
  /* root node has no begin tag */
#endif
  
  {
      struct zx_sa_Assertion_s* e;
      for (e = x->Assertion; e; e = (struct zx_sa_Assertion_s*)e->gg.g.n)
	  p = zx_ENC_SO_sa_Assertion(c, e, p);
  }

  p = zx_enc_so_unknown_elems_and_content(c, p, &x->gg);
  
#if 1 /* NORMALMODE */
  ZX_OUT_CLOSE_TAG(p, "</gl:Credential>");
  zx_pop_seen(pop_seen);
#else
  /* root node has no end tag either */
#endif
  ENC_LEN_DEBUG(x, "gl:Credential", p-enc_base);
  return p;
}

/* FUNC(zx_ENC_WO_gl_Credential) */

/* Render element into string. The XML attributes and elements are
 * processed in wire order by chasing wo pointers. This is what you want for
 * validating signatures on other people's XML documents. */

/* Called by: */
char* zx_ENC_WO_gl_Credential(struct zx_ctx* c, struct zx_gl_Credential_s* x, char* p )
{
  struct zx_elem_s* kid;
  struct zx_ns_s* pop_seen = 0;
  ENC_LEN_DEBUG_BASE;
#if 1 /* NORMALMODE */
  char* q;
  char* qq;
  ZX_OUT_CH(p, '<');
  q = p;
  if (x->gg.g.ns && x->gg.g.ns->prefix_len) {
    ZX_OUT_MEM(p, x->gg.g.ns->prefix, x->gg.g.ns->prefix_len);
    ZX_OUT_CH(p, ':');
  }
  ZX_OUT_MEM(p, "Credential", sizeof("Credential")-1);
  qq = p;

  /* *** sort the namespaces */
  if (c->inc_ns)
    zx_add_inc_ns(c, &pop_seen);
  zx_add_xmlns_if_not_seen(c, x->gg.g.ns, &pop_seen);

  p = zx_enc_seen(p, pop_seen); 
  p = zx_attr_wo_enc(p, x->notOnOrAfter, "notOnOrAfter=\"", sizeof("notOnOrAfter=\"")-1);

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
  ENC_LEN_DEBUG(x, "gl:Credential", p-enc_base);
  return p;
}

/* FUNC(zx_EASY_ENC_SO_gl_Credential) */

/* Called by: */
struct zx_str* zx_EASY_ENC_SO_gl_Credential(struct zx_ctx* c, struct zx_gl_Credential_s* x )
{
  int len;
  char* buf;
  c->ns_tab = ZX_ALLOC(c, sizeof(zx_ns_tab));
  memcpy(c->ns_tab, zx_ns_tab, sizeof(zx_ns_tab));
  len = zx_LEN_SO_gl_Credential(c, x );
  buf = ZX_ALLOC(c, len+1);
  return zx_easy_enc_common(c, zx_ENC_SO_gl_Credential(c, x, buf ), buf, len);
}

/* FUNC(zx_EASY_ENC_WO_gl_Credential) */

/* Called by: */
struct zx_str* zx_EASY_ENC_WO_gl_Credential(struct zx_ctx* c, struct zx_gl_Credential_s* x )
{
  int len;
  char* buf;
  c->ns_tab = ZX_ALLOC(c, sizeof(zx_ns_tab));
  memcpy(c->ns_tab, zx_ns_tab, sizeof(zx_ns_tab));
  len = zx_LEN_WO_gl_Credential(c, x );
  buf = ZX_ALLOC(c, len+1);
  return zx_easy_enc_common(c, zx_ENC_WO_gl_Credential(c, x, buf ), buf, len);
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

#define EL_NAME   gl_Data
#define EL_STRUCT zx_gl_Data_s
#define EL_NS     gl
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

/* FUNC(zx_LEN_SO_gl_Data) */

/* Compute length of an element (and its subelements). The XML attributes
 * and elements are processed in schema order. */

/* Called by: */
int zx_LEN_SO_gl_Data(struct zx_ctx* c, struct zx_gl_Data_s* x )
{
  struct zx_ns_s* pop_seen = 0;
  struct zx_elem_s* se MAYBE_UNUSED;
#if 1 /* NORMALMODE */
  /* *** in simple_elem case should output ns prefix from ns node. */
  int len = sizeof("<gl:Data")-1 + 1 + sizeof("</gl:Data>")-1;
  if (c->inc_ns_len)
    len += zx_len_inc_ns(c, &pop_seen);
  if (x->changeFormat)
    len += zx_len_xmlns_if_not_seen(c, zx_ns_tab+zx_xmlns_ix_gl, &pop_seen);

  len += zx_attr_so_len(x->id, sizeof("id")-1);
  len += zx_attr_so_len(x->itemIDRef, sizeof("itemIDRef")-1);
  len += zx_attr_so_len(x->nextOffset, sizeof("nextOffset")-1);
  len += zx_attr_so_len(x->notSorted, sizeof("notSorted")-1);
  len += zx_attr_so_len(x->remaining, sizeof("remaining")-1);
  len += zx_attr_so_len(x->setID, sizeof("setID")-1);
  len += zx_attr_so_len(x->changeFormat, sizeof("gl:changeFormat")-1);

#else
  /* root node has no begin tag */
  int len = 0;
#endif
  


  len += zx_len_so_common(c, &x->gg);
  zx_pop_seen(pop_seen);
  ENC_LEN_DEBUG(x, "gl:Data", len);
  return len;
}

/* FUNC(zx_LEN_WO_gl_Data) */

/* Compute length of an element (and its subelements). The XML attributes
 * and elements are processed in wire order and no assumptions
 * are made about namespace prefixes. */

/* Called by: */
int zx_LEN_WO_gl_Data(struct zx_ctx* c, struct zx_gl_Data_s* x )
{
  struct zx_ns_s* pop_seen = 0;
  struct zx_elem_s* se MAYBE_UNUSED;
#if 1 /* NORMALMODE */
  int len = 1 + sizeof("Data")-1 + 1 + 2 + sizeof("Data")-1 + 1;
  
  if (x->gg.g.ns && x->gg.g.ns->prefix_len)
    len += (x->gg.g.ns->prefix_len + 1) * 2;
  if (c->inc_ns_len)
    len += zx_len_inc_ns(c, &pop_seen);
  if (x->changeFormat)
    len += zx_len_xmlns_if_not_seen(c, x->changeFormat->g.ns, &pop_seen);

  len += zx_attr_wo_len(x->id, sizeof("id")-1);
  len += zx_attr_wo_len(x->itemIDRef, sizeof("itemIDRef")-1);
  len += zx_attr_wo_len(x->nextOffset, sizeof("nextOffset")-1);
  len += zx_attr_wo_len(x->notSorted, sizeof("notSorted")-1);
  len += zx_attr_wo_len(x->remaining, sizeof("remaining")-1);
  len += zx_attr_wo_len(x->setID, sizeof("setID")-1);
  len += zx_attr_wo_len(x->changeFormat, sizeof("changeFormat")-1);

#else
  /* root node has no begin tag */
  int len = 0;
#endif
  


  len += zx_len_wo_common(c, &x->gg); 
  zx_pop_seen(pop_seen);
  ENC_LEN_DEBUG(x, "gl:Data", len);
  return len;
}

/* FUNC(zx_ENC_SO_gl_Data) */

/* Render element into string. The XML attributes and elements are
 * processed in schema order. This is what you generally want for
 * rendering new data structure to a string. The wo pointers are not used. */

/* Called by: */
char* zx_ENC_SO_gl_Data(struct zx_ctx* c, struct zx_gl_Data_s* x, char* p )
{
  struct zx_elem_s* se MAYBE_UNUSED;
  struct zx_ns_s* pop_seen = 0;
  ENC_LEN_DEBUG_BASE;
#if 1 /* NORMALMODE */
  /* *** in simple_elem case should output ns prefix from ns node. */
  ZX_OUT_TAG(p, "<gl:Data");
  if (c->inc_ns)
    p = zx_enc_inc_ns(c, p, &pop_seen);
  if (x->changeFormat)
    p = zx_enc_xmlns_if_not_seen(c, p, zx_ns_tab+zx_xmlns_ix_gl, &pop_seen);

  p = zx_attr_so_enc(p, x->id, " id=\"", sizeof(" id=\"")-1);
  p = zx_attr_so_enc(p, x->itemIDRef, " itemIDRef=\"", sizeof(" itemIDRef=\"")-1);
  p = zx_attr_so_enc(p, x->nextOffset, " nextOffset=\"", sizeof(" nextOffset=\"")-1);
  p = zx_attr_so_enc(p, x->notSorted, " notSorted=\"", sizeof(" notSorted=\"")-1);
  p = zx_attr_so_enc(p, x->remaining, " remaining=\"", sizeof(" remaining=\"")-1);
  p = zx_attr_so_enc(p, x->setID, " setID=\"", sizeof(" setID=\"")-1);
  p = zx_attr_so_enc(p, x->changeFormat, " gl:changeFormat=\"", sizeof(" gl:changeFormat=\"")-1);

  p = zx_enc_unknown_attrs(p, x->gg.any_attr);
#else
  /* root node has no begin tag */
#endif
  

  p = zx_enc_so_unknown_elems_and_content(c, p, &x->gg);
  
#if 1 /* NORMALMODE */
  ZX_OUT_CLOSE_TAG(p, "</gl:Data>");
  zx_pop_seen(pop_seen);
#else
  /* root node has no end tag either */
#endif
  ENC_LEN_DEBUG(x, "gl:Data", p-enc_base);
  return p;
}

/* FUNC(zx_ENC_WO_gl_Data) */

/* Render element into string. The XML attributes and elements are
 * processed in wire order by chasing wo pointers. This is what you want for
 * validating signatures on other people's XML documents. */

/* Called by: */
char* zx_ENC_WO_gl_Data(struct zx_ctx* c, struct zx_gl_Data_s* x, char* p )
{
  struct zx_elem_s* kid;
  struct zx_ns_s* pop_seen = 0;
  ENC_LEN_DEBUG_BASE;
#if 1 /* NORMALMODE */
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
  if (x->changeFormat)
    zx_add_xmlns_if_not_seen(c, x->changeFormat->g.ns, &pop_seen);

  p = zx_enc_seen(p, pop_seen); 
  p = zx_attr_wo_enc(p, x->id, "id=\"", sizeof("id=\"")-1);
  p = zx_attr_wo_enc(p, x->itemIDRef, "itemIDRef=\"", sizeof("itemIDRef=\"")-1);
  p = zx_attr_wo_enc(p, x->nextOffset, "nextOffset=\"", sizeof("nextOffset=\"")-1);
  p = zx_attr_wo_enc(p, x->notSorted, "notSorted=\"", sizeof("notSorted=\"")-1);
  p = zx_attr_wo_enc(p, x->remaining, "remaining=\"", sizeof("remaining=\"")-1);
  p = zx_attr_wo_enc(p, x->setID, "setID=\"", sizeof("setID=\"")-1);
  p = zx_attr_wo_enc(p, x->changeFormat, "changeFormat=\"", sizeof("changeFormat=\"")-1);

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
  ENC_LEN_DEBUG(x, "gl:Data", p-enc_base);
  return p;
}

/* FUNC(zx_EASY_ENC_SO_gl_Data) */

/* Called by: */
struct zx_str* zx_EASY_ENC_SO_gl_Data(struct zx_ctx* c, struct zx_gl_Data_s* x )
{
  int len;
  char* buf;
  c->ns_tab = ZX_ALLOC(c, sizeof(zx_ns_tab));
  memcpy(c->ns_tab, zx_ns_tab, sizeof(zx_ns_tab));
  len = zx_LEN_SO_gl_Data(c, x );
  buf = ZX_ALLOC(c, len+1);
  return zx_easy_enc_common(c, zx_ENC_SO_gl_Data(c, x, buf ), buf, len);
}

/* FUNC(zx_EASY_ENC_WO_gl_Data) */

/* Called by: */
struct zx_str* zx_EASY_ENC_WO_gl_Data(struct zx_ctx* c, struct zx_gl_Data_s* x )
{
  int len;
  char* buf;
  c->ns_tab = ZX_ALLOC(c, sizeof(zx_ns_tab));
  memcpy(c->ns_tab, zx_ns_tab, sizeof(zx_ns_tab));
  len = zx_LEN_WO_gl_Data(c, x );
  buf = ZX_ALLOC(c, len+1);
  return zx_easy_enc_common(c, zx_ENC_WO_gl_Data(c, x, buf ), buf, len);
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

#define EL_NAME   gl_Delete
#define EL_STRUCT zx_gl_Delete_s
#define EL_NS     gl
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

/* FUNC(zx_LEN_SO_gl_Delete) */

/* Compute length of an element (and its subelements). The XML attributes
 * and elements are processed in schema order. */

/* Called by: */
int zx_LEN_SO_gl_Delete(struct zx_ctx* c, struct zx_gl_Delete_s* x )
{
  struct zx_ns_s* pop_seen = 0;
  struct zx_elem_s* se MAYBE_UNUSED;
#if 1 /* NORMALMODE */
  /* *** in simple_elem case should output ns prefix from ns node. */
  int len = sizeof("<gl:Delete")-1 + 1 + sizeof("</gl:Delete>")-1;
  if (c->inc_ns_len)
    len += zx_len_inc_ns(c, &pop_seen);
  len += zx_len_xmlns_if_not_seen(c, zx_ns_tab+zx_xmlns_ix_gl, &pop_seen);

  len += zx_attr_so_len(x->id, sizeof("id")-1);

#else
  /* root node has no begin tag */
  int len = 0;
#endif
  
  {
      struct zx_gl_ResourceID_s* e;
      for (e = x->ResourceID; e; e = (struct zx_gl_ResourceID_s*)e->gg.g.n)
	  len += zx_LEN_SO_gl_ResourceID(c, e);
  }
  {
      struct zx_gl_EncryptedResourceID_s* e;
      for (e = x->EncryptedResourceID; e; e = (struct zx_gl_EncryptedResourceID_s*)e->gg.g.n)
	  len += zx_LEN_SO_gl_EncryptedResourceID(c, e);
  }
  {
      struct zx_gl_DeleteItem_s* e;
      for (e = x->DeleteItem; e; e = (struct zx_gl_DeleteItem_s*)e->gg.g.n)
	  len += zx_LEN_SO_gl_DeleteItem(c, e);
  }
  {
      struct zx_gl_Extension_s* e;
      for (e = x->Extension; e; e = (struct zx_gl_Extension_s*)e->gg.g.n)
	  len += zx_LEN_SO_gl_Extension(c, e);
  }


  len += zx_len_so_common(c, &x->gg);
  zx_pop_seen(pop_seen);
  ENC_LEN_DEBUG(x, "gl:Delete", len);
  return len;
}

/* FUNC(zx_LEN_WO_gl_Delete) */

/* Compute length of an element (and its subelements). The XML attributes
 * and elements are processed in wire order and no assumptions
 * are made about namespace prefixes. */

/* Called by: */
int zx_LEN_WO_gl_Delete(struct zx_ctx* c, struct zx_gl_Delete_s* x )
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

  len += zx_attr_wo_len(x->id, sizeof("id")-1);

#else
  /* root node has no begin tag */
  int len = 0;
#endif
  
  {
      struct zx_gl_ResourceID_s* e;
      for (e = x->ResourceID; e; e = (struct zx_gl_ResourceID_s*)e->gg.g.n)
	  len += zx_LEN_WO_gl_ResourceID(c, e);
  }
  {
      struct zx_gl_EncryptedResourceID_s* e;
      for (e = x->EncryptedResourceID; e; e = (struct zx_gl_EncryptedResourceID_s*)e->gg.g.n)
	  len += zx_LEN_WO_gl_EncryptedResourceID(c, e);
  }
  {
      struct zx_gl_DeleteItem_s* e;
      for (e = x->DeleteItem; e; e = (struct zx_gl_DeleteItem_s*)e->gg.g.n)
	  len += zx_LEN_WO_gl_DeleteItem(c, e);
  }
  {
      struct zx_gl_Extension_s* e;
      for (e = x->Extension; e; e = (struct zx_gl_Extension_s*)e->gg.g.n)
	  len += zx_LEN_WO_gl_Extension(c, e);
  }


  len += zx_len_wo_common(c, &x->gg); 
  zx_pop_seen(pop_seen);
  ENC_LEN_DEBUG(x, "gl:Delete", len);
  return len;
}

/* FUNC(zx_ENC_SO_gl_Delete) */

/* Render element into string. The XML attributes and elements are
 * processed in schema order. This is what you generally want for
 * rendering new data structure to a string. The wo pointers are not used. */

/* Called by: */
char* zx_ENC_SO_gl_Delete(struct zx_ctx* c, struct zx_gl_Delete_s* x, char* p )
{
  struct zx_elem_s* se MAYBE_UNUSED;
  struct zx_ns_s* pop_seen = 0;
  ENC_LEN_DEBUG_BASE;
#if 1 /* NORMALMODE */
  /* *** in simple_elem case should output ns prefix from ns node. */
  ZX_OUT_TAG(p, "<gl:Delete");
  if (c->inc_ns)
    p = zx_enc_inc_ns(c, p, &pop_seen);
  p = zx_enc_xmlns_if_not_seen(c, p, zx_ns_tab+zx_xmlns_ix_gl, &pop_seen);

  p = zx_attr_so_enc(p, x->id, " id=\"", sizeof(" id=\"")-1);

  p = zx_enc_unknown_attrs(p, x->gg.any_attr);
#else
  /* root node has no begin tag */
#endif
  
  {
      struct zx_gl_ResourceID_s* e;
      for (e = x->ResourceID; e; e = (struct zx_gl_ResourceID_s*)e->gg.g.n)
	  p = zx_ENC_SO_gl_ResourceID(c, e, p);
  }
  {
      struct zx_gl_EncryptedResourceID_s* e;
      for (e = x->EncryptedResourceID; e; e = (struct zx_gl_EncryptedResourceID_s*)e->gg.g.n)
	  p = zx_ENC_SO_gl_EncryptedResourceID(c, e, p);
  }
  {
      struct zx_gl_DeleteItem_s* e;
      for (e = x->DeleteItem; e; e = (struct zx_gl_DeleteItem_s*)e->gg.g.n)
	  p = zx_ENC_SO_gl_DeleteItem(c, e, p);
  }
  {
      struct zx_gl_Extension_s* e;
      for (e = x->Extension; e; e = (struct zx_gl_Extension_s*)e->gg.g.n)
	  p = zx_ENC_SO_gl_Extension(c, e, p);
  }

  p = zx_enc_so_unknown_elems_and_content(c, p, &x->gg);
  
#if 1 /* NORMALMODE */
  ZX_OUT_CLOSE_TAG(p, "</gl:Delete>");
  zx_pop_seen(pop_seen);
#else
  /* root node has no end tag either */
#endif
  ENC_LEN_DEBUG(x, "gl:Delete", p-enc_base);
  return p;
}

/* FUNC(zx_ENC_WO_gl_Delete) */

/* Render element into string. The XML attributes and elements are
 * processed in wire order by chasing wo pointers. This is what you want for
 * validating signatures on other people's XML documents. */

/* Called by: */
char* zx_ENC_WO_gl_Delete(struct zx_ctx* c, struct zx_gl_Delete_s* x, char* p )
{
  struct zx_elem_s* kid;
  struct zx_ns_s* pop_seen = 0;
  ENC_LEN_DEBUG_BASE;
#if 1 /* NORMALMODE */
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
  ENC_LEN_DEBUG(x, "gl:Delete", p-enc_base);
  return p;
}

/* FUNC(zx_EASY_ENC_SO_gl_Delete) */

/* Called by: */
struct zx_str* zx_EASY_ENC_SO_gl_Delete(struct zx_ctx* c, struct zx_gl_Delete_s* x )
{
  int len;
  char* buf;
  c->ns_tab = ZX_ALLOC(c, sizeof(zx_ns_tab));
  memcpy(c->ns_tab, zx_ns_tab, sizeof(zx_ns_tab));
  len = zx_LEN_SO_gl_Delete(c, x );
  buf = ZX_ALLOC(c, len+1);
  return zx_easy_enc_common(c, zx_ENC_SO_gl_Delete(c, x, buf ), buf, len);
}

/* FUNC(zx_EASY_ENC_WO_gl_Delete) */

/* Called by: */
struct zx_str* zx_EASY_ENC_WO_gl_Delete(struct zx_ctx* c, struct zx_gl_Delete_s* x )
{
  int len;
  char* buf;
  c->ns_tab = ZX_ALLOC(c, sizeof(zx_ns_tab));
  memcpy(c->ns_tab, zx_ns_tab, sizeof(zx_ns_tab));
  len = zx_LEN_WO_gl_Delete(c, x );
  buf = ZX_ALLOC(c, len+1);
  return zx_easy_enc_common(c, zx_ENC_WO_gl_Delete(c, x, buf ), buf, len);
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

#define EL_NAME   gl_DeleteItem
#define EL_STRUCT zx_gl_DeleteItem_s
#define EL_NS     gl
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

/* FUNC(zx_LEN_SO_gl_DeleteItem) */

/* Compute length of an element (and its subelements). The XML attributes
 * and elements are processed in schema order. */

/* Called by: */
int zx_LEN_SO_gl_DeleteItem(struct zx_ctx* c, struct zx_gl_DeleteItem_s* x )
{
  struct zx_ns_s* pop_seen = 0;
  struct zx_elem_s* se MAYBE_UNUSED;
#if 1 /* NORMALMODE */
  /* *** in simple_elem case should output ns prefix from ns node. */
  int len = sizeof("<gl:DeleteItem")-1 + 1 + sizeof("</gl:DeleteItem>")-1;
  if (c->inc_ns_len)
    len += zx_len_inc_ns(c, &pop_seen);
  len += zx_len_xmlns_if_not_seen(c, zx_ns_tab+zx_xmlns_ix_gl, &pop_seen);

  len += zx_attr_so_len(x->id, sizeof("id")-1);
  len += zx_attr_so_len(x->itemID, sizeof("itemID")-1);
  len += zx_attr_so_len(x->notChangedSince, sizeof("notChangedSince")-1);
  len += zx_attr_so_len(x->objectType, sizeof("objectType")-1);
  len += zx_attr_so_len(x->predefined, sizeof("predefined")-1);

#else
  /* root node has no begin tag */
  int len = 0;
#endif
  
  for (se = x->Select; se; se = (struct zx_elem_s*)se->g.n)
    len += zx_LEN_SO_simple_elem(c,se, sizeof("gl:Select")-1, zx_ns_tab+zx_xmlns_ix_gl);


  len += zx_len_so_common(c, &x->gg);
  zx_pop_seen(pop_seen);
  ENC_LEN_DEBUG(x, "gl:DeleteItem", len);
  return len;
}

/* FUNC(zx_LEN_WO_gl_DeleteItem) */

/* Compute length of an element (and its subelements). The XML attributes
 * and elements are processed in wire order and no assumptions
 * are made about namespace prefixes. */

/* Called by: */
int zx_LEN_WO_gl_DeleteItem(struct zx_ctx* c, struct zx_gl_DeleteItem_s* x )
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

  len += zx_attr_wo_len(x->id, sizeof("id")-1);
  len += zx_attr_wo_len(x->itemID, sizeof("itemID")-1);
  len += zx_attr_wo_len(x->notChangedSince, sizeof("notChangedSince")-1);
  len += zx_attr_wo_len(x->objectType, sizeof("objectType")-1);
  len += zx_attr_wo_len(x->predefined, sizeof("predefined")-1);

#else
  /* root node has no begin tag */
  int len = 0;
#endif
  
  for (se = x->Select; se; se = (struct zx_elem_s*)se->g.n)
    len += zx_LEN_WO_simple_elem(c, se, sizeof("Select")-1);


  len += zx_len_wo_common(c, &x->gg); 
  zx_pop_seen(pop_seen);
  ENC_LEN_DEBUG(x, "gl:DeleteItem", len);
  return len;
}

/* FUNC(zx_ENC_SO_gl_DeleteItem) */

/* Render element into string. The XML attributes and elements are
 * processed in schema order. This is what you generally want for
 * rendering new data structure to a string. The wo pointers are not used. */

/* Called by: */
char* zx_ENC_SO_gl_DeleteItem(struct zx_ctx* c, struct zx_gl_DeleteItem_s* x, char* p )
{
  struct zx_elem_s* se MAYBE_UNUSED;
  struct zx_ns_s* pop_seen = 0;
  ENC_LEN_DEBUG_BASE;
#if 1 /* NORMALMODE */
  /* *** in simple_elem case should output ns prefix from ns node. */
  ZX_OUT_TAG(p, "<gl:DeleteItem");
  if (c->inc_ns)
    p = zx_enc_inc_ns(c, p, &pop_seen);
  p = zx_enc_xmlns_if_not_seen(c, p, zx_ns_tab+zx_xmlns_ix_gl, &pop_seen);

  p = zx_attr_so_enc(p, x->id, " id=\"", sizeof(" id=\"")-1);
  p = zx_attr_so_enc(p, x->itemID, " itemID=\"", sizeof(" itemID=\"")-1);
  p = zx_attr_so_enc(p, x->notChangedSince, " notChangedSince=\"", sizeof(" notChangedSince=\"")-1);
  p = zx_attr_so_enc(p, x->objectType, " objectType=\"", sizeof(" objectType=\"")-1);
  p = zx_attr_so_enc(p, x->predefined, " predefined=\"", sizeof(" predefined=\"")-1);

  p = zx_enc_unknown_attrs(p, x->gg.any_attr);
#else
  /* root node has no begin tag */
#endif
  
  for (se = x->Select; se; se = (struct zx_elem_s*)se->g.n)
    p = zx_ENC_SO_simple_elem(c, se, p, "gl:Select", sizeof("gl:Select")-1, zx_ns_tab+zx_xmlns_ix_gl);

  p = zx_enc_so_unknown_elems_and_content(c, p, &x->gg);
  
#if 1 /* NORMALMODE */
  ZX_OUT_CLOSE_TAG(p, "</gl:DeleteItem>");
  zx_pop_seen(pop_seen);
#else
  /* root node has no end tag either */
#endif
  ENC_LEN_DEBUG(x, "gl:DeleteItem", p-enc_base);
  return p;
}

/* FUNC(zx_ENC_WO_gl_DeleteItem) */

/* Render element into string. The XML attributes and elements are
 * processed in wire order by chasing wo pointers. This is what you want for
 * validating signatures on other people's XML documents. */

/* Called by: */
char* zx_ENC_WO_gl_DeleteItem(struct zx_ctx* c, struct zx_gl_DeleteItem_s* x, char* p )
{
  struct zx_elem_s* kid;
  struct zx_ns_s* pop_seen = 0;
  ENC_LEN_DEBUG_BASE;
#if 1 /* NORMALMODE */
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

  p = zx_enc_seen(p, pop_seen); 
  p = zx_attr_wo_enc(p, x->id, "id=\"", sizeof("id=\"")-1);
  p = zx_attr_wo_enc(p, x->itemID, "itemID=\"", sizeof("itemID=\"")-1);
  p = zx_attr_wo_enc(p, x->notChangedSince, "notChangedSince=\"", sizeof("notChangedSince=\"")-1);
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
  ENC_LEN_DEBUG(x, "gl:DeleteItem", p-enc_base);
  return p;
}

/* FUNC(zx_EASY_ENC_SO_gl_DeleteItem) */

/* Called by: */
struct zx_str* zx_EASY_ENC_SO_gl_DeleteItem(struct zx_ctx* c, struct zx_gl_DeleteItem_s* x )
{
  int len;
  char* buf;
  c->ns_tab = ZX_ALLOC(c, sizeof(zx_ns_tab));
  memcpy(c->ns_tab, zx_ns_tab, sizeof(zx_ns_tab));
  len = zx_LEN_SO_gl_DeleteItem(c, x );
  buf = ZX_ALLOC(c, len+1);
  return zx_easy_enc_common(c, zx_ENC_SO_gl_DeleteItem(c, x, buf ), buf, len);
}

/* FUNC(zx_EASY_ENC_WO_gl_DeleteItem) */

/* Called by: */
struct zx_str* zx_EASY_ENC_WO_gl_DeleteItem(struct zx_ctx* c, struct zx_gl_DeleteItem_s* x )
{
  int len;
  char* buf;
  c->ns_tab = ZX_ALLOC(c, sizeof(zx_ns_tab));
  memcpy(c->ns_tab, zx_ns_tab, sizeof(zx_ns_tab));
  len = zx_LEN_WO_gl_DeleteItem(c, x );
  buf = ZX_ALLOC(c, len+1);
  return zx_easy_enc_common(c, zx_ENC_WO_gl_DeleteItem(c, x, buf ), buf, len);
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

#define EL_NAME   gl_DeleteResponse
#define EL_STRUCT zx_gl_DeleteResponse_s
#define EL_NS     gl
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

/* FUNC(zx_LEN_SO_gl_DeleteResponse) */

/* Compute length of an element (and its subelements). The XML attributes
 * and elements are processed in schema order. */

/* Called by: */
int zx_LEN_SO_gl_DeleteResponse(struct zx_ctx* c, struct zx_gl_DeleteResponse_s* x )
{
  struct zx_ns_s* pop_seen = 0;
  struct zx_elem_s* se MAYBE_UNUSED;
#if 1 /* NORMALMODE */
  /* *** in simple_elem case should output ns prefix from ns node. */
  int len = sizeof("<gl:DeleteResponse")-1 + 1 + sizeof("</gl:DeleteResponse>")-1;
  if (c->inc_ns_len)
    len += zx_len_inc_ns(c, &pop_seen);
  len += zx_len_xmlns_if_not_seen(c, zx_ns_tab+zx_xmlns_ix_gl, &pop_seen);

  len += zx_attr_so_len(x->id, sizeof("id")-1);

#else
  /* root node has no begin tag */
  int len = 0;
#endif
  
  {
      struct zx_gl_Status_s* e;
      for (e = x->Status; e; e = (struct zx_gl_Status_s*)e->gg.g.n)
	  len += zx_LEN_SO_gl_Status(c, e);
  }
  {
      struct zx_gl_Extension_s* e;
      for (e = x->Extension; e; e = (struct zx_gl_Extension_s*)e->gg.g.n)
	  len += zx_LEN_SO_gl_Extension(c, e);
  }


  len += zx_len_so_common(c, &x->gg);
  zx_pop_seen(pop_seen);
  ENC_LEN_DEBUG(x, "gl:DeleteResponse", len);
  return len;
}

/* FUNC(zx_LEN_WO_gl_DeleteResponse) */

/* Compute length of an element (and its subelements). The XML attributes
 * and elements are processed in wire order and no assumptions
 * are made about namespace prefixes. */

/* Called by: */
int zx_LEN_WO_gl_DeleteResponse(struct zx_ctx* c, struct zx_gl_DeleteResponse_s* x )
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

  len += zx_attr_wo_len(x->id, sizeof("id")-1);

#else
  /* root node has no begin tag */
  int len = 0;
#endif
  
  {
      struct zx_gl_Status_s* e;
      for (e = x->Status; e; e = (struct zx_gl_Status_s*)e->gg.g.n)
	  len += zx_LEN_WO_gl_Status(c, e);
  }
  {
      struct zx_gl_Extension_s* e;
      for (e = x->Extension; e; e = (struct zx_gl_Extension_s*)e->gg.g.n)
	  len += zx_LEN_WO_gl_Extension(c, e);
  }


  len += zx_len_wo_common(c, &x->gg); 
  zx_pop_seen(pop_seen);
  ENC_LEN_DEBUG(x, "gl:DeleteResponse", len);
  return len;
}

/* FUNC(zx_ENC_SO_gl_DeleteResponse) */

/* Render element into string. The XML attributes and elements are
 * processed in schema order. This is what you generally want for
 * rendering new data structure to a string. The wo pointers are not used. */

/* Called by: */
char* zx_ENC_SO_gl_DeleteResponse(struct zx_ctx* c, struct zx_gl_DeleteResponse_s* x, char* p )
{
  struct zx_elem_s* se MAYBE_UNUSED;
  struct zx_ns_s* pop_seen = 0;
  ENC_LEN_DEBUG_BASE;
#if 1 /* NORMALMODE */
  /* *** in simple_elem case should output ns prefix from ns node. */
  ZX_OUT_TAG(p, "<gl:DeleteResponse");
  if (c->inc_ns)
    p = zx_enc_inc_ns(c, p, &pop_seen);
  p = zx_enc_xmlns_if_not_seen(c, p, zx_ns_tab+zx_xmlns_ix_gl, &pop_seen);

  p = zx_attr_so_enc(p, x->id, " id=\"", sizeof(" id=\"")-1);

  p = zx_enc_unknown_attrs(p, x->gg.any_attr);
#else
  /* root node has no begin tag */
#endif
  
  {
      struct zx_gl_Status_s* e;
      for (e = x->Status; e; e = (struct zx_gl_Status_s*)e->gg.g.n)
	  p = zx_ENC_SO_gl_Status(c, e, p);
  }
  {
      struct zx_gl_Extension_s* e;
      for (e = x->Extension; e; e = (struct zx_gl_Extension_s*)e->gg.g.n)
	  p = zx_ENC_SO_gl_Extension(c, e, p);
  }

  p = zx_enc_so_unknown_elems_and_content(c, p, &x->gg);
  
#if 1 /* NORMALMODE */
  ZX_OUT_CLOSE_TAG(p, "</gl:DeleteResponse>");
  zx_pop_seen(pop_seen);
#else
  /* root node has no end tag either */
#endif
  ENC_LEN_DEBUG(x, "gl:DeleteResponse", p-enc_base);
  return p;
}

/* FUNC(zx_ENC_WO_gl_DeleteResponse) */

/* Render element into string. The XML attributes and elements are
 * processed in wire order by chasing wo pointers. This is what you want for
 * validating signatures on other people's XML documents. */

/* Called by: */
char* zx_ENC_WO_gl_DeleteResponse(struct zx_ctx* c, struct zx_gl_DeleteResponse_s* x, char* p )
{
  struct zx_elem_s* kid;
  struct zx_ns_s* pop_seen = 0;
  ENC_LEN_DEBUG_BASE;
#if 1 /* NORMALMODE */
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
  ENC_LEN_DEBUG(x, "gl:DeleteResponse", p-enc_base);
  return p;
}

/* FUNC(zx_EASY_ENC_SO_gl_DeleteResponse) */

/* Called by: */
struct zx_str* zx_EASY_ENC_SO_gl_DeleteResponse(struct zx_ctx* c, struct zx_gl_DeleteResponse_s* x )
{
  int len;
  char* buf;
  c->ns_tab = ZX_ALLOC(c, sizeof(zx_ns_tab));
  memcpy(c->ns_tab, zx_ns_tab, sizeof(zx_ns_tab));
  len = zx_LEN_SO_gl_DeleteResponse(c, x );
  buf = ZX_ALLOC(c, len+1);
  return zx_easy_enc_common(c, zx_ENC_SO_gl_DeleteResponse(c, x, buf ), buf, len);
}

/* FUNC(zx_EASY_ENC_WO_gl_DeleteResponse) */

/* Called by: */
struct zx_str* zx_EASY_ENC_WO_gl_DeleteResponse(struct zx_ctx* c, struct zx_gl_DeleteResponse_s* x )
{
  int len;
  char* buf;
  c->ns_tab = ZX_ALLOC(c, sizeof(zx_ns_tab));
  memcpy(c->ns_tab, zx_ns_tab, sizeof(zx_ns_tab));
  len = zx_LEN_WO_gl_DeleteResponse(c, x );
  buf = ZX_ALLOC(c, len+1);
  return zx_easy_enc_common(c, zx_ENC_WO_gl_DeleteResponse(c, x, buf ), buf, len);
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

#define EL_NAME   gl_EllipticalArea
#define EL_STRUCT zx_gl_EllipticalArea_s
#define EL_NS     gl
#define EL_TAG    EllipticalArea

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

/* FUNC(zx_LEN_SO_gl_EllipticalArea) */

/* Compute length of an element (and its subelements). The XML attributes
 * and elements are processed in schema order. */

/* Called by: */
int zx_LEN_SO_gl_EllipticalArea(struct zx_ctx* c, struct zx_gl_EllipticalArea_s* x )
{
  struct zx_ns_s* pop_seen = 0;
  struct zx_elem_s* se MAYBE_UNUSED;
#if 1 /* NORMALMODE */
  /* *** in simple_elem case should output ns prefix from ns node. */
  int len = sizeof("<gl:EllipticalArea")-1 + 1 + sizeof("</gl:EllipticalArea>")-1;
  if (c->inc_ns_len)
    len += zx_len_inc_ns(c, &pop_seen);
  len += zx_len_xmlns_if_not_seen(c, zx_ns_tab+zx_xmlns_ix_gl, &pop_seen);

  len += zx_attr_so_len(x->gid, sizeof("gid")-1);
  len += zx_attr_so_len(x->srsName, sizeof("srsName")-1);

#else
  /* root node has no begin tag */
  int len = 0;
#endif
  
  {
      struct zx_gl_coord_s* e;
      for (e = x->coord; e; e = (struct zx_gl_coord_s*)e->gg.g.n)
	  len += zx_LEN_SO_gl_coord(c, e);
  }
  for (se = x->angle; se; se = (struct zx_elem_s*)se->g.n)
    len += zx_LEN_SO_simple_elem(c,se, sizeof("gl:angle")-1, zx_ns_tab+zx_xmlns_ix_gl);
  for (se = x->semiMajor; se; se = (struct zx_elem_s*)se->g.n)
    len += zx_LEN_SO_simple_elem(c,se, sizeof("gl:semiMajor")-1, zx_ns_tab+zx_xmlns_ix_gl);
  for (se = x->semiMinor; se; se = (struct zx_elem_s*)se->g.n)
    len += zx_LEN_SO_simple_elem(c,se, sizeof("gl:semiMinor")-1, zx_ns_tab+zx_xmlns_ix_gl);
  for (se = x->angularUnit; se; se = (struct zx_elem_s*)se->g.n)
    len += zx_LEN_SO_simple_elem(c,se, sizeof("gl:angularUnit")-1, zx_ns_tab+zx_xmlns_ix_gl);
  for (se = x->distanceUnit; se; se = (struct zx_elem_s*)se->g.n)
    len += zx_LEN_SO_simple_elem(c,se, sizeof("gl:distanceUnit")-1, zx_ns_tab+zx_xmlns_ix_gl);


  len += zx_len_so_common(c, &x->gg);
  zx_pop_seen(pop_seen);
  ENC_LEN_DEBUG(x, "gl:EllipticalArea", len);
  return len;
}

/* FUNC(zx_LEN_WO_gl_EllipticalArea) */

/* Compute length of an element (and its subelements). The XML attributes
 * and elements are processed in wire order and no assumptions
 * are made about namespace prefixes. */

/* Called by: */
int zx_LEN_WO_gl_EllipticalArea(struct zx_ctx* c, struct zx_gl_EllipticalArea_s* x )
{
  struct zx_ns_s* pop_seen = 0;
  struct zx_elem_s* se MAYBE_UNUSED;
#if 1 /* NORMALMODE */
  int len = 1 + sizeof("EllipticalArea")-1 + 1 + 2 + sizeof("EllipticalArea")-1 + 1;
  
  if (x->gg.g.ns && x->gg.g.ns->prefix_len)
    len += (x->gg.g.ns->prefix_len + 1) * 2;
  if (c->inc_ns_len)
    len += zx_len_inc_ns(c, &pop_seen);
  len += zx_len_xmlns_if_not_seen(c, x->gg.g.ns, &pop_seen);

  len += zx_attr_wo_len(x->gid, sizeof("gid")-1);
  len += zx_attr_wo_len(x->srsName, sizeof("srsName")-1);

#else
  /* root node has no begin tag */
  int len = 0;
#endif
  
  {
      struct zx_gl_coord_s* e;
      for (e = x->coord; e; e = (struct zx_gl_coord_s*)e->gg.g.n)
	  len += zx_LEN_WO_gl_coord(c, e);
  }
  for (se = x->angle; se; se = (struct zx_elem_s*)se->g.n)
    len += zx_LEN_WO_simple_elem(c, se, sizeof("angle")-1);
  for (se = x->semiMajor; se; se = (struct zx_elem_s*)se->g.n)
    len += zx_LEN_WO_simple_elem(c, se, sizeof("semiMajor")-1);
  for (se = x->semiMinor; se; se = (struct zx_elem_s*)se->g.n)
    len += zx_LEN_WO_simple_elem(c, se, sizeof("semiMinor")-1);
  for (se = x->angularUnit; se; se = (struct zx_elem_s*)se->g.n)
    len += zx_LEN_WO_simple_elem(c, se, sizeof("angularUnit")-1);
  for (se = x->distanceUnit; se; se = (struct zx_elem_s*)se->g.n)
    len += zx_LEN_WO_simple_elem(c, se, sizeof("distanceUnit")-1);


  len += zx_len_wo_common(c, &x->gg); 
  zx_pop_seen(pop_seen);
  ENC_LEN_DEBUG(x, "gl:EllipticalArea", len);
  return len;
}

/* FUNC(zx_ENC_SO_gl_EllipticalArea) */

/* Render element into string. The XML attributes and elements are
 * processed in schema order. This is what you generally want for
 * rendering new data structure to a string. The wo pointers are not used. */

/* Called by: */
char* zx_ENC_SO_gl_EllipticalArea(struct zx_ctx* c, struct zx_gl_EllipticalArea_s* x, char* p )
{
  struct zx_elem_s* se MAYBE_UNUSED;
  struct zx_ns_s* pop_seen = 0;
  ENC_LEN_DEBUG_BASE;
#if 1 /* NORMALMODE */
  /* *** in simple_elem case should output ns prefix from ns node. */
  ZX_OUT_TAG(p, "<gl:EllipticalArea");
  if (c->inc_ns)
    p = zx_enc_inc_ns(c, p, &pop_seen);
  p = zx_enc_xmlns_if_not_seen(c, p, zx_ns_tab+zx_xmlns_ix_gl, &pop_seen);

  p = zx_attr_so_enc(p, x->gid, " gid=\"", sizeof(" gid=\"")-1);
  p = zx_attr_so_enc(p, x->srsName, " srsName=\"", sizeof(" srsName=\"")-1);

  p = zx_enc_unknown_attrs(p, x->gg.any_attr);
#else
  /* root node has no begin tag */
#endif
  
  {
      struct zx_gl_coord_s* e;
      for (e = x->coord; e; e = (struct zx_gl_coord_s*)e->gg.g.n)
	  p = zx_ENC_SO_gl_coord(c, e, p);
  }
  for (se = x->angle; se; se = (struct zx_elem_s*)se->g.n)
    p = zx_ENC_SO_simple_elem(c, se, p, "gl:angle", sizeof("gl:angle")-1, zx_ns_tab+zx_xmlns_ix_gl);
  for (se = x->semiMajor; se; se = (struct zx_elem_s*)se->g.n)
    p = zx_ENC_SO_simple_elem(c, se, p, "gl:semiMajor", sizeof("gl:semiMajor")-1, zx_ns_tab+zx_xmlns_ix_gl);
  for (se = x->semiMinor; se; se = (struct zx_elem_s*)se->g.n)
    p = zx_ENC_SO_simple_elem(c, se, p, "gl:semiMinor", sizeof("gl:semiMinor")-1, zx_ns_tab+zx_xmlns_ix_gl);
  for (se = x->angularUnit; se; se = (struct zx_elem_s*)se->g.n)
    p = zx_ENC_SO_simple_elem(c, se, p, "gl:angularUnit", sizeof("gl:angularUnit")-1, zx_ns_tab+zx_xmlns_ix_gl);
  for (se = x->distanceUnit; se; se = (struct zx_elem_s*)se->g.n)
    p = zx_ENC_SO_simple_elem(c, se, p, "gl:distanceUnit", sizeof("gl:distanceUnit")-1, zx_ns_tab+zx_xmlns_ix_gl);

  p = zx_enc_so_unknown_elems_and_content(c, p, &x->gg);
  
#if 1 /* NORMALMODE */
  ZX_OUT_CLOSE_TAG(p, "</gl:EllipticalArea>");
  zx_pop_seen(pop_seen);
#else
  /* root node has no end tag either */
#endif
  ENC_LEN_DEBUG(x, "gl:EllipticalArea", p-enc_base);
  return p;
}

/* FUNC(zx_ENC_WO_gl_EllipticalArea) */

/* Render element into string. The XML attributes and elements are
 * processed in wire order by chasing wo pointers. This is what you want for
 * validating signatures on other people's XML documents. */

/* Called by: */
char* zx_ENC_WO_gl_EllipticalArea(struct zx_ctx* c, struct zx_gl_EllipticalArea_s* x, char* p )
{
  struct zx_elem_s* kid;
  struct zx_ns_s* pop_seen = 0;
  ENC_LEN_DEBUG_BASE;
#if 1 /* NORMALMODE */
  char* q;
  char* qq;
  ZX_OUT_CH(p, '<');
  q = p;
  if (x->gg.g.ns && x->gg.g.ns->prefix_len) {
    ZX_OUT_MEM(p, x->gg.g.ns->prefix, x->gg.g.ns->prefix_len);
    ZX_OUT_CH(p, ':');
  }
  ZX_OUT_MEM(p, "EllipticalArea", sizeof("EllipticalArea")-1);
  qq = p;

  /* *** sort the namespaces */
  if (c->inc_ns)
    zx_add_inc_ns(c, &pop_seen);
  zx_add_xmlns_if_not_seen(c, x->gg.g.ns, &pop_seen);

  p = zx_enc_seen(p, pop_seen); 
  p = zx_attr_wo_enc(p, x->gid, "gid=\"", sizeof("gid=\"")-1);
  p = zx_attr_wo_enc(p, x->srsName, "srsName=\"", sizeof("srsName=\"")-1);

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
  ENC_LEN_DEBUG(x, "gl:EllipticalArea", p-enc_base);
  return p;
}

/* FUNC(zx_EASY_ENC_SO_gl_EllipticalArea) */

/* Called by: */
struct zx_str* zx_EASY_ENC_SO_gl_EllipticalArea(struct zx_ctx* c, struct zx_gl_EllipticalArea_s* x )
{
  int len;
  char* buf;
  c->ns_tab = ZX_ALLOC(c, sizeof(zx_ns_tab));
  memcpy(c->ns_tab, zx_ns_tab, sizeof(zx_ns_tab));
  len = zx_LEN_SO_gl_EllipticalArea(c, x );
  buf = ZX_ALLOC(c, len+1);
  return zx_easy_enc_common(c, zx_ENC_SO_gl_EllipticalArea(c, x, buf ), buf, len);
}

/* FUNC(zx_EASY_ENC_WO_gl_EllipticalArea) */

/* Called by: */
struct zx_str* zx_EASY_ENC_WO_gl_EllipticalArea(struct zx_ctx* c, struct zx_gl_EllipticalArea_s* x )
{
  int len;
  char* buf;
  c->ns_tab = ZX_ALLOC(c, sizeof(zx_ns_tab));
  memcpy(c->ns_tab, zx_ns_tab, sizeof(zx_ns_tab));
  len = zx_LEN_WO_gl_EllipticalArea(c, x );
  buf = ZX_ALLOC(c, len+1);
  return zx_easy_enc_common(c, zx_ENC_WO_gl_EllipticalArea(c, x, buf ), buf, len);
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

#define EL_NAME   gl_EncryptedResourceID
#define EL_STRUCT zx_gl_EncryptedResourceID_s
#define EL_NS     gl
#define EL_TAG    EncryptedResourceID

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

/* FUNC(zx_LEN_SO_gl_EncryptedResourceID) */

/* Compute length of an element (and its subelements). The XML attributes
 * and elements are processed in schema order. */

/* Called by: */
int zx_LEN_SO_gl_EncryptedResourceID(struct zx_ctx* c, struct zx_gl_EncryptedResourceID_s* x )
{
  struct zx_ns_s* pop_seen = 0;
  struct zx_elem_s* se MAYBE_UNUSED;
#if 1 /* NORMALMODE */
  /* *** in simple_elem case should output ns prefix from ns node. */
  int len = sizeof("<gl:EncryptedResourceID")-1 + 1 + sizeof("</gl:EncryptedResourceID>")-1;
  if (c->inc_ns_len)
    len += zx_len_inc_ns(c, &pop_seen);
  len += zx_len_xmlns_if_not_seen(c, zx_ns_tab+zx_xmlns_ix_gl, &pop_seen);


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


  len += zx_len_so_common(c, &x->gg);
  zx_pop_seen(pop_seen);
  ENC_LEN_DEBUG(x, "gl:EncryptedResourceID", len);
  return len;
}

/* FUNC(zx_LEN_WO_gl_EncryptedResourceID) */

/* Compute length of an element (and its subelements). The XML attributes
 * and elements are processed in wire order and no assumptions
 * are made about namespace prefixes. */

/* Called by: */
int zx_LEN_WO_gl_EncryptedResourceID(struct zx_ctx* c, struct zx_gl_EncryptedResourceID_s* x )
{
  struct zx_ns_s* pop_seen = 0;
  struct zx_elem_s* se MAYBE_UNUSED;
#if 1 /* NORMALMODE */
  int len = 1 + sizeof("EncryptedResourceID")-1 + 1 + 2 + sizeof("EncryptedResourceID")-1 + 1;
  
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


  len += zx_len_wo_common(c, &x->gg); 
  zx_pop_seen(pop_seen);
  ENC_LEN_DEBUG(x, "gl:EncryptedResourceID", len);
  return len;
}

/* FUNC(zx_ENC_SO_gl_EncryptedResourceID) */

/* Render element into string. The XML attributes and elements are
 * processed in schema order. This is what you generally want for
 * rendering new data structure to a string. The wo pointers are not used. */

/* Called by: */
char* zx_ENC_SO_gl_EncryptedResourceID(struct zx_ctx* c, struct zx_gl_EncryptedResourceID_s* x, char* p )
{
  struct zx_elem_s* se MAYBE_UNUSED;
  struct zx_ns_s* pop_seen = 0;
  ENC_LEN_DEBUG_BASE;
#if 1 /* NORMALMODE */
  /* *** in simple_elem case should output ns prefix from ns node. */
  ZX_OUT_TAG(p, "<gl:EncryptedResourceID");
  if (c->inc_ns)
    p = zx_enc_inc_ns(c, p, &pop_seen);
  p = zx_enc_xmlns_if_not_seen(c, p, zx_ns_tab+zx_xmlns_ix_gl, &pop_seen);


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
  ZX_OUT_CLOSE_TAG(p, "</gl:EncryptedResourceID>");
  zx_pop_seen(pop_seen);
#else
  /* root node has no end tag either */
#endif
  ENC_LEN_DEBUG(x, "gl:EncryptedResourceID", p-enc_base);
  return p;
}

/* FUNC(zx_ENC_WO_gl_EncryptedResourceID) */

/* Render element into string. The XML attributes and elements are
 * processed in wire order by chasing wo pointers. This is what you want for
 * validating signatures on other people's XML documents. */

/* Called by: */
char* zx_ENC_WO_gl_EncryptedResourceID(struct zx_ctx* c, struct zx_gl_EncryptedResourceID_s* x, char* p )
{
  struct zx_elem_s* kid;
  struct zx_ns_s* pop_seen = 0;
  ENC_LEN_DEBUG_BASE;
#if 1 /* NORMALMODE */
  char* q;
  char* qq;
  ZX_OUT_CH(p, '<');
  q = p;
  if (x->gg.g.ns && x->gg.g.ns->prefix_len) {
    ZX_OUT_MEM(p, x->gg.g.ns->prefix, x->gg.g.ns->prefix_len);
    ZX_OUT_CH(p, ':');
  }
  ZX_OUT_MEM(p, "EncryptedResourceID", sizeof("EncryptedResourceID")-1);
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
  ENC_LEN_DEBUG(x, "gl:EncryptedResourceID", p-enc_base);
  return p;
}

/* FUNC(zx_EASY_ENC_SO_gl_EncryptedResourceID) */

/* Called by: */
struct zx_str* zx_EASY_ENC_SO_gl_EncryptedResourceID(struct zx_ctx* c, struct zx_gl_EncryptedResourceID_s* x )
{
  int len;
  char* buf;
  c->ns_tab = ZX_ALLOC(c, sizeof(zx_ns_tab));
  memcpy(c->ns_tab, zx_ns_tab, sizeof(zx_ns_tab));
  len = zx_LEN_SO_gl_EncryptedResourceID(c, x );
  buf = ZX_ALLOC(c, len+1);
  return zx_easy_enc_common(c, zx_ENC_SO_gl_EncryptedResourceID(c, x, buf ), buf, len);
}

/* FUNC(zx_EASY_ENC_WO_gl_EncryptedResourceID) */

/* Called by: */
struct zx_str* zx_EASY_ENC_WO_gl_EncryptedResourceID(struct zx_ctx* c, struct zx_gl_EncryptedResourceID_s* x )
{
  int len;
  char* buf;
  c->ns_tab = ZX_ALLOC(c, sizeof(zx_ns_tab));
  memcpy(c->ns_tab, zx_ns_tab, sizeof(zx_ns_tab));
  len = zx_LEN_WO_gl_EncryptedResourceID(c, x );
  buf = ZX_ALLOC(c, len+1);
  return zx_easy_enc_common(c, zx_ENC_WO_gl_EncryptedResourceID(c, x, buf ), buf, len);
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

#define EL_NAME   gl_Extension
#define EL_STRUCT zx_gl_Extension_s
#define EL_NS     gl
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

/* FUNC(zx_LEN_SO_gl_Extension) */

/* Compute length of an element (and its subelements). The XML attributes
 * and elements are processed in schema order. */

/* Called by: */
int zx_LEN_SO_gl_Extension(struct zx_ctx* c, struct zx_gl_Extension_s* x )
{
  struct zx_ns_s* pop_seen = 0;
  struct zx_elem_s* se MAYBE_UNUSED;
#if 1 /* NORMALMODE */
  /* *** in simple_elem case should output ns prefix from ns node. */
  int len = sizeof("<gl:Extension")-1 + 1 + sizeof("</gl:Extension>")-1;
  if (c->inc_ns_len)
    len += zx_len_inc_ns(c, &pop_seen);
  len += zx_len_xmlns_if_not_seen(c, zx_ns_tab+zx_xmlns_ix_gl, &pop_seen);


#else
  /* root node has no begin tag */
  int len = 0;
#endif
  


  len += zx_len_so_common(c, &x->gg);
  zx_pop_seen(pop_seen);
  ENC_LEN_DEBUG(x, "gl:Extension", len);
  return len;
}

/* FUNC(zx_LEN_WO_gl_Extension) */

/* Compute length of an element (and its subelements). The XML attributes
 * and elements are processed in wire order and no assumptions
 * are made about namespace prefixes. */

/* Called by: */
int zx_LEN_WO_gl_Extension(struct zx_ctx* c, struct zx_gl_Extension_s* x )
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
  ENC_LEN_DEBUG(x, "gl:Extension", len);
  return len;
}

/* FUNC(zx_ENC_SO_gl_Extension) */

/* Render element into string. The XML attributes and elements are
 * processed in schema order. This is what you generally want for
 * rendering new data structure to a string. The wo pointers are not used. */

/* Called by: */
char* zx_ENC_SO_gl_Extension(struct zx_ctx* c, struct zx_gl_Extension_s* x, char* p )
{
  struct zx_elem_s* se MAYBE_UNUSED;
  struct zx_ns_s* pop_seen = 0;
  ENC_LEN_DEBUG_BASE;
#if 1 /* NORMALMODE */
  /* *** in simple_elem case should output ns prefix from ns node. */
  ZX_OUT_TAG(p, "<gl:Extension");
  if (c->inc_ns)
    p = zx_enc_inc_ns(c, p, &pop_seen);
  p = zx_enc_xmlns_if_not_seen(c, p, zx_ns_tab+zx_xmlns_ix_gl, &pop_seen);


  p = zx_enc_unknown_attrs(p, x->gg.any_attr);
#else
  /* root node has no begin tag */
#endif
  

  p = zx_enc_so_unknown_elems_and_content(c, p, &x->gg);
  
#if 1 /* NORMALMODE */
  ZX_OUT_CLOSE_TAG(p, "</gl:Extension>");
  zx_pop_seen(pop_seen);
#else
  /* root node has no end tag either */
#endif
  ENC_LEN_DEBUG(x, "gl:Extension", p-enc_base);
  return p;
}

/* FUNC(zx_ENC_WO_gl_Extension) */

/* Render element into string. The XML attributes and elements are
 * processed in wire order by chasing wo pointers. This is what you want for
 * validating signatures on other people's XML documents. */

/* Called by: */
char* zx_ENC_WO_gl_Extension(struct zx_ctx* c, struct zx_gl_Extension_s* x, char* p )
{
  struct zx_elem_s* kid;
  struct zx_ns_s* pop_seen = 0;
  ENC_LEN_DEBUG_BASE;
#if 1 /* NORMALMODE */
  char* q;
  char* qq;
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
  ENC_LEN_DEBUG(x, "gl:Extension", p-enc_base);
  return p;
}

/* FUNC(zx_EASY_ENC_SO_gl_Extension) */

/* Called by: */
struct zx_str* zx_EASY_ENC_SO_gl_Extension(struct zx_ctx* c, struct zx_gl_Extension_s* x )
{
  int len;
  char* buf;
  c->ns_tab = ZX_ALLOC(c, sizeof(zx_ns_tab));
  memcpy(c->ns_tab, zx_ns_tab, sizeof(zx_ns_tab));
  len = zx_LEN_SO_gl_Extension(c, x );
  buf = ZX_ALLOC(c, len+1);
  return zx_easy_enc_common(c, zx_ENC_SO_gl_Extension(c, x, buf ), buf, len);
}

/* FUNC(zx_EASY_ENC_WO_gl_Extension) */

/* Called by: */
struct zx_str* zx_EASY_ENC_WO_gl_Extension(struct zx_ctx* c, struct zx_gl_Extension_s* x )
{
  int len;
  char* buf;
  c->ns_tab = ZX_ALLOC(c, sizeof(zx_ns_tab));
  memcpy(c->ns_tab, zx_ns_tab, sizeof(zx_ns_tab));
  len = zx_LEN_WO_gl_Extension(c, x );
  buf = ZX_ALLOC(c, len+1);
  return zx_easy_enc_common(c, zx_ENC_WO_gl_Extension(c, x, buf ), buf, len);
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

#define EL_NAME   gl_GeometryCollection
#define EL_STRUCT zx_gl_GeometryCollection_s
#define EL_NS     gl
#define EL_TAG    GeometryCollection

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

/* FUNC(zx_LEN_SO_gl_GeometryCollection) */

/* Compute length of an element (and its subelements). The XML attributes
 * and elements are processed in schema order. */

/* Called by: */
int zx_LEN_SO_gl_GeometryCollection(struct zx_ctx* c, struct zx_gl_GeometryCollection_s* x )
{
  struct zx_ns_s* pop_seen = 0;
  struct zx_elem_s* se MAYBE_UNUSED;
#if 1 /* NORMALMODE */
  /* *** in simple_elem case should output ns prefix from ns node. */
  int len = sizeof("<gl:GeometryCollection")-1 + 1 + sizeof("</gl:GeometryCollection>")-1;
  if (c->inc_ns_len)
    len += zx_len_inc_ns(c, &pop_seen);
  len += zx_len_xmlns_if_not_seen(c, zx_ns_tab+zx_xmlns_ix_gl, &pop_seen);

  len += zx_attr_so_len(x->gid, sizeof("gid")-1);
  len += zx_attr_so_len(x->srsName, sizeof("srsName")-1);

#else
  /* root node has no begin tag */
  int len = 0;
#endif
  
  {
      struct zx_gl_shape_s* e;
      for (e = x->shape; e; e = (struct zx_gl_shape_s*)e->gg.g.n)
	  len += zx_LEN_SO_gl_shape(c, e);
  }


  len += zx_len_so_common(c, &x->gg);
  zx_pop_seen(pop_seen);
  ENC_LEN_DEBUG(x, "gl:GeometryCollection", len);
  return len;
}

/* FUNC(zx_LEN_WO_gl_GeometryCollection) */

/* Compute length of an element (and its subelements). The XML attributes
 * and elements are processed in wire order and no assumptions
 * are made about namespace prefixes. */

/* Called by: */
int zx_LEN_WO_gl_GeometryCollection(struct zx_ctx* c, struct zx_gl_GeometryCollection_s* x )
{
  struct zx_ns_s* pop_seen = 0;
  struct zx_elem_s* se MAYBE_UNUSED;
#if 1 /* NORMALMODE */
  int len = 1 + sizeof("GeometryCollection")-1 + 1 + 2 + sizeof("GeometryCollection")-1 + 1;
  
  if (x->gg.g.ns && x->gg.g.ns->prefix_len)
    len += (x->gg.g.ns->prefix_len + 1) * 2;
  if (c->inc_ns_len)
    len += zx_len_inc_ns(c, &pop_seen);
  len += zx_len_xmlns_if_not_seen(c, x->gg.g.ns, &pop_seen);

  len += zx_attr_wo_len(x->gid, sizeof("gid")-1);
  len += zx_attr_wo_len(x->srsName, sizeof("srsName")-1);

#else
  /* root node has no begin tag */
  int len = 0;
#endif
  
  {
      struct zx_gl_shape_s* e;
      for (e = x->shape; e; e = (struct zx_gl_shape_s*)e->gg.g.n)
	  len += zx_LEN_WO_gl_shape(c, e);
  }


  len += zx_len_wo_common(c, &x->gg); 
  zx_pop_seen(pop_seen);
  ENC_LEN_DEBUG(x, "gl:GeometryCollection", len);
  return len;
}

/* FUNC(zx_ENC_SO_gl_GeometryCollection) */

/* Render element into string. The XML attributes and elements are
 * processed in schema order. This is what you generally want for
 * rendering new data structure to a string. The wo pointers are not used. */

/* Called by: */
char* zx_ENC_SO_gl_GeometryCollection(struct zx_ctx* c, struct zx_gl_GeometryCollection_s* x, char* p )
{
  struct zx_elem_s* se MAYBE_UNUSED;
  struct zx_ns_s* pop_seen = 0;
  ENC_LEN_DEBUG_BASE;
#if 1 /* NORMALMODE */
  /* *** in simple_elem case should output ns prefix from ns node. */
  ZX_OUT_TAG(p, "<gl:GeometryCollection");
  if (c->inc_ns)
    p = zx_enc_inc_ns(c, p, &pop_seen);
  p = zx_enc_xmlns_if_not_seen(c, p, zx_ns_tab+zx_xmlns_ix_gl, &pop_seen);

  p = zx_attr_so_enc(p, x->gid, " gid=\"", sizeof(" gid=\"")-1);
  p = zx_attr_so_enc(p, x->srsName, " srsName=\"", sizeof(" srsName=\"")-1);

  p = zx_enc_unknown_attrs(p, x->gg.any_attr);
#else
  /* root node has no begin tag */
#endif
  
  {
      struct zx_gl_shape_s* e;
      for (e = x->shape; e; e = (struct zx_gl_shape_s*)e->gg.g.n)
	  p = zx_ENC_SO_gl_shape(c, e, p);
  }

  p = zx_enc_so_unknown_elems_and_content(c, p, &x->gg);
  
#if 1 /* NORMALMODE */
  ZX_OUT_CLOSE_TAG(p, "</gl:GeometryCollection>");
  zx_pop_seen(pop_seen);
#else
  /* root node has no end tag either */
#endif
  ENC_LEN_DEBUG(x, "gl:GeometryCollection", p-enc_base);
  return p;
}

/* FUNC(zx_ENC_WO_gl_GeometryCollection) */

/* Render element into string. The XML attributes and elements are
 * processed in wire order by chasing wo pointers. This is what you want for
 * validating signatures on other people's XML documents. */

/* Called by: */
char* zx_ENC_WO_gl_GeometryCollection(struct zx_ctx* c, struct zx_gl_GeometryCollection_s* x, char* p )
{
  struct zx_elem_s* kid;
  struct zx_ns_s* pop_seen = 0;
  ENC_LEN_DEBUG_BASE;
#if 1 /* NORMALMODE */
  char* q;
  char* qq;
  ZX_OUT_CH(p, '<');
  q = p;
  if (x->gg.g.ns && x->gg.g.ns->prefix_len) {
    ZX_OUT_MEM(p, x->gg.g.ns->prefix, x->gg.g.ns->prefix_len);
    ZX_OUT_CH(p, ':');
  }
  ZX_OUT_MEM(p, "GeometryCollection", sizeof("GeometryCollection")-1);
  qq = p;

  /* *** sort the namespaces */
  if (c->inc_ns)
    zx_add_inc_ns(c, &pop_seen);
  zx_add_xmlns_if_not_seen(c, x->gg.g.ns, &pop_seen);

  p = zx_enc_seen(p, pop_seen); 
  p = zx_attr_wo_enc(p, x->gid, "gid=\"", sizeof("gid=\"")-1);
  p = zx_attr_wo_enc(p, x->srsName, "srsName=\"", sizeof("srsName=\"")-1);

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
  ENC_LEN_DEBUG(x, "gl:GeometryCollection", p-enc_base);
  return p;
}

/* FUNC(zx_EASY_ENC_SO_gl_GeometryCollection) */

/* Called by: */
struct zx_str* zx_EASY_ENC_SO_gl_GeometryCollection(struct zx_ctx* c, struct zx_gl_GeometryCollection_s* x )
{
  int len;
  char* buf;
  c->ns_tab = ZX_ALLOC(c, sizeof(zx_ns_tab));
  memcpy(c->ns_tab, zx_ns_tab, sizeof(zx_ns_tab));
  len = zx_LEN_SO_gl_GeometryCollection(c, x );
  buf = ZX_ALLOC(c, len+1);
  return zx_easy_enc_common(c, zx_ENC_SO_gl_GeometryCollection(c, x, buf ), buf, len);
}

/* FUNC(zx_EASY_ENC_WO_gl_GeometryCollection) */

/* Called by: */
struct zx_str* zx_EASY_ENC_WO_gl_GeometryCollection(struct zx_ctx* c, struct zx_gl_GeometryCollection_s* x )
{
  int len;
  char* buf;
  c->ns_tab = ZX_ALLOC(c, sizeof(zx_ns_tab));
  memcpy(c->ns_tab, zx_ns_tab, sizeof(zx_ns_tab));
  len = zx_LEN_WO_gl_GeometryCollection(c, x );
  buf = ZX_ALLOC(c, len+1);
  return zx_easy_enc_common(c, zx_ENC_WO_gl_GeometryCollection(c, x, buf ), buf, len);
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

#define EL_NAME   gl_Identifier
#define EL_STRUCT zx_gl_Identifier_s
#define EL_NS     gl
#define EL_TAG    Identifier

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

/* FUNC(zx_LEN_SO_gl_Identifier) */

/* Compute length of an element (and its subelements). The XML attributes
 * and elements are processed in schema order. */

/* Called by: */
int zx_LEN_SO_gl_Identifier(struct zx_ctx* c, struct zx_gl_Identifier_s* x )
{
  struct zx_ns_s* pop_seen = 0;
  struct zx_elem_s* se MAYBE_UNUSED;
#if 1 /* NORMALMODE */
  /* *** in simple_elem case should output ns prefix from ns node. */
  int len = sizeof("<gl:Identifier")-1 + 1 + sizeof("</gl:Identifier>")-1;
  if (c->inc_ns_len)
    len += zx_len_inc_ns(c, &pop_seen);
  len += zx_len_xmlns_if_not_seen(c, zx_ns_tab+zx_xmlns_ix_gl, &pop_seen);


#else
  /* root node has no begin tag */
  int len = 0;
#endif
  
  for (se = x->code; se; se = (struct zx_elem_s*)se->g.n)
    len += zx_LEN_SO_simple_elem(c,se, sizeof("gl:code")-1, zx_ns_tab+zx_xmlns_ix_gl);
  for (se = x->codeSpace; se; se = (struct zx_elem_s*)se->g.n)
    len += zx_LEN_SO_simple_elem(c,se, sizeof("gl:codeSpace")-1, zx_ns_tab+zx_xmlns_ix_gl);
  for (se = x->edition; se; se = (struct zx_elem_s*)se->g.n)
    len += zx_LEN_SO_simple_elem(c,se, sizeof("gl:edition")-1, zx_ns_tab+zx_xmlns_ix_gl);


  len += zx_len_so_common(c, &x->gg);
  zx_pop_seen(pop_seen);
  ENC_LEN_DEBUG(x, "gl:Identifier", len);
  return len;
}

/* FUNC(zx_LEN_WO_gl_Identifier) */

/* Compute length of an element (and its subelements). The XML attributes
 * and elements are processed in wire order and no assumptions
 * are made about namespace prefixes. */

/* Called by: */
int zx_LEN_WO_gl_Identifier(struct zx_ctx* c, struct zx_gl_Identifier_s* x )
{
  struct zx_ns_s* pop_seen = 0;
  struct zx_elem_s* se MAYBE_UNUSED;
#if 1 /* NORMALMODE */
  int len = 1 + sizeof("Identifier")-1 + 1 + 2 + sizeof("Identifier")-1 + 1;
  
  if (x->gg.g.ns && x->gg.g.ns->prefix_len)
    len += (x->gg.g.ns->prefix_len + 1) * 2;
  if (c->inc_ns_len)
    len += zx_len_inc_ns(c, &pop_seen);
  len += zx_len_xmlns_if_not_seen(c, x->gg.g.ns, &pop_seen);


#else
  /* root node has no begin tag */
  int len = 0;
#endif
  
  for (se = x->code; se; se = (struct zx_elem_s*)se->g.n)
    len += zx_LEN_WO_simple_elem(c, se, sizeof("code")-1);
  for (se = x->codeSpace; se; se = (struct zx_elem_s*)se->g.n)
    len += zx_LEN_WO_simple_elem(c, se, sizeof("codeSpace")-1);
  for (se = x->edition; se; se = (struct zx_elem_s*)se->g.n)
    len += zx_LEN_WO_simple_elem(c, se, sizeof("edition")-1);


  len += zx_len_wo_common(c, &x->gg); 
  zx_pop_seen(pop_seen);
  ENC_LEN_DEBUG(x, "gl:Identifier", len);
  return len;
}

/* FUNC(zx_ENC_SO_gl_Identifier) */

/* Render element into string. The XML attributes and elements are
 * processed in schema order. This is what you generally want for
 * rendering new data structure to a string. The wo pointers are not used. */

/* Called by: */
char* zx_ENC_SO_gl_Identifier(struct zx_ctx* c, struct zx_gl_Identifier_s* x, char* p )
{
  struct zx_elem_s* se MAYBE_UNUSED;
  struct zx_ns_s* pop_seen = 0;
  ENC_LEN_DEBUG_BASE;
#if 1 /* NORMALMODE */
  /* *** in simple_elem case should output ns prefix from ns node. */
  ZX_OUT_TAG(p, "<gl:Identifier");
  if (c->inc_ns)
    p = zx_enc_inc_ns(c, p, &pop_seen);
  p = zx_enc_xmlns_if_not_seen(c, p, zx_ns_tab+zx_xmlns_ix_gl, &pop_seen);


  p = zx_enc_unknown_attrs(p, x->gg.any_attr);
#else
  /* root node has no begin tag */
#endif
  
  for (se = x->code; se; se = (struct zx_elem_s*)se->g.n)
    p = zx_ENC_SO_simple_elem(c, se, p, "gl:code", sizeof("gl:code")-1, zx_ns_tab+zx_xmlns_ix_gl);
  for (se = x->codeSpace; se; se = (struct zx_elem_s*)se->g.n)
    p = zx_ENC_SO_simple_elem(c, se, p, "gl:codeSpace", sizeof("gl:codeSpace")-1, zx_ns_tab+zx_xmlns_ix_gl);
  for (se = x->edition; se; se = (struct zx_elem_s*)se->g.n)
    p = zx_ENC_SO_simple_elem(c, se, p, "gl:edition", sizeof("gl:edition")-1, zx_ns_tab+zx_xmlns_ix_gl);

  p = zx_enc_so_unknown_elems_and_content(c, p, &x->gg);
  
#if 1 /* NORMALMODE */
  ZX_OUT_CLOSE_TAG(p, "</gl:Identifier>");
  zx_pop_seen(pop_seen);
#else
  /* root node has no end tag either */
#endif
  ENC_LEN_DEBUG(x, "gl:Identifier", p-enc_base);
  return p;
}

/* FUNC(zx_ENC_WO_gl_Identifier) */

/* Render element into string. The XML attributes and elements are
 * processed in wire order by chasing wo pointers. This is what you want for
 * validating signatures on other people's XML documents. */

/* Called by: */
char* zx_ENC_WO_gl_Identifier(struct zx_ctx* c, struct zx_gl_Identifier_s* x, char* p )
{
  struct zx_elem_s* kid;
  struct zx_ns_s* pop_seen = 0;
  ENC_LEN_DEBUG_BASE;
#if 1 /* NORMALMODE */
  char* q;
  char* qq;
  ZX_OUT_CH(p, '<');
  q = p;
  if (x->gg.g.ns && x->gg.g.ns->prefix_len) {
    ZX_OUT_MEM(p, x->gg.g.ns->prefix, x->gg.g.ns->prefix_len);
    ZX_OUT_CH(p, ':');
  }
  ZX_OUT_MEM(p, "Identifier", sizeof("Identifier")-1);
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
  ENC_LEN_DEBUG(x, "gl:Identifier", p-enc_base);
  return p;
}

/* FUNC(zx_EASY_ENC_SO_gl_Identifier) */

/* Called by: */
struct zx_str* zx_EASY_ENC_SO_gl_Identifier(struct zx_ctx* c, struct zx_gl_Identifier_s* x )
{
  int len;
  char* buf;
  c->ns_tab = ZX_ALLOC(c, sizeof(zx_ns_tab));
  memcpy(c->ns_tab, zx_ns_tab, sizeof(zx_ns_tab));
  len = zx_LEN_SO_gl_Identifier(c, x );
  buf = ZX_ALLOC(c, len+1);
  return zx_easy_enc_common(c, zx_ENC_SO_gl_Identifier(c, x, buf ), buf, len);
}

/* FUNC(zx_EASY_ENC_WO_gl_Identifier) */

/* Called by: */
struct zx_str* zx_EASY_ENC_WO_gl_Identifier(struct zx_ctx* c, struct zx_gl_Identifier_s* x )
{
  int len;
  char* buf;
  c->ns_tab = ZX_ALLOC(c, sizeof(zx_ns_tab));
  memcpy(c->ns_tab, zx_ns_tab, sizeof(zx_ns_tab));
  len = zx_LEN_WO_gl_Identifier(c, x );
  buf = ZX_ALLOC(c, len+1);
  return zx_easy_enc_common(c, zx_ENC_WO_gl_Identifier(c, x, buf ), buf, len);
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

#define EL_NAME   gl_ItemData
#define EL_STRUCT zx_gl_ItemData_s
#define EL_NS     gl
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

/* FUNC(zx_LEN_SO_gl_ItemData) */

/* Compute length of an element (and its subelements). The XML attributes
 * and elements are processed in schema order. */

/* Called by: */
int zx_LEN_SO_gl_ItemData(struct zx_ctx* c, struct zx_gl_ItemData_s* x )
{
  struct zx_ns_s* pop_seen = 0;
  struct zx_elem_s* se MAYBE_UNUSED;
#if 1 /* NORMALMODE */
  /* *** in simple_elem case should output ns prefix from ns node. */
  int len = sizeof("<gl:ItemData")-1 + 1 + sizeof("</gl:ItemData>")-1;
  if (c->inc_ns_len)
    len += zx_len_inc_ns(c, &pop_seen);
  if (x->changeFormat)
    len += zx_len_xmlns_if_not_seen(c, zx_ns_tab+zx_xmlns_ix_gl, &pop_seen);

  len += zx_attr_so_len(x->id, sizeof("id")-1);
  len += zx_attr_so_len(x->itemIDRef, sizeof("itemIDRef")-1);
  len += zx_attr_so_len(x->notSorted, sizeof("notSorted")-1);
  len += zx_attr_so_len(x->changeFormat, sizeof("gl:changeFormat")-1);

#else
  /* root node has no begin tag */
  int len = 0;
#endif
  


  len += zx_len_so_common(c, &x->gg);
  zx_pop_seen(pop_seen);
  ENC_LEN_DEBUG(x, "gl:ItemData", len);
  return len;
}

/* FUNC(zx_LEN_WO_gl_ItemData) */

/* Compute length of an element (and its subelements). The XML attributes
 * and elements are processed in wire order and no assumptions
 * are made about namespace prefixes. */

/* Called by: */
int zx_LEN_WO_gl_ItemData(struct zx_ctx* c, struct zx_gl_ItemData_s* x )
{
  struct zx_ns_s* pop_seen = 0;
  struct zx_elem_s* se MAYBE_UNUSED;
#if 1 /* NORMALMODE */
  int len = 1 + sizeof("ItemData")-1 + 1 + 2 + sizeof("ItemData")-1 + 1;
  
  if (x->gg.g.ns && x->gg.g.ns->prefix_len)
    len += (x->gg.g.ns->prefix_len + 1) * 2;
  if (c->inc_ns_len)
    len += zx_len_inc_ns(c, &pop_seen);
  if (x->changeFormat)
    len += zx_len_xmlns_if_not_seen(c, x->changeFormat->g.ns, &pop_seen);

  len += zx_attr_wo_len(x->id, sizeof("id")-1);
  len += zx_attr_wo_len(x->itemIDRef, sizeof("itemIDRef")-1);
  len += zx_attr_wo_len(x->notSorted, sizeof("notSorted")-1);
  len += zx_attr_wo_len(x->changeFormat, sizeof("changeFormat")-1);

#else
  /* root node has no begin tag */
  int len = 0;
#endif
  


  len += zx_len_wo_common(c, &x->gg); 
  zx_pop_seen(pop_seen);
  ENC_LEN_DEBUG(x, "gl:ItemData", len);
  return len;
}

/* FUNC(zx_ENC_SO_gl_ItemData) */

/* Render element into string. The XML attributes and elements are
 * processed in schema order. This is what you generally want for
 * rendering new data structure to a string. The wo pointers are not used. */

/* Called by: */
char* zx_ENC_SO_gl_ItemData(struct zx_ctx* c, struct zx_gl_ItemData_s* x, char* p )
{
  struct zx_elem_s* se MAYBE_UNUSED;
  struct zx_ns_s* pop_seen = 0;
  ENC_LEN_DEBUG_BASE;
#if 1 /* NORMALMODE */
  /* *** in simple_elem case should output ns prefix from ns node. */
  ZX_OUT_TAG(p, "<gl:ItemData");
  if (c->inc_ns)
    p = zx_enc_inc_ns(c, p, &pop_seen);
  if (x->changeFormat)
    p = zx_enc_xmlns_if_not_seen(c, p, zx_ns_tab+zx_xmlns_ix_gl, &pop_seen);

  p = zx_attr_so_enc(p, x->id, " id=\"", sizeof(" id=\"")-1);
  p = zx_attr_so_enc(p, x->itemIDRef, " itemIDRef=\"", sizeof(" itemIDRef=\"")-1);
  p = zx_attr_so_enc(p, x->notSorted, " notSorted=\"", sizeof(" notSorted=\"")-1);
  p = zx_attr_so_enc(p, x->changeFormat, " gl:changeFormat=\"", sizeof(" gl:changeFormat=\"")-1);

  p = zx_enc_unknown_attrs(p, x->gg.any_attr);
#else
  /* root node has no begin tag */
#endif
  

  p = zx_enc_so_unknown_elems_and_content(c, p, &x->gg);
  
#if 1 /* NORMALMODE */
  ZX_OUT_CLOSE_TAG(p, "</gl:ItemData>");
  zx_pop_seen(pop_seen);
#else
  /* root node has no end tag either */
#endif
  ENC_LEN_DEBUG(x, "gl:ItemData", p-enc_base);
  return p;
}

/* FUNC(zx_ENC_WO_gl_ItemData) */

/* Render element into string. The XML attributes and elements are
 * processed in wire order by chasing wo pointers. This is what you want for
 * validating signatures on other people's XML documents. */

/* Called by: */
char* zx_ENC_WO_gl_ItemData(struct zx_ctx* c, struct zx_gl_ItemData_s* x, char* p )
{
  struct zx_elem_s* kid;
  struct zx_ns_s* pop_seen = 0;
  ENC_LEN_DEBUG_BASE;
#if 1 /* NORMALMODE */
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
  if (x->changeFormat)
    zx_add_xmlns_if_not_seen(c, x->changeFormat->g.ns, &pop_seen);

  p = zx_enc_seen(p, pop_seen); 
  p = zx_attr_wo_enc(p, x->id, "id=\"", sizeof("id=\"")-1);
  p = zx_attr_wo_enc(p, x->itemIDRef, "itemIDRef=\"", sizeof("itemIDRef=\"")-1);
  p = zx_attr_wo_enc(p, x->notSorted, "notSorted=\"", sizeof("notSorted=\"")-1);
  p = zx_attr_wo_enc(p, x->changeFormat, "changeFormat=\"", sizeof("changeFormat=\"")-1);

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
  ENC_LEN_DEBUG(x, "gl:ItemData", p-enc_base);
  return p;
}

/* FUNC(zx_EASY_ENC_SO_gl_ItemData) */

/* Called by: */
struct zx_str* zx_EASY_ENC_SO_gl_ItemData(struct zx_ctx* c, struct zx_gl_ItemData_s* x )
{
  int len;
  char* buf;
  c->ns_tab = ZX_ALLOC(c, sizeof(zx_ns_tab));
  memcpy(c->ns_tab, zx_ns_tab, sizeof(zx_ns_tab));
  len = zx_LEN_SO_gl_ItemData(c, x );
  buf = ZX_ALLOC(c, len+1);
  return zx_easy_enc_common(c, zx_ENC_SO_gl_ItemData(c, x, buf ), buf, len);
}

/* FUNC(zx_EASY_ENC_WO_gl_ItemData) */

/* Called by: */
struct zx_str* zx_EASY_ENC_WO_gl_ItemData(struct zx_ctx* c, struct zx_gl_ItemData_s* x )
{
  int len;
  char* buf;
  c->ns_tab = ZX_ALLOC(c, sizeof(zx_ns_tab));
  memcpy(c->ns_tab, zx_ns_tab, sizeof(zx_ns_tab));
  len = zx_LEN_WO_gl_ItemData(c, x );
  buf = ZX_ALLOC(c, len+1);
  return zx_easy_enc_common(c, zx_ENC_WO_gl_ItemData(c, x, buf ), buf, len);
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

#define EL_NAME   gl_ItemSelection
#define EL_STRUCT zx_gl_ItemSelection_s
#define EL_NS     gl
#define EL_TAG    ItemSelection

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

/* FUNC(zx_LEN_SO_gl_ItemSelection) */

/* Compute length of an element (and its subelements). The XML attributes
 * and elements are processed in schema order. */

/* Called by: */
int zx_LEN_SO_gl_ItemSelection(struct zx_ctx* c, struct zx_gl_ItemSelection_s* x )
{
  struct zx_ns_s* pop_seen = 0;
  struct zx_elem_s* se MAYBE_UNUSED;
#if 1 /* NORMALMODE */
  /* *** in simple_elem case should output ns prefix from ns node. */
  int len = sizeof("<gl:ItemSelection")-1 + 1 + sizeof("</gl:ItemSelection>")-1;
  if (c->inc_ns_len)
    len += zx_len_inc_ns(c, &pop_seen);
  len += zx_len_xmlns_if_not_seen(c, zx_ns_tab+zx_xmlns_ix_gl, &pop_seen);


#else
  /* root node has no begin tag */
  int len = 0;
#endif
  
  {
      struct zx_gl_AreaComparison_s* e;
      for (e = x->AreaComparison; e; e = (struct zx_gl_AreaComparison_s*)e->gg.g.n)
	  len += zx_LEN_SO_gl_AreaComparison(c, e);
  }
  {
      struct zx_gl_eqop_s* e;
      for (e = x->eqop; e; e = (struct zx_gl_eqop_s*)e->gg.g.n)
	  len += zx_LEN_SO_gl_eqop(c, e);
  }
  {
      struct zx_gl_geoinfo_s* e;
      for (e = x->geoinfo; e; e = (struct zx_gl_geoinfo_s*)e->gg.g.n)
	  len += zx_LEN_SO_gl_geoinfo(c, e);
  }
  {
      struct zx_gl_loc_type_s* e;
      for (e = x->loc_type; e; e = (struct zx_gl_loc_type_s*)e->gg.g.n)
	  len += zx_LEN_SO_gl_loc_type(c, e);
  }
  {
      struct zx_gl_prio_s* e;
      for (e = x->prio; e; e = (struct zx_gl_prio_s*)e->gg.g.n)
	  len += zx_LEN_SO_gl_prio(c, e);
  }
  {
      struct zx_gl_Extension_s* e;
      for (e = x->Extension; e; e = (struct zx_gl_Extension_s*)e->gg.g.n)
	  len += zx_LEN_SO_gl_Extension(c, e);
  }


  len += zx_len_so_common(c, &x->gg);
  zx_pop_seen(pop_seen);
  ENC_LEN_DEBUG(x, "gl:ItemSelection", len);
  return len;
}

/* FUNC(zx_LEN_WO_gl_ItemSelection) */

/* Compute length of an element (and its subelements). The XML attributes
 * and elements are processed in wire order and no assumptions
 * are made about namespace prefixes. */

/* Called by: */
int zx_LEN_WO_gl_ItemSelection(struct zx_ctx* c, struct zx_gl_ItemSelection_s* x )
{
  struct zx_ns_s* pop_seen = 0;
  struct zx_elem_s* se MAYBE_UNUSED;
#if 1 /* NORMALMODE */
  int len = 1 + sizeof("ItemSelection")-1 + 1 + 2 + sizeof("ItemSelection")-1 + 1;
  
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
      struct zx_gl_AreaComparison_s* e;
      for (e = x->AreaComparison; e; e = (struct zx_gl_AreaComparison_s*)e->gg.g.n)
	  len += zx_LEN_WO_gl_AreaComparison(c, e);
  }
  {
      struct zx_gl_eqop_s* e;
      for (e = x->eqop; e; e = (struct zx_gl_eqop_s*)e->gg.g.n)
	  len += zx_LEN_WO_gl_eqop(c, e);
  }
  {
      struct zx_gl_geoinfo_s* e;
      for (e = x->geoinfo; e; e = (struct zx_gl_geoinfo_s*)e->gg.g.n)
	  len += zx_LEN_WO_gl_geoinfo(c, e);
  }
  {
      struct zx_gl_loc_type_s* e;
      for (e = x->loc_type; e; e = (struct zx_gl_loc_type_s*)e->gg.g.n)
	  len += zx_LEN_WO_gl_loc_type(c, e);
  }
  {
      struct zx_gl_prio_s* e;
      for (e = x->prio; e; e = (struct zx_gl_prio_s*)e->gg.g.n)
	  len += zx_LEN_WO_gl_prio(c, e);
  }
  {
      struct zx_gl_Extension_s* e;
      for (e = x->Extension; e; e = (struct zx_gl_Extension_s*)e->gg.g.n)
	  len += zx_LEN_WO_gl_Extension(c, e);
  }


  len += zx_len_wo_common(c, &x->gg); 
  zx_pop_seen(pop_seen);
  ENC_LEN_DEBUG(x, "gl:ItemSelection", len);
  return len;
}

/* FUNC(zx_ENC_SO_gl_ItemSelection) */

/* Render element into string. The XML attributes and elements are
 * processed in schema order. This is what you generally want for
 * rendering new data structure to a string. The wo pointers are not used. */

/* Called by: */
char* zx_ENC_SO_gl_ItemSelection(struct zx_ctx* c, struct zx_gl_ItemSelection_s* x, char* p )
{
  struct zx_elem_s* se MAYBE_UNUSED;
  struct zx_ns_s* pop_seen = 0;
  ENC_LEN_DEBUG_BASE;
#if 1 /* NORMALMODE */
  /* *** in simple_elem case should output ns prefix from ns node. */
  ZX_OUT_TAG(p, "<gl:ItemSelection");
  if (c->inc_ns)
    p = zx_enc_inc_ns(c, p, &pop_seen);
  p = zx_enc_xmlns_if_not_seen(c, p, zx_ns_tab+zx_xmlns_ix_gl, &pop_seen);


  p = zx_enc_unknown_attrs(p, x->gg.any_attr);
#else
  /* root node has no begin tag */
#endif
  
  {
      struct zx_gl_AreaComparison_s* e;
      for (e = x->AreaComparison; e; e = (struct zx_gl_AreaComparison_s*)e->gg.g.n)
	  p = zx_ENC_SO_gl_AreaComparison(c, e, p);
  }
  {
      struct zx_gl_eqop_s* e;
      for (e = x->eqop; e; e = (struct zx_gl_eqop_s*)e->gg.g.n)
	  p = zx_ENC_SO_gl_eqop(c, e, p);
  }
  {
      struct zx_gl_geoinfo_s* e;
      for (e = x->geoinfo; e; e = (struct zx_gl_geoinfo_s*)e->gg.g.n)
	  p = zx_ENC_SO_gl_geoinfo(c, e, p);
  }
  {
      struct zx_gl_loc_type_s* e;
      for (e = x->loc_type; e; e = (struct zx_gl_loc_type_s*)e->gg.g.n)
	  p = zx_ENC_SO_gl_loc_type(c, e, p);
  }
  {
      struct zx_gl_prio_s* e;
      for (e = x->prio; e; e = (struct zx_gl_prio_s*)e->gg.g.n)
	  p = zx_ENC_SO_gl_prio(c, e, p);
  }
  {
      struct zx_gl_Extension_s* e;
      for (e = x->Extension; e; e = (struct zx_gl_Extension_s*)e->gg.g.n)
	  p = zx_ENC_SO_gl_Extension(c, e, p);
  }

  p = zx_enc_so_unknown_elems_and_content(c, p, &x->gg);
  
#if 1 /* NORMALMODE */
  ZX_OUT_CLOSE_TAG(p, "</gl:ItemSelection>");
  zx_pop_seen(pop_seen);
#else
  /* root node has no end tag either */
#endif
  ENC_LEN_DEBUG(x, "gl:ItemSelection", p-enc_base);
  return p;
}

/* FUNC(zx_ENC_WO_gl_ItemSelection) */

/* Render element into string. The XML attributes and elements are
 * processed in wire order by chasing wo pointers. This is what you want for
 * validating signatures on other people's XML documents. */

/* Called by: */
char* zx_ENC_WO_gl_ItemSelection(struct zx_ctx* c, struct zx_gl_ItemSelection_s* x, char* p )
{
  struct zx_elem_s* kid;
  struct zx_ns_s* pop_seen = 0;
  ENC_LEN_DEBUG_BASE;
#if 1 /* NORMALMODE */
  char* q;
  char* qq;
  ZX_OUT_CH(p, '<');
  q = p;
  if (x->gg.g.ns && x->gg.g.ns->prefix_len) {
    ZX_OUT_MEM(p, x->gg.g.ns->prefix, x->gg.g.ns->prefix_len);
    ZX_OUT_CH(p, ':');
  }
  ZX_OUT_MEM(p, "ItemSelection", sizeof("ItemSelection")-1);
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
  ENC_LEN_DEBUG(x, "gl:ItemSelection", p-enc_base);
  return p;
}

/* FUNC(zx_EASY_ENC_SO_gl_ItemSelection) */

/* Called by: */
struct zx_str* zx_EASY_ENC_SO_gl_ItemSelection(struct zx_ctx* c, struct zx_gl_ItemSelection_s* x )
{
  int len;
  char* buf;
  c->ns_tab = ZX_ALLOC(c, sizeof(zx_ns_tab));
  memcpy(c->ns_tab, zx_ns_tab, sizeof(zx_ns_tab));
  len = zx_LEN_SO_gl_ItemSelection(c, x );
  buf = ZX_ALLOC(c, len+1);
  return zx_easy_enc_common(c, zx_ENC_SO_gl_ItemSelection(c, x, buf ), buf, len);
}

/* FUNC(zx_EASY_ENC_WO_gl_ItemSelection) */

/* Called by: */
struct zx_str* zx_EASY_ENC_WO_gl_ItemSelection(struct zx_ctx* c, struct zx_gl_ItemSelection_s* x )
{
  int len;
  char* buf;
  c->ns_tab = ZX_ALLOC(c, sizeof(zx_ns_tab));
  memcpy(c->ns_tab, zx_ns_tab, sizeof(zx_ns_tab));
  len = zx_LEN_WO_gl_ItemSelection(c, x );
  buf = ZX_ALLOC(c, len+1);
  return zx_easy_enc_common(c, zx_ENC_WO_gl_ItemSelection(c, x, buf ), buf, len);
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

#define EL_NAME   gl_LL
#define EL_STRUCT zx_gl_LL_s
#define EL_NS     gl
#define EL_TAG    LL

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

/* FUNC(zx_LEN_SO_gl_LL) */

/* Compute length of an element (and its subelements). The XML attributes
 * and elements are processed in schema order. */

/* Called by: */
int zx_LEN_SO_gl_LL(struct zx_ctx* c, struct zx_gl_LL_s* x )
{
  struct zx_ns_s* pop_seen = 0;
  struct zx_elem_s* se MAYBE_UNUSED;
#if 1 /* NORMALMODE */
  /* *** in simple_elem case should output ns prefix from ns node. */
  int len = sizeof("<gl:LL")-1 + 1 + sizeof("</gl:LL>")-1;
  if (c->inc_ns_len)
    len += zx_len_inc_ns(c, &pop_seen);
  if (x->script)
    len += zx_len_xmlns_if_not_seen(c, zx_ns_tab+zx_xmlns_ix_gl, &pop_seen);
  if (x->lang)
    len += zx_len_xmlns_if_not_seen(c, zx_ns_tab+zx_xmlns_ix_xml, &pop_seen);

  len += zx_attr_so_len(x->lang, sizeof("xml:lang")-1);
  len += zx_attr_so_len(x->script, sizeof("gl:script")-1);

#else
  /* root node has no begin tag */
  int len = 0;
#endif
  


  len += zx_len_so_common(c, &x->gg);
  zx_pop_seen(pop_seen);
  ENC_LEN_DEBUG(x, "gl:LL", len);
  return len;
}

/* FUNC(zx_LEN_WO_gl_LL) */

/* Compute length of an element (and its subelements). The XML attributes
 * and elements are processed in wire order and no assumptions
 * are made about namespace prefixes. */

/* Called by: */
int zx_LEN_WO_gl_LL(struct zx_ctx* c, struct zx_gl_LL_s* x )
{
  struct zx_ns_s* pop_seen = 0;
  struct zx_elem_s* se MAYBE_UNUSED;
#if 1 /* NORMALMODE */
  int len = 1 + sizeof("LL")-1 + 1 + 2 + sizeof("LL")-1 + 1;
  
  if (x->gg.g.ns && x->gg.g.ns->prefix_len)
    len += (x->gg.g.ns->prefix_len + 1) * 2;
  if (c->inc_ns_len)
    len += zx_len_inc_ns(c, &pop_seen);
  if (x->script)
    len += zx_len_xmlns_if_not_seen(c, x->script->g.ns, &pop_seen);
  if (x->lang)
    len += zx_len_xmlns_if_not_seen(c, x->lang->g.ns, &pop_seen);

  len += zx_attr_wo_len(x->lang, sizeof("lang")-1);
  len += zx_attr_wo_len(x->script, sizeof("script")-1);

#else
  /* root node has no begin tag */
  int len = 0;
#endif
  


  len += zx_len_wo_common(c, &x->gg); 
  zx_pop_seen(pop_seen);
  ENC_LEN_DEBUG(x, "gl:LL", len);
  return len;
}

/* FUNC(zx_ENC_SO_gl_LL) */

/* Render element into string. The XML attributes and elements are
 * processed in schema order. This is what you generally want for
 * rendering new data structure to a string. The wo pointers are not used. */

/* Called by: */
char* zx_ENC_SO_gl_LL(struct zx_ctx* c, struct zx_gl_LL_s* x, char* p )
{
  struct zx_elem_s* se MAYBE_UNUSED;
  struct zx_ns_s* pop_seen = 0;
  ENC_LEN_DEBUG_BASE;
#if 1 /* NORMALMODE */
  /* *** in simple_elem case should output ns prefix from ns node. */
  ZX_OUT_TAG(p, "<gl:LL");
  if (c->inc_ns)
    p = zx_enc_inc_ns(c, p, &pop_seen);
  if (x->script)
    p = zx_enc_xmlns_if_not_seen(c, p, zx_ns_tab+zx_xmlns_ix_gl, &pop_seen);
  if (x->lang)
    p = zx_enc_xmlns_if_not_seen(c, p, zx_ns_tab+zx_xmlns_ix_xml, &pop_seen);

  p = zx_attr_so_enc(p, x->lang, " xml:lang=\"", sizeof(" xml:lang=\"")-1);
  p = zx_attr_so_enc(p, x->script, " gl:script=\"", sizeof(" gl:script=\"")-1);

  p = zx_enc_unknown_attrs(p, x->gg.any_attr);
#else
  /* root node has no begin tag */
#endif
  

  p = zx_enc_so_unknown_elems_and_content(c, p, &x->gg);
  
#if 1 /* NORMALMODE */
  ZX_OUT_CLOSE_TAG(p, "</gl:LL>");
  zx_pop_seen(pop_seen);
#else
  /* root node has no end tag either */
#endif
  ENC_LEN_DEBUG(x, "gl:LL", p-enc_base);
  return p;
}

/* FUNC(zx_ENC_WO_gl_LL) */

/* Render element into string. The XML attributes and elements are
 * processed in wire order by chasing wo pointers. This is what you want for
 * validating signatures on other people's XML documents. */

/* Called by: */
char* zx_ENC_WO_gl_LL(struct zx_ctx* c, struct zx_gl_LL_s* x, char* p )
{
  struct zx_elem_s* kid;
  struct zx_ns_s* pop_seen = 0;
  ENC_LEN_DEBUG_BASE;
#if 1 /* NORMALMODE */
  char* q;
  char* qq;
  ZX_OUT_CH(p, '<');
  q = p;
  if (x->gg.g.ns && x->gg.g.ns->prefix_len) {
    ZX_OUT_MEM(p, x->gg.g.ns->prefix, x->gg.g.ns->prefix_len);
    ZX_OUT_CH(p, ':');
  }
  ZX_OUT_MEM(p, "LL", sizeof("LL")-1);
  qq = p;

  /* *** sort the namespaces */
  if (c->inc_ns)
    zx_add_inc_ns(c, &pop_seen);
  if (x->script)
    zx_add_xmlns_if_not_seen(c, x->script->g.ns, &pop_seen);
  if (x->lang)
    zx_add_xmlns_if_not_seen(c, x->lang->g.ns, &pop_seen);

  p = zx_enc_seen(p, pop_seen); 
  p = zx_attr_wo_enc(p, x->lang, "lang=\"", sizeof("lang=\"")-1);
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
  ENC_LEN_DEBUG(x, "gl:LL", p-enc_base);
  return p;
}

/* FUNC(zx_EASY_ENC_SO_gl_LL) */

/* Called by: */
struct zx_str* zx_EASY_ENC_SO_gl_LL(struct zx_ctx* c, struct zx_gl_LL_s* x )
{
  int len;
  char* buf;
  c->ns_tab = ZX_ALLOC(c, sizeof(zx_ns_tab));
  memcpy(c->ns_tab, zx_ns_tab, sizeof(zx_ns_tab));
  len = zx_LEN_SO_gl_LL(c, x );
  buf = ZX_ALLOC(c, len+1);
  return zx_easy_enc_common(c, zx_ENC_SO_gl_LL(c, x, buf ), buf, len);
}

/* FUNC(zx_EASY_ENC_WO_gl_LL) */

/* Called by: */
struct zx_str* zx_EASY_ENC_WO_gl_LL(struct zx_ctx* c, struct zx_gl_LL_s* x )
{
  int len;
  char* buf;
  c->ns_tab = ZX_ALLOC(c, sizeof(zx_ns_tab));
  memcpy(c->ns_tab, zx_ns_tab, sizeof(zx_ns_tab));
  len = zx_LEN_WO_gl_LL(c, x );
  buf = ZX_ALLOC(c, len+1);
  return zx_easy_enc_common(c, zx_ENC_WO_gl_LL(c, x, buf ), buf, len);
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

#define EL_NAME   gl_LPostalAddress
#define EL_STRUCT zx_gl_LPostalAddress_s
#define EL_NS     gl
#define EL_TAG    LPostalAddress

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

/* FUNC(zx_LEN_SO_gl_LPostalAddress) */

/* Compute length of an element (and its subelements). The XML attributes
 * and elements are processed in schema order. */

/* Called by: */
int zx_LEN_SO_gl_LPostalAddress(struct zx_ctx* c, struct zx_gl_LPostalAddress_s* x )
{
  struct zx_ns_s* pop_seen = 0;
  struct zx_elem_s* se MAYBE_UNUSED;
#if 1 /* NORMALMODE */
  /* *** in simple_elem case should output ns prefix from ns node. */
  int len = sizeof("<gl:LPostalAddress")-1 + 1 + sizeof("</gl:LPostalAddress>")-1;
  if (c->inc_ns_len)
    len += zx_len_inc_ns(c, &pop_seen);
  if (x->script)
    len += zx_len_xmlns_if_not_seen(c, zx_ns_tab+zx_xmlns_ix_gl, &pop_seen);
  if (x->lang)
    len += zx_len_xmlns_if_not_seen(c, zx_ns_tab+zx_xmlns_ix_xml, &pop_seen);

  len += zx_attr_so_len(x->lang, sizeof("xml:lang")-1);
  len += zx_attr_so_len(x->script, sizeof("gl:script")-1);

#else
  /* root node has no begin tag */
  int len = 0;
#endif
  


  len += zx_len_so_common(c, &x->gg);
  zx_pop_seen(pop_seen);
  ENC_LEN_DEBUG(x, "gl:LPostalAddress", len);
  return len;
}

/* FUNC(zx_LEN_WO_gl_LPostalAddress) */

/* Compute length of an element (and its subelements). The XML attributes
 * and elements are processed in wire order and no assumptions
 * are made about namespace prefixes. */

/* Called by: */
int zx_LEN_WO_gl_LPostalAddress(struct zx_ctx* c, struct zx_gl_LPostalAddress_s* x )
{
  struct zx_ns_s* pop_seen = 0;
  struct zx_elem_s* se MAYBE_UNUSED;
#if 1 /* NORMALMODE */
  int len = 1 + sizeof("LPostalAddress")-1 + 1 + 2 + sizeof("LPostalAddress")-1 + 1;
  
  if (x->gg.g.ns && x->gg.g.ns->prefix_len)
    len += (x->gg.g.ns->prefix_len + 1) * 2;
  if (c->inc_ns_len)
    len += zx_len_inc_ns(c, &pop_seen);
  if (x->script)
    len += zx_len_xmlns_if_not_seen(c, x->script->g.ns, &pop_seen);
  if (x->lang)
    len += zx_len_xmlns_if_not_seen(c, x->lang->g.ns, &pop_seen);

  len += zx_attr_wo_len(x->lang, sizeof("lang")-1);
  len += zx_attr_wo_len(x->script, sizeof("script")-1);

#else
  /* root node has no begin tag */
  int len = 0;
#endif
  


  len += zx_len_wo_common(c, &x->gg); 
  zx_pop_seen(pop_seen);
  ENC_LEN_DEBUG(x, "gl:LPostalAddress", len);
  return len;
}

/* FUNC(zx_ENC_SO_gl_LPostalAddress) */

/* Render element into string. The XML attributes and elements are
 * processed in schema order. This is what you generally want for
 * rendering new data structure to a string. The wo pointers are not used. */

/* Called by: */
char* zx_ENC_SO_gl_LPostalAddress(struct zx_ctx* c, struct zx_gl_LPostalAddress_s* x, char* p )
{
  struct zx_elem_s* se MAYBE_UNUSED;
  struct zx_ns_s* pop_seen = 0;
  ENC_LEN_DEBUG_BASE;
#if 1 /* NORMALMODE */
  /* *** in simple_elem case should output ns prefix from ns node. */
  ZX_OUT_TAG(p, "<gl:LPostalAddress");
  if (c->inc_ns)
    p = zx_enc_inc_ns(c, p, &pop_seen);
  if (x->script)
    p = zx_enc_xmlns_if_not_seen(c, p, zx_ns_tab+zx_xmlns_ix_gl, &pop_seen);
  if (x->lang)
    p = zx_enc_xmlns_if_not_seen(c, p, zx_ns_tab+zx_xmlns_ix_xml, &pop_seen);

  p = zx_attr_so_enc(p, x->lang, " xml:lang=\"", sizeof(" xml:lang=\"")-1);
  p = zx_attr_so_enc(p, x->script, " gl:script=\"", sizeof(" gl:script=\"")-1);

  p = zx_enc_unknown_attrs(p, x->gg.any_attr);
#else
  /* root node has no begin tag */
#endif
  

  p = zx_enc_so_unknown_elems_and_content(c, p, &x->gg);
  
#if 1 /* NORMALMODE */
  ZX_OUT_CLOSE_TAG(p, "</gl:LPostalAddress>");
  zx_pop_seen(pop_seen);
#else
  /* root node has no end tag either */
#endif
  ENC_LEN_DEBUG(x, "gl:LPostalAddress", p-enc_base);
  return p;
}

/* FUNC(zx_ENC_WO_gl_LPostalAddress) */

/* Render element into string. The XML attributes and elements are
 * processed in wire order by chasing wo pointers. This is what you want for
 * validating signatures on other people's XML documents. */

/* Called by: */
char* zx_ENC_WO_gl_LPostalAddress(struct zx_ctx* c, struct zx_gl_LPostalAddress_s* x, char* p )
{
  struct zx_elem_s* kid;
  struct zx_ns_s* pop_seen = 0;
  ENC_LEN_DEBUG_BASE;
#if 1 /* NORMALMODE */
  char* q;
  char* qq;
  ZX_OUT_CH(p, '<');
  q = p;
  if (x->gg.g.ns && x->gg.g.ns->prefix_len) {
    ZX_OUT_MEM(p, x->gg.g.ns->prefix, x->gg.g.ns->prefix_len);
    ZX_OUT_CH(p, ':');
  }
  ZX_OUT_MEM(p, "LPostalAddress", sizeof("LPostalAddress")-1);
  qq = p;

  /* *** sort the namespaces */
  if (c->inc_ns)
    zx_add_inc_ns(c, &pop_seen);
  if (x->script)
    zx_add_xmlns_if_not_seen(c, x->script->g.ns, &pop_seen);
  if (x->lang)
    zx_add_xmlns_if_not_seen(c, x->lang->g.ns, &pop_seen);

  p = zx_enc_seen(p, pop_seen); 
  p = zx_attr_wo_enc(p, x->lang, "lang=\"", sizeof("lang=\"")-1);
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
  ENC_LEN_DEBUG(x, "gl:LPostalAddress", p-enc_base);
  return p;
}

/* FUNC(zx_EASY_ENC_SO_gl_LPostalAddress) */

/* Called by: */
struct zx_str* zx_EASY_ENC_SO_gl_LPostalAddress(struct zx_ctx* c, struct zx_gl_LPostalAddress_s* x )
{
  int len;
  char* buf;
  c->ns_tab = ZX_ALLOC(c, sizeof(zx_ns_tab));
  memcpy(c->ns_tab, zx_ns_tab, sizeof(zx_ns_tab));
  len = zx_LEN_SO_gl_LPostalAddress(c, x );
  buf = ZX_ALLOC(c, len+1);
  return zx_easy_enc_common(c, zx_ENC_SO_gl_LPostalAddress(c, x, buf ), buf, len);
}

/* FUNC(zx_EASY_ENC_WO_gl_LPostalAddress) */

/* Called by: */
struct zx_str* zx_EASY_ENC_WO_gl_LPostalAddress(struct zx_ctx* c, struct zx_gl_LPostalAddress_s* x )
{
  int len;
  char* buf;
  c->ns_tab = ZX_ALLOC(c, sizeof(zx_ns_tab));
  memcpy(c->ns_tab, zx_ns_tab, sizeof(zx_ns_tab));
  len = zx_LEN_WO_gl_LPostalAddress(c, x );
  buf = ZX_ALLOC(c, len+1);
  return zx_easy_enc_common(c, zx_ENC_WO_gl_LPostalAddress(c, x, buf ), buf, len);
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

#define EL_NAME   gl_LSt
#define EL_STRUCT zx_gl_LSt_s
#define EL_NS     gl
#define EL_TAG    LSt

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

/* FUNC(zx_LEN_SO_gl_LSt) */

/* Compute length of an element (and its subelements). The XML attributes
 * and elements are processed in schema order. */

/* Called by: */
int zx_LEN_SO_gl_LSt(struct zx_ctx* c, struct zx_gl_LSt_s* x )
{
  struct zx_ns_s* pop_seen = 0;
  struct zx_elem_s* se MAYBE_UNUSED;
#if 1 /* NORMALMODE */
  /* *** in simple_elem case should output ns prefix from ns node. */
  int len = sizeof("<gl:LSt")-1 + 1 + sizeof("</gl:LSt>")-1;
  if (c->inc_ns_len)
    len += zx_len_inc_ns(c, &pop_seen);
  if (x->script)
    len += zx_len_xmlns_if_not_seen(c, zx_ns_tab+zx_xmlns_ix_gl, &pop_seen);
  if (x->lang)
    len += zx_len_xmlns_if_not_seen(c, zx_ns_tab+zx_xmlns_ix_xml, &pop_seen);

  len += zx_attr_so_len(x->lang, sizeof("xml:lang")-1);
  len += zx_attr_so_len(x->script, sizeof("gl:script")-1);

#else
  /* root node has no begin tag */
  int len = 0;
#endif
  


  len += zx_len_so_common(c, &x->gg);
  zx_pop_seen(pop_seen);
  ENC_LEN_DEBUG(x, "gl:LSt", len);
  return len;
}

/* FUNC(zx_LEN_WO_gl_LSt) */

/* Compute length of an element (and its subelements). The XML attributes
 * and elements are processed in wire order and no assumptions
 * are made about namespace prefixes. */

/* Called by: */
int zx_LEN_WO_gl_LSt(struct zx_ctx* c, struct zx_gl_LSt_s* x )
{
  struct zx_ns_s* pop_seen = 0;
  struct zx_elem_s* se MAYBE_UNUSED;
#if 1 /* NORMALMODE */
  int len = 1 + sizeof("LSt")-1 + 1 + 2 + sizeof("LSt")-1 + 1;
  
  if (x->gg.g.ns && x->gg.g.ns->prefix_len)
    len += (x->gg.g.ns->prefix_len + 1) * 2;
  if (c->inc_ns_len)
    len += zx_len_inc_ns(c, &pop_seen);
  if (x->script)
    len += zx_len_xmlns_if_not_seen(c, x->script->g.ns, &pop_seen);
  if (x->lang)
    len += zx_len_xmlns_if_not_seen(c, x->lang->g.ns, &pop_seen);

  len += zx_attr_wo_len(x->lang, sizeof("lang")-1);
  len += zx_attr_wo_len(x->script, sizeof("script")-1);

#else
  /* root node has no begin tag */
  int len = 0;
#endif
  


  len += zx_len_wo_common(c, &x->gg); 
  zx_pop_seen(pop_seen);
  ENC_LEN_DEBUG(x, "gl:LSt", len);
  return len;
}

/* FUNC(zx_ENC_SO_gl_LSt) */

/* Render element into string. The XML attributes and elements are
 * processed in schema order. This is what you generally want for
 * rendering new data structure to a string. The wo pointers are not used. */

/* Called by: */
char* zx_ENC_SO_gl_LSt(struct zx_ctx* c, struct zx_gl_LSt_s* x, char* p )
{
  struct zx_elem_s* se MAYBE_UNUSED;
  struct zx_ns_s* pop_seen = 0;
  ENC_LEN_DEBUG_BASE;
#if 1 /* NORMALMODE */
  /* *** in simple_elem case should output ns prefix from ns node. */
  ZX_OUT_TAG(p, "<gl:LSt");
  if (c->inc_ns)
    p = zx_enc_inc_ns(c, p, &pop_seen);
  if (x->script)
    p = zx_enc_xmlns_if_not_seen(c, p, zx_ns_tab+zx_xmlns_ix_gl, &pop_seen);
  if (x->lang)
    p = zx_enc_xmlns_if_not_seen(c, p, zx_ns_tab+zx_xmlns_ix_xml, &pop_seen);

  p = zx_attr_so_enc(p, x->lang, " xml:lang=\"", sizeof(" xml:lang=\"")-1);
  p = zx_attr_so_enc(p, x->script, " gl:script=\"", sizeof(" gl:script=\"")-1);

  p = zx_enc_unknown_attrs(p, x->gg.any_attr);
#else
  /* root node has no begin tag */
#endif
  

  p = zx_enc_so_unknown_elems_and_content(c, p, &x->gg);
  
#if 1 /* NORMALMODE */
  ZX_OUT_CLOSE_TAG(p, "</gl:LSt>");
  zx_pop_seen(pop_seen);
#else
  /* root node has no end tag either */
#endif
  ENC_LEN_DEBUG(x, "gl:LSt", p-enc_base);
  return p;
}

/* FUNC(zx_ENC_WO_gl_LSt) */

/* Render element into string. The XML attributes and elements are
 * processed in wire order by chasing wo pointers. This is what you want for
 * validating signatures on other people's XML documents. */

/* Called by: */
char* zx_ENC_WO_gl_LSt(struct zx_ctx* c, struct zx_gl_LSt_s* x, char* p )
{
  struct zx_elem_s* kid;
  struct zx_ns_s* pop_seen = 0;
  ENC_LEN_DEBUG_BASE;
#if 1 /* NORMALMODE */
  char* q;
  char* qq;
  ZX_OUT_CH(p, '<');
  q = p;
  if (x->gg.g.ns && x->gg.g.ns->prefix_len) {
    ZX_OUT_MEM(p, x->gg.g.ns->prefix, x->gg.g.ns->prefix_len);
    ZX_OUT_CH(p, ':');
  }
  ZX_OUT_MEM(p, "LSt", sizeof("LSt")-1);
  qq = p;

  /* *** sort the namespaces */
  if (c->inc_ns)
    zx_add_inc_ns(c, &pop_seen);
  if (x->script)
    zx_add_xmlns_if_not_seen(c, x->script->g.ns, &pop_seen);
  if (x->lang)
    zx_add_xmlns_if_not_seen(c, x->lang->g.ns, &pop_seen);

  p = zx_enc_seen(p, pop_seen); 
  p = zx_attr_wo_enc(p, x->lang, "lang=\"", sizeof("lang=\"")-1);
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
  ENC_LEN_DEBUG(x, "gl:LSt", p-enc_base);
  return p;
}

/* FUNC(zx_EASY_ENC_SO_gl_LSt) */

/* Called by: */
struct zx_str* zx_EASY_ENC_SO_gl_LSt(struct zx_ctx* c, struct zx_gl_LSt_s* x )
{
  int len;
  char* buf;
  c->ns_tab = ZX_ALLOC(c, sizeof(zx_ns_tab));
  memcpy(c->ns_tab, zx_ns_tab, sizeof(zx_ns_tab));
  len = zx_LEN_SO_gl_LSt(c, x );
  buf = ZX_ALLOC(c, len+1);
  return zx_easy_enc_common(c, zx_ENC_SO_gl_LSt(c, x, buf ), buf, len);
}

/* FUNC(zx_EASY_ENC_WO_gl_LSt) */

/* Called by: */
struct zx_str* zx_EASY_ENC_WO_gl_LSt(struct zx_ctx* c, struct zx_gl_LSt_s* x )
{
  int len;
  char* buf;
  c->ns_tab = ZX_ALLOC(c, sizeof(zx_ns_tab));
  memcpy(c->ns_tab, zx_ns_tab, sizeof(zx_ns_tab));
  len = zx_LEN_WO_gl_LSt(c, x );
  buf = ZX_ALLOC(c, len+1);
  return zx_easy_enc_common(c, zx_ENC_WO_gl_LSt(c, x, buf ), buf, len);
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

#define EL_NAME   gl_LineString
#define EL_STRUCT zx_gl_LineString_s
#define EL_NS     gl
#define EL_TAG    LineString

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

/* FUNC(zx_LEN_SO_gl_LineString) */

/* Compute length of an element (and its subelements). The XML attributes
 * and elements are processed in schema order. */

/* Called by: */
int zx_LEN_SO_gl_LineString(struct zx_ctx* c, struct zx_gl_LineString_s* x )
{
  struct zx_ns_s* pop_seen = 0;
  struct zx_elem_s* se MAYBE_UNUSED;
#if 1 /* NORMALMODE */
  /* *** in simple_elem case should output ns prefix from ns node. */
  int len = sizeof("<gl:LineString")-1 + 1 + sizeof("</gl:LineString>")-1;
  if (c->inc_ns_len)
    len += zx_len_inc_ns(c, &pop_seen);
  len += zx_len_xmlns_if_not_seen(c, zx_ns_tab+zx_xmlns_ix_gl, &pop_seen);

  len += zx_attr_so_len(x->gid, sizeof("gid")-1);
  len += zx_attr_so_len(x->srsName, sizeof("srsName")-1);

#else
  /* root node has no begin tag */
  int len = 0;
#endif
  
  {
      struct zx_gl_coord_s* e;
      for (e = x->coord; e; e = (struct zx_gl_coord_s*)e->gg.g.n)
	  len += zx_LEN_SO_gl_coord(c, e);
  }


  len += zx_len_so_common(c, &x->gg);
  zx_pop_seen(pop_seen);
  ENC_LEN_DEBUG(x, "gl:LineString", len);
  return len;
}

/* FUNC(zx_LEN_WO_gl_LineString) */

/* Compute length of an element (and its subelements). The XML attributes
 * and elements are processed in wire order and no assumptions
 * are made about namespace prefixes. */

/* Called by: */
int zx_LEN_WO_gl_LineString(struct zx_ctx* c, struct zx_gl_LineString_s* x )
{
  struct zx_ns_s* pop_seen = 0;
  struct zx_elem_s* se MAYBE_UNUSED;
#if 1 /* NORMALMODE */
  int len = 1 + sizeof("LineString")-1 + 1 + 2 + sizeof("LineString")-1 + 1;
  
  if (x->gg.g.ns && x->gg.g.ns->prefix_len)
    len += (x->gg.g.ns->prefix_len + 1) * 2;
  if (c->inc_ns_len)
    len += zx_len_inc_ns(c, &pop_seen);
  len += zx_len_xmlns_if_not_seen(c, x->gg.g.ns, &pop_seen);

  len += zx_attr_wo_len(x->gid, sizeof("gid")-1);
  len += zx_attr_wo_len(x->srsName, sizeof("srsName")-1);

#else
  /* root node has no begin tag */
  int len = 0;
#endif
  
  {
      struct zx_gl_coord_s* e;
      for (e = x->coord; e; e = (struct zx_gl_coord_s*)e->gg.g.n)
	  len += zx_LEN_WO_gl_coord(c, e);
  }


  len += zx_len_wo_common(c, &x->gg); 
  zx_pop_seen(pop_seen);
  ENC_LEN_DEBUG(x, "gl:LineString", len);
  return len;
}

/* FUNC(zx_ENC_SO_gl_LineString) */

/* Render element into string. The XML attributes and elements are
 * processed in schema order. This is what you generally want for
 * rendering new data structure to a string. The wo pointers are not used. */

/* Called by: */
char* zx_ENC_SO_gl_LineString(struct zx_ctx* c, struct zx_gl_LineString_s* x, char* p )
{
  struct zx_elem_s* se MAYBE_UNUSED;
  struct zx_ns_s* pop_seen = 0;
  ENC_LEN_DEBUG_BASE;
#if 1 /* NORMALMODE */
  /* *** in simple_elem case should output ns prefix from ns node. */
  ZX_OUT_TAG(p, "<gl:LineString");
  if (c->inc_ns)
    p = zx_enc_inc_ns(c, p, &pop_seen);
  p = zx_enc_xmlns_if_not_seen(c, p, zx_ns_tab+zx_xmlns_ix_gl, &pop_seen);

  p = zx_attr_so_enc(p, x->gid, " gid=\"", sizeof(" gid=\"")-1);
  p = zx_attr_so_enc(p, x->srsName, " srsName=\"", sizeof(" srsName=\"")-1);

  p = zx_enc_unknown_attrs(p, x->gg.any_attr);
#else
  /* root node has no begin tag */
#endif
  
  {
      struct zx_gl_coord_s* e;
      for (e = x->coord; e; e = (struct zx_gl_coord_s*)e->gg.g.n)
	  p = zx_ENC_SO_gl_coord(c, e, p);
  }

  p = zx_enc_so_unknown_elems_and_content(c, p, &x->gg);
  
#if 1 /* NORMALMODE */
  ZX_OUT_CLOSE_TAG(p, "</gl:LineString>");
  zx_pop_seen(pop_seen);
#else
  /* root node has no end tag either */
#endif
  ENC_LEN_DEBUG(x, "gl:LineString", p-enc_base);
  return p;
}

/* FUNC(zx_ENC_WO_gl_LineString) */

/* Render element into string. The XML attributes and elements are
 * processed in wire order by chasing wo pointers. This is what you want for
 * validating signatures on other people's XML documents. */

/* Called by: */
char* zx_ENC_WO_gl_LineString(struct zx_ctx* c, struct zx_gl_LineString_s* x, char* p )
{
  struct zx_elem_s* kid;
  struct zx_ns_s* pop_seen = 0;
  ENC_LEN_DEBUG_BASE;
#if 1 /* NORMALMODE */
  char* q;
  char* qq;
  ZX_OUT_CH(p, '<');
  q = p;
  if (x->gg.g.ns && x->gg.g.ns->prefix_len) {
    ZX_OUT_MEM(p, x->gg.g.ns->prefix, x->gg.g.ns->prefix_len);
    ZX_OUT_CH(p, ':');
  }
  ZX_OUT_MEM(p, "LineString", sizeof("LineString")-1);
  qq = p;

  /* *** sort the namespaces */
  if (c->inc_ns)
    zx_add_inc_ns(c, &pop_seen);
  zx_add_xmlns_if_not_seen(c, x->gg.g.ns, &pop_seen);

  p = zx_enc_seen(p, pop_seen); 
  p = zx_attr_wo_enc(p, x->gid, "gid=\"", sizeof("gid=\"")-1);
  p = zx_attr_wo_enc(p, x->srsName, "srsName=\"", sizeof("srsName=\"")-1);

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
  ENC_LEN_DEBUG(x, "gl:LineString", p-enc_base);
  return p;
}

/* FUNC(zx_EASY_ENC_SO_gl_LineString) */

/* Called by: */
struct zx_str* zx_EASY_ENC_SO_gl_LineString(struct zx_ctx* c, struct zx_gl_LineString_s* x )
{
  int len;
  char* buf;
  c->ns_tab = ZX_ALLOC(c, sizeof(zx_ns_tab));
  memcpy(c->ns_tab, zx_ns_tab, sizeof(zx_ns_tab));
  len = zx_LEN_SO_gl_LineString(c, x );
  buf = ZX_ALLOC(c, len+1);
  return zx_easy_enc_common(c, zx_ENC_SO_gl_LineString(c, x, buf ), buf, len);
}

/* FUNC(zx_EASY_ENC_WO_gl_LineString) */

/* Called by: */
struct zx_str* zx_EASY_ENC_WO_gl_LineString(struct zx_ctx* c, struct zx_gl_LineString_s* x )
{
  int len;
  char* buf;
  c->ns_tab = ZX_ALLOC(c, sizeof(zx_ns_tab));
  memcpy(c->ns_tab, zx_ns_tab, sizeof(zx_ns_tab));
  len = zx_LEN_WO_gl_LineString(c, x );
  buf = ZX_ALLOC(c, len+1);
  return zx_easy_enc_common(c, zx_ENC_WO_gl_LineString(c, x, buf ), buf, len);
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

#define EL_NAME   gl_LinearRing
#define EL_STRUCT zx_gl_LinearRing_s
#define EL_NS     gl
#define EL_TAG    LinearRing

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

/* FUNC(zx_LEN_SO_gl_LinearRing) */

/* Compute length of an element (and its subelements). The XML attributes
 * and elements are processed in schema order. */

/* Called by: */
int zx_LEN_SO_gl_LinearRing(struct zx_ctx* c, struct zx_gl_LinearRing_s* x )
{
  struct zx_ns_s* pop_seen = 0;
  struct zx_elem_s* se MAYBE_UNUSED;
#if 1 /* NORMALMODE */
  /* *** in simple_elem case should output ns prefix from ns node. */
  int len = sizeof("<gl:LinearRing")-1 + 1 + sizeof("</gl:LinearRing>")-1;
  if (c->inc_ns_len)
    len += zx_len_inc_ns(c, &pop_seen);
  len += zx_len_xmlns_if_not_seen(c, zx_ns_tab+zx_xmlns_ix_gl, &pop_seen);

  len += zx_attr_so_len(x->gid, sizeof("gid")-1);
  len += zx_attr_so_len(x->srsName, sizeof("srsName")-1);

#else
  /* root node has no begin tag */
  int len = 0;
#endif
  
  {
      struct zx_gl_coord_s* e;
      for (e = x->coord; e; e = (struct zx_gl_coord_s*)e->gg.g.n)
	  len += zx_LEN_SO_gl_coord(c, e);
  }


  len += zx_len_so_common(c, &x->gg);
  zx_pop_seen(pop_seen);
  ENC_LEN_DEBUG(x, "gl:LinearRing", len);
  return len;
}

/* FUNC(zx_LEN_WO_gl_LinearRing) */

/* Compute length of an element (and its subelements). The XML attributes
 * and elements are processed in wire order and no assumptions
 * are made about namespace prefixes. */

/* Called by: */
int zx_LEN_WO_gl_LinearRing(struct zx_ctx* c, struct zx_gl_LinearRing_s* x )
{
  struct zx_ns_s* pop_seen = 0;
  struct zx_elem_s* se MAYBE_UNUSED;
#if 1 /* NORMALMODE */
  int len = 1 + sizeof("LinearRing")-1 + 1 + 2 + sizeof("LinearRing")-1 + 1;
  
  if (x->gg.g.ns && x->gg.g.ns->prefix_len)
    len += (x->gg.g.ns->prefix_len + 1) * 2;
  if (c->inc_ns_len)
    len += zx_len_inc_ns(c, &pop_seen);
  len += zx_len_xmlns_if_not_seen(c, x->gg.g.ns, &pop_seen);

  len += zx_attr_wo_len(x->gid, sizeof("gid")-1);
  len += zx_attr_wo_len(x->srsName, sizeof("srsName")-1);

#else
  /* root node has no begin tag */
  int len = 0;
#endif
  
  {
      struct zx_gl_coord_s* e;
      for (e = x->coord; e; e = (struct zx_gl_coord_s*)e->gg.g.n)
	  len += zx_LEN_WO_gl_coord(c, e);
  }


  len += zx_len_wo_common(c, &x->gg); 
  zx_pop_seen(pop_seen);
  ENC_LEN_DEBUG(x, "gl:LinearRing", len);
  return len;
}

/* FUNC(zx_ENC_SO_gl_LinearRing) */

/* Render element into string. The XML attributes and elements are
 * processed in schema order. This is what you generally want for
 * rendering new data structure to a string. The wo pointers are not used. */

/* Called by: */
char* zx_ENC_SO_gl_LinearRing(struct zx_ctx* c, struct zx_gl_LinearRing_s* x, char* p )
{
  struct zx_elem_s* se MAYBE_UNUSED;
  struct zx_ns_s* pop_seen = 0;
  ENC_LEN_DEBUG_BASE;
#if 1 /* NORMALMODE */
  /* *** in simple_elem case should output ns prefix from ns node. */
  ZX_OUT_TAG(p, "<gl:LinearRing");
  if (c->inc_ns)
    p = zx_enc_inc_ns(c, p, &pop_seen);
  p = zx_enc_xmlns_if_not_seen(c, p, zx_ns_tab+zx_xmlns_ix_gl, &pop_seen);

  p = zx_attr_so_enc(p, x->gid, " gid=\"", sizeof(" gid=\"")-1);
  p = zx_attr_so_enc(p, x->srsName, " srsName=\"", sizeof(" srsName=\"")-1);

  p = zx_enc_unknown_attrs(p, x->gg.any_attr);
#else
  /* root node has no begin tag */
#endif
  
  {
      struct zx_gl_coord_s* e;
      for (e = x->coord; e; e = (struct zx_gl_coord_s*)e->gg.g.n)
	  p = zx_ENC_SO_gl_coord(c, e, p);
  }

  p = zx_enc_so_unknown_elems_and_content(c, p, &x->gg);
  
#if 1 /* NORMALMODE */
  ZX_OUT_CLOSE_TAG(p, "</gl:LinearRing>");
  zx_pop_seen(pop_seen);
#else
  /* root node has no end tag either */
#endif
  ENC_LEN_DEBUG(x, "gl:LinearRing", p-enc_base);
  return p;
}

/* FUNC(zx_ENC_WO_gl_LinearRing) */

/* Render element into string. The XML attributes and elements are
 * processed in wire order by chasing wo pointers. This is what you want for
 * validating signatures on other people's XML documents. */

/* Called by: */
char* zx_ENC_WO_gl_LinearRing(struct zx_ctx* c, struct zx_gl_LinearRing_s* x, char* p )
{
  struct zx_elem_s* kid;
  struct zx_ns_s* pop_seen = 0;
  ENC_LEN_DEBUG_BASE;
#if 1 /* NORMALMODE */
  char* q;
  char* qq;
  ZX_OUT_CH(p, '<');
  q = p;
  if (x->gg.g.ns && x->gg.g.ns->prefix_len) {
    ZX_OUT_MEM(p, x->gg.g.ns->prefix, x->gg.g.ns->prefix_len);
    ZX_OUT_CH(p, ':');
  }
  ZX_OUT_MEM(p, "LinearRing", sizeof("LinearRing")-1);
  qq = p;

  /* *** sort the namespaces */
  if (c->inc_ns)
    zx_add_inc_ns(c, &pop_seen);
  zx_add_xmlns_if_not_seen(c, x->gg.g.ns, &pop_seen);

  p = zx_enc_seen(p, pop_seen); 
  p = zx_attr_wo_enc(p, x->gid, "gid=\"", sizeof("gid=\"")-1);
  p = zx_attr_wo_enc(p, x->srsName, "srsName=\"", sizeof("srsName=\"")-1);

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
  ENC_LEN_DEBUG(x, "gl:LinearRing", p-enc_base);
  return p;
}

/* FUNC(zx_EASY_ENC_SO_gl_LinearRing) */

/* Called by: */
struct zx_str* zx_EASY_ENC_SO_gl_LinearRing(struct zx_ctx* c, struct zx_gl_LinearRing_s* x )
{
  int len;
  char* buf;
  c->ns_tab = ZX_ALLOC(c, sizeof(zx_ns_tab));
  memcpy(c->ns_tab, zx_ns_tab, sizeof(zx_ns_tab));
  len = zx_LEN_SO_gl_LinearRing(c, x );
  buf = ZX_ALLOC(c, len+1);
  return zx_easy_enc_common(c, zx_ENC_SO_gl_LinearRing(c, x, buf ), buf, len);
}

/* FUNC(zx_EASY_ENC_WO_gl_LinearRing) */

/* Called by: */
struct zx_str* zx_EASY_ENC_WO_gl_LinearRing(struct zx_ctx* c, struct zx_gl_LinearRing_s* x )
{
  int len;
  char* buf;
  c->ns_tab = ZX_ALLOC(c, sizeof(zx_ns_tab));
  memcpy(c->ns_tab, zx_ns_tab, sizeof(zx_ns_tab));
  len = zx_LEN_WO_gl_LinearRing(c, x );
  buf = ZX_ALLOC(c, len+1);
  return zx_easy_enc_common(c, zx_ENC_WO_gl_LinearRing(c, x, buf ), buf, len);
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

#define EL_NAME   gl_Modification
#define EL_STRUCT zx_gl_Modification_s
#define EL_NS     gl
#define EL_TAG    Modification

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

/* FUNC(zx_LEN_SO_gl_Modification) */

/* Compute length of an element (and its subelements). The XML attributes
 * and elements are processed in schema order. */

/* Called by: */
int zx_LEN_SO_gl_Modification(struct zx_ctx* c, struct zx_gl_Modification_s* x )
{
  struct zx_ns_s* pop_seen = 0;
  struct zx_elem_s* se MAYBE_UNUSED;
#if 1 /* NORMALMODE */
  /* *** in simple_elem case should output ns prefix from ns node. */
  int len = sizeof("<gl:Modification")-1 + 1 + sizeof("</gl:Modification>")-1;
  if (c->inc_ns_len)
    len += zx_len_inc_ns(c, &pop_seen);
  len += zx_len_xmlns_if_not_seen(c, zx_ns_tab+zx_xmlns_ix_gl, &pop_seen);

  len += zx_attr_so_len(x->id, sizeof("id")-1);
  len += zx_attr_so_len(x->itemID, sizeof("itemID")-1);
  len += zx_attr_so_len(x->notChangedSince, sizeof("notChangedSince")-1);
  len += zx_attr_so_len(x->objectType, sizeof("objectType")-1);
  len += zx_attr_so_len(x->overrideAllowed, sizeof("overrideAllowed")-1);

#else
  /* root node has no begin tag */
  int len = 0;
#endif
  
  for (se = x->Select; se; se = (struct zx_elem_s*)se->g.n)
    len += zx_LEN_SO_simple_elem(c,se, sizeof("gl:Select")-1, zx_ns_tab+zx_xmlns_ix_gl);
  {
      struct zx_gl_NewData_s* e;
      for (e = x->NewData; e; e = (struct zx_gl_NewData_s*)e->gg.g.n)
	  len += zx_LEN_SO_gl_NewData(c, e);
  }


  len += zx_len_so_common(c, &x->gg);
  zx_pop_seen(pop_seen);
  ENC_LEN_DEBUG(x, "gl:Modification", len);
  return len;
}

/* FUNC(zx_LEN_WO_gl_Modification) */

/* Compute length of an element (and its subelements). The XML attributes
 * and elements are processed in wire order and no assumptions
 * are made about namespace prefixes. */

/* Called by: */
int zx_LEN_WO_gl_Modification(struct zx_ctx* c, struct zx_gl_Modification_s* x )
{
  struct zx_ns_s* pop_seen = 0;
  struct zx_elem_s* se MAYBE_UNUSED;
#if 1 /* NORMALMODE */
  int len = 1 + sizeof("Modification")-1 + 1 + 2 + sizeof("Modification")-1 + 1;
  
  if (x->gg.g.ns && x->gg.g.ns->prefix_len)
    len += (x->gg.g.ns->prefix_len + 1) * 2;
  if (c->inc_ns_len)
    len += zx_len_inc_ns(c, &pop_seen);
  len += zx_len_xmlns_if_not_seen(c, x->gg.g.ns, &pop_seen);

  len += zx_attr_wo_len(x->id, sizeof("id")-1);
  len += zx_attr_wo_len(x->itemID, sizeof("itemID")-1);
  len += zx_attr_wo_len(x->notChangedSince, sizeof("notChangedSince")-1);
  len += zx_attr_wo_len(x->objectType, sizeof("objectType")-1);
  len += zx_attr_wo_len(x->overrideAllowed, sizeof("overrideAllowed")-1);

#else
  /* root node has no begin tag */
  int len = 0;
#endif
  
  for (se = x->Select; se; se = (struct zx_elem_s*)se->g.n)
    len += zx_LEN_WO_simple_elem(c, se, sizeof("Select")-1);
  {
      struct zx_gl_NewData_s* e;
      for (e = x->NewData; e; e = (struct zx_gl_NewData_s*)e->gg.g.n)
	  len += zx_LEN_WO_gl_NewData(c, e);
  }


  len += zx_len_wo_common(c, &x->gg); 
  zx_pop_seen(pop_seen);
  ENC_LEN_DEBUG(x, "gl:Modification", len);
  return len;
}

/* FUNC(zx_ENC_SO_gl_Modification) */

/* Render element into string. The XML attributes and elements are
 * processed in schema order. This is what you generally want for
 * rendering new data structure to a string. The wo pointers are not used. */

/* Called by: */
char* zx_ENC_SO_gl_Modification(struct zx_ctx* c, struct zx_gl_Modification_s* x, char* p )
{
  struct zx_elem_s* se MAYBE_UNUSED;
  struct zx_ns_s* pop_seen = 0;
  ENC_LEN_DEBUG_BASE;
#if 1 /* NORMALMODE */
  /* *** in simple_elem case should output ns prefix from ns node. */
  ZX_OUT_TAG(p, "<gl:Modification");
  if (c->inc_ns)
    p = zx_enc_inc_ns(c, p, &pop_seen);
  p = zx_enc_xmlns_if_not_seen(c, p, zx_ns_tab+zx_xmlns_ix_gl, &pop_seen);

  p = zx_attr_so_enc(p, x->id, " id=\"", sizeof(" id=\"")-1);
  p = zx_attr_so_enc(p, x->itemID, " itemID=\"", sizeof(" itemID=\"")-1);
  p = zx_attr_so_enc(p, x->notChangedSince, " notChangedSince=\"", sizeof(" notChangedSince=\"")-1);
  p = zx_attr_so_enc(p, x->objectType, " objectType=\"", sizeof(" objectType=\"")-1);
  p = zx_attr_so_enc(p, x->overrideAllowed, " overrideAllowed=\"", sizeof(" overrideAllowed=\"")-1);

  p = zx_enc_unknown_attrs(p, x->gg.any_attr);
#else
  /* root node has no begin tag */
#endif
  
  for (se = x->Select; se; se = (struct zx_elem_s*)se->g.n)
    p = zx_ENC_SO_simple_elem(c, se, p, "gl:Select", sizeof("gl:Select")-1, zx_ns_tab+zx_xmlns_ix_gl);
  {
      struct zx_gl_NewData_s* e;
      for (e = x->NewData; e; e = (struct zx_gl_NewData_s*)e->gg.g.n)
	  p = zx_ENC_SO_gl_NewData(c, e, p);
  }

  p = zx_enc_so_unknown_elems_and_content(c, p, &x->gg);
  
#if 1 /* NORMALMODE */
  ZX_OUT_CLOSE_TAG(p, "</gl:Modification>");
  zx_pop_seen(pop_seen);
#else
  /* root node has no end tag either */
#endif
  ENC_LEN_DEBUG(x, "gl:Modification", p-enc_base);
  return p;
}

/* FUNC(zx_ENC_WO_gl_Modification) */

/* Render element into string. The XML attributes and elements are
 * processed in wire order by chasing wo pointers. This is what you want for
 * validating signatures on other people's XML documents. */

/* Called by: */
char* zx_ENC_WO_gl_Modification(struct zx_ctx* c, struct zx_gl_Modification_s* x, char* p )
{
  struct zx_elem_s* kid;
  struct zx_ns_s* pop_seen = 0;
  ENC_LEN_DEBUG_BASE;
#if 1 /* NORMALMODE */
  char* q;
  char* qq;
  ZX_OUT_CH(p, '<');
  q = p;
  if (x->gg.g.ns && x->gg.g.ns->prefix_len) {
    ZX_OUT_MEM(p, x->gg.g.ns->prefix, x->gg.g.ns->prefix_len);
    ZX_OUT_CH(p, ':');
  }
  ZX_OUT_MEM(p, "Modification", sizeof("Modification")-1);
  qq = p;

  /* *** sort the namespaces */
  if (c->inc_ns)
    zx_add_inc_ns(c, &pop_seen);
  zx_add_xmlns_if_not_seen(c, x->gg.g.ns, &pop_seen);

  p = zx_enc_seen(p, pop_seen); 
  p = zx_attr_wo_enc(p, x->id, "id=\"", sizeof("id=\"")-1);
  p = zx_attr_wo_enc(p, x->itemID, "itemID=\"", sizeof("itemID=\"")-1);
  p = zx_attr_wo_enc(p, x->notChangedSince, "notChangedSince=\"", sizeof("notChangedSince=\"")-1);
  p = zx_attr_wo_enc(p, x->objectType, "objectType=\"", sizeof("objectType=\"")-1);
  p = zx_attr_wo_enc(p, x->overrideAllowed, "overrideAllowed=\"", sizeof("overrideAllowed=\"")-1);

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
  ENC_LEN_DEBUG(x, "gl:Modification", p-enc_base);
  return p;
}

/* FUNC(zx_EASY_ENC_SO_gl_Modification) */

/* Called by: */
struct zx_str* zx_EASY_ENC_SO_gl_Modification(struct zx_ctx* c, struct zx_gl_Modification_s* x )
{
  int len;
  char* buf;
  c->ns_tab = ZX_ALLOC(c, sizeof(zx_ns_tab));
  memcpy(c->ns_tab, zx_ns_tab, sizeof(zx_ns_tab));
  len = zx_LEN_SO_gl_Modification(c, x );
  buf = ZX_ALLOC(c, len+1);
  return zx_easy_enc_common(c, zx_ENC_SO_gl_Modification(c, x, buf ), buf, len);
}

/* FUNC(zx_EASY_ENC_WO_gl_Modification) */

/* Called by: */
struct zx_str* zx_EASY_ENC_WO_gl_Modification(struct zx_ctx* c, struct zx_gl_Modification_s* x )
{
  int len;
  char* buf;
  c->ns_tab = ZX_ALLOC(c, sizeof(zx_ns_tab));
  memcpy(c->ns_tab, zx_ns_tab, sizeof(zx_ns_tab));
  len = zx_LEN_WO_gl_Modification(c, x );
  buf = ZX_ALLOC(c, len+1);
  return zx_easy_enc_common(c, zx_ENC_WO_gl_Modification(c, x, buf ), buf, len);
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

#define EL_NAME   gl_Modify
#define EL_STRUCT zx_gl_Modify_s
#define EL_NS     gl
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

/* FUNC(zx_LEN_SO_gl_Modify) */

/* Compute length of an element (and its subelements). The XML attributes
 * and elements are processed in schema order. */

/* Called by: */
int zx_LEN_SO_gl_Modify(struct zx_ctx* c, struct zx_gl_Modify_s* x )
{
  struct zx_ns_s* pop_seen = 0;
  struct zx_elem_s* se MAYBE_UNUSED;
#if 1 /* NORMALMODE */
  /* *** in simple_elem case should output ns prefix from ns node. */
  int len = sizeof("<gl:Modify")-1 + 1 + sizeof("</gl:Modify>")-1;
  if (c->inc_ns_len)
    len += zx_len_inc_ns(c, &pop_seen);
  len += zx_len_xmlns_if_not_seen(c, zx_ns_tab+zx_xmlns_ix_gl, &pop_seen);

  len += zx_attr_so_len(x->id, sizeof("id")-1);

#else
  /* root node has no begin tag */
  int len = 0;
#endif
  
  {
      struct zx_gl_ResourceID_s* e;
      for (e = x->ResourceID; e; e = (struct zx_gl_ResourceID_s*)e->gg.g.n)
	  len += zx_LEN_SO_gl_ResourceID(c, e);
  }
  {
      struct zx_gl_EncryptedResourceID_s* e;
      for (e = x->EncryptedResourceID; e; e = (struct zx_gl_EncryptedResourceID_s*)e->gg.g.n)
	  len += zx_LEN_SO_gl_EncryptedResourceID(c, e);
  }
  {
      struct zx_gl_Subscription_s* e;
      for (e = x->Subscription; e; e = (struct zx_gl_Subscription_s*)e->gg.g.n)
	  len += zx_LEN_SO_gl_Subscription(c, e);
  }
  {
      struct zx_gl_Modification_s* e;
      for (e = x->Modification; e; e = (struct zx_gl_Modification_s*)e->gg.g.n)
	  len += zx_LEN_SO_gl_Modification(c, e);
  }
  {
      struct zx_gl_ItemSelection_s* e;
      for (e = x->ItemSelection; e; e = (struct zx_gl_ItemSelection_s*)e->gg.g.n)
	  len += zx_LEN_SO_gl_ItemSelection(c, e);
  }
  {
      struct zx_gl_Extension_s* e;
      for (e = x->Extension; e; e = (struct zx_gl_Extension_s*)e->gg.g.n)
	  len += zx_LEN_SO_gl_Extension(c, e);
  }


  len += zx_len_so_common(c, &x->gg);
  zx_pop_seen(pop_seen);
  ENC_LEN_DEBUG(x, "gl:Modify", len);
  return len;
}

/* FUNC(zx_LEN_WO_gl_Modify) */

/* Compute length of an element (and its subelements). The XML attributes
 * and elements are processed in wire order and no assumptions
 * are made about namespace prefixes. */

/* Called by: */
int zx_LEN_WO_gl_Modify(struct zx_ctx* c, struct zx_gl_Modify_s* x )
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

  len += zx_attr_wo_len(x->id, sizeof("id")-1);

#else
  /* root node has no begin tag */
  int len = 0;
#endif
  
  {
      struct zx_gl_ResourceID_s* e;
      for (e = x->ResourceID; e; e = (struct zx_gl_ResourceID_s*)e->gg.g.n)
	  len += zx_LEN_WO_gl_ResourceID(c, e);
  }
  {
      struct zx_gl_EncryptedResourceID_s* e;
      for (e = x->EncryptedResourceID; e; e = (struct zx_gl_EncryptedResourceID_s*)e->gg.g.n)
	  len += zx_LEN_WO_gl_EncryptedResourceID(c, e);
  }
  {
      struct zx_gl_Subscription_s* e;
      for (e = x->Subscription; e; e = (struct zx_gl_Subscription_s*)e->gg.g.n)
	  len += zx_LEN_WO_gl_Subscription(c, e);
  }
  {
      struct zx_gl_Modification_s* e;
      for (e = x->Modification; e; e = (struct zx_gl_Modification_s*)e->gg.g.n)
	  len += zx_LEN_WO_gl_Modification(c, e);
  }
  {
      struct zx_gl_ItemSelection_s* e;
      for (e = x->ItemSelection; e; e = (struct zx_gl_ItemSelection_s*)e->gg.g.n)
	  len += zx_LEN_WO_gl_ItemSelection(c, e);
  }
  {
      struct zx_gl_Extension_s* e;
      for (e = x->Extension; e; e = (struct zx_gl_Extension_s*)e->gg.g.n)
	  len += zx_LEN_WO_gl_Extension(c, e);
  }


  len += zx_len_wo_common(c, &x->gg); 
  zx_pop_seen(pop_seen);
  ENC_LEN_DEBUG(x, "gl:Modify", len);
  return len;
}

/* FUNC(zx_ENC_SO_gl_Modify) */

/* Render element into string. The XML attributes and elements are
 * processed in schema order. This is what you generally want for
 * rendering new data structure to a string. The wo pointers are not used. */

/* Called by: */
char* zx_ENC_SO_gl_Modify(struct zx_ctx* c, struct zx_gl_Modify_s* x, char* p )
{
  struct zx_elem_s* se MAYBE_UNUSED;
  struct zx_ns_s* pop_seen = 0;
  ENC_LEN_DEBUG_BASE;
#if 1 /* NORMALMODE */
  /* *** in simple_elem case should output ns prefix from ns node. */
  ZX_OUT_TAG(p, "<gl:Modify");
  if (c->inc_ns)
    p = zx_enc_inc_ns(c, p, &pop_seen);
  p = zx_enc_xmlns_if_not_seen(c, p, zx_ns_tab+zx_xmlns_ix_gl, &pop_seen);

  p = zx_attr_so_enc(p, x->id, " id=\"", sizeof(" id=\"")-1);

  p = zx_enc_unknown_attrs(p, x->gg.any_attr);
#else
  /* root node has no begin tag */
#endif
  
  {
      struct zx_gl_ResourceID_s* e;
      for (e = x->ResourceID; e; e = (struct zx_gl_ResourceID_s*)e->gg.g.n)
	  p = zx_ENC_SO_gl_ResourceID(c, e, p);
  }
  {
      struct zx_gl_EncryptedResourceID_s* e;
      for (e = x->EncryptedResourceID; e; e = (struct zx_gl_EncryptedResourceID_s*)e->gg.g.n)
	  p = zx_ENC_SO_gl_EncryptedResourceID(c, e, p);
  }
  {
      struct zx_gl_Subscription_s* e;
      for (e = x->Subscription; e; e = (struct zx_gl_Subscription_s*)e->gg.g.n)
	  p = zx_ENC_SO_gl_Subscription(c, e, p);
  }
  {
      struct zx_gl_Modification_s* e;
      for (e = x->Modification; e; e = (struct zx_gl_Modification_s*)e->gg.g.n)
	  p = zx_ENC_SO_gl_Modification(c, e, p);
  }
  {
      struct zx_gl_ItemSelection_s* e;
      for (e = x->ItemSelection; e; e = (struct zx_gl_ItemSelection_s*)e->gg.g.n)
	  p = zx_ENC_SO_gl_ItemSelection(c, e, p);
  }
  {
      struct zx_gl_Extension_s* e;
      for (e = x->Extension; e; e = (struct zx_gl_Extension_s*)e->gg.g.n)
	  p = zx_ENC_SO_gl_Extension(c, e, p);
  }

  p = zx_enc_so_unknown_elems_and_content(c, p, &x->gg);
  
#if 1 /* NORMALMODE */
  ZX_OUT_CLOSE_TAG(p, "</gl:Modify>");
  zx_pop_seen(pop_seen);
#else
  /* root node has no end tag either */
#endif
  ENC_LEN_DEBUG(x, "gl:Modify", p-enc_base);
  return p;
}

/* FUNC(zx_ENC_WO_gl_Modify) */

/* Render element into string. The XML attributes and elements are
 * processed in wire order by chasing wo pointers. This is what you want for
 * validating signatures on other people's XML documents. */

/* Called by: */
char* zx_ENC_WO_gl_Modify(struct zx_ctx* c, struct zx_gl_Modify_s* x, char* p )
{
  struct zx_elem_s* kid;
  struct zx_ns_s* pop_seen = 0;
  ENC_LEN_DEBUG_BASE;
#if 1 /* NORMALMODE */
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
  ENC_LEN_DEBUG(x, "gl:Modify", p-enc_base);
  return p;
}

/* FUNC(zx_EASY_ENC_SO_gl_Modify) */

/* Called by: */
struct zx_str* zx_EASY_ENC_SO_gl_Modify(struct zx_ctx* c, struct zx_gl_Modify_s* x )
{
  int len;
  char* buf;
  c->ns_tab = ZX_ALLOC(c, sizeof(zx_ns_tab));
  memcpy(c->ns_tab, zx_ns_tab, sizeof(zx_ns_tab));
  len = zx_LEN_SO_gl_Modify(c, x );
  buf = ZX_ALLOC(c, len+1);
  return zx_easy_enc_common(c, zx_ENC_SO_gl_Modify(c, x, buf ), buf, len);
}

/* FUNC(zx_EASY_ENC_WO_gl_Modify) */

/* Called by: */
struct zx_str* zx_EASY_ENC_WO_gl_Modify(struct zx_ctx* c, struct zx_gl_Modify_s* x )
{
  int len;
  char* buf;
  c->ns_tab = ZX_ALLOC(c, sizeof(zx_ns_tab));
  memcpy(c->ns_tab, zx_ns_tab, sizeof(zx_ns_tab));
  len = zx_LEN_WO_gl_Modify(c, x );
  buf = ZX_ALLOC(c, len+1);
  return zx_easy_enc_common(c, zx_ENC_WO_gl_Modify(c, x, buf ), buf, len);
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

#define EL_NAME   gl_ModifyResponse
#define EL_STRUCT zx_gl_ModifyResponse_s
#define EL_NS     gl
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

/* FUNC(zx_LEN_SO_gl_ModifyResponse) */

/* Compute length of an element (and its subelements). The XML attributes
 * and elements are processed in schema order. */

/* Called by: */
int zx_LEN_SO_gl_ModifyResponse(struct zx_ctx* c, struct zx_gl_ModifyResponse_s* x )
{
  struct zx_ns_s* pop_seen = 0;
  struct zx_elem_s* se MAYBE_UNUSED;
#if 1 /* NORMALMODE */
  /* *** in simple_elem case should output ns prefix from ns node. */
  int len = sizeof("<gl:ModifyResponse")-1 + 1 + sizeof("</gl:ModifyResponse>")-1;
  if (c->inc_ns_len)
    len += zx_len_inc_ns(c, &pop_seen);
  len += zx_len_xmlns_if_not_seen(c, zx_ns_tab+zx_xmlns_ix_gl, &pop_seen);

  len += zx_attr_so_len(x->id, sizeof("id")-1);
  len += zx_attr_so_len(x->timeStamp, sizeof("timeStamp")-1);

#else
  /* root node has no begin tag */
  int len = 0;
#endif
  
  {
      struct zx_gl_Status_s* e;
      for (e = x->Status; e; e = (struct zx_gl_Status_s*)e->gg.g.n)
	  len += zx_LEN_SO_gl_Status(c, e);
  }
  {
      struct zx_gl_ItemData_s* e;
      for (e = x->ItemData; e; e = (struct zx_gl_ItemData_s*)e->gg.g.n)
	  len += zx_LEN_SO_gl_ItemData(c, e);
  }
  {
      struct zx_gl_Extension_s* e;
      for (e = x->Extension; e; e = (struct zx_gl_Extension_s*)e->gg.g.n)
	  len += zx_LEN_SO_gl_Extension(c, e);
  }


  len += zx_len_so_common(c, &x->gg);
  zx_pop_seen(pop_seen);
  ENC_LEN_DEBUG(x, "gl:ModifyResponse", len);
  return len;
}

/* FUNC(zx_LEN_WO_gl_ModifyResponse) */

/* Compute length of an element (and its subelements). The XML attributes
 * and elements are processed in wire order and no assumptions
 * are made about namespace prefixes. */

/* Called by: */
int zx_LEN_WO_gl_ModifyResponse(struct zx_ctx* c, struct zx_gl_ModifyResponse_s* x )
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

  len += zx_attr_wo_len(x->id, sizeof("id")-1);
  len += zx_attr_wo_len(x->timeStamp, sizeof("timeStamp")-1);

#else
  /* root node has no begin tag */
  int len = 0;
#endif
  
  {
      struct zx_gl_Status_s* e;
      for (e = x->Status; e; e = (struct zx_gl_Status_s*)e->gg.g.n)
	  len += zx_LEN_WO_gl_Status(c, e);
  }
  {
      struct zx_gl_ItemData_s* e;
      for (e = x->ItemData; e; e = (struct zx_gl_ItemData_s*)e->gg.g.n)
	  len += zx_LEN_WO_gl_ItemData(c, e);
  }
  {
      struct zx_gl_Extension_s* e;
      for (e = x->Extension; e; e = (struct zx_gl_Extension_s*)e->gg.g.n)
	  len += zx_LEN_WO_gl_Extension(c, e);
  }


  len += zx_len_wo_common(c, &x->gg); 
  zx_pop_seen(pop_seen);
  ENC_LEN_DEBUG(x, "gl:ModifyResponse", len);
  return len;
}

/* FUNC(zx_ENC_SO_gl_ModifyResponse) */

/* Render element into string. The XML attributes and elements are
 * processed in schema order. This is what you generally want for
 * rendering new data structure to a string. The wo pointers are not used. */

/* Called by: */
char* zx_ENC_SO_gl_ModifyResponse(struct zx_ctx* c, struct zx_gl_ModifyResponse_s* x, char* p )
{
  struct zx_elem_s* se MAYBE_UNUSED;
  struct zx_ns_s* pop_seen = 0;
  ENC_LEN_DEBUG_BASE;
#if 1 /* NORMALMODE */
  /* *** in simple_elem case should output ns prefix from ns node. */
  ZX_OUT_TAG(p, "<gl:ModifyResponse");
  if (c->inc_ns)
    p = zx_enc_inc_ns(c, p, &pop_seen);
  p = zx_enc_xmlns_if_not_seen(c, p, zx_ns_tab+zx_xmlns_ix_gl, &pop_seen);

  p = zx_attr_so_enc(p, x->id, " id=\"", sizeof(" id=\"")-1);
  p = zx_attr_so_enc(p, x->timeStamp, " timeStamp=\"", sizeof(" timeStamp=\"")-1);

  p = zx_enc_unknown_attrs(p, x->gg.any_attr);
#else
  /* root node has no begin tag */
#endif
  
  {
      struct zx_gl_Status_s* e;
      for (e = x->Status; e; e = (struct zx_gl_Status_s*)e->gg.g.n)
	  p = zx_ENC_SO_gl_Status(c, e, p);
  }
  {
      struct zx_gl_ItemData_s* e;
      for (e = x->ItemData; e; e = (struct zx_gl_ItemData_s*)e->gg.g.n)
	  p = zx_ENC_SO_gl_ItemData(c, e, p);
  }
  {
      struct zx_gl_Extension_s* e;
      for (e = x->Extension; e; e = (struct zx_gl_Extension_s*)e->gg.g.n)
	  p = zx_ENC_SO_gl_Extension(c, e, p);
  }

  p = zx_enc_so_unknown_elems_and_content(c, p, &x->gg);
  
#if 1 /* NORMALMODE */
  ZX_OUT_CLOSE_TAG(p, "</gl:ModifyResponse>");
  zx_pop_seen(pop_seen);
#else
  /* root node has no end tag either */
#endif
  ENC_LEN_DEBUG(x, "gl:ModifyResponse", p-enc_base);
  return p;
}

/* FUNC(zx_ENC_WO_gl_ModifyResponse) */

/* Render element into string. The XML attributes and elements are
 * processed in wire order by chasing wo pointers. This is what you want for
 * validating signatures on other people's XML documents. */

/* Called by: */
char* zx_ENC_WO_gl_ModifyResponse(struct zx_ctx* c, struct zx_gl_ModifyResponse_s* x, char* p )
{
  struct zx_elem_s* kid;
  struct zx_ns_s* pop_seen = 0;
  ENC_LEN_DEBUG_BASE;
#if 1 /* NORMALMODE */
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

  p = zx_enc_seen(p, pop_seen); 
  p = zx_attr_wo_enc(p, x->id, "id=\"", sizeof("id=\"")-1);
  p = zx_attr_wo_enc(p, x->timeStamp, "timeStamp=\"", sizeof("timeStamp=\"")-1);

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
  ENC_LEN_DEBUG(x, "gl:ModifyResponse", p-enc_base);
  return p;
}

/* FUNC(zx_EASY_ENC_SO_gl_ModifyResponse) */

/* Called by: */
struct zx_str* zx_EASY_ENC_SO_gl_ModifyResponse(struct zx_ctx* c, struct zx_gl_ModifyResponse_s* x )
{
  int len;
  char* buf;
  c->ns_tab = ZX_ALLOC(c, sizeof(zx_ns_tab));
  memcpy(c->ns_tab, zx_ns_tab, sizeof(zx_ns_tab));
  len = zx_LEN_SO_gl_ModifyResponse(c, x );
  buf = ZX_ALLOC(c, len+1);
  return zx_easy_enc_common(c, zx_ENC_SO_gl_ModifyResponse(c, x, buf ), buf, len);
}

/* FUNC(zx_EASY_ENC_WO_gl_ModifyResponse) */

/* Called by: */
struct zx_str* zx_EASY_ENC_WO_gl_ModifyResponse(struct zx_ctx* c, struct zx_gl_ModifyResponse_s* x )
{
  int len;
  char* buf;
  c->ns_tab = ZX_ALLOC(c, sizeof(zx_ns_tab));
  memcpy(c->ns_tab, zx_ns_tab, sizeof(zx_ns_tab));
  len = zx_LEN_WO_gl_ModifyResponse(c, x );
  buf = ZX_ALLOC(c, len+1);
  return zx_easy_enc_common(c, zx_ENC_WO_gl_ModifyResponse(c, x, buf ), buf, len);
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

#define EL_NAME   gl_MultiLineString
#define EL_STRUCT zx_gl_MultiLineString_s
#define EL_NS     gl
#define EL_TAG    MultiLineString

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

/* FUNC(zx_LEN_SO_gl_MultiLineString) */

/* Compute length of an element (and its subelements). The XML attributes
 * and elements are processed in schema order. */

/* Called by: */
int zx_LEN_SO_gl_MultiLineString(struct zx_ctx* c, struct zx_gl_MultiLineString_s* x )
{
  struct zx_ns_s* pop_seen = 0;
  struct zx_elem_s* se MAYBE_UNUSED;
#if 1 /* NORMALMODE */
  /* *** in simple_elem case should output ns prefix from ns node. */
  int len = sizeof("<gl:MultiLineString")-1 + 1 + sizeof("</gl:MultiLineString>")-1;
  if (c->inc_ns_len)
    len += zx_len_inc_ns(c, &pop_seen);
  len += zx_len_xmlns_if_not_seen(c, zx_ns_tab+zx_xmlns_ix_gl, &pop_seen);

  len += zx_attr_so_len(x->gid, sizeof("gid")-1);
  len += zx_attr_so_len(x->srsName, sizeof("srsName")-1);

#else
  /* root node has no begin tag */
  int len = 0;
#endif
  
  {
      struct zx_gl_LineString_s* e;
      for (e = x->LineString; e; e = (struct zx_gl_LineString_s*)e->gg.g.n)
	  len += zx_LEN_SO_gl_LineString(c, e);
  }


  len += zx_len_so_common(c, &x->gg);
  zx_pop_seen(pop_seen);
  ENC_LEN_DEBUG(x, "gl:MultiLineString", len);
  return len;
}

/* FUNC(zx_LEN_WO_gl_MultiLineString) */

/* Compute length of an element (and its subelements). The XML attributes
 * and elements are processed in wire order and no assumptions
 * are made about namespace prefixes. */

/* Called by: */
int zx_LEN_WO_gl_MultiLineString(struct zx_ctx* c, struct zx_gl_MultiLineString_s* x )
{
  struct zx_ns_s* pop_seen = 0;
  struct zx_elem_s* se MAYBE_UNUSED;
#if 1 /* NORMALMODE */
  int len = 1 + sizeof("MultiLineString")-1 + 1 + 2 + sizeof("MultiLineString")-1 + 1;
  
  if (x->gg.g.ns && x->gg.g.ns->prefix_len)
    len += (x->gg.g.ns->prefix_len + 1) * 2;
  if (c->inc_ns_len)
    len += zx_len_inc_ns(c, &pop_seen);
  len += zx_len_xmlns_if_not_seen(c, x->gg.g.ns, &pop_seen);

  len += zx_attr_wo_len(x->gid, sizeof("gid")-1);
  len += zx_attr_wo_len(x->srsName, sizeof("srsName")-1);

#else
  /* root node has no begin tag */
  int len = 0;
#endif
  
  {
      struct zx_gl_LineString_s* e;
      for (e = x->LineString; e; e = (struct zx_gl_LineString_s*)e->gg.g.n)
	  len += zx_LEN_WO_gl_LineString(c, e);
  }


  len += zx_len_wo_common(c, &x->gg); 
  zx_pop_seen(pop_seen);
  ENC_LEN_DEBUG(x, "gl:MultiLineString", len);
  return len;
}

/* FUNC(zx_ENC_SO_gl_MultiLineString) */

/* Render element into string. The XML attributes and elements are
 * processed in schema order. This is what you generally want for
 * rendering new data structure to a string. The wo pointers are not used. */

/* Called by: */
char* zx_ENC_SO_gl_MultiLineString(struct zx_ctx* c, struct zx_gl_MultiLineString_s* x, char* p )
{
  struct zx_elem_s* se MAYBE_UNUSED;
  struct zx_ns_s* pop_seen = 0;
  ENC_LEN_DEBUG_BASE;
#if 1 /* NORMALMODE */
  /* *** in simple_elem case should output ns prefix from ns node. */
  ZX_OUT_TAG(p, "<gl:MultiLineString");
  if (c->inc_ns)
    p = zx_enc_inc_ns(c, p, &pop_seen);
  p = zx_enc_xmlns_if_not_seen(c, p, zx_ns_tab+zx_xmlns_ix_gl, &pop_seen);

  p = zx_attr_so_enc(p, x->gid, " gid=\"", sizeof(" gid=\"")-1);
  p = zx_attr_so_enc(p, x->srsName, " srsName=\"", sizeof(" srsName=\"")-1);

  p = zx_enc_unknown_attrs(p, x->gg.any_attr);
#else
  /* root node has no begin tag */
#endif
  
  {
      struct zx_gl_LineString_s* e;
      for (e = x->LineString; e; e = (struct zx_gl_LineString_s*)e->gg.g.n)
	  p = zx_ENC_SO_gl_LineString(c, e, p);
  }

  p = zx_enc_so_unknown_elems_and_content(c, p, &x->gg);
  
#if 1 /* NORMALMODE */
  ZX_OUT_CLOSE_TAG(p, "</gl:MultiLineString>");
  zx_pop_seen(pop_seen);
#else
  /* root node has no end tag either */
#endif
  ENC_LEN_DEBUG(x, "gl:MultiLineString", p-enc_base);
  return p;
}

/* FUNC(zx_ENC_WO_gl_MultiLineString) */

/* Render element into string. The XML attributes and elements are
 * processed in wire order by chasing wo pointers. This is what you want for
 * validating signatures on other people's XML documents. */

/* Called by: */
char* zx_ENC_WO_gl_MultiLineString(struct zx_ctx* c, struct zx_gl_MultiLineString_s* x, char* p )
{
  struct zx_elem_s* kid;
  struct zx_ns_s* pop_seen = 0;
  ENC_LEN_DEBUG_BASE;
#if 1 /* NORMALMODE */
  char* q;
  char* qq;
  ZX_OUT_CH(p, '<');
  q = p;
  if (x->gg.g.ns && x->gg.g.ns->prefix_len) {
    ZX_OUT_MEM(p, x->gg.g.ns->prefix, x->gg.g.ns->prefix_len);
    ZX_OUT_CH(p, ':');
  }
  ZX_OUT_MEM(p, "MultiLineString", sizeof("MultiLineString")-1);
  qq = p;

  /* *** sort the namespaces */
  if (c->inc_ns)
    zx_add_inc_ns(c, &pop_seen);
  zx_add_xmlns_if_not_seen(c, x->gg.g.ns, &pop_seen);

  p = zx_enc_seen(p, pop_seen); 
  p = zx_attr_wo_enc(p, x->gid, "gid=\"", sizeof("gid=\"")-1);
  p = zx_attr_wo_enc(p, x->srsName, "srsName=\"", sizeof("srsName=\"")-1);

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
  ENC_LEN_DEBUG(x, "gl:MultiLineString", p-enc_base);
  return p;
}

/* FUNC(zx_EASY_ENC_SO_gl_MultiLineString) */

/* Called by: */
struct zx_str* zx_EASY_ENC_SO_gl_MultiLineString(struct zx_ctx* c, struct zx_gl_MultiLineString_s* x )
{
  int len;
  char* buf;
  c->ns_tab = ZX_ALLOC(c, sizeof(zx_ns_tab));
  memcpy(c->ns_tab, zx_ns_tab, sizeof(zx_ns_tab));
  len = zx_LEN_SO_gl_MultiLineString(c, x );
  buf = ZX_ALLOC(c, len+1);
  return zx_easy_enc_common(c, zx_ENC_SO_gl_MultiLineString(c, x, buf ), buf, len);
}

/* FUNC(zx_EASY_ENC_WO_gl_MultiLineString) */

/* Called by: */
struct zx_str* zx_EASY_ENC_WO_gl_MultiLineString(struct zx_ctx* c, struct zx_gl_MultiLineString_s* x )
{
  int len;
  char* buf;
  c->ns_tab = ZX_ALLOC(c, sizeof(zx_ns_tab));
  memcpy(c->ns_tab, zx_ns_tab, sizeof(zx_ns_tab));
  len = zx_LEN_WO_gl_MultiLineString(c, x );
  buf = ZX_ALLOC(c, len+1);
  return zx_easy_enc_common(c, zx_ENC_WO_gl_MultiLineString(c, x, buf ), buf, len);
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

#define EL_NAME   gl_MultiPoint
#define EL_STRUCT zx_gl_MultiPoint_s
#define EL_NS     gl
#define EL_TAG    MultiPoint

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

/* FUNC(zx_LEN_SO_gl_MultiPoint) */

/* Compute length of an element (and its subelements). The XML attributes
 * and elements are processed in schema order. */

/* Called by: */
int zx_LEN_SO_gl_MultiPoint(struct zx_ctx* c, struct zx_gl_MultiPoint_s* x )
{
  struct zx_ns_s* pop_seen = 0;
  struct zx_elem_s* se MAYBE_UNUSED;
#if 1 /* NORMALMODE */
  /* *** in simple_elem case should output ns prefix from ns node. */
  int len = sizeof("<gl:MultiPoint")-1 + 1 + sizeof("</gl:MultiPoint>")-1;
  if (c->inc_ns_len)
    len += zx_len_inc_ns(c, &pop_seen);
  len += zx_len_xmlns_if_not_seen(c, zx_ns_tab+zx_xmlns_ix_gl, &pop_seen);

  len += zx_attr_so_len(x->gid, sizeof("gid")-1);
  len += zx_attr_so_len(x->srsName, sizeof("srsName")-1);

#else
  /* root node has no begin tag */
  int len = 0;
#endif
  
  {
      struct zx_gl_Point_s* e;
      for (e = x->Point; e; e = (struct zx_gl_Point_s*)e->gg.g.n)
	  len += zx_LEN_SO_gl_Point(c, e);
  }


  len += zx_len_so_common(c, &x->gg);
  zx_pop_seen(pop_seen);
  ENC_LEN_DEBUG(x, "gl:MultiPoint", len);
  return len;
}

/* FUNC(zx_LEN_WO_gl_MultiPoint) */

/* Compute length of an element (and its subelements). The XML attributes
 * and elements are processed in wire order and no assumptions
 * are made about namespace prefixes. */

/* Called by: */
int zx_LEN_WO_gl_MultiPoint(struct zx_ctx* c, struct zx_gl_MultiPoint_s* x )
{
  struct zx_ns_s* pop_seen = 0;
  struct zx_elem_s* se MAYBE_UNUSED;
#if 1 /* NORMALMODE */
  int len = 1 + sizeof("MultiPoint")-1 + 1 + 2 + sizeof("MultiPoint")-1 + 1;
  
  if (x->gg.g.ns && x->gg.g.ns->prefix_len)
    len += (x->gg.g.ns->prefix_len + 1) * 2;
  if (c->inc_ns_len)
    len += zx_len_inc_ns(c, &pop_seen);
  len += zx_len_xmlns_if_not_seen(c, x->gg.g.ns, &pop_seen);

  len += zx_attr_wo_len(x->gid, sizeof("gid")-1);
  len += zx_attr_wo_len(x->srsName, sizeof("srsName")-1);

#else
  /* root node has no begin tag */
  int len = 0;
#endif
  
  {
      struct zx_gl_Point_s* e;
      for (e = x->Point; e; e = (struct zx_gl_Point_s*)e->gg.g.n)
	  len += zx_LEN_WO_gl_Point(c, e);
  }


  len += zx_len_wo_common(c, &x->gg); 
  zx_pop_seen(pop_seen);
  ENC_LEN_DEBUG(x, "gl:MultiPoint", len);
  return len;
}

/* FUNC(zx_ENC_SO_gl_MultiPoint) */

/* Render element into string. The XML attributes and elements are
 * processed in schema order. This is what you generally want for
 * rendering new data structure to a string. The wo pointers are not used. */

/* Called by: */
char* zx_ENC_SO_gl_MultiPoint(struct zx_ctx* c, struct zx_gl_MultiPoint_s* x, char* p )
{
  struct zx_elem_s* se MAYBE_UNUSED;
  struct zx_ns_s* pop_seen = 0;
  ENC_LEN_DEBUG_BASE;
#if 1 /* NORMALMODE */
  /* *** in simple_elem case should output ns prefix from ns node. */
  ZX_OUT_TAG(p, "<gl:MultiPoint");
  if (c->inc_ns)
    p = zx_enc_inc_ns(c, p, &pop_seen);
  p = zx_enc_xmlns_if_not_seen(c, p, zx_ns_tab+zx_xmlns_ix_gl, &pop_seen);

  p = zx_attr_so_enc(p, x->gid, " gid=\"", sizeof(" gid=\"")-1);
  p = zx_attr_so_enc(p, x->srsName, " srsName=\"", sizeof(" srsName=\"")-1);

  p = zx_enc_unknown_attrs(p, x->gg.any_attr);
#else
  /* root node has no begin tag */
#endif
  
  {
      struct zx_gl_Point_s* e;
      for (e = x->Point; e; e = (struct zx_gl_Point_s*)e->gg.g.n)
	  p = zx_ENC_SO_gl_Point(c, e, p);
  }

  p = zx_enc_so_unknown_elems_and_content(c, p, &x->gg);
  
#if 1 /* NORMALMODE */
  ZX_OUT_CLOSE_TAG(p, "</gl:MultiPoint>");
  zx_pop_seen(pop_seen);
#else
  /* root node has no end tag either */
#endif
  ENC_LEN_DEBUG(x, "gl:MultiPoint", p-enc_base);
  return p;
}

/* FUNC(zx_ENC_WO_gl_MultiPoint) */

/* Render element into string. The XML attributes and elements are
 * processed in wire order by chasing wo pointers. This is what you want for
 * validating signatures on other people's XML documents. */

/* Called by: */
char* zx_ENC_WO_gl_MultiPoint(struct zx_ctx* c, struct zx_gl_MultiPoint_s* x, char* p )
{
  struct zx_elem_s* kid;
  struct zx_ns_s* pop_seen = 0;
  ENC_LEN_DEBUG_BASE;
#if 1 /* NORMALMODE */
  char* q;
  char* qq;
  ZX_OUT_CH(p, '<');
  q = p;
  if (x->gg.g.ns && x->gg.g.ns->prefix_len) {
    ZX_OUT_MEM(p, x->gg.g.ns->prefix, x->gg.g.ns->prefix_len);
    ZX_OUT_CH(p, ':');
  }
  ZX_OUT_MEM(p, "MultiPoint", sizeof("MultiPoint")-1);
  qq = p;

  /* *** sort the namespaces */
  if (c->inc_ns)
    zx_add_inc_ns(c, &pop_seen);
  zx_add_xmlns_if_not_seen(c, x->gg.g.ns, &pop_seen);

  p = zx_enc_seen(p, pop_seen); 
  p = zx_attr_wo_enc(p, x->gid, "gid=\"", sizeof("gid=\"")-1);
  p = zx_attr_wo_enc(p, x->srsName, "srsName=\"", sizeof("srsName=\"")-1);

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
  ENC_LEN_DEBUG(x, "gl:MultiPoint", p-enc_base);
  return p;
}

/* FUNC(zx_EASY_ENC_SO_gl_MultiPoint) */

/* Called by: */
struct zx_str* zx_EASY_ENC_SO_gl_MultiPoint(struct zx_ctx* c, struct zx_gl_MultiPoint_s* x )
{
  int len;
  char* buf;
  c->ns_tab = ZX_ALLOC(c, sizeof(zx_ns_tab));
  memcpy(c->ns_tab, zx_ns_tab, sizeof(zx_ns_tab));
  len = zx_LEN_SO_gl_MultiPoint(c, x );
  buf = ZX_ALLOC(c, len+1);
  return zx_easy_enc_common(c, zx_ENC_SO_gl_MultiPoint(c, x, buf ), buf, len);
}

/* FUNC(zx_EASY_ENC_WO_gl_MultiPoint) */

/* Called by: */
struct zx_str* zx_EASY_ENC_WO_gl_MultiPoint(struct zx_ctx* c, struct zx_gl_MultiPoint_s* x )
{
  int len;
  char* buf;
  c->ns_tab = ZX_ALLOC(c, sizeof(zx_ns_tab));
  memcpy(c->ns_tab, zx_ns_tab, sizeof(zx_ns_tab));
  len = zx_LEN_WO_gl_MultiPoint(c, x );
  buf = ZX_ALLOC(c, len+1);
  return zx_easy_enc_common(c, zx_ENC_WO_gl_MultiPoint(c, x, buf ), buf, len);
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

#define EL_NAME   gl_MultiPolygon
#define EL_STRUCT zx_gl_MultiPolygon_s
#define EL_NS     gl
#define EL_TAG    MultiPolygon

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

/* FUNC(zx_LEN_SO_gl_MultiPolygon) */

/* Compute length of an element (and its subelements). The XML attributes
 * and elements are processed in schema order. */

/* Called by: */
int zx_LEN_SO_gl_MultiPolygon(struct zx_ctx* c, struct zx_gl_MultiPolygon_s* x )
{
  struct zx_ns_s* pop_seen = 0;
  struct zx_elem_s* se MAYBE_UNUSED;
#if 1 /* NORMALMODE */
  /* *** in simple_elem case should output ns prefix from ns node. */
  int len = sizeof("<gl:MultiPolygon")-1 + 1 + sizeof("</gl:MultiPolygon>")-1;
  if (c->inc_ns_len)
    len += zx_len_inc_ns(c, &pop_seen);
  len += zx_len_xmlns_if_not_seen(c, zx_ns_tab+zx_xmlns_ix_gl, &pop_seen);

  len += zx_attr_so_len(x->gid, sizeof("gid")-1);
  len += zx_attr_so_len(x->srsName, sizeof("srsName")-1);

#else
  /* root node has no begin tag */
  int len = 0;
#endif
  
  {
      struct zx_gl_Polygon_s* e;
      for (e = x->Polygon; e; e = (struct zx_gl_Polygon_s*)e->gg.g.n)
	  len += zx_LEN_SO_gl_Polygon(c, e);
  }
  {
      struct zx_gl_Box_s* e;
      for (e = x->Box; e; e = (struct zx_gl_Box_s*)e->gg.g.n)
	  len += zx_LEN_SO_gl_Box(c, e);
  }
  {
      struct zx_gl_CircularArea_s* e;
      for (e = x->CircularArea; e; e = (struct zx_gl_CircularArea_s*)e->gg.g.n)
	  len += zx_LEN_SO_gl_CircularArea(c, e);
  }
  {
      struct zx_gl_CircularArcArea_s* e;
      for (e = x->CircularArcArea; e; e = (struct zx_gl_CircularArcArea_s*)e->gg.g.n)
	  len += zx_LEN_SO_gl_CircularArcArea(c, e);
  }
  {
      struct zx_gl_EllipticalArea_s* e;
      for (e = x->EllipticalArea; e; e = (struct zx_gl_EllipticalArea_s*)e->gg.g.n)
	  len += zx_LEN_SO_gl_EllipticalArea(c, e);
  }


  len += zx_len_so_common(c, &x->gg);
  zx_pop_seen(pop_seen);
  ENC_LEN_DEBUG(x, "gl:MultiPolygon", len);
  return len;
}

/* FUNC(zx_LEN_WO_gl_MultiPolygon) */

/* Compute length of an element (and its subelements). The XML attributes
 * and elements are processed in wire order and no assumptions
 * are made about namespace prefixes. */

/* Called by: */
int zx_LEN_WO_gl_MultiPolygon(struct zx_ctx* c, struct zx_gl_MultiPolygon_s* x )
{
  struct zx_ns_s* pop_seen = 0;
  struct zx_elem_s* se MAYBE_UNUSED;
#if 1 /* NORMALMODE */
  int len = 1 + sizeof("MultiPolygon")-1 + 1 + 2 + sizeof("MultiPolygon")-1 + 1;
  
  if (x->gg.g.ns && x->gg.g.ns->prefix_len)
    len += (x->gg.g.ns->prefix_len + 1) * 2;
  if (c->inc_ns_len)
    len += zx_len_inc_ns(c, &pop_seen);
  len += zx_len_xmlns_if_not_seen(c, x->gg.g.ns, &pop_seen);

  len += zx_attr_wo_len(x->gid, sizeof("gid")-1);
  len += zx_attr_wo_len(x->srsName, sizeof("srsName")-1);

#else
  /* root node has no begin tag */
  int len = 0;
#endif
  
  {
      struct zx_gl_Polygon_s* e;
      for (e = x->Polygon; e; e = (struct zx_gl_Polygon_s*)e->gg.g.n)
	  len += zx_LEN_WO_gl_Polygon(c, e);
  }
  {
      struct zx_gl_Box_s* e;
      for (e = x->Box; e; e = (struct zx_gl_Box_s*)e->gg.g.n)
	  len += zx_LEN_WO_gl_Box(c, e);
  }
  {
      struct zx_gl_CircularArea_s* e;
      for (e = x->CircularArea; e; e = (struct zx_gl_CircularArea_s*)e->gg.g.n)
	  len += zx_LEN_WO_gl_CircularArea(c, e);
  }
  {
      struct zx_gl_CircularArcArea_s* e;
      for (e = x->CircularArcArea; e; e = (struct zx_gl_CircularArcArea_s*)e->gg.g.n)
	  len += zx_LEN_WO_gl_CircularArcArea(c, e);
  }
  {
      struct zx_gl_EllipticalArea_s* e;
      for (e = x->EllipticalArea; e; e = (struct zx_gl_EllipticalArea_s*)e->gg.g.n)
	  len += zx_LEN_WO_gl_EllipticalArea(c, e);
  }


  len += zx_len_wo_common(c, &x->gg); 
  zx_pop_seen(pop_seen);
  ENC_LEN_DEBUG(x, "gl:MultiPolygon", len);
  return len;
}

/* FUNC(zx_ENC_SO_gl_MultiPolygon) */

/* Render element into string. The XML attributes and elements are
 * processed in schema order. This is what you generally want for
 * rendering new data structure to a string. The wo pointers are not used. */

/* Called by: */
char* zx_ENC_SO_gl_MultiPolygon(struct zx_ctx* c, struct zx_gl_MultiPolygon_s* x, char* p )
{
  struct zx_elem_s* se MAYBE_UNUSED;
  struct zx_ns_s* pop_seen = 0;
  ENC_LEN_DEBUG_BASE;
#if 1 /* NORMALMODE */
  /* *** in simple_elem case should output ns prefix from ns node. */
  ZX_OUT_TAG(p, "<gl:MultiPolygon");
  if (c->inc_ns)
    p = zx_enc_inc_ns(c, p, &pop_seen);
  p = zx_enc_xmlns_if_not_seen(c, p, zx_ns_tab+zx_xmlns_ix_gl, &pop_seen);

  p = zx_attr_so_enc(p, x->gid, " gid=\"", sizeof(" gid=\"")-1);
  p = zx_attr_so_enc(p, x->srsName, " srsName=\"", sizeof(" srsName=\"")-1);

  p = zx_enc_unknown_attrs(p, x->gg.any_attr);
#else
  /* root node has no begin tag */
#endif
  
  {
      struct zx_gl_Polygon_s* e;
      for (e = x->Polygon; e; e = (struct zx_gl_Polygon_s*)e->gg.g.n)
	  p = zx_ENC_SO_gl_Polygon(c, e, p);
  }
  {
      struct zx_gl_Box_s* e;
      for (e = x->Box; e; e = (struct zx_gl_Box_s*)e->gg.g.n)
	  p = zx_ENC_SO_gl_Box(c, e, p);
  }
  {
      struct zx_gl_CircularArea_s* e;
      for (e = x->CircularArea; e; e = (struct zx_gl_CircularArea_s*)e->gg.g.n)
	  p = zx_ENC_SO_gl_CircularArea(c, e, p);
  }
  {
      struct zx_gl_CircularArcArea_s* e;
      for (e = x->CircularArcArea; e; e = (struct zx_gl_CircularArcArea_s*)e->gg.g.n)
	  p = zx_ENC_SO_gl_CircularArcArea(c, e, p);
  }
  {
      struct zx_gl_EllipticalArea_s* e;
      for (e = x->EllipticalArea; e; e = (struct zx_gl_EllipticalArea_s*)e->gg.g.n)
	  p = zx_ENC_SO_gl_EllipticalArea(c, e, p);
  }

  p = zx_enc_so_unknown_elems_and_content(c, p, &x->gg);
  
#if 1 /* NORMALMODE */
  ZX_OUT_CLOSE_TAG(p, "</gl:MultiPolygon>");
  zx_pop_seen(pop_seen);
#else
  /* root node has no end tag either */
#endif
  ENC_LEN_DEBUG(x, "gl:MultiPolygon", p-enc_base);
  return p;
}

/* FUNC(zx_ENC_WO_gl_MultiPolygon) */

/* Render element into string. The XML attributes and elements are
 * processed in wire order by chasing wo pointers. This is what you want for
 * validating signatures on other people's XML documents. */

/* Called by: */
char* zx_ENC_WO_gl_MultiPolygon(struct zx_ctx* c, struct zx_gl_MultiPolygon_s* x, char* p )
{
  struct zx_elem_s* kid;
  struct zx_ns_s* pop_seen = 0;
  ENC_LEN_DEBUG_BASE;
#if 1 /* NORMALMODE */
  char* q;
  char* qq;
  ZX_OUT_CH(p, '<');
  q = p;
  if (x->gg.g.ns && x->gg.g.ns->prefix_len) {
    ZX_OUT_MEM(p, x->gg.g.ns->prefix, x->gg.g.ns->prefix_len);
    ZX_OUT_CH(p, ':');
  }
  ZX_OUT_MEM(p, "MultiPolygon", sizeof("MultiPolygon")-1);
  qq = p;

  /* *** sort the namespaces */
  if (c->inc_ns)
    zx_add_inc_ns(c, &pop_seen);
  zx_add_xmlns_if_not_seen(c, x->gg.g.ns, &pop_seen);

  p = zx_enc_seen(p, pop_seen); 
  p = zx_attr_wo_enc(p, x->gid, "gid=\"", sizeof("gid=\"")-1);
  p = zx_attr_wo_enc(p, x->srsName, "srsName=\"", sizeof("srsName=\"")-1);

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
  ENC_LEN_DEBUG(x, "gl:MultiPolygon", p-enc_base);
  return p;
}

/* FUNC(zx_EASY_ENC_SO_gl_MultiPolygon) */

/* Called by: */
struct zx_str* zx_EASY_ENC_SO_gl_MultiPolygon(struct zx_ctx* c, struct zx_gl_MultiPolygon_s* x )
{
  int len;
  char* buf;
  c->ns_tab = ZX_ALLOC(c, sizeof(zx_ns_tab));
  memcpy(c->ns_tab, zx_ns_tab, sizeof(zx_ns_tab));
  len = zx_LEN_SO_gl_MultiPolygon(c, x );
  buf = ZX_ALLOC(c, len+1);
  return zx_easy_enc_common(c, zx_ENC_SO_gl_MultiPolygon(c, x, buf ), buf, len);
}

/* FUNC(zx_EASY_ENC_WO_gl_MultiPolygon) */

/* Called by: */
struct zx_str* zx_EASY_ENC_WO_gl_MultiPolygon(struct zx_ctx* c, struct zx_gl_MultiPolygon_s* x )
{
  int len;
  char* buf;
  c->ns_tab = ZX_ALLOC(c, sizeof(zx_ns_tab));
  memcpy(c->ns_tab, zx_ns_tab, sizeof(zx_ns_tab));
  len = zx_LEN_WO_gl_MultiPolygon(c, x );
  buf = ZX_ALLOC(c, len+1);
  return zx_easy_enc_common(c, zx_ENC_WO_gl_MultiPolygon(c, x, buf ), buf, len);
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

#define EL_NAME   gl_NewData
#define EL_STRUCT zx_gl_NewData_s
#define EL_NS     gl
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

/* FUNC(zx_LEN_SO_gl_NewData) */

/* Compute length of an element (and its subelements). The XML attributes
 * and elements are processed in schema order. */

/* Called by: */
int zx_LEN_SO_gl_NewData(struct zx_ctx* c, struct zx_gl_NewData_s* x )
{
  struct zx_ns_s* pop_seen = 0;
  struct zx_elem_s* se MAYBE_UNUSED;
#if 1 /* NORMALMODE */
  /* *** in simple_elem case should output ns prefix from ns node. */
  int len = sizeof("<gl:NewData")-1 + 1 + sizeof("</gl:NewData>")-1;
  if (c->inc_ns_len)
    len += zx_len_inc_ns(c, &pop_seen);
  len += zx_len_xmlns_if_not_seen(c, zx_ns_tab+zx_xmlns_ix_gl, &pop_seen);


#else
  /* root node has no begin tag */
  int len = 0;
#endif
  


  len += zx_len_so_common(c, &x->gg);
  zx_pop_seen(pop_seen);
  ENC_LEN_DEBUG(x, "gl:NewData", len);
  return len;
}

/* FUNC(zx_LEN_WO_gl_NewData) */

/* Compute length of an element (and its subelements). The XML attributes
 * and elements are processed in wire order and no assumptions
 * are made about namespace prefixes. */

/* Called by: */
int zx_LEN_WO_gl_NewData(struct zx_ctx* c, struct zx_gl_NewData_s* x )
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
  


  len += zx_len_wo_common(c, &x->gg); 
  zx_pop_seen(pop_seen);
  ENC_LEN_DEBUG(x, "gl:NewData", len);
  return len;
}

/* FUNC(zx_ENC_SO_gl_NewData) */

/* Render element into string. The XML attributes and elements are
 * processed in schema order. This is what you generally want for
 * rendering new data structure to a string. The wo pointers are not used. */

/* Called by: */
char* zx_ENC_SO_gl_NewData(struct zx_ctx* c, struct zx_gl_NewData_s* x, char* p )
{
  struct zx_elem_s* se MAYBE_UNUSED;
  struct zx_ns_s* pop_seen = 0;
  ENC_LEN_DEBUG_BASE;
#if 1 /* NORMALMODE */
  /* *** in simple_elem case should output ns prefix from ns node. */
  ZX_OUT_TAG(p, "<gl:NewData");
  if (c->inc_ns)
    p = zx_enc_inc_ns(c, p, &pop_seen);
  p = zx_enc_xmlns_if_not_seen(c, p, zx_ns_tab+zx_xmlns_ix_gl, &pop_seen);


  p = zx_enc_unknown_attrs(p, x->gg.any_attr);
#else
  /* root node has no begin tag */
#endif
  

  p = zx_enc_so_unknown_elems_and_content(c, p, &x->gg);
  
#if 1 /* NORMALMODE */
  ZX_OUT_CLOSE_TAG(p, "</gl:NewData>");
  zx_pop_seen(pop_seen);
#else
  /* root node has no end tag either */
#endif
  ENC_LEN_DEBUG(x, "gl:NewData", p-enc_base);
  return p;
}

/* FUNC(zx_ENC_WO_gl_NewData) */

/* Render element into string. The XML attributes and elements are
 * processed in wire order by chasing wo pointers. This is what you want for
 * validating signatures on other people's XML documents. */

/* Called by: */
char* zx_ENC_WO_gl_NewData(struct zx_ctx* c, struct zx_gl_NewData_s* x, char* p )
{
  struct zx_elem_s* kid;
  struct zx_ns_s* pop_seen = 0;
  ENC_LEN_DEBUG_BASE;
#if 1 /* NORMALMODE */
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
  ENC_LEN_DEBUG(x, "gl:NewData", p-enc_base);
  return p;
}

/* FUNC(zx_EASY_ENC_SO_gl_NewData) */

/* Called by: */
struct zx_str* zx_EASY_ENC_SO_gl_NewData(struct zx_ctx* c, struct zx_gl_NewData_s* x )
{
  int len;
  char* buf;
  c->ns_tab = ZX_ALLOC(c, sizeof(zx_ns_tab));
  memcpy(c->ns_tab, zx_ns_tab, sizeof(zx_ns_tab));
  len = zx_LEN_SO_gl_NewData(c, x );
  buf = ZX_ALLOC(c, len+1);
  return zx_easy_enc_common(c, zx_ENC_SO_gl_NewData(c, x, buf ), buf, len);
}

/* FUNC(zx_EASY_ENC_WO_gl_NewData) */

/* Called by: */
struct zx_str* zx_EASY_ENC_WO_gl_NewData(struct zx_ctx* c, struct zx_gl_NewData_s* x )
{
  int len;
  char* buf;
  c->ns_tab = ZX_ALLOC(c, sizeof(zx_ns_tab));
  memcpy(c->ns_tab, zx_ns_tab, sizeof(zx_ns_tab));
  len = zx_LEN_WO_gl_NewData(c, x );
  buf = ZX_ALLOC(c, len+1);
  return zx_easy_enc_common(c, zx_ENC_WO_gl_NewData(c, x, buf ), buf, len);
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

#define EL_NAME   gl_Notification
#define EL_STRUCT zx_gl_Notification_s
#define EL_NS     gl
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

/* FUNC(zx_LEN_SO_gl_Notification) */

/* Compute length of an element (and its subelements). The XML attributes
 * and elements are processed in schema order. */

/* Called by: */
int zx_LEN_SO_gl_Notification(struct zx_ctx* c, struct zx_gl_Notification_s* x )
{
  struct zx_ns_s* pop_seen = 0;
  struct zx_elem_s* se MAYBE_UNUSED;
#if 1 /* NORMALMODE */
  /* *** in simple_elem case should output ns prefix from ns node. */
  int len = sizeof("<gl:Notification")-1 + 1 + sizeof("</gl:Notification>")-1;
  if (c->inc_ns_len)
    len += zx_len_inc_ns(c, &pop_seen);
  len += zx_len_xmlns_if_not_seen(c, zx_ns_tab+zx_xmlns_ix_gl, &pop_seen);

  len += zx_attr_so_len(x->endReason, sizeof("endReason")-1);
  len += zx_attr_so_len(x->expires, sizeof("expires")-1);
  len += zx_attr_so_len(x->id, sizeof("id")-1);
  len += zx_attr_so_len(x->subscriptionID, sizeof("subscriptionID")-1);

#else
  /* root node has no begin tag */
  int len = 0;
#endif
  
  {
      struct zx_gl_ItemData_s* e;
      for (e = x->ItemData; e; e = (struct zx_gl_ItemData_s*)e->gg.g.n)
	  len += zx_LEN_SO_gl_ItemData(c, e);
  }


  len += zx_len_so_common(c, &x->gg);
  zx_pop_seen(pop_seen);
  ENC_LEN_DEBUG(x, "gl:Notification", len);
  return len;
}

/* FUNC(zx_LEN_WO_gl_Notification) */

/* Compute length of an element (and its subelements). The XML attributes
 * and elements are processed in wire order and no assumptions
 * are made about namespace prefixes. */

/* Called by: */
int zx_LEN_WO_gl_Notification(struct zx_ctx* c, struct zx_gl_Notification_s* x )
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
      struct zx_gl_ItemData_s* e;
      for (e = x->ItemData; e; e = (struct zx_gl_ItemData_s*)e->gg.g.n)
	  len += zx_LEN_WO_gl_ItemData(c, e);
  }


  len += zx_len_wo_common(c, &x->gg); 
  zx_pop_seen(pop_seen);
  ENC_LEN_DEBUG(x, "gl:Notification", len);
  return len;
}

/* FUNC(zx_ENC_SO_gl_Notification) */

/* Render element into string. The XML attributes and elements are
 * processed in schema order. This is what you generally want for
 * rendering new data structure to a string. The wo pointers are not used. */

/* Called by: */
char* zx_ENC_SO_gl_Notification(struct zx_ctx* c, struct zx_gl_Notification_s* x, char* p )
{
  struct zx_elem_s* se MAYBE_UNUSED;
  struct zx_ns_s* pop_seen = 0;
  ENC_LEN_DEBUG_BASE;
#if 1 /* NORMALMODE */
  /* *** in simple_elem case should output ns prefix from ns node. */
  ZX_OUT_TAG(p, "<gl:Notification");
  if (c->inc_ns)
    p = zx_enc_inc_ns(c, p, &pop_seen);
  p = zx_enc_xmlns_if_not_seen(c, p, zx_ns_tab+zx_xmlns_ix_gl, &pop_seen);

  p = zx_attr_so_enc(p, x->endReason, " endReason=\"", sizeof(" endReason=\"")-1);
  p = zx_attr_so_enc(p, x->expires, " expires=\"", sizeof(" expires=\"")-1);
  p = zx_attr_so_enc(p, x->id, " id=\"", sizeof(" id=\"")-1);
  p = zx_attr_so_enc(p, x->subscriptionID, " subscriptionID=\"", sizeof(" subscriptionID=\"")-1);

  p = zx_enc_unknown_attrs(p, x->gg.any_attr);
#else
  /* root node has no begin tag */
#endif
  
  {
      struct zx_gl_ItemData_s* e;
      for (e = x->ItemData; e; e = (struct zx_gl_ItemData_s*)e->gg.g.n)
	  p = zx_ENC_SO_gl_ItemData(c, e, p);
  }

  p = zx_enc_so_unknown_elems_and_content(c, p, &x->gg);
  
#if 1 /* NORMALMODE */
  ZX_OUT_CLOSE_TAG(p, "</gl:Notification>");
  zx_pop_seen(pop_seen);
#else
  /* root node has no end tag either */
#endif
  ENC_LEN_DEBUG(x, "gl:Notification", p-enc_base);
  return p;
}

/* FUNC(zx_ENC_WO_gl_Notification) */

/* Render element into string. The XML attributes and elements are
 * processed in wire order by chasing wo pointers. This is what you want for
 * validating signatures on other people's XML documents. */

/* Called by: */
char* zx_ENC_WO_gl_Notification(struct zx_ctx* c, struct zx_gl_Notification_s* x, char* p )
{
  struct zx_elem_s* kid;
  struct zx_ns_s* pop_seen = 0;
  ENC_LEN_DEBUG_BASE;
#if 1 /* NORMALMODE */
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
  ENC_LEN_DEBUG(x, "gl:Notification", p-enc_base);
  return p;
}

/* FUNC(zx_EASY_ENC_SO_gl_Notification) */

/* Called by: */
struct zx_str* zx_EASY_ENC_SO_gl_Notification(struct zx_ctx* c, struct zx_gl_Notification_s* x )
{
  int len;
  char* buf;
  c->ns_tab = ZX_ALLOC(c, sizeof(zx_ns_tab));
  memcpy(c->ns_tab, zx_ns_tab, sizeof(zx_ns_tab));
  len = zx_LEN_SO_gl_Notification(c, x );
  buf = ZX_ALLOC(c, len+1);
  return zx_easy_enc_common(c, zx_ENC_SO_gl_Notification(c, x, buf ), buf, len);
}

/* FUNC(zx_EASY_ENC_WO_gl_Notification) */

/* Called by: */
struct zx_str* zx_EASY_ENC_WO_gl_Notification(struct zx_ctx* c, struct zx_gl_Notification_s* x )
{
  int len;
  char* buf;
  c->ns_tab = ZX_ALLOC(c, sizeof(zx_ns_tab));
  memcpy(c->ns_tab, zx_ns_tab, sizeof(zx_ns_tab));
  len = zx_LEN_WO_gl_Notification(c, x );
  buf = ZX_ALLOC(c, len+1);
  return zx_easy_enc_common(c, zx_ENC_WO_gl_Notification(c, x, buf ), buf, len);
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

#define EL_NAME   gl_Notify
#define EL_STRUCT zx_gl_Notify_s
#define EL_NS     gl
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

/* FUNC(zx_LEN_SO_gl_Notify) */

/* Compute length of an element (and its subelements). The XML attributes
 * and elements are processed in schema order. */

/* Called by: */
int zx_LEN_SO_gl_Notify(struct zx_ctx* c, struct zx_gl_Notify_s* x )
{
  struct zx_ns_s* pop_seen = 0;
  struct zx_elem_s* se MAYBE_UNUSED;
#if 1 /* NORMALMODE */
  /* *** in simple_elem case should output ns prefix from ns node. */
  int len = sizeof("<gl:Notify")-1 + 1 + sizeof("</gl:Notify>")-1;
  if (c->inc_ns_len)
    len += zx_len_inc_ns(c, &pop_seen);
  len += zx_len_xmlns_if_not_seen(c, zx_ns_tab+zx_xmlns_ix_gl, &pop_seen);

  len += zx_attr_so_len(x->id, sizeof("id")-1);
  len += zx_attr_so_len(x->timeStamp, sizeof("timeStamp")-1);

#else
  /* root node has no begin tag */
  int len = 0;
#endif
  
  {
      struct zx_gl_Notification_s* e;
      for (e = x->Notification; e; e = (struct zx_gl_Notification_s*)e->gg.g.n)
	  len += zx_LEN_SO_gl_Notification(c, e);
  }
  {
      struct zx_gl_Extension_s* e;
      for (e = x->Extension; e; e = (struct zx_gl_Extension_s*)e->gg.g.n)
	  len += zx_LEN_SO_gl_Extension(c, e);
  }


  len += zx_len_so_common(c, &x->gg);
  zx_pop_seen(pop_seen);
  ENC_LEN_DEBUG(x, "gl:Notify", len);
  return len;
}

/* FUNC(zx_LEN_WO_gl_Notify) */

/* Compute length of an element (and its subelements). The XML attributes
 * and elements are processed in wire order and no assumptions
 * are made about namespace prefixes. */

/* Called by: */
int zx_LEN_WO_gl_Notify(struct zx_ctx* c, struct zx_gl_Notify_s* x )
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

  len += zx_attr_wo_len(x->id, sizeof("id")-1);
  len += zx_attr_wo_len(x->timeStamp, sizeof("timeStamp")-1);

#else
  /* root node has no begin tag */
  int len = 0;
#endif
  
  {
      struct zx_gl_Notification_s* e;
      for (e = x->Notification; e; e = (struct zx_gl_Notification_s*)e->gg.g.n)
	  len += zx_LEN_WO_gl_Notification(c, e);
  }
  {
      struct zx_gl_Extension_s* e;
      for (e = x->Extension; e; e = (struct zx_gl_Extension_s*)e->gg.g.n)
	  len += zx_LEN_WO_gl_Extension(c, e);
  }


  len += zx_len_wo_common(c, &x->gg); 
  zx_pop_seen(pop_seen);
  ENC_LEN_DEBUG(x, "gl:Notify", len);
  return len;
}

/* FUNC(zx_ENC_SO_gl_Notify) */

/* Render element into string. The XML attributes and elements are
 * processed in schema order. This is what you generally want for
 * rendering new data structure to a string. The wo pointers are not used. */

/* Called by: */
char* zx_ENC_SO_gl_Notify(struct zx_ctx* c, struct zx_gl_Notify_s* x, char* p )
{
  struct zx_elem_s* se MAYBE_UNUSED;
  struct zx_ns_s* pop_seen = 0;
  ENC_LEN_DEBUG_BASE;
#if 1 /* NORMALMODE */
  /* *** in simple_elem case should output ns prefix from ns node. */
  ZX_OUT_TAG(p, "<gl:Notify");
  if (c->inc_ns)
    p = zx_enc_inc_ns(c, p, &pop_seen);
  p = zx_enc_xmlns_if_not_seen(c, p, zx_ns_tab+zx_xmlns_ix_gl, &pop_seen);

  p = zx_attr_so_enc(p, x->id, " id=\"", sizeof(" id=\"")-1);
  p = zx_attr_so_enc(p, x->timeStamp, " timeStamp=\"", sizeof(" timeStamp=\"")-1);

  p = zx_enc_unknown_attrs(p, x->gg.any_attr);
#else
  /* root node has no begin tag */
#endif
  
  {
      struct zx_gl_Notification_s* e;
      for (e = x->Notification; e; e = (struct zx_gl_Notification_s*)e->gg.g.n)
	  p = zx_ENC_SO_gl_Notification(c, e, p);
  }
  {
      struct zx_gl_Extension_s* e;
      for (e = x->Extension; e; e = (struct zx_gl_Extension_s*)e->gg.g.n)
	  p = zx_ENC_SO_gl_Extension(c, e, p);
  }

  p = zx_enc_so_unknown_elems_and_content(c, p, &x->gg);
  
#if 1 /* NORMALMODE */
  ZX_OUT_CLOSE_TAG(p, "</gl:Notify>");
  zx_pop_seen(pop_seen);
#else
  /* root node has no end tag either */
#endif
  ENC_LEN_DEBUG(x, "gl:Notify", p-enc_base);
  return p;
}

/* FUNC(zx_ENC_WO_gl_Notify) */

/* Render element into string. The XML attributes and elements are
 * processed in wire order by chasing wo pointers. This is what you want for
 * validating signatures on other people's XML documents. */

/* Called by: */
char* zx_ENC_WO_gl_Notify(struct zx_ctx* c, struct zx_gl_Notify_s* x, char* p )
{
  struct zx_elem_s* kid;
  struct zx_ns_s* pop_seen = 0;
  ENC_LEN_DEBUG_BASE;
#if 1 /* NORMALMODE */
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

  p = zx_enc_seen(p, pop_seen); 
  p = zx_attr_wo_enc(p, x->id, "id=\"", sizeof("id=\"")-1);
  p = zx_attr_wo_enc(p, x->timeStamp, "timeStamp=\"", sizeof("timeStamp=\"")-1);

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
  ENC_LEN_DEBUG(x, "gl:Notify", p-enc_base);
  return p;
}

/* FUNC(zx_EASY_ENC_SO_gl_Notify) */

/* Called by: */
struct zx_str* zx_EASY_ENC_SO_gl_Notify(struct zx_ctx* c, struct zx_gl_Notify_s* x )
{
  int len;
  char* buf;
  c->ns_tab = ZX_ALLOC(c, sizeof(zx_ns_tab));
  memcpy(c->ns_tab, zx_ns_tab, sizeof(zx_ns_tab));
  len = zx_LEN_SO_gl_Notify(c, x );
  buf = ZX_ALLOC(c, len+1);
  return zx_easy_enc_common(c, zx_ENC_SO_gl_Notify(c, x, buf ), buf, len);
}

/* FUNC(zx_EASY_ENC_WO_gl_Notify) */

/* Called by: */
struct zx_str* zx_EASY_ENC_WO_gl_Notify(struct zx_ctx* c, struct zx_gl_Notify_s* x )
{
  int len;
  char* buf;
  c->ns_tab = ZX_ALLOC(c, sizeof(zx_ns_tab));
  memcpy(c->ns_tab, zx_ns_tab, sizeof(zx_ns_tab));
  len = zx_LEN_WO_gl_Notify(c, x );
  buf = ZX_ALLOC(c, len+1);
  return zx_easy_enc_common(c, zx_ENC_WO_gl_Notify(c, x, buf ), buf, len);
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

#define EL_NAME   gl_NotifyAdminTo
#define EL_STRUCT zx_gl_NotifyAdminTo_s
#define EL_NS     gl
#define EL_TAG    NotifyAdminTo

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

/* FUNC(zx_LEN_SO_gl_NotifyAdminTo) */

/* Compute length of an element (and its subelements). The XML attributes
 * and elements are processed in schema order. */

/* Called by: */
int zx_LEN_SO_gl_NotifyAdminTo(struct zx_ctx* c, struct zx_gl_NotifyAdminTo_s* x )
{
  struct zx_ns_s* pop_seen = 0;
  struct zx_elem_s* se MAYBE_UNUSED;
#if 1 /* NORMALMODE */
  /* *** in simple_elem case should output ns prefix from ns node. */
  int len = sizeof("<gl:NotifyAdminTo")-1 + 1 + sizeof("</gl:NotifyAdminTo>")-1;
  if (c->inc_ns_len)
    len += zx_len_inc_ns(c, &pop_seen);
  len += zx_len_xmlns_if_not_seen(c, zx_ns_tab+zx_xmlns_ix_gl, &pop_seen);

  len += zx_attr_so_len(x->id, sizeof("id")-1);

#else
  /* root node has no begin tag */
  int len = 0;
#endif
  
  for (se = x->SecurityMechID; se; se = (struct zx_elem_s*)se->g.n)
    len += zx_LEN_SO_simple_elem(c,se, sizeof("gl:SecurityMechID")-1, zx_ns_tab+zx_xmlns_ix_gl);
  {
      struct zx_gl_Credential_s* e;
      for (e = x->Credential; e; e = (struct zx_gl_Credential_s*)e->gg.g.n)
	  len += zx_LEN_SO_gl_Credential(c, e);
  }
  for (se = x->Endpoint; se; se = (struct zx_elem_s*)se->g.n)
    len += zx_LEN_SO_simple_elem(c,se, sizeof("gl:Endpoint")-1, zx_ns_tab+zx_xmlns_ix_gl);


  len += zx_len_so_common(c, &x->gg);
  zx_pop_seen(pop_seen);
  ENC_LEN_DEBUG(x, "gl:NotifyAdminTo", len);
  return len;
}

/* FUNC(zx_LEN_WO_gl_NotifyAdminTo) */

/* Compute length of an element (and its subelements). The XML attributes
 * and elements are processed in wire order and no assumptions
 * are made about namespace prefixes. */

/* Called by: */
int zx_LEN_WO_gl_NotifyAdminTo(struct zx_ctx* c, struct zx_gl_NotifyAdminTo_s* x )
{
  struct zx_ns_s* pop_seen = 0;
  struct zx_elem_s* se MAYBE_UNUSED;
#if 1 /* NORMALMODE */
  int len = 1 + sizeof("NotifyAdminTo")-1 + 1 + 2 + sizeof("NotifyAdminTo")-1 + 1;
  
  if (x->gg.g.ns && x->gg.g.ns->prefix_len)
    len += (x->gg.g.ns->prefix_len + 1) * 2;
  if (c->inc_ns_len)
    len += zx_len_inc_ns(c, &pop_seen);
  len += zx_len_xmlns_if_not_seen(c, x->gg.g.ns, &pop_seen);

  len += zx_attr_wo_len(x->id, sizeof("id")-1);

#else
  /* root node has no begin tag */
  int len = 0;
#endif
  
  for (se = x->SecurityMechID; se; se = (struct zx_elem_s*)se->g.n)
    len += zx_LEN_WO_simple_elem(c, se, sizeof("SecurityMechID")-1);
  {
      struct zx_gl_Credential_s* e;
      for (e = x->Credential; e; e = (struct zx_gl_Credential_s*)e->gg.g.n)
	  len += zx_LEN_WO_gl_Credential(c, e);
  }
  for (se = x->Endpoint; se; se = (struct zx_elem_s*)se->g.n)
    len += zx_LEN_WO_simple_elem(c, se, sizeof("Endpoint")-1);


  len += zx_len_wo_common(c, &x->gg); 
  zx_pop_seen(pop_seen);
  ENC_LEN_DEBUG(x, "gl:NotifyAdminTo", len);
  return len;
}

/* FUNC(zx_ENC_SO_gl_NotifyAdminTo) */

/* Render element into string. The XML attributes and elements are
 * processed in schema order. This is what you generally want for
 * rendering new data structure to a string. The wo pointers are not used. */

/* Called by: */
char* zx_ENC_SO_gl_NotifyAdminTo(struct zx_ctx* c, struct zx_gl_NotifyAdminTo_s* x, char* p )
{
  struct zx_elem_s* se MAYBE_UNUSED;
  struct zx_ns_s* pop_seen = 0;
  ENC_LEN_DEBUG_BASE;
#if 1 /* NORMALMODE */
  /* *** in simple_elem case should output ns prefix from ns node. */
  ZX_OUT_TAG(p, "<gl:NotifyAdminTo");
  if (c->inc_ns)
    p = zx_enc_inc_ns(c, p, &pop_seen);
  p = zx_enc_xmlns_if_not_seen(c, p, zx_ns_tab+zx_xmlns_ix_gl, &pop_seen);

  p = zx_attr_so_enc(p, x->id, " id=\"", sizeof(" id=\"")-1);

  p = zx_enc_unknown_attrs(p, x->gg.any_attr);
#else
  /* root node has no begin tag */
#endif
  
  for (se = x->SecurityMechID; se; se = (struct zx_elem_s*)se->g.n)
    p = zx_ENC_SO_simple_elem(c, se, p, "gl:SecurityMechID", sizeof("gl:SecurityMechID")-1, zx_ns_tab+zx_xmlns_ix_gl);
  {
      struct zx_gl_Credential_s* e;
      for (e = x->Credential; e; e = (struct zx_gl_Credential_s*)e->gg.g.n)
	  p = zx_ENC_SO_gl_Credential(c, e, p);
  }
  for (se = x->Endpoint; se; se = (struct zx_elem_s*)se->g.n)
    p = zx_ENC_SO_simple_elem(c, se, p, "gl:Endpoint", sizeof("gl:Endpoint")-1, zx_ns_tab+zx_xmlns_ix_gl);

  p = zx_enc_so_unknown_elems_and_content(c, p, &x->gg);
  
#if 1 /* NORMALMODE */
  ZX_OUT_CLOSE_TAG(p, "</gl:NotifyAdminTo>");
  zx_pop_seen(pop_seen);
#else
  /* root node has no end tag either */
#endif
  ENC_LEN_DEBUG(x, "gl:NotifyAdminTo", p-enc_base);
  return p;
}

/* FUNC(zx_ENC_WO_gl_NotifyAdminTo) */

/* Render element into string. The XML attributes and elements are
 * processed in wire order by chasing wo pointers. This is what you want for
 * validating signatures on other people's XML documents. */

/* Called by: */
char* zx_ENC_WO_gl_NotifyAdminTo(struct zx_ctx* c, struct zx_gl_NotifyAdminTo_s* x, char* p )
{
  struct zx_elem_s* kid;
  struct zx_ns_s* pop_seen = 0;
  ENC_LEN_DEBUG_BASE;
#if 1 /* NORMALMODE */
  char* q;
  char* qq;
  ZX_OUT_CH(p, '<');
  q = p;
  if (x->gg.g.ns && x->gg.g.ns->prefix_len) {
    ZX_OUT_MEM(p, x->gg.g.ns->prefix, x->gg.g.ns->prefix_len);
    ZX_OUT_CH(p, ':');
  }
  ZX_OUT_MEM(p, "NotifyAdminTo", sizeof("NotifyAdminTo")-1);
  qq = p;

  /* *** sort the namespaces */
  if (c->inc_ns)
    zx_add_inc_ns(c, &pop_seen);
  zx_add_xmlns_if_not_seen(c, x->gg.g.ns, &pop_seen);

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
  ENC_LEN_DEBUG(x, "gl:NotifyAdminTo", p-enc_base);
  return p;
}

/* FUNC(zx_EASY_ENC_SO_gl_NotifyAdminTo) */

/* Called by: */
struct zx_str* zx_EASY_ENC_SO_gl_NotifyAdminTo(struct zx_ctx* c, struct zx_gl_NotifyAdminTo_s* x )
{
  int len;
  char* buf;
  c->ns_tab = ZX_ALLOC(c, sizeof(zx_ns_tab));
  memcpy(c->ns_tab, zx_ns_tab, sizeof(zx_ns_tab));
  len = zx_LEN_SO_gl_NotifyAdminTo(c, x );
  buf = ZX_ALLOC(c, len+1);
  return zx_easy_enc_common(c, zx_ENC_SO_gl_NotifyAdminTo(c, x, buf ), buf, len);
}

/* FUNC(zx_EASY_ENC_WO_gl_NotifyAdminTo) */

/* Called by: */
struct zx_str* zx_EASY_ENC_WO_gl_NotifyAdminTo(struct zx_ctx* c, struct zx_gl_NotifyAdminTo_s* x )
{
  int len;
  char* buf;
  c->ns_tab = ZX_ALLOC(c, sizeof(zx_ns_tab));
  memcpy(c->ns_tab, zx_ns_tab, sizeof(zx_ns_tab));
  len = zx_LEN_WO_gl_NotifyAdminTo(c, x );
  buf = ZX_ALLOC(c, len+1);
  return zx_easy_enc_common(c, zx_ENC_WO_gl_NotifyAdminTo(c, x, buf ), buf, len);
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

#define EL_NAME   gl_NotifyResponse
#define EL_STRUCT zx_gl_NotifyResponse_s
#define EL_NS     gl
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

/* FUNC(zx_LEN_SO_gl_NotifyResponse) */

/* Compute length of an element (and its subelements). The XML attributes
 * and elements are processed in schema order. */

/* Called by: */
int zx_LEN_SO_gl_NotifyResponse(struct zx_ctx* c, struct zx_gl_NotifyResponse_s* x )
{
  struct zx_ns_s* pop_seen = 0;
  struct zx_elem_s* se MAYBE_UNUSED;
#if 1 /* NORMALMODE */
  /* *** in simple_elem case should output ns prefix from ns node. */
  int len = sizeof("<gl:NotifyResponse")-1 + 1 + sizeof("</gl:NotifyResponse>")-1;
  if (c->inc_ns_len)
    len += zx_len_inc_ns(c, &pop_seen);
  len += zx_len_xmlns_if_not_seen(c, zx_ns_tab+zx_xmlns_ix_gl, &pop_seen);

  len += zx_attr_so_len(x->id, sizeof("id")-1);

#else
  /* root node has no begin tag */
  int len = 0;
#endif
  
  {
      struct zx_gl_Status_s* e;
      for (e = x->Status; e; e = (struct zx_gl_Status_s*)e->gg.g.n)
	  len += zx_LEN_SO_gl_Status(c, e);
  }
  {
      struct zx_gl_Extension_s* e;
      for (e = x->Extension; e; e = (struct zx_gl_Extension_s*)e->gg.g.n)
	  len += zx_LEN_SO_gl_Extension(c, e);
  }


  len += zx_len_so_common(c, &x->gg);
  zx_pop_seen(pop_seen);
  ENC_LEN_DEBUG(x, "gl:NotifyResponse", len);
  return len;
}

/* FUNC(zx_LEN_WO_gl_NotifyResponse) */

/* Compute length of an element (and its subelements). The XML attributes
 * and elements are processed in wire order and no assumptions
 * are made about namespace prefixes. */

/* Called by: */
int zx_LEN_WO_gl_NotifyResponse(struct zx_ctx* c, struct zx_gl_NotifyResponse_s* x )
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

  len += zx_attr_wo_len(x->id, sizeof("id")-1);

#else
  /* root node has no begin tag */
  int len = 0;
#endif
  
  {
      struct zx_gl_Status_s* e;
      for (e = x->Status; e; e = (struct zx_gl_Status_s*)e->gg.g.n)
	  len += zx_LEN_WO_gl_Status(c, e);
  }
  {
      struct zx_gl_Extension_s* e;
      for (e = x->Extension; e; e = (struct zx_gl_Extension_s*)e->gg.g.n)
	  len += zx_LEN_WO_gl_Extension(c, e);
  }


  len += zx_len_wo_common(c, &x->gg); 
  zx_pop_seen(pop_seen);
  ENC_LEN_DEBUG(x, "gl:NotifyResponse", len);
  return len;
}

/* FUNC(zx_ENC_SO_gl_NotifyResponse) */

/* Render element into string. The XML attributes and elements are
 * processed in schema order. This is what you generally want for
 * rendering new data structure to a string. The wo pointers are not used. */

/* Called by: */
char* zx_ENC_SO_gl_NotifyResponse(struct zx_ctx* c, struct zx_gl_NotifyResponse_s* x, char* p )
{
  struct zx_elem_s* se MAYBE_UNUSED;
  struct zx_ns_s* pop_seen = 0;
  ENC_LEN_DEBUG_BASE;
#if 1 /* NORMALMODE */
  /* *** in simple_elem case should output ns prefix from ns node. */
  ZX_OUT_TAG(p, "<gl:NotifyResponse");
  if (c->inc_ns)
    p = zx_enc_inc_ns(c, p, &pop_seen);
  p = zx_enc_xmlns_if_not_seen(c, p, zx_ns_tab+zx_xmlns_ix_gl, &pop_seen);

  p = zx_attr_so_enc(p, x->id, " id=\"", sizeof(" id=\"")-1);

  p = zx_enc_unknown_attrs(p, x->gg.any_attr);
#else
  /* root node has no begin tag */
#endif
  
  {
      struct zx_gl_Status_s* e;
      for (e = x->Status; e; e = (struct zx_gl_Status_s*)e->gg.g.n)
	  p = zx_ENC_SO_gl_Status(c, e, p);
  }
  {
      struct zx_gl_Extension_s* e;
      for (e = x->Extension; e; e = (struct zx_gl_Extension_s*)e->gg.g.n)
	  p = zx_ENC_SO_gl_Extension(c, e, p);
  }

  p = zx_enc_so_unknown_elems_and_content(c, p, &x->gg);
  
#if 1 /* NORMALMODE */
  ZX_OUT_CLOSE_TAG(p, "</gl:NotifyResponse>");
  zx_pop_seen(pop_seen);
#else
  /* root node has no end tag either */
#endif
  ENC_LEN_DEBUG(x, "gl:NotifyResponse", p-enc_base);
  return p;
}

/* FUNC(zx_ENC_WO_gl_NotifyResponse) */

/* Render element into string. The XML attributes and elements are
 * processed in wire order by chasing wo pointers. This is what you want for
 * validating signatures on other people's XML documents. */

/* Called by: */
char* zx_ENC_WO_gl_NotifyResponse(struct zx_ctx* c, struct zx_gl_NotifyResponse_s* x, char* p )
{
  struct zx_elem_s* kid;
  struct zx_ns_s* pop_seen = 0;
  ENC_LEN_DEBUG_BASE;
#if 1 /* NORMALMODE */
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
  ENC_LEN_DEBUG(x, "gl:NotifyResponse", p-enc_base);
  return p;
}

/* FUNC(zx_EASY_ENC_SO_gl_NotifyResponse) */

/* Called by: */
struct zx_str* zx_EASY_ENC_SO_gl_NotifyResponse(struct zx_ctx* c, struct zx_gl_NotifyResponse_s* x )
{
  int len;
  char* buf;
  c->ns_tab = ZX_ALLOC(c, sizeof(zx_ns_tab));
  memcpy(c->ns_tab, zx_ns_tab, sizeof(zx_ns_tab));
  len = zx_LEN_SO_gl_NotifyResponse(c, x );
  buf = ZX_ALLOC(c, len+1);
  return zx_easy_enc_common(c, zx_ENC_SO_gl_NotifyResponse(c, x, buf ), buf, len);
}

/* FUNC(zx_EASY_ENC_WO_gl_NotifyResponse) */

/* Called by: */
struct zx_str* zx_EASY_ENC_WO_gl_NotifyResponse(struct zx_ctx* c, struct zx_gl_NotifyResponse_s* x )
{
  int len;
  char* buf;
  c->ns_tab = ZX_ALLOC(c, sizeof(zx_ns_tab));
  memcpy(c->ns_tab, zx_ns_tab, sizeof(zx_ns_tab));
  len = zx_LEN_WO_gl_NotifyResponse(c, x );
  buf = ZX_ALLOC(c, len+1);
  return zx_easy_enc_common(c, zx_ENC_WO_gl_NotifyResponse(c, x, buf ), buf, len);
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

#define EL_NAME   gl_NotifyTo
#define EL_STRUCT zx_gl_NotifyTo_s
#define EL_NS     gl
#define EL_TAG    NotifyTo

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

/* FUNC(zx_LEN_SO_gl_NotifyTo) */

/* Compute length of an element (and its subelements). The XML attributes
 * and elements are processed in schema order. */

/* Called by: */
int zx_LEN_SO_gl_NotifyTo(struct zx_ctx* c, struct zx_gl_NotifyTo_s* x )
{
  struct zx_ns_s* pop_seen = 0;
  struct zx_elem_s* se MAYBE_UNUSED;
#if 1 /* NORMALMODE */
  /* *** in simple_elem case should output ns prefix from ns node. */
  int len = sizeof("<gl:NotifyTo")-1 + 1 + sizeof("</gl:NotifyTo>")-1;
  if (c->inc_ns_len)
    len += zx_len_inc_ns(c, &pop_seen);
  len += zx_len_xmlns_if_not_seen(c, zx_ns_tab+zx_xmlns_ix_gl, &pop_seen);

  len += zx_attr_so_len(x->id, sizeof("id")-1);

#else
  /* root node has no begin tag */
  int len = 0;
#endif
  
  for (se = x->SecurityMechID; se; se = (struct zx_elem_s*)se->g.n)
    len += zx_LEN_SO_simple_elem(c,se, sizeof("gl:SecurityMechID")-1, zx_ns_tab+zx_xmlns_ix_gl);
  {
      struct zx_gl_Credential_s* e;
      for (e = x->Credential; e; e = (struct zx_gl_Credential_s*)e->gg.g.n)
	  len += zx_LEN_SO_gl_Credential(c, e);
  }
  for (se = x->Endpoint; se; se = (struct zx_elem_s*)se->g.n)
    len += zx_LEN_SO_simple_elem(c,se, sizeof("gl:Endpoint")-1, zx_ns_tab+zx_xmlns_ix_gl);


  len += zx_len_so_common(c, &x->gg);
  zx_pop_seen(pop_seen);
  ENC_LEN_DEBUG(x, "gl:NotifyTo", len);
  return len;
}

/* FUNC(zx_LEN_WO_gl_NotifyTo) */

/* Compute length of an element (and its subelements). The XML attributes
 * and elements are processed in wire order and no assumptions
 * are made about namespace prefixes. */

/* Called by: */
int zx_LEN_WO_gl_NotifyTo(struct zx_ctx* c, struct zx_gl_NotifyTo_s* x )
{
  struct zx_ns_s* pop_seen = 0;
  struct zx_elem_s* se MAYBE_UNUSED;
#if 1 /* NORMALMODE */
  int len = 1 + sizeof("NotifyTo")-1 + 1 + 2 + sizeof("NotifyTo")-1 + 1;
  
  if (x->gg.g.ns && x->gg.g.ns->prefix_len)
    len += (x->gg.g.ns->prefix_len + 1) * 2;
  if (c->inc_ns_len)
    len += zx_len_inc_ns(c, &pop_seen);
  len += zx_len_xmlns_if_not_seen(c, x->gg.g.ns, &pop_seen);

  len += zx_attr_wo_len(x->id, sizeof("id")-1);

#else
  /* root node has no begin tag */
  int len = 0;
#endif
  
  for (se = x->SecurityMechID; se; se = (struct zx_elem_s*)se->g.n)
    len += zx_LEN_WO_simple_elem(c, se, sizeof("SecurityMechID")-1);
  {
      struct zx_gl_Credential_s* e;
      for (e = x->Credential; e; e = (struct zx_gl_Credential_s*)e->gg.g.n)
	  len += zx_LEN_WO_gl_Credential(c, e);
  }
  for (se = x->Endpoint; se; se = (struct zx_elem_s*)se->g.n)
    len += zx_LEN_WO_simple_elem(c, se, sizeof("Endpoint")-1);


  len += zx_len_wo_common(c, &x->gg); 
  zx_pop_seen(pop_seen);
  ENC_LEN_DEBUG(x, "gl:NotifyTo", len);
  return len;
}

/* FUNC(zx_ENC_SO_gl_NotifyTo) */

/* Render element into string. The XML attributes and elements are
 * processed in schema order. This is what you generally want for
 * rendering new data structure to a string. The wo pointers are not used. */

/* Called by: */
char* zx_ENC_SO_gl_NotifyTo(struct zx_ctx* c, struct zx_gl_NotifyTo_s* x, char* p )
{
  struct zx_elem_s* se MAYBE_UNUSED;
  struct zx_ns_s* pop_seen = 0;
  ENC_LEN_DEBUG_BASE;
#if 1 /* NORMALMODE */
  /* *** in simple_elem case should output ns prefix from ns node. */
  ZX_OUT_TAG(p, "<gl:NotifyTo");
  if (c->inc_ns)
    p = zx_enc_inc_ns(c, p, &pop_seen);
  p = zx_enc_xmlns_if_not_seen(c, p, zx_ns_tab+zx_xmlns_ix_gl, &pop_seen);

  p = zx_attr_so_enc(p, x->id, " id=\"", sizeof(" id=\"")-1);

  p = zx_enc_unknown_attrs(p, x->gg.any_attr);
#else
  /* root node has no begin tag */
#endif
  
  for (se = x->SecurityMechID; se; se = (struct zx_elem_s*)se->g.n)
    p = zx_ENC_SO_simple_elem(c, se, p, "gl:SecurityMechID", sizeof("gl:SecurityMechID")-1, zx_ns_tab+zx_xmlns_ix_gl);
  {
      struct zx_gl_Credential_s* e;
      for (e = x->Credential; e; e = (struct zx_gl_Credential_s*)e->gg.g.n)
	  p = zx_ENC_SO_gl_Credential(c, e, p);
  }
  for (se = x->Endpoint; se; se = (struct zx_elem_s*)se->g.n)
    p = zx_ENC_SO_simple_elem(c, se, p, "gl:Endpoint", sizeof("gl:Endpoint")-1, zx_ns_tab+zx_xmlns_ix_gl);

  p = zx_enc_so_unknown_elems_and_content(c, p, &x->gg);
  
#if 1 /* NORMALMODE */
  ZX_OUT_CLOSE_TAG(p, "</gl:NotifyTo>");
  zx_pop_seen(pop_seen);
#else
  /* root node has no end tag either */
#endif
  ENC_LEN_DEBUG(x, "gl:NotifyTo", p-enc_base);
  return p;
}

/* FUNC(zx_ENC_WO_gl_NotifyTo) */

/* Render element into string. The XML attributes and elements are
 * processed in wire order by chasing wo pointers. This is what you want for
 * validating signatures on other people's XML documents. */

/* Called by: */
char* zx_ENC_WO_gl_NotifyTo(struct zx_ctx* c, struct zx_gl_NotifyTo_s* x, char* p )
{
  struct zx_elem_s* kid;
  struct zx_ns_s* pop_seen = 0;
  ENC_LEN_DEBUG_BASE;
#if 1 /* NORMALMODE */
  char* q;
  char* qq;
  ZX_OUT_CH(p, '<');
  q = p;
  if (x->gg.g.ns && x->gg.g.ns->prefix_len) {
    ZX_OUT_MEM(p, x->gg.g.ns->prefix, x->gg.g.ns->prefix_len);
    ZX_OUT_CH(p, ':');
  }
  ZX_OUT_MEM(p, "NotifyTo", sizeof("NotifyTo")-1);
  qq = p;

  /* *** sort the namespaces */
  if (c->inc_ns)
    zx_add_inc_ns(c, &pop_seen);
  zx_add_xmlns_if_not_seen(c, x->gg.g.ns, &pop_seen);

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
  ENC_LEN_DEBUG(x, "gl:NotifyTo", p-enc_base);
  return p;
}

/* FUNC(zx_EASY_ENC_SO_gl_NotifyTo) */

/* Called by: */
struct zx_str* zx_EASY_ENC_SO_gl_NotifyTo(struct zx_ctx* c, struct zx_gl_NotifyTo_s* x )
{
  int len;
  char* buf;
  c->ns_tab = ZX_ALLOC(c, sizeof(zx_ns_tab));
  memcpy(c->ns_tab, zx_ns_tab, sizeof(zx_ns_tab));
  len = zx_LEN_SO_gl_NotifyTo(c, x );
  buf = ZX_ALLOC(c, len+1);
  return zx_easy_enc_common(c, zx_ENC_SO_gl_NotifyTo(c, x, buf ), buf, len);
}

/* FUNC(zx_EASY_ENC_WO_gl_NotifyTo) */

/* Called by: */
struct zx_str* zx_EASY_ENC_WO_gl_NotifyTo(struct zx_ctx* c, struct zx_gl_NotifyTo_s* x )
{
  int len;
  char* buf;
  c->ns_tab = ZX_ALLOC(c, sizeof(zx_ns_tab));
  memcpy(c->ns_tab, zx_ns_tab, sizeof(zx_ns_tab));
  len = zx_LEN_WO_gl_NotifyTo(c, x );
  buf = ZX_ALLOC(c, len+1);
  return zx_easy_enc_common(c, zx_ENC_WO_gl_NotifyTo(c, x, buf ), buf, len);
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

#define EL_NAME   gl_Point
#define EL_STRUCT zx_gl_Point_s
#define EL_NS     gl
#define EL_TAG    Point

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

/* FUNC(zx_LEN_SO_gl_Point) */

/* Compute length of an element (and its subelements). The XML attributes
 * and elements are processed in schema order. */

/* Called by: */
int zx_LEN_SO_gl_Point(struct zx_ctx* c, struct zx_gl_Point_s* x )
{
  struct zx_ns_s* pop_seen = 0;
  struct zx_elem_s* se MAYBE_UNUSED;
#if 1 /* NORMALMODE */
  /* *** in simple_elem case should output ns prefix from ns node. */
  int len = sizeof("<gl:Point")-1 + 1 + sizeof("</gl:Point>")-1;
  if (c->inc_ns_len)
    len += zx_len_inc_ns(c, &pop_seen);
  len += zx_len_xmlns_if_not_seen(c, zx_ns_tab+zx_xmlns_ix_gl, &pop_seen);

  len += zx_attr_so_len(x->gid, sizeof("gid")-1);
  len += zx_attr_so_len(x->srsName, sizeof("srsName")-1);

#else
  /* root node has no begin tag */
  int len = 0;
#endif
  
  {
      struct zx_gl_coord_s* e;
      for (e = x->coord; e; e = (struct zx_gl_coord_s*)e->gg.g.n)
	  len += zx_LEN_SO_gl_coord(c, e);
  }


  len += zx_len_so_common(c, &x->gg);
  zx_pop_seen(pop_seen);
  ENC_LEN_DEBUG(x, "gl:Point", len);
  return len;
}

/* FUNC(zx_LEN_WO_gl_Point) */

/* Compute length of an element (and its subelements). The XML attributes
 * and elements are processed in wire order and no assumptions
 * are made about namespace prefixes. */

/* Called by: */
int zx_LEN_WO_gl_Point(struct zx_ctx* c, struct zx_gl_Point_s* x )
{
  struct zx_ns_s* pop_seen = 0;
  struct zx_elem_s* se MAYBE_UNUSED;
#if 1 /* NORMALMODE */
  int len = 1 + sizeof("Point")-1 + 1 + 2 + sizeof("Point")-1 + 1;
  
  if (x->gg.g.ns && x->gg.g.ns->prefix_len)
    len += (x->gg.g.ns->prefix_len + 1) * 2;
  if (c->inc_ns_len)
    len += zx_len_inc_ns(c, &pop_seen);
  len += zx_len_xmlns_if_not_seen(c, x->gg.g.ns, &pop_seen);

  len += zx_attr_wo_len(x->gid, sizeof("gid")-1);
  len += zx_attr_wo_len(x->srsName, sizeof("srsName")-1);

#else
  /* root node has no begin tag */
  int len = 0;
#endif
  
  {
      struct zx_gl_coord_s* e;
      for (e = x->coord; e; e = (struct zx_gl_coord_s*)e->gg.g.n)
	  len += zx_LEN_WO_gl_coord(c, e);
  }


  len += zx_len_wo_common(c, &x->gg); 
  zx_pop_seen(pop_seen);
  ENC_LEN_DEBUG(x, "gl:Point", len);
  return len;
}

/* FUNC(zx_ENC_SO_gl_Point) */

/* Render element into string. The XML attributes and elements are
 * processed in schema order. This is what you generally want for
 * rendering new data structure to a string. The wo pointers are not used. */

/* Called by: */
char* zx_ENC_SO_gl_Point(struct zx_ctx* c, struct zx_gl_Point_s* x, char* p )
{
  struct zx_elem_s* se MAYBE_UNUSED;
  struct zx_ns_s* pop_seen = 0;
  ENC_LEN_DEBUG_BASE;
#if 1 /* NORMALMODE */
  /* *** in simple_elem case should output ns prefix from ns node. */
  ZX_OUT_TAG(p, "<gl:Point");
  if (c->inc_ns)
    p = zx_enc_inc_ns(c, p, &pop_seen);
  p = zx_enc_xmlns_if_not_seen(c, p, zx_ns_tab+zx_xmlns_ix_gl, &pop_seen);

  p = zx_attr_so_enc(p, x->gid, " gid=\"", sizeof(" gid=\"")-1);
  p = zx_attr_so_enc(p, x->srsName, " srsName=\"", sizeof(" srsName=\"")-1);

  p = zx_enc_unknown_attrs(p, x->gg.any_attr);
#else
  /* root node has no begin tag */
#endif
  
  {
      struct zx_gl_coord_s* e;
      for (e = x->coord; e; e = (struct zx_gl_coord_s*)e->gg.g.n)
	  p = zx_ENC_SO_gl_coord(c, e, p);
  }

  p = zx_enc_so_unknown_elems_and_content(c, p, &x->gg);
  
#if 1 /* NORMALMODE */
  ZX_OUT_CLOSE_TAG(p, "</gl:Point>");
  zx_pop_seen(pop_seen);
#else
  /* root node has no end tag either */
#endif
  ENC_LEN_DEBUG(x, "gl:Point", p-enc_base);
  return p;
}

/* FUNC(zx_ENC_WO_gl_Point) */

/* Render element into string. The XML attributes and elements are
 * processed in wire order by chasing wo pointers. This is what you want for
 * validating signatures on other people's XML documents. */

/* Called by: */
char* zx_ENC_WO_gl_Point(struct zx_ctx* c, struct zx_gl_Point_s* x, char* p )
{
  struct zx_elem_s* kid;
  struct zx_ns_s* pop_seen = 0;
  ENC_LEN_DEBUG_BASE;
#if 1 /* NORMALMODE */
  char* q;
  char* qq;
  ZX_OUT_CH(p, '<');
  q = p;
  if (x->gg.g.ns && x->gg.g.ns->prefix_len) {
    ZX_OUT_MEM(p, x->gg.g.ns->prefix, x->gg.g.ns->prefix_len);
    ZX_OUT_CH(p, ':');
  }
  ZX_OUT_MEM(p, "Point", sizeof("Point")-1);
  qq = p;

  /* *** sort the namespaces */
  if (c->inc_ns)
    zx_add_inc_ns(c, &pop_seen);
  zx_add_xmlns_if_not_seen(c, x->gg.g.ns, &pop_seen);

  p = zx_enc_seen(p, pop_seen); 
  p = zx_attr_wo_enc(p, x->gid, "gid=\"", sizeof("gid=\"")-1);
  p = zx_attr_wo_enc(p, x->srsName, "srsName=\"", sizeof("srsName=\"")-1);

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
  ENC_LEN_DEBUG(x, "gl:Point", p-enc_base);
  return p;
}

/* FUNC(zx_EASY_ENC_SO_gl_Point) */

/* Called by: */
struct zx_str* zx_EASY_ENC_SO_gl_Point(struct zx_ctx* c, struct zx_gl_Point_s* x )
{
  int len;
  char* buf;
  c->ns_tab = ZX_ALLOC(c, sizeof(zx_ns_tab));
  memcpy(c->ns_tab, zx_ns_tab, sizeof(zx_ns_tab));
  len = zx_LEN_SO_gl_Point(c, x );
  buf = ZX_ALLOC(c, len+1);
  return zx_easy_enc_common(c, zx_ENC_SO_gl_Point(c, x, buf ), buf, len);
}

/* FUNC(zx_EASY_ENC_WO_gl_Point) */

/* Called by: */
struct zx_str* zx_EASY_ENC_WO_gl_Point(struct zx_ctx* c, struct zx_gl_Point_s* x )
{
  int len;
  char* buf;
  c->ns_tab = ZX_ALLOC(c, sizeof(zx_ns_tab));
  memcpy(c->ns_tab, zx_ns_tab, sizeof(zx_ns_tab));
  len = zx_LEN_WO_gl_Point(c, x );
  buf = ZX_ALLOC(c, len+1);
  return zx_easy_enc_common(c, zx_ENC_WO_gl_Point(c, x, buf ), buf, len);
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

#define EL_NAME   gl_Polygon
#define EL_STRUCT zx_gl_Polygon_s
#define EL_NS     gl
#define EL_TAG    Polygon

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

/* FUNC(zx_LEN_SO_gl_Polygon) */

/* Compute length of an element (and its subelements). The XML attributes
 * and elements are processed in schema order. */

/* Called by: */
int zx_LEN_SO_gl_Polygon(struct zx_ctx* c, struct zx_gl_Polygon_s* x )
{
  struct zx_ns_s* pop_seen = 0;
  struct zx_elem_s* se MAYBE_UNUSED;
#if 1 /* NORMALMODE */
  /* *** in simple_elem case should output ns prefix from ns node. */
  int len = sizeof("<gl:Polygon")-1 + 1 + sizeof("</gl:Polygon>")-1;
  if (c->inc_ns_len)
    len += zx_len_inc_ns(c, &pop_seen);
  len += zx_len_xmlns_if_not_seen(c, zx_ns_tab+zx_xmlns_ix_gl, &pop_seen);

  len += zx_attr_so_len(x->gid, sizeof("gid")-1);
  len += zx_attr_so_len(x->srsName, sizeof("srsName")-1);

#else
  /* root node has no begin tag */
  int len = 0;
#endif
  
  {
      struct zx_gl_outerBoundaryIs_s* e;
      for (e = x->outerBoundaryIs; e; e = (struct zx_gl_outerBoundaryIs_s*)e->gg.g.n)
	  len += zx_LEN_SO_gl_outerBoundaryIs(c, e);
  }
  {
      struct zx_gl_innerBoundaryIs_s* e;
      for (e = x->innerBoundaryIs; e; e = (struct zx_gl_innerBoundaryIs_s*)e->gg.g.n)
	  len += zx_LEN_SO_gl_innerBoundaryIs(c, e);
  }


  len += zx_len_so_common(c, &x->gg);
  zx_pop_seen(pop_seen);
  ENC_LEN_DEBUG(x, "gl:Polygon", len);
  return len;
}

/* FUNC(zx_LEN_WO_gl_Polygon) */

/* Compute length of an element (and its subelements). The XML attributes
 * and elements are processed in wire order and no assumptions
 * are made about namespace prefixes. */

/* Called by: */
int zx_LEN_WO_gl_Polygon(struct zx_ctx* c, struct zx_gl_Polygon_s* x )
{
  struct zx_ns_s* pop_seen = 0;
  struct zx_elem_s* se MAYBE_UNUSED;
#if 1 /* NORMALMODE */
  int len = 1 + sizeof("Polygon")-1 + 1 + 2 + sizeof("Polygon")-1 + 1;
  
  if (x->gg.g.ns && x->gg.g.ns->prefix_len)
    len += (x->gg.g.ns->prefix_len + 1) * 2;
  if (c->inc_ns_len)
    len += zx_len_inc_ns(c, &pop_seen);
  len += zx_len_xmlns_if_not_seen(c, x->gg.g.ns, &pop_seen);

  len += zx_attr_wo_len(x->gid, sizeof("gid")-1);
  len += zx_attr_wo_len(x->srsName, sizeof("srsName")-1);

#else
  /* root node has no begin tag */
  int len = 0;
#endif
  
  {
      struct zx_gl_outerBoundaryIs_s* e;
      for (e = x->outerBoundaryIs; e; e = (struct zx_gl_outerBoundaryIs_s*)e->gg.g.n)
	  len += zx_LEN_WO_gl_outerBoundaryIs(c, e);
  }
  {
      struct zx_gl_innerBoundaryIs_s* e;
      for (e = x->innerBoundaryIs; e; e = (struct zx_gl_innerBoundaryIs_s*)e->gg.g.n)
	  len += zx_LEN_WO_gl_innerBoundaryIs(c, e);
  }


  len += zx_len_wo_common(c, &x->gg); 
  zx_pop_seen(pop_seen);
  ENC_LEN_DEBUG(x, "gl:Polygon", len);
  return len;
}

/* FUNC(zx_ENC_SO_gl_Polygon) */

/* Render element into string. The XML attributes and elements are
 * processed in schema order. This is what you generally want for
 * rendering new data structure to a string. The wo pointers are not used. */

/* Called by: */
char* zx_ENC_SO_gl_Polygon(struct zx_ctx* c, struct zx_gl_Polygon_s* x, char* p )
{
  struct zx_elem_s* se MAYBE_UNUSED;
  struct zx_ns_s* pop_seen = 0;
  ENC_LEN_DEBUG_BASE;
#if 1 /* NORMALMODE */
  /* *** in simple_elem case should output ns prefix from ns node. */
  ZX_OUT_TAG(p, "<gl:Polygon");
  if (c->inc_ns)
    p = zx_enc_inc_ns(c, p, &pop_seen);
  p = zx_enc_xmlns_if_not_seen(c, p, zx_ns_tab+zx_xmlns_ix_gl, &pop_seen);

  p = zx_attr_so_enc(p, x->gid, " gid=\"", sizeof(" gid=\"")-1);
  p = zx_attr_so_enc(p, x->srsName, " srsName=\"", sizeof(" srsName=\"")-1);

  p = zx_enc_unknown_attrs(p, x->gg.any_attr);
#else
  /* root node has no begin tag */
#endif
  
  {
      struct zx_gl_outerBoundaryIs_s* e;
      for (e = x->outerBoundaryIs; e; e = (struct zx_gl_outerBoundaryIs_s*)e->gg.g.n)
	  p = zx_ENC_SO_gl_outerBoundaryIs(c, e, p);
  }
  {
      struct zx_gl_innerBoundaryIs_s* e;
      for (e = x->innerBoundaryIs; e; e = (struct zx_gl_innerBoundaryIs_s*)e->gg.g.n)
	  p = zx_ENC_SO_gl_innerBoundaryIs(c, e, p);
  }

  p = zx_enc_so_unknown_elems_and_content(c, p, &x->gg);
  
#if 1 /* NORMALMODE */
  ZX_OUT_CLOSE_TAG(p, "</gl:Polygon>");
  zx_pop_seen(pop_seen);
#else
  /* root node has no end tag either */
#endif
  ENC_LEN_DEBUG(x, "gl:Polygon", p-enc_base);
  return p;
}

/* FUNC(zx_ENC_WO_gl_Polygon) */

/* Render element into string. The XML attributes and elements are
 * processed in wire order by chasing wo pointers. This is what you want for
 * validating signatures on other people's XML documents. */

/* Called by: */
char* zx_ENC_WO_gl_Polygon(struct zx_ctx* c, struct zx_gl_Polygon_s* x, char* p )
{
  struct zx_elem_s* kid;
  struct zx_ns_s* pop_seen = 0;
  ENC_LEN_DEBUG_BASE;
#if 1 /* NORMALMODE */
  char* q;
  char* qq;
  ZX_OUT_CH(p, '<');
  q = p;
  if (x->gg.g.ns && x->gg.g.ns->prefix_len) {
    ZX_OUT_MEM(p, x->gg.g.ns->prefix, x->gg.g.ns->prefix_len);
    ZX_OUT_CH(p, ':');
  }
  ZX_OUT_MEM(p, "Polygon", sizeof("Polygon")-1);
  qq = p;

  /* *** sort the namespaces */
  if (c->inc_ns)
    zx_add_inc_ns(c, &pop_seen);
  zx_add_xmlns_if_not_seen(c, x->gg.g.ns, &pop_seen);

  p = zx_enc_seen(p, pop_seen); 
  p = zx_attr_wo_enc(p, x->gid, "gid=\"", sizeof("gid=\"")-1);
  p = zx_attr_wo_enc(p, x->srsName, "srsName=\"", sizeof("srsName=\"")-1);

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
  ENC_LEN_DEBUG(x, "gl:Polygon", p-enc_base);
  return p;
}

/* FUNC(zx_EASY_ENC_SO_gl_Polygon) */

/* Called by: */
struct zx_str* zx_EASY_ENC_SO_gl_Polygon(struct zx_ctx* c, struct zx_gl_Polygon_s* x )
{
  int len;
  char* buf;
  c->ns_tab = ZX_ALLOC(c, sizeof(zx_ns_tab));
  memcpy(c->ns_tab, zx_ns_tab, sizeof(zx_ns_tab));
  len = zx_LEN_SO_gl_Polygon(c, x );
  buf = ZX_ALLOC(c, len+1);
  return zx_easy_enc_common(c, zx_ENC_SO_gl_Polygon(c, x, buf ), buf, len);
}

/* FUNC(zx_EASY_ENC_WO_gl_Polygon) */

/* Called by: */
struct zx_str* zx_EASY_ENC_WO_gl_Polygon(struct zx_ctx* c, struct zx_gl_Polygon_s* x )
{
  int len;
  char* buf;
  c->ns_tab = ZX_ALLOC(c, sizeof(zx_ns_tab));
  memcpy(c->ns_tab, zx_ns_tab, sizeof(zx_ns_tab));
  len = zx_LEN_WO_gl_Polygon(c, x );
  buf = ZX_ALLOC(c, len+1);
  return zx_easy_enc_common(c, zx_ENC_WO_gl_Polygon(c, x, buf ), buf, len);
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

#define EL_NAME   gl_Query
#define EL_STRUCT zx_gl_Query_s
#define EL_NS     gl
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

/* FUNC(zx_LEN_SO_gl_Query) */

/* Compute length of an element (and its subelements). The XML attributes
 * and elements are processed in schema order. */

/* Called by: */
int zx_LEN_SO_gl_Query(struct zx_ctx* c, struct zx_gl_Query_s* x )
{
  struct zx_ns_s* pop_seen = 0;
  struct zx_elem_s* se MAYBE_UNUSED;
#if 1 /* NORMALMODE */
  /* *** in simple_elem case should output ns prefix from ns node. */
  int len = sizeof("<gl:Query")-1 + 1 + sizeof("</gl:Query>")-1;
  if (c->inc_ns_len)
    len += zx_len_inc_ns(c, &pop_seen);
  len += zx_len_xmlns_if_not_seen(c, zx_ns_tab+zx_xmlns_ix_gl, &pop_seen);

  len += zx_attr_so_len(x->id, sizeof("id")-1);

#else
  /* root node has no begin tag */
  int len = 0;
#endif
  
  {
      struct zx_gl_ResourceID_s* e;
      for (e = x->ResourceID; e; e = (struct zx_gl_ResourceID_s*)e->gg.g.n)
	  len += zx_LEN_SO_gl_ResourceID(c, e);
  }
  {
      struct zx_gl_EncryptedResourceID_s* e;
      for (e = x->EncryptedResourceID; e; e = (struct zx_gl_EncryptedResourceID_s*)e->gg.g.n)
	  len += zx_LEN_SO_gl_EncryptedResourceID(c, e);
  }
  {
      struct zx_gl_Subscription_s* e;
      for (e = x->Subscription; e; e = (struct zx_gl_Subscription_s*)e->gg.g.n)
	  len += zx_LEN_SO_gl_Subscription(c, e);
  }
  {
      struct zx_gl_QueryItem_s* e;
      for (e = x->QueryItem; e; e = (struct zx_gl_QueryItem_s*)e->gg.g.n)
	  len += zx_LEN_SO_gl_QueryItem(c, e);
  }
  {
      struct zx_gl_Extension_s* e;
      for (e = x->Extension; e; e = (struct zx_gl_Extension_s*)e->gg.g.n)
	  len += zx_LEN_SO_gl_Extension(c, e);
  }


  len += zx_len_so_common(c, &x->gg);
  zx_pop_seen(pop_seen);
  ENC_LEN_DEBUG(x, "gl:Query", len);
  return len;
}

/* FUNC(zx_LEN_WO_gl_Query) */

/* Compute length of an element (and its subelements). The XML attributes
 * and elements are processed in wire order and no assumptions
 * are made about namespace prefixes. */

/* Called by: */
int zx_LEN_WO_gl_Query(struct zx_ctx* c, struct zx_gl_Query_s* x )
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

  len += zx_attr_wo_len(x->id, sizeof("id")-1);

#else
  /* root node has no begin tag */
  int len = 0;
#endif
  
  {
      struct zx_gl_ResourceID_s* e;
      for (e = x->ResourceID; e; e = (struct zx_gl_ResourceID_s*)e->gg.g.n)
	  len += zx_LEN_WO_gl_ResourceID(c, e);
  }
  {
      struct zx_gl_EncryptedResourceID_s* e;
      for (e = x->EncryptedResourceID; e; e = (struct zx_gl_EncryptedResourceID_s*)e->gg.g.n)
	  len += zx_LEN_WO_gl_EncryptedResourceID(c, e);
  }
  {
      struct zx_gl_Subscription_s* e;
      for (e = x->Subscription; e; e = (struct zx_gl_Subscription_s*)e->gg.g.n)
	  len += zx_LEN_WO_gl_Subscription(c, e);
  }
  {
      struct zx_gl_QueryItem_s* e;
      for (e = x->QueryItem; e; e = (struct zx_gl_QueryItem_s*)e->gg.g.n)
	  len += zx_LEN_WO_gl_QueryItem(c, e);
  }
  {
      struct zx_gl_Extension_s* e;
      for (e = x->Extension; e; e = (struct zx_gl_Extension_s*)e->gg.g.n)
	  len += zx_LEN_WO_gl_Extension(c, e);
  }


  len += zx_len_wo_common(c, &x->gg); 
  zx_pop_seen(pop_seen);
  ENC_LEN_DEBUG(x, "gl:Query", len);
  return len;
}

/* FUNC(zx_ENC_SO_gl_Query) */

/* Render element into string. The XML attributes and elements are
 * processed in schema order. This is what you generally want for
 * rendering new data structure to a string. The wo pointers are not used. */

/* Called by: */
char* zx_ENC_SO_gl_Query(struct zx_ctx* c, struct zx_gl_Query_s* x, char* p )
{
  struct zx_elem_s* se MAYBE_UNUSED;
  struct zx_ns_s* pop_seen = 0;
  ENC_LEN_DEBUG_BASE;
#if 1 /* NORMALMODE */
  /* *** in simple_elem case should output ns prefix from ns node. */
  ZX_OUT_TAG(p, "<gl:Query");
  if (c->inc_ns)
    p = zx_enc_inc_ns(c, p, &pop_seen);
  p = zx_enc_xmlns_if_not_seen(c, p, zx_ns_tab+zx_xmlns_ix_gl, &pop_seen);

  p = zx_attr_so_enc(p, x->id, " id=\"", sizeof(" id=\"")-1);

  p = zx_enc_unknown_attrs(p, x->gg.any_attr);
#else
  /* root node has no begin tag */
#endif
  
  {
      struct zx_gl_ResourceID_s* e;
      for (e = x->ResourceID; e; e = (struct zx_gl_ResourceID_s*)e->gg.g.n)
	  p = zx_ENC_SO_gl_ResourceID(c, e, p);
  }
  {
      struct zx_gl_EncryptedResourceID_s* e;
      for (e = x->EncryptedResourceID; e; e = (struct zx_gl_EncryptedResourceID_s*)e->gg.g.n)
	  p = zx_ENC_SO_gl_EncryptedResourceID(c, e, p);
  }
  {
      struct zx_gl_Subscription_s* e;
      for (e = x->Subscription; e; e = (struct zx_gl_Subscription_s*)e->gg.g.n)
	  p = zx_ENC_SO_gl_Subscription(c, e, p);
  }
  {
      struct zx_gl_QueryItem_s* e;
      for (e = x->QueryItem; e; e = (struct zx_gl_QueryItem_s*)e->gg.g.n)
	  p = zx_ENC_SO_gl_QueryItem(c, e, p);
  }
  {
      struct zx_gl_Extension_s* e;
      for (e = x->Extension; e; e = (struct zx_gl_Extension_s*)e->gg.g.n)
	  p = zx_ENC_SO_gl_Extension(c, e, p);
  }

  p = zx_enc_so_unknown_elems_and_content(c, p, &x->gg);
  
#if 1 /* NORMALMODE */
  ZX_OUT_CLOSE_TAG(p, "</gl:Query>");
  zx_pop_seen(pop_seen);
#else
  /* root node has no end tag either */
#endif
  ENC_LEN_DEBUG(x, "gl:Query", p-enc_base);
  return p;
}

/* FUNC(zx_ENC_WO_gl_Query) */

/* Render element into string. The XML attributes and elements are
 * processed in wire order by chasing wo pointers. This is what you want for
 * validating signatures on other people's XML documents. */

/* Called by: */
char* zx_ENC_WO_gl_Query(struct zx_ctx* c, struct zx_gl_Query_s* x, char* p )
{
  struct zx_elem_s* kid;
  struct zx_ns_s* pop_seen = 0;
  ENC_LEN_DEBUG_BASE;
#if 1 /* NORMALMODE */
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
  ENC_LEN_DEBUG(x, "gl:Query", p-enc_base);
  return p;
}

/* FUNC(zx_EASY_ENC_SO_gl_Query) */

/* Called by: */
struct zx_str* zx_EASY_ENC_SO_gl_Query(struct zx_ctx* c, struct zx_gl_Query_s* x )
{
  int len;
  char* buf;
  c->ns_tab = ZX_ALLOC(c, sizeof(zx_ns_tab));
  memcpy(c->ns_tab, zx_ns_tab, sizeof(zx_ns_tab));
  len = zx_LEN_SO_gl_Query(c, x );
  buf = ZX_ALLOC(c, len+1);
  return zx_easy_enc_common(c, zx_ENC_SO_gl_Query(c, x, buf ), buf, len);
}

/* FUNC(zx_EASY_ENC_WO_gl_Query) */

/* Called by: */
struct zx_str* zx_EASY_ENC_WO_gl_Query(struct zx_ctx* c, struct zx_gl_Query_s* x )
{
  int len;
  char* buf;
  c->ns_tab = ZX_ALLOC(c, sizeof(zx_ns_tab));
  memcpy(c->ns_tab, zx_ns_tab, sizeof(zx_ns_tab));
  len = zx_LEN_WO_gl_Query(c, x );
  buf = ZX_ALLOC(c, len+1);
  return zx_easy_enc_common(c, zx_ENC_WO_gl_Query(c, x, buf ), buf, len);
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

#define EL_NAME   gl_QueryItem
#define EL_STRUCT zx_gl_QueryItem_s
#define EL_NS     gl
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

/* FUNC(zx_LEN_SO_gl_QueryItem) */

/* Compute length of an element (and its subelements). The XML attributes
 * and elements are processed in schema order. */

/* Called by: */
int zx_LEN_SO_gl_QueryItem(struct zx_ctx* c, struct zx_gl_QueryItem_s* x )
{
  struct zx_ns_s* pop_seen = 0;
  struct zx_elem_s* se MAYBE_UNUSED;
#if 1 /* NORMALMODE */
  /* *** in simple_elem case should output ns prefix from ns node. */
  int len = sizeof("<gl:QueryItem")-1 + 1 + sizeof("</gl:QueryItem>")-1;
  if (c->inc_ns_len)
    len += zx_len_inc_ns(c, &pop_seen);
  len += zx_len_xmlns_if_not_seen(c, zx_ns_tab+zx_xmlns_ix_gl, &pop_seen);

  len += zx_attr_so_len(x->count, sizeof("count")-1);
  len += zx_attr_so_len(x->offset, sizeof("offset")-1);
  len += zx_attr_so_len(x->setID, sizeof("setID")-1);
  len += zx_attr_so_len(x->setReq, sizeof("setReq")-1);

#else
  /* root node has no begin tag */
  int len = 0;
#endif
  
  {
      struct zx_gl_AreaComparison_s* e;
      for (e = x->AreaComparison; e; e = (struct zx_gl_AreaComparison_s*)e->gg.g.n)
	  len += zx_LEN_SO_gl_AreaComparison(c, e);
  }
  {
      struct zx_gl_eqop_s* e;
      for (e = x->eqop; e; e = (struct zx_gl_eqop_s*)e->gg.g.n)
	  len += zx_LEN_SO_gl_eqop(c, e);
  }
  {
      struct zx_gl_geoinfo_s* e;
      for (e = x->geoinfo; e; e = (struct zx_gl_geoinfo_s*)e->gg.g.n)
	  len += zx_LEN_SO_gl_geoinfo(c, e);
  }
  {
      struct zx_gl_loc_type_s* e;
      for (e = x->loc_type; e; e = (struct zx_gl_loc_type_s*)e->gg.g.n)
	  len += zx_LEN_SO_gl_loc_type(c, e);
  }
  {
      struct zx_gl_prio_s* e;
      for (e = x->prio; e; e = (struct zx_gl_prio_s*)e->gg.g.n)
	  len += zx_LEN_SO_gl_prio(c, e);
  }
  {
      struct zx_gl_Extension_s* e;
      for (e = x->Extension; e; e = (struct zx_gl_Extension_s*)e->gg.g.n)
	  len += zx_LEN_SO_gl_Extension(c, e);
  }


  len += zx_len_so_common(c, &x->gg);
  zx_pop_seen(pop_seen);
  ENC_LEN_DEBUG(x, "gl:QueryItem", len);
  return len;
}

/* FUNC(zx_LEN_WO_gl_QueryItem) */

/* Compute length of an element (and its subelements). The XML attributes
 * and elements are processed in wire order and no assumptions
 * are made about namespace prefixes. */

/* Called by: */
int zx_LEN_WO_gl_QueryItem(struct zx_ctx* c, struct zx_gl_QueryItem_s* x )
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

  len += zx_attr_wo_len(x->count, sizeof("count")-1);
  len += zx_attr_wo_len(x->offset, sizeof("offset")-1);
  len += zx_attr_wo_len(x->setID, sizeof("setID")-1);
  len += zx_attr_wo_len(x->setReq, sizeof("setReq")-1);

#else
  /* root node has no begin tag */
  int len = 0;
#endif
  
  {
      struct zx_gl_AreaComparison_s* e;
      for (e = x->AreaComparison; e; e = (struct zx_gl_AreaComparison_s*)e->gg.g.n)
	  len += zx_LEN_WO_gl_AreaComparison(c, e);
  }
  {
      struct zx_gl_eqop_s* e;
      for (e = x->eqop; e; e = (struct zx_gl_eqop_s*)e->gg.g.n)
	  len += zx_LEN_WO_gl_eqop(c, e);
  }
  {
      struct zx_gl_geoinfo_s* e;
      for (e = x->geoinfo; e; e = (struct zx_gl_geoinfo_s*)e->gg.g.n)
	  len += zx_LEN_WO_gl_geoinfo(c, e);
  }
  {
      struct zx_gl_loc_type_s* e;
      for (e = x->loc_type; e; e = (struct zx_gl_loc_type_s*)e->gg.g.n)
	  len += zx_LEN_WO_gl_loc_type(c, e);
  }
  {
      struct zx_gl_prio_s* e;
      for (e = x->prio; e; e = (struct zx_gl_prio_s*)e->gg.g.n)
	  len += zx_LEN_WO_gl_prio(c, e);
  }
  {
      struct zx_gl_Extension_s* e;
      for (e = x->Extension; e; e = (struct zx_gl_Extension_s*)e->gg.g.n)
	  len += zx_LEN_WO_gl_Extension(c, e);
  }


  len += zx_len_wo_common(c, &x->gg); 
  zx_pop_seen(pop_seen);
  ENC_LEN_DEBUG(x, "gl:QueryItem", len);
  return len;
}

/* FUNC(zx_ENC_SO_gl_QueryItem) */

/* Render element into string. The XML attributes and elements are
 * processed in schema order. This is what you generally want for
 * rendering new data structure to a string. The wo pointers are not used. */

/* Called by: */
char* zx_ENC_SO_gl_QueryItem(struct zx_ctx* c, struct zx_gl_QueryItem_s* x, char* p )
{
  struct zx_elem_s* se MAYBE_UNUSED;
  struct zx_ns_s* pop_seen = 0;
  ENC_LEN_DEBUG_BASE;
#if 1 /* NORMALMODE */
  /* *** in simple_elem case should output ns prefix from ns node. */
  ZX_OUT_TAG(p, "<gl:QueryItem");
  if (c->inc_ns)
    p = zx_enc_inc_ns(c, p, &pop_seen);
  p = zx_enc_xmlns_if_not_seen(c, p, zx_ns_tab+zx_xmlns_ix_gl, &pop_seen);

  p = zx_attr_so_enc(p, x->count, " count=\"", sizeof(" count=\"")-1);
  p = zx_attr_so_enc(p, x->offset, " offset=\"", sizeof(" offset=\"")-1);
  p = zx_attr_so_enc(p, x->setID, " setID=\"", sizeof(" setID=\"")-1);
  p = zx_attr_so_enc(p, x->setReq, " setReq=\"", sizeof(" setReq=\"")-1);

  p = zx_enc_unknown_attrs(p, x->gg.any_attr);
#else
  /* root node has no begin tag */
#endif
  
  {
      struct zx_gl_AreaComparison_s* e;
      for (e = x->AreaComparison; e; e = (struct zx_gl_AreaComparison_s*)e->gg.g.n)
	  p = zx_ENC_SO_gl_AreaComparison(c, e, p);
  }
  {
      struct zx_gl_eqop_s* e;
      for (e = x->eqop; e; e = (struct zx_gl_eqop_s*)e->gg.g.n)
	  p = zx_ENC_SO_gl_eqop(c, e, p);
  }
  {
      struct zx_gl_geoinfo_s* e;
      for (e = x->geoinfo; e; e = (struct zx_gl_geoinfo_s*)e->gg.g.n)
	  p = zx_ENC_SO_gl_geoinfo(c, e, p);
  }
  {
      struct zx_gl_loc_type_s* e;
      for (e = x->loc_type; e; e = (struct zx_gl_loc_type_s*)e->gg.g.n)
	  p = zx_ENC_SO_gl_loc_type(c, e, p);
  }
  {
      struct zx_gl_prio_s* e;
      for (e = x->prio; e; e = (struct zx_gl_prio_s*)e->gg.g.n)
	  p = zx_ENC_SO_gl_prio(c, e, p);
  }
  {
      struct zx_gl_Extension_s* e;
      for (e = x->Extension; e; e = (struct zx_gl_Extension_s*)e->gg.g.n)
	  p = zx_ENC_SO_gl_Extension(c, e, p);
  }

  p = zx_enc_so_unknown_elems_and_content(c, p, &x->gg);
  
#if 1 /* NORMALMODE */
  ZX_OUT_CLOSE_TAG(p, "</gl:QueryItem>");
  zx_pop_seen(pop_seen);
#else
  /* root node has no end tag either */
#endif
  ENC_LEN_DEBUG(x, "gl:QueryItem", p-enc_base);
  return p;
}

/* FUNC(zx_ENC_WO_gl_QueryItem) */

/* Render element into string. The XML attributes and elements are
 * processed in wire order by chasing wo pointers. This is what you want for
 * validating signatures on other people's XML documents. */

/* Called by: */
char* zx_ENC_WO_gl_QueryItem(struct zx_ctx* c, struct zx_gl_QueryItem_s* x, char* p )
{
  struct zx_elem_s* kid;
  struct zx_ns_s* pop_seen = 0;
  ENC_LEN_DEBUG_BASE;
#if 1 /* NORMALMODE */
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

  p = zx_enc_seen(p, pop_seen); 
  p = zx_attr_wo_enc(p, x->count, "count=\"", sizeof("count=\"")-1);
  p = zx_attr_wo_enc(p, x->offset, "offset=\"", sizeof("offset=\"")-1);
  p = zx_attr_wo_enc(p, x->setID, "setID=\"", sizeof("setID=\"")-1);
  p = zx_attr_wo_enc(p, x->setReq, "setReq=\"", sizeof("setReq=\"")-1);

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
  ENC_LEN_DEBUG(x, "gl:QueryItem", p-enc_base);
  return p;
}

/* FUNC(zx_EASY_ENC_SO_gl_QueryItem) */

/* Called by: */
struct zx_str* zx_EASY_ENC_SO_gl_QueryItem(struct zx_ctx* c, struct zx_gl_QueryItem_s* x )
{
  int len;
  char* buf;
  c->ns_tab = ZX_ALLOC(c, sizeof(zx_ns_tab));
  memcpy(c->ns_tab, zx_ns_tab, sizeof(zx_ns_tab));
  len = zx_LEN_SO_gl_QueryItem(c, x );
  buf = ZX_ALLOC(c, len+1);
  return zx_easy_enc_common(c, zx_ENC_SO_gl_QueryItem(c, x, buf ), buf, len);
}

/* FUNC(zx_EASY_ENC_WO_gl_QueryItem) */

/* Called by: */
struct zx_str* zx_EASY_ENC_WO_gl_QueryItem(struct zx_ctx* c, struct zx_gl_QueryItem_s* x )
{
  int len;
  char* buf;
  c->ns_tab = ZX_ALLOC(c, sizeof(zx_ns_tab));
  memcpy(c->ns_tab, zx_ns_tab, sizeof(zx_ns_tab));
  len = zx_LEN_WO_gl_QueryItem(c, x );
  buf = ZX_ALLOC(c, len+1);
  return zx_easy_enc_common(c, zx_ENC_WO_gl_QueryItem(c, x, buf ), buf, len);
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

#define EL_NAME   gl_QueryResponse
#define EL_STRUCT zx_gl_QueryResponse_s
#define EL_NS     gl
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

/* FUNC(zx_LEN_SO_gl_QueryResponse) */

/* Compute length of an element (and its subelements). The XML attributes
 * and elements are processed in schema order. */

/* Called by: */
int zx_LEN_SO_gl_QueryResponse(struct zx_ctx* c, struct zx_gl_QueryResponse_s* x )
{
  struct zx_ns_s* pop_seen = 0;
  struct zx_elem_s* se MAYBE_UNUSED;
#if 1 /* NORMALMODE */
  /* *** in simple_elem case should output ns prefix from ns node. */
  int len = sizeof("<gl:QueryResponse")-1 + 1 + sizeof("</gl:QueryResponse>")-1;
  if (c->inc_ns_len)
    len += zx_len_inc_ns(c, &pop_seen);
  len += zx_len_xmlns_if_not_seen(c, zx_ns_tab+zx_xmlns_ix_gl, &pop_seen);

  len += zx_attr_so_len(x->id, sizeof("id")-1);
  len += zx_attr_so_len(x->itemIDRef, sizeof("itemIDRef")-1);
  len += zx_attr_so_len(x->timeStamp, sizeof("timeStamp")-1);

#else
  /* root node has no begin tag */
  int len = 0;
#endif
  
  {
      struct zx_gl_Status_s* e;
      for (e = x->Status; e; e = (struct zx_gl_Status_s*)e->gg.g.n)
	  len += zx_LEN_SO_gl_Status(c, e);
  }
  {
      struct zx_gl_Data_s* e;
      for (e = x->Data; e; e = (struct zx_gl_Data_s*)e->gg.g.n)
	  len += zx_LEN_SO_gl_Data(c, e);
  }
  {
      struct zx_gl_Extension_s* e;
      for (e = x->Extension; e; e = (struct zx_gl_Extension_s*)e->gg.g.n)
	  len += zx_LEN_SO_gl_Extension(c, e);
  }


  len += zx_len_so_common(c, &x->gg);
  zx_pop_seen(pop_seen);
  ENC_LEN_DEBUG(x, "gl:QueryResponse", len);
  return len;
}

/* FUNC(zx_LEN_WO_gl_QueryResponse) */

/* Compute length of an element (and its subelements). The XML attributes
 * and elements are processed in wire order and no assumptions
 * are made about namespace prefixes. */

/* Called by: */
int zx_LEN_WO_gl_QueryResponse(struct zx_ctx* c, struct zx_gl_QueryResponse_s* x )
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

  len += zx_attr_wo_len(x->id, sizeof("id")-1);
  len += zx_attr_wo_len(x->itemIDRef, sizeof("itemIDRef")-1);
  len += zx_attr_wo_len(x->timeStamp, sizeof("timeStamp")-1);

#else
  /* root node has no begin tag */
  int len = 0;
#endif
  
  {
      struct zx_gl_Status_s* e;
      for (e = x->Status; e; e = (struct zx_gl_Status_s*)e->gg.g.n)
	  len += zx_LEN_WO_gl_Status(c, e);
  }
  {
      struct zx_gl_Data_s* e;
      for (e = x->Data; e; e = (struct zx_gl_Data_s*)e->gg.g.n)
	  len += zx_LEN_WO_gl_Data(c, e);
  }
  {
      struct zx_gl_Extension_s* e;
      for (e = x->Extension; e; e = (struct zx_gl_Extension_s*)e->gg.g.n)
	  len += zx_LEN_WO_gl_Extension(c, e);
  }


  len += zx_len_wo_common(c, &x->gg); 
  zx_pop_seen(pop_seen);
  ENC_LEN_DEBUG(x, "gl:QueryResponse", len);
  return len;
}

/* FUNC(zx_ENC_SO_gl_QueryResponse) */

/* Render element into string. The XML attributes and elements are
 * processed in schema order. This is what you generally want for
 * rendering new data structure to a string. The wo pointers are not used. */

/* Called by: */
char* zx_ENC_SO_gl_QueryResponse(struct zx_ctx* c, struct zx_gl_QueryResponse_s* x, char* p )
{
  struct zx_elem_s* se MAYBE_UNUSED;
  struct zx_ns_s* pop_seen = 0;
  ENC_LEN_DEBUG_BASE;
#if 1 /* NORMALMODE */
  /* *** in simple_elem case should output ns prefix from ns node. */
  ZX_OUT_TAG(p, "<gl:QueryResponse");
  if (c->inc_ns)
    p = zx_enc_inc_ns(c, p, &pop_seen);
  p = zx_enc_xmlns_if_not_seen(c, p, zx_ns_tab+zx_xmlns_ix_gl, &pop_seen);

  p = zx_attr_so_enc(p, x->id, " id=\"", sizeof(" id=\"")-1);
  p = zx_attr_so_enc(p, x->itemIDRef, " itemIDRef=\"", sizeof(" itemIDRef=\"")-1);
  p = zx_attr_so_enc(p, x->timeStamp, " timeStamp=\"", sizeof(" timeStamp=\"")-1);

  p = zx_enc_unknown_attrs(p, x->gg.any_attr);
#else
  /* root node has no begin tag */
#endif
  
  {
      struct zx_gl_Status_s* e;
      for (e = x->Status; e; e = (struct zx_gl_Status_s*)e->gg.g.n)
	  p = zx_ENC_SO_gl_Status(c, e, p);
  }
  {
      struct zx_gl_Data_s* e;
      for (e = x->Data; e; e = (struct zx_gl_Data_s*)e->gg.g.n)
	  p = zx_ENC_SO_gl_Data(c, e, p);
  }
  {
      struct zx_gl_Extension_s* e;
      for (e = x->Extension; e; e = (struct zx_gl_Extension_s*)e->gg.g.n)
	  p = zx_ENC_SO_gl_Extension(c, e, p);
  }

  p = zx_enc_so_unknown_elems_and_content(c, p, &x->gg);
  
#if 1 /* NORMALMODE */
  ZX_OUT_CLOSE_TAG(p, "</gl:QueryResponse>");
  zx_pop_seen(pop_seen);
#else
  /* root node has no end tag either */
#endif
  ENC_LEN_DEBUG(x, "gl:QueryResponse", p-enc_base);
  return p;
}

/* FUNC(zx_ENC_WO_gl_QueryResponse) */

/* Render element into string. The XML attributes and elements are
 * processed in wire order by chasing wo pointers. This is what you want for
 * validating signatures on other people's XML documents. */

/* Called by: */
char* zx_ENC_WO_gl_QueryResponse(struct zx_ctx* c, struct zx_gl_QueryResponse_s* x, char* p )
{
  struct zx_elem_s* kid;
  struct zx_ns_s* pop_seen = 0;
  ENC_LEN_DEBUG_BASE;
#if 1 /* NORMALMODE */
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

  p = zx_enc_seen(p, pop_seen); 
  p = zx_attr_wo_enc(p, x->id, "id=\"", sizeof("id=\"")-1);
  p = zx_attr_wo_enc(p, x->itemIDRef, "itemIDRef=\"", sizeof("itemIDRef=\"")-1);
  p = zx_attr_wo_enc(p, x->timeStamp, "timeStamp=\"", sizeof("timeStamp=\"")-1);

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
  ENC_LEN_DEBUG(x, "gl:QueryResponse", p-enc_base);
  return p;
}

/* FUNC(zx_EASY_ENC_SO_gl_QueryResponse) */

/* Called by: */
struct zx_str* zx_EASY_ENC_SO_gl_QueryResponse(struct zx_ctx* c, struct zx_gl_QueryResponse_s* x )
{
  int len;
  char* buf;
  c->ns_tab = ZX_ALLOC(c, sizeof(zx_ns_tab));
  memcpy(c->ns_tab, zx_ns_tab, sizeof(zx_ns_tab));
  len = zx_LEN_SO_gl_QueryResponse(c, x );
  buf = ZX_ALLOC(c, len+1);
  return zx_easy_enc_common(c, zx_ENC_SO_gl_QueryResponse(c, x, buf ), buf, len);
}

/* FUNC(zx_EASY_ENC_WO_gl_QueryResponse) */

/* Called by: */
struct zx_str* zx_EASY_ENC_WO_gl_QueryResponse(struct zx_ctx* c, struct zx_gl_QueryResponse_s* x )
{
  int len;
  char* buf;
  c->ns_tab = ZX_ALLOC(c, sizeof(zx_ns_tab));
  memcpy(c->ns_tab, zx_ns_tab, sizeof(zx_ns_tab));
  len = zx_LEN_WO_gl_QueryResponse(c, x );
  buf = ZX_ALLOC(c, len+1);
  return zx_easy_enc_common(c, zx_ENC_WO_gl_QueryResponse(c, x, buf ), buf, len);
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

#define EL_NAME   gl_RefItem
#define EL_STRUCT zx_gl_RefItem_s
#define EL_NS     gl
#define EL_TAG    RefItem

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

/* FUNC(zx_LEN_SO_gl_RefItem) */

/* Compute length of an element (and its subelements). The XML attributes
 * and elements are processed in schema order. */

/* Called by: */
int zx_LEN_SO_gl_RefItem(struct zx_ctx* c, struct zx_gl_RefItem_s* x )
{
  struct zx_ns_s* pop_seen = 0;
  struct zx_elem_s* se MAYBE_UNUSED;
#if 1 /* NORMALMODE */
  /* *** in simple_elem case should output ns prefix from ns node. */
  int len = sizeof("<gl:RefItem")-1 + 1 + sizeof("</gl:RefItem>")-1;
  if (c->inc_ns_len)
    len += zx_len_inc_ns(c, &pop_seen);
  len += zx_len_xmlns_if_not_seen(c, zx_ns_tab+zx_xmlns_ix_gl, &pop_seen);

  len += zx_attr_so_len(x->ItemIDRef, sizeof("ItemIDRef")-1);
  len += zx_attr_so_len(x->subscriptionID, sizeof("subscriptionID")-1);

#else
  /* root node has no begin tag */
  int len = 0;
#endif
  


  len += zx_len_so_common(c, &x->gg);
  zx_pop_seen(pop_seen);
  ENC_LEN_DEBUG(x, "gl:RefItem", len);
  return len;
}

/* FUNC(zx_LEN_WO_gl_RefItem) */

/* Compute length of an element (and its subelements). The XML attributes
 * and elements are processed in wire order and no assumptions
 * are made about namespace prefixes. */

/* Called by: */
int zx_LEN_WO_gl_RefItem(struct zx_ctx* c, struct zx_gl_RefItem_s* x )
{
  struct zx_ns_s* pop_seen = 0;
  struct zx_elem_s* se MAYBE_UNUSED;
#if 1 /* NORMALMODE */
  int len = 1 + sizeof("RefItem")-1 + 1 + 2 + sizeof("RefItem")-1 + 1;
  
  if (x->gg.g.ns && x->gg.g.ns->prefix_len)
    len += (x->gg.g.ns->prefix_len + 1) * 2;
  if (c->inc_ns_len)
    len += zx_len_inc_ns(c, &pop_seen);
  len += zx_len_xmlns_if_not_seen(c, x->gg.g.ns, &pop_seen);

  len += zx_attr_wo_len(x->ItemIDRef, sizeof("ItemIDRef")-1);
  len += zx_attr_wo_len(x->subscriptionID, sizeof("subscriptionID")-1);

#else
  /* root node has no begin tag */
  int len = 0;
#endif
  


  len += zx_len_wo_common(c, &x->gg); 
  zx_pop_seen(pop_seen);
  ENC_LEN_DEBUG(x, "gl:RefItem", len);
  return len;
}

/* FUNC(zx_ENC_SO_gl_RefItem) */

/* Render element into string. The XML attributes and elements are
 * processed in schema order. This is what you generally want for
 * rendering new data structure to a string. The wo pointers are not used. */

/* Called by: */
char* zx_ENC_SO_gl_RefItem(struct zx_ctx* c, struct zx_gl_RefItem_s* x, char* p )
{
  struct zx_elem_s* se MAYBE_UNUSED;
  struct zx_ns_s* pop_seen = 0;
  ENC_LEN_DEBUG_BASE;
#if 1 /* NORMALMODE */
  /* *** in simple_elem case should output ns prefix from ns node. */
  ZX_OUT_TAG(p, "<gl:RefItem");
  if (c->inc_ns)
    p = zx_enc_inc_ns(c, p, &pop_seen);
  p = zx_enc_xmlns_if_not_seen(c, p, zx_ns_tab+zx_xmlns_ix_gl, &pop_seen);

  p = zx_attr_so_enc(p, x->ItemIDRef, " ItemIDRef=\"", sizeof(" ItemIDRef=\"")-1);
  p = zx_attr_so_enc(p, x->subscriptionID, " subscriptionID=\"", sizeof(" subscriptionID=\"")-1);

  p = zx_enc_unknown_attrs(p, x->gg.any_attr);
#else
  /* root node has no begin tag */
#endif
  

  p = zx_enc_so_unknown_elems_and_content(c, p, &x->gg);
  
#if 1 /* NORMALMODE */
  ZX_OUT_CLOSE_TAG(p, "</gl:RefItem>");
  zx_pop_seen(pop_seen);
#else
  /* root node has no end tag either */
#endif
  ENC_LEN_DEBUG(x, "gl:RefItem", p-enc_base);
  return p;
}

/* FUNC(zx_ENC_WO_gl_RefItem) */

/* Render element into string. The XML attributes and elements are
 * processed in wire order by chasing wo pointers. This is what you want for
 * validating signatures on other people's XML documents. */

/* Called by: */
char* zx_ENC_WO_gl_RefItem(struct zx_ctx* c, struct zx_gl_RefItem_s* x, char* p )
{
  struct zx_elem_s* kid;
  struct zx_ns_s* pop_seen = 0;
  ENC_LEN_DEBUG_BASE;
#if 1 /* NORMALMODE */
  char* q;
  char* qq;
  ZX_OUT_CH(p, '<');
  q = p;
  if (x->gg.g.ns && x->gg.g.ns->prefix_len) {
    ZX_OUT_MEM(p, x->gg.g.ns->prefix, x->gg.g.ns->prefix_len);
    ZX_OUT_CH(p, ':');
  }
  ZX_OUT_MEM(p, "RefItem", sizeof("RefItem")-1);
  qq = p;

  /* *** sort the namespaces */
  if (c->inc_ns)
    zx_add_inc_ns(c, &pop_seen);
  zx_add_xmlns_if_not_seen(c, x->gg.g.ns, &pop_seen);

  p = zx_enc_seen(p, pop_seen); 
  p = zx_attr_wo_enc(p, x->ItemIDRef, "ItemIDRef=\"", sizeof("ItemIDRef=\"")-1);
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
  ENC_LEN_DEBUG(x, "gl:RefItem", p-enc_base);
  return p;
}

/* FUNC(zx_EASY_ENC_SO_gl_RefItem) */

/* Called by: */
struct zx_str* zx_EASY_ENC_SO_gl_RefItem(struct zx_ctx* c, struct zx_gl_RefItem_s* x )
{
  int len;
  char* buf;
  c->ns_tab = ZX_ALLOC(c, sizeof(zx_ns_tab));
  memcpy(c->ns_tab, zx_ns_tab, sizeof(zx_ns_tab));
  len = zx_LEN_SO_gl_RefItem(c, x );
  buf = ZX_ALLOC(c, len+1);
  return zx_easy_enc_common(c, zx_ENC_SO_gl_RefItem(c, x, buf ), buf, len);
}

/* FUNC(zx_EASY_ENC_WO_gl_RefItem) */

/* Called by: */
struct zx_str* zx_EASY_ENC_WO_gl_RefItem(struct zx_ctx* c, struct zx_gl_RefItem_s* x )
{
  int len;
  char* buf;
  c->ns_tab = ZX_ALLOC(c, sizeof(zx_ns_tab));
  memcpy(c->ns_tab, zx_ns_tab, sizeof(zx_ns_tab));
  len = zx_LEN_WO_gl_RefItem(c, x );
  buf = ZX_ALLOC(c, len+1);
  return zx_easy_enc_common(c, zx_ENC_WO_gl_RefItem(c, x, buf ), buf, len);
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

#define EL_NAME   gl_ResourceID
#define EL_STRUCT zx_gl_ResourceID_s
#define EL_NS     gl
#define EL_TAG    ResourceID

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

/* FUNC(zx_LEN_SO_gl_ResourceID) */

/* Compute length of an element (and its subelements). The XML attributes
 * and elements are processed in schema order. */

/* Called by: */
int zx_LEN_SO_gl_ResourceID(struct zx_ctx* c, struct zx_gl_ResourceID_s* x )
{
  struct zx_ns_s* pop_seen = 0;
  struct zx_elem_s* se MAYBE_UNUSED;
#if 1 /* NORMALMODE */
  /* *** in simple_elem case should output ns prefix from ns node. */
  int len = sizeof("<gl:ResourceID")-1 + 1 + sizeof("</gl:ResourceID>")-1;
  if (c->inc_ns_len)
    len += zx_len_inc_ns(c, &pop_seen);
  len += zx_len_xmlns_if_not_seen(c, zx_ns_tab+zx_xmlns_ix_gl, &pop_seen);

  len += zx_attr_so_len(x->id, sizeof("id")-1);

#else
  /* root node has no begin tag */
  int len = 0;
#endif
  


  len += zx_len_so_common(c, &x->gg);
  zx_pop_seen(pop_seen);
  ENC_LEN_DEBUG(x, "gl:ResourceID", len);
  return len;
}

/* FUNC(zx_LEN_WO_gl_ResourceID) */

/* Compute length of an element (and its subelements). The XML attributes
 * and elements are processed in wire order and no assumptions
 * are made about namespace prefixes. */

/* Called by: */
int zx_LEN_WO_gl_ResourceID(struct zx_ctx* c, struct zx_gl_ResourceID_s* x )
{
  struct zx_ns_s* pop_seen = 0;
  struct zx_elem_s* se MAYBE_UNUSED;
#if 1 /* NORMALMODE */
  int len = 1 + sizeof("ResourceID")-1 + 1 + 2 + sizeof("ResourceID")-1 + 1;
  
  if (x->gg.g.ns && x->gg.g.ns->prefix_len)
    len += (x->gg.g.ns->prefix_len + 1) * 2;
  if (c->inc_ns_len)
    len += zx_len_inc_ns(c, &pop_seen);
  len += zx_len_xmlns_if_not_seen(c, x->gg.g.ns, &pop_seen);

  len += zx_attr_wo_len(x->id, sizeof("id")-1);

#else
  /* root node has no begin tag */
  int len = 0;
#endif
  


  len += zx_len_wo_common(c, &x->gg); 
  zx_pop_seen(pop_seen);
  ENC_LEN_DEBUG(x, "gl:ResourceID", len);
  return len;
}

/* FUNC(zx_ENC_SO_gl_ResourceID) */

/* Render element into string. The XML attributes and elements are
 * processed in schema order. This is what you generally want for
 * rendering new data structure to a string. The wo pointers are not used. */

/* Called by: */
char* zx_ENC_SO_gl_ResourceID(struct zx_ctx* c, struct zx_gl_ResourceID_s* x, char* p )
{
  struct zx_elem_s* se MAYBE_UNUSED;
  struct zx_ns_s* pop_seen = 0;
  ENC_LEN_DEBUG_BASE;
#if 1 /* NORMALMODE */
  /* *** in simple_elem case should output ns prefix from ns node. */
  ZX_OUT_TAG(p, "<gl:ResourceID");
  if (c->inc_ns)
    p = zx_enc_inc_ns(c, p, &pop_seen);
  p = zx_enc_xmlns_if_not_seen(c, p, zx_ns_tab+zx_xmlns_ix_gl, &pop_seen);

  p = zx_attr_so_enc(p, x->id, " id=\"", sizeof(" id=\"")-1);

  p = zx_enc_unknown_attrs(p, x->gg.any_attr);
#else
  /* root node has no begin tag */
#endif
  

  p = zx_enc_so_unknown_elems_and_content(c, p, &x->gg);
  
#if 1 /* NORMALMODE */
  ZX_OUT_CLOSE_TAG(p, "</gl:ResourceID>");
  zx_pop_seen(pop_seen);
#else
  /* root node has no end tag either */
#endif
  ENC_LEN_DEBUG(x, "gl:ResourceID", p-enc_base);
  return p;
}

/* FUNC(zx_ENC_WO_gl_ResourceID) */

/* Render element into string. The XML attributes and elements are
 * processed in wire order by chasing wo pointers. This is what you want for
 * validating signatures on other people's XML documents. */

/* Called by: */
char* zx_ENC_WO_gl_ResourceID(struct zx_ctx* c, struct zx_gl_ResourceID_s* x, char* p )
{
  struct zx_elem_s* kid;
  struct zx_ns_s* pop_seen = 0;
  ENC_LEN_DEBUG_BASE;
#if 1 /* NORMALMODE */
  char* q;
  char* qq;
  ZX_OUT_CH(p, '<');
  q = p;
  if (x->gg.g.ns && x->gg.g.ns->prefix_len) {
    ZX_OUT_MEM(p, x->gg.g.ns->prefix, x->gg.g.ns->prefix_len);
    ZX_OUT_CH(p, ':');
  }
  ZX_OUT_MEM(p, "ResourceID", sizeof("ResourceID")-1);
  qq = p;

  /* *** sort the namespaces */
  if (c->inc_ns)
    zx_add_inc_ns(c, &pop_seen);
  zx_add_xmlns_if_not_seen(c, x->gg.g.ns, &pop_seen);

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
  ENC_LEN_DEBUG(x, "gl:ResourceID", p-enc_base);
  return p;
}

/* FUNC(zx_EASY_ENC_SO_gl_ResourceID) */

/* Called by: */
struct zx_str* zx_EASY_ENC_SO_gl_ResourceID(struct zx_ctx* c, struct zx_gl_ResourceID_s* x )
{
  int len;
  char* buf;
  c->ns_tab = ZX_ALLOC(c, sizeof(zx_ns_tab));
  memcpy(c->ns_tab, zx_ns_tab, sizeof(zx_ns_tab));
  len = zx_LEN_SO_gl_ResourceID(c, x );
  buf = ZX_ALLOC(c, len+1);
  return zx_easy_enc_common(c, zx_ENC_SO_gl_ResourceID(c, x, buf ), buf, len);
}

/* FUNC(zx_EASY_ENC_WO_gl_ResourceID) */

/* Called by: */
struct zx_str* zx_EASY_ENC_WO_gl_ResourceID(struct zx_ctx* c, struct zx_gl_ResourceID_s* x )
{
  int len;
  char* buf;
  c->ns_tab = ZX_ALLOC(c, sizeof(zx_ns_tab));
  memcpy(c->ns_tab, zx_ns_tab, sizeof(zx_ns_tab));
  len = zx_LEN_WO_gl_ResourceID(c, x );
  buf = ZX_ALLOC(c, len+1);
  return zx_easy_enc_common(c, zx_ENC_WO_gl_ResourceID(c, x, buf ), buf, len);
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

#define EL_NAME   gl_Status
#define EL_STRUCT zx_gl_Status_s
#define EL_NS     gl
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

/* FUNC(zx_LEN_SO_gl_Status) */

/* Compute length of an element (and its subelements). The XML attributes
 * and elements are processed in schema order. */

/* Called by: */
int zx_LEN_SO_gl_Status(struct zx_ctx* c, struct zx_gl_Status_s* x )
{
  struct zx_ns_s* pop_seen = 0;
  struct zx_elem_s* se MAYBE_UNUSED;
#if 1 /* NORMALMODE */
  /* *** in simple_elem case should output ns prefix from ns node. */
  int len = sizeof("<gl:Status")-1 + 1 + sizeof("</gl:Status>")-1;
  if (c->inc_ns_len)
    len += zx_len_inc_ns(c, &pop_seen);
  len += zx_len_xmlns_if_not_seen(c, zx_ns_tab+zx_xmlns_ix_gl, &pop_seen);

  len += zx_attr_so_len(x->code, sizeof("code")-1);
  len += zx_attr_so_len(x->comment, sizeof("comment")-1);
  len += zx_attr_so_len(x->ref, sizeof("ref")-1);

#else
  /* root node has no begin tag */
  int len = 0;
#endif
  
  {
      struct zx_gl_Status_s* e;
      for (e = x->Status; e; e = (struct zx_gl_Status_s*)e->gg.g.n)
	  len += zx_LEN_SO_gl_Status(c, e);
  }


  len += zx_len_so_common(c, &x->gg);
  zx_pop_seen(pop_seen);
  ENC_LEN_DEBUG(x, "gl:Status", len);
  return len;
}

/* FUNC(zx_LEN_WO_gl_Status) */

/* Compute length of an element (and its subelements). The XML attributes
 * and elements are processed in wire order and no assumptions
 * are made about namespace prefixes. */

/* Called by: */
int zx_LEN_WO_gl_Status(struct zx_ctx* c, struct zx_gl_Status_s* x )
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

  len += zx_attr_wo_len(x->code, sizeof("code")-1);
  len += zx_attr_wo_len(x->comment, sizeof("comment")-1);
  len += zx_attr_wo_len(x->ref, sizeof("ref")-1);

#else
  /* root node has no begin tag */
  int len = 0;
#endif
  
  {
      struct zx_gl_Status_s* e;
      for (e = x->Status; e; e = (struct zx_gl_Status_s*)e->gg.g.n)
	  len += zx_LEN_WO_gl_Status(c, e);
  }


  len += zx_len_wo_common(c, &x->gg); 
  zx_pop_seen(pop_seen);
  ENC_LEN_DEBUG(x, "gl:Status", len);
  return len;
}

/* FUNC(zx_ENC_SO_gl_Status) */

/* Render element into string. The XML attributes and elements are
 * processed in schema order. This is what you generally want for
 * rendering new data structure to a string. The wo pointers are not used. */

/* Called by: */
char* zx_ENC_SO_gl_Status(struct zx_ctx* c, struct zx_gl_Status_s* x, char* p )
{
  struct zx_elem_s* se MAYBE_UNUSED;
  struct zx_ns_s* pop_seen = 0;
  ENC_LEN_DEBUG_BASE;
#if 1 /* NORMALMODE */
  /* *** in simple_elem case should output ns prefix from ns node. */
  ZX_OUT_TAG(p, "<gl:Status");
  if (c->inc_ns)
    p = zx_enc_inc_ns(c, p, &pop_seen);
  p = zx_enc_xmlns_if_not_seen(c, p, zx_ns_tab+zx_xmlns_ix_gl, &pop_seen);

  p = zx_attr_so_enc(p, x->code, " code=\"", sizeof(" code=\"")-1);
  p = zx_attr_so_enc(p, x->comment, " comment=\"", sizeof(" comment=\"")-1);
  p = zx_attr_so_enc(p, x->ref, " ref=\"", sizeof(" ref=\"")-1);

  p = zx_enc_unknown_attrs(p, x->gg.any_attr);
#else
  /* root node has no begin tag */
#endif
  
  {
      struct zx_gl_Status_s* e;
      for (e = x->Status; e; e = (struct zx_gl_Status_s*)e->gg.g.n)
	  p = zx_ENC_SO_gl_Status(c, e, p);
  }

  p = zx_enc_so_unknown_elems_and_content(c, p, &x->gg);
  
#if 1 /* NORMALMODE */
  ZX_OUT_CLOSE_TAG(p, "</gl:Status>");
  zx_pop_seen(pop_seen);
#else
  /* root node has no end tag either */
#endif
  ENC_LEN_DEBUG(x, "gl:Status", p-enc_base);
  return p;
}

/* FUNC(zx_ENC_WO_gl_Status) */

/* Render element into string. The XML attributes and elements are
 * processed in wire order by chasing wo pointers. This is what you want for
 * validating signatures on other people's XML documents. */

/* Called by: */
char* zx_ENC_WO_gl_Status(struct zx_ctx* c, struct zx_gl_Status_s* x, char* p )
{
  struct zx_elem_s* kid;
  struct zx_ns_s* pop_seen = 0;
  ENC_LEN_DEBUG_BASE;
#if 1 /* NORMALMODE */
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
  zx_add_xmlns_if_not_seen(c, x->gg.g.ns, &pop_seen);

  p = zx_enc_seen(p, pop_seen); 
  p = zx_attr_wo_enc(p, x->code, "code=\"", sizeof("code=\"")-1);
  p = zx_attr_wo_enc(p, x->comment, "comment=\"", sizeof("comment=\"")-1);
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
  ENC_LEN_DEBUG(x, "gl:Status", p-enc_base);
  return p;
}

/* FUNC(zx_EASY_ENC_SO_gl_Status) */

/* Called by: */
struct zx_str* zx_EASY_ENC_SO_gl_Status(struct zx_ctx* c, struct zx_gl_Status_s* x )
{
  int len;
  char* buf;
  c->ns_tab = ZX_ALLOC(c, sizeof(zx_ns_tab));
  memcpy(c->ns_tab, zx_ns_tab, sizeof(zx_ns_tab));
  len = zx_LEN_SO_gl_Status(c, x );
  buf = ZX_ALLOC(c, len+1);
  return zx_easy_enc_common(c, zx_ENC_SO_gl_Status(c, x, buf ), buf, len);
}

/* FUNC(zx_EASY_ENC_WO_gl_Status) */

/* Called by: */
struct zx_str* zx_EASY_ENC_WO_gl_Status(struct zx_ctx* c, struct zx_gl_Status_s* x )
{
  int len;
  char* buf;
  c->ns_tab = ZX_ALLOC(c, sizeof(zx_ns_tab));
  memcpy(c->ns_tab, zx_ns_tab, sizeof(zx_ns_tab));
  len = zx_LEN_WO_gl_Status(c, x );
  buf = ZX_ALLOC(c, len+1);
  return zx_easy_enc_common(c, zx_ENC_WO_gl_Status(c, x, buf ), buf, len);
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

#define EL_NAME   gl_Subscription
#define EL_STRUCT zx_gl_Subscription_s
#define EL_NS     gl
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

/* FUNC(zx_LEN_SO_gl_Subscription) */

/* Compute length of an element (and its subelements). The XML attributes
 * and elements are processed in schema order. */

/* Called by: */
int zx_LEN_SO_gl_Subscription(struct zx_ctx* c, struct zx_gl_Subscription_s* x )
{
  struct zx_ns_s* pop_seen = 0;
  struct zx_elem_s* se MAYBE_UNUSED;
#if 1 /* NORMALMODE */
  /* *** in simple_elem case should output ns prefix from ns node. */
  int len = sizeof("<gl:Subscription")-1 + 1 + sizeof("</gl:Subscription>")-1;
  if (c->inc_ns_len)
    len += zx_len_inc_ns(c, &pop_seen);
  len += zx_len_xmlns_if_not_seen(c, zx_ns_tab+zx_xmlns_ix_gl, &pop_seen);

  len += zx_attr_so_len(x->expires, sizeof("expires")-1);
  len += zx_attr_so_len(x->id, sizeof("id")-1);
  len += zx_attr_so_len(x->includeData, sizeof("includeData")-1);
  len += zx_attr_so_len(x->starts, sizeof("starts")-1);
  len += zx_attr_so_len(x->subscriptionID, sizeof("subscriptionID")-1);

#else
  /* root node has no begin tag */
  int len = 0;
#endif
  
  {
      struct zx_gl_ItemSelection_s* e;
      for (e = x->ItemSelection; e; e = (struct zx_gl_ItemSelection_s*)e->gg.g.n)
	  len += zx_LEN_SO_gl_ItemSelection(c, e);
  }
  {
      struct zx_gl_RefItem_s* e;
      for (e = x->RefItem; e; e = (struct zx_gl_RefItem_s*)e->gg.g.n)
	  len += zx_LEN_SO_gl_RefItem(c, e);
  }
  {
      struct zx_gl_NotifyTo_s* e;
      for (e = x->NotifyTo; e; e = (struct zx_gl_NotifyTo_s*)e->gg.g.n)
	  len += zx_LEN_SO_gl_NotifyTo(c, e);
  }
  {
      struct zx_gl_NotifyAdminTo_s* e;
      for (e = x->NotifyAdminTo; e; e = (struct zx_gl_NotifyAdminTo_s*)e->gg.g.n)
	  len += zx_LEN_SO_gl_NotifyAdminTo(c, e);
  }
  for (se = x->Aggregation; se; se = (struct zx_elem_s*)se->g.n)
    len += zx_LEN_SO_simple_elem(c,se, sizeof("gl:Aggregation")-1, zx_ns_tab+zx_xmlns_ix_gl);
  {
      struct zx_gl_Trigger_s* e;
      for (e = x->Trigger; e; e = (struct zx_gl_Trigger_s*)e->gg.g.n)
	  len += zx_LEN_SO_gl_Trigger(c, e);
  }
  {
      struct zx_gl_Extension_s* e;
      for (e = x->Extension; e; e = (struct zx_gl_Extension_s*)e->gg.g.n)
	  len += zx_LEN_SO_gl_Extension(c, e);
  }


  len += zx_len_so_common(c, &x->gg);
  zx_pop_seen(pop_seen);
  ENC_LEN_DEBUG(x, "gl:Subscription", len);
  return len;
}

/* FUNC(zx_LEN_WO_gl_Subscription) */

/* Compute length of an element (and its subelements). The XML attributes
 * and elements are processed in wire order and no assumptions
 * are made about namespace prefixes. */

/* Called by: */
int zx_LEN_WO_gl_Subscription(struct zx_ctx* c, struct zx_gl_Subscription_s* x )
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

  len += zx_attr_wo_len(x->expires, sizeof("expires")-1);
  len += zx_attr_wo_len(x->id, sizeof("id")-1);
  len += zx_attr_wo_len(x->includeData, sizeof("includeData")-1);
  len += zx_attr_wo_len(x->starts, sizeof("starts")-1);
  len += zx_attr_wo_len(x->subscriptionID, sizeof("subscriptionID")-1);

#else
  /* root node has no begin tag */
  int len = 0;
#endif
  
  {
      struct zx_gl_ItemSelection_s* e;
      for (e = x->ItemSelection; e; e = (struct zx_gl_ItemSelection_s*)e->gg.g.n)
	  len += zx_LEN_WO_gl_ItemSelection(c, e);
  }
  {
      struct zx_gl_RefItem_s* e;
      for (e = x->RefItem; e; e = (struct zx_gl_RefItem_s*)e->gg.g.n)
	  len += zx_LEN_WO_gl_RefItem(c, e);
  }
  {
      struct zx_gl_NotifyTo_s* e;
      for (e = x->NotifyTo; e; e = (struct zx_gl_NotifyTo_s*)e->gg.g.n)
	  len += zx_LEN_WO_gl_NotifyTo(c, e);
  }
  {
      struct zx_gl_NotifyAdminTo_s* e;
      for (e = x->NotifyAdminTo; e; e = (struct zx_gl_NotifyAdminTo_s*)e->gg.g.n)
	  len += zx_LEN_WO_gl_NotifyAdminTo(c, e);
  }
  for (se = x->Aggregation; se; se = (struct zx_elem_s*)se->g.n)
    len += zx_LEN_WO_simple_elem(c, se, sizeof("Aggregation")-1);
  {
      struct zx_gl_Trigger_s* e;
      for (e = x->Trigger; e; e = (struct zx_gl_Trigger_s*)e->gg.g.n)
	  len += zx_LEN_WO_gl_Trigger(c, e);
  }
  {
      struct zx_gl_Extension_s* e;
      for (e = x->Extension; e; e = (struct zx_gl_Extension_s*)e->gg.g.n)
	  len += zx_LEN_WO_gl_Extension(c, e);
  }


  len += zx_len_wo_common(c, &x->gg); 
  zx_pop_seen(pop_seen);
  ENC_LEN_DEBUG(x, "gl:Subscription", len);
  return len;
}

/* FUNC(zx_ENC_SO_gl_Subscription) */

/* Render element into string. The XML attributes and elements are
 * processed in schema order. This is what you generally want for
 * rendering new data structure to a string. The wo pointers are not used. */

/* Called by: */
char* zx_ENC_SO_gl_Subscription(struct zx_ctx* c, struct zx_gl_Subscription_s* x, char* p )
{
  struct zx_elem_s* se MAYBE_UNUSED;
  struct zx_ns_s* pop_seen = 0;
  ENC_LEN_DEBUG_BASE;
#if 1 /* NORMALMODE */
  /* *** in simple_elem case should output ns prefix from ns node. */
  ZX_OUT_TAG(p, "<gl:Subscription");
  if (c->inc_ns)
    p = zx_enc_inc_ns(c, p, &pop_seen);
  p = zx_enc_xmlns_if_not_seen(c, p, zx_ns_tab+zx_xmlns_ix_gl, &pop_seen);

  p = zx_attr_so_enc(p, x->expires, " expires=\"", sizeof(" expires=\"")-1);
  p = zx_attr_so_enc(p, x->id, " id=\"", sizeof(" id=\"")-1);
  p = zx_attr_so_enc(p, x->includeData, " includeData=\"", sizeof(" includeData=\"")-1);
  p = zx_attr_so_enc(p, x->starts, " starts=\"", sizeof(" starts=\"")-1);
  p = zx_attr_so_enc(p, x->subscriptionID, " subscriptionID=\"", sizeof(" subscriptionID=\"")-1);

  p = zx_enc_unknown_attrs(p, x->gg.any_attr);
#else
  /* root node has no begin tag */
#endif
  
  {
      struct zx_gl_ItemSelection_s* e;
      for (e = x->ItemSelection; e; e = (struct zx_gl_ItemSelection_s*)e->gg.g.n)
	  p = zx_ENC_SO_gl_ItemSelection(c, e, p);
  }
  {
      struct zx_gl_RefItem_s* e;
      for (e = x->RefItem; e; e = (struct zx_gl_RefItem_s*)e->gg.g.n)
	  p = zx_ENC_SO_gl_RefItem(c, e, p);
  }
  {
      struct zx_gl_NotifyTo_s* e;
      for (e = x->NotifyTo; e; e = (struct zx_gl_NotifyTo_s*)e->gg.g.n)
	  p = zx_ENC_SO_gl_NotifyTo(c, e, p);
  }
  {
      struct zx_gl_NotifyAdminTo_s* e;
      for (e = x->NotifyAdminTo; e; e = (struct zx_gl_NotifyAdminTo_s*)e->gg.g.n)
	  p = zx_ENC_SO_gl_NotifyAdminTo(c, e, p);
  }
  for (se = x->Aggregation; se; se = (struct zx_elem_s*)se->g.n)
    p = zx_ENC_SO_simple_elem(c, se, p, "gl:Aggregation", sizeof("gl:Aggregation")-1, zx_ns_tab+zx_xmlns_ix_gl);
  {
      struct zx_gl_Trigger_s* e;
      for (e = x->Trigger; e; e = (struct zx_gl_Trigger_s*)e->gg.g.n)
	  p = zx_ENC_SO_gl_Trigger(c, e, p);
  }
  {
      struct zx_gl_Extension_s* e;
      for (e = x->Extension; e; e = (struct zx_gl_Extension_s*)e->gg.g.n)
	  p = zx_ENC_SO_gl_Extension(c, e, p);
  }

  p = zx_enc_so_unknown_elems_and_content(c, p, &x->gg);
  
#if 1 /* NORMALMODE */
  ZX_OUT_CLOSE_TAG(p, "</gl:Subscription>");
  zx_pop_seen(pop_seen);
#else
  /* root node has no end tag either */
#endif
  ENC_LEN_DEBUG(x, "gl:Subscription", p-enc_base);
  return p;
}

/* FUNC(zx_ENC_WO_gl_Subscription) */

/* Render element into string. The XML attributes and elements are
 * processed in wire order by chasing wo pointers. This is what you want for
 * validating signatures on other people's XML documents. */

/* Called by: */
char* zx_ENC_WO_gl_Subscription(struct zx_ctx* c, struct zx_gl_Subscription_s* x, char* p )
{
  struct zx_elem_s* kid;
  struct zx_ns_s* pop_seen = 0;
  ENC_LEN_DEBUG_BASE;
#if 1 /* NORMALMODE */
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
  p = zx_attr_wo_enc(p, x->expires, "expires=\"", sizeof("expires=\"")-1);
  p = zx_attr_wo_enc(p, x->id, "id=\"", sizeof("id=\"")-1);
  p = zx_attr_wo_enc(p, x->includeData, "includeData=\"", sizeof("includeData=\"")-1);
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
  ENC_LEN_DEBUG(x, "gl:Subscription", p-enc_base);
  return p;
}

/* FUNC(zx_EASY_ENC_SO_gl_Subscription) */

/* Called by: */
struct zx_str* zx_EASY_ENC_SO_gl_Subscription(struct zx_ctx* c, struct zx_gl_Subscription_s* x )
{
  int len;
  char* buf;
  c->ns_tab = ZX_ALLOC(c, sizeof(zx_ns_tab));
  memcpy(c->ns_tab, zx_ns_tab, sizeof(zx_ns_tab));
  len = zx_LEN_SO_gl_Subscription(c, x );
  buf = ZX_ALLOC(c, len+1);
  return zx_easy_enc_common(c, zx_ENC_SO_gl_Subscription(c, x, buf ), buf, len);
}

/* FUNC(zx_EASY_ENC_WO_gl_Subscription) */

/* Called by: */
struct zx_str* zx_EASY_ENC_WO_gl_Subscription(struct zx_ctx* c, struct zx_gl_Subscription_s* x )
{
  int len;
  char* buf;
  c->ns_tab = ZX_ALLOC(c, sizeof(zx_ns_tab));
  memcpy(c->ns_tab, zx_ns_tab, sizeof(zx_ns_tab));
  len = zx_LEN_WO_gl_Subscription(c, x );
  buf = ZX_ALLOC(c, len+1);
  return zx_easy_enc_common(c, zx_ENC_WO_gl_Subscription(c, x, buf ), buf, len);
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

#define EL_NAME   gl_Trigger
#define EL_STRUCT zx_gl_Trigger_s
#define EL_NS     gl
#define EL_TAG    Trigger

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

/* FUNC(zx_LEN_SO_gl_Trigger) */

/* Compute length of an element (and its subelements). The XML attributes
 * and elements are processed in schema order. */

/* Called by: */
int zx_LEN_SO_gl_Trigger(struct zx_ctx* c, struct zx_gl_Trigger_s* x )
{
  struct zx_ns_s* pop_seen = 0;
  struct zx_elem_s* se MAYBE_UNUSED;
#if 1 /* NORMALMODE */
  /* *** in simple_elem case should output ns prefix from ns node. */
  int len = sizeof("<gl:Trigger")-1 + 1 + sizeof("</gl:Trigger>")-1;
  if (c->inc_ns_len)
    len += zx_len_inc_ns(c, &pop_seen);
  len += zx_len_xmlns_if_not_seen(c, zx_ns_tab+zx_xmlns_ix_gl, &pop_seen);


#else
  /* root node has no begin tag */
  int len = 0;
#endif
  
  for (se = x->Granularity; se; se = (struct zx_elem_s*)se->g.n)
    len += zx_LEN_SO_simple_elem(c,se, sizeof("gl:Granularity")-1, zx_ns_tab+zx_xmlns_ix_gl);
  for (se = x->Interval; se; se = (struct zx_elem_s*)se->g.n)
    len += zx_LEN_SO_simple_elem(c,se, sizeof("gl:Interval")-1, zx_ns_tab+zx_xmlns_ix_gl);
  {
      struct zx_gl_ms_action_s* e;
      for (e = x->ms_action; e; e = (struct zx_gl_ms_action_s*)e->gg.g.n)
	  len += zx_LEN_SO_gl_ms_action(c, e);
  }
  {
      struct zx_gl_ChangeArea_s* e;
      for (e = x->ChangeArea; e; e = (struct zx_gl_ChangeArea_s*)e->gg.g.n)
	  len += zx_LEN_SO_gl_ChangeArea(c, e);
  }
  {
      struct zx_gl_Extension_s* e;
      for (e = x->Extension; e; e = (struct zx_gl_Extension_s*)e->gg.g.n)
	  len += zx_LEN_SO_gl_Extension(c, e);
  }


  len += zx_len_so_common(c, &x->gg);
  zx_pop_seen(pop_seen);
  ENC_LEN_DEBUG(x, "gl:Trigger", len);
  return len;
}

/* FUNC(zx_LEN_WO_gl_Trigger) */

/* Compute length of an element (and its subelements). The XML attributes
 * and elements are processed in wire order and no assumptions
 * are made about namespace prefixes. */

/* Called by: */
int zx_LEN_WO_gl_Trigger(struct zx_ctx* c, struct zx_gl_Trigger_s* x )
{
  struct zx_ns_s* pop_seen = 0;
  struct zx_elem_s* se MAYBE_UNUSED;
#if 1 /* NORMALMODE */
  int len = 1 + sizeof("Trigger")-1 + 1 + 2 + sizeof("Trigger")-1 + 1;
  
  if (x->gg.g.ns && x->gg.g.ns->prefix_len)
    len += (x->gg.g.ns->prefix_len + 1) * 2;
  if (c->inc_ns_len)
    len += zx_len_inc_ns(c, &pop_seen);
  len += zx_len_xmlns_if_not_seen(c, x->gg.g.ns, &pop_seen);


#else
  /* root node has no begin tag */
  int len = 0;
#endif
  
  for (se = x->Granularity; se; se = (struct zx_elem_s*)se->g.n)
    len += zx_LEN_WO_simple_elem(c, se, sizeof("Granularity")-1);
  for (se = x->Interval; se; se = (struct zx_elem_s*)se->g.n)
    len += zx_LEN_WO_simple_elem(c, se, sizeof("Interval")-1);
  {
      struct zx_gl_ms_action_s* e;
      for (e = x->ms_action; e; e = (struct zx_gl_ms_action_s*)e->gg.g.n)
	  len += zx_LEN_WO_gl_ms_action(c, e);
  }
  {
      struct zx_gl_ChangeArea_s* e;
      for (e = x->ChangeArea; e; e = (struct zx_gl_ChangeArea_s*)e->gg.g.n)
	  len += zx_LEN_WO_gl_ChangeArea(c, e);
  }
  {
      struct zx_gl_Extension_s* e;
      for (e = x->Extension; e; e = (struct zx_gl_Extension_s*)e->gg.g.n)
	  len += zx_LEN_WO_gl_Extension(c, e);
  }


  len += zx_len_wo_common(c, &x->gg); 
  zx_pop_seen(pop_seen);
  ENC_LEN_DEBUG(x, "gl:Trigger", len);
  return len;
}

/* FUNC(zx_ENC_SO_gl_Trigger) */

/* Render element into string. The XML attributes and elements are
 * processed in schema order. This is what you generally want for
 * rendering new data structure to a string. The wo pointers are not used. */

/* Called by: */
char* zx_ENC_SO_gl_Trigger(struct zx_ctx* c, struct zx_gl_Trigger_s* x, char* p )
{
  struct zx_elem_s* se MAYBE_UNUSED;
  struct zx_ns_s* pop_seen = 0;
  ENC_LEN_DEBUG_BASE;
#if 1 /* NORMALMODE */
  /* *** in simple_elem case should output ns prefix from ns node. */
  ZX_OUT_TAG(p, "<gl:Trigger");
  if (c->inc_ns)
    p = zx_enc_inc_ns(c, p, &pop_seen);
  p = zx_enc_xmlns_if_not_seen(c, p, zx_ns_tab+zx_xmlns_ix_gl, &pop_seen);


  p = zx_enc_unknown_attrs(p, x->gg.any_attr);
#else
  /* root node has no begin tag */
#endif
  
  for (se = x->Granularity; se; se = (struct zx_elem_s*)se->g.n)
    p = zx_ENC_SO_simple_elem(c, se, p, "gl:Granularity", sizeof("gl:Granularity")-1, zx_ns_tab+zx_xmlns_ix_gl);
  for (se = x->Interval; se; se = (struct zx_elem_s*)se->g.n)
    p = zx_ENC_SO_simple_elem(c, se, p, "gl:Interval", sizeof("gl:Interval")-1, zx_ns_tab+zx_xmlns_ix_gl);
  {
      struct zx_gl_ms_action_s* e;
      for (e = x->ms_action; e; e = (struct zx_gl_ms_action_s*)e->gg.g.n)
	  p = zx_ENC_SO_gl_ms_action(c, e, p);
  }
  {
      struct zx_gl_ChangeArea_s* e;
      for (e = x->ChangeArea; e; e = (struct zx_gl_ChangeArea_s*)e->gg.g.n)
	  p = zx_ENC_SO_gl_ChangeArea(c, e, p);
  }
  {
      struct zx_gl_Extension_s* e;
      for (e = x->Extension; e; e = (struct zx_gl_Extension_s*)e->gg.g.n)
	  p = zx_ENC_SO_gl_Extension(c, e, p);
  }

  p = zx_enc_so_unknown_elems_and_content(c, p, &x->gg);
  
#if 1 /* NORMALMODE */
  ZX_OUT_CLOSE_TAG(p, "</gl:Trigger>");
  zx_pop_seen(pop_seen);
#else
  /* root node has no end tag either */
#endif
  ENC_LEN_DEBUG(x, "gl:Trigger", p-enc_base);
  return p;
}

/* FUNC(zx_ENC_WO_gl_Trigger) */

/* Render element into string. The XML attributes and elements are
 * processed in wire order by chasing wo pointers. This is what you want for
 * validating signatures on other people's XML documents. */

/* Called by: */
char* zx_ENC_WO_gl_Trigger(struct zx_ctx* c, struct zx_gl_Trigger_s* x, char* p )
{
  struct zx_elem_s* kid;
  struct zx_ns_s* pop_seen = 0;
  ENC_LEN_DEBUG_BASE;
#if 1 /* NORMALMODE */
  char* q;
  char* qq;
  ZX_OUT_CH(p, '<');
  q = p;
  if (x->gg.g.ns && x->gg.g.ns->prefix_len) {
    ZX_OUT_MEM(p, x->gg.g.ns->prefix, x->gg.g.ns->prefix_len);
    ZX_OUT_CH(p, ':');
  }
  ZX_OUT_MEM(p, "Trigger", sizeof("Trigger")-1);
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
  ENC_LEN_DEBUG(x, "gl:Trigger", p-enc_base);
  return p;
}

/* FUNC(zx_EASY_ENC_SO_gl_Trigger) */

/* Called by: */
struct zx_str* zx_EASY_ENC_SO_gl_Trigger(struct zx_ctx* c, struct zx_gl_Trigger_s* x )
{
  int len;
  char* buf;
  c->ns_tab = ZX_ALLOC(c, sizeof(zx_ns_tab));
  memcpy(c->ns_tab, zx_ns_tab, sizeof(zx_ns_tab));
  len = zx_LEN_SO_gl_Trigger(c, x );
  buf = ZX_ALLOC(c, len+1);
  return zx_easy_enc_common(c, zx_ENC_SO_gl_Trigger(c, x, buf ), buf, len);
}

/* FUNC(zx_EASY_ENC_WO_gl_Trigger) */

/* Called by: */
struct zx_str* zx_EASY_ENC_WO_gl_Trigger(struct zx_ctx* c, struct zx_gl_Trigger_s* x )
{
  int len;
  char* buf;
  c->ns_tab = ZX_ALLOC(c, sizeof(zx_ns_tab));
  memcpy(c->ns_tab, zx_ns_tab, sizeof(zx_ns_tab));
  len = zx_LEN_WO_gl_Trigger(c, x );
  buf = ZX_ALLOC(c, len+1);
  return zx_easy_enc_common(c, zx_ENC_WO_gl_Trigger(c, x, buf ), buf, len);
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

#define EL_NAME   gl_coord
#define EL_STRUCT zx_gl_coord_s
#define EL_NS     gl
#define EL_TAG    coord

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

/* FUNC(zx_LEN_SO_gl_coord) */

/* Compute length of an element (and its subelements). The XML attributes
 * and elements are processed in schema order. */

/* Called by: */
int zx_LEN_SO_gl_coord(struct zx_ctx* c, struct zx_gl_coord_s* x )
{
  struct zx_ns_s* pop_seen = 0;
  struct zx_elem_s* se MAYBE_UNUSED;
#if 1 /* NORMALMODE */
  /* *** in simple_elem case should output ns prefix from ns node. */
  int len = sizeof("<gl:coord")-1 + 1 + sizeof("</gl:coord>")-1;
  if (c->inc_ns_len)
    len += zx_len_inc_ns(c, &pop_seen);
  len += zx_len_xmlns_if_not_seen(c, zx_ns_tab+zx_xmlns_ix_gl, &pop_seen);


#else
  /* root node has no begin tag */
  int len = 0;
#endif
  
  for (se = x->X; se; se = (struct zx_elem_s*)se->g.n)
    len += zx_LEN_SO_simple_elem(c,se, sizeof("gl:X")-1, zx_ns_tab+zx_xmlns_ix_gl);
  for (se = x->Y; se; se = (struct zx_elem_s*)se->g.n)
    len += zx_LEN_SO_simple_elem(c,se, sizeof("gl:Y")-1, zx_ns_tab+zx_xmlns_ix_gl);
  for (se = x->Z; se; se = (struct zx_elem_s*)se->g.n)
    len += zx_LEN_SO_simple_elem(c,se, sizeof("gl:Z")-1, zx_ns_tab+zx_xmlns_ix_gl);


  len += zx_len_so_common(c, &x->gg);
  zx_pop_seen(pop_seen);
  ENC_LEN_DEBUG(x, "gl:coord", len);
  return len;
}

/* FUNC(zx_LEN_WO_gl_coord) */

/* Compute length of an element (and its subelements). The XML attributes
 * and elements are processed in wire order and no assumptions
 * are made about namespace prefixes. */

/* Called by: */
int zx_LEN_WO_gl_coord(struct zx_ctx* c, struct zx_gl_coord_s* x )
{
  struct zx_ns_s* pop_seen = 0;
  struct zx_elem_s* se MAYBE_UNUSED;
#if 1 /* NORMALMODE */
  int len = 1 + sizeof("coord")-1 + 1 + 2 + sizeof("coord")-1 + 1;
  
  if (x->gg.g.ns && x->gg.g.ns->prefix_len)
    len += (x->gg.g.ns->prefix_len + 1) * 2;
  if (c->inc_ns_len)
    len += zx_len_inc_ns(c, &pop_seen);
  len += zx_len_xmlns_if_not_seen(c, x->gg.g.ns, &pop_seen);


#else
  /* root node has no begin tag */
  int len = 0;
#endif
  
  for (se = x->X; se; se = (struct zx_elem_s*)se->g.n)
    len += zx_LEN_WO_simple_elem(c, se, sizeof("X")-1);
  for (se = x->Y; se; se = (struct zx_elem_s*)se->g.n)
    len += zx_LEN_WO_simple_elem(c, se, sizeof("Y")-1);
  for (se = x->Z; se; se = (struct zx_elem_s*)se->g.n)
    len += zx_LEN_WO_simple_elem(c, se, sizeof("Z")-1);


  len += zx_len_wo_common(c, &x->gg); 
  zx_pop_seen(pop_seen);
  ENC_LEN_DEBUG(x, "gl:coord", len);
  return len;
}

/* FUNC(zx_ENC_SO_gl_coord) */

/* Render element into string. The XML attributes and elements are
 * processed in schema order. This is what you generally want for
 * rendering new data structure to a string. The wo pointers are not used. */

/* Called by: */
char* zx_ENC_SO_gl_coord(struct zx_ctx* c, struct zx_gl_coord_s* x, char* p )
{
  struct zx_elem_s* se MAYBE_UNUSED;
  struct zx_ns_s* pop_seen = 0;
  ENC_LEN_DEBUG_BASE;
#if 1 /* NORMALMODE */
  /* *** in simple_elem case should output ns prefix from ns node. */
  ZX_OUT_TAG(p, "<gl:coord");
  if (c->inc_ns)
    p = zx_enc_inc_ns(c, p, &pop_seen);
  p = zx_enc_xmlns_if_not_seen(c, p, zx_ns_tab+zx_xmlns_ix_gl, &pop_seen);


  p = zx_enc_unknown_attrs(p, x->gg.any_attr);
#else
  /* root node has no begin tag */
#endif
  
  for (se = x->X; se; se = (struct zx_elem_s*)se->g.n)
    p = zx_ENC_SO_simple_elem(c, se, p, "gl:X", sizeof("gl:X")-1, zx_ns_tab+zx_xmlns_ix_gl);
  for (se = x->Y; se; se = (struct zx_elem_s*)se->g.n)
    p = zx_ENC_SO_simple_elem(c, se, p, "gl:Y", sizeof("gl:Y")-1, zx_ns_tab+zx_xmlns_ix_gl);
  for (se = x->Z; se; se = (struct zx_elem_s*)se->g.n)
    p = zx_ENC_SO_simple_elem(c, se, p, "gl:Z", sizeof("gl:Z")-1, zx_ns_tab+zx_xmlns_ix_gl);

  p = zx_enc_so_unknown_elems_and_content(c, p, &x->gg);
  
#if 1 /* NORMALMODE */
  ZX_OUT_CLOSE_TAG(p, "</gl:coord>");
  zx_pop_seen(pop_seen);
#else
  /* root node has no end tag either */
#endif
  ENC_LEN_DEBUG(x, "gl:coord", p-enc_base);
  return p;
}

/* FUNC(zx_ENC_WO_gl_coord) */

/* Render element into string. The XML attributes and elements are
 * processed in wire order by chasing wo pointers. This is what you want for
 * validating signatures on other people's XML documents. */

/* Called by: */
char* zx_ENC_WO_gl_coord(struct zx_ctx* c, struct zx_gl_coord_s* x, char* p )
{
  struct zx_elem_s* kid;
  struct zx_ns_s* pop_seen = 0;
  ENC_LEN_DEBUG_BASE;
#if 1 /* NORMALMODE */
  char* q;
  char* qq;
  ZX_OUT_CH(p, '<');
  q = p;
  if (x->gg.g.ns && x->gg.g.ns->prefix_len) {
    ZX_OUT_MEM(p, x->gg.g.ns->prefix, x->gg.g.ns->prefix_len);
    ZX_OUT_CH(p, ':');
  }
  ZX_OUT_MEM(p, "coord", sizeof("coord")-1);
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
  ENC_LEN_DEBUG(x, "gl:coord", p-enc_base);
  return p;
}

/* FUNC(zx_EASY_ENC_SO_gl_coord) */

/* Called by: */
struct zx_str* zx_EASY_ENC_SO_gl_coord(struct zx_ctx* c, struct zx_gl_coord_s* x )
{
  int len;
  char* buf;
  c->ns_tab = ZX_ALLOC(c, sizeof(zx_ns_tab));
  memcpy(c->ns_tab, zx_ns_tab, sizeof(zx_ns_tab));
  len = zx_LEN_SO_gl_coord(c, x );
  buf = ZX_ALLOC(c, len+1);
  return zx_easy_enc_common(c, zx_ENC_SO_gl_coord(c, x, buf ), buf, len);
}

/* FUNC(zx_EASY_ENC_WO_gl_coord) */

/* Called by: */
struct zx_str* zx_EASY_ENC_WO_gl_coord(struct zx_ctx* c, struct zx_gl_coord_s* x )
{
  int len;
  char* buf;
  c->ns_tab = ZX_ALLOC(c, sizeof(zx_ns_tab));
  memcpy(c->ns_tab, zx_ns_tab, sizeof(zx_ns_tab));
  len = zx_LEN_WO_gl_coord(c, x );
  buf = ZX_ALLOC(c, len+1);
  return zx_easy_enc_common(c, zx_ENC_WO_gl_coord(c, x, buf ), buf, len);
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

#define EL_NAME   gl_eqop
#define EL_STRUCT zx_gl_eqop_s
#define EL_NS     gl
#define EL_TAG    eqop

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

/* FUNC(zx_LEN_SO_gl_eqop) */

/* Compute length of an element (and its subelements). The XML attributes
 * and elements are processed in schema order. */

/* Called by: */
int zx_LEN_SO_gl_eqop(struct zx_ctx* c, struct zx_gl_eqop_s* x )
{
  struct zx_ns_s* pop_seen = 0;
  struct zx_elem_s* se MAYBE_UNUSED;
#if 1 /* NORMALMODE */
  /* *** in simple_elem case should output ns prefix from ns node. */
  int len = sizeof("<gl:eqop")-1 + 1 + sizeof("</gl:eqop>")-1;
  if (c->inc_ns_len)
    len += zx_len_inc_ns(c, &pop_seen);
  len += zx_len_xmlns_if_not_seen(c, zx_ns_tab+zx_xmlns_ix_gl, &pop_seen);


#else
  /* root node has no begin tag */
  int len = 0;
#endif
  
  {
      struct zx_gl_resp_req_s* e;
      for (e = x->resp_req; e; e = (struct zx_gl_resp_req_s*)e->gg.g.n)
	  len += zx_LEN_SO_gl_resp_req(c, e);
  }
  for (se = x->ll_acc; se; se = (struct zx_elem_s*)se->g.n)
    len += zx_LEN_SO_simple_elem(c,se, sizeof("gl:ll_acc")-1, zx_ns_tab+zx_xmlns_ix_gl);
  for (se = x->hor_acc; se; se = (struct zx_elem_s*)se->g.n)
    len += zx_LEN_SO_simple_elem(c,se, sizeof("gl:hor_acc")-1, zx_ns_tab+zx_xmlns_ix_gl);
  for (se = x->alt_acc; se; se = (struct zx_elem_s*)se->g.n)
    len += zx_LEN_SO_simple_elem(c,se, sizeof("gl:alt_acc")-1, zx_ns_tab+zx_xmlns_ix_gl);
  for (se = x->max_loc_age; se; se = (struct zx_elem_s*)se->g.n)
    len += zx_LEN_SO_simple_elem(c,se, sizeof("gl:max_loc_age")-1, zx_ns_tab+zx_xmlns_ix_gl);
  {
      struct zx_gl_Extension_s* e;
      for (e = x->Extension; e; e = (struct zx_gl_Extension_s*)e->gg.g.n)
	  len += zx_LEN_SO_gl_Extension(c, e);
  }


  len += zx_len_so_common(c, &x->gg);
  zx_pop_seen(pop_seen);
  ENC_LEN_DEBUG(x, "gl:eqop", len);
  return len;
}

/* FUNC(zx_LEN_WO_gl_eqop) */

/* Compute length of an element (and its subelements). The XML attributes
 * and elements are processed in wire order and no assumptions
 * are made about namespace prefixes. */

/* Called by: */
int zx_LEN_WO_gl_eqop(struct zx_ctx* c, struct zx_gl_eqop_s* x )
{
  struct zx_ns_s* pop_seen = 0;
  struct zx_elem_s* se MAYBE_UNUSED;
#if 1 /* NORMALMODE */
  int len = 1 + sizeof("eqop")-1 + 1 + 2 + sizeof("eqop")-1 + 1;
  
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
      struct zx_gl_resp_req_s* e;
      for (e = x->resp_req; e; e = (struct zx_gl_resp_req_s*)e->gg.g.n)
	  len += zx_LEN_WO_gl_resp_req(c, e);
  }
  for (se = x->ll_acc; se; se = (struct zx_elem_s*)se->g.n)
    len += zx_LEN_WO_simple_elem(c, se, sizeof("ll_acc")-1);
  for (se = x->hor_acc; se; se = (struct zx_elem_s*)se->g.n)
    len += zx_LEN_WO_simple_elem(c, se, sizeof("hor_acc")-1);
  for (se = x->alt_acc; se; se = (struct zx_elem_s*)se->g.n)
    len += zx_LEN_WO_simple_elem(c, se, sizeof("alt_acc")-1);
  for (se = x->max_loc_age; se; se = (struct zx_elem_s*)se->g.n)
    len += zx_LEN_WO_simple_elem(c, se, sizeof("max_loc_age")-1);
  {
      struct zx_gl_Extension_s* e;
      for (e = x->Extension; e; e = (struct zx_gl_Extension_s*)e->gg.g.n)
	  len += zx_LEN_WO_gl_Extension(c, e);
  }


  len += zx_len_wo_common(c, &x->gg); 
  zx_pop_seen(pop_seen);
  ENC_LEN_DEBUG(x, "gl:eqop", len);
  return len;
}

/* FUNC(zx_ENC_SO_gl_eqop) */

/* Render element into string. The XML attributes and elements are
 * processed in schema order. This is what you generally want for
 * rendering new data structure to a string. The wo pointers are not used. */

/* Called by: */
char* zx_ENC_SO_gl_eqop(struct zx_ctx* c, struct zx_gl_eqop_s* x, char* p )
{
  struct zx_elem_s* se MAYBE_UNUSED;
  struct zx_ns_s* pop_seen = 0;
  ENC_LEN_DEBUG_BASE;
#if 1 /* NORMALMODE */
  /* *** in simple_elem case should output ns prefix from ns node. */
  ZX_OUT_TAG(p, "<gl:eqop");
  if (c->inc_ns)
    p = zx_enc_inc_ns(c, p, &pop_seen);
  p = zx_enc_xmlns_if_not_seen(c, p, zx_ns_tab+zx_xmlns_ix_gl, &pop_seen);


  p = zx_enc_unknown_attrs(p, x->gg.any_attr);
#else
  /* root node has no begin tag */
#endif
  
  {
      struct zx_gl_resp_req_s* e;
      for (e = x->resp_req; e; e = (struct zx_gl_resp_req_s*)e->gg.g.n)
	  p = zx_ENC_SO_gl_resp_req(c, e, p);
  }
  for (se = x->ll_acc; se; se = (struct zx_elem_s*)se->g.n)
    p = zx_ENC_SO_simple_elem(c, se, p, "gl:ll_acc", sizeof("gl:ll_acc")-1, zx_ns_tab+zx_xmlns_ix_gl);
  for (se = x->hor_acc; se; se = (struct zx_elem_s*)se->g.n)
    p = zx_ENC_SO_simple_elem(c, se, p, "gl:hor_acc", sizeof("gl:hor_acc")-1, zx_ns_tab+zx_xmlns_ix_gl);
  for (se = x->alt_acc; se; se = (struct zx_elem_s*)se->g.n)
    p = zx_ENC_SO_simple_elem(c, se, p, "gl:alt_acc", sizeof("gl:alt_acc")-1, zx_ns_tab+zx_xmlns_ix_gl);
  for (se = x->max_loc_age; se; se = (struct zx_elem_s*)se->g.n)
    p = zx_ENC_SO_simple_elem(c, se, p, "gl:max_loc_age", sizeof("gl:max_loc_age")-1, zx_ns_tab+zx_xmlns_ix_gl);
  {
      struct zx_gl_Extension_s* e;
      for (e = x->Extension; e; e = (struct zx_gl_Extension_s*)e->gg.g.n)
	  p = zx_ENC_SO_gl_Extension(c, e, p);
  }

  p = zx_enc_so_unknown_elems_and_content(c, p, &x->gg);
  
#if 1 /* NORMALMODE */
  ZX_OUT_CLOSE_TAG(p, "</gl:eqop>");
  zx_pop_seen(pop_seen);
#else
  /* root node has no end tag either */
#endif
  ENC_LEN_DEBUG(x, "gl:eqop", p-enc_base);
  return p;
}

/* FUNC(zx_ENC_WO_gl_eqop) */

/* Render element into string. The XML attributes and elements are
 * processed in wire order by chasing wo pointers. This is what you want for
 * validating signatures on other people's XML documents. */

/* Called by: */
char* zx_ENC_WO_gl_eqop(struct zx_ctx* c, struct zx_gl_eqop_s* x, char* p )
{
  struct zx_elem_s* kid;
  struct zx_ns_s* pop_seen = 0;
  ENC_LEN_DEBUG_BASE;
#if 1 /* NORMALMODE */
  char* q;
  char* qq;
  ZX_OUT_CH(p, '<');
  q = p;
  if (x->gg.g.ns && x->gg.g.ns->prefix_len) {
    ZX_OUT_MEM(p, x->gg.g.ns->prefix, x->gg.g.ns->prefix_len);
    ZX_OUT_CH(p, ':');
  }
  ZX_OUT_MEM(p, "eqop", sizeof("eqop")-1);
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
  ENC_LEN_DEBUG(x, "gl:eqop", p-enc_base);
  return p;
}

/* FUNC(zx_EASY_ENC_SO_gl_eqop) */

/* Called by: */
struct zx_str* zx_EASY_ENC_SO_gl_eqop(struct zx_ctx* c, struct zx_gl_eqop_s* x )
{
  int len;
  char* buf;
  c->ns_tab = ZX_ALLOC(c, sizeof(zx_ns_tab));
  memcpy(c->ns_tab, zx_ns_tab, sizeof(zx_ns_tab));
  len = zx_LEN_SO_gl_eqop(c, x );
  buf = ZX_ALLOC(c, len+1);
  return zx_easy_enc_common(c, zx_ENC_SO_gl_eqop(c, x, buf ), buf, len);
}

/* FUNC(zx_EASY_ENC_WO_gl_eqop) */

/* Called by: */
struct zx_str* zx_EASY_ENC_WO_gl_eqop(struct zx_ctx* c, struct zx_gl_eqop_s* x )
{
  int len;
  char* buf;
  c->ns_tab = ZX_ALLOC(c, sizeof(zx_ns_tab));
  memcpy(c->ns_tab, zx_ns_tab, sizeof(zx_ns_tab));
  len = zx_LEN_WO_gl_eqop(c, x );
  buf = ZX_ALLOC(c, len+1);
  return zx_easy_enc_common(c, zx_ENC_WO_gl_eqop(c, x, buf ), buf, len);
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

#define EL_NAME   gl_esrd
#define EL_STRUCT zx_gl_esrd_s
#define EL_NS     gl
#define EL_TAG    esrd

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

/* FUNC(zx_LEN_SO_gl_esrd) */

/* Compute length of an element (and its subelements). The XML attributes
 * and elements are processed in schema order. */

/* Called by: */
int zx_LEN_SO_gl_esrd(struct zx_ctx* c, struct zx_gl_esrd_s* x )
{
  struct zx_ns_s* pop_seen = 0;
  struct zx_elem_s* se MAYBE_UNUSED;
#if 1 /* NORMALMODE */
  /* *** in simple_elem case should output ns prefix from ns node. */
  int len = sizeof("<gl:esrd")-1 + 1 + sizeof("</gl:esrd>")-1;
  if (c->inc_ns_len)
    len += zx_len_inc_ns(c, &pop_seen);
  len += zx_len_xmlns_if_not_seen(c, zx_ns_tab+zx_xmlns_ix_gl, &pop_seen);

  len += zx_attr_so_len(x->type, sizeof("type")-1);

#else
  /* root node has no begin tag */
  int len = 0;
#endif
  


  len += zx_len_so_common(c, &x->gg);
  zx_pop_seen(pop_seen);
  ENC_LEN_DEBUG(x, "gl:esrd", len);
  return len;
}

/* FUNC(zx_LEN_WO_gl_esrd) */

/* Compute length of an element (and its subelements). The XML attributes
 * and elements are processed in wire order and no assumptions
 * are made about namespace prefixes. */

/* Called by: */
int zx_LEN_WO_gl_esrd(struct zx_ctx* c, struct zx_gl_esrd_s* x )
{
  struct zx_ns_s* pop_seen = 0;
  struct zx_elem_s* se MAYBE_UNUSED;
#if 1 /* NORMALMODE */
  int len = 1 + sizeof("esrd")-1 + 1 + 2 + sizeof("esrd")-1 + 1;
  
  if (x->gg.g.ns && x->gg.g.ns->prefix_len)
    len += (x->gg.g.ns->prefix_len + 1) * 2;
  if (c->inc_ns_len)
    len += zx_len_inc_ns(c, &pop_seen);
  len += zx_len_xmlns_if_not_seen(c, x->gg.g.ns, &pop_seen);

  len += zx_attr_wo_len(x->type, sizeof("type")-1);

#else
  /* root node has no begin tag */
  int len = 0;
#endif
  


  len += zx_len_wo_common(c, &x->gg); 
  zx_pop_seen(pop_seen);
  ENC_LEN_DEBUG(x, "gl:esrd", len);
  return len;
}

/* FUNC(zx_ENC_SO_gl_esrd) */

/* Render element into string. The XML attributes and elements are
 * processed in schema order. This is what you generally want for
 * rendering new data structure to a string. The wo pointers are not used. */

/* Called by: */
char* zx_ENC_SO_gl_esrd(struct zx_ctx* c, struct zx_gl_esrd_s* x, char* p )
{
  struct zx_elem_s* se MAYBE_UNUSED;
  struct zx_ns_s* pop_seen = 0;
  ENC_LEN_DEBUG_BASE;
#if 1 /* NORMALMODE */
  /* *** in simple_elem case should output ns prefix from ns node. */
  ZX_OUT_TAG(p, "<gl:esrd");
  if (c->inc_ns)
    p = zx_enc_inc_ns(c, p, &pop_seen);
  p = zx_enc_xmlns_if_not_seen(c, p, zx_ns_tab+zx_xmlns_ix_gl, &pop_seen);

  p = zx_attr_so_enc(p, x->type, " type=\"", sizeof(" type=\"")-1);

  p = zx_enc_unknown_attrs(p, x->gg.any_attr);
#else
  /* root node has no begin tag */
#endif
  

  p = zx_enc_so_unknown_elems_and_content(c, p, &x->gg);
  
#if 1 /* NORMALMODE */
  ZX_OUT_CLOSE_TAG(p, "</gl:esrd>");
  zx_pop_seen(pop_seen);
#else
  /* root node has no end tag either */
#endif
  ENC_LEN_DEBUG(x, "gl:esrd", p-enc_base);
  return p;
}

/* FUNC(zx_ENC_WO_gl_esrd) */

/* Render element into string. The XML attributes and elements are
 * processed in wire order by chasing wo pointers. This is what you want for
 * validating signatures on other people's XML documents. */

/* Called by: */
char* zx_ENC_WO_gl_esrd(struct zx_ctx* c, struct zx_gl_esrd_s* x, char* p )
{
  struct zx_elem_s* kid;
  struct zx_ns_s* pop_seen = 0;
  ENC_LEN_DEBUG_BASE;
#if 1 /* NORMALMODE */
  char* q;
  char* qq;
  ZX_OUT_CH(p, '<');
  q = p;
  if (x->gg.g.ns && x->gg.g.ns->prefix_len) {
    ZX_OUT_MEM(p, x->gg.g.ns->prefix, x->gg.g.ns->prefix_len);
    ZX_OUT_CH(p, ':');
  }
  ZX_OUT_MEM(p, "esrd", sizeof("esrd")-1);
  qq = p;

  /* *** sort the namespaces */
  if (c->inc_ns)
    zx_add_inc_ns(c, &pop_seen);
  zx_add_xmlns_if_not_seen(c, x->gg.g.ns, &pop_seen);

  p = zx_enc_seen(p, pop_seen); 
  p = zx_attr_wo_enc(p, x->type, "type=\"", sizeof("type=\"")-1);

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
  ENC_LEN_DEBUG(x, "gl:esrd", p-enc_base);
  return p;
}

/* FUNC(zx_EASY_ENC_SO_gl_esrd) */

/* Called by: */
struct zx_str* zx_EASY_ENC_SO_gl_esrd(struct zx_ctx* c, struct zx_gl_esrd_s* x )
{
  int len;
  char* buf;
  c->ns_tab = ZX_ALLOC(c, sizeof(zx_ns_tab));
  memcpy(c->ns_tab, zx_ns_tab, sizeof(zx_ns_tab));
  len = zx_LEN_SO_gl_esrd(c, x );
  buf = ZX_ALLOC(c, len+1);
  return zx_easy_enc_common(c, zx_ENC_SO_gl_esrd(c, x, buf ), buf, len);
}

/* FUNC(zx_EASY_ENC_WO_gl_esrd) */

/* Called by: */
struct zx_str* zx_EASY_ENC_WO_gl_esrd(struct zx_ctx* c, struct zx_gl_esrd_s* x )
{
  int len;
  char* buf;
  c->ns_tab = ZX_ALLOC(c, sizeof(zx_ns_tab));
  memcpy(c->ns_tab, zx_ns_tab, sizeof(zx_ns_tab));
  len = zx_LEN_WO_gl_esrd(c, x );
  buf = ZX_ALLOC(c, len+1);
  return zx_easy_enc_common(c, zx_ENC_WO_gl_esrd(c, x, buf ), buf, len);
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

#define EL_NAME   gl_esrk
#define EL_STRUCT zx_gl_esrk_s
#define EL_NS     gl
#define EL_TAG    esrk

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

/* FUNC(zx_LEN_SO_gl_esrk) */

/* Compute length of an element (and its subelements). The XML attributes
 * and elements are processed in schema order. */

/* Called by: */
int zx_LEN_SO_gl_esrk(struct zx_ctx* c, struct zx_gl_esrk_s* x )
{
  struct zx_ns_s* pop_seen = 0;
  struct zx_elem_s* se MAYBE_UNUSED;
#if 1 /* NORMALMODE */
  /* *** in simple_elem case should output ns prefix from ns node. */
  int len = sizeof("<gl:esrk")-1 + 1 + sizeof("</gl:esrk>")-1;
  if (c->inc_ns_len)
    len += zx_len_inc_ns(c, &pop_seen);
  len += zx_len_xmlns_if_not_seen(c, zx_ns_tab+zx_xmlns_ix_gl, &pop_seen);

  len += zx_attr_so_len(x->type, sizeof("type")-1);

#else
  /* root node has no begin tag */
  int len = 0;
#endif
  


  len += zx_len_so_common(c, &x->gg);
  zx_pop_seen(pop_seen);
  ENC_LEN_DEBUG(x, "gl:esrk", len);
  return len;
}

/* FUNC(zx_LEN_WO_gl_esrk) */

/* Compute length of an element (and its subelements). The XML attributes
 * and elements are processed in wire order and no assumptions
 * are made about namespace prefixes. */

/* Called by: */
int zx_LEN_WO_gl_esrk(struct zx_ctx* c, struct zx_gl_esrk_s* x )
{
  struct zx_ns_s* pop_seen = 0;
  struct zx_elem_s* se MAYBE_UNUSED;
#if 1 /* NORMALMODE */
  int len = 1 + sizeof("esrk")-1 + 1 + 2 + sizeof("esrk")-1 + 1;
  
  if (x->gg.g.ns && x->gg.g.ns->prefix_len)
    len += (x->gg.g.ns->prefix_len + 1) * 2;
  if (c->inc_ns_len)
    len += zx_len_inc_ns(c, &pop_seen);
  len += zx_len_xmlns_if_not_seen(c, x->gg.g.ns, &pop_seen);

  len += zx_attr_wo_len(x->type, sizeof("type")-1);

#else
  /* root node has no begin tag */
  int len = 0;
#endif
  


  len += zx_len_wo_common(c, &x->gg); 
  zx_pop_seen(pop_seen);
  ENC_LEN_DEBUG(x, "gl:esrk", len);
  return len;
}

/* FUNC(zx_ENC_SO_gl_esrk) */

/* Render element into string. The XML attributes and elements are
 * processed in schema order. This is what you generally want for
 * rendering new data structure to a string. The wo pointers are not used. */

/* Called by: */
char* zx_ENC_SO_gl_esrk(struct zx_ctx* c, struct zx_gl_esrk_s* x, char* p )
{
  struct zx_elem_s* se MAYBE_UNUSED;
  struct zx_ns_s* pop_seen = 0;
  ENC_LEN_DEBUG_BASE;
#if 1 /* NORMALMODE */
  /* *** in simple_elem case should output ns prefix from ns node. */
  ZX_OUT_TAG(p, "<gl:esrk");
  if (c->inc_ns)
    p = zx_enc_inc_ns(c, p, &pop_seen);
  p = zx_enc_xmlns_if_not_seen(c, p, zx_ns_tab+zx_xmlns_ix_gl, &pop_seen);

  p = zx_attr_so_enc(p, x->type, " type=\"", sizeof(" type=\"")-1);

  p = zx_enc_unknown_attrs(p, x->gg.any_attr);
#else
  /* root node has no begin tag */
#endif
  

  p = zx_enc_so_unknown_elems_and_content(c, p, &x->gg);
  
#if 1 /* NORMALMODE */
  ZX_OUT_CLOSE_TAG(p, "</gl:esrk>");
  zx_pop_seen(pop_seen);
#else
  /* root node has no end tag either */
#endif
  ENC_LEN_DEBUG(x, "gl:esrk", p-enc_base);
  return p;
}

/* FUNC(zx_ENC_WO_gl_esrk) */

/* Render element into string. The XML attributes and elements are
 * processed in wire order by chasing wo pointers. This is what you want for
 * validating signatures on other people's XML documents. */

/* Called by: */
char* zx_ENC_WO_gl_esrk(struct zx_ctx* c, struct zx_gl_esrk_s* x, char* p )
{
  struct zx_elem_s* kid;
  struct zx_ns_s* pop_seen = 0;
  ENC_LEN_DEBUG_BASE;
#if 1 /* NORMALMODE */
  char* q;
  char* qq;
  ZX_OUT_CH(p, '<');
  q = p;
  if (x->gg.g.ns && x->gg.g.ns->prefix_len) {
    ZX_OUT_MEM(p, x->gg.g.ns->prefix, x->gg.g.ns->prefix_len);
    ZX_OUT_CH(p, ':');
  }
  ZX_OUT_MEM(p, "esrk", sizeof("esrk")-1);
  qq = p;

  /* *** sort the namespaces */
  if (c->inc_ns)
    zx_add_inc_ns(c, &pop_seen);
  zx_add_xmlns_if_not_seen(c, x->gg.g.ns, &pop_seen);

  p = zx_enc_seen(p, pop_seen); 
  p = zx_attr_wo_enc(p, x->type, "type=\"", sizeof("type=\"")-1);

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
  ENC_LEN_DEBUG(x, "gl:esrk", p-enc_base);
  return p;
}

/* FUNC(zx_EASY_ENC_SO_gl_esrk) */

/* Called by: */
struct zx_str* zx_EASY_ENC_SO_gl_esrk(struct zx_ctx* c, struct zx_gl_esrk_s* x )
{
  int len;
  char* buf;
  c->ns_tab = ZX_ALLOC(c, sizeof(zx_ns_tab));
  memcpy(c->ns_tab, zx_ns_tab, sizeof(zx_ns_tab));
  len = zx_LEN_SO_gl_esrk(c, x );
  buf = ZX_ALLOC(c, len+1);
  return zx_easy_enc_common(c, zx_ENC_SO_gl_esrk(c, x, buf ), buf, len);
}

/* FUNC(zx_EASY_ENC_WO_gl_esrk) */

/* Called by: */
struct zx_str* zx_EASY_ENC_WO_gl_esrk(struct zx_ctx* c, struct zx_gl_esrk_s* x )
{
  int len;
  char* buf;
  c->ns_tab = ZX_ALLOC(c, sizeof(zx_ns_tab));
  memcpy(c->ns_tab, zx_ns_tab, sizeof(zx_ns_tab));
  len = zx_LEN_WO_gl_esrk(c, x );
  buf = ZX_ALLOC(c, len+1);
  return zx_easy_enc_common(c, zx_ENC_WO_gl_esrk(c, x, buf ), buf, len);
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

#define EL_NAME   gl_geoinfo
#define EL_STRUCT zx_gl_geoinfo_s
#define EL_NS     gl
#define EL_TAG    geoinfo

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

/* FUNC(zx_LEN_SO_gl_geoinfo) */

/* Compute length of an element (and its subelements). The XML attributes
 * and elements are processed in schema order. */

/* Called by: */
int zx_LEN_SO_gl_geoinfo(struct zx_ctx* c, struct zx_gl_geoinfo_s* x )
{
  struct zx_ns_s* pop_seen = 0;
  struct zx_elem_s* se MAYBE_UNUSED;
#if 1 /* NORMALMODE */
  /* *** in simple_elem case should output ns prefix from ns node. */
  int len = sizeof("<gl:geoinfo")-1 + 1 + sizeof("</gl:geoinfo>")-1;
  if (c->inc_ns_len)
    len += zx_len_inc_ns(c, &pop_seen);
  len += zx_len_xmlns_if_not_seen(c, zx_ns_tab+zx_xmlns_ix_gl, &pop_seen);


#else
  /* root node has no begin tag */
  int len = 0;
#endif
  
  {
      struct zx_gl_CoordinateReferenceSystem_s* e;
      for (e = x->CoordinateReferenceSystem; e; e = (struct zx_gl_CoordinateReferenceSystem_s*)e->gg.g.n)
	  len += zx_LEN_SO_gl_CoordinateReferenceSystem(c, e);
  }
  {
      struct zx_gl_CivilData_s* e;
      for (e = x->CivilData; e; e = (struct zx_gl_CivilData_s*)e->gg.g.n)
	  len += zx_LEN_SO_gl_CivilData(c, e);
  }
  {
      struct zx_gl_shape_s* e;
      for (e = x->shape; e; e = (struct zx_gl_shape_s*)e->gg.g.n)
	  len += zx_LEN_SO_gl_shape(c, e);
  }
  for (se = x->speed; se; se = (struct zx_elem_s*)se->g.n)
    len += zx_LEN_SO_simple_elem(c,se, sizeof("gl:speed")-1, zx_ns_tab+zx_xmlns_ix_gl);
  for (se = x->alt; se; se = (struct zx_elem_s*)se->g.n)
    len += zx_LEN_SO_simple_elem(c,se, sizeof("gl:alt")-1, zx_ns_tab+zx_xmlns_ix_gl);
  for (se = x->direction; se; se = (struct zx_elem_s*)se->g.n)
    len += zx_LEN_SO_simple_elem(c,se, sizeof("gl:direction")-1, zx_ns_tab+zx_xmlns_ix_gl);
  for (se = x->Heading; se; se = (struct zx_elem_s*)se->g.n)
    len += zx_LEN_SO_simple_elem(c,se, sizeof("gl:Heading")-1, zx_ns_tab+zx_xmlns_ix_gl);
  {
      struct zx_gl_Extension_s* e;
      for (e = x->Extension; e; e = (struct zx_gl_Extension_s*)e->gg.g.n)
	  len += zx_LEN_SO_gl_Extension(c, e);
  }


  len += zx_len_so_common(c, &x->gg);
  zx_pop_seen(pop_seen);
  ENC_LEN_DEBUG(x, "gl:geoinfo", len);
  return len;
}

/* FUNC(zx_LEN_WO_gl_geoinfo) */

/* Compute length of an element (and its subelements). The XML attributes
 * and elements are processed in wire order and no assumptions
 * are made about namespace prefixes. */

/* Called by: */
int zx_LEN_WO_gl_geoinfo(struct zx_ctx* c, struct zx_gl_geoinfo_s* x )
{
  struct zx_ns_s* pop_seen = 0;
  struct zx_elem_s* se MAYBE_UNUSED;
#if 1 /* NORMALMODE */
  int len = 1 + sizeof("geoinfo")-1 + 1 + 2 + sizeof("geoinfo")-1 + 1;
  
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
      struct zx_gl_CoordinateReferenceSystem_s* e;
      for (e = x->CoordinateReferenceSystem; e; e = (struct zx_gl_CoordinateReferenceSystem_s*)e->gg.g.n)
	  len += zx_LEN_WO_gl_CoordinateReferenceSystem(c, e);
  }
  {
      struct zx_gl_CivilData_s* e;
      for (e = x->CivilData; e; e = (struct zx_gl_CivilData_s*)e->gg.g.n)
	  len += zx_LEN_WO_gl_CivilData(c, e);
  }
  {
      struct zx_gl_shape_s* e;
      for (e = x->shape; e; e = (struct zx_gl_shape_s*)e->gg.g.n)
	  len += zx_LEN_WO_gl_shape(c, e);
  }
  for (se = x->speed; se; se = (struct zx_elem_s*)se->g.n)
    len += zx_LEN_WO_simple_elem(c, se, sizeof("speed")-1);
  for (se = x->alt; se; se = (struct zx_elem_s*)se->g.n)
    len += zx_LEN_WO_simple_elem(c, se, sizeof("alt")-1);
  for (se = x->direction; se; se = (struct zx_elem_s*)se->g.n)
    len += zx_LEN_WO_simple_elem(c, se, sizeof("direction")-1);
  for (se = x->Heading; se; se = (struct zx_elem_s*)se->g.n)
    len += zx_LEN_WO_simple_elem(c, se, sizeof("Heading")-1);
  {
      struct zx_gl_Extension_s* e;
      for (e = x->Extension; e; e = (struct zx_gl_Extension_s*)e->gg.g.n)
	  len += zx_LEN_WO_gl_Extension(c, e);
  }


  len += zx_len_wo_common(c, &x->gg); 
  zx_pop_seen(pop_seen);
  ENC_LEN_DEBUG(x, "gl:geoinfo", len);
  return len;
}

/* FUNC(zx_ENC_SO_gl_geoinfo) */

/* Render element into string. The XML attributes and elements are
 * processed in schema order. This is what you generally want for
 * rendering new data structure to a string. The wo pointers are not used. */

/* Called by: */
char* zx_ENC_SO_gl_geoinfo(struct zx_ctx* c, struct zx_gl_geoinfo_s* x, char* p )
{
  struct zx_elem_s* se MAYBE_UNUSED;
  struct zx_ns_s* pop_seen = 0;
  ENC_LEN_DEBUG_BASE;
#if 1 /* NORMALMODE */
  /* *** in simple_elem case should output ns prefix from ns node. */
  ZX_OUT_TAG(p, "<gl:geoinfo");
  if (c->inc_ns)
    p = zx_enc_inc_ns(c, p, &pop_seen);
  p = zx_enc_xmlns_if_not_seen(c, p, zx_ns_tab+zx_xmlns_ix_gl, &pop_seen);


  p = zx_enc_unknown_attrs(p, x->gg.any_attr);
#else
  /* root node has no begin tag */
#endif
  
  {
      struct zx_gl_CoordinateReferenceSystem_s* e;
      for (e = x->CoordinateReferenceSystem; e; e = (struct zx_gl_CoordinateReferenceSystem_s*)e->gg.g.n)
	  p = zx_ENC_SO_gl_CoordinateReferenceSystem(c, e, p);
  }
  {
      struct zx_gl_CivilData_s* e;
      for (e = x->CivilData; e; e = (struct zx_gl_CivilData_s*)e->gg.g.n)
	  p = zx_ENC_SO_gl_CivilData(c, e, p);
  }
  {
      struct zx_gl_shape_s* e;
      for (e = x->shape; e; e = (struct zx_gl_shape_s*)e->gg.g.n)
	  p = zx_ENC_SO_gl_shape(c, e, p);
  }
  for (se = x->speed; se; se = (struct zx_elem_s*)se->g.n)
    p = zx_ENC_SO_simple_elem(c, se, p, "gl:speed", sizeof("gl:speed")-1, zx_ns_tab+zx_xmlns_ix_gl);
  for (se = x->alt; se; se = (struct zx_elem_s*)se->g.n)
    p = zx_ENC_SO_simple_elem(c, se, p, "gl:alt", sizeof("gl:alt")-1, zx_ns_tab+zx_xmlns_ix_gl);
  for (se = x->direction; se; se = (struct zx_elem_s*)se->g.n)
    p = zx_ENC_SO_simple_elem(c, se, p, "gl:direction", sizeof("gl:direction")-1, zx_ns_tab+zx_xmlns_ix_gl);
  for (se = x->Heading; se; se = (struct zx_elem_s*)se->g.n)
    p = zx_ENC_SO_simple_elem(c, se, p, "gl:Heading", sizeof("gl:Heading")-1, zx_ns_tab+zx_xmlns_ix_gl);
  {
      struct zx_gl_Extension_s* e;
      for (e = x->Extension; e; e = (struct zx_gl_Extension_s*)e->gg.g.n)
	  p = zx_ENC_SO_gl_Extension(c, e, p);
  }

  p = zx_enc_so_unknown_elems_and_content(c, p, &x->gg);
  
#if 1 /* NORMALMODE */
  ZX_OUT_CLOSE_TAG(p, "</gl:geoinfo>");
  zx_pop_seen(pop_seen);
#else
  /* root node has no end tag either */
#endif
  ENC_LEN_DEBUG(x, "gl:geoinfo", p-enc_base);
  return p;
}

/* FUNC(zx_ENC_WO_gl_geoinfo) */

/* Render element into string. The XML attributes and elements are
 * processed in wire order by chasing wo pointers. This is what you want for
 * validating signatures on other people's XML documents. */

/* Called by: */
char* zx_ENC_WO_gl_geoinfo(struct zx_ctx* c, struct zx_gl_geoinfo_s* x, char* p )
{
  struct zx_elem_s* kid;
  struct zx_ns_s* pop_seen = 0;
  ENC_LEN_DEBUG_BASE;
#if 1 /* NORMALMODE */
  char* q;
  char* qq;
  ZX_OUT_CH(p, '<');
  q = p;
  if (x->gg.g.ns && x->gg.g.ns->prefix_len) {
    ZX_OUT_MEM(p, x->gg.g.ns->prefix, x->gg.g.ns->prefix_len);
    ZX_OUT_CH(p, ':');
  }
  ZX_OUT_MEM(p, "geoinfo", sizeof("geoinfo")-1);
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
  ENC_LEN_DEBUG(x, "gl:geoinfo", p-enc_base);
  return p;
}

/* FUNC(zx_EASY_ENC_SO_gl_geoinfo) */

/* Called by: */
struct zx_str* zx_EASY_ENC_SO_gl_geoinfo(struct zx_ctx* c, struct zx_gl_geoinfo_s* x )
{
  int len;
  char* buf;
  c->ns_tab = ZX_ALLOC(c, sizeof(zx_ns_tab));
  memcpy(c->ns_tab, zx_ns_tab, sizeof(zx_ns_tab));
  len = zx_LEN_SO_gl_geoinfo(c, x );
  buf = ZX_ALLOC(c, len+1);
  return zx_easy_enc_common(c, zx_ENC_SO_gl_geoinfo(c, x, buf ), buf, len);
}

/* FUNC(zx_EASY_ENC_WO_gl_geoinfo) */

/* Called by: */
struct zx_str* zx_EASY_ENC_WO_gl_geoinfo(struct zx_ctx* c, struct zx_gl_geoinfo_s* x )
{
  int len;
  char* buf;
  c->ns_tab = ZX_ALLOC(c, sizeof(zx_ns_tab));
  memcpy(c->ns_tab, zx_ns_tab, sizeof(zx_ns_tab));
  len = zx_LEN_WO_gl_geoinfo(c, x );
  buf = ZX_ALLOC(c, len+1);
  return zx_easy_enc_common(c, zx_ENC_WO_gl_geoinfo(c, x, buf ), buf, len);
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

#define EL_NAME   gl_innerBoundaryIs
#define EL_STRUCT zx_gl_innerBoundaryIs_s
#define EL_NS     gl
#define EL_TAG    innerBoundaryIs

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

/* FUNC(zx_LEN_SO_gl_innerBoundaryIs) */

/* Compute length of an element (and its subelements). The XML attributes
 * and elements are processed in schema order. */

/* Called by: */
int zx_LEN_SO_gl_innerBoundaryIs(struct zx_ctx* c, struct zx_gl_innerBoundaryIs_s* x )
{
  struct zx_ns_s* pop_seen = 0;
  struct zx_elem_s* se MAYBE_UNUSED;
#if 1 /* NORMALMODE */
  /* *** in simple_elem case should output ns prefix from ns node. */
  int len = sizeof("<gl:innerBoundaryIs")-1 + 1 + sizeof("</gl:innerBoundaryIs>")-1;
  if (c->inc_ns_len)
    len += zx_len_inc_ns(c, &pop_seen);
  len += zx_len_xmlns_if_not_seen(c, zx_ns_tab+zx_xmlns_ix_gl, &pop_seen);


#else
  /* root node has no begin tag */
  int len = 0;
#endif
  
  {
      struct zx_gl_LinearRing_s* e;
      for (e = x->LinearRing; e; e = (struct zx_gl_LinearRing_s*)e->gg.g.n)
	  len += zx_LEN_SO_gl_LinearRing(c, e);
  }


  len += zx_len_so_common(c, &x->gg);
  zx_pop_seen(pop_seen);
  ENC_LEN_DEBUG(x, "gl:innerBoundaryIs", len);
  return len;
}

/* FUNC(zx_LEN_WO_gl_innerBoundaryIs) */

/* Compute length of an element (and its subelements). The XML attributes
 * and elements are processed in wire order and no assumptions
 * are made about namespace prefixes. */

/* Called by: */
int zx_LEN_WO_gl_innerBoundaryIs(struct zx_ctx* c, struct zx_gl_innerBoundaryIs_s* x )
{
  struct zx_ns_s* pop_seen = 0;
  struct zx_elem_s* se MAYBE_UNUSED;
#if 1 /* NORMALMODE */
  int len = 1 + sizeof("innerBoundaryIs")-1 + 1 + 2 + sizeof("innerBoundaryIs")-1 + 1;
  
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
      struct zx_gl_LinearRing_s* e;
      for (e = x->LinearRing; e; e = (struct zx_gl_LinearRing_s*)e->gg.g.n)
	  len += zx_LEN_WO_gl_LinearRing(c, e);
  }


  len += zx_len_wo_common(c, &x->gg); 
  zx_pop_seen(pop_seen);
  ENC_LEN_DEBUG(x, "gl:innerBoundaryIs", len);
  return len;
}

/* FUNC(zx_ENC_SO_gl_innerBoundaryIs) */

/* Render element into string. The XML attributes and elements are
 * processed in schema order. This is what you generally want for
 * rendering new data structure to a string. The wo pointers are not used. */

/* Called by: */
char* zx_ENC_SO_gl_innerBoundaryIs(struct zx_ctx* c, struct zx_gl_innerBoundaryIs_s* x, char* p )
{
  struct zx_elem_s* se MAYBE_UNUSED;
  struct zx_ns_s* pop_seen = 0;
  ENC_LEN_DEBUG_BASE;
#if 1 /* NORMALMODE */
  /* *** in simple_elem case should output ns prefix from ns node. */
  ZX_OUT_TAG(p, "<gl:innerBoundaryIs");
  if (c->inc_ns)
    p = zx_enc_inc_ns(c, p, &pop_seen);
  p = zx_enc_xmlns_if_not_seen(c, p, zx_ns_tab+zx_xmlns_ix_gl, &pop_seen);


  p = zx_enc_unknown_attrs(p, x->gg.any_attr);
#else
  /* root node has no begin tag */
#endif
  
  {
      struct zx_gl_LinearRing_s* e;
      for (e = x->LinearRing; e; e = (struct zx_gl_LinearRing_s*)e->gg.g.n)
	  p = zx_ENC_SO_gl_LinearRing(c, e, p);
  }

  p = zx_enc_so_unknown_elems_and_content(c, p, &x->gg);
  
#if 1 /* NORMALMODE */
  ZX_OUT_CLOSE_TAG(p, "</gl:innerBoundaryIs>");
  zx_pop_seen(pop_seen);
#else
  /* root node has no end tag either */
#endif
  ENC_LEN_DEBUG(x, "gl:innerBoundaryIs", p-enc_base);
  return p;
}

/* FUNC(zx_ENC_WO_gl_innerBoundaryIs) */

/* Render element into string. The XML attributes and elements are
 * processed in wire order by chasing wo pointers. This is what you want for
 * validating signatures on other people's XML documents. */

/* Called by: */
char* zx_ENC_WO_gl_innerBoundaryIs(struct zx_ctx* c, struct zx_gl_innerBoundaryIs_s* x, char* p )
{
  struct zx_elem_s* kid;
  struct zx_ns_s* pop_seen = 0;
  ENC_LEN_DEBUG_BASE;
#if 1 /* NORMALMODE */
  char* q;
  char* qq;
  ZX_OUT_CH(p, '<');
  q = p;
  if (x->gg.g.ns && x->gg.g.ns->prefix_len) {
    ZX_OUT_MEM(p, x->gg.g.ns->prefix, x->gg.g.ns->prefix_len);
    ZX_OUT_CH(p, ':');
  }
  ZX_OUT_MEM(p, "innerBoundaryIs", sizeof("innerBoundaryIs")-1);
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
  ENC_LEN_DEBUG(x, "gl:innerBoundaryIs", p-enc_base);
  return p;
}

/* FUNC(zx_EASY_ENC_SO_gl_innerBoundaryIs) */

/* Called by: */
struct zx_str* zx_EASY_ENC_SO_gl_innerBoundaryIs(struct zx_ctx* c, struct zx_gl_innerBoundaryIs_s* x )
{
  int len;
  char* buf;
  c->ns_tab = ZX_ALLOC(c, sizeof(zx_ns_tab));
  memcpy(c->ns_tab, zx_ns_tab, sizeof(zx_ns_tab));
  len = zx_LEN_SO_gl_innerBoundaryIs(c, x );
  buf = ZX_ALLOC(c, len+1);
  return zx_easy_enc_common(c, zx_ENC_SO_gl_innerBoundaryIs(c, x, buf ), buf, len);
}

/* FUNC(zx_EASY_ENC_WO_gl_innerBoundaryIs) */

/* Called by: */
struct zx_str* zx_EASY_ENC_WO_gl_innerBoundaryIs(struct zx_ctx* c, struct zx_gl_innerBoundaryIs_s* x )
{
  int len;
  char* buf;
  c->ns_tab = ZX_ALLOC(c, sizeof(zx_ns_tab));
  memcpy(c->ns_tab, zx_ns_tab, sizeof(zx_ns_tab));
  len = zx_LEN_WO_gl_innerBoundaryIs(c, x );
  buf = ZX_ALLOC(c, len+1);
  return zx_easy_enc_common(c, zx_ENC_WO_gl_innerBoundaryIs(c, x, buf ), buf, len);
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

#define EL_NAME   gl_loc_type
#define EL_STRUCT zx_gl_loc_type_s
#define EL_NS     gl
#define EL_TAG    loc_type

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

/* FUNC(zx_LEN_SO_gl_loc_type) */

/* Compute length of an element (and its subelements). The XML attributes
 * and elements are processed in schema order. */

/* Called by: */
int zx_LEN_SO_gl_loc_type(struct zx_ctx* c, struct zx_gl_loc_type_s* x )
{
  struct zx_ns_s* pop_seen = 0;
  struct zx_elem_s* se MAYBE_UNUSED;
#if 1 /* NORMALMODE */
  /* *** in simple_elem case should output ns prefix from ns node. */
  int len = sizeof("<gl:loc_type")-1 + 1 + sizeof("</gl:loc_type>")-1;
  if (c->inc_ns_len)
    len += zx_len_inc_ns(c, &pop_seen);
  len += zx_len_xmlns_if_not_seen(c, zx_ns_tab+zx_xmlns_ix_gl, &pop_seen);

  len += zx_attr_so_len(x->type, sizeof("type")-1);

#else
  /* root node has no begin tag */
  int len = 0;
#endif
  


  len += zx_len_so_common(c, &x->gg);
  zx_pop_seen(pop_seen);
  ENC_LEN_DEBUG(x, "gl:loc_type", len);
  return len;
}

/* FUNC(zx_LEN_WO_gl_loc_type) */

/* Compute length of an element (and its subelements). The XML attributes
 * and elements are processed in wire order and no assumptions
 * are made about namespace prefixes. */

/* Called by: */
int zx_LEN_WO_gl_loc_type(struct zx_ctx* c, struct zx_gl_loc_type_s* x )
{
  struct zx_ns_s* pop_seen = 0;
  struct zx_elem_s* se MAYBE_UNUSED;
#if 1 /* NORMALMODE */
  int len = 1 + sizeof("loc_type")-1 + 1 + 2 + sizeof("loc_type")-1 + 1;
  
  if (x->gg.g.ns && x->gg.g.ns->prefix_len)
    len += (x->gg.g.ns->prefix_len + 1) * 2;
  if (c->inc_ns_len)
    len += zx_len_inc_ns(c, &pop_seen);
  len += zx_len_xmlns_if_not_seen(c, x->gg.g.ns, &pop_seen);

  len += zx_attr_wo_len(x->type, sizeof("type")-1);

#else
  /* root node has no begin tag */
  int len = 0;
#endif
  


  len += zx_len_wo_common(c, &x->gg); 
  zx_pop_seen(pop_seen);
  ENC_LEN_DEBUG(x, "gl:loc_type", len);
  return len;
}

/* FUNC(zx_ENC_SO_gl_loc_type) */

/* Render element into string. The XML attributes and elements are
 * processed in schema order. This is what you generally want for
 * rendering new data structure to a string. The wo pointers are not used. */

/* Called by: */
char* zx_ENC_SO_gl_loc_type(struct zx_ctx* c, struct zx_gl_loc_type_s* x, char* p )
{
  struct zx_elem_s* se MAYBE_UNUSED;
  struct zx_ns_s* pop_seen = 0;
  ENC_LEN_DEBUG_BASE;
#if 1 /* NORMALMODE */
  /* *** in simple_elem case should output ns prefix from ns node. */
  ZX_OUT_TAG(p, "<gl:loc_type");
  if (c->inc_ns)
    p = zx_enc_inc_ns(c, p, &pop_seen);
  p = zx_enc_xmlns_if_not_seen(c, p, zx_ns_tab+zx_xmlns_ix_gl, &pop_seen);

  p = zx_attr_so_enc(p, x->type, " type=\"", sizeof(" type=\"")-1);

  p = zx_enc_unknown_attrs(p, x->gg.any_attr);
#else
  /* root node has no begin tag */
#endif
  

  p = zx_enc_so_unknown_elems_and_content(c, p, &x->gg);
  
#if 1 /* NORMALMODE */
  ZX_OUT_CLOSE_TAG(p, "</gl:loc_type>");
  zx_pop_seen(pop_seen);
#else
  /* root node has no end tag either */
#endif
  ENC_LEN_DEBUG(x, "gl:loc_type", p-enc_base);
  return p;
}

/* FUNC(zx_ENC_WO_gl_loc_type) */

/* Render element into string. The XML attributes and elements are
 * processed in wire order by chasing wo pointers. This is what you want for
 * validating signatures on other people's XML documents. */

/* Called by: */
char* zx_ENC_WO_gl_loc_type(struct zx_ctx* c, struct zx_gl_loc_type_s* x, char* p )
{
  struct zx_elem_s* kid;
  struct zx_ns_s* pop_seen = 0;
  ENC_LEN_DEBUG_BASE;
#if 1 /* NORMALMODE */
  char* q;
  char* qq;
  ZX_OUT_CH(p, '<');
  q = p;
  if (x->gg.g.ns && x->gg.g.ns->prefix_len) {
    ZX_OUT_MEM(p, x->gg.g.ns->prefix, x->gg.g.ns->prefix_len);
    ZX_OUT_CH(p, ':');
  }
  ZX_OUT_MEM(p, "loc_type", sizeof("loc_type")-1);
  qq = p;

  /* *** sort the namespaces */
  if (c->inc_ns)
    zx_add_inc_ns(c, &pop_seen);
  zx_add_xmlns_if_not_seen(c, x->gg.g.ns, &pop_seen);

  p = zx_enc_seen(p, pop_seen); 
  p = zx_attr_wo_enc(p, x->type, "type=\"", sizeof("type=\"")-1);

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
  ENC_LEN_DEBUG(x, "gl:loc_type", p-enc_base);
  return p;
}

/* FUNC(zx_EASY_ENC_SO_gl_loc_type) */

/* Called by: */
struct zx_str* zx_EASY_ENC_SO_gl_loc_type(struct zx_ctx* c, struct zx_gl_loc_type_s* x )
{
  int len;
  char* buf;
  c->ns_tab = ZX_ALLOC(c, sizeof(zx_ns_tab));
  memcpy(c->ns_tab, zx_ns_tab, sizeof(zx_ns_tab));
  len = zx_LEN_SO_gl_loc_type(c, x );
  buf = ZX_ALLOC(c, len+1);
  return zx_easy_enc_common(c, zx_ENC_SO_gl_loc_type(c, x, buf ), buf, len);
}

/* FUNC(zx_EASY_ENC_WO_gl_loc_type) */

/* Called by: */
struct zx_str* zx_EASY_ENC_WO_gl_loc_type(struct zx_ctx* c, struct zx_gl_loc_type_s* x )
{
  int len;
  char* buf;
  c->ns_tab = ZX_ALLOC(c, sizeof(zx_ns_tab));
  memcpy(c->ns_tab, zx_ns_tab, sizeof(zx_ns_tab));
  len = zx_LEN_WO_gl_loc_type(c, x );
  buf = ZX_ALLOC(c, len+1);
  return zx_easy_enc_common(c, zx_ENC_WO_gl_loc_type(c, x, buf ), buf, len);
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

#define EL_NAME   gl_ms_action
#define EL_STRUCT zx_gl_ms_action_s
#define EL_NS     gl
#define EL_TAG    ms_action

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

/* FUNC(zx_LEN_SO_gl_ms_action) */

/* Compute length of an element (and its subelements). The XML attributes
 * and elements are processed in schema order. */

/* Called by: */
int zx_LEN_SO_gl_ms_action(struct zx_ctx* c, struct zx_gl_ms_action_s* x )
{
  struct zx_ns_s* pop_seen = 0;
  struct zx_elem_s* se MAYBE_UNUSED;
#if 1 /* NORMALMODE */
  /* *** in simple_elem case should output ns prefix from ns node. */
  int len = sizeof("<gl:ms_action")-1 + 1 + sizeof("</gl:ms_action>")-1;
  if (c->inc_ns_len)
    len += zx_len_inc_ns(c, &pop_seen);
  len += zx_len_xmlns_if_not_seen(c, zx_ns_tab+zx_xmlns_ix_gl, &pop_seen);

  len += zx_attr_so_len(x->type, sizeof("type")-1);

#else
  /* root node has no begin tag */
  int len = 0;
#endif
  


  len += zx_len_so_common(c, &x->gg);
  zx_pop_seen(pop_seen);
  ENC_LEN_DEBUG(x, "gl:ms_action", len);
  return len;
}

/* FUNC(zx_LEN_WO_gl_ms_action) */

/* Compute length of an element (and its subelements). The XML attributes
 * and elements are processed in wire order and no assumptions
 * are made about namespace prefixes. */

/* Called by: */
int zx_LEN_WO_gl_ms_action(struct zx_ctx* c, struct zx_gl_ms_action_s* x )
{
  struct zx_ns_s* pop_seen = 0;
  struct zx_elem_s* se MAYBE_UNUSED;
#if 1 /* NORMALMODE */
  int len = 1 + sizeof("ms_action")-1 + 1 + 2 + sizeof("ms_action")-1 + 1;
  
  if (x->gg.g.ns && x->gg.g.ns->prefix_len)
    len += (x->gg.g.ns->prefix_len + 1) * 2;
  if (c->inc_ns_len)
    len += zx_len_inc_ns(c, &pop_seen);
  len += zx_len_xmlns_if_not_seen(c, x->gg.g.ns, &pop_seen);

  len += zx_attr_wo_len(x->type, sizeof("type")-1);

#else
  /* root node has no begin tag */
  int len = 0;
#endif
  


  len += zx_len_wo_common(c, &x->gg); 
  zx_pop_seen(pop_seen);
  ENC_LEN_DEBUG(x, "gl:ms_action", len);
  return len;
}

/* FUNC(zx_ENC_SO_gl_ms_action) */

/* Render element into string. The XML attributes and elements are
 * processed in schema order. This is what you generally want for
 * rendering new data structure to a string. The wo pointers are not used. */

/* Called by: */
char* zx_ENC_SO_gl_ms_action(struct zx_ctx* c, struct zx_gl_ms_action_s* x, char* p )
{
  struct zx_elem_s* se MAYBE_UNUSED;
  struct zx_ns_s* pop_seen = 0;
  ENC_LEN_DEBUG_BASE;
#if 1 /* NORMALMODE */
  /* *** in simple_elem case should output ns prefix from ns node. */
  ZX_OUT_TAG(p, "<gl:ms_action");
  if (c->inc_ns)
    p = zx_enc_inc_ns(c, p, &pop_seen);
  p = zx_enc_xmlns_if_not_seen(c, p, zx_ns_tab+zx_xmlns_ix_gl, &pop_seen);

  p = zx_attr_so_enc(p, x->type, " type=\"", sizeof(" type=\"")-1);

  p = zx_enc_unknown_attrs(p, x->gg.any_attr);
#else
  /* root node has no begin tag */
#endif
  

  p = zx_enc_so_unknown_elems_and_content(c, p, &x->gg);
  
#if 1 /* NORMALMODE */
  ZX_OUT_CLOSE_TAG(p, "</gl:ms_action>");
  zx_pop_seen(pop_seen);
#else
  /* root node has no end tag either */
#endif
  ENC_LEN_DEBUG(x, "gl:ms_action", p-enc_base);
  return p;
}

/* FUNC(zx_ENC_WO_gl_ms_action) */

/* Render element into string. The XML attributes and elements are
 * processed in wire order by chasing wo pointers. This is what you want for
 * validating signatures on other people's XML documents. */

/* Called by: */
char* zx_ENC_WO_gl_ms_action(struct zx_ctx* c, struct zx_gl_ms_action_s* x, char* p )
{
  struct zx_elem_s* kid;
  struct zx_ns_s* pop_seen = 0;
  ENC_LEN_DEBUG_BASE;
#if 1 /* NORMALMODE */
  char* q;
  char* qq;
  ZX_OUT_CH(p, '<');
  q = p;
  if (x->gg.g.ns && x->gg.g.ns->prefix_len) {
    ZX_OUT_MEM(p, x->gg.g.ns->prefix, x->gg.g.ns->prefix_len);
    ZX_OUT_CH(p, ':');
  }
  ZX_OUT_MEM(p, "ms_action", sizeof("ms_action")-1);
  qq = p;

  /* *** sort the namespaces */
  if (c->inc_ns)
    zx_add_inc_ns(c, &pop_seen);
  zx_add_xmlns_if_not_seen(c, x->gg.g.ns, &pop_seen);

  p = zx_enc_seen(p, pop_seen); 
  p = zx_attr_wo_enc(p, x->type, "type=\"", sizeof("type=\"")-1);

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
  ENC_LEN_DEBUG(x, "gl:ms_action", p-enc_base);
  return p;
}

/* FUNC(zx_EASY_ENC_SO_gl_ms_action) */

/* Called by: */
struct zx_str* zx_EASY_ENC_SO_gl_ms_action(struct zx_ctx* c, struct zx_gl_ms_action_s* x )
{
  int len;
  char* buf;
  c->ns_tab = ZX_ALLOC(c, sizeof(zx_ns_tab));
  memcpy(c->ns_tab, zx_ns_tab, sizeof(zx_ns_tab));
  len = zx_LEN_SO_gl_ms_action(c, x );
  buf = ZX_ALLOC(c, len+1);
  return zx_easy_enc_common(c, zx_ENC_SO_gl_ms_action(c, x, buf ), buf, len);
}

/* FUNC(zx_EASY_ENC_WO_gl_ms_action) */

/* Called by: */
struct zx_str* zx_EASY_ENC_WO_gl_ms_action(struct zx_ctx* c, struct zx_gl_ms_action_s* x )
{
  int len;
  char* buf;
  c->ns_tab = ZX_ALLOC(c, sizeof(zx_ns_tab));
  memcpy(c->ns_tab, zx_ns_tab, sizeof(zx_ns_tab));
  len = zx_LEN_WO_gl_ms_action(c, x );
  buf = ZX_ALLOC(c, len+1);
  return zx_easy_enc_common(c, zx_ENC_WO_gl_ms_action(c, x, buf ), buf, len);
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

#define EL_NAME   gl_outerBoundaryIs
#define EL_STRUCT zx_gl_outerBoundaryIs_s
#define EL_NS     gl
#define EL_TAG    outerBoundaryIs

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

/* FUNC(zx_LEN_SO_gl_outerBoundaryIs) */

/* Compute length of an element (and its subelements). The XML attributes
 * and elements are processed in schema order. */

/* Called by: */
int zx_LEN_SO_gl_outerBoundaryIs(struct zx_ctx* c, struct zx_gl_outerBoundaryIs_s* x )
{
  struct zx_ns_s* pop_seen = 0;
  struct zx_elem_s* se MAYBE_UNUSED;
#if 1 /* NORMALMODE */
  /* *** in simple_elem case should output ns prefix from ns node. */
  int len = sizeof("<gl:outerBoundaryIs")-1 + 1 + sizeof("</gl:outerBoundaryIs>")-1;
  if (c->inc_ns_len)
    len += zx_len_inc_ns(c, &pop_seen);
  len += zx_len_xmlns_if_not_seen(c, zx_ns_tab+zx_xmlns_ix_gl, &pop_seen);


#else
  /* root node has no begin tag */
  int len = 0;
#endif
  
  {
      struct zx_gl_LinearRing_s* e;
      for (e = x->LinearRing; e; e = (struct zx_gl_LinearRing_s*)e->gg.g.n)
	  len += zx_LEN_SO_gl_LinearRing(c, e);
  }


  len += zx_len_so_common(c, &x->gg);
  zx_pop_seen(pop_seen);
  ENC_LEN_DEBUG(x, "gl:outerBoundaryIs", len);
  return len;
}

/* FUNC(zx_LEN_WO_gl_outerBoundaryIs) */

/* Compute length of an element (and its subelements). The XML attributes
 * and elements are processed in wire order and no assumptions
 * are made about namespace prefixes. */

/* Called by: */
int zx_LEN_WO_gl_outerBoundaryIs(struct zx_ctx* c, struct zx_gl_outerBoundaryIs_s* x )
{
  struct zx_ns_s* pop_seen = 0;
  struct zx_elem_s* se MAYBE_UNUSED;
#if 1 /* NORMALMODE */
  int len = 1 + sizeof("outerBoundaryIs")-1 + 1 + 2 + sizeof("outerBoundaryIs")-1 + 1;
  
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
      struct zx_gl_LinearRing_s* e;
      for (e = x->LinearRing; e; e = (struct zx_gl_LinearRing_s*)e->gg.g.n)
	  len += zx_LEN_WO_gl_LinearRing(c, e);
  }


  len += zx_len_wo_common(c, &x->gg); 
  zx_pop_seen(pop_seen);
  ENC_LEN_DEBUG(x, "gl:outerBoundaryIs", len);
  return len;
}

/* FUNC(zx_ENC_SO_gl_outerBoundaryIs) */

/* Render element into string. The XML attributes and elements are
 * processed in schema order. This is what you generally want for
 * rendering new data structure to a string. The wo pointers are not used. */

/* Called by: */
char* zx_ENC_SO_gl_outerBoundaryIs(struct zx_ctx* c, struct zx_gl_outerBoundaryIs_s* x, char* p )
{
  struct zx_elem_s* se MAYBE_UNUSED;
  struct zx_ns_s* pop_seen = 0;
  ENC_LEN_DEBUG_BASE;
#if 1 /* NORMALMODE */
  /* *** in simple_elem case should output ns prefix from ns node. */
  ZX_OUT_TAG(p, "<gl:outerBoundaryIs");
  if (c->inc_ns)
    p = zx_enc_inc_ns(c, p, &pop_seen);
  p = zx_enc_xmlns_if_not_seen(c, p, zx_ns_tab+zx_xmlns_ix_gl, &pop_seen);


  p = zx_enc_unknown_attrs(p, x->gg.any_attr);
#else
  /* root node has no begin tag */
#endif
  
  {
      struct zx_gl_LinearRing_s* e;
      for (e = x->LinearRing; e; e = (struct zx_gl_LinearRing_s*)e->gg.g.n)
	  p = zx_ENC_SO_gl_LinearRing(c, e, p);
  }

  p = zx_enc_so_unknown_elems_and_content(c, p, &x->gg);
  
#if 1 /* NORMALMODE */
  ZX_OUT_CLOSE_TAG(p, "</gl:outerBoundaryIs>");
  zx_pop_seen(pop_seen);
#else
  /* root node has no end tag either */
#endif
  ENC_LEN_DEBUG(x, "gl:outerBoundaryIs", p-enc_base);
  return p;
}

/* FUNC(zx_ENC_WO_gl_outerBoundaryIs) */

/* Render element into string. The XML attributes and elements are
 * processed in wire order by chasing wo pointers. This is what you want for
 * validating signatures on other people's XML documents. */

/* Called by: */
char* zx_ENC_WO_gl_outerBoundaryIs(struct zx_ctx* c, struct zx_gl_outerBoundaryIs_s* x, char* p )
{
  struct zx_elem_s* kid;
  struct zx_ns_s* pop_seen = 0;
  ENC_LEN_DEBUG_BASE;
#if 1 /* NORMALMODE */
  char* q;
  char* qq;
  ZX_OUT_CH(p, '<');
  q = p;
  if (x->gg.g.ns && x->gg.g.ns->prefix_len) {
    ZX_OUT_MEM(p, x->gg.g.ns->prefix, x->gg.g.ns->prefix_len);
    ZX_OUT_CH(p, ':');
  }
  ZX_OUT_MEM(p, "outerBoundaryIs", sizeof("outerBoundaryIs")-1);
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
  ENC_LEN_DEBUG(x, "gl:outerBoundaryIs", p-enc_base);
  return p;
}

/* FUNC(zx_EASY_ENC_SO_gl_outerBoundaryIs) */

/* Called by: */
struct zx_str* zx_EASY_ENC_SO_gl_outerBoundaryIs(struct zx_ctx* c, struct zx_gl_outerBoundaryIs_s* x )
{
  int len;
  char* buf;
  c->ns_tab = ZX_ALLOC(c, sizeof(zx_ns_tab));
  memcpy(c->ns_tab, zx_ns_tab, sizeof(zx_ns_tab));
  len = zx_LEN_SO_gl_outerBoundaryIs(c, x );
  buf = ZX_ALLOC(c, len+1);
  return zx_easy_enc_common(c, zx_ENC_SO_gl_outerBoundaryIs(c, x, buf ), buf, len);
}

/* FUNC(zx_EASY_ENC_WO_gl_outerBoundaryIs) */

/* Called by: */
struct zx_str* zx_EASY_ENC_WO_gl_outerBoundaryIs(struct zx_ctx* c, struct zx_gl_outerBoundaryIs_s* x )
{
  int len;
  char* buf;
  c->ns_tab = ZX_ALLOC(c, sizeof(zx_ns_tab));
  memcpy(c->ns_tab, zx_ns_tab, sizeof(zx_ns_tab));
  len = zx_LEN_WO_gl_outerBoundaryIs(c, x );
  buf = ZX_ALLOC(c, len+1);
  return zx_easy_enc_common(c, zx_ENC_WO_gl_outerBoundaryIs(c, x, buf ), buf, len);
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

#define EL_NAME   gl_pd
#define EL_STRUCT zx_gl_pd_s
#define EL_NS     gl
#define EL_TAG    pd

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

/* FUNC(zx_LEN_SO_gl_pd) */

/* Compute length of an element (and its subelements). The XML attributes
 * and elements are processed in schema order. */

/* Called by: */
int zx_LEN_SO_gl_pd(struct zx_ctx* c, struct zx_gl_pd_s* x )
{
  struct zx_ns_s* pop_seen = 0;
  struct zx_elem_s* se MAYBE_UNUSED;
#if 1 /* NORMALMODE */
  /* *** in simple_elem case should output ns prefix from ns node. */
  int len = sizeof("<gl:pd")-1 + 1 + sizeof("</gl:pd>")-1;
  if (c->inc_ns_len)
    len += zx_len_inc_ns(c, &pop_seen);
  if (x->ACC)
    len += zx_len_xmlns_if_not_seen(c, zx_ns_tab+zx_xmlns_ix_gl, &pop_seen);

  len += zx_attr_so_len(x->ACC, sizeof("gl:ACC")-1);

#else
  /* root node has no begin tag */
  int len = 0;
#endif
  
  for (se = x->time; se; se = (struct zx_elem_s*)se->g.n)
    len += zx_LEN_SO_simple_elem(c,se, sizeof("gl:time")-1, zx_ns_tab+zx_xmlns_ix_gl);
  {
      struct zx_gl_CivilData_s* e;
      for (e = x->CivilData; e; e = (struct zx_gl_CivilData_s*)e->gg.g.n)
	  len += zx_LEN_SO_gl_CivilData(c, e);
  }
  {
      struct zx_gl_shape_s* e;
      for (e = x->shape; e; e = (struct zx_gl_shape_s*)e->gg.g.n)
	  len += zx_LEN_SO_gl_shape(c, e);
  }
  for (se = x->alt; se; se = (struct zx_elem_s*)se->g.n)
    len += zx_LEN_SO_simple_elem(c,se, sizeof("gl:alt")-1, zx_ns_tab+zx_xmlns_ix_gl);
  for (se = x->alt_acc; se; se = (struct zx_elem_s*)se->g.n)
    len += zx_LEN_SO_simple_elem(c,se, sizeof("gl:alt_acc")-1, zx_ns_tab+zx_xmlns_ix_gl);
  for (se = x->speed; se; se = (struct zx_elem_s*)se->g.n)
    len += zx_LEN_SO_simple_elem(c,se, sizeof("gl:speed")-1, zx_ns_tab+zx_xmlns_ix_gl);
  for (se = x->direction; se; se = (struct zx_elem_s*)se->g.n)
    len += zx_LEN_SO_simple_elem(c,se, sizeof("gl:direction")-1, zx_ns_tab+zx_xmlns_ix_gl);
  for (se = x->Heading; se; se = (struct zx_elem_s*)se->g.n)
    len += zx_LEN_SO_simple_elem(c,se, sizeof("gl:Heading")-1, zx_ns_tab+zx_xmlns_ix_gl);
  for (se = x->lev_conf; se; se = (struct zx_elem_s*)se->g.n)
    len += zx_LEN_SO_simple_elem(c,se, sizeof("gl:lev_conf")-1, zx_ns_tab+zx_xmlns_ix_gl);
  {
      struct zx_gl_Extension_s* e;
      for (e = x->Extension; e; e = (struct zx_gl_Extension_s*)e->gg.g.n)
	  len += zx_LEN_SO_gl_Extension(c, e);
  }


  len += zx_len_so_common(c, &x->gg);
  zx_pop_seen(pop_seen);
  ENC_LEN_DEBUG(x, "gl:pd", len);
  return len;
}

/* FUNC(zx_LEN_WO_gl_pd) */

/* Compute length of an element (and its subelements). The XML attributes
 * and elements are processed in wire order and no assumptions
 * are made about namespace prefixes. */

/* Called by: */
int zx_LEN_WO_gl_pd(struct zx_ctx* c, struct zx_gl_pd_s* x )
{
  struct zx_ns_s* pop_seen = 0;
  struct zx_elem_s* se MAYBE_UNUSED;
#if 1 /* NORMALMODE */
  int len = 1 + sizeof("pd")-1 + 1 + 2 + sizeof("pd")-1 + 1;
  
  if (x->gg.g.ns && x->gg.g.ns->prefix_len)
    len += (x->gg.g.ns->prefix_len + 1) * 2;
  if (c->inc_ns_len)
    len += zx_len_inc_ns(c, &pop_seen);
  if (x->ACC)
    len += zx_len_xmlns_if_not_seen(c, x->ACC->g.ns, &pop_seen);

  len += zx_attr_wo_len(x->ACC, sizeof("ACC")-1);

#else
  /* root node has no begin tag */
  int len = 0;
#endif
  
  for (se = x->time; se; se = (struct zx_elem_s*)se->g.n)
    len += zx_LEN_WO_simple_elem(c, se, sizeof("time")-1);
  {
      struct zx_gl_CivilData_s* e;
      for (e = x->CivilData; e; e = (struct zx_gl_CivilData_s*)e->gg.g.n)
	  len += zx_LEN_WO_gl_CivilData(c, e);
  }
  {
      struct zx_gl_shape_s* e;
      for (e = x->shape; e; e = (struct zx_gl_shape_s*)e->gg.g.n)
	  len += zx_LEN_WO_gl_shape(c, e);
  }
  for (se = x->alt; se; se = (struct zx_elem_s*)se->g.n)
    len += zx_LEN_WO_simple_elem(c, se, sizeof("alt")-1);
  for (se = x->alt_acc; se; se = (struct zx_elem_s*)se->g.n)
    len += zx_LEN_WO_simple_elem(c, se, sizeof("alt_acc")-1);
  for (se = x->speed; se; se = (struct zx_elem_s*)se->g.n)
    len += zx_LEN_WO_simple_elem(c, se, sizeof("speed")-1);
  for (se = x->direction; se; se = (struct zx_elem_s*)se->g.n)
    len += zx_LEN_WO_simple_elem(c, se, sizeof("direction")-1);
  for (se = x->Heading; se; se = (struct zx_elem_s*)se->g.n)
    len += zx_LEN_WO_simple_elem(c, se, sizeof("Heading")-1);
  for (se = x->lev_conf; se; se = (struct zx_elem_s*)se->g.n)
    len += zx_LEN_WO_simple_elem(c, se, sizeof("lev_conf")-1);
  {
      struct zx_gl_Extension_s* e;
      for (e = x->Extension; e; e = (struct zx_gl_Extension_s*)e->gg.g.n)
	  len += zx_LEN_WO_gl_Extension(c, e);
  }


  len += zx_len_wo_common(c, &x->gg); 
  zx_pop_seen(pop_seen);
  ENC_LEN_DEBUG(x, "gl:pd", len);
  return len;
}

/* FUNC(zx_ENC_SO_gl_pd) */

/* Render element into string. The XML attributes and elements are
 * processed in schema order. This is what you generally want for
 * rendering new data structure to a string. The wo pointers are not used. */

/* Called by: */
char* zx_ENC_SO_gl_pd(struct zx_ctx* c, struct zx_gl_pd_s* x, char* p )
{
  struct zx_elem_s* se MAYBE_UNUSED;
  struct zx_ns_s* pop_seen = 0;
  ENC_LEN_DEBUG_BASE;
#if 1 /* NORMALMODE */
  /* *** in simple_elem case should output ns prefix from ns node. */
  ZX_OUT_TAG(p, "<gl:pd");
  if (c->inc_ns)
    p = zx_enc_inc_ns(c, p, &pop_seen);
  if (x->ACC)
    p = zx_enc_xmlns_if_not_seen(c, p, zx_ns_tab+zx_xmlns_ix_gl, &pop_seen);

  p = zx_attr_so_enc(p, x->ACC, " gl:ACC=\"", sizeof(" gl:ACC=\"")-1);

  p = zx_enc_unknown_attrs(p, x->gg.any_attr);
#else
  /* root node has no begin tag */
#endif
  
  for (se = x->time; se; se = (struct zx_elem_s*)se->g.n)
    p = zx_ENC_SO_simple_elem(c, se, p, "gl:time", sizeof("gl:time")-1, zx_ns_tab+zx_xmlns_ix_gl);
  {
      struct zx_gl_CivilData_s* e;
      for (e = x->CivilData; e; e = (struct zx_gl_CivilData_s*)e->gg.g.n)
	  p = zx_ENC_SO_gl_CivilData(c, e, p);
  }
  {
      struct zx_gl_shape_s* e;
      for (e = x->shape; e; e = (struct zx_gl_shape_s*)e->gg.g.n)
	  p = zx_ENC_SO_gl_shape(c, e, p);
  }
  for (se = x->alt; se; se = (struct zx_elem_s*)se->g.n)
    p = zx_ENC_SO_simple_elem(c, se, p, "gl:alt", sizeof("gl:alt")-1, zx_ns_tab+zx_xmlns_ix_gl);
  for (se = x->alt_acc; se; se = (struct zx_elem_s*)se->g.n)
    p = zx_ENC_SO_simple_elem(c, se, p, "gl:alt_acc", sizeof("gl:alt_acc")-1, zx_ns_tab+zx_xmlns_ix_gl);
  for (se = x->speed; se; se = (struct zx_elem_s*)se->g.n)
    p = zx_ENC_SO_simple_elem(c, se, p, "gl:speed", sizeof("gl:speed")-1, zx_ns_tab+zx_xmlns_ix_gl);
  for (se = x->direction; se; se = (struct zx_elem_s*)se->g.n)
    p = zx_ENC_SO_simple_elem(c, se, p, "gl:direction", sizeof("gl:direction")-1, zx_ns_tab+zx_xmlns_ix_gl);
  for (se = x->Heading; se; se = (struct zx_elem_s*)se->g.n)
    p = zx_ENC_SO_simple_elem(c, se, p, "gl:Heading", sizeof("gl:Heading")-1, zx_ns_tab+zx_xmlns_ix_gl);
  for (se = x->lev_conf; se; se = (struct zx_elem_s*)se->g.n)
    p = zx_ENC_SO_simple_elem(c, se, p, "gl:lev_conf", sizeof("gl:lev_conf")-1, zx_ns_tab+zx_xmlns_ix_gl);
  {
      struct zx_gl_Extension_s* e;
      for (e = x->Extension; e; e = (struct zx_gl_Extension_s*)e->gg.g.n)
	  p = zx_ENC_SO_gl_Extension(c, e, p);
  }

  p = zx_enc_so_unknown_elems_and_content(c, p, &x->gg);
  
#if 1 /* NORMALMODE */
  ZX_OUT_CLOSE_TAG(p, "</gl:pd>");
  zx_pop_seen(pop_seen);
#else
  /* root node has no end tag either */
#endif
  ENC_LEN_DEBUG(x, "gl:pd", p-enc_base);
  return p;
}

/* FUNC(zx_ENC_WO_gl_pd) */

/* Render element into string. The XML attributes and elements are
 * processed in wire order by chasing wo pointers. This is what you want for
 * validating signatures on other people's XML documents. */

/* Called by: */
char* zx_ENC_WO_gl_pd(struct zx_ctx* c, struct zx_gl_pd_s* x, char* p )
{
  struct zx_elem_s* kid;
  struct zx_ns_s* pop_seen = 0;
  ENC_LEN_DEBUG_BASE;
#if 1 /* NORMALMODE */
  char* q;
  char* qq;
  ZX_OUT_CH(p, '<');
  q = p;
  if (x->gg.g.ns && x->gg.g.ns->prefix_len) {
    ZX_OUT_MEM(p, x->gg.g.ns->prefix, x->gg.g.ns->prefix_len);
    ZX_OUT_CH(p, ':');
  }
  ZX_OUT_MEM(p, "pd", sizeof("pd")-1);
  qq = p;

  /* *** sort the namespaces */
  if (c->inc_ns)
    zx_add_inc_ns(c, &pop_seen);
  if (x->ACC)
    zx_add_xmlns_if_not_seen(c, x->ACC->g.ns, &pop_seen);

  p = zx_enc_seen(p, pop_seen); 
  p = zx_attr_wo_enc(p, x->ACC, "ACC=\"", sizeof("ACC=\"")-1);

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
  ENC_LEN_DEBUG(x, "gl:pd", p-enc_base);
  return p;
}

/* FUNC(zx_EASY_ENC_SO_gl_pd) */

/* Called by: */
struct zx_str* zx_EASY_ENC_SO_gl_pd(struct zx_ctx* c, struct zx_gl_pd_s* x )
{
  int len;
  char* buf;
  c->ns_tab = ZX_ALLOC(c, sizeof(zx_ns_tab));
  memcpy(c->ns_tab, zx_ns_tab, sizeof(zx_ns_tab));
  len = zx_LEN_SO_gl_pd(c, x );
  buf = ZX_ALLOC(c, len+1);
  return zx_easy_enc_common(c, zx_ENC_SO_gl_pd(c, x, buf ), buf, len);
}

/* FUNC(zx_EASY_ENC_WO_gl_pd) */

/* Called by: */
struct zx_str* zx_EASY_ENC_WO_gl_pd(struct zx_ctx* c, struct zx_gl_pd_s* x )
{
  int len;
  char* buf;
  c->ns_tab = ZX_ALLOC(c, sizeof(zx_ns_tab));
  memcpy(c->ns_tab, zx_ns_tab, sizeof(zx_ns_tab));
  len = zx_LEN_WO_gl_pd(c, x );
  buf = ZX_ALLOC(c, len+1);
  return zx_easy_enc_common(c, zx_ENC_WO_gl_pd(c, x, buf ), buf, len);
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

#define EL_NAME   gl_prio
#define EL_STRUCT zx_gl_prio_s
#define EL_NS     gl
#define EL_TAG    prio

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

/* FUNC(zx_LEN_SO_gl_prio) */

/* Compute length of an element (and its subelements). The XML attributes
 * and elements are processed in schema order. */

/* Called by: */
int zx_LEN_SO_gl_prio(struct zx_ctx* c, struct zx_gl_prio_s* x )
{
  struct zx_ns_s* pop_seen = 0;
  struct zx_elem_s* se MAYBE_UNUSED;
#if 1 /* NORMALMODE */
  /* *** in simple_elem case should output ns prefix from ns node. */
  int len = sizeof("<gl:prio")-1 + 1 + sizeof("</gl:prio>")-1;
  if (c->inc_ns_len)
    len += zx_len_inc_ns(c, &pop_seen);
  len += zx_len_xmlns_if_not_seen(c, zx_ns_tab+zx_xmlns_ix_gl, &pop_seen);

  len += zx_attr_so_len(x->type, sizeof("type")-1);

#else
  /* root node has no begin tag */
  int len = 0;
#endif
  


  len += zx_len_so_common(c, &x->gg);
  zx_pop_seen(pop_seen);
  ENC_LEN_DEBUG(x, "gl:prio", len);
  return len;
}

/* FUNC(zx_LEN_WO_gl_prio) */

/* Compute length of an element (and its subelements). The XML attributes
 * and elements are processed in wire order and no assumptions
 * are made about namespace prefixes. */

/* Called by: */
int zx_LEN_WO_gl_prio(struct zx_ctx* c, struct zx_gl_prio_s* x )
{
  struct zx_ns_s* pop_seen = 0;
  struct zx_elem_s* se MAYBE_UNUSED;
#if 1 /* NORMALMODE */
  int len = 1 + sizeof("prio")-1 + 1 + 2 + sizeof("prio")-1 + 1;
  
  if (x->gg.g.ns && x->gg.g.ns->prefix_len)
    len += (x->gg.g.ns->prefix_len + 1) * 2;
  if (c->inc_ns_len)
    len += zx_len_inc_ns(c, &pop_seen);
  len += zx_len_xmlns_if_not_seen(c, x->gg.g.ns, &pop_seen);

  len += zx_attr_wo_len(x->type, sizeof("type")-1);

#else
  /* root node has no begin tag */
  int len = 0;
#endif
  


  len += zx_len_wo_common(c, &x->gg); 
  zx_pop_seen(pop_seen);
  ENC_LEN_DEBUG(x, "gl:prio", len);
  return len;
}

/* FUNC(zx_ENC_SO_gl_prio) */

/* Render element into string. The XML attributes and elements are
 * processed in schema order. This is what you generally want for
 * rendering new data structure to a string. The wo pointers are not used. */

/* Called by: */
char* zx_ENC_SO_gl_prio(struct zx_ctx* c, struct zx_gl_prio_s* x, char* p )
{
  struct zx_elem_s* se MAYBE_UNUSED;
  struct zx_ns_s* pop_seen = 0;
  ENC_LEN_DEBUG_BASE;
#if 1 /* NORMALMODE */
  /* *** in simple_elem case should output ns prefix from ns node. */
  ZX_OUT_TAG(p, "<gl:prio");
  if (c->inc_ns)
    p = zx_enc_inc_ns(c, p, &pop_seen);
  p = zx_enc_xmlns_if_not_seen(c, p, zx_ns_tab+zx_xmlns_ix_gl, &pop_seen);

  p = zx_attr_so_enc(p, x->type, " type=\"", sizeof(" type=\"")-1);

  p = zx_enc_unknown_attrs(p, x->gg.any_attr);
#else
  /* root node has no begin tag */
#endif
  

  p = zx_enc_so_unknown_elems_and_content(c, p, &x->gg);
  
#if 1 /* NORMALMODE */
  ZX_OUT_CLOSE_TAG(p, "</gl:prio>");
  zx_pop_seen(pop_seen);
#else
  /* root node has no end tag either */
#endif
  ENC_LEN_DEBUG(x, "gl:prio", p-enc_base);
  return p;
}

/* FUNC(zx_ENC_WO_gl_prio) */

/* Render element into string. The XML attributes and elements are
 * processed in wire order by chasing wo pointers. This is what you want for
 * validating signatures on other people's XML documents. */

/* Called by: */
char* zx_ENC_WO_gl_prio(struct zx_ctx* c, struct zx_gl_prio_s* x, char* p )
{
  struct zx_elem_s* kid;
  struct zx_ns_s* pop_seen = 0;
  ENC_LEN_DEBUG_BASE;
#if 1 /* NORMALMODE */
  char* q;
  char* qq;
  ZX_OUT_CH(p, '<');
  q = p;
  if (x->gg.g.ns && x->gg.g.ns->prefix_len) {
    ZX_OUT_MEM(p, x->gg.g.ns->prefix, x->gg.g.ns->prefix_len);
    ZX_OUT_CH(p, ':');
  }
  ZX_OUT_MEM(p, "prio", sizeof("prio")-1);
  qq = p;

  /* *** sort the namespaces */
  if (c->inc_ns)
    zx_add_inc_ns(c, &pop_seen);
  zx_add_xmlns_if_not_seen(c, x->gg.g.ns, &pop_seen);

  p = zx_enc_seen(p, pop_seen); 
  p = zx_attr_wo_enc(p, x->type, "type=\"", sizeof("type=\"")-1);

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
  ENC_LEN_DEBUG(x, "gl:prio", p-enc_base);
  return p;
}

/* FUNC(zx_EASY_ENC_SO_gl_prio) */

/* Called by: */
struct zx_str* zx_EASY_ENC_SO_gl_prio(struct zx_ctx* c, struct zx_gl_prio_s* x )
{
  int len;
  char* buf;
  c->ns_tab = ZX_ALLOC(c, sizeof(zx_ns_tab));
  memcpy(c->ns_tab, zx_ns_tab, sizeof(zx_ns_tab));
  len = zx_LEN_SO_gl_prio(c, x );
  buf = ZX_ALLOC(c, len+1);
  return zx_easy_enc_common(c, zx_ENC_SO_gl_prio(c, x, buf ), buf, len);
}

/* FUNC(zx_EASY_ENC_WO_gl_prio) */

/* Called by: */
struct zx_str* zx_EASY_ENC_WO_gl_prio(struct zx_ctx* c, struct zx_gl_prio_s* x )
{
  int len;
  char* buf;
  c->ns_tab = ZX_ALLOC(c, sizeof(zx_ns_tab));
  memcpy(c->ns_tab, zx_ns_tab, sizeof(zx_ns_tab));
  len = zx_LEN_WO_gl_prio(c, x );
  buf = ZX_ALLOC(c, len+1);
  return zx_easy_enc_common(c, zx_ENC_WO_gl_prio(c, x, buf ), buf, len);
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

#define EL_NAME   gl_resp_req
#define EL_STRUCT zx_gl_resp_req_s
#define EL_NS     gl
#define EL_TAG    resp_req

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

/* FUNC(zx_LEN_SO_gl_resp_req) */

/* Compute length of an element (and its subelements). The XML attributes
 * and elements are processed in schema order. */

/* Called by: */
int zx_LEN_SO_gl_resp_req(struct zx_ctx* c, struct zx_gl_resp_req_s* x )
{
  struct zx_ns_s* pop_seen = 0;
  struct zx_elem_s* se MAYBE_UNUSED;
#if 1 /* NORMALMODE */
  /* *** in simple_elem case should output ns prefix from ns node. */
  int len = sizeof("<gl:resp_req")-1 + 1 + sizeof("</gl:resp_req>")-1;
  if (c->inc_ns_len)
    len += zx_len_inc_ns(c, &pop_seen);
  len += zx_len_xmlns_if_not_seen(c, zx_ns_tab+zx_xmlns_ix_gl, &pop_seen);

  len += zx_attr_so_len(x->type, sizeof("type")-1);

#else
  /* root node has no begin tag */
  int len = 0;
#endif
  


  len += zx_len_so_common(c, &x->gg);
  zx_pop_seen(pop_seen);
  ENC_LEN_DEBUG(x, "gl:resp_req", len);
  return len;
}

/* FUNC(zx_LEN_WO_gl_resp_req) */

/* Compute length of an element (and its subelements). The XML attributes
 * and elements are processed in wire order and no assumptions
 * are made about namespace prefixes. */

/* Called by: */
int zx_LEN_WO_gl_resp_req(struct zx_ctx* c, struct zx_gl_resp_req_s* x )
{
  struct zx_ns_s* pop_seen = 0;
  struct zx_elem_s* se MAYBE_UNUSED;
#if 1 /* NORMALMODE */
  int len = 1 + sizeof("resp_req")-1 + 1 + 2 + sizeof("resp_req")-1 + 1;
  
  if (x->gg.g.ns && x->gg.g.ns->prefix_len)
    len += (x->gg.g.ns->prefix_len + 1) * 2;
  if (c->inc_ns_len)
    len += zx_len_inc_ns(c, &pop_seen);
  len += zx_len_xmlns_if_not_seen(c, x->gg.g.ns, &pop_seen);

  len += zx_attr_wo_len(x->type, sizeof("type")-1);

#else
  /* root node has no begin tag */
  int len = 0;
#endif
  


  len += zx_len_wo_common(c, &x->gg); 
  zx_pop_seen(pop_seen);
  ENC_LEN_DEBUG(x, "gl:resp_req", len);
  return len;
}

/* FUNC(zx_ENC_SO_gl_resp_req) */

/* Render element into string. The XML attributes and elements are
 * processed in schema order. This is what you generally want for
 * rendering new data structure to a string. The wo pointers are not used. */

/* Called by: */
char* zx_ENC_SO_gl_resp_req(struct zx_ctx* c, struct zx_gl_resp_req_s* x, char* p )
{
  struct zx_elem_s* se MAYBE_UNUSED;
  struct zx_ns_s* pop_seen = 0;
  ENC_LEN_DEBUG_BASE;
#if 1 /* NORMALMODE */
  /* *** in simple_elem case should output ns prefix from ns node. */
  ZX_OUT_TAG(p, "<gl:resp_req");
  if (c->inc_ns)
    p = zx_enc_inc_ns(c, p, &pop_seen);
  p = zx_enc_xmlns_if_not_seen(c, p, zx_ns_tab+zx_xmlns_ix_gl, &pop_seen);

  p = zx_attr_so_enc(p, x->type, " type=\"", sizeof(" type=\"")-1);

  p = zx_enc_unknown_attrs(p, x->gg.any_attr);
#else
  /* root node has no begin tag */
#endif
  

  p = zx_enc_so_unknown_elems_and_content(c, p, &x->gg);
  
#if 1 /* NORMALMODE */
  ZX_OUT_CLOSE_TAG(p, "</gl:resp_req>");
  zx_pop_seen(pop_seen);
#else
  /* root node has no end tag either */
#endif
  ENC_LEN_DEBUG(x, "gl:resp_req", p-enc_base);
  return p;
}

/* FUNC(zx_ENC_WO_gl_resp_req) */

/* Render element into string. The XML attributes and elements are
 * processed in wire order by chasing wo pointers. This is what you want for
 * validating signatures on other people's XML documents. */

/* Called by: */
char* zx_ENC_WO_gl_resp_req(struct zx_ctx* c, struct zx_gl_resp_req_s* x, char* p )
{
  struct zx_elem_s* kid;
  struct zx_ns_s* pop_seen = 0;
  ENC_LEN_DEBUG_BASE;
#if 1 /* NORMALMODE */
  char* q;
  char* qq;
  ZX_OUT_CH(p, '<');
  q = p;
  if (x->gg.g.ns && x->gg.g.ns->prefix_len) {
    ZX_OUT_MEM(p, x->gg.g.ns->prefix, x->gg.g.ns->prefix_len);
    ZX_OUT_CH(p, ':');
  }
  ZX_OUT_MEM(p, "resp_req", sizeof("resp_req")-1);
  qq = p;

  /* *** sort the namespaces */
  if (c->inc_ns)
    zx_add_inc_ns(c, &pop_seen);
  zx_add_xmlns_if_not_seen(c, x->gg.g.ns, &pop_seen);

  p = zx_enc_seen(p, pop_seen); 
  p = zx_attr_wo_enc(p, x->type, "type=\"", sizeof("type=\"")-1);

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
  ENC_LEN_DEBUG(x, "gl:resp_req", p-enc_base);
  return p;
}

/* FUNC(zx_EASY_ENC_SO_gl_resp_req) */

/* Called by: */
struct zx_str* zx_EASY_ENC_SO_gl_resp_req(struct zx_ctx* c, struct zx_gl_resp_req_s* x )
{
  int len;
  char* buf;
  c->ns_tab = ZX_ALLOC(c, sizeof(zx_ns_tab));
  memcpy(c->ns_tab, zx_ns_tab, sizeof(zx_ns_tab));
  len = zx_LEN_SO_gl_resp_req(c, x );
  buf = ZX_ALLOC(c, len+1);
  return zx_easy_enc_common(c, zx_ENC_SO_gl_resp_req(c, x, buf ), buf, len);
}

/* FUNC(zx_EASY_ENC_WO_gl_resp_req) */

/* Called by: */
struct zx_str* zx_EASY_ENC_WO_gl_resp_req(struct zx_ctx* c, struct zx_gl_resp_req_s* x )
{
  int len;
  char* buf;
  c->ns_tab = ZX_ALLOC(c, sizeof(zx_ns_tab));
  memcpy(c->ns_tab, zx_ns_tab, sizeof(zx_ns_tab));
  len = zx_LEN_WO_gl_resp_req(c, x );
  buf = ZX_ALLOC(c, len+1);
  return zx_easy_enc_common(c, zx_ENC_WO_gl_resp_req(c, x, buf ), buf, len);
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

#define EL_NAME   gl_shape
#define EL_STRUCT zx_gl_shape_s
#define EL_NS     gl
#define EL_TAG    shape

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

/* FUNC(zx_LEN_SO_gl_shape) */

/* Compute length of an element (and its subelements). The XML attributes
 * and elements are processed in schema order. */

/* Called by: */
int zx_LEN_SO_gl_shape(struct zx_ctx* c, struct zx_gl_shape_s* x )
{
  struct zx_ns_s* pop_seen = 0;
  struct zx_elem_s* se MAYBE_UNUSED;
#if 1 /* NORMALMODE */
  /* *** in simple_elem case should output ns prefix from ns node. */
  int len = sizeof("<gl:shape")-1 + 1 + sizeof("</gl:shape>")-1;
  if (c->inc_ns_len)
    len += zx_len_inc_ns(c, &pop_seen);
  len += zx_len_xmlns_if_not_seen(c, zx_ns_tab+zx_xmlns_ix_gl, &pop_seen);


#else
  /* root node has no begin tag */
  int len = 0;
#endif
  
  {
      struct zx_gl_Point_s* e;
      for (e = x->Point; e; e = (struct zx_gl_Point_s*)e->gg.g.n)
	  len += zx_LEN_SO_gl_Point(c, e);
  }
  {
      struct zx_gl_LineString_s* e;
      for (e = x->LineString; e; e = (struct zx_gl_LineString_s*)e->gg.g.n)
	  len += zx_LEN_SO_gl_LineString(c, e);
  }
  {
      struct zx_gl_Polygon_s* e;
      for (e = x->Polygon; e; e = (struct zx_gl_Polygon_s*)e->gg.g.n)
	  len += zx_LEN_SO_gl_Polygon(c, e);
  }
  {
      struct zx_gl_Box_s* e;
      for (e = x->Box; e; e = (struct zx_gl_Box_s*)e->gg.g.n)
	  len += zx_LEN_SO_gl_Box(c, e);
  }
  {
      struct zx_gl_CircularArea_s* e;
      for (e = x->CircularArea; e; e = (struct zx_gl_CircularArea_s*)e->gg.g.n)
	  len += zx_LEN_SO_gl_CircularArea(c, e);
  }
  {
      struct zx_gl_CircularArcArea_s* e;
      for (e = x->CircularArcArea; e; e = (struct zx_gl_CircularArcArea_s*)e->gg.g.n)
	  len += zx_LEN_SO_gl_CircularArcArea(c, e);
  }
  {
      struct zx_gl_EllipticalArea_s* e;
      for (e = x->EllipticalArea; e; e = (struct zx_gl_EllipticalArea_s*)e->gg.g.n)
	  len += zx_LEN_SO_gl_EllipticalArea(c, e);
  }
  {
      struct zx_gl_GeometryCollection_s* e;
      for (e = x->GeometryCollection; e; e = (struct zx_gl_GeometryCollection_s*)e->gg.g.n)
	  len += zx_LEN_SO_gl_GeometryCollection(c, e);
  }
  {
      struct zx_gl_MultiLineString_s* e;
      for (e = x->MultiLineString; e; e = (struct zx_gl_MultiLineString_s*)e->gg.g.n)
	  len += zx_LEN_SO_gl_MultiLineString(c, e);
  }
  {
      struct zx_gl_MultiPoint_s* e;
      for (e = x->MultiPoint; e; e = (struct zx_gl_MultiPoint_s*)e->gg.g.n)
	  len += zx_LEN_SO_gl_MultiPoint(c, e);
  }
  {
      struct zx_gl_MultiPolygon_s* e;
      for (e = x->MultiPolygon; e; e = (struct zx_gl_MultiPolygon_s*)e->gg.g.n)
	  len += zx_LEN_SO_gl_MultiPolygon(c, e);
  }
  {
      struct zx_gl_Extension_s* e;
      for (e = x->Extension; e; e = (struct zx_gl_Extension_s*)e->gg.g.n)
	  len += zx_LEN_SO_gl_Extension(c, e);
  }


  len += zx_len_so_common(c, &x->gg);
  zx_pop_seen(pop_seen);
  ENC_LEN_DEBUG(x, "gl:shape", len);
  return len;
}

/* FUNC(zx_LEN_WO_gl_shape) */

/* Compute length of an element (and its subelements). The XML attributes
 * and elements are processed in wire order and no assumptions
 * are made about namespace prefixes. */

/* Called by: */
int zx_LEN_WO_gl_shape(struct zx_ctx* c, struct zx_gl_shape_s* x )
{
  struct zx_ns_s* pop_seen = 0;
  struct zx_elem_s* se MAYBE_UNUSED;
#if 1 /* NORMALMODE */
  int len = 1 + sizeof("shape")-1 + 1 + 2 + sizeof("shape")-1 + 1;
  
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
      struct zx_gl_Point_s* e;
      for (e = x->Point; e; e = (struct zx_gl_Point_s*)e->gg.g.n)
	  len += zx_LEN_WO_gl_Point(c, e);
  }
  {
      struct zx_gl_LineString_s* e;
      for (e = x->LineString; e; e = (struct zx_gl_LineString_s*)e->gg.g.n)
	  len += zx_LEN_WO_gl_LineString(c, e);
  }
  {
      struct zx_gl_Polygon_s* e;
      for (e = x->Polygon; e; e = (struct zx_gl_Polygon_s*)e->gg.g.n)
	  len += zx_LEN_WO_gl_Polygon(c, e);
  }
  {
      struct zx_gl_Box_s* e;
      for (e = x->Box; e; e = (struct zx_gl_Box_s*)e->gg.g.n)
	  len += zx_LEN_WO_gl_Box(c, e);
  }
  {
      struct zx_gl_CircularArea_s* e;
      for (e = x->CircularArea; e; e = (struct zx_gl_CircularArea_s*)e->gg.g.n)
	  len += zx_LEN_WO_gl_CircularArea(c, e);
  }
  {
      struct zx_gl_CircularArcArea_s* e;
      for (e = x->CircularArcArea; e; e = (struct zx_gl_CircularArcArea_s*)e->gg.g.n)
	  len += zx_LEN_WO_gl_CircularArcArea(c, e);
  }
  {
      struct zx_gl_EllipticalArea_s* e;
      for (e = x->EllipticalArea; e; e = (struct zx_gl_EllipticalArea_s*)e->gg.g.n)
	  len += zx_LEN_WO_gl_EllipticalArea(c, e);
  }
  {
      struct zx_gl_GeometryCollection_s* e;
      for (e = x->GeometryCollection; e; e = (struct zx_gl_GeometryCollection_s*)e->gg.g.n)
	  len += zx_LEN_WO_gl_GeometryCollection(c, e);
  }
  {
      struct zx_gl_MultiLineString_s* e;
      for (e = x->MultiLineString; e; e = (struct zx_gl_MultiLineString_s*)e->gg.g.n)
	  len += zx_LEN_WO_gl_MultiLineString(c, e);
  }
  {
      struct zx_gl_MultiPoint_s* e;
      for (e = x->MultiPoint; e; e = (struct zx_gl_MultiPoint_s*)e->gg.g.n)
	  len += zx_LEN_WO_gl_MultiPoint(c, e);
  }
  {
      struct zx_gl_MultiPolygon_s* e;
      for (e = x->MultiPolygon; e; e = (struct zx_gl_MultiPolygon_s*)e->gg.g.n)
	  len += zx_LEN_WO_gl_MultiPolygon(c, e);
  }
  {
      struct zx_gl_Extension_s* e;
      for (e = x->Extension; e; e = (struct zx_gl_Extension_s*)e->gg.g.n)
	  len += zx_LEN_WO_gl_Extension(c, e);
  }


  len += zx_len_wo_common(c, &x->gg); 
  zx_pop_seen(pop_seen);
  ENC_LEN_DEBUG(x, "gl:shape", len);
  return len;
}

/* FUNC(zx_ENC_SO_gl_shape) */

/* Render element into string. The XML attributes and elements are
 * processed in schema order. This is what you generally want for
 * rendering new data structure to a string. The wo pointers are not used. */

/* Called by: */
char* zx_ENC_SO_gl_shape(struct zx_ctx* c, struct zx_gl_shape_s* x, char* p )
{
  struct zx_elem_s* se MAYBE_UNUSED;
  struct zx_ns_s* pop_seen = 0;
  ENC_LEN_DEBUG_BASE;
#if 1 /* NORMALMODE */
  /* *** in simple_elem case should output ns prefix from ns node. */
  ZX_OUT_TAG(p, "<gl:shape");
  if (c->inc_ns)
    p = zx_enc_inc_ns(c, p, &pop_seen);
  p = zx_enc_xmlns_if_not_seen(c, p, zx_ns_tab+zx_xmlns_ix_gl, &pop_seen);


  p = zx_enc_unknown_attrs(p, x->gg.any_attr);
#else
  /* root node has no begin tag */
#endif
  
  {
      struct zx_gl_Point_s* e;
      for (e = x->Point; e; e = (struct zx_gl_Point_s*)e->gg.g.n)
	  p = zx_ENC_SO_gl_Point(c, e, p);
  }
  {
      struct zx_gl_LineString_s* e;
      for (e = x->LineString; e; e = (struct zx_gl_LineString_s*)e->gg.g.n)
	  p = zx_ENC_SO_gl_LineString(c, e, p);
  }
  {
      struct zx_gl_Polygon_s* e;
      for (e = x->Polygon; e; e = (struct zx_gl_Polygon_s*)e->gg.g.n)
	  p = zx_ENC_SO_gl_Polygon(c, e, p);
  }
  {
      struct zx_gl_Box_s* e;
      for (e = x->Box; e; e = (struct zx_gl_Box_s*)e->gg.g.n)
	  p = zx_ENC_SO_gl_Box(c, e, p);
  }
  {
      struct zx_gl_CircularArea_s* e;
      for (e = x->CircularArea; e; e = (struct zx_gl_CircularArea_s*)e->gg.g.n)
	  p = zx_ENC_SO_gl_CircularArea(c, e, p);
  }
  {
      struct zx_gl_CircularArcArea_s* e;
      for (e = x->CircularArcArea; e; e = (struct zx_gl_CircularArcArea_s*)e->gg.g.n)
	  p = zx_ENC_SO_gl_CircularArcArea(c, e, p);
  }
  {
      struct zx_gl_EllipticalArea_s* e;
      for (e = x->EllipticalArea; e; e = (struct zx_gl_EllipticalArea_s*)e->gg.g.n)
	  p = zx_ENC_SO_gl_EllipticalArea(c, e, p);
  }
  {
      struct zx_gl_GeometryCollection_s* e;
      for (e = x->GeometryCollection; e; e = (struct zx_gl_GeometryCollection_s*)e->gg.g.n)
	  p = zx_ENC_SO_gl_GeometryCollection(c, e, p);
  }
  {
      struct zx_gl_MultiLineString_s* e;
      for (e = x->MultiLineString; e; e = (struct zx_gl_MultiLineString_s*)e->gg.g.n)
	  p = zx_ENC_SO_gl_MultiLineString(c, e, p);
  }
  {
      struct zx_gl_MultiPoint_s* e;
      for (e = x->MultiPoint; e; e = (struct zx_gl_MultiPoint_s*)e->gg.g.n)
	  p = zx_ENC_SO_gl_MultiPoint(c, e, p);
  }
  {
      struct zx_gl_MultiPolygon_s* e;
      for (e = x->MultiPolygon; e; e = (struct zx_gl_MultiPolygon_s*)e->gg.g.n)
	  p = zx_ENC_SO_gl_MultiPolygon(c, e, p);
  }
  {
      struct zx_gl_Extension_s* e;
      for (e = x->Extension; e; e = (struct zx_gl_Extension_s*)e->gg.g.n)
	  p = zx_ENC_SO_gl_Extension(c, e, p);
  }

  p = zx_enc_so_unknown_elems_and_content(c, p, &x->gg);
  
#if 1 /* NORMALMODE */
  ZX_OUT_CLOSE_TAG(p, "</gl:shape>");
  zx_pop_seen(pop_seen);
#else
  /* root node has no end tag either */
#endif
  ENC_LEN_DEBUG(x, "gl:shape", p-enc_base);
  return p;
}

/* FUNC(zx_ENC_WO_gl_shape) */

/* Render element into string. The XML attributes and elements are
 * processed in wire order by chasing wo pointers. This is what you want for
 * validating signatures on other people's XML documents. */

/* Called by: */
char* zx_ENC_WO_gl_shape(struct zx_ctx* c, struct zx_gl_shape_s* x, char* p )
{
  struct zx_elem_s* kid;
  struct zx_ns_s* pop_seen = 0;
  ENC_LEN_DEBUG_BASE;
#if 1 /* NORMALMODE */
  char* q;
  char* qq;
  ZX_OUT_CH(p, '<');
  q = p;
  if (x->gg.g.ns && x->gg.g.ns->prefix_len) {
    ZX_OUT_MEM(p, x->gg.g.ns->prefix, x->gg.g.ns->prefix_len);
    ZX_OUT_CH(p, ':');
  }
  ZX_OUT_MEM(p, "shape", sizeof("shape")-1);
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
  ENC_LEN_DEBUG(x, "gl:shape", p-enc_base);
  return p;
}

/* FUNC(zx_EASY_ENC_SO_gl_shape) */

/* Called by: */
struct zx_str* zx_EASY_ENC_SO_gl_shape(struct zx_ctx* c, struct zx_gl_shape_s* x )
{
  int len;
  char* buf;
  c->ns_tab = ZX_ALLOC(c, sizeof(zx_ns_tab));
  memcpy(c->ns_tab, zx_ns_tab, sizeof(zx_ns_tab));
  len = zx_LEN_SO_gl_shape(c, x );
  buf = ZX_ALLOC(c, len+1);
  return zx_easy_enc_common(c, zx_ENC_SO_gl_shape(c, x, buf ), buf, len);
}

/* FUNC(zx_EASY_ENC_WO_gl_shape) */

/* Called by: */
struct zx_str* zx_EASY_ENC_WO_gl_shape(struct zx_ctx* c, struct zx_gl_shape_s* x )
{
  int len;
  char* buf;
  c->ns_tab = ZX_ALLOC(c, sizeof(zx_ns_tab));
  memcpy(c->ns_tab, zx_ns_tab, sizeof(zx_ns_tab));
  len = zx_LEN_WO_gl_shape(c, x );
  buf = ZX_ALLOC(c, len+1);
  return zx_easy_enc_common(c, zx_ENC_WO_gl_shape(c, x, buf ), buf, len);
}




/* EOF -- c/zx-gl-enc.c */
