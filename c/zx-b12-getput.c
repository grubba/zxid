/* c/zx-b12-getput.c - WARNING: This file was automatically generated. DO NOT EDIT!
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
#include "c/zx-b12-data.h"

/* FUNC(zx_b12_Consent_GET_id) */
struct zx_str* zx_b12_Consent_GET_id(struct zx_b12_Consent_s* x) { return x->id; }
/* FUNC(zx_b12_Consent_PUT_id) */
void zx_b12_Consent_PUT_id(struct zx_b12_Consent_s* x, struct zx_str* y) { x->id = y; }
/* FUNC(zx_b12_Consent_GET_timestamp) */
struct zx_str* zx_b12_Consent_GET_timestamp(struct zx_b12_Consent_s* x) { return x->timestamp; }
/* FUNC(zx_b12_Consent_PUT_timestamp) */
void zx_b12_Consent_PUT_timestamp(struct zx_b12_Consent_s* x, struct zx_str* y) { x->timestamp = y; }
/* FUNC(zx_b12_Consent_GET_uri) */
struct zx_str* zx_b12_Consent_GET_uri(struct zx_b12_Consent_s* x) { return x->uri; }
/* FUNC(zx_b12_Consent_PUT_uri) */
void zx_b12_Consent_PUT_uri(struct zx_b12_Consent_s* x, struct zx_str* y) { x->uri = y; }
/* FUNC(zx_b12_Consent_GET_actor) */
struct zx_str* zx_b12_Consent_GET_actor(struct zx_b12_Consent_s* x) { return x->actor; }
/* FUNC(zx_b12_Consent_PUT_actor) */
void zx_b12_Consent_PUT_actor(struct zx_b12_Consent_s* x, struct zx_str* y) { x->actor = y; }
/* FUNC(zx_b12_Consent_GET_mustUnderstand) */
struct zx_str* zx_b12_Consent_GET_mustUnderstand(struct zx_b12_Consent_s* x) { return x->mustUnderstand; }
/* FUNC(zx_b12_Consent_PUT_mustUnderstand) */
void zx_b12_Consent_PUT_mustUnderstand(struct zx_b12_Consent_s* x, struct zx_str* y) { x->mustUnderstand = y; }





/* FUNC(zx_b12_Correlation_GET_id) */
struct zx_str* zx_b12_Correlation_GET_id(struct zx_b12_Correlation_s* x) { return x->id; }
/* FUNC(zx_b12_Correlation_PUT_id) */
void zx_b12_Correlation_PUT_id(struct zx_b12_Correlation_s* x, struct zx_str* y) { x->id = y; }
/* FUNC(zx_b12_Correlation_GET_messageID) */
struct zx_str* zx_b12_Correlation_GET_messageID(struct zx_b12_Correlation_s* x) { return x->messageID; }
/* FUNC(zx_b12_Correlation_PUT_messageID) */
void zx_b12_Correlation_PUT_messageID(struct zx_b12_Correlation_s* x, struct zx_str* y) { x->messageID = y; }
/* FUNC(zx_b12_Correlation_GET_refToMessageID) */
struct zx_str* zx_b12_Correlation_GET_refToMessageID(struct zx_b12_Correlation_s* x) { return x->refToMessageID; }
/* FUNC(zx_b12_Correlation_PUT_refToMessageID) */
void zx_b12_Correlation_PUT_refToMessageID(struct zx_b12_Correlation_s* x, struct zx_str* y) { x->refToMessageID = y; }
/* FUNC(zx_b12_Correlation_GET_timestamp) */
struct zx_str* zx_b12_Correlation_GET_timestamp(struct zx_b12_Correlation_s* x) { return x->timestamp; }
/* FUNC(zx_b12_Correlation_PUT_timestamp) */
void zx_b12_Correlation_PUT_timestamp(struct zx_b12_Correlation_s* x, struct zx_str* y) { x->timestamp = y; }
/* FUNC(zx_b12_Correlation_GET_actor) */
struct zx_str* zx_b12_Correlation_GET_actor(struct zx_b12_Correlation_s* x) { return x->actor; }
/* FUNC(zx_b12_Correlation_PUT_actor) */
void zx_b12_Correlation_PUT_actor(struct zx_b12_Correlation_s* x, struct zx_str* y) { x->actor = y; }
/* FUNC(zx_b12_Correlation_GET_mustUnderstand) */
struct zx_str* zx_b12_Correlation_GET_mustUnderstand(struct zx_b12_Correlation_s* x) { return x->mustUnderstand; }
/* FUNC(zx_b12_Correlation_PUT_mustUnderstand) */
void zx_b12_Correlation_PUT_mustUnderstand(struct zx_b12_Correlation_s* x, struct zx_str* y) { x->mustUnderstand = y; }





