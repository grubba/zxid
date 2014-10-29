/* precheck/chk-curl.c  -  Check that Curl include files and libraries are available
 * Copyright (c) 2008 Symlabs (symlabs@symlabs.com), All Rights Reserved.
 * Author: Sampo Kellomaki (sampo@iki.fi)
 * This is confidential unpublished proprietary source code of the author.
 * NO WARRANTY, not even implied warranties. Contains trade secrets.
 * Distribution prohibited unless authorized in writing.
 * Licensed under Apache License 2.0, see file COPYING.
 * $Id: chk-curl.c,v 1.1 2008-09-17 03:41:11 sampo Exp $
 *
 * 16.9.2008, created --Sampo
 */

#ifdef USE_CURL
#include <curl/curl.h>
#include <curl/curlver.h>
#endif

#include <stdio.h>

/* Called by: */
int main(int argc, char** argv)
{
#ifdef USE_CURL
  printf("  -- libcurl version from curlver.h: %s\n", LIBCURL_VERSION);
  printf("  -- from curl_version(): %s\n", curl_version());
#endif
  return 0;
}

/* EOF  --  chk-curl.c */
