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
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <errno.h>
#include <string.h>

#include "akbox.h"
#include "hiproto.h"
#include "hiios.h"
#include "errmac.h"

extern int zx_debug;
#ifdef MUTEX_DEBUG
extern pthread_mutexattr_t MUTEXATTR_DECL;
#endif

void hi_hit_init(struct hi_thr* hit)
{
  memset(hit, 0, sizeof(struct hi_thr));
}

/*() Allocate io structure (connection) pool and global PDU
 * pool, from which per thread pools will be plensihed - see
 * hi_pdu_alloc() - and initialize syncronization primitives. */

/* Called by:  main */
struct hiios* hi_new_shuffler(struct hi_thr* hit, int nfd, int npdu)
{
  int i;
  struct hiios* shf;

  ZMALLOC(shf);
  hit->shf = shf;

  /* Allocate global pool of PDUs (as a blob) */

  ZMALLOCN(shf->pdu_buf_blob, sizeof(struct hi_pdu)*npdu);
  shf->max_pdus = npdu;
  for (i = npdu - 1; i; --i) {  /* Link the PDUs to a list. */
    shf->pdu_buf_blob[i-1].qel.n = (struct hi_qel*)(shf->pdu_buf_blob + i);
    pthread_mutex_init(&shf->pdu_buf_blob[i].qel.mut.ptmut, MUTEXATTR);
  }
  pthread_mutex_init(&shf->pdu_buf_blob[0].qel.mut.ptmut, MUTEXATTR);
  shf->free_pdus = shf->pdu_buf_blob;  /* Make PDUs available as free. */
  pthread_mutex_init(&shf->pdu_mut.ptmut, MUTEXATTR);

  /* Allocate ios array as a blob and prepare them for I/O (by allocating cur_pdu) */
  
  ZMALLOCN(shf->ios, sizeof(struct hi_io) * nfd);
  shf->max_ios = nfd;
  for (i = 0; i < nfd; ++i) {
    pthread_mutex_init(&shf->ios[i].qel.mut.ptmut, MUTEXATTR);
    if (!(shf->ios[i].cur_pdu = hi_pdu_alloc(hit, "new_shuffler"))) {
      ERR("Out of PDUs when preparing cur_pdu for each I/O object. Use -npdu to specify a value at least twice the value of -nfd. Current values: npdu=%d, nfd=%d", npdu, nfd);
      exit(1);
    }
  }
  
  pthread_cond_init(&shf->todo_cond, 0);
  pthread_mutex_init(&shf->todo_mut.ptmut, MUTEXATTR);

  shf->poll_tok.kind = HI_POLL;           /* Permanently labeled as poll_tok (there is only 1) */
  shf->poll_tok.proto = HIPROTO_POLL_ON;  /* token is available */

  shf->max_evs = MIN(nfd, 1024);
#ifdef LINUX
  shf->ep = epoll_create(nfd);
  if (shf->ep == -1) { perror("epoll"); exit(1); }
  ZMALLOCN(shf->evs, sizeof(struct epoll_event) * shf->max_evs);
#endif
#ifdef SUNOS
  shf->ep = open("/dev/poll", O_RDWR);
  if (shf->ep == -1) { perror("open(/dev/poll)"); exit(1); }
  ZMALLOCN(shf->evs, sizeof(struct pollfd) * shf->max_evs);
#endif
  return shf;
}

/*() Set socket to be nonblocking.
 * Our I/O strategy (edge triggered epoll or /dev/poll) depends on nonblocking fds. */

