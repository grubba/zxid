/* zxbustailf.c  -  tailf like utility for sending tail of a log to zxbus
 * Copyright (c) 2012 Sampo Kellomaki (sampo@iki.fi), All Rights Reserved.
 * This is confidential unpublished proprietary source code of the author.
 * NO WARRANTY, not even implied warranties. Contains trade secrets.
 * Distribution prohibited unless authorized in writing.
 * Licensed under Apache License 2.0, see file COPYING.
 * $Id: zxcot.c,v 1.5 2009-11-29 12:23:06 sampo Exp $
 *
 * 27.8.2009, created --Sampo
 */

#include "platform.h"  /* for dirent.h */

#include <string.h>
#include <stdio.h>
#include <fcntl.h>
#include <errno.h>

#include "platform.h"
#include "errmac.h"
#include "zx.h"
#include "zxid.h"
#include "zxidutil.h"
#include "zxidconf.h"
#include "c/zxidvers.h"
#include "c/zx-const.h"
#include "c/zx-ns.h"
#include "c/zx-data.h"

char* help =
"zxbustailf  -  tail a log file and send events to zxbus R" ZXID_REL "\n\
zxbus is an Audit Bus for TAS3 or end2end Trus Assurance (e2eTA).\n\
Copyright (c) 2012 Sampo Kellomaki (sampo@iki.fi), All Rights Reserved.\n\
NO WARRANTY, not even implied warranties. Licensed under Apache License v2.0\n\
See http://www.apache.org/licenses/LICENSE-2.0\n\
Send well researched bug reports to the author. Home: zxid.org\n\
\n\
Usage: zxbustailf [options] < stream-to-log   # Will stop at EOF\n\
       zxbustailf [options] /file/to/tailf\n\
       zxbustailf [options] -e MSG </dev/null\n\
  -c CONF          Optional configuration string (default -c PATH=/var/zxid/)\n\
                   Most of the configuration is read from /var/zxid/zxid.conf\n\
  -ch CHAN         Indicate logging channel. Default is to use configuration.\n\
  -n N or -N       Output the last N lines of file - the default is to log all.\n\
  -e MSG           Log message from command line\n\
  -i N             Number of iterations of connect-send-disconnect cycle. For benchmarking.\n\
  -is N            Number of sends per connection, for benchmarking.\n\
  -v               Verbose messages.\n\
  -q               Be extra quiet.\n\
  -d               Turn on debugging.\n\
  -dc              Dump config.\n\
  -h               This help message\n\
  --               End of options\n\
\n\
echo '<query>Foo</query>' | zxbustailf -a https://idp.tas3.eu/zxididp?o=B user:pw -t urn:x-demo-svc\n\
\n";

int dryrun  = 0;
int verbose = 1;
int n_iter = 1;
int n_send = 2;
char* bdy = 0;
char* chan = 0;
zxid_conf* cf;

/* Called by:  main x9, zxbustailf_main, zxcall_main, zxcot_main, zxdecode_main */
static void opt(int* argc, char*** argv, char*** env)
{
  struct zx_str* ss;
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
	zxid_parse_conf(cf, (*argv)[0]);
	continue;
      case 'h':
	++(*argv); --(*argc);
	if ((*argc) < 1) break;
	chan = (*argv)[0];
	continue;
      }
      break;

    case 'd':
      switch ((*argv)[0][2]) {
      case '\0':
	++zx_debug;
	if (zx_debug == 2)
	  strncpy(zx_instance, "\t\e[43mzxbustailf\e[0m", sizeof(zx_instance));
	continue;
      case 'c':
	ss = zxid_show_conf(cf);
	if (verbose>1) {
	  printf("\n======== CONF ========\n%.*s\n^^^^^^^^ CONF ^^^^^^^^\n",ss->len,ss->s);
	  exit(0);
	}
	fprintf(stderr, "\n======== CONF ========\n%.*s\n^^^^^^^^ CONF ^^^^^^^^\n",ss->len,ss->s);
	continue;
      }
      break;

    case 'e':
      switch ((*argv)[0][2]) {
      case '\0':
	++(*argv); --(*argc);
	if ((*argc) < 1) break;
	bdy = (*argv)[0];
	continue;
      }
      break;


    case 'i':
      switch ((*argv)[0][2]) {
      case '\0':
	++(*argv); --(*argc);
	if (!(*argc)) break;
	n_iter = atoi((*argv)[0]);
	continue;
      case 's':
	if ((*argv)[0][3]) break;
	++(*argv); --(*argc);
	if (!(*argc)) break;
	n_send = atoi((*argv)[0]);
	continue;
      }
      break;


    case 'n':
      switch ((*argv)[0][2]) {
      case '\0':
	++dryrun;
	continue;
      }
      break;

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
help:
    if (verbose>1) {
      printf("%s", help);
      exit(0);
    }
    fprintf(stderr, "%s", help);
    /*fprintf(stderr, "version=0x%06x rel(%s)\n", zxid_version(), zxid_version_str());*/
    exit(3);
  }
}


#ifndef zxbustailf_main
#define zxbustailf_main main
#endif

/*() Web Services Client tool */

/* Called by: */
int zxbustailf_main(int argc, char** argv, char** env)
{
  int ns;
  char buf[64];
  strncpy(zx_instance, "\tzxbustailf", sizeof(zx_instance));
  cf = zxid_new_conf_to_cf(0);
  opt(&argc, &argv, &env);

  for (; n_iter; --n_iter) {
    if (ns > 1 || n_iter > 1) {
      for (ns = n_send; ns; --ns) {
	snprintf(buf, sizeof(buf), "test(%d,%d)", n_iter, ns);
	zxbus_send(cf, strlen(bdy), buf);
      }
    } else {
      if (bdy) {
	zxbus_send(cf, strlen(bdy), bdy);
      }
    }
    /* *** implement actual tail functionality */
    
    zxbus_close_all(cf);
  }
  return 0;
}

/* EOF  --  zxbustailf.c */
