/* hiwrite.c  -  Hiquu I/O Engine Write Operation.
 * Copyright (c) 2006,2012 Sampo Kellomaki (sampo@iki.fi), All Rights Reserved.
 * This is confidential unpublished proprietary source code of the author.
 * NO WARRANTY, not even implied warranties. Contains trade secrets.
 * Distribution prohibited unless authorized in writing. See file COPYING.
 * Special grant: hiwrite.c may be used with zxid open source project under
 * same licensing terms as zxid itself.
 * $Id$
 *
 * 15.4.2006, created over Easter holiday --Sampo
 * 22.4.2006, refined multi iov sends over the weekend --Sampo
 * 16.8.2012, modified license grant to allow use with ZXID.org --Sampo
 *
 * Idea: Consider separate lock for maintenance of to_write queue and separate
 * for in_write, iov, and actual wrintev().
 */

#include <pthread.h>
#include <memory.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <errno.h>
#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "platform.h"
#include "errmac.h"
#include "akbox.h"
#include "hiios.h"

extern int zx_debug;

/*() Schedule to be sent a response.
 * If req is supplied, the response is taken to be response to that.
 * Otherwise resp istreated as a stand along PDU, unsolicited response if you like. */

/* Called by:  hi_send1, hi_send2, hi_send3 */
void hi_send0(struct hi_thr* hit, struct hi_io* io, struct hi_pdu* req, struct hi_pdu* resp)
{
  int write_now = 0;
  HI_SANITY(hit->shf, hit);
  if (req) {
    resp->req = req;
    resp->n = req->reals;
    req->reals = resp;
  } else {
    resp->req = resp->n = 0;
  }

#if 0
  LOCK(hit->shf->todo_mut, "hi_in_out-done");
  --io->n_thr;
  ASSERT(io->n_thr >= 0);
  UNLOCK(hit->shf->todo_mut, "hi_in_out-done");
#endif

  LOCK(io->qel.mut, "send0");
  if (!io->to_write_produce)
    io->to_write_consume = resp;
  else
    io->to_write_produce->qel.n = &resp->qel;
  io->to_write_produce = resp;
  resp->qel.n = 0;
  ++io->n_to_write;
  ++io->n_pdu_out;
  if (!io->writing)
    io->writing = write_now = 1;
  UNLOCK(io->qel.mut, "send0");
  
  HI_SANITY(hit->shf, hit);
  D("hisend fd(%x) pdu(%p) n_iov=%d iov0(%.*s)", io->fd, resp, resp->n_iov, MIN(resp->iov->iov_len,4), (char*)resp->iov->iov_base);

  if (write_now) {
    /* Try cranking the write machine right away! *** should we fish out any todo queue item that may stomp on us? How to deal with thread that has already consumed from the todo_queue? */
    hi_write(hit, io);
#if 0
    LOCK(hit->shf->todo_mut, "hi_in_out-done");
    --io->n_thr;
    ASSERT(io->n_thr >= 0);
    UNLOCK(hit->shf->todo_mut, "hi_in_out-done");
#endif
  } else {
    hi_todo_produce(hit->shf, &io->qel);
  }
}

/*() Frontend to hi_send1() which uses hi_send0() to send one segment message. */

/* Called by:  hi_sendf, http_send_err, stomp_cmd_ni, stomp_err, test_ping_reply */
void hi_send(struct hi_thr* hit, struct hi_io* io, struct hi_pdu* req, struct hi_pdu* resp)
{
  hi_send1(hit, io, req, resp, resp->need, resp->m);
}

/*() Uses hi_send0() to send one segment message. */

/* Called by:  hi_send, smtp_resp_wait_250_from_ehlo, smtp_resp_wait_354_from_data, smtp_send */
void hi_send1(struct hi_thr* hit, struct hi_io* io, struct hi_pdu* req, struct hi_pdu* resp, int len0, char* d0)
{
  resp->n_iov = 1;
  resp->iov[0].iov_len = len0;
  resp->iov[0].iov_base = d0;
  //HEXDUMP("iov0: ", d0, d0+len0, 800);
  hi_send0(hit, io, req, resp);
}

