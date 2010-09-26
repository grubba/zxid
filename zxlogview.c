/* zxlogview.c  -  Encrypted and signed log decoder
 * Copyright (c) 2006-2009 Symlabs (symlabs@symlabs.com), All Rights Reserved.
 * Author: Sampo Kellomaki (sampo@iki.fi)
 * This is confidential unpublished proprietary source code of the author.
 * NO WARRANTY, not even implied warranties. Contains trade secrets.
 * Distribution prohibited unless authorized in writing.
 * Licensed under Apache License 2.0, see file COPYING.
 * $Id: zxlogview.c,v 1.15 2009-11-24 23:53:40 sampo Exp $
 *
 * 19.11.2006, started --Sampo
 * 29.8.2009, added hmac chaining field --Sampo
 *
 * TODO Ideas
 *
 * 1. DONE: Decrypt log lines and validate signatures
 * 2. Add some form of summary report gathered from the processed log lines.
 *    - sig failures
 *    - other errors
 *    - activity by IdP
 *    - activity by user (name ID)
 *    - activity in timeline
 *    - activity by operation
 * 3. Using /var/zxid/cot dereference the sha1 names to entity IDs
 * 4. Using /var/zxid/log/rely (and issue) chase the referenced
 *    assertions and validate them (sig, conditions, etc.) and
 *    extract statistics from them.
 * 5. Simple decryptor and signature verificator for encrypted
 *    files (e.g. rely assertions) (gpg or other standard compatible?)
 * 6. Regression test mode
 */

#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>

#ifdef USE_OPENSSL
#include <openssl/x509.h>
#include <openssl/rsa.h>
#include <openssl/aes.h>
#endif

#include "errmac.h"
#include "zx.h"
#include "zxid.h"
#include "c/zxidvers.h"

char* help =
"zxlogview  -  Decrypt logs and validate log signatures - R" ZXID_REL "\n\
SAML 2.0 is a standard for federated idenity and Single Sign-On.\n\
Copyright (c) 2006-2009 Symlabs (symlabs@symlabs.com), All Rights Reserved.\n\
Author: Sampo Kellomaki (sampo@iki.fi)\n\
NO WARRANTY, not even implied warranties. Licensed under Apache License v2.0\n\
See http://www.apache.org/licenses/LICENSE-2.0\n\
Send well researched bug reports to the author. Home: zxid.org\n\
\n\
Usage: zxlogview [options] logsign-nopw-cert.pem logenc-nopw-cert.pem <loglines\n\
  -t        Test mode. The certificates are interpretted from enc & sign perspective.\n\
  -v        Verbose messages.\n\
  -q        Be extra quiet.\n\
  -d        Turn on debugging.\n\
  -license  Show licensing and NO WARRANTY details.\n\
  -h        This help message\n\
  --        End of options\n";

#define DIE(reason) MB fprintf(stderr, "%s\n", reason); exit(2); ME

int verbose = 1;
extern int zx_debug;
int leak_free = 0;

X509* log_verify_cert;
RSA*  log_decrypt_pkey;
char  log_symkey[20];
char  buf[4096];

static void test_mode(int* argc, char*** argv, char*** env);

/* Called by:  main x8, zxcall_main, zxcot_main */
static void opt(int* argc, char*** argv, char*** env)
{
  int gotall;
  if (*argc <= 1) goto argerr;
  
  while (1) {
    ++(*argv); --(*argc);
    
    if (!(*argc) || ((*argv)[0][0] != '-')) break;  /* start of non option arguments */
    
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
      case 'i':  if ((*argv)[0][3]) break;
	++(*argv); --(*argc);
	if (!(*argc)) break;
	strcpy(zx_instance, (*argv)[0]);
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
      
    case 'r':
      switch ((*argv)[0][2]) {
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
      case 'a':
	if ((*argv)[0][3] == 0) {
	  /*AFR_TS(ASSERT_NONFATAL, 0, "assert nonfatal enabled");*/
#if 1
	  ERR("*** WARNING: YOU HAVE TURNED ASSERTS OFF USING -ra FLAG. THIS MEANS THAT YOU WILL NOT BE ABLE TO OBTAIN ANY SUPPORT. IF PROGRAM NOW TRIES TO ASSERT IT MAY MYSTERIOUSLY AND UNPREDICTABLY CRASH INSTEAD, AND NOBODY WILL BE ABLE TO FIGURE OUT WHAT WENT WRONG OR HOW MUCH DAMAGE MAY BE DONE. USING -ra IS NOT RECOMMENDED. %d\n", assert_nonfatal);
#endif
	  ++assert_nonfatal;
	  continue;
	}
	break;
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
      
    case 't': test_mode(argc, argv, env);
    } 
    /* fall thru means unrecognized flag */
    if (*argc)
      fprintf(stderr, "Unrecognized flag `%s'\n", (*argv)[0]);
  argerr:
    fprintf(stderr, help);
    exit(3);
  }

  if (*argc) {  /* Signature verification certificate (logsign-nopw-cert.pem) */
    if ((*argv)[0][0]) {
      read_all(sizeof(buf), buf, "logview opt cert", "%s", (*argv)[0]);
      log_verify_cert = zxid_extract_cert(buf, (*argv)[0]);
    }
    ++(*argv); --(*argc);
  }

  if (*argc) {  /* Log decryption key (logenc-nopw-cert.pem) */
    if ((*argv)[0][0]) {
      gotall = read_all(sizeof(buf), buf, "logview opt key", "%s", (*argv)[0]);
      SHA1((unsigned char*)buf, gotall, (unsigned char*)log_symkey);
      log_decrypt_pkey = zxid_extract_private_key(buf, (*argv)[0]);
    }
    ++(*argv); --(*argc);
  }
}

