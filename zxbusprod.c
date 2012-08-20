/* zxbusprod.c  -  Liberty oriented logging facility with log signing and encryption
 * Copyright (c) 2012 Synergetics (sampo@synergetics.be), All Rights Reserved.
 * Copyright (c) 2010-2011 Sampo Kellomaki (sampo@iki.fi), All Rights Reserved.
 * Copyright (c) 2006-2009 Symlabs (symlabs@symlabs.com), All Rights Reserved.
 * Author: Sampo Kellomaki (sampo@iki.fi)
 * This is confidential unpublished proprietary source code of the author.
 * NO WARRANTY, not even implied warranties. Contains trade secrets.
 * Distribution prohibited unless authorized in writing.
 * Licensed under Apache License 2.0, see file COPYING.
 * $Id$
 *
 * 17.8.2012,  creted, based on zxlog.c --Sampo
 * 19.8.2012, added tolerance for CRLF where strictly LF is meant --Sampo
 *
 * Apart from formatting code, this is effectively a STOMP 1.1 client. Typically
 * it will talk to zxbusd instances configured using BUS_URL options.
 *
 * See also:  http://stomp.github.com/stomp-specification-1.1.html (20110331)
 */

#include "platform.h"  /* needed on Win32 for pthread_mutex_lock() et al. */

#include <fcntl.h>
#include <string.h>
#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <time.h>
#include <netdb.h>
#include <sys/types.h>
#include <sys/stat.h>

#ifdef USE_OPENSSL
#include <openssl/x509.h>
#include <openssl/rsa.h>
#include <openssl/evp.h>
#include <openssl/aes.h>
#endif

#include "errmac.h"
#include "zxid.h"
#include "zxidutil.h"  /* for zx_zlib_raw_deflate(), safe_basis_64, and name_from_path */
#include "zxidconf.h"
#include "c/zx-data.h"  /* Generated. If missing, run `make dep ENA_GEN=1' */

#define ZXBUS_TIME_FMT "%04d%02d%02d-%02d%02d%02d.%03ld"
#define ZXBUS_TIME_ARG(t,usec) t.tm_year + 1900, t.tm_mon + 1, t.tm_mday, \
                               t.tm_hour, t.tm_min, t.tm_sec, usec/1000

#if 0
/*() Allocate memory for logging purposes.
 * Generally memory allocation goes via zx_alloc() family of functions. However
 * dues to special requirements of cryptographically implemeted logging,
 * we maintain this special allocation function (which backends to zx_alloc()).
 * Among the special features: This function makes sure the buffer size is
 * rounded up to multiple of nonce to accommodate block ciphers.
 *
 * This function is considered internal. Do not use unless you know what you are doing. */

/* Called by:  zxbus_write_line x3 */
static char* zxbus_alloc_zbuf(zxid_conf* cf, int *zlen, char* zbuf, int len, char* sig, int nonce)
{
  char* p;
  int siz = nonce + 2 + len + *zlen;
  ROUND_UP(siz, nonce);        /* Round up to block size */
  p = ZX_ALLOC(cf->ctx, siz);
  if (nonce)
    zx_rand(p, nonce);
  p[nonce] = (len >> 8) & 0xff;
  p[nonce+1] = len & 0xff;
  if (len) {
    memcpy(p+nonce+2, sig, len);
    ZX_FREE(cf->ctx, sig);
  }
  memcpy(p+nonce+2+len, zbuf, *zlen);
  ZX_FREE(cf->ctx, zbuf);
  *zlen += nonce + 2 + len;
  return p;
}

/*() Write a line to a log, taking care of all formalities of locking and
* observing all special options for signing and encryption of the logs.
* Not usually called directly (but you can if you want to), this is the
* work horse behind zxbus().
*
* cf::  ZXID configuration object, used for memory allocation.
* c_path:: Path to the log file, as C string
* encflags:: Encryption flags. See LOG_ERR or LOG_ACT configuration options in zxidconf.h
* n:: length of log data
* logbuf:: The data that should be logged
*/

