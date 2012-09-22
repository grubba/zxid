/* zxmqtest.c  -  Test message queues
 * Copyright (c) 2010-2011 Sampo Kellomaki (sampo@iki.fi), All Rights Reserved.
 * This is confidential unpublished proprietary source code of the author.
 * NO WARRANTY, not even implied warranties. Contains trade secrets.
 * Distribution prohibited unless authorized in writing.
 * Licensed under Apache License 2.0, see file COPYING.
 * $Id: zxencdectest.c,v 1.9 2009-11-24 23:53:40 sampo Exp $
 *
 * 1.1.2011, started --Sampo

/apps/bin/ccache /apps/bin/gcc -g -fpic -fmessage-length=0 -Wno-unused-label -Wno-unknown-pragmas -fno-strict-aliasing -Wall -Wno-parentheses -DMAYBE_UNUSED='__attribute__ ((unused))' -ffunction-sections -fdata-sections -DUSE_CURL -DUSE_OPENSSL -DUSE_PTHREAD -DLINUX -D_REENTRANT -DDEBUG -I. -I/home/sampo/zxid -I/apps/openssl/std/include -I/apps/include -I/include -I/apps/apache/std/include -I/apps/apache/std/srclib/apr-util/include -o zxmqtest  zxmqtest.c /s/zeromq-2.0.9/libzmq.a -L. -lzxid -lstdc++ -lcurl -lssl -lcrypto -lpthread -luuid

 * See also: http://www.openamq.org/doc:prog-wireapi
 * openamq-dev@lists.openamq.org
 * http://www.mail-archive.com/qpid-dev@incubator.apache.org/msg07651.html   (2008 test problems)
 * http://news.ycombinator.com/item?id=1232242  (harsh critique of AMQP)
 * http://wiki.secondlife.com/wiki/Message_Queue_Evaluation_Notes  (comparison)
 * http://www.h-online.com/open/news/forum/S-Re-So-what-went-wrong-Why-other-Big-open-source-projects-thrive/forum-114743/msg-14370740/read/
 */

#include <signal.h>
#include <fcntl.h>
#include <netdb.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <openssl/x509.h>
//#include <unistd.h>  // off64_t needed by /apps/openamq/std/include/apr.h

#ifdef OPENAMQ
typedef __off64_t off64_t;   // off64_t needed by /apps/openamq/std/include/apr.h:285
#include "wireapi.h"
//#include "asl.h"
//#include "amq_client_connection.h"
//#include "amq_client_session.h"
#endif

#ifdef ZMQ
#include <zmq.h>
#endif

#include "errmac.h"

#include "zx.h"
#include "zxid.h"
#include "zxidutil.h"
#include "c/zxidvers.h"
#include "c/zx-data.h"
#include "c/zx-const.h"
#include "c/zx-ns.h"

const char* help =
"zxmqtest  -  ZX Message Queue tester - R" ZXID_REL "\n\
Copyright (c) 2010-2011 Sampo Kellomaki (sampo@iki.fi), All Rights Reserved.\n\
NO WARRANTY, not even implied warranties. Licensed under Apache License v2.0\n\
See http://www.apache.org/licenses/LICENSE-2.0\n\
Send well researched bug reports to the author. Home: zxid.org\n\
\n\
Usage: zxmqtest [options]\n\
  -l           Listener mode\n\
  -r N         Run test number N. 1 = IBM cert dec, 2 = IBM cert enc dec\n\
  -i N         Number of iterations to benchmark (default 1).\n\
  -t SECONDS   Timeout. Default: 0=no timeout.\n\
  -c CIPHER    Enable crypto on DTS interface using specified cipher. Use '?' for list.\n\
  -k FDNUMBER  File descriptor for reading symmetric key. Use 0 for stdin.\n\
  -egd PATH    Specify path of Entropy Gathering Daemon socket, default\n\
               on Solaris: /tmp/entropy; Linux: /dev/urandom\n\
               See http://www.lothar.com/tech/crypto/ or\n\
               http://www.aet.tu-cottbus.de/personen/jaenicke/postfix_tls/prngd.html\n\
  -rand PATH   Location of random number seed file. On Solaris EGD is used.\n\
               On Linux the default is /dev/urandom. See RFC1750.\n\
  -v           Verbose messages.\n\
  -q           Be extra quiet.\n\
  -d           Turn on debugging.\n\
  -license     Show licensing and NO WARRANTY details.\n\
  -h           This help message\n\
  --           End of options\n";

