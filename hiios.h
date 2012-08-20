/* hiios.h  -  Hiquu I/O Engine
 * Copyright (c) 2006,2012 Sampo Kellomaki (sampo@iki.fi), All Rights Reserved.
 * This is confidential unpublished proprietary source code of the author.
 * NO WARRANTY, not even implied warranties. Contains trade secrets.
 * Distribution prohibited unless authorized in writing. See file COPYING.
 * Special grant: hiios.h may be used with zxid open source project under
 * same licensing terms as zxid itself.
 * $Id$
 *
 * 15.4.2006, created over Easter holiday --Sampo
 * 23.4.2006, DTS specific enhancements --Sampo
 * 16.8.2012, modified license grant to allow use with ZXID.org --Sampo
 *
 * A shuffler (hiios) is the top most global object, containing all
 * the connection objects and original global PDU memory pool.
 * Each thread has a shuffler, but also a local pool of PDU memory
 * that can be accessed without locking.
 *
 * PDU is always somehow reachable through pdu->qel.n (next) pointer, but
 * membership in queue is mutually exclusive as follows
 * 1. shf->free_pdus  -- may appear to be in shf->pdus too, but that is coincidence
 * 2. hit->free_pdus  -- per thread free list, the usual source for allocation within a thread
 *
 * PDU also has its own next pointer, the pdu->n which is used to keep lists of active PDUs
 * A. io->reqs        -- linked list of real reqs of this session, protect by qel.mut
 * B. io->cur_pdu     -- not really a list, but PDU can be here after allocation and before reqs
 * C. pdu->reals      -- linked list of real resps to this req
 * D. pdu->synths     -- linked list of subreqs and synth resps (not yet used as of 2012)
 *
 * Additionally a PDU may participate in various write related queues using wn (write next) pointer
 * i.   io->to_write_produce  -- add new pdus here (main thr only)
 * ii.  io->to_write_consume  -- list of PDUs that are imminently going to be written
 * iii. io->in_write          -- list of pdus that are in process of being written (have iovs)
 * iv.  io->subresps          -- subreq: list of resps, to ds_wait() upon
 *
 * The PDUs in the to_write queue have pdu->wn pointing from consume towards produce:
 *
 * to_write_produce --> pdu3      pdu2      pdu1 <-- to_write_consume
 *                      wn:0 <----wn   <----wn
 *
 * Here pdu1 was inserted first, then pdu2, etc. Inserts happen at produce
 * end (and set the wn pointer of the previous head to point to new head)
 * and removals at consumer end (by chasing the wn pointer). Here's queue with one element
 *
 * to_write_produce --> pdu1 <---------------------- to_write_consume
 *                      wn:0 
 *
 * Empty queue is expressed by both pointer being null.
 *
 * to_write_produce:0                                to_write_consume:0
 *
 * See http://pl.atyp.us/content/tech/servers.html for inspiration on threading strategy.
 * http://www.kegel.com/c10k.html
 */

#ifndef _hiios_h
#define _hiios_h

#ifdef LINUX
#include <sys/epoll.h>     /* See man 4 epoll (Linux 2.6) */
#endif
#ifdef SUNOS
#include <sys/devpoll.h>   /* See man -s 7d poll (Solaris 8) */
#include <sys/poll.h>
#endif

#include <netinet/in.h>
#include <sys/uio.h>
#include <pthread.h>

#ifndef IOV_MAX
#define IOV_MAX 16
#endif
#define HI_N_IOV (IOV_MAX < 32 ? IOV_MAX : 32)   /* Avoid unreasonably huge iov */
#if 0
#define HI_PDU_MEM 2200 /* Default PDU memory buffer size, sufficient for reliable data */
#define HI_PDU_MEM 4200 /* Default PDU memory buffer size, sufficient for broadcast data */
#endif
#define HI_PDU_MEM 3072 /* Default PDU memory buffer size, for log lines */

#define HI_POLL    1    /* Trigger epoll */
#define HI_PDU     2    /* PDU */
#define HI_LISTEN  3    /* Listening socket for TCP */
#define HI_TCP_S   4    /* TCP server socket, i.e. accept(2)'d from listening socket */
#define HI_TCP_C   5    /* TCP client socket, i.e. formed using connect(2) */
#define HI_SNMP    6    /* SNMP (UDP) socket */

struct hi_qel {         /* hiios task queue element. This is the 1st thing on io and pdu objects */
  struct hi_qel* n;     /* Next in todo_queue for IOs or in free_pdus and elsewhere for PDUs. */
  pthread_mutex_t mut;
  char kind;
  char proto;
  char flags;
  char inqueue;
};