/* Called by:  test_mode x12, zxbus_output x2 */
void zxbus_write_line(zxid_conf* cf, char* c_path, int encflags, int n, const char* logbuf)
{
  EVP_PKEY* log_sign_pkey;
  struct rsa_st* rsa_pkey;
  struct aes_key_st aes_key;
  int len = 0, blen, zlen;
  char sigletter = 'P';
  char encletter = 'P';
  char* p;
  char* sig = 0;
  char* zbuf;
  char* b64;
  char sigbuf[28+4];   /* Space for "SP " and sha1 */
  char keybuf[16];
  char ivec[16];
  if (n == -2)
    n = strlen(logbuf);
  if (encflags & 0x70) {          /* Encrypt check */
    zbuf = zx_zlib_raw_deflate(cf->ctx, n-1, logbuf, &zlen);
    switch (encflags & 0x06) {     /* Sign check */
    case 0x02:      /* Sx plain sha1 */
      sigletter = 'S';
      sig = ZX_ALLOC(cf->ctx, 20);
      SHA1((unsigned char*)zbuf, zlen, (unsigned char*)sig);
      len = 20;
      break;
    case 0x04:      /* Rx RSA-SHA1 signature */
      sigletter = 'R';
      LOCK(cf->mx, "logsign-wrln");      
      if (!(log_sign_pkey = cf->log_sign_pkey))
	log_sign_pkey = cf->log_sign_pkey = zxid_read_private_key(cf, "logsign-nopw-cert.pem");
      UNLOCK(cf->mx, "logsign-wrln");      
      if (!log_sign_pkey)
	break;
      len = zxsig_data(cf->ctx, zlen, zbuf, &sig, log_sign_pkey, "enc log line");
      break;
    case 0x06:      /* Dx DSA-SHA1 signature */
      ERR("DSA-SHA1 sig not implemented in encrypted mode. Use RSA-SHA1 or none. %x", encflags);
      break;
    case 0: break;  /* Px no signing */
    }
    
    switch (encflags & 0x70) {
    case 0x10:  /* xZ RFC1951 zip + safe base64 */
      encletter = 'Z';
      zbuf = zxbus_alloc_zbuf(cf, &zlen, zbuf, len, sig, 0);
      break;
    case 0x20:  /* xA RSA-AES */
      encletter = 'A';
      zbuf = zxbus_alloc_zbuf(cf, &zlen, zbuf, len, sig, 16);
      zx_rand(keybuf, 16);
      AES_set_encrypt_key((unsigned char*)keybuf, 128, &aes_key);
      memcpy(ivec, zbuf, sizeof(ivec));
      AES_cbc_encrypt((unsigned char*)zbuf+16, (unsigned char*)zbuf+16, zlen-16, &aes_key, (unsigned char*)ivec, 1);
      ROUND_UP(zlen, 16);        /* Round up to block size */

      LOCK(cf->mx, "logenc-wrln");
      if (!cf->log_enc_cert)
	cf->log_enc_cert = zxid_read_cert(cf, "logenc-nopw-cert.pem");
      rsa_pkey = zx_get_rsa_pub_from_cert(cf->log_enc_cert, "log_enc_cert");
      UNLOCK(cf->mx, "logenc-wrln");
      if (!rsa_pkey)
	break;
      
      len = RSA_size(rsa_pkey);
      sig = ZX_ALLOC(cf->ctx, len);
      if (RSA_public_encrypt(16, (unsigned char*)keybuf, (unsigned char*)sig, rsa_pkey, RSA_PKCS1_OAEP_PADDING) < 0) {
	ERR("RSA enc fail %x", encflags);
	zx_report_openssl_error("zxbus rsa enc");
	return;
      }
      p = ZX_ALLOC(cf->ctx, 2 + len + zlen);
      p[0] = (len >> 8) & 0xff;
      p[1] = len & 0xff;
      memcpy(p+2, sig, len);
      memcpy(p+2+len, zbuf, zlen);
      ZX_FREE(cf->ctx, sig);
      ZX_FREE(cf->ctx, zbuf);
      zbuf = p;
      zlen += 2 + len;
      break;
    case 0x30:  /* xT RSA-3DES */
      encletter = 'T';
      ERR("Enc not implemented %x", encflags);
      break;
    case 0x40:  /* xB AES */
      encletter = 'B';
      zbuf = zxbus_alloc_zbuf(cf, &zlen, zbuf, len, sig, 16);
      if (!cf->log_symkey[0])
	zx_get_symkey(cf, "logenc.key", cf->log_symkey);
      AES_set_encrypt_key((unsigned char*)cf->log_symkey, 128, &aes_key);
      memcpy(ivec, zbuf, sizeof(ivec));
      AES_cbc_encrypt((unsigned char*)zbuf+16, (unsigned char*)zbuf+16, zlen-16, &aes_key, (unsigned char*)ivec, 1);
      ROUND_UP(zlen, 16);        /* Round up to block size */
      break;
    case 0x50:  /* xU 3DES */
      encletter = 'U';
      ERR("Enc not implemented %x", encflags);
      break;
    default:
      ERR("Enc not implemented %x", encflags);
      break;
    }

    blen = SIMPLE_BASE64_LEN(zlen) + 3 + 1;
    b64 = ZX_ALLOC(cf->ctx, blen);
    b64[0] = sigletter;
    b64[1] = encletter;
    b64[2] = ' ';
    p = base64_fancy_raw(zbuf, zlen, b64+3, safe_basis_64, 1<<31, 0, 0, '.');
    blen = p-b64 + 1;
    *p = '\n';
    write2_or_append_lock_c_path(c_path, 0, 0, blen, b64, "zxbus enc", SEEK_END, O_APPEND);
    return;
  }

  /* Plain text, possibly signed. */

  switch (encflags & 0x06) {
  case 0x02:   /* SP plain sha1 */
    strcpy(sigbuf, "SP ");
    sha1_safe_base64(sigbuf+3, n-1, logbuf);
    sigbuf[3+27] = ' ';
    len = 3+27+1;
    p = sigbuf;
    break;
  case 0x04:   /* RP RSA-SHA1 signature */
    LOCK(cf->mx, "logsign-wrln");      
    if (!(log_sign_pkey = cf->log_sign_pkey))
      log_sign_pkey = cf->log_sign_pkey = zxid_read_private_key(cf, "logsign-nopw-cert.pem");
    UNLOCK(cf->mx, "logsign-wrln");
    if (!log_sign_pkey)
      break;
    zlen = zxsig_data(cf->ctx, n-1, logbuf, &zbuf, log_sign_pkey, "log line");
    len = SIMPLE_BASE64_LEN(zlen) + 4;
    sig = ZX_ALLOC(cf->ctx, len);
    strcpy(sig, "RP ");
    p = base64_fancy_raw(zbuf, zlen, sig+3, safe_basis_64, 1<<31, 0, 0, '.');
    len = p-sig + 1;
    *p = ' ';
    p = sig;
    break;
  case 0x06:   /* DP DSA-SHA1 signature */
    ERR("DSA-SHA1 signature not implemented %x", encflags);
    break;
  case 0:      /* Plain logging, no signing, no encryption. */
    len = 5;
    p = "PP - ";
    break;
  }
  write2_or_append_lock_c_path(c_path, len, p, n, logbuf, "zxbus sig", SEEK_END, O_APPEND);
  if (sig)
    ZX_FREE(cf->ctx, sig);
}

