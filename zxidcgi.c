/* zxidcgi.c  -  Handwritten functions for parsing SP specific CGI options
 * Copyright (c) 2006-2009 Symlabs (symlabs@symlabs.com), All Rights Reserved.
 * Author: Sampo Kellomaki (sampo@iki.fi)
 * This is confidential unpublished proprietary source code of the author.
 * NO WARRANTY, not even implied warranties. Contains trade secrets.
 * Distribution prohibited unless authorized in writing.
 * Licensed under Apache License 2.0, see file COPYING.
 * $Id: zxidcgi.c,v 1.33 2010-01-08 02:10:09 sampo Exp $
 *
 * 12.8.2006, created --Sampo
 * 16.1.2007, split from zxidlib.c --Sampo
 * 12.10.2007, added cookie scanning --Sampo
 * 7.10.2008, added documentation --Sampo
 *
 * See also: http://hoohoo.ncsa.uiuc.edu/cgi/interface.html (CGI specification)
 */

#include <memory.h>
#include <string.h>
#include "errmac.h"
#include "zxid.h"
#include "zxidconf.h"

/* ============== CGI Parsing ============== */

/*(i) Parse query string or form POST and detect parameters relevant for ZXID.
 * N.B. This CGI parsing is very specific for needs of ZXID. It is not generic.
 *
 * cgi:: Already allocated CGI structure where results of this function
 *     are deposited. Note that this structure is not cleared. Thus it is
 *     possible to call zxid_parse_cgi() multiple times to accumulate
 *     results from multiple sources, e.g. foirst for query string, and then
 *     for form POST.
 * qs:: CGI formatted input. Usually query string or form POST content.
 * return:: 0 on success. Other values reserved. Usually return value is
 *     ignored as there really is no way for this function to fail. Unrecognized
 *     CGI arguments are simply ignored with assumption that some other processing
 *     layer will pick them up - hence no need to flag error. */

/* Called by:  chkuid x3, main x4, zxid_az_cf_ses, zxid_new_cgi, zxid_simple_cf_ses x3, zxid_simple_idp_pw_authn */
int zxid_parse_cgi(struct zxid_cgi* cgi, char* qs)
{
  char *p, *n, *v, *val, *name;
  DD("qs(%s) len=%d", STRNULLCHK(qs), qs?strlen(qs):-1);
  if (!qs)
    return 0;
  while (*qs) {
    for (; *qs == '&'; ++qs) ;                  /* Skip over & or && */
    if (!*qs) break;
    
    for (name = qs; *qs && *qs != '='; ++qs) ;  /* Scan name (until '=') */
    if (!*qs) break;
    if (qs == name) {                           /* Key was an empty string: skip it */
      for (; *qs && *qs != '&'; ++qs) ;         /* Scan value (until '&') *** or '?' */
      continue;
    }
    for (; name < qs && *name <= ' '; ++name) ; /* Skip over initial whitespace before name */
    n = p = name;
    URL_DECODE(p, name, qs);
    *p = 0;                                     /* Nul-term n (name) */
    
    for (val = ++qs; *qs && *qs != '&'; ++qs) ; /* Skip over = and scan value (until '&') */
    v = p = val;
    /* SAMLRequest and Response MUST NOT be URL decoded as the URL encoding
     * is needed for redirect binding signature validation. See also unbase64_raw()
     * for how these fields are URL decoded at later stage. */
    if (n[0] != 'S' && n[0] != 'R'
	|| strcmp(n, "SAMLRequest") && strcmp(n, "SAMLResponse")
	&& strcmp(n, "SigAlg") && strcmp(n, "Signature") && strcmp(n, "RelayState"))
      URL_DECODE(p, val, qs);
    else
      p = qs;

    if (*qs)
      ++qs;
    *p = 0;                                     /* Nul-term v (value) */
    
    switch (n[0]) {
    case 'o':
      if (!n[1]) { cgi->op = v[0];    break; }
      if (n[1] = 'k' && !n[2]) { cgi->ok = v;  break; }  /* ok button */
      goto unknown;
    case 's': cgi->sid = v;           break;
    case 'c': cgi->cdc = v;           break;
      
      /* The following two entity IDs, combined with various login buttons
       * aim at supporting may different user interface layouts. You need to
       * understand how they interact to avoid undesired conflicts. */
    case 'e':  /* EntityID field (manual entry). Overrides 'd'. */
set_eid:
      if (v[0]) cgi->eid = v;
      DD("v(%s) v0=0x%02x v=%p cgi->eid=%p cgi=%p", v, v[0], v, cgi->eid, cgi);
      break;
    case 'd':  /* EntityID popup or radio box */
      if (cgi->eid && cgi->eid[0]) {
	D("EID already set v(%s) v0=0x%02x v=%p cgi->eid=%p cgi=%p", v, v[0], v, cgi->eid, cgi);
	break;
      }
      goto set_eid;
    case 'l':
      /* Login button names are like lP<eid>, where "l" is literal ell, P is
       * protocol profile designator, and <eid> is Entity ID of the IdP.
       * N.B. If eid is omitted from button name, it may be provided using
       * d or e fields (see above). */
      cgi->pr_ix = n[1];
      if (n[2])
	cgi->eid = n+2;
      cgi->op = 'L';
      D("cgi: login eid(%s)", cgi->eid);
      break;
    case 'i':
      /* IdP and protocol index selection popup values are like P<eid>
       * N.B. If eid is omitted from button name, it may be provided using
       * d or e fields (see above). This effectively allows i to be just
       * a protocol selection popup. */
      cgi->pr_ix = v[0];
      if (v[1])
	cgi->eid = v+1;
      break;
    case 'f':  /* flags and (hidden) fields found in typical SP login form */
      switch (n[1]) {
      case 'a': cgi->authn_ctx = v;       D("authn_ctx=%s", cgi->authn_ctx); break;
      case 'c': cgi->allow_create = v[0]; D("allow_create=%c", cgi->allow_create); break;
      case 'f': cgi->force_authn = v[0];  D("force_authn=%c", cgi->force_authn); break;
      case 'g': cgi->get_complete = v;    break;
      case 'h': cgi->pxy_count = v;       break;
	/*case 'i': cgi->idp_list = v;        break;*/
      case 'm': cgi->matching_rule = v;   break;
      case 'n': cgi->nid_fmt = v;         D("nid_fmt=%s", cgi->nid_fmt); break;
      case 'p': cgi->ispassive = v[0];    D("ispassive=%c", cgi->ispassive); break;
      case 'q': cgi->affil = v;           break;
      case 'r': cgi->rs = v;              break;
      case 'y': cgi->consent = v;         break;
      }
      break;
    case 'g':
      switch (n[1]) {
      case 'l':
      case 'r':
      case 's':
      case 't':
      case 'u': cgi->op = n[1];           break;
      case 'n': cgi->newnym = v;          break;
      case 'e': cgi->enc_hint = v[0];     break;
      }
      break;
    case 'a':
      switch (n[1]) {
      case 'l': cgi->op = n[2];           break;
      case 'u': if (v[0] || !cgi->uid) cgi->uid = v; break;
      case 'p': cgi->pw = v;              break;
      case 'r': cgi->ssoreq = v;          break;
      case 'n': cgi->op = 'N';            break;
      case 'w': cgi->op = 'W';            break;
      case 't': cgi->atselafter = 1;      break;
      }
      break;
    case 'z':
      switch (n[1]) {
      case 'x':
	switch (n[2]) {
	case 'a': cgi->zxapp = v;         break;
	case 'r': cgi->zxrfr = v;         break;
	}
	break;
      }
      break;
    case 'R':
      if (!strcmp(n, "RelayState")) {
	cgi->rs = v;
	break;
      }
      break;
    case 'S':
      if (!strcmp(n, "SAMLart")) {
	cgi->saml_art = v;
	cgi->op = 'A';
	break;
      }
      if (!strcmp(n, "SAMLResponse")) {
	cgi->saml_resp = v;
	cgi->op = 'P';
	break;
      }
      if (!strcmp(n, "SAMLRequest")) {
	cgi->saml_req = v;
	if (!ONE_OF_3(cgi->op, 'p', 'F', 'R'))  /* Avoid redundant sigvfy and processing for IdP */
	  cgi->op = 'Q';
	break;
      }
      if (!strcmp(n, "SigAlg")) {
	cgi->sigalg = v;
	break;
      }
      if (!strcmp(n, "Signature")) {
	cgi->sig = v;
	break;
      }
      /* fall thru */
    unknown:
    default:  D("Unknown CGI field(%s) val(%s)", n, v);
    }
  }
  DD("END cgi=%p cgi->eid=%p (%s) op(%c) magic=%x", cgi, cgi->eid, cgi->eid, cgi->op, cgi->magic);
  return 0;
}

