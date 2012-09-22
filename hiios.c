/* hiios.c  -  Hiquu I/O Engine I/O shuffler
 * Copyright (c) 2006,2012 Sampo Kellomaki (sampo@iki.fi), All Rights Reserved.
 * This is confidential unpublished proprietary source code of the author.
 * NO WARRANTY, not even implied warranties. Contains trade secrets.
 * Distribution prohibited unless authorized in writing. See file COPYING.
 * Special grant: hiios.c may be used with zxid open source project under
 * same licensing terms as zxid itself.
 * $Id$
 *
 * 15.4.2006, created over Easter holiday --Sampo
 * 16.8.2012, modified license grant to allow use with ZXID.org --Sampo
 * 6.9.2012,  added support for TLS and SSL --Sampo
 * 17.9.2012, factored init, todo, and net code to their own files --Sampo
 *
 * See http://pl.atyp.us/content/tech/servers.html for inspiration on threading strategy.
 *
 *   MANY ELEMENTS IN QUEUE            ONE ELEMENT IN Q   EMPTY QUEUE
 *   consume             produce       consume  produce   consume  produce
 *    |                   |             | ,-------'         |        |
 *    V                   V             V V                 V        V
 *   qel.n --> qel.n --> qel.n --> 0   qel.n --> 0          0        0
 *
 ****
 * accept() blocks (after accept returned EAGAIN) - see if this is a blocking socket
 * see if edge triggered epoll has some special consideration for accept(2).
 */

#include "platform.h"

#ifdef LINUX
#include <sys/epoll.h>     /* See man 4 epoll (Linux 2.6) */
#endif
#ifdef SUNOS
#include <sys/devpoll.h>   /* See man -s 7d poll (Solaris 8) */
#include <sys/poll.h>
#endif

#include <pthread.h>
#include <malloc.h>
#include <memory.h>
#include <stdlib.h>
//#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <errno.h>
#include <string.h>

#include <zx/zxid.h>
#include "akbox.h"
#include "hiproto.h"
#include "hiios.h"
#include "errmac.h"

extern int zx_debug;
#ifdef MUTEX_DEBUG
extern pthread_mutexattr_t MUTEXATTR_DECL;
#endif

/*() Close an I/O object.
 * This involves special cleanup of todo queue to prevent any further
 * work. However, there might be threads already at work with
 * the connection. It will not be safe to reuse the io object until
 * they are done. If fd is not opened or accepted again, then presumably
 * such threads will sooner or later terminate due to I/O errors.
 * However, the next accept(2) is almost guaranteed to reuse the
 * fd number. Thus we need a reference count of sorts on the io
 * object to understand when a thread has let go of it. Upon accept
 * with same number, we are bound to wait, postpone any reads,
 * until the old threads have let go. */

