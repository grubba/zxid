/* zxdecode.c  -  SAML Decoding tool
 * Copyright (c) 2008-2010 Sampo Kellomaki (sampo@iki.fi), All Rights Reserved.
 * This is confidential unpublished proprietary source code of the author.
 * NO WARRANTY, not even implied warranties. Contains trade secrets.
 * Distribution prohibited unless authorized in writing.
 * Licensed under Apache License 2.0, see file COPYING.
 * $Id: zxdecode.c,v 1.8 2009-11-29 12:23:06 sampo Exp $
 *
 * 25.11.2008, created --Sampo
 * 4.10.2010, added -s and ss modes, as well as -i N selector --Sampo
 */

#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <signal.h>
#include <fcntl.h>

#include "errmac.h"
#include "zx.h"
#include "zxid.h"
#include "zxidconf.h"
#include "c/zxidvers.h"
#include "c/zx-ns.h"
#include "c/zx-const.h"
#include "c/zx-data.h"

char* help =
"zxdecode  -  Decode SAML Redirect and POST Messages R" ZXID_REL "\n\
Copyright (c) 2008-2010 Sampo Kellomaki (sampo@iki.fi), All Rights Reserved.\n\
NO WARRANTY, not even implied warranties. Licensed under Apache License v2.0\n\
See http://www.apache.org/licenses/LICENSE-2.0\n\
Send well researched bug reports to the author. Home: zxid.org\n\
\n\
Usage: zxdecode [options] <message >decoded\n\
  -z -Z            Prevent or force inflate step (default auto detects)\n\
  -i N             Pick Nth detected decodable structure, default: 1=first\n\
  -s               Enable signature validation step (reads config from -c, see below)\n\
  -c CONF          For -s, optional configuration string (default -c PATH=/var/zxid/)\n\
                   Most of the configuration is read from /var/zxid/zxid.conf\n\
  -sha1            Compute sha1 over input and print as base64. For debugging canon.\n\
  -v               Verbose messages.\n\
  -q               Be extra quiet.\n\
  -d               Turn on debugging.\n\
  -h               This help message\n\
  --               End of options\n\
\n\
Will attempt to detect many layers of encoding. Will hunt for the\n\
relevant input such as SAMLRequest or SAMLResponse in, e.g., log file.\n";

int inflate_flag = 2;  /* Auto */
int verbose = 1;
int ix = 1;
int sig_flag = 0;  /* No sig checking by default. */
int sha1_flag;
zxid_conf* cf = 0;
char buf[256*1024];

/* Called by:  main x8, zxcall_main, zxcot_main */
static void opt(int* argc, char*** argv, char*** env)
{
  if (*argc <= 1) return;
  
  while (1) {
    ++(*argv); --(*argc);
    
    if (!(*argc) || ((*argv)[0][0] != '-')) break;  /* normal exit from options loop */
    
    switch ((*argv)[0][1]) {
    case '-': if ((*argv)[0][2]) break;
      ++(*argv); --(*argc);
      DD("End of options by --");
      return;  /* -- ends the options */

    case 'c':
      switch ((*argv)[0][2]) {
      case '\0':
	++(*argv); --(*argc);
	if ((*argc) < 1) break;
	if (!cf)
	  cf = zxid_new_conf_to_cf(0);
	zxid_parse_conf(cf, (*argv)[0]);
	continue;
      }
      break;

    case 'd':
      switch ((*argv)[0][2]) {
      case '\0':
	++zx_debug;
	continue;
      }
      break;

    case 'i':
      switch ((*argv)[0][2]) {
      case '\0':
	++(*argv); --(*argc);
	if ((*argc) < 1) break;
	sscanf((*argv)[0], "%i", &ix);
	continue;
      }
      break;

    case 's':
      switch ((*argv)[0][2]) {
      case '\0':
	++sig_flag;
	if (!cf)
	  cf = zxid_new_conf_to_cf(0);
	continue;
      case 'h':
	++sha1_flag;
	continue;
      }
      break;

    case 'z':
      switch ((*argv)[0][2]) {
      case '\0':
	inflate_flag = 0;
	continue;
      }
      break;
    case 'Z':
      switch ((*argv)[0][2]) {
      case '\0':
	inflate_flag = 1;
	continue;
      }
      break;

#if 0
    case 'l':
      switch ((*argv)[0][2]) {
      case 'i':
	if (!strcmp((*argv)[0],"-license")) {
	  extern char* license;
	  fprintf(stderr, license);
	  exit(0);
	}
	break;
      }
      break;
#endif

    case 'q':
      switch ((*argv)[0][2]) {
      case '\0':
	verbose = 0;
	continue;
      }
      break;

    case 'v':
      switch ((*argv)[0][2]) {
      case '\0':
	++verbose;
	continue;
      }
      break;

    } 
    /* fall thru means unrecognized flag */
    if (*argc)
      fprintf(stderr, "Unrecognized flag `%s'\n", (*argv)[0]);
    fprintf(stderr, help);
    /*fprintf(stderr, "version=0x%06x rel(%s)\n", zxid_version(), zxid_version_str());*/
    exit(3);
  }
}

