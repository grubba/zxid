/* zxidps.c  -  People Service
 * Copyright (c) 2010 Sampo Kellomaki (sampo@iki.fi), All Rights Reserved.
 * Copyright (c) 2010 Risaris Ltd, All Rights Reserved.
 * Author: Sampo Kellomaki (sampo@iki.fi)
 * This is confidential unpublished proprietary source code of the author.
 * NO WARRANTY, not even implied warranties. Contains trade secrets.
 * Distribution prohibited unless authorized in writing.
 * Licensed under Apache License 2.0, see file COPYING.
 * $Id: zxiddi.c,v 1.2 2009-11-24 23:53:40 sampo Exp $
 *
 * 16.9.2010, created --Sampo
 *
 * See also zxcall for client
 * - liberty-idwsf-overview-v2.0.pdf sec 2.3 and 2.4 (pp.15-31) for use cases
 * - liberty-idwsf-people-service-v1.0.pdf, sec 4.4 Elements Supporting Invitation (pp.53-57)
 *
 *  zxcot -e http://idp.tas3.pt:8081/zxididp?o=S 'People Svc' \
 *    http://idp.tas3.pt:8081/zxididp?o=B urn:liberty:ps:2006-08 \
 *  | zxcot -b /var/zxid/idpdimd
 */

#include "platform.h"  /* for dirent.h */
#include "errmac.h"
#include "zxid.h"
#include "zxidconf.h"
#include "saml2.h"
#include "wsf.h"
#include "c/zx-const.h"
#include "c/zx-ns.h"
#include "c/zx-data.h"

/*() Encrypt psobj identifier for an entity.
 *
 * ObjectID (psobj) has particlar privacy threat in that several WSCs may
 * see them and be able to correlate about the user that the object refers
 * to (see brief discussion in sec 2.1.4 "<ObjectID> Element", ll.278-281,
 * of [PeopleSvc].
 *
 * We adopt solution where psobj issued towards an entity (SP, WSC) is
 * the psobj encrypted (AES-128-CBC) with key consisting of concatenation
 * of secret (/var/zxid/pem/psobj-enc.key) known to ps server (i.e. the
 * zxididp) and the Entity ID of the entity. */

struct zx_str* zxid_psobj_enc(zxid_conf* cf, struct zx_str* eid, const char* psobj)
{
  char symkey[20];
  struct zx_str* ss;
  if (!cf->psobj_symkey[0])
    zx_get_symkey(cf, "psobj-enc.key", cf->psobj_symkey);
  zx_raw_digest2(cf->ctx, symkey, "SHA1", strlen(cf->psobj_symkey), cf->psobj_symkey, eid->len, eid->s);
  ss = zx_raw_cipher(cf->ctx, "AES-128-CBC", 1, symkey, strlen(psobj), psobj, 16, 0);
  return ss;
}

/*() Decrypt psobj identifier from an entity. */

struct zx_str* zxid_psobj_dec(zxid_conf* cf, struct zx_str* eid, struct zx_str* psobj)
{
  char symkey[20];
  struct zx_str* ss;
  if (!cf->psobj_symkey[0])
    zx_get_symkey(cf, "psobj-enc.key", cf->psobj_symkey);
  zx_raw_digest2(cf->ctx, symkey, "SHA1", strlen(cf->psobj_symkey), cf->psobj_symkey, eid->len, eid->s);
  ss = zx_raw_cipher(cf->ctx, "AES-128-CBC", 0, symkey, psobj->len-16, psobj->s+16, 16, psobj->s);
  return ss;
}

/*() Render the linked list of delegated permissions to a string */

char* zxid_render_perms(zxid_conf* cf, struct zxid_perm* perms)
{
  int n, len = 0;
  struct zxid_perm* perm;
  char* ret;
  char* p;
  
  /* Length computation phase */
  
  for (perm = perms; perm; perm = perm->n)
    len += sizeof("perm: ")-1 + (perm->eid?perm->eid->len:0) + 1 + (perm->qs?perm->qs->len:0) + 1;
  
  ret = p = ZX_ALLOC(cf->ctx, len+1);
  
  /* Rendering phase */
  
  for (perm = perms; perm; perm = perm->n) {
    n = sprintf(p, "perm: %.*s$%.*s\n",
		perm->eid?perm->eid->len:0, perm->eid?perm->eid->s:"",
		perm->qs?perm->qs->len:0,   perm->qs?perm->qs->s:"");
    p += n;
  }
  
  ASSERTOP(p-ret, ==, len);
  *p = 0; /* nul terminate */
  return ret;
}

