/* zxidmeta.c  -  Handwritten functions for metadata parsing and generation as well as CoT handling
 * Copyright (c) 2010 Sampo Kellomaki (sampo@iki.fi), All Rights Reserved.
 * Copyright (c) 2006-2009 Symlabs (symlabs@symlabs.com), All Rights Reserved.
 * Author: Sampo Kellomaki (sampo@iki.fi)
 * This is confidential unpublished proprietary source code of the author.
 * NO WARRANTY, not even implied warranties. Contains trade secrets.
 * Distribution prohibited unless authorized in writing.
 * Licensed under Apache License 2.0, see file COPYING.
 * $Id: zxidmeta.c,v 1.59 2009-11-24 23:53:40 sampo Exp $
 *
 * The CoT cache exists both on disk as directory /var/zxid/cot and in
 * memory as the field cf->cot. The latter is protected by cf->mx lock.
 * The entities in cache are essentially read only, i.e. once the head
 * of the list cf->cot has been dereferenced in a thread safe way,
 * the entity pointers themselves can be passed around threads with
 * impunity. No locking needed for them.
 *
 * 12.8.2006,  created --Sampo
 * 12.10.2007, mild refactoring to process keys for xenc as well. --Sampo
 * 13.12.2007, fixed missing KeyDescriptor/@use as seen in CA IdP metadata --Sampo
 * 14.4.2008,  added SimpleSign --Sampo
 * 7.10.2008,  added documentation --Sampo
 * 1.2.2010,   removed arbitrary size limit --Sampo
 * 12.2.2010,  added pthread locking --Sampo
 */

#include <fcntl.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <dirent.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/stat.h>

#ifdef USE_OPENSSL
#include <openssl/sha.h>
#include <openssl/x509.h>
#include <openssl/rsa.h>
#endif

#include "errmac.h"
#include "saml2.h"
#include "zxid.h"
#include "zxidconf.h"
#include "platform.h"
#include "c/zx-const.h"
#include "c/zx-ns.h"
#include "c/zx-data.h"

/* ============== CoT and Metadata of Others ============== */

/*() Process certificates (public keys) from a metadata for entity.
 * Since one entity can be both IdP and SP, this function may
 * be called twice per entity, with different kd argument. */

/* Called by:  zxid_mk_ent x2 */
static void zxid_process_keys(zxid_conf* cf, zxid_entity* ent, struct zx_md_KeyDescriptor_s* kd, char* logkey)
{
  int len;
  char* pp;
  char* p;
  char* e;
  X509* x;

  for (; kd; kd = (struct zx_md_KeyDescriptor_s*)kd->gg.g.n) {
    if (!kd->KeyInfo || !kd->KeyInfo->X509Data || !kd->KeyInfo->X509Data->X509Certificate || !kd->KeyInfo->X509Data->X509Certificate->content) {
      ERR("KeyDescriptor for %s missing essential subelements KeyInfo=%p", logkey, kd->KeyInfo);
      return;
    }
    p = kd->KeyInfo->X509Data->X509Certificate->content->s;
    len = kd->KeyInfo->X509Data->X509Certificate->content->len;
    e = p + len;
    pp = ZX_ALLOC(cf->ctx, SIMPLE_BASE64_PESSIMISTIC_DECODE_LEN(e-p));
    e = unbase64_raw(p, e, pp, zx_std_index_64);
    x = 0;  /* Forces d2i_X509() to alloc the memory. */
    if (!d2i_X509(&x, (const unsigned char**)&pp /* *** compile warning */, e-pp) || !x) {
      ERR("DER decoding of X509 certificate for %s failed. use(%.*s)", logkey, kd->use->len, kd->use->s);
      D("Extracted %s base64 form of cert(%.*s)", logkey, len, p);
      return;
    }
    if (!kd->use) {
      ent->sign_cert = x;
      ent->enc_cert = x;
      D("KeyDescriptor is missing use attribute. Assume this certificate can be used for both signing and encryption. %d", 0);
      return;
    }
    if (!memcmp("signing", kd->use->s, kd->use->len)) {
      ent->sign_cert = x;
      DD("Extracted %s sign cert(%.*s)", logkey, len, p);
    } else if (!memcmp("encryption", kd->use->s, kd->use->len)) {
      ent->enc_cert = x;
      DD("Extracted %s enc cert(%.*s)", logkey, len, p);
    } else {
      ERR("Unknown key use(%.*s)", kd->use->len, kd->use->s);
      D("Extracted %s cert(%.*s)", logkey, len, p);
    }
  }
}

/* Called by:  zxid_parse_meta x2 */
static zxid_entity* zxid_mk_ent(zxid_conf* cf, struct zx_md_EntityDescriptor_s* ed)
{
  zxid_entity* ent = ZX_ZALLOC(cf->ctx, zxid_entity);
  ent->ed = ed;
  if (!ed->entityID)
    goto bad_md;
  ent->eid = zx_str_to_c(cf->ctx, ed->entityID);
  sha1_safe_base64(ent->sha1_name, ed->entityID->len, ent->eid);
  ent->sha1_name[27] = 0;
  
  if (ed->Organization && ed->Organization->OrganizationDisplayName
      && ed->Organization->OrganizationDisplayName->gg.content)
    ent->dpy_name = zx_str_to_c(cf->ctx, ed->Organization->OrganizationDisplayName->gg.content);
  
  if (ed->IDPSSODescriptor)
    zxid_process_keys(cf, ent, ed->IDPSSODescriptor->KeyDescriptor, "IDP SSO");
  if (ed->SPSSODescriptor)
    zxid_process_keys(cf, ent, ed->SPSSODescriptor->KeyDescriptor, "SP SSO");

  return ent;
 bad_md:
  ERR("Bad metadata. EntityDescriptor was corrupt. %d", 0);
  zxlog(cf, 0, 0, 0, 0, 0, 0, 0, "N", "B", "BADMD", 0, "");
  return 0;
}

