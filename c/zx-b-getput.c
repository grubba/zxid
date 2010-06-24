/* c/zx-b-getput.c - WARNING: This file was automatically generated. DO NOT EDIT!
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
#include "c/zx-b-data.h"



#ifdef ZX_ENA_GETPUT

/* FUNC(zx_b_ApplicationEPR_NUM_Address) */

int zx_b_ApplicationEPR_NUM_Address(struct zx_b_ApplicationEPR_s* x)
{
  struct zx_a_Address_s* y;
  int n = 0;
  if (!x) return 0;
  for (y = x->Address; y; ++n, y = (struct zx_a_Address_s*)y->gg.g.n) ;
  return n;
}

/* FUNC(zx_b_ApplicationEPR_GET_Address) */

struct zx_a_Address_s* zx_b_ApplicationEPR_GET_Address(struct zx_b_ApplicationEPR_s* x, int n)
{
  struct zx_a_Address_s* y;
  if (!x) return 0;
  for (y = x->Address; n>=0 && y; --n, y = (struct zx_a_Address_s*)y->gg.g.n) ;
  return y;
}

/* FUNC(zx_b_ApplicationEPR_POP_Address) */

struct zx_a_Address_s* zx_b_ApplicationEPR_POP_Address(struct zx_b_ApplicationEPR_s* x)
{
  struct zx_a_Address_s* y;
  if (!x) return 0;
  y = x->Address;
  if (y)
    x->Address = (struct zx_a_Address_s*)y->gg.g.n;
  return y;
}

/* FUNC(zx_b_ApplicationEPR_PUSH_Address) */

void zx_b_ApplicationEPR_PUSH_Address(struct zx_b_ApplicationEPR_s* x, struct zx_a_Address_s* z)
{
  if (!x || !z) return;
  z->gg.g.n = &x->Address->gg.g;
  x->Address = z;
}

/* FUNC(zx_b_ApplicationEPR_REV_Address) */

void zx_b_ApplicationEPR_REV_Address(struct zx_b_ApplicationEPR_s* x)
{
  struct zx_a_Address_s* nxt;
  struct zx_a_Address_s* y;
  if (!x) return;
  y = x->Address;
  if (!y) return;
  x->Address = 0;
  while (y) {
    nxt = (struct zx_a_Address_s*)y->gg.g.n;
    y->gg.g.n = &x->Address->gg.g;
    x->Address = y;
    y = nxt;
  }
}

/* FUNC(zx_b_ApplicationEPR_PUT_Address) */

void zx_b_ApplicationEPR_PUT_Address(struct zx_b_ApplicationEPR_s* x, int n, struct zx_a_Address_s* z)
{
  struct zx_a_Address_s* y;
  if (!x || !z) return;
  y = x->Address;
  if (!y) return;
  switch (n) {
  case 0:
    z->gg.g.n = y->gg.g.n;
    x->Address = z;
    return;
  default:
    for (; n > 1 && y->gg.g.n; --n, y = (struct zx_a_Address_s*)y->gg.g.n) ;
    if (!y->gg.g.n) return;
    z->gg.g.n = y->gg.g.n->n;
    y->gg.g.n = &z->gg.g;
  }
}

/* FUNC(zx_b_ApplicationEPR_ADD_Address) */

void zx_b_ApplicationEPR_ADD_Address(struct zx_b_ApplicationEPR_s* x, int n, struct zx_a_Address_s* z)
{
  struct zx_a_Address_s* y;
  if (!x || !z) return;
  switch (n) {
  case 0:
  add_to_start:
    z->gg.g.n = &x->Address->gg.g;
    x->Address = z;
    return;
  case -1:
    y = x->Address;
    if (!y) goto add_to_start;
    for (; y->gg.g.n; y = (struct zx_a_Address_s*)y->gg.g.n) ;
    break;
  default:
    for (y = x->Address; n > 1 && y; --n, y = (struct zx_a_Address_s*)y->gg.g.n) ;
    if (!y) return;
  }
  z->gg.g.n = y->gg.g.n;
  y->gg.g.n = &z->gg.g;
}

/* FUNC(zx_b_ApplicationEPR_DEL_Address) */

void zx_b_ApplicationEPR_DEL_Address(struct zx_b_ApplicationEPR_s* x, int n)
{
  struct zx_a_Address_s* y;
  if (!x) return;
  switch (n) {
  case 0:
    x->Address = (struct zx_a_Address_s*)x->Address->gg.g.n;
    return;
  case -1:
    y = (struct zx_a_Address_s*)x->Address;
    if (!y) return;
    for (; y->gg.g.n; y = (struct zx_a_Address_s*)y->gg.g.n) ;
    break;
  default:
    for (y = x->Address; n > 1 && y->gg.g.n; --n, y = (struct zx_a_Address_s*)y->gg.g.n) ;
    if (!y->gg.g.n) return;
  }
  y->gg.g.n = y->gg.g.n->n;
}

#endif



#ifdef ZX_ENA_GETPUT

/* FUNC(zx_b_ApplicationEPR_NUM_ReferenceParameters) */

int zx_b_ApplicationEPR_NUM_ReferenceParameters(struct zx_b_ApplicationEPR_s* x)
{
  struct zx_a_ReferenceParameters_s* y;
  int n = 0;
  if (!x) return 0;
  for (y = x->ReferenceParameters; y; ++n, y = (struct zx_a_ReferenceParameters_s*)y->gg.g.n) ;
  return n;
}

/* FUNC(zx_b_ApplicationEPR_GET_ReferenceParameters) */

struct zx_a_ReferenceParameters_s* zx_b_ApplicationEPR_GET_ReferenceParameters(struct zx_b_ApplicationEPR_s* x, int n)
{
  struct zx_a_ReferenceParameters_s* y;
  if (!x) return 0;
  for (y = x->ReferenceParameters; n>=0 && y; --n, y = (struct zx_a_ReferenceParameters_s*)y->gg.g.n) ;
  return y;
}

/* FUNC(zx_b_ApplicationEPR_POP_ReferenceParameters) */

struct zx_a_ReferenceParameters_s* zx_b_ApplicationEPR_POP_ReferenceParameters(struct zx_b_ApplicationEPR_s* x)
{
  struct zx_a_ReferenceParameters_s* y;
  if (!x) return 0;
  y = x->ReferenceParameters;
  if (y)
    x->ReferenceParameters = (struct zx_a_ReferenceParameters_s*)y->gg.g.n;
  return y;
}

/* FUNC(zx_b_ApplicationEPR_PUSH_ReferenceParameters) */

void zx_b_ApplicationEPR_PUSH_ReferenceParameters(struct zx_b_ApplicationEPR_s* x, struct zx_a_ReferenceParameters_s* z)
{
  if (!x || !z) return;
  z->gg.g.n = &x->ReferenceParameters->gg.g;
  x->ReferenceParameters = z;
}

/* FUNC(zx_b_ApplicationEPR_REV_ReferenceParameters) */

void zx_b_ApplicationEPR_REV_ReferenceParameters(struct zx_b_ApplicationEPR_s* x)
{
  struct zx_a_ReferenceParameters_s* nxt;
  struct zx_a_ReferenceParameters_s* y;
  if (!x) return;
  y = x->ReferenceParameters;
  if (!y) return;
  x->ReferenceParameters = 0;
  while (y) {
    nxt = (struct zx_a_ReferenceParameters_s*)y->gg.g.n;
    y->gg.g.n = &x->ReferenceParameters->gg.g;
    x->ReferenceParameters = y;
    y = nxt;
  }
}

/* FUNC(zx_b_ApplicationEPR_PUT_ReferenceParameters) */

void zx_b_ApplicationEPR_PUT_ReferenceParameters(struct zx_b_ApplicationEPR_s* x, int n, struct zx_a_ReferenceParameters_s* z)
{
  struct zx_a_ReferenceParameters_s* y;
  if (!x || !z) return;
  y = x->ReferenceParameters;
  if (!y) return;
  switch (n) {
  case 0:
    z->gg.g.n = y->gg.g.n;
    x->ReferenceParameters = z;
    return;
  default:
    for (; n > 1 && y->gg.g.n; --n, y = (struct zx_a_ReferenceParameters_s*)y->gg.g.n) ;
    if (!y->gg.g.n) return;
    z->gg.g.n = y->gg.g.n->n;
    y->gg.g.n = &z->gg.g;
  }
}

/* FUNC(zx_b_ApplicationEPR_ADD_ReferenceParameters) */

void zx_b_ApplicationEPR_ADD_ReferenceParameters(struct zx_b_ApplicationEPR_s* x, int n, struct zx_a_ReferenceParameters_s* z)
{
  struct zx_a_ReferenceParameters_s* y;
  if (!x || !z) return;
  switch (n) {
  case 0:
  add_to_start:
    z->gg.g.n = &x->ReferenceParameters->gg.g;
    x->ReferenceParameters = z;
    return;
  case -1:
    y = x->ReferenceParameters;
    if (!y) goto add_to_start;
    for (; y->gg.g.n; y = (struct zx_a_ReferenceParameters_s*)y->gg.g.n) ;
    break;
  default:
    for (y = x->ReferenceParameters; n > 1 && y; --n, y = (struct zx_a_ReferenceParameters_s*)y->gg.g.n) ;
    if (!y) return;
  }
  z->gg.g.n = y->gg.g.n;
  y->gg.g.n = &z->gg.g;
}

/* FUNC(zx_b_ApplicationEPR_DEL_ReferenceParameters) */

void zx_b_ApplicationEPR_DEL_ReferenceParameters(struct zx_b_ApplicationEPR_s* x, int n)
{
  struct zx_a_ReferenceParameters_s* y;
  if (!x) return;
  switch (n) {
  case 0:
    x->ReferenceParameters = (struct zx_a_ReferenceParameters_s*)x->ReferenceParameters->gg.g.n;
    return;
  case -1:
    y = (struct zx_a_ReferenceParameters_s*)x->ReferenceParameters;
    if (!y) return;
    for (; y->gg.g.n; y = (struct zx_a_ReferenceParameters_s*)y->gg.g.n) ;
    break;
  default:
    for (y = x->ReferenceParameters; n > 1 && y->gg.g.n; --n, y = (struct zx_a_ReferenceParameters_s*)y->gg.g.n) ;
    if (!y->gg.g.n) return;
  }
  y->gg.g.n = y->gg.g.n->n;
}

#endif



#ifdef ZX_ENA_GETPUT

/* FUNC(zx_b_ApplicationEPR_NUM_Metadata) */

int zx_b_ApplicationEPR_NUM_Metadata(struct zx_b_ApplicationEPR_s* x)
{
  struct zx_a_Metadata_s* y;
  int n = 0;
  if (!x) return 0;
  for (y = x->Metadata; y; ++n, y = (struct zx_a_Metadata_s*)y->gg.g.n) ;
  return n;
}

/* FUNC(zx_b_ApplicationEPR_GET_Metadata) */

struct zx_a_Metadata_s* zx_b_ApplicationEPR_GET_Metadata(struct zx_b_ApplicationEPR_s* x, int n)
{
  struct zx_a_Metadata_s* y;
  if (!x) return 0;
  for (y = x->Metadata; n>=0 && y; --n, y = (struct zx_a_Metadata_s*)y->gg.g.n) ;
  return y;
}

/* FUNC(zx_b_ApplicationEPR_POP_Metadata) */

struct zx_a_Metadata_s* zx_b_ApplicationEPR_POP_Metadata(struct zx_b_ApplicationEPR_s* x)
{
  struct zx_a_Metadata_s* y;
  if (!x) return 0;
  y = x->Metadata;
  if (y)
    x->Metadata = (struct zx_a_Metadata_s*)y->gg.g.n;
  return y;
}

/* FUNC(zx_b_ApplicationEPR_PUSH_Metadata) */

void zx_b_ApplicationEPR_PUSH_Metadata(struct zx_b_ApplicationEPR_s* x, struct zx_a_Metadata_s* z)
{
  if (!x || !z) return;
  z->gg.g.n = &x->Metadata->gg.g;
  x->Metadata = z;
}

/* FUNC(zx_b_ApplicationEPR_REV_Metadata) */

void zx_b_ApplicationEPR_REV_Metadata(struct zx_b_ApplicationEPR_s* x)
{
  struct zx_a_Metadata_s* nxt;
  struct zx_a_Metadata_s* y;
  if (!x) return;
  y = x->Metadata;
  if (!y) return;
  x->Metadata = 0;
  while (y) {
    nxt = (struct zx_a_Metadata_s*)y->gg.g.n;
    y->gg.g.n = &x->Metadata->gg.g;
    x->Metadata = y;
    y = nxt;
  }
}

/* FUNC(zx_b_ApplicationEPR_PUT_Metadata) */

void zx_b_ApplicationEPR_PUT_Metadata(struct zx_b_ApplicationEPR_s* x, int n, struct zx_a_Metadata_s* z)
{
  struct zx_a_Metadata_s* y;
  if (!x || !z) return;
  y = x->Metadata;
  if (!y) return;
  switch (n) {
  case 0:
    z->gg.g.n = y->gg.g.n;
    x->Metadata = z;
    return;
  default:
    for (; n > 1 && y->gg.g.n; --n, y = (struct zx_a_Metadata_s*)y->gg.g.n) ;
    if (!y->gg.g.n) return;
    z->gg.g.n = y->gg.g.n->n;
    y->gg.g.n = &z->gg.g;
  }
}

/* FUNC(zx_b_ApplicationEPR_ADD_Metadata) */

void zx_b_ApplicationEPR_ADD_Metadata(struct zx_b_ApplicationEPR_s* x, int n, struct zx_a_Metadata_s* z)
{
  struct zx_a_Metadata_s* y;
  if (!x || !z) return;
  switch (n) {
  case 0:
  add_to_start:
    z->gg.g.n = &x->Metadata->gg.g;
    x->Metadata = z;
    return;
  case -1:
    y = x->Metadata;
    if (!y) goto add_to_start;
    for (; y->gg.g.n; y = (struct zx_a_Metadata_s*)y->gg.g.n) ;
    break;
  default:
    for (y = x->Metadata; n > 1 && y; --n, y = (struct zx_a_Metadata_s*)y->gg.g.n) ;
    if (!y) return;
  }
  z->gg.g.n = y->gg.g.n;
  y->gg.g.n = &z->gg.g;
}

/* FUNC(zx_b_ApplicationEPR_DEL_Metadata) */

void zx_b_ApplicationEPR_DEL_Metadata(struct zx_b_ApplicationEPR_s* x, int n)
{
  struct zx_a_Metadata_s* y;
  if (!x) return;
  switch (n) {
  case 0:
    x->Metadata = (struct zx_a_Metadata_s*)x->Metadata->gg.g.n;
    return;
  case -1:
    y = (struct zx_a_Metadata_s*)x->Metadata;
    if (!y) return;
    for (; y->gg.g.n; y = (struct zx_a_Metadata_s*)y->gg.g.n) ;
    break;
  default:
    for (y = x->Metadata; n > 1 && y->gg.g.n; --n, y = (struct zx_a_Metadata_s*)y->gg.g.n) ;
    if (!y->gg.g.n) return;
  }
  y->gg.g.n = y->gg.g.n->n;
}

