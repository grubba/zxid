/* zxidcurl.c  -  libcurl interface for making SOAP calls and getting metadata
 * Copyright (c) 2010 Sampo Kellomaki (sampo@iki.fi), All Rights Reserved.
 * Copyright (c) 2006-2008 Symlabs (symlabs@symlabs.com), All Rights Reserved.
 * Author: Sampo Kellomaki (sampo@iki.fi)
 * This is confidential unpublished proprietary source code of the author.
 * NO WARRANTY, not even implied warranties. Contains trade secrets.
 * Distribution prohibited unless authorized in writing.
 * Licensed under Apache License 2.0, see file COPYING.
 * $Id: zxidcurl.c,v 1.9 2009-11-24 23:53:40 sampo Exp $
 *
 * 12.8.2006, created --Sampo
 * 4.10.2007, fixed missing Content-length header found by Damien Laniel --Sampo
 * 4.10.2008, added documentation --Sampo
 * 1.2.2010,  removed arbitrary limit on SOAP response size --Sampo
 *
 * See also: http://hoohoo.ncsa.uiuc.edu/cgi/interface.html (CGI specification)
 *           http://curl.haxx.se/libcurl/
 */

#include "platform.h"  /* needed on Win32 for pthread_mutex_lock() et al. */

#include <string.h>

#ifdef USE_CURL
#include <curl/curl.h>

#if LIBCURL_VERSION_NUM < 0x070c00
#define CURL_EASY_STRERR(ec) "error-not-avail-in-curl-before-0x070c00"
#else
#define CURL_EASY_STRERR(ec) curl_easy_strerror(ec)
#endif

#endif

#include "errmac.h"
#include "zxid.h"
#include "zxidconf.h"
#include "c/zx-ns.h"
#include "c/zx-data.h"

/* ============== CoT and Metadata of Others ============== */

/*() Call back used by Curl to move received data to application buffer.
 * Internal. Do not use directly. */

/* Called by: */
size_t zxid_curl_write_data(void *buffer, size_t size, size_t nmemb, void *userp)
{
  int len = size * nmemb;
#if 1
  struct zxid_curl_ctx* rc = (struct zxid_curl_ctx*)userp;
  int old_len, new_len, in_buf = rc->p - rc->buf;
  if (rc->p + len > rc->lim) {
    old_len = rc->lim-rc->buf;
    new_len = MIN(MAX(old_len + old_len, in_buf + len), ZXID_MAX_CURL_BUF);
    if (new_len == ZXID_MAX_CURL_BUF) {
      ERR("Too large HTTP response. Response length at least %d. Maximum allowed length (ZXID_MAX_CURL_BUF): %d", in_buf + len, ZXID_MAX_CURL_BUF);
      return -1;  /* Signal error */
    }
    D("Reallocating curl buffer from %d to %d in_buf=%d len=%d", old_len, new_len, in_buf, len);
    REALLOCN(rc->buf, new_len+1);
    rc->p = rc->buf + in_buf;
    rc->lim = rc->buf + new_len;
  }
  memcpy(rc->p, buffer, len);
  rc->p += len;
  if (zx_debug & CURL_INOUT) INFO("RECV(%.*s) %d chars", len, (char*)buffer, len);
#else
  int fd = (int)userp;
  write_all_fd(fd, buffer, len);
#endif
  return len;
}

/*() Call back used by Curl to move data from application buffer to Curl
 * internal send buffer. Internal. Do not use directly. */

/* Called by: */
size_t zxid_curl_read_data(void *buffer, size_t size, size_t nmemb, void *userp)
{
  int len = size*nmemb;
  struct zxid_curl_ctx* wc = (struct zxid_curl_ctx*)userp;
  if (len > (wc->lim - wc->p))
    len = wc->lim - wc->p;
  memcpy(buffer, wc->p, len);
  wc->p += len;
  if (zx_debug & CURL_INOUT) INFO("SEND(%.*s) %d chars", len, (char*)buffer, len);
  return len;
}