/* Called by:  hi_accept, hi_open_listener, hi_open_tcp, serial_init, zxbus_open_bus_url */
void nonblock(int fd)
{
#ifdef MINGW
  u_long arg = 1;
  if (ioctlsocket(fd, FIONBIO, &arg) == SOCKET_ERROR) {
    ERR("Unable to ioctlsocket(%d, FIONBIO, 1): %d %s", fd, errno, STRERROR(errno));
    exit(2);
  }
#else
#if 0
  int fflags = fcntl(fd, F_GETFL, 0);
  if (fflags == -1) {
    ERR("Unable to fcntl(F_GETFL) on socket %d: %d %s", fd, errno, STRERROR(errno));
    exit(2);
  }
  fflags |= O_NONBLOCK | O_NDELAY;  /* O_ASYNC would be synonymous */
#endif

  if( fcntl(fd, F_SETFL, O_NONBLOCK | O_NDELAY) == -1) {
    ERR("Unable to fcntl(F_SETFL) on socket %d: %d %s", fd, errno, STRERROR(errno));
    exit(2);
  }

#if 0
  if (fcntl(fd, F_SETFD, FD_CLOEXEC) == -1) {
    ERR("fcntl(F_SETFD,FD_CLOEXEC) system call failed for %d: %d %s", fd, errno, STRERROR(errno));
    exit(2);
  }
#endif
#endif
}

/* Tweaking kernel buffers to be smaller can be a win if a massive number
 * of connections are simultaneously open. On many systems default buffer
 * size is 64KB in each direction, leading to 128KB memory consumption. Tweaking
 * to only, say, 8KB can bring substantial savings (but may hurt TCP performance). */

/* Called by:  hi_accept, hi_open_listener, hi_open_tcp, zxbus_open_bus_url */
void setkernelbufsizes(int fd, int tx, int rx)
{
  /* See `man 7 tcp' for TCP_CORK, TCP_NODELAY, etc. */
  if (setsockopt(fd, SOL_SOCKET, SO_SNDBUF, (char*)&tx, sizeof(tx)) == -1) {
    ERR("setsockopt(SO_SNDBUF, %d) on fd=%d: %d %s", tx, fd, errno, STRERROR(errno));
    exit(2);
  }
  if (setsockopt(fd, SOL_SOCKET, SO_RCVBUF, (char*)&rx, sizeof(rx)) == -1) {
    ERR("setsockopt(SO_RCVBUF, %d) on fd=%d: %d %s", rx, fd, errno, STRERROR(errno));
    exit(2);
  }
}

extern int nkbuf;
extern int listen_backlog;

/* Called by:  main */
struct hi_io* hi_open_listener(struct hiios* shf, struct hi_host_spec* hs, int proto)
{
  struct hi_io* io;
  int fd, tmp;
  if ((fd = socket(AF_INET, SOCK_STREAM, 0))== -1) {
    ERR("listen: Unable to create socket(AF_INET, SOCK_STREAM, 0) %d %s", errno, STRERROR(errno));
    return 0;
  }
  if (fd >= shf->max_ios) {
    ERR("listen: File descriptor limit(%d) exceeded fd=%d. Consider increasing the limit with -nfd flag, or figure out if there are any descriptor leaks.", shf->max_ios, fd);
    close(fd);
    return 0;
  }
  nonblock(fd);
  if (nkbuf)
    setkernelbufsizes(fd, nkbuf, nkbuf);

  tmp = 1;
  if (setsockopt(fd, SOL_SOCKET, SO_REUSEADDR, (char*)&tmp, sizeof(tmp)) == -1) {
    ERR("listen: Failed to call setsockopt(REUSEADDR) on %d: %d %s", fd, errno, STRERROR(errno));
    exit(2);
  }

  if (bind(fd, (struct sockaddr*)&hs->sin, sizeof(struct sockaddr_in))) {
    ERR("listen: Unable to bind socket %d (%s): %d %s (trying again in 2 secs)",
	fd, hs->specstr, errno, STRERROR(errno));
    /* It appears to be a problem under 2.5.7x series kernels that if you kill a process that
     * was listening to a port, you can not immediately bind on that same port again. */
    sleep(2);
    if (bind (fd, (struct sockaddr*)&hs->sin, sizeof(struct sockaddr_in))) {
      ERR("listen: Unable to bind socket %d (%s): %d %s (giving up)",
	  fd, hs->specstr, errno, STRERROR(errno));
      close(fd);
      return 0;
    }
  }
  
