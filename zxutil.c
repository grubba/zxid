/* zxutil.c  -  Utility functions
 * Copyright (c) 2010 Sampo Kellomaki (sampo@iki.fi), All Rights Reserved.
 * Copyright (c) 2006-2008 Symlabs (symlabs@symlabs.com), All Rights Reserved.
 * Author: Sampo Kellomaki (sampo@iki.fi)
 * This is confidential unpublished proprietary source code of the author.
 * NO WARRANTY, not even implied warranties. Contains trade secrets.
 * Distribution prohibited unless authorized in writing.
 * Licensed under Apache License 2.0, see file COPYING.
 * $Id: zxutil.c,v 1.53 2009-11-29 12:23:06 sampo Exp $
 *
 * 15.4.2006, created over Easter holiday --Sampo
 * 7.10.2008, added documentation --Sampo
 * 21.5.2010, added file copy --Sampo
 */

#include "errmac.h"

#include <stdarg.h>
#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <fcntl.h>
#include <unistd.h>
#include <errno.h>
#include <time.h>
#include <openssl/sha.h>
#include <zlib.h>

#ifdef MINGW
#include <windows.h>
#define fdtype HANDLE
#else
#define fdtype int
#endif

#include "zx.h"
#include "zxidconf.h"
#include "platform.h"

#if !defined(USE_STDIO) && !defined(MINGW)
/* *** Static initialization of struct flock is suspect since man fcntl() documentation
 * does not guarantee ordering of the fields, or that they would be the first fields.
 * On Linux-2.4 and 2.6 as well as Solaris-8 the ordering is as follows, but this needs
 * to be checked on other platforms.
 *                       l_type,  l_whence, l_start, l_len */
struct flock ds_rdlk = { F_RDLCK, SEEK_SET, 0, 0 };
struct flock ds_wrlk = { F_WRLCK, SEEK_SET, 0, 0 };
struct flock ds_unlk = { F_UNLCK, SEEK_SET, 0, 0 };
#endif

int close_file(fdtype fd, const char* logkey);

/*() Generate formatted file name path. */

/* Called by:  name_from_path, vopen_fd_from_path */
int vname_from_path(char* buf, int buf_len, const char* name_fmt, va_list ap)
{
  int len = vsnprintf(buf, buf_len, name_fmt, ap);
  buf[buf_len-1] = 0; /* must terminate manually as on win32 nul is not guaranteed */
  if (len < 0) {
    perror("vsnprintf");
    D("Broken vsnprintf? Impossible to compute length of string. Be sure to `export LANG=C' if you get errors about multibyte characters. Length returned: %d", len);
    return 0;
  }
  return 1;
#if 0
 too_long:
  ERR("Path too long base(%s) dir(%s) name(%s)\n", base, dir, name);
  return 0;
#endif
}

/*() Generate formatted file name path. */

/* Called by:  main, zxid_check_fed x3, zxid_del_ses x3, zxid_di_query, zxid_find_epr, zxid_find_ses, zxid_gen_boots, zxid_idp_as_do x2, zxid_mk_transient_nid x2, zxid_mk_user_a7n_to_sp x2, zxid_put_ses, zxid_put_user */
int name_from_path(char* buf, int buf_len, const char* name_fmt, ...)
{
  int ret;
  va_list ap;
  va_start(ap, name_fmt);
  ret = vname_from_path(buf, buf_len, name_fmt, ap);
  va_end(ap);
  return ret;
}

/*() Open a file with formatted file name path. */

/* Called by:  open_fd_from_path, read_all */
fdtype vopen_fd_from_path(int flags, int mode, const char* logkey, const char* name_fmt, va_list ap)
{
  fdtype fd;
  char buf[ZXID_MAX_BUF];
  if (!vname_from_path(buf, sizeof(buf), name_fmt, ap))
    return BADFD;
#ifdef MINGW
  if (flags == O_RDONLY) {
    fd = openfile_ro(buf);
  } else {
    fd = CreateFile(buf, MINGW_RW_PERM, FILE_SHARE_READ | FILE_SHARE_WRITE, 0, OPEN_ALWAYS, FILE_ATTRIBUTE_NORMAL, 0);
  }
#else
  fd = open(buf, flags, mode);
#endif
  if (fd == BADFD) {
    if (logkey[0] != '-') {
      perror("open (vopen_fd_from_path)");
      ERR("File(%s) not found lk(%s) errno=%d err(%s). flags=0x%x, euid=%d egid=%d", buf, logkey, errno, STRERROR(errno), flags, geteuid(), getegid());
    }
    return BADFD;
  }
  return fd;
}

/*() Open a file with formatted file name path. */

