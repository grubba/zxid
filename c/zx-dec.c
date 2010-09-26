/* c/zx-dec.c - WARNING: This file was automatically generated. DO NOT EDIT!
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



/* FUNC(zx_DEC_root) */

#define EL_NAME   root
#define EL_STRUCT zx_root_s
#define EL_NS     
#define EL_TAG    root

/* Called by: */
struct zx_root_s* zx_DEC_root(struct zx_ctx* c, struct zx_ns_s* ns , int n_decode)
{
  int tok;
  struct zx_elem_s* iternode;
  struct zx_elem_s* el;
  struct zx_str* ss;
  struct zx_ns_s* pop_seen;
  const char* name;
  const char* data;
  struct zx_root_s* x = ZX_ZALLOC(c, struct zx_root_s);
  x->gg.g.tok = zx_root_ELEM;
  x->gg.g.ns = ns;
  ZX_START_DEC_EXT(x);



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
          case zx_sa_Assertion_ELEM:
            el = (struct zx_elem_s*)zx_DEC_sa_Assertion(c, ns);
            el->g.n = &x->Assertion->gg.g;
            x->Assertion = (struct zx_sa_Assertion_s*)el;
            break;
          case zx_sa_NameID_ELEM:
            el = (struct zx_elem_s*)zx_DEC_sa_NameID(c, ns);
            el->g.n = &x->NameID->gg.g;
            x->NameID = (struct zx_sa_NameID_s*)el;
            break;
          case zx_sp_NewID_ELEM:
            el = zx_DEC_simple_elem(c, ns, tok);
            el->g.n = &x->NewID->g;
            x->NewID = el;
            break;
          case zx_sp_AuthnRequest_ELEM:
            el = (struct zx_elem_s*)zx_DEC_sp_AuthnRequest(c, ns);
            el->g.n = &x->AuthnRequest->gg.g;
            x->AuthnRequest = (struct zx_sp_AuthnRequest_s*)el;
            break;
          case zx_sp_Response_ELEM:
            el = (struct zx_elem_s*)zx_DEC_sp_Response(c, ns);
            el->g.n = &x->Response->gg.g;
            x->Response = (struct zx_sp_Response_s*)el;
            break;
          case zx_sp_LogoutRequest_ELEM:
            el = (struct zx_elem_s*)zx_DEC_sp_LogoutRequest(c, ns);
            el->g.n = &x->LogoutRequest->gg.g;
            x->LogoutRequest = (struct zx_sp_LogoutRequest_s*)el;
            break;
          case zx_sp_LogoutResponse_ELEM:
            el = (struct zx_elem_s*)zx_DEC_sp_LogoutResponse(c, ns);
            el->g.n = &x->LogoutResponse->gg.g;
            x->LogoutResponse = (struct zx_sp_LogoutResponse_s*)el;
            break;
          case zx_sp_ManageNameIDRequest_ELEM:
            el = (struct zx_elem_s*)zx_DEC_sp_ManageNameIDRequest(c, ns);
            el->g.n = &x->ManageNameIDRequest->gg.g;
            x->ManageNameIDRequest = (struct zx_sp_ManageNameIDRequest_s*)el;
            break;
          case zx_sp_ManageNameIDResponse_ELEM:
            el = (struct zx_elem_s*)zx_DEC_sp_ManageNameIDResponse(c, ns);
            el->g.n = &x->ManageNameIDResponse->gg.g;
            x->ManageNameIDResponse = (struct zx_sp_ManageNameIDResponse_s*)el;
            break;
          case zx_e_Envelope_ELEM:
            el = (struct zx_elem_s*)zx_DEC_e_Envelope(c, ns);
            el->g.n = &x->Envelope->gg.g;
            x->Envelope = (struct zx_e_Envelope_s*)el;
            break;
          case zx_e_Header_ELEM:
            el = (struct zx_elem_s*)zx_DEC_e_Header(c, ns);
            el->g.n = &x->Header->gg.g;
            x->Header = (struct zx_e_Header_s*)el;
            break;
          case zx_e_Body_ELEM:
            el = (struct zx_elem_s*)zx_DEC_e_Body(c, ns);
            el->g.n = &x->Body->gg.g;
            x->Body = (struct zx_e_Body_s*)el;
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
          case zx_sa11_Assertion_ELEM:
            el = (struct zx_elem_s*)zx_DEC_sa11_Assertion(c, ns);
            el->g.n = &x->sa11_Assertion->gg.g;
            x->sa11_Assertion = (struct zx_sa11_Assertion_s*)el;
            break;
          case zx_sp11_Request_ELEM:
            el = (struct zx_elem_s*)zx_DEC_sp11_Request(c, ns);
            el->g.n = &x->Request->gg.g;
            x->Request = (struct zx_sp11_Request_s*)el;
            break;
          case zx_sp11_Response_ELEM:
            el = (struct zx_elem_s*)zx_DEC_sp11_Response(c, ns);
            el->g.n = &x->sp11_Response->gg.g;
            x->sp11_Response = (struct zx_sp11_Response_s*)el;
            break;
          case zx_ff12_Assertion_ELEM:
            el = (struct zx_elem_s*)zx_DEC_ff12_Assertion(c, ns);
            el->g.n = &x->ff12_Assertion->gg.g;
            x->ff12_Assertion = (struct zx_ff12_Assertion_s*)el;
            break;
          case zx_ff12_AuthnRequest_ELEM:
            el = (struct zx_elem_s*)zx_DEC_ff12_AuthnRequest(c, ns);
            el->g.n = &x->ff12_AuthnRequest->gg.g;
            x->ff12_AuthnRequest = (struct zx_ff12_AuthnRequest_s*)el;
            break;
          case zx_ff12_AuthnResponse_ELEM:
            el = (struct zx_elem_s*)zx_DEC_ff12_AuthnResponse(c, ns);
            el->g.n = &x->AuthnResponse->gg.g;
            x->AuthnResponse = (struct zx_ff12_AuthnResponse_s*)el;
            break;
          case zx_ff12_AuthnRequestEnvelope_ELEM:
            el = (struct zx_elem_s*)zx_DEC_ff12_AuthnRequestEnvelope(c, ns);
            el->g.n = &x->AuthnRequestEnvelope->gg.g;
            x->AuthnRequestEnvelope = (struct zx_ff12_AuthnRequestEnvelope_s*)el;
            break;
          case zx_ff12_AuthnResponseEnvelope_ELEM:
            el = (struct zx_elem_s*)zx_DEC_ff12_AuthnResponseEnvelope(c, ns);
            el->g.n = &x->AuthnResponseEnvelope->gg.g;
            x->AuthnResponseEnvelope = (struct zx_ff12_AuthnResponseEnvelope_s*)el;
            break;
          case zx_ff12_RegisterNameIdentifierRequest_ELEM:
            el = (struct zx_elem_s*)zx_DEC_ff12_RegisterNameIdentifierRequest(c, ns);
            el->g.n = &x->RegisterNameIdentifierRequest->gg.g;
            x->RegisterNameIdentifierRequest = (struct zx_ff12_RegisterNameIdentifierRequest_s*)el;
            break;
          case zx_ff12_RegisterNameIdentifierResponse_ELEM:
            el = (struct zx_elem_s*)zx_DEC_ff12_RegisterNameIdentifierResponse(c, ns);
            el->g.n = &x->RegisterNameIdentifierResponse->gg.g;
            x->RegisterNameIdentifierResponse = (struct zx_ff12_RegisterNameIdentifierResponse_s*)el;
            break;
          case zx_ff12_FederationTerminationNotification_ELEM:
            el = (struct zx_elem_s*)zx_DEC_ff12_FederationTerminationNotification(c, ns);
            el->g.n = &x->FederationTerminationNotification->gg.g;
            x->FederationTerminationNotification = (struct zx_ff12_FederationTerminationNotification_s*)el;
            break;
          case zx_ff12_LogoutRequest_ELEM:
            el = (struct zx_elem_s*)zx_DEC_ff12_LogoutRequest(c, ns);
            el->g.n = &x->ff12_LogoutRequest->gg.g;
            x->ff12_LogoutRequest = (struct zx_ff12_LogoutRequest_s*)el;
            break;
          case zx_ff12_LogoutResponse_ELEM:
            el = (struct zx_elem_s*)zx_DEC_ff12_LogoutResponse(c, ns);
            el->g.n = &x->ff12_LogoutResponse->gg.g;
            x->ff12_LogoutResponse = (struct zx_ff12_LogoutResponse_s*)el;
            break;
          case zx_ff12_NameIdentifierMappingRequest_ELEM:
            el = (struct zx_elem_s*)zx_DEC_ff12_NameIdentifierMappingRequest(c, ns);
            el->g.n = &x->NameIdentifierMappingRequest->gg.g;
            x->NameIdentifierMappingRequest = (struct zx_ff12_NameIdentifierMappingRequest_s*)el;
            break;
          case zx_ff12_NameIdentifierMappingResponse_ELEM:
            el = (struct zx_elem_s*)zx_DEC_ff12_NameIdentifierMappingResponse(c, ns);
            el->g.n = &x->NameIdentifierMappingResponse->gg.g;
            x->NameIdentifierMappingResponse = (struct zx_ff12_NameIdentifierMappingResponse_s*)el;
            break;
          case zx_m20_EntityDescriptor_ELEM:
            el = (struct zx_elem_s*)zx_DEC_m20_EntityDescriptor(c, ns);
            el->g.n = &x->m20_EntityDescriptor->gg.g;
            x->m20_EntityDescriptor = (struct zx_m20_EntityDescriptor_s*)el;
            break;
          case zx_m20_EntitiesDescriptor_ELEM:
            el = (struct zx_elem_s*)zx_DEC_m20_EntitiesDescriptor(c, ns);
            el->g.n = &x->m20_EntitiesDescriptor->gg.g;
            x->m20_EntitiesDescriptor = (struct zx_m20_EntitiesDescriptor_s*)el;
            break;
          case zx_a_EndpointReference_ELEM:
            el = (struct zx_elem_s*)zx_DEC_a_EndpointReference(c, ns);
            el->g.n = &x->EndpointReference->gg.g;
            x->EndpointReference = (struct zx_a_EndpointReference_s*)el;
            break;
          case zx_hrxml_Candidate_ELEM:
            el = (struct zx_elem_s*)zx_DEC_hrxml_Candidate(c, ns);
            el->g.n = &x->Candidate->gg.g;
            x->Candidate = (struct zx_hrxml_Candidate_s*)el;
            break;
          case zx_xasp_XACMLAuthzDecisionQuery_ELEM:
            el = (struct zx_elem_s*)zx_DEC_xasp_XACMLAuthzDecisionQuery(c, ns);
            el->g.n = &x->XACMLAuthzDecisionQuery->gg.g;
            x->XACMLAuthzDecisionQuery = (struct zx_xasp_XACMLAuthzDecisionQuery_s*)el;
            break;
          case zx_xasp_XACMLPolicyQuery_ELEM:
            el = (struct zx_elem_s*)zx_DEC_xasp_XACMLPolicyQuery(c, ns);
            el->g.n = &x->XACMLPolicyQuery->gg.g;
            x->XACMLPolicyQuery = (struct zx_xasp_XACMLPolicyQuery_s*)el;
            break;
          case zx_xaspcd1_XACMLAuthzDecisionQuery_ELEM:
            el = (struct zx_elem_s*)zx_DEC_xaspcd1_XACMLAuthzDecisionQuery(c, ns);
            el->g.n = &x->xaspcd1_XACMLAuthzDecisionQuery->gg.g;
            x->xaspcd1_XACMLAuthzDecisionQuery = (struct zx_xaspcd1_XACMLAuthzDecisionQuery_s*)el;
            break;
          case zx_xaspcd1_XACMLPolicyQuery_ELEM:
            el = (struct zx_elem_s*)zx_DEC_xaspcd1_XACMLPolicyQuery(c, ns);
            el->g.n = &x->xaspcd1_XACMLPolicyQuery->gg.g;
            x->xaspcd1_XACMLPolicyQuery = (struct zx_xaspcd1_XACMLPolicyQuery_s*)el;
            break;