#define DIE(reason) MB fprintf(stderr, "%s\n", reason); exit(2); ME
char buf[256*1024];


int ak_buf_size = 0;
int verbose = 1;
extern int debug;
int timeout = 0;
int gcthreshold = 0;
int leak_free = 0;
extern int assert_nonfatal;
int drop_uid = 0;
int drop_gid = 0;
char* rand_path;
char* egd_path;
char  symmetric_key[1024];
int symmetric_key_len;
int n_iter = 1;
int listen_mode = 0;

/* Called by:  main x8, zxbusd_main, zxbuslist_main, zxbustailf_main, zxcall_main, zxcot_main, zxdecode_main */
void opt(int* argc, char*** argv, char*** env)
{
  if (*argc < 1) goto argerr;
  
  while (1) {
    ++(*argv); --(*argc);
    
    if (!(*argc) || ((*argv)[0][0] != '-')) break;
    
    switch ((*argv)[0][1]) {
    case '-': if ((*argv)[0][2]) break;
      ++(*argv); --(*argc);
      DD("End of options by --");
      return;  /* -- ends the options */

    case 'i': if ((*argv)[0][2]) break;
      ++(*argv); --(*argc);
      if (!(*argc)) break;
      n_iter = atoi((*argv)[0]);
      continue;

    case 't': if ((*argv)[0][2]) break;
      ++(*argv); --(*argc);
      if (!(*argc)) break;
      timeout = atoi((*argv)[0]);
      continue;

    case 'd':
      switch ((*argv)[0][2]) {
      case '\0':
	++zx_debug;
	continue;
      case 'i':  if ((*argv)[0][3]) break;
	++(*argv); --(*argc);
	if (!(*argc)) break;
	strncpy(zx_instance, (*argv)[0], sizeof(zx_instance));
	continue;
      }
      break;

    case 'v':
      switch ((*argv)[0][2]) {
      case '\0':
	++verbose;
	continue;
      }
      break;

    case 'q':
      switch ((*argv)[0][2]) {
      case '\0':
	verbose = 0;
	continue;
      }
      break;

    case 'e':
      switch ((*argv)[0][2]) {
      case 'g': if ((*argv)[0][3] != 'd' || (*argv)[0][4]) break;
	++(*argv); --(*argc);
	if (!(*argc)) break;
	egd_path = (*argv)[0];
	continue;
      }
      break;
      
    case 'r':
      switch ((*argv)[0][2]) {
      case 'f':
	/*AK_TS(LEAK, 0, "memory leaks enabled");*/
#if 1
	ERR("*** WARNING: You have turned memory frees to memory leaks. We will (eventually) run out of memory. Using -rf is not recommended. %d\n", 0);
#endif
	++leak_free;
	continue;
#if 0
      case 'e':
	if ((*argv)[0][3]) break;
	++(*argv); --(*argc);
	if ((*argc) < 4) break;
	sscanf((*argv)[0], "%i", &abort_funcno);
	++(*argv); --(*argc);
	sscanf((*argv)[0], "%i", &abort_line);
	++(*argv); --(*argc);
	sscanf((*argv)[0], "%i", &abort_error_code);
	++(*argv); --(*argc);
	sscanf((*argv)[0], "%i", &abort_iter);
	fprintf(stderr, "Will force core upon %x:%x err=%d iter=%d\n",
		abort_funcno, abort_line, abort_error_code, abort_iter);
	continue;
#endif
      case 'g':
	if ((*argv)[0][3]) break;
	++(*argv); --(*argc);
	if (!(*argc)) break;
	gcthreshold = atoi((*argv)[0]);
	if (!gcthreshold)
	  ERR("*** WARNING: You have disabled garbage collection. This may lead to increased memory consumption for scripts that handle a lot of PDUs or run for long time. Using `-rg 0' is not recommended. %d\n", 0);
	continue;
      case 'a':
	if ((*argv)[0][3] == 0) {
	  /*AK_TS(ASSERT_NONFATAL, 0, "assert nonfatal enabled");*/
#if 1
	  ERR("*** WARNING: YOU HAVE TURNED ASSERTS OFF USING -ra FLAG. THIS MEANS THAT YOU WILL NOT BE ABLE TO OBTAIN ANY SUPPORT. IF PROGRAM NOW TRIES TO ASSERT IT MAY MYSTERIOUSLY AND UNPREDICTABLY CRASH INSTEAD, AND NOBODY WILL BE ABLE TO FIGURE OUT WHAT WENT WRONG OR HOW MUCH DAMAGE MAY BE DONE. USING -ra IS NOT RECOMMENDED. %d\n", assert_nonfatal);
#endif
	  ++assert_nonfatal;
	  continue;
	}
	if (!strcmp((*argv)[0],"-rand")) {
	  ++(*argv); --(*argc);
	  if (!(*argc)) break;
	  rand_path = (*argv)[0];
	  continue;
	}
	break;
      }
      break;

    case 'k':
      switch ((*argv)[0][2]) {
      case '\0':
	++(*argv); --(*argc);
	if (!(*argc)) break;
	read_all_fd(atoi((*argv)[0]), symmetric_key, sizeof(symmetric_key), &symmetric_key_len);
	D("Got %d characters of symmetric key", symmetric_key_len);
	continue;
      }
      break;

    case 'c': if ((*argv)[0][2]) break;
      ++(*argv); --(*argc);
      if (!(*argc)) break;
#ifndef ENCRYPTION
      ERR("Encryption not compiled in. %d",0);
#endif
      continue;

    case 'u':
      switch ((*argv)[0][2]) {
      case 'i': if ((*argv)[0][3] != 'd' || (*argv)[0][4]) break;
	++(*argv); --(*argc);
	if (!(*argc)) break;
	sscanf((*argv)[0], "%i:%i", &drop_uid, &drop_gid);
	continue;
      }
      break;

    case 'l':
      switch ((*argv)[0][2]) {
      case 0:
	++listen_mode;
	continue;
      case 'i':
	if (!strcmp((*argv)[0],"-license")) {
	  extern char* license;
	  fprintf(stderr, license);
	  exit(0);
	}
	break;
      }
      break;

    } 
    /* fall thru means unrecognized flag */
    if (*argc)
      fprintf(stderr, "Unrecognized flag `%s'\n", (*argv)[0]);
  argerr:
    fprintf(stderr, help);
    exit(3);
  }
}