#endif

/* FUNC(zx_b_ApplicationEPR_GET_ID) */
struct zx_str* zx_b_ApplicationEPR_GET_ID(struct zx_b_ApplicationEPR_s* x) { return x->ID; }
/* FUNC(zx_b_ApplicationEPR_PUT_ID) */
void zx_b_ApplicationEPR_PUT_ID(struct zx_b_ApplicationEPR_s* x, struct zx_str* y) { x->ID = y; }
/* FUNC(zx_b_ApplicationEPR_GET_id) */
struct zx_str* zx_b_ApplicationEPR_GET_id(struct zx_b_ApplicationEPR_s* x) { return x->id; }
/* FUNC(zx_b_ApplicationEPR_PUT_id) */
void zx_b_ApplicationEPR_PUT_id(struct zx_b_ApplicationEPR_s* x, struct zx_str* y) { x->id = y; }
/* FUNC(zx_b_ApplicationEPR_GET_notOnOrAfter) */
struct zx_str* zx_b_ApplicationEPR_GET_notOnOrAfter(struct zx_b_ApplicationEPR_s* x) { return x->notOnOrAfter; }
/* FUNC(zx_b_ApplicationEPR_PUT_notOnOrAfter) */
void zx_b_ApplicationEPR_PUT_notOnOrAfter(struct zx_b_ApplicationEPR_s* x, struct zx_str* y) { x->notOnOrAfter = y; }
/* FUNC(zx_b_ApplicationEPR_GET_Id) */
struct zx_str* zx_b_ApplicationEPR_GET_Id(struct zx_b_ApplicationEPR_s* x) { return x->Id; }
/* FUNC(zx_b_ApplicationEPR_PUT_Id) */
void zx_b_ApplicationEPR_PUT_Id(struct zx_b_ApplicationEPR_s* x, struct zx_str* y) { x->Id = y; }
/* FUNC(zx_b_ApplicationEPR_GET_actor) */
struct zx_str* zx_b_ApplicationEPR_GET_actor(struct zx_b_ApplicationEPR_s* x) { return x->actor; }
/* FUNC(zx_b_ApplicationEPR_PUT_actor) */
void zx_b_ApplicationEPR_PUT_actor(struct zx_b_ApplicationEPR_s* x, struct zx_str* y) { x->actor = y; }
/* FUNC(zx_b_ApplicationEPR_GET_mustUnderstand) */
struct zx_str* zx_b_ApplicationEPR_GET_mustUnderstand(struct zx_b_ApplicationEPR_s* x) { return x->mustUnderstand; }
/* FUNC(zx_b_ApplicationEPR_PUT_mustUnderstand) */
void zx_b_ApplicationEPR_PUT_mustUnderstand(struct zx_b_ApplicationEPR_s* x, struct zx_str* y) { x->mustUnderstand = y; }





/* FUNC(zx_b_Consent_GET_id) */
struct zx_str* zx_b_Consent_GET_id(struct zx_b_Consent_s* x) { return x->id; }
/* FUNC(zx_b_Consent_PUT_id) */
void zx_b_Consent_PUT_id(struct zx_b_Consent_s* x, struct zx_str* y) { x->id = y; }
/* FUNC(zx_b_Consent_GET_timestamp) */
struct zx_str* zx_b_Consent_GET_timestamp(struct zx_b_Consent_s* x) { return x->timestamp; }
/* FUNC(zx_b_Consent_PUT_timestamp) */
void zx_b_Consent_PUT_timestamp(struct zx_b_Consent_s* x, struct zx_str* y) { x->timestamp = y; }
/* FUNC(zx_b_Consent_GET_uri) */
struct zx_str* zx_b_Consent_GET_uri(struct zx_b_Consent_s* x) { return x->uri; }
/* FUNC(zx_b_Consent_PUT_uri) */
void zx_b_Consent_PUT_uri(struct zx_b_Consent_s* x, struct zx_str* y) { x->uri = y; }
/* FUNC(zx_b_Consent_GET_Id) */
struct zx_str* zx_b_Consent_GET_Id(struct zx_b_Consent_s* x) { return x->Id; }
/* FUNC(zx_b_Consent_PUT_Id) */
void zx_b_Consent_PUT_Id(struct zx_b_Consent_s* x, struct zx_str* y) { x->Id = y; }
/* FUNC(zx_b_Consent_GET_actor) */
struct zx_str* zx_b_Consent_GET_actor(struct zx_b_Consent_s* x) { return x->actor; }
/* FUNC(zx_b_Consent_PUT_actor) */
void zx_b_Consent_PUT_actor(struct zx_b_Consent_s* x, struct zx_str* y) { x->actor = y; }
/* FUNC(zx_b_Consent_GET_mustUnderstand) */
struct zx_str* zx_b_Consent_GET_mustUnderstand(struct zx_b_Consent_s* x) { return x->mustUnderstand; }
/* FUNC(zx_b_Consent_PUT_mustUnderstand) */
void zx_b_Consent_PUT_mustUnderstand(struct zx_b_Consent_s* x, struct zx_str* y) { x->mustUnderstand = y; }







#ifdef ZX_ENA_GETPUT

/* FUNC(zx_b_CredentialsContext_NUM_RequestedAuthnContext) */

int zx_b_CredentialsContext_NUM_RequestedAuthnContext(struct zx_b_CredentialsContext_s* x)
{
  struct zx_sp_RequestedAuthnContext_s* y;
  int n = 0;
  if (!x) return 0;
  for (y = x->RequestedAuthnContext; y; ++n, y = (struct zx_sp_RequestedAuthnContext_s*)y->gg.g.n) ;
  return n;
}

/* FUNC(zx_b_CredentialsContext_GET_RequestedAuthnContext) */

struct zx_sp_RequestedAuthnContext_s* zx_b_CredentialsContext_GET_RequestedAuthnContext(struct zx_b_CredentialsContext_s* x, int n)
{
  struct zx_sp_RequestedAuthnContext_s* y;
  if (!x) return 0;
  for (y = x->RequestedAuthnContext; n>=0 && y; --n, y = (struct zx_sp_RequestedAuthnContext_s*)y->gg.g.n) ;
  return y;
}

/* FUNC(zx_b_CredentialsContext_POP_RequestedAuthnContext) */

struct zx_sp_RequestedAuthnContext_s* zx_b_CredentialsContext_POP_RequestedAuthnContext(struct zx_b_CredentialsContext_s* x)
{
  struct zx_sp_RequestedAuthnContext_s* y;
  if (!x) return 0;
  y = x->RequestedAuthnContext;
  if (y)
    x->RequestedAuthnContext = (struct zx_sp_RequestedAuthnContext_s*)y->gg.g.n;
  return y;
}

/* FUNC(zx_b_CredentialsContext_PUSH_RequestedAuthnContext) */

void zx_b_CredentialsContext_PUSH_RequestedAuthnContext(struct zx_b_CredentialsContext_s* x, struct zx_sp_RequestedAuthnContext_s* z)
{
  if (!x || !z) return;
  z->gg.g.n = &x->RequestedAuthnContext->gg.g;
  x->RequestedAuthnContext = z;
}

/* FUNC(zx_b_CredentialsContext_REV_RequestedAuthnContext) */

void zx_b_CredentialsContext_REV_RequestedAuthnContext(struct zx_b_CredentialsContext_s* x)
{
  struct zx_sp_RequestedAuthnContext_s* nxt;
  struct zx_sp_RequestedAuthnContext_s* y;
  if (!x) return;
  y = x->RequestedAuthnContext;
  if (!y) return;
  x->RequestedAuthnContext = 0;
  while (y) {
    nxt = (struct zx_sp_RequestedAuthnContext_s*)y->gg.g.n;
    y->gg.g.n = &x->RequestedAuthnContext->gg.g;
    x->RequestedAuthnContext = y;
    y = nxt;
  }
}

/* FUNC(zx_b_CredentialsContext_PUT_RequestedAuthnContext) */

void zx_b_CredentialsContext_PUT_RequestedAuthnContext(struct zx_b_CredentialsContext_s* x, int n, struct zx_sp_RequestedAuthnContext_s* z)
{
  struct zx_sp_RequestedAuthnContext_s* y;
  if (!x || !z) return;
  y = x->RequestedAuthnContext;
  if (!y) return;
  switch (n) {
  case 0:
    z->gg.g.n = y->gg.g.n;
    x->RequestedAuthnContext = z;
    return;
  default:
    for (; n > 1 && y->gg.g.n; --n, y = (struct zx_sp_RequestedAuthnContext_s*)y->gg.g.n) ;
    if (!y->gg.g.n) return;
    z->gg.g.n = y->gg.g.n->n;
    y->gg.g.n = &z->gg.g;
  }
}

/* FUNC(zx_b_CredentialsContext_ADD_RequestedAuthnContext) */

void zx_b_CredentialsContext_ADD_RequestedAuthnContext(struct zx_b_CredentialsContext_s* x, int n, struct zx_sp_RequestedAuthnContext_s* z)
{
  struct zx_sp_RequestedAuthnContext_s* y;
  if (!x || !z) return;
  switch (n) {
  case 0:
  add_to_start:
    z->gg.g.n = &x->RequestedAuthnContext->gg.g;
    x->RequestedAuthnContext = z;
    return;
  case -1:
    y = x->RequestedAuthnContext;
    if (!y) goto add_to_start;
    for (; y->gg.g.n; y = (struct zx_sp_RequestedAuthnContext_s*)y->gg.g.n) ;
    break;
  default:
    for (y = x->RequestedAuthnContext; n > 1 && y; --n, y = (struct zx_sp_RequestedAuthnContext_s*)y->gg.g.n) ;
    if (!y) return;
  }
  z->gg.g.n = y->gg.g.n;
  y->gg.g.n = &z->gg.g;
}

/* FUNC(zx_b_CredentialsContext_DEL_RequestedAuthnContext) */

void zx_b_CredentialsContext_DEL_RequestedAuthnContext(struct zx_b_CredentialsContext_s* x, int n)
{
  struct zx_sp_RequestedAuthnContext_s* y;
  if (!x) return;
  switch (n) {
  case 0:
    x->RequestedAuthnContext = (struct zx_sp_RequestedAuthnContext_s*)x->RequestedAuthnContext->gg.g.n;
    return;
  case -1:
    y = (struct zx_sp_RequestedAuthnContext_s*)x->RequestedAuthnContext;
    if (!y) return;
    for (; y->gg.g.n; y = (struct zx_sp_RequestedAuthnContext_s*)y->gg.g.n) ;
    break;
  default:
    for (y = x->RequestedAuthnContext; n > 1 && y->gg.g.n; --n, y = (struct zx_sp_RequestedAuthnContext_s*)y->gg.g.n) ;
    if (!y->gg.g.n) return;
  }
  y->gg.g.n = y->gg.g.n->n;
}

#endif



#ifdef ZX_ENA_GETPUT

/* FUNC(zx_b_CredentialsContext_NUM_SecurityMechID) */

int zx_b_CredentialsContext_NUM_SecurityMechID(struct zx_b_CredentialsContext_s* x)
{
  struct zx_elem_s* y;
  int n = 0;
  if (!x) return 0;
  for (y = x->SecurityMechID; y; ++n, y = (struct zx_elem_s*)y->g.n) ;
  return n;
}

/* FUNC(zx_b_CredentialsContext_GET_SecurityMechID) */

struct zx_elem_s* zx_b_CredentialsContext_GET_SecurityMechID(struct zx_b_CredentialsContext_s* x, int n)
{
  struct zx_elem_s* y;
  if (!x) return 0;
  for (y = x->SecurityMechID; n>=0 && y; --n, y = (struct zx_elem_s*)y->g.n) ;
  return y;
}

/* FUNC(zx_b_CredentialsContext_POP_SecurityMechID) */

struct zx_elem_s* zx_b_CredentialsContext_POP_SecurityMechID(struct zx_b_CredentialsContext_s* x)
{
  struct zx_elem_s* y;
  if (!x) return 0;
  y = x->SecurityMechID;
  if (y)
    x->SecurityMechID = (struct zx_elem_s*)y->g.n;
  return y;
}

/* FUNC(zx_b_CredentialsContext_PUSH_SecurityMechID) */

void zx_b_CredentialsContext_PUSH_SecurityMechID(struct zx_b_CredentialsContext_s* x, struct zx_elem_s* z)
{
  if (!x || !z) return;
  z->g.n = &x->SecurityMechID->g;
  x->SecurityMechID = z;
}

/* FUNC(zx_b_CredentialsContext_REV_SecurityMechID) */

void zx_b_CredentialsContext_REV_SecurityMechID(struct zx_b_CredentialsContext_s* x)
{
  struct zx_elem_s* nxt;
  struct zx_elem_s* y;
  if (!x) return;
  y = x->SecurityMechID;
  if (!y) return;
  x->SecurityMechID = 0;
  while (y) {
    nxt = (struct zx_elem_s*)y->g.n;
    y->g.n = &x->SecurityMechID->g;
    x->SecurityMechID = y;
    y = nxt;
  }
}

/* FUNC(zx_b_CredentialsContext_PUT_SecurityMechID) */

void zx_b_CredentialsContext_PUT_SecurityMechID(struct zx_b_CredentialsContext_s* x, int n, struct zx_elem_s* z)
{
  struct zx_elem_s* y;
  if (!x || !z) return;
  y = x->SecurityMechID;
  if (!y) return;
  switch (n) {
  case 0:
    z->g.n = y->g.n;
    x->SecurityMechID = z;
    return;
  default:
    for (; n > 1 && y->g.n; --n, y = (struct zx_elem_s*)y->g.n) ;
    if (!y->g.n) return;
    z->g.n = y->g.n->n;
    y->g.n = &z->g;
  }
}

/* FUNC(zx_b_CredentialsContext_ADD_SecurityMechID) */

void zx_b_CredentialsContext_ADD_SecurityMechID(struct zx_b_CredentialsContext_s* x, int n, struct zx_elem_s* z)
{
  struct zx_elem_s* y;
  if (!x || !z) return;
  switch (n) {
  case 0:
  add_to_start:
    z->g.n = &x->SecurityMechID->g;
    x->SecurityMechID = z;
    return;
  case -1:
    y = x->SecurityMechID;
    if (!y) goto add_to_start;
    for (; y->g.n; y = (struct zx_elem_s*)y->g.n) ;
    break;
  default:
    for (y = x->SecurityMechID; n > 1 && y; --n, y = (struct zx_elem_s*)y->g.n) ;
    if (!y) return;
  }
  z->g.n = y->g.n;
  y->g.n = &z->g;
}

/* FUNC(zx_b_CredentialsContext_DEL_SecurityMechID) */