	  default:
	    el = zx_known_or_unknown_elem(c, tok, &x->gg, c->p - name, name, ns);
	    tok = ZX_TOK_NOT_FOUND;
	    break;
	  }
          el->g.wo = &x->gg.kids->g;
          x->gg.kids = el;
	  zx_pop_seen(pop_seen);
	  if (--n_decode) { x->gg.g.tok = tok; return x; }
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






/* FUNC(zx_DEC_simple_elem) */

#define EL_NAME   simple_elem
#define EL_STRUCT zx_elem_s
#define EL_NS     
#define EL_TAG    simple_elem

/* Called by: */
struct zx_elem_s* zx_DEC_simple_elem(struct zx_ctx* c, struct zx_ns_s* ns , int toke)
{
  int tok;
  struct zx_elem_s* iternode;
  struct zx_elem_s* el;
  struct zx_str* ss;
  struct zx_ns_s* pop_seen;
  const char* name;
  const char* data;
  struct zx_elem_s* x = ZX_ZALLOC(c, struct zx_elem_s);
  x->g.tok = toke;
  x->g.ns = ns;
  ZX_START_DEC_EXT(x);

#if 1 /* NORMALMODE */
  ZX_DEC_TAG_NOT_YET_CLOSED(x->g);

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
      ss = zx_dec_unknown_attr(c, x, name, data, tok, x->g.tok);
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
      ZX_DEC_TAG_NOW_CLOSED(x->g);
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
	if (x->g.ns->prefix_len
	    ?(c->p - name - x->g.ns->prefix_len - 1 != namlen || memcmp(name+x->g.ns->prefix_len+1, nam, namlen))
	    :(c->p-name != namlen || memcmp(name, nam, namlen)))
#else
	tok = zx_elem_lookup(c, name, c->p, &ns);
	if (tok != x->g.tok)
#endif
	{
	  ERR("Mismatching close tag(%.*s) tok=%d context=%d", c->p-name, name, tok, x->g.tok);
	  zx_xml_parse_err(c, '-', (const char*)__FUNCTION__, "Mismatching close tag");
	  ZX_DEC_TAG_MISMATCH_CLOSE(x->g);
	  ++c->p;
	  return x;
	}
	/* Legitimate close tag. Normal exit from this function. */
	++c->p;
	ZX_DEC_TAG_NOW_CLOSED(x->g);
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
	    el = zx_known_or_unknown_elem(c, tok, x, c->p - name, name, ns);
	    tok = ZX_TOK_NOT_FOUND;
	    break;
	  }
          el->g.wo = &x->kids->g;
          x->kids = el;
	  zx_pop_seen(pop_seen);
	  
	  goto next_elem;
	}
      }
      /* false alarm <, fall thru */
    }
    if (!zx_scan_data(c, x))
      return x;
    goto potential_tag;
  }
 out:
  iternode = x->kids;
  REVERSE_LIST_NEXT(x->kids, iternode, g.wo);
  iternode = (struct zx_elem_s*)(x->any_elem);
  REVERSE_LIST_NEXT(x->any_elem, iternode, g.n);
  ss = (struct zx_str*)(x->any_attr);
  REVERSE_LIST_NEXT(x->any_attr, ss, g.n);
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






