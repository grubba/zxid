/* zxidsimp.c  -  Handwritten zxid_simple() API
 * Copyright (c) 2009-2010 Sampo Kellomaki (sampo@iki.fi), All Rights Reserved.
 * Copyright (c) 2007-2009 Symlabs (symlabs@symlabs.com), All Rights Reserved.
 * Author: Sampo Kellomaki (sampo@iki.fi)
 * This is confidential unpublished proprietary source code of the author.
 * NO WARRANTY, not even implied warranties. Contains trade secrets.
 * Distribution prohibited unless authorized in writing.
 * Licensed under Apache License 2.0, see file COPYING.
 * $Id: zxidsimp.c,v 1.64 2010-01-08 02:10:09 sampo Exp $
 *
 * 17.1.2007, created --Sampo
 * 2.2.2007,  improved the LDIF return --Sampo
 * 9.3.2008,  refactored the logged in and need login cases to subroutines --Sampo
 * 7.10.2008, added documentation --Sampo
 * 4.9.2009,  added attribute broker and PEP functionality --Sampo
 *
 * Login button abbreviations
 * A2 = SAML 2.0 Artifact Profile
 * P2 = SAML 2.0 POST Profile
 * S2 = SAML 2.0 POST Simple Sign
 * A12 = Liberty ID-FF 1.2 Artifact Profile
 * P12 = Liberty ID-FF 1.2 POST Profile
 * A1 = Bare SAML 1.x Artifact Profile
 * P1 = Base SAML 1.x POST Profile
 * A0 = WS-Federation Artifact Profile
 * P0 = WS-Federation POST Profile
 */

#include <memory.h>
#include <string.h>
#include <unistd.h>

#include "errmac.h"
#include "zx.h"
#include "zxid.h"
#include "zxidconf.h"
#include "c/zxidvers.h"

/*() Convert configuration string ~conf~ to configuration object ~cf~. */

/* Called by:  dirconf, main x2, zxid_az, zxid_fed_mgmt_len, zxid_idp_list_len, zxid_idp_select_len, zxid_new_conf_to_cf, zxid_simple_len */
int zxid_conf_to_cf_len(zxid_conf* cf, int conf_len, const char* conf)
{
#if 1
  if (!cf->ctx) {
    cf->ctx = zx_init_ctx();
    if (!cf->ctx) {
      ERR("Failed to alloc zx_ctx %d",0);
      exit(2);
    }
  }
  zxid_init_conf(cf, ZXID_PATH);
#ifdef USE_CURL
  LOCK(cf->curl_mx, "curl init");
  cf->curl = curl_easy_init();
  if (!cf->curl) {
    ERR("Failed to initialize libcurl %d",0);
    UNLOCK(cf->curl_mx, "curl init");
    exit(2);
  }
  UNLOCK(cf->curl_mx, "curl init");
#endif
#else
  zxid_init_conf_ctx(cf, ZXID_PATH /* N.B. Often this is overridden. */);
#endif
#if defined(ZXID_CONF_FILE) || defined(ZXID_CONF_FLAG)
  {
    char* buf;
    char* cc;
    int len, clen = conf_len == -1 && conf ? strlen(conf) : conf_len;

    if (!conf || conf_len < 5 || memcmp(conf, "PATH=", 5)) {
      /* No conf, or conf does not start by PATH: read from file default values */
      buf = ZX_ALLOC(cf->ctx, ZXID_MAX_CONF);
      len = read_all(ZXID_MAX_CONF-1, buf, "-conf_to_cf", "%szxid.conf", cf->path);
      if (len > 0) {
	buf[len] = 0;
	zxid_parse_conf_raw(cf, len, buf);
      }
    }
    
    if (conf && conf_len) {
      /* Copy the conf string because we are going to modify it in place. */
      cc = ZX_ALLOC(cf->ctx, clen+1);
      memcpy(cc, conf, clen);
      cc[clen] = 0;
      zxid_parse_conf_raw(cf, clen, cc);
    }
  }
#endif
  return 0;
}

/*() Create new ZXID configuration object given configuration string and
 * possibly configuration file.
 *
 * conf::   Configuration service
 * return:: Configuration object */

/* Called by:  main x6, zxcall_main, zxidwspcgi_main x2 */
zxid_conf* zxid_new_conf_to_cf(const char* conf)
{
  zxid_conf* cf = malloc(sizeof(zxid_conf));  /* *** direct use of malloc */
  D("malloc %p size=%d", cf, sizeof(zxid_conf));
  if (!cf) {
    ERR("out-of-memory %d", sizeof(zxid_conf));
    exit(1); /* *** perhaps too severe! */
  }
  cf = memset(cf, 0, sizeof(zxid_conf));
  zxid_conf_to_cf_len(cf, -1, conf);
  return cf;
}

/* ------------ zxid_fed_mgmt() ------------ */

/*(i) Generate Single Logout button and possibly other federation management
 * buttons for use in logged in state of the app HTML GUI.
 *
 * Either outputs the management screen to stdout or returns string of HTML (at specified
 * automation level). If res_len is supplied, the string length is returned in res_len.
 * Otherwise you can just run strlen() on return value.
 *
 * N.B. More complete documentation is available in <<link: zxid-simple.pd>> (*** fixme) */

/* Called by:  zxid_fed_mgmt_len, zxid_simple_ses_active_cf */
char* zxid_fed_mgmt_cf(zxid_conf* cf, int* res_len, int sid_len, char* sid, int auto_flags)
{
  char* res;
  struct zx_str* ss;
  struct zx_str* ss2;
  int slen = sid_len == -1 && sid ? strlen(sid) : sid_len;
  if (auto_flags & ZXID_AUTO_DEBUG) zxid_set_opt(cf, 1, 1);

  if (cf->log_level>1)
    zxlog(cf, 0, 0, 0, 0, 0, 0, 0, "N", "W", "MGMT", 0, "sid(%.*s)", sid_len, STRNULLCHK(sid));
  
  if ((auto_flags & ZXID_AUTO_FORMT) && (auto_flags & ZXID_AUTO_FORMF))
    ss = zx_strf(cf->ctx,
		 "%s"
#ifdef ZXID_USE_POST
		 "<form method=post action=\"%s?o=P\">\n"
#else
		 "<form method=get action=\"%s\">\n"
#endif
		 "<input type=hidden name=s value=\"%.*s\">\n"
		 "%s%s\n"
		 "</form>%s%s%s%s",
		 cf->mgmt_start,
		 cf->url,
		 slen, STRNULLCHK(sid),
		 cf->mgmt_logout, cf->mgmt_defed,
		 cf->mgmt_footer, zxid_version_str(), STRNULLCHK(cf->dbg), cf->mgmt_end);
  else if (auto_flags & ZXID_AUTO_FORMT)
    ss = zx_strf(cf->ctx,
#ifdef ZXID_USE_POST
		 "<form method=post action=\"%s?o=P\">\n"
#else
		 "<form method=get action=\"%s\">\n"
#endif
		 "<input type=hidden name=s value=\"%.*s\">"
		 "%s%s\n"
		 "</form>",
		 cf->url,
		 slen, STRNULLCHK(sid),
		 cf->mgmt_logout, cf->mgmt_defed);
  else if (auto_flags & ZXID_AUTO_FORMF)
    ss = zx_strf(cf->ctx,
		 "<input type=hidden name=s value=\"%.*s\">"
		 "%s%s\n",
		 slen, STRNULLCHK(sid),
		 cf->mgmt_logout, cf->mgmt_defed);
  else
    ss = zx_dup_str(cf->ctx, "");

#if 0
  printf("COOKIE: foo\r\n");
  if (qs) printf("QS(%s)\n", qs);
  if (got>0) printf("GOT(%.*s)\n", got, buf);
  if (cgi->err) printf("<p><font color=red><i>%s</i></font></p>\n", cgi->err);
  if (cgi->msg) printf("<p><i>%s</i></p>\n", cgi->msg);
  printf("User:<input name=user> PW:<input name=pw type=password>");
  printf("<input name=login value=\" Login \" type=submit>");
  printf("<h3>Technical options (typically hidden fields on production site)</h3>\n");
  printf("sid(%s) nid(%s) <a href=\"zxid?s=%s\">Reload</a>", ses->sid, ses->nid, ses->sid);
  if (cgi->dbg) printf("<p><form><textarea cols=100 row=10>%s</textarea></form>\n", cgi->dbg);
#endif

  if (auto_flags & ZXID_AUTO_MGMTC && auto_flags & ZXID_AUTO_MGMTH) {  /* Both H&C: CGI */
    printf("Content-Type: text/html" CRLF "Content-Length: %d" CRLF2 "%.*s",
	   ss->len, ss->len, ss->s);
    zx_str_free(cf->ctx, ss);
    return 0;
  }

  if (auto_flags & (ZXID_AUTO_MGMTC | ZXID_AUTO_MGMTH)) {
    if (auto_flags & ZXID_AUTO_MGMTH) {  /* H only: return both H and C */
      D("With headers 0x%x", auto_flags);
      ss2 = zx_strf(cf->ctx, "Content-Type: text/html" CRLF "Content-Length: %d" CRLF2 "%.*s",
		    ss->len, ss->len, ss->s);
      zx_str_free(cf->ctx, ss);
    } else {
      D("No headers 0x%x", auto_flags);
      ss2 = ss;       /* C only */
    }
    res = ss2->s;
    DD("res(%s)", res);
    if (res_len)
      *res_len = ss2->len;
    ZX_FREE(cf->ctx, ss2);
    return res;
  }
  D("m(%.*s)", ss->len, ss->s);
  zx_str_free(cf->ctx, ss);
  if (res_len)
    *res_len = 1;
  return zx_dup_cstr(cf->ctx, "m");   /* Neither H nor C */
}