void zx_b_CredentialsContext_DEL_SecurityMechID(struct zx_b_CredentialsContext_s* x, int n)
{
  struct zx_elem_s* y;
  if (!x) return;
  switch (n) {
  case 0:
    x->SecurityMechID = (struct zx_elem_s*)x->SecurityMechID->g.n;
    return;
  case -1:
    y = (struct zx_elem_s*)x->SecurityMechID;
    if (!y) return;
    for (; y->g.n; y = (struct zx_elem_s*)y->g.n) ;
    break;
  default:
    for (y = x->SecurityMechID; n > 1 && y->g.n; --n, y = (struct zx_elem_s*)y->g.n) ;
    if (!y->g.n) return;
  }
  y->g.n = y->g.n->n;
}

#endif

/* FUNC(zx_b_CredentialsContext_GET_id) */
struct zx_str* zx_b_CredentialsContext_GET_id(struct zx_b_CredentialsContext_s* x) { return x->id; }
/* FUNC(zx_b_CredentialsContext_PUT_id) */
void zx_b_CredentialsContext_PUT_id(struct zx_b_CredentialsContext_s* x, struct zx_str* y) { x->id = y; }
/* FUNC(zx_b_CredentialsContext_GET_Id) */
struct zx_str* zx_b_CredentialsContext_GET_Id(struct zx_b_CredentialsContext_s* x) { return x->Id; }
/* FUNC(zx_b_CredentialsContext_PUT_Id) */
void zx_b_CredentialsContext_PUT_Id(struct zx_b_CredentialsContext_s* x, struct zx_str* y) { x->Id = y; }
/* FUNC(zx_b_CredentialsContext_GET_actor) */
struct zx_str* zx_b_CredentialsContext_GET_actor(struct zx_b_CredentialsContext_s* x) { return x->actor; }
/* FUNC(zx_b_CredentialsContext_PUT_actor) */
void zx_b_CredentialsContext_PUT_actor(struct zx_b_CredentialsContext_s* x, struct zx_str* y) { x->actor = y; }
/* FUNC(zx_b_CredentialsContext_GET_mustUnderstand) */
struct zx_str* zx_b_CredentialsContext_GET_mustUnderstand(struct zx_b_CredentialsContext_s* x) { return x->mustUnderstand; }
/* FUNC(zx_b_CredentialsContext_PUT_mustUnderstand) */
void zx_b_CredentialsContext_PUT_mustUnderstand(struct zx_b_CredentialsContext_s* x, struct zx_str* y) { x->mustUnderstand = y; }







#ifdef ZX_ENA_GETPUT

/* FUNC(zx_b_EndpointUpdate_NUM_Address) */

int zx_b_EndpointUpdate_NUM_Address(struct zx_b_EndpointUpdate_s* x)
{
  struct zx_a_Address_s* y;
  int n = 0;
  if (!x) return 0;
  for (y = x->Address; y; ++n, y = (struct zx_a_Address_s*)y->gg.g.n) ;
  return n;
}

/* FUNC(zx_b_EndpointUpdate_GET_Address) */

struct zx_a_Address_s* zx_b_EndpointUpdate_GET_Address(struct zx_b_EndpointUpdate_s* x, int n)
{
  struct zx_a_Address_s* y;
  if (!x) return 0;
  for (y = x->Address; n>=0 && y; --n, y = (struct zx_a_Address_s*)y->gg.g.n) ;
  return y;
}

/* FUNC(zx_b_EndpointUpdate_POP_Address) */

struct zx_a_Address_s* zx_b_EndpointUpdate_POP_Address(struct zx_b_EndpointUpdate_s* x)
{
  struct zx_a_Address_s* y;
  if (!x) return 0;
  y = x->Address;
  if (y)
    x->Address = (struct zx_a_Address_s*)y->gg.g.n;
  return y;
}

/* FUNC(zx_b_EndpointUpdate_PUSH_Address) */

void zx_b_EndpointUpdate_PUSH_Address(struct zx_b_EndpointUpdate_s* x, struct zx_a_Address_s* z)
{
  if (!x || !z) return;
  z->gg.g.n = &x->Address->gg.g;
  x->Address = z;
}

/* FUNC(zx_b_EndpointUpdate_REV_Address) */

void zx_b_EndpointUpdate_REV_Address(struct zx_b_EndpointUpdate_s* x)
{
  struct zx_a_Address_s* nxt;
  struct zx_a_Address_s* y;
  if (!x) return;
  y = x->Address;
  if (!y) return;
  x->Address = 0;
  while (y) {
    nxt = (struct zx_a_Address_s*)y->gg.g.n;
    y->gg.g.n = &x->Address->gg.g;
    x->Address = y;
    y = nxt;
  }
}

/* FUNC(zx_b_EndpointUpdate_PUT_Address) */

void zx_b_EndpointUpdate_PUT_Address(struct zx_b_EndpointUpdate_s* x, int n, struct zx_a_Address_s* z)
{
  struct zx_a_Address_s* y;
  if (!x || !z) return;
  y = x->Address;
  if (!y) return;
  switch (n) {
  case 0:
    z->gg.g.n = y->gg.g.n;
    x->Address = z;
    return;
  default:
    for (; n > 1 && y->gg.g.n; --n, y = (struct zx_a_Address_s*)y->gg.g.n) ;
    if (!y->gg.g.n) return;
    z->gg.g.n = y->gg.g.n->n;
    y->gg.g.n = &z->gg.g;
  }
}

/* FUNC(zx_b_EndpointUpdate_ADD_Address) */

void zx_b_EndpointUpdate_ADD_Address(struct zx_b_EndpointUpdate_s* x, int n, struct zx_a_Address_s* z)
{
  struct zx_a_Address_s* y;
  if (!x || !z) return;
  switch (n) {
  case 0:
  add_to_start:
    z->gg.g.n = &x->Address->gg.g;
    x->Address = z;
    return;
  case -1:
    y = x->Address;
    if (!y) goto add_to_start;
    for (; y->gg.g.n; y = (struct zx_a_Address_s*)y->gg.g.n) ;
    break;
  default:
    for (y = x->Address; n > 1 && y; --n, y = (struct zx_a_Address_s*)y->gg.g.n) ;
    if (!y) return;
  }
  z->gg.g.n = y->gg.g.n;
  y->gg.g.n = &z->gg.g;
}

/* FUNC(zx_b_EndpointUpdate_DEL_Address) */

void zx_b_EndpointUpdate_DEL_Address(struct zx_b_EndpointUpdate_s* x, int n)
{
  struct zx_a_Address_s* y;
  if (!x) return;
  switch (n) {
  case 0:
    x->Address = (struct zx_a_Address_s*)x->Address->gg.g.n;
    return;
  case -1:
    y = (struct zx_a_Address_s*)x->Address;
    if (!y) return;
    for (; y->gg.g.n; y = (struct zx_a_Address_s*)y->gg.g.n) ;
    break;
  default:
    for (y = x->Address; n > 1 && y->gg.g.n; --n, y = (struct zx_a_Address_s*)y->gg.g.n) ;
    if (!y->gg.g.n) return;
  }
  y->gg.g.n = y->gg.g.n->n;
}

#endif



#ifdef ZX_ENA_GETPUT

/* FUNC(zx_b_EndpointUpdate_NUM_ReferenceParameters) */

int zx_b_EndpointUpdate_NUM_ReferenceParameters(struct zx_b_EndpointUpdate_s* x)
{
  struct zx_a_ReferenceParameters_s* y;
  int n = 0;
  if (!x) return 0;
  for (y = x->ReferenceParameters; y; ++n, y = (struct zx_a_ReferenceParameters_s*)y->gg.g.n) ;
  return n;
}

/* FUNC(zx_b_EndpointUpdate_GET_ReferenceParameters) */

struct zx_a_ReferenceParameters_s* zx_b_EndpointUpdate_GET_ReferenceParameters(struct zx_b_EndpointUpdate_s* x, int n)
{
  struct zx_a_ReferenceParameters_s* y;
  if (!x) return 0;
  for (y = x->ReferenceParameters; n>=0 && y; --n, y = (struct zx_a_ReferenceParameters_s*)y->gg.g.n) ;
  return y;
}

/* FUNC(zx_b_EndpointUpdate_POP_ReferenceParameters) */

struct zx_a_ReferenceParameters_s* zx_b_EndpointUpdate_POP_ReferenceParameters(struct zx_b_EndpointUpdate_s* x)
{
  struct zx_a_ReferenceParameters_s* y;
  if (!x) return 0;
  y = x->ReferenceParameters;
  if (y)
    x->ReferenceParameters = (struct zx_a_ReferenceParameters_s*)y->gg.g.n;
  return y;
}

/* FUNC(zx_b_EndpointUpdate_PUSH_ReferenceParameters) */

void zx_b_EndpointUpdate_PUSH_ReferenceParameters(struct zx_b_EndpointUpdate_s* x, struct zx_a_ReferenceParameters_s* z)
{
  if (!x || !z) return;
  z->gg.g.n = &x->ReferenceParameters->gg.g;
  x->ReferenceParameters = z;
}

/* FUNC(zx_b_EndpointUpdate_REV_ReferenceParameters) */

void zx_b_EndpointUpdate_REV_ReferenceParameters(struct zx_b_EndpointUpdate_s* x)
{
  struct zx_a_ReferenceParameters_s* nxt;
  struct zx_a_ReferenceParameters_s* y;
  if (!x) return;
  y = x->ReferenceParameters;
  if (!y) return;
  x->ReferenceParameters = 0;
  while (y) {
    nxt = (struct zx_a_ReferenceParameters_s*)y->gg.g.n;
    y->gg.g.n = &x->ReferenceParameters->gg.g;
    x->ReferenceParameters = y;
    y = nxt;
  }
}

/* FUNC(zx_b_EndpointUpdate_PUT_ReferenceParameters) */

void zx_b_EndpointUpdate_PUT_ReferenceParameters(struct zx_b_EndpointUpdate_s* x, int n, struct zx_a_ReferenceParameters_s* z)
{
  struct zx_a_ReferenceParameters_s* y;
  if (!x || !z) return;
  y = x->ReferenceParameters;
  if (!y) return;
  switch (n) {
  case 0:
    z->gg.g.n = y->gg.g.n;
    x->ReferenceParameters = z;
    return;
  default:
    for (; n > 1 && y->gg.g.n; --n, y = (struct zx_a_ReferenceParameters_s*)y->gg.g.n) ;
    if (!y->gg.g.n) return;
    z->gg.g.n = y->gg.g.n->n;
    y->gg.g.n = &z->gg.g;
  }
}

/* FUNC(zx_b_EndpointUpdate_ADD_ReferenceParameters) */

void zx_b_EndpointUpdate_ADD_ReferenceParameters(struct zx_b_EndpointUpdate_s* x, int n, struct zx_a_ReferenceParameters_s* z)
{
  struct zx_a_ReferenceParameters_s* y;
  if (!x || !z) return;
  switch (n) {
  case 0:
  add_to_start:
    z->gg.g.n = &x->ReferenceParameters->gg.g;
    x->ReferenceParameters = z;
    return;
  case -1:
    y = x->ReferenceParameters;
    if (!y) goto add_to_start;
    for (; y->gg.g.n; y = (struct zx_a_ReferenceParameters_s*)y->gg.g.n) ;
    break;
  default:
    for (y = x->ReferenceParameters; n > 1 && y; --n, y = (struct zx_a_ReferenceParameters_s*)y->gg.g.n) ;
    if (!y) return;
  }
  z->gg.g.n = y->gg.g.n;
  y->gg.g.n = &z->gg.g;
}

/* FUNC(zx_b_EndpointUpdate_DEL_ReferenceParameters) */

void zx_b_EndpointUpdate_DEL_ReferenceParameters(struct zx_b_EndpointUpdate_s* x, int n)
{
  struct zx_a_ReferenceParameters_s* y;
  if (!x) return;
  switch (n) {
  case 0:
    x->ReferenceParameters = (struct zx_a_ReferenceParameters_s*)x->ReferenceParameters->gg.g.n;
    return;
  case -1:
    y = (struct zx_a_ReferenceParameters_s*)x->ReferenceParameters;
    if (!y) return;
    for (; y->gg.g.n; y = (struct zx_a_ReferenceParameters_s*)y->gg.g.n) ;
    break;
  default:
    for (y = x->ReferenceParameters; n > 1 && y->gg.g.n; --n, y = (struct zx_a_ReferenceParameters_s*)y->gg.g.n) ;
    if (!y->gg.g.n) return;
  }
  y->gg.g.n = y->gg.g.n->n;
}

#endif



#ifdef ZX_ENA_GETPUT

/* FUNC(zx_b_EndpointUpdate_NUM_Metadata) */

int zx_b_EndpointUpdate_NUM_Metadata(struct zx_b_EndpointUpdate_s* x)
{
  struct zx_a_Metadata_s* y;
  int n = 0;
  if (!x) return 0;
  for (y = x->Metadata; y; ++n, y = (struct zx_a_Metadata_s*)y->gg.g.n) ;
  return n;
}

/* FUNC(zx_b_EndpointUpdate_GET_Metadata) */

struct zx_a_Metadata_s* zx_b_EndpointUpdate_GET_Metadata(struct zx_b_EndpointUpdate_s* x, int n)
{
  struct zx_a_Metadata_s* y;
  if (!x) return 0;
  for (y = x->Metadata; n>=0 && y; --n, y = (struct zx_a_Metadata_s*)y->gg.g.n) ;
  return y;
}

/* FUNC(zx_b_EndpointUpdate_POP_Metadata) */

struct zx_a_Metadata_s* zx_b_EndpointUpdate_POP_Metadata(struct zx_b_EndpointUpdate_s* x)
{
  struct zx_a_Metadata_s* y;
  if (!x) return 0;
  y = x->Metadata;
  if (y)
    x->Metadata = (struct zx_a_Metadata_s*)y->gg.g.n;
  return y;
}

/* FUNC(zx_b_EndpointUpdate_PUSH_Metadata) */

void zx_b_EndpointUpdate_PUSH_Metadata(struct zx_b_EndpointUpdate_s* x, struct zx_a_Metadata_s* z)
{
  if (!x || !z) return;
  z->gg.g.n = &x->Metadata->gg.g;
  x->Metadata = z;
}

/* FUNC(zx_b_EndpointUpdate_REV_Metadata) */

void zx_b_EndpointUpdate_REV_Metadata(struct zx_b_EndpointUpdate_s* x)
{
  struct zx_a_Metadata_s* nxt;
  struct zx_a_Metadata_s* y;
  if (!x) return;
  y = x->Metadata;
  if (!y) return;
  x->Metadata = 0;
  while (y) {
    nxt = (struct zx_a_Metadata_s*)y->gg.g.n;
    y->gg.g.n = &x->Metadata->gg.g;
    x->Metadata = y;
    y = nxt;
  }
}

/* FUNC(zx_b_EndpointUpdate_PUT_Metadata) */

void zx_b_EndpointUpdate_PUT_Metadata(struct zx_b_EndpointUpdate_s* x, int n, struct zx_a_Metadata_s* z)
{
  struct zx_a_Metadata_s* y;
  if (!x || !z) return;
  y = x->Metadata;
  if (!y) return;
  switch (n) {
  case 0:
    z->gg.g.n = y->gg.g.n;
    x->Metadata = z;
    return;
  default:
    for (; n > 1 && y->gg.g.n; --n, y = (struct zx_a_Metadata_s*)y->gg.g.n) ;
    if (!y->gg.g.n) return;
    z->gg.g.n = y->gg.g.n->n;
    y->gg.g.n = &z->gg.g;
  }
}

