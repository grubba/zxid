/* zxidpsso.c  -  Handwritten functions for implementing Single Sign-On logic on IdP
 * Copyright (c) 2009-2010 Sampo Kellomaki (sampo@iki.fi), All Rights Reserved.
 * Copyright (c) 2008-2009 Sampo Kellomaki (sampo@iki.fi), All Rights Reserved.
 * This is confidential unpublished proprietary source code of the author.
 * NO WARRANTY, not even implied warranties. Contains trade secrets.
 * Distribution prohibited unless authorized in writing.
 * Licensed under Apache License 2.0, see file COPYING.
 * $Id: zxidpsso.c,v 1.16 2010-01-08 02:10:09 sampo Exp $
 *
 * 14.11.2008, created --Sampo
 * 4.9.2009,   added persistent nameid support --Sampo
 * 24.11.2009, fixed handling of transient nameid --Sampo
 * 12.2.2010,  added locking to lazy loading --Sampo
 *
 * See also: http://hoohoo.ncsa.uiuc.edu/cgi/interface.html (CGI specification)
 */

#include <sys/stat.h>
#include <dirent.h>
#include <errno.h>

#include "errmac.h"
#include "zxid.h"
#include "zxidconf.h"
#include "saml2.h"
#include "wsf.h"
#include "c/zxidvers.h"
#include "c/zx-const.h"
#include "c/zx-ns.h"
#include "c/zx-data.h"

/*() Helper function to sign, if needed, and log the issued assertion.
 * Checks for Assertion ID duplicate and returns 0 on
 * failure (i.e. duplicate), 1 on success. */

/* Called by:  zxid_add_fed_tok_to_epr, zxid_idp_sso x3 */
int zxid_anoint_a7n(struct zxid_conf* cf, int sign, struct zx_sa_Assertion_s* a7n, struct zx_str* issued_to, const char* lk)
{
  X509* sign_cert;
  RSA*  sign_pkey;
  struct zxsig_ref refs;
  struct zx_str* ss;
  struct zx_str* logpath;
  struct timeval ourts;
  GETTIMEOFDAY(&ourts, 0);
  
  if (sign) {
    refs.id = a7n->ID;
    refs.canon = zx_EASY_ENC_SO_sa_Assertion(cf->ctx, a7n);
    if (zxid_lazy_load_sign_cert_and_pkey(cf, &sign_cert, &sign_pkey, "use sign cert anoint a7n"))
      a7n->Signature = zxsig_sign(cf->ctx, 1, &refs, sign_cert, sign_pkey);
    zx_str_free(cf->ctx, refs.canon);
  }
  
  /* Log the issued a7n */

  zxlog(cf, &ourts, &ourts, 0, issued_to, 0, a7n->ID,
	(a7n->Subject->NameID && a7n->Subject->NameID->gg.content
	 ?a7n->Subject->NameID->gg.content
	 :(zx_dup_str(cf->ctx, (a7n->Subject->EncryptedID?"ENC":"-")))),
	sign?"U":"N", "K", lk, "-", 0);
  
  if (cf->log_issue_a7n) {
    logpath = zxlog_path(cf, issued_to, a7n->ID, ZXLOG_ISSUE_DIR, ZXLOG_A7N_KIND, 1);
    if (logpath) {
      ss = zx_EASY_ENC_SO_sa_Assertion(cf->ctx, a7n);
      if (zxlog_dup_check(cf, logpath, "IdP POST Assertion")) {
	ERR("Duplicate Assertion ID(%.*s)", a7n->ID->len, a7n->ID->s);
	if (cf->dup_a7n_fatal) {
	  ERR("FATAL (by configuration): Duplicate Assertion ID(%.*s)", a7n->ID->len, a7n->ID->s);
	  zxlog_blob(cf, 1, logpath, ss, "anoint_a7n dup");
	  zx_str_free(cf->ctx, ss);
	  zx_str_free(cf->ctx, logpath);
	  return 0;
	}
      }
      zxlog_blob(cf, 1, logpath, ss, "anoint_a7n");
      zx_str_free(cf->ctx, logpath);
    }
  }
  zx_str_free(cf->ctx, ss);
  return 1;
}

/*() Helper function to sign, if needed, and log the issued response.
 * Checks for message ID duplicate and returns 0 on failure (i.e. duplicate),
 * or the canonicalized response message string on success. This string
 * may be useful for caller to send further and should be freed by the caller. */

/* Called by:  zxid_idp_sso x4 */
static struct zx_str* zxid_anoint_sso_resp(struct zxid_conf* cf, int sign, struct zx_sp_Response_s* resp, struct zx_sp_AuthnRequest_s* ar)
{
  X509* sign_cert;
  RSA*  sign_pkey;
  struct zxsig_ref refs;
  struct zx_str* ss;
  struct zx_str* logpath;
  struct timeval ourts;
  GETTIMEOFDAY(&ourts, 0);
  
  if (sign) {
    refs.id = resp->ID;
    refs.canon = zx_EASY_ENC_SO_sp_Response(cf->ctx, resp);
    if (zxid_lazy_load_sign_cert_and_pkey(cf, &sign_cert, &sign_pkey, "use sign cert anoint resp"))
      resp->Signature = zxsig_sign(cf->ctx, 1, &refs, sign_cert, sign_pkey);
    zx_str_free(cf->ctx, refs.canon);
  }
  
  /* Log the issued Response */
  
  zxlog(cf, &ourts, &ourts, 0, ar->Issuer->gg.content, resp->ID,
	resp->Assertion&&resp->Assertion->ID?resp->Assertion->ID:zx_dup_str(cf->ctx, "-"),
	(resp->Assertion
	 ?(resp->Assertion->Subject->NameID && resp->Assertion->Subject->NameID->gg.content
	   ?resp->Assertion->Subject->NameID->gg.content
	   :(zx_dup_str(cf->ctx, (resp->Assertion->Subject->EncryptedID?"ENC":"-"))))
	 :zx_dup_str(cf->ctx,"-")),
	sign?"U":"N", "K", "SSORESP", "-", 0);

