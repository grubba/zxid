/* testping.c  -  Test ping for debugging
 * Copyright (c) 2006,2012 Sampo Kellomaki (sampo@iki.fi), All Rights Reserved.
 * This is confidential unpublished proprietary source code of the author.
 * NO WARRANTY, not even implied warranties. Contains trade secrets.
 * Distribution prohibited unless authorized in writing. See file COPYING.
 * Special grant: testping.c may be used with zxid open source project under
 * same licensing terms as zxid itself.
 * $Id$
 *
 * 15.4.2006, created over Easter holiday --Sampo
 * 16.8.2012, modified license grant to allow use with ZXID.org --Sampo
 */

#include "platform.h"
#include "errmac.h"
#include "akbox.h"
#include "hiios.h"

#include <ctype.h>
#include <memory.h>
#include <netinet/in.h> /* htons(3) and friends */

#define MIN_PING 5
#define MAX_PING 10

/* Called by:  test_ping */
void test_ping_reply(struct hi_thr* hit, struct hi_io* io, struct hi_pdu* req)
{
  int i;
  int n = req->ap - req->m;
  struct hi_pdu* resp = hi_pdu_alloc(hit);
  if (!resp) { NEVERNEVER("*** out of pdus in bad place %d", n); }
  memcpy(resp->ap, req->m, n);
  resp->ap += n;
  for (i = n-1; i; --i)  /* all but the first letter */
    resp->m[i] = toupper(resp->m[i]);
  D("test_ping(%.*s) %d chars", n, resp->m, n);
  hi_send(hit, io, req, resp);
}

/* Called by:  hi_read */
void test_ping(struct hi_thr* hit, struct hi_io* io)
{
  struct hi_pdu* req = io->cur_pdu;
  int n = req->ap - req->m;
  
  if (n < MIN_PING) {   /* too little, need more */
    req->need = MIN_PING - n;
    return;
  }
  
  if (n > MAX_PING) {  /* more than enough */
    struct hi_pdu* nreq = hi_pdu_alloc(hit);
    if (!nreq) { NEVERNEVER("*** out of pdus in bad place %d", n); }
    memcpy(nreq->ap, req->m + MAX_PING, n - MAX_PING);
    nreq->ap += n - MAX_PING;
    n = MAX_PING;
    io->cur_pdu = nreq;
  } else
    io->cur_pdu = 0;
  
  /* Got enough. Associate request with frontend. */
  
  hi_add_to_reqs(io, req);  
  test_ping_reply(hit, io, req);
}

/* EOF  --  testping.c */