/* FUNC(zx_b_EndpointUpdate_ADD_Metadata) */

void zx_b_EndpointUpdate_ADD_Metadata(struct zx_b_EndpointUpdate_s* x, int n, struct zx_a_Metadata_s* z)
{
  struct zx_a_Metadata_s* y;
  if (!x || !z) return;
  switch (n) {
  case 0:
  add_to_start:
    z->gg.g.n = &x->Metadata->gg.g;
    x->Metadata = z;
    return;
  case -1:
    y = x->Metadata;
    if (!y) goto add_to_start;
    for (; y->gg.g.n; y = (struct zx_a_Metadata_s*)y->gg.g.n) ;
    break;
  default:
    for (y = x->Metadata; n > 1 && y; --n, y = (struct zx_a_Metadata_s*)y->gg.g.n) ;
    if (!y) return;
  }
  z->gg.g.n = y->gg.g.n;
  y->gg.g.n = &z->gg.g;
}

/* FUNC(zx_b_EndpointUpdate_DEL_Metadata) */

void zx_b_EndpointUpdate_DEL_Metadata(struct zx_b_EndpointUpdate_s* x, int n)
{
  struct zx_a_Metadata_s* y;
  if (!x) return;
  switch (n) {
  case 0:
    x->Metadata = (struct zx_a_Metadata_s*)x->Metadata->gg.g.n;
    return;
  case -1:
    y = (struct zx_a_Metadata_s*)x->Metadata;
    if (!y) return;
    for (; y->gg.g.n; y = (struct zx_a_Metadata_s*)y->gg.g.n) ;
    break;
  default:
    for (y = x->Metadata; n > 1 && y->gg.g.n; --n, y = (struct zx_a_Metadata_s*)y->gg.g.n) ;
    if (!y->gg.g.n) return;
  }
  y->gg.g.n = y->gg.g.n->n;
}

#endif

/* FUNC(zx_b_EndpointUpdate_GET_ID) */
struct zx_str* zx_b_EndpointUpdate_GET_ID(struct zx_b_EndpointUpdate_s* x) { return x->ID; }
/* FUNC(zx_b_EndpointUpdate_PUT_ID) */
void zx_b_EndpointUpdate_PUT_ID(struct zx_b_EndpointUpdate_s* x, struct zx_str* y) { x->ID = y; }
/* FUNC(zx_b_EndpointUpdate_GET_id) */
struct zx_str* zx_b_EndpointUpdate_GET_id(struct zx_b_EndpointUpdate_s* x) { return x->id; }
/* FUNC(zx_b_EndpointUpdate_PUT_id) */
void zx_b_EndpointUpdate_PUT_id(struct zx_b_EndpointUpdate_s* x, struct zx_str* y) { x->id = y; }
/* FUNC(zx_b_EndpointUpdate_GET_notOnOrAfter) */
struct zx_str* zx_b_EndpointUpdate_GET_notOnOrAfter(struct zx_b_EndpointUpdate_s* x) { return x->notOnOrAfter; }
/* FUNC(zx_b_EndpointUpdate_PUT_notOnOrAfter) */
void zx_b_EndpointUpdate_PUT_notOnOrAfter(struct zx_b_EndpointUpdate_s* x, struct zx_str* y) { x->notOnOrAfter = y; }
/* FUNC(zx_b_EndpointUpdate_GET_updateType) */
struct zx_str* zx_b_EndpointUpdate_GET_updateType(struct zx_b_EndpointUpdate_s* x) { return x->updateType; }
/* FUNC(zx_b_EndpointUpdate_PUT_updateType) */
void zx_b_EndpointUpdate_PUT_updateType(struct zx_b_EndpointUpdate_s* x, struct zx_str* y) { x->updateType = y; }
/* FUNC(zx_b_EndpointUpdate_GET_Id) */
struct zx_str* zx_b_EndpointUpdate_GET_Id(struct zx_b_EndpointUpdate_s* x) { return x->Id; }
/* FUNC(zx_b_EndpointUpdate_PUT_Id) */
void zx_b_EndpointUpdate_PUT_Id(struct zx_b_EndpointUpdate_s* x, struct zx_str* y) { x->Id = y; }
/* FUNC(zx_b_EndpointUpdate_GET_actor) */
struct zx_str* zx_b_EndpointUpdate_GET_actor(struct zx_b_EndpointUpdate_s* x) { return x->actor; }
/* FUNC(zx_b_EndpointUpdate_PUT_actor) */
void zx_b_EndpointUpdate_PUT_actor(struct zx_b_EndpointUpdate_s* x, struct zx_str* y) { x->actor = y; }
/* FUNC(zx_b_EndpointUpdate_GET_mustUnderstand) */
struct zx_str* zx_b_EndpointUpdate_GET_mustUnderstand(struct zx_b_EndpointUpdate_s* x) { return x->mustUnderstand; }
/* FUNC(zx_b_EndpointUpdate_PUT_mustUnderstand) */
void zx_b_EndpointUpdate_PUT_mustUnderstand(struct zx_b_EndpointUpdate_s* x, struct zx_str* y) { x->mustUnderstand = y; }





/* FUNC(zx_b_Framework_GET_id) */
struct zx_str* zx_b_Framework_GET_id(struct zx_b_Framework_s* x) { return x->id; }
/* FUNC(zx_b_Framework_PUT_id) */
void zx_b_Framework_PUT_id(struct zx_b_Framework_s* x, struct zx_str* y) { x->id = y; }
/* FUNC(zx_b_Framework_GET_version) */
struct zx_str* zx_b_Framework_GET_version(struct zx_b_Framework_s* x) { return x->version; }
/* FUNC(zx_b_Framework_PUT_version) */
void zx_b_Framework_PUT_version(struct zx_b_Framework_s* x, struct zx_str* y) { x->version = y; }
/* FUNC(zx_b_Framework_GET_Id) */
struct zx_str* zx_b_Framework_GET_Id(struct zx_b_Framework_s* x) { return x->Id; }
/* FUNC(zx_b_Framework_PUT_Id) */
void zx_b_Framework_PUT_Id(struct zx_b_Framework_s* x, struct zx_str* y) { x->Id = y; }
/* FUNC(zx_b_Framework_GET_actor) */
struct zx_str* zx_b_Framework_GET_actor(struct zx_b_Framework_s* x) { return x->actor; }
/* FUNC(zx_b_Framework_PUT_actor) */
void zx_b_Framework_PUT_actor(struct zx_b_Framework_s* x, struct zx_str* y) { x->actor = y; }
/* FUNC(zx_b_Framework_GET_mustUnderstand) */
struct zx_str* zx_b_Framework_GET_mustUnderstand(struct zx_b_Framework_s* x) { return x->mustUnderstand; }
/* FUNC(zx_b_Framework_PUT_mustUnderstand) */
void zx_b_Framework_PUT_mustUnderstand(struct zx_b_Framework_s* x, struct zx_str* y) { x->mustUnderstand = y; }







#ifdef ZX_ENA_GETPUT

/* FUNC(zx_b_InteractionService_NUM_Address) */

int zx_b_InteractionService_NUM_Address(struct zx_b_InteractionService_s* x)
{
  struct zx_a_Address_s* y;
  int n = 0;
  if (!x) return 0;
  for (y = x->Address; y; ++n, y = (struct zx_a_Address_s*)y->gg.g.n) ;
  return n;
}

/* FUNC(zx_b_InteractionService_GET_Address) */

struct zx_a_Address_s* zx_b_InteractionService_GET_Address(struct zx_b_InteractionService_s* x, int n)
{
  struct zx_a_Address_s* y;
  if (!x) return 0;
  for (y = x->Address; n>=0 && y; --n, y = (struct zx_a_Address_s*)y->gg.g.n) ;
  return y;
}

/* FUNC(zx_b_InteractionService_POP_Address) */

struct zx_a_Address_s* zx_b_InteractionService_POP_Address(struct zx_b_InteractionService_s* x)
{
  struct zx_a_Address_s* y;
  if (!x) return 0;
  y = x->Address;
  if (y)
    x->Address = (struct zx_a_Address_s*)y->gg.g.n;
  return y;
}

/* FUNC(zx_b_InteractionService_PUSH_Address) */

void zx_b_InteractionService_PUSH_Address(struct zx_b_InteractionService_s* x, struct zx_a_Address_s* z)
{
  if (!x || !z) return;
  z->gg.g.n = &x->Address->gg.g;
  x->Address = z;
}

/* FUNC(zx_b_InteractionService_REV_Address) */

void zx_b_InteractionService_REV_Address(struct zx_b_InteractionService_s* x)
{
  struct zx_a_Address_s* nxt;
  struct zx_a_Address_s* y;
  if (!x) return;
  y = x->Address;
  if (!y) return;
  x->Address = 0;
  while (y) {
    nxt = (struct zx_a_Address_s*)y->gg.g.n;
    y->gg.g.n = &x->Address->gg.g;
    x->Address = y;
    y = nxt;
  }
}

/* FUNC(zx_b_InteractionService_PUT_Address) */

void zx_b_InteractionService_PUT_Address(struct zx_b_InteractionService_s* x, int n, struct zx_a_Address_s* z)
{
  struct zx_a_Address_s* y;
  if (!x || !z) return;
  y = x->Address;
  if (!y) return;
  switch (n) {
  case 0:
    z->gg.g.n = y->gg.g.n;
    x->Address = z;
    return;
  default:
    for (; n > 1 && y->gg.g.n; --n, y = (struct zx_a_Address_s*)y->gg.g.n) ;
    if (!y->gg.g.n) return;
    z->gg.g.n = y->gg.g.n->n;
    y->gg.g.n = &z->gg.g;
  }
}

/* FUNC(zx_b_InteractionService_ADD_Address) */

void zx_b_InteractionService_ADD_Address(struct zx_b_InteractionService_s* x, int n, struct zx_a_Address_s* z)
{
  struct zx_a_Address_s* y;
  if (!x || !z) return;
  switch (n) {
  case 0:
  add_to_start:
    z->gg.g.n = &x->Address->gg.g;
    x->Address = z;
    return;
  case -1:
    y = x->Address;
    if (!y) goto add_to_start;
    for (; y->gg.g.n; y = (struct zx_a_Address_s*)y->gg.g.n) ;
    break;
  default:
    for (y = x->Address; n > 1 && y; --n, y = (struct zx_a_Address_s*)y->gg.g.n) ;
    if (!y) return;
  }
  z->gg.g.n = y->gg.g.n;
  y->gg.g.n = &z->gg.g;
}

/* FUNC(zx_b_InteractionService_DEL_Address) */

void zx_b_InteractionService_DEL_Address(struct zx_b_InteractionService_s* x, int n)
{
  struct zx_a_Address_s* y;
  if (!x) return;
  switch (n) {
  case 0:
    x->Address = (struct zx_a_Address_s*)x->Address->gg.g.n;
    return;
  case -1:
    y = (struct zx_a_Address_s*)x->Address;
    if (!y) return;
    for (; y->gg.g.n; y = (struct zx_a_Address_s*)y->gg.g.n) ;
    break;
  default:
    for (y = x->Address; n > 1 && y->gg.g.n; --n, y = (struct zx_a_Address_s*)y->gg.g.n) ;
    if (!y->gg.g.n) return;
  }
  y->gg.g.n = y->gg.g.n->n;
}

#endif



#ifdef ZX_ENA_GETPUT

/* FUNC(zx_b_InteractionService_NUM_ReferenceParameters) */

int zx_b_InteractionService_NUM_ReferenceParameters(struct zx_b_InteractionService_s* x)
{
  struct zx_a_ReferenceParameters_s* y;
  int n = 0;
  if (!x) return 0;
  for (y = x->ReferenceParameters; y; ++n, y = (struct zx_a_ReferenceParameters_s*)y->gg.g.n) ;
  return n;
}

/* FUNC(zx_b_InteractionService_GET_ReferenceParameters) */

struct zx_a_ReferenceParameters_s* zx_b_InteractionService_GET_ReferenceParameters(struct zx_b_InteractionService_s* x, int n)
{
  struct zx_a_ReferenceParameters_s* y;
  if (!x) return 0;
  for (y = x->ReferenceParameters; n>=0 && y; --n, y = (struct zx_a_ReferenceParameters_s*)y->gg.g.n) ;
  return y;
}

/* FUNC(zx_b_InteractionService_POP_ReferenceParameters) */

struct zx_a_ReferenceParameters_s* zx_b_InteractionService_POP_ReferenceParameters(struct zx_b_InteractionService_s* x)
{
  struct zx_a_ReferenceParameters_s* y;
  if (!x) return 0;
  y = x->ReferenceParameters;
  if (y)
    x->ReferenceParameters = (struct zx_a_ReferenceParameters_s*)y->gg.g.n;
  return y;
}

/* FUNC(zx_b_InteractionService_PUSH_ReferenceParameters) */

void zx_b_InteractionService_PUSH_ReferenceParameters(struct zx_b_InteractionService_s* x, struct zx_a_ReferenceParameters_s* z)
{
  if (!x || !z) return;
  z->gg.g.n = &x->ReferenceParameters->gg.g;
  x->ReferenceParameters = z;
}

/* FUNC(zx_b_InteractionService_REV_ReferenceParameters) */

void zx_b_InteractionService_REV_ReferenceParameters(struct zx_b_InteractionService_s* x)
{
  struct zx_a_ReferenceParameters_s* nxt;
  struct zx_a_ReferenceParameters_s* y;
  if (!x) return;
  y = x->ReferenceParameters;
  if (!y) return;
  x->ReferenceParameters = 0;
  while (y) {
    nxt = (struct zx_a_ReferenceParameters_s*)y->gg.g.n;
    y->gg.g.n = &x->ReferenceParameters->gg.g;
    x->ReferenceParameters = y;
    y = nxt;
  }
}

/* FUNC(zx_b_InteractionService_PUT_ReferenceParameters) */

void zx_b_InteractionService_PUT_ReferenceParameters(struct zx_b_InteractionService_s* x, int n, struct zx_a_ReferenceParameters_s* z)
{
  struct zx_a_ReferenceParameters_s* y;
  if (!x || !z) return;
  y = x->ReferenceParameters;
  if (!y) return;
  switch (n) {
  case 0:
    z->gg.g.n = y->gg.g.n;
    x->ReferenceParameters = z;
    return;
  default:
    for (; n > 1 && y->gg.g.n; --n, y = (struct zx_a_ReferenceParameters_s*)y->gg.g.n) ;
    if (!y->gg.g.n) return;
    z->gg.g.n = y->gg.g.n->n;
    y->gg.g.n = &z->gg.g;
  }
}

/* FUNC(zx_b_InteractionService_ADD_ReferenceParameters) */