/* Called by:  zxid_fed_mgmt */
char* zxid_fed_mgmt_len(int conf_len, char* conf, int* res_len, char* sid, int auto_flags) {
  zxid_conf cf;
  zxid_conf_to_cf_len(&cf, conf_len, conf);
  return zxid_fed_mgmt_cf(&cf, 0, -1, sid, auto_flags);
}

/* Called by: */
char* zxid_fed_mgmt(char* conf, char* sid, int auto_flags) {
  return zxid_fed_mgmt_len(-1, conf, 0, sid, auto_flags);
}

/* ------------ zxid_an_page() ------------ */

#define BBMATCH(k, key, lim) (sizeof(k)-1 == (lim)-(key) && !memcmp((k), (key), sizeof(k)-1))

/*() Bang-bang expansions (!!VAR) understood in the templates. */

/* Called by:  zxid_template_page_cf */
static char* zxid_map_bangbang(zxid_conf* cf, zxid_cgi* cgi, const char* key, const char* lim)
{
  char* s;
  struct zx_str* ss;
  
  switch (*key) {
  case 'D':
    if (BBMATCH("DBG", key, lim)) return cgi->dbg;
    break;
  case 'E':
    if (BBMATCH("EID", key, lim)) {
      ss = zxid_my_entity_id(cf);
      s = ss->s; ZX_FREE(cf->ctx, ss);
      return s;
    }
    if (BBMATCH("ERR", key, lim)) return cgi->err;
    break;
  case 'M':
    if (BBMATCH("MSG", key, lim)) return cgi->msg;
    break;
  case 'U':
    if (BBMATCH("URL", key, lim)) return cf->url;
    break;
  case 'S':
    if (BBMATCH("SP_EID", key, lim)) return cgi->sp_eid;
    if (BBMATCH("SP_DPY_NAME", key, lim)) return cgi->sp_dpy_name;
    if (BBMATCH("SSOREQ", key, lim)) return cgi->ssoreq;
    break;
  case 'V':
    if (BBMATCH("VERSION", key, lim)) return zxid_version_str();
    break;
  case 'Z':
    if (BBMATCH("ZXAPP", key, lim)) return cgi->zxapp;
    break;
  }
  D("Unmatched bangbang key(%.*s), taken as empty.", lim-key, key);
  return 0;
}

/*() Expand a template. */

/* Called by:  zxid_simple_idp_show_an */
static struct zx_str* zxid_template_page_cf(zxid_conf* cf, zxid_cgi* cgi, const char* templ_path, const char* default_templ)
{
  char buf[8192];
  char* p;
  char* q;
  char* pp;
  struct zx_str* ss;
  int len, got = read_all(sizeof(buf)-1, buf, "templ", "%s", templ_path);
  if (got <= 0) {
    D("Template at path(%s) not found. Using default template.", templ_path);
    p = default_templ;
  } else if (got <= 0 || got == sizeof(buf)-1) {
    ERR("Template at path(%s) does not fit in buffer of %d. Using default template.", templ_path, sizeof(buf)-1);
    p = default_templ;
  } else
    p = buf;
  ss = zx_new_len_str(cf->ctx, strlen(p) + 4096);
  for (pp = ss->s; *p && pp < ss->s + ss->len; ) {
    if (p[0] == '!' && p[1] == '!' && A_Z_a_z_(p[2])) {
      for (q = p+=2; A_Z_a_z_(*p); ++p) ;
      q = zxid_map_bangbang(cf, cgi, q, p);
      if (!q || !*q)
	continue;
      len = strlen(q);
      if (pp + len >= ss->s + ss->len) {
	pp += len;
	break;
      }
      memcpy(pp, q, len);
      pp += len;
      continue;
    }
    *pp++ = *p++;
  }
  if (pp >= ss->s + ss->len) {
    ERR("Expansion of template too big. Does not fit in %d", ss->len);
    return 0;
  }
  *pp = 0;
  return ss;
}

/* ------------ zxid_idp_list() ------------ */

/*(i) Generate IdP selection buttons (Login buttons) for the IdPs that are
 * members of our Circle of Trust (CoT). This can be used as component for
 * developing your application specific (HTML) login screen.
 *
 * N.B. More complete documentation is available in <<link: zxid-simple.pd>> (*** fixme) */

/* Called by:  zxid_idp_list_cf, zxid_idp_select_zxstr_cf_cgi */
char* zxid_idp_list_cf_cgi(zxid_conf* cf, zxid_cgi* cgi, int* res_len, int auto_flags)
{
  int i;
  char* s;
  char mark[32];
  struct zx_str* ss;
  struct zx_str* dd;
  zxid_entity* idp;
  zxid_entity* idp_cdc;
  if (auto_flags & ZXID_AUTO_DEBUG) zxid_set_opt(cf, 1, 1);
  idp = zxid_load_cot_cache(cf);
  if (!idp) {
    D("No IdP's found %p", res_len);
    if (res_len)
      *res_len = 0;
    return "";
  }
  
  if ((auto_flags & ZXID_AUTO_FORMT) && (auto_flags & ZXID_AUTO_FORMF))
    ss = zx_dup_str(cf->ctx, "<h3>Login Using Known IdP</h3>\n");
  else
    ss = zx_dup_str(cf->ctx, "");

#define ZXID_USE_POPUP
#ifdef ZXID_USE_POPUP
  dd = zx_strf(cf->ctx, "%.*s<select name=d>\n", ss->len, ss->s);
  zx_str_free(cf->ctx, ss);
  ss = dd;
#endif

  D("Starting IdP processing... %p", idp);
  for (; idp; idp = idp->n) {
    if (!idp->ed->IDPSSODescriptor)
      continue;
    
    mark[0] = 0;
    if (cgi) {    /* Was IdP recommended in IdP list supplied via CDC? See zxid_cdc_check() */
      for (idp_cdc = cgi->idp_list, i=1; idp_cdc && idp_cdc != idp; idp_cdc = idp_cdc->n_cdc, ++i);
      if (cf->cdc_choice == ZXID_CDC_CHOICE_UI_ONLY_CDC && cgi->idp_list && !idp_cdc)
	continue;
      if (idp_cdc) {
	snprintf(mark, sizeof(mark), " CDC %d", i);
	mark[sizeof(mark)-1] = 0;
      }
    }

#ifdef ZXID_USE_POPUP
    dd = zx_strf(cf->ctx, "%.*s"
		 "<option value=\"%s\"> %s (%s) %s\n",
		 ss->len, ss->s, idp->eid, STRNULLCHK(idp->dpy_name), idp->eid, mark);
#else
    if (cf->show_tech) {
      dd = zx_strf(cf->ctx, "%.*s"
		   "<input type=submit name=\"l0%s\" value=\" Login to %s \">\n"
		   "<input type=submit name=\"l1%s\" value=\" Login to %s (A2) \">\n"
		   "<input type=submit name=\"l2%s\" value=\" Login to %s (P2) \">\n"
		   "<input type=submit name=\"l5%s\" value=\" Login to %s (S2) \">%s<br>\n",
		   ss->len, ss->s,
		   idp->eid, idp->eid,
		   idp->eid, idp->eid,
		   idp->eid, idp->eid,
		   idp->eid, idp->eid,
		   mark);
    } else {
      dd = zx_strf(cf->ctx, "%.*s"
		   "<input type=submit name=\"l0%s\" value=\" Login to %s \">%s<br>\n"
		   ss->len, ss->s, idp->eid, idp->eid, mark);
    }
#endif
    zx_str_free(cf->ctx, ss);
    ss = dd;
  }
#ifdef ZXID_USE_POPUP
  if (cf->show_tech) {
    dd = zx_strf(cf->ctx, "%.*s</select>"
		 "<input type=submit name=\"l0\" value=\" Login \">\n"
		 "<input type=submit name=\"l1\" value=\" Login (A2) \">\n"
		 "<input type=submit name=\"l2\" value=\" Login (P2) \">\n"
		 "<input type=submit name=\"l5\" value=\" Login (S2) \"><br>\n",
		 ss->len, ss->s);
  } else {
    dd = zx_strf(cf->ctx, "%.*s</select>"
		 "<input type=submit name=\"l0\" value=\" Login \"><br>\n",
		 ss->len, ss->s);
  }
  zx_str_free(cf->ctx, ss);
  ss = dd;
#endif

  s = ss->s;
  D("IdP list(%s)", s);
  if (res_len)
    *res_len = ss->len;
  ZX_FREE(cf->ctx, ss);
  return s;
}