/*() Helper function for formatting all kinds of logs. */

static int zxbus_fmt(zxid_conf* cf,   /* 1 */
		     int len, char* logbuf,
		     struct timeval* ourts,  /* 2 null allowed, will use current time */
		     struct timeval* srcts,  /* 3 null allowed, will use start of unix epoch... */
		     const char* ipport,     /* 4 null allowed, -:- or cf->ipport if not given */
		     struct zx_str* entid,   /* 5 null allowed, - if not given */
		     struct zx_str* msgid,   /* 6 null allowed, - if not given */
		     struct zx_str* a7nid,   /* 7 null allowed, - if not given */
		     struct zx_str* nid,     /* 8 null allowed, - if not given */
		     const char* sigval,     /* 9 null allowed, - if not given */
		     const char* res,        /* 10 */
		     const char* op,         /* 11 */
		     const char* arg,        /* 12 null allowed, - if not given */
		     const char* fmt,        /* 13 null allowed as format, ends the line */
		     va_list ap)
{
  int n;
  char* p;
  char sha1_name[28];
  struct tm ot;
  struct tm st;
  struct timeval ourtsdefault;
  struct timeval srctsdefault;
  
  /* Prepare values */

  if (!ourts) {
    ourts = &ourtsdefault;
    GETTIMEOFDAY(ourts, 0);
  }
  if (!srcts) {
    srcts = &srctsdefault;
    srctsdefault.tv_sec = 0;
    srctsdefault.tv_usec = 501000;
  }
  GMTIME_R(ourts->tv_sec, ot);
  GMTIME_R(srcts->tv_sec, st);
  
  if (entid && entid->len && entid->s) {
    sha1_safe_base64(sha1_name, entid->len, entid->s);
    sha1_name[27] = 0;
  } else {
    sha1_name[0] = '-';
    sha1_name[1] = 0;
  }
  
  if (!ipport) {
    ipport = cf->ipport;
    if (!ipport)
      ipport = "-:-";
  }
  
  /* Format */
  
  n = snprintf(logbuf, len-3, ZXBUS_TIME_FMT " " ZXBUS_TIME_FMT
	       " %s %s"  /* ipport  sha1_name-of-ent */
	       " %.*s"
	       " %.*s"
	       " %.*s"
	       " %s %s %s %s %s ",
	       ZXBUS_TIME_ARG(ot, ourts->tv_usec), ZXBUS_TIME_ARG(st, srcts->tv_usec),
	       ipport, sha1_name,
	       msgid?msgid->len:1, msgid?msgid->s:"-",
	       a7nid?a7nid->len:1, a7nid?a7nid->s:"-",
	       nid?nid->len:1,     nid?nid->s:"-",
	       zx_instance, STRNULLCHKD(sigval), res, op, arg?arg:"-");
  logbuf[len-1] = 0; /* must terminate manually as on win32 nul is not guaranteed */
  if (n <= 0 || n >= len-3) {
    if (n < 0) {
      perror("snprintf");
      D("Broken snprintf? Impossible to compute length of string. Be sure to `export LANG=C' if you get errors about multibyte characters. Length returned: %d", n);
    }
    D("Log buffer too short: %d chars needed", n);
    if (n <= 0)
      n = 0;
    else
      n = len-3;
  } else { /* Space left: try printing the format string as well! */
    p = logbuf+n;
    if (fmt && fmt[0]) {
      n = vsnprintf(p, len-n-2, fmt, ap);
      logbuf[len-1] = 0;  /* must terminate manually as on win32 nul term is not guaranteed */
      if (n <= 0 || n >= len-(p-logbuf)-2) {
	if (n < 0) {
	  perror("vsnprintf");
	  D("Broken vsnprintf? Impossible to compute length of string. Be sure to `export LANG=C' if you get errors about multibyte characters. Length returned: %d", n);
	}
	D("Log buffer truncated during format print: %d chars needed", n);
	if (n <= 0)
	  n = p-logbuf;
	else
	  n = len-(p-logbuf)-2;
      } else
	n += p-logbuf;
    } else {
      logbuf[n++] = '-';
    }
  }
  logbuf[n++] = '\n';
  logbuf[n] = 0;
  /*logbuf[len-1] = 0;*/
  return n;
}
#endif