void zx_b_InteractionService_ADD_ReferenceParameters(struct zx_b_InteractionService_s* x, int n, struct zx_a_ReferenceParameters_s* z)
{
  struct zx_a_ReferenceParameters_s* y;
  if (!x || !z) return;
  switch (n) {
  case 0:
  add_to_start:
    z->gg.g.n = &x->ReferenceParameters->gg.g;
    x->ReferenceParameters = z;
    return;
  case -1:
    y = x->ReferenceParameters;
    if (!y) goto add_to_start;
    for (; y->gg.g.n; y = (struct zx_a_ReferenceParameters_s*)y->gg.g.n) ;
    break;
  default:
    for (y = x->ReferenceParameters; n > 1 && y; --n, y = (struct zx_a_ReferenceParameters_s*)y->gg.g.n) ;
    if (!y) return;
  }
  z->gg.g.n = y->gg.g.n;
  y->gg.g.n = &z->gg.g;
}

/* FUNC(zx_b_InteractionService_DEL_ReferenceParameters) */

void zx_b_InteractionService_DEL_ReferenceParameters(struct zx_b_InteractionService_s* x, int n)
{
  struct zx_a_ReferenceParameters_s* y;
  if (!x) return;
  switch (n) {
  case 0:
    x->ReferenceParameters = (struct zx_a_ReferenceParameters_s*)x->ReferenceParameters->gg.g.n;
    return;
  case -1:
    y = (struct zx_a_ReferenceParameters_s*)x->ReferenceParameters;
    if (!y) return;
    for (; y->gg.g.n; y = (struct zx_a_ReferenceParameters_s*)y->gg.g.n) ;
    break;
  default:
    for (y = x->ReferenceParameters; n > 1 && y->gg.g.n; --n, y = (struct zx_a_ReferenceParameters_s*)y->gg.g.n) ;
    if (!y->gg.g.n) return;
  }
  y->gg.g.n = y->gg.g.n->n;
}

#endif



#ifdef ZX_ENA_GETPUT

/* FUNC(zx_b_InteractionService_NUM_Metadata) */

int zx_b_InteractionService_NUM_Metadata(struct zx_b_InteractionService_s* x)
{
  struct zx_a_Metadata_s* y;
  int n = 0;
  if (!x) return 0;
  for (y = x->Metadata; y; ++n, y = (struct zx_a_Metadata_s*)y->gg.g.n) ;
  return n;
}

/* FUNC(zx_b_InteractionService_GET_Metadata) */

struct zx_a_Metadata_s* zx_b_InteractionService_GET_Metadata(struct zx_b_InteractionService_s* x, int n)
{
  struct zx_a_Metadata_s* y;
  if (!x) return 0;
  for (y = x->Metadata; n>=0 && y; --n, y = (struct zx_a_Metadata_s*)y->gg.g.n) ;
  return y;
}

/* FUNC(zx_b_InteractionService_POP_Metadata) */

struct zx_a_Metadata_s* zx_b_InteractionService_POP_Metadata(struct zx_b_InteractionService_s* x)
{
  struct zx_a_Metadata_s* y;
  if (!x) return 0;
  y = x->Metadata;
  if (y)
    x->Metadata = (struct zx_a_Metadata_s*)y->gg.g.n;
  return y;
}

/* FUNC(zx_b_InteractionService_PUSH_Metadata) */

void zx_b_InteractionService_PUSH_Metadata(struct zx_b_InteractionService_s* x, struct zx_a_Metadata_s* z)
{
  if (!x || !z) return;
  z->gg.g.n = &x->Metadata->gg.g;
  x->Metadata = z;
}

/* FUNC(zx_b_InteractionService_REV_Metadata) */

void zx_b_InteractionService_REV_Metadata(struct zx_b_InteractionService_s* x)
{
  struct zx_a_Metadata_s* nxt;
  struct zx_a_Metadata_s* y;
  if (!x) return;
  y = x->Metadata;
  if (!y) return;
  x->Metadata = 0;
  while (y) {
    nxt = (struct zx_a_Metadata_s*)y->gg.g.n;
    y->gg.g.n = &x->Metadata->gg.g;
    x->Metadata = y;
    y = nxt;
  }
}

/* FUNC(zx_b_InteractionService_PUT_Metadata) */

void zx_b_InteractionService_PUT_Metadata(struct zx_b_InteractionService_s* x, int n, struct zx_a_Metadata_s* z)
{
  struct zx_a_Metadata_s* y;
  if (!x || !z) return;
  y = x->Metadata;
  if (!y) return;
  switch (n) {
  case 0:
    z->gg.g.n = y->gg.g.n;
    x->Metadata = z;
    return;
  default:
    for (; n > 1 && y->gg.g.n; --n, y = (struct zx_a_Metadata_s*)y->gg.g.n) ;
    if (!y->gg.g.n) return;
    z->gg.g.n = y->gg.g.n->n;
    y->gg.g.n = &z->gg.g;
  }
}

/* FUNC(zx_b_InteractionService_ADD_Metadata) */

void zx_b_InteractionService_ADD_Metadata(struct zx_b_InteractionService_s* x, int n, struct zx_a_Metadata_s* z)
{
  struct zx_a_Metadata_s* y;
  if (!x || !z) return;
  switch (n) {
  case 0:
  add_to_start:
    z->gg.g.n = &x->Metadata->gg.g;
    x->Metadata = z;
    return;
  case -1:
    y = x->Metadata;
    if (!y) goto add_to_start;
    for (; y->gg.g.n; y = (struct zx_a_Metadata_s*)y->gg.g.n) ;
    break;
  default:
    for (y = x->Metadata; n > 1 && y; --n, y = (struct zx_a_Metadata_s*)y->gg.g.n) ;
    if (!y) return;
  }
  z->gg.g.n = y->gg.g.n;
  y->gg.g.n = &z->gg.g;
}

/* FUNC(zx_b_InteractionService_DEL_Metadata) */

void zx_b_InteractionService_DEL_Metadata(struct zx_b_InteractionService_s* x, int n)
{
  struct zx_a_Metadata_s* y;
  if (!x) return;
  switch (n) {
  case 0:
    x->Metadata = (struct zx_a_Metadata_s*)x->Metadata->gg.g.n;
    return;
  case -1:
    y = (struct zx_a_Metadata_s*)x->Metadata;
    if (!y) return;
    for (; y->gg.g.n; y = (struct zx_a_Metadata_s*)y->gg.g.n) ;
    break;
  default:
    for (y = x->Metadata; n > 1 && y->gg.g.n; --n, y = (struct zx_a_Metadata_s*)y->gg.g.n) ;
    if (!y->gg.g.n) return;
  }
  y->gg.g.n = y->gg.g.n->n;
}

#endif

/* FUNC(zx_b_InteractionService_GET_ID) */
struct zx_str* zx_b_InteractionService_GET_ID(struct zx_b_InteractionService_s* x) { return x->ID; }
/* FUNC(zx_b_InteractionService_PUT_ID) */
void zx_b_InteractionService_PUT_ID(struct zx_b_InteractionService_s* x, struct zx_str* y) { x->ID = y; }
/* FUNC(zx_b_InteractionService_GET_id) */
struct zx_str* zx_b_InteractionService_GET_id(struct zx_b_InteractionService_s* x) { return x->id; }
/* FUNC(zx_b_InteractionService_PUT_id) */
void zx_b_InteractionService_PUT_id(struct zx_b_InteractionService_s* x, struct zx_str* y) { x->id = y; }
/* FUNC(zx_b_InteractionService_GET_notOnOrAfter) */
struct zx_str* zx_b_InteractionService_GET_notOnOrAfter(struct zx_b_InteractionService_s* x) { return x->notOnOrAfter; }
/* FUNC(zx_b_InteractionService_PUT_notOnOrAfter) */
void zx_b_InteractionService_PUT_notOnOrAfter(struct zx_b_InteractionService_s* x, struct zx_str* y) { x->notOnOrAfter = y; }
/* FUNC(zx_b_InteractionService_GET_Id) */
struct zx_str* zx_b_InteractionService_GET_Id(struct zx_b_InteractionService_s* x) { return x->Id; }
/* FUNC(zx_b_InteractionService_PUT_Id) */
void zx_b_InteractionService_PUT_Id(struct zx_b_InteractionService_s* x, struct zx_str* y) { x->Id = y; }
/* FUNC(zx_b_InteractionService_GET_actor) */
struct zx_str* zx_b_InteractionService_GET_actor(struct zx_b_InteractionService_s* x) { return x->actor; }
/* FUNC(zx_b_InteractionService_PUT_actor) */
void zx_b_InteractionService_PUT_actor(struct zx_b_InteractionService_s* x, struct zx_str* y) { x->actor = y; }
/* FUNC(zx_b_InteractionService_GET_mustUnderstand) */
struct zx_str* zx_b_InteractionService_GET_mustUnderstand(struct zx_b_InteractionService_s* x) { return x->mustUnderstand; }
/* FUNC(zx_b_InteractionService_PUT_mustUnderstand) */
void zx_b_InteractionService_PUT_mustUnderstand(struct zx_b_InteractionService_s* x, struct zx_str* y) { x->mustUnderstand = y; }





/* FUNC(zx_b_ProcessingContext_GET_id) */
struct zx_str* zx_b_ProcessingContext_GET_id(struct zx_b_ProcessingContext_s* x) { return x->id; }
/* FUNC(zx_b_ProcessingContext_PUT_id) */
void zx_b_ProcessingContext_PUT_id(struct zx_b_ProcessingContext_s* x, struct zx_str* y) { x->id = y; }
/* FUNC(zx_b_ProcessingContext_GET_Id) */
struct zx_str* zx_b_ProcessingContext_GET_Id(struct zx_b_ProcessingContext_s* x) { return x->Id; }
/* FUNC(zx_b_ProcessingContext_PUT_Id) */
void zx_b_ProcessingContext_PUT_Id(struct zx_b_ProcessingContext_s* x, struct zx_str* y) { x->Id = y; }
/* FUNC(zx_b_ProcessingContext_GET_actor) */
struct zx_str* zx_b_ProcessingContext_GET_actor(struct zx_b_ProcessingContext_s* x) { return x->actor; }
/* FUNC(zx_b_ProcessingContext_PUT_actor) */
void zx_b_ProcessingContext_PUT_actor(struct zx_b_ProcessingContext_s* x, struct zx_str* y) { x->actor = y; }
/* FUNC(zx_b_ProcessingContext_GET_mustUnderstand) */
struct zx_str* zx_b_ProcessingContext_GET_mustUnderstand(struct zx_b_ProcessingContext_s* x) { return x->mustUnderstand; }
/* FUNC(zx_b_ProcessingContext_PUT_mustUnderstand) */
void zx_b_ProcessingContext_PUT_mustUnderstand(struct zx_b_ProcessingContext_s* x, struct zx_str* y) { x->mustUnderstand = y; }





/* FUNC(zx_b_RedirectRequest_GET_id) */
struct zx_str* zx_b_RedirectRequest_GET_id(struct zx_b_RedirectRequest_s* x) { return x->id; }
/* FUNC(zx_b_RedirectRequest_PUT_id) */
void zx_b_RedirectRequest_PUT_id(struct zx_b_RedirectRequest_s* x, struct zx_str* y) { x->id = y; }
/* FUNC(zx_b_RedirectRequest_GET_redirectURL) */
struct zx_str* zx_b_RedirectRequest_GET_redirectURL(struct zx_b_RedirectRequest_s* x) { return x->redirectURL; }
/* FUNC(zx_b_RedirectRequest_PUT_redirectURL) */
void zx_b_RedirectRequest_PUT_redirectURL(struct zx_b_RedirectRequest_s* x, struct zx_str* y) { x->redirectURL = y; }
/* FUNC(zx_b_RedirectRequest_GET_Id) */
struct zx_str* zx_b_RedirectRequest_GET_Id(struct zx_b_RedirectRequest_s* x) { return x->Id; }
/* FUNC(zx_b_RedirectRequest_PUT_Id) */
void zx_b_RedirectRequest_PUT_Id(struct zx_b_RedirectRequest_s* x, struct zx_str* y) { x->Id = y; }
/* FUNC(zx_b_RedirectRequest_GET_actor) */
struct zx_str* zx_b_RedirectRequest_GET_actor(struct zx_b_RedirectRequest_s* x) { return x->actor; }
/* FUNC(zx_b_RedirectRequest_PUT_actor) */
void zx_b_RedirectRequest_PUT_actor(struct zx_b_RedirectRequest_s* x, struct zx_str* y) { x->actor = y; }
/* FUNC(zx_b_RedirectRequest_GET_mustUnderstand) */
struct zx_str* zx_b_RedirectRequest_GET_mustUnderstand(struct zx_b_RedirectRequest_s* x) { return x->mustUnderstand; }
/* FUNC(zx_b_RedirectRequest_PUT_mustUnderstand) */
void zx_b_RedirectRequest_PUT_mustUnderstand(struct zx_b_RedirectRequest_s* x, struct zx_str* y) { x->mustUnderstand = y; }





/* FUNC(zx_b_Sender_GET_affiliationID) */
struct zx_str* zx_b_Sender_GET_affiliationID(struct zx_b_Sender_s* x) { return x->affiliationID; }
/* FUNC(zx_b_Sender_PUT_affiliationID) */
void zx_b_Sender_PUT_affiliationID(struct zx_b_Sender_s* x, struct zx_str* y) { x->affiliationID = y; }
/* FUNC(zx_b_Sender_GET_id) */
struct zx_str* zx_b_Sender_GET_id(struct zx_b_Sender_s* x) { return x->id; }
/* FUNC(zx_b_Sender_PUT_id) */
void zx_b_Sender_PUT_id(struct zx_b_Sender_s* x, struct zx_str* y) { x->id = y; }
/* FUNC(zx_b_Sender_GET_providerID) */
struct zx_str* zx_b_Sender_GET_providerID(struct zx_b_Sender_s* x) { return x->providerID; }
/* FUNC(zx_b_Sender_PUT_providerID) */
void zx_b_Sender_PUT_providerID(struct zx_b_Sender_s* x, struct zx_str* y) { x->providerID = y; }
/* FUNC(zx_b_Sender_GET_Id) */
struct zx_str* zx_b_Sender_GET_Id(struct zx_b_Sender_s* x) { return x->Id; }
/* FUNC(zx_b_Sender_PUT_Id) */
void zx_b_Sender_PUT_Id(struct zx_b_Sender_s* x, struct zx_str* y) { x->Id = y; }
/* FUNC(zx_b_Sender_GET_actor) */
struct zx_str* zx_b_Sender_GET_actor(struct zx_b_Sender_s* x) { return x->actor; }
/* FUNC(zx_b_Sender_PUT_actor) */
void zx_b_Sender_PUT_actor(struct zx_b_Sender_s* x, struct zx_str* y) { x->actor = y; }
/* FUNC(zx_b_Sender_GET_mustUnderstand) */
struct zx_str* zx_b_Sender_GET_mustUnderstand(struct zx_b_Sender_s* x) { return x->mustUnderstand; }
/* FUNC(zx_b_Sender_PUT_mustUnderstand) */
void zx_b_Sender_PUT_mustUnderstand(struct zx_b_Sender_s* x, struct zx_str* y) { x->mustUnderstand = y; }







