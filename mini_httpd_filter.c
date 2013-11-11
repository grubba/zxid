/* mini_httpd_filter.c  -  Emulate mod_auth_saml for mini_httpd
 * Copyright (c) 2012-2013 Synergetics SA (sampo@synergetics.be), All Rights Reserved.
 * Copyright (c) 2009-2011 Sampo Kellomaki (sampo@iki.fi), All Rights Reserved.
 * Copyright (c) 2008-2009 Symlabs (symlabs@symlabs.com), All Rights Reserved.
 * Author: Sampo Kellomaki (sampo@iki.fi)
 * This is confidential unpublished proprietary source code of the author.
 * NO WARRANTY, not even implied warranties. Contains trade secrets.
 * Distribution prohibited unless authorized in writing or as licensed below.
 * Licensed under Apache License 2.0, see file COPYING.
 * $Id: mod_auth_saml.c,v 1.17 2010-01-08 02:10:09 sampo Exp $
 *
 * 1.2.2008,  created --Sampo
 * 22.2.2008, distilled to much more compact version --Sampo
 * 25.8.2009, add attribute passing and pep call --Sampo
 * 11.1.2010, refactoring and review --Sampo
 * 15.7.2010, consider passing to simple layer more data about the request --Sampo
 * 28.9.2012, changed zx_instance string to "mas", fixed parsing CGI for other page --Sampo
 * 13.2.2013, added WD option --Sampo
 * 21.6.2013, added SOAP WSP capability --Sampo
 * 22.6.2013, created, based on mod_auth_saml.c and zxidwspcgi.c --Sampo
 *
 * See also: zxidwspcgi.c, mod_auth_saml.c
 */

#define _LARGEFILE64_SOURCE   /* So off64_t is found, see: man 3 lseek64 */

#include <zx/platform.h>
#include <zx/errmac.h>
#include <zx/zx.h>
#include <zx/zxid.h>
#include <zx/zxidpriv.h>
#include <zx/zxidconf.h>
#include <zx/zxidutil.h>
#include <zx/c/zxidvers.h>

#include <errno.h>
#include <unistd.h>

/* declare stuff from mini_httpd.c */
void send_error_and_exit(int s, char* title, char* extra_header, char* text);
ssize_t my_read(char* buf, size_t size);
ssize_t my_write(char* buf, size_t size);
void add_to_buf(char** bufP, size_t* bufsizeP, size_t* buflenP, char* str, size_t len);
void add_to_request(char* str, size_t len);
void add_headers(int s, char* title, char* extra_header, char* me, char* mt, off_t b, time_t mod);
void add_to_response(char* str, size_t len);
void send_response(void);
extern char* request;
extern size_t request_size, request_len, request_idx;
extern size_t content_length;
extern int zxid_is_wsp;               /* Flag to trigger WSP response decoration. */

/*() Convert session attribute pool into mini_httpd CGI execution environment.
 *
 * OUTMAP will be applied to decide which attributes to pass to the environment
 * and to rename them.
 *
 * This is considered internal function to mod_auth_saml, called by chkuid().
 * You should not call this directly, unless you know what you are doing. */