/*() Render the linked list of invitation IDs to a string */

char* zxid_render_str_list(zxid_conf* cf, struct zx_str* strs, const char* attr_name)
{
  int n, len = 0, atn_len = strlen(attr_name);
  struct zx_str* str;
  char* ret;
  char* p;
  
  /* Length computation phase */
  
  for (str = strs; str; str = str->n)
    len += atn_len + sizeof(": ")-1 + str->len + 1;
  
  ret = p = ZX_ALLOC(cf->ctx, len+1);
  
  /* Rendering phase */
  
  for (str = strs; str; str = str->n) {
    n = sprintf(p, "%s: %.*s\n", attr_name, str->len, str->s);
    p += n;
  }
  
  ASSERTOP(p-ret, ==, len);
  *p = 0; /* nul terminate */
  return ret;
}

/*() Create new invitation in file system. */

int zxid_put_invite(zxid_conf* cf, struct zxid_invite* inv)
{
  char* buf = ZX_ALLOC(cf->ctx, ZXID_MAX_USER);
  char* perms = zxid_render_perms(cf, inv->perms);
  
  write_all_path_fmt("put_inv", ZXID_MAX_USER, buf,
		     "%s" ZXID_INV_DIR "%s", cf->path, invid,
		     "dn: invid=%.*s\ninvid: %.*s\nuid: %.*s\ndesc: %.*s\npsobj: %.*s\nps2spredir: %.*s\nmaxusage: %d\nusage: %d\nnotbefore: %s\nexpires: %s\n%s\n\n",
		     inv->invid->len, inv->invid->s,
		     inv->invid->len, inv->invid->s,
		     inv->uid?inv->uid->len:0, inv->uid?inv->uid->s:"",
		     inv->desc?inv->desc->len:0, inv->desc?inv->desc->s:"",
		     inv->psobj?inv->psobj->len:0, inv->psobj?inv->psobj->s:"",
		     inv->ps2spredir?inv->ps2spredir->len:0, inv->ps2spredir?inv->ps2spredir->s:"",
		     inv->maxusage,
		     inv->usage,
		     zxid_date_time(cf, inv->notbefore),
		     zxid_date_time(cf, inv->expires),
		     STRNULLCHK(perms));
  ZX_FREE(cf->ctx, buf);
  D("PUT INVITATION invid(%s)", invid);
  return 1;
}

/*() Create new People Service Object in file system. */

int zxid_put_psobj(zxid_conf* cf, char* owner, struct zxid_psobj* obj)
{
  char  dir[ZXID_MAX_BUF];
  char* buf = ZX_ALLOC(cf->ctx, ZXID_MAX_USER);
  char* children = 0;  /* *** groups and children not supported yet. */
  char* tags = zxid_render_str_list(cf, obj->invids, "tag");
  char* invids = zxid_render_str_list(cf, obj->invids, "invid");
  char* perms = zxid_render_perms(cf, obj->perms);
  
  write_all_path_fmt("put_psobj", ZXID_MAX_USER, buf,
		     "%s" ZXID_UID_DIR "%s", cf->path, owner,
		     "dn: psobj=%.*s,uid=%s\npsobj: %.*s\nowner: %s\nidpnid: %.*s\ndispname: %.*s\nnodetype: %d\n%s%s%s%s\n\n",
		     obj->psobj->len, obj->psobj->s, owner,
		     obj->psobj->len, obj->psobj->s, owner,
		     obj->idpnid?obj->idpnid->len:0, obj->idpnid?obj->idpnid->s:"",
		     obj->dispname?obj->dispname->len:0, obj->dispname?obj->dispname->s:"",  /* *** Should really support multiple */
		     obj->nodetype,
		     STRNULLCHK(children),
		     STRNULLCHK(tags),
		     STRNULLCHK(invids),
		     STRNULLCHK(perms));
  ZX_FREE(cf->ctx, buf);
  D("PUT PSOBJ(%s)", psobj);
  return 1;
}

/*() Populate psobj from LDIF. Parse LDIF format and insert attributes to struct.
 * The input is temporarily modified and then restored. Do not pass const string. */