/*() Parse Metadata, see [SAML2meta]. This function is quite low level
 * and assumes it is processing a buffer (which may contain multiple
 * instances of various metadata).
 *
 * cf:: ZXID configuration object, used here mainly for memory allocation
 * md:: Value-result parameter. Pointer to char pointer pointing to the
 *     beginning of the metadata. As metadata is scanned and parsed, this
 *     pointer will be advanced
 * lim:: End of the metadata buffer
 * return:: Entity data structure composed from the metadata. If more than
 *     one EntityDescriptor is found, then a linked list is returned. */

/* Called by:  zxid_addmd, zxid_get_ent_from_file, zxid_get_meta, zxid_lscot_line */
zxid_entity* zxid_parse_meta(zxid_conf* cf, char** md, char* lim)
{
  zxid_entity* ee;
  zxid_entity* ent;
  struct zx_md_EntityDescriptor_s* ed;
  struct zx_root_s* r;

  LOCK(cf->ctx->mx, "parse meta");
  zx_prepare_dec_ctx(cf->ctx, zx_ns_tab, *md, lim);
  r = zx_DEC_root(cf->ctx, 0, 5);
  UNLOCK(cf->ctx->mx, "parse meta");
  *md = cf->ctx->p;
  if (!r)
    return 0;
  if (r->EntityDescriptor) {
    ed = r->EntityDescriptor;
    ZX_FREE(cf->ctx, r);  /* N.B Shallow free only, do not free the descriptor. */
    return zxid_mk_ent(cf, ed);
  } else if (r->EntitiesDescriptor) {
    if (!r->EntitiesDescriptor->EntityDescriptor)
      goto bad_md;
    for (ed = r->EntitiesDescriptor->EntityDescriptor; ed; ed = (struct zx_md_EntityDescriptor_s*)ZX_NEXT(ed)) {
      ent = zxid_mk_ent(cf, ed);
      ent->n = ee;
      ee = ent;
    }
    ZX_FREE(cf->ctx, r->EntitiesDescriptor);
    ZX_FREE(cf->ctx, r);  /* N.B Shallow free only, do not free the descriptors. */
    return ee;
  }  
 bad_md:
  ERR("Bad metadata. EntityDescriptor could not be found or was corrupt. MD(%.*s) %d chars parsed.", lim-cf->ctx->base, cf->ctx->base, *md - cf->ctx->base);
  zxlog(cf, 0, 0, 0, 0, 0, 0, 0, "N", "B", "BADMD", 0, "chars_parsed(%d)", *md - cf->ctx->base);
  zx_FREE_root(cf->ctx, r, 0);
  return 0;
}

/*() Write metadata of an entity to the Circle of Trust (CoT) cache of
 * the entity identified by cf. Mainly used by Auto-CoT. */

/* Called by:  opt x3, zxid_get_ent_ss */
int zxid_write_ent_to_cache(zxid_conf* cf, zxid_entity* ent)
{
  struct zx_str* ss;
  fdtype fd = open_fd_from_path(O_CREAT | O_WRONLY | O_TRUNC, 0666, "write_ent_to_cache", "%s" ZXID_COT_DIR "%s", cf->path, ent->sha1_name);
  if (fd == BADFD) {
    perror("open metadata for writing metadata to cache");
    ERR("Failed to open file for writing: sha1_name(%s) to metadata cache", ent->sha1_name);
    return 0;
  }
  
  ss = zx_EASY_ENC_SO_md_EntityDescriptor(cf->ctx, ent->ed);
  if (!ss)
    return 0;
  write_all_fd(fd, ss->s, ss->len);
  zx_str_free(cf->ctx, ss);
  close_file(fd, (const char*)__FUNCTION__);
  return 1;
}

/*() Read metadata from a file.
 *
 * Usually the file will be named according to "sha1 name", which
 * is safe base64 encoded SHA1 digest hash over the EntityID. This
 * is used to ensure unique file name for each entity. However,
 * this function will in fact read from any file name supplied.
 * If the file contains multiple EntityDescriptor elements, they
 * are all added to the cot. Also EntitiesDesciptor is handled.
 *
 * See also zxid_get_ent_from_cache() which will compute the sha1_name
 * and then read the metadata. */

/* Called by:  main x3, test_ibm_cert_problem_enc_dec, zxid_get_ent_by_sha1_name, zxid_get_ent_from_cache, zxid_load_cot_cache_from_file */
zxid_entity* zxid_get_ent_from_file(zxid_conf* cf, char* sha1_name)
{
  int n, got, gotty, siz = ZXID_INIT_MD_BUF;
  fdtype fd;
  char* md_buf;
  char* p;
  zxid_entity* first = 0;
  zxid_entity* ent;
  zxid_entity* ee;
  
  DD("sha1_name(%s)", sha1_name);
  fd = open_fd_from_path(O_RDONLY, 0, "get_ent_from_file", "%s" ZXID_COT_DIR "%s", cf->path, sha1_name);
  if (fd == BADFD) {
    perror("open metadata to read");
    D("No metadata file found for sha1_name(%s)", sha1_name);
    return 0;
  }
  
  md_buf = ZX_ALLOC(cf->ctx, siz+1);
  n = read_all_fd(fd, md_buf, siz, &got);
  DD("==========sha1_name(%s)", sha1_name);
  if (n == -1)
    goto readerr;

  while (got == siz) {
    siz += siz;
    if (siz > ZXID_MAX_CURL_BUF) {
      ERR("Metadata for sha1_name(%s) is too big. Exceeds built in limit ZXID_MAX_CURL_BUF=%d", sha1_name, ZXID_MAX_CURL_BUF);
      close_file(fd, (const char*)__FUNCTION__);
      return 0;
    }
    DD("Realloc(%.*s) got=%d siz=%d Realloc(%s)", got, md_buf, got, siz, sha1_name);
    REALLOCN(md_buf, siz+1);
    n = read_all_fd(fd, md_buf+got, siz-got, &gotty);
    if (n == -1)
      goto readerr;
    got += gotty;
  }
  close_file(fd, (const char*)__FUNCTION__);

  DD("md_buf(%.*s) got=%d siz=%d md_buf(%s)", got, md_buf, got, siz, sha1_name);
  
  p = md_buf;
  while (p < md_buf+got) {   /* Loop over concatenated descriptors. */
    ent = zxid_parse_meta(cf, &p, md_buf+got);
    if (!first)
      first = ent;
    DD("++++++++++++sha1_name(%s)", sha1_name);
    if (!ent) {
      ZX_FREE(cf->ctx, md_buf);
      ERR("***** Parsing metadata failed for sha1_name(%s)", sha1_name);
      return first;
    }
    LOCK(cf->mx, "add ent to cot");
    while (ent) {
      ee = ent->n;
      ent->n = cf->cot;
      cf->cot = ent;
      ent = ee;
    }
    UNLOCK(cf->mx, "add ent to cot");
    D("GOT META sha1_name(%s) eid(%s)", sha1_name, first?first->eid:"?");
  }
  return first;

readerr:
  perror("read metadata");
  D("Failed to read metadata for sha1_name(%s)", sha1_name);
  close_file(fd, (const char*)__FUNCTION__);
  return 0;
}