/* Called by:  main x2, write_all_path_fmt, zxid_addmd, zxid_cache_epr, zxid_get_ent_from_file, zxid_get_meta, zxid_reg_svc x2, zxid_write_ent_to_cache */
fdtype open_fd_from_path(int flags, int mode, const char* logkey, const char* name_fmt, ...)
{
  va_list ap;
  fdtype fd;
  va_start(ap, name_fmt);
  fd = vopen_fd_from_path(flags, mode, logkey, name_fmt, ap);
  va_end(ap);
  return fd;
}

/*() Low level function that keeps on sucking from a file descriptor until
 * want is satisfied or error happens. May block (though usually will not if
 * the file is in cache or local disk) in process. Buffer p must have been allocated.
 * Return value reflects last got, i.e. what last read(2) system call returned.
 * got_all reflects the total number of bytes received. */

/* Called by:  main x10, opt x5, read_all, test_ibm_cert_problem, zxcall_main, zxid_addmd, zxid_get_ent_from_file x2, zxid_reg_svc, zxid_simple_cf_ses, zxidwspcgi_main, zxidwspcgi_parent */
int read_all_fd(fdtype fd, char* p, int want, int* got_all)
{
#ifdef USE_STDIO
  int got;
  got = fread(p, 1, want, (FILE*)fd);
  if (got_all) *got_all = got;
#elif defined(MINGW)
  DWORD got;
  if (!ReadFile(fd, p, want, &got, 0))
    return -1;
  if (got_all) *got_all = got;
#else  /* The Unix way */
  int got = 0;
  if (got_all) *got_all = 0;
  while (want) {
    got = read(fd, p, want);
    if (got <= 0) break;  /* EOF, possibly premature */
    if (got_all)
      *got_all += got;
    p += got;
    want -= got;
  }
#endif
  return got;   /* N.B. This is the last got, not the total. Use got_all for total. */
}

/*() Read all data from a file at formatted file name path.
 *
 * maxlen:: Length of buffer
 * buf:: Result parameter. This buffer will be populated with data from the file.
 * return:: actual total length. The buffer will always be nul terminated. */

/* Called by:  list_user x5, list_users x2, main x4, opt x10, test_mode x2, zxid_check_fed, zxid_conf_to_cf_len, zxid_di_query x2, zxid_find_epr x2, zxid_gen_boots, zxid_get_ses, zxid_get_ses_sso_a7n, zxid_get_user_nameid, zxid_lscot_line, zxid_mk_user_a7n_to_sp x4, zxid_parse_conf_raw, zxid_pw_authn x3, zxid_read_cert, zxid_read_private_key, zxid_ses_to_pool x3, zxid_sha1_file, zxid_template_page_cf, zxlog_write_line */
int read_all(int maxlen, char* buf, const char* logkey, const char* name_fmt, ...)
{
  va_list ap;
  int gotall;
  fdtype fd;
  va_start(ap, name_fmt);
  fd = vopen_fd_from_path(O_RDONLY, 0, logkey, name_fmt, ap);
  va_end(ap);
  if (fd == BADFD) { if (buf) buf[0] = 0; return 0; }
  if (read_all_fd(fd, buf, maxlen, &gotall) == -1) {
    perror("Trouble reading.");
    D("read error lk(%s)", logkey);
    close_file(fd, logkey);
    buf[maxlen-1] = 0;
    return 0;
  }
  close_file(fd, logkey);
  buf[MIN(gotall, maxlen-1)] = 0;  /* nul terminate */
  return gotall;
}

/*() Low level function that keeps writing data to a file descriptor unil
 * everything is written. It may block in the process. */

/* Called by:  main x4, write2_or_append_lock_c_path x4, write_all_path_fmt, zxid_addmd x2, zxid_cache_epr, zxid_curl_write_data, zxid_reg_svc x3, zxid_send_sp_meta x2, zxid_snarf_eprs_from_ses, zxid_write_ent_to_cache, zxidwspcgi_child */
int write_all_fd(fdtype fd, const char* p, int pending)
{
#ifdef MINGW
  DWORD wrote;
  if (fd == BADFD || !pending || !p) return 0;  
  if (!WriteFile(fd, p, pending, &wrote, 0))
    return 0;
  FlushFileBuffers(fd);
  DD("write_all_fd(%x, `%.*s', %d) wrote=%d\n", fd, pending, p, pending, wrote);
#else
  int wrote;
  if ((fd == BADFD) || !pending || !p) return 0;
  while (pending) {
    wrote = write(fd, p, pending);
    if (wrote <= 0) return 0;
    pending -= wrote;
    p += wrote;
  }
#endif
  return 1;
}

/*() Write all data to a file at the formatted path. The buf is used for formatting
 * data. The path_fmt can have up to two %s specifiers, which will be satisfied
 * by prepath and postpath. Return 1 on success, 0 on fail. */

