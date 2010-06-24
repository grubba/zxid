/* c/zx-sec-getput.c - WARNING: This file was automatically generated. DO NOT EDIT!
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
#include "c/zx-sec-data.h"



#ifdef ZX_ENA_GETPUT

/* FUNC(zx_sec_Token_NUM_Assertion) */

int zx_sec_Token_NUM_Assertion(struct zx_sec_Token_s* x)
{
  struct zx_sa_Assertion_s* y;
  int n = 0;
  if (!x) return 0;
  for (y = x->Assertion; y; ++n, y = (struct zx_sa_Assertion_s*)y->gg.g.n) ;
  return n;
}

/* FUNC(zx_sec_Token_GET_Assertion) */

struct zx_sa_Assertion_s* zx_sec_Token_GET_Assertion(struct zx_sec_Token_s* x, int n)
{
  struct zx_sa_Assertion_s* y;
  if (!x) return 0;
  for (y = x->Assertion; n>=0 && y; --n, y = (struct zx_sa_Assertion_s*)y->gg.g.n) ;
  return y;
}

/* FUNC(zx_sec_Token_POP_Assertion) */

struct zx_sa_Assertion_s* zx_sec_Token_POP_Assertion(struct zx_sec_Token_s* x)
{
  struct zx_sa_Assertion_s* y;
  if (!x) return 0;
  y = x->Assertion;
  if (y)
    x->Assertion = (struct zx_sa_Assertion_s*)y->gg.g.n;
  return y;
}

/* FUNC(zx_sec_Token_PUSH_Assertion) */

void zx_sec_Token_PUSH_Assertion(struct zx_sec_Token_s* x, struct zx_sa_Assertion_s* z)
{
  if (!x || !z) return;
  z->gg.g.n = &x->Assertion->gg.g;
  x->Assertion = z;
}

/* FUNC(zx_sec_Token_REV_Assertion) */

void zx_sec_Token_REV_Assertion(struct zx_sec_Token_s* x)
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

/* FUNC(zx_sec_Token_PUT_Assertion) */

void zx_sec_Token_PUT_Assertion(struct zx_sec_Token_s* x, int n, struct zx_sa_Assertion_s* z)
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

/* FUNC(zx_sec_Token_ADD_Assertion) */

void zx_sec_Token_ADD_Assertion(struct zx_sec_Token_s* x, int n, struct zx_sa_Assertion_s* z)
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

/* FUNC(zx_sec_Token_DEL_Assertion) */

void zx_sec_Token_DEL_Assertion(struct zx_sec_Token_s* x, int n)
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

/* FUNC(zx_sec_Token_NUM_EncryptedAssertion) */

int zx_sec_Token_NUM_EncryptedAssertion(struct zx_sec_Token_s* x)
{
  struct zx_sa_EncryptedAssertion_s* y;
  int n = 0;
  if (!x) return 0;
  for (y = x->EncryptedAssertion; y; ++n, y = (struct zx_sa_EncryptedAssertion_s*)y->gg.g.n) ;
  return n;
}

/* FUNC(zx_sec_Token_GET_EncryptedAssertion) */

struct zx_sa_EncryptedAssertion_s* zx_sec_Token_GET_EncryptedAssertion(struct zx_sec_Token_s* x, int n)
{
  struct zx_sa_EncryptedAssertion_s* y;
  if (!x) return 0;
  for (y = x->EncryptedAssertion; n>=0 && y; --n, y = (struct zx_sa_EncryptedAssertion_s*)y->gg.g.n) ;
  return y;
}

/* FUNC(zx_sec_Token_POP_EncryptedAssertion) */

struct zx_sa_EncryptedAssertion_s* zx_sec_Token_POP_EncryptedAssertion(struct zx_sec_Token_s* x)
{
  struct zx_sa_EncryptedAssertion_s* y;
  if (!x) return 0;
  y = x->EncryptedAssertion;
  if (y)
    x->EncryptedAssertion = (struct zx_sa_EncryptedAssertion_s*)y->gg.g.n;
  return y;
}

