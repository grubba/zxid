/* c/zx-sp11-dec.c - WARNING: This file was automatically generated. DO NOT EDIT!
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
#include "c/zx-sp11-data.h"

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



/* FUNC(zx_DEC_sp11_AttributeQuery) */

#define EL_NAME   sp11_AttributeQuery
#define EL_STRUCT zx_sp11_AttributeQuery_s
#define EL_NS     sp11
#define EL_TAG    AttributeQuery

/* Called by: */
struct zx_sp11_AttributeQuery_s* zx_DEC_sp11_AttributeQuery(struct zx_ctx* c, struct zx_ns_s* ns )
{
  int tok;
  struct zx_elem_s* iternode;
  struct zx_elem_s* el;
  struct zx_str* ss;
  struct zx_ns_s* pop_seen;
  char* name;
  char* data;
  struct zx_sp11_AttributeQuery_s* x = ZX_ZALLOC(c, struct zx_sp11_AttributeQuery_s);
  x->gg.g.tok = zx_sp11_AttributeQuery_ELEM;
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
    case zx_Resource_ATTR:
      ss = ZX_ZALLOC(c, struct zx_str);
      ss->g.n = &x->Resource->g;
      x->Resource = ss;
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
    ss->s = data;
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
          case zx_sa11_Subject_ELEM:
            el = (struct zx_elem_s*)zx_DEC_sa11_Subject(c, ns);
            el->g.n = &x->Subject->gg.g;
            x->Subject = (struct zx_sa11_Subject_s*)el;
            break;
          case zx_sa11_AttributeDesignator_ELEM:
            el = (struct zx_elem_s*)zx_DEC_sa11_AttributeDesignator(c, ns);
            el->g.n = &x->AttributeDesignator->gg.g;
            x->AttributeDesignator = (struct zx_sa11_AttributeDesignator_s*)el;
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






/* FUNC(zx_DEC_sp11_AuthenticationQuery) */

#define EL_NAME   sp11_AuthenticationQuery
#define EL_STRUCT zx_sp11_AuthenticationQuery_s
#define EL_NS     sp11
#define EL_TAG    AuthenticationQuery

/* Called by: */
struct zx_sp11_AuthenticationQuery_s* zx_DEC_sp11_AuthenticationQuery(struct zx_ctx* c, struct zx_ns_s* ns )
{
  int tok;
  struct zx_elem_s* iternode;
  struct zx_elem_s* el;
  struct zx_str* ss;
  struct zx_ns_s* pop_seen;
  char* name;
  char* data;
  struct zx_sp11_AuthenticationQuery_s* x = ZX_ZALLOC(c, struct zx_sp11_AuthenticationQuery_s);
  x->gg.g.tok = zx_sp11_AuthenticationQuery_ELEM;
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
    case zx_AuthenticationMethod_ATTR:
      ss = ZX_ZALLOC(c, struct zx_str);
      ss->g.n = &x->AuthenticationMethod->g;
      x->AuthenticationMethod = ss;
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
    ss->s = data;
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
          case zx_sa11_Subject_ELEM:
            el = (struct zx_elem_s*)zx_DEC_sa11_Subject(c, ns);
            el->g.n = &x->Subject->gg.g;
            x->Subject = (struct zx_sa11_Subject_s*)el;
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






/* FUNC(zx_DEC_sp11_AuthorizationDecisionQuery) */

#define EL_NAME   sp11_AuthorizationDecisionQuery
#define EL_STRUCT zx_sp11_AuthorizationDecisionQuery_s
#define EL_NS     sp11
#define EL_TAG    AuthorizationDecisionQuery

/* Called by: */
struct zx_sp11_AuthorizationDecisionQuery_s* zx_DEC_sp11_AuthorizationDecisionQuery(struct zx_ctx* c, struct zx_ns_s* ns )
{
  int tok;
  struct zx_elem_s* iternode;
  struct zx_elem_s* el;
  struct zx_str* ss;
  struct zx_ns_s* pop_seen;
  char* name;
  char* data;
  struct zx_sp11_AuthorizationDecisionQuery_s* x = ZX_ZALLOC(c, struct zx_sp11_AuthorizationDecisionQuery_s);
  x->gg.g.tok = zx_sp11_AuthorizationDecisionQuery_ELEM;
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
    case zx_Resource_ATTR:
      ss = ZX_ZALLOC(c, struct zx_str);
      ss->g.n = &x->Resource->g;
      x->Resource = ss;
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
    ss->s = data;
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
          case zx_sa11_Subject_ELEM:
            el = (struct zx_elem_s*)zx_DEC_sa11_Subject(c, ns);
            el->g.n = &x->Subject->gg.g;
            x->Subject = (struct zx_sa11_Subject_s*)el;
            break;
          case zx_sa11_Action_ELEM:
            el = (struct zx_elem_s*)zx_DEC_sa11_Action(c, ns);
            el->g.n = &x->Action->gg.g;
            x->Action = (struct zx_sa11_Action_s*)el;
            break;
          case zx_sa11_Evidence_ELEM:
            el = (struct zx_elem_s*)zx_DEC_sa11_Evidence(c, ns);
            el->g.n = &x->Evidence->gg.g;
            x->Evidence = (struct zx_sa11_Evidence_s*)el;
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






/* FUNC(zx_DEC_sp11_Request) */

#define EL_NAME   sp11_Request
#define EL_STRUCT zx_sp11_Request_s
#define EL_NS     sp11
#define EL_TAG    Request

/* Called by: */
struct zx_sp11_Request_s* zx_DEC_sp11_Request(struct zx_ctx* c, struct zx_ns_s* ns )
{
  int tok;
  struct zx_elem_s* iternode;
  struct zx_elem_s* el;
  struct zx_str* ss;
  struct zx_ns_s* pop_seen;
  char* name;
  char* data;
  struct zx_sp11_Request_s* x = ZX_ZALLOC(c, struct zx_sp11_Request_s);
  x->gg.g.tok = zx_sp11_Request_ELEM;
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
    case zx_IssueInstant_ATTR:
      ss = ZX_ZALLOC(c, struct zx_str);
      ss->g.n = &x->IssueInstant->g;
      x->IssueInstant = ss;
      ZX_ATTR_DEC_EXT(ss);
      break;
    case zx_MajorVersion_ATTR:
      ss = ZX_ZALLOC(c, struct zx_str);
      ss->g.n = &x->MajorVersion->g;
      x->MajorVersion = ss;
      ZX_ATTR_DEC_EXT(ss);
      break;
    case zx_MinorVersion_ATTR:
      ss = ZX_ZALLOC(c, struct zx_str);
      ss->g.n = &x->MinorVersion->g;
      x->MinorVersion = ss;
      ZX_ATTR_DEC_EXT(ss);
      break;
    case zx_RequestID_ATTR:
      ss = ZX_ZALLOC(c, struct zx_str);
      ss->g.n = &x->RequestID->g;
      x->RequestID = ss;
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
    ss->s = data;
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
          case zx_sp11_RespondWith_ELEM:
            el = zx_DEC_simple_elem(c, ns, tok);
            el->g.n = &x->RespondWith->g;
            x->RespondWith = el;
            break;
          case zx_ds_Signature_ELEM:
            el = (struct zx_elem_s*)zx_DEC_ds_Signature(c, ns);
            el->g.n = &x->Signature->gg.g;
            x->Signature = (struct zx_ds_Signature_s*)el;
            break;
          case zx_sp11_Query_ELEM:
            el = zx_DEC_simple_elem(c, ns, tok);
            el->g.n = &x->Query->g;
            x->Query = el;
            break;
          case zx_sp11_SubjectQuery_ELEM:
            el = (struct zx_elem_s*)zx_DEC_sp11_SubjectQuery(c, ns);
            el->g.n = &x->SubjectQuery->gg.g;
            x->SubjectQuery = (struct zx_sp11_SubjectQuery_s*)el;
            break;
          case zx_sp11_AuthenticationQuery_ELEM:
            el = (struct zx_elem_s*)zx_DEC_sp11_AuthenticationQuery(c, ns);
            el->g.n = &x->AuthenticationQuery->gg.g;
            x->AuthenticationQuery = (struct zx_sp11_AuthenticationQuery_s*)el;
            break;
          case zx_sp11_AttributeQuery_ELEM:
            el = (struct zx_elem_s*)zx_DEC_sp11_AttributeQuery(c, ns);
            el->g.n = &x->AttributeQuery->gg.g;
            x->AttributeQuery = (struct zx_sp11_AttributeQuery_s*)el;
            break;
          case zx_sp11_AuthorizationDecisionQuery_ELEM:
            el = (struct zx_elem_s*)zx_DEC_sp11_AuthorizationDecisionQuery(c, ns);
            el->g.n = &x->AuthorizationDecisionQuery->gg.g;
            x->AuthorizationDecisionQuery = (struct zx_sp11_AuthorizationDecisionQuery_s*)el;
            break;
          case zx_sa11_AssertionIDReference_ELEM:
            el = zx_DEC_simple_elem(c, ns, tok);
            el->g.n = &x->AssertionIDReference->g;
            x->AssertionIDReference = el;
            break;
          case zx_sp11_AssertionArtifact_ELEM:
            el = zx_DEC_simple_elem(c, ns, tok);
            el->g.n = &x->AssertionArtifact->g;
            x->AssertionArtifact = el;
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






/* FUNC(zx_DEC_sp11_Response) */

#define EL_NAME   sp11_Response
#define EL_STRUCT zx_sp11_Response_s
#define EL_NS     sp11
#define EL_TAG    Response

/* Called by: */
struct zx_sp11_Response_s* zx_DEC_sp11_Response(struct zx_ctx* c, struct zx_ns_s* ns )
{
  int tok;
  struct zx_elem_s* iternode;
  struct zx_elem_s* el;
  struct zx_str* ss;
  struct zx_ns_s* pop_seen;
  char* name;
  char* data;
  struct zx_sp11_Response_s* x = ZX_ZALLOC(c, struct zx_sp11_Response_s);
  x->gg.g.tok = zx_sp11_Response_ELEM;
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
    case zx_InResponseTo_ATTR:
      ss = ZX_ZALLOC(c, struct zx_str);
      ss->g.n = &x->InResponseTo->g;
      x->InResponseTo = ss;
      ZX_ATTR_DEC_EXT(ss);
      break;
    case zx_IssueInstant_ATTR:
      ss = ZX_ZALLOC(c, struct zx_str);
      ss->g.n = &x->IssueInstant->g;
      x->IssueInstant = ss;
      ZX_ATTR_DEC_EXT(ss);
      break;
    case zx_MajorVersion_ATTR:
      ss = ZX_ZALLOC(c, struct zx_str);
      ss->g.n = &x->MajorVersion->g;
      x->MajorVersion = ss;
      ZX_ATTR_DEC_EXT(ss);
      break;
    case zx_MinorVersion_ATTR:
      ss = ZX_ZALLOC(c, struct zx_str);
      ss->g.n = &x->MinorVersion->g;
      x->MinorVersion = ss;
      ZX_ATTR_DEC_EXT(ss);
      break;
    case zx_Recipient_ATTR:
      ss = ZX_ZALLOC(c, struct zx_str);
      ss->g.n = &x->Recipient->g;
      x->Recipient = ss;
      ZX_ATTR_DEC_EXT(ss);
      break;
    case zx_ResponseID_ATTR:
      ss = ZX_ZALLOC(c, struct zx_str);
      ss->g.n = &x->ResponseID->g;
      x->ResponseID = ss;
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
    ss->s = data;
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
          case zx_ds_Signature_ELEM:
            el = (struct zx_elem_s*)zx_DEC_ds_Signature(c, ns);
            el->g.n = &x->Signature->gg.g;
            x->Signature = (struct zx_ds_Signature_s*)el;
            break;
          case zx_sp11_Status_ELEM:
            el = (struct zx_elem_s*)zx_DEC_sp11_Status(c, ns);
            el->g.n = &x->Status->gg.g;
            x->Status = (struct zx_sp11_Status_s*)el;
            break;
          case zx_sa11_Assertion_ELEM:
            el = (struct zx_elem_s*)zx_DEC_sa11_Assertion(c, ns);
            el->g.n = &x->Assertion->gg.g;
            x->Assertion = (struct zx_sa11_Assertion_s*)el;
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






/* FUNC(zx_DEC_sp11_Status) */

#define EL_NAME   sp11_Status
#define EL_STRUCT zx_sp11_Status_s
#define EL_NS     sp11
#define EL_TAG    Status

/* Called by: */
struct zx_sp11_Status_s* zx_DEC_sp11_Status(struct zx_ctx* c, struct zx_ns_s* ns )
{
  int tok;
  struct zx_elem_s* iternode;
  struct zx_elem_s* el;
  struct zx_str* ss;
  struct zx_ns_s* pop_seen;
  char* name;
  char* data;
  struct zx_sp11_Status_s* x = ZX_ZALLOC(c, struct zx_sp11_Status_s);
  x->gg.g.tok = zx_sp11_Status_ELEM;
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
    ss->s = data;
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
          case zx_sp11_StatusCode_ELEM:
            el = (struct zx_elem_s*)zx_DEC_sp11_StatusCode(c, ns);
            el->g.n = &x->StatusCode->gg.g;
            x->StatusCode = (struct zx_sp11_StatusCode_s*)el;
            break;
          case zx_sp11_StatusMessage_ELEM:
            el = zx_DEC_simple_elem(c, ns, tok);
            el->g.n = &x->StatusMessage->g;
            x->StatusMessage = el;
            break;
          case zx_sp11_StatusDetail_ELEM:
            el = (struct zx_elem_s*)zx_DEC_sp11_StatusDetail(c, ns);
            el->g.n = &x->StatusDetail->gg.g;
            x->StatusDetail = (struct zx_sp11_StatusDetail_s*)el;
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






/* FUNC(zx_DEC_sp11_StatusCode) */

#define EL_NAME   sp11_StatusCode
#define EL_STRUCT zx_sp11_StatusCode_s
#define EL_NS     sp11
#define EL_TAG    StatusCode

/* Called by: */
struct zx_sp11_StatusCode_s* zx_DEC_sp11_StatusCode(struct zx_ctx* c, struct zx_ns_s* ns )
{
  int tok;
  struct zx_elem_s* iternode;
  struct zx_elem_s* el;
  struct zx_str* ss;
  struct zx_ns_s* pop_seen;
  char* name;
  char* data;
  struct zx_sp11_StatusCode_s* x = ZX_ZALLOC(c, struct zx_sp11_StatusCode_s);
  x->gg.g.tok = zx_sp11_StatusCode_ELEM;
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
    case zx_Value_ATTR:
      ss = ZX_ZALLOC(c, struct zx_str);
      ss->g.n = &x->Value->g;
      x->Value = ss;
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
    ss->s = data;
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
          case zx_sp11_StatusCode_ELEM:
            el = (struct zx_elem_s*)zx_DEC_sp11_StatusCode(c, ns);
            el->g.n = &x->StatusCode->gg.g;
            x->StatusCode = (struct zx_sp11_StatusCode_s*)el;
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






/* FUNC(zx_DEC_sp11_StatusDetail) */

#define EL_NAME   sp11_StatusDetail
#define EL_STRUCT zx_sp11_StatusDetail_s
#define EL_NS     sp11
#define EL_TAG    StatusDetail

/* Called by: */
struct zx_sp11_StatusDetail_s* zx_DEC_sp11_StatusDetail(struct zx_ctx* c, struct zx_ns_s* ns )
{
  int tok;
  struct zx_elem_s* iternode;
  struct zx_elem_s* el;
  struct zx_str* ss;
  struct zx_ns_s* pop_seen;
  char* name;
  char* data;
  struct zx_sp11_StatusDetail_s* x = ZX_ZALLOC(c, struct zx_sp11_StatusDetail_s);
  x->gg.g.tok = zx_sp11_StatusDetail_ELEM;
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
    ss->s = data;
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






/* FUNC(zx_DEC_sp11_SubjectQuery) */

#define EL_NAME   sp11_SubjectQuery
#define EL_STRUCT zx_sp11_SubjectQuery_s
#define EL_NS     sp11
#define EL_TAG    SubjectQuery

/* Called by: */
struct zx_sp11_SubjectQuery_s* zx_DEC_sp11_SubjectQuery(struct zx_ctx* c, struct zx_ns_s* ns )
{
  int tok;
  struct zx_elem_s* iternode;
  struct zx_elem_s* el;
  struct zx_str* ss;
  struct zx_ns_s* pop_seen;
  char* name;
  char* data;
  struct zx_sp11_SubjectQuery_s* x = ZX_ZALLOC(c, struct zx_sp11_SubjectQuery_s);
  x->gg.g.tok = zx_sp11_SubjectQuery_ELEM;
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
    ss->s = data;
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
          case zx_sa11_Subject_ELEM:
            el = (struct zx_elem_s*)zx_DEC_sa11_Subject(c, ns);
            el->g.n = &x->Subject->gg.g;
            x->Subject = (struct zx_sa11_Subject_s*)el;
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




/* EOF -- c/zx-sp11-dec.c */
