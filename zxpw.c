/* zxpw.c  -  Password authentication
 * Copyright (c) 2012 Synergetics NV (sampo@synergetics.be), All Rights Reserved.
 * Copyright (c) 2009-2010 Sampo Kellomaki (sampo@iki.fi), All Rights Reserved.
 * Copyright (c) 2007-2009 Symlabs (symlabs@symlabs.com), All Rights Reserved.
 * Author: Sampo Kellomaki (sampo@iki.fi)
 * This is confidential unpublished proprietary source code of the author.
 * NO WARRANTY, not even implied warranties. Contains trade secrets.
 * Distribution prohibited unless authorized in writing.
 * Licensed under Apache License 2.0, see file COPYING.
 * $Id: zxiduser.c,v 1.18 2009-11-29 12:23:06 sampo Exp $
 *
 * 12.10.2007, created --Sampo
 * 7.10.2008,  added documentation --Sampo
 * 14.11.2009, added yubikey (yubico.com) support --Sampo
 * 23.9.2010,  added delegation support --Sampo
 * 1.9.2012,   distilled the authentication backend from zxiduser.c to its own module --Sampo
 */

#include "platform.h"  /* for dirent.h */

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>
#include <stdio.h>
#include <errno.h>

#ifdef USE_OPENSSL
#include <openssl/des.h>
#endif

#include "errmac.h"
#include "zxid.h"
#include "zxidutil.h"
#include "zxidconf.h"
#include "yubikey.h"   /* from libyubikey-1.5 */

/*() Low level Yubikey one time password token (usbkey) authentication.
 * The yubikey system requires that spent OTPs are remembered to prevent
 * replay attack. We do this by keeping per user /PATH/uid/UID/.ykspent/
 * directory: if the key is already in this directory, then fail.
 * See: yubico.com
 * return:: 0 on failure, 1 on success  */

/* Called by:  zx_pw_authn */
int zx_yubikey_authn(const char* path, char* uid, const char* passw)
{
  unsigned char buf[256];
  unsigned char pw_buf[256];
  unsigned char pw_hash[120];
  yubikey_token_st yktok;
  int len = strlen(uid);

  strcpy((char*)pw_hash, uid + len - 32);
  uid[len - 32] = 0;
  D("yubikey user(%s) ticket(%s)", uid, pw_hash);
  
  snprintf((char*)buf, sizeof(buf)-1, "%s" ZXID_UID_DIR "%s", path, uid);
  buf[sizeof(buf)-1] = 0;
  len = read_all(sizeof(pw_buf), (char*)pw_buf, "ykspent", 1, "%s/.ykspent/%s", buf, pw_hash);
  if (len) {
    ERR("The One Time Password has already been spent. ticket(%s%s) buf(%.*s)", uid, pw_hash, len, pw_buf);
    return 0;
  }
  if (!write_all_path_fmt("ykspent", sizeof(pw_buf), (char*)pw_buf, "%s/.ykspent/%s", (char*)buf, (char*)pw_hash, "1"))
    return 0;
  
  len = read_all(sizeof(pw_buf), (char*)pw_buf, "ykaes", 1, "%s/.yk", buf);
  D("buf    (%s) got=%d", pw_buf, len);
  if (len < 32) {
    ERR("User's %s/.yk file must contain aes128 key as 32 hexadecimal characters. Too few characters %d ticket(%s)", uid, len, pw_hash);
    return 0;
  }
  if (len > 32) {
    INFO("User's %s/.yk file must contain aes128 key as 32 hexadecimal characters. Too many characters %d ticket(%s). Truncating.", uid, len, pw_hash);
    len = 32;
    pw_buf[len] = 0;
  }
  zx_hexdec((char*)pw_buf, (char*)pw_buf, len, hex_trans);
  ZERO (&yktok, sizeof(yktok));
  zx_hexdec((void*)&yktok, (char*)pw_hash, 32, ykmodhex_trans);
  yubikey_aes_decrypt((void*)&yktok, pw_buf);
  D("internal uid %02x %02x %02x %02x %02x %02x counter=%d 0x%x timestamp=%d (hi=%x lo=%x) use=%d 0x%x rnd=0x%x crc=0x%x", yktok.uid[0], yktok.uid[1], yktok.uid[2], yktok.uid[3], yktok.uid[4], yktok.uid[5], yktok.ctr, yktok.ctr, (yktok.tstph << 16) | yktok.tstpl, yktok.tstph, yktok.tstpl, yktok.use, yktok.use, yktok.rnd, yktok.crc);
  
  if (!yubikey_crc_ok_p((unsigned char*)&yktok)) {
    ERR("yubikey ticket validation failure %d", 0);
    return 0;
  }
  return 1;
}