/* FUNC(zx_sec_Token_PUSH_EncryptedAssertion) */

void zx_sec_Token_PUSH_EncryptedAssertion(struct zx_sec_Token_s* x, struct zx_sa_EncryptedAssertion_s* z)
{
  if (!x || !z) return;
  z->gg.g.n = &x->EncryptedAssertion->gg.g;
  x->EncryptedAssertion = z;
}

/* FUNC(zx_sec_Token_REV_EncryptedAssertion) */

void zx_sec_Token_REV_EncryptedAssertion(struct zx_sec_Token_s* x)
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

/* FUNC(zx_sec_Token_PUT_EncryptedAssertion) */

void zx_sec_Token_PUT_EncryptedAssertion(struct zx_sec_Token_s* x, int n, struct zx_sa_EncryptedAssertion_s* z)
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

/* FUNC(zx_sec_Token_ADD_EncryptedAssertion) */

void zx_sec_Token_ADD_EncryptedAssertion(struct zx_sec_Token_s* x, int n, struct zx_sa_EncryptedAssertion_s* z)
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

/* FUNC(zx_sec_Token_DEL_EncryptedAssertion) */

void zx_sec_Token_DEL_EncryptedAssertion(struct zx_sec_Token_s* x, int n)
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

/* FUNC(zx_sec_Token_NUM_sa11_Assertion) */

int zx_sec_Token_NUM_sa11_Assertion(struct zx_sec_Token_s* x)
{
  struct zx_sa11_Assertion_s* y;
  int n = 0;
  if (!x) return 0;
  for (y = x->sa11_Assertion; y; ++n, y = (struct zx_sa11_Assertion_s*)y->gg.g.n) ;
  return n;
}

/* FUNC(zx_sec_Token_GET_sa11_Assertion) */

struct zx_sa11_Assertion_s* zx_sec_Token_GET_sa11_Assertion(struct zx_sec_Token_s* x, int n)
{
  struct zx_sa11_Assertion_s* y;
  if (!x) return 0;
  for (y = x->sa11_Assertion; n>=0 && y; --n, y = (struct zx_sa11_Assertion_s*)y->gg.g.n) ;
  return y;
}

/* FUNC(zx_sec_Token_POP_sa11_Assertion) */

struct zx_sa11_Assertion_s* zx_sec_Token_POP_sa11_Assertion(struct zx_sec_Token_s* x)
{
  struct zx_sa11_Assertion_s* y;
  if (!x) return 0;
  y = x->sa11_Assertion;
  if (y)
    x->sa11_Assertion = (struct zx_sa11_Assertion_s*)y->gg.g.n;
  return y;
}

/* FUNC(zx_sec_Token_PUSH_sa11_Assertion) */

void zx_sec_Token_PUSH_sa11_Assertion(struct zx_sec_Token_s* x, struct zx_sa11_Assertion_s* z)
{
  if (!x || !z) return;
  z->gg.g.n = &x->sa11_Assertion->gg.g;
  x->sa11_Assertion = z;
}

/* FUNC(zx_sec_Token_REV_sa11_Assertion) */

void zx_sec_Token_REV_sa11_Assertion(struct zx_sec_Token_s* x)
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

/* FUNC(zx_sec_Token_PUT_sa11_Assertion) */

void zx_sec_Token_PUT_sa11_Assertion(struct zx_sec_Token_s* x, int n, struct zx_sa11_Assertion_s* z)
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

/* FUNC(zx_sec_Token_ADD_sa11_Assertion) */

void zx_sec_Token_ADD_sa11_Assertion(struct zx_sec_Token_s* x, int n, struct zx_sa11_Assertion_s* z)
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

/* FUNC(zx_sec_Token_DEL_sa11_Assertion) */

void zx_sec_Token_DEL_sa11_Assertion(struct zx_sec_Token_s* x, int n)
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

/* FUNC(zx_sec_Token_NUM_ff12_Assertion) */

