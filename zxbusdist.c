/* zxbusdist.c  -  Message persist and distribution, subscription management
 * Copyright (c) 2012 Sampo Kellomaki (sampo@iki.fi), All Rights Reserved.
 * This is confidential unpublished proprietary source code of the author.
 * NO WARRANTY, not even implied warranties. Contains trade secrets.
 * Distribution prohibited unless authorized in writing. See file COPYING.
 * Special grant: http.c may be used with zxid open source project under
 * same licensing terms as zxid itself.
 * $Id$
 *
 * 16.8.2012, created --Sampo
 * 30.9.2012, added subscription mechanisms --Sampo
 *
 * Subscriptions are organized by channel. First the channel is looked up
 * and then list of io objects needs to be chased to deliver the message
 * to each of them. Number of channels is expected to be relatively small,
 * except for per user channels that are handled as a special case. The
 * number of subscribers to common channels is expected to be extremely
 * large, The number of subscribers for per user channel are expected to
 * be relatively small. Thus alternative structure is to simply scan
 * the io object array. This has the advantage of not maintaining a
 * separate data structure that would require additional pointer fields
 * and additional locking.
 *
 * Persistent store of channel subscriptions is realized by having
 * in each channel directory a special file .subs which lists the
 * entity IDs of the subscribers, one per line. When zxbusd starts,
 * it loads this persisted data to memory. When new subscriptions
 * are made, the subscription is "written through" to persistent
 * storage and the in-memory data structure is updates as well.
 */

#include "platform.h"
#include "errmac.h"
#include "akbox.h"
#include "hiios.h"
#include "hiproto.h"
#include <zx/zxidconf.h>
#include <zx/zxidutil.h>

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

extern int verbose;  /* defined in option parsing in zxbusd.c */
extern char* zxbus_path;

#define ZXID_CH_DIR "ch/"

/*() Find the channel in shf->chs array.
 * N.B. The channel composition is fixed at boot time so no locking is needed.
 * return:: hi_ch pointer on success, 0 on not found */

static struct hi_ch* zxbus_find_ch(struct hiios* shf, int len, const char* dest)
{
  int n;
  struct hi_ch* ch;
  if (len == -1)
    len = strlen(dest);
  for (n = shf->max_chs, ch = shf->chs; n; --n, ++ch) {
    if (!ch->dest)
      break;
    if (!memcmp(ch->dest, dest, len) && ONE_OF_2(dest[len],'\n','\0')) {
      D("found ch(%s)", ch->dest);
      return ch;
    }
  }
  D("channel(%.*s) not found", len, dest);
  return 0;
}

/* Handle special "delivery bitch" PDU that represents need to
 * send a message to listeners of a channel (aka destination).
 * We create a synthetic PDU which is scheduled for the delivery
 * work in todo queue. This PDU is not associated to any particular
 * io object and will keep on rescheduling itself until its job
 * has been done. At that point it will free itself. */

/* Called by:  hi_shuffle */
void stomp_msg_deliver(struct hi_thr* hit, struct hi_pdu* db_pdu)
{
  struct hi_ent* ent;
  struct hi_ch* ch;
  int ch_num;
  D("db_pdu(%p) events=0x%x", db_pdu, db_pdu->events);

  ch = zxbus_find_ch(hit->shf, -1, db_pdu->ad.stomp.dest);
  if (!ch)
    return;
  ch_num = ch - hit->shf->chs;
  LOCK(hit->shf->ent_mut, "deliver");
  for (ent = hit->shf->ents; ent; ent = ent->n)
    if (ent->chs[ch_num]) {  /* entity listens on this channel? */
      if (ent->io) {
	hi_sendf(hit, ent->io, db_pdu, 0, "MESSAGE\nsubscription:%s\nmessage-id:%d\ndestination:%s\ncontent-length:%d\n\n%.*s%c", "0", 0, db_pdu->ad.stomp.dest, db_pdu->ad.stomp.len, db_pdu->ad.stomp.len, db_pdu->ad.stomp.body, 0);
	/* the receiving half will decrement  ++(int)db_pdu->ad.stomp.ack */
	++(db_pdu->ad.stomp.ack); /* number of ACKs pending due to MESSAGEs sent */
      } else {
	D("Can not deliver. entity(%s) not connected at the moment?", ent->eid);
      }
    }
  UNLOCK(hit->shf->ent_mut, "deliver");
#if 0
  if (db_pdu->ad.stomp.ack)  /* still something pending? */
    hi_todo_produce(hit->shf, &db_pdu->qel, "delivery bitch again");
  else
    hi_free_req(hit, db_pdu);
#else
  /* No rescheduling. Operate in one-shot mode: all connected ones get delivery attempt.
   * The cleanup will happen when last ACK is received and db_pdu->ad.stomp.ack
   * count has dropped to zero. Redelivery attempts later are handled separately. */
#endif
}

