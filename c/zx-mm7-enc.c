/* c/zx-mm7-enc.c - WARNING: This file was automatically generated. DO NOT EDIT!
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
#include "c/zx-mm7-data.h"
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

#define EL_NAME   mm7_AdditionalInformation
#define EL_STRUCT zx_mm7_AdditionalInformation_s
#define EL_NS     mm7
#define EL_TAG    AdditionalInformation

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

/* FUNC(zx_LEN_SO_mm7_AdditionalInformation) */

/* Compute length of an element (and its subelements). The XML attributes
 * and elements are processed in schema order. */

/* Called by: */
int zx_LEN_SO_mm7_AdditionalInformation(struct zx_ctx* c, struct zx_mm7_AdditionalInformation_s* x )
{
  struct zx_ns_s* pop_seen = 0;
  struct zx_elem_s* se MAYBE_UNUSED;
#if 1 /* NORMALMODE */
  /* *** in simple_elem case should output ns prefix from ns node. */
  int len = sizeof("<mm7:AdditionalInformation")-1 + 1 + sizeof("</mm7:AdditionalInformation>")-1;
  if (c->inc_ns_len)
    len += zx_len_inc_ns(c, &pop_seen);
  len += zx_len_xmlns_if_not_seen(c, zx_ns_tab+zx_xmlns_ix_mm7, &pop_seen);

  len += zx_attr_so_len(x->href, sizeof("href")-1);

#else
  /* root node has no begin tag */
  int len = 0;
#endif
  


  len += zx_len_so_common(c, &x->gg);
  zx_pop_seen(pop_seen);
  ENC_LEN_DEBUG(x, "mm7:AdditionalInformation", len);
  return len;
}

/* FUNC(zx_LEN_WO_mm7_AdditionalInformation) */

/* Compute length of an element (and its subelements). The XML attributes
 * and elements are processed in wire order and no assumptions
 * are made about namespace prefixes. */

/* Called by: */
int zx_LEN_WO_mm7_AdditionalInformation(struct zx_ctx* c, struct zx_mm7_AdditionalInformation_s* x )
{
  struct zx_ns_s* pop_seen = 0;
  struct zx_elem_s* se MAYBE_UNUSED;
#if 1 /* NORMALMODE */
  int len = 1 + sizeof("AdditionalInformation")-1 + 1 + 2 + sizeof("AdditionalInformation")-1 + 1;
  
  if (x->gg.g.ns && x->gg.g.ns->prefix_len)
    len += (x->gg.g.ns->prefix_len + 1) * 2;
  if (c->inc_ns_len)
    len += zx_len_inc_ns(c, &pop_seen);
  len += zx_len_xmlns_if_not_seen(c, x->gg.g.ns, &pop_seen);

  len += zx_attr_wo_len(x->href, sizeof("href")-1);

#else
  /* root node has no begin tag */
  int len = 0;
#endif
  


  len += zx_len_wo_common(c, &x->gg); 
  zx_pop_seen(pop_seen);
  ENC_LEN_DEBUG(x, "mm7:AdditionalInformation", len);
  return len;
}

/* FUNC(zx_ENC_SO_mm7_AdditionalInformation) */

/* Render element into string. The XML attributes and elements are
 * processed in schema order. This is what you generally want for
 * rendering new data structure to a string. The wo pointers are not used. */

/* Called by: */
char* zx_ENC_SO_mm7_AdditionalInformation(struct zx_ctx* c, struct zx_mm7_AdditionalInformation_s* x, char* p )
{
  struct zx_elem_s* se MAYBE_UNUSED;
  struct zx_ns_s* pop_seen = 0;
  ENC_LEN_DEBUG_BASE;
#if 1 /* NORMALMODE */
  /* *** in simple_elem case should output ns prefix from ns node. */
  ZX_OUT_TAG(p, "<mm7:AdditionalInformation");
  if (c->inc_ns)
    p = zx_enc_inc_ns(c, p, &pop_seen);
  p = zx_enc_xmlns_if_not_seen(c, p, zx_ns_tab+zx_xmlns_ix_mm7, &pop_seen);

  p = zx_attr_so_enc(p, x->href, " href=\"", sizeof(" href=\"")-1);

  p = zx_enc_unknown_attrs(p, x->gg.any_attr);
#else
  /* root node has no begin tag */
#endif
  

  p = zx_enc_so_unknown_elems_and_content(c, p, &x->gg);
  
#if 1 /* NORMALMODE */
  ZX_OUT_CLOSE_TAG(p, "</mm7:AdditionalInformation>");
  zx_pop_seen(pop_seen);
#else
  /* root node has no end tag either */
#endif
  ENC_LEN_DEBUG(x, "mm7:AdditionalInformation", p-enc_base);
  return p;
}

/* FUNC(zx_ENC_WO_mm7_AdditionalInformation) */

/* Render element into string. The XML attributes and elements are
 * processed in wire order by chasing wo pointers. This is what you want for
 * validating signatures on other people's XML documents. */

/* Called by: */
char* zx_ENC_WO_mm7_AdditionalInformation(struct zx_ctx* c, struct zx_mm7_AdditionalInformation_s* x, char* p )
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
  ZX_OUT_MEM(p, "AdditionalInformation", sizeof("AdditionalInformation")-1);
  qq = p;

  /* *** sort the namespaces */
  if (c->inc_ns)
    zx_add_inc_ns(c, &pop_seen);
  zx_add_xmlns_if_not_seen(c, x->gg.g.ns, &pop_seen);

  p = zx_enc_seen(p, pop_seen); 
  p = zx_attr_wo_enc(p, x->href, "href=\"", sizeof("href=\"")-1);

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
  ENC_LEN_DEBUG(x, "mm7:AdditionalInformation", p-enc_base);
  return p;
}

/* FUNC(zx_EASY_ENC_SO_mm7_AdditionalInformation) */

/* Called by: */
struct zx_str* zx_EASY_ENC_SO_mm7_AdditionalInformation(struct zx_ctx* c, struct zx_mm7_AdditionalInformation_s* x )
{
  int len;
  char* buf;
  c->ns_tab = ZX_ALLOC(c, sizeof(zx_ns_tab));
  memcpy(c->ns_tab, zx_ns_tab, sizeof(zx_ns_tab));
  len = zx_LEN_SO_mm7_AdditionalInformation(c, x );
  buf = ZX_ALLOC(c, len+1);
  return zx_easy_enc_common(c, zx_ENC_SO_mm7_AdditionalInformation(c, x, buf ), buf, len);
}

/* FUNC(zx_EASY_ENC_WO_mm7_AdditionalInformation) */

/* Called by: */
struct zx_str* zx_EASY_ENC_WO_mm7_AdditionalInformation(struct zx_ctx* c, struct zx_mm7_AdditionalInformation_s* x )
{
  int len;
  char* buf;
  c->ns_tab = ZX_ALLOC(c, sizeof(zx_ns_tab));
  memcpy(c->ns_tab, zx_ns_tab, sizeof(zx_ns_tab));
  len = zx_LEN_WO_mm7_AdditionalInformation(c, x );
  buf = ZX_ALLOC(c, len+1);
  return zx_easy_enc_common(c, zx_ENC_WO_mm7_AdditionalInformation(c, x, buf ), buf, len);
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

#define EL_NAME   mm7_Bcc
#define EL_STRUCT zx_mm7_Bcc_s
#define EL_NS     mm7
#define EL_TAG    Bcc

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

/* FUNC(zx_LEN_SO_mm7_Bcc) */

/* Compute length of an element (and its subelements). The XML attributes
 * and elements are processed in schema order. */

/* Called by: */
int zx_LEN_SO_mm7_Bcc(struct zx_ctx* c, struct zx_mm7_Bcc_s* x )
{
  struct zx_ns_s* pop_seen = 0;
  struct zx_elem_s* se MAYBE_UNUSED;
#if 1 /* NORMALMODE */
  /* *** in simple_elem case should output ns prefix from ns node. */
  int len = sizeof("<mm7:Bcc")-1 + 1 + sizeof("</mm7:Bcc>")-1;
  if (c->inc_ns_len)
    len += zx_len_inc_ns(c, &pop_seen);
  len += zx_len_xmlns_if_not_seen(c, zx_ns_tab+zx_xmlns_ix_mm7, &pop_seen);


#else
  /* root node has no begin tag */
  int len = 0;
#endif
  
  {
      struct zx_mm7_RFC2822Address_s* e;
      for (e = x->RFC2822Address; e; e = (struct zx_mm7_RFC2822Address_s*)e->gg.g.n)
	  len += zx_LEN_SO_mm7_RFC2822Address(c, e);
  }
  {
      struct zx_mm7_Number_s* e;
      for (e = x->Number; e; e = (struct zx_mm7_Number_s*)e->gg.g.n)
	  len += zx_LEN_SO_mm7_Number(c, e);
  }
  {
      struct zx_mm7_ShortCode_s* e;
      for (e = x->ShortCode; e; e = (struct zx_mm7_ShortCode_s*)e->gg.g.n)
	  len += zx_LEN_SO_mm7_ShortCode(c, e);
  }
  {
      struct zx_mm7_Extension_s* e;
      for (e = x->Extension; e; e = (struct zx_mm7_Extension_s*)e->gg.g.n)
	  len += zx_LEN_SO_mm7_Extension(c, e);
  }


  len += zx_len_so_common(c, &x->gg);
  zx_pop_seen(pop_seen);
  ENC_LEN_DEBUG(x, "mm7:Bcc", len);
  return len;
}

/* FUNC(zx_LEN_WO_mm7_Bcc) */

/* Compute length of an element (and its subelements). The XML attributes
 * and elements are processed in wire order and no assumptions
 * are made about namespace prefixes. */

/* Called by: */
int zx_LEN_WO_mm7_Bcc(struct zx_ctx* c, struct zx_mm7_Bcc_s* x )
{
  struct zx_ns_s* pop_seen = 0;
  struct zx_elem_s* se MAYBE_UNUSED;
#if 1 /* NORMALMODE */
  int len = 1 + sizeof("Bcc")-1 + 1 + 2 + sizeof("Bcc")-1 + 1;
  
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
      struct zx_mm7_RFC2822Address_s* e;
      for (e = x->RFC2822Address; e; e = (struct zx_mm7_RFC2822Address_s*)e->gg.g.n)
	  len += zx_LEN_WO_mm7_RFC2822Address(c, e);
  }
  {
      struct zx_mm7_Number_s* e;
      for (e = x->Number; e; e = (struct zx_mm7_Number_s*)e->gg.g.n)
	  len += zx_LEN_WO_mm7_Number(c, e);
  }
  {
      struct zx_mm7_ShortCode_s* e;
      for (e = x->ShortCode; e; e = (struct zx_mm7_ShortCode_s*)e->gg.g.n)
	  len += zx_LEN_WO_mm7_ShortCode(c, e);
  }
  {
      struct zx_mm7_Extension_s* e;
      for (e = x->Extension; e; e = (struct zx_mm7_Extension_s*)e->gg.g.n)
	  len += zx_LEN_WO_mm7_Extension(c, e);
  }


  len += zx_len_wo_common(c, &x->gg); 
  zx_pop_seen(pop_seen);
  ENC_LEN_DEBUG(x, "mm7:Bcc", len);
  return len;
}

/* FUNC(zx_ENC_SO_mm7_Bcc) */

/* Render element into string. The XML attributes and elements are
 * processed in schema order. This is what you generally want for
 * rendering new data structure to a string. The wo pointers are not used. */

/* Called by: */
char* zx_ENC_SO_mm7_Bcc(struct zx_ctx* c, struct zx_mm7_Bcc_s* x, char* p )
{
  struct zx_elem_s* se MAYBE_UNUSED;
  struct zx_ns_s* pop_seen = 0;
  ENC_LEN_DEBUG_BASE;
#if 1 /* NORMALMODE */
  /* *** in simple_elem case should output ns prefix from ns node. */
  ZX_OUT_TAG(p, "<mm7:Bcc");
  if (c->inc_ns)
    p = zx_enc_inc_ns(c, p, &pop_seen);
  p = zx_enc_xmlns_if_not_seen(c, p, zx_ns_tab+zx_xmlns_ix_mm7, &pop_seen);


  p = zx_enc_unknown_attrs(p, x->gg.any_attr);
#else
  /* root node has no begin tag */
#endif
  
  {
      struct zx_mm7_RFC2822Address_s* e;
      for (e = x->RFC2822Address; e; e = (struct zx_mm7_RFC2822Address_s*)e->gg.g.n)
	  p = zx_ENC_SO_mm7_RFC2822Address(c, e, p);
  }
  {
      struct zx_mm7_Number_s* e;
      for (e = x->Number; e; e = (struct zx_mm7_Number_s*)e->gg.g.n)
	  p = zx_ENC_SO_mm7_Number(c, e, p);
  }
  {
      struct zx_mm7_ShortCode_s* e;
      for (e = x->ShortCode; e; e = (struct zx_mm7_ShortCode_s*)e->gg.g.n)
	  p = zx_ENC_SO_mm7_ShortCode(c, e, p);
  }
  {
      struct zx_mm7_Extension_s* e;
      for (e = x->Extension; e; e = (struct zx_mm7_Extension_s*)e->gg.g.n)
	  p = zx_ENC_SO_mm7_Extension(c, e, p);
  }

  p = zx_enc_so_unknown_elems_and_content(c, p, &x->gg);
  
#if 1 /* NORMALMODE */
  ZX_OUT_CLOSE_TAG(p, "</mm7:Bcc>");
  zx_pop_seen(pop_seen);
#else
  /* root node has no end tag either */
#endif
  ENC_LEN_DEBUG(x, "mm7:Bcc", p-enc_base);
  return p;
}

/* FUNC(zx_ENC_WO_mm7_Bcc) */

/* Render element into string. The XML attributes and elements are
 * processed in wire order by chasing wo pointers. This is what you want for
 * validating signatures on other people's XML documents. */

/* Called by: */
char* zx_ENC_WO_mm7_Bcc(struct zx_ctx* c, struct zx_mm7_Bcc_s* x, char* p )
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
  ZX_OUT_MEM(p, "Bcc", sizeof("Bcc")-1);
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
  ENC_LEN_DEBUG(x, "mm7:Bcc", p-enc_base);
  return p;
}

/* FUNC(zx_EASY_ENC_SO_mm7_Bcc) */

/* Called by: */
struct zx_str* zx_EASY_ENC_SO_mm7_Bcc(struct zx_ctx* c, struct zx_mm7_Bcc_s* x )
{
  int len;
  char* buf;
  c->ns_tab = ZX_ALLOC(c, sizeof(zx_ns_tab));
  memcpy(c->ns_tab, zx_ns_tab, sizeof(zx_ns_tab));
  len = zx_LEN_SO_mm7_Bcc(c, x );
  buf = ZX_ALLOC(c, len+1);
  return zx_easy_enc_common(c, zx_ENC_SO_mm7_Bcc(c, x, buf ), buf, len);
}

/* FUNC(zx_EASY_ENC_WO_mm7_Bcc) */

/* Called by: */
struct zx_str* zx_EASY_ENC_WO_mm7_Bcc(struct zx_ctx* c, struct zx_mm7_Bcc_s* x )
{
  int len;
  char* buf;
  c->ns_tab = ZX_ALLOC(c, sizeof(zx_ns_tab));
  memcpy(c->ns_tab, zx_ns_tab, sizeof(zx_ns_tab));
  len = zx_LEN_WO_mm7_Bcc(c, x );
  buf = ZX_ALLOC(c, len+1);
  return zx_easy_enc_common(c, zx_ENC_WO_mm7_Bcc(c, x, buf ), buf, len);
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

#define EL_NAME   mm7_CancelReq
#define EL_STRUCT zx_mm7_CancelReq_s
#define EL_NS     mm7
#define EL_TAG    CancelReq

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

/* FUNC(zx_LEN_SO_mm7_CancelReq) */

/* Compute length of an element (and its subelements). The XML attributes
 * and elements are processed in schema order. */

/* Called by: */
int zx_LEN_SO_mm7_CancelReq(struct zx_ctx* c, struct zx_mm7_CancelReq_s* x )
{
  struct zx_ns_s* pop_seen = 0;
  struct zx_elem_s* se MAYBE_UNUSED;
#if 1 /* NORMALMODE */
  /* *** in simple_elem case should output ns prefix from ns node. */
  int len = sizeof("<mm7:CancelReq")-1 + 1 + sizeof("</mm7:CancelReq>")-1;
  if (c->inc_ns_len)
    len += zx_len_inc_ns(c, &pop_seen);
  len += zx_len_xmlns_if_not_seen(c, zx_ns_tab+zx_xmlns_ix_mm7, &pop_seen);


#else
  /* root node has no begin tag */
  int len = 0;
#endif
  
  for (se = x->MM7Version; se; se = (struct zx_elem_s*)se->g.n)
    len += zx_LEN_SO_simple_elem(c,se, sizeof("mm7:MM7Version")-1, zx_ns_tab+zx_xmlns_ix_mm7);
  {
      struct zx_mm7_SenderIdentification_s* e;
      for (e = x->SenderIdentification; e; e = (struct zx_mm7_SenderIdentification_s*)e->gg.g.n)
	  len += zx_LEN_SO_mm7_SenderIdentification(c, e);
  }
  {
      struct zx_mm7_Extension_s* e;
      for (e = x->Extension; e; e = (struct zx_mm7_Extension_s*)e->gg.g.n)
	  len += zx_LEN_SO_mm7_Extension(c, e);
  }
  for (se = x->MessageID; se; se = (struct zx_elem_s*)se->g.n)
    len += zx_LEN_SO_simple_elem(c,se, sizeof("mm7:MessageID")-1, zx_ns_tab+zx_xmlns_ix_mm7);
  {
      struct zx_mm7_Recipients_s* e;
      for (e = x->Recipients; e; e = (struct zx_mm7_Recipients_s*)e->gg.g.n)
	  len += zx_LEN_SO_mm7_Recipients(c, e);
  }
  for (se = x->ApplicID; se; se = (struct zx_elem_s*)se->g.n)
    len += zx_LEN_SO_simple_elem(c,se, sizeof("mm7:ApplicID")-1, zx_ns_tab+zx_xmlns_ix_mm7);
  for (se = x->ReplyApplicID; se; se = (struct zx_elem_s*)se->g.n)
    len += zx_LEN_SO_simple_elem(c,se, sizeof("mm7:ReplyApplicID")-1, zx_ns_tab+zx_xmlns_ix_mm7);
  for (se = x->AuxApplicInfo; se; se = (struct zx_elem_s*)se->g.n)
    len += zx_LEN_SO_simple_elem(c,se, sizeof("mm7:AuxApplicInfo")-1, zx_ns_tab+zx_xmlns_ix_mm7);


  len += zx_len_so_common(c, &x->gg);
  zx_pop_seen(pop_seen);
  ENC_LEN_DEBUG(x, "mm7:CancelReq", len);
  return len;
}

/* FUNC(zx_LEN_WO_mm7_CancelReq) */

/* Compute length of an element (and its subelements). The XML attributes
 * and elements are processed in wire order and no assumptions
 * are made about namespace prefixes. */

/* Called by: */
int zx_LEN_WO_mm7_CancelReq(struct zx_ctx* c, struct zx_mm7_CancelReq_s* x )
{
  struct zx_ns_s* pop_seen = 0;
  struct zx_elem_s* se MAYBE_UNUSED;
#if 1 /* NORMALMODE */
  int len = 1 + sizeof("CancelReq")-1 + 1 + 2 + sizeof("CancelReq")-1 + 1;
  
  if (x->gg.g.ns && x->gg.g.ns->prefix_len)
    len += (x->gg.g.ns->prefix_len + 1) * 2;
  if (c->inc_ns_len)
    len += zx_len_inc_ns(c, &pop_seen);
  len += zx_len_xmlns_if_not_seen(c, x->gg.g.ns, &pop_seen);


#else
  /* root node has no begin tag */
  int len = 0;
#endif
  
  for (se = x->MM7Version; se; se = (struct zx_elem_s*)se->g.n)
    len += zx_LEN_WO_simple_elem(c, se, sizeof("MM7Version")-1);
  {
      struct zx_mm7_SenderIdentification_s* e;
      for (e = x->SenderIdentification; e; e = (struct zx_mm7_SenderIdentification_s*)e->gg.g.n)
	  len += zx_LEN_WO_mm7_SenderIdentification(c, e);
  }
  {
      struct zx_mm7_Extension_s* e;
      for (e = x->Extension; e; e = (struct zx_mm7_Extension_s*)e->gg.g.n)
	  len += zx_LEN_WO_mm7_Extension(c, e);
  }
  for (se = x->MessageID; se; se = (struct zx_elem_s*)se->g.n)
    len += zx_LEN_WO_simple_elem(c, se, sizeof("MessageID")-1);
  {
      struct zx_mm7_Recipients_s* e;
      for (e = x->Recipients; e; e = (struct zx_mm7_Recipients_s*)e->gg.g.n)
	  len += zx_LEN_WO_mm7_Recipients(c, e);
  }
  for (se = x->ApplicID; se; se = (struct zx_elem_s*)se->g.n)
    len += zx_LEN_WO_simple_elem(c, se, sizeof("ApplicID")-1);
  for (se = x->ReplyApplicID; se; se = (struct zx_elem_s*)se->g.n)
    len += zx_LEN_WO_simple_elem(c, se, sizeof("ReplyApplicID")-1);
  for (se = x->AuxApplicInfo; se; se = (struct zx_elem_s*)se->g.n)
    len += zx_LEN_WO_simple_elem(c, se, sizeof("AuxApplicInfo")-1);


  len += zx_len_wo_common(c, &x->gg); 
  zx_pop_seen(pop_seen);
  ENC_LEN_DEBUG(x, "mm7:CancelReq", len);
  return len;
}

/* FUNC(zx_ENC_SO_mm7_CancelReq) */

/* Render element into string. The XML attributes and elements are
 * processed in schema order. This is what you generally want for
 * rendering new data structure to a string. The wo pointers are not used. */

/* Called by: */
char* zx_ENC_SO_mm7_CancelReq(struct zx_ctx* c, struct zx_mm7_CancelReq_s* x, char* p )
{
  struct zx_elem_s* se MAYBE_UNUSED;
  struct zx_ns_s* pop_seen = 0;
  ENC_LEN_DEBUG_BASE;
#if 1 /* NORMALMODE */
  /* *** in simple_elem case should output ns prefix from ns node. */
  ZX_OUT_TAG(p, "<mm7:CancelReq");
  if (c->inc_ns)
    p = zx_enc_inc_ns(c, p, &pop_seen);
  p = zx_enc_xmlns_if_not_seen(c, p, zx_ns_tab+zx_xmlns_ix_mm7, &pop_seen);


  p = zx_enc_unknown_attrs(p, x->gg.any_attr);
#else
  /* root node has no begin tag */
#endif
  
  for (se = x->MM7Version; se; se = (struct zx_elem_s*)se->g.n)
    p = zx_ENC_SO_simple_elem(c, se, p, "mm7:MM7Version", sizeof("mm7:MM7Version")-1, zx_ns_tab+zx_xmlns_ix_mm7);
  {
      struct zx_mm7_SenderIdentification_s* e;
      for (e = x->SenderIdentification; e; e = (struct zx_mm7_SenderIdentification_s*)e->gg.g.n)
	  p = zx_ENC_SO_mm7_SenderIdentification(c, e, p);
  }
  {
      struct zx_mm7_Extension_s* e;
      for (e = x->Extension; e; e = (struct zx_mm7_Extension_s*)e->gg.g.n)
	  p = zx_ENC_SO_mm7_Extension(c, e, p);
  }
  for (se = x->MessageID; se; se = (struct zx_elem_s*)se->g.n)
    p = zx_ENC_SO_simple_elem(c, se, p, "mm7:MessageID", sizeof("mm7:MessageID")-1, zx_ns_tab+zx_xmlns_ix_mm7);
  {
      struct zx_mm7_Recipients_s* e;
      for (e = x->Recipients; e; e = (struct zx_mm7_Recipients_s*)e->gg.g.n)
	  p = zx_ENC_SO_mm7_Recipients(c, e, p);
  }
  for (se = x->ApplicID; se; se = (struct zx_elem_s*)se->g.n)
    p = zx_ENC_SO_simple_elem(c, se, p, "mm7:ApplicID", sizeof("mm7:ApplicID")-1, zx_ns_tab+zx_xmlns_ix_mm7);
  for (se = x->ReplyApplicID; se; se = (struct zx_elem_s*)se->g.n)
    p = zx_ENC_SO_simple_elem(c, se, p, "mm7:ReplyApplicID", sizeof("mm7:ReplyApplicID")-1, zx_ns_tab+zx_xmlns_ix_mm7);
  for (se = x->AuxApplicInfo; se; se = (struct zx_elem_s*)se->g.n)
    p = zx_ENC_SO_simple_elem(c, se, p, "mm7:AuxApplicInfo", sizeof("mm7:AuxApplicInfo")-1, zx_ns_tab+zx_xmlns_ix_mm7);

  p = zx_enc_so_unknown_elems_and_content(c, p, &x->gg);
  
#if 1 /* NORMALMODE */
  ZX_OUT_CLOSE_TAG(p, "</mm7:CancelReq>");
  zx_pop_seen(pop_seen);
#else
  /* root node has no end tag either */
#endif
  ENC_LEN_DEBUG(x, "mm7:CancelReq", p-enc_base);
  return p;
}

/* FUNC(zx_ENC_WO_mm7_CancelReq) */

/* Render element into string. The XML attributes and elements are
 * processed in wire order by chasing wo pointers. This is what you want for
 * validating signatures on other people's XML documents. */

/* Called by: */
char* zx_ENC_WO_mm7_CancelReq(struct zx_ctx* c, struct zx_mm7_CancelReq_s* x, char* p )
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
  ZX_OUT_MEM(p, "CancelReq", sizeof("CancelReq")-1);
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
  ENC_LEN_DEBUG(x, "mm7:CancelReq", p-enc_base);
  return p;
}

/* FUNC(zx_EASY_ENC_SO_mm7_CancelReq) */

/* Called by: */
struct zx_str* zx_EASY_ENC_SO_mm7_CancelReq(struct zx_ctx* c, struct zx_mm7_CancelReq_s* x )
{
  int len;
  char* buf;
  c->ns_tab = ZX_ALLOC(c, sizeof(zx_ns_tab));
  memcpy(c->ns_tab, zx_ns_tab, sizeof(zx_ns_tab));
  len = zx_LEN_SO_mm7_CancelReq(c, x );
  buf = ZX_ALLOC(c, len+1);
  return zx_easy_enc_common(c, zx_ENC_SO_mm7_CancelReq(c, x, buf ), buf, len);
}

/* FUNC(zx_EASY_ENC_WO_mm7_CancelReq) */

/* Called by: */
struct zx_str* zx_EASY_ENC_WO_mm7_CancelReq(struct zx_ctx* c, struct zx_mm7_CancelReq_s* x )
{
  int len;
  char* buf;
  c->ns_tab = ZX_ALLOC(c, sizeof(zx_ns_tab));
  memcpy(c->ns_tab, zx_ns_tab, sizeof(zx_ns_tab));
  len = zx_LEN_WO_mm7_CancelReq(c, x );
  buf = ZX_ALLOC(c, len+1);
  return zx_easy_enc_common(c, zx_ENC_WO_mm7_CancelReq(c, x, buf ), buf, len);
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

#define EL_NAME   mm7_CancelRsp
#define EL_STRUCT zx_mm7_CancelRsp_s
#define EL_NS     mm7
#define EL_TAG    CancelRsp

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

/* FUNC(zx_LEN_SO_mm7_CancelRsp) */

/* Compute length of an element (and its subelements). The XML attributes
 * and elements are processed in schema order. */

/* Called by: */
int zx_LEN_SO_mm7_CancelRsp(struct zx_ctx* c, struct zx_mm7_CancelRsp_s* x )
{
  struct zx_ns_s* pop_seen = 0;
  struct zx_elem_s* se MAYBE_UNUSED;
#if 1 /* NORMALMODE */
  /* *** in simple_elem case should output ns prefix from ns node. */
  int len = sizeof("<mm7:CancelRsp")-1 + 1 + sizeof("</mm7:CancelRsp>")-1;
  if (c->inc_ns_len)
    len += zx_len_inc_ns(c, &pop_seen);
  len += zx_len_xmlns_if_not_seen(c, zx_ns_tab+zx_xmlns_ix_mm7, &pop_seen);


#else
  /* root node has no begin tag */
  int len = 0;
#endif
  
  for (se = x->MM7Version; se; se = (struct zx_elem_s*)se->g.n)
    len += zx_LEN_SO_simple_elem(c,se, sizeof("mm7:MM7Version")-1, zx_ns_tab+zx_xmlns_ix_mm7);
  {
      struct zx_mm7_Status_s* e;
      for (e = x->Status; e; e = (struct zx_mm7_Status_s*)e->gg.g.n)
	  len += zx_LEN_SO_mm7_Status(c, e);
  }
  {
      struct zx_mm7_Extension_s* e;
      for (e = x->Extension; e; e = (struct zx_mm7_Extension_s*)e->gg.g.n)
	  len += zx_LEN_SO_mm7_Extension(c, e);
  }


  len += zx_len_so_common(c, &x->gg);
  zx_pop_seen(pop_seen);
  ENC_LEN_DEBUG(x, "mm7:CancelRsp", len);
  return len;
}

/* FUNC(zx_LEN_WO_mm7_CancelRsp) */

/* Compute length of an element (and its subelements). The XML attributes
 * and elements are processed in wire order and no assumptions
 * are made about namespace prefixes. */

/* Called by: */
int zx_LEN_WO_mm7_CancelRsp(struct zx_ctx* c, struct zx_mm7_CancelRsp_s* x )
{
  struct zx_ns_s* pop_seen = 0;
  struct zx_elem_s* se MAYBE_UNUSED;
#if 1 /* NORMALMODE */
  int len = 1 + sizeof("CancelRsp")-1 + 1 + 2 + sizeof("CancelRsp")-1 + 1;
  
  if (x->gg.g.ns && x->gg.g.ns->prefix_len)
    len += (x->gg.g.ns->prefix_len + 1) * 2;
  if (c->inc_ns_len)
    len += zx_len_inc_ns(c, &pop_seen);
  len += zx_len_xmlns_if_not_seen(c, x->gg.g.ns, &pop_seen);


#else
  /* root node has no begin tag */
  int len = 0;
#endif
  
  for (se = x->MM7Version; se; se = (struct zx_elem_s*)se->g.n)
    len += zx_LEN_WO_simple_elem(c, se, sizeof("MM7Version")-1);
  {
      struct zx_mm7_Status_s* e;
      for (e = x->Status; e; e = (struct zx_mm7_Status_s*)e->gg.g.n)
	  len += zx_LEN_WO_mm7_Status(c, e);
  }
  {
      struct zx_mm7_Extension_s* e;
      for (e = x->Extension; e; e = (struct zx_mm7_Extension_s*)e->gg.g.n)
	  len += zx_LEN_WO_mm7_Extension(c, e);
  }


  len += zx_len_wo_common(c, &x->gg); 
  zx_pop_seen(pop_seen);
  ENC_LEN_DEBUG(x, "mm7:CancelRsp", len);
  return len;
}

/* FUNC(zx_ENC_SO_mm7_CancelRsp) */

/* Render element into string. The XML attributes and elements are
 * processed in schema order. This is what you generally want for
 * rendering new data structure to a string. The wo pointers are not used. */

/* Called by: */
char* zx_ENC_SO_mm7_CancelRsp(struct zx_ctx* c, struct zx_mm7_CancelRsp_s* x, char* p )
{
  struct zx_elem_s* se MAYBE_UNUSED;
  struct zx_ns_s* pop_seen = 0;
  ENC_LEN_DEBUG_BASE;
#if 1 /* NORMALMODE */
  /* *** in simple_elem case should output ns prefix from ns node. */
  ZX_OUT_TAG(p, "<mm7:CancelRsp");
  if (c->inc_ns)
    p = zx_enc_inc_ns(c, p, &pop_seen);
  p = zx_enc_xmlns_if_not_seen(c, p, zx_ns_tab+zx_xmlns_ix_mm7, &pop_seen);


  p = zx_enc_unknown_attrs(p, x->gg.any_attr);
#else
  /* root node has no begin tag */
#endif
  
  for (se = x->MM7Version; se; se = (struct zx_elem_s*)se->g.n)
    p = zx_ENC_SO_simple_elem(c, se, p, "mm7:MM7Version", sizeof("mm7:MM7Version")-1, zx_ns_tab+zx_xmlns_ix_mm7);
  {
      struct zx_mm7_Status_s* e;
      for (e = x->Status; e; e = (struct zx_mm7_Status_s*)e->gg.g.n)
	  p = zx_ENC_SO_mm7_Status(c, e, p);
  }
  {
      struct zx_mm7_Extension_s* e;
      for (e = x->Extension; e; e = (struct zx_mm7_Extension_s*)e->gg.g.n)
	  p = zx_ENC_SO_mm7_Extension(c, e, p);
  }

  p = zx_enc_so_unknown_elems_and_content(c, p, &x->gg);
  
#if 1 /* NORMALMODE */
  ZX_OUT_CLOSE_TAG(p, "</mm7:CancelRsp>");
  zx_pop_seen(pop_seen);
#else
  /* root node has no end tag either */
#endif
  ENC_LEN_DEBUG(x, "mm7:CancelRsp", p-enc_base);
  return p;
}

/* FUNC(zx_ENC_WO_mm7_CancelRsp) */

/* Render element into string. The XML attributes and elements are
 * processed in wire order by chasing wo pointers. This is what you want for
 * validating signatures on other people's XML documents. */

/* Called by: */
char* zx_ENC_WO_mm7_CancelRsp(struct zx_ctx* c, struct zx_mm7_CancelRsp_s* x, char* p )
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
  ZX_OUT_MEM(p, "CancelRsp", sizeof("CancelRsp")-1);
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
  ENC_LEN_DEBUG(x, "mm7:CancelRsp", p-enc_base);
  return p;
}

/* FUNC(zx_EASY_ENC_SO_mm7_CancelRsp) */

/* Called by: */
struct zx_str* zx_EASY_ENC_SO_mm7_CancelRsp(struct zx_ctx* c, struct zx_mm7_CancelRsp_s* x )
{
  int len;
  char* buf;
  c->ns_tab = ZX_ALLOC(c, sizeof(zx_ns_tab));
  memcpy(c->ns_tab, zx_ns_tab, sizeof(zx_ns_tab));
  len = zx_LEN_SO_mm7_CancelRsp(c, x );
  buf = ZX_ALLOC(c, len+1);
  return zx_easy_enc_common(c, zx_ENC_SO_mm7_CancelRsp(c, x, buf ), buf, len);
}

/* FUNC(zx_EASY_ENC_WO_mm7_CancelRsp) */

/* Called by: */
struct zx_str* zx_EASY_ENC_WO_mm7_CancelRsp(struct zx_ctx* c, struct zx_mm7_CancelRsp_s* x )
{
  int len;
  char* buf;
  c->ns_tab = ZX_ALLOC(c, sizeof(zx_ns_tab));
  memcpy(c->ns_tab, zx_ns_tab, sizeof(zx_ns_tab));
  len = zx_LEN_WO_mm7_CancelRsp(c, x );
  buf = ZX_ALLOC(c, len+1);
  return zx_easy_enc_common(c, zx_ENC_WO_mm7_CancelRsp(c, x, buf ), buf, len);
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

#define EL_NAME   mm7_Cc
#define EL_STRUCT zx_mm7_Cc_s
#define EL_NS     mm7
#define EL_TAG    Cc

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

/* FUNC(zx_LEN_SO_mm7_Cc) */

/* Compute length of an element (and its subelements). The XML attributes
 * and elements are processed in schema order. */

/* Called by: */
int zx_LEN_SO_mm7_Cc(struct zx_ctx* c, struct zx_mm7_Cc_s* x )
{
  struct zx_ns_s* pop_seen = 0;
  struct zx_elem_s* se MAYBE_UNUSED;
#if 1 /* NORMALMODE */
  /* *** in simple_elem case should output ns prefix from ns node. */
  int len = sizeof("<mm7:Cc")-1 + 1 + sizeof("</mm7:Cc>")-1;
  if (c->inc_ns_len)
    len += zx_len_inc_ns(c, &pop_seen);
  len += zx_len_xmlns_if_not_seen(c, zx_ns_tab+zx_xmlns_ix_mm7, &pop_seen);


#else
  /* root node has no begin tag */
  int len = 0;
#endif
  
  {
      struct zx_mm7_RFC2822Address_s* e;
      for (e = x->RFC2822Address; e; e = (struct zx_mm7_RFC2822Address_s*)e->gg.g.n)
	  len += zx_LEN_SO_mm7_RFC2822Address(c, e);
  }
  {
      struct zx_mm7_Number_s* e;
      for (e = x->Number; e; e = (struct zx_mm7_Number_s*)e->gg.g.n)
	  len += zx_LEN_SO_mm7_Number(c, e);
  }
  {
      struct zx_mm7_ShortCode_s* e;
      for (e = x->ShortCode; e; e = (struct zx_mm7_ShortCode_s*)e->gg.g.n)
	  len += zx_LEN_SO_mm7_ShortCode(c, e);
  }
  {
      struct zx_mm7_Extension_s* e;
      for (e = x->Extension; e; e = (struct zx_mm7_Extension_s*)e->gg.g.n)
	  len += zx_LEN_SO_mm7_Extension(c, e);
  }


  len += zx_len_so_common(c, &x->gg);
  zx_pop_seen(pop_seen);
  ENC_LEN_DEBUG(x, "mm7:Cc", len);
  return len;
}

/* FUNC(zx_LEN_WO_mm7_Cc) */

/* Compute length of an element (and its subelements). The XML attributes
 * and elements are processed in wire order and no assumptions
 * are made about namespace prefixes. */

/* Called by: */
int zx_LEN_WO_mm7_Cc(struct zx_ctx* c, struct zx_mm7_Cc_s* x )
{
  struct zx_ns_s* pop_seen = 0;
  struct zx_elem_s* se MAYBE_UNUSED;
#if 1 /* NORMALMODE */
  int len = 1 + sizeof("Cc")-1 + 1 + 2 + sizeof("Cc")-1 + 1;
  
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
      struct zx_mm7_RFC2822Address_s* e;
      for (e = x->RFC2822Address; e; e = (struct zx_mm7_RFC2822Address_s*)e->gg.g.n)
	  len += zx_LEN_WO_mm7_RFC2822Address(c, e);
  }
  {
      struct zx_mm7_Number_s* e;
      for (e = x->Number; e; e = (struct zx_mm7_Number_s*)e->gg.g.n)
	  len += zx_LEN_WO_mm7_Number(c, e);
  }
  {
      struct zx_mm7_ShortCode_s* e;
      for (e = x->ShortCode; e; e = (struct zx_mm7_ShortCode_s*)e->gg.g.n)
	  len += zx_LEN_WO_mm7_ShortCode(c, e);
  }
  {
      struct zx_mm7_Extension_s* e;
      for (e = x->Extension; e; e = (struct zx_mm7_Extension_s*)e->gg.g.n)
	  len += zx_LEN_WO_mm7_Extension(c, e);
  }


  len += zx_len_wo_common(c, &x->gg); 
  zx_pop_seen(pop_seen);
  ENC_LEN_DEBUG(x, "mm7:Cc", len);
  return len;
}

/* FUNC(zx_ENC_SO_mm7_Cc) */

/* Render element into string. The XML attributes and elements are
 * processed in schema order. This is what you generally want for
 * rendering new data structure to a string. The wo pointers are not used. */

/* Called by: */
char* zx_ENC_SO_mm7_Cc(struct zx_ctx* c, struct zx_mm7_Cc_s* x, char* p )
{
  struct zx_elem_s* se MAYBE_UNUSED;
  struct zx_ns_s* pop_seen = 0;
  ENC_LEN_DEBUG_BASE;
#if 1 /* NORMALMODE */
  /* *** in simple_elem case should output ns prefix from ns node. */
  ZX_OUT_TAG(p, "<mm7:Cc");
  if (c->inc_ns)
    p = zx_enc_inc_ns(c, p, &pop_seen);
  p = zx_enc_xmlns_if_not_seen(c, p, zx_ns_tab+zx_xmlns_ix_mm7, &pop_seen);


  p = zx_enc_unknown_attrs(p, x->gg.any_attr);
#else
  /* root node has no begin tag */
#endif
  
  {
      struct zx_mm7_RFC2822Address_s* e;
      for (e = x->RFC2822Address; e; e = (struct zx_mm7_RFC2822Address_s*)e->gg.g.n)
	  p = zx_ENC_SO_mm7_RFC2822Address(c, e, p);
  }
  {
      struct zx_mm7_Number_s* e;
      for (e = x->Number; e; e = (struct zx_mm7_Number_s*)e->gg.g.n)
	  p = zx_ENC_SO_mm7_Number(c, e, p);
  }
  {
      struct zx_mm7_ShortCode_s* e;
      for (e = x->ShortCode; e; e = (struct zx_mm7_ShortCode_s*)e->gg.g.n)
	  p = zx_ENC_SO_mm7_ShortCode(c, e, p);
  }
  {
      struct zx_mm7_Extension_s* e;
      for (e = x->Extension; e; e = (struct zx_mm7_Extension_s*)e->gg.g.n)
	  p = zx_ENC_SO_mm7_Extension(c, e, p);
  }

  p = zx_enc_so_unknown_elems_and_content(c, p, &x->gg);
  
#if 1 /* NORMALMODE */
  ZX_OUT_CLOSE_TAG(p, "</mm7:Cc>");
  zx_pop_seen(pop_seen);
#else
  /* root node has no end tag either */
#endif
  ENC_LEN_DEBUG(x, "mm7:Cc", p-enc_base);
  return p;
}

/* FUNC(zx_ENC_WO_mm7_Cc) */

/* Render element into string. The XML attributes and elements are
 * processed in wire order by chasing wo pointers. This is what you want for
 * validating signatures on other people's XML documents. */

/* Called by: */
char* zx_ENC_WO_mm7_Cc(struct zx_ctx* c, struct zx_mm7_Cc_s* x, char* p )
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
  ZX_OUT_MEM(p, "Cc", sizeof("Cc")-1);
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
  ENC_LEN_DEBUG(x, "mm7:Cc", p-enc_base);
  return p;
}

/* FUNC(zx_EASY_ENC_SO_mm7_Cc) */

/* Called by: */
struct zx_str* zx_EASY_ENC_SO_mm7_Cc(struct zx_ctx* c, struct zx_mm7_Cc_s* x )
{
  int len;
  char* buf;
  c->ns_tab = ZX_ALLOC(c, sizeof(zx_ns_tab));
  memcpy(c->ns_tab, zx_ns_tab, sizeof(zx_ns_tab));
  len = zx_LEN_SO_mm7_Cc(c, x );
  buf = ZX_ALLOC(c, len+1);
  return zx_easy_enc_common(c, zx_ENC_SO_mm7_Cc(c, x, buf ), buf, len);
}

/* FUNC(zx_EASY_ENC_WO_mm7_Cc) */

/* Called by: */
struct zx_str* zx_EASY_ENC_WO_mm7_Cc(struct zx_ctx* c, struct zx_mm7_Cc_s* x )
{
  int len;
  char* buf;
  c->ns_tab = ZX_ALLOC(c, sizeof(zx_ns_tab));
  memcpy(c->ns_tab, zx_ns_tab, sizeof(zx_ns_tab));
  len = zx_LEN_WO_mm7_Cc(c, x );
  buf = ZX_ALLOC(c, len+1);
  return zx_easy_enc_common(c, zx_ENC_WO_mm7_Cc(c, x, buf ), buf, len);
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

#define EL_NAME   mm7_Content
#define EL_STRUCT zx_mm7_Content_s
#define EL_NS     mm7
#define EL_TAG    Content

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

/* FUNC(zx_LEN_SO_mm7_Content) */

/* Compute length of an element (and its subelements). The XML attributes
 * and elements are processed in schema order. */

/* Called by: */
int zx_LEN_SO_mm7_Content(struct zx_ctx* c, struct zx_mm7_Content_s* x )
{
  struct zx_ns_s* pop_seen = 0;
  struct zx_elem_s* se MAYBE_UNUSED;
#if 1 /* NORMALMODE */
  /* *** in simple_elem case should output ns prefix from ns node. */
  int len = sizeof("<mm7:Content")-1 + 1 + sizeof("</mm7:Content>")-1;
  if (c->inc_ns_len)
    len += zx_len_inc_ns(c, &pop_seen);
  len += zx_len_xmlns_if_not_seen(c, zx_ns_tab+zx_xmlns_ix_mm7, &pop_seen);

  len += zx_attr_so_len(x->allowAdaptations, sizeof("allowAdaptations")-1);
  len += zx_attr_so_len(x->href, sizeof("href")-1);
  len += zx_attr_so_len(x->type, sizeof("type")-1);

#else
  /* root node has no begin tag */
  int len = 0;
#endif
  


  len += zx_len_so_common(c, &x->gg);
  zx_pop_seen(pop_seen);
  ENC_LEN_DEBUG(x, "mm7:Content", len);
  return len;
}

/* FUNC(zx_LEN_WO_mm7_Content) */

/* Compute length of an element (and its subelements). The XML attributes
 * and elements are processed in wire order and no assumptions
 * are made about namespace prefixes. */

/* Called by: */
int zx_LEN_WO_mm7_Content(struct zx_ctx* c, struct zx_mm7_Content_s* x )
{
  struct zx_ns_s* pop_seen = 0;
  struct zx_elem_s* se MAYBE_UNUSED;
#if 1 /* NORMALMODE */
  int len = 1 + sizeof("Content")-1 + 1 + 2 + sizeof("Content")-1 + 1;
  
  if (x->gg.g.ns && x->gg.g.ns->prefix_len)
    len += (x->gg.g.ns->prefix_len + 1) * 2;
  if (c->inc_ns_len)
    len += zx_len_inc_ns(c, &pop_seen);
  len += zx_len_xmlns_if_not_seen(c, x->gg.g.ns, &pop_seen);

  len += zx_attr_wo_len(x->allowAdaptations, sizeof("allowAdaptations")-1);
  len += zx_attr_wo_len(x->href, sizeof("href")-1);
  len += zx_attr_wo_len(x->type, sizeof("type")-1);

#else
  /* root node has no begin tag */
  int len = 0;
#endif
  


  len += zx_len_wo_common(c, &x->gg); 
  zx_pop_seen(pop_seen);
  ENC_LEN_DEBUG(x, "mm7:Content", len);
  return len;
}

/* FUNC(zx_ENC_SO_mm7_Content) */

/* Render element into string. The XML attributes and elements are
 * processed in schema order. This is what you generally want for
 * rendering new data structure to a string. The wo pointers are not used. */

/* Called by: */
char* zx_ENC_SO_mm7_Content(struct zx_ctx* c, struct zx_mm7_Content_s* x, char* p )
{
  struct zx_elem_s* se MAYBE_UNUSED;
  struct zx_ns_s* pop_seen = 0;
  ENC_LEN_DEBUG_BASE;
#if 1 /* NORMALMODE */
  /* *** in simple_elem case should output ns prefix from ns node. */
  ZX_OUT_TAG(p, "<mm7:Content");
  if (c->inc_ns)
    p = zx_enc_inc_ns(c, p, &pop_seen);
  p = zx_enc_xmlns_if_not_seen(c, p, zx_ns_tab+zx_xmlns_ix_mm7, &pop_seen);

  p = zx_attr_so_enc(p, x->allowAdaptations, " allowAdaptations=\"", sizeof(" allowAdaptations=\"")-1);
  p = zx_attr_so_enc(p, x->href, " href=\"", sizeof(" href=\"")-1);
  p = zx_attr_so_enc(p, x->type, " type=\"", sizeof(" type=\"")-1);

  p = zx_enc_unknown_attrs(p, x->gg.any_attr);
#else
  /* root node has no begin tag */
#endif
  

  p = zx_enc_so_unknown_elems_and_content(c, p, &x->gg);
  
#if 1 /* NORMALMODE */
  ZX_OUT_CLOSE_TAG(p, "</mm7:Content>");
  zx_pop_seen(pop_seen);
#else
  /* root node has no end tag either */
#endif
  ENC_LEN_DEBUG(x, "mm7:Content", p-enc_base);
  return p;
}

/* FUNC(zx_ENC_WO_mm7_Content) */

/* Render element into string. The XML attributes and elements are
 * processed in wire order by chasing wo pointers. This is what you want for
 * validating signatures on other people's XML documents. */

/* Called by: */
char* zx_ENC_WO_mm7_Content(struct zx_ctx* c, struct zx_mm7_Content_s* x, char* p )
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
  ZX_OUT_MEM(p, "Content", sizeof("Content")-1);
  qq = p;

  /* *** sort the namespaces */
  if (c->inc_ns)
    zx_add_inc_ns(c, &pop_seen);
  zx_add_xmlns_if_not_seen(c, x->gg.g.ns, &pop_seen);

  p = zx_enc_seen(p, pop_seen); 
  p = zx_attr_wo_enc(p, x->allowAdaptations, "allowAdaptations=\"", sizeof("allowAdaptations=\"")-1);
  p = zx_attr_wo_enc(p, x->href, "href=\"", sizeof("href=\"")-1);
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
  ENC_LEN_DEBUG(x, "mm7:Content", p-enc_base);
  return p;
}

/* FUNC(zx_EASY_ENC_SO_mm7_Content) */

/* Called by: */
struct zx_str* zx_EASY_ENC_SO_mm7_Content(struct zx_ctx* c, struct zx_mm7_Content_s* x )
{
  int len;
  char* buf;
  c->ns_tab = ZX_ALLOC(c, sizeof(zx_ns_tab));
  memcpy(c->ns_tab, zx_ns_tab, sizeof(zx_ns_tab));
  len = zx_LEN_SO_mm7_Content(c, x );
  buf = ZX_ALLOC(c, len+1);
  return zx_easy_enc_common(c, zx_ENC_SO_mm7_Content(c, x, buf ), buf, len);
}

/* FUNC(zx_EASY_ENC_WO_mm7_Content) */

/* Called by: */
struct zx_str* zx_EASY_ENC_WO_mm7_Content(struct zx_ctx* c, struct zx_mm7_Content_s* x )
{
  int len;
  char* buf;
  c->ns_tab = ZX_ALLOC(c, sizeof(zx_ns_tab));
  memcpy(c->ns_tab, zx_ns_tab, sizeof(zx_ns_tab));
  len = zx_LEN_WO_mm7_Content(c, x );
  buf = ZX_ALLOC(c, len+1);
  return zx_easy_enc_common(c, zx_ENC_WO_mm7_Content(c, x, buf ), buf, len);
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

#define EL_NAME   mm7_DateTime
#define EL_STRUCT zx_mm7_DateTime_s
#define EL_NS     mm7
#define EL_TAG    DateTime

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

/* FUNC(zx_LEN_SO_mm7_DateTime) */

/* Compute length of an element (and its subelements). The XML attributes
 * and elements are processed in schema order. */

/* Called by: */
int zx_LEN_SO_mm7_DateTime(struct zx_ctx* c, struct zx_mm7_DateTime_s* x )
{
  struct zx_ns_s* pop_seen = 0;
  struct zx_elem_s* se MAYBE_UNUSED;
#if 1 /* NORMALMODE */
  /* *** in simple_elem case should output ns prefix from ns node. */
  int len = sizeof("<mm7:DateTime")-1 + 1 + sizeof("</mm7:DateTime>")-1;
  if (c->inc_ns_len)
    len += zx_len_inc_ns(c, &pop_seen);
  len += zx_len_xmlns_if_not_seen(c, zx_ns_tab+zx_xmlns_ix_mm7, &pop_seen);

  len += zx_attr_so_len(x->sequence, sizeof("sequence")-1);

#else
  /* root node has no begin tag */
  int len = 0;
#endif
  


  len += zx_len_so_common(c, &x->gg);
  zx_pop_seen(pop_seen);
  ENC_LEN_DEBUG(x, "mm7:DateTime", len);
  return len;
}

/* FUNC(zx_LEN_WO_mm7_DateTime) */

/* Compute length of an element (and its subelements). The XML attributes
 * and elements are processed in wire order and no assumptions
 * are made about namespace prefixes. */

/* Called by: */
int zx_LEN_WO_mm7_DateTime(struct zx_ctx* c, struct zx_mm7_DateTime_s* x )
{
  struct zx_ns_s* pop_seen = 0;
  struct zx_elem_s* se MAYBE_UNUSED;
#if 1 /* NORMALMODE */
  int len = 1 + sizeof("DateTime")-1 + 1 + 2 + sizeof("DateTime")-1 + 1;
  
  if (x->gg.g.ns && x->gg.g.ns->prefix_len)
    len += (x->gg.g.ns->prefix_len + 1) * 2;
  if (c->inc_ns_len)
    len += zx_len_inc_ns(c, &pop_seen);
  len += zx_len_xmlns_if_not_seen(c, x->gg.g.ns, &pop_seen);

  len += zx_attr_wo_len(x->sequence, sizeof("sequence")-1);

#else
  /* root node has no begin tag */
  int len = 0;
#endif
  


  len += zx_len_wo_common(c, &x->gg); 
  zx_pop_seen(pop_seen);
  ENC_LEN_DEBUG(x, "mm7:DateTime", len);
  return len;
}

/* FUNC(zx_ENC_SO_mm7_DateTime) */

/* Render element into string. The XML attributes and elements are
 * processed in schema order. This is what you generally want for
 * rendering new data structure to a string. The wo pointers are not used. */

/* Called by: */
char* zx_ENC_SO_mm7_DateTime(struct zx_ctx* c, struct zx_mm7_DateTime_s* x, char* p )
{
  struct zx_elem_s* se MAYBE_UNUSED;
  struct zx_ns_s* pop_seen = 0;
  ENC_LEN_DEBUG_BASE;
#if 1 /* NORMALMODE */
  /* *** in simple_elem case should output ns prefix from ns node. */
  ZX_OUT_TAG(p, "<mm7:DateTime");
  if (c->inc_ns)
    p = zx_enc_inc_ns(c, p, &pop_seen);
  p = zx_enc_xmlns_if_not_seen(c, p, zx_ns_tab+zx_xmlns_ix_mm7, &pop_seen);

  p = zx_attr_so_enc(p, x->sequence, " sequence=\"", sizeof(" sequence=\"")-1);

  p = zx_enc_unknown_attrs(p, x->gg.any_attr);
#else
  /* root node has no begin tag */
#endif
  

  p = zx_enc_so_unknown_elems_and_content(c, p, &x->gg);
  
#if 1 /* NORMALMODE */
  ZX_OUT_CLOSE_TAG(p, "</mm7:DateTime>");
  zx_pop_seen(pop_seen);
#else
  /* root node has no end tag either */
#endif
  ENC_LEN_DEBUG(x, "mm7:DateTime", p-enc_base);
  return p;
}

/* FUNC(zx_ENC_WO_mm7_DateTime) */

/* Render element into string. The XML attributes and elements are
 * processed in wire order by chasing wo pointers. This is what you want for
 * validating signatures on other people's XML documents. */

/* Called by: */
char* zx_ENC_WO_mm7_DateTime(struct zx_ctx* c, struct zx_mm7_DateTime_s* x, char* p )
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
  ZX_OUT_MEM(p, "DateTime", sizeof("DateTime")-1);
  qq = p;

  /* *** sort the namespaces */
  if (c->inc_ns)
    zx_add_inc_ns(c, &pop_seen);
  zx_add_xmlns_if_not_seen(c, x->gg.g.ns, &pop_seen);

  p = zx_enc_seen(p, pop_seen); 
  p = zx_attr_wo_enc(p, x->sequence, "sequence=\"", sizeof("sequence=\"")-1);

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
  ENC_LEN_DEBUG(x, "mm7:DateTime", p-enc_base);
  return p;
}

/* FUNC(zx_EASY_ENC_SO_mm7_DateTime) */

/* Called by: */
struct zx_str* zx_EASY_ENC_SO_mm7_DateTime(struct zx_ctx* c, struct zx_mm7_DateTime_s* x )
{
  int len;
  char* buf;
  c->ns_tab = ZX_ALLOC(c, sizeof(zx_ns_tab));
  memcpy(c->ns_tab, zx_ns_tab, sizeof(zx_ns_tab));
  len = zx_LEN_SO_mm7_DateTime(c, x );
  buf = ZX_ALLOC(c, len+1);
  return zx_easy_enc_common(c, zx_ENC_SO_mm7_DateTime(c, x, buf ), buf, len);
}

/* FUNC(zx_EASY_ENC_WO_mm7_DateTime) */

/* Called by: */
struct zx_str* zx_EASY_ENC_WO_mm7_DateTime(struct zx_ctx* c, struct zx_mm7_DateTime_s* x )
{
  int len;
  char* buf;
  c->ns_tab = ZX_ALLOC(c, sizeof(zx_ns_tab));
  memcpy(c->ns_tab, zx_ns_tab, sizeof(zx_ns_tab));
  len = zx_LEN_WO_mm7_DateTime(c, x );
  buf = ZX_ALLOC(c, len+1);
  return zx_easy_enc_common(c, zx_ENC_WO_mm7_DateTime(c, x, buf ), buf, len);
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

#define EL_NAME   mm7_DeliverReq
#define EL_STRUCT zx_mm7_DeliverReq_s
#define EL_NS     mm7
#define EL_TAG    DeliverReq

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

/* FUNC(zx_LEN_SO_mm7_DeliverReq) */

/* Compute length of an element (and its subelements). The XML attributes
 * and elements are processed in schema order. */

/* Called by: */
int zx_LEN_SO_mm7_DeliverReq(struct zx_ctx* c, struct zx_mm7_DeliverReq_s* x )
{
  struct zx_ns_s* pop_seen = 0;
  struct zx_elem_s* se MAYBE_UNUSED;
#if 1 /* NORMALMODE */
  /* *** in simple_elem case should output ns prefix from ns node. */
  int len = sizeof("<mm7:DeliverReq")-1 + 1 + sizeof("</mm7:DeliverReq>")-1;
  if (c->inc_ns_len)
    len += zx_len_inc_ns(c, &pop_seen);
  len += zx_len_xmlns_if_not_seen(c, zx_ns_tab+zx_xmlns_ix_mm7, &pop_seen);


#else
  /* root node has no begin tag */
  int len = 0;
#endif
  
  for (se = x->MM7Version; se; se = (struct zx_elem_s*)se->g.n)
    len += zx_LEN_SO_simple_elem(c,se, sizeof("mm7:MM7Version")-1, zx_ns_tab+zx_xmlns_ix_mm7);
  for (se = x->MMSRelayServerID; se; se = (struct zx_elem_s*)se->g.n)
    len += zx_LEN_SO_simple_elem(c,se, sizeof("mm7:MMSRelayServerID")-1, zx_ns_tab+zx_xmlns_ix_mm7);
  {
      struct zx_mm7_Extension_s* e;
      for (e = x->Extension; e; e = (struct zx_mm7_Extension_s*)e->gg.g.n)
	  len += zx_LEN_SO_mm7_Extension(c, e);
  }
  for (se = x->VASPID; se; se = (struct zx_elem_s*)se->g.n)
    len += zx_LEN_SO_simple_elem(c,se, sizeof("mm7:VASPID")-1, zx_ns_tab+zx_xmlns_ix_mm7);
  for (se = x->VASID; se; se = (struct zx_elem_s*)se->g.n)
    len += zx_LEN_SO_simple_elem(c,se, sizeof("mm7:VASID")-1, zx_ns_tab+zx_xmlns_ix_mm7);
  for (se = x->LinkedID; se; se = (struct zx_elem_s*)se->g.n)
    len += zx_LEN_SO_simple_elem(c,se, sizeof("mm7:LinkedID")-1, zx_ns_tab+zx_xmlns_ix_mm7);
  {
      struct zx_mm7_Sender_s* e;
      for (e = x->Sender; e; e = (struct zx_mm7_Sender_s*)e->gg.g.n)
	  len += zx_LEN_SO_mm7_Sender(c, e);
  }
  {
      struct zx_mm7_Recipients_s* e;
      for (e = x->Recipients; e; e = (struct zx_mm7_Recipients_s*)e->gg.g.n)
	  len += zx_LEN_SO_mm7_Recipients(c, e);
  }
  {
      struct zx_mm7_Previouslysentby_s* e;
      for (e = x->Previouslysentby; e; e = (struct zx_mm7_Previouslysentby_s*)e->gg.g.n)
	  len += zx_LEN_SO_mm7_Previouslysentby(c, e);
  }
  {
      struct zx_mm7_Previouslysentdateandtime_s* e;
      for (e = x->Previouslysentdateandtime; e; e = (struct zx_mm7_Previouslysentdateandtime_s*)e->gg.g.n)
	  len += zx_LEN_SO_mm7_Previouslysentdateandtime(c, e);
  }
  for (se = x->SenderSPI; se; se = (struct zx_elem_s*)se->g.n)
    len += zx_LEN_SO_simple_elem(c,se, sizeof("mm7:SenderSPI")-1, zx_ns_tab+zx_xmlns_ix_mm7);
  for (se = x->RecipientSPI; se; se = (struct zx_elem_s*)se->g.n)
    len += zx_LEN_SO_simple_elem(c,se, sizeof("mm7:RecipientSPI")-1, zx_ns_tab+zx_xmlns_ix_mm7);
  for (se = x->TimeStamp; se; se = (struct zx_elem_s*)se->g.n)
    len += zx_LEN_SO_simple_elem(c,se, sizeof("mm7:TimeStamp")-1, zx_ns_tab+zx_xmlns_ix_mm7);
  for (se = x->ReplyChargingID; se; se = (struct zx_elem_s*)se->g.n)
    len += zx_LEN_SO_simple_elem(c,se, sizeof("mm7:ReplyChargingID")-1, zx_ns_tab+zx_xmlns_ix_mm7);
  for (se = x->Priority; se; se = (struct zx_elem_s*)se->g.n)
    len += zx_LEN_SO_simple_elem(c,se, sizeof("mm7:Priority")-1, zx_ns_tab+zx_xmlns_ix_mm7);
  for (se = x->Subject; se; se = (struct zx_elem_s*)se->g.n)
    len += zx_LEN_SO_simple_elem(c,se, sizeof("mm7:Subject")-1, zx_ns_tab+zx_xmlns_ix_mm7);
  for (se = x->ApplicID; se; se = (struct zx_elem_s*)se->g.n)
    len += zx_LEN_SO_simple_elem(c,se, sizeof("mm7:ApplicID")-1, zx_ns_tab+zx_xmlns_ix_mm7);
  for (se = x->ReplyApplicID; se; se = (struct zx_elem_s*)se->g.n)
    len += zx_LEN_SO_simple_elem(c,se, sizeof("mm7:ReplyApplicID")-1, zx_ns_tab+zx_xmlns_ix_mm7);
  for (se = x->AuxApplicInfo; se; se = (struct zx_elem_s*)se->g.n)
    len += zx_LEN_SO_simple_elem(c,se, sizeof("mm7:AuxApplicInfo")-1, zx_ns_tab+zx_xmlns_ix_mm7);
  {
      struct zx_mm7_UACapabilities_s* e;
      for (e = x->UACapabilities; e; e = (struct zx_mm7_UACapabilities_s*)e->gg.g.n)
	  len += zx_LEN_SO_mm7_UACapabilities(c, e);
  }
  {
      struct zx_mm7_Content_s* e;
      for (e = x->Content; e; e = (struct zx_mm7_Content_s*)e->gg.g.n)
	  len += zx_LEN_SO_mm7_Content(c, e);
  }
  {
      struct zx_mm7_AdditionalInformation_s* e;
      for (e = x->AdditionalInformation; e; e = (struct zx_mm7_AdditionalInformation_s*)e->gg.g.n)
	  len += zx_LEN_SO_mm7_AdditionalInformation(c, e);
  }
  {
      struct zx_mm7_MessageExtraData_s* e;
      for (e = x->MessageExtraData; e; e = (struct zx_mm7_MessageExtraData_s*)e->gg.g.n)
	  len += zx_LEN_SO_mm7_MessageExtraData(c, e);
  }


  len += zx_len_so_common(c, &x->gg);
  zx_pop_seen(pop_seen);
  ENC_LEN_DEBUG(x, "mm7:DeliverReq", len);
  return len;
}

/* FUNC(zx_LEN_WO_mm7_DeliverReq) */

/* Compute length of an element (and its subelements). The XML attributes
 * and elements are processed in wire order and no assumptions
 * are made about namespace prefixes. */

/* Called by: */
int zx_LEN_WO_mm7_DeliverReq(struct zx_ctx* c, struct zx_mm7_DeliverReq_s* x )
{
  struct zx_ns_s* pop_seen = 0;
  struct zx_elem_s* se MAYBE_UNUSED;
#if 1 /* NORMALMODE */
  int len = 1 + sizeof("DeliverReq")-1 + 1 + 2 + sizeof("DeliverReq")-1 + 1;
  
  if (x->gg.g.ns && x->gg.g.ns->prefix_len)
    len += (x->gg.g.ns->prefix_len + 1) * 2;
  if (c->inc_ns_len)
    len += zx_len_inc_ns(c, &pop_seen);
  len += zx_len_xmlns_if_not_seen(c, x->gg.g.ns, &pop_seen);


#else
  /* root node has no begin tag */
  int len = 0;
#endif
  
  for (se = x->MM7Version; se; se = (struct zx_elem_s*)se->g.n)
    len += zx_LEN_WO_simple_elem(c, se, sizeof("MM7Version")-1);
  for (se = x->MMSRelayServerID; se; se = (struct zx_elem_s*)se->g.n)
    len += zx_LEN_WO_simple_elem(c, se, sizeof("MMSRelayServerID")-1);
  {
      struct zx_mm7_Extension_s* e;
      for (e = x->Extension; e; e = (struct zx_mm7_Extension_s*)e->gg.g.n)
	  len += zx_LEN_WO_mm7_Extension(c, e);
  }
  for (se = x->VASPID; se; se = (struct zx_elem_s*)se->g.n)
    len += zx_LEN_WO_simple_elem(c, se, sizeof("VASPID")-1);
  for (se = x->VASID; se; se = (struct zx_elem_s*)se->g.n)
    len += zx_LEN_WO_simple_elem(c, se, sizeof("VASID")-1);
  for (se = x->LinkedID; se; se = (struct zx_elem_s*)se->g.n)
    len += zx_LEN_WO_simple_elem(c, se, sizeof("LinkedID")-1);
  {
      struct zx_mm7_Sender_s* e;
      for (e = x->Sender; e; e = (struct zx_mm7_Sender_s*)e->gg.g.n)
	  len += zx_LEN_WO_mm7_Sender(c, e);
  }
  {
      struct zx_mm7_Recipients_s* e;
      for (e = x->Recipients; e; e = (struct zx_mm7_Recipients_s*)e->gg.g.n)
	  len += zx_LEN_WO_mm7_Recipients(c, e);
  }
  {
      struct zx_mm7_Previouslysentby_s* e;
      for (e = x->Previouslysentby; e; e = (struct zx_mm7_Previouslysentby_s*)e->gg.g.n)
	  len += zx_LEN_WO_mm7_Previouslysentby(c, e);
  }
  {
      struct zx_mm7_Previouslysentdateandtime_s* e;
      for (e = x->Previouslysentdateandtime; e; e = (struct zx_mm7_Previouslysentdateandtime_s*)e->gg.g.n)
	  len += zx_LEN_WO_mm7_Previouslysentdateandtime(c, e);
  }
  for (se = x->SenderSPI; se; se = (struct zx_elem_s*)se->g.n)
    len += zx_LEN_WO_simple_elem(c, se, sizeof("SenderSPI")-1);
  for (se = x->RecipientSPI; se; se = (struct zx_elem_s*)se->g.n)
    len += zx_LEN_WO_simple_elem(c, se, sizeof("RecipientSPI")-1);
  for (se = x->TimeStamp; se; se = (struct zx_elem_s*)se->g.n)
    len += zx_LEN_WO_simple_elem(c, se, sizeof("TimeStamp")-1);
  for (se = x->ReplyChargingID; se; se = (struct zx_elem_s*)se->g.n)
    len += zx_LEN_WO_simple_elem(c, se, sizeof("ReplyChargingID")-1);
  for (se = x->Priority; se; se = (struct zx_elem_s*)se->g.n)
    len += zx_LEN_WO_simple_elem(c, se, sizeof("Priority")-1);
  for (se = x->Subject; se; se = (struct zx_elem_s*)se->g.n)
    len += zx_LEN_WO_simple_elem(c, se, sizeof("Subject")-1);
  for (se = x->ApplicID; se; se = (struct zx_elem_s*)se->g.n)
    len += zx_LEN_WO_simple_elem(c, se, sizeof("ApplicID")-1);
  for (se = x->ReplyApplicID; se; se = (struct zx_elem_s*)se->g.n)
    len += zx_LEN_WO_simple_elem(c, se, sizeof("ReplyApplicID")-1);
  for (se = x->AuxApplicInfo; se; se = (struct zx_elem_s*)se->g.n)
    len += zx_LEN_WO_simple_elem(c, se, sizeof("AuxApplicInfo")-1);
  {
      struct zx_mm7_UACapabilities_s* e;
      for (e = x->UACapabilities; e; e = (struct zx_mm7_UACapabilities_s*)e->gg.g.n)
	  len += zx_LEN_WO_mm7_UACapabilities(c, e);
  }
  {
      struct zx_mm7_Content_s* e;
      for (e = x->Content; e; e = (struct zx_mm7_Content_s*)e->gg.g.n)
	  len += zx_LEN_WO_mm7_Content(c, e);
  }
  {
      struct zx_mm7_AdditionalInformation_s* e;
      for (e = x->AdditionalInformation; e; e = (struct zx_mm7_AdditionalInformation_s*)e->gg.g.n)
	  len += zx_LEN_WO_mm7_AdditionalInformation(c, e);
  }
  {
      struct zx_mm7_MessageExtraData_s* e;
      for (e = x->MessageExtraData; e; e = (struct zx_mm7_MessageExtraData_s*)e->gg.g.n)
	  len += zx_LEN_WO_mm7_MessageExtraData(c, e);
  }


  len += zx_len_wo_common(c, &x->gg); 
  zx_pop_seen(pop_seen);
  ENC_LEN_DEBUG(x, "mm7:DeliverReq", len);
  return len;
}

/* FUNC(zx_ENC_SO_mm7_DeliverReq) */

/* Render element into string. The XML attributes and elements are
 * processed in schema order. This is what you generally want for
 * rendering new data structure to a string. The wo pointers are not used. */

/* Called by: */
char* zx_ENC_SO_mm7_DeliverReq(struct zx_ctx* c, struct zx_mm7_DeliverReq_s* x, char* p )
{
  struct zx_elem_s* se MAYBE_UNUSED;
  struct zx_ns_s* pop_seen = 0;
  ENC_LEN_DEBUG_BASE;
#if 1 /* NORMALMODE */
  /* *** in simple_elem case should output ns prefix from ns node. */
  ZX_OUT_TAG(p, "<mm7:DeliverReq");
  if (c->inc_ns)
    p = zx_enc_inc_ns(c, p, &pop_seen);
  p = zx_enc_xmlns_if_not_seen(c, p, zx_ns_tab+zx_xmlns_ix_mm7, &pop_seen);


  p = zx_enc_unknown_attrs(p, x->gg.any_attr);
#else
  /* root node has no begin tag */
#endif
  
  for (se = x->MM7Version; se; se = (struct zx_elem_s*)se->g.n)
    p = zx_ENC_SO_simple_elem(c, se, p, "mm7:MM7Version", sizeof("mm7:MM7Version")-1, zx_ns_tab+zx_xmlns_ix_mm7);
  for (se = x->MMSRelayServerID; se; se = (struct zx_elem_s*)se->g.n)
    p = zx_ENC_SO_simple_elem(c, se, p, "mm7:MMSRelayServerID", sizeof("mm7:MMSRelayServerID")-1, zx_ns_tab+zx_xmlns_ix_mm7);
  {
      struct zx_mm7_Extension_s* e;
      for (e = x->Extension; e; e = (struct zx_mm7_Extension_s*)e->gg.g.n)
	  p = zx_ENC_SO_mm7_Extension(c, e, p);
  }
  for (se = x->VASPID; se; se = (struct zx_elem_s*)se->g.n)
    p = zx_ENC_SO_simple_elem(c, se, p, "mm7:VASPID", sizeof("mm7:VASPID")-1, zx_ns_tab+zx_xmlns_ix_mm7);
  for (se = x->VASID; se; se = (struct zx_elem_s*)se->g.n)
    p = zx_ENC_SO_simple_elem(c, se, p, "mm7:VASID", sizeof("mm7:VASID")-1, zx_ns_tab+zx_xmlns_ix_mm7);
  for (se = x->LinkedID; se; se = (struct zx_elem_s*)se->g.n)
    p = zx_ENC_SO_simple_elem(c, se, p, "mm7:LinkedID", sizeof("mm7:LinkedID")-1, zx_ns_tab+zx_xmlns_ix_mm7);
  {
      struct zx_mm7_Sender_s* e;
      for (e = x->Sender; e; e = (struct zx_mm7_Sender_s*)e->gg.g.n)
	  p = zx_ENC_SO_mm7_Sender(c, e, p);
  }
  {
      struct zx_mm7_Recipients_s* e;
      for (e = x->Recipients; e; e = (struct zx_mm7_Recipients_s*)e->gg.g.n)
	  p = zx_ENC_SO_mm7_Recipients(c, e, p);
  }
  {
      struct zx_mm7_Previouslysentby_s* e;
      for (e = x->Previouslysentby; e; e = (struct zx_mm7_Previouslysentby_s*)e->gg.g.n)
	  p = zx_ENC_SO_mm7_Previouslysentby(c, e, p);
  }
  {
      struct zx_mm7_Previouslysentdateandtime_s* e;
      for (e = x->Previouslysentdateandtime; e; e = (struct zx_mm7_Previouslysentdateandtime_s*)e->gg.g.n)
	  p = zx_ENC_SO_mm7_Previouslysentdateandtime(c, e, p);
  }
  for (se = x->SenderSPI; se; se = (struct zx_elem_s*)se->g.n)
    p = zx_ENC_SO_simple_elem(c, se, p, "mm7:SenderSPI", sizeof("mm7:SenderSPI")-1, zx_ns_tab+zx_xmlns_ix_mm7);
  for (se = x->RecipientSPI; se; se = (struct zx_elem_s*)se->g.n)
    p = zx_ENC_SO_simple_elem(c, se, p, "mm7:RecipientSPI", sizeof("mm7:RecipientSPI")-1, zx_ns_tab+zx_xmlns_ix_mm7);
  for (se = x->TimeStamp; se; se = (struct zx_elem_s*)se->g.n)
    p = zx_ENC_SO_simple_elem(c, se, p, "mm7:TimeStamp", sizeof("mm7:TimeStamp")-1, zx_ns_tab+zx_xmlns_ix_mm7);
  for (se = x->ReplyChargingID; se; se = (struct zx_elem_s*)se->g.n)
    p = zx_ENC_SO_simple_elem(c, se, p, "mm7:ReplyChargingID", sizeof("mm7:ReplyChargingID")-1, zx_ns_tab+zx_xmlns_ix_mm7);
  for (se = x->Priority; se; se = (struct zx_elem_s*)se->g.n)
    p = zx_ENC_SO_simple_elem(c, se, p, "mm7:Priority", sizeof("mm7:Priority")-1, zx_ns_tab+zx_xmlns_ix_mm7);
  for (se = x->Subject; se; se = (struct zx_elem_s*)se->g.n)
    p = zx_ENC_SO_simple_elem(c, se, p, "mm7:Subject", sizeof("mm7:Subject")-1, zx_ns_tab+zx_xmlns_ix_mm7);
  for (se = x->ApplicID; se; se = (struct zx_elem_s*)se->g.n)
    p = zx_ENC_SO_simple_elem(c, se, p, "mm7:ApplicID", sizeof("mm7:ApplicID")-1, zx_ns_tab+zx_xmlns_ix_mm7);
  for (se = x->ReplyApplicID; se; se = (struct zx_elem_s*)se->g.n)
    p = zx_ENC_SO_simple_elem(c, se, p, "mm7:ReplyApplicID", sizeof("mm7:ReplyApplicID")-1, zx_ns_tab+zx_xmlns_ix_mm7);
  for (se = x->AuxApplicInfo; se; se = (struct zx_elem_s*)se->g.n)
    p = zx_ENC_SO_simple_elem(c, se, p, "mm7:AuxApplicInfo", sizeof("mm7:AuxApplicInfo")-1, zx_ns_tab+zx_xmlns_ix_mm7);
  {
      struct zx_mm7_UACapabilities_s* e;
      for (e = x->UACapabilities; e; e = (struct zx_mm7_UACapabilities_s*)e->gg.g.n)
	  p = zx_ENC_SO_mm7_UACapabilities(c, e, p);
  }
  {
      struct zx_mm7_Content_s* e;
      for (e = x->Content; e; e = (struct zx_mm7_Content_s*)e->gg.g.n)
	  p = zx_ENC_SO_mm7_Content(c, e, p);
  }
  {
      struct zx_mm7_AdditionalInformation_s* e;
      for (e = x->AdditionalInformation; e; e = (struct zx_mm7_AdditionalInformation_s*)e->gg.g.n)
	  p = zx_ENC_SO_mm7_AdditionalInformation(c, e, p);
  }
  {
      struct zx_mm7_MessageExtraData_s* e;
      for (e = x->MessageExtraData; e; e = (struct zx_mm7_MessageExtraData_s*)e->gg.g.n)
	  p = zx_ENC_SO_mm7_MessageExtraData(c, e, p);
  }

  p = zx_enc_so_unknown_elems_and_content(c, p, &x->gg);
  
#if 1 /* NORMALMODE */
  ZX_OUT_CLOSE_TAG(p, "</mm7:DeliverReq>");
  zx_pop_seen(pop_seen);
#else
  /* root node has no end tag either */
#endif
  ENC_LEN_DEBUG(x, "mm7:DeliverReq", p-enc_base);
  return p;
}

/* FUNC(zx_ENC_WO_mm7_DeliverReq) */

/* Render element into string. The XML attributes and elements are
 * processed in wire order by chasing wo pointers. This is what you want for
 * validating signatures on other people's XML documents. */

/* Called by: */
char* zx_ENC_WO_mm7_DeliverReq(struct zx_ctx* c, struct zx_mm7_DeliverReq_s* x, char* p )
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
  ZX_OUT_MEM(p, "DeliverReq", sizeof("DeliverReq")-1);
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
  ENC_LEN_DEBUG(x, "mm7:DeliverReq", p-enc_base);
  return p;
}

/* FUNC(zx_EASY_ENC_SO_mm7_DeliverReq) */

/* Called by: */
struct zx_str* zx_EASY_ENC_SO_mm7_DeliverReq(struct zx_ctx* c, struct zx_mm7_DeliverReq_s* x )
{
  int len;
  char* buf;
  c->ns_tab = ZX_ALLOC(c, sizeof(zx_ns_tab));
  memcpy(c->ns_tab, zx_ns_tab, sizeof(zx_ns_tab));
  len = zx_LEN_SO_mm7_DeliverReq(c, x );
  buf = ZX_ALLOC(c, len+1);
  return zx_easy_enc_common(c, zx_ENC_SO_mm7_DeliverReq(c, x, buf ), buf, len);
}

/* FUNC(zx_EASY_ENC_WO_mm7_DeliverReq) */

/* Called by: */
struct zx_str* zx_EASY_ENC_WO_mm7_DeliverReq(struct zx_ctx* c, struct zx_mm7_DeliverReq_s* x )
{
  int len;
  char* buf;
  c->ns_tab = ZX_ALLOC(c, sizeof(zx_ns_tab));
  memcpy(c->ns_tab, zx_ns_tab, sizeof(zx_ns_tab));
  len = zx_LEN_WO_mm7_DeliverReq(c, x );
  buf = ZX_ALLOC(c, len+1);
  return zx_easy_enc_common(c, zx_ENC_WO_mm7_DeliverReq(c, x, buf ), buf, len);
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

#define EL_NAME   mm7_DeliverRsp
#define EL_STRUCT zx_mm7_DeliverRsp_s
#define EL_NS     mm7
#define EL_TAG    DeliverRsp

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

/* FUNC(zx_LEN_SO_mm7_DeliverRsp) */

/* Compute length of an element (and its subelements). The XML attributes
 * and elements are processed in schema order. */

/* Called by: */
int zx_LEN_SO_mm7_DeliverRsp(struct zx_ctx* c, struct zx_mm7_DeliverRsp_s* x )
{
  struct zx_ns_s* pop_seen = 0;
  struct zx_elem_s* se MAYBE_UNUSED;
#if 1 /* NORMALMODE */
  /* *** in simple_elem case should output ns prefix from ns node. */
  int len = sizeof("<mm7:DeliverRsp")-1 + 1 + sizeof("</mm7:DeliverRsp>")-1;
  if (c->inc_ns_len)
    len += zx_len_inc_ns(c, &pop_seen);
  len += zx_len_xmlns_if_not_seen(c, zx_ns_tab+zx_xmlns_ix_mm7, &pop_seen);


#else
  /* root node has no begin tag */
  int len = 0;
#endif
  
  for (se = x->MM7Version; se; se = (struct zx_elem_s*)se->g.n)
    len += zx_LEN_SO_simple_elem(c,se, sizeof("mm7:MM7Version")-1, zx_ns_tab+zx_xmlns_ix_mm7);
  {
      struct zx_mm7_Status_s* e;
      for (e = x->Status; e; e = (struct zx_mm7_Status_s*)e->gg.g.n)
	  len += zx_LEN_SO_mm7_Status(c, e);
  }
  {
      struct zx_mm7_Extension_s* e;
      for (e = x->Extension; e; e = (struct zx_mm7_Extension_s*)e->gg.g.n)
	  len += zx_LEN_SO_mm7_Extension(c, e);
  }
  {
      struct zx_mm7_ServiceCode_s* e;
      for (e = x->ServiceCode; e; e = (struct zx_mm7_ServiceCode_s*)e->gg.g.n)
	  len += zx_LEN_SO_mm7_ServiceCode(c, e);
  }


  len += zx_len_so_common(c, &x->gg);
  zx_pop_seen(pop_seen);
  ENC_LEN_DEBUG(x, "mm7:DeliverRsp", len);
  return len;
}

/* FUNC(zx_LEN_WO_mm7_DeliverRsp) */

/* Compute length of an element (and its subelements). The XML attributes
 * and elements are processed in wire order and no assumptions
 * are made about namespace prefixes. */

/* Called by: */
int zx_LEN_WO_mm7_DeliverRsp(struct zx_ctx* c, struct zx_mm7_DeliverRsp_s* x )
{
  struct zx_ns_s* pop_seen = 0;
  struct zx_elem_s* se MAYBE_UNUSED;
#if 1 /* NORMALMODE */
  int len = 1 + sizeof("DeliverRsp")-1 + 1 + 2 + sizeof("DeliverRsp")-1 + 1;
  
  if (x->gg.g.ns && x->gg.g.ns->prefix_len)
    len += (x->gg.g.ns->prefix_len + 1) * 2;
  if (c->inc_ns_len)
    len += zx_len_inc_ns(c, &pop_seen);
  len += zx_len_xmlns_if_not_seen(c, x->gg.g.ns, &pop_seen);


#else
  /* root node has no begin tag */
  int len = 0;
#endif
  
  for (se = x->MM7Version; se; se = (struct zx_elem_s*)se->g.n)
    len += zx_LEN_WO_simple_elem(c, se, sizeof("MM7Version")-1);
  {
      struct zx_mm7_Status_s* e;
      for (e = x->Status; e; e = (struct zx_mm7_Status_s*)e->gg.g.n)
	  len += zx_LEN_WO_mm7_Status(c, e);
  }
  {
      struct zx_mm7_Extension_s* e;
      for (e = x->Extension; e; e = (struct zx_mm7_Extension_s*)e->gg.g.n)
	  len += zx_LEN_WO_mm7_Extension(c, e);
  }
  {
      struct zx_mm7_ServiceCode_s* e;
      for (e = x->ServiceCode; e; e = (struct zx_mm7_ServiceCode_s*)e->gg.g.n)
	  len += zx_LEN_WO_mm7_ServiceCode(c, e);
  }


  len += zx_len_wo_common(c, &x->gg); 
  zx_pop_seen(pop_seen);
  ENC_LEN_DEBUG(x, "mm7:DeliverRsp", len);
  return len;
}

/* FUNC(zx_ENC_SO_mm7_DeliverRsp) */

/* Render element into string. The XML attributes and elements are
 * processed in schema order. This is what you generally want for
 * rendering new data structure to a string. The wo pointers are not used. */

/* Called by: */
char* zx_ENC_SO_mm7_DeliverRsp(struct zx_ctx* c, struct zx_mm7_DeliverRsp_s* x, char* p )
{
  struct zx_elem_s* se MAYBE_UNUSED;
  struct zx_ns_s* pop_seen = 0;
  ENC_LEN_DEBUG_BASE;
#if 1 /* NORMALMODE */
  /* *** in simple_elem case should output ns prefix from ns node. */
  ZX_OUT_TAG(p, "<mm7:DeliverRsp");
  if (c->inc_ns)
    p = zx_enc_inc_ns(c, p, &pop_seen);
  p = zx_enc_xmlns_if_not_seen(c, p, zx_ns_tab+zx_xmlns_ix_mm7, &pop_seen);


  p = zx_enc_unknown_attrs(p, x->gg.any_attr);
#else
  /* root node has no begin tag */
#endif
  
  for (se = x->MM7Version; se; se = (struct zx_elem_s*)se->g.n)
    p = zx_ENC_SO_simple_elem(c, se, p, "mm7:MM7Version", sizeof("mm7:MM7Version")-1, zx_ns_tab+zx_xmlns_ix_mm7);
  {
      struct zx_mm7_Status_s* e;
      for (e = x->Status; e; e = (struct zx_mm7_Status_s*)e->gg.g.n)
	  p = zx_ENC_SO_mm7_Status(c, e, p);
  }
  {
      struct zx_mm7_Extension_s* e;
      for (e = x->Extension; e; e = (struct zx_mm7_Extension_s*)e->gg.g.n)
	  p = zx_ENC_SO_mm7_Extension(c, e, p);
  }
  {
      struct zx_mm7_ServiceCode_s* e;
      for (e = x->ServiceCode; e; e = (struct zx_mm7_ServiceCode_s*)e->gg.g.n)
	  p = zx_ENC_SO_mm7_ServiceCode(c, e, p);
  }

  p = zx_enc_so_unknown_elems_and_content(c, p, &x->gg);
  
#if 1 /* NORMALMODE */
  ZX_OUT_CLOSE_TAG(p, "</mm7:DeliverRsp>");
  zx_pop_seen(pop_seen);
#else
  /* root node has no end tag either */
#endif
  ENC_LEN_DEBUG(x, "mm7:DeliverRsp", p-enc_base);
  return p;
}

/* FUNC(zx_ENC_WO_mm7_DeliverRsp) */

/* Render element into string. The XML attributes and elements are
 * processed in wire order by chasing wo pointers. This is what you want for
 * validating signatures on other people's XML documents. */

/* Called by: */
char* zx_ENC_WO_mm7_DeliverRsp(struct zx_ctx* c, struct zx_mm7_DeliverRsp_s* x, char* p )
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
  ZX_OUT_MEM(p, "DeliverRsp", sizeof("DeliverRsp")-1);
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
  ENC_LEN_DEBUG(x, "mm7:DeliverRsp", p-enc_base);
  return p;
}

/* FUNC(zx_EASY_ENC_SO_mm7_DeliverRsp) */

/* Called by: */
struct zx_str* zx_EASY_ENC_SO_mm7_DeliverRsp(struct zx_ctx* c, struct zx_mm7_DeliverRsp_s* x )
{
  int len;
  char* buf;
  c->ns_tab = ZX_ALLOC(c, sizeof(zx_ns_tab));
  memcpy(c->ns_tab, zx_ns_tab, sizeof(zx_ns_tab));
  len = zx_LEN_SO_mm7_DeliverRsp(c, x );
  buf = ZX_ALLOC(c, len+1);
  return zx_easy_enc_common(c, zx_ENC_SO_mm7_DeliverRsp(c, x, buf ), buf, len);
}

/* FUNC(zx_EASY_ENC_WO_mm7_DeliverRsp) */

/* Called by: */
struct zx_str* zx_EASY_ENC_WO_mm7_DeliverRsp(struct zx_ctx* c, struct zx_mm7_DeliverRsp_s* x )
{
  int len;
  char* buf;
  c->ns_tab = ZX_ALLOC(c, sizeof(zx_ns_tab));
  memcpy(c->ns_tab, zx_ns_tab, sizeof(zx_ns_tab));
  len = zx_LEN_WO_mm7_DeliverRsp(c, x );
  buf = ZX_ALLOC(c, len+1);
  return zx_easy_enc_common(c, zx_ENC_WO_mm7_DeliverRsp(c, x, buf ), buf, len);
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

#define EL_NAME   mm7_DeliveryCondition
#define EL_STRUCT zx_mm7_DeliveryCondition_s
#define EL_NS     mm7
#define EL_TAG    DeliveryCondition

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

/* FUNC(zx_LEN_SO_mm7_DeliveryCondition) */

/* Compute length of an element (and its subelements). The XML attributes
 * and elements are processed in schema order. */

/* Called by: */
int zx_LEN_SO_mm7_DeliveryCondition(struct zx_ctx* c, struct zx_mm7_DeliveryCondition_s* x )
{
  struct zx_ns_s* pop_seen = 0;
  struct zx_elem_s* se MAYBE_UNUSED;
#if 1 /* NORMALMODE */
  /* *** in simple_elem case should output ns prefix from ns node. */
  int len = sizeof("<mm7:DeliveryCondition")-1 + 1 + sizeof("</mm7:DeliveryCondition>")-1;
  if (c->inc_ns_len)
    len += zx_len_inc_ns(c, &pop_seen);
  len += zx_len_xmlns_if_not_seen(c, zx_ns_tab+zx_xmlns_ix_mm7, &pop_seen);


#else
  /* root node has no begin tag */
  int len = 0;
#endif
  
  for (se = x->DC; se; se = (struct zx_elem_s*)se->g.n)
    len += zx_LEN_SO_simple_elem(c,se, sizeof("mm7:DC")-1, zx_ns_tab+zx_xmlns_ix_mm7);


  len += zx_len_so_common(c, &x->gg);
  zx_pop_seen(pop_seen);
  ENC_LEN_DEBUG(x, "mm7:DeliveryCondition", len);
  return len;
}

/* FUNC(zx_LEN_WO_mm7_DeliveryCondition) */

/* Compute length of an element (and its subelements). The XML attributes
 * and elements are processed in wire order and no assumptions
 * are made about namespace prefixes. */

/* Called by: */
int zx_LEN_WO_mm7_DeliveryCondition(struct zx_ctx* c, struct zx_mm7_DeliveryCondition_s* x )
{
  struct zx_ns_s* pop_seen = 0;
  struct zx_elem_s* se MAYBE_UNUSED;
#if 1 /* NORMALMODE */
  int len = 1 + sizeof("DeliveryCondition")-1 + 1 + 2 + sizeof("DeliveryCondition")-1 + 1;
  
  if (x->gg.g.ns && x->gg.g.ns->prefix_len)
    len += (x->gg.g.ns->prefix_len + 1) * 2;
  if (c->inc_ns_len)
    len += zx_len_inc_ns(c, &pop_seen);
  len += zx_len_xmlns_if_not_seen(c, x->gg.g.ns, &pop_seen);


#else
  /* root node has no begin tag */
  int len = 0;
#endif
  
  for (se = x->DC; se; se = (struct zx_elem_s*)se->g.n)
    len += zx_LEN_WO_simple_elem(c, se, sizeof("DC")-1);


  len += zx_len_wo_common(c, &x->gg); 
  zx_pop_seen(pop_seen);
  ENC_LEN_DEBUG(x, "mm7:DeliveryCondition", len);
  return len;
}

/* FUNC(zx_ENC_SO_mm7_DeliveryCondition) */

/* Render element into string. The XML attributes and elements are
 * processed in schema order. This is what you generally want for
 * rendering new data structure to a string. The wo pointers are not used. */

/* Called by: */
char* zx_ENC_SO_mm7_DeliveryCondition(struct zx_ctx* c, struct zx_mm7_DeliveryCondition_s* x, char* p )
{
  struct zx_elem_s* se MAYBE_UNUSED;
  struct zx_ns_s* pop_seen = 0;
  ENC_LEN_DEBUG_BASE;
#if 1 /* NORMALMODE */
  /* *** in simple_elem case should output ns prefix from ns node. */
  ZX_OUT_TAG(p, "<mm7:DeliveryCondition");
  if (c->inc_ns)
    p = zx_enc_inc_ns(c, p, &pop_seen);
  p = zx_enc_xmlns_if_not_seen(c, p, zx_ns_tab+zx_xmlns_ix_mm7, &pop_seen);


  p = zx_enc_unknown_attrs(p, x->gg.any_attr);
#else
  /* root node has no begin tag */
#endif
  
  for (se = x->DC; se; se = (struct zx_elem_s*)se->g.n)
    p = zx_ENC_SO_simple_elem(c, se, p, "mm7:DC", sizeof("mm7:DC")-1, zx_ns_tab+zx_xmlns_ix_mm7);

  p = zx_enc_so_unknown_elems_and_content(c, p, &x->gg);
  
#if 1 /* NORMALMODE */
  ZX_OUT_CLOSE_TAG(p, "</mm7:DeliveryCondition>");
  zx_pop_seen(pop_seen);
#else
  /* root node has no end tag either */
#endif
  ENC_LEN_DEBUG(x, "mm7:DeliveryCondition", p-enc_base);
  return p;
}

/* FUNC(zx_ENC_WO_mm7_DeliveryCondition) */

/* Render element into string. The XML attributes and elements are
 * processed in wire order by chasing wo pointers. This is what you want for
 * validating signatures on other people's XML documents. */

/* Called by: */
char* zx_ENC_WO_mm7_DeliveryCondition(struct zx_ctx* c, struct zx_mm7_DeliveryCondition_s* x, char* p )
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
  ZX_OUT_MEM(p, "DeliveryCondition", sizeof("DeliveryCondition")-1);
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
  ENC_LEN_DEBUG(x, "mm7:DeliveryCondition", p-enc_base);
  return p;
}

/* FUNC(zx_EASY_ENC_SO_mm7_DeliveryCondition) */

/* Called by: */
struct zx_str* zx_EASY_ENC_SO_mm7_DeliveryCondition(struct zx_ctx* c, struct zx_mm7_DeliveryCondition_s* x )
{
  int len;
  char* buf;
  c->ns_tab = ZX_ALLOC(c, sizeof(zx_ns_tab));
  memcpy(c->ns_tab, zx_ns_tab, sizeof(zx_ns_tab));
  len = zx_LEN_SO_mm7_DeliveryCondition(c, x );
  buf = ZX_ALLOC(c, len+1);
  return zx_easy_enc_common(c, zx_ENC_SO_mm7_DeliveryCondition(c, x, buf ), buf, len);
}

/* FUNC(zx_EASY_ENC_WO_mm7_DeliveryCondition) */

/* Called by: */
struct zx_str* zx_EASY_ENC_WO_mm7_DeliveryCondition(struct zx_ctx* c, struct zx_mm7_DeliveryCondition_s* x )
{
  int len;
  char* buf;
  c->ns_tab = ZX_ALLOC(c, sizeof(zx_ns_tab));
  memcpy(c->ns_tab, zx_ns_tab, sizeof(zx_ns_tab));
  len = zx_LEN_WO_mm7_DeliveryCondition(c, x );
  buf = ZX_ALLOC(c, len+1);
  return zx_easy_enc_common(c, zx_ENC_WO_mm7_DeliveryCondition(c, x, buf ), buf, len);
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

#define EL_NAME   mm7_DeliveryReportReq
#define EL_STRUCT zx_mm7_DeliveryReportReq_s
#define EL_NS     mm7
#define EL_TAG    DeliveryReportReq

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

/* FUNC(zx_LEN_SO_mm7_DeliveryReportReq) */

/* Compute length of an element (and its subelements). The XML attributes
 * and elements are processed in schema order. */

/* Called by: */
int zx_LEN_SO_mm7_DeliveryReportReq(struct zx_ctx* c, struct zx_mm7_DeliveryReportReq_s* x )
{
  struct zx_ns_s* pop_seen = 0;
  struct zx_elem_s* se MAYBE_UNUSED;
#if 1 /* NORMALMODE */
  /* *** in simple_elem case should output ns prefix from ns node. */
  int len = sizeof("<mm7:DeliveryReportReq")-1 + 1 + sizeof("</mm7:DeliveryReportReq>")-1;
  if (c->inc_ns_len)
    len += zx_len_inc_ns(c, &pop_seen);
  len += zx_len_xmlns_if_not_seen(c, zx_ns_tab+zx_xmlns_ix_mm7, &pop_seen);


#else
  /* root node has no begin tag */
  int len = 0;
#endif
  
  for (se = x->MM7Version; se; se = (struct zx_elem_s*)se->g.n)
    len += zx_LEN_SO_simple_elem(c,se, sizeof("mm7:MM7Version")-1, zx_ns_tab+zx_xmlns_ix_mm7);
  for (se = x->MMSRelayServerID; se; se = (struct zx_elem_s*)se->g.n)
    len += zx_LEN_SO_simple_elem(c,se, sizeof("mm7:MMSRelayServerID")-1, zx_ns_tab+zx_xmlns_ix_mm7);
  {
      struct zx_mm7_Extension_s* e;
      for (e = x->Extension; e; e = (struct zx_mm7_Extension_s*)e->gg.g.n)
	  len += zx_LEN_SO_mm7_Extension(c, e);
  }
  for (se = x->MessageID; se; se = (struct zx_elem_s*)se->g.n)
    len += zx_LEN_SO_simple_elem(c,se, sizeof("mm7:MessageID")-1, zx_ns_tab+zx_xmlns_ix_mm7);
  {
      struct zx_mm7_Recipient_s* e;
      for (e = x->Recipient; e; e = (struct zx_mm7_Recipient_s*)e->gg.g.n)
	  len += zx_LEN_SO_mm7_Recipient(c, e);
  }
  {
      struct zx_mm7_Sender_s* e;
      for (e = x->Sender; e; e = (struct zx_mm7_Sender_s*)e->gg.g.n)
	  len += zx_LEN_SO_mm7_Sender(c, e);
  }
  for (se = x->Date; se; se = (struct zx_elem_s*)se->g.n)
    len += zx_LEN_SO_simple_elem(c,se, sizeof("mm7:Date")-1, zx_ns_tab+zx_xmlns_ix_mm7);
  for (se = x->MMStatus; se; se = (struct zx_elem_s*)se->g.n)
    len += zx_LEN_SO_simple_elem(c,se, sizeof("mm7:MMStatus")-1, zx_ns_tab+zx_xmlns_ix_mm7);
  for (se = x->MMStatusExtension; se; se = (struct zx_elem_s*)se->g.n)
    len += zx_LEN_SO_simple_elem(c,se, sizeof("mm7:MMStatusExtension")-1, zx_ns_tab+zx_xmlns_ix_mm7);
  for (se = x->StatusText; se; se = (struct zx_elem_s*)se->g.n)
    len += zx_LEN_SO_simple_elem(c,se, sizeof("mm7:StatusText")-1, zx_ns_tab+zx_xmlns_ix_mm7);
  for (se = x->ApplicID; se; se = (struct zx_elem_s*)se->g.n)
    len += zx_LEN_SO_simple_elem(c,se, sizeof("mm7:ApplicID")-1, zx_ns_tab+zx_xmlns_ix_mm7);
  for (se = x->ReplyApplicID; se; se = (struct zx_elem_s*)se->g.n)
    len += zx_LEN_SO_simple_elem(c,se, sizeof("mm7:ReplyApplicID")-1, zx_ns_tab+zx_xmlns_ix_mm7);
  for (se = x->AuxApplicInfo; se; se = (struct zx_elem_s*)se->g.n)
    len += zx_LEN_SO_simple_elem(c,se, sizeof("mm7:AuxApplicInfo")-1, zx_ns_tab+zx_xmlns_ix_mm7);
  {
      struct zx_mm7_UACapabilities_s* e;
      for (e = x->UACapabilities; e; e = (struct zx_mm7_UACapabilities_s*)e->gg.g.n)
	  len += zx_LEN_SO_mm7_UACapabilities(c, e);
  }


  len += zx_len_so_common(c, &x->gg);
  zx_pop_seen(pop_seen);
  ENC_LEN_DEBUG(x, "mm7:DeliveryReportReq", len);
  return len;
}

/* FUNC(zx_LEN_WO_mm7_DeliveryReportReq) */

/* Compute length of an element (and its subelements). The XML attributes
 * and elements are processed in wire order and no assumptions
 * are made about namespace prefixes. */

/* Called by: */
int zx_LEN_WO_mm7_DeliveryReportReq(struct zx_ctx* c, struct zx_mm7_DeliveryReportReq_s* x )
{
  struct zx_ns_s* pop_seen = 0;
  struct zx_elem_s* se MAYBE_UNUSED;
#if 1 /* NORMALMODE */
  int len = 1 + sizeof("DeliveryReportReq")-1 + 1 + 2 + sizeof("DeliveryReportReq")-1 + 1;
  
  if (x->gg.g.ns && x->gg.g.ns->prefix_len)
    len += (x->gg.g.ns->prefix_len + 1) * 2;
  if (c->inc_ns_len)
    len += zx_len_inc_ns(c, &pop_seen);
  len += zx_len_xmlns_if_not_seen(c, x->gg.g.ns, &pop_seen);


#else
  /* root node has no begin tag */
  int len = 0;
#endif
  
  for (se = x->MM7Version; se; se = (struct zx_elem_s*)se->g.n)
    len += zx_LEN_WO_simple_elem(c, se, sizeof("MM7Version")-1);
  for (se = x->MMSRelayServerID; se; se = (struct zx_elem_s*)se->g.n)
    len += zx_LEN_WO_simple_elem(c, se, sizeof("MMSRelayServerID")-1);
  {
      struct zx_mm7_Extension_s* e;
      for (e = x->Extension; e; e = (struct zx_mm7_Extension_s*)e->gg.g.n)
	  len += zx_LEN_WO_mm7_Extension(c, e);
  }
  for (se = x->MessageID; se; se = (struct zx_elem_s*)se->g.n)
    len += zx_LEN_WO_simple_elem(c, se, sizeof("MessageID")-1);
  {
      struct zx_mm7_Recipient_s* e;
      for (e = x->Recipient; e; e = (struct zx_mm7_Recipient_s*)e->gg.g.n)
	  len += zx_LEN_WO_mm7_Recipient(c, e);
  }
  {
      struct zx_mm7_Sender_s* e;
      for (e = x->Sender; e; e = (struct zx_mm7_Sender_s*)e->gg.g.n)
	  len += zx_LEN_WO_mm7_Sender(c, e);
  }
  for (se = x->Date; se; se = (struct zx_elem_s*)se->g.n)
    len += zx_LEN_WO_simple_elem(c, se, sizeof("Date")-1);
  for (se = x->MMStatus; se; se = (struct zx_elem_s*)se->g.n)
    len += zx_LEN_WO_simple_elem(c, se, sizeof("MMStatus")-1);
  for (se = x->MMStatusExtension; se; se = (struct zx_elem_s*)se->g.n)
    len += zx_LEN_WO_simple_elem(c, se, sizeof("MMStatusExtension")-1);
  for (se = x->StatusText; se; se = (struct zx_elem_s*)se->g.n)
    len += zx_LEN_WO_simple_elem(c, se, sizeof("StatusText")-1);
  for (se = x->ApplicID; se; se = (struct zx_elem_s*)se->g.n)
    len += zx_LEN_WO_simple_elem(c, se, sizeof("ApplicID")-1);
  for (se = x->ReplyApplicID; se; se = (struct zx_elem_s*)se->g.n)
    len += zx_LEN_WO_simple_elem(c, se, sizeof("ReplyApplicID")-1);
  for (se = x->AuxApplicInfo; se; se = (struct zx_elem_s*)se->g.n)
    len += zx_LEN_WO_simple_elem(c, se, sizeof("AuxApplicInfo")-1);
  {
      struct zx_mm7_UACapabilities_s* e;
      for (e = x->UACapabilities; e; e = (struct zx_mm7_UACapabilities_s*)e->gg.g.n)
	  len += zx_LEN_WO_mm7_UACapabilities(c, e);
  }


  len += zx_len_wo_common(c, &x->gg); 
  zx_pop_seen(pop_seen);
  ENC_LEN_DEBUG(x, "mm7:DeliveryReportReq", len);
  return len;
}

/* FUNC(zx_ENC_SO_mm7_DeliveryReportReq) */

/* Render element into string. The XML attributes and elements are
 * processed in schema order. This is what you generally want for
 * rendering new data structure to a string. The wo pointers are not used. */

/* Called by: */
char* zx_ENC_SO_mm7_DeliveryReportReq(struct zx_ctx* c, struct zx_mm7_DeliveryReportReq_s* x, char* p )
{
  struct zx_elem_s* se MAYBE_UNUSED;
  struct zx_ns_s* pop_seen = 0;
  ENC_LEN_DEBUG_BASE;
#if 1 /* NORMALMODE */
  /* *** in simple_elem case should output ns prefix from ns node. */
  ZX_OUT_TAG(p, "<mm7:DeliveryReportReq");
  if (c->inc_ns)
    p = zx_enc_inc_ns(c, p, &pop_seen);
  p = zx_enc_xmlns_if_not_seen(c, p, zx_ns_tab+zx_xmlns_ix_mm7, &pop_seen);


  p = zx_enc_unknown_attrs(p, x->gg.any_attr);
#else
  /* root node has no begin tag */
#endif
  
  for (se = x->MM7Version; se; se = (struct zx_elem_s*)se->g.n)
    p = zx_ENC_SO_simple_elem(c, se, p, "mm7:MM7Version", sizeof("mm7:MM7Version")-1, zx_ns_tab+zx_xmlns_ix_mm7);
  for (se = x->MMSRelayServerID; se; se = (struct zx_elem_s*)se->g.n)
    p = zx_ENC_SO_simple_elem(c, se, p, "mm7:MMSRelayServerID", sizeof("mm7:MMSRelayServerID")-1, zx_ns_tab+zx_xmlns_ix_mm7);
  {
      struct zx_mm7_Extension_s* e;
      for (e = x->Extension; e; e = (struct zx_mm7_Extension_s*)e->gg.g.n)
	  p = zx_ENC_SO_mm7_Extension(c, e, p);
  }
  for (se = x->MessageID; se; se = (struct zx_elem_s*)se->g.n)
    p = zx_ENC_SO_simple_elem(c, se, p, "mm7:MessageID", sizeof("mm7:MessageID")-1, zx_ns_tab+zx_xmlns_ix_mm7);
  {
      struct zx_mm7_Recipient_s* e;
      for (e = x->Recipient; e; e = (struct zx_mm7_Recipient_s*)e->gg.g.n)
	  p = zx_ENC_SO_mm7_Recipient(c, e, p);
  }
  {
      struct zx_mm7_Sender_s* e;
      for (e = x->Sender; e; e = (struct zx_mm7_Sender_s*)e->gg.g.n)
	  p = zx_ENC_SO_mm7_Sender(c, e, p);
  }
  for (se = x->Date; se; se = (struct zx_elem_s*)se->g.n)
    p = zx_ENC_SO_simple_elem(c, se, p, "mm7:Date", sizeof("mm7:Date")-1, zx_ns_tab+zx_xmlns_ix_mm7);
  for (se = x->MMStatus; se; se = (struct zx_elem_s*)se->g.n)
    p = zx_ENC_SO_simple_elem(c, se, p, "mm7:MMStatus", sizeof("mm7:MMStatus")-1, zx_ns_tab+zx_xmlns_ix_mm7);
  for (se = x->MMStatusExtension; se; se = (struct zx_elem_s*)se->g.n)
    p = zx_ENC_SO_simple_elem(c, se, p, "mm7:MMStatusExtension", sizeof("mm7:MMStatusExtension")-1, zx_ns_tab+zx_xmlns_ix_mm7);
  for (se = x->StatusText; se; se = (struct zx_elem_s*)se->g.n)
    p = zx_ENC_SO_simple_elem(c, se, p, "mm7:StatusText", sizeof("mm7:StatusText")-1, zx_ns_tab+zx_xmlns_ix_mm7);
  for (se = x->ApplicID; se; se = (struct zx_elem_s*)se->g.n)
    p = zx_ENC_SO_simple_elem(c, se, p, "mm7:ApplicID", sizeof("mm7:ApplicID")-1, zx_ns_tab+zx_xmlns_ix_mm7);
  for (se = x->ReplyApplicID; se; se = (struct zx_elem_s*)se->g.n)
    p = zx_ENC_SO_simple_elem(c, se, p, "mm7:ReplyApplicID", sizeof("mm7:ReplyApplicID")-1, zx_ns_tab+zx_xmlns_ix_mm7);
  for (se = x->AuxApplicInfo; se; se = (struct zx_elem_s*)se->g.n)
    p = zx_ENC_SO_simple_elem(c, se, p, "mm7:AuxApplicInfo", sizeof("mm7:AuxApplicInfo")-1, zx_ns_tab+zx_xmlns_ix_mm7);
  {
      struct zx_mm7_UACapabilities_s* e;
      for (e = x->UACapabilities; e; e = (struct zx_mm7_UACapabilities_s*)e->gg.g.n)
	  p = zx_ENC_SO_mm7_UACapabilities(c, e, p);
  }

  p = zx_enc_so_unknown_elems_and_content(c, p, &x->gg);
  
#if 1 /* NORMALMODE */
  ZX_OUT_CLOSE_TAG(p, "</mm7:DeliveryReportReq>");
  zx_pop_seen(pop_seen);
#else
  /* root node has no end tag either */
#endif
  ENC_LEN_DEBUG(x, "mm7:DeliveryReportReq", p-enc_base);
  return p;
}

/* FUNC(zx_ENC_WO_mm7_DeliveryReportReq) */

/* Render element into string. The XML attributes and elements are
 * processed in wire order by chasing wo pointers. This is what you want for
 * validating signatures on other people's XML documents. */

/* Called by: */
char* zx_ENC_WO_mm7_DeliveryReportReq(struct zx_ctx* c, struct zx_mm7_DeliveryReportReq_s* x, char* p )
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
  ZX_OUT_MEM(p, "DeliveryReportReq", sizeof("DeliveryReportReq")-1);
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
  ENC_LEN_DEBUG(x, "mm7:DeliveryReportReq", p-enc_base);
  return p;
}

/* FUNC(zx_EASY_ENC_SO_mm7_DeliveryReportReq) */

/* Called by: */
struct zx_str* zx_EASY_ENC_SO_mm7_DeliveryReportReq(struct zx_ctx* c, struct zx_mm7_DeliveryReportReq_s* x )
{
  int len;
  char* buf;
  c->ns_tab = ZX_ALLOC(c, sizeof(zx_ns_tab));
  memcpy(c->ns_tab, zx_ns_tab, sizeof(zx_ns_tab));
  len = zx_LEN_SO_mm7_DeliveryReportReq(c, x );
  buf = ZX_ALLOC(c, len+1);
  return zx_easy_enc_common(c, zx_ENC_SO_mm7_DeliveryReportReq(c, x, buf ), buf, len);
}

/* FUNC(zx_EASY_ENC_WO_mm7_DeliveryReportReq) */

/* Called by: */
struct zx_str* zx_EASY_ENC_WO_mm7_DeliveryReportReq(struct zx_ctx* c, struct zx_mm7_DeliveryReportReq_s* x )
{
  int len;
  char* buf;
  c->ns_tab = ZX_ALLOC(c, sizeof(zx_ns_tab));
  memcpy(c->ns_tab, zx_ns_tab, sizeof(zx_ns_tab));
  len = zx_LEN_WO_mm7_DeliveryReportReq(c, x );
  buf = ZX_ALLOC(c, len+1);
  return zx_easy_enc_common(c, zx_ENC_WO_mm7_DeliveryReportReq(c, x, buf ), buf, len);
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

#define EL_NAME   mm7_DeliveryReportRsp
#define EL_STRUCT zx_mm7_DeliveryReportRsp_s
#define EL_NS     mm7
#define EL_TAG    DeliveryReportRsp

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

/* FUNC(zx_LEN_SO_mm7_DeliveryReportRsp) */

/* Compute length of an element (and its subelements). The XML attributes
 * and elements are processed in schema order. */

/* Called by: */
int zx_LEN_SO_mm7_DeliveryReportRsp(struct zx_ctx* c, struct zx_mm7_DeliveryReportRsp_s* x )
{
  struct zx_ns_s* pop_seen = 0;
  struct zx_elem_s* se MAYBE_UNUSED;
#if 1 /* NORMALMODE */
  /* *** in simple_elem case should output ns prefix from ns node. */
  int len = sizeof("<mm7:DeliveryReportRsp")-1 + 1 + sizeof("</mm7:DeliveryReportRsp>")-1;
  if (c->inc_ns_len)
    len += zx_len_inc_ns(c, &pop_seen);
  len += zx_len_xmlns_if_not_seen(c, zx_ns_tab+zx_xmlns_ix_mm7, &pop_seen);


#else
  /* root node has no begin tag */
  int len = 0;
#endif
  
  for (se = x->MM7Version; se; se = (struct zx_elem_s*)se->g.n)
    len += zx_LEN_SO_simple_elem(c,se, sizeof("mm7:MM7Version")-1, zx_ns_tab+zx_xmlns_ix_mm7);
  {
      struct zx_mm7_Status_s* e;
      for (e = x->Status; e; e = (struct zx_mm7_Status_s*)e->gg.g.n)
	  len += zx_LEN_SO_mm7_Status(c, e);
  }
  {
      struct zx_mm7_Extension_s* e;
      for (e = x->Extension; e; e = (struct zx_mm7_Extension_s*)e->gg.g.n)
	  len += zx_LEN_SO_mm7_Extension(c, e);
  }


  len += zx_len_so_common(c, &x->gg);
  zx_pop_seen(pop_seen);
  ENC_LEN_DEBUG(x, "mm7:DeliveryReportRsp", len);
  return len;
}

/* FUNC(zx_LEN_WO_mm7_DeliveryReportRsp) */

/* Compute length of an element (and its subelements). The XML attributes
 * and elements are processed in wire order and no assumptions
 * are made about namespace prefixes. */

/* Called by: */
int zx_LEN_WO_mm7_DeliveryReportRsp(struct zx_ctx* c, struct zx_mm7_DeliveryReportRsp_s* x )
{
  struct zx_ns_s* pop_seen = 0;
  struct zx_elem_s* se MAYBE_UNUSED;
#if 1 /* NORMALMODE */
  int len = 1 + sizeof("DeliveryReportRsp")-1 + 1 + 2 + sizeof("DeliveryReportRsp")-1 + 1;
  
  if (x->gg.g.ns && x->gg.g.ns->prefix_len)
    len += (x->gg.g.ns->prefix_len + 1) * 2;
  if (c->inc_ns_len)
    len += zx_len_inc_ns(c, &pop_seen);
  len += zx_len_xmlns_if_not_seen(c, x->gg.g.ns, &pop_seen);


#else
  /* root node has no begin tag */
  int len = 0;
#endif
  
  for (se = x->MM7Version; se; se = (struct zx_elem_s*)se->g.n)
    len += zx_LEN_WO_simple_elem(c, se, sizeof("MM7Version")-1);
  {
      struct zx_mm7_Status_s* e;
      for (e = x->Status; e; e = (struct zx_mm7_Status_s*)e->gg.g.n)
	  len += zx_LEN_WO_mm7_Status(c, e);
  }
  {
      struct zx_mm7_Extension_s* e;
      for (e = x->Extension; e; e = (struct zx_mm7_Extension_s*)e->gg.g.n)
	  len += zx_LEN_WO_mm7_Extension(c, e);
  }


  len += zx_len_wo_common(c, &x->gg); 
  zx_pop_seen(pop_seen);
  ENC_LEN_DEBUG(x, "mm7:DeliveryReportRsp", len);
  return len;
}

/* FUNC(zx_ENC_SO_mm7_DeliveryReportRsp) */

/* Render element into string. The XML attributes and elements are
 * processed in schema order. This is what you generally want for
 * rendering new data structure to a string. The wo pointers are not used. */

/* Called by: */
char* zx_ENC_SO_mm7_DeliveryReportRsp(struct zx_ctx* c, struct zx_mm7_DeliveryReportRsp_s* x, char* p )
{
  struct zx_elem_s* se MAYBE_UNUSED;
  struct zx_ns_s* pop_seen = 0;
  ENC_LEN_DEBUG_BASE;
#if 1 /* NORMALMODE */
  /* *** in simple_elem case should output ns prefix from ns node. */
  ZX_OUT_TAG(p, "<mm7:DeliveryReportRsp");
  if (c->inc_ns)
    p = zx_enc_inc_ns(c, p, &pop_seen);
  p = zx_enc_xmlns_if_not_seen(c, p, zx_ns_tab+zx_xmlns_ix_mm7, &pop_seen);


  p = zx_enc_unknown_attrs(p, x->gg.any_attr);
#else
  /* root node has no begin tag */
#endif
  
  for (se = x->MM7Version; se; se = (struct zx_elem_s*)se->g.n)
    p = zx_ENC_SO_simple_elem(c, se, p, "mm7:MM7Version", sizeof("mm7:MM7Version")-1, zx_ns_tab+zx_xmlns_ix_mm7);
  {
      struct zx_mm7_Status_s* e;
      for (e = x->Status; e; e = (struct zx_mm7_Status_s*)e->gg.g.n)
	  p = zx_ENC_SO_mm7_Status(c, e, p);
  }
  {
      struct zx_mm7_Extension_s* e;
      for (e = x->Extension; e; e = (struct zx_mm7_Extension_s*)e->gg.g.n)
	  p = zx_ENC_SO_mm7_Extension(c, e, p);
  }

  p = zx_enc_so_unknown_elems_and_content(c, p, &x->gg);
  
#if 1 /* NORMALMODE */
  ZX_OUT_CLOSE_TAG(p, "</mm7:DeliveryReportRsp>");
  zx_pop_seen(pop_seen);
#else
  /* root node has no end tag either */
#endif
  ENC_LEN_DEBUG(x, "mm7:DeliveryReportRsp", p-enc_base);
  return p;
}

/* FUNC(zx_ENC_WO_mm7_DeliveryReportRsp) */

/* Render element into string. The XML attributes and elements are
 * processed in wire order by chasing wo pointers. This is what you want for
 * validating signatures on other people's XML documents. */

/* Called by: */
char* zx_ENC_WO_mm7_DeliveryReportRsp(struct zx_ctx* c, struct zx_mm7_DeliveryReportRsp_s* x, char* p )
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
  ZX_OUT_MEM(p, "DeliveryReportRsp", sizeof("DeliveryReportRsp")-1);
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
  ENC_LEN_DEBUG(x, "mm7:DeliveryReportRsp", p-enc_base);
  return p;
}

/* FUNC(zx_EASY_ENC_SO_mm7_DeliveryReportRsp) */

/* Called by: */
struct zx_str* zx_EASY_ENC_SO_mm7_DeliveryReportRsp(struct zx_ctx* c, struct zx_mm7_DeliveryReportRsp_s* x )
{
  int len;
  char* buf;
  c->ns_tab = ZX_ALLOC(c, sizeof(zx_ns_tab));
  memcpy(c->ns_tab, zx_ns_tab, sizeof(zx_ns_tab));
  len = zx_LEN_SO_mm7_DeliveryReportRsp(c, x );
  buf = ZX_ALLOC(c, len+1);
  return zx_easy_enc_common(c, zx_ENC_SO_mm7_DeliveryReportRsp(c, x, buf ), buf, len);
}

/* FUNC(zx_EASY_ENC_WO_mm7_DeliveryReportRsp) */

/* Called by: */
struct zx_str* zx_EASY_ENC_WO_mm7_DeliveryReportRsp(struct zx_ctx* c, struct zx_mm7_DeliveryReportRsp_s* x )
{
  int len;
  char* buf;
  c->ns_tab = ZX_ALLOC(c, sizeof(zx_ns_tab));
  memcpy(c->ns_tab, zx_ns_tab, sizeof(zx_ns_tab));
  len = zx_LEN_WO_mm7_DeliveryReportRsp(c, x );
  buf = ZX_ALLOC(c, len+1);
  return zx_easy_enc_common(c, zx_ENC_WO_mm7_DeliveryReportRsp(c, x, buf ), buf, len);
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

#define EL_NAME   mm7_Details
#define EL_STRUCT zx_mm7_Details_s
#define EL_NS     mm7
#define EL_TAG    Details

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

/* FUNC(zx_LEN_SO_mm7_Details) */

/* Compute length of an element (and its subelements). The XML attributes
 * and elements are processed in schema order. */

/* Called by: */
int zx_LEN_SO_mm7_Details(struct zx_ctx* c, struct zx_mm7_Details_s* x )
{
  struct zx_ns_s* pop_seen = 0;
  struct zx_elem_s* se MAYBE_UNUSED;
#if 1 /* NORMALMODE */
  /* *** in simple_elem case should output ns prefix from ns node. */
  int len = sizeof("<mm7:Details")-1 + 1 + sizeof("</mm7:Details>")-1;
  if (c->inc_ns_len)
    len += zx_len_inc_ns(c, &pop_seen);
  len += zx_len_xmlns_if_not_seen(c, zx_ns_tab+zx_xmlns_ix_mm7, &pop_seen);


#else
  /* root node has no begin tag */
  int len = 0;
#endif
  


  len += zx_len_so_common(c, &x->gg);
  zx_pop_seen(pop_seen);
  ENC_LEN_DEBUG(x, "mm7:Details", len);
  return len;
}

/* FUNC(zx_LEN_WO_mm7_Details) */

/* Compute length of an element (and its subelements). The XML attributes
 * and elements are processed in wire order and no assumptions
 * are made about namespace prefixes. */

/* Called by: */
int zx_LEN_WO_mm7_Details(struct zx_ctx* c, struct zx_mm7_Details_s* x )
{
  struct zx_ns_s* pop_seen = 0;
  struct zx_elem_s* se MAYBE_UNUSED;
#if 1 /* NORMALMODE */
  int len = 1 + sizeof("Details")-1 + 1 + 2 + sizeof("Details")-1 + 1;
  
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
  ENC_LEN_DEBUG(x, "mm7:Details", len);
  return len;
}

/* FUNC(zx_ENC_SO_mm7_Details) */

/* Render element into string. The XML attributes and elements are
 * processed in schema order. This is what you generally want for
 * rendering new data structure to a string. The wo pointers are not used. */

/* Called by: */
char* zx_ENC_SO_mm7_Details(struct zx_ctx* c, struct zx_mm7_Details_s* x, char* p )
{
  struct zx_elem_s* se MAYBE_UNUSED;
  struct zx_ns_s* pop_seen = 0;
  ENC_LEN_DEBUG_BASE;
#if 1 /* NORMALMODE */
  /* *** in simple_elem case should output ns prefix from ns node. */
  ZX_OUT_TAG(p, "<mm7:Details");
  if (c->inc_ns)
    p = zx_enc_inc_ns(c, p, &pop_seen);
  p = zx_enc_xmlns_if_not_seen(c, p, zx_ns_tab+zx_xmlns_ix_mm7, &pop_seen);


  p = zx_enc_unknown_attrs(p, x->gg.any_attr);
#else
  /* root node has no begin tag */
#endif
  

  p = zx_enc_so_unknown_elems_and_content(c, p, &x->gg);
  
#if 1 /* NORMALMODE */
  ZX_OUT_CLOSE_TAG(p, "</mm7:Details>");
  zx_pop_seen(pop_seen);
#else
  /* root node has no end tag either */
#endif
  ENC_LEN_DEBUG(x, "mm7:Details", p-enc_base);
  return p;
}

/* FUNC(zx_ENC_WO_mm7_Details) */

/* Render element into string. The XML attributes and elements are
 * processed in wire order by chasing wo pointers. This is what you want for
 * validating signatures on other people's XML documents. */

/* Called by: */
char* zx_ENC_WO_mm7_Details(struct zx_ctx* c, struct zx_mm7_Details_s* x, char* p )
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
  ZX_OUT_MEM(p, "Details", sizeof("Details")-1);
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
  ENC_LEN_DEBUG(x, "mm7:Details", p-enc_base);
  return p;
}

/* FUNC(zx_EASY_ENC_SO_mm7_Details) */

/* Called by: */
struct zx_str* zx_EASY_ENC_SO_mm7_Details(struct zx_ctx* c, struct zx_mm7_Details_s* x )
{
  int len;
  char* buf;
  c->ns_tab = ZX_ALLOC(c, sizeof(zx_ns_tab));
  memcpy(c->ns_tab, zx_ns_tab, sizeof(zx_ns_tab));
  len = zx_LEN_SO_mm7_Details(c, x );
  buf = ZX_ALLOC(c, len+1);
  return zx_easy_enc_common(c, zx_ENC_SO_mm7_Details(c, x, buf ), buf, len);
}

/* FUNC(zx_EASY_ENC_WO_mm7_Details) */

/* Called by: */
struct zx_str* zx_EASY_ENC_WO_mm7_Details(struct zx_ctx* c, struct zx_mm7_Details_s* x )
{
  int len;
  char* buf;
  c->ns_tab = ZX_ALLOC(c, sizeof(zx_ns_tab));
  memcpy(c->ns_tab, zx_ns_tab, sizeof(zx_ns_tab));
  len = zx_LEN_WO_mm7_Details(c, x );
  buf = ZX_ALLOC(c, len+1);
  return zx_easy_enc_common(c, zx_ENC_WO_mm7_Details(c, x, buf ), buf, len);
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

#define EL_NAME   mm7_Extension
#define EL_STRUCT zx_mm7_Extension_s
#define EL_NS     mm7
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

/* FUNC(zx_LEN_SO_mm7_Extension) */

/* Compute length of an element (and its subelements). The XML attributes
 * and elements are processed in schema order. */

/* Called by: */
int zx_LEN_SO_mm7_Extension(struct zx_ctx* c, struct zx_mm7_Extension_s* x )
{
  struct zx_ns_s* pop_seen = 0;
  struct zx_elem_s* se MAYBE_UNUSED;
#if 1 /* NORMALMODE */
  /* *** in simple_elem case should output ns prefix from ns node. */
  int len = sizeof("<mm7:Extension")-1 + 1 + sizeof("</mm7:Extension>")-1;
  if (c->inc_ns_len)
    len += zx_len_inc_ns(c, &pop_seen);
  len += zx_len_xmlns_if_not_seen(c, zx_ns_tab+zx_xmlns_ix_mm7, &pop_seen);


#else
  /* root node has no begin tag */
  int len = 0;
#endif
  
  {
      struct zx_mm7_IdentityAddressingToken_s* e;
      for (e = x->IdentityAddressingToken; e; e = (struct zx_mm7_IdentityAddressingToken_s*)e->gg.g.n)
	  len += zx_LEN_SO_mm7_IdentityAddressingToken(c, e);
  }
  {
      struct zx_mm7_MessageExtraData_s* e;
      for (e = x->MessageExtraData; e; e = (struct zx_mm7_MessageExtraData_s*)e->gg.g.n)
	  len += zx_LEN_SO_mm7_MessageExtraData(c, e);
  }


  len += zx_len_so_common(c, &x->gg);
  zx_pop_seen(pop_seen);
  ENC_LEN_DEBUG(x, "mm7:Extension", len);
  return len;
}

/* FUNC(zx_LEN_WO_mm7_Extension) */

/* Compute length of an element (and its subelements). The XML attributes
 * and elements are processed in wire order and no assumptions
 * are made about namespace prefixes. */

/* Called by: */
int zx_LEN_WO_mm7_Extension(struct zx_ctx* c, struct zx_mm7_Extension_s* x )
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
  
  {
      struct zx_mm7_IdentityAddressingToken_s* e;
      for (e = x->IdentityAddressingToken; e; e = (struct zx_mm7_IdentityAddressingToken_s*)e->gg.g.n)
	  len += zx_LEN_WO_mm7_IdentityAddressingToken(c, e);
  }
  {
      struct zx_mm7_MessageExtraData_s* e;
      for (e = x->MessageExtraData; e; e = (struct zx_mm7_MessageExtraData_s*)e->gg.g.n)
	  len += zx_LEN_WO_mm7_MessageExtraData(c, e);
  }


  len += zx_len_wo_common(c, &x->gg); 
  zx_pop_seen(pop_seen);
  ENC_LEN_DEBUG(x, "mm7:Extension", len);
  return len;
}

/* FUNC(zx_ENC_SO_mm7_Extension) */

/* Render element into string. The XML attributes and elements are
 * processed in schema order. This is what you generally want for
 * rendering new data structure to a string. The wo pointers are not used. */

/* Called by: */
char* zx_ENC_SO_mm7_Extension(struct zx_ctx* c, struct zx_mm7_Extension_s* x, char* p )
{
  struct zx_elem_s* se MAYBE_UNUSED;
  struct zx_ns_s* pop_seen = 0;
  ENC_LEN_DEBUG_BASE;
#if 1 /* NORMALMODE */
  /* *** in simple_elem case should output ns prefix from ns node. */
  ZX_OUT_TAG(p, "<mm7:Extension");
  if (c->inc_ns)
    p = zx_enc_inc_ns(c, p, &pop_seen);
  p = zx_enc_xmlns_if_not_seen(c, p, zx_ns_tab+zx_xmlns_ix_mm7, &pop_seen);


  p = zx_enc_unknown_attrs(p, x->gg.any_attr);
#else
  /* root node has no begin tag */
#endif
  
  {
      struct zx_mm7_IdentityAddressingToken_s* e;
      for (e = x->IdentityAddressingToken; e; e = (struct zx_mm7_IdentityAddressingToken_s*)e->gg.g.n)
	  p = zx_ENC_SO_mm7_IdentityAddressingToken(c, e, p);
  }
  {
      struct zx_mm7_MessageExtraData_s* e;
      for (e = x->MessageExtraData; e; e = (struct zx_mm7_MessageExtraData_s*)e->gg.g.n)
	  p = zx_ENC_SO_mm7_MessageExtraData(c, e, p);
  }

  p = zx_enc_so_unknown_elems_and_content(c, p, &x->gg);
  
#if 1 /* NORMALMODE */
  ZX_OUT_CLOSE_TAG(p, "</mm7:Extension>");
  zx_pop_seen(pop_seen);
#else
  /* root node has no end tag either */
#endif
  ENC_LEN_DEBUG(x, "mm7:Extension", p-enc_base);
  return p;
}

/* FUNC(zx_ENC_WO_mm7_Extension) */

/* Render element into string. The XML attributes and elements are
 * processed in wire order by chasing wo pointers. This is what you want for
 * validating signatures on other people's XML documents. */

/* Called by: */
char* zx_ENC_WO_mm7_Extension(struct zx_ctx* c, struct zx_mm7_Extension_s* x, char* p )
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
  ENC_LEN_DEBUG(x, "mm7:Extension", p-enc_base);
  return p;
}

/* FUNC(zx_EASY_ENC_SO_mm7_Extension) */

/* Called by: */
struct zx_str* zx_EASY_ENC_SO_mm7_Extension(struct zx_ctx* c, struct zx_mm7_Extension_s* x )
{
  int len;
  char* buf;
  c->ns_tab = ZX_ALLOC(c, sizeof(zx_ns_tab));
  memcpy(c->ns_tab, zx_ns_tab, sizeof(zx_ns_tab));
  len = zx_LEN_SO_mm7_Extension(c, x );
  buf = ZX_ALLOC(c, len+1);
  return zx_easy_enc_common(c, zx_ENC_SO_mm7_Extension(c, x, buf ), buf, len);
}

/* FUNC(zx_EASY_ENC_WO_mm7_Extension) */

/* Called by: */
struct zx_str* zx_EASY_ENC_WO_mm7_Extension(struct zx_ctx* c, struct zx_mm7_Extension_s* x )
{
  int len;
  char* buf;
  c->ns_tab = ZX_ALLOC(c, sizeof(zx_ns_tab));
  memcpy(c->ns_tab, zx_ns_tab, sizeof(zx_ns_tab));
  len = zx_LEN_WO_mm7_Extension(c, x );
  buf = ZX_ALLOC(c, len+1);
  return zx_easy_enc_common(c, zx_ENC_WO_mm7_Extension(c, x, buf ), buf, len);
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

#define EL_NAME   mm7_IdentityAddressingToken
#define EL_STRUCT zx_mm7_IdentityAddressingToken_s
#define EL_NS     mm7
#define EL_TAG    IdentityAddressingToken

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

/* FUNC(zx_LEN_SO_mm7_IdentityAddressingToken) */

/* Compute length of an element (and its subelements). The XML attributes
 * and elements are processed in schema order. */

/* Called by: */
int zx_LEN_SO_mm7_IdentityAddressingToken(struct zx_ctx* c, struct zx_mm7_IdentityAddressingToken_s* x )
{
  struct zx_ns_s* pop_seen = 0;
  struct zx_elem_s* se MAYBE_UNUSED;
#if 1 /* NORMALMODE */
  /* *** in simple_elem case should output ns prefix from ns node. */
  int len = sizeof("<mm7:IdentityAddressingToken")-1 + 1 + sizeof("</mm7:IdentityAddressingToken>")-1;
  if (c->inc_ns_len)
    len += zx_len_inc_ns(c, &pop_seen);
  len += zx_len_xmlns_if_not_seen(c, zx_ns_tab+zx_xmlns_ix_mm7, &pop_seen);


#else
  /* root node has no begin tag */
  int len = 0;
#endif
  
  for (se = x->CredentialRef; se; se = (struct zx_elem_s*)se->g.n)
    len += zx_LEN_SO_simple_elem(c,se, sizeof("mm7:CredentialRef")-1, zx_ns_tab+zx_xmlns_ix_mm7);


  len += zx_len_so_common(c, &x->gg);
  zx_pop_seen(pop_seen);
  ENC_LEN_DEBUG(x, "mm7:IdentityAddressingToken", len);
  return len;
}

/* FUNC(zx_LEN_WO_mm7_IdentityAddressingToken) */

/* Compute length of an element (and its subelements). The XML attributes
 * and elements are processed in wire order and no assumptions
 * are made about namespace prefixes. */

/* Called by: */
int zx_LEN_WO_mm7_IdentityAddressingToken(struct zx_ctx* c, struct zx_mm7_IdentityAddressingToken_s* x )
{
  struct zx_ns_s* pop_seen = 0;
  struct zx_elem_s* se MAYBE_UNUSED;
#if 1 /* NORMALMODE */
  int len = 1 + sizeof("IdentityAddressingToken")-1 + 1 + 2 + sizeof("IdentityAddressingToken")-1 + 1;
  
  if (x->gg.g.ns && x->gg.g.ns->prefix_len)
    len += (x->gg.g.ns->prefix_len + 1) * 2;
  if (c->inc_ns_len)
    len += zx_len_inc_ns(c, &pop_seen);
  len += zx_len_xmlns_if_not_seen(c, x->gg.g.ns, &pop_seen);


#else
  /* root node has no begin tag */
  int len = 0;
#endif
  
  for (se = x->CredentialRef; se; se = (struct zx_elem_s*)se->g.n)
    len += zx_LEN_WO_simple_elem(c, se, sizeof("CredentialRef")-1);


  len += zx_len_wo_common(c, &x->gg); 
  zx_pop_seen(pop_seen);
  ENC_LEN_DEBUG(x, "mm7:IdentityAddressingToken", len);
  return len;
}

/* FUNC(zx_ENC_SO_mm7_IdentityAddressingToken) */

/* Render element into string. The XML attributes and elements are
 * processed in schema order. This is what you generally want for
 * rendering new data structure to a string. The wo pointers are not used. */

/* Called by: */
char* zx_ENC_SO_mm7_IdentityAddressingToken(struct zx_ctx* c, struct zx_mm7_IdentityAddressingToken_s* x, char* p )
{
  struct zx_elem_s* se MAYBE_UNUSED;
  struct zx_ns_s* pop_seen = 0;
  ENC_LEN_DEBUG_BASE;
#if 1 /* NORMALMODE */
  /* *** in simple_elem case should output ns prefix from ns node. */
  ZX_OUT_TAG(p, "<mm7:IdentityAddressingToken");
  if (c->inc_ns)
    p = zx_enc_inc_ns(c, p, &pop_seen);
  p = zx_enc_xmlns_if_not_seen(c, p, zx_ns_tab+zx_xmlns_ix_mm7, &pop_seen);


  p = zx_enc_unknown_attrs(p, x->gg.any_attr);
#else
  /* root node has no begin tag */
#endif
  
  for (se = x->CredentialRef; se; se = (struct zx_elem_s*)se->g.n)
    p = zx_ENC_SO_simple_elem(c, se, p, "mm7:CredentialRef", sizeof("mm7:CredentialRef")-1, zx_ns_tab+zx_xmlns_ix_mm7);

  p = zx_enc_so_unknown_elems_and_content(c, p, &x->gg);
  
#if 1 /* NORMALMODE */
  ZX_OUT_CLOSE_TAG(p, "</mm7:IdentityAddressingToken>");
  zx_pop_seen(pop_seen);
#else
  /* root node has no end tag either */
#endif
  ENC_LEN_DEBUG(x, "mm7:IdentityAddressingToken", p-enc_base);
  return p;
}

/* FUNC(zx_ENC_WO_mm7_IdentityAddressingToken) */

/* Render element into string. The XML attributes and elements are
 * processed in wire order by chasing wo pointers. This is what you want for
 * validating signatures on other people's XML documents. */

/* Called by: */
char* zx_ENC_WO_mm7_IdentityAddressingToken(struct zx_ctx* c, struct zx_mm7_IdentityAddressingToken_s* x, char* p )
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
  ZX_OUT_MEM(p, "IdentityAddressingToken", sizeof("IdentityAddressingToken")-1);
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
  ENC_LEN_DEBUG(x, "mm7:IdentityAddressingToken", p-enc_base);
  return p;
}

/* FUNC(zx_EASY_ENC_SO_mm7_IdentityAddressingToken) */

/* Called by: */
struct zx_str* zx_EASY_ENC_SO_mm7_IdentityAddressingToken(struct zx_ctx* c, struct zx_mm7_IdentityAddressingToken_s* x )
{
  int len;
  char* buf;
  c->ns_tab = ZX_ALLOC(c, sizeof(zx_ns_tab));
  memcpy(c->ns_tab, zx_ns_tab, sizeof(zx_ns_tab));
  len = zx_LEN_SO_mm7_IdentityAddressingToken(c, x );
  buf = ZX_ALLOC(c, len+1);
  return zx_easy_enc_common(c, zx_ENC_SO_mm7_IdentityAddressingToken(c, x, buf ), buf, len);
}

/* FUNC(zx_EASY_ENC_WO_mm7_IdentityAddressingToken) */

/* Called by: */
struct zx_str* zx_EASY_ENC_WO_mm7_IdentityAddressingToken(struct zx_ctx* c, struct zx_mm7_IdentityAddressingToken_s* x )
{
  int len;
  char* buf;
  c->ns_tab = ZX_ALLOC(c, sizeof(zx_ns_tab));
  memcpy(c->ns_tab, zx_ns_tab, sizeof(zx_ns_tab));
  len = zx_LEN_WO_mm7_IdentityAddressingToken(c, x );
  buf = ZX_ALLOC(c, len+1);
  return zx_easy_enc_common(c, zx_ENC_WO_mm7_IdentityAddressingToken(c, x, buf ), buf, len);
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

#define EL_NAME   mm7_MessageExtraData
#define EL_STRUCT zx_mm7_MessageExtraData_s
#define EL_NS     mm7
#define EL_TAG    MessageExtraData

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

/* FUNC(zx_LEN_SO_mm7_MessageExtraData) */

/* Compute length of an element (and its subelements). The XML attributes
 * and elements are processed in schema order. */

/* Called by: */
int zx_LEN_SO_mm7_MessageExtraData(struct zx_ctx* c, struct zx_mm7_MessageExtraData_s* x )
{
  struct zx_ns_s* pop_seen = 0;
  struct zx_elem_s* se MAYBE_UNUSED;
#if 1 /* NORMALMODE */
  /* *** in simple_elem case should output ns prefix from ns node. */
  int len = sizeof("<mm7:MessageExtraData")-1 + 1 + sizeof("</mm7:MessageExtraData>")-1;
  if (c->inc_ns_len)
    len += zx_len_inc_ns(c, &pop_seen);
  len += zx_len_xmlns_if_not_seen(c, zx_ns_tab+zx_xmlns_ix_mm7, &pop_seen);


#else
  /* root node has no begin tag */
  int len = 0;
#endif
  
  {
      struct zx_mm7_element_s* e;
      for (e = x->element; e; e = (struct zx_mm7_element_s*)e->gg.g.n)
	  len += zx_LEN_SO_mm7_element(c, e);
  }


  len += zx_len_so_common(c, &x->gg);
  zx_pop_seen(pop_seen);
  ENC_LEN_DEBUG(x, "mm7:MessageExtraData", len);
  return len;
}

/* FUNC(zx_LEN_WO_mm7_MessageExtraData) */

/* Compute length of an element (and its subelements). The XML attributes
 * and elements are processed in wire order and no assumptions
 * are made about namespace prefixes. */

/* Called by: */
int zx_LEN_WO_mm7_MessageExtraData(struct zx_ctx* c, struct zx_mm7_MessageExtraData_s* x )
{
  struct zx_ns_s* pop_seen = 0;
  struct zx_elem_s* se MAYBE_UNUSED;
#if 1 /* NORMALMODE */
  int len = 1 + sizeof("MessageExtraData")-1 + 1 + 2 + sizeof("MessageExtraData")-1 + 1;
  
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
      struct zx_mm7_element_s* e;
      for (e = x->element; e; e = (struct zx_mm7_element_s*)e->gg.g.n)
	  len += zx_LEN_WO_mm7_element(c, e);
  }


  len += zx_len_wo_common(c, &x->gg); 
  zx_pop_seen(pop_seen);
  ENC_LEN_DEBUG(x, "mm7:MessageExtraData", len);
  return len;
}

/* FUNC(zx_ENC_SO_mm7_MessageExtraData) */

/* Render element into string. The XML attributes and elements are
 * processed in schema order. This is what you generally want for
 * rendering new data structure to a string. The wo pointers are not used. */

/* Called by: */
char* zx_ENC_SO_mm7_MessageExtraData(struct zx_ctx* c, struct zx_mm7_MessageExtraData_s* x, char* p )
{
  struct zx_elem_s* se MAYBE_UNUSED;
  struct zx_ns_s* pop_seen = 0;
  ENC_LEN_DEBUG_BASE;
#if 1 /* NORMALMODE */
  /* *** in simple_elem case should output ns prefix from ns node. */
  ZX_OUT_TAG(p, "<mm7:MessageExtraData");
  if (c->inc_ns)
    p = zx_enc_inc_ns(c, p, &pop_seen);
  p = zx_enc_xmlns_if_not_seen(c, p, zx_ns_tab+zx_xmlns_ix_mm7, &pop_seen);


  p = zx_enc_unknown_attrs(p, x->gg.any_attr);
#else
  /* root node has no begin tag */
#endif
  
  {
      struct zx_mm7_element_s* e;
      for (e = x->element; e; e = (struct zx_mm7_element_s*)e->gg.g.n)
	  p = zx_ENC_SO_mm7_element(c, e, p);
  }

  p = zx_enc_so_unknown_elems_and_content(c, p, &x->gg);
  
#if 1 /* NORMALMODE */
  ZX_OUT_CLOSE_TAG(p, "</mm7:MessageExtraData>");
  zx_pop_seen(pop_seen);
#else
  /* root node has no end tag either */
#endif
  ENC_LEN_DEBUG(x, "mm7:MessageExtraData", p-enc_base);
  return p;
}

/* FUNC(zx_ENC_WO_mm7_MessageExtraData) */

/* Render element into string. The XML attributes and elements are
 * processed in wire order by chasing wo pointers. This is what you want for
 * validating signatures on other people's XML documents. */

/* Called by: */
char* zx_ENC_WO_mm7_MessageExtraData(struct zx_ctx* c, struct zx_mm7_MessageExtraData_s* x, char* p )
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
  ZX_OUT_MEM(p, "MessageExtraData", sizeof("MessageExtraData")-1);
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
  ENC_LEN_DEBUG(x, "mm7:MessageExtraData", p-enc_base);
  return p;
}

/* FUNC(zx_EASY_ENC_SO_mm7_MessageExtraData) */

/* Called by: */
struct zx_str* zx_EASY_ENC_SO_mm7_MessageExtraData(struct zx_ctx* c, struct zx_mm7_MessageExtraData_s* x )
{
  int len;
  char* buf;
  c->ns_tab = ZX_ALLOC(c, sizeof(zx_ns_tab));
  memcpy(c->ns_tab, zx_ns_tab, sizeof(zx_ns_tab));
  len = zx_LEN_SO_mm7_MessageExtraData(c, x );
  buf = ZX_ALLOC(c, len+1);
  return zx_easy_enc_common(c, zx_ENC_SO_mm7_MessageExtraData(c, x, buf ), buf, len);
}

/* FUNC(zx_EASY_ENC_WO_mm7_MessageExtraData) */

/* Called by: */
struct zx_str* zx_EASY_ENC_WO_mm7_MessageExtraData(struct zx_ctx* c, struct zx_mm7_MessageExtraData_s* x )
{
  int len;
  char* buf;
  c->ns_tab = ZX_ALLOC(c, sizeof(zx_ns_tab));
  memcpy(c->ns_tab, zx_ns_tab, sizeof(zx_ns_tab));
  len = zx_LEN_WO_mm7_MessageExtraData(c, x );
  buf = ZX_ALLOC(c, len+1);
  return zx_easy_enc_common(c, zx_ENC_WO_mm7_MessageExtraData(c, x, buf ), buf, len);
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

#define EL_NAME   mm7_Number
#define EL_STRUCT zx_mm7_Number_s
#define EL_NS     mm7
#define EL_TAG    Number

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

/* FUNC(zx_LEN_SO_mm7_Number) */

/* Compute length of an element (and its subelements). The XML attributes
 * and elements are processed in schema order. */

/* Called by: */
int zx_LEN_SO_mm7_Number(struct zx_ctx* c, struct zx_mm7_Number_s* x )
{
  struct zx_ns_s* pop_seen = 0;
  struct zx_elem_s* se MAYBE_UNUSED;
#if 1 /* NORMALMODE */
  /* *** in simple_elem case should output ns prefix from ns node. */
  int len = sizeof("<mm7:Number")-1 + 1 + sizeof("</mm7:Number>")-1;
  if (c->inc_ns_len)
    len += zx_len_inc_ns(c, &pop_seen);
  len += zx_len_xmlns_if_not_seen(c, zx_ns_tab+zx_xmlns_ix_mm7, &pop_seen);

  len += zx_attr_so_len(x->addressCoding, sizeof("addressCoding")-1);
  len += zx_attr_so_len(x->displayOnly, sizeof("displayOnly")-1);
  len += zx_attr_so_len(x->id, sizeof("id")-1);

#else
  /* root node has no begin tag */
  int len = 0;
#endif
  


  len += zx_len_so_common(c, &x->gg);
  zx_pop_seen(pop_seen);
  ENC_LEN_DEBUG(x, "mm7:Number", len);
  return len;
}

/* FUNC(zx_LEN_WO_mm7_Number) */

/* Compute length of an element (and its subelements). The XML attributes
 * and elements are processed in wire order and no assumptions
 * are made about namespace prefixes. */

/* Called by: */
int zx_LEN_WO_mm7_Number(struct zx_ctx* c, struct zx_mm7_Number_s* x )
{
  struct zx_ns_s* pop_seen = 0;
  struct zx_elem_s* se MAYBE_UNUSED;
#if 1 /* NORMALMODE */
  int len = 1 + sizeof("Number")-1 + 1 + 2 + sizeof("Number")-1 + 1;
  
  if (x->gg.g.ns && x->gg.g.ns->prefix_len)
    len += (x->gg.g.ns->prefix_len + 1) * 2;
  if (c->inc_ns_len)
    len += zx_len_inc_ns(c, &pop_seen);
  len += zx_len_xmlns_if_not_seen(c, x->gg.g.ns, &pop_seen);

  len += zx_attr_wo_len(x->addressCoding, sizeof("addressCoding")-1);
  len += zx_attr_wo_len(x->displayOnly, sizeof("displayOnly")-1);
  len += zx_attr_wo_len(x->id, sizeof("id")-1);

#else
  /* root node has no begin tag */
  int len = 0;
#endif
  


  len += zx_len_wo_common(c, &x->gg); 
  zx_pop_seen(pop_seen);
  ENC_LEN_DEBUG(x, "mm7:Number", len);
  return len;
}

/* FUNC(zx_ENC_SO_mm7_Number) */

/* Render element into string. The XML attributes and elements are
 * processed in schema order. This is what you generally want for
 * rendering new data structure to a string. The wo pointers are not used. */

/* Called by: */
char* zx_ENC_SO_mm7_Number(struct zx_ctx* c, struct zx_mm7_Number_s* x, char* p )
{
  struct zx_elem_s* se MAYBE_UNUSED;
  struct zx_ns_s* pop_seen = 0;
  ENC_LEN_DEBUG_BASE;
#if 1 /* NORMALMODE */
  /* *** in simple_elem case should output ns prefix from ns node. */
  ZX_OUT_TAG(p, "<mm7:Number");
  if (c->inc_ns)
    p = zx_enc_inc_ns(c, p, &pop_seen);
  p = zx_enc_xmlns_if_not_seen(c, p, zx_ns_tab+zx_xmlns_ix_mm7, &pop_seen);

  p = zx_attr_so_enc(p, x->addressCoding, " addressCoding=\"", sizeof(" addressCoding=\"")-1);
  p = zx_attr_so_enc(p, x->displayOnly, " displayOnly=\"", sizeof(" displayOnly=\"")-1);
  p = zx_attr_so_enc(p, x->id, " id=\"", sizeof(" id=\"")-1);

  p = zx_enc_unknown_attrs(p, x->gg.any_attr);
#else
  /* root node has no begin tag */
#endif
  

  p = zx_enc_so_unknown_elems_and_content(c, p, &x->gg);
  
#if 1 /* NORMALMODE */
  ZX_OUT_CLOSE_TAG(p, "</mm7:Number>");
  zx_pop_seen(pop_seen);
#else
  /* root node has no end tag either */
#endif
  ENC_LEN_DEBUG(x, "mm7:Number", p-enc_base);
  return p;
}

/* FUNC(zx_ENC_WO_mm7_Number) */

/* Render element into string. The XML attributes and elements are
 * processed in wire order by chasing wo pointers. This is what you want for
 * validating signatures on other people's XML documents. */

/* Called by: */
char* zx_ENC_WO_mm7_Number(struct zx_ctx* c, struct zx_mm7_Number_s* x, char* p )
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
  ZX_OUT_MEM(p, "Number", sizeof("Number")-1);
  qq = p;

  /* *** sort the namespaces */
  if (c->inc_ns)
    zx_add_inc_ns(c, &pop_seen);
  zx_add_xmlns_if_not_seen(c, x->gg.g.ns, &pop_seen);

  p = zx_enc_seen(p, pop_seen); 
  p = zx_attr_wo_enc(p, x->addressCoding, "addressCoding=\"", sizeof("addressCoding=\"")-1);
  p = zx_attr_wo_enc(p, x->displayOnly, "displayOnly=\"", sizeof("displayOnly=\"")-1);
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
  ENC_LEN_DEBUG(x, "mm7:Number", p-enc_base);
  return p;
}

/* FUNC(zx_EASY_ENC_SO_mm7_Number) */

/* Called by: */
struct zx_str* zx_EASY_ENC_SO_mm7_Number(struct zx_ctx* c, struct zx_mm7_Number_s* x )
{
  int len;
  char* buf;
  c->ns_tab = ZX_ALLOC(c, sizeof(zx_ns_tab));
  memcpy(c->ns_tab, zx_ns_tab, sizeof(zx_ns_tab));
  len = zx_LEN_SO_mm7_Number(c, x );
  buf = ZX_ALLOC(c, len+1);
  return zx_easy_enc_common(c, zx_ENC_SO_mm7_Number(c, x, buf ), buf, len);
}

/* FUNC(zx_EASY_ENC_WO_mm7_Number) */

/* Called by: */
struct zx_str* zx_EASY_ENC_WO_mm7_Number(struct zx_ctx* c, struct zx_mm7_Number_s* x )
{
  int len;
  char* buf;
  c->ns_tab = ZX_ALLOC(c, sizeof(zx_ns_tab));
  memcpy(c->ns_tab, zx_ns_tab, sizeof(zx_ns_tab));
  len = zx_LEN_WO_mm7_Number(c, x );
  buf = ZX_ALLOC(c, len+1);
  return zx_easy_enc_common(c, zx_ENC_WO_mm7_Number(c, x, buf ), buf, len);
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

#define EL_NAME   mm7_PreferredChannels
#define EL_STRUCT zx_mm7_PreferredChannels_s
#define EL_NS     mm7
#define EL_TAG    PreferredChannels

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

/* FUNC(zx_LEN_SO_mm7_PreferredChannels) */

/* Compute length of an element (and its subelements). The XML attributes
 * and elements are processed in schema order. */

/* Called by: */
int zx_LEN_SO_mm7_PreferredChannels(struct zx_ctx* c, struct zx_mm7_PreferredChannels_s* x )
{
  struct zx_ns_s* pop_seen = 0;
  struct zx_elem_s* se MAYBE_UNUSED;
#if 1 /* NORMALMODE */
  /* *** in simple_elem case should output ns prefix from ns node. */
  int len = sizeof("<mm7:PreferredChannels")-1 + 1 + sizeof("</mm7:PreferredChannels>")-1;
  if (c->inc_ns_len)
    len += zx_len_inc_ns(c, &pop_seen);
  len += zx_len_xmlns_if_not_seen(c, zx_ns_tab+zx_xmlns_ix_mm7, &pop_seen);


#else
  /* root node has no begin tag */
  int len = 0;
#endif
  
  for (se = x->DeliverUsing; se; se = (struct zx_elem_s*)se->g.n)
    len += zx_LEN_SO_simple_elem(c,se, sizeof("mm7:DeliverUsing")-1, zx_ns_tab+zx_xmlns_ix_mm7);


  len += zx_len_so_common(c, &x->gg);
  zx_pop_seen(pop_seen);
  ENC_LEN_DEBUG(x, "mm7:PreferredChannels", len);
  return len;
}

/* FUNC(zx_LEN_WO_mm7_PreferredChannels) */

/* Compute length of an element (and its subelements). The XML attributes
 * and elements are processed in wire order and no assumptions
 * are made about namespace prefixes. */

/* Called by: */
int zx_LEN_WO_mm7_PreferredChannels(struct zx_ctx* c, struct zx_mm7_PreferredChannels_s* x )
{
  struct zx_ns_s* pop_seen = 0;
  struct zx_elem_s* se MAYBE_UNUSED;
#if 1 /* NORMALMODE */
  int len = 1 + sizeof("PreferredChannels")-1 + 1 + 2 + sizeof("PreferredChannels")-1 + 1;
  
  if (x->gg.g.ns && x->gg.g.ns->prefix_len)
    len += (x->gg.g.ns->prefix_len + 1) * 2;
  if (c->inc_ns_len)
    len += zx_len_inc_ns(c, &pop_seen);
  len += zx_len_xmlns_if_not_seen(c, x->gg.g.ns, &pop_seen);


#else
  /* root node has no begin tag */
  int len = 0;
#endif
  
  for (se = x->DeliverUsing; se; se = (struct zx_elem_s*)se->g.n)
    len += zx_LEN_WO_simple_elem(c, se, sizeof("DeliverUsing")-1);


  len += zx_len_wo_common(c, &x->gg); 
  zx_pop_seen(pop_seen);
  ENC_LEN_DEBUG(x, "mm7:PreferredChannels", len);
  return len;
}

/* FUNC(zx_ENC_SO_mm7_PreferredChannels) */

/* Render element into string. The XML attributes and elements are
 * processed in schema order. This is what you generally want for
 * rendering new data structure to a string. The wo pointers are not used. */

/* Called by: */
char* zx_ENC_SO_mm7_PreferredChannels(struct zx_ctx* c, struct zx_mm7_PreferredChannels_s* x, char* p )
{
  struct zx_elem_s* se MAYBE_UNUSED;
  struct zx_ns_s* pop_seen = 0;
  ENC_LEN_DEBUG_BASE;
#if 1 /* NORMALMODE */
  /* *** in simple_elem case should output ns prefix from ns node. */
  ZX_OUT_TAG(p, "<mm7:PreferredChannels");
  if (c->inc_ns)
    p = zx_enc_inc_ns(c, p, &pop_seen);
  p = zx_enc_xmlns_if_not_seen(c, p, zx_ns_tab+zx_xmlns_ix_mm7, &pop_seen);


  p = zx_enc_unknown_attrs(p, x->gg.any_attr);
#else
  /* root node has no begin tag */
#endif
  
  for (se = x->DeliverUsing; se; se = (struct zx_elem_s*)se->g.n)
    p = zx_ENC_SO_simple_elem(c, se, p, "mm7:DeliverUsing", sizeof("mm7:DeliverUsing")-1, zx_ns_tab+zx_xmlns_ix_mm7);

  p = zx_enc_so_unknown_elems_and_content(c, p, &x->gg);
  
#if 1 /* NORMALMODE */
  ZX_OUT_CLOSE_TAG(p, "</mm7:PreferredChannels>");
  zx_pop_seen(pop_seen);
#else
  /* root node has no end tag either */
#endif
  ENC_LEN_DEBUG(x, "mm7:PreferredChannels", p-enc_base);
  return p;
}

/* FUNC(zx_ENC_WO_mm7_PreferredChannels) */

/* Render element into string. The XML attributes and elements are
 * processed in wire order by chasing wo pointers. This is what you want for
 * validating signatures on other people's XML documents. */

/* Called by: */
char* zx_ENC_WO_mm7_PreferredChannels(struct zx_ctx* c, struct zx_mm7_PreferredChannels_s* x, char* p )
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
  ZX_OUT_MEM(p, "PreferredChannels", sizeof("PreferredChannels")-1);
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
  ENC_LEN_DEBUG(x, "mm7:PreferredChannels", p-enc_base);
  return p;
}

/* FUNC(zx_EASY_ENC_SO_mm7_PreferredChannels) */

/* Called by: */
struct zx_str* zx_EASY_ENC_SO_mm7_PreferredChannels(struct zx_ctx* c, struct zx_mm7_PreferredChannels_s* x )
{
  int len;
  char* buf;
  c->ns_tab = ZX_ALLOC(c, sizeof(zx_ns_tab));
  memcpy(c->ns_tab, zx_ns_tab, sizeof(zx_ns_tab));
  len = zx_LEN_SO_mm7_PreferredChannels(c, x );
  buf = ZX_ALLOC(c, len+1);
  return zx_easy_enc_common(c, zx_ENC_SO_mm7_PreferredChannels(c, x, buf ), buf, len);
}

/* FUNC(zx_EASY_ENC_WO_mm7_PreferredChannels) */

/* Called by: */
struct zx_str* zx_EASY_ENC_WO_mm7_PreferredChannels(struct zx_ctx* c, struct zx_mm7_PreferredChannels_s* x )
{
  int len;
  char* buf;
  c->ns_tab = ZX_ALLOC(c, sizeof(zx_ns_tab));
  memcpy(c->ns_tab, zx_ns_tab, sizeof(zx_ns_tab));
  len = zx_LEN_WO_mm7_PreferredChannels(c, x );
  buf = ZX_ALLOC(c, len+1);
  return zx_easy_enc_common(c, zx_ENC_WO_mm7_PreferredChannels(c, x, buf ), buf, len);
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

#define EL_NAME   mm7_Previouslysentby
#define EL_STRUCT zx_mm7_Previouslysentby_s
#define EL_NS     mm7
#define EL_TAG    Previouslysentby

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

/* FUNC(zx_LEN_SO_mm7_Previouslysentby) */

/* Compute length of an element (and its subelements). The XML attributes
 * and elements are processed in schema order. */

/* Called by: */
int zx_LEN_SO_mm7_Previouslysentby(struct zx_ctx* c, struct zx_mm7_Previouslysentby_s* x )
{
  struct zx_ns_s* pop_seen = 0;
  struct zx_elem_s* se MAYBE_UNUSED;
#if 1 /* NORMALMODE */
  /* *** in simple_elem case should output ns prefix from ns node. */
  int len = sizeof("<mm7:Previouslysentby")-1 + 1 + sizeof("</mm7:Previouslysentby>")-1;
  if (c->inc_ns_len)
    len += zx_len_inc_ns(c, &pop_seen);
  len += zx_len_xmlns_if_not_seen(c, zx_ns_tab+zx_xmlns_ix_mm7, &pop_seen);


#else
  /* root node has no begin tag */
  int len = 0;
#endif
  
  {
      struct zx_mm7_UserAgent_s* e;
      for (e = x->UserAgent; e; e = (struct zx_mm7_UserAgent_s*)e->gg.g.n)
	  len += zx_LEN_SO_mm7_UserAgent(c, e);
  }


  len += zx_len_so_common(c, &x->gg);
  zx_pop_seen(pop_seen);
  ENC_LEN_DEBUG(x, "mm7:Previouslysentby", len);
  return len;
}

/* FUNC(zx_LEN_WO_mm7_Previouslysentby) */

/* Compute length of an element (and its subelements). The XML attributes
 * and elements are processed in wire order and no assumptions
 * are made about namespace prefixes. */

/* Called by: */
int zx_LEN_WO_mm7_Previouslysentby(struct zx_ctx* c, struct zx_mm7_Previouslysentby_s* x )
{
  struct zx_ns_s* pop_seen = 0;
  struct zx_elem_s* se MAYBE_UNUSED;
#if 1 /* NORMALMODE */
  int len = 1 + sizeof("Previouslysentby")-1 + 1 + 2 + sizeof("Previouslysentby")-1 + 1;
  
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
      struct zx_mm7_UserAgent_s* e;
      for (e = x->UserAgent; e; e = (struct zx_mm7_UserAgent_s*)e->gg.g.n)
	  len += zx_LEN_WO_mm7_UserAgent(c, e);
  }


  len += zx_len_wo_common(c, &x->gg); 
  zx_pop_seen(pop_seen);
  ENC_LEN_DEBUG(x, "mm7:Previouslysentby", len);
  return len;
}

/* FUNC(zx_ENC_SO_mm7_Previouslysentby) */

/* Render element into string. The XML attributes and elements are
 * processed in schema order. This is what you generally want for
 * rendering new data structure to a string. The wo pointers are not used. */

/* Called by: */
char* zx_ENC_SO_mm7_Previouslysentby(struct zx_ctx* c, struct zx_mm7_Previouslysentby_s* x, char* p )
{
  struct zx_elem_s* se MAYBE_UNUSED;
  struct zx_ns_s* pop_seen = 0;
  ENC_LEN_DEBUG_BASE;
#if 1 /* NORMALMODE */
  /* *** in simple_elem case should output ns prefix from ns node. */
  ZX_OUT_TAG(p, "<mm7:Previouslysentby");
  if (c->inc_ns)
    p = zx_enc_inc_ns(c, p, &pop_seen);
  p = zx_enc_xmlns_if_not_seen(c, p, zx_ns_tab+zx_xmlns_ix_mm7, &pop_seen);


  p = zx_enc_unknown_attrs(p, x->gg.any_attr);
#else
  /* root node has no begin tag */
#endif
  
  {
      struct zx_mm7_UserAgent_s* e;
      for (e = x->UserAgent; e; e = (struct zx_mm7_UserAgent_s*)e->gg.g.n)
	  p = zx_ENC_SO_mm7_UserAgent(c, e, p);
  }

  p = zx_enc_so_unknown_elems_and_content(c, p, &x->gg);
  
#if 1 /* NORMALMODE */
  ZX_OUT_CLOSE_TAG(p, "</mm7:Previouslysentby>");
  zx_pop_seen(pop_seen);
#else
  /* root node has no end tag either */
#endif
  ENC_LEN_DEBUG(x, "mm7:Previouslysentby", p-enc_base);
  return p;
}

/* FUNC(zx_ENC_WO_mm7_Previouslysentby) */

/* Render element into string. The XML attributes and elements are
 * processed in wire order by chasing wo pointers. This is what you want for
 * validating signatures on other people's XML documents. */

/* Called by: */
char* zx_ENC_WO_mm7_Previouslysentby(struct zx_ctx* c, struct zx_mm7_Previouslysentby_s* x, char* p )
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
  ZX_OUT_MEM(p, "Previouslysentby", sizeof("Previouslysentby")-1);
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
  ENC_LEN_DEBUG(x, "mm7:Previouslysentby", p-enc_base);
  return p;
}

/* FUNC(zx_EASY_ENC_SO_mm7_Previouslysentby) */

/* Called by: */
struct zx_str* zx_EASY_ENC_SO_mm7_Previouslysentby(struct zx_ctx* c, struct zx_mm7_Previouslysentby_s* x )
{
  int len;
  char* buf;
  c->ns_tab = ZX_ALLOC(c, sizeof(zx_ns_tab));
  memcpy(c->ns_tab, zx_ns_tab, sizeof(zx_ns_tab));
  len = zx_LEN_SO_mm7_Previouslysentby(c, x );
  buf = ZX_ALLOC(c, len+1);
  return zx_easy_enc_common(c, zx_ENC_SO_mm7_Previouslysentby(c, x, buf ), buf, len);
}

/* FUNC(zx_EASY_ENC_WO_mm7_Previouslysentby) */

/* Called by: */
struct zx_str* zx_EASY_ENC_WO_mm7_Previouslysentby(struct zx_ctx* c, struct zx_mm7_Previouslysentby_s* x )
{
  int len;
  char* buf;
  c->ns_tab = ZX_ALLOC(c, sizeof(zx_ns_tab));
  memcpy(c->ns_tab, zx_ns_tab, sizeof(zx_ns_tab));
  len = zx_LEN_WO_mm7_Previouslysentby(c, x );
  buf = ZX_ALLOC(c, len+1);
  return zx_easy_enc_common(c, zx_ENC_WO_mm7_Previouslysentby(c, x, buf ), buf, len);
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

#define EL_NAME   mm7_Previouslysentdateandtime
#define EL_STRUCT zx_mm7_Previouslysentdateandtime_s
#define EL_NS     mm7
#define EL_TAG    Previouslysentdateandtime

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

/* FUNC(zx_LEN_SO_mm7_Previouslysentdateandtime) */

/* Compute length of an element (and its subelements). The XML attributes
 * and elements are processed in schema order. */

/* Called by: */
int zx_LEN_SO_mm7_Previouslysentdateandtime(struct zx_ctx* c, struct zx_mm7_Previouslysentdateandtime_s* x )
{
  struct zx_ns_s* pop_seen = 0;
  struct zx_elem_s* se MAYBE_UNUSED;
#if 1 /* NORMALMODE */
  /* *** in simple_elem case should output ns prefix from ns node. */
  int len = sizeof("<mm7:Previouslysentdateandtime")-1 + 1 + sizeof("</mm7:Previouslysentdateandtime>")-1;
  if (c->inc_ns_len)
    len += zx_len_inc_ns(c, &pop_seen);
  len += zx_len_xmlns_if_not_seen(c, zx_ns_tab+zx_xmlns_ix_mm7, &pop_seen);


#else
  /* root node has no begin tag */
  int len = 0;
#endif
  
  {
      struct zx_mm7_DateTime_s* e;
      for (e = x->DateTime; e; e = (struct zx_mm7_DateTime_s*)e->gg.g.n)
	  len += zx_LEN_SO_mm7_DateTime(c, e);
  }


  len += zx_len_so_common(c, &x->gg);
  zx_pop_seen(pop_seen);
  ENC_LEN_DEBUG(x, "mm7:Previouslysentdateandtime", len);
  return len;
}

/* FUNC(zx_LEN_WO_mm7_Previouslysentdateandtime) */

/* Compute length of an element (and its subelements). The XML attributes
 * and elements are processed in wire order and no assumptions
 * are made about namespace prefixes. */

/* Called by: */
int zx_LEN_WO_mm7_Previouslysentdateandtime(struct zx_ctx* c, struct zx_mm7_Previouslysentdateandtime_s* x )
{
  struct zx_ns_s* pop_seen = 0;
  struct zx_elem_s* se MAYBE_UNUSED;
#if 1 /* NORMALMODE */
  int len = 1 + sizeof("Previouslysentdateandtime")-1 + 1 + 2 + sizeof("Previouslysentdateandtime")-1 + 1;
  
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
      struct zx_mm7_DateTime_s* e;
      for (e = x->DateTime; e; e = (struct zx_mm7_DateTime_s*)e->gg.g.n)
	  len += zx_LEN_WO_mm7_DateTime(c, e);
  }


  len += zx_len_wo_common(c, &x->gg); 
  zx_pop_seen(pop_seen);
  ENC_LEN_DEBUG(x, "mm7:Previouslysentdateandtime", len);
  return len;
}

/* FUNC(zx_ENC_SO_mm7_Previouslysentdateandtime) */

/* Render element into string. The XML attributes and elements are
 * processed in schema order. This is what you generally want for
 * rendering new data structure to a string. The wo pointers are not used. */

/* Called by: */
char* zx_ENC_SO_mm7_Previouslysentdateandtime(struct zx_ctx* c, struct zx_mm7_Previouslysentdateandtime_s* x, char* p )
{
  struct zx_elem_s* se MAYBE_UNUSED;
  struct zx_ns_s* pop_seen = 0;
  ENC_LEN_DEBUG_BASE;
#if 1 /* NORMALMODE */
  /* *** in simple_elem case should output ns prefix from ns node. */
  ZX_OUT_TAG(p, "<mm7:Previouslysentdateandtime");
  if (c->inc_ns)
    p = zx_enc_inc_ns(c, p, &pop_seen);
  p = zx_enc_xmlns_if_not_seen(c, p, zx_ns_tab+zx_xmlns_ix_mm7, &pop_seen);


  p = zx_enc_unknown_attrs(p, x->gg.any_attr);
#else
  /* root node has no begin tag */
#endif
  
  {
      struct zx_mm7_DateTime_s* e;
      for (e = x->DateTime; e; e = (struct zx_mm7_DateTime_s*)e->gg.g.n)
	  p = zx_ENC_SO_mm7_DateTime(c, e, p);
  }

  p = zx_enc_so_unknown_elems_and_content(c, p, &x->gg);
  
#if 1 /* NORMALMODE */
  ZX_OUT_CLOSE_TAG(p, "</mm7:Previouslysentdateandtime>");
  zx_pop_seen(pop_seen);
#else
  /* root node has no end tag either */
#endif
  ENC_LEN_DEBUG(x, "mm7:Previouslysentdateandtime", p-enc_base);
  return p;
}

/* FUNC(zx_ENC_WO_mm7_Previouslysentdateandtime) */

/* Render element into string. The XML attributes and elements are
 * processed in wire order by chasing wo pointers. This is what you want for
 * validating signatures on other people's XML documents. */

/* Called by: */
char* zx_ENC_WO_mm7_Previouslysentdateandtime(struct zx_ctx* c, struct zx_mm7_Previouslysentdateandtime_s* x, char* p )
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
  ZX_OUT_MEM(p, "Previouslysentdateandtime", sizeof("Previouslysentdateandtime")-1);
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
  ENC_LEN_DEBUG(x, "mm7:Previouslysentdateandtime", p-enc_base);
  return p;
}

/* FUNC(zx_EASY_ENC_SO_mm7_Previouslysentdateandtime) */

/* Called by: */
struct zx_str* zx_EASY_ENC_SO_mm7_Previouslysentdateandtime(struct zx_ctx* c, struct zx_mm7_Previouslysentdateandtime_s* x )
{
  int len;
  char* buf;
  c->ns_tab = ZX_ALLOC(c, sizeof(zx_ns_tab));
  memcpy(c->ns_tab, zx_ns_tab, sizeof(zx_ns_tab));
  len = zx_LEN_SO_mm7_Previouslysentdateandtime(c, x );
  buf = ZX_ALLOC(c, len+1);
  return zx_easy_enc_common(c, zx_ENC_SO_mm7_Previouslysentdateandtime(c, x, buf ), buf, len);
}

/* FUNC(zx_EASY_ENC_WO_mm7_Previouslysentdateandtime) */

/* Called by: */
struct zx_str* zx_EASY_ENC_WO_mm7_Previouslysentdateandtime(struct zx_ctx* c, struct zx_mm7_Previouslysentdateandtime_s* x )
{
  int len;
  char* buf;
  c->ns_tab = ZX_ALLOC(c, sizeof(zx_ns_tab));
  memcpy(c->ns_tab, zx_ns_tab, sizeof(zx_ns_tab));
  len = zx_LEN_WO_mm7_Previouslysentdateandtime(c, x );
  buf = ZX_ALLOC(c, len+1);
  return zx_easy_enc_common(c, zx_ENC_WO_mm7_Previouslysentdateandtime(c, x, buf ), buf, len);
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

#define EL_NAME   mm7_QueryStatusReq
#define EL_STRUCT zx_mm7_QueryStatusReq_s
#define EL_NS     mm7
#define EL_TAG    QueryStatusReq

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

/* FUNC(zx_LEN_SO_mm7_QueryStatusReq) */

/* Compute length of an element (and its subelements). The XML attributes
 * and elements are processed in schema order. */

/* Called by: */
int zx_LEN_SO_mm7_QueryStatusReq(struct zx_ctx* c, struct zx_mm7_QueryStatusReq_s* x )
{
  struct zx_ns_s* pop_seen = 0;
  struct zx_elem_s* se MAYBE_UNUSED;
#if 1 /* NORMALMODE */
  /* *** in simple_elem case should output ns prefix from ns node. */
  int len = sizeof("<mm7:QueryStatusReq")-1 + 1 + sizeof("</mm7:QueryStatusReq>")-1;
  if (c->inc_ns_len)
    len += zx_len_inc_ns(c, &pop_seen);
  len += zx_len_xmlns_if_not_seen(c, zx_ns_tab+zx_xmlns_ix_mm7, &pop_seen);


#else
  /* root node has no begin tag */
  int len = 0;
#endif
  
  {
      struct zx_mm7_TransactionID_s* e;
      for (e = x->TransactionID; e; e = (struct zx_mm7_TransactionID_s*)e->gg.g.n)
	  len += zx_LEN_SO_mm7_TransactionID(c, e);
  }
  for (se = x->MessageType; se; se = (struct zx_elem_s*)se->g.n)
    len += zx_LEN_SO_simple_elem(c,se, sizeof("mm7:MessageType")-1, zx_ns_tab+zx_xmlns_ix_mm7);
  for (se = x->MM7Version; se; se = (struct zx_elem_s*)se->g.n)
    len += zx_LEN_SO_simple_elem(c,se, sizeof("mm7:MM7Version")-1, zx_ns_tab+zx_xmlns_ix_mm7);
  for (se = x->VASPID; se; se = (struct zx_elem_s*)se->g.n)
    len += zx_LEN_SO_simple_elem(c,se, sizeof("mm7:VASPID")-1, zx_ns_tab+zx_xmlns_ix_mm7);
  for (se = x->VASID; se; se = (struct zx_elem_s*)se->g.n)
    len += zx_LEN_SO_simple_elem(c,se, sizeof("mm7:VASID")-1, zx_ns_tab+zx_xmlns_ix_mm7);
  for (se = x->MessageID; se; se = (struct zx_elem_s*)se->g.n)
    len += zx_LEN_SO_simple_elem(c,se, sizeof("mm7:MessageID")-1, zx_ns_tab+zx_xmlns_ix_mm7);


  len += zx_len_so_common(c, &x->gg);
  zx_pop_seen(pop_seen);
  ENC_LEN_DEBUG(x, "mm7:QueryStatusReq", len);
  return len;
}

/* FUNC(zx_LEN_WO_mm7_QueryStatusReq) */

/* Compute length of an element (and its subelements). The XML attributes
 * and elements are processed in wire order and no assumptions
 * are made about namespace prefixes. */

/* Called by: */
int zx_LEN_WO_mm7_QueryStatusReq(struct zx_ctx* c, struct zx_mm7_QueryStatusReq_s* x )
{
  struct zx_ns_s* pop_seen = 0;
  struct zx_elem_s* se MAYBE_UNUSED;
#if 1 /* NORMALMODE */
  int len = 1 + sizeof("QueryStatusReq")-1 + 1 + 2 + sizeof("QueryStatusReq")-1 + 1;
  
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
      struct zx_mm7_TransactionID_s* e;
      for (e = x->TransactionID; e; e = (struct zx_mm7_TransactionID_s*)e->gg.g.n)
	  len += zx_LEN_WO_mm7_TransactionID(c, e);
  }
  for (se = x->MessageType; se; se = (struct zx_elem_s*)se->g.n)
    len += zx_LEN_WO_simple_elem(c, se, sizeof("MessageType")-1);
  for (se = x->MM7Version; se; se = (struct zx_elem_s*)se->g.n)
    len += zx_LEN_WO_simple_elem(c, se, sizeof("MM7Version")-1);
  for (se = x->VASPID; se; se = (struct zx_elem_s*)se->g.n)
    len += zx_LEN_WO_simple_elem(c, se, sizeof("VASPID")-1);
  for (se = x->VASID; se; se = (struct zx_elem_s*)se->g.n)
    len += zx_LEN_WO_simple_elem(c, se, sizeof("VASID")-1);
  for (se = x->MessageID; se; se = (struct zx_elem_s*)se->g.n)
    len += zx_LEN_WO_simple_elem(c, se, sizeof("MessageID")-1);


  len += zx_len_wo_common(c, &x->gg); 
  zx_pop_seen(pop_seen);
  ENC_LEN_DEBUG(x, "mm7:QueryStatusReq", len);
  return len;
}

/* FUNC(zx_ENC_SO_mm7_QueryStatusReq) */

/* Render element into string. The XML attributes and elements are
 * processed in schema order. This is what you generally want for
 * rendering new data structure to a string. The wo pointers are not used. */

/* Called by: */
char* zx_ENC_SO_mm7_QueryStatusReq(struct zx_ctx* c, struct zx_mm7_QueryStatusReq_s* x, char* p )
{
  struct zx_elem_s* se MAYBE_UNUSED;
  struct zx_ns_s* pop_seen = 0;
  ENC_LEN_DEBUG_BASE;
#if 1 /* NORMALMODE */
  /* *** in simple_elem case should output ns prefix from ns node. */
  ZX_OUT_TAG(p, "<mm7:QueryStatusReq");
  if (c->inc_ns)
    p = zx_enc_inc_ns(c, p, &pop_seen);
  p = zx_enc_xmlns_if_not_seen(c, p, zx_ns_tab+zx_xmlns_ix_mm7, &pop_seen);


  p = zx_enc_unknown_attrs(p, x->gg.any_attr);
#else
  /* root node has no begin tag */
#endif
  
  {
      struct zx_mm7_TransactionID_s* e;
      for (e = x->TransactionID; e; e = (struct zx_mm7_TransactionID_s*)e->gg.g.n)
	  p = zx_ENC_SO_mm7_TransactionID(c, e, p);
  }
  for (se = x->MessageType; se; se = (struct zx_elem_s*)se->g.n)
    p = zx_ENC_SO_simple_elem(c, se, p, "mm7:MessageType", sizeof("mm7:MessageType")-1, zx_ns_tab+zx_xmlns_ix_mm7);
  for (se = x->MM7Version; se; se = (struct zx_elem_s*)se->g.n)
    p = zx_ENC_SO_simple_elem(c, se, p, "mm7:MM7Version", sizeof("mm7:MM7Version")-1, zx_ns_tab+zx_xmlns_ix_mm7);
  for (se = x->VASPID; se; se = (struct zx_elem_s*)se->g.n)
    p = zx_ENC_SO_simple_elem(c, se, p, "mm7:VASPID", sizeof("mm7:VASPID")-1, zx_ns_tab+zx_xmlns_ix_mm7);
  for (se = x->VASID; se; se = (struct zx_elem_s*)se->g.n)
    p = zx_ENC_SO_simple_elem(c, se, p, "mm7:VASID", sizeof("mm7:VASID")-1, zx_ns_tab+zx_xmlns_ix_mm7);
  for (se = x->MessageID; se; se = (struct zx_elem_s*)se->g.n)
    p = zx_ENC_SO_simple_elem(c, se, p, "mm7:MessageID", sizeof("mm7:MessageID")-1, zx_ns_tab+zx_xmlns_ix_mm7);

  p = zx_enc_so_unknown_elems_and_content(c, p, &x->gg);
  
#if 1 /* NORMALMODE */
  ZX_OUT_CLOSE_TAG(p, "</mm7:QueryStatusReq>");
  zx_pop_seen(pop_seen);
#else
  /* root node has no end tag either */
#endif
  ENC_LEN_DEBUG(x, "mm7:QueryStatusReq", p-enc_base);
  return p;
}

/* FUNC(zx_ENC_WO_mm7_QueryStatusReq) */

/* Render element into string. The XML attributes and elements are
 * processed in wire order by chasing wo pointers. This is what you want for
 * validating signatures on other people's XML documents. */

/* Called by: */
char* zx_ENC_WO_mm7_QueryStatusReq(struct zx_ctx* c, struct zx_mm7_QueryStatusReq_s* x, char* p )
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
  ZX_OUT_MEM(p, "QueryStatusReq", sizeof("QueryStatusReq")-1);
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
  ENC_LEN_DEBUG(x, "mm7:QueryStatusReq", p-enc_base);
  return p;
}

/* FUNC(zx_EASY_ENC_SO_mm7_QueryStatusReq) */

/* Called by: */
struct zx_str* zx_EASY_ENC_SO_mm7_QueryStatusReq(struct zx_ctx* c, struct zx_mm7_QueryStatusReq_s* x )
{
  int len;
  char* buf;
  c->ns_tab = ZX_ALLOC(c, sizeof(zx_ns_tab));
  memcpy(c->ns_tab, zx_ns_tab, sizeof(zx_ns_tab));
  len = zx_LEN_SO_mm7_QueryStatusReq(c, x );
  buf = ZX_ALLOC(c, len+1);
  return zx_easy_enc_common(c, zx_ENC_SO_mm7_QueryStatusReq(c, x, buf ), buf, len);
}

/* FUNC(zx_EASY_ENC_WO_mm7_QueryStatusReq) */

/* Called by: */
struct zx_str* zx_EASY_ENC_WO_mm7_QueryStatusReq(struct zx_ctx* c, struct zx_mm7_QueryStatusReq_s* x )
{
  int len;
  char* buf;
  c->ns_tab = ZX_ALLOC(c, sizeof(zx_ns_tab));
  memcpy(c->ns_tab, zx_ns_tab, sizeof(zx_ns_tab));
  len = zx_LEN_WO_mm7_QueryStatusReq(c, x );
  buf = ZX_ALLOC(c, len+1);
  return zx_easy_enc_common(c, zx_ENC_WO_mm7_QueryStatusReq(c, x, buf ), buf, len);
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

#define EL_NAME   mm7_QueryStatusRsp
#define EL_STRUCT zx_mm7_QueryStatusRsp_s
#define EL_NS     mm7
#define EL_TAG    QueryStatusRsp

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

/* FUNC(zx_LEN_SO_mm7_QueryStatusRsp) */

/* Compute length of an element (and its subelements). The XML attributes
 * and elements are processed in schema order. */

/* Called by: */
int zx_LEN_SO_mm7_QueryStatusRsp(struct zx_ctx* c, struct zx_mm7_QueryStatusRsp_s* x )
{
  struct zx_ns_s* pop_seen = 0;
  struct zx_elem_s* se MAYBE_UNUSED;
#if 1 /* NORMALMODE */
  /* *** in simple_elem case should output ns prefix from ns node. */
  int len = sizeof("<mm7:QueryStatusRsp")-1 + 1 + sizeof("</mm7:QueryStatusRsp>")-1;
  if (c->inc_ns_len)
    len += zx_len_inc_ns(c, &pop_seen);
  len += zx_len_xmlns_if_not_seen(c, zx_ns_tab+zx_xmlns_ix_mm7, &pop_seen);


#else
  /* root node has no begin tag */
  int len = 0;
#endif
  
  {
      struct zx_mm7_TransactionID_s* e;
      for (e = x->TransactionID; e; e = (struct zx_mm7_TransactionID_s*)e->gg.g.n)
	  len += zx_LEN_SO_mm7_TransactionID(c, e);
  }
  for (se = x->MessageType; se; se = (struct zx_elem_s*)se->g.n)
    len += zx_LEN_SO_simple_elem(c,se, sizeof("mm7:MessageType")-1, zx_ns_tab+zx_xmlns_ix_mm7);
  for (se = x->MM7Version; se; se = (struct zx_elem_s*)se->g.n)
    len += zx_LEN_SO_simple_elem(c,se, sizeof("mm7:MM7Version")-1, zx_ns_tab+zx_xmlns_ix_mm7);
  for (se = x->StatusCode; se; se = (struct zx_elem_s*)se->g.n)
    len += zx_LEN_SO_simple_elem(c,se, sizeof("mm7:StatusCode")-1, zx_ns_tab+zx_xmlns_ix_mm7);
  for (se = x->StatusText; se; se = (struct zx_elem_s*)se->g.n)
    len += zx_LEN_SO_simple_elem(c,se, sizeof("mm7:StatusText")-1, zx_ns_tab+zx_xmlns_ix_mm7);
  {
      struct zx_mm7_Details_s* e;
      for (e = x->Details; e; e = (struct zx_mm7_Details_s*)e->gg.g.n)
	  len += zx_LEN_SO_mm7_Details(c, e);
  }


  len += zx_len_so_common(c, &x->gg);
  zx_pop_seen(pop_seen);
  ENC_LEN_DEBUG(x, "mm7:QueryStatusRsp", len);
  return len;
}

/* FUNC(zx_LEN_WO_mm7_QueryStatusRsp) */

/* Compute length of an element (and its subelements). The XML attributes
 * and elements are processed in wire order and no assumptions
 * are made about namespace prefixes. */

/* Called by: */
int zx_LEN_WO_mm7_QueryStatusRsp(struct zx_ctx* c, struct zx_mm7_QueryStatusRsp_s* x )
{
  struct zx_ns_s* pop_seen = 0;
  struct zx_elem_s* se MAYBE_UNUSED;
#if 1 /* NORMALMODE */
  int len = 1 + sizeof("QueryStatusRsp")-1 + 1 + 2 + sizeof("QueryStatusRsp")-1 + 1;
  
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
      struct zx_mm7_TransactionID_s* e;
      for (e = x->TransactionID; e; e = (struct zx_mm7_TransactionID_s*)e->gg.g.n)
	  len += zx_LEN_WO_mm7_TransactionID(c, e);
  }
  for (se = x->MessageType; se; se = (struct zx_elem_s*)se->g.n)
    len += zx_LEN_WO_simple_elem(c, se, sizeof("MessageType")-1);
  for (se = x->MM7Version; se; se = (struct zx_elem_s*)se->g.n)
    len += zx_LEN_WO_simple_elem(c, se, sizeof("MM7Version")-1);
  for (se = x->StatusCode; se; se = (struct zx_elem_s*)se->g.n)
    len += zx_LEN_WO_simple_elem(c, se, sizeof("StatusCode")-1);
  for (se = x->StatusText; se; se = (struct zx_elem_s*)se->g.n)
    len += zx_LEN_WO_simple_elem(c, se, sizeof("StatusText")-1);
  {
      struct zx_mm7_Details_s* e;
      for (e = x->Details; e; e = (struct zx_mm7_Details_s*)e->gg.g.n)
	  len += zx_LEN_WO_mm7_Details(c, e);
  }


  len += zx_len_wo_common(c, &x->gg); 
  zx_pop_seen(pop_seen);
  ENC_LEN_DEBUG(x, "mm7:QueryStatusRsp", len);
  return len;
}

/* FUNC(zx_ENC_SO_mm7_QueryStatusRsp) */

/* Render element into string. The XML attributes and elements are
 * processed in schema order. This is what you generally want for
 * rendering new data structure to a string. The wo pointers are not used. */

/* Called by: */
char* zx_ENC_SO_mm7_QueryStatusRsp(struct zx_ctx* c, struct zx_mm7_QueryStatusRsp_s* x, char* p )
{
  struct zx_elem_s* se MAYBE_UNUSED;
  struct zx_ns_s* pop_seen = 0;
  ENC_LEN_DEBUG_BASE;
#if 1 /* NORMALMODE */
  /* *** in simple_elem case should output ns prefix from ns node. */
  ZX_OUT_TAG(p, "<mm7:QueryStatusRsp");
  if (c->inc_ns)
    p = zx_enc_inc_ns(c, p, &pop_seen);
  p = zx_enc_xmlns_if_not_seen(c, p, zx_ns_tab+zx_xmlns_ix_mm7, &pop_seen);


  p = zx_enc_unknown_attrs(p, x->gg.any_attr);
#else
  /* root node has no begin tag */
#endif
  
  {
      struct zx_mm7_TransactionID_s* e;
      for (e = x->TransactionID; e; e = (struct zx_mm7_TransactionID_s*)e->gg.g.n)
	  p = zx_ENC_SO_mm7_TransactionID(c, e, p);
  }
  for (se = x->MessageType; se; se = (struct zx_elem_s*)se->g.n)
    p = zx_ENC_SO_simple_elem(c, se, p, "mm7:MessageType", sizeof("mm7:MessageType")-1, zx_ns_tab+zx_xmlns_ix_mm7);
  for (se = x->MM7Version; se; se = (struct zx_elem_s*)se->g.n)
    p = zx_ENC_SO_simple_elem(c, se, p, "mm7:MM7Version", sizeof("mm7:MM7Version")-1, zx_ns_tab+zx_xmlns_ix_mm7);
  for (se = x->StatusCode; se; se = (struct zx_elem_s*)se->g.n)
    p = zx_ENC_SO_simple_elem(c, se, p, "mm7:StatusCode", sizeof("mm7:StatusCode")-1, zx_ns_tab+zx_xmlns_ix_mm7);
  for (se = x->StatusText; se; se = (struct zx_elem_s*)se->g.n)
    p = zx_ENC_SO_simple_elem(c, se, p, "mm7:StatusText", sizeof("mm7:StatusText")-1, zx_ns_tab+zx_xmlns_ix_mm7);
  {
      struct zx_mm7_Details_s* e;
      for (e = x->Details; e; e = (struct zx_mm7_Details_s*)e->gg.g.n)
	  p = zx_ENC_SO_mm7_Details(c, e, p);
  }

  p = zx_enc_so_unknown_elems_and_content(c, p, &x->gg);
  
#if 1 /* NORMALMODE */
  ZX_OUT_CLOSE_TAG(p, "</mm7:QueryStatusRsp>");
  zx_pop_seen(pop_seen);
#else
  /* root node has no end tag either */
#endif
  ENC_LEN_DEBUG(x, "mm7:QueryStatusRsp", p-enc_base);
  return p;
}

/* FUNC(zx_ENC_WO_mm7_QueryStatusRsp) */

/* Render element into string. The XML attributes and elements are
 * processed in wire order by chasing wo pointers. This is what you want for
 * validating signatures on other people's XML documents. */

/* Called by: */
char* zx_ENC_WO_mm7_QueryStatusRsp(struct zx_ctx* c, struct zx_mm7_QueryStatusRsp_s* x, char* p )
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
  ZX_OUT_MEM(p, "QueryStatusRsp", sizeof("QueryStatusRsp")-1);
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
  ENC_LEN_DEBUG(x, "mm7:QueryStatusRsp", p-enc_base);
  return p;
}

/* FUNC(zx_EASY_ENC_SO_mm7_QueryStatusRsp) */

/* Called by: */
struct zx_str* zx_EASY_ENC_SO_mm7_QueryStatusRsp(struct zx_ctx* c, struct zx_mm7_QueryStatusRsp_s* x )
{
  int len;
  char* buf;
  c->ns_tab = ZX_ALLOC(c, sizeof(zx_ns_tab));
  memcpy(c->ns_tab, zx_ns_tab, sizeof(zx_ns_tab));
  len = zx_LEN_SO_mm7_QueryStatusRsp(c, x );
  buf = ZX_ALLOC(c, len+1);
  return zx_easy_enc_common(c, zx_ENC_SO_mm7_QueryStatusRsp(c, x, buf ), buf, len);
}

/* FUNC(zx_EASY_ENC_WO_mm7_QueryStatusRsp) */

/* Called by: */
struct zx_str* zx_EASY_ENC_WO_mm7_QueryStatusRsp(struct zx_ctx* c, struct zx_mm7_QueryStatusRsp_s* x )
{
  int len;
  char* buf;
  c->ns_tab = ZX_ALLOC(c, sizeof(zx_ns_tab));
  memcpy(c->ns_tab, zx_ns_tab, sizeof(zx_ns_tab));
  len = zx_LEN_WO_mm7_QueryStatusRsp(c, x );
  buf = ZX_ALLOC(c, len+1);
  return zx_easy_enc_common(c, zx_ENC_WO_mm7_QueryStatusRsp(c, x, buf ), buf, len);
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

#define EL_NAME   mm7_RFC2822Address
#define EL_STRUCT zx_mm7_RFC2822Address_s
#define EL_NS     mm7
#define EL_TAG    RFC2822Address

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

/* FUNC(zx_LEN_SO_mm7_RFC2822Address) */

/* Compute length of an element (and its subelements). The XML attributes
 * and elements are processed in schema order. */

/* Called by: */
int zx_LEN_SO_mm7_RFC2822Address(struct zx_ctx* c, struct zx_mm7_RFC2822Address_s* x )
{
  struct zx_ns_s* pop_seen = 0;
  struct zx_elem_s* se MAYBE_UNUSED;
#if 1 /* NORMALMODE */
  /* *** in simple_elem case should output ns prefix from ns node. */
  int len = sizeof("<mm7:RFC2822Address")-1 + 1 + sizeof("</mm7:RFC2822Address>")-1;
  if (c->inc_ns_len)
    len += zx_len_inc_ns(c, &pop_seen);
  len += zx_len_xmlns_if_not_seen(c, zx_ns_tab+zx_xmlns_ix_mm7, &pop_seen);

  len += zx_attr_so_len(x->addressCoding, sizeof("addressCoding")-1);
  len += zx_attr_so_len(x->displayOnly, sizeof("displayOnly")-1);
  len += zx_attr_so_len(x->id, sizeof("id")-1);

#else
  /* root node has no begin tag */
  int len = 0;
#endif
  


  len += zx_len_so_common(c, &x->gg);
  zx_pop_seen(pop_seen);
  ENC_LEN_DEBUG(x, "mm7:RFC2822Address", len);
  return len;
}

/* FUNC(zx_LEN_WO_mm7_RFC2822Address) */

/* Compute length of an element (and its subelements). The XML attributes
 * and elements are processed in wire order and no assumptions
 * are made about namespace prefixes. */

/* Called by: */
int zx_LEN_WO_mm7_RFC2822Address(struct zx_ctx* c, struct zx_mm7_RFC2822Address_s* x )
{
  struct zx_ns_s* pop_seen = 0;
  struct zx_elem_s* se MAYBE_UNUSED;
#if 1 /* NORMALMODE */
  int len = 1 + sizeof("RFC2822Address")-1 + 1 + 2 + sizeof("RFC2822Address")-1 + 1;
  
  if (x->gg.g.ns && x->gg.g.ns->prefix_len)
    len += (x->gg.g.ns->prefix_len + 1) * 2;
  if (c->inc_ns_len)
    len += zx_len_inc_ns(c, &pop_seen);
  len += zx_len_xmlns_if_not_seen(c, x->gg.g.ns, &pop_seen);

  len += zx_attr_wo_len(x->addressCoding, sizeof("addressCoding")-1);
  len += zx_attr_wo_len(x->displayOnly, sizeof("displayOnly")-1);
  len += zx_attr_wo_len(x->id, sizeof("id")-1);

#else
  /* root node has no begin tag */
  int len = 0;
#endif
  


  len += zx_len_wo_common(c, &x->gg); 
  zx_pop_seen(pop_seen);
  ENC_LEN_DEBUG(x, "mm7:RFC2822Address", len);
  return len;
}

/* FUNC(zx_ENC_SO_mm7_RFC2822Address) */

/* Render element into string. The XML attributes and elements are
 * processed in schema order. This is what you generally want for
 * rendering new data structure to a string. The wo pointers are not used. */

/* Called by: */
char* zx_ENC_SO_mm7_RFC2822Address(struct zx_ctx* c, struct zx_mm7_RFC2822Address_s* x, char* p )
{
  struct zx_elem_s* se MAYBE_UNUSED;
  struct zx_ns_s* pop_seen = 0;
  ENC_LEN_DEBUG_BASE;
#if 1 /* NORMALMODE */
  /* *** in simple_elem case should output ns prefix from ns node. */
  ZX_OUT_TAG(p, "<mm7:RFC2822Address");
  if (c->inc_ns)
    p = zx_enc_inc_ns(c, p, &pop_seen);
  p = zx_enc_xmlns_if_not_seen(c, p, zx_ns_tab+zx_xmlns_ix_mm7, &pop_seen);

  p = zx_attr_so_enc(p, x->addressCoding, " addressCoding=\"", sizeof(" addressCoding=\"")-1);
  p = zx_attr_so_enc(p, x->displayOnly, " displayOnly=\"", sizeof(" displayOnly=\"")-1);
  p = zx_attr_so_enc(p, x->id, " id=\"", sizeof(" id=\"")-1);

  p = zx_enc_unknown_attrs(p, x->gg.any_attr);
#else
  /* root node has no begin tag */
#endif
  

  p = zx_enc_so_unknown_elems_and_content(c, p, &x->gg);
  
#if 1 /* NORMALMODE */
  ZX_OUT_CLOSE_TAG(p, "</mm7:RFC2822Address>");
  zx_pop_seen(pop_seen);
#else
  /* root node has no end tag either */
#endif
  ENC_LEN_DEBUG(x, "mm7:RFC2822Address", p-enc_base);
  return p;
}

/* FUNC(zx_ENC_WO_mm7_RFC2822Address) */

/* Render element into string. The XML attributes and elements are
 * processed in wire order by chasing wo pointers. This is what you want for
 * validating signatures on other people's XML documents. */

/* Called by: */
char* zx_ENC_WO_mm7_RFC2822Address(struct zx_ctx* c, struct zx_mm7_RFC2822Address_s* x, char* p )
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
  ZX_OUT_MEM(p, "RFC2822Address", sizeof("RFC2822Address")-1);
  qq = p;

  /* *** sort the namespaces */
  if (c->inc_ns)
    zx_add_inc_ns(c, &pop_seen);
  zx_add_xmlns_if_not_seen(c, x->gg.g.ns, &pop_seen);

  p = zx_enc_seen(p, pop_seen); 
  p = zx_attr_wo_enc(p, x->addressCoding, "addressCoding=\"", sizeof("addressCoding=\"")-1);
  p = zx_attr_wo_enc(p, x->displayOnly, "displayOnly=\"", sizeof("displayOnly=\"")-1);
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
  ENC_LEN_DEBUG(x, "mm7:RFC2822Address", p-enc_base);
  return p;
}

/* FUNC(zx_EASY_ENC_SO_mm7_RFC2822Address) */

/* Called by: */
struct zx_str* zx_EASY_ENC_SO_mm7_RFC2822Address(struct zx_ctx* c, struct zx_mm7_RFC2822Address_s* x )
{
  int len;
  char* buf;
  c->ns_tab = ZX_ALLOC(c, sizeof(zx_ns_tab));
  memcpy(c->ns_tab, zx_ns_tab, sizeof(zx_ns_tab));
  len = zx_LEN_SO_mm7_RFC2822Address(c, x );
  buf = ZX_ALLOC(c, len+1);
  return zx_easy_enc_common(c, zx_ENC_SO_mm7_RFC2822Address(c, x, buf ), buf, len);
}

/* FUNC(zx_EASY_ENC_WO_mm7_RFC2822Address) */

/* Called by: */
struct zx_str* zx_EASY_ENC_WO_mm7_RFC2822Address(struct zx_ctx* c, struct zx_mm7_RFC2822Address_s* x )
{
  int len;
  char* buf;
  c->ns_tab = ZX_ALLOC(c, sizeof(zx_ns_tab));
  memcpy(c->ns_tab, zx_ns_tab, sizeof(zx_ns_tab));
  len = zx_LEN_WO_mm7_RFC2822Address(c, x );
  buf = ZX_ALLOC(c, len+1);
  return zx_easy_enc_common(c, zx_ENC_WO_mm7_RFC2822Address(c, x, buf ), buf, len);
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

#define EL_NAME   mm7_RSErrorRsp
#define EL_STRUCT zx_mm7_RSErrorRsp_s
#define EL_NS     mm7
#define EL_TAG    RSErrorRsp

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

/* FUNC(zx_LEN_SO_mm7_RSErrorRsp) */

/* Compute length of an element (and its subelements). The XML attributes
 * and elements are processed in schema order. */

/* Called by: */
int zx_LEN_SO_mm7_RSErrorRsp(struct zx_ctx* c, struct zx_mm7_RSErrorRsp_s* x )
{
  struct zx_ns_s* pop_seen = 0;
  struct zx_elem_s* se MAYBE_UNUSED;
#if 1 /* NORMALMODE */
  /* *** in simple_elem case should output ns prefix from ns node. */
  int len = sizeof("<mm7:RSErrorRsp")-1 + 1 + sizeof("</mm7:RSErrorRsp>")-1;
  if (c->inc_ns_len)
    len += zx_len_inc_ns(c, &pop_seen);
  len += zx_len_xmlns_if_not_seen(c, zx_ns_tab+zx_xmlns_ix_mm7, &pop_seen);


#else
  /* root node has no begin tag */
  int len = 0;
#endif
  
  for (se = x->MM7Version; se; se = (struct zx_elem_s*)se->g.n)
    len += zx_LEN_SO_simple_elem(c,se, sizeof("mm7:MM7Version")-1, zx_ns_tab+zx_xmlns_ix_mm7);
  {
      struct zx_mm7_Status_s* e;
      for (e = x->Status; e; e = (struct zx_mm7_Status_s*)e->gg.g.n)
	  len += zx_LEN_SO_mm7_Status(c, e);
  }
  {
      struct zx_mm7_Extension_s* e;
      for (e = x->Extension; e; e = (struct zx_mm7_Extension_s*)e->gg.g.n)
	  len += zx_LEN_SO_mm7_Extension(c, e);
  }


  len += zx_len_so_common(c, &x->gg);
  zx_pop_seen(pop_seen);
  ENC_LEN_DEBUG(x, "mm7:RSErrorRsp", len);
  return len;
}

/* FUNC(zx_LEN_WO_mm7_RSErrorRsp) */

/* Compute length of an element (and its subelements). The XML attributes
 * and elements are processed in wire order and no assumptions
 * are made about namespace prefixes. */

/* Called by: */
int zx_LEN_WO_mm7_RSErrorRsp(struct zx_ctx* c, struct zx_mm7_RSErrorRsp_s* x )
{
  struct zx_ns_s* pop_seen = 0;
  struct zx_elem_s* se MAYBE_UNUSED;
#if 1 /* NORMALMODE */
  int len = 1 + sizeof("RSErrorRsp")-1 + 1 + 2 + sizeof("RSErrorRsp")-1 + 1;
  
  if (x->gg.g.ns && x->gg.g.ns->prefix_len)
    len += (x->gg.g.ns->prefix_len + 1) * 2;
  if (c->inc_ns_len)
    len += zx_len_inc_ns(c, &pop_seen);
  len += zx_len_xmlns_if_not_seen(c, x->gg.g.ns, &pop_seen);


#else
  /* root node has no begin tag */
  int len = 0;
#endif
  
  for (se = x->MM7Version; se; se = (struct zx_elem_s*)se->g.n)
    len += zx_LEN_WO_simple_elem(c, se, sizeof("MM7Version")-1);
  {
      struct zx_mm7_Status_s* e;
      for (e = x->Status; e; e = (struct zx_mm7_Status_s*)e->gg.g.n)
	  len += zx_LEN_WO_mm7_Status(c, e);
  }
  {
      struct zx_mm7_Extension_s* e;
      for (e = x->Extension; e; e = (struct zx_mm7_Extension_s*)e->gg.g.n)
	  len += zx_LEN_WO_mm7_Extension(c, e);
  }


  len += zx_len_wo_common(c, &x->gg); 
  zx_pop_seen(pop_seen);
  ENC_LEN_DEBUG(x, "mm7:RSErrorRsp", len);
  return len;
}

/* FUNC(zx_ENC_SO_mm7_RSErrorRsp) */

/* Render element into string. The XML attributes and elements are
 * processed in schema order. This is what you generally want for
 * rendering new data structure to a string. The wo pointers are not used. */

/* Called by: */
char* zx_ENC_SO_mm7_RSErrorRsp(struct zx_ctx* c, struct zx_mm7_RSErrorRsp_s* x, char* p )
{
  struct zx_elem_s* se MAYBE_UNUSED;
  struct zx_ns_s* pop_seen = 0;
  ENC_LEN_DEBUG_BASE;
#if 1 /* NORMALMODE */
  /* *** in simple_elem case should output ns prefix from ns node. */
  ZX_OUT_TAG(p, "<mm7:RSErrorRsp");
  if (c->inc_ns)
    p = zx_enc_inc_ns(c, p, &pop_seen);
  p = zx_enc_xmlns_if_not_seen(c, p, zx_ns_tab+zx_xmlns_ix_mm7, &pop_seen);


  p = zx_enc_unknown_attrs(p, x->gg.any_attr);
#else
  /* root node has no begin tag */
#endif
  
  for (se = x->MM7Version; se; se = (struct zx_elem_s*)se->g.n)
    p = zx_ENC_SO_simple_elem(c, se, p, "mm7:MM7Version", sizeof("mm7:MM7Version")-1, zx_ns_tab+zx_xmlns_ix_mm7);
  {
      struct zx_mm7_Status_s* e;
      for (e = x->Status; e; e = (struct zx_mm7_Status_s*)e->gg.g.n)
	  p = zx_ENC_SO_mm7_Status(c, e, p);
  }
  {
      struct zx_mm7_Extension_s* e;
      for (e = x->Extension; e; e = (struct zx_mm7_Extension_s*)e->gg.g.n)
	  p = zx_ENC_SO_mm7_Extension(c, e, p);
  }

  p = zx_enc_so_unknown_elems_and_content(c, p, &x->gg);
  
#if 1 /* NORMALMODE */
  ZX_OUT_CLOSE_TAG(p, "</mm7:RSErrorRsp>");
  zx_pop_seen(pop_seen);
#else
  /* root node has no end tag either */
#endif
  ENC_LEN_DEBUG(x, "mm7:RSErrorRsp", p-enc_base);
  return p;
}

/* FUNC(zx_ENC_WO_mm7_RSErrorRsp) */

/* Render element into string. The XML attributes and elements are
 * processed in wire order by chasing wo pointers. This is what you want for
 * validating signatures on other people's XML documents. */

/* Called by: */
char* zx_ENC_WO_mm7_RSErrorRsp(struct zx_ctx* c, struct zx_mm7_RSErrorRsp_s* x, char* p )
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
  ZX_OUT_MEM(p, "RSErrorRsp", sizeof("RSErrorRsp")-1);
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
  ENC_LEN_DEBUG(x, "mm7:RSErrorRsp", p-enc_base);
  return p;
}

/* FUNC(zx_EASY_ENC_SO_mm7_RSErrorRsp) */

/* Called by: */
struct zx_str* zx_EASY_ENC_SO_mm7_RSErrorRsp(struct zx_ctx* c, struct zx_mm7_RSErrorRsp_s* x )
{
  int len;
  char* buf;
  c->ns_tab = ZX_ALLOC(c, sizeof(zx_ns_tab));
  memcpy(c->ns_tab, zx_ns_tab, sizeof(zx_ns_tab));
  len = zx_LEN_SO_mm7_RSErrorRsp(c, x );
  buf = ZX_ALLOC(c, len+1);
  return zx_easy_enc_common(c, zx_ENC_SO_mm7_RSErrorRsp(c, x, buf ), buf, len);
}

/* FUNC(zx_EASY_ENC_WO_mm7_RSErrorRsp) */

/* Called by: */
struct zx_str* zx_EASY_ENC_WO_mm7_RSErrorRsp(struct zx_ctx* c, struct zx_mm7_RSErrorRsp_s* x )
{
  int len;
  char* buf;
  c->ns_tab = ZX_ALLOC(c, sizeof(zx_ns_tab));
  memcpy(c->ns_tab, zx_ns_tab, sizeof(zx_ns_tab));
  len = zx_LEN_WO_mm7_RSErrorRsp(c, x );
  buf = ZX_ALLOC(c, len+1);
  return zx_easy_enc_common(c, zx_ENC_WO_mm7_RSErrorRsp(c, x, buf ), buf, len);
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

#define EL_NAME   mm7_ReadReplyReq
#define EL_STRUCT zx_mm7_ReadReplyReq_s
#define EL_NS     mm7
#define EL_TAG    ReadReplyReq

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

/* FUNC(zx_LEN_SO_mm7_ReadReplyReq) */

/* Compute length of an element (and its subelements). The XML attributes
 * and elements are processed in schema order. */

/* Called by: */
int zx_LEN_SO_mm7_ReadReplyReq(struct zx_ctx* c, struct zx_mm7_ReadReplyReq_s* x )
{
  struct zx_ns_s* pop_seen = 0;
  struct zx_elem_s* se MAYBE_UNUSED;
#if 1 /* NORMALMODE */
  /* *** in simple_elem case should output ns prefix from ns node. */
  int len = sizeof("<mm7:ReadReplyReq")-1 + 1 + sizeof("</mm7:ReadReplyReq>")-1;
  if (c->inc_ns_len)
    len += zx_len_inc_ns(c, &pop_seen);
  len += zx_len_xmlns_if_not_seen(c, zx_ns_tab+zx_xmlns_ix_mm7, &pop_seen);


#else
  /* root node has no begin tag */
  int len = 0;
#endif
  
  for (se = x->MM7Version; se; se = (struct zx_elem_s*)se->g.n)
    len += zx_LEN_SO_simple_elem(c,se, sizeof("mm7:MM7Version")-1, zx_ns_tab+zx_xmlns_ix_mm7);
  for (se = x->MMSRelayServerID; se; se = (struct zx_elem_s*)se->g.n)
    len += zx_LEN_SO_simple_elem(c,se, sizeof("mm7:MMSRelayServerID")-1, zx_ns_tab+zx_xmlns_ix_mm7);
  {
      struct zx_mm7_Extension_s* e;
      for (e = x->Extension; e; e = (struct zx_mm7_Extension_s*)e->gg.g.n)
	  len += zx_LEN_SO_mm7_Extension(c, e);
  }
  for (se = x->MessageID; se; se = (struct zx_elem_s*)se->g.n)
    len += zx_LEN_SO_simple_elem(c,se, sizeof("mm7:MessageID")-1, zx_ns_tab+zx_xmlns_ix_mm7);
  {
      struct zx_mm7_Recipient_s* e;
      for (e = x->Recipient; e; e = (struct zx_mm7_Recipient_s*)e->gg.g.n)
	  len += zx_LEN_SO_mm7_Recipient(c, e);
  }
  {
      struct zx_mm7_Sender_s* e;
      for (e = x->Sender; e; e = (struct zx_mm7_Sender_s*)e->gg.g.n)
	  len += zx_LEN_SO_mm7_Sender(c, e);
  }
  for (se = x->TimeStamp; se; se = (struct zx_elem_s*)se->g.n)
    len += zx_LEN_SO_simple_elem(c,se, sizeof("mm7:TimeStamp")-1, zx_ns_tab+zx_xmlns_ix_mm7);
  for (se = x->MMStatus; se; se = (struct zx_elem_s*)se->g.n)
    len += zx_LEN_SO_simple_elem(c,se, sizeof("mm7:MMStatus")-1, zx_ns_tab+zx_xmlns_ix_mm7);
  for (se = x->StatusText; se; se = (struct zx_elem_s*)se->g.n)
    len += zx_LEN_SO_simple_elem(c,se, sizeof("mm7:StatusText")-1, zx_ns_tab+zx_xmlns_ix_mm7);
  for (se = x->ApplicID; se; se = (struct zx_elem_s*)se->g.n)
    len += zx_LEN_SO_simple_elem(c,se, sizeof("mm7:ApplicID")-1, zx_ns_tab+zx_xmlns_ix_mm7);
  for (se = x->ReplyApplicID; se; se = (struct zx_elem_s*)se->g.n)
    len += zx_LEN_SO_simple_elem(c,se, sizeof("mm7:ReplyApplicID")-1, zx_ns_tab+zx_xmlns_ix_mm7);
  for (se = x->AuxApplicInfo; se; se = (struct zx_elem_s*)se->g.n)
    len += zx_LEN_SO_simple_elem(c,se, sizeof("mm7:AuxApplicInfo")-1, zx_ns_tab+zx_xmlns_ix_mm7);


  len += zx_len_so_common(c, &x->gg);
  zx_pop_seen(pop_seen);
  ENC_LEN_DEBUG(x, "mm7:ReadReplyReq", len);
  return len;
}

/* FUNC(zx_LEN_WO_mm7_ReadReplyReq) */

/* Compute length of an element (and its subelements). The XML attributes
 * and elements are processed in wire order and no assumptions
 * are made about namespace prefixes. */

/* Called by: */
int zx_LEN_WO_mm7_ReadReplyReq(struct zx_ctx* c, struct zx_mm7_ReadReplyReq_s* x )
{
  struct zx_ns_s* pop_seen = 0;
  struct zx_elem_s* se MAYBE_UNUSED;
#if 1 /* NORMALMODE */
  int len = 1 + sizeof("ReadReplyReq")-1 + 1 + 2 + sizeof("ReadReplyReq")-1 + 1;
  
  if (x->gg.g.ns && x->gg.g.ns->prefix_len)
    len += (x->gg.g.ns->prefix_len + 1) * 2;
  if (c->inc_ns_len)
    len += zx_len_inc_ns(c, &pop_seen);
  len += zx_len_xmlns_if_not_seen(c, x->gg.g.ns, &pop_seen);


#else
  /* root node has no begin tag */
  int len = 0;
#endif
  
  for (se = x->MM7Version; se; se = (struct zx_elem_s*)se->g.n)
    len += zx_LEN_WO_simple_elem(c, se, sizeof("MM7Version")-1);
  for (se = x->MMSRelayServerID; se; se = (struct zx_elem_s*)se->g.n)
    len += zx_LEN_WO_simple_elem(c, se, sizeof("MMSRelayServerID")-1);
  {
      struct zx_mm7_Extension_s* e;
      for (e = x->Extension; e; e = (struct zx_mm7_Extension_s*)e->gg.g.n)
	  len += zx_LEN_WO_mm7_Extension(c, e);
  }
  for (se = x->MessageID; se; se = (struct zx_elem_s*)se->g.n)
    len += zx_LEN_WO_simple_elem(c, se, sizeof("MessageID")-1);
  {
      struct zx_mm7_Recipient_s* e;
      for (e = x->Recipient; e; e = (struct zx_mm7_Recipient_s*)e->gg.g.n)
	  len += zx_LEN_WO_mm7_Recipient(c, e);
  }
  {
      struct zx_mm7_Sender_s* e;
      for (e = x->Sender; e; e = (struct zx_mm7_Sender_s*)e->gg.g.n)
	  len += zx_LEN_WO_mm7_Sender(c, e);
  }
  for (se = x->TimeStamp; se; se = (struct zx_elem_s*)se->g.n)
    len += zx_LEN_WO_simple_elem(c, se, sizeof("TimeStamp")-1);
  for (se = x->MMStatus; se; se = (struct zx_elem_s*)se->g.n)
    len += zx_LEN_WO_simple_elem(c, se, sizeof("MMStatus")-1);
  for (se = x->StatusText; se; se = (struct zx_elem_s*)se->g.n)
    len += zx_LEN_WO_simple_elem(c, se, sizeof("StatusText")-1);
  for (se = x->ApplicID; se; se = (struct zx_elem_s*)se->g.n)
    len += zx_LEN_WO_simple_elem(c, se, sizeof("ApplicID")-1);
  for (se = x->ReplyApplicID; se; se = (struct zx_elem_s*)se->g.n)
    len += zx_LEN_WO_simple_elem(c, se, sizeof("ReplyApplicID")-1);
  for (se = x->AuxApplicInfo; se; se = (struct zx_elem_s*)se->g.n)
    len += zx_LEN_WO_simple_elem(c, se, sizeof("AuxApplicInfo")-1);


  len += zx_len_wo_common(c, &x->gg); 
  zx_pop_seen(pop_seen);
  ENC_LEN_DEBUG(x, "mm7:ReadReplyReq", len);
  return len;
}

/* FUNC(zx_ENC_SO_mm7_ReadReplyReq) */

/* Render element into string. The XML attributes and elements are
 * processed in schema order. This is what you generally want for
 * rendering new data structure to a string. The wo pointers are not used. */

/* Called by: */
char* zx_ENC_SO_mm7_ReadReplyReq(struct zx_ctx* c, struct zx_mm7_ReadReplyReq_s* x, char* p )
{
  struct zx_elem_s* se MAYBE_UNUSED;
  struct zx_ns_s* pop_seen = 0;
  ENC_LEN_DEBUG_BASE;
#if 1 /* NORMALMODE */
  /* *** in simple_elem case should output ns prefix from ns node. */
  ZX_OUT_TAG(p, "<mm7:ReadReplyReq");
  if (c->inc_ns)
    p = zx_enc_inc_ns(c, p, &pop_seen);
  p = zx_enc_xmlns_if_not_seen(c, p, zx_ns_tab+zx_xmlns_ix_mm7, &pop_seen);


  p = zx_enc_unknown_attrs(p, x->gg.any_attr);
#else
  /* root node has no begin tag */
#endif
  
  for (se = x->MM7Version; se; se = (struct zx_elem_s*)se->g.n)
    p = zx_ENC_SO_simple_elem(c, se, p, "mm7:MM7Version", sizeof("mm7:MM7Version")-1, zx_ns_tab+zx_xmlns_ix_mm7);
  for (se = x->MMSRelayServerID; se; se = (struct zx_elem_s*)se->g.n)
    p = zx_ENC_SO_simple_elem(c, se, p, "mm7:MMSRelayServerID", sizeof("mm7:MMSRelayServerID")-1, zx_ns_tab+zx_xmlns_ix_mm7);
  {
      struct zx_mm7_Extension_s* e;
      for (e = x->Extension; e; e = (struct zx_mm7_Extension_s*)e->gg.g.n)
	  p = zx_ENC_SO_mm7_Extension(c, e, p);
  }
  for (se = x->MessageID; se; se = (struct zx_elem_s*)se->g.n)
    p = zx_ENC_SO_simple_elem(c, se, p, "mm7:MessageID", sizeof("mm7:MessageID")-1, zx_ns_tab+zx_xmlns_ix_mm7);
  {
      struct zx_mm7_Recipient_s* e;
      for (e = x->Recipient; e; e = (struct zx_mm7_Recipient_s*)e->gg.g.n)
	  p = zx_ENC_SO_mm7_Recipient(c, e, p);
  }
  {
      struct zx_mm7_Sender_s* e;
      for (e = x->Sender; e; e = (struct zx_mm7_Sender_s*)e->gg.g.n)
	  p = zx_ENC_SO_mm7_Sender(c, e, p);
  }
  for (se = x->TimeStamp; se; se = (struct zx_elem_s*)se->g.n)
    p = zx_ENC_SO_simple_elem(c, se, p, "mm7:TimeStamp", sizeof("mm7:TimeStamp")-1, zx_ns_tab+zx_xmlns_ix_mm7);
  for (se = x->MMStatus; se; se = (struct zx_elem_s*)se->g.n)
    p = zx_ENC_SO_simple_elem(c, se, p, "mm7:MMStatus", sizeof("mm7:MMStatus")-1, zx_ns_tab+zx_xmlns_ix_mm7);
  for (se = x->StatusText; se; se = (struct zx_elem_s*)se->g.n)
    p = zx_ENC_SO_simple_elem(c, se, p, "mm7:StatusText", sizeof("mm7:StatusText")-1, zx_ns_tab+zx_xmlns_ix_mm7);
  for (se = x->ApplicID; se; se = (struct zx_elem_s*)se->g.n)
    p = zx_ENC_SO_simple_elem(c, se, p, "mm7:ApplicID", sizeof("mm7:ApplicID")-1, zx_ns_tab+zx_xmlns_ix_mm7);
  for (se = x->ReplyApplicID; se; se = (struct zx_elem_s*)se->g.n)
    p = zx_ENC_SO_simple_elem(c, se, p, "mm7:ReplyApplicID", sizeof("mm7:ReplyApplicID")-1, zx_ns_tab+zx_xmlns_ix_mm7);
  for (se = x->AuxApplicInfo; se; se = (struct zx_elem_s*)se->g.n)
    p = zx_ENC_SO_simple_elem(c, se, p, "mm7:AuxApplicInfo", sizeof("mm7:AuxApplicInfo")-1, zx_ns_tab+zx_xmlns_ix_mm7);

  p = zx_enc_so_unknown_elems_and_content(c, p, &x->gg);
  
#if 1 /* NORMALMODE */
  ZX_OUT_CLOSE_TAG(p, "</mm7:ReadReplyReq>");
  zx_pop_seen(pop_seen);
#else
  /* root node has no end tag either */
#endif
  ENC_LEN_DEBUG(x, "mm7:ReadReplyReq", p-enc_base);
  return p;
}

/* FUNC(zx_ENC_WO_mm7_ReadReplyReq) */

/* Render element into string. The XML attributes and elements are
 * processed in wire order by chasing wo pointers. This is what you want for
 * validating signatures on other people's XML documents. */

/* Called by: */
char* zx_ENC_WO_mm7_ReadReplyReq(struct zx_ctx* c, struct zx_mm7_ReadReplyReq_s* x, char* p )
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
  ZX_OUT_MEM(p, "ReadReplyReq", sizeof("ReadReplyReq")-1);
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
  ENC_LEN_DEBUG(x, "mm7:ReadReplyReq", p-enc_base);
  return p;
}

/* FUNC(zx_EASY_ENC_SO_mm7_ReadReplyReq) */

/* Called by: */
struct zx_str* zx_EASY_ENC_SO_mm7_ReadReplyReq(struct zx_ctx* c, struct zx_mm7_ReadReplyReq_s* x )
{
  int len;
  char* buf;
  c->ns_tab = ZX_ALLOC(c, sizeof(zx_ns_tab));
  memcpy(c->ns_tab, zx_ns_tab, sizeof(zx_ns_tab));
  len = zx_LEN_SO_mm7_ReadReplyReq(c, x );
  buf = ZX_ALLOC(c, len+1);
  return zx_easy_enc_common(c, zx_ENC_SO_mm7_ReadReplyReq(c, x, buf ), buf, len);
}

/* FUNC(zx_EASY_ENC_WO_mm7_ReadReplyReq) */

/* Called by: */
struct zx_str* zx_EASY_ENC_WO_mm7_ReadReplyReq(struct zx_ctx* c, struct zx_mm7_ReadReplyReq_s* x )
{
  int len;
  char* buf;
  c->ns_tab = ZX_ALLOC(c, sizeof(zx_ns_tab));
  memcpy(c->ns_tab, zx_ns_tab, sizeof(zx_ns_tab));
  len = zx_LEN_WO_mm7_ReadReplyReq(c, x );
  buf = ZX_ALLOC(c, len+1);
  return zx_easy_enc_common(c, zx_ENC_WO_mm7_ReadReplyReq(c, x, buf ), buf, len);
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

#define EL_NAME   mm7_ReadReplyRsp
#define EL_STRUCT zx_mm7_ReadReplyRsp_s
#define EL_NS     mm7
#define EL_TAG    ReadReplyRsp

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

/* FUNC(zx_LEN_SO_mm7_ReadReplyRsp) */

/* Compute length of an element (and its subelements). The XML attributes
 * and elements are processed in schema order. */

/* Called by: */
int zx_LEN_SO_mm7_ReadReplyRsp(struct zx_ctx* c, struct zx_mm7_ReadReplyRsp_s* x )
{
  struct zx_ns_s* pop_seen = 0;
  struct zx_elem_s* se MAYBE_UNUSED;
#if 1 /* NORMALMODE */
  /* *** in simple_elem case should output ns prefix from ns node. */
  int len = sizeof("<mm7:ReadReplyRsp")-1 + 1 + sizeof("</mm7:ReadReplyRsp>")-1;
  if (c->inc_ns_len)
    len += zx_len_inc_ns(c, &pop_seen);
  len += zx_len_xmlns_if_not_seen(c, zx_ns_tab+zx_xmlns_ix_mm7, &pop_seen);


#else
  /* root node has no begin tag */
  int len = 0;
#endif
  
  for (se = x->MM7Version; se; se = (struct zx_elem_s*)se->g.n)
    len += zx_LEN_SO_simple_elem(c,se, sizeof("mm7:MM7Version")-1, zx_ns_tab+zx_xmlns_ix_mm7);
  {
      struct zx_mm7_Status_s* e;
      for (e = x->Status; e; e = (struct zx_mm7_Status_s*)e->gg.g.n)
	  len += zx_LEN_SO_mm7_Status(c, e);
  }
  {
      struct zx_mm7_Extension_s* e;
      for (e = x->Extension; e; e = (struct zx_mm7_Extension_s*)e->gg.g.n)
	  len += zx_LEN_SO_mm7_Extension(c, e);
  }


  len += zx_len_so_common(c, &x->gg);
  zx_pop_seen(pop_seen);
  ENC_LEN_DEBUG(x, "mm7:ReadReplyRsp", len);
  return len;
}

/* FUNC(zx_LEN_WO_mm7_ReadReplyRsp) */

/* Compute length of an element (and its subelements). The XML attributes
 * and elements are processed in wire order and no assumptions
 * are made about namespace prefixes. */

/* Called by: */
int zx_LEN_WO_mm7_ReadReplyRsp(struct zx_ctx* c, struct zx_mm7_ReadReplyRsp_s* x )
{
  struct zx_ns_s* pop_seen = 0;
  struct zx_elem_s* se MAYBE_UNUSED;
#if 1 /* NORMALMODE */
  int len = 1 + sizeof("ReadReplyRsp")-1 + 1 + 2 + sizeof("ReadReplyRsp")-1 + 1;
  
  if (x->gg.g.ns && x->gg.g.ns->prefix_len)
    len += (x->gg.g.ns->prefix_len + 1) * 2;
  if (c->inc_ns_len)
    len += zx_len_inc_ns(c, &pop_seen);
  len += zx_len_xmlns_if_not_seen(c, x->gg.g.ns, &pop_seen);


#else
  /* root node has no begin tag */
  int len = 0;
#endif
  
  for (se = x->MM7Version; se; se = (struct zx_elem_s*)se->g.n)
    len += zx_LEN_WO_simple_elem(c, se, sizeof("MM7Version")-1);
  {
      struct zx_mm7_Status_s* e;
      for (e = x->Status; e; e = (struct zx_mm7_Status_s*)e->gg.g.n)
	  len += zx_LEN_WO_mm7_Status(c, e);
  }
  {
      struct zx_mm7_Extension_s* e;
      for (e = x->Extension; e; e = (struct zx_mm7_Extension_s*)e->gg.g.n)
	  len += zx_LEN_WO_mm7_Extension(c, e);
  }


  len += zx_len_wo_common(c, &x->gg); 
  zx_pop_seen(pop_seen);
  ENC_LEN_DEBUG(x, "mm7:ReadReplyRsp", len);
  return len;
}

/* FUNC(zx_ENC_SO_mm7_ReadReplyRsp) */

/* Render element into string. The XML attributes and elements are
 * processed in schema order. This is what you generally want for
 * rendering new data structure to a string. The wo pointers are not used. */

/* Called by: */
char* zx_ENC_SO_mm7_ReadReplyRsp(struct zx_ctx* c, struct zx_mm7_ReadReplyRsp_s* x, char* p )
{
  struct zx_elem_s* se MAYBE_UNUSED;
  struct zx_ns_s* pop_seen = 0;
  ENC_LEN_DEBUG_BASE;
#if 1 /* NORMALMODE */
  /* *** in simple_elem case should output ns prefix from ns node. */
  ZX_OUT_TAG(p, "<mm7:ReadReplyRsp");
  if (c->inc_ns)
    p = zx_enc_inc_ns(c, p, &pop_seen);
  p = zx_enc_xmlns_if_not_seen(c, p, zx_ns_tab+zx_xmlns_ix_mm7, &pop_seen);


  p = zx_enc_unknown_attrs(p, x->gg.any_attr);
#else
  /* root node has no begin tag */
#endif
  
  for (se = x->MM7Version; se; se = (struct zx_elem_s*)se->g.n)
    p = zx_ENC_SO_simple_elem(c, se, p, "mm7:MM7Version", sizeof("mm7:MM7Version")-1, zx_ns_tab+zx_xmlns_ix_mm7);
  {
      struct zx_mm7_Status_s* e;
      for (e = x->Status; e; e = (struct zx_mm7_Status_s*)e->gg.g.n)
	  p = zx_ENC_SO_mm7_Status(c, e, p);
  }
  {
      struct zx_mm7_Extension_s* e;
      for (e = x->Extension; e; e = (struct zx_mm7_Extension_s*)e->gg.g.n)
	  p = zx_ENC_SO_mm7_Extension(c, e, p);
  }

  p = zx_enc_so_unknown_elems_and_content(c, p, &x->gg);
  
#if 1 /* NORMALMODE */
  ZX_OUT_CLOSE_TAG(p, "</mm7:ReadReplyRsp>");
  zx_pop_seen(pop_seen);
#else
  /* root node has no end tag either */
#endif
  ENC_LEN_DEBUG(x, "mm7:ReadReplyRsp", p-enc_base);
  return p;
}

/* FUNC(zx_ENC_WO_mm7_ReadReplyRsp) */

/* Render element into string. The XML attributes and elements are
 * processed in wire order by chasing wo pointers. This is what you want for
 * validating signatures on other people's XML documents. */

/* Called by: */
char* zx_ENC_WO_mm7_ReadReplyRsp(struct zx_ctx* c, struct zx_mm7_ReadReplyRsp_s* x, char* p )
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
  ZX_OUT_MEM(p, "ReadReplyRsp", sizeof("ReadReplyRsp")-1);
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
  ENC_LEN_DEBUG(x, "mm7:ReadReplyRsp", p-enc_base);
  return p;
}

/* FUNC(zx_EASY_ENC_SO_mm7_ReadReplyRsp) */

/* Called by: */
struct zx_str* zx_EASY_ENC_SO_mm7_ReadReplyRsp(struct zx_ctx* c, struct zx_mm7_ReadReplyRsp_s* x )
{
  int len;
  char* buf;
  c->ns_tab = ZX_ALLOC(c, sizeof(zx_ns_tab));
  memcpy(c->ns_tab, zx_ns_tab, sizeof(zx_ns_tab));
  len = zx_LEN_SO_mm7_ReadReplyRsp(c, x );
  buf = ZX_ALLOC(c, len+1);
  return zx_easy_enc_common(c, zx_ENC_SO_mm7_ReadReplyRsp(c, x, buf ), buf, len);
}

/* FUNC(zx_EASY_ENC_WO_mm7_ReadReplyRsp) */

/* Called by: */
struct zx_str* zx_EASY_ENC_WO_mm7_ReadReplyRsp(struct zx_ctx* c, struct zx_mm7_ReadReplyRsp_s* x )
{
  int len;
  char* buf;
  c->ns_tab = ZX_ALLOC(c, sizeof(zx_ns_tab));
  memcpy(c->ns_tab, zx_ns_tab, sizeof(zx_ns_tab));
  len = zx_LEN_WO_mm7_ReadReplyRsp(c, x );
  buf = ZX_ALLOC(c, len+1);
  return zx_easy_enc_common(c, zx_ENC_WO_mm7_ReadReplyRsp(c, x, buf ), buf, len);
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

#define EL_NAME   mm7_Recipient
#define EL_STRUCT zx_mm7_Recipient_s
#define EL_NS     mm7
#define EL_TAG    Recipient

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

/* FUNC(zx_LEN_SO_mm7_Recipient) */

/* Compute length of an element (and its subelements). The XML attributes
 * and elements are processed in schema order. */

/* Called by: */
int zx_LEN_SO_mm7_Recipient(struct zx_ctx* c, struct zx_mm7_Recipient_s* x )
{
  struct zx_ns_s* pop_seen = 0;
  struct zx_elem_s* se MAYBE_UNUSED;
#if 1 /* NORMALMODE */
  /* *** in simple_elem case should output ns prefix from ns node. */
  int len = sizeof("<mm7:Recipient")-1 + 1 + sizeof("</mm7:Recipient>")-1;
  if (c->inc_ns_len)
    len += zx_len_inc_ns(c, &pop_seen);
  len += zx_len_xmlns_if_not_seen(c, zx_ns_tab+zx_xmlns_ix_mm7, &pop_seen);


#else
  /* root node has no begin tag */
  int len = 0;
#endif
  
  {
      struct zx_mm7_RFC2822Address_s* e;
      for (e = x->RFC2822Address; e; e = (struct zx_mm7_RFC2822Address_s*)e->gg.g.n)
	  len += zx_LEN_SO_mm7_RFC2822Address(c, e);
  }
  {
      struct zx_mm7_Number_s* e;
      for (e = x->Number; e; e = (struct zx_mm7_Number_s*)e->gg.g.n)
	  len += zx_LEN_SO_mm7_Number(c, e);
  }
  {
      struct zx_mm7_ShortCode_s* e;
      for (e = x->ShortCode; e; e = (struct zx_mm7_ShortCode_s*)e->gg.g.n)
	  len += zx_LEN_SO_mm7_ShortCode(c, e);
  }
  {
      struct zx_mm7_Extension_s* e;
      for (e = x->Extension; e; e = (struct zx_mm7_Extension_s*)e->gg.g.n)
	  len += zx_LEN_SO_mm7_Extension(c, e);
  }


  len += zx_len_so_common(c, &x->gg);
  zx_pop_seen(pop_seen);
  ENC_LEN_DEBUG(x, "mm7:Recipient", len);
  return len;
}

/* FUNC(zx_LEN_WO_mm7_Recipient) */

/* Compute length of an element (and its subelements). The XML attributes
 * and elements are processed in wire order and no assumptions
 * are made about namespace prefixes. */

/* Called by: */
int zx_LEN_WO_mm7_Recipient(struct zx_ctx* c, struct zx_mm7_Recipient_s* x )
{
  struct zx_ns_s* pop_seen = 0;
  struct zx_elem_s* se MAYBE_UNUSED;
#if 1 /* NORMALMODE */
  int len = 1 + sizeof("Recipient")-1 + 1 + 2 + sizeof("Recipient")-1 + 1;
  
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
      struct zx_mm7_RFC2822Address_s* e;
      for (e = x->RFC2822Address; e; e = (struct zx_mm7_RFC2822Address_s*)e->gg.g.n)
	  len += zx_LEN_WO_mm7_RFC2822Address(c, e);
  }
  {
      struct zx_mm7_Number_s* e;
      for (e = x->Number; e; e = (struct zx_mm7_Number_s*)e->gg.g.n)
	  len += zx_LEN_WO_mm7_Number(c, e);
  }
  {
      struct zx_mm7_ShortCode_s* e;
      for (e = x->ShortCode; e; e = (struct zx_mm7_ShortCode_s*)e->gg.g.n)
	  len += zx_LEN_WO_mm7_ShortCode(c, e);
  }
  {
      struct zx_mm7_Extension_s* e;
      for (e = x->Extension; e; e = (struct zx_mm7_Extension_s*)e->gg.g.n)
	  len += zx_LEN_WO_mm7_Extension(c, e);
  }


  len += zx_len_wo_common(c, &x->gg); 
  zx_pop_seen(pop_seen);
  ENC_LEN_DEBUG(x, "mm7:Recipient", len);
  return len;
}

/* FUNC(zx_ENC_SO_mm7_Recipient) */

/* Render element into string. The XML attributes and elements are
 * processed in schema order. This is what you generally want for
 * rendering new data structure to a string. The wo pointers are not used. */

/* Called by: */
char* zx_ENC_SO_mm7_Recipient(struct zx_ctx* c, struct zx_mm7_Recipient_s* x, char* p )
{
  struct zx_elem_s* se MAYBE_UNUSED;
  struct zx_ns_s* pop_seen = 0;
  ENC_LEN_DEBUG_BASE;
#if 1 /* NORMALMODE */
  /* *** in simple_elem case should output ns prefix from ns node. */
  ZX_OUT_TAG(p, "<mm7:Recipient");
  if (c->inc_ns)
    p = zx_enc_inc_ns(c, p, &pop_seen);
  p = zx_enc_xmlns_if_not_seen(c, p, zx_ns_tab+zx_xmlns_ix_mm7, &pop_seen);


  p = zx_enc_unknown_attrs(p, x->gg.any_attr);
#else
  /* root node has no begin tag */
#endif
  
  {
      struct zx_mm7_RFC2822Address_s* e;
      for (e = x->RFC2822Address; e; e = (struct zx_mm7_RFC2822Address_s*)e->gg.g.n)
	  p = zx_ENC_SO_mm7_RFC2822Address(c, e, p);
  }
  {
      struct zx_mm7_Number_s* e;
      for (e = x->Number; e; e = (struct zx_mm7_Number_s*)e->gg.g.n)
	  p = zx_ENC_SO_mm7_Number(c, e, p);
  }
  {
      struct zx_mm7_ShortCode_s* e;
      for (e = x->ShortCode; e; e = (struct zx_mm7_ShortCode_s*)e->gg.g.n)
	  p = zx_ENC_SO_mm7_ShortCode(c, e, p);
  }
  {
      struct zx_mm7_Extension_s* e;
      for (e = x->Extension; e; e = (struct zx_mm7_Extension_s*)e->gg.g.n)
	  p = zx_ENC_SO_mm7_Extension(c, e, p);
  }

  p = zx_enc_so_unknown_elems_and_content(c, p, &x->gg);
  
#if 1 /* NORMALMODE */
  ZX_OUT_CLOSE_TAG(p, "</mm7:Recipient>");
  zx_pop_seen(pop_seen);
#else
  /* root node has no end tag either */
#endif
  ENC_LEN_DEBUG(x, "mm7:Recipient", p-enc_base);
  return p;
}

/* FUNC(zx_ENC_WO_mm7_Recipient) */

/* Render element into string. The XML attributes and elements are
 * processed in wire order by chasing wo pointers. This is what you want for
 * validating signatures on other people's XML documents. */

/* Called by: */
char* zx_ENC_WO_mm7_Recipient(struct zx_ctx* c, struct zx_mm7_Recipient_s* x, char* p )
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
  ZX_OUT_MEM(p, "Recipient", sizeof("Recipient")-1);
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
  ENC_LEN_DEBUG(x, "mm7:Recipient", p-enc_base);
  return p;
}

/* FUNC(zx_EASY_ENC_SO_mm7_Recipient) */

/* Called by: */
struct zx_str* zx_EASY_ENC_SO_mm7_Recipient(struct zx_ctx* c, struct zx_mm7_Recipient_s* x )
{
  int len;
  char* buf;
  c->ns_tab = ZX_ALLOC(c, sizeof(zx_ns_tab));
  memcpy(c->ns_tab, zx_ns_tab, sizeof(zx_ns_tab));
  len = zx_LEN_SO_mm7_Recipient(c, x );
  buf = ZX_ALLOC(c, len+1);
  return zx_easy_enc_common(c, zx_ENC_SO_mm7_Recipient(c, x, buf ), buf, len);
}

/* FUNC(zx_EASY_ENC_WO_mm7_Recipient) */

/* Called by: */
struct zx_str* zx_EASY_ENC_WO_mm7_Recipient(struct zx_ctx* c, struct zx_mm7_Recipient_s* x )
{
  int len;
  char* buf;
  c->ns_tab = ZX_ALLOC(c, sizeof(zx_ns_tab));
  memcpy(c->ns_tab, zx_ns_tab, sizeof(zx_ns_tab));
  len = zx_LEN_WO_mm7_Recipient(c, x );
  buf = ZX_ALLOC(c, len+1);
  return zx_easy_enc_common(c, zx_ENC_WO_mm7_Recipient(c, x, buf ), buf, len);
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

#define EL_NAME   mm7_Recipients
#define EL_STRUCT zx_mm7_Recipients_s
#define EL_NS     mm7
#define EL_TAG    Recipients

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

/* FUNC(zx_LEN_SO_mm7_Recipients) */

/* Compute length of an element (and its subelements). The XML attributes
 * and elements are processed in schema order. */

/* Called by: */
int zx_LEN_SO_mm7_Recipients(struct zx_ctx* c, struct zx_mm7_Recipients_s* x )
{
  struct zx_ns_s* pop_seen = 0;
  struct zx_elem_s* se MAYBE_UNUSED;
#if 1 /* NORMALMODE */
  /* *** in simple_elem case should output ns prefix from ns node. */
  int len = sizeof("<mm7:Recipients")-1 + 1 + sizeof("</mm7:Recipients>")-1;
  if (c->inc_ns_len)
    len += zx_len_inc_ns(c, &pop_seen);
  len += zx_len_xmlns_if_not_seen(c, zx_ns_tab+zx_xmlns_ix_mm7, &pop_seen);


#else
  /* root node has no begin tag */
  int len = 0;
#endif
  
  {
      struct zx_mm7_To_s* e;
      for (e = x->To; e; e = (struct zx_mm7_To_s*)e->gg.g.n)
	  len += zx_LEN_SO_mm7_To(c, e);
  }
  {
      struct zx_mm7_Cc_s* e;
      for (e = x->Cc; e; e = (struct zx_mm7_Cc_s*)e->gg.g.n)
	  len += zx_LEN_SO_mm7_Cc(c, e);
  }
  {
      struct zx_mm7_Bcc_s* e;
      for (e = x->Bcc; e; e = (struct zx_mm7_Bcc_s*)e->gg.g.n)
	  len += zx_LEN_SO_mm7_Bcc(c, e);
  }


  len += zx_len_so_common(c, &x->gg);
  zx_pop_seen(pop_seen);
  ENC_LEN_DEBUG(x, "mm7:Recipients", len);
  return len;
}

/* FUNC(zx_LEN_WO_mm7_Recipients) */

/* Compute length of an element (and its subelements). The XML attributes
 * and elements are processed in wire order and no assumptions
 * are made about namespace prefixes. */

/* Called by: */
int zx_LEN_WO_mm7_Recipients(struct zx_ctx* c, struct zx_mm7_Recipients_s* x )
{
  struct zx_ns_s* pop_seen = 0;
  struct zx_elem_s* se MAYBE_UNUSED;
#if 1 /* NORMALMODE */
  int len = 1 + sizeof("Recipients")-1 + 1 + 2 + sizeof("Recipients")-1 + 1;
  
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
      struct zx_mm7_To_s* e;
      for (e = x->To; e; e = (struct zx_mm7_To_s*)e->gg.g.n)
	  len += zx_LEN_WO_mm7_To(c, e);
  }
  {
      struct zx_mm7_Cc_s* e;
      for (e = x->Cc; e; e = (struct zx_mm7_Cc_s*)e->gg.g.n)
	  len += zx_LEN_WO_mm7_Cc(c, e);
  }
  {
      struct zx_mm7_Bcc_s* e;
      for (e = x->Bcc; e; e = (struct zx_mm7_Bcc_s*)e->gg.g.n)
	  len += zx_LEN_WO_mm7_Bcc(c, e);
  }


  len += zx_len_wo_common(c, &x->gg); 
  zx_pop_seen(pop_seen);
  ENC_LEN_DEBUG(x, "mm7:Recipients", len);
  return len;
}

/* FUNC(zx_ENC_SO_mm7_Recipients) */

/* Render element into string. The XML attributes and elements are
 * processed in schema order. This is what you generally want for
 * rendering new data structure to a string. The wo pointers are not used. */

/* Called by: */
char* zx_ENC_SO_mm7_Recipients(struct zx_ctx* c, struct zx_mm7_Recipients_s* x, char* p )
{
  struct zx_elem_s* se MAYBE_UNUSED;
  struct zx_ns_s* pop_seen = 0;
  ENC_LEN_DEBUG_BASE;
#if 1 /* NORMALMODE */
  /* *** in simple_elem case should output ns prefix from ns node. */
  ZX_OUT_TAG(p, "<mm7:Recipients");
  if (c->inc_ns)
    p = zx_enc_inc_ns(c, p, &pop_seen);
  p = zx_enc_xmlns_if_not_seen(c, p, zx_ns_tab+zx_xmlns_ix_mm7, &pop_seen);


  p = zx_enc_unknown_attrs(p, x->gg.any_attr);
#else
  /* root node has no begin tag */
#endif
  
  {
      struct zx_mm7_To_s* e;
      for (e = x->To; e; e = (struct zx_mm7_To_s*)e->gg.g.n)
	  p = zx_ENC_SO_mm7_To(c, e, p);
  }
  {
      struct zx_mm7_Cc_s* e;
      for (e = x->Cc; e; e = (struct zx_mm7_Cc_s*)e->gg.g.n)
	  p = zx_ENC_SO_mm7_Cc(c, e, p);
  }
  {
      struct zx_mm7_Bcc_s* e;
      for (e = x->Bcc; e; e = (struct zx_mm7_Bcc_s*)e->gg.g.n)
	  p = zx_ENC_SO_mm7_Bcc(c, e, p);
  }

  p = zx_enc_so_unknown_elems_and_content(c, p, &x->gg);
  
#if 1 /* NORMALMODE */
  ZX_OUT_CLOSE_TAG(p, "</mm7:Recipients>");
  zx_pop_seen(pop_seen);
#else
  /* root node has no end tag either */
#endif
  ENC_LEN_DEBUG(x, "mm7:Recipients", p-enc_base);
  return p;
}

/* FUNC(zx_ENC_WO_mm7_Recipients) */

/* Render element into string. The XML attributes and elements are
 * processed in wire order by chasing wo pointers. This is what you want for
 * validating signatures on other people's XML documents. */

/* Called by: */
char* zx_ENC_WO_mm7_Recipients(struct zx_ctx* c, struct zx_mm7_Recipients_s* x, char* p )
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
  ZX_OUT_MEM(p, "Recipients", sizeof("Recipients")-1);
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
  ENC_LEN_DEBUG(x, "mm7:Recipients", p-enc_base);
  return p;
}

/* FUNC(zx_EASY_ENC_SO_mm7_Recipients) */

/* Called by: */
struct zx_str* zx_EASY_ENC_SO_mm7_Recipients(struct zx_ctx* c, struct zx_mm7_Recipients_s* x )
{
  int len;
  char* buf;
  c->ns_tab = ZX_ALLOC(c, sizeof(zx_ns_tab));
  memcpy(c->ns_tab, zx_ns_tab, sizeof(zx_ns_tab));
  len = zx_LEN_SO_mm7_Recipients(c, x );
  buf = ZX_ALLOC(c, len+1);
  return zx_easy_enc_common(c, zx_ENC_SO_mm7_Recipients(c, x, buf ), buf, len);
}

/* FUNC(zx_EASY_ENC_WO_mm7_Recipients) */

/* Called by: */
struct zx_str* zx_EASY_ENC_WO_mm7_Recipients(struct zx_ctx* c, struct zx_mm7_Recipients_s* x )
{
  int len;
  char* buf;
  c->ns_tab = ZX_ALLOC(c, sizeof(zx_ns_tab));
  memcpy(c->ns_tab, zx_ns_tab, sizeof(zx_ns_tab));
  len = zx_LEN_WO_mm7_Recipients(c, x );
  buf = ZX_ALLOC(c, len+1);
  return zx_easy_enc_common(c, zx_ENC_WO_mm7_Recipients(c, x, buf ), buf, len);
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

#define EL_NAME   mm7_ReplaceReq
#define EL_STRUCT zx_mm7_ReplaceReq_s
#define EL_NS     mm7
#define EL_TAG    ReplaceReq

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

/* FUNC(zx_LEN_SO_mm7_ReplaceReq) */

/* Compute length of an element (and its subelements). The XML attributes
 * and elements are processed in schema order. */

/* Called by: */
int zx_LEN_SO_mm7_ReplaceReq(struct zx_ctx* c, struct zx_mm7_ReplaceReq_s* x )
{
  struct zx_ns_s* pop_seen = 0;
  struct zx_elem_s* se MAYBE_UNUSED;
#if 1 /* NORMALMODE */
  /* *** in simple_elem case should output ns prefix from ns node. */
  int len = sizeof("<mm7:ReplaceReq")-1 + 1 + sizeof("</mm7:ReplaceReq>")-1;
  if (c->inc_ns_len)
    len += zx_len_inc_ns(c, &pop_seen);
  len += zx_len_xmlns_if_not_seen(c, zx_ns_tab+zx_xmlns_ix_mm7, &pop_seen);


#else
  /* root node has no begin tag */
  int len = 0;
#endif
  
  for (se = x->MM7Version; se; se = (struct zx_elem_s*)se->g.n)
    len += zx_LEN_SO_simple_elem(c,se, sizeof("mm7:MM7Version")-1, zx_ns_tab+zx_xmlns_ix_mm7);
  {
      struct zx_mm7_SenderIdentification_s* e;
      for (e = x->SenderIdentification; e; e = (struct zx_mm7_SenderIdentification_s*)e->gg.g.n)
	  len += zx_LEN_SO_mm7_SenderIdentification(c, e);
  }
  {
      struct zx_mm7_Extension_s* e;
      for (e = x->Extension; e; e = (struct zx_mm7_Extension_s*)e->gg.g.n)
	  len += zx_LEN_SO_mm7_Extension(c, e);
  }
  for (se = x->MessageID; se; se = (struct zx_elem_s*)se->g.n)
    len += zx_LEN_SO_simple_elem(c,se, sizeof("mm7:MessageID")-1, zx_ns_tab+zx_xmlns_ix_mm7);
  {
      struct zx_mm7_ServiceCode_s* e;
      for (e = x->ServiceCode; e; e = (struct zx_mm7_ServiceCode_s*)e->gg.g.n)
	  len += zx_LEN_SO_mm7_ServiceCode(c, e);
  }
  for (se = x->TimeStamp; se; se = (struct zx_elem_s*)se->g.n)
    len += zx_LEN_SO_simple_elem(c,se, sizeof("mm7:TimeStamp")-1, zx_ns_tab+zx_xmlns_ix_mm7);
  for (se = x->ReadReply; se; se = (struct zx_elem_s*)se->g.n)
    len += zx_LEN_SO_simple_elem(c,se, sizeof("mm7:ReadReply")-1, zx_ns_tab+zx_xmlns_ix_mm7);
  for (se = x->EarliestDeliveryTime; se; se = (struct zx_elem_s*)se->g.n)
    len += zx_LEN_SO_simple_elem(c,se, sizeof("mm7:EarliestDeliveryTime")-1, zx_ns_tab+zx_xmlns_ix_mm7);
  for (se = x->DistributionIndicator; se; se = (struct zx_elem_s*)se->g.n)
    len += zx_LEN_SO_simple_elem(c,se, sizeof("mm7:DistributionIndicator")-1, zx_ns_tab+zx_xmlns_ix_mm7);
  for (se = x->ContentClass; se; se = (struct zx_elem_s*)se->g.n)
    len += zx_LEN_SO_simple_elem(c,se, sizeof("mm7:ContentClass")-1, zx_ns_tab+zx_xmlns_ix_mm7);
  for (se = x->DRMContent; se; se = (struct zx_elem_s*)se->g.n)
    len += zx_LEN_SO_simple_elem(c,se, sizeof("mm7:DRMContent")-1, zx_ns_tab+zx_xmlns_ix_mm7);
  for (se = x->ApplicID; se; se = (struct zx_elem_s*)se->g.n)
    len += zx_LEN_SO_simple_elem(c,se, sizeof("mm7:ApplicID")-1, zx_ns_tab+zx_xmlns_ix_mm7);
  for (se = x->ReplyApplicID; se; se = (struct zx_elem_s*)se->g.n)
    len += zx_LEN_SO_simple_elem(c,se, sizeof("mm7:ReplyApplicID")-1, zx_ns_tab+zx_xmlns_ix_mm7);
  for (se = x->AuxApplicInfo; se; se = (struct zx_elem_s*)se->g.n)
    len += zx_LEN_SO_simple_elem(c,se, sizeof("mm7:AuxApplicInfo")-1, zx_ns_tab+zx_xmlns_ix_mm7);
  {
      struct zx_mm7_Content_s* e;
      for (e = x->Content; e; e = (struct zx_mm7_Content_s*)e->gg.g.n)
	  len += zx_LEN_SO_mm7_Content(c, e);
  }
  {
      struct zx_mm7_AdditionalInformation_s* e;
      for (e = x->AdditionalInformation; e; e = (struct zx_mm7_AdditionalInformation_s*)e->gg.g.n)
	  len += zx_LEN_SO_mm7_AdditionalInformation(c, e);
  }
  {
      struct zx_mm7_MessageExtraData_s* e;
      for (e = x->MessageExtraData; e; e = (struct zx_mm7_MessageExtraData_s*)e->gg.g.n)
	  len += zx_LEN_SO_mm7_MessageExtraData(c, e);
  }


  len += zx_len_so_common(c, &x->gg);
  zx_pop_seen(pop_seen);
  ENC_LEN_DEBUG(x, "mm7:ReplaceReq", len);
  return len;
}

/* FUNC(zx_LEN_WO_mm7_ReplaceReq) */

/* Compute length of an element (and its subelements). The XML attributes
 * and elements are processed in wire order and no assumptions
 * are made about namespace prefixes. */

/* Called by: */
int zx_LEN_WO_mm7_ReplaceReq(struct zx_ctx* c, struct zx_mm7_ReplaceReq_s* x )
{
  struct zx_ns_s* pop_seen = 0;
  struct zx_elem_s* se MAYBE_UNUSED;
#if 1 /* NORMALMODE */
  int len = 1 + sizeof("ReplaceReq")-1 + 1 + 2 + sizeof("ReplaceReq")-1 + 1;
  
  if (x->gg.g.ns && x->gg.g.ns->prefix_len)
    len += (x->gg.g.ns->prefix_len + 1) * 2;
  if (c->inc_ns_len)
    len += zx_len_inc_ns(c, &pop_seen);
  len += zx_len_xmlns_if_not_seen(c, x->gg.g.ns, &pop_seen);


#else
  /* root node has no begin tag */
  int len = 0;
#endif
  
  for (se = x->MM7Version; se; se = (struct zx_elem_s*)se->g.n)
    len += zx_LEN_WO_simple_elem(c, se, sizeof("MM7Version")-1);
  {
      struct zx_mm7_SenderIdentification_s* e;
      for (e = x->SenderIdentification; e; e = (struct zx_mm7_SenderIdentification_s*)e->gg.g.n)
	  len += zx_LEN_WO_mm7_SenderIdentification(c, e);
  }
  {
      struct zx_mm7_Extension_s* e;
      for (e = x->Extension; e; e = (struct zx_mm7_Extension_s*)e->gg.g.n)
	  len += zx_LEN_WO_mm7_Extension(c, e);
  }
  for (se = x->MessageID; se; se = (struct zx_elem_s*)se->g.n)
    len += zx_LEN_WO_simple_elem(c, se, sizeof("MessageID")-1);
  {
      struct zx_mm7_ServiceCode_s* e;
      for (e = x->ServiceCode; e; e = (struct zx_mm7_ServiceCode_s*)e->gg.g.n)
	  len += zx_LEN_WO_mm7_ServiceCode(c, e);
  }
  for (se = x->TimeStamp; se; se = (struct zx_elem_s*)se->g.n)
    len += zx_LEN_WO_simple_elem(c, se, sizeof("TimeStamp")-1);
  for (se = x->ReadReply; se; se = (struct zx_elem_s*)se->g.n)
    len += zx_LEN_WO_simple_elem(c, se, sizeof("ReadReply")-1);
  for (se = x->EarliestDeliveryTime; se; se = (struct zx_elem_s*)se->g.n)
    len += zx_LEN_WO_simple_elem(c, se, sizeof("EarliestDeliveryTime")-1);
  for (se = x->DistributionIndicator; se; se = (struct zx_elem_s*)se->g.n)
    len += zx_LEN_WO_simple_elem(c, se, sizeof("DistributionIndicator")-1);
  for (se = x->ContentClass; se; se = (struct zx_elem_s*)se->g.n)
    len += zx_LEN_WO_simple_elem(c, se, sizeof("ContentClass")-1);
  for (se = x->DRMContent; se; se = (struct zx_elem_s*)se->g.n)
    len += zx_LEN_WO_simple_elem(c, se, sizeof("DRMContent")-1);
  for (se = x->ApplicID; se; se = (struct zx_elem_s*)se->g.n)
    len += zx_LEN_WO_simple_elem(c, se, sizeof("ApplicID")-1);
  for (se = x->ReplyApplicID; se; se = (struct zx_elem_s*)se->g.n)
    len += zx_LEN_WO_simple_elem(c, se, sizeof("ReplyApplicID")-1);
  for (se = x->AuxApplicInfo; se; se = (struct zx_elem_s*)se->g.n)
    len += zx_LEN_WO_simple_elem(c, se, sizeof("AuxApplicInfo")-1);
  {
      struct zx_mm7_Content_s* e;
      for (e = x->Content; e; e = (struct zx_mm7_Content_s*)e->gg.g.n)
	  len += zx_LEN_WO_mm7_Content(c, e);
  }
  {
      struct zx_mm7_AdditionalInformation_s* e;
      for (e = x->AdditionalInformation; e; e = (struct zx_mm7_AdditionalInformation_s*)e->gg.g.n)
	  len += zx_LEN_WO_mm7_AdditionalInformation(c, e);
  }
  {
      struct zx_mm7_MessageExtraData_s* e;
      for (e = x->MessageExtraData; e; e = (struct zx_mm7_MessageExtraData_s*)e->gg.g.n)
	  len += zx_LEN_WO_mm7_MessageExtraData(c, e);
  }


  len += zx_len_wo_common(c, &x->gg); 
  zx_pop_seen(pop_seen);
  ENC_LEN_DEBUG(x, "mm7:ReplaceReq", len);
  return len;
}

/* FUNC(zx_ENC_SO_mm7_ReplaceReq) */

/* Render element into string. The XML attributes and elements are
 * processed in schema order. This is what you generally want for
 * rendering new data structure to a string. The wo pointers are not used. */

/* Called by: */
char* zx_ENC_SO_mm7_ReplaceReq(struct zx_ctx* c, struct zx_mm7_ReplaceReq_s* x, char* p )
{
  struct zx_elem_s* se MAYBE_UNUSED;
  struct zx_ns_s* pop_seen = 0;
  ENC_LEN_DEBUG_BASE;
#if 1 /* NORMALMODE */
  /* *** in simple_elem case should output ns prefix from ns node. */
  ZX_OUT_TAG(p, "<mm7:ReplaceReq");
  if (c->inc_ns)
    p = zx_enc_inc_ns(c, p, &pop_seen);
  p = zx_enc_xmlns_if_not_seen(c, p, zx_ns_tab+zx_xmlns_ix_mm7, &pop_seen);


  p = zx_enc_unknown_attrs(p, x->gg.any_attr);
#else
  /* root node has no begin tag */
#endif
  
  for (se = x->MM7Version; se; se = (struct zx_elem_s*)se->g.n)
    p = zx_ENC_SO_simple_elem(c, se, p, "mm7:MM7Version", sizeof("mm7:MM7Version")-1, zx_ns_tab+zx_xmlns_ix_mm7);
  {
      struct zx_mm7_SenderIdentification_s* e;
      for (e = x->SenderIdentification; e; e = (struct zx_mm7_SenderIdentification_s*)e->gg.g.n)
	  p = zx_ENC_SO_mm7_SenderIdentification(c, e, p);
  }
  {
      struct zx_mm7_Extension_s* e;
      for (e = x->Extension; e; e = (struct zx_mm7_Extension_s*)e->gg.g.n)
	  p = zx_ENC_SO_mm7_Extension(c, e, p);
  }
  for (se = x->MessageID; se; se = (struct zx_elem_s*)se->g.n)
    p = zx_ENC_SO_simple_elem(c, se, p, "mm7:MessageID", sizeof("mm7:MessageID")-1, zx_ns_tab+zx_xmlns_ix_mm7);
  {
      struct zx_mm7_ServiceCode_s* e;
      for (e = x->ServiceCode; e; e = (struct zx_mm7_ServiceCode_s*)e->gg.g.n)
	  p = zx_ENC_SO_mm7_ServiceCode(c, e, p);
  }
  for (se = x->TimeStamp; se; se = (struct zx_elem_s*)se->g.n)
    p = zx_ENC_SO_simple_elem(c, se, p, "mm7:TimeStamp", sizeof("mm7:TimeStamp")-1, zx_ns_tab+zx_xmlns_ix_mm7);
  for (se = x->ReadReply; se; se = (struct zx_elem_s*)se->g.n)
    p = zx_ENC_SO_simple_elem(c, se, p, "mm7:ReadReply", sizeof("mm7:ReadReply")-1, zx_ns_tab+zx_xmlns_ix_mm7);
  for (se = x->EarliestDeliveryTime; se; se = (struct zx_elem_s*)se->g.n)
    p = zx_ENC_SO_simple_elem(c, se, p, "mm7:EarliestDeliveryTime", sizeof("mm7:EarliestDeliveryTime")-1, zx_ns_tab+zx_xmlns_ix_mm7);
  for (se = x->DistributionIndicator; se; se = (struct zx_elem_s*)se->g.n)
    p = zx_ENC_SO_simple_elem(c, se, p, "mm7:DistributionIndicator", sizeof("mm7:DistributionIndicator")-1, zx_ns_tab+zx_xmlns_ix_mm7);
  for (se = x->ContentClass; se; se = (struct zx_elem_s*)se->g.n)
    p = zx_ENC_SO_simple_elem(c, se, p, "mm7:ContentClass", sizeof("mm7:ContentClass")-1, zx_ns_tab+zx_xmlns_ix_mm7);
  for (se = x->DRMContent; se; se = (struct zx_elem_s*)se->g.n)
    p = zx_ENC_SO_simple_elem(c, se, p, "mm7:DRMContent", sizeof("mm7:DRMContent")-1, zx_ns_tab+zx_xmlns_ix_mm7);
  for (se = x->ApplicID; se; se = (struct zx_elem_s*)se->g.n)
    p = zx_ENC_SO_simple_elem(c, se, p, "mm7:ApplicID", sizeof("mm7:ApplicID")-1, zx_ns_tab+zx_xmlns_ix_mm7);
  for (se = x->ReplyApplicID; se; se = (struct zx_elem_s*)se->g.n)
    p = zx_ENC_SO_simple_elem(c, se, p, "mm7:ReplyApplicID", sizeof("mm7:ReplyApplicID")-1, zx_ns_tab+zx_xmlns_ix_mm7);
  for (se = x->AuxApplicInfo; se; se = (struct zx_elem_s*)se->g.n)
    p = zx_ENC_SO_simple_elem(c, se, p, "mm7:AuxApplicInfo", sizeof("mm7:AuxApplicInfo")-1, zx_ns_tab+zx_xmlns_ix_mm7);
  {
      struct zx_mm7_Content_s* e;
      for (e = x->Content; e; e = (struct zx_mm7_Content_s*)e->gg.g.n)
	  p = zx_ENC_SO_mm7_Content(c, e, p);
  }
  {
      struct zx_mm7_AdditionalInformation_s* e;
      for (e = x->AdditionalInformation; e; e = (struct zx_mm7_AdditionalInformation_s*)e->gg.g.n)
	  p = zx_ENC_SO_mm7_AdditionalInformation(c, e, p);
  }
  {
      struct zx_mm7_MessageExtraData_s* e;
      for (e = x->MessageExtraData; e; e = (struct zx_mm7_MessageExtraData_s*)e->gg.g.n)
	  p = zx_ENC_SO_mm7_MessageExtraData(c, e, p);
  }

  p = zx_enc_so_unknown_elems_and_content(c, p, &x->gg);
  
#if 1 /* NORMALMODE */
  ZX_OUT_CLOSE_TAG(p, "</mm7:ReplaceReq>");
  zx_pop_seen(pop_seen);
#else
  /* root node has no end tag either */
#endif
  ENC_LEN_DEBUG(x, "mm7:ReplaceReq", p-enc_base);
  return p;
}

/* FUNC(zx_ENC_WO_mm7_ReplaceReq) */

/* Render element into string. The XML attributes and elements are
 * processed in wire order by chasing wo pointers. This is what you want for
 * validating signatures on other people's XML documents. */

/* Called by: */
char* zx_ENC_WO_mm7_ReplaceReq(struct zx_ctx* c, struct zx_mm7_ReplaceReq_s* x, char* p )
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
  ZX_OUT_MEM(p, "ReplaceReq", sizeof("ReplaceReq")-1);
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
  ENC_LEN_DEBUG(x, "mm7:ReplaceReq", p-enc_base);
  return p;
}

/* FUNC(zx_EASY_ENC_SO_mm7_ReplaceReq) */

/* Called by: */
struct zx_str* zx_EASY_ENC_SO_mm7_ReplaceReq(struct zx_ctx* c, struct zx_mm7_ReplaceReq_s* x )
{
  int len;
  char* buf;
  c->ns_tab = ZX_ALLOC(c, sizeof(zx_ns_tab));
  memcpy(c->ns_tab, zx_ns_tab, sizeof(zx_ns_tab));
  len = zx_LEN_SO_mm7_ReplaceReq(c, x );
  buf = ZX_ALLOC(c, len+1);
  return zx_easy_enc_common(c, zx_ENC_SO_mm7_ReplaceReq(c, x, buf ), buf, len);
}

/* FUNC(zx_EASY_ENC_WO_mm7_ReplaceReq) */

/* Called by: */
struct zx_str* zx_EASY_ENC_WO_mm7_ReplaceReq(struct zx_ctx* c, struct zx_mm7_ReplaceReq_s* x )
{
  int len;
  char* buf;
  c->ns_tab = ZX_ALLOC(c, sizeof(zx_ns_tab));
  memcpy(c->ns_tab, zx_ns_tab, sizeof(zx_ns_tab));
  len = zx_LEN_WO_mm7_ReplaceReq(c, x );
  buf = ZX_ALLOC(c, len+1);
  return zx_easy_enc_common(c, zx_ENC_WO_mm7_ReplaceReq(c, x, buf ), buf, len);
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

#define EL_NAME   mm7_ReplaceRsp
#define EL_STRUCT zx_mm7_ReplaceRsp_s
#define EL_NS     mm7
#define EL_TAG    ReplaceRsp

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

/* FUNC(zx_LEN_SO_mm7_ReplaceRsp) */

/* Compute length of an element (and its subelements). The XML attributes
 * and elements are processed in schema order. */

/* Called by: */
int zx_LEN_SO_mm7_ReplaceRsp(struct zx_ctx* c, struct zx_mm7_ReplaceRsp_s* x )
{
  struct zx_ns_s* pop_seen = 0;
  struct zx_elem_s* se MAYBE_UNUSED;
#if 1 /* NORMALMODE */
  /* *** in simple_elem case should output ns prefix from ns node. */
  int len = sizeof("<mm7:ReplaceRsp")-1 + 1 + sizeof("</mm7:ReplaceRsp>")-1;
  if (c->inc_ns_len)
    len += zx_len_inc_ns(c, &pop_seen);
  len += zx_len_xmlns_if_not_seen(c, zx_ns_tab+zx_xmlns_ix_mm7, &pop_seen);


#else
  /* root node has no begin tag */
  int len = 0;
#endif
  
  for (se = x->MM7Version; se; se = (struct zx_elem_s*)se->g.n)
    len += zx_LEN_SO_simple_elem(c,se, sizeof("mm7:MM7Version")-1, zx_ns_tab+zx_xmlns_ix_mm7);
  {
      struct zx_mm7_Status_s* e;
      for (e = x->Status; e; e = (struct zx_mm7_Status_s*)e->gg.g.n)
	  len += zx_LEN_SO_mm7_Status(c, e);
  }
  {
      struct zx_mm7_Extension_s* e;
      for (e = x->Extension; e; e = (struct zx_mm7_Extension_s*)e->gg.g.n)
	  len += zx_LEN_SO_mm7_Extension(c, e);
  }


  len += zx_len_so_common(c, &x->gg);
  zx_pop_seen(pop_seen);
  ENC_LEN_DEBUG(x, "mm7:ReplaceRsp", len);
  return len;
}

/* FUNC(zx_LEN_WO_mm7_ReplaceRsp) */

/* Compute length of an element (and its subelements). The XML attributes
 * and elements are processed in wire order and no assumptions
 * are made about namespace prefixes. */

/* Called by: */
int zx_LEN_WO_mm7_ReplaceRsp(struct zx_ctx* c, struct zx_mm7_ReplaceRsp_s* x )
{
  struct zx_ns_s* pop_seen = 0;
  struct zx_elem_s* se MAYBE_UNUSED;
#if 1 /* NORMALMODE */
  int len = 1 + sizeof("ReplaceRsp")-1 + 1 + 2 + sizeof("ReplaceRsp")-1 + 1;
  
  if (x->gg.g.ns && x->gg.g.ns->prefix_len)
    len += (x->gg.g.ns->prefix_len + 1) * 2;
  if (c->inc_ns_len)
    len += zx_len_inc_ns(c, &pop_seen);
  len += zx_len_xmlns_if_not_seen(c, x->gg.g.ns, &pop_seen);


#else
  /* root node has no begin tag */
  int len = 0;
#endif
  
  for (se = x->MM7Version; se; se = (struct zx_elem_s*)se->g.n)
    len += zx_LEN_WO_simple_elem(c, se, sizeof("MM7Version")-1);
  {
      struct zx_mm7_Status_s* e;
      for (e = x->Status; e; e = (struct zx_mm7_Status_s*)e->gg.g.n)
	  len += zx_LEN_WO_mm7_Status(c, e);
  }
  {
      struct zx_mm7_Extension_s* e;
      for (e = x->Extension; e; e = (struct zx_mm7_Extension_s*)e->gg.g.n)
	  len += zx_LEN_WO_mm7_Extension(c, e);
  }


  len += zx_len_wo_common(c, &x->gg); 
  zx_pop_seen(pop_seen);
  ENC_LEN_DEBUG(x, "mm7:ReplaceRsp", len);
  return len;
}

/* FUNC(zx_ENC_SO_mm7_ReplaceRsp) */

/* Render element into string. The XML attributes and elements are
 * processed in schema order. This is what you generally want for
 * rendering new data structure to a string. The wo pointers are not used. */

/* Called by: */
char* zx_ENC_SO_mm7_ReplaceRsp(struct zx_ctx* c, struct zx_mm7_ReplaceRsp_s* x, char* p )
{
  struct zx_elem_s* se MAYBE_UNUSED;
  struct zx_ns_s* pop_seen = 0;
  ENC_LEN_DEBUG_BASE;
#if 1 /* NORMALMODE */
  /* *** in simple_elem case should output ns prefix from ns node. */
  ZX_OUT_TAG(p, "<mm7:ReplaceRsp");
  if (c->inc_ns)
    p = zx_enc_inc_ns(c, p, &pop_seen);
  p = zx_enc_xmlns_if_not_seen(c, p, zx_ns_tab+zx_xmlns_ix_mm7, &pop_seen);


  p = zx_enc_unknown_attrs(p, x->gg.any_attr);
#else
  /* root node has no begin tag */
#endif
  
  for (se = x->MM7Version; se; se = (struct zx_elem_s*)se->g.n)
    p = zx_ENC_SO_simple_elem(c, se, p, "mm7:MM7Version", sizeof("mm7:MM7Version")-1, zx_ns_tab+zx_xmlns_ix_mm7);
  {
      struct zx_mm7_Status_s* e;
      for (e = x->Status; e; e = (struct zx_mm7_Status_s*)e->gg.g.n)
	  p = zx_ENC_SO_mm7_Status(c, e, p);
  }
  {
      struct zx_mm7_Extension_s* e;
      for (e = x->Extension; e; e = (struct zx_mm7_Extension_s*)e->gg.g.n)
	  p = zx_ENC_SO_mm7_Extension(c, e, p);
  }

  p = zx_enc_so_unknown_elems_and_content(c, p, &x->gg);
  
#if 1 /* NORMALMODE */
  ZX_OUT_CLOSE_TAG(p, "</mm7:ReplaceRsp>");
  zx_pop_seen(pop_seen);
#else
  /* root node has no end tag either */
#endif
  ENC_LEN_DEBUG(x, "mm7:ReplaceRsp", p-enc_base);
  return p;
}

/* FUNC(zx_ENC_WO_mm7_ReplaceRsp) */

/* Render element into string. The XML attributes and elements are
 * processed in wire order by chasing wo pointers. This is what you want for
 * validating signatures on other people's XML documents. */

/* Called by: */
char* zx_ENC_WO_mm7_ReplaceRsp(struct zx_ctx* c, struct zx_mm7_ReplaceRsp_s* x, char* p )
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
  ZX_OUT_MEM(p, "ReplaceRsp", sizeof("ReplaceRsp")-1);
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
  ENC_LEN_DEBUG(x, "mm7:ReplaceRsp", p-enc_base);
  return p;
}

/* FUNC(zx_EASY_ENC_SO_mm7_ReplaceRsp) */

/* Called by: */
struct zx_str* zx_EASY_ENC_SO_mm7_ReplaceRsp(struct zx_ctx* c, struct zx_mm7_ReplaceRsp_s* x )
{
  int len;
  char* buf;
  c->ns_tab = ZX_ALLOC(c, sizeof(zx_ns_tab));
  memcpy(c->ns_tab, zx_ns_tab, sizeof(zx_ns_tab));
  len = zx_LEN_SO_mm7_ReplaceRsp(c, x );
  buf = ZX_ALLOC(c, len+1);
  return zx_easy_enc_common(c, zx_ENC_SO_mm7_ReplaceRsp(c, x, buf ), buf, len);
}

/* FUNC(zx_EASY_ENC_WO_mm7_ReplaceRsp) */

/* Called by: */
struct zx_str* zx_EASY_ENC_WO_mm7_ReplaceRsp(struct zx_ctx* c, struct zx_mm7_ReplaceRsp_s* x )
{
  int len;
  char* buf;
  c->ns_tab = ZX_ALLOC(c, sizeof(zx_ns_tab));
  memcpy(c->ns_tab, zx_ns_tab, sizeof(zx_ns_tab));
  len = zx_LEN_WO_mm7_ReplaceRsp(c, x );
  buf = ZX_ALLOC(c, len+1);
  return zx_easy_enc_common(c, zx_ENC_WO_mm7_ReplaceRsp(c, x, buf ), buf, len);
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

#define EL_NAME   mm7_ReplyCharging
#define EL_STRUCT zx_mm7_ReplyCharging_s
#define EL_NS     mm7
#define EL_TAG    ReplyCharging

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

/* FUNC(zx_LEN_SO_mm7_ReplyCharging) */

/* Compute length of an element (and its subelements). The XML attributes
 * and elements are processed in schema order. */

/* Called by: */
int zx_LEN_SO_mm7_ReplyCharging(struct zx_ctx* c, struct zx_mm7_ReplyCharging_s* x )
{
  struct zx_ns_s* pop_seen = 0;
  struct zx_elem_s* se MAYBE_UNUSED;
#if 1 /* NORMALMODE */
  /* *** in simple_elem case should output ns prefix from ns node. */
  int len = sizeof("<mm7:ReplyCharging")-1 + 1 + sizeof("</mm7:ReplyCharging>")-1;
  if (c->inc_ns_len)
    len += zx_len_inc_ns(c, &pop_seen);
  len += zx_len_xmlns_if_not_seen(c, zx_ns_tab+zx_xmlns_ix_mm7, &pop_seen);

  len += zx_attr_so_len(x->replyChargingSize, sizeof("replyChargingSize")-1);
  len += zx_attr_so_len(x->replyDeadline, sizeof("replyDeadline")-1);

#else
  /* root node has no begin tag */
  int len = 0;
#endif
  


  len += zx_len_so_common(c, &x->gg);
  zx_pop_seen(pop_seen);
  ENC_LEN_DEBUG(x, "mm7:ReplyCharging", len);
  return len;
}

/* FUNC(zx_LEN_WO_mm7_ReplyCharging) */

/* Compute length of an element (and its subelements). The XML attributes
 * and elements are processed in wire order and no assumptions
 * are made about namespace prefixes. */

/* Called by: */
int zx_LEN_WO_mm7_ReplyCharging(struct zx_ctx* c, struct zx_mm7_ReplyCharging_s* x )
{
  struct zx_ns_s* pop_seen = 0;
  struct zx_elem_s* se MAYBE_UNUSED;
#if 1 /* NORMALMODE */
  int len = 1 + sizeof("ReplyCharging")-1 + 1 + 2 + sizeof("ReplyCharging")-1 + 1;
  
  if (x->gg.g.ns && x->gg.g.ns->prefix_len)
    len += (x->gg.g.ns->prefix_len + 1) * 2;
  if (c->inc_ns_len)
    len += zx_len_inc_ns(c, &pop_seen);
  len += zx_len_xmlns_if_not_seen(c, x->gg.g.ns, &pop_seen);

  len += zx_attr_wo_len(x->replyChargingSize, sizeof("replyChargingSize")-1);
  len += zx_attr_wo_len(x->replyDeadline, sizeof("replyDeadline")-1);

#else
  /* root node has no begin tag */
  int len = 0;
#endif
  


  len += zx_len_wo_common(c, &x->gg); 
  zx_pop_seen(pop_seen);
  ENC_LEN_DEBUG(x, "mm7:ReplyCharging", len);
  return len;
}

/* FUNC(zx_ENC_SO_mm7_ReplyCharging) */

/* Render element into string. The XML attributes and elements are
 * processed in schema order. This is what you generally want for
 * rendering new data structure to a string. The wo pointers are not used. */

/* Called by: */
char* zx_ENC_SO_mm7_ReplyCharging(struct zx_ctx* c, struct zx_mm7_ReplyCharging_s* x, char* p )
{
  struct zx_elem_s* se MAYBE_UNUSED;
  struct zx_ns_s* pop_seen = 0;
  ENC_LEN_DEBUG_BASE;
#if 1 /* NORMALMODE */
  /* *** in simple_elem case should output ns prefix from ns node. */
  ZX_OUT_TAG(p, "<mm7:ReplyCharging");
  if (c->inc_ns)
    p = zx_enc_inc_ns(c, p, &pop_seen);
  p = zx_enc_xmlns_if_not_seen(c, p, zx_ns_tab+zx_xmlns_ix_mm7, &pop_seen);

  p = zx_attr_so_enc(p, x->replyChargingSize, " replyChargingSize=\"", sizeof(" replyChargingSize=\"")-1);
  p = zx_attr_so_enc(p, x->replyDeadline, " replyDeadline=\"", sizeof(" replyDeadline=\"")-1);

  p = zx_enc_unknown_attrs(p, x->gg.any_attr);
#else
  /* root node has no begin tag */
#endif
  

  p = zx_enc_so_unknown_elems_and_content(c, p, &x->gg);
  
#if 1 /* NORMALMODE */
  ZX_OUT_CLOSE_TAG(p, "</mm7:ReplyCharging>");
  zx_pop_seen(pop_seen);
#else
  /* root node has no end tag either */
#endif
  ENC_LEN_DEBUG(x, "mm7:ReplyCharging", p-enc_base);
  return p;
}

/* FUNC(zx_ENC_WO_mm7_ReplyCharging) */

/* Render element into string. The XML attributes and elements are
 * processed in wire order by chasing wo pointers. This is what you want for
 * validating signatures on other people's XML documents. */

/* Called by: */
char* zx_ENC_WO_mm7_ReplyCharging(struct zx_ctx* c, struct zx_mm7_ReplyCharging_s* x, char* p )
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
  ZX_OUT_MEM(p, "ReplyCharging", sizeof("ReplyCharging")-1);
  qq = p;

  /* *** sort the namespaces */
  if (c->inc_ns)
    zx_add_inc_ns(c, &pop_seen);
  zx_add_xmlns_if_not_seen(c, x->gg.g.ns, &pop_seen);

  p = zx_enc_seen(p, pop_seen); 
  p = zx_attr_wo_enc(p, x->replyChargingSize, "replyChargingSize=\"", sizeof("replyChargingSize=\"")-1);
  p = zx_attr_wo_enc(p, x->replyDeadline, "replyDeadline=\"", sizeof("replyDeadline=\"")-1);

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
  ENC_LEN_DEBUG(x, "mm7:ReplyCharging", p-enc_base);
  return p;
}

/* FUNC(zx_EASY_ENC_SO_mm7_ReplyCharging) */

/* Called by: */
struct zx_str* zx_EASY_ENC_SO_mm7_ReplyCharging(struct zx_ctx* c, struct zx_mm7_ReplyCharging_s* x )
{
  int len;
  char* buf;
  c->ns_tab = ZX_ALLOC(c, sizeof(zx_ns_tab));
  memcpy(c->ns_tab, zx_ns_tab, sizeof(zx_ns_tab));
  len = zx_LEN_SO_mm7_ReplyCharging(c, x );
  buf = ZX_ALLOC(c, len+1);
  return zx_easy_enc_common(c, zx_ENC_SO_mm7_ReplyCharging(c, x, buf ), buf, len);
}

/* FUNC(zx_EASY_ENC_WO_mm7_ReplyCharging) */

/* Called by: */
struct zx_str* zx_EASY_ENC_WO_mm7_ReplyCharging(struct zx_ctx* c, struct zx_mm7_ReplyCharging_s* x )
{
  int len;
  char* buf;
  c->ns_tab = ZX_ALLOC(c, sizeof(zx_ns_tab));
  memcpy(c->ns_tab, zx_ns_tab, sizeof(zx_ns_tab));
  len = zx_LEN_WO_mm7_ReplyCharging(c, x );
  buf = ZX_ALLOC(c, len+1);
  return zx_easy_enc_common(c, zx_ENC_WO_mm7_ReplyCharging(c, x, buf ), buf, len);
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

#define EL_NAME   mm7_Sender
#define EL_STRUCT zx_mm7_Sender_s
#define EL_NS     mm7
#define EL_TAG    Sender

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

/* FUNC(zx_LEN_SO_mm7_Sender) */

/* Compute length of an element (and its subelements). The XML attributes
 * and elements are processed in schema order. */

/* Called by: */
int zx_LEN_SO_mm7_Sender(struct zx_ctx* c, struct zx_mm7_Sender_s* x )
{
  struct zx_ns_s* pop_seen = 0;
  struct zx_elem_s* se MAYBE_UNUSED;
#if 1 /* NORMALMODE */
  /* *** in simple_elem case should output ns prefix from ns node. */
  int len = sizeof("<mm7:Sender")-1 + 1 + sizeof("</mm7:Sender>")-1;
  if (c->inc_ns_len)
    len += zx_len_inc_ns(c, &pop_seen);
  len += zx_len_xmlns_if_not_seen(c, zx_ns_tab+zx_xmlns_ix_mm7, &pop_seen);


#else
  /* root node has no begin tag */
  int len = 0;
#endif
  
  {
      struct zx_mm7_RFC2822Address_s* e;
      for (e = x->RFC2822Address; e; e = (struct zx_mm7_RFC2822Address_s*)e->gg.g.n)
	  len += zx_LEN_SO_mm7_RFC2822Address(c, e);
  }
  {
      struct zx_mm7_Number_s* e;
      for (e = x->Number; e; e = (struct zx_mm7_Number_s*)e->gg.g.n)
	  len += zx_LEN_SO_mm7_Number(c, e);
  }
  {
      struct zx_mm7_ShortCode_s* e;
      for (e = x->ShortCode; e; e = (struct zx_mm7_ShortCode_s*)e->gg.g.n)
	  len += zx_LEN_SO_mm7_ShortCode(c, e);
  }
  {
      struct zx_mm7_Extension_s* e;
      for (e = x->Extension; e; e = (struct zx_mm7_Extension_s*)e->gg.g.n)
	  len += zx_LEN_SO_mm7_Extension(c, e);
  }


  len += zx_len_so_common(c, &x->gg);
  zx_pop_seen(pop_seen);
  ENC_LEN_DEBUG(x, "mm7:Sender", len);
  return len;
}

/* FUNC(zx_LEN_WO_mm7_Sender) */

/* Compute length of an element (and its subelements). The XML attributes
 * and elements are processed in wire order and no assumptions
 * are made about namespace prefixes. */

/* Called by: */
int zx_LEN_WO_mm7_Sender(struct zx_ctx* c, struct zx_mm7_Sender_s* x )
{
  struct zx_ns_s* pop_seen = 0;
  struct zx_elem_s* se MAYBE_UNUSED;
#if 1 /* NORMALMODE */
  int len = 1 + sizeof("Sender")-1 + 1 + 2 + sizeof("Sender")-1 + 1;
  
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
      struct zx_mm7_RFC2822Address_s* e;
      for (e = x->RFC2822Address; e; e = (struct zx_mm7_RFC2822Address_s*)e->gg.g.n)
	  len += zx_LEN_WO_mm7_RFC2822Address(c, e);
  }
  {
      struct zx_mm7_Number_s* e;
      for (e = x->Number; e; e = (struct zx_mm7_Number_s*)e->gg.g.n)
	  len += zx_LEN_WO_mm7_Number(c, e);
  }
  {
      struct zx_mm7_ShortCode_s* e;
      for (e = x->ShortCode; e; e = (struct zx_mm7_ShortCode_s*)e->gg.g.n)
	  len += zx_LEN_WO_mm7_ShortCode(c, e);
  }
  {
      struct zx_mm7_Extension_s* e;
      for (e = x->Extension; e; e = (struct zx_mm7_Extension_s*)e->gg.g.n)
	  len += zx_LEN_WO_mm7_Extension(c, e);
  }


  len += zx_len_wo_common(c, &x->gg); 
  zx_pop_seen(pop_seen);
  ENC_LEN_DEBUG(x, "mm7:Sender", len);
  return len;
}

/* FUNC(zx_ENC_SO_mm7_Sender) */

/* Render element into string. The XML attributes and elements are
 * processed in schema order. This is what you generally want for
 * rendering new data structure to a string. The wo pointers are not used. */

/* Called by: */
char* zx_ENC_SO_mm7_Sender(struct zx_ctx* c, struct zx_mm7_Sender_s* x, char* p )
{
  struct zx_elem_s* se MAYBE_UNUSED;
  struct zx_ns_s* pop_seen = 0;
  ENC_LEN_DEBUG_BASE;
#if 1 /* NORMALMODE */
  /* *** in simple_elem case should output ns prefix from ns node. */
  ZX_OUT_TAG(p, "<mm7:Sender");
  if (c->inc_ns)
    p = zx_enc_inc_ns(c, p, &pop_seen);
  p = zx_enc_xmlns_if_not_seen(c, p, zx_ns_tab+zx_xmlns_ix_mm7, &pop_seen);


  p = zx_enc_unknown_attrs(p, x->gg.any_attr);
#else
  /* root node has no begin tag */
#endif
  
  {
      struct zx_mm7_RFC2822Address_s* e;
      for (e = x->RFC2822Address; e; e = (struct zx_mm7_RFC2822Address_s*)e->gg.g.n)
	  p = zx_ENC_SO_mm7_RFC2822Address(c, e, p);
  }
  {
      struct zx_mm7_Number_s* e;
      for (e = x->Number; e; e = (struct zx_mm7_Number_s*)e->gg.g.n)
	  p = zx_ENC_SO_mm7_Number(c, e, p);
  }
  {
      struct zx_mm7_ShortCode_s* e;
      for (e = x->ShortCode; e; e = (struct zx_mm7_ShortCode_s*)e->gg.g.n)
	  p = zx_ENC_SO_mm7_ShortCode(c, e, p);
  }
  {
      struct zx_mm7_Extension_s* e;
      for (e = x->Extension; e; e = (struct zx_mm7_Extension_s*)e->gg.g.n)
	  p = zx_ENC_SO_mm7_Extension(c, e, p);
  }

  p = zx_enc_so_unknown_elems_and_content(c, p, &x->gg);
  
#if 1 /* NORMALMODE */
  ZX_OUT_CLOSE_TAG(p, "</mm7:Sender>");
  zx_pop_seen(pop_seen);
#else
  /* root node has no end tag either */
#endif
  ENC_LEN_DEBUG(x, "mm7:Sender", p-enc_base);
  return p;
}

/* FUNC(zx_ENC_WO_mm7_Sender) */

/* Render element into string. The XML attributes and elements are
 * processed in wire order by chasing wo pointers. This is what you want for
 * validating signatures on other people's XML documents. */

/* Called by: */
char* zx_ENC_WO_mm7_Sender(struct zx_ctx* c, struct zx_mm7_Sender_s* x, char* p )
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
  ZX_OUT_MEM(p, "Sender", sizeof("Sender")-1);
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
  ENC_LEN_DEBUG(x, "mm7:Sender", p-enc_base);
  return p;
}

/* FUNC(zx_EASY_ENC_SO_mm7_Sender) */

/* Called by: */
struct zx_str* zx_EASY_ENC_SO_mm7_Sender(struct zx_ctx* c, struct zx_mm7_Sender_s* x )
{
  int len;
  char* buf;
  c->ns_tab = ZX_ALLOC(c, sizeof(zx_ns_tab));
  memcpy(c->ns_tab, zx_ns_tab, sizeof(zx_ns_tab));
  len = zx_LEN_SO_mm7_Sender(c, x );
  buf = ZX_ALLOC(c, len+1);
  return zx_easy_enc_common(c, zx_ENC_SO_mm7_Sender(c, x, buf ), buf, len);
}

/* FUNC(zx_EASY_ENC_WO_mm7_Sender) */

/* Called by: */
struct zx_str* zx_EASY_ENC_WO_mm7_Sender(struct zx_ctx* c, struct zx_mm7_Sender_s* x )
{
  int len;
  char* buf;
  c->ns_tab = ZX_ALLOC(c, sizeof(zx_ns_tab));
  memcpy(c->ns_tab, zx_ns_tab, sizeof(zx_ns_tab));
  len = zx_LEN_WO_mm7_Sender(c, x );
  buf = ZX_ALLOC(c, len+1);
  return zx_easy_enc_common(c, zx_ENC_WO_mm7_Sender(c, x, buf ), buf, len);
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

#define EL_NAME   mm7_SenderAddress
#define EL_STRUCT zx_mm7_SenderAddress_s
#define EL_NS     mm7
#define EL_TAG    SenderAddress

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

/* FUNC(zx_LEN_SO_mm7_SenderAddress) */

/* Compute length of an element (and its subelements). The XML attributes
 * and elements are processed in schema order. */

/* Called by: */
int zx_LEN_SO_mm7_SenderAddress(struct zx_ctx* c, struct zx_mm7_SenderAddress_s* x )
{
  struct zx_ns_s* pop_seen = 0;
  struct zx_elem_s* se MAYBE_UNUSED;
#if 1 /* NORMALMODE */
  /* *** in simple_elem case should output ns prefix from ns node. */
  int len = sizeof("<mm7:SenderAddress")-1 + 1 + sizeof("</mm7:SenderAddress>")-1;
  if (c->inc_ns_len)
    len += zx_len_inc_ns(c, &pop_seen);
  len += zx_len_xmlns_if_not_seen(c, zx_ns_tab+zx_xmlns_ix_mm7, &pop_seen);


#else
  /* root node has no begin tag */
  int len = 0;
#endif
  
  {
      struct zx_mm7_RFC2822Address_s* e;
      for (e = x->RFC2822Address; e; e = (struct zx_mm7_RFC2822Address_s*)e->gg.g.n)
	  len += zx_LEN_SO_mm7_RFC2822Address(c, e);
  }
  {
      struct zx_mm7_Number_s* e;
      for (e = x->Number; e; e = (struct zx_mm7_Number_s*)e->gg.g.n)
	  len += zx_LEN_SO_mm7_Number(c, e);
  }
  {
      struct zx_mm7_ShortCode_s* e;
      for (e = x->ShortCode; e; e = (struct zx_mm7_ShortCode_s*)e->gg.g.n)
	  len += zx_LEN_SO_mm7_ShortCode(c, e);
  }
  {
      struct zx_mm7_Extension_s* e;
      for (e = x->Extension; e; e = (struct zx_mm7_Extension_s*)e->gg.g.n)
	  len += zx_LEN_SO_mm7_Extension(c, e);
  }


  len += zx_len_so_common(c, &x->gg);
  zx_pop_seen(pop_seen);
  ENC_LEN_DEBUG(x, "mm7:SenderAddress", len);
  return len;
}

/* FUNC(zx_LEN_WO_mm7_SenderAddress) */

/* Compute length of an element (and its subelements). The XML attributes
 * and elements are processed in wire order and no assumptions
 * are made about namespace prefixes. */

/* Called by: */
int zx_LEN_WO_mm7_SenderAddress(struct zx_ctx* c, struct zx_mm7_SenderAddress_s* x )
{
  struct zx_ns_s* pop_seen = 0;
  struct zx_elem_s* se MAYBE_UNUSED;
#if 1 /* NORMALMODE */
  int len = 1 + sizeof("SenderAddress")-1 + 1 + 2 + sizeof("SenderAddress")-1 + 1;
  
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
      struct zx_mm7_RFC2822Address_s* e;
      for (e = x->RFC2822Address; e; e = (struct zx_mm7_RFC2822Address_s*)e->gg.g.n)
	  len += zx_LEN_WO_mm7_RFC2822Address(c, e);
  }
  {
      struct zx_mm7_Number_s* e;
      for (e = x->Number; e; e = (struct zx_mm7_Number_s*)e->gg.g.n)
	  len += zx_LEN_WO_mm7_Number(c, e);
  }
  {
      struct zx_mm7_ShortCode_s* e;
      for (e = x->ShortCode; e; e = (struct zx_mm7_ShortCode_s*)e->gg.g.n)
	  len += zx_LEN_WO_mm7_ShortCode(c, e);
  }
  {
      struct zx_mm7_Extension_s* e;
      for (e = x->Extension; e; e = (struct zx_mm7_Extension_s*)e->gg.g.n)
	  len += zx_LEN_WO_mm7_Extension(c, e);
  }


  len += zx_len_wo_common(c, &x->gg); 
  zx_pop_seen(pop_seen);
  ENC_LEN_DEBUG(x, "mm7:SenderAddress", len);
  return len;
}

/* FUNC(zx_ENC_SO_mm7_SenderAddress) */

/* Render element into string. The XML attributes and elements are
 * processed in schema order. This is what you generally want for
 * rendering new data structure to a string. The wo pointers are not used. */

/* Called by: */
char* zx_ENC_SO_mm7_SenderAddress(struct zx_ctx* c, struct zx_mm7_SenderAddress_s* x, char* p )
{
  struct zx_elem_s* se MAYBE_UNUSED;
  struct zx_ns_s* pop_seen = 0;
  ENC_LEN_DEBUG_BASE;
#if 1 /* NORMALMODE */
  /* *** in simple_elem case should output ns prefix from ns node. */
  ZX_OUT_TAG(p, "<mm7:SenderAddress");
  if (c->inc_ns)
    p = zx_enc_inc_ns(c, p, &pop_seen);
  p = zx_enc_xmlns_if_not_seen(c, p, zx_ns_tab+zx_xmlns_ix_mm7, &pop_seen);


  p = zx_enc_unknown_attrs(p, x->gg.any_attr);
#else
  /* root node has no begin tag */
#endif
  
  {
      struct zx_mm7_RFC2822Address_s* e;
      for (e = x->RFC2822Address; e; e = (struct zx_mm7_RFC2822Address_s*)e->gg.g.n)
	  p = zx_ENC_SO_mm7_RFC2822Address(c, e, p);
  }
  {
      struct zx_mm7_Number_s* e;
      for (e = x->Number; e; e = (struct zx_mm7_Number_s*)e->gg.g.n)
	  p = zx_ENC_SO_mm7_Number(c, e, p);
  }
  {
      struct zx_mm7_ShortCode_s* e;
      for (e = x->ShortCode; e; e = (struct zx_mm7_ShortCode_s*)e->gg.g.n)
	  p = zx_ENC_SO_mm7_ShortCode(c, e, p);
  }
  {
      struct zx_mm7_Extension_s* e;
      for (e = x->Extension; e; e = (struct zx_mm7_Extension_s*)e->gg.g.n)
	  p = zx_ENC_SO_mm7_Extension(c, e, p);
  }

  p = zx_enc_so_unknown_elems_and_content(c, p, &x->gg);
  
#if 1 /* NORMALMODE */
  ZX_OUT_CLOSE_TAG(p, "</mm7:SenderAddress>");
  zx_pop_seen(pop_seen);
#else
  /* root node has no end tag either */
#endif
  ENC_LEN_DEBUG(x, "mm7:SenderAddress", p-enc_base);
  return p;
}

/* FUNC(zx_ENC_WO_mm7_SenderAddress) */

/* Render element into string. The XML attributes and elements are
 * processed in wire order by chasing wo pointers. This is what you want for
 * validating signatures on other people's XML documents. */

/* Called by: */
char* zx_ENC_WO_mm7_SenderAddress(struct zx_ctx* c, struct zx_mm7_SenderAddress_s* x, char* p )
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
  ZX_OUT_MEM(p, "SenderAddress", sizeof("SenderAddress")-1);
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
  ENC_LEN_DEBUG(x, "mm7:SenderAddress", p-enc_base);
  return p;
}

/* FUNC(zx_EASY_ENC_SO_mm7_SenderAddress) */

/* Called by: */
struct zx_str* zx_EASY_ENC_SO_mm7_SenderAddress(struct zx_ctx* c, struct zx_mm7_SenderAddress_s* x )
{
  int len;
  char* buf;
  c->ns_tab = ZX_ALLOC(c, sizeof(zx_ns_tab));
  memcpy(c->ns_tab, zx_ns_tab, sizeof(zx_ns_tab));
  len = zx_LEN_SO_mm7_SenderAddress(c, x );
  buf = ZX_ALLOC(c, len+1);
  return zx_easy_enc_common(c, zx_ENC_SO_mm7_SenderAddress(c, x, buf ), buf, len);
}

/* FUNC(zx_EASY_ENC_WO_mm7_SenderAddress) */

/* Called by: */
struct zx_str* zx_EASY_ENC_WO_mm7_SenderAddress(struct zx_ctx* c, struct zx_mm7_SenderAddress_s* x )
{
  int len;
  char* buf;
  c->ns_tab = ZX_ALLOC(c, sizeof(zx_ns_tab));
  memcpy(c->ns_tab, zx_ns_tab, sizeof(zx_ns_tab));
  len = zx_LEN_WO_mm7_SenderAddress(c, x );
  buf = ZX_ALLOC(c, len+1);
  return zx_easy_enc_common(c, zx_ENC_WO_mm7_SenderAddress(c, x, buf ), buf, len);
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

#define EL_NAME   mm7_SenderIdentification
#define EL_STRUCT zx_mm7_SenderIdentification_s
#define EL_NS     mm7
#define EL_TAG    SenderIdentification

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

/* FUNC(zx_LEN_SO_mm7_SenderIdentification) */

/* Compute length of an element (and its subelements). The XML attributes
 * and elements are processed in schema order. */

/* Called by: */
int zx_LEN_SO_mm7_SenderIdentification(struct zx_ctx* c, struct zx_mm7_SenderIdentification_s* x )
{
  struct zx_ns_s* pop_seen = 0;
  struct zx_elem_s* se MAYBE_UNUSED;
#if 1 /* NORMALMODE */
  /* *** in simple_elem case should output ns prefix from ns node. */
  int len = sizeof("<mm7:SenderIdentification")-1 + 1 + sizeof("</mm7:SenderIdentification>")-1;
  if (c->inc_ns_len)
    len += zx_len_inc_ns(c, &pop_seen);
  len += zx_len_xmlns_if_not_seen(c, zx_ns_tab+zx_xmlns_ix_mm7, &pop_seen);


#else
  /* root node has no begin tag */
  int len = 0;
#endif
  
  for (se = x->VASPID; se; se = (struct zx_elem_s*)se->g.n)
    len += zx_LEN_SO_simple_elem(c,se, sizeof("mm7:VASPID")-1, zx_ns_tab+zx_xmlns_ix_mm7);
  for (se = x->VASID; se; se = (struct zx_elem_s*)se->g.n)
    len += zx_LEN_SO_simple_elem(c,se, sizeof("mm7:VASID")-1, zx_ns_tab+zx_xmlns_ix_mm7);
  {
      struct zx_mm7_SenderAddress_s* e;
      for (e = x->SenderAddress; e; e = (struct zx_mm7_SenderAddress_s*)e->gg.g.n)
	  len += zx_LEN_SO_mm7_SenderAddress(c, e);
  }


  len += zx_len_so_common(c, &x->gg);
  zx_pop_seen(pop_seen);
  ENC_LEN_DEBUG(x, "mm7:SenderIdentification", len);
  return len;
}

/* FUNC(zx_LEN_WO_mm7_SenderIdentification) */

/* Compute length of an element (and its subelements). The XML attributes
 * and elements are processed in wire order and no assumptions
 * are made about namespace prefixes. */

/* Called by: */
int zx_LEN_WO_mm7_SenderIdentification(struct zx_ctx* c, struct zx_mm7_SenderIdentification_s* x )
{
  struct zx_ns_s* pop_seen = 0;
  struct zx_elem_s* se MAYBE_UNUSED;
#if 1 /* NORMALMODE */
  int len = 1 + sizeof("SenderIdentification")-1 + 1 + 2 + sizeof("SenderIdentification")-1 + 1;
  
  if (x->gg.g.ns && x->gg.g.ns->prefix_len)
    len += (x->gg.g.ns->prefix_len + 1) * 2;
  if (c->inc_ns_len)
    len += zx_len_inc_ns(c, &pop_seen);
  len += zx_len_xmlns_if_not_seen(c, x->gg.g.ns, &pop_seen);


#else
  /* root node has no begin tag */
  int len = 0;
#endif
  
  for (se = x->VASPID; se; se = (struct zx_elem_s*)se->g.n)
    len += zx_LEN_WO_simple_elem(c, se, sizeof("VASPID")-1);
  for (se = x->VASID; se; se = (struct zx_elem_s*)se->g.n)
    len += zx_LEN_WO_simple_elem(c, se, sizeof("VASID")-1);
  {
      struct zx_mm7_SenderAddress_s* e;
      for (e = x->SenderAddress; e; e = (struct zx_mm7_SenderAddress_s*)e->gg.g.n)
	  len += zx_LEN_WO_mm7_SenderAddress(c, e);
  }


  len += zx_len_wo_common(c, &x->gg); 
  zx_pop_seen(pop_seen);
  ENC_LEN_DEBUG(x, "mm7:SenderIdentification", len);
  return len;
}

/* FUNC(zx_ENC_SO_mm7_SenderIdentification) */

/* Render element into string. The XML attributes and elements are
 * processed in schema order. This is what you generally want for
 * rendering new data structure to a string. The wo pointers are not used. */

/* Called by: */
char* zx_ENC_SO_mm7_SenderIdentification(struct zx_ctx* c, struct zx_mm7_SenderIdentification_s* x, char* p )
{
  struct zx_elem_s* se MAYBE_UNUSED;
  struct zx_ns_s* pop_seen = 0;
  ENC_LEN_DEBUG_BASE;
#if 1 /* NORMALMODE */
  /* *** in simple_elem case should output ns prefix from ns node. */
  ZX_OUT_TAG(p, "<mm7:SenderIdentification");
  if (c->inc_ns)
    p = zx_enc_inc_ns(c, p, &pop_seen);
  p = zx_enc_xmlns_if_not_seen(c, p, zx_ns_tab+zx_xmlns_ix_mm7, &pop_seen);


  p = zx_enc_unknown_attrs(p, x->gg.any_attr);
#else
  /* root node has no begin tag */
#endif
  
  for (se = x->VASPID; se; se = (struct zx_elem_s*)se->g.n)
    p = zx_ENC_SO_simple_elem(c, se, p, "mm7:VASPID", sizeof("mm7:VASPID")-1, zx_ns_tab+zx_xmlns_ix_mm7);
  for (se = x->VASID; se; se = (struct zx_elem_s*)se->g.n)
    p = zx_ENC_SO_simple_elem(c, se, p, "mm7:VASID", sizeof("mm7:VASID")-1, zx_ns_tab+zx_xmlns_ix_mm7);
  {
      struct zx_mm7_SenderAddress_s* e;
      for (e = x->SenderAddress; e; e = (struct zx_mm7_SenderAddress_s*)e->gg.g.n)
	  p = zx_ENC_SO_mm7_SenderAddress(c, e, p);
  }

  p = zx_enc_so_unknown_elems_and_content(c, p, &x->gg);
  
#if 1 /* NORMALMODE */
  ZX_OUT_CLOSE_TAG(p, "</mm7:SenderIdentification>");
  zx_pop_seen(pop_seen);
#else
  /* root node has no end tag either */
#endif
  ENC_LEN_DEBUG(x, "mm7:SenderIdentification", p-enc_base);
  return p;
}

/* FUNC(zx_ENC_WO_mm7_SenderIdentification) */

/* Render element into string. The XML attributes and elements are
 * processed in wire order by chasing wo pointers. This is what you want for
 * validating signatures on other people's XML documents. */

/* Called by: */
char* zx_ENC_WO_mm7_SenderIdentification(struct zx_ctx* c, struct zx_mm7_SenderIdentification_s* x, char* p )
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
  ZX_OUT_MEM(p, "SenderIdentification", sizeof("SenderIdentification")-1);
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
  ENC_LEN_DEBUG(x, "mm7:SenderIdentification", p-enc_base);
  return p;
}

/* FUNC(zx_EASY_ENC_SO_mm7_SenderIdentification) */

/* Called by: */
struct zx_str* zx_EASY_ENC_SO_mm7_SenderIdentification(struct zx_ctx* c, struct zx_mm7_SenderIdentification_s* x )
{
  int len;
  char* buf;
  c->ns_tab = ZX_ALLOC(c, sizeof(zx_ns_tab));
  memcpy(c->ns_tab, zx_ns_tab, sizeof(zx_ns_tab));
  len = zx_LEN_SO_mm7_SenderIdentification(c, x );
  buf = ZX_ALLOC(c, len+1);
  return zx_easy_enc_common(c, zx_ENC_SO_mm7_SenderIdentification(c, x, buf ), buf, len);
}

/* FUNC(zx_EASY_ENC_WO_mm7_SenderIdentification) */

/* Called by: */
struct zx_str* zx_EASY_ENC_WO_mm7_SenderIdentification(struct zx_ctx* c, struct zx_mm7_SenderIdentification_s* x )
{
  int len;
  char* buf;
  c->ns_tab = ZX_ALLOC(c, sizeof(zx_ns_tab));
  memcpy(c->ns_tab, zx_ns_tab, sizeof(zx_ns_tab));
  len = zx_LEN_WO_mm7_SenderIdentification(c, x );
  buf = ZX_ALLOC(c, len+1);
  return zx_easy_enc_common(c, zx_ENC_WO_mm7_SenderIdentification(c, x, buf ), buf, len);
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

#define EL_NAME   mm7_ServiceCode
#define EL_STRUCT zx_mm7_ServiceCode_s
#define EL_NS     mm7
#define EL_TAG    ServiceCode

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

/* FUNC(zx_LEN_SO_mm7_ServiceCode) */

/* Compute length of an element (and its subelements). The XML attributes
 * and elements are processed in schema order. */

/* Called by: */
int zx_LEN_SO_mm7_ServiceCode(struct zx_ctx* c, struct zx_mm7_ServiceCode_s* x )
{
  struct zx_ns_s* pop_seen = 0;
  struct zx_elem_s* se MAYBE_UNUSED;
#if 1 /* NORMALMODE */
  /* *** in simple_elem case should output ns prefix from ns node. */
  int len = sizeof("<mm7:ServiceCode")-1 + 1 + sizeof("</mm7:ServiceCode>")-1;
  if (c->inc_ns_len)
    len += zx_len_inc_ns(c, &pop_seen);
  len += zx_len_xmlns_if_not_seen(c, zx_ns_tab+zx_xmlns_ix_mm7, &pop_seen);


#else
  /* root node has no begin tag */
  int len = 0;
#endif
  


  len += zx_len_so_common(c, &x->gg);
  zx_pop_seen(pop_seen);
  ENC_LEN_DEBUG(x, "mm7:ServiceCode", len);
  return len;
}

/* FUNC(zx_LEN_WO_mm7_ServiceCode) */

/* Compute length of an element (and its subelements). The XML attributes
 * and elements are processed in wire order and no assumptions
 * are made about namespace prefixes. */

/* Called by: */
int zx_LEN_WO_mm7_ServiceCode(struct zx_ctx* c, struct zx_mm7_ServiceCode_s* x )
{
  struct zx_ns_s* pop_seen = 0;
  struct zx_elem_s* se MAYBE_UNUSED;
#if 1 /* NORMALMODE */
  int len = 1 + sizeof("ServiceCode")-1 + 1 + 2 + sizeof("ServiceCode")-1 + 1;
  
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
  ENC_LEN_DEBUG(x, "mm7:ServiceCode", len);
  return len;
}

/* FUNC(zx_ENC_SO_mm7_ServiceCode) */

/* Render element into string. The XML attributes and elements are
 * processed in schema order. This is what you generally want for
 * rendering new data structure to a string. The wo pointers are not used. */

/* Called by: */
char* zx_ENC_SO_mm7_ServiceCode(struct zx_ctx* c, struct zx_mm7_ServiceCode_s* x, char* p )
{
  struct zx_elem_s* se MAYBE_UNUSED;
  struct zx_ns_s* pop_seen = 0;
  ENC_LEN_DEBUG_BASE;
#if 1 /* NORMALMODE */
  /* *** in simple_elem case should output ns prefix from ns node. */
  ZX_OUT_TAG(p, "<mm7:ServiceCode");
  if (c->inc_ns)
    p = zx_enc_inc_ns(c, p, &pop_seen);
  p = zx_enc_xmlns_if_not_seen(c, p, zx_ns_tab+zx_xmlns_ix_mm7, &pop_seen);


  p = zx_enc_unknown_attrs(p, x->gg.any_attr);
#else
  /* root node has no begin tag */
#endif
  

  p = zx_enc_so_unknown_elems_and_content(c, p, &x->gg);
  
#if 1 /* NORMALMODE */
  ZX_OUT_CLOSE_TAG(p, "</mm7:ServiceCode>");
  zx_pop_seen(pop_seen);
#else
  /* root node has no end tag either */
#endif
  ENC_LEN_DEBUG(x, "mm7:ServiceCode", p-enc_base);
  return p;
}

/* FUNC(zx_ENC_WO_mm7_ServiceCode) */

/* Render element into string. The XML attributes and elements are
 * processed in wire order by chasing wo pointers. This is what you want for
 * validating signatures on other people's XML documents. */

/* Called by: */
char* zx_ENC_WO_mm7_ServiceCode(struct zx_ctx* c, struct zx_mm7_ServiceCode_s* x, char* p )
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
  ZX_OUT_MEM(p, "ServiceCode", sizeof("ServiceCode")-1);
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
  ENC_LEN_DEBUG(x, "mm7:ServiceCode", p-enc_base);
  return p;
}

/* FUNC(zx_EASY_ENC_SO_mm7_ServiceCode) */

/* Called by: */
struct zx_str* zx_EASY_ENC_SO_mm7_ServiceCode(struct zx_ctx* c, struct zx_mm7_ServiceCode_s* x )
{
  int len;
  char* buf;
  c->ns_tab = ZX_ALLOC(c, sizeof(zx_ns_tab));
  memcpy(c->ns_tab, zx_ns_tab, sizeof(zx_ns_tab));
  len = zx_LEN_SO_mm7_ServiceCode(c, x );
  buf = ZX_ALLOC(c, len+1);
  return zx_easy_enc_common(c, zx_ENC_SO_mm7_ServiceCode(c, x, buf ), buf, len);
}

/* FUNC(zx_EASY_ENC_WO_mm7_ServiceCode) */

/* Called by: */
struct zx_str* zx_EASY_ENC_WO_mm7_ServiceCode(struct zx_ctx* c, struct zx_mm7_ServiceCode_s* x )
{
  int len;
  char* buf;
  c->ns_tab = ZX_ALLOC(c, sizeof(zx_ns_tab));
  memcpy(c->ns_tab, zx_ns_tab, sizeof(zx_ns_tab));
  len = zx_LEN_WO_mm7_ServiceCode(c, x );
  buf = ZX_ALLOC(c, len+1);
  return zx_easy_enc_common(c, zx_ENC_WO_mm7_ServiceCode(c, x, buf ), buf, len);
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

#define EL_NAME   mm7_ShortCode
#define EL_STRUCT zx_mm7_ShortCode_s
#define EL_NS     mm7
#define EL_TAG    ShortCode

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

/* FUNC(zx_LEN_SO_mm7_ShortCode) */

/* Compute length of an element (and its subelements). The XML attributes
 * and elements are processed in schema order. */

/* Called by: */
int zx_LEN_SO_mm7_ShortCode(struct zx_ctx* c, struct zx_mm7_ShortCode_s* x )
{
  struct zx_ns_s* pop_seen = 0;
  struct zx_elem_s* se MAYBE_UNUSED;
#if 1 /* NORMALMODE */
  /* *** in simple_elem case should output ns prefix from ns node. */
  int len = sizeof("<mm7:ShortCode")-1 + 1 + sizeof("</mm7:ShortCode>")-1;
  if (c->inc_ns_len)
    len += zx_len_inc_ns(c, &pop_seen);
  len += zx_len_xmlns_if_not_seen(c, zx_ns_tab+zx_xmlns_ix_mm7, &pop_seen);

  len += zx_attr_so_len(x->addressCoding, sizeof("addressCoding")-1);
  len += zx_attr_so_len(x->displayOnly, sizeof("displayOnly")-1);
  len += zx_attr_so_len(x->id, sizeof("id")-1);

#else
  /* root node has no begin tag */
  int len = 0;
#endif
  


  len += zx_len_so_common(c, &x->gg);
  zx_pop_seen(pop_seen);
  ENC_LEN_DEBUG(x, "mm7:ShortCode", len);
  return len;
}

/* FUNC(zx_LEN_WO_mm7_ShortCode) */

/* Compute length of an element (and its subelements). The XML attributes
 * and elements are processed in wire order and no assumptions
 * are made about namespace prefixes. */

/* Called by: */
int zx_LEN_WO_mm7_ShortCode(struct zx_ctx* c, struct zx_mm7_ShortCode_s* x )
{
  struct zx_ns_s* pop_seen = 0;
  struct zx_elem_s* se MAYBE_UNUSED;
#if 1 /* NORMALMODE */
  int len = 1 + sizeof("ShortCode")-1 + 1 + 2 + sizeof("ShortCode")-1 + 1;
  
  if (x->gg.g.ns && x->gg.g.ns->prefix_len)
    len += (x->gg.g.ns->prefix_len + 1) * 2;
  if (c->inc_ns_len)
    len += zx_len_inc_ns(c, &pop_seen);
  len += zx_len_xmlns_if_not_seen(c, x->gg.g.ns, &pop_seen);

  len += zx_attr_wo_len(x->addressCoding, sizeof("addressCoding")-1);
  len += zx_attr_wo_len(x->displayOnly, sizeof("displayOnly")-1);
  len += zx_attr_wo_len(x->id, sizeof("id")-1);

#else
  /* root node has no begin tag */
  int len = 0;
#endif
  


  len += zx_len_wo_common(c, &x->gg); 
  zx_pop_seen(pop_seen);
  ENC_LEN_DEBUG(x, "mm7:ShortCode", len);
  return len;
}

/* FUNC(zx_ENC_SO_mm7_ShortCode) */

/* Render element into string. The XML attributes and elements are
 * processed in schema order. This is what you generally want for
 * rendering new data structure to a string. The wo pointers are not used. */

/* Called by: */
char* zx_ENC_SO_mm7_ShortCode(struct zx_ctx* c, struct zx_mm7_ShortCode_s* x, char* p )
{
  struct zx_elem_s* se MAYBE_UNUSED;
  struct zx_ns_s* pop_seen = 0;
  ENC_LEN_DEBUG_BASE;
#if 1 /* NORMALMODE */
  /* *** in simple_elem case should output ns prefix from ns node. */
  ZX_OUT_TAG(p, "<mm7:ShortCode");
  if (c->inc_ns)
    p = zx_enc_inc_ns(c, p, &pop_seen);
  p = zx_enc_xmlns_if_not_seen(c, p, zx_ns_tab+zx_xmlns_ix_mm7, &pop_seen);

  p = zx_attr_so_enc(p, x->addressCoding, " addressCoding=\"", sizeof(" addressCoding=\"")-1);
  p = zx_attr_so_enc(p, x->displayOnly, " displayOnly=\"", sizeof(" displayOnly=\"")-1);
  p = zx_attr_so_enc(p, x->id, " id=\"", sizeof(" id=\"")-1);

  p = zx_enc_unknown_attrs(p, x->gg.any_attr);
#else
  /* root node has no begin tag */
#endif
  

  p = zx_enc_so_unknown_elems_and_content(c, p, &x->gg);
  
#if 1 /* NORMALMODE */
  ZX_OUT_CLOSE_TAG(p, "</mm7:ShortCode>");
  zx_pop_seen(pop_seen);
#else
  /* root node has no end tag either */
#endif
  ENC_LEN_DEBUG(x, "mm7:ShortCode", p-enc_base);
  return p;
}

/* FUNC(zx_ENC_WO_mm7_ShortCode) */

/* Render element into string. The XML attributes and elements are
 * processed in wire order by chasing wo pointers. This is what you want for
 * validating signatures on other people's XML documents. */

/* Called by: */
char* zx_ENC_WO_mm7_ShortCode(struct zx_ctx* c, struct zx_mm7_ShortCode_s* x, char* p )
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
  ZX_OUT_MEM(p, "ShortCode", sizeof("ShortCode")-1);
  qq = p;

  /* *** sort the namespaces */
  if (c->inc_ns)
    zx_add_inc_ns(c, &pop_seen);
  zx_add_xmlns_if_not_seen(c, x->gg.g.ns, &pop_seen);

  p = zx_enc_seen(p, pop_seen); 
  p = zx_attr_wo_enc(p, x->addressCoding, "addressCoding=\"", sizeof("addressCoding=\"")-1);
  p = zx_attr_wo_enc(p, x->displayOnly, "displayOnly=\"", sizeof("displayOnly=\"")-1);
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
  ENC_LEN_DEBUG(x, "mm7:ShortCode", p-enc_base);
  return p;
}

/* FUNC(zx_EASY_ENC_SO_mm7_ShortCode) */

/* Called by: */
struct zx_str* zx_EASY_ENC_SO_mm7_ShortCode(struct zx_ctx* c, struct zx_mm7_ShortCode_s* x )
{
  int len;
  char* buf;
  c->ns_tab = ZX_ALLOC(c, sizeof(zx_ns_tab));
  memcpy(c->ns_tab, zx_ns_tab, sizeof(zx_ns_tab));
  len = zx_LEN_SO_mm7_ShortCode(c, x );
  buf = ZX_ALLOC(c, len+1);
  return zx_easy_enc_common(c, zx_ENC_SO_mm7_ShortCode(c, x, buf ), buf, len);
}

/* FUNC(zx_EASY_ENC_WO_mm7_ShortCode) */

/* Called by: */
struct zx_str* zx_EASY_ENC_WO_mm7_ShortCode(struct zx_ctx* c, struct zx_mm7_ShortCode_s* x )
{
  int len;
  char* buf;
  c->ns_tab = ZX_ALLOC(c, sizeof(zx_ns_tab));
  memcpy(c->ns_tab, zx_ns_tab, sizeof(zx_ns_tab));
  len = zx_LEN_WO_mm7_ShortCode(c, x );
  buf = ZX_ALLOC(c, len+1);
  return zx_easy_enc_common(c, zx_ENC_WO_mm7_ShortCode(c, x, buf ), buf, len);
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

#define EL_NAME   mm7_Status
#define EL_STRUCT zx_mm7_Status_s
#define EL_NS     mm7
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

/* FUNC(zx_LEN_SO_mm7_Status) */

/* Compute length of an element (and its subelements). The XML attributes
 * and elements are processed in schema order. */

/* Called by: */
int zx_LEN_SO_mm7_Status(struct zx_ctx* c, struct zx_mm7_Status_s* x )
{
  struct zx_ns_s* pop_seen = 0;
  struct zx_elem_s* se MAYBE_UNUSED;
#if 1 /* NORMALMODE */
  /* *** in simple_elem case should output ns prefix from ns node. */
  int len = sizeof("<mm7:Status")-1 + 1 + sizeof("</mm7:Status>")-1;
  if (c->inc_ns_len)
    len += zx_len_inc_ns(c, &pop_seen);
  len += zx_len_xmlns_if_not_seen(c, zx_ns_tab+zx_xmlns_ix_mm7, &pop_seen);


#else
  /* root node has no begin tag */
  int len = 0;
#endif
  
  for (se = x->StatusCode; se; se = (struct zx_elem_s*)se->g.n)
    len += zx_LEN_SO_simple_elem(c,se, sizeof("mm7:StatusCode")-1, zx_ns_tab+zx_xmlns_ix_mm7);
  for (se = x->StatusText; se; se = (struct zx_elem_s*)se->g.n)
    len += zx_LEN_SO_simple_elem(c,se, sizeof("mm7:StatusText")-1, zx_ns_tab+zx_xmlns_ix_mm7);
  {
      struct zx_mm7_Details_s* e;
      for (e = x->Details; e; e = (struct zx_mm7_Details_s*)e->gg.g.n)
	  len += zx_LEN_SO_mm7_Details(c, e);
  }


  len += zx_len_so_common(c, &x->gg);
  zx_pop_seen(pop_seen);
  ENC_LEN_DEBUG(x, "mm7:Status", len);
  return len;
}

/* FUNC(zx_LEN_WO_mm7_Status) */

/* Compute length of an element (and its subelements). The XML attributes
 * and elements are processed in wire order and no assumptions
 * are made about namespace prefixes. */

/* Called by: */
int zx_LEN_WO_mm7_Status(struct zx_ctx* c, struct zx_mm7_Status_s* x )
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


#else
  /* root node has no begin tag */
  int len = 0;
#endif
  
  for (se = x->StatusCode; se; se = (struct zx_elem_s*)se->g.n)
    len += zx_LEN_WO_simple_elem(c, se, sizeof("StatusCode")-1);
  for (se = x->StatusText; se; se = (struct zx_elem_s*)se->g.n)
    len += zx_LEN_WO_simple_elem(c, se, sizeof("StatusText")-1);
  {
      struct zx_mm7_Details_s* e;
      for (e = x->Details; e; e = (struct zx_mm7_Details_s*)e->gg.g.n)
	  len += zx_LEN_WO_mm7_Details(c, e);
  }


  len += zx_len_wo_common(c, &x->gg); 
  zx_pop_seen(pop_seen);
  ENC_LEN_DEBUG(x, "mm7:Status", len);
  return len;
}

/* FUNC(zx_ENC_SO_mm7_Status) */

/* Render element into string. The XML attributes and elements are
 * processed in schema order. This is what you generally want for
 * rendering new data structure to a string. The wo pointers are not used. */

/* Called by: */
char* zx_ENC_SO_mm7_Status(struct zx_ctx* c, struct zx_mm7_Status_s* x, char* p )
{
  struct zx_elem_s* se MAYBE_UNUSED;
  struct zx_ns_s* pop_seen = 0;
  ENC_LEN_DEBUG_BASE;
#if 1 /* NORMALMODE */
  /* *** in simple_elem case should output ns prefix from ns node. */
  ZX_OUT_TAG(p, "<mm7:Status");
  if (c->inc_ns)
    p = zx_enc_inc_ns(c, p, &pop_seen);
  p = zx_enc_xmlns_if_not_seen(c, p, zx_ns_tab+zx_xmlns_ix_mm7, &pop_seen);


  p = zx_enc_unknown_attrs(p, x->gg.any_attr);
#else
  /* root node has no begin tag */
#endif
  
  for (se = x->StatusCode; se; se = (struct zx_elem_s*)se->g.n)
    p = zx_ENC_SO_simple_elem(c, se, p, "mm7:StatusCode", sizeof("mm7:StatusCode")-1, zx_ns_tab+zx_xmlns_ix_mm7);
  for (se = x->StatusText; se; se = (struct zx_elem_s*)se->g.n)
    p = zx_ENC_SO_simple_elem(c, se, p, "mm7:StatusText", sizeof("mm7:StatusText")-1, zx_ns_tab+zx_xmlns_ix_mm7);
  {
      struct zx_mm7_Details_s* e;
      for (e = x->Details; e; e = (struct zx_mm7_Details_s*)e->gg.g.n)
	  p = zx_ENC_SO_mm7_Details(c, e, p);
  }

  p = zx_enc_so_unknown_elems_and_content(c, p, &x->gg);
  
#if 1 /* NORMALMODE */
  ZX_OUT_CLOSE_TAG(p, "</mm7:Status>");
  zx_pop_seen(pop_seen);
#else
  /* root node has no end tag either */
#endif
  ENC_LEN_DEBUG(x, "mm7:Status", p-enc_base);
  return p;
}

/* FUNC(zx_ENC_WO_mm7_Status) */

/* Render element into string. The XML attributes and elements are
 * processed in wire order by chasing wo pointers. This is what you want for
 * validating signatures on other people's XML documents. */

/* Called by: */
char* zx_ENC_WO_mm7_Status(struct zx_ctx* c, struct zx_mm7_Status_s* x, char* p )
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
  ZX_OUT_MEM(p, "Status", sizeof("Status")-1);
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
  ENC_LEN_DEBUG(x, "mm7:Status", p-enc_base);
  return p;
}

/* FUNC(zx_EASY_ENC_SO_mm7_Status) */

/* Called by: */
struct zx_str* zx_EASY_ENC_SO_mm7_Status(struct zx_ctx* c, struct zx_mm7_Status_s* x )
{
  int len;
  char* buf;
  c->ns_tab = ZX_ALLOC(c, sizeof(zx_ns_tab));
  memcpy(c->ns_tab, zx_ns_tab, sizeof(zx_ns_tab));
  len = zx_LEN_SO_mm7_Status(c, x );
  buf = ZX_ALLOC(c, len+1);
  return zx_easy_enc_common(c, zx_ENC_SO_mm7_Status(c, x, buf ), buf, len);
}

/* FUNC(zx_EASY_ENC_WO_mm7_Status) */

/* Called by: */
struct zx_str* zx_EASY_ENC_WO_mm7_Status(struct zx_ctx* c, struct zx_mm7_Status_s* x )
{
  int len;
  char* buf;
  c->ns_tab = ZX_ALLOC(c, sizeof(zx_ns_tab));
  memcpy(c->ns_tab, zx_ns_tab, sizeof(zx_ns_tab));
  len = zx_LEN_WO_mm7_Status(c, x );
  buf = ZX_ALLOC(c, len+1);
  return zx_easy_enc_common(c, zx_ENC_WO_mm7_Status(c, x, buf ), buf, len);
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

#define EL_NAME   mm7_SubmitReq
#define EL_STRUCT zx_mm7_SubmitReq_s
#define EL_NS     mm7
#define EL_TAG    SubmitReq

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

/* FUNC(zx_LEN_SO_mm7_SubmitReq) */

/* Compute length of an element (and its subelements). The XML attributes
 * and elements are processed in schema order. */

/* Called by: */
int zx_LEN_SO_mm7_SubmitReq(struct zx_ctx* c, struct zx_mm7_SubmitReq_s* x )
{
  struct zx_ns_s* pop_seen = 0;
  struct zx_elem_s* se MAYBE_UNUSED;
#if 1 /* NORMALMODE */
  /* *** in simple_elem case should output ns prefix from ns node. */
  int len = sizeof("<mm7:SubmitReq")-1 + 1 + sizeof("</mm7:SubmitReq>")-1;
  if (c->inc_ns_len)
    len += zx_len_inc_ns(c, &pop_seen);
  len += zx_len_xmlns_if_not_seen(c, zx_ns_tab+zx_xmlns_ix_mm7, &pop_seen);


#else
  /* root node has no begin tag */
  int len = 0;
#endif
  
  for (se = x->MM7Version; se; se = (struct zx_elem_s*)se->g.n)
    len += zx_LEN_SO_simple_elem(c,se, sizeof("mm7:MM7Version")-1, zx_ns_tab+zx_xmlns_ix_mm7);
  {
      struct zx_mm7_SenderIdentification_s* e;
      for (e = x->SenderIdentification; e; e = (struct zx_mm7_SenderIdentification_s*)e->gg.g.n)
	  len += zx_LEN_SO_mm7_SenderIdentification(c, e);
  }
  {
      struct zx_mm7_Extension_s* e;
      for (e = x->Extension; e; e = (struct zx_mm7_Extension_s*)e->gg.g.n)
	  len += zx_LEN_SO_mm7_Extension(c, e);
  }
  {
      struct zx_mm7_Recipients_s* e;
      for (e = x->Recipients; e; e = (struct zx_mm7_Recipients_s*)e->gg.g.n)
	  len += zx_LEN_SO_mm7_Recipients(c, e);
  }
  {
      struct zx_mm7_PreferredChannels_s* e;
      for (e = x->PreferredChannels; e; e = (struct zx_mm7_PreferredChannels_s*)e->gg.g.n)
	  len += zx_LEN_SO_mm7_PreferredChannels(c, e);
  }
  {
      struct zx_mm7_ServiceCode_s* e;
      for (e = x->ServiceCode; e; e = (struct zx_mm7_ServiceCode_s*)e->gg.g.n)
	  len += zx_LEN_SO_mm7_ServiceCode(c, e);
  }
  for (se = x->LinkedID; se; se = (struct zx_elem_s*)se->g.n)
    len += zx_LEN_SO_simple_elem(c,se, sizeof("mm7:LinkedID")-1, zx_ns_tab+zx_xmlns_ix_mm7);
  for (se = x->MessageClass; se; se = (struct zx_elem_s*)se->g.n)
    len += zx_LEN_SO_simple_elem(c,se, sizeof("mm7:MessageClass")-1, zx_ns_tab+zx_xmlns_ix_mm7);
  for (se = x->TimeStamp; se; se = (struct zx_elem_s*)se->g.n)
    len += zx_LEN_SO_simple_elem(c,se, sizeof("mm7:TimeStamp")-1, zx_ns_tab+zx_xmlns_ix_mm7);
  {
      struct zx_mm7_ReplyCharging_s* e;
      for (e = x->ReplyCharging; e; e = (struct zx_mm7_ReplyCharging_s*)e->gg.g.n)
	  len += zx_LEN_SO_mm7_ReplyCharging(c, e);
  }
  for (se = x->EarliestDeliveryTime; se; se = (struct zx_elem_s*)se->g.n)
    len += zx_LEN_SO_simple_elem(c,se, sizeof("mm7:EarliestDeliveryTime")-1, zx_ns_tab+zx_xmlns_ix_mm7);
  for (se = x->ExpiryDate; se; se = (struct zx_elem_s*)se->g.n)
    len += zx_LEN_SO_simple_elem(c,se, sizeof("mm7:ExpiryDate")-1, zx_ns_tab+zx_xmlns_ix_mm7);
  for (se = x->DeliveryReport; se; se = (struct zx_elem_s*)se->g.n)
    len += zx_LEN_SO_simple_elem(c,se, sizeof("mm7:DeliveryReport")-1, zx_ns_tab+zx_xmlns_ix_mm7);
  for (se = x->ReadReply; se; se = (struct zx_elem_s*)se->g.n)
    len += zx_LEN_SO_simple_elem(c,se, sizeof("mm7:ReadReply")-1, zx_ns_tab+zx_xmlns_ix_mm7);
  for (se = x->Priority; se; se = (struct zx_elem_s*)se->g.n)
    len += zx_LEN_SO_simple_elem(c,se, sizeof("mm7:Priority")-1, zx_ns_tab+zx_xmlns_ix_mm7);
  for (se = x->Subject; se; se = (struct zx_elem_s*)se->g.n)
    len += zx_LEN_SO_simple_elem(c,se, sizeof("mm7:Subject")-1, zx_ns_tab+zx_xmlns_ix_mm7);
  for (se = x->ChargedParty; se; se = (struct zx_elem_s*)se->g.n)
    len += zx_LEN_SO_simple_elem(c,se, sizeof("mm7:ChargedParty")-1, zx_ns_tab+zx_xmlns_ix_mm7);
  for (se = x->ChargedPartyID; se; se = (struct zx_elem_s*)se->g.n)
    len += zx_LEN_SO_simple_elem(c,se, sizeof("mm7:ChargedPartyID")-1, zx_ns_tab+zx_xmlns_ix_mm7);
  {
      struct zx_mm7_ThirdPartyPayer_s* e;
      for (e = x->ThirdPartyPayer; e; e = (struct zx_mm7_ThirdPartyPayer_s*)e->gg.g.n)
	  len += zx_LEN_SO_mm7_ThirdPartyPayer(c, e);
  }
  for (se = x->DistributionIndicator; se; se = (struct zx_elem_s*)se->g.n)
    len += zx_LEN_SO_simple_elem(c,se, sizeof("mm7:DistributionIndicator")-1, zx_ns_tab+zx_xmlns_ix_mm7);
  {
      struct zx_mm7_DeliveryCondition_s* e;
      for (e = x->DeliveryCondition; e; e = (struct zx_mm7_DeliveryCondition_s*)e->gg.g.n)
	  len += zx_LEN_SO_mm7_DeliveryCondition(c, e);
  }
  for (se = x->ApplicID; se; se = (struct zx_elem_s*)se->g.n)
    len += zx_LEN_SO_simple_elem(c,se, sizeof("mm7:ApplicID")-1, zx_ns_tab+zx_xmlns_ix_mm7);
  for (se = x->ReplyApplicID; se; se = (struct zx_elem_s*)se->g.n)
    len += zx_LEN_SO_simple_elem(c,se, sizeof("mm7:ReplyApplicID")-1, zx_ns_tab+zx_xmlns_ix_mm7);
  for (se = x->AuxApplicInfo; se; se = (struct zx_elem_s*)se->g.n)
    len += zx_LEN_SO_simple_elem(c,se, sizeof("mm7:AuxApplicInfo")-1, zx_ns_tab+zx_xmlns_ix_mm7);
  for (se = x->ContentClass; se; se = (struct zx_elem_s*)se->g.n)
    len += zx_LEN_SO_simple_elem(c,se, sizeof("mm7:ContentClass")-1, zx_ns_tab+zx_xmlns_ix_mm7);
  for (se = x->DRMContent; se; se = (struct zx_elem_s*)se->g.n)
    len += zx_LEN_SO_simple_elem(c,se, sizeof("mm7:DRMContent")-1, zx_ns_tab+zx_xmlns_ix_mm7);
  {
      struct zx_mm7_Content_s* e;
      for (e = x->Content; e; e = (struct zx_mm7_Content_s*)e->gg.g.n)
	  len += zx_LEN_SO_mm7_Content(c, e);
  }
  {
      struct zx_mm7_AdditionalInformation_s* e;
      for (e = x->AdditionalInformation; e; e = (struct zx_mm7_AdditionalInformation_s*)e->gg.g.n)
	  len += zx_LEN_SO_mm7_AdditionalInformation(c, e);
  }
  {
      struct zx_mm7_MessageExtraData_s* e;
      for (e = x->MessageExtraData; e; e = (struct zx_mm7_MessageExtraData_s*)e->gg.g.n)
	  len += zx_LEN_SO_mm7_MessageExtraData(c, e);
  }


  len += zx_len_so_common(c, &x->gg);
  zx_pop_seen(pop_seen);
  ENC_LEN_DEBUG(x, "mm7:SubmitReq", len);
  return len;
}

/* FUNC(zx_LEN_WO_mm7_SubmitReq) */

/* Compute length of an element (and its subelements). The XML attributes
 * and elements are processed in wire order and no assumptions
 * are made about namespace prefixes. */

/* Called by: */
int zx_LEN_WO_mm7_SubmitReq(struct zx_ctx* c, struct zx_mm7_SubmitReq_s* x )
{
  struct zx_ns_s* pop_seen = 0;
  struct zx_elem_s* se MAYBE_UNUSED;
#if 1 /* NORMALMODE */
  int len = 1 + sizeof("SubmitReq")-1 + 1 + 2 + sizeof("SubmitReq")-1 + 1;
  
  if (x->gg.g.ns && x->gg.g.ns->prefix_len)
    len += (x->gg.g.ns->prefix_len + 1) * 2;
  if (c->inc_ns_len)
    len += zx_len_inc_ns(c, &pop_seen);
  len += zx_len_xmlns_if_not_seen(c, x->gg.g.ns, &pop_seen);


#else
  /* root node has no begin tag */
  int len = 0;
#endif
  
  for (se = x->MM7Version; se; se = (struct zx_elem_s*)se->g.n)
    len += zx_LEN_WO_simple_elem(c, se, sizeof("MM7Version")-1);
  {
      struct zx_mm7_SenderIdentification_s* e;
      for (e = x->SenderIdentification; e; e = (struct zx_mm7_SenderIdentification_s*)e->gg.g.n)
	  len += zx_LEN_WO_mm7_SenderIdentification(c, e);
  }
  {
      struct zx_mm7_Extension_s* e;
      for (e = x->Extension; e; e = (struct zx_mm7_Extension_s*)e->gg.g.n)
	  len += zx_LEN_WO_mm7_Extension(c, e);
  }
  {
      struct zx_mm7_Recipients_s* e;
      for (e = x->Recipients; e; e = (struct zx_mm7_Recipients_s*)e->gg.g.n)
	  len += zx_LEN_WO_mm7_Recipients(c, e);
  }
  {
      struct zx_mm7_PreferredChannels_s* e;
      for (e = x->PreferredChannels; e; e = (struct zx_mm7_PreferredChannels_s*)e->gg.g.n)
	  len += zx_LEN_WO_mm7_PreferredChannels(c, e);
  }
  {
      struct zx_mm7_ServiceCode_s* e;
      for (e = x->ServiceCode; e; e = (struct zx_mm7_ServiceCode_s*)e->gg.g.n)
	  len += zx_LEN_WO_mm7_ServiceCode(c, e);
  }
  for (se = x->LinkedID; se; se = (struct zx_elem_s*)se->g.n)
    len += zx_LEN_WO_simple_elem(c, se, sizeof("LinkedID")-1);
  for (se = x->MessageClass; se; se = (struct zx_elem_s*)se->g.n)
    len += zx_LEN_WO_simple_elem(c, se, sizeof("MessageClass")-1);
  for (se = x->TimeStamp; se; se = (struct zx_elem_s*)se->g.n)
    len += zx_LEN_WO_simple_elem(c, se, sizeof("TimeStamp")-1);
  {
      struct zx_mm7_ReplyCharging_s* e;
      for (e = x->ReplyCharging; e; e = (struct zx_mm7_ReplyCharging_s*)e->gg.g.n)
	  len += zx_LEN_WO_mm7_ReplyCharging(c, e);
  }
  for (se = x->EarliestDeliveryTime; se; se = (struct zx_elem_s*)se->g.n)
    len += zx_LEN_WO_simple_elem(c, se, sizeof("EarliestDeliveryTime")-1);
  for (se = x->ExpiryDate; se; se = (struct zx_elem_s*)se->g.n)
    len += zx_LEN_WO_simple_elem(c, se, sizeof("ExpiryDate")-1);
  for (se = x->DeliveryReport; se; se = (struct zx_elem_s*)se->g.n)
    len += zx_LEN_WO_simple_elem(c, se, sizeof("DeliveryReport")-1);
  for (se = x->ReadReply; se; se = (struct zx_elem_s*)se->g.n)
    len += zx_LEN_WO_simple_elem(c, se, sizeof("ReadReply")-1);
  for (se = x->Priority; se; se = (struct zx_elem_s*)se->g.n)
    len += zx_LEN_WO_simple_elem(c, se, sizeof("Priority")-1);
  for (se = x->Subject; se; se = (struct zx_elem_s*)se->g.n)
    len += zx_LEN_WO_simple_elem(c, se, sizeof("Subject")-1);
  for (se = x->ChargedParty; se; se = (struct zx_elem_s*)se->g.n)
    len += zx_LEN_WO_simple_elem(c, se, sizeof("ChargedParty")-1);
  for (se = x->ChargedPartyID; se; se = (struct zx_elem_s*)se->g.n)
    len += zx_LEN_WO_simple_elem(c, se, sizeof("ChargedPartyID")-1);
  {
      struct zx_mm7_ThirdPartyPayer_s* e;
      for (e = x->ThirdPartyPayer; e; e = (struct zx_mm7_ThirdPartyPayer_s*)e->gg.g.n)
	  len += zx_LEN_WO_mm7_ThirdPartyPayer(c, e);
  }
  for (se = x->DistributionIndicator; se; se = (struct zx_elem_s*)se->g.n)
    len += zx_LEN_WO_simple_elem(c, se, sizeof("DistributionIndicator")-1);
  {
      struct zx_mm7_DeliveryCondition_s* e;
      for (e = x->DeliveryCondition; e; e = (struct zx_mm7_DeliveryCondition_s*)e->gg.g.n)
	  len += zx_LEN_WO_mm7_DeliveryCondition(c, e);
  }
  for (se = x->ApplicID; se; se = (struct zx_elem_s*)se->g.n)
    len += zx_LEN_WO_simple_elem(c, se, sizeof("ApplicID")-1);
  for (se = x->ReplyApplicID; se; se = (struct zx_elem_s*)se->g.n)
    len += zx_LEN_WO_simple_elem(c, se, sizeof("ReplyApplicID")-1);
  for (se = x->AuxApplicInfo; se; se = (struct zx_elem_s*)se->g.n)
    len += zx_LEN_WO_simple_elem(c, se, sizeof("AuxApplicInfo")-1);
  for (se = x->ContentClass; se; se = (struct zx_elem_s*)se->g.n)
    len += zx_LEN_WO_simple_elem(c, se, sizeof("ContentClass")-1);
  for (se = x->DRMContent; se; se = (struct zx_elem_s*)se->g.n)
    len += zx_LEN_WO_simple_elem(c, se, sizeof("DRMContent")-1);
  {
      struct zx_mm7_Content_s* e;
      for (e = x->Content; e; e = (struct zx_mm7_Content_s*)e->gg.g.n)
	  len += zx_LEN_WO_mm7_Content(c, e);
  }
  {
      struct zx_mm7_AdditionalInformation_s* e;
      for (e = x->AdditionalInformation; e; e = (struct zx_mm7_AdditionalInformation_s*)e->gg.g.n)
	  len += zx_LEN_WO_mm7_AdditionalInformation(c, e);
  }
  {
      struct zx_mm7_MessageExtraData_s* e;
      for (e = x->MessageExtraData; e; e = (struct zx_mm7_MessageExtraData_s*)e->gg.g.n)
	  len += zx_LEN_WO_mm7_MessageExtraData(c, e);
  }


  len += zx_len_wo_common(c, &x->gg); 
  zx_pop_seen(pop_seen);
  ENC_LEN_DEBUG(x, "mm7:SubmitReq", len);
  return len;
}

/* FUNC(zx_ENC_SO_mm7_SubmitReq) */

/* Render element into string. The XML attributes and elements are
 * processed in schema order. This is what you generally want for
 * rendering new data structure to a string. The wo pointers are not used. */

/* Called by: */
char* zx_ENC_SO_mm7_SubmitReq(struct zx_ctx* c, struct zx_mm7_SubmitReq_s* x, char* p )
{
  struct zx_elem_s* se MAYBE_UNUSED;
  struct zx_ns_s* pop_seen = 0;
  ENC_LEN_DEBUG_BASE;
#if 1 /* NORMALMODE */
  /* *** in simple_elem case should output ns prefix from ns node. */
  ZX_OUT_TAG(p, "<mm7:SubmitReq");
  if (c->inc_ns)
    p = zx_enc_inc_ns(c, p, &pop_seen);
  p = zx_enc_xmlns_if_not_seen(c, p, zx_ns_tab+zx_xmlns_ix_mm7, &pop_seen);


  p = zx_enc_unknown_attrs(p, x->gg.any_attr);
#else
  /* root node has no begin tag */
#endif
  
  for (se = x->MM7Version; se; se = (struct zx_elem_s*)se->g.n)
    p = zx_ENC_SO_simple_elem(c, se, p, "mm7:MM7Version", sizeof("mm7:MM7Version")-1, zx_ns_tab+zx_xmlns_ix_mm7);
  {
      struct zx_mm7_SenderIdentification_s* e;
      for (e = x->SenderIdentification; e; e = (struct zx_mm7_SenderIdentification_s*)e->gg.g.n)
	  p = zx_ENC_SO_mm7_SenderIdentification(c, e, p);
  }
  {
      struct zx_mm7_Extension_s* e;
      for (e = x->Extension; e; e = (struct zx_mm7_Extension_s*)e->gg.g.n)
	  p = zx_ENC_SO_mm7_Extension(c, e, p);
  }
  {
      struct zx_mm7_Recipients_s* e;
      for (e = x->Recipients; e; e = (struct zx_mm7_Recipients_s*)e->gg.g.n)
	  p = zx_ENC_SO_mm7_Recipients(c, e, p);
  }
  {
      struct zx_mm7_PreferredChannels_s* e;
      for (e = x->PreferredChannels; e; e = (struct zx_mm7_PreferredChannels_s*)e->gg.g.n)
	  p = zx_ENC_SO_mm7_PreferredChannels(c, e, p);
  }
  {
      struct zx_mm7_ServiceCode_s* e;
      for (e = x->ServiceCode; e; e = (struct zx_mm7_ServiceCode_s*)e->gg.g.n)
	  p = zx_ENC_SO_mm7_ServiceCode(c, e, p);
  }
  for (se = x->LinkedID; se; se = (struct zx_elem_s*)se->g.n)
    p = zx_ENC_SO_simple_elem(c, se, p, "mm7:LinkedID", sizeof("mm7:LinkedID")-1, zx_ns_tab+zx_xmlns_ix_mm7);
  for (se = x->MessageClass; se; se = (struct zx_elem_s*)se->g.n)
    p = zx_ENC_SO_simple_elem(c, se, p, "mm7:MessageClass", sizeof("mm7:MessageClass")-1, zx_ns_tab+zx_xmlns_ix_mm7);
  for (se = x->TimeStamp; se; se = (struct zx_elem_s*)se->g.n)
    p = zx_ENC_SO_simple_elem(c, se, p, "mm7:TimeStamp", sizeof("mm7:TimeStamp")-1, zx_ns_tab+zx_xmlns_ix_mm7);
  {
      struct zx_mm7_ReplyCharging_s* e;
      for (e = x->ReplyCharging; e; e = (struct zx_mm7_ReplyCharging_s*)e->gg.g.n)
	  p = zx_ENC_SO_mm7_ReplyCharging(c, e, p);
  }
  for (se = x->EarliestDeliveryTime; se; se = (struct zx_elem_s*)se->g.n)
    p = zx_ENC_SO_simple_elem(c, se, p, "mm7:EarliestDeliveryTime", sizeof("mm7:EarliestDeliveryTime")-1, zx_ns_tab+zx_xmlns_ix_mm7);
  for (se = x->ExpiryDate; se; se = (struct zx_elem_s*)se->g.n)
    p = zx_ENC_SO_simple_elem(c, se, p, "mm7:ExpiryDate", sizeof("mm7:ExpiryDate")-1, zx_ns_tab+zx_xmlns_ix_mm7);
  for (se = x->DeliveryReport; se; se = (struct zx_elem_s*)se->g.n)
    p = zx_ENC_SO_simple_elem(c, se, p, "mm7:DeliveryReport", sizeof("mm7:DeliveryReport")-1, zx_ns_tab+zx_xmlns_ix_mm7);
  for (se = x->ReadReply; se; se = (struct zx_elem_s*)se->g.n)
    p = zx_ENC_SO_simple_elem(c, se, p, "mm7:ReadReply", sizeof("mm7:ReadReply")-1, zx_ns_tab+zx_xmlns_ix_mm7);
  for (se = x->Priority; se; se = (struct zx_elem_s*)se->g.n)
    p = zx_ENC_SO_simple_elem(c, se, p, "mm7:Priority", sizeof("mm7:Priority")-1, zx_ns_tab+zx_xmlns_ix_mm7);
  for (se = x->Subject; se; se = (struct zx_elem_s*)se->g.n)
    p = zx_ENC_SO_simple_elem(c, se, p, "mm7:Subject", sizeof("mm7:Subject")-1, zx_ns_tab+zx_xmlns_ix_mm7);
  for (se = x->ChargedParty; se; se = (struct zx_elem_s*)se->g.n)
    p = zx_ENC_SO_simple_elem(c, se, p, "mm7:ChargedParty", sizeof("mm7:ChargedParty")-1, zx_ns_tab+zx_xmlns_ix_mm7);
  for (se = x->ChargedPartyID; se; se = (struct zx_elem_s*)se->g.n)
    p = zx_ENC_SO_simple_elem(c, se, p, "mm7:ChargedPartyID", sizeof("mm7:ChargedPartyID")-1, zx_ns_tab+zx_xmlns_ix_mm7);
  {
      struct zx_mm7_ThirdPartyPayer_s* e;
      for (e = x->ThirdPartyPayer; e; e = (struct zx_mm7_ThirdPartyPayer_s*)e->gg.g.n)
	  p = zx_ENC_SO_mm7_ThirdPartyPayer(c, e, p);
  }
  for (se = x->DistributionIndicator; se; se = (struct zx_elem_s*)se->g.n)
    p = zx_ENC_SO_simple_elem(c, se, p, "mm7:DistributionIndicator", sizeof("mm7:DistributionIndicator")-1, zx_ns_tab+zx_xmlns_ix_mm7);
  {
      struct zx_mm7_DeliveryCondition_s* e;
      for (e = x->DeliveryCondition; e; e = (struct zx_mm7_DeliveryCondition_s*)e->gg.g.n)
	  p = zx_ENC_SO_mm7_DeliveryCondition(c, e, p);
  }
  for (se = x->ApplicID; se; se = (struct zx_elem_s*)se->g.n)
    p = zx_ENC_SO_simple_elem(c, se, p, "mm7:ApplicID", sizeof("mm7:ApplicID")-1, zx_ns_tab+zx_xmlns_ix_mm7);
  for (se = x->ReplyApplicID; se; se = (struct zx_elem_s*)se->g.n)
    p = zx_ENC_SO_simple_elem(c, se, p, "mm7:ReplyApplicID", sizeof("mm7:ReplyApplicID")-1, zx_ns_tab+zx_xmlns_ix_mm7);
  for (se = x->AuxApplicInfo; se; se = (struct zx_elem_s*)se->g.n)
    p = zx_ENC_SO_simple_elem(c, se, p, "mm7:AuxApplicInfo", sizeof("mm7:AuxApplicInfo")-1, zx_ns_tab+zx_xmlns_ix_mm7);
  for (se = x->ContentClass; se; se = (struct zx_elem_s*)se->g.n)
    p = zx_ENC_SO_simple_elem(c, se, p, "mm7:ContentClass", sizeof("mm7:ContentClass")-1, zx_ns_tab+zx_xmlns_ix_mm7);
  for (se = x->DRMContent; se; se = (struct zx_elem_s*)se->g.n)
    p = zx_ENC_SO_simple_elem(c, se, p, "mm7:DRMContent", sizeof("mm7:DRMContent")-1, zx_ns_tab+zx_xmlns_ix_mm7);
  {
      struct zx_mm7_Content_s* e;
      for (e = x->Content; e; e = (struct zx_mm7_Content_s*)e->gg.g.n)
	  p = zx_ENC_SO_mm7_Content(c, e, p);
  }
  {
      struct zx_mm7_AdditionalInformation_s* e;
      for (e = x->AdditionalInformation; e; e = (struct zx_mm7_AdditionalInformation_s*)e->gg.g.n)
	  p = zx_ENC_SO_mm7_AdditionalInformation(c, e, p);
  }
  {
      struct zx_mm7_MessageExtraData_s* e;
      for (e = x->MessageExtraData; e; e = (struct zx_mm7_MessageExtraData_s*)e->gg.g.n)
	  p = zx_ENC_SO_mm7_MessageExtraData(c, e, p);
  }

  p = zx_enc_so_unknown_elems_and_content(c, p, &x->gg);
  
#if 1 /* NORMALMODE */
  ZX_OUT_CLOSE_TAG(p, "</mm7:SubmitReq>");
  zx_pop_seen(pop_seen);
#else
  /* root node has no end tag either */
#endif
  ENC_LEN_DEBUG(x, "mm7:SubmitReq", p-enc_base);
  return p;
}

/* FUNC(zx_ENC_WO_mm7_SubmitReq) */

/* Render element into string. The XML attributes and elements are
 * processed in wire order by chasing wo pointers. This is what you want for
 * validating signatures on other people's XML documents. */

/* Called by: */
char* zx_ENC_WO_mm7_SubmitReq(struct zx_ctx* c, struct zx_mm7_SubmitReq_s* x, char* p )
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
  ZX_OUT_MEM(p, "SubmitReq", sizeof("SubmitReq")-1);
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
  ENC_LEN_DEBUG(x, "mm7:SubmitReq", p-enc_base);
  return p;
}

/* FUNC(zx_EASY_ENC_SO_mm7_SubmitReq) */

/* Called by: */
struct zx_str* zx_EASY_ENC_SO_mm7_SubmitReq(struct zx_ctx* c, struct zx_mm7_SubmitReq_s* x )
{
  int len;
  char* buf;
  c->ns_tab = ZX_ALLOC(c, sizeof(zx_ns_tab));
  memcpy(c->ns_tab, zx_ns_tab, sizeof(zx_ns_tab));
  len = zx_LEN_SO_mm7_SubmitReq(c, x );
  buf = ZX_ALLOC(c, len+1);
  return zx_easy_enc_common(c, zx_ENC_SO_mm7_SubmitReq(c, x, buf ), buf, len);
}

/* FUNC(zx_EASY_ENC_WO_mm7_SubmitReq) */

/* Called by: */
struct zx_str* zx_EASY_ENC_WO_mm7_SubmitReq(struct zx_ctx* c, struct zx_mm7_SubmitReq_s* x )
{
  int len;
  char* buf;
  c->ns_tab = ZX_ALLOC(c, sizeof(zx_ns_tab));
  memcpy(c->ns_tab, zx_ns_tab, sizeof(zx_ns_tab));
  len = zx_LEN_WO_mm7_SubmitReq(c, x );
  buf = ZX_ALLOC(c, len+1);
  return zx_easy_enc_common(c, zx_ENC_WO_mm7_SubmitReq(c, x, buf ), buf, len);
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

#define EL_NAME   mm7_SubmitRsp
#define EL_STRUCT zx_mm7_SubmitRsp_s
#define EL_NS     mm7
#define EL_TAG    SubmitRsp

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

/* FUNC(zx_LEN_SO_mm7_SubmitRsp) */

/* Compute length of an element (and its subelements). The XML attributes
 * and elements are processed in schema order. */

/* Called by: */
int zx_LEN_SO_mm7_SubmitRsp(struct zx_ctx* c, struct zx_mm7_SubmitRsp_s* x )
{
  struct zx_ns_s* pop_seen = 0;
  struct zx_elem_s* se MAYBE_UNUSED;
#if 1 /* NORMALMODE */
  /* *** in simple_elem case should output ns prefix from ns node. */
  int len = sizeof("<mm7:SubmitRsp")-1 + 1 + sizeof("</mm7:SubmitRsp>")-1;
  if (c->inc_ns_len)
    len += zx_len_inc_ns(c, &pop_seen);
  len += zx_len_xmlns_if_not_seen(c, zx_ns_tab+zx_xmlns_ix_mm7, &pop_seen);


#else
  /* root node has no begin tag */
  int len = 0;
#endif
  
  for (se = x->MM7Version; se; se = (struct zx_elem_s*)se->g.n)
    len += zx_LEN_SO_simple_elem(c,se, sizeof("mm7:MM7Version")-1, zx_ns_tab+zx_xmlns_ix_mm7);
  {
      struct zx_mm7_Status_s* e;
      for (e = x->Status; e; e = (struct zx_mm7_Status_s*)e->gg.g.n)
	  len += zx_LEN_SO_mm7_Status(c, e);
  }
  {
      struct zx_mm7_Extension_s* e;
      for (e = x->Extension; e; e = (struct zx_mm7_Extension_s*)e->gg.g.n)
	  len += zx_LEN_SO_mm7_Extension(c, e);
  }
  for (se = x->MessageID; se; se = (struct zx_elem_s*)se->g.n)
    len += zx_LEN_SO_simple_elem(c,se, sizeof("mm7:MessageID")-1, zx_ns_tab+zx_xmlns_ix_mm7);


  len += zx_len_so_common(c, &x->gg);
  zx_pop_seen(pop_seen);
  ENC_LEN_DEBUG(x, "mm7:SubmitRsp", len);
  return len;
}

/* FUNC(zx_LEN_WO_mm7_SubmitRsp) */

/* Compute length of an element (and its subelements). The XML attributes
 * and elements are processed in wire order and no assumptions
 * are made about namespace prefixes. */

/* Called by: */
int zx_LEN_WO_mm7_SubmitRsp(struct zx_ctx* c, struct zx_mm7_SubmitRsp_s* x )
{
  struct zx_ns_s* pop_seen = 0;
  struct zx_elem_s* se MAYBE_UNUSED;
#if 1 /* NORMALMODE */
  int len = 1 + sizeof("SubmitRsp")-1 + 1 + 2 + sizeof("SubmitRsp")-1 + 1;
  
  if (x->gg.g.ns && x->gg.g.ns->prefix_len)
    len += (x->gg.g.ns->prefix_len + 1) * 2;
  if (c->inc_ns_len)
    len += zx_len_inc_ns(c, &pop_seen);
  len += zx_len_xmlns_if_not_seen(c, x->gg.g.ns, &pop_seen);


#else
  /* root node has no begin tag */
  int len = 0;
#endif
  
  for (se = x->MM7Version; se; se = (struct zx_elem_s*)se->g.n)
    len += zx_LEN_WO_simple_elem(c, se, sizeof("MM7Version")-1);
  {
      struct zx_mm7_Status_s* e;
      for (e = x->Status; e; e = (struct zx_mm7_Status_s*)e->gg.g.n)
	  len += zx_LEN_WO_mm7_Status(c, e);
  }
  {
      struct zx_mm7_Extension_s* e;
      for (e = x->Extension; e; e = (struct zx_mm7_Extension_s*)e->gg.g.n)
	  len += zx_LEN_WO_mm7_Extension(c, e);
  }
  for (se = x->MessageID; se; se = (struct zx_elem_s*)se->g.n)
    len += zx_LEN_WO_simple_elem(c, se, sizeof("MessageID")-1);


  len += zx_len_wo_common(c, &x->gg); 
  zx_pop_seen(pop_seen);
  ENC_LEN_DEBUG(x, "mm7:SubmitRsp", len);
  return len;
}

/* FUNC(zx_ENC_SO_mm7_SubmitRsp) */

/* Render element into string. The XML attributes and elements are
 * processed in schema order. This is what you generally want for
 * rendering new data structure to a string. The wo pointers are not used. */

/* Called by: */
char* zx_ENC_SO_mm7_SubmitRsp(struct zx_ctx* c, struct zx_mm7_SubmitRsp_s* x, char* p )
{
  struct zx_elem_s* se MAYBE_UNUSED;
  struct zx_ns_s* pop_seen = 0;
  ENC_LEN_DEBUG_BASE;
#if 1 /* NORMALMODE */
  /* *** in simple_elem case should output ns prefix from ns node. */
  ZX_OUT_TAG(p, "<mm7:SubmitRsp");
  if (c->inc_ns)
    p = zx_enc_inc_ns(c, p, &pop_seen);
  p = zx_enc_xmlns_if_not_seen(c, p, zx_ns_tab+zx_xmlns_ix_mm7, &pop_seen);


  p = zx_enc_unknown_attrs(p, x->gg.any_attr);
#else
  /* root node has no begin tag */
#endif
  
  for (se = x->MM7Version; se; se = (struct zx_elem_s*)se->g.n)
    p = zx_ENC_SO_simple_elem(c, se, p, "mm7:MM7Version", sizeof("mm7:MM7Version")-1, zx_ns_tab+zx_xmlns_ix_mm7);
  {
      struct zx_mm7_Status_s* e;
      for (e = x->Status; e; e = (struct zx_mm7_Status_s*)e->gg.g.n)
	  p = zx_ENC_SO_mm7_Status(c, e, p);
  }
  {
      struct zx_mm7_Extension_s* e;
      for (e = x->Extension; e; e = (struct zx_mm7_Extension_s*)e->gg.g.n)
	  p = zx_ENC_SO_mm7_Extension(c, e, p);
  }
  for (se = x->MessageID; se; se = (struct zx_elem_s*)se->g.n)
    p = zx_ENC_SO_simple_elem(c, se, p, "mm7:MessageID", sizeof("mm7:MessageID")-1, zx_ns_tab+zx_xmlns_ix_mm7);

  p = zx_enc_so_unknown_elems_and_content(c, p, &x->gg);
  
#if 1 /* NORMALMODE */
  ZX_OUT_CLOSE_TAG(p, "</mm7:SubmitRsp>");
  zx_pop_seen(pop_seen);
#else
  /* root node has no end tag either */
#endif
  ENC_LEN_DEBUG(x, "mm7:SubmitRsp", p-enc_base);
  return p;
}

/* FUNC(zx_ENC_WO_mm7_SubmitRsp) */

/* Render element into string. The XML attributes and elements are
 * processed in wire order by chasing wo pointers. This is what you want for
 * validating signatures on other people's XML documents. */

/* Called by: */
char* zx_ENC_WO_mm7_SubmitRsp(struct zx_ctx* c, struct zx_mm7_SubmitRsp_s* x, char* p )
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
  ZX_OUT_MEM(p, "SubmitRsp", sizeof("SubmitRsp")-1);
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
  ENC_LEN_DEBUG(x, "mm7:SubmitRsp", p-enc_base);
  return p;
}

/* FUNC(zx_EASY_ENC_SO_mm7_SubmitRsp) */

/* Called by: */
struct zx_str* zx_EASY_ENC_SO_mm7_SubmitRsp(struct zx_ctx* c, struct zx_mm7_SubmitRsp_s* x )
{
  int len;
  char* buf;
  c->ns_tab = ZX_ALLOC(c, sizeof(zx_ns_tab));
  memcpy(c->ns_tab, zx_ns_tab, sizeof(zx_ns_tab));
  len = zx_LEN_SO_mm7_SubmitRsp(c, x );
  buf = ZX_ALLOC(c, len+1);
  return zx_easy_enc_common(c, zx_ENC_SO_mm7_SubmitRsp(c, x, buf ), buf, len);
}

/* FUNC(zx_EASY_ENC_WO_mm7_SubmitRsp) */

/* Called by: */
struct zx_str* zx_EASY_ENC_WO_mm7_SubmitRsp(struct zx_ctx* c, struct zx_mm7_SubmitRsp_s* x )
{
  int len;
  char* buf;
  c->ns_tab = ZX_ALLOC(c, sizeof(zx_ns_tab));
  memcpy(c->ns_tab, zx_ns_tab, sizeof(zx_ns_tab));
  len = zx_LEN_WO_mm7_SubmitRsp(c, x );
  buf = ZX_ALLOC(c, len+1);
  return zx_easy_enc_common(c, zx_ENC_WO_mm7_SubmitRsp(c, x, buf ), buf, len);
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

#define EL_NAME   mm7_ThirdPartyPayer
#define EL_STRUCT zx_mm7_ThirdPartyPayer_s
#define EL_NS     mm7
#define EL_TAG    ThirdPartyPayer

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

/* FUNC(zx_LEN_SO_mm7_ThirdPartyPayer) */

/* Compute length of an element (and its subelements). The XML attributes
 * and elements are processed in schema order. */

/* Called by: */
int zx_LEN_SO_mm7_ThirdPartyPayer(struct zx_ctx* c, struct zx_mm7_ThirdPartyPayer_s* x )
{
  struct zx_ns_s* pop_seen = 0;
  struct zx_elem_s* se MAYBE_UNUSED;
#if 1 /* NORMALMODE */
  /* *** in simple_elem case should output ns prefix from ns node. */
  int len = sizeof("<mm7:ThirdPartyPayer")-1 + 1 + sizeof("</mm7:ThirdPartyPayer>")-1;
  if (c->inc_ns_len)
    len += zx_len_inc_ns(c, &pop_seen);
  len += zx_len_xmlns_if_not_seen(c, zx_ns_tab+zx_xmlns_ix_mm7, &pop_seen);


#else
  /* root node has no begin tag */
  int len = 0;
#endif
  
  {
      struct zx_mm7_RFC2822Address_s* e;
      for (e = x->RFC2822Address; e; e = (struct zx_mm7_RFC2822Address_s*)e->gg.g.n)
	  len += zx_LEN_SO_mm7_RFC2822Address(c, e);
  }
  {
      struct zx_mm7_Number_s* e;
      for (e = x->Number; e; e = (struct zx_mm7_Number_s*)e->gg.g.n)
	  len += zx_LEN_SO_mm7_Number(c, e);
  }
  {
      struct zx_mm7_ShortCode_s* e;
      for (e = x->ShortCode; e; e = (struct zx_mm7_ShortCode_s*)e->gg.g.n)
	  len += zx_LEN_SO_mm7_ShortCode(c, e);
  }
  {
      struct zx_mm7_Extension_s* e;
      for (e = x->Extension; e; e = (struct zx_mm7_Extension_s*)e->gg.g.n)
	  len += zx_LEN_SO_mm7_Extension(c, e);
  }


  len += zx_len_so_common(c, &x->gg);
  zx_pop_seen(pop_seen);
  ENC_LEN_DEBUG(x, "mm7:ThirdPartyPayer", len);
  return len;
}

/* FUNC(zx_LEN_WO_mm7_ThirdPartyPayer) */

/* Compute length of an element (and its subelements). The XML attributes
 * and elements are processed in wire order and no assumptions
 * are made about namespace prefixes. */

/* Called by: */
int zx_LEN_WO_mm7_ThirdPartyPayer(struct zx_ctx* c, struct zx_mm7_ThirdPartyPayer_s* x )
{
  struct zx_ns_s* pop_seen = 0;
  struct zx_elem_s* se MAYBE_UNUSED;
#if 1 /* NORMALMODE */
  int len = 1 + sizeof("ThirdPartyPayer")-1 + 1 + 2 + sizeof("ThirdPartyPayer")-1 + 1;
  
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
      struct zx_mm7_RFC2822Address_s* e;
      for (e = x->RFC2822Address; e; e = (struct zx_mm7_RFC2822Address_s*)e->gg.g.n)
	  len += zx_LEN_WO_mm7_RFC2822Address(c, e);
  }
  {
      struct zx_mm7_Number_s* e;
      for (e = x->Number; e; e = (struct zx_mm7_Number_s*)e->gg.g.n)
	  len += zx_LEN_WO_mm7_Number(c, e);
  }
  {
      struct zx_mm7_ShortCode_s* e;
      for (e = x->ShortCode; e; e = (struct zx_mm7_ShortCode_s*)e->gg.g.n)
	  len += zx_LEN_WO_mm7_ShortCode(c, e);
  }
  {
      struct zx_mm7_Extension_s* e;
      for (e = x->Extension; e; e = (struct zx_mm7_Extension_s*)e->gg.g.n)
	  len += zx_LEN_WO_mm7_Extension(c, e);
  }


  len += zx_len_wo_common(c, &x->gg); 
  zx_pop_seen(pop_seen);
  ENC_LEN_DEBUG(x, "mm7:ThirdPartyPayer", len);
  return len;
}

/* FUNC(zx_ENC_SO_mm7_ThirdPartyPayer) */

/* Render element into string. The XML attributes and elements are
 * processed in schema order. This is what you generally want for
 * rendering new data structure to a string. The wo pointers are not used. */

/* Called by: */
char* zx_ENC_SO_mm7_ThirdPartyPayer(struct zx_ctx* c, struct zx_mm7_ThirdPartyPayer_s* x, char* p )
{
  struct zx_elem_s* se MAYBE_UNUSED;
  struct zx_ns_s* pop_seen = 0;
  ENC_LEN_DEBUG_BASE;
#if 1 /* NORMALMODE */
  /* *** in simple_elem case should output ns prefix from ns node. */
  ZX_OUT_TAG(p, "<mm7:ThirdPartyPayer");
  if (c->inc_ns)
    p = zx_enc_inc_ns(c, p, &pop_seen);
  p = zx_enc_xmlns_if_not_seen(c, p, zx_ns_tab+zx_xmlns_ix_mm7, &pop_seen);


  p = zx_enc_unknown_attrs(p, x->gg.any_attr);
#else
  /* root node has no begin tag */
#endif
  
  {
      struct zx_mm7_RFC2822Address_s* e;
      for (e = x->RFC2822Address; e; e = (struct zx_mm7_RFC2822Address_s*)e->gg.g.n)
	  p = zx_ENC_SO_mm7_RFC2822Address(c, e, p);
  }
  {
      struct zx_mm7_Number_s* e;
      for (e = x->Number; e; e = (struct zx_mm7_Number_s*)e->gg.g.n)
	  p = zx_ENC_SO_mm7_Number(c, e, p);
  }
  {
      struct zx_mm7_ShortCode_s* e;
      for (e = x->ShortCode; e; e = (struct zx_mm7_ShortCode_s*)e->gg.g.n)
	  p = zx_ENC_SO_mm7_ShortCode(c, e, p);
  }
  {
      struct zx_mm7_Extension_s* e;
      for (e = x->Extension; e; e = (struct zx_mm7_Extension_s*)e->gg.g.n)
	  p = zx_ENC_SO_mm7_Extension(c, e, p);
  }

  p = zx_enc_so_unknown_elems_and_content(c, p, &x->gg);
  
#if 1 /* NORMALMODE */
  ZX_OUT_CLOSE_TAG(p, "</mm7:ThirdPartyPayer>");
  zx_pop_seen(pop_seen);
#else
  /* root node has no end tag either */
#endif
  ENC_LEN_DEBUG(x, "mm7:ThirdPartyPayer", p-enc_base);
  return p;
}

/* FUNC(zx_ENC_WO_mm7_ThirdPartyPayer) */

/* Render element into string. The XML attributes and elements are
 * processed in wire order by chasing wo pointers. This is what you want for
 * validating signatures on other people's XML documents. */

/* Called by: */
char* zx_ENC_WO_mm7_ThirdPartyPayer(struct zx_ctx* c, struct zx_mm7_ThirdPartyPayer_s* x, char* p )
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
  ZX_OUT_MEM(p, "ThirdPartyPayer", sizeof("ThirdPartyPayer")-1);
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
  ENC_LEN_DEBUG(x, "mm7:ThirdPartyPayer", p-enc_base);
  return p;
}

/* FUNC(zx_EASY_ENC_SO_mm7_ThirdPartyPayer) */

/* Called by: */
struct zx_str* zx_EASY_ENC_SO_mm7_ThirdPartyPayer(struct zx_ctx* c, struct zx_mm7_ThirdPartyPayer_s* x )
{
  int len;
  char* buf;
  c->ns_tab = ZX_ALLOC(c, sizeof(zx_ns_tab));
  memcpy(c->ns_tab, zx_ns_tab, sizeof(zx_ns_tab));
  len = zx_LEN_SO_mm7_ThirdPartyPayer(c, x );
  buf = ZX_ALLOC(c, len+1);
  return zx_easy_enc_common(c, zx_ENC_SO_mm7_ThirdPartyPayer(c, x, buf ), buf, len);
}

/* FUNC(zx_EASY_ENC_WO_mm7_ThirdPartyPayer) */

/* Called by: */
struct zx_str* zx_EASY_ENC_WO_mm7_ThirdPartyPayer(struct zx_ctx* c, struct zx_mm7_ThirdPartyPayer_s* x )
{
  int len;
  char* buf;
  c->ns_tab = ZX_ALLOC(c, sizeof(zx_ns_tab));
  memcpy(c->ns_tab, zx_ns_tab, sizeof(zx_ns_tab));
  len = zx_LEN_WO_mm7_ThirdPartyPayer(c, x );
  buf = ZX_ALLOC(c, len+1);
  return zx_easy_enc_common(c, zx_ENC_WO_mm7_ThirdPartyPayer(c, x, buf ), buf, len);
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

#define EL_NAME   mm7_To
#define EL_STRUCT zx_mm7_To_s
#define EL_NS     mm7
#define EL_TAG    To

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

/* FUNC(zx_LEN_SO_mm7_To) */

/* Compute length of an element (and its subelements). The XML attributes
 * and elements are processed in schema order. */

/* Called by: */
int zx_LEN_SO_mm7_To(struct zx_ctx* c, struct zx_mm7_To_s* x )
{
  struct zx_ns_s* pop_seen = 0;
  struct zx_elem_s* se MAYBE_UNUSED;
#if 1 /* NORMALMODE */
  /* *** in simple_elem case should output ns prefix from ns node. */
  int len = sizeof("<mm7:To")-1 + 1 + sizeof("</mm7:To>")-1;
  if (c->inc_ns_len)
    len += zx_len_inc_ns(c, &pop_seen);
  len += zx_len_xmlns_if_not_seen(c, zx_ns_tab+zx_xmlns_ix_mm7, &pop_seen);


#else
  /* root node has no begin tag */
  int len = 0;
#endif
  
  {
      struct zx_mm7_RFC2822Address_s* e;
      for (e = x->RFC2822Address; e; e = (struct zx_mm7_RFC2822Address_s*)e->gg.g.n)
	  len += zx_LEN_SO_mm7_RFC2822Address(c, e);
  }
  {
      struct zx_mm7_Number_s* e;
      for (e = x->Number; e; e = (struct zx_mm7_Number_s*)e->gg.g.n)
	  len += zx_LEN_SO_mm7_Number(c, e);
  }
  {
      struct zx_mm7_ShortCode_s* e;
      for (e = x->ShortCode; e; e = (struct zx_mm7_ShortCode_s*)e->gg.g.n)
	  len += zx_LEN_SO_mm7_ShortCode(c, e);
  }
  {
      struct zx_mm7_Extension_s* e;
      for (e = x->Extension; e; e = (struct zx_mm7_Extension_s*)e->gg.g.n)
	  len += zx_LEN_SO_mm7_Extension(c, e);
  }


  len += zx_len_so_common(c, &x->gg);
  zx_pop_seen(pop_seen);
  ENC_LEN_DEBUG(x, "mm7:To", len);
  return len;
}

/* FUNC(zx_LEN_WO_mm7_To) */

/* Compute length of an element (and its subelements). The XML attributes
 * and elements are processed in wire order and no assumptions
 * are made about namespace prefixes. */

/* Called by: */
int zx_LEN_WO_mm7_To(struct zx_ctx* c, struct zx_mm7_To_s* x )
{
  struct zx_ns_s* pop_seen = 0;
  struct zx_elem_s* se MAYBE_UNUSED;
#if 1 /* NORMALMODE */
  int len = 1 + sizeof("To")-1 + 1 + 2 + sizeof("To")-1 + 1;
  
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
      struct zx_mm7_RFC2822Address_s* e;
      for (e = x->RFC2822Address; e; e = (struct zx_mm7_RFC2822Address_s*)e->gg.g.n)
	  len += zx_LEN_WO_mm7_RFC2822Address(c, e);
  }
  {
      struct zx_mm7_Number_s* e;
      for (e = x->Number; e; e = (struct zx_mm7_Number_s*)e->gg.g.n)
	  len += zx_LEN_WO_mm7_Number(c, e);
  }
  {
      struct zx_mm7_ShortCode_s* e;
      for (e = x->ShortCode; e; e = (struct zx_mm7_ShortCode_s*)e->gg.g.n)
	  len += zx_LEN_WO_mm7_ShortCode(c, e);
  }
  {
      struct zx_mm7_Extension_s* e;
      for (e = x->Extension; e; e = (struct zx_mm7_Extension_s*)e->gg.g.n)
	  len += zx_LEN_WO_mm7_Extension(c, e);
  }


  len += zx_len_wo_common(c, &x->gg); 
  zx_pop_seen(pop_seen);
  ENC_LEN_DEBUG(x, "mm7:To", len);
  return len;
}

/* FUNC(zx_ENC_SO_mm7_To) */

/* Render element into string. The XML attributes and elements are
 * processed in schema order. This is what you generally want for
 * rendering new data structure to a string. The wo pointers are not used. */

/* Called by: */
char* zx_ENC_SO_mm7_To(struct zx_ctx* c, struct zx_mm7_To_s* x, char* p )
{
  struct zx_elem_s* se MAYBE_UNUSED;
  struct zx_ns_s* pop_seen = 0;
  ENC_LEN_DEBUG_BASE;
#if 1 /* NORMALMODE */
  /* *** in simple_elem case should output ns prefix from ns node. */
  ZX_OUT_TAG(p, "<mm7:To");
  if (c->inc_ns)
    p = zx_enc_inc_ns(c, p, &pop_seen);
  p = zx_enc_xmlns_if_not_seen(c, p, zx_ns_tab+zx_xmlns_ix_mm7, &pop_seen);


  p = zx_enc_unknown_attrs(p, x->gg.any_attr);
#else
  /* root node has no begin tag */
#endif
  
  {
      struct zx_mm7_RFC2822Address_s* e;
      for (e = x->RFC2822Address; e; e = (struct zx_mm7_RFC2822Address_s*)e->gg.g.n)
	  p = zx_ENC_SO_mm7_RFC2822Address(c, e, p);
  }
  {
      struct zx_mm7_Number_s* e;
      for (e = x->Number; e; e = (struct zx_mm7_Number_s*)e->gg.g.n)
	  p = zx_ENC_SO_mm7_Number(c, e, p);
  }
  {
      struct zx_mm7_ShortCode_s* e;
      for (e = x->ShortCode; e; e = (struct zx_mm7_ShortCode_s*)e->gg.g.n)
	  p = zx_ENC_SO_mm7_ShortCode(c, e, p);
  }
  {
      struct zx_mm7_Extension_s* e;
      for (e = x->Extension; e; e = (struct zx_mm7_Extension_s*)e->gg.g.n)
	  p = zx_ENC_SO_mm7_Extension(c, e, p);
  }

  p = zx_enc_so_unknown_elems_and_content(c, p, &x->gg);
  
#if 1 /* NORMALMODE */
  ZX_OUT_CLOSE_TAG(p, "</mm7:To>");
  zx_pop_seen(pop_seen);
#else
  /* root node has no end tag either */
#endif
  ENC_LEN_DEBUG(x, "mm7:To", p-enc_base);
  return p;
}

/* FUNC(zx_ENC_WO_mm7_To) */

/* Render element into string. The XML attributes and elements are
 * processed in wire order by chasing wo pointers. This is what you want for
 * validating signatures on other people's XML documents. */

/* Called by: */
char* zx_ENC_WO_mm7_To(struct zx_ctx* c, struct zx_mm7_To_s* x, char* p )
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
  ZX_OUT_MEM(p, "To", sizeof("To")-1);
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
  ENC_LEN_DEBUG(x, "mm7:To", p-enc_base);
  return p;
}

/* FUNC(zx_EASY_ENC_SO_mm7_To) */

/* Called by: */
struct zx_str* zx_EASY_ENC_SO_mm7_To(struct zx_ctx* c, struct zx_mm7_To_s* x )
{
  int len;
  char* buf;
  c->ns_tab = ZX_ALLOC(c, sizeof(zx_ns_tab));
  memcpy(c->ns_tab, zx_ns_tab, sizeof(zx_ns_tab));
  len = zx_LEN_SO_mm7_To(c, x );
  buf = ZX_ALLOC(c, len+1);
  return zx_easy_enc_common(c, zx_ENC_SO_mm7_To(c, x, buf ), buf, len);
}

/* FUNC(zx_EASY_ENC_WO_mm7_To) */

/* Called by: */
struct zx_str* zx_EASY_ENC_WO_mm7_To(struct zx_ctx* c, struct zx_mm7_To_s* x )
{
  int len;
  char* buf;
  c->ns_tab = ZX_ALLOC(c, sizeof(zx_ns_tab));
  memcpy(c->ns_tab, zx_ns_tab, sizeof(zx_ns_tab));
  len = zx_LEN_WO_mm7_To(c, x );
  buf = ZX_ALLOC(c, len+1);
  return zx_easy_enc_common(c, zx_ENC_WO_mm7_To(c, x, buf ), buf, len);
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

#define EL_NAME   mm7_TransactionID
#define EL_STRUCT zx_mm7_TransactionID_s
#define EL_NS     mm7
#define EL_TAG    TransactionID

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

/* FUNC(zx_LEN_SO_mm7_TransactionID) */

/* Compute length of an element (and its subelements). The XML attributes
 * and elements are processed in schema order. */

/* Called by: */
int zx_LEN_SO_mm7_TransactionID(struct zx_ctx* c, struct zx_mm7_TransactionID_s* x )
{
  struct zx_ns_s* pop_seen = 0;
  struct zx_elem_s* se MAYBE_UNUSED;
#if 1 /* NORMALMODE */
  /* *** in simple_elem case should output ns prefix from ns node. */
  int len = sizeof("<mm7:TransactionID")-1 + 1 + sizeof("</mm7:TransactionID>")-1;
  if (c->inc_ns_len)
    len += zx_len_inc_ns(c, &pop_seen);
  if (x->actor || x->encodingStyle || x->mustUnderstand)
    len += zx_len_xmlns_if_not_seen(c, zx_ns_tab+zx_xmlns_ix_e, &pop_seen);
  len += zx_len_xmlns_if_not_seen(c, zx_ns_tab+zx_xmlns_ix_mm7, &pop_seen);

  len += zx_attr_so_len(x->actor, sizeof("e:actor")-1);
  len += zx_attr_so_len(x->encodingStyle, sizeof("e:encodingStyle")-1);
  len += zx_attr_so_len(x->mustUnderstand, sizeof("e:mustUnderstand")-1);

#else
  /* root node has no begin tag */
  int len = 0;
#endif
  


  len += zx_len_so_common(c, &x->gg);
  zx_pop_seen(pop_seen);
  ENC_LEN_DEBUG(x, "mm7:TransactionID", len);
  return len;
}

/* FUNC(zx_LEN_WO_mm7_TransactionID) */

/* Compute length of an element (and its subelements). The XML attributes
 * and elements are processed in wire order and no assumptions
 * are made about namespace prefixes. */

/* Called by: */
int zx_LEN_WO_mm7_TransactionID(struct zx_ctx* c, struct zx_mm7_TransactionID_s* x )
{
  struct zx_ns_s* pop_seen = 0;
  struct zx_elem_s* se MAYBE_UNUSED;
#if 1 /* NORMALMODE */
  int len = 1 + sizeof("TransactionID")-1 + 1 + 2 + sizeof("TransactionID")-1 + 1;
  
  if (x->gg.g.ns && x->gg.g.ns->prefix_len)
    len += (x->gg.g.ns->prefix_len + 1) * 2;
  if (c->inc_ns_len)
    len += zx_len_inc_ns(c, &pop_seen);
  if (x->actor)
    len += zx_len_xmlns_if_not_seen(c, x->actor->g.ns, &pop_seen);
  if (x->encodingStyle)
    len += zx_len_xmlns_if_not_seen(c, x->encodingStyle->g.ns, &pop_seen);
  if (x->mustUnderstand)
    len += zx_len_xmlns_if_not_seen(c, x->mustUnderstand->g.ns, &pop_seen);
  len += zx_len_xmlns_if_not_seen(c, x->gg.g.ns, &pop_seen);

  len += zx_attr_wo_len(x->actor, sizeof("actor")-1);
  len += zx_attr_wo_len(x->encodingStyle, sizeof("encodingStyle")-1);
  len += zx_attr_wo_len(x->mustUnderstand, sizeof("mustUnderstand")-1);

#else
  /* root node has no begin tag */
  int len = 0;
#endif
  


  len += zx_len_wo_common(c, &x->gg); 
  zx_pop_seen(pop_seen);
  ENC_LEN_DEBUG(x, "mm7:TransactionID", len);
  return len;
}

/* FUNC(zx_ENC_SO_mm7_TransactionID) */

/* Render element into string. The XML attributes and elements are
 * processed in schema order. This is what you generally want for
 * rendering new data structure to a string. The wo pointers are not used. */

/* Called by: */
char* zx_ENC_SO_mm7_TransactionID(struct zx_ctx* c, struct zx_mm7_TransactionID_s* x, char* p )
{
  struct zx_elem_s* se MAYBE_UNUSED;
  struct zx_ns_s* pop_seen = 0;
  ENC_LEN_DEBUG_BASE;
#if 1 /* NORMALMODE */
  /* *** in simple_elem case should output ns prefix from ns node. */
  ZX_OUT_TAG(p, "<mm7:TransactionID");
  if (c->inc_ns)
    p = zx_enc_inc_ns(c, p, &pop_seen);
  if (x->actor || x->encodingStyle || x->mustUnderstand)
    p = zx_enc_xmlns_if_not_seen(c, p, zx_ns_tab+zx_xmlns_ix_e, &pop_seen);
  p = zx_enc_xmlns_if_not_seen(c, p, zx_ns_tab+zx_xmlns_ix_mm7, &pop_seen);

  p = zx_attr_so_enc(p, x->actor, " e:actor=\"", sizeof(" e:actor=\"")-1);
  p = zx_attr_so_enc(p, x->encodingStyle, " e:encodingStyle=\"", sizeof(" e:encodingStyle=\"")-1);
  p = zx_attr_so_enc(p, x->mustUnderstand, " e:mustUnderstand=\"", sizeof(" e:mustUnderstand=\"")-1);

  p = zx_enc_unknown_attrs(p, x->gg.any_attr);
#else
  /* root node has no begin tag */
#endif
  

  p = zx_enc_so_unknown_elems_and_content(c, p, &x->gg);
  
#if 1 /* NORMALMODE */
  ZX_OUT_CLOSE_TAG(p, "</mm7:TransactionID>");
  zx_pop_seen(pop_seen);
#else
  /* root node has no end tag either */
#endif
  ENC_LEN_DEBUG(x, "mm7:TransactionID", p-enc_base);
  return p;
}

/* FUNC(zx_ENC_WO_mm7_TransactionID) */

/* Render element into string. The XML attributes and elements are
 * processed in wire order by chasing wo pointers. This is what you want for
 * validating signatures on other people's XML documents. */

/* Called by: */
char* zx_ENC_WO_mm7_TransactionID(struct zx_ctx* c, struct zx_mm7_TransactionID_s* x, char* p )
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
  ZX_OUT_MEM(p, "TransactionID", sizeof("TransactionID")-1);
  qq = p;

  /* *** sort the namespaces */
  if (c->inc_ns)
    zx_add_inc_ns(c, &pop_seen);
  if (x->actor)
    zx_add_xmlns_if_not_seen(c, x->actor->g.ns, &pop_seen);
  if (x->encodingStyle)
    zx_add_xmlns_if_not_seen(c, x->encodingStyle->g.ns, &pop_seen);
  if (x->mustUnderstand)
    zx_add_xmlns_if_not_seen(c, x->mustUnderstand->g.ns, &pop_seen);
  zx_add_xmlns_if_not_seen(c, x->gg.g.ns, &pop_seen);

  p = zx_enc_seen(p, pop_seen); 
  p = zx_attr_wo_enc(p, x->actor, "actor=\"", sizeof("actor=\"")-1);
  p = zx_attr_wo_enc(p, x->encodingStyle, "encodingStyle=\"", sizeof("encodingStyle=\"")-1);
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
  ENC_LEN_DEBUG(x, "mm7:TransactionID", p-enc_base);
  return p;
}

/* FUNC(zx_EASY_ENC_SO_mm7_TransactionID) */

/* Called by: */
struct zx_str* zx_EASY_ENC_SO_mm7_TransactionID(struct zx_ctx* c, struct zx_mm7_TransactionID_s* x )
{
  int len;
  char* buf;
  c->ns_tab = ZX_ALLOC(c, sizeof(zx_ns_tab));
  memcpy(c->ns_tab, zx_ns_tab, sizeof(zx_ns_tab));
  len = zx_LEN_SO_mm7_TransactionID(c, x );
  buf = ZX_ALLOC(c, len+1);
  return zx_easy_enc_common(c, zx_ENC_SO_mm7_TransactionID(c, x, buf ), buf, len);
}

/* FUNC(zx_EASY_ENC_WO_mm7_TransactionID) */

/* Called by: */
struct zx_str* zx_EASY_ENC_WO_mm7_TransactionID(struct zx_ctx* c, struct zx_mm7_TransactionID_s* x )
{
  int len;
  char* buf;
  c->ns_tab = ZX_ALLOC(c, sizeof(zx_ns_tab));
  memcpy(c->ns_tab, zx_ns_tab, sizeof(zx_ns_tab));
  len = zx_LEN_WO_mm7_TransactionID(c, x );
  buf = ZX_ALLOC(c, len+1);
  return zx_easy_enc_common(c, zx_ENC_WO_mm7_TransactionID(c, x, buf ), buf, len);
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

#define EL_NAME   mm7_UACapabilities
#define EL_STRUCT zx_mm7_UACapabilities_s
#define EL_NS     mm7
#define EL_TAG    UACapabilities

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

/* FUNC(zx_LEN_SO_mm7_UACapabilities) */

/* Compute length of an element (and its subelements). The XML attributes
 * and elements are processed in schema order. */

/* Called by: */
int zx_LEN_SO_mm7_UACapabilities(struct zx_ctx* c, struct zx_mm7_UACapabilities_s* x )
{
  struct zx_ns_s* pop_seen = 0;
  struct zx_elem_s* se MAYBE_UNUSED;
#if 1 /* NORMALMODE */
  /* *** in simple_elem case should output ns prefix from ns node. */
  int len = sizeof("<mm7:UACapabilities")-1 + 1 + sizeof("</mm7:UACapabilities>")-1;
  if (c->inc_ns_len)
    len += zx_len_inc_ns(c, &pop_seen);
  len += zx_len_xmlns_if_not_seen(c, zx_ns_tab+zx_xmlns_ix_mm7, &pop_seen);

  len += zx_attr_so_len(x->TimeStamp, sizeof("TimeStamp")-1);
  len += zx_attr_so_len(x->UAProf, sizeof("UAProf")-1);

#else
  /* root node has no begin tag */
  int len = 0;
#endif
  


  len += zx_len_so_common(c, &x->gg);
  zx_pop_seen(pop_seen);
  ENC_LEN_DEBUG(x, "mm7:UACapabilities", len);
  return len;
}

/* FUNC(zx_LEN_WO_mm7_UACapabilities) */

/* Compute length of an element (and its subelements). The XML attributes
 * and elements are processed in wire order and no assumptions
 * are made about namespace prefixes. */

/* Called by: */
int zx_LEN_WO_mm7_UACapabilities(struct zx_ctx* c, struct zx_mm7_UACapabilities_s* x )
{
  struct zx_ns_s* pop_seen = 0;
  struct zx_elem_s* se MAYBE_UNUSED;
#if 1 /* NORMALMODE */
  int len = 1 + sizeof("UACapabilities")-1 + 1 + 2 + sizeof("UACapabilities")-1 + 1;
  
  if (x->gg.g.ns && x->gg.g.ns->prefix_len)
    len += (x->gg.g.ns->prefix_len + 1) * 2;
  if (c->inc_ns_len)
    len += zx_len_inc_ns(c, &pop_seen);
  len += zx_len_xmlns_if_not_seen(c, x->gg.g.ns, &pop_seen);

  len += zx_attr_wo_len(x->TimeStamp, sizeof("TimeStamp")-1);
  len += zx_attr_wo_len(x->UAProf, sizeof("UAProf")-1);

#else
  /* root node has no begin tag */
  int len = 0;
#endif
  


  len += zx_len_wo_common(c, &x->gg); 
  zx_pop_seen(pop_seen);
  ENC_LEN_DEBUG(x, "mm7:UACapabilities", len);
  return len;
}

/* FUNC(zx_ENC_SO_mm7_UACapabilities) */

/* Render element into string. The XML attributes and elements are
 * processed in schema order. This is what you generally want for
 * rendering new data structure to a string. The wo pointers are not used. */

/* Called by: */
char* zx_ENC_SO_mm7_UACapabilities(struct zx_ctx* c, struct zx_mm7_UACapabilities_s* x, char* p )
{
  struct zx_elem_s* se MAYBE_UNUSED;
  struct zx_ns_s* pop_seen = 0;
  ENC_LEN_DEBUG_BASE;
#if 1 /* NORMALMODE */
  /* *** in simple_elem case should output ns prefix from ns node. */
  ZX_OUT_TAG(p, "<mm7:UACapabilities");
  if (c->inc_ns)
    p = zx_enc_inc_ns(c, p, &pop_seen);
  p = zx_enc_xmlns_if_not_seen(c, p, zx_ns_tab+zx_xmlns_ix_mm7, &pop_seen);

  p = zx_attr_so_enc(p, x->TimeStamp, " TimeStamp=\"", sizeof(" TimeStamp=\"")-1);
  p = zx_attr_so_enc(p, x->UAProf, " UAProf=\"", sizeof(" UAProf=\"")-1);

  p = zx_enc_unknown_attrs(p, x->gg.any_attr);
#else
  /* root node has no begin tag */
#endif
  

  p = zx_enc_so_unknown_elems_and_content(c, p, &x->gg);
  
#if 1 /* NORMALMODE */
  ZX_OUT_CLOSE_TAG(p, "</mm7:UACapabilities>");
  zx_pop_seen(pop_seen);
#else
  /* root node has no end tag either */
#endif
  ENC_LEN_DEBUG(x, "mm7:UACapabilities", p-enc_base);
  return p;
}

/* FUNC(zx_ENC_WO_mm7_UACapabilities) */

/* Render element into string. The XML attributes and elements are
 * processed in wire order by chasing wo pointers. This is what you want for
 * validating signatures on other people's XML documents. */

/* Called by: */
char* zx_ENC_WO_mm7_UACapabilities(struct zx_ctx* c, struct zx_mm7_UACapabilities_s* x, char* p )
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
  ZX_OUT_MEM(p, "UACapabilities", sizeof("UACapabilities")-1);
  qq = p;

  /* *** sort the namespaces */
  if (c->inc_ns)
    zx_add_inc_ns(c, &pop_seen);
  zx_add_xmlns_if_not_seen(c, x->gg.g.ns, &pop_seen);

  p = zx_enc_seen(p, pop_seen); 
  p = zx_attr_wo_enc(p, x->TimeStamp, "TimeStamp=\"", sizeof("TimeStamp=\"")-1);
  p = zx_attr_wo_enc(p, x->UAProf, "UAProf=\"", sizeof("UAProf=\"")-1);

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
  ENC_LEN_DEBUG(x, "mm7:UACapabilities", p-enc_base);
  return p;
}

/* FUNC(zx_EASY_ENC_SO_mm7_UACapabilities) */

/* Called by: */
struct zx_str* zx_EASY_ENC_SO_mm7_UACapabilities(struct zx_ctx* c, struct zx_mm7_UACapabilities_s* x )
{
  int len;
  char* buf;
  c->ns_tab = ZX_ALLOC(c, sizeof(zx_ns_tab));
  memcpy(c->ns_tab, zx_ns_tab, sizeof(zx_ns_tab));
  len = zx_LEN_SO_mm7_UACapabilities(c, x );
  buf = ZX_ALLOC(c, len+1);
  return zx_easy_enc_common(c, zx_ENC_SO_mm7_UACapabilities(c, x, buf ), buf, len);
}

/* FUNC(zx_EASY_ENC_WO_mm7_UACapabilities) */

/* Called by: */
struct zx_str* zx_EASY_ENC_WO_mm7_UACapabilities(struct zx_ctx* c, struct zx_mm7_UACapabilities_s* x )
{
  int len;
  char* buf;
  c->ns_tab = ZX_ALLOC(c, sizeof(zx_ns_tab));
  memcpy(c->ns_tab, zx_ns_tab, sizeof(zx_ns_tab));
  len = zx_LEN_WO_mm7_UACapabilities(c, x );
  buf = ZX_ALLOC(c, len+1);
  return zx_easy_enc_common(c, zx_ENC_WO_mm7_UACapabilities(c, x, buf ), buf, len);
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

#define EL_NAME   mm7_UserAgent
#define EL_STRUCT zx_mm7_UserAgent_s
#define EL_NS     mm7
#define EL_TAG    UserAgent

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

/* FUNC(zx_LEN_SO_mm7_UserAgent) */

/* Compute length of an element (and its subelements). The XML attributes
 * and elements are processed in schema order. */

/* Called by: */
int zx_LEN_SO_mm7_UserAgent(struct zx_ctx* c, struct zx_mm7_UserAgent_s* x )
{
  struct zx_ns_s* pop_seen = 0;
  struct zx_elem_s* se MAYBE_UNUSED;
#if 1 /* NORMALMODE */
  /* *** in simple_elem case should output ns prefix from ns node. */
  int len = sizeof("<mm7:UserAgent")-1 + 1 + sizeof("</mm7:UserAgent>")-1;
  if (c->inc_ns_len)
    len += zx_len_inc_ns(c, &pop_seen);
  len += zx_len_xmlns_if_not_seen(c, zx_ns_tab+zx_xmlns_ix_mm7, &pop_seen);

  len += zx_attr_so_len(x->sequence, sizeof("sequence")-1);

#else
  /* root node has no begin tag */
  int len = 0;
#endif
  
  {
      struct zx_mm7_RFC2822Address_s* e;
      for (e = x->RFC2822Address; e; e = (struct zx_mm7_RFC2822Address_s*)e->gg.g.n)
	  len += zx_LEN_SO_mm7_RFC2822Address(c, e);
  }
  {
      struct zx_mm7_Number_s* e;
      for (e = x->Number; e; e = (struct zx_mm7_Number_s*)e->gg.g.n)
	  len += zx_LEN_SO_mm7_Number(c, e);
  }
  {
      struct zx_mm7_ShortCode_s* e;
      for (e = x->ShortCode; e; e = (struct zx_mm7_ShortCode_s*)e->gg.g.n)
	  len += zx_LEN_SO_mm7_ShortCode(c, e);
  }
  {
      struct zx_mm7_Extension_s* e;
      for (e = x->Extension; e; e = (struct zx_mm7_Extension_s*)e->gg.g.n)
	  len += zx_LEN_SO_mm7_Extension(c, e);
  }


  len += zx_len_so_common(c, &x->gg);
  zx_pop_seen(pop_seen);
  ENC_LEN_DEBUG(x, "mm7:UserAgent", len);
  return len;
}

/* FUNC(zx_LEN_WO_mm7_UserAgent) */

/* Compute length of an element (and its subelements). The XML attributes
 * and elements are processed in wire order and no assumptions
 * are made about namespace prefixes. */

/* Called by: */
int zx_LEN_WO_mm7_UserAgent(struct zx_ctx* c, struct zx_mm7_UserAgent_s* x )
{
  struct zx_ns_s* pop_seen = 0;
  struct zx_elem_s* se MAYBE_UNUSED;
#if 1 /* NORMALMODE */
  int len = 1 + sizeof("UserAgent")-1 + 1 + 2 + sizeof("UserAgent")-1 + 1;
  
  if (x->gg.g.ns && x->gg.g.ns->prefix_len)
    len += (x->gg.g.ns->prefix_len + 1) * 2;
  if (c->inc_ns_len)
    len += zx_len_inc_ns(c, &pop_seen);
  len += zx_len_xmlns_if_not_seen(c, x->gg.g.ns, &pop_seen);

  len += zx_attr_wo_len(x->sequence, sizeof("sequence")-1);

#else
  /* root node has no begin tag */
  int len = 0;
#endif
  
  {
      struct zx_mm7_RFC2822Address_s* e;
      for (e = x->RFC2822Address; e; e = (struct zx_mm7_RFC2822Address_s*)e->gg.g.n)
	  len += zx_LEN_WO_mm7_RFC2822Address(c, e);
  }
  {
      struct zx_mm7_Number_s* e;
      for (e = x->Number; e; e = (struct zx_mm7_Number_s*)e->gg.g.n)
	  len += zx_LEN_WO_mm7_Number(c, e);
  }
  {
      struct zx_mm7_ShortCode_s* e;
      for (e = x->ShortCode; e; e = (struct zx_mm7_ShortCode_s*)e->gg.g.n)
	  len += zx_LEN_WO_mm7_ShortCode(c, e);
  }
  {
      struct zx_mm7_Extension_s* e;
      for (e = x->Extension; e; e = (struct zx_mm7_Extension_s*)e->gg.g.n)
	  len += zx_LEN_WO_mm7_Extension(c, e);
  }


  len += zx_len_wo_common(c, &x->gg); 
  zx_pop_seen(pop_seen);
  ENC_LEN_DEBUG(x, "mm7:UserAgent", len);
  return len;
}

/* FUNC(zx_ENC_SO_mm7_UserAgent) */

/* Render element into string. The XML attributes and elements are
 * processed in schema order. This is what you generally want for
 * rendering new data structure to a string. The wo pointers are not used. */

/* Called by: */
char* zx_ENC_SO_mm7_UserAgent(struct zx_ctx* c, struct zx_mm7_UserAgent_s* x, char* p )
{
  struct zx_elem_s* se MAYBE_UNUSED;
  struct zx_ns_s* pop_seen = 0;
  ENC_LEN_DEBUG_BASE;
#if 1 /* NORMALMODE */
  /* *** in simple_elem case should output ns prefix from ns node. */
  ZX_OUT_TAG(p, "<mm7:UserAgent");
  if (c->inc_ns)
    p = zx_enc_inc_ns(c, p, &pop_seen);
  p = zx_enc_xmlns_if_not_seen(c, p, zx_ns_tab+zx_xmlns_ix_mm7, &pop_seen);

  p = zx_attr_so_enc(p, x->sequence, " sequence=\"", sizeof(" sequence=\"")-1);

  p = zx_enc_unknown_attrs(p, x->gg.any_attr);
#else
  /* root node has no begin tag */
#endif
  
  {
      struct zx_mm7_RFC2822Address_s* e;
      for (e = x->RFC2822Address; e; e = (struct zx_mm7_RFC2822Address_s*)e->gg.g.n)
	  p = zx_ENC_SO_mm7_RFC2822Address(c, e, p);
  }
  {
      struct zx_mm7_Number_s* e;
      for (e = x->Number; e; e = (struct zx_mm7_Number_s*)e->gg.g.n)
	  p = zx_ENC_SO_mm7_Number(c, e, p);
  }
  {
      struct zx_mm7_ShortCode_s* e;
      for (e = x->ShortCode; e; e = (struct zx_mm7_ShortCode_s*)e->gg.g.n)
	  p = zx_ENC_SO_mm7_ShortCode(c, e, p);
  }
  {
      struct zx_mm7_Extension_s* e;
      for (e = x->Extension; e; e = (struct zx_mm7_Extension_s*)e->gg.g.n)
	  p = zx_ENC_SO_mm7_Extension(c, e, p);
  }

  p = zx_enc_so_unknown_elems_and_content(c, p, &x->gg);
  
#if 1 /* NORMALMODE */
  ZX_OUT_CLOSE_TAG(p, "</mm7:UserAgent>");
  zx_pop_seen(pop_seen);
#else
  /* root node has no end tag either */
#endif
  ENC_LEN_DEBUG(x, "mm7:UserAgent", p-enc_base);
  return p;
}

/* FUNC(zx_ENC_WO_mm7_UserAgent) */

/* Render element into string. The XML attributes and elements are
 * processed in wire order by chasing wo pointers. This is what you want for
 * validating signatures on other people's XML documents. */

/* Called by: */
char* zx_ENC_WO_mm7_UserAgent(struct zx_ctx* c, struct zx_mm7_UserAgent_s* x, char* p )
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
  ZX_OUT_MEM(p, "UserAgent", sizeof("UserAgent")-1);
  qq = p;

  /* *** sort the namespaces */
  if (c->inc_ns)
    zx_add_inc_ns(c, &pop_seen);
  zx_add_xmlns_if_not_seen(c, x->gg.g.ns, &pop_seen);

  p = zx_enc_seen(p, pop_seen); 
  p = zx_attr_wo_enc(p, x->sequence, "sequence=\"", sizeof("sequence=\"")-1);

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
  ENC_LEN_DEBUG(x, "mm7:UserAgent", p-enc_base);
  return p;
}

/* FUNC(zx_EASY_ENC_SO_mm7_UserAgent) */

/* Called by: */
struct zx_str* zx_EASY_ENC_SO_mm7_UserAgent(struct zx_ctx* c, struct zx_mm7_UserAgent_s* x )
{
  int len;
  char* buf;
  c->ns_tab = ZX_ALLOC(c, sizeof(zx_ns_tab));
  memcpy(c->ns_tab, zx_ns_tab, sizeof(zx_ns_tab));
  len = zx_LEN_SO_mm7_UserAgent(c, x );
  buf = ZX_ALLOC(c, len+1);
  return zx_easy_enc_common(c, zx_ENC_SO_mm7_UserAgent(c, x, buf ), buf, len);
}

/* FUNC(zx_EASY_ENC_WO_mm7_UserAgent) */

/* Called by: */
struct zx_str* zx_EASY_ENC_WO_mm7_UserAgent(struct zx_ctx* c, struct zx_mm7_UserAgent_s* x )
{
  int len;
  char* buf;
  c->ns_tab = ZX_ALLOC(c, sizeof(zx_ns_tab));
  memcpy(c->ns_tab, zx_ns_tab, sizeof(zx_ns_tab));
  len = zx_LEN_WO_mm7_UserAgent(c, x );
  buf = ZX_ALLOC(c, len+1);
  return zx_easy_enc_common(c, zx_ENC_WO_mm7_UserAgent(c, x, buf ), buf, len);
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

#define EL_NAME   mm7_VASPErrorRsp
#define EL_STRUCT zx_mm7_VASPErrorRsp_s
#define EL_NS     mm7
#define EL_TAG    VASPErrorRsp

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

/* FUNC(zx_LEN_SO_mm7_VASPErrorRsp) */

/* Compute length of an element (and its subelements). The XML attributes
 * and elements are processed in schema order. */

/* Called by: */
int zx_LEN_SO_mm7_VASPErrorRsp(struct zx_ctx* c, struct zx_mm7_VASPErrorRsp_s* x )
{
  struct zx_ns_s* pop_seen = 0;
  struct zx_elem_s* se MAYBE_UNUSED;
#if 1 /* NORMALMODE */
  /* *** in simple_elem case should output ns prefix from ns node. */
  int len = sizeof("<mm7:VASPErrorRsp")-1 + 1 + sizeof("</mm7:VASPErrorRsp>")-1;
  if (c->inc_ns_len)
    len += zx_len_inc_ns(c, &pop_seen);
  len += zx_len_xmlns_if_not_seen(c, zx_ns_tab+zx_xmlns_ix_mm7, &pop_seen);


#else
  /* root node has no begin tag */
  int len = 0;
#endif
  
  for (se = x->MM7Version; se; se = (struct zx_elem_s*)se->g.n)
    len += zx_LEN_SO_simple_elem(c,se, sizeof("mm7:MM7Version")-1, zx_ns_tab+zx_xmlns_ix_mm7);
  {
      struct zx_mm7_Status_s* e;
      for (e = x->Status; e; e = (struct zx_mm7_Status_s*)e->gg.g.n)
	  len += zx_LEN_SO_mm7_Status(c, e);
  }
  {
      struct zx_mm7_Extension_s* e;
      for (e = x->Extension; e; e = (struct zx_mm7_Extension_s*)e->gg.g.n)
	  len += zx_LEN_SO_mm7_Extension(c, e);
  }


  len += zx_len_so_common(c, &x->gg);
  zx_pop_seen(pop_seen);
  ENC_LEN_DEBUG(x, "mm7:VASPErrorRsp", len);
  return len;
}

/* FUNC(zx_LEN_WO_mm7_VASPErrorRsp) */

/* Compute length of an element (and its subelements). The XML attributes
 * and elements are processed in wire order and no assumptions
 * are made about namespace prefixes. */

/* Called by: */
int zx_LEN_WO_mm7_VASPErrorRsp(struct zx_ctx* c, struct zx_mm7_VASPErrorRsp_s* x )
{
  struct zx_ns_s* pop_seen = 0;
  struct zx_elem_s* se MAYBE_UNUSED;
#if 1 /* NORMALMODE */
  int len = 1 + sizeof("VASPErrorRsp")-1 + 1 + 2 + sizeof("VASPErrorRsp")-1 + 1;
  
  if (x->gg.g.ns && x->gg.g.ns->prefix_len)
    len += (x->gg.g.ns->prefix_len + 1) * 2;
  if (c->inc_ns_len)
    len += zx_len_inc_ns(c, &pop_seen);
  len += zx_len_xmlns_if_not_seen(c, x->gg.g.ns, &pop_seen);


#else
  /* root node has no begin tag */
  int len = 0;
#endif
  
  for (se = x->MM7Version; se; se = (struct zx_elem_s*)se->g.n)
    len += zx_LEN_WO_simple_elem(c, se, sizeof("MM7Version")-1);
  {
      struct zx_mm7_Status_s* e;
      for (e = x->Status; e; e = (struct zx_mm7_Status_s*)e->gg.g.n)
	  len += zx_LEN_WO_mm7_Status(c, e);
  }
  {
      struct zx_mm7_Extension_s* e;
      for (e = x->Extension; e; e = (struct zx_mm7_Extension_s*)e->gg.g.n)
	  len += zx_LEN_WO_mm7_Extension(c, e);
  }


  len += zx_len_wo_common(c, &x->gg); 
  zx_pop_seen(pop_seen);
  ENC_LEN_DEBUG(x, "mm7:VASPErrorRsp", len);
  return len;
}

/* FUNC(zx_ENC_SO_mm7_VASPErrorRsp) */

/* Render element into string. The XML attributes and elements are
 * processed in schema order. This is what you generally want for
 * rendering new data structure to a string. The wo pointers are not used. */

/* Called by: */
char* zx_ENC_SO_mm7_VASPErrorRsp(struct zx_ctx* c, struct zx_mm7_VASPErrorRsp_s* x, char* p )
{
  struct zx_elem_s* se MAYBE_UNUSED;
  struct zx_ns_s* pop_seen = 0;
  ENC_LEN_DEBUG_BASE;
#if 1 /* NORMALMODE */
  /* *** in simple_elem case should output ns prefix from ns node. */
  ZX_OUT_TAG(p, "<mm7:VASPErrorRsp");
  if (c->inc_ns)
    p = zx_enc_inc_ns(c, p, &pop_seen);
  p = zx_enc_xmlns_if_not_seen(c, p, zx_ns_tab+zx_xmlns_ix_mm7, &pop_seen);


  p = zx_enc_unknown_attrs(p, x->gg.any_attr);
#else
  /* root node has no begin tag */
#endif
  
  for (se = x->MM7Version; se; se = (struct zx_elem_s*)se->g.n)
    p = zx_ENC_SO_simple_elem(c, se, p, "mm7:MM7Version", sizeof("mm7:MM7Version")-1, zx_ns_tab+zx_xmlns_ix_mm7);
  {
      struct zx_mm7_Status_s* e;
      for (e = x->Status; e; e = (struct zx_mm7_Status_s*)e->gg.g.n)
	  p = zx_ENC_SO_mm7_Status(c, e, p);
  }
  {
      struct zx_mm7_Extension_s* e;
      for (e = x->Extension; e; e = (struct zx_mm7_Extension_s*)e->gg.g.n)
	  p = zx_ENC_SO_mm7_Extension(c, e, p);
  }

  p = zx_enc_so_unknown_elems_and_content(c, p, &x->gg);
  
#if 1 /* NORMALMODE */
  ZX_OUT_CLOSE_TAG(p, "</mm7:VASPErrorRsp>");
  zx_pop_seen(pop_seen);
#else
  /* root node has no end tag either */
#endif
  ENC_LEN_DEBUG(x, "mm7:VASPErrorRsp", p-enc_base);
  return p;
}

/* FUNC(zx_ENC_WO_mm7_VASPErrorRsp) */

/* Render element into string. The XML attributes and elements are
 * processed in wire order by chasing wo pointers. This is what you want for
 * validating signatures on other people's XML documents. */

/* Called by: */
char* zx_ENC_WO_mm7_VASPErrorRsp(struct zx_ctx* c, struct zx_mm7_VASPErrorRsp_s* x, char* p )
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
  ZX_OUT_MEM(p, "VASPErrorRsp", sizeof("VASPErrorRsp")-1);
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
  ENC_LEN_DEBUG(x, "mm7:VASPErrorRsp", p-enc_base);
  return p;
}

/* FUNC(zx_EASY_ENC_SO_mm7_VASPErrorRsp) */

/* Called by: */
struct zx_str* zx_EASY_ENC_SO_mm7_VASPErrorRsp(struct zx_ctx* c, struct zx_mm7_VASPErrorRsp_s* x )
{
  int len;
  char* buf;
  c->ns_tab = ZX_ALLOC(c, sizeof(zx_ns_tab));
  memcpy(c->ns_tab, zx_ns_tab, sizeof(zx_ns_tab));
  len = zx_LEN_SO_mm7_VASPErrorRsp(c, x );
  buf = ZX_ALLOC(c, len+1);
  return zx_easy_enc_common(c, zx_ENC_SO_mm7_VASPErrorRsp(c, x, buf ), buf, len);
}

/* FUNC(zx_EASY_ENC_WO_mm7_VASPErrorRsp) */

/* Called by: */
struct zx_str* zx_EASY_ENC_WO_mm7_VASPErrorRsp(struct zx_ctx* c, struct zx_mm7_VASPErrorRsp_s* x )
{
  int len;
  char* buf;
  c->ns_tab = ZX_ALLOC(c, sizeof(zx_ns_tab));
  memcpy(c->ns_tab, zx_ns_tab, sizeof(zx_ns_tab));
  len = zx_LEN_WO_mm7_VASPErrorRsp(c, x );
  buf = ZX_ALLOC(c, len+1);
  return zx_easy_enc_common(c, zx_ENC_WO_mm7_VASPErrorRsp(c, x, buf ), buf, len);
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

#define EL_NAME   mm7_element
#define EL_STRUCT zx_mm7_element_s
#define EL_NS     mm7
#define EL_TAG    element

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

/* FUNC(zx_LEN_SO_mm7_element) */

/* Compute length of an element (and its subelements). The XML attributes
 * and elements are processed in schema order. */

/* Called by: */
int zx_LEN_SO_mm7_element(struct zx_ctx* c, struct zx_mm7_element_s* x )
{
  struct zx_ns_s* pop_seen = 0;
  struct zx_elem_s* se MAYBE_UNUSED;
#if 1 /* NORMALMODE */
  /* *** in simple_elem case should output ns prefix from ns node. */
  int len = sizeof("<mm7:element")-1 + 1 + sizeof("</mm7:element>")-1;
  if (c->inc_ns_len)
    len += zx_len_inc_ns(c, &pop_seen);
  len += zx_len_xmlns_if_not_seen(c, zx_ns_tab+zx_xmlns_ix_mm7, &pop_seen);


#else
  /* root node has no begin tag */
  int len = 0;
#endif
  
  for (se = x->key; se; se = (struct zx_elem_s*)se->g.n)
    len += zx_LEN_SO_simple_elem(c,se, sizeof("mm7:key")-1, zx_ns_tab+zx_xmlns_ix_mm7);
  for (se = x->value; se; se = (struct zx_elem_s*)se->g.n)
    len += zx_LEN_SO_simple_elem(c,se, sizeof("mm7:value")-1, zx_ns_tab+zx_xmlns_ix_mm7);


  len += zx_len_so_common(c, &x->gg);
  zx_pop_seen(pop_seen);
  ENC_LEN_DEBUG(x, "mm7:element", len);
  return len;
}

/* FUNC(zx_LEN_WO_mm7_element) */

/* Compute length of an element (and its subelements). The XML attributes
 * and elements are processed in wire order and no assumptions
 * are made about namespace prefixes. */

/* Called by: */
int zx_LEN_WO_mm7_element(struct zx_ctx* c, struct zx_mm7_element_s* x )
{
  struct zx_ns_s* pop_seen = 0;
  struct zx_elem_s* se MAYBE_UNUSED;
#if 1 /* NORMALMODE */
  int len = 1 + sizeof("element")-1 + 1 + 2 + sizeof("element")-1 + 1;
  
  if (x->gg.g.ns && x->gg.g.ns->prefix_len)
    len += (x->gg.g.ns->prefix_len + 1) * 2;
  if (c->inc_ns_len)
    len += zx_len_inc_ns(c, &pop_seen);
  len += zx_len_xmlns_if_not_seen(c, x->gg.g.ns, &pop_seen);


#else
  /* root node has no begin tag */
  int len = 0;
#endif
  
  for (se = x->key; se; se = (struct zx_elem_s*)se->g.n)
    len += zx_LEN_WO_simple_elem(c, se, sizeof("key")-1);
  for (se = x->value; se; se = (struct zx_elem_s*)se->g.n)
    len += zx_LEN_WO_simple_elem(c, se, sizeof("value")-1);


  len += zx_len_wo_common(c, &x->gg); 
  zx_pop_seen(pop_seen);
  ENC_LEN_DEBUG(x, "mm7:element", len);
  return len;
}

/* FUNC(zx_ENC_SO_mm7_element) */

/* Render element into string. The XML attributes and elements are
 * processed in schema order. This is what you generally want for
 * rendering new data structure to a string. The wo pointers are not used. */

/* Called by: */
char* zx_ENC_SO_mm7_element(struct zx_ctx* c, struct zx_mm7_element_s* x, char* p )
{
  struct zx_elem_s* se MAYBE_UNUSED;
  struct zx_ns_s* pop_seen = 0;
  ENC_LEN_DEBUG_BASE;
#if 1 /* NORMALMODE */
  /* *** in simple_elem case should output ns prefix from ns node. */
  ZX_OUT_TAG(p, "<mm7:element");
  if (c->inc_ns)
    p = zx_enc_inc_ns(c, p, &pop_seen);
  p = zx_enc_xmlns_if_not_seen(c, p, zx_ns_tab+zx_xmlns_ix_mm7, &pop_seen);


  p = zx_enc_unknown_attrs(p, x->gg.any_attr);
#else
  /* root node has no begin tag */
#endif
  
  for (se = x->key; se; se = (struct zx_elem_s*)se->g.n)
    p = zx_ENC_SO_simple_elem(c, se, p, "mm7:key", sizeof("mm7:key")-1, zx_ns_tab+zx_xmlns_ix_mm7);
  for (se = x->value; se; se = (struct zx_elem_s*)se->g.n)
    p = zx_ENC_SO_simple_elem(c, se, p, "mm7:value", sizeof("mm7:value")-1, zx_ns_tab+zx_xmlns_ix_mm7);

  p = zx_enc_so_unknown_elems_and_content(c, p, &x->gg);
  
#if 1 /* NORMALMODE */
  ZX_OUT_CLOSE_TAG(p, "</mm7:element>");
  zx_pop_seen(pop_seen);
#else
  /* root node has no end tag either */
#endif
  ENC_LEN_DEBUG(x, "mm7:element", p-enc_base);
  return p;
}

/* FUNC(zx_ENC_WO_mm7_element) */

/* Render element into string. The XML attributes and elements are
 * processed in wire order by chasing wo pointers. This is what you want for
 * validating signatures on other people's XML documents. */

/* Called by: */
char* zx_ENC_WO_mm7_element(struct zx_ctx* c, struct zx_mm7_element_s* x, char* p )
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
  ZX_OUT_MEM(p, "element", sizeof("element")-1);
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
  ENC_LEN_DEBUG(x, "mm7:element", p-enc_base);
  return p;
}

/* FUNC(zx_EASY_ENC_SO_mm7_element) */

/* Called by: */
struct zx_str* zx_EASY_ENC_SO_mm7_element(struct zx_ctx* c, struct zx_mm7_element_s* x )
{
  int len;
  char* buf;
  c->ns_tab = ZX_ALLOC(c, sizeof(zx_ns_tab));
  memcpy(c->ns_tab, zx_ns_tab, sizeof(zx_ns_tab));
  len = zx_LEN_SO_mm7_element(c, x );
  buf = ZX_ALLOC(c, len+1);
  return zx_easy_enc_common(c, zx_ENC_SO_mm7_element(c, x, buf ), buf, len);
}

/* FUNC(zx_EASY_ENC_WO_mm7_element) */

/* Called by: */
struct zx_str* zx_EASY_ENC_WO_mm7_element(struct zx_ctx* c, struct zx_mm7_element_s* x )
{
  int len;
  char* buf;
  c->ns_tab = ZX_ALLOC(c, sizeof(zx_ns_tab));
  memcpy(c->ns_tab, zx_ns_tab, sizeof(zx_ns_tab));
  len = zx_LEN_WO_mm7_element(c, x );
  buf = ZX_ALLOC(c, len+1);
  return zx_easy_enc_common(c, zx_ENC_WO_mm7_element(c, x, buf ), buf, len);
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

#define EL_NAME   mm7_extendedCancelReq
#define EL_STRUCT zx_mm7_extendedCancelReq_s
#define EL_NS     mm7
#define EL_TAG    extendedCancelReq

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

/* FUNC(zx_LEN_SO_mm7_extendedCancelReq) */

/* Compute length of an element (and its subelements). The XML attributes
 * and elements are processed in schema order. */

/* Called by: */
int zx_LEN_SO_mm7_extendedCancelReq(struct zx_ctx* c, struct zx_mm7_extendedCancelReq_s* x )
{
  struct zx_ns_s* pop_seen = 0;
  struct zx_elem_s* se MAYBE_UNUSED;
#if 1 /* NORMALMODE */
  /* *** in simple_elem case should output ns prefix from ns node. */
  int len = sizeof("<mm7:extendedCancelReq")-1 + 1 + sizeof("</mm7:extendedCancelReq>")-1;
  if (c->inc_ns_len)
    len += zx_len_inc_ns(c, &pop_seen);
  len += zx_len_xmlns_if_not_seen(c, zx_ns_tab+zx_xmlns_ix_mm7, &pop_seen);


#else
  /* root node has no begin tag */
  int len = 0;
#endif
  
  for (se = x->MM7Version; se; se = (struct zx_elem_s*)se->g.n)
    len += zx_LEN_SO_simple_elem(c,se, sizeof("mm7:MM7Version")-1, zx_ns_tab+zx_xmlns_ix_mm7);
  {
      struct zx_mm7_SenderIdentification_s* e;
      for (e = x->SenderIdentification; e; e = (struct zx_mm7_SenderIdentification_s*)e->gg.g.n)
	  len += zx_LEN_SO_mm7_SenderIdentification(c, e);
  }
  {
      struct zx_mm7_Extension_s* e;
      for (e = x->Extension; e; e = (struct zx_mm7_Extension_s*)e->gg.g.n)
	  len += zx_LEN_SO_mm7_Extension(c, e);
  }
  for (se = x->CancelID; se; se = (struct zx_elem_s*)se->g.n)
    len += zx_LEN_SO_simple_elem(c,se, sizeof("mm7:CancelID")-1, zx_ns_tab+zx_xmlns_ix_mm7);


  len += zx_len_so_common(c, &x->gg);
  zx_pop_seen(pop_seen);
  ENC_LEN_DEBUG(x, "mm7:extendedCancelReq", len);
  return len;
}

/* FUNC(zx_LEN_WO_mm7_extendedCancelReq) */

/* Compute length of an element (and its subelements). The XML attributes
 * and elements are processed in wire order and no assumptions
 * are made about namespace prefixes. */

/* Called by: */
int zx_LEN_WO_mm7_extendedCancelReq(struct zx_ctx* c, struct zx_mm7_extendedCancelReq_s* x )
{
  struct zx_ns_s* pop_seen = 0;
  struct zx_elem_s* se MAYBE_UNUSED;
#if 1 /* NORMALMODE */
  int len = 1 + sizeof("extendedCancelReq")-1 + 1 + 2 + sizeof("extendedCancelReq")-1 + 1;
  
  if (x->gg.g.ns && x->gg.g.ns->prefix_len)
    len += (x->gg.g.ns->prefix_len + 1) * 2;
  if (c->inc_ns_len)
    len += zx_len_inc_ns(c, &pop_seen);
  len += zx_len_xmlns_if_not_seen(c, x->gg.g.ns, &pop_seen);


#else
  /* root node has no begin tag */
  int len = 0;
#endif
  
  for (se = x->MM7Version; se; se = (struct zx_elem_s*)se->g.n)
    len += zx_LEN_WO_simple_elem(c, se, sizeof("MM7Version")-1);
  {
      struct zx_mm7_SenderIdentification_s* e;
      for (e = x->SenderIdentification; e; e = (struct zx_mm7_SenderIdentification_s*)e->gg.g.n)
	  len += zx_LEN_WO_mm7_SenderIdentification(c, e);
  }
  {
      struct zx_mm7_Extension_s* e;
      for (e = x->Extension; e; e = (struct zx_mm7_Extension_s*)e->gg.g.n)
	  len += zx_LEN_WO_mm7_Extension(c, e);
  }
  for (se = x->CancelID; se; se = (struct zx_elem_s*)se->g.n)
    len += zx_LEN_WO_simple_elem(c, se, sizeof("CancelID")-1);


  len += zx_len_wo_common(c, &x->gg); 
  zx_pop_seen(pop_seen);
  ENC_LEN_DEBUG(x, "mm7:extendedCancelReq", len);
  return len;
}

/* FUNC(zx_ENC_SO_mm7_extendedCancelReq) */

/* Render element into string. The XML attributes and elements are
 * processed in schema order. This is what you generally want for
 * rendering new data structure to a string. The wo pointers are not used. */

/* Called by: */
char* zx_ENC_SO_mm7_extendedCancelReq(struct zx_ctx* c, struct zx_mm7_extendedCancelReq_s* x, char* p )
{
  struct zx_elem_s* se MAYBE_UNUSED;
  struct zx_ns_s* pop_seen = 0;
  ENC_LEN_DEBUG_BASE;
#if 1 /* NORMALMODE */
  /* *** in simple_elem case should output ns prefix from ns node. */
  ZX_OUT_TAG(p, "<mm7:extendedCancelReq");
  if (c->inc_ns)
    p = zx_enc_inc_ns(c, p, &pop_seen);
  p = zx_enc_xmlns_if_not_seen(c, p, zx_ns_tab+zx_xmlns_ix_mm7, &pop_seen);


  p = zx_enc_unknown_attrs(p, x->gg.any_attr);
#else
  /* root node has no begin tag */
#endif
  
  for (se = x->MM7Version; se; se = (struct zx_elem_s*)se->g.n)
    p = zx_ENC_SO_simple_elem(c, se, p, "mm7:MM7Version", sizeof("mm7:MM7Version")-1, zx_ns_tab+zx_xmlns_ix_mm7);
  {
      struct zx_mm7_SenderIdentification_s* e;
      for (e = x->SenderIdentification; e; e = (struct zx_mm7_SenderIdentification_s*)e->gg.g.n)
	  p = zx_ENC_SO_mm7_SenderIdentification(c, e, p);
  }
  {
      struct zx_mm7_Extension_s* e;
      for (e = x->Extension; e; e = (struct zx_mm7_Extension_s*)e->gg.g.n)
	  p = zx_ENC_SO_mm7_Extension(c, e, p);
  }
  for (se = x->CancelID; se; se = (struct zx_elem_s*)se->g.n)
    p = zx_ENC_SO_simple_elem(c, se, p, "mm7:CancelID", sizeof("mm7:CancelID")-1, zx_ns_tab+zx_xmlns_ix_mm7);

  p = zx_enc_so_unknown_elems_and_content(c, p, &x->gg);
  
#if 1 /* NORMALMODE */
  ZX_OUT_CLOSE_TAG(p, "</mm7:extendedCancelReq>");
  zx_pop_seen(pop_seen);
#else
  /* root node has no end tag either */
#endif
  ENC_LEN_DEBUG(x, "mm7:extendedCancelReq", p-enc_base);
  return p;
}

/* FUNC(zx_ENC_WO_mm7_extendedCancelReq) */

/* Render element into string. The XML attributes and elements are
 * processed in wire order by chasing wo pointers. This is what you want for
 * validating signatures on other people's XML documents. */

/* Called by: */
char* zx_ENC_WO_mm7_extendedCancelReq(struct zx_ctx* c, struct zx_mm7_extendedCancelReq_s* x, char* p )
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
  ZX_OUT_MEM(p, "extendedCancelReq", sizeof("extendedCancelReq")-1);
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
  ENC_LEN_DEBUG(x, "mm7:extendedCancelReq", p-enc_base);
  return p;
}

/* FUNC(zx_EASY_ENC_SO_mm7_extendedCancelReq) */

/* Called by: */
struct zx_str* zx_EASY_ENC_SO_mm7_extendedCancelReq(struct zx_ctx* c, struct zx_mm7_extendedCancelReq_s* x )
{
  int len;
  char* buf;
  c->ns_tab = ZX_ALLOC(c, sizeof(zx_ns_tab));
  memcpy(c->ns_tab, zx_ns_tab, sizeof(zx_ns_tab));
  len = zx_LEN_SO_mm7_extendedCancelReq(c, x );
  buf = ZX_ALLOC(c, len+1);
  return zx_easy_enc_common(c, zx_ENC_SO_mm7_extendedCancelReq(c, x, buf ), buf, len);
}

/* FUNC(zx_EASY_ENC_WO_mm7_extendedCancelReq) */

/* Called by: */
struct zx_str* zx_EASY_ENC_WO_mm7_extendedCancelReq(struct zx_ctx* c, struct zx_mm7_extendedCancelReq_s* x )
{
  int len;
  char* buf;
  c->ns_tab = ZX_ALLOC(c, sizeof(zx_ns_tab));
  memcpy(c->ns_tab, zx_ns_tab, sizeof(zx_ns_tab));
  len = zx_LEN_WO_mm7_extendedCancelReq(c, x );
  buf = ZX_ALLOC(c, len+1);
  return zx_easy_enc_common(c, zx_ENC_WO_mm7_extendedCancelReq(c, x, buf ), buf, len);
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

#define EL_NAME   mm7_extendedCancelRsp
#define EL_STRUCT zx_mm7_extendedCancelRsp_s
#define EL_NS     mm7
#define EL_TAG    extendedCancelRsp

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

/* FUNC(zx_LEN_SO_mm7_extendedCancelRsp) */

/* Compute length of an element (and its subelements). The XML attributes
 * and elements are processed in schema order. */

/* Called by: */
int zx_LEN_SO_mm7_extendedCancelRsp(struct zx_ctx* c, struct zx_mm7_extendedCancelRsp_s* x )
{
  struct zx_ns_s* pop_seen = 0;
  struct zx_elem_s* se MAYBE_UNUSED;
#if 1 /* NORMALMODE */
  /* *** in simple_elem case should output ns prefix from ns node. */
  int len = sizeof("<mm7:extendedCancelRsp")-1 + 1 + sizeof("</mm7:extendedCancelRsp>")-1;
  if (c->inc_ns_len)
    len += zx_len_inc_ns(c, &pop_seen);
  len += zx_len_xmlns_if_not_seen(c, zx_ns_tab+zx_xmlns_ix_mm7, &pop_seen);


#else
  /* root node has no begin tag */
  int len = 0;
#endif
  
  for (se = x->MM7Version; se; se = (struct zx_elem_s*)se->g.n)
    len += zx_LEN_SO_simple_elem(c,se, sizeof("mm7:MM7Version")-1, zx_ns_tab+zx_xmlns_ix_mm7);
  {
      struct zx_mm7_Status_s* e;
      for (e = x->Status; e; e = (struct zx_mm7_Status_s*)e->gg.g.n)
	  len += zx_LEN_SO_mm7_Status(c, e);
  }


  len += zx_len_so_common(c, &x->gg);
  zx_pop_seen(pop_seen);
  ENC_LEN_DEBUG(x, "mm7:extendedCancelRsp", len);
  return len;
}

/* FUNC(zx_LEN_WO_mm7_extendedCancelRsp) */

/* Compute length of an element (and its subelements). The XML attributes
 * and elements are processed in wire order and no assumptions
 * are made about namespace prefixes. */

/* Called by: */
int zx_LEN_WO_mm7_extendedCancelRsp(struct zx_ctx* c, struct zx_mm7_extendedCancelRsp_s* x )
{
  struct zx_ns_s* pop_seen = 0;
  struct zx_elem_s* se MAYBE_UNUSED;
#if 1 /* NORMALMODE */
  int len = 1 + sizeof("extendedCancelRsp")-1 + 1 + 2 + sizeof("extendedCancelRsp")-1 + 1;
  
  if (x->gg.g.ns && x->gg.g.ns->prefix_len)
    len += (x->gg.g.ns->prefix_len + 1) * 2;
  if (c->inc_ns_len)
    len += zx_len_inc_ns(c, &pop_seen);
  len += zx_len_xmlns_if_not_seen(c, x->gg.g.ns, &pop_seen);


#else
  /* root node has no begin tag */
  int len = 0;
#endif
  
  for (se = x->MM7Version; se; se = (struct zx_elem_s*)se->g.n)
    len += zx_LEN_WO_simple_elem(c, se, sizeof("MM7Version")-1);
  {
      struct zx_mm7_Status_s* e;
      for (e = x->Status; e; e = (struct zx_mm7_Status_s*)e->gg.g.n)
	  len += zx_LEN_WO_mm7_Status(c, e);
  }


  len += zx_len_wo_common(c, &x->gg); 
  zx_pop_seen(pop_seen);
  ENC_LEN_DEBUG(x, "mm7:extendedCancelRsp", len);
  return len;
}

/* FUNC(zx_ENC_SO_mm7_extendedCancelRsp) */

/* Render element into string. The XML attributes and elements are
 * processed in schema order. This is what you generally want for
 * rendering new data structure to a string. The wo pointers are not used. */

/* Called by: */
char* zx_ENC_SO_mm7_extendedCancelRsp(struct zx_ctx* c, struct zx_mm7_extendedCancelRsp_s* x, char* p )
{
  struct zx_elem_s* se MAYBE_UNUSED;
  struct zx_ns_s* pop_seen = 0;
  ENC_LEN_DEBUG_BASE;
#if 1 /* NORMALMODE */
  /* *** in simple_elem case should output ns prefix from ns node. */
  ZX_OUT_TAG(p, "<mm7:extendedCancelRsp");
  if (c->inc_ns)
    p = zx_enc_inc_ns(c, p, &pop_seen);
  p = zx_enc_xmlns_if_not_seen(c, p, zx_ns_tab+zx_xmlns_ix_mm7, &pop_seen);


  p = zx_enc_unknown_attrs(p, x->gg.any_attr);
#else
  /* root node has no begin tag */
#endif
  
  for (se = x->MM7Version; se; se = (struct zx_elem_s*)se->g.n)
    p = zx_ENC_SO_simple_elem(c, se, p, "mm7:MM7Version", sizeof("mm7:MM7Version")-1, zx_ns_tab+zx_xmlns_ix_mm7);
  {
      struct zx_mm7_Status_s* e;
      for (e = x->Status; e; e = (struct zx_mm7_Status_s*)e->gg.g.n)
	  p = zx_ENC_SO_mm7_Status(c, e, p);
  }

  p = zx_enc_so_unknown_elems_and_content(c, p, &x->gg);
  
#if 1 /* NORMALMODE */
  ZX_OUT_CLOSE_TAG(p, "</mm7:extendedCancelRsp>");
  zx_pop_seen(pop_seen);
#else
  /* root node has no end tag either */
#endif
  ENC_LEN_DEBUG(x, "mm7:extendedCancelRsp", p-enc_base);
  return p;
}

/* FUNC(zx_ENC_WO_mm7_extendedCancelRsp) */

/* Render element into string. The XML attributes and elements are
 * processed in wire order by chasing wo pointers. This is what you want for
 * validating signatures on other people's XML documents. */

/* Called by: */
char* zx_ENC_WO_mm7_extendedCancelRsp(struct zx_ctx* c, struct zx_mm7_extendedCancelRsp_s* x, char* p )
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
  ZX_OUT_MEM(p, "extendedCancelRsp", sizeof("extendedCancelRsp")-1);
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
  ENC_LEN_DEBUG(x, "mm7:extendedCancelRsp", p-enc_base);
  return p;
}

/* FUNC(zx_EASY_ENC_SO_mm7_extendedCancelRsp) */

/* Called by: */
struct zx_str* zx_EASY_ENC_SO_mm7_extendedCancelRsp(struct zx_ctx* c, struct zx_mm7_extendedCancelRsp_s* x )
{
  int len;
  char* buf;
  c->ns_tab = ZX_ALLOC(c, sizeof(zx_ns_tab));
  memcpy(c->ns_tab, zx_ns_tab, sizeof(zx_ns_tab));
  len = zx_LEN_SO_mm7_extendedCancelRsp(c, x );
  buf = ZX_ALLOC(c, len+1);
  return zx_easy_enc_common(c, zx_ENC_SO_mm7_extendedCancelRsp(c, x, buf ), buf, len);
}

/* FUNC(zx_EASY_ENC_WO_mm7_extendedCancelRsp) */

/* Called by: */
struct zx_str* zx_EASY_ENC_WO_mm7_extendedCancelRsp(struct zx_ctx* c, struct zx_mm7_extendedCancelRsp_s* x )
{
  int len;
  char* buf;
  c->ns_tab = ZX_ALLOC(c, sizeof(zx_ns_tab));
  memcpy(c->ns_tab, zx_ns_tab, sizeof(zx_ns_tab));
  len = zx_LEN_WO_mm7_extendedCancelRsp(c, x );
  buf = ZX_ALLOC(c, len+1);
  return zx_easy_enc_common(c, zx_ENC_WO_mm7_extendedCancelRsp(c, x, buf ), buf, len);
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

#define EL_NAME   mm7_extendedReplaceReq
#define EL_STRUCT zx_mm7_extendedReplaceReq_s
#define EL_NS     mm7
#define EL_TAG    extendedReplaceReq

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

/* FUNC(zx_LEN_SO_mm7_extendedReplaceReq) */

/* Compute length of an element (and its subelements). The XML attributes
 * and elements are processed in schema order. */

/* Called by: */
int zx_LEN_SO_mm7_extendedReplaceReq(struct zx_ctx* c, struct zx_mm7_extendedReplaceReq_s* x )
{
  struct zx_ns_s* pop_seen = 0;
  struct zx_elem_s* se MAYBE_UNUSED;
#if 1 /* NORMALMODE */
  /* *** in simple_elem case should output ns prefix from ns node. */
  int len = sizeof("<mm7:extendedReplaceReq")-1 + 1 + sizeof("</mm7:extendedReplaceReq>")-1;
  if (c->inc_ns_len)
    len += zx_len_inc_ns(c, &pop_seen);
  len += zx_len_xmlns_if_not_seen(c, zx_ns_tab+zx_xmlns_ix_mm7, &pop_seen);


#else
  /* root node has no begin tag */
  int len = 0;
#endif
  
  for (se = x->MM7Version; se; se = (struct zx_elem_s*)se->g.n)
    len += zx_LEN_SO_simple_elem(c,se, sizeof("mm7:MM7Version")-1, zx_ns_tab+zx_xmlns_ix_mm7);
  for (se = x->VASPID; se; se = (struct zx_elem_s*)se->g.n)
    len += zx_LEN_SO_simple_elem(c,se, sizeof("mm7:VASPID")-1, zx_ns_tab+zx_xmlns_ix_mm7);
  for (se = x->VASID; se; se = (struct zx_elem_s*)se->g.n)
    len += zx_LEN_SO_simple_elem(c,se, sizeof("mm7:VASID")-1, zx_ns_tab+zx_xmlns_ix_mm7);
  {
      struct zx_mm7_ServiceCode_s* e;
      for (e = x->ServiceCode; e; e = (struct zx_mm7_ServiceCode_s*)e->gg.g.n)
	  len += zx_LEN_SO_mm7_ServiceCode(c, e);
  }
  for (se = x->ReplaceID; se; se = (struct zx_elem_s*)se->g.n)
    len += zx_LEN_SO_simple_elem(c,se, sizeof("mm7:ReplaceID")-1, zx_ns_tab+zx_xmlns_ix_mm7);
  for (se = x->TimeStamp; se; se = (struct zx_elem_s*)se->g.n)
    len += zx_LEN_SO_simple_elem(c,se, sizeof("mm7:TimeStamp")-1, zx_ns_tab+zx_xmlns_ix_mm7);
  for (se = x->EarliestDeliveryTime; se; se = (struct zx_elem_s*)se->g.n)
    len += zx_LEN_SO_simple_elem(c,se, sizeof("mm7:EarliestDeliveryTime")-1, zx_ns_tab+zx_xmlns_ix_mm7);
  for (se = x->ExpiryDate; se; se = (struct zx_elem_s*)se->g.n)
    len += zx_LEN_SO_simple_elem(c,se, sizeof("mm7:ExpiryDate")-1, zx_ns_tab+zx_xmlns_ix_mm7);
  for (se = x->ReadReply; se; se = (struct zx_elem_s*)se->g.n)
    len += zx_LEN_SO_simple_elem(c,se, sizeof("mm7:ReadReply")-1, zx_ns_tab+zx_xmlns_ix_mm7);
  for (se = x->DeliveryReport; se; se = (struct zx_elem_s*)se->g.n)
    len += zx_LEN_SO_simple_elem(c,se, sizeof("mm7:DeliveryReport")-1, zx_ns_tab+zx_xmlns_ix_mm7);
  {
      struct zx_mm7_Content_s* e;
      for (e = x->Content; e; e = (struct zx_mm7_Content_s*)e->gg.g.n)
	  len += zx_LEN_SO_mm7_Content(c, e);
  }
  {
      struct zx_mm7_AdditionalInformation_s* e;
      for (e = x->AdditionalInformation; e; e = (struct zx_mm7_AdditionalInformation_s*)e->gg.g.n)
	  len += zx_LEN_SO_mm7_AdditionalInformation(c, e);
  }
  {
      struct zx_mm7_MessageExtraData_s* e;
      for (e = x->MessageExtraData; e; e = (struct zx_mm7_MessageExtraData_s*)e->gg.g.n)
	  len += zx_LEN_SO_mm7_MessageExtraData(c, e);
  }


  len += zx_len_so_common(c, &x->gg);
  zx_pop_seen(pop_seen);
  ENC_LEN_DEBUG(x, "mm7:extendedReplaceReq", len);
  return len;
}

/* FUNC(zx_LEN_WO_mm7_extendedReplaceReq) */

/* Compute length of an element (and its subelements). The XML attributes
 * and elements are processed in wire order and no assumptions
 * are made about namespace prefixes. */

/* Called by: */
int zx_LEN_WO_mm7_extendedReplaceReq(struct zx_ctx* c, struct zx_mm7_extendedReplaceReq_s* x )
{
  struct zx_ns_s* pop_seen = 0;
  struct zx_elem_s* se MAYBE_UNUSED;
#if 1 /* NORMALMODE */
  int len = 1 + sizeof("extendedReplaceReq")-1 + 1 + 2 + sizeof("extendedReplaceReq")-1 + 1;
  
  if (x->gg.g.ns && x->gg.g.ns->prefix_len)
    len += (x->gg.g.ns->prefix_len + 1) * 2;
  if (c->inc_ns_len)
    len += zx_len_inc_ns(c, &pop_seen);
  len += zx_len_xmlns_if_not_seen(c, x->gg.g.ns, &pop_seen);


#else
  /* root node has no begin tag */
  int len = 0;
#endif
  
  for (se = x->MM7Version; se; se = (struct zx_elem_s*)se->g.n)
    len += zx_LEN_WO_simple_elem(c, se, sizeof("MM7Version")-1);
  for (se = x->VASPID; se; se = (struct zx_elem_s*)se->g.n)
    len += zx_LEN_WO_simple_elem(c, se, sizeof("VASPID")-1);
  for (se = x->VASID; se; se = (struct zx_elem_s*)se->g.n)
    len += zx_LEN_WO_simple_elem(c, se, sizeof("VASID")-1);
  {
      struct zx_mm7_ServiceCode_s* e;
      for (e = x->ServiceCode; e; e = (struct zx_mm7_ServiceCode_s*)e->gg.g.n)
	  len += zx_LEN_WO_mm7_ServiceCode(c, e);
  }
  for (se = x->ReplaceID; se; se = (struct zx_elem_s*)se->g.n)
    len += zx_LEN_WO_simple_elem(c, se, sizeof("ReplaceID")-1);
  for (se = x->TimeStamp; se; se = (struct zx_elem_s*)se->g.n)
    len += zx_LEN_WO_simple_elem(c, se, sizeof("TimeStamp")-1);
  for (se = x->EarliestDeliveryTime; se; se = (struct zx_elem_s*)se->g.n)
    len += zx_LEN_WO_simple_elem(c, se, sizeof("EarliestDeliveryTime")-1);
  for (se = x->ExpiryDate; se; se = (struct zx_elem_s*)se->g.n)
    len += zx_LEN_WO_simple_elem(c, se, sizeof("ExpiryDate")-1);
  for (se = x->ReadReply; se; se = (struct zx_elem_s*)se->g.n)
    len += zx_LEN_WO_simple_elem(c, se, sizeof("ReadReply")-1);
  for (se = x->DeliveryReport; se; se = (struct zx_elem_s*)se->g.n)
    len += zx_LEN_WO_simple_elem(c, se, sizeof("DeliveryReport")-1);
  {
      struct zx_mm7_Content_s* e;
      for (e = x->Content; e; e = (struct zx_mm7_Content_s*)e->gg.g.n)
	  len += zx_LEN_WO_mm7_Content(c, e);
  }
  {
      struct zx_mm7_AdditionalInformation_s* e;
      for (e = x->AdditionalInformation; e; e = (struct zx_mm7_AdditionalInformation_s*)e->gg.g.n)
	  len += zx_LEN_WO_mm7_AdditionalInformation(c, e);
  }
  {
      struct zx_mm7_MessageExtraData_s* e;
      for (e = x->MessageExtraData; e; e = (struct zx_mm7_MessageExtraData_s*)e->gg.g.n)
	  len += zx_LEN_WO_mm7_MessageExtraData(c, e);
  }


  len += zx_len_wo_common(c, &x->gg); 
  zx_pop_seen(pop_seen);
  ENC_LEN_DEBUG(x, "mm7:extendedReplaceReq", len);
  return len;
}

/* FUNC(zx_ENC_SO_mm7_extendedReplaceReq) */

/* Render element into string. The XML attributes and elements are
 * processed in schema order. This is what you generally want for
 * rendering new data structure to a string. The wo pointers are not used. */

/* Called by: */
char* zx_ENC_SO_mm7_extendedReplaceReq(struct zx_ctx* c, struct zx_mm7_extendedReplaceReq_s* x, char* p )
{
  struct zx_elem_s* se MAYBE_UNUSED;
  struct zx_ns_s* pop_seen = 0;
  ENC_LEN_DEBUG_BASE;
#if 1 /* NORMALMODE */
  /* *** in simple_elem case should output ns prefix from ns node. */
  ZX_OUT_TAG(p, "<mm7:extendedReplaceReq");
  if (c->inc_ns)
    p = zx_enc_inc_ns(c, p, &pop_seen);
  p = zx_enc_xmlns_if_not_seen(c, p, zx_ns_tab+zx_xmlns_ix_mm7, &pop_seen);


  p = zx_enc_unknown_attrs(p, x->gg.any_attr);
#else
  /* root node has no begin tag */
#endif
  
  for (se = x->MM7Version; se; se = (struct zx_elem_s*)se->g.n)
    p = zx_ENC_SO_simple_elem(c, se, p, "mm7:MM7Version", sizeof("mm7:MM7Version")-1, zx_ns_tab+zx_xmlns_ix_mm7);
  for (se = x->VASPID; se; se = (struct zx_elem_s*)se->g.n)
    p = zx_ENC_SO_simple_elem(c, se, p, "mm7:VASPID", sizeof("mm7:VASPID")-1, zx_ns_tab+zx_xmlns_ix_mm7);
  for (se = x->VASID; se; se = (struct zx_elem_s*)se->g.n)
    p = zx_ENC_SO_simple_elem(c, se, p, "mm7:VASID", sizeof("mm7:VASID")-1, zx_ns_tab+zx_xmlns_ix_mm7);
  {
      struct zx_mm7_ServiceCode_s* e;
      for (e = x->ServiceCode; e; e = (struct zx_mm7_ServiceCode_s*)e->gg.g.n)
	  p = zx_ENC_SO_mm7_ServiceCode(c, e, p);
  }
  for (se = x->ReplaceID; se; se = (struct zx_elem_s*)se->g.n)
    p = zx_ENC_SO_simple_elem(c, se, p, "mm7:ReplaceID", sizeof("mm7:ReplaceID")-1, zx_ns_tab+zx_xmlns_ix_mm7);
  for (se = x->TimeStamp; se; se = (struct zx_elem_s*)se->g.n)
    p = zx_ENC_SO_simple_elem(c, se, p, "mm7:TimeStamp", sizeof("mm7:TimeStamp")-1, zx_ns_tab+zx_xmlns_ix_mm7);
  for (se = x->EarliestDeliveryTime; se; se = (struct zx_elem_s*)se->g.n)
    p = zx_ENC_SO_simple_elem(c, se, p, "mm7:EarliestDeliveryTime", sizeof("mm7:EarliestDeliveryTime")-1, zx_ns_tab+zx_xmlns_ix_mm7);
  for (se = x->ExpiryDate; se; se = (struct zx_elem_s*)se->g.n)
    p = zx_ENC_SO_simple_elem(c, se, p, "mm7:ExpiryDate", sizeof("mm7:ExpiryDate")-1, zx_ns_tab+zx_xmlns_ix_mm7);
  for (se = x->ReadReply; se; se = (struct zx_elem_s*)se->g.n)
    p = zx_ENC_SO_simple_elem(c, se, p, "mm7:ReadReply", sizeof("mm7:ReadReply")-1, zx_ns_tab+zx_xmlns_ix_mm7);
  for (se = x->DeliveryReport; se; se = (struct zx_elem_s*)se->g.n)
    p = zx_ENC_SO_simple_elem(c, se, p, "mm7:DeliveryReport", sizeof("mm7:DeliveryReport")-1, zx_ns_tab+zx_xmlns_ix_mm7);
  {
      struct zx_mm7_Content_s* e;
      for (e = x->Content; e; e = (struct zx_mm7_Content_s*)e->gg.g.n)
	  p = zx_ENC_SO_mm7_Content(c, e, p);
  }
  {
      struct zx_mm7_AdditionalInformation_s* e;
      for (e = x->AdditionalInformation; e; e = (struct zx_mm7_AdditionalInformation_s*)e->gg.g.n)
	  p = zx_ENC_SO_mm7_AdditionalInformation(c, e, p);
  }
  {
      struct zx_mm7_MessageExtraData_s* e;
      for (e = x->MessageExtraData; e; e = (struct zx_mm7_MessageExtraData_s*)e->gg.g.n)
	  p = zx_ENC_SO_mm7_MessageExtraData(c, e, p);
  }

  p = zx_enc_so_unknown_elems_and_content(c, p, &x->gg);
  
#if 1 /* NORMALMODE */
  ZX_OUT_CLOSE_TAG(p, "</mm7:extendedReplaceReq>");
  zx_pop_seen(pop_seen);
#else
  /* root node has no end tag either */
#endif
  ENC_LEN_DEBUG(x, "mm7:extendedReplaceReq", p-enc_base);
  return p;
}

/* FUNC(zx_ENC_WO_mm7_extendedReplaceReq) */

/* Render element into string. The XML attributes and elements are
 * processed in wire order by chasing wo pointers. This is what you want for
 * validating signatures on other people's XML documents. */

/* Called by: */
char* zx_ENC_WO_mm7_extendedReplaceReq(struct zx_ctx* c, struct zx_mm7_extendedReplaceReq_s* x, char* p )
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
  ZX_OUT_MEM(p, "extendedReplaceReq", sizeof("extendedReplaceReq")-1);
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
  ENC_LEN_DEBUG(x, "mm7:extendedReplaceReq", p-enc_base);
  return p;
}

/* FUNC(zx_EASY_ENC_SO_mm7_extendedReplaceReq) */

/* Called by: */
struct zx_str* zx_EASY_ENC_SO_mm7_extendedReplaceReq(struct zx_ctx* c, struct zx_mm7_extendedReplaceReq_s* x )
{
  int len;
  char* buf;
  c->ns_tab = ZX_ALLOC(c, sizeof(zx_ns_tab));
  memcpy(c->ns_tab, zx_ns_tab, sizeof(zx_ns_tab));
  len = zx_LEN_SO_mm7_extendedReplaceReq(c, x );
  buf = ZX_ALLOC(c, len+1);
  return zx_easy_enc_common(c, zx_ENC_SO_mm7_extendedReplaceReq(c, x, buf ), buf, len);
}

/* FUNC(zx_EASY_ENC_WO_mm7_extendedReplaceReq) */

/* Called by: */
struct zx_str* zx_EASY_ENC_WO_mm7_extendedReplaceReq(struct zx_ctx* c, struct zx_mm7_extendedReplaceReq_s* x )
{
  int len;
  char* buf;
  c->ns_tab = ZX_ALLOC(c, sizeof(zx_ns_tab));
  memcpy(c->ns_tab, zx_ns_tab, sizeof(zx_ns_tab));
  len = zx_LEN_WO_mm7_extendedReplaceReq(c, x );
  buf = ZX_ALLOC(c, len+1);
  return zx_easy_enc_common(c, zx_ENC_WO_mm7_extendedReplaceReq(c, x, buf ), buf, len);
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

#define EL_NAME   mm7_extendedReplaceRsp
#define EL_STRUCT zx_mm7_extendedReplaceRsp_s
#define EL_NS     mm7
#define EL_TAG    extendedReplaceRsp

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

/* FUNC(zx_LEN_SO_mm7_extendedReplaceRsp) */

/* Compute length of an element (and its subelements). The XML attributes
 * and elements are processed in schema order. */

/* Called by: */
int zx_LEN_SO_mm7_extendedReplaceRsp(struct zx_ctx* c, struct zx_mm7_extendedReplaceRsp_s* x )
{
  struct zx_ns_s* pop_seen = 0;
  struct zx_elem_s* se MAYBE_UNUSED;
#if 1 /* NORMALMODE */
  /* *** in simple_elem case should output ns prefix from ns node. */
  int len = sizeof("<mm7:extendedReplaceRsp")-1 + 1 + sizeof("</mm7:extendedReplaceRsp>")-1;
  if (c->inc_ns_len)
    len += zx_len_inc_ns(c, &pop_seen);
  len += zx_len_xmlns_if_not_seen(c, zx_ns_tab+zx_xmlns_ix_mm7, &pop_seen);


#else
  /* root node has no begin tag */
  int len = 0;
#endif
  
  for (se = x->MM7Version; se; se = (struct zx_elem_s*)se->g.n)
    len += zx_LEN_SO_simple_elem(c,se, sizeof("mm7:MM7Version")-1, zx_ns_tab+zx_xmlns_ix_mm7);
  for (se = x->MessageID; se; se = (struct zx_elem_s*)se->g.n)
    len += zx_LEN_SO_simple_elem(c,se, sizeof("mm7:MessageID")-1, zx_ns_tab+zx_xmlns_ix_mm7);
  {
      struct zx_mm7_Status_s* e;
      for (e = x->Status; e; e = (struct zx_mm7_Status_s*)e->gg.g.n)
	  len += zx_LEN_SO_mm7_Status(c, e);
  }


  len += zx_len_so_common(c, &x->gg);
  zx_pop_seen(pop_seen);
  ENC_LEN_DEBUG(x, "mm7:extendedReplaceRsp", len);
  return len;
}

/* FUNC(zx_LEN_WO_mm7_extendedReplaceRsp) */

/* Compute length of an element (and its subelements). The XML attributes
 * and elements are processed in wire order and no assumptions
 * are made about namespace prefixes. */

/* Called by: */
int zx_LEN_WO_mm7_extendedReplaceRsp(struct zx_ctx* c, struct zx_mm7_extendedReplaceRsp_s* x )
{
  struct zx_ns_s* pop_seen = 0;
  struct zx_elem_s* se MAYBE_UNUSED;
#if 1 /* NORMALMODE */
  int len = 1 + sizeof("extendedReplaceRsp")-1 + 1 + 2 + sizeof("extendedReplaceRsp")-1 + 1;
  
  if (x->gg.g.ns && x->gg.g.ns->prefix_len)
    len += (x->gg.g.ns->prefix_len + 1) * 2;
  if (c->inc_ns_len)
    len += zx_len_inc_ns(c, &pop_seen);
  len += zx_len_xmlns_if_not_seen(c, x->gg.g.ns, &pop_seen);


#else
  /* root node has no begin tag */
  int len = 0;
#endif
  
  for (se = x->MM7Version; se; se = (struct zx_elem_s*)se->g.n)
    len += zx_LEN_WO_simple_elem(c, se, sizeof("MM7Version")-1);
  for (se = x->MessageID; se; se = (struct zx_elem_s*)se->g.n)
    len += zx_LEN_WO_simple_elem(c, se, sizeof("MessageID")-1);
  {
      struct zx_mm7_Status_s* e;
      for (e = x->Status; e; e = (struct zx_mm7_Status_s*)e->gg.g.n)
	  len += zx_LEN_WO_mm7_Status(c, e);
  }


  len += zx_len_wo_common(c, &x->gg); 
  zx_pop_seen(pop_seen);
  ENC_LEN_DEBUG(x, "mm7:extendedReplaceRsp", len);
  return len;
}

/* FUNC(zx_ENC_SO_mm7_extendedReplaceRsp) */

/* Render element into string. The XML attributes and elements are
 * processed in schema order. This is what you generally want for
 * rendering new data structure to a string. The wo pointers are not used. */

/* Called by: */
char* zx_ENC_SO_mm7_extendedReplaceRsp(struct zx_ctx* c, struct zx_mm7_extendedReplaceRsp_s* x, char* p )
{
  struct zx_elem_s* se MAYBE_UNUSED;
  struct zx_ns_s* pop_seen = 0;
  ENC_LEN_DEBUG_BASE;
#if 1 /* NORMALMODE */
  /* *** in simple_elem case should output ns prefix from ns node. */
  ZX_OUT_TAG(p, "<mm7:extendedReplaceRsp");
  if (c->inc_ns)
    p = zx_enc_inc_ns(c, p, &pop_seen);
  p = zx_enc_xmlns_if_not_seen(c, p, zx_ns_tab+zx_xmlns_ix_mm7, &pop_seen);


  p = zx_enc_unknown_attrs(p, x->gg.any_attr);
#else
  /* root node has no begin tag */
#endif
  
  for (se = x->MM7Version; se; se = (struct zx_elem_s*)se->g.n)
    p = zx_ENC_SO_simple_elem(c, se, p, "mm7:MM7Version", sizeof("mm7:MM7Version")-1, zx_ns_tab+zx_xmlns_ix_mm7);
  for (se = x->MessageID; se; se = (struct zx_elem_s*)se->g.n)
    p = zx_ENC_SO_simple_elem(c, se, p, "mm7:MessageID", sizeof("mm7:MessageID")-1, zx_ns_tab+zx_xmlns_ix_mm7);
  {
      struct zx_mm7_Status_s* e;
      for (e = x->Status; e; e = (struct zx_mm7_Status_s*)e->gg.g.n)
	  p = zx_ENC_SO_mm7_Status(c, e, p);
  }

  p = zx_enc_so_unknown_elems_and_content(c, p, &x->gg);
  
#if 1 /* NORMALMODE */
  ZX_OUT_CLOSE_TAG(p, "</mm7:extendedReplaceRsp>");
  zx_pop_seen(pop_seen);
#else
  /* root node has no end tag either */
#endif
  ENC_LEN_DEBUG(x, "mm7:extendedReplaceRsp", p-enc_base);
  return p;
}

/* FUNC(zx_ENC_WO_mm7_extendedReplaceRsp) */

/* Render element into string. The XML attributes and elements are
 * processed in wire order by chasing wo pointers. This is what you want for
 * validating signatures on other people's XML documents. */

/* Called by: */
char* zx_ENC_WO_mm7_extendedReplaceRsp(struct zx_ctx* c, struct zx_mm7_extendedReplaceRsp_s* x, char* p )
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
  ZX_OUT_MEM(p, "extendedReplaceRsp", sizeof("extendedReplaceRsp")-1);
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
  ENC_LEN_DEBUG(x, "mm7:extendedReplaceRsp", p-enc_base);
  return p;
}

/* FUNC(zx_EASY_ENC_SO_mm7_extendedReplaceRsp) */

/* Called by: */
struct zx_str* zx_EASY_ENC_SO_mm7_extendedReplaceRsp(struct zx_ctx* c, struct zx_mm7_extendedReplaceRsp_s* x )
{
  int len;
  char* buf;
  c->ns_tab = ZX_ALLOC(c, sizeof(zx_ns_tab));
  memcpy(c->ns_tab, zx_ns_tab, sizeof(zx_ns_tab));
  len = zx_LEN_SO_mm7_extendedReplaceRsp(c, x );
  buf = ZX_ALLOC(c, len+1);
  return zx_easy_enc_common(c, zx_ENC_SO_mm7_extendedReplaceRsp(c, x, buf ), buf, len);
}

/* FUNC(zx_EASY_ENC_WO_mm7_extendedReplaceRsp) */

/* Called by: */
struct zx_str* zx_EASY_ENC_WO_mm7_extendedReplaceRsp(struct zx_ctx* c, struct zx_mm7_extendedReplaceRsp_s* x )
{
  int len;
  char* buf;
  c->ns_tab = ZX_ALLOC(c, sizeof(zx_ns_tab));
  memcpy(c->ns_tab, zx_ns_tab, sizeof(zx_ns_tab));
  len = zx_LEN_WO_mm7_extendedReplaceRsp(c, x );
  buf = ZX_ALLOC(c, len+1);
  return zx_easy_enc_common(c, zx_ENC_WO_mm7_extendedReplaceRsp(c, x, buf ), buf, len);
}




/* EOF -- c/zx-mm7-enc.c */