/*() Uses hi_send0() to send two segment message. */

/* Called by:  hmtp_send */
void hi_send2(struct hi_thr* hit, struct hi_io* io, struct hi_pdu* req, struct hi_pdu* resp, int len0, char* d0, int len1, char* d1)
{
  resp->n_iov = 2;
  resp->iov[0].iov_len  = len0;
  resp->iov[0].iov_base = d0;
  resp->iov[1].iov_len  = len1;
  resp->iov[1].iov_base = d1;
  //HEXDUMP("iov0: ", d0, d0+len0, 800);
  //HEXDUMP("iov1: ", d1, d1+len1, 800);
  hi_send0(hit, io, req, resp);
}

/*() Uses hi_send0() to send three segment message. */

/* Called by:  hmtp_send */
void hi_send3(struct hi_thr* hit, struct hi_io* io, struct hi_pdu* req, struct hi_pdu* resp, int len0, char* d0, int len1, char* d1, int len2, char* d2)
{
  resp->n_iov = 3;
  resp->iov[0].iov_len  = len0;
  resp->iov[0].iov_base = d0;
  resp->iov[1].iov_len  = len1;
  resp->iov[1].iov_base = d1;
  resp->iov[2].iov_len  = len2;
  resp->iov[2].iov_base = d2;
  //HEXDUMP("iov0: ", d0, d0+len0, 800);
  //HEXDUMP("iov1: ", d1, d1+len1, 800);
  //HEXDUMP("iov2: ", d2, d2+len2, 800);
  hi_send0(hit, io, req, resp);
}

/*() Send formatted response.
 * Uses underlying machiner of hi_send0().
 * *** As req argument is entirely lacking, this must be to send unsolicited responses. */

/* Called by:  hi_accept, smtp_data, smtp_ehlo, smtp_mail_from x2, smtp_rcpt_to x3, smtp_resp_wait_220_greet, smtp_resp_wait_250_msg_sent, stomp_got_disc, stomp_got_login, stomp_got_send x2 */
void hi_sendf(struct hi_thr* hit, struct hi_io* io, struct hi_pdu* req, char* fmt, ...)
{
  va_list pv;
  struct hi_pdu* pdu = hi_pdu_alloc(hit);
  if (!pdu) { ERR("Out of PDUs in bad place fmt(%s)", fmt); return; }
  
  va_start(pv, fmt);
  pdu->need = vsnprintf(pdu->m, pdu->lim - pdu->m, fmt, pv);
  va_end(pv);
  
  pdu->ap += pdu->need;
  hi_send(hit, io, req, pdu);
}

/*() Process io->to_write_consume to produce an iov and move the PDUs to io->inwrite.
 * This is the main (only?) way how writes end up in hiios poll machinery to be written.
 * The only consumer of the io->to_write_consume queue. */

/* Called by:  hi_write */
static void hi_make_iov(struct hi_io* io)
{
  struct hi_pdu* pdu;
  struct iovec* lim = io->iov+HI_N_IOV;
  struct iovec* cur = io->iov_cur = io->iov;
  D("make_iov(%x)", io->fd);
  LOCK(io->qel.mut, "make_iov");
  while ((pdu = io->to_write_consume) && (cur + pdu->n_iov) <= lim) {
    memcpy(cur, pdu->iov, pdu->n_iov * sizeof(struct iovec));
    cur += pdu->n_iov;
    
    if (!(io->to_write_consume = pdu->wn))    /* consume from to_write */
      io->to_write_produce = 0;
    --io->n_to_write;
    pdu->wn = io->in_write;                   /* produce to in_write */
    io->in_write = pdu;
    
    ASSERT(io->n_to_write >= 0);
    ASSERT(pdu->n_iov && pdu->iov[0].iov_len);   /* Empty writes can lead to infinite loops */
    D("make_iov(%x) added pdu(%p) n_iov=%d", io->fd, pdu, cur - io->iov_cur);
  }
  UNLOCK(io->qel.mut, "make_iov");
  io->n_iov = cur - io->iov_cur;
}