/* Called by:  hi_in_out x2, hi_read x2, hi_write */
void hi_close(struct hi_thr* hit, struct hi_io* io, const char* lk)
{
  int fd = io->fd;
  D("%s: closing(%x) n_close=%d n_thr=%d", lk, fd, io->n_close, io->n_thr);
#if 0
  /* *** should never happen because io had to be consumed before hi_in_out() was called.
   * err, the io could have been consumed twice: once for reading and once for writing.
   * Thus it may be optimal to clean up the todo queue here, but this still will
   * not stop the other thread that already consumed. */
  LOCK(hit->shf->todo_mut, "hi_close");
  if (io->qel.intodo == HI_INTODO_INTODO) {
    if (hit->shf->todo_consume == &io->qel) {
      hi_todo_consume_inlock(hit->shf);
    } else {  /* Tricky consume from middle of queue. O(n) to queue size :-( */
      /* Since io->intodo is set, io must be in the queue. If it's not, following loop
       * will crash with NULL next pointer in the end. Or be infinite loop if a
       * loop of next pointers was somehow created. Both are programming errors. */
      for (qe = hit->shf->todo_consume; 1; qe = qe->n)
	if (qe->n == &io->qel) {
	  qe->n = io->qel.n;
	  break; /* only way out */
	}
      if (!qe->n)
	hit->shf->todo_produce = qe;
      qe->n = 0;
      qe->intodo = HI_INTODO_SHF_FREE;
      --hit->shf->n_todo;
    }
  }
  UNLOCK(hit->shf->todo_mut, "hi_close");
#endif
#if 0
  /* Expensive assert. Consider disabling. Not even true, because it is possible
   * to consume twice before close, so the other thread could already be causing
   * intodo situation. */
  LOCK(hit->shf->todo_mut, "hi_close");
  D("%s: close LK&UNLK todo_mut.thr=%x", lk, hit->shf->todo_mut.thr);
  ASSERT(!io->qel.intodo == HI_INTODO_INTODO);
  UNLOCK(hit->shf->todo_mut, "hi_close");
#endif
  /* *** deal with freeing associated PDUs. If fail, consider shutdown(2) of socket
   *     and reenqueue to todo list so freeing can be tried again later. */
  
  /* Race between produce and close: see hi_to_do_produce() */

  LOCK(io->qel.mut, "hi_close");
  D("LOCK io(%x)->qel.thr=%x n_close=%d n_thr=%d", fd, io->qel.mut.thr, io->n_close, io->n_thr);
  ASSERT(io->n_thr >= 0);
  ASSERT(hit->cur_io == io);
  if (hit->cur_n_close != io->n_close) {
    D("%s: already closed(%x) cur_n_close=%d != n_close=%d", lk, fd, hit->cur_n_close,io->n_close);
    D("UNLOCK io(%x)->qel.thr=%x", fd, io->qel.mut.thr);
    hit->cur_io = 0;
    UNLOCK(io->qel.mut, "hi_close-already");
    return;
  }

  if (fd&0x80000000) {
    D("second close(%x) n_close=%d n_thr=%d", fd, io->n_close, io->n_thr);
  } else {
    hi_del_fd(hit, fd);    /* stop poll from returning this fd */
    io->fd |= 0x80000000;  /* mark as closed */
    ASSERTOP(io->n_thr, >, 0, io->n_thr);
    --io->n_thr;  /* Will not be returned by poll any more, thus remove "virtual thread" */
  }
  ASSERT(io->qel.intodo != HI_INTODO_SHF_FREE); /* *** HI_INTODO_INTODO is a possibility if other thread might still be about to write to the connection. */
  
  /* N.B. n_thr manipulations are done before calling hi_close() */
  if (io->n_thr) {           /* Some threads are still tinkering with this fd: delay closing */
    if (shutdown(fd & 0x7ffffff, SHUT_RD))
      ERR("shutdown %d %s", errno, STRERROR(errno));
    D("%s: close(%x) waiting n_thr=%d n_close=%d intodo=%x", lk, fd, io->n_thr, io->n_close, io->qel.intodo);
    D("UNLOCK io(%x)->qel.thr=%x", fd, io->qel.mut.thr);
    hit->cur_io = 0;
    UNLOCK(io->qel.mut, "hi_close");
    return;
  }
  
  hi_close_final(hit, io, lk);
  /* Must let go of the lock only after close so no read can creep in. */
  D("UNLOCK io(%x)->qel.thr=%x", fd, io->qel.mut.thr);
  UNLOCK(io->qel.mut, "hi_close");
}

/*() Finalize close, actually closing the fd.
 * locking:: must be called with io->qel.mut held, typically after
 *     checking that io->n_close == hit->cur_n_close.  */ 

/* Called by:  hi_close, hi_todo_produce */
void hi_close_final(struct hi_thr* hit, struct hi_io* io, const char* lk)
{  
  struct hi_pdu* pdu;
  D("%s: close final(%x) n_close=%d n_thr=%d", lk, io->fd, io->n_close, io->n_thr);
  ASSERTOP(io->n_thr, ==, 0, io->n_thr);
  for (pdu = io->reqs; pdu; pdu = pdu->n)
    hi_free_req(hit, pdu);
  io->reqs = 0;
  for (pdu = io->pending; pdu; pdu = pdu->n)
    hi_free_req(hit, pdu);
  io->pending = 0;
  
  if (io->cur_pdu) {
    hi_free_req(hit, io->cur_pdu);
    io->cur_pdu = hi_pdu_alloc(hit, "cur_pdu-clo");  /* *** Could we recycle the PDU without freeing? */
  }
#ifdef ENA_S5066
  void sis_clean(struct hi_io* io);
  sis_clean(io);
#endif
  
  /* Clear the association with entity as late as possible so ACKs may
   * get a chance of being processed and written. */
  if (io->ent) {
    if (io->ent->io == io) {
      io->ent->io = 0;
      INFO("Dissociate ent_%p (%s) from io(%x)", io->ent, io->ent->eid, io->fd);
    } else {
      ERR("io(%x)->ent and ent->io(%x) are different", io->fd, io->ent->io->fd);
    }
    io->ent = 0;
  } else {
    ERR("io(%x) has no entity associated", io->fd);
  }
  
#ifdef USE_OPENSSL
  if (io->ssl) {
    SSL_shutdown(io->ssl);
    SSL_free(io->ssl);
    io->ssl = 0;
  }
#endif
  ASSERTOP(io->qel.intodo, ==, HI_INTODO_IOINUSE, io->qel.intodo); /* HI_INTODO_INTODO should not be possible anymore. */
  io->qel.intodo = HI_INTODO_SHF_FREE;
  close(io->fd & 0x7ffffff); /* Now some other thread may reuse the slot by accept()ing same fd */
  ++io->n_close;
  hit->cur_io = 0;
  D("%s: closed(%x) n_close=%d", lk, io->fd, io->n_close);
}

