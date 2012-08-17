/* stomp.c  -  STOMP 1.1 protocol for HIIOS engine
 * Copyright (c) 2012 Sampo Kellomaki (sampo@iki.fi), All Rights Reserved.
 * This is confidential unpublished proprietary source code of the author.
 * NO WARRANTY, not even implied warranties. Contains trade secrets.
 * Distribution prohibited unless authorized in writing. See file COPYING.
 * Special grant: http.c may be used with zxid open source project under
 * same licensing terms as zxid itself.
 * $Id$
 *
 * 16.8.2012, created --Sampo
 *
 * See also:  http://stomp.github.com/stomp-specification-1.1.html (20110331)
 */

#include "akbox.h"
#include "hiios.h"
#include "errmac.h"

#include <ctype.h>
#include <memory.h>
#include <netinet/in.h> /* htons(3) and friends */

struct hi_pdu* stomp_encode_start(struct hi_thr* hit)
{
  struct hi_pdu* resp = hi_pdu_alloc(hit);
  if (!resp) { NEVERNEVER("*** out of pdus in bad place %d", 0); }
  return resp;
}

void stomp_send_err(struct hi_thr* hit, struct hi_io* io, struct hi_pdu* req, int r, char* m)
{
  struct hi_pdu* resp = stomp_encode_start(hit);
  resp->len = sprintf(resp->m, "STOMP/1.0 %03d %s\r\nContent-Type: text/plain\r\nContent-Length: %d\r\n\r\n%s", r, m, strlen(m), m);
  hi_send(hit, io, req, resp);
}

void stomp_send_data(struct hi_thr* hit, struct hi_io* io, struct hi_pdu* req, int len, char* d)
{
  struct hi_pdu* resp = stomp_encode_start(hit);
  /*hi_sendv(hit, io, req, resp, len, resp->m, size, req->m + len);*/
}

void stomp_send_file(struct hi_thr* hit, struct hi_io* io, struct hi_pdu* req, int len, char* d)
{
  struct hi_pdu* resp = stomp_encode_start(hit);
  /*hi_sendv(hit, io, req, resp, len, resp->m, size, req->m + len);*/
}

#define STOMP_MIN_PDU_SIZE (sizeof("GET / STOMP/1.0\n\n")-1)

int stomp_decode(struct hi_thr* hit, struct hi_io* io)
{
  struct hi_pdu* req = io->cur_pdu;
  char* url;
  char* url_lim = 0;
  char* p = req->m;
  int n = req->ap - p;
  
  if (n < STOMP_MIN_PDU_SIZE) {   /* too little, need more */
    req->need = STOMP_MIN_PDU_SIZE - n;
    return 0;
  }
  
  if (memcmp(p, "GET /", sizeof("GET /")-1)) {
    ERR("Not a GET STOMP PDU. fd(%x). Got(%.*s)", io->fd, STOMP_MIN_PDU_SIZE, req->m);
    return HI_CONN_CLOSE;
  }

  for (p += 5; p < req->ap - (sizeof(" STOMP/1.0")-2); ++p)
    if (!memcmp(p, " STOMP/1.0\n", sizeof(" STOMP/1.0")-1)) {
      /* Found end of URL */
      url = req->m + 4;
      url_lim = p;
      break;
    }
  
  if (!url_lim) {
    req->need = 1;
    return 0;
  }
  
  io->cur_pdu = 0;
  hi_add_to_reqs(io, req);

  switch (req->m[6]) {
  case 'a': stomp_send_data(hit, io, req, url_lim-url, url); break;
  case 'b': stomp_send_file(hit, io, req, url_lim-url, url); break;  /* *** */
  default:  stomp_send_err(hit, io, req, 500, "Error"); break;
  }
  return 0;
}

/* EOF  --  stomp.c */
