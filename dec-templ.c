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

/* When per element decoder is called, the c->p will point to just past
 * the element name. The namespace prescan has also already been done. */

/* Called by: */
struct zx_elem_s* TXDEC_ELNAME(struct zx_ctx* c, EL_STRUCT* x ROOT_N_DECODE)
{
  int tok; 
  struct zx_elem_s* el;
  struct zx_str* ss;
  struct zx_ns_s* pop_seen;

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
    if (c->p[-1] == '/' && c->p[0] == '>') {  /* <Tag/> without content */
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
	if (!zx_scan_elem_end(c, x->gg.g.s, (const char*)__FUNCTION__))
	  return x;
	/* Legitimate close tag. Normal exit from this function. */
	++c->p;
	goto out;
      default:
	if (A_Z_a_z_(*c->p)) {
	  el = TXelem_lookup(c, &x->gg, &pop_seen);
	  if (!el)
	    return x;
	  switch (el->g.tok) {
ELEMS;
	  default:
	    zx_known_elem_wrong_context(c, &x->gg);
	    break;
	  }
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
#endif

/* EOF */
