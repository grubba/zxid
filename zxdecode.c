/* zxdecode.c  -  SAML Decoding tool
 * Copyright (c) 2008-2010 Sampo Kellomaki (sampo@iki.fi), All Rights Reserved.
 * This is confidential unpublished proprietary source code of the author.
 * NO WARRANTY, not even implied warranties. Contains trade secrets.
 * Distribution prohibited unless authorized in writing.
 * Licensed under Apache License 2.0, see file COPYING.
 * $Id: zxdecode.c,v 1.8 2009-11-29 12:23:06 sampo Exp $
 *
 * 25.11.2008, created --Sampo
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

CU8* help =
"zxdecode  -  Decode SAML Redirect and POST Messages R" ZXID_REL "\n\
Copyright (c) 2008-2009 Sampo Kellomaki (sampo@iki.fi), All Rights Reserved.\n\
NO WARRANTY, not even implied warranties. Licensed under Apache License v2.0\n\
See http://www.apache.org/licenses/LICENSE-2.0\n\
Send well researched bug reports to the author. Home: zxid.org\n\
\n\
Usage: zxdecode [options] <message >decoded\n\
  -z -Z            Prevent or force inflate step (default auto detects)\n\
  -v               Verbose messages.\n\
  -q               Be extra quiet.\n\
  -d               Turn on debugging.\n\
  -h               This help message\n\
  --               End of options\n";

int inflate_flag = 2;  /* Auto */
int verbose = 1;
char buf[32*1024];

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

    case 'd':
      switch ((*argv)[0][2]) {
      case '\0':
	++zx_debug;
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

/* Called by:  main x4 */
static void decode(char* msg, char* q)
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
    fclose(stdout);
  }
}

/* Called by: */
int main(int argc, char** argv, char** env)
{
  int got;
  char* p;
  char* q;

  strcpy(zx_instance, "\tzxdec");
  opt(&argc, &argv, &env);

  read_all_fd(0, buf, sizeof(buf)-1, &got);
  buf[got] = 0;

  p = strstr(buf, "SAMLRequest=");
  if (p) {
    q = strchr(p, '&');
    if (!q) q = buf+got;
    decode(p + sizeof("SAMLRequest=")-1, q);
    return 0;
  }
  p = strstr(buf, "SAMLResponse=");
  if (p) {
    q = strchr(p, '&');
    if (!q) q = buf+got;
    decode(p + sizeof("SAMLResponse=")-1, q);
    return 0;
  }
  if (*buf == '<') {  /* HTML for POST */
    p = strstr(buf, "SAMLRequest");
    if (p) {
      p += sizeof("SAMLRequest")-1;
    } else {
      p = strstr(buf, "SAMLResponse");
      if (p)
	p += sizeof("SAMLResponse")-1;
    }
    if (p) {
      p = strstr(p, "value=");
      if (p) {
	p += sizeof("value=")-1;
	if (*p == '"') {
	  ++p;
	  q = strchr(p, '"');
	} else {
	  q = p+strcspn(p, "\" >");
	}
	if (!q) q = buf+got;
	decode(p, q);
	return 0;
      }
    }

  }
  decode(buf, buf + got);
  return 0;
}

/* EOF  --  zxdecode.c */