/* Called by:  zxid_idp_list_len */
char* zxid_idp_list_cf(zxid_conf* cf, int* res_len, int auto_flags) {
  return zxid_idp_list_cf_cgi(cf, 0, res_len, auto_flags);
}

/* Called by:  zxid_idp_list */
char* zxid_idp_list_len(int conf_len, char* conf, int* res_len, int auto_flags) {
  zxid_conf cf;
  zxid_conf_to_cf_len(&cf, conf_len, conf);
  return zxid_idp_list_cf(&cf, 0, auto_flags);
}

/* Called by: */
char* zxid_idp_list(char* conf, int auto_flags) {
  return zxid_idp_list_len(-1, conf, 0, auto_flags);
}

#define FLDCHK(x,y) (x && x->y ? x->y : "")

/*(i) Render entire IdP selection screen. You may use this code, possibly adjusted
 * by some configuration options (see zxidconf.h), or you may choose to develop
 * your own IdP selection screen from scratch.
 *
 * N.B. More complete documentation is available in <<link: zxid-simple.pd>> (*** fixme) */

/* Called by:  zxid_idp_select_zxstr_cf, zxid_simple_show_idp_sel */
struct zx_str* zxid_idp_select_zxstr_cf_cgi(zxid_conf* cf, zxid_cgi* cgi, int auto_flags)
{
  struct zx_str* eid=0;
  struct zx_str* ss;
  char* idp_list;

  if (cf->idp_sel_our_eid && cf->idp_sel_our_eid[0])
    eid = zxid_my_entity_id(cf);
  D("HERE %p e(%s) m(%s) d(%s)", eid, FLDCHK(cgi, err), FLDCHK(cgi, msg), FLDCHK(cgi, dbg));
  idp_list = zxid_idp_list_cf_cgi(cf, cgi, 0, auto_flags);
  if (cf->log_level>1)
    zxlog(cf, 0,0,0,0,0,0,0, "N", "W", "IDPSEL", 0, 0);
  if ((auto_flags & ZXID_AUTO_FORMT) && (auto_flags & ZXID_AUTO_FORMF)) {
    DD("HERE %p", idp_list);
    ss = zx_strf(cf->ctx,
		 "%s"
#ifdef ZXID_USE_POST
		 "<form method=post action=\"%s?o=P\">\n"
#else
		 "<form method=get action=\"%s\">\n"
#endif
		 "<font color=red>%s</font><font color=green>%s</font><font color=white>%s</font>"
		 "%s"
		 "%s<a href=\"%.*s\">%.*s</a><br>"
		 "%s"    /* IdP List */
		 "%s%s"
		 "<input type=hidden name=fr value=\"%s\">\n"
		 "</form>%s%s%s",
		 cf->idp_sel_start,
		 cf->url,
		 FLDCHK(cgi, err), FLDCHK(cgi, msg), FLDCHK(cgi, dbg),
		 cf->idp_sel_new_idp,
		 cf->idp_sel_our_eid, eid?eid->len:0, eid?eid->s:"", eid?eid->len:0, eid?eid->s:"",
		 idp_list,
		 cf->idp_sel_tech_user, cf->idp_sel_tech_site,
		 FLDCHK(cgi, rs),
		 cf->idp_sel_footer, zxid_version_str(), cf->idp_sel_end);
    DD("HERE(%d) ss(%.*s)", ss->len, ss->len, ss->s);
  } else if (auto_flags & ZXID_AUTO_FORMT) {
    ss = zx_strf(cf->ctx,
#ifdef ZXID_USE_POST
		 "<form method=post action=\"%s?o=P\">\n"
#else
		 "<form method=get action=\"%s\">\n"
#endif
		 "<font color=red>%s</font><font color=green>%s</font><font color=white>%s</font>"
		 "%s"
		 "%s<a href=\"%.*s\">%.*s</a><br>"
		 "%s"    /* IdP List */
		 "%s%s"
		 "<input type=hidden name=fr value=\"%s\">\n"
		 "</form>",
		 cf->url,
		 FLDCHK(cgi, err), FLDCHK(cgi, msg), FLDCHK(cgi, dbg),
		 cf->idp_sel_new_idp,
		 cf->idp_sel_our_eid, eid?eid->len:0, eid?eid->s:"", eid?eid->len:0, eid?eid->s:"",
		 idp_list,
		 cf->idp_sel_tech_user, cf->idp_sel_tech_site,
		 FLDCHK(cgi, rs));
  } else if (auto_flags & ZXID_AUTO_FORMF) {
    ss = zx_strf(cf->ctx,
		 "<font color=red>%s</font><font color=green>%s</font><font color=white>%s</font>"
		 "%s"
		 "%s<a href=\"%.*s\">%.*s</a><br>"
		 "%s"    /* IdP List */
		 "%s%s"
		 "<input type=hidden name=fr value=\"%s\">\n",
		 FLDCHK(cgi, err), FLDCHK(cgi, msg), FLDCHK(cgi, dbg),
		 cf->idp_sel_new_idp,
		 cf->idp_sel_our_eid, eid?eid->len:0, eid?eid->s:"", eid?eid->len:0, eid?eid->s:"",
		 idp_list,
		 cf->idp_sel_tech_user, cf->idp_sel_tech_site,
		 FLDCHK(cgi, rs));
  } else
    ss = zx_dup_str(cf->ctx, "");
#if 0
  if (cgi.err) printf("<p><font color=red><i>%s</i></font></p>\n", cgi.err);
  if (cgi.msg) printf("<p><i>%s</i></p>\n", cgi.msg);
  printf("User:<input name=user> PW:<input name=pw type=password>");
  printf("<input name=login value=\" Login \" type=submit>");
  printf("<h3>Login Using IdP Discovered from Common Domain Cookie (CDC)</h3>\n");
  printf("RelayState: <input name=fr value=\"rs123\"><br>\n");
  if (cgi.dbg) printf("<p><form><textarea cols=100 row=10>%s</textarea></form>\n", cgi.dbg);
#endif
  return ss;
}

/* Called by:  zxid_idp_select_cf */
struct zx_str* zxid_idp_select_zxstr_cf(zxid_conf* cf, int auto_flags) {
  return zxid_idp_select_zxstr_cf_cgi(cf, 0, auto_flags);
}

/* Called by:  zxid_idp_select_len */
char* zxid_idp_select_cf(zxid_conf* cf, int* res_len, int auto_flags) {
  char* s;
  struct zx_str* ss = zxid_idp_select_zxstr_cf(cf, auto_flags);
  s = ss->s;
  if (res_len)
    *res_len = ss->len;
  ZX_FREE(cf->ctx, ss);
  return s;
}

/* Called by:  zxid_idp_select */
char* zxid_idp_select_len(int conf_len, char* conf, int* res_len, int auto_flags) {
  zxid_conf cf;
  zxid_conf_to_cf_len(&cf, conf_len, conf);
  return zxid_idp_select_cf(&cf, 0, auto_flags);
}

/* Called by: */
char* zxid_idp_select(char* conf, int auto_flags) {
  return zxid_idp_select_len(-1, conf, 0, auto_flags);
}

/* ------------ Attribute Broker and PEP ------------ */

/*() Local Policy Decision Point - decide on role and idpnid.
 * Return: 0 for Deny and 1 for Permit.  */

/* Called by:  zxid_simple_ab_pep */
static int zxid_localpdp(zxid_conf* cf, zxid_ses* ses)
{
  struct zxid_attr* at;

  if (cf->localpdp_role_permit || cf->localpdp_role_deny) {
    at = zxid_find_at(ses->at, "role");
    if (cf->localpdp_role_permit) {  /* whitelist of roles: not on list means deny */
      if (!at) {
	D("Deny due to no role attribute %d (whitelist)",0);
	return 0;
      }
      if (!zxid_find_cstr_list(cf->localpdp_role_permit, at->val)) {
	D("Deny: role(%s) not on whitelist", at->val);
	return 0;
      }
    }
    if (cf->localpdp_role_deny) {    /* blacklist of roles: on list means deny */
      if (at && zxid_find_cstr_list(cf->localpdp_role_deny, at->val)) {
	D("Deny: role(%s) on blacklist", at->val);
	return 0;
      }
    }
  }

  if (cf->localpdp_idpnid_permit || cf->localpdp_idpnid_deny) {
    at = zxid_find_at(ses->at, "idpnid");
    if (cf->localpdp_idpnid_permit) {  /* whitelist of idpnids: not on list means deny */
      if (!at) {
	D("Deny due to no idpnid attribute %d (whitelist)",0);
	return 0;
      }
      if (!zxid_find_cstr_list(cf->localpdp_idpnid_permit, at->val)) {
	D("Deny: idpnid(%s) not on whitelist", at->val);
	return 0;
      }
    }
    if (cf->localpdp_idpnid_deny) {    /* blacklist of idpnids: on list means deny */
      if (at && zxid_find_cstr_list(cf->localpdp_idpnid_deny, at->val)) {
	D("Deny: idpnid(%s) on blacklist", at->val);
	return 0;
      }
    }
  }

  D("Permit by local PDP %d", 1);
  return 1;
}