#define ZXBUS_BUF_SIZE 4096
/* Alias some struct fields for headers that can not be seen together. */
#define receipt   host
#define rcpt_id   host
#define acpt_vers vers
#define tx_id     vers
#define session   login
#define subs_id   login
#define subsc     login
#define server    pw
#define ack       pw
#define msg_id    pw
#define heart_bt  dest

struct stomp_hdr {
  int len;               /* Populated from content-length header, if one is supplied. */
  char* body;            /* Body of the message */
  char* host;            /* also receipt and receipt_id */
  char* vers;            /* version, also accept-version, tx_id */
  char* login;           /* also session, subs_id, subsc */
  char* pw;              /* also server, ack, msg_id */
  char* dest;            /* destination, also heart_bt */
  char* end_of_pdu;      /* One past end of frame data. Helps in cleaning buffer for next PDU. */
};

#define STOMP_MIN_PDU_SIZE (sizeof("ACK\n\n\0\n")-1)

/*() Read and parse a frame from STOMP 1.1 connection (from zxbusd).
 * Blocks until frame has been read. Returns 1 on success, 0 on failure.
 * In case of failure, caller should close the connection. The PDU
 * data is left in bu->buf, possibly with the following pdu as well. The
 * caller shouldclean the buffer without loosing the next pdu
 * fragment before calling this function again. For example:
 *   memmove(bu->buf, stomp->end_of_pdu, bu->ap-stomp->end_of_pdu);
 *   bu->ap = bu->buf + (bu->ap-stomp->end_of_pdu);
 *   stomp->end_of_pdu = 0;
 * This is performed automatically if stomp->end_of_pdu is set in
 * the structure that is passed in.
 * The parsed headers are returned in the struct stomp_hdr. */