/* Called by:  main x5, zxid_check_fed x2, zxid_mk_self_sig_cert x2, zxid_mk_transient_nid, zxid_put_ses, zxid_put_user, zxid_pw_authn, zxlog_write_line */
int write_all_path_fmt(const char* logkey, int len, char* buf, const char* path_fmt, const char* prepath, const char* postpath, const char* data_fmt, ...)
{
  va_list ap;
  fdtype fd;
  fd = open_fd_from_path(O_CREAT | O_WRONLY | O_TRUNC, 0666, logkey, path_fmt, prepath, postpath);
  DD("write_all_path_fmt(%s, %x)", logkey, fd);
  if (fd == BADFD) return 0;
  
  va_start(ap, data_fmt);
  len = vsnprintf(buf, len, data_fmt, ap);
  buf[len-1] = 0; /* must terminate manually as on win32 nul is not guaranteed */
  va_end(ap);
  if (len < 0) {
    perror("vsnprintf");
    D("%s, Broken snprintf? Impossible to compute length of string. Be sure to `export LANG=C' if you get errors about multibyte characters. Length returned: %d", logkey, len);
    len = 0;
  }
  if (write_all_fd(fd, buf, len) == -1) {
    perror("Trouble writing");
    close_file(fd, logkey);
    return 0;
  }
  close_file(fd, logkey);
  return 1;
}

/*() Write or append all data to a file at the formatted path. The file
 * is opened for appending, data written, and file closed (flushing the data).
 * Will perform file locking to ensure consistent results. Will create the
 * file if needed, but will not create parent directories. Returns 1 on success, 0 on err */

/* Called by:  zxlog_blob, zxlog_write_line x2 */
int write2_or_append_lock_c_path(const char* c_path,
				 int len1, const char* data1,
				 int len2, const char* data2,
				 const char* which,  /* log key */
				 int seeky,   /* SEEK_END, O_APPEND == append */
				 int flag)    /* SEEK_SET, O_TRUNC  == overwrite */
{
  fdtype fd;
  if (!c_path)
    return 0;
#ifdef MINGW
  fd = CreateFile(c_path, MINGW_RW_PERM, /*0*/FILE_SHARE_READ | FILE_SHARE_WRITE /* 0  means no sharing allowed */, 0 /* security */,
		  (flag == O_APPEND) ? OPEN_ALWAYS : CREATE_ALWAYS /* truncates, too? */,
		  FILE_ATTRIBUTE_NORMAL, 0);
  if (fd == BADFD) goto badopen;
  if (flag == O_APPEND) {
    MS_LONG zero = 0;
    SetFilePointer(fd, 0, &zero, FILE_END);  /* seek to end */
  }

  if (len1 && data1) {
    if (!write_all_fd(fd, data1, len1)) {
      ERR("%s: Writing to file `%s' %d bytes failed: %d %s. Check permissions and disk space. euid=%d egid=%d", which, c_path, len1, errno, STRERROR(errno), geteuid(), getegid());
      close_file(fd, which);
      return 0;
    }
  }
  if (len2 && data2) {
    if (!write_all_fd(fd, data2, len2)) {
      ERR("%s: Writing to file `%s' %d bytes failed: %d %s. Check permissions and disk space. euid=%d egid=%d", which, c_path, len2, errno, STRERROR(errno), geteuid(), getegid());
      close_file(fd, which);
      return 0;
    }
  }
#else
  fd = open(c_path, O_WRONLY | O_CREAT | flag, 0666);
  if (fd == BADFD) goto badopen;
  if (FLOCKEX(fd)  == -1) {
    ERR("%s: Locking exclusively file `%s' failed: %d %s. Check permissions and that the file system supports locking. euid=%d egid=%d", which, c_path, errno, STRERROR(errno), geteuid(), getegid());
    close_file(fd, which);
    return 0;
  }
  
  lseek(fd,0,seeky);
  if (len1 && data1) {
    if (!write_all_fd(fd, data1, len1)) {
      ERR("%s: Writing to file(%s) fd=%d %d bytes failed: %d %s. Check permissions and disk space. euid=%d egid=%d", which, c_path, fd, len1, errno, STRERROR(errno), geteuid(), getegid());
      FUNLOCK(fd);
      close_file(fd, which);
      return 0;
    }
  }

  if (len2 && data2) {
    if (!write_all_fd(fd, data2, len2)) {
      ERR("%s: Writing to file(%s) %d bytes failed: %d %s. Check permissions and disk space. euid=%d egid=%d", which, c_path, len2, errno, STRERROR(errno), geteuid(), getegid());
      FUNLOCK(fd);
      close_file(fd, which);
      return 0;
    }
  }
  
  FUNLOCK(fd);
#endif
  if (close_file(fd, which) < 0) {
    ERR("%s: closing file(%s) after write failed: %d %s. Check permissions and disk space. Could be NFS problem. euid=%d egid=%d", which, c_path, errno, STRERROR(errno), geteuid(), getegid());
    return 0;
  }
  return 1;
badopen:
  ERR("%s: Opening file(%s) for writing failed: %d %s. Check permissions and that directories exist. euid=%d egid=%d", which, c_path, errno, STRERROR(errno), geteuid(), getegid());
  return 0;
}

