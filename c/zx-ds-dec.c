/* c/zx-ds-dec.c - WARNING: This file was automatically generated. DO NOT EDIT!
 * $Id$ */
/* Code generation design Copyright (c) 2006 Sampo Kellomaki (sampo@iki.fi),
 * All Rights Reserved. NO WARRANTY. See file COPYING for terms and conditions
 * of use. Some aspects of code generation were driven by schema
 * descriptions that were used as input and may be subject to their own copyright.
 * Code generation uses a template, whose copyright statement follows. */

/** dec-templ.c  -  XML decoder template, used in code generation
 ** Copyright (c) 2010 Sampo Kellomaki (sampo@iki.fi), All Rights Reserved.
 ** Copyright (c) 2006-2007 Symlabs (symlabs@symlabs.com), All Rights Reserved.
 ** Author: Sampo Kellomaki (sampo@iki.fi)
 ** This is confidential unpublished proprietary source code of the author.
 ** NO WARRANTY, not even implied warranties. Contains trade secrets.
 ** Distribution prohibited unless authorized in writing.
 ** Licensed under Apache License 2.0, see file COPYING.
 ** Id: dec-templ.c,v 1.30 2008-10-04 23:42:14 sampo Exp $
 **
 ** 28.5.2006, created, Sampo Kellomaki (sampo@iki.fi)
 ** 8.8.2006,  reworked namespace handling --Sampo
 ** 12.8.2006, added special scanning of xmlns to avoid backtracking elem recognition --Sampo
 ** 23.9.2006, added collection of WO information --Sampo
 ** 21.6.2007, improved handling of undeclared namespace prefixes --Sampo
 **
 ** N.B: This template is meant to be processed by pd/xsd2sg.pl. Beware
 ** of special markers that xsd2sg.pl expects to find and understand.
 **/

#include "errmac.h"
#include "zx.h"
#include "c/zx-const.h"
#include "c/zx-data.h"
#include "c/zx-ds-data.h"

#define TPF zx_

#ifndef ZX_ATTR_DEC_EXT
#define ZX_ATTR_DEC_EXT(ss)  /* Extension point called just after decoding known attribute */
#endif

#ifndef ZX_XMLNS_DEC_EXT
#define ZX_XMLNS_DEC_EXT(ss) /* Extension point called just after decoding xmlns attribute */
#endif

#ifndef ZX_UNKNOWN_ATTR_DEC_EXT
#define ZX_UNKNOWN_ATTR_DEC_EXT(ss) /* Extension point called just after decoding unknown attr */
#endif

#ifndef ZX_START_DEC_EXT
#define ZX_START_DEC_EXT(x) /* Extension point called just after decoding element name and allocating struct, but before decoding any of the attributes. */
#endif

#ifndef ZX_END_DEC_EXT
#define ZX_END_DEC_EXT(x) /* Extension point called just after decoding the entire element. */
#endif

#ifndef ZX_START_BODY_DEC_EXT
#define ZX_START_BODY_DEC_EXT(x) /* Extension point called just after decoding element tag, including attributes, but before decoding the body of the element. */
#endif

#ifndef ZX_PI_DEC_EXT
#define ZX_PI_DEC_EXT(pi) /* Extension point called just after decoding processing instruction */
#endif

#ifndef ZX_COMMENT_DEC_EXT
#define ZX_COMMENT_DEC_EXT(comment) /* Extension point called just after decoding comment */
#endif

#ifndef ZX_CONTENT_DEC
#define ZX_CONTENT_DEC(ss) /* Extension point called just after decoding string content */
#endif

#ifndef ZX_UNKNOWN_ELEM_DEC_EXT
#define ZX_UNKNOWN_ELEM_DEC_EXT(elem) /* Extension point called just after decoding unknown element */
#endif



/* FUNC(zx_DEC_ds_CanonicalizationMethod) */

#define EL_NAME   ds_CanonicalizationMethod
#define EL_STRUCT zx_ds_CanonicalizationMethod_s
#define EL_NS     ds
#define EL_TAG    CanonicalizationMethod

/* Called by: */
struct zx_ds_CanonicalizationMethod_s* zx_DEC_ds_CanonicalizationMethod(struct zx_ctx* c, struct zx_ns_s* ns )
{
  int tok;
  struct zx_elem_s* iternode;
  struct zx_elem_s* el;
  struct zx_str* ss;
  struct zx_ns_s* pop_seen;
  const char* name;
  const char* data;
  struct zx_ds_CanonicalizationMethod_s* x = ZX_ZALLOC(c, struct zx_ds_CanonicalizationMethod_s);
  x->gg.g.tok = zx_ds_CanonicalizationMethod_ELEM;
  x->gg.g.ns = ns;
  ZX_START_DEC_EXT(x);

#if 1 /* NORMALMODE */
  ZX_DEC_TAG_NOT_YET_CLOSED(x->gg.g);

  /* The tag name has already been detected. Process attributes until '>' */
  
  for (; c->p; ++c->p) {
    ZX_SKIP_WS(c,x);
    if (ONE_OF_2(*c->p, '>', '/'))
      break;
    if (!(data = zx_dec_attr_val(c, &name))) {
      D("Decoding attr_val failed %p", c->p);
      return x;
    }
    tok = zx_attr_lookup(c, name, data-2, &ns);
    switch (tok) {
    case zx_Algorithm_ATTR:
      ss = ZX_ZALLOC(c, struct zx_str);
      ss->g.n = &x->Algorithm->g;
      x->Algorithm = ss;
      ZX_ATTR_DEC_EXT(ss);
      break;

    case ZX_TOK_XMLNS:
      ZX_XMLNS_DEC_EXT(ss);
      DD("xmlns detected(%.*s)", data-2-name, name);
      goto next_attr;
    default:
      ss = zx_dec_unknown_attr(c, &x->gg, name, data, tok, x->gg.g.tok);
    }
    ss->g.ns = ns;
    ss->g.tok = tok;
    ss->g.err |= ZXERR_ATTR_FLAG;
    ss->len = c->p - data;
    ss->s = (char*)data;
next_attr:
    continue;
  }
  if (c->p) {
    ++c->p;
    if (c->p[-1] == '/' && c->p[0] == '>') {  /* Tag without content */
      ++c->p;
      ZX_DEC_TAG_NOW_CLOSED(x->gg.g);
      goto out;
    }
  }
#endif

  /* Process contents until '</' */
  
  ZX_START_BODY_DEC_EXT(x);
  
  while (c->p) {
  next_elem:
    /*ZX_SKIP_WS(c,x);    DO NOT SQUASH WS! EXC-CANON NEEDS IT. */
    if (*c->p == '<') {
    potential_tag:
      ++c->p;
      switch (*c->p) {
      case '?':  /* processing instruction <?xml ... ?> */
      case '!':  /* comment <!-- ... --> */
	if (zx_scan_pi_or_comment(c))
	  break;
	goto next_elem;
      case '/':  /* close tag */
	++c->p;
	name = c->p;
	ZX_LOOK_FOR(c,'>');
#if defined(DEC_WRONG_ELEM)
	if (x->gg.g.ns->prefix_len
	    ?(c->p - name - x->gg.g.ns->prefix_len - 1 != namlen || memcmp(name+x->gg.g.ns->prefix_len+1, nam, namlen))
	    :(c->p-name != namlen || memcmp(name, nam, namlen)))
#else
	tok = zx_elem_lookup(c, name, c->p, &ns);
	if (tok != x->gg.g.tok)
#endif
	{
	  ERR("Mismatching close tag(%.*s) tok=%d context=%d", c->p-name, name, tok, x->gg.g.tok);
	  zx_xml_parse_err(c, '-', (const char*)__FUNCTION__, "Mismatching close tag");
	  ZX_DEC_TAG_MISMATCH_CLOSE(x->gg.g);
	  ++c->p;
	  return x;
	}
	/* Legitimate close tag. Normal exit from this function. */
	++c->p;
	ZX_DEC_TAG_NOW_CLOSED(x->gg.g);
	goto out;
      default:
	if (A_Z_a_z_(*c->p)) {
	  name = c->p;
	  for (++c->p; *c->p && !ONE_OF_6(*c->p, ' ', '>', '/', '\n', '\r', '\t'); ++c->p) ;
	  if (!*c->p) {
	    D("Incomplete %s", name);
	    return x;
	  }
	  pop_seen = zx_scan_xmlns(c);  /* Prescan namespaces so that token can be correctly recognized. */
	  tok = zx_elem_lookup(c, name, c->p, &ns);
	  switch (tok) {

	  default:
	    el = zx_known_or_unknown_elem(c, tok, &x->gg, c->p - name, name, ns);
	    tok = ZX_TOK_NOT_FOUND;
	    break;
	  }
          el->g.wo = &x->gg.kids->g;
          x->gg.kids = el;
	  zx_pop_seen(pop_seen);
	  
	  goto next_elem;
	}
      }
      /* false alarm <, fall thru */
    }
    if (!zx_scan_data(c, &x->gg))
      return x;
    goto potential_tag;
  }
 out:
  iternode = x->gg.kids;
  REVERSE_LIST_NEXT(x->gg.kids, iternode, g.wo);
  iternode = (struct zx_elem_s*)(x->gg.any_elem);
  REVERSE_LIST_NEXT(x->gg.any_elem, iternode, g.n);
  ss = (struct zx_str*)(x->gg.any_attr);
  REVERSE_LIST_NEXT(x->gg.any_attr, ss, g.n);
  ZX_END_DEC_EXT(x);
  return x;

 look_for_not_found:
  zx_xml_parse_err(c, '>', (const char*)__FUNCTION__, "char not found");
  return x;
}

#undef EL_NAME
#undef EL_STRUCT
#undef EL_NS
#undef EL_TAG






/* FUNC(zx_DEC_ds_DSAKeyValue) */

#define EL_NAME   ds_DSAKeyValue
#define EL_STRUCT zx_ds_DSAKeyValue_s
#define EL_NS     ds
#define EL_TAG    DSAKeyValue

/* Called by: */
struct zx_ds_DSAKeyValue_s* zx_DEC_ds_DSAKeyValue(struct zx_ctx* c, struct zx_ns_s* ns )
{
  int tok;
  struct zx_elem_s* iternode;
  struct zx_elem_s* el;
  struct zx_str* ss;
  struct zx_ns_s* pop_seen;
  const char* name;
  const char* data;
  struct zx_ds_DSAKeyValue_s* x = ZX_ZALLOC(c, struct zx_ds_DSAKeyValue_s);
  x->gg.g.tok = zx_ds_DSAKeyValue_ELEM;
  x->gg.g.ns = ns;
  ZX_START_DEC_EXT(x);

#if 1 /* NORMALMODE */
  ZX_DEC_TAG_NOT_YET_CLOSED(x->gg.g);

  /* The tag name has already been detected. Process attributes until '>' */
  
  for (; c->p; ++c->p) {
    ZX_SKIP_WS(c,x);
    if (ONE_OF_2(*c->p, '>', '/'))
      break;
    if (!(data = zx_dec_attr_val(c, &name))) {
      D("Decoding attr_val failed %p", c->p);
      return x;
    }
    tok = zx_attr_lookup(c, name, data-2, &ns);
    switch (tok) {

    case ZX_TOK_XMLNS:
      ZX_XMLNS_DEC_EXT(ss);
      DD("xmlns detected(%.*s)", data-2-name, name);
      goto next_attr;
    default:
      ss = zx_dec_unknown_attr(c, &x->gg, name, data, tok, x->gg.g.tok);
    }
    ss->g.ns = ns;
    ss->g.tok = tok;
    ss->g.err |= ZXERR_ATTR_FLAG;
    ss->len = c->p - data;
    ss->s = (char*)data;
next_attr:
    continue;
  }
  if (c->p) {
    ++c->p;
    if (c->p[-1] == '/' && c->p[0] == '>') {  /* Tag without content */
      ++c->p;
      ZX_DEC_TAG_NOW_CLOSED(x->gg.g);
      goto out;
    }
  }
#endif

  /* Process contents until '</' */
  
  ZX_START_BODY_DEC_EXT(x);
  
  while (c->p) {
  next_elem:
    /*ZX_SKIP_WS(c,x);    DO NOT SQUASH WS! EXC-CANON NEEDS IT. */
    if (*c->p == '<') {
    potential_tag:
      ++c->p;
      switch (*c->p) {
      case '?':  /* processing instruction <?xml ... ?> */
      case '!':  /* comment <!-- ... --> */
	if (zx_scan_pi_or_comment(c))
	  break;
	goto next_elem;
      case '/':  /* close tag */
	++c->p;
	name = c->p;
	ZX_LOOK_FOR(c,'>');
#if defined(DEC_WRONG_ELEM)
	if (x->gg.g.ns->prefix_len
	    ?(c->p - name - x->gg.g.ns->prefix_len - 1 != namlen || memcmp(name+x->gg.g.ns->prefix_len+1, nam, namlen))
	    :(c->p-name != namlen || memcmp(name, nam, namlen)))
#else
	tok = zx_elem_lookup(c, name, c->p, &ns);
	if (tok != x->gg.g.tok)
#endif
	{
	  ERR("Mismatching close tag(%.*s) tok=%d context=%d", c->p-name, name, tok, x->gg.g.tok);
	  zx_xml_parse_err(c, '-', (const char*)__FUNCTION__, "Mismatching close tag");
	  ZX_DEC_TAG_MISMATCH_CLOSE(x->gg.g);
	  ++c->p;
	  return x;
	}
	/* Legitimate close tag. Normal exit from this function. */
	++c->p;
	ZX_DEC_TAG_NOW_CLOSED(x->gg.g);
	goto out;
      default:
	if (A_Z_a_z_(*c->p)) {
	  name = c->p;
	  for (++c->p; *c->p && !ONE_OF_6(*c->p, ' ', '>', '/', '\n', '\r', '\t'); ++c->p) ;
	  if (!*c->p) {
	    D("Incomplete %s", name);
	    return x;
	  }
	  pop_seen = zx_scan_xmlns(c);  /* Prescan namespaces so that token can be correctly recognized. */
	  tok = zx_elem_lookup(c, name, c->p, &ns);
	  switch (tok) {
          case zx_ds_P_ELEM:
            el = zx_DEC_simple_elem(c, ns, tok);
            el->g.n = &x->P->g;
            x->P = el;
            break;
          case zx_ds_Q_ELEM:
            el = zx_DEC_simple_elem(c, ns, tok);
            el->g.n = &x->Q->g;
            x->Q = el;
            break;
          case zx_ds_G_ELEM:
            el = zx_DEC_simple_elem(c, ns, tok);
            el->g.n = &x->G->g;
            x->G = el;
            break;
          case zx_ds_Y_ELEM:
            el = zx_DEC_simple_elem(c, ns, tok);
            el->g.n = &x->Y->g;
            x->Y = el;
            break;
          case zx_ds_J_ELEM:
            el = zx_DEC_simple_elem(c, ns, tok);
            el->g.n = &x->J->g;
            x->J = el;
            break;
          case zx_ds_Seed_ELEM:
            el = zx_DEC_simple_elem(c, ns, tok);
            el->g.n = &x->Seed->g;
            x->Seed = el;
            break;
          case zx_ds_PgenCounter_ELEM:
            el = zx_DEC_simple_elem(c, ns, tok);
            el->g.n = &x->PgenCounter->g;
            x->PgenCounter = el;
            break;

	  default:
	    el = zx_known_or_unknown_elem(c, tok, &x->gg, c->p - name, name, ns);
	    tok = ZX_TOK_NOT_FOUND;
	    break;
	  }
          el->g.wo = &x->gg.kids->g;
          x->gg.kids = el;
	  zx_pop_seen(pop_seen);
	  
	  goto next_elem;
	}
      }
      /* false alarm <, fall thru */
    }
    if (!zx_scan_data(c, &x->gg))
      return x;
    goto potential_tag;
  }
 out:
  iternode = x->gg.kids;
  REVERSE_LIST_NEXT(x->gg.kids, iternode, g.wo);
  iternode = (struct zx_elem_s*)(x->gg.any_elem);
  REVERSE_LIST_NEXT(x->gg.any_elem, iternode, g.n);
  ss = (struct zx_str*)(x->gg.any_attr);
  REVERSE_LIST_NEXT(x->gg.any_attr, ss, g.n);
  ZX_END_DEC_EXT(x);
  return x;

 look_for_not_found:
  zx_xml_parse_err(c, '>', (const char*)__FUNCTION__, "char not found");
  return x;
}

#undef EL_NAME
#undef EL_STRUCT
#undef EL_NS
#undef EL_TAG






/* FUNC(zx_DEC_ds_DigestMethod) */

#define EL_NAME   ds_DigestMethod
#define EL_STRUCT zx_ds_DigestMethod_s
#define EL_NS     ds
#define EL_TAG    DigestMethod

/* Called by: */
struct zx_ds_DigestMethod_s* zx_DEC_ds_DigestMethod(struct zx_ctx* c, struct zx_ns_s* ns )
{
  int tok;
  struct zx_elem_s* iternode;
  struct zx_elem_s* el;
  struct zx_str* ss;
  struct zx_ns_s* pop_seen;
  const char* name;
  const char* data;
  struct zx_ds_DigestMethod_s* x = ZX_ZALLOC(c, struct zx_ds_DigestMethod_s);
  x->gg.g.tok = zx_ds_DigestMethod_ELEM;
  x->gg.g.ns = ns;
  ZX_START_DEC_EXT(x);

#if 1 /* NORMALMODE */
  ZX_DEC_TAG_NOT_YET_CLOSED(x->gg.g);

  /* The tag name has already been detected. Process attributes until '>' */
  