  if (listen(fd, listen_backlog)) {
    ERR("Unable to listen(%d, %d) (%s): %d %s",
	fd, listen_backlog, hs->specstr, errno, STRERROR(errno));
    close(fd);
    return 0;
  }

  io = shf->ios + fd;

#ifdef LINUX
  {
    struct epoll_event ev;
    ev.events = EPOLLIN | EPOLLET;  /* ET == EdgeTriggered */
    ev.data.ptr = io;
    if (epoll_ctl(shf->ep, EPOLL_CTL_ADD, fd, &ev)) {
      ERR("Unable to epoll_ctl(%d) (%s): %d %s", fd, hs->specstr, errno, STRERROR(errno));
      close(fd);
      return 0;
    }
  }
#endif
#ifdef SUNOS
  {
    struct pollfd pfd;
    pfd.fd = fd;
    pfd.events = POLLIN | POLLERR;
    if (write(shf->ep, &pfd, sizeof(pfd)) == -1) {
      ERR("Unable to write to /dev/poll fd(%d) (%s): %d %s", fd, hs->specstr, errno, STRERROR(errno));
      close(fd);
      return 0;
    }
  }
#endif

  io->fd = fd;
  io->qel.kind = HI_LISTEN;
  io->qel.proto = proto;
  D("listen(%x) hs(%s)", fd, hs->specstr);
  return io;
}

/*() Add file descriptor to poll */

/* Called by:  hi_accept, hi_open_tcp, serial_init */
struct hi_io* hi_add_fd(struct hiios* shf, int fd, int proto, int kind)
{
  struct hi_io* io = shf->ios + fd;  /* uniqueness of fd acts as mutual exclusion mechanism */
  ASSERTOP(fd, <, shf->max_ios, fd);

#ifdef LINUX
  {
    struct epoll_event ev;
    ev.events = EPOLLIN | EPOLLOUT | EPOLLERR | EPOLLHUP | EPOLLET;  /* ET == EdgeTriggered */
    ev.data.ptr = io;
    if (epoll_ctl(shf->ep, EPOLL_CTL_ADD, fd, &ev)) {
      ERR("Unable to epoll_ctl(%d): %d %s", fd, errno, STRERROR(errno));
      close(fd);
      return 0;
    }
  }
#endif
#ifdef SUNOS
  {
    struct pollfd pfd;
    pfd.fd = fd;
    pfd.events = POLLIN | POLLOUT | POLLERR | POLLHUP;
    if (write(shf->ep, &pfd, sizeof(pfd)) == -1) {
      ERR("Unable to write to /dev/poll fd(%d): %d %s", fd, errno, STRERROR(errno));
      close(fd);
      return 0;
    }
  }
#endif

  /* memset(io, 0, sizeof(struct hi_io)); *** MUST NOT clear as there are important fields like cur_pdu and lock initializations already set. All memory was zeroed in hi_new_shuff(). After that all changes should be field by field. */
  io->fd = fd;
  io->qel.kind = kind;
  io->qel.proto = proto;
  return io;
}

/*() Create client socket. */

/* Called by:  main, smtp_send */
struct hi_io* hi_open_tcp(struct hiios* shf, struct hi_host_spec* hs, int proto)
{
  int fd;
  if ((fd = socket(AF_INET, SOCK_STREAM, 0)) == -1) {
    ERR("Unable to create socket(AF_INET, SOCK_STREAM, 0) %d %s", errno, STRERROR(errno));
    return 0;
  }

  if (fd >= shf->max_ios) {
    ERR("File descriptor limit(%d) exceeded fd=%d. Consider increasing the limit with -nfd flag, or figure out if there are any descriptor leaks.", shf->max_ios, fd);
    close(fd);
    return 0;
  }

  nonblock(fd);
  if (nkbuf)
    setkernelbufsizes(fd, nkbuf, nkbuf);
  