/* FUNC(zx_b12_ProcessingContext_GET_id) */
struct zx_str* zx_b12_ProcessingContext_GET_id(struct zx_b12_ProcessingContext_s* x) { return x->id; }
/* FUNC(zx_b12_ProcessingContext_PUT_id) */
void zx_b12_ProcessingContext_PUT_id(struct zx_b12_ProcessingContext_s* x, struct zx_str* y) { x->id = y; }
/* FUNC(zx_b12_ProcessingContext_GET_actor) */
struct zx_str* zx_b12_ProcessingContext_GET_actor(struct zx_b12_ProcessingContext_s* x) { return x->actor; }
/* FUNC(zx_b12_ProcessingContext_PUT_actor) */
void zx_b12_ProcessingContext_PUT_actor(struct zx_b12_ProcessingContext_s* x, struct zx_str* y) { x->actor = y; }
/* FUNC(zx_b12_ProcessingContext_GET_mustUnderstand) */
struct zx_str* zx_b12_ProcessingContext_GET_mustUnderstand(struct zx_b12_ProcessingContext_s* x) { return x->mustUnderstand; }
/* FUNC(zx_b12_ProcessingContext_PUT_mustUnderstand) */
void zx_b12_ProcessingContext_PUT_mustUnderstand(struct zx_b12_ProcessingContext_s* x, struct zx_str* y) { x->mustUnderstand = y; }





/* FUNC(zx_b12_Provider_GET_affiliationID) */
struct zx_str* zx_b12_Provider_GET_affiliationID(struct zx_b12_Provider_s* x) { return x->affiliationID; }
/* FUNC(zx_b12_Provider_PUT_affiliationID) */
void zx_b12_Provider_PUT_affiliationID(struct zx_b12_Provider_s* x, struct zx_str* y) { x->affiliationID = y; }
/* FUNC(zx_b12_Provider_GET_id) */
struct zx_str* zx_b12_Provider_GET_id(struct zx_b12_Provider_s* x) { return x->id; }
/* FUNC(zx_b12_Provider_PUT_id) */
void zx_b12_Provider_PUT_id(struct zx_b12_Provider_s* x, struct zx_str* y) { x->id = y; }
/* FUNC(zx_b12_Provider_GET_providerID) */
struct zx_str* zx_b12_Provider_GET_providerID(struct zx_b12_Provider_s* x) { return x->providerID; }
/* FUNC(zx_b12_Provider_PUT_providerID) */
void zx_b12_Provider_PUT_providerID(struct zx_b12_Provider_s* x, struct zx_str* y) { x->providerID = y; }
/* FUNC(zx_b12_Provider_GET_actor) */
struct zx_str* zx_b12_Provider_GET_actor(struct zx_b12_Provider_s* x) { return x->actor; }
/* FUNC(zx_b12_Provider_PUT_actor) */
void zx_b12_Provider_PUT_actor(struct zx_b12_Provider_s* x, struct zx_str* y) { x->actor = y; }
/* FUNC(zx_b12_Provider_GET_mustUnderstand) */
struct zx_str* zx_b12_Provider_GET_mustUnderstand(struct zx_b12_Provider_s* x) { return x->mustUnderstand; }
/* FUNC(zx_b12_Provider_PUT_mustUnderstand) */
void zx_b12_Provider_PUT_mustUnderstand(struct zx_b12_Provider_s* x, struct zx_str* y) { x->mustUnderstand = y; }





/* FUNC(zx_b12_UsageDirective_GET_id) */
struct zx_str* zx_b12_UsageDirective_GET_id(struct zx_b12_UsageDirective_s* x) { return x->id; }
/* FUNC(zx_b12_UsageDirective_PUT_id) */
void zx_b12_UsageDirective_PUT_id(struct zx_b12_UsageDirective_s* x, struct zx_str* y) { x->id = y; }
/* FUNC(zx_b12_UsageDirective_GET_ref) */
struct zx_str* zx_b12_UsageDirective_GET_ref(struct zx_b12_UsageDirective_s* x) { return x->ref; }
/* FUNC(zx_b12_UsageDirective_PUT_ref) */
void zx_b12_UsageDirective_PUT_ref(struct zx_b12_UsageDirective_s* x, struct zx_str* y) { x->ref = y; }
/* FUNC(zx_b12_UsageDirective_GET_actor) */
struct zx_str* zx_b12_UsageDirective_GET_actor(struct zx_b12_UsageDirective_s* x) { return x->actor; }
/* FUNC(zx_b12_UsageDirective_PUT_actor) */
void zx_b12_UsageDirective_PUT_actor(struct zx_b12_UsageDirective_s* x, struct zx_str* y) { x->actor = y; }
/* FUNC(zx_b12_UsageDirective_GET_mustUnderstand) */
struct zx_str* zx_b12_UsageDirective_GET_mustUnderstand(struct zx_b12_UsageDirective_s* x) { return x->mustUnderstand; }
/* FUNC(zx_b12_UsageDirective_PUT_mustUnderstand) */
void zx_b12_UsageDirective_PUT_mustUnderstand(struct zx_b12_UsageDirective_s* x, struct zx_str* y) { x->mustUnderstand = y; }





/* EOF -- c/zx-b12-getput.c */