  for (; c->p; ++c->p) {
    ZX_SKIP_WS(c,x);
    if (ONE_OF_2(*c->p, '>', '/'))
      break;
    if (!(data = zx_dec_attr_val(c, &name))) {
      D("Decoding attr_val failed %p", c->p);
      return x;
    }
    tok = zx_attr_lookup(c, name, data-2, &ns);
    switch (tok) {
    case zx_Algorithm_ATTR:
      ss = ZX_ZALLOC(c, struct zx_str);
      ss->g.n = &x->Algorithm->g;
      x->Algorithm = ss;
      ZX_ATTR_DEC_EXT(ss);
      break;

    case ZX_TOK_XMLNS:
      ZX_XMLNS_DEC_EXT(ss);
      DD("xmlns detected(%.*s)", data-2-name, name);
      goto next_attr;
    default:
      ss = zx_dec_unknown_attr(c, &x->gg, name, data, tok, x->gg.g.tok);
    }
    ss->g.ns = ns;
    ss->g.tok = tok;
    ss->g.err |= ZXERR_ATTR_FLAG;
    ss->len = c->p - data;
    ss->s = (char*)data;
next_attr:
    continue;
  }
  if (c->p) {
    ++c->p;
    if (c->p[-1] == '/' && c->p[0] == '>') {  /* Tag without content */
      ++c->p;
      ZX_DEC_TAG_NOW_CLOSED(x->gg.g);
      goto out;
    }
  }
#endif

  /* Process contents until '</' */
  
  ZX_START_BODY_DEC_EXT(x);
  
  while (c->p) {
  next_elem:
    /*ZX_SKIP_WS(c,x);    DO NOT SQUASH WS! EXC-CANON NEEDS IT. */
    if (*c->p == '<') {
    potential_tag:
      ++c->p;
      switch (*c->p) {
      case '?':  /* processing instruction <?xml ... ?> */
      case '!':  /* comment <!-- ... --> */
	if (zx_scan_pi_or_comment(c))
	  break;
	goto next_elem;
      case '/':  /* close tag */
	++c->p;
	name = c->p;
	ZX_LOOK_FOR(c,'>');
#if defined(DEC_WRONG_ELEM)
	if (x->gg.g.ns->prefix_len
	    ?(c->p - name - x->gg.g.ns->prefix_len - 1 != namlen || memcmp(name+x->gg.g.ns->prefix_len+1, nam, namlen))
	    :(c->p-name != namlen || memcmp(name, nam, namlen)))
#else
	tok = zx_elem_lookup(c, name, c->p, &ns);
	if (tok != x->gg.g.tok)
#endif
	{
	  ERR("Mismatching close tag(%.*s) tok=%d context=%d", c->p-name, name, tok, x->gg.g.tok);
	  zx_xml_parse_err(c, '-', (const char*)__FUNCTION__, "Mismatching close tag");
	  ZX_DEC_TAG_MISMATCH_CLOSE(x->gg.g);
	  ++c->p;
	  return x;
	}
	/* Legitimate close tag. Normal exit from this function. */
	++c->p;
	ZX_DEC_TAG_NOW_CLOSED(x->gg.g);
	goto out;
      default:
	if (A_Z_a_z_(*c->p)) {
	  name = c->p;
	  for (++c->p; *c->p && !ONE_OF_6(*c->p, ' ', '>', '/', '\n', '\r', '\t'); ++c->p) ;
	  if (!*c->p) {
	    D("Incomplete %s", name);
	    return x;
	  }
	  pop_seen = zx_scan_xmlns(c);  /* Prescan namespaces so that token can be correctly recognized. */
	  tok = zx_elem_lookup(c, name, c->p, &ns);
	  switch (tok) {

	  default:
	    el = zx_known_or_unknown_elem(c, tok, &x->gg, c->p - name, name, ns);
	    tok = ZX_TOK_NOT_FOUND;
	    break;
	  }
          el->g.wo = &x->gg.kids->g;
          x->gg.kids = el;
	  zx_pop_seen(pop_seen);
	  
	  goto next_elem;
	}
      }
      /* false alarm <, fall thru */
    }
    if (!zx_scan_data(c, &x->gg))
      return x;
    goto potential_tag;
  }
 out:
  iternode = x->gg.kids;
  REVERSE_LIST_NEXT(x->gg.kids, iternode, g.wo);
  iternode = (struct zx_elem_s*)(x->gg.any_elem);
  REVERSE_LIST_NEXT(x->gg.any_elem, iternode, g.n);
  ss = (struct zx_str*)(x->gg.any_attr);
  REVERSE_LIST_NEXT(x->gg.any_attr, ss, g.n);
  ZX_END_DEC_EXT(x);
  return x;

 look_for_not_found:
  zx_xml_parse_err(c, '>', (const char*)__FUNCTION__, "char not found");
  return x;
}

#undef EL_NAME
#undef EL_STRUCT
#undef EL_NS
#undef EL_TAG






/* FUNC(zx_DEC_ds_KeyInfo) */

#define EL_NAME   ds_KeyInfo
#define EL_STRUCT zx_ds_KeyInfo_s
#define EL_NS     ds
#define EL_TAG    KeyInfo

/* Called by: */
struct zx_ds_KeyInfo_s* zx_DEC_ds_KeyInfo(struct zx_ctx* c, struct zx_ns_s* ns )
{
  int tok;
  struct zx_elem_s* iternode;
  struct zx_elem_s* el;
  struct zx_str* ss;
  struct zx_ns_s* pop_seen;
  const char* name;
  const char* data;
  struct zx_ds_KeyInfo_s* x = ZX_ZALLOC(c, struct zx_ds_KeyInfo_s);
  x->gg.g.tok = zx_ds_KeyInfo_ELEM;
  x->gg.g.ns = ns;
  ZX_START_DEC_EXT(x);

#if 1 /* NORMALMODE */
  ZX_DEC_TAG_NOT_YET_CLOSED(x->gg.g);

  /* The tag name has already been detected. Process attributes until '>' */
  
  for (; c->p; ++c->p) {
    ZX_SKIP_WS(c,x);
    if (ONE_OF_2(*c->p, '>', '/'))
      break;
    if (!(data = zx_dec_attr_val(c, &name))) {
      D("Decoding attr_val failed %p", c->p);
      return x;
    }
    tok = zx_attr_lookup(c, name, data-2, &ns);
    switch (tok) {
    case zx_Id_ATTR:
      ss = ZX_ZALLOC(c, struct zx_str);
      ss->g.n = &x->Id->g;
      x->Id = ss;
      ZX_ATTR_DEC_EXT(ss);
      break;

    case ZX_TOK_XMLNS:
      ZX_XMLNS_DEC_EXT(ss);
      DD("xmlns detected(%.*s)", data-2-name, name);
      goto next_attr;
    default:
      ss = zx_dec_unknown_attr(c, &x->gg, name, data, tok, x->gg.g.tok);
    }
    ss->g.ns = ns;
    ss->g.tok = tok;
    ss->g.err |= ZXERR_ATTR_FLAG;
    ss->len = c->p - data;
    ss->s = (char*)data;
next_attr:
    continue;
  }
  if (c->p) {
    ++c->p;
    if (c->p[-1] == '/' && c->p[0] == '>') {  /* Tag without content */
      ++c->p;
      ZX_DEC_TAG_NOW_CLOSED(x->gg.g);
      goto out;
    }
  }
#endif

  /* Process contents until '</' */
  
  ZX_START_BODY_DEC_EXT(x);
  
  while (c->p) {
  next_elem:
    /*ZX_SKIP_WS(c,x);    DO NOT SQUASH WS! EXC-CANON NEEDS IT. */
    if (*c->p == '<') {
    potential_tag:
      ++c->p;
      switch (*c->p) {
      case '?':  /* processing instruction <?xml ... ?> */
      case '!':  /* comment <!-- ... --> */
	if (zx_scan_pi_or_comment(c))
	  break;
	goto next_elem;
      case '/':  /* close tag */
	++c->p;
	name = c->p;
	ZX_LOOK_FOR(c,'>');
#if defined(DEC_WRONG_ELEM)
	if (x->gg.g.ns->prefix_len
	    ?(c->p - name - x->gg.g.ns->prefix_len - 1 != namlen || memcmp(name+x->gg.g.ns->prefix_len+1, nam, namlen))
	    :(c->p-name != namlen || memcmp(name, nam, namlen)))
#else
	tok = zx_elem_lookup(c, name, c->p, &ns);
	if (tok != x->gg.g.tok)
#endif
	{
	  ERR("Mismatching close tag(%.*s) tok=%d context=%d", c->p-name, name, tok, x->gg.g.tok);
	  zx_xml_parse_err(c, '-', (const char*)__FUNCTION__, "Mismatching close tag");
	  ZX_DEC_TAG_MISMATCH_CLOSE(x->gg.g);
	  ++c->p;
	  return x;
	}
	/* Legitimate close tag. Normal exit from this function. */
	++c->p;
	ZX_DEC_TAG_NOW_CLOSED(x->gg.g);
	goto out;
      default:
	if (A_Z_a_z_(*c->p)) {
	  name = c->p;
	  for (++c->p; *c->p && !ONE_OF_6(*c->p, ' ', '>', '/', '\n', '\r', '\t'); ++c->p) ;
	  if (!*c->p) {
	    D("Incomplete %s", name);
	    return x;
	  }
	  pop_seen = zx_scan_xmlns(c);  /* Prescan namespaces so that token can be correctly recognized. */
	  tok = zx_elem_lookup(c, name, c->p, &ns);
	  switch (tok) {
          case zx_ds_KeyName_ELEM:
            el = zx_DEC_simple_elem(c, ns, tok);
            el->g.n = &x->KeyName->g;
            x->KeyName = el;
            break;
          case zx_ds_KeyValue_ELEM:
            el = (struct zx_elem_s*)zx_DEC_ds_KeyValue(c, ns);
            el->g.n = &x->KeyValue->gg.g;
            x->KeyValue = (struct zx_ds_KeyValue_s*)el;
            break;
          case zx_ds_RetrievalMethod_ELEM:
            el = (struct zx_elem_s*)zx_DEC_ds_RetrievalMethod(c, ns);
            el->g.n = &x->RetrievalMethod->gg.g;
            x->RetrievalMethod = (struct zx_ds_RetrievalMethod_s*)el;
            break;
          case zx_ds_X509Data_ELEM:
            el = (struct zx_elem_s*)zx_DEC_ds_X509Data(c, ns);
            el->g.n = &x->X509Data->gg.g;
            x->X509Data = (struct zx_ds_X509Data_s*)el;
            break;
          case zx_ds_PGPData_ELEM:
            el = (struct zx_elem_s*)zx_DEC_ds_PGPData(c, ns);
            el->g.n = &x->PGPData->gg.g;
            x->PGPData = (struct zx_ds_PGPData_s*)el;
            break;
          case zx_ds_SPKIData_ELEM:
            el = (struct zx_elem_s*)zx_DEC_ds_SPKIData(c, ns);
            el->g.n = &x->SPKIData->gg.g;
            x->SPKIData = (struct zx_ds_SPKIData_s*)el;
            break;
          case zx_ds_MgmtData_ELEM:
            el = zx_DEC_simple_elem(c, ns, tok);
            el->g.n = &x->MgmtData->g;
            x->MgmtData = el;
            break;
          case zx_xenc_EncryptedKey_ELEM:
            el = (struct zx_elem_s*)zx_DEC_xenc_EncryptedKey(c, ns);
            el->g.n = &x->EncryptedKey->gg.g;
            x->EncryptedKey = (struct zx_xenc_EncryptedKey_s*)el;
            break;

	  default:
	    el = zx_known_or_unknown_elem(c, tok, &x->gg, c->p - name, name, ns);
	    tok = ZX_TOK_NOT_FOUND;
	    break;
	  }
          el->g.wo = &x->gg.kids->g;
          x->gg.kids = el;
	  zx_pop_seen(pop_seen);
	  
	  goto next_elem;
	}
      }
      /* false alarm <, fall thru */
    }
    if (!zx_scan_data(c, &x->gg))
      return x;
    goto potential_tag;
  }
 out:
  iternode = x->gg.kids;
  REVERSE_LIST_NEXT(x->gg.kids, iternode, g.wo);
  iternode = (struct zx_elem_s*)(x->gg.any_elem);
  REVERSE_LIST_NEXT(x->gg.any_elem, iternode, g.n);
  ss = (struct zx_str*)(x->gg.any_attr);
  REVERSE_LIST_NEXT(x->gg.any_attr, ss, g.n);
  ZX_END_DEC_EXT(x);
  return x;

 look_for_not_found:
  zx_xml_parse_err(c, '>', (const char*)__FUNCTION__, "char not found");
  return x;
}

#undef EL_NAME
#undef EL_STRUCT
#undef EL_NS
#undef EL_TAG






/* FUNC(zx_DEC_ds_KeyValue) */

#define EL_NAME   ds_KeyValue
#define EL_STRUCT zx_ds_KeyValue_s
#define EL_NS     ds
#define EL_TAG    KeyValue

/* Called by: */
struct zx_ds_KeyValue_s* zx_DEC_ds_KeyValue(struct zx_ctx* c, struct zx_ns_s* ns )
{
  int tok;
  struct zx_elem_s* iternode;
  struct zx_elem_s* el;
  struct zx_str* ss;
  struct zx_ns_s* pop_seen;
  const char* name;
  const char* data;
  struct zx_ds_KeyValue_s* x = ZX_ZALLOC(c, struct zx_ds_KeyValue_s);
  x->gg.g.tok = zx_ds_KeyValue_ELEM;
  x->gg.g.ns = ns;
  ZX_START_DEC_EXT(x);

#if 1 /* NORMALMODE */
  ZX_DEC_TAG_NOT_YET_CLOSED(x->gg.g);

  /* The tag name has already been detected. Process attributes until '>' */
  
  for (; c->p; ++c->p) {
    ZX_SKIP_WS(c,x);
    if (ONE_OF_2(*c->p, '>', '/'))
      break;
    if (!(data = zx_dec_attr_val(c, &name))) {
      D("Decoding attr_val failed %p", c->p);
      return x;
    }
    tok = zx_attr_lookup(c, name, data-2, &ns);
    switch (tok) {

    case ZX_TOK_XMLNS:
      ZX_XMLNS_DEC_EXT(ss);
      DD("xmlns detected(%.*s)", data-2-name, name);
      goto next_attr;
    default:
      ss = zx_dec_unknown_attr(c, &x->gg, name, data, tok, x->gg.g.tok);
    }
    ss->g.ns = ns;
    ss->g.tok = tok;
    ss->g.err |= ZXERR_ATTR_FLAG;
    ss->len = c->p - data;
    ss->s = (char*)data;
next_attr:
    continue;
  }
  if (c->p) {
    ++c->p;
    if (c->p[-1] == '/' && c->p[0] == '>') {  /* Tag without content */
      ++c->p;
      ZX_DEC_TAG_NOW_CLOSED(x->gg.g);
      goto out;
    }
  }
#endif

  /* Process contents until '</' */
  
  ZX_START_BODY_DEC_EXT(x);
  
  while (c->p) {
  next_elem:
    /*ZX_SKIP_WS(c,x);    DO NOT SQUASH WS! EXC-CANON NEEDS IT. */
    if (*c->p == '<') {
    potential_tag:
      ++c->p;
      switch (*c->p) {
      case '?':  /* processing instruction <?xml ... ?> */
      case '!':  /* comment <!-- ... --> */
	if (zx_scan_pi_or_comment(c))
	  break;
	goto next_elem;
      case '/':  /* close tag */
	++c->p;
	name = c->p;
	ZX_LOOK_FOR(c,'>');
#if defined(DEC_WRONG_ELEM)
	if (x->gg.g.ns->prefix_len
	    ?(c->p - name - x->gg.g.ns->prefix_len - 1 != namlen || memcmp(name+x->gg.g.ns->prefix_len+1, nam, namlen))
	    :(c->p-name != namlen || memcmp(name, nam, namlen)))
#else
	tok = zx_elem_lookup(c, name, c->p, &ns);
	if (tok != x->gg.g.tok)
#endif
	{
	  ERR("Mismatching close tag(%.*s) tok=%d context=%d", c->p-name, name, tok, x->gg.g.tok);
	  zx_xml_parse_err(c, '-', (const char*)__FUNCTION__, "Mismatching close tag");
	  ZX_DEC_TAG_MISMATCH_CLOSE(x->gg.g);
	  ++c->p;
	  return x;
	}
	/* Legitimate close tag. Normal exit from this function. */
	++c->p;
	ZX_DEC_TAG_NOW_CLOSED(x->gg.g);
	goto out;
      default:
	if (A_Z_a_z_(*c->p)) {
	  name = c->p;
	  for (++c->p; *c->p && !ONE_OF_6(*c->p, ' ', '>', '/', '\n', '\r', '\t'); ++c->p) ;
	  if (!*c->p) {
	    D("Incomplete %s", name);
	    return x;
	  }
	  pop_seen = zx_scan_xmlns(c);  /* Prescan namespaces so that token can be correctly recognized. */
	  tok = zx_elem_lookup(c, name, c->p, &ns);
	  switch (tok) {
          case zx_ds_DSAKeyValue_ELEM:
            el = (struct zx_elem_s*)zx_DEC_ds_DSAKeyValue(c, ns);
            el->g.n = &x->DSAKeyValue->gg.g;
            x->DSAKeyValue = (struct zx_ds_DSAKeyValue_s*)el;
            break;
          case zx_ds_RSAKeyValue_ELEM:
            el = (struct zx_elem_s*)zx_DEC_ds_RSAKeyValue(c, ns);
            el->g.n = &x->RSAKeyValue->gg.g;
            x->RSAKeyValue = (struct zx_ds_RSAKeyValue_s*)el;
            break;

	  default:
	    el = zx_known_or_unknown_elem(c, tok, &x->gg, c->p - name, name, ns);
	    tok = ZX_TOK_NOT_FOUND;
	    break;
	  }
          el->g.wo = &x->gg.kids->g;
          x->gg.kids = el;
	  zx_pop_seen(pop_seen);
	  
	  goto next_elem;
	}
      }
      /* false alarm <, fall thru */
    }
    if (!zx_scan_data(c, &x->gg))
      return x;
    goto potential_tag;
  }
 out:
  iternode = x->gg.kids;
  REVERSE_LIST_NEXT(x->gg.kids, iternode, g.wo);
  iternode = (struct zx_elem_s*)(x->gg.any_elem);
  REVERSE_LIST_NEXT(x->gg.any_elem, iternode, g.n);
  ss = (struct zx_str*)(x->gg.any_attr);
  REVERSE_LIST_NEXT(x->gg.any_attr, ss, g.n);
  ZX_END_DEC_EXT(x);
  return x;