/*() Send HTTP request for metadata using Well Known Location (WKL) method
 * and wait for response. Send the message to the server using Curl. Return
 * the metadata as parsed XML for the entity.
 * This call will block while the HTTP request-response is happening.
 *
 * cf::      ZXID configuration object, also used for memory allocation
 * url::     Where the request will be sent, i.e. the WKL
 * return::  XML data structure representing the entity, or 0 upon failure
 *
 * The underlying HTTP client is libcurl. While libcurl is documented to
 * be "entirely thread safe", one limitation is that chrl handle can not
 * be shared between threads. Since we keep the curl handle a part
 * of the configuration object, which may be shared between threads,
 * we need to take a lock for duration of the curl operation. Thus any
 * given configuration object can have only one HTTP request active
 * at a time. If you need more parallelism, you need more configuration
 * objects.
 */

/* Called by:  opt x3, zxid_addmd, zxid_get_meta_ss */
zxid_entity* zxid_get_meta(zxid_conf* cf, char* url)
{
  zxid_entity* ent;
#ifdef USE_CURL
  CURLcode res;
  struct zxid_curl_ctx rc;
#if 1
  rc.buf = rc.p = ZX_ALLOC(cf->ctx, ZXID_INIT_MD_BUF+1);
  rc.lim = rc.buf + ZXID_INIT_MD_BUF;
  LOCK(cf->curl_mx, "curl get_meta");
  curl_easy_setopt(cf->curl, CURLOPT_WRITEDATA, &rc);
#else
  {
    /* TEST CODE (usually disabled) */
    int fd = open_fd_from_path(O_CREAT | O_WRONLY | O_TRUNC, 0666, "get_meta TEST", "%s" ZXID_COT_DIR "test", cf->path);
    if (fd == -1) {
      perror("open meta to write");
      /*UNLOCK(cf->curl_mx, "curl get_meta");*/
      ERR("Failed to open file(%s) for writing metadata", url);
      return 0;
    }
    curl_easy_setopt(cf->curl, CURLOPT_WRITEDATA, fd);
  }
#endif
  curl_easy_setopt(cf->curl, CURLOPT_WRITEFUNCTION, zxid_curl_write_data);
  curl_easy_setopt(cf->curl, CURLOPT_NOPROGRESS, 1);
  curl_easy_setopt(cf->curl, CURLOPT_FOLLOWLOCATION, 1);
  curl_easy_setopt(cf->curl, CURLOPT_MAXREDIRS, 110);
  curl_easy_setopt(cf->curl, CURLOPT_SSL_VERIFYPEER, 0);
  curl_easy_setopt(cf->curl, CURLOPT_SSL_VERIFYHOST, 0);
  curl_easy_setopt(cf->curl, CURLOPT_URL, url);

  D("get_meta: url(%s)", url);
  if (cf->log_level>1)
    zxlog(cf, 0, 0, 0, 0, 0, 0, 0, "N", "W", "GETMD", url, 0);
  res = curl_easy_perform(cf->curl);
  UNLOCK(cf->curl_mx, "curl get_meta");
  rc.lim = rc.p;
  rc.p[1] = 0;
  rc.p = rc.buf;
  if (rc.lim - rc.p < 300) {
    ERR("Metadata response too short (%d chars, min 300 required). url(%s) CURLcode(%d) CURLerr(%s) buf(%.*s)",	rc.lim-rc.buf, url, res, CURL_EASY_STRERR(res), rc.lim-rc.buf, rc.buf);
    ZX_FREE(cf->ctx, rc.buf);
    return 0;
  }
  
  ent = zxid_parse_meta(cf, &rc.p, rc.lim);
  if (!ent) {
    ERR("Failed to parse metadata response url(%s) CURLcode(%d) CURLerr(%s) buf(%.*s)",	url, res, CURL_EASY_STRERR(res), rc.lim-rc.buf, rc.buf);
    ZX_FREE(cf->ctx, rc.buf);
    return 0;
  }
  if (cf->log_level>0)
    zxlog(cf, 0, 0, 0, 0, 0, 0, 0, "N", "W", "GOTMD", url, 0);
  return ent;
#else
  ERR("This copy of zxid was compiled to NOT use libcurl. As such metadata fetching is not supported. Add -DUSE_CURL and recompile. %d", 0);
  return 0;
#endif
}