/*LOCK_STATIC(zxid_ent_cache_mx);*/
extern pthread_mutex_t zxid_ent_cache_mx;

/* Called by:  zxid_get_ent_from_cache, zxid_load_cot_cache */
static void zxid_load_cot_cache_from_file(zxid_conf* cf)
{
  zxid_entity* ee;  
  if (!cf->load_cot_cache)
    return;
  LOCK(zxid_ent_cache_mx, "get ent from cache");
  LOCK(cf->mx, "check cot");
  ee = cf->cot;
  UNLOCK(cf->mx, "check cot");
  if (!ee) {
    D("Loading cot cache from(%s)", cf->load_cot_cache);
    zxid_get_ent_from_file(cf, cf->load_cot_cache);
    D("CoT cache loaded from(%s)", cf->load_cot_cache);
  }
  UNLOCK(zxid_ent_cache_mx, "get ent from cache");
}

/*() Search cot datastructure by entity id. Failing to find,
 * compute sha1_name for an entity and then read the metadata from
 * the CoT metadata cache directory, e.g. /var/zxid/cot */

/* Called by:  main x5, zxid_get_ent_ss x3 */
zxid_entity* zxid_get_ent_from_cache(zxid_conf* cf, struct zx_str* eid)
{
  zxid_entity* ent;
  char sha1_name[28];
  zxid_load_cot_cache_from_file(cf);
  for (ent = cf->cot; ent; ent = ent->n)  /* Check in memory cache. */
    if (eid->len == strlen(ent->eid) && !memcmp(eid->s, ent->eid, eid->len)) {
      D("GOT FROM MEM eid(%s)", ent->eid);
      return ent;
    }
  sha1_safe_base64(sha1_name, eid->len, eid->s);
  sha1_name[27] = 0;
  return zxid_get_ent_from_file(cf, sha1_name);
}

/*(i) Get metadata for entity, either from cache or network (using WKL), depending
 * on configuration options. Main work horse for getting entity metadata.
 *
 * cf:: ZXID configuration object
 * eid:: Entity ID whose metadata is desired
 * return:: Entity data structure, including the metadata */

/* Called by:  zxid_add_fed_tok_to_epr, zxid_chk_sig, zxid_decode_redir_or_post, zxid_get_ent, zxid_get_ses_idp, zxid_idp_dispatch, zxid_idp_sso, zxid_simple_idp_show_an, zxid_slo_resp_redir, zxid_sp_dispatch, zxid_sp_sso_finalize, zxid_wsf_validate_a7n, zxid_wsp_validate */
zxid_entity* zxid_get_ent_ss(zxid_conf* cf, struct zx_str* eid)
{
  zxid_entity* old_cot;
  zxid_entity* ent;
  zxid_entity* ee;
  zxid_entity* match = 0;
  
  D("eid(%.*s) path(%.*s) cf->magic=%x, md_cache_first(%d), cot(%p)", eid->len, eid->s, cf->path_len, cf->path, cf->magic, cf->md_cache_first, cf->cot);
  if (cf->md_cache_first) {
    ent = zxid_get_ent_from_cache(cf, eid);
    if (ent)
      return ent;
  }
  
  if (cf->md_fetch) {
    ent = zxid_get_meta_ss(cf, eid);
    if (ent) {
      LOCK(cf->mx, "read cot");
      old_cot = cf->cot;
      UNLOCK(cf->mx, "read cot");
      while (ent) {
	if (eid->len == strlen(ent->eid) && !memcmp(eid->s, ent->eid, eid->len)) {
	  match = ent;
	}
	/* Check whether entity is already in the cache. */
	if (zxid_get_ent_from_cache(cf, ent->ed->entityID)) {
	  INFO("While fetching metadata for eid(%.*s) got metadata for eid(%s), but the metadata was already in the cache. New metadata ignored.", eid->len, eid->s, ent->eid);
	  ent = ent->n;
	} else {
	  INFO("While fetching metadata for eid(%.*s) got metadata for eid(%s). New metadata cached.", eid->len, eid->s, ent->eid);
	  ee = ent->n;
	  LOCK(cf->mx, "add fetched ent to cot");
	  ent->n = cf->cot;
	  cf->cot = ent;
	  UNLOCK(cf->mx, "add fetched ent to cot");
	  ent = ee;
	}
      }
      
      if (cf->md_populate_cache) {
	LOCK(cf->mx, "read cot");
	ent = cf->cot;
	UNLOCK(cf->mx, "read cot");
	for (; ent != old_cot; ent = ent->n)
	  zxid_write_ent_to_cache(cf, ent);
      }
      if (match)
	return match;
    }
  }
  
  if (cf->md_cache_last) {
    ent = zxid_get_ent_from_cache(cf, eid);
    if (ent)
      return ent;
  }
  D("eid(%.*s) NOT FOUND\n", eid->len, eid->s);
  zxlog(cf, 0, 0, 0, 0, 0, 0, 0, "N", "B", "NOMD", 0, "eid(%.*s)", eid->len, eid->s);
  return 0;
}