static int zxbus_read(zxid_conf* cf, struct zxid_bus_url* bu, struct stomp_hdr* stomp)
{
  int len = 0, got;
  char* hdr;
  char* h;
  char* v;
  char* p;

  if (stomp->end_of_pdu) {
    memmove(bu->buf, stomp->end_of_pdu, bu->ap-stomp->end_of_pdu);
    bu->ap = bu->buf + (bu->ap-stomp->end_of_pdu);
  }
  memset(stomp, 0, sizeof(struct stomp_hdr));

  while (bu->ap - bu->buf < ZXBUS_BUF_SIZE) {
    got = recv(bu->fd, bu->ap, ZXBUS_BUF_SIZE - (bu->ap - bu->buf), 0);
    if (got < 0) {
      ERR("recv: %d %s", errno, STRERROR(errno));
      return 0;
    }
    if (!got) {
      D("recv: returned empty, gotten=%d", (bu->ap - bu->buf));
      return 0;
    }
    bu->ap += got;

    for (p = bu->buf; p < bu->ap && ONE_OF_2(*p, '\n', '\r'); ++p) ;
    if (p > bu->buf) {
      /* Wipe out initial newlines */
      memmove(bu->buf, p, bu->ap - p);
      bu->ap -= p - bu->buf;
      p = bu->buf;
    }
    if (bu->ap - p < STOMP_MIN_PDU_SIZE)
      goto read_more;

    /* Extract command (always in beginning of buf) */

    hdr = memchr(p, '\n', bu->ap - p);
    if (!hdr || ++hdr == bu->ap)
      goto read_more;
    p = hdr;

    /* Decode headers
     * 01234 5 6 7
     * STOMP\n\n\0
     *         ^-p
     * 01234 5 6 7 8 9
     * STOMP\r\n\r\n\0
     *           ^-p
     * STOMP\nhost:foo\n\n\0
     *        ^-p        ^-pp
     * STOMP\r\nhost:foo\r\n\r\n\0
     *          ^-p          ^-pp
     * STOMP\nhost:foo\naccept-version:1.1\n\n\0
     *        ^-p       ^-pp                 ^-ppp
     * STOMP\r\nhost:foo\r\naccept-version:1.1\r\n\r\n\0
     *          ^-p         ^-pp                   ^-ppp
     */

    while (!ONE_OF_2(*p,'\n','\r')) { /* Empty line separates headers from body. */
      h = p;
      p = memchr(p, '\n', bu->ap - p);
      if (!p || ++p == bu->ap)
	goto read_more;
      v = memchr(h, ':', p-h);
      if (!v) {
	ERR("Header missing colon. hdr(%*s)", bu->ap-h,h);
	return 0;
      }
#define HDR(hdr, field, val) } else if (!memcmp(h, hdr, sizeof(hdr)-1)) { if (!stomp->field) stomp->field = (val)

      if (!memcmp(p, "content-length:", sizeof("content-length:")-1))
      { if (!stomp->len) stomp->len = len = atoi(v);
      HDR("host:",           host,      v);
      HDR("receipt:",        receipt,   v);
      HDR("receipt-id:",     rcpt_id,   v);
      HDR("version:",        vers,      v);
      HDR("accept-version:", acpt_vers, v);
      HDR("transaction:",    tx_id,     v);
      HDR("login:",          login,     v);
      HDR("passcode:",       pw,        v);
      HDR("session:",        session,   v);
      HDR("id:",             subs_id,   v);
      HDR("subscription:",   subsc,     v);
      HDR("server:",         server,    v);
      HDR("ack:",            ack,       v);
      HDR("message-id:",     msg_id,    v);
      HDR("destination:",    dest,      v);
      HDR("heart-beat:",     heart_bt,  v);
      } else if (!memcmp(p, "content-type:", sizeof("content-type:"))) { /* ignore */
      } else {
        D("Unknown header(%*s) ignored.", h-p, h);
      }
    }
  
    /* Now body */

    if (*p == '\r') ++p;
    stomp->body = ++p;

    if (len) {
      if (len < bu->ap - p) {
        /* Got complete with content-length */
        p += len;
        if (!*p++)
	  goto done;
	ERR("No nul to terminate body. %d",0);
	return 0;
      } else {
	goto read_more;
      }
    } else {
      /* Scan until nul */
      while (1) {
        if (bu->ap - p < 1) {   /* too little, need more */
	  goto read_more;
        }
        if (!*p++) {
	  stomp->len = len = p - stomp->body - 1;
          goto done;
        }
      }
    }
  read_more:
    continue;
  }
  if (bu->ap - bu->buf >= ZXBUS_BUF_SIZE) {
    ERR("PDU does not fit in buffer %d", bu->ap - bu->buf);
    return 0;
  }
 done:
  stomp->end_of_pdu = p;
  return 1;
}

/*() Open a bus_url, i.e. STOMP 1.1 connection to zxbusd.
 * Return 0 on failure, 1 on success. */

