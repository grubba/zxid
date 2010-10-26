/** dec-templ.c  -  XML decoder template, used in code generation
 ** Copyright (c) 2010 Sampo Kellomaki (sampo@iki.fi), All Rights Reserved.
 ** Copyright (c) 2006-2007 Symlabs (symlabs@symlabs.com), All Rights Reserved.
 ** Author: Sampo Kellomaki (sampo@iki.fi)
 ** This is confidential unpublished proprietary source code of the author.
 ** NO WARRANTY, not even implied warranties. Contains trade secrets.
 ** Distribution prohibited unless authorized in writing.
 ** Licensed under Apache License 2.0, see file COPYING.
 ** $Id: dec-templ.c,v 1.30 2008-10-04 23:42:14 sampo Exp $
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

/* FUNC(TXDEC_ELNAME) */

#define EL_NAME   ELNAME
#define EL_STRUCT ELSTRUCT
#define EL_NS     ELNS
#define EL_TAG    ELTAG

/* Called by: */
struct ELSTRUCT* TXDEC_ELNAME(struct zx_ctx* c, struct zx_ns_s* ns ROOT_N_DECODE)
{
  int tok;
  struct zx_elem_s* el;
  struct zx_str* ss;
  struct zx_ns_s* pop_seen;
  const char* name;
  const char* data;
  struct ELSTRUCT* x = ZX_ZALLOC(c, struct ELSTRUCT);
  x->gg.g.tok = TXELNAME_ELEM;
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
    tok = TXattr_lookup(c, name, data-2, &ns);
    switch (tok) {
ATTRS;
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
	tok = TXelem_lookup(c, name, c->p, &ns);
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
	  tok = TXelem_lookup(c, name, c->p, &ns);
	  switch (tok) {
ELEMS;
	  default:
	    el = TXknown_or_unknown_elem(c, tok, &x->gg, c->p - name, name, ns);
	    tok = ZX_TOK_NOT_FOUND;
	    break;
	  }
          el->g.wo = &x->gg.kids->g;
          x->gg.kids = el;
	  zx_pop_seen(pop_seen);
	  ROOT_CHECK_N_DECODED;
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

#if 1 /* DEC_LOOKUP_SUBTEMPL */

/* This subtemplate is only expanded once (i.e. not per element) */

/* FUNC(TXknown_or_unknown_elem) */

/* Called by:  TXDEC_ELNAME */
struct zx_elem_s* TXknown_or_unknown_elem(struct zx_ctx* c, int tok, struct zx_elem_s* x, int len, const char* name, struct zx_ns_s* ns)
{
  const char* p;
  struct zx_elem_s* el;
  if (tok == ZX_TOK_NOT_FOUND) {
    D("Unknown element(%.*s) in context(%d)", len, name, x->g.tok);
  } else {
    D("Known element(%.*s) tok(%d) in wrong context(%d)", len, name, tok, x->g.tok);
  }
  p = memchr(name, ':', len);  /* look for namespace prefix */
  if (p) {
    /*prefix = name;*/
    len -= p+1-name;
    name = p+1;
  }
  el = (struct zx_elem_s*)TXDEC_wrong_elem(c, ns, name, len);
  /*ZX_UNKNOWN_ELEM_DEC_EXT(el);*/
  el->g.n = &x->any_elem->gg.g;
  x->any_elem = (struct zx_any_elem_s*)el;
  return el;
}

/* FUNC(TXattr_lookup) */

/* Tokenize a string.
 * Lookup functions to convert a namespace qualified string to an integer token.
 * One of each (attr and elem) is needed for every prefix used in code generation.
 * The ...2tok() functions come from code generation via gperf. */

/* Called by:  TXDEC_ELNAME */
int TXattr_lookup(struct zx_ctx* c, const char* name, const char* lim, struct zx_ns_s** ns)
{
  const struct zx_tok* zt;
  const char* prefix;
  const char* p;
  
  p = memchr(name, ':', lim-name);  /* look for namespace prefix */
  if (p) {
    prefix = name;
    name = p+1;
  } else
    prefix = 0;

  /* Look for namespace declaration. Skip as these were prescanned (see above in this file). */
  if (prefix) {
    if ((name-1)-prefix == sizeof("xmlns")-1 && !memcmp("xmlns", prefix, sizeof("xmlns")-1))
      return ZX_TOK_XMLNS;
    *ns = zx_prefix_seen_whine(c, prefix ? (name-1)-prefix : 0, prefix, "TXattr_lookup", 0);
  } else {
    if (lim-name == sizeof("xmlns")-1 && !memcmp("xmlns", name, sizeof("xmlns")-1))
      return ZX_TOK_XMLNS;
    *ns = 0;
  }
  
  zt = TXattr2tok(name, lim-name);
  if (!zt)
    return ZX_TOK_NOT_FOUND;

  /* Look for token whose namespace matches. */
  zt = zx_tok_by_ns(zt, TXattrs + sizeof(TXattrs) / sizeof(struct zx_tok), lim-name, name, *ns);
  if (!zt)
    return ZX_TOK_NOT_FOUND;
  return zt - TXattrs;
}

/* FUNC(TXelem_lookup) */

/* Called by:  TXDEC_ELNAME x2 */
int TXelem_lookup(struct zx_ctx* c, const char* name, const char* lim, struct zx_ns_s** ns)
{
  const struct zx_tok* zt;
  const char* prefix;
  const char* p;
  
  p = memchr(name, ':', lim-name);  /* look for namespace prefix */
  if (p) {
    prefix = name;
    name = p+1;
  } else
    prefix = 0;

  *ns = zx_prefix_seen_whine(c, prefix ? (name-1)-prefix : 0, prefix, "TXelem_lookup", 1);

  zt = TXelem2tok(name, lim-name);
  if (!zt)
    return ZX_TOK_NOT_FOUND;
  
  /* Look for token whose namespace matches. */
  zt = zx_tok_by_ns(zt, TXelems + sizeof(TXelems) / sizeof(struct zx_tok), lim-name, name, *ns);
  if (!zt)
    return ZX_TOK_NOT_FOUND;
  return zt - TXelems;
}

#endif

/* EOF */
