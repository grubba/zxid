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
 ** 27.10.2010, CSE refactoring, re-engineered namespace handling --Sampo
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
  const char* data;
  struct ELSTRUCT* x = ZX_ZALLOC(c, struct ELSTRUCT);
  x->gg.g.tok = TXELNAME_ELEM;
  x->gg.g.len = c->p-start;
  /*x->gg.g.ns = ns;*/
  ZX_START_DEC_EXT(x);

#if 1 /* NORMALMODE */
  /* The tag name has already been detected. Process attributes until '>' */
  
  for (; c->p; ++c->p) {
    tok = TXattr_lookup(c, &x->gg, (const char*)__FUNCTION__);
    switch (tok) {
ATTRS;
    case ZX_TOK_XMLNS: break;
    case ZX_TOK_ATTR_NOT_FOUND: break;
    case ZX_TOK_INCOMP:
    case ZX_TOK_ATTR_ERR: return x; 
    case ZX_TOK_NO_ATTR: goto no_attr;
    default: zx_known_attr_wrong_context(c, &x->gg);
    }
  }
no_attr:
  if (c->p) {
    ++c->p;
    if (c->p[-1] == '/' && c->p[0] == '>') {  /* Tag without content */
      ++c->p;
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
	if (!zx_scan_elem_end(c, x->gg.g.start, (const char*)__FUNCTION__))
	  return x;
	/* Legitimate close tag. Normal exit from this function. */
	++c->p;
	goto out;
      default:
	if (A_Z_a_z_(*c->p)) {
	  tok = TXelem_lookup(c, &ns, &pop_seen);
	  switch (tok) {
ELEMS;
          case ZX_TOK_INCOMP: return x; 
	  default:
	    el = TXknown_or_unknown_el(c, tok, &x->gg, ns);
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

#if 1 /* DEC_LOOKUP_SUBTEMPL */

/* This subtemplate is only expanded once (i.e. not per namespace per element) */

/* FUNC(TXknown_or_unknown_elem) */
/* c->p points to char (usually space) after elem name. */

/* Called by:  TXDEC_ELNAME */
struct zx_elem_s* TXknown_or_unknown_el(struct zx_ctx* c, int tok, struct zx_elem_s* x, struct zx_ns_s* ns)
{
  int len;
  const char* name;
  const char* p;
  struct zx_elem_s* el;

  for (name = c->p; *name != '<'; --name) ;  /* Scan backwards to find beginning of name. Cached */
  ++name;
  len = c->p - name;

  if (tok == ZX_TOK_NOT_FOUND) {
    D("Unknown element(%.*s) in context(%.*s)", len, name, x->g.len, x->g.s);
  } else {
    D("Known element(%.*s) in wrong context(%.*s)", len, name, x->g.len, x->g.s);
  }
  p = memchr(name, ':', len);  /* look for namespace prefix */
  if (p) {
    /*prefix = name;*/
    len -= p+1-name;
    name = p+1;
  }
  el = (struct zx_elem_s*)TXDEC_wrong_elem(c, ns, name, len);
  /*ZX_UNKNOWN_ELEM_DEC_EXT(el);*/
  return el;
}

/* FUNC(TXattr_lookup) */

/* Tokenize a string.
 * Lookup functions to convert a namespace qualified string to an integer token.
 * One of each (attr and elem) is needed for every prefix used in code generation.
 * The ...2tok() functions come from code generation via gperf. */

/*() Internal function CSE. Attribute token lookup.
 * Starts with c->p pointing to beginning of attribute (with ns prefix, if any) */

/* Called by:  TXDEC_ELNAME */
int TXattr_lookup(struct zx_ctx* c, struct zx_elem_s* x, const char* func)
{
  const char* prefix;
  const char* name;
  const char* lim;
  const char* data;
  const char* p;
  struct zx_ns_s* ns;
  const struct zx_tok* zt;
  struct zx_attr_s* attr;

  ZX_SKIP_WS(c, ZX_TOK_INCOMP);
  if (ONE_OF_2(*c->p, '>', '/'))
    return ZX_TOK_NO_ATTR;

  attr = ZX_ZALLOC(c, struct zx_attr_s);
  attr->name = name = c->p;
  if (!(data = zx_dec_attr_val(c, func))) {
    ZX_FREE(c, attr);
    return ZX_TOK_ATTR_ERR;
  }
  attr->g.s = data;
  attr->g.len = c->p - attr->g.s;
  lim = attr->g.s - 2;

  p = memchr(name, ':', lim-name);  /* look for namespace prefix */
  if (p) {
    prefix = name;
    name = p+1;
  } else
    prefix = 0;

  /* Look for namespace declaration. Skip as these were prescanned (see above in this file). */
  if (prefix) {
    if ((name-1)-prefix == sizeof("xmlns")-1 && !memcmp("xmlns", prefix, sizeof("xmlns")-1)) {
      ZX_FREE(c, attr);
      zx_xmlns_detected(c, x, data);
      return ZX_TOK_XMLNS;
    }
    ns = zx_prefix_seen_whine(c, prefix ? (name-1)-prefix : 0, prefix, "TXattr_lookup", 0);
    attr->g.tok = ((ns?(ns - TXns_tab):0) << 8;
  } else {
    if (lim-name == sizeof("xmlns")-1 && !memcmp("xmlns", name, sizeof("xmlns")-1)) {
      ZX_FREE(c, attr);
      zx_xmlns_detected(c, x, data);
      return ZX_TOK_XMLNS;
    }
    ns = 0;  /* Most attributes are namespaceless (or have containing element's namespace). */
  }

  attr->g.n = &el->attr->g;
  el->attr = attr;
  zt = TXattr2tok(name, lim-name);
  if (zt)
    return attr->g.tok |= (zt - *ns->attrs);
  else
    return attr->g.tok |= ZX_TOK_ATTR_NOT_FOUND;
}

/* FUNC(TXelem_lookup) */

/* Called by:  TXDEC_ELNAME x2 */
int TXelem_lookup(struct zx_ctx* c, struct zx_ns_s** ns, struct zx_ns_s** pop_seenp)
{
  const struct zx_tok* zt;
  const char* name;
  const char* prefix;
  const char* p;

  if (!(name = zx_scan_elem_start(c)))
    return ZX_TOK_INCOMP;
  *pop_seenp = zx_scan_xmlns(c);    /* Prescan namespaces so token can be correctly recognized. */
  
  p = memchr(name, ':', c->p-name); /* look for namespace prefix */
  if (p) {
    prefix = name;
    name = p+1;
  } else
    prefix = 0;

  *ns = zx_prefix_seen_whine(c, prefix ? (name-1)-prefix : 0, prefix, "TXelem_lookup", 1);
  if (!*ns->elem2tok)
    return ZX_TOK_NOT_FOUND;

  zt = *ns->elem2tok(name, c->p-name);
  if (!zt)
    return ZX_TOK_NOT_FOUND;
  return (*ns - TXns_tab) << 8 | (zt - *ns->elems);
}

#endif

/* EOF */
