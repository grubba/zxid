/* c/zx-paos-getput.c - WARNING: This file was automatically generated. DO NOT EDIT!
 * $Id$ */
/* Code generation design Copyright (c) 2006 Sampo Kellomaki (sampo@iki.fi),
 * All Rights Reserved. NO WARRANTY. See file COPYING for terms and conditions
 * of use. Some aspects of code generation were driven by schema
 * descriptions that were used as input and may be subject to their own copyright.
 * Code generation uses a template, whose copyright statement follows. */

/** getput-templ.c  -  Auxiliary functions template: cloning, freeing, walking data
 ** Copyright (c) 2006 Symlabs (symlabs@symlabs.com), All Rights Reserved.
 ** Author: Sampo Kellomaki (sampo@iki.fi)
 ** This is confidential unpublished proprietary source code of the author.
 ** NO WARRANTY, not even implied warranties. Contains trade secrets.
 ** Distribution prohibited unless authorized in writing.
 ** Licensed under Apache License 2.0, see file COPYING.
 ** Id: getput-templ.c,v 1.8 2009-08-30 15:09:26 sampo Exp $
 **
 ** 30.5.2006, created, Sampo Kellomaki (sampo@iki.fi)
 ** 6.8.2006, factored from enc-templ.c to separate file --Sampo
 **
 ** N.B: wo=wire order (needed for exc-c14n), so=schema order
 ** Edit with care! xsd2sg.pl applies various substitutions to this file.
 **/

#include <memory.h>
#include "errmac.h"
#include "zx.h"
#include "c/zx-const.h"
#include "c/zx-data.h"
#include "c/zx-paos-data.h"

/* FUNC(zx_paos_Request_GET_messageID) */
struct zx_str* zx_paos_Request_GET_messageID(struct zx_paos_Request_s* x) { return x->messageID; }
/* FUNC(zx_paos_Request_PUT_messageID) */
void zx_paos_Request_PUT_messageID(struct zx_paos_Request_s* x, struct zx_str* y) { x->messageID = y; }
/* FUNC(zx_paos_Request_GET_responseConsumerURL) */
struct zx_str* zx_paos_Request_GET_responseConsumerURL(struct zx_paos_Request_s* x) { return x->responseConsumerURL; }
/* FUNC(zx_paos_Request_PUT_responseConsumerURL) */
void zx_paos_Request_PUT_responseConsumerURL(struct zx_paos_Request_s* x, struct zx_str* y) { x->responseConsumerURL = y; }
/* FUNC(zx_paos_Request_GET_service) */
struct zx_str* zx_paos_Request_GET_service(struct zx_paos_Request_s* x) { return x->service; }
/* FUNC(zx_paos_Request_PUT_service) */
void zx_paos_Request_PUT_service(struct zx_paos_Request_s* x, struct zx_str* y) { x->service = y; }
/* FUNC(zx_paos_Request_GET_actor) */
struct zx_str* zx_paos_Request_GET_actor(struct zx_paos_Request_s* x) { return x->actor; }
/* FUNC(zx_paos_Request_PUT_actor) */
void zx_paos_Request_PUT_actor(struct zx_paos_Request_s* x, struct zx_str* y) { x->actor = y; }
/* FUNC(zx_paos_Request_GET_mustUnderstand) */
struct zx_str* zx_paos_Request_GET_mustUnderstand(struct zx_paos_Request_s* x) { return x->mustUnderstand; }
/* FUNC(zx_paos_Request_PUT_mustUnderstand) */
void zx_paos_Request_PUT_mustUnderstand(struct zx_paos_Request_s* x, struct zx_str* y) { x->mustUnderstand = y; }





/* FUNC(zx_paos_Response_GET_refToMessageID) */
struct zx_str* zx_paos_Response_GET_refToMessageID(struct zx_paos_Response_s* x) { return x->refToMessageID; }
/* FUNC(zx_paos_Response_PUT_refToMessageID) */
void zx_paos_Response_PUT_refToMessageID(struct zx_paos_Response_s* x, struct zx_str* y) { x->refToMessageID = y; }
/* FUNC(zx_paos_Response_GET_actor) */
struct zx_str* zx_paos_Response_GET_actor(struct zx_paos_Response_s* x) { return x->actor; }
/* FUNC(zx_paos_Response_PUT_actor) */
void zx_paos_Response_PUT_actor(struct zx_paos_Response_s* x, struct zx_str* y) { x->actor = y; }
/* FUNC(zx_paos_Response_GET_mustUnderstand) */
struct zx_str* zx_paos_Response_GET_mustUnderstand(struct zx_paos_Response_s* x) { return x->mustUnderstand; }
/* FUNC(zx_paos_Response_PUT_mustUnderstand) */
void zx_paos_Response_PUT_mustUnderstand(struct zx_paos_Response_s* x, struct zx_str* y) { x->mustUnderstand = y; }





/* EOF -- c/zx-paos-getput.c */
