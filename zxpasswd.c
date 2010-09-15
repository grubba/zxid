/* zxpasswd.c  -  Password creation and user management tool
 * Copyright (c) 2009 Sampo Kellomaki (sampo@iki.fi), All Rights Reserved.
 * This is confidential unpublished proprietary source code of the author.
 * NO WARRANTY, not even implied warranties. Contains trade secrets.
 * Distribution prohibited unless authorized in writing.
 * Licensed under Apache License 2.0, see file COPYING.
 * $Id: zxpasswd.c,v 1.6 2010-01-08 02:10:09 sampo Exp $
 *
 * 18.10.2009, created --Sampo
 * 14.11.2009, added yubikey support --Sampo
 *
 * See also: http://www.users.zetnet.co.uk/hopwood/crypto/scan/ph.html
 * http://www.usenix.org/events/usenix99/provos/provos_html/index.html
 * http://www.koders.com/c/fid18C2933FE8729E3DBC6E9B1DEB65D282560D4B14.aspx?s=md5
 * zxid_pw_authn() in zxiduser.c
 * phd/sampo-idp-disco-encfs-kbdtok-2009.pd
 */

#include "platform.h"  /* for dirent.h */

#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <stdint.h>
#include <signal.h>
#include <fcntl.h>

#include "errmac.h"
#include "zx.h"
#include "zxid.h"
#include "zxidconf.h"
#include "c/zxidvers.h"
#include "c/zx-ns.h"
#include "yubikey.h"

#define UDIR "/var/zxid/idpuid"

CU8* help =
"zxpasswd  -  Password creation and user management tool R" ZXID_REL "\n\
Copyright (c) 2009 Sampo Kellomaki (sampo@iki.fi), All Rights Reserved.\n\
NO WARRANTY, not even implied warranties. Licensed under Apache License v2.0\n\
See http://www.apache.org/licenses/LICENSE-2.0\n\
Send well researched bug reports to the author. Home: zxid.org\n\
\n\
Usage: zxpasswd [options] user [udir] <passwd    # Set user's password\n\
       zxpasswd [options] -c user [udir] <passwd # Create user and set password\n\
       zxpasswd [options] -a user [udir] <passwd # Authenticate as user using pw\n\
       zxpasswd [options] -l [user] [udir]       # List information about user\n\
  [udir]           Specify zxididp user directory. Default " UDIR "\n\
  -c               Create user\n\
  -s exist_uid     Symlink user to an existing user (e.g. yubikey alias)\n\
  -a               Authenticate as user. exit(2) value 0 means success\n\
  -l               List user info. If no user is specified, lists all users.\n\
  -t N             Choose password hash type: 0=plain, 1=MD5 (default), y=yubikey\n\
  -v               Verbose messages.\n\
  -q               Be extra quiet.\n\
  -d               Turn on debugging.\n\
  -h               This help message\n\
  --               End of options\n\
\n\
For Yubikey (yubico.com) authentication (-a), supply the yubikey ticket\n\
as user and omit the password. For creating account or changing password,\n\
use -h y to indicate that you pass yubikey AES128 shared key in hex as password.\n";

char zx_instance[64] = "\tzxpw";
int zx_debug = 0;
char zx_indent[256] = "";
int verbose = 1;
int assert_nonfatal = 0;
char* assert_msg = "assert fired.";
int create = 0;
int an = 0;
int list = 0;
char* hash_type = "1";
char* udir = 0;
char* user = 0;
char* symlink_user = 0;
char pw[1024];
char userdir[4096];
char buf[4096];