int zx_sec_Token_NUM_ff12_Assertion(struct zx_sec_Token_s* x)
{
  struct zx_ff12_Assertion_s* y;
  int n = 0;
  if (!x) return 0;
  for (y = x->ff12_Assertion; y; ++n, y = (struct zx_ff12_Assertion_s*)y->gg.g.n) ;
  return n;
}

/* FUNC(zx_sec_Token_GET_ff12_Assertion) */

struct zx_ff12_Assertion_s* zx_sec_Token_GET_ff12_Assertion(struct zx_sec_Token_s* x, int n)
{
  struct zx_ff12_Assertion_s* y;
  if (!x) return 0;
  for (y = x->ff12_Assertion; n>=0 && y; --n, y = (struct zx_ff12_Assertion_s*)y->gg.g.n) ;
  return y;
}

/* FUNC(zx_sec_Token_POP_ff12_Assertion) */

struct zx_ff12_Assertion_s* zx_sec_Token_POP_ff12_Assertion(struct zx_sec_Token_s* x)
{
  struct zx_ff12_Assertion_s* y;
  if (!x) return 0;
  y = x->ff12_Assertion;
  if (y)
    x->ff12_Assertion = (struct zx_ff12_Assertion_s*)y->gg.g.n;
  return y;
}

/* FUNC(zx_sec_Token_PUSH_ff12_Assertion) */

void zx_sec_Token_PUSH_ff12_Assertion(struct zx_sec_Token_s* x, struct zx_ff12_Assertion_s* z)
{
  if (!x || !z) return;
  z->gg.g.n = &x->ff12_Assertion->gg.g;
  x->ff12_Assertion = z;
}

/* FUNC(zx_sec_Token_REV_ff12_Assertion) */

void zx_sec_Token_REV_ff12_Assertion(struct zx_sec_Token_s* x)
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

/* FUNC(zx_sec_Token_PUT_ff12_Assertion) */

void zx_sec_Token_PUT_ff12_Assertion(struct zx_sec_Token_s* x, int n, struct zx_ff12_Assertion_s* z)
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

/* FUNC(zx_sec_Token_ADD_ff12_Assertion) */

void zx_sec_Token_ADD_ff12_Assertion(struct zx_sec_Token_s* x, int n, struct zx_ff12_Assertion_s* z)
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

/* FUNC(zx_sec_Token_DEL_ff12_Assertion) */

void zx_sec_Token_DEL_ff12_Assertion(struct zx_sec_Token_s* x, int n)
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

/* FUNC(zx_sec_Token_GET_id) */
struct zx_str* zx_sec_Token_GET_id(struct zx_sec_Token_s* x) { return x->id; }
/* FUNC(zx_sec_Token_PUT_id) */
void zx_sec_Token_PUT_id(struct zx_sec_Token_s* x, struct zx_str* y) { x->id = y; }
/* FUNC(zx_sec_Token_GET_ref) */
struct zx_str* zx_sec_Token_GET_ref(struct zx_sec_Token_s* x) { return x->ref; }
/* FUNC(zx_sec_Token_PUT_ref) */
void zx_sec_Token_PUT_ref(struct zx_sec_Token_s* x, struct zx_str* y) { x->ref = y; }
/* FUNC(zx_sec_Token_GET_usage) */
struct zx_str* zx_sec_Token_GET_usage(struct zx_sec_Token_s* x) { return x->usage; }
/* FUNC(zx_sec_Token_PUT_usage) */
void zx_sec_Token_PUT_usage(struct zx_sec_Token_s* x, struct zx_str* y) { x->usage = y; }