/*() Attempt to presist a message.
 * Persisting involves synchronous write and an atomic filesystem rename operation, ala Maildir.
 * return:: 0 on failure, 1 on success. */

/* Called by:  stomp_got_send */
int zxbus_persist(struct hi_thr* hit, struct hi_io* io, struct hi_pdu* req)
{
  int len;
  char* dest;
  char* nl;
  char* p;
  char t_path[ZXID_MAX_BUF];  /* temp path before atomic rename */
  char d_path[ZXID_MAX_BUF];  /* destination path after atomic rename */
  struct hi_pdu* pdu;
  
  if (!(dest = req->ad.stomp.dest)) {
    stomp_err(hit,io,req,"no destination - client error","SEND MUST specify destination header, i.e. channel to send to.");
    return 0;
  }
  nl = memchr(dest, '\n', req->ap - dest);
  if (*dest == '/')
    ++dest; /* skip initial /, if any */
  
  DD("persist(%.*s)", nl-dest, dest);
  
  /* Sanity check destination for any cracking attempts. */
  for (p = dest; p < nl; ++p) {
    if (p[0] == '.' && p[1] == '.') {
      ERR("SEND destination is a .. hack(%.*s)", nl-dest, dest);
      stomp_err(hit,io,req,"bad destination client error","SEND destination is not a valid channel.");    
      return 0;
    }
    if (ONE_OF_2(*p, '~', '\\') || *p > 122 || *p < 33) {
      ERR("SEND destination bad char 0x%x hack(%.*s)", *p, nl-dest, dest);
      stomp_err(hit,io,req,"bad destination client error","SEND destination is not a valid channel.");    
      return 0;
    }
  }
  
  /* Persist the message, use Maildir style rename from tmp/ to ch/ */
  
  len = name_from_path(d_path, sizeof(d_path), "%sch/%.*s/", zxbus_path, nl-dest, dest);
  if (sizeof(d_path)-len < 28+1 /* +1 accounts for t_path having one more char (tmp vs. ch) */) {
    ERR("The d_path for persisting exceeds limit. len=%d", len);
    stomp_err(hit,io,req,"persist failure at server","Unable to persist message. Can not guarantee reliable delivery, therefore rejecting. Internal error (d_path too long).");    
    return 0;
  }
  DD("d_path(%s) len=%d", d_path, len);
  sha1_safe_base64(d_path+len, req->ap-req->m, req->m);
  d_path[len+27] = 0;
  DD("d_path(%s)", d_path);
  
  name_from_path(t_path, sizeof(t_path), "%stmp/%.*s", zxbus_path, 27, d_path+len);
  
  if (!write2_or_append_lock_c_path(t_path, 0, 0, req->ap-req->m, req->m, "zxbus persist", SEEK_SET, O_TRUNC)) {
    stomp_err(hit,io,req,"persist failure at server","Unable to persist message. Can not guarantee reliable delivery, therefore rejecting. Perhaps filesystem is full, read only, wrong permissions, not mounted, or unreachable?");    
    /* *** shoud we make an effort to close the connection? */
    return 0;
  }
  
  if (rename(t_path, d_path)) {
    ERR("Renaming file(%s) to(%s) for atomicity failed: %d %s. Check permissions and that directories exist. euid=%d egid=%d", t_path, d_path, errno, STRERROR(errno), geteuid(), getegid());
    stomp_err(hit,io,req,"persist failure at server","Unable to persist message. Can not guarantee reliable delivery, therefore rejecting. Perhaps filesystem is read only, wrong permissions, full, not mounted, or unreachable?");    
    /* *** shoud we make an effort to close the connection? */
    return 0;
  }
  D("persisted at(%s) (%.*s) len=%d", d_path, MIN(req->ap-req->ad.stomp.body, 10), req->ad.stomp.body, req->ap-req->m);
  if (verbose) {
    if (req->ad.stomp.receipt)
      nl = memchr(req->ad.stomp.receipt, '\n', req->ap - req->ad.stomp.receipt);
    else
      nl = 0;
    printf("FMT0 persist at %s '%.*s' len=%d rcpt(%.*s)\n", d_path, MIN(req->ap-req->ad.stomp.body, 10), req->ad.stomp.body, req->ap-req->m, nl?(nl-req->ad.stomp.receipt):0, nl?req->ad.stomp.receipt:"");
  }
  /* Schedule delivery to happen. See stomp_msg_deliver() for what happens next.
   * We create a synthetic PDU which is scheduled for the delivery
   * work in todo queue. This PDU is not associated to any particular
   * io object and will keep on rescheduling itself until its job
   * has been done. At that point it will free itself. */

  /* *** change to ad.delivb */
  pdu = hi_pdu_alloc(hit,"delivery bitch");
  pdu->qel.kind = HI_PDU_DIST;
  memcpy(pdu->m, req->m, req->need);  /* copy PDU substance */
  pdu->ap += req->need;
  pdu->ad.stomp.len = req->ad.stomp.len;
  pdu->ad.stomp.body = pdu->m + (req->ad.stomp.body - req->m);
  pdu->ad.stomp.dest = pdu->m + (req->ad.stomp.dest - req->m);
  p = strchr(pdu->ad.stomp.dest, '\n');
  *p = 0; /* nul term dest */
  hi_todo_produce(hit->shf, &pdu->qel,"delivery bitch");
  return 1;
}

