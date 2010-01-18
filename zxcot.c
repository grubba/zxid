/* zxcot.c  -  CoT (Circle-of-Trust) management tool: list CoT, add metadata to CoT
 * Copyright (c) 2009-2010 Sampo Kellomaki (sampo@iki.fi), All Rights Reserved.
 * This is confidential unpublished proprietary source code of the author.
 * NO WARRANTY, not even implied warranties. Contains trade secrets.
 * Distribution prohibited unless authorized in writing.
 * Licensed under Apache License 2.0, see file COPYING.
 * $Id: zxcot.c,v 1.5 2009-11-29 12:23:06 sampo Exp $
 *
 * 27.8.2009, created --Sampo
 */

#include <string.h>
#include <stdio.h>
#include <fcntl.h>
#include <dirent.h>
#include <errno.h>

#include "errmac.h"
#include "zx.h"
#include "zxid.h"
#include "zxidconf.h"
#include "c/zxidvers.h"
#include "c/zx-const.h"
#include "c/zx-ns.h"
#include "c/zx-data.h"

CU8* help =
"zxcot  -  Circle-of-Trust management tool R" ZXID_REL "\n\
Copyright (c) 2009-2010 Sampo Kellomaki (sampo@iki.fi), All Rights Reserved.\n\
NO WARRANTY, not even implied warranties. Licensed under Apache License v2.0\n\
See http://www.apache.org/licenses/LICENSE-2.0\n\
Send well researched bug reports to the author. Home: zxid.org\n\
\n\
Usage: zxcot [options] [dir]\n\
       zxcot -a [options] [dir] <meta.xml\n\
       zxcot -b [options] [dir] <epr.xml\n\
       curl https://site.com/metadata.xml | zxcot -a [options] [dir]\n\
       zxcot -g https://site.com/metadata.xml [options] [dir]\n\
       zxcot -p https://site.com/metadata.xml\n\
  [dir]            CoT directory. Default /var/zxid/cot\n\
  -a               Add metadata from stdin\n\
  -b               Register Web Service, add Service EPR from stdin\n\
  -bs              Register Web Service and Bootstrap, add Service EPR from stdin\n\
  -e endpoint abstract entid servicetype   Dump EPR to stdout.\n\
  -g URL           Do HTTP(S) GET to URL and add as metadata (if compiled w/libcurl)\n\
  -n               Dryrun. Do not actually add the metadata. Instead print it to stdout.\n\
  -s               Swap columns, for easier sorting by URL\n\
  -p ENTID         Print sha1 name corresponding to an entity ID.\n\
  -v               Verbose messages.\n\
  -q               Be extra quiet.\n\
  -d               Turn on debugging.\n\
  -h               This help message\n\
  --               End of options\n\
\n\
zxcot -e http://idp.tas3.pt:8081/zxididp?o=S 'TAS3 Default Discovery Service (ID-WSF 2.0)' http://idp.tas3.pt:8081/zxididp?o=B urn:liberty:disco:2006-08 | zxcot -b\n\
\n";

int swap = 0;
int addmd = 0;
int regsvc = 0;
int regbs = 0;
int dryrun = 0;
int inflate_flag = 2;  /* Auto */
int verbose = 1;
char buf[ZXID_MAX_MD+1];
char* mdurl = 0;
char* entid = 0;
char* cotdir  = ZXID_PATH ZXID_COT_DIR;
char* dimddir = ZXID_PATH ZXID_DIMD_DIR;
char* uiddir  = ZXID_PATH ZXID_UID_DIR;