static int zxbus_open_bus_url(zxid_conf* cf, struct zxid_bus_url* bu)
{
  struct hostent* he;
  struct sockaddr_in sin;
  struct stomp_hdr stomp;
  int host_len;
  char* proto;
  char* host;
  char* port;
  char* local;
  char* qs;

  /* Parse the bus_url */

  if (!bu || !bu->s || !*bu->s) {
    ERR("Null arguments or empty bus_url supplied %p", bu);
    return 0;
  }
  
  host = strstr(bu->s, "://");
  if (!host) {
    ERR("Malformed bus_url(%s): missing protocol field", bu->s);
    proto = "stomps:";
    host = bu->s;
  } else {
    proto = bu->s;
    host += 3;
  }
  
  if (!memcmp(proto, "stomps:", sizeof("stomps:")-1)) {
    bu->tls = 1;
  } else if (!memcmp(proto, "stomp:", sizeof("stomp:")-1)) {
    bu->tls = 0;
  } else {
    ERR("Unknown protocol(%*s)", 6, proto);
    return 0;
  }
  
  port = strchr(host, ':');
  if (!port) {
    port = bu->tls ? ":2229/" : ":2228/";  /* ZXID default ports for stomps: and plain stomp: */
    local = strchr(host, '/');
    if (!local) {
      qs = strchr(host, '?');
      if (!qs) {
	host_len = strlen(host);
      } else {
	host_len = qs-host;
      }
    } else {
      host_len = local-host;
      qs = strchr(local, '?');
    }
  } else {
    host_len = port-host;
    local = strchr(port, '/');
    if (!local) {
      qs = strchr(port, '?');
    } else {
      qs = strchr(local, '?');
    }
  }

  bu->buf = bu->ap = ZX_ALLOC(cf->ctx, ZXBUS_BUF_SIZE);

  memcpy(bu->buf, host, MIN(host_len, ZXBUS_BUF_SIZE-2));
  bu->buf[MIN(host_len, ZXBUS_BUF_SIZE-2)+1] = 0;
  he = gethostbyname(bu->buf);
  if (!he) {
    ERR("hostname(%s) did not resolve(%d)", bu->buf, h_errno);
    exit(5);
  }
  
  memset(&sin, 0, sizeof(sin));
  sin.sin_family = AF_INET;
  sin.sin_port = htons(atoi(port+1));
  memcpy(&(sin.sin_addr.s_addr), he->h_addr, sizeof(sin.sin_addr.s_addr));
  
  if ((bu->fd = socket(AF_INET, SOCK_STREAM, 0)) == -1) {
    ERR("Unable to create socket(AF_INET, SOCK_STREAM, 0) %d %s", errno, STRERROR(errno));
    return 0;
  }

#if 0
  nonblock(bu->fd);
  if (nkbuf)
    setkernelbufsizes(bu->fd, nkbuf, nkbuf);
#endif

  if ((connect(bu->fd, (struct sockaddr*)&sin, sizeof(sin)) == -1) && (errno != EINPROGRESS)) {
    int myerrno = errno;
    close(bu->fd);
    ERR("Connection to %s failed: %d %s", bu->s, myerrno, STRERROR(myerrno));
    bu->fd = 0;
    return 0;
  }
  
  D("connect(%x) hs(%s)", bu->fd, bu->s);

#define STOMP_CONNECT  "STOMP\naccept-version:1.1\nhost:localhost\n\n\0"
  send_all_socket(bu->fd, STOMP_CONNECT, sizeof(STOMP_CONNECT)-1);

  memset(&stomp, 0, sizeof(struct stomp_hdr));
  if (zxbus_read(cf, bu, &stomp)) {
    if (!memcmp(bu->buf, "CONNECTED", sizeof("CONNECTED")-1)) {
      memmove(bu->buf, stomp.end_of_pdu, bu->ap-stomp.end_of_pdu);
      bu->ap = bu->buf + (bu->ap-stomp.end_of_pdu);
      stomp.end_of_pdu = 0;
      D("STOMP got CONNECTED %d", 0);
      return 1;
    }
  }
  close(bu->fd);
  bu->fd = 0;
  ERR("Connection to %s failed. Other end did not send CONNECTED", bu->s);
  return 0;
}

/*() SEND a STOMP 1.1 DISCONNECT to audit bus and wait for RECEIPT.
 * Returns:: zero on failure and 1 on success. Connection is closed in either case. */

/* Called by: */
int zxbus_close(zxid_conf* cf, struct zxid_bus_url* bu)
{
  int len;
  char buf[1024];
  struct stomp_hdr stomp;
  
  if (!bu || !bu->s || !bu->s[0] || !bu->fd)
    return 0;         /* No bus_url configured means audit bus reporting is disabled. */

  /* *** implement intelligent lbfo algo */
  
  len = snprintf(buf, sizeof(buf), "DISCONNECT\nreceipt:%d\n\n%c", bu->cur_rcpt-1, 0);
  send_all_socket(bu->fd, buf, len);

  memset(&stomp, 0, sizeof(struct stomp_hdr));
  if (zxbus_read(cf, bu, &stomp)) {
    if (!memcmp(bu->buf, "RECEIPT", sizeof("RECEIPT")-1)) {
      if (atoi(stomp.rcpt_id) == bu->cur_rcpt - 1) {
	memmove(bu->buf, stomp.end_of_pdu, bu->ap-stomp.end_of_pdu);
	bu->ap = bu->buf + (bu->ap-stomp.end_of_pdu);
	D("DISCONNECT got RECEIPT %d", bu->cur_rcpt-1);
	close(bu->fd);
	bu->fd = 0;
	return 1;
      } else {
	close(bu->fd);
	bu->fd = 0;
	ERR("DISCONNECT to %s failed. RECEIPT number(%*s)=%d mismatch cur_rcpt-1=%d", bu->s, bu->ap - stomp.rcpt_id, stomp.rcpt_id, atoi(stomp.rcpt_id), bu->cur_rcpt-1);
	return 0;
      }
    } else {
      ERR("DISCONNECT to %s failed. Other end did not send RECEIPT(%*ss)", bu->s, bu->ap - bu->buf, bu->buf);
    }
  } else {
    ERR("DISCONNECT to %s failed. Other end did not send RECEIPT. Read error.", bu->s);
  }
  close(bu->fd);
  bu->fd = 0;
  return 0;
}