/*(s) Connection object */

struct hi_io {
  struct hi_qel qel;
  struct hi_io* n;           /* next among io objects, esp. backends */
  struct hi_io* pair;        /* the other half of a proxy connection */
  int fd;                    /* file descriptor (socket), or 0x80000000 flag if not in use */
  char* description;         /* Nito: To be able to map fd->devices/ports. Link to hi_host_spec->specstr */
  char events;               /* events from last poll */
  char n_iov;
  struct iovec* iov_cur;     /* not used by listeners, only useful for sessions and backend ses */
  struct iovec iov[HI_N_IOV];
  struct hi_pdu* in_write;   /* wn list of pdus that are in process of being written (have iovs) */
  int n_to_write;            /* length of to_write queue */
  struct hi_pdu* to_write_consume;  /* wn list of PDUs that are imminently going to be written */
  struct hi_pdu* to_write_produce;  /* wn add new pdus here (main thr only) */
  
  /* Statistics counters */
  int n_written;  /* bytes */
  int n_read;     /* bytes */
  int n_pdu_out;
  int n_pdu_in;
  
  struct hi_pdu* cur_pdu;    /* PDU for which we currently expect to do I/O */
  struct hi_pdu* reqs;       /* n linked list of real reqs of this session, protect by qel.mut */
  union {
    struct dts_conn* dts;
    int sap;                 /* S5066 SAP ID, indexes into saptab[] and svc_type_tab[] */
    struct {
      struct hi_pdu* uni_ind_hmtp;
      int state;
    } smtp;
    struct {
      int state;
    } stomp;
  } ad;                      /* Application specific data */
};

/*(s) PDU object */

struct hi_pdu {
  struct hi_qel qel;
  struct hi_pdu* n;          /* Next among requests or responses */
  struct hi_pdu* wn;         /* Write next. Used by in_write, to_write, and subresps queues. */
  struct hi_io* fe;
  
  struct hi_pdu* req;        /* Set for response to indicate which request it is response to. */
  struct hi_pdu* parent;     /* Set for sub-requests and -responses */
  
  struct hi_pdu* subresps;   /* wn subreq: list of resps, to ds_wait() upon */
  struct hi_pdu* reals;      /* pdu->n linked list of real resps to this req */
  struct hi_pdu* synths;     /* pdu->n linked list of subreqs and synth resps */

  char events;               /* events needed by this PDU (EPOLLIN or EPOLLOUT) */
  char n_iov;
  char color;                /* Coloring flar gor integrity tests, e.g. to detect circular ptrs */
  char res3;
  struct iovec iov[3];       /* Enough for header, payload, and CRC */
  
  int need;                  /* How much more is needed to complete a PDU? */
  char* scan;                /* How far has protocol parsin progressed, e.g. in SMTP. */
  char* ap;                  /* Allocation pointer: next free memory location */
  char* m;                   /* Beginning of memory (often m == mem, but could be malloc'd) */
  char* lim;                 /* One past end of memory */
  char mem[HI_PDU_MEM];      /* Memory for processing a PDU */

  union {
#ifdef ENA_S5066
    struct {
      int n_tx_seq;          /* Transmit Frame Sequence Number */
      int addr_len;
      char* c_pdu;           /* S5066 DTS segmented C_PDU */
    } dts;
    struct {
      char rx_map[SIS_MAX_PDU_SIZE/8];  /* bitmap of bytes rx'd so we know if we have rx'd all */
    } dtsrx;
#endif
    struct {
      char* skip_ehlo;
    } smtp;
    struct {
      int len;               /* Populated from content-length header, if one is supplied. */
      char* body;            /* Body of the message */
      char* host;            /* also receipt and receipt_id */
      char* vers;            /* version, also accept-version, tx_id */
      char* login;           /* also session, subs_id, subsc */
      char* pw;              /* also server, ack, msg_id */
      char* dest;            /* destination, also heart_bt */
    } stomp;
  } ad;                      /* Application specific data */
  int len;
  int op;
};

#if 0
struct c_pdu_buf;
#endif

/*(s) Main shuffler object */

struct hiios {
  int ep;       /* epoll(4) (Linux 2.6) or /dev/poll (Solaris 8, man -s 7d poll) file descriptor */
  int n_evs;    /* how many useful events last epoll_wait() returned */
  int max_evs;
#ifdef LINUX
  struct epoll_event* evs;
#endif
#ifdef SUNOS
  struct pollfd* evs;
#endif
  int n_ios;
  int max_ios;
  struct hi_io* ios;