#ifdef ZX_ENA_GETPUT

/* FUNC(zx_b_TargetIdentity_NUM_Assertion) */

int zx_b_TargetIdentity_NUM_Assertion(struct zx_b_TargetIdentity_s* x)
{
  struct zx_sa_Assertion_s* y;
  int n = 0;
  if (!x) return 0;
  for (y = x->Assertion; y; ++n, y = (struct zx_sa_Assertion_s*)y->gg.g.n) ;
  return n;
}

/* FUNC(zx_b_TargetIdentity_GET_Assertion) */

struct zx_sa_Assertion_s* zx_b_TargetIdentity_GET_Assertion(struct zx_b_TargetIdentity_s* x, int n)
{
  struct zx_sa_Assertion_s* y;
  if (!x) return 0;
  for (y = x->Assertion; n>=0 && y; --n, y = (struct zx_sa_Assertion_s*)y->gg.g.n) ;
  return y;
}

/* FUNC(zx_b_TargetIdentity_POP_Assertion) */

struct zx_sa_Assertion_s* zx_b_TargetIdentity_POP_Assertion(struct zx_b_TargetIdentity_s* x)
{
  struct zx_sa_Assertion_s* y;
  if (!x) return 0;
  y = x->Assertion;
  if (y)
    x->Assertion = (struct zx_sa_Assertion_s*)y->gg.g.n;
  return y;
}

/* FUNC(zx_b_TargetIdentity_PUSH_Assertion) */

void zx_b_TargetIdentity_PUSH_Assertion(struct zx_b_TargetIdentity_s* x, struct zx_sa_Assertion_s* z)
{
  if (!x || !z) return;
  z->gg.g.n = &x->Assertion->gg.g;
  x->Assertion = z;
}

/* FUNC(zx_b_TargetIdentity_REV_Assertion) */

void zx_b_TargetIdentity_REV_Assertion(struct zx_b_TargetIdentity_s* x)
{
  struct zx_sa_Assertion_s* nxt;
  struct zx_sa_Assertion_s* y;
  if (!x) return;
  y = x->Assertion;
  if (!y) return;
  x->Assertion = 0;
  while (y) {
    nxt = (struct zx_sa_Assertion_s*)y->gg.g.n;
    y->gg.g.n = &x->Assertion->gg.g;
    x->Assertion = y;
    y = nxt;
  }
}

/* FUNC(zx_b_TargetIdentity_PUT_Assertion) */

void zx_b_TargetIdentity_PUT_Assertion(struct zx_b_TargetIdentity_s* x, int n, struct zx_sa_Assertion_s* z)
{
  struct zx_sa_Assertion_s* y;
  if (!x || !z) return;
  y = x->Assertion;
  if (!y) return;
  switch (n) {
  case 0:
    z->gg.g.n = y->gg.g.n;
    x->Assertion = z;
    return;
  default:
    for (; n > 1 && y->gg.g.n; --n, y = (struct zx_sa_Assertion_s*)y->gg.g.n) ;
    if (!y->gg.g.n) return;
    z->gg.g.n = y->gg.g.n->n;
    y->gg.g.n = &z->gg.g;
  }
}

/* FUNC(zx_b_TargetIdentity_ADD_Assertion) */

void zx_b_TargetIdentity_ADD_Assertion(struct zx_b_TargetIdentity_s* x, int n, struct zx_sa_Assertion_s* z)
{
  struct zx_sa_Assertion_s* y;
  if (!x || !z) return;
  switch (n) {
  case 0:
  add_to_start:
    z->gg.g.n = &x->Assertion->gg.g;
    x->Assertion = z;
    return;
  case -1:
    y = x->Assertion;
    if (!y) goto add_to_start;
    for (; y->gg.g.n; y = (struct zx_sa_Assertion_s*)y->gg.g.n) ;
    break;
  default:
    for (y = x->Assertion; n > 1 && y; --n, y = (struct zx_sa_Assertion_s*)y->gg.g.n) ;
    if (!y) return;
  }
  z->gg.g.n = y->gg.g.n;
  y->gg.g.n = &z->gg.g;
}

/* FUNC(zx_b_TargetIdentity_DEL_Assertion) */

void zx_b_TargetIdentity_DEL_Assertion(struct zx_b_TargetIdentity_s* x, int n)
{
  struct zx_sa_Assertion_s* y;
  if (!x) return;
  switch (n) {
  case 0:
    x->Assertion = (struct zx_sa_Assertion_s*)x->Assertion->gg.g.n;
    return;
  case -1:
    y = (struct zx_sa_Assertion_s*)x->Assertion;
    if (!y) return;
    for (; y->gg.g.n; y = (struct zx_sa_Assertion_s*)y->gg.g.n) ;
    break;
  default:
    for (y = x->Assertion; n > 1 && y->gg.g.n; --n, y = (struct zx_sa_Assertion_s*)y->gg.g.n) ;
    if (!y->gg.g.n) return;
  }
  y->gg.g.n = y->gg.g.n->n;
}

#endif



#ifdef ZX_ENA_GETPUT

/* FUNC(zx_b_TargetIdentity_NUM_EncryptedAssertion) */

int zx_b_TargetIdentity_NUM_EncryptedAssertion(struct zx_b_TargetIdentity_s* x)
{
  struct zx_sa_EncryptedAssertion_s* y;
  int n = 0;
  if (!x) return 0;
  for (y = x->EncryptedAssertion; y; ++n, y = (struct zx_sa_EncryptedAssertion_s*)y->gg.g.n) ;
  return n;
}

/* FUNC(zx_b_TargetIdentity_GET_EncryptedAssertion) */

struct zx_sa_EncryptedAssertion_s* zx_b_TargetIdentity_GET_EncryptedAssertion(struct zx_b_TargetIdentity_s* x, int n)
{
  struct zx_sa_EncryptedAssertion_s* y;
  if (!x) return 0;
  for (y = x->EncryptedAssertion; n>=0 && y; --n, y = (struct zx_sa_EncryptedAssertion_s*)y->gg.g.n) ;
  return y;
}

/* FUNC(zx_b_TargetIdentity_POP_EncryptedAssertion) */

struct zx_sa_EncryptedAssertion_s* zx_b_TargetIdentity_POP_EncryptedAssertion(struct zx_b_TargetIdentity_s* x)
{
  struct zx_sa_EncryptedAssertion_s* y;
  if (!x) return 0;
  y = x->EncryptedAssertion;
  if (y)
    x->EncryptedAssertion = (struct zx_sa_EncryptedAssertion_s*)y->gg.g.n;
  return y;
}

/* FUNC(zx_b_TargetIdentity_PUSH_EncryptedAssertion) */

void zx_b_TargetIdentity_PUSH_EncryptedAssertion(struct zx_b_TargetIdentity_s* x, struct zx_sa_EncryptedAssertion_s* z)
{
  if (!x || !z) return;
  z->gg.g.n = &x->EncryptedAssertion->gg.g;
  x->EncryptedAssertion = z;
}

/* FUNC(zx_b_TargetIdentity_REV_EncryptedAssertion) */

void zx_b_TargetIdentity_REV_EncryptedAssertion(struct zx_b_TargetIdentity_s* x)
{
  struct zx_sa_EncryptedAssertion_s* nxt;
  struct zx_sa_EncryptedAssertion_s* y;
  if (!x) return;
  y = x->EncryptedAssertion;
  if (!y) return;
  x->EncryptedAssertion = 0;
  while (y) {
    nxt = (struct zx_sa_EncryptedAssertion_s*)y->gg.g.n;
    y->gg.g.n = &x->EncryptedAssertion->gg.g;
    x->EncryptedAssertion = y;
    y = nxt;
  }
}

/* FUNC(zx_b_TargetIdentity_PUT_EncryptedAssertion) */

void zx_b_TargetIdentity_PUT_EncryptedAssertion(struct zx_b_TargetIdentity_s* x, int n, struct zx_sa_EncryptedAssertion_s* z)
{
  struct zx_sa_EncryptedAssertion_s* y;
  if (!x || !z) return;
  y = x->EncryptedAssertion;
  if (!y) return;
  switch (n) {
  case 0:
    z->gg.g.n = y->gg.g.n;
    x->EncryptedAssertion = z;
    return;
  default:
    for (; n > 1 && y->gg.g.n; --n, y = (struct zx_sa_EncryptedAssertion_s*)y->gg.g.n) ;
    if (!y->gg.g.n) return;
    z->gg.g.n = y->gg.g.n->n;
    y->gg.g.n = &z->gg.g;
  }
}

/* FUNC(zx_b_TargetIdentity_ADD_EncryptedAssertion) */

void zx_b_TargetIdentity_ADD_EncryptedAssertion(struct zx_b_TargetIdentity_s* x, int n, struct zx_sa_EncryptedAssertion_s* z)
{
  struct zx_sa_EncryptedAssertion_s* y;
  if (!x || !z) return;
  switch (n) {
  case 0:
  add_to_start:
    z->gg.g.n = &x->EncryptedAssertion->gg.g;
    x->EncryptedAssertion = z;
    return;
  case -1:
    y = x->EncryptedAssertion;
    if (!y) goto add_to_start;
    for (; y->gg.g.n; y = (struct zx_sa_EncryptedAssertion_s*)y->gg.g.n) ;
    break;
  default:
    for (y = x->EncryptedAssertion; n > 1 && y; --n, y = (struct zx_sa_EncryptedAssertion_s*)y->gg.g.n) ;
    if (!y) return;
  }
  z->gg.g.n = y->gg.g.n;
  y->gg.g.n = &z->gg.g;
}

/* FUNC(zx_b_TargetIdentity_DEL_EncryptedAssertion) */

void zx_b_TargetIdentity_DEL_EncryptedAssertion(struct zx_b_TargetIdentity_s* x, int n)
{
  struct zx_sa_EncryptedAssertion_s* y;
  if (!x) return;
  switch (n) {
  case 0:
    x->EncryptedAssertion = (struct zx_sa_EncryptedAssertion_s*)x->EncryptedAssertion->gg.g.n;
    return;
  case -1:
    y = (struct zx_sa_EncryptedAssertion_s*)x->EncryptedAssertion;
    if (!y) return;
    for (; y->gg.g.n; y = (struct zx_sa_EncryptedAssertion_s*)y->gg.g.n) ;
    break;
  default:
    for (y = x->EncryptedAssertion; n > 1 && y->gg.g.n; --n, y = (struct zx_sa_EncryptedAssertion_s*)y->gg.g.n) ;
    if (!y->gg.g.n) return;
  }
  y->gg.g.n = y->gg.g.n->n;
}

#endif



#ifdef ZX_ENA_GETPUT

/* FUNC(zx_b_TargetIdentity_NUM_sa11_Assertion) */

int zx_b_TargetIdentity_NUM_sa11_Assertion(struct zx_b_TargetIdentity_s* x)
{
  struct zx_sa11_Assertion_s* y;
  int n = 0;
  if (!x) return 0;
  for (y = x->sa11_Assertion; y; ++n, y = (struct zx_sa11_Assertion_s*)y->gg.g.n) ;
  return n;
}

/* FUNC(zx_b_TargetIdentity_GET_sa11_Assertion) */

struct zx_sa11_Assertion_s* zx_b_TargetIdentity_GET_sa11_Assertion(struct zx_b_TargetIdentity_s* x, int n)
{
  struct zx_sa11_Assertion_s* y;
  if (!x) return 0;
  for (y = x->sa11_Assertion; n>=0 && y; --n, y = (struct zx_sa11_Assertion_s*)y->gg.g.n) ;
  return y;
}

/* FUNC(zx_b_TargetIdentity_POP_sa11_Assertion) */

struct zx_sa11_Assertion_s* zx_b_TargetIdentity_POP_sa11_Assertion(struct zx_b_TargetIdentity_s* x)
{
  struct zx_sa11_Assertion_s* y;
  if (!x) return 0;
  y = x->sa11_Assertion;
  if (y)
    x->sa11_Assertion = (struct zx_sa11_Assertion_s*)y->gg.g.n;
  return y;
}

/* FUNC(zx_b_TargetIdentity_PUSH_sa11_Assertion) */

void zx_b_TargetIdentity_PUSH_sa11_Assertion(struct zx_b_TargetIdentity_s* x, struct zx_sa11_Assertion_s* z)
{
  if (!x || !z) return;
  z->gg.g.n = &x->sa11_Assertion->gg.g;
  x->sa11_Assertion = z;
}

/* FUNC(zx_b_TargetIdentity_REV_sa11_Assertion) */

void zx_b_TargetIdentity_REV_sa11_Assertion(struct zx_b_TargetIdentity_s* x)
{
  struct zx_sa11_Assertion_s* nxt;
  struct zx_sa11_Assertion_s* y;
  if (!x) return;
  y = x->sa11_Assertion;
  if (!y) return;
  x->sa11_Assertion = 0;
  while (y) {
    nxt = (struct zx_sa11_Assertion_s*)y->gg.g.n;
    y->gg.g.n = &x->sa11_Assertion->gg.g;
    x->sa11_Assertion = y;
    y = nxt;
  }
}

/* FUNC(zx_b_TargetIdentity_PUT_sa11_Assertion) */

void zx_b_TargetIdentity_PUT_sa11_Assertion(struct zx_b_TargetIdentity_s* x, int n, struct zx_sa11_Assertion_s* z)
{
  struct zx_sa11_Assertion_s* y;
  if (!x || !z) return;
  y = x->sa11_Assertion;
  if (!y) return;
  switch (n) {
  case 0:
    z->gg.g.n = y->gg.g.n;
    x->sa11_Assertion = z;
    return;
  default:
    for (; n > 1 && y->gg.g.n; --n, y = (struct zx_sa11_Assertion_s*)y->gg.g.n) ;
    if (!y->gg.g.n) return;
    z->gg.g.n = y->gg.g.n->n;
    y->gg.g.n = &z->gg.g;
  }
}

/* FUNC(zx_b_TargetIdentity_ADD_sa11_Assertion) */

void zx_b_TargetIdentity_ADD_sa11_Assertion(struct zx_b_TargetIdentity_s* x, int n, struct zx_sa11_Assertion_s* z)
{
  struct zx_sa11_Assertion_s* y;
  if (!x || !z) return;
  switch (n) {
  case 0:
  add_to_start:
    z->gg.g.n = &x->sa11_Assertion->gg.g;
    x->sa11_Assertion = z;
    return;
  case -1:
    y = x->sa11_Assertion;
    if (!y) goto add_to_start;
    for (; y->gg.g.n; y = (struct zx_sa11_Assertion_s*)y->gg.g.n) ;
    break;
  default:
    for (y = x->sa11_Assertion; n > 1 && y; --n, y = (struct zx_sa11_Assertion_s*)y->gg.g.n) ;
    if (!y) return;
  }
  z->gg.g.n = y->gg.g.n;
  y->gg.g.n = &z->gg.g;
}

