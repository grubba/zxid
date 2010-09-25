/* zxencdectest.c  -  Test XML encoding and decoding using zx generated code
 * Copyright (c) 2010 Sampo Kellomaki (sampo@iki.fi), All Rights Reserved.
 * Copyright (c) 2006-2007 Symlabs (symlabs@symlabs.com), All Rights Reserved.
 * Author: Sampo Kellomaki (sampo@iki.fi)
 * This is confidential unpublished proprietary source code of the author.
 * NO WARRANTY, not even implied warranties. Contains trade secrets.
 * Distribution prohibited unless authorized in writing.
 * Licensed under Apache License 2.0, see file COPYING.
 * $Id: zxencdectest.c,v 1.9 2009-11-24 23:53:40 sampo Exp $
 *
 * 1.7.2006, started --Sampo
 * 9.2.2007, improved to make basis of a test suite tool --Sampo
 *
 * Test encoding and decoding SAML 2.0 assertions and other related stuff.
 */

#include <signal.h>
#include <fcntl.h>
#include <netdb.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <openssl/x509.h>

#include "errmac.h"

#include "zx.h"
#include "zxid.h"
#include "c/zxidvers.h"
#include "c/zx-data.h"
#include "c/zx-const.h"
#include "c/zx-ns.h"

int read_all_fd(int fd, char* p, int want, int* got_all);
int write_all_fd(int fd, char* p, int pending);

CU8* help =
"zxencdectest  -  ZX encoding and decoding tester - R" ZXID_REL "\n\
Copyright (c) 2010 Sampo Kellomaki (sampo@iki.fi), All Rights Reserved.\n\
Copyright (c) 2006-2007 Symlabs (symlabs@symlabs.com), All Rights Reserved.\n\
Author: Sampo Kellomaki (sampo@iki.fi)\n\
NO WARRANTY, not even implied warranties. Licensed under Apache License v2.0\n\
See http://www.apache.org/licenses/LICENSE-2.0\n\
Send well researched bug reports to the author. Home: zxid.org\n\
\n\
Usage: zxencdectest [options] <foo.xml >reencoded-foo.xml\n\
  -r N         Run test number N. 1 = IBM cert dec, 2 = IBM cert enc dec\n\
  -i N         Number of iterations to benchmark (default 1).\n\
  -t SECONDS   Timeout. Default: 0=no timeout.\n\
  -c CIPHER    Enable crypto on DTS interface using specified cipher. Use '?' for list.\n\
  -k FDNUMBER  File descriptor for reading symmetric key. Use 0 for stdin.\n\
  -egd PATH    Specify path of Entropy Gathering Daemon socket, default\n\
               on Solaris: /tmp/entropy; Linux: /dev/urandom\n\
               See http://www.lothar.com/tech/crypto/ or\n\
               http://www.aet.tu-cottbus.de/personen/jaenicke/postfix_tls/prngd.html\n\
  -rand PATH   Location of random number seed file. On Solaris EGD is used.\n\
               On Linux the default is /dev/urandom. See RFC1750.\n\
  -so PATH     File to write schema order encoding in\n\
  -wo PATH     File to write wire order encoding in\n\
  -v           Verbose messages.\n\
  -q           Be extra quiet.\n\
  -d           Turn on debugging.\n\
  -license     Show licensing and NO WARRANTY details.\n\
  -h           This help message\n\
  --           End of options\n";

#define DIE(reason) MB fprintf(stderr, "%s\n", reason); exit(2); ME
char buf[256*1024];