/*() Free a response PDU.
 * *** Here complex determination about freeability of a PDU needs to be done.
 * For now we "fake" it by assuming that a response sufficies to free request.
 * In real life you would have to consider
 * a. multiple responses
 * b. subrequests and their responses
 * c. possibility of sending a response before processing of request itself has ended
 */

/* Called by:  hi_clear_iov */
void hi_free_resp(struct hi_thr* hit, struct hi_pdu* resp)
{
  struct hi_pdu* pdu = resp->req->reals;
  
  HI_SANITY(hit->shf, hit);

  /* Remove resp from request's real response list. resp MUST be in this list: if it
   * is not, pdu->n (next) pointer chasing will lead to NULL dereference (by design). */
  
  if (resp == pdu)
    resp->req->reals = pdu->n;
  else
    for (; 1; pdu = pdu->n)
      if (pdu->n == resp) {
	pdu->n = resp->n;
	break;
      }
  
  resp->qel.n = &hit->free_pdus->qel;         /* move to free list */
  hit->free_pdus = resp;
  D("resp(%p) freed", resp);

  HI_SANITY(hit->shf, hit);
}

/*() Free a request, and its real consequences (response, subrequests, etc.).
 * May be called either because individual resp was done, or because of connection close. */

/* Called by:  hi_close x2, hi_free_req_fe */
void hi_free_req(struct hi_thr* hit, struct hi_pdu* req)
{
  struct hi_pdu* pdu;
  
  HI_SANITY(hit->shf, hit);

  for (pdu = req->reals; pdu; pdu = pdu->n) { /* free dependent resps */
    pdu->qel.n = &hit->free_pdus->qel;
    hit->free_pdus = pdu;
  }
  
  req->qel.n = &hit->free_pdus->qel;         /* move to free list */
  hit->free_pdus = req;
  D("req(%p) freed", req);

  HI_SANITY(hit->shf, hit);
}

/*() Free a request, assuming it is associated with a frontend.
 * Will also remove the PDU frm the frontend reqs queue. */

/* Called by:  hi_clear_iov */
void hi_free_req_fe(struct hi_thr* hit, struct hi_pdu* req)
{
  struct hi_pdu* pdu;
  ASSERT(req->fe);
  if (!req->fe)
    return;
  HI_SANITY(hit->shf, hit);

  /* Scan the frontend to find the reference. The theory is that
   * hi_free_req_fe() only gets called when its known that the request is in the queue.
   * If it is not, the loop will run off the end and crash with NULL pointer. */
  
  LOCK(req->fe->qel.mut, "del-from-reqs");
  pdu = req->fe->reqs;
  if (pdu == req)
    req->fe->reqs = req->n;
  else
    for (; 1; pdu = pdu->n)
      if (pdu->n == req) {
	pdu->n = req->n;
	break;
      }
  UNLOCK(req->fe->qel.mut, "del-from-reqs");

  HI_SANITY(hit->shf, hit);
  hi_free_req(hit, req);
}

/*() Add a PDU to the reqs associated with the io object.
 * Often moving PDU to reqs means it should stop being cur_pdu.
 * If minlen (protocol dependent PDU minimum length) is passed,
 * hi_ckeckmore() processing is triggered and cur_pdu dealt with.
 * Clearing cur_pdu is important to enable the hi_in_out() to
 * admit new worker thread to perform read work. */

/* Called by:  http_decode, stomp_decode, test_ping */
void hi_add_to_reqs(struct hi_thr* hit, struct hi_io* io, struct hi_pdu* req, int minlen)
{
  LOCK(io->qel.mut, "add_to_reqs");
  if (minlen) {
    ASSERTOP(io->cur_pdu, ==, req);
    ASSERT(io->reading);
    io->reading = 0;  /* reading was set in hi_in_out() */
    hi_checkmore(hit, io, req, minlen);
  }
  req->fe = io;
  req->n = io->reqs;
  io->reqs = req;
  UNLOCK(io->qel.mut, "add_to_reqs");
}