/*() Wrapper for zxid_get_meta() so you can provide the URL as ~zx_str~. */
/* Called by:  zxid_get_ent_ss */
zxid_entity* zxid_get_meta_ss(zxid_conf* cf, struct zx_str* url)
{
  return zxid_get_meta(cf, zx_str_to_c(cf->ctx, url));
}

/* ============== SOAP Call ============= */

/*() HTTP client for POST method.
 * This method is just a wrapper around underlying libcurl HTTP client.
 *
 * cf:: ZXID configuration object
 * url_len:: Length of the URL. If -1 is passed, strlen(url) is used
 * url:: URL for POST
 * len:: Length of the data. If -1 is passed, strlen(data) is used
 * data:: HTTP body for the POST
 * returns:: HTTP body of the response */

/* Called by:  zxid_soap_call_raw */
struct zx_str* zxid_http_post_raw(zxid_conf* cf, int url_len, const char* url, int len, const char* data)
{
#ifdef USE_CURL
  struct zx_str* ret;
  CURLcode res;
  struct zxid_curl_ctx rc;
  struct zxid_curl_ctx wc;
  struct curl_slist content_type;
  struct curl_slist SOAPaction;
  char* urli;
  rc.buf = rc.p = ZX_ALLOC(cf->ctx, ZXID_INIT_SOAP_BUF+1);
  rc.lim = rc.buf + ZXID_INIT_SOAP_BUF;
  LOCK(cf->curl_mx, "curl soap");
  curl_easy_setopt(cf->curl, CURLOPT_WRITEDATA, &rc);
  curl_easy_setopt(cf->curl, CURLOPT_WRITEFUNCTION, zxid_curl_write_data);
  curl_easy_setopt(cf->curl, CURLOPT_NOPROGRESS, 1);
  curl_easy_setopt(cf->curl, CURLOPT_FOLLOWLOCATION, 1);
  curl_easy_setopt(cf->curl, CURLOPT_MAXREDIRS, 110);
  curl_easy_setopt(cf->curl, CURLOPT_SSL_VERIFYPEER, 0);  /* *** arrange verification */
  curl_easy_setopt(cf->curl, CURLOPT_SSL_VERIFYHOST, 0);  /* *** arrange verification */
  //curl_easy_setopt(cf->curl, CURLOPT_CERTINFO, 1);

  if (url_len == -1)
    url_len = strlen(url);
  urli = ZX_ALLOC(cf->ctx, url_len+1);
  memcpy(urli, url, url_len);
  urli[url_len] = 0;
  DD("urli(%s) len=%d", urli, len);
  curl_easy_setopt(cf->curl, CURLOPT_URL, urli);
  
  if (len == -1)
    len = strlen(data);
  wc.buf = wc.p = (char*)data;
  wc.lim = (char*)data + len;
  
  curl_easy_setopt(cf->curl, CURLOPT_POST, 1);
  curl_easy_setopt(cf->curl, CURLOPT_POSTFIELDSIZE, len);
  curl_easy_setopt(cf->curl, CURLOPT_READDATA, &wc);
  curl_easy_setopt(cf->curl, CURLOPT_READFUNCTION, zxid_curl_read_data);

  memset(&content_type, 0, sizeof(content_type));
  content_type.data = "Content-Type: text/xml";
  memset(&SOAPaction, 0, sizeof(SOAPaction));
#if 1
  SOAPaction.data = "SOAPAction: \"\"";  /* Empty SOAPAction is the ID-WSF (and SAML?) standard */
#else
  /* Evil stuff: some implementations, especially Apache AXIS, are very
   * picky about SOAPAction header. */
  //SOAPaction.data = "SOAPAction: \"http://ws.apache.org/axis2/TestPolicyPortType/authRequestRequest\"";
  SOAPaction.data = "SOAPAction: \"authRequest\"";
#endif
  SOAPaction.next = &content_type;    //curl_slist_append(3)
  curl_easy_setopt(cf->curl, CURLOPT_HTTPHEADER, &SOAPaction);
  