/*() SEND a STOMP 1.1 DISCONNECT to audit bus and wait for RECEIPT.
 * Returns:: nothing. Ignores any errors (but errors cause fd to be closed). */

/* Called by: */
void zxbus_close_all(zxid_conf* cf)
{
  struct zxid_bus_url* bu;
  for (bu = cf->bus_url; bu; bu = bu->n)
    zxbus_close(cf, bu);
}

/*() SEND a STOMP 1.1 message to audit bus and wait for RECEIPT.
 * Blocks until the transaction completes (or fails). Figures out
 * from configuration, which bus daemon to contact (looks at bus_urls).
 * Returns:: zero on failure and 1 on success. */

/* Called by: */
int zxbus_send(zxid_conf* cf, int n, const char* logbuf)
{
  int len;
  char buf[1024];
  struct zxid_bus_url* bu;
  struct stomp_hdr stomp;
  
  if (n == -1)
    n = strlen(logbuf);
  DD("LOG(%.*s)", n-1, logbuf);

  bu = cf->bus_url;
  if (!bu || !bu->s || !bu->s[0])
    return 0;         /* No bus_url configured means audit bus reporting is disabled. */

  /* *** implement intelligent lbfo algo */

  if (!bu->fd)
    zxbus_open_bus_url(cf, bu);
  if (!bu->fd)
    return 0;
  
  len = snprintf(buf, sizeof(buf), "SEND\nreceipt:%d\ncontent-length:%d\n\n", bu->cur_rcpt++, n);
  send_all_socket(bu->fd, buf, len);
  send_all_socket(bu->fd, logbuf, n);
  send_all_socket(bu->fd, "\0", 1);

  memset(&stomp, 0, sizeof(struct stomp_hdr));
  if (zxbus_read(cf, bu, &stomp)) {
    if (!memcmp(bu->buf, "RECEIPT", sizeof("RECEIPT")-1)) {
      if (atoi(stomp.rcpt_id) == bu->cur_rcpt - 1) {
	memmove(bu->buf, stomp.end_of_pdu, bu->ap-stomp.end_of_pdu);
	bu->ap = bu->buf + (bu->ap-stomp.end_of_pdu);
	D("SEND got RECEIPT %d", bu->cur_rcpt-1);
	return 1;
      } else {
	close(bu->fd);
	bu->fd = 0;
	ERR("Send to %s failed. RECEIPT number(%*s)=%d mismatch cur_rcpt-1=%d", bu->s, bu->ap - stomp.rcpt_id, stomp.rcpt_id, atoi(stomp.rcpt_id), bu->cur_rcpt-1);
	return 0;
      }
    } else {
      ERR("Send to %s failed. Other end did not send RECEIPT(%*ss)", bu->s, bu->ap - bu->buf, bu->buf);
    }
  } else {
    ERR("Send to %s failed. Other end did not send RECEIPT. Read error.", bu->s);
  }
  close(bu->fd);
  bu->fd = 0;
  return 0;
}

#if 0

/*(i) Log to activity and/or error log depending on ~res~ and configuration settings.
 * This is the main audit logging function you should call. Please see <<link:../../html/zxid-log.html: zxid-log.pd>>
 * for detailed description of the log format and features. See <<link:../../html/zxid-conf.html: zxid-conf.pd>> for
 * configuration options governing the logging. (*** check the links)
 *
 * Proper audit trail is essential for any high value transactions based on SSO. Also
 * some SAML protocol Processing Rules, such as duplicate detection, depend on the
 * logging.
 *
 * cf     (1)::  ZXID configuration object, used for configuration options and memory allocation
 * ourts  (2)::  Timestamp as observed by localhost. Typically the wall clock
 *     time. See gettimeofday(3)
 * srcts  (3)::  Timestamp claimed by the message to which the log entry pertains
 * ipport (4)::  IP address and port number from which the message appears to have originated
 * entid  (5)::  Entity ID to which the message pertains, usually the issuer. Null ok.
 * msgid  (6)::  Message ID, can be used for correlation to establish audit trail continuity
 *     from request to response. Null ok.
 * a7nid  (7)::  Assertion ID, if message contained assertion (outermost and first
 *     assertion if there are multiple relevant assertions). Null ok.
 * nid    (8)::  Name ID pertaining to the message
 * sigval (9)::  Signature validation letters
 * res   (10)::  Result letters
 * op    (11)::  Operation code for the message
 * arg   (12)::  Operation specific argument
 * fmt, ...  ::  Free format message conveying additional information
 * return:: 0 on success, nonzero on failure (often ignored as zxbus() is very
 *     robust and rarely fails - and when it does, situation is so hopeless that
 *     you would not be able to report its failure anyway)
 */

