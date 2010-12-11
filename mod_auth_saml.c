/* mod_auth_saml.c  -  Handwritten functions for Apache mod_auth_saml module
 * Copyright (c) 2009-2010 Sampo Kellomaki (sampo@iki.fi), All Rights Reserved.
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
 *
 * Idea: set REMOTE_USER header
 */

#define _LARGEFILE64_SOURCE   /* So off64_t is found, see: man 3 lseek64 */

#include <zx/errmac.h>
#include <zx/zxid.h>
#include <zx/zxidconf.h>
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
 * You should not call this directly, unless you know what you are doing. */

/* Called by:  chkuid */
static int pool2apache(zxid_conf* cf, request_rec* r, struct zxid_attr* pool)
{
  int ret = OK;
  char* name;
  char* rs = 0;
  char* setcookie = 0;
  char* cookie = 0;
  char* idpnid = 0;
  struct zxid_map* map;
  struct zxid_attr* at;
  struct zxid_attr* av;
  
  /* Length computation pass */

  for (at = pool; at; at = at->n) {
    map = zxid_find_map(cf->outmap, at->name);
    if (map) {
      if (map->rule == ZXID_MAP_RULE_DEL) {
	D("attribute(%s) filtered out by del rule in OUTMAP", at->name);
	continue;
      }
      at->map_val = zxid_map_val(cf, 0, 0, map, at->name, at->val);
      if (map->dst && map->dst[0] && map->src && map->src[0] != '*') {
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

      D("ATTR(%s)=VAL(%s)", at->name, at->val);
      /* *** handling of multivalued attributes (right now only last is preserved) */
      name = apr_psprintf(r->pool, "%s%s", cf->mod_saml_attr_prefix, at->name);
      apr_table_set(r->subprocess_env, name, at->val);
      for (av = at->nv; av; av = av->n)
	apr_table_set(r->subprocess_env, name, av->val);
    }
    if (     !strcmp(at->name, "rs"))        rs = at->val;        /* Capture special */
    else if (!strcmp(at->name, "idpnid"))    idpnid = at->val;
    else if (!strcmp(at->name, "setcookie")) setcookie = at->val;
    else if (!strcmp(at->name, "cookie"))    cookie = at->val;
  }

  if (rs && rs[0] && rs[0] != '-') {
    if (strcmp(r->uri, rs)) {  /* Different, need external or internal redirect */
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
  if (setcookie && setcookie[0] != '-') {
    D("Set-Cookie(%s)", setcookie);
    apr_table_setn(r->headers_out, "Set-Cookie", setcookie);
    apr_table_setn(r->err_headers_out, "Set-Cookie", setcookie);  /* Only way to get redir to set header */
    apr_table_setn(r->headers_in,  "Set-Cookie", setcookie);  /* So subrequest can pick them up! */
  }
  if (cookie && cookie[0] != '-') {
    D("Cookie(%s)", cookie);
    apr_table_setn(r->headers_in, "Cookie", cookie);  /* so internal redirect sees it */
  }
  if (idpnid && idpnid[0] != '-') {
    D("REMOTE_USER(%s)", idpnid);
    apr_table_set(r->subprocess_env, "REMOTE_USER", idpnid);
  }
  
  //apr_table_setn(r->subprocess_env,
  //		 apr_psprintf(r->pool, "%sLDIF", cf->mod_saml_attr_prefix), ldif);
  D("SSO OK ret(%d) uri(%s) filename(%s) path_info(%s) rs(%s)", ret, r->uri, r->filename, r->path_info, STRNULLCHKQ(rs));
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
  res += 14;
  DD("RES(%s)", res);
  p = strchr(res, '\r');
  *p = 0;
  //apr_table_setn(r->headers_out, "Content-Type", res);
  DD("CONTENT-TYPE(%s)", res);
  ap_set_content_type(r, res);
  res = p+2 + 16;  /* Content-Length: */
  sscanf(res, "%d", &len);
  res = strchr(res, '\r') + 4; /* skip CRFL pair before body */
  DD("CONTENT-LENGTH(%d)", len);
  ap_set_content_length(r, len);
  
  if (zx_debug & MOD_AUTH_SAML_INOUT) INFO("LEN(%d) strlen(%d) RES(%s)", len, strlen(res), res);
  
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
  if (zx_debug & MOD_AUTH_SAML_INOUT) INFO("POST(%s)", res);
  return res;
}

/* 0x6000 outf QS + JSON = no output
 * 0x1000 debug
 * 0x0e00 11 + 10 = Generate all HTML + Mgmt w/headers as string
 * 0x00a0 10 + 10 = Login w/headers as string + Meta w/headers as string
 * 0x0008 10 + 00 = SOAP w/headers as string + no auto redir, no exit(2) */
#define AUTO_FLAGS 0x6ea8

/*(i) Apache hook. Called from httpd-2.2.8/server/request.c: ap_process_request_internal()
 * ap_run_check_user_id(). Return value is processed in modules/http/http_request.c
 * and redirect is in ap_die(), http_protocol.c: ap_send_error_response()  */

/* Called by: */
static int chkuid(request_rec* r)
{
  int ret, uri_len, url_len;
  char* p;
  char* res;
  const char* cookie_hdr;
  const char* cur_auth;
  struct zx_str* ss;
  zxid_conf* cf = dir_cf(r);
  zxid_cgi cgi;
  zxid_ses ses;
  ZERO(&cgi, sizeof(zxid_cgi));
  ZERO(&ses, sizeof(zxid_ses));

  D("===== START %s req=%p uri(%s) args(%s)", ZXID_REL, r, r?STRNULLCHK(r->uri):"", r?STRNULLCHK(r->args):"");
  
  if (r->main) {  /* subreq can't come from net: always auth. */
    D("sub ok %d", OK);
    return OK;
  }
  
  cur_auth = ap_auth_type(r);   /* From directive: AuthType "saml" */
  if (!cur_auth || strcasecmp(cur_auth, "saml")) {
    D("not saml auth (%s) %d", STRNULLCHKD(cur_auth), DECLINED);
    return DECLINED;
  }
  r->ap_auth_type = "saml";
  
  if (cf->ses_cookie_name && *cf->ses_cookie_name) {
    cookie_hdr = apr_table_get(r->headers_in, "Cookie");
    if (cookie_hdr) {
      D("found cookie(%s)", STRNULLCHK(cookie_hdr));
      zxid_get_sid_from_cookie(cf, &cgi, cookie_hdr);
      /* Kludge to get subrequest to set-cookie, i.e. on return path */
      cookie_hdr = apr_table_get(r->headers_in, "Set-Cookie");
      if (cookie_hdr) {
	D("subrequest set-cookie(%s)", cookie_hdr);
	apr_table_setn(r->headers_out, "Set-Cookie", cookie_hdr);
      }
    }
  }

  /* Redirect hack */
  
  if (cf->redirect_hack_imposed_url && !strcmp(r->uri, cf->redirect_hack_imposed_url)) {
    D("Redirect hack: mapping(%s) imposed to zxid(%s)", r->uri, cf->redirect_hack_zxid_url);
    r->uri = cf->redirect_hack_zxid_url;
    if (cf->redirect_hack_zxid_qs) {
      if (r->args) {
	ss = zx_strf(cf->ctx, "%s&%s", cf->redirect_hack_zxid_qs, r->args);
	r->args = ss->s;
	ZX_FREE(cf->ctx, ss);
      } else {
	r->args = cf->redirect_hack_zxid_qs;
      }
    }
    D("After hack uri(%s) args(%s)", STRNULLCHK(r->uri), STRNULLCHK(r->args));
  }
  
  /* Check if we are supposed to enter zxid due to URL suffix. To do this
   * correctly we need to ignore the query string part. */
  uri_len = strlen(r->uri);
  url_len = strlen(cf->url);
  for (p = cf->url + url_len - 1; p > cf->url; --p)
    if (*p == '?')
      break;
  if (p == cf->url)
    p = cf->url + url_len;
  
  if (url_len >= uri_len && !memcmp(p - uri_len, r->uri, uri_len)) {  /* Suffix match */
    zxid_parse_cgi(&cgi, r->args);
    if (zx_debug & MOD_AUTH_SAML_INOUT) INFO("matched uri(%s) cf->url(%s) qs(%s) rs(%s) op(%c)", r->uri, cf->url, r->args, cgi.rs, cgi.op);
    if (r->method_number == M_POST) {
      res = read_post(cf, r);   /* Will print some debug output */
      if (res) {
	if (cgi.op == 'S') {
	  ret = zxid_sp_soap_parse(cf, &cgi, &ses, strlen(res), res);
	  D("POST soap parse returned %d", ret);
#if 0
	  /* *** TODO: SOAP response should not be sent internally unless there is auto */
	  if (ret == ZXID_SSO_OK)
	    return zxid_simple_ab_pep(cf, &ses, res_len, auto_flags);
	  if (auto_flags & ZXID_AUTO_SOAPC || auto_flags & ZXID_AUTO_SOAPH) {
	    res = zx_dup_cstr(cf->ctx, "n");
	    if (res_len)
	      *res_len = 1;
	    goto done;
	  }
	  res = zx_dup_cstr(cf->ctx, ret ? "n" : "*** SOAP error (enable debug if you want to see why)"); 
	  if (res_len)
	    *res_len = strlen(res);
	  goto done;
#endif
	} else {
	  zxid_parse_cgi(&cgi, res);
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
  } else {
    /* Some other page. Just check for session. */
    if (zx_debug & MOD_AUTH_SAML_INOUT) INFO("other page uri(%s) qs(%s) cf->url(%s) uri_len=%d url_len=%d", r->uri, STRNULLCHKNULL(r->args), cf->url, uri_len, url_len);
    cgi.op = 'E';
    cgi.rs = r->uri;  /* Will be copied to ses->rs and from there in ab_pep to resource-id */
    if (cf->defaultqs && cf->defaultqs[0]) {
      if (zx_debug & MOD_AUTH_SAML_INOUT) INFO("DEFAULTQS(%s)", cf->defaultqs);
      zxid_parse_cgi(&cgi, cf->defaultqs);
    }
    if (cgi.sid && cgi.sid[0] && zxid_get_ses(cf, &ses, cgi.sid)) {
      res = zxid_simple_ses_active_cf(cf, &cgi, &ses, 0, AUTO_FLAGS);
      if (res)
	goto process_zxid_simple_outcome;
    } else {
      D("No session(%s) active op(%c)", STRNULLCHK(cgi.sid), cgi.op);
    }
    D("other page: no_ses uri(%s)", r->uri);
  }
step_up:  
  res = zxid_simple_no_ses_cf(cf, &cgi, &ses, 0, AUTO_FLAGS);

process_zxid_simple_outcome:
  switch (res[0]) {
  case 'L':
    if (zx_debug & MOD_AUTH_SAML_INOUT) INFO("REDIR(%s)", res);
    apr_table_setn(r->headers_out, "Location", res+10);
    return HTTP_SEE_OTHER;
  case 'C':
    if (zx_debug & MOD_AUTH_SAML_INOUT) INFO("CONTENT(%s)", res);
    return send_res(cf, r, res);
  case 'z':
    INFO("User not authorized %d", 0);
    return HTTP_UNAUTHORIZED;
  case 0: /* Logged in case */
    D("SSO OK pre uri(%s) filename(%s) path_info(%s)", r->uri, r->filename, r->path_info);
    return pool2apache(cf, r, ses.at);
#if 0
  case 'd': /* Logged in case */
    if (zx_debug & MOD_AUTH_SAML_INOUT) INFO("SSO OK LDIF(%s)", res);
    D("SSO OK pre uri(%s) filename(%s) path_info(%s)", r->uri, r->filename, r->path_info);
    return ldif2apache(cf, r, res);
#endif
  default:
    ERR("Unknown zxid_simple response(%s)", res);
    return HTTP_INTERNAL_SERVER_ERROR;
  }

  D("final ok %d", OK);
  return OK;
}

/* ------------------------ CONF -------------------------- */

/*() Process ZXIDDebug directive in Apache configuration file.
 *
 * This is considered internal function to mod_auth_saml. Do not call directly. */

/* Called by: */
static const char* set_debug(cmd_parms* cmd, void* st, const char* arg) {
  D("old debug=%x, new debug(%s)", zx_debug, arg);
  sscanf(arg, "%i", &zx_debug);
  INFO("debug=0x%x now arg(%s)", zx_debug, arg);
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
 * production use. Curently we just redo the work.
 *
 * This is considered internal function to mod_auth_saml. Do not call directly. */

/* Called by: */
static void* dirconf(apr_pool_t* p, char* d)
{
  zxid_conf* cf = apr_palloc(p, sizeof(zxid_conf));
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