  if ((connect(fd, (struct sockaddr*)&hs->sin, sizeof(hs->sin)) == -1)
      && (errno != EINPROGRESS)) {
    int myerrno = errno;
    close(fd);
    ERR("Connection to %s failed: %d %s", hs->specstr, myerrno, STRERROR(myerrno));
    return 0;
  }
  
  D("connect(%x) hs(%s)", fd, hs->specstr);
  return hi_add_fd(shf, fd, proto, HI_TCP_C);
}

/*() Process half accepted socket (already accepted at socket layer, but
 * not yet booked in our data structures - perhaps due to delayed
 * booking used to cope with threads that are still looking at
 * the old connection. */

/* Called by:  hi_shuffle */
static void hi_accept_book(struct hi_thr* hit, struct hi_io* io)
{
  int n_thr;

  /* We may accept new connection with same fd as an old one before all references
   * to the old one are gone. We could try reference counting - or we can delay
   * fully closing the fd before every reference has gone away.
   * *** Arguably this should never happen due to our half close strategy
   * keeping the fd occupied until all threads really are gone. */
  LOCK(io->qel.mut, "hi_accept");
  D("ACCEPT LK&UNLK io(%x)->qel.thr=%x", io->fd, io->qel.mut.thr);
  n_thr = io->n_thr;
  UNLOCK(io->qel.mut, "hi_accept");
  if (n_thr) {
    D("old fd(%x) n_thr=%d still going", io->fd, n_thr);
    NEVERNEVER("NOT POSSIBLE due to half close n_thr=%d", n_thr);
    io->qel.kind = HI_HALF_ACCEPT;
    hi_todo_produce(hit->shf, &io->qel);  /* schedule a new try */
    return;
  }

  io->fd &= 0x7fffffff;
  io = hi_add_fd(hit->shf, io->fd, io->qel.proto, HI_TCP_S);
  D("accepted and booked(%x)", io->fd);
  
  switch (io->qel.proto) {
  case HIPROTO_SMTP: /* In SMTP, server starts speaking first */
    hi_sendf(hit, io, 0, "220 %s smtp ready\r\n", SMTP_GREET_DOMAIN);
    io->ad.smtp.state = SMTP_START;
    break;
#ifdef ENA_S5066
  case HIPROTO_DTS:
    {
      struct hi_host_spec* hs;
      ZMALLOC(io->ad.dts);
      io->ad.dts->remote_station_addr[0] = 0x61;   /* three nibbles long (padded with zeroes) */
      io->ad.dts->remote_station_addr[1] = 0x45;
      io->ad.dts->remote_station_addr[2] = 0x00;
      io->ad.dts->remote_station_addr[3] = 0x00;
      if (!(hs = prototab[HIPROTO_DTS].specs)) {
	ZMALLOC(hs);
	hs->proto = HIPROTO_DTS;
	hs->specstr = "dts:accepted:connections";
	hs->next = prototab[HIPROTO_DTS].specs;
	prototab[HIPROTO_DTS].specs = hs;
      }
      io->n = hs->conns;
      hs->conns = io;
    }
    break;
#endif
  }
}

/*() Create server side worker socket by accept(2)ing from listener socket. */

static void hi_accept(struct hi_thr* hit, struct hi_io* listener)
{
  struct hi_io* io;
  struct sockaddr_in sa;
  int fd;
  size_t size;
  size = sizeof(sa);
  D("accept from(%x)", listener->fd);
  if ((fd = accept(listener->fd, (struct sockaddr*)&sa, &size)) == -1) {
    if (errno != EAGAIN)
      ERR("Unable to accept from %x: %d %s", listener->fd, errno, STRERROR(errno));
    else
      D("accept(%x): EAGAIN", listener->fd);
    return;
  }
  if (fd >= hit->shf->max_ios) {
    ERR("accept: File descriptor limit(%d) exceeded fd=%d. Consider increasing the limit with -nfd flag, or figure out if there are any descriptor leaks.", hit->shf->max_ios, fd);
    close(fd);
    return;
  }
  nonblock(fd);
  if (nkbuf)
    setkernelbufsizes(fd, nkbuf, nkbuf);

  ++listener->n_read;  /* n_read counter is used for accounting accepts */
  io = hit->shf->ios + fd;
  io->fd = fd | 0x80000000;
  io->qel.proto = listener->qel.proto;
  hi_accept_book(hit, io);
  hi_todo_produce(hit->shf, &listener->qel); /* Must exhaust accept: reenqueue (could also loop) */
}

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

