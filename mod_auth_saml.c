/* mod_auth_saml.c  -  Handwritten functions for Apache mod_auth_saml module
 * Copyright (c) 2012-2013 Synergetics NV (sampo@synergetics.be), All Rights Reserved.
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
 * 17.11.2013, move redir_to_content feature to zxid_simple() --Sampo
 *
 * To configure this module add to httpd.conf something like
 *
 *   LoadModule auth_saml_module modules/mod_auth_saml.so
 *   <Location /secret>
 *     Require valid-user
 *     AuthType "saml"
 *     ZXIDConf "URL=https://sp1.zxidsp.org:8443/secret/saml"
 *   </Location>
 *
 * http://httpd.apache.org/docs/2.2/developer/
 * http://modules.apache.org/doc/API.html
 */

#define _LARGEFILE64_SOURCE   /* So off64_t is found, see: man 3 lseek64 */

#include <zx/platform.h>
#include <zx/errmac.h>
#include <zx/zxid.h>
#include <zx/zxidpriv.h>
#include <zx/zxidconf.h>
#include <zx/zxidutil.h>
#include <zx/c/zxidvers.h>

#include "ap_config.h"
#include "ap_compat.h"
#include "apr_strings.h"
#include "httpd.h"
#include "http_config.h"
#include "http_core.h"
#include "http_log.h"
#include "http_protocol.h"
#include "http_request.h"

#define srv_cf(s) (struct zxid_srv_cf*)ap_get_module_config((s)->module_config, &auth_saml_module)
#define dir_cf(r) (zxid_conf*)ap_get_module_config((r)->per_dir_config, &auth_saml_module)

/* This extern variable is used as first argument to LoadModule in httpd.conf,
 * E.g: LoadModule auth_saml_module modules/mod_auth_saml.so */

extern module AP_MODULE_DECLARE_DATA auth_saml_module;

#if 0
/* This function is run when each child process of apache starts. It does
 * initializations that do not survive fork(2). */
/* Called by: */
static void chldinit(apr_pool_t* p, server_rec* s)
{
  CURLcode res;
  D("server_rec=%p", m, s);
  res = curl_global_init(CURL_GLOBAL_ALL); /* vs. _SSL. Also OpenSSL vs. gnuTLS. */
  if(res != CURLE_OK) {
    ap_log_error(APLOG_MARK, APLOG_ERR, 0, s, "Failed to initialize curl library: %u", res);
  }
}
#endif

/* ------------------------ Run time action -------------------------- */

/*() Convert session attribute pool into Apache execution environment
 * that will be passed to CGI, mod_php, mod_perl, and other Apache modules.
 *
 * OUTMAP will be applied to decide which attributes to pass to the environment
 * and to rename them.
 *
 * This is considered internal function to mod_auth_saml, called by chkuid().
 * You should not call this directly, unless you know what you are doing.
 *
 * return:: Apache error code, typically OK, which allows Apache continue
 *     processing the request. */

/* Called by:  chkuid */
static int pool2apache(zxid_conf* cf, request_rec* r, struct zxid_attr* pool)
{
  int ret = OK;
  char* name;
  //char* rs = 0;
  //char* rs_qs;
  char* setcookie = 0;
  char* setptmcookie = 0;
  char* cookie = 0;
  char* idpnid = 0;
  struct zxid_map* map;
  struct zxid_attr* at;
  struct zxid_attr* av;
  
  /* Length computation pass */

  for (at = pool; at; at = at->n) {
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

      name = apr_psprintf(r->pool, "%s%s", cf->mod_saml_attr_prefix, name);
      apr_table_set(r->subprocess_env, name, at->val);
      for (av = at->nv; av; av = av->n) {
	av->map_val = zxid_map_val(cf, 0, 0, map, at->name, av->val);
	apr_table_set(r->subprocess_env, name, av->map_val->s);
      }
    } else {
      if ((errmac_debug & ERRMAC_DEBUG_MASK)>1)
	D("ATTR(%s)=VAL(%s)", at->name, STRNULLCHKNULL(at->val));
      else
	D("ATTR(%s)=VAL(%.*s)", at->name, at->val?(int)MIN(35,strlen(at->val)):6, at->val?at->val:"(null)");
      /* *** handling of multivalued attributes (right now only last is preserved) */
      name = apr_psprintf(r->pool, "%s%s", cf->mod_saml_attr_prefix, at->name);
      apr_table_set(r->subprocess_env, name, at->val);
      for (av = at->nv; av; av = av->n)
	apr_table_set(r->subprocess_env, name, av->val);
    }
    if      (!strcmp(at->name, "idpnid"))       idpnid = at->val;      /* Capture special */
    else if (!strcmp(at->name, "setcookie"))    setcookie = at->val;
    else if (!strcmp(at->name, "setptmcookie")) setptmcookie = at->val;
    else if (!strcmp(at->name, "cookie"))       cookie = at->val;
    //else if (!strcmp(at->name, "rs"))         rs = at->val;
  }