  if (cf->log_issue_msg) {
    logpath = zxlog_path(cf, ar->Issuer->gg.content, resp->ID, ZXLOG_ISSUE_DIR, ZXLOG_MSG_KIND,1);
    if (logpath) {
      ss = zx_EASY_ENC_SO_sp_Response(cf->ctx, resp);
      if (zxlog_dup_check(cf, logpath, "IdP POST Response")) {
	ERR("Duplicate Response ID(%.*s)", resp->ID->len, resp->ID->s);
	if (cf->dup_msg_fatal) {
	  ERR("FATAL (by configuration): Duplicate Response ID(%.*s)", resp->ID->len, resp->ID->s);
	  zxlog_blob(cf, 1, logpath, ss, "anoint_sso_resp dup");
	  zx_str_free(cf->ctx, ss);
	  zx_str_free(cf->ctx, logpath);
	  return 0;
	}
      }
      zxlog_blob(cf, 1, logpath, ss, "anoint_sso_resp");
      zx_str_free(cf->ctx, logpath);
    }
  }
  return ss;
}

/*() Parse LDIF format and insert attributes to linked list. Return new head of the list.
 * *** illegal input causes corrupt pointer. For example query string input causes corruption. */

/* Called by:  zxid_mk_user_a7n_to_sp x4 */
struct zx_sa_Attribute_s* zxid_add_ldif_attrs(struct zxid_conf* cf, struct zx_sa_Attribute_s* prev, int len, char* p, char* lk)
{
  struct zx_sa_Attribute_s* at;
  char* name;
  char* val;

  for (; p; ++p) {
    name = p;
    p = strstr(p, ": ");
    if (!p)
      break;
    *p = 0;
    val = p+2;
    p = strchr(val, '\n');  /* *** parsing LDIF is fragile if values are multiline */
    if (p)
      *p = 0;

    D("%s: ATTR(%s)=VAL(%s)", lk, name, val);
    at = zxid_mk_attribute(cf, name, val);
    ZX_NEXT(at) = (void*)prev;
    prev = at;

    val[-2] = ':'; /* restore */
    if (*p)
      *p = '\n';
  }
  return at;
}

#define ZXID_ADD_BS_LVL_LIM 2  /* 2=only add full bootstraps on SSO. Only add di there after. */

/*() Process .bs directory. See also zxid_di_query() */

/* Called by:  zxid_idp_as_do x2, zxid_mk_user_a7n_to_sp x2 */
struct zx_sa_Attribute_s* zxid_gen_boots(struct zxid_conf* cf, const char* uid, char* path, struct zx_sa_Attribute_s* bootstraps, int bs_lvl)
{
  struct timeval srcts = {0,501000};
  struct zx_sa_Attribute_s* at;
  struct zx_a_EndpointReference_s* epr;
  struct zx_root_s* r;
  DIR* dir;
  struct dirent * de;
  char mdpath[ZXID_MAX_BUF];
  char* logop;
  char* epr_buf;
  int epr_len;
  int is_di;

  D_INDENT("gen_bs: ");

  if (!bs_lvl) {
    D("bs_lvl=%d: nothing to add", bs_lvl);
    D_DEDENT("gen_bs: ");
    return bootstraps;  /* Discovery EPRs do not need any bootstraps. */
  }
  
  name_from_path(mdpath, sizeof(mdpath), "%s" ZXID_DIMD_DIR, cf->path);
  D("Looking for service metadata in dir(%s) bs_lvl=%d", mdpath, bs_lvl);
  
  dir = opendir(path);
  if (!dir) {
    perror("opendir to find bootstraps");
    ERR("Opening bootstrap directory failed path(%s)", path);
    D_DEDENT("gen_bs: ");
    return bootstraps;
  }
  