  D("------------------------ url(%s) ------------------------", urli);
  D("SOAP_CALL post(%.*s) len=%d\n", len, data, len);
  res = curl_easy_perform(cf->curl);  /* <========= Actual call, blocks. */
  switch (res) {
  case 0: break;
  case CURLE_SSL_CONNECT_ERROR:
    ERR("Is the URL(%s) really an https url? Check that certificate of the server is valid and that certification authority is known to the client. CURLcode(%d) CURLerr(%s)", urli, res, CURL_EASY_STRERR(res));
    DD("buf(%.*s)", rc.lim-rc.buf, rc.buf);
#if 0
    struct curl_certinfo* ci;
    res = curl_easy_getinfo(cf->curl, CURLINFO_CERTINFO, &ci);  /* CURLINFO_SSL_VERIFYRESULT */
    if (!res && ci) {
      int i;
      struct curl_slist *slist;
      D("%d certs", ci->num_of_certs);
      for (i = 0; i < ci->num_of_certs; ++i)
	for (slist = ci->certinfo[i]; slist; slist = slist->next)
	  D("%d: %s", i, slist->data);
    }
#endif
    break;
  default:
    ERR("Failed post to url(%s) CURLcode(%d) CURLerr(%s)", urli, res, CURL_EASY_STRERR(res));
    DD("buf(%.*s)", rc.lim-rc.buf, rc.buf);
  }
  UNLOCK(cf->curl_mx, "curl soap");
  ZX_FREE(cf->ctx, urli);
  rc.lim = rc.p;
  rc.p[0] = 0;

  D("SOAP_CALL got(%s)", rc.buf);
  
  ret = zx_ref_len_str(cf->ctx, rc.lim - rc.buf, rc.buf);
  return ret;
#else
  ERR("This copy of zxid was compiled to NOT use libcurl. SOAP calls (such as Artifact profile and WSC) are not supported. Add -DUSE_CURL (make ENA_CURL=1) and recompile. %d", 0);
  return 0;
#endif
}

/*(i) Send SOAP request and wait for response. Send the message to the
 * server using Curl. Return the parsed XML response data structure.
 * This call will block while the HTTP request-response is happening.
 *
 * cf:: ZXID configuration object, also used for memory allocation
 * url:: Where the request will be sent
 * data:: Serialized XML data to be sent
 * ret_enve:: result parameter allows upper layers to see the message as string
 * return:: XML data structure representing the response, or 0 upon failure
 *
 * The underlying HTTP client is libcurl. While libcurl is documented to
 * be "entirely thread safe", one limitation is that chrl handle can not
 * be shared between threads. Since we keep the curl handle a part
 * of the configuration object, which may be shared between threads,
 * we need to take a lock for duration of the curl operation. Thus any
 * given configuration object can have only one HTTP request active
 * at a time. If you need more parallelism, you need more configuration
 * objects.
 */

/* Called by:  zxid_soap_call_envelope, zxid_soap_call_hdr_body */
struct zx_root_s* zxid_soap_call_raw(zxid_conf* cf, struct zx_str* url, struct zx_str* data, char** ret_enve)
{
#ifdef USE_CURL
  struct zx_root_s* r;
  struct zx_str* ret = zxid_http_post_raw(cf, url->len, url->s, data->len, data->s);
  if (ret_enve)
    *ret_enve = ret?ret->s:0;
  if (!ret)
    return 0;
  
  LOCK(cf->ctx->mx, "soap_call");
  zx_prepare_dec_ctx(cf->ctx, zx_ns_tab, ret->s, ret->s + ret->len);
  r = zx_DEC_root(cf->ctx, 0, 1);
  UNLOCK(cf->ctx->mx, "soap_call");
  if (!r || !r->Envelope || !r->Envelope->Body) {
    ERR("Failed to parse SOAP response url(%.*s) buf(%.*s)",
	url->len, url->s, ret->len, ret->s);
    ZX_FREE(cf->ctx, ret);
    return 0;
  }
  return r;
#else
  ERR("This copy of zxid was compiled to NOT use libcurl. SOAP calls (such as Artifact profile and WSC) are not supported. Add -DUSE_CURL (make ENA_CURL=1) and recompile. %d", 0);
  return 0;
#endif
}

/* EOF  --  zxidcurl.c */