#if 0
  if (rs && rs[0] && rs[0] != '-') {
    /* N.B. RelayState was set by chkuid() "some other page" section by setting cgi.rs
     * to deflated and safe base64 encoded value which was then sent to IdP as RelayState.
     * It then came back from IdP and was decoded as one of the SSO attributes.
     * The decoding is controlled by <<tt: rsrc$rs$unsb64-inf$$ >>  rule in OUTMAP. */
    rs = zxid_unbase64_inflate(cf->ctx, -2, rs, 0);
    if (!rs) {
      ERR("Bad relaystate. Error in inflate. %d", 0);
      return HTTP_BAD_REQUEST;
    }
    rs_qs = strchr(rs, '?');
    if (rs_qs
	?(memcmp(r->uri, rs, rs_qs-rs)||strcmp(r->args?r->args:"",rs_qs+1))
	:strcmp(r->uri, rs)) {  /* Different, need external or internal redirect */
      D("redirect(%s) redir_to_content=%d", rs, cf->redir_to_content);
      //r->uri = apr_pstrdup(r->pool, val);
      if (cf->redir_to_content) {
	apr_table_setn(r->headers_out, "Location", rs);
	ret = HTTP_SEE_OTHER;
      } else {
	/* *** any attributes after this point may not appear in subrequest */
	ap_internal_redirect_handler(rs, r);
      }
    }
  }
#endif
  
  if (setcookie && setcookie[0] && setcookie[0] != '-') {
    /* http://dev.ariel-networks.com/apr/apr-tutorial/html/apr-tutorial-19.html */
    D("Set-Cookie(%s)", setcookie);
    apr_table_addn(r->headers_out, "Set-Cookie", setcookie);
    apr_table_addn(r->err_headers_out, "Set-Cookie", setcookie);  /* Only way to get redir to set header */
    apr_table_addn(r->headers_in,  "Set-Cookie", setcookie);  /* So subrequest can pick them up! */
  }
  if (setptmcookie && setptmcookie[0] && setptmcookie[0] != '-') {
    /* http://dev.ariel-networks.com/apr/apr-tutorial/html/apr-tutorial-19.html */
    D("PTM Set-Cookie(%s)", setptmcookie);
    apr_table_addn(r->headers_out, "Set-Cookie", setptmcookie);
    apr_table_addn(r->err_headers_out, "Set-Cookie", setptmcookie);  /* Only way to get redir to set header */
    apr_table_addn(r->headers_in,  "Set-Cookie", setptmcookie);  /* So subrequest can pick them up! */
  }
  if (cookie && cookie[0] != '-') {
    D("Cookie(%s) 2", cookie);
    apr_table_addn(r->headers_in, "Cookie", cookie);  /* so internal redirect sees it */
  }
  if (idpnid && idpnid[0] != '-') {
    D("REMOTE_USER(%s)", idpnid);
    apr_table_set(r->subprocess_env, "REMOTE_USER", idpnid);
  }
  
  //apr_table_setn(r->subprocess_env,
  //		 apr_psprintf(r->pool, "%sLDIF", cf->mod_saml_attr_prefix), ldif);
  D("SSO OK ret(%d) uri(%s) filename(%s) path_info(%s)", ret, r->uri, r->filename, r->path_info);
  return ret;
}