/* Called by:  opt */
void test_ibm_cert_problem()
{
  int got_all, len_so;
  zxid_conf* cf;
  struct zx_root_s* r;
  struct zx_sp_LogoutRequest_s* req;

  len_so = read_all_fd(0, buf, sizeof(buf)-1, &got_all);
  if (got_all <= 0) DIE("Missing data");
  buf[got_all] = 0;

  /* IBM padding debug */
  cf = zxid_new_conf("/var/zxid/");
  LOCK(cf->ctx->mx, "zxencdectest");
  zx_prepare_dec_ctx(cf->ctx, zx_ns_tab, buf, buf + got_all);
  r = zx_DEC_root(cf->ctx, 0, 1000);
  UNLOCK(cf->ctx->mx, "zxencdectest");
  if (!r)
    DIE("Decode failure");

#if 1
  cf->enc_pkey = zxid_read_private_key(cf, "sym-idp-enc.pem");
#else
  cf->enc_pkey = zxid_read_private_key(cf, "ibm-idp-enc.pem");
#endif
  
  req = r->Envelope->Body->LogoutRequest;
  req->NameID = zxid_decrypt_nameid(cf, req->NameID, req->EncryptedID);
  printf("r1 nid(%.*s)\n", req->NameID->gg.content->len, req->NameID->gg.content->s);
}

/* Called by:  opt */
void test_ibm_cert_problem_enc_dec()
{
  zxid_conf* cf;
  struct zx_sp_LogoutRequest_s* req;
  zxid_nid* nameid;
  zxid_entity* idp_meta;

  cf = zxid_new_conf("/var/zxid/");

  nameid = zx_NEW_sa_NameID(cf->ctx);
  nameid->Format = zx_ref_str(cf->ctx, "persistent");
  nameid->NameQualifier = zx_ref_str(cf->ctx, "ibmidp");
  /*nameid->SPNameQualifier = zx_ref_str(cf->ctx, spqual);*/
  nameid->gg.content = zx_ref_str(cf->ctx, "a-persistent-nid");

#if 0
  cf->enc_pkey = zxid_read_private_key(cf, "sym-idp-enc.pem");
#else
  cf->enc_pkey = zxid_read_private_key(cf, "ibm-idp-enc.pem");
  idp_meta = zxid_get_ent_from_file(cf, "N9zsU-AwbI1O-U3mvjLmOALtbtU"); /* IBMIdP */
#endif
  
  req = zxid_mk_logout(cf, nameid, 0, idp_meta);  
  req->NameID = zxid_decrypt_nameid(cf, req->NameID, req->EncryptedID);
  printf("r2 nid(%.*s) should be(a-persistent-nid)\n", req->NameID->gg.content->len, req->NameID->gg.content->s);
}

int afr_buf_size = 0;
int verbose = 1;
extern int debug;
int timeout = 0;
int gcthreshold = 0;
int leak_free = 0;
extern int assert_nonfatal;
int drop_uid = 0;
int drop_gid = 0;
char* rand_path;
char* egd_path;
char  symmetric_key[1024];
int symmetric_key_len;
int n_iter = 1;
char* so_path = 0;
char* wo_path = 0;

