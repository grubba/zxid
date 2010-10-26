/* c/zx-ff12-dec.c - WARNING: This file was automatically generated. DO NOT EDIT!
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
#include "c/zx-ff12-data.h"

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



/* FUNC(zx_DEC_ff12_Assertion) */

#define EL_NAME   ff12_Assertion
#define EL_STRUCT zx_ff12_Assertion_s
#define EL_NS     ff12
#define EL_TAG    Assertion

/* Called by: */
struct zx_ff12_Assertion_s* zx_DEC_ff12_Assertion(struct zx_ctx* c, struct zx_ns_s* ns )
{
  int tok;
  struct zx_elem_s* el;
  struct zx_str* ss;
  struct zx_ns_s* pop_seen;
  const char* name;
  const char* data;
  struct zx_ff12_Assertion_s* x = ZX_ZALLOC(c, struct zx_ff12_Assertion_s);
  x->gg.g.tok = zx_ff12_Assertion_ELEM;
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
    case zx_AssertionID_ATTR:
      ss = ZX_ZALLOC(c, struct zx_str);
      ss->g.n = &x->AssertionID->g;
      x->AssertionID = ss;
      ZX_ATTR_DEC_EXT(ss);
      break;
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
    case zx_Issuer_ATTR:
      ss = ZX_ZALLOC(c, struct zx_str);
      ss->g.n = &x->Issuer->g;
      x->Issuer = ss;
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
          case zx_sa11_Conditions_ELEM:
            el = (struct zx_elem_s*)zx_DEC_sa11_Conditions(c, ns);
            el->g.n = &x->Conditions->gg.g;
            x->Conditions = (struct zx_sa11_Conditions_s*)el;
            break;
          case zx_sa11_Advice_ELEM:
            el = (struct zx_elem_s*)zx_DEC_sa11_Advice(c, ns);
            el->g.n = &x->Advice->gg.g;
            x->Advice = (struct zx_sa11_Advice_s*)el;
            break;
          case zx_sa11_Statement_ELEM:
            el = zx_DEC_simple_elem(c, ns, tok);
            el->g.n = &x->Statement->g;
            x->Statement = el;
            break;
          case zx_sa11_SubjectStatement_ELEM:
            el = (struct zx_elem_s*)zx_DEC_sa11_SubjectStatement(c, ns);
            el->g.n = &x->SubjectStatement->gg.g;
            x->SubjectStatement = (struct zx_sa11_SubjectStatement_s*)el;
            break;
          case zx_sa11_AuthenticationStatement_ELEM:
            el = (struct zx_elem_s*)zx_DEC_sa11_AuthenticationStatement(c, ns);
            el->g.n = &x->AuthenticationStatement->gg.g;
            x->AuthenticationStatement = (struct zx_sa11_AuthenticationStatement_s*)el;
            break;
          case zx_sa11_AuthorizationDecisionStatement_ELEM:
            el = (struct zx_elem_s*)zx_DEC_sa11_AuthorizationDecisionStatement(c, ns);
            el->g.n = &x->AuthorizationDecisionStatement->gg.g;
            x->AuthorizationDecisionStatement = (struct zx_sa11_AuthorizationDecisionStatement_s*)el;
            break;
          case zx_sa11_AttributeStatement_ELEM:
            el = (struct zx_elem_s*)zx_DEC_sa11_AttributeStatement(c, ns);
            el->g.n = &x->AttributeStatement->gg.g;
            x->AttributeStatement = (struct zx_sa11_AttributeStatement_s*)el;
            break;
          case zx_xasa_XACMLAuthzDecisionStatement_ELEM:
            el = (struct zx_elem_s*)zx_DEC_xasa_XACMLAuthzDecisionStatement(c, ns);
            el->g.n = &x->XACMLAuthzDecisionStatement->gg.g;
            x->XACMLAuthzDecisionStatement = (struct zx_xasa_XACMLAuthzDecisionStatement_s*)el;
            break;
          case zx_xasa_XACMLPolicyStatement_ELEM:
            el = (struct zx_elem_s*)zx_DEC_xasa_XACMLPolicyStatement(c, ns);
            el->g.n = &x->XACMLPolicyStatement->gg.g;
            x->XACMLPolicyStatement = (struct zx_xasa_XACMLPolicyStatement_s*)el;
            break;
          case zx_xasacd1_XACMLAuthzDecisionStatement_ELEM:
            el = (struct zx_elem_s*)zx_DEC_xasacd1_XACMLAuthzDecisionStatement(c, ns);
            el->g.n = &x->xasacd1_XACMLAuthzDecisionStatement->gg.g;
            x->xasacd1_XACMLAuthzDecisionStatement = (struct zx_xasacd1_XACMLAuthzDecisionStatement_s*)el;
            break;
          case zx_xasacd1_XACMLPolicyStatement_ELEM:
            el = (struct zx_elem_s*)zx_DEC_xasacd1_XACMLPolicyStatement(c, ns);
            el->g.n = &x->xasacd1_XACMLPolicyStatement->gg.g;
            x->xasacd1_XACMLPolicyStatement = (struct zx_xasacd1_XACMLPolicyStatement_s*)el;
            break;
          case zx_ds_Signature_ELEM:
            el = (struct zx_elem_s*)zx_DEC_ds_Signature(c, ns);
            el->g.n = &x->Signature->gg.g;
            x->Signature = (struct zx_ds_Signature_s*)el;
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






/* FUNC(zx_DEC_ff12_AuthenticationStatement) */

#define EL_NAME   ff12_AuthenticationStatement
#define EL_STRUCT zx_ff12_AuthenticationStatement_s
#define EL_NS     ff12
#define EL_TAG    AuthenticationStatement

/* Called by: */
struct zx_ff12_AuthenticationStatement_s* zx_DEC_ff12_AuthenticationStatement(struct zx_ctx* c, struct zx_ns_s* ns )
{
  int tok;
  struct zx_elem_s* el;
  struct zx_str* ss;
  struct zx_ns_s* pop_seen;
  const char* name;
  const char* data;
  struct zx_ff12_AuthenticationStatement_s* x = ZX_ZALLOC(c, struct zx_ff12_AuthenticationStatement_s);
  x->gg.g.tok = zx_ff12_AuthenticationStatement_ELEM;
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
    case zx_AuthenticationInstant_ATTR:
      ss = ZX_ZALLOC(c, struct zx_str);
      ss->g.n = &x->AuthenticationInstant->g;
      x->AuthenticationInstant = ss;
      ZX_ATTR_DEC_EXT(ss);
      break;
    case zx_AuthenticationMethod_ATTR:
      ss = ZX_ZALLOC(c, struct zx_str);
      ss->g.n = &x->AuthenticationMethod->g;
      x->AuthenticationMethod = ss;
      ZX_ATTR_DEC_EXT(ss);
      break;
    case zx_ReauthenticateOnOrAfter_ATTR:
      ss = ZX_ZALLOC(c, struct zx_str);
      ss->g.n = &x->ReauthenticateOnOrAfter->g;
      x->ReauthenticateOnOrAfter = ss;
      ZX_ATTR_DEC_EXT(ss);
      break;
    case zx_SessionIndex_ATTR:
      ss = ZX_ZALLOC(c, struct zx_str);
      ss->g.n = &x->SessionIndex->g;
      x->SessionIndex = ss;
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
          case zx_sa11_Subject_ELEM:
            el = (struct zx_elem_s*)zx_DEC_sa11_Subject(c, ns);
            el->g.n = &x->Subject->gg.g;
            x->Subject = (struct zx_sa11_Subject_s*)el;
            break;
          case zx_sa11_SubjectLocality_ELEM:
            el = (struct zx_elem_s*)zx_DEC_sa11_SubjectLocality(c, ns);
            el->g.n = &x->SubjectLocality->gg.g;
            x->SubjectLocality = (struct zx_sa11_SubjectLocality_s*)el;
            break;
          case zx_sa11_AuthorityBinding_ELEM:
            el = (struct zx_elem_s*)zx_DEC_sa11_AuthorityBinding(c, ns);
            el->g.n = &x->AuthorityBinding->gg.g;
            x->AuthorityBinding = (struct zx_sa11_AuthorityBinding_s*)el;
            break;
          case zx_ff12_AuthnContext_ELEM:
            el = (struct zx_elem_s*)zx_DEC_ff12_AuthnContext(c, ns);
            el->g.n = &x->AuthnContext->gg.g;
            x->AuthnContext = (struct zx_ff12_AuthnContext_s*)el;
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






/* FUNC(zx_DEC_ff12_AuthnContext) */

#define EL_NAME   ff12_AuthnContext
#define EL_STRUCT zx_ff12_AuthnContext_s
#define EL_NS     ff12
#define EL_TAG    AuthnContext

/* Called by: */
struct zx_ff12_AuthnContext_s* zx_DEC_ff12_AuthnContext(struct zx_ctx* c, struct zx_ns_s* ns )
{
  int tok;
  struct zx_elem_s* el;
  struct zx_str* ss;
  struct zx_ns_s* pop_seen;
  const char* name;
  const char* data;
  struct zx_ff12_AuthnContext_s* x = ZX_ZALLOC(c, struct zx_ff12_AuthnContext_s);
  x->gg.g.tok = zx_ff12_AuthnContext_ELEM;
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
          case zx_ff12_AuthnContextClassRef_ELEM:
            el = zx_DEC_simple_elem(c, ns, tok);
            el->g.n = &x->AuthnContextClassRef->g;
            x->AuthnContextClassRef = el;
            break;
          case zx_ac_AuthenticationContextStatement_ELEM:
            el = (struct zx_elem_s*)zx_DEC_ac_AuthenticationContextStatement(c, ns);
            el->g.n = &x->AuthenticationContextStatement->gg.g;
            x->AuthenticationContextStatement = (struct zx_ac_AuthenticationContextStatement_s*)el;
            break;
          case zx_ff12_AuthnContextStatementRef_ELEM:
            el = zx_DEC_simple_elem(c, ns, tok);
            el->g.n = &x->AuthnContextStatementRef->g;
            x->AuthnContextStatementRef = el;
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






/* FUNC(zx_DEC_ff12_AuthnRequest) */

#define EL_NAME   ff12_AuthnRequest
#define EL_STRUCT zx_ff12_AuthnRequest_s
#define EL_NS     ff12
#define EL_TAG    AuthnRequest

/* Called by: */
struct zx_ff12_AuthnRequest_s* zx_DEC_ff12_AuthnRequest(struct zx_ctx* c, struct zx_ns_s* ns )
{
  int tok;
  struct zx_elem_s* el;
  struct zx_str* ss;
  struct zx_ns_s* pop_seen;
  const char* name;
  const char* data;
  struct zx_ff12_AuthnRequest_s* x = ZX_ZALLOC(c, struct zx_ff12_AuthnRequest_s);
  x->gg.g.tok = zx_ff12_AuthnRequest_ELEM;
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
    case zx_consent_ATTR:
      ss = ZX_ZALLOC(c, struct zx_str);
      ss->g.n = &x->consent->g;
      x->consent = ss;
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
          case zx_ff12_Extension_ELEM:
            el = (struct zx_elem_s*)zx_DEC_ff12_Extension(c, ns);
            el->g.n = &x->Extension->gg.g;
            x->Extension = (struct zx_ff12_Extension_s*)el;
            break;
          case zx_ff12_ProviderID_ELEM:
            el = zx_DEC_simple_elem(c, ns, tok);
            el->g.n = &x->ProviderID->g;
            x->ProviderID = el;
            break;
          case zx_ff12_AffiliationID_ELEM:
            el = zx_DEC_simple_elem(c, ns, tok);
            el->g.n = &x->AffiliationID->g;
            x->AffiliationID = el;
            break;
          case zx_ff12_NameIDPolicy_ELEM:
            el = zx_DEC_simple_elem(c, ns, tok);
            el->g.n = &x->NameIDPolicy->g;
            x->NameIDPolicy = el;
            break;
          case zx_ff12_ForceAuthn_ELEM:
            el = zx_DEC_simple_elem(c, ns, tok);
            el->g.n = &x->ForceAuthn->g;
            x->ForceAuthn = el;
            break;
          case zx_ff12_IsPassive_ELEM:
            el = zx_DEC_simple_elem(c, ns, tok);
            el->g.n = &x->IsPassive->g;
            x->IsPassive = el;
            break;
          case zx_ff12_ProtocolProfile_ELEM:
            el = zx_DEC_simple_elem(c, ns, tok);
            el->g.n = &x->ProtocolProfile->g;
            x->ProtocolProfile = el;
            break;
          case zx_ff12_AssertionConsumerServiceID_ELEM:
            el = zx_DEC_simple_elem(c, ns, tok);
            el->g.n = &x->AssertionConsumerServiceID->g;
            x->AssertionConsumerServiceID = el;
            break;
          case zx_ff12_RequestAuthnContext_ELEM:
            el = (struct zx_elem_s*)zx_DEC_ff12_RequestAuthnContext(c, ns);
            el->g.n = &x->RequestAuthnContext->gg.g;
            x->RequestAuthnContext = (struct zx_ff12_RequestAuthnContext_s*)el;
            break;
          case zx_ff12_RelayState_ELEM:
            el = zx_DEC_simple_elem(c, ns, tok);
            el->g.n = &x->RelayState->g;
            x->RelayState = el;
            break;
          case zx_ff12_Scoping_ELEM:
            el = (struct zx_elem_s*)zx_DEC_ff12_Scoping(c, ns);
            el->g.n = &x->Scoping->gg.g;
            x->Scoping = (struct zx_ff12_Scoping_s*)el;
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






/* FUNC(zx_DEC_ff12_AuthnRequestEnvelope) */

#define EL_NAME   ff12_AuthnRequestEnvelope
#define EL_STRUCT zx_ff12_AuthnRequestEnvelope_s
#define EL_NS     ff12
#define EL_TAG    AuthnRequestEnvelope

/* Called by: */
struct zx_ff12_AuthnRequestEnvelope_s* zx_DEC_ff12_AuthnRequestEnvelope(struct zx_ctx* c, struct zx_ns_s* ns )
{
  int tok;
  struct zx_elem_s* el;
  struct zx_str* ss;
  struct zx_ns_s* pop_seen;
  const char* name;
  const char* data;
  struct zx_ff12_AuthnRequestEnvelope_s* x = ZX_ZALLOC(c, struct zx_ff12_AuthnRequestEnvelope_s);
  x->gg.g.tok = zx_ff12_AuthnRequestEnvelope_ELEM;
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
          case zx_ff12_Extension_ELEM:
            el = (struct zx_elem_s*)zx_DEC_ff12_Extension(c, ns);
            el->g.n = &x->Extension->gg.g;
            x->Extension = (struct zx_ff12_Extension_s*)el;
            break;
          case zx_ff12_AuthnRequest_ELEM:
            el = (struct zx_elem_s*)zx_DEC_ff12_AuthnRequest(c, ns);
            el->g.n = &x->AuthnRequest->gg.g;
            x->AuthnRequest = (struct zx_ff12_AuthnRequest_s*)el;
            break;
          case zx_ff12_ProviderID_ELEM:
            el = zx_DEC_simple_elem(c, ns, tok);
            el->g.n = &x->ProviderID->g;
            x->ProviderID = el;
            break;
          case zx_ff12_ProviderName_ELEM:
            el = zx_DEC_simple_elem(c, ns, tok);
            el->g.n = &x->ProviderName->g;
            x->ProviderName = el;
            break;
          case zx_ff12_AssertionConsumerServiceURL_ELEM:
            el = zx_DEC_simple_elem(c, ns, tok);
            el->g.n = &x->AssertionConsumerServiceURL->g;
            x->AssertionConsumerServiceURL = el;
            break;
          case zx_ff12_IDPList_ELEM:
            el = (struct zx_elem_s*)zx_DEC_ff12_IDPList(c, ns);
            el->g.n = &x->IDPList->gg.g;
            x->IDPList = (struct zx_ff12_IDPList_s*)el;
            break;
          case zx_ff12_IsPassive_ELEM:
            el = zx_DEC_simple_elem(c, ns, tok);
            el->g.n = &x->IsPassive->g;
            x->IsPassive = el;
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






/* FUNC(zx_DEC_ff12_AuthnResponse) */

#define EL_NAME   ff12_AuthnResponse
#define EL_STRUCT zx_ff12_AuthnResponse_s
#define EL_NS     ff12
#define EL_TAG    AuthnResponse

/* Called by: */
struct zx_ff12_AuthnResponse_s* zx_DEC_ff12_AuthnResponse(struct zx_ctx* c, struct zx_ns_s* ns )
{
  int tok;
  struct zx_elem_s* el;
  struct zx_str* ss;
  struct zx_ns_s* pop_seen;
  const char* name;
  const char* data;
  struct zx_ff12_AuthnResponse_s* x = ZX_ZALLOC(c, struct zx_ff12_AuthnResponse_s);
  x->gg.g.tok = zx_ff12_AuthnResponse_ELEM;
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
    case zx_consent_ATTR:
      ss = ZX_ZALLOC(c, struct zx_str);
      ss->g.n = &x->consent->g;
      x->consent = ss;
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
          case zx_ff12_Extension_ELEM:
            el = (struct zx_elem_s*)zx_DEC_ff12_Extension(c, ns);
            el->g.n = &x->Extension->gg.g;
            x->Extension = (struct zx_ff12_Extension_s*)el;
            break;
          case zx_ff12_ProviderID_ELEM:
            el = zx_DEC_simple_elem(c, ns, tok);
            el->g.n = &x->ProviderID->g;
            x->ProviderID = el;
            break;
          case zx_ff12_RelayState_ELEM:
            el = zx_DEC_simple_elem(c, ns, tok);
            el->g.n = &x->RelayState->g;
            x->RelayState = el;
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






/* FUNC(zx_DEC_ff12_AuthnResponseEnvelope) */

#define EL_NAME   ff12_AuthnResponseEnvelope
#define EL_STRUCT zx_ff12_AuthnResponseEnvelope_s
#define EL_NS     ff12
#define EL_TAG    AuthnResponseEnvelope

/* Called by: */
struct zx_ff12_AuthnResponseEnvelope_s* zx_DEC_ff12_AuthnResponseEnvelope(struct zx_ctx* c, struct zx_ns_s* ns )
{
  int tok;
  struct zx_elem_s* el;
  struct zx_str* ss;
  struct zx_ns_s* pop_seen;
  const char* name;
  const char* data;
  struct zx_ff12_AuthnResponseEnvelope_s* x = ZX_ZALLOC(c, struct zx_ff12_AuthnResponseEnvelope_s);
  x->gg.g.tok = zx_ff12_AuthnResponseEnvelope_ELEM;
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
          case zx_ff12_Extension_ELEM:
            el = (struct zx_elem_s*)zx_DEC_ff12_Extension(c, ns);
            el->g.n = &x->Extension->gg.g;
            x->Extension = (struct zx_ff12_Extension_s*)el;
            break;
          case zx_ff12_AuthnResponse_ELEM:
            el = (struct zx_elem_s*)zx_DEC_ff12_AuthnResponse(c, ns);
            el->g.n = &x->AuthnResponse->gg.g;
            x->AuthnResponse = (struct zx_ff12_AuthnResponse_s*)el;
            break;
          case zx_ff12_AssertionConsumerServiceURL_ELEM:
            el = zx_DEC_simple_elem(c, ns, tok);
            el->g.n = &x->AssertionConsumerServiceURL->g;
            x->AssertionConsumerServiceURL = el;
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






/* FUNC(zx_DEC_ff12_EncryptableNameIdentifier) */

#define EL_NAME   ff12_EncryptableNameIdentifier
#define EL_STRUCT zx_ff12_EncryptableNameIdentifier_s
#define EL_NS     ff12
#define EL_TAG    EncryptableNameIdentifier

/* Called by: */
struct zx_ff12_EncryptableNameIdentifier_s* zx_DEC_ff12_EncryptableNameIdentifier(struct zx_ctx* c, struct zx_ns_s* ns )
{
  int tok;
  struct zx_elem_s* el;
  struct zx_str* ss;
  struct zx_ns_s* pop_seen;
  const char* name;
  const char* data;
  struct zx_ff12_EncryptableNameIdentifier_s* x = ZX_ZALLOC(c, struct zx_ff12_EncryptableNameIdentifier_s);
  x->gg.g.tok = zx_ff12_EncryptableNameIdentifier_ELEM;
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
    case zx_Format_ATTR:
      ss = ZX_ZALLOC(c, struct zx_str);
      ss->g.n = &x->Format->g;
      x->Format = ss;
      ZX_ATTR_DEC_EXT(ss);
      break;
    case zx_IssueInstant_ATTR:
      ss = ZX_ZALLOC(c, struct zx_str);
      ss->g.n = &x->IssueInstant->g;
      x->IssueInstant = ss;
      ZX_ATTR_DEC_EXT(ss);
      break;
    case zx_NameQualifier_ATTR:
      ss = ZX_ZALLOC(c, struct zx_str);
      ss->g.n = &x->NameQualifier->g;
      x->NameQualifier = ss;
      ZX_ATTR_DEC_EXT(ss);
      break;
    case zx_Nonce_ATTR:
      ss = ZX_ZALLOC(c, struct zx_str);
      ss->g.n = &x->Nonce->g;
      x->Nonce = ss;
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






/* FUNC(zx_DEC_ff12_EncryptedNameIdentifier) */

#define EL_NAME   ff12_EncryptedNameIdentifier
#define EL_STRUCT zx_ff12_EncryptedNameIdentifier_s
#define EL_NS     ff12
#define EL_TAG    EncryptedNameIdentifier

/* Called by: */
struct zx_ff12_EncryptedNameIdentifier_s* zx_DEC_ff12_EncryptedNameIdentifier(struct zx_ctx* c, struct zx_ns_s* ns )
{
  int tok;
  struct zx_elem_s* el;
  struct zx_str* ss;
  struct zx_ns_s* pop_seen;
  const char* name;
  const char* data;
  struct zx_ff12_EncryptedNameIdentifier_s* x = ZX_ZALLOC(c, struct zx_ff12_EncryptedNameIdentifier_s);
  x->gg.g.tok = zx_ff12_EncryptedNameIdentifier_ELEM;
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
          case zx_xenc_EncryptedData_ELEM:
            el = (struct zx_elem_s*)zx_DEC_xenc_EncryptedData(c, ns);
            el->g.n = &x->EncryptedData->gg.g;
            x->EncryptedData = (struct zx_xenc_EncryptedData_s*)el;
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






/* FUNC(zx_DEC_ff12_Extension) */

#define EL_NAME   ff12_Extension
#define EL_STRUCT zx_ff12_Extension_s
#define EL_NS     ff12
#define EL_TAG    Extension

/* Called by: */
struct zx_ff12_Extension_s* zx_DEC_ff12_Extension(struct zx_ctx* c, struct zx_ns_s* ns )
{
  int tok;
  struct zx_elem_s* el;
  struct zx_str* ss;
  struct zx_ns_s* pop_seen;
  const char* name;
  const char* data;
  struct zx_ff12_Extension_s* x = ZX_ZALLOC(c, struct zx_ff12_Extension_s);
  x->gg.g.tok = zx_ff12_Extension_ELEM;
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






/* FUNC(zx_DEC_ff12_FederationTerminationNotification) */

#define EL_NAME   ff12_FederationTerminationNotification
#define EL_STRUCT zx_ff12_FederationTerminationNotification_s
#define EL_NS     ff12
#define EL_TAG    FederationTerminationNotification

/* Called by: */
struct zx_ff12_FederationTerminationNotification_s* zx_DEC_ff12_FederationTerminationNotification(struct zx_ctx* c, struct zx_ns_s* ns )
{
  int tok;
  struct zx_elem_s* el;
  struct zx_str* ss;
  struct zx_ns_s* pop_seen;
  const char* name;
  const char* data;
  struct zx_ff12_FederationTerminationNotification_s* x = ZX_ZALLOC(c, struct zx_ff12_FederationTerminationNotification_s);
  x->gg.g.tok = zx_ff12_FederationTerminationNotification_ELEM;
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
    case zx_consent_ATTR:
      ss = ZX_ZALLOC(c, struct zx_str);
      ss->g.n = &x->consent->g;
      x->consent = ss;
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
          case zx_ff12_Extension_ELEM:
            el = (struct zx_elem_s*)zx_DEC_ff12_Extension(c, ns);
            el->g.n = &x->Extension->gg.g;
            x->Extension = (struct zx_ff12_Extension_s*)el;
            break;
          case zx_ff12_ProviderID_ELEM:
            el = zx_DEC_simple_elem(c, ns, tok);
            el->g.n = &x->ProviderID->g;
            x->ProviderID = el;
            break;
          case zx_sa11_NameIdentifier_ELEM:
            el = (struct zx_elem_s*)zx_DEC_sa11_NameIdentifier(c, ns);
            el->g.n = &x->NameIdentifier->gg.g;
            x->NameIdentifier = (struct zx_sa11_NameIdentifier_s*)el;
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






/* FUNC(zx_DEC_ff12_IDPEntries) */

#define EL_NAME   ff12_IDPEntries
#define EL_STRUCT zx_ff12_IDPEntries_s
#define EL_NS     ff12
#define EL_TAG    IDPEntries

/* Called by: */
struct zx_ff12_IDPEntries_s* zx_DEC_ff12_IDPEntries(struct zx_ctx* c, struct zx_ns_s* ns )
{
  int tok;
  struct zx_elem_s* el;
  struct zx_str* ss;
  struct zx_ns_s* pop_seen;
  const char* name;
  const char* data;
  struct zx_ff12_IDPEntries_s* x = ZX_ZALLOC(c, struct zx_ff12_IDPEntries_s);
  x->gg.g.tok = zx_ff12_IDPEntries_ELEM;
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
          case zx_ff12_IDPEntry_ELEM:
            el = (struct zx_elem_s*)zx_DEC_ff12_IDPEntry(c, ns);
            el->g.n = &x->IDPEntry->gg.g;
            x->IDPEntry = (struct zx_ff12_IDPEntry_s*)el;
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






/* FUNC(zx_DEC_ff12_IDPEntry) */

#define EL_NAME   ff12_IDPEntry
#define EL_STRUCT zx_ff12_IDPEntry_s
#define EL_NS     ff12
#define EL_TAG    IDPEntry

/* Called by: */
struct zx_ff12_IDPEntry_s* zx_DEC_ff12_IDPEntry(struct zx_ctx* c, struct zx_ns_s* ns )
{
  int tok;
  struct zx_elem_s* el;
  struct zx_str* ss;
  struct zx_ns_s* pop_seen;
  const char* name;
  const char* data;
  struct zx_ff12_IDPEntry_s* x = ZX_ZALLOC(c, struct zx_ff12_IDPEntry_s);
  x->gg.g.tok = zx_ff12_IDPEntry_ELEM;
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
          case zx_ff12_ProviderID_ELEM:
            el = zx_DEC_simple_elem(c, ns, tok);
            el->g.n = &x->ProviderID->g;
            x->ProviderID = el;
            break;
          case zx_ff12_ProviderName_ELEM:
            el = zx_DEC_simple_elem(c, ns, tok);
            el->g.n = &x->ProviderName->g;
            x->ProviderName = el;
            break;
          case zx_ff12_Loc_ELEM:
            el = zx_DEC_simple_elem(c, ns, tok);
            el->g.n = &x->Loc->g;
            x->Loc = el;
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






/* FUNC(zx_DEC_ff12_IDPList) */

#define EL_NAME   ff12_IDPList
#define EL_STRUCT zx_ff12_IDPList_s
#define EL_NS     ff12
#define EL_TAG    IDPList

/* Called by: */
struct zx_ff12_IDPList_s* zx_DEC_ff12_IDPList(struct zx_ctx* c, struct zx_ns_s* ns )
{
  int tok;
  struct zx_elem_s* el;
  struct zx_str* ss;
  struct zx_ns_s* pop_seen;
  const char* name;
  const char* data;
  struct zx_ff12_IDPList_s* x = ZX_ZALLOC(c, struct zx_ff12_IDPList_s);
  x->gg.g.tok = zx_ff12_IDPList_ELEM;
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
          case zx_ff12_IDPEntries_ELEM:
            el = (struct zx_elem_s*)zx_DEC_ff12_IDPEntries(c, ns);
            el->g.n = &x->IDPEntries->gg.g;
            x->IDPEntries = (struct zx_ff12_IDPEntries_s*)el;
            break;
          case zx_ff12_GetComplete_ELEM:
            el = zx_DEC_simple_elem(c, ns, tok);
            el->g.n = &x->GetComplete->g;
            x->GetComplete = el;
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






/* FUNC(zx_DEC_ff12_IDPProvidedNameIdentifier) */

#define EL_NAME   ff12_IDPProvidedNameIdentifier
#define EL_STRUCT zx_ff12_IDPProvidedNameIdentifier_s
#define EL_NS     ff12
#define EL_TAG    IDPProvidedNameIdentifier

/* Called by: */
struct zx_ff12_IDPProvidedNameIdentifier_s* zx_DEC_ff12_IDPProvidedNameIdentifier(struct zx_ctx* c, struct zx_ns_s* ns )
{
  int tok;
  struct zx_elem_s* el;
  struct zx_str* ss;
  struct zx_ns_s* pop_seen;
  const char* name;
  const char* data;
  struct zx_ff12_IDPProvidedNameIdentifier_s* x = ZX_ZALLOC(c, struct zx_ff12_IDPProvidedNameIdentifier_s);
  x->gg.g.tok = zx_ff12_IDPProvidedNameIdentifier_ELEM;
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
    case zx_Format_ATTR:
      ss = ZX_ZALLOC(c, struct zx_str);
      ss->g.n = &x->Format->g;
      x->Format = ss;
      ZX_ATTR_DEC_EXT(ss);
      break;
    case zx_NameQualifier_ATTR:
      ss = ZX_ZALLOC(c, struct zx_str);
      ss->g.n = &x->NameQualifier->g;
      x->NameQualifier = ss;
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






/* FUNC(zx_DEC_ff12_LogoutRequest) */

#define EL_NAME   ff12_LogoutRequest
#define EL_STRUCT zx_ff12_LogoutRequest_s
#define EL_NS     ff12
#define EL_TAG    LogoutRequest

/* Called by: */
struct zx_ff12_LogoutRequest_s* zx_DEC_ff12_LogoutRequest(struct zx_ctx* c, struct zx_ns_s* ns )
{
  int tok;
  struct zx_elem_s* el;
  struct zx_str* ss;
  struct zx_ns_s* pop_seen;
  const char* name;
  const char* data;
  struct zx_ff12_LogoutRequest_s* x = ZX_ZALLOC(c, struct zx_ff12_LogoutRequest_s);
  x->gg.g.tok = zx_ff12_LogoutRequest_ELEM;
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
    case zx_NotOnOrAfter_ATTR:
      ss = ZX_ZALLOC(c, struct zx_str);
      ss->g.n = &x->NotOnOrAfter->g;
      x->NotOnOrAfter = ss;
      ZX_ATTR_DEC_EXT(ss);
      break;
    case zx_RequestID_ATTR:
      ss = ZX_ZALLOC(c, struct zx_str);
      ss->g.n = &x->RequestID->g;
      x->RequestID = ss;
      ZX_ATTR_DEC_EXT(ss);
      break;
    case zx_consent_ATTR:
      ss = ZX_ZALLOC(c, struct zx_str);
      ss->g.n = &x->consent->g;
      x->consent = ss;
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
          case zx_ff12_Extension_ELEM:
            el = (struct zx_elem_s*)zx_DEC_ff12_Extension(c, ns);
            el->g.n = &x->Extension->gg.g;
            x->Extension = (struct zx_ff12_Extension_s*)el;
            break;
          case zx_ff12_ProviderID_ELEM:
            el = zx_DEC_simple_elem(c, ns, tok);
            el->g.n = &x->ProviderID->g;
            x->ProviderID = el;
            break;
          case zx_sa11_NameIdentifier_ELEM:
            el = (struct zx_elem_s*)zx_DEC_sa11_NameIdentifier(c, ns);
            el->g.n = &x->NameIdentifier->gg.g;
            x->NameIdentifier = (struct zx_sa11_NameIdentifier_s*)el;
            break;
          case zx_ff12_SessionIndex_ELEM:
            el = zx_DEC_simple_elem(c, ns, tok);
            el->g.n = &x->SessionIndex->g;
            x->SessionIndex = el;
            break;
          case zx_ff12_RelayState_ELEM:
            el = zx_DEC_simple_elem(c, ns, tok);
            el->g.n = &x->RelayState->g;
            x->RelayState = el;
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






/* FUNC(zx_DEC_ff12_LogoutResponse) */

#define EL_NAME   ff12_LogoutResponse
#define EL_STRUCT zx_ff12_LogoutResponse_s
#define EL_NS     ff12
#define EL_TAG    LogoutResponse

/* Called by: */
struct zx_ff12_LogoutResponse_s* zx_DEC_ff12_LogoutResponse(struct zx_ctx* c, struct zx_ns_s* ns )
{
  int tok;
  struct zx_elem_s* el;
  struct zx_str* ss;
  struct zx_ns_s* pop_seen;
  const char* name;
  const char* data;
  struct zx_ff12_LogoutResponse_s* x = ZX_ZALLOC(c, struct zx_ff12_LogoutResponse_s);
  x->gg.g.tok = zx_ff12_LogoutResponse_ELEM;
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
          case zx_ff12_Extension_ELEM:
            el = (struct zx_elem_s*)zx_DEC_ff12_Extension(c, ns);
            el->g.n = &x->Extension->gg.g;
            x->Extension = (struct zx_ff12_Extension_s*)el;
            break;
          case zx_ff12_ProviderID_ELEM:
            el = zx_DEC_simple_elem(c, ns, tok);
            el->g.n = &x->ProviderID->g;
            x->ProviderID = el;
            break;
          case zx_sp11_Status_ELEM:
            el = (struct zx_elem_s*)zx_DEC_sp11_Status(c, ns);
            el->g.n = &x->Status->gg.g;
            x->Status = (struct zx_sp11_Status_s*)el;
            break;
          case zx_ff12_RelayState_ELEM:
            el = zx_DEC_simple_elem(c, ns, tok);
            el->g.n = &x->RelayState->g;
            x->RelayState = el;
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






/* FUNC(zx_DEC_ff12_NameIdentifierMappingRequest) */

#define EL_NAME   ff12_NameIdentifierMappingRequest
#define EL_STRUCT zx_ff12_NameIdentifierMappingRequest_s
#define EL_NS     ff12
#define EL_TAG    NameIdentifierMappingRequest

/* Called by: */
struct zx_ff12_NameIdentifierMappingRequest_s* zx_DEC_ff12_NameIdentifierMappingRequest(struct zx_ctx* c, struct zx_ns_s* ns )
{
  int tok;
  struct zx_elem_s* el;
  struct zx_str* ss;
  struct zx_ns_s* pop_seen;
  const char* name;
  const char* data;
  struct zx_ff12_NameIdentifierMappingRequest_s* x = ZX_ZALLOC(c, struct zx_ff12_NameIdentifierMappingRequest_s);
  x->gg.g.tok = zx_ff12_NameIdentifierMappingRequest_ELEM;
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
    case zx_consent_ATTR:
      ss = ZX_ZALLOC(c, struct zx_str);
      ss->g.n = &x->consent->g;
      x->consent = ss;
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
          case zx_ff12_Extension_ELEM:
            el = (struct zx_elem_s*)zx_DEC_ff12_Extension(c, ns);
            el->g.n = &x->Extension->gg.g;
            x->Extension = (struct zx_ff12_Extension_s*)el;
            break;
          case zx_ff12_ProviderID_ELEM:
            el = zx_DEC_simple_elem(c, ns, tok);
            el->g.n = &x->ProviderID->g;
            x->ProviderID = el;
            break;
          case zx_sa11_NameIdentifier_ELEM:
            el = (struct zx_elem_s*)zx_DEC_sa11_NameIdentifier(c, ns);
            el->g.n = &x->NameIdentifier->gg.g;
            x->NameIdentifier = (struct zx_sa11_NameIdentifier_s*)el;
            break;
          case zx_ff12_TargetNamespace_ELEM:
            el = zx_DEC_simple_elem(c, ns, tok);
            el->g.n = &x->TargetNamespace->g;
            x->TargetNamespace = el;
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






/* FUNC(zx_DEC_ff12_NameIdentifierMappingResponse) */

#define EL_NAME   ff12_NameIdentifierMappingResponse
#define EL_STRUCT zx_ff12_NameIdentifierMappingResponse_s
#define EL_NS     ff12
#define EL_TAG    NameIdentifierMappingResponse

/* Called by: */
struct zx_ff12_NameIdentifierMappingResponse_s* zx_DEC_ff12_NameIdentifierMappingResponse(struct zx_ctx* c, struct zx_ns_s* ns )
{
  int tok;
  struct zx_elem_s* el;
  struct zx_str* ss;
  struct zx_ns_s* pop_seen;
  const char* name;
  const char* data;
  struct zx_ff12_NameIdentifierMappingResponse_s* x = ZX_ZALLOC(c, struct zx_ff12_NameIdentifierMappingResponse_s);
  x->gg.g.tok = zx_ff12_NameIdentifierMappingResponse_ELEM;
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
          case zx_ff12_Extension_ELEM:
            el = (struct zx_elem_s*)zx_DEC_ff12_Extension(c, ns);
            el->g.n = &x->Extension->gg.g;
            x->Extension = (struct zx_ff12_Extension_s*)el;
            break;
          case zx_ff12_ProviderID_ELEM:
            el = zx_DEC_simple_elem(c, ns, tok);
            el->g.n = &x->ProviderID->g;
            x->ProviderID = el;
            break;
          case zx_sp11_Status_ELEM:
            el = (struct zx_elem_s*)zx_DEC_sp11_Status(c, ns);
            el->g.n = &x->Status->gg.g;
            x->Status = (struct zx_sp11_Status_s*)el;
            break;
          case zx_sa11_NameIdentifier_ELEM:
            el = (struct zx_elem_s*)zx_DEC_sa11_NameIdentifier(c, ns);
            el->g.n = &x->NameIdentifier->gg.g;
            x->NameIdentifier = (struct zx_sa11_NameIdentifier_s*)el;
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






/* FUNC(zx_DEC_ff12_OldProvidedNameIdentifier) */

#define EL_NAME   ff12_OldProvidedNameIdentifier
#define EL_STRUCT zx_ff12_OldProvidedNameIdentifier_s
#define EL_NS     ff12
#define EL_TAG    OldProvidedNameIdentifier

/* Called by: */
struct zx_ff12_OldProvidedNameIdentifier_s* zx_DEC_ff12_OldProvidedNameIdentifier(struct zx_ctx* c, struct zx_ns_s* ns )
{
  int tok;
  struct zx_elem_s* el;
  struct zx_str* ss;
  struct zx_ns_s* pop_seen;
  const char* name;
  const char* data;
  struct zx_ff12_OldProvidedNameIdentifier_s* x = ZX_ZALLOC(c, struct zx_ff12_OldProvidedNameIdentifier_s);
  x->gg.g.tok = zx_ff12_OldProvidedNameIdentifier_ELEM;
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
    case zx_Format_ATTR:
      ss = ZX_ZALLOC(c, struct zx_str);
      ss->g.n = &x->Format->g;
      x->Format = ss;
      ZX_ATTR_DEC_EXT(ss);
      break;
    case zx_NameQualifier_ATTR:
      ss = ZX_ZALLOC(c, struct zx_str);
      ss->g.n = &x->NameQualifier->g;
      x->NameQualifier = ss;
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






/* FUNC(zx_DEC_ff12_RegisterNameIdentifierRequest) */

#define EL_NAME   ff12_RegisterNameIdentifierRequest
#define EL_STRUCT zx_ff12_RegisterNameIdentifierRequest_s
#define EL_NS     ff12
#define EL_TAG    RegisterNameIdentifierRequest

/* Called by: */
struct zx_ff12_RegisterNameIdentifierRequest_s* zx_DEC_ff12_RegisterNameIdentifierRequest(struct zx_ctx* c, struct zx_ns_s* ns )
{
  int tok;
  struct zx_elem_s* el;
  struct zx_str* ss;
  struct zx_ns_s* pop_seen;
  const char* name;
  const char* data;
  struct zx_ff12_RegisterNameIdentifierRequest_s* x = ZX_ZALLOC(c, struct zx_ff12_RegisterNameIdentifierRequest_s);
  x->gg.g.tok = zx_ff12_RegisterNameIdentifierRequest_ELEM;
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
          case zx_ff12_Extension_ELEM:
            el = (struct zx_elem_s*)zx_DEC_ff12_Extension(c, ns);
            el->g.n = &x->Extension->gg.g;
            x->Extension = (struct zx_ff12_Extension_s*)el;
            break;
          case zx_ff12_ProviderID_ELEM:
            el = zx_DEC_simple_elem(c, ns, tok);
            el->g.n = &x->ProviderID->g;
            x->ProviderID = el;
            break;
          case zx_ff12_IDPProvidedNameIdentifier_ELEM:
            el = (struct zx_elem_s*)zx_DEC_ff12_IDPProvidedNameIdentifier(c, ns);
            el->g.n = &x->IDPProvidedNameIdentifier->gg.g;
            x->IDPProvidedNameIdentifier = (struct zx_ff12_IDPProvidedNameIdentifier_s*)el;
            break;
          case zx_ff12_SPProvidedNameIdentifier_ELEM:
            el = (struct zx_elem_s*)zx_DEC_ff12_SPProvidedNameIdentifier(c, ns);
            el->g.n = &x->SPProvidedNameIdentifier->gg.g;
            x->SPProvidedNameIdentifier = (struct zx_ff12_SPProvidedNameIdentifier_s*)el;
            break;
          case zx_ff12_OldProvidedNameIdentifier_ELEM:
            el = (struct zx_elem_s*)zx_DEC_ff12_OldProvidedNameIdentifier(c, ns);
            el->g.n = &x->OldProvidedNameIdentifier->gg.g;
            x->OldProvidedNameIdentifier = (struct zx_ff12_OldProvidedNameIdentifier_s*)el;
            break;
          case zx_ff12_RelayState_ELEM:
            el = zx_DEC_simple_elem(c, ns, tok);
            el->g.n = &x->RelayState->g;
            x->RelayState = el;
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






/* FUNC(zx_DEC_ff12_RegisterNameIdentifierResponse) */

#define EL_NAME   ff12_RegisterNameIdentifierResponse
#define EL_STRUCT zx_ff12_RegisterNameIdentifierResponse_s
#define EL_NS     ff12
#define EL_TAG    RegisterNameIdentifierResponse

/* Called by: */
struct zx_ff12_RegisterNameIdentifierResponse_s* zx_DEC_ff12_RegisterNameIdentifierResponse(struct zx_ctx* c, struct zx_ns_s* ns )
{
  int tok;
  struct zx_elem_s* el;
  struct zx_str* ss;
  struct zx_ns_s* pop_seen;
  const char* name;
  const char* data;
  struct zx_ff12_RegisterNameIdentifierResponse_s* x = ZX_ZALLOC(c, struct zx_ff12_RegisterNameIdentifierResponse_s);
  x->gg.g.tok = zx_ff12_RegisterNameIdentifierResponse_ELEM;
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
          case zx_ff12_Extension_ELEM:
            el = (struct zx_elem_s*)zx_DEC_ff12_Extension(c, ns);
            el->g.n = &x->Extension->gg.g;
            x->Extension = (struct zx_ff12_Extension_s*)el;
            break;
          case zx_ff12_ProviderID_ELEM:
            el = zx_DEC_simple_elem(c, ns, tok);
            el->g.n = &x->ProviderID->g;
            x->ProviderID = el;
            break;
          case zx_sp11_Status_ELEM:
            el = (struct zx_elem_s*)zx_DEC_sp11_Status(c, ns);
            el->g.n = &x->Status->gg.g;
            x->Status = (struct zx_sp11_Status_s*)el;
            break;
          case zx_ff12_RelayState_ELEM:
            el = zx_DEC_simple_elem(c, ns, tok);
            el->g.n = &x->RelayState->g;
            x->RelayState = el;
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






/* FUNC(zx_DEC_ff12_RequestAuthnContext) */

#define EL_NAME   ff12_RequestAuthnContext
#define EL_STRUCT zx_ff12_RequestAuthnContext_s
#define EL_NS     ff12
#define EL_TAG    RequestAuthnContext

/* Called by: */
struct zx_ff12_RequestAuthnContext_s* zx_DEC_ff12_RequestAuthnContext(struct zx_ctx* c, struct zx_ns_s* ns )
{
  int tok;
  struct zx_elem_s* el;
  struct zx_str* ss;
  struct zx_ns_s* pop_seen;
  const char* name;
  const char* data;
  struct zx_ff12_RequestAuthnContext_s* x = ZX_ZALLOC(c, struct zx_ff12_RequestAuthnContext_s);
  x->gg.g.tok = zx_ff12_RequestAuthnContext_ELEM;
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
          case zx_ff12_AuthnContextClassRef_ELEM:
            el = zx_DEC_simple_elem(c, ns, tok);
            el->g.n = &x->AuthnContextClassRef->g;
            x->AuthnContextClassRef = el;
            break;
          case zx_ff12_AuthnContextStatementRef_ELEM:
            el = zx_DEC_simple_elem(c, ns, tok);
            el->g.n = &x->AuthnContextStatementRef->g;
            x->AuthnContextStatementRef = el;
            break;
          case zx_ff12_AuthnContextComparison_ELEM:
            el = zx_DEC_simple_elem(c, ns, tok);
            el->g.n = &x->AuthnContextComparison->g;
            x->AuthnContextComparison = el;
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






/* FUNC(zx_DEC_ff12_SPProvidedNameIdentifier) */

#define EL_NAME   ff12_SPProvidedNameIdentifier
#define EL_STRUCT zx_ff12_SPProvidedNameIdentifier_s
#define EL_NS     ff12
#define EL_TAG    SPProvidedNameIdentifier

/* Called by: */
struct zx_ff12_SPProvidedNameIdentifier_s* zx_DEC_ff12_SPProvidedNameIdentifier(struct zx_ctx* c, struct zx_ns_s* ns )
{
  int tok;
  struct zx_elem_s* el;
  struct zx_str* ss;
  struct zx_ns_s* pop_seen;
  const char* name;
  const char* data;
  struct zx_ff12_SPProvidedNameIdentifier_s* x = ZX_ZALLOC(c, struct zx_ff12_SPProvidedNameIdentifier_s);
  x->gg.g.tok = zx_ff12_SPProvidedNameIdentifier_ELEM;
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
    case zx_Format_ATTR:
      ss = ZX_ZALLOC(c, struct zx_str);
      ss->g.n = &x->Format->g;
      x->Format = ss;
      ZX_ATTR_DEC_EXT(ss);
      break;
    case zx_NameQualifier_ATTR:
      ss = ZX_ZALLOC(c, struct zx_str);
      ss->g.n = &x->NameQualifier->g;
      x->NameQualifier = ss;
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






/* FUNC(zx_DEC_ff12_Scoping) */

#define EL_NAME   ff12_Scoping
#define EL_STRUCT zx_ff12_Scoping_s
#define EL_NS     ff12
#define EL_TAG    Scoping

/* Called by: */
struct zx_ff12_Scoping_s* zx_DEC_ff12_Scoping(struct zx_ctx* c, struct zx_ns_s* ns )
{
  int tok;
  struct zx_elem_s* el;
  struct zx_str* ss;
  struct zx_ns_s* pop_seen;
  const char* name;
  const char* data;
  struct zx_ff12_Scoping_s* x = ZX_ZALLOC(c, struct zx_ff12_Scoping_s);
  x->gg.g.tok = zx_ff12_Scoping_ELEM;
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
          case zx_ff12_ProxyCount_ELEM:
            el = zx_DEC_simple_elem(c, ns, tok);
            el->g.n = &x->ProxyCount->g;
            x->ProxyCount = el;
            break;
          case zx_ff12_IDPList_ELEM:
            el = (struct zx_elem_s*)zx_DEC_ff12_IDPList(c, ns);
            el->g.n = &x->IDPList->gg.g;
            x->IDPList = (struct zx_ff12_IDPList_s*)el;
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






/* FUNC(zx_DEC_ff12_Subject) */

#define EL_NAME   ff12_Subject
#define EL_STRUCT zx_ff12_Subject_s
#define EL_NS     ff12
#define EL_TAG    Subject

/* Called by: */
struct zx_ff12_Subject_s* zx_DEC_ff12_Subject(struct zx_ctx* c, struct zx_ns_s* ns )
{
  int tok;
  struct zx_elem_s* el;
  struct zx_str* ss;
  struct zx_ns_s* pop_seen;
  const char* name;
  const char* data;
  struct zx_ff12_Subject_s* x = ZX_ZALLOC(c, struct zx_ff12_Subject_s);
  x->gg.g.tok = zx_ff12_Subject_ELEM;
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
          case zx_sa11_NameIdentifier_ELEM:
            el = (struct zx_elem_s*)zx_DEC_sa11_NameIdentifier(c, ns);
            el->g.n = &x->NameIdentifier->gg.g;
            x->NameIdentifier = (struct zx_sa11_NameIdentifier_s*)el;
            break;
          case zx_sa11_SubjectConfirmation_ELEM:
            el = (struct zx_elem_s*)zx_DEC_sa11_SubjectConfirmation(c, ns);
            el->g.n = &x->SubjectConfirmation->gg.g;
            x->SubjectConfirmation = (struct zx_sa11_SubjectConfirmation_s*)el;
            break;
          case zx_ff12_IDPProvidedNameIdentifier_ELEM:
            el = (struct zx_elem_s*)zx_DEC_ff12_IDPProvidedNameIdentifier(c, ns);
            el->g.n = &x->IDPProvidedNameIdentifier->gg.g;
            x->IDPProvidedNameIdentifier = (struct zx_ff12_IDPProvidedNameIdentifier_s*)el;
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




/* EOF -- c/zx-ff12-dec.c */