/* Called by:  chkuid */
int zxid_pool2env(zxid_conf* cf, zxid_ses* ses, char** envp, int envn, int max_envn, const char* uri_path, const char* qs)
{
  char* rs_qs;
  char* name;
  char* rs = 0;
  char* setcookie = 0;
  char* setptmcookie = 0;
  char* cookie = 0;
  char* idpnid = 0;
  struct zxid_map* map;
  struct zxid_attr* at;
  struct zxid_attr* av;
  
  /* Length computation pass */

  for (at = ses->at; at; at = at->n) {
    DD("HERE name(%s)", at->name);
    map = zxid_find_map(cf->outmap, at->name);
    if (map) {
      if (map->rule == ZXID_MAP_RULE_DEL) {
	D("attribute(%s) filtered out by del rule in OUTMAP", at->name);
	continue;
      }
      at->map_val = zxid_map_val(cf, 0, 0, map, at->name, at->val);
      if (map->dst && *map->dst && map->src && map->src[0] != '*') {
	name = map->dst;
      } else {
	name = at->name;
      }

      if (envn >= max_envn) goto enverr;
      envp[envn++] = zx_alloc_sprintf(cf->ctx, 0, "%s%s=%s",
				      cf->mod_saml_attr_prefix, name, at->map_val->s);
      for (av = at->nv; av; av = av->n) {
	/* Multivalued */
	av->map_val = zxid_map_val(cf, 0, 0, map, at->name, av->val);
	if (envn >= max_envn) goto enverr;
	envp[envn++] = zx_alloc_sprintf(cf->ctx, 0, "%s%s=%s",
					cf->mod_saml_attr_prefix, name, av->map_val->s);
      }
    } else {
      if ((zx_debug & ZX_DEBUG_MASK)>1)
	D("ATTR(%s)=VAL(%s)", at->name, STRNULLCHKNULL(at->val));
      else
	D("ATTR(%s)=VAL(%.*s)", at->name, at->val?(int)MIN(35,strlen(at->val)):6, at->val?at->val:"(null)");

      if (envn >= max_envn) goto enverr;
      envp[envn++] = zx_alloc_sprintf(cf->ctx, 0, "%s%s=%s",
				      cf->mod_saml_attr_prefix, at->name, at->val);
      for (av = at->nv; av; av = av->n) {
	/* Multivalued */
	av->map_val = zxid_map_val(cf, 0, 0, map, at->name, av->val);
	if (envn >= max_envn) goto enverr;
	envp[envn++] = zx_alloc_sprintf(cf->ctx, 0, "%s%s=%s",
					cf->mod_saml_attr_prefix, at->name, av->val);
      }
    }
    if (     !strcmp(at->name, "rs"))           rs = at->val;      /* Capture special */
    else if (!strcmp(at->name, "idpnid"))       idpnid = at->val;
    else if (!strcmp(at->name, "setcookie"))    setcookie = at->val;
    else if (!strcmp(at->name, "setptmcookie")) setptmcookie = at->val;
    else if (!strcmp(at->name, "cookie"))       cookie = at->val;
  }

  if (rs && rs[0] && rs[0] != '-') {
    /* N.B. RelayState was set by chkuid() "some other page" section by setting cgi.rs
     * to deflated and safe base64 encoded value which was then sent to IdP as RelayState.
     * It then came back from IdP and was decoded as one of the SSO attributes.
     * The decoding is controlled by <<tt: rsrc$rs$unsb64-inf$$ >>  rule in OUTMAP. */
#if 1
    rs = zxid_unbase64_inflate(cf->ctx, -2, rs, 0);
    if (!rs) {
      ERR("Bad relaystate. Error in inflate. %d", 0);
      send_error_and_exit(400, "Bad Request", "", "Error in relaystate inflate");
    }
#endif
    rs_qs = strchr(rs, '?');
    if (rs_qs
	?(memcmp(uri_path, rs, rs_qs-rs)||strcmp(qs?qs:"",rs_qs+1))
	:strcmp(uri_path, rs)) {  /* Different, need external or internal redirect */
      D("redirect(%s) redir_to_content=%d", rs, cf->redir_to_content);
      //r->uri = apr_pstrdup(r->pool, val);
      if (cf->redir_to_content) {
	send_error_and_exit(302, "Found", rs, "SAML Redirect" );
      } else {
	/* *** for this to be effective, it should be done much earlier, already where
	 *     filter is called. By this time the file global has already been computed. */
	uri_path = rs;
      }
    }
  }
  
#if 0
  /* *** figure out how to influence mini_httpd response headers */
  if (setcookie && setcookie[0] && setcookie[0] != '-') {
    D("Set-Cookie(%s)", setcookie);
    apr_table_addn(r->headers_out, "Set-Cookie", setcookie);
    apr_table_addn(r->err_headers_out, "Set-Cookie", setcookie);  /* Only way to get redir to set header */
  }
  if (setptmcookie && setptmcookie[0] && setptmcookie[0] != '-') {
    D("PTM Set-Cookie(%s)", setptmcookie);
    apr_table_addn(r->headers_out, "Set-Cookie", setptmcookie);
    apr_table_addn(r->err_headers_out, "Set-Cookie", setptmcookie);  /* Only way to get redir to set header */
  }
#endif
  if (idpnid && idpnid[0] != '-') {
    D("REMOTE_USER(%s)", idpnid);
    if (envn >= max_envn) goto enverr;
    envp[envn++] = zx_alloc_sprintf(cf->ctx, 0, "REMOTE_USER=%s", idpnid);
  }
  
  D("SSO OK uri(%s) rs(%s)", uri_path, STRNULLCHKQ(rs));
  return envn;
 enverr:
  ERR("Statically allocated CGI environment array too small. max_envn=%d", max_envn);
  return envn;
}