/* FUNC(zx_DEC_wrong_elem) */

#define EL_NAME   wrong_elem
#define EL_STRUCT zx_any_elem_s
#define EL_NS     
#define EL_TAG    wrong_elem

/* Called by: */
struct zx_any_elem_s* zx_DEC_wrong_elem(struct zx_ctx* c, struct zx_ns_s* ns , const char* nam, int namlen)
{
  int tok;
  struct zx_elem_s* iternode;
  struct zx_elem_s* el;
  struct zx_str* ss;
  struct zx_ns_s* pop_seen;
  const char* name;
  const char* data;
  struct zx_any_elem_s* x = ZX_ZALLOC(c, struct zx_any_elem_s);
  x->gg.g.tok = ZX_TOK_NOT_FOUND;
  x->name_len = namlen;
  x->name = nam;
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
#if 1
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






/* This subtemplate is only expanded once (i.e. not per element) */

/* FUNC(zx_known_or_unknown_elem) */

/* Called by:  zx_DEC_ELNAME */
struct zx_elem_s* zx_known_or_unknown_elem(struct zx_ctx* c, int tok, struct zx_elem_s* x, int len, const char* name, struct zx_ns_s* ns)
{
  const char* p;
  struct zx_elem_s* el;
  if (tok == ZX_TOK_NOT_FOUND) {
    D("Unknown element(%.*s) in context(%d)", len, name, x->g.tok);
  } else {
    D("Known element(%.*s) tok(%d) in wrong context(%d)", len, name, tok, x->g.tok);
  }
  for (p = name; p < name + len && *p != ':'; ++p) ;  /* look for namespace prefix */
  if (p < name + len) {
    /*prefix = name;*/
    len -= p+1-name;
    name = p+1;
  }
  el = (struct zx_elem_s*)zx_DEC_wrong_elem(c, ns, name, len);
  /*ZX_UNKNOWN_ELEM_DEC_EXT(el);*/
  el->g.n = &x->any_elem->gg.g;
  x->any_elem = (struct zx_any_elem_s*)el;
  return el;
}

/* FUNC(zx_attr_lookup) */

/* Tokenize a string.
 * Lookup functions to convert a namespace qualified string to an integer token.
 * One of each (attr and elem) is needed for every prefix used in code generation.
 * The ...2tok() functions come from code generation via gperf. */

/* Called by:  zx_DEC_ELNAME */
int zx_attr_lookup(struct zx_ctx* c, const char* name, const char* lim, struct zx_ns_s** ns)
{
  const struct zx_tok* zt;
  const char* prefix;
  const char* p;
  
  for (p = name; p < lim && *p != ':'; ++p) ;  /* look for namespace prefix */
  if (p < lim) {
    prefix = name;
    name = p+1;
  } else
    prefix = 0;

  if (prefix)
    *ns = zx_prefix_seen_whine(c, prefix ? (name-1)-prefix : 0, prefix, "zx_attr_lookup", 0);
  else
    *ns = 0;
  
  zt = zx_attr2tok(name, lim-name);
  if (!zt) {
    if (prefix ? ((name-1)-prefix == sizeof("xmlns")-1
		  && !memcmp("xmlns", prefix, sizeof("xmlns")-1))
	: (lim-name == sizeof("xmlns")-1
	   && !memcmp("xmlns", name, sizeof("xmlns")-1))) {
      /* Namespace declaration. Skip because these were prescanned (see ablec in this file). */
      return ZX_TOK_XMLNS;
    }
    return ZX_TOK_NOT_FOUND;
  }

  /* Look for token whose namespace matches. */
  zt = zx_tok_by_ns(zt, zx_attrs + sizeof(zx_attrs) / sizeof(struct zx_tok), lim-name, name, *ns);
  if (!zt)
    return ZX_TOK_NOT_FOUND;
  return zt - zx_attrs;
}

/* FUNC(zx_elem_lookup) */

/* Called by:  zx_DEC_ELNAME x2 */
int zx_elem_lookup(struct zx_ctx* c, const char* name, const char* lim, struct zx_ns_s** ns)
{
  const struct zx_tok* zt;
  const char* prefix;
  const char* p;
  
  for (p = name; p < lim && *p != ':'; ++p) ;  /* look for namespace prefix */
  if (p < lim) {
    prefix = name;
    name = p+1;
  } else
    prefix = 0;

  *ns = zx_prefix_seen_whine(c, prefix ? (name-1)-prefix : 0, prefix, "zx_elem_lookup", 1);

  zt = zx_elem2tok(name, lim-name);
  if (!zt)
    return ZX_TOK_NOT_FOUND;
  
  /* Look for token whose namespace matches. */
  zt = zx_tok_by_ns(zt, zx_elems + sizeof(zx_elems) / sizeof(struct zx_tok), lim-name, name, *ns);
  if (!zt)
    return ZX_TOK_NOT_FOUND;
  return zt - zx_elems;
}

/* EOF -- c/zx-dec.c */