  pthread_mutex_t pdu_mut;
  int max_pdus;
  struct hi_pdu* pdu_buf_blob;  /* Backingstore for the PDU pool (big blob) */
  struct hi_pdu* free_pdus;     /* Global pool of PDUs (linked list) */

#if 0
  pthread_mutex_t c_pdu_buf_mut;
  int max_c_pdu_bufs;
  struct c_pdu_buf* c_pdu_bufs; /* global pool for c_pdu buffers */
  struct c_pdu_buf* free_c_pdu_bufs;
#endif

  pthread_mutex_t todo_mut;
  pthread_cond_t todo_cond;
  struct hi_qel* todo_consume;  /* PDUs and I/O objects that need processing. */
  struct hi_qel* todo_produce;
  int n_todo;
  struct hi_qel poll_tok;
};

/*(s) Thread object */

struct hi_thr {
  struct hiios* shf;
  struct hi_pdu* free_pdus;     /* Per thread pool of PDUs */
#if 0
  struct c_pdu_buf* free_c_pdu_bufs;
#endif
};

struct hi_host_spec {
  struct hi_host_spec* next;
  struct sockaddr_in sin;
  int proto;
  char* specstr;
  struct hi_io* conns;
};

struct hi_proto {
  char name[8];
  int default_port;
  struct hi_host_spec* specs;
};

extern struct hi_proto prototab[];

/* External APIs */

struct hiios* hi_new_shuffler(int nfd, int npdu);
struct hi_io* hi_open_listener(struct hiios* shf, struct hi_host_spec* hs, int proto);
struct hi_io* hi_open_tcp(struct hiios* shf, struct hi_host_spec* hs, int proto);
struct hi_io* hi_add_fd(struct hiios* shf, int fd, int proto, int kind, char *description);

struct hi_pdu* hi_pdu_alloc(struct hi_thr* hit);
void hi_send(struct hi_thr* hit, struct hi_io* io, struct hi_pdu* req, struct hi_pdu* resp);
void hi_send1(struct hi_thr* hit, struct hi_io* io, struct hi_pdu* req, struct hi_pdu* resp, int len0, char* d0);
void hi_send2(struct hi_thr* hit, struct hi_io* io, struct hi_pdu* req, struct hi_pdu* resp, int len0, char* d0, int len1, char* d1);
void hi_send3(struct hi_thr* hit, struct hi_io* io, struct hi_pdu* req, struct hi_pdu* resp, int len0, char* d0, int len1, char* d1, int len2, char* d2);
void hi_sendf(struct hi_thr* hit, struct hi_io* io, struct hi_pdu* req, char* fmt, ...);
void hi_todo_produce(struct hiios* shf, struct hi_qel* qe);
void hi_shuffle(struct hi_thr* hit, struct hiios* shf);

/* Internal APIs */

#define HI_NOERR 0
#define HI_CONN_CLOSE 1

void hi_process(struct hi_thr* hit, struct hi_pdu* pdu);
void hi_in_out( struct hi_thr* hit, struct hi_io* io);
void hi_close(  struct hi_thr* hit, struct hi_io* io);
void hi_write(  struct hi_thr* hit, struct hi_io* io);
void hi_read(   struct hi_thr* hit, struct hi_io* io);

void hi_checkmore(struct hi_thr* hit, struct hi_io* io, struct hi_pdu* req, int minlen);

void hi_free_req(struct hi_thr* hit, struct hi_pdu* pdu);
void hi_free_req_fe(struct hi_thr* hit, struct hi_pdu* req);
void hi_add_to_reqs(struct hi_io* io, struct hi_pdu* req);

/* Sanity checking and data structure dumping for debugging. */

extern char hi_color;  /* color usid for data structure circularity checks */

int hi_sanity_pdu(int mode, struct hi_pdu* root_pdu);
int hi_sanity_io(int mode, struct hi_io* root_io);
int hi_sanity_hit(int mode, struct hi_thr* root_hit);
int hi_sanity_shf(int mode, struct hiios* root_shf);
int hi_sanity(int mode, struct hiios* root_shf, struct hi_thr* root_hit, const char* fn, int line);

#define HI_SANITY(shf, hit) if (zx_debug>2) hi_sanity(255, (shf), (hit), __FUNCTION__, __LINE__)

#endif /* _hiios_h */
