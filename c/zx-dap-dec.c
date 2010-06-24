/* c/zx-dap-dec.c - WARNING: This file was automatically generated. DO NOT EDIT!
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
#include "c/zx-dap-data.h"

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



/* FUNC(zx_DEC_dap_Create) */

#define EL_NAME   dap_Create
#define EL_STRUCT zx_dap_Create_s
#define EL_NS     dap
#define EL_TAG    Create

/* Called by: */
struct zx_dap_Create_s* zx_DEC_dap_Create(struct zx_ctx* c, struct zx_ns_s* ns )
{
  int tok;
  struct zx_elem_s* iternode;
  struct zx_elem_s* el;
  struct zx_str* ss;
  struct zx_ns_s* pop_seen;
  char* name;
  char* data;
  struct zx_dap_Create_s* x = ZX_ZALLOC(c, struct zx_dap_Create_s);
  x->gg.g.tok = zx_dap_Create_ELEM;
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
    case zx_dst_itemID_ATTR:
      ss = ZX_ZALLOC(c, struct zx_str);
      ss->g.n = &x->itemID->g;
      x->itemID = ss;
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
          case zx_lu_Extension_ELEM:
            el = (struct zx_elem_s*)zx_DEC_lu_Extension(c, ns);
            el->g.n = &x->Extension->gg.g;
            x->Extension = (struct zx_lu_Extension_s*)el;
            break;
          case zx_dap_Subscription_ELEM:
            el = (struct zx_elem_s*)zx_DEC_dap_Subscription(c, ns);
            el->g.n = &x->Subscription->gg.g;
            x->Subscription = (struct zx_dap_Subscription_s*)el;
            break;
          case zx_dap_CreateItem_ELEM:
            el = (struct zx_elem_s*)zx_DEC_dap_CreateItem(c, ns);
            el->g.n = &x->CreateItem->gg.g;
            x->CreateItem = (struct zx_dap_CreateItem_s*)el;
            break;
          case zx_dap_ResultQuery_ELEM:
            el = (struct zx_elem_s*)zx_DEC_dap_ResultQuery(c, ns);
            el->g.n = &x->ResultQuery->gg.g;
            x->ResultQuery = (struct zx_dap_ResultQuery_s*)el;
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






/* FUNC(zx_DEC_dap_CreateItem) */

#define EL_NAME   dap_CreateItem
#define EL_STRUCT zx_dap_CreateItem_s
#define EL_NS     dap
#define EL_TAG    CreateItem

/* Called by: */
struct zx_dap_CreateItem_s* zx_DEC_dap_CreateItem(struct zx_ctx* c, struct zx_ns_s* ns )
{
  int tok;
  struct zx_elem_s* iternode;
  struct zx_elem_s* el;
  struct zx_str* ss;
  struct zx_ns_s* pop_seen;
  char* name;
  char* data;
  struct zx_dap_CreateItem_s* x = ZX_ZALLOC(c, struct zx_dap_CreateItem_s);
  x->gg.g.tok = zx_dap_CreateItem_ELEM;
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
    case zx_id_ATTR:
      ss = ZX_ZALLOC(c, struct zx_str);
      ss->g.n = &x->id->g;
      x->id = ss;
      ZX_ATTR_DEC_EXT(ss);
      break;
    case zx_dst_itemID_ATTR:
      ss = ZX_ZALLOC(c, struct zx_str);
      ss->g.n = &x->itemID->g;
      x->itemID = ss;
      ZX_ATTR_DEC_EXT(ss);
      break;
    case zx_dst_objectType_ATTR:
      ss = ZX_ZALLOC(c, struct zx_str);
      ss->g.n = &x->objectType->g;
      x->objectType = ss;
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
          case zx_dap_NewData_ELEM:
            el = (struct zx_elem_s*)zx_DEC_dap_NewData(c, ns);
            el->g.n = &x->NewData->gg.g;
            x->NewData = (struct zx_dap_NewData_s*)el;
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






/* FUNC(zx_DEC_dap_CreateResponse) */

#define EL_NAME   dap_CreateResponse
#define EL_STRUCT zx_dap_CreateResponse_s
#define EL_NS     dap
#define EL_TAG    CreateResponse

/* Called by: */
struct zx_dap_CreateResponse_s* zx_DEC_dap_CreateResponse(struct zx_ctx* c, struct zx_ns_s* ns )
{
  int tok;
  struct zx_elem_s* iternode;
  struct zx_elem_s* el;
  struct zx_str* ss;
  struct zx_ns_s* pop_seen;
  char* name;
  char* data;
  struct zx_dap_CreateResponse_s* x = ZX_ZALLOC(c, struct zx_dap_CreateResponse_s);
  x->gg.g.tok = zx_dap_CreateResponse_ELEM;
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
    case zx_timeStamp_ATTR:
      ss = ZX_ZALLOC(c, struct zx_str);
      ss->g.n = &x->timeStamp->g;
      x->timeStamp = ss;
      ZX_ATTR_DEC_EXT(ss);
      break;
    case zx_dst_itemIDRef_ATTR:
      ss = ZX_ZALLOC(c, struct zx_str);
      ss->g.n = &x->itemIDRef->g;
      x->itemIDRef = ss;
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
          case zx_lu_Status_ELEM:
            el = (struct zx_elem_s*)zx_DEC_lu_Status(c, ns);
            el->g.n = &x->Status->gg.g;
            x->Status = (struct zx_lu_Status_s*)el;
            break;
          case zx_lu_Extension_ELEM:
            el = (struct zx_elem_s*)zx_DEC_lu_Extension(c, ns);
            el->g.n = &x->Extension->gg.g;
            x->Extension = (struct zx_lu_Extension_s*)el;
            break;
          case zx_dap_ItemData_ELEM:
            el = (struct zx_elem_s*)zx_DEC_dap_ItemData(c, ns);
            el->g.n = &x->ItemData->gg.g;
            x->ItemData = (struct zx_dap_ItemData_s*)el;
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






/* FUNC(zx_DEC_dap_Data) */

#define EL_NAME   dap_Data
#define EL_STRUCT zx_dap_Data_s
#define EL_NS     dap
#define EL_TAG    Data

/* Called by: */
struct zx_dap_Data_s* zx_DEC_dap_Data(struct zx_ctx* c, struct zx_ns_s* ns )
{
  int tok;
  struct zx_elem_s* iternode;
  struct zx_elem_s* el;
  struct zx_str* ss;
  struct zx_ns_s* pop_seen;
  char* name;
  char* data;
  struct zx_dap_Data_s* x = ZX_ZALLOC(c, struct zx_dap_Data_s);
  x->gg.g.tok = zx_dap_Data_ELEM;
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
    case zx_nextOffset_ATTR:
      ss = ZX_ZALLOC(c, struct zx_str);
      ss->g.n = &x->nextOffset->g;
      x->nextOffset = ss;
      ZX_ATTR_DEC_EXT(ss);
      break;
    case zx_notSorted_ATTR:
      ss = ZX_ZALLOC(c, struct zx_str);
      ss->g.n = &x->notSorted->g;
      x->notSorted = ss;
      ZX_ATTR_DEC_EXT(ss);
      break;
    case zx_remaining_ATTR:
      ss = ZX_ZALLOC(c, struct zx_str);
      ss->g.n = &x->remaining->g;
      x->remaining = ss;
      ZX_ATTR_DEC_EXT(ss);
      break;
    case zx_setID_ATTR:
      ss = ZX_ZALLOC(c, struct zx_str);
      ss->g.n = &x->setID->g;
      x->setID = ss;
      ZX_ATTR_DEC_EXT(ss);
      break;
    case zx_dst_changeFormat_ATTR:
      ss = ZX_ZALLOC(c, struct zx_str);
      ss->g.n = &x->changeFormat->g;
      x->changeFormat = ss;
      ZX_ATTR_DEC_EXT(ss);
      break;
    case zx_dst_itemIDRef_ATTR:
      ss = ZX_ZALLOC(c, struct zx_str);
      ss->g.n = &x->itemIDRef->g;
      x->itemIDRef = ss;
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
          case zx_dap_LDIF_ELEM:
            el = (struct zx_elem_s*)zx_DEC_dap_LDIF(c, ns);
            el->g.n = &x->LDIF->gg.g;
            x->LDIF = (struct zx_dap_LDIF_s*)el;
            break;
          case zx_dap_Subscription_ELEM:
            el = (struct zx_elem_s*)zx_DEC_dap_Subscription(c, ns);
            el->g.n = &x->Subscription->gg.g;
            x->Subscription = (struct zx_dap_Subscription_s*)el;
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






/* FUNC(zx_DEC_dap_Delete) */

#define EL_NAME   dap_Delete
#define EL_STRUCT zx_dap_Delete_s
#define EL_NS     dap
#define EL_TAG    Delete

/* Called by: */
struct zx_dap_Delete_s* zx_DEC_dap_Delete(struct zx_ctx* c, struct zx_ns_s* ns )
{
  int tok;
  struct zx_elem_s* iternode;
  struct zx_elem_s* el;
  struct zx_str* ss;
  struct zx_ns_s* pop_seen;
  char* name;
  char* data;
  struct zx_dap_Delete_s* x = ZX_ZALLOC(c, struct zx_dap_Delete_s);
  x->gg.g.tok = zx_dap_Delete_ELEM;
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
    case zx_dst_itemID_ATTR:
      ss = ZX_ZALLOC(c, struct zx_str);
      ss->g.n = &x->itemID->g;
      x->itemID = ss;
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
          case zx_lu_Extension_ELEM:
            el = (struct zx_elem_s*)zx_DEC_lu_Extension(c, ns);
            el->g.n = &x->Extension->gg.g;
            x->Extension = (struct zx_lu_Extension_s*)el;
            break;
          case zx_dap_DeleteItem_ELEM:
            el = (struct zx_elem_s*)zx_DEC_dap_DeleteItem(c, ns);
            el->g.n = &x->DeleteItem->gg.g;
            x->DeleteItem = (struct zx_dap_DeleteItem_s*)el;
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






/* FUNC(zx_DEC_dap_DeleteItem) */

#define EL_NAME   dap_DeleteItem
#define EL_STRUCT zx_dap_DeleteItem_s
#define EL_NS     dap
#define EL_TAG    DeleteItem

/* Called by: */
struct zx_dap_DeleteItem_s* zx_DEC_dap_DeleteItem(struct zx_ctx* c, struct zx_ns_s* ns )
{
  int tok;
  struct zx_elem_s* iternode;
  struct zx_elem_s* el;
  struct zx_str* ss;
  struct zx_ns_s* pop_seen;
  char* name;
  char* data;
  struct zx_dap_DeleteItem_s* x = ZX_ZALLOC(c, struct zx_dap_DeleteItem_s);
  x->gg.g.tok = zx_dap_DeleteItem_ELEM;
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
    case zx_id_ATTR:
      ss = ZX_ZALLOC(c, struct zx_str);
      ss->g.n = &x->id->g;
      x->id = ss;
      ZX_ATTR_DEC_EXT(ss);
      break;
    case zx_notChangedSince_ATTR:
      ss = ZX_ZALLOC(c, struct zx_str);
      ss->g.n = &x->notChangedSince->g;
      x->notChangedSince = ss;
      ZX_ATTR_DEC_EXT(ss);
      break;
    case zx_dst_itemID_ATTR:
      ss = ZX_ZALLOC(c, struct zx_str);
      ss->g.n = &x->itemID->g;
      x->itemID = ss;
      ZX_ATTR_DEC_EXT(ss);
      break;
    case zx_dst_objectType_ATTR:
      ss = ZX_ZALLOC(c, struct zx_str);
      ss->g.n = &x->objectType->g;
      x->objectType = ss;
      ZX_ATTR_DEC_EXT(ss);
      break;
    case zx_dst_predefined_ATTR:
      ss = ZX_ZALLOC(c, struct zx_str);
      ss->g.n = &x->predefined->g;
      x->predefined = ss;
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
          case zx_dap_Select_ELEM:
            el = (struct zx_elem_s*)zx_DEC_dap_Select(c, ns);
            el->g.n = &x->Select->gg.g;
            x->Select = (struct zx_dap_Select_s*)el;
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






/* FUNC(zx_DEC_dap_DeleteResponse) */

#define EL_NAME   dap_DeleteResponse
#define EL_STRUCT zx_dap_DeleteResponse_s
#define EL_NS     dap
#define EL_TAG    DeleteResponse

/* Called by: */
struct zx_dap_DeleteResponse_s* zx_DEC_dap_DeleteResponse(struct zx_ctx* c, struct zx_ns_s* ns )
{
  int tok;
  struct zx_elem_s* iternode;
  struct zx_elem_s* el;
  struct zx_str* ss;
  struct zx_ns_s* pop_seen;
  char* name;
  char* data;
  struct zx_dap_DeleteResponse_s* x = ZX_ZALLOC(c, struct zx_dap_DeleteResponse_s);
  x->gg.g.tok = zx_dap_DeleteResponse_ELEM;
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
    case zx_itemIDRef_ATTR:
      ss = ZX_ZALLOC(c, struct zx_str);
      ss->g.n = &x->itemIDRef->g;
      x->itemIDRef = ss;
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
          case zx_lu_Status_ELEM:
            el = (struct zx_elem_s*)zx_DEC_lu_Status(c, ns);
            el->g.n = &x->Status->gg.g;
            x->Status = (struct zx_lu_Status_s*)el;
            break;
          case zx_lu_Extension_ELEM:
            el = (struct zx_elem_s*)zx_DEC_lu_Extension(c, ns);
            el->g.n = &x->Extension->gg.g;
            x->Extension = (struct zx_lu_Extension_s*)el;
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






/* FUNC(zx_DEC_dap_ItemData) */

#define EL_NAME   dap_ItemData
#define EL_STRUCT zx_dap_ItemData_s
#define EL_NS     dap
#define EL_TAG    ItemData

/* Called by: */
struct zx_dap_ItemData_s* zx_DEC_dap_ItemData(struct zx_ctx* c, struct zx_ns_s* ns )
{
  int tok;
  struct zx_elem_s* iternode;
  struct zx_elem_s* el;
  struct zx_str* ss;
  struct zx_ns_s* pop_seen;
  char* name;
  char* data;
  struct zx_dap_ItemData_s* x = ZX_ZALLOC(c, struct zx_dap_ItemData_s);
  x->gg.g.tok = zx_dap_ItemData_ELEM;
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
    case zx_notSorted_ATTR:
      ss = ZX_ZALLOC(c, struct zx_str);
      ss->g.n = &x->notSorted->g;
      x->notSorted = ss;
      ZX_ATTR_DEC_EXT(ss);
      break;
    case zx_dst_changeFormat_ATTR:
      ss = ZX_ZALLOC(c, struct zx_str);
      ss->g.n = &x->changeFormat->g;
      x->changeFormat = ss;
      ZX_ATTR_DEC_EXT(ss);
      break;
    case zx_dst_itemIDRef_ATTR:
      ss = ZX_ZALLOC(c, struct zx_str);
      ss->g.n = &x->itemIDRef->g;
      x->itemIDRef = ss;
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
          case zx_dap_LDIF_ELEM:
            el = (struct zx_elem_s*)zx_DEC_dap_LDIF(c, ns);
            el->g.n = &x->LDIF->gg.g;
            x->LDIF = (struct zx_dap_LDIF_s*)el;
            break;
          case zx_dap_Subscription_ELEM:
            el = (struct zx_elem_s*)zx_DEC_dap_Subscription(c, ns);
            el->g.n = &x->Subscription->gg.g;
            x->Subscription = (struct zx_dap_Subscription_s*)el;
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






/* FUNC(zx_DEC_dap_LDIF) */

#define EL_NAME   dap_LDIF
#define EL_STRUCT zx_dap_LDIF_s
#define EL_NS     dap
#define EL_TAG    LDIF

/* Called by: */
struct zx_dap_LDIF_s* zx_DEC_dap_LDIF(struct zx_ctx* c, struct zx_ns_s* ns )
{
  int tok;
  struct zx_elem_s* iternode;
  struct zx_elem_s* el;
  struct zx_str* ss;
  struct zx_ns_s* pop_seen;
  char* name;
  char* data;
  struct zx_dap_LDIF_s* x = ZX_ZALLOC(c, struct zx_dap_LDIF_s);
  x->gg.g.tok = zx_dap_LDIF_ELEM;
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
    case zx_xml_lang_ATTR:
      ss = ZX_ZALLOC(c, struct zx_str);
      ss->g.n = &x->lang->g;
      x->lang = ss;
      ZX_ATTR_DEC_EXT(ss);
      break;
    case zx_dst_ACC_ATTR:
      ss = ZX_ZALLOC(c, struct zx_str);
      ss->g.n = &x->ACC->g;
      x->ACC = ss;
      ZX_ATTR_DEC_EXT(ss);
      break;
    case zx_dst_ACCTime_ATTR:
      ss = ZX_ZALLOC(c, struct zx_str);
      ss->g.n = &x->ACCTime->g;
      x->ACCTime = ss;
      ZX_ATTR_DEC_EXT(ss);
      break;
    case zx_dst_id_ATTR:
      ss = ZX_ZALLOC(c, struct zx_str);
      ss->g.n = &x->id->g;
      x->id = ss;
      ZX_ATTR_DEC_EXT(ss);
      break;
    case zx_dst_modificationTime_ATTR:
      ss = ZX_ZALLOC(c, struct zx_str);
      ss->g.n = &x->modificationTime->g;
      x->modificationTime = ss;
      ZX_ATTR_DEC_EXT(ss);
      break;
    case zx_dst_modifier_ATTR:
      ss = ZX_ZALLOC(c, struct zx_str);
      ss->g.n = &x->modifier->g;
      x->modifier = ss;
      ZX_ATTR_DEC_EXT(ss);
      break;
    case zx_dst_script_ATTR:
      ss = ZX_ZALLOC(c, struct zx_str);
      ss->g.n = &x->script->g;
      x->script = ss;
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






/* FUNC(zx_DEC_dap_Modify) */

#define EL_NAME   dap_Modify
#define EL_STRUCT zx_dap_Modify_s
#define EL_NS     dap
#define EL_TAG    Modify

/* Called by: */
struct zx_dap_Modify_s* zx_DEC_dap_Modify(struct zx_ctx* c, struct zx_ns_s* ns )
{
  int tok;
  struct zx_elem_s* iternode;
  struct zx_elem_s* el;
  struct zx_str* ss;
  struct zx_ns_s* pop_seen;
  char* name;
  char* data;
  struct zx_dap_Modify_s* x = ZX_ZALLOC(c, struct zx_dap_Modify_s);
  x->gg.g.tok = zx_dap_Modify_ELEM;
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
    case zx_dst_itemID_ATTR:
      ss = ZX_ZALLOC(c, struct zx_str);
      ss->g.n = &x->itemID->g;
      x->itemID = ss;
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
          case zx_lu_Extension_ELEM:
            el = (struct zx_elem_s*)zx_DEC_lu_Extension(c, ns);
            el->g.n = &x->Extension->gg.g;
            x->Extension = (struct zx_lu_Extension_s*)el;
            break;
          case zx_dap_Subscription_ELEM:
            el = (struct zx_elem_s*)zx_DEC_dap_Subscription(c, ns);
            el->g.n = &x->Subscription->gg.g;
            x->Subscription = (struct zx_dap_Subscription_s*)el;
            break;
          case zx_dap_ModifyItem_ELEM:
            el = (struct zx_elem_s*)zx_DEC_dap_ModifyItem(c, ns);
            el->g.n = &x->ModifyItem->gg.g;
            x->ModifyItem = (struct zx_dap_ModifyItem_s*)el;
            break;
          case zx_dap_ResultQuery_ELEM:
            el = (struct zx_elem_s*)zx_DEC_dap_ResultQuery(c, ns);
            el->g.n = &x->ResultQuery->gg.g;
            x->ResultQuery = (struct zx_dap_ResultQuery_s*)el;
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






/* FUNC(zx_DEC_dap_ModifyItem) */

#define EL_NAME   dap_ModifyItem
#define EL_STRUCT zx_dap_ModifyItem_s
#define EL_NS     dap
#define EL_TAG    ModifyItem

/* Called by: */
struct zx_dap_ModifyItem_s* zx_DEC_dap_ModifyItem(struct zx_ctx* c, struct zx_ns_s* ns )
{
  int tok;
  struct zx_elem_s* iternode;
  struct zx_elem_s* el;
  struct zx_str* ss;
  struct zx_ns_s* pop_seen;
  char* name;
  char* data;
  struct zx_dap_ModifyItem_s* x = ZX_ZALLOC(c, struct zx_dap_ModifyItem_s);
  x->gg.g.tok = zx_dap_ModifyItem_ELEM;
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
    case zx_id_ATTR:
      ss = ZX_ZALLOC(c, struct zx_str);
      ss->g.n = &x->id->g;
      x->id = ss;
      ZX_ATTR_DEC_EXT(ss);
      break;
    case zx_notChangedSince_ATTR:
      ss = ZX_ZALLOC(c, struct zx_str);
      ss->g.n = &x->notChangedSince->g;
      x->notChangedSince = ss;
      ZX_ATTR_DEC_EXT(ss);
      break;
    case zx_overrideAllowed_ATTR:
      ss = ZX_ZALLOC(c, struct zx_str);
      ss->g.n = &x->overrideAllowed->g;
      x->overrideAllowed = ss;
      ZX_ATTR_DEC_EXT(ss);
      break;
    case zx_dst_itemID_ATTR:
      ss = ZX_ZALLOC(c, struct zx_str);
      ss->g.n = &x->itemID->g;
      x->itemID = ss;
      ZX_ATTR_DEC_EXT(ss);
      break;
    case zx_dst_objectType_ATTR:
      ss = ZX_ZALLOC(c, struct zx_str);
      ss->g.n = &x->objectType->g;
      x->objectType = ss;
      ZX_ATTR_DEC_EXT(ss);
      break;
    case zx_dst_predefined_ATTR:
      ss = ZX_ZALLOC(c, struct zx_str);
      ss->g.n = &x->predefined->g;
      x->predefined = ss;
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
          case zx_dap_Select_ELEM:
            el = (struct zx_elem_s*)zx_DEC_dap_Select(c, ns);
            el->g.n = &x->Select->gg.g;
            x->Select = (struct zx_dap_Select_s*)el;
            break;
          case zx_dap_NewData_ELEM:
            el = (struct zx_elem_s*)zx_DEC_dap_NewData(c, ns);
            el->g.n = &x->NewData->gg.g;
            x->NewData = (struct zx_dap_NewData_s*)el;
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






/* FUNC(zx_DEC_dap_ModifyResponse) */

#define EL_NAME   dap_ModifyResponse
#define EL_STRUCT zx_dap_ModifyResponse_s
#define EL_NS     dap
#define EL_TAG    ModifyResponse

/* Called by: */
struct zx_dap_ModifyResponse_s* zx_DEC_dap_ModifyResponse(struct zx_ctx* c, struct zx_ns_s* ns )
{
  int tok;
  struct zx_elem_s* iternode;
  struct zx_elem_s* el;
  struct zx_str* ss;
  struct zx_ns_s* pop_seen;
  char* name;
  char* data;
  struct zx_dap_ModifyResponse_s* x = ZX_ZALLOC(c, struct zx_dap_ModifyResponse_s);
  x->gg.g.tok = zx_dap_ModifyResponse_ELEM;
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
    case zx_timeStamp_ATTR:
      ss = ZX_ZALLOC(c, struct zx_str);
      ss->g.n = &x->timeStamp->g;
      x->timeStamp = ss;
      ZX_ATTR_DEC_EXT(ss);
      break;
    case zx_dst_itemIDRef_ATTR:
      ss = ZX_ZALLOC(c, struct zx_str);
      ss->g.n = &x->itemIDRef->g;
      x->itemIDRef = ss;
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
          case zx_lu_Status_ELEM:
            el = (struct zx_elem_s*)zx_DEC_lu_Status(c, ns);
            el->g.n = &x->Status->gg.g;
            x->Status = (struct zx_lu_Status_s*)el;
            break;
          case zx_lu_Extension_ELEM:
            el = (struct zx_elem_s*)zx_DEC_lu_Extension(c, ns);
            el->g.n = &x->Extension->gg.g;
            x->Extension = (struct zx_lu_Extension_s*)el;
            break;
          case zx_dap_ItemData_ELEM:
            el = (struct zx_elem_s*)zx_DEC_dap_ItemData(c, ns);
            el->g.n = &x->ItemData->gg.g;
            x->ItemData = (struct zx_dap_ItemData_s*)el;
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






/* FUNC(zx_DEC_dap_NewData) */

#define EL_NAME   dap_NewData
#define EL_STRUCT zx_dap_NewData_s
#define EL_NS     dap
#define EL_TAG    NewData

/* Called by: */
struct zx_dap_NewData_s* zx_DEC_dap_NewData(struct zx_ctx* c, struct zx_ns_s* ns )
{
  int tok;
  struct zx_elem_s* iternode;
  struct zx_elem_s* el;
  struct zx_str* ss;
  struct zx_ns_s* pop_seen;
  char* name;
  char* data;
  struct zx_dap_NewData_s* x = ZX_ZALLOC(c, struct zx_dap_NewData_s);
  x->gg.g.tok = zx_dap_NewData_ELEM;
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
          case zx_dap_LDIF_ELEM:
            el = (struct zx_elem_s*)zx_DEC_dap_LDIF(c, ns);
            el->g.n = &x->LDIF->gg.g;
            x->LDIF = (struct zx_dap_LDIF_s*)el;
            break;
          case zx_dap_Subscription_ELEM:
            el = (struct zx_elem_s*)zx_DEC_dap_Subscription(c, ns);
            el->g.n = &x->Subscription->gg.g;
            x->Subscription = (struct zx_dap_Subscription_s*)el;
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






/* FUNC(zx_DEC_dap_Notification) */

#define EL_NAME   dap_Notification
#define EL_STRUCT zx_dap_Notification_s
#define EL_NS     dap
#define EL_TAG    Notification

/* Called by: */
struct zx_dap_Notification_s* zx_DEC_dap_Notification(struct zx_ctx* c, struct zx_ns_s* ns )
{
  int tok;
  struct zx_elem_s* iternode;
  struct zx_elem_s* el;
  struct zx_str* ss;
  struct zx_ns_s* pop_seen;
  char* name;
  char* data;
  struct zx_dap_Notification_s* x = ZX_ZALLOC(c, struct zx_dap_Notification_s);
  x->gg.g.tok = zx_dap_Notification_ELEM;
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
    case zx_endReason_ATTR:
      ss = ZX_ZALLOC(c, struct zx_str);
      ss->g.n = &x->endReason->g;
      x->endReason = ss;
      ZX_ATTR_DEC_EXT(ss);
      break;
    case zx_expires_ATTR:
      ss = ZX_ZALLOC(c, struct zx_str);
      ss->g.n = &x->expires->g;
      x->expires = ss;
      ZX_ATTR_DEC_EXT(ss);
      break;
    case zx_id_ATTR:
      ss = ZX_ZALLOC(c, struct zx_str);
      ss->g.n = &x->id->g;
      x->id = ss;
      ZX_ATTR_DEC_EXT(ss);
      break;
    case zx_subscriptionID_ATTR:
      ss = ZX_ZALLOC(c, struct zx_str);
      ss->g.n = &x->subscriptionID->g;
      x->subscriptionID = ss;
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
          case zx_lu_TestResult_ELEM:
            el = (struct zx_elem_s*)zx_DEC_lu_TestResult(c, ns);
            el->g.n = &x->TestResult->gg.g;
            x->TestResult = (struct zx_lu_TestResult_s*)el;
            break;
          case zx_dap_ItemData_ELEM:
            el = (struct zx_elem_s*)zx_DEC_dap_ItemData(c, ns);
            el->g.n = &x->ItemData->gg.g;
            x->ItemData = (struct zx_dap_ItemData_s*)el;
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






/* FUNC(zx_DEC_dap_Notify) */

#define EL_NAME   dap_Notify
#define EL_STRUCT zx_dap_Notify_s
#define EL_NS     dap
#define EL_TAG    Notify

/* Called by: */
struct zx_dap_Notify_s* zx_DEC_dap_Notify(struct zx_ctx* c, struct zx_ns_s* ns )
{
  int tok;
  struct zx_elem_s* iternode;
  struct zx_elem_s* el;
  struct zx_str* ss;
  struct zx_ns_s* pop_seen;
  char* name;
  char* data;
  struct zx_dap_Notify_s* x = ZX_ZALLOC(c, struct zx_dap_Notify_s);
  x->gg.g.tok = zx_dap_Notify_ELEM;
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
    case zx_timeStamp_ATTR:
      ss = ZX_ZALLOC(c, struct zx_str);
      ss->g.n = &x->timeStamp->g;
      x->timeStamp = ss;
      ZX_ATTR_DEC_EXT(ss);
      break;
    case zx_dst_itemID_ATTR:
      ss = ZX_ZALLOC(c, struct zx_str);
      ss->g.n = &x->itemID->g;
      x->itemID = ss;
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
          case zx_lu_Extension_ELEM:
            el = (struct zx_elem_s*)zx_DEC_lu_Extension(c, ns);
            el->g.n = &x->Extension->gg.g;
            x->Extension = (struct zx_lu_Extension_s*)el;
            break;
          case zx_dap_Notification_ELEM:
            el = (struct zx_elem_s*)zx_DEC_dap_Notification(c, ns);
            el->g.n = &x->Notification->gg.g;
            x->Notification = (struct zx_dap_Notification_s*)el;
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






/* FUNC(zx_DEC_dap_NotifyResponse) */

#define EL_NAME   dap_NotifyResponse
#define EL_STRUCT zx_dap_NotifyResponse_s
#define EL_NS     dap
#define EL_TAG    NotifyResponse

/* Called by: */
struct zx_dap_NotifyResponse_s* zx_DEC_dap_NotifyResponse(struct zx_ctx* c, struct zx_ns_s* ns )
{
  int tok;
  struct zx_elem_s* iternode;
  struct zx_elem_s* el;
  struct zx_str* ss;
  struct zx_ns_s* pop_seen;
  char* name;
  char* data;
  struct zx_dap_NotifyResponse_s* x = ZX_ZALLOC(c, struct zx_dap_NotifyResponse_s);
  x->gg.g.tok = zx_dap_NotifyResponse_ELEM;
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
    case zx_itemIDRef_ATTR:
      ss = ZX_ZALLOC(c, struct zx_str);
      ss->g.n = &x->itemIDRef->g;
      x->itemIDRef = ss;
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
          case zx_lu_Status_ELEM:
            el = (struct zx_elem_s*)zx_DEC_lu_Status(c, ns);
            el->g.n = &x->Status->gg.g;
            x->Status = (struct zx_lu_Status_s*)el;
            break;
          case zx_lu_Extension_ELEM:
            el = (struct zx_elem_s*)zx_DEC_lu_Extension(c, ns);
            el->g.n = &x->Extension->gg.g;
            x->Extension = (struct zx_lu_Extension_s*)el;
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






/* FUNC(zx_DEC_dap_Query) */

#define EL_NAME   dap_Query
#define EL_STRUCT zx_dap_Query_s
#define EL_NS     dap
#define EL_TAG    Query

/* Called by: */
struct zx_dap_Query_s* zx_DEC_dap_Query(struct zx_ctx* c, struct zx_ns_s* ns )
{
  int tok;
  struct zx_elem_s* iternode;
  struct zx_elem_s* el;
  struct zx_str* ss;
  struct zx_ns_s* pop_seen;
  char* name;
  char* data;
  struct zx_dap_Query_s* x = ZX_ZALLOC(c, struct zx_dap_Query_s);
  x->gg.g.tok = zx_dap_Query_ELEM;
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
    case zx_dst_itemID_ATTR:
      ss = ZX_ZALLOC(c, struct zx_str);
      ss->g.n = &x->itemID->g;
      x->itemID = ss;
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
          case zx_lu_Extension_ELEM:
            el = (struct zx_elem_s*)zx_DEC_lu_Extension(c, ns);
            el->g.n = &x->Extension->gg.g;
            x->Extension = (struct zx_lu_Extension_s*)el;
            break;
          case zx_dap_TestItem_ELEM:
            el = (struct zx_elem_s*)zx_DEC_dap_TestItem(c, ns);
            el->g.n = &x->TestItem->gg.g;
            x->TestItem = (struct zx_dap_TestItem_s*)el;
            break;
          case zx_dap_QueryItem_ELEM:
            el = (struct zx_elem_s*)zx_DEC_dap_QueryItem(c, ns);
            el->g.n = &x->QueryItem->gg.g;
            x->QueryItem = (struct zx_dap_QueryItem_s*)el;
            break;
          case zx_dap_Subscription_ELEM:
            el = (struct zx_elem_s*)zx_DEC_dap_Subscription(c, ns);
            el->g.n = &x->Subscription->gg.g;
            x->Subscription = (struct zx_dap_Subscription_s*)el;
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






/* FUNC(zx_DEC_dap_QueryItem) */

#define EL_NAME   dap_QueryItem
#define EL_STRUCT zx_dap_QueryItem_s
#define EL_NS     dap
#define EL_TAG    QueryItem

/* Called by: */
struct zx_dap_QueryItem_s* zx_DEC_dap_QueryItem(struct zx_ctx* c, struct zx_ns_s* ns )
{
  int tok;
  struct zx_elem_s* iternode;
  struct zx_elem_s* el;
  struct zx_str* ss;
  struct zx_ns_s* pop_seen;
  char* name;
  char* data;
  struct zx_dap_QueryItem_s* x = ZX_ZALLOC(c, struct zx_dap_QueryItem_s);
  x->gg.g.tok = zx_dap_QueryItem_ELEM;
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
    case zx_changedSince_ATTR:
      ss = ZX_ZALLOC(c, struct zx_str);
      ss->g.n = &x->changedSince->g;
      x->changedSince = ss;
      ZX_ATTR_DEC_EXT(ss);
      break;
    case zx_contingency_ATTR:
      ss = ZX_ZALLOC(c, struct zx_str);
      ss->g.n = &x->contingency->g;
      x->contingency = ss;
      ZX_ATTR_DEC_EXT(ss);
      break;
    case zx_count_ATTR:
      ss = ZX_ZALLOC(c, struct zx_str);
      ss->g.n = &x->count->g;
      x->count = ss;
      ZX_ATTR_DEC_EXT(ss);
      break;
    case zx_includeCommonAttributes_ATTR:
      ss = ZX_ZALLOC(c, struct zx_str);
      ss->g.n = &x->includeCommonAttributes->g;
      x->includeCommonAttributes = ss;
      ZX_ATTR_DEC_EXT(ss);
      break;
    case zx_offset_ATTR:
      ss = ZX_ZALLOC(c, struct zx_str);
      ss->g.n = &x->offset->g;
      x->offset = ss;
      ZX_ATTR_DEC_EXT(ss);
      break;
    case zx_setID_ATTR:
      ss = ZX_ZALLOC(c, struct zx_str);
      ss->g.n = &x->setID->g;
      x->setID = ss;
      ZX_ATTR_DEC_EXT(ss);
      break;
    case zx_setReq_ATTR:
      ss = ZX_ZALLOC(c, struct zx_str);
      ss->g.n = &x->setReq->g;
      x->setReq = ss;
      ZX_ATTR_DEC_EXT(ss);
      break;
    case zx_dst_itemID_ATTR:
      ss = ZX_ZALLOC(c, struct zx_str);
      ss->g.n = &x->itemID->g;
      x->itemID = ss;
      ZX_ATTR_DEC_EXT(ss);
      break;
    case zx_dst_itemIDRef_ATTR:
      ss = ZX_ZALLOC(c, struct zx_str);
      ss->g.n = &x->itemIDRef->g;
      x->itemIDRef = ss;
      ZX_ATTR_DEC_EXT(ss);
      break;
    case zx_dst_objectType_ATTR:
      ss = ZX_ZALLOC(c, struct zx_str);
      ss->g.n = &x->objectType->g;
      x->objectType = ss;
      ZX_ATTR_DEC_EXT(ss);
      break;
    case zx_dst_predefined_ATTR:
      ss = ZX_ZALLOC(c, struct zx_str);
      ss->g.n = &x->predefined->g;
      x->predefined = ss;
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
          case zx_dst_ChangeFormat_ELEM:
            el = zx_DEC_simple_elem(c, ns, tok);
            el->g.n = &x->ChangeFormat->g;
            x->ChangeFormat = el;
            break;
          case zx_dap_Select_ELEM:
            el = (struct zx_elem_s*)zx_DEC_dap_Select(c, ns);
            el->g.n = &x->Select->gg.g;
            x->Select = (struct zx_dap_Select_s*)el;
            break;
          case zx_dap_Sort_ELEM:
            el = zx_DEC_simple_elem(c, ns, tok);
            el->g.n = &x->Sort->g;
            x->Sort = el;
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






/* FUNC(zx_DEC_dap_QueryResponse) */

#define EL_NAME   dap_QueryResponse
#define EL_STRUCT zx_dap_QueryResponse_s
#define EL_NS     dap
#define EL_TAG    QueryResponse

/* Called by: */
struct zx_dap_QueryResponse_s* zx_DEC_dap_QueryResponse(struct zx_ctx* c, struct zx_ns_s* ns )
{
  int tok;
  struct zx_elem_s* iternode;
  struct zx_elem_s* el;
  struct zx_str* ss;
  struct zx_ns_s* pop_seen;
  char* name;
  char* data;
  struct zx_dap_QueryResponse_s* x = ZX_ZALLOC(c, struct zx_dap_QueryResponse_s);
  x->gg.g.tok = zx_dap_QueryResponse_ELEM;
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
    case zx_timeStamp_ATTR:
      ss = ZX_ZALLOC(c, struct zx_str);
      ss->g.n = &x->timeStamp->g;
      x->timeStamp = ss;
      ZX_ATTR_DEC_EXT(ss);
      break;
    case zx_dst_itemIDRef_ATTR:
      ss = ZX_ZALLOC(c, struct zx_str);
      ss->g.n = &x->itemIDRef->g;
      x->itemIDRef = ss;
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
          case zx_lu_Status_ELEM:
            el = (struct zx_elem_s*)zx_DEC_lu_Status(c, ns);
            el->g.n = &x->Status->gg.g;
            x->Status = (struct zx_lu_Status_s*)el;
            break;
          case zx_lu_Extension_ELEM:
            el = (struct zx_elem_s*)zx_DEC_lu_Extension(c, ns);
            el->g.n = &x->Extension->gg.g;
            x->Extension = (struct zx_lu_Extension_s*)el;
            break;
          case zx_dst_TestResult_ELEM:
            el = (struct zx_elem_s*)zx_DEC_dst_TestResult(c, ns);
            el->g.n = &x->TestResult->gg.g;
            x->TestResult = (struct zx_dst_TestResult_s*)el;
            break;
          case zx_dap_Data_ELEM:
            el = (struct zx_elem_s*)zx_DEC_dap_Data(c, ns);
            el->g.n = &x->Data->gg.g;
            x->Data = (struct zx_dap_Data_s*)el;
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






/* FUNC(zx_DEC_dap_ResultQuery) */

#define EL_NAME   dap_ResultQuery
#define EL_STRUCT zx_dap_ResultQuery_s
#define EL_NS     dap
#define EL_TAG    ResultQuery

/* Called by: */
struct zx_dap_ResultQuery_s* zx_DEC_dap_ResultQuery(struct zx_ctx* c, struct zx_ns_s* ns )
{
  int tok;
  struct zx_elem_s* iternode;
  struct zx_elem_s* el;
  struct zx_str* ss;
  struct zx_ns_s* pop_seen;
  char* name;
  char* data;
  struct zx_dap_ResultQuery_s* x = ZX_ZALLOC(c, struct zx_dap_ResultQuery_s);
  x->gg.g.tok = zx_dap_ResultQuery_ELEM;
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
    case zx_changedSince_ATTR:
      ss = ZX_ZALLOC(c, struct zx_str);
      ss->g.n = &x->changedSince->g;
      x->changedSince = ss;
      ZX_ATTR_DEC_EXT(ss);
      break;
    case zx_contingency_ATTR:
      ss = ZX_ZALLOC(c, struct zx_str);
      ss->g.n = &x->contingency->g;
      x->contingency = ss;
      ZX_ATTR_DEC_EXT(ss);
      break;
    case zx_includeCommonAttributes_ATTR:
      ss = ZX_ZALLOC(c, struct zx_str);
      ss->g.n = &x->includeCommonAttributes->g;
      x->includeCommonAttributes = ss;
      ZX_ATTR_DEC_EXT(ss);
      break;
    case zx_dst_itemID_ATTR:
      ss = ZX_ZALLOC(c, struct zx_str);
      ss->g.n = &x->itemID->g;
      x->itemID = ss;
      ZX_ATTR_DEC_EXT(ss);
      break;
    case zx_dst_itemIDRef_ATTR:
      ss = ZX_ZALLOC(c, struct zx_str);
      ss->g.n = &x->itemIDRef->g;
      x->itemIDRef = ss;
      ZX_ATTR_DEC_EXT(ss);
      break;
    case zx_dst_objectType_ATTR:
      ss = ZX_ZALLOC(c, struct zx_str);
      ss->g.n = &x->objectType->g;
      x->objectType = ss;
      ZX_ATTR_DEC_EXT(ss);
      break;
    case zx_dst_predefined_ATTR:
      ss = ZX_ZALLOC(c, struct zx_str);
      ss->g.n = &x->predefined->g;
      x->predefined = ss;
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
          case zx_dst_ChangeFormat_ELEM:
            el = zx_DEC_simple_elem(c, ns, tok);
            el->g.n = &x->ChangeFormat->g;
            x->ChangeFormat = el;
            break;
          case zx_dap_Select_ELEM:
            el = (struct zx_elem_s*)zx_DEC_dap_Select(c, ns);
            el->g.n = &x->Select->gg.g;
            x->Select = (struct zx_dap_Select_s*)el;
            break;
          case zx_dap_Sort_ELEM:
            el = zx_DEC_simple_elem(c, ns, tok);
            el->g.n = &x->Sort->g;
            x->Sort = el;
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






/* FUNC(zx_DEC_dap_Select) */

#define EL_NAME   dap_Select
#define EL_STRUCT zx_dap_Select_s
#define EL_NS     dap
#define EL_TAG    Select

/* Called by: */
struct zx_dap_Select_s* zx_DEC_dap_Select(struct zx_ctx* c, struct zx_ns_s* ns )
{
  int tok;
  struct zx_elem_s* iternode;
  struct zx_elem_s* el;
  struct zx_str* ss;
  struct zx_ns_s* pop_seen;
  char* name;
  char* data;
  struct zx_dap_Select_s* x = ZX_ZALLOC(c, struct zx_dap_Select_s);
  x->gg.g.tok = zx_dap_Select_ELEM;
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
    case zx_attributes_ATTR:
      ss = ZX_ZALLOC(c, struct zx_str);
      ss->g.n = &x->attributes->g;
      x->attributes = ss;
      ZX_ATTR_DEC_EXT(ss);
      break;
    case zx_derefaliases_ATTR:
      ss = ZX_ZALLOC(c, struct zx_str);
      ss->g.n = &x->derefaliases->g;
      x->derefaliases = ss;
      ZX_ATTR_DEC_EXT(ss);
      break;
    case zx_scope_ATTR:
      ss = ZX_ZALLOC(c, struct zx_str);
      ss->g.n = &x->scope->g;
      x->scope = ss;
      ZX_ATTR_DEC_EXT(ss);
      break;
    case zx_sizelimit_ATTR:
      ss = ZX_ZALLOC(c, struct zx_str);
      ss->g.n = &x->sizelimit->g;
      x->sizelimit = ss;
      ZX_ATTR_DEC_EXT(ss);
      break;
    case zx_timelimit_ATTR:
      ss = ZX_ZALLOC(c, struct zx_str);
      ss->g.n = &x->timelimit->g;
      x->timelimit = ss;
      ZX_ATTR_DEC_EXT(ss);
      break;
    case zx_typesonly_ATTR:
      ss = ZX_ZALLOC(c, struct zx_str);
      ss->g.n = &x->typesonly->g;
      x->typesonly = ss;
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
          case zx_dap_dn_ELEM:
            el = zx_DEC_simple_elem(c, ns, tok);
            el->g.n = &x->dn->g;
            x->dn = el;
            break;
          case zx_dap_filter_ELEM:
            el = zx_DEC_simple_elem(c, ns, tok);
            el->g.n = &x->filter->g;
            x->filter = el;
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






/* FUNC(zx_DEC_dap_Subscription) */

#define EL_NAME   dap_Subscription
#define EL_STRUCT zx_dap_Subscription_s
#define EL_NS     dap
#define EL_TAG    Subscription

/* Called by: */
struct zx_dap_Subscription_s* zx_DEC_dap_Subscription(struct zx_ctx* c, struct zx_ns_s* ns )
{
  int tok;
  struct zx_elem_s* iternode;
  struct zx_elem_s* el;
  struct zx_str* ss;
  struct zx_ns_s* pop_seen;
  char* name;
  char* data;
  struct zx_dap_Subscription_s* x = ZX_ZALLOC(c, struct zx_dap_Subscription_s);
  x->gg.g.tok = zx_dap_Subscription_ELEM;
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
    case zx_adminNotifyToRef_ATTR:
      ss = ZX_ZALLOC(c, struct zx_str);
      ss->g.n = &x->adminNotifyToRef->g;
      x->adminNotifyToRef = ss;
      ZX_ATTR_DEC_EXT(ss);
      break;
    case zx_expires_ATTR:
      ss = ZX_ZALLOC(c, struct zx_str);
      ss->g.n = &x->expires->g;
      x->expires = ss;
      ZX_ATTR_DEC_EXT(ss);
      break;
    case zx_id_ATTR:
      ss = ZX_ZALLOC(c, struct zx_str);
      ss->g.n = &x->id->g;
      x->id = ss;
      ZX_ATTR_DEC_EXT(ss);
      break;
    case zx_includeData_ATTR:
      ss = ZX_ZALLOC(c, struct zx_str);
      ss->g.n = &x->includeData->g;
      x->includeData = ss;
      ZX_ATTR_DEC_EXT(ss);
      break;
    case zx_notifyToRef_ATTR:
      ss = ZX_ZALLOC(c, struct zx_str);
      ss->g.n = &x->notifyToRef->g;
      x->notifyToRef = ss;
      ZX_ATTR_DEC_EXT(ss);
      break;
    case zx_starts_ATTR:
      ss = ZX_ZALLOC(c, struct zx_str);
      ss->g.n = &x->starts->g;
      x->starts = ss;
      ZX_ATTR_DEC_EXT(ss);
      break;
    case zx_subscriptionID_ATTR:
      ss = ZX_ZALLOC(c, struct zx_str);
      ss->g.n = &x->subscriptionID->g;
      x->subscriptionID = ss;
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
          case zx_subs_RefItem_ELEM:
            el = (struct zx_elem_s*)zx_DEC_subs_RefItem(c, ns);
            el->g.n = &x->RefItem->gg.g;
            x->RefItem = (struct zx_subs_RefItem_s*)el;
            break;
          case zx_lu_Extension_ELEM:
            el = (struct zx_elem_s*)zx_DEC_lu_Extension(c, ns);
            el->g.n = &x->Extension->gg.g;
            x->Extension = (struct zx_lu_Extension_s*)el;
            break;
          case zx_dap_ResultQuery_ELEM:
            el = (struct zx_elem_s*)zx_DEC_dap_ResultQuery(c, ns);
            el->g.n = &x->ResultQuery->gg.g;
            x->ResultQuery = (struct zx_dap_ResultQuery_s*)el;
            break;
          case zx_dap_Aggregation_ELEM:
            el = zx_DEC_simple_elem(c, ns, tok);
            el->g.n = &x->Aggregation->g;
            x->Aggregation = el;
            break;
          case zx_dap_Trigger_ELEM:
            el = zx_DEC_simple_elem(c, ns, tok);
            el->g.n = &x->Trigger->g;
            x->Trigger = el;
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






/* FUNC(zx_DEC_dap_TestItem) */

#define EL_NAME   dap_TestItem
#define EL_STRUCT zx_dap_TestItem_s
#define EL_NS     dap
#define EL_TAG    TestItem

/* Called by: */
struct zx_dap_TestItem_s* zx_DEC_dap_TestItem(struct zx_ctx* c, struct zx_ns_s* ns )
{
  int tok;
  struct zx_elem_s* iternode;
  struct zx_elem_s* el;
  struct zx_str* ss;
  struct zx_ns_s* pop_seen;
  char* name;
  char* data;
  struct zx_dap_TestItem_s* x = ZX_ZALLOC(c, struct zx_dap_TestItem_s);
  x->gg.g.tok = zx_dap_TestItem_ELEM;
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
    case zx_id_ATTR:
      ss = ZX_ZALLOC(c, struct zx_str);
      ss->g.n = &x->id->g;
      x->id = ss;
      ZX_ATTR_DEC_EXT(ss);
      break;
    case zx_dst_itemID_ATTR:
      ss = ZX_ZALLOC(c, struct zx_str);
      ss->g.n = &x->itemID->g;
      x->itemID = ss;
      ZX_ATTR_DEC_EXT(ss);
      break;
    case zx_dst_objectType_ATTR:
      ss = ZX_ZALLOC(c, struct zx_str);
      ss->g.n = &x->objectType->g;
      x->objectType = ss;
      ZX_ATTR_DEC_EXT(ss);
      break;
    case zx_dst_predefined_ATTR:
      ss = ZX_ZALLOC(c, struct zx_str);
      ss->g.n = &x->predefined->g;
      x->predefined = ss;
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
          case zx_dap_TestOp_ELEM:
            el = (struct zx_elem_s*)zx_DEC_dap_TestOp(c, ns);
            el->g.n = &x->TestOp->gg.g;
            x->TestOp = (struct zx_dap_TestOp_s*)el;
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






/* FUNC(zx_DEC_dap_TestOp) */

#define EL_NAME   dap_TestOp
#define EL_STRUCT zx_dap_TestOp_s
#define EL_NS     dap
#define EL_TAG    TestOp

/* Called by: */
struct zx_dap_TestOp_s* zx_DEC_dap_TestOp(struct zx_ctx* c, struct zx_ns_s* ns )
{
  int tok;
  struct zx_elem_s* iternode;
  struct zx_elem_s* el;
  struct zx_str* ss;
  struct zx_ns_s* pop_seen;
  char* name;
  char* data;
  struct zx_dap_TestOp_s* x = ZX_ZALLOC(c, struct zx_dap_TestOp_s);
  x->gg.g.tok = zx_dap_TestOp_ELEM;
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
    case zx_attributes_ATTR:
      ss = ZX_ZALLOC(c, struct zx_str);
      ss->g.n = &x->attributes->g;
      x->attributes = ss;
      ZX_ATTR_DEC_EXT(ss);
      break;
    case zx_derefaliases_ATTR:
      ss = ZX_ZALLOC(c, struct zx_str);
      ss->g.n = &x->derefaliases->g;
      x->derefaliases = ss;
      ZX_ATTR_DEC_EXT(ss);
      break;
    case zx_scope_ATTR:
      ss = ZX_ZALLOC(c, struct zx_str);
      ss->g.n = &x->scope->g;
      x->scope = ss;
      ZX_ATTR_DEC_EXT(ss);
      break;
    case zx_sizelimit_ATTR:
      ss = ZX_ZALLOC(c, struct zx_str);
      ss->g.n = &x->sizelimit->g;
      x->sizelimit = ss;
      ZX_ATTR_DEC_EXT(ss);
      break;
    case zx_timelimit_ATTR:
      ss = ZX_ZALLOC(c, struct zx_str);
      ss->g.n = &x->timelimit->g;
      x->timelimit = ss;
      ZX_ATTR_DEC_EXT(ss);
      break;
    case zx_typesonly_ATTR:
      ss = ZX_ZALLOC(c, struct zx_str);
      ss->g.n = &x->typesonly->g;
      x->typesonly = ss;
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
          case zx_dap_dn_ELEM:
            el = zx_DEC_simple_elem(c, ns, tok);
            el->g.n = &x->dn->g;
            x->dn = el;
            break;
          case zx_dap_filter_ELEM:
            el = zx_DEC_simple_elem(c, ns, tok);
            el->g.n = &x->filter->g;
            x->filter = el;
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




/* EOF -- c/zx-dap-dec.c */