/*() Wrapper for zxid_get_ent_ss(), which see. */

/* Called by:  zxcall_main, zxid_cdc_check x2, zxid_start_sso_url */
zxid_entity* zxid_get_ent(zxid_conf* cf, char* eid)
{
  struct zx_str ss;
  if (!eid)
    return 0;
  ss.s = eid;
  ss.len = strlen(eid);
  DD("eid: (%s)", eid);
  return zxid_get_ent_ss(cf, &ss);
}

/*() Given sha1_name, check in memory cache and if not, the disk cache. Do not try net (WKL). */

/* Called by:  zxid_get_ent_by_succinct_id, zxid_load_cot_cache */
zxid_entity* zxid_get_ent_by_sha1_name(zxid_conf* cf, char* sha1_name)
{
  zxid_entity* ent;
  LOCK(cf->mx, "scan cache by sha1_name");
  for (ent = cf->cot; ent; ent = ent->n)  /* Check in-memory cache. */
    if (!strcmp(sha1_name, ent->sha1_name)) {
      UNLOCK(cf->mx, "scan cache by sha1_name");
      return ent;
    }
  UNLOCK(cf->mx, "scan cache by sha1_name");
  ent = zxid_get_ent_from_file(cf, sha1_name);
  if (!ent)
    zxlog(cf, 0, 0, 0, 0, 0, 0, 0, "N", "B", "NOMD", 0, "sha1_name(%s)", sha1_name);
  return ent;
}

/*() In artifact profile concept of "succinct id" appears. If you have one of those,
 * you canuse this function to fetch the entity metadata. Only in-memory
 * and disk caches will be tried. No network connection (WKL) will be initiated. */

/* Called by:  zxid_sp_deref_art */
zxid_entity* zxid_get_ent_by_succinct_id(zxid_conf* cf, char* raw_succinct_id)
{
  char sha1_name[28];
  base64_fancy_raw(raw_succinct_id, 20, sha1_name, safe_basis_64, 1<<31, 0, 0, '.');
  sha1_name[27] = 0;
  return zxid_get_ent_by_sha1_name(cf, sha1_name);
}

/*() Usually you will want to use the get_ent() methods if you need
 * only specific entities. Loading the entire cache is expensive and
 * only useful if you really need to enumerate through all
 * available entities. This may be the case when rendering login
 * buttons for all IdPs in a user interface.
 *
 * cf:: ZXID configuration object
 * return:: Linked list of Entity objects (metadata) for CoT partners */

/* Called by:  main x2, zxid_idp_list_cf_cgi, zxid_mk_idp_list */
zxid_entity* zxid_load_cot_cache(zxid_conf* cf)
{
  zxid_entity* ent;
  struct dirent* de;
  DIR* dir;
  char buf[4096];
  if (cf->path_len + sizeof(ZXID_COT_DIR) > sizeof(buf)) {
   ERR("Too long path(%.*s) for config dir. Has %d chars. Max allowed %d. (config problem)",
	cf->path_len, cf->path, cf->path_len, sizeof(buf) - sizeof(ZXID_COT_DIR));
    return 0;
  }
  memcpy(buf, cf->path, cf->path_len);
  memcpy(buf + cf->path_len, ZXID_COT_DIR, sizeof(ZXID_COT_DIR));

  zxid_load_cot_cache_from_file(cf);
  
  dir = opendir(buf);
  if (!dir) {
    perror("opendir for /var/zxid/cot (or other if configured) for loading cot cache");
    ERR("opendir failed path(%s) uid=%d gid=%d", buf, geteuid(), getegid());
    return 0;
  }
  
  while (de = readdir(dir))
    if (de->d_name[0] != '.' && de->d_name[strlen(de->d_name)-1] != '~')
      zxid_get_ent_by_sha1_name(cf, de->d_name);
  
  DD("HERE %p", cf);
  closedir(dir);

  LOCK(cf->mx, "return cot");
  ent = cf->cot;
  UNLOCK(cf->mx, "return cot");
  return ent;
}

/* ============== Our Metadata ============== */

#if 0
/*() Constructor for key descriptor.
 * In the metadata the PEM start/end cert markers are NOT used. */

/* Called by:  zxid_idp_sso_desc x2, zxid_sp_sso_desc x2 */
struct zx_md_KeyDescriptor_s* zxid_key_desc(zxid_conf* cf, char* use, X509* x)
{
  int len;
  char* dd;
  char* d;
  char* pp;
  char* p;
  struct zx_md_KeyDescriptor_s* kd = zx_NEW_md_KeyDescriptor(cf->ctx);
  kd->use = zx_ref_str(cf->ctx, use);
  kd->KeyInfo = zx_NEW_ds_KeyInfo(cf->ctx);
  kd->KeyInfo->X509Data = zx_NEW_ds_X509Data(cf->ctx);

#ifdef USE_OPENSSL
  /* Build PEM encoding */
  
  len = i2d_X509(x, 0);
  if (len <= 0) {
    ERR("DER encoding certificate failed: %d", len);
  } else {
    dd = d = ZX_ALLOC(cf->ctx, len);
    i2d_X509(x, (unsigned char**)&d);
    pp = p = ZX_ALLOC(cf->ctx, (len+4) * 4 / 3 + (len/64) + 6
		      + sizeof(PEM_CERT_START) + sizeof(PEM_CERT_END));    
    memcpy(p, PEM_CERT_START, sizeof(PEM_CERT_START)-1);
    p += sizeof(PEM_CERT_START)-1;
    *p++ = '\n';
    p = base64_fancy_raw(dd, len, p, std_basis_64, 64, 1, "\n", '=');
    memcpy(p, PEM_CERT_END, sizeof(PEM_CERT_END)-1);
    p += sizeof(PEM_CERT_END)-1;
    /**p++ = '\n';*/
    *p = 0;

    kd->KeyInfo->X509Data->X509Certificate = zx_ref_len_simple_elem(cf->ctx, p-pp, pp);
  }
#else
  ERR("This copy of zxid was compiled to NOT use OpenSSL. Generating KeyInfo is not supported. Add -DUSE_OPENSSL and recompile. %d", 0);
#endif
  return kd;
}
#endif