/*(i) Postprocessing of SSO: Attribute Broker handles attributes and PEP/PDP
 * decide on authorization. */

/* Called by:  chkuid, zxid_simple_cf_ses, zxid_simple_no_ses_cf x2, zxid_simple_ses_active_cf */
char* zxid_simple_ab_pep(zxid_conf* cf, zxid_ses* ses, int* res_len, int auto_flags)
{
  char* res;
  struct zx_str* ss;
  D_INDENT("ab_pep: ");
  DD("ab_pep %d", 0);
  zxid_ses_to_pool(cf, ses);  /* Process SSO a7n, applying NEED, WANT, and INMAP */

  if (!zxid_localpdp(cf, ses)) {
    D("Deny by local PDP %d",0);
    D_DEDENT("ab_pep: ");
    return "z";
  }

  if (cf->pdp_url && *cf->pdp_url) {
    //zxid_add_attr_to_pool(cf, ses, "Action", zx_dup_str(cf->ctx, "access"));
    //zxid_add_attr_to_pool(cf, ses, "URL", zx_dup_str(cf->ctx, ses->rs));
    if (!zxid_pep_az_soap(cf, 0, ses, cf->pdp_url)) {
      D("Deny %d", 0);
      D_DEDENT("ab_pep: ");
      return "z";
    }
  }
  
  switch (auto_flags & (ZXID_AUTO_FMTQ | ZXID_AUTO_FMTJ)) {
  case ZXID_AUTO_FMTQ|ZXID_AUTO_FMTJ: ss = zx_dup_str(cf->ctx, ""); break; /* No output */
  case ZXID_AUTO_FMTQ:  ss = zxid_ses_to_qs(cf, ses); break;
  case ZXID_AUTO_FMTJ:  ss = zxid_ses_to_json(cf, ses); break;
  default: ERR("Unsupported output format bits %x", auto_flags & (ZXID_AUTO_FMTQ|ZXID_AUTO_FMTJ));
  case 0:               ss = zxid_ses_to_ldif(cf, ses); break;
  }
  if (zx_debug & ZXID_INOUT) INFO("LDIF(%.*s)", ss?ss->len:1, ss?ss->s:"-");
  if (cf->log_level > 0)
    zxlog(cf, 0,0,0,0,0,0, ses->nameid?ses->nameid->gg.content:0, "N", "K", "SHOWPC", ses->sid, 0);
  res = ss->s;
  if (res_len)
    *res_len = ss->len;
  ZX_FREE(cf->ctx, ss);
  D_DEDENT("ab_pep: ");
  return res;
}

/* ------------ zxid_simple() ------------ */

/*() Deal with the various methods of shipping the page, including CGI stdout, or
 * as string with or without headers, as indicated by the auto_flag. The
 * page is in ss. */

/* Called by:  zxid_simple_idp_show_an, zxid_simple_show_carml, zxid_simple_show_conf, zxid_simple_show_idp_sel, zxid_simple_show_meta */
static char* zxid_simple_show_page(zxid_conf* cf, struct zx_str* ss, int c_mask, int h_mask, char* rets, char* cont_type, int* res_len, int auto_flags)
{
  char* res;
  struct zx_str* ss2;
  if (auto_flags & c_mask && auto_flags & h_mask) {  /* Both H&C: CGI */
    D("CGI %x", auto_flags);
    printf("Content-Type: %s" CRLF "Content-Length: %d" CRLF2 "%.*s",
	   cont_type, ss->len, ss->len, ss->s);
    if (auto_flags & ZXID_AUTO_EXIT)
      exit(0);
    zx_str_free(cf->ctx, ss);
    if (res_len)
      *res_len = 1;
    return zx_dup_cstr(cf->ctx, "n");
  }
  
  if (auto_flags & (c_mask | h_mask)) {
    if (auto_flags & h_mask) {  /* H only: return both H and C */
      D("With headers %x", auto_flags);
      ss2 = zx_strf(cf->ctx, "Content-Type: %s" CRLF "Content-Length: %d" CRLF2 "%.*s",
		    cont_type, ss->len, ss->len, ss->s);
      zx_str_free(cf->ctx, ss);
    } else {
      D("No headers %x", auto_flags);
      ss2 = ss;       /* C only */
    }
    res = ss2->s;
    DD("res(%s)", res);
    if (res_len)
      *res_len = ss2->len;
    ZX_FREE(cf->ctx, ss2);
    return res;
  }
  /* Do not output anything (both c and h 0). Effectively the generated page is thrown away. */
  D("e(%.*s) cm=%x hm=%x af=%x rets(%s)", ss?ss->len:-1, ss?ss->s:"", c_mask, h_mask, auto_flags, rets);
  if (ss)
    zx_str_free(cf->ctx, ss);
  if (res_len)
    *res_len = 1;
  return zx_dup_cstr(cf->ctx, rets);   /* Neither H nor C */
}

/*() Helper function to redirect according to auto flags. */

/* Called by:  zxid_simple_idp_an_ok_do_rest, zxid_simple_idp_new_user, zxid_simple_idp_recover_password, zxid_simple_idp_show_an, zxid_simple_show_idp_sel */
static char* zxid_simple_redir_page(zxid_conf* cf, char* redir, char* rs, int* res_len, int auto_flags)
{
  char* res;
  struct zx_str* ss;
  D("cf=%p redir(%s)", cf, redir);
  if (auto_flags & ZXID_AUTO_REDIR) {
    printf("Location: %s?%s" CRLF2, redir, STRNULLCHK(rs));
    if (auto_flags & ZXID_AUTO_EXIT)
      exit(0);
    if (res_len)
      *res_len = 1;
    return zx_dup_cstr(cf->ctx, "n");
  }
  ss = zx_strf(cf->ctx, "Location: %s?%s" CRLF2, redir, STRNULLCHK(rs));
  if (res_len)
    *res_len = ss->len;
  res = ss->s;
  ZX_FREE(cf->ctx, ss);
  return res;
}

/*() Show IdP selection or login screen.
 *
 * N.B. More complete documentation is available in <<link: zxid-simple.pd>> (*** fixme) */

/* Called by:  zxid_simple_no_ses_cf, zxid_simple_ses_active_cf x5 */
static char* zxid_simple_show_idp_sel(zxid_conf* cf, zxid_cgi* cgi, int* res_len, int auto_flags)
{
  struct zx_str* ss;
  D("cf=%p cgi=%p", cf, cgi);
  if (cf->idp_sel_page && cf->idp_sel_page[0]) {
    D("idp_sel_page(%s) rs(%s)", cf->idp_sel_page, STRNULLCHK(cgi->rs));
    return zxid_simple_redir_page(cf, cf->idp_sel_page, cgi->rs, res_len, auto_flags);
  }
  ss = auto_flags & (ZXID_AUTO_LOGINC | ZXID_AUTO_LOGINH)
    ? zxid_idp_select_zxstr_cf_cgi(cf, cgi, auto_flags)
    : 0;
  DD("idp_select: ret(%s)", ss?ss->len:1, ss?ss->s:"?");
  return zxid_simple_show_page(cf, ss, ZXID_AUTO_LOGINC, ZXID_AUTO_LOGINH,
			       "e", "text/html", res_len, auto_flags);
}


/*() Emit metadata. Corresponds to "o=B" query string.
 *
 * N.B. More complete documentation is available in <<link: zxid-simple.pd>> (*** fixme) */

/* Called by:  zxid_simple_no_ses_cf x2, zxid_simple_ses_active_cf x2 */
static char* zxid_simple_show_meta(zxid_conf* cf, zxid_cgi* cgi, int* res_len, int auto_flags)
{
  struct zx_str* meta = zxid_sp_meta(cf, cgi);
  return zxid_simple_show_page(cf, meta, ZXID_AUTO_METAC, ZXID_AUTO_METAH,
			       "b", "text/xml", res_len, auto_flags);
}

/*() Emit CARML declaration for SP. Corresponds to "o=c" query string. */

/* Called by:  zxid_simple_no_ses_cf, zxid_simple_ses_active_cf */
static char* zxid_simple_show_carml(zxid_conf* cf, zxid_cgi* cgi, int* res_len, int auto_flags)
{
  struct zx_str* carml = zxid_sp_carml(cf);
  return zxid_simple_show_page(cf, carml, ZXID_AUTO_METAC, ZXID_AUTO_METAH,
			       "c", "text/xml", res_len, auto_flags);
}