/* Called by:  main x8, zxcall_main, zxcot_main */
static void opt(int* argc, char*** argv, char*** env)
{
  if (*argc <= 1) {
    fprintf(stderr, "Too few arguments (%d). Must specify at least user name.\n", *argc);
    goto help;
  }
  
  while (1) {
    ++(*argv); --(*argc);
    
    if (!(*argc) || ((*argv)[0][0] != '-')) break;  /* normal exit from options loop */
    
    switch ((*argv)[0][1]) {
    case '-': if ((*argv)[0][2]) break;
      ++(*argv); --(*argc);
      DD("End of options by --");
      goto last;  /* -- ends the options */

    case 'c':
      switch ((*argv)[0][2]) {
      case '\0':
	++create;
	continue;
      }
      break;

    case 'a':
      switch ((*argv)[0][2]) {
      case '\0':
	++an;
	continue;
      }
      break;

    case 'l':
      switch ((*argv)[0][2]) {
      case '\0':
	++list;
	continue;
#if 0
      case 'i':
	if (!strcmp((*argv)[0],"-license")) {
	  extern char* license;
	  fprintf(stderr, license);
	  exit(0);
	}
	break;
#endif
      }
      break;

    case 't':
      switch ((*argv)[0][2]) {
      case '\0':
	++(*argv); --(*argc);
	if ((*argc) < 1) break;
	hash_type = (*argv)[0];
	continue;
      }
      break;

    case 's':
      switch ((*argv)[0][2]) {
      case '\0':
	++(*argv); --(*argc);
	if ((*argc) < 1) break;
	symlink_user = (*argv)[0];
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
    fprintf(stderr, help);
    /*fprintf(stderr, "version=0x%06x rel(%s)\n", zxid_version(), zxid_version_str());*/
    exit(3);
  }
 last:
  if (!*argc) {
    fprintf(stderr, "Too few arguments (%d). Must specify at least user name.\n", *argc);
    goto help;
  }
}

/* Called by:  main */
static int list_user(char* userdir, char* udir)
{
  int got;
  struct dirent* de;
  DIR* dir;

  printf("User dir:              %s\n", userdir);
  got = read_all(sizeof(buf), buf, "pw", "%s/%s/.pw", udir, user);
  printf("Password hash:         %s\n", buf);
  got = read_all(sizeof(buf), buf, "at", "%s/%s/.bs/.at", udir, user);
  printf("User attributes:       %s\n", buf);
  got = read_all(sizeof(buf), buf, "all at", "%s/.all/.bs/.at", udir, 0);
  printf("All user's attributes: %s\n", buf);

  printf("User's Federated SPs\n");

  dir = opendir(userdir);
  if (!dir) {
    perror("opendir for /var/zxid/idpuid/USER userdir (or other if configured)");
    D("failed path(%s)", userdir);
    return 0;
  }
  while (de = readdir(dir))
    if (de->d_name[0] != '.' && de->d_name[strlen(de->d_name)-1] != '~') {
      got = read_all(sizeof(buf), buf, "sp at", "%s/%s/.mni", userdir, de->d_name);
      printf("SP specific NameID:  %s (%s)\n", buf, de->d_name);
      got = read_all(sizeof(buf), buf, "sp at", "%s/%s/.at", userdir, de->d_name);
      printf("SP specific attrib:  %s (%s)\n", buf, de->d_name);
    }

  /* *** TODO: .all SPs, bootstraps, discovery regs */
  
  DD("HERE %p", cf);
  closedir(dir);

  return 0;
}

/* Called by:  main */
static int list_users(char* udir)
{
  int got;
  struct dirent* de;
  DIR* dir;

  dir = opendir(udir);
  if (!dir) {
    perror("opendir for /var/zxid/idpuid (or other if configured)");
    D("failed path(%s)", udir);
    return 0;
  }
  while (de = readdir(dir))
    if (de->d_name[0] != '.' && de->d_name[strlen(de->d_name)-1] != '~') {
      got = read_all(sizeof(buf), buf, "sp at", "%s/%s/.mni", userdir, de->d_name);
      printf("SP specific NameID:  %s (%s)\n", buf, de->d_name);
      got = read_all(sizeof(buf), buf, "sp at", "%s/%s/.at", userdir, de->d_name);
      printf("SP specific attrib:  %s (%s)\n", buf, de->d_name);
    }
  
  closedir(dir);
  return 0;
}

extern char pw_basis_64[64];

/* Called by: */
int main(int argc, char** argv, char** env)
{
  int isyk = 0;
  int got, pwgot;
  unsigned char salt[16];
  unsigned char pw_hash[120];
  unsigned char ch;
  yubikey_token_st yktok;
  
  opt(&argc, &argv, &env);
  if (argc)
    user = argv[0];
  else if (!list) {
    fprintf(stderr, "Too few arguments (%d). Specify at least user name.\n", argc);
    fprintf(stderr, help);
    /*fprintf(stderr, "version=0x%06x rel(%s)\n", zxid_version(), zxid_version_str());*/
    exit(3);
  }

  if (user) {
    udir = argc>1?argv[1]:UDIR;
    snprintf(userdir, sizeof(userdir)-1, "%s/%s", udir, user);
    userdir[sizeof(userdir)-1] = 0;
  }
  if (list) {
    if (user)
      return list_user(userdir, udir);
    else
      return list_users(udir);
  }

  got = strlen(user);
  if (got > 32) {  /* Very long user is actually yubikey ticket */
    strcpy(pw, user + got - 32);
    user[got - 32] = 0;
    pwgot = 32;
    D("yubikey user(%s) ticket(%s)", user, pw);
    isyk = 1;
  } else {
    read_all_fd(0, pw, sizeof(pw)-1, &pwgot);  /* Password from stdin */
  }
  if (pwgot) {
    if (pw[pwgot-1] == '\015') --pwgot;
    if (pw[pwgot-1] == '\012') --pwgot;
  }
  pw[pwgot] = 0;
  D("pw(%s) len=%d", pw, pwgot);

  if (an) {
    /* See also: zxid_pw_authn() in zxiduser.c */

    if (isyk) {
      snprintf(userdir, sizeof(userdir)-1, "%s/%s", udir, user);
      userdir[sizeof(userdir)-1] = 0;
      got = read_all(sizeof(buf), buf, "ykspent", "%s/.ykspent/%s", userdir, pw);
      if (got) {
	ERR("The One Time Password has already been spent. ticket(%s%s) buf(%.*s)", user, pw, got, buf);
	return 1;
      }
      if (!write_all_path_fmt("ykspent", sizeof(buf), buf, "%s/.ykspent/%s", userdir, pw, "1"))
	return 1;

      got = read_all(sizeof(buf), buf, "ykaes", "%s/%s/.yk", udir, user);
      D("buf    (%s) got=%d", buf, got);
      if (got < 32) {
	ERR("User's %s/.yk file must contain aes128 key as 32 hexadecimal characters. Too few characters %d ticket(%s)", user, got, pw);
	return 1;
      }
      if (got > 32) {
	INFO("User's %s/.yk file must contain aes128 key as 32 hexadecimal characters. Too many characters %d ticket(%s). Truncating.", user, got, pw);
	got = 32;
	buf[got] = 0;
      }
      zx_hexdec(buf, buf, got, hex_trans);
      memset (&yktok, 0, sizeof(yktok));
      zx_hexdec((void *)&yktok, pw, pwgot, ykmodhex_trans);
      yubikey_aes_decrypt((void *)&yktok, buf);
      D("internal uid %02x %02x %02x %02x %02x %02x counter=%d 0x%x timestamp=%d (hi=%x lo=%x) use=%d 0x%x rnd=0x%x crc=0x%x", yktok.uid[0], yktok.uid[1], yktok.uid[2], yktok.uid[3], yktok.uid[4], yktok.uid[5], yktok.ctr, yktok.ctr, (yktok.tstph << 16) | yktok.tstpl, yktok.tstph, yktok.tstpl, yktok.use, yktok.use, yktok.rnd, yktok.crc);
            
      if (yubikey_crc_ok_p((unsigned char*)&yktok)) {
	D("yubikey ticket validates ok %d", 0);
	return 0;
      }
      D("yubikey ticket validation failure %d", 0);
      return 1;
    }
    got = read_all(sizeof(buf), buf, "pw", "%s/%s/.pw", udir, user);
    D("buf    (%s)", buf);
    if (!memcmp(buf, "$1$", sizeof("$1$")-1)) {
      zx_md5_crypt(pw, buf, pw_hash);
      D("pw_hash(%s)", pw_hash);
      return strcmp(buf, pw_hash)?1:0;
    }
    if (ONE_OF_2(buf[0], '$', '_')) {
      fprintf(stderr, "Unsupported password hash algorithm (%s).\n", buf);
      return 1;
    }
    D("Assume plain text password %d", 0);
    return strcmp(buf, pw)?1:0;
  }
  
  if (create) {
    MKDIR(userdir, 0770);
  }
  if (symlink_user) {
    snprintf(buf, sizeof(buf), "%s/%s", udir, symlink_user);
    buf[sizeof(buf)-1] = 0; /* must terminate manually as on win32 nul is not guaranteed */
#ifdef MINGW
    ERR("Symlink not implemented on Win32. from(%s) (-s %s) path(%s)", buf, symlink_user, userdir);
#else
    D("Symlink from(%s) (-s %s) path(%s)", buf, symlink_user, userdir);
    if (symlink(buf, userdir) == -1) {
      perror("symlink user alias");
      return 2;
    }
#endif
  }
  
  /* $1$$6C2jXXYmjnyAkfWXmnCSf0 */
  /* $y$$6012cab434c66ab87d43d4babe463331 */

  if (!strcmp(hash_type, "0")) {
    strcpy(pw_hash, pw);
  } else if (!strcmp(hash_type, "1")) {
    for (got = 0; got < 8; ++got) {
      zx_rand(&ch, 1);
      salt[got] = pw_basis_64[ch & 0x3f];
    }
    salt[8] = 0;
    D("salt(%s)", salt);
    zx_md5_crypt(pw, salt, pw_hash);
    D("pw_hash(%s)", pw_hash);
  } else if (!strcmp(hash_type, "y")) {
    D("Provisioning yubikey aes(%s) in %s/%s/.yk", pw, udir, user);
    if (!write_all_path_fmt("set yk", sizeof(buf), buf, "%s/%s/.yk", udir, user, "%s", pw))
      return 1;
    snprintf(userdir, sizeof(userdir)-1, "%s/%s/.ykspent", udir, user);
    userdir[sizeof(userdir)-1] = 0;
    MKDIR(userdir, 0770);
    return 0;
  } else {
    fprintf(stderr, "Unsupported password hash algorithm (%s).\n", hash_type);
  }
  
  if (!write_all_path_fmt("set pw", sizeof(buf), buf, "%s/%s/.pw", udir, user, "%s", pw_hash))
    return 1;
  return 0;
}

/* EOF  --  zxdecode.c */

#if 0

Personalizing yubikeys 2009: get and compile libyubikey-1.5 and ykpers-1.0

ykpersonalize -y -v -ofixed=refucenikj -a6012cad434c66ab87d43d4babe463231
ykdebug 6012cad434c66ab87d43d4babe463231 refucenikjdbrgulutnjhurchlkcckdkergfitcebf

Here -ofixed specifies the "username" for purposes of /var/zxid/idpuid and
-a specifies the AES128 key that will be put in .pw file as follows:

#endif