 look_for_not_found:
  zx_xml_parse_err(c, '>', (const char*)__FUNCTION__, "char not found");
  return x;
}

#undef EL_NAME
#undef EL_STRUCT
#undef EL_NS
#undef EL_TAG






/* FUNC(zx_DEC_ds_Manifest) */

#define EL_NAME   ds_Manifest
#define EL_STRUCT zx_ds_Manifest_s
#define EL_NS     ds
#define EL_TAG    Manifest

/* Called by: */
struct zx_ds_Manifest_s* zx_DEC_ds_Manifest(struct zx_ctx* c, struct zx_ns_s* ns )
{
  int tok;
  struct zx_elem_s* iternode;
  struct zx_elem_s* el;
  struct zx_str* ss;
  struct zx_ns_s* pop_seen;
  const char* name;
  const char* data;
  struct zx_ds_Manifest_s* x = ZX_ZALLOC(c, struct zx_ds_Manifest_s);
  x->gg.g.tok = zx_ds_Manifest_ELEM;
  x->gg.g.ns = ns;
  ZX_START_DEC_EXT(x);

#if 1 /* NORMALMODE */
  ZX_DEC_TAG_NOT_YET_CLOSED(x->gg.g);

  /* The tag name has already been detected. Process attributes until '>' */
  
  for (; c->p; ++c->p) {
    ZX_SKIP_WS(c,x);
    if (ONE_OF_2(*c->p, '>', '/'))
      break;
    if (!(data = zx_dec_attr_val(c, &name))) {
      D("Decoding attr_val failed %p", c->p);
      return x;
    }
    tok = zx_attr_lookup(c, name, data-2, &ns);
    switch (tok) {
    case zx_Id_ATTR:
      ss = ZX_ZALLOC(c, struct zx_str);
      ss->g.n = &x->Id->g;
      x->Id = ss;
      ZX_ATTR_DEC_EXT(ss);
      break;

    case ZX_TOK_XMLNS:
      ZX_XMLNS_DEC_EXT(ss);
      DD("xmlns detected(%.*s)", data-2-name, name);
      goto next_attr;
    default:
      ss = zx_dec_unknown_attr(c, &x->gg, name, data, tok, x->gg.g.tok);
    }
    ss->g.ns = ns;
    ss->g.tok = tok;
    ss->g.err |= ZXERR_ATTR_FLAG;
    ss->len = c->p - data;
    ss->s = (char*)data;
next_attr:
    continue;
  }
  if (c->p) {
    ++c->p;
    if (c->p[-1] == '/' && c->p[0] == '>') {  /* Tag without content */
      ++c->p;
      ZX_DEC_TAG_NOW_CLOSED(x->gg.g);
      goto out;
    }
  }
#endif

  /* Process contents until '</' */
  
  ZX_START_BODY_DEC_EXT(x);
  
  while (c->p) {
  next_elem:
    /*ZX_SKIP_WS(c,x);    DO NOT SQUASH WS! EXC-CANON NEEDS IT. */
    if (*c->p == '<') {
    potential_tag:
      ++c->p;
      switch (*c->p) {
      case '?':  /* processing instruction <?xml ... ?> */
      case '!':  /* comment <!-- ... --> */
	if (zx_scan_pi_or_comment(c))
	  break;
	goto next_elem;
      case '/':  /* close tag */
	++c->p;
	name = c->p;
	ZX_LOOK_FOR(c,'>');
#if defined(DEC_WRONG_ELEM)
	if (x->gg.g.ns->prefix_len
	    ?(c->p - name - x->gg.g.ns->prefix_len - 1 != namlen || memcmp(name+x->gg.g.ns->prefix_len+1, nam, namlen))
	    :(c->p-name != namlen || memcmp(name, nam, namlen)))
#else
	tok = zx_elem_lookup(c, name, c->p, &ns);
	if (tok != x->gg.g.tok)
#endif
	{
	  ERR("Mismatching close tag(%.*s) tok=%d context=%d", c->p-name, name, tok, x->gg.g.tok);
	  zx_xml_parse_err(c, '-', (const char*)__FUNCTION__, "Mismatching close tag");
	  ZX_DEC_TAG_MISMATCH_CLOSE(x->gg.g);
	  ++c->p;
	  return x;
	}
	/* Legitimate close tag. Normal exit from this function. */
	++c->p;
	ZX_DEC_TAG_NOW_CLOSED(x->gg.g);
	goto out;
      default:
	if (A_Z_a_z_(*c->p)) {
	  name = c->p;
	  for (++c->p; *c->p && !ONE_OF_6(*c->p, ' ', '>', '/', '\n', '\r', '\t'); ++c->p) ;
	  if (!*c->p) {
	    D("Incomplete %s", name);
	    return x;
	  }
	  pop_seen = zx_scan_xmlns(c);  /* Prescan namespaces so that token can be correctly recognized. */
	  tok = zx_elem_lookup(c, name, c->p, &ns);
	  switch (tok) {
          case zx_ds_Reference_ELEM:
            el = (struct zx_elem_s*)zx_DEC_ds_Reference(c, ns);
            el->g.n = &x->Reference->gg.g;
            x->Reference = (struct zx_ds_Reference_s*)el;
            break;

	  default:
	    el = zx_known_or_unknown_elem(c, tok, &x->gg, c->p - name, name, ns);
	    tok = ZX_TOK_NOT_FOUND;
	    break;
	  }
          el->g.wo = &x->gg.kids->g;
          x->gg.kids = el;
	  zx_pop_seen(pop_seen);
	  
	  goto next_elem;
	}
      }
      /* false alarm <, fall thru */
    }
    if (!zx_scan_data(c, &x->gg))
      return x;
    goto potential_tag;
  }
 out:
  iternode = x->gg.kids;
  REVERSE_LIST_NEXT(x->gg.kids, iternode, g.wo);
  iternode = (struct zx_elem_s*)(x->gg.any_elem);
  REVERSE_LIST_NEXT(x->gg.any_elem, iternode, g.n);
  ss = (struct zx_str*)(x->gg.any_attr);
  REVERSE_LIST_NEXT(x->gg.any_attr, ss, g.n);
  ZX_END_DEC_EXT(x);
  return x;

 look_for_not_found:
  zx_xml_parse_err(c, '>', (const char*)__FUNCTION__, "char not found");
  return x;
}

#undef EL_NAME
#undef EL_STRUCT
#undef EL_NS
#undef EL_TAG






/* FUNC(zx_DEC_ds_Object) */

#define EL_NAME   ds_Object
#define EL_STRUCT zx_ds_Object_s
#define EL_NS     ds
#define EL_TAG    Object

/* Called by: */
struct zx_ds_Object_s* zx_DEC_ds_Object(struct zx_ctx* c, struct zx_ns_s* ns )
{
  int tok;
  struct zx_elem_s* iternode;
  struct zx_elem_s* el;
  struct zx_str* ss;
  struct zx_ns_s* pop_seen;
  const char* name;
  const char* data;
  struct zx_ds_Object_s* x = ZX_ZALLOC(c, struct zx_ds_Object_s);
  x->gg.g.tok = zx_ds_Object_ELEM;
  x->gg.g.ns = ns;
  ZX_START_DEC_EXT(x);

#if 1 /* NORMALMODE */
  ZX_DEC_TAG_NOT_YET_CLOSED(x->gg.g);

  /* The tag name has already been detected. Process attributes until '>' */
  
  for (; c->p; ++c->p) {
    ZX_SKIP_WS(c,x);
    if (ONE_OF_2(*c->p, '>', '/'))
      break;
    if (!(data = zx_dec_attr_val(c, &name))) {
      D("Decoding attr_val failed %p", c->p);
      return x;
    }
    tok = zx_attr_lookup(c, name, data-2, &ns);
    switch (tok) {
    case zx_Encoding_ATTR:
      ss = ZX_ZALLOC(c, struct zx_str);
      ss->g.n = &x->Encoding->g;
      x->Encoding = ss;
      ZX_ATTR_DEC_EXT(ss);
      break;
    case zx_Id_ATTR:
      ss = ZX_ZALLOC(c, struct zx_str);
      ss->g.n = &x->Id->g;
      x->Id = ss;
      ZX_ATTR_DEC_EXT(ss);
      break;
    case zx_MimeType_ATTR:
      ss = ZX_ZALLOC(c, struct zx_str);
      ss->g.n = &x->MimeType->g;
      x->MimeType = ss;
      ZX_ATTR_DEC_EXT(ss);
      break;

    case ZX_TOK_XMLNS:
      ZX_XMLNS_DEC_EXT(ss);
      DD("xmlns detected(%.*s)", data-2-name, name);
      goto next_attr;
    default:
      ss = zx_dec_unknown_attr(c, &x->gg, name, data, tok, x->gg.g.tok);
    }
    ss->g.ns = ns;
    ss->g.tok = tok;
    ss->g.err |= ZXERR_ATTR_FLAG;
    ss->len = c->p - data;
    ss->s = (char*)data;
next_attr:
    continue;
  }
  if (c->p) {
    ++c->p;
    if (c->p[-1] == '/' && c->p[0] == '>') {  /* Tag without content */
      ++c->p;
      ZX_DEC_TAG_NOW_CLOSED(x->gg.g);
      goto out;
    }
  }
#endif

  /* Process contents until '</' */
  
  ZX_START_BODY_DEC_EXT(x);
  
  while (c->p) {
  next_elem:
    /*ZX_SKIP_WS(c,x);    DO NOT SQUASH WS! EXC-CANON NEEDS IT. */
    if (*c->p == '<') {
    potential_tag:
      ++c->p;
      switch (*c->p) {
      case '?':  /* processing instruction <?xml ... ?> */
      case '!':  /* comment <!-- ... --> */
	if (zx_scan_pi_or_comment(c))
	  break;
	goto next_elem;
      case '/':  /* close tag */
	++c->p;
	name = c->p;
	ZX_LOOK_FOR(c,'>');
#if defined(DEC_WRONG_ELEM)
	if (x->gg.g.ns->prefix_len
	    ?(c->p - name - x->gg.g.ns->prefix_len - 1 != namlen || memcmp(name+x->gg.g.ns->prefix_len+1, nam, namlen))
	    :(c->p-name != namlen || memcmp(name, nam, namlen)))
#else
	tok = zx_elem_lookup(c, name, c->p, &ns);
	if (tok != x->gg.g.tok)
#endif
	{
	  ERR("Mismatching close tag(%.*s) tok=%d context=%d", c->p-name, name, tok, x->gg.g.tok);
	  zx_xml_parse_err(c, '-', (const char*)__FUNCTION__, "Mismatching close tag");
	  ZX_DEC_TAG_MISMATCH_CLOSE(x->gg.g);
	  ++c->p;
	  return x;
	}
	/* Legitimate close tag. Normal exit from this function. */
	++c->p;
	ZX_DEC_TAG_NOW_CLOSED(x->gg.g);
	goto out;
      default:
	if (A_Z_a_z_(*c->p)) {
	  name = c->p;
	  for (++c->p; *c->p && !ONE_OF_6(*c->p, ' ', '>', '/', '\n', '\r', '\t'); ++c->p) ;
	  if (!*c->p) {
	    D("Incomplete %s", name);
	    return x;
	  }
	  pop_seen = zx_scan_xmlns(c);  /* Prescan namespaces so that token can be correctly recognized. */
	  tok = zx_elem_lookup(c, name, c->p, &ns);
	  switch (tok) {

	  default:
	    el = zx_known_or_unknown_elem(c, tok, &x->gg, c->p - name, name, ns);
	    tok = ZX_TOK_NOT_FOUND;
	    break;
	  }
          el->g.wo = &x->gg.kids->g;
          x->gg.kids = el;
	  zx_pop_seen(pop_seen);
	  
	  goto next_elem;
	}
      }
      /* false alarm <, fall thru */
    }
    if (!zx_scan_data(c, &x->gg))
      return x;
    goto potential_tag;
  }
 out:
  iternode = x->gg.kids;
  REVERSE_LIST_NEXT(x->gg.kids, iternode, g.wo);
  iternode = (struct zx_elem_s*)(x->gg.any_elem);
  REVERSE_LIST_NEXT(x->gg.any_elem, iternode, g.n);
  ss = (struct zx_str*)(x->gg.any_attr);
  REVERSE_LIST_NEXT(x->gg.any_attr, ss, g.n);
  ZX_END_DEC_EXT(x);
  return x;

 look_for_not_found:
  zx_xml_parse_err(c, '>', (const char*)__FUNCTION__, "char not found");
  return x;
}

#undef EL_NAME
#undef EL_STRUCT
#undef EL_NS
#undef EL_TAG






/* FUNC(zx_DEC_ds_PGPData) */

#define EL_NAME   ds_PGPData
#define EL_STRUCT zx_ds_PGPData_s
#define EL_NS     ds
#define EL_TAG    PGPData

/* Called by: */
struct zx_ds_PGPData_s* zx_DEC_ds_PGPData(struct zx_ctx* c, struct zx_ns_s* ns )
{
  int tok;
  struct zx_elem_s* iternode;
  struct zx_elem_s* el;
  struct zx_str* ss;
  struct zx_ns_s* pop_seen;
  const char* name;
  const char* data;
  struct zx_ds_PGPData_s* x = ZX_ZALLOC(c, struct zx_ds_PGPData_s);
  x->gg.g.tok = zx_ds_PGPData_ELEM;
  x->gg.g.ns = ns;
  ZX_START_DEC_EXT(x);

#if 1 /* NORMALMODE */
  ZX_DEC_TAG_NOT_YET_CLOSED(x->gg.g);

  /* The tag name has already been detected. Process attributes until '>' */
  
  for (; c->p; ++c->p) {
    ZX_SKIP_WS(c,x);
    if (ONE_OF_2(*c->p, '>', '/'))
      break;
    if (!(data = zx_dec_attr_val(c, &name))) {
      D("Decoding attr_val failed %p", c->p);
      return x;
    }
    tok = zx_attr_lookup(c, name, data-2, &ns);
    switch (tok) {

    case ZX_TOK_XMLNS:
      ZX_XMLNS_DEC_EXT(ss);
      DD("xmlns detected(%.*s)", data-2-name, name);
      goto next_attr;
    default:
      ss = zx_dec_unknown_attr(c, &x->gg, name, data, tok, x->gg.g.tok);
    }
    ss->g.ns = ns;
    ss->g.tok = tok;
    ss->g.err |= ZXERR_ATTR_FLAG;
    ss->len = c->p - data;
    ss->s = (char*)data;
next_attr:
    continue;
  }
  if (c->p) {
    ++c->p;
    if (c->p[-1] == '/' && c->p[0] == '>') {  /* Tag without content */
      ++c->p;
      ZX_DEC_TAG_NOW_CLOSED(x->gg.g);
      goto out;
    }
  }
#endif

  /* Process contents until '</' */
  
  ZX_START_BODY_DEC_EXT(x);
  
  while (c->p) {
  next_elem:
    /*ZX_SKIP_WS(c,x);    DO NOT SQUASH WS! EXC-CANON NEEDS IT. */
    if (*c->p == '<') {
    potential_tag:
      ++c->p;
      switch (*c->p) {
      case '?':  /* processing instruction <?xml ... ?> */
      case '!':  /* comment <!-- ... --> */
	if (zx_scan_pi_or_comment(c))
	  break;
	goto next_elem;
      case '/':  /* close tag */
	++c->p;
	name = c->p;
	ZX_LOOK_FOR(c,'>');
#if defined(DEC_WRONG_ELEM)
	if (x->gg.g.ns->prefix_len
	    ?(c->p - name - x->gg.g.ns->prefix_len - 1 != namlen || memcmp(name+x->gg.g.ns->prefix_len+1, nam, namlen))
	    :(c->p-name != namlen || memcmp(name, nam, namlen)))
#else
	tok = zx_elem_lookup(c, name, c->p, &ns);
	if (tok != x->gg.g.tok)
#endif
	{
	  ERR("Mismatching close tag(%.*s) tok=%d context=%d", c->p-name, name, tok, x->gg.g.tok);
	  zx_xml_parse_err(c, '-', (const char*)__FUNCTION__, "Mismatching close tag");
	  ZX_DEC_TAG_MISMATCH_CLOSE(x->gg.g);
	  ++c->p;
	  return x;
	}
	/* Legitimate close tag. Normal exit from this function. */
	++c->p;
	ZX_DEC_TAG_NOW_CLOSED(x->gg.g);
	goto out;
      default:
	if (A_Z_a_z_(*c->p)) {
	  name = c->p;
	  for (++c->p; *c->p && !ONE_OF_6(*c->p, ' ', '>', '/', '\n', '\r', '\t'); ++c->p) ;
	  if (!*c->p) {
	    D("Incomplete %s", name);
	    return x;
	  }
	  pop_seen = zx_scan_xmlns(c);  /* Prescan namespaces so that token can be correctly recognized. */
	  tok = zx_elem_lookup(c, name, c->p, &ns);
	  switch (tok) {
          case zx_ds_PGPKeyID_ELEM:
            el = zx_DEC_simple_elem(c, ns, tok);
            el->g.n = &x->PGPKeyID->g;
            x->PGPKeyID = el;
            break;
          case zx_ds_PGPKeyPacket_ELEM:
            el = zx_DEC_simple_elem(c, ns, tok);
            el->g.n = &x->PGPKeyPacket->g;
            x->PGPKeyPacket = el;
            break;

	  default:
	    el = zx_known_or_unknown_elem(c, tok, &x->gg, c->p - name, name, ns);
	    tok = ZX_TOK_NOT_FOUND;
	    break;
	  }
          el->g.wo = &x->gg.kids->g;
          x->gg.kids = el;
	  zx_pop_seen(pop_seen);
	  
	  goto next_elem;
	}
      }
      /* false alarm <, fall thru */
    }
    if (!zx_scan_data(c, &x->gg))
      return x;
    goto potential_tag;
  }
 out:
  iternode = x->gg.kids;
  REVERSE_LIST_NEXT(x->gg.kids, iternode, g.wo);
  iternode = (struct zx_elem_s*)(x->gg.any_elem);
  REVERSE_LIST_NEXT(x->gg.any_elem, iternode, g.n);
  ss = (struct zx_str*)(x->gg.any_attr);
  REVERSE_LIST_NEXT(x->gg.any_attr, ss, g.n);
  ZX_END_DEC_EXT(x);
  return x;