/*() Close a file rather than just any file descriptor and check error
 * return. It is important that it is a file since on MS Windows closing
 * files is different from closing descriptors. Checking error return
 * from close is important because in NFS environments you may not know
 * that your write has failed until you actually attempt to close the file. */

/* Called by:  copy_file, main x2, read_all x2, write2_or_append_lock_c_path x6, write_all_path_fmt x2, zxid_addmd, zxid_cache_epr, zxid_get_ent_from_file x3, zxid_reg_svc x2, zxid_write_ent_to_cache */
int close_file(fdtype fd, const char* logkey)
{
  int res = closefile(fd);
  if (res) {
    perror("close file");
    ERR("%s: Errors on closing file, after write, could indicate write back cache problems, especially under NFS. Ignoring the error.  euid=%d egid=%d", logkey, geteuid(), getegid());
  }
  return res;
}

/*() Copy contents of a file, i.e. first read a file, then write a file.
 * Many places use copy_file() as opposed to hardlinking file because
 * actually copying file is more portable. Even in Unix, hardlinking
 * can be troublesome if the from and to are on different file systems. */

/* Called by:  zxid_copy_user_eprs_to_ses */
int copy_file(const char* from, const char* to, const char* logkey, int may_link)
{
  fdtype fd_from;
  fdtype fd_to;
  int ret, pending, wrote;
  char buf[4096];
  char* p;

#ifndef MINGW
  switch (may_link) {
  case 2:
    ret = symlink(from, to);
    goto linkrest;
  case 1:
    ret = link(from, to);
linkrest:
    if (ret) {
      perror("{hard|sym}link");
      ERR("%s: Error linking(%d) from(%s) to(%s) euid=%d egid=%d", logkey, may_link, from, to, geteuid(), getegid());
      return -1;
    }
    return 0;
  }
#endif
  fd_from = openfile_ro(from);
  if (fd_from == BADFD) {
      perror("openfile_ro");
      ERR("%s: Error opening from(%s) euid=%d egid=%d", logkey, from, geteuid(), getegid());
      return BADFD;

  }
#ifdef MINGW
  fd_to = CreateFile(buf, MINGW_RW_PERM, FILE_SHARE_READ | FILE_SHARE_WRITE, 0, OPEN_ALWAYS, FILE_ATTRIBUTE_NORMAL, 0);
#else
  fd_to = open(buf, O_WRONLY | O_CREAT, 0666);
#endif
  if (fd_to == BADFD) {
      perror("openfile_ro");
      ERR("%s: Error opening from(%s) euid=%d egid=%d", logkey, from, geteuid(), getegid());
      return BADFD;
  }

#ifdef USE_STDIO
  while (1) {
    pending = fread(buf, 1, sizeof(buf), (FILE*)fd_from);
    if (pending <= 0) break; /* EOF */
    p = buf;
    while (pending) {
      wrote = fwrite(p, 1, pending, fd_to);
      if (wrote <= 0) return 0;
      pending -= wrote;
      p += wrote;
    }
  }
#elif defined(MINGW)
  while (1) {
    DWORD wrot;
    DWORD pend;
    if (!ReadFile(fd_from, buf, sizeof(buf), &pend, 0))
      return -1;
    if (!pend)
      break;
    p = buf;
    while (pend) {
      if (!WriteFile(fd_to, p, pend, &wrot, 0))
	return BADFD;
      pend -= wrot;
      p += wrot;
    }
  }
  FlushFileBuffers(fd_to);
#else
  while (1) {
    pending = read(fd_from, buf, sizeof(buf));
    if (!pending) break; /* EOF */
    p = buf;
    while (pending) {
      wrote = write(fd_to, p, pending);
      if (wrote <= 0) return 0;
      pending -= wrote;
      p += wrote;
    }
  }
#endif

  close_file(fd_to, logkey);
  closefile(fd_from);
  return 0;
}

/*() Output a hexdump to stderr. Used for debugging purposes. */

/* Called by:  hexdmp, zxsig_data_rsa_sha1 x2, zxsig_verify_data_rsa_sha1 x4 */
int hexdump(char* msg, char* p, char* lim, int max)
{
  int i;
  char* lim16;
  char buf[3*16+1+1+16+1];
  if (!msg)
    msg = "";
  if (lim-p > max)
    lim = p + max;
  
  buf[sizeof(buf)-1] = '\0';
  
  while (p<lim) {
    memset(buf, ' ', sizeof(buf)-1);
    lim16 = MIN(p+16, lim);
    for (i = 0; p<lim16; ++p, ++i) {
      buf[3*i+(i>7?1:0)]   = HEX_DIGIT((*p >> 4) & 0x0f);
      buf[3*i+1+(i>7?1:0)] = HEX_DIGIT(*p & 0x0f);
      switch (*p) {
      case '\0': buf[3*16+1+1+i] = '~'; break;
      case '\r': buf[3*16+1+1+i] = '['; break;
      case '\n': buf[3*16+1+1+i] = ']'; break;
      case '~':  buf[3*16+1+1+i] = '^'; break;
      case '[':  buf[3*16+1+1+i] = '^'; break;
      case ']':  buf[3*16+1+1+i] = '^'; break;
      default:
	buf[3*16+1+1+i] = *p < ' ' ? '^' : *p;
      }
    }
    fprintf(stderr, "%s%s\n", msg, buf);
  }
  return 0;
}