  while (de = readdir(dir)) {
    D("Considering bootstrap file(%s%s)", path, de->d_name);
    
    if (de->d_name[strlen(de->d_name)-1] == '~')  /* Ignore backups from hand edited EPRs. */
      continue;
    if (de->d_name[0] == '.')  /* Ignore hidden files. */
      continue;
    
    /* Probable enough, read and parse EPR so we can continue examination. */
    
    epr_buf = ZX_ALLOC(cf->ctx, ZXID_INIT_EPR_BUF);
    epr_len = read_all(ZXID_INIT_EPR_BUF, epr_buf, "find_bs_svcmd", "%s/%s", mdpath, de->d_name);
    if (!epr_len) {
      ERR("User's (%s) bootstrap(%s) lacks service metadata registration. Reject. Consider using zxcot -e ... | zxcot -bs. See zxid-idp.pd for further information.", uid, de->d_name);
      ZX_FREE(cf->ctx, epr_buf);
      continue;
    }
    LOCK(cf->ctx->mx, "gen boots");
    zx_prepare_dec_ctx(cf->ctx, zx_ns_tab, epr_buf, epr_buf + epr_len);
    r = zx_DEC_root(cf->ctx, 0, 1);
    UNLOCK(cf->ctx->mx, "gen boots");
    if (!r) {
      ERR("Failed to XML parse epr_buf(%.*s) file(%s)", epr_len, epr_buf, de->d_name);
      ZX_FREE(cf->ctx, epr_buf);
      continue;
    }
    /* *** add ID-WSF 1.1 handling */
    epr = r->EndpointReference;
    ZX_FREE(cf->ctx, r);

    if (!epr || !epr->Metadata || !epr->Metadata->ServiceType
	|| !epr->Metadata->ServiceType->content || !epr->Metadata->ServiceType->content->s) {
      ERR("No EPR, corrupt EPR, or missing <Metadata> %p or <ServiceType>. epr_buf(%.*s) file(%s)", epr->Metadata, epr_len, epr_buf, de->d_name);
      ZX_FREE(cf->ctx, epr_buf);
      continue;
    }
    is_di = !memcmp(epr->Metadata->ServiceType->content->s, XMLNS_DISCO_2_0,
		    epr->Metadata->ServiceType->content->len);
    D("FOUND BOOTSTRAP url(%.*s) is_di=%d", epr->Address->gg.content->len, epr->Address->gg.content->s, is_di);
    
    if (is_di) {
      logop = zxid_add_fed_tok_to_epr(cf, epr, uid, 0); /* recurse, di tail */
    } else if (bs_lvl > cf->bootstrap_level) {
      D("No further bootstraps generated due to boostrap_level=%d (except di boostraps)", bs_lvl);
      ZX_FREE(cf->ctx, epr_buf);
      continue;
    } else
      logop = zxid_add_fed_tok_to_epr(cf, epr, uid, bs_lvl+1); /* recurse */
    D("bs_lvl=%d: adding logop(%s)", bs_lvl, STRNULLCHK(logop));
    if (!logop)
      goto next_file;
    
    D("ADD BOOTSTRAP url(%.*s) is_di=%d", epr->Address->gg.content->len, epr->Address->gg.content->s, is_di);
    at = zxid_mk_attribute(cf, WSF20_DI_RO, 0);
    at->AttributeValue->EndpointReference = epr;
    ZX_NEXT(at) = (void*)bootstraps;
    bootstraps = at;
    
    zxlog(cf, 0, &srcts, 0, 0, 0, 0 /*a7n->ID*/, 0 /*nameid->gg.content*/,"N","K", logop, uid, "gen_bs");
    
  next_file:
    continue;
  }
  
  closedir(dir);
  D_DEDENT("gen_bs: ");
  return bootstraps;
}

/*(i) Construct an assertion given user's attribute and bootstrap configuration.
 * bs_lvl:: 0: DI (do not add any bs), 1: add all bootstraps at sso level,
 *     <= cf->bootstrap_level: add all boostraps, > cf->bootstrap_level: only add di BS. */

/* Called by:  zxid_add_fed_tok_to_epr, zxid_idp_sso */
struct zx_sa_Assertion_s* zxid_mk_user_a7n_to_sp(struct zxid_conf* cf, struct zxid_ses* ses, const char* uid, struct zx_sa_NameID_s* nameid, struct zxid_entity* sp_meta, const char* sp_name_buf, int bs_lvl)
{
  struct zx_sa_Assertion_s* a7n;
  struct zx_sa_Subject_s* subj;
  struct zx_sa_AuthnStatement_s* an_stmt;
  struct zx_sa_AttributeStatement_s* at_stmt;
  char buf[ZXID_MAX_USER];
  int got;

  D_INDENT("mka7n: ");
  D("sp_eid(%.*s)", sp_meta->eid_len, sp_meta->eid);

  subj = zxid_mk_subj(cf, sp_meta, nameid);
  an_stmt = ses ? zxid_mk_an_stmt(cf, ses) : 0;
  at_stmt = zx_NEW_sa_AttributeStatement(cf->ctx);
  at_stmt->Attribute = zxid_mk_attribute(cf, "zxididp", ZXID_REL " " ZXID_COMPILE_DATE);

  got = read_all(sizeof(buf)-1, buf, "idpsso_uid_at", "%s" ZXID_UID_DIR "%s/.bs/.at" , cf->path, uid);
  if (got) {
    at_stmt->Attribute = zxid_add_ldif_attrs(cf, at_stmt->Attribute, got, buf, "idpsso_uid_at");
  }

  got = read_all(sizeof(buf)-1, buf, "idpsso_uid_sp_at", "%s" ZXID_UID_DIR "%s/%s/.at" , cf->path, uid, sp_name_buf);
  if (got) {
    at_stmt->Attribute = zxid_add_ldif_attrs(cf, at_stmt->Attribute, got, buf, "idpsso_uid_sp_at");
  }

  got = read_all(sizeof(buf)-1, buf, "idpsso_all_at", "%s" ZXID_UID_DIR ".all/.bs/.at" , cf->path);
  if (got) {
    at_stmt->Attribute = zxid_add_ldif_attrs(cf, at_stmt->Attribute, got, buf, "idpsso_all_at");
  }

  got = read_all(sizeof(buf)-1, buf, "idpsso_all_sp_at", "%s" ZXID_UID_DIR ".all/%s/.at" , cf->path, sp_name_buf);
  if (got) {
    at_stmt->Attribute = zxid_add_ldif_attrs(cf, at_stmt->Attribute, got, buf, "idpsso_all_sp_at");
  }
  D("sp_eid(%.*s) bs_lvl=%d", sp_meta->eid_len, sp_meta->eid, bs_lvl);
  
  /* Process bootstraps */

  name_from_path(buf, sizeof(buf), "%s" ZXID_UID_DIR "%s/.bs/", cf->path, uid);
  at_stmt->Attribute = zxid_gen_boots(cf, uid, buf, at_stmt->Attribute, bs_lvl);
  
  name_from_path(buf, sizeof(buf), "%s" ZXID_UID_DIR ".all/.bs/", cf->path);
  at_stmt->Attribute = zxid_gen_boots(cf, uid, buf, at_stmt->Attribute, bs_lvl);
  