/*() Generate XML-DSIG key info given X509 certificate. */

/* Called by:  zxenc_pubkey_enc, zxid_key_desc */
struct zx_ds_KeyInfo_s* zxid_key_info(zxid_conf* cf, X509* x)
{
  int len;
  char* dd;
  char* d;
  char* pp;
  char* p;
  struct zx_ds_KeyInfo_s* ki = zx_NEW_ds_KeyInfo(cf->ctx);
  ki->X509Data = zx_NEW_ds_X509Data(cf->ctx);

#ifdef USE_OPENSSL
  /* Build PEM encoding (which is base64 of the DER encoding + header and footer) */
  
  len = i2d_X509(x, 0);  /* Length of the DER encoding */
  if (len <= 0) {
    ERR("DER encoding certificate failed: %d", len);
  } else {
    dd = d = ZX_ALLOC(cf->ctx, len);
    i2d_X509(x, (unsigned char**)&d);  /* DER encoding of the cert */
    pp = p = ZX_ALLOC(cf->ctx, (len+4) * 4 / 3 + (len/64) + 6);    
    p = base64_fancy_raw(dd, len, p, std_basis_64, 64, 1, "\n", '=');
    *p = 0;
    ki->X509Data->X509Certificate = zx_ref_len_simple_elem(cf->ctx, p-pp, pp);
  }
#else
  ERR("This copy of zxid was compiled to NOT use OpenSSL. Generating KeyInfo is not supported. Add -DUSE_OPENSSL and recompile. %d", 0);
#endif
  return ki;
}

/*() Generate key descriptor metadata fragment given X509 certificate [SAML2meta]. */

/* Called by:  zxid_idp_sso_desc x2, zxid_sp_sso_desc x2 */
struct zx_md_KeyDescriptor_s* zxid_key_desc(zxid_conf* cf, char* use, X509* x)
{
  struct zx_md_KeyDescriptor_s* kd = zx_NEW_md_KeyDescriptor(cf->ctx);
  kd->use = zx_ref_str(cf->ctx, use);
  kd->KeyInfo = zxid_key_info(cf, x);
  return kd;
}

/*() Generate Artifact Resolution (AR) Descriptor idp metadata fragment [SAML2meta]. */

/* Called by:  zxid_idp_sso_desc */
struct zx_md_ArtifactResolutionService_s* zxid_ar_desc(zxid_conf* cf,
						       char* binding, char* loc, char* resp_loc)
{
  struct zx_md_ArtifactResolutionService_s* d = zx_NEW_md_ArtifactResolutionService(cf->ctx);
  d->Binding = zx_ref_str(cf->ctx, binding);
  d->Location = zx_strf(cf->ctx, "%s%s", cf->url, loc);
  if (resp_loc)
    d->ResponseLocation = zx_strf(cf->ctx, "%s%s", cf->url, resp_loc);
  return d;
}

/*() Generate Single SignOn (SSO) Descriptor idp metadata fragment [SAML2meta]. */

/* Called by:  zxid_idp_sso_desc */
struct zx_md_SingleSignOnService_s* zxid_sso_desc(zxid_conf* cf,
						  char* binding, char* loc, char* resp_loc)
{
  struct zx_md_SingleSignOnService_s* d = zx_NEW_md_SingleSignOnService(cf->ctx);
  d->Binding = zx_ref_str(cf->ctx, binding);
  d->Location = zx_strf(cf->ctx, "%s%s", cf->url, loc);
  if (resp_loc)
    d->ResponseLocation = zx_strf(cf->ctx, "%s%s", cf->url, resp_loc);
  return d;
}

/*() Generate Single Logout (SLO) Descriptor metadata fragment [SAML2meta]. */

/* Called by:  zxid_idp_sso_desc x2, zxid_sp_sso_desc x2 */
struct zx_md_SingleLogoutService_s* zxid_slo_desc(zxid_conf* cf,
						  char* binding, char* loc, char* resp_loc)
{
  struct zx_md_SingleLogoutService_s* d = zx_NEW_md_SingleLogoutService(cf->ctx);
  d->Binding = zx_ref_str(cf->ctx, binding);
  d->Location = zx_strf(cf->ctx, "%s%s", cf->url, loc);
  if (resp_loc)
    d->ResponseLocation = zx_strf(cf->ctx, "%s%s", cf->url, resp_loc);
  return d;
}

/*() Generate Manage Name Id (MNI) Descriptor metadata fragment [SAML2meta]. */

/* Called by:  zxid_idp_sso_desc x2, zxid_sp_sso_desc x2 */
struct zx_md_ManageNameIDService_s* zxid_mni_desc(zxid_conf* cf,
						  char* binding, char* loc, char* resp_loc)
{
  struct zx_md_ManageNameIDService_s* d = zx_NEW_md_ManageNameIDService(cf->ctx);
  d->Binding = zx_ref_str(cf->ctx, binding);
  d->Location = zx_strf(cf->ctx, "%s%s", cf->url, loc);
  if (resp_loc)
    d->ResponseLocation = zx_strf(cf->ctx, "%s%s", cf->url, resp_loc);
  return d;
}

/*() Generate Assertion Consumer Service (SSO) Descriptor metadata fragment [SAML2meta]. */

/* Called by:  zxid_sp_sso_desc x5 */
struct zx_md_AssertionConsumerService_s* zxid_ac_desc(zxid_conf* cf,
						      char* binding, char* loc, char* ix)
{
  struct zx_md_AssertionConsumerService_s* d = zx_NEW_md_AssertionConsumerService(cf->ctx);
  d->Binding = zx_ref_str(cf->ctx, binding);
  d->Location = zx_strf(cf->ctx, "%s%s", cf->url, loc);
  d->index = zx_ref_str(cf->ctx, ix);
  return d;
}