/* Called by:  zxsig_validate x5 */
int hexdmp(char* msg, char* p, int len, int max) {
  return hexdump(msg, p, p+len, max);
}

/*
 *  Base 64 encoding and decoding in its canonical and URL safe forms.
 */

/* Base64 std, RFC3548, defines also safe base64, the form that does not need URL encoding
 * and is also otherwise more filesystem safe (i.e. / is not used). The pw_basis
 * is used by md5_crypt() and other password hashing schemes. */

#define MAX_LINE  76 /* size of encoded lines */
char std_basis_64[64]  = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/"; /*=*/
char safe_basis_64[64] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789-_"; /*=*/
char pw_basis_64[64]   = "./0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";

/*() Raw version. Can use any encoding table and arbitrary line length.
 * Known bug: line_len is not fully respected on last line - it can
 * be up to 3 characters longer than specified due to padding.
 * Every three chars (from alphabet of 256) of input map to
 * four chars (from alphabet of 64) of output. See also SIMPLE_BASE64_LEN().
 *
 * p::        input
 * len::      length of input
 * r::        Output buffer. Will not be NUL terminated.
 * basis_64:: The 64 character alphabet to be used, such as ~std_basis_64~ or ~safe_basis_64~
 * line_len:: Length of each line. 76 is customary. Or use very large value to
 *     avoid any line breaks
 * eol_len::  Length of End-of-Line string.
 * eol::      End-of-Line string, inserted every line_len.
 * eq_pad::   Padding character, usually equals (=)
 * return::   Pointer one past last byte written in r. This function never fails. */

/* Called by:  base64_fancy, safe_base64 */
char* base64_fancy_raw(const char* p, int len, /* input and its length */
		       char* r,                /* Output buffer. Will not be NUL terminated. */
		       const char* basis_64,   /* 64 character alphabet to be used, see above */
		       int line_len,           /* Length of each line. 76 is customary. */
		       int eol_len,            /* Length of End-of-Line string. */
		       const char* eol,        /* End-of-Line string, inserted every line_len. */
		       char eq_pad)            /* Padding character, usually equals (=) */
{
  unsigned char c1,c2,c3;
  int chunk;
  line_len /= 4;
  
  for (chunk=0; len > 2; len -= 3, ++chunk) {
    if ((chunk == line_len) && eol_len) {  /* 19 chunks (3x19=57chars) per line */
      memcpy(r, eol, eol_len);
      r += eol_len;
      chunk = 0;
    }
    c1 = *p++;
    c2 = *p++;  // *** len==1 causes bug if no null term
    *r++ = basis_64[c1>>2];
    *r++ = basis_64[((c1 & 0x0003)<< 4) | ((c2 & 0x00f0) >> 4)];
    
    c3 = *p++;
    *r++ = basis_64[((c2 & 0x000f) << 2) | ((c3 & 0x00c0) >> 6)];
    *r++ = basis_64[c3 & 0x003f];
  }
  
  /* Post processing to handle the last line, which is often incomplete. */
  
  c1 = *p++;
  switch (len) {
  case 2:
    c2 = *p++;  // *** len==1 causes bug if no null term
    *r++ = basis_64[c1>>2];
    *r++ = basis_64[((c1 & 0x0003)<< 4) | ((c2 & 0x00f0) >> 4)];
    *r++ = basis_64[(c2 & 0x000f) << 2];
    *r++ = eq_pad;
    break;
  case 1:
    *r++ = basis_64[c1>>2];
    *r++ = basis_64[(c1 & 0x0003)<< 4];
    *r++ = eq_pad;
    *r++ = eq_pad;
    break;
  case 0:
    break;  /* no padding needed */
  default:
    NEVERNEVER("Corrupt len=%d", len);
  }
  if (eol_len) {
    memcpy(r, eol, eol_len);
    r += eol_len;
  }
  return r;
}

#define XX      255     /* illegal base64 char */
#define Eq      254     /* padding */
#define INVALID XX