/* Called by:  zxid_an_page_cf, zxid_anoint_sso_a7n, zxid_anoint_sso_resp, zxid_chk_sig, zxid_decode_redir_or_post x2, zxid_fed_mgmt_cf, zxid_get_ent_by_sha1_name, zxid_get_ent_ss, zxid_get_meta x2, zxid_idp_dispatch, zxid_idp_select_zxstr_cf_cgi, zxid_idp_soap_dispatch x2, zxid_idp_soap_parse, zxid_parse_conf_raw, zxid_parse_meta, zxid_saml_ok x2, zxid_simple_render_ses, zxid_simple_ses_active_cf, zxid_sp_anon_finalize, zxid_sp_deref_art x5, zxid_sp_dig_sso_a7n x2, zxid_sp_dispatch, zxid_sp_meta, zxid_sp_mni_redir, zxid_sp_mni_soap, zxid_sp_slo_redir, zxid_sp_slo_soap, zxid_sp_soap_dispatch x2, zxid_sp_soap_parse, zxid_sp_sso_finalize x2, zxid_start_sso_url x3 */
int zxbus(zxid_conf* cf,   /* 1 */
	  struct timeval* ourts,  /* 2 null allowed, will use current time */
	  struct timeval* srcts,  /* 3 null allowed, will use start of unix epoch + 501 usec */
	  const char* ipport,     /* 4 null allowed, -:- or cf->ipport if not given */
	  struct zx_str* entid,   /* 5 null allowed, - if not given */
	  struct zx_str* msgid,   /* 6 null allowed, - if not given */
	  struct zx_str* a7nid,   /* 7 null allowed, - if not given */
	  struct zx_str* nid,     /* 8 null allowed, - if not given */
	  const char* sigval,     /* 9 null allowed, - if not given */
	  const char* res,        /* 10 */
	  const char* op,         /* 11 */
	  const char* arg,        /* 12 null allowed, - if not given */
	  const char* fmt, ...)   /* 13 null allowed as format, ends the line w/o further ado */
{
  int n;
  char logbuf[1024];
  va_list ap;
  
  /* Avoid computation if logging is hopeless. */
  
  if (!((cf->log_err_in_act || res[0] == 'K') && cf->log_act)
      && !(cf->log_err && res[0] != 'K')) {
    return 0;
  }

  va_start(ap, fmt);
  n = zxbus_fmt(cf, sizeof(logbuf), logbuf,
		ourts, srcts, ipport, entid, msgid, a7nid, nid, sigval, res,
		op, arg, fmt, ap);
  va_end(ap);
  return zxbus_output(cf, n, logbuf, res);
}

/*() Log to activity and/or error log depending on ~res~ and configuration settings.
 * This variant uses the ses object to extract many of the log fields. These fields
 * were populated to ses by zxid_wsp_validate()
 */

int zxbuswsp(zxid_conf* cf,    /* 1 */
	     zxid_ses* ses,    /* 2 */
	     const char* res,  /* 3 */
	     const char* op,   /* 4 */
	     const char* arg,  /* 5 null allowed, - if not given */
	     const char* fmt, ...)   /* 13 null allowed as format, ends the line w/o further ado */
{
  int n;
  char logbuf[1024];
  va_list ap;
  
  /* Avoid computation if logging is hopeless. */
  
  if (!((cf->log_err_in_act || res[0] == 'K') && cf->log_act)
      && !(cf->log_err && res[0] != 'K')) {
    return 0;
  }

  va_start(ap, fmt);
  n = zxbus_fmt(cf, sizeof(logbuf), logbuf,
		0, ses?&ses->srcts:0, ses?ses->ipport:0,
		ses?ses->issuer:0, ses?ses->wsp_msgid:0,
		ses&&ses->a7n?&ses->a7n->ID->g:0,
		ses?ZX_GET_CONTENT(ses->nameid):0,
		ses&&ses->sigres?&ses->sigres:"-", res,
		op, arg, fmt, ap);
  va_end(ap);
  return zxbus_output(cf, n, logbuf, res);
}
#endif

/* EOF  --  zxbusprod.c */
