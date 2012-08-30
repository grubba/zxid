/* stomp.c  -  STOMP 1.1 protocol for HIIOS engine
 * Copyright (c) 2012 Sampo Kellomaki (sampo@iki.fi), All Rights Reserved.
 * This is confidential unpublished proprietary source code of the author.
 * NO WARRANTY, not even implied warranties. Contains trade secrets.
 * Distribution prohibited unless authorized in writing. See file COPYING.
 * Special grant: http.c may be used with zxid open source project under
 * same licensing terms as zxid itself.
 * $Id$
 *
 * 16.8.2012, created, based on http and smtp --Sampo
 * 19.8.2012, added tolerance for CRLF where strictly LF is meant --Sampo
 *
 * STOMP 1.1 frame is considered a PDU and consists of
 *
 *   COMMAND\n       -- lines end in LF (not CRLF)
 *   header:value\n  -- zero or more
 *   \n              -- blank line separates headers and body
 *   payload
 *   \0
 *   \n              -- zero, or more in case of heart beats
 *
 * See also:  http://stomp.github.com/stomp-specification-1.1.html (20110331)
 * Todo: implement heart beat generation and checking
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

#if 0
/* Called by: */
static struct hi_pdu* stomp_encode_start(struct hi_thr* hit)
{
  struct hi_pdu* resp = hi_pdu_alloc(hit,"stomp_enc_start");
  if (!resp) { NEVERNEVER("*** out of pdus in bad place %d", 0); }
  return resp;
}
#endif

/* Called by:  stomp_cmd_ni, stomp_decode x2 */
static int stomp_err(struct hi_thr* hit, struct hi_io* io, struct hi_pdu* req, const char* ecode, const char* emsg)
{
  int len;
  char* rcpt;
  if ((rcpt = req->ad.stomp.receipt)) {
    len = memchr(rcpt, '\n', req->ap - rcpt) - (void*)rcpt;
  } else {
    len = 1;
    rcpt = "-";
  }
  hi_sendf(hit, io, req, "ERROR\nmessage:%s\nreceipt-id:%.*s\ncontent-type:text/plain\ncontent-length:%d\n\n%s%c", ecode, len, rcpt, strlen(emsg), emsg, 0);
  return HI_CONN_CLOSE;
}

#define CMD_NI_MSG "Command(%.*s) not implemented by server."

/* Called by:  stomp_decode x8, stomp_got_ack, stomp_got_subsc, stomp_got_unsubsc */
static int stomp_cmd_ni(struct hi_thr* hit, struct hi_io* io, struct hi_pdu* req, const char* cmd)
{
  const char* nl = strchr(cmd, '\n');
  int len;
  char* rcpt;
  if ((rcpt = req->ad.stomp.receipt)) {
    len = memchr(rcpt, '\n', req->ap - rcpt) - (void*)rcpt;
  } else {
    len = 1;
    rcpt = "-";
  }
  hi_sendf(hit, io, req, "ERROR\nmessage:command not implemented by server\nreceipt-id:%.*s\ncontent-type:text/plain\ncontent-length:%d\n\n" CMD_NI_MSG "%c", len, rcpt, sizeof(CMD_NI_MSG)-3+(nl-cmd), (nl-cmd), cmd, 0);
  return HI_CONN_CLOSE;
}

/* Called by:  stomp_decode */
static int stomp_got_err(struct hi_thr* hit, struct hi_io* io, struct hi_pdu* req)
{
  //struct hi_pdu* resp = stomp_encode_start(hit);
  /*hi_sendv(hit, io, req, resp, len, resp->m, size, req->m + len);*/
  return HI_CONN_CLOSE;
}

/* STOMP Received Command Handling */

/* Called by:  stomp_decode */
static void stomp_got_login(struct hi_thr* hit, struct hi_io* io, struct hi_pdu* req)
{
  /* *** add login checks */
  io->ad.stomp.state = STOMP_CONN;
  hi_sendf(hit, io, req, "CONNECTED\nversion:1.1\nserver:zxbusd-1.x\n\n%c", 0);
}

/* Called by:  stomp_decode */
static int stomp_got_disc(struct hi_thr* hit, struct hi_io* io, struct hi_pdu* req)
{
  hi_sendf(hit, io, req, "RECEIPT\nreceipt-id:0\n\n%c", 0);  /* *** figure out the real receipt id */
  return HI_CONN_CLOSE;
}

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
    printf("FMT0 persisted at(%s) (%.*s) len=%d receipt(%.*s)\n", d_path, MIN(req->ap-req->ad.stomp.body, 10), req->ad.stomp.body, req->ap-req->m, nl?(nl-req->ad.stomp.receipt):0, nl?req->ad.stomp.receipt:"");
  }
  /* *** Schedule delivery to happen - or have this PDU take care of it. */
  return 1;
}