/*() Write subscriptions of a channel.
 * Called when new subscription is added at run time.
 * Will walk the entities and subscriptions relating to that channel.
 * locking:: shf->ent_mut must be held when calling this function
 */

static int zxbus_write_ch_subs(struct hiios* shf, struct hi_ch* ch)
{
#ifndef PATH_MAX
#define PATH_MAX ZXID_MAX_BUF
#endif
  char err_buf[PATH_MAX];
  int ch_num = ch - shf->chs;
  struct hi_ent* ent;
  char buf[ZXID_MAX_BUF];
  FILE* out;

  D("writing .subs for ch(%s) ch_num=%d", ch->dest, ch_num);
  name_from_path(buf, sizeof(buf), "%s" ZXID_CH_DIR "%s/.subs", zxbus_path, ch->dest);
  if (!(out = fopen(buf, "wb"))) {
    perror("open");
    ERR("writing subscriptions: File(%s) not writable errno=%d err(%s). euid=%d egid=%d cwd(%s)", buf, errno, STRERROR(errno), geteuid(), getegid(), getcwd(err_buf, sizeof(err_buf)));
    return 0;
  }

  for (ent = shf->ents; ent; ent = ent->n)
    if (ent->chs[ch_num]) {
      D("eid(%s)", ent->eid);
      fprintf(out, "%s\n", ent->eid);
    }
  fclose(out);
  return 1;
}

/*() Load subscriptions of a channel. Called once at startup.
 * N.B. The channel composition is fixed at boot time so no locking is needed. */