unsigned char zx_std_index_64[256] = {
    XX,XX,XX,XX, XX,XX,XX,XX, XX,XX,XX,XX, XX,XX,XX,XX,
    XX,XX,XX,XX, XX,XX,XX,XX, XX,XX,XX,XX, XX,XX,XX,XX,
    XX,XX,XX,XX, XX,XX,XX,XX, XX,XX,XX,62, Eq,62,XX,63,  /* `+' ',' '-' `/' */
    52,53,54,55, 56,57,58,59, 60,61,XX,XX, XX,Eq,XX,XX,  /* `=' */
    XX, 0, 1, 2,  3, 4, 5, 6,  7, 8, 9,10, 11,12,13,14,
    15,16,17,18, 19,20,21,22, 23,24,25,XX, XX,XX,XX,63,  /* `_' */
    XX,26,27,28, 29,30,31,32, 33,34,35,36, 37,38,39,40,
    41,42,43,44, 45,46,47,48, 49,50,51,XX, XX,XX,XX,XX,

    XX,XX,XX,XX, XX,XX,XX,XX, XX,XX,XX,XX, XX,XX,XX,XX,
    XX,XX,XX,XX, XX,XX,XX,XX, XX,XX,XX,XX, XX,XX,XX,XX,
    XX,XX,XX,XX, XX,XX,XX,XX, XX,XX,XX,XX, XX,XX,XX,XX,
    XX,XX,XX,XX, XX,XX,XX,XX, XX,XX,XX,XX, XX,XX,XX,XX,
    XX,XX,XX,XX, XX,XX,XX,XX, XX,XX,XX,XX, XX,XX,XX,XX,
    XX,XX,XX,XX, XX,XX,XX,XX, XX,XX,XX,XX, XX,XX,XX,XX,
    XX,XX,XX,XX, XX,XX,XX,XX, XX,XX,XX,XX, XX,XX,XX,XX,
    XX,XX,XX,XX, XX,XX,XX,XX, XX,XX,XX,XX, XX,XX,XX,XX
};

/*() Raw version. Can use any decoding table. Assumes receiving buffer r has been allocated
 * to correct length. Is able to perform the operation in place, i.e. p and r
 * can point to the same buffer. Both canonical and safe base64 are handled.
 * If string contains URL encoding (as it might for + or =) it is automatically
 * unraveled as well. This is useful for SAMLRequest field in Redirect signing.
 * Returns pointer one past last output char written. Does not nul terminate.
 * Never fails. See also SIMPLE_BASE64_PESSIMISTIC_DECODE_LEN(). */

/* Called by:  decode, main x5, zxenc_privkey_dec, zxenc_symkey_dec, zxid_cdc_check, zxid_decode_redir_or_post x2, zxid_decode_ssoreq, zxid_extract_cert, zxid_extract_private_key, zxid_idp_as_do, zxid_map_val x3, zxid_process_keys, zxid_sp_deref_art, zxsig_validate x2 */
char* unbase64_raw(const char* p, const char* lim, char* r, const unsigned char* index_64)
{
  int i;
  unsigned char c[4];
  unsigned char uc;
  
  while (p < lim) {
    i = 0;
    do {
      if (*p == '%' && p+2 < lim && IS_HEX(p[1]) && IS_HEX(p[2])) {
	/* Percent sign from URL encoding: decode */
	uc = index_64[(HEX(p[1]) << 4) | HEX(p[2])];
	p += 3;
      } else
	uc = index_64[(int)*p++];
      if (uc != INVALID)
	c[i++] = uc;
      
      if (p == lim) {
	if (i < 4) {
	  /*if (i) ERR("Premature end of base64 data. (incomplete base64 input) i=%d", i);*/
	  if (i < 2) return r;
	  if (i == 2) c[2] = Eq;
	  c[3] = Eq;
	}
	break;
      }
    } while (i < 4);
    
    if (c[0] == Eq || c[1] == Eq) {
      ERR("Premature end of base64 data. (incomplete base64 input) c0(%x)", c[0]);
      break;
    }
    /* D("c0=%d,c1=%d,c2=%d,c3=%d\n", c[0],c[1],c[2],c[3]); */
    
    *r++ = (c[0] << 2) | ((c[1] & 0x30) >> 4);
    if (c[2] == Eq) break;
    *r++ = ((c[1] & 0x0f) << 4) | ((c[2] & 0x3c) >> 2);
    if (c[3] == Eq) break;
    *r++ = ((c[2] & 0x03) << 6) | c[3];
  }
  return r;
}

/*() The out_buf should be 28 chars in length. The buffer is not automatically nul termianated.
 * There will be 27 characters of payload, plus one termination character "." (which
 * caller can overwrite with nul, if you like).
 *
 * out_buf:: Buffer where result will be written. It must be 28 characters long and already allocated. The buffer will not be null terminated.
 * len:: Length of data. -1=use strlen(data)
 * data:: Data to be digested
 * return:: Pointer one past last character written */

