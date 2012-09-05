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
  if (!resp) { hi_dump(hit->shf); NEVERNEVER("*** out of pdus in bad place %d", 0); }
  return resp;
}
#endif

/* Called by:  stomp_cmd_ni, stomp_decode x2 */
int stomp_err(struct hi_thr* hit, struct hi_io* io, struct hi_pdu* req, const char* ecode, const char* emsg)
{
  int len;
  char* rcpt;
  if ((rcpt = req->ad.stomp.receipt)) {
    len = memchr(rcpt, '\n', req->ap - rcpt) - (void*)rcpt;
  } else {
    len = 1;
    rcpt = "-";
  }
  hi_sendf(hit, io, 0, req, "ERROR\nmessage:%s\nreceipt-id:%.*s\ncontent-type:text/plain\ncontent-length:%d\n\n%s%c", ecode, len, rcpt, strlen(emsg), emsg, 0);
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
  hi_sendf(hit, io, 0, req, "ERROR\nmessage:command not implemented by server\nreceipt-id:%.*s\ncontent-type:text/plain\ncontent-length:%d\n\n" CMD_NI_MSG "%c", len, rcpt, sizeof(CMD_NI_MSG)-3+(nl-cmd), (nl-cmd), cmd, 0);
  return HI_CONN_CLOSE;
}

/* Called by:  stomp_decode */
static int stomp_got_err(struct hi_thr* hit, struct hi_io* io, struct hi_pdu* req)
{
  //struct hi_pdu* resp = stomp_encode_start(hit);
  /*hi_sendv(hit, io, 0, req, resp, len, resp->m, size, req->m + len);*/
  return HI_CONN_CLOSE;
}

/*() Send a receipt to client. */

static void stomp_send_receipt(struct hi_thr* hit, struct hi_io* io, struct hi_pdu* req)
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
  hi_sendf(hit, io, 0, req, "RECEIPT\nreceipt-id:%.*s\n\n%c", len, rcpt, 0);
}

/* STOMP Received Command Handling */

/* Called by:  stomp_decode */
static int stomp_got_login(struct hi_thr* hit, struct hi_io* io, struct hi_pdu* req)
{
  /* *** add login checks */
  if (zxbus_login_ent(hit, io, req)) {
    io->ad.stomp.state = STOMP_CONN;
    hi_sendf(hit, io, 0, req, "CONNECTED\nversion:1.1\nserver:zxbusd-1.x\n\n%c", 0);
    return 0;
  } else
    return stomp_err(hit, io, req, "login fail", "login failed either due to nonexistent entity id or bad credential");
}

/* Called by:  stomp_decode */
static int stomp_got_disc(struct hi_thr* hit, struct hi_io* io, struct hi_pdu* req)
{
  /* *** figure out the real receipt id */
  stomp_send_receipt(hit, io, req);
  return HI_CONN_CLOSE;
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
  if (zxbus_persist(hit, io, req)) {
    stomp_send_receipt(hit, io, req);
  } else {
    ERR("Persist Problem. Disk full? %d", 0);
    //hi_sendf(hit, io, 0, req, "ERROR\nmessage:persist failure\nreceipt-id:%.*s\n\nUnable to persist message. Can not guarantee reliable delivery, therefore rejecting.%c", len, rcpt, 0);
  }
}

/*() Process ACK response from client to MESSAGE request sent by server. */

/* Called by:  stomp_decode */
static void stomp_got_ack(struct hi_thr* hit, struct hi_io* io, struct hi_pdu* resp)
{
  int subsc_len, msg_id_len;
  struct hi_pdu* parent;

  subsc_len = resp->ad.stomp.subsc ? (strchr(resp->ad.stomp.subsc, '\n') - resp->ad.stomp.subsc) : 0;
  msg_id_len = resp->ad.stomp.msg_id ? (strchr(resp->ad.stomp.msg_id, '\n') - resp->ad.stomp.msg_id) : 0;
  D("ACK subsc(%.*s) msg_id(%.*s)", subsc_len, subsc_len?resp->ad.stomp.subsc:"", msg_id_len, msg_id_len?resp->ad.stomp.msg_id:"");

  ASSERTOP(resp->req, ==, 0, resp->req);
  LOCK(io->qel.mut, "ack");
  if (io->pending) {
    resp->req = io->pending;
    io->pending = io->pending->n;
    parent = resp->parent = resp->req->parent;
    UNLOCK(io->qel.mut, "ack");
  } else {
    ERR("Unsolicited ACK subsc(%.*s) msg_id(%.*s)", subsc_len, subsc_len?resp->ad.stomp.subsc:"", msg_id_len, msg_id_len?resp->ad.stomp.msg_id:"");
    UNLOCK(io->qel.mut, "ack-unsolicited");
    return;
  }
  
  ASSERT(resp->parent);
  hi_free_resp(hit, resp);
  
  if (--(parent->ad.stomp.ack) <= 0) {
    D("freeing parent(%p)", parent);
    ASSERTOP(parent->ad.stomp.ack, ==, 0, parent->ad.stomp.ack);
    /* Clean up */
    hi_free_req(hit, parent);
  }
}

/* Called by:  stomp_decode */
static void stomp_got_subsc(struct hi_thr* hit, struct hi_io* io, struct hi_pdu* req)
{
  HI_SANITY(hit->shf, hit);
  if (zxbus_subscribe(hit, io, req)) {
    stomp_send_receipt(hit, io, req);
  } else {
    ERR("Subscribe Problem. Disk full? %d", 0);
  }
}

/* Called by:  stomp_decode */
static void stomp_got_unsubsc(struct hi_thr* hit, struct hi_io* io, struct hi_pdu* req)
{
  stomp_cmd_ni(hit,io,req,"UNSUBSCRIBE\n");
}

/*() Nonstandard STOMP command for ZXBUS testing.
 * Based on different body content, diffrent magic can be invoked:
 * dump - dump data structures to stdout with hi_dump() */

/* Called by:  stomp_decode */
static void stomp_got_zxctl(struct hi_thr* hit, struct hi_io* io, struct hi_pdu* req)
{
  D("ZXCTL(%.*s)", req->ad.stomp.len, req->ad.stomp.body);
  if (!memcmp(req->ad.stomp.body, "dump", sizeof("dump")-1)) hi_dump(hit->shf);
  stomp_send_receipt(hit, io, req);
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
    } else if (!memcmp(hdr, "content-type:", sizeof("content-type:"))) { /* ignore */
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
  { return stomp_got_login(hit,io,req);
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
  CMD("ERROR",       return stomp_got_err(hit,io,req) );
  CMD("ZXCTL",       stomp_got_zxctl(hit,io,req) );  /* Custom command */
  } else {
    D("Unknown command(%.*s) ignored.", 4, command);
    stomp_cmd_ni(hit,io,req,p);
  }
  return 0;
}

/* EOF  --  stomp.c */