/* FUNC(zx_sec_TokenPolicy_GET_issueTo) */
struct zx_str* zx_sec_TokenPolicy_GET_issueTo(struct zx_sec_TokenPolicy_s* x) { return x->issueTo; }
/* FUNC(zx_sec_TokenPolicy_PUT_issueTo) */
void zx_sec_TokenPolicy_PUT_issueTo(struct zx_sec_TokenPolicy_s* x, struct zx_str* y) { x->issueTo = y; }
/* FUNC(zx_sec_TokenPolicy_GET_type) */
struct zx_str* zx_sec_TokenPolicy_GET_type(struct zx_sec_TokenPolicy_s* x) { return x->type; }
/* FUNC(zx_sec_TokenPolicy_PUT_type) */
void zx_sec_TokenPolicy_PUT_type(struct zx_sec_TokenPolicy_s* x, struct zx_str* y) { x->type = y; }
/* FUNC(zx_sec_TokenPolicy_GET_validUntil) */
struct zx_str* zx_sec_TokenPolicy_GET_validUntil(struct zx_sec_TokenPolicy_s* x) { return x->validUntil; }
/* FUNC(zx_sec_TokenPolicy_PUT_validUntil) */
void zx_sec_TokenPolicy_PUT_validUntil(struct zx_sec_TokenPolicy_s* x, struct zx_str* y) { x->validUntil = y; }
/* FUNC(zx_sec_TokenPolicy_GET_wantDSEPR) */
struct zx_str* zx_sec_TokenPolicy_GET_wantDSEPR(struct zx_sec_TokenPolicy_s* x) { return x->wantDSEPR; }
/* FUNC(zx_sec_TokenPolicy_PUT_wantDSEPR) */
void zx_sec_TokenPolicy_PUT_wantDSEPR(struct zx_sec_TokenPolicy_s* x, struct zx_str* y) { x->wantDSEPR = y; }





/* FUNC(zx_sec_TransitedProvider_GET_confirmationURI) */
struct zx_str* zx_sec_TransitedProvider_GET_confirmationURI(struct zx_sec_TransitedProvider_s* x) { return x->confirmationURI; }
/* FUNC(zx_sec_TransitedProvider_PUT_confirmationURI) */
void zx_sec_TransitedProvider_PUT_confirmationURI(struct zx_sec_TransitedProvider_s* x, struct zx_str* y) { x->confirmationURI = y; }
/* FUNC(zx_sec_TransitedProvider_GET_timeStamp) */
struct zx_str* zx_sec_TransitedProvider_GET_timeStamp(struct zx_sec_TransitedProvider_s* x) { return x->timeStamp; }
/* FUNC(zx_sec_TransitedProvider_PUT_timeStamp) */
void zx_sec_TransitedProvider_PUT_timeStamp(struct zx_sec_TransitedProvider_s* x, struct zx_str* y) { x->timeStamp = y; }







#ifdef ZX_ENA_GETPUT

/* FUNC(zx_sec_TransitedProviderPath_NUM_TransitedProvider) */

int zx_sec_TransitedProviderPath_NUM_TransitedProvider(struct zx_sec_TransitedProviderPath_s* x)
{
  struct zx_sec_TransitedProvider_s* y;
  int n = 0;
  if (!x) return 0;
  for (y = x->TransitedProvider; y; ++n, y = (struct zx_sec_TransitedProvider_s*)y->gg.g.n) ;
  return n;
}

/* FUNC(zx_sec_TransitedProviderPath_GET_TransitedProvider) */

struct zx_sec_TransitedProvider_s* zx_sec_TransitedProviderPath_GET_TransitedProvider(struct zx_sec_TransitedProviderPath_s* x, int n)
{
  struct zx_sec_TransitedProvider_s* y;
  if (!x) return 0;
  for (y = x->TransitedProvider; n>=0 && y; --n, y = (struct zx_sec_TransitedProvider_s*)y->gg.g.n) ;
  return y;
}

/* FUNC(zx_sec_TransitedProviderPath_POP_TransitedProvider) */

struct zx_sec_TransitedProvider_s* zx_sec_TransitedProviderPath_POP_TransitedProvider(struct zx_sec_TransitedProviderPath_s* x)
{
  struct zx_sec_TransitedProvider_s* y;
  if (!x) return 0;
  y = x->TransitedProvider;
  if (y)
    x->TransitedProvider = (struct zx_sec_TransitedProvider_s*)y->gg.g.n;
  return y;
}

/* FUNC(zx_sec_TransitedProviderPath_PUSH_TransitedProvider) */