/* FUNC(zx_b_TargetIdentity_DEL_sa11_Assertion) */

void zx_b_TargetIdentity_DEL_sa11_Assertion(struct zx_b_TargetIdentity_s* x, int n)
{
  struct zx_sa11_Assertion_s* y;
  if (!x) return;
  switch (n) {
  case 0:
    x->sa11_Assertion = (struct zx_sa11_Assertion_s*)x->sa11_Assertion->gg.g.n;
    return;
  case -1:
    y = (struct zx_sa11_Assertion_s*)x->sa11_Assertion;
    if (!y) return;
    for (; y->gg.g.n; y = (struct zx_sa11_Assertion_s*)y->gg.g.n) ;
    break;
  default:
    for (y = x->sa11_Assertion; n > 1 && y->gg.g.n; --n, y = (struct zx_sa11_Assertion_s*)y->gg.g.n) ;
    if (!y->gg.g.n) return;
  }
  y->gg.g.n = y->gg.g.n->n;
}

#endif



#ifdef ZX_ENA_GETPUT

/* FUNC(zx_b_TargetIdentity_NUM_ff12_Assertion) */

int zx_b_TargetIdentity_NUM_ff12_Assertion(struct zx_b_TargetIdentity_s* x)
{
  struct zx_ff12_Assertion_s* y;
  int n = 0;
  if (!x) return 0;
  for (y = x->ff12_Assertion; y; ++n, y = (struct zx_ff12_Assertion_s*)y->gg.g.n) ;
  return n;
}

/* FUNC(zx_b_TargetIdentity_GET_ff12_Assertion) */

struct zx_ff12_Assertion_s* zx_b_TargetIdentity_GET_ff12_Assertion(struct zx_b_TargetIdentity_s* x, int n)
{
  struct zx_ff12_Assertion_s* y;
  if (!x) return 0;
  for (y = x->ff12_Assertion; n>=0 && y; --n, y = (struct zx_ff12_Assertion_s*)y->gg.g.n) ;
  return y;
}

/* FUNC(zx_b_TargetIdentity_POP_ff12_Assertion) */

struct zx_ff12_Assertion_s* zx_b_TargetIdentity_POP_ff12_Assertion(struct zx_b_TargetIdentity_s* x)
{
  struct zx_ff12_Assertion_s* y;
  if (!x) return 0;
  y = x->ff12_Assertion;
  if (y)
    x->ff12_Assertion = (struct zx_ff12_Assertion_s*)y->gg.g.n;
  return y;
}

/* FUNC(zx_b_TargetIdentity_PUSH_ff12_Assertion) */

void zx_b_TargetIdentity_PUSH_ff12_Assertion(struct zx_b_TargetIdentity_s* x, struct zx_ff12_Assertion_s* z)
{
  if (!x || !z) return;
  z->gg.g.n = &x->ff12_Assertion->gg.g;
  x->ff12_Assertion = z;
}

/* FUNC(zx_b_TargetIdentity_REV_ff12_Assertion) */

void zx_b_TargetIdentity_REV_ff12_Assertion(struct zx_b_TargetIdentity_s* x)
{
  struct zx_ff12_Assertion_s* nxt;
  struct zx_ff12_Assertion_s* y;
  if (!x) return;
  y = x->ff12_Assertion;
  if (!y) return;
  x->ff12_Assertion = 0;
  while (y) {
    nxt = (struct zx_ff12_Assertion_s*)y->gg.g.n;
    y->gg.g.n = &x->ff12_Assertion->gg.g;
    x->ff12_Assertion = y;
    y = nxt;
  }
}

/* FUNC(zx_b_TargetIdentity_PUT_ff12_Assertion) */

void zx_b_TargetIdentity_PUT_ff12_Assertion(struct zx_b_TargetIdentity_s* x, int n, struct zx_ff12_Assertion_s* z)
{
  struct zx_ff12_Assertion_s* y;
  if (!x || !z) return;
  y = x->ff12_Assertion;
  if (!y) return;
  switch (n) {
  case 0:
    z->gg.g.n = y->gg.g.n;
    x->ff12_Assertion = z;
    return;
  default:
    for (; n > 1 && y->gg.g.n; --n, y = (struct zx_ff12_Assertion_s*)y->gg.g.n) ;
    if (!y->gg.g.n) return;
    z->gg.g.n = y->gg.g.n->n;
    y->gg.g.n = &z->gg.g;
  }
}

/* FUNC(zx_b_TargetIdentity_ADD_ff12_Assertion) */

void zx_b_TargetIdentity_ADD_ff12_Assertion(struct zx_b_TargetIdentity_s* x, int n, struct zx_ff12_Assertion_s* z)
{
  struct zx_ff12_Assertion_s* y;
  if (!x || !z) return;
  switch (n) {
  case 0:
  add_to_start:
    z->gg.g.n = &x->ff12_Assertion->gg.g;
    x->ff12_Assertion = z;
    return;
  case -1:
    y = x->ff12_Assertion;
    if (!y) goto add_to_start;
    for (; y->gg.g.n; y = (struct zx_ff12_Assertion_s*)y->gg.g.n) ;
    break;
  default:
    for (y = x->ff12_Assertion; n > 1 && y; --n, y = (struct zx_ff12_Assertion_s*)y->gg.g.n) ;
    if (!y) return;
  }
  z->gg.g.n = y->gg.g.n;
  y->gg.g.n = &z->gg.g;
}

/* FUNC(zx_b_TargetIdentity_DEL_ff12_Assertion) */

void zx_b_TargetIdentity_DEL_ff12_Assertion(struct zx_b_TargetIdentity_s* x, int n)
{
  struct zx_ff12_Assertion_s* y;
  if (!x) return;
  switch (n) {
  case 0:
    x->ff12_Assertion = (struct zx_ff12_Assertion_s*)x->ff12_Assertion->gg.g.n;
    return;
  case -1:
    y = (struct zx_ff12_Assertion_s*)x->ff12_Assertion;
    if (!y) return;
    for (; y->gg.g.n; y = (struct zx_ff12_Assertion_s*)y->gg.g.n) ;
    break;
  default:
    for (y = x->ff12_Assertion; n > 1 && y->gg.g.n; --n, y = (struct zx_ff12_Assertion_s*)y->gg.g.n) ;
    if (!y->gg.g.n) return;
  }
  y->gg.g.n = y->gg.g.n->n;
}

#endif

/* FUNC(zx_b_TargetIdentity_GET_id) */
struct zx_str* zx_b_TargetIdentity_GET_id(struct zx_b_TargetIdentity_s* x) { return x->id; }
/* FUNC(zx_b_TargetIdentity_PUT_id) */
void zx_b_TargetIdentity_PUT_id(struct zx_b_TargetIdentity_s* x, struct zx_str* y) { x->id = y; }
/* FUNC(zx_b_TargetIdentity_GET_Id) */
struct zx_str* zx_b_TargetIdentity_GET_Id(struct zx_b_TargetIdentity_s* x) { return x->Id; }
/* FUNC(zx_b_TargetIdentity_PUT_Id) */
void zx_b_TargetIdentity_PUT_Id(struct zx_b_TargetIdentity_s* x, struct zx_str* y) { x->Id = y; }
/* FUNC(zx_b_TargetIdentity_GET_actor) */
struct zx_str* zx_b_TargetIdentity_GET_actor(struct zx_b_TargetIdentity_s* x) { return x->actor; }
/* FUNC(zx_b_TargetIdentity_PUT_actor) */
void zx_b_TargetIdentity_PUT_actor(struct zx_b_TargetIdentity_s* x, struct zx_str* y) { x->actor = y; }
/* FUNC(zx_b_TargetIdentity_GET_mustUnderstand) */
struct zx_str* zx_b_TargetIdentity_GET_mustUnderstand(struct zx_b_TargetIdentity_s* x) { return x->mustUnderstand; }
/* FUNC(zx_b_TargetIdentity_PUT_mustUnderstand) */
void zx_b_TargetIdentity_PUT_mustUnderstand(struct zx_b_TargetIdentity_s* x, struct zx_str* y) { x->mustUnderstand = y; }





/* FUNC(zx_b_Timeout_GET_id) */
struct zx_str* zx_b_Timeout_GET_id(struct zx_b_Timeout_s* x) { return x->id; }
/* FUNC(zx_b_Timeout_PUT_id) */
void zx_b_Timeout_PUT_id(struct zx_b_Timeout_s* x, struct zx_str* y) { x->id = y; }
/* FUNC(zx_b_Timeout_GET_maxProcessingTime) */
struct zx_str* zx_b_Timeout_GET_maxProcessingTime(struct zx_b_Timeout_s* x) { return x->maxProcessingTime; }
/* FUNC(zx_b_Timeout_PUT_maxProcessingTime) */
void zx_b_Timeout_PUT_maxProcessingTime(struct zx_b_Timeout_s* x, struct zx_str* y) { x->maxProcessingTime = y; }
/* FUNC(zx_b_Timeout_GET_Id) */
struct zx_str* zx_b_Timeout_GET_Id(struct zx_b_Timeout_s* x) { return x->Id; }
/* FUNC(zx_b_Timeout_PUT_Id) */
void zx_b_Timeout_PUT_Id(struct zx_b_Timeout_s* x, struct zx_str* y) { x->Id = y; }
/* FUNC(zx_b_Timeout_GET_actor) */
struct zx_str* zx_b_Timeout_GET_actor(struct zx_b_Timeout_s* x) { return x->actor; }
/* FUNC(zx_b_Timeout_PUT_actor) */
void zx_b_Timeout_PUT_actor(struct zx_b_Timeout_s* x, struct zx_str* y) { x->actor = y; }
/* FUNC(zx_b_Timeout_GET_mustUnderstand) */
struct zx_str* zx_b_Timeout_GET_mustUnderstand(struct zx_b_Timeout_s* x) { return x->mustUnderstand; }
/* FUNC(zx_b_Timeout_PUT_mustUnderstand) */
void zx_b_Timeout_PUT_mustUnderstand(struct zx_b_Timeout_s* x, struct zx_str* y) { x->mustUnderstand = y; }







#ifdef ZX_ENA_GETPUT

/* FUNC(zx_b_UsageDirective_NUM_Obligation) */

int zx_b_UsageDirective_NUM_Obligation(struct zx_b_UsageDirective_s* x)
{
  struct zx_xa_Obligation_s* y;
  int n = 0;
  if (!x) return 0;
  for (y = x->Obligation; y; ++n, y = (struct zx_xa_Obligation_s*)y->gg.g.n) ;
  return n;
}

/* FUNC(zx_b_UsageDirective_GET_Obligation) */

struct zx_xa_Obligation_s* zx_b_UsageDirective_GET_Obligation(struct zx_b_UsageDirective_s* x, int n)
{
  struct zx_xa_Obligation_s* y;
  if (!x) return 0;
  for (y = x->Obligation; n>=0 && y; --n, y = (struct zx_xa_Obligation_s*)y->gg.g.n) ;
  return y;
}

/* FUNC(zx_b_UsageDirective_POP_Obligation) */

struct zx_xa_Obligation_s* zx_b_UsageDirective_POP_Obligation(struct zx_b_UsageDirective_s* x)
{
  struct zx_xa_Obligation_s* y;
  if (!x) return 0;
  y = x->Obligation;
  if (y)
    x->Obligation = (struct zx_xa_Obligation_s*)y->gg.g.n;
  return y;
}

/* FUNC(zx_b_UsageDirective_PUSH_Obligation) */

void zx_b_UsageDirective_PUSH_Obligation(struct zx_b_UsageDirective_s* x, struct zx_xa_Obligation_s* z)
{
  if (!x || !z) return;
  z->gg.g.n = &x->Obligation->gg.g;
  x->Obligation = z;
}

/* FUNC(zx_b_UsageDirective_REV_Obligation) */

void zx_b_UsageDirective_REV_Obligation(struct zx_b_UsageDirective_s* x)
{
  struct zx_xa_Obligation_s* nxt;
  struct zx_xa_Obligation_s* y;
  if (!x) return;
  y = x->Obligation;
  if (!y) return;
  x->Obligation = 0;
  while (y) {
    nxt = (struct zx_xa_Obligation_s*)y->gg.g.n;
    y->gg.g.n = &x->Obligation->gg.g;
    x->Obligation = y;
    y = nxt;
  }
}

/* FUNC(zx_b_UsageDirective_PUT_Obligation) */

void zx_b_UsageDirective_PUT_Obligation(struct zx_b_UsageDirective_s* x, int n, struct zx_xa_Obligation_s* z)
{
  struct zx_xa_Obligation_s* y;
  if (!x || !z) return;
  y = x->Obligation;
  if (!y) return;
  switch (n) {
  case 0:
    z->gg.g.n = y->gg.g.n;
    x->Obligation = z;
    return;
  default:
    for (; n > 1 && y->gg.g.n; --n, y = (struct zx_xa_Obligation_s*)y->gg.g.n) ;
    if (!y->gg.g.n) return;
    z->gg.g.n = y->gg.g.n->n;
    y->gg.g.n = &z->gg.g;
  }
}

/* FUNC(zx_b_UsageDirective_ADD_Obligation) */

void zx_b_UsageDirective_ADD_Obligation(struct zx_b_UsageDirective_s* x, int n, struct zx_xa_Obligation_s* z)
{
  struct zx_xa_Obligation_s* y;
  if (!x || !z) return;
  switch (n) {
  case 0:
  add_to_start:
    z->gg.g.n = &x->Obligation->gg.g;
    x->Obligation = z;
    return;
  case -1:
    y = x->Obligation;
    if (!y) goto add_to_start;
    for (; y->gg.g.n; y = (struct zx_xa_Obligation_s*)y->gg.g.n) ;
    break;
  default:
    for (y = x->Obligation; n > 1 && y; --n, y = (struct zx_xa_Obligation_s*)y->gg.g.n) ;
    if (!y) return;
  }
  z->gg.g.n = y->gg.g.n;
  y->gg.g.n = &z->gg.g;
}

/* FUNC(zx_b_UsageDirective_DEL_Obligation) */

void zx_b_UsageDirective_DEL_Obligation(struct zx_b_UsageDirective_s* x, int n)
{
  struct zx_xa_Obligation_s* y;
  if (!x) return;
  switch (n) {
  case 0:
    x->Obligation = (struct zx_xa_Obligation_s*)x->Obligation->gg.g.n;
    return;
  case -1:
    y = (struct zx_xa_Obligation_s*)x->Obligation;
    if (!y) return;
    for (; y->gg.g.n; y = (struct zx_xa_Obligation_s*)y->gg.g.n) ;
    break;
  default:
    for (y = x->Obligation; n > 1 && y->gg.g.n; --n, y = (struct zx_xa_Obligation_s*)y->gg.g.n) ;
    if (!y->gg.g.n) return;
  }
  y->gg.g.n = y->gg.g.n->n;
}

#endif



#ifdef ZX_ENA_GETPUT

/* FUNC(zx_b_UsageDirective_NUM_Dict) */

