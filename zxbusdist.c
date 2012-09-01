/* zxbusdist.c  -  Message persist and distribution, subscription management
 * Copyright (c) 2012 Sampo Kellomaki (sampo@iki.fi), All Rights Reserved.
 * This is confidential unpublished proprietary source code of the author.
 * NO WARRANTY, not even implied warranties. Contains trade secrets.
 * Distribution prohibited unless authorized in writing. See file COPYING.
 * Special grant: http.c may be used with zxid open source project under
 * same licensing terms as zxid itself.
 * $Id$
 *
 * 16.8.2012, created, based on http and smtp --Sampo
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
#define STOMP_MIN_PDU_SIZE (sizeof("ACK\n\n\0")-1)

extern int verbose;  /* defined in option parsing in zxbusd.c */

#define ZXID_BUS_DIR "bus/"

/*() Attempt to presist a message.
 * Persisting involves synchronous write and an atomic filesystem rename operation, ala Maildir.
 * Returns: 0 on failure, 1 on success. */

/* Called by:  stomp_got_send */
int zxbus_persist(struct hi_thr* hit, struct hi_io* io, struct hi_pdu* req)
{
  int len;
  const char* dest;
  const char* p;
  const char* nl;
  char t_path[ZXID_MAX_BUF];  /* temp path before atomic rename */
  char d_path[ZXID_MAX_BUF];  /* destination path after atomic rename */
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
  
  len = name_from_path(d_path, sizeof(d_path), "%s" ZXID_BUS_DIR "ch/%.*s/", ZXID_PATH, nl-dest, dest);
  if (sizeof(d_path)-len < 28+1 /* +1 accounts for t_path having one more char (tmp vs. ch) */) {
    ERR("The d_path for persisting exceeds limit. len=%d", len);
    stomp_err(hit,io,req,"persist failure at server","Unable to persist message. Can not guarantee reliable delivery, therefore rejecting. Internal error (d_path too long).");    
    return 0;
  }
  DD("d_path(%s) len=%d", d_path, len);
  sha1_safe_base64(d_path+len, req->ap-req->m, req->m);
  d_path[len+27] = 0;
  DD("d_path(%s)", d_path);
  
  name_from_path(t_path, sizeof(t_path), "%s" ZXID_BUS_DIR "tmp/%.*s", ZXID_PATH, 27, d_path+len);
  
  if (!write2_or_append_lock_c_path(t_path, 0, 0, req->ap-req->m, req->m, "zxbus persist", SEEK_SET, O_TRUNC)) {
    stomp_err(hit,io,req,"persist failure at server","Unable to persist message. Can not guarantee reliable delivery, therefore rejecting. Perhaps filesystem is full, read only, wrong permissions, not mounted, or unreachable?");    
    return 0;
  }
  
  if (rename(t_path, d_path)) {
    ERR("Renaming file(%s) to(%s) for atomicity failed: %d %s. Check permissions and that directories exist. euid=%d egid=%d", t_path, d_path, errno, STRERROR(errno), geteuid(), getegid());
    stomp_err(hit,io,req,"persist failure at server","Unable to persist message. Can not guarantee reliable delivery, therefore rejecting. Perhaps filesystem is read only, wrong permissions, full, not mounted, or unreachable?");    
    //hi_sendf(hit, io, req, "ERROR\nmessage:persist failure\nreceipt-id:%.*s\n\nUnable to persist message. Can not guarantee reliable delivery, therefore rejecting. Perhaps filesystem is full?%c", len, rcpt, 0);
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
  /* *** Schedule delivery to happen - or have this PDU take care of it. */
  return 1;
}

/*() Persist a subscription and book it into data structure */

int zxbus_subscribe(struct hi_thr* hit, struct hi_io* io, struct hi_pdu* req)
{
  
}

/* EOF  --  zxbusdist.c */