/*() Read POST input
 *
 * This is considered internal function to mini_httpd_filter().
 * It works by accessing certain request related global variables from mini_httpd.
 * You should not call this directly, unless you know what you are doing. */

/* Called by: */
static char* zxid_mini_httpd_read_post(zxid_conf* cf)
{
  char* res;

  for (;;) {
    char buf[16*1024];
    int already_read = request_len-request_idx;
    int len = MIN(sizeof(buf), content_length - already_read);
    D("About to read post data content_length=%d already_read=%d sizeof(buf)=%d req=%d", content_length, already_read, sizeof(buf), len);
    if (!len)
      break;  /* nothing further to read */
    len = my_read(buf, len);
    if (len < 0 && ONE_OF_2(errno, EINTR, EAGAIN))
      continue;
    if (len <= 0)
      break;
    add_to_request(buf, len);
  }
  res = request + request_idx;
  if (zx_debug & MOD_AUTH_SAML_INOUT) INFO("POST(%s)", res);
  return res;
}

zxid_ses* zxid_mini_httpd_wsp(zxid_conf* cf, const char* method, const char* uri_path, const char* qs)
{  
  char* res;
  zxid_ses* ses = zxid_alloc_ses(cf);
  
  if (*method == 'P') {
    res = zxid_mini_httpd_read_post(cf);
    if (zxid_wsp_validate(cf, ses, 0, res)) {
      D("WSP(%s) request valid", uri_path);
      /* Essentially we fall through and let CGI processing happen.
       * zxid_wsp_decorate() will be called in cgi_interpose_output() */
    } else {
      INFO("WSP(%s) call not authorized", uri_path);
      send_error_and_exit(403, "Forbidden", "", "Authorization denied.");
    }
  } else {
    ERR("WSP(%s) must be called with POST method (%s)", uri_path, method);
    send_error_and_exit(405, "Method Not Allowed", "", "WSP only accepts POST method.");
  }
  return ses;
}

/*() Handle the WSP case of cgi_interpose_output(). Read in entire response,
 * apply decoration, and send it on its way. */

void zxid_mini_httpd_wsp_response(zxid_conf* cf, zxid_ses* ses, int rfd, char** response, size_t* response_size, size_t* response_len, int br_ix)
{  
  struct zx_str* res;
  
  D("DECOR START response_size=%d response_len=%d br_ix=%d response(%.*s)", *response_size, *response_len, br_ix, *response_len, *response);

  /* Read until EOF */
  for (;;) {
    char buf[10*1024];
    int len = read(rfd, buf, sizeof(buf));
    if (len < 0 && ONE_OF_2(errno, EINTR, EAGAIN)) {
      sleep(1);
      continue;
    }
    if (len <= 0)
      break;
    add_to_buf(response, response_size, response_len, buf, len);
  }
  
  D("DECOR2 response_size=%d response_len=%d br_ix=%d response(%.*s)", *response_size, *response_len, br_ix, *response_len, *response);

  /* Write the saved headers (and any beginning of payload). */
  if ((*response)[br_ix] == '\015') ++br_ix;
  if ((*response)[br_ix] == '\012') ++br_ix;
  if ((*response)[br_ix] == '\015') ++br_ix;
  if ((*response)[br_ix] == '\012') ++br_ix;

  D("DECOR3 response_len=%d br_ix=%d header(%.*s)", *response_len, br_ix, br_ix, *response);
  (void) my_write(*response, br_ix);

  res = zxid_wsp_decorate(cf, ses, 0, *response+br_ix);
  (void) my_write(res->s, res->len);
}