/* Called by:  main x9 */
static void opt(int* argc, char*** argv, char*** env)
{
  int len;
  if (*argc <= 1) return;
  
  while (1) {
    ++(*argv); --(*argc);
    
    if (!(*argc) || ((*argv)[0][0] != '-')) break;  /* normal exit from options loop */
    
    switch ((*argv)[0][1]) {
    case '-': if ((*argv)[0][2]) break;
      ++(*argv); --(*argc);
      DD("End of options by --");
      return;  /* -- ends the options */

    case 'a':
      switch ((*argv)[0][2]) {
      case '\0':
	++addmd;
	continue;
      }
      break;

    case 'b':
      switch ((*argv)[0][2]) {
      case 's':
	++regsvc;
	++regbs;
	dimddir = ZXID_PATH "idp" ZXID_DIMD_DIR;
	uiddir  = ZXID_PATH "idp" ZXID_UID_DIR;
	continue;
      case '\0':
	++regsvc;
	uiddir  = ZXID_PATH "idp" ZXID_UID_DIR;
	continue;
      }
      break;

    case 'e':
      switch ((*argv)[0][2]) {
      case '\0':
	if ((*argc) < 4) break;
	printf(
"<wsa:EndpointReference xmlns:wsa=\"http://www.w3.org/2005/08/addressing\" "
"xmlns:wsu=\"http://docs.oasis-open.org/wss/2004/01/oasis-200401-wss-wssecurity-utility-1.0.xsd\" "
    "notOnOrAfter=\"2037-01-05T23:03:59.001Z\" "
    "wsu:Id=\"EPRID92lFPo3ZNEt_3rHtJFoU\">"
  "<wsa:Address>%s</wsa:Address>"
  "<wsa:Metadata>"
    "<di:Abstract xmlns:di=\"urn:liberty:disco:2006-08\">%s</di:Abstract>"
    "<sbf:Framework xmlns:sbf=\"urn:liberty:sb\" version=\"2.0\"></sbf:Framework>"
    "<di:ProviderID xmlns:di=\"urn:liberty:disco:2006-08\">%s</di:ProviderID>"
    "<di:ServiceType xmlns:di=\"urn:liberty:disco:2006-08\">%s</di:ServiceType>"
  "</wsa:Metadata>"
"</wsa:EndpointReference>", (*argv)[1], (*argv)[2], (*argv)[3], (*argv)[4]);
	exit(0);
      }
      break;

    case 'g':
      switch ((*argv)[0][2]) {
      case '\0':
	++(*argv); --(*argc);
	if ((*argc) < 1) break;
	mdurl = (*argv)[0];
	++addmd;
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

    case 's':
      switch ((*argv)[0][2]) {
      case '\0':
	++swap;
	continue;
      }
      break;

    case 'p':
      switch ((*argv)[0][2]) {
      case '\0':
	++(*argv); --(*argc);
	if ((*argc) < 1) break;
	entid = (*argv)[0];
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
    D("HERE");
    if (*argc)
      fprintf(stderr, "Unrecognized flag `%s'\n", (*argv)[0]);
    fprintf(stderr, help);
    /*fprintf(stderr, "version=0x%06x rel(%s)\n", zxid_version(), zxid_version_str());*/
    exit(3);
  }
  if (*argc) {
    uiddir = dimddir = cotdir = (*argv)[0];
    len = strlen(cotdir);
    if (cotdir[len-1] != '/') {
      cotdir = malloc(len+1);
      strcpy(cotdir, (*argv)[0]);
      cotdir[len] = '/';
      cotdir[len+1] = 0;
      uiddir = dimddir = cotdir;
    }
  }
}

/*() IdP and Discovery. Register service metadata to /var/zxid/idpdimd/XX,
 * and possibly boostrap to /var/zxid/idpuid/.all/.bs/YY */

static int zxid_reg_svc(struct zxid_conf* cf, int bs_reg, int dry_run, const char* ddimd, const char* duid)
{
  char sha1_name[28];
  char path[ZXID_MAX_BUF];
  char* p;
  char* uiddir;
  int got, fd;
  struct zx_root_s* r;
  struct zx_a_EndpointReference_s* epr;
  struct zx_str* ss;
  
  read_all_fd(0, buf, sizeof(buf)-1, &got);
  buf[got] = 0;
  p = buf;
  
  zx_prepare_dec_ctx(cf->ctx, zx_ns_tab, buf, buf + got);
  r = zx_DEC_root(cf->ctx, 0, 1);
  if (!r || !r->EndpointReference) {
    ERR("Failed to parse <EndpointReference> buf(%.*s)", got, buf);
    return 1;
  }
  epr = r->EndpointReference;
  if (!epr->Address || !epr->Address->gg.content || !epr->Address->gg.content->len) {
    ERR("<EndpointReference> MUST have <Address> element buf(%.*s)", got, buf);
    return 1;
  }
  if (!epr->Metadata) {
    ERR("<EndpointReference> MUST have <Metadata> element buf(%.*s)", got, buf);
    return 1;
  }
  if (!epr->Metadata->ProviderID
      || !epr->Metadata->ProviderID->content->len || !epr->Metadata->ProviderID->content->len) {
    ERR("<EndpointReference> MUST have <Metadata> with <ProviderID> element buf(%.*s)", got, buf);
    return 1;
  }
  if (!epr->Metadata->ServiceType) {
    ERR("<EndpointReference> MUST have <ServiceType> element buf(%.*s)", got, buf);
    return 1;
  }

  /* *** possibly add something here and double check the required fields are available. */

  ss = zx_EASY_ENC_SO_a_EndpointReference(cf->ctx, epr);
  if (!ss)
    return 2;
  
#if 0
  // *** wrong
  got = MIN(epr->Metadata->ProviderID->content->len, sizeof(path)-1);
  memcpy(path, epr->Metadata->ProviderID->content->s, got);
#else
  got = MIN(epr->Metadata->ServiceType->content->len, sizeof(path)-1);
  memcpy(path, epr->Metadata->ServiceType->content->s, got);
#endif
  path[got] = 0;
  zxid_fold_svc(path, got);

  sha1_safe_base64(sha1_name, ss->len, ss->s);
  sha1_name[27] = 0;
  duid = strdup(duid);
  got = strlen(duid);
  if (strcmp(duid + got - (sizeof("dimd/")-1), "dimd/")) {
    /* strcpy ok, because always fits: "uid/" is shorter than "dimd/" */
    strcpy(duid + got - (sizeof("dimd/")-1), "uid/");
  }

  if (verbose)
    fprintf(stderr, "Registering metadata in %s%s,%s", ddimd, path, sha1_name);
  
  if (dry_run) {
    if (verbose)
      fprintf(stderr, "Register EPR dry run. Would have written to path(%s%s,%s). "
	      "You may also want to\n"
	      "  touch %s.all/.bs/%s,%s\n\n", ddimd, path, sha1_name, uiddir, path, sha1_name);
    fflush(stdin);
    write_all_fd(1, ss->s, ss->len);
    zx_str_free(cf->ctx, ss);
    return 0;
  }
  
  D("Register EPR path(%s%s,%s) in discovery metadata.", ddimd, path, sha1_name);
  fd = open_fd_from_path(O_CREAT | O_WRONLY | O_TRUNC, 0666, "zxcot -b",
			 "%s%s,%s", ddimd, path, sha1_name);
  if (fd == BADFD) {
    perror("open epr for registering");
    ERR("Failed to open file for writing: sha1_name(%s,%s) to service registration", path, sha1_name);
    zx_str_free(cf->ctx, ss);
    return 1;
  }
  
  write_all_fd(fd, ss->s, ss->len);
  zx_str_free(cf->ctx, ss);
  close_file(fd, (const char*)__FUNCTION__);

  if (bs_reg) {
    if (verbose)
      fprintf(stderr, "Activating bootstrap %s.all/.bs/%s,%s", duid, path, sha1_name);

    if (!dryrun) {
      fd = open_fd_from_path(O_CREAT | O_WRONLY | O_TRUNC, 0666, "zxcot -bs",
			     "%s.all/.bs/%s,%s", duid, path, sha1_name);
      if (fd == BADFD) {
	perror("open epr for bootstrap activation");
	ERR("Failed to open file for writing: sha1_name(%s,%s) to bootstrap activation", path, sha1_name);
	return 1;
      }
    
      write_all_fd(fd, "", 0);
      close_file(fd, (const char*)__FUNCTION__);
    }
  } else {
    D("You may also want to activate bootstrap by\n  touch %s.all/.bs/%s,%s", duid, path, sha1_name);
  }
  return 0;
}

/*() Add metadata of a partner to the Circle-of-Trust, represented by the CoT dir */

static int zxid_addmd(struct zxid_conf* cf, char* mdurl, int dry_run, const char* dcot)
{
  int got, fd;
  char* p;
  struct zxid_entity* ent;
  struct zx_str* ss;
  
  if (mdurl) {
    ent = zxid_get_meta(cf, mdurl);
  } else {
    read_all_fd(0, buf, sizeof(buf)-1, &got);
    buf[got] = 0;
    p = buf;
    ent = zxid_parse_meta(cf, &p, buf+got);
  }
  
  if (!ent) {
    ERR("***** Parsing metadata failed %d", 0);
    return 1;
  }
  
  ss = zx_EASY_ENC_SO_md_EntityDescriptor(cf->ctx, ent->ed);
  if (!ss)
    return 2;
  
  if (verbose)
    fprintf(stderr, "Writing ent(%.*s) to %s%s\n", ent->eid_len, ent->eid, dcot, ent->sha1_name);
  if (dry_run) {
    write_all_fd(1, ss->s, ss->len);
    zx_str_free(cf->ctx, ss);
    return 0;
  }
  
  fd = open_fd_from_path(O_CREAT | O_WRONLY | O_TRUNC, 0666, "zxcot -a", "%s%s", dcot, ent->sha1_name);
  if (fd == BADFD) {
    perror("open metadata for writing metadata to cache");
    ERR("Failed to open file for writing: sha1_name(%s) to metadata cache", ent->sha1_name);
    zx_str_free(cf->ctx, ss);
    return 0;
  }
  
  write_all_fd(fd, ss->s, ss->len);
  zx_str_free(cf->ctx, ss);
  close_file(fd, (const char*)__FUNCTION__);
  return 0;
}

/*() Print a line of Circle-of-Trust listing */

static int zxid_lscot_line(struct zxid_conf* cf, int col_swap, const char* dcot, const char* den)
{
  struct zxid_entity* ent;
  char* p;
  int got = read_all(ZXID_MAX_MD, buf, "zxcot line", "%s%s", dcot, den);
  if (!got) {
    ERR("Zero data in file(%s%s)", dcot, den);
    return 1;
  }
  p = buf;
  ent = zxid_parse_meta(cf, &p, buf+got);
  if (!ent) {
    ERR("***** Parsing metadata failed for(%s%s)", dcot, den);
    return 2;
  }
  switch (col_swap) {
  case 1:  printf("%.*s\t%s%s\n", ent->eid_len, ent->eid, dcot, den); break;
  case 2:  printf("%.*s\n",       ent->eid_len, ent->eid); break;
  default: printf("%s%s %.*s\n",  dcot, den, ent->eid_len, ent->eid);
  }
  if (strcmp(*den?den:dcot, ent->sha1_name))
    fprintf(stderr, "Filename(%s) does not match sha1_name(%s)\n", *den?den:dcot, ent->sha1_name);
  return 0;
}

/*() List the contents of the Circle-of-Trust, represented by the CoT directory,
 * in various formats. */

static int zxid_lscot(struct zxid_conf* cf, int col_swap, const char* dcot)
{
  int got, ret;
  char* p;
  DIR* dir;
  struct dirent* de;

  dir = opendir(dcot);
  if (!dir) {
    perror("opendir for /var/zxid/cot (or other if configured) for loading cot cache");
    D("failed path(%s)", dcot);
    
    got = strlen(dcot);
    p = ZX_ALLOC(cf->ctx, got+1);
    memcpy(p, dcot, got-1);
    p[got-1] = 0;  /* chop off / */
    got = zxid_lscot_line(cf, col_swap, p, "");
    ZX_FREE(cf->ctx, p);
    return got;
  }
  
  while (de = readdir(dir)) {
    if (de->d_name[0] == '.' || de->d_name[strlen(de->d_name)-1] == '~')
      continue;
    ret = zxid_lscot_line(cf, col_swap, dcot, de->d_name);
    if (!ONE_OF_2(ret, 0, 2))
      return ret;
  }
  return 0;
}

#ifndef zxcot_main
#define zxcot_main main
#endif

/*() Circle of Trust management tool */

/* Called by: */
int zxcot_main(int argc, char** argv, char** env)
{
  struct zxid_conf cf;

  strncpy(zx_instance, "\tzxdec", sizeof(zx_instance));
 
  opt(&argc, &argv, &env);
  
  if (entid) {
    char sha1_name[28];
    sha1_safe_base64(sha1_name, strlen(entid), entid);
    sha1_name[27] = 0;
    printf("%s\n", sha1_name);
    return 0;
  }
  
  zxid_init_conf_ctx(&cf, ZXID_PATH);
  
  if (addmd)
    return zxid_addmd(&cf, mdurl, dryrun, cotdir);
  
  if (regsvc)
    return zxid_reg_svc(&cf, regbs, dryrun, dimddir, uiddir);
  
  return zxid_lscot(&cf, swap, cotdir);
}

/* EOF  --  zxcot.c */