/*() Main function for receiving audit bus summary log lines from SPs.
 * This function will first store the line in a persistent way (RAID1
 * arrangement needs to be implemented at the OS level), and then,
 * perhaps, attempt to deliver the message to all subscribers. Indeed,
 * delivery should be attempted first and if successful, the persistence
 * is not necessary. If delivery is unsuccessful, the delivery needs
 * to be retried, i.e. this is a store-and-forward system. However,
 * the delivery first approach needs extensive IO engine
 * operations and it thus may be easier to just store the message
 * first and then have a separate process attempt the sending. This
 * latter is the approach adopted here. */

/* Called by:  stomp_decode */
static void stomp_got_send(struct hi_thr* hit, struct hi_io* io, struct hi_pdu* req)
{
  int len;
  char* rcpt;
  if ((rcpt = req->ad.stomp.receipt)) {
    len = (char*)memchr(rcpt, '\n', req->ap - rcpt) - rcpt;
  } else {
    len = 1;
    rcpt = "-";
  }
  DD("rcpt(%.*s) len=%d", len, rcpt, len);
  HI_SANITY(hit->shf, hit);
  if (zxbus_persist(hit, io, req)) {
    hi_sendf(hit, io, req, "RECEIPT\nreceipt-id:%.*s\n\n%c", len, rcpt, 0);
  } else {
    ERR("Persist Problem. Disk full? %d", 0);
    //hi_sendf(hit, io, req, "ERROR\nmessage:persist failure\nreceipt-id:%.*s\n\nUnable to persist message. Can not guarantee reliable delivery, therefore rejecting.%c", len, rcpt, 0);
  }
}

/* Called by:  stomp_decode */
static void stomp_got_ack(struct hi_thr* hit, struct hi_io* io, struct hi_pdu* req)
{
  stomp_cmd_ni(hit,io,req,"ACK\n");
  /* struct hi_pdu* resp = stomp_encode_start(hit);
     hi_sendv(hit, io, req, resp, len, resp->m, size, req->m + len);*/
}

/* Called by:  stomp_decode */
static void stomp_got_subsc(struct hi_thr* hit, struct hi_io* io, struct hi_pdu* req)
{
  stomp_cmd_ni(hit,io,req,"SUBSCRIBE\n");
}

/* Called by:  stomp_decode */
static void stomp_got_unsubsc(struct hi_thr* hit, struct hi_io* io, struct hi_pdu* req)
{
  stomp_cmd_ni(hit,io,req,"UNSUBSCRIBE\n");
}

/*() STOMP decoder and dispatch.
 * Return 0 for no error (including need more and PDU complete and processed),
 * 1 to force closing connection. */