 look_for_not_found:
  zx_xml_parse_err(c, '>', (const char*)__FUNCTION__, "char not found");
  return x;
}

#undef EL_NAME
#undef EL_STRUCT
#undef EL_NS
#undef EL_TAG






/* FUNC(zx_DEC_ds_RSAKeyValue) */

#define EL_NAME   ds_RSAKeyValue
#define EL_STRUCT zx_ds_RSAKeyValue_s
#define EL_NS     ds
#define EL_TAG    RSAKeyValue

/* Called by: */
struct zx_ds_RSAKeyValue_s* zx_DEC_ds_RSAKeyValue(struct zx_ctx* c, struct zx_ns_s* ns )
{
  int tok;
  struct zx_elem_s* iternode;
  struct zx_elem_s* el;
  struct zx_str* ss;
  struct zx_ns_s* pop_seen;
  const char* name;
  const char* data;
  struct zx_ds_RSAKeyValue_s* x = ZX_ZALLOC(c, struct zx_ds_RSAKeyValue_s);
  x->gg.g.tok = zx_ds_RSAKeyValue_ELEM;
  x->gg.g.ns = ns;
  ZX_START_DEC_EXT(x);

#if 1 /* NORMALMODE */
  ZX_DEC_TAG_NOT_YET_CLOSED(x->gg.g);

  /* The tag name has already been detected. Process attributes until '>' */
  
  for (; c->p; ++c->p) {
    ZX_SKIP_WS(c,x);
    if (ONE_OF_2(*c->p, '>', '/'))
      break;
    if (!(data = zx_dec_attr_val(c, &name))) {
      D("Decoding attr_val failed %p", c->p);
      return x;
    }
    tok = zx_attr_lookup(c, name, data-2, &ns);
    switch (tok) {

    case ZX_TOK_XMLNS:
      ZX_XMLNS_DEC_EXT(ss);
      DD("xmlns detected(%.*s)", data-2-name, name);
      goto next_attr;
    default:
      ss = zx_dec_unknown_attr(c, &x->gg, name, data, tok, x->gg.g.tok);
    }
    ss->g.ns = ns;
    ss->g.tok = tok;
    ss->g.err |= ZXERR_ATTR_FLAG;
    ss->len = c->p - data;
    ss->s = (char*)data;
next_attr:
    continue;
  }
  if (c->p) {
    ++c->p;
    if (c->p[-1] == '/' && c->p[0] == '>') {  /* Tag without content */
      ++c->p;
      ZX_DEC_TAG_NOW_CLOSED(x->gg.g);
      goto out;
    }
  }
#endif

  /* Process contents until '</' */
  
  ZX_START_BODY_DEC_EXT(x);
  
  while (c->p) {
  next_elem:
    /*ZX_SKIP_WS(c,x);    DO NOT SQUASH WS! EXC-CANON NEEDS IT. */
    if (*c->p == '<') {
    potential_tag:
      ++c->p;
      switch (*c->p) {
      case '?':  /* processing instruction <?xml ... ?> */
      case '!':  /* comment <!-- ... --> */
	if (zx_scan_pi_or_comment(c))
	  break;
	goto next_elem;
      case '/':  /* close tag */
	++c->p;
	name = c->p;
	ZX_LOOK_FOR(c,'>');
#if defined(DEC_WRONG_ELEM)
	if (x->gg.g.ns->prefix_len
	    ?(c->p - name - x->gg.g.ns->prefix_len - 1 != namlen || memcmp(name+x->gg.g.ns->prefix_len+1, nam, namlen))
	    :(c->p-name != namlen || memcmp(name, nam, namlen)))
#else
	tok = zx_elem_lookup(c, name, c->p, &ns);
	if (tok != x->gg.g.tok)
#endif
	{
	  ERR("Mismatching close tag(%.*s) tok=%d context=%d", c->p-name, name, tok, x->gg.g.tok);
	  zx_xml_parse_err(c, '-', (const char*)__FUNCTION__, "Mismatching close tag");
	  ZX_DEC_TAG_MISMATCH_CLOSE(x->gg.g);
	  ++c->p;
	  return x;
	}
	/* Legitimate close tag. Normal exit from this function. */
	++c->p;
	ZX_DEC_TAG_NOW_CLOSED(x->gg.g);
	goto out;
      default:
	if (A_Z_a_z_(*c->p)) {
	  name = c->p;
	  for (++c->p; *c->p && !ONE_OF_6(*c->p, ' ', '>', '/', '\n', '\r', '\t'); ++c->p) ;
	  if (!*c->p) {
	    D("Incomplete %s", name);
	    return x;
	  }
	  pop_seen = zx_scan_xmlns(c);  /* Prescan namespaces so that token can be correctly recognized. */
	  tok = zx_elem_lookup(c, name, c->p, &ns);
	  switch (tok) {
          case zx_ds_Modulus_ELEM:
            el = zx_DEC_simple_elem(c, ns, tok);
            el->g.n = &x->Modulus->g;
            x->Modulus = el;
            break;
          case zx_ds_Exponent_ELEM:
            el = zx_DEC_simple_elem(c, ns, tok);
            el->g.n = &x->Exponent->g;
            x->Exponent = el;
            break;

	  default:
	    el = zx_known_or_unknown_elem(c, tok, &x->gg, c->p - name, name, ns);
	    tok = ZX_TOK_NOT_FOUND;
	    break;
	  }
          el->g.wo = &x->gg.kids->g;
          x->gg.kids = el;
	  zx_pop_seen(pop_seen);
	  
	  goto next_elem;
	}
      }
      /* false alarm <, fall thru */
    }
    if (!zx_scan_data(c, &x->gg))
      return x;
    goto potential_tag;
  }
 out:
  iternode = x->gg.kids;
  REVERSE_LIST_NEXT(x->gg.kids, iternode, g.wo);
  iternode = (struct zx_elem_s*)(x->gg.any_elem);
  REVERSE_LIST_NEXT(x->gg.any_elem, iternode, g.n);
  ss = (struct zx_str*)(x->gg.any_attr);
  REVERSE_LIST_NEXT(x->gg.any_attr, ss, g.n);
  ZX_END_DEC_EXT(x);
  return x;

 look_for_not_found:
  zx_xml_parse_err(c, '>', (const char*)__FUNCTION__, "char not found");
  return x;
}

#undef EL_NAME
#undef EL_STRUCT
#undef EL_NS
#undef EL_TAG






/* FUNC(zx_DEC_ds_Reference) */

#define EL_NAME   ds_Reference
#define EL_STRUCT zx_ds_Reference_s
#define EL_NS     ds
#define EL_TAG    Reference

/* Called by: */
struct zx_ds_Reference_s* zx_DEC_ds_Reference(struct zx_ctx* c, struct zx_ns_s* ns )
{
  int tok;
  struct zx_elem_s* iternode;
  struct zx_elem_s* el;
  struct zx_str* ss;
  struct zx_ns_s* pop_seen;
  const char* name;
  const char* data;
  struct zx_ds_Reference_s* x = ZX_ZALLOC(c, struct zx_ds_Reference_s);
  x->gg.g.tok = zx_ds_Reference_ELEM;
  x->gg.g.ns = ns;
  ZX_START_DEC_EXT(x);

#if 1 /* NORMALMODE */
  ZX_DEC_TAG_NOT_YET_CLOSED(x->gg.g);

  /* The tag name has already been detected. Process attributes until '>' */
  
  for (; c->p; ++c->p) {
    ZX_SKIP_WS(c,x);
    if (ONE_OF_2(*c->p, '>', '/'))
      break;
    if (!(data = zx_dec_attr_val(c, &name))) {
      D("Decoding attr_val failed %p", c->p);
      return x;
    }
    tok = zx_attr_lookup(c, name, data-2, &ns);
    switch (tok) {
    case zx_Id_ATTR:
      ss = ZX_ZALLOC(c, struct zx_str);
      ss->g.n = &x->Id->g;
      x->Id = ss;
      ZX_ATTR_DEC_EXT(ss);
      break;
    case zx_Type_ATTR:
      ss = ZX_ZALLOC(c, struct zx_str);
      ss->g.n = &x->Type->g;
      x->Type = ss;
      ZX_ATTR_DEC_EXT(ss);
      break;
    case zx_URI_ATTR:
      ss = ZX_ZALLOC(c, struct zx_str);
      ss->g.n = &x->URI->g;
      x->URI = ss;
      ZX_ATTR_DEC_EXT(ss);
      break;

    case ZX_TOK_XMLNS:
      ZX_XMLNS_DEC_EXT(ss);
      DD("xmlns detected(%.*s)", data-2-name, name);
      goto next_attr;
    default:
      ss = zx_dec_unknown_attr(c, &x->gg, name, data, tok, x->gg.g.tok);
    }
    ss->g.ns = ns;
    ss->g.tok = tok;
    ss->g.err |= ZXERR_ATTR_FLAG;
    ss->len = c->p - data;
    ss->s = (char*)data;
next_attr:
    continue;
  }
  if (c->p) {
    ++c->p;
    if (c->p[-1] == '/' && c->p[0] == '>') {  /* Tag without content */
      ++c->p;
      ZX_DEC_TAG_NOW_CLOSED(x->gg.g);
      goto out;
    }
  }
#endif

  /* Process contents until '</' */
  
  ZX_START_BODY_DEC_EXT(x);
  
  while (c->p) {
  next_elem:
    /*ZX_SKIP_WS(c,x);    DO NOT SQUASH WS! EXC-CANON NEEDS IT. */
    if (*c->p == '<') {
    potential_tag:
      ++c->p;
      switch (*c->p) {
      case '?':  /* processing instruction <?xml ... ?> */
      case '!':  /* comment <!-- ... --> */
	if (zx_scan_pi_or_comment(c))
	  break;
	goto next_elem;
      case '/':  /* close tag */
	++c->p;
	name = c->p;
	ZX_LOOK_FOR(c,'>');
#if defined(DEC_WRONG_ELEM)
	if (x->gg.g.ns->prefix_len
	    ?(c->p - name - x->gg.g.ns->prefix_len - 1 != namlen || memcmp(name+x->gg.g.ns->prefix_len+1, nam, namlen))
	    :(c->p-name != namlen || memcmp(name, nam, namlen)))
#else
	tok = zx_elem_lookup(c, name, c->p, &ns);
	if (tok != x->gg.g.tok)
#endif
	{
	  ERR("Mismatching close tag(%.*s) tok=%d context=%d", c->p-name, name, tok, x->gg.g.tok);
	  zx_xml_parse_err(c, '-', (const char*)__FUNCTION__, "Mismatching close tag");
	  ZX_DEC_TAG_MISMATCH_CLOSE(x->gg.g);
	  ++c->p;
	  return x;
	}
	/* Legitimate close tag. Normal exit from this function. */
	++c->p;
	ZX_DEC_TAG_NOW_CLOSED(x->gg.g);
	goto out;
      default:
	if (A_Z_a_z_(*c->p)) {
	  name = c->p;
	  for (++c->p; *c->p && !ONE_OF_6(*c->p, ' ', '>', '/', '\n', '\r', '\t'); ++c->p) ;
	  if (!*c->p) {
	    D("Incomplete %s", name);
	    return x;
	  }
	  pop_seen = zx_scan_xmlns(c);  /* Prescan namespaces so that token can be correctly recognized. */
	  tok = zx_elem_lookup(c, name, c->p, &ns);
	  switch (tok) {
          case zx_ds_Transforms_ELEM:
            el = (struct zx_elem_s*)zx_DEC_ds_Transforms(c, ns);
            el->g.n = &x->Transforms->gg.g;
            x->Transforms = (struct zx_ds_Transforms_s*)el;
            break;
          case zx_ds_DigestMethod_ELEM:
            el = (struct zx_elem_s*)zx_DEC_ds_DigestMethod(c, ns);
            el->g.n = &x->DigestMethod->gg.g;
            x->DigestMethod = (struct zx_ds_DigestMethod_s*)el;
            break;
          case zx_ds_DigestValue_ELEM:
            el = zx_DEC_simple_elem(c, ns, tok);
            el->g.n = &x->DigestValue->g;
            x->DigestValue = el;
            break;

	  default:
	    el = zx_known_or_unknown_elem(c, tok, &x->gg, c->p - name, name, ns);
	    tok = ZX_TOK_NOT_FOUND;
	    break;
	  }
          el->g.wo = &x->gg.kids->g;
          x->gg.kids = el;
	  zx_pop_seen(pop_seen);
	  
	  goto next_elem;
	}
      }
      /* false alarm <, fall thru */
    }
    if (!zx_scan_data(c, &x->gg))
      return x;
    goto potential_tag;
  }
 out:
  iternode = x->gg.kids;
  REVERSE_LIST_NEXT(x->gg.kids, iternode, g.wo);
  iternode = (struct zx_elem_s*)(x->gg.any_elem);
  REVERSE_LIST_NEXT(x->gg.any_elem, iternode, g.n);
  ss = (struct zx_str*)(x->gg.any_attr);
  REVERSE_LIST_NEXT(x->gg.any_attr, ss, g.n);
  ZX_END_DEC_EXT(x);
  return x;

 look_for_not_found:
  zx_xml_parse_err(c, '>', (const char*)__FUNCTION__, "char not found");
  return x;
}

#undef EL_NAME
#undef EL_STRUCT
#undef EL_NS
#undef EL_TAG






/* FUNC(zx_DEC_ds_RetrievalMethod) */

#define EL_NAME   ds_RetrievalMethod
#define EL_STRUCT zx_ds_RetrievalMethod_s
#define EL_NS     ds
#define EL_TAG    RetrievalMethod

/* Called by: */
struct zx_ds_RetrievalMethod_s* zx_DEC_ds_RetrievalMethod(struct zx_ctx* c, struct zx_ns_s* ns )
{
  int tok;
  struct zx_elem_s* iternode;
  struct zx_elem_s* el;
  struct zx_str* ss;
  struct zx_ns_s* pop_seen;
  const char* name;
  const char* data;
  struct zx_ds_RetrievalMethod_s* x = ZX_ZALLOC(c, struct zx_ds_RetrievalMethod_s);
  x->gg.g.tok = zx_ds_RetrievalMethod_ELEM;
  x->gg.g.ns = ns;
  ZX_START_DEC_EXT(x);

#if 1 /* NORMALMODE */
  ZX_DEC_TAG_NOT_YET_CLOSED(x->gg.g);

  /* The tag name has already been detected. Process attributes until '>' */
  
  for (; c->p; ++c->p) {
    ZX_SKIP_WS(c,x);
    if (ONE_OF_2(*c->p, '>', '/'))
      break;
    if (!(data = zx_dec_attr_val(c, &name))) {
      D("Decoding attr_val failed %p", c->p);
      return x;
    }
    tok = zx_attr_lookup(c, name, data-2, &ns);
    switch (tok) {
    case zx_Type_ATTR:
      ss = ZX_ZALLOC(c, struct zx_str);
      ss->g.n = &x->Type->g;
      x->Type = ss;
      ZX_ATTR_DEC_EXT(ss);
      break;
    case zx_URI_ATTR:
      ss = ZX_ZALLOC(c, struct zx_str);
      ss->g.n = &x->URI->g;
      x->URI = ss;
      ZX_ATTR_DEC_EXT(ss);
      break;

    case ZX_TOK_XMLNS:
      ZX_XMLNS_DEC_EXT(ss);
      DD("xmlns detected(%.*s)", data-2-name, name);
      goto next_attr;
    default:
      ss = zx_dec_unknown_attr(c, &x->gg, name, data, tok, x->gg.g.tok);
    }
    ss->g.ns = ns;
    ss->g.tok = tok;
    ss->g.err |= ZXERR_ATTR_FLAG;
    ss->len = c->p - data;
    ss->s = (char*)data;
next_attr:
    continue;
  }
  if (c->p) {
    ++c->p;
    if (c->p[-1] == '/' && c->p[0] == '>') {  /* Tag without content */
      ++c->p;
      ZX_DEC_TAG_NOW_CLOSED(x->gg.g);
      goto out;
    }
  }
#endif

  /* Process contents until '</' */
  
  ZX_START_BODY_DEC_EXT(x);
  