void zx_sec_TransitedProviderPath_PUSH_TransitedProvider(struct zx_sec_TransitedProviderPath_s* x, struct zx_sec_TransitedProvider_s* z)
{
  if (!x || !z) return;
  z->gg.g.n = &x->TransitedProvider->gg.g;
  x->TransitedProvider = z;
}

/* FUNC(zx_sec_TransitedProviderPath_REV_TransitedProvider) */

void zx_sec_TransitedProviderPath_REV_TransitedProvider(struct zx_sec_TransitedProviderPath_s* x)
{
  struct zx_sec_TransitedProvider_s* nxt;
  struct zx_sec_TransitedProvider_s* y;
  if (!x) return;
  y = x->TransitedProvider;
  if (!y) return;
  x->TransitedProvider = 0;
  while (y) {
    nxt = (struct zx_sec_TransitedProvider_s*)y->gg.g.n;
    y->gg.g.n = &x->TransitedProvider->gg.g;
    x->TransitedProvider = y;
    y = nxt;
  }
}

/* FUNC(zx_sec_TransitedProviderPath_PUT_TransitedProvider) */

void zx_sec_TransitedProviderPath_PUT_TransitedProvider(struct zx_sec_TransitedProviderPath_s* x, int n, struct zx_sec_TransitedProvider_s* z)
{
  struct zx_sec_TransitedProvider_s* y;
  if (!x || !z) return;
  y = x->TransitedProvider;
  if (!y) return;
  switch (n) {
  case 0:
    z->gg.g.n = y->gg.g.n;
    x->TransitedProvider = z;
    return;
  default:
    for (; n > 1 && y->gg.g.n; --n, y = (struct zx_sec_TransitedProvider_s*)y->gg.g.n) ;
    if (!y->gg.g.n) return;
    z->gg.g.n = y->gg.g.n->n;
    y->gg.g.n = &z->gg.g;
  }
}

/* FUNC(zx_sec_TransitedProviderPath_ADD_TransitedProvider) */

void zx_sec_TransitedProviderPath_ADD_TransitedProvider(struct zx_sec_TransitedProviderPath_s* x, int n, struct zx_sec_TransitedProvider_s* z)
{
  struct zx_sec_TransitedProvider_s* y;
  if (!x || !z) return;
  switch (n) {
  case 0:
  add_to_start:
    z->gg.g.n = &x->TransitedProvider->gg.g;
    x->TransitedProvider = z;
    return;
  case -1:
    y = x->TransitedProvider;
    if (!y) goto add_to_start;
    for (; y->gg.g.n; y = (struct zx_sec_TransitedProvider_s*)y->gg.g.n) ;
    break;
  default:
    for (y = x->TransitedProvider; n > 1 && y; --n, y = (struct zx_sec_TransitedProvider_s*)y->gg.g.n) ;
    if (!y) return;
  }
  z->gg.g.n = y->gg.g.n;
  y->gg.g.n = &z->gg.g;
}

/* FUNC(zx_sec_TransitedProviderPath_DEL_TransitedProvider) */

void zx_sec_TransitedProviderPath_DEL_TransitedProvider(struct zx_sec_TransitedProviderPath_s* x, int n)
{
  struct zx_sec_TransitedProvider_s* y;
  if (!x) return;
  switch (n) {
  case 0:
    x->TransitedProvider = (struct zx_sec_TransitedProvider_s*)x->TransitedProvider->gg.g.n;
    return;
  case -1:
    y = (struct zx_sec_TransitedProvider_s*)x->TransitedProvider;
    if (!y) return;
    for (; y->gg.g.n; y = (struct zx_sec_TransitedProvider_s*)y->gg.g.n) ;
    break;
  default:
    for (y = x->TransitedProvider; n > 1 && y->gg.g.n; --n, y = (struct zx_sec_TransitedProvider_s*)y->gg.g.n) ;
    if (!y->gg.g.n) return;
  }
  y->gg.g.n = y->gg.g.n->n;
}

#endif






/* EOF -- c/zx-sec-getput.c */