/*() Dump internal info and configuration. Corresponds to "o=d" query string. */

/* Called by:  zxid_simple_no_ses_cf, zxid_simple_ses_active_cf */
static char* zxid_simple_show_conf(zxid_conf* cf, zxid_cgi* cgi, int* res_len, int auto_flags)
{
  struct zx_str* ss = zxid_show_conf(cf);
  return zxid_simple_show_page(cf, ss, ZXID_AUTO_METAC, ZXID_AUTO_METAH,
			       "c", "text/html", res_len, auto_flags);
}

/* ----------- IdP Screens ----------- */

/*() Decode ssoreq (ar=), i.e. the preserved original AuthnReq */

/* Called by:  zxid_simple_idp_pw_authn, zxid_simple_idp_show_an */
static int zxid_decode_ssoreq(zxid_conf* cf, zxid_cgi* cgi)
{
  int len;
  char* buf;
  char* p;
  if (!cgi->ssoreq || !cgi->ssoreq[0])
    return 1;
  D("ssoreq(%s)", cgi->ssoreq);
  len = strlen(cgi->ssoreq);
  buf = ZX_ALLOC(cf->ctx, SIMPLE_BASE64_PESSIMISTIC_DECODE_LEN(len));
  p = unbase64_raw(cgi->ssoreq, cgi->ssoreq + len, buf, zx_std_index_64);
  p = zx_zlib_raw_inflate(0, p-buf, buf, &len);
  ZX_FREE(cf->ctx, buf);
  if (!p)
    return 0;
  p[len] = 0;
  cgi->op = 0;
  D("ar/ssoreq decoded(%s)", p);
  zxid_parse_cgi(cgi, p);  /* cgi->op will be Q due to SAMLRequest inside ssoreq */
  cgi->op = 'F';
  return 1;
}

/*() Process IdP side after successful authentication. If IdP was
 * invoked with AuthnReq (in SAMLRequest) then op=='F' as set
 * in zxid_simple_idp_pw_authn() which will trigger the rest of the
 * SSO protocol in zxid_simple_ses_active_cf(). Otherwise just
 * show the IdP management screen. */

/* Called by:  zxid_simple_idp_pw_authn, zxid_simple_idp_show_an */
static char* zxid_simple_idp_an_ok_do_rest(zxid_conf* cf, zxid_cgi* cgi, zxid_ses* ses, int* res_len, int auto_flags)
{
  struct zx_str* ss;
  char* p;
  DD("idp do_rest %p", ses);
  if (cf->atsel_page && cgi->atselafter) { /* *** More sophisticated criteria needed. */
    ss = zx_strf(cf->ctx, "ar=%s&s=%s&zxrfr=F%s%s%s%s&zxidpurl=%s",
		 cgi->ssoreq, cgi->sid,
		 cgi->zxapp && cgi->zxapp[0] ? "&zxapp=" : "", cgi->zxapp ? cgi->zxapp : "",
		 cgi->err && cgi->err[0] ? "&err=" : "", cgi->err ? cgi->err : "",
		 cf->url);
    p = ss->s;
    ZX_FREE(cf->ctx, ss);
    D("atsel_page(%s) redir(%s)", cf->atsel_page, p);
    return zxid_simple_redir_page(cf, cf->atsel_page, p, res_len, auto_flags);
  }
  return zxid_simple_ses_active_cf(cf, cgi, ses, res_len, auto_flags);
}

/*() Show Authentication screen. Generally this will be in response to
 * the SP having sent user via redirect to o=F carrying AuthnRequest encoded
 * in SAMLRequest query string parameter, per SAML redirect binding
 * [SAML2bind].  We must preserve SAMLRequest as hidden field, ar, in the
 * page for later processing once the authentication step has been
 * taken care of. It will also be passed on the query string to
 * external authentication page if any was configured with AN_PAGE
 * directive.
 *
 * N.B. More complete documentation is available in <<link: zxid-simple.pd>> (*** fixme) */

/* Called by:  zxid_simple_idp_new_user, zxid_simple_idp_pw_authn, zxid_simple_idp_recover_password, zxid_simple_no_ses_cf */
static char* zxid_simple_idp_show_an(zxid_conf* cf, zxid_cgi* cgi, int* res_len, int auto_flags)
{
  int zlen, len;
  char* zbuf;
  char* b64 = 0;
  char* p;
  char* ar;
  struct zx_sa_Issuer_s* issuer;
  zxid_entity* meta;
  struct zx_root_s* r;
  struct zx_str* ss;
  zxid_ses sess;
  memset(&sess, 0 , sizeof(sess));
  D("cf=%p cgi=%p", cf, cgi);
  
  DD("z saml_req(%s) rs(%s) sigalg(%s) sig(%s)", cgi->saml_req, cgi->rs, cgi->sigalg, cgi->sig);  
  if (cgi->uid && zxid_pw_authn(cf, cgi, &sess)) {  /* Try login, just in case. */
    return zxid_simple_idp_an_ok_do_rest(cf, cgi, &sess, res_len, auto_flags);
  }
  if (cgi->saml_req) {
    DD("zz saml_req(%s) rs(%s) sigalg(%s) sig(%s)", cgi->saml_req, cgi->rs, cgi->sigalg, cgi->sig);  
    ss = zx_strf(cf->ctx, "SAMLRequest=%s%s%s&SigAlg=%s&Signature=%s",
		 STRNULLCHK(cgi->saml_req),
		 cgi->rs && cgi->rs[0] ? "&RelayState=" : "", cgi->rs ? cgi->rs : "",
		 STRNULLCHK(cgi->sigalg),
		 STRNULLCHK(cgi->sig));
    D("z input(%.*s) len=%d", ss->len, ss->s, ss->len);
    zbuf = zx_zlib_raw_deflate(cf->ctx, ss->len, ss->s, &zlen);
    if (!zbuf)
      return 0;
    
    len = SIMPLE_BASE64_LEN(zlen);
    DD("zbuf(%.*s) zlen=%d len=%d", zlen, zbuf, zlen, len);
    b64 = ZX_ALLOC(cf->ctx, len+1);
    p = base64_fancy_raw(zbuf, zlen, b64, safe_basis_64, 1<<31, 0, 0, '=');
    *p = 0;
    zx_str_free(cf->ctx, ss);
    cgi->ssoreq = b64;
  }
  
  if (cf->an_page && cf->an_page[0]) {
    ss = zx_strf(cf->ctx, "ar=%s&zxrfr=F%s%s%s%s&zxidpurl=%s",
		 cgi->ssoreq,
		 cgi->zxapp && cgi->zxapp[0] ? "&zxapp=" : "", cgi->zxapp ? cgi->zxapp : "",
		 cgi->err && cgi->err[0] ? "&err=" : "", cgi->err ? cgi->err : "",
		 cf->url);
    if (b64)
      ZX_FREE(cf->ctx, b64);
    ar = ss->s;
    ZX_FREE(cf->ctx, ss);
    D("an_page(%s) ar(%s)", cf->an_page, ar);
    return zxid_simple_redir_page(cf, cf->an_page, ar, res_len, auto_flags);
  }
  
  if (cf->log_level>1)
    zxlog(cf, 0, 0, 0, 0, 0, 0, 0, "N", "W", "AUTHN", 0, "");
  
  /* Attempt to provisorily decode the request and fetch metadata of the SP so we
   * can detect trouble early on and provide some assuring knowledge to the user. */
  
  if (!cgi->saml_req && cgi->ssoreq) {
    zxid_decode_ssoreq(cf, cgi);
  }
  
  r = zxid_decode_redir_or_post(cf, cgi, &sess, 0x2);
  if (r) {
    issuer = zxid_extract_issuer(cf, cgi, &sess, r);
    if (issuer && issuer->gg.content && issuer->gg.content->len && issuer->gg.content->s[0]) {
      meta = zxid_get_ent_ss(cf, issuer->gg.content);
      if (meta) {
	cgi->sp_eid = meta->eid;
	cgi->sp_dpy_name = meta->dpy_name;
      } else {
	ERR("Unable to find metadata for Issuer(%.*s) in AnReq Redir", issuer->gg.content->len, issuer->gg.content->s);
	cgi->err = "Issuer unknown - metadata exchange may be needed (AnReq).";
	cgi->sp_dpy_name = "--SP description unavailable--";
	cgi->sp_eid = zx_str_to_c(cf->ctx, issuer->gg.content);
      }
    } else {
      cgi->err = "Issuer could not be determined from Authentication Request.";
      cgi->sp_eid = "";
      cgi->sp_dpy_name = "--No SP could be determined--";
    }
  } else {
      cgi->err = "Malformed or nonexistant Authentication Request";
      cgi->sp_eid = "";
      cgi->sp_dpy_name = "--No SP could be determined--";
  }
  
  ss = zxid_template_page_cf(cf, cgi, cf->an_templ_file, cf->an_templ);
  if (b64)
    ZX_FREE(cf->ctx, b64);
  DD("an_page: ret(%s)", ss?ss->len:1, ss?ss->s:"?");
  return zxid_simple_show_page(cf, ss, ZXID_AUTO_LOGINC, ZXID_AUTO_LOGINH,
			       "a", "text/html", res_len, auto_flags);
}