  D("sp_eid(%.*s)", sp_meta->eid_len, sp_meta->eid);
  a7n = zxid_mk_a7n(cf, zx_dup_len_str(cf->ctx, sp_meta->eid_len, sp_meta->eid), subj, an_stmt, at_stmt, 0);
  D_DEDENT("mka7n: ");
  return a7n;
}

/*(i) Check federation, create federation if appropriate. */

/* Called by:  zxid_add_fed_tok_to_epr, zxid_idp_sso */
struct zx_sa_NameID_s* zxid_check_fed(struct zxid_conf* cf, struct zx_str* affil, const char* uid, char allow_create, struct timeval* srcts, struct zx_str* issuer, struct zx_str* req_id, const char* sp_name_buf)
{
  int got;
  char buf[ZXID_MAX_USER];
  char dir[ZXID_MAX_DIR];
  struct zx_sa_NameID_s* nameid;
  struct zx_str* nid;
  struct zx_str* idp_eid;

  got = read_all(sizeof(buf)-1, buf, "idpsso", "%s" ZXID_UID_DIR "%s/%s/.mni" , cf->path, uid, sp_name_buf);

  if (!got) {
    if (allow_create == '1') {

      D_INDENT("allowcreate: ");
      
      name_from_path(dir, sizeof(dir), "%s" ZXID_UID_DIR "%s/%s", cf->path, uid, sp_name_buf);
      if (MKDIR(dir, 0777) && errno != EEXIST) {
	perror("mkdir for uid/sp fed");
	ERR("Creating uid/sp federation directory(%s) failed", dir);
	zxlog(cf, 0, srcts, 0, issuer, req_id, 0, nid, "N", "S", "EFILE", dir, "mkdir fail, permissions?");
	D_DEDENT("allowcreate: ");
	return 0;
      }
      idp_eid = zxid_my_entity_id(cf);
      nid = zxid_mk_id(cf, "F", ZXID_ID_BITS);
      nameid = zx_NEW_sa_NameID(cf->ctx);
      nameid->Format = zx_ref_str(cf->ctx, SAML2_PERSISTENT_NID_FMT);
      nameid->NameQualifier = idp_eid;
      nameid->SPNameQualifier = affil;
      nameid->gg.content = nid;

      if (!write_all_path_fmt("put_fed", ZXID_MAX_USER, buf,
			      "%s%s", dir, "/.mni",
			      "%.*s|%.*s|%.*s|%.*s|",
			      sizeof(SAML2_PERSISTENT_NID_FMT), SAML2_PERSISTENT_NID_FMT,
			      idp_eid->len, idp_eid->s,
			      affil->len, affil->s,
			      nid->len, nid->s)) {
	zxlog(cf, 0, srcts, 0, issuer, req_id, 0, nid, "N", "S", "EFILE", uid, "put_fed fail, permissions?");
	D_DEDENT("allowcreate: ");
	return 0;
      }

      /* Create entry for reverse mapping from pseudonym nid to uid */

      name_from_path(dir, sizeof(dir), "%s" ZXID_NID_DIR "%s", cf->path, sp_name_buf);
      if (MKDIR(dir, 0777) && errno != EEXIST) {
	perror("mkdir for nid fed");
	ERR("Creating nid index directory(%s) failed", dir);
	zxlog(cf, 0, srcts, 0, issuer, req_id, 0, nid, "N", "S", "EFILE", dir, "mkdir fail, permissions?");
	D_DEDENT("allowcreate: ");
	return 0;
      }
      
      name_from_path(dir, sizeof(dir), "%s" ZXID_NID_DIR "%s/%.*s", cf->path, sp_name_buf, nid->len, nid->s);
      if (!write_all_path_fmt("put_nidmap", ZXID_MAX_USER, buf, "%s", dir, 0, "%s", uid)) {
	zxlog(cf, 0, srcts, 0, issuer, req_id, 0, nid, "N", "S", "EFILE", uid, "put_nidmap fail, permissions?");
	D_DEDENT("allowcreate: ");
	return 0;
      }
      
      zxlog(cf, 0, srcts, 0, issuer, req_id, 0, nid, "N", "K", "FEDNEW", uid, 0);
      D_DEDENT("allowcreate: ");

    } else {
      ERR("No federation for uid(%s) in affil(%.*s) and AllowCreate false %d", uid, affil->len, affil->s, allow_create);
      return 0;
    }
  } else {
    buf[got] = 0;
    nameid = zxid_parse_mni(cf, buf, 0);
    D("Old fed uid(%s) affil(%.*s) nid(%.*s)", uid, affil->len, affil->s, nameid->gg.content->len, nameid->gg.content->s);
  }

  if (!nameid) {
    ERR("No federation for affil(%.*s) and AllowCreate false %d", affil->len, affil->s, allow_create);
    return 0;
  }
  return nameid;
}

/*() Change NameID to be transient and record corresponding mapping. */

/* Called by:  zxid_add_fed_tok_to_epr x2, zxid_idp_sso x2 */
void zxid_mk_transient_nid(struct zxid_conf* cf, struct zx_sa_NameID_s* nameid, const char* sp_name_buf, const char* uid)
{
  struct zx_str* nid;
  char buf[ZXID_MAX_USER];
  char dir[ZXID_MAX_DIR];

  D_INDENT("mk_trans: ");
  nameid->Format = zx_dup_str(cf->ctx, SAML2_TRANSIENT_NID_FMT);
  nameid->gg.content = nid = zxid_mk_id(cf, "T", ZXID_ID_BITS);
  
  /* Create entry for reverse mapping from pseudonym nid to uid */
  
  name_from_path(dir, sizeof(dir), "%s" ZXID_NID_DIR "%s", cf->path, sp_name_buf);
  if (MKDIR(dir, 0777) && errno != EEXIST) {
    perror("mkdir for nid tmp");
    ERR("Creating nid index directory(%s) failed", dir);
    zxlog(cf, 0, 0, 0, 0, 0, 0, nid, "N", "S", "EFILE", dir, "mkdir fail, permissions?");
    D_DEDENT("mk_trans: ");
    return;
  }
  
  name_from_path(dir, sizeof(dir), "%s" ZXID_NID_DIR "%s/%.*s", cf->path, sp_name_buf, nid->len, nid->s);
  if (!write_all_path_fmt("put_nidmap_tmp", ZXID_MAX_USER, buf, "%s", dir, 0, "%s", uid)) {
    zxlog(cf, 0, 0, 0, 0, 0, 0, nid, "N", "S", "EFILE", uid, "put_nidmap fail, permissions?");
    D_DEDENT("mk_trans: ");
    return;
  }
  
  /*zxlog(cf, 0, srcts, 0, issuer, req_id, 0, nid, "N", "K", "TMPNEW", uid, 0);*/
  D_DEDENT("mk_trans: ");
}