/* Called by:  main x8, zxcall_main, zxcot_main */
void opt(int* argc, char*** argv, char*** env)
{
  if (*argc < 1) goto argerr;
  
  while (1) {
    ++(*argv); --(*argc);
    
    if (!(*argc) || ((*argv)[0][0] != '-')) break;
    
    switch ((*argv)[0][1]) {
    case '-': if ((*argv)[0][2]) break;
      ++(*argv); --(*argc);
      DD("End of options by --");
      return;  /* -- ends the options */

    case 'i': if ((*argv)[0][2]) break;
      ++(*argv); --(*argc);
      if (!(*argc)) break;
      n_iter = atoi((*argv)[0]);
      continue;

    case 't': if ((*argv)[0][2]) break;
      ++(*argv); --(*argc);
      if (!(*argc)) break;
      timeout = atoi((*argv)[0]);
      continue;

    case 'd':
      switch ((*argv)[0][2]) {
      case '\0':
	++zx_debug;
	continue;
      case 'i':  if ((*argv)[0][3]) break;
	++(*argv); --(*argc);
	if (!(*argc)) break;
	zx_instance = (*argv)[0];
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

    case 'q':
      switch ((*argv)[0][2]) {
      case '\0':
	verbose = 0;
	continue;
      }
      break;

    case 'e':
      switch ((*argv)[0][2]) {
      case 'g': if ((*argv)[0][3] != 'd' || (*argv)[0][4]) break;
	++(*argv); --(*argc);
	if (!(*argc)) break;
	egd_path = (*argv)[0];
	continue;
      }
      break;
      
    case 'r':
      switch ((*argv)[0][2]) {
      case '\0':
	++(*argv); --(*argc);
	if (!(*argc)) break;
	switch (atoi((*argv)[0])) {
	case 1: test_ibm_cert_problem(); break;
	case 2: test_ibm_cert_problem_enc_dec(); break;
	}
	exit(0);

      case 'f':
	/*AFR_TS(LEAK, 0, "memory leaks enabled");*/
#if 1
	ERR("*** WARNING: You have turned memory frees to memory leaks. We will (eventually) run out of memory. Using -rf is not recommended. %d\n", 0);
#endif
	++leak_free;
	continue;
#if 0
      case 'e':
	if ((*argv)[0][3]) break;
	++(*argv); --(*argc);
	if ((*argc) < 4) break;
	sscanf((*argv)[0], "%i", &abort_funcno);
	++(*argv); --(*argc);
	sscanf((*argv)[0], "%i", &abort_line);
	++(*argv); --(*argc);
	sscanf((*argv)[0], "%i", &abort_error_code);
	++(*argv); --(*argc);
	sscanf((*argv)[0], "%i", &abort_iter);
	fprintf(stderr, "Will force core upon %x:%x err=%d iter=%d\n",
		abort_funcno, abort_line, abort_error_code, abort_iter);
	continue;
#endif
      case 'g':
	if ((*argv)[0][3]) break;
	++(*argv); --(*argc);
	if (!(*argc)) break;
	gcthreshold = atoi((*argv)[0]);
	if (!gcthreshold)
	  ERR("*** WARNING: You have disabled garbage collection. This may lead to increased memory consumption for scripts that handle a lot of PDUs or run for long time. Using `-rg 0' is not recommended. %d\n", 0);
	continue;
      case 'a':
	if ((*argv)[0][3] == 0) {
	  /*AFR_TS(ASSERT_NONFATAL, 0, "assert nonfatal enabled");*/
#if 1
	  ERR("*** WARNING: YOU HAVE TURNED ASSERTS OFF USING -ra FLAG. THIS MEANS THAT YOU WILL NOT BE ABLE TO OBTAIN ANY SUPPORT. IF PROGRAM NOW TRIES TO ASSERT IT MAY MYSTERIOUSLY AND UNPREDICTABLY CRASH INSTEAD, AND NOBODY WILL BE ABLE TO FIGURE OUT WHAT WENT WRONG OR HOW MUCH DAMAGE MAY BE DONE. USING -ra IS NOT RECOMMENDED. %d\n", assert_nonfatal);
#endif
	  ++assert_nonfatal;
	  continue;
	}
	if (!strcmp((*argv)[0],"-rand")) {
	  ++(*argv); --(*argc);
	  if (!(*argc)) break;
	  rand_path = (*argv)[0];
	  continue;
	}
	break;
      }
      break;

    case 's':
      switch ((*argv)[0][2]) {
      case 'o': if ((*argv)[0][3]) break;
	++(*argv); --(*argc);
	if (!(*argc)) break;
	so_path = (*argv)[0];
	continue;
      }
      break;

    case 'w':
      switch ((*argv)[0][2]) {
      case 'o': if ((*argv)[0][3]) break;
	++(*argv); --(*argc);
	if (!(*argc)) break;
	wo_path = (*argv)[0];
	continue;
      }
      break;

    case 'k':
      switch ((*argv)[0][2]) {
      case '\0':
	++(*argv); --(*argc);
	if (!(*argc)) break;
	read_all_fd(atoi((*argv)[0]), symmetric_key, sizeof(symmetric_key), &symmetric_key_len);
	D("Got %d characters of symmetric key", symmetric_key_len);
	continue;
      }
      break;

    case 'c': if ((*argv)[0][2]) break;
      ++(*argv); --(*argc);
      if (!(*argc)) break;
#ifndef ENCRYPTION
      ERR("Encryption not compiled in. %d",0);
#endif
      continue;

    case 'u':
      switch ((*argv)[0][2]) {
      case 'i': if ((*argv)[0][3] != 'd' || (*argv)[0][4]) break;
	++(*argv); --(*argc);
	if (!(*argc)) break;
	sscanf((*argv)[0], "%i:%i", &drop_uid, &drop_gid);
	continue;
      }
      break;

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

    } 
    /* fall thru means unrecognized flag */
    if (*argc)
      fprintf(stderr, "Unrecognized flag `%s'\n", (*argv)[0]);
  argerr:
    fprintf(stderr, help);
    exit(3);
  }
}

/* ============== M A I N ============== */

/* Called by: */
int main(int argc, char** argv, char** env)
{
  struct zx_ctx ctx;
  struct zx_root_s* r;
  int got_all, len_so, len_wo;
  char so_out[256*1024];
  char* so_p;
  char wo_out[256*1024];
  char* wo_p;
  opt(&argc, &argv, &env);
  
  len_so = read_all_fd(0, buf, sizeof(buf)-1, &got_all);
  if (got_all <= 0) DIE("Missing data");
  buf[got_all] = 0;

  D("Decoding %d chars, n_iter(%d)\n", got_all, n_iter);
  
  for (; n_iter; --n_iter) {
    memset(&ctx, 0, sizeof(ctx));
    LOCK(ctx.mx, "zxencdectest main");
    zx_prepare_dec_ctx(&ctx, zx_ns_tab, buf, buf + got_all);
    r = zx_DEC_root(&ctx, 0, 1000);
    UNLOCK(ctx.mx, "zxencdectest main");
    if (!r)
      DIE("Decode failure");

    len_so = zx_LEN_SO_root(&ctx, r);
    D("Enc so len %d chars", len_so);

    ctx.bas = so_out;
    so_p = zx_ENC_SO_root(&ctx, r, so_out);
    if (!so_p)
      DIE("encoding error");

    len_wo = zx_LEN_WO_root(&ctx, r);
    D("Enc wo len %d chars", len_wo);

    ctx.bas = wo_out;
    wo_p = zx_ENC_WO_root(&ctx, r, wo_out);
    if (!wo_p)
      DIE("encoding error");

    zx_FREE_root(&ctx, r, 0);
  }

  if (got_all != len_wo)
    printf("Original and WO are different lengths %d != %d\n", got_all, len_wo);

  if (memcmp(buf, wo_out, MIN(got_all, len_wo)))
    printf("Original and WO differ.\n");

  if (memcmp(so_out, wo_out, MIN(len_so, len_wo)))
    printf("SO and WO differ.\n");

  if (so_p - so_out != len_so)
    ERR("SO encode length mismatch %d vs. %d (len)", so_p - so_out, len_so);
  printf("Re-encoded result SO (len=%d):\n%.*s\n\n", len_so, len_so, so_out);

  if (wo_p - wo_out != len_wo)
    ERR("WO encode length mismatch %d vs %d (len)", wo_p - wo_out, len_wo);
  printf("Re-encoded result WO (len=%d):\n%.*s\n\n", len_wo, len_wo, wo_out);

  if (so_path)
    write_all_path_fmt("SO", sizeof(buf), buf, "%s", so_path, 0, "%.*s", len_so, so_out);
  if (wo_path)
    write_all_path_fmt("WO", sizeof(buf), buf, "%s", wo_path, 0, "%.*s", len_wo, wo_out);
  return 0;
}

/* EOF  --  zxencdectest.c */