/*() Process password authentication form and, if ssoreq (ar=) is present
 * (see zxid_simple_idp_show_an() for how it is embedded to hidden
 * form field), proceed to federated SSO. If login fails, redisplay
 * the authentication page.
 *
 * N.B. More complete documentation is available in <<link: zxid-simple.pd>> (*** fixme) */

/* Called by:  zxid_simple_no_ses_cf */
static char* zxid_simple_idp_pw_authn(zxid_conf* cf, zxid_cgi* cgi, int* res_len, int auto_flags)
{
  zxid_ses sess;
  D("cf=%p cgi=%p", cf, cgi);
 
  if (!zxid_decode_ssoreq(cf, cgi))
    goto err;
  
  if (zxid_pw_authn(cf, cgi, &sess))
    return zxid_simple_idp_an_ok_do_rest(cf, cgi, &sess, res_len, auto_flags);

  D("PW Login failed uid(%s) pw(%s) err(%s)", STRNULLCHK(cgi->uid), STRNULLCHK(cgi->pw), STRNULLCHK(cgi->err));
 err:
  return zxid_simple_idp_show_an(cf, cgi, res_len, auto_flags);
}

/*() Redirect user to new user creation page. */

/* Called by:  zxid_simple_no_ses_cf */
static char* zxid_simple_idp_new_user(zxid_conf* cf, zxid_cgi* cgi, int* res_len, int auto_flags)
{
  char* p;
  struct zx_str* ss;
  D("cf=%p cgi=%p", cf, cgi);

  // ***

  if (cf->new_user_page && cf->new_user_page[0]) {
    ss = zx_strf(cf->ctx, "ar=%s&zxrfr=F%s%s%s%s&zxidpurl=%s",
		 cgi->ssoreq,
		 cgi->zxapp && cgi->zxapp[0] ? "&zxapp=" : "", cgi->zxapp ? cgi->zxapp : "",
		 cgi->err && cgi->err[0] ? "&err=" : "", cgi->err ? cgi->err : "",
		 cf->url);
    p = ss->s;
    ZX_FREE(cf->ctx, ss);
    D("new_user_page(%s) redir(%s)", cf->new_user_page, p);
    return zxid_simple_redir_page(cf, cf->new_user_page, p, res_len, auto_flags);
  }

  ERR("No new user page URL defined. (IdP config problem, or IdP intentionally does not support online new user creation. See NEW_USER_PAGE config option.) %d", 0);
  cgi->err = "No new user page URL defined. (IdP config problem, or IdP intentionally does not support online new user creation.)";
  
  return zxid_simple_idp_show_an(cf, cgi, res_len, auto_flags);
}

/*() Redirect user to recover password page. */

/* Called by:  zxid_simple_no_ses_cf */
static char* zxid_simple_idp_recover_password(zxid_conf* cf, zxid_cgi* cgi, int* res_len, int auto_flags)
{
  char* p;
  struct zx_str* ss;
  D("cf=%p cgi=%p", cf, cgi);

  // ***

  if (cf->recover_passwd && cf->recover_passwd[0]) {
    ss = zx_strf(cf->ctx, "ar=%s&zxrfr=F%s%s%s%s&zxidpurl=%s",
		 cgi->ssoreq,
		 cgi->zxapp && cgi->zxapp[0] ? "&zxapp=" : "", cgi->zxapp ? cgi->zxapp : "",
		 cgi->err && cgi->err[0] ? "&err=" : "", cgi->err ? cgi->err : "",
		 cf->url);
    p = ss->s;
    ZX_FREE(cf->ctx, ss);
    D("recover_passwd(%s) redir(%s)", cf->recover_passwd, p);
    return zxid_simple_redir_page(cf, cf->recover_passwd, p, res_len, auto_flags);
  }

  ERR("No password recover page URL defined. (IdP config problem, or IdP intentionally does not support online password recovery. See RECOVER_PASSWD config option.) %d", 0);
  cgi->err = "No password recover page URL defined. (IdP config problem, or IdP intentionally does not support online password recovery.)";
  
  return zxid_simple_idp_show_an(cf, cgi, res_len, auto_flags);
}

/* ===== Main Control Logic for Session Active and Session Inactive Cases ===== */

/*() Subroutine of zxid_simple_cf() for the session active case.
 *
 * NULL return means the "not logged in" processing is needed, see zxid_simple_no_ses_cf()
 *
 * N.B. More complete documentation is available in <<link: zxid-simple.pd>> (*** fixme) */

/* Called by:  chkuid x2, zxid_simple_cf_ses, zxid_simple_idp_an_ok_do_rest */
char* zxid_simple_ses_active_cf(zxid_conf* cf, zxid_cgi* cgi, zxid_ses* ses, int* res_len, int auto_flags)
{
  struct zx_str* accr;
  char* p;
  char* res = 0;
  struct zx_str* ss;
  
  if (!cf || !cgi || !ses) {
    ERR("FATAL: NULL pointer. You MUST supply configuration(%p), cgi(%p), and session(%p) objects (programming error)", cf, cgi, ses);
    NEVERNEVER("Bad args %p", cf);
  }
  
  /* OPs (the o= CGI field. Not to be confused with first letter of zxid_simple() return value)
   * l = local logout (form gl)
   * r = SLO redir    (form gr)
   * s = SLO soap     (form gs)
   * t = nireg redir  (form gt)
   * u = nireg soap   (form gu)
   * v = Az soap      (form gv)
   * c = CARML for the SP
   * d = Dump internal data, including config; debug screen
   * m = Show management screen
   * n = Just check session (used for checking session for protected content pages)
   * p = Password Login (IdP form submit alp= with au= and ap=)
   * P = POST response. HTTP POST in general
   * Q = POST request
   * R = POST request to IdP
   * S = SOAP (POST) request
   * B = Metadata
   *
   * M = CDC redirect and LECP detect
   * C = CDC reader
   * E = Normal "Entry" page (e.g. after CDC read)
   * L = Start SSO (submit of E)
   * A = Artifact processing
   * N = New User, during IdP Login (form an)
   * W = Recover password,  during IdP Login (form aw)
   *
   * I = used for IdP ???
   * K = used?
   * F = IdP: Return SSO A7N after successful An; no ses case, generate IdP ui
   *
   * Still available: DGHJORTUVWXYZabcdefghijkoqwxyz
   */
  
  if (cgi->enc_hint)
    cf->nameid_enc = cgi->enc_hint != '0';
  D("op(%c) session(%s) active", cgi->op, cgi->sid);
  DD("session(%s) active op(%c) saml_req(%s)", cgi->sid, cgi->op, STRNULLCHK(cgi->saml_req));
  switch (cgi->op) {
  case 'l':
    if (cf->log_level>0)
      zxlog(cf, 0,0,0,0,0,0, ses->nameid?ses->nameid->gg.content:0, "N", "W", "LOCLO", ses->sid,0);
    zxid_del_ses(cf, ses);
    cgi->msg = "Local logout Ok. Session terminated.";
    return zxid_simple_show_idp_sel(cf, cgi, res_len, auto_flags);
  case 'r':
    ss = zxid_sp_slo_redir(cf, cgi, ses);
    zxid_del_ses(cf, ses);
    goto redir_ok;
  case 's':
    zxid_sp_slo_soap(cf, cgi, ses);
    zxid_del_ses(cf, ses);
    cgi->msg = "SP Initiated logout (SOAP). Session terminated.";
    return zxid_simple_show_idp_sel(cf, cgi, res_len, auto_flags);
  case 't':
    ss = zxid_sp_mni_redir(cf, cgi, ses, zx_ref_str(cf->ctx, cgi->newnym));
    goto redir_ok;
  case 'u':
    zxid_sp_mni_soap(cf, cgi, ses, zx_ref_str(cf->ctx, cgi->newnym));
    cgi->msg = "SP Initiated defederation (SOAP).";
    break;     /* Defederation does not have to mean SLO */
  case 'v':
    zxid_pep_az_soap(cf, cgi, ses, cf->pdp_call_url?cf->pdp_call_url:cf->pdp_url);
    cgi->msg = "PEP-to-PDP Authorization call (SOAP).";
    break;     /* Defederation does not have to mean SLO */
  case 'm':
    res = zxid_fed_mgmt_cf(cf, res_len, -1, cgi->sid, auto_flags);
    if (auto_flags & ZXID_AUTO_EXIT)
      exit(0);
    return res;
  case 'P':    /* POST Profile Responses */
  case 'I':
  case 'K':
  case 'Q':    /* POST Profile Requests */
    D("saml_req(%s) rs(%s) sigalg(%s) sig(%s)", STRNULLCHK(cgi->saml_req), STRNULLCHK(cgi->rs), STRNULLCHK(cgi->sigalg), STRNULLCHK(cgi->sig));
    ss = zxid_sp_dispatch(cf, cgi, ses);
    switch (ss->s[0]) {
    case 'K': return zxid_simple_show_idp_sel(cf, cgi, res_len, auto_flags);
    case 'L': goto redir_ok;
    case 'I': goto idp;
    }
    D("Q ss(%.*s) (fall thru)", ss->len, ss->s);
    break;
  case 'R':
    cgi->op = 'F';
    /* Fall thru */
  case 'F': /*  IdP: Return SSO A7N after successful An; no ses case, generate IdP ui */
  idp:
    ss = zxid_idp_dispatch(cf, cgi, ses, 1);  /* N.B. The original request is in cgi->saml_req */
    switch (ss->s[0]) {
    case 'K': return zxid_simple_show_idp_sel(cf, cgi, res_len, auto_flags);
    case 'C': /* Content-type:  -- i.e. ship page or XML out */
    case 'L':
  redir_ok:
      if (auto_flags & ZXID_AUTO_REDIR) {
	printf("%.*s", ss->len, ss->s);
	zx_str_free(cf->ctx, ss);
	fflush(stdout);
	goto cgi_exit;
      } else
	goto res_zx_str;
    }
    D("idp err(%.*s) (fall thru)", ss->len, ss->s);
    /* *** */
    break;
  case 'c': return zxid_simple_show_carml(cf, cgi, res_len, auto_flags);
  case 'd': return zxid_simple_show_conf(cf, cgi, res_len, auto_flags);
  case 'B': return zxid_simple_show_meta(cf, cgi, res_len, auto_flags);
  case 'n': break;
  case 'p': break;
  default:
    if (cf->bare_url_entityid)
      return zxid_simple_show_meta(cf, cgi, res_len, auto_flags);
  }
  if (cf->required_authnctx) {
    zxid_get_ses_sso_a7n(cf, ses);
    accr = ses->a7n&&ses->a7n->AuthnStatement&&ses->a7n->AuthnStatement->AuthnContext&&ses->a7n->AuthnStatement->AuthnContext->AuthnContextClassRef&&ses->a7n->AuthnStatement->AuthnContext->AuthnContextClassRef->content&&ses->a7n->AuthnStatement->AuthnContext->AuthnContextClassRef->content?ses->a7n->AuthnStatement->AuthnContext->AuthnContextClassRef->content:0;

    if (accr)
      for (p = cf->required_authnctx[0]; p; ++p)
	if (!memcmp(accr->s, p, accr->len) && !p[accr->len])
	  goto ok;
    
    /* *** arrange same session to be used after step-up authentication. */
    
    D("Required AuthnCtx not satisfied by (%.*s). Step-up authentication needed.", accr&&accr->len?accr->len:1, accr&&accr->len?accr->s:"-");
    cgi->msg = "Step-up authentication requested.";
    return zxid_simple_show_idp_sel(cf, cgi, res_len, auto_flags);
  ok:
    D("Required AuthnCtx satisfied(%s)", p);
  }

  /* Successful Single Sign-On case starts here */
  return zxid_simple_ab_pep(cf, ses, res_len, auto_flags);
  
cgi_exit:
  if (auto_flags & ZXID_AUTO_EXIT)
    exit(0);
  res = zx_dup_cstr(cf->ctx, "n");
  if (res_len)
    *res_len = 1;
  return res;

res_zx_str:
  res = ss->s;
  if (res_len)
    *res_len = ss->len;
  ZX_FREE(cf->ctx, ss);
  return res;
}