/*() Consider an EPR and user and generate the necessary access credential (SAML a7n).
 * The EPR is modified in place. Returns logging keyword indicating which kind of token
 * was issued. Returns static string describing the nature of token, for logging purposes. */

/* Called by:  zxid_di_query, zxid_gen_boots x2 */
char* zxid_add_fed_tok_to_epr(struct zxid_conf* cf, struct zx_a_EndpointReference_s* epr, const char* uid, int bs_lvl)
{
  struct timeval srcts = {0,501000};
  struct zx_sa_NameID_s* nameid;
  struct zx_sa_Assertion_s* a7n;
  struct zxid_entity* sp_meta;
  struct zx_str* affil;
  char sp_name_buf[1024];
  char* logop;

  if (epr->Metadata->ProviderID) {
    sp_meta = zxid_get_ent_ss(cf, epr->Metadata->ProviderID->content);
    if (!sp_meta) {
      ERR("The metadata for provider could not be found or fetched. Reject. %d", 0);
      return 0;
    }
  } else {
    ERR("The EPR does not have ProviderID element. Reject. %d", 0);
    return 0;
  }
  
  if (sp_meta->ed && sp_meta->ed->AffiliationDescriptor
      && (affil = sp_meta->ed->AffiliationDescriptor->affiliationOwnerID)
      && affil->s && affil->len)
    ; /* affil is good */
  else
    affil = epr->Metadata->ProviderID->content;
  
  zxid_nice_sha1(cf, sp_name_buf, sizeof(sp_name_buf), affil, affil, 7);
  D("sp_name_buf(%s) ProviderID(%.*s) di_allow_create=%d", sp_name_buf, epr->Metadata->ProviderID->content->len, epr->Metadata->ProviderID->content->s, cf->di_allow_create);
  
  nameid = zxid_check_fed(cf, affil, uid, cf->di_allow_create, &srcts,
			  epr->Metadata->ProviderID->content, 0 /*ID*/, sp_name_buf);
  
  if (nameid) {
    if (cf->di_nid_fmt == 't') {
      zxid_mk_transient_nid(cf, nameid, sp_name_buf, uid);
      logop = "TMPDI";
    } else
      logop = "FEDDI";
  } else {
    D("No nameid (because of no federation), using transient %d", 0);
    nameid = zx_NEW_sa_NameID(cf->ctx);
    zxid_mk_transient_nid(cf, nameid, sp_name_buf, uid);
    logop = "TMPDI";
  }
  
  /* Generate access credential */
  
  a7n = zxid_mk_user_a7n_to_sp(cf, 0, uid, nameid, sp_meta, sp_name_buf, bs_lvl);
  
  if (!zxid_anoint_a7n(cf, cf->sso_sign & ZXID_SSO_SIGN_A7N, a7n,
		       epr->Metadata->ProviderID->content, "DIA7N")) {
    ERR("Failed to sign the assertion %d", 0);
    return 0;
  }
  
  if (!epr->Metadata->SecurityContext) {
    epr->Metadata->SecurityContext = zx_NEW_di_SecurityContext(cf->ctx);
  }

  if (!epr->Metadata->SecurityContext->SecurityMechID) {
    epr->Metadata->SecurityContext->SecurityMechID
      = zx_dup_simple_elem(cf->ctx, WSF20_SEC_MECH_TLS_BEARER);
  }

  if (!epr->Metadata->SecurityContext->Token) {
    epr->Metadata->SecurityContext->Token = zx_NEW_sec_Token(cf->ctx);
  }
  
  if (cf->di_a7n_enc) {
    epr->Metadata->SecurityContext->Token->EncryptedAssertion = zxid_mk_enc_a7n(cf, a7n, sp_meta);
  } else {
    epr->Metadata->SecurityContext->Token->Assertion = a7n;
  }
  return logop;
}

/*(i) Generate SSO assertion and ship it to SP by chosen binding. */

/* Called by:  zxid_idp_dispatch */
struct zx_str* zxid_idp_sso(struct zxid_conf* cf, struct zxid_cgi* cgi, struct zxid_ses* ses, struct zx_sp_AuthnRequest_s* ar)
{
  X509* sign_cert;
  RSA*  sign_pkey;
  int binding = 0;
  struct zxsig_ref refs;
  struct zxid_entity* sp_meta;
  struct zx_str* acsurl = 0;
  struct zx_str tmpss;
  struct zx_str* ss;
  struct zx_str* affil;
  struct zx_str* payload;
  struct timeval srcts = {0,501000};
  struct zx_sa_NameID_s* nameid;
  struct zx_sa_Assertion_s* a7n;
  struct zx_sp_NameIDPolicy_s* nidpol;
  struct zx_sp_Response_s* resp;
  struct zx_e_Envelope_s* e;
  char sp_name_buf[1024];
  char* p;
  char* logop;

