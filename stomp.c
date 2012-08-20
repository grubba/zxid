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

#include <ctype.h>
#include <memory.h>
#include <stdlib.h>
#include <netinet/in.h> /* htons(3) and friends */


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

static struct hi_pdu* stomp_encode_start(struct hi_thr* hit)
{
  struct hi_pdu* resp = hi_pdu_alloc(hit);
  if (!resp) { NEVERNEVER("*** out of pdus in bad place %d", 0); }
  return resp;
}

static int stomp_err(struct hi_thr* hit, struct hi_io* io, struct hi_pdu* req, char* receipt_id, char* ecode, char* emsg)
{
  struct hi_pdu* resp = stomp_encode_start(hit);
  resp->len = sprintf(resp->m, "ERROR\nreceipt-id:%s\nmessage:%s\ncontent-type:text/plain\ncontent-length:%d\n\n%s%c", receipt_id?receipt_id:"-", ecode, strlen(emsg), emsg, 0);
  hi_send(hit, io, req, resp);
  return HI_CONN_CLOSE;
}

#define CMD_NI_MSG "Command(%*s) not implemented by server."

static int stomp_cmd_ni(struct hi_thr* hit, struct hi_io* io, struct hi_pdu* req, char* receipt_id, char* cmd)
{
#if 0
  return stomp_err(hit, io, req, receipt_id, "command not implemented by server", cmd);
#else
  struct hi_pdu* resp = stomp_encode_start(hit);
  char* nl = strchr(cmd, '\n');
  resp->len = sprintf(resp->m, "ERROR\nreceipt-id:%s\nmessage:command not implemented by server\ncontent-type:text/plain\ncontent-length:%d\n\n" CMD_NI_MSG "%c", receipt_id?receipt_id:"-", sizeof(CMD_NI_MSG)-3+(nl-cmd), (nl-cmd), cmd, 0);
  hi_send(hit, io, req, resp);
  return HI_CONN_CLOSE;
#endif
}

static int stomp_got_err(struct hi_thr* hit, struct hi_io* io, struct hi_pdu* req)
{
  //struct hi_pdu* resp = stomp_encode_start(hit);
  /*hi_sendv(hit, io, req, resp, len, resp->m, size, req->m + len);*/
  return HI_CONN_CLOSE;
}

/* STOMP Received Command Handling */

static void stomp_got_login(struct hi_thr* hit, struct hi_io* io, struct hi_pdu* req)
{
  /* *** add login checks */
  io->ad.stomp.state = STOMP_CONN;
  hi_sendf(hit, io, req, "CONNECTED\nversion:1.1\nserver:zxbusd-1.x\n\n%c", 0);
}

static int stomp_got_disc(struct hi_thr* hit, struct hi_io* io, struct hi_pdu* req)
{
  hi_sendf(hit, io, req, "RECEIPT\nreceipt-id:0\n\n%c", 0);  /* *** figure out the real receipt id */
  return HI_CONN_CLOSE;
}