/*() Generate SP SSO Descriptor metadata fragment [SAML2meta]. */

/* Called by:  zxid_sp_meta */
struct zx_md_SPSSODescriptor_s* zxid_sp_sso_desc(zxid_conf* cf)
{
  struct zx_md_AssertionConsumerService_s* za;
  struct zx_elem_s* ze;
  struct zx_md_ManageNameIDService_s* z3;
  struct zx_md_SingleLogoutService_s* z2;
  struct zx_md_KeyDescriptor_s* zk;
  struct zx_md_SPSSODescriptor_s* sp_ssod = zx_NEW_md_SPSSODescriptor(cf->ctx);
  sp_ssod->AuthnRequestsSigned        = zx_ref_str(cf->ctx, cf->authn_req_sign?"1":"0");
  sp_ssod->WantAssertionsSigned       = zx_ref_str(cf->ctx, cf->want_sso_a7n_signed?"1":"0");
  sp_ssod->errorURL                   = zx_strf(cf->ctx, "%s?o=E", cf->url);
  sp_ssod->protocolSupportEnumeration = zx_ref_str(cf->ctx, SAML2_PROTO);

  LOCK(cf->mx, "read certs for our md");
  if (!cf->enc_cert)
    cf->enc_cert = zxid_read_cert(cf, "enc-nopw-cert.pem");

  if (!cf->sign_cert)
    cf->sign_cert = zxid_read_cert(cf, "sign-nopw-cert.pem");

  if (!cf->enc_cert || !cf->sign_cert) {
    UNLOCK(cf->mx, "read certs for our md");
    ERR("Signing or encryption certificate not found (or both are corrupt). %p", cf->enc_cert);
  } else {
    zk = zxid_key_desc(cf, "encryption", cf->enc_cert);
    zk->gg.g.n = &sp_ssod->KeyDescriptor->gg.g;
    sp_ssod->KeyDescriptor = zk;
    
    zk = zxid_key_desc(cf, "signing", cf->sign_cert);
    zk->gg.g.n = &sp_ssod->KeyDescriptor->gg.g;
    sp_ssod->KeyDescriptor = zk;
    UNLOCK(cf->mx, "read certs for our md");
  }

  z2 = zxid_slo_desc(cf, SAML2_REDIR, "?o=Q", "?o=Q");
  z2->gg.g.n = &sp_ssod->SingleLogoutService->gg.g;
  sp_ssod->SingleLogoutService = z2;

  z2 = zxid_slo_desc(cf, SAML2_SOAP, "?o=S", 0);
  z2->gg.g.n = &sp_ssod->SingleLogoutService->gg.g;
  sp_ssod->SingleLogoutService = z2;

  z3 = zxid_mni_desc(cf, SAML2_REDIR, "?o=Q", "?o=Q");
  z3->gg.g.n = &sp_ssod->ManageNameIDService->gg.g;
  sp_ssod->ManageNameIDService = z3;

  z3 = zxid_mni_desc(cf, SAML2_SOAP, "?o=S", 0);
  z3->gg.g.n = &sp_ssod->ManageNameIDService->gg.g;
  sp_ssod->ManageNameIDService = z3;

  ze = zx_ref_simple_elem(cf->ctx, SAML2_PERSISTENT_NID_FMT);
  ze->g.n = &sp_ssod->NameIDFormat->g;
  sp_ssod->NameIDFormat = ze;

  ze = zx_ref_simple_elem(cf->ctx, SAML2_TRANSIENT_NID_FMT);
  ze->g.n = &sp_ssod->NameIDFormat->g;
  sp_ssod->NameIDFormat = ze;

  /* N.B. The index values should not be changed. They are used in
   * AuthnReq to choose profile using AssertionConsumerServiceIndex */

  za = zxid_ac_desc(cf, SAML2_POST_SIMPLE_SIGN, "?o=P", "5");
  za->gg.g.n = &sp_ssod->AssertionConsumerService->gg.g;
  sp_ssod->AssertionConsumerService = za;

  za = zxid_ac_desc(cf, SAML2_PAOS, "?o=P", "4");
  za->gg.g.n = &sp_ssod->AssertionConsumerService->gg.g;
  sp_ssod->AssertionConsumerService = za;

  za = zxid_ac_desc(cf, SAML2_SOAP, "?o=S", "3");
  za->gg.g.n = &sp_ssod->AssertionConsumerService->gg.g;
  sp_ssod->AssertionConsumerService = za;

  za = zxid_ac_desc(cf, SAML2_POST, "?o=P", "2");
  za->gg.g.n = &sp_ssod->AssertionConsumerService->gg.g;
  sp_ssod->AssertionConsumerService = za;

  za = zxid_ac_desc(cf, SAML2_ART, "", "1");
  za->gg.g.n = &sp_ssod->AssertionConsumerService->gg.g;
  sp_ssod->AssertionConsumerService = za;
  
  return sp_ssod;
}

/*() Generate IdP SSO Descriptor metadata fragment [SAML2meta]. */

/* Called by:  zxid_sp_meta */
struct zx_md_IDPSSODescriptor_s* zxid_idp_sso_desc(zxid_conf* cf)
{
  /*struct zx_md_ArtifactResolutionService_s* z5;*/
  struct zx_elem_s* ze;
  /*struct zx_md_ManageNameIDService_s* z3;*/
  struct zx_md_SingleLogoutService_s* z2;
  struct zx_md_SingleSignOnService_s* z4;
  struct zx_md_KeyDescriptor_s* zk;
  struct zx_md_IDPSSODescriptor_s* idp_ssod = zx_NEW_md_IDPSSODescriptor(cf->ctx);
  idp_ssod->WantAuthnRequestsSigned    = zx_ref_str(cf->ctx, cf->want_authn_req_signed?"1":"0");
  idp_ssod->errorURL                   = zx_strf(cf->ctx, "%s?o=E", cf->url);
  idp_ssod->protocolSupportEnumeration = zx_ref_str(cf->ctx, SAML2_PROTO);