/*() Post process iov after write.
 * Determine if any (resp) PDUs got completely written and
 * warrant deletion of entire chaing of req and responses,
 * including subreqs and their responses. */

/* Called by:  hi_write */
static void hi_clear_iov(struct hi_thr* hit, struct hi_io* io, int n)
{
  struct hi_pdu* pdu;
  io->n_written += n;
  while (io->n_iov && n) {
    if (n >= io->iov_cur->iov_len) {
      n -= io->iov_cur->iov_len;
      ++io->iov_cur;
      --io->n_iov;
      ASSERTOP(io->iov_cur, >=, 0);
    } else {
      /* partial write: need to adjust iov_cur->iov_base */
      io->iov_cur->iov_base = ((char*)(io->iov_cur->iov_base)) + n;
      io->iov_cur->iov_len -= n;
      return;  /* we are not in end so nothing to free */
    }
  }
  ASSERTOP(n, ==, 0);
  if (io->n_iov)
    return;
  
  /* Everything has now been written. Time to free in_write list. */
  
  D("freeing responses (and possibly requests) %d", 0);
  while ((pdu = io->in_write)) {
    io->in_write = pdu->wn;
    pdu->wn = 0;
    
    if (!pdu->req) continue;
    
    /* Only a response can cause anything freed, and every response is freeable upon write. */
    
    hi_free_resp(hit, pdu);
    if (!pdu->req->reals)
      hi_free_req_fe(hit, pdu->req);  /* last response, free the request */
  }
}

/*() Attempt to write pending iovs.
 * This function can only be called by one thread at a time because the todo_queue
 * only admits an io object once and only one thread can consume it. Thus locking
 * is really needed only to protect the to_write queue, see hi_make_iov().
 * Returns 1 if connection got closed (and n_thr decremented).
 * Returns 0 if connection remains open (permitting, e.g., a read(2)). */

/* Called by:  hi_in_out, hi_send0 */
int hi_write(struct hi_thr* hit, struct hi_io* io)
{
  int ret;
  ASSERT(io->writing);
  while (1) {   /* Write until exhausted! */
    if (!io->in_write)  /* Need to prepare new iov? */
      hi_make_iov(io);
    if (!io->in_write)
      goto out;         /* Nothing further to write */
  retry:
    D("writev(%x) n_iov=%d", io->fd, io->n_iov);
    HEXDUMP("iov0:", io->iov_cur->iov_base, io->iov_cur->iov_base + io->iov_cur->iov_len, 16);
    ret = writev(io->fd, io->iov_cur, io->n_iov);
    switch (ret) {
    case 0: NEVERNEVER("writev on %x returned 0", io->fd);
    case -1:
      switch (errno) {
      case EINTR:  goto retry;
      case EAGAIN: goto out;   /* writev(2) exhausted (c.f. edge triggered epoll) */
      default:
	ERR("writev(%x) failed: %d %s (closing connection)", io->fd, errno, STRERROR(errno));
	LOCK(io->qel.mut, "clear-writing");   /* The io->writing was set in hi_in_out() */
	ASSERT(io->writing);
	io->writing = 0;
	UNLOCK(io->qel.mut, "clear-writing");
	hi_close(hit, io);
	return 1;
      }
    default:  /* something was written, deduce it from the iov */
      D("wrote(%x) %d bytes", io->fd, ret);
      hi_clear_iov(hit, io, ret);
    }
  }
 out:
  LOCK(io->qel.mut, "clear-writing");   /* The io->writing was set in hi_in_out() or hi_send0() */
  ASSERT(io->writing);
  io->writing = 0;
  UNLOCK(io->qel.mut, "clear-writing");
  return 0;
}

/* EOF  --  hiwrite.c */