/* ---------- shuffler ---------- */

extern int debugpoll;
#define DP(format,...) if (debugpoll) MB fprintf(stderr, "t%x %10s:%-3d %-16s p " format "\n", (int)pthread_self(), __FILE__, __LINE__, __FUNCTION__, __VA_ARGS__); fflush(stderr); ME

/*() For a fd that was consumed from todo, deal with potential reads and writes */

/* Called by:  hi_shuffle */
void hi_in_out(struct hi_thr* hit, struct hi_io* io)
{
  int reading;
  DP("in_out(%x) events=0x%x", io->fd, io->events);
#ifdef SUNOS
#define EPOLLHUP (POLLHUP)  /* 0x010 */
#define EPOLLERR (POLLERR)  /* 0x008 */
#define EPOLLOUT (POLLOUT)  /* 0x004 */
#define EPOLLIN  (POLLIN)   /* 0x001 */
#endif
  if (io->events & (EPOLLHUP | EPOLLERR)) {
    D("HUP or ERR on fd=%x events=0x%x", io->fd, io->events);
    LOCK(io->qel.mut, "n_thr-dec1");
    D("IN_OUT: LOCK & UNLOCK io(%x)->qel.thr=%x", io->fd, io->qel.mut.thr);
    io->n_thr -= 2;                   /* Remove both counts (write and read) */
    ASSERT(io->n_thr >= 0);
    UNLOCK(io->qel.mut, "n_thr-dec1");
    hi_close(hit, io, "hi_in_out");
    return;
  }
  
  /* We must ensure that only one thread is trying to write. The poll may
   * still report the io as writable after a thread has taken the
   * task, in that case we want the second thread to skip write and
   * go process the read. */
  LOCK(io->qel.mut, "check-writing");
  D("LOCK io(%x)->qel.thr=%x r/w=%d/%d ev=%x", io->fd, io->qel.mut.thr, io->reading, io->writing, io->events);
  if (io->events & EPOLLOUT && !io->writing) {
    DP("OUT fd=%x n_iov=%d n_to_write=%d writing", io->fd, io->n_iov, io->n_to_write);

    /* Although in_write is checked in hi_write() as well, take the opportunity
     * to check it right here while we already hold the lock. */
    if (!io->in_write)  /* Need to prepare new iov? */
      hi_make_iov_nolock(io);
    if (io->in_write) {
      io->writing = 1;
      D("UNLOCK io(%x)->qel.thr=%x", io->fd, io->qel.mut.thr);
      UNLOCK(io->qel.mut, "check-writing-enter");
    
      if (hi_write(hit, io))  { /* will clear io->writing */
	LOCK(io->qel.mut, "n_thr-dec2");
	D("IN_OUT: LOCK & UNLOCK io(%x)->qel.thr=%x closed", io->fd, io->qel.mut.thr);
	--io->n_thr;            /* Remove read count, write count already removed by hi_write() */
	ASSERT(io->n_thr >= 0);
	ASSERT(hit->cur_io == io);
	ASSERT(hit->cur_n_close == io->n_close);
	UNLOCK(io->qel.mut, "n_thr-dec2");
	hi_close(hit, io, "write-shortcircuit-close");  /* Close again, now n_thr was reduced */
	return; /* Write caused close, read will be futile */
      } else {
	LOCK(io->qel.mut, "check-reading");
	D("LOCK io(%x)->qel.thr=%x", io->fd, io->qel.mut.thr);
      }
    } else {
      --io->n_thr;              /* Remove write count as no write happened. */
    }
  } else {
    --io->n_thr;              /* Remove write count as no write happened. */
  }
  ASSERT(io->n_thr > 0);    /* Read count should still be there. */
  io->events &= ~EPOLLOUT;  /* Clear poll flag in case we get read rescheduling */
  
  if (io->events & EPOLLIN) {
    /* A special problem with EAGAIN: read(2) is not guaranteed to arm edge triggered epoll(2)
     * unless at least one EAGAIN read has happened. The problem is that as we are still
     * in io->reading, if after this EAGAIN another thread polls and consumes from todo, it
     * will not be able to read due to io->reading even though poll told it to read. After
     * missing the opportunity, the next poll will not report fd anymore because no read has
     * happened since previous report. Ouch!
     * Solution attempt: if read was polled, but could not be served due to io->reading.
     * the PDU is added back to the todo queue. This may cause the other thread to spin
     * for a while, but at least things will move on eventually. */
    if (!io->reading) {
      DP("IN fd=%x cur_pdu=%p need=%d", io->fd, io->cur_pdu, io->cur_pdu->need);
      /* Poll says work is possible: sched wk for io if not under wk yet, or cur_pdu needs wk.
       * The inverse is also important: if io->cur_pdu is set, but pdu->need is not, then someone
       * is alredy working on decoding the cur_pdu and we should not interfere. */
      reading = io->reading = io->cur_pdu->need; /* only place where io->reading is set */
      D("UNLOCK io(%x)->qel.thr=%x", io->fd, io->qel.mut.thr);
      UNLOCK(io->qel.mut, "check-reading");
      if (reading) {
	hi_read(hit, io);       /* io->n_thr and hit->cur_io have already been updated */
	ASSERT(!hit->cur_io);
      } else {
	LOCK(io->qel.mut, "n_thr-dec3");
	D("IN_OUT: LOCK & UNLOCK io(%x)->qel.thr=%x", io->fd, io->qel.mut.thr);
	--io->n_thr;            /* Remove read count as no read happened. */
	ASSERT(io->n_thr >= 0);
	ASSERT(hit->cur_io == io);
	ASSERT(hit->cur_n_close == io->n_close);
	hit->cur_io = 0;
	UNLOCK(io->qel.mut, "n_thr-dec3");
      }
    } else {
      ASSERT(io->n_thr > 0);
      ASSERT(hit->cur_io == io);
      ASSERT(hit->cur_n_close == io->n_close);
      /*--io->n_thr;     * Do not decrement. We need to keep n_thr until we are in todo queue. */
      hit->cur_io = 0;
      D("UNLOCK io(%x)->qel.thr=%x", io->fd, io->qel.mut.thr);
      UNLOCK(io->qel.mut, "n_thr-dec4");
      D("resched(%x) to avoid miss poll read n_thr=%d", io->fd, io->n_thr);
      hi_todo_produce(hit, &io->qel, "reread", 0);  /* try again so read poll is not lost */
    }
  } else {
    --io->n_thr;              /* Remove read count as no read happened. */
    ASSERT(io->n_thr >= 0);
    ASSERT(hit->cur_io == io);
    ASSERT(hit->cur_n_close == io->n_close);
    hit->cur_io = 0;
    D("UNLOCK io(%x)->qel.thr=%x", io->fd, io->qel.mut.thr);
    UNLOCK(io->qel.mut, "n_thr-dec5");
  }
}