  if (!ar || !ar->Issuer || !ar->Issuer->gg.content) {
    ERR("No Issuer found in AuthnRequest %p", ar);
    return zx_dup_str(cf->ctx, "* ERR");
  }

  sp_meta = zxid_get_ent_ss(cf, ar->Issuer->gg.content);
  if (!sp_meta) {
    ERR("The metadata for Issuer of the AuthnRequest could not be found or fetched %d", 0);
    return zx_dup_str(cf->ctx, "* ERR");
  }
  D("sp_eid(%.*s)", sp_meta->eid_len, sp_meta->eid);

  /* Figure out the binding and url */

  if (ar->AssertionConsumerServiceIndex) {
    if (ar->ProtocolBinding || ar->AssertionConsumerServiceURL) {
      ERR("When SP specifies AssertionConsumerServiceIndex in AuthnRequest, it SHOULD NOT specify ProtocolBinding(%p) or AssertionConsumerServiceURL(%p). They are ignored. AssertionConsumerServiceIndex approach is the preferred approach.", ar->ProtocolBinding, ar->AssertionConsumerServiceURL);
    }
    acsurl = zxid_sp_loc_by_index_raw(cf, cgi, sp_meta, ZXID_ACS_SVC, ar->AssertionConsumerServiceIndex, &binding);
  } else if (ar->ProtocolBinding) {
    p = zx_str_to_c(cf->ctx, ar->ProtocolBinding);
    acsurl = zxid_sp_loc_raw(cf, cgi, sp_meta, ZXID_ACS_SVC, p, 0);
    ZX_FREE(cf->ctx, p);
    if (acsurl && ar->AssertionConsumerServiceURL) {
      if (acsurl->len != ar->AssertionConsumerServiceURL->len
	  || memcmp(acsurl->s, ar->AssertionConsumerServiceURL->s, acsurl->len)) {
	ERR("SECURITY/SPOOFING: SP specified in AuthnRequest an AssertionConsumerServiceURL(%.*s) but this does not agree with the metadata specified url(%.*s) for Binding(%.*s). SP would be better off using AssertionConsumerServiceIndex approach. The metadata is relied on and the AssertionConsumerServiceURL is ignored.", ar->AssertionConsumerServiceURL->len, ar->AssertionConsumerServiceURL->s, acsurl->len, acsurl->s, ar->ProtocolBinding->len, ar->ProtocolBinding->s);
      }
      binding = zxid_protocol_binding_map_saml2(ar->ProtocolBinding);
    }
  }
  if (!acsurl) {
    D("AuthnRequest did not specify any ACS or binding. Using idp_pref_acs_binding(%s)", cf->idp_pref_acs_binding);
    acsurl = zxid_sp_loc_raw(cf, cgi, sp_meta, ZXID_ACS_SVC, cf->idp_pref_acs_binding, 0);
    if (acsurl) {
      tmpss.len = strlen(cf->idp_pref_acs_binding);
      tmpss.s = cf->idp_pref_acs_binding;
      binding = zxid_protocol_binding_map_saml2(&tmpss);
    } else {
      D("Preferred binding not supported by SP metadata, using first ACS entry from metadata %d", 0);
      if (!sp_meta->ed || !sp_meta->ed->SPSSODescriptor || !sp_meta->ed->SPSSODescriptor->AssertionConsumerService || !sp_meta->ed->SPSSODescriptor->AssertionConsumerService->Location) {
	ERR("SP metadata does not contain any AssertionConsumerService. Can not complete SSO (SP metadata problem) %d", 0);
	return zx_dup_str(cf->ctx, "* ERR");
      }
      acsurl = sp_meta->ed->SPSSODescriptor->AssertionConsumerService->Location;
      binding = zxid_protocol_binding_map_saml2(sp_meta->ed->SPSSODescriptor->AssertionConsumerService->Binding);
    }
  }

  /* User ses->uid is already logged in, now check for federation with sp */

  D("sp_eid(%.*s)", sp_meta->eid_len, sp_meta->eid);

  if (ar->IssueInstant && ar->IssueInstant->s)
    srcts.tv_sec = zx_date_time_to_secs(ar->IssueInstant->s);
  
  nidpol = ar->NameIDPolicy;
  if (!cgi->allow_create && nidpol && nidpol->AllowCreate && nidpol->AllowCreate->s) {
    D("No allow_create from form, extract from SAMLRequest (%.*s) len=%d", nidpol->AllowCreate->len, nidpol->AllowCreate->s, nidpol->AllowCreate->len);
    cgi->allow_create = ZXID_XML_TRUE_TEST(nidpol->AllowCreate) ? '1' : '0';
  }

  if ((!cgi->nid_fmt || !cgi->nid_fmt[0])
      && nidpol && nidpol->Format && nidpol->Format->s) {
    D("No Name ID Format from form, extract from SAMLRequest (%.*s) len=%d", nidpol->Format->len, nidpol->Format->s, nidpol->Format->len);
    cgi->nid_fmt = nidpol->Format->len == sizeof(SAML2_TRANSIENT_NID_FMT)-1 && !memcmp(nidpol->Format->s, SAML2_TRANSIENT_NID_FMT, sizeof(SAML2_TRANSIENT_NID_FMT)-1) ? "trnsnt" : "prstnt";
  }

  affil = nidpol && nidpol->SPNameQualifier ? nidpol->SPNameQualifier : ar->Issuer->gg.content;
  zxid_nice_sha1(cf, sp_name_buf, sizeof(sp_name_buf), affil, affil, 7);
  D("sp_name_buf(%s)  allow_create=%d", sp_name_buf, cgi->allow_create);
  nameid = zxid_check_fed(cf, affil, ses->uid, cgi->allow_create,
			  &srcts, ar->Issuer->gg.content, ar->ID, sp_name_buf);

