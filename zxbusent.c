/* zxbusent.c  -  Audit Bus Entity management
 * Copyright (c) 2012 Sampo Kellomaki (sampo@iki.fi), All Rights Reserved.
 * This is confidential unpublished proprietary source code of the author.
 * NO WARRANTY, not even implied warranties. Contains trade secrets.
 * Distribution prohibited unless authorized in writing. See file COPYING.
 * Special grant: http.c may be used with zxid open source project under
 * same licensing terms as zxid itself.
 * $Id$
 *
 * 16.8.2012, created --Sampo
 * 30.8.2012, added subscription mechanisms --Sampo
 * 5.9.2012,  separated entity management and subscriptions to own source files --Sampo
 */

#include "platform.h"
#include "errmac.h"
#include "akbox.h"
#include "hiios.h"
#include "hiproto.h"
#include <zx/zxidconf.h>
#include <zx/zxidutil.h>

#define __USE_GNU 1  /* for O_DIRECT */

#include <ctype.h>
#include <memory.h>
#include <stdlib.h>
#include <netinet/in.h> /* htons(3) and friends */
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <errno.h>

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
#define zx_rcpt_sig dest

extern int verbose;  /* defined in option parsing in zxbusd.c */
extern char* zxbus_path;

/*() Allocate an entity
 * locking:: must be called inside shf->ent_mut
 * return:: pointer to hi_ent on success, 0 on failure */

/* Called by:  zxbus_load_ent, zxbus_login_ent */
struct hi_ent* zxbus_new_ent(struct hiios* shf, int len, const char* eid)
{
  struct hi_ent* ent;
  ZMALLOC(ent);
  ent->n = shf->ents;
  shf->ents = ent;
  ZMALLOCN(ent->chs, shf->max_chs);
  MALLOCN(ent->eid, len+1);
  memcpy(ent->eid, eid, len);
  ent->eid[len] = 0;
  return ent;
}

/*() Load an entity (and check that it exists)
 * locking:: must be called inside shf->ent_mut
 * return:: pointer to hi_ent on success, 0 on failure */

/* Called by:  zxbus_load_acks, zxbus_load_ch_subs, zxbus_login_ent */
struct hi_ent* zxbus_load_ent(struct hiios* shf, int len, const char* eid)
{
  char* p;
  char eid_buf[256];
  char sha1_name[28];
  char u_path[ZXID_MAX_BUF];
  struct hi_ent* ent;
  struct stat st;

  if (len == -1)
    len = strlen(eid);
  
  /* Check if already loaded */
  
  for (ent = shf->ents; ent; ent = ent->n)
    if (!memcmp(ent->eid, eid, len) && ONE_OF_2(eid[len],'\0','\n'))
      return ent;  
  
  /* Seems not. Prepare path and check if user directory exists. */

  if (len > sizeof(eid_buf)-2) {
    ERR("Entity ID too long (%.*s) len=%d", len, eid, len);
    return 0;
  }
  memcpy(eid_buf, eid, len);
  eid_buf[len] = 0;
  
  for (p = eid_buf; *p; ++p)   /* Undo STOMP 1.1 : forbidden escaping */
    if (*p == '|')
      *p = ':';
  sha1_safe_base64(sha1_name, len, eid_buf);
  sha1_name[27] = 0;

  name_from_path(u_path, sizeof(u_path), "%s" ZXID_UID_DIR "/%s/", zxbus_path, sha1_name);
  if (stat(u_path, &st)==-1) {
    D("Entity(%.*s) does not exit. path(%s)", len, eid, u_path);
    return 0;
  }

  /* Add newly allocated entity to the list. */
  
  ent = zxbus_new_ent(shf, len, eid);
  D("Loaded eid(%s)", ent->eid);
  return ent;
}

/*() Perform zxbus specifics to call generic zx_pw_authn() */