int zxbus_persist(struct hi_thr* hit, struct hi_io* io, struct hi_pdu* req)
{
  /* *** Actually persist the message */
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

static void stomp_got_send(struct hi_thr* hit, struct hi_io* io, struct hi_pdu* req)
{
  HI_SANITY(hit->shf, hit);
  if (zxbus_persist(hit, io, req)) {
    hi_sendf(hit, io, req, "RECEIPT\nreceipt-id:0\n\n%c", 0);  /* *** figure out the real receipt id */
  } else {
    ERR("Persist Problem. Disk full? %d", 0);
    hi_sendf(hit, io, req, "ERROR\nmessage:persist failure\nreceipt-id:0\n\nUnable to persist message. Can not guarantee reliable delivery, therefore rejecting.%c", 0);  /* *** figure out the real receipt id */
  }
}

static void stomp_got_ack(struct hi_thr* hit, struct hi_io* io, struct hi_pdu* req)
{
  stomp_cmd_ni(hit,io,req,0,"ACK\n");
  /* struct hi_pdu* resp = stomp_encode_start(hit);
     hi_sendv(hit, io, req, resp, len, resp->m, size, req->m + len);*/
}

static void stomp_got_subsc(struct hi_thr* hit, struct hi_io* io, struct hi_pdu* req)
{
  stomp_cmd_ni(hit,io,req,0,"SUBSCRIBE\n");
}

static void stomp_got_unsubsc(struct hi_thr* hit, struct hi_io* io, struct hi_pdu* req)
{
  stomp_cmd_ni(hit,io,req,0,"UNSUBSCRIBE\n");
}

/*() STOMP decoder and dispatch */

int stomp_decode(struct hi_thr* hit, struct hi_io* io)
{
  struct hi_pdu* req = io->cur_pdu;
  int len = 0;
  char* command;
  char* hdr;
  char* h;
  char* v;
  char* p = req->m;

  D("decode req(%p) (%.*s)", req, MIN(req->ap - req->m, 4), req->m);
  
  HI_SANITY(hit->shf, hit);

  /* Skip newlines and check size */

  for (; p < req->ap && ONE_OF_2(*p, '\n', '\r'); ++p) ;

  if (req->ap - p < STOMP_MIN_PDU_SIZE) {   /* too little, need more */
    req->need = STOMP_MIN_PDU_SIZE;
    D("need=%d",req->need);
    return 0;
  }

  /* Extract command */

  command = p;
  hdr = memchr(p, '\n', req->ap - p);
  if (!hdr || ++hdr == req->ap) {
    req->need = MAX(STOMP_MIN_PDU_SIZE, req->ap - p + 1);
    D("need=%d",req->need);
    return 0;
  }
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
    h = p;
    p = memchr(p, '\n', req->ap - p);
    if (!p || ++p == req->ap) {
      req->need = MAX(STOMP_MIN_PDU_SIZE, req->ap - p + 1);
      D("need=%d",req->need);
      return 0;
    }
    v = memchr(h, ':', p-h);
    if (!v)
      return stomp_err(hit,io,req,0,"malformed frame received","Header missing colon.");
 
#define HDR(hdr, field, val) } else if (!memcmp(h, hdr, sizeof(hdr)-1)) { if (!req->ad.stomp.field) req->ad.stomp.field = (val)

    if (!memcmp(h, "content-length:", sizeof("content-length:")-1))
    { if (!req->ad.stomp.len) req->ad.stomp.len = len = atoi(v); D("len=%d",len);
    HDR("host:",           host,      v);
    HDR("receipt:",        receipt,   v);
    HDR("receipt-id:",     rcpt_id,   v);
    HDR("version:",        vers,      v);
    HDR("accept-version:", acpt_vers, v);
    HDR("transaction:",    tx_id,     v);
    HDR("login:",          login,     v);
    HDR("passcode:",       pw,        v);
    HDR("session:",        session,   v);
    HDR("id:",             subs_id,   v);
    HDR("subscription:",   subsc,     v);
    HDR("server:",         server,    v);
    HDR("ack:",            ack,       v);
    HDR("message-id:",     msg_id,    v);
    HDR("destination:",    dest,      v);
    HDR("heart-beat:",     heart_bt,  v);
    } else if (!memcmp(p, "content-type:", sizeof("content-type:"))) { /* ignore */
    } else {
      D("Unknown header(%*s) ignored.", h-p, h);
    }
  }
  
  /* Now body */

  if (*p == '\r') ++p;
  req->ad.stomp.body = ++p;

  if (len) {
    if (len < req->ap - p) {
      /* Got complete with content-length */
      p += len;
      if (*p++)
	return stomp_err(hit,io,req,0,"malformed frame received","No nul to terminate body.");
    } else {
      req->need = len + 1 /* nul */;
      D("need=%d",req->need);
      return 0;
    }
  } else {
    /* Scan until nul */
    while (1) {
      if (req->ap - p < 1) {   /* too little, need more */
	req->need = req->ap - req->m + 1;
	D("need=%d",req->need);
	return 0;
      }
      if (!*p++) {  /* nul termination found */
	req->ad.stomp.len = len = p - req->ad.stomp.body - 1;
	break;
      }
    }
  }
  
  HI_SANITY(hit->shf, hit);
  io->cur_pdu = 0;
  hi_add_to_reqs(io, req);
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
  CMD("BEGIN",       stomp_cmd_ni(hit,io,req,0,p) );
  CMD("COMMIT",      stomp_cmd_ni(hit,io,req,0,p) );
  CMD("ABORT",       stomp_cmd_ni(hit,io,req,0,p) );
  CMD("NACK",        stomp_cmd_ni(hit,io,req,0,p) );
  /* Commands client would see (sent by server) */
  CMD("CONNECTED",   stomp_cmd_ni(hit,io,req,0,p) );
  CMD("MESSAGE",     stomp_cmd_ni(hit,io,req,0,p) );
  CMD("RECEIPT",     stomp_cmd_ni(hit,io,req,0,p) );
  CMD("ERROR",       return stomp_got_err(hit,io,req)    );
  } else {
    D("Unknown command(%*s) ignored.", 4, command);
    stomp_cmd_ni(hit,io,req,0,p);
  }
  return 0;
}

#if 0
/*() STOMP server side decoder: Decode requests from producer. */

int stomp_decode_req(struct hi_thr* hit, struct hi_io* io)
{
  int ret;
  char* p;
  struct hi_pdu* req = io->cur_pdu;
  D("stomp_state(%d) scan(%.*s)", io->ad.stomp.state, MIN(7, req->ap - req->scan), req->scan);
  switch (io->ad.stomp.state) {
  case STOMP_START:  return stomp_connected(hit, io, req);
  case STOMP_MAIN:   return stomp_main(hit, io, req);
  case STOMP_MSG:    return stomp_wait_ack(hit, io, req);
  case STOMP_END:    return stomp_close(hit, io, req);
  default: NEVERNEVER("impossible STOMP state %d", io->ad.stomp.state);
  }
  return 0;
}

/*() STOMP client side decoder: decode responses from remote server */

int stomp_decode_resp(struct hi_thr* hit, struct hi_io* io)
{
  int ret;
  char* p;
  struct hi_pdu* resp = io->cur_pdu;
  D("stomp_state(%d) scan(%.*s)", io->ad.stomp.state, MIN(7, resp->ap - resp->scan), resp->scan);
  switch (io->ad.stomp.state) {
  case STOMP_INIT: return stomp_resp_wait_220_greet(hit, io, resp);
  case STOMP_EHLO: D("Unexpected state %x", io->ad.stomp.state);
  case STOMP_RDY:  return stomp_resp_wait_250_from_ehlo(hit, io, resp);
  case STOMP_MAIL:
  case STOMP_RCPT:
  case STOMP_DATA: D("Unexpected state %x", io->ad.stomp.state);
  case STOMP_SEND: return stomp_resp_wait_354_from_data(hit, io, resp);
  case STOMP_SENT: return stomp_resp_wait_250_msg_sent(hit, io, resp);
  case STOMP_QUIT: return stomp_resp_wait_221_goodbye(hit, io, resp);
  default: NEVERNEVER("impossible STOMP state %d", io->ad.stomp.state);
  }
  return 0;
}
#endif

/* EOF  --  stomp.c */