int zx_b_UsageDirective_NUM_Dict(struct zx_b_UsageDirective_s* x)
{
  struct zx_tas3sol_Dict_s* y;
  int n = 0;
  if (!x) return 0;
  for (y = x->Dict; y; ++n, y = (struct zx_tas3sol_Dict_s*)y->gg.g.n) ;
  return n;
}

/* FUNC(zx_b_UsageDirective_GET_Dict) */

struct zx_tas3sol_Dict_s* zx_b_UsageDirective_GET_Dict(struct zx_b_UsageDirective_s* x, int n)
{
  struct zx_tas3sol_Dict_s* y;
  if (!x) return 0;
  for (y = x->Dict; n>=0 && y; --n, y = (struct zx_tas3sol_Dict_s*)y->gg.g.n) ;
  return y;
}

/* FUNC(zx_b_UsageDirective_POP_Dict) */

struct zx_tas3sol_Dict_s* zx_b_UsageDirective_POP_Dict(struct zx_b_UsageDirective_s* x)
{
  struct zx_tas3sol_Dict_s* y;
  if (!x) return 0;
  y = x->Dict;
  if (y)
    x->Dict = (struct zx_tas3sol_Dict_s*)y->gg.g.n;
  return y;
}

/* FUNC(zx_b_UsageDirective_PUSH_Dict) */

void zx_b_UsageDirective_PUSH_Dict(struct zx_b_UsageDirective_s* x, struct zx_tas3sol_Dict_s* z)
{
  if (!x || !z) return;
  z->gg.g.n = &x->Dict->gg.g;
  x->Dict = z;
}

/* FUNC(zx_b_UsageDirective_REV_Dict) */

void zx_b_UsageDirective_REV_Dict(struct zx_b_UsageDirective_s* x)
{
  struct zx_tas3sol_Dict_s* nxt;
  struct zx_tas3sol_Dict_s* y;
  if (!x) return;
  y = x->Dict;
  if (!y) return;
  x->Dict = 0;
  while (y) {
    nxt = (struct zx_tas3sol_Dict_s*)y->gg.g.n;
    y->gg.g.n = &x->Dict->gg.g;
    x->Dict = y;
    y = nxt;
  }
}

/* FUNC(zx_b_UsageDirective_PUT_Dict) */

void zx_b_UsageDirective_PUT_Dict(struct zx_b_UsageDirective_s* x, int n, struct zx_tas3sol_Dict_s* z)
{
  struct zx_tas3sol_Dict_s* y;
  if (!x || !z) return;
  y = x->Dict;
  if (!y) return;
  switch (n) {
  case 0:
    z->gg.g.n = y->gg.g.n;
    x->Dict = z;
    return;
  default:
    for (; n > 1 && y->gg.g.n; --n, y = (struct zx_tas3sol_Dict_s*)y->gg.g.n) ;
    if (!y->gg.g.n) return;
    z->gg.g.n = y->gg.g.n->n;
    y->gg.g.n = &z->gg.g;
  }
}

/* FUNC(zx_b_UsageDirective_ADD_Dict) */

void zx_b_UsageDirective_ADD_Dict(struct zx_b_UsageDirective_s* x, int n, struct zx_tas3sol_Dict_s* z)
{
  struct zx_tas3sol_Dict_s* y;
  if (!x || !z) return;
  switch (n) {
  case 0:
  add_to_start:
    z->gg.g.n = &x->Dict->gg.g;
    x->Dict = z;
    return;
  case -1:
    y = x->Dict;
    if (!y) goto add_to_start;
    for (; y->gg.g.n; y = (struct zx_tas3sol_Dict_s*)y->gg.g.n) ;
    break;
  default:
    for (y = x->Dict; n > 1 && y; --n, y = (struct zx_tas3sol_Dict_s*)y->gg.g.n) ;
    if (!y) return;
  }
  z->gg.g.n = y->gg.g.n;
  y->gg.g.n = &z->gg.g;
}

/* FUNC(zx_b_UsageDirective_DEL_Dict) */

void zx_b_UsageDirective_DEL_Dict(struct zx_b_UsageDirective_s* x, int n)
{
  struct zx_tas3sol_Dict_s* y;
  if (!x) return;
  switch (n) {
  case 0:
    x->Dict = (struct zx_tas3sol_Dict_s*)x->Dict->gg.g.n;
    return;
  case -1:
    y = (struct zx_tas3sol_Dict_s*)x->Dict;
    if (!y) return;
    for (; y->gg.g.n; y = (struct zx_tas3sol_Dict_s*)y->gg.g.n) ;
    break;
  default:
    for (y = x->Dict; n > 1 && y->gg.g.n; --n, y = (struct zx_tas3sol_Dict_s*)y->gg.g.n) ;
    if (!y->gg.g.n) return;
  }
  y->gg.g.n = y->gg.g.n->n;
}

#endif

/* FUNC(zx_b_UsageDirective_GET_id) */
struct zx_str* zx_b_UsageDirective_GET_id(struct zx_b_UsageDirective_s* x) { return x->id; }
/* FUNC(zx_b_UsageDirective_PUT_id) */
void zx_b_UsageDirective_PUT_id(struct zx_b_UsageDirective_s* x, struct zx_str* y) { x->id = y; }
/* FUNC(zx_b_UsageDirective_GET_ref) */
struct zx_str* zx_b_UsageDirective_GET_ref(struct zx_b_UsageDirective_s* x) { return x->ref; }
/* FUNC(zx_b_UsageDirective_PUT_ref) */
void zx_b_UsageDirective_PUT_ref(struct zx_b_UsageDirective_s* x, struct zx_str* y) { x->ref = y; }
/* FUNC(zx_b_UsageDirective_GET_Id) */
struct zx_str* zx_b_UsageDirective_GET_Id(struct zx_b_UsageDirective_s* x) { return x->Id; }
/* FUNC(zx_b_UsageDirective_PUT_Id) */
void zx_b_UsageDirective_PUT_Id(struct zx_b_UsageDirective_s* x, struct zx_str* y) { x->Id = y; }
/* FUNC(zx_b_UsageDirective_GET_actor) */
struct zx_str* zx_b_UsageDirective_GET_actor(struct zx_b_UsageDirective_s* x) { return x->actor; }
/* FUNC(zx_b_UsageDirective_PUT_actor) */
void zx_b_UsageDirective_PUT_actor(struct zx_b_UsageDirective_s* x, struct zx_str* y) { x->actor = y; }
/* FUNC(zx_b_UsageDirective_GET_mustUnderstand) */
struct zx_str* zx_b_UsageDirective_GET_mustUnderstand(struct zx_b_UsageDirective_s* x) { return x->mustUnderstand; }
/* FUNC(zx_b_UsageDirective_PUT_mustUnderstand) */
void zx_b_UsageDirective_PUT_mustUnderstand(struct zx_b_UsageDirective_s* x, struct zx_str* y) { x->mustUnderstand = y; }







#ifdef ZX_ENA_GETPUT

/* FUNC(zx_b_UserInteraction_NUM_InteractionService) */

int zx_b_UserInteraction_NUM_InteractionService(struct zx_b_UserInteraction_s* x)
{
  struct zx_b_InteractionService_s* y;
  int n = 0;
  if (!x) return 0;
  for (y = x->InteractionService; y; ++n, y = (struct zx_b_InteractionService_s*)y->gg.g.n) ;
  return n;
}

/* FUNC(zx_b_UserInteraction_GET_InteractionService) */

struct zx_b_InteractionService_s* zx_b_UserInteraction_GET_InteractionService(struct zx_b_UserInteraction_s* x, int n)
{
  struct zx_b_InteractionService_s* y;
  if (!x) return 0;
  for (y = x->InteractionService; n>=0 && y; --n, y = (struct zx_b_InteractionService_s*)y->gg.g.n) ;
  return y;
}

/* FUNC(zx_b_UserInteraction_POP_InteractionService) */

struct zx_b_InteractionService_s* zx_b_UserInteraction_POP_InteractionService(struct zx_b_UserInteraction_s* x)
{
  struct zx_b_InteractionService_s* y;
  if (!x) return 0;
  y = x->InteractionService;
  if (y)
    x->InteractionService = (struct zx_b_InteractionService_s*)y->gg.g.n;
  return y;
}

/* FUNC(zx_b_UserInteraction_PUSH_InteractionService) */

void zx_b_UserInteraction_PUSH_InteractionService(struct zx_b_UserInteraction_s* x, struct zx_b_InteractionService_s* z)
{
  if (!x || !z) return;
  z->gg.g.n = &x->InteractionService->gg.g;
  x->InteractionService = z;
}

/* FUNC(zx_b_UserInteraction_REV_InteractionService) */

void zx_b_UserInteraction_REV_InteractionService(struct zx_b_UserInteraction_s* x)
{
  struct zx_b_InteractionService_s* nxt;
  struct zx_b_InteractionService_s* y;
  if (!x) return;
  y = x->InteractionService;
  if (!y) return;
  x->InteractionService = 0;
  while (y) {
    nxt = (struct zx_b_InteractionService_s*)y->gg.g.n;
    y->gg.g.n = &x->InteractionService->gg.g;
    x->InteractionService = y;
    y = nxt;
  }
}

/* FUNC(zx_b_UserInteraction_PUT_InteractionService) */

void zx_b_UserInteraction_PUT_InteractionService(struct zx_b_UserInteraction_s* x, int n, struct zx_b_InteractionService_s* z)
{
  struct zx_b_InteractionService_s* y;
  if (!x || !z) return;
  y = x->InteractionService;
  if (!y) return;
  switch (n) {
  case 0:
    z->gg.g.n = y->gg.g.n;
    x->InteractionService = z;
    return;
  default:
    for (; n > 1 && y->gg.g.n; --n, y = (struct zx_b_InteractionService_s*)y->gg.g.n) ;
    if (!y->gg.g.n) return;
    z->gg.g.n = y->gg.g.n->n;
    y->gg.g.n = &z->gg.g;
  }
}

/* FUNC(zx_b_UserInteraction_ADD_InteractionService) */

void zx_b_UserInteraction_ADD_InteractionService(struct zx_b_UserInteraction_s* x, int n, struct zx_b_InteractionService_s* z)
{
  struct zx_b_InteractionService_s* y;
  if (!x || !z) return;
  switch (n) {
  case 0:
  add_to_start:
    z->gg.g.n = &x->InteractionService->gg.g;
    x->InteractionService = z;
    return;
  case -1:
    y = x->InteractionService;
    if (!y) goto add_to_start;
    for (; y->gg.g.n; y = (struct zx_b_InteractionService_s*)y->gg.g.n) ;
    break;
  default:
    for (y = x->InteractionService; n > 1 && y; --n, y = (struct zx_b_InteractionService_s*)y->gg.g.n) ;
    if (!y) return;
  }
  z->gg.g.n = y->gg.g.n;
  y->gg.g.n = &z->gg.g;
}

/* FUNC(zx_b_UserInteraction_DEL_InteractionService) */

void zx_b_UserInteraction_DEL_InteractionService(struct zx_b_UserInteraction_s* x, int n)
{
  struct zx_b_InteractionService_s* y;
  if (!x) return;
  switch (n) {
  case 0:
    x->InteractionService = (struct zx_b_InteractionService_s*)x->InteractionService->gg.g.n;
    return;
  case -1:
    y = (struct zx_b_InteractionService_s*)x->InteractionService;
    if (!y) return;
    for (; y->gg.g.n; y = (struct zx_b_InteractionService_s*)y->gg.g.n) ;
    break;
  default:
    for (y = x->InteractionService; n > 1 && y->gg.g.n; --n, y = (struct zx_b_InteractionService_s*)y->gg.g.n) ;
    if (!y->gg.g.n) return;
  }
  y->gg.g.n = y->gg.g.n->n;
}

#endif

/* FUNC(zx_b_UserInteraction_GET_id) */
struct zx_str* zx_b_UserInteraction_GET_id(struct zx_b_UserInteraction_s* x) { return x->id; }
/* FUNC(zx_b_UserInteraction_PUT_id) */
void zx_b_UserInteraction_PUT_id(struct zx_b_UserInteraction_s* x, struct zx_str* y) { x->id = y; }
/* FUNC(zx_b_UserInteraction_GET_interact) */
struct zx_str* zx_b_UserInteraction_GET_interact(struct zx_b_UserInteraction_s* x) { return x->interact; }
/* FUNC(zx_b_UserInteraction_PUT_interact) */
void zx_b_UserInteraction_PUT_interact(struct zx_b_UserInteraction_s* x, struct zx_str* y) { x->interact = y; }
/* FUNC(zx_b_UserInteraction_GET_language) */
struct zx_str* zx_b_UserInteraction_GET_language(struct zx_b_UserInteraction_s* x) { return x->language; }
/* FUNC(zx_b_UserInteraction_PUT_language) */
void zx_b_UserInteraction_PUT_language(struct zx_b_UserInteraction_s* x, struct zx_str* y) { x->language = y; }
/* FUNC(zx_b_UserInteraction_GET_maxInteractTime) */
struct zx_str* zx_b_UserInteraction_GET_maxInteractTime(struct zx_b_UserInteraction_s* x) { return x->maxInteractTime; }
/* FUNC(zx_b_UserInteraction_PUT_maxInteractTime) */
void zx_b_UserInteraction_PUT_maxInteractTime(struct zx_b_UserInteraction_s* x, struct zx_str* y) { x->maxInteractTime = y; }
/* FUNC(zx_b_UserInteraction_GET_redirect) */
struct zx_str* zx_b_UserInteraction_GET_redirect(struct zx_b_UserInteraction_s* x) { return x->redirect; }
/* FUNC(zx_b_UserInteraction_PUT_redirect) */
void zx_b_UserInteraction_PUT_redirect(struct zx_b_UserInteraction_s* x, struct zx_str* y) { x->redirect = y; }
/* FUNC(zx_b_UserInteraction_GET_Id) */
struct zx_str* zx_b_UserInteraction_GET_Id(struct zx_b_UserInteraction_s* x) { return x->Id; }
/* FUNC(zx_b_UserInteraction_PUT_Id) */
void zx_b_UserInteraction_PUT_Id(struct zx_b_UserInteraction_s* x, struct zx_str* y) { x->Id = y; }
/* FUNC(zx_b_UserInteraction_GET_actor) */
struct zx_str* zx_b_UserInteraction_GET_actor(struct zx_b_UserInteraction_s* x) { return x->actor; }
/* FUNC(zx_b_UserInteraction_PUT_actor) */
void zx_b_UserInteraction_PUT_actor(struct zx_b_UserInteraction_s* x, struct zx_str* y) { x->actor = y; }
/* FUNC(zx_b_UserInteraction_GET_mustUnderstand) */
struct zx_str* zx_b_UserInteraction_GET_mustUnderstand(struct zx_b_UserInteraction_s* x) { return x->mustUnderstand; }
/* FUNC(zx_b_UserInteraction_PUT_mustUnderstand) */
void zx_b_UserInteraction_PUT_mustUnderstand(struct zx_b_UserInteraction_s* x, struct zx_str* y) { x->mustUnderstand = y; }





/* EOF -- c/zx-b-getput.c */