  if (nameid) {
    if (!cgi->nid_fmt || !cgi->nid_fmt[0] || !strcmp(cgi->nid_fmt, "trnsnt")) {
      zxid_mk_transient_nid(cf, nameid, sp_name_buf, ses->uid);
      logop = "ITSSO";
    } else
      logop = "IFSSO";
  } else {
    D("No nameid (because of no federation), using transient %d", 0);
    nameid = zx_NEW_sa_NameID(cf->ctx);
    zxid_mk_transient_nid(cf, nameid, sp_name_buf, ses->uid);
    logop = "ITSSO";
  }

  a7n = zxid_mk_user_a7n_to_sp(cf, ses, ses->uid, nameid, sp_meta, sp_name_buf, 1);  /* SSO a7n */

  /* Sign, encrypt, and ship the assertion according to the binding. */

  switch (binding) {
  case 'e':
    D("SAML2 PAOS ep(%.*s)", acsurl->len, acsurl->s);
    
    if (cf->sso_sign & ZXID_SSO_SIGN_A7N) {
      refs.id = a7n->ID;
      refs.canon = zx_EASY_ENC_SO_sa_Assertion(cf->ctx, a7n);
      if (zxid_lazy_load_sign_cert_and_pkey(cf, &sign_cert, &sign_pkey, "use sign cert paos"))
	a7n->Signature = zxsig_sign(cf->ctx, 1, &refs, sign_cert, sign_pkey);
    }
    resp = zxid_mk_saml_resp(cf);
    if (cf->post_a7n_enc) {
      resp->EncryptedAssertion = zxid_mk_enc_a7n(cf, a7n, sp_meta);
    } else {
      resp->Assertion = a7n;
    }
    payload = zxid_anoint_sso_resp(cf, cf->sso_sign & ZXID_SSO_SIGN_RESP, resp, ar);
    if (!payload)
      return zx_dup_str(cf->ctx, "* ERR");
    zx_str_free(cf->ctx, payload);

    /* Generate SOAP envelope with ECP header */

    e = zx_NEW_e_Envelope(cf->ctx);

    e->Header = zx_NEW_e_Header(cf->ctx);
    e->Header->ecp_Response = zx_NEW_ecp_Response(cf->ctx);
    e->Header->ecp_Response->mustUnderstand = zx_dup_str(cf->ctx, "1");
    e->Header->ecp_Response->actor = zx_dup_str(cf->ctx, SOAP_ACTOR_NEXT);
    e->Header->ecp_Response->AssertionConsumerServiceURL = acsurl;

    e->Body = zx_NEW_e_Body(cf->ctx);
    e->Body->Response = resp;
    
    ss = zx_EASY_ENC_SO_e_Envelope(cf->ctx, e);

    zxlog(cf, 0, &srcts, 0, ar->Issuer->gg.content, 0, a7n->ID, nameid->gg.content, "N", "K", logop, ses->uid, "PAOS2");


    /* *** Check what HTTP level headers PAOS needs */
    return zx_strf(cf->ctx, "Content-type: text/xml\r\nContent-Length: %d\r\n%s%s%s\r\n%.*s",
		   ss->len,
		   ses->setcookie?"Set-Cookie: ":"", ses->setcookie?ses->setcookie:"", ses->setcookie?"\r\n":"",
		   ss->len, ss->s);

  case 'q':
    D("SAML2 BRWS-POST-SIMPLE-SIGN ep(%.*s)", acsurl->len, acsurl->s);

    if (!zxid_anoint_a7n(cf, cf->sso_sign & ZXID_SSO_SIGN_A7N_SIMPLE, a7n, ar->Issuer->gg.content, "SSOA7N"))
      return zx_dup_str(cf->ctx, "* ERR");
    resp = zxid_mk_saml_resp(cf);
    if (cf->post_a7n_enc) {
      resp->EncryptedAssertion = zxid_mk_enc_a7n(cf, a7n, sp_meta);
    } else {
      resp->Assertion = a7n;
    }
    payload = zxid_anoint_sso_resp(cf, 0, resp, ar);
    if (!payload)
      return zx_dup_str(cf->ctx, "* ERR");
    ss = zxid_saml2_post_enc(cf, "SAMLResponse", payload, cgi->rs, 1, acsurl);
    zx_str_free(cf->ctx, payload);
    if (!ss)
      return zx_dup_str(cf->ctx, "* ERR");

    zxlog(cf, 0, &srcts, 0, ar->Issuer->gg.content, 0, a7n->ID, nameid->gg.content, "N", "K", logop, ses->uid, "SIMPSIG");

    return zx_strf(cf->ctx, "Content-type: text/html\r\nContent-Length: %d\r\n%s%s%s\r\n%.*s",
		   ss->len,
		   ses->setcookie?"Set-Cookie: ":"", ses->setcookie?ses->setcookie:"", ses->setcookie?"\r\n":"",
		   ss->len, ss->s);

  case 'p':
    D("SAML2 BRWS-POST ep(%.*s)", acsurl->len, acsurl->s);

    if (!zxid_anoint_a7n(cf, cf->sso_sign & ZXID_SSO_SIGN_A7N, a7n, ar->Issuer->gg.content, "SSOA7N"))
      return zx_dup_str(cf->ctx, "* ERR");
    resp = zxid_mk_saml_resp(cf);
    if (cf->post_a7n_enc) {
      resp->EncryptedAssertion = zxid_mk_enc_a7n(cf, a7n, sp_meta);
    } else {
      resp->Assertion = a7n;
    }
    payload = zxid_anoint_sso_resp(cf, cf->sso_sign & ZXID_SSO_SIGN_RESP, resp, ar);
    if (!payload)
      return zx_dup_str(cf->ctx, "* ERR");
    
    ss = zxid_saml2_post_enc(cf, "SAMLResponse", payload, cgi->rs, 0, acsurl);
    zx_str_free(cf->ctx, payload);
    if (!ss)
      return zx_dup_str(cf->ctx, "* ERR");
    
    zxlog(cf, 0, &srcts, 0, ar->Issuer->gg.content, 0, a7n->ID, nameid->gg.content, "N", "K", logop, ses->uid, "BRWS-POST");
    
    return zx_strf(cf->ctx, "Content-type: text/html\r\nContent-Length: %d\r\n%s%s%s\r\n%.*s",
		   ss->len,
		   ses->setcookie?"Set-Cookie: ":"", ses->setcookie?ses->setcookie:"", ses->setcookie?"\r\n":"",
		   ss->len, ss->s);
    
  case 'a':
    D("SAML2 BRWS-ART ep(%.*s)", acsurl->len, acsurl->s);

    if (!cf->log_issue_a7n) {
      INFO("LOG_ISSUE_A7N must be turned on in IdP configuration for artifact profile to work. Turning on now automatically. %d", 0);
      cf->log_issue_a7n = 1;
    }
    if (!zxid_anoint_a7n(cf, cf->sso_sign & ZXID_SSO_SIGN_A7N, a7n, ar->Issuer->gg.content, "SSOA7N"))
      return zx_dup_str(cf->ctx, "* ERR");
    resp = zxid_mk_saml_resp(cf);
    if (0) {
      resp->EncryptedAssertion = zxid_mk_enc_a7n(cf, a7n, sp_meta);
    } else {
      resp->Assertion = a7n;
    }
    payload = zxid_anoint_sso_resp(cf, cf->sso_sign & ZXID_SSO_SIGN_RESP, resp, ar);
    if (!payload)
      return zx_dup_str(cf->ctx, "* ERR");
    
    //ss = zxid_saml2_post_enc(cf, "SAMLResponse", pay_load, ar->RelayState);  *** redirect
    zx_str_free(cf->ctx, payload);
    /* *** Do artifact processing */

    zxlog(cf, 0, &srcts, 0, ar->Issuer->gg.content, 0, a7n->ID, nameid->gg.content, "N", "K", logop, ses->uid, "BRWS-ART");


  default:
    NEVER("Unknown or unsupported binding %d", binding);
  }