/* Called by:  hi_in_out, hi_read x3, hi_write */
void hi_close(struct hi_thr* hit, struct hi_io* io)
{
  struct hi_pdu* pdu;
  int fd = io->fd;
  D("closing(%x)", fd);
#if 0
  /* *** should never happen because io had to be consumed before hi_in_out() was called.
   * err, the io could have been consumed twice: once for reading and once for writing.
   * Thus it may be optimal to clean up the todo queue here, but this still will
   * not stop the other thread that already consumed. */
  LOCK(hit->shf->todo_mut, "hi_close");
  if (io->qel.intodo) {
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
      qe->intodo = 0;
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
  D("CLOSE LOCK & UNLOCK todo_mut.thr=%x", hit->shf->todo_mut.thr);
  ASSERT(!io->qel.intodo);
  UNLOCK(hit->shf->todo_mut, "hi_close");
#endif
  /* *** deal with freeing associated PDUs. If fail, consider shutdown(2) of socket
   *     and reenqueue to todo list so freeing can be tried again later. */
  
  LOCK(io->qel.mut, "hi_close");
  D("LOCK io(%x)->qel.thr=%x", io->fd, io->qel.mut.thr);
  ASSERT(io->n_thr >= 0);
  io->fd |= 0x80000000;  /* mark as free */

  /* N.B. n_thr manipulations are done before calling hi_close() */
  if (io->n_thr) {           /* Some threads are still tinkering with this fd: delay closing */
    if (shutdown(fd & 0x7ffffff, SHUT_RD))
      ERR("shutdown %d %s", errno, STRERROR(errno));
    D("close(%x) pending n_thr=%d", fd, io->n_thr);
    D("UNLOCK io(%x)->qel.thr=%x", fd, io->qel.mut.thr);
    UNLOCK(io->qel.mut, "hi_close");
    return;
  }
  
  for (pdu = io->reqs; pdu; pdu = pdu->n)
    hi_free_req(hit, pdu);
  io->reqs = 0;
  
  if (io->cur_pdu) {
    hi_free_req(hit, io->cur_pdu);
    io->cur_pdu = hi_pdu_alloc(hit, "cur_pdu-clo");  /* *** Could we recycle the PDU without freeing? */
  }
#ifdef ENA_S5066
  void sis_clean(struct hi_io* io);
  sis_clean(io);
#endif
  
  close(fd & 0x7ffffff); /* Now some other thread may reuse the slot by accept()ing same fd */
  D("closed(%x)", fd);
  /* Must let go of the lock only after close so no read can creep in. */
  D("UNLOCK io(%x)->qel.thr=%x", fd, io->qel.mut.thr);
  UNLOCK(io->qel.mut, "hi_close");
}

/* -------- todo_queue management, waking up threads to consume work (io, pdu) -------- */

/*() Simple mechanics of deque operation against shf->todo_consumer */

/* Called by:  hi_close, hi_todo_consume */
static struct hi_qel* hi_todo_consume_inlock(struct hiios* shf)
{
  struct hi_qel* qe = shf->todo_consume;
  shf->todo_consume = qe->n;
  if (!qe->n)
    shf->todo_produce = 0;
  qe->n = 0;
  qe->intodo = 0;
  --shf->n_todo;
  return qe;
}

/*(i) Consume from todo queue. If nothing is available,
 * block until there is work to do. This is the main
 * mechanism by which worker threads get something to do. */

/* Called by:  hi_shuffle */
static struct hi_qel* hi_todo_consume(struct hiios* shf)
{
  struct hi_io* io;
  struct hi_qel* qe;
  LOCK(shf->todo_mut, "todo_cons");
  D("LOCK todo_mut.thr=%x (cond_wait)", shf->todo_mut.thr);

  while (1) {
  try_next:
    while (!shf->todo_consume && !shf->poll_tok.proto)        /* Empty todo queue? */
      COND_WAIT(&shf->todo_cond, shf->todo_mut, "todo-cons"); /* Block until there is work. */
    D("Out of cond_wait todo_mut.thr=%x", shf->todo_mut.thr);
    if (shf->todo_consume)
      qe = hi_todo_consume_inlock(shf);
    else {
      ASSERT(shf->poll_tok.proto);
      shf->poll_tok.proto = HIPROTO_POLL_OFF;
      qe = &shf->poll_tok;
    }
    if (ONE_OF_2(qe->kind, HI_TCP_S, HI_TCP_C)) {
      io = ((struct hi_io*)qe);
      LOCK(io->qel.mut, "n_thr inc");
      if (io->fd & 0x80000000) {
	D("CONS-CLOSED: LK&UNLK io(%x)->qel.thr=%x", io->fd, io->qel.mut.thr);
	UNLOCK(io->qel.mut, "n_thr inc-fail");
	goto try_next;
      }
      io->n_thr += 2;  /* Increase two counts: once for write, and once for read */
      D("CONS: LK&UNLK io(%x)->qel.thr=%x", io->fd, io->qel.mut.thr);
      UNLOCK(io->qel.mut, "n_thr inc");
      D("use(%x) n_thr=%d reading=%d writing=%d ev=%x", io->fd, io->n_thr, io->reading, io->writing, io->events);
    } else {
      D("consume qe(%p) kind=%d", qe, qe->kind);
    }
    D("UNLOCK todo_mut.thr=%x", shf->todo_mut.thr);
    UNLOCK(shf->todo_mut, "todo_cons");
    return qe;
  }
}

/*(i) Schedule new work to be done, potentially waking up the consumer threads! */

/* Called by:  hi_accept, hi_poll x2, hi_read */
void hi_todo_produce(struct hiios* shf, struct hi_qel* qe)
{
  struct hi_io* io;
  LOCK(shf->todo_mut, "todo_prod");
  D("LOCK todo_mut.thr=%x", shf->todo_mut.thr);
  if (!qe->intodo) {
    if (shf->todo_produce)
      shf->todo_produce->n = qe;
    else
      shf->todo_consume = qe;
    shf->todo_produce = qe;
    qe->n = 0;
    qe->intodo = 1;
    ++shf->n_todo;
    if (ONE_OF_2(qe->kind, HI_TCP_S, HI_TCP_C)) {
      io = ((struct hi_io*)qe);
      D("todo(%x) n_thr=%d r/w'ing=%d/%d ev=%x", io->fd, io->n_thr, io->reading, io->writing, io->events);
    } else {
      D("todo qe(%p) kind=%x", qe, qe->kind);
    }
    COND_SIG(&shf->todo_cond, "todo-prod");  /* Wake up consumers */
  } else {
    if (ONE_OF_2(qe->kind, HI_TCP_S, HI_TCP_C)) {
      io = ((struct hi_io*)qe);
      D("already in todo(%x) n_thr=%d reading=%d writing=%d ev=%x", io->fd, io->n_thr, io->reading, io->writing, io->events);
    } else {
      D("already in todo qe(%p) kind=%x", qe, qe->kind);
    }
  }
  D("UNLOCK todo_mut.thr=%x", shf->todo_mut.thr);
  UNLOCK(shf->todo_mut, "todo_prod");
}

/* ---------- shuffler ---------- */

extern int debugpoll;
#define DP(format,...) if (debugpoll) MB fprintf(stderr, "t%x %10s:%-3d %-16s p " format "\n", (int)pthread_self(), __FILE__, __LINE__, __FUNCTION__, __VA_ARGS__); fflush(stderr); ME

/* Called by:  hi_shuffle */
static void hi_poll(struct hiios* shf)
{
  struct hi_io* io;
  int i;
  DP("epoll(%x)", shf->ep);
#ifdef LINUX
  shf->n_evs = epoll_wait(shf->ep, shf->evs, shf->max_evs, -1);
  if (shf->n_evs == -1) {
    ERR("epoll_wait(%x): %d %s", shf->ep, errno, STRERROR(errno));
    return;
  }
  for (i = 0; i < shf->n_evs; ++i) {
    io = (struct hi_io*)shf->evs[i].data.ptr;
    io->events = shf->evs[i].events;
    hi_todo_produce(shf, &io->qel);  /* *** should the todo_mut lock be batched instead? */
  }
#endif
#ifdef SUNOS
  {
    struct dvpoll dp;
    dp.dp_timeout = -1;
    dp.dp_nfds = shf->max_evs;
    dp.dp_fds = shf->evs;
    shf->n_evs = ioctl(shf->ep, DP_POLL, &dp);
    if (shf->n_evs < 0) {
      ERR("/dev/poll ioctl(%x): %d %s", shf->ep, errno, STRERROR(errno));
      return;
    }
    for (i = 0; i < shf->n_evs; ++i) {
      io = shf->ios + shf->evs[i].fd;
      io->events = shf->evs[i].revents;
      /* Poll says work is possible: sched wk for io if not under wk yet, or cur_pdu needs wk. */
      /*if (!io->cur_pdu || io->cur_pdu->need)   *** cur_pdu is always set */
      hi_todo_produce(shf, &io->qel);  /* *** should the todo_mut lock be batched instead? */
    }
  }
#endif
  LOCK(shf->todo_mut, "todo_poll");
  D("POLL LOCK & UNLOCK todo_mut.thr=%x", shf->todo_mut.thr);
  shf->poll_tok.proto = HIPROTO_POLL_ON;  /* special "on" flag - not a real protocol */
  UNLOCK(shf->todo_mut, "todo_poll");
}

/* Called by:  hi_shuffle */
void hi_process(struct hi_thr* hit, struct hi_pdu* pdu)
{
  D("pdu(%p) events=0x%x", pdu, pdu->events);
  /* *** process "continuing" event on a PDU */
}

/* Called by:  hi_shuffle */
void hi_in_out(struct hi_thr* hit, struct hi_io* io)
{
  int reading;
  DP("in_out(%x) events=0x%x", io->fd, io->events);
#ifdef SUNOS
#define EPOLLHUP (POLLHUP)
#define EPOLLERR (POLLERR)
#define EPOLLOUT (POLLOUT)
#define EPOLLIN  (POLLIN)
#endif
  if (io->events & (EPOLLHUP | EPOLLERR)) {
    D("HUP or ERR on fd=%x events=0x%x", io->fd, io->events);
    LOCK(io->qel.mut, "n_thr-dec1");
    D("IN_OUT: LOCK & UNLOCK io(%x)->qel.thr=%x", io->fd, io->qel.mut.thr);
    io->n_thr -= 2;                   /* Remove both counts (write and read) */
    ASSERT(io->n_thr >= 0);
    UNLOCK(io->qel.mut, "n_thr-dec1");
    hi_close(hit, io);
    return;
  }
  
  /* We must ensure that only one thread is trying to write. The poll may
   * still report the io as writable after a thread has taken the
   * task, in that case we want the second thread to skip write and
   * go process the read. */
  LOCK(io->qel.mut, "check-writing");
  D("LOCK io(%x)->qel.thr=%x", io->fd, io->qel.mut.thr);
  if (io->events & EPOLLOUT && !io->writing) {
    io->writing = 1;
    DP("OUT fd=%x n_iov=%d n_to_write=%d", io->fd, io->n_iov, io->n_to_write);

    /* Although in_write is checked in hi_write() as well, take the opportunity
     * to check it right here while we already hold the lock. */
    if (!io->in_write)  /* Need to prepare new iov? */
      hi_make_iov_nolock(io);
    D("UNLOCK io(%x)->qel.thr=%x", io->fd, io->qel.mut.thr);
    UNLOCK(io->qel.mut, "check-writing-enter");
    
    if (hi_write(hit, io))  { /* will clear io->writing */
      LOCK(io->qel.mut, "n_thr-dec2");
      D("IN_OUT: LOCK & UNLOCK io(%x)->qel.thr=%x", io->fd, io->qel.mut.thr);
      io->n_thr -= 1;         /* Remove read count, write count already removed by hi_write() */
      ASSERT(io->n_thr >= 0);
      UNLOCK(io->qel.mut, "n_thr-dec2");
      return; /* Write caused close */
    }
    LOCK(io->qel.mut, "check-reading");
    D("LOCK io(%x)->qel.thr=%x", io->fd, io->qel.mut.thr);
  } else {
    --io->n_thr;              /* Remove write count as no write happened. */
    ASSERT(io->n_thr >= 0);
  }
  
  if (io->events & EPOLLIN && !io->reading) {
    DP("IN fd=%x cur_pdu=%p need=%d", io->fd, io->cur_pdu, io->cur_pdu->need);
    /* Poll says work is possible: sched wk for io if not under wk yet, or cur_pdu needs wk.
     * The inverse is also important: if io->cur_pdu is set, but pdu->need is not, then someone
     * is alredy working on decoding the cur_pdu and we should not interfere. */
    reading = io->reading = io->cur_pdu->need; /* only place where io->reading is set */
    D("UNLOCK io(%x)->qel.thr=%x", io->fd, io->qel.mut.thr);
    UNLOCK(io->qel.mut, "check-reading");
    if (reading) {
      hi_read(hit, io);       /* io->n_thr had already been decremented */
    } else {
      LOCK(io->qel.mut, "n_thr-dec3");
      D("IN_OUT: LOCK & UNLOCK io(%x)->qel.thr=%x", io->fd, io->qel.mut.thr);
      --io->n_thr;            /* Remove read count as no read happened. */
      ASSERT(io->n_thr >= 0);
      UNLOCK(io->qel.mut, "n_thr-dec3");
    }
  } else {
    --io->n_thr;              /* Remove read count as no read happened. */
    ASSERT(io->n_thr >= 0);
    D("UNLOCK io(%x)->qel.thr=%x", io->fd, io->qel.mut.thr);
    UNLOCK(io->qel.mut, "n_thr-dec4");
  }
}

/*() Main I/O shuffling loop. Never returns. Main loop of most (all?) threads. */

/* Called by:  main, thread_loop */
void hi_shuffle(struct hi_thr* hit, struct hiios* shf)
{
  struct hi_qel* qe;
  hit->shf = shf;
  D("Start shuffling hit(%p) shf(%p)", hit, shf);
  while (1) {
    HI_SANITY(hit->shf, hit);
    qe = hi_todo_consume(shf);  /* Wakes up the heard to receive work. */
    switch (qe->kind) {
    case HI_POLL:    hi_poll(shf); break;
    case HI_LISTEN:  hi_accept(hit, (struct hi_io*)qe); break;
    case HI_HALF_ACCEPT: hi_accept_book(hit, (struct hi_io*)qe);
    case HI_TCP_C:
    case HI_TCP_S:   hi_in_out(hit, (struct hi_io*)qe); break;
    case HI_PDU:     hi_process(hit, (struct hi_pdu*)qe); break;
#ifdef HAVE_NET_SNMP
    case HI_SNMP:    if (snmp_port) processSNMP(); break; /* *** needs more thought */
#endif
    default: NEVER("unknown qel->kind 0x%x", qe->kind);
    }
  }
}

/* EOF  --  hiios.c */