/* ============== M A I N ============== */

/* Called by: */
int main(int argc, char** argv, char** env)
{
  int ret, got_all, len;
#ifdef OPENAMQ
  amq_client_connection_t* amq_conn;
  amq_client_session_t* amq_ses;
  amq_content_basic_t* content = NULL;
  icl_longstr_t* auth_data;
#endif
#ifdef ZMQ
  struct zx_ctx ctx;
  struct zx_root_s* r;
  int major, minor, patch;
  void* zmq_ctx;
  void* zmq_fd;
  zmq_msg_t msg;
#endif
  opt(&argc, &argv, &env);

#ifdef OPENAMQ
  icl_system_initialise(argc, argv);
  auth_data  = amq_client_connection_auth_plain("guest", "guest");
  if (!auth_data) {
    ERR("auth plain: %d %s", errno, STRERROR(errno));
    exit(1);
  }
  amq_conn = amq_client_connection_new("localhost", "/", auth_data, "test", 0, 30000);
  icl_longstr_destroy(&auth_data);
  if (!amq_conn) {
    ERR("new client conn: %d %s", errno, STRERROR(errno));
    exit(1);
  }

  D("amq_conn:\n direct(%d)\n alive(%d)\n silent(%d)\n error_text(%s)\n reply_text(%s)\n reply_code(%d)\n version_major(%d)\n version_minor(%d)\n server_product(%s)\n server_version(%s)\n server_platform(%s)\n server_copyright(%s)\n server_information(%s)\n server_identifier(%s)\n id(%s)", amq_conn->direct, amq_conn->alive, amq_conn->silent, amq_conn->error_text, amq_conn->reply_text, amq_conn->reply_code, amq_conn->version_major, amq_conn->version_minor, amq_conn->server_product, amq_conn->server_version, amq_conn->server_platform, amq_conn->server_copyright, amq_conn->server_information, amq_conn->server_identifier, amq_conn->id);

  amq_ses = amq_client_session_new(amq_conn);
  if (!amq_ses) {
    ERR("new ses: %d %s", errno, STRERROR(errno));
    exit(1);
  }

  DD("amq_ses:\n alive(%d)\n timestamp(%d)\n error_text(%s)\n ticket(%d)\n queue(%s)\n exchange(%s)\n message_count(%s)\n consumer_count(%d)\n active(%d)\n reply_text(%s)\n reply_code(%d)\n consumer_tag(%d)\n routing_key(%s)\n scope(%s)\n delivery_tag(%d)\n redelivered(%d)", amq_ses->alive, amq_ses->timestamp, amq_ses->error_text, amq_ses->ticket, amq_ses->queue, amq_ses->exchange, amq_ses->message_count, amq_ses->consumer_count, amq_ses->active, amq_ses->reply_text, amq_ses->reply_code, amq_ses->consumer_tag, amq_ses->routing_key, amq_ses->scope, amq_ses->delivery_tag, amq_ses->redelivered);
  D("amq_ses:\n alive(%d)\n timestamp(%lld)\n error_text(%s)\n queue(%s)\n exchange(%s)\n message_count(%ld)\n consumer_count(%d)\n active(%d)\n reply_text(%s)\n reply_code(%d)\n consumer_tag(%s)\n routing_key(%s)\n delivery_tag(%lld)\n redelivered(%d)", amq_ses->alive, amq_ses->timestamp, amq_ses->error_text, amq_ses->queue, amq_ses->exchange, amq_ses->message_count, amq_ses->consumer_count, amq_ses->active, amq_ses->reply_text, amq_ses->reply_code, amq_ses->consumer_tag, amq_ses->routing_key, amq_ses->delivery_tag, amq_ses->redelivered);

  if (listen_mode) {
    //  Create a private queue
    ret = amq_client_session_queue_declare(
        amq_ses,                        //  session
        0,                              //  ticket
        0,                              //  queue name
        FALSE,                          //  passive
        TRUE,                           //  durable
        TRUE,                           //  exclusive
        FALSE,                          //  auto-delete
        0);                             //  arguments tab
    if (ret) {
      ERR("ret=%d: %d %s", ret, errno, STRERROR(errno));
      exit(1);
    }

    DD("amq_ses: QUEUE(%s)\n alive(%d)\n timestamp(%d)\n error_text(%s)\n ticket(%d)\n queue(%s)\n exchange(%s)\n message_count(%s)\n consumer_count(%d)\n active(%d)\n reply_text(%s)\n reply_code(%d)\n consumer_tag(%d)\n routing_key(%s)\n scope(%s)\n delivery_tag(%d)\n redelivered(%d)", amq_ses->queue, amq_ses->alive, amq_ses->timestamp, amq_ses->error_text, amq_ses->ticket, amq_ses->queue, amq_ses->exchange, amq_ses->message_count, amq_ses->consumer_count, amq_ses->active, amq_ses->reply_text, amq_ses->reply_code, amq_ses->consumer_tag, amq_ses->routing_key, amq_ses->scope, amq_ses->delivery_tag, amq_ses->redelivered);
    D("amq_ses: QUEUE(%s)\n alive(%d)\n timestamp(%lld)\n error_text(%s)\n queue(%s)\n exchange(%s)\n message_count(%ld)\n consumer_count(%d)\n active(%d)\n reply_text(%s)\n reply_code(%d)\n consumer_tag(%s)\n routing_key(%s)\n delivery_tag(%lld)\n redelivered(%d)", amq_ses->queue, amq_ses->alive, amq_ses->timestamp, amq_ses->error_text, amq_ses->queue, amq_ses->exchange, amq_ses->message_count, amq_ses->consumer_count, amq_ses->active, amq_ses->reply_text, amq_ses->reply_code, amq_ses->consumer_tag, amq_ses->routing_key, amq_ses->delivery_tag, amq_ses->redelivered);
    
    /* *** consider setting our own exchange, see:
     * http://blogs.digitar.com/jjww/2009/01/rabbits-and-warrens/ */

    /* A binding is a routing rule that links an exchange to a queue
     * based on a routing key. It is possible for two binding rules to
     * use the same routing key. For example, maybe messages with the
     * routing key "audit" need to go both to the "log-forever" queue
     * and the "alert-the-big-dude" queue. To accomplish this, just
     * create two binding rules (each one linking the exchange to one
     * of the queues) that both trigger on routing key "audit". In
     * this case, the exchange duplicates the message and sends it to
     * both queues. Exchanges are just routing tables containing
     * bindings. */

    //  Bind the queue to the exchange
    ret = amq_client_session_queue_bind(
        amq_ses,                        //  session
        0,                              //  ticket
        0,                              //  queue (0=last declared queue of ses)
        "amq.direct",                   //  exchange
        "reitti",                       //  routing-key
        0);                             //  arguments tab
    if (ret) {
      ERR("ret=%d: %d %s", ret, errno, STRERROR(errno));
      exit(1);
    }

    //  Consume from the queue
    ret = amq_client_session_basic_consume(
        amq_ses,                        //  session
        0,                              //  ticket
        0,                              //  queue (0=?)
        0,                              //  consumer-tag
        TRUE,                           //  no-local
        TRUE,                           //  no-ack
        TRUE,                           //  exclusive
        0);                             //  arguments tab
    if (ret) {
      ERR("ret=%d: %d %s", ret, errno, STRERROR(errno));
      exit(1);
    }

    while (1) {
      while (1) {
	ret = amq_client_session_get_basic_arrived_count(amq_ses);
	D("arrived count=%d", ret);
	//  Get next message
	content = amq_client_session_basic_arrived(amq_ses);
	if (!content)
	  break;
	D("content:\n body_size(%lld)\n exchange(%s)\n routing_key(%s)\n producer_id(%s)\n content_type(%s)\n content_encoding(%s)\n headers(%p)\n delivery_mode(%d)\n priority(%d)\n correlation_id(%s)\n reply_to(%s)\n expiration(%s)\n message_id(%s)\n timestamp(%lld)\n type(%s)\n user_id(%s)\n app_id(%s)\n sender_id(%s)", content->body_size, content->exchange, content->routing_key, content->producer_id, content->content_type, content->content_encoding, content->headers, content->delivery_mode, content->priority, content->correlation_id, content->reply_to, content->expiration, content->message_id, content->timestamp, content->type, content->user_id, content->app_id, content->sender_id);

	//  Get the message body and write it to stdout
	len = amq_content_basic_get_body(content, (byte*)buf, sizeof(buf)-1);
	if (len) {
	  buf[len] = 0;
	  printf("got(%s)\n",buf);
	  //fputs(buf, stdout);
	}
	//  Destroy the message
	amq_content_basic_unlink(&content);
      }
      //  Wait while next message arrives
      amq_client_session_wait(amq_ses, 0);

      //  Exit the loop if Ctrl+C is encountered
      if (!amq_conn->alive)
	break;
    }
  } else {

    /* Send message experiment */
    //  Create a content and send it to the "queue" exchange
    content = amq_content_basic_new();
    if (!content) {
      ERR("new content: %d %s", errno, STRERROR(errno));
      exit(1);
    }
    ret = amq_content_basic_set_body(content, "Hello World!", 10, NULL);
    if (ret) {
      ERR("ret=%d: %d %s", ret, errno, STRERROR(errno));
      exit(1);
    }
    ret = amq_content_basic_set_message_id(content, "ID001");
    if (ret) {
      ERR("ret=%d: %d %s", ret, errno, STRERROR(errno));
      exit(1);
    }

    D("content:\n body_size(%lld)\n exchange(%s)\n routing_key(%s)\n producer_id(%s)\n content_type(%s)\n content_encoding(%s)\n headers(%p)\n delivery_mode(%d)\n priority(%d)\n correlation_id(%s)\n reply_to(%s)\n expiration(%s)\n message_id(%s)\n timestamp(%lld)\n type(%s)\n user_id(%s)\n app_id(%s)\n sender_id(%s)", content->body_size, content->exchange, content->routing_key, content->producer_id, content->content_type, content->content_encoding, content->headers, content->delivery_mode, content->priority, content->correlation_id, content->reply_to, content->expiration, content->message_id, content->timestamp, content->type, content->user_id, content->app_id, content->sender_id);

    /* When you publish your message to an exchange, there's a flag
     * called "Delivery Mode". Depending on the AMQP library you're
     * using there will be different ways of setting it. But the long
     * and the short of it is you want the "Delivery Mode" set to the
     * value 2, which means "persistent". "Delivery Mode" usually
     * (depending on your AMQP library) defaults to a value of 1,
     * which means "non-persistent". So the steps for persistent
     * messaging are:
     *   1. Mark the exchange "durable".
     *   2. Mark the queue "durable".
     *   3. Set the message's "delivery mode" to a value of 2
     */

    ret = amq_client_session_basic_publish(amq_ses,
					   content,
					   0,               /* ticket */
					   "amq.direct",    /* Exchange */
					   "reitti",        /* Routing key */
					   FALSE,           /* Mandatory */
					   FALSE);          /* Immediate */
    amq_content_basic_unlink(&content);
    if (ret) {
      ERR("ret=%d: %d %s", ret, errno, STRERROR(errno));
      exit(1);
    }
  }
  
  amq_client_session_destroy(&amq_ses);
  amq_client_connection_destroy(&amq_conn);
  icl_system_terminate();
  exit(0);
#endif
  
#ifdef ZMQ
  zmq_ctx = zmq_init(1);
  if (!zmq_ctx) {
    ERR("Init fail: %d %s", errno, STRERROR(errno));
    exit(1);
  }
  zmq_version(&major, &minor, &patch);
  D("zmq_version=%d.%d.%d %p", major, minor, patch, zmq_ctx);

  zmq_fd = zmq_socket(zmq_ctx, ZMQ_PUB);
  if (!zmq_fd) {
    ERR("Socket fail: %d %s", errno, STRERROR(errno));
    exit(1);
  }
  D("zmq_fd %p", zmq_fd);

  //zmq_connect(zmq_socket, "tcp://audit.tas3.nottingham.ac.uk:5672");
  ret = zmq_connect(zmq_fd, "tcp://audit.tas3.nottingham.ac.uk");
  if (ret == -1) {
    ERR("Connect fail: %d %s", errno, STRERROR(errno));
    exit(1);
  }

  ret = zmq_msg_init_data(&msg, "foo", 3, 0, 0);
  if (ret == -1) {
    ERR("msg init data fail: %d %s", errno, STRERROR(errno));
    exit(1);
  }
  D("will send... zmq_fd %p", zmq_fd);

  ret = zmq_send(zmq_fd, &msg, 0);
  if (ret == -1) {
    ERR("Send fail: %d %s", errno, STRERROR(errno));
    exit(1);
  }

  D("sent. closing... zmq_fd %p", zmq_fd);
  ret = zmq_msg_close(&msg);
  if (ret == -1) {
    ERR("msg close fail: %d %s", errno, STRERROR(errno));
    exit(1);
  }
  
  ret = zmq_close(zmq_fd);
  if (ret == -1) {
    ERR("Close fail: %d %s", errno, STRERROR(errno));
    exit(1);
  }
  zmq_term(zmq_ctx);
  D("done %d", 0);
  exit(0);
#endif

  len = read_all_fd(fileno(stdin), buf, sizeof(buf)-1, &got_all);
  if (got_all <= 0) DIE("Missing data");
  buf[got_all] = 0;
  return 0;
}

/* EOF  --  zxmqtest.c */

/*
openamq-dev@lists.openamq.org

I need a pure C implementation of AMQP and found OpenAMQP. Basically I am using wireapi
and amq_server. For me the more important part is the wireapi and I hope to interoperate
with other AMQP implementations.

However, I have some questions

1. Is the project really abandoned? Is 0-10 or 1-0 support ever forthcoming?
2. Is there any SSL support, at least in wireapi client?

On the latter point I have further specifics:

a. In addition to using SSL for encryption, I would like to use Client-TLS authentication (but
basic auth over server-TLS remains an option if nothing better is available).

b. If, as it appears, SSL support is not there, how would folks feel about using OpenSSL
for this? If I were to add OpenSSL support, any pointers to where to insert it in
the source code? OpenAMQ at 1 million lines of code is quite daunting for
what it does (OpenSSL is 300k lines and that is already a lot of bloat), so I would
appreciate pointers about what to learn and what to ignore.

Cheers,
--Sampo
*/