/* Called by:  opt */
static void test_mode(int* argc, char*** argv, char*** env)
{
  int gotall;
  zxid_conf* cf = zxid_new_conf(0);

  ++(*argv); --(*argc);
  if (*argc) {  /* Signature verification certificate (logsign-nopw-cert.pem) */
    if ((*argv)[0][0]) {
      read_all(sizeof(buf), buf, "logview test_mode private key", "%s", (*argv)[0]);
      cf->log_sign_pkey = zxid_extract_private_key(buf, (*argv)[0]);
    }
    ++(*argv); --(*argc);
  }
  
  if (*argc) {  /* Log encryption key (logenc-nopw-cert.pem) */
    if ((*argv)[0][0]) {
      gotall = read_all(sizeof(buf), buf, "logview test_mode key", "%s", (*argv)[0]);
      SHA1((unsigned char*)buf, gotall, (unsigned char*)cf->log_symkey);
      cf->log_enc_cert = zxid_extract_cert(buf, (*argv)[0]);
    }
    ++(*argv); --(*argc);
  }

  zxlog_write_line(cf, "zxlogview-test.out", 0x01, -2, "test1 Plain none\n");
  zxlog_write_line(cf, "zxlogview-test.out", 0x03, -2, "test2 Plain SHA1\n");
  zxlog_write_line(cf, "zxlogview-test.out", 0x05, -2, "test3 Plain RSA sig\n");

  zxlog_write_line(cf, "zxlogview-test.out", 0x11, -2, "test4 zip none\n");
  zxlog_write_line(cf, "zxlogview-test.out", 0x13, -2, "test5 zip SHA1\n");
  zxlog_write_line(cf, "zxlogview-test.out", 0x15, -2, "test6 zip RSA sig\n");
  
  zxlog_write_line(cf, "zxlogview-test.out", 0x21, -2, "test7 RSA-AES none\n");
  zxlog_write_line(cf, "zxlogview-test.out", 0x23, -2, "test8 RSA-AES SHA1\n");
  zxlog_write_line(cf, "zxlogview-test.out", 0x25, -2, "test9 RSA-AES RSA sig\n");

  zxlog_write_line(cf, "zxlogview-test.out", 0x41, -2, "test10 AES none\n");
  zxlog_write_line(cf, "zxlogview-test.out", 0x43, -2, "test11 AES SHA1\n");
  zxlog_write_line(cf, "zxlogview-test.out", 0x45, -2, "test12 AES RSA sig\n");

  exit(0);
}

/* Called by:  main x3 */
static void zxlog_zsig_verify_print(zxid_conf* cf, int len, char* buf, char* se, char* p)
{
  char sha1[20];
  char* sig;
  int verdict, siglen = (unsigned char)p[0] << 8 | (unsigned char)p[1];
  D("siglen(%d)", siglen);
  sig = p+2;
  p += 2+siglen;
  
  switch (se[0]) {
  case 'P':
    if (siglen) {
      ERR("No sig, siglen should be zero. Found %d", siglen);
      break;
    }
    break;
  case 'R':
    if (!siglen) {
      ERR("RSA sig claimed by no sig found. %d", siglen);
      break;
    }
    verdict = zxsig_verify_data_rsa_sha1(len-(p-buf), p, siglen, sig, log_verify_cert, "log vfy");
    if (verdict) {
      printf("RSA signature FAIL. Log file may have been tampered - or bad certificate.\n");
    } else {
      printf("RSA signature OK\n");
    }
    break;
  case 'D':  ERR("Unimplemented sign %c", se[1]); break;
  case 'S':
    if (siglen != 20) {
      ERR("Wrong sha1 length in input %d", siglen);
      break;
    }
    SHA1((unsigned char*)p, len-(p-buf), (unsigned char*)sha1);
    if (memcmp(sha1, buf+2, 20)) {
      printf("SHA1 FAIL\n");
    } else {
      printf("SHA1 OK\n");
    }
    break;
  default:   ERR("Unimplemented sign %c", se[1]); break;
  }
  sig = zx_zlib_raw_inflate(cf->ctx, len-(p-buf), p, &siglen);
  printf("----- %03d %c%c %.*s\n", siglen, se[0], se[1], siglen, sig);  /* Inflated plain text */
  ZX_FREE(cf->ctx, sig);
}