  return zx_dup_str(cf->ctx, "* ERR");
}

/*() ID-WSF Authentication Service: check password and emit bootstrap(s)
 * To generate the data, use:
 *   perl -MMIME::Base64 -e 'print encode_base64("\0user\0pw\0")'
 *   perl -MMIME::Base64 -e 'print encode_base64("\0tastest\0tas123\0")'
 * See also: zxid_as_call_ses()
 */

/* Called by:  zxid_sp_soap_dispatch */
struct zx_as_SASLResponse_s* zxid_idp_as_do(struct zxid_conf* cf, struct zx_as_SASLRequest_s* req)
{
  struct zxid_cgi cgi;
  struct zxid_ses ses;
  struct zx_as_SASLResponse_s* res = zx_NEW_as_SASLResponse(cf->ctx);
  struct zx_sa_Attribute_s* at;
  char* q;
  char* u;
  char* p;
  char buf[1024];
  char path[ZXID_MAX_BUF];

  memset(&cgi, 0, sizeof(cgi));
  memset(&ses, 0, sizeof(ses));

  if (SIMPLE_BASE64_PESSIMISTIC_DECODE_LEN(req->Data->content->len) >= sizeof(buf)-1) {
    ERR("Too long username and password data %d", req->Data->content->len);
    res->Status = zxid_mk_lu_Status(cf, "ERR", 0, 0, 0);
  }
  q = unbase64_raw(req->Data->content->s, req->Data->content->s + req->Data->content->len, buf, zx_std_index_64);
  *q = 0;
  for (u = buf; *u && u < q; ++u) ;  /* skip initial */
  for (p = ++u; *p && p < q; ++p) ;
  ++p;
  cgi.uid = u;
  cgi.pw = p;

  if (zxid_pw_authn(cf, &cgi, &ses)) {
    D_INDENT("as_ok: ");
    name_from_path(path, sizeof(path), "%s" ZXID_UID_DIR "%s/.bs/", cf->path, cgi.uid);
    at = zxid_gen_boots(cf, cgi.uid, path, 0, 1);
    for (; at; at = (struct zx_sa_Attribute_s*)at->gg.g.n) {
      at->AttributeValue->EndpointReference->gg.g.n = (void*)res->EndpointReference;
      res->EndpointReference = at->AttributeValue->EndpointReference;
    }
    /* *** Free the attribute chain, but do not free EPRs */

    name_from_path(path, sizeof(path), "%s" ZXID_UID_DIR ".all/.bs/", cf->path);
    at = zxid_gen_boots(cf, cgi.uid, path, 0, 1);
    for (; at; at = (struct zx_sa_Attribute_s*)at->gg.g.n) {
      at->AttributeValue->EndpointReference->gg.g.n = (void*)res->EndpointReference;
      res->EndpointReference = at->AttributeValue->EndpointReference;
    }
    /* *** Free the attribute chain, but do not free EPRs */
    
    res->Status = zxid_mk_lu_Status(cf, "OK", 0, 0, 0);
    D_DEDENT("as_ok: ");
  } else {
    ERR("Authentication failed uid(%s) pw(%s)", cgi.uid, cgi.pw);
    res->Status = zxid_mk_lu_Status(cf, "ERR", 0, 0, 0);
  }
  return res;
}

/* EOF  --  zxidpsso.c */