static int zxbus_load_ch_subs(struct hiios* shf, struct hi_ch* ch)
{
  int ch_num = ch - shf->chs;
  char* buf;
  char* p;
  char* nl;
  struct hi_ent* ent;

  D("Loading subs for ch(%s) ch_num=%d", ch->dest, ch_num);
  buf = p = read_all_malloc("load_ch_subs",1,0, "%s" ZXID_CH_DIR "%s/.subs", zxbus_path, ch->dest);
  if (!p)
    return 0;
  while (nl = strchr(p, '\n')) {
    *nl = 0;
    if (ent = zxbus_load_ent(shf, -1, p)) {
      ent->chs[ch_num] = 1;
    } else {
      ERR("entity(%s) does not exist, in %s/.subs", p, ch->dest);
    }
    p = nl+1;
  }
  FREE(buf);
  return 1;
}

/*() Load subscriptions of all channels. Called once at startup.
 * N.B. The channel composition is fixed at boot time so no locking is needed. */

int zxbus_load_subs(struct hiios* shf)
{
  char path[ZXID_MAX_BUF];
  struct dirent* de;
  DIR* dir;
  struct hi_ch* ch = shf->chs;
  int n = 0;
  
  name_from_path(path, sizeof(path), "%s" ZXID_CH_DIR, zxbus_path);
  dir = opendir(path);
  if (!dir) {
    perror("opendir for /var/zxid/bus/ch/ (or other if configured)");
    D("failed path(%s)", path);
    return 0;
  }
  
  while (de = readdir(dir))
    if (de->d_name[0] != '.' && de->d_name[strlen(de->d_name)-1] != '~') { /* ign hidden&backup */
      if (++n > shf->max_chs) {
	ERR("More channels in directory(%s) than fit in array. Consider increasing -nch", path);
	break;
      }
      ch->dest = strdup(de->d_name);
      zxbus_load_ch_subs(shf, ch++);
    }
  closedir(dir);
  return 1;
}

/*() Persist a subscription and book it into data structure.
 * Returns:: 1 on success, 0 on failure. */

int zxbus_subscribe(struct hi_thr* hit, struct hi_io* io, struct hi_pdu* req)
{
  int len;
  char* dest;
  struct hi_ch* ch;
  struct hi_ent* ent;

  if (!req || !req->ad.stomp.dest || !*req->ad.stomp.dest) {
    ERR("Subscription missing destination %p", req);
    return 0;
  }
  dest = req->ad.stomp.dest;
  len = strchr(dest, '\n') - dest;
  
  LOCK(io->qel.mut, "login");
  ent = io->ent;
  UNLOCK(io->qel.mut, "login");
  if (!ent) {
    ERR("No entity assiciated with io_%p", io);
    return 0;
  }
  
  ch = zxbus_find_ch(hit->shf, len, dest);    /* Check that the channel exists. */
  if (!ch) {
    ERR("%s: attempted subscription to nonexistent channel(%.*s)", ent->eid, len, dest);
    return 0;
  }

  /* Check whether entity is already subscribed. The channel arrays are
   * in alignment so we only need to look at the corresponding slot. */
  
  LOCK(hit->shf->ent_mut, "subscribe");
  if (ent->chs[ch - hit->shf->chs]) {
    UNLOCK(hit->shf->ent_mut, "subscribed");
    D("Already subscribed to(%s)", ch->dest);
  } else {
    ent->chs[ch - hit->shf->chs] = 1;
    zxbus_write_ch_subs(hit->shf, ch);
    UNLOCK(hit->shf->ent_mut, "subscribe2");
  }
  /* *** somehow schedule messages from pending subscriptions to be delivered */
  return 1;
}

/*() Allocate an entity
 * locking:: must be called inside shf->ent_mut
 * return:: pointer to hi_ent on success, 0 on failure */

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

/* EOF  --  zxbusdist.c */