  while (c->p) {
  next_elem:
    /*ZX_SKIP_WS(c,x);    DO NOT SQUASH WS! EXC-CANON NEEDS IT. */
    if (*c->p == '<') {
    potential_tag:
      ++c->p;
      switch (*c->p) {
      case '?':  /* processing instruction <?xml ... ?> */
      case '!':  /* comment <!-- ... --> */
	if (zx_scan_pi_or_comment(c))
	  break;
	goto next_elem;
      case '/':  /* close tag */
	++c->p;
	name = c->p;
	ZX_LOOK_FOR(c,'>');
#if defined(DEC_WRONG_ELEM)
	if (x->gg.g.ns->prefix_len
	    ?(c->p - name - x->gg.g.ns->prefix_len - 1 != namlen || memcmp(name+x->gg.g.ns->prefix_len+1, nam, namlen))
	    :(c->p-name != namlen || memcmp(name, nam, namlen)))
#else
	tok = zx_elem_lookup(c, name, c->p, &ns);
	if (tok != x->gg.g.tok)
#endif
	{
	  ERR("Mismatching close tag(%.*s) tok=%d context=%d", c->p-name, name, tok, x->gg.g.tok);
	  zx_xml_parse_err(c, '-', (const char*)__FUNCTION__, "Mismatching close tag");
	  ZX_DEC_TAG_MISMATCH_CLOSE(x->gg.g);
	  ++c->p;
	  return x;
	}
	/* Legitimate close tag. Normal exit from this function. */
	++c->p;
	ZX_DEC_TAG_NOW_CLOSED(x->gg.g);
	goto out;
      default:
	if (A_Z_a_z_(*c->p)) {
	  name = c->p;
	  for (++c->p; *c->p && !ONE_OF_6(*c->p, ' ', '>', '/', '\n', '\r', '\t'); ++c->p) ;
	  if (!*c->p) {
	    D("Incomplete %s", name);
	    return x;
	  }
	  pop_seen = zx_scan_xmlns(c);  /* Prescan namespaces so that token can be correctly recognized. */
	  tok = zx_elem_lookup(c, name, c->p, &ns);
	  switch (tok) {
          case zx_ds_Transforms_ELEM:
            el = (struct zx_elem_s*)zx_DEC_ds_Transforms(c, ns);
            el->g.n = &x->Transforms->gg.g;
            x->Transforms = (struct zx_ds_Transforms_s*)el;
            break;

	  default:
	    el = zx_known_or_unknown_elem(c, tok, &x->gg, c->p - name, name, ns);
	    tok = ZX_TOK_NOT_FOUND;
	    break;
	  }
          el->g.wo = &x->gg.kids->g;
          x->gg.kids = el;
	  zx_pop_seen(pop_seen);
	  
	  goto next_elem;
	}
      }
      /* false alarm <, fall thru */
    }
    if (!zx_scan_data(c, &x->gg))
      return x;
    goto potential_tag;
  }
 out:
  iternode = x->gg.kids;
  REVERSE_LIST_NEXT(x->gg.kids, iternode, g.wo);
  iternode = (struct zx_elem_s*)(x->gg.any_elem);
  REVERSE_LIST_NEXT(x->gg.any_elem, iternode, g.n);
  ss = (struct zx_str*)(x->gg.any_attr);
  REVERSE_LIST_NEXT(x->gg.any_attr, ss, g.n);
  ZX_END_DEC_EXT(x);
  return x;

 look_for_not_found:
  zx_xml_parse_err(c, '>', (const char*)__FUNCTION__, "char not found");
  return x;
}

#undef EL_NAME
#undef EL_STRUCT
#undef EL_NS
#undef EL_TAG






/* FUNC(zx_DEC_ds_SPKIData) */

#define EL_NAME   ds_SPKIData
#define EL_STRUCT zx_ds_SPKIData_s
#define EL_NS     ds
#define EL_TAG    SPKIData

/* Called by: */
struct zx_ds_SPKIData_s* zx_DEC_ds_SPKIData(struct zx_ctx* c, struct zx_ns_s* ns )
{
  int tok;
  struct zx_elem_s* iternode;
  struct zx_elem_s* el;
  struct zx_str* ss;
  struct zx_ns_s* pop_seen;
  const char* name;
  const char* data;
  struct zx_ds_SPKIData_s* x = ZX_ZALLOC(c, struct zx_ds_SPKIData_s);
  x->gg.g.tok = zx_ds_SPKIData_ELEM;
  x->gg.g.ns = ns;
  ZX_START_DEC_EXT(x);

#if 1 /* NORMALMODE */
  ZX_DEC_TAG_NOT_YET_CLOSED(x->gg.g);

  /* The tag name has already been detected. Process attributes until '>' */
  
  for (; c->p; ++c->p) {
    ZX_SKIP_WS(c,x);
    if (ONE_OF_2(*c->p, '>', '/'))
      break;
    if (!(data = zx_dec_attr_val(c, &name))) {
      D("Decoding attr_val failed %p", c->p);
      return x;
    }
    tok = zx_attr_lookup(c, name, data-2, &ns);
    switch (tok) {

    case ZX_TOK_XMLNS:
      ZX_XMLNS_DEC_EXT(ss);
      DD("xmlns detected(%.*s)", data-2-name, name);
      goto next_attr;
    default:
      ss = zx_dec_unknown_attr(c, &x->gg, name, data, tok, x->gg.g.tok);
    }
    ss->g.ns = ns;
    ss->g.tok = tok;
    ss->g.err |= ZXERR_ATTR_FLAG;
    ss->len = c->p - data;
    ss->s = (char*)data;
next_attr:
    continue;
  }
  if (c->p) {
    ++c->p;
    if (c->p[-1] == '/' && c->p[0] == '>') {  /* Tag without content */
      ++c->p;
      ZX_DEC_TAG_NOW_CLOSED(x->gg.g);
      goto out;
    }
  }
#endif

  /* Process contents until '</' */
  
  ZX_START_BODY_DEC_EXT(x);
  
  while (c->p) {
  next_elem:
    /*ZX_SKIP_WS(c,x);    DO NOT SQUASH WS! EXC-CANON NEEDS IT. */
    if (*c->p == '<') {
    potential_tag:
      ++c->p;
      switch (*c->p) {
      case '?':  /* processing instruction <?xml ... ?> */
      case '!':  /* comment <!-- ... --> */
	if (zx_scan_pi_or_comment(c))
	  break;
	goto next_elem;
      case '/':  /* close tag */
	++c->p;
	name = c->p;
	ZX_LOOK_FOR(c,'>');
#if defined(DEC_WRONG_ELEM)
	if (x->gg.g.ns->prefix_len
	    ?(c->p - name - x->gg.g.ns->prefix_len - 1 != namlen || memcmp(name+x->gg.g.ns->prefix_len+1, nam, namlen))
	    :(c->p-name != namlen || memcmp(name, nam, namlen)))
#else
	tok = zx_elem_lookup(c, name, c->p, &ns);
	if (tok != x->gg.g.tok)
#endif
	{
	  ERR("Mismatching close tag(%.*s) tok=%d context=%d", c->p-name, name, tok, x->gg.g.tok);
	  zx_xml_parse_err(c, '-', (const char*)__FUNCTION__, "Mismatching close tag");
	  ZX_DEC_TAG_MISMATCH_CLOSE(x->gg.g);
	  ++c->p;
	  return x;
	}
	/* Legitimate close tag. Normal exit from this function. */
	++c->p;
	ZX_DEC_TAG_NOW_CLOSED(x->gg.g);
	goto out;
      default:
	if (A_Z_a_z_(*c->p)) {
	  name = c->p;
	  for (++c->p; *c->p && !ONE_OF_6(*c->p, ' ', '>', '/', '\n', '\r', '\t'); ++c->p) ;
	  if (!*c->p) {
	    D("Incomplete %s", name);
	    return x;
	  }
	  pop_seen = zx_scan_xmlns(c);  /* Prescan namespaces so that token can be correctly recognized. */
	  tok = zx_elem_lookup(c, name, c->p, &ns);
	  switch (tok) {
          case zx_ds_SPKISexp_ELEM:
            el = zx_DEC_simple_elem(c, ns, tok);
            el->g.n = &x->SPKISexp->g;
            x->SPKISexp = el;
            break;

	  default:
	    el = zx_known_or_unknown_elem(c, tok, &x->gg, c->p - name, name, ns);
	    tok = ZX_TOK_NOT_FOUND;
	    break;
	  }
          el->g.wo = &x->gg.kids->g;
          x->gg.kids = el;
	  zx_pop_seen(pop_seen);
	  
	  goto next_elem;
	}
      }
      /* false alarm <, fall thru */
    }
    if (!zx_scan_data(c, &x->gg))
      return x;
    goto potential_tag;
  }
 out:
  iternode = x->gg.kids;
  REVERSE_LIST_NEXT(x->gg.kids, iternode, g.wo);
  iternode = (struct zx_elem_s*)(x->gg.any_elem);
  REVERSE_LIST_NEXT(x->gg.any_elem, iternode, g.n);
  ss = (struct zx_str*)(x->gg.any_attr);
  REVERSE_LIST_NEXT(x->gg.any_attr, ss, g.n);
  ZX_END_DEC_EXT(x);
  return x;

 look_for_not_found:
  zx_xml_parse_err(c, '>', (const char*)__FUNCTION__, "char not found");
  return x;
}

#undef EL_NAME
#undef EL_STRUCT
#undef EL_NS
#undef EL_TAG






/* FUNC(zx_DEC_ds_Signature) */

#define EL_NAME   ds_Signature
#define EL_STRUCT zx_ds_Signature_s
#define EL_NS     ds
#define EL_TAG    Signature

/* Called by: */
struct zx_ds_Signature_s* zx_DEC_ds_Signature(struct zx_ctx* c, struct zx_ns_s* ns )
{
  int tok;
  struct zx_elem_s* iternode;
  struct zx_elem_s* el;
  struct zx_str* ss;
  struct zx_ns_s* pop_seen;
  const char* name;
  const char* data;
  struct zx_ds_Signature_s* x = ZX_ZALLOC(c, struct zx_ds_Signature_s);
  x->gg.g.tok = zx_ds_Signature_ELEM;
  x->gg.g.ns = ns;
  ZX_START_DEC_EXT(x);

#if 1 /* NORMALMODE */
  ZX_DEC_TAG_NOT_YET_CLOSED(x->gg.g);

  /* The tag name has already been detected. Process attributes until '>' */
  
  for (; c->p; ++c->p) {
    ZX_SKIP_WS(c,x);
    if (ONE_OF_2(*c->p, '>', '/'))
      break;
    if (!(data = zx_dec_attr_val(c, &name))) {
      D("Decoding attr_val failed %p", c->p);
      return x;
    }
    tok = zx_attr_lookup(c, name, data-2, &ns);
    switch (tok) {
    case zx_Id_ATTR:
      ss = ZX_ZALLOC(c, struct zx_str);
      ss->g.n = &x->Id->g;
      x->Id = ss;
      ZX_ATTR_DEC_EXT(ss);
      break;

    case ZX_TOK_XMLNS:
      ZX_XMLNS_DEC_EXT(ss);
      DD("xmlns detected(%.*s)", data-2-name, name);
      goto next_attr;
    default:
      ss = zx_dec_unknown_attr(c, &x->gg, name, data, tok, x->gg.g.tok);
    }
    ss->g.ns = ns;
    ss->g.tok = tok;
    ss->g.err |= ZXERR_ATTR_FLAG;
    ss->len = c->p - data;
    ss->s = (char*)data;
next_attr:
    continue;
  }
  if (c->p) {
    ++c->p;
    if (c->p[-1] == '/' && c->p[0] == '>') {  /* Tag without content */
      ++c->p;
      ZX_DEC_TAG_NOW_CLOSED(x->gg.g);
      goto out;
    }
  }
#endif

  /* Process contents until '</' */
  
  ZX_START_BODY_DEC_EXT(x);
  
  while (c->p) {
  next_elem:
    /*ZX_SKIP_WS(c,x);    DO NOT SQUASH WS! EXC-CANON NEEDS IT. */
    if (*c->p == '<') {
    potential_tag:
      ++c->p;
      switch (*c->p) {
      case '?':  /* processing instruction <?xml ... ?> */
      case '!':  /* comment <!-- ... --> */
	if (zx_scan_pi_or_comment(c))
	  break;
	goto next_elem;
      case '/':  /* close tag */
	++c->p;
	name = c->p;
	ZX_LOOK_FOR(c,'>');
#if defined(DEC_WRONG_ELEM)
	if (x->gg.g.ns->prefix_len
	    ?(c->p - name - x->gg.g.ns->prefix_len - 1 != namlen || memcmp(name+x->gg.g.ns->prefix_len+1, nam, namlen))
	    :(c->p-name != namlen || memcmp(name, nam, namlen)))
#else
	tok = zx_elem_lookup(c, name, c->p, &ns);
	if (tok != x->gg.g.tok)
#endif
	{
	  ERR("Mismatching close tag(%.*s) tok=%d context=%d", c->p-name, name, tok, x->gg.g.tok);
	  zx_xml_parse_err(c, '-', (const char*)__FUNCTION__, "Mismatching close tag");
	  ZX_DEC_TAG_MISMATCH_CLOSE(x->gg.g);
	  ++c->p;
	  return x;
	}
	/* Legitimate close tag. Normal exit from this function. */
	++c->p;
	ZX_DEC_TAG_NOW_CLOSED(x->gg.g);
	goto out;
      default:
	if (A_Z_a_z_(*c->p)) {
	  name = c->p;
	  for (++c->p; *c->p && !ONE_OF_6(*c->p, ' ', '>', '/', '\n', '\r', '\t'); ++c->p) ;
	  if (!*c->p) {
	    D("Incomplete %s", name);
	    return x;
	  }
	  pop_seen = zx_scan_xmlns(c);  /* Prescan namespaces so that token can be correctly recognized. */
	  tok = zx_elem_lookup(c, name, c->p, &ns);
	  switch (tok) {
          case zx_ds_SignedInfo_ELEM:
            el = (struct zx_elem_s*)zx_DEC_ds_SignedInfo(c, ns);
            el->g.n = &x->SignedInfo->gg.g;
            x->SignedInfo = (struct zx_ds_SignedInfo_s*)el;
            break;
          case zx_ds_SignatureValue_ELEM:
            el = (struct zx_elem_s*)zx_DEC_ds_SignatureValue(c, ns);
            el->g.n = &x->SignatureValue->gg.g;
            x->SignatureValue = (struct zx_ds_SignatureValue_s*)el;
            break;
          case zx_ds_KeyInfo_ELEM:
            el = (struct zx_elem_s*)zx_DEC_ds_KeyInfo(c, ns);
            el->g.n = &x->KeyInfo->gg.g;
            x->KeyInfo = (struct zx_ds_KeyInfo_s*)el;
            break;
          case zx_ds_Object_ELEM:
            el = (struct zx_elem_s*)zx_DEC_ds_Object(c, ns);
            el->g.n = &x->Object->gg.g;
            x->Object = (struct zx_ds_Object_s*)el;
            break;

	  default:
	    el = zx_known_or_unknown_elem(c, tok, &x->gg, c->p - name, name, ns);
	    tok = ZX_TOK_NOT_FOUND;
	    break;
	  }
          el->g.wo = &x->gg.kids->g;
          x->gg.kids = el;
	  zx_pop_seen(pop_seen);
	  
	  goto next_elem;
	}
      }
      /* false alarm <, fall thru */
    }
    if (!zx_scan_data(c, &x->gg))
      return x;
    goto potential_tag;
  }
 out:
  iternode = x->gg.kids;
  REVERSE_LIST_NEXT(x->gg.kids, iternode, g.wo);
  iternode = (struct zx_elem_s*)(x->gg.any_elem);
  REVERSE_LIST_NEXT(x->gg.any_elem, iternode, g.n);
  ss = (struct zx_str*)(x->gg.any_attr);
  REVERSE_LIST_NEXT(x->gg.any_attr, ss, g.n);
  ZX_END_DEC_EXT(x);
  return x;

 look_for_not_found:
  zx_xml_parse_err(c, '>', (const char*)__FUNCTION__, "char not found");
  return x;
}

#undef EL_NAME
#undef EL_STRUCT
#undef EL_NS
#undef EL_TAG






/* FUNC(zx_DEC_ds_SignatureMethod) */

#define EL_NAME   ds_SignatureMethod
#define EL_STRUCT zx_ds_SignatureMethod_s
#define EL_NS     ds
#define EL_TAG    SignatureMethod

/* Called by: */
struct zx_ds_SignatureMethod_s* zx_DEC_ds_SignatureMethod(struct zx_ctx* c, struct zx_ns_s* ns )
{
  int tok;
  struct zx_elem_s* iternode;
  struct zx_elem_s* el;
  struct zx_str* ss;
  struct zx_ns_s* pop_seen;
  const char* name;
  const char* data;
  struct zx_ds_SignatureMethod_s* x = ZX_ZALLOC(c, struct zx_ds_SignatureMethod_s);
  x->gg.g.tok = zx_ds_SignatureMethod_ELEM;
  x->gg.g.ns = ns;
  ZX_START_DEC_EXT(x);

#if 1 /* NORMALMODE */
  ZX_DEC_TAG_NOT_YET_CLOSED(x->gg.g);

  /* The tag name has already been detected. Process attributes until '>' */
  
  for (; c->p; ++c->p) {
    ZX_SKIP_WS(c,x);
    if (ONE_OF_2(*c->p, '>', '/'))
      break;
    if (!(data = zx_dec_attr_val(c, &name))) {
      D("Decoding attr_val failed %p", c->p);
      return x;
    }
    tok = zx_attr_lookup(c, name, data-2, &ns);
    switch (tok) {
    case zx_Algorithm_ATTR:
      ss = ZX_ZALLOC(c, struct zx_str);
      ss->g.n = &x->Algorithm->g;
      x->Algorithm = ss;
      ZX_ATTR_DEC_EXT(ss);
      break;

    case ZX_TOK_XMLNS:
      ZX_XMLNS_DEC_EXT(ss);
      DD("xmlns detected(%.*s)", data-2-name, name);
      goto next_attr;
    default:
      ss = zx_dec_unknown_attr(c, &x->gg, name, data, tok, x->gg.g.tok);
    }
    ss->g.ns = ns;
    ss->g.tok = tok;
    ss->g.err |= ZXERR_ATTR_FLAG;
    ss->len = c->p - data;
    ss->s = (char*)data;
next_attr:
    continue;
  }
  if (c->p) {
    ++c->p;
    if (c->p[-1] == '/' && c->p[0] == '>') {  /* Tag without content */
      ++c->p;
      ZX_DEC_TAG_NOW_CLOSED(x->gg.g);
      goto out;
    }
  }
#endif