/* Called by:  zxbus_login_ent */
static int zxbus_pw_authn_ent(int len, const char* eid, const char* passw)
{
  char sha1_name[28];
  char eid_buf[256];
  char pw_buf[256];
  char* p;

  if (len > sizeof(eid_buf)-2) {
    ERR("Entity ID too long (%.*s) len=%d", len, eid, len);
    return 0;
  }
  memcpy(eid_buf, eid, len);
  eid_buf[len] = 0;
  
  for (p = eid_buf; *p; ++p)   /* Undo STOMP 1.1 : forbidden escaping */
    if (*p == '|')
      *p = ':';
  sha1_safe_base64(sha1_name, len, eid_buf);
  sha1_name[27] = 0;
  
  len = strchr(passw, '\n') - passw;
  if (len > sizeof(pw_buf)-2) {
    ERR("Password too long (%.*s) len=%d", len, passw, len);
    return 0;
  }
  memcpy(pw_buf, passw, len);
  pw_buf[len] = 0;
  
  return zx_pw_authn(zxbus_path, sha1_name, pw_buf);
  /* *** add password overwrite in memory */
}

/*() Login an entity, typically producer or listener.
 * Here we may check credentials from TLS layer against login header, (*** TBD)
 * or we may perform simple username password login using the headers.
 * In any event the entity is either found in shf->ents list or
 * it is added there. The entity is associated with io object (and vice versa).
 * return:: 1 on success, 0 on failure.
 *
 * To create bus users, which use SHA1 of their EntityID (the entityID is passed
 * in STOMP 1.1 login header) as username, you should follow these steps
 * 1. Run ./zxbuslist -c 'URL=https://sp.foo.com/' -dc to determine the entity ID
 * 2. Convert entity ID to SHA1 hash: ./zxcot -p 'http://sp.foo.com?o=B'
 * 3. Create the user: ./zxpasswd -new G2JpTSX_dbdJ7frhYNpKWGiMdTs /var/zxid/bus/uid/ <passwd
 */

/* Called by:  stomp_got_login */
int zxbus_login_ent(struct hi_thr* hit, struct hi_io* io, struct hi_pdu* req)
{
  struct hi_ent* ent;
  int len = strchr(req->ad.stomp.login, '\n') - req->ad.stomp.login;
  D("login_ent(%.*s) len=%d", len, req->ad.stomp.login, len);

  LOCK(hit->shf->ent_mut, "login");
  if (!(ent = zxbus_load_ent(hit->shf, len, req->ad.stomp.login))) {
    if (hit->shf->anonlogin) {
      ent = zxbus_new_ent(hit->shf, len, req->ad.stomp.login);
      INFO("Anon login eid(%s)", ent->eid);
      /* *** consider persisting the newly created account */
    } else {
      UNLOCK(hit->shf->ent_mut, "login-fail");
      ERR("Login account(%.*s) does not exist and no anon login", len, req->ad.stomp.login);
      return 0;
    }
  }

  if (req->ad.stomp.pw) {
    if (!zxbus_pw_authn_ent(len, req->ad.stomp.login, req->ad.stomp.pw)) {
      UNLOCK(hit->shf->ent_mut, "login-fail3");
      return 0;
    }
  } else {
    UNLOCK(hit->shf->ent_mut, "login-fail5");
    ERR("Login account(%s): no password supplied", ent->eid);
    return 0;
  }
  
  if (ent->io) {
    if (ent->io == io) {
      NEVER("Entity has io already set to current io_%p", io);
    } else {
      NEVER("Entity has io already set to different io_%p", ent->io);
    }
  }
  
  ent->io = io;
  LOCK(io->qel.mut, "login");
  if (io->ent) {
    if (io->ent == ent) {
      NEVER("io has ent already set to current ent_%p", ent);
    } else {
      NEVER("io has ent already set to different ent_%p", ent);
    }
  }
  io->ent = ent;
  UNLOCK(io->qel.mut, "login");
  UNLOCK(hit->shf->ent_mut, "login");
  return 1;
}

/* EOF  --  zxbusent.c */