/* Called by: */
struct zxid_cgi* zxid_new_cgi(struct zxid_conf* cf, char* qs)
{
  struct zxid_cgi* cgi = ZX_ZALLOC(cf->ctx, struct zxid_cgi);
  cgi->magic = ZXID_CGI_MAGIC;
  if (qs) {
    char* qqs;
    int len = strlen(qs);
    qqs = ZX_ALLOC(cf->ctx, len+1);
    memcpy(qqs, qs, len);
    qqs[len] = 0;
    zxid_parse_cgi(cgi, qqs);
  }
  return cgi;
}

/*() Try to extract session ID from a cookie. The extracted value, if any,
 * will be deposited in cgi->sid. If no session ID is found, then cgi->sid
 * is not modified. The name of the cookie is determined by configuration
 * option ~SES_COOKIE_NAME~ (see zxidconf.h).
 *
 * For original Netscape cookie spec see: http://curl.haxx.se/rfc/cookie_spec.html (Oct2007)
 *
 * *Example*
 *
 *    ONE_COOKIE=aaa; ZXIDSES=S12cvd324; SOME_OTHER_COOKIE=...
 */

/* Called by:  chkuid, zxid_simple_cf_ses */
void zxid_get_sid_from_cookie(struct zxid_conf* cf, struct zxid_cgi* cgi, const char* cookie)
{
  char* q;
  int len;
  if (!cookie)
    return;
  len = strlen(cf->ses_cookie_name);
  for (cookie = strstr(cookie, cf->ses_cookie_name);
       cookie;
       cookie = strstr(cookie + 1, cf->ses_cookie_name))
    if (cookie[len] == '=') {
      cookie += len + 1;
      if (*cookie == '"')
	++cookie;
      q = strchr(cookie, ';');
      len = q ? (q-cookie) : strlen(cookie);
      if (cookie[len-1] == '"')
	--len;
      cgi->sid = ZX_ALLOC(cf->ctx, len + 1);
      memcpy(cgi->sid, cookie, len);
      cgi->sid[len] = 0;
      return;
    }
}

/* EOF  --  zxidcgi.c */