/* ============== M A I N ============== */

/*(-) Control starts here */
/* Called by: */
int main(int argc, char** argv, char** env)
{
  int len, seslen, ver;
  char* p;
  char* pp;
  char se[4];
  char ses[16];
  char sha1[20];
  struct aes_key_st aes_key;
  zxid_conf* cf = zxid_new_conf(0);
  strcpy(zx_instance, "\tzxlogview");
  opt(&argc, &argv, &env);
  
  while (1) {
    if (scanf("%2s %4095[^\n]\n", se, buf) <= 0) {
      D("scanf unable to scan line. Presme end of file. %d", 0);
      return 0;
    }
    len = strlen(buf);
    switch (se[1]) {
    case 'P':   /* Plain: neither compressed nor encrypted. */
      printf("----+ %03d %c%c %.*s\n", len, se[0], se[1], len, buf);
      p = strchr(buf, ' ');
      if (!p) {
	ERR("Separator space not found. Corrupt line(%.*s)", len, buf);
	break;
      }
      
      switch (se[0]) {
      case 'P':  /* No sig */
	break;
      case 'R':
	pp = unbase64_raw(buf, p, buf, zx_std_index_64);  /* In place, overwrite. */
	++p;
	ver = zxsig_verify_data_rsa_sha1(len-(p-buf), p, pp-buf, buf, log_verify_cert, "log vfy");
	if (ver) {
	  printf("RSA signature FAIL. Log file may have been tampered - or bad certificate.\n");
	} else {
	  printf("RSA signature OK\n");
	}
	break;
      case 'D':  ERR("Unimplemented sign %c", se[1]); break;
      case 'S':
	unbase64_raw(buf, p, buf, zx_std_index_64);  /* In place, overwrite. */
	++p;
	SHA1((unsigned char*)p, len-(p-buf), (unsigned char*)sha1);
	if (memcmp(buf, sha1, 20)) {
	  printf("SHA1 FAIL\n");
	} else {
	  printf("SHA1 OK\n");
	}
	break;
      default:   ERR("Unimplemented sign %c", se[1]); break;
      }
      break;

    case 'A':  /* RSA-AES encrypted */
      p = unbase64_raw(buf, buf+len, buf, zx_std_index_64);
      len = p-buf;
      D("unbase64 len(%d)", len);
      seslen = (unsigned char)buf[0] << 8 | (unsigned char)buf[1];
      D("seslen(%d)", seslen);
      
      seslen = RSA_private_decrypt(seslen, (unsigned char*)buf+2, (unsigned char*)ses, log_decrypt_pkey, RSA_PKCS1_OAEP_PADDING);
      if (seslen < 0) {
	ERR("RSA dec fail %x", seslen);
	zx_report_openssl_error("zxlog rsa enc");
	break;
      }
      D("decrypted session key len(%d)", seslen);
      if (seslen != 16) {
	ERR("Decrypted session key not right size(%d), should be 16.", seslen);
	break;
      }
      
      p = buf+2+seslen+16;
      AES_set_decrypt_key((unsigned char*)ses, 128, &aes_key);
      AES_cbc_encrypt((unsigned char*)p, (unsigned char*)p, len-(p-buf), &aes_key, (unsigned char*)buf+2+seslen,0);
      zxlog_zsig_verify_print(cf, len, buf, se, p);
      break;
    case 'T':  ERR("Unimplemented decryption %c", se[1]); break;
    case 'B':  /* Symmetric AES encrypted */
      p = unbase64_raw(buf, buf+len, buf, zx_std_index_64);
      len = p-buf;
      D("unbase64 len(%d)", len);
      p = buf+16;
      AES_set_decrypt_key((unsigned char*)log_symkey, 128, &aes_key);
      AES_cbc_encrypt((unsigned char*)p, (unsigned char*)p, len-16, &aes_key, (unsigned char*)buf, 0);
      zxlog_zsig_verify_print(cf, len, buf, se, p);
      break;
    case 'U':  ERR("Unimplemented decryption %c", se[1]); break;
    case 'Z':  /* RFC1951 zip + safe base64 only */
      p = unbase64_raw(buf, buf+len, buf, zx_std_index_64);
      len = p-buf;
      D("unbase64 len(%d)", len);
      zxlog_zsig_verify_print(cf, len, buf, se, buf);
      break;
    default:   ERR("Unknown decryption %c", se[1]); break;
    }
  }
  return 0;
}

//char* assert_msg = "%s: Internal error caused an ASSERT to fire. Deliberately provoking a core dump.\nSorry for the inconvenience.\n";

/* EOF  --  zxlogview.c */