/* Called by:  zxcot_main, zxid_decode_redir_or_post x2, zxid_get_ent_from_cache, zxid_mk_ent, zxid_nice_sha1, zxid_reg_svc, zxid_user_sha1_name x2, zxlog_path x2, zxlog_write_line */
char* sha1_safe_base64(char* out_buf, int len, const char* data)
{
  char sha1[20];
  if (len == -1)
    len = strlen(data);
  SHA1(data, len, sha1);
  return base64_fancy_raw(sha1, 20, out_buf, safe_basis_64, 1<<31, 0, 0, '.');
}

/*(-) zlib integration internal */
/* Called by: */
voidpf zx_zlib_zalloc(void* opaque, uInt items, uInt size)
{
  return ZX_ALLOC(opaque, items*size);
}

/*(-) zlib integration internal */
/* Called by: */
void zx_zlib_zfree(void* opaque, voidpf addr)
{
  ZX_FREE(opaque, addr);
}

/*() Compress data using zlib-deflate (RFC1951). The deflated data will be in new
 * buffer, which is returned. out_len will indicate the length
 * of the comressed data. Since the compressed data will be
 * binary, there is no provision for nul termination. Caveat: RFC1951 is not same a gzip. */

/* Called by:  zxid_map_val, zxid_saml2_redir_enc, zxid_simple_idp_show_an, zxlog_write_line */
char* zx_zlib_raw_deflate(struct zx_ctx* c, int in_len, const char* in, int* out_len)
{
  int ret, dlen;
  char* out;
  z_stream z;
  *out_len = 0;
  memset(&z, 0, sizeof(z_stream));
  z.zalloc = zx_zlib_zalloc;
  z.zfree = zx_zlib_zfree;
  z.opaque = c;
  z.next_in = (unsigned char*)in;
  z.avail_in = in_len;
  ret = deflateInit2(&z, 9, Z_DEFLATED, -15, 9, Z_DEFAULT_STRATEGY);
  if (ret != Z_OK) {
    ERR("zlib deflateInit2 error: %d", ret);
    return 0;
  }
  
  dlen = in_len + (in_len >> 8) + 12;  /* worst case: orig_size * 1.001 + 12 */
  out = ZX_ALLOC(c, dlen);
  z.next_out = (unsigned char*)out;
  z.avail_out = dlen;
  
  ret = deflate(&z, Z_FINISH);
  if (ret != Z_STREAM_END) {
    deflateEnd(&z);
    ERR("zlib deflate error: %d", ret);
    return 0;
  }
  *out_len = z.total_out;
  deflateEnd(&z);
  return out;
}

/*() Decompress zlib-deflate (RFC1951) compressed data. The decompressed data will
 * be in a newly allocated buffer which is returned. The length
 * of the decompressed data is returned via out_len. The buffer
 * will always be at least byte one longer than indicated by out_len - this
 * should allow safe nul termination (but the decompressed data itself
 * may contain any number of nuls). Caveat: RFC1951 is not same a gzip. */

/* Called by:  decode x2, zxid_decode_redir_or_post, zxid_decode_ssoreq, zxid_map_val, zxlog_zsig_verify_print */
char* zx_zlib_raw_inflate(struct zx_ctx* c, int in_len, const char* in, int* out_len)
{
  int ret, dlen, iter = 30;
  char* out;
  char* old_out;
  z_stream z;
  *out_len = 0;
  memset(&z, 0, sizeof(z_stream));
  z.zalloc = zx_zlib_zalloc;
  z.zfree = zx_zlib_zfree;
  z.opaque = c;
  z.next_in = (unsigned char*)in;
  z.avail_in = in_len;
  
  dlen = in_len << 3;  /* guess inflated size: orig_size * 8 */
  out = ZX_ALLOC(c, dlen+1);
  z.next_out = (unsigned char*)out;
  z.avail_out = dlen;
  
  ret = inflateInit2(&z, -15);
  if (ret != Z_OK) {
    ERR("zlib inflateInit failed with error code %d", ret);
    return 0;
  }
  
#if 0
  ret = inflate(&z, Z_FINISH);
  if (ret != Z_STREAM_END) {
    inflateEnd(&z);
    ERR("zlib inflate failed with error code %d. Most probably the input data is empty, corrupt, or not in zlib format.", ret);
    return 0;
  }
#else
  while (--iter) {  /* Make sure we can never be caught in infinite loop */
    ret = inflate(&z, Z_SYNC_FLUSH);
    switch (ret) {
    case Z_STREAM_END: goto done;
    case Z_OK:  /* avail_out should be 0 now. Time to grow the buffer. */
      ret = z.next_out - (Bytef*)out;
      dlen += dlen;
      old_out = out;
      out = ZX_ALLOC(c, dlen+1);
      memcpy(out, old_out, ret);
      z.next_out = (unsigned char*)out + ret;
      z.avail_out = dlen - ret;
      break;
    default:
      inflateEnd(&z);
      ERR("zlib inflate failed with error code %d. Most probably the input data is empty, corrupt, or not in RFC1951 (zlib deflate) format. A common error is incomplete data (due to read(2) not returing all data on first iteration) resulting a failed detection of uncompressed data (the detection looks for '<' in beginning and '>' in end of base64 decoded data - often the latter is missing in incomplete data). iter=%d in_len=%d dlen=%d", ret, iter, in_len, dlen);
      return 0;
    }
  }
#endif
 done:
  *out_len = z.total_out;
  inflateEnd(&z);
  return out;
}