/* 0x6000 outf QS + JSON = no output
 * 0x1000 debug
 * 0x0e00 11 + 10 = Generate all HTML + Mgmt w/headers as string
 * 0x00a0 10 + 10 = Login w/headers as string + Meta w/headers as string
 * 0x0008 10 + 00 = SOAP w/headers as string + no auto redir, no exit(2) */
#define AUTO_FLAGS 0x6ea8

zxid_ses* zxid_mini_httpd_sso(zxid_conf* cf, const char* method, const char* uri_path, const char* qs, const char* cookie_hdr)
{  
  int ret, len, uri_len, url_len, args_len;
  char* p;
  char* res;
  char* mt;
  //const char* set_cookie_hdr;
  //const char* cur_auth;
  zxid_ses* ses = zxid_alloc_ses(cf);
  zxid_cgi cgi;
  ZERO(&cgi, sizeof(zxid_cgi));

  /* Probe for Session ID in cookie. Also propagate the cookie to subrequests. */

  if (cf->ses_cookie_name && *cf->ses_cookie_name) {
    if (cookie_hdr) {
      D("found cookie(%s) 3", STRNULLCHK(cookie_hdr));
      zxid_get_sid_from_cookie(cf, &cgi, cookie_hdr);
      /*set_cookie_hdr = apr_table_get(r->headers_in, "Set-Cookie");  // for subreqs */
    }
  }

  /* Redirect hack: deal with externally imposed ACS url that does not follow zxid convention. */
  
  args_len = qs?strlen(qs):0;
  if (cf->redirect_hack_imposed_url && !strcmp(uri_path, cf->redirect_hack_imposed_url)) {
    D("Redirect hack: mapping(%s) imposed to zxid(%s)", uri_path, cf->redirect_hack_zxid_url);
    uri_path = cf->redirect_hack_zxid_url;
    if (cf->redirect_hack_zxid_qs && *cf->redirect_hack_zxid_qs) {
      if (args_len) {
	/* concatenate redirect_hack_zxid_qs with existing qs */
	len = strlen(cf->redirect_hack_zxid_qs);
	p = ZX_ALLOC(cf->ctx, len+1+args_len+1);
	strcpy(p, cf->redirect_hack_zxid_qs);
	p[len] = '&';
	strcpy(p+len+1, qs);
	qs = p;
      } else {
	qs = cf->redirect_hack_zxid_qs;
      }
      args_len = strlen(qs);
    }
    D("After hack uri(%s) args(%s)", STRNULLCHK(uri_path), STRNULLCHK(qs));
  }
  
  DD("HERE1 args_len=%d cgi=%p k(%s) args(%s)", args_len, &cgi, STRNULLCHKNULL(cgi.skin), STRNULLCHKNULL(qs));
  if (args_len) {
    /* leak the dup str: the cgi structure will take references to this and change &s to nuls */
    p = zx_dup_cstr(cf->ctx, qs);
    zxid_parse_cgi(cf, &cgi, p);
    DD("HERE2 args_len=%d cgi=%p k(%s) args(%s)", args_len, &cgi, STRNULLCHKNULL(cgi.skin), STRNULLCHKNULL(qs));
  }
  /* Check if we are supposed to enter zxid due to URL suffix - to
   * process protocol messages rather than ordinary pages. To do this
   * correctly we need to ignore the query string part. We are looking
   * here at exact match, like /protected/saml, rather than any of
   * the other documents under /protected/ (which are handled in the
   * else clause). Both then and else -clause URLs are defined as requiring
   * SSO by virtue of the web server configuration (SSO_PAT in mini_httpd_zxid). */

  uri_len = strlen(uri_path);
  url_len = strlen(cf->url);
  for (p = cf->url + url_len - 1; p > cf->url; --p)
    if (*p == '?')
      break;
  if (p == cf->url)
    p = cf->url + url_len;
  
  if (url_len >= uri_len && !memcmp(p - uri_len, uri_path, uri_len)) {  /* Suffix match */
    if (zx_debug & MOD_AUTH_SAML_INOUT) INFO("matched uri(%s) cf->url(%s) qs(%s) rs(%s) op(%c)", uri_path, cf->url, STRNULLCHKNULL(qs), STRNULLCHKNULL(cgi.rs), cgi.op);
    if (*method == 'P') {
      res = zxid_mini_httpd_read_post(cf);   /* Will print some debug output */  // ***
      if (res) {
	if (cgi.op == 'S') {
	  ret = zxid_sp_soap_parse(cf, &cgi, ses, strlen(res), res);
	  D("POST soap parse returned %d", ret);
#if 0
	  /* *** TODO: SOAP response should not be sent internally unless there is auto */
	  if (ret == ZXID_SSO_OK) {
	    ret = zxid_simple_ab_pep(cf, ses, res_len, auto_flags);
	    D_DEDENT("minizx: ");
	    return ret;
	  }
	  if (auto_flags & ZXID_AUTO_SOAPC || auto_flags & ZXID_AUTO_SOAPH) {
	    res = zx_dup_cstr(cf->ctx, "n");
	    if (res_len)
	      *res_len = 1;
	    goto done;
	  }
	  res = zx_dup_cstr(cf->ctx, ret ? "n" : "*** SOAP error (enable debug to see why)"); 
	  if (res_len)
	    *res_len = strlen(res);
	  goto done;
#endif
	} else {
	  zxid_parse_cgi(cf, &cgi, res);
	  D("POST CGI parsed. rs(%s)", STRNULLCHKQ(cgi.rs));
	}
      }
    }
    if (ONE_OF_2(cgi.op, 'L', 'A')) /* SSO (Login, Artifact) activity overrides current session. */
      goto step_up;
    if (!cgi.sid || !zxid_get_ses(cf, ses, cgi.sid)) {
      D("No session(%s) active op(%c)", STRNULLCHK(cgi.sid), cgi.op);
    } else {
      res = zxid_simple_ses_active_cf(cf, &cgi, ses, 0, AUTO_FLAGS);
      if (res)
	goto process_zxid_simple_outcome;
    }
    /* not logged in, fall thru */
  } else {
    /* Some other page. Just check for session. */
    if (zx_debug & MOD_AUTH_SAML_INOUT) INFO("other page uri(%s) qs(%s) cf->url(%s) uri_len=%d url_len=%d", uri_path, STRNULLCHKNULL(qs), cf->url, uri_len, url_len);
    if (qs && qs[0] == 'l') {
      D("Detect login(%s)", qs);
    } else
      cgi.op = 'E';   /* Trigger IdP selection screen */
    p = ZX_ALLOC(cf->ctx, uri_len+1+args_len+1);
    strcpy(p, uri_path);
    if (args_len) {
      p[uri_len] = '?';
      strcpy(p+uri_len+1, qs);
    }
    DD("HERE3 args_len=%d cgi=%p k(%s) uri(%s) args(%s) rs(%s)", args_len, &cgi, STRNULLCHKNULL(cgi.skin), uri_path, STRNULLCHKNULL(qs), p);
    /* cgi.rs will be copied to ses->rs and from there in ab_pep to resource-id.
     * We compress and safe_base64 encode it to protect any URL special characters.
     * *** seems that at this point the p is not just rs, but the entire local URL --Sampo */
    cgi.rs = zxid_deflate_safe_b64_raw(cf->ctx, -2, p);
    if (cf->defaultqs && cf->defaultqs[0]) {
      if (zx_debug & MOD_AUTH_SAML_INOUT) INFO("DEFAULTQS(%s)", cf->defaultqs);
      zxid_parse_cgi(cf, &cgi, cf->defaultqs);
    }
    if (cgi.sid && cgi.sid[0] && zxid_get_ses(cf, ses, cgi.sid)) {
      res = zxid_simple_ses_active_cf(cf, &cgi, ses, 0, AUTO_FLAGS);
      if (res)
	goto process_zxid_simple_outcome;
    } else {
      D("No session(%s) active op(%c)", STRNULLCHK(cgi.sid), cgi.op);
    }
    D("other page: no_ses uri(%s) templ(%s) tf(%s) k(%s) cgi=%p", uri_path, STRNULLCHKNULL(cgi.templ), STRNULLCHKNULL(cf->idp_sel_templ_file), cgi.skin, &cgi);
  }
step_up:
  res = zxid_simple_no_ses_cf(cf, &cgi, ses, 0, AUTO_FLAGS);

process_zxid_simple_outcome:
  if (cookie_hdr && cookie_hdr[0]) {
    D("Passing cookie(%s) to environment", cookie_hdr);
    zxid_add_attr_to_ses(cf, ses, "cookie", zx_dup_str(cf->ctx, cookie_hdr));
  }
  D("res(%s)",res);
  switch (res[0]) {
  case 'L':
    if (zx_debug & MOD_AUTH_SAML_INOUT) INFO("REDIR(%s)", res);
    send_error_and_exit(302, "Found", res, "SAML Redirect");
  case 'C':
    if (zx_debug & MOD_AUTH_SAML_INOUT) INFO("CONTENT(%s)", res);
    res += 14;  /* skip "Content-Type:" (14 chars) */
    DD("RES(%s)", res);
    p = strchr(res, '\r');
    *p = 0;
    mt = res;
    DD("CONTENT-TYPE(%s)", res);
    res = p+2 + 16;  /* skip "Content-Length:" (16 chars) */
    sscanf(res, "%d", &len);
    res = strchr(res, '\r') + 4; /* skip CRFL pair before body */
    DD("CONTENT-LENGTH(%d)", len);
    /* *** how is set-cookie header handled? */

    add_headers(200, "OK", "", "", mt?mt:"text/html; charset=%s", len, (time_t)-1);
    add_to_response(res, len);
    send_response();
    exit(0);  /* This function is called in mini_httpd handle_request() subrprocess. */
  case 'z':
    INFO("User not authorized %d", 0);
    send_error_and_exit(403, "Forbidden", "", "Authorization denied.");
  case 0: /* Logged in case */
    D("SSO OK pre uri(%s)", uri_path);
    //ret = pool2apache(cf, r, ses.at); // *** done in docgi()
    break;
#if 0
  case 'd': /* Logged in case */
    if (zx_debug & MOD_AUTH_SAML_INOUT) INFO("SSO OK LDIF(%s)", res);
    D("SSO OK pre uri(%s)", uri_path);
    ret = ldif2apache(cf, r, res);
    return ret;
#endif
  default:
    ERR("Unknown zxid_simple response(%s)", res);
    send_error_and_exit(501, "Internal Server Error", "", "Unknown zxid_simple response." );
  }
  return ses;
}