/*() Subroutine of zxid_simple_cf() for the no session detected/active case.
 *
 * N.B. More complete documentation is available in <<link: zxid-simple.pd>> (*** fixme) */

/* Called by:  chkuid, zxid_simple_cf_ses */
char* zxid_simple_no_ses_cf(zxid_conf* cf, zxid_cgi* cgi, zxid_ses* ses, int* res_len, int auto_flags)
{
  char* res = 0;
  struct zx_str* ss;
  
  if (!cf || !cgi || !ses) {
    ERR("FATAL: NULL pointer. You MUST supply configuration(%p), cgi(%p), and session(%p) objects (programming error)", cf, cgi, ses);
    exit(1);
  }

  switch (cgi->op) {
  case 'M':  /* Invoke LECP or redirect to CDC reader. */
    ss = zxid_lecp_check(cf, cgi);
    D("LECP check: ss(%.*s)", ss?ss->len:1, ss?ss->s:"?");
    if (ss) {
      if (auto_flags & ZXID_AUTO_REDIR) {
	printf("%.*s", ss->len, ss->s);
	zx_str_free(cf->ctx, ss);
	goto cgi_exit;
      } else
	goto res_zx_str;
    } else {
      if (auto_flags & ZXID_AUTO_REDIR) {
	printf("Location: %s?o=C" CRLF2, cf->cdc_url);
	goto cgi_exit;
      } else {
	ss = zx_strf(cf->ctx, "Location: %s?o=C" CRLF2, cf->cdc_url);
	goto res_zx_str;
      }
    }
  case 'C':  /* CDC Read: Common Domain Cookie Reader */
    zxid_cdc_read(cf, cgi);
    goto cgi_exit;
  case 'E':  /* Return from CDC read, or start here to by-pass CDC read. */
    ss = zxid_lecp_check(cf, cgi);  /* use o=E&fc=1&fn=p  to set allow create true */
    D("LECP check: ss(%.*s)", ss?ss->len:1, ss?ss->s:"?");
    if (ss) {
      if (auto_flags & ZXID_AUTO_REDIR) {
	printf("%.*s", ss->len, ss->s);
	zx_str_free(cf->ctx, ss);
	goto cgi_exit;
      } else
	goto res_zx_str;
    }
    if (zxid_cdc_check(cf, cgi))
      return 0;
    D("NOT CDC %d", 0);
    break;
  case 'L':
    if (auto_flags & ZXID_AUTO_REDIR) {
      if (zxid_start_sso(cf, cgi))
	goto cgi_exit;
    } else {
      if ((ss = zxid_start_sso_location(cf, cgi)))
	goto res_zx_str;
    }
    break;
  case 'A':
    D("Process artifact(%s) pid=%d", cgi->saml_art, getpid());
    switch (zxid_sp_deref_art(cf, cgi, ses)) {
    case ZXID_REDIR_OK: ERR("*** Odd, redirect on artifact deref. %d", 0); break;
    case ZXID_SSO_OK:
show_protected_content_setcookie:
      D("show_protected_content_setcookie: (%s)", cf->ses_cookie_name);
      if (cf->ses_cookie_name && *cf->ses_cookie_name) {
	ses->setcookie = zx_alloc_sprintf(cf->ctx, 0, "%s=%s; path=/%s",
					  cf->ses_cookie_name, ses->sid,
					  ONE_OF_2(cf->url[4], 's', 'S')?"; secure":"");
	ses->cookie = zx_alloc_sprintf(cf->ctx, 0, "$Version=1; %s=%s",
				       cf->ses_cookie_name, ses->sid);
      }
      ses->rs = cgi->rs;
      return zxid_simple_ab_pep(cf, ses, res_len, auto_flags);
    }
    break;
  case 'P':    /* POST Profile Responses */
  case 'I':
  case 'K':
  case 'Q':    /* POST Profile Requests */
    DD("PRE saml_req(%s) saml_resp(%s) rs(%s) sigalg(%s) sig(%s)", STRNULLCHK(cgi->saml_req),  STRNULLCHK(cgi->saml_resp), cgi->rs, cgi->sigalg, cgi->sig);
    ss = zxid_sp_dispatch(cf, cgi, ses);
    D("POST dispatch_loc(%s)", ss->s);
    switch (ss->s[0]) {
    case 'O': goto show_protected_content_setcookie;
    case 'M': return zxid_simple_ab_pep(cf, ses, res_len, auto_flags);
    case 'L':  /* Location */
      if (auto_flags & ZXID_AUTO_REDIR) {
	printf("%.*s", ss->len, ss->s);
	zx_str_free(cf->ctx, ss);
	fflush(stdout);
	goto cgi_exit;
      } else
	goto res_zx_str;
    case 'I': goto idp;
    }
    D("Q err (fall thru) %d", 0);
    break;
  case 'c':    return zxid_simple_show_carml(cf, cgi, res_len, auto_flags);
  case 'd':    return zxid_simple_show_conf(cf, cgi, res_len, auto_flags);
  case 'B':    return zxid_simple_show_meta(cf, cgi, res_len, auto_flags);
  case 'R':
    cgi->op = 'F';
    /* Fall thru */
  case 'F':
idp:           return zxid_simple_idp_show_an(cf, cgi, res_len, auto_flags);
  case 'p':    return zxid_simple_idp_pw_authn(cf, cgi, res_len, auto_flags);
  case 'N':    return zxid_simple_idp_new_user(cf, cgi, res_len, auto_flags);
  case 'W':    return zxid_simple_idp_recover_password(cf, cgi, res_len, auto_flags);
  default:
    if (cf->bare_url_entityid)
      return zxid_simple_show_meta(cf, cgi, res_len, auto_flags);
    D("unknown op(%c)", cgi->op);
  }
  return zxid_simple_show_idp_sel(cf, cgi, res_len, auto_flags);

cgi_exit:
  if (auto_flags & ZXID_AUTO_EXIT)
    exit(0);
  res = zx_dup_cstr(cf->ctx, "n");
  if (res_len)
    *res_len = 1;
  return res;

res_zx_str:
  res = ss->s;
  if (res_len)
    *res_len = ss->len;
  ZX_FREE(cf->ctx, ss);
  return res;
}