#if 1
/* N.B. Many other Liberty implementations expect nearly everything to be URL encoded. */
#define URL_BAD(x) (!A_Z_a_z_0_9_(x))
#else
#define URL_BAD(x) (((x)<=' ')||((x)>=0x7f)||ONE_OF_4((x),'+','%','=','&')||ONE_OF_2((x),'#','?'))
#endif

/*() Compute length of the URL encoded string. The encoding is done
 * to characters listed in URL_BAD() macro in zxutil.c.
 * return: Required buffer size, including nul term. Subtract 1 for string length. */

/* Called by:  zx_url_encode, zxid_pool_to_qs x5, zxid_saml2_redir_enc x2 */
int zx_url_encode_len(int in_len, char* in)
{
  int n;
  char* lim;
  /* scan through to see how many escape expansions are needed */
  lim = in + in_len;
  for (n = 0; in < lim; ++in)
    if (URL_BAD(*in)) ++n;
  return n+n+in_len+1;   /* nul-terminated length */
}

/*() URL encode input into output. The encoding is done to
 * characters listed in URL_BAD() macro in zxutil.c. The output must already
 * have been allocated to correct length (which can be obtained from
 * zx_url_encode_len() function). zx_url_encode() is higher
 * level function that does just that. Raw version does not nul terminate.
 * Returns pointer one past last byte written. */

/* Called by:  zx_url_encode, zxid_pool_to_qs x4, zxid_saml2_redir_enc x2 */
char* zx_url_encode_raw(int in_len, char* in, char* out)
{
  char* lim;
  for (lim = in+in_len; in < lim; ++in)
    if (URL_BAD(*in)) {
      *out++ = '%';
      *out++ = HEX_DIGIT((*in >> 4) & 0x0f);
      *out++ = HEX_DIGIT(*in & 0x0f);
    } else
      *out++ = *in;
  return out;
}

/*() Perform URL encoding on buffer. New output buffer is allocated.
 * The low level work is performed by zx_url_encode_raw().
 *
 * N.B. For zx_url_decode() operation see URL_DECODE() macro in errmac.h */

/* Called by: */
char* zx_url_encode(struct zx_ctx* c, int in_len, char* in, int* out_len)
{
  char* out;
  *out_len = zx_url_encode_len(in_len, in) + 1;
  out = ZX_ALLOC(c, *out_len);
  zx_url_encode_raw(in_len, in, out);
  out[*out_len-1] = '\0';
  return out;
}

const unsigned char* hex_trans      = "0123456789abcdef";
const unsigned char* ykmodhex_trans = "cbdefghijklnrtuv";  /* as of libyubikey-1.5 */

/*() Especially useful as yubikey_modhex_decode() replacement.
 * Supports inplace conversion. Does not nul terminate. */

/* Called by:  main x2, zxid_pw_authn x2 */
char* zx_hexdec(char* dst, char* src, int len, const unsigned char* trans)
{
  const unsigned char* hi;
  const unsigned char* lo;
  for (; len>1; len-=2, ++dst, src+=2) {
    hi = strchr(trans, src[0]);
    if (!hi) {
      ERR("Bad hi character(%x) in hex string using trans(%s) len left=%d src(%.*s)", src[0], trans, len, len, src);
      hi = trans;
    }
    lo = strchr(trans, src[1]);
    if (!lo) {
      ERR("Bad lo character(%x) in hex string using trans(%s) len left=%d src(%.*s)", src[1], trans, len, len, src);
      lo = trans;
    }
    *dst = ((hi-trans) << 4) | (lo-trans);
  }
  return dst;
}

/*() Convert a date-time format timestamp into seconds since Unix epoch.
 * Format is as follows
 *   01234567890123456789
 *   yyyy-MM-ddThh:mm:ssZ */

/* Called by:  zxid_idp_sso, zxid_sp_sso_finalize, zxid_validate_cond x2, zxid_wsp_validate */
int zx_date_time_to_secs(char* dt)
{
  struct tm t;
  memset(&t, 0, sizeof(t));
  sscanf(dt, "%d-%d-%dT%d:%d:%dZ",
	 &t.tm_year, &t.tm_mon, &t.tm_mday,
	 &t.tm_hour, &t.tm_min, &t.tm_sec);
  t.tm_year -= 1900;
  --t.tm_mon;
  return mktime(&t);
}

/* EOF  --  zxutil.c */