  LOCK(cf->mx, "read certs for our md idp");
  if (!cf->enc_cert)
    cf->enc_cert = zxid_read_cert(cf, "enc-nopw-cert.pem");

  if (!cf->sign_cert)
    cf->sign_cert = zxid_read_cert(cf, "sign-nopw-cert.pem");

  if (!cf->enc_cert || !cf->sign_cert) {
    UNLOCK(cf->mx, "read certs for our md idp");
    ERR("Signing or encryption certificate not found (or both are corrupt). %p", cf->enc_cert);
  } else {
    zk = zxid_key_desc(cf, "encryption", cf->enc_cert);
    zk->gg.g.n = &idp_ssod->KeyDescriptor->gg.g;
    idp_ssod->KeyDescriptor = zk;
    
    zk = zxid_key_desc(cf, "signing", cf->sign_cert);
    zk->gg.g.n = &idp_ssod->KeyDescriptor->gg.g;
    idp_ssod->KeyDescriptor = zk;
    UNLOCK(cf->mx, "read certs for our md idp");
  }

#if 0
  /* *** NI */
  z5 = zxid_ar_desc(cf, SAML2_SOAP, "?o=S", 0);
  z5->gg.g.n = &idp_ssod->ArtifactResolutionService->gg.g;
  idp_ssod->ArtifactResolutionService = z5;
#endif

  z2 = zxid_slo_desc(cf, SAML2_REDIR, "?o=Q", "?o=Q");
  z2->gg.g.n = &idp_ssod->SingleLogoutService->gg.g;
  idp_ssod->SingleLogoutService = z2;

  z2 = zxid_slo_desc(cf, SAML2_SOAP, "?o=S", 0);
  z2->gg.g.n = &idp_ssod->SingleLogoutService->gg.g;
  idp_ssod->SingleLogoutService = z2;

#if 0
  /* *** NI */
  z3 = zxid_mni_desc(cf, SAML2_REDIR, "?o=Q", "?o=Q");
  z3->gg.g.n = &idp_ssod->ManageNameIDService->gg.g;
  idp_ssod->ManageNameIDService = z3;

  z3 = zxid_mni_desc(cf, SAML2_SOAP, "?o=S", 0);
  z3->gg.g.n = &idp_ssod->ManageNameIDService->gg.g;
  idp_ssod->ManageNameIDService = z3;
#endif

  ze = zx_ref_simple_elem(cf->ctx, SAML2_PERSISTENT_NID_FMT);
  ze->g.n = &idp_ssod->NameIDFormat->g;
  idp_ssod->NameIDFormat = ze;

  ze = zx_ref_simple_elem(cf->ctx, SAML2_TRANSIENT_NID_FMT);
  ze->g.n = &idp_ssod->NameIDFormat->g;
  idp_ssod->NameIDFormat = ze;

  z4 = zxid_sso_desc(cf, SAML2_REDIR, "?o=F", 0);
  z4->gg.g.n = &idp_ssod->SingleSignOnService->gg.g;
  idp_ssod->SingleSignOnService = z4;

  return idp_ssod;
}

/*() Generate Organization metadata fragment [SAML2meta]. */

/* Called by:  zxid_sp_meta */
struct zx_md_Organization_s* zxid_org_desc(zxid_conf* cf)
{
  struct zx_md_Organization_s* org = zx_NEW_md_Organization(cf->ctx);
  org->OrganizationDisplayName = zx_NEW_md_OrganizationDisplayName(cf->ctx);
  org->OrganizationDisplayName->lang = zx_ref_str(cf->ctx, "en");  /* *** config */
  org->OrganizationDisplayName->gg.content = zx_ref_str(cf->ctx, STRNULLCHKQ(cf->nice_name));

  org->OrganizationName = zx_NEW_md_OrganizationName(cf->ctx);
  org->OrganizationName->lang = zx_ref_str(cf->ctx, "en");  /* *** config */
  if (cf->org_name && cf->org_name[0])
    org->OrganizationName->gg.content = zx_ref_str(cf->ctx, cf->org_name);
  else
    org->OrganizationName->gg.content = zx_ref_str(cf->ctx, STRNULLCHKQ(cf->nice_name));

  org->OrganizationURL = zx_NEW_md_OrganizationURL(cf->ctx);
  org->OrganizationURL->lang = zx_ref_str(cf->ctx, "en");  /* *** config */
  if (cf->org_url && cf->org_url[0])
    org->OrganizationURL->gg.content = zx_ref_str(cf->ctx, cf->org_url);
  else
    org->OrganizationURL->gg.content = zx_ref_str(cf->ctx, cf->url);

  return org;
}

/*() Generate Contact Person metadata fragment [SAML2meta]. */

/* Called by:  zxid_sp_meta */
struct zx_md_ContactPerson_s* zxid_contact_desc(zxid_conf* cf)
{
  struct zx_md_ContactPerson_s* contact = zx_NEW_md_ContactPerson(cf->ctx);

  if (cf->contact_org) {
    if (cf->contact_org[0])
      contact->Company = zx_ref_simple_elem(cf->ctx, cf->contact_org);
  } else
    if (cf->org_name && cf->org_name[0])
      contact->Company = zx_ref_simple_elem(cf->ctx, cf->org_name);
    else
      contact->Company
	= zx_ref_simple_elem(cf->ctx, STRNULLCHKQ(cf->nice_name));

  if (cf->contact_name && cf->contact_name[0])
    contact->SurName = zx_ref_simple_elem(cf->ctx, cf->contact_name);
  if (cf->contact_email && cf->contact_email[0])
    contact->EmailAddress = zx_ref_simple_elem(cf->ctx, cf->contact_email);
  if (cf->contact_tel && cf->contact_tel[0])
    contact->TelephoneNumber = zx_ref_simple_elem(cf->ctx, cf->contact_tel);

  return contact;
}