/* Called by:  zxid_mk_user_a7n_to_sp x4 */
int zxid_parse_psobj(zxid_conf* cf, struct zxid_psobj* obj, char* p, char* lk)
{
  char* name;
  char* val;
  char* q;
  struct zx_str* ss;
  struct zxid_perm* perm;

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

    switch (name[0]) {
    case 'd':
      if (!strcmp(name, "dn"))
	goto next;
      if (!strcmp(name, "dispname")) {
	obj->dispname = zx_dup_str(cf->ctx, val);
	goto next;
      }
      break;
    case 'i':
      if (!strcmp(name, "idpnid")) {
	obj->idpnid = zx_dup_str(cf->ctx, val);
	goto next;
      }
      if (!strcmp(name, "invid")) {
	ss = zx_dup_str(cf->ctx, val);
	ss->g.n = (void*)obj->invids;
	obj->invids = ss;
	goto next;
      }
      break;
    case 'o':
      if (!strcmp(name, "owner"))
	goto next;
      break;
    case 'p':
      if (!strcmp(name, "psobj")) {
	obj->psobj = zx_dup_str(cf->ctx, val);
	goto next;
      }
      if (!strcmp(name, "psobjref")) {
	ERR("%s: *** Child objects not yet supported (%s: %s)", lk, name, val);
	/*obj->child = zx_dup_str(cf->ctx, val); *** */
	goto next;
      }
      if (!strcmp(name, "perm")) {
	perm = ZX_ZALLOC(cf->ctx, struct zxid_perm);
	q = strchr(val, '$');
	if (q) {
	  perm->eid = zx_dup_len_str(cf->ctx, q-val, val);
	  perm->qs  = zx_dup_str(cf->ctx, q);
	} else
	  perm->eid = zx_dup_str(cf->ctx, val);
	perm->n = obj->perms;
	obj->perms = perm;
	goto next;
      }
      break;
    case 't':
      if (!strcmp(name, "tag")) {
	ss = zx_dup_str(cf->ctx, val);
	ss->g.n = (void*)obj->tags;
	obj->tags = ss;
	goto next;
      }
      break;
    }
    ERR("%s: Unknown name(%s) val(%s) in psobj LDIF file. Ignored.", lk, name, val);

  next:
    val[-2] = ':'; /* restore */
    if (p)
      *p = '\n';
    else
      break;
  }
  return 1;
}

/*() Populate invitation from LDIF. Parse LDIF format and insert attributes to struct.
 * The input is temporarily modified and then restored. Do not pass const string. */

/* Called by:  zxid_mk_user_a7n_to_sp x4 */
int zxid_parse_invite(zxid_conf* cf, struct zxid_invite* obj, char* p, char* lk)
{
  char* name;
  char* val;
  char* q;
  struct zx_str* ss;
  struct zxid_perm* perm;

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

    switch (name[0]) {
    case 'd':
      if (!strcmp(name, "dn"))
	goto next;
      if (!strcmp(name, "desc")) {
	obj->desc = zx_dup_str(cf->ctx, val);
	goto next;
      }
      break;
    case 'e':
      if (!strcmp(name, "expires")) {
	obj->expires = zx_date_time_to_secs(val);
	goto next;
      }
      break;
    case 'i':
      if (!strcmp(name, "invid")) {
	obj->invid = zx_dup_str(cf->ctx, val);
	goto next;
      }
      break;
    case 'm':
      if (!strcmp(name, "maxusage")) {
	sscanf(val, "%i", &obj->maxusage);
	goto next;
      }
      break;
    case 'n':
      if (!strcmp(name, "notbefore")) {
	obj->notbefore = zx_date_time_to_secs(val);
	goto next;
      }
      break;
    case 'p':
      if (!strcmp(name, "psobj")) {
	obj->psobj = zx_dup_str(cf->ctx, val);
	goto next;
      }
      if (!strcmp(name, "ps2spredir")) {
	obj->ps2spredir = zx_dup_str(cf->ctx, val);
	goto next;
      }
      if (!strcmp(name, "perm")) {
	perm = ZX_ZALLOC(cf->ctx, struct zxid_perm);
	q = strchr(val, '$');
	if (q) {
	  perm->eid = zx_dup_len_str(cf->ctx, q-val, val);
	  perm->qs  = zx_dup_str(cf->ctx, q);
	} else
	  perm->eid = zx_dup_str(cf->ctx, val);
	perm->n = obj->perms;
	obj->perms = perm;
	goto next;
      }
      break;
    case 'u':
      if (!strcmp(name, "uid")) {
	obj->uid = zx_dup_str(cf->ctx, val);
	goto next;
      }
      if (!strcmp(name, "usage")) {
	sscanf(val, "%i", &obj->usage);
	goto next;
      }
      break;
    }
    ERR("%s: Unknown name(%s) val(%s) in psobj LDIF file. Ignored.", lk, name, val);

  next:
    val[-2] = ':'; /* restore */
    if (p)
      *p = '\n';
    else
      break;
  }
  return 1;
}