  /* Process contents until '</' */
  
  ZX_START_BODY_DEC_EXT(x);
  
  while (c->p) {
  next_elem:
    /*ZX_SKIP_WS(c,x);    DO NOT SQUASH WS! EXC-CANON NEEDS IT. */
    if (*c->p == '<') {
    potential_tag:
      ++c->p;
      switch (*c->p) {
      case '?':  /* processing instruction <?xml ... ?> */
      case '!':  /* comment <!-- ... --> */
	if (zx_scan_pi_or_comment(c))
	  break;
	goto next_elem;
      case '/':  /* close tag */
	++c->p;
	name = c->p;
	ZX_LOOK_FOR(c,'>');
#if defined(DEC_WRONG_ELEM)
	if (x->gg.g.ns->prefix_len
	    ?(c->p - name - x->gg.g.ns->prefix_len - 1 != namlen || memcmp(name+x->gg.g.ns->prefix_len+1, nam, namlen))
	    :(c->p-name != namlen || memcmp(name, nam, namlen)))
#else
	tok = zx_elem_lookup(c, name, c->p, &ns);
	if (tok != x->gg.g.tok)
#endif
	{
	  ERR("Mismatching close tag(%.*s) tok=%d context=%d", c->p-name, name, tok, x->gg.g.tok);
	  zx_xml_parse_err(c, '-', (const char*)__FUNCTION__, "Mismatching close tag");
	  ZX_DEC_TAG_MISMATCH_CLOSE(x->gg.g);
	  ++c->p;
	  return x;
	}
	/* Legitimate close tag. Normal exit from this function. */
	++c->p;
	ZX_DEC_TAG_NOW_CLOSED(x->gg.g);
	goto out;
      default:
	if (A_Z_a_z_(*c->p)) {
	  name = c->p;
	  for (++c->p; *c->p && !ONE_OF_6(*c->p, ' ', '>', '/', '\n', '\r', '\t'); ++c->p) ;
	  if (!*c->p) {
	    D("Incomplete %s", name);
	    return x;
	  }
	  pop_seen = zx_scan_xmlns(c);  /* Prescan namespaces so that token can be correctly recognized. */
	  tok = zx_elem_lookup(c, name, c->p, &ns);
	  switch (tok) {
          case zx_ds_HMACOutputLength_ELEM:
            el = zx_DEC_simple_elem(c, ns, tok);
            el->g.n = &x->HMACOutputLength->g;
            x->HMACOutputLength = el;
            break;

	  default:
	    el = zx_known_or_unknown_elem(c, tok, &x->gg, c->p - name, name, ns);
	    tok = ZX_TOK_NOT_FOUND;
	    break;
	  }
          el->g.wo = &x->gg.kids->g;
          x->gg.kids = el;
	  zx_pop_seen(pop_seen);
	  
	  goto next_elem;
	}
      }
      /* false alarm <, fall thru */
    }
    if (!zx_scan_data(c, &x->gg))
      return x;
    goto potential_tag;
  }
 out:
  iternode = x->gg.kids;
  REVERSE_LIST_NEXT(x->gg.kids, iternode, g.wo);
  iternode = (struct zx_elem_s*)(x->gg.any_elem);
  REVERSE_LIST_NEXT(x->gg.any_elem, iternode, g.n);
  ss = (struct zx_str*)(x->gg.any_attr);
  REVERSE_LIST_NEXT(x->gg.any_attr, ss, g.n);
  ZX_END_DEC_EXT(x);
  return x;

 look_for_not_found:
  zx_xml_parse_err(c, '>', (const char*)__FUNCTION__, "char not found");
  return x;
}

#undef EL_NAME
#undef EL_STRUCT
#undef EL_NS
#undef EL_TAG






/* FUNC(zx_DEC_ds_SignatureProperties) */

#define EL_NAME   ds_SignatureProperties
#define EL_STRUCT zx_ds_SignatureProperties_s
#define EL_NS     ds
#define EL_TAG    SignatureProperties

/* Called by: */
struct zx_ds_SignatureProperties_s* zx_DEC_ds_SignatureProperties(struct zx_ctx* c, struct zx_ns_s* ns )
{
  int tok;
  struct zx_elem_s* iternode;
  struct zx_elem_s* el;
  struct zx_str* ss;
  struct zx_ns_s* pop_seen;
  const char* name;
  const char* data;
  struct zx_ds_SignatureProperties_s* x = ZX_ZALLOC(c, struct zx_ds_SignatureProperties_s);
  x->gg.g.tok = zx_ds_SignatureProperties_ELEM;
  x->gg.g.ns = ns;
  ZX_START_DEC_EXT(x);

#if 1 /* NORMALMODE */
  ZX_DEC_TAG_NOT_YET_CLOSED(x->gg.g);

  /* The tag name has already been detected. Process attributes until '>' */
  
  for (; c->p; ++c->p) {
    ZX_SKIP_WS(c,x);
    if (ONE_OF_2(*c->p, '>', '/'))
      break;
    if (!(data = zx_dec_attr_val(c, &name))) {
      D("Decoding attr_val failed %p", c->p);
      return x;
    }
    tok = zx_attr_lookup(c, name, data-2, &ns);
    switch (tok) {
    case zx_Id_ATTR:
      ss = ZX_ZALLOC(c, struct zx_str);
      ss->g.n = &x->Id->g;
      x->Id = ss;
      ZX_ATTR_DEC_EXT(ss);
      break;

    case ZX_TOK_XMLNS:
      ZX_XMLNS_DEC_EXT(ss);
      DD("xmlns detected(%.*s)", data-2-name, name);
      goto next_attr;
    default:
      ss = zx_dec_unknown_attr(c, &x->gg, name, data, tok, x->gg.g.tok);
    }
    ss->g.ns = ns;
    ss->g.tok = tok;
    ss->g.err |= ZXERR_ATTR_FLAG;
    ss->len = c->p - data;
    ss->s = (char*)data;
next_attr:
    continue;
  }
  if (c->p) {
    ++c->p;
    if (c->p[-1] == '/' && c->p[0] == '>') {  /* Tag without content */
      ++c->p;
      ZX_DEC_TAG_NOW_CLOSED(x->gg.g);
      goto out;
    }
  }
#endif

  /* Process contents until '</' */
  
  ZX_START_BODY_DEC_EXT(x);
  
  while (c->p) {
  next_elem:
    /*ZX_SKIP_WS(c,x);    DO NOT SQUASH WS! EXC-CANON NEEDS IT. */
    if (*c->p == '<') {
    potential_tag:
      ++c->p;
      switch (*c->p) {
      case '?':  /* processing instruction <?xml ... ?> */
      case '!':  /* comment <!-- ... --> */
	if (zx_scan_pi_or_comment(c))
	  break;
	goto next_elem;
      case '/':  /* close tag */
	++c->p;
	name = c->p;
	ZX_LOOK_FOR(c,'>');
#if defined(DEC_WRONG_ELEM)
	if (x->gg.g.ns->prefix_len
	    ?(c->p - name - x->gg.g.ns->prefix_len - 1 != namlen || memcmp(name+x->gg.g.ns->prefix_len+1, nam, namlen))
	    :(c->p-name != namlen || memcmp(name, nam, namlen)))
#else
	tok = zx_elem_lookup(c, name, c->p, &ns);
	if (tok != x->gg.g.tok)
#endif
	{
	  ERR("Mismatching close tag(%.*s) tok=%d context=%d", c->p-name, name, tok, x->gg.g.tok);
	  zx_xml_parse_err(c, '-', (const char*)__FUNCTION__, "Mismatching close tag");
	  ZX_DEC_TAG_MISMATCH_CLOSE(x->gg.g);
	  ++c->p;
	  return x;
	}
	/* Legitimate close tag. Normal exit from this function. */
	++c->p;
	ZX_DEC_TAG_NOW_CLOSED(x->gg.g);
	goto out;
      default:
	if (A_Z_a_z_(*c->p)) {
	  name = c->p;
	  for (++c->p; *c->p && !ONE_OF_6(*c->p, ' ', '>', '/', '\n', '\r', '\t'); ++c->p) ;
	  if (!*c->p) {
	    D("Incomplete %s", name);
	    return x;
	  }
	  pop_seen = zx_scan_xmlns(c);  /* Prescan namespaces so that token can be correctly recognized. */
	  tok = zx_elem_lookup(c, name, c->p, &ns);
	  switch (tok) {
          case zx_ds_SignatureProperty_ELEM:
            el = (struct zx_elem_s*)zx_DEC_ds_SignatureProperty(c, ns);
            el->g.n = &x->SignatureProperty->gg.g;
            x->SignatureProperty = (struct zx_ds_SignatureProperty_s*)el;
            break;

	  default:
	    el = zx_known_or_unknown_elem(c, tok, &x->gg, c->p - name, name, ns);
	    tok = ZX_TOK_NOT_FOUND;
	    break;
	  }
          el->g.wo = &x->gg.kids->g;
          x->gg.kids = el;
	  zx_pop_seen(pop_seen);
	  
	  goto next_elem;
	}
      }
      /* false alarm <, fall thru */
    }
    if (!zx_scan_data(c, &x->gg))
      return x;
    goto potential_tag;
  }
 out:
  iternode = x->gg.kids;
  REVERSE_LIST_NEXT(x->gg.kids, iternode, g.wo);
  iternode = (struct zx_elem_s*)(x->gg.any_elem);
  REVERSE_LIST_NEXT(x->gg.any_elem, iternode, g.n);
  ss = (struct zx_str*)(x->gg.any_attr);
  REVERSE_LIST_NEXT(x->gg.any_attr, ss, g.n);
  ZX_END_DEC_EXT(x);
  return x;

 look_for_not_found:
  zx_xml_parse_err(c, '>', (const char*)__FUNCTION__, "char not found");
  return x;
}

#undef EL_NAME
#undef EL_STRUCT
#undef EL_NS
#undef EL_TAG






/* FUNC(zx_DEC_ds_SignatureProperty) */

#define EL_NAME   ds_SignatureProperty
#define EL_STRUCT zx_ds_SignatureProperty_s
#define EL_NS     ds
#define EL_TAG    SignatureProperty

/* Called by: */
struct zx_ds_SignatureProperty_s* zx_DEC_ds_SignatureProperty(struct zx_ctx* c, struct zx_ns_s* ns )
{
  int tok;
  struct zx_elem_s* iternode;
  struct zx_elem_s* el;
  struct zx_str* ss;
  struct zx_ns_s* pop_seen;
  const char* name;
  const char* data;
  struct zx_ds_SignatureProperty_s* x = ZX_ZALLOC(c, struct zx_ds_SignatureProperty_s);
  x->gg.g.tok = zx_ds_SignatureProperty_ELEM;
  x->gg.g.ns = ns;
  ZX_START_DEC_EXT(x);

#if 1 /* NORMALMODE */
  ZX_DEC_TAG_NOT_YET_CLOSED(x->gg.g);

  /* The tag name has already been detected. Process attributes until '>' */
  
  for (; c->p; ++c->p) {
    ZX_SKIP_WS(c,x);
    if (ONE_OF_2(*c->p, '>', '/'))
      break;
    if (!(data = zx_dec_attr_val(c, &name))) {
      D("Decoding attr_val failed %p", c->p);
      return x;
    }
    tok = zx_attr_lookup(c, name, data-2, &ns);
    switch (tok) {
    case zx_Id_ATTR:
      ss = ZX_ZALLOC(c, struct zx_str);
      ss->g.n = &x->Id->g;
      x->Id = ss;
      ZX_ATTR_DEC_EXT(ss);
      break;
    case zx_Target_ATTR:
      ss = ZX_ZALLOC(c, struct zx_str);
      ss->g.n = &x->Target->g;
      x->Target = ss;
      ZX_ATTR_DEC_EXT(ss);
      break;

    case ZX_TOK_XMLNS:
      ZX_XMLNS_DEC_EXT(ss);
      DD("xmlns detected(%.*s)", data-2-name, name);
      goto next_attr;
    default:
      ss = zx_dec_unknown_attr(c, &x->gg, name, data, tok, x->gg.g.tok);
    }
    ss->g.ns = ns;
    ss->g.tok = tok;
    ss->g.err |= ZXERR_ATTR_FLAG;
    ss->len = c->p - data;
    ss->s = (char*)data;
next_attr:
    continue;
  }
  if (c->p) {
    ++c->p;
    if (c->p[-1] == '/' && c->p[0] == '>') {  /* Tag without content */
      ++c->p;
      ZX_DEC_TAG_NOW_CLOSED(x->gg.g);
      goto out;
    }
  }
#endif

  /* Process contents until '</' */
  
  ZX_START_BODY_DEC_EXT(x);
  
  while (c->p) {
  next_elem:
    /*ZX_SKIP_WS(c,x);    DO NOT SQUASH WS! EXC-CANON NEEDS IT. */
    if (*c->p == '<') {
    potential_tag:
      ++c->p;
      switch (*c->p) {
      case '?':  /* processing instruction <?xml ... ?> */
      case '!':  /* comment <!-- ... --> */
	if (zx_scan_pi_or_comment(c))
	  break;
	goto next_elem;
      case '/':  /* close tag */
	++c->p;
	name = c->p;
	ZX_LOOK_FOR(c,'>');
#if defined(DEC_WRONG_ELEM)
	if (x->gg.g.ns->prefix_len
	    ?(c->p - name - x->gg.g.ns->prefix_len - 1 != namlen || memcmp(name+x->gg.g.ns->prefix_len+1, nam, namlen))
	    :(c->p-name != namlen || memcmp(name, nam, namlen)))
#else
	tok = zx_elem_lookup(c, name, c->p, &ns);
	if (tok != x->gg.g.tok)
#endif
	{
	  ERR("Mismatching close tag(%.*s) tok=%d context=%d", c->p-name, name, tok, x->gg.g.tok);
	  zx_xml_parse_err(c, '-', (const char*)__FUNCTION__, "Mismatching close tag");
	  ZX_DEC_TAG_MISMATCH_CLOSE(x->gg.g);
	  ++c->p;
	  return x;
	}
	/* Legitimate close tag. Normal exit from this function. */
	++c->p;
	ZX_DEC_TAG_NOW_CLOSED(x->gg.g);
	goto out;
      default:
	if (A_Z_a_z_(*c->p)) {
	  name = c->p;
	  for (++c->p; *c->p && !ONE_OF_6(*c->p, ' ', '>', '/', '\n', '\r', '\t'); ++c->p) ;
	  if (!*c->p) {
	    D("Incomplete %s", name);
	    return x;
	  }
	  pop_seen = zx_scan_xmlns(c);  /* Prescan namespaces so that token can be correctly recognized. */
	  tok = zx_elem_lookup(c, name, c->p, &ns);
	  switch (tok) {

	  default:
	    el = zx_known_or_unknown_elem(c, tok, &x->gg, c->p - name, name, ns);
	    tok = ZX_TOK_NOT_FOUND;
	    break;
	  }
          el->g.wo = &x->gg.kids->g;
          x->gg.kids = el;
	  zx_pop_seen(pop_seen);
	  
	  goto next_elem;
	}
      }
      /* false alarm <, fall thru */
    }
    if (!zx_scan_data(c, &x->gg))
      return x;
    goto potential_tag;
  }
 out:
  iternode = x->gg.kids;
  REVERSE_LIST_NEXT(x->gg.kids, iternode, g.wo);
  iternode = (struct zx_elem_s*)(x->gg.any_elem);
  REVERSE_LIST_NEXT(x->gg.any_elem, iternode, g.n);
  ss = (struct zx_str*)(x->gg.any_attr);
  REVERSE_LIST_NEXT(x->gg.any_attr, ss, g.n);
  ZX_END_DEC_EXT(x);
  return x;

 look_for_not_found:
  zx_xml_parse_err(c, '>', (const char*)__FUNCTION__, "char not found");
  return x;
}

#undef EL_NAME
#undef EL_STRUCT
#undef EL_NS
#undef EL_TAG






/* FUNC(zx_DEC_ds_SignatureValue) */

#define EL_NAME   ds_SignatureValue
#define EL_STRUCT zx_ds_SignatureValue_s
#define EL_NS     ds
#define EL_TAG    SignatureValue

/* Called by: */
struct zx_ds_SignatureValue_s* zx_DEC_ds_SignatureValue(struct zx_ctx* c, struct zx_ns_s* ns )
{
  int tok;
  struct zx_elem_s* iternode;
  struct zx_elem_s* el;
  struct zx_str* ss;
  struct zx_ns_s* pop_seen;
  const char* name;
  const char* data;
  struct zx_ds_SignatureValue_s* x = ZX_ZALLOC(c, struct zx_ds_SignatureValue_s);
  x->gg.g.tok = zx_ds_SignatureValue_ELEM;
  x->gg.g.ns = ns;
  ZX_START_DEC_EXT(x);

#if 1 /* NORMALMODE */
  ZX_DEC_TAG_NOT_YET_CLOSED(x->gg.g);

  /* The tag name has already been detected. Process attributes until '>' */
  
  for (; c->p; ++c->p) {
    ZX_SKIP_WS(c,x);
    if (ONE_OF_2(*c->p, '>', '/'))
      break;
    if (!(data = zx_dec_attr_val(c, &name))) {
      D("Decoding attr_val failed %p", c->p);
      return x;
    }
    tok = zx_attr_lookup(c, name, data-2, &ns);
    switch (tok) {
    case zx_Id_ATTR:
      ss = ZX_ZALLOC(c, struct zx_str);
      ss->g.n = &x->Id->g;
      x->Id = ss;
      ZX_ATTR_DEC_EXT(ss);
      break;

    case ZX_TOK_XMLNS:
      ZX_XMLNS_DEC_EXT(ss);
      DD("xmlns detected(%.*s)", data-2-name, name);
      goto next_attr;
    default:
      ss = zx_dec_unknown_attr(c, &x->gg, name, data, tok, x->gg.g.tok);
    }
    ss->g.ns = ns;
    ss->g.tok = tok;
    ss->g.err |= ZXERR_ATTR_FLAG;
    ss->len = c->p - data;
    ss->s = (char*)data;
next_attr:
    continue;
  }
  if (c->p) {
    ++c->p;
    if (c->p[-1] == '/' && c->p[0] == '>') {  /* Tag without content */
      ++c->p;
      ZX_DEC_TAG_NOW_CLOSED(x->gg.g);
      goto out;
    }
  }
#endif