/*(i) Primary interface to our own Entity ID. While this would usually be
 * automatically generated from URL configuration option so as to conform
 * to the Well Known Location (WKL) metadata exchange convention [SAML2meta],
 * on some sites the entity ID may be different and thus everybody who
 * does not know better should use this interface to obtain it.
 *
 * cf:: ZXID configuration object, used to compute EntityID and also for memory allocation
 * return:: Entity ID as zx_str */

/* Called by:  main x2, zxid_check_fed, zxid_di_query, zxid_idp_select_zxstr_cf_cgi, zxid_map_bangbang, zxid_mk_ecp_Request_hdr, zxid_mk_subj, zxid_my_issuer, zxid_ses_to_pool, zxid_show_conf, zxid_sp_meta, zxid_sp_sso_finalize, zxid_validate_cond, zxid_wsf_decor, zxid_wsf_validate_a7n */
struct zx_str* zxid_my_entity_id(zxid_conf* cf)
{
  if (cf->non_standard_entityid) {
    D("my_entity_id non_standard_entytid(%s)", cf->non_standard_entityid);
    return zx_strf(cf->ctx, "%s", cf->non_standard_entityid);
  } else if (cf->bare_url_entityid) {
    D("my_entity_id bare url(%s)", cf->url);
    return zx_strf(cf->ctx, "%s", cf->url);
  } else {
    D("my_entity_id url(%s)", cf->url);
    return zx_strf(cf->ctx, "%s?o=B", cf->url);
  }
}

/*() Dynamically determine our Common Domain Cookie (IdP discovery) URL. */

/* Called by: */
struct zx_str* zxid_my_cdc_url(zxid_conf* cf)
{
  return zx_strf(cf->ctx, "%s?o=C", cf->cdc_url);
}

/*() Generate Issuer value. Issuer is often same as Entity ID, but sometimes
 * it will be affiliation ID. This function is a low level interface. Usually
 * you would want to use zxid_my_issuer(). */

/* Called by:  zxid_my_issuer */
struct zx_sa_Issuer_s* zxid_issuer(zxid_conf* cf, struct zx_str* nameid, char* affiliation)
{
  struct zx_sa_Issuer_s* is = zx_NEW_sa_Issuer(cf->ctx);
  is->gg.content = nameid;
  if (affiliation && affiliation[0])
    is->NameQualifier = zx_ref_str(cf->ctx, affiliation);
  /*is->Format = zx_ref_str(cf->ctx, );*/
  return is;
}

/*() Generate Issuer value for our entity. Issuer is often same as Entity ID, but sometimes
 * it will be affiliation ID. */

/* Called by:  zxid_mk_a7n, zxid_mk_art_deref, zxid_mk_authn_req, zxid_mk_az, zxid_mk_az_cd1, zxid_mk_ecp_Request_hdr, zxid_mk_logout, zxid_mk_logout_resp, zxid_mk_mni, zxid_mk_mni_resp, zxid_mk_saml_resp */
struct zx_sa_Issuer_s* zxid_my_issuer(zxid_conf* cf) {
  return zxid_issuer(cf, zxid_my_entity_id(cf), cf->affiliation);
}

/*() Generate our SP metadata and return it as a string. */

/* Called by:  zxid_send_sp_meta, zxid_simple_show_meta */
struct zx_str* zxid_sp_meta(zxid_conf* cf, zxid_cgi* cgi)
{
  struct zx_md_EntityDescriptor_s* ed;
  
  ed = zx_NEW_md_EntityDescriptor(cf->ctx);
  ed->entityID = zxid_my_entity_id(cf);
  ed->SPSSODescriptor = zxid_sp_sso_desc(cf);
  if (cf->idp_ena)
    ed->IDPSSODescriptor = zxid_idp_sso_desc(cf);
  ed->Organization = zxid_org_desc(cf);
  ed->ContactPerson = zxid_contact_desc(cf);
  
  if (cf->log_level>0)
    zxlog(cf, 0, 0, 0, 0, 0, 0, 0, "N", "W", "MYMD", 0, 0);
  return zx_EASY_ENC_SO_md_EntityDescriptor(cf->ctx, ed);
}

/*() Generate our SP metadata and send it to remote partner.
 *
 * Limitation:: This function only works with CGI as it will print the
 *     serialized metadata straight to stdout. There are other
 *     methods for getting metadat without this limitation, e.g. zxid_sp_meta() */

/* Called by:  main x2, opt x2 */
int zxid_send_sp_meta(zxid_conf* cf, zxid_cgi* cgi)
{
  struct zx_str* ss = zxid_sp_meta(cf, cgi);
  if (!ss)
    return 0;
  //write_all_fd(1, ss->s, ss->len);
  write_all_fd(fileno(stdout), ss->s, ss->len);
  zx_str_free(cf->ctx, ss);
  return 0;
}

/* ------- CARML ------- */

/*() Generate our SP CARML and return it as a string. */

/* Called by:  zxid_simple_show_carml */
struct zx_str* zxid_sp_carml(zxid_conf* cf)
{
  if (cf->log_level>0)
    zxlog(cf, 0, 0, 0, 0, 0, 0, 0, "N", "W", "MYCARML", 0, 0);

  /* *** Much work needed to study CARML spec and to convert need and want to comply */

  return zx_strf(cf->ctx,
"<carml:ClientAttrReq"
" AppName=\"ZXID SP\""
" Description=\"ZXID SP Attribute Needs and Wants\""
" xmlns:carml=\"urn:igf:client:0.9:carml\">"
"<carml:DataDefs>"

"  <carml:Attributes>"
"  </carml:Attributes>"

"  <carml:Predicates>"
"  </carml:Predicates>"

"  <carml:Roles>"
"  </carml:Roles>"

"  <carml:Policies>"
"  </carml:Policies>"

"</carml:DataDefs>"

"<carml:ReadInteraction/>"
"<carml:FindInteraction/>"
"<carml:SearchInteraction/>"
"<carml:CompareInteraction/>"
"<carml:ModifyInteraction/>"
"<carml:AddInteraction/>"

"</carml:ClientAttrReq>"
		 );
}

/* EOF  --  zxidmeta.c */