/*() Accept an invitation. Process a URL of form https://idp.tas3.pt/zxididp?o=D&inv=i123431 */

char* zxid_ps_accept_invite(zxid_conf* cf, zxid_cgi* cgi, int* res_len, int auto_flags)
{
  // ***
  return 0;
}

/*() Add an entity to buddy store and obtain an invitation token.
 * In fact this call just adds the invitation as we can not know
 * who will respond to the invitation. The actual object will be
 * created in zxid_ps_accept_invite(). If object repesenting the
 * user already exists, that will be reused. Otherwise new
 * object will be created.
 * The permissions are expected to be passed in as special
 * tag "perm". */

/* Called by:  zxid_sp_soap_dispatch */
struct zx_ps_AddEntityResponse_s* zxid_ps_addent_invite(zxid_conf* cf, zxid_a7n* a7n, struct zx_ps_AddEntityRequest_s* req)
{
  struct zxid_invite* inv = ZX_ZALLOC(cf->ctx, struct zxid_invite);
  inv->invid = zxid_mk_id(cf, "i", 48);  /* What is secure and sufficient space? */
  inv->maxusage = 1;
  inv->notbefore = time(0);
  inv->expires = time(0) + 84200 * 30;  /* *** configurable (about a month) */
  inv->ps2spredir = req->PStoSPRedirectURL->g.content;
  inv->obj = zxid_ps_obj(req->Object->g.content);
  zxid_ps_put_inv();
  // ***
  return 0;
}

/*() Resolve an invitation token to identity */

/* Called by:  zxid_sp_soap_dispatch */
struct zx_ps_ResolveIdentifierResponse_s* zxid_ps_resolv_id(zxid_conf* cf, zxid_a7n* a7n, struct zx_ps_ResolveIdentifierRequest_s* req)
{
  zxid_nid* nameid;
  struct zx_ps_ResolveIdentifierResponse_s* resp = zx_NEW_ps_ResolveIdentifierResponse(cf->ctx);
  struct zx_ps_ResolveInput_s* inp;
  struct zx_ps_ResolveOutput_s* out;
  int len, n_resolv = 0;
  char uid[ZXID_MAX_BUF];
  char sp_name_buf[1024];
  struct zx_str* affil;
  D_INDENT("ps_resolv: ");

  //resp->ID = zxid_mk_id(cf, "DIR", ZXID_ID_BITS);
  
  if (!a7n || !a7n->Subject) {
    ERR("Malformed Assertion(%p): Subject missing.", a7n);
    resp->Status = zxid_mk_lu_Status(cf, "Fail", 0, 0, 0);
    D_DEDENT("ps_resolv: ");
    return resp;
  }

  /* Recover end user's identity: uid at IdP. This is actually done via "self federation"
   * that was created when token for accessing discovery was issued. */
  
  nameid = zxid_decrypt_nameid(cf, a7n->Subject->NameID, a7n->Subject->EncryptedID);
  affil = nameid->SPNameQualifier ? nameid->SPNameQualifier : zxid_my_entity_id(cf);
  
  zxid_nice_sha1(cf, sp_name_buf, sizeof(sp_name_buf), affil, affil, 7);
  len = read_all(sizeof(uid)-1, uid, "idp_map_nid2uid", "%s" ZXID_NID_DIR "%s/%.*s", cf->path, sp_name_buf, nameid->gg.content->len, nameid->gg.content->s);
  if (!len) {
    ERR("Can not find reverse mapping for SP,SHA1(%s) nid(%.*s)", sp_name_buf, nameid->gg.content->len, nameid->gg.content->s);
    resp->Status = zxid_mk_lu_Status(cf, "Fail", 0, 0, 0);
    D_DEDENT("ps_resolv: ");
    return resp;
  }

  for (inp = req->ResolveInput; inp; inp = (struct zx_ps_ResolveInput_s*)inp->gg.g.n) {
    // ***
  }

  zxlog(cf, 0, 0, 0, 0, 0, a7n->ID, nameid->gg.content, "N", "K", "PSRESOLVOK", 0, "n=%d", n_resolv);
  resp->Status = zxid_mk_lu_Status(cf, "OK", 0, 0, 0);
  D_DEDENT("ps_resolv: ");
  return resp;
}

/* EOF  --  zxidps.c */
