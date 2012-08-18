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

#include "akbox.h"
#include "hiios.h"
#include "errmac.h"

#include <ctype.h>
#include <memory.h>
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
#define STOMP_MIN_PDU_SIZE (sizeof("ACK\n\n\0\n")-1)

static struct hi_pdu* stomp_encode_start(struct hi_thr* hit)
{
  struct hi_pdu* resp = hi_pdu_alloc(hit);
  if (!resp) { NEVERNEVER("*** out of pdus in bad place %d", 0); }
  return resp;
}

static int stomp_err(struct hi_thr* hit, struct hi_io* io, struct hi_pdu* req, char* rctp_id, char* ecode, char* emsg)
{
  struct hi_pdu* resp = stomp_encode_start(hit);
  resp->len = sprintf(resp->m, "ERROR\nreceipt-id:%s\nmessage:%s\ncontent-type:text/plain\ncontent-length:%d\n\n%s\0", rcpt_id?rcpt_id:"-", ecode, strlen(emsg), emsg);
  hi_send(hit, io, req, resp);
  return HI_CONN_CLOSE;
}

#define CMD_NI_MSG "Command(%*s) not implemented by server."

static int stomp_cmd_ni(struct hi_thr* hit, struct hi_io* io, struct hi_pdu* req, char* rctp_id, char* cmd)
{
#if 0
  return stomp_err(hit, io, req, rcpt_id, "command not implemented by server", cmd);
#else
  struct hi_pdu* resp = stomp_encode_start(hit);
  char* nl = strchr(cmd, '\n');
  resp->len = sprintf(resp->m, "ERROR\nreceipt-id:%s\nmessage:command not implemented by server\ncontent-type:text/plain\ncontent-length:%d\n\n" CMD_NI_MSG "\0", rcpt_id?rcpt_id:"-", sizeof(CMD_NI_MSG)-3+(nl-cmd), cmd);
  hi_send(hit, io, req, resp);
  return HI_CONN_CLOSE;
#endif
}

static void stomp_got_err(struct hi_thr* hit, struct hi_io* io, struct hi_pdu* req)
{
  struct hi_pdu* resp = stomp_encode_start(hit);
  /*hi_sendv(hit, io, req, resp, len, resp->m, size, req->m + len);*/
}

/* STOMP Received Command Handling */

static void stomp_got_login(struct hi_thr* hit, struct hi_io* io, struct hi_pdu* req)
{
  /* *** add login checks */
  io->ad.stomp.state = STOMP_CONNECTED;
  hi_sendf(hit, io, "CONNECTED\nversion:1.1\nserver:zxbusd-1.x\n\n%c", 0);
}

static int stomp_got_disc(struct hi_thr* hit, struct hi_io* io, struct hi_pdu* req)
{
#if 0
  return stomp_cmd_ni(hit,io,req,0,"DISCONNECT\n");
#else
  hi_sendf(hit, io, "RECEIPT\nreceipt-id:0\n\n%c", 0);  /* *** figure out the real receipt id */
  return HI_CONN_CLOSE;
#endif
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
  if (zxbus_persist(hit, io, req)) {
    hi_sendf(hit, io, "RECEIPT\nreceipt-id:0\n\n%c", 0);  /* *** figure out the real receipt id */
  } else {

  }
  /* struct hi_pdu* resp = stomp_encode_start(hit);
     hi_sendv(hit, io, req, resp, len, resp->m, size, req->m + len);*/
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

/* STOMP decoder and dispatch */

static int stomp_decode_frame(struct hi_thr* hit, struct hi_io* io)
{
  struct hi_pdu* req = io->cur_pdu;
  int len;
  char* command;
  char* hdr;
  char* h;
  char* v;
  char* p = req->m;
  
  /* Skip newlines and check size */

  for (; p < req->ap && *p == '\n'; ++p) ;

  if (req->ap - p < STOMP_MIN_PDU_SIZE) {   /* too little, need more */
    req->need = STOMP_MIN_PDU_SIZE - (req->ap - p);
    return 0;
  }

  /* Extract command */

  command = p;
  hdr = memchr(p, '\n', req->ap - p);
  if (!hdr || ++hdr == req->ap) {
    req->need = MAX(STOMP_MIN_PDU_SIZE - (req->ap - p), 1);
    return 0;
  }
  p = hdr;

  /* Decode headers */

  while (1) {
    h = p;
    p = memchr(p, '\n', req->ap - p);
    if (!p || ++p == req->ap) {
      req->need = MAX(STOMP_MIN_PDU_SIZE - (req->ap - p), 1);
      return 0;
    }
    if (*p == '\n')
      break;         /* Empty line separates headers from body. */
    v = memchr(h, ':', p-h);
    if (!v)
      return stomp_err(hit,io,req,0,"malformed frame received","Header missing colon.");
 
#define HDR(hdr, field, val) } else if (!memcmp(h, hdr, sizeof(hdr)-1)) { if (!req->ad.stomp.field) req->ad.stomp.field = (val)

    if (!memcmp(p, "content-length:", sizeof("content-length:")-1))
    { if (!req->ad.stomp.len) req->ad.stomp.len = len = atoi(v);
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

  req->ad.stomp.body = ++p;

  if (len) {
    if (len < req->ap - p) {
      /* Got complete with content-length */
      p += len;
      if (!*p++)
	return stomp_err(hit,io,req,0,"malformed frame received","No nul to terminate body.");
    } else {
      req->need = len - (req->ap - p) + 1 /* nul */;
      return 0;
    }
  } else {
    /* Scan until nul */
    while (1) {
      if (req->ap - p < 1) {   /* too little, need more */
	req->need = 1;
	return 0;
      }
      if (!*p++) {
	req->ad.stomp.len = len = p - req->ad.stomp.body - 1;
	break;
      }
    }
  }
  
  io->cur_pdu = 0;
  hi_add_to_reqs(io, req);

  /* Command dispatch */

#define CMD(vrb, action) } else if (!memcmp(command, vrb, sizeof(vrb)-1)) { action
 
  if (!memcmp(command, "STOMP\n", sizeof("STOMP\n")-1)
      || !memcmp(command, "CONNECT\n", sizeof("CONNECT\n")-1))
  { stomp_got_login(hit,io,req)
  CMD("SEND\n",        stomp_got_send(hit,io,req) );
  CMD("ACK\n",         stomp_got_ack(hit,io,req) );
  CMD("DISCONNECT\n",  return stomp_got_disc(hit,io,req) );
  CMD("SUBSCRIBE\n",   stomp_got_subsc(hit,io,req) );
  CMD("UNSUBSCRIBE\n", stomp_got_unsubsc(hit,io,req) );
  CMD("BEGIN\n",       stomp_cmd_ni(hit,io,req,0,p) );
  CMD("COMMIT\n",      stomp_cmd_ni(hit,io,req,0,p) );
  CMD("ABORT\n",       stomp_cmd_ni(hit,io,req,0,p) );
  CMD("NACK\n",        stomp_cmd_ni(hit,io,req,0,p) );
  /* Commands client would see (sent by server) */
  CMD("CONNECTED\n",   stomp_cmd_ni(hit,io,req,0,p) );
  CMD("MESSAGE\n",     stomp_cmd_ni(hit,io,req,0,p) );
  CMD("RECEIPT\n",     stomp_cmd_ni(hit,io,req,0,p) );
  CMD("ERROR\n",       return stomp_got_err(hit,io,req)    );
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