  /* Process contents until '</' */
  
  ZX_START_BODY_DEC_EXT(x);
  
  while (c->p) {
  next_elem:
    /*ZX_SKIP_WS(c,x);    DO NOT SQUASH WS! EXC-CANON NEEDS IT. */
    if (*c->p == '<') {
    potential_tag:
      ++c->p;
      switch (*c->p) {
      case '?':  /* processing instruction <?xml ... ?> */
      case '!':  /* comment <!-- ... --> */
	if (zx_scan_pi_or_comment(c))
	  break;
	goto next_elem;
      case '/':  /* close tag */
	++c->p;
	name = c->p;
	ZX_LOOK_FOR(c,'>');
#if defined(DEC_WRONG_ELEM)
	if (x->gg.g.ns->prefix_len
	    ?(c->p - name - x->gg.g.ns->prefix_len - 1 != namlen || memcmp(name+x->gg.g.ns->prefix_len+1, nam, namlen))
	    :(c->p-name != namlen || memcmp(name, nam, namlen)))
#else
	tok = zx_elem_lookup(c, name, c->p, &ns);
	if (tok != x->gg.g.tok)
#endif
	{
	  ERR("Mismatching close tag(%.*s) tok=%d context=%d", c->p-name, name, tok, x->gg.g.tok);
	  zx_xml_parse_err(c, '-', (const char*)__FUNCTION__, "Mismatching close tag");
	  ZX_DEC_TAG_MISMATCH_CLOSE(x->gg.g);
	  ++c->p;
	  return x;
	}
	/* Legitimate close tag. Normal exit from this function. */
	++c->p;
	ZX_DEC_TAG_NOW_CLOSED(x->gg.g);
	goto out;
      default:
	if (A_Z_a_z_(*c->p)) {
	  name = c->p;
	  for (++c->p; *c->p && !ONE_OF_6(*c->p, ' ', '>', '/', '\n', '\r', '\t'); ++c->p) ;
	  if (!*c->p) {
	    D("Incomplete %s", name);
	    return x;
	  }
	  pop_seen = zx_scan_xmlns(c);  /* Prescan namespaces so that token can be correctly recognized. */
	  tok = zx_elem_lookup(c, name, c->p, &ns);
	  switch (tok) {

	  default:
	    el = zx_known_or_unknown_elem(c, tok, &x->gg, c->p - name, name, ns);
	    tok = ZX_TOK_NOT_FOUND;
	    break;
	  }
          el->g.wo = &x->gg.kids->g;
          x->gg.kids = el;
	  zx_pop_seen(pop_seen);
	  
	  goto next_elem;
	}
      }
      /* false alarm <, fall thru */
    }
    if (!zx_scan_data(c, &x->gg))
      return x;
    goto potential_tag;
  }
 out:
  iternode = x->gg.kids;
  REVERSE_LIST_NEXT(x->gg.kids, iternode, g.wo);
  iternode = (struct zx_elem_s*)(x->gg.any_elem);
  REVERSE_LIST_NEXT(x->gg.any_elem, iternode, g.n);
  ss = (struct zx_str*)(x->gg.any_attr);
  REVERSE_LIST_NEXT(x->gg.any_attr, ss, g.n);
  ZX_END_DEC_EXT(x);
  return x;

 look_for_not_found:
  zx_xml_parse_err(c, '>', (const char*)__FUNCTION__, "char not found");
  return x;
}

#undef EL_NAME
#undef EL_STRUCT
#undef EL_NS
#undef EL_TAG






/* FUNC(zx_DEC_ds_SignedInfo) */

#define EL_NAME   ds_SignedInfo
#define EL_STRUCT zx_ds_SignedInfo_s
#define EL_NS     ds
#define EL_TAG    SignedInfo

/* Called by: */
struct zx_ds_SignedInfo_s* zx_DEC_ds_SignedInfo(struct zx_ctx* c, struct zx_ns_s* ns )
{
  int tok;
  struct zx_elem_s* iternode;
  struct zx_elem_s* el;
  struct zx_str* ss;
  struct zx_ns_s* pop_seen;
  const char* name;
  const char* data;
  struct zx_ds_SignedInfo_s* x = ZX_ZALLOC(c, struct zx_ds_SignedInfo_s);
  x->gg.g.tok = zx_ds_SignedInfo_ELEM;
  x->gg.g.ns = ns;
  ZX_START_DEC_EXT(x);

#if 1 /* NORMALMODE */
  ZX_DEC_TAG_NOT_YET_CLOSED(x->gg.g);

  /* The tag name has already been detected. Process attributes until '>' */
  
  for (; c->p; ++c->p) {
    ZX_SKIP_WS(c,x);
    if (ONE_OF_2(*c->p, '>', '/'))
      break;
    if (!(data = zx_dec_attr_val(c, &name))) {
      D("Decoding attr_val failed %p", c->p);
      return x;
    }
    tok = zx_attr_lookup(c, name, data-2, &ns);
    switch (tok) {
    case zx_Id_ATTR:
      ss = ZX_ZALLOC(c, struct zx_str);
      ss->g.n = &x->Id->g;
      x->Id = ss;
      ZX_ATTR_DEC_EXT(ss);
      break;

    case ZX_TOK_XMLNS:
      ZX_XMLNS_DEC_EXT(ss);
      DD("xmlns detected(%.*s)", data-2-name, name);
      goto next_attr;
    default:
      ss = zx_dec_unknown_attr(c, &x->gg, name, data, tok, x->gg.g.tok);
    }
    ss->g.ns = ns;
    ss->g.tok = tok;
    ss->g.err |= ZXERR_ATTR_FLAG;
    ss->len = c->p - data;
    ss->s = (char*)data;
next_attr:
    continue;
  }
  if (c->p) {
    ++c->p;
    if (c->p[-1] == '/' && c->p[0] == '>') {  /* Tag without content */
      ++c->p;
      ZX_DEC_TAG_NOW_CLOSED(x->gg.g);
      goto out;
    }
  }
#endif

  /* Process contents until '</' */
  
  ZX_START_BODY_DEC_EXT(x);
  
  while (c->p) {
  next_elem:
    /*ZX_SKIP_WS(c,x);    DO NOT SQUASH WS! EXC-CANON NEEDS IT. */
    if (*c->p == '<') {
    potential_tag:
      ++c->p;
      switch (*c->p) {
      case '?':  /* processing instruction <?xml ... ?> */
      case '!':  /* comment <!-- ... --> */
	if (zx_scan_pi_or_comment(c))
	  break;
	goto next_elem;
      case '/':  /* close tag */
	++c->p;
	name = c->p;
	ZX_LOOK_FOR(c,'>');
#if defined(DEC_WRONG_ELEM)
	if (x->gg.g.ns->prefix_len
	    ?(c->p - name - x->gg.g.ns->prefix_len - 1 != namlen || memcmp(name+x->gg.g.ns->prefix_len+1, nam, namlen))
	    :(c->p-name != namlen || memcmp(name, nam, namlen)))
#else
	tok = zx_elem_lookup(c, name, c->p, &ns);
	if (tok != x->gg.g.tok)
#endif
	{
	  ERR("Mismatching close tag(%.*s) tok=%d context=%d", c->p-name, name, tok, x->gg.g.tok);
	  zx_xml_parse_err(c, '-', (const char*)__FUNCTION__, "Mismatching close tag");
	  ZX_DEC_TAG_MISMATCH_CLOSE(x->gg.g);
	  ++c->p;
	  return x;
	}
	/* Legitimate close tag. Normal exit from this function. */
	++c->p;
	ZX_DEC_TAG_NOW_CLOSED(x->gg.g);
	goto out;
      default:
	if (A_Z_a_z_(*c->p)) {
	  name = c->p;
	  for (++c->p; *c->p && !ONE_OF_6(*c->p, ' ', '>', '/', '\n', '\r', '\t'); ++c->p) ;
	  if (!*c->p) {
	    D("Incomplete %s", name);
	    return x;
	  }
	  pop_seen = zx_scan_xmlns(c);  /* Prescan namespaces so that token can be correctly recognized. */
	  tok = zx_elem_lookup(c, name, c->p, &ns);
	  switch (tok) {
          case zx_ds_CanonicalizationMethod_ELEM:
            el = (struct zx_elem_s*)zx_DEC_ds_CanonicalizationMethod(c, ns);
            el->g.n = &x->CanonicalizationMethod->gg.g;
            x->CanonicalizationMethod = (struct zx_ds_CanonicalizationMethod_s*)el;
            break;
          case zx_ds_SignatureMethod_ELEM:
            el = (struct zx_elem_s*)zx_DEC_ds_SignatureMethod(c, ns);
            el->g.n = &x->SignatureMethod->gg.g;
            x->SignatureMethod = (struct zx_ds_SignatureMethod_s*)el;
            break;
          case zx_ds_Reference_ELEM:
            el = (struct zx_elem_s*)zx_DEC_ds_Reference(c, ns);
            el->g.n = &x->Reference->gg.g;
            x->Reference = (struct zx_ds_Reference_s*)el;
            break;

	  default:
	    el = zx_known_or_unknown_elem(c, tok, &x->gg, c->p - name, name, ns);
	    tok = ZX_TOK_NOT_FOUND;
	    break;
	  }
          el->g.wo = &x->gg.kids->g;
          x->gg.kids = el;
	  zx_pop_seen(pop_seen);
	  
	  goto next_elem;
	}
      }
      /* false alarm <, fall thru */
    }
    if (!zx_scan_data(c, &x->gg))
      return x;
    goto potential_tag;
  }
 out:
  iternode = x->gg.kids;
  REVERSE_LIST_NEXT(x->gg.kids, iternode, g.wo);
  iternode = (struct zx_elem_s*)(x->gg.any_elem);
  REVERSE_LIST_NEXT(x->gg.any_elem, iternode, g.n);
  ss = (struct zx_str*)(x->gg.any_attr);
  REVERSE_LIST_NEXT(x->gg.any_attr, ss, g.n);
  ZX_END_DEC_EXT(x);
  return x;

 look_for_not_found:
  zx_xml_parse_err(c, '>', (const char*)__FUNCTION__, "char not found");
  return x;
}

#undef EL_NAME
#undef EL_STRUCT
#undef EL_NS
#undef EL_TAG






/* FUNC(zx_DEC_ds_Transform) */

#define EL_NAME   ds_Transform
#define EL_STRUCT zx_ds_Transform_s
#define EL_NS     ds
#define EL_TAG    Transform

/* Called by: */
struct zx_ds_Transform_s* zx_DEC_ds_Transform(struct zx_ctx* c, struct zx_ns_s* ns )
{
  int tok;
  struct zx_elem_s* iternode;
  struct zx_elem_s* el;
  struct zx_str* ss;
  struct zx_ns_s* pop_seen;
  const char* name;
  const char* data;
  struct zx_ds_Transform_s* x = ZX_ZALLOC(c, struct zx_ds_Transform_s);
  x->gg.g.tok = zx_ds_Transform_ELEM;
  x->gg.g.ns = ns;
  ZX_START_DEC_EXT(x);

#if 1 /* NORMALMODE */
  ZX_DEC_TAG_NOT_YET_CLOSED(x->gg.g);

  /* The tag name has already been detected. Process attributes until '>' */
  
  for (; c->p; ++c->p) {
    ZX_SKIP_WS(c,x);
    if (ONE_OF_2(*c->p, '>', '/'))
      break;
    if (!(data = zx_dec_attr_val(c, &name))) {
      D("Decoding attr_val failed %p", c->p);
      return x;
    }
    tok = zx_attr_lookup(c, name, data-2, &ns);
    switch (tok) {
    case zx_Algorithm_ATTR:
      ss = ZX_ZALLOC(c, struct zx_str);
      ss->g.n = &x->Algorithm->g;
      x->Algorithm = ss;
      ZX_ATTR_DEC_EXT(ss);
      break;

    case ZX_TOK_XMLNS:
      ZX_XMLNS_DEC_EXT(ss);
      DD("xmlns detected(%.*s)", data-2-name, name);
      goto next_attr;
    default:
      ss = zx_dec_unknown_attr(c, &x->gg, name, data, tok, x->gg.g.tok);
    }
    ss->g.ns = ns;
    ss->g.tok = tok;
    ss->g.err |= ZXERR_ATTR_FLAG;
    ss->len = c->p - data;
    ss->s = (char*)data;
next_attr:
    continue;
  }
  if (c->p) {
    ++c->p;
    if (c->p[-1] == '/' && c->p[0] == '>') {  /* Tag without content */
      ++c->p;
      ZX_DEC_TAG_NOW_CLOSED(x->gg.g);
      goto out;
    }
  }
#endif

  /* Process contents until '</' */
  
  ZX_START_BODY_DEC_EXT(x);
  
  while (c->p) {
  next_elem:
    /*ZX_SKIP_WS(c,x);    DO NOT SQUASH WS! EXC-CANON NEEDS IT. */
    if (*c->p == '<') {
    potential_tag:
      ++c->p;
      switch (*c->p) {
      case '?':  /* processing instruction <?xml ... ?> */
      case '!':  /* comment <!-- ... --> */
	if (zx_scan_pi_or_comment(c))
	  break;
	goto next_elem;
      case '/':  /* close tag */
	++c->p;
	name = c->p;
	ZX_LOOK_FOR(c,'>');
#if defined(DEC_WRONG_ELEM)
	if (x->gg.g.ns->prefix_len
	    ?(c->p - name - x->gg.g.ns->prefix_len - 1 != namlen || memcmp(name+x->gg.g.ns->prefix_len+1, nam, namlen))
	    :(c->p-name != namlen || memcmp(name, nam, namlen)))
#else
	tok = zx_elem_lookup(c, name, c->p, &ns);
	if (tok != x->gg.g.tok)
#endif
	{
	  ERR("Mismatching close tag(%.*s) tok=%d context=%d", c->p-name, name, tok, x->gg.g.tok);
	  zx_xml_parse_err(c, '-', (const char*)__FUNCTION__, "Mismatching close tag");
	  ZX_DEC_TAG_MISMATCH_CLOSE(x->gg.g);
	  ++c->p;
	  return x;
	}
	/* Legitimate close tag. Normal exit from this function. */
	++c->p;
	ZX_DEC_TAG_NOW_CLOSED(x->gg.g);
	goto out;
      default:
	if (A_Z_a_z_(*c->p)) {
	  name = c->p;
	  for (++c->p; *c->p && !ONE_OF_6(*c->p, ' ', '>', '/', '\n', '\r', '\t'); ++c->p) ;
	  if (!*c->p) {
	    D("Incomplete %s", name);
	    return x;
	  }
	  pop_seen = zx_scan_xmlns(c);  /* Prescan namespaces so that token can be correctly recognized. */
	  tok = zx_elem_lookup(c, name, c->p, &ns);
	  switch (tok) {
          case zx_ds_XPath_ELEM:
            el = zx_DEC_simple_elem(c, ns, tok);
            el->g.n = &x->XPath->g;
            x->XPath = el;
            break;
          case zx_exca_InclusiveNamespaces_ELEM:
            el = (struct zx_elem_s*)zx_DEC_exca_InclusiveNamespaces(c, ns);
            el->g.n = &x->InclusiveNamespaces->gg.g;
            x->InclusiveNamespaces = (struct zx_exca_InclusiveNamespaces_s*)el;
            break;

	  default:
	    el = zx_known_or_unknown_elem(c, tok, &x->gg, c->p - name, name, ns);
	    tok = ZX_TOK_NOT_FOUND;
	    break;
	  }
          el->g.wo = &x->gg.kids->g;
          x->gg.kids = el;
	  zx_pop_seen(pop_seen);
	  
	  goto next_elem;
	}
      }
      /* false alarm <, fall thru */
    }
    if (!zx_scan_data(c, &x->gg))
      return x;
    goto potential_tag;
  }
 out:
  iternode = x->gg.kids;
  REVERSE_LIST_NEXT(x->gg.kids, iternode, g.wo);
  iternode = (struct zx_elem_s*)(x->gg.any_elem);
  REVERSE_LIST_NEXT(x->gg.any_elem, iternode, g.n);
  ss = (struct zx_str*)(x->gg.any_attr);
  REVERSE_LIST_NEXT(x->gg.any_attr, ss, g.n);
  ZX_END_DEC_EXT(x);
  return x;

 look_for_not_found:
  zx_xml_parse_err(c, '>', (const char*)__FUNCTION__, "char not found");
  return x;
}

#undef EL_NAME
#undef EL_STRUCT
#undef EL_NS
#undef EL_TAG






/* FUNC(zx_DEC_ds_Transforms) */

#define EL_NAME   ds_Transforms
#define EL_STRUCT zx_ds_Transforms_s
#define EL_NS     ds
#define EL_TAG    Transforms

/* Called by: */
struct zx_ds_Transforms_s* zx_DEC_ds_Transforms(struct zx_ctx* c, struct zx_ns_s* ns )
{
  int tok;
  struct zx_elem_s* iternode;
  struct zx_elem_s* el;
  struct zx_str* ss;
  struct zx_ns_s* pop_seen;
  const char* name;
  const char* data;
  struct zx_ds_Transforms_s* x = ZX_ZALLOC(c, struct zx_ds_Transforms_s);
  x->gg.g.tok = zx_ds_Transforms_ELEM;
  x->gg.g.ns = ns;
  ZX_START_DEC_EXT(x);

#if 1 /* NORMALMODE */
  ZX_DEC_TAG_NOT_YET_CLOSED(x->gg.g);