/*() Low level password check using various different types of hash
 * return:: 0 on failure, 1 on success  */

/* Called by:  zx_pw_authn */
static int zx_pw_chk(const char* uid, const char* pw_buf, const char* passw, int fd_hint)
{
  unsigned char pw_hash[120];
  
  /* *** Add here support for other authentication backends */
  
  DD("io(%x) pw_buf (%s) len=%d", fd_hint, pw_buf, strlen(pw_buf));
  
  if (!memcmp(pw_buf, "$1$", sizeof("$1$")-1)) {
    zx_md5_crypt(passw, (char*)pw_buf, (char*)pw_hash);
    D("io(%x) pw_hash(%s)", fd_hint, pw_hash);
    if (strcmp((char*)pw_buf, (char*)pw_hash)) {
      ERR("Bad password. uid(%s)", uid);
      D("md5 pw(%s) .pw(%s) pw_hash(%s)", passw, pw_buf, pw_hash);
      return 0;
    }
#ifdef USE_OPENSSL
  } else if (!memcmp(pw_buf, "$c$", sizeof("$c$")-1)) {
    DES_fcrypt(passw, (char*)pw_buf+3, (char*)pw_hash);
    D("io(%x) pw_hash(%s)", fd_hint, pw_hash);
    if (strcmp((char*)pw_buf+3, (char*)pw_hash)) {
      ERR("Bad password for uid(%s)", uid);
      D("crypt pw(%s) .pw(%s) pw_hash(%s)", passw, pw_buf, pw_hash);
      return 0;
    }
#endif
  } else if (ONE_OF_2(pw_buf[0], '$', '_')) {
    ERR("Unsupported password hash. uid(%s)", uid);
    D("io(%x) pw(%s) .pw(%s)", fd_hint, passw, pw_buf);
    return 0;
  } else {
    if (strcmp((char*)pw_buf, passw)) {
      ERR("Bad password. uid(%s)", uid);
      D("io(%x) pw(%s) .pw(%s)", fd_hint, passw, pw_buf);
      return 0;
    }
  }
  INFO("Login(%x) OK acnt(%s)", fd_hint, uid);
  return 1;
}

/*() Authenticate user using password like mechanism
 * Expects to get username and password in cgi->au and cgi->ap
 * respectively. User authetication is done against local database or
 * by default using /var/zxid/uid/uid/.pw file. When filesystem
 * backend is used, for safety reasons the uid (user) component can
 * not have certain characters, such as slash (/) or sequences like "..".
 * See also: zxpasswd.c
 *
 * return:: 0 on failure, 1 on success  */

/* Called by:  zxbus_pw_authn_ent, zxid_pw_authn */
int zx_pw_authn(const char* path, char* uid, const char* passw, int fd_hint)
{
  char pw_buf[256];
  int len;

  if (!uid || !uid[0]) {
    ERR("No uid (user's login name) supplied. %p", uid);
    D("io(%x) no user name pw(%s)", fd_hint, STRNULLCHK(passw));
    return 0;
  }

  /* Check for filesystem unsafe characters. (*** Is this list complete?) */
  if (strstr(uid, "..") || strchr(uid, '/')
      || strchr(uid, '\\') || strchr(uid, '~')) {
    ERR("uid(%s) is not filesystem safe", uid);
    D("io(%x) pw(%s)", fd_hint, STRNULLCHK(passw));
    return 0;
  }

  len = strlen(uid);
  if (len > 32)
    return zx_yubikey_authn(path, uid, passw);
  
  if (!passw || !passw[0]) {
    ERR("No password supplied. uid(%s)", uid);
    return 0;
  }
  
  len = read_all(sizeof(pw_buf), pw_buf, "pw_authn", 1, "%s" ZXID_UID_DIR "%s/.pw", path, uid);
  if (len < 1) {
    ERR("No account found for uid(%s) or account does not have .pw file.", uid);
    D("io(%x) pw(%s)", fd_hint, passw);
    return 0;
  }
    
  if (len) {
    if (pw_buf[len-1] == '\012') --len;
    if (pw_buf[len-1] == '\015') --len;
  }
  pw_buf[len] = 0;
  return zx_pw_chk(uid, pw_buf, passw, fd_hint);
}

/* EOF  --  zxpw.c */
