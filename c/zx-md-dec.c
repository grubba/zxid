/* c/zx-md-dec.c - WARNING: This file was automatically generated. DO NOT EDIT!
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
#include "c/zx-md-data.h"

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



/* FUNC(zx_DEC_md_AdditionalMetadataLocation) */

#define EL_NAME   md_AdditionalMetadataLocation
#define EL_STRUCT zx_md_AdditionalMetadataLocation_s
#define EL_NS     md
#define EL_TAG    AdditionalMetadataLocation

/* Called by: */
struct zx_md_AdditionalMetadataLocation_s* zx_DEC_md_AdditionalMetadataLocation(struct zx_ctx* c, struct zx_ns_s* ns )
{
  int tok;
  struct zx_elem_s* el;
  struct zx_str* ss;
  struct zx_ns_s* pop_seen;
  const char* name;
  const char* data;
  struct zx_md_AdditionalMetadataLocation_s* x = ZX_ZALLOC(c, struct zx_md_AdditionalMetadataLocation_s);
  x->gg.g.tok = zx_md_AdditionalMetadataLocation_ELEM;
  x->gg.g.ns = ns;
  ZX_START_DEC_EXT(x);

#if 1 /* NORMALMODE */
  ZX_DEC_TAG_NOT_YET_CLOSED(x->gg.g);

  /* The tag name has already been detected. Process attributes until '>' */
  