  /* The tag name has already been detected. Process attributes until '>' */
  
  for (; c->p; ++c->p) {
    ZX_SKIP_WS(c,x);
    if (ONE_OF_2(*c->p, '>', '/'))
      break;
    if (!(data = zx_dec_attr_val(c, &name))) {
      D("Decoding attr_val failed %p", c->p);
      return x;
    }
    tok = zx_attr_lookup(c, name, data-2, &ns);
    switch (tok) {

    case ZX_TOK_XMLNS:
      ZX_XMLNS_DEC_EXT(ss);
      DD("xmlns detected(%.*s)", data-2-name, name);
      goto next_attr;
    default:
      ss = zx_dec_unknown_attr(c, &x->gg, name, data, tok, x->gg.g.tok);
    }
    ss->g.ns = ns;
    ss->g.tok = tok;
    ss->g.err |= ZXERR_ATTR_FLAG;
    ss->len = c->p - data;
    ss->s = (char*)data;
next_attr:
    continue;
  }
  if (c->p) {
    ++c->p;
    if (c->p[-1] == '/' && c->p[0] == '>') {  /* Tag without content */
      ++c->p;
      ZX_DEC_TAG_NOW_CLOSED(x->gg.g);
      goto out;
    }
  }
#endif

  /* Process contents until '</' */
  
  ZX_START_BODY_DEC_EXT(x);
  
  while (c->p) {
  next_elem:
    /*ZX_SKIP_WS(c,x);    DO NOT SQUASH WS! EXC-CANON NEEDS IT. */
    if (*c->p == '<') {
    potential_tag:
      ++c->p;
      switch (*c->p) {
      case '?':  /* processing instruction <?xml ... ?> */
      case '!':  /* comment <!-- ... --> */
	if (zx_scan_pi_or_comment(c))
	  break;
	goto next_elem;
      case '/':  /* close tag */
	++c->p;
	name = c->p;
	ZX_LOOK_FOR(c,'>');
#if defined(DEC_WRONG_ELEM)
	if (x->gg.g.ns->prefix_len
	    ?(c->p - name - x->gg.g.ns->prefix_len - 1 != namlen || memcmp(name+x->gg.g.ns->prefix_len+1, nam, namlen))
	    :(c->p-name != namlen || memcmp(name, nam, namlen)))
#else
	tok = zx_elem_lookup(c, name, c->p, &ns);
	if (tok != x->gg.g.tok)
#endif
	{
	  ERR("Mismatching close tag(%.*s) tok=%d context=%d", c->p-name, name, tok, x->gg.g.tok);
	  zx_xml_parse_err(c, '-', (const char*)__FUNCTION__, "Mismatching close tag");
	  ZX_DEC_TAG_MISMATCH_CLOSE(x->gg.g);
	  ++c->p;
	  return x;
	}
	/* Legitimate close tag. Normal exit from this function. */
	++c->p;
	ZX_DEC_TAG_NOW_CLOSED(x->gg.g);
	goto out;
      default:
	if (A_Z_a_z_(*c->p)) {
	  name = c->p;
	  for (++c->p; *c->p && !ONE_OF_6(*c->p, ' ', '>', '/', '\n', '\r', '\t'); ++c->p) ;
	  if (!*c->p) {
	    D("Incomplete %s", name);
	    return x;
	  }
	  pop_seen = zx_scan_xmlns(c);  /* Prescan namespaces so that token can be correctly recognized. */
	  tok = zx_elem_lookup(c, name, c->p, &ns);
	  switch (tok) {
          case zx_ds_Transform_ELEM:
            el = (struct zx_elem_s*)zx_DEC_ds_Transform(c, ns);
            el->g.n = &x->Transform->gg.g;
            x->Transform = (struct zx_ds_Transform_s*)el;
            break;

	  default:
	    el = zx_known_or_unknown_elem(c, tok, &x->gg, c->p - name, name, ns);
	    tok = ZX_TOK_NOT_FOUND;
	    break;
	  }
          el->g.wo = &x->gg.kids->g;
          x->gg.kids = el;
	  zx_pop_seen(pop_seen);
	  
	  goto next_elem;
	}
      }
      /* false alarm <, fall thru */
    }
    if (!zx_scan_data(c, &x->gg))
      return x;
    goto potential_tag;
  }
 out:
  iternode = x->gg.kids;
  REVERSE_LIST_NEXT(x->gg.kids, iternode, g.wo);
  iternode = (struct zx_elem_s*)(x->gg.any_elem);
  REVERSE_LIST_NEXT(x->gg.any_elem, iternode, g.n);
  ss = (struct zx_str*)(x->gg.any_attr);
  REVERSE_LIST_NEXT(x->gg.any_attr, ss, g.n);
  ZX_END_DEC_EXT(x);
  return x;

 look_for_not_found:
  zx_xml_parse_err(c, '>', (const char*)__FUNCTION__, "char not found");
  return x;
}

#undef EL_NAME
#undef EL_STRUCT
#undef EL_NS
#undef EL_TAG






/* FUNC(zx_DEC_ds_X509Data) */

#define EL_NAME   ds_X509Data
#define EL_STRUCT zx_ds_X509Data_s
#define EL_NS     ds
#define EL_TAG    X509Data

/* Called by: */
struct zx_ds_X509Data_s* zx_DEC_ds_X509Data(struct zx_ctx* c, struct zx_ns_s* ns )
{
  int tok;
  struct zx_elem_s* iternode;
  struct zx_elem_s* el;
  struct zx_str* ss;
  struct zx_ns_s* pop_seen;
  const char* name;
  const char* data;
  struct zx_ds_X509Data_s* x = ZX_ZALLOC(c, struct zx_ds_X509Data_s);
  x->gg.g.tok = zx_ds_X509Data_ELEM;
  x->gg.g.ns = ns;
  ZX_START_DEC_EXT(x);

#if 1 /* NORMALMODE */
  ZX_DEC_TAG_NOT_YET_CLOSED(x->gg.g);

  /* The tag name has already been detected. Process attributes until '>' */
  
  for (; c->p; ++c->p) {
    ZX_SKIP_WS(c,x);
    if (ONE_OF_2(*c->p, '>', '/'))
      break;
    if (!(data = zx_dec_attr_val(c, &name))) {
      D("Decoding attr_val failed %p", c->p);
      return x;
    }
    tok = zx_attr_lookup(c, name, data-2, &ns);
    switch (tok) {

    case ZX_TOK_XMLNS:
      ZX_XMLNS_DEC_EXT(ss);
      DD("xmlns detected(%.*s)", data-2-name, name);
      goto next_attr;
    default:
      ss = zx_dec_unknown_attr(c, &x->gg, name, data, tok, x->gg.g.tok);
    }
    ss->g.ns = ns;
    ss->g.tok = tok;
    ss->g.err |= ZXERR_ATTR_FLAG;
    ss->len = c->p - data;
    ss->s = (char*)data;
next_attr:
    continue;
  }
  if (c->p) {
    ++c->p;
    if (c->p[-1] == '/' && c->p[0] == '>') {  /* Tag without content */
      ++c->p;
      ZX_DEC_TAG_NOW_CLOSED(x->gg.g);
      goto out;
    }
  }
#endif

  /* Process contents until '</' */
  
  ZX_START_BODY_DEC_EXT(x);
  
  while (c->p) {
  next_elem:
    /*ZX_SKIP_WS(c,x);    DO NOT SQUASH WS! EXC-CANON NEEDS IT. */
    if (*c->p == '<') {
    potential_tag:
      ++c->p;
      switch (*c->p) {
      case '?':  /* processing instruction <?xml ... ?> */
      case '!':  /* comment <!-- ... --> */
	if (zx_scan_pi_or_comment(c))
	  break;
	goto next_elem;
      case '/':  /* close tag */
	++c->p;
	name = c->p;
	ZX_LOOK_FOR(c,'>');
#if defined(DEC_WRONG_ELEM)
	if (x->gg.g.ns->prefix_len
	    ?(c->p - name - x->gg.g.ns->prefix_len - 1 != namlen || memcmp(name+x->gg.g.ns->prefix_len+1, nam, namlen))
	    :(c->p-name != namlen || memcmp(name, nam, namlen)))
#else
	tok = zx_elem_lookup(c, name, c->p, &ns);
	if (tok != x->gg.g.tok)
#endif
	{
	  ERR("Mismatching close tag(%.*s) tok=%d context=%d", c->p-name, name, tok, x->gg.g.tok);
	  zx_xml_parse_err(c, '-', (const char*)__FUNCTION__, "Mismatching close tag");
	  ZX_DEC_TAG_MISMATCH_CLOSE(x->gg.g);
	  ++c->p;
	  return x;
	}
	/* Legitimate close tag. Normal exit from this function. */
	++c->p;
	ZX_DEC_TAG_NOW_CLOSED(x->gg.g);
	goto out;
      default:
	if (A_Z_a_z_(*c->p)) {
	  name = c->p;
	  for (++c->p; *c->p && !ONE_OF_6(*c->p, ' ', '>', '/', '\n', '\r', '\t'); ++c->p) ;
	  if (!*c->p) {
	    D("Incomplete %s", name);
	    return x;
	  }
	  pop_seen = zx_scan_xmlns(c);  /* Prescan namespaces so that token can be correctly recognized. */
	  tok = zx_elem_lookup(c, name, c->p, &ns);
	  switch (tok) {
          case zx_ds_X509IssuerSerial_ELEM:
            el = (struct zx_elem_s*)zx_DEC_ds_X509IssuerSerial(c, ns);
            el->g.n = &x->X509IssuerSerial->gg.g;
            x->X509IssuerSerial = (struct zx_ds_X509IssuerSerial_s*)el;
            break;
          case zx_ds_X509SKI_ELEM:
            el = zx_DEC_simple_elem(c, ns, tok);
            el->g.n = &x->X509SKI->g;
            x->X509SKI = el;
            break;
          case zx_ds_X509SubjectName_ELEM:
            el = zx_DEC_simple_elem(c, ns, tok);
            el->g.n = &x->X509SubjectName->g;
            x->X509SubjectName = el;
            break;
          case zx_ds_X509Certificate_ELEM:
            el = zx_DEC_simple_elem(c, ns, tok);
            el->g.n = &x->X509Certificate->g;
            x->X509Certificate = el;
            break;
          case zx_ds_X509CRL_ELEM:
            el = zx_DEC_simple_elem(c, ns, tok);
            el->g.n = &x->X509CRL->g;
            x->X509CRL = el;
            break;

	  default:
	    el = zx_known_or_unknown_elem(c, tok, &x->gg, c->p - name, name, ns);
	    tok = ZX_TOK_NOT_FOUND;
	    break;
	  }
          el->g.wo = &x->gg.kids->g;
          x->gg.kids = el;
	  zx_pop_seen(pop_seen);
	  
	  goto next_elem;
	}
      }
      /* false alarm <, fall thru */
    }
    if (!zx_scan_data(c, &x->gg))
      return x;
    goto potential_tag;
  }
 out:
  iternode = x->gg.kids;
  REVERSE_LIST_NEXT(x->gg.kids, iternode, g.wo);
  iternode = (struct zx_elem_s*)(x->gg.any_elem);
  REVERSE_LIST_NEXT(x->gg.any_elem, iternode, g.n);
  ss = (struct zx_str*)(x->gg.any_attr);
  REVERSE_LIST_NEXT(x->gg.any_attr, ss, g.n);
  ZX_END_DEC_EXT(x);
  return x;

 look_for_not_found:
  zx_xml_parse_err(c, '>', (const char*)__FUNCTION__, "char not found");
  return x;
}

#undef EL_NAME
#undef EL_STRUCT
#undef EL_NS
#undef EL_TAG






/* FUNC(zx_DEC_ds_X509IssuerSerial) */

#define EL_NAME   ds_X509IssuerSerial
#define EL_STRUCT zx_ds_X509IssuerSerial_s
#define EL_NS     ds
#define EL_TAG    X509IssuerSerial

/* Called by: */
struct zx_ds_X509IssuerSerial_s* zx_DEC_ds_X509IssuerSerial(struct zx_ctx* c, struct zx_ns_s* ns )
{
  int tok;
  struct zx_elem_s* iternode;
  struct zx_elem_s* el;
  struct zx_str* ss;
  struct zx_ns_s* pop_seen;
  const char* name;
  const char* data;
  struct zx_ds_X509IssuerSerial_s* x = ZX_ZALLOC(c, struct zx_ds_X509IssuerSerial_s);
  x->gg.g.tok = zx_ds_X509IssuerSerial_ELEM;
  x->gg.g.ns = ns;
  ZX_START_DEC_EXT(x);

#if 1 /* NORMALMODE */
  ZX_DEC_TAG_NOT_YET_CLOSED(x->gg.g);

  /* The tag name has already been detected. Process attributes until '>' */
  
  for (; c->p; ++c->p) {
    ZX_SKIP_WS(c,x);
    if (ONE_OF_2(*c->p, '>', '/'))
      break;
    if (!(data = zx_dec_attr_val(c, &name))) {
      D("Decoding attr_val failed %p", c->p);
      return x;
    }
    tok = zx_attr_lookup(c, name, data-2, &ns);
    switch (tok) {

    case ZX_TOK_XMLNS:
      ZX_XMLNS_DEC_EXT(ss);
      DD("xmlns detected(%.*s)", data-2-name, name);
      goto next_attr;
    default:
      ss = zx_dec_unknown_attr(c, &x->gg, name, data, tok, x->gg.g.tok);
    }
    ss->g.ns = ns;
    ss->g.tok = tok;
    ss->g.err |= ZXERR_ATTR_FLAG;
    ss->len = c->p - data;
    ss->s = (char*)data;
next_attr:
    continue;
  }
  if (c->p) {
    ++c->p;
    if (c->p[-1] == '/' && c->p[0] == '>') {  /* Tag without content */
      ++c->p;
      ZX_DEC_TAG_NOW_CLOSED(x->gg.g);
      goto out;
    }
  }
#endif

  /* Process contents until '</' */
  
  ZX_START_BODY_DEC_EXT(x);
  
  while (c->p) {
  next_elem:
    /*ZX_SKIP_WS(c,x);    DO NOT SQUASH WS! EXC-CANON NEEDS IT. */
    if (*c->p == '<') {
    potential_tag:
      ++c->p;
      switch (*c->p) {
      case '?':  /* processing instruction <?xml ... ?> */
      case '!':  /* comment <!-- ... --> */
	if (zx_scan_pi_or_comment(c))
	  break;
	goto next_elem;
      case '/':  /* close tag */
	++c->p;
	name = c->p;
	ZX_LOOK_FOR(c,'>');
#if defined(DEC_WRONG_ELEM)
	if (x->gg.g.ns->prefix_len
	    ?(c->p - name - x->gg.g.ns->prefix_len - 1 != namlen || memcmp(name+x->gg.g.ns->prefix_len+1, nam, namlen))
	    :(c->p-name != namlen || memcmp(name, nam, namlen)))
#else
	tok = zx_elem_lookup(c, name, c->p, &ns);
	if (tok != x->gg.g.tok)
#endif
	{
	  ERR("Mismatching close tag(%.*s) tok=%d context=%d", c->p-name, name, tok, x->gg.g.tok);
	  zx_xml_parse_err(c, '-', (const char*)__FUNCTION__, "Mismatching close tag");
	  ZX_DEC_TAG_MISMATCH_CLOSE(x->gg.g);
	  ++c->p;
	  return x;
	}
	/* Legitimate close tag. Normal exit from this function. */
	++c->p;
	ZX_DEC_TAG_NOW_CLOSED(x->gg.g);
	goto out;
      default:
	if (A_Z_a_z_(*c->p)) {
	  name = c->p;
	  for (++c->p; *c->p && !ONE_OF_6(*c->p, ' ', '>', '/', '\n', '\r', '\t'); ++c->p) ;
	  if (!*c->p) {
	    D("Incomplete %s", name);
	    return x;
	  }
	  pop_seen = zx_scan_xmlns(c);  /* Prescan namespaces so that token can be correctly recognized. */
	  tok = zx_elem_lookup(c, name, c->p, &ns);
	  switch (tok) {
          case zx_ds_X509IssuerName_ELEM:
            el = zx_DEC_simple_elem(c, ns, tok);
            el->g.n = &x->X509IssuerName->g;
            x->X509IssuerName = el;
            break;
          case zx_ds_X509SerialNumber_ELEM:
            el = zx_DEC_simple_elem(c, ns, tok);
            el->g.n = &x->X509SerialNumber->g;
            x->X509SerialNumber = el;
            break;

	  default:
	    el = zx_known_or_unknown_elem(c, tok, &x->gg, c->p - name, name, ns);
	    tok = ZX_TOK_NOT_FOUND;
	    break;
	  }
          el->g.wo = &x->gg.kids->g;
          x->gg.kids = el;
	  zx_pop_seen(pop_seen);
	  
	  goto next_elem;
	}
      }
      /* false alarm <, fall thru */
    }
    if (!zx_scan_data(c, &x->gg))
      return x;
    goto potential_tag;
  }
 out:
  iternode = x->gg.kids;
  REVERSE_LIST_NEXT(x->gg.kids, iternode, g.wo);
  iternode = (struct zx_elem_s*)(x->gg.any_elem);
  REVERSE_LIST_NEXT(x->gg.any_elem, iternode, g.n);
  ss = (struct zx_str*)(x->gg.any_attr);
  REVERSE_LIST_NEXT(x->gg.any_attr, ss, g.n);
  ZX_END_DEC_EXT(x);
  return x;

 look_for_not_found:
  zx_xml_parse_err(c, '>', (const char*)__FUNCTION__, "char not found");
  return x;
}

#undef EL_NAME
#undef EL_STRUCT
#undef EL_NS
#undef EL_TAG




/* EOF -- c/zx-ds-dec.c */