/*(i) Simple handler that assumes the configuration has already been read in.
 * The memory for result is grabbed from ZX_ALLOC(), usually malloc(3)
 * and is "given" away to the caller, i.e. caller must free it. The
 * return value is LDIF (or JSON or query string, if configured)
 * of attributes in success case.
 * res_len, if non-null, will receive the length of the response.
 *
 * The major advantage of zxid_simple_cf_ses() is that the session stays
 * as binary object and does not need to be recreated / reparsed from
 * filesystem representation. The object can be directly used for PEP
 * calls (but see inline PEP call enabled by PDPURL) and WSC.
 *
 * cf:: Configuration object
 * qs_len:: Length of the query string. -1 = use strlen()
 * qs:: Query string (or POST content)
 * ses:: Session object
 * res_len:: Result parameter. If non-null, will be set to the length of the returned string
 * auto_flags:: Automation flags, see zxid-simple.pd for documentation
 * return:: String representing protocol action or SSO attributes
 *
 * N.B. More complete documentation is available in <<link: zxid-simple.pd>> (*** fixme) */

/* Called by:  zxid_simple_cf */
char* zxid_simple_cf_ses(zxid_conf* cf, int qs_len, char* qs, zxid_ses* ses, int* res_len, int auto_flags)
{
  int got, ret;
  char* remote_addr;
  char* cont_len;
  char* buf = 0;
  char* res = 0;
  zxid_cgi cgi;
  memset(&cgi, 0, sizeof(cgi));
  
  if (!cf || !ses) {
    ERR("NULL pointer. You MUST supply configuration object %p and session object %p (programming error). auto_flags=%x", cf, ses, auto_flags);
    exit(1);
  }
  
  /*fprintf(stderr, "qs(%s) arg, autoflags=%x\n", qs, auto_flags);*/
  if (auto_flags & ZXID_AUTO_DEBUG) zxid_set_opt(cf, 1, 1);
  LOCK(cf->mx, "simple ipport");
  if (!cf->ipport) {
    remote_addr = getenv("REMOTE_ADDR");
    if (remote_addr) {
      cf->ipport = ZX_ALLOC(cf->ctx, strlen(remote_addr) + 6 + 1); /* :12345 */
      sprintf(cf->ipport, "%s:-", remote_addr);
    }
  }
  UNLOCK(cf->mx, "simple ipport");
  
  if (!qs) {
    qs = getenv("QUERY_STRING");
    D("QUERY_STRING(%s) %s", STRNULLCHK(qs), ZXID_REL);
    if (qs) {
      zxid_parse_cgi(&cgi, qs);
      if (ONE_OF_3(cgi.op, 'P', 'R', 'S')) {
	cont_len = getenv("CONTENT_LENGTH");
	if (cont_len) {
	  sscanf(cont_len, "%d", &got);
	  buf = ZX_ALLOC(cf->ctx, got);
	  if (!buf) {
	    ERR("out of memory len=%d", got);
	    exit(1);
	  }
	  if (read_all_fd(0, buf, got, &got) == -1) {
	    perror("Trouble reading post content.");
	  } else {
	    buf[got] = 0;
	    D("POST(%s) got=%d cont_len(%s)", buf, got, cont_len);
	    if (buf[0] == '<') goto sp_soap;  /* No BOM and looks like XML */
	    if (buf[2] == '<') {              /* UTF-16 BOM and looks like XML */
	      got-=2; buf+=2;
	      ERR("UTF-16 NOT SUPPORTED %x%x", buf[0], buf[1]);
	      goto sp_soap;
	    }
	    if (buf[3] == '<') {              /* UTF-8 BOM and looks XML */
	      got-=3; buf+=3;
	    sp_soap:
	      /* *** TODO: SOAP response should not be sent internally unless there is auto */
	      ret = zxid_sp_soap_parse(cf, &cgi, ses, got, buf);
	      D("POST soap parse returned %d (0=fail, 1=ok, 2=redir, 3=sso ok)", ret);
	      if (ret == ZXID_SSO_OK)
		return zxid_simple_ab_pep(cf, ses, res_len, auto_flags);
	      if (auto_flags & ZXID_AUTO_SOAPC || auto_flags & ZXID_AUTO_SOAPH) {
		if (auto_flags & ZXID_AUTO_EXIT)
		  exit(0);
		res = zx_dup_cstr(cf->ctx, "n");
		if (res_len)
		  *res_len = 1;
		goto done;
	      }
	      res = zx_dup_cstr(cf->ctx, ret ? "n" : "*** SOAP error (enable debug if you want to see why)"); 
	      if (res_len)
		*res_len = strlen(res);
	      goto done;
	    }
	    zxid_parse_cgi(&cgi, buf);
	  }
	}
      }
    }
  } else {
    if (qs_len == -1)
      qs_len = strlen(qs);
    if (qs[qs_len]) {   /* *** reads one past end of buffer */
      ERR("IMPLEMENTATION LIMIT: Query String MUST be nul terminated len=%d", qs_len);
      exit(1);
    }
    D("QUERY_STRING(%s) %s", STRNULLCHK(qs), ZXID_REL);
    zxid_parse_cgi(&cgi, qs);
  }
  if (!cgi.op && !cf->bare_url_entityid)
    cgi.op = 'M';  /* By default, if no ses, check CDC and offer SSO */

  if (!cgi.sid && cf->ses_cookie_name && *cf->ses_cookie_name)
    zxid_get_sid_from_cookie(cf, &cgi, getenv("HTTP_COOKIE"));

  if (cgi.sid) {
      if (!zxid_get_ses(cf, ses, cgi.sid)) {
	D("No session(%s) active op(%c)", cgi.sid, cgi.op);
      } else
	if (res = zxid_simple_ses_active_cf(cf, &cgi, ses, res_len, auto_flags))
	  goto done;
  }

  memset(ses, 0, sizeof(ses));   /* No session yet! Process login form */
  res = zxid_simple_no_ses_cf(cf, &cgi, ses, res_len, auto_flags);

done:
  if (buf)
    ZX_FREE(cf->ctx, buf);
  return res;
}

/*() Allocate simple session and then call simple handler. Strings
 * are length + pointer (no C string nul termination needed).
 * A wrapper for zxid_simple_cf().
 *
 * cf:: Configuration object
 * qs_len:: Length of the query string. -1 = use strlen()
 * qs:: Query string (or POST content)
 * res_len:: Result parameter. If non-null, will be set to the length of the returned string
 * auto_flags:: Automation flags, see zxid-simple.pd for documentation
 * return:: String representing protocol action or SSO attributes
 *
 * N.B. More complete documentation is available in <<link: zxid-simple.pd>> (*** fixme) */

/* Called by:  main x3, zxid_simple_len, zxidwspcgi_main */
char* zxid_simple_cf(zxid_conf* cf, int qs_len, char* qs, int* res_len, int auto_flags)
{
  zxid_ses ses;
  memset(&ses, 0, sizeof(ses));
  return zxid_simple_cf_ses(cf, qs_len, qs, &ses, res_len, auto_flags);
}

/*() Process simple configuration and then call simple handler. Strings
 * are length + pointer (no C string nul termination needed).
 * a wrapper for zxid_simple_cf().
 *
 * N.B. More complete documentation is available in <<link: zxid-simple.pd>> (*** fixme) */

/* Called by:  zxid_simple */
char* zxid_simple_len(int conf_len, char* conf, int qs_len, char* qs, int* res_len, int auto_flags)
{
  struct zx_ctx ctx;
  zxid_conf cf;
  zx_reset_ctx(&ctx);
  memset(&cf, 0, sizeof(zxid_conf));
  cf.ctx = &ctx;
  zxid_conf_to_cf_len(&cf, conf_len, conf);
  return zxid_simple_cf(&cf, qs_len, qs, res_len, auto_flags);
}

/*() Main simple interface. C string nul termination is assumed. Really just
 * a wrapper for zxid_simple_cf().
 *
 * N.B. More complete documentation is available in <<link: zxid-simple.pd>> (*** fixme) */

/* Called by:  main x4 */
char* zxid_simple(char* conf, char* qs, int auto_flags)
{
  return zxid_simple_len(-1, conf, -1, qs, 0, auto_flags);
}

/* EOF  --  zxidsimp.c */