/*() Send Apache response.
 *
 * This is considered internal function to mod_auth_saml, called by chkuid().
 * You should not call this directly, unless you know what you are doing. */

/* Called by:  chkuid */
static int send_res(zxid_conf* cf, request_rec* r, char* res)
{
  int len;
  char* p;
#if 0
  apr_table_setn(r->headers_out,     "Cache-Control", "no-cache");
  apr_table_setn(r->err_headers_out, "Cache-Control", "no-cache");
  apr_table_setn(r->headers_out,     "Pragma", "no-cache");
  apr_table_setn(r->err_headers_out, "Pragma", "no-cache");
#endif
  res += 14;  /* skip "Content-Type:" (14 chars) */
  DD("RES(%s)", res);
  p = strchr(res, '\r');
  *p = 0;
  //apr_table_setn(r->headers_out, "Content-Type", res);
  DD("CONTENT-TYPE(%s)", res);
  ap_set_content_type(r, res);
  res = p+2 + 16;  /* skip "Content-Length:" (16 chars) */
  sscanf(res, "%d", &len);
  res = strchr(res, '\r') + 4; /* skip CRFL pair before body */
  DD("CONTENT-LENGTH(%d)", len);
  ap_set_content_length(r, len);
  
  if (errmac_debug & MOD_AUTH_SAML_INOUT) INFO("LEN(%d) strlen(%d) RES(%s)", len, (int)strlen(res), res);
  
  //register_timeout("send", r);
  ap_send_http_header(r);
  if (!r->header_only)
    ap_rputs(res, r);  //send_fd(f, r);  rprintf(); ap_rwrite()
  return DONE;   /* Prevent further hooks from processing the request. */
}

/*() Read POST input, Apache style
 *
 * This is considered internal function to mod_auth_saml, called by chkuid().
 * You should not call this directly, unless you know what you are doing. */

/* Called by:  chkuid */
static char* read_post(zxid_conf* cf, request_rec* r)
{
  int len, ret;
  char* res;
  char* p;
  /*len = apr_table_get(r->headers_in, "Content-Length");*/
  
  /* Ask Apache to dechunk data if it is chunked. */
  ret = ap_setup_client_block(r, REQUEST_CHUNKED_DECHUNK);
  if (ret != OK) {
    ERR("ap_setup_client_block(r, REQUEST_CHUNKED_DECHUNK): %d", ret);
    return 0;
  }
  
  /* This function will send a 100 Continue response if the client is
   * waiting for that. If the client isn't going to send data, then this
   * function will return 0. */
  if (!ap_should_client_block(r)) {
    len = 0;
  } else {
    len = r->remaining;
  }
  res = p = apr_palloc(r->pool, len + 1);
  res[len] = 0;
  D("remaining=%d", len);
  
  while (len > 0) {
    /* Read data from the client. Returns 0 on EOF or error, the
     * number of bytes otherwise.   */
    ret = ap_get_client_block(r, p, len);
    if (!ret) {
      ap_log_rerror(APLOG_MARK, APLOG_ERR, 0, r, "Failed to read POST data from client.");
      return 0;  /* HTTP_INTERNAL_SERVER_ERROR */
    }
    
    p += ret;
    len -= ret;
  }
  if (errmac_debug & MOD_AUTH_SAML_INOUT) INFO("POST(%s)", res);
  return res;
}

/* 0x6000 outf QS + JSON = no output on successful sso, the attrubutes are in session
 * 0x1000 debug
 * 0x0e00 11 + 10 = Generate all HTML + Mgmt w/headers as string
 * 0x00a0 10 + 10 = Login w/headers as string + Meta w/headers as string
 * 0x0008 10 + 00 = SOAP w/headers as string + no auto redir, no exit(2) */
#define AUTO_FLAGS 0x6ea8