static int sig_validate(int len, char* p)
{
  int ret;
  zxid_cgi cgi;
  zxid_ses ses;
  struct zx_root_s* r;
  struct zx_sp_Response_s* resp;
  struct zx_ns_s* pop_seen;
  zxid_a7n* a7n;
  
  memset(&cgi, sizeof(cgi), 0);
  memset(&ses, sizeof(ses), 0);

  LOCK(cf->ctx->mx, "decode");
  zx_prepare_dec_ctx(cf->ctx, zx_ns_tab, p, p + len);
  r = zx_DEC_root(cf->ctx, 0, 1);
  UNLOCK(cf->ctx->mx, "decode");
  if (!r) {
    ERR("Failed to parse buf(%.*s)", len, p);
    return 2;
  }
  resp = r->Response;
  if (!r) {
    ERR("No <sp:Response> found buf(%.*s)", len, p);
    return 3;
  }

  /* See zxid_sp_dig_sso_a7n() for similar code. */
  
  if (!zxid_chk_sig(cf, &cgi, &ses, &resp->gg, resp->Signature, resp->Issuer, 0, "Response"))
    return 4;
  
  a7n = zxid_dec_a7n(cf, resp->Assertion, resp->EncryptedAssertion);
  if (!a7n) {
    ERR("No Assertion found and not anon_ok in SAML Response %d", 0);
    return 5;
  }

  zx_see_elem_ns(cf->ctx, &pop_seen, &resp->gg);
  ret = zxid_sp_sso_finalize(cf, &cgi, &ses, a7n, pop_seen);
  INFO("zxid_sp_sso_finalize() returned %d", ret);
  return ret?0:6;
}

/* Called by:  main x4 */
static int decode(char* msg, char* q)
{
  int msglen, len;
  char* p;
  char* m2;
  char* p2;
  
  *q = 0;
  D("Original Msg(%s) x=%x", msg, *msg);
  
  if (strchr(msg, '%')) {
    p = p2 = msg;
    URL_DECODE(p, p2, q);
    q = p;
    *q = 0;
    D("URL Decoded Msg(%s) x=%x", msg, *msg);
  }
  
  msglen = q - msg;
  p = unbase64_raw(msg, q, msg, zx_std_index_64);  /* inplace */
  *p = 0;
  D("Unbase64 Msg(%s) x=%x (n.b. message data may be binary at this point)", msg, *msg);

  switch (inflate_flag) {
  case 0:
    printf("%.*s", p-msg, msg);
    break;
  case 1:
    D("Decompressing... %d",0);
    p = zx_zlib_raw_inflate(0, p-msg, msg, &len);  /* Redir uses compressed payload. */
    printf("%.*s", len, p);
    break;
  case 2:
    /* Skip whitespace in the beginning and end of the payload to help correct POST detection. */
    for (m2 = msg; m2 < p; ++m2)
      if (!ONE_OF_4(*m2, ' ', '\t', '\015', '\012'))
	break;
    for (p2 = p-1; m2 < p2; --p2)
      if (!ONE_OF_4(*p2, ' ', '\t', '\015', '\012'))
	break;
    D("Msg_sans_ws(%.*s) start=%x end=%x", p2-m2+1, m2, *m2, *p2);
    
    if (*m2 == '<' && *p2 == '>') {  /* POST profiles do not compress the payload */
      len = p2 - m2 + 1;
      p = m2;
    } else {
      D("Decompressing... %d",0);
      p = zx_zlib_raw_inflate(0, p-msg, msg, &len);  /* Redir uses compressed payload. */
    }
    printf("%.*s", len, p);

    if (sig_flag)
      return sig_validate(len, p);
  }
  return 0;
}

#ifndef zxdecode_main
#define zxdecode_main main
#endif

/* Called by: */
int zxdecode_main(int argc, char** argv, char** env)
{
  int got;
  char* pp;
  char* p;
  char* q;
  char* lim;

  strcpy(zx_instance, "\tzxdec");
  opt(&argc, &argv, &env);

  read_all_fd(0, buf, sizeof(buf)-1, &got);
  buf[got] = 0;
  lim = buf+got;

  if (sha1_flag) {
    p = sha1_safe_base64(buf, got, buf);
    *p = 0;
    printf("%s\n", buf);
    return 0;
  }

  /* Try to detect relevant input, iterating if -i N was specified.
   * The detection is supposed to pick SAMLREquest or SAMLResponse from
   * middle of HTML form, or from log output. Whatever is convenient. */

  for (pp = buf; pp && pp < lim; pp = p+1) {
    p = strstr(pp, "SAMLRequest=");
    if (p) {
      if (--ix)	continue;
      q = strchr(p, '&');
      return decode(p + sizeof("SAMLRequest=")-1, q?q:lim);
    }
    p = strstr(pp, "SAMLResponse=");
    if (p) {
      if (--ix)	continue;
      q = strchr(p, '&');
      return decode(p + sizeof("SAMLResponse=")-1, q?q:lim);
    }
    if (*pp == '<') {  /* HTML for POST */
      p = strstr(pp, "SAMLRequest");
      if (p) {
	p += sizeof("SAMLRequest")-1;
      } else {
	p = strstr(pp, "SAMLResponse");
	if (p)
	  p += sizeof("SAMLResponse")-1;
      }
      if (p) {
	p = strstr(p, "value=");
	if (p) {
	  if (--ix)	continue;
	  p += sizeof("value=")-1;
	  if (*p == '"') {
	    ++p;
	    q = strchr(p, '"');
	  } else {
	    q = p+strcspn(p, "\" >");
	  }
	  return decode(p, q?q:lim);
	}
      }
    }
    if (--ix)	continue;
    return decode(pp, lim);
  }
  ERR("Found no SAMLRequest or SAMLResponse to decode %d",2);
  return 1;
}

/* EOF  --  zxdecode.c */