/*() Handle SSO or ID-WSF SSO
 * Called from mini_httpd handle_request() if zxid is configured.
 * In many cases entire situation is handled in this function
 * and exit is called. In successful SSO or WSP call function
 * may return and the regular mini_httpd processing continues.
 * In that case docgi() contains further zxid related steps to
 * pass the SSO attributes to the CGI environment. */

/* Called by: */
zxid_ses* zxid_mini_httpd_filter(zxid_conf* cf, const char* method, const char* uri_path, const char* qs, const char* cookie_hdr)
{
  zxid_ses* ses;
  char buf[256];
  D("===== START %s uri(%s) qs(%s) uid=%d pid=%d gid=%d cwd(%s)", ZXID_REL, uri_path, STRNULLCHKNULL(qs), getpid(), getuid(), getgid(), getcwd(buf,sizeof(buf)));
  if (cf->wd && *cf->wd)
    chdir(cf->wd);
  D_INDENT("minizx: ");

  zxid_is_wsp = 0;
  if (zx_wildcard_pat_match(cf->wsp_pat, uri_path)) {
    zxid_is_wsp = 1;
    ses = zxid_mini_httpd_wsp(cf, method, uri_path, qs);
    D_DEDENT("minizx: ");
    return ses;
  } else if (zx_wildcard_pat_match(cf->sso_pat, uri_path)) {
    ses = zxid_mini_httpd_sso(cf, method, uri_path, qs, cookie_hdr);
    D_DEDENT("minizx: ");
    return ses;
  } else {
    D("No SSO or WSP match(%s)",uri_path);
    D_DEDENT("minizx: ");
    return 0;
  }
}

/* EOF - mini_httpd_filter.c */