  for (; c->p; ++c->p) {
    ZX_SKIP_WS(c,x);
    if (ONE_OF_2(*c->p, '>', '/'))
      break;
    if (!(data = zx_dec_attr_val(c, &name, (const char*)__FUNCTION__)))
      return x;
    tok = zx_attr_lookup(c, name, data-2, &ns);
    switch (tok) {
    case zx_namespace_ATTR:
      ss = ZX_ZALLOC(c, struct zx_str);
      ss->g.n = &x->namespace_is_cxx_keyword->g;
      x->namespace_is_cxx_keyword = ss;
      ZX_ATTR_DEC_EXT(ss);
      break;

    case ZX_TOK_XMLNS:
      ZX_XMLNS_DEC_EXT(name);
      DD("xmlns detected(%.*s)", data-2-name, name);
      ns = zx_new_ns(c, data-2-name, name, c->p - data, data);
      ns->n = x->gg.xmlns;
      x->gg.xmlns = ns;
      goto next_attr;
    default:
      ss = zx_dec_unknown_attr(c, &x->gg, name, data, tok, x->gg.g.tok);
    }
    ss->g.ns = ns;    /* Fill in the rest of the ss fields (its already linked to right list). */
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
	  zx_xml_parse_err_mismatching_close_tag(c, (const char*)__FUNCTION__, name, tok);
	  ZX_DEC_TAG_MISMATCH_CLOSE(x->gg.g);
	  return x;
	}
	/* Legitimate close tag. Normal exit from this function. */
	++c->p;
	ZX_DEC_TAG_NOW_CLOSED(x->gg.g);
	goto out;
      default:
	if (A_Z_a_z_(*c->p)) {
	  if (!(name = zx_scan_elem_start(c, (const char*)__FUNCTION__)))
	    return x;
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
  zx_dec_reverse_lists(&x->gg);
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






/* FUNC(zx_DEC_md_AffiliationDescriptor) */

#define EL_NAME   md_AffiliationDescriptor
#define EL_STRUCT zx_md_AffiliationDescriptor_s
#define EL_NS     md
#define EL_TAG    AffiliationDescriptor

/* Called by: */
struct zx_md_AffiliationDescriptor_s* zx_DEC_md_AffiliationDescriptor(struct zx_ctx* c, struct zx_ns_s* ns )
{
  int tok;
  struct zx_elem_s* el;
  struct zx_str* ss;
  struct zx_ns_s* pop_seen;
  const char* name;
  const char* data;
  struct zx_md_AffiliationDescriptor_s* x = ZX_ZALLOC(c, struct zx_md_AffiliationDescriptor_s);
  x->gg.g.tok = zx_md_AffiliationDescriptor_ELEM;
  x->gg.g.ns = ns;
  ZX_START_DEC_EXT(x);

#if 1 /* NORMALMODE */
  ZX_DEC_TAG_NOT_YET_CLOSED(x->gg.g);

  /* The tag name has already been detected. Process attributes until '>' */
  
  for (; c->p; ++c->p) {
    ZX_SKIP_WS(c,x);
    if (ONE_OF_2(*c->p, '>', '/'))
      break;
    if (!(data = zx_dec_attr_val(c, &name, (const char*)__FUNCTION__)))
      return x;
    tok = zx_attr_lookup(c, name, data-2, &ns);
    switch (tok) {
    case zx_ID_ATTR:
      ss = ZX_ZALLOC(c, struct zx_str);
      ss->g.n = &x->ID->g;
      x->ID = ss;
      ZX_ATTR_DEC_EXT(ss);
      break;
    case zx_affiliationOwnerID_ATTR:
      ss = ZX_ZALLOC(c, struct zx_str);
      ss->g.n = &x->affiliationOwnerID->g;
      x->affiliationOwnerID = ss;
      ZX_ATTR_DEC_EXT(ss);
      break;
    case zx_cacheDuration_ATTR:
      ss = ZX_ZALLOC(c, struct zx_str);
      ss->g.n = &x->cacheDuration->g;
      x->cacheDuration = ss;
      ZX_ATTR_DEC_EXT(ss);
      break;
    case zx_validUntil_ATTR:
      ss = ZX_ZALLOC(c, struct zx_str);
      ss->g.n = &x->validUntil->g;
      x->validUntil = ss;
      ZX_ATTR_DEC_EXT(ss);
      break;

    case ZX_TOK_XMLNS:
      ZX_XMLNS_DEC_EXT(name);
      DD("xmlns detected(%.*s)", data-2-name, name);
      ns = zx_new_ns(c, data-2-name, name, c->p - data, data);
      ns->n = x->gg.xmlns;
      x->gg.xmlns = ns;
      goto next_attr;
    default:
      ss = zx_dec_unknown_attr(c, &x->gg, name, data, tok, x->gg.g.tok);
    }
    ss->g.ns = ns;    /* Fill in the rest of the ss fields (its already linked to right list). */
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
	  zx_xml_parse_err_mismatching_close_tag(c, (const char*)__FUNCTION__, name, tok);
	  ZX_DEC_TAG_MISMATCH_CLOSE(x->gg.g);
	  return x;
	}
	/* Legitimate close tag. Normal exit from this function. */
	++c->p;
	ZX_DEC_TAG_NOW_CLOSED(x->gg.g);
	goto out;
      default:
	if (A_Z_a_z_(*c->p)) {
	  if (!(name = zx_scan_elem_start(c, (const char*)__FUNCTION__)))
	    return x;
	  pop_seen = zx_scan_xmlns(c);  /* Prescan namespaces so that token can be correctly recognized. */
	  tok = zx_elem_lookup(c, name, c->p, &ns);
	  switch (tok) {
          case zx_ds_Signature_ELEM:
            el = (struct zx_elem_s*)zx_DEC_ds_Signature(c, ns);
            el->g.n = &x->Signature->gg.g;
            x->Signature = (struct zx_ds_Signature_s*)el;
            break;
          case zx_md_Extensions_ELEM:
            el = (struct zx_elem_s*)zx_DEC_md_Extensions(c, ns);
            el->g.n = &x->Extensions->gg.g;
            x->Extensions = (struct zx_md_Extensions_s*)el;
            break;
          case zx_md_AffiliateMember_ELEM:
            el = zx_DEC_simple_elem(c, ns, tok);
            el->g.n = &x->AffiliateMember->g;
            x->AffiliateMember = el;
            break;
          case zx_md_KeyDescriptor_ELEM:
            el = (struct zx_elem_s*)zx_DEC_md_KeyDescriptor(c, ns);
            el->g.n = &x->KeyDescriptor->gg.g;
            x->KeyDescriptor = (struct zx_md_KeyDescriptor_s*)el;
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
  zx_dec_reverse_lists(&x->gg);
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






/* FUNC(zx_DEC_md_ArtifactResolutionService) */

#define EL_NAME   md_ArtifactResolutionService
#define EL_STRUCT zx_md_ArtifactResolutionService_s
#define EL_NS     md
#define EL_TAG    ArtifactResolutionService

/* Called by: */
struct zx_md_ArtifactResolutionService_s* zx_DEC_md_ArtifactResolutionService(struct zx_ctx* c, struct zx_ns_s* ns )
{
  int tok;
  struct zx_elem_s* el;
  struct zx_str* ss;
  struct zx_ns_s* pop_seen;
  const char* name;
  const char* data;
  struct zx_md_ArtifactResolutionService_s* x = ZX_ZALLOC(c, struct zx_md_ArtifactResolutionService_s);
  x->gg.g.tok = zx_md_ArtifactResolutionService_ELEM;
  x->gg.g.ns = ns;
  ZX_START_DEC_EXT(x);

#if 1 /* NORMALMODE */
  ZX_DEC_TAG_NOT_YET_CLOSED(x->gg.g);

  /* The tag name has already been detected. Process attributes until '>' */
  
  for (; c->p; ++c->p) {
    ZX_SKIP_WS(c,x);
    if (ONE_OF_2(*c->p, '>', '/'))
      break;
    if (!(data = zx_dec_attr_val(c, &name, (const char*)__FUNCTION__)))
      return x;
    tok = zx_attr_lookup(c, name, data-2, &ns);
    switch (tok) {
    case zx_Binding_ATTR:
      ss = ZX_ZALLOC(c, struct zx_str);
      ss->g.n = &x->Binding->g;
      x->Binding = ss;
      ZX_ATTR_DEC_EXT(ss);
      break;
    case zx_Location_ATTR:
      ss = ZX_ZALLOC(c, struct zx_str);
      ss->g.n = &x->Location->g;
      x->Location = ss;
      ZX_ATTR_DEC_EXT(ss);
      break;
    case zx_ResponseLocation_ATTR:
      ss = ZX_ZALLOC(c, struct zx_str);
      ss->g.n = &x->ResponseLocation->g;
      x->ResponseLocation = ss;
      ZX_ATTR_DEC_EXT(ss);
      break;
    case zx_index_ATTR:
      ss = ZX_ZALLOC(c, struct zx_str);
      ss->g.n = &x->index->g;
      x->index = ss;
      ZX_ATTR_DEC_EXT(ss);
      break;
    case zx_isDefault_ATTR:
      ss = ZX_ZALLOC(c, struct zx_str);
      ss->g.n = &x->isDefault->g;
      x->isDefault = ss;
      ZX_ATTR_DEC_EXT(ss);
      break;

    case ZX_TOK_XMLNS:
      ZX_XMLNS_DEC_EXT(name);
      DD("xmlns detected(%.*s)", data-2-name, name);
      ns = zx_new_ns(c, data-2-name, name, c->p - data, data);
      ns->n = x->gg.xmlns;
      x->gg.xmlns = ns;
      goto next_attr;
    default:
      ss = zx_dec_unknown_attr(c, &x->gg, name, data, tok, x->gg.g.tok);
    }
    ss->g.ns = ns;    /* Fill in the rest of the ss fields (its already linked to right list). */
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
	  zx_xml_parse_err_mismatching_close_tag(c, (const char*)__FUNCTION__, name, tok);
	  ZX_DEC_TAG_MISMATCH_CLOSE(x->gg.g);
	  return x;
	}
	/* Legitimate close tag. Normal exit from this function. */
	++c->p;
	ZX_DEC_TAG_NOW_CLOSED(x->gg.g);
	goto out;
      default:
	if (A_Z_a_z_(*c->p)) {
	  if (!(name = zx_scan_elem_start(c, (const char*)__FUNCTION__)))
	    return x;
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
  zx_dec_reverse_lists(&x->gg);
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






/* FUNC(zx_DEC_md_AssertionConsumerService) */

#define EL_NAME   md_AssertionConsumerService
#define EL_STRUCT zx_md_AssertionConsumerService_s
#define EL_NS     md
#define EL_TAG    AssertionConsumerService

/* Called by: */
struct zx_md_AssertionConsumerService_s* zx_DEC_md_AssertionConsumerService(struct zx_ctx* c, struct zx_ns_s* ns )
{
  int tok;
  struct zx_elem_s* el;
  struct zx_str* ss;
  struct zx_ns_s* pop_seen;
  const char* name;
  const char* data;
  struct zx_md_AssertionConsumerService_s* x = ZX_ZALLOC(c, struct zx_md_AssertionConsumerService_s);
  x->gg.g.tok = zx_md_AssertionConsumerService_ELEM;
  x->gg.g.ns = ns;
  ZX_START_DEC_EXT(x);

#if 1 /* NORMALMODE */
  ZX_DEC_TAG_NOT_YET_CLOSED(x->gg.g);

  /* The tag name has already been detected. Process attributes until '>' */
  
  for (; c->p; ++c->p) {
    ZX_SKIP_WS(c,x);
    if (ONE_OF_2(*c->p, '>', '/'))
      break;
    if (!(data = zx_dec_attr_val(c, &name, (const char*)__FUNCTION__)))
      return x;
    tok = zx_attr_lookup(c, name, data-2, &ns);
    switch (tok) {
    case zx_Binding_ATTR:
      ss = ZX_ZALLOC(c, struct zx_str);
      ss->g.n = &x->Binding->g;
      x->Binding = ss;
      ZX_ATTR_DEC_EXT(ss);
      break;
    case zx_Location_ATTR:
      ss = ZX_ZALLOC(c, struct zx_str);
      ss->g.n = &x->Location->g;
      x->Location = ss;
      ZX_ATTR_DEC_EXT(ss);
      break;
    case zx_ResponseLocation_ATTR:
      ss = ZX_ZALLOC(c, struct zx_str);
      ss->g.n = &x->ResponseLocation->g;
      x->ResponseLocation = ss;
      ZX_ATTR_DEC_EXT(ss);
      break;
    case zx_index_ATTR:
      ss = ZX_ZALLOC(c, struct zx_str);
      ss->g.n = &x->index->g;
      x->index = ss;
      ZX_ATTR_DEC_EXT(ss);
      break;
    case zx_isDefault_ATTR:
      ss = ZX_ZALLOC(c, struct zx_str);
      ss->g.n = &x->isDefault->g;
      x->isDefault = ss;
      ZX_ATTR_DEC_EXT(ss);
      break;

    case ZX_TOK_XMLNS:
      ZX_XMLNS_DEC_EXT(name);
      DD("xmlns detected(%.*s)", data-2-name, name);
      ns = zx_new_ns(c, data-2-name, name, c->p - data, data);
      ns->n = x->gg.xmlns;
      x->gg.xmlns = ns;
      goto next_attr;
    default:
      ss = zx_dec_unknown_attr(c, &x->gg, name, data, tok, x->gg.g.tok);
    }
    ss->g.ns = ns;    /* Fill in the rest of the ss fields (its already linked to right list). */
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
	  zx_xml_parse_err_mismatching_close_tag(c, (const char*)__FUNCTION__, name, tok);
	  ZX_DEC_TAG_MISMATCH_CLOSE(x->gg.g);
	  return x;
	}
	/* Legitimate close tag. Normal exit from this function. */
	++c->p;
	ZX_DEC_TAG_NOW_CLOSED(x->gg.g);
	goto out;
      default:
	if (A_Z_a_z_(*c->p)) {
	  if (!(name = zx_scan_elem_start(c, (const char*)__FUNCTION__)))
	    return x;
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
  zx_dec_reverse_lists(&x->gg);
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






/* FUNC(zx_DEC_md_AssertionIDRequestService) */

#define EL_NAME   md_AssertionIDRequestService
#define EL_STRUCT zx_md_AssertionIDRequestService_s
#define EL_NS     md
#define EL_TAG    AssertionIDRequestService

/* Called by: */
struct zx_md_AssertionIDRequestService_s* zx_DEC_md_AssertionIDRequestService(struct zx_ctx* c, struct zx_ns_s* ns )
{
  int tok;
  struct zx_elem_s* el;
  struct zx_str* ss;
  struct zx_ns_s* pop_seen;
  const char* name;
  const char* data;
  struct zx_md_AssertionIDRequestService_s* x = ZX_ZALLOC(c, struct zx_md_AssertionIDRequestService_s);
  x->gg.g.tok = zx_md_AssertionIDRequestService_ELEM;
  x->gg.g.ns = ns;
  ZX_START_DEC_EXT(x);

#if 1 /* NORMALMODE */
  ZX_DEC_TAG_NOT_YET_CLOSED(x->gg.g);

  /* The tag name has already been detected. Process attributes until '>' */
  
  for (; c->p; ++c->p) {
    ZX_SKIP_WS(c,x);
    if (ONE_OF_2(*c->p, '>', '/'))
      break;
    if (!(data = zx_dec_attr_val(c, &name, (const char*)__FUNCTION__)))
      return x;
    tok = zx_attr_lookup(c, name, data-2, &ns);
    switch (tok) {
    case zx_Binding_ATTR:
      ss = ZX_ZALLOC(c, struct zx_str);
      ss->g.n = &x->Binding->g;
      x->Binding = ss;
      ZX_ATTR_DEC_EXT(ss);
      break;
    case zx_Location_ATTR:
      ss = ZX_ZALLOC(c, struct zx_str);
      ss->g.n = &x->Location->g;
      x->Location = ss;
      ZX_ATTR_DEC_EXT(ss);
      break;
    case zx_ResponseLocation_ATTR:
      ss = ZX_ZALLOC(c, struct zx_str);
      ss->g.n = &x->ResponseLocation->g;
      x->ResponseLocation = ss;
      ZX_ATTR_DEC_EXT(ss);
      break;
    case zx_index_ATTR:
      ss = ZX_ZALLOC(c, struct zx_str);
      ss->g.n = &x->index->g;
      x->index = ss;
      ZX_ATTR_DEC_EXT(ss);
      break;
    case zx_isDefault_ATTR:
      ss = ZX_ZALLOC(c, struct zx_str);
      ss->g.n = &x->isDefault->g;
      x->isDefault = ss;
      ZX_ATTR_DEC_EXT(ss);
      break;

    case ZX_TOK_XMLNS:
      ZX_XMLNS_DEC_EXT(name);
      DD("xmlns detected(%.*s)", data-2-name, name);
      ns = zx_new_ns(c, data-2-name, name, c->p - data, data);
      ns->n = x->gg.xmlns;
      x->gg.xmlns = ns;
      goto next_attr;
    default:
      ss = zx_dec_unknown_attr(c, &x->gg, name, data, tok, x->gg.g.tok);
    }
    ss->g.ns = ns;    /* Fill in the rest of the ss fields (its already linked to right list). */
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
	  zx_xml_parse_err_mismatching_close_tag(c, (const char*)__FUNCTION__, name, tok);
	  ZX_DEC_TAG_MISMATCH_CLOSE(x->gg.g);
	  return x;
	}
	/* Legitimate close tag. Normal exit from this function. */
	++c->p;
	ZX_DEC_TAG_NOW_CLOSED(x->gg.g);
	goto out;
      default:
	if (A_Z_a_z_(*c->p)) {
	  if (!(name = zx_scan_elem_start(c, (const char*)__FUNCTION__)))
	    return x;
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
  zx_dec_reverse_lists(&x->gg);
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






/* FUNC(zx_DEC_md_AttributeAuthorityDescriptor) */

#define EL_NAME   md_AttributeAuthorityDescriptor
#define EL_STRUCT zx_md_AttributeAuthorityDescriptor_s
#define EL_NS     md
#define EL_TAG    AttributeAuthorityDescriptor

/* Called by: */
struct zx_md_AttributeAuthorityDescriptor_s* zx_DEC_md_AttributeAuthorityDescriptor(struct zx_ctx* c, struct zx_ns_s* ns )
{
  int tok;
  struct zx_elem_s* el;
  struct zx_str* ss;
  struct zx_ns_s* pop_seen;
  const char* name;
  const char* data;
  struct zx_md_AttributeAuthorityDescriptor_s* x = ZX_ZALLOC(c, struct zx_md_AttributeAuthorityDescriptor_s);
  x->gg.g.tok = zx_md_AttributeAuthorityDescriptor_ELEM;
  x->gg.g.ns = ns;
  ZX_START_DEC_EXT(x);

#if 1 /* NORMALMODE */
  ZX_DEC_TAG_NOT_YET_CLOSED(x->gg.g);

  /* The tag name has already been detected. Process attributes until '>' */
  
  for (; c->p; ++c->p) {
    ZX_SKIP_WS(c,x);
    if (ONE_OF_2(*c->p, '>', '/'))
      break;
    if (!(data = zx_dec_attr_val(c, &name, (const char*)__FUNCTION__)))
      return x;
    tok = zx_attr_lookup(c, name, data-2, &ns);
    switch (tok) {
    case zx_ID_ATTR:
      ss = ZX_ZALLOC(c, struct zx_str);
      ss->g.n = &x->ID->g;
      x->ID = ss;
      ZX_ATTR_DEC_EXT(ss);
      break;
    case zx_cacheDuration_ATTR:
      ss = ZX_ZALLOC(c, struct zx_str);
      ss->g.n = &x->cacheDuration->g;
      x->cacheDuration = ss;
      ZX_ATTR_DEC_EXT(ss);
      break;
    case zx_errorURL_ATTR:
      ss = ZX_ZALLOC(c, struct zx_str);
      ss->g.n = &x->errorURL->g;
      x->errorURL = ss;
      ZX_ATTR_DEC_EXT(ss);
      break;
    case zx_protocolSupportEnumeration_ATTR:
      ss = ZX_ZALLOC(c, struct zx_str);
      ss->g.n = &x->protocolSupportEnumeration->g;
      x->protocolSupportEnumeration = ss;
      ZX_ATTR_DEC_EXT(ss);
      break;
    case zx_validUntil_ATTR:
      ss = ZX_ZALLOC(c, struct zx_str);
      ss->g.n = &x->validUntil->g;
      x->validUntil = ss;
      ZX_ATTR_DEC_EXT(ss);
      break;

    case ZX_TOK_XMLNS:
      ZX_XMLNS_DEC_EXT(name);
      DD("xmlns detected(%.*s)", data-2-name, name);
      ns = zx_new_ns(c, data-2-name, name, c->p - data, data);
      ns->n = x->gg.xmlns;
      x->gg.xmlns = ns;
      goto next_attr;
    default:
      ss = zx_dec_unknown_attr(c, &x->gg, name, data, tok, x->gg.g.tok);
    }
    ss->g.ns = ns;    /* Fill in the rest of the ss fields (its already linked to right list). */
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
	  zx_xml_parse_err_mismatching_close_tag(c, (const char*)__FUNCTION__, name, tok);
	  ZX_DEC_TAG_MISMATCH_CLOSE(x->gg.g);
	  return x;
	}
	/* Legitimate close tag. Normal exit from this function. */
	++c->p;
	ZX_DEC_TAG_NOW_CLOSED(x->gg.g);
	goto out;
      default:
	if (A_Z_a_z_(*c->p)) {
	  if (!(name = zx_scan_elem_start(c, (const char*)__FUNCTION__)))
	    return x;
	  pop_seen = zx_scan_xmlns(c);  /* Prescan namespaces so that token can be correctly recognized. */
	  tok = zx_elem_lookup(c, name, c->p, &ns);
	  switch (tok) {
          case zx_ds_Signature_ELEM:
            el = (struct zx_elem_s*)zx_DEC_ds_Signature(c, ns);
            el->g.n = &x->Signature->gg.g;
            x->Signature = (struct zx_ds_Signature_s*)el;
            break;
          case zx_md_Extensions_ELEM:
            el = (struct zx_elem_s*)zx_DEC_md_Extensions(c, ns);
            el->g.n = &x->Extensions->gg.g;
            x->Extensions = (struct zx_md_Extensions_s*)el;
            break;
          case zx_md_KeyDescriptor_ELEM:
            el = (struct zx_elem_s*)zx_DEC_md_KeyDescriptor(c, ns);
            el->g.n = &x->KeyDescriptor->gg.g;
            x->KeyDescriptor = (struct zx_md_KeyDescriptor_s*)el;
            break;
          case zx_md_Organization_ELEM:
            el = (struct zx_elem_s*)zx_DEC_md_Organization(c, ns);
            el->g.n = &x->Organization->gg.g;
            x->Organization = (struct zx_md_Organization_s*)el;
            break;
          case zx_md_ContactPerson_ELEM:
            el = (struct zx_elem_s*)zx_DEC_md_ContactPerson(c, ns);
            el->g.n = &x->ContactPerson->gg.g;
            x->ContactPerson = (struct zx_md_ContactPerson_s*)el;
            break;
          case zx_md_AttributeService_ELEM:
            el = (struct zx_elem_s*)zx_DEC_md_AttributeService(c, ns);
            el->g.n = &x->AttributeService->gg.g;
            x->AttributeService = (struct zx_md_AttributeService_s*)el;
            break;
          case zx_md_AssertionIDRequestService_ELEM:
            el = (struct zx_elem_s*)zx_DEC_md_AssertionIDRequestService(c, ns);
            el->g.n = &x->AssertionIDRequestService->gg.g;
            x->AssertionIDRequestService = (struct zx_md_AssertionIDRequestService_s*)el;
            break;
          case zx_md_NameIDFormat_ELEM:
            el = zx_DEC_simple_elem(c, ns, tok);
            el->g.n = &x->NameIDFormat->g;
            x->NameIDFormat = el;
            break;
          case zx_md_AttributeProfile_ELEM:
            el = zx_DEC_simple_elem(c, ns, tok);
            el->g.n = &x->AttributeProfile->g;
            x->AttributeProfile = el;
            break;
          case zx_sa_Attribute_ELEM:
            el = (struct zx_elem_s*)zx_DEC_sa_Attribute(c, ns);
            el->g.n = &x->Attribute->gg.g;
            x->Attribute = (struct zx_sa_Attribute_s*)el;
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
  zx_dec_reverse_lists(&x->gg);
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






/* FUNC(zx_DEC_md_AttributeConsumingService) */

#define EL_NAME   md_AttributeConsumingService
#define EL_STRUCT zx_md_AttributeConsumingService_s
#define EL_NS     md
#define EL_TAG    AttributeConsumingService

/* Called by: */
struct zx_md_AttributeConsumingService_s* zx_DEC_md_AttributeConsumingService(struct zx_ctx* c, struct zx_ns_s* ns )
{
  int tok;
  struct zx_elem_s* el;
  struct zx_str* ss;
  struct zx_ns_s* pop_seen;
  const char* name;
  const char* data;
  struct zx_md_AttributeConsumingService_s* x = ZX_ZALLOC(c, struct zx_md_AttributeConsumingService_s);
  x->gg.g.tok = zx_md_AttributeConsumingService_ELEM;
  x->gg.g.ns = ns;
  ZX_START_DEC_EXT(x);

#if 1 /* NORMALMODE */
  ZX_DEC_TAG_NOT_YET_CLOSED(x->gg.g);

  /* The tag name has already been detected. Process attributes until '>' */
  
  for (; c->p; ++c->p) {
    ZX_SKIP_WS(c,x);
    if (ONE_OF_2(*c->p, '>', '/'))
      break;
    if (!(data = zx_dec_attr_val(c, &name, (const char*)__FUNCTION__)))
      return x;
    tok = zx_attr_lookup(c, name, data-2, &ns);
    switch (tok) {
    case zx_index_ATTR:
      ss = ZX_ZALLOC(c, struct zx_str);
      ss->g.n = &x->index->g;
      x->index = ss;
      ZX_ATTR_DEC_EXT(ss);
      break;
    case zx_isDefault_ATTR:
      ss = ZX_ZALLOC(c, struct zx_str);
      ss->g.n = &x->isDefault->g;
      x->isDefault = ss;
      ZX_ATTR_DEC_EXT(ss);
      break;

    case ZX_TOK_XMLNS:
      ZX_XMLNS_DEC_EXT(name);
      DD("xmlns detected(%.*s)", data-2-name, name);
      ns = zx_new_ns(c, data-2-name, name, c->p - data, data);
      ns->n = x->gg.xmlns;
      x->gg.xmlns = ns;
      goto next_attr;
    default:
      ss = zx_dec_unknown_attr(c, &x->gg, name, data, tok, x->gg.g.tok);
    }
    ss->g.ns = ns;    /* Fill in the rest of the ss fields (its already linked to right list). */
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
	  zx_xml_parse_err_mismatching_close_tag(c, (const char*)__FUNCTION__, name, tok);
	  ZX_DEC_TAG_MISMATCH_CLOSE(x->gg.g);
	  return x;
	}
	/* Legitimate close tag. Normal exit from this function. */
	++c->p;
	ZX_DEC_TAG_NOW_CLOSED(x->gg.g);
	goto out;
      default:
	if (A_Z_a_z_(*c->p)) {
	  if (!(name = zx_scan_elem_start(c, (const char*)__FUNCTION__)))
	    return x;
	  pop_seen = zx_scan_xmlns(c);  /* Prescan namespaces so that token can be correctly recognized. */
	  tok = zx_elem_lookup(c, name, c->p, &ns);
	  switch (tok) {
          case zx_md_ServiceName_ELEM:
            el = (struct zx_elem_s*)zx_DEC_md_ServiceName(c, ns);
            el->g.n = &x->ServiceName->gg.g;
            x->ServiceName = (struct zx_md_ServiceName_s*)el;
            break;
          case zx_md_ServiceDescription_ELEM:
            el = (struct zx_elem_s*)zx_DEC_md_ServiceDescription(c, ns);
            el->g.n = &x->ServiceDescription->gg.g;
            x->ServiceDescription = (struct zx_md_ServiceDescription_s*)el;
            break;
          case zx_md_RequestedAttribute_ELEM:
            el = (struct zx_elem_s*)zx_DEC_md_RequestedAttribute(c, ns);
            el->g.n = &x->RequestedAttribute->gg.g;
            x->RequestedAttribute = (struct zx_md_RequestedAttribute_s*)el;
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
  zx_dec_reverse_lists(&x->gg);
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






/* FUNC(zx_DEC_md_AttributeService) */

#define EL_NAME   md_AttributeService
#define EL_STRUCT zx_md_AttributeService_s
#define EL_NS     md
#define EL_TAG    AttributeService

/* Called by: */
struct zx_md_AttributeService_s* zx_DEC_md_AttributeService(struct zx_ctx* c, struct zx_ns_s* ns )
{
  int tok;
  struct zx_elem_s* el;
  struct zx_str* ss;
  struct zx_ns_s* pop_seen;
  const char* name;
  const char* data;
  struct zx_md_AttributeService_s* x = ZX_ZALLOC(c, struct zx_md_AttributeService_s);
  x->gg.g.tok = zx_md_AttributeService_ELEM;
  x->gg.g.ns = ns;
  ZX_START_DEC_EXT(x);

#if 1 /* NORMALMODE */
  ZX_DEC_TAG_NOT_YET_CLOSED(x->gg.g);

  /* The tag name has already been detected. Process attributes until '>' */
  
  for (; c->p; ++c->p) {
    ZX_SKIP_WS(c,x);
    if (ONE_OF_2(*c->p, '>', '/'))
      break;
    if (!(data = zx_dec_attr_val(c, &name, (const char*)__FUNCTION__)))
      return x;
    tok = zx_attr_lookup(c, name, data-2, &ns);
    switch (tok) {
    case zx_Binding_ATTR:
      ss = ZX_ZALLOC(c, struct zx_str);
      ss->g.n = &x->Binding->g;
      x->Binding = ss;
      ZX_ATTR_DEC_EXT(ss);
      break;
    case zx_Location_ATTR:
      ss = ZX_ZALLOC(c, struct zx_str);
      ss->g.n = &x->Location->g;
      x->Location = ss;
      ZX_ATTR_DEC_EXT(ss);
      break;
    case zx_ResponseLocation_ATTR:
      ss = ZX_ZALLOC(c, struct zx_str);
      ss->g.n = &x->ResponseLocation->g;
      x->ResponseLocation = ss;
      ZX_ATTR_DEC_EXT(ss);
      break;
    case zx_index_ATTR:
      ss = ZX_ZALLOC(c, struct zx_str);
      ss->g.n = &x->index->g;
      x->index = ss;
      ZX_ATTR_DEC_EXT(ss);
      break;
    case zx_isDefault_ATTR:
      ss = ZX_ZALLOC(c, struct zx_str);
      ss->g.n = &x->isDefault->g;
      x->isDefault = ss;
      ZX_ATTR_DEC_EXT(ss);
      break;

    case ZX_TOK_XMLNS:
      ZX_XMLNS_DEC_EXT(name);
      DD("xmlns detected(%.*s)", data-2-name, name);
      ns = zx_new_ns(c, data-2-name, name, c->p - data, data);
      ns->n = x->gg.xmlns;
      x->gg.xmlns = ns;
      goto next_attr;
    default:
      ss = zx_dec_unknown_attr(c, &x->gg, name, data, tok, x->gg.g.tok);
    }
    ss->g.ns = ns;    /* Fill in the rest of the ss fields (its already linked to right list). */
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
	  zx_xml_parse_err_mismatching_close_tag(c, (const char*)__FUNCTION__, name, tok);
	  ZX_DEC_TAG_MISMATCH_CLOSE(x->gg.g);
	  return x;
	}
	/* Legitimate close tag. Normal exit from this function. */
	++c->p;
	ZX_DEC_TAG_NOW_CLOSED(x->gg.g);
	goto out;
      default:
	if (A_Z_a_z_(*c->p)) {
	  if (!(name = zx_scan_elem_start(c, (const char*)__FUNCTION__)))
	    return x;
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
  zx_dec_reverse_lists(&x->gg);
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






/* FUNC(zx_DEC_md_AuthnAuthorityDescriptor) */

#define EL_NAME   md_AuthnAuthorityDescriptor
#define EL_STRUCT zx_md_AuthnAuthorityDescriptor_s
#define EL_NS     md
#define EL_TAG    AuthnAuthorityDescriptor

/* Called by: */
struct zx_md_AuthnAuthorityDescriptor_s* zx_DEC_md_AuthnAuthorityDescriptor(struct zx_ctx* c, struct zx_ns_s* ns )
{
  int tok;
  struct zx_elem_s* el;
  struct zx_str* ss;
  struct zx_ns_s* pop_seen;
  const char* name;
  const char* data;
  struct zx_md_AuthnAuthorityDescriptor_s* x = ZX_ZALLOC(c, struct zx_md_AuthnAuthorityDescriptor_s);
  x->gg.g.tok = zx_md_AuthnAuthorityDescriptor_ELEM;
  x->gg.g.ns = ns;
  ZX_START_DEC_EXT(x);

#if 1 /* NORMALMODE */
  ZX_DEC_TAG_NOT_YET_CLOSED(x->gg.g);

  /* The tag name has already been detected. Process attributes until '>' */
  
  for (; c->p; ++c->p) {
    ZX_SKIP_WS(c,x);
    if (ONE_OF_2(*c->p, '>', '/'))
      break;
    if (!(data = zx_dec_attr_val(c, &name, (const char*)__FUNCTION__)))
      return x;
    tok = zx_attr_lookup(c, name, data-2, &ns);
    switch (tok) {
    case zx_ID_ATTR:
      ss = ZX_ZALLOC(c, struct zx_str);
      ss->g.n = &x->ID->g;
      x->ID = ss;
      ZX_ATTR_DEC_EXT(ss);
      break;
    case zx_cacheDuration_ATTR:
      ss = ZX_ZALLOC(c, struct zx_str);
      ss->g.n = &x->cacheDuration->g;
      x->cacheDuration = ss;
      ZX_ATTR_DEC_EXT(ss);
      break;
    case zx_errorURL_ATTR:
      ss = ZX_ZALLOC(c, struct zx_str);
      ss->g.n = &x->errorURL->g;
      x->errorURL = ss;
      ZX_ATTR_DEC_EXT(ss);
      break;
    case zx_protocolSupportEnumeration_ATTR:
      ss = ZX_ZALLOC(c, struct zx_str);
      ss->g.n = &x->protocolSupportEnumeration->g;
      x->protocolSupportEnumeration = ss;
      ZX_ATTR_DEC_EXT(ss);
      break;
    case zx_validUntil_ATTR:
      ss = ZX_ZALLOC(c, struct zx_str);
      ss->g.n = &x->validUntil->g;
      x->validUntil = ss;
      ZX_ATTR_DEC_EXT(ss);
      break;

    case ZX_TOK_XMLNS:
      ZX_XMLNS_DEC_EXT(name);
      DD("xmlns detected(%.*s)", data-2-name, name);
      ns = zx_new_ns(c, data-2-name, name, c->p - data, data);
      ns->n = x->gg.xmlns;
      x->gg.xmlns = ns;
      goto next_attr;
    default:
      ss = zx_dec_unknown_attr(c, &x->gg, name, data, tok, x->gg.g.tok);
    }
    ss->g.ns = ns;    /* Fill in the rest of the ss fields (its already linked to right list). */
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
	  zx_xml_parse_err_mismatching_close_tag(c, (const char*)__FUNCTION__, name, tok);
	  ZX_DEC_TAG_MISMATCH_CLOSE(x->gg.g);
	  return x;
	}
	/* Legitimate close tag. Normal exit from this function. */
	++c->p;
	ZX_DEC_TAG_NOW_CLOSED(x->gg.g);
	goto out;
      default:
	if (A_Z_a_z_(*c->p)) {
	  if (!(name = zx_scan_elem_start(c, (const char*)__FUNCTION__)))
	    return x;
	  pop_seen = zx_scan_xmlns(c);  /* Prescan namespaces so that token can be correctly recognized. */
	  tok = zx_elem_lookup(c, name, c->p, &ns);
	  switch (tok) {
          case zx_ds_Signature_ELEM:
            el = (struct zx_elem_s*)zx_DEC_ds_Signature(c, ns);
            el->g.n = &x->Signature->gg.g;
            x->Signature = (struct zx_ds_Signature_s*)el;
            break;
          case zx_md_Extensions_ELEM:
            el = (struct zx_elem_s*)zx_DEC_md_Extensions(c, ns);
            el->g.n = &x->Extensions->gg.g;
            x->Extensions = (struct zx_md_Extensions_s*)el;
            break;
          case zx_md_KeyDescriptor_ELEM:
            el = (struct zx_elem_s*)zx_DEC_md_KeyDescriptor(c, ns);
            el->g.n = &x->KeyDescriptor->gg.g;
            x->KeyDescriptor = (struct zx_md_KeyDescriptor_s*)el;
            break;
          case zx_md_Organization_ELEM:
            el = (struct zx_elem_s*)zx_DEC_md_Organization(c, ns);
            el->g.n = &x->Organization->gg.g;
            x->Organization = (struct zx_md_Organization_s*)el;
            break;
          case zx_md_ContactPerson_ELEM:
            el = (struct zx_elem_s*)zx_DEC_md_ContactPerson(c, ns);
            el->g.n = &x->ContactPerson->gg.g;
            x->ContactPerson = (struct zx_md_ContactPerson_s*)el;
            break;
          case zx_md_AuthnQueryService_ELEM:
            el = (struct zx_elem_s*)zx_DEC_md_AuthnQueryService(c, ns);
            el->g.n = &x->AuthnQueryService->gg.g;
            x->AuthnQueryService = (struct zx_md_AuthnQueryService_s*)el;
            break;
          case zx_md_AssertionIDRequestService_ELEM:
            el = (struct zx_elem_s*)zx_DEC_md_AssertionIDRequestService(c, ns);
            el->g.n = &x->AssertionIDRequestService->gg.g;
            x->AssertionIDRequestService = (struct zx_md_AssertionIDRequestService_s*)el;
            break;
          case zx_md_NameIDFormat_ELEM:
            el = zx_DEC_simple_elem(c, ns, tok);
            el->g.n = &x->NameIDFormat->g;
            x->NameIDFormat = el;
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
  zx_dec_reverse_lists(&x->gg);
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






/* FUNC(zx_DEC_md_AuthnQueryService) */

#define EL_NAME   md_AuthnQueryService
#define EL_STRUCT zx_md_AuthnQueryService_s
#define EL_NS     md
#define EL_TAG    AuthnQueryService

/* Called by: */
struct zx_md_AuthnQueryService_s* zx_DEC_md_AuthnQueryService(struct zx_ctx* c, struct zx_ns_s* ns )
{
  int tok;
  struct zx_elem_s* el;
  struct zx_str* ss;
  struct zx_ns_s* pop_seen;
  const char* name;
  const char* data;
  struct zx_md_AuthnQueryService_s* x = ZX_ZALLOC(c, struct zx_md_AuthnQueryService_s);
  x->gg.g.tok = zx_md_AuthnQueryService_ELEM;
  x->gg.g.ns = ns;
  ZX_START_DEC_EXT(x);

#if 1 /* NORMALMODE */
  ZX_DEC_TAG_NOT_YET_CLOSED(x->gg.g);

  /* The tag name has already been detected. Process attributes until '>' */
  
  for (; c->p; ++c->p) {
    ZX_SKIP_WS(c,x);
    if (ONE_OF_2(*c->p, '>', '/'))
      break;
    if (!(data = zx_dec_attr_val(c, &name, (const char*)__FUNCTION__)))
      return x;
    tok = zx_attr_lookup(c, name, data-2, &ns);
    switch (tok) {
    case zx_Binding_ATTR:
      ss = ZX_ZALLOC(c, struct zx_str);
      ss->g.n = &x->Binding->g;
      x->Binding = ss;
      ZX_ATTR_DEC_EXT(ss);
      break;
    case zx_Location_ATTR:
      ss = ZX_ZALLOC(c, struct zx_str);
      ss->g.n = &x->Location->g;
      x->Location = ss;
      ZX_ATTR_DEC_EXT(ss);
      break;
    case zx_ResponseLocation_ATTR:
      ss = ZX_ZALLOC(c, struct zx_str);
      ss->g.n = &x->ResponseLocation->g;
      x->ResponseLocation = ss;
      ZX_ATTR_DEC_EXT(ss);
      break;
    case zx_index_ATTR:
      ss = ZX_ZALLOC(c, struct zx_str);
      ss->g.n = &x->index->g;
      x->index = ss;
      ZX_ATTR_DEC_EXT(ss);
      break;
    case zx_isDefault_ATTR:
      ss = ZX_ZALLOC(c, struct zx_str);
      ss->g.n = &x->isDefault->g;
      x->isDefault = ss;
      ZX_ATTR_DEC_EXT(ss);
      break;

    case ZX_TOK_XMLNS:
      ZX_XMLNS_DEC_EXT(name);
      DD("xmlns detected(%.*s)", data-2-name, name);
      ns = zx_new_ns(c, data-2-name, name, c->p - data, data);
      ns->n = x->gg.xmlns;
      x->gg.xmlns = ns;
      goto next_attr;
    default:
      ss = zx_dec_unknown_attr(c, &x->gg, name, data, tok, x->gg.g.tok);
    }
    ss->g.ns = ns;    /* Fill in the rest of the ss fields (its already linked to right list). */
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
	  zx_xml_parse_err_mismatching_close_tag(c, (const char*)__FUNCTION__, name, tok);
	  ZX_DEC_TAG_MISMATCH_CLOSE(x->gg.g);
	  return x;
	}
	/* Legitimate close tag. Normal exit from this function. */
	++c->p;
	ZX_DEC_TAG_NOW_CLOSED(x->gg.g);
	goto out;
      default:
	if (A_Z_a_z_(*c->p)) {
	  if (!(name = zx_scan_elem_start(c, (const char*)__FUNCTION__)))
	    return x;
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
  zx_dec_reverse_lists(&x->gg);
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






/* FUNC(zx_DEC_md_AuthzService) */

#define EL_NAME   md_AuthzService
#define EL_STRUCT zx_md_AuthzService_s
#define EL_NS     md
#define EL_TAG    AuthzService

/* Called by: */
struct zx_md_AuthzService_s* zx_DEC_md_AuthzService(struct zx_ctx* c, struct zx_ns_s* ns )
{
  int tok;
  struct zx_elem_s* el;
  struct zx_str* ss;
  struct zx_ns_s* pop_seen;
  const char* name;
  const char* data;
  struct zx_md_AuthzService_s* x = ZX_ZALLOC(c, struct zx_md_AuthzService_s);
  x->gg.g.tok = zx_md_AuthzService_ELEM;
  x->gg.g.ns = ns;
  ZX_START_DEC_EXT(x);

#if 1 /* NORMALMODE */
  ZX_DEC_TAG_NOT_YET_CLOSED(x->gg.g);

  /* The tag name has already been detected. Process attributes until '>' */
  
  for (; c->p; ++c->p) {
    ZX_SKIP_WS(c,x);
    if (ONE_OF_2(*c->p, '>', '/'))
      break;
    if (!(data = zx_dec_attr_val(c, &name, (const char*)__FUNCTION__)))
      return x;
    tok = zx_attr_lookup(c, name, data-2, &ns);
    switch (tok) {
    case zx_Binding_ATTR:
      ss = ZX_ZALLOC(c, struct zx_str);
      ss->g.n = &x->Binding->g;
      x->Binding = ss;
      ZX_ATTR_DEC_EXT(ss);
      break;
    case zx_Location_ATTR:
      ss = ZX_ZALLOC(c, struct zx_str);
      ss->g.n = &x->Location->g;
      x->Location = ss;
      ZX_ATTR_DEC_EXT(ss);
      break;
    case zx_ResponseLocation_ATTR:
      ss = ZX_ZALLOC(c, struct zx_str);
      ss->g.n = &x->ResponseLocation->g;
      x->ResponseLocation = ss;
      ZX_ATTR_DEC_EXT(ss);
      break;
    case zx_index_ATTR:
      ss = ZX_ZALLOC(c, struct zx_str);
      ss->g.n = &x->index->g;
      x->index = ss;
      ZX_ATTR_DEC_EXT(ss);
      break;
    case zx_isDefault_ATTR:
      ss = ZX_ZALLOC(c, struct zx_str);
      ss->g.n = &x->isDefault->g;
      x->isDefault = ss;
      ZX_ATTR_DEC_EXT(ss);
      break;

    case ZX_TOK_XMLNS:
      ZX_XMLNS_DEC_EXT(name);
      DD("xmlns detected(%.*s)", data-2-name, name);
      ns = zx_new_ns(c, data-2-name, name, c->p - data, data);
      ns->n = x->gg.xmlns;
      x->gg.xmlns = ns;
      goto next_attr;
    default:
      ss = zx_dec_unknown_attr(c, &x->gg, name, data, tok, x->gg.g.tok);
    }
    ss->g.ns = ns;    /* Fill in the rest of the ss fields (its already linked to right list). */
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
	  zx_xml_parse_err_mismatching_close_tag(c, (const char*)__FUNCTION__, name, tok);
	  ZX_DEC_TAG_MISMATCH_CLOSE(x->gg.g);
	  return x;
	}
	/* Legitimate close tag. Normal exit from this function. */
	++c->p;
	ZX_DEC_TAG_NOW_CLOSED(x->gg.g);
	goto out;
      default:
	if (A_Z_a_z_(*c->p)) {
	  if (!(name = zx_scan_elem_start(c, (const char*)__FUNCTION__)))
	    return x;
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
  zx_dec_reverse_lists(&x->gg);
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






/* FUNC(zx_DEC_md_ContactPerson) */

#define EL_NAME   md_ContactPerson
#define EL_STRUCT zx_md_ContactPerson_s
#define EL_NS     md
#define EL_TAG    ContactPerson

/* Called by: */
struct zx_md_ContactPerson_s* zx_DEC_md_ContactPerson(struct zx_ctx* c, struct zx_ns_s* ns )
{
  int tok;
  struct zx_elem_s* el;
  struct zx_str* ss;
  struct zx_ns_s* pop_seen;
  const char* name;
  const char* data;
  struct zx_md_ContactPerson_s* x = ZX_ZALLOC(c, struct zx_md_ContactPerson_s);
  x->gg.g.tok = zx_md_ContactPerson_ELEM;
  x->gg.g.ns = ns;
  ZX_START_DEC_EXT(x);

#if 1 /* NORMALMODE */
  ZX_DEC_TAG_NOT_YET_CLOSED(x->gg.g);

  /* The tag name has already been detected. Process attributes until '>' */
  
  for (; c->p; ++c->p) {
    ZX_SKIP_WS(c,x);
    if (ONE_OF_2(*c->p, '>', '/'))
      break;
    if (!(data = zx_dec_attr_val(c, &name, (const char*)__FUNCTION__)))
      return x;
    tok = zx_attr_lookup(c, name, data-2, &ns);
    switch (tok) {
    case zx_contactType_ATTR:
      ss = ZX_ZALLOC(c, struct zx_str);
      ss->g.n = &x->contactType->g;
      x->contactType = ss;
      ZX_ATTR_DEC_EXT(ss);
      break;

    case ZX_TOK_XMLNS:
      ZX_XMLNS_DEC_EXT(name);
      DD("xmlns detected(%.*s)", data-2-name, name);
      ns = zx_new_ns(c, data-2-name, name, c->p - data, data);
      ns->n = x->gg.xmlns;
      x->gg.xmlns = ns;
      goto next_attr;
    default:
      ss = zx_dec_unknown_attr(c, &x->gg, name, data, tok, x->gg.g.tok);
    }
    ss->g.ns = ns;    /* Fill in the rest of the ss fields (its already linked to right list). */
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
	  zx_xml_parse_err_mismatching_close_tag(c, (const char*)__FUNCTION__, name, tok);
	  ZX_DEC_TAG_MISMATCH_CLOSE(x->gg.g);
	  return x;
	}
	/* Legitimate close tag. Normal exit from this function. */
	++c->p;
	ZX_DEC_TAG_NOW_CLOSED(x->gg.g);
	goto out;
      default:
	if (A_Z_a_z_(*c->p)) {
	  if (!(name = zx_scan_elem_start(c, (const char*)__FUNCTION__)))
	    return x;
	  pop_seen = zx_scan_xmlns(c);  /* Prescan namespaces so that token can be correctly recognized. */
	  tok = zx_elem_lookup(c, name, c->p, &ns);
	  switch (tok) {
          case zx_md_Extensions_ELEM:
            el = (struct zx_elem_s*)zx_DEC_md_Extensions(c, ns);
            el->g.n = &x->Extensions->gg.g;
            x->Extensions = (struct zx_md_Extensions_s*)el;
            break;
          case zx_md_Company_ELEM:
            el = zx_DEC_simple_elem(c, ns, tok);
            el->g.n = &x->Company->g;
            x->Company = el;
            break;
          case zx_md_GivenName_ELEM:
            el = zx_DEC_simple_elem(c, ns, tok);
            el->g.n = &x->GivenName->g;
            x->GivenName = el;
            break;
          case zx_md_SurName_ELEM:
            el = zx_DEC_simple_elem(c, ns, tok);
            el->g.n = &x->SurName->g;
            x->SurName = el;
            break;
          case zx_md_EmailAddress_ELEM:
            el = zx_DEC_simple_elem(c, ns, tok);
            el->g.n = &x->EmailAddress->g;
            x->EmailAddress = el;
            break;
          case zx_md_TelephoneNumber_ELEM:
            el = zx_DEC_simple_elem(c, ns, tok);
            el->g.n = &x->TelephoneNumber->g;
            x->TelephoneNumber = el;
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
  zx_dec_reverse_lists(&x->gg);
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






/* FUNC(zx_DEC_md_EncryptionMethod) */

#define EL_NAME   md_EncryptionMethod
#define EL_STRUCT zx_md_EncryptionMethod_s
#define EL_NS     md
#define EL_TAG    EncryptionMethod

/* Called by: */
struct zx_md_EncryptionMethod_s* zx_DEC_md_EncryptionMethod(struct zx_ctx* c, struct zx_ns_s* ns )
{
  int tok;
  struct zx_elem_s* el;
  struct zx_str* ss;
  struct zx_ns_s* pop_seen;
  const char* name;
  const char* data;
  struct zx_md_EncryptionMethod_s* x = ZX_ZALLOC(c, struct zx_md_EncryptionMethod_s);
  x->gg.g.tok = zx_md_EncryptionMethod_ELEM;
  x->gg.g.ns = ns;
  ZX_START_DEC_EXT(x);

#if 1 /* NORMALMODE */
  ZX_DEC_TAG_NOT_YET_CLOSED(x->gg.g);

  /* The tag name has already been detected. Process attributes until '>' */
  
  for (; c->p; ++c->p) {
    ZX_SKIP_WS(c,x);
    if (ONE_OF_2(*c->p, '>', '/'))
      break;
    if (!(data = zx_dec_attr_val(c, &name, (const char*)__FUNCTION__)))
      return x;
    tok = zx_attr_lookup(c, name, data-2, &ns);
    switch (tok) {
    case zx_Algorithm_ATTR:
      ss = ZX_ZALLOC(c, struct zx_str);
      ss->g.n = &x->Algorithm->g;
      x->Algorithm = ss;
      ZX_ATTR_DEC_EXT(ss);
      break;

    case ZX_TOK_XMLNS:
      ZX_XMLNS_DEC_EXT(name);
      DD("xmlns detected(%.*s)", data-2-name, name);
      ns = zx_new_ns(c, data-2-name, name, c->p - data, data);
      ns->n = x->gg.xmlns;
      x->gg.xmlns = ns;
      goto next_attr;
    default:
      ss = zx_dec_unknown_attr(c, &x->gg, name, data, tok, x->gg.g.tok);
    }
    ss->g.ns = ns;    /* Fill in the rest of the ss fields (its already linked to right list). */
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
	  zx_xml_parse_err_mismatching_close_tag(c, (const char*)__FUNCTION__, name, tok);
	  ZX_DEC_TAG_MISMATCH_CLOSE(x->gg.g);
	  return x;
	}
	/* Legitimate close tag. Normal exit from this function. */
	++c->p;
	ZX_DEC_TAG_NOW_CLOSED(x->gg.g);
	goto out;
      default:
	if (A_Z_a_z_(*c->p)) {
	  if (!(name = zx_scan_elem_start(c, (const char*)__FUNCTION__)))
	    return x;
	  pop_seen = zx_scan_xmlns(c);  /* Prescan namespaces so that token can be correctly recognized. */
	  tok = zx_elem_lookup(c, name, c->p, &ns);
	  switch (tok) {
          case zx_xenc_KeySize_ELEM:
            el = zx_DEC_simple_elem(c, ns, tok);
            el->g.n = &x->KeySize->g;
            x->KeySize = el;
            break;
          case zx_xenc_OAEPparams_ELEM:
            el = zx_DEC_simple_elem(c, ns, tok);
            el->g.n = &x->OAEPparams->g;
            x->OAEPparams = el;
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
  zx_dec_reverse_lists(&x->gg);
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






/* FUNC(zx_DEC_md_EntitiesDescriptor) */

#define EL_NAME   md_EntitiesDescriptor
#define EL_STRUCT zx_md_EntitiesDescriptor_s
#define EL_NS     md
#define EL_TAG    EntitiesDescriptor

/* Called by: */
struct zx_md_EntitiesDescriptor_s* zx_DEC_md_EntitiesDescriptor(struct zx_ctx* c, struct zx_ns_s* ns )
{
  int tok;
  struct zx_elem_s* el;
  struct zx_str* ss;
  struct zx_ns_s* pop_seen;
  const char* name;
  const char* data;
  struct zx_md_EntitiesDescriptor_s* x = ZX_ZALLOC(c, struct zx_md_EntitiesDescriptor_s);
  x->gg.g.tok = zx_md_EntitiesDescriptor_ELEM;
  x->gg.g.ns = ns;
  ZX_START_DEC_EXT(x);

#if 1 /* NORMALMODE */
  ZX_DEC_TAG_NOT_YET_CLOSED(x->gg.g);

  /* The tag name has already been detected. Process attributes until '>' */
  
  for (; c->p; ++c->p) {
    ZX_SKIP_WS(c,x);
    if (ONE_OF_2(*c->p, '>', '/'))
      break;
    if (!(data = zx_dec_attr_val(c, &name, (const char*)__FUNCTION__)))
      return x;
    tok = zx_attr_lookup(c, name, data-2, &ns);
    switch (tok) {
    case zx_ID_ATTR:
      ss = ZX_ZALLOC(c, struct zx_str);
      ss->g.n = &x->ID->g;
      x->ID = ss;
      ZX_ATTR_DEC_EXT(ss);
      break;
    case zx_Name_ATTR:
      ss = ZX_ZALLOC(c, struct zx_str);
      ss->g.n = &x->Name->g;
      x->Name = ss;
      ZX_ATTR_DEC_EXT(ss);
      break;
    case zx_cacheDuration_ATTR:
      ss = ZX_ZALLOC(c, struct zx_str);
      ss->g.n = &x->cacheDuration->g;
      x->cacheDuration = ss;
      ZX_ATTR_DEC_EXT(ss);
      break;
    case zx_validUntil_ATTR:
      ss = ZX_ZALLOC(c, struct zx_str);
      ss->g.n = &x->validUntil->g;
      x->validUntil = ss;
      ZX_ATTR_DEC_EXT(ss);
      break;

    case ZX_TOK_XMLNS:
      ZX_XMLNS_DEC_EXT(name);
      DD("xmlns detected(%.*s)", data-2-name, name);
      ns = zx_new_ns(c, data-2-name, name, c->p - data, data);
      ns->n = x->gg.xmlns;
      x->gg.xmlns = ns;
      goto next_attr;
    default:
      ss = zx_dec_unknown_attr(c, &x->gg, name, data, tok, x->gg.g.tok);
    }
    ss->g.ns = ns;    /* Fill in the rest of the ss fields (its already linked to right list). */
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
	  zx_xml_parse_err_mismatching_close_tag(c, (const char*)__FUNCTION__, name, tok);
	  ZX_DEC_TAG_MISMATCH_CLOSE(x->gg.g);
	  return x;
	}
	/* Legitimate close tag. Normal exit from this function. */
	++c->p;
	ZX_DEC_TAG_NOW_CLOSED(x->gg.g);
	goto out;
      default:
	if (A_Z_a_z_(*c->p)) {
	  if (!(name = zx_scan_elem_start(c, (const char*)__FUNCTION__)))
	    return x;
	  pop_seen = zx_scan_xmlns(c);  /* Prescan namespaces so that token can be correctly recognized. */
	  tok = zx_elem_lookup(c, name, c->p, &ns);
	  switch (tok) {
          case zx_ds_Signature_ELEM:
            el = (struct zx_elem_s*)zx_DEC_ds_Signature(c, ns);
            el->g.n = &x->Signature->gg.g;
            x->Signature = (struct zx_ds_Signature_s*)el;
            break;
          case zx_md_Extensions_ELEM:
            el = (struct zx_elem_s*)zx_DEC_md_Extensions(c, ns);
            el->g.n = &x->Extensions->gg.g;
            x->Extensions = (struct zx_md_Extensions_s*)el;
            break;
          case zx_md_EntityDescriptor_ELEM:
            el = (struct zx_elem_s*)zx_DEC_md_EntityDescriptor(c, ns);
            el->g.n = &x->EntityDescriptor->gg.g;
            x->EntityDescriptor = (struct zx_md_EntityDescriptor_s*)el;
            break;
          case zx_md_EntitiesDescriptor_ELEM:
            el = (struct zx_elem_s*)zx_DEC_md_EntitiesDescriptor(c, ns);
            el->g.n = &x->EntitiesDescriptor->gg.g;
            x->EntitiesDescriptor = (struct zx_md_EntitiesDescriptor_s*)el;
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
  zx_dec_reverse_lists(&x->gg);
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






/* FUNC(zx_DEC_md_EntityDescriptor) */

#define EL_NAME   md_EntityDescriptor
#define EL_STRUCT zx_md_EntityDescriptor_s
#define EL_NS     md
#define EL_TAG    EntityDescriptor

/* Called by: */
struct zx_md_EntityDescriptor_s* zx_DEC_md_EntityDescriptor(struct zx_ctx* c, struct zx_ns_s* ns )
{
  int tok;
  struct zx_elem_s* el;
  struct zx_str* ss;
  struct zx_ns_s* pop_seen;
  const char* name;
  const char* data;
  struct zx_md_EntityDescriptor_s* x = ZX_ZALLOC(c, struct zx_md_EntityDescriptor_s);
  x->gg.g.tok = zx_md_EntityDescriptor_ELEM;
  x->gg.g.ns = ns;
  ZX_START_DEC_EXT(x);

#if 1 /* NORMALMODE */
  ZX_DEC_TAG_NOT_YET_CLOSED(x->gg.g);

  /* The tag name has already been detected. Process attributes until '>' */
  
  for (; c->p; ++c->p) {
    ZX_SKIP_WS(c,x);
    if (ONE_OF_2(*c->p, '>', '/'))
      break;
    if (!(data = zx_dec_attr_val(c, &name, (const char*)__FUNCTION__)))
      return x;
    tok = zx_attr_lookup(c, name, data-2, &ns);
    switch (tok) {
    case zx_ID_ATTR:
      ss = ZX_ZALLOC(c, struct zx_str);
      ss->g.n = &x->ID->g;
      x->ID = ss;
      ZX_ATTR_DEC_EXT(ss);
      break;
    case zx_cacheDuration_ATTR:
      ss = ZX_ZALLOC(c, struct zx_str);
      ss->g.n = &x->cacheDuration->g;
      x->cacheDuration = ss;
      ZX_ATTR_DEC_EXT(ss);
      break;
    case zx_entityID_ATTR:
      ss = ZX_ZALLOC(c, struct zx_str);
      ss->g.n = &x->entityID->g;
      x->entityID = ss;
      ZX_ATTR_DEC_EXT(ss);
      break;
    case zx_validUntil_ATTR:
      ss = ZX_ZALLOC(c, struct zx_str);
      ss->g.n = &x->validUntil->g;
      x->validUntil = ss;
      ZX_ATTR_DEC_EXT(ss);
      break;

    case ZX_TOK_XMLNS:
      ZX_XMLNS_DEC_EXT(name);
      DD("xmlns detected(%.*s)", data-2-name, name);
      ns = zx_new_ns(c, data-2-name, name, c->p - data, data);
      ns->n = x->gg.xmlns;
      x->gg.xmlns = ns;
      goto next_attr;
    default:
      ss = zx_dec_unknown_attr(c, &x->gg, name, data, tok, x->gg.g.tok);
    }
    ss->g.ns = ns;    /* Fill in the rest of the ss fields (its already linked to right list). */
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
	  zx_xml_parse_err_mismatching_close_tag(c, (const char*)__FUNCTION__, name, tok);
	  ZX_DEC_TAG_MISMATCH_CLOSE(x->gg.g);
	  return x;
	}
	/* Legitimate close tag. Normal exit from this function. */
	++c->p;
	ZX_DEC_TAG_NOW_CLOSED(x->gg.g);
	goto out;
      default:
	if (A_Z_a_z_(*c->p)) {
	  if (!(name = zx_scan_elem_start(c, (const char*)__FUNCTION__)))
	    return x;
	  pop_seen = zx_scan_xmlns(c);  /* Prescan namespaces so that token can be correctly recognized. */
	  tok = zx_elem_lookup(c, name, c->p, &ns);
	  switch (tok) {
          case zx_ds_Signature_ELEM:
            el = (struct zx_elem_s*)zx_DEC_ds_Signature(c, ns);
            el->g.n = &x->Signature->gg.g;
            x->Signature = (struct zx_ds_Signature_s*)el;
            break;
          case zx_md_Extensions_ELEM:
            el = (struct zx_elem_s*)zx_DEC_md_Extensions(c, ns);
            el->g.n = &x->Extensions->gg.g;
            x->Extensions = (struct zx_md_Extensions_s*)el;
            break;
          case zx_md_RoleDescriptor_ELEM:
            el = (struct zx_elem_s*)zx_DEC_md_RoleDescriptor(c, ns);
            el->g.n = &x->RoleDescriptor->gg.g;
            x->RoleDescriptor = (struct zx_md_RoleDescriptor_s*)el;
            break;
          case zx_md_IDPSSODescriptor_ELEM:
            el = (struct zx_elem_s*)zx_DEC_md_IDPSSODescriptor(c, ns);
            el->g.n = &x->IDPSSODescriptor->gg.g;
            x->IDPSSODescriptor = (struct zx_md_IDPSSODescriptor_s*)el;
            break;
          case zx_md_SPSSODescriptor_ELEM:
            el = (struct zx_elem_s*)zx_DEC_md_SPSSODescriptor(c, ns);
            el->g.n = &x->SPSSODescriptor->gg.g;
            x->SPSSODescriptor = (struct zx_md_SPSSODescriptor_s*)el;
            break;
          case zx_md_AuthnAuthorityDescriptor_ELEM:
            el = (struct zx_elem_s*)zx_DEC_md_AuthnAuthorityDescriptor(c, ns);
            el->g.n = &x->AuthnAuthorityDescriptor->gg.g;
            x->AuthnAuthorityDescriptor = (struct zx_md_AuthnAuthorityDescriptor_s*)el;
            break;
          case zx_md_AttributeAuthorityDescriptor_ELEM:
            el = (struct zx_elem_s*)zx_DEC_md_AttributeAuthorityDescriptor(c, ns);
            el->g.n = &x->AttributeAuthorityDescriptor->gg.g;
            x->AttributeAuthorityDescriptor = (struct zx_md_AttributeAuthorityDescriptor_s*)el;
            break;
          case zx_md_PDPDescriptor_ELEM:
            el = (struct zx_elem_s*)zx_DEC_md_PDPDescriptor(c, ns);
            el->g.n = &x->PDPDescriptor->gg.g;
            x->PDPDescriptor = (struct zx_md_PDPDescriptor_s*)el;
            break;
          case zx_md_AffiliationDescriptor_ELEM:
            el = (struct zx_elem_s*)zx_DEC_md_AffiliationDescriptor(c, ns);
            el->g.n = &x->AffiliationDescriptor->gg.g;
            x->AffiliationDescriptor = (struct zx_md_AffiliationDescriptor_s*)el;
            break;
          case zx_md_Organization_ELEM:
            el = (struct zx_elem_s*)zx_DEC_md_Organization(c, ns);
            el->g.n = &x->Organization->gg.g;
            x->Organization = (struct zx_md_Organization_s*)el;
            break;
          case zx_md_ContactPerson_ELEM:
            el = (struct zx_elem_s*)zx_DEC_md_ContactPerson(c, ns);
            el->g.n = &x->ContactPerson->gg.g;
            x->ContactPerson = (struct zx_md_ContactPerson_s*)el;
            break;
          case zx_md_AdditionalMetadataLocation_ELEM:
            el = (struct zx_elem_s*)zx_DEC_md_AdditionalMetadataLocation(c, ns);
            el->g.n = &x->AdditionalMetadataLocation->gg.g;
            x->AdditionalMetadataLocation = (struct zx_md_AdditionalMetadataLocation_s*)el;
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
  zx_dec_reverse_lists(&x->gg);
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






/* FUNC(zx_DEC_md_Extensions) */

#define EL_NAME   md_Extensions
#define EL_STRUCT zx_md_Extensions_s
#define EL_NS     md
#define EL_TAG    Extensions

/* Called by: */
struct zx_md_Extensions_s* zx_DEC_md_Extensions(struct zx_ctx* c, struct zx_ns_s* ns )
{
  int tok;
  struct zx_elem_s* el;
  struct zx_str* ss;
  struct zx_ns_s* pop_seen;
  const char* name;
  const char* data;
  struct zx_md_Extensions_s* x = ZX_ZALLOC(c, struct zx_md_Extensions_s);
  x->gg.g.tok = zx_md_Extensions_ELEM;
  x->gg.g.ns = ns;
  ZX_START_DEC_EXT(x);

#if 1 /* NORMALMODE */
  ZX_DEC_TAG_NOT_YET_CLOSED(x->gg.g);

  /* The tag name has already been detected. Process attributes until '>' */
  
  for (; c->p; ++c->p) {
    ZX_SKIP_WS(c,x);
    if (ONE_OF_2(*c->p, '>', '/'))
      break;
    if (!(data = zx_dec_attr_val(c, &name, (const char*)__FUNCTION__)))
      return x;
    tok = zx_attr_lookup(c, name, data-2, &ns);
    switch (tok) {

    case ZX_TOK_XMLNS:
      ZX_XMLNS_DEC_EXT(name);
      DD("xmlns detected(%.*s)", data-2-name, name);
      ns = zx_new_ns(c, data-2-name, name, c->p - data, data);
      ns->n = x->gg.xmlns;
      x->gg.xmlns = ns;
      goto next_attr;
    default:
      ss = zx_dec_unknown_attr(c, &x->gg, name, data, tok, x->gg.g.tok);
    }
    ss->g.ns = ns;    /* Fill in the rest of the ss fields (its already linked to right list). */
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
	  zx_xml_parse_err_mismatching_close_tag(c, (const char*)__FUNCTION__, name, tok);
	  ZX_DEC_TAG_MISMATCH_CLOSE(x->gg.g);
	  return x;
	}
	/* Legitimate close tag. Normal exit from this function. */
	++c->p;
	ZX_DEC_TAG_NOW_CLOSED(x->gg.g);
	goto out;
      default:
	if (A_Z_a_z_(*c->p)) {
	  if (!(name = zx_scan_elem_start(c, (const char*)__FUNCTION__)))
	    return x;
	  pop_seen = zx_scan_xmlns(c);  /* Prescan namespaces so that token can be correctly recognized. */
	  tok = zx_elem_lookup(c, name, c->p, &ns);
	  switch (tok) {
          case zx_shibmd_Scope_ELEM:
            el = (struct zx_elem_s*)zx_DEC_shibmd_Scope(c, ns);
            el->g.n = &x->Scope->gg.g;
            x->Scope = (struct zx_shibmd_Scope_s*)el;
            break;
          case zx_shibmd_KeyAuthority_ELEM:
            el = (struct zx_elem_s*)zx_DEC_shibmd_KeyAuthority(c, ns);
            el->g.n = &x->KeyAuthority->gg.g;
            x->KeyAuthority = (struct zx_shibmd_KeyAuthority_s*)el;
            break;
          case zx_idpdisc_DiscoveryResponse_ELEM:
            el = (struct zx_elem_s*)zx_DEC_idpdisc_DiscoveryResponse(c, ns);
            el->g.n = &x->DiscoveryResponse->gg.g;
            x->DiscoveryResponse = (struct zx_idpdisc_DiscoveryResponse_s*)el;
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
  zx_dec_reverse_lists(&x->gg);
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






/* FUNC(zx_DEC_md_IDPSSODescriptor) */

#define EL_NAME   md_IDPSSODescriptor
#define EL_STRUCT zx_md_IDPSSODescriptor_s
#define EL_NS     md
#define EL_TAG    IDPSSODescriptor

/* Called by: */
struct zx_md_IDPSSODescriptor_s* zx_DEC_md_IDPSSODescriptor(struct zx_ctx* c, struct zx_ns_s* ns )
{
  int tok;
  struct zx_elem_s* el;
  struct zx_str* ss;
  struct zx_ns_s* pop_seen;
  const char* name;
  const char* data;
  struct zx_md_IDPSSODescriptor_s* x = ZX_ZALLOC(c, struct zx_md_IDPSSODescriptor_s);
  x->gg.g.tok = zx_md_IDPSSODescriptor_ELEM;
  x->gg.g.ns = ns;
  ZX_START_DEC_EXT(x);

#if 1 /* NORMALMODE */
  ZX_DEC_TAG_NOT_YET_CLOSED(x->gg.g);

  /* The tag name has already been detected. Process attributes until '>' */
  
  for (; c->p; ++c->p) {
    ZX_SKIP_WS(c,x);
    if (ONE_OF_2(*c->p, '>', '/'))
      break;
    if (!(data = zx_dec_attr_val(c, &name, (const char*)__FUNCTION__)))
      return x;
    tok = zx_attr_lookup(c, name, data-2, &ns);
    switch (tok) {
    case zx_ID_ATTR:
      ss = ZX_ZALLOC(c, struct zx_str);
      ss->g.n = &x->ID->g;
      x->ID = ss;
      ZX_ATTR_DEC_EXT(ss);
      break;
    case zx_WantAuthnRequestsSigned_ATTR:
      ss = ZX_ZALLOC(c, struct zx_str);
      ss->g.n = &x->WantAuthnRequestsSigned->g;
      x->WantAuthnRequestsSigned = ss;
      ZX_ATTR_DEC_EXT(ss);
      break;
    case zx_cacheDuration_ATTR:
      ss = ZX_ZALLOC(c, struct zx_str);
      ss->g.n = &x->cacheDuration->g;
      x->cacheDuration = ss;
      ZX_ATTR_DEC_EXT(ss);
      break;
    case zx_errorURL_ATTR:
      ss = ZX_ZALLOC(c, struct zx_str);
      ss->g.n = &x->errorURL->g;
      x->errorURL = ss;
      ZX_ATTR_DEC_EXT(ss);
      break;
    case zx_protocolSupportEnumeration_ATTR:
      ss = ZX_ZALLOC(c, struct zx_str);
      ss->g.n = &x->protocolSupportEnumeration->g;
      x->protocolSupportEnumeration = ss;
      ZX_ATTR_DEC_EXT(ss);
      break;
    case zx_validUntil_ATTR:
      ss = ZX_ZALLOC(c, struct zx_str);
      ss->g.n = &x->validUntil->g;
      x->validUntil = ss;
      ZX_ATTR_DEC_EXT(ss);
      break;

    case ZX_TOK_XMLNS:
      ZX_XMLNS_DEC_EXT(name);
      DD("xmlns detected(%.*s)", data-2-name, name);
      ns = zx_new_ns(c, data-2-name, name, c->p - data, data);
      ns->n = x->gg.xmlns;
      x->gg.xmlns = ns;
      goto next_attr;
    default:
      ss = zx_dec_unknown_attr(c, &x->gg, name, data, tok, x->gg.g.tok);
    }
    ss->g.ns = ns;    /* Fill in the rest of the ss fields (its already linked to right list). */
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
	  zx_xml_parse_err_mismatching_close_tag(c, (const char*)__FUNCTION__, name, tok);
	  ZX_DEC_TAG_MISMATCH_CLOSE(x->gg.g);
	  return x;
	}
	/* Legitimate close tag. Normal exit from this function. */
	++c->p;
	ZX_DEC_TAG_NOW_CLOSED(x->gg.g);
	goto out;
      default:
	if (A_Z_a_z_(*c->p)) {
	  if (!(name = zx_scan_elem_start(c, (const char*)__FUNCTION__)))
	    return x;
	  pop_seen = zx_scan_xmlns(c);  /* Prescan namespaces so that token can be correctly recognized. */
	  tok = zx_elem_lookup(c, name, c->p, &ns);
	  switch (tok) {
          case zx_ds_Signature_ELEM:
            el = (struct zx_elem_s*)zx_DEC_ds_Signature(c, ns);
            el->g.n = &x->Signature->gg.g;
            x->Signature = (struct zx_ds_Signature_s*)el;
            break;
          case zx_md_Extensions_ELEM:
            el = (struct zx_elem_s*)zx_DEC_md_Extensions(c, ns);
            el->g.n = &x->Extensions->gg.g;
            x->Extensions = (struct zx_md_Extensions_s*)el;
            break;
          case zx_md_KeyDescriptor_ELEM:
            el = (struct zx_elem_s*)zx_DEC_md_KeyDescriptor(c, ns);
            el->g.n = &x->KeyDescriptor->gg.g;
            x->KeyDescriptor = (struct zx_md_KeyDescriptor_s*)el;
            break;
          case zx_md_Organization_ELEM:
            el = (struct zx_elem_s*)zx_DEC_md_Organization(c, ns);
            el->g.n = &x->Organization->gg.g;
            x->Organization = (struct zx_md_Organization_s*)el;
            break;
          case zx_md_ContactPerson_ELEM:
            el = (struct zx_elem_s*)zx_DEC_md_ContactPerson(c, ns);
            el->g.n = &x->ContactPerson->gg.g;
            x->ContactPerson = (struct zx_md_ContactPerson_s*)el;
            break;
          case zx_md_ArtifactResolutionService_ELEM:
            el = (struct zx_elem_s*)zx_DEC_md_ArtifactResolutionService(c, ns);
            el->g.n = &x->ArtifactResolutionService->gg.g;
            x->ArtifactResolutionService = (struct zx_md_ArtifactResolutionService_s*)el;
            break;
          case zx_md_SingleLogoutService_ELEM:
            el = (struct zx_elem_s*)zx_DEC_md_SingleLogoutService(c, ns);
            el->g.n = &x->SingleLogoutService->gg.g;
            x->SingleLogoutService = (struct zx_md_SingleLogoutService_s*)el;
            break;
          case zx_md_ManageNameIDService_ELEM:
            el = (struct zx_elem_s*)zx_DEC_md_ManageNameIDService(c, ns);
            el->g.n = &x->ManageNameIDService->gg.g;
            x->ManageNameIDService = (struct zx_md_ManageNameIDService_s*)el;
            break;
          case zx_md_NameIDFormat_ELEM:
            el = zx_DEC_simple_elem(c, ns, tok);
            el->g.n = &x->NameIDFormat->g;
            x->NameIDFormat = el;
            break;
          case zx_md_SingleSignOnService_ELEM:
            el = (struct zx_elem_s*)zx_DEC_md_SingleSignOnService(c, ns);
            el->g.n = &x->SingleSignOnService->gg.g;
            x->SingleSignOnService = (struct zx_md_SingleSignOnService_s*)el;
            break;
          case zx_md_NameIDMappingService_ELEM:
            el = (struct zx_elem_s*)zx_DEC_md_NameIDMappingService(c, ns);
            el->g.n = &x->NameIDMappingService->gg.g;
            x->NameIDMappingService = (struct zx_md_NameIDMappingService_s*)el;
            break;
          case zx_md_AssertionIDRequestService_ELEM:
            el = (struct zx_elem_s*)zx_DEC_md_AssertionIDRequestService(c, ns);
            el->g.n = &x->AssertionIDRequestService->gg.g;
            x->AssertionIDRequestService = (struct zx_md_AssertionIDRequestService_s*)el;
            break;
          case zx_md_AttributeProfile_ELEM:
            el = zx_DEC_simple_elem(c, ns, tok);
            el->g.n = &x->AttributeProfile->g;
            x->AttributeProfile = el;
            break;
          case zx_sa_Attribute_ELEM:
            el = (struct zx_elem_s*)zx_DEC_sa_Attribute(c, ns);
            el->g.n = &x->Attribute->gg.g;
            x->Attribute = (struct zx_sa_Attribute_s*)el;
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
  zx_dec_reverse_lists(&x->gg);
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






/* FUNC(zx_DEC_md_KeyDescriptor) */

#define EL_NAME   md_KeyDescriptor
#define EL_STRUCT zx_md_KeyDescriptor_s
#define EL_NS     md
#define EL_TAG    KeyDescriptor

/* Called by: */
struct zx_md_KeyDescriptor_s* zx_DEC_md_KeyDescriptor(struct zx_ctx* c, struct zx_ns_s* ns )
{
  int tok;
  struct zx_elem_s* el;
  struct zx_str* ss;
  struct zx_ns_s* pop_seen;
  const char* name;
  const char* data;
  struct zx_md_KeyDescriptor_s* x = ZX_ZALLOC(c, struct zx_md_KeyDescriptor_s);
  x->gg.g.tok = zx_md_KeyDescriptor_ELEM;
  x->gg.g.ns = ns;
  ZX_START_DEC_EXT(x);

#if 1 /* NORMALMODE */
  ZX_DEC_TAG_NOT_YET_CLOSED(x->gg.g);

  /* The tag name has already been detected. Process attributes until '>' */
  
  for (; c->p; ++c->p) {
    ZX_SKIP_WS(c,x);
    if (ONE_OF_2(*c->p, '>', '/'))
      break;
    if (!(data = zx_dec_attr_val(c, &name, (const char*)__FUNCTION__)))
      return x;
    tok = zx_attr_lookup(c, name, data-2, &ns);
    switch (tok) {
    case zx_use_ATTR:
      ss = ZX_ZALLOC(c, struct zx_str);
      ss->g.n = &x->use->g;
      x->use = ss;
      ZX_ATTR_DEC_EXT(ss);
      break;

    case ZX_TOK_XMLNS:
      ZX_XMLNS_DEC_EXT(name);
      DD("xmlns detected(%.*s)", data-2-name, name);
      ns = zx_new_ns(c, data-2-name, name, c->p - data, data);
      ns->n = x->gg.xmlns;
      x->gg.xmlns = ns;
      goto next_attr;
    default:
      ss = zx_dec_unknown_attr(c, &x->gg, name, data, tok, x->gg.g.tok);
    }
    ss->g.ns = ns;    /* Fill in the rest of the ss fields (its already linked to right list). */
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
	  zx_xml_parse_err_mismatching_close_tag(c, (const char*)__FUNCTION__, name, tok);
	  ZX_DEC_TAG_MISMATCH_CLOSE(x->gg.g);
	  return x;
	}
	/* Legitimate close tag. Normal exit from this function. */
	++c->p;
	ZX_DEC_TAG_NOW_CLOSED(x->gg.g);
	goto out;
      default:
	if (A_Z_a_z_(*c->p)) {
	  if (!(name = zx_scan_elem_start(c, (const char*)__FUNCTION__)))
	    return x;
	  pop_seen = zx_scan_xmlns(c);  /* Prescan namespaces so that token can be correctly recognized. */
	  tok = zx_elem_lookup(c, name, c->p, &ns);
	  switch (tok) {
          case zx_ds_KeyInfo_ELEM:
            el = (struct zx_elem_s*)zx_DEC_ds_KeyInfo(c, ns);
            el->g.n = &x->KeyInfo->gg.g;
            x->KeyInfo = (struct zx_ds_KeyInfo_s*)el;
            break;
          case zx_md_EncryptionMethod_ELEM:
            el = (struct zx_elem_s*)zx_DEC_md_EncryptionMethod(c, ns);
            el->g.n = &x->EncryptionMethod->gg.g;
            x->EncryptionMethod = (struct zx_md_EncryptionMethod_s*)el;
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
  zx_dec_reverse_lists(&x->gg);
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






/* FUNC(zx_DEC_md_ManageNameIDService) */

#define EL_NAME   md_ManageNameIDService
#define EL_STRUCT zx_md_ManageNameIDService_s
#define EL_NS     md
#define EL_TAG    ManageNameIDService

/* Called by: */
struct zx_md_ManageNameIDService_s* zx_DEC_md_ManageNameIDService(struct zx_ctx* c, struct zx_ns_s* ns )
{
  int tok;
  struct zx_elem_s* el;
  struct zx_str* ss;
  struct zx_ns_s* pop_seen;
  const char* name;
  const char* data;
  struct zx_md_ManageNameIDService_s* x = ZX_ZALLOC(c, struct zx_md_ManageNameIDService_s);
  x->gg.g.tok = zx_md_ManageNameIDService_ELEM;
  x->gg.g.ns = ns;
  ZX_START_DEC_EXT(x);

#if 1 /* NORMALMODE */
  ZX_DEC_TAG_NOT_YET_CLOSED(x->gg.g);

  /* The tag name has already been detected. Process attributes until '>' */
  
  for (; c->p; ++c->p) {
    ZX_SKIP_WS(c,x);
    if (ONE_OF_2(*c->p, '>', '/'))
      break;
    if (!(data = zx_dec_attr_val(c, &name, (const char*)__FUNCTION__)))
      return x;
    tok = zx_attr_lookup(c, name, data-2, &ns);
    switch (tok) {
    case zx_Binding_ATTR:
      ss = ZX_ZALLOC(c, struct zx_str);
      ss->g.n = &x->Binding->g;
      x->Binding = ss;
      ZX_ATTR_DEC_EXT(ss);
      break;
    case zx_Location_ATTR:
      ss = ZX_ZALLOC(c, struct zx_str);
      ss->g.n = &x->Location->g;
      x->Location = ss;
      ZX_ATTR_DEC_EXT(ss);
      break;
    case zx_ResponseLocation_ATTR:
      ss = ZX_ZALLOC(c, struct zx_str);
      ss->g.n = &x->ResponseLocation->g;
      x->ResponseLocation = ss;
      ZX_ATTR_DEC_EXT(ss);
      break;
    case zx_index_ATTR:
      ss = ZX_ZALLOC(c, struct zx_str);
      ss->g.n = &x->index->g;
      x->index = ss;
      ZX_ATTR_DEC_EXT(ss);
      break;
    case zx_isDefault_ATTR:
      ss = ZX_ZALLOC(c, struct zx_str);
      ss->g.n = &x->isDefault->g;
      x->isDefault = ss;
      ZX_ATTR_DEC_EXT(ss);
      break;

    case ZX_TOK_XMLNS:
      ZX_XMLNS_DEC_EXT(name);
      DD("xmlns detected(%.*s)", data-2-name, name);
      ns = zx_new_ns(c, data-2-name, name, c->p - data, data);
      ns->n = x->gg.xmlns;
      x->gg.xmlns = ns;
      goto next_attr;
    default:
      ss = zx_dec_unknown_attr(c, &x->gg, name, data, tok, x->gg.g.tok);
    }
    ss->g.ns = ns;    /* Fill in the rest of the ss fields (its already linked to right list). */
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
	  zx_xml_parse_err_mismatching_close_tag(c, (const char*)__FUNCTION__, name, tok);
	  ZX_DEC_TAG_MISMATCH_CLOSE(x->gg.g);
	  return x;
	}
	/* Legitimate close tag. Normal exit from this function. */
	++c->p;
	ZX_DEC_TAG_NOW_CLOSED(x->gg.g);
	goto out;
      default:
	if (A_Z_a_z_(*c->p)) {
	  if (!(name = zx_scan_elem_start(c, (const char*)__FUNCTION__)))
	    return x;
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
  zx_dec_reverse_lists(&x->gg);
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






/* FUNC(zx_DEC_md_NameIDMappingService) */

#define EL_NAME   md_NameIDMappingService
#define EL_STRUCT zx_md_NameIDMappingService_s
#define EL_NS     md
#define EL_TAG    NameIDMappingService

/* Called by: */
struct zx_md_NameIDMappingService_s* zx_DEC_md_NameIDMappingService(struct zx_ctx* c, struct zx_ns_s* ns )
{
  int tok;
  struct zx_elem_s* el;
  struct zx_str* ss;
  struct zx_ns_s* pop_seen;
  const char* name;
  const char* data;
  struct zx_md_NameIDMappingService_s* x = ZX_ZALLOC(c, struct zx_md_NameIDMappingService_s);
  x->gg.g.tok = zx_md_NameIDMappingService_ELEM;
  x->gg.g.ns = ns;
  ZX_START_DEC_EXT(x);

#if 1 /* NORMALMODE */
  ZX_DEC_TAG_NOT_YET_CLOSED(x->gg.g);

  /* The tag name has already been detected. Process attributes until '>' */
  
  for (; c->p; ++c->p) {
    ZX_SKIP_WS(c,x);
    if (ONE_OF_2(*c->p, '>', '/'))
      break;
    if (!(data = zx_dec_attr_val(c, &name, (const char*)__FUNCTION__)))
      return x;
    tok = zx_attr_lookup(c, name, data-2, &ns);
    switch (tok) {
    case zx_Binding_ATTR:
      ss = ZX_ZALLOC(c, struct zx_str);
      ss->g.n = &x->Binding->g;
      x->Binding = ss;
      ZX_ATTR_DEC_EXT(ss);
      break;
    case zx_Location_ATTR:
      ss = ZX_ZALLOC(c, struct zx_str);
      ss->g.n = &x->Location->g;
      x->Location = ss;
      ZX_ATTR_DEC_EXT(ss);
      break;
    case zx_ResponseLocation_ATTR:
      ss = ZX_ZALLOC(c, struct zx_str);
      ss->g.n = &x->ResponseLocation->g;
      x->ResponseLocation = ss;
      ZX_ATTR_DEC_EXT(ss);
      break;
    case zx_index_ATTR:
      ss = ZX_ZALLOC(c, struct zx_str);
      ss->g.n = &x->index->g;
      x->index = ss;
      ZX_ATTR_DEC_EXT(ss);
      break;
    case zx_isDefault_ATTR:
      ss = ZX_ZALLOC(c, struct zx_str);
      ss->g.n = &x->isDefault->g;
      x->isDefault = ss;
      ZX_ATTR_DEC_EXT(ss);
      break;

    case ZX_TOK_XMLNS:
      ZX_XMLNS_DEC_EXT(name);
      DD("xmlns detected(%.*s)", data-2-name, name);
      ns = zx_new_ns(c, data-2-name, name, c->p - data, data);
      ns->n = x->gg.xmlns;
      x->gg.xmlns = ns;
      goto next_attr;
    default:
      ss = zx_dec_unknown_attr(c, &x->gg, name, data, tok, x->gg.g.tok);
    }
    ss->g.ns = ns;    /* Fill in the rest of the ss fields (its already linked to right list). */
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
	  zx_xml_parse_err_mismatching_close_tag(c, (const char*)__FUNCTION__, name, tok);
	  ZX_DEC_TAG_MISMATCH_CLOSE(x->gg.g);
	  return x;
	}
	/* Legitimate close tag. Normal exit from this function. */
	++c->p;
	ZX_DEC_TAG_NOW_CLOSED(x->gg.g);
	goto out;
      default:
	if (A_Z_a_z_(*c->p)) {
	  if (!(name = zx_scan_elem_start(c, (const char*)__FUNCTION__)))
	    return x;
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
  zx_dec_reverse_lists(&x->gg);
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






/* FUNC(zx_DEC_md_Organization) */

#define EL_NAME   md_Organization
#define EL_STRUCT zx_md_Organization_s
#define EL_NS     md
#define EL_TAG    Organization

/* Called by: */
struct zx_md_Organization_s* zx_DEC_md_Organization(struct zx_ctx* c, struct zx_ns_s* ns )
{
  int tok;
  struct zx_elem_s* el;
  struct zx_str* ss;
  struct zx_ns_s* pop_seen;
  const char* name;
  const char* data;
  struct zx_md_Organization_s* x = ZX_ZALLOC(c, struct zx_md_Organization_s);
  x->gg.g.tok = zx_md_Organization_ELEM;
  x->gg.g.ns = ns;
  ZX_START_DEC_EXT(x);

#if 1 /* NORMALMODE */
  ZX_DEC_TAG_NOT_YET_CLOSED(x->gg.g);

  /* The tag name has already been detected. Process attributes until '>' */
  
  for (; c->p; ++c->p) {
    ZX_SKIP_WS(c,x);
    if (ONE_OF_2(*c->p, '>', '/'))
      break;
    if (!(data = zx_dec_attr_val(c, &name, (const char*)__FUNCTION__)))
      return x;
    tok = zx_attr_lookup(c, name, data-2, &ns);
    switch (tok) {

    case ZX_TOK_XMLNS:
      ZX_XMLNS_DEC_EXT(name);
      DD("xmlns detected(%.*s)", data-2-name, name);
      ns = zx_new_ns(c, data-2-name, name, c->p - data, data);
      ns->n = x->gg.xmlns;
      x->gg.xmlns = ns;
      goto next_attr;
    default:
      ss = zx_dec_unknown_attr(c, &x->gg, name, data, tok, x->gg.g.tok);
    }
    ss->g.ns = ns;    /* Fill in the rest of the ss fields (its already linked to right list). */
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
	  zx_xml_parse_err_mismatching_close_tag(c, (const char*)__FUNCTION__, name, tok);
	  ZX_DEC_TAG_MISMATCH_CLOSE(x->gg.g);
	  return x;
	}
	/* Legitimate close tag. Normal exit from this function. */
	++c->p;
	ZX_DEC_TAG_NOW_CLOSED(x->gg.g);
	goto out;
      default:
	if (A_Z_a_z_(*c->p)) {
	  if (!(name = zx_scan_elem_start(c, (const char*)__FUNCTION__)))
	    return x;
	  pop_seen = zx_scan_xmlns(c);  /* Prescan namespaces so that token can be correctly recognized. */
	  tok = zx_elem_lookup(c, name, c->p, &ns);
	  switch (tok) {
          case zx_md_Extensions_ELEM:
            el = (struct zx_elem_s*)zx_DEC_md_Extensions(c, ns);
            el->g.n = &x->Extensions->gg.g;
            x->Extensions = (struct zx_md_Extensions_s*)el;
            break;
          case zx_md_OrganizationName_ELEM:
            el = (struct zx_elem_s*)zx_DEC_md_OrganizationName(c, ns);
            el->g.n = &x->OrganizationName->gg.g;
            x->OrganizationName = (struct zx_md_OrganizationName_s*)el;
            break;
          case zx_md_OrganizationDisplayName_ELEM:
            el = (struct zx_elem_s*)zx_DEC_md_OrganizationDisplayName(c, ns);
            el->g.n = &x->OrganizationDisplayName->gg.g;
            x->OrganizationDisplayName = (struct zx_md_OrganizationDisplayName_s*)el;
            break;
          case zx_md_OrganizationURL_ELEM:
            el = (struct zx_elem_s*)zx_DEC_md_OrganizationURL(c, ns);
            el->g.n = &x->OrganizationURL->gg.g;
            x->OrganizationURL = (struct zx_md_OrganizationURL_s*)el;
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
  zx_dec_reverse_lists(&x->gg);
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






/* FUNC(zx_DEC_md_OrganizationDisplayName) */

#define EL_NAME   md_OrganizationDisplayName
#define EL_STRUCT zx_md_OrganizationDisplayName_s
#define EL_NS     md
#define EL_TAG    OrganizationDisplayName

/* Called by: */
struct zx_md_OrganizationDisplayName_s* zx_DEC_md_OrganizationDisplayName(struct zx_ctx* c, struct zx_ns_s* ns )
{
  int tok;
  struct zx_elem_s* el;
  struct zx_str* ss;
  struct zx_ns_s* pop_seen;
  const char* name;
  const char* data;
  struct zx_md_OrganizationDisplayName_s* x = ZX_ZALLOC(c, struct zx_md_OrganizationDisplayName_s);
  x->gg.g.tok = zx_md_OrganizationDisplayName_ELEM;
  x->gg.g.ns = ns;
  ZX_START_DEC_EXT(x);

#if 1 /* NORMALMODE */
  ZX_DEC_TAG_NOT_YET_CLOSED(x->gg.g);

  /* The tag name has already been detected. Process attributes until '>' */
  
  for (; c->p; ++c->p) {
    ZX_SKIP_WS(c,x);
    if (ONE_OF_2(*c->p, '>', '/'))
      break;
    if (!(data = zx_dec_attr_val(c, &name, (const char*)__FUNCTION__)))
      return x;
    tok = zx_attr_lookup(c, name, data-2, &ns);
    switch (tok) {
    case zx_xml_lang_ATTR:
      ss = ZX_ZALLOC(c, struct zx_str);
      ss->g.n = &x->lang->g;
      x->lang = ss;
      ZX_ATTR_DEC_EXT(ss);
      break;

    case ZX_TOK_XMLNS:
      ZX_XMLNS_DEC_EXT(name);
      DD("xmlns detected(%.*s)", data-2-name, name);
      ns = zx_new_ns(c, data-2-name, name, c->p - data, data);
      ns->n = x->gg.xmlns;
      x->gg.xmlns = ns;
      goto next_attr;
    default:
      ss = zx_dec_unknown_attr(c, &x->gg, name, data, tok, x->gg.g.tok);
    }
    ss->g.ns = ns;    /* Fill in the rest of the ss fields (its already linked to right list). */
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
	  zx_xml_parse_err_mismatching_close_tag(c, (const char*)__FUNCTION__, name, tok);
	  ZX_DEC_TAG_MISMATCH_CLOSE(x->gg.g);
	  return x;
	}
	/* Legitimate close tag. Normal exit from this function. */
	++c->p;
	ZX_DEC_TAG_NOW_CLOSED(x->gg.g);
	goto out;
      default:
	if (A_Z_a_z_(*c->p)) {
	  if (!(name = zx_scan_elem_start(c, (const char*)__FUNCTION__)))
	    return x;
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
  zx_dec_reverse_lists(&x->gg);
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






/* FUNC(zx_DEC_md_OrganizationName) */

#define EL_NAME   md_OrganizationName
#define EL_STRUCT zx_md_OrganizationName_s
#define EL_NS     md
#define EL_TAG    OrganizationName

/* Called by: */
struct zx_md_OrganizationName_s* zx_DEC_md_OrganizationName(struct zx_ctx* c, struct zx_ns_s* ns )
{
  int tok;
  struct zx_elem_s* el;
  struct zx_str* ss;
  struct zx_ns_s* pop_seen;
  const char* name;
  const char* data;
  struct zx_md_OrganizationName_s* x = ZX_ZALLOC(c, struct zx_md_OrganizationName_s);
  x->gg.g.tok = zx_md_OrganizationName_ELEM;
  x->gg.g.ns = ns;
  ZX_START_DEC_EXT(x);

#if 1 /* NORMALMODE */
  ZX_DEC_TAG_NOT_YET_CLOSED(x->gg.g);

  /* The tag name has already been detected. Process attributes until '>' */
  
  for (; c->p; ++c->p) {
    ZX_SKIP_WS(c,x);
    if (ONE_OF_2(*c->p, '>', '/'))
      break;
    if (!(data = zx_dec_attr_val(c, &name, (const char*)__FUNCTION__)))
      return x;
    tok = zx_attr_lookup(c, name, data-2, &ns);
    switch (tok) {
    case zx_xml_lang_ATTR:
      ss = ZX_ZALLOC(c, struct zx_str);
      ss->g.n = &x->lang->g;
      x->lang = ss;
      ZX_ATTR_DEC_EXT(ss);
      break;

    case ZX_TOK_XMLNS:
      ZX_XMLNS_DEC_EXT(name);
      DD("xmlns detected(%.*s)", data-2-name, name);
      ns = zx_new_ns(c, data-2-name, name, c->p - data, data);
      ns->n = x->gg.xmlns;
      x->gg.xmlns = ns;
      goto next_attr;
    default:
      ss = zx_dec_unknown_attr(c, &x->gg, name, data, tok, x->gg.g.tok);
    }
    ss->g.ns = ns;    /* Fill in the rest of the ss fields (its already linked to right list). */
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
	  zx_xml_parse_err_mismatching_close_tag(c, (const char*)__FUNCTION__, name, tok);
	  ZX_DEC_TAG_MISMATCH_CLOSE(x->gg.g);
	  return x;
	}
	/* Legitimate close tag. Normal exit from this function. */
	++c->p;
	ZX_DEC_TAG_NOW_CLOSED(x->gg.g);
	goto out;
      default:
	if (A_Z_a_z_(*c->p)) {
	  if (!(name = zx_scan_elem_start(c, (const char*)__FUNCTION__)))
	    return x;
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
  zx_dec_reverse_lists(&x->gg);
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






/* FUNC(zx_DEC_md_OrganizationURL) */

#define EL_NAME   md_OrganizationURL
#define EL_STRUCT zx_md_OrganizationURL_s
#define EL_NS     md
#define EL_TAG    OrganizationURL

/* Called by: */
struct zx_md_OrganizationURL_s* zx_DEC_md_OrganizationURL(struct zx_ctx* c, struct zx_ns_s* ns )
{
  int tok;
  struct zx_elem_s* el;
  struct zx_str* ss;
  struct zx_ns_s* pop_seen;
  const char* name;
  const char* data;
  struct zx_md_OrganizationURL_s* x = ZX_ZALLOC(c, struct zx_md_OrganizationURL_s);
  x->gg.g.tok = zx_md_OrganizationURL_ELEM;
  x->gg.g.ns = ns;
  ZX_START_DEC_EXT(x);

#if 1 /* NORMALMODE */
  ZX_DEC_TAG_NOT_YET_CLOSED(x->gg.g);

  /* The tag name has already been detected. Process attributes until '>' */
  
  for (; c->p; ++c->p) {
    ZX_SKIP_WS(c,x);
    if (ONE_OF_2(*c->p, '>', '/'))
      break;
    if (!(data = zx_dec_attr_val(c, &name, (const char*)__FUNCTION__)))
      return x;
    tok = zx_attr_lookup(c, name, data-2, &ns);
    switch (tok) {
    case zx_xml_lang_ATTR:
      ss = ZX_ZALLOC(c, struct zx_str);
      ss->g.n = &x->lang->g;
      x->lang = ss;
      ZX_ATTR_DEC_EXT(ss);
      break;

    case ZX_TOK_XMLNS:
      ZX_XMLNS_DEC_EXT(name);
      DD("xmlns detected(%.*s)", data-2-name, name);
      ns = zx_new_ns(c, data-2-name, name, c->p - data, data);
      ns->n = x->gg.xmlns;
      x->gg.xmlns = ns;
      goto next_attr;
    default:
      ss = zx_dec_unknown_attr(c, &x->gg, name, data, tok, x->gg.g.tok);
    }
    ss->g.ns = ns;    /* Fill in the rest of the ss fields (its already linked to right list). */
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
	  zx_xml_parse_err_mismatching_close_tag(c, (const char*)__FUNCTION__, name, tok);
	  ZX_DEC_TAG_MISMATCH_CLOSE(x->gg.g);
	  return x;
	}
	/* Legitimate close tag. Normal exit from this function. */
	++c->p;
	ZX_DEC_TAG_NOW_CLOSED(x->gg.g);
	goto out;
      default:
	if (A_Z_a_z_(*c->p)) {
	  if (!(name = zx_scan_elem_start(c, (const char*)__FUNCTION__)))
	    return x;
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
  zx_dec_reverse_lists(&x->gg);
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






/* FUNC(zx_DEC_md_PDPDescriptor) */

#define EL_NAME   md_PDPDescriptor
#define EL_STRUCT zx_md_PDPDescriptor_s
#define EL_NS     md
#define EL_TAG    PDPDescriptor

/* Called by: */
struct zx_md_PDPDescriptor_s* zx_DEC_md_PDPDescriptor(struct zx_ctx* c, struct zx_ns_s* ns )
{
  int tok;
  struct zx_elem_s* el;
  struct zx_str* ss;
  struct zx_ns_s* pop_seen;
  const char* name;
  const char* data;
  struct zx_md_PDPDescriptor_s* x = ZX_ZALLOC(c, struct zx_md_PDPDescriptor_s);
  x->gg.g.tok = zx_md_PDPDescriptor_ELEM;
  x->gg.g.ns = ns;
  ZX_START_DEC_EXT(x);

#if 1 /* NORMALMODE */
  ZX_DEC_TAG_NOT_YET_CLOSED(x->gg.g);

  /* The tag name has already been detected. Process attributes until '>' */
  
  for (; c->p; ++c->p) {
    ZX_SKIP_WS(c,x);
    if (ONE_OF_2(*c->p, '>', '/'))
      break;
    if (!(data = zx_dec_attr_val(c, &name, (const char*)__FUNCTION__)))
      return x;
    tok = zx_attr_lookup(c, name, data-2, &ns);
    switch (tok) {
    case zx_ID_ATTR:
      ss = ZX_ZALLOC(c, struct zx_str);
      ss->g.n = &x->ID->g;
      x->ID = ss;
      ZX_ATTR_DEC_EXT(ss);
      break;
    case zx_cacheDuration_ATTR:
      ss = ZX_ZALLOC(c, struct zx_str);
      ss->g.n = &x->cacheDuration->g;
      x->cacheDuration = ss;
      ZX_ATTR_DEC_EXT(ss);
      break;
    case zx_errorURL_ATTR:
      ss = ZX_ZALLOC(c, struct zx_str);
      ss->g.n = &x->errorURL->g;
      x->errorURL = ss;
      ZX_ATTR_DEC_EXT(ss);
      break;
    case zx_protocolSupportEnumeration_ATTR:
      ss = ZX_ZALLOC(c, struct zx_str);
      ss->g.n = &x->protocolSupportEnumeration->g;
      x->protocolSupportEnumeration = ss;
      ZX_ATTR_DEC_EXT(ss);
      break;
    case zx_validUntil_ATTR:
      ss = ZX_ZALLOC(c, struct zx_str);
      ss->g.n = &x->validUntil->g;
      x->validUntil = ss;
      ZX_ATTR_DEC_EXT(ss);
      break;

    case ZX_TOK_XMLNS:
      ZX_XMLNS_DEC_EXT(name);
      DD("xmlns detected(%.*s)", data-2-name, name);
      ns = zx_new_ns(c, data-2-name, name, c->p - data, data);
      ns->n = x->gg.xmlns;
      x->gg.xmlns = ns;
      goto next_attr;
    default:
      ss = zx_dec_unknown_attr(c, &x->gg, name, data, tok, x->gg.g.tok);
    }
    ss->g.ns = ns;    /* Fill in the rest of the ss fields (its already linked to right list). */
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
	  zx_xml_parse_err_mismatching_close_tag(c, (const char*)__FUNCTION__, name, tok);
	  ZX_DEC_TAG_MISMATCH_CLOSE(x->gg.g);
	  return x;
	}
	/* Legitimate close tag. Normal exit from this function. */
	++c->p;
	ZX_DEC_TAG_NOW_CLOSED(x->gg.g);
	goto out;
      default:
	if (A_Z_a_z_(*c->p)) {
	  if (!(name = zx_scan_elem_start(c, (const char*)__FUNCTION__)))
	    return x;
	  pop_seen = zx_scan_xmlns(c);  /* Prescan namespaces so that token can be correctly recognized. */
	  tok = zx_elem_lookup(c, name, c->p, &ns);
	  switch (tok) {
          case zx_ds_Signature_ELEM:
            el = (struct zx_elem_s*)zx_DEC_ds_Signature(c, ns);
            el->g.n = &x->Signature->gg.g;
            x->Signature = (struct zx_ds_Signature_s*)el;
            break;
          case zx_md_Extensions_ELEM:
            el = (struct zx_elem_s*)zx_DEC_md_Extensions(c, ns);
            el->g.n = &x->Extensions->gg.g;
            x->Extensions = (struct zx_md_Extensions_s*)el;
            break;
          case zx_md_KeyDescriptor_ELEM:
            el = (struct zx_elem_s*)zx_DEC_md_KeyDescriptor(c, ns);
            el->g.n = &x->KeyDescriptor->gg.g;
            x->KeyDescriptor = (struct zx_md_KeyDescriptor_s*)el;
            break;
          case zx_md_Organization_ELEM:
            el = (struct zx_elem_s*)zx_DEC_md_Organization(c, ns);
            el->g.n = &x->Organization->gg.g;
            x->Organization = (struct zx_md_Organization_s*)el;
            break;
          case zx_md_ContactPerson_ELEM:
            el = (struct zx_elem_s*)zx_DEC_md_ContactPerson(c, ns);
            el->g.n = &x->ContactPerson->gg.g;
            x->ContactPerson = (struct zx_md_ContactPerson_s*)el;
            break;
          case zx_md_AuthzService_ELEM:
            el = (struct zx_elem_s*)zx_DEC_md_AuthzService(c, ns);
            el->g.n = &x->AuthzService->gg.g;
            x->AuthzService = (struct zx_md_AuthzService_s*)el;
            break;
          case zx_md_AssertionIDRequestService_ELEM:
            el = (struct zx_elem_s*)zx_DEC_md_AssertionIDRequestService(c, ns);
            el->g.n = &x->AssertionIDRequestService->gg.g;
            x->AssertionIDRequestService = (struct zx_md_AssertionIDRequestService_s*)el;
            break;
          case zx_md_NameIDFormat_ELEM:
            el = zx_DEC_simple_elem(c, ns, tok);
            el->g.n = &x->NameIDFormat->g;
            x->NameIDFormat = el;
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
  zx_dec_reverse_lists(&x->gg);
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






/* FUNC(zx_DEC_md_RequestedAttribute) */

#define EL_NAME   md_RequestedAttribute
#define EL_STRUCT zx_md_RequestedAttribute_s
#define EL_NS     md
#define EL_TAG    RequestedAttribute

/* Called by: */
struct zx_md_RequestedAttribute_s* zx_DEC_md_RequestedAttribute(struct zx_ctx* c, struct zx_ns_s* ns )
{
  int tok;
  struct zx_elem_s* el;
  struct zx_str* ss;
  struct zx_ns_s* pop_seen;
  const char* name;
  const char* data;
  struct zx_md_RequestedAttribute_s* x = ZX_ZALLOC(c, struct zx_md_RequestedAttribute_s);
  x->gg.g.tok = zx_md_RequestedAttribute_ELEM;
  x->gg.g.ns = ns;
  ZX_START_DEC_EXT(x);

#if 1 /* NORMALMODE */
  ZX_DEC_TAG_NOT_YET_CLOSED(x->gg.g);

  /* The tag name has already been detected. Process attributes until '>' */
  
  for (; c->p; ++c->p) {
    ZX_SKIP_WS(c,x);
    if (ONE_OF_2(*c->p, '>', '/'))
      break;
    if (!(data = zx_dec_attr_val(c, &name, (const char*)__FUNCTION__)))
      return x;
    tok = zx_attr_lookup(c, name, data-2, &ns);
    switch (tok) {
    case zx_FriendlyName_ATTR:
      ss = ZX_ZALLOC(c, struct zx_str);
      ss->g.n = &x->FriendlyName->g;
      x->FriendlyName = ss;
      ZX_ATTR_DEC_EXT(ss);
      break;
    case zx_Name_ATTR:
      ss = ZX_ZALLOC(c, struct zx_str);
      ss->g.n = &x->Name->g;
      x->Name = ss;
      ZX_ATTR_DEC_EXT(ss);
      break;
    case zx_NameFormat_ATTR:
      ss = ZX_ZALLOC(c, struct zx_str);
      ss->g.n = &x->NameFormat->g;
      x->NameFormat = ss;
      ZX_ATTR_DEC_EXT(ss);
      break;
    case zx_isRequired_ATTR:
      ss = ZX_ZALLOC(c, struct zx_str);
      ss->g.n = &x->isRequired->g;
      x->isRequired = ss;
      ZX_ATTR_DEC_EXT(ss);
      break;

    case ZX_TOK_XMLNS:
      ZX_XMLNS_DEC_EXT(name);
      DD("xmlns detected(%.*s)", data-2-name, name);
      ns = zx_new_ns(c, data-2-name, name, c->p - data, data);
      ns->n = x->gg.xmlns;
      x->gg.xmlns = ns;
      goto next_attr;
    default:
      ss = zx_dec_unknown_attr(c, &x->gg, name, data, tok, x->gg.g.tok);
    }
    ss->g.ns = ns;    /* Fill in the rest of the ss fields (its already linked to right list). */
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
	  zx_xml_parse_err_mismatching_close_tag(c, (const char*)__FUNCTION__, name, tok);
	  ZX_DEC_TAG_MISMATCH_CLOSE(x->gg.g);
	  return x;
	}
	/* Legitimate close tag. Normal exit from this function. */
	++c->p;
	ZX_DEC_TAG_NOW_CLOSED(x->gg.g);
	goto out;
      default:
	if (A_Z_a_z_(*c->p)) {
	  if (!(name = zx_scan_elem_start(c, (const char*)__FUNCTION__)))
	    return x;
	  pop_seen = zx_scan_xmlns(c);  /* Prescan namespaces so that token can be correctly recognized. */
	  tok = zx_elem_lookup(c, name, c->p, &ns);
	  switch (tok) {
          case zx_sa_AttributeValue_ELEM:
            el = (struct zx_elem_s*)zx_DEC_sa_AttributeValue(c, ns);
            el->g.n = &x->AttributeValue->gg.g;
            x->AttributeValue = (struct zx_sa_AttributeValue_s*)el;
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
  zx_dec_reverse_lists(&x->gg);
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






/* FUNC(zx_DEC_md_RoleDescriptor) */

#define EL_NAME   md_RoleDescriptor
#define EL_STRUCT zx_md_RoleDescriptor_s
#define EL_NS     md
#define EL_TAG    RoleDescriptor

/* Called by: */
struct zx_md_RoleDescriptor_s* zx_DEC_md_RoleDescriptor(struct zx_ctx* c, struct zx_ns_s* ns )
{
  int tok;
  struct zx_elem_s* el;
  struct zx_str* ss;
  struct zx_ns_s* pop_seen;
  const char* name;
  const char* data;
  struct zx_md_RoleDescriptor_s* x = ZX_ZALLOC(c, struct zx_md_RoleDescriptor_s);
  x->gg.g.tok = zx_md_RoleDescriptor_ELEM;
  x->gg.g.ns = ns;
  ZX_START_DEC_EXT(x);

#if 1 /* NORMALMODE */
  ZX_DEC_TAG_NOT_YET_CLOSED(x->gg.g);

  /* The tag name has already been detected. Process attributes until '>' */
  
  for (; c->p; ++c->p) {
    ZX_SKIP_WS(c,x);
    if (ONE_OF_2(*c->p, '>', '/'))
      break;
    if (!(data = zx_dec_attr_val(c, &name, (const char*)__FUNCTION__)))
      return x;
    tok = zx_attr_lookup(c, name, data-2, &ns);
    switch (tok) {
    case zx_ID_ATTR:
      ss = ZX_ZALLOC(c, struct zx_str);
      ss->g.n = &x->ID->g;
      x->ID = ss;
      ZX_ATTR_DEC_EXT(ss);
      break;
    case zx_cacheDuration_ATTR:
      ss = ZX_ZALLOC(c, struct zx_str);
      ss->g.n = &x->cacheDuration->g;
      x->cacheDuration = ss;
      ZX_ATTR_DEC_EXT(ss);
      break;
    case zx_errorURL_ATTR:
      ss = ZX_ZALLOC(c, struct zx_str);
      ss->g.n = &x->errorURL->g;
      x->errorURL = ss;
      ZX_ATTR_DEC_EXT(ss);
      break;
    case zx_protocolSupportEnumeration_ATTR:
      ss = ZX_ZALLOC(c, struct zx_str);
      ss->g.n = &x->protocolSupportEnumeration->g;
      x->protocolSupportEnumeration = ss;
      ZX_ATTR_DEC_EXT(ss);
      break;
    case zx_validUntil_ATTR:
      ss = ZX_ZALLOC(c, struct zx_str);
      ss->g.n = &x->validUntil->g;
      x->validUntil = ss;
      ZX_ATTR_DEC_EXT(ss);
      break;

    case ZX_TOK_XMLNS:
      ZX_XMLNS_DEC_EXT(name);
      DD("xmlns detected(%.*s)", data-2-name, name);
      ns = zx_new_ns(c, data-2-name, name, c->p - data, data);
      ns->n = x->gg.xmlns;
      x->gg.xmlns = ns;
      goto next_attr;
    default:
      ss = zx_dec_unknown_attr(c, &x->gg, name, data, tok, x->gg.g.tok);
    }
    ss->g.ns = ns;    /* Fill in the rest of the ss fields (its already linked to right list). */
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
	  zx_xml_parse_err_mismatching_close_tag(c, (const char*)__FUNCTION__, name, tok);
	  ZX_DEC_TAG_MISMATCH_CLOSE(x->gg.g);
	  return x;
	}
	/* Legitimate close tag. Normal exit from this function. */
	++c->p;
	ZX_DEC_TAG_NOW_CLOSED(x->gg.g);
	goto out;
      default:
	if (A_Z_a_z_(*c->p)) {
	  if (!(name = zx_scan_elem_start(c, (const char*)__FUNCTION__)))
	    return x;
	  pop_seen = zx_scan_xmlns(c);  /* Prescan namespaces so that token can be correctly recognized. */
	  tok = zx_elem_lookup(c, name, c->p, &ns);
	  switch (tok) {
          case zx_ds_Signature_ELEM:
            el = (struct zx_elem_s*)zx_DEC_ds_Signature(c, ns);
            el->g.n = &x->Signature->gg.g;
            x->Signature = (struct zx_ds_Signature_s*)el;
            break;
          case zx_md_Extensions_ELEM:
            el = (struct zx_elem_s*)zx_DEC_md_Extensions(c, ns);
            el->g.n = &x->Extensions->gg.g;
            x->Extensions = (struct zx_md_Extensions_s*)el;
            break;
          case zx_md_KeyDescriptor_ELEM:
            el = (struct zx_elem_s*)zx_DEC_md_KeyDescriptor(c, ns);
            el->g.n = &x->KeyDescriptor->gg.g;
            x->KeyDescriptor = (struct zx_md_KeyDescriptor_s*)el;
            break;
          case zx_md_Organization_ELEM:
            el = (struct zx_elem_s*)zx_DEC_md_Organization(c, ns);
            el->g.n = &x->Organization->gg.g;
            x->Organization = (struct zx_md_Organization_s*)el;
            break;
          case zx_md_ContactPerson_ELEM:
            el = (struct zx_elem_s*)zx_DEC_md_ContactPerson(c, ns);
            el->g.n = &x->ContactPerson->gg.g;
            x->ContactPerson = (struct zx_md_ContactPerson_s*)el;
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
  zx_dec_reverse_lists(&x->gg);
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






/* FUNC(zx_DEC_md_SPSSODescriptor) */

#define EL_NAME   md_SPSSODescriptor
#define EL_STRUCT zx_md_SPSSODescriptor_s
#define EL_NS     md
#define EL_TAG    SPSSODescriptor

/* Called by: */
struct zx_md_SPSSODescriptor_s* zx_DEC_md_SPSSODescriptor(struct zx_ctx* c, struct zx_ns_s* ns )
{
  int tok;
  struct zx_elem_s* el;
  struct zx_str* ss;
  struct zx_ns_s* pop_seen;
  const char* name;
  const char* data;
  struct zx_md_SPSSODescriptor_s* x = ZX_ZALLOC(c, struct zx_md_SPSSODescriptor_s);
  x->gg.g.tok = zx_md_SPSSODescriptor_ELEM;
  x->gg.g.ns = ns;
  ZX_START_DEC_EXT(x);

#if 1 /* NORMALMODE */
  ZX_DEC_TAG_NOT_YET_CLOSED(x->gg.g);

  /* The tag name has already been detected. Process attributes until '>' */
  
  for (; c->p; ++c->p) {
    ZX_SKIP_WS(c,x);
    if (ONE_OF_2(*c->p, '>', '/'))
      break;
    if (!(data = zx_dec_attr_val(c, &name, (const char*)__FUNCTION__)))
      return x;
    tok = zx_attr_lookup(c, name, data-2, &ns);
    switch (tok) {
    case zx_AuthnRequestsSigned_ATTR:
      ss = ZX_ZALLOC(c, struct zx_str);
      ss->g.n = &x->AuthnRequestsSigned->g;
      x->AuthnRequestsSigned = ss;
      ZX_ATTR_DEC_EXT(ss);
      break;
    case zx_ID_ATTR:
      ss = ZX_ZALLOC(c, struct zx_str);
      ss->g.n = &x->ID->g;
      x->ID = ss;
      ZX_ATTR_DEC_EXT(ss);
      break;
    case zx_WantAssertionsSigned_ATTR:
      ss = ZX_ZALLOC(c, struct zx_str);
      ss->g.n = &x->WantAssertionsSigned->g;
      x->WantAssertionsSigned = ss;
      ZX_ATTR_DEC_EXT(ss);
      break;
    case zx_cacheDuration_ATTR:
      ss = ZX_ZALLOC(c, struct zx_str);
      ss->g.n = &x->cacheDuration->g;
      x->cacheDuration = ss;
      ZX_ATTR_DEC_EXT(ss);
      break;
    case zx_errorURL_ATTR:
      ss = ZX_ZALLOC(c, struct zx_str);
      ss->g.n = &x->errorURL->g;
      x->errorURL = ss;
      ZX_ATTR_DEC_EXT(ss);
      break;
    case zx_protocolSupportEnumeration_ATTR:
      ss = ZX_ZALLOC(c, struct zx_str);
      ss->g.n = &x->protocolSupportEnumeration->g;
      x->protocolSupportEnumeration = ss;
      ZX_ATTR_DEC_EXT(ss);
      break;
    case zx_validUntil_ATTR:
      ss = ZX_ZALLOC(c, struct zx_str);
      ss->g.n = &x->validUntil->g;
      x->validUntil = ss;
      ZX_ATTR_DEC_EXT(ss);
      break;

    case ZX_TOK_XMLNS:
      ZX_XMLNS_DEC_EXT(name);
      DD("xmlns detected(%.*s)", data-2-name, name);
      ns = zx_new_ns(c, data-2-name, name, c->p - data, data);
      ns->n = x->gg.xmlns;
      x->gg.xmlns = ns;
      goto next_attr;
    default:
      ss = zx_dec_unknown_attr(c, &x->gg, name, data, tok, x->gg.g.tok);
    }
    ss->g.ns = ns;    /* Fill in the rest of the ss fields (its already linked to right list). */
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
	  zx_xml_parse_err_mismatching_close_tag(c, (const char*)__FUNCTION__, name, tok);
	  ZX_DEC_TAG_MISMATCH_CLOSE(x->gg.g);
	  return x;
	}
	/* Legitimate close tag. Normal exit from this function. */
	++c->p;
	ZX_DEC_TAG_NOW_CLOSED(x->gg.g);
	goto out;
      default:
	if (A_Z_a_z_(*c->p)) {
	  if (!(name = zx_scan_elem_start(c, (const char*)__FUNCTION__)))
	    return x;
	  pop_seen = zx_scan_xmlns(c);  /* Prescan namespaces so that token can be correctly recognized. */
	  tok = zx_elem_lookup(c, name, c->p, &ns);
	  switch (tok) {
          case zx_ds_Signature_ELEM:
            el = (struct zx_elem_s*)zx_DEC_ds_Signature(c, ns);
            el->g.n = &x->Signature->gg.g;
            x->Signature = (struct zx_ds_Signature_s*)el;
            break;
          case zx_md_Extensions_ELEM:
            el = (struct zx_elem_s*)zx_DEC_md_Extensions(c, ns);
            el->g.n = &x->Extensions->gg.g;
            x->Extensions = (struct zx_md_Extensions_s*)el;
            break;
          case zx_md_KeyDescriptor_ELEM:
            el = (struct zx_elem_s*)zx_DEC_md_KeyDescriptor(c, ns);
            el->g.n = &x->KeyDescriptor->gg.g;
            x->KeyDescriptor = (struct zx_md_KeyDescriptor_s*)el;
            break;
          case zx_md_Organization_ELEM:
            el = (struct zx_elem_s*)zx_DEC_md_Organization(c, ns);
            el->g.n = &x->Organization->gg.g;
            x->Organization = (struct zx_md_Organization_s*)el;
            break;
          case zx_md_ContactPerson_ELEM:
            el = (struct zx_elem_s*)zx_DEC_md_ContactPerson(c, ns);
            el->g.n = &x->ContactPerson->gg.g;
            x->ContactPerson = (struct zx_md_ContactPerson_s*)el;
            break;
          case zx_md_ArtifactResolutionService_ELEM:
            el = (struct zx_elem_s*)zx_DEC_md_ArtifactResolutionService(c, ns);
            el->g.n = &x->ArtifactResolutionService->gg.g;
            x->ArtifactResolutionService = (struct zx_md_ArtifactResolutionService_s*)el;
            break;
          case zx_md_SingleLogoutService_ELEM:
            el = (struct zx_elem_s*)zx_DEC_md_SingleLogoutService(c, ns);
            el->g.n = &x->SingleLogoutService->gg.g;
            x->SingleLogoutService = (struct zx_md_SingleLogoutService_s*)el;
            break;
          case zx_md_ManageNameIDService_ELEM:
            el = (struct zx_elem_s*)zx_DEC_md_ManageNameIDService(c, ns);
            el->g.n = &x->ManageNameIDService->gg.g;
            x->ManageNameIDService = (struct zx_md_ManageNameIDService_s*)el;
            break;
          case zx_md_NameIDFormat_ELEM:
            el = zx_DEC_simple_elem(c, ns, tok);
            el->g.n = &x->NameIDFormat->g;
            x->NameIDFormat = el;
            break;
          case zx_md_AssertionConsumerService_ELEM:
            el = (struct zx_elem_s*)zx_DEC_md_AssertionConsumerService(c, ns);
            el->g.n = &x->AssertionConsumerService->gg.g;
            x->AssertionConsumerService = (struct zx_md_AssertionConsumerService_s*)el;
            break;
          case zx_md_AttributeConsumingService_ELEM:
            el = (struct zx_elem_s*)zx_DEC_md_AttributeConsumingService(c, ns);
            el->g.n = &x->AttributeConsumingService->gg.g;
            x->AttributeConsumingService = (struct zx_md_AttributeConsumingService_s*)el;
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
  zx_dec_reverse_lists(&x->gg);
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






/* FUNC(zx_DEC_md_ServiceDescription) */

#define EL_NAME   md_ServiceDescription
#define EL_STRUCT zx_md_ServiceDescription_s
#define EL_NS     md
#define EL_TAG    ServiceDescription

/* Called by: */
struct zx_md_ServiceDescription_s* zx_DEC_md_ServiceDescription(struct zx_ctx* c, struct zx_ns_s* ns )
{
  int tok;
  struct zx_elem_s* el;
  struct zx_str* ss;
  struct zx_ns_s* pop_seen;
  const char* name;
  const char* data;
  struct zx_md_ServiceDescription_s* x = ZX_ZALLOC(c, struct zx_md_ServiceDescription_s);
  x->gg.g.tok = zx_md_ServiceDescription_ELEM;
  x->gg.g.ns = ns;
  ZX_START_DEC_EXT(x);

#if 1 /* NORMALMODE */
  ZX_DEC_TAG_NOT_YET_CLOSED(x->gg.g);

  /* The tag name has already been detected. Process attributes until '>' */
  
  for (; c->p; ++c->p) {
    ZX_SKIP_WS(c,x);
    if (ONE_OF_2(*c->p, '>', '/'))
      break;
    if (!(data = zx_dec_attr_val(c, &name, (const char*)__FUNCTION__)))
      return x;
    tok = zx_attr_lookup(c, name, data-2, &ns);
    switch (tok) {
    case zx_xml_lang_ATTR:
      ss = ZX_ZALLOC(c, struct zx_str);
      ss->g.n = &x->lang->g;
      x->lang = ss;
      ZX_ATTR_DEC_EXT(ss);
      break;

    case ZX_TOK_XMLNS:
      ZX_XMLNS_DEC_EXT(name);
      DD("xmlns detected(%.*s)", data-2-name, name);
      ns = zx_new_ns(c, data-2-name, name, c->p - data, data);
      ns->n = x->gg.xmlns;
      x->gg.xmlns = ns;
      goto next_attr;
    default:
      ss = zx_dec_unknown_attr(c, &x->gg, name, data, tok, x->gg.g.tok);
    }
    ss->g.ns = ns;    /* Fill in the rest of the ss fields (its already linked to right list). */
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
	  zx_xml_parse_err_mismatching_close_tag(c, (const char*)__FUNCTION__, name, tok);
	  ZX_DEC_TAG_MISMATCH_CLOSE(x->gg.g);
	  return x;
	}
	/* Legitimate close tag. Normal exit from this function. */
	++c->p;
	ZX_DEC_TAG_NOW_CLOSED(x->gg.g);
	goto out;
      default:
	if (A_Z_a_z_(*c->p)) {
	  if (!(name = zx_scan_elem_start(c, (const char*)__FUNCTION__)))
	    return x;
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
  zx_dec_reverse_lists(&x->gg);
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






/* FUNC(zx_DEC_md_ServiceName) */

#define EL_NAME   md_ServiceName
#define EL_STRUCT zx_md_ServiceName_s
#define EL_NS     md
#define EL_TAG    ServiceName

/* Called by: */
struct zx_md_ServiceName_s* zx_DEC_md_ServiceName(struct zx_ctx* c, struct zx_ns_s* ns )
{
  int tok;
  struct zx_elem_s* el;
  struct zx_str* ss;
  struct zx_ns_s* pop_seen;
  const char* name;
  const char* data;
  struct zx_md_ServiceName_s* x = ZX_ZALLOC(c, struct zx_md_ServiceName_s);
  x->gg.g.tok = zx_md_ServiceName_ELEM;
  x->gg.g.ns = ns;
  ZX_START_DEC_EXT(x);

#if 1 /* NORMALMODE */
  ZX_DEC_TAG_NOT_YET_CLOSED(x->gg.g);

  /* The tag name has already been detected. Process attributes until '>' */
  
  for (; c->p; ++c->p) {
    ZX_SKIP_WS(c,x);
    if (ONE_OF_2(*c->p, '>', '/'))
      break;
    if (!(data = zx_dec_attr_val(c, &name, (const char*)__FUNCTION__)))
      return x;
    tok = zx_attr_lookup(c, name, data-2, &ns);
    switch (tok) {
    case zx_xml_lang_ATTR:
      ss = ZX_ZALLOC(c, struct zx_str);
      ss->g.n = &x->lang->g;
      x->lang = ss;
      ZX_ATTR_DEC_EXT(ss);
      break;

    case ZX_TOK_XMLNS:
      ZX_XMLNS_DEC_EXT(name);
      DD("xmlns detected(%.*s)", data-2-name, name);
      ns = zx_new_ns(c, data-2-name, name, c->p - data, data);
      ns->n = x->gg.xmlns;
      x->gg.xmlns = ns;
      goto next_attr;
    default:
      ss = zx_dec_unknown_attr(c, &x->gg, name, data, tok, x->gg.g.tok);
    }
    ss->g.ns = ns;    /* Fill in the rest of the ss fields (its already linked to right list). */
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
	  zx_xml_parse_err_mismatching_close_tag(c, (const char*)__FUNCTION__, name, tok);
	  ZX_DEC_TAG_MISMATCH_CLOSE(x->gg.g);
	  return x;
	}
	/* Legitimate close tag. Normal exit from this function. */
	++c->p;
	ZX_DEC_TAG_NOW_CLOSED(x->gg.g);
	goto out;
      default:
	if (A_Z_a_z_(*c->p)) {
	  if (!(name = zx_scan_elem_start(c, (const char*)__FUNCTION__)))
	    return x;
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
  zx_dec_reverse_lists(&x->gg);
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






/* FUNC(zx_DEC_md_SingleLogoutService) */

#define EL_NAME   md_SingleLogoutService
#define EL_STRUCT zx_md_SingleLogoutService_s
#define EL_NS     md
#define EL_TAG    SingleLogoutService

/* Called by: */
struct zx_md_SingleLogoutService_s* zx_DEC_md_SingleLogoutService(struct zx_ctx* c, struct zx_ns_s* ns )
{
  int tok;
  struct zx_elem_s* el;
  struct zx_str* ss;
  struct zx_ns_s* pop_seen;
  const char* name;
  const char* data;
  struct zx_md_SingleLogoutService_s* x = ZX_ZALLOC(c, struct zx_md_SingleLogoutService_s);
  x->gg.g.tok = zx_md_SingleLogoutService_ELEM;
  x->gg.g.ns = ns;
  ZX_START_DEC_EXT(x);

#if 1 /* NORMALMODE */
  ZX_DEC_TAG_NOT_YET_CLOSED(x->gg.g);

  /* The tag name has already been detected. Process attributes until '>' */
  
  for (; c->p; ++c->p) {
    ZX_SKIP_WS(c,x);
    if (ONE_OF_2(*c->p, '>', '/'))
      break;
    if (!(data = zx_dec_attr_val(c, &name, (const char*)__FUNCTION__)))
      return x;
    tok = zx_attr_lookup(c, name, data-2, &ns);
    switch (tok) {
    case zx_Binding_ATTR:
      ss = ZX_ZALLOC(c, struct zx_str);
      ss->g.n = &x->Binding->g;
      x->Binding = ss;
      ZX_ATTR_DEC_EXT(ss);
      break;
    case zx_Location_ATTR:
      ss = ZX_ZALLOC(c, struct zx_str);
      ss->g.n = &x->Location->g;
      x->Location = ss;
      ZX_ATTR_DEC_EXT(ss);
      break;
    case zx_ResponseLocation_ATTR:
      ss = ZX_ZALLOC(c, struct zx_str);
      ss->g.n = &x->ResponseLocation->g;
      x->ResponseLocation = ss;
      ZX_ATTR_DEC_EXT(ss);
      break;
    case zx_index_ATTR:
      ss = ZX_ZALLOC(c, struct zx_str);
      ss->g.n = &x->index->g;
      x->index = ss;
      ZX_ATTR_DEC_EXT(ss);
      break;
    case zx_isDefault_ATTR:
      ss = ZX_ZALLOC(c, struct zx_str);
      ss->g.n = &x->isDefault->g;
      x->isDefault = ss;
      ZX_ATTR_DEC_EXT(ss);
      break;

    case ZX_TOK_XMLNS:
      ZX_XMLNS_DEC_EXT(name);
      DD("xmlns detected(%.*s)", data-2-name, name);
      ns = zx_new_ns(c, data-2-name, name, c->p - data, data);
      ns->n = x->gg.xmlns;
      x->gg.xmlns = ns;
      goto next_attr;
    default:
      ss = zx_dec_unknown_attr(c, &x->gg, name, data, tok, x->gg.g.tok);
    }
    ss->g.ns = ns;    /* Fill in the rest of the ss fields (its already linked to right list). */
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
	  zx_xml_parse_err_mismatching_close_tag(c, (const char*)__FUNCTION__, name, tok);
	  ZX_DEC_TAG_MISMATCH_CLOSE(x->gg.g);
	  return x;
	}
	/* Legitimate close tag. Normal exit from this function. */
	++c->p;
	ZX_DEC_TAG_NOW_CLOSED(x->gg.g);
	goto out;
      default:
	if (A_Z_a_z_(*c->p)) {
	  if (!(name = zx_scan_elem_start(c, (const char*)__FUNCTION__)))
	    return x;
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
  zx_dec_reverse_lists(&x->gg);
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






/* FUNC(zx_DEC_md_SingleSignOnService) */

#define EL_NAME   md_SingleSignOnService
#define EL_STRUCT zx_md_SingleSignOnService_s
#define EL_NS     md
#define EL_TAG    SingleSignOnService

/* Called by: */
struct zx_md_SingleSignOnService_s* zx_DEC_md_SingleSignOnService(struct zx_ctx* c, struct zx_ns_s* ns )
{
  int tok;
  struct zx_elem_s* el;
  struct zx_str* ss;
  struct zx_ns_s* pop_seen;
  const char* name;
  const char* data;
  struct zx_md_SingleSignOnService_s* x = ZX_ZALLOC(c, struct zx_md_SingleSignOnService_s);
  x->gg.g.tok = zx_md_SingleSignOnService_ELEM;
  x->gg.g.ns = ns;
  ZX_START_DEC_EXT(x);

#if 1 /* NORMALMODE */
  ZX_DEC_TAG_NOT_YET_CLOSED(x->gg.g);

  /* The tag name has already been detected. Process attributes until '>' */
  
  for (; c->p; ++c->p) {
    ZX_SKIP_WS(c,x);
    if (ONE_OF_2(*c->p, '>', '/'))
      break;
    if (!(data = zx_dec_attr_val(c, &name, (const char*)__FUNCTION__)))
      return x;
    tok = zx_attr_lookup(c, name, data-2, &ns);
    switch (tok) {
    case zx_Binding_ATTR:
      ss = ZX_ZALLOC(c, struct zx_str);
      ss->g.n = &x->Binding->g;
      x->Binding = ss;
      ZX_ATTR_DEC_EXT(ss);
      break;
    case zx_Location_ATTR:
      ss = ZX_ZALLOC(c, struct zx_str);
      ss->g.n = &x->Location->g;
      x->Location = ss;
      ZX_ATTR_DEC_EXT(ss);
      break;
    case zx_ResponseLocation_ATTR:
      ss = ZX_ZALLOC(c, struct zx_str);
      ss->g.n = &x->ResponseLocation->g;
      x->ResponseLocation = ss;
      ZX_ATTR_DEC_EXT(ss);
      break;
    case zx_index_ATTR:
      ss = ZX_ZALLOC(c, struct zx_str);
      ss->g.n = &x->index->g;
      x->index = ss;
      ZX_ATTR_DEC_EXT(ss);
      break;
    case zx_isDefault_ATTR:
      ss = ZX_ZALLOC(c, struct zx_str);
      ss->g.n = &x->isDefault->g;
      x->isDefault = ss;
      ZX_ATTR_DEC_EXT(ss);
      break;

    case ZX_TOK_XMLNS:
      ZX_XMLNS_DEC_EXT(name);
      DD("xmlns detected(%.*s)", data-2-name, name);
      ns = zx_new_ns(c, data-2-name, name, c->p - data, data);
      ns->n = x->gg.xmlns;
      x->gg.xmlns = ns;
      goto next_attr;
    default:
      ss = zx_dec_unknown_attr(c, &x->gg, name, data, tok, x->gg.g.tok);
    }
    ss->g.ns = ns;    /* Fill in the rest of the ss fields (its already linked to right list). */
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
	  zx_xml_parse_err_mismatching_close_tag(c, (const char*)__FUNCTION__, name, tok);
	  ZX_DEC_TAG_MISMATCH_CLOSE(x->gg.g);
	  return x;
	}
	/* Legitimate close tag. Normal exit from this function. */
	++c->p;
	ZX_DEC_TAG_NOW_CLOSED(x->gg.g);
	goto out;
      default:
	if (A_Z_a_z_(*c->p)) {
	  if (!(name = zx_scan_elem_start(c, (const char*)__FUNCTION__)))
	    return x;
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
  zx_dec_reverse_lists(&x->gg);
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




/* EOF -- c/zx-md-dec.c */