/* Called by:  hi_read */
int stomp_decode(struct hi_thr* hit, struct hi_io* io)
{
  struct hi_pdu* req = io->cur_pdu;
  int len = 0;
  char* command;
  char* hdr;
  char* val;
  char* p = req->m;

  D("decode req(%p)->need=%d (%.*s)", req, req->need, MIN(req->ap - req->m, 4), req->m);
  
  HI_SANITY(hit->shf, hit);

  /* Skip newlines and check size */

  for (; p < req->ap && ONE_OF_2(*p, '\n', '\r'); ++p) ;

  if (req->ap - p < STOMP_MIN_PDU_SIZE) {   /* too little, need more */
    req->need = STOMP_MIN_PDU_SIZE;
    D("need=%d have=%d",req->need,req->ap-req->m);
    return  HI_NEED_MORE;
  }

  /* Extract command */

  command = p;
  hdr = memchr(p, '\n', req->ap - p);
  if (!hdr || ++hdr == req->ap) {
    req->need = MAX(STOMP_MIN_PDU_SIZE, req->ap - p + 1);
    D("need=%d have=%d",req->need,req->ap-req->m);
    return  HI_NEED_MORE;
  }
  memset(&req->ad.stomp, 0, sizeof(req->ad.stomp));
  p = hdr;

  /* Decode headers
   * 012345678901234567890
   * STOMP\n\n\0
   *         ^-p
   * STOMP\r\n\r\n\0
   *           ^-p
   * STOMP\nhost:foo\n\n\0
   *        ^-p        ^-pp
   * STOMP\r\nhost:foo\r\n\r\n\0
   *          ^-p          ^-pp
   * STOMP\nhost:foo\naccept-version:1.1\n\n\0
   *        ^-p       ^-pp                 ^-ppp
   * STOMP\r\nhost:foo\r\naccept-version:1.1\r\n\r\n\0
   *          ^-p         ^-pp                   ^-ppp
   */

  while (!ONE_OF_2(*p,'\n','\r')) {
    hdr = p;
    p = memchr(p, '\n', req->ap - p);
    if (!p || ++p == req->ap) {
      req->need = MAX(STOMP_MIN_PDU_SIZE, req->ap - p + 1);
      D("need=%d have=%d",req->need,req->ap-req->m);
      return HI_NEED_MORE;
    }
    val = memchr(hdr, ':', p-hdr);
    if (!val)
      return stomp_err(hit,io,req,"malformed frame received","Header missing colon.");
    ++val; /* skip : */

#define HDR(header, field, valu) } else if (!memcmp(hdr, header, sizeof(header)-1)) { if (!req->ad.stomp.field) req->ad.stomp.field = (valu)

    if (!memcmp(hdr, "content-length:", sizeof("content-length:")-1))
    { if (!req->ad.stomp.len) {
        req->ad.stomp.len = len = atoi(val);
	req->need = len + p - req->m + 2;  /* not accurate if more headers follow, but fix below */
      }
      D("len=%d need=%d (%.*s)", len, req->need, p-hdr-1, hdr);
    } else if (!memcmp(p, "content-type:", sizeof("content-type:"))) { /* ignore */
    HDR("receipt:",        receipt,   val);
    HDR("destination:",    dest,      val);
    HDR("host:",           host,      val);
    HDR("version:",        vers,      val);
    HDR("accept-version:", acpt_vers, val);
    HDR("server:",         server,    val);
    HDR("heart-beat:",     heart_bt,  val);
    HDR("login:",          login,     val);
    HDR("passcode:",       pw,        val);
    HDR("session:",        session,   val);
    HDR("transaction:",    tx_id,     val);
    HDR("id:",             subs_id,   val);
    HDR("subscription:",   subsc,     val);
    HDR("ack:",            ack,       val);
    HDR("message-id:",     msg_id,    val);
    HDR("receipt-id:",     rcpt_id,   val);  D("receipt-id(%.*s)", 4, req->ad.stomp.rcpt_id);
    } else {
      D("Unknown header(%.*s) ignored.", p-hdr, hdr);
    }
  }
  
  /* Now body */

  if (*p == '\r') ++p;
  req->ad.stomp.body = ++p;

  /* p now points to first byte of body (after \n\n; at nul if no body) */

  if (len) {
    req->need = p - req->m + len + 1 /* nul */;  /* req->need has to be set correctly for hi_checkmore() to work right. */
    if (len < req->ap - p) {
      /* Got complete with content-length */
      p += len;
      if (*p++)
	return stomp_err(hit,io,req,"malformed frame received","No nul to terminate body.");
    } else {
      D("need=%d have=%d",req->need,req->ap-req->m);
      return HI_NEED_MORE;
    }
  } else {
    /* Scan until nul */
    while (1) {
      if (req->ap - p < 1) {   /* too little, need more */
	req->need = req->ap - req->m + 1;
	D("need=%d have=%d",req->need,req->ap-req->m);
	return HI_NEED_MORE;
      }
      if (!*p++) {  /* nul termination found */
	req->ad.stomp.len = len = p - req->ad.stomp.body - 1;
	req->need = p - req->m;
	break;
      }
    }
  }
  
  HI_SANITY(hit->shf, hit);
  hi_add_to_reqs(hit, io, req, STOMP_MIN_PDU_SIZE);
  HI_SANITY(hit->shf, hit);

  /* Command dispatch */

#define CMD(vrb, action) } else if (!memcmp(command, vrb, sizeof(vrb)-1)) { action
 
  if (!memcmp(command, "STOMP", sizeof("STOMP")-1)
      || (!memcmp(command, "CONNECT", sizeof("CONNECT")-1)
	  &&ONE_OF_2(command[sizeof("CONNECT")],'\n','\r')))
  { stomp_got_login(hit,io,req);
  CMD("SEND",        stomp_got_send(hit,io,req) );
  CMD("ACK",         stomp_got_ack(hit,io,req) );
  CMD("DISCONNECT",  return stomp_got_disc(hit,io,req) );
  CMD("SUBSCRIBE",   stomp_got_subsc(hit,io,req) );
  CMD("UNSUBSCRIBE", stomp_got_unsubsc(hit,io,req) );
  CMD("BEGIN",       stomp_cmd_ni(hit,io,req,p) );
  CMD("COMMIT",      stomp_cmd_ni(hit,io,req,p) );
  CMD("ABORT",       stomp_cmd_ni(hit,io,req,p) );
  CMD("NACK",        stomp_cmd_ni(hit,io,req,p) );
  /* Commands client would see (sent by server) */
  CMD("CONNECTED",   stomp_cmd_ni(hit,io,req,p) );
  CMD("MESSAGE",     stomp_cmd_ni(hit,io,req,p) );
  CMD("RECEIPT",     stomp_cmd_ni(hit,io,req,p) );
  CMD("ERROR",       return stomp_got_err(hit,io,req)    );
  } else {
    D("Unknown command(%.*s) ignored.", 4, command);
    stomp_cmd_ni(hit,io,req,p);
  }
  return 0;
}

/* EOF  --  stomp.c */