/*(i) Apache hook. Called from httpd-2.2.8/server/request.c: ap_process_request_internal()
 * ap_run_check_user_id(). Return value is processed in modules/http/http_request.c
 * and redirect is in ap_die(), http_protocol.c: ap_send_error_response()
 *
 * It seems this function will in effect be called twice by Apache internals: once
 * to see if it would succeed and second time to actually do the work. This is rather
 * wasteful, but we do not know any easy way to avoid it.
 *
 * Originally this was just for SSO, but nowdays we also support WSP mode.  */

/* Called by: */
static int chkuid(request_rec* r)
{
  int ret, len, uri_len, url_len, args_len;
  char* p;
  char* res;
  char buf[256];
  const char* cookie_hdr=0;
  const char* set_cookie_hdr;
  const char* cur_auth;
  zxid_conf* cf = dir_cf(r);
  zxid_cgi cgi;
  zxid_ses ses;
  ZERO(&cgi, sizeof(zxid_cgi));
  ZERO(&ses, sizeof(zxid_ses));
  cgi.uri_path = r?r->uri:0;
  cgi.qs = r?r->args:0;

  D("===== START %s req=%p uri(%s) args(%s) pid=%d cwd(%s)", ZXID_REL, r, r?STRNULLCHKNULL(r->uri):"(r null)", r?STRNULLCHKNULL(r->args):"(r null)", getpid(), getcwd(buf,sizeof(buf)));
  if (cf->wd && *cf->wd)
    chdir(cf->wd);  /* Ensure the working dir is not / (sometimes Apache httpd changes dir) */
  D_INDENT("chkuid: ");

  if (r->main) {  /* subreq can't come from net: always auth. */
    D("sub ok %d", OK);
    D_DEDENT("chkuid: ");
    return OK;
  }
  
  cur_auth = ap_auth_type(r);   /* From directive: AuthType "saml" */
  if (!cur_auth || strcasecmp(cur_auth, "saml")) {
    D("not saml auth (%s) %d", STRNULLCHKD(cur_auth), DECLINED);
    D_DEDENT("chkuid: ");
    return DECLINED;
  }
  r->ap_auth_type = "saml";
  
  /* Probe for Session ID in cookie. Also propagate the cookie to subrequests. */

  if (cf->ses_cookie_name && *cf->ses_cookie_name) {
    cookie_hdr = apr_table_get(r->headers_in, "Cookie");
    if (cookie_hdr) {
      D("found cookie(%s) 3", STRNULLCHK(cookie_hdr));
      zxid_get_sid_from_cookie(cf, &cgi, cookie_hdr);
      apr_table_addn(r->headers_out, "Cookie", cookie_hdr);       /* Pass cookies to subreq */
      DD("found cookie(%s) 5", STRNULLCHK(cookie_hdr));
      /* Kludge to get subrequest to set-cookie, i.e. on return path */
      set_cookie_hdr = apr_table_get(r->headers_in, "Set-Cookie");
      if (set_cookie_hdr) {
	D("subrequest set-cookie(%s) 2", set_cookie_hdr);
	apr_table_addn(r->headers_out, "Set-Cookie", set_cookie_hdr);
      }
    }
  }

  /* Redirect hack: deal with externally imposed ACS url that does not follow zxid convention. */
  
  args_len = r->args?strlen(r->args):0;
  if (cf->redirect_hack_imposed_url && !strcmp(r->uri, cf->redirect_hack_imposed_url)) {
    D("Redirect hack: mapping(%s) imposed to zxid(%s)", r->uri, cf->redirect_hack_zxid_url);
    r->uri = cf->redirect_hack_zxid_url;
    if (cf->redirect_hack_zxid_qs && *cf->redirect_hack_zxid_qs) {
      if (args_len) {
	/* concatenate redirect_hack_zxid_qs with existing qs */
	len = strlen(cf->redirect_hack_zxid_qs);
	p = apr_palloc(r->pool, len+1+args_len+1);
	strcpy(p, cf->redirect_hack_zxid_qs);
	p[len] = '&';
	strcpy(p+len+1, r->args);
	cgi.qs = r->args = p;
      } else {
	cgi.qs = r->args = cf->redirect_hack_zxid_qs;
      }
      args_len = strlen(r->args);
    }
    D("After hack uri(%s) args(%s)", STRNULLCHK(r->uri), STRNULLCHK(r->args));
  }
  
  DD("HERE1 args_len=%d cgi=%p k(%s) args(%s)", args_len, &cgi, STRNULLCHKNULL(cgi.skin), STRNULLCHKNULL(r->args));
  if (args_len) {
    /* leak the dup str: the cgi structure will take references to this and change &s to nuls */
    p = apr_palloc(r->pool, args_len + 1);
    strcpy(p, r->args);
    zxid_parse_cgi(cf, &cgi, p);
    DD("HERE2 args_len=%d cgi=%p k(%s) args(%s)", args_len, &cgi, STRNULLCHKNULL(cgi.skin), STRNULLCHKNULL(r->args));
  }
  /* Check if we are supposed to enter zxid due to URL suffix - to
   * process protocol messages rather than ordinary pages. To do this
   * correctly we need to ignore the query string part. We are looking
   * here at exact match, like /protected/saml, rather than any of
   * the other documents under /protected/ (which are handled in the
   * else clause). Both then and else -clause URLs are defined as requiring
   * SSO by virtue of the web server configuration. */

  uri_len = strlen(r->uri);
  url_len = strlen(cf->url);
  for (p = cf->url + url_len - 1; p > cf->url; --p)
    if (*p == '?')
      break;
  if (p == cf->url)
    p = cf->url + url_len;
  
  if (url_len >= uri_len && !memcmp(p - uri_len, r->uri, uri_len)) {  /* Suffix match */
    if (errmac_debug & MOD_AUTH_SAML_INOUT) INFO("matched uri(%s) cf->url(%s) qs(%s) rs(%s) op(%c)", r->uri, cf->url, STRNULLCHKNULL(r->args), STRNULLCHKNULL(cgi.rs), cgi.op);
    if (r->method_number == M_POST) {
      res = read_post(cf, r);   /* Will print some debug output */
      if (res) {
	if (cgi.op == 'S') {
	  ret = zxid_sp_soap_parse(cf, &cgi, &ses, strlen(res), res);
	  D("POST soap parse returned %d", ret);
#if 0
	  /* *** TODO: SOAP response should not be sent internally unless there is auto */
	  if (ret == ZXID_SSO_OK) {
	    ret = zxid_simple_ab_pep(cf, &ses, res_len, auto_flags);
	    D_DEDENT("chkuid: ");
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
    if (!cgi.sid || !zxid_get_ses(cf, &ses, cgi.sid)) {
      D("No session(%s) active op(%c)", STRNULLCHK(cgi.sid), cgi.op);
    } else {
      res = zxid_simple_ses_active_cf(cf, &cgi, &ses, 0, AUTO_FLAGS);
      if (res)
	goto process_zxid_simple_outcome;
    }
    /* not logged in, fall thru */
  } else if (zx_wildcard_pat_match(cf->wsp_pat, r->uri)) {
    /* WSP case */
    if (r->method_number == M_POST) {
      res = read_post(cf, r);   /* Will print some debug output */
      if (zxid_wsp_validate(cf, &ses, 0, res)) {
	D("WSP(%s) request valid", r->uri);
	D("WSP CALL uri(%s) filename(%s) path_info(%s)", r->uri, r->filename, r->path_info);
	ret = pool2apache(cf, r, ses.at);
	D_DEDENT("chkuid: ");
	return ret;
	/* Essentially we fall through and let CGI processing happen.
	 * *** how to decorate the CGI return value?!? New hook needed? --Sampo */
      } else {
	ERR("WSP(%s) request validation failed", r->uri);
	D_DEDENT("chkuid: ");
	return HTTP_FORBIDDEN;
      }
    } else {
      ERR("WSP(%s) must be called with POST method %d", r->uri, r->method_number);
      D_DEDENT("chkuid: ");
      return HTTP_METHOD_NOT_ALLOWED;
    }
  } else {
    /* Some other page. Just check for session. */
    if (errmac_debug & MOD_AUTH_SAML_INOUT) INFO("other page uri(%s) qs(%s) cf->url(%s) uri_len=%d url_len=%d", r->uri, STRNULLCHKNULL(r->args), cf->url, uri_len, url_len);
    if (r->args && r->args[0] == 'l') {
      D("Detect login(%s)", r->args);
    } else
      cgi.op = 'E';   /* Trigger IdP selection screen */
    p = apr_palloc(r->pool, uri_len+1+args_len+1);
    strcpy(p, r->uri);
    if (args_len) {
      p[uri_len] = '?';
      strcpy(p+uri_len+1, r->args);
    }
    DD("HERE3 args_len=%d cgi=%p k(%s) uri(%s) args(%s) rs(%s)", args_len, &cgi, STRNULLCHKNULL(cgi.skin), r->uri, STRNULLCHKNULL(r->args), p);
    /* cgi.rs will be copied to ses->rs and from there in ab_pep to resource-id.
     * We compress and safe_base64 encode it to protect any URL special characters.
     * *** seems that at this point the p is not just rs, but the entire local URL --Sampo */
    cgi.rs = zxid_deflate_safe_b64_raw(cf->ctx, -2, p);
    if (cf->defaultqs && cf->defaultqs[0]) {
      if (errmac_debug & MOD_AUTH_SAML_INOUT) INFO("DEFAULTQS(%s)", cf->defaultqs);
      zxid_parse_cgi(cf, &cgi, apr_pstrdup(r->pool, cf->defaultqs));
    }
    if (cgi.sid && cgi.sid[0] && zxid_get_ses(cf, &ses, cgi.sid)) {
      res = zxid_simple_ses_active_cf(cf, &cgi, &ses, 0, AUTO_FLAGS);
      if (res)
	goto process_zxid_simple_outcome;
    } else {
      D("No session(%s) active op(%c)", STRNULLCHK(cgi.sid), cgi.op);
    }
    D("other page: no_ses uri(%s) templ(%s) tf(%s) k(%s) cgi=%p", r->uri, STRNULLCHKNULL(cgi.templ), STRNULLCHKNULL(cf->idp_sel_templ_file), cgi.skin, &cgi);
  }
step_up:
  res = zxid_simple_no_ses_cf(cf, &cgi, &ses, 0, AUTO_FLAGS);

process_zxid_simple_outcome:
  if (cookie_hdr && cookie_hdr[0]) {
    D("Passing cookie(%s) to environment", cookie_hdr);
    zxid_add_attr_to_ses(cf, &ses, "cookie", zx_dup_str(cf->ctx, cookie_hdr));
  }

  switch (res[0]) {
  case 'L':
    if (errmac_debug & MOD_AUTH_SAML_INOUT) INFO("REDIR(%s)", res);
    apr_table_setn(r->headers_out, "Location", res+10);
    D_DEDENT("chkuid: ");
    return HTTP_SEE_OTHER;
  case 'C':
    if (errmac_debug & MOD_AUTH_SAML_INOUT) INFO("CONTENT(%s)", res);
    ret = send_res(cf, r, res);
    D_DEDENT("chkuid: ");
    return ret;
  case 'z':
    INFO("User not authorized %d", 0);
    D_DEDENT("chkuid: ");
    return HTTP_FORBIDDEN;
  case 0: /* Logged in case */
    D("SSO OK pre uri(%s) filename(%s) path_info(%s)", r->uri, r->filename, r->path_info);
    ret = pool2apache(cf, r, ses.at);
    D_DEDENT("chkuid: ");
    return ret;
#if 0
  case 'd': /* Logged in case */
    if (errmac_debug & MOD_AUTH_SAML_INOUT) INFO("SSO OK LDIF(%s)", res);
    D("SSO OK pre uri(%s) filename(%s) path_info(%s)", r->uri, r->filename, r->path_info);
    ret = ldif2apache(cf, r, res);
    D_DEDENT("chkuid: ");
    return ret;
#endif
  default:
    ERR("Unknown zxid_simple response(%s)", res);
    D_DEDENT("chkuid: ");
    return HTTP_INTERNAL_SERVER_ERROR;
  }

  D("final ok %d", OK);
  D_DEDENT("chkuid: ");
  return OK;
}

/* ------------------------ CONF -------------------------- */

/*() Process ZXIDDebug directive in Apache configuration file.
 *
 * This is considered internal function to mod_auth_saml. Do not call directly. */

/* Called by: */
static const char* set_debug(cmd_parms* cmd, void* st, const char* arg) {
  char buf[256];
  D("old debug=%x, new debug(%s)", errmac_debug, arg);
  sscanf(arg, "%i", &errmac_debug);
  INFO("debug=0x%x now arg(%s) cwd(%s)", errmac_debug, arg, getcwd(buf, sizeof(buf)));
  return 0;
}

/*() Process ZXIDConf directive in Apache configuration file.
 * Can be called any number of times to set additional parameters.
 *
 * This is considered internal function to mod_auth_saml. Do not call directly. */

/* Called by: */
static const char* set_zxid_conf(cmd_parms* cmd, void* st, const char* arg) {
  int len;
  char* buf;
  zxid_conf* cf = (zxid_conf*)st;
  D("arg(%s) cf=%p", arg, cf);
  len = strlen(arg);
  buf = ZX_ALLOC(cf->ctx, len+1);
  memcpy(buf, arg, len+1);
  zxid_parse_conf(cf, buf);
  return 0;
}

const command_rec zxid_apache_commands[] = {
  AP_INIT_TAKE1("ZXIDDebug", set_debug, 0, OR_AUTHCFG,
		"Enable debugging output to stderr. 0 to disable."),
  AP_INIT_TAKE1("ZXIDConf", set_zxid_conf, 0, OR_AUTHCFG,
		"Supply ZXID CONF string. May be supplied multiple times."),
  {0}
};


#define ZXID_APACHE_DEFAULT_CONF ""  /* defaults will reign, including path /var/zxid */

/*() Create default configuration in response for Apache <Location> or <Directory>
 * directives. This is then augmented by ZXIDConf directives.
 * This code may run twice: once for syntax check, and then again for
 * production use. Currently we just redo the work.
 *
 * This is considered internal function to mod_auth_saml. Do not call directly. */

/* Called by: */
static void* dirconf(apr_pool_t* p, char* d)
{
  zxid_conf* cf;
  strncpy(errmac_instance, "\tmas", sizeof(errmac_instance));
  cf = apr_palloc(p, sizeof(zxid_conf));
  ZERO(cf, sizeof(zxid_conf));
  cf->ctx = apr_palloc(p, sizeof(struct zx_ctx));
  zx_reset_ctx(cf->ctx);
  D("cf=%p ctx=%p d(%s)", cf, cf->ctx, STRNULLCHKD(d));
  /* *** set malloc func ptr in ctx to use apr_palloc() */
  zxid_conf_to_cf_len(cf, -1, ZXID_APACHE_DEFAULT_CONF);
  cf->path_supplied = 0;
  return cf;
}

/* ------------------------ Hooks -------------------------- */

/*() Register Apache hook for mod_auth_saml
 *
 * This is considered internal function to mod_auth_saml. Do not call directly. */

/* Called by: */
static void reghk(apr_pool_t *p) {
  D("pool=%p", p);
  //ap_hook_access_checker(authusr,  0, 0, APR_HOOK_MIDDLE);
  ap_hook_check_user_id( chkuid,   0, 0, APR_HOOK_MIDDLE);
  //ap_hook_post_config(   postconf, 0, 0, APR_HOOK_MIDDLE);
  /*ap_hook_child_init(    chldinit, 0, 0, APR_HOOK_MIDDLE);*/
}

/* This extern variable is used as first argument to LoadModule in httpd.conf,
 * E.g: LoadModule auth_saml_module modules/mod_auth_saml.so */

module AP_MODULE_DECLARE_DATA auth_saml_module = {
  STANDARD20_MODULE_STUFF,
  dirconf,
  0, //dirmerge,
  0, //srvconf,
  0, //srvmerge,
  zxid_apache_commands,
  reghk
};

/* EOF - mod_auth_saml.c */