/*() Main I/O shuffling loop. Never returns. Main loop of most (all?) threads. */

/* Called by:  thread_loop, zxbusd_main */
void hi_shuffle(struct hi_thr* hit, struct hiios* shf)
{
  struct hi_qel* qe;
  hit->shf = shf;
  LOCK(shf->todo_mut, "add-thread");
  hit->n = shf->threads;
  shf->threads = hit;
  UNLOCK(shf->todo_mut, "add-thread");
  INFO("Start shuffling hit(%p) shf(%p)", hit, shf);
  while (1) {
    HI_SANITY(hit->shf, hit);
    qe = hi_todo_consume(hit);  /* Wakes up the heard to receive work. */
    switch (qe->kind) {
    case HI_POLL:     hi_poll(hit); break;
    case HI_LISTEN:   hi_accept(hit, (struct hi_io*)qe); break;
    case HI_HALF_ACCEPT: hi_accept_book(hit, (struct hi_io*)qe, ((struct hi_io*)qe)->fd);
    case HI_TCP_C:
    case HI_TCP_S:    hi_in_out(hit, (struct hi_io*)qe); break;
    case HI_PDU_DIST: stomp_msg_deliver(hit, (struct hi_pdu*)qe); break;
#ifdef HAVE_NET_SNMP
    case HI_SNMP:     if (snmp_port) processSNMP(); break; /* *** needs more thought */
#endif
    default: NEVER("unknown qel->kind 0x%x", qe->kind);
    }
  }
}

/* EOF  --  hiios.c */
