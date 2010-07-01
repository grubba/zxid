/* c/zx-cdm-enc.c - WARNING: This file was automatically generated. DO NOT EDIT!
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
#include "c/zx-cdm-data.h"
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

#define EL_NAME   cdm_ADR
#define EL_STRUCT zx_cdm_ADR_s
#define EL_NS     cdm
#define EL_TAG    ADR

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

/* FUNC(zx_LEN_SO_cdm_ADR) */

/* Compute length of an element (and its subelements). The XML attributes
 * and elements are processed in schema order. */

/* Called by: */
int zx_LEN_SO_cdm_ADR(struct zx_ctx* c, struct zx_cdm_ADR_s* x )
{
  struct zx_ns_s* pop_seen = 0;
  struct zx_elem_s* se MAYBE_UNUSED;
#if 1 /* NORMALMODE */
  /* *** in simple_elem case should output ns prefix from ns node. */
  int len = sizeof("<cdm:ADR")-1 + 1 + sizeof("</cdm:ADR>")-1;
  if (c->inc_ns_len)
    len += zx_len_inc_ns(c, &pop_seen);
  if (x->id || x->modificationTime)
    len += zx_len_xmlns_if_not_seen(c, zx_ns_tab+zx_xmlns_ix_cb, &pop_seen);
  len += zx_len_xmlns_if_not_seen(c, zx_ns_tab+zx_xmlns_ix_cdm, &pop_seen);

  len += zx_attr_so_len(x->id, sizeof("cb:id")-1);
  len += zx_attr_so_len(x->modificationTime, sizeof("cb:modificationTime")-1);

#else
  /* root node has no begin tag */
  int len = 0;
#endif
  
  for (se = x->HOME; se; se = (struct zx_elem_s*)se->g.n)
    len += zx_LEN_SO_simple_elem(c,se, sizeof("cdm:HOME")-1, zx_ns_tab+zx_xmlns_ix_cdm);
  for (se = x->WORK; se; se = (struct zx_elem_s*)se->g.n)
    len += zx_LEN_SO_simple_elem(c,se, sizeof("cdm:WORK")-1, zx_ns_tab+zx_xmlns_ix_cdm);
  for (se = x->POSTAL; se; se = (struct zx_elem_s*)se->g.n)
    len += zx_LEN_SO_simple_elem(c,se, sizeof("cdm:POSTAL")-1, zx_ns_tab+zx_xmlns_ix_cdm);
  for (se = x->PARCEL; se; se = (struct zx_elem_s*)se->g.n)
    len += zx_LEN_SO_simple_elem(c,se, sizeof("cdm:PARCEL")-1, zx_ns_tab+zx_xmlns_ix_cdm);
  for (se = x->DOM; se; se = (struct zx_elem_s*)se->g.n)
    len += zx_LEN_SO_simple_elem(c,se, sizeof("cdm:DOM")-1, zx_ns_tab+zx_xmlns_ix_cdm);
  for (se = x->INTL; se; se = (struct zx_elem_s*)se->g.n)
    len += zx_LEN_SO_simple_elem(c,se, sizeof("cdm:INTL")-1, zx_ns_tab+zx_xmlns_ix_cdm);
  for (se = x->PREF; se; se = (struct zx_elem_s*)se->g.n)
    len += zx_LEN_SO_simple_elem(c,se, sizeof("cdm:PREF")-1, zx_ns_tab+zx_xmlns_ix_cdm);
  {
      struct zx_cdm_POBOX_s* e;
      for (e = x->POBOX; e; e = (struct zx_cdm_POBOX_s*)e->gg.g.n)
	  len += zx_LEN_SO_cdm_POBOX(c, e);
  }
  {
      struct zx_cdm_EXTADR_s* e;
      for (e = x->EXTADR; e; e = (struct zx_cdm_EXTADR_s*)e->gg.g.n)
	  len += zx_LEN_SO_cdm_EXTADR(c, e);
  }
  {
      struct zx_cdm_STREET_s* e;
      for (e = x->STREET; e; e = (struct zx_cdm_STREET_s*)e->gg.g.n)
	  len += zx_LEN_SO_cdm_STREET(c, e);
  }
  {
      struct zx_cdm_LOCALITY_s* e;
      for (e = x->LOCALITY; e; e = (struct zx_cdm_LOCALITY_s*)e->gg.g.n)
	  len += zx_LEN_SO_cdm_LOCALITY(c, e);
  }
  {
      struct zx_cdm_REGION_s* e;
      for (e = x->REGION; e; e = (struct zx_cdm_REGION_s*)e->gg.g.n)
	  len += zx_LEN_SO_cdm_REGION(c, e);
  }
  {
      struct zx_cdm_PCODE_s* e;
      for (e = x->PCODE; e; e = (struct zx_cdm_PCODE_s*)e->gg.g.n)
	  len += zx_LEN_SO_cdm_PCODE(c, e);
  }
  {
      struct zx_cdm_CTRY_s* e;
      for (e = x->CTRY; e; e = (struct zx_cdm_CTRY_s*)e->gg.g.n)
	  len += zx_LEN_SO_cdm_CTRY(c, e);
  }


  len += zx_len_so_common(c, &x->gg);
  zx_pop_seen(pop_seen);
  ENC_LEN_DEBUG(x, "cdm:ADR", len);
  return len;
}

/* FUNC(zx_LEN_WO_cdm_ADR) */

/* Compute length of an element (and its subelements). The XML attributes
 * and elements are processed in wire order and no assumptions
 * are made about namespace prefixes. */

/* Called by: */
int zx_LEN_WO_cdm_ADR(struct zx_ctx* c, struct zx_cdm_ADR_s* x )
{
  struct zx_ns_s* pop_seen = 0;
  struct zx_elem_s* se MAYBE_UNUSED;
#if 1 /* NORMALMODE */
  int len = 1 + sizeof("ADR")-1 + 1 + 2 + sizeof("ADR")-1 + 1;
  
  if (x->gg.g.ns && x->gg.g.ns->prefix_len)
    len += (x->gg.g.ns->prefix_len + 1) * 2;
  if (c->inc_ns_len)
    len += zx_len_inc_ns(c, &pop_seen);
  if (x->id)
    len += zx_len_xmlns_if_not_seen(c, x->id->g.ns, &pop_seen);
  if (x->modificationTime)
    len += zx_len_xmlns_if_not_seen(c, x->modificationTime->g.ns, &pop_seen);
  len += zx_len_xmlns_if_not_seen(c, x->gg.g.ns, &pop_seen);

  len += zx_attr_wo_len(x->id, sizeof("id")-1);
  len += zx_attr_wo_len(x->modificationTime, sizeof("modificationTime")-1);

#else
  /* root node has no begin tag */
  int len = 0;
#endif
  
  for (se = x->HOME; se; se = (struct zx_elem_s*)se->g.n)
    len += zx_LEN_WO_simple_elem(c, se, sizeof("HOME")-1);
  for (se = x->WORK; se; se = (struct zx_elem_s*)se->g.n)
    len += zx_LEN_WO_simple_elem(c, se, sizeof("WORK")-1);
  for (se = x->POSTAL; se; se = (struct zx_elem_s*)se->g.n)
    len += zx_LEN_WO_simple_elem(c, se, sizeof("POSTAL")-1);
  for (se = x->PARCEL; se; se = (struct zx_elem_s*)se->g.n)
    len += zx_LEN_WO_simple_elem(c, se, sizeof("PARCEL")-1);
  for (se = x->DOM; se; se = (struct zx_elem_s*)se->g.n)
    len += zx_LEN_WO_simple_elem(c, se, sizeof("DOM")-1);
  for (se = x->INTL; se; se = (struct zx_elem_s*)se->g.n)
    len += zx_LEN_WO_simple_elem(c, se, sizeof("INTL")-1);
  for (se = x->PREF; se; se = (struct zx_elem_s*)se->g.n)
    len += zx_LEN_WO_simple_elem(c, se, sizeof("PREF")-1);
  {
      struct zx_cdm_POBOX_s* e;
      for (e = x->POBOX; e; e = (struct zx_cdm_POBOX_s*)e->gg.g.n)
	  len += zx_LEN_WO_cdm_POBOX(c, e);
  }
  {
      struct zx_cdm_EXTADR_s* e;
      for (e = x->EXTADR; e; e = (struct zx_cdm_EXTADR_s*)e->gg.g.n)
	  len += zx_LEN_WO_cdm_EXTADR(c, e);
  }
  {
      struct zx_cdm_STREET_s* e;
      for (e = x->STREET; e; e = (struct zx_cdm_STREET_s*)e->gg.g.n)
	  len += zx_LEN_WO_cdm_STREET(c, e);
  }
  {
      struct zx_cdm_LOCALITY_s* e;
      for (e = x->LOCALITY; e; e = (struct zx_cdm_LOCALITY_s*)e->gg.g.n)
	  len += zx_LEN_WO_cdm_LOCALITY(c, e);
  }
  {
      struct zx_cdm_REGION_s* e;
      for (e = x->REGION; e; e = (struct zx_cdm_REGION_s*)e->gg.g.n)
	  len += zx_LEN_WO_cdm_REGION(c, e);
  }
  {
      struct zx_cdm_PCODE_s* e;
      for (e = x->PCODE; e; e = (struct zx_cdm_PCODE_s*)e->gg.g.n)
	  len += zx_LEN_WO_cdm_PCODE(c, e);
  }
  {
      struct zx_cdm_CTRY_s* e;
      for (e = x->CTRY; e; e = (struct zx_cdm_CTRY_s*)e->gg.g.n)
	  len += zx_LEN_WO_cdm_CTRY(c, e);
  }


  len += zx_len_wo_common(c, &x->gg); 
  zx_pop_seen(pop_seen);
  ENC_LEN_DEBUG(x, "cdm:ADR", len);
  return len;
}

/* FUNC(zx_ENC_SO_cdm_ADR) */

/* Render element into string. The XML attributes and elements are
 * processed in schema order. This is what you generally want for
 * rendering new data structure to a string. The wo pointers are not used. */

/* Called by: */
char* zx_ENC_SO_cdm_ADR(struct zx_ctx* c, struct zx_cdm_ADR_s* x, char* p )
{
  struct zx_elem_s* se MAYBE_UNUSED;
  struct zx_ns_s* pop_seen = 0;
  ENC_LEN_DEBUG_BASE;
#if 1 /* NORMALMODE */
  /* *** in simple_elem case should output ns prefix from ns node. */
  ZX_OUT_TAG(p, "<cdm:ADR");
  if (c->inc_ns)
    p = zx_enc_inc_ns(c, p, &pop_seen);
  if (x->id || x->modificationTime)
    p = zx_enc_xmlns_if_not_seen(c, p, zx_ns_tab+zx_xmlns_ix_cb, &pop_seen);
  p = zx_enc_xmlns_if_not_seen(c, p, zx_ns_tab+zx_xmlns_ix_cdm, &pop_seen);

  p = zx_attr_so_enc(p, x->id, " cb:id=\"", sizeof(" cb:id=\"")-1);
  p = zx_attr_so_enc(p, x->modificationTime, " cb:modificationTime=\"", sizeof(" cb:modificationTime=\"")-1);

  p = zx_enc_unknown_attrs(p, x->gg.any_attr);
#else
  /* root node has no begin tag */
#endif
  
  for (se = x->HOME; se; se = (struct zx_elem_s*)se->g.n)
    p = zx_ENC_SO_simple_elem(c, se, p, "cdm:HOME", sizeof("cdm:HOME")-1, zx_ns_tab+zx_xmlns_ix_cdm);
  for (se = x->WORK; se; se = (struct zx_elem_s*)se->g.n)
    p = zx_ENC_SO_simple_elem(c, se, p, "cdm:WORK", sizeof("cdm:WORK")-1, zx_ns_tab+zx_xmlns_ix_cdm);
  for (se = x->POSTAL; se; se = (struct zx_elem_s*)se->g.n)
    p = zx_ENC_SO_simple_elem(c, se, p, "cdm:POSTAL", sizeof("cdm:POSTAL")-1, zx_ns_tab+zx_xmlns_ix_cdm);
  for (se = x->PARCEL; se; se = (struct zx_elem_s*)se->g.n)
    p = zx_ENC_SO_simple_elem(c, se, p, "cdm:PARCEL", sizeof("cdm:PARCEL")-1, zx_ns_tab+zx_xmlns_ix_cdm);
  for (se = x->DOM; se; se = (struct zx_elem_s*)se->g.n)
    p = zx_ENC_SO_simple_elem(c, se, p, "cdm:DOM", sizeof("cdm:DOM")-1, zx_ns_tab+zx_xmlns_ix_cdm);
  for (se = x->INTL; se; se = (struct zx_elem_s*)se->g.n)
    p = zx_ENC_SO_simple_elem(c, se, p, "cdm:INTL", sizeof("cdm:INTL")-1, zx_ns_tab+zx_xmlns_ix_cdm);
  for (se = x->PREF; se; se = (struct zx_elem_s*)se->g.n)
    p = zx_ENC_SO_simple_elem(c, se, p, "cdm:PREF", sizeof("cdm:PREF")-1, zx_ns_tab+zx_xmlns_ix_cdm);
  {
      struct zx_cdm_POBOX_s* e;
      for (e = x->POBOX; e; e = (struct zx_cdm_POBOX_s*)e->gg.g.n)
	  p = zx_ENC_SO_cdm_POBOX(c, e, p);
  }
  {
      struct zx_cdm_EXTADR_s* e;
      for (e = x->EXTADR; e; e = (struct zx_cdm_EXTADR_s*)e->gg.g.n)
	  p = zx_ENC_SO_cdm_EXTADR(c, e, p);
  }
  {
      struct zx_cdm_STREET_s* e;
      for (e = x->STREET; e; e = (struct zx_cdm_STREET_s*)e->gg.g.n)
	  p = zx_ENC_SO_cdm_STREET(c, e, p);
  }
  {
      struct zx_cdm_LOCALITY_s* e;
      for (e = x->LOCALITY; e; e = (struct zx_cdm_LOCALITY_s*)e->gg.g.n)
	  p = zx_ENC_SO_cdm_LOCALITY(c, e, p);
  }
  {
      struct zx_cdm_REGION_s* e;
      for (e = x->REGION; e; e = (struct zx_cdm_REGION_s*)e->gg.g.n)
	  p = zx_ENC_SO_cdm_REGION(c, e, p);
  }
  {
      struct zx_cdm_PCODE_s* e;
      for (e = x->PCODE; e; e = (struct zx_cdm_PCODE_s*)e->gg.g.n)
	  p = zx_ENC_SO_cdm_PCODE(c, e, p);
  }
  {
      struct zx_cdm_CTRY_s* e;
      for (e = x->CTRY; e; e = (struct zx_cdm_CTRY_s*)e->gg.g.n)
	  p = zx_ENC_SO_cdm_CTRY(c, e, p);
  }

  p = zx_enc_so_unknown_elems_and_content(c, p, &x->gg);
  
#if 1 /* NORMALMODE */
  ZX_OUT_CLOSE_TAG(p, "</cdm:ADR>");
  zx_pop_seen(pop_seen);
#else
  /* root node has no end tag either */
#endif
  ENC_LEN_DEBUG(x, "cdm:ADR", p-enc_base);
  return p;
}

/* FUNC(zx_ENC_WO_cdm_ADR) */

/* Render element into string. The XML attributes and elements are
 * processed in wire order by chasing wo pointers. This is what you want for
 * validating signatures on other people's XML documents. */

/* Called by: */
char* zx_ENC_WO_cdm_ADR(struct zx_ctx* c, struct zx_cdm_ADR_s* x, char* p )
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
  ZX_OUT_MEM(p, "ADR", sizeof("ADR")-1);
  qq = p;

  /* *** sort the namespaces */
  if (c->inc_ns)
    zx_add_inc_ns(c, &pop_seen);
  if (x->id)
    zx_add_xmlns_if_not_seen(c, x->id->g.ns, &pop_seen);
  if (x->modificationTime)
    zx_add_xmlns_if_not_seen(c, x->modificationTime->g.ns, &pop_seen);
  zx_add_xmlns_if_not_seen(c, x->gg.g.ns, &pop_seen);

  p = zx_enc_seen(p, pop_seen); 
  p = zx_attr_wo_enc(p, x->id, "id=\"", sizeof("id=\"")-1);
  p = zx_attr_wo_enc(p, x->modificationTime, "modificationTime=\"", sizeof("modificationTime=\"")-1);

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
  ENC_LEN_DEBUG(x, "cdm:ADR", p-enc_base);
  return p;
}

/* FUNC(zx_EASY_ENC_SO_cdm_ADR) */

/* Called by: */
struct zx_str* zx_EASY_ENC_SO_cdm_ADR(struct zx_ctx* c, struct zx_cdm_ADR_s* x )
{
  int len;
  char* buf;
  c->ns_tab = ZX_ALLOC(c, sizeof(zx_ns_tab));
  memcpy(c->ns_tab, zx_ns_tab, sizeof(zx_ns_tab));
  len = zx_LEN_SO_cdm_ADR(c, x );
  buf = ZX_ALLOC(c, len+1);
  return zx_easy_enc_common(c, zx_ENC_SO_cdm_ADR(c, x, buf ), buf, len);
}

/* FUNC(zx_EASY_ENC_WO_cdm_ADR) */

/* Called by: */
struct zx_str* zx_EASY_ENC_WO_cdm_ADR(struct zx_ctx* c, struct zx_cdm_ADR_s* x )
{
  int len;
  char* buf;
  c->ns_tab = ZX_ALLOC(c, sizeof(zx_ns_tab));
  memcpy(c->ns_tab, zx_ns_tab, sizeof(zx_ns_tab));
  len = zx_LEN_WO_cdm_ADR(c, x );
  buf = ZX_ALLOC(c, len+1);
  return zx_easy_enc_common(c, zx_ENC_WO_cdm_ADR(c, x, buf ), buf, len);
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

#define EL_NAME   cdm_AGENT
#define EL_STRUCT zx_cdm_AGENT_s
#define EL_NS     cdm
#define EL_TAG    AGENT

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

/* FUNC(zx_LEN_SO_cdm_AGENT) */

/* Compute length of an element (and its subelements). The XML attributes
 * and elements are processed in schema order. */

/* Called by: */
int zx_LEN_SO_cdm_AGENT(struct zx_ctx* c, struct zx_cdm_AGENT_s* x )
{
  struct zx_ns_s* pop_seen = 0;
  struct zx_elem_s* se MAYBE_UNUSED;
#if 1 /* NORMALMODE */
  /* *** in simple_elem case should output ns prefix from ns node. */
  int len = sizeof("<cdm:AGENT")-1 + 1 + sizeof("</cdm:AGENT>")-1;
  if (c->inc_ns_len)
    len += zx_len_inc_ns(c, &pop_seen);
  if (x->id || x->modificationTime)
    len += zx_len_xmlns_if_not_seen(c, zx_ns_tab+zx_xmlns_ix_cb, &pop_seen);
  len += zx_len_xmlns_if_not_seen(c, zx_ns_tab+zx_xmlns_ix_cdm, &pop_seen);

  len += zx_attr_so_len(x->id, sizeof("cb:id")-1);
  len += zx_attr_so_len(x->modificationTime, sizeof("cb:modificationTime")-1);

#else
  /* root node has no begin tag */
  int len = 0;
#endif
  
  {
      struct zx_cdm_vCard_s* e;
      for (e = x->vCard; e; e = (struct zx_cdm_vCard_s*)e->gg.g.n)
	  len += zx_LEN_SO_cdm_vCard(c, e);
  }
  {
      struct zx_cdm_EXTVAL_s* e;
      for (e = x->EXTVAL; e; e = (struct zx_cdm_EXTVAL_s*)e->gg.g.n)
	  len += zx_LEN_SO_cdm_EXTVAL(c, e);
  }


  len += zx_len_so_common(c, &x->gg);
  zx_pop_seen(pop_seen);
  ENC_LEN_DEBUG(x, "cdm:AGENT", len);
  return len;
}

/* FUNC(zx_LEN_WO_cdm_AGENT) */

/* Compute length of an element (and its subelements). The XML attributes
 * and elements are processed in wire order and no assumptions
 * are made about namespace prefixes. */

/* Called by: */
int zx_LEN_WO_cdm_AGENT(struct zx_ctx* c, struct zx_cdm_AGENT_s* x )
{
  struct zx_ns_s* pop_seen = 0;
  struct zx_elem_s* se MAYBE_UNUSED;
#if 1 /* NORMALMODE */
  int len = 1 + sizeof("AGENT")-1 + 1 + 2 + sizeof("AGENT")-1 + 1;
  
  if (x->gg.g.ns && x->gg.g.ns->prefix_len)
    len += (x->gg.g.ns->prefix_len + 1) * 2;
  if (c->inc_ns_len)
    len += zx_len_inc_ns(c, &pop_seen);
  if (x->id)
    len += zx_len_xmlns_if_not_seen(c, x->id->g.ns, &pop_seen);
  if (x->modificationTime)
    len += zx_len_xmlns_if_not_seen(c, x->modificationTime->g.ns, &pop_seen);
  len += zx_len_xmlns_if_not_seen(c, x->gg.g.ns, &pop_seen);

  len += zx_attr_wo_len(x->id, sizeof("id")-1);
  len += zx_attr_wo_len(x->modificationTime, sizeof("modificationTime")-1);

#else
  /* root node has no begin tag */
  int len = 0;
#endif
  
  {
      struct zx_cdm_vCard_s* e;
      for (e = x->vCard; e; e = (struct zx_cdm_vCard_s*)e->gg.g.n)
	  len += zx_LEN_WO_cdm_vCard(c, e);
  }
  {
      struct zx_cdm_EXTVAL_s* e;
      for (e = x->EXTVAL; e; e = (struct zx_cdm_EXTVAL_s*)e->gg.g.n)
	  len += zx_LEN_WO_cdm_EXTVAL(c, e);
  }


  len += zx_len_wo_common(c, &x->gg); 
  zx_pop_seen(pop_seen);
  ENC_LEN_DEBUG(x, "cdm:AGENT", len);
  return len;
}

/* FUNC(zx_ENC_SO_cdm_AGENT) */

/* Render element into string. The XML attributes and elements are
 * processed in schema order. This is what you generally want for
 * rendering new data structure to a string. The wo pointers are not used. */

/* Called by: */
char* zx_ENC_SO_cdm_AGENT(struct zx_ctx* c, struct zx_cdm_AGENT_s* x, char* p )
{
  struct zx_elem_s* se MAYBE_UNUSED;
  struct zx_ns_s* pop_seen = 0;
  ENC_LEN_DEBUG_BASE;
#if 1 /* NORMALMODE */
  /* *** in simple_elem case should output ns prefix from ns node. */
  ZX_OUT_TAG(p, "<cdm:AGENT");
  if (c->inc_ns)
    p = zx_enc_inc_ns(c, p, &pop_seen);
  if (x->id || x->modificationTime)
    p = zx_enc_xmlns_if_not_seen(c, p, zx_ns_tab+zx_xmlns_ix_cb, &pop_seen);
  p = zx_enc_xmlns_if_not_seen(c, p, zx_ns_tab+zx_xmlns_ix_cdm, &pop_seen);

  p = zx_attr_so_enc(p, x->id, " cb:id=\"", sizeof(" cb:id=\"")-1);
  p = zx_attr_so_enc(p, x->modificationTime, " cb:modificationTime=\"", sizeof(" cb:modificationTime=\"")-1);

  p = zx_enc_unknown_attrs(p, x->gg.any_attr);
#else
  /* root node has no begin tag */
#endif
  
  {
      struct zx_cdm_vCard_s* e;
      for (e = x->vCard; e; e = (struct zx_cdm_vCard_s*)e->gg.g.n)
	  p = zx_ENC_SO_cdm_vCard(c, e, p);
  }
  {
      struct zx_cdm_EXTVAL_s* e;
      for (e = x->EXTVAL; e; e = (struct zx_cdm_EXTVAL_s*)e->gg.g.n)
	  p = zx_ENC_SO_cdm_EXTVAL(c, e, p);
  }

  p = zx_enc_so_unknown_elems_and_content(c, p, &x->gg);
  
#if 1 /* NORMALMODE */
  ZX_OUT_CLOSE_TAG(p, "</cdm:AGENT>");
  zx_pop_seen(pop_seen);
#else
  /* root node has no end tag either */
#endif
  ENC_LEN_DEBUG(x, "cdm:AGENT", p-enc_base);
  return p;
}

/* FUNC(zx_ENC_WO_cdm_AGENT) */

/* Render element into string. The XML attributes and elements are
 * processed in wire order by chasing wo pointers. This is what you want for
 * validating signatures on other people's XML documents. */

/* Called by: */
char* zx_ENC_WO_cdm_AGENT(struct zx_ctx* c, struct zx_cdm_AGENT_s* x, char* p )
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
  ZX_OUT_MEM(p, "AGENT", sizeof("AGENT")-1);
  qq = p;

  /* *** sort the namespaces */
  if (c->inc_ns)
    zx_add_inc_ns(c, &pop_seen);
  if (x->id)
    zx_add_xmlns_if_not_seen(c, x->id->g.ns, &pop_seen);
  if (x->modificationTime)
    zx_add_xmlns_if_not_seen(c, x->modificationTime->g.ns, &pop_seen);
  zx_add_xmlns_if_not_seen(c, x->gg.g.ns, &pop_seen);

  p = zx_enc_seen(p, pop_seen); 
  p = zx_attr_wo_enc(p, x->id, "id=\"", sizeof("id=\"")-1);
  p = zx_attr_wo_enc(p, x->modificationTime, "modificationTime=\"", sizeof("modificationTime=\"")-1);

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
  ENC_LEN_DEBUG(x, "cdm:AGENT", p-enc_base);
  return p;
}

/* FUNC(zx_EASY_ENC_SO_cdm_AGENT) */

/* Called by: */
struct zx_str* zx_EASY_ENC_SO_cdm_AGENT(struct zx_ctx* c, struct zx_cdm_AGENT_s* x )
{
  int len;
  char* buf;
  c->ns_tab = ZX_ALLOC(c, sizeof(zx_ns_tab));
  memcpy(c->ns_tab, zx_ns_tab, sizeof(zx_ns_tab));
  len = zx_LEN_SO_cdm_AGENT(c, x );
  buf = ZX_ALLOC(c, len+1);
  return zx_easy_enc_common(c, zx_ENC_SO_cdm_AGENT(c, x, buf ), buf, len);
}

/* FUNC(zx_EASY_ENC_WO_cdm_AGENT) */

/* Called by: */
struct zx_str* zx_EASY_ENC_WO_cdm_AGENT(struct zx_ctx* c, struct zx_cdm_AGENT_s* x )
{
  int len;
  char* buf;
  c->ns_tab = ZX_ALLOC(c, sizeof(zx_ns_tab));
  memcpy(c->ns_tab, zx_ns_tab, sizeof(zx_ns_tab));
  len = zx_LEN_WO_cdm_AGENT(c, x );
  buf = ZX_ALLOC(c, len+1);
  return zx_easy_enc_common(c, zx_ENC_WO_cdm_AGENT(c, x, buf ), buf, len);
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

#define EL_NAME   cdm_BDAY
#define EL_STRUCT zx_cdm_BDAY_s
#define EL_NS     cdm
#define EL_TAG    BDAY

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

/* FUNC(zx_LEN_SO_cdm_BDAY) */

/* Compute length of an element (and its subelements). The XML attributes
 * and elements are processed in schema order. */

/* Called by: */
int zx_LEN_SO_cdm_BDAY(struct zx_ctx* c, struct zx_cdm_BDAY_s* x )
{
  struct zx_ns_s* pop_seen = 0;
  struct zx_elem_s* se MAYBE_UNUSED;
#if 1 /* NORMALMODE */
  /* *** in simple_elem case should output ns prefix from ns node. */
  int len = sizeof("<cdm:BDAY")-1 + 1 + sizeof("</cdm:BDAY>")-1;
  if (c->inc_ns_len)
    len += zx_len_inc_ns(c, &pop_seen);
  if (x->ACC || x->ACCTime || x->id || x->modificationTime || x->modifier)
    len += zx_len_xmlns_if_not_seen(c, zx_ns_tab+zx_xmlns_ix_cb, &pop_seen);
  len += zx_len_xmlns_if_not_seen(c, zx_ns_tab+zx_xmlns_ix_cdm, &pop_seen);

  len += zx_attr_so_len(x->ACC, sizeof("cb:ACC")-1);
  len += zx_attr_so_len(x->ACCTime, sizeof("cb:ACCTime")-1);
  len += zx_attr_so_len(x->id, sizeof("cb:id")-1);
  len += zx_attr_so_len(x->modificationTime, sizeof("cb:modificationTime")-1);
  len += zx_attr_so_len(x->modifier, sizeof("cb:modifier")-1);

#else
  /* root node has no begin tag */
  int len = 0;
#endif
  


  len += zx_len_so_common(c, &x->gg);
  zx_pop_seen(pop_seen);
  ENC_LEN_DEBUG(x, "cdm:BDAY", len);
  return len;
}

/* FUNC(zx_LEN_WO_cdm_BDAY) */

/* Compute length of an element (and its subelements). The XML attributes
 * and elements are processed in wire order and no assumptions
 * are made about namespace prefixes. */

/* Called by: */
int zx_LEN_WO_cdm_BDAY(struct zx_ctx* c, struct zx_cdm_BDAY_s* x )
{
  struct zx_ns_s* pop_seen = 0;
  struct zx_elem_s* se MAYBE_UNUSED;
#if 1 /* NORMALMODE */
  int len = 1 + sizeof("BDAY")-1 + 1 + 2 + sizeof("BDAY")-1 + 1;
  
  if (x->gg.g.ns && x->gg.g.ns->prefix_len)
    len += (x->gg.g.ns->prefix_len + 1) * 2;
  if (c->inc_ns_len)
    len += zx_len_inc_ns(c, &pop_seen);
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
  len += zx_len_xmlns_if_not_seen(c, x->gg.g.ns, &pop_seen);

  len += zx_attr_wo_len(x->ACC, sizeof("ACC")-1);
  len += zx_attr_wo_len(x->ACCTime, sizeof("ACCTime")-1);
  len += zx_attr_wo_len(x->id, sizeof("id")-1);
  len += zx_attr_wo_len(x->modificationTime, sizeof("modificationTime")-1);
  len += zx_attr_wo_len(x->modifier, sizeof("modifier")-1);

#else
  /* root node has no begin tag */
  int len = 0;
#endif
  


  len += zx_len_wo_common(c, &x->gg); 
  zx_pop_seen(pop_seen);
  ENC_LEN_DEBUG(x, "cdm:BDAY", len);
  return len;
}

/* FUNC(zx_ENC_SO_cdm_BDAY) */

/* Render element into string. The XML attributes and elements are
 * processed in schema order. This is what you generally want for
 * rendering new data structure to a string. The wo pointers are not used. */

/* Called by: */
char* zx_ENC_SO_cdm_BDAY(struct zx_ctx* c, struct zx_cdm_BDAY_s* x, char* p )
{
  struct zx_elem_s* se MAYBE_UNUSED;
  struct zx_ns_s* pop_seen = 0;
  ENC_LEN_DEBUG_BASE;
#if 1 /* NORMALMODE */
  /* *** in simple_elem case should output ns prefix from ns node. */
  ZX_OUT_TAG(p, "<cdm:BDAY");
  if (c->inc_ns)
    p = zx_enc_inc_ns(c, p, &pop_seen);
  if (x->ACC || x->ACCTime || x->id || x->modificationTime || x->modifier)
    p = zx_enc_xmlns_if_not_seen(c, p, zx_ns_tab+zx_xmlns_ix_cb, &pop_seen);
  p = zx_enc_xmlns_if_not_seen(c, p, zx_ns_tab+zx_xmlns_ix_cdm, &pop_seen);

  p = zx_attr_so_enc(p, x->ACC, " cb:ACC=\"", sizeof(" cb:ACC=\"")-1);
  p = zx_attr_so_enc(p, x->ACCTime, " cb:ACCTime=\"", sizeof(" cb:ACCTime=\"")-1);
  p = zx_attr_so_enc(p, x->id, " cb:id=\"", sizeof(" cb:id=\"")-1);
  p = zx_attr_so_enc(p, x->modificationTime, " cb:modificationTime=\"", sizeof(" cb:modificationTime=\"")-1);
  p = zx_attr_so_enc(p, x->modifier, " cb:modifier=\"", sizeof(" cb:modifier=\"")-1);

  p = zx_enc_unknown_attrs(p, x->gg.any_attr);
#else
  /* root node has no begin tag */
#endif
  

  p = zx_enc_so_unknown_elems_and_content(c, p, &x->gg);
  
#if 1 /* NORMALMODE */
  ZX_OUT_CLOSE_TAG(p, "</cdm:BDAY>");
  zx_pop_seen(pop_seen);
#else
  /* root node has no end tag either */
#endif
  ENC_LEN_DEBUG(x, "cdm:BDAY", p-enc_base);
  return p;
}

/* FUNC(zx_ENC_WO_cdm_BDAY) */

/* Render element into string. The XML attributes and elements are
 * processed in wire order by chasing wo pointers. This is what you want for
 * validating signatures on other people's XML documents. */

/* Called by: */
char* zx_ENC_WO_cdm_BDAY(struct zx_ctx* c, struct zx_cdm_BDAY_s* x, char* p )
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
  ZX_OUT_MEM(p, "BDAY", sizeof("BDAY")-1);
  qq = p;

  /* *** sort the namespaces */
  if (c->inc_ns)
    zx_add_inc_ns(c, &pop_seen);
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
  zx_add_xmlns_if_not_seen(c, x->gg.g.ns, &pop_seen);

  p = zx_enc_seen(p, pop_seen); 
  p = zx_attr_wo_enc(p, x->ACC, "ACC=\"", sizeof("ACC=\"")-1);
  p = zx_attr_wo_enc(p, x->ACCTime, "ACCTime=\"", sizeof("ACCTime=\"")-1);
  p = zx_attr_wo_enc(p, x->id, "id=\"", sizeof("id=\"")-1);
  p = zx_attr_wo_enc(p, x->modificationTime, "modificationTime=\"", sizeof("modificationTime=\"")-1);
  p = zx_attr_wo_enc(p, x->modifier, "modifier=\"", sizeof("modifier=\"")-1);

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
  ENC_LEN_DEBUG(x, "cdm:BDAY", p-enc_base);
  return p;
}

/* FUNC(zx_EASY_ENC_SO_cdm_BDAY) */

/* Called by: */
struct zx_str* zx_EASY_ENC_SO_cdm_BDAY(struct zx_ctx* c, struct zx_cdm_BDAY_s* x )
{
  int len;
  char* buf;
  c->ns_tab = ZX_ALLOC(c, sizeof(zx_ns_tab));
  memcpy(c->ns_tab, zx_ns_tab, sizeof(zx_ns_tab));
  len = zx_LEN_SO_cdm_BDAY(c, x );
  buf = ZX_ALLOC(c, len+1);
  return zx_easy_enc_common(c, zx_ENC_SO_cdm_BDAY(c, x, buf ), buf, len);
}

/* FUNC(zx_EASY_ENC_WO_cdm_BDAY) */

/* Called by: */
struct zx_str* zx_EASY_ENC_WO_cdm_BDAY(struct zx_ctx* c, struct zx_cdm_BDAY_s* x )
{
  int len;
  char* buf;
  c->ns_tab = ZX_ALLOC(c, sizeof(zx_ns_tab));
  memcpy(c->ns_tab, zx_ns_tab, sizeof(zx_ns_tab));
  len = zx_LEN_WO_cdm_BDAY(c, x );
  buf = ZX_ALLOC(c, len+1);
  return zx_easy_enc_common(c, zx_ENC_WO_cdm_BDAY(c, x, buf ), buf, len);
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

#define EL_NAME   cdm_BINVAL
#define EL_STRUCT zx_cdm_BINVAL_s
#define EL_NS     cdm
#define EL_TAG    BINVAL

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

/* FUNC(zx_LEN_SO_cdm_BINVAL) */

/* Compute length of an element (and its subelements). The XML attributes
 * and elements are processed in schema order. */

/* Called by: */
int zx_LEN_SO_cdm_BINVAL(struct zx_ctx* c, struct zx_cdm_BINVAL_s* x )
{
  struct zx_ns_s* pop_seen = 0;
  struct zx_elem_s* se MAYBE_UNUSED;
#if 1 /* NORMALMODE */
  /* *** in simple_elem case should output ns prefix from ns node. */
  int len = sizeof("<cdm:BINVAL")-1 + 1 + sizeof("</cdm:BINVAL>")-1;
  if (c->inc_ns_len)
    len += zx_len_inc_ns(c, &pop_seen);
  if (x->ACC || x->ACCTime || x->id || x->modificationTime || x->modifier)
    len += zx_len_xmlns_if_not_seen(c, zx_ns_tab+zx_xmlns_ix_cb, &pop_seen);
  len += zx_len_xmlns_if_not_seen(c, zx_ns_tab+zx_xmlns_ix_cdm, &pop_seen);

  len += zx_attr_so_len(x->ACC, sizeof("cb:ACC")-1);
  len += zx_attr_so_len(x->ACCTime, sizeof("cb:ACCTime")-1);
  len += zx_attr_so_len(x->id, sizeof("cb:id")-1);
  len += zx_attr_so_len(x->modificationTime, sizeof("cb:modificationTime")-1);
  len += zx_attr_so_len(x->modifier, sizeof("cb:modifier")-1);

#else
  /* root node has no begin tag */
  int len = 0;
#endif
  


  len += zx_len_so_common(c, &x->gg);
  zx_pop_seen(pop_seen);
  ENC_LEN_DEBUG(x, "cdm:BINVAL", len);
  return len;
}

/* FUNC(zx_LEN_WO_cdm_BINVAL) */

/* Compute length of an element (and its subelements). The XML attributes
 * and elements are processed in wire order and no assumptions
 * are made about namespace prefixes. */

/* Called by: */
int zx_LEN_WO_cdm_BINVAL(struct zx_ctx* c, struct zx_cdm_BINVAL_s* x )
{
  struct zx_ns_s* pop_seen = 0;
  struct zx_elem_s* se MAYBE_UNUSED;
#if 1 /* NORMALMODE */
  int len = 1 + sizeof("BINVAL")-1 + 1 + 2 + sizeof("BINVAL")-1 + 1;
  
  if (x->gg.g.ns && x->gg.g.ns->prefix_len)
    len += (x->gg.g.ns->prefix_len + 1) * 2;
  if (c->inc_ns_len)
    len += zx_len_inc_ns(c, &pop_seen);
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
  len += zx_len_xmlns_if_not_seen(c, x->gg.g.ns, &pop_seen);

  len += zx_attr_wo_len(x->ACC, sizeof("ACC")-1);
  len += zx_attr_wo_len(x->ACCTime, sizeof("ACCTime")-1);
  len += zx_attr_wo_len(x->id, sizeof("id")-1);
  len += zx_attr_wo_len(x->modificationTime, sizeof("modificationTime")-1);
  len += zx_attr_wo_len(x->modifier, sizeof("modifier")-1);

#else
  /* root node has no begin tag */
  int len = 0;
#endif
  


  len += zx_len_wo_common(c, &x->gg); 
  zx_pop_seen(pop_seen);
  ENC_LEN_DEBUG(x, "cdm:BINVAL", len);
  return len;
}

/* FUNC(zx_ENC_SO_cdm_BINVAL) */

/* Render element into string. The XML attributes and elements are
 * processed in schema order. This is what you generally want for
 * rendering new data structure to a string. The wo pointers are not used. */

/* Called by: */
char* zx_ENC_SO_cdm_BINVAL(struct zx_ctx* c, struct zx_cdm_BINVAL_s* x, char* p )
{
  struct zx_elem_s* se MAYBE_UNUSED;
  struct zx_ns_s* pop_seen = 0;
  ENC_LEN_DEBUG_BASE;
#if 1 /* NORMALMODE */
  /* *** in simple_elem case should output ns prefix from ns node. */
  ZX_OUT_TAG(p, "<cdm:BINVAL");
  if (c->inc_ns)
    p = zx_enc_inc_ns(c, p, &pop_seen);
  if (x->ACC || x->ACCTime || x->id || x->modificationTime || x->modifier)
    p = zx_enc_xmlns_if_not_seen(c, p, zx_ns_tab+zx_xmlns_ix_cb, &pop_seen);
  p = zx_enc_xmlns_if_not_seen(c, p, zx_ns_tab+zx_xmlns_ix_cdm, &pop_seen);

  p = zx_attr_so_enc(p, x->ACC, " cb:ACC=\"", sizeof(" cb:ACC=\"")-1);
  p = zx_attr_so_enc(p, x->ACCTime, " cb:ACCTime=\"", sizeof(" cb:ACCTime=\"")-1);
  p = zx_attr_so_enc(p, x->id, " cb:id=\"", sizeof(" cb:id=\"")-1);
  p = zx_attr_so_enc(p, x->modificationTime, " cb:modificationTime=\"", sizeof(" cb:modificationTime=\"")-1);
  p = zx_attr_so_enc(p, x->modifier, " cb:modifier=\"", sizeof(" cb:modifier=\"")-1);

  p = zx_enc_unknown_attrs(p, x->gg.any_attr);
#else
  /* root node has no begin tag */
#endif
  

  p = zx_enc_so_unknown_elems_and_content(c, p, &x->gg);
  
#if 1 /* NORMALMODE */
  ZX_OUT_CLOSE_TAG(p, "</cdm:BINVAL>");
  zx_pop_seen(pop_seen);
#else
  /* root node has no end tag either */
#endif
  ENC_LEN_DEBUG(x, "cdm:BINVAL", p-enc_base);
  return p;
}

/* FUNC(zx_ENC_WO_cdm_BINVAL) */

/* Render element into string. The XML attributes and elements are
 * processed in wire order by chasing wo pointers. This is what you want for
 * validating signatures on other people's XML documents. */

/* Called by: */
char* zx_ENC_WO_cdm_BINVAL(struct zx_ctx* c, struct zx_cdm_BINVAL_s* x, char* p )
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
  ZX_OUT_MEM(p, "BINVAL", sizeof("BINVAL")-1);
  qq = p;

  /* *** sort the namespaces */
  if (c->inc_ns)
    zx_add_inc_ns(c, &pop_seen);
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
  zx_add_xmlns_if_not_seen(c, x->gg.g.ns, &pop_seen);

  p = zx_enc_seen(p, pop_seen); 
  p = zx_attr_wo_enc(p, x->ACC, "ACC=\"", sizeof("ACC=\"")-1);
  p = zx_attr_wo_enc(p, x->ACCTime, "ACCTime=\"", sizeof("ACCTime=\"")-1);
  p = zx_attr_wo_enc(p, x->id, "id=\"", sizeof("id=\"")-1);
  p = zx_attr_wo_enc(p, x->modificationTime, "modificationTime=\"", sizeof("modificationTime=\"")-1);
  p = zx_attr_wo_enc(p, x->modifier, "modifier=\"", sizeof("modifier=\"")-1);

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
  ENC_LEN_DEBUG(x, "cdm:BINVAL", p-enc_base);
  return p;
}

/* FUNC(zx_EASY_ENC_SO_cdm_BINVAL) */

/* Called by: */
struct zx_str* zx_EASY_ENC_SO_cdm_BINVAL(struct zx_ctx* c, struct zx_cdm_BINVAL_s* x )
{
  int len;
  char* buf;
  c->ns_tab = ZX_ALLOC(c, sizeof(zx_ns_tab));
  memcpy(c->ns_tab, zx_ns_tab, sizeof(zx_ns_tab));
  len = zx_LEN_SO_cdm_BINVAL(c, x );
  buf = ZX_ALLOC(c, len+1);
  return zx_easy_enc_common(c, zx_ENC_SO_cdm_BINVAL(c, x, buf ), buf, len);
}

/* FUNC(zx_EASY_ENC_WO_cdm_BINVAL) */

/* Called by: */
struct zx_str* zx_EASY_ENC_WO_cdm_BINVAL(struct zx_ctx* c, struct zx_cdm_BINVAL_s* x )
{
  int len;
  char* buf;
  c->ns_tab = ZX_ALLOC(c, sizeof(zx_ns_tab));
  memcpy(c->ns_tab, zx_ns_tab, sizeof(zx_ns_tab));
  len = zx_LEN_WO_cdm_BINVAL(c, x );
  buf = ZX_ALLOC(c, len+1);
  return zx_easy_enc_common(c, zx_ENC_WO_cdm_BINVAL(c, x, buf ), buf, len);
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

#define EL_NAME   cdm_CALADRURI
#define EL_STRUCT zx_cdm_CALADRURI_s
#define EL_NS     cdm
#define EL_TAG    CALADRURI

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

/* FUNC(zx_LEN_SO_cdm_CALADRURI) */

/* Compute length of an element (and its subelements). The XML attributes
 * and elements are processed in schema order. */

/* Called by: */
int zx_LEN_SO_cdm_CALADRURI(struct zx_ctx* c, struct zx_cdm_CALADRURI_s* x )
{
  struct zx_ns_s* pop_seen = 0;
  struct zx_elem_s* se MAYBE_UNUSED;
#if 1 /* NORMALMODE */
  /* *** in simple_elem case should output ns prefix from ns node. */
  int len = sizeof("<cdm:CALADRURI")-1 + 1 + sizeof("</cdm:CALADRURI>")-1;
  if (c->inc_ns_len)
    len += zx_len_inc_ns(c, &pop_seen);
  if (x->ACC || x->ACCTime || x->id || x->modificationTime || x->modifier)
    len += zx_len_xmlns_if_not_seen(c, zx_ns_tab+zx_xmlns_ix_cb, &pop_seen);
  len += zx_len_xmlns_if_not_seen(c, zx_ns_tab+zx_xmlns_ix_cdm, &pop_seen);

  len += zx_attr_so_len(x->ACC, sizeof("cb:ACC")-1);
  len += zx_attr_so_len(x->ACCTime, sizeof("cb:ACCTime")-1);
  len += zx_attr_so_len(x->id, sizeof("cb:id")-1);
  len += zx_attr_so_len(x->modificationTime, sizeof("cb:modificationTime")-1);
  len += zx_attr_so_len(x->modifier, sizeof("cb:modifier")-1);

#else
  /* root node has no begin tag */
  int len = 0;
#endif
  
  for (se = x->PREF; se; se = (struct zx_elem_s*)se->g.n)
    len += zx_LEN_SO_simple_elem(c,se, sizeof("cdm:PREF")-1, zx_ns_tab+zx_xmlns_ix_cdm);
  {
      struct zx_cdm_URI_s* e;
      for (e = x->URI; e; e = (struct zx_cdm_URI_s*)e->gg.g.n)
	  len += zx_LEN_SO_cdm_URI(c, e);
  }


  len += zx_len_so_common(c, &x->gg);
  zx_pop_seen(pop_seen);
  ENC_LEN_DEBUG(x, "cdm:CALADRURI", len);
  return len;
}

/* FUNC(zx_LEN_WO_cdm_CALADRURI) */

/* Compute length of an element (and its subelements). The XML attributes
 * and elements are processed in wire order and no assumptions
 * are made about namespace prefixes. */

/* Called by: */
int zx_LEN_WO_cdm_CALADRURI(struct zx_ctx* c, struct zx_cdm_CALADRURI_s* x )
{
  struct zx_ns_s* pop_seen = 0;
  struct zx_elem_s* se MAYBE_UNUSED;
#if 1 /* NORMALMODE */
  int len = 1 + sizeof("CALADRURI")-1 + 1 + 2 + sizeof("CALADRURI")-1 + 1;
  
  if (x->gg.g.ns && x->gg.g.ns->prefix_len)
    len += (x->gg.g.ns->prefix_len + 1) * 2;
  if (c->inc_ns_len)
    len += zx_len_inc_ns(c, &pop_seen);
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
  len += zx_len_xmlns_if_not_seen(c, x->gg.g.ns, &pop_seen);

  len += zx_attr_wo_len(x->ACC, sizeof("ACC")-1);
  len += zx_attr_wo_len(x->ACCTime, sizeof("ACCTime")-1);
  len += zx_attr_wo_len(x->id, sizeof("id")-1);
  len += zx_attr_wo_len(x->modificationTime, sizeof("modificationTime")-1);
  len += zx_attr_wo_len(x->modifier, sizeof("modifier")-1);

#else
  /* root node has no begin tag */
  int len = 0;
#endif
  
  for (se = x->PREF; se; se = (struct zx_elem_s*)se->g.n)
    len += zx_LEN_WO_simple_elem(c, se, sizeof("PREF")-1);
  {
      struct zx_cdm_URI_s* e;
      for (e = x->URI; e; e = (struct zx_cdm_URI_s*)e->gg.g.n)
	  len += zx_LEN_WO_cdm_URI(c, e);
  }


  len += zx_len_wo_common(c, &x->gg); 
  zx_pop_seen(pop_seen);
  ENC_LEN_DEBUG(x, "cdm:CALADRURI", len);
  return len;
}

/* FUNC(zx_ENC_SO_cdm_CALADRURI) */

/* Render element into string. The XML attributes and elements are
 * processed in schema order. This is what you generally want for
 * rendering new data structure to a string. The wo pointers are not used. */

/* Called by: */
char* zx_ENC_SO_cdm_CALADRURI(struct zx_ctx* c, struct zx_cdm_CALADRURI_s* x, char* p )
{
  struct zx_elem_s* se MAYBE_UNUSED;
  struct zx_ns_s* pop_seen = 0;
  ENC_LEN_DEBUG_BASE;
#if 1 /* NORMALMODE */
  /* *** in simple_elem case should output ns prefix from ns node. */
  ZX_OUT_TAG(p, "<cdm:CALADRURI");
  if (c->inc_ns)
    p = zx_enc_inc_ns(c, p, &pop_seen);
  if (x->ACC || x->ACCTime || x->id || x->modificationTime || x->modifier)
    p = zx_enc_xmlns_if_not_seen(c, p, zx_ns_tab+zx_xmlns_ix_cb, &pop_seen);
  p = zx_enc_xmlns_if_not_seen(c, p, zx_ns_tab+zx_xmlns_ix_cdm, &pop_seen);

  p = zx_attr_so_enc(p, x->ACC, " cb:ACC=\"", sizeof(" cb:ACC=\"")-1);
  p = zx_attr_so_enc(p, x->ACCTime, " cb:ACCTime=\"", sizeof(" cb:ACCTime=\"")-1);
  p = zx_attr_so_enc(p, x->id, " cb:id=\"", sizeof(" cb:id=\"")-1);
  p = zx_attr_so_enc(p, x->modificationTime, " cb:modificationTime=\"", sizeof(" cb:modificationTime=\"")-1);
  p = zx_attr_so_enc(p, x->modifier, " cb:modifier=\"", sizeof(" cb:modifier=\"")-1);

  p = zx_enc_unknown_attrs(p, x->gg.any_attr);
#else
  /* root node has no begin tag */
#endif
  
  for (se = x->PREF; se; se = (struct zx_elem_s*)se->g.n)
    p = zx_ENC_SO_simple_elem(c, se, p, "cdm:PREF", sizeof("cdm:PREF")-1, zx_ns_tab+zx_xmlns_ix_cdm);
  {
      struct zx_cdm_URI_s* e;
      for (e = x->URI; e; e = (struct zx_cdm_URI_s*)e->gg.g.n)
	  p = zx_ENC_SO_cdm_URI(c, e, p);
  }

  p = zx_enc_so_unknown_elems_and_content(c, p, &x->gg);
  
#if 1 /* NORMALMODE */
  ZX_OUT_CLOSE_TAG(p, "</cdm:CALADRURI>");
  zx_pop_seen(pop_seen);
#else
  /* root node has no end tag either */
#endif
  ENC_LEN_DEBUG(x, "cdm:CALADRURI", p-enc_base);
  return p;
}

/* FUNC(zx_ENC_WO_cdm_CALADRURI) */

/* Render element into string. The XML attributes and elements are
 * processed in wire order by chasing wo pointers. This is what you want for
 * validating signatures on other people's XML documents. */

/* Called by: */
char* zx_ENC_WO_cdm_CALADRURI(struct zx_ctx* c, struct zx_cdm_CALADRURI_s* x, char* p )
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
  ZX_OUT_MEM(p, "CALADRURI", sizeof("CALADRURI")-1);
  qq = p;

  /* *** sort the namespaces */
  if (c->inc_ns)
    zx_add_inc_ns(c, &pop_seen);
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
  zx_add_xmlns_if_not_seen(c, x->gg.g.ns, &pop_seen);

  p = zx_enc_seen(p, pop_seen); 
  p = zx_attr_wo_enc(p, x->ACC, "ACC=\"", sizeof("ACC=\"")-1);
  p = zx_attr_wo_enc(p, x->ACCTime, "ACCTime=\"", sizeof("ACCTime=\"")-1);
  p = zx_attr_wo_enc(p, x->id, "id=\"", sizeof("id=\"")-1);
  p = zx_attr_wo_enc(p, x->modificationTime, "modificationTime=\"", sizeof("modificationTime=\"")-1);
  p = zx_attr_wo_enc(p, x->modifier, "modifier=\"", sizeof("modifier=\"")-1);

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
  ENC_LEN_DEBUG(x, "cdm:CALADRURI", p-enc_base);
  return p;
}

/* FUNC(zx_EASY_ENC_SO_cdm_CALADRURI) */

/* Called by: */
struct zx_str* zx_EASY_ENC_SO_cdm_CALADRURI(struct zx_ctx* c, struct zx_cdm_CALADRURI_s* x )
{
  int len;
  char* buf;
  c->ns_tab = ZX_ALLOC(c, sizeof(zx_ns_tab));
  memcpy(c->ns_tab, zx_ns_tab, sizeof(zx_ns_tab));
  len = zx_LEN_SO_cdm_CALADRURI(c, x );
  buf = ZX_ALLOC(c, len+1);
  return zx_easy_enc_common(c, zx_ENC_SO_cdm_CALADRURI(c, x, buf ), buf, len);
}

/* FUNC(zx_EASY_ENC_WO_cdm_CALADRURI) */

/* Called by: */
struct zx_str* zx_EASY_ENC_WO_cdm_CALADRURI(struct zx_ctx* c, struct zx_cdm_CALADRURI_s* x )
{
  int len;
  char* buf;
  c->ns_tab = ZX_ALLOC(c, sizeof(zx_ns_tab));
  memcpy(c->ns_tab, zx_ns_tab, sizeof(zx_ns_tab));
  len = zx_LEN_WO_cdm_CALADRURI(c, x );
  buf = ZX_ALLOC(c, len+1);
  return zx_easy_enc_common(c, zx_ENC_WO_cdm_CALADRURI(c, x, buf ), buf, len);
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

#define EL_NAME   cdm_CALURI
#define EL_STRUCT zx_cdm_CALURI_s
#define EL_NS     cdm
#define EL_TAG    CALURI

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

/* FUNC(zx_LEN_SO_cdm_CALURI) */

/* Compute length of an element (and its subelements). The XML attributes
 * and elements are processed in schema order. */

/* Called by: */
int zx_LEN_SO_cdm_CALURI(struct zx_ctx* c, struct zx_cdm_CALURI_s* x )
{
  struct zx_ns_s* pop_seen = 0;
  struct zx_elem_s* se MAYBE_UNUSED;
#if 1 /* NORMALMODE */
  /* *** in simple_elem case should output ns prefix from ns node. */
  int len = sizeof("<cdm:CALURI")-1 + 1 + sizeof("</cdm:CALURI>")-1;
  if (c->inc_ns_len)
    len += zx_len_inc_ns(c, &pop_seen);
  if (x->ACC || x->ACCTime || x->id || x->modificationTime || x->modifier)
    len += zx_len_xmlns_if_not_seen(c, zx_ns_tab+zx_xmlns_ix_cb, &pop_seen);
  len += zx_len_xmlns_if_not_seen(c, zx_ns_tab+zx_xmlns_ix_cdm, &pop_seen);

  len += zx_attr_so_len(x->ACC, sizeof("cb:ACC")-1);
  len += zx_attr_so_len(x->ACCTime, sizeof("cb:ACCTime")-1);
  len += zx_attr_so_len(x->id, sizeof("cb:id")-1);
  len += zx_attr_so_len(x->modificationTime, sizeof("cb:modificationTime")-1);
  len += zx_attr_so_len(x->modifier, sizeof("cb:modifier")-1);

#else
  /* root node has no begin tag */
  int len = 0;
#endif
  
  for (se = x->PREF; se; se = (struct zx_elem_s*)se->g.n)
    len += zx_LEN_SO_simple_elem(c,se, sizeof("cdm:PREF")-1, zx_ns_tab+zx_xmlns_ix_cdm);
  {
      struct zx_cdm_URI_s* e;
      for (e = x->URI; e; e = (struct zx_cdm_URI_s*)e->gg.g.n)
	  len += zx_LEN_SO_cdm_URI(c, e);
  }


  len += zx_len_so_common(c, &x->gg);
  zx_pop_seen(pop_seen);
  ENC_LEN_DEBUG(x, "cdm:CALURI", len);
  return len;
}

/* FUNC(zx_LEN_WO_cdm_CALURI) */

/* Compute length of an element (and its subelements). The XML attributes
 * and elements are processed in wire order and no assumptions
 * are made about namespace prefixes. */

/* Called by: */
int zx_LEN_WO_cdm_CALURI(struct zx_ctx* c, struct zx_cdm_CALURI_s* x )
{
  struct zx_ns_s* pop_seen = 0;
  struct zx_elem_s* se MAYBE_UNUSED;
#if 1 /* NORMALMODE */
  int len = 1 + sizeof("CALURI")-1 + 1 + 2 + sizeof("CALURI")-1 + 1;
  
  if (x->gg.g.ns && x->gg.g.ns->prefix_len)
    len += (x->gg.g.ns->prefix_len + 1) * 2;
  if (c->inc_ns_len)
    len += zx_len_inc_ns(c, &pop_seen);
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
  len += zx_len_xmlns_if_not_seen(c, x->gg.g.ns, &pop_seen);

  len += zx_attr_wo_len(x->ACC, sizeof("ACC")-1);
  len += zx_attr_wo_len(x->ACCTime, sizeof("ACCTime")-1);
  len += zx_attr_wo_len(x->id, sizeof("id")-1);
  len += zx_attr_wo_len(x->modificationTime, sizeof("modificationTime")-1);
  len += zx_attr_wo_len(x->modifier, sizeof("modifier")-1);

#else
  /* root node has no begin tag */
  int len = 0;
#endif
  
  for (se = x->PREF; se; se = (struct zx_elem_s*)se->g.n)
    len += zx_LEN_WO_simple_elem(c, se, sizeof("PREF")-1);
  {
      struct zx_cdm_URI_s* e;
      for (e = x->URI; e; e = (struct zx_cdm_URI_s*)e->gg.g.n)
	  len += zx_LEN_WO_cdm_URI(c, e);
  }


  len += zx_len_wo_common(c, &x->gg); 
  zx_pop_seen(pop_seen);
  ENC_LEN_DEBUG(x, "cdm:CALURI", len);
  return len;
}

/* FUNC(zx_ENC_SO_cdm_CALURI) */

/* Render element into string. The XML attributes and elements are
 * processed in schema order. This is what you generally want for
 * rendering new data structure to a string. The wo pointers are not used. */

/* Called by: */
char* zx_ENC_SO_cdm_CALURI(struct zx_ctx* c, struct zx_cdm_CALURI_s* x, char* p )
{
  struct zx_elem_s* se MAYBE_UNUSED;
  struct zx_ns_s* pop_seen = 0;
  ENC_LEN_DEBUG_BASE;
#if 1 /* NORMALMODE */
  /* *** in simple_elem case should output ns prefix from ns node. */
  ZX_OUT_TAG(p, "<cdm:CALURI");
  if (c->inc_ns)
    p = zx_enc_inc_ns(c, p, &pop_seen);
  if (x->ACC || x->ACCTime || x->id || x->modificationTime || x->modifier)
    p = zx_enc_xmlns_if_not_seen(c, p, zx_ns_tab+zx_xmlns_ix_cb, &pop_seen);
  p = zx_enc_xmlns_if_not_seen(c, p, zx_ns_tab+zx_xmlns_ix_cdm, &pop_seen);

  p = zx_attr_so_enc(p, x->ACC, " cb:ACC=\"", sizeof(" cb:ACC=\"")-1);
  p = zx_attr_so_enc(p, x->ACCTime, " cb:ACCTime=\"", sizeof(" cb:ACCTime=\"")-1);
  p = zx_attr_so_enc(p, x->id, " cb:id=\"", sizeof(" cb:id=\"")-1);
  p = zx_attr_so_enc(p, x->modificationTime, " cb:modificationTime=\"", sizeof(" cb:modificationTime=\"")-1);
  p = zx_attr_so_enc(p, x->modifier, " cb:modifier=\"", sizeof(" cb:modifier=\"")-1);

  p = zx_enc_unknown_attrs(p, x->gg.any_attr);
#else
  /* root node has no begin tag */
#endif
  
  for (se = x->PREF; se; se = (struct zx_elem_s*)se->g.n)
    p = zx_ENC_SO_simple_elem(c, se, p, "cdm:PREF", sizeof("cdm:PREF")-1, zx_ns_tab+zx_xmlns_ix_cdm);
  {
      struct zx_cdm_URI_s* e;
      for (e = x->URI; e; e = (struct zx_cdm_URI_s*)e->gg.g.n)
	  p = zx_ENC_SO_cdm_URI(c, e, p);
  }

  p = zx_enc_so_unknown_elems_and_content(c, p, &x->gg);
  
#if 1 /* NORMALMODE */
  ZX_OUT_CLOSE_TAG(p, "</cdm:CALURI>");
  zx_pop_seen(pop_seen);
#else
  /* root node has no end tag either */
#endif
  ENC_LEN_DEBUG(x, "cdm:CALURI", p-enc_base);
  return p;
}

/* FUNC(zx_ENC_WO_cdm_CALURI) */

/* Render element into string. The XML attributes and elements are
 * processed in wire order by chasing wo pointers. This is what you want for
 * validating signatures on other people's XML documents. */

/* Called by: */
char* zx_ENC_WO_cdm_CALURI(struct zx_ctx* c, struct zx_cdm_CALURI_s* x, char* p )
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
  ZX_OUT_MEM(p, "CALURI", sizeof("CALURI")-1);
  qq = p;

  /* *** sort the namespaces */
  if (c->inc_ns)
    zx_add_inc_ns(c, &pop_seen);
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
  zx_add_xmlns_if_not_seen(c, x->gg.g.ns, &pop_seen);

  p = zx_enc_seen(p, pop_seen); 
  p = zx_attr_wo_enc(p, x->ACC, "ACC=\"", sizeof("ACC=\"")-1);
  p = zx_attr_wo_enc(p, x->ACCTime, "ACCTime=\"", sizeof("ACCTime=\"")-1);
  p = zx_attr_wo_enc(p, x->id, "id=\"", sizeof("id=\"")-1);
  p = zx_attr_wo_enc(p, x->modificationTime, "modificationTime=\"", sizeof("modificationTime=\"")-1);
  p = zx_attr_wo_enc(p, x->modifier, "modifier=\"", sizeof("modifier=\"")-1);

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
  ENC_LEN_DEBUG(x, "cdm:CALURI", p-enc_base);
  return p;
}

/* FUNC(zx_EASY_ENC_SO_cdm_CALURI) */

/* Called by: */
struct zx_str* zx_EASY_ENC_SO_cdm_CALURI(struct zx_ctx* c, struct zx_cdm_CALURI_s* x )
{
  int len;
  char* buf;
  c->ns_tab = ZX_ALLOC(c, sizeof(zx_ns_tab));
  memcpy(c->ns_tab, zx_ns_tab, sizeof(zx_ns_tab));
  len = zx_LEN_SO_cdm_CALURI(c, x );
  buf = ZX_ALLOC(c, len+1);
  return zx_easy_enc_common(c, zx_ENC_SO_cdm_CALURI(c, x, buf ), buf, len);
}

/* FUNC(zx_EASY_ENC_WO_cdm_CALURI) */

/* Called by: */
struct zx_str* zx_EASY_ENC_WO_cdm_CALURI(struct zx_ctx* c, struct zx_cdm_CALURI_s* x )
{
  int len;
  char* buf;
  c->ns_tab = ZX_ALLOC(c, sizeof(zx_ns_tab));
  memcpy(c->ns_tab, zx_ns_tab, sizeof(zx_ns_tab));
  len = zx_LEN_WO_cdm_CALURI(c, x );
  buf = ZX_ALLOC(c, len+1);
  return zx_easy_enc_common(c, zx_ENC_WO_cdm_CALURI(c, x, buf ), buf, len);
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

#define EL_NAME   cdm_CAPURI
#define EL_STRUCT zx_cdm_CAPURI_s
#define EL_NS     cdm
#define EL_TAG    CAPURI

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

/* FUNC(zx_LEN_SO_cdm_CAPURI) */

/* Compute length of an element (and its subelements). The XML attributes
 * and elements are processed in schema order. */

/* Called by: */
int zx_LEN_SO_cdm_CAPURI(struct zx_ctx* c, struct zx_cdm_CAPURI_s* x )
{
  struct zx_ns_s* pop_seen = 0;
  struct zx_elem_s* se MAYBE_UNUSED;
#if 1 /* NORMALMODE */
  /* *** in simple_elem case should output ns prefix from ns node. */
  int len = sizeof("<cdm:CAPURI")-1 + 1 + sizeof("</cdm:CAPURI>")-1;
  if (c->inc_ns_len)
    len += zx_len_inc_ns(c, &pop_seen);
  if (x->ACC || x->ACCTime || x->id || x->modificationTime || x->modifier)
    len += zx_len_xmlns_if_not_seen(c, zx_ns_tab+zx_xmlns_ix_cb, &pop_seen);
  len += zx_len_xmlns_if_not_seen(c, zx_ns_tab+zx_xmlns_ix_cdm, &pop_seen);

  len += zx_attr_so_len(x->ACC, sizeof("cb:ACC")-1);
  len += zx_attr_so_len(x->ACCTime, sizeof("cb:ACCTime")-1);
  len += zx_attr_so_len(x->id, sizeof("cb:id")-1);
  len += zx_attr_so_len(x->modificationTime, sizeof("cb:modificationTime")-1);
  len += zx_attr_so_len(x->modifier, sizeof("cb:modifier")-1);

#else
  /* root node has no begin tag */
  int len = 0;
#endif
  
  for (se = x->PREF; se; se = (struct zx_elem_s*)se->g.n)
    len += zx_LEN_SO_simple_elem(c,se, sizeof("cdm:PREF")-1, zx_ns_tab+zx_xmlns_ix_cdm);
  {
      struct zx_cdm_URI_s* e;
      for (e = x->URI; e; e = (struct zx_cdm_URI_s*)e->gg.g.n)
	  len += zx_LEN_SO_cdm_URI(c, e);
  }


  len += zx_len_so_common(c, &x->gg);
  zx_pop_seen(pop_seen);
  ENC_LEN_DEBUG(x, "cdm:CAPURI", len);
  return len;
}

/* FUNC(zx_LEN_WO_cdm_CAPURI) */

/* Compute length of an element (and its subelements). The XML attributes
 * and elements are processed in wire order and no assumptions
 * are made about namespace prefixes. */

/* Called by: */
int zx_LEN_WO_cdm_CAPURI(struct zx_ctx* c, struct zx_cdm_CAPURI_s* x )
{
  struct zx_ns_s* pop_seen = 0;
  struct zx_elem_s* se MAYBE_UNUSED;
#if 1 /* NORMALMODE */
  int len = 1 + sizeof("CAPURI")-1 + 1 + 2 + sizeof("CAPURI")-1 + 1;
  
  if (x->gg.g.ns && x->gg.g.ns->prefix_len)
    len += (x->gg.g.ns->prefix_len + 1) * 2;
  if (c->inc_ns_len)
    len += zx_len_inc_ns(c, &pop_seen);
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
  len += zx_len_xmlns_if_not_seen(c, x->gg.g.ns, &pop_seen);

  len += zx_attr_wo_len(x->ACC, sizeof("ACC")-1);
  len += zx_attr_wo_len(x->ACCTime, sizeof("ACCTime")-1);
  len += zx_attr_wo_len(x->id, sizeof("id")-1);
  len += zx_attr_wo_len(x->modificationTime, sizeof("modificationTime")-1);
  len += zx_attr_wo_len(x->modifier, sizeof("modifier")-1);

#else
  /* root node has no begin tag */
  int len = 0;
#endif
  
  for (se = x->PREF; se; se = (struct zx_elem_s*)se->g.n)
    len += zx_LEN_WO_simple_elem(c, se, sizeof("PREF")-1);
  {
      struct zx_cdm_URI_s* e;
      for (e = x->URI; e; e = (struct zx_cdm_URI_s*)e->gg.g.n)
	  len += zx_LEN_WO_cdm_URI(c, e);
  }


  len += zx_len_wo_common(c, &x->gg); 
  zx_pop_seen(pop_seen);
  ENC_LEN_DEBUG(x, "cdm:CAPURI", len);
  return len;
}

/* FUNC(zx_ENC_SO_cdm_CAPURI) */

/* Render element into string. The XML attributes and elements are
 * processed in schema order. This is what you generally want for
 * rendering new data structure to a string. The wo pointers are not used. */

/* Called by: */
char* zx_ENC_SO_cdm_CAPURI(struct zx_ctx* c, struct zx_cdm_CAPURI_s* x, char* p )
{
  struct zx_elem_s* se MAYBE_UNUSED;
  struct zx_ns_s* pop_seen = 0;
  ENC_LEN_DEBUG_BASE;
#if 1 /* NORMALMODE */
  /* *** in simple_elem case should output ns prefix from ns node. */
  ZX_OUT_TAG(p, "<cdm:CAPURI");
  if (c->inc_ns)
    p = zx_enc_inc_ns(c, p, &pop_seen);
  if (x->ACC || x->ACCTime || x->id || x->modificationTime || x->modifier)
    p = zx_enc_xmlns_if_not_seen(c, p, zx_ns_tab+zx_xmlns_ix_cb, &pop_seen);
  p = zx_enc_xmlns_if_not_seen(c, p, zx_ns_tab+zx_xmlns_ix_cdm, &pop_seen);

  p = zx_attr_so_enc(p, x->ACC, " cb:ACC=\"", sizeof(" cb:ACC=\"")-1);
  p = zx_attr_so_enc(p, x->ACCTime, " cb:ACCTime=\"", sizeof(" cb:ACCTime=\"")-1);
  p = zx_attr_so_enc(p, x->id, " cb:id=\"", sizeof(" cb:id=\"")-1);
  p = zx_attr_so_enc(p, x->modificationTime, " cb:modificationTime=\"", sizeof(" cb:modificationTime=\"")-1);
  p = zx_attr_so_enc(p, x->modifier, " cb:modifier=\"", sizeof(" cb:modifier=\"")-1);

  p = zx_enc_unknown_attrs(p, x->gg.any_attr);
#else
  /* root node has no begin tag */
#endif
  
  for (se = x->PREF; se; se = (struct zx_elem_s*)se->g.n)
    p = zx_ENC_SO_simple_elem(c, se, p, "cdm:PREF", sizeof("cdm:PREF")-1, zx_ns_tab+zx_xmlns_ix_cdm);
  {
      struct zx_cdm_URI_s* e;
      for (e = x->URI; e; e = (struct zx_cdm_URI_s*)e->gg.g.n)
	  p = zx_ENC_SO_cdm_URI(c, e, p);
  }

  p = zx_enc_so_unknown_elems_and_content(c, p, &x->gg);
  
#if 1 /* NORMALMODE */
  ZX_OUT_CLOSE_TAG(p, "</cdm:CAPURI>");
  zx_pop_seen(pop_seen);
#else
  /* root node has no end tag either */
#endif
  ENC_LEN_DEBUG(x, "cdm:CAPURI", p-enc_base);
  return p;
}

/* FUNC(zx_ENC_WO_cdm_CAPURI) */

/* Render element into string. The XML attributes and elements are
 * processed in wire order by chasing wo pointers. This is what you want for
 * validating signatures on other people's XML documents. */

/* Called by: */
char* zx_ENC_WO_cdm_CAPURI(struct zx_ctx* c, struct zx_cdm_CAPURI_s* x, char* p )
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
  ZX_OUT_MEM(p, "CAPURI", sizeof("CAPURI")-1);
  qq = p;

  /* *** sort the namespaces */
  if (c->inc_ns)
    zx_add_inc_ns(c, &pop_seen);
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
  zx_add_xmlns_if_not_seen(c, x->gg.g.ns, &pop_seen);

  p = zx_enc_seen(p, pop_seen); 
  p = zx_attr_wo_enc(p, x->ACC, "ACC=\"", sizeof("ACC=\"")-1);
  p = zx_attr_wo_enc(p, x->ACCTime, "ACCTime=\"", sizeof("ACCTime=\"")-1);
  p = zx_attr_wo_enc(p, x->id, "id=\"", sizeof("id=\"")-1);
  p = zx_attr_wo_enc(p, x->modificationTime, "modificationTime=\"", sizeof("modificationTime=\"")-1);
  p = zx_attr_wo_enc(p, x->modifier, "modifier=\"", sizeof("modifier=\"")-1);

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
  ENC_LEN_DEBUG(x, "cdm:CAPURI", p-enc_base);
  return p;
}

/* FUNC(zx_EASY_ENC_SO_cdm_CAPURI) */

/* Called by: */
struct zx_str* zx_EASY_ENC_SO_cdm_CAPURI(struct zx_ctx* c, struct zx_cdm_CAPURI_s* x )
{
  int len;
  char* buf;
  c->ns_tab = ZX_ALLOC(c, sizeof(zx_ns_tab));
  memcpy(c->ns_tab, zx_ns_tab, sizeof(zx_ns_tab));
  len = zx_LEN_SO_cdm_CAPURI(c, x );
  buf = ZX_ALLOC(c, len+1);
  return zx_easy_enc_common(c, zx_ENC_SO_cdm_CAPURI(c, x, buf ), buf, len);
}

/* FUNC(zx_EASY_ENC_WO_cdm_CAPURI) */

/* Called by: */
struct zx_str* zx_EASY_ENC_WO_cdm_CAPURI(struct zx_ctx* c, struct zx_cdm_CAPURI_s* x )
{
  int len;
  char* buf;
  c->ns_tab = ZX_ALLOC(c, sizeof(zx_ns_tab));
  memcpy(c->ns_tab, zx_ns_tab, sizeof(zx_ns_tab));
  len = zx_LEN_WO_cdm_CAPURI(c, x );
  buf = ZX_ALLOC(c, len+1);
  return zx_easy_enc_common(c, zx_ENC_WO_cdm_CAPURI(c, x, buf ), buf, len);
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

#define EL_NAME   cdm_CATEGORIES
#define EL_STRUCT zx_cdm_CATEGORIES_s
#define EL_NS     cdm
#define EL_TAG    CATEGORIES

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

/* FUNC(zx_LEN_SO_cdm_CATEGORIES) */

/* Compute length of an element (and its subelements). The XML attributes
 * and elements are processed in schema order. */

/* Called by: */
int zx_LEN_SO_cdm_CATEGORIES(struct zx_ctx* c, struct zx_cdm_CATEGORIES_s* x )
{
  struct zx_ns_s* pop_seen = 0;
  struct zx_elem_s* se MAYBE_UNUSED;
#if 1 /* NORMALMODE */
  /* *** in simple_elem case should output ns prefix from ns node. */
  int len = sizeof("<cdm:CATEGORIES")-1 + 1 + sizeof("</cdm:CATEGORIES>")-1;
  if (c->inc_ns_len)
    len += zx_len_inc_ns(c, &pop_seen);
  if (x->id || x->modificationTime)
    len += zx_len_xmlns_if_not_seen(c, zx_ns_tab+zx_xmlns_ix_cb, &pop_seen);
  len += zx_len_xmlns_if_not_seen(c, zx_ns_tab+zx_xmlns_ix_cdm, &pop_seen);

  len += zx_attr_so_len(x->id, sizeof("cb:id")-1);
  len += zx_attr_so_len(x->modificationTime, sizeof("cb:modificationTime")-1);

#else
  /* root node has no begin tag */
  int len = 0;
#endif
  
  {
      struct zx_cdm_KEYWORD_s* e;
      for (e = x->KEYWORD; e; e = (struct zx_cdm_KEYWORD_s*)e->gg.g.n)
	  len += zx_LEN_SO_cdm_KEYWORD(c, e);
  }


  len += zx_len_so_common(c, &x->gg);
  zx_pop_seen(pop_seen);
  ENC_LEN_DEBUG(x, "cdm:CATEGORIES", len);
  return len;
}

/* FUNC(zx_LEN_WO_cdm_CATEGORIES) */

/* Compute length of an element (and its subelements). The XML attributes
 * and elements are processed in wire order and no assumptions
 * are made about namespace prefixes. */

/* Called by: */
int zx_LEN_WO_cdm_CATEGORIES(struct zx_ctx* c, struct zx_cdm_CATEGORIES_s* x )
{
  struct zx_ns_s* pop_seen = 0;
  struct zx_elem_s* se MAYBE_UNUSED;
#if 1 /* NORMALMODE */
  int len = 1 + sizeof("CATEGORIES")-1 + 1 + 2 + sizeof("CATEGORIES")-1 + 1;
  
  if (x->gg.g.ns && x->gg.g.ns->prefix_len)
    len += (x->gg.g.ns->prefix_len + 1) * 2;
  if (c->inc_ns_len)
    len += zx_len_inc_ns(c, &pop_seen);
  if (x->id)
    len += zx_len_xmlns_if_not_seen(c, x->id->g.ns, &pop_seen);
  if (x->modificationTime)
    len += zx_len_xmlns_if_not_seen(c, x->modificationTime->g.ns, &pop_seen);
  len += zx_len_xmlns_if_not_seen(c, x->gg.g.ns, &pop_seen);

  len += zx_attr_wo_len(x->id, sizeof("id")-1);
  len += zx_attr_wo_len(x->modificationTime, sizeof("modificationTime")-1);

#else
  /* root node has no begin tag */
  int len = 0;
#endif
  
  {
      struct zx_cdm_KEYWORD_s* e;
      for (e = x->KEYWORD; e; e = (struct zx_cdm_KEYWORD_s*)e->gg.g.n)
	  len += zx_LEN_WO_cdm_KEYWORD(c, e);
  }


  len += zx_len_wo_common(c, &x->gg); 
  zx_pop_seen(pop_seen);
  ENC_LEN_DEBUG(x, "cdm:CATEGORIES", len);
  return len;
}

/* FUNC(zx_ENC_SO_cdm_CATEGORIES) */

/* Render element into string. The XML attributes and elements are
 * processed in schema order. This is what you generally want for
 * rendering new data structure to a string. The wo pointers are not used. */

/* Called by: */
char* zx_ENC_SO_cdm_CATEGORIES(struct zx_ctx* c, struct zx_cdm_CATEGORIES_s* x, char* p )
{
  struct zx_elem_s* se MAYBE_UNUSED;
  struct zx_ns_s* pop_seen = 0;
  ENC_LEN_DEBUG_BASE;
#if 1 /* NORMALMODE */
  /* *** in simple_elem case should output ns prefix from ns node. */
  ZX_OUT_TAG(p, "<cdm:CATEGORIES");
  if (c->inc_ns)
    p = zx_enc_inc_ns(c, p, &pop_seen);
  if (x->id || x->modificationTime)
    p = zx_enc_xmlns_if_not_seen(c, p, zx_ns_tab+zx_xmlns_ix_cb, &pop_seen);
  p = zx_enc_xmlns_if_not_seen(c, p, zx_ns_tab+zx_xmlns_ix_cdm, &pop_seen);

  p = zx_attr_so_enc(p, x->id, " cb:id=\"", sizeof(" cb:id=\"")-1);
  p = zx_attr_so_enc(p, x->modificationTime, " cb:modificationTime=\"", sizeof(" cb:modificationTime=\"")-1);

  p = zx_enc_unknown_attrs(p, x->gg.any_attr);
#else
  /* root node has no begin tag */
#endif
  
  {
      struct zx_cdm_KEYWORD_s* e;
      for (e = x->KEYWORD; e; e = (struct zx_cdm_KEYWORD_s*)e->gg.g.n)
	  p = zx_ENC_SO_cdm_KEYWORD(c, e, p);
  }

  p = zx_enc_so_unknown_elems_and_content(c, p, &x->gg);
  
#if 1 /* NORMALMODE */
  ZX_OUT_CLOSE_TAG(p, "</cdm:CATEGORIES>");
  zx_pop_seen(pop_seen);
#else
  /* root node has no end tag either */
#endif
  ENC_LEN_DEBUG(x, "cdm:CATEGORIES", p-enc_base);
  return p;
}

/* FUNC(zx_ENC_WO_cdm_CATEGORIES) */

/* Render element into string. The XML attributes and elements are
 * processed in wire order by chasing wo pointers. This is what you want for
 * validating signatures on other people's XML documents. */

/* Called by: */
char* zx_ENC_WO_cdm_CATEGORIES(struct zx_ctx* c, struct zx_cdm_CATEGORIES_s* x, char* p )
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
  ZX_OUT_MEM(p, "CATEGORIES", sizeof("CATEGORIES")-1);
  qq = p;

  /* *** sort the namespaces */
  if (c->inc_ns)
    zx_add_inc_ns(c, &pop_seen);
  if (x->id)
    zx_add_xmlns_if_not_seen(c, x->id->g.ns, &pop_seen);
  if (x->modificationTime)
    zx_add_xmlns_if_not_seen(c, x->modificationTime->g.ns, &pop_seen);
  zx_add_xmlns_if_not_seen(c, x->gg.g.ns, &pop_seen);

  p = zx_enc_seen(p, pop_seen); 
  p = zx_attr_wo_enc(p, x->id, "id=\"", sizeof("id=\"")-1);
  p = zx_attr_wo_enc(p, x->modificationTime, "modificationTime=\"", sizeof("modificationTime=\"")-1);

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
  ENC_LEN_DEBUG(x, "cdm:CATEGORIES", p-enc_base);
  return p;
}

/* FUNC(zx_EASY_ENC_SO_cdm_CATEGORIES) */

/* Called by: */
struct zx_str* zx_EASY_ENC_SO_cdm_CATEGORIES(struct zx_ctx* c, struct zx_cdm_CATEGORIES_s* x )
{
  int len;
  char* buf;
  c->ns_tab = ZX_ALLOC(c, sizeof(zx_ns_tab));
  memcpy(c->ns_tab, zx_ns_tab, sizeof(zx_ns_tab));
  len = zx_LEN_SO_cdm_CATEGORIES(c, x );
  buf = ZX_ALLOC(c, len+1);
  return zx_easy_enc_common(c, zx_ENC_SO_cdm_CATEGORIES(c, x, buf ), buf, len);
}

/* FUNC(zx_EASY_ENC_WO_cdm_CATEGORIES) */

/* Called by: */
struct zx_str* zx_EASY_ENC_WO_cdm_CATEGORIES(struct zx_ctx* c, struct zx_cdm_CATEGORIES_s* x )
{
  int len;
  char* buf;
  c->ns_tab = ZX_ALLOC(c, sizeof(zx_ns_tab));
  memcpy(c->ns_tab, zx_ns_tab, sizeof(zx_ns_tab));
  len = zx_LEN_WO_cdm_CATEGORIES(c, x );
  buf = ZX_ALLOC(c, len+1);
  return zx_easy_enc_common(c, zx_ENC_WO_cdm_CATEGORIES(c, x, buf ), buf, len);
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

#define EL_NAME   cdm_CLASS
#define EL_STRUCT zx_cdm_CLASS_s
#define EL_NS     cdm
#define EL_TAG    CLASS

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

/* FUNC(zx_LEN_SO_cdm_CLASS) */

/* Compute length of an element (and its subelements). The XML attributes
 * and elements are processed in schema order. */

/* Called by: */
int zx_LEN_SO_cdm_CLASS(struct zx_ctx* c, struct zx_cdm_CLASS_s* x )
{
  struct zx_ns_s* pop_seen = 0;
  struct zx_elem_s* se MAYBE_UNUSED;
#if 1 /* NORMALMODE */
  /* *** in simple_elem case should output ns prefix from ns node. */
  int len = sizeof("<cdm:CLASS")-1 + 1 + sizeof("</cdm:CLASS>")-1;
  if (c->inc_ns_len)
    len += zx_len_inc_ns(c, &pop_seen);
  if (x->ACC || x->ACCTime || x->id || x->modificationTime || x->modifier)
    len += zx_len_xmlns_if_not_seen(c, zx_ns_tab+zx_xmlns_ix_cb, &pop_seen);
  len += zx_len_xmlns_if_not_seen(c, zx_ns_tab+zx_xmlns_ix_cdm, &pop_seen);

  len += zx_attr_so_len(x->ACC, sizeof("cb:ACC")-1);
  len += zx_attr_so_len(x->ACCTime, sizeof("cb:ACCTime")-1);
  len += zx_attr_so_len(x->id, sizeof("cb:id")-1);
  len += zx_attr_so_len(x->modificationTime, sizeof("cb:modificationTime")-1);
  len += zx_attr_so_len(x->modifier, sizeof("cb:modifier")-1);

#else
  /* root node has no begin tag */
  int len = 0;
#endif
  
  for (se = x->PUBLIC; se; se = (struct zx_elem_s*)se->g.n)
    len += zx_LEN_SO_simple_elem(c,se, sizeof("cdm:PUBLIC")-1, zx_ns_tab+zx_xmlns_ix_cdm);
  for (se = x->PRIVATE; se; se = (struct zx_elem_s*)se->g.n)
    len += zx_LEN_SO_simple_elem(c,se, sizeof("cdm:PRIVATE")-1, zx_ns_tab+zx_xmlns_ix_cdm);
  for (se = x->CONFIDENTIAL; se; se = (struct zx_elem_s*)se->g.n)
    len += zx_LEN_SO_simple_elem(c,se, sizeof("cdm:CONFIDENTIAL")-1, zx_ns_tab+zx_xmlns_ix_cdm);


  len += zx_len_so_common(c, &x->gg);
  zx_pop_seen(pop_seen);
  ENC_LEN_DEBUG(x, "cdm:CLASS", len);
  return len;
}

/* FUNC(zx_LEN_WO_cdm_CLASS) */

/* Compute length of an element (and its subelements). The XML attributes
 * and elements are processed in wire order and no assumptions
 * are made about namespace prefixes. */

/* Called by: */
int zx_LEN_WO_cdm_CLASS(struct zx_ctx* c, struct zx_cdm_CLASS_s* x )
{
  struct zx_ns_s* pop_seen = 0;
  struct zx_elem_s* se MAYBE_UNUSED;
#if 1 /* NORMALMODE */
  int len = 1 + sizeof("CLASS")-1 + 1 + 2 + sizeof("CLASS")-1 + 1;
  
  if (x->gg.g.ns && x->gg.g.ns->prefix_len)
    len += (x->gg.g.ns->prefix_len + 1) * 2;
  if (c->inc_ns_len)
    len += zx_len_inc_ns(c, &pop_seen);
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
  len += zx_len_xmlns_if_not_seen(c, x->gg.g.ns, &pop_seen);

  len += zx_attr_wo_len(x->ACC, sizeof("ACC")-1);
  len += zx_attr_wo_len(x->ACCTime, sizeof("ACCTime")-1);
  len += zx_attr_wo_len(x->id, sizeof("id")-1);
  len += zx_attr_wo_len(x->modificationTime, sizeof("modificationTime")-1);
  len += zx_attr_wo_len(x->modifier, sizeof("modifier")-1);

#else
  /* root node has no begin tag */
  int len = 0;
#endif
  
  for (se = x->PUBLIC; se; se = (struct zx_elem_s*)se->g.n)
    len += zx_LEN_WO_simple_elem(c, se, sizeof("PUBLIC")-1);
  for (se = x->PRIVATE; se; se = (struct zx_elem_s*)se->g.n)
    len += zx_LEN_WO_simple_elem(c, se, sizeof("PRIVATE")-1);
  for (se = x->CONFIDENTIAL; se; se = (struct zx_elem_s*)se->g.n)
    len += zx_LEN_WO_simple_elem(c, se, sizeof("CONFIDENTIAL")-1);


  len += zx_len_wo_common(c, &x->gg); 
  zx_pop_seen(pop_seen);
  ENC_LEN_DEBUG(x, "cdm:CLASS", len);
  return len;
}

/* FUNC(zx_ENC_SO_cdm_CLASS) */

/* Render element into string. The XML attributes and elements are
 * processed in schema order. This is what you generally want for
 * rendering new data structure to a string. The wo pointers are not used. */

/* Called by: */
char* zx_ENC_SO_cdm_CLASS(struct zx_ctx* c, struct zx_cdm_CLASS_s* x, char* p )
{
  struct zx_elem_s* se MAYBE_UNUSED;
  struct zx_ns_s* pop_seen = 0;
  ENC_LEN_DEBUG_BASE;
#if 1 /* NORMALMODE */
  /* *** in simple_elem case should output ns prefix from ns node. */
  ZX_OUT_TAG(p, "<cdm:CLASS");
  if (c->inc_ns)
    p = zx_enc_inc_ns(c, p, &pop_seen);
  if (x->ACC || x->ACCTime || x->id || x->modificationTime || x->modifier)
    p = zx_enc_xmlns_if_not_seen(c, p, zx_ns_tab+zx_xmlns_ix_cb, &pop_seen);
  p = zx_enc_xmlns_if_not_seen(c, p, zx_ns_tab+zx_xmlns_ix_cdm, &pop_seen);

  p = zx_attr_so_enc(p, x->ACC, " cb:ACC=\"", sizeof(" cb:ACC=\"")-1);
  p = zx_attr_so_enc(p, x->ACCTime, " cb:ACCTime=\"", sizeof(" cb:ACCTime=\"")-1);
  p = zx_attr_so_enc(p, x->id, " cb:id=\"", sizeof(" cb:id=\"")-1);
  p = zx_attr_so_enc(p, x->modificationTime, " cb:modificationTime=\"", sizeof(" cb:modificationTime=\"")-1);
  p = zx_attr_so_enc(p, x->modifier, " cb:modifier=\"", sizeof(" cb:modifier=\"")-1);

  p = zx_enc_unknown_attrs(p, x->gg.any_attr);
#else
  /* root node has no begin tag */
#endif
  
  for (se = x->PUBLIC; se; se = (struct zx_elem_s*)se->g.n)
    p = zx_ENC_SO_simple_elem(c, se, p, "cdm:PUBLIC", sizeof("cdm:PUBLIC")-1, zx_ns_tab+zx_xmlns_ix_cdm);
  for (se = x->PRIVATE; se; se = (struct zx_elem_s*)se->g.n)
    p = zx_ENC_SO_simple_elem(c, se, p, "cdm:PRIVATE", sizeof("cdm:PRIVATE")-1, zx_ns_tab+zx_xmlns_ix_cdm);
  for (se = x->CONFIDENTIAL; se; se = (struct zx_elem_s*)se->g.n)
    p = zx_ENC_SO_simple_elem(c, se, p, "cdm:CONFIDENTIAL", sizeof("cdm:CONFIDENTIAL")-1, zx_ns_tab+zx_xmlns_ix_cdm);

  p = zx_enc_so_unknown_elems_and_content(c, p, &x->gg);
  
#if 1 /* NORMALMODE */
  ZX_OUT_CLOSE_TAG(p, "</cdm:CLASS>");
  zx_pop_seen(pop_seen);
#else
  /* root node has no end tag either */
#endif
  ENC_LEN_DEBUG(x, "cdm:CLASS", p-enc_base);
  return p;
}

/* FUNC(zx_ENC_WO_cdm_CLASS) */

/* Render element into string. The XML attributes and elements are
 * processed in wire order by chasing wo pointers. This is what you want for
 * validating signatures on other people's XML documents. */

/* Called by: */
char* zx_ENC_WO_cdm_CLASS(struct zx_ctx* c, struct zx_cdm_CLASS_s* x, char* p )
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
  ZX_OUT_MEM(p, "CLASS", sizeof("CLASS")-1);
  qq = p;

  /* *** sort the namespaces */
  if (c->inc_ns)
    zx_add_inc_ns(c, &pop_seen);
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
  zx_add_xmlns_if_not_seen(c, x->gg.g.ns, &pop_seen);

  p = zx_enc_seen(p, pop_seen); 
  p = zx_attr_wo_enc(p, x->ACC, "ACC=\"", sizeof("ACC=\"")-1);
  p = zx_attr_wo_enc(p, x->ACCTime, "ACCTime=\"", sizeof("ACCTime=\"")-1);
  p = zx_attr_wo_enc(p, x->id, "id=\"", sizeof("id=\"")-1);
  p = zx_attr_wo_enc(p, x->modificationTime, "modificationTime=\"", sizeof("modificationTime=\"")-1);
  p = zx_attr_wo_enc(p, x->modifier, "modifier=\"", sizeof("modifier=\"")-1);

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
  ENC_LEN_DEBUG(x, "cdm:CLASS", p-enc_base);
  return p;
}

/* FUNC(zx_EASY_ENC_SO_cdm_CLASS) */

/* Called by: */
struct zx_str* zx_EASY_ENC_SO_cdm_CLASS(struct zx_ctx* c, struct zx_cdm_CLASS_s* x )
{
  int len;
  char* buf;
  c->ns_tab = ZX_ALLOC(c, sizeof(zx_ns_tab));
  memcpy(c->ns_tab, zx_ns_tab, sizeof(zx_ns_tab));
  len = zx_LEN_SO_cdm_CLASS(c, x );
  buf = ZX_ALLOC(c, len+1);
  return zx_easy_enc_common(c, zx_ENC_SO_cdm_CLASS(c, x, buf ), buf, len);
}

/* FUNC(zx_EASY_ENC_WO_cdm_CLASS) */

/* Called by: */
struct zx_str* zx_EASY_ENC_WO_cdm_CLASS(struct zx_ctx* c, struct zx_cdm_CLASS_s* x )
{
  int len;
  char* buf;
  c->ns_tab = ZX_ALLOC(c, sizeof(zx_ns_tab));
  memcpy(c->ns_tab, zx_ns_tab, sizeof(zx_ns_tab));
  len = zx_LEN_WO_cdm_CLASS(c, x );
  buf = ZX_ALLOC(c, len+1);
  return zx_easy_enc_common(c, zx_ENC_WO_cdm_CLASS(c, x, buf ), buf, len);
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

#define EL_NAME   cdm_CRED
#define EL_STRUCT zx_cdm_CRED_s
#define EL_NS     cdm
#define EL_TAG    CRED

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

/* FUNC(zx_LEN_SO_cdm_CRED) */

/* Compute length of an element (and its subelements). The XML attributes
 * and elements are processed in schema order. */

/* Called by: */
int zx_LEN_SO_cdm_CRED(struct zx_ctx* c, struct zx_cdm_CRED_s* x )
{
  struct zx_ns_s* pop_seen = 0;
  struct zx_elem_s* se MAYBE_UNUSED;
#if 1 /* NORMALMODE */
  /* *** in simple_elem case should output ns prefix from ns node. */
  int len = sizeof("<cdm:CRED")-1 + 1 + sizeof("</cdm:CRED>")-1;
  if (c->inc_ns_len)
    len += zx_len_inc_ns(c, &pop_seen);
  if (x->ACC || x->ACCTime || x->id || x->modificationTime || x->modifier)
    len += zx_len_xmlns_if_not_seen(c, zx_ns_tab+zx_xmlns_ix_cb, &pop_seen);
  len += zx_len_xmlns_if_not_seen(c, zx_ns_tab+zx_xmlns_ix_cdm, &pop_seen);

  len += zx_attr_so_len(x->ACC, sizeof("cb:ACC")-1);
  len += zx_attr_so_len(x->ACCTime, sizeof("cb:ACCTime")-1);
  len += zx_attr_so_len(x->id, sizeof("cb:id")-1);
  len += zx_attr_so_len(x->modificationTime, sizeof("cb:modificationTime")-1);
  len += zx_attr_so_len(x->modifier, sizeof("cb:modifier")-1);

#else
  /* root node has no begin tag */
  int len = 0;
#endif
  


  len += zx_len_so_common(c, &x->gg);
  zx_pop_seen(pop_seen);
  ENC_LEN_DEBUG(x, "cdm:CRED", len);
  return len;
}

/* FUNC(zx_LEN_WO_cdm_CRED) */

/* Compute length of an element (and its subelements). The XML attributes
 * and elements are processed in wire order and no assumptions
 * are made about namespace prefixes. */

/* Called by: */
int zx_LEN_WO_cdm_CRED(struct zx_ctx* c, struct zx_cdm_CRED_s* x )
{
  struct zx_ns_s* pop_seen = 0;
  struct zx_elem_s* se MAYBE_UNUSED;
#if 1 /* NORMALMODE */
  int len = 1 + sizeof("CRED")-1 + 1 + 2 + sizeof("CRED")-1 + 1;
  
  if (x->gg.g.ns && x->gg.g.ns->prefix_len)
    len += (x->gg.g.ns->prefix_len + 1) * 2;
  if (c->inc_ns_len)
    len += zx_len_inc_ns(c, &pop_seen);
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
  len += zx_len_xmlns_if_not_seen(c, x->gg.g.ns, &pop_seen);

  len += zx_attr_wo_len(x->ACC, sizeof("ACC")-1);
  len += zx_attr_wo_len(x->ACCTime, sizeof("ACCTime")-1);
  len += zx_attr_wo_len(x->id, sizeof("id")-1);
  len += zx_attr_wo_len(x->modificationTime, sizeof("modificationTime")-1);
  len += zx_attr_wo_len(x->modifier, sizeof("modifier")-1);

#else
  /* root node has no begin tag */
  int len = 0;
#endif
  


  len += zx_len_wo_common(c, &x->gg); 
  zx_pop_seen(pop_seen);
  ENC_LEN_DEBUG(x, "cdm:CRED", len);
  return len;
}

/* FUNC(zx_ENC_SO_cdm_CRED) */

/* Render element into string. The XML attributes and elements are
 * processed in schema order. This is what you generally want for
 * rendering new data structure to a string. The wo pointers are not used. */

/* Called by: */
char* zx_ENC_SO_cdm_CRED(struct zx_ctx* c, struct zx_cdm_CRED_s* x, char* p )
{
  struct zx_elem_s* se MAYBE_UNUSED;
  struct zx_ns_s* pop_seen = 0;
  ENC_LEN_DEBUG_BASE;
#if 1 /* NORMALMODE */
  /* *** in simple_elem case should output ns prefix from ns node. */
  ZX_OUT_TAG(p, "<cdm:CRED");
  if (c->inc_ns)
    p = zx_enc_inc_ns(c, p, &pop_seen);
  if (x->ACC || x->ACCTime || x->id || x->modificationTime || x->modifier)
    p = zx_enc_xmlns_if_not_seen(c, p, zx_ns_tab+zx_xmlns_ix_cb, &pop_seen);
  p = zx_enc_xmlns_if_not_seen(c, p, zx_ns_tab+zx_xmlns_ix_cdm, &pop_seen);

  p = zx_attr_so_enc(p, x->ACC, " cb:ACC=\"", sizeof(" cb:ACC=\"")-1);
  p = zx_attr_so_enc(p, x->ACCTime, " cb:ACCTime=\"", sizeof(" cb:ACCTime=\"")-1);
  p = zx_attr_so_enc(p, x->id, " cb:id=\"", sizeof(" cb:id=\"")-1);
  p = zx_attr_so_enc(p, x->modificationTime, " cb:modificationTime=\"", sizeof(" cb:modificationTime=\"")-1);
  p = zx_attr_so_enc(p, x->modifier, " cb:modifier=\"", sizeof(" cb:modifier=\"")-1);

  p = zx_enc_unknown_attrs(p, x->gg.any_attr);
#else
  /* root node has no begin tag */
#endif
  

  p = zx_enc_so_unknown_elems_and_content(c, p, &x->gg);
  
#if 1 /* NORMALMODE */
  ZX_OUT_CLOSE_TAG(p, "</cdm:CRED>");
  zx_pop_seen(pop_seen);
#else
  /* root node has no end tag either */
#endif
  ENC_LEN_DEBUG(x, "cdm:CRED", p-enc_base);
  return p;
}

/* FUNC(zx_ENC_WO_cdm_CRED) */

/* Render element into string. The XML attributes and elements are
 * processed in wire order by chasing wo pointers. This is what you want for
 * validating signatures on other people's XML documents. */

/* Called by: */
char* zx_ENC_WO_cdm_CRED(struct zx_ctx* c, struct zx_cdm_CRED_s* x, char* p )
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
  ZX_OUT_MEM(p, "CRED", sizeof("CRED")-1);
  qq = p;

  /* *** sort the namespaces */
  if (c->inc_ns)
    zx_add_inc_ns(c, &pop_seen);
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
  zx_add_xmlns_if_not_seen(c, x->gg.g.ns, &pop_seen);

  p = zx_enc_seen(p, pop_seen); 
  p = zx_attr_wo_enc(p, x->ACC, "ACC=\"", sizeof("ACC=\"")-1);
  p = zx_attr_wo_enc(p, x->ACCTime, "ACCTime=\"", sizeof("ACCTime=\"")-1);
  p = zx_attr_wo_enc(p, x->id, "id=\"", sizeof("id=\"")-1);
  p = zx_attr_wo_enc(p, x->modificationTime, "modificationTime=\"", sizeof("modificationTime=\"")-1);
  p = zx_attr_wo_enc(p, x->modifier, "modifier=\"", sizeof("modifier=\"")-1);

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
  ENC_LEN_DEBUG(x, "cdm:CRED", p-enc_base);
  return p;
}

/* FUNC(zx_EASY_ENC_SO_cdm_CRED) */

/* Called by: */
struct zx_str* zx_EASY_ENC_SO_cdm_CRED(struct zx_ctx* c, struct zx_cdm_CRED_s* x )
{
  int len;
  char* buf;
  c->ns_tab = ZX_ALLOC(c, sizeof(zx_ns_tab));
  memcpy(c->ns_tab, zx_ns_tab, sizeof(zx_ns_tab));
  len = zx_LEN_SO_cdm_CRED(c, x );
  buf = ZX_ALLOC(c, len+1);
  return zx_easy_enc_common(c, zx_ENC_SO_cdm_CRED(c, x, buf ), buf, len);
}

/* FUNC(zx_EASY_ENC_WO_cdm_CRED) */

/* Called by: */
struct zx_str* zx_EASY_ENC_WO_cdm_CRED(struct zx_ctx* c, struct zx_cdm_CRED_s* x )
{
  int len;
  char* buf;
  c->ns_tab = ZX_ALLOC(c, sizeof(zx_ns_tab));
  memcpy(c->ns_tab, zx_ns_tab, sizeof(zx_ns_tab));
  len = zx_LEN_WO_cdm_CRED(c, x );
  buf = ZX_ALLOC(c, len+1);
  return zx_easy_enc_common(c, zx_ENC_WO_cdm_CRED(c, x, buf ), buf, len);
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

#define EL_NAME   cdm_CTRY
#define EL_STRUCT zx_cdm_CTRY_s
#define EL_NS     cdm
#define EL_TAG    CTRY

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

/* FUNC(zx_LEN_SO_cdm_CTRY) */

/* Compute length of an element (and its subelements). The XML attributes
 * and elements are processed in schema order. */

/* Called by: */
int zx_LEN_SO_cdm_CTRY(struct zx_ctx* c, struct zx_cdm_CTRY_s* x )
{
  struct zx_ns_s* pop_seen = 0;
  struct zx_elem_s* se MAYBE_UNUSED;
#if 1 /* NORMALMODE */
  /* *** in simple_elem case should output ns prefix from ns node. */
  int len = sizeof("<cdm:CTRY")-1 + 1 + sizeof("</cdm:CTRY>")-1;
  if (c->inc_ns_len)
    len += zx_len_inc_ns(c, &pop_seen);
  if (x->group)
    len += zx_len_xmlns_if_not_seen(c, zx_ns_tab+zx_xmlns_ix_cb, &pop_seen);
  len += zx_len_xmlns_if_not_seen(c, zx_ns_tab+zx_xmlns_ix_cdm, &pop_seen);

  len += zx_attr_so_len(x->group, sizeof("cb:group")-1);

#else
  /* root node has no begin tag */
  int len = 0;
#endif
  


  len += zx_len_so_common(c, &x->gg);
  zx_pop_seen(pop_seen);
  ENC_LEN_DEBUG(x, "cdm:CTRY", len);
  return len;
}

/* FUNC(zx_LEN_WO_cdm_CTRY) */

/* Compute length of an element (and its subelements). The XML attributes
 * and elements are processed in wire order and no assumptions
 * are made about namespace prefixes. */

/* Called by: */
int zx_LEN_WO_cdm_CTRY(struct zx_ctx* c, struct zx_cdm_CTRY_s* x )
{
  struct zx_ns_s* pop_seen = 0;
  struct zx_elem_s* se MAYBE_UNUSED;
#if 1 /* NORMALMODE */
  int len = 1 + sizeof("CTRY")-1 + 1 + 2 + sizeof("CTRY")-1 + 1;
  
  if (x->gg.g.ns && x->gg.g.ns->prefix_len)
    len += (x->gg.g.ns->prefix_len + 1) * 2;
  if (c->inc_ns_len)
    len += zx_len_inc_ns(c, &pop_seen);
  if (x->group)
    len += zx_len_xmlns_if_not_seen(c, x->group->g.ns, &pop_seen);
  len += zx_len_xmlns_if_not_seen(c, x->gg.g.ns, &pop_seen);

  len += zx_attr_wo_len(x->group, sizeof("group")-1);

#else
  /* root node has no begin tag */
  int len = 0;
#endif
  


  len += zx_len_wo_common(c, &x->gg); 
  zx_pop_seen(pop_seen);
  ENC_LEN_DEBUG(x, "cdm:CTRY", len);
  return len;
}

/* FUNC(zx_ENC_SO_cdm_CTRY) */

/* Render element into string. The XML attributes and elements are
 * processed in schema order. This is what you generally want for
 * rendering new data structure to a string. The wo pointers are not used. */

/* Called by: */
char* zx_ENC_SO_cdm_CTRY(struct zx_ctx* c, struct zx_cdm_CTRY_s* x, char* p )
{
  struct zx_elem_s* se MAYBE_UNUSED;
  struct zx_ns_s* pop_seen = 0;
  ENC_LEN_DEBUG_BASE;
#if 1 /* NORMALMODE */
  /* *** in simple_elem case should output ns prefix from ns node. */
  ZX_OUT_TAG(p, "<cdm:CTRY");
  if (c->inc_ns)
    p = zx_enc_inc_ns(c, p, &pop_seen);
  if (x->group)
    p = zx_enc_xmlns_if_not_seen(c, p, zx_ns_tab+zx_xmlns_ix_cb, &pop_seen);
  p = zx_enc_xmlns_if_not_seen(c, p, zx_ns_tab+zx_xmlns_ix_cdm, &pop_seen);

  p = zx_attr_so_enc(p, x->group, " cb:group=\"", sizeof(" cb:group=\"")-1);

  p = zx_enc_unknown_attrs(p, x->gg.any_attr);
#else
  /* root node has no begin tag */
#endif
  

  p = zx_enc_so_unknown_elems_and_content(c, p, &x->gg);
  
#if 1 /* NORMALMODE */
  ZX_OUT_CLOSE_TAG(p, "</cdm:CTRY>");
  zx_pop_seen(pop_seen);
#else
  /* root node has no end tag either */
#endif
  ENC_LEN_DEBUG(x, "cdm:CTRY", p-enc_base);
  return p;
}

/* FUNC(zx_ENC_WO_cdm_CTRY) */

/* Render element into string. The XML attributes and elements are
 * processed in wire order by chasing wo pointers. This is what you want for
 * validating signatures on other people's XML documents. */

/* Called by: */
char* zx_ENC_WO_cdm_CTRY(struct zx_ctx* c, struct zx_cdm_CTRY_s* x, char* p )
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
  ZX_OUT_MEM(p, "CTRY", sizeof("CTRY")-1);
  qq = p;

  /* *** sort the namespaces */
  if (c->inc_ns)
    zx_add_inc_ns(c, &pop_seen);
  if (x->group)
    zx_add_xmlns_if_not_seen(c, x->group->g.ns, &pop_seen);
  zx_add_xmlns_if_not_seen(c, x->gg.g.ns, &pop_seen);

  p = zx_enc_seen(p, pop_seen); 
  p = zx_attr_wo_enc(p, x->group, "group=\"", sizeof("group=\"")-1);

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
  ENC_LEN_DEBUG(x, "cdm:CTRY", p-enc_base);
  return p;
}

/* FUNC(zx_EASY_ENC_SO_cdm_CTRY) */

/* Called by: */
struct zx_str* zx_EASY_ENC_SO_cdm_CTRY(struct zx_ctx* c, struct zx_cdm_CTRY_s* x )
{
  int len;
  char* buf;
  c->ns_tab = ZX_ALLOC(c, sizeof(zx_ns_tab));
  memcpy(c->ns_tab, zx_ns_tab, sizeof(zx_ns_tab));
  len = zx_LEN_SO_cdm_CTRY(c, x );
  buf = ZX_ALLOC(c, len+1);
  return zx_easy_enc_common(c, zx_ENC_SO_cdm_CTRY(c, x, buf ), buf, len);
}

/* FUNC(zx_EASY_ENC_WO_cdm_CTRY) */

/* Called by: */
struct zx_str* zx_EASY_ENC_WO_cdm_CTRY(struct zx_ctx* c, struct zx_cdm_CTRY_s* x )
{
  int len;
  char* buf;
  c->ns_tab = ZX_ALLOC(c, sizeof(zx_ns_tab));
  memcpy(c->ns_tab, zx_ns_tab, sizeof(zx_ns_tab));
  len = zx_LEN_WO_cdm_CTRY(c, x );
  buf = ZX_ALLOC(c, len+1);
  return zx_easy_enc_common(c, zx_ENC_WO_cdm_CTRY(c, x, buf ), buf, len);
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

#define EL_NAME   cdm_DESC
#define EL_STRUCT zx_cdm_DESC_s
#define EL_NS     cdm
#define EL_TAG    DESC

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

/* FUNC(zx_LEN_SO_cdm_DESC) */

/* Compute length of an element (and its subelements). The XML attributes
 * and elements are processed in schema order. */

/* Called by: */
int zx_LEN_SO_cdm_DESC(struct zx_ctx* c, struct zx_cdm_DESC_s* x )
{
  struct zx_ns_s* pop_seen = 0;
  struct zx_elem_s* se MAYBE_UNUSED;
#if 1 /* NORMALMODE */
  /* *** in simple_elem case should output ns prefix from ns node. */
  int len = sizeof("<cdm:DESC")-1 + 1 + sizeof("</cdm:DESC>")-1;
  if (c->inc_ns_len)
    len += zx_len_inc_ns(c, &pop_seen);
  if (x->group)
    len += zx_len_xmlns_if_not_seen(c, zx_ns_tab+zx_xmlns_ix_cb, &pop_seen);
  len += zx_len_xmlns_if_not_seen(c, zx_ns_tab+zx_xmlns_ix_cdm, &pop_seen);

  len += zx_attr_so_len(x->group, sizeof("cb:group")-1);

#else
  /* root node has no begin tag */
  int len = 0;
#endif
  


  len += zx_len_so_common(c, &x->gg);
  zx_pop_seen(pop_seen);
  ENC_LEN_DEBUG(x, "cdm:DESC", len);
  return len;
}

/* FUNC(zx_LEN_WO_cdm_DESC) */

/* Compute length of an element (and its subelements). The XML attributes
 * and elements are processed in wire order and no assumptions
 * are made about namespace prefixes. */

/* Called by: */
int zx_LEN_WO_cdm_DESC(struct zx_ctx* c, struct zx_cdm_DESC_s* x )
{
  struct zx_ns_s* pop_seen = 0;
  struct zx_elem_s* se MAYBE_UNUSED;
#if 1 /* NORMALMODE */
  int len = 1 + sizeof("DESC")-1 + 1 + 2 + sizeof("DESC")-1 + 1;
  
  if (x->gg.g.ns && x->gg.g.ns->prefix_len)
    len += (x->gg.g.ns->prefix_len + 1) * 2;
  if (c->inc_ns_len)
    len += zx_len_inc_ns(c, &pop_seen);
  if (x->group)
    len += zx_len_xmlns_if_not_seen(c, x->group->g.ns, &pop_seen);
  len += zx_len_xmlns_if_not_seen(c, x->gg.g.ns, &pop_seen);

  len += zx_attr_wo_len(x->group, sizeof("group")-1);

#else
  /* root node has no begin tag */
  int len = 0;
#endif
  


  len += zx_len_wo_common(c, &x->gg); 
  zx_pop_seen(pop_seen);
  ENC_LEN_DEBUG(x, "cdm:DESC", len);
  return len;
}

/* FUNC(zx_ENC_SO_cdm_DESC) */

/* Render element into string. The XML attributes and elements are
 * processed in schema order. This is what you generally want for
 * rendering new data structure to a string. The wo pointers are not used. */

/* Called by: */
char* zx_ENC_SO_cdm_DESC(struct zx_ctx* c, struct zx_cdm_DESC_s* x, char* p )
{
  struct zx_elem_s* se MAYBE_UNUSED;
  struct zx_ns_s* pop_seen = 0;
  ENC_LEN_DEBUG_BASE;
#if 1 /* NORMALMODE */
  /* *** in simple_elem case should output ns prefix from ns node. */
  ZX_OUT_TAG(p, "<cdm:DESC");
  if (c->inc_ns)
    p = zx_enc_inc_ns(c, p, &pop_seen);
  if (x->group)
    p = zx_enc_xmlns_if_not_seen(c, p, zx_ns_tab+zx_xmlns_ix_cb, &pop_seen);
  p = zx_enc_xmlns_if_not_seen(c, p, zx_ns_tab+zx_xmlns_ix_cdm, &pop_seen);

  p = zx_attr_so_enc(p, x->group, " cb:group=\"", sizeof(" cb:group=\"")-1);

  p = zx_enc_unknown_attrs(p, x->gg.any_attr);
#else
  /* root node has no begin tag */
#endif
  

  p = zx_enc_so_unknown_elems_and_content(c, p, &x->gg);
  
#if 1 /* NORMALMODE */
  ZX_OUT_CLOSE_TAG(p, "</cdm:DESC>");
  zx_pop_seen(pop_seen);
#else
  /* root node has no end tag either */
#endif
  ENC_LEN_DEBUG(x, "cdm:DESC", p-enc_base);
  return p;
}

/* FUNC(zx_ENC_WO_cdm_DESC) */

/* Render element into string. The XML attributes and elements are
 * processed in wire order by chasing wo pointers. This is what you want for
 * validating signatures on other people's XML documents. */

/* Called by: */
char* zx_ENC_WO_cdm_DESC(struct zx_ctx* c, struct zx_cdm_DESC_s* x, char* p )
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
  ZX_OUT_MEM(p, "DESC", sizeof("DESC")-1);
  qq = p;

  /* *** sort the namespaces */
  if (c->inc_ns)
    zx_add_inc_ns(c, &pop_seen);
  if (x->group)
    zx_add_xmlns_if_not_seen(c, x->group->g.ns, &pop_seen);
  zx_add_xmlns_if_not_seen(c, x->gg.g.ns, &pop_seen);

  p = zx_enc_seen(p, pop_seen); 
  p = zx_attr_wo_enc(p, x->group, "group=\"", sizeof("group=\"")-1);

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
  ENC_LEN_DEBUG(x, "cdm:DESC", p-enc_base);
  return p;
}

/* FUNC(zx_EASY_ENC_SO_cdm_DESC) */

/* Called by: */
struct zx_str* zx_EASY_ENC_SO_cdm_DESC(struct zx_ctx* c, struct zx_cdm_DESC_s* x )
{
  int len;
  char* buf;
  c->ns_tab = ZX_ALLOC(c, sizeof(zx_ns_tab));
  memcpy(c->ns_tab, zx_ns_tab, sizeof(zx_ns_tab));
  len = zx_LEN_SO_cdm_DESC(c, x );
  buf = ZX_ALLOC(c, len+1);
  return zx_easy_enc_common(c, zx_ENC_SO_cdm_DESC(c, x, buf ), buf, len);
}

/* FUNC(zx_EASY_ENC_WO_cdm_DESC) */

/* Called by: */
struct zx_str* zx_EASY_ENC_WO_cdm_DESC(struct zx_ctx* c, struct zx_cdm_DESC_s* x )
{
  int len;
  char* buf;
  c->ns_tab = ZX_ALLOC(c, sizeof(zx_ns_tab));
  memcpy(c->ns_tab, zx_ns_tab, sizeof(zx_ns_tab));
  len = zx_LEN_WO_cdm_DESC(c, x );
  buf = ZX_ALLOC(c, len+1);
  return zx_easy_enc_common(c, zx_ENC_WO_cdm_DESC(c, x, buf ), buf, len);
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

#define EL_NAME   cdm_EMAIL
#define EL_STRUCT zx_cdm_EMAIL_s
#define EL_NS     cdm
#define EL_TAG    EMAIL

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

/* FUNC(zx_LEN_SO_cdm_EMAIL) */

/* Compute length of an element (and its subelements). The XML attributes
 * and elements are processed in schema order. */

/* Called by: */
int zx_LEN_SO_cdm_EMAIL(struct zx_ctx* c, struct zx_cdm_EMAIL_s* x )
{
  struct zx_ns_s* pop_seen = 0;
  struct zx_elem_s* se MAYBE_UNUSED;
#if 1 /* NORMALMODE */
  /* *** in simple_elem case should output ns prefix from ns node. */
  int len = sizeof("<cdm:EMAIL")-1 + 1 + sizeof("</cdm:EMAIL>")-1;
  if (c->inc_ns_len)
    len += zx_len_inc_ns(c, &pop_seen);
  if (x->id || x->modificationTime)
    len += zx_len_xmlns_if_not_seen(c, zx_ns_tab+zx_xmlns_ix_cb, &pop_seen);
  len += zx_len_xmlns_if_not_seen(c, zx_ns_tab+zx_xmlns_ix_cdm, &pop_seen);

  len += zx_attr_so_len(x->id, sizeof("cb:id")-1);
  len += zx_attr_so_len(x->modificationTime, sizeof("cb:modificationTime")-1);

#else
  /* root node has no begin tag */
  int len = 0;
#endif
  
  for (se = x->HOME; se; se = (struct zx_elem_s*)se->g.n)
    len += zx_LEN_SO_simple_elem(c,se, sizeof("cdm:HOME")-1, zx_ns_tab+zx_xmlns_ix_cdm);
  for (se = x->WORK; se; se = (struct zx_elem_s*)se->g.n)
    len += zx_LEN_SO_simple_elem(c,se, sizeof("cdm:WORK")-1, zx_ns_tab+zx_xmlns_ix_cdm);
  for (se = x->INTERNET; se; se = (struct zx_elem_s*)se->g.n)
    len += zx_LEN_SO_simple_elem(c,se, sizeof("cdm:INTERNET")-1, zx_ns_tab+zx_xmlns_ix_cdm);
  for (se = x->PREF; se; se = (struct zx_elem_s*)se->g.n)
    len += zx_LEN_SO_simple_elem(c,se, sizeof("cdm:PREF")-1, zx_ns_tab+zx_xmlns_ix_cdm);
  for (se = x->X400; se; se = (struct zx_elem_s*)se->g.n)
    len += zx_LEN_SO_simple_elem(c,se, sizeof("cdm:X400")-1, zx_ns_tab+zx_xmlns_ix_cdm);
  {
      struct zx_cdm_USERID_s* e;
      for (e = x->USERID; e; e = (struct zx_cdm_USERID_s*)e->gg.g.n)
	  len += zx_LEN_SO_cdm_USERID(c, e);
  }


  len += zx_len_so_common(c, &x->gg);
  zx_pop_seen(pop_seen);
  ENC_LEN_DEBUG(x, "cdm:EMAIL", len);
  return len;
}

/* FUNC(zx_LEN_WO_cdm_EMAIL) */

/* Compute length of an element (and its subelements). The XML attributes
 * and elements are processed in wire order and no assumptions
 * are made about namespace prefixes. */

/* Called by: */
int zx_LEN_WO_cdm_EMAIL(struct zx_ctx* c, struct zx_cdm_EMAIL_s* x )
{
  struct zx_ns_s* pop_seen = 0;
  struct zx_elem_s* se MAYBE_UNUSED;
#if 1 /* NORMALMODE */
  int len = 1 + sizeof("EMAIL")-1 + 1 + 2 + sizeof("EMAIL")-1 + 1;
  
  if (x->gg.g.ns && x->gg.g.ns->prefix_len)
    len += (x->gg.g.ns->prefix_len + 1) * 2;
  if (c->inc_ns_len)
    len += zx_len_inc_ns(c, &pop_seen);
  if (x->id)
    len += zx_len_xmlns_if_not_seen(c, x->id->g.ns, &pop_seen);
  if (x->modificationTime)
    len += zx_len_xmlns_if_not_seen(c, x->modificationTime->g.ns, &pop_seen);
  len += zx_len_xmlns_if_not_seen(c, x->gg.g.ns, &pop_seen);

  len += zx_attr_wo_len(x->id, sizeof("id")-1);
  len += zx_attr_wo_len(x->modificationTime, sizeof("modificationTime")-1);

#else
  /* root node has no begin tag */
  int len = 0;
#endif
  
  for (se = x->HOME; se; se = (struct zx_elem_s*)se->g.n)
    len += zx_LEN_WO_simple_elem(c, se, sizeof("HOME")-1);
  for (se = x->WORK; se; se = (struct zx_elem_s*)se->g.n)
    len += zx_LEN_WO_simple_elem(c, se, sizeof("WORK")-1);
  for (se = x->INTERNET; se; se = (struct zx_elem_s*)se->g.n)
    len += zx_LEN_WO_simple_elem(c, se, sizeof("INTERNET")-1);
  for (se = x->PREF; se; se = (struct zx_elem_s*)se->g.n)
    len += zx_LEN_WO_simple_elem(c, se, sizeof("PREF")-1);
  for (se = x->X400; se; se = (struct zx_elem_s*)se->g.n)
    len += zx_LEN_WO_simple_elem(c, se, sizeof("X400")-1);
  {
      struct zx_cdm_USERID_s* e;
      for (e = x->USERID; e; e = (struct zx_cdm_USERID_s*)e->gg.g.n)
	  len += zx_LEN_WO_cdm_USERID(c, e);
  }


  len += zx_len_wo_common(c, &x->gg); 
  zx_pop_seen(pop_seen);
  ENC_LEN_DEBUG(x, "cdm:EMAIL", len);
  return len;
}

/* FUNC(zx_ENC_SO_cdm_EMAIL) */

/* Render element into string. The XML attributes and elements are
 * processed in schema order. This is what you generally want for
 * rendering new data structure to a string. The wo pointers are not used. */

/* Called by: */
char* zx_ENC_SO_cdm_EMAIL(struct zx_ctx* c, struct zx_cdm_EMAIL_s* x, char* p )
{
  struct zx_elem_s* se MAYBE_UNUSED;
  struct zx_ns_s* pop_seen = 0;
  ENC_LEN_DEBUG_BASE;
#if 1 /* NORMALMODE */
  /* *** in simple_elem case should output ns prefix from ns node. */
  ZX_OUT_TAG(p, "<cdm:EMAIL");
  if (c->inc_ns)
    p = zx_enc_inc_ns(c, p, &pop_seen);
  if (x->id || x->modificationTime)
    p = zx_enc_xmlns_if_not_seen(c, p, zx_ns_tab+zx_xmlns_ix_cb, &pop_seen);
  p = zx_enc_xmlns_if_not_seen(c, p, zx_ns_tab+zx_xmlns_ix_cdm, &pop_seen);

  p = zx_attr_so_enc(p, x->id, " cb:id=\"", sizeof(" cb:id=\"")-1);
  p = zx_attr_so_enc(p, x->modificationTime, " cb:modificationTime=\"", sizeof(" cb:modificationTime=\"")-1);

  p = zx_enc_unknown_attrs(p, x->gg.any_attr);
#else
  /* root node has no begin tag */
#endif
  
  for (se = x->HOME; se; se = (struct zx_elem_s*)se->g.n)
    p = zx_ENC_SO_simple_elem(c, se, p, "cdm:HOME", sizeof("cdm:HOME")-1, zx_ns_tab+zx_xmlns_ix_cdm);
  for (se = x->WORK; se; se = (struct zx_elem_s*)se->g.n)
    p = zx_ENC_SO_simple_elem(c, se, p, "cdm:WORK", sizeof("cdm:WORK")-1, zx_ns_tab+zx_xmlns_ix_cdm);
  for (se = x->INTERNET; se; se = (struct zx_elem_s*)se->g.n)
    p = zx_ENC_SO_simple_elem(c, se, p, "cdm:INTERNET", sizeof("cdm:INTERNET")-1, zx_ns_tab+zx_xmlns_ix_cdm);
  for (se = x->PREF; se; se = (struct zx_elem_s*)se->g.n)
    p = zx_ENC_SO_simple_elem(c, se, p, "cdm:PREF", sizeof("cdm:PREF")-1, zx_ns_tab+zx_xmlns_ix_cdm);
  for (se = x->X400; se; se = (struct zx_elem_s*)se->g.n)
    p = zx_ENC_SO_simple_elem(c, se, p, "cdm:X400", sizeof("cdm:X400")-1, zx_ns_tab+zx_xmlns_ix_cdm);
  {
      struct zx_cdm_USERID_s* e;
      for (e = x->USERID; e; e = (struct zx_cdm_USERID_s*)e->gg.g.n)
	  p = zx_ENC_SO_cdm_USERID(c, e, p);
  }

  p = zx_enc_so_unknown_elems_and_content(c, p, &x->gg);
  
#if 1 /* NORMALMODE */
  ZX_OUT_CLOSE_TAG(p, "</cdm:EMAIL>");
  zx_pop_seen(pop_seen);
#else
  /* root node has no end tag either */
#endif
  ENC_LEN_DEBUG(x, "cdm:EMAIL", p-enc_base);
  return p;
}

/* FUNC(zx_ENC_WO_cdm_EMAIL) */

/* Render element into string. The XML attributes and elements are
 * processed in wire order by chasing wo pointers. This is what you want for
 * validating signatures on other people's XML documents. */

/* Called by: */
char* zx_ENC_WO_cdm_EMAIL(struct zx_ctx* c, struct zx_cdm_EMAIL_s* x, char* p )
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
  ZX_OUT_MEM(p, "EMAIL", sizeof("EMAIL")-1);
  qq = p;

  /* *** sort the namespaces */
  if (c->inc_ns)
    zx_add_inc_ns(c, &pop_seen);
  if (x->id)
    zx_add_xmlns_if_not_seen(c, x->id->g.ns, &pop_seen);
  if (x->modificationTime)
    zx_add_xmlns_if_not_seen(c, x->modificationTime->g.ns, &pop_seen);
  zx_add_xmlns_if_not_seen(c, x->gg.g.ns, &pop_seen);

  p = zx_enc_seen(p, pop_seen); 
  p = zx_attr_wo_enc(p, x->id, "id=\"", sizeof("id=\"")-1);
  p = zx_attr_wo_enc(p, x->modificationTime, "modificationTime=\"", sizeof("modificationTime=\"")-1);

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
  ENC_LEN_DEBUG(x, "cdm:EMAIL", p-enc_base);
  return p;
}

/* FUNC(zx_EASY_ENC_SO_cdm_EMAIL) */

/* Called by: */
struct zx_str* zx_EASY_ENC_SO_cdm_EMAIL(struct zx_ctx* c, struct zx_cdm_EMAIL_s* x )
{
  int len;
  char* buf;
  c->ns_tab = ZX_ALLOC(c, sizeof(zx_ns_tab));
  memcpy(c->ns_tab, zx_ns_tab, sizeof(zx_ns_tab));
  len = zx_LEN_SO_cdm_EMAIL(c, x );
  buf = ZX_ALLOC(c, len+1);
  return zx_easy_enc_common(c, zx_ENC_SO_cdm_EMAIL(c, x, buf ), buf, len);
}

/* FUNC(zx_EASY_ENC_WO_cdm_EMAIL) */

/* Called by: */
struct zx_str* zx_EASY_ENC_WO_cdm_EMAIL(struct zx_ctx* c, struct zx_cdm_EMAIL_s* x )
{
  int len;
  char* buf;
  c->ns_tab = ZX_ALLOC(c, sizeof(zx_ns_tab));
  memcpy(c->ns_tab, zx_ns_tab, sizeof(zx_ns_tab));
  len = zx_LEN_WO_cdm_EMAIL(c, x );
  buf = ZX_ALLOC(c, len+1);
  return zx_easy_enc_common(c, zx_ENC_WO_cdm_EMAIL(c, x, buf ), buf, len);
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

#define EL_NAME   cdm_EXTADR
#define EL_STRUCT zx_cdm_EXTADR_s
#define EL_NS     cdm
#define EL_TAG    EXTADR

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

/* FUNC(zx_LEN_SO_cdm_EXTADR) */

/* Compute length of an element (and its subelements). The XML attributes
 * and elements are processed in schema order. */

/* Called by: */
int zx_LEN_SO_cdm_EXTADR(struct zx_ctx* c, struct zx_cdm_EXTADR_s* x )
{
  struct zx_ns_s* pop_seen = 0;
  struct zx_elem_s* se MAYBE_UNUSED;
#if 1 /* NORMALMODE */
  /* *** in simple_elem case should output ns prefix from ns node. */
  int len = sizeof("<cdm:EXTADR")-1 + 1 + sizeof("</cdm:EXTADR>")-1;
  if (c->inc_ns_len)
    len += zx_len_inc_ns(c, &pop_seen);
  if (x->group)
    len += zx_len_xmlns_if_not_seen(c, zx_ns_tab+zx_xmlns_ix_cb, &pop_seen);
  len += zx_len_xmlns_if_not_seen(c, zx_ns_tab+zx_xmlns_ix_cdm, &pop_seen);

  len += zx_attr_so_len(x->group, sizeof("cb:group")-1);

#else
  /* root node has no begin tag */
  int len = 0;
#endif
  


  len += zx_len_so_common(c, &x->gg);
  zx_pop_seen(pop_seen);
  ENC_LEN_DEBUG(x, "cdm:EXTADR", len);
  return len;
}

/* FUNC(zx_LEN_WO_cdm_EXTADR) */

/* Compute length of an element (and its subelements). The XML attributes
 * and elements are processed in wire order and no assumptions
 * are made about namespace prefixes. */

/* Called by: */
int zx_LEN_WO_cdm_EXTADR(struct zx_ctx* c, struct zx_cdm_EXTADR_s* x )
{
  struct zx_ns_s* pop_seen = 0;
  struct zx_elem_s* se MAYBE_UNUSED;
#if 1 /* NORMALMODE */
  int len = 1 + sizeof("EXTADR")-1 + 1 + 2 + sizeof("EXTADR")-1 + 1;
  
  if (x->gg.g.ns && x->gg.g.ns->prefix_len)
    len += (x->gg.g.ns->prefix_len + 1) * 2;
  if (c->inc_ns_len)
    len += zx_len_inc_ns(c, &pop_seen);
  if (x->group)
    len += zx_len_xmlns_if_not_seen(c, x->group->g.ns, &pop_seen);
  len += zx_len_xmlns_if_not_seen(c, x->gg.g.ns, &pop_seen);

  len += zx_attr_wo_len(x->group, sizeof("group")-1);

#else
  /* root node has no begin tag */
  int len = 0;
#endif
  


  len += zx_len_wo_common(c, &x->gg); 
  zx_pop_seen(pop_seen);
  ENC_LEN_DEBUG(x, "cdm:EXTADR", len);
  return len;
}

/* FUNC(zx_ENC_SO_cdm_EXTADR) */

/* Render element into string. The XML attributes and elements are
 * processed in schema order. This is what you generally want for
 * rendering new data structure to a string. The wo pointers are not used. */

/* Called by: */
char* zx_ENC_SO_cdm_EXTADR(struct zx_ctx* c, struct zx_cdm_EXTADR_s* x, char* p )
{
  struct zx_elem_s* se MAYBE_UNUSED;
  struct zx_ns_s* pop_seen = 0;
  ENC_LEN_DEBUG_BASE;
#if 1 /* NORMALMODE */
  /* *** in simple_elem case should output ns prefix from ns node. */
  ZX_OUT_TAG(p, "<cdm:EXTADR");
  if (c->inc_ns)
    p = zx_enc_inc_ns(c, p, &pop_seen);
  if (x->group)
    p = zx_enc_xmlns_if_not_seen(c, p, zx_ns_tab+zx_xmlns_ix_cb, &pop_seen);
  p = zx_enc_xmlns_if_not_seen(c, p, zx_ns_tab+zx_xmlns_ix_cdm, &pop_seen);

  p = zx_attr_so_enc(p, x->group, " cb:group=\"", sizeof(" cb:group=\"")-1);

  p = zx_enc_unknown_attrs(p, x->gg.any_attr);
#else
  /* root node has no begin tag */
#endif
  

  p = zx_enc_so_unknown_elems_and_content(c, p, &x->gg);
  
#if 1 /* NORMALMODE */
  ZX_OUT_CLOSE_TAG(p, "</cdm:EXTADR>");
  zx_pop_seen(pop_seen);
#else
  /* root node has no end tag either */
#endif
  ENC_LEN_DEBUG(x, "cdm:EXTADR", p-enc_base);
  return p;
}

/* FUNC(zx_ENC_WO_cdm_EXTADR) */

/* Render element into string. The XML attributes and elements are
 * processed in wire order by chasing wo pointers. This is what you want for
 * validating signatures on other people's XML documents. */

/* Called by: */
char* zx_ENC_WO_cdm_EXTADR(struct zx_ctx* c, struct zx_cdm_EXTADR_s* x, char* p )
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
  ZX_OUT_MEM(p, "EXTADR", sizeof("EXTADR")-1);
  qq = p;

  /* *** sort the namespaces */
  if (c->inc_ns)
    zx_add_inc_ns(c, &pop_seen);
  if (x->group)
    zx_add_xmlns_if_not_seen(c, x->group->g.ns, &pop_seen);
  zx_add_xmlns_if_not_seen(c, x->gg.g.ns, &pop_seen);

  p = zx_enc_seen(p, pop_seen); 
  p = zx_attr_wo_enc(p, x->group, "group=\"", sizeof("group=\"")-1);

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
  ENC_LEN_DEBUG(x, "cdm:EXTADR", p-enc_base);
  return p;
}

/* FUNC(zx_EASY_ENC_SO_cdm_EXTADR) */

/* Called by: */
struct zx_str* zx_EASY_ENC_SO_cdm_EXTADR(struct zx_ctx* c, struct zx_cdm_EXTADR_s* x )
{
  int len;
  char* buf;
  c->ns_tab = ZX_ALLOC(c, sizeof(zx_ns_tab));
  memcpy(c->ns_tab, zx_ns_tab, sizeof(zx_ns_tab));
  len = zx_LEN_SO_cdm_EXTADR(c, x );
  buf = ZX_ALLOC(c, len+1);
  return zx_easy_enc_common(c, zx_ENC_SO_cdm_EXTADR(c, x, buf ), buf, len);
}

/* FUNC(zx_EASY_ENC_WO_cdm_EXTADR) */

/* Called by: */
struct zx_str* zx_EASY_ENC_WO_cdm_EXTADR(struct zx_ctx* c, struct zx_cdm_EXTADR_s* x )
{
  int len;
  char* buf;
  c->ns_tab = ZX_ALLOC(c, sizeof(zx_ns_tab));
  memcpy(c->ns_tab, zx_ns_tab, sizeof(zx_ns_tab));
  len = zx_LEN_WO_cdm_EXTADR(c, x );
  buf = ZX_ALLOC(c, len+1);
  return zx_easy_enc_common(c, zx_ENC_WO_cdm_EXTADR(c, x, buf ), buf, len);
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

#define EL_NAME   cdm_EXTVAL
#define EL_STRUCT zx_cdm_EXTVAL_s
#define EL_NS     cdm
#define EL_TAG    EXTVAL

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

/* FUNC(zx_LEN_SO_cdm_EXTVAL) */

/* Compute length of an element (and its subelements). The XML attributes
 * and elements are processed in schema order. */

/* Called by: */
int zx_LEN_SO_cdm_EXTVAL(struct zx_ctx* c, struct zx_cdm_EXTVAL_s* x )
{
  struct zx_ns_s* pop_seen = 0;
  struct zx_elem_s* se MAYBE_UNUSED;
#if 1 /* NORMALMODE */
  /* *** in simple_elem case should output ns prefix from ns node. */
  int len = sizeof("<cdm:EXTVAL")-1 + 1 + sizeof("</cdm:EXTVAL>")-1;
  if (c->inc_ns_len)
    len += zx_len_inc_ns(c, &pop_seen);
  if (x->ACC || x->ACCTime || x->id || x->modificationTime || x->modifier)
    len += zx_len_xmlns_if_not_seen(c, zx_ns_tab+zx_xmlns_ix_cb, &pop_seen);
  len += zx_len_xmlns_if_not_seen(c, zx_ns_tab+zx_xmlns_ix_cdm, &pop_seen);

  len += zx_attr_so_len(x->ACC, sizeof("cb:ACC")-1);
  len += zx_attr_so_len(x->ACCTime, sizeof("cb:ACCTime")-1);
  len += zx_attr_so_len(x->id, sizeof("cb:id")-1);
  len += zx_attr_so_len(x->modificationTime, sizeof("cb:modificationTime")-1);
  len += zx_attr_so_len(x->modifier, sizeof("cb:modifier")-1);

#else
  /* root node has no begin tag */
  int len = 0;
#endif
  


  len += zx_len_so_common(c, &x->gg);
  zx_pop_seen(pop_seen);
  ENC_LEN_DEBUG(x, "cdm:EXTVAL", len);
  return len;
}

/* FUNC(zx_LEN_WO_cdm_EXTVAL) */

/* Compute length of an element (and its subelements). The XML attributes
 * and elements are processed in wire order and no assumptions
 * are made about namespace prefixes. */

/* Called by: */
int zx_LEN_WO_cdm_EXTVAL(struct zx_ctx* c, struct zx_cdm_EXTVAL_s* x )
{
  struct zx_ns_s* pop_seen = 0;
  struct zx_elem_s* se MAYBE_UNUSED;
#if 1 /* NORMALMODE */
  int len = 1 + sizeof("EXTVAL")-1 + 1 + 2 + sizeof("EXTVAL")-1 + 1;
  
  if (x->gg.g.ns && x->gg.g.ns->prefix_len)
    len += (x->gg.g.ns->prefix_len + 1) * 2;
  if (c->inc_ns_len)
    len += zx_len_inc_ns(c, &pop_seen);
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
  len += zx_len_xmlns_if_not_seen(c, x->gg.g.ns, &pop_seen);

  len += zx_attr_wo_len(x->ACC, sizeof("ACC")-1);
  len += zx_attr_wo_len(x->ACCTime, sizeof("ACCTime")-1);
  len += zx_attr_wo_len(x->id, sizeof("id")-1);
  len += zx_attr_wo_len(x->modificationTime, sizeof("modificationTime")-1);
  len += zx_attr_wo_len(x->modifier, sizeof("modifier")-1);

#else
  /* root node has no begin tag */
  int len = 0;
#endif
  


  len += zx_len_wo_common(c, &x->gg); 
  zx_pop_seen(pop_seen);
  ENC_LEN_DEBUG(x, "cdm:EXTVAL", len);
  return len;
}

/* FUNC(zx_ENC_SO_cdm_EXTVAL) */

/* Render element into string. The XML attributes and elements are
 * processed in schema order. This is what you generally want for
 * rendering new data structure to a string. The wo pointers are not used. */

/* Called by: */
char* zx_ENC_SO_cdm_EXTVAL(struct zx_ctx* c, struct zx_cdm_EXTVAL_s* x, char* p )
{
  struct zx_elem_s* se MAYBE_UNUSED;
  struct zx_ns_s* pop_seen = 0;
  ENC_LEN_DEBUG_BASE;
#if 1 /* NORMALMODE */
  /* *** in simple_elem case should output ns prefix from ns node. */
  ZX_OUT_TAG(p, "<cdm:EXTVAL");
  if (c->inc_ns)
    p = zx_enc_inc_ns(c, p, &pop_seen);
  if (x->ACC || x->ACCTime || x->id || x->modificationTime || x->modifier)
    p = zx_enc_xmlns_if_not_seen(c, p, zx_ns_tab+zx_xmlns_ix_cb, &pop_seen);
  p = zx_enc_xmlns_if_not_seen(c, p, zx_ns_tab+zx_xmlns_ix_cdm, &pop_seen);

  p = zx_attr_so_enc(p, x->ACC, " cb:ACC=\"", sizeof(" cb:ACC=\"")-1);
  p = zx_attr_so_enc(p, x->ACCTime, " cb:ACCTime=\"", sizeof(" cb:ACCTime=\"")-1);
  p = zx_attr_so_enc(p, x->id, " cb:id=\"", sizeof(" cb:id=\"")-1);
  p = zx_attr_so_enc(p, x->modificationTime, " cb:modificationTime=\"", sizeof(" cb:modificationTime=\"")-1);
  p = zx_attr_so_enc(p, x->modifier, " cb:modifier=\"", sizeof(" cb:modifier=\"")-1);

  p = zx_enc_unknown_attrs(p, x->gg.any_attr);
#else
  /* root node has no begin tag */
#endif
  

  p = zx_enc_so_unknown_elems_and_content(c, p, &x->gg);
  
#if 1 /* NORMALMODE */
  ZX_OUT_CLOSE_TAG(p, "</cdm:EXTVAL>");
  zx_pop_seen(pop_seen);
#else
  /* root node has no end tag either */
#endif
  ENC_LEN_DEBUG(x, "cdm:EXTVAL", p-enc_base);
  return p;
}

/* FUNC(zx_ENC_WO_cdm_EXTVAL) */

/* Render element into string. The XML attributes and elements are
 * processed in wire order by chasing wo pointers. This is what you want for
 * validating signatures on other people's XML documents. */

/* Called by: */
char* zx_ENC_WO_cdm_EXTVAL(struct zx_ctx* c, struct zx_cdm_EXTVAL_s* x, char* p )
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
  ZX_OUT_MEM(p, "EXTVAL", sizeof("EXTVAL")-1);
  qq = p;

  /* *** sort the namespaces */
  if (c->inc_ns)
    zx_add_inc_ns(c, &pop_seen);
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
  zx_add_xmlns_if_not_seen(c, x->gg.g.ns, &pop_seen);

  p = zx_enc_seen(p, pop_seen); 
  p = zx_attr_wo_enc(p, x->ACC, "ACC=\"", sizeof("ACC=\"")-1);
  p = zx_attr_wo_enc(p, x->ACCTime, "ACCTime=\"", sizeof("ACCTime=\"")-1);
  p = zx_attr_wo_enc(p, x->id, "id=\"", sizeof("id=\"")-1);
  p = zx_attr_wo_enc(p, x->modificationTime, "modificationTime=\"", sizeof("modificationTime=\"")-1);
  p = zx_attr_wo_enc(p, x->modifier, "modifier=\"", sizeof("modifier=\"")-1);

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
  ENC_LEN_DEBUG(x, "cdm:EXTVAL", p-enc_base);
  return p;
}

/* FUNC(zx_EASY_ENC_SO_cdm_EXTVAL) */

/* Called by: */
struct zx_str* zx_EASY_ENC_SO_cdm_EXTVAL(struct zx_ctx* c, struct zx_cdm_EXTVAL_s* x )
{
  int len;
  char* buf;
  c->ns_tab = ZX_ALLOC(c, sizeof(zx_ns_tab));
  memcpy(c->ns_tab, zx_ns_tab, sizeof(zx_ns_tab));
  len = zx_LEN_SO_cdm_EXTVAL(c, x );
  buf = ZX_ALLOC(c, len+1);
  return zx_easy_enc_common(c, zx_ENC_SO_cdm_EXTVAL(c, x, buf ), buf, len);
}

/* FUNC(zx_EASY_ENC_WO_cdm_EXTVAL) */

/* Called by: */
struct zx_str* zx_EASY_ENC_WO_cdm_EXTVAL(struct zx_ctx* c, struct zx_cdm_EXTVAL_s* x )
{
  int len;
  char* buf;
  c->ns_tab = ZX_ALLOC(c, sizeof(zx_ns_tab));
  memcpy(c->ns_tab, zx_ns_tab, sizeof(zx_ns_tab));
  len = zx_LEN_WO_cdm_EXTVAL(c, x );
  buf = ZX_ALLOC(c, len+1);
  return zx_easy_enc_common(c, zx_ENC_WO_cdm_EXTVAL(c, x, buf ), buf, len);
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

#define EL_NAME   cdm_FAMILY
#define EL_STRUCT zx_cdm_FAMILY_s
#define EL_NS     cdm
#define EL_TAG    FAMILY

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

/* FUNC(zx_LEN_SO_cdm_FAMILY) */

/* Compute length of an element (and its subelements). The XML attributes
 * and elements are processed in schema order. */

/* Called by: */
int zx_LEN_SO_cdm_FAMILY(struct zx_ctx* c, struct zx_cdm_FAMILY_s* x )
{
  struct zx_ns_s* pop_seen = 0;
  struct zx_elem_s* se MAYBE_UNUSED;
#if 1 /* NORMALMODE */
  /* *** in simple_elem case should output ns prefix from ns node. */
  int len = sizeof("<cdm:FAMILY")-1 + 1 + sizeof("</cdm:FAMILY>")-1;
  if (c->inc_ns_len)
    len += zx_len_inc_ns(c, &pop_seen);
  if (x->group)
    len += zx_len_xmlns_if_not_seen(c, zx_ns_tab+zx_xmlns_ix_cb, &pop_seen);
  len += zx_len_xmlns_if_not_seen(c, zx_ns_tab+zx_xmlns_ix_cdm, &pop_seen);

  len += zx_attr_so_len(x->group, sizeof("cb:group")-1);

#else
  /* root node has no begin tag */
  int len = 0;
#endif
  


  len += zx_len_so_common(c, &x->gg);
  zx_pop_seen(pop_seen);
  ENC_LEN_DEBUG(x, "cdm:FAMILY", len);
  return len;
}

/* FUNC(zx_LEN_WO_cdm_FAMILY) */

/* Compute length of an element (and its subelements). The XML attributes
 * and elements are processed in wire order and no assumptions
 * are made about namespace prefixes. */

/* Called by: */
int zx_LEN_WO_cdm_FAMILY(struct zx_ctx* c, struct zx_cdm_FAMILY_s* x )
{
  struct zx_ns_s* pop_seen = 0;
  struct zx_elem_s* se MAYBE_UNUSED;
#if 1 /* NORMALMODE */
  int len = 1 + sizeof("FAMILY")-1 + 1 + 2 + sizeof("FAMILY")-1 + 1;
  
  if (x->gg.g.ns && x->gg.g.ns->prefix_len)
    len += (x->gg.g.ns->prefix_len + 1) * 2;
  if (c->inc_ns_len)
    len += zx_len_inc_ns(c, &pop_seen);
  if (x->group)
    len += zx_len_xmlns_if_not_seen(c, x->group->g.ns, &pop_seen);
  len += zx_len_xmlns_if_not_seen(c, x->gg.g.ns, &pop_seen);

  len += zx_attr_wo_len(x->group, sizeof("group")-1);

#else
  /* root node has no begin tag */
  int len = 0;
#endif
  


  len += zx_len_wo_common(c, &x->gg); 
  zx_pop_seen(pop_seen);
  ENC_LEN_DEBUG(x, "cdm:FAMILY", len);
  return len;
}

/* FUNC(zx_ENC_SO_cdm_FAMILY) */

/* Render element into string. The XML attributes and elements are
 * processed in schema order. This is what you generally want for
 * rendering new data structure to a string. The wo pointers are not used. */

/* Called by: */
char* zx_ENC_SO_cdm_FAMILY(struct zx_ctx* c, struct zx_cdm_FAMILY_s* x, char* p )
{
  struct zx_elem_s* se MAYBE_UNUSED;
  struct zx_ns_s* pop_seen = 0;
  ENC_LEN_DEBUG_BASE;
#if 1 /* NORMALMODE */
  /* *** in simple_elem case should output ns prefix from ns node. */
  ZX_OUT_TAG(p, "<cdm:FAMILY");
  if (c->inc_ns)
    p = zx_enc_inc_ns(c, p, &pop_seen);
  if (x->group)
    p = zx_enc_xmlns_if_not_seen(c, p, zx_ns_tab+zx_xmlns_ix_cb, &pop_seen);
  p = zx_enc_xmlns_if_not_seen(c, p, zx_ns_tab+zx_xmlns_ix_cdm, &pop_seen);

  p = zx_attr_so_enc(p, x->group, " cb:group=\"", sizeof(" cb:group=\"")-1);

  p = zx_enc_unknown_attrs(p, x->gg.any_attr);
#else
  /* root node has no begin tag */
#endif
  

  p = zx_enc_so_unknown_elems_and_content(c, p, &x->gg);
  
#if 1 /* NORMALMODE */
  ZX_OUT_CLOSE_TAG(p, "</cdm:FAMILY>");
  zx_pop_seen(pop_seen);
#else
  /* root node has no end tag either */
#endif
  ENC_LEN_DEBUG(x, "cdm:FAMILY", p-enc_base);
  return p;
}

/* FUNC(zx_ENC_WO_cdm_FAMILY) */

/* Render element into string. The XML attributes and elements are
 * processed in wire order by chasing wo pointers. This is what you want for
 * validating signatures on other people's XML documents. */

/* Called by: */
char* zx_ENC_WO_cdm_FAMILY(struct zx_ctx* c, struct zx_cdm_FAMILY_s* x, char* p )
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
  ZX_OUT_MEM(p, "FAMILY", sizeof("FAMILY")-1);
  qq = p;

  /* *** sort the namespaces */
  if (c->inc_ns)
    zx_add_inc_ns(c, &pop_seen);
  if (x->group)
    zx_add_xmlns_if_not_seen(c, x->group->g.ns, &pop_seen);
  zx_add_xmlns_if_not_seen(c, x->gg.g.ns, &pop_seen);

  p = zx_enc_seen(p, pop_seen); 
  p = zx_attr_wo_enc(p, x->group, "group=\"", sizeof("group=\"")-1);

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
  ENC_LEN_DEBUG(x, "cdm:FAMILY", p-enc_base);
  return p;
}

/* FUNC(zx_EASY_ENC_SO_cdm_FAMILY) */

/* Called by: */
struct zx_str* zx_EASY_ENC_SO_cdm_FAMILY(struct zx_ctx* c, struct zx_cdm_FAMILY_s* x )
{
  int len;
  char* buf;
  c->ns_tab = ZX_ALLOC(c, sizeof(zx_ns_tab));
  memcpy(c->ns_tab, zx_ns_tab, sizeof(zx_ns_tab));
  len = zx_LEN_SO_cdm_FAMILY(c, x );
  buf = ZX_ALLOC(c, len+1);
  return zx_easy_enc_common(c, zx_ENC_SO_cdm_FAMILY(c, x, buf ), buf, len);
}

/* FUNC(zx_EASY_ENC_WO_cdm_FAMILY) */

/* Called by: */
struct zx_str* zx_EASY_ENC_WO_cdm_FAMILY(struct zx_ctx* c, struct zx_cdm_FAMILY_s* x )
{
  int len;
  char* buf;
  c->ns_tab = ZX_ALLOC(c, sizeof(zx_ns_tab));
  memcpy(c->ns_tab, zx_ns_tab, sizeof(zx_ns_tab));
  len = zx_LEN_WO_cdm_FAMILY(c, x );
  buf = ZX_ALLOC(c, len+1);
  return zx_easy_enc_common(c, zx_ENC_WO_cdm_FAMILY(c, x, buf ), buf, len);
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

#define EL_NAME   cdm_FBURL
#define EL_STRUCT zx_cdm_FBURL_s
#define EL_NS     cdm
#define EL_TAG    FBURL

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

/* FUNC(zx_LEN_SO_cdm_FBURL) */

/* Compute length of an element (and its subelements). The XML attributes
 * and elements are processed in schema order. */

/* Called by: */
int zx_LEN_SO_cdm_FBURL(struct zx_ctx* c, struct zx_cdm_FBURL_s* x )
{
  struct zx_ns_s* pop_seen = 0;
  struct zx_elem_s* se MAYBE_UNUSED;
#if 1 /* NORMALMODE */
  /* *** in simple_elem case should output ns prefix from ns node. */
  int len = sizeof("<cdm:FBURL")-1 + 1 + sizeof("</cdm:FBURL>")-1;
  if (c->inc_ns_len)
    len += zx_len_inc_ns(c, &pop_seen);
  if (x->ACC || x->ACCTime || x->id || x->modificationTime || x->modifier)
    len += zx_len_xmlns_if_not_seen(c, zx_ns_tab+zx_xmlns_ix_cb, &pop_seen);
  len += zx_len_xmlns_if_not_seen(c, zx_ns_tab+zx_xmlns_ix_cdm, &pop_seen);

  len += zx_attr_so_len(x->ACC, sizeof("cb:ACC")-1);
  len += zx_attr_so_len(x->ACCTime, sizeof("cb:ACCTime")-1);
  len += zx_attr_so_len(x->id, sizeof("cb:id")-1);
  len += zx_attr_so_len(x->modificationTime, sizeof("cb:modificationTime")-1);
  len += zx_attr_so_len(x->modifier, sizeof("cb:modifier")-1);

#else
  /* root node has no begin tag */
  int len = 0;
#endif
  
  for (se = x->PREF; se; se = (struct zx_elem_s*)se->g.n)
    len += zx_LEN_SO_simple_elem(c,se, sizeof("cdm:PREF")-1, zx_ns_tab+zx_xmlns_ix_cdm);
  {
      struct zx_cdm_URI_s* e;
      for (e = x->URI; e; e = (struct zx_cdm_URI_s*)e->gg.g.n)
	  len += zx_LEN_SO_cdm_URI(c, e);
  }


  len += zx_len_so_common(c, &x->gg);
  zx_pop_seen(pop_seen);
  ENC_LEN_DEBUG(x, "cdm:FBURL", len);
  return len;
}

/* FUNC(zx_LEN_WO_cdm_FBURL) */

/* Compute length of an element (and its subelements). The XML attributes
 * and elements are processed in wire order and no assumptions
 * are made about namespace prefixes. */

/* Called by: */
int zx_LEN_WO_cdm_FBURL(struct zx_ctx* c, struct zx_cdm_FBURL_s* x )
{
  struct zx_ns_s* pop_seen = 0;
  struct zx_elem_s* se MAYBE_UNUSED;
#if 1 /* NORMALMODE */
  int len = 1 + sizeof("FBURL")-1 + 1 + 2 + sizeof("FBURL")-1 + 1;
  
  if (x->gg.g.ns && x->gg.g.ns->prefix_len)
    len += (x->gg.g.ns->prefix_len + 1) * 2;
  if (c->inc_ns_len)
    len += zx_len_inc_ns(c, &pop_seen);
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
  len += zx_len_xmlns_if_not_seen(c, x->gg.g.ns, &pop_seen);

  len += zx_attr_wo_len(x->ACC, sizeof("ACC")-1);
  len += zx_attr_wo_len(x->ACCTime, sizeof("ACCTime")-1);
  len += zx_attr_wo_len(x->id, sizeof("id")-1);
  len += zx_attr_wo_len(x->modificationTime, sizeof("modificationTime")-1);
  len += zx_attr_wo_len(x->modifier, sizeof("modifier")-1);

#else
  /* root node has no begin tag */
  int len = 0;
#endif
  
  for (se = x->PREF; se; se = (struct zx_elem_s*)se->g.n)
    len += zx_LEN_WO_simple_elem(c, se, sizeof("PREF")-1);
  {
      struct zx_cdm_URI_s* e;
      for (e = x->URI; e; e = (struct zx_cdm_URI_s*)e->gg.g.n)
	  len += zx_LEN_WO_cdm_URI(c, e);
  }


  len += zx_len_wo_common(c, &x->gg); 
  zx_pop_seen(pop_seen);
  ENC_LEN_DEBUG(x, "cdm:FBURL", len);
  return len;
}

/* FUNC(zx_ENC_SO_cdm_FBURL) */

/* Render element into string. The XML attributes and elements are
 * processed in schema order. This is what you generally want for
 * rendering new data structure to a string. The wo pointers are not used. */

/* Called by: */
char* zx_ENC_SO_cdm_FBURL(struct zx_ctx* c, struct zx_cdm_FBURL_s* x, char* p )
{
  struct zx_elem_s* se MAYBE_UNUSED;
  struct zx_ns_s* pop_seen = 0;
  ENC_LEN_DEBUG_BASE;
#if 1 /* NORMALMODE */
  /* *** in simple_elem case should output ns prefix from ns node. */
  ZX_OUT_TAG(p, "<cdm:FBURL");
  if (c->inc_ns)
    p = zx_enc_inc_ns(c, p, &pop_seen);
  if (x->ACC || x->ACCTime || x->id || x->modificationTime || x->modifier)
    p = zx_enc_xmlns_if_not_seen(c, p, zx_ns_tab+zx_xmlns_ix_cb, &pop_seen);
  p = zx_enc_xmlns_if_not_seen(c, p, zx_ns_tab+zx_xmlns_ix_cdm, &pop_seen);

  p = zx_attr_so_enc(p, x->ACC, " cb:ACC=\"", sizeof(" cb:ACC=\"")-1);
  p = zx_attr_so_enc(p, x->ACCTime, " cb:ACCTime=\"", sizeof(" cb:ACCTime=\"")-1);
  p = zx_attr_so_enc(p, x->id, " cb:id=\"", sizeof(" cb:id=\"")-1);
  p = zx_attr_so_enc(p, x->modificationTime, " cb:modificationTime=\"", sizeof(" cb:modificationTime=\"")-1);
  p = zx_attr_so_enc(p, x->modifier, " cb:modifier=\"", sizeof(" cb:modifier=\"")-1);

  p = zx_enc_unknown_attrs(p, x->gg.any_attr);
#else
  /* root node has no begin tag */
#endif
  
  for (se = x->PREF; se; se = (struct zx_elem_s*)se->g.n)
    p = zx_ENC_SO_simple_elem(c, se, p, "cdm:PREF", sizeof("cdm:PREF")-1, zx_ns_tab+zx_xmlns_ix_cdm);
  {
      struct zx_cdm_URI_s* e;
      for (e = x->URI; e; e = (struct zx_cdm_URI_s*)e->gg.g.n)
	  p = zx_ENC_SO_cdm_URI(c, e, p);
  }

  p = zx_enc_so_unknown_elems_and_content(c, p, &x->gg);
  
#if 1 /* NORMALMODE */
  ZX_OUT_CLOSE_TAG(p, "</cdm:FBURL>");
  zx_pop_seen(pop_seen);
#else
  /* root node has no end tag either */
#endif
  ENC_LEN_DEBUG(x, "cdm:FBURL", p-enc_base);
  return p;
}

/* FUNC(zx_ENC_WO_cdm_FBURL) */

/* Render element into string. The XML attributes and elements are
 * processed in wire order by chasing wo pointers. This is what you want for
 * validating signatures on other people's XML documents. */

/* Called by: */
char* zx_ENC_WO_cdm_FBURL(struct zx_ctx* c, struct zx_cdm_FBURL_s* x, char* p )
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
  ZX_OUT_MEM(p, "FBURL", sizeof("FBURL")-1);
  qq = p;

  /* *** sort the namespaces */
  if (c->inc_ns)
    zx_add_inc_ns(c, &pop_seen);
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
  zx_add_xmlns_if_not_seen(c, x->gg.g.ns, &pop_seen);

  p = zx_enc_seen(p, pop_seen); 
  p = zx_attr_wo_enc(p, x->ACC, "ACC=\"", sizeof("ACC=\"")-1);
  p = zx_attr_wo_enc(p, x->ACCTime, "ACCTime=\"", sizeof("ACCTime=\"")-1);
  p = zx_attr_wo_enc(p, x->id, "id=\"", sizeof("id=\"")-1);
  p = zx_attr_wo_enc(p, x->modificationTime, "modificationTime=\"", sizeof("modificationTime=\"")-1);
  p = zx_attr_wo_enc(p, x->modifier, "modifier=\"", sizeof("modifier=\"")-1);

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
  ENC_LEN_DEBUG(x, "cdm:FBURL", p-enc_base);
  return p;
}

/* FUNC(zx_EASY_ENC_SO_cdm_FBURL) */

/* Called by: */
struct zx_str* zx_EASY_ENC_SO_cdm_FBURL(struct zx_ctx* c, struct zx_cdm_FBURL_s* x )
{
  int len;
  char* buf;
  c->ns_tab = ZX_ALLOC(c, sizeof(zx_ns_tab));
  memcpy(c->ns_tab, zx_ns_tab, sizeof(zx_ns_tab));
  len = zx_LEN_SO_cdm_FBURL(c, x );
  buf = ZX_ALLOC(c, len+1);
  return zx_easy_enc_common(c, zx_ENC_SO_cdm_FBURL(c, x, buf ), buf, len);
}

/* FUNC(zx_EASY_ENC_WO_cdm_FBURL) */

/* Called by: */
struct zx_str* zx_EASY_ENC_WO_cdm_FBURL(struct zx_ctx* c, struct zx_cdm_FBURL_s* x )
{
  int len;
  char* buf;
  c->ns_tab = ZX_ALLOC(c, sizeof(zx_ns_tab));
  memcpy(c->ns_tab, zx_ns_tab, sizeof(zx_ns_tab));
  len = zx_LEN_WO_cdm_FBURL(c, x );
  buf = ZX_ALLOC(c, len+1);
  return zx_easy_enc_common(c, zx_ENC_WO_cdm_FBURL(c, x, buf ), buf, len);
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

#define EL_NAME   cdm_FN
#define EL_STRUCT zx_cdm_FN_s
#define EL_NS     cdm
#define EL_TAG    FN

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

/* FUNC(zx_LEN_SO_cdm_FN) */

/* Compute length of an element (and its subelements). The XML attributes
 * and elements are processed in schema order. */

/* Called by: */
int zx_LEN_SO_cdm_FN(struct zx_ctx* c, struct zx_cdm_FN_s* x )
{
  struct zx_ns_s* pop_seen = 0;
  struct zx_elem_s* se MAYBE_UNUSED;
#if 1 /* NORMALMODE */
  /* *** in simple_elem case should output ns prefix from ns node. */
  int len = sizeof("<cdm:FN")-1 + 1 + sizeof("</cdm:FN>")-1;
  if (c->inc_ns_len)
    len += zx_len_inc_ns(c, &pop_seen);
  if (x->group)
    len += zx_len_xmlns_if_not_seen(c, zx_ns_tab+zx_xmlns_ix_cb, &pop_seen);
  len += zx_len_xmlns_if_not_seen(c, zx_ns_tab+zx_xmlns_ix_cdm, &pop_seen);

  len += zx_attr_so_len(x->group, sizeof("cb:group")-1);

#else
  /* root node has no begin tag */
  int len = 0;
#endif
  


  len += zx_len_so_common(c, &x->gg);
  zx_pop_seen(pop_seen);
  ENC_LEN_DEBUG(x, "cdm:FN", len);
  return len;
}

/* FUNC(zx_LEN_WO_cdm_FN) */

/* Compute length of an element (and its subelements). The XML attributes
 * and elements are processed in wire order and no assumptions
 * are made about namespace prefixes. */

/* Called by: */
int zx_LEN_WO_cdm_FN(struct zx_ctx* c, struct zx_cdm_FN_s* x )
{
  struct zx_ns_s* pop_seen = 0;
  struct zx_elem_s* se MAYBE_UNUSED;
#if 1 /* NORMALMODE */
  int len = 1 + sizeof("FN")-1 + 1 + 2 + sizeof("FN")-1 + 1;
  
  if (x->gg.g.ns && x->gg.g.ns->prefix_len)
    len += (x->gg.g.ns->prefix_len + 1) * 2;
  if (c->inc_ns_len)
    len += zx_len_inc_ns(c, &pop_seen);
  if (x->group)
    len += zx_len_xmlns_if_not_seen(c, x->group->g.ns, &pop_seen);
  len += zx_len_xmlns_if_not_seen(c, x->gg.g.ns, &pop_seen);

  len += zx_attr_wo_len(x->group, sizeof("group")-1);

#else
  /* root node has no begin tag */
  int len = 0;
#endif
  


  len += zx_len_wo_common(c, &x->gg); 
  zx_pop_seen(pop_seen);
  ENC_LEN_DEBUG(x, "cdm:FN", len);
  return len;
}

/* FUNC(zx_ENC_SO_cdm_FN) */

/* Render element into string. The XML attributes and elements are
 * processed in schema order. This is what you generally want for
 * rendering new data structure to a string. The wo pointers are not used. */

/* Called by: */
char* zx_ENC_SO_cdm_FN(struct zx_ctx* c, struct zx_cdm_FN_s* x, char* p )
{
  struct zx_elem_s* se MAYBE_UNUSED;
  struct zx_ns_s* pop_seen = 0;
  ENC_LEN_DEBUG_BASE;
#if 1 /* NORMALMODE */
  /* *** in simple_elem case should output ns prefix from ns node. */
  ZX_OUT_TAG(p, "<cdm:FN");
  if (c->inc_ns)
    p = zx_enc_inc_ns(c, p, &pop_seen);
  if (x->group)
    p = zx_enc_xmlns_if_not_seen(c, p, zx_ns_tab+zx_xmlns_ix_cb, &pop_seen);
  p = zx_enc_xmlns_if_not_seen(c, p, zx_ns_tab+zx_xmlns_ix_cdm, &pop_seen);

  p = zx_attr_so_enc(p, x->group, " cb:group=\"", sizeof(" cb:group=\"")-1);

  p = zx_enc_unknown_attrs(p, x->gg.any_attr);
#else
  /* root node has no begin tag */
#endif
  

  p = zx_enc_so_unknown_elems_and_content(c, p, &x->gg);
  
#if 1 /* NORMALMODE */
  ZX_OUT_CLOSE_TAG(p, "</cdm:FN>");
  zx_pop_seen(pop_seen);
#else
  /* root node has no end tag either */
#endif
  ENC_LEN_DEBUG(x, "cdm:FN", p-enc_base);
  return p;
}

/* FUNC(zx_ENC_WO_cdm_FN) */

/* Render element into string. The XML attributes and elements are
 * processed in wire order by chasing wo pointers. This is what you want for
 * validating signatures on other people's XML documents. */

/* Called by: */
char* zx_ENC_WO_cdm_FN(struct zx_ctx* c, struct zx_cdm_FN_s* x, char* p )
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
  ZX_OUT_MEM(p, "FN", sizeof("FN")-1);
  qq = p;

  /* *** sort the namespaces */
  if (c->inc_ns)
    zx_add_inc_ns(c, &pop_seen);
  if (x->group)
    zx_add_xmlns_if_not_seen(c, x->group->g.ns, &pop_seen);
  zx_add_xmlns_if_not_seen(c, x->gg.g.ns, &pop_seen);

  p = zx_enc_seen(p, pop_seen); 
  p = zx_attr_wo_enc(p, x->group, "group=\"", sizeof("group=\"")-1);

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
  ENC_LEN_DEBUG(x, "cdm:FN", p-enc_base);
  return p;
}

/* FUNC(zx_EASY_ENC_SO_cdm_FN) */

/* Called by: */
struct zx_str* zx_EASY_ENC_SO_cdm_FN(struct zx_ctx* c, struct zx_cdm_FN_s* x )
{
  int len;
  char* buf;
  c->ns_tab = ZX_ALLOC(c, sizeof(zx_ns_tab));
  memcpy(c->ns_tab, zx_ns_tab, sizeof(zx_ns_tab));
  len = zx_LEN_SO_cdm_FN(c, x );
  buf = ZX_ALLOC(c, len+1);
  return zx_easy_enc_common(c, zx_ENC_SO_cdm_FN(c, x, buf ), buf, len);
}

/* FUNC(zx_EASY_ENC_WO_cdm_FN) */

/* Called by: */
struct zx_str* zx_EASY_ENC_WO_cdm_FN(struct zx_ctx* c, struct zx_cdm_FN_s* x )
{
  int len;
  char* buf;
  c->ns_tab = ZX_ALLOC(c, sizeof(zx_ns_tab));
  memcpy(c->ns_tab, zx_ns_tab, sizeof(zx_ns_tab));
  len = zx_LEN_WO_cdm_FN(c, x );
  buf = ZX_ALLOC(c, len+1);
  return zx_easy_enc_common(c, zx_ENC_WO_cdm_FN(c, x, buf ), buf, len);
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

#define EL_NAME   cdm_GEO
#define EL_STRUCT zx_cdm_GEO_s
#define EL_NS     cdm
#define EL_TAG    GEO

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

/* FUNC(zx_LEN_SO_cdm_GEO) */

/* Compute length of an element (and its subelements). The XML attributes
 * and elements are processed in schema order. */

/* Called by: */
int zx_LEN_SO_cdm_GEO(struct zx_ctx* c, struct zx_cdm_GEO_s* x )
{
  struct zx_ns_s* pop_seen = 0;
  struct zx_elem_s* se MAYBE_UNUSED;
#if 1 /* NORMALMODE */
  /* *** in simple_elem case should output ns prefix from ns node. */
  int len = sizeof("<cdm:GEO")-1 + 1 + sizeof("</cdm:GEO>")-1;
  if (c->inc_ns_len)
    len += zx_len_inc_ns(c, &pop_seen);
  if (x->id || x->modificationTime)
    len += zx_len_xmlns_if_not_seen(c, zx_ns_tab+zx_xmlns_ix_cb, &pop_seen);
  len += zx_len_xmlns_if_not_seen(c, zx_ns_tab+zx_xmlns_ix_cdm, &pop_seen);

  len += zx_attr_so_len(x->id, sizeof("cb:id")-1);
  len += zx_attr_so_len(x->modificationTime, sizeof("cb:modificationTime")-1);

#else
  /* root node has no begin tag */
  int len = 0;
#endif
  
  {
      struct zx_cdm_LAT_s* e;
      for (e = x->LAT; e; e = (struct zx_cdm_LAT_s*)e->gg.g.n)
	  len += zx_LEN_SO_cdm_LAT(c, e);
  }
  {
      struct zx_cdm_LON_s* e;
      for (e = x->LON; e; e = (struct zx_cdm_LON_s*)e->gg.g.n)
	  len += zx_LEN_SO_cdm_LON(c, e);
  }


  len += zx_len_so_common(c, &x->gg);
  zx_pop_seen(pop_seen);
  ENC_LEN_DEBUG(x, "cdm:GEO", len);
  return len;
}

/* FUNC(zx_LEN_WO_cdm_GEO) */

/* Compute length of an element (and its subelements). The XML attributes
 * and elements are processed in wire order and no assumptions
 * are made about namespace prefixes. */

/* Called by: */
int zx_LEN_WO_cdm_GEO(struct zx_ctx* c, struct zx_cdm_GEO_s* x )
{
  struct zx_ns_s* pop_seen = 0;
  struct zx_elem_s* se MAYBE_UNUSED;
#if 1 /* NORMALMODE */
  int len = 1 + sizeof("GEO")-1 + 1 + 2 + sizeof("GEO")-1 + 1;
  
  if (x->gg.g.ns && x->gg.g.ns->prefix_len)
    len += (x->gg.g.ns->prefix_len + 1) * 2;
  if (c->inc_ns_len)
    len += zx_len_inc_ns(c, &pop_seen);
  if (x->id)
    len += zx_len_xmlns_if_not_seen(c, x->id->g.ns, &pop_seen);
  if (x->modificationTime)
    len += zx_len_xmlns_if_not_seen(c, x->modificationTime->g.ns, &pop_seen);
  len += zx_len_xmlns_if_not_seen(c, x->gg.g.ns, &pop_seen);

  len += zx_attr_wo_len(x->id, sizeof("id")-1);
  len += zx_attr_wo_len(x->modificationTime, sizeof("modificationTime")-1);

#else
  /* root node has no begin tag */
  int len = 0;
#endif
  
  {
      struct zx_cdm_LAT_s* e;
      for (e = x->LAT; e; e = (struct zx_cdm_LAT_s*)e->gg.g.n)
	  len += zx_LEN_WO_cdm_LAT(c, e);
  }
  {
      struct zx_cdm_LON_s* e;
      for (e = x->LON; e; e = (struct zx_cdm_LON_s*)e->gg.g.n)
	  len += zx_LEN_WO_cdm_LON(c, e);
  }


  len += zx_len_wo_common(c, &x->gg); 
  zx_pop_seen(pop_seen);
  ENC_LEN_DEBUG(x, "cdm:GEO", len);
  return len;
}

/* FUNC(zx_ENC_SO_cdm_GEO) */

/* Render element into string. The XML attributes and elements are
 * processed in schema order. This is what you generally want for
 * rendering new data structure to a string. The wo pointers are not used. */

/* Called by: */
char* zx_ENC_SO_cdm_GEO(struct zx_ctx* c, struct zx_cdm_GEO_s* x, char* p )
{
  struct zx_elem_s* se MAYBE_UNUSED;
  struct zx_ns_s* pop_seen = 0;
  ENC_LEN_DEBUG_BASE;
#if 1 /* NORMALMODE */
  /* *** in simple_elem case should output ns prefix from ns node. */
  ZX_OUT_TAG(p, "<cdm:GEO");
  if (c->inc_ns)
    p = zx_enc_inc_ns(c, p, &pop_seen);
  if (x->id || x->modificationTime)
    p = zx_enc_xmlns_if_not_seen(c, p, zx_ns_tab+zx_xmlns_ix_cb, &pop_seen);
  p = zx_enc_xmlns_if_not_seen(c, p, zx_ns_tab+zx_xmlns_ix_cdm, &pop_seen);

  p = zx_attr_so_enc(p, x->id, " cb:id=\"", sizeof(" cb:id=\"")-1);
  p = zx_attr_so_enc(p, x->modificationTime, " cb:modificationTime=\"", sizeof(" cb:modificationTime=\"")-1);

  p = zx_enc_unknown_attrs(p, x->gg.any_attr);
#else
  /* root node has no begin tag */
#endif
  
  {
      struct zx_cdm_LAT_s* e;
      for (e = x->LAT; e; e = (struct zx_cdm_LAT_s*)e->gg.g.n)
	  p = zx_ENC_SO_cdm_LAT(c, e, p);
  }
  {
      struct zx_cdm_LON_s* e;
      for (e = x->LON; e; e = (struct zx_cdm_LON_s*)e->gg.g.n)
	  p = zx_ENC_SO_cdm_LON(c, e, p);
  }

  p = zx_enc_so_unknown_elems_and_content(c, p, &x->gg);
  
#if 1 /* NORMALMODE */
  ZX_OUT_CLOSE_TAG(p, "</cdm:GEO>");
  zx_pop_seen(pop_seen);
#else
  /* root node has no end tag either */
#endif
  ENC_LEN_DEBUG(x, "cdm:GEO", p-enc_base);
  return p;
}

/* FUNC(zx_ENC_WO_cdm_GEO) */

/* Render element into string. The XML attributes and elements are
 * processed in wire order by chasing wo pointers. This is what you want for
 * validating signatures on other people's XML documents. */

/* Called by: */
char* zx_ENC_WO_cdm_GEO(struct zx_ctx* c, struct zx_cdm_GEO_s* x, char* p )
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
  ZX_OUT_MEM(p, "GEO", sizeof("GEO")-1);
  qq = p;

  /* *** sort the namespaces */
  if (c->inc_ns)
    zx_add_inc_ns(c, &pop_seen);
  if (x->id)
    zx_add_xmlns_if_not_seen(c, x->id->g.ns, &pop_seen);
  if (x->modificationTime)
    zx_add_xmlns_if_not_seen(c, x->modificationTime->g.ns, &pop_seen);
  zx_add_xmlns_if_not_seen(c, x->gg.g.ns, &pop_seen);

  p = zx_enc_seen(p, pop_seen); 
  p = zx_attr_wo_enc(p, x->id, "id=\"", sizeof("id=\"")-1);
  p = zx_attr_wo_enc(p, x->modificationTime, "modificationTime=\"", sizeof("modificationTime=\"")-1);

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
  ENC_LEN_DEBUG(x, "cdm:GEO", p-enc_base);
  return p;
}

/* FUNC(zx_EASY_ENC_SO_cdm_GEO) */

/* Called by: */
struct zx_str* zx_EASY_ENC_SO_cdm_GEO(struct zx_ctx* c, struct zx_cdm_GEO_s* x )
{
  int len;
  char* buf;
  c->ns_tab = ZX_ALLOC(c, sizeof(zx_ns_tab));
  memcpy(c->ns_tab, zx_ns_tab, sizeof(zx_ns_tab));
  len = zx_LEN_SO_cdm_GEO(c, x );
  buf = ZX_ALLOC(c, len+1);
  return zx_easy_enc_common(c, zx_ENC_SO_cdm_GEO(c, x, buf ), buf, len);
}

/* FUNC(zx_EASY_ENC_WO_cdm_GEO) */

/* Called by: */
struct zx_str* zx_EASY_ENC_WO_cdm_GEO(struct zx_ctx* c, struct zx_cdm_GEO_s* x )
{
  int len;
  char* buf;
  c->ns_tab = ZX_ALLOC(c, sizeof(zx_ns_tab));
  memcpy(c->ns_tab, zx_ns_tab, sizeof(zx_ns_tab));
  len = zx_LEN_WO_cdm_GEO(c, x );
  buf = ZX_ALLOC(c, len+1);
  return zx_easy_enc_common(c, zx_ENC_WO_cdm_GEO(c, x, buf ), buf, len);
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

#define EL_NAME   cdm_GIVEN
#define EL_STRUCT zx_cdm_GIVEN_s
#define EL_NS     cdm
#define EL_TAG    GIVEN

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

/* FUNC(zx_LEN_SO_cdm_GIVEN) */

/* Compute length of an element (and its subelements). The XML attributes
 * and elements are processed in schema order. */

/* Called by: */
int zx_LEN_SO_cdm_GIVEN(struct zx_ctx* c, struct zx_cdm_GIVEN_s* x )
{
  struct zx_ns_s* pop_seen = 0;
  struct zx_elem_s* se MAYBE_UNUSED;
#if 1 /* NORMALMODE */
  /* *** in simple_elem case should output ns prefix from ns node. */
  int len = sizeof("<cdm:GIVEN")-1 + 1 + sizeof("</cdm:GIVEN>")-1;
  if (c->inc_ns_len)
    len += zx_len_inc_ns(c, &pop_seen);
  if (x->group)
    len += zx_len_xmlns_if_not_seen(c, zx_ns_tab+zx_xmlns_ix_cb, &pop_seen);
  len += zx_len_xmlns_if_not_seen(c, zx_ns_tab+zx_xmlns_ix_cdm, &pop_seen);

  len += zx_attr_so_len(x->group, sizeof("cb:group")-1);

#else
  /* root node has no begin tag */
  int len = 0;
#endif
  


  len += zx_len_so_common(c, &x->gg);
  zx_pop_seen(pop_seen);
  ENC_LEN_DEBUG(x, "cdm:GIVEN", len);
  return len;
}

/* FUNC(zx_LEN_WO_cdm_GIVEN) */

/* Compute length of an element (and its subelements). The XML attributes
 * and elements are processed in wire order and no assumptions
 * are made about namespace prefixes. */

/* Called by: */
int zx_LEN_WO_cdm_GIVEN(struct zx_ctx* c, struct zx_cdm_GIVEN_s* x )
{
  struct zx_ns_s* pop_seen = 0;
  struct zx_elem_s* se MAYBE_UNUSED;
#if 1 /* NORMALMODE */
  int len = 1 + sizeof("GIVEN")-1 + 1 + 2 + sizeof("GIVEN")-1 + 1;
  
  if (x->gg.g.ns && x->gg.g.ns->prefix_len)
    len += (x->gg.g.ns->prefix_len + 1) * 2;
  if (c->inc_ns_len)
    len += zx_len_inc_ns(c, &pop_seen);
  if (x->group)
    len += zx_len_xmlns_if_not_seen(c, x->group->g.ns, &pop_seen);
  len += zx_len_xmlns_if_not_seen(c, x->gg.g.ns, &pop_seen);

  len += zx_attr_wo_len(x->group, sizeof("group")-1);

#else
  /* root node has no begin tag */
  int len = 0;
#endif
  


  len += zx_len_wo_common(c, &x->gg); 
  zx_pop_seen(pop_seen);
  ENC_LEN_DEBUG(x, "cdm:GIVEN", len);
  return len;
}

/* FUNC(zx_ENC_SO_cdm_GIVEN) */

/* Render element into string. The XML attributes and elements are
 * processed in schema order. This is what you generally want for
 * rendering new data structure to a string. The wo pointers are not used. */

/* Called by: */
char* zx_ENC_SO_cdm_GIVEN(struct zx_ctx* c, struct zx_cdm_GIVEN_s* x, char* p )
{
  struct zx_elem_s* se MAYBE_UNUSED;
  struct zx_ns_s* pop_seen = 0;
  ENC_LEN_DEBUG_BASE;
#if 1 /* NORMALMODE */
  /* *** in simple_elem case should output ns prefix from ns node. */
  ZX_OUT_TAG(p, "<cdm:GIVEN");
  if (c->inc_ns)
    p = zx_enc_inc_ns(c, p, &pop_seen);
  if (x->group)
    p = zx_enc_xmlns_if_not_seen(c, p, zx_ns_tab+zx_xmlns_ix_cb, &pop_seen);
  p = zx_enc_xmlns_if_not_seen(c, p, zx_ns_tab+zx_xmlns_ix_cdm, &pop_seen);

  p = zx_attr_so_enc(p, x->group, " cb:group=\"", sizeof(" cb:group=\"")-1);

  p = zx_enc_unknown_attrs(p, x->gg.any_attr);
#else
  /* root node has no begin tag */
#endif
  

  p = zx_enc_so_unknown_elems_and_content(c, p, &x->gg);
  
#if 1 /* NORMALMODE */
  ZX_OUT_CLOSE_TAG(p, "</cdm:GIVEN>");
  zx_pop_seen(pop_seen);
#else
  /* root node has no end tag either */
#endif
  ENC_LEN_DEBUG(x, "cdm:GIVEN", p-enc_base);
  return p;
}

/* FUNC(zx_ENC_WO_cdm_GIVEN) */

/* Render element into string. The XML attributes and elements are
 * processed in wire order by chasing wo pointers. This is what you want for
 * validating signatures on other people's XML documents. */

/* Called by: */
char* zx_ENC_WO_cdm_GIVEN(struct zx_ctx* c, struct zx_cdm_GIVEN_s* x, char* p )
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
  ZX_OUT_MEM(p, "GIVEN", sizeof("GIVEN")-1);
  qq = p;

  /* *** sort the namespaces */
  if (c->inc_ns)
    zx_add_inc_ns(c, &pop_seen);
  if (x->group)
    zx_add_xmlns_if_not_seen(c, x->group->g.ns, &pop_seen);
  zx_add_xmlns_if_not_seen(c, x->gg.g.ns, &pop_seen);

  p = zx_enc_seen(p, pop_seen); 
  p = zx_attr_wo_enc(p, x->group, "group=\"", sizeof("group=\"")-1);

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
  ENC_LEN_DEBUG(x, "cdm:GIVEN", p-enc_base);
  return p;
}

/* FUNC(zx_EASY_ENC_SO_cdm_GIVEN) */

/* Called by: */
struct zx_str* zx_EASY_ENC_SO_cdm_GIVEN(struct zx_ctx* c, struct zx_cdm_GIVEN_s* x )
{
  int len;
  char* buf;
  c->ns_tab = ZX_ALLOC(c, sizeof(zx_ns_tab));
  memcpy(c->ns_tab, zx_ns_tab, sizeof(zx_ns_tab));
  len = zx_LEN_SO_cdm_GIVEN(c, x );
  buf = ZX_ALLOC(c, len+1);
  return zx_easy_enc_common(c, zx_ENC_SO_cdm_GIVEN(c, x, buf ), buf, len);
}

/* FUNC(zx_EASY_ENC_WO_cdm_GIVEN) */

/* Called by: */
struct zx_str* zx_EASY_ENC_WO_cdm_GIVEN(struct zx_ctx* c, struct zx_cdm_GIVEN_s* x )
{
  int len;
  char* buf;
  c->ns_tab = ZX_ALLOC(c, sizeof(zx_ns_tab));
  memcpy(c->ns_tab, zx_ns_tab, sizeof(zx_ns_tab));
  len = zx_LEN_WO_cdm_GIVEN(c, x );
  buf = ZX_ALLOC(c, len+1);
  return zx_easy_enc_common(c, zx_ENC_WO_cdm_GIVEN(c, x, buf ), buf, len);
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

#define EL_NAME   cdm_JABBERID
#define EL_STRUCT zx_cdm_JABBERID_s
#define EL_NS     cdm
#define EL_TAG    JABBERID

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

/* FUNC(zx_LEN_SO_cdm_JABBERID) */

/* Compute length of an element (and its subelements). The XML attributes
 * and elements are processed in schema order. */

/* Called by: */
int zx_LEN_SO_cdm_JABBERID(struct zx_ctx* c, struct zx_cdm_JABBERID_s* x )
{
  struct zx_ns_s* pop_seen = 0;
  struct zx_elem_s* se MAYBE_UNUSED;
#if 1 /* NORMALMODE */
  /* *** in simple_elem case should output ns prefix from ns node. */
  int len = sizeof("<cdm:JABBERID")-1 + 1 + sizeof("</cdm:JABBERID>")-1;
  if (c->inc_ns_len)
    len += zx_len_inc_ns(c, &pop_seen);
  if (x->ACC || x->ACCTime || x->id || x->modificationTime || x->modifier)
    len += zx_len_xmlns_if_not_seen(c, zx_ns_tab+zx_xmlns_ix_cb, &pop_seen);
  len += zx_len_xmlns_if_not_seen(c, zx_ns_tab+zx_xmlns_ix_cdm, &pop_seen);

  len += zx_attr_so_len(x->ACC, sizeof("cb:ACC")-1);
  len += zx_attr_so_len(x->ACCTime, sizeof("cb:ACCTime")-1);
  len += zx_attr_so_len(x->id, sizeof("cb:id")-1);
  len += zx_attr_so_len(x->modificationTime, sizeof("cb:modificationTime")-1);
  len += zx_attr_so_len(x->modifier, sizeof("cb:modifier")-1);

#else
  /* root node has no begin tag */
  int len = 0;
#endif
  


  len += zx_len_so_common(c, &x->gg);
  zx_pop_seen(pop_seen);
  ENC_LEN_DEBUG(x, "cdm:JABBERID", len);
  return len;
}

/* FUNC(zx_LEN_WO_cdm_JABBERID) */

/* Compute length of an element (and its subelements). The XML attributes
 * and elements are processed in wire order and no assumptions
 * are made about namespace prefixes. */

/* Called by: */
int zx_LEN_WO_cdm_JABBERID(struct zx_ctx* c, struct zx_cdm_JABBERID_s* x )
{
  struct zx_ns_s* pop_seen = 0;
  struct zx_elem_s* se MAYBE_UNUSED;
#if 1 /* NORMALMODE */
  int len = 1 + sizeof("JABBERID")-1 + 1 + 2 + sizeof("JABBERID")-1 + 1;
  
  if (x->gg.g.ns && x->gg.g.ns->prefix_len)
    len += (x->gg.g.ns->prefix_len + 1) * 2;
  if (c->inc_ns_len)
    len += zx_len_inc_ns(c, &pop_seen);
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
  len += zx_len_xmlns_if_not_seen(c, x->gg.g.ns, &pop_seen);

  len += zx_attr_wo_len(x->ACC, sizeof("ACC")-1);
  len += zx_attr_wo_len(x->ACCTime, sizeof("ACCTime")-1);
  len += zx_attr_wo_len(x->id, sizeof("id")-1);
  len += zx_attr_wo_len(x->modificationTime, sizeof("modificationTime")-1);
  len += zx_attr_wo_len(x->modifier, sizeof("modifier")-1);

#else
  /* root node has no begin tag */
  int len = 0;
#endif
  


  len += zx_len_wo_common(c, &x->gg); 
  zx_pop_seen(pop_seen);
  ENC_LEN_DEBUG(x, "cdm:JABBERID", len);
  return len;
}

/* FUNC(zx_ENC_SO_cdm_JABBERID) */

/* Render element into string. The XML attributes and elements are
 * processed in schema order. This is what you generally want for
 * rendering new data structure to a string. The wo pointers are not used. */

/* Called by: */
char* zx_ENC_SO_cdm_JABBERID(struct zx_ctx* c, struct zx_cdm_JABBERID_s* x, char* p )
{
  struct zx_elem_s* se MAYBE_UNUSED;
  struct zx_ns_s* pop_seen = 0;
  ENC_LEN_DEBUG_BASE;
#if 1 /* NORMALMODE */
  /* *** in simple_elem case should output ns prefix from ns node. */
  ZX_OUT_TAG(p, "<cdm:JABBERID");
  if (c->inc_ns)
    p = zx_enc_inc_ns(c, p, &pop_seen);
  if (x->ACC || x->ACCTime || x->id || x->modificationTime || x->modifier)
    p = zx_enc_xmlns_if_not_seen(c, p, zx_ns_tab+zx_xmlns_ix_cb, &pop_seen);
  p = zx_enc_xmlns_if_not_seen(c, p, zx_ns_tab+zx_xmlns_ix_cdm, &pop_seen);

  p = zx_attr_so_enc(p, x->ACC, " cb:ACC=\"", sizeof(" cb:ACC=\"")-1);
  p = zx_attr_so_enc(p, x->ACCTime, " cb:ACCTime=\"", sizeof(" cb:ACCTime=\"")-1);
  p = zx_attr_so_enc(p, x->id, " cb:id=\"", sizeof(" cb:id=\"")-1);
  p = zx_attr_so_enc(p, x->modificationTime, " cb:modificationTime=\"", sizeof(" cb:modificationTime=\"")-1);
  p = zx_attr_so_enc(p, x->modifier, " cb:modifier=\"", sizeof(" cb:modifier=\"")-1);

  p = zx_enc_unknown_attrs(p, x->gg.any_attr);
#else
  /* root node has no begin tag */
#endif
  

  p = zx_enc_so_unknown_elems_and_content(c, p, &x->gg);
  
#if 1 /* NORMALMODE */
  ZX_OUT_CLOSE_TAG(p, "</cdm:JABBERID>");
  zx_pop_seen(pop_seen);
#else
  /* root node has no end tag either */
#endif
  ENC_LEN_DEBUG(x, "cdm:JABBERID", p-enc_base);
  return p;
}

/* FUNC(zx_ENC_WO_cdm_JABBERID) */

/* Render element into string. The XML attributes and elements are
 * processed in wire order by chasing wo pointers. This is what you want for
 * validating signatures on other people's XML documents. */

/* Called by: */
char* zx_ENC_WO_cdm_JABBERID(struct zx_ctx* c, struct zx_cdm_JABBERID_s* x, char* p )
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
  ZX_OUT_MEM(p, "JABBERID", sizeof("JABBERID")-1);
  qq = p;

  /* *** sort the namespaces */
  if (c->inc_ns)
    zx_add_inc_ns(c, &pop_seen);
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
  zx_add_xmlns_if_not_seen(c, x->gg.g.ns, &pop_seen);

  p = zx_enc_seen(p, pop_seen); 
  p = zx_attr_wo_enc(p, x->ACC, "ACC=\"", sizeof("ACC=\"")-1);
  p = zx_attr_wo_enc(p, x->ACCTime, "ACCTime=\"", sizeof("ACCTime=\"")-1);
  p = zx_attr_wo_enc(p, x->id, "id=\"", sizeof("id=\"")-1);
  p = zx_attr_wo_enc(p, x->modificationTime, "modificationTime=\"", sizeof("modificationTime=\"")-1);
  p = zx_attr_wo_enc(p, x->modifier, "modifier=\"", sizeof("modifier=\"")-1);

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
  ENC_LEN_DEBUG(x, "cdm:JABBERID", p-enc_base);
  return p;
}

/* FUNC(zx_EASY_ENC_SO_cdm_JABBERID) */

/* Called by: */
struct zx_str* zx_EASY_ENC_SO_cdm_JABBERID(struct zx_ctx* c, struct zx_cdm_JABBERID_s* x )
{
  int len;
  char* buf;
  c->ns_tab = ZX_ALLOC(c, sizeof(zx_ns_tab));
  memcpy(c->ns_tab, zx_ns_tab, sizeof(zx_ns_tab));
  len = zx_LEN_SO_cdm_JABBERID(c, x );
  buf = ZX_ALLOC(c, len+1);
  return zx_easy_enc_common(c, zx_ENC_SO_cdm_JABBERID(c, x, buf ), buf, len);
}

/* FUNC(zx_EASY_ENC_WO_cdm_JABBERID) */

/* Called by: */
struct zx_str* zx_EASY_ENC_WO_cdm_JABBERID(struct zx_ctx* c, struct zx_cdm_JABBERID_s* x )
{
  int len;
  char* buf;
  c->ns_tab = ZX_ALLOC(c, sizeof(zx_ns_tab));
  memcpy(c->ns_tab, zx_ns_tab, sizeof(zx_ns_tab));
  len = zx_LEN_WO_cdm_JABBERID(c, x );
  buf = ZX_ALLOC(c, len+1);
  return zx_easy_enc_common(c, zx_ENC_WO_cdm_JABBERID(c, x, buf ), buf, len);
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

#define EL_NAME   cdm_KEY
#define EL_STRUCT zx_cdm_KEY_s
#define EL_NS     cdm
#define EL_TAG    KEY

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

/* FUNC(zx_LEN_SO_cdm_KEY) */

/* Compute length of an element (and its subelements). The XML attributes
 * and elements are processed in schema order. */

/* Called by: */
int zx_LEN_SO_cdm_KEY(struct zx_ctx* c, struct zx_cdm_KEY_s* x )
{
  struct zx_ns_s* pop_seen = 0;
  struct zx_elem_s* se MAYBE_UNUSED;
#if 1 /* NORMALMODE */
  /* *** in simple_elem case should output ns prefix from ns node. */
  int len = sizeof("<cdm:KEY")-1 + 1 + sizeof("</cdm:KEY>")-1;
  if (c->inc_ns_len)
    len += zx_len_inc_ns(c, &pop_seen);
  len += zx_len_xmlns_if_not_seen(c, zx_ns_tab+zx_xmlns_ix_cdm, &pop_seen);


#else
  /* root node has no begin tag */
  int len = 0;
#endif
  
  {
      struct zx_cdm_TYPE_s* e;
      for (e = x->TYPE; e; e = (struct zx_cdm_TYPE_s*)e->gg.g.n)
	  len += zx_LEN_SO_cdm_TYPE(c, e);
  }
  {
      struct zx_cdm_CRED_s* e;
      for (e = x->CRED; e; e = (struct zx_cdm_CRED_s*)e->gg.g.n)
	  len += zx_LEN_SO_cdm_CRED(c, e);
  }


  len += zx_len_so_common(c, &x->gg);
  zx_pop_seen(pop_seen);
  ENC_LEN_DEBUG(x, "cdm:KEY", len);
  return len;
}

/* FUNC(zx_LEN_WO_cdm_KEY) */

/* Compute length of an element (and its subelements). The XML attributes
 * and elements are processed in wire order and no assumptions
 * are made about namespace prefixes. */

/* Called by: */
int zx_LEN_WO_cdm_KEY(struct zx_ctx* c, struct zx_cdm_KEY_s* x )
{
  struct zx_ns_s* pop_seen = 0;
  struct zx_elem_s* se MAYBE_UNUSED;
#if 1 /* NORMALMODE */
  int len = 1 + sizeof("KEY")-1 + 1 + 2 + sizeof("KEY")-1 + 1;
  
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
      struct zx_cdm_TYPE_s* e;
      for (e = x->TYPE; e; e = (struct zx_cdm_TYPE_s*)e->gg.g.n)
	  len += zx_LEN_WO_cdm_TYPE(c, e);
  }
  {
      struct zx_cdm_CRED_s* e;
      for (e = x->CRED; e; e = (struct zx_cdm_CRED_s*)e->gg.g.n)
	  len += zx_LEN_WO_cdm_CRED(c, e);
  }


  len += zx_len_wo_common(c, &x->gg); 
  zx_pop_seen(pop_seen);
  ENC_LEN_DEBUG(x, "cdm:KEY", len);
  return len;
}

/* FUNC(zx_ENC_SO_cdm_KEY) */

/* Render element into string. The XML attributes and elements are
 * processed in schema order. This is what you generally want for
 * rendering new data structure to a string. The wo pointers are not used. */

/* Called by: */
char* zx_ENC_SO_cdm_KEY(struct zx_ctx* c, struct zx_cdm_KEY_s* x, char* p )
{
  struct zx_elem_s* se MAYBE_UNUSED;
  struct zx_ns_s* pop_seen = 0;
  ENC_LEN_DEBUG_BASE;
#if 1 /* NORMALMODE */
  /* *** in simple_elem case should output ns prefix from ns node. */
  ZX_OUT_TAG(p, "<cdm:KEY");
  if (c->inc_ns)
    p = zx_enc_inc_ns(c, p, &pop_seen);
  p = zx_enc_xmlns_if_not_seen(c, p, zx_ns_tab+zx_xmlns_ix_cdm, &pop_seen);


  p = zx_enc_unknown_attrs(p, x->gg.any_attr);
#else
  /* root node has no begin tag */
#endif
  
  {
      struct zx_cdm_TYPE_s* e;
      for (e = x->TYPE; e; e = (struct zx_cdm_TYPE_s*)e->gg.g.n)
	  p = zx_ENC_SO_cdm_TYPE(c, e, p);
  }
  {
      struct zx_cdm_CRED_s* e;
      for (e = x->CRED; e; e = (struct zx_cdm_CRED_s*)e->gg.g.n)
	  p = zx_ENC_SO_cdm_CRED(c, e, p);
  }

  p = zx_enc_so_unknown_elems_and_content(c, p, &x->gg);
  
#if 1 /* NORMALMODE */
  ZX_OUT_CLOSE_TAG(p, "</cdm:KEY>");
  zx_pop_seen(pop_seen);
#else
  /* root node has no end tag either */
#endif
  ENC_LEN_DEBUG(x, "cdm:KEY", p-enc_base);
  return p;
}

/* FUNC(zx_ENC_WO_cdm_KEY) */

/* Render element into string. The XML attributes and elements are
 * processed in wire order by chasing wo pointers. This is what you want for
 * validating signatures on other people's XML documents. */

/* Called by: */
char* zx_ENC_WO_cdm_KEY(struct zx_ctx* c, struct zx_cdm_KEY_s* x, char* p )
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
  ZX_OUT_MEM(p, "KEY", sizeof("KEY")-1);
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
  ENC_LEN_DEBUG(x, "cdm:KEY", p-enc_base);
  return p;
}

/* FUNC(zx_EASY_ENC_SO_cdm_KEY) */

/* Called by: */
struct zx_str* zx_EASY_ENC_SO_cdm_KEY(struct zx_ctx* c, struct zx_cdm_KEY_s* x )
{
  int len;
  char* buf;
  c->ns_tab = ZX_ALLOC(c, sizeof(zx_ns_tab));
  memcpy(c->ns_tab, zx_ns_tab, sizeof(zx_ns_tab));
  len = zx_LEN_SO_cdm_KEY(c, x );
  buf = ZX_ALLOC(c, len+1);
  return zx_easy_enc_common(c, zx_ENC_SO_cdm_KEY(c, x, buf ), buf, len);
}

/* FUNC(zx_EASY_ENC_WO_cdm_KEY) */

/* Called by: */
struct zx_str* zx_EASY_ENC_WO_cdm_KEY(struct zx_ctx* c, struct zx_cdm_KEY_s* x )
{
  int len;
  char* buf;
  c->ns_tab = ZX_ALLOC(c, sizeof(zx_ns_tab));
  memcpy(c->ns_tab, zx_ns_tab, sizeof(zx_ns_tab));
  len = zx_LEN_WO_cdm_KEY(c, x );
  buf = ZX_ALLOC(c, len+1);
  return zx_easy_enc_common(c, zx_ENC_WO_cdm_KEY(c, x, buf ), buf, len);
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

#define EL_NAME   cdm_KEYWORD
#define EL_STRUCT zx_cdm_KEYWORD_s
#define EL_NS     cdm
#define EL_TAG    KEYWORD

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

/* FUNC(zx_LEN_SO_cdm_KEYWORD) */

/* Compute length of an element (and its subelements). The XML attributes
 * and elements are processed in schema order. */

/* Called by: */
int zx_LEN_SO_cdm_KEYWORD(struct zx_ctx* c, struct zx_cdm_KEYWORD_s* x )
{
  struct zx_ns_s* pop_seen = 0;
  struct zx_elem_s* se MAYBE_UNUSED;
#if 1 /* NORMALMODE */
  /* *** in simple_elem case should output ns prefix from ns node. */
  int len = sizeof("<cdm:KEYWORD")-1 + 1 + sizeof("</cdm:KEYWORD>")-1;
  if (c->inc_ns_len)
    len += zx_len_inc_ns(c, &pop_seen);
  if (x->ACC || x->ACCTime || x->id || x->modificationTime || x->modifier)
    len += zx_len_xmlns_if_not_seen(c, zx_ns_tab+zx_xmlns_ix_cb, &pop_seen);
  len += zx_len_xmlns_if_not_seen(c, zx_ns_tab+zx_xmlns_ix_cdm, &pop_seen);

  len += zx_attr_so_len(x->ACC, sizeof("cb:ACC")-1);
  len += zx_attr_so_len(x->ACCTime, sizeof("cb:ACCTime")-1);
  len += zx_attr_so_len(x->id, sizeof("cb:id")-1);
  len += zx_attr_so_len(x->modificationTime, sizeof("cb:modificationTime")-1);
  len += zx_attr_so_len(x->modifier, sizeof("cb:modifier")-1);

#else
  /* root node has no begin tag */
  int len = 0;
#endif
  


  len += zx_len_so_common(c, &x->gg);
  zx_pop_seen(pop_seen);
  ENC_LEN_DEBUG(x, "cdm:KEYWORD", len);
  return len;
}

/* FUNC(zx_LEN_WO_cdm_KEYWORD) */

/* Compute length of an element (and its subelements). The XML attributes
 * and elements are processed in wire order and no assumptions
 * are made about namespace prefixes. */

/* Called by: */
int zx_LEN_WO_cdm_KEYWORD(struct zx_ctx* c, struct zx_cdm_KEYWORD_s* x )
{
  struct zx_ns_s* pop_seen = 0;
  struct zx_elem_s* se MAYBE_UNUSED;
#if 1 /* NORMALMODE */
  int len = 1 + sizeof("KEYWORD")-1 + 1 + 2 + sizeof("KEYWORD")-1 + 1;
  
  if (x->gg.g.ns && x->gg.g.ns->prefix_len)
    len += (x->gg.g.ns->prefix_len + 1) * 2;
  if (c->inc_ns_len)
    len += zx_len_inc_ns(c, &pop_seen);
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
  len += zx_len_xmlns_if_not_seen(c, x->gg.g.ns, &pop_seen);

  len += zx_attr_wo_len(x->ACC, sizeof("ACC")-1);
  len += zx_attr_wo_len(x->ACCTime, sizeof("ACCTime")-1);
  len += zx_attr_wo_len(x->id, sizeof("id")-1);
  len += zx_attr_wo_len(x->modificationTime, sizeof("modificationTime")-1);
  len += zx_attr_wo_len(x->modifier, sizeof("modifier")-1);

#else
  /* root node has no begin tag */
  int len = 0;
#endif
  


  len += zx_len_wo_common(c, &x->gg); 
  zx_pop_seen(pop_seen);
  ENC_LEN_DEBUG(x, "cdm:KEYWORD", len);
  return len;
}

/* FUNC(zx_ENC_SO_cdm_KEYWORD) */

/* Render element into string. The XML attributes and elements are
 * processed in schema order. This is what you generally want for
 * rendering new data structure to a string. The wo pointers are not used. */

/* Called by: */
char* zx_ENC_SO_cdm_KEYWORD(struct zx_ctx* c, struct zx_cdm_KEYWORD_s* x, char* p )
{
  struct zx_elem_s* se MAYBE_UNUSED;
  struct zx_ns_s* pop_seen = 0;
  ENC_LEN_DEBUG_BASE;
#if 1 /* NORMALMODE */
  /* *** in simple_elem case should output ns prefix from ns node. */
  ZX_OUT_TAG(p, "<cdm:KEYWORD");
  if (c->inc_ns)
    p = zx_enc_inc_ns(c, p, &pop_seen);
  if (x->ACC || x->ACCTime || x->id || x->modificationTime || x->modifier)
    p = zx_enc_xmlns_if_not_seen(c, p, zx_ns_tab+zx_xmlns_ix_cb, &pop_seen);
  p = zx_enc_xmlns_if_not_seen(c, p, zx_ns_tab+zx_xmlns_ix_cdm, &pop_seen);

  p = zx_attr_so_enc(p, x->ACC, " cb:ACC=\"", sizeof(" cb:ACC=\"")-1);
  p = zx_attr_so_enc(p, x->ACCTime, " cb:ACCTime=\"", sizeof(" cb:ACCTime=\"")-1);
  p = zx_attr_so_enc(p, x->id, " cb:id=\"", sizeof(" cb:id=\"")-1);
  p = zx_attr_so_enc(p, x->modificationTime, " cb:modificationTime=\"", sizeof(" cb:modificationTime=\"")-1);
  p = zx_attr_so_enc(p, x->modifier, " cb:modifier=\"", sizeof(" cb:modifier=\"")-1);

  p = zx_enc_unknown_attrs(p, x->gg.any_attr);
#else
  /* root node has no begin tag */
#endif
  

  p = zx_enc_so_unknown_elems_and_content(c, p, &x->gg);
  
#if 1 /* NORMALMODE */
  ZX_OUT_CLOSE_TAG(p, "</cdm:KEYWORD>");
  zx_pop_seen(pop_seen);
#else
  /* root node has no end tag either */
#endif
  ENC_LEN_DEBUG(x, "cdm:KEYWORD", p-enc_base);
  return p;
}

/* FUNC(zx_ENC_WO_cdm_KEYWORD) */

/* Render element into string. The XML attributes and elements are
 * processed in wire order by chasing wo pointers. This is what you want for
 * validating signatures on other people's XML documents. */

/* Called by: */
char* zx_ENC_WO_cdm_KEYWORD(struct zx_ctx* c, struct zx_cdm_KEYWORD_s* x, char* p )
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
  ZX_OUT_MEM(p, "KEYWORD", sizeof("KEYWORD")-1);
  qq = p;

  /* *** sort the namespaces */
  if (c->inc_ns)
    zx_add_inc_ns(c, &pop_seen);
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
  zx_add_xmlns_if_not_seen(c, x->gg.g.ns, &pop_seen);

  p = zx_enc_seen(p, pop_seen); 
  p = zx_attr_wo_enc(p, x->ACC, "ACC=\"", sizeof("ACC=\"")-1);
  p = zx_attr_wo_enc(p, x->ACCTime, "ACCTime=\"", sizeof("ACCTime=\"")-1);
  p = zx_attr_wo_enc(p, x->id, "id=\"", sizeof("id=\"")-1);
  p = zx_attr_wo_enc(p, x->modificationTime, "modificationTime=\"", sizeof("modificationTime=\"")-1);
  p = zx_attr_wo_enc(p, x->modifier, "modifier=\"", sizeof("modifier=\"")-1);

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
  ENC_LEN_DEBUG(x, "cdm:KEYWORD", p-enc_base);
  return p;
}

/* FUNC(zx_EASY_ENC_SO_cdm_KEYWORD) */

/* Called by: */
struct zx_str* zx_EASY_ENC_SO_cdm_KEYWORD(struct zx_ctx* c, struct zx_cdm_KEYWORD_s* x )
{
  int len;
  char* buf;
  c->ns_tab = ZX_ALLOC(c, sizeof(zx_ns_tab));
  memcpy(c->ns_tab, zx_ns_tab, sizeof(zx_ns_tab));
  len = zx_LEN_SO_cdm_KEYWORD(c, x );
  buf = ZX_ALLOC(c, len+1);
  return zx_easy_enc_common(c, zx_ENC_SO_cdm_KEYWORD(c, x, buf ), buf, len);
}

/* FUNC(zx_EASY_ENC_WO_cdm_KEYWORD) */

/* Called by: */
struct zx_str* zx_EASY_ENC_WO_cdm_KEYWORD(struct zx_ctx* c, struct zx_cdm_KEYWORD_s* x )
{
  int len;
  char* buf;
  c->ns_tab = ZX_ALLOC(c, sizeof(zx_ns_tab));
  memcpy(c->ns_tab, zx_ns_tab, sizeof(zx_ns_tab));
  len = zx_LEN_WO_cdm_KEYWORD(c, x );
  buf = ZX_ALLOC(c, len+1);
  return zx_easy_enc_common(c, zx_ENC_WO_cdm_KEYWORD(c, x, buf ), buf, len);
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

#define EL_NAME   cdm_LABEL
#define EL_STRUCT zx_cdm_LABEL_s
#define EL_NS     cdm
#define EL_TAG    LABEL

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

/* FUNC(zx_LEN_SO_cdm_LABEL) */

/* Compute length of an element (and its subelements). The XML attributes
 * and elements are processed in schema order. */

/* Called by: */
int zx_LEN_SO_cdm_LABEL(struct zx_ctx* c, struct zx_cdm_LABEL_s* x )
{
  struct zx_ns_s* pop_seen = 0;
  struct zx_elem_s* se MAYBE_UNUSED;
#if 1 /* NORMALMODE */
  /* *** in simple_elem case should output ns prefix from ns node. */
  int len = sizeof("<cdm:LABEL")-1 + 1 + sizeof("</cdm:LABEL>")-1;
  if (c->inc_ns_len)
    len += zx_len_inc_ns(c, &pop_seen);
  if (x->id || x->modificationTime)
    len += zx_len_xmlns_if_not_seen(c, zx_ns_tab+zx_xmlns_ix_cb, &pop_seen);
  len += zx_len_xmlns_if_not_seen(c, zx_ns_tab+zx_xmlns_ix_cdm, &pop_seen);

  len += zx_attr_so_len(x->id, sizeof("cb:id")-1);
  len += zx_attr_so_len(x->modificationTime, sizeof("cb:modificationTime")-1);

#else
  /* root node has no begin tag */
  int len = 0;
#endif
  
  for (se = x->HOME; se; se = (struct zx_elem_s*)se->g.n)
    len += zx_LEN_SO_simple_elem(c,se, sizeof("cdm:HOME")-1, zx_ns_tab+zx_xmlns_ix_cdm);
  for (se = x->WORK; se; se = (struct zx_elem_s*)se->g.n)
    len += zx_LEN_SO_simple_elem(c,se, sizeof("cdm:WORK")-1, zx_ns_tab+zx_xmlns_ix_cdm);
  for (se = x->POSTAL; se; se = (struct zx_elem_s*)se->g.n)
    len += zx_LEN_SO_simple_elem(c,se, sizeof("cdm:POSTAL")-1, zx_ns_tab+zx_xmlns_ix_cdm);
  for (se = x->PARCEL; se; se = (struct zx_elem_s*)se->g.n)
    len += zx_LEN_SO_simple_elem(c,se, sizeof("cdm:PARCEL")-1, zx_ns_tab+zx_xmlns_ix_cdm);
  for (se = x->DOM; se; se = (struct zx_elem_s*)se->g.n)
    len += zx_LEN_SO_simple_elem(c,se, sizeof("cdm:DOM")-1, zx_ns_tab+zx_xmlns_ix_cdm);
  for (se = x->INTL; se; se = (struct zx_elem_s*)se->g.n)
    len += zx_LEN_SO_simple_elem(c,se, sizeof("cdm:INTL")-1, zx_ns_tab+zx_xmlns_ix_cdm);
  for (se = x->PREF; se; se = (struct zx_elem_s*)se->g.n)
    len += zx_LEN_SO_simple_elem(c,se, sizeof("cdm:PREF")-1, zx_ns_tab+zx_xmlns_ix_cdm);
  {
      struct zx_cdm_LINE_s* e;
      for (e = x->LINE; e; e = (struct zx_cdm_LINE_s*)e->gg.g.n)
	  len += zx_LEN_SO_cdm_LINE(c, e);
  }


  len += zx_len_so_common(c, &x->gg);
  zx_pop_seen(pop_seen);
  ENC_LEN_DEBUG(x, "cdm:LABEL", len);
  return len;
}

/* FUNC(zx_LEN_WO_cdm_LABEL) */

/* Compute length of an element (and its subelements). The XML attributes
 * and elements are processed in wire order and no assumptions
 * are made about namespace prefixes. */

/* Called by: */
int zx_LEN_WO_cdm_LABEL(struct zx_ctx* c, struct zx_cdm_LABEL_s* x )
{
  struct zx_ns_s* pop_seen = 0;
  struct zx_elem_s* se MAYBE_UNUSED;
#if 1 /* NORMALMODE */
  int len = 1 + sizeof("LABEL")-1 + 1 + 2 + sizeof("LABEL")-1 + 1;
  
  if (x->gg.g.ns && x->gg.g.ns->prefix_len)
    len += (x->gg.g.ns->prefix_len + 1) * 2;
  if (c->inc_ns_len)
    len += zx_len_inc_ns(c, &pop_seen);
  if (x->id)
    len += zx_len_xmlns_if_not_seen(c, x->id->g.ns, &pop_seen);
  if (x->modificationTime)
    len += zx_len_xmlns_if_not_seen(c, x->modificationTime->g.ns, &pop_seen);
  len += zx_len_xmlns_if_not_seen(c, x->gg.g.ns, &pop_seen);

  len += zx_attr_wo_len(x->id, sizeof("id")-1);
  len += zx_attr_wo_len(x->modificationTime, sizeof("modificationTime")-1);

#else
  /* root node has no begin tag */
  int len = 0;
#endif
  
  for (se = x->HOME; se; se = (struct zx_elem_s*)se->g.n)
    len += zx_LEN_WO_simple_elem(c, se, sizeof("HOME")-1);
  for (se = x->WORK; se; se = (struct zx_elem_s*)se->g.n)
    len += zx_LEN_WO_simple_elem(c, se, sizeof("WORK")-1);
  for (se = x->POSTAL; se; se = (struct zx_elem_s*)se->g.n)
    len += zx_LEN_WO_simple_elem(c, se, sizeof("POSTAL")-1);
  for (se = x->PARCEL; se; se = (struct zx_elem_s*)se->g.n)
    len += zx_LEN_WO_simple_elem(c, se, sizeof("PARCEL")-1);
  for (se = x->DOM; se; se = (struct zx_elem_s*)se->g.n)
    len += zx_LEN_WO_simple_elem(c, se, sizeof("DOM")-1);
  for (se = x->INTL; se; se = (struct zx_elem_s*)se->g.n)
    len += zx_LEN_WO_simple_elem(c, se, sizeof("INTL")-1);
  for (se = x->PREF; se; se = (struct zx_elem_s*)se->g.n)
    len += zx_LEN_WO_simple_elem(c, se, sizeof("PREF")-1);
  {
      struct zx_cdm_LINE_s* e;
      for (e = x->LINE; e; e = (struct zx_cdm_LINE_s*)e->gg.g.n)
	  len += zx_LEN_WO_cdm_LINE(c, e);
  }


  len += zx_len_wo_common(c, &x->gg); 
  zx_pop_seen(pop_seen);
  ENC_LEN_DEBUG(x, "cdm:LABEL", len);
  return len;
}

/* FUNC(zx_ENC_SO_cdm_LABEL) */

/* Render element into string. The XML attributes and elements are
 * processed in schema order. This is what you generally want for
 * rendering new data structure to a string. The wo pointers are not used. */

/* Called by: */
char* zx_ENC_SO_cdm_LABEL(struct zx_ctx* c, struct zx_cdm_LABEL_s* x, char* p )
{
  struct zx_elem_s* se MAYBE_UNUSED;
  struct zx_ns_s* pop_seen = 0;
  ENC_LEN_DEBUG_BASE;
#if 1 /* NORMALMODE */
  /* *** in simple_elem case should output ns prefix from ns node. */
  ZX_OUT_TAG(p, "<cdm:LABEL");
  if (c->inc_ns)
    p = zx_enc_inc_ns(c, p, &pop_seen);
  if (x->id || x->modificationTime)
    p = zx_enc_xmlns_if_not_seen(c, p, zx_ns_tab+zx_xmlns_ix_cb, &pop_seen);
  p = zx_enc_xmlns_if_not_seen(c, p, zx_ns_tab+zx_xmlns_ix_cdm, &pop_seen);

  p = zx_attr_so_enc(p, x->id, " cb:id=\"", sizeof(" cb:id=\"")-1);
  p = zx_attr_so_enc(p, x->modificationTime, " cb:modificationTime=\"", sizeof(" cb:modificationTime=\"")-1);

  p = zx_enc_unknown_attrs(p, x->gg.any_attr);
#else
  /* root node has no begin tag */
#endif
  
  for (se = x->HOME; se; se = (struct zx_elem_s*)se->g.n)
    p = zx_ENC_SO_simple_elem(c, se, p, "cdm:HOME", sizeof("cdm:HOME")-1, zx_ns_tab+zx_xmlns_ix_cdm);
  for (se = x->WORK; se; se = (struct zx_elem_s*)se->g.n)
    p = zx_ENC_SO_simple_elem(c, se, p, "cdm:WORK", sizeof("cdm:WORK")-1, zx_ns_tab+zx_xmlns_ix_cdm);
  for (se = x->POSTAL; se; se = (struct zx_elem_s*)se->g.n)
    p = zx_ENC_SO_simple_elem(c, se, p, "cdm:POSTAL", sizeof("cdm:POSTAL")-1, zx_ns_tab+zx_xmlns_ix_cdm);
  for (se = x->PARCEL; se; se = (struct zx_elem_s*)se->g.n)
    p = zx_ENC_SO_simple_elem(c, se, p, "cdm:PARCEL", sizeof("cdm:PARCEL")-1, zx_ns_tab+zx_xmlns_ix_cdm);
  for (se = x->DOM; se; se = (struct zx_elem_s*)se->g.n)
    p = zx_ENC_SO_simple_elem(c, se, p, "cdm:DOM", sizeof("cdm:DOM")-1, zx_ns_tab+zx_xmlns_ix_cdm);
  for (se = x->INTL; se; se = (struct zx_elem_s*)se->g.n)
    p = zx_ENC_SO_simple_elem(c, se, p, "cdm:INTL", sizeof("cdm:INTL")-1, zx_ns_tab+zx_xmlns_ix_cdm);
  for (se = x->PREF; se; se = (struct zx_elem_s*)se->g.n)
    p = zx_ENC_SO_simple_elem(c, se, p, "cdm:PREF", sizeof("cdm:PREF")-1, zx_ns_tab+zx_xmlns_ix_cdm);
  {
      struct zx_cdm_LINE_s* e;
      for (e = x->LINE; e; e = (struct zx_cdm_LINE_s*)e->gg.g.n)
	  p = zx_ENC_SO_cdm_LINE(c, e, p);
  }

  p = zx_enc_so_unknown_elems_and_content(c, p, &x->gg);
  
#if 1 /* NORMALMODE */
  ZX_OUT_CLOSE_TAG(p, "</cdm:LABEL>");
  zx_pop_seen(pop_seen);
#else
  /* root node has no end tag either */
#endif
  ENC_LEN_DEBUG(x, "cdm:LABEL", p-enc_base);
  return p;
}

/* FUNC(zx_ENC_WO_cdm_LABEL) */

/* Render element into string. The XML attributes and elements are
 * processed in wire order by chasing wo pointers. This is what you want for
 * validating signatures on other people's XML documents. */

/* Called by: */
char* zx_ENC_WO_cdm_LABEL(struct zx_ctx* c, struct zx_cdm_LABEL_s* x, char* p )
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
  ZX_OUT_MEM(p, "LABEL", sizeof("LABEL")-1);
  qq = p;

  /* *** sort the namespaces */
  if (c->inc_ns)
    zx_add_inc_ns(c, &pop_seen);
  if (x->id)
    zx_add_xmlns_if_not_seen(c, x->id->g.ns, &pop_seen);
  if (x->modificationTime)
    zx_add_xmlns_if_not_seen(c, x->modificationTime->g.ns, &pop_seen);
  zx_add_xmlns_if_not_seen(c, x->gg.g.ns, &pop_seen);

  p = zx_enc_seen(p, pop_seen); 
  p = zx_attr_wo_enc(p, x->id, "id=\"", sizeof("id=\"")-1);
  p = zx_attr_wo_enc(p, x->modificationTime, "modificationTime=\"", sizeof("modificationTime=\"")-1);

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
  ENC_LEN_DEBUG(x, "cdm:LABEL", p-enc_base);
  return p;
}

/* FUNC(zx_EASY_ENC_SO_cdm_LABEL) */

/* Called by: */
struct zx_str* zx_EASY_ENC_SO_cdm_LABEL(struct zx_ctx* c, struct zx_cdm_LABEL_s* x )
{
  int len;
  char* buf;
  c->ns_tab = ZX_ALLOC(c, sizeof(zx_ns_tab));
  memcpy(c->ns_tab, zx_ns_tab, sizeof(zx_ns_tab));
  len = zx_LEN_SO_cdm_LABEL(c, x );
  buf = ZX_ALLOC(c, len+1);
  return zx_easy_enc_common(c, zx_ENC_SO_cdm_LABEL(c, x, buf ), buf, len);
}

/* FUNC(zx_EASY_ENC_WO_cdm_LABEL) */

/* Called by: */
struct zx_str* zx_EASY_ENC_WO_cdm_LABEL(struct zx_ctx* c, struct zx_cdm_LABEL_s* x )
{
  int len;
  char* buf;
  c->ns_tab = ZX_ALLOC(c, sizeof(zx_ns_tab));
  memcpy(c->ns_tab, zx_ns_tab, sizeof(zx_ns_tab));
  len = zx_LEN_WO_cdm_LABEL(c, x );
  buf = ZX_ALLOC(c, len+1);
  return zx_easy_enc_common(c, zx_ENC_WO_cdm_LABEL(c, x, buf ), buf, len);
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

#define EL_NAME   cdm_LAT
#define EL_STRUCT zx_cdm_LAT_s
#define EL_NS     cdm
#define EL_TAG    LAT

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

/* FUNC(zx_LEN_SO_cdm_LAT) */

/* Compute length of an element (and its subelements). The XML attributes
 * and elements are processed in schema order. */

/* Called by: */
int zx_LEN_SO_cdm_LAT(struct zx_ctx* c, struct zx_cdm_LAT_s* x )
{
  struct zx_ns_s* pop_seen = 0;
  struct zx_elem_s* se MAYBE_UNUSED;
#if 1 /* NORMALMODE */
  /* *** in simple_elem case should output ns prefix from ns node. */
  int len = sizeof("<cdm:LAT")-1 + 1 + sizeof("</cdm:LAT>")-1;
  if (c->inc_ns_len)
    len += zx_len_inc_ns(c, &pop_seen);
  if (x->ACC || x->ACCTime || x->id || x->modificationTime || x->modifier)
    len += zx_len_xmlns_if_not_seen(c, zx_ns_tab+zx_xmlns_ix_cb, &pop_seen);
  len += zx_len_xmlns_if_not_seen(c, zx_ns_tab+zx_xmlns_ix_cdm, &pop_seen);

  len += zx_attr_so_len(x->ACC, sizeof("cb:ACC")-1);
  len += zx_attr_so_len(x->ACCTime, sizeof("cb:ACCTime")-1);
  len += zx_attr_so_len(x->id, sizeof("cb:id")-1);
  len += zx_attr_so_len(x->modificationTime, sizeof("cb:modificationTime")-1);
  len += zx_attr_so_len(x->modifier, sizeof("cb:modifier")-1);

#else
  /* root node has no begin tag */
  int len = 0;
#endif
  


  len += zx_len_so_common(c, &x->gg);
  zx_pop_seen(pop_seen);
  ENC_LEN_DEBUG(x, "cdm:LAT", len);
  return len;
}

/* FUNC(zx_LEN_WO_cdm_LAT) */

/* Compute length of an element (and its subelements). The XML attributes
 * and elements are processed in wire order and no assumptions
 * are made about namespace prefixes. */

/* Called by: */
int zx_LEN_WO_cdm_LAT(struct zx_ctx* c, struct zx_cdm_LAT_s* x )
{
  struct zx_ns_s* pop_seen = 0;
  struct zx_elem_s* se MAYBE_UNUSED;
#if 1 /* NORMALMODE */
  int len = 1 + sizeof("LAT")-1 + 1 + 2 + sizeof("LAT")-1 + 1;
  
  if (x->gg.g.ns && x->gg.g.ns->prefix_len)
    len += (x->gg.g.ns->prefix_len + 1) * 2;
  if (c->inc_ns_len)
    len += zx_len_inc_ns(c, &pop_seen);
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
  len += zx_len_xmlns_if_not_seen(c, x->gg.g.ns, &pop_seen);

  len += zx_attr_wo_len(x->ACC, sizeof("ACC")-1);
  len += zx_attr_wo_len(x->ACCTime, sizeof("ACCTime")-1);
  len += zx_attr_wo_len(x->id, sizeof("id")-1);
  len += zx_attr_wo_len(x->modificationTime, sizeof("modificationTime")-1);
  len += zx_attr_wo_len(x->modifier, sizeof("modifier")-1);

#else
  /* root node has no begin tag */
  int len = 0;
#endif
  


  len += zx_len_wo_common(c, &x->gg); 
  zx_pop_seen(pop_seen);
  ENC_LEN_DEBUG(x, "cdm:LAT", len);
  return len;
}

/* FUNC(zx_ENC_SO_cdm_LAT) */

/* Render element into string. The XML attributes and elements are
 * processed in schema order. This is what you generally want for
 * rendering new data structure to a string. The wo pointers are not used. */

/* Called by: */
char* zx_ENC_SO_cdm_LAT(struct zx_ctx* c, struct zx_cdm_LAT_s* x, char* p )
{
  struct zx_elem_s* se MAYBE_UNUSED;
  struct zx_ns_s* pop_seen = 0;
  ENC_LEN_DEBUG_BASE;
#if 1 /* NORMALMODE */
  /* *** in simple_elem case should output ns prefix from ns node. */
  ZX_OUT_TAG(p, "<cdm:LAT");
  if (c->inc_ns)
    p = zx_enc_inc_ns(c, p, &pop_seen);
  if (x->ACC || x->ACCTime || x->id || x->modificationTime || x->modifier)
    p = zx_enc_xmlns_if_not_seen(c, p, zx_ns_tab+zx_xmlns_ix_cb, &pop_seen);
  p = zx_enc_xmlns_if_not_seen(c, p, zx_ns_tab+zx_xmlns_ix_cdm, &pop_seen);

  p = zx_attr_so_enc(p, x->ACC, " cb:ACC=\"", sizeof(" cb:ACC=\"")-1);
  p = zx_attr_so_enc(p, x->ACCTime, " cb:ACCTime=\"", sizeof(" cb:ACCTime=\"")-1);
  p = zx_attr_so_enc(p, x->id, " cb:id=\"", sizeof(" cb:id=\"")-1);
  p = zx_attr_so_enc(p, x->modificationTime, " cb:modificationTime=\"", sizeof(" cb:modificationTime=\"")-1);
  p = zx_attr_so_enc(p, x->modifier, " cb:modifier=\"", sizeof(" cb:modifier=\"")-1);

  p = zx_enc_unknown_attrs(p, x->gg.any_attr);
#else
  /* root node has no begin tag */
#endif
  

  p = zx_enc_so_unknown_elems_and_content(c, p, &x->gg);
  
#if 1 /* NORMALMODE */
  ZX_OUT_CLOSE_TAG(p, "</cdm:LAT>");
  zx_pop_seen(pop_seen);
#else
  /* root node has no end tag either */
#endif
  ENC_LEN_DEBUG(x, "cdm:LAT", p-enc_base);
  return p;
}

/* FUNC(zx_ENC_WO_cdm_LAT) */

/* Render element into string. The XML attributes and elements are
 * processed in wire order by chasing wo pointers. This is what you want for
 * validating signatures on other people's XML documents. */

/* Called by: */
char* zx_ENC_WO_cdm_LAT(struct zx_ctx* c, struct zx_cdm_LAT_s* x, char* p )
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
  ZX_OUT_MEM(p, "LAT", sizeof("LAT")-1);
  qq = p;

  /* *** sort the namespaces */
  if (c->inc_ns)
    zx_add_inc_ns(c, &pop_seen);
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
  zx_add_xmlns_if_not_seen(c, x->gg.g.ns, &pop_seen);

  p = zx_enc_seen(p, pop_seen); 
  p = zx_attr_wo_enc(p, x->ACC, "ACC=\"", sizeof("ACC=\"")-1);
  p = zx_attr_wo_enc(p, x->ACCTime, "ACCTime=\"", sizeof("ACCTime=\"")-1);
  p = zx_attr_wo_enc(p, x->id, "id=\"", sizeof("id=\"")-1);
  p = zx_attr_wo_enc(p, x->modificationTime, "modificationTime=\"", sizeof("modificationTime=\"")-1);
  p = zx_attr_wo_enc(p, x->modifier, "modifier=\"", sizeof("modifier=\"")-1);

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
  ENC_LEN_DEBUG(x, "cdm:LAT", p-enc_base);
  return p;
}

/* FUNC(zx_EASY_ENC_SO_cdm_LAT) */

/* Called by: */
struct zx_str* zx_EASY_ENC_SO_cdm_LAT(struct zx_ctx* c, struct zx_cdm_LAT_s* x )
{
  int len;
  char* buf;
  c->ns_tab = ZX_ALLOC(c, sizeof(zx_ns_tab));
  memcpy(c->ns_tab, zx_ns_tab, sizeof(zx_ns_tab));
  len = zx_LEN_SO_cdm_LAT(c, x );
  buf = ZX_ALLOC(c, len+1);
  return zx_easy_enc_common(c, zx_ENC_SO_cdm_LAT(c, x, buf ), buf, len);
}

/* FUNC(zx_EASY_ENC_WO_cdm_LAT) */

/* Called by: */
struct zx_str* zx_EASY_ENC_WO_cdm_LAT(struct zx_ctx* c, struct zx_cdm_LAT_s* x )
{
  int len;
  char* buf;
  c->ns_tab = ZX_ALLOC(c, sizeof(zx_ns_tab));
  memcpy(c->ns_tab, zx_ns_tab, sizeof(zx_ns_tab));
  len = zx_LEN_WO_cdm_LAT(c, x );
  buf = ZX_ALLOC(c, len+1);
  return zx_easy_enc_common(c, zx_ENC_WO_cdm_LAT(c, x, buf ), buf, len);
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

#define EL_NAME   cdm_LINE
#define EL_STRUCT zx_cdm_LINE_s
#define EL_NS     cdm
#define EL_TAG    LINE

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

/* FUNC(zx_LEN_SO_cdm_LINE) */

/* Compute length of an element (and its subelements). The XML attributes
 * and elements are processed in schema order. */

/* Called by: */
int zx_LEN_SO_cdm_LINE(struct zx_ctx* c, struct zx_cdm_LINE_s* x )
{
  struct zx_ns_s* pop_seen = 0;
  struct zx_elem_s* se MAYBE_UNUSED;
#if 1 /* NORMALMODE */
  /* *** in simple_elem case should output ns prefix from ns node. */
  int len = sizeof("<cdm:LINE")-1 + 1 + sizeof("</cdm:LINE>")-1;
  if (c->inc_ns_len)
    len += zx_len_inc_ns(c, &pop_seen);
  if (x->group)
    len += zx_len_xmlns_if_not_seen(c, zx_ns_tab+zx_xmlns_ix_cb, &pop_seen);
  len += zx_len_xmlns_if_not_seen(c, zx_ns_tab+zx_xmlns_ix_cdm, &pop_seen);

  len += zx_attr_so_len(x->group, sizeof("cb:group")-1);

#else
  /* root node has no begin tag */
  int len = 0;
#endif
  


  len += zx_len_so_common(c, &x->gg);
  zx_pop_seen(pop_seen);
  ENC_LEN_DEBUG(x, "cdm:LINE", len);
  return len;
}

/* FUNC(zx_LEN_WO_cdm_LINE) */

/* Compute length of an element (and its subelements). The XML attributes
 * and elements are processed in wire order and no assumptions
 * are made about namespace prefixes. */

/* Called by: */
int zx_LEN_WO_cdm_LINE(struct zx_ctx* c, struct zx_cdm_LINE_s* x )
{
  struct zx_ns_s* pop_seen = 0;
  struct zx_elem_s* se MAYBE_UNUSED;
#if 1 /* NORMALMODE */
  int len = 1 + sizeof("LINE")-1 + 1 + 2 + sizeof("LINE")-1 + 1;
  
  if (x->gg.g.ns && x->gg.g.ns->prefix_len)
    len += (x->gg.g.ns->prefix_len + 1) * 2;
  if (c->inc_ns_len)
    len += zx_len_inc_ns(c, &pop_seen);
  if (x->group)
    len += zx_len_xmlns_if_not_seen(c, x->group->g.ns, &pop_seen);
  len += zx_len_xmlns_if_not_seen(c, x->gg.g.ns, &pop_seen);

  len += zx_attr_wo_len(x->group, sizeof("group")-1);

#else
  /* root node has no begin tag */
  int len = 0;
#endif
  


  len += zx_len_wo_common(c, &x->gg); 
  zx_pop_seen(pop_seen);
  ENC_LEN_DEBUG(x, "cdm:LINE", len);
  return len;
}

/* FUNC(zx_ENC_SO_cdm_LINE) */

/* Render element into string. The XML attributes and elements are
 * processed in schema order. This is what you generally want for
 * rendering new data structure to a string. The wo pointers are not used. */

/* Called by: */
char* zx_ENC_SO_cdm_LINE(struct zx_ctx* c, struct zx_cdm_LINE_s* x, char* p )
{
  struct zx_elem_s* se MAYBE_UNUSED;
  struct zx_ns_s* pop_seen = 0;
  ENC_LEN_DEBUG_BASE;
#if 1 /* NORMALMODE */
  /* *** in simple_elem case should output ns prefix from ns node. */
  ZX_OUT_TAG(p, "<cdm:LINE");
  if (c->inc_ns)
    p = zx_enc_inc_ns(c, p, &pop_seen);
  if (x->group)
    p = zx_enc_xmlns_if_not_seen(c, p, zx_ns_tab+zx_xmlns_ix_cb, &pop_seen);
  p = zx_enc_xmlns_if_not_seen(c, p, zx_ns_tab+zx_xmlns_ix_cdm, &pop_seen);

  p = zx_attr_so_enc(p, x->group, " cb:group=\"", sizeof(" cb:group=\"")-1);

  p = zx_enc_unknown_attrs(p, x->gg.any_attr);
#else
  /* root node has no begin tag */
#endif
  

  p = zx_enc_so_unknown_elems_and_content(c, p, &x->gg);
  
#if 1 /* NORMALMODE */
  ZX_OUT_CLOSE_TAG(p, "</cdm:LINE>");
  zx_pop_seen(pop_seen);
#else
  /* root node has no end tag either */
#endif
  ENC_LEN_DEBUG(x, "cdm:LINE", p-enc_base);
  return p;
}

/* FUNC(zx_ENC_WO_cdm_LINE) */

/* Render element into string. The XML attributes and elements are
 * processed in wire order by chasing wo pointers. This is what you want for
 * validating signatures on other people's XML documents. */

/* Called by: */
char* zx_ENC_WO_cdm_LINE(struct zx_ctx* c, struct zx_cdm_LINE_s* x, char* p )
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
  ZX_OUT_MEM(p, "LINE", sizeof("LINE")-1);
  qq = p;

  /* *** sort the namespaces */
  if (c->inc_ns)
    zx_add_inc_ns(c, &pop_seen);
  if (x->group)
    zx_add_xmlns_if_not_seen(c, x->group->g.ns, &pop_seen);
  zx_add_xmlns_if_not_seen(c, x->gg.g.ns, &pop_seen);

  p = zx_enc_seen(p, pop_seen); 
  p = zx_attr_wo_enc(p, x->group, "group=\"", sizeof("group=\"")-1);

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
  ENC_LEN_DEBUG(x, "cdm:LINE", p-enc_base);
  return p;
}

/* FUNC(zx_EASY_ENC_SO_cdm_LINE) */

/* Called by: */
struct zx_str* zx_EASY_ENC_SO_cdm_LINE(struct zx_ctx* c, struct zx_cdm_LINE_s* x )
{
  int len;
  char* buf;
  c->ns_tab = ZX_ALLOC(c, sizeof(zx_ns_tab));
  memcpy(c->ns_tab, zx_ns_tab, sizeof(zx_ns_tab));
  len = zx_LEN_SO_cdm_LINE(c, x );
  buf = ZX_ALLOC(c, len+1);
  return zx_easy_enc_common(c, zx_ENC_SO_cdm_LINE(c, x, buf ), buf, len);
}

/* FUNC(zx_EASY_ENC_WO_cdm_LINE) */

/* Called by: */
struct zx_str* zx_EASY_ENC_WO_cdm_LINE(struct zx_ctx* c, struct zx_cdm_LINE_s* x )
{
  int len;
  char* buf;
  c->ns_tab = ZX_ALLOC(c, sizeof(zx_ns_tab));
  memcpy(c->ns_tab, zx_ns_tab, sizeof(zx_ns_tab));
  len = zx_LEN_WO_cdm_LINE(c, x );
  buf = ZX_ALLOC(c, len+1);
  return zx_easy_enc_common(c, zx_ENC_WO_cdm_LINE(c, x, buf ), buf, len);
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

#define EL_NAME   cdm_LISTMEMBER
#define EL_STRUCT zx_cdm_LISTMEMBER_s
#define EL_NS     cdm
#define EL_TAG    LISTMEMBER

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

/* FUNC(zx_LEN_SO_cdm_LISTMEMBER) */

/* Compute length of an element (and its subelements). The XML attributes
 * and elements are processed in schema order. */

/* Called by: */
int zx_LEN_SO_cdm_LISTMEMBER(struct zx_ctx* c, struct zx_cdm_LISTMEMBER_s* x )
{
  struct zx_ns_s* pop_seen = 0;
  struct zx_elem_s* se MAYBE_UNUSED;
#if 1 /* NORMALMODE */
  /* *** in simple_elem case should output ns prefix from ns node. */
  int len = sizeof("<cdm:LISTMEMBER")-1 + 1 + sizeof("</cdm:LISTMEMBER>")-1;
  if (c->inc_ns_len)
    len += zx_len_inc_ns(c, &pop_seen);
  if (x->ACC || x->ACCTime || x->id || x->modificationTime || x->modifier)
    len += zx_len_xmlns_if_not_seen(c, zx_ns_tab+zx_xmlns_ix_cb, &pop_seen);
  len += zx_len_xmlns_if_not_seen(c, zx_ns_tab+zx_xmlns_ix_cdm, &pop_seen);

  len += zx_attr_so_len(x->ACC, sizeof("cb:ACC")-1);
  len += zx_attr_so_len(x->ACCTime, sizeof("cb:ACCTime")-1);
  len += zx_attr_so_len(x->id, sizeof("cb:id")-1);
  len += zx_attr_so_len(x->modificationTime, sizeof("cb:modificationTime")-1);
  len += zx_attr_so_len(x->modifier, sizeof("cb:modifier")-1);

#else
  /* root node has no begin tag */
  int len = 0;
#endif
  


  len += zx_len_so_common(c, &x->gg);
  zx_pop_seen(pop_seen);
  ENC_LEN_DEBUG(x, "cdm:LISTMEMBER", len);
  return len;
}

/* FUNC(zx_LEN_WO_cdm_LISTMEMBER) */

/* Compute length of an element (and its subelements). The XML attributes
 * and elements are processed in wire order and no assumptions
 * are made about namespace prefixes. */

/* Called by: */
int zx_LEN_WO_cdm_LISTMEMBER(struct zx_ctx* c, struct zx_cdm_LISTMEMBER_s* x )
{
  struct zx_ns_s* pop_seen = 0;
  struct zx_elem_s* se MAYBE_UNUSED;
#if 1 /* NORMALMODE */
  int len = 1 + sizeof("LISTMEMBER")-1 + 1 + 2 + sizeof("LISTMEMBER")-1 + 1;
  
  if (x->gg.g.ns && x->gg.g.ns->prefix_len)
    len += (x->gg.g.ns->prefix_len + 1) * 2;
  if (c->inc_ns_len)
    len += zx_len_inc_ns(c, &pop_seen);
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
  len += zx_len_xmlns_if_not_seen(c, x->gg.g.ns, &pop_seen);

  len += zx_attr_wo_len(x->ACC, sizeof("ACC")-1);
  len += zx_attr_wo_len(x->ACCTime, sizeof("ACCTime")-1);
  len += zx_attr_wo_len(x->id, sizeof("id")-1);
  len += zx_attr_wo_len(x->modificationTime, sizeof("modificationTime")-1);
  len += zx_attr_wo_len(x->modifier, sizeof("modifier")-1);

#else
  /* root node has no begin tag */
  int len = 0;
#endif
  


  len += zx_len_wo_common(c, &x->gg); 
  zx_pop_seen(pop_seen);
  ENC_LEN_DEBUG(x, "cdm:LISTMEMBER", len);
  return len;
}

/* FUNC(zx_ENC_SO_cdm_LISTMEMBER) */

/* Render element into string. The XML attributes and elements are
 * processed in schema order. This is what you generally want for
 * rendering new data structure to a string. The wo pointers are not used. */

/* Called by: */
char* zx_ENC_SO_cdm_LISTMEMBER(struct zx_ctx* c, struct zx_cdm_LISTMEMBER_s* x, char* p )
{
  struct zx_elem_s* se MAYBE_UNUSED;
  struct zx_ns_s* pop_seen = 0;
  ENC_LEN_DEBUG_BASE;
#if 1 /* NORMALMODE */
  /* *** in simple_elem case should output ns prefix from ns node. */
  ZX_OUT_TAG(p, "<cdm:LISTMEMBER");
  if (c->inc_ns)
    p = zx_enc_inc_ns(c, p, &pop_seen);
  if (x->ACC || x->ACCTime || x->id || x->modificationTime || x->modifier)
    p = zx_enc_xmlns_if_not_seen(c, p, zx_ns_tab+zx_xmlns_ix_cb, &pop_seen);
  p = zx_enc_xmlns_if_not_seen(c, p, zx_ns_tab+zx_xmlns_ix_cdm, &pop_seen);

  p = zx_attr_so_enc(p, x->ACC, " cb:ACC=\"", sizeof(" cb:ACC=\"")-1);
  p = zx_attr_so_enc(p, x->ACCTime, " cb:ACCTime=\"", sizeof(" cb:ACCTime=\"")-1);
  p = zx_attr_so_enc(p, x->id, " cb:id=\"", sizeof(" cb:id=\"")-1);
  p = zx_attr_so_enc(p, x->modificationTime, " cb:modificationTime=\"", sizeof(" cb:modificationTime=\"")-1);
  p = zx_attr_so_enc(p, x->modifier, " cb:modifier=\"", sizeof(" cb:modifier=\"")-1);

  p = zx_enc_unknown_attrs(p, x->gg.any_attr);
#else
  /* root node has no begin tag */
#endif
  

  p = zx_enc_so_unknown_elems_and_content(c, p, &x->gg);
  
#if 1 /* NORMALMODE */
  ZX_OUT_CLOSE_TAG(p, "</cdm:LISTMEMBER>");
  zx_pop_seen(pop_seen);
#else
  /* root node has no end tag either */
#endif
  ENC_LEN_DEBUG(x, "cdm:LISTMEMBER", p-enc_base);
  return p;
}

/* FUNC(zx_ENC_WO_cdm_LISTMEMBER) */

/* Render element into string. The XML attributes and elements are
 * processed in wire order by chasing wo pointers. This is what you want for
 * validating signatures on other people's XML documents. */

/* Called by: */
char* zx_ENC_WO_cdm_LISTMEMBER(struct zx_ctx* c, struct zx_cdm_LISTMEMBER_s* x, char* p )
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
  ZX_OUT_MEM(p, "LISTMEMBER", sizeof("LISTMEMBER")-1);
  qq = p;

  /* *** sort the namespaces */
  if (c->inc_ns)
    zx_add_inc_ns(c, &pop_seen);
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
  zx_add_xmlns_if_not_seen(c, x->gg.g.ns, &pop_seen);

  p = zx_enc_seen(p, pop_seen); 
  p = zx_attr_wo_enc(p, x->ACC, "ACC=\"", sizeof("ACC=\"")-1);
  p = zx_attr_wo_enc(p, x->ACCTime, "ACCTime=\"", sizeof("ACCTime=\"")-1);
  p = zx_attr_wo_enc(p, x->id, "id=\"", sizeof("id=\"")-1);
  p = zx_attr_wo_enc(p, x->modificationTime, "modificationTime=\"", sizeof("modificationTime=\"")-1);
  p = zx_attr_wo_enc(p, x->modifier, "modifier=\"", sizeof("modifier=\"")-1);

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
  ENC_LEN_DEBUG(x, "cdm:LISTMEMBER", p-enc_base);
  return p;
}

/* FUNC(zx_EASY_ENC_SO_cdm_LISTMEMBER) */

/* Called by: */
struct zx_str* zx_EASY_ENC_SO_cdm_LISTMEMBER(struct zx_ctx* c, struct zx_cdm_LISTMEMBER_s* x )
{
  int len;
  char* buf;
  c->ns_tab = ZX_ALLOC(c, sizeof(zx_ns_tab));
  memcpy(c->ns_tab, zx_ns_tab, sizeof(zx_ns_tab));
  len = zx_LEN_SO_cdm_LISTMEMBER(c, x );
  buf = ZX_ALLOC(c, len+1);
  return zx_easy_enc_common(c, zx_ENC_SO_cdm_LISTMEMBER(c, x, buf ), buf, len);
}

/* FUNC(zx_EASY_ENC_WO_cdm_LISTMEMBER) */

/* Called by: */
struct zx_str* zx_EASY_ENC_WO_cdm_LISTMEMBER(struct zx_ctx* c, struct zx_cdm_LISTMEMBER_s* x )
{
  int len;
  char* buf;
  c->ns_tab = ZX_ALLOC(c, sizeof(zx_ns_tab));
  memcpy(c->ns_tab, zx_ns_tab, sizeof(zx_ns_tab));
  len = zx_LEN_WO_cdm_LISTMEMBER(c, x );
  buf = ZX_ALLOC(c, len+1);
  return zx_easy_enc_common(c, zx_ENC_WO_cdm_LISTMEMBER(c, x, buf ), buf, len);
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

#define EL_NAME   cdm_LOCALITY
#define EL_STRUCT zx_cdm_LOCALITY_s
#define EL_NS     cdm
#define EL_TAG    LOCALITY

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

/* FUNC(zx_LEN_SO_cdm_LOCALITY) */

/* Compute length of an element (and its subelements). The XML attributes
 * and elements are processed in schema order. */

/* Called by: */
int zx_LEN_SO_cdm_LOCALITY(struct zx_ctx* c, struct zx_cdm_LOCALITY_s* x )
{
  struct zx_ns_s* pop_seen = 0;
  struct zx_elem_s* se MAYBE_UNUSED;
#if 1 /* NORMALMODE */
  /* *** in simple_elem case should output ns prefix from ns node. */
  int len = sizeof("<cdm:LOCALITY")-1 + 1 + sizeof("</cdm:LOCALITY>")-1;
  if (c->inc_ns_len)
    len += zx_len_inc_ns(c, &pop_seen);
  if (x->group)
    len += zx_len_xmlns_if_not_seen(c, zx_ns_tab+zx_xmlns_ix_cb, &pop_seen);
  len += zx_len_xmlns_if_not_seen(c, zx_ns_tab+zx_xmlns_ix_cdm, &pop_seen);

  len += zx_attr_so_len(x->group, sizeof("cb:group")-1);

#else
  /* root node has no begin tag */
  int len = 0;
#endif
  


  len += zx_len_so_common(c, &x->gg);
  zx_pop_seen(pop_seen);
  ENC_LEN_DEBUG(x, "cdm:LOCALITY", len);
  return len;
}

/* FUNC(zx_LEN_WO_cdm_LOCALITY) */

/* Compute length of an element (and its subelements). The XML attributes
 * and elements are processed in wire order and no assumptions
 * are made about namespace prefixes. */

/* Called by: */
int zx_LEN_WO_cdm_LOCALITY(struct zx_ctx* c, struct zx_cdm_LOCALITY_s* x )
{
  struct zx_ns_s* pop_seen = 0;
  struct zx_elem_s* se MAYBE_UNUSED;
#if 1 /* NORMALMODE */
  int len = 1 + sizeof("LOCALITY")-1 + 1 + 2 + sizeof("LOCALITY")-1 + 1;
  
  if (x->gg.g.ns && x->gg.g.ns->prefix_len)
    len += (x->gg.g.ns->prefix_len + 1) * 2;
  if (c->inc_ns_len)
    len += zx_len_inc_ns(c, &pop_seen);
  if (x->group)
    len += zx_len_xmlns_if_not_seen(c, x->group->g.ns, &pop_seen);
  len += zx_len_xmlns_if_not_seen(c, x->gg.g.ns, &pop_seen);

  len += zx_attr_wo_len(x->group, sizeof("group")-1);

#else
  /* root node has no begin tag */
  int len = 0;
#endif
  


  len += zx_len_wo_common(c, &x->gg); 
  zx_pop_seen(pop_seen);
  ENC_LEN_DEBUG(x, "cdm:LOCALITY", len);
  return len;
}

/* FUNC(zx_ENC_SO_cdm_LOCALITY) */

/* Render element into string. The XML attributes and elements are
 * processed in schema order. This is what you generally want for
 * rendering new data structure to a string. The wo pointers are not used. */

/* Called by: */
char* zx_ENC_SO_cdm_LOCALITY(struct zx_ctx* c, struct zx_cdm_LOCALITY_s* x, char* p )
{
  struct zx_elem_s* se MAYBE_UNUSED;
  struct zx_ns_s* pop_seen = 0;
  ENC_LEN_DEBUG_BASE;
#if 1 /* NORMALMODE */
  /* *** in simple_elem case should output ns prefix from ns node. */
  ZX_OUT_TAG(p, "<cdm:LOCALITY");
  if (c->inc_ns)
    p = zx_enc_inc_ns(c, p, &pop_seen);
  if (x->group)
    p = zx_enc_xmlns_if_not_seen(c, p, zx_ns_tab+zx_xmlns_ix_cb, &pop_seen);
  p = zx_enc_xmlns_if_not_seen(c, p, zx_ns_tab+zx_xmlns_ix_cdm, &pop_seen);

  p = zx_attr_so_enc(p, x->group, " cb:group=\"", sizeof(" cb:group=\"")-1);

  p = zx_enc_unknown_attrs(p, x->gg.any_attr);
#else
  /* root node has no begin tag */
#endif
  

  p = zx_enc_so_unknown_elems_and_content(c, p, &x->gg);
  
#if 1 /* NORMALMODE */
  ZX_OUT_CLOSE_TAG(p, "</cdm:LOCALITY>");
  zx_pop_seen(pop_seen);
#else
  /* root node has no end tag either */
#endif
  ENC_LEN_DEBUG(x, "cdm:LOCALITY", p-enc_base);
  return p;
}

/* FUNC(zx_ENC_WO_cdm_LOCALITY) */

/* Render element into string. The XML attributes and elements are
 * processed in wire order by chasing wo pointers. This is what you want for
 * validating signatures on other people's XML documents. */

/* Called by: */
char* zx_ENC_WO_cdm_LOCALITY(struct zx_ctx* c, struct zx_cdm_LOCALITY_s* x, char* p )
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
  ZX_OUT_MEM(p, "LOCALITY", sizeof("LOCALITY")-1);
  qq = p;

  /* *** sort the namespaces */
  if (c->inc_ns)
    zx_add_inc_ns(c, &pop_seen);
  if (x->group)
    zx_add_xmlns_if_not_seen(c, x->group->g.ns, &pop_seen);
  zx_add_xmlns_if_not_seen(c, x->gg.g.ns, &pop_seen);

  p = zx_enc_seen(p, pop_seen); 
  p = zx_attr_wo_enc(p, x->group, "group=\"", sizeof("group=\"")-1);

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
  ENC_LEN_DEBUG(x, "cdm:LOCALITY", p-enc_base);
  return p;
}

/* FUNC(zx_EASY_ENC_SO_cdm_LOCALITY) */

/* Called by: */
struct zx_str* zx_EASY_ENC_SO_cdm_LOCALITY(struct zx_ctx* c, struct zx_cdm_LOCALITY_s* x )
{
  int len;
  char* buf;
  c->ns_tab = ZX_ALLOC(c, sizeof(zx_ns_tab));
  memcpy(c->ns_tab, zx_ns_tab, sizeof(zx_ns_tab));
  len = zx_LEN_SO_cdm_LOCALITY(c, x );
  buf = ZX_ALLOC(c, len+1);
  return zx_easy_enc_common(c, zx_ENC_SO_cdm_LOCALITY(c, x, buf ), buf, len);
}

/* FUNC(zx_EASY_ENC_WO_cdm_LOCALITY) */

/* Called by: */
struct zx_str* zx_EASY_ENC_WO_cdm_LOCALITY(struct zx_ctx* c, struct zx_cdm_LOCALITY_s* x )
{
  int len;
  char* buf;
  c->ns_tab = ZX_ALLOC(c, sizeof(zx_ns_tab));
  memcpy(c->ns_tab, zx_ns_tab, sizeof(zx_ns_tab));
  len = zx_LEN_WO_cdm_LOCALITY(c, x );
  buf = ZX_ALLOC(c, len+1);
  return zx_easy_enc_common(c, zx_ENC_WO_cdm_LOCALITY(c, x, buf ), buf, len);
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

#define EL_NAME   cdm_LOGO
#define EL_STRUCT zx_cdm_LOGO_s
#define EL_NS     cdm
#define EL_TAG    LOGO

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

/* FUNC(zx_LEN_SO_cdm_LOGO) */

/* Compute length of an element (and its subelements). The XML attributes
 * and elements are processed in schema order. */

/* Called by: */
int zx_LEN_SO_cdm_LOGO(struct zx_ctx* c, struct zx_cdm_LOGO_s* x )
{
  struct zx_ns_s* pop_seen = 0;
  struct zx_elem_s* se MAYBE_UNUSED;
#if 1 /* NORMALMODE */
  /* *** in simple_elem case should output ns prefix from ns node. */
  int len = sizeof("<cdm:LOGO")-1 + 1 + sizeof("</cdm:LOGO>")-1;
  if (c->inc_ns_len)
    len += zx_len_inc_ns(c, &pop_seen);
  if (x->id || x->modificationTime)
    len += zx_len_xmlns_if_not_seen(c, zx_ns_tab+zx_xmlns_ix_cb, &pop_seen);
  len += zx_len_xmlns_if_not_seen(c, zx_ns_tab+zx_xmlns_ix_cdm, &pop_seen);

  len += zx_attr_so_len(x->id, sizeof("cb:id")-1);
  len += zx_attr_so_len(x->modificationTime, sizeof("cb:modificationTime")-1);

#else
  /* root node has no begin tag */
  int len = 0;
#endif
  
  {
      struct zx_cdm_TYPE_s* e;
      for (e = x->TYPE; e; e = (struct zx_cdm_TYPE_s*)e->gg.g.n)
	  len += zx_LEN_SO_cdm_TYPE(c, e);
  }
  {
      struct zx_cdm_BINVAL_s* e;
      for (e = x->BINVAL; e; e = (struct zx_cdm_BINVAL_s*)e->gg.g.n)
	  len += zx_LEN_SO_cdm_BINVAL(c, e);
  }
  {
      struct zx_cdm_EXTVAL_s* e;
      for (e = x->EXTVAL; e; e = (struct zx_cdm_EXTVAL_s*)e->gg.g.n)
	  len += zx_LEN_SO_cdm_EXTVAL(c, e);
  }


  len += zx_len_so_common(c, &x->gg);
  zx_pop_seen(pop_seen);
  ENC_LEN_DEBUG(x, "cdm:LOGO", len);
  return len;
}

/* FUNC(zx_LEN_WO_cdm_LOGO) */

/* Compute length of an element (and its subelements). The XML attributes
 * and elements are processed in wire order and no assumptions
 * are made about namespace prefixes. */

/* Called by: */
int zx_LEN_WO_cdm_LOGO(struct zx_ctx* c, struct zx_cdm_LOGO_s* x )
{
  struct zx_ns_s* pop_seen = 0;
  struct zx_elem_s* se MAYBE_UNUSED;
#if 1 /* NORMALMODE */
  int len = 1 + sizeof("LOGO")-1 + 1 + 2 + sizeof("LOGO")-1 + 1;
  
  if (x->gg.g.ns && x->gg.g.ns->prefix_len)
    len += (x->gg.g.ns->prefix_len + 1) * 2;
  if (c->inc_ns_len)
    len += zx_len_inc_ns(c, &pop_seen);
  if (x->id)
    len += zx_len_xmlns_if_not_seen(c, x->id->g.ns, &pop_seen);
  if (x->modificationTime)
    len += zx_len_xmlns_if_not_seen(c, x->modificationTime->g.ns, &pop_seen);
  len += zx_len_xmlns_if_not_seen(c, x->gg.g.ns, &pop_seen);

  len += zx_attr_wo_len(x->id, sizeof("id")-1);
  len += zx_attr_wo_len(x->modificationTime, sizeof("modificationTime")-1);

#else
  /* root node has no begin tag */
  int len = 0;
#endif
  
  {
      struct zx_cdm_TYPE_s* e;
      for (e = x->TYPE; e; e = (struct zx_cdm_TYPE_s*)e->gg.g.n)
	  len += zx_LEN_WO_cdm_TYPE(c, e);
  }
  {
      struct zx_cdm_BINVAL_s* e;
      for (e = x->BINVAL; e; e = (struct zx_cdm_BINVAL_s*)e->gg.g.n)
	  len += zx_LEN_WO_cdm_BINVAL(c, e);
  }
  {
      struct zx_cdm_EXTVAL_s* e;
      for (e = x->EXTVAL; e; e = (struct zx_cdm_EXTVAL_s*)e->gg.g.n)
	  len += zx_LEN_WO_cdm_EXTVAL(c, e);
  }


  len += zx_len_wo_common(c, &x->gg); 
  zx_pop_seen(pop_seen);
  ENC_LEN_DEBUG(x, "cdm:LOGO", len);
  return len;
}

/* FUNC(zx_ENC_SO_cdm_LOGO) */

/* Render element into string. The XML attributes and elements are
 * processed in schema order. This is what you generally want for
 * rendering new data structure to a string. The wo pointers are not used. */

/* Called by: */
char* zx_ENC_SO_cdm_LOGO(struct zx_ctx* c, struct zx_cdm_LOGO_s* x, char* p )
{
  struct zx_elem_s* se MAYBE_UNUSED;
  struct zx_ns_s* pop_seen = 0;
  ENC_LEN_DEBUG_BASE;
#if 1 /* NORMALMODE */
  /* *** in simple_elem case should output ns prefix from ns node. */
  ZX_OUT_TAG(p, "<cdm:LOGO");
  if (c->inc_ns)
    p = zx_enc_inc_ns(c, p, &pop_seen);
  if (x->id || x->modificationTime)
    p = zx_enc_xmlns_if_not_seen(c, p, zx_ns_tab+zx_xmlns_ix_cb, &pop_seen);
  p = zx_enc_xmlns_if_not_seen(c, p, zx_ns_tab+zx_xmlns_ix_cdm, &pop_seen);

  p = zx_attr_so_enc(p, x->id, " cb:id=\"", sizeof(" cb:id=\"")-1);
  p = zx_attr_so_enc(p, x->modificationTime, " cb:modificationTime=\"", sizeof(" cb:modificationTime=\"")-1);

  p = zx_enc_unknown_attrs(p, x->gg.any_attr);
#else
  /* root node has no begin tag */
#endif
  
  {
      struct zx_cdm_TYPE_s* e;
      for (e = x->TYPE; e; e = (struct zx_cdm_TYPE_s*)e->gg.g.n)
	  p = zx_ENC_SO_cdm_TYPE(c, e, p);
  }
  {
      struct zx_cdm_BINVAL_s* e;
      for (e = x->BINVAL; e; e = (struct zx_cdm_BINVAL_s*)e->gg.g.n)
	  p = zx_ENC_SO_cdm_BINVAL(c, e, p);
  }
  {
      struct zx_cdm_EXTVAL_s* e;
      for (e = x->EXTVAL; e; e = (struct zx_cdm_EXTVAL_s*)e->gg.g.n)
	  p = zx_ENC_SO_cdm_EXTVAL(c, e, p);
  }

  p = zx_enc_so_unknown_elems_and_content(c, p, &x->gg);
  
#if 1 /* NORMALMODE */
  ZX_OUT_CLOSE_TAG(p, "</cdm:LOGO>");
  zx_pop_seen(pop_seen);
#else
  /* root node has no end tag either */
#endif
  ENC_LEN_DEBUG(x, "cdm:LOGO", p-enc_base);
  return p;
}

/* FUNC(zx_ENC_WO_cdm_LOGO) */

/* Render element into string. The XML attributes and elements are
 * processed in wire order by chasing wo pointers. This is what you want for
 * validating signatures on other people's XML documents. */

/* Called by: */
char* zx_ENC_WO_cdm_LOGO(struct zx_ctx* c, struct zx_cdm_LOGO_s* x, char* p )
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
  ZX_OUT_MEM(p, "LOGO", sizeof("LOGO")-1);
  qq = p;

  /* *** sort the namespaces */
  if (c->inc_ns)
    zx_add_inc_ns(c, &pop_seen);
  if (x->id)
    zx_add_xmlns_if_not_seen(c, x->id->g.ns, &pop_seen);
  if (x->modificationTime)
    zx_add_xmlns_if_not_seen(c, x->modificationTime->g.ns, &pop_seen);
  zx_add_xmlns_if_not_seen(c, x->gg.g.ns, &pop_seen);

  p = zx_enc_seen(p, pop_seen); 
  p = zx_attr_wo_enc(p, x->id, "id=\"", sizeof("id=\"")-1);
  p = zx_attr_wo_enc(p, x->modificationTime, "modificationTime=\"", sizeof("modificationTime=\"")-1);

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
  ENC_LEN_DEBUG(x, "cdm:LOGO", p-enc_base);
  return p;
}

/* FUNC(zx_EASY_ENC_SO_cdm_LOGO) */

/* Called by: */
struct zx_str* zx_EASY_ENC_SO_cdm_LOGO(struct zx_ctx* c, struct zx_cdm_LOGO_s* x )
{
  int len;
  char* buf;
  c->ns_tab = ZX_ALLOC(c, sizeof(zx_ns_tab));
  memcpy(c->ns_tab, zx_ns_tab, sizeof(zx_ns_tab));
  len = zx_LEN_SO_cdm_LOGO(c, x );
  buf = ZX_ALLOC(c, len+1);
  return zx_easy_enc_common(c, zx_ENC_SO_cdm_LOGO(c, x, buf ), buf, len);
}

/* FUNC(zx_EASY_ENC_WO_cdm_LOGO) */

/* Called by: */
struct zx_str* zx_EASY_ENC_WO_cdm_LOGO(struct zx_ctx* c, struct zx_cdm_LOGO_s* x )
{
  int len;
  char* buf;
  c->ns_tab = ZX_ALLOC(c, sizeof(zx_ns_tab));
  memcpy(c->ns_tab, zx_ns_tab, sizeof(zx_ns_tab));
  len = zx_LEN_WO_cdm_LOGO(c, x );
  buf = ZX_ALLOC(c, len+1);
  return zx_easy_enc_common(c, zx_ENC_WO_cdm_LOGO(c, x, buf ), buf, len);
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

#define EL_NAME   cdm_LON
#define EL_STRUCT zx_cdm_LON_s
#define EL_NS     cdm
#define EL_TAG    LON

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

/* FUNC(zx_LEN_SO_cdm_LON) */

/* Compute length of an element (and its subelements). The XML attributes
 * and elements are processed in schema order. */

/* Called by: */
int zx_LEN_SO_cdm_LON(struct zx_ctx* c, struct zx_cdm_LON_s* x )
{
  struct zx_ns_s* pop_seen = 0;
  struct zx_elem_s* se MAYBE_UNUSED;
#if 1 /* NORMALMODE */
  /* *** in simple_elem case should output ns prefix from ns node. */
  int len = sizeof("<cdm:LON")-1 + 1 + sizeof("</cdm:LON>")-1;
  if (c->inc_ns_len)
    len += zx_len_inc_ns(c, &pop_seen);
  if (x->ACC || x->ACCTime || x->id || x->modificationTime || x->modifier)
    len += zx_len_xmlns_if_not_seen(c, zx_ns_tab+zx_xmlns_ix_cb, &pop_seen);
  len += zx_len_xmlns_if_not_seen(c, zx_ns_tab+zx_xmlns_ix_cdm, &pop_seen);

  len += zx_attr_so_len(x->ACC, sizeof("cb:ACC")-1);
  len += zx_attr_so_len(x->ACCTime, sizeof("cb:ACCTime")-1);
  len += zx_attr_so_len(x->id, sizeof("cb:id")-1);
  len += zx_attr_so_len(x->modificationTime, sizeof("cb:modificationTime")-1);
  len += zx_attr_so_len(x->modifier, sizeof("cb:modifier")-1);

#else
  /* root node has no begin tag */
  int len = 0;
#endif
  


  len += zx_len_so_common(c, &x->gg);
  zx_pop_seen(pop_seen);
  ENC_LEN_DEBUG(x, "cdm:LON", len);
  return len;
}

/* FUNC(zx_LEN_WO_cdm_LON) */

/* Compute length of an element (and its subelements). The XML attributes
 * and elements are processed in wire order and no assumptions
 * are made about namespace prefixes. */

/* Called by: */
int zx_LEN_WO_cdm_LON(struct zx_ctx* c, struct zx_cdm_LON_s* x )
{
  struct zx_ns_s* pop_seen = 0;
  struct zx_elem_s* se MAYBE_UNUSED;
#if 1 /* NORMALMODE */
  int len = 1 + sizeof("LON")-1 + 1 + 2 + sizeof("LON")-1 + 1;
  
  if (x->gg.g.ns && x->gg.g.ns->prefix_len)
    len += (x->gg.g.ns->prefix_len + 1) * 2;
  if (c->inc_ns_len)
    len += zx_len_inc_ns(c, &pop_seen);
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
  len += zx_len_xmlns_if_not_seen(c, x->gg.g.ns, &pop_seen);

  len += zx_attr_wo_len(x->ACC, sizeof("ACC")-1);
  len += zx_attr_wo_len(x->ACCTime, sizeof("ACCTime")-1);
  len += zx_attr_wo_len(x->id, sizeof("id")-1);
  len += zx_attr_wo_len(x->modificationTime, sizeof("modificationTime")-1);
  len += zx_attr_wo_len(x->modifier, sizeof("modifier")-1);

#else
  /* root node has no begin tag */
  int len = 0;
#endif
  


  len += zx_len_wo_common(c, &x->gg); 
  zx_pop_seen(pop_seen);
  ENC_LEN_DEBUG(x, "cdm:LON", len);
  return len;
}

/* FUNC(zx_ENC_SO_cdm_LON) */

/* Render element into string. The XML attributes and elements are
 * processed in schema order. This is what you generally want for
 * rendering new data structure to a string. The wo pointers are not used. */

/* Called by: */
char* zx_ENC_SO_cdm_LON(struct zx_ctx* c, struct zx_cdm_LON_s* x, char* p )
{
  struct zx_elem_s* se MAYBE_UNUSED;
  struct zx_ns_s* pop_seen = 0;
  ENC_LEN_DEBUG_BASE;
#if 1 /* NORMALMODE */
  /* *** in simple_elem case should output ns prefix from ns node. */
  ZX_OUT_TAG(p, "<cdm:LON");
  if (c->inc_ns)
    p = zx_enc_inc_ns(c, p, &pop_seen);
  if (x->ACC || x->ACCTime || x->id || x->modificationTime || x->modifier)
    p = zx_enc_xmlns_if_not_seen(c, p, zx_ns_tab+zx_xmlns_ix_cb, &pop_seen);
  p = zx_enc_xmlns_if_not_seen(c, p, zx_ns_tab+zx_xmlns_ix_cdm, &pop_seen);

  p = zx_attr_so_enc(p, x->ACC, " cb:ACC=\"", sizeof(" cb:ACC=\"")-1);
  p = zx_attr_so_enc(p, x->ACCTime, " cb:ACCTime=\"", sizeof(" cb:ACCTime=\"")-1);
  p = zx_attr_so_enc(p, x->id, " cb:id=\"", sizeof(" cb:id=\"")-1);
  p = zx_attr_so_enc(p, x->modificationTime, " cb:modificationTime=\"", sizeof(" cb:modificationTime=\"")-1);
  p = zx_attr_so_enc(p, x->modifier, " cb:modifier=\"", sizeof(" cb:modifier=\"")-1);

  p = zx_enc_unknown_attrs(p, x->gg.any_attr);
#else
  /* root node has no begin tag */
#endif
  

  p = zx_enc_so_unknown_elems_and_content(c, p, &x->gg);
  
#if 1 /* NORMALMODE */
  ZX_OUT_CLOSE_TAG(p, "</cdm:LON>");
  zx_pop_seen(pop_seen);
#else
  /* root node has no end tag either */
#endif
  ENC_LEN_DEBUG(x, "cdm:LON", p-enc_base);
  return p;
}

/* FUNC(zx_ENC_WO_cdm_LON) */

/* Render element into string. The XML attributes and elements are
 * processed in wire order by chasing wo pointers. This is what you want for
 * validating signatures on other people's XML documents. */

/* Called by: */
char* zx_ENC_WO_cdm_LON(struct zx_ctx* c, struct zx_cdm_LON_s* x, char* p )
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
  ZX_OUT_MEM(p, "LON", sizeof("LON")-1);
  qq = p;

  /* *** sort the namespaces */
  if (c->inc_ns)
    zx_add_inc_ns(c, &pop_seen);
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
  zx_add_xmlns_if_not_seen(c, x->gg.g.ns, &pop_seen);

  p = zx_enc_seen(p, pop_seen); 
  p = zx_attr_wo_enc(p, x->ACC, "ACC=\"", sizeof("ACC=\"")-1);
  p = zx_attr_wo_enc(p, x->ACCTime, "ACCTime=\"", sizeof("ACCTime=\"")-1);
  p = zx_attr_wo_enc(p, x->id, "id=\"", sizeof("id=\"")-1);
  p = zx_attr_wo_enc(p, x->modificationTime, "modificationTime=\"", sizeof("modificationTime=\"")-1);
  p = zx_attr_wo_enc(p, x->modifier, "modifier=\"", sizeof("modifier=\"")-1);

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
  ENC_LEN_DEBUG(x, "cdm:LON", p-enc_base);
  return p;
}

/* FUNC(zx_EASY_ENC_SO_cdm_LON) */

/* Called by: */
struct zx_str* zx_EASY_ENC_SO_cdm_LON(struct zx_ctx* c, struct zx_cdm_LON_s* x )
{
  int len;
  char* buf;
  c->ns_tab = ZX_ALLOC(c, sizeof(zx_ns_tab));
  memcpy(c->ns_tab, zx_ns_tab, sizeof(zx_ns_tab));
  len = zx_LEN_SO_cdm_LON(c, x );
  buf = ZX_ALLOC(c, len+1);
  return zx_easy_enc_common(c, zx_ENC_SO_cdm_LON(c, x, buf ), buf, len);
}

/* FUNC(zx_EASY_ENC_WO_cdm_LON) */

/* Called by: */
struct zx_str* zx_EASY_ENC_WO_cdm_LON(struct zx_ctx* c, struct zx_cdm_LON_s* x )
{
  int len;
  char* buf;
  c->ns_tab = ZX_ALLOC(c, sizeof(zx_ns_tab));
  memcpy(c->ns_tab, zx_ns_tab, sizeof(zx_ns_tab));
  len = zx_LEN_WO_cdm_LON(c, x );
  buf = ZX_ALLOC(c, len+1);
  return zx_easy_enc_common(c, zx_ENC_WO_cdm_LON(c, x, buf ), buf, len);
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

#define EL_NAME   cdm_MAILER
#define EL_STRUCT zx_cdm_MAILER_s
#define EL_NS     cdm
#define EL_TAG    MAILER

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

/* FUNC(zx_LEN_SO_cdm_MAILER) */

/* Compute length of an element (and its subelements). The XML attributes
 * and elements are processed in schema order. */

/* Called by: */
int zx_LEN_SO_cdm_MAILER(struct zx_ctx* c, struct zx_cdm_MAILER_s* x )
{
  struct zx_ns_s* pop_seen = 0;
  struct zx_elem_s* se MAYBE_UNUSED;
#if 1 /* NORMALMODE */
  /* *** in simple_elem case should output ns prefix from ns node. */
  int len = sizeof("<cdm:MAILER")-1 + 1 + sizeof("</cdm:MAILER>")-1;
  if (c->inc_ns_len)
    len += zx_len_inc_ns(c, &pop_seen);
  if (x->ACC || x->ACCTime || x->id || x->modificationTime || x->modifier)
    len += zx_len_xmlns_if_not_seen(c, zx_ns_tab+zx_xmlns_ix_cb, &pop_seen);
  len += zx_len_xmlns_if_not_seen(c, zx_ns_tab+zx_xmlns_ix_cdm, &pop_seen);

  len += zx_attr_so_len(x->ACC, sizeof("cb:ACC")-1);
  len += zx_attr_so_len(x->ACCTime, sizeof("cb:ACCTime")-1);
  len += zx_attr_so_len(x->id, sizeof("cb:id")-1);
  len += zx_attr_so_len(x->modificationTime, sizeof("cb:modificationTime")-1);
  len += zx_attr_so_len(x->modifier, sizeof("cb:modifier")-1);

#else
  /* root node has no begin tag */
  int len = 0;
#endif
  


  len += zx_len_so_common(c, &x->gg);
  zx_pop_seen(pop_seen);
  ENC_LEN_DEBUG(x, "cdm:MAILER", len);
  return len;
}

/* FUNC(zx_LEN_WO_cdm_MAILER) */

/* Compute length of an element (and its subelements). The XML attributes
 * and elements are processed in wire order and no assumptions
 * are made about namespace prefixes. */

/* Called by: */
int zx_LEN_WO_cdm_MAILER(struct zx_ctx* c, struct zx_cdm_MAILER_s* x )
{
  struct zx_ns_s* pop_seen = 0;
  struct zx_elem_s* se MAYBE_UNUSED;
#if 1 /* NORMALMODE */
  int len = 1 + sizeof("MAILER")-1 + 1 + 2 + sizeof("MAILER")-1 + 1;
  
  if (x->gg.g.ns && x->gg.g.ns->prefix_len)
    len += (x->gg.g.ns->prefix_len + 1) * 2;
  if (c->inc_ns_len)
    len += zx_len_inc_ns(c, &pop_seen);
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
  len += zx_len_xmlns_if_not_seen(c, x->gg.g.ns, &pop_seen);

  len += zx_attr_wo_len(x->ACC, sizeof("ACC")-1);
  len += zx_attr_wo_len(x->ACCTime, sizeof("ACCTime")-1);
  len += zx_attr_wo_len(x->id, sizeof("id")-1);
  len += zx_attr_wo_len(x->modificationTime, sizeof("modificationTime")-1);
  len += zx_attr_wo_len(x->modifier, sizeof("modifier")-1);

#else
  /* root node has no begin tag */
  int len = 0;
#endif
  


  len += zx_len_wo_common(c, &x->gg); 
  zx_pop_seen(pop_seen);
  ENC_LEN_DEBUG(x, "cdm:MAILER", len);
  return len;
}

/* FUNC(zx_ENC_SO_cdm_MAILER) */

/* Render element into string. The XML attributes and elements are
 * processed in schema order. This is what you generally want for
 * rendering new data structure to a string. The wo pointers are not used. */

/* Called by: */
char* zx_ENC_SO_cdm_MAILER(struct zx_ctx* c, struct zx_cdm_MAILER_s* x, char* p )
{
  struct zx_elem_s* se MAYBE_UNUSED;
  struct zx_ns_s* pop_seen = 0;
  ENC_LEN_DEBUG_BASE;
#if 1 /* NORMALMODE */
  /* *** in simple_elem case should output ns prefix from ns node. */
  ZX_OUT_TAG(p, "<cdm:MAILER");
  if (c->inc_ns)
    p = zx_enc_inc_ns(c, p, &pop_seen);
  if (x->ACC || x->ACCTime || x->id || x->modificationTime || x->modifier)
    p = zx_enc_xmlns_if_not_seen(c, p, zx_ns_tab+zx_xmlns_ix_cb, &pop_seen);
  p = zx_enc_xmlns_if_not_seen(c, p, zx_ns_tab+zx_xmlns_ix_cdm, &pop_seen);

  p = zx_attr_so_enc(p, x->ACC, " cb:ACC=\"", sizeof(" cb:ACC=\"")-1);
  p = zx_attr_so_enc(p, x->ACCTime, " cb:ACCTime=\"", sizeof(" cb:ACCTime=\"")-1);
  p = zx_attr_so_enc(p, x->id, " cb:id=\"", sizeof(" cb:id=\"")-1);
  p = zx_attr_so_enc(p, x->modificationTime, " cb:modificationTime=\"", sizeof(" cb:modificationTime=\"")-1);
  p = zx_attr_so_enc(p, x->modifier, " cb:modifier=\"", sizeof(" cb:modifier=\"")-1);

  p = zx_enc_unknown_attrs(p, x->gg.any_attr);
#else
  /* root node has no begin tag */
#endif
  

  p = zx_enc_so_unknown_elems_and_content(c, p, &x->gg);
  
#if 1 /* NORMALMODE */
  ZX_OUT_CLOSE_TAG(p, "</cdm:MAILER>");
  zx_pop_seen(pop_seen);
#else
  /* root node has no end tag either */
#endif
  ENC_LEN_DEBUG(x, "cdm:MAILER", p-enc_base);
  return p;
}

/* FUNC(zx_ENC_WO_cdm_MAILER) */

/* Render element into string. The XML attributes and elements are
 * processed in wire order by chasing wo pointers. This is what you want for
 * validating signatures on other people's XML documents. */

/* Called by: */
char* zx_ENC_WO_cdm_MAILER(struct zx_ctx* c, struct zx_cdm_MAILER_s* x, char* p )
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
  ZX_OUT_MEM(p, "MAILER", sizeof("MAILER")-1);
  qq = p;

  /* *** sort the namespaces */
  if (c->inc_ns)
    zx_add_inc_ns(c, &pop_seen);
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
  zx_add_xmlns_if_not_seen(c, x->gg.g.ns, &pop_seen);

  p = zx_enc_seen(p, pop_seen); 
  p = zx_attr_wo_enc(p, x->ACC, "ACC=\"", sizeof("ACC=\"")-1);
  p = zx_attr_wo_enc(p, x->ACCTime, "ACCTime=\"", sizeof("ACCTime=\"")-1);
  p = zx_attr_wo_enc(p, x->id, "id=\"", sizeof("id=\"")-1);
  p = zx_attr_wo_enc(p, x->modificationTime, "modificationTime=\"", sizeof("modificationTime=\"")-1);
  p = zx_attr_wo_enc(p, x->modifier, "modifier=\"", sizeof("modifier=\"")-1);

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
  ENC_LEN_DEBUG(x, "cdm:MAILER", p-enc_base);
  return p;
}

/* FUNC(zx_EASY_ENC_SO_cdm_MAILER) */

/* Called by: */
struct zx_str* zx_EASY_ENC_SO_cdm_MAILER(struct zx_ctx* c, struct zx_cdm_MAILER_s* x )
{
  int len;
  char* buf;
  c->ns_tab = ZX_ALLOC(c, sizeof(zx_ns_tab));
  memcpy(c->ns_tab, zx_ns_tab, sizeof(zx_ns_tab));
  len = zx_LEN_SO_cdm_MAILER(c, x );
  buf = ZX_ALLOC(c, len+1);
  return zx_easy_enc_common(c, zx_ENC_SO_cdm_MAILER(c, x, buf ), buf, len);
}

/* FUNC(zx_EASY_ENC_WO_cdm_MAILER) */

/* Called by: */
struct zx_str* zx_EASY_ENC_WO_cdm_MAILER(struct zx_ctx* c, struct zx_cdm_MAILER_s* x )
{
  int len;
  char* buf;
  c->ns_tab = ZX_ALLOC(c, sizeof(zx_ns_tab));
  memcpy(c->ns_tab, zx_ns_tab, sizeof(zx_ns_tab));
  len = zx_LEN_WO_cdm_MAILER(c, x );
  buf = ZX_ALLOC(c, len+1);
  return zx_easy_enc_common(c, zx_ENC_WO_cdm_MAILER(c, x, buf ), buf, len);
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

#define EL_NAME   cdm_MIDDLE
#define EL_STRUCT zx_cdm_MIDDLE_s
#define EL_NS     cdm
#define EL_TAG    MIDDLE

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

/* FUNC(zx_LEN_SO_cdm_MIDDLE) */

/* Compute length of an element (and its subelements). The XML attributes
 * and elements are processed in schema order. */

/* Called by: */
int zx_LEN_SO_cdm_MIDDLE(struct zx_ctx* c, struct zx_cdm_MIDDLE_s* x )
{
  struct zx_ns_s* pop_seen = 0;
  struct zx_elem_s* se MAYBE_UNUSED;
#if 1 /* NORMALMODE */
  /* *** in simple_elem case should output ns prefix from ns node. */
  int len = sizeof("<cdm:MIDDLE")-1 + 1 + sizeof("</cdm:MIDDLE>")-1;
  if (c->inc_ns_len)
    len += zx_len_inc_ns(c, &pop_seen);
  if (x->group)
    len += zx_len_xmlns_if_not_seen(c, zx_ns_tab+zx_xmlns_ix_cb, &pop_seen);
  len += zx_len_xmlns_if_not_seen(c, zx_ns_tab+zx_xmlns_ix_cdm, &pop_seen);

  len += zx_attr_so_len(x->group, sizeof("cb:group")-1);

#else
  /* root node has no begin tag */
  int len = 0;
#endif
  


  len += zx_len_so_common(c, &x->gg);
  zx_pop_seen(pop_seen);
  ENC_LEN_DEBUG(x, "cdm:MIDDLE", len);
  return len;
}

/* FUNC(zx_LEN_WO_cdm_MIDDLE) */

/* Compute length of an element (and its subelements). The XML attributes
 * and elements are processed in wire order and no assumptions
 * are made about namespace prefixes. */

/* Called by: */
int zx_LEN_WO_cdm_MIDDLE(struct zx_ctx* c, struct zx_cdm_MIDDLE_s* x )
{
  struct zx_ns_s* pop_seen = 0;
  struct zx_elem_s* se MAYBE_UNUSED;
#if 1 /* NORMALMODE */
  int len = 1 + sizeof("MIDDLE")-1 + 1 + 2 + sizeof("MIDDLE")-1 + 1;
  
  if (x->gg.g.ns && x->gg.g.ns->prefix_len)
    len += (x->gg.g.ns->prefix_len + 1) * 2;
  if (c->inc_ns_len)
    len += zx_len_inc_ns(c, &pop_seen);
  if (x->group)
    len += zx_len_xmlns_if_not_seen(c, x->group->g.ns, &pop_seen);
  len += zx_len_xmlns_if_not_seen(c, x->gg.g.ns, &pop_seen);

  len += zx_attr_wo_len(x->group, sizeof("group")-1);

#else
  /* root node has no begin tag */
  int len = 0;
#endif
  


  len += zx_len_wo_common(c, &x->gg); 
  zx_pop_seen(pop_seen);
  ENC_LEN_DEBUG(x, "cdm:MIDDLE", len);
  return len;
}

/* FUNC(zx_ENC_SO_cdm_MIDDLE) */

/* Render element into string. The XML attributes and elements are
 * processed in schema order. This is what you generally want for
 * rendering new data structure to a string. The wo pointers are not used. */

/* Called by: */
char* zx_ENC_SO_cdm_MIDDLE(struct zx_ctx* c, struct zx_cdm_MIDDLE_s* x, char* p )
{
  struct zx_elem_s* se MAYBE_UNUSED;
  struct zx_ns_s* pop_seen = 0;
  ENC_LEN_DEBUG_BASE;
#if 1 /* NORMALMODE */
  /* *** in simple_elem case should output ns prefix from ns node. */
  ZX_OUT_TAG(p, "<cdm:MIDDLE");
  if (c->inc_ns)
    p = zx_enc_inc_ns(c, p, &pop_seen);
  if (x->group)
    p = zx_enc_xmlns_if_not_seen(c, p, zx_ns_tab+zx_xmlns_ix_cb, &pop_seen);
  p = zx_enc_xmlns_if_not_seen(c, p, zx_ns_tab+zx_xmlns_ix_cdm, &pop_seen);

  p = zx_attr_so_enc(p, x->group, " cb:group=\"", sizeof(" cb:group=\"")-1);

  p = zx_enc_unknown_attrs(p, x->gg.any_attr);
#else
  /* root node has no begin tag */
#endif
  

  p = zx_enc_so_unknown_elems_and_content(c, p, &x->gg);
  
#if 1 /* NORMALMODE */
  ZX_OUT_CLOSE_TAG(p, "</cdm:MIDDLE>");
  zx_pop_seen(pop_seen);
#else
  /* root node has no end tag either */
#endif
  ENC_LEN_DEBUG(x, "cdm:MIDDLE", p-enc_base);
  return p;
}

/* FUNC(zx_ENC_WO_cdm_MIDDLE) */

/* Render element into string. The XML attributes and elements are
 * processed in wire order by chasing wo pointers. This is what you want for
 * validating signatures on other people's XML documents. */

/* Called by: */
char* zx_ENC_WO_cdm_MIDDLE(struct zx_ctx* c, struct zx_cdm_MIDDLE_s* x, char* p )
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
  ZX_OUT_MEM(p, "MIDDLE", sizeof("MIDDLE")-1);
  qq = p;

  /* *** sort the namespaces */
  if (c->inc_ns)
    zx_add_inc_ns(c, &pop_seen);
  if (x->group)
    zx_add_xmlns_if_not_seen(c, x->group->g.ns, &pop_seen);
  zx_add_xmlns_if_not_seen(c, x->gg.g.ns, &pop_seen);

  p = zx_enc_seen(p, pop_seen); 
  p = zx_attr_wo_enc(p, x->group, "group=\"", sizeof("group=\"")-1);

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
  ENC_LEN_DEBUG(x, "cdm:MIDDLE", p-enc_base);
  return p;
}

/* FUNC(zx_EASY_ENC_SO_cdm_MIDDLE) */

/* Called by: */
struct zx_str* zx_EASY_ENC_SO_cdm_MIDDLE(struct zx_ctx* c, struct zx_cdm_MIDDLE_s* x )
{
  int len;
  char* buf;
  c->ns_tab = ZX_ALLOC(c, sizeof(zx_ns_tab));
  memcpy(c->ns_tab, zx_ns_tab, sizeof(zx_ns_tab));
  len = zx_LEN_SO_cdm_MIDDLE(c, x );
  buf = ZX_ALLOC(c, len+1);
  return zx_easy_enc_common(c, zx_ENC_SO_cdm_MIDDLE(c, x, buf ), buf, len);
}

/* FUNC(zx_EASY_ENC_WO_cdm_MIDDLE) */

/* Called by: */
struct zx_str* zx_EASY_ENC_WO_cdm_MIDDLE(struct zx_ctx* c, struct zx_cdm_MIDDLE_s* x )
{
  int len;
  char* buf;
  c->ns_tab = ZX_ALLOC(c, sizeof(zx_ns_tab));
  memcpy(c->ns_tab, zx_ns_tab, sizeof(zx_ns_tab));
  len = zx_LEN_WO_cdm_MIDDLE(c, x );
  buf = ZX_ALLOC(c, len+1);
  return zx_easy_enc_common(c, zx_ENC_WO_cdm_MIDDLE(c, x, buf ), buf, len);
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

#define EL_NAME   cdm_N
#define EL_STRUCT zx_cdm_N_s
#define EL_NS     cdm
#define EL_TAG    N

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

/* FUNC(zx_LEN_SO_cdm_N) */

/* Compute length of an element (and its subelements). The XML attributes
 * and elements are processed in schema order. */

/* Called by: */
int zx_LEN_SO_cdm_N(struct zx_ctx* c, struct zx_cdm_N_s* x )
{
  struct zx_ns_s* pop_seen = 0;
  struct zx_elem_s* se MAYBE_UNUSED;
#if 1 /* NORMALMODE */
  /* *** in simple_elem case should output ns prefix from ns node. */
  int len = sizeof("<cdm:N")-1 + 1 + sizeof("</cdm:N>")-1;
  if (c->inc_ns_len)
    len += zx_len_inc_ns(c, &pop_seen);
  if (x->id || x->modificationTime)
    len += zx_len_xmlns_if_not_seen(c, zx_ns_tab+zx_xmlns_ix_cb, &pop_seen);
  len += zx_len_xmlns_if_not_seen(c, zx_ns_tab+zx_xmlns_ix_cdm, &pop_seen);

  len += zx_attr_so_len(x->id, sizeof("cb:id")-1);
  len += zx_attr_so_len(x->modificationTime, sizeof("cb:modificationTime")-1);

#else
  /* root node has no begin tag */
  int len = 0;
#endif
  
  {
      struct zx_cdm_FAMILY_s* e;
      for (e = x->FAMILY; e; e = (struct zx_cdm_FAMILY_s*)e->gg.g.n)
	  len += zx_LEN_SO_cdm_FAMILY(c, e);
  }
  {
      struct zx_cdm_GIVEN_s* e;
      for (e = x->GIVEN; e; e = (struct zx_cdm_GIVEN_s*)e->gg.g.n)
	  len += zx_LEN_SO_cdm_GIVEN(c, e);
  }
  {
      struct zx_cdm_MIDDLE_s* e;
      for (e = x->MIDDLE; e; e = (struct zx_cdm_MIDDLE_s*)e->gg.g.n)
	  len += zx_LEN_SO_cdm_MIDDLE(c, e);
  }
  {
      struct zx_cdm_PREFIX_s* e;
      for (e = x->PREFIX; e; e = (struct zx_cdm_PREFIX_s*)e->gg.g.n)
	  len += zx_LEN_SO_cdm_PREFIX(c, e);
  }
  {
      struct zx_cdm_SUFFIX_s* e;
      for (e = x->SUFFIX; e; e = (struct zx_cdm_SUFFIX_s*)e->gg.g.n)
	  len += zx_LEN_SO_cdm_SUFFIX(c, e);
  }


  len += zx_len_so_common(c, &x->gg);
  zx_pop_seen(pop_seen);
  ENC_LEN_DEBUG(x, "cdm:N", len);
  return len;
}

/* FUNC(zx_LEN_WO_cdm_N) */

/* Compute length of an element (and its subelements). The XML attributes
 * and elements are processed in wire order and no assumptions
 * are made about namespace prefixes. */

/* Called by: */
int zx_LEN_WO_cdm_N(struct zx_ctx* c, struct zx_cdm_N_s* x )
{
  struct zx_ns_s* pop_seen = 0;
  struct zx_elem_s* se MAYBE_UNUSED;
#if 1 /* NORMALMODE */
  int len = 1 + sizeof("N")-1 + 1 + 2 + sizeof("N")-1 + 1;
  
  if (x->gg.g.ns && x->gg.g.ns->prefix_len)
    len += (x->gg.g.ns->prefix_len + 1) * 2;
  if (c->inc_ns_len)
    len += zx_len_inc_ns(c, &pop_seen);
  if (x->id)
    len += zx_len_xmlns_if_not_seen(c, x->id->g.ns, &pop_seen);
  if (x->modificationTime)
    len += zx_len_xmlns_if_not_seen(c, x->modificationTime->g.ns, &pop_seen);
  len += zx_len_xmlns_if_not_seen(c, x->gg.g.ns, &pop_seen);

  len += zx_attr_wo_len(x->id, sizeof("id")-1);
  len += zx_attr_wo_len(x->modificationTime, sizeof("modificationTime")-1);

#else
  /* root node has no begin tag */
  int len = 0;
#endif
  
  {
      struct zx_cdm_FAMILY_s* e;
      for (e = x->FAMILY; e; e = (struct zx_cdm_FAMILY_s*)e->gg.g.n)
	  len += zx_LEN_WO_cdm_FAMILY(c, e);
  }
  {
      struct zx_cdm_GIVEN_s* e;
      for (e = x->GIVEN; e; e = (struct zx_cdm_GIVEN_s*)e->gg.g.n)
	  len += zx_LEN_WO_cdm_GIVEN(c, e);
  }
  {
      struct zx_cdm_MIDDLE_s* e;
      for (e = x->MIDDLE; e; e = (struct zx_cdm_MIDDLE_s*)e->gg.g.n)
	  len += zx_LEN_WO_cdm_MIDDLE(c, e);
  }
  {
      struct zx_cdm_PREFIX_s* e;
      for (e = x->PREFIX; e; e = (struct zx_cdm_PREFIX_s*)e->gg.g.n)
	  len += zx_LEN_WO_cdm_PREFIX(c, e);
  }
  {
      struct zx_cdm_SUFFIX_s* e;
      for (e = x->SUFFIX; e; e = (struct zx_cdm_SUFFIX_s*)e->gg.g.n)
	  len += zx_LEN_WO_cdm_SUFFIX(c, e);
  }


  len += zx_len_wo_common(c, &x->gg); 
  zx_pop_seen(pop_seen);
  ENC_LEN_DEBUG(x, "cdm:N", len);
  return len;
}

/* FUNC(zx_ENC_SO_cdm_N) */

/* Render element into string. The XML attributes and elements are
 * processed in schema order. This is what you generally want for
 * rendering new data structure to a string. The wo pointers are not used. */

/* Called by: */
char* zx_ENC_SO_cdm_N(struct zx_ctx* c, struct zx_cdm_N_s* x, char* p )
{
  struct zx_elem_s* se MAYBE_UNUSED;
  struct zx_ns_s* pop_seen = 0;
  ENC_LEN_DEBUG_BASE;
#if 1 /* NORMALMODE */
  /* *** in simple_elem case should output ns prefix from ns node. */
  ZX_OUT_TAG(p, "<cdm:N");
  if (c->inc_ns)
    p = zx_enc_inc_ns(c, p, &pop_seen);
  if (x->id || x->modificationTime)
    p = zx_enc_xmlns_if_not_seen(c, p, zx_ns_tab+zx_xmlns_ix_cb, &pop_seen);
  p = zx_enc_xmlns_if_not_seen(c, p, zx_ns_tab+zx_xmlns_ix_cdm, &pop_seen);

  p = zx_attr_so_enc(p, x->id, " cb:id=\"", sizeof(" cb:id=\"")-1);
  p = zx_attr_so_enc(p, x->modificationTime, " cb:modificationTime=\"", sizeof(" cb:modificationTime=\"")-1);

  p = zx_enc_unknown_attrs(p, x->gg.any_attr);
#else
  /* root node has no begin tag */
#endif
  
  {
      struct zx_cdm_FAMILY_s* e;
      for (e = x->FAMILY; e; e = (struct zx_cdm_FAMILY_s*)e->gg.g.n)
	  p = zx_ENC_SO_cdm_FAMILY(c, e, p);
  }
  {
      struct zx_cdm_GIVEN_s* e;
      for (e = x->GIVEN; e; e = (struct zx_cdm_GIVEN_s*)e->gg.g.n)
	  p = zx_ENC_SO_cdm_GIVEN(c, e, p);
  }
  {
      struct zx_cdm_MIDDLE_s* e;
      for (e = x->MIDDLE; e; e = (struct zx_cdm_MIDDLE_s*)e->gg.g.n)
	  p = zx_ENC_SO_cdm_MIDDLE(c, e, p);
  }
  {
      struct zx_cdm_PREFIX_s* e;
      for (e = x->PREFIX; e; e = (struct zx_cdm_PREFIX_s*)e->gg.g.n)
	  p = zx_ENC_SO_cdm_PREFIX(c, e, p);
  }
  {
      struct zx_cdm_SUFFIX_s* e;
      for (e = x->SUFFIX; e; e = (struct zx_cdm_SUFFIX_s*)e->gg.g.n)
	  p = zx_ENC_SO_cdm_SUFFIX(c, e, p);
  }

  p = zx_enc_so_unknown_elems_and_content(c, p, &x->gg);
  
#if 1 /* NORMALMODE */
  ZX_OUT_CLOSE_TAG(p, "</cdm:N>");
  zx_pop_seen(pop_seen);
#else
  /* root node has no end tag either */
#endif
  ENC_LEN_DEBUG(x, "cdm:N", p-enc_base);
  return p;
}

/* FUNC(zx_ENC_WO_cdm_N) */

/* Render element into string. The XML attributes and elements are
 * processed in wire order by chasing wo pointers. This is what you want for
 * validating signatures on other people's XML documents. */

/* Called by: */
char* zx_ENC_WO_cdm_N(struct zx_ctx* c, struct zx_cdm_N_s* x, char* p )
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
  ZX_OUT_MEM(p, "N", sizeof("N")-1);
  qq = p;

  /* *** sort the namespaces */
  if (c->inc_ns)
    zx_add_inc_ns(c, &pop_seen);
  if (x->id)
    zx_add_xmlns_if_not_seen(c, x->id->g.ns, &pop_seen);
  if (x->modificationTime)
    zx_add_xmlns_if_not_seen(c, x->modificationTime->g.ns, &pop_seen);
  zx_add_xmlns_if_not_seen(c, x->gg.g.ns, &pop_seen);

  p = zx_enc_seen(p, pop_seen); 
  p = zx_attr_wo_enc(p, x->id, "id=\"", sizeof("id=\"")-1);
  p = zx_attr_wo_enc(p, x->modificationTime, "modificationTime=\"", sizeof("modificationTime=\"")-1);

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
  ENC_LEN_DEBUG(x, "cdm:N", p-enc_base);
  return p;
}

/* FUNC(zx_EASY_ENC_SO_cdm_N) */

/* Called by: */
struct zx_str* zx_EASY_ENC_SO_cdm_N(struct zx_ctx* c, struct zx_cdm_N_s* x )
{
  int len;
  char* buf;
  c->ns_tab = ZX_ALLOC(c, sizeof(zx_ns_tab));
  memcpy(c->ns_tab, zx_ns_tab, sizeof(zx_ns_tab));
  len = zx_LEN_SO_cdm_N(c, x );
  buf = ZX_ALLOC(c, len+1);
  return zx_easy_enc_common(c, zx_ENC_SO_cdm_N(c, x, buf ), buf, len);
}

/* FUNC(zx_EASY_ENC_WO_cdm_N) */

/* Called by: */
struct zx_str* zx_EASY_ENC_WO_cdm_N(struct zx_ctx* c, struct zx_cdm_N_s* x )
{
  int len;
  char* buf;
  c->ns_tab = ZX_ALLOC(c, sizeof(zx_ns_tab));
  memcpy(c->ns_tab, zx_ns_tab, sizeof(zx_ns_tab));
  len = zx_LEN_WO_cdm_N(c, x );
  buf = ZX_ALLOC(c, len+1);
  return zx_easy_enc_common(c, zx_ENC_WO_cdm_N(c, x, buf ), buf, len);
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

#define EL_NAME   cdm_NICKNAME
#define EL_STRUCT zx_cdm_NICKNAME_s
#define EL_NS     cdm
#define EL_TAG    NICKNAME

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

/* FUNC(zx_LEN_SO_cdm_NICKNAME) */

/* Compute length of an element (and its subelements). The XML attributes
 * and elements are processed in schema order. */

/* Called by: */
int zx_LEN_SO_cdm_NICKNAME(struct zx_ctx* c, struct zx_cdm_NICKNAME_s* x )
{
  struct zx_ns_s* pop_seen = 0;
  struct zx_elem_s* se MAYBE_UNUSED;
#if 1 /* NORMALMODE */
  /* *** in simple_elem case should output ns prefix from ns node. */
  int len = sizeof("<cdm:NICKNAME")-1 + 1 + sizeof("</cdm:NICKNAME>")-1;
  if (c->inc_ns_len)
    len += zx_len_inc_ns(c, &pop_seen);
  if (x->group)
    len += zx_len_xmlns_if_not_seen(c, zx_ns_tab+zx_xmlns_ix_cb, &pop_seen);
  len += zx_len_xmlns_if_not_seen(c, zx_ns_tab+zx_xmlns_ix_cdm, &pop_seen);

  len += zx_attr_so_len(x->group, sizeof("cb:group")-1);

#else
  /* root node has no begin tag */
  int len = 0;
#endif
  


  len += zx_len_so_common(c, &x->gg);
  zx_pop_seen(pop_seen);
  ENC_LEN_DEBUG(x, "cdm:NICKNAME", len);
  return len;
}

/* FUNC(zx_LEN_WO_cdm_NICKNAME) */

/* Compute length of an element (and its subelements). The XML attributes
 * and elements are processed in wire order and no assumptions
 * are made about namespace prefixes. */

/* Called by: */
int zx_LEN_WO_cdm_NICKNAME(struct zx_ctx* c, struct zx_cdm_NICKNAME_s* x )
{
  struct zx_ns_s* pop_seen = 0;
  struct zx_elem_s* se MAYBE_UNUSED;
#if 1 /* NORMALMODE */
  int len = 1 + sizeof("NICKNAME")-1 + 1 + 2 + sizeof("NICKNAME")-1 + 1;
  
  if (x->gg.g.ns && x->gg.g.ns->prefix_len)
    len += (x->gg.g.ns->prefix_len + 1) * 2;
  if (c->inc_ns_len)
    len += zx_len_inc_ns(c, &pop_seen);
  if (x->group)
    len += zx_len_xmlns_if_not_seen(c, x->group->g.ns, &pop_seen);
  len += zx_len_xmlns_if_not_seen(c, x->gg.g.ns, &pop_seen);

  len += zx_attr_wo_len(x->group, sizeof("group")-1);

#else
  /* root node has no begin tag */
  int len = 0;
#endif
  


  len += zx_len_wo_common(c, &x->gg); 
  zx_pop_seen(pop_seen);
  ENC_LEN_DEBUG(x, "cdm:NICKNAME", len);
  return len;
}

/* FUNC(zx_ENC_SO_cdm_NICKNAME) */

/* Render element into string. The XML attributes and elements are
 * processed in schema order. This is what you generally want for
 * rendering new data structure to a string. The wo pointers are not used. */

/* Called by: */
char* zx_ENC_SO_cdm_NICKNAME(struct zx_ctx* c, struct zx_cdm_NICKNAME_s* x, char* p )
{
  struct zx_elem_s* se MAYBE_UNUSED;
  struct zx_ns_s* pop_seen = 0;
  ENC_LEN_DEBUG_BASE;
#if 1 /* NORMALMODE */
  /* *** in simple_elem case should output ns prefix from ns node. */
  ZX_OUT_TAG(p, "<cdm:NICKNAME");
  if (c->inc_ns)
    p = zx_enc_inc_ns(c, p, &pop_seen);
  if (x->group)
    p = zx_enc_xmlns_if_not_seen(c, p, zx_ns_tab+zx_xmlns_ix_cb, &pop_seen);
  p = zx_enc_xmlns_if_not_seen(c, p, zx_ns_tab+zx_xmlns_ix_cdm, &pop_seen);

  p = zx_attr_so_enc(p, x->group, " cb:group=\"", sizeof(" cb:group=\"")-1);

  p = zx_enc_unknown_attrs(p, x->gg.any_attr);
#else
  /* root node has no begin tag */
#endif
  

  p = zx_enc_so_unknown_elems_and_content(c, p, &x->gg);
  
#if 1 /* NORMALMODE */
  ZX_OUT_CLOSE_TAG(p, "</cdm:NICKNAME>");
  zx_pop_seen(pop_seen);
#else
  /* root node has no end tag either */
#endif
  ENC_LEN_DEBUG(x, "cdm:NICKNAME", p-enc_base);
  return p;
}

/* FUNC(zx_ENC_WO_cdm_NICKNAME) */

/* Render element into string. The XML attributes and elements are
 * processed in wire order by chasing wo pointers. This is what you want for
 * validating signatures on other people's XML documents. */

/* Called by: */
char* zx_ENC_WO_cdm_NICKNAME(struct zx_ctx* c, struct zx_cdm_NICKNAME_s* x, char* p )
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
  ZX_OUT_MEM(p, "NICKNAME", sizeof("NICKNAME")-1);
  qq = p;

  /* *** sort the namespaces */
  if (c->inc_ns)
    zx_add_inc_ns(c, &pop_seen);
  if (x->group)
    zx_add_xmlns_if_not_seen(c, x->group->g.ns, &pop_seen);
  zx_add_xmlns_if_not_seen(c, x->gg.g.ns, &pop_seen);

  p = zx_enc_seen(p, pop_seen); 
  p = zx_attr_wo_enc(p, x->group, "group=\"", sizeof("group=\"")-1);

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
  ENC_LEN_DEBUG(x, "cdm:NICKNAME", p-enc_base);
  return p;
}

/* FUNC(zx_EASY_ENC_SO_cdm_NICKNAME) */

/* Called by: */
struct zx_str* zx_EASY_ENC_SO_cdm_NICKNAME(struct zx_ctx* c, struct zx_cdm_NICKNAME_s* x )
{
  int len;
  char* buf;
  c->ns_tab = ZX_ALLOC(c, sizeof(zx_ns_tab));
  memcpy(c->ns_tab, zx_ns_tab, sizeof(zx_ns_tab));
  len = zx_LEN_SO_cdm_NICKNAME(c, x );
  buf = ZX_ALLOC(c, len+1);
  return zx_easy_enc_common(c, zx_ENC_SO_cdm_NICKNAME(c, x, buf ), buf, len);
}

/* FUNC(zx_EASY_ENC_WO_cdm_NICKNAME) */

/* Called by: */
struct zx_str* zx_EASY_ENC_WO_cdm_NICKNAME(struct zx_ctx* c, struct zx_cdm_NICKNAME_s* x )
{
  int len;
  char* buf;
  c->ns_tab = ZX_ALLOC(c, sizeof(zx_ns_tab));
  memcpy(c->ns_tab, zx_ns_tab, sizeof(zx_ns_tab));
  len = zx_LEN_WO_cdm_NICKNAME(c, x );
  buf = ZX_ALLOC(c, len+1);
  return zx_easy_enc_common(c, zx_ENC_WO_cdm_NICKNAME(c, x, buf ), buf, len);
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

#define EL_NAME   cdm_NOTE
#define EL_STRUCT zx_cdm_NOTE_s
#define EL_NS     cdm
#define EL_TAG    NOTE

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

/* FUNC(zx_LEN_SO_cdm_NOTE) */

/* Compute length of an element (and its subelements). The XML attributes
 * and elements are processed in schema order. */

/* Called by: */
int zx_LEN_SO_cdm_NOTE(struct zx_ctx* c, struct zx_cdm_NOTE_s* x )
{
  struct zx_ns_s* pop_seen = 0;
  struct zx_elem_s* se MAYBE_UNUSED;
#if 1 /* NORMALMODE */
  /* *** in simple_elem case should output ns prefix from ns node. */
  int len = sizeof("<cdm:NOTE")-1 + 1 + sizeof("</cdm:NOTE>")-1;
  if (c->inc_ns_len)
    len += zx_len_inc_ns(c, &pop_seen);
  if (x->group)
    len += zx_len_xmlns_if_not_seen(c, zx_ns_tab+zx_xmlns_ix_cb, &pop_seen);
  len += zx_len_xmlns_if_not_seen(c, zx_ns_tab+zx_xmlns_ix_cdm, &pop_seen);

  len += zx_attr_so_len(x->group, sizeof("cb:group")-1);

#else
  /* root node has no begin tag */
  int len = 0;
#endif
  


  len += zx_len_so_common(c, &x->gg);
  zx_pop_seen(pop_seen);
  ENC_LEN_DEBUG(x, "cdm:NOTE", len);
  return len;
}

/* FUNC(zx_LEN_WO_cdm_NOTE) */

/* Compute length of an element (and its subelements). The XML attributes
 * and elements are processed in wire order and no assumptions
 * are made about namespace prefixes. */

/* Called by: */
int zx_LEN_WO_cdm_NOTE(struct zx_ctx* c, struct zx_cdm_NOTE_s* x )
{
  struct zx_ns_s* pop_seen = 0;
  struct zx_elem_s* se MAYBE_UNUSED;
#if 1 /* NORMALMODE */
  int len = 1 + sizeof("NOTE")-1 + 1 + 2 + sizeof("NOTE")-1 + 1;
  
  if (x->gg.g.ns && x->gg.g.ns->prefix_len)
    len += (x->gg.g.ns->prefix_len + 1) * 2;
  if (c->inc_ns_len)
    len += zx_len_inc_ns(c, &pop_seen);
  if (x->group)
    len += zx_len_xmlns_if_not_seen(c, x->group->g.ns, &pop_seen);
  len += zx_len_xmlns_if_not_seen(c, x->gg.g.ns, &pop_seen);

  len += zx_attr_wo_len(x->group, sizeof("group")-1);

#else
  /* root node has no begin tag */
  int len = 0;
#endif
  


  len += zx_len_wo_common(c, &x->gg); 
  zx_pop_seen(pop_seen);
  ENC_LEN_DEBUG(x, "cdm:NOTE", len);
  return len;
}

/* FUNC(zx_ENC_SO_cdm_NOTE) */

/* Render element into string. The XML attributes and elements are
 * processed in schema order. This is what you generally want for
 * rendering new data structure to a string. The wo pointers are not used. */

/* Called by: */
char* zx_ENC_SO_cdm_NOTE(struct zx_ctx* c, struct zx_cdm_NOTE_s* x, char* p )
{
  struct zx_elem_s* se MAYBE_UNUSED;
  struct zx_ns_s* pop_seen = 0;
  ENC_LEN_DEBUG_BASE;
#if 1 /* NORMALMODE */
  /* *** in simple_elem case should output ns prefix from ns node. */
  ZX_OUT_TAG(p, "<cdm:NOTE");
  if (c->inc_ns)
    p = zx_enc_inc_ns(c, p, &pop_seen);
  if (x->group)
    p = zx_enc_xmlns_if_not_seen(c, p, zx_ns_tab+zx_xmlns_ix_cb, &pop_seen);
  p = zx_enc_xmlns_if_not_seen(c, p, zx_ns_tab+zx_xmlns_ix_cdm, &pop_seen);

  p = zx_attr_so_enc(p, x->group, " cb:group=\"", sizeof(" cb:group=\"")-1);

  p = zx_enc_unknown_attrs(p, x->gg.any_attr);
#else
  /* root node has no begin tag */
#endif
  

  p = zx_enc_so_unknown_elems_and_content(c, p, &x->gg);
  
#if 1 /* NORMALMODE */
  ZX_OUT_CLOSE_TAG(p, "</cdm:NOTE>");
  zx_pop_seen(pop_seen);
#else
  /* root node has no end tag either */
#endif
  ENC_LEN_DEBUG(x, "cdm:NOTE", p-enc_base);
  return p;
}

/* FUNC(zx_ENC_WO_cdm_NOTE) */

/* Render element into string. The XML attributes and elements are
 * processed in wire order by chasing wo pointers. This is what you want for
 * validating signatures on other people's XML documents. */

/* Called by: */
char* zx_ENC_WO_cdm_NOTE(struct zx_ctx* c, struct zx_cdm_NOTE_s* x, char* p )
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
  ZX_OUT_MEM(p, "NOTE", sizeof("NOTE")-1);
  qq = p;

  /* *** sort the namespaces */
  if (c->inc_ns)
    zx_add_inc_ns(c, &pop_seen);
  if (x->group)
    zx_add_xmlns_if_not_seen(c, x->group->g.ns, &pop_seen);
  zx_add_xmlns_if_not_seen(c, x->gg.g.ns, &pop_seen);

  p = zx_enc_seen(p, pop_seen); 
  p = zx_attr_wo_enc(p, x->group, "group=\"", sizeof("group=\"")-1);

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
  ENC_LEN_DEBUG(x, "cdm:NOTE", p-enc_base);
  return p;
}

/* FUNC(zx_EASY_ENC_SO_cdm_NOTE) */

/* Called by: */
struct zx_str* zx_EASY_ENC_SO_cdm_NOTE(struct zx_ctx* c, struct zx_cdm_NOTE_s* x )
{
  int len;
  char* buf;
  c->ns_tab = ZX_ALLOC(c, sizeof(zx_ns_tab));
  memcpy(c->ns_tab, zx_ns_tab, sizeof(zx_ns_tab));
  len = zx_LEN_SO_cdm_NOTE(c, x );
  buf = ZX_ALLOC(c, len+1);
  return zx_easy_enc_common(c, zx_ENC_SO_cdm_NOTE(c, x, buf ), buf, len);
}

/* FUNC(zx_EASY_ENC_WO_cdm_NOTE) */

/* Called by: */
struct zx_str* zx_EASY_ENC_WO_cdm_NOTE(struct zx_ctx* c, struct zx_cdm_NOTE_s* x )
{
  int len;
  char* buf;
  c->ns_tab = ZX_ALLOC(c, sizeof(zx_ns_tab));
  memcpy(c->ns_tab, zx_ns_tab, sizeof(zx_ns_tab));
  len = zx_LEN_WO_cdm_NOTE(c, x );
  buf = ZX_ALLOC(c, len+1);
  return zx_easy_enc_common(c, zx_ENC_WO_cdm_NOTE(c, x, buf ), buf, len);
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

#define EL_NAME   cdm_NUMBER
#define EL_STRUCT zx_cdm_NUMBER_s
#define EL_NS     cdm
#define EL_TAG    NUMBER

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

/* FUNC(zx_LEN_SO_cdm_NUMBER) */

/* Compute length of an element (and its subelements). The XML attributes
 * and elements are processed in schema order. */

/* Called by: */
int zx_LEN_SO_cdm_NUMBER(struct zx_ctx* c, struct zx_cdm_NUMBER_s* x )
{
  struct zx_ns_s* pop_seen = 0;
  struct zx_elem_s* se MAYBE_UNUSED;
#if 1 /* NORMALMODE */
  /* *** in simple_elem case should output ns prefix from ns node. */
  int len = sizeof("<cdm:NUMBER")-1 + 1 + sizeof("</cdm:NUMBER>")-1;
  if (c->inc_ns_len)
    len += zx_len_inc_ns(c, &pop_seen);
  if (x->ACC || x->ACCTime || x->id || x->modificationTime || x->modifier)
    len += zx_len_xmlns_if_not_seen(c, zx_ns_tab+zx_xmlns_ix_cb, &pop_seen);
  len += zx_len_xmlns_if_not_seen(c, zx_ns_tab+zx_xmlns_ix_cdm, &pop_seen);

  len += zx_attr_so_len(x->ACC, sizeof("cb:ACC")-1);
  len += zx_attr_so_len(x->ACCTime, sizeof("cb:ACCTime")-1);
  len += zx_attr_so_len(x->id, sizeof("cb:id")-1);
  len += zx_attr_so_len(x->modificationTime, sizeof("cb:modificationTime")-1);
  len += zx_attr_so_len(x->modifier, sizeof("cb:modifier")-1);

#else
  /* root node has no begin tag */
  int len = 0;
#endif
  


  len += zx_len_so_common(c, &x->gg);
  zx_pop_seen(pop_seen);
  ENC_LEN_DEBUG(x, "cdm:NUMBER", len);
  return len;
}

/* FUNC(zx_LEN_WO_cdm_NUMBER) */

/* Compute length of an element (and its subelements). The XML attributes
 * and elements are processed in wire order and no assumptions
 * are made about namespace prefixes. */

/* Called by: */
int zx_LEN_WO_cdm_NUMBER(struct zx_ctx* c, struct zx_cdm_NUMBER_s* x )
{
  struct zx_ns_s* pop_seen = 0;
  struct zx_elem_s* se MAYBE_UNUSED;
#if 1 /* NORMALMODE */
  int len = 1 + sizeof("NUMBER")-1 + 1 + 2 + sizeof("NUMBER")-1 + 1;
  
  if (x->gg.g.ns && x->gg.g.ns->prefix_len)
    len += (x->gg.g.ns->prefix_len + 1) * 2;
  if (c->inc_ns_len)
    len += zx_len_inc_ns(c, &pop_seen);
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
  len += zx_len_xmlns_if_not_seen(c, x->gg.g.ns, &pop_seen);

  len += zx_attr_wo_len(x->ACC, sizeof("ACC")-1);
  len += zx_attr_wo_len(x->ACCTime, sizeof("ACCTime")-1);
  len += zx_attr_wo_len(x->id, sizeof("id")-1);
  len += zx_attr_wo_len(x->modificationTime, sizeof("modificationTime")-1);
  len += zx_attr_wo_len(x->modifier, sizeof("modifier")-1);

#else
  /* root node has no begin tag */
  int len = 0;
#endif
  


  len += zx_len_wo_common(c, &x->gg); 
  zx_pop_seen(pop_seen);
  ENC_LEN_DEBUG(x, "cdm:NUMBER", len);
  return len;
}

/* FUNC(zx_ENC_SO_cdm_NUMBER) */

/* Render element into string. The XML attributes and elements are
 * processed in schema order. This is what you generally want for
 * rendering new data structure to a string. The wo pointers are not used. */

/* Called by: */
char* zx_ENC_SO_cdm_NUMBER(struct zx_ctx* c, struct zx_cdm_NUMBER_s* x, char* p )
{
  struct zx_elem_s* se MAYBE_UNUSED;
  struct zx_ns_s* pop_seen = 0;
  ENC_LEN_DEBUG_BASE;
#if 1 /* NORMALMODE */
  /* *** in simple_elem case should output ns prefix from ns node. */
  ZX_OUT_TAG(p, "<cdm:NUMBER");
  if (c->inc_ns)
    p = zx_enc_inc_ns(c, p, &pop_seen);
  if (x->ACC || x->ACCTime || x->id || x->modificationTime || x->modifier)
    p = zx_enc_xmlns_if_not_seen(c, p, zx_ns_tab+zx_xmlns_ix_cb, &pop_seen);
  p = zx_enc_xmlns_if_not_seen(c, p, zx_ns_tab+zx_xmlns_ix_cdm, &pop_seen);

  p = zx_attr_so_enc(p, x->ACC, " cb:ACC=\"", sizeof(" cb:ACC=\"")-1);
  p = zx_attr_so_enc(p, x->ACCTime, " cb:ACCTime=\"", sizeof(" cb:ACCTime=\"")-1);
  p = zx_attr_so_enc(p, x->id, " cb:id=\"", sizeof(" cb:id=\"")-1);
  p = zx_attr_so_enc(p, x->modificationTime, " cb:modificationTime=\"", sizeof(" cb:modificationTime=\"")-1);
  p = zx_attr_so_enc(p, x->modifier, " cb:modifier=\"", sizeof(" cb:modifier=\"")-1);

  p = zx_enc_unknown_attrs(p, x->gg.any_attr);
#else
  /* root node has no begin tag */
#endif
  

  p = zx_enc_so_unknown_elems_and_content(c, p, &x->gg);
  
#if 1 /* NORMALMODE */
  ZX_OUT_CLOSE_TAG(p, "</cdm:NUMBER>");
  zx_pop_seen(pop_seen);
#else
  /* root node has no end tag either */
#endif
  ENC_LEN_DEBUG(x, "cdm:NUMBER", p-enc_base);
  return p;
}

/* FUNC(zx_ENC_WO_cdm_NUMBER) */

/* Render element into string. The XML attributes and elements are
 * processed in wire order by chasing wo pointers. This is what you want for
 * validating signatures on other people's XML documents. */

/* Called by: */
char* zx_ENC_WO_cdm_NUMBER(struct zx_ctx* c, struct zx_cdm_NUMBER_s* x, char* p )
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
  ZX_OUT_MEM(p, "NUMBER", sizeof("NUMBER")-1);
  qq = p;

  /* *** sort the namespaces */
  if (c->inc_ns)
    zx_add_inc_ns(c, &pop_seen);
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
  zx_add_xmlns_if_not_seen(c, x->gg.g.ns, &pop_seen);

  p = zx_enc_seen(p, pop_seen); 
  p = zx_attr_wo_enc(p, x->ACC, "ACC=\"", sizeof("ACC=\"")-1);
  p = zx_attr_wo_enc(p, x->ACCTime, "ACCTime=\"", sizeof("ACCTime=\"")-1);
  p = zx_attr_wo_enc(p, x->id, "id=\"", sizeof("id=\"")-1);
  p = zx_attr_wo_enc(p, x->modificationTime, "modificationTime=\"", sizeof("modificationTime=\"")-1);
  p = zx_attr_wo_enc(p, x->modifier, "modifier=\"", sizeof("modifier=\"")-1);

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
  ENC_LEN_DEBUG(x, "cdm:NUMBER", p-enc_base);
  return p;
}

/* FUNC(zx_EASY_ENC_SO_cdm_NUMBER) */

/* Called by: */
struct zx_str* zx_EASY_ENC_SO_cdm_NUMBER(struct zx_ctx* c, struct zx_cdm_NUMBER_s* x )
{
  int len;
  char* buf;
  c->ns_tab = ZX_ALLOC(c, sizeof(zx_ns_tab));
  memcpy(c->ns_tab, zx_ns_tab, sizeof(zx_ns_tab));
  len = zx_LEN_SO_cdm_NUMBER(c, x );
  buf = ZX_ALLOC(c, len+1);
  return zx_easy_enc_common(c, zx_ENC_SO_cdm_NUMBER(c, x, buf ), buf, len);
}

/* FUNC(zx_EASY_ENC_WO_cdm_NUMBER) */

/* Called by: */
struct zx_str* zx_EASY_ENC_WO_cdm_NUMBER(struct zx_ctx* c, struct zx_cdm_NUMBER_s* x )
{
  int len;
  char* buf;
  c->ns_tab = ZX_ALLOC(c, sizeof(zx_ns_tab));
  memcpy(c->ns_tab, zx_ns_tab, sizeof(zx_ns_tab));
  len = zx_LEN_WO_cdm_NUMBER(c, x );
  buf = ZX_ALLOC(c, len+1);
  return zx_easy_enc_common(c, zx_ENC_WO_cdm_NUMBER(c, x, buf ), buf, len);
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

#define EL_NAME   cdm_ORG
#define EL_STRUCT zx_cdm_ORG_s
#define EL_NS     cdm
#define EL_TAG    ORG

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

/* FUNC(zx_LEN_SO_cdm_ORG) */

/* Compute length of an element (and its subelements). The XML attributes
 * and elements are processed in schema order. */

/* Called by: */
int zx_LEN_SO_cdm_ORG(struct zx_ctx* c, struct zx_cdm_ORG_s* x )
{
  struct zx_ns_s* pop_seen = 0;
  struct zx_elem_s* se MAYBE_UNUSED;
#if 1 /* NORMALMODE */
  /* *** in simple_elem case should output ns prefix from ns node. */
  int len = sizeof("<cdm:ORG")-1 + 1 + sizeof("</cdm:ORG>")-1;
  if (c->inc_ns_len)
    len += zx_len_inc_ns(c, &pop_seen);
  if (x->id || x->modificationTime)
    len += zx_len_xmlns_if_not_seen(c, zx_ns_tab+zx_xmlns_ix_cb, &pop_seen);
  len += zx_len_xmlns_if_not_seen(c, zx_ns_tab+zx_xmlns_ix_cdm, &pop_seen);

  len += zx_attr_so_len(x->id, sizeof("cb:id")-1);
  len += zx_attr_so_len(x->modificationTime, sizeof("cb:modificationTime")-1);

#else
  /* root node has no begin tag */
  int len = 0;
#endif
  
  {
      struct zx_cdm_ORGNAME_s* e;
      for (e = x->ORGNAME; e; e = (struct zx_cdm_ORGNAME_s*)e->gg.g.n)
	  len += zx_LEN_SO_cdm_ORGNAME(c, e);
  }
  {
      struct zx_cdm_ORGUNIT_s* e;
      for (e = x->ORGUNIT; e; e = (struct zx_cdm_ORGUNIT_s*)e->gg.g.n)
	  len += zx_LEN_SO_cdm_ORGUNIT(c, e);
  }


  len += zx_len_so_common(c, &x->gg);
  zx_pop_seen(pop_seen);
  ENC_LEN_DEBUG(x, "cdm:ORG", len);
  return len;
}

/* FUNC(zx_LEN_WO_cdm_ORG) */

/* Compute length of an element (and its subelements). The XML attributes
 * and elements are processed in wire order and no assumptions
 * are made about namespace prefixes. */

/* Called by: */
int zx_LEN_WO_cdm_ORG(struct zx_ctx* c, struct zx_cdm_ORG_s* x )
{
  struct zx_ns_s* pop_seen = 0;
  struct zx_elem_s* se MAYBE_UNUSED;
#if 1 /* NORMALMODE */
  int len = 1 + sizeof("ORG")-1 + 1 + 2 + sizeof("ORG")-1 + 1;
  
  if (x->gg.g.ns && x->gg.g.ns->prefix_len)
    len += (x->gg.g.ns->prefix_len + 1) * 2;
  if (c->inc_ns_len)
    len += zx_len_inc_ns(c, &pop_seen);
  if (x->id)
    len += zx_len_xmlns_if_not_seen(c, x->id->g.ns, &pop_seen);
  if (x->modificationTime)
    len += zx_len_xmlns_if_not_seen(c, x->modificationTime->g.ns, &pop_seen);
  len += zx_len_xmlns_if_not_seen(c, x->gg.g.ns, &pop_seen);

  len += zx_attr_wo_len(x->id, sizeof("id")-1);
  len += zx_attr_wo_len(x->modificationTime, sizeof("modificationTime")-1);

#else
  /* root node has no begin tag */
  int len = 0;
#endif
  
  {
      struct zx_cdm_ORGNAME_s* e;
      for (e = x->ORGNAME; e; e = (struct zx_cdm_ORGNAME_s*)e->gg.g.n)
	  len += zx_LEN_WO_cdm_ORGNAME(c, e);
  }
  {
      struct zx_cdm_ORGUNIT_s* e;
      for (e = x->ORGUNIT; e; e = (struct zx_cdm_ORGUNIT_s*)e->gg.g.n)
	  len += zx_LEN_WO_cdm_ORGUNIT(c, e);
  }


  len += zx_len_wo_common(c, &x->gg); 
  zx_pop_seen(pop_seen);
  ENC_LEN_DEBUG(x, "cdm:ORG", len);
  return len;
}

/* FUNC(zx_ENC_SO_cdm_ORG) */

/* Render element into string. The XML attributes and elements are
 * processed in schema order. This is what you generally want for
 * rendering new data structure to a string. The wo pointers are not used. */

/* Called by: */
char* zx_ENC_SO_cdm_ORG(struct zx_ctx* c, struct zx_cdm_ORG_s* x, char* p )
{
  struct zx_elem_s* se MAYBE_UNUSED;
  struct zx_ns_s* pop_seen = 0;
  ENC_LEN_DEBUG_BASE;
#if 1 /* NORMALMODE */
  /* *** in simple_elem case should output ns prefix from ns node. */
  ZX_OUT_TAG(p, "<cdm:ORG");
  if (c->inc_ns)
    p = zx_enc_inc_ns(c, p, &pop_seen);
  if (x->id || x->modificationTime)
    p = zx_enc_xmlns_if_not_seen(c, p, zx_ns_tab+zx_xmlns_ix_cb, &pop_seen);
  p = zx_enc_xmlns_if_not_seen(c, p, zx_ns_tab+zx_xmlns_ix_cdm, &pop_seen);

  p = zx_attr_so_enc(p, x->id, " cb:id=\"", sizeof(" cb:id=\"")-1);
  p = zx_attr_so_enc(p, x->modificationTime, " cb:modificationTime=\"", sizeof(" cb:modificationTime=\"")-1);

  p = zx_enc_unknown_attrs(p, x->gg.any_attr);
#else
  /* root node has no begin tag */
#endif
  
  {
      struct zx_cdm_ORGNAME_s* e;
      for (e = x->ORGNAME; e; e = (struct zx_cdm_ORGNAME_s*)e->gg.g.n)
	  p = zx_ENC_SO_cdm_ORGNAME(c, e, p);
  }
  {
      struct zx_cdm_ORGUNIT_s* e;
      for (e = x->ORGUNIT; e; e = (struct zx_cdm_ORGUNIT_s*)e->gg.g.n)
	  p = zx_ENC_SO_cdm_ORGUNIT(c, e, p);
  }

  p = zx_enc_so_unknown_elems_and_content(c, p, &x->gg);
  
#if 1 /* NORMALMODE */
  ZX_OUT_CLOSE_TAG(p, "</cdm:ORG>");
  zx_pop_seen(pop_seen);
#else
  /* root node has no end tag either */
#endif
  ENC_LEN_DEBUG(x, "cdm:ORG", p-enc_base);
  return p;
}

/* FUNC(zx_ENC_WO_cdm_ORG) */

/* Render element into string. The XML attributes and elements are
 * processed in wire order by chasing wo pointers. This is what you want for
 * validating signatures on other people's XML documents. */

/* Called by: */
char* zx_ENC_WO_cdm_ORG(struct zx_ctx* c, struct zx_cdm_ORG_s* x, char* p )
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
  ZX_OUT_MEM(p, "ORG", sizeof("ORG")-1);
  qq = p;

  /* *** sort the namespaces */
  if (c->inc_ns)
    zx_add_inc_ns(c, &pop_seen);
  if (x->id)
    zx_add_xmlns_if_not_seen(c, x->id->g.ns, &pop_seen);
  if (x->modificationTime)
    zx_add_xmlns_if_not_seen(c, x->modificationTime->g.ns, &pop_seen);
  zx_add_xmlns_if_not_seen(c, x->gg.g.ns, &pop_seen);

  p = zx_enc_seen(p, pop_seen); 
  p = zx_attr_wo_enc(p, x->id, "id=\"", sizeof("id=\"")-1);
  p = zx_attr_wo_enc(p, x->modificationTime, "modificationTime=\"", sizeof("modificationTime=\"")-1);

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
  ENC_LEN_DEBUG(x, "cdm:ORG", p-enc_base);
  return p;
}

/* FUNC(zx_EASY_ENC_SO_cdm_ORG) */

/* Called by: */
struct zx_str* zx_EASY_ENC_SO_cdm_ORG(struct zx_ctx* c, struct zx_cdm_ORG_s* x )
{
  int len;
  char* buf;
  c->ns_tab = ZX_ALLOC(c, sizeof(zx_ns_tab));
  memcpy(c->ns_tab, zx_ns_tab, sizeof(zx_ns_tab));
  len = zx_LEN_SO_cdm_ORG(c, x );
  buf = ZX_ALLOC(c, len+1);
  return zx_easy_enc_common(c, zx_ENC_SO_cdm_ORG(c, x, buf ), buf, len);
}

/* FUNC(zx_EASY_ENC_WO_cdm_ORG) */

/* Called by: */
struct zx_str* zx_EASY_ENC_WO_cdm_ORG(struct zx_ctx* c, struct zx_cdm_ORG_s* x )
{
  int len;
  char* buf;
  c->ns_tab = ZX_ALLOC(c, sizeof(zx_ns_tab));
  memcpy(c->ns_tab, zx_ns_tab, sizeof(zx_ns_tab));
  len = zx_LEN_WO_cdm_ORG(c, x );
  buf = ZX_ALLOC(c, len+1);
  return zx_easy_enc_common(c, zx_ENC_WO_cdm_ORG(c, x, buf ), buf, len);
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

#define EL_NAME   cdm_ORGNAME
#define EL_STRUCT zx_cdm_ORGNAME_s
#define EL_NS     cdm
#define EL_TAG    ORGNAME

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

/* FUNC(zx_LEN_SO_cdm_ORGNAME) */

/* Compute length of an element (and its subelements). The XML attributes
 * and elements are processed in schema order. */

/* Called by: */
int zx_LEN_SO_cdm_ORGNAME(struct zx_ctx* c, struct zx_cdm_ORGNAME_s* x )
{
  struct zx_ns_s* pop_seen = 0;
  struct zx_elem_s* se MAYBE_UNUSED;
#if 1 /* NORMALMODE */
  /* *** in simple_elem case should output ns prefix from ns node. */
  int len = sizeof("<cdm:ORGNAME")-1 + 1 + sizeof("</cdm:ORGNAME>")-1;
  if (c->inc_ns_len)
    len += zx_len_inc_ns(c, &pop_seen);
  if (x->group)
    len += zx_len_xmlns_if_not_seen(c, zx_ns_tab+zx_xmlns_ix_cb, &pop_seen);
  len += zx_len_xmlns_if_not_seen(c, zx_ns_tab+zx_xmlns_ix_cdm, &pop_seen);

  len += zx_attr_so_len(x->group, sizeof("cb:group")-1);

#else
  /* root node has no begin tag */
  int len = 0;
#endif
  


  len += zx_len_so_common(c, &x->gg);
  zx_pop_seen(pop_seen);
  ENC_LEN_DEBUG(x, "cdm:ORGNAME", len);
  return len;
}

/* FUNC(zx_LEN_WO_cdm_ORGNAME) */

/* Compute length of an element (and its subelements). The XML attributes
 * and elements are processed in wire order and no assumptions
 * are made about namespace prefixes. */

/* Called by: */
int zx_LEN_WO_cdm_ORGNAME(struct zx_ctx* c, struct zx_cdm_ORGNAME_s* x )
{
  struct zx_ns_s* pop_seen = 0;
  struct zx_elem_s* se MAYBE_UNUSED;
#if 1 /* NORMALMODE */
  int len = 1 + sizeof("ORGNAME")-1 + 1 + 2 + sizeof("ORGNAME")-1 + 1;
  
  if (x->gg.g.ns && x->gg.g.ns->prefix_len)
    len += (x->gg.g.ns->prefix_len + 1) * 2;
  if (c->inc_ns_len)
    len += zx_len_inc_ns(c, &pop_seen);
  if (x->group)
    len += zx_len_xmlns_if_not_seen(c, x->group->g.ns, &pop_seen);
  len += zx_len_xmlns_if_not_seen(c, x->gg.g.ns, &pop_seen);

  len += zx_attr_wo_len(x->group, sizeof("group")-1);

#else
  /* root node has no begin tag */
  int len = 0;
#endif
  


  len += zx_len_wo_common(c, &x->gg); 
  zx_pop_seen(pop_seen);
  ENC_LEN_DEBUG(x, "cdm:ORGNAME", len);
  return len;
}

/* FUNC(zx_ENC_SO_cdm_ORGNAME) */

/* Render element into string. The XML attributes and elements are
 * processed in schema order. This is what you generally want for
 * rendering new data structure to a string. The wo pointers are not used. */

/* Called by: */
char* zx_ENC_SO_cdm_ORGNAME(struct zx_ctx* c, struct zx_cdm_ORGNAME_s* x, char* p )
{
  struct zx_elem_s* se MAYBE_UNUSED;
  struct zx_ns_s* pop_seen = 0;
  ENC_LEN_DEBUG_BASE;
#if 1 /* NORMALMODE */
  /* *** in simple_elem case should output ns prefix from ns node. */
  ZX_OUT_TAG(p, "<cdm:ORGNAME");
  if (c->inc_ns)
    p = zx_enc_inc_ns(c, p, &pop_seen);
  if (x->group)
    p = zx_enc_xmlns_if_not_seen(c, p, zx_ns_tab+zx_xmlns_ix_cb, &pop_seen);
  p = zx_enc_xmlns_if_not_seen(c, p, zx_ns_tab+zx_xmlns_ix_cdm, &pop_seen);

  p = zx_attr_so_enc(p, x->group, " cb:group=\"", sizeof(" cb:group=\"")-1);

  p = zx_enc_unknown_attrs(p, x->gg.any_attr);
#else
  /* root node has no begin tag */
#endif
  

  p = zx_enc_so_unknown_elems_and_content(c, p, &x->gg);
  
#if 1 /* NORMALMODE */
  ZX_OUT_CLOSE_TAG(p, "</cdm:ORGNAME>");
  zx_pop_seen(pop_seen);
#else
  /* root node has no end tag either */
#endif
  ENC_LEN_DEBUG(x, "cdm:ORGNAME", p-enc_base);
  return p;
}

/* FUNC(zx_ENC_WO_cdm_ORGNAME) */

/* Render element into string. The XML attributes and elements are
 * processed in wire order by chasing wo pointers. This is what you want for
 * validating signatures on other people's XML documents. */

/* Called by: */
char* zx_ENC_WO_cdm_ORGNAME(struct zx_ctx* c, struct zx_cdm_ORGNAME_s* x, char* p )
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
  ZX_OUT_MEM(p, "ORGNAME", sizeof("ORGNAME")-1);
  qq = p;

  /* *** sort the namespaces */
  if (c->inc_ns)
    zx_add_inc_ns(c, &pop_seen);
  if (x->group)
    zx_add_xmlns_if_not_seen(c, x->group->g.ns, &pop_seen);
  zx_add_xmlns_if_not_seen(c, x->gg.g.ns, &pop_seen);

  p = zx_enc_seen(p, pop_seen); 
  p = zx_attr_wo_enc(p, x->group, "group=\"", sizeof("group=\"")-1);

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
  ENC_LEN_DEBUG(x, "cdm:ORGNAME", p-enc_base);
  return p;
}

/* FUNC(zx_EASY_ENC_SO_cdm_ORGNAME) */

/* Called by: */
struct zx_str* zx_EASY_ENC_SO_cdm_ORGNAME(struct zx_ctx* c, struct zx_cdm_ORGNAME_s* x )
{
  int len;
  char* buf;
  c->ns_tab = ZX_ALLOC(c, sizeof(zx_ns_tab));
  memcpy(c->ns_tab, zx_ns_tab, sizeof(zx_ns_tab));
  len = zx_LEN_SO_cdm_ORGNAME(c, x );
  buf = ZX_ALLOC(c, len+1);
  return zx_easy_enc_common(c, zx_ENC_SO_cdm_ORGNAME(c, x, buf ), buf, len);
}

/* FUNC(zx_EASY_ENC_WO_cdm_ORGNAME) */

/* Called by: */
struct zx_str* zx_EASY_ENC_WO_cdm_ORGNAME(struct zx_ctx* c, struct zx_cdm_ORGNAME_s* x )
{
  int len;
  char* buf;
  c->ns_tab = ZX_ALLOC(c, sizeof(zx_ns_tab));
  memcpy(c->ns_tab, zx_ns_tab, sizeof(zx_ns_tab));
  len = zx_LEN_WO_cdm_ORGNAME(c, x );
  buf = ZX_ALLOC(c, len+1);
  return zx_easy_enc_common(c, zx_ENC_WO_cdm_ORGNAME(c, x, buf ), buf, len);
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

#define EL_NAME   cdm_ORGUNIT
#define EL_STRUCT zx_cdm_ORGUNIT_s
#define EL_NS     cdm
#define EL_TAG    ORGUNIT

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

/* FUNC(zx_LEN_SO_cdm_ORGUNIT) */

/* Compute length of an element (and its subelements). The XML attributes
 * and elements are processed in schema order. */

/* Called by: */
int zx_LEN_SO_cdm_ORGUNIT(struct zx_ctx* c, struct zx_cdm_ORGUNIT_s* x )
{
  struct zx_ns_s* pop_seen = 0;
  struct zx_elem_s* se MAYBE_UNUSED;
#if 1 /* NORMALMODE */
  /* *** in simple_elem case should output ns prefix from ns node. */
  int len = sizeof("<cdm:ORGUNIT")-1 + 1 + sizeof("</cdm:ORGUNIT>")-1;
  if (c->inc_ns_len)
    len += zx_len_inc_ns(c, &pop_seen);
  if (x->group)
    len += zx_len_xmlns_if_not_seen(c, zx_ns_tab+zx_xmlns_ix_cb, &pop_seen);
  len += zx_len_xmlns_if_not_seen(c, zx_ns_tab+zx_xmlns_ix_cdm, &pop_seen);

  len += zx_attr_so_len(x->group, sizeof("cb:group")-1);

#else
  /* root node has no begin tag */
  int len = 0;
#endif
  


  len += zx_len_so_common(c, &x->gg);
  zx_pop_seen(pop_seen);
  ENC_LEN_DEBUG(x, "cdm:ORGUNIT", len);
  return len;
}

/* FUNC(zx_LEN_WO_cdm_ORGUNIT) */

/* Compute length of an element (and its subelements). The XML attributes
 * and elements are processed in wire order and no assumptions
 * are made about namespace prefixes. */

/* Called by: */
int zx_LEN_WO_cdm_ORGUNIT(struct zx_ctx* c, struct zx_cdm_ORGUNIT_s* x )
{
  struct zx_ns_s* pop_seen = 0;
  struct zx_elem_s* se MAYBE_UNUSED;
#if 1 /* NORMALMODE */
  int len = 1 + sizeof("ORGUNIT")-1 + 1 + 2 + sizeof("ORGUNIT")-1 + 1;
  
  if (x->gg.g.ns && x->gg.g.ns->prefix_len)
    len += (x->gg.g.ns->prefix_len + 1) * 2;
  if (c->inc_ns_len)
    len += zx_len_inc_ns(c, &pop_seen);
  if (x->group)
    len += zx_len_xmlns_if_not_seen(c, x->group->g.ns, &pop_seen);
  len += zx_len_xmlns_if_not_seen(c, x->gg.g.ns, &pop_seen);

  len += zx_attr_wo_len(x->group, sizeof("group")-1);

#else
  /* root node has no begin tag */
  int len = 0;
#endif
  


  len += zx_len_wo_common(c, &x->gg); 
  zx_pop_seen(pop_seen);
  ENC_LEN_DEBUG(x, "cdm:ORGUNIT", len);
  return len;
}

/* FUNC(zx_ENC_SO_cdm_ORGUNIT) */

/* Render element into string. The XML attributes and elements are
 * processed in schema order. This is what you generally want for
 * rendering new data structure to a string. The wo pointers are not used. */

/* Called by: */
char* zx_ENC_SO_cdm_ORGUNIT(struct zx_ctx* c, struct zx_cdm_ORGUNIT_s* x, char* p )
{
  struct zx_elem_s* se MAYBE_UNUSED;
  struct zx_ns_s* pop_seen = 0;
  ENC_LEN_DEBUG_BASE;
#if 1 /* NORMALMODE */
  /* *** in simple_elem case should output ns prefix from ns node. */
  ZX_OUT_TAG(p, "<cdm:ORGUNIT");
  if (c->inc_ns)
    p = zx_enc_inc_ns(c, p, &pop_seen);
  if (x->group)
    p = zx_enc_xmlns_if_not_seen(c, p, zx_ns_tab+zx_xmlns_ix_cb, &pop_seen);
  p = zx_enc_xmlns_if_not_seen(c, p, zx_ns_tab+zx_xmlns_ix_cdm, &pop_seen);

  p = zx_attr_so_enc(p, x->group, " cb:group=\"", sizeof(" cb:group=\"")-1);

  p = zx_enc_unknown_attrs(p, x->gg.any_attr);
#else
  /* root node has no begin tag */
#endif
  

  p = zx_enc_so_unknown_elems_and_content(c, p, &x->gg);
  
#if 1 /* NORMALMODE */
  ZX_OUT_CLOSE_TAG(p, "</cdm:ORGUNIT>");
  zx_pop_seen(pop_seen);
#else
  /* root node has no end tag either */
#endif
  ENC_LEN_DEBUG(x, "cdm:ORGUNIT", p-enc_base);
  return p;
}

/* FUNC(zx_ENC_WO_cdm_ORGUNIT) */

/* Render element into string. The XML attributes and elements are
 * processed in wire order by chasing wo pointers. This is what you want for
 * validating signatures on other people's XML documents. */

/* Called by: */
char* zx_ENC_WO_cdm_ORGUNIT(struct zx_ctx* c, struct zx_cdm_ORGUNIT_s* x, char* p )
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
  ZX_OUT_MEM(p, "ORGUNIT", sizeof("ORGUNIT")-1);
  qq = p;

  /* *** sort the namespaces */
  if (c->inc_ns)
    zx_add_inc_ns(c, &pop_seen);
  if (x->group)
    zx_add_xmlns_if_not_seen(c, x->group->g.ns, &pop_seen);
  zx_add_xmlns_if_not_seen(c, x->gg.g.ns, &pop_seen);

  p = zx_enc_seen(p, pop_seen); 
  p = zx_attr_wo_enc(p, x->group, "group=\"", sizeof("group=\"")-1);

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
  ENC_LEN_DEBUG(x, "cdm:ORGUNIT", p-enc_base);
  return p;
}

/* FUNC(zx_EASY_ENC_SO_cdm_ORGUNIT) */

/* Called by: */
struct zx_str* zx_EASY_ENC_SO_cdm_ORGUNIT(struct zx_ctx* c, struct zx_cdm_ORGUNIT_s* x )
{
  int len;
  char* buf;
  c->ns_tab = ZX_ALLOC(c, sizeof(zx_ns_tab));
  memcpy(c->ns_tab, zx_ns_tab, sizeof(zx_ns_tab));
  len = zx_LEN_SO_cdm_ORGUNIT(c, x );
  buf = ZX_ALLOC(c, len+1);
  return zx_easy_enc_common(c, zx_ENC_SO_cdm_ORGUNIT(c, x, buf ), buf, len);
}

/* FUNC(zx_EASY_ENC_WO_cdm_ORGUNIT) */

/* Called by: */
struct zx_str* zx_EASY_ENC_WO_cdm_ORGUNIT(struct zx_ctx* c, struct zx_cdm_ORGUNIT_s* x )
{
  int len;
  char* buf;
  c->ns_tab = ZX_ALLOC(c, sizeof(zx_ns_tab));
  memcpy(c->ns_tab, zx_ns_tab, sizeof(zx_ns_tab));
  len = zx_LEN_WO_cdm_ORGUNIT(c, x );
  buf = ZX_ALLOC(c, len+1);
  return zx_easy_enc_common(c, zx_ENC_WO_cdm_ORGUNIT(c, x, buf ), buf, len);
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

#define EL_NAME   cdm_PCODE
#define EL_STRUCT zx_cdm_PCODE_s
#define EL_NS     cdm
#define EL_TAG    PCODE

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

/* FUNC(zx_LEN_SO_cdm_PCODE) */

/* Compute length of an element (and its subelements). The XML attributes
 * and elements are processed in schema order. */

/* Called by: */
int zx_LEN_SO_cdm_PCODE(struct zx_ctx* c, struct zx_cdm_PCODE_s* x )
{
  struct zx_ns_s* pop_seen = 0;
  struct zx_elem_s* se MAYBE_UNUSED;
#if 1 /* NORMALMODE */
  /* *** in simple_elem case should output ns prefix from ns node. */
  int len = sizeof("<cdm:PCODE")-1 + 1 + sizeof("</cdm:PCODE>")-1;
  if (c->inc_ns_len)
    len += zx_len_inc_ns(c, &pop_seen);
  if (x->group)
    len += zx_len_xmlns_if_not_seen(c, zx_ns_tab+zx_xmlns_ix_cb, &pop_seen);
  len += zx_len_xmlns_if_not_seen(c, zx_ns_tab+zx_xmlns_ix_cdm, &pop_seen);

  len += zx_attr_so_len(x->group, sizeof("cb:group")-1);

#else
  /* root node has no begin tag */
  int len = 0;
#endif
  


  len += zx_len_so_common(c, &x->gg);
  zx_pop_seen(pop_seen);
  ENC_LEN_DEBUG(x, "cdm:PCODE", len);
  return len;
}

/* FUNC(zx_LEN_WO_cdm_PCODE) */

/* Compute length of an element (and its subelements). The XML attributes
 * and elements are processed in wire order and no assumptions
 * are made about namespace prefixes. */

/* Called by: */
int zx_LEN_WO_cdm_PCODE(struct zx_ctx* c, struct zx_cdm_PCODE_s* x )
{
  struct zx_ns_s* pop_seen = 0;
  struct zx_elem_s* se MAYBE_UNUSED;
#if 1 /* NORMALMODE */
  int len = 1 + sizeof("PCODE")-1 + 1 + 2 + sizeof("PCODE")-1 + 1;
  
  if (x->gg.g.ns && x->gg.g.ns->prefix_len)
    len += (x->gg.g.ns->prefix_len + 1) * 2;
  if (c->inc_ns_len)
    len += zx_len_inc_ns(c, &pop_seen);
  if (x->group)
    len += zx_len_xmlns_if_not_seen(c, x->group->g.ns, &pop_seen);
  len += zx_len_xmlns_if_not_seen(c, x->gg.g.ns, &pop_seen);

  len += zx_attr_wo_len(x->group, sizeof("group")-1);

#else
  /* root node has no begin tag */
  int len = 0;
#endif
  


  len += zx_len_wo_common(c, &x->gg); 
  zx_pop_seen(pop_seen);
  ENC_LEN_DEBUG(x, "cdm:PCODE", len);
  return len;
}

/* FUNC(zx_ENC_SO_cdm_PCODE) */

/* Render element into string. The XML attributes and elements are
 * processed in schema order. This is what you generally want for
 * rendering new data structure to a string. The wo pointers are not used. */

/* Called by: */
char* zx_ENC_SO_cdm_PCODE(struct zx_ctx* c, struct zx_cdm_PCODE_s* x, char* p )
{
  struct zx_elem_s* se MAYBE_UNUSED;
  struct zx_ns_s* pop_seen = 0;
  ENC_LEN_DEBUG_BASE;
#if 1 /* NORMALMODE */
  /* *** in simple_elem case should output ns prefix from ns node. */
  ZX_OUT_TAG(p, "<cdm:PCODE");
  if (c->inc_ns)
    p = zx_enc_inc_ns(c, p, &pop_seen);
  if (x->group)
    p = zx_enc_xmlns_if_not_seen(c, p, zx_ns_tab+zx_xmlns_ix_cb, &pop_seen);
  p = zx_enc_xmlns_if_not_seen(c, p, zx_ns_tab+zx_xmlns_ix_cdm, &pop_seen);

  p = zx_attr_so_enc(p, x->group, " cb:group=\"", sizeof(" cb:group=\"")-1);

  p = zx_enc_unknown_attrs(p, x->gg.any_attr);
#else
  /* root node has no begin tag */
#endif
  

  p = zx_enc_so_unknown_elems_and_content(c, p, &x->gg);
  
#if 1 /* NORMALMODE */
  ZX_OUT_CLOSE_TAG(p, "</cdm:PCODE>");
  zx_pop_seen(pop_seen);
#else
  /* root node has no end tag either */
#endif
  ENC_LEN_DEBUG(x, "cdm:PCODE", p-enc_base);
  return p;
}

/* FUNC(zx_ENC_WO_cdm_PCODE) */

/* Render element into string. The XML attributes and elements are
 * processed in wire order by chasing wo pointers. This is what you want for
 * validating signatures on other people's XML documents. */

/* Called by: */
char* zx_ENC_WO_cdm_PCODE(struct zx_ctx* c, struct zx_cdm_PCODE_s* x, char* p )
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
  ZX_OUT_MEM(p, "PCODE", sizeof("PCODE")-1);
  qq = p;

  /* *** sort the namespaces */
  if (c->inc_ns)
    zx_add_inc_ns(c, &pop_seen);
  if (x->group)
    zx_add_xmlns_if_not_seen(c, x->group->g.ns, &pop_seen);
  zx_add_xmlns_if_not_seen(c, x->gg.g.ns, &pop_seen);

  p = zx_enc_seen(p, pop_seen); 
  p = zx_attr_wo_enc(p, x->group, "group=\"", sizeof("group=\"")-1);

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
  ENC_LEN_DEBUG(x, "cdm:PCODE", p-enc_base);
  return p;
}

/* FUNC(zx_EASY_ENC_SO_cdm_PCODE) */

/* Called by: */
struct zx_str* zx_EASY_ENC_SO_cdm_PCODE(struct zx_ctx* c, struct zx_cdm_PCODE_s* x )
{
  int len;
  char* buf;
  c->ns_tab = ZX_ALLOC(c, sizeof(zx_ns_tab));
  memcpy(c->ns_tab, zx_ns_tab, sizeof(zx_ns_tab));
  len = zx_LEN_SO_cdm_PCODE(c, x );
  buf = ZX_ALLOC(c, len+1);
  return zx_easy_enc_common(c, zx_ENC_SO_cdm_PCODE(c, x, buf ), buf, len);
}

/* FUNC(zx_EASY_ENC_WO_cdm_PCODE) */

/* Called by: */
struct zx_str* zx_EASY_ENC_WO_cdm_PCODE(struct zx_ctx* c, struct zx_cdm_PCODE_s* x )
{
  int len;
  char* buf;
  c->ns_tab = ZX_ALLOC(c, sizeof(zx_ns_tab));
  memcpy(c->ns_tab, zx_ns_tab, sizeof(zx_ns_tab));
  len = zx_LEN_WO_cdm_PCODE(c, x );
  buf = ZX_ALLOC(c, len+1);
  return zx_easy_enc_common(c, zx_ENC_WO_cdm_PCODE(c, x, buf ), buf, len);
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

#define EL_NAME   cdm_PHONETIC
#define EL_STRUCT zx_cdm_PHONETIC_s
#define EL_NS     cdm
#define EL_TAG    PHONETIC

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

/* FUNC(zx_LEN_SO_cdm_PHONETIC) */

/* Compute length of an element (and its subelements). The XML attributes
 * and elements are processed in schema order. */

/* Called by: */
int zx_LEN_SO_cdm_PHONETIC(struct zx_ctx* c, struct zx_cdm_PHONETIC_s* x )
{
  struct zx_ns_s* pop_seen = 0;
  struct zx_elem_s* se MAYBE_UNUSED;
#if 1 /* NORMALMODE */
  /* *** in simple_elem case should output ns prefix from ns node. */
  int len = sizeof("<cdm:PHONETIC")-1 + 1 + sizeof("</cdm:PHONETIC>")-1;
  if (c->inc_ns_len)
    len += zx_len_inc_ns(c, &pop_seen);
  if (x->group)
    len += zx_len_xmlns_if_not_seen(c, zx_ns_tab+zx_xmlns_ix_cb, &pop_seen);
  len += zx_len_xmlns_if_not_seen(c, zx_ns_tab+zx_xmlns_ix_cdm, &pop_seen);

  len += zx_attr_so_len(x->group, sizeof("cb:group")-1);

#else
  /* root node has no begin tag */
  int len = 0;
#endif
  


  len += zx_len_so_common(c, &x->gg);
  zx_pop_seen(pop_seen);
  ENC_LEN_DEBUG(x, "cdm:PHONETIC", len);
  return len;
}

/* FUNC(zx_LEN_WO_cdm_PHONETIC) */

/* Compute length of an element (and its subelements). The XML attributes
 * and elements are processed in wire order and no assumptions
 * are made about namespace prefixes. */

/* Called by: */
int zx_LEN_WO_cdm_PHONETIC(struct zx_ctx* c, struct zx_cdm_PHONETIC_s* x )
{
  struct zx_ns_s* pop_seen = 0;
  struct zx_elem_s* se MAYBE_UNUSED;
#if 1 /* NORMALMODE */
  int len = 1 + sizeof("PHONETIC")-1 + 1 + 2 + sizeof("PHONETIC")-1 + 1;
  
  if (x->gg.g.ns && x->gg.g.ns->prefix_len)
    len += (x->gg.g.ns->prefix_len + 1) * 2;
  if (c->inc_ns_len)
    len += zx_len_inc_ns(c, &pop_seen);
  if (x->group)
    len += zx_len_xmlns_if_not_seen(c, x->group->g.ns, &pop_seen);
  len += zx_len_xmlns_if_not_seen(c, x->gg.g.ns, &pop_seen);

  len += zx_attr_wo_len(x->group, sizeof("group")-1);

#else
  /* root node has no begin tag */
  int len = 0;
#endif
  


  len += zx_len_wo_common(c, &x->gg); 
  zx_pop_seen(pop_seen);
  ENC_LEN_DEBUG(x, "cdm:PHONETIC", len);
  return len;
}

/* FUNC(zx_ENC_SO_cdm_PHONETIC) */

/* Render element into string. The XML attributes and elements are
 * processed in schema order. This is what you generally want for
 * rendering new data structure to a string. The wo pointers are not used. */

/* Called by: */
char* zx_ENC_SO_cdm_PHONETIC(struct zx_ctx* c, struct zx_cdm_PHONETIC_s* x, char* p )
{
  struct zx_elem_s* se MAYBE_UNUSED;
  struct zx_ns_s* pop_seen = 0;
  ENC_LEN_DEBUG_BASE;
#if 1 /* NORMALMODE */
  /* *** in simple_elem case should output ns prefix from ns node. */
  ZX_OUT_TAG(p, "<cdm:PHONETIC");
  if (c->inc_ns)
    p = zx_enc_inc_ns(c, p, &pop_seen);
  if (x->group)
    p = zx_enc_xmlns_if_not_seen(c, p, zx_ns_tab+zx_xmlns_ix_cb, &pop_seen);
  p = zx_enc_xmlns_if_not_seen(c, p, zx_ns_tab+zx_xmlns_ix_cdm, &pop_seen);

  p = zx_attr_so_enc(p, x->group, " cb:group=\"", sizeof(" cb:group=\"")-1);

  p = zx_enc_unknown_attrs(p, x->gg.any_attr);
#else
  /* root node has no begin tag */
#endif
  

  p = zx_enc_so_unknown_elems_and_content(c, p, &x->gg);
  
#if 1 /* NORMALMODE */
  ZX_OUT_CLOSE_TAG(p, "</cdm:PHONETIC>");
  zx_pop_seen(pop_seen);
#else
  /* root node has no end tag either */
#endif
  ENC_LEN_DEBUG(x, "cdm:PHONETIC", p-enc_base);
  return p;
}

/* FUNC(zx_ENC_WO_cdm_PHONETIC) */

/* Render element into string. The XML attributes and elements are
 * processed in wire order by chasing wo pointers. This is what you want for
 * validating signatures on other people's XML documents. */

/* Called by: */
char* zx_ENC_WO_cdm_PHONETIC(struct zx_ctx* c, struct zx_cdm_PHONETIC_s* x, char* p )
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
  ZX_OUT_MEM(p, "PHONETIC", sizeof("PHONETIC")-1);
  qq = p;

  /* *** sort the namespaces */
  if (c->inc_ns)
    zx_add_inc_ns(c, &pop_seen);
  if (x->group)
    zx_add_xmlns_if_not_seen(c, x->group->g.ns, &pop_seen);
  zx_add_xmlns_if_not_seen(c, x->gg.g.ns, &pop_seen);

  p = zx_enc_seen(p, pop_seen); 
  p = zx_attr_wo_enc(p, x->group, "group=\"", sizeof("group=\"")-1);

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
  ENC_LEN_DEBUG(x, "cdm:PHONETIC", p-enc_base);
  return p;
}

/* FUNC(zx_EASY_ENC_SO_cdm_PHONETIC) */

/* Called by: */
struct zx_str* zx_EASY_ENC_SO_cdm_PHONETIC(struct zx_ctx* c, struct zx_cdm_PHONETIC_s* x )
{
  int len;
  char* buf;
  c->ns_tab = ZX_ALLOC(c, sizeof(zx_ns_tab));
  memcpy(c->ns_tab, zx_ns_tab, sizeof(zx_ns_tab));
  len = zx_LEN_SO_cdm_PHONETIC(c, x );
  buf = ZX_ALLOC(c, len+1);
  return zx_easy_enc_common(c, zx_ENC_SO_cdm_PHONETIC(c, x, buf ), buf, len);
}

/* FUNC(zx_EASY_ENC_WO_cdm_PHONETIC) */

/* Called by: */
struct zx_str* zx_EASY_ENC_WO_cdm_PHONETIC(struct zx_ctx* c, struct zx_cdm_PHONETIC_s* x )
{
  int len;
  char* buf;
  c->ns_tab = ZX_ALLOC(c, sizeof(zx_ns_tab));
  memcpy(c->ns_tab, zx_ns_tab, sizeof(zx_ns_tab));
  len = zx_LEN_WO_cdm_PHONETIC(c, x );
  buf = ZX_ALLOC(c, len+1);
  return zx_easy_enc_common(c, zx_ENC_WO_cdm_PHONETIC(c, x, buf ), buf, len);
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

#define EL_NAME   cdm_PHOTO
#define EL_STRUCT zx_cdm_PHOTO_s
#define EL_NS     cdm
#define EL_TAG    PHOTO

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

/* FUNC(zx_LEN_SO_cdm_PHOTO) */

/* Compute length of an element (and its subelements). The XML attributes
 * and elements are processed in schema order. */

/* Called by: */
int zx_LEN_SO_cdm_PHOTO(struct zx_ctx* c, struct zx_cdm_PHOTO_s* x )
{
  struct zx_ns_s* pop_seen = 0;
  struct zx_elem_s* se MAYBE_UNUSED;
#if 1 /* NORMALMODE */
  /* *** in simple_elem case should output ns prefix from ns node. */
  int len = sizeof("<cdm:PHOTO")-1 + 1 + sizeof("</cdm:PHOTO>")-1;
  if (c->inc_ns_len)
    len += zx_len_inc_ns(c, &pop_seen);
  if (x->id || x->modificationTime)
    len += zx_len_xmlns_if_not_seen(c, zx_ns_tab+zx_xmlns_ix_cb, &pop_seen);
  len += zx_len_xmlns_if_not_seen(c, zx_ns_tab+zx_xmlns_ix_cdm, &pop_seen);

  len += zx_attr_so_len(x->id, sizeof("cb:id")-1);
  len += zx_attr_so_len(x->modificationTime, sizeof("cb:modificationTime")-1);

#else
  /* root node has no begin tag */
  int len = 0;
#endif
  
  {
      struct zx_cdm_TYPE_s* e;
      for (e = x->TYPE; e; e = (struct zx_cdm_TYPE_s*)e->gg.g.n)
	  len += zx_LEN_SO_cdm_TYPE(c, e);
  }
  {
      struct zx_cdm_BINVAL_s* e;
      for (e = x->BINVAL; e; e = (struct zx_cdm_BINVAL_s*)e->gg.g.n)
	  len += zx_LEN_SO_cdm_BINVAL(c, e);
  }
  {
      struct zx_cdm_EXTVAL_s* e;
      for (e = x->EXTVAL; e; e = (struct zx_cdm_EXTVAL_s*)e->gg.g.n)
	  len += zx_LEN_SO_cdm_EXTVAL(c, e);
  }


  len += zx_len_so_common(c, &x->gg);
  zx_pop_seen(pop_seen);
  ENC_LEN_DEBUG(x, "cdm:PHOTO", len);
  return len;
}

/* FUNC(zx_LEN_WO_cdm_PHOTO) */

/* Compute length of an element (and its subelements). The XML attributes
 * and elements are processed in wire order and no assumptions
 * are made about namespace prefixes. */

/* Called by: */
int zx_LEN_WO_cdm_PHOTO(struct zx_ctx* c, struct zx_cdm_PHOTO_s* x )
{
  struct zx_ns_s* pop_seen = 0;
  struct zx_elem_s* se MAYBE_UNUSED;
#if 1 /* NORMALMODE */
  int len = 1 + sizeof("PHOTO")-1 + 1 + 2 + sizeof("PHOTO")-1 + 1;
  
  if (x->gg.g.ns && x->gg.g.ns->prefix_len)
    len += (x->gg.g.ns->prefix_len + 1) * 2;
  if (c->inc_ns_len)
    len += zx_len_inc_ns(c, &pop_seen);
  if (x->id)
    len += zx_len_xmlns_if_not_seen(c, x->id->g.ns, &pop_seen);
  if (x->modificationTime)
    len += zx_len_xmlns_if_not_seen(c, x->modificationTime->g.ns, &pop_seen);
  len += zx_len_xmlns_if_not_seen(c, x->gg.g.ns, &pop_seen);

  len += zx_attr_wo_len(x->id, sizeof("id")-1);
  len += zx_attr_wo_len(x->modificationTime, sizeof("modificationTime")-1);

#else
  /* root node has no begin tag */
  int len = 0;
#endif
  
  {
      struct zx_cdm_TYPE_s* e;
      for (e = x->TYPE; e; e = (struct zx_cdm_TYPE_s*)e->gg.g.n)
	  len += zx_LEN_WO_cdm_TYPE(c, e);
  }
  {
      struct zx_cdm_BINVAL_s* e;
      for (e = x->BINVAL; e; e = (struct zx_cdm_BINVAL_s*)e->gg.g.n)
	  len += zx_LEN_WO_cdm_BINVAL(c, e);
  }
  {
      struct zx_cdm_EXTVAL_s* e;
      for (e = x->EXTVAL; e; e = (struct zx_cdm_EXTVAL_s*)e->gg.g.n)
	  len += zx_LEN_WO_cdm_EXTVAL(c, e);
  }


  len += zx_len_wo_common(c, &x->gg); 
  zx_pop_seen(pop_seen);
  ENC_LEN_DEBUG(x, "cdm:PHOTO", len);
  return len;
}

/* FUNC(zx_ENC_SO_cdm_PHOTO) */

/* Render element into string. The XML attributes and elements are
 * processed in schema order. This is what you generally want for
 * rendering new data structure to a string. The wo pointers are not used. */

/* Called by: */
char* zx_ENC_SO_cdm_PHOTO(struct zx_ctx* c, struct zx_cdm_PHOTO_s* x, char* p )
{
  struct zx_elem_s* se MAYBE_UNUSED;
  struct zx_ns_s* pop_seen = 0;
  ENC_LEN_DEBUG_BASE;
#if 1 /* NORMALMODE */
  /* *** in simple_elem case should output ns prefix from ns node. */
  ZX_OUT_TAG(p, "<cdm:PHOTO");
  if (c->inc_ns)
    p = zx_enc_inc_ns(c, p, &pop_seen);
  if (x->id || x->modificationTime)
    p = zx_enc_xmlns_if_not_seen(c, p, zx_ns_tab+zx_xmlns_ix_cb, &pop_seen);
  p = zx_enc_xmlns_if_not_seen(c, p, zx_ns_tab+zx_xmlns_ix_cdm, &pop_seen);

  p = zx_attr_so_enc(p, x->id, " cb:id=\"", sizeof(" cb:id=\"")-1);
  p = zx_attr_so_enc(p, x->modificationTime, " cb:modificationTime=\"", sizeof(" cb:modificationTime=\"")-1);

  p = zx_enc_unknown_attrs(p, x->gg.any_attr);
#else
  /* root node has no begin tag */
#endif
  
  {
      struct zx_cdm_TYPE_s* e;
      for (e = x->TYPE; e; e = (struct zx_cdm_TYPE_s*)e->gg.g.n)
	  p = zx_ENC_SO_cdm_TYPE(c, e, p);
  }
  {
      struct zx_cdm_BINVAL_s* e;
      for (e = x->BINVAL; e; e = (struct zx_cdm_BINVAL_s*)e->gg.g.n)
	  p = zx_ENC_SO_cdm_BINVAL(c, e, p);
  }
  {
      struct zx_cdm_EXTVAL_s* e;
      for (e = x->EXTVAL; e; e = (struct zx_cdm_EXTVAL_s*)e->gg.g.n)
	  p = zx_ENC_SO_cdm_EXTVAL(c, e, p);
  }

  p = zx_enc_so_unknown_elems_and_content(c, p, &x->gg);
  
#if 1 /* NORMALMODE */
  ZX_OUT_CLOSE_TAG(p, "</cdm:PHOTO>");
  zx_pop_seen(pop_seen);
#else
  /* root node has no end tag either */
#endif
  ENC_LEN_DEBUG(x, "cdm:PHOTO", p-enc_base);
  return p;
}

/* FUNC(zx_ENC_WO_cdm_PHOTO) */

/* Render element into string. The XML attributes and elements are
 * processed in wire order by chasing wo pointers. This is what you want for
 * validating signatures on other people's XML documents. */

/* Called by: */
char* zx_ENC_WO_cdm_PHOTO(struct zx_ctx* c, struct zx_cdm_PHOTO_s* x, char* p )
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
  ZX_OUT_MEM(p, "PHOTO", sizeof("PHOTO")-1);
  qq = p;

  /* *** sort the namespaces */
  if (c->inc_ns)
    zx_add_inc_ns(c, &pop_seen);
  if (x->id)
    zx_add_xmlns_if_not_seen(c, x->id->g.ns, &pop_seen);
  if (x->modificationTime)
    zx_add_xmlns_if_not_seen(c, x->modificationTime->g.ns, &pop_seen);
  zx_add_xmlns_if_not_seen(c, x->gg.g.ns, &pop_seen);

  p = zx_enc_seen(p, pop_seen); 
  p = zx_attr_wo_enc(p, x->id, "id=\"", sizeof("id=\"")-1);
  p = zx_attr_wo_enc(p, x->modificationTime, "modificationTime=\"", sizeof("modificationTime=\"")-1);

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
  ENC_LEN_DEBUG(x, "cdm:PHOTO", p-enc_base);
  return p;
}

/* FUNC(zx_EASY_ENC_SO_cdm_PHOTO) */

/* Called by: */
struct zx_str* zx_EASY_ENC_SO_cdm_PHOTO(struct zx_ctx* c, struct zx_cdm_PHOTO_s* x )
{
  int len;
  char* buf;
  c->ns_tab = ZX_ALLOC(c, sizeof(zx_ns_tab));
  memcpy(c->ns_tab, zx_ns_tab, sizeof(zx_ns_tab));
  len = zx_LEN_SO_cdm_PHOTO(c, x );
  buf = ZX_ALLOC(c, len+1);
  return zx_easy_enc_common(c, zx_ENC_SO_cdm_PHOTO(c, x, buf ), buf, len);
}

/* FUNC(zx_EASY_ENC_WO_cdm_PHOTO) */

/* Called by: */
struct zx_str* zx_EASY_ENC_WO_cdm_PHOTO(struct zx_ctx* c, struct zx_cdm_PHOTO_s* x )
{
  int len;
  char* buf;
  c->ns_tab = ZX_ALLOC(c, sizeof(zx_ns_tab));
  memcpy(c->ns_tab, zx_ns_tab, sizeof(zx_ns_tab));
  len = zx_LEN_WO_cdm_PHOTO(c, x );
  buf = ZX_ALLOC(c, len+1);
  return zx_easy_enc_common(c, zx_ENC_WO_cdm_PHOTO(c, x, buf ), buf, len);
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

#define EL_NAME   cdm_PHYSICALACCESS
#define EL_STRUCT zx_cdm_PHYSICALACCESS_s
#define EL_NS     cdm
#define EL_TAG    PHYSICALACCESS

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

/* FUNC(zx_LEN_SO_cdm_PHYSICALACCESS) */

/* Compute length of an element (and its subelements). The XML attributes
 * and elements are processed in schema order. */

/* Called by: */
int zx_LEN_SO_cdm_PHYSICALACCESS(struct zx_ctx* c, struct zx_cdm_PHYSICALACCESS_s* x )
{
  struct zx_ns_s* pop_seen = 0;
  struct zx_elem_s* se MAYBE_UNUSED;
#if 1 /* NORMALMODE */
  /* *** in simple_elem case should output ns prefix from ns node. */
  int len = sizeof("<cdm:PHYSICALACCESS")-1 + 1 + sizeof("</cdm:PHYSICALACCESS>")-1;
  if (c->inc_ns_len)
    len += zx_len_inc_ns(c, &pop_seen);
  if (x->group)
    len += zx_len_xmlns_if_not_seen(c, zx_ns_tab+zx_xmlns_ix_cb, &pop_seen);
  len += zx_len_xmlns_if_not_seen(c, zx_ns_tab+zx_xmlns_ix_cdm, &pop_seen);

  len += zx_attr_so_len(x->group, sizeof("cb:group")-1);

#else
  /* root node has no begin tag */
  int len = 0;
#endif
  


  len += zx_len_so_common(c, &x->gg);
  zx_pop_seen(pop_seen);
  ENC_LEN_DEBUG(x, "cdm:PHYSICALACCESS", len);
  return len;
}

/* FUNC(zx_LEN_WO_cdm_PHYSICALACCESS) */

/* Compute length of an element (and its subelements). The XML attributes
 * and elements are processed in wire order and no assumptions
 * are made about namespace prefixes. */

/* Called by: */
int zx_LEN_WO_cdm_PHYSICALACCESS(struct zx_ctx* c, struct zx_cdm_PHYSICALACCESS_s* x )
{
  struct zx_ns_s* pop_seen = 0;
  struct zx_elem_s* se MAYBE_UNUSED;
#if 1 /* NORMALMODE */
  int len = 1 + sizeof("PHYSICALACCESS")-1 + 1 + 2 + sizeof("PHYSICALACCESS")-1 + 1;
  
  if (x->gg.g.ns && x->gg.g.ns->prefix_len)
    len += (x->gg.g.ns->prefix_len + 1) * 2;
  if (c->inc_ns_len)
    len += zx_len_inc_ns(c, &pop_seen);
  if (x->group)
    len += zx_len_xmlns_if_not_seen(c, x->group->g.ns, &pop_seen);
  len += zx_len_xmlns_if_not_seen(c, x->gg.g.ns, &pop_seen);

  len += zx_attr_wo_len(x->group, sizeof("group")-1);

#else
  /* root node has no begin tag */
  int len = 0;
#endif
  


  len += zx_len_wo_common(c, &x->gg); 
  zx_pop_seen(pop_seen);
  ENC_LEN_DEBUG(x, "cdm:PHYSICALACCESS", len);
  return len;
}

/* FUNC(zx_ENC_SO_cdm_PHYSICALACCESS) */

/* Render element into string. The XML attributes and elements are
 * processed in schema order. This is what you generally want for
 * rendering new data structure to a string. The wo pointers are not used. */

/* Called by: */
char* zx_ENC_SO_cdm_PHYSICALACCESS(struct zx_ctx* c, struct zx_cdm_PHYSICALACCESS_s* x, char* p )
{
  struct zx_elem_s* se MAYBE_UNUSED;
  struct zx_ns_s* pop_seen = 0;
  ENC_LEN_DEBUG_BASE;
#if 1 /* NORMALMODE */
  /* *** in simple_elem case should output ns prefix from ns node. */
  ZX_OUT_TAG(p, "<cdm:PHYSICALACCESS");
  if (c->inc_ns)
    p = zx_enc_inc_ns(c, p, &pop_seen);
  if (x->group)
    p = zx_enc_xmlns_if_not_seen(c, p, zx_ns_tab+zx_xmlns_ix_cb, &pop_seen);
  p = zx_enc_xmlns_if_not_seen(c, p, zx_ns_tab+zx_xmlns_ix_cdm, &pop_seen);

  p = zx_attr_so_enc(p, x->group, " cb:group=\"", sizeof(" cb:group=\"")-1);

  p = zx_enc_unknown_attrs(p, x->gg.any_attr);
#else
  /* root node has no begin tag */
#endif
  

  p = zx_enc_so_unknown_elems_and_content(c, p, &x->gg);
  
#if 1 /* NORMALMODE */
  ZX_OUT_CLOSE_TAG(p, "</cdm:PHYSICALACCESS>");
  zx_pop_seen(pop_seen);
#else
  /* root node has no end tag either */
#endif
  ENC_LEN_DEBUG(x, "cdm:PHYSICALACCESS", p-enc_base);
  return p;
}

/* FUNC(zx_ENC_WO_cdm_PHYSICALACCESS) */

/* Render element into string. The XML attributes and elements are
 * processed in wire order by chasing wo pointers. This is what you want for
 * validating signatures on other people's XML documents. */

/* Called by: */
char* zx_ENC_WO_cdm_PHYSICALACCESS(struct zx_ctx* c, struct zx_cdm_PHYSICALACCESS_s* x, char* p )
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
  ZX_OUT_MEM(p, "PHYSICALACCESS", sizeof("PHYSICALACCESS")-1);
  qq = p;

  /* *** sort the namespaces */
  if (c->inc_ns)
    zx_add_inc_ns(c, &pop_seen);
  if (x->group)
    zx_add_xmlns_if_not_seen(c, x->group->g.ns, &pop_seen);
  zx_add_xmlns_if_not_seen(c, x->gg.g.ns, &pop_seen);

  p = zx_enc_seen(p, pop_seen); 
  p = zx_attr_wo_enc(p, x->group, "group=\"", sizeof("group=\"")-1);

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
  ENC_LEN_DEBUG(x, "cdm:PHYSICALACCESS", p-enc_base);
  return p;
}

/* FUNC(zx_EASY_ENC_SO_cdm_PHYSICALACCESS) */

/* Called by: */
struct zx_str* zx_EASY_ENC_SO_cdm_PHYSICALACCESS(struct zx_ctx* c, struct zx_cdm_PHYSICALACCESS_s* x )
{
  int len;
  char* buf;
  c->ns_tab = ZX_ALLOC(c, sizeof(zx_ns_tab));
  memcpy(c->ns_tab, zx_ns_tab, sizeof(zx_ns_tab));
  len = zx_LEN_SO_cdm_PHYSICALACCESS(c, x );
  buf = ZX_ALLOC(c, len+1);
  return zx_easy_enc_common(c, zx_ENC_SO_cdm_PHYSICALACCESS(c, x, buf ), buf, len);
}

/* FUNC(zx_EASY_ENC_WO_cdm_PHYSICALACCESS) */

/* Called by: */
struct zx_str* zx_EASY_ENC_WO_cdm_PHYSICALACCESS(struct zx_ctx* c, struct zx_cdm_PHYSICALACCESS_s* x )
{
  int len;
  char* buf;
  c->ns_tab = ZX_ALLOC(c, sizeof(zx_ns_tab));
  memcpy(c->ns_tab, zx_ns_tab, sizeof(zx_ns_tab));
  len = zx_LEN_WO_cdm_PHYSICALACCESS(c, x );
  buf = ZX_ALLOC(c, len+1);
  return zx_easy_enc_common(c, zx_ENC_WO_cdm_PHYSICALACCESS(c, x, buf ), buf, len);
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

#define EL_NAME   cdm_POBOX
#define EL_STRUCT zx_cdm_POBOX_s
#define EL_NS     cdm
#define EL_TAG    POBOX

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

/* FUNC(zx_LEN_SO_cdm_POBOX) */

/* Compute length of an element (and its subelements). The XML attributes
 * and elements are processed in schema order. */

/* Called by: */
int zx_LEN_SO_cdm_POBOX(struct zx_ctx* c, struct zx_cdm_POBOX_s* x )
{
  struct zx_ns_s* pop_seen = 0;
  struct zx_elem_s* se MAYBE_UNUSED;
#if 1 /* NORMALMODE */
  /* *** in simple_elem case should output ns prefix from ns node. */
  int len = sizeof("<cdm:POBOX")-1 + 1 + sizeof("</cdm:POBOX>")-1;
  if (c->inc_ns_len)
    len += zx_len_inc_ns(c, &pop_seen);
  if (x->group)
    len += zx_len_xmlns_if_not_seen(c, zx_ns_tab+zx_xmlns_ix_cb, &pop_seen);
  len += zx_len_xmlns_if_not_seen(c, zx_ns_tab+zx_xmlns_ix_cdm, &pop_seen);

  len += zx_attr_so_len(x->group, sizeof("cb:group")-1);

#else
  /* root node has no begin tag */
  int len = 0;
#endif
  


  len += zx_len_so_common(c, &x->gg);
  zx_pop_seen(pop_seen);
  ENC_LEN_DEBUG(x, "cdm:POBOX", len);
  return len;
}

/* FUNC(zx_LEN_WO_cdm_POBOX) */

/* Compute length of an element (and its subelements). The XML attributes
 * and elements are processed in wire order and no assumptions
 * are made about namespace prefixes. */

/* Called by: */
int zx_LEN_WO_cdm_POBOX(struct zx_ctx* c, struct zx_cdm_POBOX_s* x )
{
  struct zx_ns_s* pop_seen = 0;
  struct zx_elem_s* se MAYBE_UNUSED;
#if 1 /* NORMALMODE */
  int len = 1 + sizeof("POBOX")-1 + 1 + 2 + sizeof("POBOX")-1 + 1;
  
  if (x->gg.g.ns && x->gg.g.ns->prefix_len)
    len += (x->gg.g.ns->prefix_len + 1) * 2;
  if (c->inc_ns_len)
    len += zx_len_inc_ns(c, &pop_seen);
  if (x->group)
    len += zx_len_xmlns_if_not_seen(c, x->group->g.ns, &pop_seen);
  len += zx_len_xmlns_if_not_seen(c, x->gg.g.ns, &pop_seen);

  len += zx_attr_wo_len(x->group, sizeof("group")-1);

#else
  /* root node has no begin tag */
  int len = 0;
#endif
  


  len += zx_len_wo_common(c, &x->gg); 
  zx_pop_seen(pop_seen);
  ENC_LEN_DEBUG(x, "cdm:POBOX", len);
  return len;
}

/* FUNC(zx_ENC_SO_cdm_POBOX) */

/* Render element into string. The XML attributes and elements are
 * processed in schema order. This is what you generally want for
 * rendering new data structure to a string. The wo pointers are not used. */

/* Called by: */
char* zx_ENC_SO_cdm_POBOX(struct zx_ctx* c, struct zx_cdm_POBOX_s* x, char* p )
{
  struct zx_elem_s* se MAYBE_UNUSED;
  struct zx_ns_s* pop_seen = 0;
  ENC_LEN_DEBUG_BASE;
#if 1 /* NORMALMODE */
  /* *** in simple_elem case should output ns prefix from ns node. */
  ZX_OUT_TAG(p, "<cdm:POBOX");
  if (c->inc_ns)
    p = zx_enc_inc_ns(c, p, &pop_seen);
  if (x->group)
    p = zx_enc_xmlns_if_not_seen(c, p, zx_ns_tab+zx_xmlns_ix_cb, &pop_seen);
  p = zx_enc_xmlns_if_not_seen(c, p, zx_ns_tab+zx_xmlns_ix_cdm, &pop_seen);

  p = zx_attr_so_enc(p, x->group, " cb:group=\"", sizeof(" cb:group=\"")-1);

  p = zx_enc_unknown_attrs(p, x->gg.any_attr);
#else
  /* root node has no begin tag */
#endif
  

  p = zx_enc_so_unknown_elems_and_content(c, p, &x->gg);
  
#if 1 /* NORMALMODE */
  ZX_OUT_CLOSE_TAG(p, "</cdm:POBOX>");
  zx_pop_seen(pop_seen);
#else
  /* root node has no end tag either */
#endif
  ENC_LEN_DEBUG(x, "cdm:POBOX", p-enc_base);
  return p;
}

/* FUNC(zx_ENC_WO_cdm_POBOX) */

/* Render element into string. The XML attributes and elements are
 * processed in wire order by chasing wo pointers. This is what you want for
 * validating signatures on other people's XML documents. */

/* Called by: */
char* zx_ENC_WO_cdm_POBOX(struct zx_ctx* c, struct zx_cdm_POBOX_s* x, char* p )
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
  ZX_OUT_MEM(p, "POBOX", sizeof("POBOX")-1);
  qq = p;

  /* *** sort the namespaces */
  if (c->inc_ns)
    zx_add_inc_ns(c, &pop_seen);
  if (x->group)
    zx_add_xmlns_if_not_seen(c, x->group->g.ns, &pop_seen);
  zx_add_xmlns_if_not_seen(c, x->gg.g.ns, &pop_seen);

  p = zx_enc_seen(p, pop_seen); 
  p = zx_attr_wo_enc(p, x->group, "group=\"", sizeof("group=\"")-1);

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
  ENC_LEN_DEBUG(x, "cdm:POBOX", p-enc_base);
  return p;
}

/* FUNC(zx_EASY_ENC_SO_cdm_POBOX) */

/* Called by: */
struct zx_str* zx_EASY_ENC_SO_cdm_POBOX(struct zx_ctx* c, struct zx_cdm_POBOX_s* x )
{
  int len;
  char* buf;
  c->ns_tab = ZX_ALLOC(c, sizeof(zx_ns_tab));
  memcpy(c->ns_tab, zx_ns_tab, sizeof(zx_ns_tab));
  len = zx_LEN_SO_cdm_POBOX(c, x );
  buf = ZX_ALLOC(c, len+1);
  return zx_easy_enc_common(c, zx_ENC_SO_cdm_POBOX(c, x, buf ), buf, len);
}

/* FUNC(zx_EASY_ENC_WO_cdm_POBOX) */

/* Called by: */
struct zx_str* zx_EASY_ENC_WO_cdm_POBOX(struct zx_ctx* c, struct zx_cdm_POBOX_s* x )
{
  int len;
  char* buf;
  c->ns_tab = ZX_ALLOC(c, sizeof(zx_ns_tab));
  memcpy(c->ns_tab, zx_ns_tab, sizeof(zx_ns_tab));
  len = zx_LEN_WO_cdm_POBOX(c, x );
  buf = ZX_ALLOC(c, len+1);
  return zx_easy_enc_common(c, zx_ENC_WO_cdm_POBOX(c, x, buf ), buf, len);
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

#define EL_NAME   cdm_PREFIX
#define EL_STRUCT zx_cdm_PREFIX_s
#define EL_NS     cdm
#define EL_TAG    PREFIX

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

/* FUNC(zx_LEN_SO_cdm_PREFIX) */

/* Compute length of an element (and its subelements). The XML attributes
 * and elements are processed in schema order. */

/* Called by: */
int zx_LEN_SO_cdm_PREFIX(struct zx_ctx* c, struct zx_cdm_PREFIX_s* x )
{
  struct zx_ns_s* pop_seen = 0;
  struct zx_elem_s* se MAYBE_UNUSED;
#if 1 /* NORMALMODE */
  /* *** in simple_elem case should output ns prefix from ns node. */
  int len = sizeof("<cdm:PREFIX")-1 + 1 + sizeof("</cdm:PREFIX>")-1;
  if (c->inc_ns_len)
    len += zx_len_inc_ns(c, &pop_seen);
  if (x->group)
    len += zx_len_xmlns_if_not_seen(c, zx_ns_tab+zx_xmlns_ix_cb, &pop_seen);
  len += zx_len_xmlns_if_not_seen(c, zx_ns_tab+zx_xmlns_ix_cdm, &pop_seen);

  len += zx_attr_so_len(x->group, sizeof("cb:group")-1);

#else
  /* root node has no begin tag */
  int len = 0;
#endif
  


  len += zx_len_so_common(c, &x->gg);
  zx_pop_seen(pop_seen);
  ENC_LEN_DEBUG(x, "cdm:PREFIX", len);
  return len;
}

/* FUNC(zx_LEN_WO_cdm_PREFIX) */

/* Compute length of an element (and its subelements). The XML attributes
 * and elements are processed in wire order and no assumptions
 * are made about namespace prefixes. */

/* Called by: */
int zx_LEN_WO_cdm_PREFIX(struct zx_ctx* c, struct zx_cdm_PREFIX_s* x )
{
  struct zx_ns_s* pop_seen = 0;
  struct zx_elem_s* se MAYBE_UNUSED;
#if 1 /* NORMALMODE */
  int len = 1 + sizeof("PREFIX")-1 + 1 + 2 + sizeof("PREFIX")-1 + 1;
  
  if (x->gg.g.ns && x->gg.g.ns->prefix_len)
    len += (x->gg.g.ns->prefix_len + 1) * 2;
  if (c->inc_ns_len)
    len += zx_len_inc_ns(c, &pop_seen);
  if (x->group)
    len += zx_len_xmlns_if_not_seen(c, x->group->g.ns, &pop_seen);
  len += zx_len_xmlns_if_not_seen(c, x->gg.g.ns, &pop_seen);

  len += zx_attr_wo_len(x->group, sizeof("group")-1);

#else
  /* root node has no begin tag */
  int len = 0;
#endif
  


  len += zx_len_wo_common(c, &x->gg); 
  zx_pop_seen(pop_seen);
  ENC_LEN_DEBUG(x, "cdm:PREFIX", len);
  return len;
}

/* FUNC(zx_ENC_SO_cdm_PREFIX) */

/* Render element into string. The XML attributes and elements are
 * processed in schema order. This is what you generally want for
 * rendering new data structure to a string. The wo pointers are not used. */

/* Called by: */
char* zx_ENC_SO_cdm_PREFIX(struct zx_ctx* c, struct zx_cdm_PREFIX_s* x, char* p )
{
  struct zx_elem_s* se MAYBE_UNUSED;
  struct zx_ns_s* pop_seen = 0;
  ENC_LEN_DEBUG_BASE;
#if 1 /* NORMALMODE */
  /* *** in simple_elem case should output ns prefix from ns node. */
  ZX_OUT_TAG(p, "<cdm:PREFIX");
  if (c->inc_ns)
    p = zx_enc_inc_ns(c, p, &pop_seen);
  if (x->group)
    p = zx_enc_xmlns_if_not_seen(c, p, zx_ns_tab+zx_xmlns_ix_cb, &pop_seen);
  p = zx_enc_xmlns_if_not_seen(c, p, zx_ns_tab+zx_xmlns_ix_cdm, &pop_seen);

  p = zx_attr_so_enc(p, x->group, " cb:group=\"", sizeof(" cb:group=\"")-1);

  p = zx_enc_unknown_attrs(p, x->gg.any_attr);
#else
  /* root node has no begin tag */
#endif
  

  p = zx_enc_so_unknown_elems_and_content(c, p, &x->gg);
  
#if 1 /* NORMALMODE */
  ZX_OUT_CLOSE_TAG(p, "</cdm:PREFIX>");
  zx_pop_seen(pop_seen);
#else
  /* root node has no end tag either */
#endif
  ENC_LEN_DEBUG(x, "cdm:PREFIX", p-enc_base);
  return p;
}

/* FUNC(zx_ENC_WO_cdm_PREFIX) */

/* Render element into string. The XML attributes and elements are
 * processed in wire order by chasing wo pointers. This is what you want for
 * validating signatures on other people's XML documents. */

/* Called by: */
char* zx_ENC_WO_cdm_PREFIX(struct zx_ctx* c, struct zx_cdm_PREFIX_s* x, char* p )
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
  ZX_OUT_MEM(p, "PREFIX", sizeof("PREFIX")-1);
  qq = p;

  /* *** sort the namespaces */
  if (c->inc_ns)
    zx_add_inc_ns(c, &pop_seen);
  if (x->group)
    zx_add_xmlns_if_not_seen(c, x->group->g.ns, &pop_seen);
  zx_add_xmlns_if_not_seen(c, x->gg.g.ns, &pop_seen);

  p = zx_enc_seen(p, pop_seen); 
  p = zx_attr_wo_enc(p, x->group, "group=\"", sizeof("group=\"")-1);

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
  ENC_LEN_DEBUG(x, "cdm:PREFIX", p-enc_base);
  return p;
}

/* FUNC(zx_EASY_ENC_SO_cdm_PREFIX) */

/* Called by: */
struct zx_str* zx_EASY_ENC_SO_cdm_PREFIX(struct zx_ctx* c, struct zx_cdm_PREFIX_s* x )
{
  int len;
  char* buf;
  c->ns_tab = ZX_ALLOC(c, sizeof(zx_ns_tab));
  memcpy(c->ns_tab, zx_ns_tab, sizeof(zx_ns_tab));
  len = zx_LEN_SO_cdm_PREFIX(c, x );
  buf = ZX_ALLOC(c, len+1);
  return zx_easy_enc_common(c, zx_ENC_SO_cdm_PREFIX(c, x, buf ), buf, len);
}

/* FUNC(zx_EASY_ENC_WO_cdm_PREFIX) */

/* Called by: */
struct zx_str* zx_EASY_ENC_WO_cdm_PREFIX(struct zx_ctx* c, struct zx_cdm_PREFIX_s* x )
{
  int len;
  char* buf;
  c->ns_tab = ZX_ALLOC(c, sizeof(zx_ns_tab));
  memcpy(c->ns_tab, zx_ns_tab, sizeof(zx_ns_tab));
  len = zx_LEN_WO_cdm_PREFIX(c, x );
  buf = ZX_ALLOC(c, len+1);
  return zx_easy_enc_common(c, zx_ENC_WO_cdm_PREFIX(c, x, buf ), buf, len);
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

#define EL_NAME   cdm_PRODID
#define EL_STRUCT zx_cdm_PRODID_s
#define EL_NS     cdm
#define EL_TAG    PRODID

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

/* FUNC(zx_LEN_SO_cdm_PRODID) */

/* Compute length of an element (and its subelements). The XML attributes
 * and elements are processed in schema order. */

/* Called by: */
int zx_LEN_SO_cdm_PRODID(struct zx_ctx* c, struct zx_cdm_PRODID_s* x )
{
  struct zx_ns_s* pop_seen = 0;
  struct zx_elem_s* se MAYBE_UNUSED;
#if 1 /* NORMALMODE */
  /* *** in simple_elem case should output ns prefix from ns node. */
  int len = sizeof("<cdm:PRODID")-1 + 1 + sizeof("</cdm:PRODID>")-1;
  if (c->inc_ns_len)
    len += zx_len_inc_ns(c, &pop_seen);
  if (x->ACC || x->ACCTime || x->id || x->modificationTime || x->modifier)
    len += zx_len_xmlns_if_not_seen(c, zx_ns_tab+zx_xmlns_ix_cb, &pop_seen);
  len += zx_len_xmlns_if_not_seen(c, zx_ns_tab+zx_xmlns_ix_cdm, &pop_seen);

  len += zx_attr_so_len(x->ACC, sizeof("cb:ACC")-1);
  len += zx_attr_so_len(x->ACCTime, sizeof("cb:ACCTime")-1);
  len += zx_attr_so_len(x->id, sizeof("cb:id")-1);
  len += zx_attr_so_len(x->modificationTime, sizeof("cb:modificationTime")-1);
  len += zx_attr_so_len(x->modifier, sizeof("cb:modifier")-1);

#else
  /* root node has no begin tag */
  int len = 0;
#endif
  


  len += zx_len_so_common(c, &x->gg);
  zx_pop_seen(pop_seen);
  ENC_LEN_DEBUG(x, "cdm:PRODID", len);
  return len;
}

/* FUNC(zx_LEN_WO_cdm_PRODID) */

/* Compute length of an element (and its subelements). The XML attributes
 * and elements are processed in wire order and no assumptions
 * are made about namespace prefixes. */

/* Called by: */
int zx_LEN_WO_cdm_PRODID(struct zx_ctx* c, struct zx_cdm_PRODID_s* x )
{
  struct zx_ns_s* pop_seen = 0;
  struct zx_elem_s* se MAYBE_UNUSED;
#if 1 /* NORMALMODE */
  int len = 1 + sizeof("PRODID")-1 + 1 + 2 + sizeof("PRODID")-1 + 1;
  
  if (x->gg.g.ns && x->gg.g.ns->prefix_len)
    len += (x->gg.g.ns->prefix_len + 1) * 2;
  if (c->inc_ns_len)
    len += zx_len_inc_ns(c, &pop_seen);
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
  len += zx_len_xmlns_if_not_seen(c, x->gg.g.ns, &pop_seen);

  len += zx_attr_wo_len(x->ACC, sizeof("ACC")-1);
  len += zx_attr_wo_len(x->ACCTime, sizeof("ACCTime")-1);
  len += zx_attr_wo_len(x->id, sizeof("id")-1);
  len += zx_attr_wo_len(x->modificationTime, sizeof("modificationTime")-1);
  len += zx_attr_wo_len(x->modifier, sizeof("modifier")-1);

#else
  /* root node has no begin tag */
  int len = 0;
#endif
  


  len += zx_len_wo_common(c, &x->gg); 
  zx_pop_seen(pop_seen);
  ENC_LEN_DEBUG(x, "cdm:PRODID", len);
  return len;
}

/* FUNC(zx_ENC_SO_cdm_PRODID) */

/* Render element into string. The XML attributes and elements are
 * processed in schema order. This is what you generally want for
 * rendering new data structure to a string. The wo pointers are not used. */

/* Called by: */
char* zx_ENC_SO_cdm_PRODID(struct zx_ctx* c, struct zx_cdm_PRODID_s* x, char* p )
{
  struct zx_elem_s* se MAYBE_UNUSED;
  struct zx_ns_s* pop_seen = 0;
  ENC_LEN_DEBUG_BASE;
#if 1 /* NORMALMODE */
  /* *** in simple_elem case should output ns prefix from ns node. */
  ZX_OUT_TAG(p, "<cdm:PRODID");
  if (c->inc_ns)
    p = zx_enc_inc_ns(c, p, &pop_seen);
  if (x->ACC || x->ACCTime || x->id || x->modificationTime || x->modifier)
    p = zx_enc_xmlns_if_not_seen(c, p, zx_ns_tab+zx_xmlns_ix_cb, &pop_seen);
  p = zx_enc_xmlns_if_not_seen(c, p, zx_ns_tab+zx_xmlns_ix_cdm, &pop_seen);

  p = zx_attr_so_enc(p, x->ACC, " cb:ACC=\"", sizeof(" cb:ACC=\"")-1);
  p = zx_attr_so_enc(p, x->ACCTime, " cb:ACCTime=\"", sizeof(" cb:ACCTime=\"")-1);
  p = zx_attr_so_enc(p, x->id, " cb:id=\"", sizeof(" cb:id=\"")-1);
  p = zx_attr_so_enc(p, x->modificationTime, " cb:modificationTime=\"", sizeof(" cb:modificationTime=\"")-1);
  p = zx_attr_so_enc(p, x->modifier, " cb:modifier=\"", sizeof(" cb:modifier=\"")-1);

  p = zx_enc_unknown_attrs(p, x->gg.any_attr);
#else
  /* root node has no begin tag */
#endif
  

  p = zx_enc_so_unknown_elems_and_content(c, p, &x->gg);
  
#if 1 /* NORMALMODE */
  ZX_OUT_CLOSE_TAG(p, "</cdm:PRODID>");
  zx_pop_seen(pop_seen);
#else
  /* root node has no end tag either */
#endif
  ENC_LEN_DEBUG(x, "cdm:PRODID", p-enc_base);
  return p;
}

/* FUNC(zx_ENC_WO_cdm_PRODID) */

/* Render element into string. The XML attributes and elements are
 * processed in wire order by chasing wo pointers. This is what you want for
 * validating signatures on other people's XML documents. */

/* Called by: */
char* zx_ENC_WO_cdm_PRODID(struct zx_ctx* c, struct zx_cdm_PRODID_s* x, char* p )
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
  ZX_OUT_MEM(p, "PRODID", sizeof("PRODID")-1);
  qq = p;

  /* *** sort the namespaces */
  if (c->inc_ns)
    zx_add_inc_ns(c, &pop_seen);
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
  zx_add_xmlns_if_not_seen(c, x->gg.g.ns, &pop_seen);

  p = zx_enc_seen(p, pop_seen); 
  p = zx_attr_wo_enc(p, x->ACC, "ACC=\"", sizeof("ACC=\"")-1);
  p = zx_attr_wo_enc(p, x->ACCTime, "ACCTime=\"", sizeof("ACCTime=\"")-1);
  p = zx_attr_wo_enc(p, x->id, "id=\"", sizeof("id=\"")-1);
  p = zx_attr_wo_enc(p, x->modificationTime, "modificationTime=\"", sizeof("modificationTime=\"")-1);
  p = zx_attr_wo_enc(p, x->modifier, "modifier=\"", sizeof("modifier=\"")-1);

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
  ENC_LEN_DEBUG(x, "cdm:PRODID", p-enc_base);
  return p;
}

/* FUNC(zx_EASY_ENC_SO_cdm_PRODID) */

/* Called by: */
struct zx_str* zx_EASY_ENC_SO_cdm_PRODID(struct zx_ctx* c, struct zx_cdm_PRODID_s* x )
{
  int len;
  char* buf;
  c->ns_tab = ZX_ALLOC(c, sizeof(zx_ns_tab));
  memcpy(c->ns_tab, zx_ns_tab, sizeof(zx_ns_tab));
  len = zx_LEN_SO_cdm_PRODID(c, x );
  buf = ZX_ALLOC(c, len+1);
  return zx_easy_enc_common(c, zx_ENC_SO_cdm_PRODID(c, x, buf ), buf, len);
}

/* FUNC(zx_EASY_ENC_WO_cdm_PRODID) */

/* Called by: */
struct zx_str* zx_EASY_ENC_WO_cdm_PRODID(struct zx_ctx* c, struct zx_cdm_PRODID_s* x )
{
  int len;
  char* buf;
  c->ns_tab = ZX_ALLOC(c, sizeof(zx_ns_tab));
  memcpy(c->ns_tab, zx_ns_tab, sizeof(zx_ns_tab));
  len = zx_LEN_WO_cdm_PRODID(c, x );
  buf = ZX_ALLOC(c, len+1);
  return zx_easy_enc_common(c, zx_ENC_WO_cdm_PRODID(c, x, buf ), buf, len);
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

#define EL_NAME   cdm_REGION
#define EL_STRUCT zx_cdm_REGION_s
#define EL_NS     cdm
#define EL_TAG    REGION

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

/* FUNC(zx_LEN_SO_cdm_REGION) */

/* Compute length of an element (and its subelements). The XML attributes
 * and elements are processed in schema order. */

/* Called by: */
int zx_LEN_SO_cdm_REGION(struct zx_ctx* c, struct zx_cdm_REGION_s* x )
{
  struct zx_ns_s* pop_seen = 0;
  struct zx_elem_s* se MAYBE_UNUSED;
#if 1 /* NORMALMODE */
  /* *** in simple_elem case should output ns prefix from ns node. */
  int len = sizeof("<cdm:REGION")-1 + 1 + sizeof("</cdm:REGION>")-1;
  if (c->inc_ns_len)
    len += zx_len_inc_ns(c, &pop_seen);
  if (x->group)
    len += zx_len_xmlns_if_not_seen(c, zx_ns_tab+zx_xmlns_ix_cb, &pop_seen);
  len += zx_len_xmlns_if_not_seen(c, zx_ns_tab+zx_xmlns_ix_cdm, &pop_seen);

  len += zx_attr_so_len(x->group, sizeof("cb:group")-1);

#else
  /* root node has no begin tag */
  int len = 0;
#endif
  


  len += zx_len_so_common(c, &x->gg);
  zx_pop_seen(pop_seen);
  ENC_LEN_DEBUG(x, "cdm:REGION", len);
  return len;
}

/* FUNC(zx_LEN_WO_cdm_REGION) */

/* Compute length of an element (and its subelements). The XML attributes
 * and elements are processed in wire order and no assumptions
 * are made about namespace prefixes. */

/* Called by: */
int zx_LEN_WO_cdm_REGION(struct zx_ctx* c, struct zx_cdm_REGION_s* x )
{
  struct zx_ns_s* pop_seen = 0;
  struct zx_elem_s* se MAYBE_UNUSED;
#if 1 /* NORMALMODE */
  int len = 1 + sizeof("REGION")-1 + 1 + 2 + sizeof("REGION")-1 + 1;
  
  if (x->gg.g.ns && x->gg.g.ns->prefix_len)
    len += (x->gg.g.ns->prefix_len + 1) * 2;
  if (c->inc_ns_len)
    len += zx_len_inc_ns(c, &pop_seen);
  if (x->group)
    len += zx_len_xmlns_if_not_seen(c, x->group->g.ns, &pop_seen);
  len += zx_len_xmlns_if_not_seen(c, x->gg.g.ns, &pop_seen);

  len += zx_attr_wo_len(x->group, sizeof("group")-1);

#else
  /* root node has no begin tag */
  int len = 0;
#endif
  


  len += zx_len_wo_common(c, &x->gg); 
  zx_pop_seen(pop_seen);
  ENC_LEN_DEBUG(x, "cdm:REGION", len);
  return len;
}

/* FUNC(zx_ENC_SO_cdm_REGION) */

/* Render element into string. The XML attributes and elements are
 * processed in schema order. This is what you generally want for
 * rendering new data structure to a string. The wo pointers are not used. */

/* Called by: */
char* zx_ENC_SO_cdm_REGION(struct zx_ctx* c, struct zx_cdm_REGION_s* x, char* p )
{
  struct zx_elem_s* se MAYBE_UNUSED;
  struct zx_ns_s* pop_seen = 0;
  ENC_LEN_DEBUG_BASE;
#if 1 /* NORMALMODE */
  /* *** in simple_elem case should output ns prefix from ns node. */
  ZX_OUT_TAG(p, "<cdm:REGION");
  if (c->inc_ns)
    p = zx_enc_inc_ns(c, p, &pop_seen);
  if (x->group)
    p = zx_enc_xmlns_if_not_seen(c, p, zx_ns_tab+zx_xmlns_ix_cb, &pop_seen);
  p = zx_enc_xmlns_if_not_seen(c, p, zx_ns_tab+zx_xmlns_ix_cdm, &pop_seen);

  p = zx_attr_so_enc(p, x->group, " cb:group=\"", sizeof(" cb:group=\"")-1);

  p = zx_enc_unknown_attrs(p, x->gg.any_attr);
#else
  /* root node has no begin tag */
#endif
  

  p = zx_enc_so_unknown_elems_and_content(c, p, &x->gg);
  
#if 1 /* NORMALMODE */
  ZX_OUT_CLOSE_TAG(p, "</cdm:REGION>");
  zx_pop_seen(pop_seen);
#else
  /* root node has no end tag either */
#endif
  ENC_LEN_DEBUG(x, "cdm:REGION", p-enc_base);
  return p;
}

/* FUNC(zx_ENC_WO_cdm_REGION) */

/* Render element into string. The XML attributes and elements are
 * processed in wire order by chasing wo pointers. This is what you want for
 * validating signatures on other people's XML documents. */

/* Called by: */
char* zx_ENC_WO_cdm_REGION(struct zx_ctx* c, struct zx_cdm_REGION_s* x, char* p )
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
  ZX_OUT_MEM(p, "REGION", sizeof("REGION")-1);
  qq = p;

  /* *** sort the namespaces */
  if (c->inc_ns)
    zx_add_inc_ns(c, &pop_seen);
  if (x->group)
    zx_add_xmlns_if_not_seen(c, x->group->g.ns, &pop_seen);
  zx_add_xmlns_if_not_seen(c, x->gg.g.ns, &pop_seen);

  p = zx_enc_seen(p, pop_seen); 
  p = zx_attr_wo_enc(p, x->group, "group=\"", sizeof("group=\"")-1);

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
  ENC_LEN_DEBUG(x, "cdm:REGION", p-enc_base);
  return p;
}

/* FUNC(zx_EASY_ENC_SO_cdm_REGION) */

/* Called by: */
struct zx_str* zx_EASY_ENC_SO_cdm_REGION(struct zx_ctx* c, struct zx_cdm_REGION_s* x )
{
  int len;
  char* buf;
  c->ns_tab = ZX_ALLOC(c, sizeof(zx_ns_tab));
  memcpy(c->ns_tab, zx_ns_tab, sizeof(zx_ns_tab));
  len = zx_LEN_SO_cdm_REGION(c, x );
  buf = ZX_ALLOC(c, len+1);
  return zx_easy_enc_common(c, zx_ENC_SO_cdm_REGION(c, x, buf ), buf, len);
}

/* FUNC(zx_EASY_ENC_WO_cdm_REGION) */

/* Called by: */
struct zx_str* zx_EASY_ENC_WO_cdm_REGION(struct zx_ctx* c, struct zx_cdm_REGION_s* x )
{
  int len;
  char* buf;
  c->ns_tab = ZX_ALLOC(c, sizeof(zx_ns_tab));
  memcpy(c->ns_tab, zx_ns_tab, sizeof(zx_ns_tab));
  len = zx_LEN_WO_cdm_REGION(c, x );
  buf = ZX_ALLOC(c, len+1);
  return zx_easy_enc_common(c, zx_ENC_WO_cdm_REGION(c, x, buf ), buf, len);
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

#define EL_NAME   cdm_REV
#define EL_STRUCT zx_cdm_REV_s
#define EL_NS     cdm
#define EL_TAG    REV

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

/* FUNC(zx_LEN_SO_cdm_REV) */

/* Compute length of an element (and its subelements). The XML attributes
 * and elements are processed in schema order. */

/* Called by: */
int zx_LEN_SO_cdm_REV(struct zx_ctx* c, struct zx_cdm_REV_s* x )
{
  struct zx_ns_s* pop_seen = 0;
  struct zx_elem_s* se MAYBE_UNUSED;
#if 1 /* NORMALMODE */
  /* *** in simple_elem case should output ns prefix from ns node. */
  int len = sizeof("<cdm:REV")-1 + 1 + sizeof("</cdm:REV>")-1;
  if (c->inc_ns_len)
    len += zx_len_inc_ns(c, &pop_seen);
  if (x->ACC || x->ACCTime || x->id || x->modificationTime || x->modifier)
    len += zx_len_xmlns_if_not_seen(c, zx_ns_tab+zx_xmlns_ix_cb, &pop_seen);
  len += zx_len_xmlns_if_not_seen(c, zx_ns_tab+zx_xmlns_ix_cdm, &pop_seen);

  len += zx_attr_so_len(x->ACC, sizeof("cb:ACC")-1);
  len += zx_attr_so_len(x->ACCTime, sizeof("cb:ACCTime")-1);
  len += zx_attr_so_len(x->id, sizeof("cb:id")-1);
  len += zx_attr_so_len(x->modificationTime, sizeof("cb:modificationTime")-1);
  len += zx_attr_so_len(x->modifier, sizeof("cb:modifier")-1);

#else
  /* root node has no begin tag */
  int len = 0;
#endif
  


  len += zx_len_so_common(c, &x->gg);
  zx_pop_seen(pop_seen);
  ENC_LEN_DEBUG(x, "cdm:REV", len);
  return len;
}

/* FUNC(zx_LEN_WO_cdm_REV) */

/* Compute length of an element (and its subelements). The XML attributes
 * and elements are processed in wire order and no assumptions
 * are made about namespace prefixes. */

/* Called by: */
int zx_LEN_WO_cdm_REV(struct zx_ctx* c, struct zx_cdm_REV_s* x )
{
  struct zx_ns_s* pop_seen = 0;
  struct zx_elem_s* se MAYBE_UNUSED;
#if 1 /* NORMALMODE */
  int len = 1 + sizeof("REV")-1 + 1 + 2 + sizeof("REV")-1 + 1;
  
  if (x->gg.g.ns && x->gg.g.ns->prefix_len)
    len += (x->gg.g.ns->prefix_len + 1) * 2;
  if (c->inc_ns_len)
    len += zx_len_inc_ns(c, &pop_seen);
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
  len += zx_len_xmlns_if_not_seen(c, x->gg.g.ns, &pop_seen);

  len += zx_attr_wo_len(x->ACC, sizeof("ACC")-1);
  len += zx_attr_wo_len(x->ACCTime, sizeof("ACCTime")-1);
  len += zx_attr_wo_len(x->id, sizeof("id")-1);
  len += zx_attr_wo_len(x->modificationTime, sizeof("modificationTime")-1);
  len += zx_attr_wo_len(x->modifier, sizeof("modifier")-1);

#else
  /* root node has no begin tag */
  int len = 0;
#endif
  


  len += zx_len_wo_common(c, &x->gg); 
  zx_pop_seen(pop_seen);
  ENC_LEN_DEBUG(x, "cdm:REV", len);
  return len;
}

/* FUNC(zx_ENC_SO_cdm_REV) */

/* Render element into string. The XML attributes and elements are
 * processed in schema order. This is what you generally want for
 * rendering new data structure to a string. The wo pointers are not used. */

/* Called by: */
char* zx_ENC_SO_cdm_REV(struct zx_ctx* c, struct zx_cdm_REV_s* x, char* p )
{
  struct zx_elem_s* se MAYBE_UNUSED;
  struct zx_ns_s* pop_seen = 0;
  ENC_LEN_DEBUG_BASE;
#if 1 /* NORMALMODE */
  /* *** in simple_elem case should output ns prefix from ns node. */
  ZX_OUT_TAG(p, "<cdm:REV");
  if (c->inc_ns)
    p = zx_enc_inc_ns(c, p, &pop_seen);
  if (x->ACC || x->ACCTime || x->id || x->modificationTime || x->modifier)
    p = zx_enc_xmlns_if_not_seen(c, p, zx_ns_tab+zx_xmlns_ix_cb, &pop_seen);
  p = zx_enc_xmlns_if_not_seen(c, p, zx_ns_tab+zx_xmlns_ix_cdm, &pop_seen);

  p = zx_attr_so_enc(p, x->ACC, " cb:ACC=\"", sizeof(" cb:ACC=\"")-1);
  p = zx_attr_so_enc(p, x->ACCTime, " cb:ACCTime=\"", sizeof(" cb:ACCTime=\"")-1);
  p = zx_attr_so_enc(p, x->id, " cb:id=\"", sizeof(" cb:id=\"")-1);
  p = zx_attr_so_enc(p, x->modificationTime, " cb:modificationTime=\"", sizeof(" cb:modificationTime=\"")-1);
  p = zx_attr_so_enc(p, x->modifier, " cb:modifier=\"", sizeof(" cb:modifier=\"")-1);

  p = zx_enc_unknown_attrs(p, x->gg.any_attr);
#else
  /* root node has no begin tag */
#endif
  

  p = zx_enc_so_unknown_elems_and_content(c, p, &x->gg);
  
#if 1 /* NORMALMODE */
  ZX_OUT_CLOSE_TAG(p, "</cdm:REV>");
  zx_pop_seen(pop_seen);
#else
  /* root node has no end tag either */
#endif
  ENC_LEN_DEBUG(x, "cdm:REV", p-enc_base);
  return p;
}

/* FUNC(zx_ENC_WO_cdm_REV) */

/* Render element into string. The XML attributes and elements are
 * processed in wire order by chasing wo pointers. This is what you want for
 * validating signatures on other people's XML documents. */

/* Called by: */
char* zx_ENC_WO_cdm_REV(struct zx_ctx* c, struct zx_cdm_REV_s* x, char* p )
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
  ZX_OUT_MEM(p, "REV", sizeof("REV")-1);
  qq = p;

  /* *** sort the namespaces */
  if (c->inc_ns)
    zx_add_inc_ns(c, &pop_seen);
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
  zx_add_xmlns_if_not_seen(c, x->gg.g.ns, &pop_seen);

  p = zx_enc_seen(p, pop_seen); 
  p = zx_attr_wo_enc(p, x->ACC, "ACC=\"", sizeof("ACC=\"")-1);
  p = zx_attr_wo_enc(p, x->ACCTime, "ACCTime=\"", sizeof("ACCTime=\"")-1);
  p = zx_attr_wo_enc(p, x->id, "id=\"", sizeof("id=\"")-1);
  p = zx_attr_wo_enc(p, x->modificationTime, "modificationTime=\"", sizeof("modificationTime=\"")-1);
  p = zx_attr_wo_enc(p, x->modifier, "modifier=\"", sizeof("modifier=\"")-1);

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
  ENC_LEN_DEBUG(x, "cdm:REV", p-enc_base);
  return p;
}

/* FUNC(zx_EASY_ENC_SO_cdm_REV) */

/* Called by: */
struct zx_str* zx_EASY_ENC_SO_cdm_REV(struct zx_ctx* c, struct zx_cdm_REV_s* x )
{
  int len;
  char* buf;
  c->ns_tab = ZX_ALLOC(c, sizeof(zx_ns_tab));
  memcpy(c->ns_tab, zx_ns_tab, sizeof(zx_ns_tab));
  len = zx_LEN_SO_cdm_REV(c, x );
  buf = ZX_ALLOC(c, len+1);
  return zx_easy_enc_common(c, zx_ENC_SO_cdm_REV(c, x, buf ), buf, len);
}

/* FUNC(zx_EASY_ENC_WO_cdm_REV) */

/* Called by: */
struct zx_str* zx_EASY_ENC_WO_cdm_REV(struct zx_ctx* c, struct zx_cdm_REV_s* x )
{
  int len;
  char* buf;
  c->ns_tab = ZX_ALLOC(c, sizeof(zx_ns_tab));
  memcpy(c->ns_tab, zx_ns_tab, sizeof(zx_ns_tab));
  len = zx_LEN_WO_cdm_REV(c, x );
  buf = ZX_ALLOC(c, len+1);
  return zx_easy_enc_common(c, zx_ENC_WO_cdm_REV(c, x, buf ), buf, len);
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

#define EL_NAME   cdm_ROLE
#define EL_STRUCT zx_cdm_ROLE_s
#define EL_NS     cdm
#define EL_TAG    ROLE

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

/* FUNC(zx_LEN_SO_cdm_ROLE) */

/* Compute length of an element (and its subelements). The XML attributes
 * and elements are processed in schema order. */

/* Called by: */
int zx_LEN_SO_cdm_ROLE(struct zx_ctx* c, struct zx_cdm_ROLE_s* x )
{
  struct zx_ns_s* pop_seen = 0;
  struct zx_elem_s* se MAYBE_UNUSED;
#if 1 /* NORMALMODE */
  /* *** in simple_elem case should output ns prefix from ns node. */
  int len = sizeof("<cdm:ROLE")-1 + 1 + sizeof("</cdm:ROLE>")-1;
  if (c->inc_ns_len)
    len += zx_len_inc_ns(c, &pop_seen);
  if (x->group)
    len += zx_len_xmlns_if_not_seen(c, zx_ns_tab+zx_xmlns_ix_cb, &pop_seen);
  len += zx_len_xmlns_if_not_seen(c, zx_ns_tab+zx_xmlns_ix_cdm, &pop_seen);

  len += zx_attr_so_len(x->group, sizeof("cb:group")-1);

#else
  /* root node has no begin tag */
  int len = 0;
#endif
  


  len += zx_len_so_common(c, &x->gg);
  zx_pop_seen(pop_seen);
  ENC_LEN_DEBUG(x, "cdm:ROLE", len);
  return len;
}

/* FUNC(zx_LEN_WO_cdm_ROLE) */

/* Compute length of an element (and its subelements). The XML attributes
 * and elements are processed in wire order and no assumptions
 * are made about namespace prefixes. */

/* Called by: */
int zx_LEN_WO_cdm_ROLE(struct zx_ctx* c, struct zx_cdm_ROLE_s* x )
{
  struct zx_ns_s* pop_seen = 0;
  struct zx_elem_s* se MAYBE_UNUSED;
#if 1 /* NORMALMODE */
  int len = 1 + sizeof("ROLE")-1 + 1 + 2 + sizeof("ROLE")-1 + 1;
  
  if (x->gg.g.ns && x->gg.g.ns->prefix_len)
    len += (x->gg.g.ns->prefix_len + 1) * 2;
  if (c->inc_ns_len)
    len += zx_len_inc_ns(c, &pop_seen);
  if (x->group)
    len += zx_len_xmlns_if_not_seen(c, x->group->g.ns, &pop_seen);
  len += zx_len_xmlns_if_not_seen(c, x->gg.g.ns, &pop_seen);

  len += zx_attr_wo_len(x->group, sizeof("group")-1);

#else
  /* root node has no begin tag */
  int len = 0;
#endif
  


  len += zx_len_wo_common(c, &x->gg); 
  zx_pop_seen(pop_seen);
  ENC_LEN_DEBUG(x, "cdm:ROLE", len);
  return len;
}

/* FUNC(zx_ENC_SO_cdm_ROLE) */

/* Render element into string. The XML attributes and elements are
 * processed in schema order. This is what you generally want for
 * rendering new data structure to a string. The wo pointers are not used. */

/* Called by: */
char* zx_ENC_SO_cdm_ROLE(struct zx_ctx* c, struct zx_cdm_ROLE_s* x, char* p )
{
  struct zx_elem_s* se MAYBE_UNUSED;
  struct zx_ns_s* pop_seen = 0;
  ENC_LEN_DEBUG_BASE;
#if 1 /* NORMALMODE */
  /* *** in simple_elem case should output ns prefix from ns node. */
  ZX_OUT_TAG(p, "<cdm:ROLE");
  if (c->inc_ns)
    p = zx_enc_inc_ns(c, p, &pop_seen);
  if (x->group)
    p = zx_enc_xmlns_if_not_seen(c, p, zx_ns_tab+zx_xmlns_ix_cb, &pop_seen);
  p = zx_enc_xmlns_if_not_seen(c, p, zx_ns_tab+zx_xmlns_ix_cdm, &pop_seen);

  p = zx_attr_so_enc(p, x->group, " cb:group=\"", sizeof(" cb:group=\"")-1);

  p = zx_enc_unknown_attrs(p, x->gg.any_attr);
#else
  /* root node has no begin tag */
#endif
  

  p = zx_enc_so_unknown_elems_and_content(c, p, &x->gg);
  
#if 1 /* NORMALMODE */
  ZX_OUT_CLOSE_TAG(p, "</cdm:ROLE>");
  zx_pop_seen(pop_seen);
#else
  /* root node has no end tag either */
#endif
  ENC_LEN_DEBUG(x, "cdm:ROLE", p-enc_base);
  return p;
}

/* FUNC(zx_ENC_WO_cdm_ROLE) */

/* Render element into string. The XML attributes and elements are
 * processed in wire order by chasing wo pointers. This is what you want for
 * validating signatures on other people's XML documents. */

/* Called by: */
char* zx_ENC_WO_cdm_ROLE(struct zx_ctx* c, struct zx_cdm_ROLE_s* x, char* p )
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
  ZX_OUT_MEM(p, "ROLE", sizeof("ROLE")-1);
  qq = p;

  /* *** sort the namespaces */
  if (c->inc_ns)
    zx_add_inc_ns(c, &pop_seen);
  if (x->group)
    zx_add_xmlns_if_not_seen(c, x->group->g.ns, &pop_seen);
  zx_add_xmlns_if_not_seen(c, x->gg.g.ns, &pop_seen);

  p = zx_enc_seen(p, pop_seen); 
  p = zx_attr_wo_enc(p, x->group, "group=\"", sizeof("group=\"")-1);

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
  ENC_LEN_DEBUG(x, "cdm:ROLE", p-enc_base);
  return p;
}

/* FUNC(zx_EASY_ENC_SO_cdm_ROLE) */

/* Called by: */
struct zx_str* zx_EASY_ENC_SO_cdm_ROLE(struct zx_ctx* c, struct zx_cdm_ROLE_s* x )
{
  int len;
  char* buf;
  c->ns_tab = ZX_ALLOC(c, sizeof(zx_ns_tab));
  memcpy(c->ns_tab, zx_ns_tab, sizeof(zx_ns_tab));
  len = zx_LEN_SO_cdm_ROLE(c, x );
  buf = ZX_ALLOC(c, len+1);
  return zx_easy_enc_common(c, zx_ENC_SO_cdm_ROLE(c, x, buf ), buf, len);
}

/* FUNC(zx_EASY_ENC_WO_cdm_ROLE) */

/* Called by: */
struct zx_str* zx_EASY_ENC_WO_cdm_ROLE(struct zx_ctx* c, struct zx_cdm_ROLE_s* x )
{
  int len;
  char* buf;
  c->ns_tab = ZX_ALLOC(c, sizeof(zx_ns_tab));
  memcpy(c->ns_tab, zx_ns_tab, sizeof(zx_ns_tab));
  len = zx_LEN_WO_cdm_ROLE(c, x );
  buf = ZX_ALLOC(c, len+1);
  return zx_easy_enc_common(c, zx_ENC_WO_cdm_ROLE(c, x, buf ), buf, len);
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

#define EL_NAME   cdm_SORT_STRING
#define EL_STRUCT zx_cdm_SORT_STRING_s
#define EL_NS     cdm
#define EL_TAG    SORT_STRING

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

/* FUNC(zx_LEN_SO_cdm_SORT_STRING) */

/* Compute length of an element (and its subelements). The XML attributes
 * and elements are processed in schema order. */

/* Called by: */
int zx_LEN_SO_cdm_SORT_STRING(struct zx_ctx* c, struct zx_cdm_SORT_STRING_s* x )
{
  struct zx_ns_s* pop_seen = 0;
  struct zx_elem_s* se MAYBE_UNUSED;
#if 1 /* NORMALMODE */
  /* *** in simple_elem case should output ns prefix from ns node. */
  int len = sizeof("<cdm:SORT_STRING")-1 + 1 + sizeof("</cdm:SORT_STRING>")-1;
  if (c->inc_ns_len)
    len += zx_len_inc_ns(c, &pop_seen);
  if (x->group)
    len += zx_len_xmlns_if_not_seen(c, zx_ns_tab+zx_xmlns_ix_cb, &pop_seen);
  len += zx_len_xmlns_if_not_seen(c, zx_ns_tab+zx_xmlns_ix_cdm, &pop_seen);

  len += zx_attr_so_len(x->group, sizeof("cb:group")-1);

#else
  /* root node has no begin tag */
  int len = 0;
#endif
  


  len += zx_len_so_common(c, &x->gg);
  zx_pop_seen(pop_seen);
  ENC_LEN_DEBUG(x, "cdm:SORT_STRING", len);
  return len;
}

/* FUNC(zx_LEN_WO_cdm_SORT_STRING) */

/* Compute length of an element (and its subelements). The XML attributes
 * and elements are processed in wire order and no assumptions
 * are made about namespace prefixes. */

/* Called by: */
int zx_LEN_WO_cdm_SORT_STRING(struct zx_ctx* c, struct zx_cdm_SORT_STRING_s* x )
{
  struct zx_ns_s* pop_seen = 0;
  struct zx_elem_s* se MAYBE_UNUSED;
#if 1 /* NORMALMODE */
  int len = 1 + sizeof("SORT_STRING")-1 + 1 + 2 + sizeof("SORT_STRING")-1 + 1;
  
  if (x->gg.g.ns && x->gg.g.ns->prefix_len)
    len += (x->gg.g.ns->prefix_len + 1) * 2;
  if (c->inc_ns_len)
    len += zx_len_inc_ns(c, &pop_seen);
  if (x->group)
    len += zx_len_xmlns_if_not_seen(c, x->group->g.ns, &pop_seen);
  len += zx_len_xmlns_if_not_seen(c, x->gg.g.ns, &pop_seen);

  len += zx_attr_wo_len(x->group, sizeof("group")-1);

#else
  /* root node has no begin tag */
  int len = 0;
#endif
  


  len += zx_len_wo_common(c, &x->gg); 
  zx_pop_seen(pop_seen);
  ENC_LEN_DEBUG(x, "cdm:SORT_STRING", len);
  return len;
}

/* FUNC(zx_ENC_SO_cdm_SORT_STRING) */

/* Render element into string. The XML attributes and elements are
 * processed in schema order. This is what you generally want for
 * rendering new data structure to a string. The wo pointers are not used. */

/* Called by: */
char* zx_ENC_SO_cdm_SORT_STRING(struct zx_ctx* c, struct zx_cdm_SORT_STRING_s* x, char* p )
{
  struct zx_elem_s* se MAYBE_UNUSED;
  struct zx_ns_s* pop_seen = 0;
  ENC_LEN_DEBUG_BASE;
#if 1 /* NORMALMODE */
  /* *** in simple_elem case should output ns prefix from ns node. */
  ZX_OUT_TAG(p, "<cdm:SORT_STRING");
  if (c->inc_ns)
    p = zx_enc_inc_ns(c, p, &pop_seen);
  if (x->group)
    p = zx_enc_xmlns_if_not_seen(c, p, zx_ns_tab+zx_xmlns_ix_cb, &pop_seen);
  p = zx_enc_xmlns_if_not_seen(c, p, zx_ns_tab+zx_xmlns_ix_cdm, &pop_seen);

  p = zx_attr_so_enc(p, x->group, " cb:group=\"", sizeof(" cb:group=\"")-1);

  p = zx_enc_unknown_attrs(p, x->gg.any_attr);
#else
  /* root node has no begin tag */
#endif
  

  p = zx_enc_so_unknown_elems_and_content(c, p, &x->gg);
  
#if 1 /* NORMALMODE */
  ZX_OUT_CLOSE_TAG(p, "</cdm:SORT_STRING>");
  zx_pop_seen(pop_seen);
#else
  /* root node has no end tag either */
#endif
  ENC_LEN_DEBUG(x, "cdm:SORT_STRING", p-enc_base);
  return p;
}

/* FUNC(zx_ENC_WO_cdm_SORT_STRING) */

/* Render element into string. The XML attributes and elements are
 * processed in wire order by chasing wo pointers. This is what you want for
 * validating signatures on other people's XML documents. */

/* Called by: */
char* zx_ENC_WO_cdm_SORT_STRING(struct zx_ctx* c, struct zx_cdm_SORT_STRING_s* x, char* p )
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
  ZX_OUT_MEM(p, "SORT_STRING", sizeof("SORT_STRING")-1);
  qq = p;

  /* *** sort the namespaces */
  if (c->inc_ns)
    zx_add_inc_ns(c, &pop_seen);
  if (x->group)
    zx_add_xmlns_if_not_seen(c, x->group->g.ns, &pop_seen);
  zx_add_xmlns_if_not_seen(c, x->gg.g.ns, &pop_seen);

  p = zx_enc_seen(p, pop_seen); 
  p = zx_attr_wo_enc(p, x->group, "group=\"", sizeof("group=\"")-1);

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
  ENC_LEN_DEBUG(x, "cdm:SORT_STRING", p-enc_base);
  return p;
}

/* FUNC(zx_EASY_ENC_SO_cdm_SORT_STRING) */

/* Called by: */
struct zx_str* zx_EASY_ENC_SO_cdm_SORT_STRING(struct zx_ctx* c, struct zx_cdm_SORT_STRING_s* x )
{
  int len;
  char* buf;
  c->ns_tab = ZX_ALLOC(c, sizeof(zx_ns_tab));
  memcpy(c->ns_tab, zx_ns_tab, sizeof(zx_ns_tab));
  len = zx_LEN_SO_cdm_SORT_STRING(c, x );
  buf = ZX_ALLOC(c, len+1);
  return zx_easy_enc_common(c, zx_ENC_SO_cdm_SORT_STRING(c, x, buf ), buf, len);
}

/* FUNC(zx_EASY_ENC_WO_cdm_SORT_STRING) */

/* Called by: */
struct zx_str* zx_EASY_ENC_WO_cdm_SORT_STRING(struct zx_ctx* c, struct zx_cdm_SORT_STRING_s* x )
{
  int len;
  char* buf;
  c->ns_tab = ZX_ALLOC(c, sizeof(zx_ns_tab));
  memcpy(c->ns_tab, zx_ns_tab, sizeof(zx_ns_tab));
  len = zx_LEN_WO_cdm_SORT_STRING(c, x );
  buf = ZX_ALLOC(c, len+1);
  return zx_easy_enc_common(c, zx_ENC_WO_cdm_SORT_STRING(c, x, buf ), buf, len);
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

#define EL_NAME   cdm_SOUND
#define EL_STRUCT zx_cdm_SOUND_s
#define EL_NS     cdm
#define EL_TAG    SOUND

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

/* FUNC(zx_LEN_SO_cdm_SOUND) */

/* Compute length of an element (and its subelements). The XML attributes
 * and elements are processed in schema order. */

/* Called by: */
int zx_LEN_SO_cdm_SOUND(struct zx_ctx* c, struct zx_cdm_SOUND_s* x )
{
  struct zx_ns_s* pop_seen = 0;
  struct zx_elem_s* se MAYBE_UNUSED;
#if 1 /* NORMALMODE */
  /* *** in simple_elem case should output ns prefix from ns node. */
  int len = sizeof("<cdm:SOUND")-1 + 1 + sizeof("</cdm:SOUND>")-1;
  if (c->inc_ns_len)
    len += zx_len_inc_ns(c, &pop_seen);
  if (x->id || x->modificationTime)
    len += zx_len_xmlns_if_not_seen(c, zx_ns_tab+zx_xmlns_ix_cb, &pop_seen);
  len += zx_len_xmlns_if_not_seen(c, zx_ns_tab+zx_xmlns_ix_cdm, &pop_seen);

  len += zx_attr_so_len(x->id, sizeof("cb:id")-1);
  len += zx_attr_so_len(x->modificationTime, sizeof("cb:modificationTime")-1);

#else
  /* root node has no begin tag */
  int len = 0;
#endif
  
  {
      struct zx_cdm_PHONETIC_s* e;
      for (e = x->PHONETIC; e; e = (struct zx_cdm_PHONETIC_s*)e->gg.g.n)
	  len += zx_LEN_SO_cdm_PHONETIC(c, e);
  }
  {
      struct zx_cdm_BINVAL_s* e;
      for (e = x->BINVAL; e; e = (struct zx_cdm_BINVAL_s*)e->gg.g.n)
	  len += zx_LEN_SO_cdm_BINVAL(c, e);
  }
  {
      struct zx_cdm_EXTVAL_s* e;
      for (e = x->EXTVAL; e; e = (struct zx_cdm_EXTVAL_s*)e->gg.g.n)
	  len += zx_LEN_SO_cdm_EXTVAL(c, e);
  }


  len += zx_len_so_common(c, &x->gg);
  zx_pop_seen(pop_seen);
  ENC_LEN_DEBUG(x, "cdm:SOUND", len);
  return len;
}

/* FUNC(zx_LEN_WO_cdm_SOUND) */

/* Compute length of an element (and its subelements). The XML attributes
 * and elements are processed in wire order and no assumptions
 * are made about namespace prefixes. */

/* Called by: */
int zx_LEN_WO_cdm_SOUND(struct zx_ctx* c, struct zx_cdm_SOUND_s* x )
{
  struct zx_ns_s* pop_seen = 0;
  struct zx_elem_s* se MAYBE_UNUSED;
#if 1 /* NORMALMODE */
  int len = 1 + sizeof("SOUND")-1 + 1 + 2 + sizeof("SOUND")-1 + 1;
  
  if (x->gg.g.ns && x->gg.g.ns->prefix_len)
    len += (x->gg.g.ns->prefix_len + 1) * 2;
  if (c->inc_ns_len)
    len += zx_len_inc_ns(c, &pop_seen);
  if (x->id)
    len += zx_len_xmlns_if_not_seen(c, x->id->g.ns, &pop_seen);
  if (x->modificationTime)
    len += zx_len_xmlns_if_not_seen(c, x->modificationTime->g.ns, &pop_seen);
  len += zx_len_xmlns_if_not_seen(c, x->gg.g.ns, &pop_seen);

  len += zx_attr_wo_len(x->id, sizeof("id")-1);
  len += zx_attr_wo_len(x->modificationTime, sizeof("modificationTime")-1);

#else
  /* root node has no begin tag */
  int len = 0;
#endif
  
  {
      struct zx_cdm_PHONETIC_s* e;
      for (e = x->PHONETIC; e; e = (struct zx_cdm_PHONETIC_s*)e->gg.g.n)
	  len += zx_LEN_WO_cdm_PHONETIC(c, e);
  }
  {
      struct zx_cdm_BINVAL_s* e;
      for (e = x->BINVAL; e; e = (struct zx_cdm_BINVAL_s*)e->gg.g.n)
	  len += zx_LEN_WO_cdm_BINVAL(c, e);
  }
  {
      struct zx_cdm_EXTVAL_s* e;
      for (e = x->EXTVAL; e; e = (struct zx_cdm_EXTVAL_s*)e->gg.g.n)
	  len += zx_LEN_WO_cdm_EXTVAL(c, e);
  }


  len += zx_len_wo_common(c, &x->gg); 
  zx_pop_seen(pop_seen);
  ENC_LEN_DEBUG(x, "cdm:SOUND", len);
  return len;
}

/* FUNC(zx_ENC_SO_cdm_SOUND) */

/* Render element into string. The XML attributes and elements are
 * processed in schema order. This is what you generally want for
 * rendering new data structure to a string. The wo pointers are not used. */

/* Called by: */
char* zx_ENC_SO_cdm_SOUND(struct zx_ctx* c, struct zx_cdm_SOUND_s* x, char* p )
{
  struct zx_elem_s* se MAYBE_UNUSED;
  struct zx_ns_s* pop_seen = 0;
  ENC_LEN_DEBUG_BASE;
#if 1 /* NORMALMODE */
  /* *** in simple_elem case should output ns prefix from ns node. */
  ZX_OUT_TAG(p, "<cdm:SOUND");
  if (c->inc_ns)
    p = zx_enc_inc_ns(c, p, &pop_seen);
  if (x->id || x->modificationTime)
    p = zx_enc_xmlns_if_not_seen(c, p, zx_ns_tab+zx_xmlns_ix_cb, &pop_seen);
  p = zx_enc_xmlns_if_not_seen(c, p, zx_ns_tab+zx_xmlns_ix_cdm, &pop_seen);

  p = zx_attr_so_enc(p, x->id, " cb:id=\"", sizeof(" cb:id=\"")-1);
  p = zx_attr_so_enc(p, x->modificationTime, " cb:modificationTime=\"", sizeof(" cb:modificationTime=\"")-1);

  p = zx_enc_unknown_attrs(p, x->gg.any_attr);
#else
  /* root node has no begin tag */
#endif
  
  {
      struct zx_cdm_PHONETIC_s* e;
      for (e = x->PHONETIC; e; e = (struct zx_cdm_PHONETIC_s*)e->gg.g.n)
	  p = zx_ENC_SO_cdm_PHONETIC(c, e, p);
  }
  {
      struct zx_cdm_BINVAL_s* e;
      for (e = x->BINVAL; e; e = (struct zx_cdm_BINVAL_s*)e->gg.g.n)
	  p = zx_ENC_SO_cdm_BINVAL(c, e, p);
  }
  {
      struct zx_cdm_EXTVAL_s* e;
      for (e = x->EXTVAL; e; e = (struct zx_cdm_EXTVAL_s*)e->gg.g.n)
	  p = zx_ENC_SO_cdm_EXTVAL(c, e, p);
  }

  p = zx_enc_so_unknown_elems_and_content(c, p, &x->gg);
  
#if 1 /* NORMALMODE */
  ZX_OUT_CLOSE_TAG(p, "</cdm:SOUND>");
  zx_pop_seen(pop_seen);
#else
  /* root node has no end tag either */
#endif
  ENC_LEN_DEBUG(x, "cdm:SOUND", p-enc_base);
  return p;
}

/* FUNC(zx_ENC_WO_cdm_SOUND) */

/* Render element into string. The XML attributes and elements are
 * processed in wire order by chasing wo pointers. This is what you want for
 * validating signatures on other people's XML documents. */

/* Called by: */
char* zx_ENC_WO_cdm_SOUND(struct zx_ctx* c, struct zx_cdm_SOUND_s* x, char* p )
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
  ZX_OUT_MEM(p, "SOUND", sizeof("SOUND")-1);
  qq = p;

  /* *** sort the namespaces */
  if (c->inc_ns)
    zx_add_inc_ns(c, &pop_seen);
  if (x->id)
    zx_add_xmlns_if_not_seen(c, x->id->g.ns, &pop_seen);
  if (x->modificationTime)
    zx_add_xmlns_if_not_seen(c, x->modificationTime->g.ns, &pop_seen);
  zx_add_xmlns_if_not_seen(c, x->gg.g.ns, &pop_seen);

  p = zx_enc_seen(p, pop_seen); 
  p = zx_attr_wo_enc(p, x->id, "id=\"", sizeof("id=\"")-1);
  p = zx_attr_wo_enc(p, x->modificationTime, "modificationTime=\"", sizeof("modificationTime=\"")-1);

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
  ENC_LEN_DEBUG(x, "cdm:SOUND", p-enc_base);
  return p;
}

/* FUNC(zx_EASY_ENC_SO_cdm_SOUND) */

/* Called by: */
struct zx_str* zx_EASY_ENC_SO_cdm_SOUND(struct zx_ctx* c, struct zx_cdm_SOUND_s* x )
{
  int len;
  char* buf;
  c->ns_tab = ZX_ALLOC(c, sizeof(zx_ns_tab));
  memcpy(c->ns_tab, zx_ns_tab, sizeof(zx_ns_tab));
  len = zx_LEN_SO_cdm_SOUND(c, x );
  buf = ZX_ALLOC(c, len+1);
  return zx_easy_enc_common(c, zx_ENC_SO_cdm_SOUND(c, x, buf ), buf, len);
}

/* FUNC(zx_EASY_ENC_WO_cdm_SOUND) */

/* Called by: */
struct zx_str* zx_EASY_ENC_WO_cdm_SOUND(struct zx_ctx* c, struct zx_cdm_SOUND_s* x )
{
  int len;
  char* buf;
  c->ns_tab = ZX_ALLOC(c, sizeof(zx_ns_tab));
  memcpy(c->ns_tab, zx_ns_tab, sizeof(zx_ns_tab));
  len = zx_LEN_WO_cdm_SOUND(c, x );
  buf = ZX_ALLOC(c, len+1);
  return zx_easy_enc_common(c, zx_ENC_WO_cdm_SOUND(c, x, buf ), buf, len);
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

#define EL_NAME   cdm_STREET
#define EL_STRUCT zx_cdm_STREET_s
#define EL_NS     cdm
#define EL_TAG    STREET

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

/* FUNC(zx_LEN_SO_cdm_STREET) */

/* Compute length of an element (and its subelements). The XML attributes
 * and elements are processed in schema order. */

/* Called by: */
int zx_LEN_SO_cdm_STREET(struct zx_ctx* c, struct zx_cdm_STREET_s* x )
{
  struct zx_ns_s* pop_seen = 0;
  struct zx_elem_s* se MAYBE_UNUSED;
#if 1 /* NORMALMODE */
  /* *** in simple_elem case should output ns prefix from ns node. */
  int len = sizeof("<cdm:STREET")-1 + 1 + sizeof("</cdm:STREET>")-1;
  if (c->inc_ns_len)
    len += zx_len_inc_ns(c, &pop_seen);
  if (x->group)
    len += zx_len_xmlns_if_not_seen(c, zx_ns_tab+zx_xmlns_ix_cb, &pop_seen);
  len += zx_len_xmlns_if_not_seen(c, zx_ns_tab+zx_xmlns_ix_cdm, &pop_seen);

  len += zx_attr_so_len(x->group, sizeof("cb:group")-1);

#else
  /* root node has no begin tag */
  int len = 0;
#endif
  


  len += zx_len_so_common(c, &x->gg);
  zx_pop_seen(pop_seen);
  ENC_LEN_DEBUG(x, "cdm:STREET", len);
  return len;
}

/* FUNC(zx_LEN_WO_cdm_STREET) */

/* Compute length of an element (and its subelements). The XML attributes
 * and elements are processed in wire order and no assumptions
 * are made about namespace prefixes. */

/* Called by: */
int zx_LEN_WO_cdm_STREET(struct zx_ctx* c, struct zx_cdm_STREET_s* x )
{
  struct zx_ns_s* pop_seen = 0;
  struct zx_elem_s* se MAYBE_UNUSED;
#if 1 /* NORMALMODE */
  int len = 1 + sizeof("STREET")-1 + 1 + 2 + sizeof("STREET")-1 + 1;
  
  if (x->gg.g.ns && x->gg.g.ns->prefix_len)
    len += (x->gg.g.ns->prefix_len + 1) * 2;
  if (c->inc_ns_len)
    len += zx_len_inc_ns(c, &pop_seen);
  if (x->group)
    len += zx_len_xmlns_if_not_seen(c, x->group->g.ns, &pop_seen);
  len += zx_len_xmlns_if_not_seen(c, x->gg.g.ns, &pop_seen);

  len += zx_attr_wo_len(x->group, sizeof("group")-1);

#else
  /* root node has no begin tag */
  int len = 0;
#endif
  


  len += zx_len_wo_common(c, &x->gg); 
  zx_pop_seen(pop_seen);
  ENC_LEN_DEBUG(x, "cdm:STREET", len);
  return len;
}

/* FUNC(zx_ENC_SO_cdm_STREET) */

/* Render element into string. The XML attributes and elements are
 * processed in schema order. This is what you generally want for
 * rendering new data structure to a string. The wo pointers are not used. */

/* Called by: */
char* zx_ENC_SO_cdm_STREET(struct zx_ctx* c, struct zx_cdm_STREET_s* x, char* p )
{
  struct zx_elem_s* se MAYBE_UNUSED;
  struct zx_ns_s* pop_seen = 0;
  ENC_LEN_DEBUG_BASE;
#if 1 /* NORMALMODE */
  /* *** in simple_elem case should output ns prefix from ns node. */
  ZX_OUT_TAG(p, "<cdm:STREET");
  if (c->inc_ns)
    p = zx_enc_inc_ns(c, p, &pop_seen);
  if (x->group)
    p = zx_enc_xmlns_if_not_seen(c, p, zx_ns_tab+zx_xmlns_ix_cb, &pop_seen);
  p = zx_enc_xmlns_if_not_seen(c, p, zx_ns_tab+zx_xmlns_ix_cdm, &pop_seen);

  p = zx_attr_so_enc(p, x->group, " cb:group=\"", sizeof(" cb:group=\"")-1);

  p = zx_enc_unknown_attrs(p, x->gg.any_attr);
#else
  /* root node has no begin tag */
#endif
  

  p = zx_enc_so_unknown_elems_and_content(c, p, &x->gg);
  
#if 1 /* NORMALMODE */
  ZX_OUT_CLOSE_TAG(p, "</cdm:STREET>");
  zx_pop_seen(pop_seen);
#else
  /* root node has no end tag either */
#endif
  ENC_LEN_DEBUG(x, "cdm:STREET", p-enc_base);
  return p;
}

/* FUNC(zx_ENC_WO_cdm_STREET) */

/* Render element into string. The XML attributes and elements are
 * processed in wire order by chasing wo pointers. This is what you want for
 * validating signatures on other people's XML documents. */

/* Called by: */
char* zx_ENC_WO_cdm_STREET(struct zx_ctx* c, struct zx_cdm_STREET_s* x, char* p )
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
  ZX_OUT_MEM(p, "STREET", sizeof("STREET")-1);
  qq = p;

  /* *** sort the namespaces */
  if (c->inc_ns)
    zx_add_inc_ns(c, &pop_seen);
  if (x->group)
    zx_add_xmlns_if_not_seen(c, x->group->g.ns, &pop_seen);
  zx_add_xmlns_if_not_seen(c, x->gg.g.ns, &pop_seen);

  p = zx_enc_seen(p, pop_seen); 
  p = zx_attr_wo_enc(p, x->group, "group=\"", sizeof("group=\"")-1);

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
  ENC_LEN_DEBUG(x, "cdm:STREET", p-enc_base);
  return p;
}

/* FUNC(zx_EASY_ENC_SO_cdm_STREET) */

/* Called by: */
struct zx_str* zx_EASY_ENC_SO_cdm_STREET(struct zx_ctx* c, struct zx_cdm_STREET_s* x )
{
  int len;
  char* buf;
  c->ns_tab = ZX_ALLOC(c, sizeof(zx_ns_tab));
  memcpy(c->ns_tab, zx_ns_tab, sizeof(zx_ns_tab));
  len = zx_LEN_SO_cdm_STREET(c, x );
  buf = ZX_ALLOC(c, len+1);
  return zx_easy_enc_common(c, zx_ENC_SO_cdm_STREET(c, x, buf ), buf, len);
}

/* FUNC(zx_EASY_ENC_WO_cdm_STREET) */

/* Called by: */
struct zx_str* zx_EASY_ENC_WO_cdm_STREET(struct zx_ctx* c, struct zx_cdm_STREET_s* x )
{
  int len;
  char* buf;
  c->ns_tab = ZX_ALLOC(c, sizeof(zx_ns_tab));
  memcpy(c->ns_tab, zx_ns_tab, sizeof(zx_ns_tab));
  len = zx_LEN_WO_cdm_STREET(c, x );
  buf = ZX_ALLOC(c, len+1);
  return zx_easy_enc_common(c, zx_ENC_WO_cdm_STREET(c, x, buf ), buf, len);
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

#define EL_NAME   cdm_SUFFIX
#define EL_STRUCT zx_cdm_SUFFIX_s
#define EL_NS     cdm
#define EL_TAG    SUFFIX

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

/* FUNC(zx_LEN_SO_cdm_SUFFIX) */

/* Compute length of an element (and its subelements). The XML attributes
 * and elements are processed in schema order. */

/* Called by: */
int zx_LEN_SO_cdm_SUFFIX(struct zx_ctx* c, struct zx_cdm_SUFFIX_s* x )
{
  struct zx_ns_s* pop_seen = 0;
  struct zx_elem_s* se MAYBE_UNUSED;
#if 1 /* NORMALMODE */
  /* *** in simple_elem case should output ns prefix from ns node. */
  int len = sizeof("<cdm:SUFFIX")-1 + 1 + sizeof("</cdm:SUFFIX>")-1;
  if (c->inc_ns_len)
    len += zx_len_inc_ns(c, &pop_seen);
  if (x->group)
    len += zx_len_xmlns_if_not_seen(c, zx_ns_tab+zx_xmlns_ix_cb, &pop_seen);
  len += zx_len_xmlns_if_not_seen(c, zx_ns_tab+zx_xmlns_ix_cdm, &pop_seen);

  len += zx_attr_so_len(x->group, sizeof("cb:group")-1);

#else
  /* root node has no begin tag */
  int len = 0;
#endif
  


  len += zx_len_so_common(c, &x->gg);
  zx_pop_seen(pop_seen);
  ENC_LEN_DEBUG(x, "cdm:SUFFIX", len);
  return len;
}

/* FUNC(zx_LEN_WO_cdm_SUFFIX) */

/* Compute length of an element (and its subelements). The XML attributes
 * and elements are processed in wire order and no assumptions
 * are made about namespace prefixes. */

/* Called by: */
int zx_LEN_WO_cdm_SUFFIX(struct zx_ctx* c, struct zx_cdm_SUFFIX_s* x )
{
  struct zx_ns_s* pop_seen = 0;
  struct zx_elem_s* se MAYBE_UNUSED;
#if 1 /* NORMALMODE */
  int len = 1 + sizeof("SUFFIX")-1 + 1 + 2 + sizeof("SUFFIX")-1 + 1;
  
  if (x->gg.g.ns && x->gg.g.ns->prefix_len)
    len += (x->gg.g.ns->prefix_len + 1) * 2;
  if (c->inc_ns_len)
    len += zx_len_inc_ns(c, &pop_seen);
  if (x->group)
    len += zx_len_xmlns_if_not_seen(c, x->group->g.ns, &pop_seen);
  len += zx_len_xmlns_if_not_seen(c, x->gg.g.ns, &pop_seen);

  len += zx_attr_wo_len(x->group, sizeof("group")-1);

#else
  /* root node has no begin tag */
  int len = 0;
#endif
  


  len += zx_len_wo_common(c, &x->gg); 
  zx_pop_seen(pop_seen);
  ENC_LEN_DEBUG(x, "cdm:SUFFIX", len);
  return len;
}

/* FUNC(zx_ENC_SO_cdm_SUFFIX) */

/* Render element into string. The XML attributes and elements are
 * processed in schema order. This is what you generally want for
 * rendering new data structure to a string. The wo pointers are not used. */

/* Called by: */
char* zx_ENC_SO_cdm_SUFFIX(struct zx_ctx* c, struct zx_cdm_SUFFIX_s* x, char* p )
{
  struct zx_elem_s* se MAYBE_UNUSED;
  struct zx_ns_s* pop_seen = 0;
  ENC_LEN_DEBUG_BASE;
#if 1 /* NORMALMODE */
  /* *** in simple_elem case should output ns prefix from ns node. */
  ZX_OUT_TAG(p, "<cdm:SUFFIX");
  if (c->inc_ns)
    p = zx_enc_inc_ns(c, p, &pop_seen);
  if (x->group)
    p = zx_enc_xmlns_if_not_seen(c, p, zx_ns_tab+zx_xmlns_ix_cb, &pop_seen);
  p = zx_enc_xmlns_if_not_seen(c, p, zx_ns_tab+zx_xmlns_ix_cdm, &pop_seen);

  p = zx_attr_so_enc(p, x->group, " cb:group=\"", sizeof(" cb:group=\"")-1);

  p = zx_enc_unknown_attrs(p, x->gg.any_attr);
#else
  /* root node has no begin tag */
#endif
  

  p = zx_enc_so_unknown_elems_and_content(c, p, &x->gg);
  
#if 1 /* NORMALMODE */
  ZX_OUT_CLOSE_TAG(p, "</cdm:SUFFIX>");
  zx_pop_seen(pop_seen);
#else
  /* root node has no end tag either */
#endif
  ENC_LEN_DEBUG(x, "cdm:SUFFIX", p-enc_base);
  return p;
}

/* FUNC(zx_ENC_WO_cdm_SUFFIX) */

/* Render element into string. The XML attributes and elements are
 * processed in wire order by chasing wo pointers. This is what you want for
 * validating signatures on other people's XML documents. */

/* Called by: */
char* zx_ENC_WO_cdm_SUFFIX(struct zx_ctx* c, struct zx_cdm_SUFFIX_s* x, char* p )
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
  ZX_OUT_MEM(p, "SUFFIX", sizeof("SUFFIX")-1);
  qq = p;

  /* *** sort the namespaces */
  if (c->inc_ns)
    zx_add_inc_ns(c, &pop_seen);
  if (x->group)
    zx_add_xmlns_if_not_seen(c, x->group->g.ns, &pop_seen);
  zx_add_xmlns_if_not_seen(c, x->gg.g.ns, &pop_seen);

  p = zx_enc_seen(p, pop_seen); 
  p = zx_attr_wo_enc(p, x->group, "group=\"", sizeof("group=\"")-1);

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
  ENC_LEN_DEBUG(x, "cdm:SUFFIX", p-enc_base);
  return p;
}

/* FUNC(zx_EASY_ENC_SO_cdm_SUFFIX) */

/* Called by: */
struct zx_str* zx_EASY_ENC_SO_cdm_SUFFIX(struct zx_ctx* c, struct zx_cdm_SUFFIX_s* x )
{
  int len;
  char* buf;
  c->ns_tab = ZX_ALLOC(c, sizeof(zx_ns_tab));
  memcpy(c->ns_tab, zx_ns_tab, sizeof(zx_ns_tab));
  len = zx_LEN_SO_cdm_SUFFIX(c, x );
  buf = ZX_ALLOC(c, len+1);
  return zx_easy_enc_common(c, zx_ENC_SO_cdm_SUFFIX(c, x, buf ), buf, len);
}

/* FUNC(zx_EASY_ENC_WO_cdm_SUFFIX) */

/* Called by: */
struct zx_str* zx_EASY_ENC_WO_cdm_SUFFIX(struct zx_ctx* c, struct zx_cdm_SUFFIX_s* x )
{
  int len;
  char* buf;
  c->ns_tab = ZX_ALLOC(c, sizeof(zx_ns_tab));
  memcpy(c->ns_tab, zx_ns_tab, sizeof(zx_ns_tab));
  len = zx_LEN_WO_cdm_SUFFIX(c, x );
  buf = ZX_ALLOC(c, len+1);
  return zx_easy_enc_common(c, zx_ENC_WO_cdm_SUFFIX(c, x, buf ), buf, len);
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

#define EL_NAME   cdm_TEL
#define EL_STRUCT zx_cdm_TEL_s
#define EL_NS     cdm
#define EL_TAG    TEL

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

/* FUNC(zx_LEN_SO_cdm_TEL) */

/* Compute length of an element (and its subelements). The XML attributes
 * and elements are processed in schema order. */

/* Called by: */
int zx_LEN_SO_cdm_TEL(struct zx_ctx* c, struct zx_cdm_TEL_s* x )
{
  struct zx_ns_s* pop_seen = 0;
  struct zx_elem_s* se MAYBE_UNUSED;
#if 1 /* NORMALMODE */
  /* *** in simple_elem case should output ns prefix from ns node. */
  int len = sizeof("<cdm:TEL")-1 + 1 + sizeof("</cdm:TEL>")-1;
  if (c->inc_ns_len)
    len += zx_len_inc_ns(c, &pop_seen);
  if (x->id || x->modificationTime)
    len += zx_len_xmlns_if_not_seen(c, zx_ns_tab+zx_xmlns_ix_cb, &pop_seen);
  len += zx_len_xmlns_if_not_seen(c, zx_ns_tab+zx_xmlns_ix_cdm, &pop_seen);

  len += zx_attr_so_len(x->id, sizeof("cb:id")-1);
  len += zx_attr_so_len(x->modificationTime, sizeof("cb:modificationTime")-1);

#else
  /* root node has no begin tag */
  int len = 0;
#endif
  
  for (se = x->HOME; se; se = (struct zx_elem_s*)se->g.n)
    len += zx_LEN_SO_simple_elem(c,se, sizeof("cdm:HOME")-1, zx_ns_tab+zx_xmlns_ix_cdm);
  for (se = x->WORK; se; se = (struct zx_elem_s*)se->g.n)
    len += zx_LEN_SO_simple_elem(c,se, sizeof("cdm:WORK")-1, zx_ns_tab+zx_xmlns_ix_cdm);
  for (se = x->VOICE; se; se = (struct zx_elem_s*)se->g.n)
    len += zx_LEN_SO_simple_elem(c,se, sizeof("cdm:VOICE")-1, zx_ns_tab+zx_xmlns_ix_cdm);
  for (se = x->FAX; se; se = (struct zx_elem_s*)se->g.n)
    len += zx_LEN_SO_simple_elem(c,se, sizeof("cdm:FAX")-1, zx_ns_tab+zx_xmlns_ix_cdm);
  for (se = x->PAGER; se; se = (struct zx_elem_s*)se->g.n)
    len += zx_LEN_SO_simple_elem(c,se, sizeof("cdm:PAGER")-1, zx_ns_tab+zx_xmlns_ix_cdm);
  for (se = x->MSG; se; se = (struct zx_elem_s*)se->g.n)
    len += zx_LEN_SO_simple_elem(c,se, sizeof("cdm:MSG")-1, zx_ns_tab+zx_xmlns_ix_cdm);
  for (se = x->CELL; se; se = (struct zx_elem_s*)se->g.n)
    len += zx_LEN_SO_simple_elem(c,se, sizeof("cdm:CELL")-1, zx_ns_tab+zx_xmlns_ix_cdm);
  for (se = x->VIDEO; se; se = (struct zx_elem_s*)se->g.n)
    len += zx_LEN_SO_simple_elem(c,se, sizeof("cdm:VIDEO")-1, zx_ns_tab+zx_xmlns_ix_cdm);
  for (se = x->BBS; se; se = (struct zx_elem_s*)se->g.n)
    len += zx_LEN_SO_simple_elem(c,se, sizeof("cdm:BBS")-1, zx_ns_tab+zx_xmlns_ix_cdm);
  for (se = x->MODEM; se; se = (struct zx_elem_s*)se->g.n)
    len += zx_LEN_SO_simple_elem(c,se, sizeof("cdm:MODEM")-1, zx_ns_tab+zx_xmlns_ix_cdm);
  for (se = x->ISDN; se; se = (struct zx_elem_s*)se->g.n)
    len += zx_LEN_SO_simple_elem(c,se, sizeof("cdm:ISDN")-1, zx_ns_tab+zx_xmlns_ix_cdm);
  for (se = x->PCS; se; se = (struct zx_elem_s*)se->g.n)
    len += zx_LEN_SO_simple_elem(c,se, sizeof("cdm:PCS")-1, zx_ns_tab+zx_xmlns_ix_cdm);
  for (se = x->PREF; se; se = (struct zx_elem_s*)se->g.n)
    len += zx_LEN_SO_simple_elem(c,se, sizeof("cdm:PREF")-1, zx_ns_tab+zx_xmlns_ix_cdm);
  {
      struct zx_cdm_NUMBER_s* e;
      for (e = x->NUMBER; e; e = (struct zx_cdm_NUMBER_s*)e->gg.g.n)
	  len += zx_LEN_SO_cdm_NUMBER(c, e);
  }


  len += zx_len_so_common(c, &x->gg);
  zx_pop_seen(pop_seen);
  ENC_LEN_DEBUG(x, "cdm:TEL", len);
  return len;
}

/* FUNC(zx_LEN_WO_cdm_TEL) */

/* Compute length of an element (and its subelements). The XML attributes
 * and elements are processed in wire order and no assumptions
 * are made about namespace prefixes. */

/* Called by: */
int zx_LEN_WO_cdm_TEL(struct zx_ctx* c, struct zx_cdm_TEL_s* x )
{
  struct zx_ns_s* pop_seen = 0;
  struct zx_elem_s* se MAYBE_UNUSED;
#if 1 /* NORMALMODE */
  int len = 1 + sizeof("TEL")-1 + 1 + 2 + sizeof("TEL")-1 + 1;
  
  if (x->gg.g.ns && x->gg.g.ns->prefix_len)
    len += (x->gg.g.ns->prefix_len + 1) * 2;
  if (c->inc_ns_len)
    len += zx_len_inc_ns(c, &pop_seen);
  if (x->id)
    len += zx_len_xmlns_if_not_seen(c, x->id->g.ns, &pop_seen);
  if (x->modificationTime)
    len += zx_len_xmlns_if_not_seen(c, x->modificationTime->g.ns, &pop_seen);
  len += zx_len_xmlns_if_not_seen(c, x->gg.g.ns, &pop_seen);

  len += zx_attr_wo_len(x->id, sizeof("id")-1);
  len += zx_attr_wo_len(x->modificationTime, sizeof("modificationTime")-1);

#else
  /* root node has no begin tag */
  int len = 0;
#endif
  
  for (se = x->HOME; se; se = (struct zx_elem_s*)se->g.n)
    len += zx_LEN_WO_simple_elem(c, se, sizeof("HOME")-1);
  for (se = x->WORK; se; se = (struct zx_elem_s*)se->g.n)
    len += zx_LEN_WO_simple_elem(c, se, sizeof("WORK")-1);
  for (se = x->VOICE; se; se = (struct zx_elem_s*)se->g.n)
    len += zx_LEN_WO_simple_elem(c, se, sizeof("VOICE")-1);
  for (se = x->FAX; se; se = (struct zx_elem_s*)se->g.n)
    len += zx_LEN_WO_simple_elem(c, se, sizeof("FAX")-1);
  for (se = x->PAGER; se; se = (struct zx_elem_s*)se->g.n)
    len += zx_LEN_WO_simple_elem(c, se, sizeof("PAGER")-1);
  for (se = x->MSG; se; se = (struct zx_elem_s*)se->g.n)
    len += zx_LEN_WO_simple_elem(c, se, sizeof("MSG")-1);
  for (se = x->CELL; se; se = (struct zx_elem_s*)se->g.n)
    len += zx_LEN_WO_simple_elem(c, se, sizeof("CELL")-1);
  for (se = x->VIDEO; se; se = (struct zx_elem_s*)se->g.n)
    len += zx_LEN_WO_simple_elem(c, se, sizeof("VIDEO")-1);
  for (se = x->BBS; se; se = (struct zx_elem_s*)se->g.n)
    len += zx_LEN_WO_simple_elem(c, se, sizeof("BBS")-1);
  for (se = x->MODEM; se; se = (struct zx_elem_s*)se->g.n)
    len += zx_LEN_WO_simple_elem(c, se, sizeof("MODEM")-1);
  for (se = x->ISDN; se; se = (struct zx_elem_s*)se->g.n)
    len += zx_LEN_WO_simple_elem(c, se, sizeof("ISDN")-1);
  for (se = x->PCS; se; se = (struct zx_elem_s*)se->g.n)
    len += zx_LEN_WO_simple_elem(c, se, sizeof("PCS")-1);
  for (se = x->PREF; se; se = (struct zx_elem_s*)se->g.n)
    len += zx_LEN_WO_simple_elem(c, se, sizeof("PREF")-1);
  {
      struct zx_cdm_NUMBER_s* e;
      for (e = x->NUMBER; e; e = (struct zx_cdm_NUMBER_s*)e->gg.g.n)
	  len += zx_LEN_WO_cdm_NUMBER(c, e);
  }


  len += zx_len_wo_common(c, &x->gg); 
  zx_pop_seen(pop_seen);
  ENC_LEN_DEBUG(x, "cdm:TEL", len);
  return len;
}

/* FUNC(zx_ENC_SO_cdm_TEL) */

/* Render element into string. The XML attributes and elements are
 * processed in schema order. This is what you generally want for
 * rendering new data structure to a string. The wo pointers are not used. */

/* Called by: */
char* zx_ENC_SO_cdm_TEL(struct zx_ctx* c, struct zx_cdm_TEL_s* x, char* p )
{
  struct zx_elem_s* se MAYBE_UNUSED;
  struct zx_ns_s* pop_seen = 0;
  ENC_LEN_DEBUG_BASE;
#if 1 /* NORMALMODE */
  /* *** in simple_elem case should output ns prefix from ns node. */
  ZX_OUT_TAG(p, "<cdm:TEL");
  if (c->inc_ns)
    p = zx_enc_inc_ns(c, p, &pop_seen);
  if (x->id || x->modificationTime)
    p = zx_enc_xmlns_if_not_seen(c, p, zx_ns_tab+zx_xmlns_ix_cb, &pop_seen);
  p = zx_enc_xmlns_if_not_seen(c, p, zx_ns_tab+zx_xmlns_ix_cdm, &pop_seen);

  p = zx_attr_so_enc(p, x->id, " cb:id=\"", sizeof(" cb:id=\"")-1);
  p = zx_attr_so_enc(p, x->modificationTime, " cb:modificationTime=\"", sizeof(" cb:modificationTime=\"")-1);

  p = zx_enc_unknown_attrs(p, x->gg.any_attr);
#else
  /* root node has no begin tag */
#endif
  
  for (se = x->HOME; se; se = (struct zx_elem_s*)se->g.n)
    p = zx_ENC_SO_simple_elem(c, se, p, "cdm:HOME", sizeof("cdm:HOME")-1, zx_ns_tab+zx_xmlns_ix_cdm);
  for (se = x->WORK; se; se = (struct zx_elem_s*)se->g.n)
    p = zx_ENC_SO_simple_elem(c, se, p, "cdm:WORK", sizeof("cdm:WORK")-1, zx_ns_tab+zx_xmlns_ix_cdm);
  for (se = x->VOICE; se; se = (struct zx_elem_s*)se->g.n)
    p = zx_ENC_SO_simple_elem(c, se, p, "cdm:VOICE", sizeof("cdm:VOICE")-1, zx_ns_tab+zx_xmlns_ix_cdm);
  for (se = x->FAX; se; se = (struct zx_elem_s*)se->g.n)
    p = zx_ENC_SO_simple_elem(c, se, p, "cdm:FAX", sizeof("cdm:FAX")-1, zx_ns_tab+zx_xmlns_ix_cdm);
  for (se = x->PAGER; se; se = (struct zx_elem_s*)se->g.n)
    p = zx_ENC_SO_simple_elem(c, se, p, "cdm:PAGER", sizeof("cdm:PAGER")-1, zx_ns_tab+zx_xmlns_ix_cdm);
  for (se = x->MSG; se; se = (struct zx_elem_s*)se->g.n)
    p = zx_ENC_SO_simple_elem(c, se, p, "cdm:MSG", sizeof("cdm:MSG")-1, zx_ns_tab+zx_xmlns_ix_cdm);
  for (se = x->CELL; se; se = (struct zx_elem_s*)se->g.n)
    p = zx_ENC_SO_simple_elem(c, se, p, "cdm:CELL", sizeof("cdm:CELL")-1, zx_ns_tab+zx_xmlns_ix_cdm);
  for (se = x->VIDEO; se; se = (struct zx_elem_s*)se->g.n)
    p = zx_ENC_SO_simple_elem(c, se, p, "cdm:VIDEO", sizeof("cdm:VIDEO")-1, zx_ns_tab+zx_xmlns_ix_cdm);
  for (se = x->BBS; se; se = (struct zx_elem_s*)se->g.n)
    p = zx_ENC_SO_simple_elem(c, se, p, "cdm:BBS", sizeof("cdm:BBS")-1, zx_ns_tab+zx_xmlns_ix_cdm);
  for (se = x->MODEM; se; se = (struct zx_elem_s*)se->g.n)
    p = zx_ENC_SO_simple_elem(c, se, p, "cdm:MODEM", sizeof("cdm:MODEM")-1, zx_ns_tab+zx_xmlns_ix_cdm);
  for (se = x->ISDN; se; se = (struct zx_elem_s*)se->g.n)
    p = zx_ENC_SO_simple_elem(c, se, p, "cdm:ISDN", sizeof("cdm:ISDN")-1, zx_ns_tab+zx_xmlns_ix_cdm);
  for (se = x->PCS; se; se = (struct zx_elem_s*)se->g.n)
    p = zx_ENC_SO_simple_elem(c, se, p, "cdm:PCS", sizeof("cdm:PCS")-1, zx_ns_tab+zx_xmlns_ix_cdm);
  for (se = x->PREF; se; se = (struct zx_elem_s*)se->g.n)
    p = zx_ENC_SO_simple_elem(c, se, p, "cdm:PREF", sizeof("cdm:PREF")-1, zx_ns_tab+zx_xmlns_ix_cdm);
  {
      struct zx_cdm_NUMBER_s* e;
      for (e = x->NUMBER; e; e = (struct zx_cdm_NUMBER_s*)e->gg.g.n)
	  p = zx_ENC_SO_cdm_NUMBER(c, e, p);
  }

  p = zx_enc_so_unknown_elems_and_content(c, p, &x->gg);
  
#if 1 /* NORMALMODE */
  ZX_OUT_CLOSE_TAG(p, "</cdm:TEL>");
  zx_pop_seen(pop_seen);
#else
  /* root node has no end tag either */
#endif
  ENC_LEN_DEBUG(x, "cdm:TEL", p-enc_base);
  return p;
}

/* FUNC(zx_ENC_WO_cdm_TEL) */

/* Render element into string. The XML attributes and elements are
 * processed in wire order by chasing wo pointers. This is what you want for
 * validating signatures on other people's XML documents. */

/* Called by: */
char* zx_ENC_WO_cdm_TEL(struct zx_ctx* c, struct zx_cdm_TEL_s* x, char* p )
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
  ZX_OUT_MEM(p, "TEL", sizeof("TEL")-1);
  qq = p;

  /* *** sort the namespaces */
  if (c->inc_ns)
    zx_add_inc_ns(c, &pop_seen);
  if (x->id)
    zx_add_xmlns_if_not_seen(c, x->id->g.ns, &pop_seen);
  if (x->modificationTime)
    zx_add_xmlns_if_not_seen(c, x->modificationTime->g.ns, &pop_seen);
  zx_add_xmlns_if_not_seen(c, x->gg.g.ns, &pop_seen);

  p = zx_enc_seen(p, pop_seen); 
  p = zx_attr_wo_enc(p, x->id, "id=\"", sizeof("id=\"")-1);
  p = zx_attr_wo_enc(p, x->modificationTime, "modificationTime=\"", sizeof("modificationTime=\"")-1);

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
  ENC_LEN_DEBUG(x, "cdm:TEL", p-enc_base);
  return p;
}

/* FUNC(zx_EASY_ENC_SO_cdm_TEL) */

/* Called by: */
struct zx_str* zx_EASY_ENC_SO_cdm_TEL(struct zx_ctx* c, struct zx_cdm_TEL_s* x )
{
  int len;
  char* buf;
  c->ns_tab = ZX_ALLOC(c, sizeof(zx_ns_tab));
  memcpy(c->ns_tab, zx_ns_tab, sizeof(zx_ns_tab));
  len = zx_LEN_SO_cdm_TEL(c, x );
  buf = ZX_ALLOC(c, len+1);
  return zx_easy_enc_common(c, zx_ENC_SO_cdm_TEL(c, x, buf ), buf, len);
}

/* FUNC(zx_EASY_ENC_WO_cdm_TEL) */

/* Called by: */
struct zx_str* zx_EASY_ENC_WO_cdm_TEL(struct zx_ctx* c, struct zx_cdm_TEL_s* x )
{
  int len;
  char* buf;
  c->ns_tab = ZX_ALLOC(c, sizeof(zx_ns_tab));
  memcpy(c->ns_tab, zx_ns_tab, sizeof(zx_ns_tab));
  len = zx_LEN_WO_cdm_TEL(c, x );
  buf = ZX_ALLOC(c, len+1);
  return zx_easy_enc_common(c, zx_ENC_WO_cdm_TEL(c, x, buf ), buf, len);
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

#define EL_NAME   cdm_TITLE
#define EL_STRUCT zx_cdm_TITLE_s
#define EL_NS     cdm
#define EL_TAG    TITLE

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

/* FUNC(zx_LEN_SO_cdm_TITLE) */

/* Compute length of an element (and its subelements). The XML attributes
 * and elements are processed in schema order. */

/* Called by: */
int zx_LEN_SO_cdm_TITLE(struct zx_ctx* c, struct zx_cdm_TITLE_s* x )
{
  struct zx_ns_s* pop_seen = 0;
  struct zx_elem_s* se MAYBE_UNUSED;
#if 1 /* NORMALMODE */
  /* *** in simple_elem case should output ns prefix from ns node. */
  int len = sizeof("<cdm:TITLE")-1 + 1 + sizeof("</cdm:TITLE>")-1;
  if (c->inc_ns_len)
    len += zx_len_inc_ns(c, &pop_seen);
  if (x->group)
    len += zx_len_xmlns_if_not_seen(c, zx_ns_tab+zx_xmlns_ix_cb, &pop_seen);
  len += zx_len_xmlns_if_not_seen(c, zx_ns_tab+zx_xmlns_ix_cdm, &pop_seen);

  len += zx_attr_so_len(x->group, sizeof("cb:group")-1);

#else
  /* root node has no begin tag */
  int len = 0;
#endif
  


  len += zx_len_so_common(c, &x->gg);
  zx_pop_seen(pop_seen);
  ENC_LEN_DEBUG(x, "cdm:TITLE", len);
  return len;
}

/* FUNC(zx_LEN_WO_cdm_TITLE) */

/* Compute length of an element (and its subelements). The XML attributes
 * and elements are processed in wire order and no assumptions
 * are made about namespace prefixes. */

/* Called by: */
int zx_LEN_WO_cdm_TITLE(struct zx_ctx* c, struct zx_cdm_TITLE_s* x )
{
  struct zx_ns_s* pop_seen = 0;
  struct zx_elem_s* se MAYBE_UNUSED;
#if 1 /* NORMALMODE */
  int len = 1 + sizeof("TITLE")-1 + 1 + 2 + sizeof("TITLE")-1 + 1;
  
  if (x->gg.g.ns && x->gg.g.ns->prefix_len)
    len += (x->gg.g.ns->prefix_len + 1) * 2;
  if (c->inc_ns_len)
    len += zx_len_inc_ns(c, &pop_seen);
  if (x->group)
    len += zx_len_xmlns_if_not_seen(c, x->group->g.ns, &pop_seen);
  len += zx_len_xmlns_if_not_seen(c, x->gg.g.ns, &pop_seen);

  len += zx_attr_wo_len(x->group, sizeof("group")-1);

#else
  /* root node has no begin tag */
  int len = 0;
#endif
  


  len += zx_len_wo_common(c, &x->gg); 
  zx_pop_seen(pop_seen);
  ENC_LEN_DEBUG(x, "cdm:TITLE", len);
  return len;
}

/* FUNC(zx_ENC_SO_cdm_TITLE) */

/* Render element into string. The XML attributes and elements are
 * processed in schema order. This is what you generally want for
 * rendering new data structure to a string. The wo pointers are not used. */

/* Called by: */
char* zx_ENC_SO_cdm_TITLE(struct zx_ctx* c, struct zx_cdm_TITLE_s* x, char* p )
{
  struct zx_elem_s* se MAYBE_UNUSED;
  struct zx_ns_s* pop_seen = 0;
  ENC_LEN_DEBUG_BASE;
#if 1 /* NORMALMODE */
  /* *** in simple_elem case should output ns prefix from ns node. */
  ZX_OUT_TAG(p, "<cdm:TITLE");
  if (c->inc_ns)
    p = zx_enc_inc_ns(c, p, &pop_seen);
  if (x->group)
    p = zx_enc_xmlns_if_not_seen(c, p, zx_ns_tab+zx_xmlns_ix_cb, &pop_seen);
  p = zx_enc_xmlns_if_not_seen(c, p, zx_ns_tab+zx_xmlns_ix_cdm, &pop_seen);

  p = zx_attr_so_enc(p, x->group, " cb:group=\"", sizeof(" cb:group=\"")-1);

  p = zx_enc_unknown_attrs(p, x->gg.any_attr);
#else
  /* root node has no begin tag */
#endif
  

  p = zx_enc_so_unknown_elems_and_content(c, p, &x->gg);
  
#if 1 /* NORMALMODE */
  ZX_OUT_CLOSE_TAG(p, "</cdm:TITLE>");
  zx_pop_seen(pop_seen);
#else
  /* root node has no end tag either */
#endif
  ENC_LEN_DEBUG(x, "cdm:TITLE", p-enc_base);
  return p;
}

/* FUNC(zx_ENC_WO_cdm_TITLE) */

/* Render element into string. The XML attributes and elements are
 * processed in wire order by chasing wo pointers. This is what you want for
 * validating signatures on other people's XML documents. */

/* Called by: */
char* zx_ENC_WO_cdm_TITLE(struct zx_ctx* c, struct zx_cdm_TITLE_s* x, char* p )
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
  ZX_OUT_MEM(p, "TITLE", sizeof("TITLE")-1);
  qq = p;

  /* *** sort the namespaces */
  if (c->inc_ns)
    zx_add_inc_ns(c, &pop_seen);
  if (x->group)
    zx_add_xmlns_if_not_seen(c, x->group->g.ns, &pop_seen);
  zx_add_xmlns_if_not_seen(c, x->gg.g.ns, &pop_seen);

  p = zx_enc_seen(p, pop_seen); 
  p = zx_attr_wo_enc(p, x->group, "group=\"", sizeof("group=\"")-1);

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
  ENC_LEN_DEBUG(x, "cdm:TITLE", p-enc_base);
  return p;
}

/* FUNC(zx_EASY_ENC_SO_cdm_TITLE) */

/* Called by: */
struct zx_str* zx_EASY_ENC_SO_cdm_TITLE(struct zx_ctx* c, struct zx_cdm_TITLE_s* x )
{
  int len;
  char* buf;
  c->ns_tab = ZX_ALLOC(c, sizeof(zx_ns_tab));
  memcpy(c->ns_tab, zx_ns_tab, sizeof(zx_ns_tab));
  len = zx_LEN_SO_cdm_TITLE(c, x );
  buf = ZX_ALLOC(c, len+1);
  return zx_easy_enc_common(c, zx_ENC_SO_cdm_TITLE(c, x, buf ), buf, len);
}

/* FUNC(zx_EASY_ENC_WO_cdm_TITLE) */

/* Called by: */
struct zx_str* zx_EASY_ENC_WO_cdm_TITLE(struct zx_ctx* c, struct zx_cdm_TITLE_s* x )
{
  int len;
  char* buf;
  c->ns_tab = ZX_ALLOC(c, sizeof(zx_ns_tab));
  memcpy(c->ns_tab, zx_ns_tab, sizeof(zx_ns_tab));
  len = zx_LEN_WO_cdm_TITLE(c, x );
  buf = ZX_ALLOC(c, len+1);
  return zx_easy_enc_common(c, zx_ENC_WO_cdm_TITLE(c, x, buf ), buf, len);
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

#define EL_NAME   cdm_TYPE
#define EL_STRUCT zx_cdm_TYPE_s
#define EL_NS     cdm
#define EL_TAG    TYPE

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

/* FUNC(zx_LEN_SO_cdm_TYPE) */

/* Compute length of an element (and its subelements). The XML attributes
 * and elements are processed in schema order. */

/* Called by: */
int zx_LEN_SO_cdm_TYPE(struct zx_ctx* c, struct zx_cdm_TYPE_s* x )
{
  struct zx_ns_s* pop_seen = 0;
  struct zx_elem_s* se MAYBE_UNUSED;
#if 1 /* NORMALMODE */
  /* *** in simple_elem case should output ns prefix from ns node. */
  int len = sizeof("<cdm:TYPE")-1 + 1 + sizeof("</cdm:TYPE>")-1;
  if (c->inc_ns_len)
    len += zx_len_inc_ns(c, &pop_seen);
  if (x->ACC || x->ACCTime || x->id || x->modificationTime || x->modifier)
    len += zx_len_xmlns_if_not_seen(c, zx_ns_tab+zx_xmlns_ix_cb, &pop_seen);
  len += zx_len_xmlns_if_not_seen(c, zx_ns_tab+zx_xmlns_ix_cdm, &pop_seen);

  len += zx_attr_so_len(x->ACC, sizeof("cb:ACC")-1);
  len += zx_attr_so_len(x->ACCTime, sizeof("cb:ACCTime")-1);
  len += zx_attr_so_len(x->id, sizeof("cb:id")-1);
  len += zx_attr_so_len(x->modificationTime, sizeof("cb:modificationTime")-1);
  len += zx_attr_so_len(x->modifier, sizeof("cb:modifier")-1);

#else
  /* root node has no begin tag */
  int len = 0;
#endif
  


  len += zx_len_so_common(c, &x->gg);
  zx_pop_seen(pop_seen);
  ENC_LEN_DEBUG(x, "cdm:TYPE", len);
  return len;
}

/* FUNC(zx_LEN_WO_cdm_TYPE) */

/* Compute length of an element (and its subelements). The XML attributes
 * and elements are processed in wire order and no assumptions
 * are made about namespace prefixes. */

/* Called by: */
int zx_LEN_WO_cdm_TYPE(struct zx_ctx* c, struct zx_cdm_TYPE_s* x )
{
  struct zx_ns_s* pop_seen = 0;
  struct zx_elem_s* se MAYBE_UNUSED;
#if 1 /* NORMALMODE */
  int len = 1 + sizeof("TYPE")-1 + 1 + 2 + sizeof("TYPE")-1 + 1;
  
  if (x->gg.g.ns && x->gg.g.ns->prefix_len)
    len += (x->gg.g.ns->prefix_len + 1) * 2;
  if (c->inc_ns_len)
    len += zx_len_inc_ns(c, &pop_seen);
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
  len += zx_len_xmlns_if_not_seen(c, x->gg.g.ns, &pop_seen);

  len += zx_attr_wo_len(x->ACC, sizeof("ACC")-1);
  len += zx_attr_wo_len(x->ACCTime, sizeof("ACCTime")-1);
  len += zx_attr_wo_len(x->id, sizeof("id")-1);
  len += zx_attr_wo_len(x->modificationTime, sizeof("modificationTime")-1);
  len += zx_attr_wo_len(x->modifier, sizeof("modifier")-1);

#else
  /* root node has no begin tag */
  int len = 0;
#endif
  


  len += zx_len_wo_common(c, &x->gg); 
  zx_pop_seen(pop_seen);
  ENC_LEN_DEBUG(x, "cdm:TYPE", len);
  return len;
}

/* FUNC(zx_ENC_SO_cdm_TYPE) */

/* Render element into string. The XML attributes and elements are
 * processed in schema order. This is what you generally want for
 * rendering new data structure to a string. The wo pointers are not used. */

/* Called by: */
char* zx_ENC_SO_cdm_TYPE(struct zx_ctx* c, struct zx_cdm_TYPE_s* x, char* p )
{
  struct zx_elem_s* se MAYBE_UNUSED;
  struct zx_ns_s* pop_seen = 0;
  ENC_LEN_DEBUG_BASE;
#if 1 /* NORMALMODE */
  /* *** in simple_elem case should output ns prefix from ns node. */
  ZX_OUT_TAG(p, "<cdm:TYPE");
  if (c->inc_ns)
    p = zx_enc_inc_ns(c, p, &pop_seen);
  if (x->ACC || x->ACCTime || x->id || x->modificationTime || x->modifier)
    p = zx_enc_xmlns_if_not_seen(c, p, zx_ns_tab+zx_xmlns_ix_cb, &pop_seen);
  p = zx_enc_xmlns_if_not_seen(c, p, zx_ns_tab+zx_xmlns_ix_cdm, &pop_seen);

  p = zx_attr_so_enc(p, x->ACC, " cb:ACC=\"", sizeof(" cb:ACC=\"")-1);
  p = zx_attr_so_enc(p, x->ACCTime, " cb:ACCTime=\"", sizeof(" cb:ACCTime=\"")-1);
  p = zx_attr_so_enc(p, x->id, " cb:id=\"", sizeof(" cb:id=\"")-1);
  p = zx_attr_so_enc(p, x->modificationTime, " cb:modificationTime=\"", sizeof(" cb:modificationTime=\"")-1);
  p = zx_attr_so_enc(p, x->modifier, " cb:modifier=\"", sizeof(" cb:modifier=\"")-1);

  p = zx_enc_unknown_attrs(p, x->gg.any_attr);
#else
  /* root node has no begin tag */
#endif
  

  p = zx_enc_so_unknown_elems_and_content(c, p, &x->gg);
  
#if 1 /* NORMALMODE */
  ZX_OUT_CLOSE_TAG(p, "</cdm:TYPE>");
  zx_pop_seen(pop_seen);
#else
  /* root node has no end tag either */
#endif
  ENC_LEN_DEBUG(x, "cdm:TYPE", p-enc_base);
  return p;
}

/* FUNC(zx_ENC_WO_cdm_TYPE) */

/* Render element into string. The XML attributes and elements are
 * processed in wire order by chasing wo pointers. This is what you want for
 * validating signatures on other people's XML documents. */

/* Called by: */
char* zx_ENC_WO_cdm_TYPE(struct zx_ctx* c, struct zx_cdm_TYPE_s* x, char* p )
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
  ZX_OUT_MEM(p, "TYPE", sizeof("TYPE")-1);
  qq = p;

  /* *** sort the namespaces */
  if (c->inc_ns)
    zx_add_inc_ns(c, &pop_seen);
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
  zx_add_xmlns_if_not_seen(c, x->gg.g.ns, &pop_seen);

  p = zx_enc_seen(p, pop_seen); 
  p = zx_attr_wo_enc(p, x->ACC, "ACC=\"", sizeof("ACC=\"")-1);
  p = zx_attr_wo_enc(p, x->ACCTime, "ACCTime=\"", sizeof("ACCTime=\"")-1);
  p = zx_attr_wo_enc(p, x->id, "id=\"", sizeof("id=\"")-1);
  p = zx_attr_wo_enc(p, x->modificationTime, "modificationTime=\"", sizeof("modificationTime=\"")-1);
  p = zx_attr_wo_enc(p, x->modifier, "modifier=\"", sizeof("modifier=\"")-1);

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
  ENC_LEN_DEBUG(x, "cdm:TYPE", p-enc_base);
  return p;
}

/* FUNC(zx_EASY_ENC_SO_cdm_TYPE) */

/* Called by: */
struct zx_str* zx_EASY_ENC_SO_cdm_TYPE(struct zx_ctx* c, struct zx_cdm_TYPE_s* x )
{
  int len;
  char* buf;
  c->ns_tab = ZX_ALLOC(c, sizeof(zx_ns_tab));
  memcpy(c->ns_tab, zx_ns_tab, sizeof(zx_ns_tab));
  len = zx_LEN_SO_cdm_TYPE(c, x );
  buf = ZX_ALLOC(c, len+1);
  return zx_easy_enc_common(c, zx_ENC_SO_cdm_TYPE(c, x, buf ), buf, len);
}

/* FUNC(zx_EASY_ENC_WO_cdm_TYPE) */

/* Called by: */
struct zx_str* zx_EASY_ENC_WO_cdm_TYPE(struct zx_ctx* c, struct zx_cdm_TYPE_s* x )
{
  int len;
  char* buf;
  c->ns_tab = ZX_ALLOC(c, sizeof(zx_ns_tab));
  memcpy(c->ns_tab, zx_ns_tab, sizeof(zx_ns_tab));
  len = zx_LEN_WO_cdm_TYPE(c, x );
  buf = ZX_ALLOC(c, len+1);
  return zx_easy_enc_common(c, zx_ENC_WO_cdm_TYPE(c, x, buf ), buf, len);
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

#define EL_NAME   cdm_TZ
#define EL_STRUCT zx_cdm_TZ_s
#define EL_NS     cdm
#define EL_TAG    TZ

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

/* FUNC(zx_LEN_SO_cdm_TZ) */

/* Compute length of an element (and its subelements). The XML attributes
 * and elements are processed in schema order. */

/* Called by: */
int zx_LEN_SO_cdm_TZ(struct zx_ctx* c, struct zx_cdm_TZ_s* x )
{
  struct zx_ns_s* pop_seen = 0;
  struct zx_elem_s* se MAYBE_UNUSED;
#if 1 /* NORMALMODE */
  /* *** in simple_elem case should output ns prefix from ns node. */
  int len = sizeof("<cdm:TZ")-1 + 1 + sizeof("</cdm:TZ>")-1;
  if (c->inc_ns_len)
    len += zx_len_inc_ns(c, &pop_seen);
  if (x->ACC || x->ACCTime || x->id || x->modificationTime || x->modifier)
    len += zx_len_xmlns_if_not_seen(c, zx_ns_tab+zx_xmlns_ix_cb, &pop_seen);
  len += zx_len_xmlns_if_not_seen(c, zx_ns_tab+zx_xmlns_ix_cdm, &pop_seen);

  len += zx_attr_so_len(x->ACC, sizeof("cb:ACC")-1);
  len += zx_attr_so_len(x->ACCTime, sizeof("cb:ACCTime")-1);
  len += zx_attr_so_len(x->id, sizeof("cb:id")-1);
  len += zx_attr_so_len(x->modificationTime, sizeof("cb:modificationTime")-1);
  len += zx_attr_so_len(x->modifier, sizeof("cb:modifier")-1);

#else
  /* root node has no begin tag */
  int len = 0;
#endif
  


  len += zx_len_so_common(c, &x->gg);
  zx_pop_seen(pop_seen);
  ENC_LEN_DEBUG(x, "cdm:TZ", len);
  return len;
}

/* FUNC(zx_LEN_WO_cdm_TZ) */

/* Compute length of an element (and its subelements). The XML attributes
 * and elements are processed in wire order and no assumptions
 * are made about namespace prefixes. */

/* Called by: */
int zx_LEN_WO_cdm_TZ(struct zx_ctx* c, struct zx_cdm_TZ_s* x )
{
  struct zx_ns_s* pop_seen = 0;
  struct zx_elem_s* se MAYBE_UNUSED;
#if 1 /* NORMALMODE */
  int len = 1 + sizeof("TZ")-1 + 1 + 2 + sizeof("TZ")-1 + 1;
  
  if (x->gg.g.ns && x->gg.g.ns->prefix_len)
    len += (x->gg.g.ns->prefix_len + 1) * 2;
  if (c->inc_ns_len)
    len += zx_len_inc_ns(c, &pop_seen);
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
  len += zx_len_xmlns_if_not_seen(c, x->gg.g.ns, &pop_seen);

  len += zx_attr_wo_len(x->ACC, sizeof("ACC")-1);
  len += zx_attr_wo_len(x->ACCTime, sizeof("ACCTime")-1);
  len += zx_attr_wo_len(x->id, sizeof("id")-1);
  len += zx_attr_wo_len(x->modificationTime, sizeof("modificationTime")-1);
  len += zx_attr_wo_len(x->modifier, sizeof("modifier")-1);

#else
  /* root node has no begin tag */
  int len = 0;
#endif
  


  len += zx_len_wo_common(c, &x->gg); 
  zx_pop_seen(pop_seen);
  ENC_LEN_DEBUG(x, "cdm:TZ", len);
  return len;
}

/* FUNC(zx_ENC_SO_cdm_TZ) */

/* Render element into string. The XML attributes and elements are
 * processed in schema order. This is what you generally want for
 * rendering new data structure to a string. The wo pointers are not used. */

/* Called by: */
char* zx_ENC_SO_cdm_TZ(struct zx_ctx* c, struct zx_cdm_TZ_s* x, char* p )
{
  struct zx_elem_s* se MAYBE_UNUSED;
  struct zx_ns_s* pop_seen = 0;
  ENC_LEN_DEBUG_BASE;
#if 1 /* NORMALMODE */
  /* *** in simple_elem case should output ns prefix from ns node. */
  ZX_OUT_TAG(p, "<cdm:TZ");
  if (c->inc_ns)
    p = zx_enc_inc_ns(c, p, &pop_seen);
  if (x->ACC || x->ACCTime || x->id || x->modificationTime || x->modifier)
    p = zx_enc_xmlns_if_not_seen(c, p, zx_ns_tab+zx_xmlns_ix_cb, &pop_seen);
  p = zx_enc_xmlns_if_not_seen(c, p, zx_ns_tab+zx_xmlns_ix_cdm, &pop_seen);

  p = zx_attr_so_enc(p, x->ACC, " cb:ACC=\"", sizeof(" cb:ACC=\"")-1);
  p = zx_attr_so_enc(p, x->ACCTime, " cb:ACCTime=\"", sizeof(" cb:ACCTime=\"")-1);
  p = zx_attr_so_enc(p, x->id, " cb:id=\"", sizeof(" cb:id=\"")-1);
  p = zx_attr_so_enc(p, x->modificationTime, " cb:modificationTime=\"", sizeof(" cb:modificationTime=\"")-1);
  p = zx_attr_so_enc(p, x->modifier, " cb:modifier=\"", sizeof(" cb:modifier=\"")-1);

  p = zx_enc_unknown_attrs(p, x->gg.any_attr);
#else
  /* root node has no begin tag */
#endif
  

  p = zx_enc_so_unknown_elems_and_content(c, p, &x->gg);
  
#if 1 /* NORMALMODE */
  ZX_OUT_CLOSE_TAG(p, "</cdm:TZ>");
  zx_pop_seen(pop_seen);
#else
  /* root node has no end tag either */
#endif
  ENC_LEN_DEBUG(x, "cdm:TZ", p-enc_base);
  return p;
}

/* FUNC(zx_ENC_WO_cdm_TZ) */

/* Render element into string. The XML attributes and elements are
 * processed in wire order by chasing wo pointers. This is what you want for
 * validating signatures on other people's XML documents. */

/* Called by: */
char* zx_ENC_WO_cdm_TZ(struct zx_ctx* c, struct zx_cdm_TZ_s* x, char* p )
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
  ZX_OUT_MEM(p, "TZ", sizeof("TZ")-1);
  qq = p;

  /* *** sort the namespaces */
  if (c->inc_ns)
    zx_add_inc_ns(c, &pop_seen);
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
  zx_add_xmlns_if_not_seen(c, x->gg.g.ns, &pop_seen);

  p = zx_enc_seen(p, pop_seen); 
  p = zx_attr_wo_enc(p, x->ACC, "ACC=\"", sizeof("ACC=\"")-1);
  p = zx_attr_wo_enc(p, x->ACCTime, "ACCTime=\"", sizeof("ACCTime=\"")-1);
  p = zx_attr_wo_enc(p, x->id, "id=\"", sizeof("id=\"")-1);
  p = zx_attr_wo_enc(p, x->modificationTime, "modificationTime=\"", sizeof("modificationTime=\"")-1);
  p = zx_attr_wo_enc(p, x->modifier, "modifier=\"", sizeof("modifier=\"")-1);

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
  ENC_LEN_DEBUG(x, "cdm:TZ", p-enc_base);
  return p;
}

/* FUNC(zx_EASY_ENC_SO_cdm_TZ) */

/* Called by: */
struct zx_str* zx_EASY_ENC_SO_cdm_TZ(struct zx_ctx* c, struct zx_cdm_TZ_s* x )
{
  int len;
  char* buf;
  c->ns_tab = ZX_ALLOC(c, sizeof(zx_ns_tab));
  memcpy(c->ns_tab, zx_ns_tab, sizeof(zx_ns_tab));
  len = zx_LEN_SO_cdm_TZ(c, x );
  buf = ZX_ALLOC(c, len+1);
  return zx_easy_enc_common(c, zx_ENC_SO_cdm_TZ(c, x, buf ), buf, len);
}

/* FUNC(zx_EASY_ENC_WO_cdm_TZ) */

/* Called by: */
struct zx_str* zx_EASY_ENC_WO_cdm_TZ(struct zx_ctx* c, struct zx_cdm_TZ_s* x )
{
  int len;
  char* buf;
  c->ns_tab = ZX_ALLOC(c, sizeof(zx_ns_tab));
  memcpy(c->ns_tab, zx_ns_tab, sizeof(zx_ns_tab));
  len = zx_LEN_WO_cdm_TZ(c, x );
  buf = ZX_ALLOC(c, len+1);
  return zx_easy_enc_common(c, zx_ENC_WO_cdm_TZ(c, x, buf ), buf, len);
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

#define EL_NAME   cdm_UID
#define EL_STRUCT zx_cdm_UID_s
#define EL_NS     cdm
#define EL_TAG    UID

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

/* FUNC(zx_LEN_SO_cdm_UID) */

/* Compute length of an element (and its subelements). The XML attributes
 * and elements are processed in schema order. */

/* Called by: */
int zx_LEN_SO_cdm_UID(struct zx_ctx* c, struct zx_cdm_UID_s* x )
{
  struct zx_ns_s* pop_seen = 0;
  struct zx_elem_s* se MAYBE_UNUSED;
#if 1 /* NORMALMODE */
  /* *** in simple_elem case should output ns prefix from ns node. */
  int len = sizeof("<cdm:UID")-1 + 1 + sizeof("</cdm:UID>")-1;
  if (c->inc_ns_len)
    len += zx_len_inc_ns(c, &pop_seen);
  if (x->ACC || x->ACCTime || x->id || x->modificationTime || x->modifier)
    len += zx_len_xmlns_if_not_seen(c, zx_ns_tab+zx_xmlns_ix_cb, &pop_seen);
  len += zx_len_xmlns_if_not_seen(c, zx_ns_tab+zx_xmlns_ix_cdm, &pop_seen);

  len += zx_attr_so_len(x->ACC, sizeof("cb:ACC")-1);
  len += zx_attr_so_len(x->ACCTime, sizeof("cb:ACCTime")-1);
  len += zx_attr_so_len(x->id, sizeof("cb:id")-1);
  len += zx_attr_so_len(x->modificationTime, sizeof("cb:modificationTime")-1);
  len += zx_attr_so_len(x->modifier, sizeof("cb:modifier")-1);

#else
  /* root node has no begin tag */
  int len = 0;
#endif
  


  len += zx_len_so_common(c, &x->gg);
  zx_pop_seen(pop_seen);
  ENC_LEN_DEBUG(x, "cdm:UID", len);
  return len;
}

/* FUNC(zx_LEN_WO_cdm_UID) */

/* Compute length of an element (and its subelements). The XML attributes
 * and elements are processed in wire order and no assumptions
 * are made about namespace prefixes. */

/* Called by: */
int zx_LEN_WO_cdm_UID(struct zx_ctx* c, struct zx_cdm_UID_s* x )
{
  struct zx_ns_s* pop_seen = 0;
  struct zx_elem_s* se MAYBE_UNUSED;
#if 1 /* NORMALMODE */
  int len = 1 + sizeof("UID")-1 + 1 + 2 + sizeof("UID")-1 + 1;
  
  if (x->gg.g.ns && x->gg.g.ns->prefix_len)
    len += (x->gg.g.ns->prefix_len + 1) * 2;
  if (c->inc_ns_len)
    len += zx_len_inc_ns(c, &pop_seen);
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
  len += zx_len_xmlns_if_not_seen(c, x->gg.g.ns, &pop_seen);

  len += zx_attr_wo_len(x->ACC, sizeof("ACC")-1);
  len += zx_attr_wo_len(x->ACCTime, sizeof("ACCTime")-1);
  len += zx_attr_wo_len(x->id, sizeof("id")-1);
  len += zx_attr_wo_len(x->modificationTime, sizeof("modificationTime")-1);
  len += zx_attr_wo_len(x->modifier, sizeof("modifier")-1);

#else
  /* root node has no begin tag */
  int len = 0;
#endif
  


  len += zx_len_wo_common(c, &x->gg); 
  zx_pop_seen(pop_seen);
  ENC_LEN_DEBUG(x, "cdm:UID", len);
  return len;
}

/* FUNC(zx_ENC_SO_cdm_UID) */

/* Render element into string. The XML attributes and elements are
 * processed in schema order. This is what you generally want for
 * rendering new data structure to a string. The wo pointers are not used. */

/* Called by: */
char* zx_ENC_SO_cdm_UID(struct zx_ctx* c, struct zx_cdm_UID_s* x, char* p )
{
  struct zx_elem_s* se MAYBE_UNUSED;
  struct zx_ns_s* pop_seen = 0;
  ENC_LEN_DEBUG_BASE;
#if 1 /* NORMALMODE */
  /* *** in simple_elem case should output ns prefix from ns node. */
  ZX_OUT_TAG(p, "<cdm:UID");
  if (c->inc_ns)
    p = zx_enc_inc_ns(c, p, &pop_seen);
  if (x->ACC || x->ACCTime || x->id || x->modificationTime || x->modifier)
    p = zx_enc_xmlns_if_not_seen(c, p, zx_ns_tab+zx_xmlns_ix_cb, &pop_seen);
  p = zx_enc_xmlns_if_not_seen(c, p, zx_ns_tab+zx_xmlns_ix_cdm, &pop_seen);

  p = zx_attr_so_enc(p, x->ACC, " cb:ACC=\"", sizeof(" cb:ACC=\"")-1);
  p = zx_attr_so_enc(p, x->ACCTime, " cb:ACCTime=\"", sizeof(" cb:ACCTime=\"")-1);
  p = zx_attr_so_enc(p, x->id, " cb:id=\"", sizeof(" cb:id=\"")-1);
  p = zx_attr_so_enc(p, x->modificationTime, " cb:modificationTime=\"", sizeof(" cb:modificationTime=\"")-1);
  p = zx_attr_so_enc(p, x->modifier, " cb:modifier=\"", sizeof(" cb:modifier=\"")-1);

  p = zx_enc_unknown_attrs(p, x->gg.any_attr);
#else
  /* root node has no begin tag */
#endif
  

  p = zx_enc_so_unknown_elems_and_content(c, p, &x->gg);
  
#if 1 /* NORMALMODE */
  ZX_OUT_CLOSE_TAG(p, "</cdm:UID>");
  zx_pop_seen(pop_seen);
#else
  /* root node has no end tag either */
#endif
  ENC_LEN_DEBUG(x, "cdm:UID", p-enc_base);
  return p;
}

/* FUNC(zx_ENC_WO_cdm_UID) */

/* Render element into string. The XML attributes and elements are
 * processed in wire order by chasing wo pointers. This is what you want for
 * validating signatures on other people's XML documents. */

/* Called by: */
char* zx_ENC_WO_cdm_UID(struct zx_ctx* c, struct zx_cdm_UID_s* x, char* p )
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
  ZX_OUT_MEM(p, "UID", sizeof("UID")-1);
  qq = p;

  /* *** sort the namespaces */
  if (c->inc_ns)
    zx_add_inc_ns(c, &pop_seen);
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
  zx_add_xmlns_if_not_seen(c, x->gg.g.ns, &pop_seen);

  p = zx_enc_seen(p, pop_seen); 
  p = zx_attr_wo_enc(p, x->ACC, "ACC=\"", sizeof("ACC=\"")-1);
  p = zx_attr_wo_enc(p, x->ACCTime, "ACCTime=\"", sizeof("ACCTime=\"")-1);
  p = zx_attr_wo_enc(p, x->id, "id=\"", sizeof("id=\"")-1);
  p = zx_attr_wo_enc(p, x->modificationTime, "modificationTime=\"", sizeof("modificationTime=\"")-1);
  p = zx_attr_wo_enc(p, x->modifier, "modifier=\"", sizeof("modifier=\"")-1);

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
  ENC_LEN_DEBUG(x, "cdm:UID", p-enc_base);
  return p;
}

/* FUNC(zx_EASY_ENC_SO_cdm_UID) */

/* Called by: */
struct zx_str* zx_EASY_ENC_SO_cdm_UID(struct zx_ctx* c, struct zx_cdm_UID_s* x )
{
  int len;
  char* buf;
  c->ns_tab = ZX_ALLOC(c, sizeof(zx_ns_tab));
  memcpy(c->ns_tab, zx_ns_tab, sizeof(zx_ns_tab));
  len = zx_LEN_SO_cdm_UID(c, x );
  buf = ZX_ALLOC(c, len+1);
  return zx_easy_enc_common(c, zx_ENC_SO_cdm_UID(c, x, buf ), buf, len);
}

/* FUNC(zx_EASY_ENC_WO_cdm_UID) */

/* Called by: */
struct zx_str* zx_EASY_ENC_WO_cdm_UID(struct zx_ctx* c, struct zx_cdm_UID_s* x )
{
  int len;
  char* buf;
  c->ns_tab = ZX_ALLOC(c, sizeof(zx_ns_tab));
  memcpy(c->ns_tab, zx_ns_tab, sizeof(zx_ns_tab));
  len = zx_LEN_WO_cdm_UID(c, x );
  buf = ZX_ALLOC(c, len+1);
  return zx_easy_enc_common(c, zx_ENC_WO_cdm_UID(c, x, buf ), buf, len);
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

#define EL_NAME   cdm_URI
#define EL_STRUCT zx_cdm_URI_s
#define EL_NS     cdm
#define EL_TAG    URI

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

/* FUNC(zx_LEN_SO_cdm_URI) */

/* Compute length of an element (and its subelements). The XML attributes
 * and elements are processed in schema order. */

/* Called by: */
int zx_LEN_SO_cdm_URI(struct zx_ctx* c, struct zx_cdm_URI_s* x )
{
  struct zx_ns_s* pop_seen = 0;
  struct zx_elem_s* se MAYBE_UNUSED;
#if 1 /* NORMALMODE */
  /* *** in simple_elem case should output ns prefix from ns node. */
  int len = sizeof("<cdm:URI")-1 + 1 + sizeof("</cdm:URI>")-1;
  if (c->inc_ns_len)
    len += zx_len_inc_ns(c, &pop_seen);
  if (x->ACC || x->ACCTime || x->id || x->modificationTime || x->modifier)
    len += zx_len_xmlns_if_not_seen(c, zx_ns_tab+zx_xmlns_ix_cb, &pop_seen);
  len += zx_len_xmlns_if_not_seen(c, zx_ns_tab+zx_xmlns_ix_cdm, &pop_seen);

  len += zx_attr_so_len(x->ACC, sizeof("cb:ACC")-1);
  len += zx_attr_so_len(x->ACCTime, sizeof("cb:ACCTime")-1);
  len += zx_attr_so_len(x->id, sizeof("cb:id")-1);
  len += zx_attr_so_len(x->modificationTime, sizeof("cb:modificationTime")-1);
  len += zx_attr_so_len(x->modifier, sizeof("cb:modifier")-1);

#else
  /* root node has no begin tag */
  int len = 0;
#endif
  


  len += zx_len_so_common(c, &x->gg);
  zx_pop_seen(pop_seen);
  ENC_LEN_DEBUG(x, "cdm:URI", len);
  return len;
}

/* FUNC(zx_LEN_WO_cdm_URI) */

/* Compute length of an element (and its subelements). The XML attributes
 * and elements are processed in wire order and no assumptions
 * are made about namespace prefixes. */

/* Called by: */
int zx_LEN_WO_cdm_URI(struct zx_ctx* c, struct zx_cdm_URI_s* x )
{
  struct zx_ns_s* pop_seen = 0;
  struct zx_elem_s* se MAYBE_UNUSED;
#if 1 /* NORMALMODE */
  int len = 1 + sizeof("URI")-1 + 1 + 2 + sizeof("URI")-1 + 1;
  
  if (x->gg.g.ns && x->gg.g.ns->prefix_len)
    len += (x->gg.g.ns->prefix_len + 1) * 2;
  if (c->inc_ns_len)
    len += zx_len_inc_ns(c, &pop_seen);
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
  len += zx_len_xmlns_if_not_seen(c, x->gg.g.ns, &pop_seen);

  len += zx_attr_wo_len(x->ACC, sizeof("ACC")-1);
  len += zx_attr_wo_len(x->ACCTime, sizeof("ACCTime")-1);
  len += zx_attr_wo_len(x->id, sizeof("id")-1);
  len += zx_attr_wo_len(x->modificationTime, sizeof("modificationTime")-1);
  len += zx_attr_wo_len(x->modifier, sizeof("modifier")-1);

#else
  /* root node has no begin tag */
  int len = 0;
#endif
  


  len += zx_len_wo_common(c, &x->gg); 
  zx_pop_seen(pop_seen);
  ENC_LEN_DEBUG(x, "cdm:URI", len);
  return len;
}

/* FUNC(zx_ENC_SO_cdm_URI) */

/* Render element into string. The XML attributes and elements are
 * processed in schema order. This is what you generally want for
 * rendering new data structure to a string. The wo pointers are not used. */

/* Called by: */
char* zx_ENC_SO_cdm_URI(struct zx_ctx* c, struct zx_cdm_URI_s* x, char* p )
{
  struct zx_elem_s* se MAYBE_UNUSED;
  struct zx_ns_s* pop_seen = 0;
  ENC_LEN_DEBUG_BASE;
#if 1 /* NORMALMODE */
  /* *** in simple_elem case should output ns prefix from ns node. */
  ZX_OUT_TAG(p, "<cdm:URI");
  if (c->inc_ns)
    p = zx_enc_inc_ns(c, p, &pop_seen);
  if (x->ACC || x->ACCTime || x->id || x->modificationTime || x->modifier)
    p = zx_enc_xmlns_if_not_seen(c, p, zx_ns_tab+zx_xmlns_ix_cb, &pop_seen);
  p = zx_enc_xmlns_if_not_seen(c, p, zx_ns_tab+zx_xmlns_ix_cdm, &pop_seen);

  p = zx_attr_so_enc(p, x->ACC, " cb:ACC=\"", sizeof(" cb:ACC=\"")-1);
  p = zx_attr_so_enc(p, x->ACCTime, " cb:ACCTime=\"", sizeof(" cb:ACCTime=\"")-1);
  p = zx_attr_so_enc(p, x->id, " cb:id=\"", sizeof(" cb:id=\"")-1);
  p = zx_attr_so_enc(p, x->modificationTime, " cb:modificationTime=\"", sizeof(" cb:modificationTime=\"")-1);
  p = zx_attr_so_enc(p, x->modifier, " cb:modifier=\"", sizeof(" cb:modifier=\"")-1);

  p = zx_enc_unknown_attrs(p, x->gg.any_attr);
#else
  /* root node has no begin tag */
#endif
  

  p = zx_enc_so_unknown_elems_and_content(c, p, &x->gg);
  
#if 1 /* NORMALMODE */
  ZX_OUT_CLOSE_TAG(p, "</cdm:URI>");
  zx_pop_seen(pop_seen);
#else
  /* root node has no end tag either */
#endif
  ENC_LEN_DEBUG(x, "cdm:URI", p-enc_base);
  return p;
}

/* FUNC(zx_ENC_WO_cdm_URI) */

/* Render element into string. The XML attributes and elements are
 * processed in wire order by chasing wo pointers. This is what you want for
 * validating signatures on other people's XML documents. */

/* Called by: */
char* zx_ENC_WO_cdm_URI(struct zx_ctx* c, struct zx_cdm_URI_s* x, char* p )
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
  ZX_OUT_MEM(p, "URI", sizeof("URI")-1);
  qq = p;

  /* *** sort the namespaces */
  if (c->inc_ns)
    zx_add_inc_ns(c, &pop_seen);
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
  zx_add_xmlns_if_not_seen(c, x->gg.g.ns, &pop_seen);

  p = zx_enc_seen(p, pop_seen); 
  p = zx_attr_wo_enc(p, x->ACC, "ACC=\"", sizeof("ACC=\"")-1);
  p = zx_attr_wo_enc(p, x->ACCTime, "ACCTime=\"", sizeof("ACCTime=\"")-1);
  p = zx_attr_wo_enc(p, x->id, "id=\"", sizeof("id=\"")-1);
  p = zx_attr_wo_enc(p, x->modificationTime, "modificationTime=\"", sizeof("modificationTime=\"")-1);
  p = zx_attr_wo_enc(p, x->modifier, "modifier=\"", sizeof("modifier=\"")-1);

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
  ENC_LEN_DEBUG(x, "cdm:URI", p-enc_base);
  return p;
}

/* FUNC(zx_EASY_ENC_SO_cdm_URI) */

/* Called by: */
struct zx_str* zx_EASY_ENC_SO_cdm_URI(struct zx_ctx* c, struct zx_cdm_URI_s* x )
{
  int len;
  char* buf;
  c->ns_tab = ZX_ALLOC(c, sizeof(zx_ns_tab));
  memcpy(c->ns_tab, zx_ns_tab, sizeof(zx_ns_tab));
  len = zx_LEN_SO_cdm_URI(c, x );
  buf = ZX_ALLOC(c, len+1);
  return zx_easy_enc_common(c, zx_ENC_SO_cdm_URI(c, x, buf ), buf, len);
}

/* FUNC(zx_EASY_ENC_WO_cdm_URI) */

/* Called by: */
struct zx_str* zx_EASY_ENC_WO_cdm_URI(struct zx_ctx* c, struct zx_cdm_URI_s* x )
{
  int len;
  char* buf;
  c->ns_tab = ZX_ALLOC(c, sizeof(zx_ns_tab));
  memcpy(c->ns_tab, zx_ns_tab, sizeof(zx_ns_tab));
  len = zx_LEN_WO_cdm_URI(c, x );
  buf = ZX_ALLOC(c, len+1);
  return zx_easy_enc_common(c, zx_ENC_WO_cdm_URI(c, x, buf ), buf, len);
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

#define EL_NAME   cdm_URL
#define EL_STRUCT zx_cdm_URL_s
#define EL_NS     cdm
#define EL_TAG    URL

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

/* FUNC(zx_LEN_SO_cdm_URL) */

/* Compute length of an element (and its subelements). The XML attributes
 * and elements are processed in schema order. */

/* Called by: */
int zx_LEN_SO_cdm_URL(struct zx_ctx* c, struct zx_cdm_URL_s* x )
{
  struct zx_ns_s* pop_seen = 0;
  struct zx_elem_s* se MAYBE_UNUSED;
#if 1 /* NORMALMODE */
  /* *** in simple_elem case should output ns prefix from ns node. */
  int len = sizeof("<cdm:URL")-1 + 1 + sizeof("</cdm:URL>")-1;
  if (c->inc_ns_len)
    len += zx_len_inc_ns(c, &pop_seen);
  if (x->ACC || x->ACCTime || x->id || x->modificationTime || x->modifier)
    len += zx_len_xmlns_if_not_seen(c, zx_ns_tab+zx_xmlns_ix_cb, &pop_seen);
  len += zx_len_xmlns_if_not_seen(c, zx_ns_tab+zx_xmlns_ix_cdm, &pop_seen);

  len += zx_attr_so_len(x->ACC, sizeof("cb:ACC")-1);
  len += zx_attr_so_len(x->ACCTime, sizeof("cb:ACCTime")-1);
  len += zx_attr_so_len(x->id, sizeof("cb:id")-1);
  len += zx_attr_so_len(x->modificationTime, sizeof("cb:modificationTime")-1);
  len += zx_attr_so_len(x->modifier, sizeof("cb:modifier")-1);

#else
  /* root node has no begin tag */
  int len = 0;
#endif
  


  len += zx_len_so_common(c, &x->gg);
  zx_pop_seen(pop_seen);
  ENC_LEN_DEBUG(x, "cdm:URL", len);
  return len;
}

/* FUNC(zx_LEN_WO_cdm_URL) */

/* Compute length of an element (and its subelements). The XML attributes
 * and elements are processed in wire order and no assumptions
 * are made about namespace prefixes. */

/* Called by: */
int zx_LEN_WO_cdm_URL(struct zx_ctx* c, struct zx_cdm_URL_s* x )
{
  struct zx_ns_s* pop_seen = 0;
  struct zx_elem_s* se MAYBE_UNUSED;
#if 1 /* NORMALMODE */
  int len = 1 + sizeof("URL")-1 + 1 + 2 + sizeof("URL")-1 + 1;
  
  if (x->gg.g.ns && x->gg.g.ns->prefix_len)
    len += (x->gg.g.ns->prefix_len + 1) * 2;
  if (c->inc_ns_len)
    len += zx_len_inc_ns(c, &pop_seen);
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
  len += zx_len_xmlns_if_not_seen(c, x->gg.g.ns, &pop_seen);

  len += zx_attr_wo_len(x->ACC, sizeof("ACC")-1);
  len += zx_attr_wo_len(x->ACCTime, sizeof("ACCTime")-1);
  len += zx_attr_wo_len(x->id, sizeof("id")-1);
  len += zx_attr_wo_len(x->modificationTime, sizeof("modificationTime")-1);
  len += zx_attr_wo_len(x->modifier, sizeof("modifier")-1);

#else
  /* root node has no begin tag */
  int len = 0;
#endif
  


  len += zx_len_wo_common(c, &x->gg); 
  zx_pop_seen(pop_seen);
  ENC_LEN_DEBUG(x, "cdm:URL", len);
  return len;
}

/* FUNC(zx_ENC_SO_cdm_URL) */

/* Render element into string. The XML attributes and elements are
 * processed in schema order. This is what you generally want for
 * rendering new data structure to a string. The wo pointers are not used. */

/* Called by: */
char* zx_ENC_SO_cdm_URL(struct zx_ctx* c, struct zx_cdm_URL_s* x, char* p )
{
  struct zx_elem_s* se MAYBE_UNUSED;
  struct zx_ns_s* pop_seen = 0;
  ENC_LEN_DEBUG_BASE;
#if 1 /* NORMALMODE */
  /* *** in simple_elem case should output ns prefix from ns node. */
  ZX_OUT_TAG(p, "<cdm:URL");
  if (c->inc_ns)
    p = zx_enc_inc_ns(c, p, &pop_seen);
  if (x->ACC || x->ACCTime || x->id || x->modificationTime || x->modifier)
    p = zx_enc_xmlns_if_not_seen(c, p, zx_ns_tab+zx_xmlns_ix_cb, &pop_seen);
  p = zx_enc_xmlns_if_not_seen(c, p, zx_ns_tab+zx_xmlns_ix_cdm, &pop_seen);

  p = zx_attr_so_enc(p, x->ACC, " cb:ACC=\"", sizeof(" cb:ACC=\"")-1);
  p = zx_attr_so_enc(p, x->ACCTime, " cb:ACCTime=\"", sizeof(" cb:ACCTime=\"")-1);
  p = zx_attr_so_enc(p, x->id, " cb:id=\"", sizeof(" cb:id=\"")-1);
  p = zx_attr_so_enc(p, x->modificationTime, " cb:modificationTime=\"", sizeof(" cb:modificationTime=\"")-1);
  p = zx_attr_so_enc(p, x->modifier, " cb:modifier=\"", sizeof(" cb:modifier=\"")-1);

  p = zx_enc_unknown_attrs(p, x->gg.any_attr);
#else
  /* root node has no begin tag */
#endif
  

  p = zx_enc_so_unknown_elems_and_content(c, p, &x->gg);
  
#if 1 /* NORMALMODE */
  ZX_OUT_CLOSE_TAG(p, "</cdm:URL>");
  zx_pop_seen(pop_seen);
#else
  /* root node has no end tag either */
#endif
  ENC_LEN_DEBUG(x, "cdm:URL", p-enc_base);
  return p;
}

/* FUNC(zx_ENC_WO_cdm_URL) */

/* Render element into string. The XML attributes and elements are
 * processed in wire order by chasing wo pointers. This is what you want for
 * validating signatures on other people's XML documents. */

/* Called by: */
char* zx_ENC_WO_cdm_URL(struct zx_ctx* c, struct zx_cdm_URL_s* x, char* p )
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
  ZX_OUT_MEM(p, "URL", sizeof("URL")-1);
  qq = p;

  /* *** sort the namespaces */
  if (c->inc_ns)
    zx_add_inc_ns(c, &pop_seen);
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
  zx_add_xmlns_if_not_seen(c, x->gg.g.ns, &pop_seen);

  p = zx_enc_seen(p, pop_seen); 
  p = zx_attr_wo_enc(p, x->ACC, "ACC=\"", sizeof("ACC=\"")-1);
  p = zx_attr_wo_enc(p, x->ACCTime, "ACCTime=\"", sizeof("ACCTime=\"")-1);
  p = zx_attr_wo_enc(p, x->id, "id=\"", sizeof("id=\"")-1);
  p = zx_attr_wo_enc(p, x->modificationTime, "modificationTime=\"", sizeof("modificationTime=\"")-1);
  p = zx_attr_wo_enc(p, x->modifier, "modifier=\"", sizeof("modifier=\"")-1);

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
  ENC_LEN_DEBUG(x, "cdm:URL", p-enc_base);
  return p;
}

/* FUNC(zx_EASY_ENC_SO_cdm_URL) */

/* Called by: */
struct zx_str* zx_EASY_ENC_SO_cdm_URL(struct zx_ctx* c, struct zx_cdm_URL_s* x )
{
  int len;
  char* buf;
  c->ns_tab = ZX_ALLOC(c, sizeof(zx_ns_tab));
  memcpy(c->ns_tab, zx_ns_tab, sizeof(zx_ns_tab));
  len = zx_LEN_SO_cdm_URL(c, x );
  buf = ZX_ALLOC(c, len+1);
  return zx_easy_enc_common(c, zx_ENC_SO_cdm_URL(c, x, buf ), buf, len);
}

/* FUNC(zx_EASY_ENC_WO_cdm_URL) */

/* Called by: */
struct zx_str* zx_EASY_ENC_WO_cdm_URL(struct zx_ctx* c, struct zx_cdm_URL_s* x )
{
  int len;
  char* buf;
  c->ns_tab = ZX_ALLOC(c, sizeof(zx_ns_tab));
  memcpy(c->ns_tab, zx_ns_tab, sizeof(zx_ns_tab));
  len = zx_LEN_WO_cdm_URL(c, x );
  buf = ZX_ALLOC(c, len+1);
  return zx_easy_enc_common(c, zx_ENC_WO_cdm_URL(c, x, buf ), buf, len);
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

#define EL_NAME   cdm_USERID
#define EL_STRUCT zx_cdm_USERID_s
#define EL_NS     cdm
#define EL_TAG    USERID

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

/* FUNC(zx_LEN_SO_cdm_USERID) */

/* Compute length of an element (and its subelements). The XML attributes
 * and elements are processed in schema order. */

/* Called by: */
int zx_LEN_SO_cdm_USERID(struct zx_ctx* c, struct zx_cdm_USERID_s* x )
{
  struct zx_ns_s* pop_seen = 0;
  struct zx_elem_s* se MAYBE_UNUSED;
#if 1 /* NORMALMODE */
  /* *** in simple_elem case should output ns prefix from ns node. */
  int len = sizeof("<cdm:USERID")-1 + 1 + sizeof("</cdm:USERID>")-1;
  if (c->inc_ns_len)
    len += zx_len_inc_ns(c, &pop_seen);
  if (x->ACC || x->ACCTime || x->id || x->modificationTime || x->modifier)
    len += zx_len_xmlns_if_not_seen(c, zx_ns_tab+zx_xmlns_ix_cb, &pop_seen);
  len += zx_len_xmlns_if_not_seen(c, zx_ns_tab+zx_xmlns_ix_cdm, &pop_seen);

  len += zx_attr_so_len(x->ACC, sizeof("cb:ACC")-1);
  len += zx_attr_so_len(x->ACCTime, sizeof("cb:ACCTime")-1);
  len += zx_attr_so_len(x->id, sizeof("cb:id")-1);
  len += zx_attr_so_len(x->modificationTime, sizeof("cb:modificationTime")-1);
  len += zx_attr_so_len(x->modifier, sizeof("cb:modifier")-1);

#else
  /* root node has no begin tag */
  int len = 0;
#endif
  


  len += zx_len_so_common(c, &x->gg);
  zx_pop_seen(pop_seen);
  ENC_LEN_DEBUG(x, "cdm:USERID", len);
  return len;
}

/* FUNC(zx_LEN_WO_cdm_USERID) */

/* Compute length of an element (and its subelements). The XML attributes
 * and elements are processed in wire order and no assumptions
 * are made about namespace prefixes. */

/* Called by: */
int zx_LEN_WO_cdm_USERID(struct zx_ctx* c, struct zx_cdm_USERID_s* x )
{
  struct zx_ns_s* pop_seen = 0;
  struct zx_elem_s* se MAYBE_UNUSED;
#if 1 /* NORMALMODE */
  int len = 1 + sizeof("USERID")-1 + 1 + 2 + sizeof("USERID")-1 + 1;
  
  if (x->gg.g.ns && x->gg.g.ns->prefix_len)
    len += (x->gg.g.ns->prefix_len + 1) * 2;
  if (c->inc_ns_len)
    len += zx_len_inc_ns(c, &pop_seen);
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
  len += zx_len_xmlns_if_not_seen(c, x->gg.g.ns, &pop_seen);

  len += zx_attr_wo_len(x->ACC, sizeof("ACC")-1);
  len += zx_attr_wo_len(x->ACCTime, sizeof("ACCTime")-1);
  len += zx_attr_wo_len(x->id, sizeof("id")-1);
  len += zx_attr_wo_len(x->modificationTime, sizeof("modificationTime")-1);
  len += zx_attr_wo_len(x->modifier, sizeof("modifier")-1);

#else
  /* root node has no begin tag */
  int len = 0;
#endif
  


  len += zx_len_wo_common(c, &x->gg); 
  zx_pop_seen(pop_seen);
  ENC_LEN_DEBUG(x, "cdm:USERID", len);
  return len;
}

/* FUNC(zx_ENC_SO_cdm_USERID) */

/* Render element into string. The XML attributes and elements are
 * processed in schema order. This is what you generally want for
 * rendering new data structure to a string. The wo pointers are not used. */

/* Called by: */
char* zx_ENC_SO_cdm_USERID(struct zx_ctx* c, struct zx_cdm_USERID_s* x, char* p )
{
  struct zx_elem_s* se MAYBE_UNUSED;
  struct zx_ns_s* pop_seen = 0;
  ENC_LEN_DEBUG_BASE;
#if 1 /* NORMALMODE */
  /* *** in simple_elem case should output ns prefix from ns node. */
  ZX_OUT_TAG(p, "<cdm:USERID");
  if (c->inc_ns)
    p = zx_enc_inc_ns(c, p, &pop_seen);
  if (x->ACC || x->ACCTime || x->id || x->modificationTime || x->modifier)
    p = zx_enc_xmlns_if_not_seen(c, p, zx_ns_tab+zx_xmlns_ix_cb, &pop_seen);
  p = zx_enc_xmlns_if_not_seen(c, p, zx_ns_tab+zx_xmlns_ix_cdm, &pop_seen);

  p = zx_attr_so_enc(p, x->ACC, " cb:ACC=\"", sizeof(" cb:ACC=\"")-1);
  p = zx_attr_so_enc(p, x->ACCTime, " cb:ACCTime=\"", sizeof(" cb:ACCTime=\"")-1);
  p = zx_attr_so_enc(p, x->id, " cb:id=\"", sizeof(" cb:id=\"")-1);
  p = zx_attr_so_enc(p, x->modificationTime, " cb:modificationTime=\"", sizeof(" cb:modificationTime=\"")-1);
  p = zx_attr_so_enc(p, x->modifier, " cb:modifier=\"", sizeof(" cb:modifier=\"")-1);

  p = zx_enc_unknown_attrs(p, x->gg.any_attr);
#else
  /* root node has no begin tag */
#endif
  

  p = zx_enc_so_unknown_elems_and_content(c, p, &x->gg);
  
#if 1 /* NORMALMODE */
  ZX_OUT_CLOSE_TAG(p, "</cdm:USERID>");
  zx_pop_seen(pop_seen);
#else
  /* root node has no end tag either */
#endif
  ENC_LEN_DEBUG(x, "cdm:USERID", p-enc_base);
  return p;
}

/* FUNC(zx_ENC_WO_cdm_USERID) */

/* Render element into string. The XML attributes and elements are
 * processed in wire order by chasing wo pointers. This is what you want for
 * validating signatures on other people's XML documents. */

/* Called by: */
char* zx_ENC_WO_cdm_USERID(struct zx_ctx* c, struct zx_cdm_USERID_s* x, char* p )
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
  ZX_OUT_MEM(p, "USERID", sizeof("USERID")-1);
  qq = p;

  /* *** sort the namespaces */
  if (c->inc_ns)
    zx_add_inc_ns(c, &pop_seen);
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
  zx_add_xmlns_if_not_seen(c, x->gg.g.ns, &pop_seen);

  p = zx_enc_seen(p, pop_seen); 
  p = zx_attr_wo_enc(p, x->ACC, "ACC=\"", sizeof("ACC=\"")-1);
  p = zx_attr_wo_enc(p, x->ACCTime, "ACCTime=\"", sizeof("ACCTime=\"")-1);
  p = zx_attr_wo_enc(p, x->id, "id=\"", sizeof("id=\"")-1);
  p = zx_attr_wo_enc(p, x->modificationTime, "modificationTime=\"", sizeof("modificationTime=\"")-1);
  p = zx_attr_wo_enc(p, x->modifier, "modifier=\"", sizeof("modifier=\"")-1);

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
  ENC_LEN_DEBUG(x, "cdm:USERID", p-enc_base);
  return p;
}

/* FUNC(zx_EASY_ENC_SO_cdm_USERID) */

/* Called by: */
struct zx_str* zx_EASY_ENC_SO_cdm_USERID(struct zx_ctx* c, struct zx_cdm_USERID_s* x )
{
  int len;
  char* buf;
  c->ns_tab = ZX_ALLOC(c, sizeof(zx_ns_tab));
  memcpy(c->ns_tab, zx_ns_tab, sizeof(zx_ns_tab));
  len = zx_LEN_SO_cdm_USERID(c, x );
  buf = ZX_ALLOC(c, len+1);
  return zx_easy_enc_common(c, zx_ENC_SO_cdm_USERID(c, x, buf ), buf, len);
}

/* FUNC(zx_EASY_ENC_WO_cdm_USERID) */

/* Called by: */
struct zx_str* zx_EASY_ENC_WO_cdm_USERID(struct zx_ctx* c, struct zx_cdm_USERID_s* x )
{
  int len;
  char* buf;
  c->ns_tab = ZX_ALLOC(c, sizeof(zx_ns_tab));
  memcpy(c->ns_tab, zx_ns_tab, sizeof(zx_ns_tab));
  len = zx_LEN_WO_cdm_USERID(c, x );
  buf = ZX_ALLOC(c, len+1);
  return zx_easy_enc_common(c, zx_ENC_WO_cdm_USERID(c, x, buf ), buf, len);
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

#define EL_NAME   cdm_VERSION
#define EL_STRUCT zx_cdm_VERSION_s
#define EL_NS     cdm
#define EL_TAG    VERSION

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

/* FUNC(zx_LEN_SO_cdm_VERSION) */

/* Compute length of an element (and its subelements). The XML attributes
 * and elements are processed in schema order. */

/* Called by: */
int zx_LEN_SO_cdm_VERSION(struct zx_ctx* c, struct zx_cdm_VERSION_s* x )
{
  struct zx_ns_s* pop_seen = 0;
  struct zx_elem_s* se MAYBE_UNUSED;
#if 1 /* NORMALMODE */
  /* *** in simple_elem case should output ns prefix from ns node. */
  int len = sizeof("<cdm:VERSION")-1 + 1 + sizeof("</cdm:VERSION>")-1;
  if (c->inc_ns_len)
    len += zx_len_inc_ns(c, &pop_seen);
  if (x->ACC || x->ACCTime || x->id || x->modificationTime || x->modifier)
    len += zx_len_xmlns_if_not_seen(c, zx_ns_tab+zx_xmlns_ix_cb, &pop_seen);
  len += zx_len_xmlns_if_not_seen(c, zx_ns_tab+zx_xmlns_ix_cdm, &pop_seen);

  len += zx_attr_so_len(x->ACC, sizeof("cb:ACC")-1);
  len += zx_attr_so_len(x->ACCTime, sizeof("cb:ACCTime")-1);
  len += zx_attr_so_len(x->id, sizeof("cb:id")-1);
  len += zx_attr_so_len(x->modificationTime, sizeof("cb:modificationTime")-1);
  len += zx_attr_so_len(x->modifier, sizeof("cb:modifier")-1);

#else
  /* root node has no begin tag */
  int len = 0;
#endif
  


  len += zx_len_so_common(c, &x->gg);
  zx_pop_seen(pop_seen);
  ENC_LEN_DEBUG(x, "cdm:VERSION", len);
  return len;
}

/* FUNC(zx_LEN_WO_cdm_VERSION) */

/* Compute length of an element (and its subelements). The XML attributes
 * and elements are processed in wire order and no assumptions
 * are made about namespace prefixes. */

/* Called by: */
int zx_LEN_WO_cdm_VERSION(struct zx_ctx* c, struct zx_cdm_VERSION_s* x )
{
  struct zx_ns_s* pop_seen = 0;
  struct zx_elem_s* se MAYBE_UNUSED;
#if 1 /* NORMALMODE */
  int len = 1 + sizeof("VERSION")-1 + 1 + 2 + sizeof("VERSION")-1 + 1;
  
  if (x->gg.g.ns && x->gg.g.ns->prefix_len)
    len += (x->gg.g.ns->prefix_len + 1) * 2;
  if (c->inc_ns_len)
    len += zx_len_inc_ns(c, &pop_seen);
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
  len += zx_len_xmlns_if_not_seen(c, x->gg.g.ns, &pop_seen);

  len += zx_attr_wo_len(x->ACC, sizeof("ACC")-1);
  len += zx_attr_wo_len(x->ACCTime, sizeof("ACCTime")-1);
  len += zx_attr_wo_len(x->id, sizeof("id")-1);
  len += zx_attr_wo_len(x->modificationTime, sizeof("modificationTime")-1);
  len += zx_attr_wo_len(x->modifier, sizeof("modifier")-1);

#else
  /* root node has no begin tag */
  int len = 0;
#endif
  


  len += zx_len_wo_common(c, &x->gg); 
  zx_pop_seen(pop_seen);
  ENC_LEN_DEBUG(x, "cdm:VERSION", len);
  return len;
}

/* FUNC(zx_ENC_SO_cdm_VERSION) */

/* Render element into string. The XML attributes and elements are
 * processed in schema order. This is what you generally want for
 * rendering new data structure to a string. The wo pointers are not used. */

/* Called by: */
char* zx_ENC_SO_cdm_VERSION(struct zx_ctx* c, struct zx_cdm_VERSION_s* x, char* p )
{
  struct zx_elem_s* se MAYBE_UNUSED;
  struct zx_ns_s* pop_seen = 0;
  ENC_LEN_DEBUG_BASE;
#if 1 /* NORMALMODE */
  /* *** in simple_elem case should output ns prefix from ns node. */
  ZX_OUT_TAG(p, "<cdm:VERSION");
  if (c->inc_ns)
    p = zx_enc_inc_ns(c, p, &pop_seen);
  if (x->ACC || x->ACCTime || x->id || x->modificationTime || x->modifier)
    p = zx_enc_xmlns_if_not_seen(c, p, zx_ns_tab+zx_xmlns_ix_cb, &pop_seen);
  p = zx_enc_xmlns_if_not_seen(c, p, zx_ns_tab+zx_xmlns_ix_cdm, &pop_seen);

  p = zx_attr_so_enc(p, x->ACC, " cb:ACC=\"", sizeof(" cb:ACC=\"")-1);
  p = zx_attr_so_enc(p, x->ACCTime, " cb:ACCTime=\"", sizeof(" cb:ACCTime=\"")-1);
  p = zx_attr_so_enc(p, x->id, " cb:id=\"", sizeof(" cb:id=\"")-1);
  p = zx_attr_so_enc(p, x->modificationTime, " cb:modificationTime=\"", sizeof(" cb:modificationTime=\"")-1);
  p = zx_attr_so_enc(p, x->modifier, " cb:modifier=\"", sizeof(" cb:modifier=\"")-1);

  p = zx_enc_unknown_attrs(p, x->gg.any_attr);
#else
  /* root node has no begin tag */
#endif
  

  p = zx_enc_so_unknown_elems_and_content(c, p, &x->gg);
  
#if 1 /* NORMALMODE */
  ZX_OUT_CLOSE_TAG(p, "</cdm:VERSION>");
  zx_pop_seen(pop_seen);
#else
  /* root node has no end tag either */
#endif
  ENC_LEN_DEBUG(x, "cdm:VERSION", p-enc_base);
  return p;
}

/* FUNC(zx_ENC_WO_cdm_VERSION) */

/* Render element into string. The XML attributes and elements are
 * processed in wire order by chasing wo pointers. This is what you want for
 * validating signatures on other people's XML documents. */

/* Called by: */
char* zx_ENC_WO_cdm_VERSION(struct zx_ctx* c, struct zx_cdm_VERSION_s* x, char* p )
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
  ZX_OUT_MEM(p, "VERSION", sizeof("VERSION")-1);
  qq = p;

  /* *** sort the namespaces */
  if (c->inc_ns)
    zx_add_inc_ns(c, &pop_seen);
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
  zx_add_xmlns_if_not_seen(c, x->gg.g.ns, &pop_seen);

  p = zx_enc_seen(p, pop_seen); 
  p = zx_attr_wo_enc(p, x->ACC, "ACC=\"", sizeof("ACC=\"")-1);
  p = zx_attr_wo_enc(p, x->ACCTime, "ACCTime=\"", sizeof("ACCTime=\"")-1);
  p = zx_attr_wo_enc(p, x->id, "id=\"", sizeof("id=\"")-1);
  p = zx_attr_wo_enc(p, x->modificationTime, "modificationTime=\"", sizeof("modificationTime=\"")-1);
  p = zx_attr_wo_enc(p, x->modifier, "modifier=\"", sizeof("modifier=\"")-1);

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
  ENC_LEN_DEBUG(x, "cdm:VERSION", p-enc_base);
  return p;
}

/* FUNC(zx_EASY_ENC_SO_cdm_VERSION) */

/* Called by: */
struct zx_str* zx_EASY_ENC_SO_cdm_VERSION(struct zx_ctx* c, struct zx_cdm_VERSION_s* x )
{
  int len;
  char* buf;
  c->ns_tab = ZX_ALLOC(c, sizeof(zx_ns_tab));
  memcpy(c->ns_tab, zx_ns_tab, sizeof(zx_ns_tab));
  len = zx_LEN_SO_cdm_VERSION(c, x );
  buf = ZX_ALLOC(c, len+1);
  return zx_easy_enc_common(c, zx_ENC_SO_cdm_VERSION(c, x, buf ), buf, len);
}

/* FUNC(zx_EASY_ENC_WO_cdm_VERSION) */

/* Called by: */
struct zx_str* zx_EASY_ENC_WO_cdm_VERSION(struct zx_ctx* c, struct zx_cdm_VERSION_s* x )
{
  int len;
  char* buf;
  c->ns_tab = ZX_ALLOC(c, sizeof(zx_ns_tab));
  memcpy(c->ns_tab, zx_ns_tab, sizeof(zx_ns_tab));
  len = zx_LEN_WO_cdm_VERSION(c, x );
  buf = ZX_ALLOC(c, len+1);
  return zx_easy_enc_common(c, zx_ENC_WO_cdm_VERSION(c, x, buf ), buf, len);
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

#define EL_NAME   cdm_vCard
#define EL_STRUCT zx_cdm_vCard_s
#define EL_NS     cdm
#define EL_TAG    vCard

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

/* FUNC(zx_LEN_SO_cdm_vCard) */

/* Compute length of an element (and its subelements). The XML attributes
 * and elements are processed in schema order. */

/* Called by: */
int zx_LEN_SO_cdm_vCard(struct zx_ctx* c, struct zx_cdm_vCard_s* x )
{
  struct zx_ns_s* pop_seen = 0;
  struct zx_elem_s* se MAYBE_UNUSED;
#if 1 /* NORMALMODE */
  /* *** in simple_elem case should output ns prefix from ns node. */
  int len = sizeof("<cdm:vCard")-1 + 1 + sizeof("</cdm:vCard>")-1;
  if (c->inc_ns_len)
    len += zx_len_inc_ns(c, &pop_seen);
  if (x->id || x->modificationTime)
    len += zx_len_xmlns_if_not_seen(c, zx_ns_tab+zx_xmlns_ix_cb, &pop_seen);
  len += zx_len_xmlns_if_not_seen(c, zx_ns_tab+zx_xmlns_ix_cdm, &pop_seen);

  len += zx_attr_so_len(x->id, sizeof("cb:id")-1);
  len += zx_attr_so_len(x->modificationTime, sizeof("cb:modificationTime")-1);

#else
  /* root node has no begin tag */
  int len = 0;
#endif
  
  {
      struct zx_cdm_VERSION_s* e;
      for (e = x->VERSION_is_Perl_MakeMaker_gobbled; e; e = (struct zx_cdm_VERSION_s*)e->gg.g.n)
	  len += zx_LEN_SO_cdm_VERSION(c, e);
  }
  for (se = x->CARDID; se; se = (struct zx_elem_s*)se->g.n)
    len += zx_LEN_SO_simple_elem(c,se, sizeof("cdm:CARDID")-1, zx_ns_tab+zx_xmlns_ix_cdm);
  for (se = x->DISTRIBUTIONLIST; se; se = (struct zx_elem_s*)se->g.n)
    len += zx_LEN_SO_simple_elem(c,se, sizeof("cdm:DISTRIBUTIONLIST")-1, zx_ns_tab+zx_xmlns_ix_cdm);
  for (se = x->SELF; se; se = (struct zx_elem_s*)se->g.n)
    len += zx_LEN_SO_simple_elem(c,se, sizeof("cdm:SELF")-1, zx_ns_tab+zx_xmlns_ix_cdm);
  for (se = x->FAVORITE; se; se = (struct zx_elem_s*)se->g.n)
    len += zx_LEN_SO_simple_elem(c,se, sizeof("cdm:FAVORITE")-1, zx_ns_tab+zx_xmlns_ix_cdm);
  {
      struct zx_cdm_FN_s* e;
      for (e = x->FN; e; e = (struct zx_cdm_FN_s*)e->gg.g.n)
	  len += zx_LEN_SO_cdm_FN(c, e);
  }
  {
      struct zx_cdm_N_s* e;
      for (e = x->N; e; e = (struct zx_cdm_N_s*)e->gg.g.n)
	  len += zx_LEN_SO_cdm_N(c, e);
  }
  {
      struct zx_cdm_LISTMEMBER_s* e;
      for (e = x->LISTMEMBER; e; e = (struct zx_cdm_LISTMEMBER_s*)e->gg.g.n)
	  len += zx_LEN_SO_cdm_LISTMEMBER(c, e);
  }
  {
      struct zx_cdm_NICKNAME_s* e;
      for (e = x->NICKNAME; e; e = (struct zx_cdm_NICKNAME_s*)e->gg.g.n)
	  len += zx_LEN_SO_cdm_NICKNAME(c, e);
  }
  {
      struct zx_cdm_PHOTO_s* e;
      for (e = x->PHOTO; e; e = (struct zx_cdm_PHOTO_s*)e->gg.g.n)
	  len += zx_LEN_SO_cdm_PHOTO(c, e);
  }
  {
      struct zx_cdm_BDAY_s* e;
      for (e = x->BDAY; e; e = (struct zx_cdm_BDAY_s*)e->gg.g.n)
	  len += zx_LEN_SO_cdm_BDAY(c, e);
  }
  {
      struct zx_cdm_ADR_s* e;
      for (e = x->ADR; e; e = (struct zx_cdm_ADR_s*)e->gg.g.n)
	  len += zx_LEN_SO_cdm_ADR(c, e);
  }
  {
      struct zx_cdm_LABEL_s* e;
      for (e = x->LABEL; e; e = (struct zx_cdm_LABEL_s*)e->gg.g.n)
	  len += zx_LEN_SO_cdm_LABEL(c, e);
  }
  {
      struct zx_cdm_TEL_s* e;
      for (e = x->TEL; e; e = (struct zx_cdm_TEL_s*)e->gg.g.n)
	  len += zx_LEN_SO_cdm_TEL(c, e);
  }
  {
      struct zx_cdm_EMAIL_s* e;
      for (e = x->EMAIL; e; e = (struct zx_cdm_EMAIL_s*)e->gg.g.n)
	  len += zx_LEN_SO_cdm_EMAIL(c, e);
  }
  {
      struct zx_cdm_JABBERID_s* e;
      for (e = x->JABBERID; e; e = (struct zx_cdm_JABBERID_s*)e->gg.g.n)
	  len += zx_LEN_SO_cdm_JABBERID(c, e);
  }
  {
      struct zx_cdm_MAILER_s* e;
      for (e = x->MAILER; e; e = (struct zx_cdm_MAILER_s*)e->gg.g.n)
	  len += zx_LEN_SO_cdm_MAILER(c, e);
  }
  {
      struct zx_cdm_TZ_s* e;
      for (e = x->TZ; e; e = (struct zx_cdm_TZ_s*)e->gg.g.n)
	  len += zx_LEN_SO_cdm_TZ(c, e);
  }
  {
      struct zx_cdm_GEO_s* e;
      for (e = x->GEO; e; e = (struct zx_cdm_GEO_s*)e->gg.g.n)
	  len += zx_LEN_SO_cdm_GEO(c, e);
  }
  {
      struct zx_cdm_TITLE_s* e;
      for (e = x->TITLE; e; e = (struct zx_cdm_TITLE_s*)e->gg.g.n)
	  len += zx_LEN_SO_cdm_TITLE(c, e);
  }
  {
      struct zx_cdm_ROLE_s* e;
      for (e = x->ROLE; e; e = (struct zx_cdm_ROLE_s*)e->gg.g.n)
	  len += zx_LEN_SO_cdm_ROLE(c, e);
  }
  {
      struct zx_cdm_LOGO_s* e;
      for (e = x->LOGO; e; e = (struct zx_cdm_LOGO_s*)e->gg.g.n)
	  len += zx_LEN_SO_cdm_LOGO(c, e);
  }
  {
      struct zx_cdm_AGENT_s* e;
      for (e = x->AGENT; e; e = (struct zx_cdm_AGENT_s*)e->gg.g.n)
	  len += zx_LEN_SO_cdm_AGENT(c, e);
  }
  {
      struct zx_cdm_ORG_s* e;
      for (e = x->ORG; e; e = (struct zx_cdm_ORG_s*)e->gg.g.n)
	  len += zx_LEN_SO_cdm_ORG(c, e);
  }
  {
      struct zx_cdm_CATEGORIES_s* e;
      for (e = x->CATEGORIES; e; e = (struct zx_cdm_CATEGORIES_s*)e->gg.g.n)
	  len += zx_LEN_SO_cdm_CATEGORIES(c, e);
  }
  {
      struct zx_cdm_NOTE_s* e;
      for (e = x->NOTE; e; e = (struct zx_cdm_NOTE_s*)e->gg.g.n)
	  len += zx_LEN_SO_cdm_NOTE(c, e);
  }
  {
      struct zx_cdm_PRODID_s* e;
      for (e = x->PRODID; e; e = (struct zx_cdm_PRODID_s*)e->gg.g.n)
	  len += zx_LEN_SO_cdm_PRODID(c, e);
  }
  {
      struct zx_cdm_REV_s* e;
      for (e = x->REV; e; e = (struct zx_cdm_REV_s*)e->gg.g.n)
	  len += zx_LEN_SO_cdm_REV(c, e);
  }
  {
      struct zx_cdm_SORT_STRING_s* e;
      for (e = x->SORT_STRING; e; e = (struct zx_cdm_SORT_STRING_s*)e->gg.g.n)
	  len += zx_LEN_SO_cdm_SORT_STRING(c, e);
  }
  {
      struct zx_cdm_SOUND_s* e;
      for (e = x->SOUND; e; e = (struct zx_cdm_SOUND_s*)e->gg.g.n)
	  len += zx_LEN_SO_cdm_SOUND(c, e);
  }
  {
      struct zx_cdm_UID_s* e;
      for (e = x->UID; e; e = (struct zx_cdm_UID_s*)e->gg.g.n)
	  len += zx_LEN_SO_cdm_UID(c, e);
  }
  {
      struct zx_cdm_URL_s* e;
      for (e = x->URL; e; e = (struct zx_cdm_URL_s*)e->gg.g.n)
	  len += zx_LEN_SO_cdm_URL(c, e);
  }
  {
      struct zx_cdm_CLASS_s* e;
      for (e = x->CLASS; e; e = (struct zx_cdm_CLASS_s*)e->gg.g.n)
	  len += zx_LEN_SO_cdm_CLASS(c, e);
  }
  {
      struct zx_cdm_KEY_s* e;
      for (e = x->KEY; e; e = (struct zx_cdm_KEY_s*)e->gg.g.n)
	  len += zx_LEN_SO_cdm_KEY(c, e);
  }
  {
      struct zx_cdm_DESC_s* e;
      for (e = x->DESC; e; e = (struct zx_cdm_DESC_s*)e->gg.g.n)
	  len += zx_LEN_SO_cdm_DESC(c, e);
  }
  {
      struct zx_cdm_PHYSICALACCESS_s* e;
      for (e = x->PHYSICALACCESS; e; e = (struct zx_cdm_PHYSICALACCESS_s*)e->gg.g.n)
	  len += zx_LEN_SO_cdm_PHYSICALACCESS(c, e);
  }
  {
      struct zx_cdm_CALURI_s* e;
      for (e = x->CALURI; e; e = (struct zx_cdm_CALURI_s*)e->gg.g.n)
	  len += zx_LEN_SO_cdm_CALURI(c, e);
  }
  {
      struct zx_cdm_CAPURI_s* e;
      for (e = x->CAPURI; e; e = (struct zx_cdm_CAPURI_s*)e->gg.g.n)
	  len += zx_LEN_SO_cdm_CAPURI(c, e);
  }
  {
      struct zx_cdm_CALADRURI_s* e;
      for (e = x->CALADRURI; e; e = (struct zx_cdm_CALADRURI_s*)e->gg.g.n)
	  len += zx_LEN_SO_cdm_CALADRURI(c, e);
  }
  {
      struct zx_cdm_FBURL_s* e;
      for (e = x->FBURL; e; e = (struct zx_cdm_FBURL_s*)e->gg.g.n)
	  len += zx_LEN_SO_cdm_FBURL(c, e);
  }
  {
      struct zx_cb_Extension_s* e;
      for (e = x->Extension; e; e = (struct zx_cb_Extension_s*)e->gg.g.n)
	  len += zx_LEN_SO_cb_Extension(c, e);
  }


  len += zx_len_so_common(c, &x->gg);
  zx_pop_seen(pop_seen);
  ENC_LEN_DEBUG(x, "cdm:vCard", len);
  return len;
}

/* FUNC(zx_LEN_WO_cdm_vCard) */

/* Compute length of an element (and its subelements). The XML attributes
 * and elements are processed in wire order and no assumptions
 * are made about namespace prefixes. */

/* Called by: */
int zx_LEN_WO_cdm_vCard(struct zx_ctx* c, struct zx_cdm_vCard_s* x )
{
  struct zx_ns_s* pop_seen = 0;
  struct zx_elem_s* se MAYBE_UNUSED;
#if 1 /* NORMALMODE */
  int len = 1 + sizeof("vCard")-1 + 1 + 2 + sizeof("vCard")-1 + 1;
  
  if (x->gg.g.ns && x->gg.g.ns->prefix_len)
    len += (x->gg.g.ns->prefix_len + 1) * 2;
  if (c->inc_ns_len)
    len += zx_len_inc_ns(c, &pop_seen);
  if (x->id)
    len += zx_len_xmlns_if_not_seen(c, x->id->g.ns, &pop_seen);
  if (x->modificationTime)
    len += zx_len_xmlns_if_not_seen(c, x->modificationTime->g.ns, &pop_seen);
  len += zx_len_xmlns_if_not_seen(c, x->gg.g.ns, &pop_seen);

  len += zx_attr_wo_len(x->id, sizeof("id")-1);
  len += zx_attr_wo_len(x->modificationTime, sizeof("modificationTime")-1);

#else
  /* root node has no begin tag */
  int len = 0;
#endif
  
  {
      struct zx_cdm_VERSION_s* e;
      for (e = x->VERSION_is_Perl_MakeMaker_gobbled; e; e = (struct zx_cdm_VERSION_s*)e->gg.g.n)
	  len += zx_LEN_WO_cdm_VERSION(c, e);
  }
  for (se = x->CARDID; se; se = (struct zx_elem_s*)se->g.n)
    len += zx_LEN_WO_simple_elem(c, se, sizeof("CARDID")-1);
  for (se = x->DISTRIBUTIONLIST; se; se = (struct zx_elem_s*)se->g.n)
    len += zx_LEN_WO_simple_elem(c, se, sizeof("DISTRIBUTIONLIST")-1);
  for (se = x->SELF; se; se = (struct zx_elem_s*)se->g.n)
    len += zx_LEN_WO_simple_elem(c, se, sizeof("SELF")-1);
  for (se = x->FAVORITE; se; se = (struct zx_elem_s*)se->g.n)
    len += zx_LEN_WO_simple_elem(c, se, sizeof("FAVORITE")-1);
  {
      struct zx_cdm_FN_s* e;
      for (e = x->FN; e; e = (struct zx_cdm_FN_s*)e->gg.g.n)
	  len += zx_LEN_WO_cdm_FN(c, e);
  }
  {
      struct zx_cdm_N_s* e;
      for (e = x->N; e; e = (struct zx_cdm_N_s*)e->gg.g.n)
	  len += zx_LEN_WO_cdm_N(c, e);
  }
  {
      struct zx_cdm_LISTMEMBER_s* e;
      for (e = x->LISTMEMBER; e; e = (struct zx_cdm_LISTMEMBER_s*)e->gg.g.n)
	  len += zx_LEN_WO_cdm_LISTMEMBER(c, e);
  }
  {
      struct zx_cdm_NICKNAME_s* e;
      for (e = x->NICKNAME; e; e = (struct zx_cdm_NICKNAME_s*)e->gg.g.n)
	  len += zx_LEN_WO_cdm_NICKNAME(c, e);
  }
  {
      struct zx_cdm_PHOTO_s* e;
      for (e = x->PHOTO; e; e = (struct zx_cdm_PHOTO_s*)e->gg.g.n)
	  len += zx_LEN_WO_cdm_PHOTO(c, e);
  }
  {
      struct zx_cdm_BDAY_s* e;
      for (e = x->BDAY; e; e = (struct zx_cdm_BDAY_s*)e->gg.g.n)
	  len += zx_LEN_WO_cdm_BDAY(c, e);
  }
  {
      struct zx_cdm_ADR_s* e;
      for (e = x->ADR; e; e = (struct zx_cdm_ADR_s*)e->gg.g.n)
	  len += zx_LEN_WO_cdm_ADR(c, e);
  }
  {
      struct zx_cdm_LABEL_s* e;
      for (e = x->LABEL; e; e = (struct zx_cdm_LABEL_s*)e->gg.g.n)
	  len += zx_LEN_WO_cdm_LABEL(c, e);
  }
  {
      struct zx_cdm_TEL_s* e;
      for (e = x->TEL; e; e = (struct zx_cdm_TEL_s*)e->gg.g.n)
	  len += zx_LEN_WO_cdm_TEL(c, e);
  }
  {
      struct zx_cdm_EMAIL_s* e;
      for (e = x->EMAIL; e; e = (struct zx_cdm_EMAIL_s*)e->gg.g.n)
	  len += zx_LEN_WO_cdm_EMAIL(c, e);
  }
  {
      struct zx_cdm_JABBERID_s* e;
      for (e = x->JABBERID; e; e = (struct zx_cdm_JABBERID_s*)e->gg.g.n)
	  len += zx_LEN_WO_cdm_JABBERID(c, e);
  }
  {
      struct zx_cdm_MAILER_s* e;
      for (e = x->MAILER; e; e = (struct zx_cdm_MAILER_s*)e->gg.g.n)
	  len += zx_LEN_WO_cdm_MAILER(c, e);
  }
  {
      struct zx_cdm_TZ_s* e;
      for (e = x->TZ; e; e = (struct zx_cdm_TZ_s*)e->gg.g.n)
	  len += zx_LEN_WO_cdm_TZ(c, e);
  }
  {
      struct zx_cdm_GEO_s* e;
      for (e = x->GEO; e; e = (struct zx_cdm_GEO_s*)e->gg.g.n)
	  len += zx_LEN_WO_cdm_GEO(c, e);
  }
  {
      struct zx_cdm_TITLE_s* e;
      for (e = x->TITLE; e; e = (struct zx_cdm_TITLE_s*)e->gg.g.n)
	  len += zx_LEN_WO_cdm_TITLE(c, e);
  }
  {
      struct zx_cdm_ROLE_s* e;
      for (e = x->ROLE; e; e = (struct zx_cdm_ROLE_s*)e->gg.g.n)
	  len += zx_LEN_WO_cdm_ROLE(c, e);
  }
  {
      struct zx_cdm_LOGO_s* e;
      for (e = x->LOGO; e; e = (struct zx_cdm_LOGO_s*)e->gg.g.n)
	  len += zx_LEN_WO_cdm_LOGO(c, e);
  }
  {
      struct zx_cdm_AGENT_s* e;
      for (e = x->AGENT; e; e = (struct zx_cdm_AGENT_s*)e->gg.g.n)
	  len += zx_LEN_WO_cdm_AGENT(c, e);
  }
  {
      struct zx_cdm_ORG_s* e;
      for (e = x->ORG; e; e = (struct zx_cdm_ORG_s*)e->gg.g.n)
	  len += zx_LEN_WO_cdm_ORG(c, e);
  }
  {
      struct zx_cdm_CATEGORIES_s* e;
      for (e = x->CATEGORIES; e; e = (struct zx_cdm_CATEGORIES_s*)e->gg.g.n)
	  len += zx_LEN_WO_cdm_CATEGORIES(c, e);
  }
  {
      struct zx_cdm_NOTE_s* e;
      for (e = x->NOTE; e; e = (struct zx_cdm_NOTE_s*)e->gg.g.n)
	  len += zx_LEN_WO_cdm_NOTE(c, e);
  }
  {
      struct zx_cdm_PRODID_s* e;
      for (e = x->PRODID; e; e = (struct zx_cdm_PRODID_s*)e->gg.g.n)
	  len += zx_LEN_WO_cdm_PRODID(c, e);
  }
  {
      struct zx_cdm_REV_s* e;
      for (e = x->REV; e; e = (struct zx_cdm_REV_s*)e->gg.g.n)
	  len += zx_LEN_WO_cdm_REV(c, e);
  }
  {
      struct zx_cdm_SORT_STRING_s* e;
      for (e = x->SORT_STRING; e; e = (struct zx_cdm_SORT_STRING_s*)e->gg.g.n)
	  len += zx_LEN_WO_cdm_SORT_STRING(c, e);
  }
  {
      struct zx_cdm_SOUND_s* e;
      for (e = x->SOUND; e; e = (struct zx_cdm_SOUND_s*)e->gg.g.n)
	  len += zx_LEN_WO_cdm_SOUND(c, e);
  }
  {
      struct zx_cdm_UID_s* e;
      for (e = x->UID; e; e = (struct zx_cdm_UID_s*)e->gg.g.n)
	  len += zx_LEN_WO_cdm_UID(c, e);
  }
  {
      struct zx_cdm_URL_s* e;
      for (e = x->URL; e; e = (struct zx_cdm_URL_s*)e->gg.g.n)
	  len += zx_LEN_WO_cdm_URL(c, e);
  }
  {
      struct zx_cdm_CLASS_s* e;
      for (e = x->CLASS; e; e = (struct zx_cdm_CLASS_s*)e->gg.g.n)
	  len += zx_LEN_WO_cdm_CLASS(c, e);
  }
  {
      struct zx_cdm_KEY_s* e;
      for (e = x->KEY; e; e = (struct zx_cdm_KEY_s*)e->gg.g.n)
	  len += zx_LEN_WO_cdm_KEY(c, e);
  }
  {
      struct zx_cdm_DESC_s* e;
      for (e = x->DESC; e; e = (struct zx_cdm_DESC_s*)e->gg.g.n)
	  len += zx_LEN_WO_cdm_DESC(c, e);
  }
  {
      struct zx_cdm_PHYSICALACCESS_s* e;
      for (e = x->PHYSICALACCESS; e; e = (struct zx_cdm_PHYSICALACCESS_s*)e->gg.g.n)
	  len += zx_LEN_WO_cdm_PHYSICALACCESS(c, e);
  }
  {
      struct zx_cdm_CALURI_s* e;
      for (e = x->CALURI; e; e = (struct zx_cdm_CALURI_s*)e->gg.g.n)
	  len += zx_LEN_WO_cdm_CALURI(c, e);
  }
  {
      struct zx_cdm_CAPURI_s* e;
      for (e = x->CAPURI; e; e = (struct zx_cdm_CAPURI_s*)e->gg.g.n)
	  len += zx_LEN_WO_cdm_CAPURI(c, e);
  }
  {
      struct zx_cdm_CALADRURI_s* e;
      for (e = x->CALADRURI; e; e = (struct zx_cdm_CALADRURI_s*)e->gg.g.n)
	  len += zx_LEN_WO_cdm_CALADRURI(c, e);
  }
  {
      struct zx_cdm_FBURL_s* e;
      for (e = x->FBURL; e; e = (struct zx_cdm_FBURL_s*)e->gg.g.n)
	  len += zx_LEN_WO_cdm_FBURL(c, e);
  }
  {
      struct zx_cb_Extension_s* e;
      for (e = x->Extension; e; e = (struct zx_cb_Extension_s*)e->gg.g.n)
	  len += zx_LEN_WO_cb_Extension(c, e);
  }


  len += zx_len_wo_common(c, &x->gg); 
  zx_pop_seen(pop_seen);
  ENC_LEN_DEBUG(x, "cdm:vCard", len);
  return len;
}

/* FUNC(zx_ENC_SO_cdm_vCard) */

/* Render element into string. The XML attributes and elements are
 * processed in schema order. This is what you generally want for
 * rendering new data structure to a string. The wo pointers are not used. */

/* Called by: */
char* zx_ENC_SO_cdm_vCard(struct zx_ctx* c, struct zx_cdm_vCard_s* x, char* p )
{
  struct zx_elem_s* se MAYBE_UNUSED;
  struct zx_ns_s* pop_seen = 0;
  ENC_LEN_DEBUG_BASE;
#if 1 /* NORMALMODE */
  /* *** in simple_elem case should output ns prefix from ns node. */
  ZX_OUT_TAG(p, "<cdm:vCard");
  if (c->inc_ns)
    p = zx_enc_inc_ns(c, p, &pop_seen);
  if (x->id || x->modificationTime)
    p = zx_enc_xmlns_if_not_seen(c, p, zx_ns_tab+zx_xmlns_ix_cb, &pop_seen);
  p = zx_enc_xmlns_if_not_seen(c, p, zx_ns_tab+zx_xmlns_ix_cdm, &pop_seen);

  p = zx_attr_so_enc(p, x->id, " cb:id=\"", sizeof(" cb:id=\"")-1);
  p = zx_attr_so_enc(p, x->modificationTime, " cb:modificationTime=\"", sizeof(" cb:modificationTime=\"")-1);

  p = zx_enc_unknown_attrs(p, x->gg.any_attr);
#else
  /* root node has no begin tag */
#endif
  
  {
      struct zx_cdm_VERSION_s* e;
      for (e = x->VERSION_is_Perl_MakeMaker_gobbled; e; e = (struct zx_cdm_VERSION_s*)e->gg.g.n)
	  p = zx_ENC_SO_cdm_VERSION(c, e, p);
  }
  for (se = x->CARDID; se; se = (struct zx_elem_s*)se->g.n)
    p = zx_ENC_SO_simple_elem(c, se, p, "cdm:CARDID", sizeof("cdm:CARDID")-1, zx_ns_tab+zx_xmlns_ix_cdm);
  for (se = x->DISTRIBUTIONLIST; se; se = (struct zx_elem_s*)se->g.n)
    p = zx_ENC_SO_simple_elem(c, se, p, "cdm:DISTRIBUTIONLIST", sizeof("cdm:DISTRIBUTIONLIST")-1, zx_ns_tab+zx_xmlns_ix_cdm);
  for (se = x->SELF; se; se = (struct zx_elem_s*)se->g.n)
    p = zx_ENC_SO_simple_elem(c, se, p, "cdm:SELF", sizeof("cdm:SELF")-1, zx_ns_tab+zx_xmlns_ix_cdm);
  for (se = x->FAVORITE; se; se = (struct zx_elem_s*)se->g.n)
    p = zx_ENC_SO_simple_elem(c, se, p, "cdm:FAVORITE", sizeof("cdm:FAVORITE")-1, zx_ns_tab+zx_xmlns_ix_cdm);
  {
      struct zx_cdm_FN_s* e;
      for (e = x->FN; e; e = (struct zx_cdm_FN_s*)e->gg.g.n)
	  p = zx_ENC_SO_cdm_FN(c, e, p);
  }
  {
      struct zx_cdm_N_s* e;
      for (e = x->N; e; e = (struct zx_cdm_N_s*)e->gg.g.n)
	  p = zx_ENC_SO_cdm_N(c, e, p);
  }
  {
      struct zx_cdm_LISTMEMBER_s* e;
      for (e = x->LISTMEMBER; e; e = (struct zx_cdm_LISTMEMBER_s*)e->gg.g.n)
	  p = zx_ENC_SO_cdm_LISTMEMBER(c, e, p);
  }
  {
      struct zx_cdm_NICKNAME_s* e;
      for (e = x->NICKNAME; e; e = (struct zx_cdm_NICKNAME_s*)e->gg.g.n)
	  p = zx_ENC_SO_cdm_NICKNAME(c, e, p);
  }
  {
      struct zx_cdm_PHOTO_s* e;
      for (e = x->PHOTO; e; e = (struct zx_cdm_PHOTO_s*)e->gg.g.n)
	  p = zx_ENC_SO_cdm_PHOTO(c, e, p);
  }
  {
      struct zx_cdm_BDAY_s* e;
      for (e = x->BDAY; e; e = (struct zx_cdm_BDAY_s*)e->gg.g.n)
	  p = zx_ENC_SO_cdm_BDAY(c, e, p);
  }
  {
      struct zx_cdm_ADR_s* e;
      for (e = x->ADR; e; e = (struct zx_cdm_ADR_s*)e->gg.g.n)
	  p = zx_ENC_SO_cdm_ADR(c, e, p);
  }
  {
      struct zx_cdm_LABEL_s* e;
      for (e = x->LABEL; e; e = (struct zx_cdm_LABEL_s*)e->gg.g.n)
	  p = zx_ENC_SO_cdm_LABEL(c, e, p);
  }
  {
      struct zx_cdm_TEL_s* e;
      for (e = x->TEL; e; e = (struct zx_cdm_TEL_s*)e->gg.g.n)
	  p = zx_ENC_SO_cdm_TEL(c, e, p);
  }
  {
      struct zx_cdm_EMAIL_s* e;
      for (e = x->EMAIL; e; e = (struct zx_cdm_EMAIL_s*)e->gg.g.n)
	  p = zx_ENC_SO_cdm_EMAIL(c, e, p);
  }
  {
      struct zx_cdm_JABBERID_s* e;
      for (e = x->JABBERID; e; e = (struct zx_cdm_JABBERID_s*)e->gg.g.n)
	  p = zx_ENC_SO_cdm_JABBERID(c, e, p);
  }
  {
      struct zx_cdm_MAILER_s* e;
      for (e = x->MAILER; e; e = (struct zx_cdm_MAILER_s*)e->gg.g.n)
	  p = zx_ENC_SO_cdm_MAILER(c, e, p);
  }
  {
      struct zx_cdm_TZ_s* e;
      for (e = x->TZ; e; e = (struct zx_cdm_TZ_s*)e->gg.g.n)
	  p = zx_ENC_SO_cdm_TZ(c, e, p);
  }
  {
      struct zx_cdm_GEO_s* e;
      for (e = x->GEO; e; e = (struct zx_cdm_GEO_s*)e->gg.g.n)
	  p = zx_ENC_SO_cdm_GEO(c, e, p);
  }
  {
      struct zx_cdm_TITLE_s* e;
      for (e = x->TITLE; e; e = (struct zx_cdm_TITLE_s*)e->gg.g.n)
	  p = zx_ENC_SO_cdm_TITLE(c, e, p);
  }
  {
      struct zx_cdm_ROLE_s* e;
      for (e = x->ROLE; e; e = (struct zx_cdm_ROLE_s*)e->gg.g.n)
	  p = zx_ENC_SO_cdm_ROLE(c, e, p);
  }
  {
      struct zx_cdm_LOGO_s* e;
      for (e = x->LOGO; e; e = (struct zx_cdm_LOGO_s*)e->gg.g.n)
	  p = zx_ENC_SO_cdm_LOGO(c, e, p);
  }
  {
      struct zx_cdm_AGENT_s* e;
      for (e = x->AGENT; e; e = (struct zx_cdm_AGENT_s*)e->gg.g.n)
	  p = zx_ENC_SO_cdm_AGENT(c, e, p);
  }
  {
      struct zx_cdm_ORG_s* e;
      for (e = x->ORG; e; e = (struct zx_cdm_ORG_s*)e->gg.g.n)
	  p = zx_ENC_SO_cdm_ORG(c, e, p);
  }
  {
      struct zx_cdm_CATEGORIES_s* e;
      for (e = x->CATEGORIES; e; e = (struct zx_cdm_CATEGORIES_s*)e->gg.g.n)
	  p = zx_ENC_SO_cdm_CATEGORIES(c, e, p);
  }
  {
      struct zx_cdm_NOTE_s* e;
      for (e = x->NOTE; e; e = (struct zx_cdm_NOTE_s*)e->gg.g.n)
	  p = zx_ENC_SO_cdm_NOTE(c, e, p);
  }
  {
      struct zx_cdm_PRODID_s* e;
      for (e = x->PRODID; e; e = (struct zx_cdm_PRODID_s*)e->gg.g.n)
	  p = zx_ENC_SO_cdm_PRODID(c, e, p);
  }
  {
      struct zx_cdm_REV_s* e;
      for (e = x->REV; e; e = (struct zx_cdm_REV_s*)e->gg.g.n)
	  p = zx_ENC_SO_cdm_REV(c, e, p);
  }
  {
      struct zx_cdm_SORT_STRING_s* e;
      for (e = x->SORT_STRING; e; e = (struct zx_cdm_SORT_STRING_s*)e->gg.g.n)
	  p = zx_ENC_SO_cdm_SORT_STRING(c, e, p);
  }
  {
      struct zx_cdm_SOUND_s* e;
      for (e = x->SOUND; e; e = (struct zx_cdm_SOUND_s*)e->gg.g.n)
	  p = zx_ENC_SO_cdm_SOUND(c, e, p);
  }
  {
      struct zx_cdm_UID_s* e;
      for (e = x->UID; e; e = (struct zx_cdm_UID_s*)e->gg.g.n)
	  p = zx_ENC_SO_cdm_UID(c, e, p);
  }
  {
      struct zx_cdm_URL_s* e;
      for (e = x->URL; e; e = (struct zx_cdm_URL_s*)e->gg.g.n)
	  p = zx_ENC_SO_cdm_URL(c, e, p);
  }
  {
      struct zx_cdm_CLASS_s* e;
      for (e = x->CLASS; e; e = (struct zx_cdm_CLASS_s*)e->gg.g.n)
	  p = zx_ENC_SO_cdm_CLASS(c, e, p);
  }
  {
      struct zx_cdm_KEY_s* e;
      for (e = x->KEY; e; e = (struct zx_cdm_KEY_s*)e->gg.g.n)
	  p = zx_ENC_SO_cdm_KEY(c, e, p);
  }
  {
      struct zx_cdm_DESC_s* e;
      for (e = x->DESC; e; e = (struct zx_cdm_DESC_s*)e->gg.g.n)
	  p = zx_ENC_SO_cdm_DESC(c, e, p);
  }
  {
      struct zx_cdm_PHYSICALACCESS_s* e;
      for (e = x->PHYSICALACCESS; e; e = (struct zx_cdm_PHYSICALACCESS_s*)e->gg.g.n)
	  p = zx_ENC_SO_cdm_PHYSICALACCESS(c, e, p);
  }
  {
      struct zx_cdm_CALURI_s* e;
      for (e = x->CALURI; e; e = (struct zx_cdm_CALURI_s*)e->gg.g.n)
	  p = zx_ENC_SO_cdm_CALURI(c, e, p);
  }
  {
      struct zx_cdm_CAPURI_s* e;
      for (e = x->CAPURI; e; e = (struct zx_cdm_CAPURI_s*)e->gg.g.n)
	  p = zx_ENC_SO_cdm_CAPURI(c, e, p);
  }
  {
      struct zx_cdm_CALADRURI_s* e;
      for (e = x->CALADRURI; e; e = (struct zx_cdm_CALADRURI_s*)e->gg.g.n)
	  p = zx_ENC_SO_cdm_CALADRURI(c, e, p);
  }
  {
      struct zx_cdm_FBURL_s* e;
      for (e = x->FBURL; e; e = (struct zx_cdm_FBURL_s*)e->gg.g.n)
	  p = zx_ENC_SO_cdm_FBURL(c, e, p);
  }
  {
      struct zx_cb_Extension_s* e;
      for (e = x->Extension; e; e = (struct zx_cb_Extension_s*)e->gg.g.n)
	  p = zx_ENC_SO_cb_Extension(c, e, p);
  }

  p = zx_enc_so_unknown_elems_and_content(c, p, &x->gg);
  
#if 1 /* NORMALMODE */
  ZX_OUT_CLOSE_TAG(p, "</cdm:vCard>");
  zx_pop_seen(pop_seen);
#else
  /* root node has no end tag either */
#endif
  ENC_LEN_DEBUG(x, "cdm:vCard", p-enc_base);
  return p;
}

/* FUNC(zx_ENC_WO_cdm_vCard) */

/* Render element into string. The XML attributes and elements are
 * processed in wire order by chasing wo pointers. This is what you want for
 * validating signatures on other people's XML documents. */

/* Called by: */
char* zx_ENC_WO_cdm_vCard(struct zx_ctx* c, struct zx_cdm_vCard_s* x, char* p )
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
  ZX_OUT_MEM(p, "vCard", sizeof("vCard")-1);
  qq = p;

  /* *** sort the namespaces */
  if (c->inc_ns)
    zx_add_inc_ns(c, &pop_seen);
  if (x->id)
    zx_add_xmlns_if_not_seen(c, x->id->g.ns, &pop_seen);
  if (x->modificationTime)
    zx_add_xmlns_if_not_seen(c, x->modificationTime->g.ns, &pop_seen);
  zx_add_xmlns_if_not_seen(c, x->gg.g.ns, &pop_seen);

  p = zx_enc_seen(p, pop_seen); 
  p = zx_attr_wo_enc(p, x->id, "id=\"", sizeof("id=\"")-1);
  p = zx_attr_wo_enc(p, x->modificationTime, "modificationTime=\"", sizeof("modificationTime=\"")-1);

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
  ENC_LEN_DEBUG(x, "cdm:vCard", p-enc_base);
  return p;
}

/* FUNC(zx_EASY_ENC_SO_cdm_vCard) */

/* Called by: */
struct zx_str* zx_EASY_ENC_SO_cdm_vCard(struct zx_ctx* c, struct zx_cdm_vCard_s* x )
{
  int len;
  char* buf;
  c->ns_tab = ZX_ALLOC(c, sizeof(zx_ns_tab));
  memcpy(c->ns_tab, zx_ns_tab, sizeof(zx_ns_tab));
  len = zx_LEN_SO_cdm_vCard(c, x );
  buf = ZX_ALLOC(c, len+1);
  return zx_easy_enc_common(c, zx_ENC_SO_cdm_vCard(c, x, buf ), buf, len);
}

/* FUNC(zx_EASY_ENC_WO_cdm_vCard) */

/* Called by: */
struct zx_str* zx_EASY_ENC_WO_cdm_vCard(struct zx_ctx* c, struct zx_cdm_vCard_s* x )
{
  int len;
  char* buf;
  c->ns_tab = ZX_ALLOC(c, sizeof(zx_ns_tab));
  memcpy(c->ns_tab, zx_ns_tab, sizeof(zx_ns_tab));
  len = zx_LEN_WO_cdm_vCard(c, x );
  buf = ZX_ALLOC(c, len+1);
  return zx_easy_enc_common(c, zx_ENC_WO_cdm_vCard(c, x, buf ), buf, len);
}




/* EOF -- c/zx-cdm-enc.c */
