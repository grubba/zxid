/* c/zx-sa-getput.c - WARNING: This file was automatically generated. DO NOT EDIT!
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
#include "c/zx-sa-data.h"

/* FUNC(zx_sa_Action_GET_Namespace) */
struct zx_str* zx_sa_Action_GET_Namespace(struct zx_sa_Action_s* x) { return x->Namespace; }
/* FUNC(zx_sa_Action_PUT_Namespace) */
void zx_sa_Action_PUT_Namespace(struct zx_sa_Action_s* x, struct zx_str* y) { x->Namespace = y; }







#ifdef ZX_ENA_GETPUT

/* FUNC(zx_sa_Advice_NUM_AssertionIDRef) */

int zx_sa_Advice_NUM_AssertionIDRef(struct zx_sa_Advice_s* x)
{
  struct zx_elem_s* y;
  int n = 0;
  if (!x) return 0;
  for (y = x->AssertionIDRef; y; ++n, y = (struct zx_elem_s*)y->g.n) ;
  return n;
}

/* FUNC(zx_sa_Advice_GET_AssertionIDRef) */

struct zx_elem_s* zx_sa_Advice_GET_AssertionIDRef(struct zx_sa_Advice_s* x, int n)
{
  struct zx_elem_s* y;
  if (!x) return 0;
  for (y = x->AssertionIDRef; n>=0 && y; --n, y = (struct zx_elem_s*)y->g.n) ;
  return y;
}

/* FUNC(zx_sa_Advice_POP_AssertionIDRef) */

struct zx_elem_s* zx_sa_Advice_POP_AssertionIDRef(struct zx_sa_Advice_s* x)
{
  struct zx_elem_s* y;
  if (!x) return 0;
  y = x->AssertionIDRef;
  if (y)
    x->AssertionIDRef = (struct zx_elem_s*)y->g.n;
  return y;
}

/* FUNC(zx_sa_Advice_PUSH_AssertionIDRef) */

void zx_sa_Advice_PUSH_AssertionIDRef(struct zx_sa_Advice_s* x, struct zx_elem_s* z)
{
  if (!x || !z) return;
  z->g.n = &x->AssertionIDRef->g;
  x->AssertionIDRef = z;
}

/* FUNC(zx_sa_Advice_REV_AssertionIDRef) */

void zx_sa_Advice_REV_AssertionIDRef(struct zx_sa_Advice_s* x)
{
  struct zx_elem_s* nxt;
  struct zx_elem_s* y;
  if (!x) return;
  y = x->AssertionIDRef;
  if (!y) return;
  x->AssertionIDRef = 0;
  while (y) {
    nxt = (struct zx_elem_s*)y->g.n;
    y->g.n = &x->AssertionIDRef->g;
    x->AssertionIDRef = y;
    y = nxt;
  }
}

/* FUNC(zx_sa_Advice_PUT_AssertionIDRef) */

void zx_sa_Advice_PUT_AssertionIDRef(struct zx_sa_Advice_s* x, int n, struct zx_elem_s* z)
{
  struct zx_elem_s* y;
  if (!x || !z) return;
  y = x->AssertionIDRef;
  if (!y) return;
  switch (n) {
  case 0:
    z->g.n = y->g.n;
    x->AssertionIDRef = z;
    return;
  default:
    for (; n > 1 && y->g.n; --n, y = (struct zx_elem_s*)y->g.n) ;
    if (!y->g.n) return;
    z->g.n = y->g.n->n;
    y->g.n = &z->g;
  }
}

/* FUNC(zx_sa_Advice_ADD_AssertionIDRef) */

void zx_sa_Advice_ADD_AssertionIDRef(struct zx_sa_Advice_s* x, int n, struct zx_elem_s* z)
{
  struct zx_elem_s* y;
  if (!x || !z) return;
  switch (n) {
  case 0:
  add_to_start:
    z->g.n = &x->AssertionIDRef->g;
    x->AssertionIDRef = z;
    return;
  case -1:
    y = x->AssertionIDRef;
    if (!y) goto add_to_start;
    for (; y->g.n; y = (struct zx_elem_s*)y->g.n) ;
    break;
  default:
    for (y = x->AssertionIDRef; n > 1 && y; --n, y = (struct zx_elem_s*)y->g.n) ;
    if (!y) return;
  }
  z->g.n = y->g.n;
  y->g.n = &z->g;
}

/* FUNC(zx_sa_Advice_DEL_AssertionIDRef) */

void zx_sa_Advice_DEL_AssertionIDRef(struct zx_sa_Advice_s* x, int n)
{
  struct zx_elem_s* y;
  if (!x) return;
  switch (n) {
  case 0:
    x->AssertionIDRef = (struct zx_elem_s*)x->AssertionIDRef->g.n;
    return;
  case -1:
    y = (struct zx_elem_s*)x->AssertionIDRef;
    if (!y) return;
    for (; y->g.n; y = (struct zx_elem_s*)y->g.n) ;
    break;
  default:
    for (y = x->AssertionIDRef; n > 1 && y->g.n; --n, y = (struct zx_elem_s*)y->g.n) ;
    if (!y->g.n) return;
  }
  y->g.n = y->g.n->n;
}

#endif



#ifdef ZX_ENA_GETPUT

/* FUNC(zx_sa_Advice_NUM_AssertionURIRef) */

int zx_sa_Advice_NUM_AssertionURIRef(struct zx_sa_Advice_s* x)
{
  struct zx_elem_s* y;
  int n = 0;
  if (!x) return 0;
  for (y = x->AssertionURIRef; y; ++n, y = (struct zx_elem_s*)y->g.n) ;
  return n;
}

/* FUNC(zx_sa_Advice_GET_AssertionURIRef) */

struct zx_elem_s* zx_sa_Advice_GET_AssertionURIRef(struct zx_sa_Advice_s* x, int n)
{
  struct zx_elem_s* y;
  if (!x) return 0;
  for (y = x->AssertionURIRef; n>=0 && y; --n, y = (struct zx_elem_s*)y->g.n) ;
  return y;
}

/* FUNC(zx_sa_Advice_POP_AssertionURIRef) */

struct zx_elem_s* zx_sa_Advice_POP_AssertionURIRef(struct zx_sa_Advice_s* x)
{
  struct zx_elem_s* y;
  if (!x) return 0;
  y = x->AssertionURIRef;
  if (y)
    x->AssertionURIRef = (struct zx_elem_s*)y->g.n;
  return y;
}

/* FUNC(zx_sa_Advice_PUSH_AssertionURIRef) */

void zx_sa_Advice_PUSH_AssertionURIRef(struct zx_sa_Advice_s* x, struct zx_elem_s* z)
{
  if (!x || !z) return;
  z->g.n = &x->AssertionURIRef->g;
  x->AssertionURIRef = z;
}

/* FUNC(zx_sa_Advice_REV_AssertionURIRef) */

void zx_sa_Advice_REV_AssertionURIRef(struct zx_sa_Advice_s* x)
{
  struct zx_elem_s* nxt;
  struct zx_elem_s* y;
  if (!x) return;
  y = x->AssertionURIRef;
  if (!y) return;
  x->AssertionURIRef = 0;
  while (y) {
    nxt = (struct zx_elem_s*)y->g.n;
    y->g.n = &x->AssertionURIRef->g;
    x->AssertionURIRef = y;
    y = nxt;
  }
}

/* FUNC(zx_sa_Advice_PUT_AssertionURIRef) */

void zx_sa_Advice_PUT_AssertionURIRef(struct zx_sa_Advice_s* x, int n, struct zx_elem_s* z)
{
  struct zx_elem_s* y;
  if (!x || !z) return;
  y = x->AssertionURIRef;
  if (!y) return;
  switch (n) {
  case 0:
    z->g.n = y->g.n;
    x->AssertionURIRef = z;
    return;
  default:
    for (; n > 1 && y->g.n; --n, y = (struct zx_elem_s*)y->g.n) ;
    if (!y->g.n) return;
    z->g.n = y->g.n->n;
    y->g.n = &z->g;
  }
}

/* FUNC(zx_sa_Advice_ADD_AssertionURIRef) */

void zx_sa_Advice_ADD_AssertionURIRef(struct zx_sa_Advice_s* x, int n, struct zx_elem_s* z)
{
  struct zx_elem_s* y;
  if (!x || !z) return;
  switch (n) {
  case 0:
  add_to_start:
    z->g.n = &x->AssertionURIRef->g;
    x->AssertionURIRef = z;
    return;
  case -1:
    y = x->AssertionURIRef;
    if (!y) goto add_to_start;
    for (; y->g.n; y = (struct zx_elem_s*)y->g.n) ;
    break;
  default:
    for (y = x->AssertionURIRef; n > 1 && y; --n, y = (struct zx_elem_s*)y->g.n) ;
    if (!y) return;
  }
  z->g.n = y->g.n;
  y->g.n = &z->g;
}

/* FUNC(zx_sa_Advice_DEL_AssertionURIRef) */

void zx_sa_Advice_DEL_AssertionURIRef(struct zx_sa_Advice_s* x, int n)
{
  struct zx_elem_s* y;
  if (!x) return;
  switch (n) {
  case 0:
    x->AssertionURIRef = (struct zx_elem_s*)x->AssertionURIRef->g.n;
    return;
  case -1:
    y = (struct zx_elem_s*)x->AssertionURIRef;
    if (!y) return;
    for (; y->g.n; y = (struct zx_elem_s*)y->g.n) ;
    break;
  default:
    for (y = x->AssertionURIRef; n > 1 && y->g.n; --n, y = (struct zx_elem_s*)y->g.n) ;
    if (!y->g.n) return;
  }
  y->g.n = y->g.n->n;
}

#endif



#ifdef ZX_ENA_GETPUT

/* FUNC(zx_sa_Advice_NUM_Assertion) */

int zx_sa_Advice_NUM_Assertion(struct zx_sa_Advice_s* x)
{
  struct zx_sa_Assertion_s* y;
  int n = 0;
  if (!x) return 0;
  for (y = x->Assertion; y; ++n, y = (struct zx_sa_Assertion_s*)y->gg.g.n) ;
  return n;
}

/* FUNC(zx_sa_Advice_GET_Assertion) */

struct zx_sa_Assertion_s* zx_sa_Advice_GET_Assertion(struct zx_sa_Advice_s* x, int n)
{
  struct zx_sa_Assertion_s* y;
  if (!x) return 0;
  for (y = x->Assertion; n>=0 && y; --n, y = (struct zx_sa_Assertion_s*)y->gg.g.n) ;
  return y;
}

/* FUNC(zx_sa_Advice_POP_Assertion) */

struct zx_sa_Assertion_s* zx_sa_Advice_POP_Assertion(struct zx_sa_Advice_s* x)
{
  struct zx_sa_Assertion_s* y;
  if (!x) return 0;
  y = x->Assertion;
  if (y)
    x->Assertion = (struct zx_sa_Assertion_s*)y->gg.g.n;
  return y;
}

/* FUNC(zx_sa_Advice_PUSH_Assertion) */

void zx_sa_Advice_PUSH_Assertion(struct zx_sa_Advice_s* x, struct zx_sa_Assertion_s* z)
{
  if (!x || !z) return;
  z->gg.g.n = &x->Assertion->gg.g;
  x->Assertion = z;
}

/* FUNC(zx_sa_Advice_REV_Assertion) */

void zx_sa_Advice_REV_Assertion(struct zx_sa_Advice_s* x)
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

/* FUNC(zx_sa_Advice_PUT_Assertion) */

void zx_sa_Advice_PUT_Assertion(struct zx_sa_Advice_s* x, int n, struct zx_sa_Assertion_s* z)
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

/* FUNC(zx_sa_Advice_ADD_Assertion) */

void zx_sa_Advice_ADD_Assertion(struct zx_sa_Advice_s* x, int n, struct zx_sa_Assertion_s* z)
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

/* FUNC(zx_sa_Advice_DEL_Assertion) */

void zx_sa_Advice_DEL_Assertion(struct zx_sa_Advice_s* x, int n)
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

/* FUNC(zx_sa_Advice_NUM_EncryptedAssertion) */

int zx_sa_Advice_NUM_EncryptedAssertion(struct zx_sa_Advice_s* x)
{
  struct zx_sa_EncryptedAssertion_s* y;
  int n = 0;
  if (!x) return 0;
  for (y = x->EncryptedAssertion; y; ++n, y = (struct zx_sa_EncryptedAssertion_s*)y->gg.g.n) ;
  return n;
}

/* FUNC(zx_sa_Advice_GET_EncryptedAssertion) */

struct zx_sa_EncryptedAssertion_s* zx_sa_Advice_GET_EncryptedAssertion(struct zx_sa_Advice_s* x, int n)
{
  struct zx_sa_EncryptedAssertion_s* y;
  if (!x) return 0;
  for (y = x->EncryptedAssertion; n>=0 && y; --n, y = (struct zx_sa_EncryptedAssertion_s*)y->gg.g.n) ;
  return y;
}

/* FUNC(zx_sa_Advice_POP_EncryptedAssertion) */

struct zx_sa_EncryptedAssertion_s* zx_sa_Advice_POP_EncryptedAssertion(struct zx_sa_Advice_s* x)
{
  struct zx_sa_EncryptedAssertion_s* y;
  if (!x) return 0;
  y = x->EncryptedAssertion;
  if (y)
    x->EncryptedAssertion = (struct zx_sa_EncryptedAssertion_s*)y->gg.g.n;
  return y;
}

/* FUNC(zx_sa_Advice_PUSH_EncryptedAssertion) */

void zx_sa_Advice_PUSH_EncryptedAssertion(struct zx_sa_Advice_s* x, struct zx_sa_EncryptedAssertion_s* z)
{
  if (!x || !z) return;
  z->gg.g.n = &x->EncryptedAssertion->gg.g;
  x->EncryptedAssertion = z;
}

/* FUNC(zx_sa_Advice_REV_EncryptedAssertion) */

void zx_sa_Advice_REV_EncryptedAssertion(struct zx_sa_Advice_s* x)
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

/* FUNC(zx_sa_Advice_PUT_EncryptedAssertion) */

void zx_sa_Advice_PUT_EncryptedAssertion(struct zx_sa_Advice_s* x, int n, struct zx_sa_EncryptedAssertion_s* z)
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

/* FUNC(zx_sa_Advice_ADD_EncryptedAssertion) */

void zx_sa_Advice_ADD_EncryptedAssertion(struct zx_sa_Advice_s* x, int n, struct zx_sa_EncryptedAssertion_s* z)
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

/* FUNC(zx_sa_Advice_DEL_EncryptedAssertion) */

void zx_sa_Advice_DEL_EncryptedAssertion(struct zx_sa_Advice_s* x, int n)
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

/* FUNC(zx_sa_Advice_NUM_sa11_Assertion) */

int zx_sa_Advice_NUM_sa11_Assertion(struct zx_sa_Advice_s* x)
{
  struct zx_sa11_Assertion_s* y;
  int n = 0;
  if (!x) return 0;
  for (y = x->sa11_Assertion; y; ++n, y = (struct zx_sa11_Assertion_s*)y->gg.g.n) ;
  return n;
}

/* FUNC(zx_sa_Advice_GET_sa11_Assertion) */

struct zx_sa11_Assertion_s* zx_sa_Advice_GET_sa11_Assertion(struct zx_sa_Advice_s* x, int n)
{
  struct zx_sa11_Assertion_s* y;
  if (!x) return 0;
  for (y = x->sa11_Assertion; n>=0 && y; --n, y = (struct zx_sa11_Assertion_s*)y->gg.g.n) ;
  return y;
}

/* FUNC(zx_sa_Advice_POP_sa11_Assertion) */

struct zx_sa11_Assertion_s* zx_sa_Advice_POP_sa11_Assertion(struct zx_sa_Advice_s* x)
{
  struct zx_sa11_Assertion_s* y;
  if (!x) return 0;
  y = x->sa11_Assertion;
  if (y)
    x->sa11_Assertion = (struct zx_sa11_Assertion_s*)y->gg.g.n;
  return y;
}

/* FUNC(zx_sa_Advice_PUSH_sa11_Assertion) */

void zx_sa_Advice_PUSH_sa11_Assertion(struct zx_sa_Advice_s* x, struct zx_sa11_Assertion_s* z)
{
  if (!x || !z) return;
  z->gg.g.n = &x->sa11_Assertion->gg.g;
  x->sa11_Assertion = z;
}

/* FUNC(zx_sa_Advice_REV_sa11_Assertion) */

void zx_sa_Advice_REV_sa11_Assertion(struct zx_sa_Advice_s* x)
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

/* FUNC(zx_sa_Advice_PUT_sa11_Assertion) */

void zx_sa_Advice_PUT_sa11_Assertion(struct zx_sa_Advice_s* x, int n, struct zx_sa11_Assertion_s* z)
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

/* FUNC(zx_sa_Advice_ADD_sa11_Assertion) */

void zx_sa_Advice_ADD_sa11_Assertion(struct zx_sa_Advice_s* x, int n, struct zx_sa11_Assertion_s* z)
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

/* FUNC(zx_sa_Advice_DEL_sa11_Assertion) */

void zx_sa_Advice_DEL_sa11_Assertion(struct zx_sa_Advice_s* x, int n)
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

/* FUNC(zx_sa_Advice_NUM_ff12_Assertion) */

int zx_sa_Advice_NUM_ff12_Assertion(struct zx_sa_Advice_s* x)
{
  struct zx_ff12_Assertion_s* y;
  int n = 0;
  if (!x) return 0;
  for (y = x->ff12_Assertion; y; ++n, y = (struct zx_ff12_Assertion_s*)y->gg.g.n) ;
  return n;
}

/* FUNC(zx_sa_Advice_GET_ff12_Assertion) */

struct zx_ff12_Assertion_s* zx_sa_Advice_GET_ff12_Assertion(struct zx_sa_Advice_s* x, int n)
{
  struct zx_ff12_Assertion_s* y;
  if (!x) return 0;
  for (y = x->ff12_Assertion; n>=0 && y; --n, y = (struct zx_ff12_Assertion_s*)y->gg.g.n) ;
  return y;
}

/* FUNC(zx_sa_Advice_POP_ff12_Assertion) */

struct zx_ff12_Assertion_s* zx_sa_Advice_POP_ff12_Assertion(struct zx_sa_Advice_s* x)
{
  struct zx_ff12_Assertion_s* y;
  if (!x) return 0;
  y = x->ff12_Assertion;
  if (y)
    x->ff12_Assertion = (struct zx_ff12_Assertion_s*)y->gg.g.n;
  return y;
}

/* FUNC(zx_sa_Advice_PUSH_ff12_Assertion) */

void zx_sa_Advice_PUSH_ff12_Assertion(struct zx_sa_Advice_s* x, struct zx_ff12_Assertion_s* z)
{
  if (!x || !z) return;
  z->gg.g.n = &x->ff12_Assertion->gg.g;
  x->ff12_Assertion = z;
}

/* FUNC(zx_sa_Advice_REV_ff12_Assertion) */

void zx_sa_Advice_REV_ff12_Assertion(struct zx_sa_Advice_s* x)
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

/* FUNC(zx_sa_Advice_PUT_ff12_Assertion) */

void zx_sa_Advice_PUT_ff12_Assertion(struct zx_sa_Advice_s* x, int n, struct zx_ff12_Assertion_s* z)
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

/* FUNC(zx_sa_Advice_ADD_ff12_Assertion) */

void zx_sa_Advice_ADD_ff12_Assertion(struct zx_sa_Advice_s* x, int n, struct zx_ff12_Assertion_s* z)
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

/* FUNC(zx_sa_Advice_DEL_ff12_Assertion) */

void zx_sa_Advice_DEL_ff12_Assertion(struct zx_sa_Advice_s* x, int n)
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








#ifdef ZX_ENA_GETPUT

/* FUNC(zx_sa_Assertion_NUM_Issuer) */

int zx_sa_Assertion_NUM_Issuer(struct zx_sa_Assertion_s* x)
{
  struct zx_sa_Issuer_s* y;
  int n = 0;
  if (!x) return 0;
  for (y = x->Issuer; y; ++n, y = (struct zx_sa_Issuer_s*)y->gg.g.n) ;
  return n;
}

/* FUNC(zx_sa_Assertion_GET_Issuer) */

struct zx_sa_Issuer_s* zx_sa_Assertion_GET_Issuer(struct zx_sa_Assertion_s* x, int n)
{
  struct zx_sa_Issuer_s* y;
  if (!x) return 0;
  for (y = x->Issuer; n>=0 && y; --n, y = (struct zx_sa_Issuer_s*)y->gg.g.n) ;
  return y;
}

/* FUNC(zx_sa_Assertion_POP_Issuer) */

struct zx_sa_Issuer_s* zx_sa_Assertion_POP_Issuer(struct zx_sa_Assertion_s* x)
{
  struct zx_sa_Issuer_s* y;
  if (!x) return 0;
  y = x->Issuer;
  if (y)
    x->Issuer = (struct zx_sa_Issuer_s*)y->gg.g.n;
  return y;
}

/* FUNC(zx_sa_Assertion_PUSH_Issuer) */

void zx_sa_Assertion_PUSH_Issuer(struct zx_sa_Assertion_s* x, struct zx_sa_Issuer_s* z)
{
  if (!x || !z) return;
  z->gg.g.n = &x->Issuer->gg.g;
  x->Issuer = z;
}

/* FUNC(zx_sa_Assertion_REV_Issuer) */

void zx_sa_Assertion_REV_Issuer(struct zx_sa_Assertion_s* x)
{
  struct zx_sa_Issuer_s* nxt;
  struct zx_sa_Issuer_s* y;
  if (!x) return;
  y = x->Issuer;
  if (!y) return;
  x->Issuer = 0;
  while (y) {
    nxt = (struct zx_sa_Issuer_s*)y->gg.g.n;
    y->gg.g.n = &x->Issuer->gg.g;
    x->Issuer = y;
    y = nxt;
  }
}

/* FUNC(zx_sa_Assertion_PUT_Issuer) */

void zx_sa_Assertion_PUT_Issuer(struct zx_sa_Assertion_s* x, int n, struct zx_sa_Issuer_s* z)
{
  struct zx_sa_Issuer_s* y;
  if (!x || !z) return;
  y = x->Issuer;
  if (!y) return;
  switch (n) {
  case 0:
    z->gg.g.n = y->gg.g.n;
    x->Issuer = z;
    return;
  default:
    for (; n > 1 && y->gg.g.n; --n, y = (struct zx_sa_Issuer_s*)y->gg.g.n) ;
    if (!y->gg.g.n) return;
    z->gg.g.n = y->gg.g.n->n;
    y->gg.g.n = &z->gg.g;
  }
}

/* FUNC(zx_sa_Assertion_ADD_Issuer) */

void zx_sa_Assertion_ADD_Issuer(struct zx_sa_Assertion_s* x, int n, struct zx_sa_Issuer_s* z)
{
  struct zx_sa_Issuer_s* y;
  if (!x || !z) return;
  switch (n) {
  case 0:
  add_to_start:
    z->gg.g.n = &x->Issuer->gg.g;
    x->Issuer = z;
    return;
  case -1:
    y = x->Issuer;
    if (!y) goto add_to_start;
    for (; y->gg.g.n; y = (struct zx_sa_Issuer_s*)y->gg.g.n) ;
    break;
  default:
    for (y = x->Issuer; n > 1 && y; --n, y = (struct zx_sa_Issuer_s*)y->gg.g.n) ;
    if (!y) return;
  }
  z->gg.g.n = y->gg.g.n;
  y->gg.g.n = &z->gg.g;
}

/* FUNC(zx_sa_Assertion_DEL_Issuer) */

void zx_sa_Assertion_DEL_Issuer(struct zx_sa_Assertion_s* x, int n)
{
  struct zx_sa_Issuer_s* y;
  if (!x) return;
  switch (n) {
  case 0:
    x->Issuer = (struct zx_sa_Issuer_s*)x->Issuer->gg.g.n;
    return;
  case -1:
    y = (struct zx_sa_Issuer_s*)x->Issuer;
    if (!y) return;
    for (; y->gg.g.n; y = (struct zx_sa_Issuer_s*)y->gg.g.n) ;
    break;
  default:
    for (y = x->Issuer; n > 1 && y->gg.g.n; --n, y = (struct zx_sa_Issuer_s*)y->gg.g.n) ;
    if (!y->gg.g.n) return;
  }
  y->gg.g.n = y->gg.g.n->n;
}

#endif



#ifdef ZX_ENA_GETPUT

/* FUNC(zx_sa_Assertion_NUM_Signature) */

int zx_sa_Assertion_NUM_Signature(struct zx_sa_Assertion_s* x)
{
  struct zx_ds_Signature_s* y;
  int n = 0;
  if (!x) return 0;
  for (y = x->Signature; y; ++n, y = (struct zx_ds_Signature_s*)y->gg.g.n) ;
  return n;
}

/* FUNC(zx_sa_Assertion_GET_Signature) */

struct zx_ds_Signature_s* zx_sa_Assertion_GET_Signature(struct zx_sa_Assertion_s* x, int n)
{
  struct zx_ds_Signature_s* y;
  if (!x) return 0;
  for (y = x->Signature; n>=0 && y; --n, y = (struct zx_ds_Signature_s*)y->gg.g.n) ;
  return y;
}

/* FUNC(zx_sa_Assertion_POP_Signature) */

struct zx_ds_Signature_s* zx_sa_Assertion_POP_Signature(struct zx_sa_Assertion_s* x)
{
  struct zx_ds_Signature_s* y;
  if (!x) return 0;
  y = x->Signature;
  if (y)
    x->Signature = (struct zx_ds_Signature_s*)y->gg.g.n;
  return y;
}

/* FUNC(zx_sa_Assertion_PUSH_Signature) */

void zx_sa_Assertion_PUSH_Signature(struct zx_sa_Assertion_s* x, struct zx_ds_Signature_s* z)
{
  if (!x || !z) return;
  z->gg.g.n = &x->Signature->gg.g;
  x->Signature = z;
}

/* FUNC(zx_sa_Assertion_REV_Signature) */

void zx_sa_Assertion_REV_Signature(struct zx_sa_Assertion_s* x)
{
  struct zx_ds_Signature_s* nxt;
  struct zx_ds_Signature_s* y;
  if (!x) return;
  y = x->Signature;
  if (!y) return;
  x->Signature = 0;
  while (y) {
    nxt = (struct zx_ds_Signature_s*)y->gg.g.n;
    y->gg.g.n = &x->Signature->gg.g;
    x->Signature = y;
    y = nxt;
  }
}

/* FUNC(zx_sa_Assertion_PUT_Signature) */

void zx_sa_Assertion_PUT_Signature(struct zx_sa_Assertion_s* x, int n, struct zx_ds_Signature_s* z)
{
  struct zx_ds_Signature_s* y;
  if (!x || !z) return;
  y = x->Signature;
  if (!y) return;
  switch (n) {
  case 0:
    z->gg.g.n = y->gg.g.n;
    x->Signature = z;
    return;
  default:
    for (; n > 1 && y->gg.g.n; --n, y = (struct zx_ds_Signature_s*)y->gg.g.n) ;
    if (!y->gg.g.n) return;
    z->gg.g.n = y->gg.g.n->n;
    y->gg.g.n = &z->gg.g;
  }
}

/* FUNC(zx_sa_Assertion_ADD_Signature) */

void zx_sa_Assertion_ADD_Signature(struct zx_sa_Assertion_s* x, int n, struct zx_ds_Signature_s* z)
{
  struct zx_ds_Signature_s* y;
  if (!x || !z) return;
  switch (n) {
  case 0:
  add_to_start:
    z->gg.g.n = &x->Signature->gg.g;
    x->Signature = z;
    return;
  case -1:
    y = x->Signature;
    if (!y) goto add_to_start;
    for (; y->gg.g.n; y = (struct zx_ds_Signature_s*)y->gg.g.n) ;
    break;
  default:
    for (y = x->Signature; n > 1 && y; --n, y = (struct zx_ds_Signature_s*)y->gg.g.n) ;
    if (!y) return;
  }
  z->gg.g.n = y->gg.g.n;
  y->gg.g.n = &z->gg.g;
}

/* FUNC(zx_sa_Assertion_DEL_Signature) */

void zx_sa_Assertion_DEL_Signature(struct zx_sa_Assertion_s* x, int n)
{
  struct zx_ds_Signature_s* y;
  if (!x) return;
  switch (n) {
  case 0:
    x->Signature = (struct zx_ds_Signature_s*)x->Signature->gg.g.n;
    return;
  case -1:
    y = (struct zx_ds_Signature_s*)x->Signature;
    if (!y) return;
    for (; y->gg.g.n; y = (struct zx_ds_Signature_s*)y->gg.g.n) ;
    break;
  default:
    for (y = x->Signature; n > 1 && y->gg.g.n; --n, y = (struct zx_ds_Signature_s*)y->gg.g.n) ;
    if (!y->gg.g.n) return;
  }
  y->gg.g.n = y->gg.g.n->n;
}

#endif



#ifdef ZX_ENA_GETPUT

/* FUNC(zx_sa_Assertion_NUM_Subject) */

int zx_sa_Assertion_NUM_Subject(struct zx_sa_Assertion_s* x)
{
  struct zx_sa_Subject_s* y;
  int n = 0;
  if (!x) return 0;
  for (y = x->Subject; y; ++n, y = (struct zx_sa_Subject_s*)y->gg.g.n) ;
  return n;
}

/* FUNC(zx_sa_Assertion_GET_Subject) */

struct zx_sa_Subject_s* zx_sa_Assertion_GET_Subject(struct zx_sa_Assertion_s* x, int n)
{
  struct zx_sa_Subject_s* y;
  if (!x) return 0;
  for (y = x->Subject; n>=0 && y; --n, y = (struct zx_sa_Subject_s*)y->gg.g.n) ;
  return y;
}

/* FUNC(zx_sa_Assertion_POP_Subject) */

struct zx_sa_Subject_s* zx_sa_Assertion_POP_Subject(struct zx_sa_Assertion_s* x)
{
  struct zx_sa_Subject_s* y;
  if (!x) return 0;
  y = x->Subject;
  if (y)
    x->Subject = (struct zx_sa_Subject_s*)y->gg.g.n;
  return y;
}

/* FUNC(zx_sa_Assertion_PUSH_Subject) */

void zx_sa_Assertion_PUSH_Subject(struct zx_sa_Assertion_s* x, struct zx_sa_Subject_s* z)
{
  if (!x || !z) return;
  z->gg.g.n = &x->Subject->gg.g;
  x->Subject = z;
}

/* FUNC(zx_sa_Assertion_REV_Subject) */

void zx_sa_Assertion_REV_Subject(struct zx_sa_Assertion_s* x)
{
  struct zx_sa_Subject_s* nxt;
  struct zx_sa_Subject_s* y;
  if (!x) return;
  y = x->Subject;
  if (!y) return;
  x->Subject = 0;
  while (y) {
    nxt = (struct zx_sa_Subject_s*)y->gg.g.n;
    y->gg.g.n = &x->Subject->gg.g;
    x->Subject = y;
    y = nxt;
  }
}

/* FUNC(zx_sa_Assertion_PUT_Subject) */

void zx_sa_Assertion_PUT_Subject(struct zx_sa_Assertion_s* x, int n, struct zx_sa_Subject_s* z)
{
  struct zx_sa_Subject_s* y;
  if (!x || !z) return;
  y = x->Subject;
  if (!y) return;
  switch (n) {
  case 0:
    z->gg.g.n = y->gg.g.n;
    x->Subject = z;
    return;
  default:
    for (; n > 1 && y->gg.g.n; --n, y = (struct zx_sa_Subject_s*)y->gg.g.n) ;
    if (!y->gg.g.n) return;
    z->gg.g.n = y->gg.g.n->n;
    y->gg.g.n = &z->gg.g;
  }
}

/* FUNC(zx_sa_Assertion_ADD_Subject) */

void zx_sa_Assertion_ADD_Subject(struct zx_sa_Assertion_s* x, int n, struct zx_sa_Subject_s* z)
{
  struct zx_sa_Subject_s* y;
  if (!x || !z) return;
  switch (n) {
  case 0:
  add_to_start:
    z->gg.g.n = &x->Subject->gg.g;
    x->Subject = z;
    return;
  case -1:
    y = x->Subject;
    if (!y) goto add_to_start;
    for (; y->gg.g.n; y = (struct zx_sa_Subject_s*)y->gg.g.n) ;
    break;
  default:
    for (y = x->Subject; n > 1 && y; --n, y = (struct zx_sa_Subject_s*)y->gg.g.n) ;
    if (!y) return;
  }
  z->gg.g.n = y->gg.g.n;
  y->gg.g.n = &z->gg.g;
}

/* FUNC(zx_sa_Assertion_DEL_Subject) */

void zx_sa_Assertion_DEL_Subject(struct zx_sa_Assertion_s* x, int n)
{
  struct zx_sa_Subject_s* y;
  if (!x) return;
  switch (n) {
  case 0:
    x->Subject = (struct zx_sa_Subject_s*)x->Subject->gg.g.n;
    return;
  case -1:
    y = (struct zx_sa_Subject_s*)x->Subject;
    if (!y) return;
    for (; y->gg.g.n; y = (struct zx_sa_Subject_s*)y->gg.g.n) ;
    break;
  default:
    for (y = x->Subject; n > 1 && y->gg.g.n; --n, y = (struct zx_sa_Subject_s*)y->gg.g.n) ;
    if (!y->gg.g.n) return;
  }
  y->gg.g.n = y->gg.g.n->n;
}

#endif



#ifdef ZX_ENA_GETPUT

/* FUNC(zx_sa_Assertion_NUM_Conditions) */

int zx_sa_Assertion_NUM_Conditions(struct zx_sa_Assertion_s* x)
{
  struct zx_sa_Conditions_s* y;
  int n = 0;
  if (!x) return 0;
  for (y = x->Conditions; y; ++n, y = (struct zx_sa_Conditions_s*)y->gg.g.n) ;
  return n;
}

/* FUNC(zx_sa_Assertion_GET_Conditions) */

struct zx_sa_Conditions_s* zx_sa_Assertion_GET_Conditions(struct zx_sa_Assertion_s* x, int n)
{
  struct zx_sa_Conditions_s* y;
  if (!x) return 0;
  for (y = x->Conditions; n>=0 && y; --n, y = (struct zx_sa_Conditions_s*)y->gg.g.n) ;
  return y;
}

/* FUNC(zx_sa_Assertion_POP_Conditions) */

struct zx_sa_Conditions_s* zx_sa_Assertion_POP_Conditions(struct zx_sa_Assertion_s* x)
{
  struct zx_sa_Conditions_s* y;
  if (!x) return 0;
  y = x->Conditions;
  if (y)
    x->Conditions = (struct zx_sa_Conditions_s*)y->gg.g.n;
  return y;
}

/* FUNC(zx_sa_Assertion_PUSH_Conditions) */

void zx_sa_Assertion_PUSH_Conditions(struct zx_sa_Assertion_s* x, struct zx_sa_Conditions_s* z)
{
  if (!x || !z) return;
  z->gg.g.n = &x->Conditions->gg.g;
  x->Conditions = z;
}

/* FUNC(zx_sa_Assertion_REV_Conditions) */

void zx_sa_Assertion_REV_Conditions(struct zx_sa_Assertion_s* x)
{
  struct zx_sa_Conditions_s* nxt;
  struct zx_sa_Conditions_s* y;
  if (!x) return;
  y = x->Conditions;
  if (!y) return;
  x->Conditions = 0;
  while (y) {
    nxt = (struct zx_sa_Conditions_s*)y->gg.g.n;
    y->gg.g.n = &x->Conditions->gg.g;
    x->Conditions = y;
    y = nxt;
  }
}

/* FUNC(zx_sa_Assertion_PUT_Conditions) */

void zx_sa_Assertion_PUT_Conditions(struct zx_sa_Assertion_s* x, int n, struct zx_sa_Conditions_s* z)
{
  struct zx_sa_Conditions_s* y;
  if (!x || !z) return;
  y = x->Conditions;
  if (!y) return;
  switch (n) {
  case 0:
    z->gg.g.n = y->gg.g.n;
    x->Conditions = z;
    return;
  default:
    for (; n > 1 && y->gg.g.n; --n, y = (struct zx_sa_Conditions_s*)y->gg.g.n) ;
    if (!y->gg.g.n) return;
    z->gg.g.n = y->gg.g.n->n;
    y->gg.g.n = &z->gg.g;
  }
}

/* FUNC(zx_sa_Assertion_ADD_Conditions) */

void zx_sa_Assertion_ADD_Conditions(struct zx_sa_Assertion_s* x, int n, struct zx_sa_Conditions_s* z)
{
  struct zx_sa_Conditions_s* y;
  if (!x || !z) return;
  switch (n) {
  case 0:
  add_to_start:
    z->gg.g.n = &x->Conditions->gg.g;
    x->Conditions = z;
    return;
  case -1:
    y = x->Conditions;
    if (!y) goto add_to_start;
    for (; y->gg.g.n; y = (struct zx_sa_Conditions_s*)y->gg.g.n) ;
    break;
  default:
    for (y = x->Conditions; n > 1 && y; --n, y = (struct zx_sa_Conditions_s*)y->gg.g.n) ;
    if (!y) return;
  }
  z->gg.g.n = y->gg.g.n;
  y->gg.g.n = &z->gg.g;
}

/* FUNC(zx_sa_Assertion_DEL_Conditions) */

void zx_sa_Assertion_DEL_Conditions(struct zx_sa_Assertion_s* x, int n)
{
  struct zx_sa_Conditions_s* y;
  if (!x) return;
  switch (n) {
  case 0:
    x->Conditions = (struct zx_sa_Conditions_s*)x->Conditions->gg.g.n;
    return;
  case -1:
    y = (struct zx_sa_Conditions_s*)x->Conditions;
    if (!y) return;
    for (; y->gg.g.n; y = (struct zx_sa_Conditions_s*)y->gg.g.n) ;
    break;
  default:
    for (y = x->Conditions; n > 1 && y->gg.g.n; --n, y = (struct zx_sa_Conditions_s*)y->gg.g.n) ;
    if (!y->gg.g.n) return;
  }
  y->gg.g.n = y->gg.g.n->n;
}

#endif



#ifdef ZX_ENA_GETPUT

/* FUNC(zx_sa_Assertion_NUM_Advice) */

int zx_sa_Assertion_NUM_Advice(struct zx_sa_Assertion_s* x)
{
  struct zx_sa_Advice_s* y;
  int n = 0;
  if (!x) return 0;
  for (y = x->Advice; y; ++n, y = (struct zx_sa_Advice_s*)y->gg.g.n) ;
  return n;
}

/* FUNC(zx_sa_Assertion_GET_Advice) */

struct zx_sa_Advice_s* zx_sa_Assertion_GET_Advice(struct zx_sa_Assertion_s* x, int n)
{
  struct zx_sa_Advice_s* y;
  if (!x) return 0;
  for (y = x->Advice; n>=0 && y; --n, y = (struct zx_sa_Advice_s*)y->gg.g.n) ;
  return y;
}

/* FUNC(zx_sa_Assertion_POP_Advice) */

struct zx_sa_Advice_s* zx_sa_Assertion_POP_Advice(struct zx_sa_Assertion_s* x)
{
  struct zx_sa_Advice_s* y;
  if (!x) return 0;
  y = x->Advice;
  if (y)
    x->Advice = (struct zx_sa_Advice_s*)y->gg.g.n;
  return y;
}

/* FUNC(zx_sa_Assertion_PUSH_Advice) */

void zx_sa_Assertion_PUSH_Advice(struct zx_sa_Assertion_s* x, struct zx_sa_Advice_s* z)
{
  if (!x || !z) return;
  z->gg.g.n = &x->Advice->gg.g;
  x->Advice = z;
}

/* FUNC(zx_sa_Assertion_REV_Advice) */

void zx_sa_Assertion_REV_Advice(struct zx_sa_Assertion_s* x)
{
  struct zx_sa_Advice_s* nxt;
  struct zx_sa_Advice_s* y;
  if (!x) return;
  y = x->Advice;
  if (!y) return;
  x->Advice = 0;
  while (y) {
    nxt = (struct zx_sa_Advice_s*)y->gg.g.n;
    y->gg.g.n = &x->Advice->gg.g;
    x->Advice = y;
    y = nxt;
  }
}

/* FUNC(zx_sa_Assertion_PUT_Advice) */

void zx_sa_Assertion_PUT_Advice(struct zx_sa_Assertion_s* x, int n, struct zx_sa_Advice_s* z)
{
  struct zx_sa_Advice_s* y;
  if (!x || !z) return;
  y = x->Advice;
  if (!y) return;
  switch (n) {
  case 0:
    z->gg.g.n = y->gg.g.n;
    x->Advice = z;
    return;
  default:
    for (; n > 1 && y->gg.g.n; --n, y = (struct zx_sa_Advice_s*)y->gg.g.n) ;
    if (!y->gg.g.n) return;
    z->gg.g.n = y->gg.g.n->n;
    y->gg.g.n = &z->gg.g;
  }
}

/* FUNC(zx_sa_Assertion_ADD_Advice) */

void zx_sa_Assertion_ADD_Advice(struct zx_sa_Assertion_s* x, int n, struct zx_sa_Advice_s* z)
{
  struct zx_sa_Advice_s* y;
  if (!x || !z) return;
  switch (n) {
  case 0:
  add_to_start:
    z->gg.g.n = &x->Advice->gg.g;
    x->Advice = z;
    return;
  case -1:
    y = x->Advice;
    if (!y) goto add_to_start;
    for (; y->gg.g.n; y = (struct zx_sa_Advice_s*)y->gg.g.n) ;
    break;
  default:
    for (y = x->Advice; n > 1 && y; --n, y = (struct zx_sa_Advice_s*)y->gg.g.n) ;
    if (!y) return;
  }
  z->gg.g.n = y->gg.g.n;
  y->gg.g.n = &z->gg.g;
}

/* FUNC(zx_sa_Assertion_DEL_Advice) */

void zx_sa_Assertion_DEL_Advice(struct zx_sa_Assertion_s* x, int n)
{
  struct zx_sa_Advice_s* y;
  if (!x) return;
  switch (n) {
  case 0:
    x->Advice = (struct zx_sa_Advice_s*)x->Advice->gg.g.n;
    return;
  case -1:
    y = (struct zx_sa_Advice_s*)x->Advice;
    if (!y) return;
    for (; y->gg.g.n; y = (struct zx_sa_Advice_s*)y->gg.g.n) ;
    break;
  default:
    for (y = x->Advice; n > 1 && y->gg.g.n; --n, y = (struct zx_sa_Advice_s*)y->gg.g.n) ;
    if (!y->gg.g.n) return;
  }
  y->gg.g.n = y->gg.g.n->n;
}

#endif



#ifdef ZX_ENA_GETPUT

/* FUNC(zx_sa_Assertion_NUM_Statement) */

int zx_sa_Assertion_NUM_Statement(struct zx_sa_Assertion_s* x)
{
  struct zx_sa_Statement_s* y;
  int n = 0;
  if (!x) return 0;
  for (y = x->Statement; y; ++n, y = (struct zx_sa_Statement_s*)y->gg.g.n) ;
  return n;
}

/* FUNC(zx_sa_Assertion_GET_Statement) */

struct zx_sa_Statement_s* zx_sa_Assertion_GET_Statement(struct zx_sa_Assertion_s* x, int n)
{
  struct zx_sa_Statement_s* y;
  if (!x) return 0;
  for (y = x->Statement; n>=0 && y; --n, y = (struct zx_sa_Statement_s*)y->gg.g.n) ;
  return y;
}

/* FUNC(zx_sa_Assertion_POP_Statement) */

struct zx_sa_Statement_s* zx_sa_Assertion_POP_Statement(struct zx_sa_Assertion_s* x)
{
  struct zx_sa_Statement_s* y;
  if (!x) return 0;
  y = x->Statement;
  if (y)
    x->Statement = (struct zx_sa_Statement_s*)y->gg.g.n;
  return y;
}

/* FUNC(zx_sa_Assertion_PUSH_Statement) */

void zx_sa_Assertion_PUSH_Statement(struct zx_sa_Assertion_s* x, struct zx_sa_Statement_s* z)
{
  if (!x || !z) return;
  z->gg.g.n = &x->Statement->gg.g;
  x->Statement = z;
}

/* FUNC(zx_sa_Assertion_REV_Statement) */

void zx_sa_Assertion_REV_Statement(struct zx_sa_Assertion_s* x)
{
  struct zx_sa_Statement_s* nxt;
  struct zx_sa_Statement_s* y;
  if (!x) return;
  y = x->Statement;
  if (!y) return;
  x->Statement = 0;
  while (y) {
    nxt = (struct zx_sa_Statement_s*)y->gg.g.n;
    y->gg.g.n = &x->Statement->gg.g;
    x->Statement = y;
    y = nxt;
  }
}

/* FUNC(zx_sa_Assertion_PUT_Statement) */

void zx_sa_Assertion_PUT_Statement(struct zx_sa_Assertion_s* x, int n, struct zx_sa_Statement_s* z)
{
  struct zx_sa_Statement_s* y;
  if (!x || !z) return;
  y = x->Statement;
  if (!y) return;
  switch (n) {
  case 0:
    z->gg.g.n = y->gg.g.n;
    x->Statement = z;
    return;
  default:
    for (; n > 1 && y->gg.g.n; --n, y = (struct zx_sa_Statement_s*)y->gg.g.n) ;
    if (!y->gg.g.n) return;
    z->gg.g.n = y->gg.g.n->n;
    y->gg.g.n = &z->gg.g;
  }
}

/* FUNC(zx_sa_Assertion_ADD_Statement) */

void zx_sa_Assertion_ADD_Statement(struct zx_sa_Assertion_s* x, int n, struct zx_sa_Statement_s* z)
{
  struct zx_sa_Statement_s* y;
  if (!x || !z) return;
  switch (n) {
  case 0:
  add_to_start:
    z->gg.g.n = &x->Statement->gg.g;
    x->Statement = z;
    return;
  case -1:
    y = x->Statement;
    if (!y) goto add_to_start;
    for (; y->gg.g.n; y = (struct zx_sa_Statement_s*)y->gg.g.n) ;
    break;
  default:
    for (y = x->Statement; n > 1 && y; --n, y = (struct zx_sa_Statement_s*)y->gg.g.n) ;
    if (!y) return;
  }
  z->gg.g.n = y->gg.g.n;
  y->gg.g.n = &z->gg.g;
}

/* FUNC(zx_sa_Assertion_DEL_Statement) */

void zx_sa_Assertion_DEL_Statement(struct zx_sa_Assertion_s* x, int n)
{
  struct zx_sa_Statement_s* y;
  if (!x) return;
  switch (n) {
  case 0:
    x->Statement = (struct zx_sa_Statement_s*)x->Statement->gg.g.n;
    return;
  case -1:
    y = (struct zx_sa_Statement_s*)x->Statement;
    if (!y) return;
    for (; y->gg.g.n; y = (struct zx_sa_Statement_s*)y->gg.g.n) ;
    break;
  default:
    for (y = x->Statement; n > 1 && y->gg.g.n; --n, y = (struct zx_sa_Statement_s*)y->gg.g.n) ;
    if (!y->gg.g.n) return;
  }
  y->gg.g.n = y->gg.g.n->n;
}

#endif



#ifdef ZX_ENA_GETPUT

/* FUNC(zx_sa_Assertion_NUM_AuthnStatement) */

int zx_sa_Assertion_NUM_AuthnStatement(struct zx_sa_Assertion_s* x)
{
  struct zx_sa_AuthnStatement_s* y;
  int n = 0;
  if (!x) return 0;
  for (y = x->AuthnStatement; y; ++n, y = (struct zx_sa_AuthnStatement_s*)y->gg.g.n) ;
  return n;
}

/* FUNC(zx_sa_Assertion_GET_AuthnStatement) */

struct zx_sa_AuthnStatement_s* zx_sa_Assertion_GET_AuthnStatement(struct zx_sa_Assertion_s* x, int n)
{
  struct zx_sa_AuthnStatement_s* y;
  if (!x) return 0;
  for (y = x->AuthnStatement; n>=0 && y; --n, y = (struct zx_sa_AuthnStatement_s*)y->gg.g.n) ;
  return y;
}

/* FUNC(zx_sa_Assertion_POP_AuthnStatement) */

struct zx_sa_AuthnStatement_s* zx_sa_Assertion_POP_AuthnStatement(struct zx_sa_Assertion_s* x)
{
  struct zx_sa_AuthnStatement_s* y;
  if (!x) return 0;
  y = x->AuthnStatement;
  if (y)
    x->AuthnStatement = (struct zx_sa_AuthnStatement_s*)y->gg.g.n;
  return y;
}

/* FUNC(zx_sa_Assertion_PUSH_AuthnStatement) */

void zx_sa_Assertion_PUSH_AuthnStatement(struct zx_sa_Assertion_s* x, struct zx_sa_AuthnStatement_s* z)
{
  if (!x || !z) return;
  z->gg.g.n = &x->AuthnStatement->gg.g;
  x->AuthnStatement = z;
}

/* FUNC(zx_sa_Assertion_REV_AuthnStatement) */

void zx_sa_Assertion_REV_AuthnStatement(struct zx_sa_Assertion_s* x)
{
  struct zx_sa_AuthnStatement_s* nxt;
  struct zx_sa_AuthnStatement_s* y;
  if (!x) return;
  y = x->AuthnStatement;
  if (!y) return;
  x->AuthnStatement = 0;
  while (y) {
    nxt = (struct zx_sa_AuthnStatement_s*)y->gg.g.n;
    y->gg.g.n = &x->AuthnStatement->gg.g;
    x->AuthnStatement = y;
    y = nxt;
  }
}

/* FUNC(zx_sa_Assertion_PUT_AuthnStatement) */

void zx_sa_Assertion_PUT_AuthnStatement(struct zx_sa_Assertion_s* x, int n, struct zx_sa_AuthnStatement_s* z)
{
  struct zx_sa_AuthnStatement_s* y;
  if (!x || !z) return;
  y = x->AuthnStatement;
  if (!y) return;
  switch (n) {
  case 0:
    z->gg.g.n = y->gg.g.n;
    x->AuthnStatement = z;
    return;
  default:
    for (; n > 1 && y->gg.g.n; --n, y = (struct zx_sa_AuthnStatement_s*)y->gg.g.n) ;
    if (!y->gg.g.n) return;
    z->gg.g.n = y->gg.g.n->n;
    y->gg.g.n = &z->gg.g;
  }
}

/* FUNC(zx_sa_Assertion_ADD_AuthnStatement) */

void zx_sa_Assertion_ADD_AuthnStatement(struct zx_sa_Assertion_s* x, int n, struct zx_sa_AuthnStatement_s* z)
{
  struct zx_sa_AuthnStatement_s* y;
  if (!x || !z) return;
  switch (n) {
  case 0:
  add_to_start:
    z->gg.g.n = &x->AuthnStatement->gg.g;
    x->AuthnStatement = z;
    return;
  case -1:
    y = x->AuthnStatement;
    if (!y) goto add_to_start;
    for (; y->gg.g.n; y = (struct zx_sa_AuthnStatement_s*)y->gg.g.n) ;
    break;
  default:
    for (y = x->AuthnStatement; n > 1 && y; --n, y = (struct zx_sa_AuthnStatement_s*)y->gg.g.n) ;
    if (!y) return;
  }
  z->gg.g.n = y->gg.g.n;
  y->gg.g.n = &z->gg.g;
}

/* FUNC(zx_sa_Assertion_DEL_AuthnStatement) */

void zx_sa_Assertion_DEL_AuthnStatement(struct zx_sa_Assertion_s* x, int n)
{
  struct zx_sa_AuthnStatement_s* y;
  if (!x) return;
  switch (n) {
  case 0:
    x->AuthnStatement = (struct zx_sa_AuthnStatement_s*)x->AuthnStatement->gg.g.n;
    return;
  case -1:
    y = (struct zx_sa_AuthnStatement_s*)x->AuthnStatement;
    if (!y) return;
    for (; y->gg.g.n; y = (struct zx_sa_AuthnStatement_s*)y->gg.g.n) ;
    break;
  default:
    for (y = x->AuthnStatement; n > 1 && y->gg.g.n; --n, y = (struct zx_sa_AuthnStatement_s*)y->gg.g.n) ;
    if (!y->gg.g.n) return;
  }
  y->gg.g.n = y->gg.g.n->n;
}

#endif



#ifdef ZX_ENA_GETPUT

/* FUNC(zx_sa_Assertion_NUM_AuthzDecisionStatement) */

int zx_sa_Assertion_NUM_AuthzDecisionStatement(struct zx_sa_Assertion_s* x)
{
  struct zx_sa_AuthzDecisionStatement_s* y;
  int n = 0;
  if (!x) return 0;
  for (y = x->AuthzDecisionStatement; y; ++n, y = (struct zx_sa_AuthzDecisionStatement_s*)y->gg.g.n) ;
  return n;
}

/* FUNC(zx_sa_Assertion_GET_AuthzDecisionStatement) */

struct zx_sa_AuthzDecisionStatement_s* zx_sa_Assertion_GET_AuthzDecisionStatement(struct zx_sa_Assertion_s* x, int n)
{
  struct zx_sa_AuthzDecisionStatement_s* y;
  if (!x) return 0;
  for (y = x->AuthzDecisionStatement; n>=0 && y; --n, y = (struct zx_sa_AuthzDecisionStatement_s*)y->gg.g.n) ;
  return y;
}

/* FUNC(zx_sa_Assertion_POP_AuthzDecisionStatement) */

struct zx_sa_AuthzDecisionStatement_s* zx_sa_Assertion_POP_AuthzDecisionStatement(struct zx_sa_Assertion_s* x)
{
  struct zx_sa_AuthzDecisionStatement_s* y;
  if (!x) return 0;
  y = x->AuthzDecisionStatement;
  if (y)
    x->AuthzDecisionStatement = (struct zx_sa_AuthzDecisionStatement_s*)y->gg.g.n;
  return y;
}

/* FUNC(zx_sa_Assertion_PUSH_AuthzDecisionStatement) */

void zx_sa_Assertion_PUSH_AuthzDecisionStatement(struct zx_sa_Assertion_s* x, struct zx_sa_AuthzDecisionStatement_s* z)
{
  if (!x || !z) return;
  z->gg.g.n = &x->AuthzDecisionStatement->gg.g;
  x->AuthzDecisionStatement = z;
}

/* FUNC(zx_sa_Assertion_REV_AuthzDecisionStatement) */

void zx_sa_Assertion_REV_AuthzDecisionStatement(struct zx_sa_Assertion_s* x)
{
  struct zx_sa_AuthzDecisionStatement_s* nxt;
  struct zx_sa_AuthzDecisionStatement_s* y;
  if (!x) return;
  y = x->AuthzDecisionStatement;
  if (!y) return;
  x->AuthzDecisionStatement = 0;
  while (y) {
    nxt = (struct zx_sa_AuthzDecisionStatement_s*)y->gg.g.n;
    y->gg.g.n = &x->AuthzDecisionStatement->gg.g;
    x->AuthzDecisionStatement = y;
    y = nxt;
  }
}

/* FUNC(zx_sa_Assertion_PUT_AuthzDecisionStatement) */

void zx_sa_Assertion_PUT_AuthzDecisionStatement(struct zx_sa_Assertion_s* x, int n, struct zx_sa_AuthzDecisionStatement_s* z)
{
  struct zx_sa_AuthzDecisionStatement_s* y;
  if (!x || !z) return;
  y = x->AuthzDecisionStatement;
  if (!y) return;
  switch (n) {
  case 0:
    z->gg.g.n = y->gg.g.n;
    x->AuthzDecisionStatement = z;
    return;
  default:
    for (; n > 1 && y->gg.g.n; --n, y = (struct zx_sa_AuthzDecisionStatement_s*)y->gg.g.n) ;
    if (!y->gg.g.n) return;
    z->gg.g.n = y->gg.g.n->n;
    y->gg.g.n = &z->gg.g;
  }
}

/* FUNC(zx_sa_Assertion_ADD_AuthzDecisionStatement) */

void zx_sa_Assertion_ADD_AuthzDecisionStatement(struct zx_sa_Assertion_s* x, int n, struct zx_sa_AuthzDecisionStatement_s* z)
{
  struct zx_sa_AuthzDecisionStatement_s* y;
  if (!x || !z) return;
  switch (n) {
  case 0:
  add_to_start:
    z->gg.g.n = &x->AuthzDecisionStatement->gg.g;
    x->AuthzDecisionStatement = z;
    return;
  case -1:
    y = x->AuthzDecisionStatement;
    if (!y) goto add_to_start;
    for (; y->gg.g.n; y = (struct zx_sa_AuthzDecisionStatement_s*)y->gg.g.n) ;
    break;
  default:
    for (y = x->AuthzDecisionStatement; n > 1 && y; --n, y = (struct zx_sa_AuthzDecisionStatement_s*)y->gg.g.n) ;
    if (!y) return;
  }
  z->gg.g.n = y->gg.g.n;
  y->gg.g.n = &z->gg.g;
}

/* FUNC(zx_sa_Assertion_DEL_AuthzDecisionStatement) */

void zx_sa_Assertion_DEL_AuthzDecisionStatement(struct zx_sa_Assertion_s* x, int n)
{
  struct zx_sa_AuthzDecisionStatement_s* y;
  if (!x) return;
  switch (n) {
  case 0:
    x->AuthzDecisionStatement = (struct zx_sa_AuthzDecisionStatement_s*)x->AuthzDecisionStatement->gg.g.n;
    return;
  case -1:
    y = (struct zx_sa_AuthzDecisionStatement_s*)x->AuthzDecisionStatement;
    if (!y) return;
    for (; y->gg.g.n; y = (struct zx_sa_AuthzDecisionStatement_s*)y->gg.g.n) ;
    break;
  default:
    for (y = x->AuthzDecisionStatement; n > 1 && y->gg.g.n; --n, y = (struct zx_sa_AuthzDecisionStatement_s*)y->gg.g.n) ;
    if (!y->gg.g.n) return;
  }
  y->gg.g.n = y->gg.g.n->n;
}

#endif



#ifdef ZX_ENA_GETPUT

/* FUNC(zx_sa_Assertion_NUM_AttributeStatement) */

int zx_sa_Assertion_NUM_AttributeStatement(struct zx_sa_Assertion_s* x)
{
  struct zx_sa_AttributeStatement_s* y;
  int n = 0;
  if (!x) return 0;
  for (y = x->AttributeStatement; y; ++n, y = (struct zx_sa_AttributeStatement_s*)y->gg.g.n) ;
  return n;
}

/* FUNC(zx_sa_Assertion_GET_AttributeStatement) */

struct zx_sa_AttributeStatement_s* zx_sa_Assertion_GET_AttributeStatement(struct zx_sa_Assertion_s* x, int n)
{
  struct zx_sa_AttributeStatement_s* y;
  if (!x) return 0;
  for (y = x->AttributeStatement; n>=0 && y; --n, y = (struct zx_sa_AttributeStatement_s*)y->gg.g.n) ;
  return y;
}

/* FUNC(zx_sa_Assertion_POP_AttributeStatement) */

struct zx_sa_AttributeStatement_s* zx_sa_Assertion_POP_AttributeStatement(struct zx_sa_Assertion_s* x)
{
  struct zx_sa_AttributeStatement_s* y;
  if (!x) return 0;
  y = x->AttributeStatement;
  if (y)
    x->AttributeStatement = (struct zx_sa_AttributeStatement_s*)y->gg.g.n;
  return y;
}

/* FUNC(zx_sa_Assertion_PUSH_AttributeStatement) */

void zx_sa_Assertion_PUSH_AttributeStatement(struct zx_sa_Assertion_s* x, struct zx_sa_AttributeStatement_s* z)
{
  if (!x || !z) return;
  z->gg.g.n = &x->AttributeStatement->gg.g;
  x->AttributeStatement = z;
}

/* FUNC(zx_sa_Assertion_REV_AttributeStatement) */

void zx_sa_Assertion_REV_AttributeStatement(struct zx_sa_Assertion_s* x)
{
  struct zx_sa_AttributeStatement_s* nxt;
  struct zx_sa_AttributeStatement_s* y;
  if (!x) return;
  y = x->AttributeStatement;
  if (!y) return;
  x->AttributeStatement = 0;
  while (y) {
    nxt = (struct zx_sa_AttributeStatement_s*)y->gg.g.n;
    y->gg.g.n = &x->AttributeStatement->gg.g;
    x->AttributeStatement = y;
    y = nxt;
  }
}

/* FUNC(zx_sa_Assertion_PUT_AttributeStatement) */

void zx_sa_Assertion_PUT_AttributeStatement(struct zx_sa_Assertion_s* x, int n, struct zx_sa_AttributeStatement_s* z)
{
  struct zx_sa_AttributeStatement_s* y;
  if (!x || !z) return;
  y = x->AttributeStatement;
  if (!y) return;
  switch (n) {
  case 0:
    z->gg.g.n = y->gg.g.n;
    x->AttributeStatement = z;
    return;
  default:
    for (; n > 1 && y->gg.g.n; --n, y = (struct zx_sa_AttributeStatement_s*)y->gg.g.n) ;
    if (!y->gg.g.n) return;
    z->gg.g.n = y->gg.g.n->n;
    y->gg.g.n = &z->gg.g;
  }
}

/* FUNC(zx_sa_Assertion_ADD_AttributeStatement) */

void zx_sa_Assertion_ADD_AttributeStatement(struct zx_sa_Assertion_s* x, int n, struct zx_sa_AttributeStatement_s* z)
{
  struct zx_sa_AttributeStatement_s* y;
  if (!x || !z) return;
  switch (n) {
  case 0:
  add_to_start:
    z->gg.g.n = &x->AttributeStatement->gg.g;
    x->AttributeStatement = z;
    return;
  case -1:
    y = x->AttributeStatement;
    if (!y) goto add_to_start;
    for (; y->gg.g.n; y = (struct zx_sa_AttributeStatement_s*)y->gg.g.n) ;
    break;
  default:
    for (y = x->AttributeStatement; n > 1 && y; --n, y = (struct zx_sa_AttributeStatement_s*)y->gg.g.n) ;
    if (!y) return;
  }
  z->gg.g.n = y->gg.g.n;
  y->gg.g.n = &z->gg.g;
}

/* FUNC(zx_sa_Assertion_DEL_AttributeStatement) */

void zx_sa_Assertion_DEL_AttributeStatement(struct zx_sa_Assertion_s* x, int n)
{
  struct zx_sa_AttributeStatement_s* y;
  if (!x) return;
  switch (n) {
  case 0:
    x->AttributeStatement = (struct zx_sa_AttributeStatement_s*)x->AttributeStatement->gg.g.n;
    return;
  case -1:
    y = (struct zx_sa_AttributeStatement_s*)x->AttributeStatement;
    if (!y) return;
    for (; y->gg.g.n; y = (struct zx_sa_AttributeStatement_s*)y->gg.g.n) ;
    break;
  default:
    for (y = x->AttributeStatement; n > 1 && y->gg.g.n; --n, y = (struct zx_sa_AttributeStatement_s*)y->gg.g.n) ;
    if (!y->gg.g.n) return;
  }
  y->gg.g.n = y->gg.g.n->n;
}

#endif



#ifdef ZX_ENA_GETPUT

/* FUNC(zx_sa_Assertion_NUM_XACMLAuthzDecisionStatement) */

int zx_sa_Assertion_NUM_XACMLAuthzDecisionStatement(struct zx_sa_Assertion_s* x)
{
  struct zx_xasa_XACMLAuthzDecisionStatement_s* y;
  int n = 0;
  if (!x) return 0;
  for (y = x->XACMLAuthzDecisionStatement; y; ++n, y = (struct zx_xasa_XACMLAuthzDecisionStatement_s*)y->gg.g.n) ;
  return n;
}

/* FUNC(zx_sa_Assertion_GET_XACMLAuthzDecisionStatement) */

struct zx_xasa_XACMLAuthzDecisionStatement_s* zx_sa_Assertion_GET_XACMLAuthzDecisionStatement(struct zx_sa_Assertion_s* x, int n)
{
  struct zx_xasa_XACMLAuthzDecisionStatement_s* y;
  if (!x) return 0;
  for (y = x->XACMLAuthzDecisionStatement; n>=0 && y; --n, y = (struct zx_xasa_XACMLAuthzDecisionStatement_s*)y->gg.g.n) ;
  return y;
}

/* FUNC(zx_sa_Assertion_POP_XACMLAuthzDecisionStatement) */

struct zx_xasa_XACMLAuthzDecisionStatement_s* zx_sa_Assertion_POP_XACMLAuthzDecisionStatement(struct zx_sa_Assertion_s* x)
{
  struct zx_xasa_XACMLAuthzDecisionStatement_s* y;
  if (!x) return 0;
  y = x->XACMLAuthzDecisionStatement;
  if (y)
    x->XACMLAuthzDecisionStatement = (struct zx_xasa_XACMLAuthzDecisionStatement_s*)y->gg.g.n;
  return y;
}

/* FUNC(zx_sa_Assertion_PUSH_XACMLAuthzDecisionStatement) */

void zx_sa_Assertion_PUSH_XACMLAuthzDecisionStatement(struct zx_sa_Assertion_s* x, struct zx_xasa_XACMLAuthzDecisionStatement_s* z)
{
  if (!x || !z) return;
  z->gg.g.n = &x->XACMLAuthzDecisionStatement->gg.g;
  x->XACMLAuthzDecisionStatement = z;
}

/* FUNC(zx_sa_Assertion_REV_XACMLAuthzDecisionStatement) */

void zx_sa_Assertion_REV_XACMLAuthzDecisionStatement(struct zx_sa_Assertion_s* x)
{
  struct zx_xasa_XACMLAuthzDecisionStatement_s* nxt;
  struct zx_xasa_XACMLAuthzDecisionStatement_s* y;
  if (!x) return;
  y = x->XACMLAuthzDecisionStatement;
  if (!y) return;
  x->XACMLAuthzDecisionStatement = 0;
  while (y) {
    nxt = (struct zx_xasa_XACMLAuthzDecisionStatement_s*)y->gg.g.n;
    y->gg.g.n = &x->XACMLAuthzDecisionStatement->gg.g;
    x->XACMLAuthzDecisionStatement = y;
    y = nxt;
  }
}

/* FUNC(zx_sa_Assertion_PUT_XACMLAuthzDecisionStatement) */

void zx_sa_Assertion_PUT_XACMLAuthzDecisionStatement(struct zx_sa_Assertion_s* x, int n, struct zx_xasa_XACMLAuthzDecisionStatement_s* z)
{
  struct zx_xasa_XACMLAuthzDecisionStatement_s* y;
  if (!x || !z) return;
  y = x->XACMLAuthzDecisionStatement;
  if (!y) return;
  switch (n) {
  case 0:
    z->gg.g.n = y->gg.g.n;
    x->XACMLAuthzDecisionStatement = z;
    return;
  default:
    for (; n > 1 && y->gg.g.n; --n, y = (struct zx_xasa_XACMLAuthzDecisionStatement_s*)y->gg.g.n) ;
    if (!y->gg.g.n) return;
    z->gg.g.n = y->gg.g.n->n;
    y->gg.g.n = &z->gg.g;
  }
}

/* FUNC(zx_sa_Assertion_ADD_XACMLAuthzDecisionStatement) */

void zx_sa_Assertion_ADD_XACMLAuthzDecisionStatement(struct zx_sa_Assertion_s* x, int n, struct zx_xasa_XACMLAuthzDecisionStatement_s* z)
{
  struct zx_xasa_XACMLAuthzDecisionStatement_s* y;
  if (!x || !z) return;
  switch (n) {
  case 0:
  add_to_start:
    z->gg.g.n = &x->XACMLAuthzDecisionStatement->gg.g;
    x->XACMLAuthzDecisionStatement = z;
    return;
  case -1:
    y = x->XACMLAuthzDecisionStatement;
    if (!y) goto add_to_start;
    for (; y->gg.g.n; y = (struct zx_xasa_XACMLAuthzDecisionStatement_s*)y->gg.g.n) ;
    break;
  default:
    for (y = x->XACMLAuthzDecisionStatement; n > 1 && y; --n, y = (struct zx_xasa_XACMLAuthzDecisionStatement_s*)y->gg.g.n) ;
    if (!y) return;
  }
  z->gg.g.n = y->gg.g.n;
  y->gg.g.n = &z->gg.g;
}

/* FUNC(zx_sa_Assertion_DEL_XACMLAuthzDecisionStatement) */

void zx_sa_Assertion_DEL_XACMLAuthzDecisionStatement(struct zx_sa_Assertion_s* x, int n)
{
  struct zx_xasa_XACMLAuthzDecisionStatement_s* y;
  if (!x) return;
  switch (n) {
  case 0:
    x->XACMLAuthzDecisionStatement = (struct zx_xasa_XACMLAuthzDecisionStatement_s*)x->XACMLAuthzDecisionStatement->gg.g.n;
    return;
  case -1:
    y = (struct zx_xasa_XACMLAuthzDecisionStatement_s*)x->XACMLAuthzDecisionStatement;
    if (!y) return;
    for (; y->gg.g.n; y = (struct zx_xasa_XACMLAuthzDecisionStatement_s*)y->gg.g.n) ;
    break;
  default:
    for (y = x->XACMLAuthzDecisionStatement; n > 1 && y->gg.g.n; --n, y = (struct zx_xasa_XACMLAuthzDecisionStatement_s*)y->gg.g.n) ;
    if (!y->gg.g.n) return;
  }
  y->gg.g.n = y->gg.g.n->n;
}

#endif



#ifdef ZX_ENA_GETPUT

/* FUNC(zx_sa_Assertion_NUM_XACMLPolicyStatement) */

int zx_sa_Assertion_NUM_XACMLPolicyStatement(struct zx_sa_Assertion_s* x)
{
  struct zx_xasa_XACMLPolicyStatement_s* y;
  int n = 0;
  if (!x) return 0;
  for (y = x->XACMLPolicyStatement; y; ++n, y = (struct zx_xasa_XACMLPolicyStatement_s*)y->gg.g.n) ;
  return n;
}

/* FUNC(zx_sa_Assertion_GET_XACMLPolicyStatement) */

struct zx_xasa_XACMLPolicyStatement_s* zx_sa_Assertion_GET_XACMLPolicyStatement(struct zx_sa_Assertion_s* x, int n)
{
  struct zx_xasa_XACMLPolicyStatement_s* y;
  if (!x) return 0;
  for (y = x->XACMLPolicyStatement; n>=0 && y; --n, y = (struct zx_xasa_XACMLPolicyStatement_s*)y->gg.g.n) ;
  return y;
}

/* FUNC(zx_sa_Assertion_POP_XACMLPolicyStatement) */

struct zx_xasa_XACMLPolicyStatement_s* zx_sa_Assertion_POP_XACMLPolicyStatement(struct zx_sa_Assertion_s* x)
{
  struct zx_xasa_XACMLPolicyStatement_s* y;
  if (!x) return 0;
  y = x->XACMLPolicyStatement;
  if (y)
    x->XACMLPolicyStatement = (struct zx_xasa_XACMLPolicyStatement_s*)y->gg.g.n;
  return y;
}

/* FUNC(zx_sa_Assertion_PUSH_XACMLPolicyStatement) */

void zx_sa_Assertion_PUSH_XACMLPolicyStatement(struct zx_sa_Assertion_s* x, struct zx_xasa_XACMLPolicyStatement_s* z)
{
  if (!x || !z) return;
  z->gg.g.n = &x->XACMLPolicyStatement->gg.g;
  x->XACMLPolicyStatement = z;
}

/* FUNC(zx_sa_Assertion_REV_XACMLPolicyStatement) */

void zx_sa_Assertion_REV_XACMLPolicyStatement(struct zx_sa_Assertion_s* x)
{
  struct zx_xasa_XACMLPolicyStatement_s* nxt;
  struct zx_xasa_XACMLPolicyStatement_s* y;
  if (!x) return;
  y = x->XACMLPolicyStatement;
  if (!y) return;
  x->XACMLPolicyStatement = 0;
  while (y) {
    nxt = (struct zx_xasa_XACMLPolicyStatement_s*)y->gg.g.n;
    y->gg.g.n = &x->XACMLPolicyStatement->gg.g;
    x->XACMLPolicyStatement = y;
    y = nxt;
  }
}

/* FUNC(zx_sa_Assertion_PUT_XACMLPolicyStatement) */

void zx_sa_Assertion_PUT_XACMLPolicyStatement(struct zx_sa_Assertion_s* x, int n, struct zx_xasa_XACMLPolicyStatement_s* z)
{
  struct zx_xasa_XACMLPolicyStatement_s* y;
  if (!x || !z) return;
  y = x->XACMLPolicyStatement;
  if (!y) return;
  switch (n) {
  case 0:
    z->gg.g.n = y->gg.g.n;
    x->XACMLPolicyStatement = z;
    return;
  default:
    for (; n > 1 && y->gg.g.n; --n, y = (struct zx_xasa_XACMLPolicyStatement_s*)y->gg.g.n) ;
    if (!y->gg.g.n) return;
    z->gg.g.n = y->gg.g.n->n;
    y->gg.g.n = &z->gg.g;
  }
}

/* FUNC(zx_sa_Assertion_ADD_XACMLPolicyStatement) */

void zx_sa_Assertion_ADD_XACMLPolicyStatement(struct zx_sa_Assertion_s* x, int n, struct zx_xasa_XACMLPolicyStatement_s* z)
{
  struct zx_xasa_XACMLPolicyStatement_s* y;
  if (!x || !z) return;
  switch (n) {
  case 0:
  add_to_start:
    z->gg.g.n = &x->XACMLPolicyStatement->gg.g;
    x->XACMLPolicyStatement = z;
    return;
  case -1:
    y = x->XACMLPolicyStatement;
    if (!y) goto add_to_start;
    for (; y->gg.g.n; y = (struct zx_xasa_XACMLPolicyStatement_s*)y->gg.g.n) ;
    break;
  default:
    for (y = x->XACMLPolicyStatement; n > 1 && y; --n, y = (struct zx_xasa_XACMLPolicyStatement_s*)y->gg.g.n) ;
    if (!y) return;
  }
  z->gg.g.n = y->gg.g.n;
  y->gg.g.n = &z->gg.g;
}

/* FUNC(zx_sa_Assertion_DEL_XACMLPolicyStatement) */

void zx_sa_Assertion_DEL_XACMLPolicyStatement(struct zx_sa_Assertion_s* x, int n)
{
  struct zx_xasa_XACMLPolicyStatement_s* y;
  if (!x) return;
  switch (n) {
  case 0:
    x->XACMLPolicyStatement = (struct zx_xasa_XACMLPolicyStatement_s*)x->XACMLPolicyStatement->gg.g.n;
    return;
  case -1:
    y = (struct zx_xasa_XACMLPolicyStatement_s*)x->XACMLPolicyStatement;
    if (!y) return;
    for (; y->gg.g.n; y = (struct zx_xasa_XACMLPolicyStatement_s*)y->gg.g.n) ;
    break;
  default:
    for (y = x->XACMLPolicyStatement; n > 1 && y->gg.g.n; --n, y = (struct zx_xasa_XACMLPolicyStatement_s*)y->gg.g.n) ;
    if (!y->gg.g.n) return;
  }
  y->gg.g.n = y->gg.g.n->n;
}

#endif



#ifdef ZX_ENA_GETPUT

/* FUNC(zx_sa_Assertion_NUM_xasacd1_XACMLAuthzDecisionStatement) */

int zx_sa_Assertion_NUM_xasacd1_XACMLAuthzDecisionStatement(struct zx_sa_Assertion_s* x)
{
  struct zx_xasacd1_XACMLAuthzDecisionStatement_s* y;
  int n = 0;
  if (!x) return 0;
  for (y = x->xasacd1_XACMLAuthzDecisionStatement; y; ++n, y = (struct zx_xasacd1_XACMLAuthzDecisionStatement_s*)y->gg.g.n) ;
  return n;
}

/* FUNC(zx_sa_Assertion_GET_xasacd1_XACMLAuthzDecisionStatement) */

struct zx_xasacd1_XACMLAuthzDecisionStatement_s* zx_sa_Assertion_GET_xasacd1_XACMLAuthzDecisionStatement(struct zx_sa_Assertion_s* x, int n)
{
  struct zx_xasacd1_XACMLAuthzDecisionStatement_s* y;
  if (!x) return 0;
  for (y = x->xasacd1_XACMLAuthzDecisionStatement; n>=0 && y; --n, y = (struct zx_xasacd1_XACMLAuthzDecisionStatement_s*)y->gg.g.n) ;
  return y;
}

/* FUNC(zx_sa_Assertion_POP_xasacd1_XACMLAuthzDecisionStatement) */

struct zx_xasacd1_XACMLAuthzDecisionStatement_s* zx_sa_Assertion_POP_xasacd1_XACMLAuthzDecisionStatement(struct zx_sa_Assertion_s* x)
{
  struct zx_xasacd1_XACMLAuthzDecisionStatement_s* y;
  if (!x) return 0;
  y = x->xasacd1_XACMLAuthzDecisionStatement;
  if (y)
    x->xasacd1_XACMLAuthzDecisionStatement = (struct zx_xasacd1_XACMLAuthzDecisionStatement_s*)y->gg.g.n;
  return y;
}

/* FUNC(zx_sa_Assertion_PUSH_xasacd1_XACMLAuthzDecisionStatement) */

void zx_sa_Assertion_PUSH_xasacd1_XACMLAuthzDecisionStatement(struct zx_sa_Assertion_s* x, struct zx_xasacd1_XACMLAuthzDecisionStatement_s* z)
{
  if (!x || !z) return;
  z->gg.g.n = &x->xasacd1_XACMLAuthzDecisionStatement->gg.g;
  x->xasacd1_XACMLAuthzDecisionStatement = z;
}

/* FUNC(zx_sa_Assertion_REV_xasacd1_XACMLAuthzDecisionStatement) */

void zx_sa_Assertion_REV_xasacd1_XACMLAuthzDecisionStatement(struct zx_sa_Assertion_s* x)
{
  struct zx_xasacd1_XACMLAuthzDecisionStatement_s* nxt;
  struct zx_xasacd1_XACMLAuthzDecisionStatement_s* y;
  if (!x) return;
  y = x->xasacd1_XACMLAuthzDecisionStatement;
  if (!y) return;
  x->xasacd1_XACMLAuthzDecisionStatement = 0;
  while (y) {
    nxt = (struct zx_xasacd1_XACMLAuthzDecisionStatement_s*)y->gg.g.n;
    y->gg.g.n = &x->xasacd1_XACMLAuthzDecisionStatement->gg.g;
    x->xasacd1_XACMLAuthzDecisionStatement = y;
    y = nxt;
  }
}

/* FUNC(zx_sa_Assertion_PUT_xasacd1_XACMLAuthzDecisionStatement) */

void zx_sa_Assertion_PUT_xasacd1_XACMLAuthzDecisionStatement(struct zx_sa_Assertion_s* x, int n, struct zx_xasacd1_XACMLAuthzDecisionStatement_s* z)
{
  struct zx_xasacd1_XACMLAuthzDecisionStatement_s* y;
  if (!x || !z) return;
  y = x->xasacd1_XACMLAuthzDecisionStatement;
  if (!y) return;
  switch (n) {
  case 0:
    z->gg.g.n = y->gg.g.n;
    x->xasacd1_XACMLAuthzDecisionStatement = z;
    return;
  default:
    for (; n > 1 && y->gg.g.n; --n, y = (struct zx_xasacd1_XACMLAuthzDecisionStatement_s*)y->gg.g.n) ;
    if (!y->gg.g.n) return;
    z->gg.g.n = y->gg.g.n->n;
    y->gg.g.n = &z->gg.g;
  }
}

/* FUNC(zx_sa_Assertion_ADD_xasacd1_XACMLAuthzDecisionStatement) */

void zx_sa_Assertion_ADD_xasacd1_XACMLAuthzDecisionStatement(struct zx_sa_Assertion_s* x, int n, struct zx_xasacd1_XACMLAuthzDecisionStatement_s* z)
{
  struct zx_xasacd1_XACMLAuthzDecisionStatement_s* y;
  if (!x || !z) return;
  switch (n) {
  case 0:
  add_to_start:
    z->gg.g.n = &x->xasacd1_XACMLAuthzDecisionStatement->gg.g;
    x->xasacd1_XACMLAuthzDecisionStatement = z;
    return;
  case -1:
    y = x->xasacd1_XACMLAuthzDecisionStatement;
    if (!y) goto add_to_start;
    for (; y->gg.g.n; y = (struct zx_xasacd1_XACMLAuthzDecisionStatement_s*)y->gg.g.n) ;
    break;
  default:
    for (y = x->xasacd1_XACMLAuthzDecisionStatement; n > 1 && y; --n, y = (struct zx_xasacd1_XACMLAuthzDecisionStatement_s*)y->gg.g.n) ;
    if (!y) return;
  }
  z->gg.g.n = y->gg.g.n;
  y->gg.g.n = &z->gg.g;
}

/* FUNC(zx_sa_Assertion_DEL_xasacd1_XACMLAuthzDecisionStatement) */

void zx_sa_Assertion_DEL_xasacd1_XACMLAuthzDecisionStatement(struct zx_sa_Assertion_s* x, int n)
{
  struct zx_xasacd1_XACMLAuthzDecisionStatement_s* y;
  if (!x) return;
  switch (n) {
  case 0:
    x->xasacd1_XACMLAuthzDecisionStatement = (struct zx_xasacd1_XACMLAuthzDecisionStatement_s*)x->xasacd1_XACMLAuthzDecisionStatement->gg.g.n;
    return;
  case -1:
    y = (struct zx_xasacd1_XACMLAuthzDecisionStatement_s*)x->xasacd1_XACMLAuthzDecisionStatement;
    if (!y) return;
    for (; y->gg.g.n; y = (struct zx_xasacd1_XACMLAuthzDecisionStatement_s*)y->gg.g.n) ;
    break;
  default:
    for (y = x->xasacd1_XACMLAuthzDecisionStatement; n > 1 && y->gg.g.n; --n, y = (struct zx_xasacd1_XACMLAuthzDecisionStatement_s*)y->gg.g.n) ;
    if (!y->gg.g.n) return;
  }
  y->gg.g.n = y->gg.g.n->n;
}

#endif



#ifdef ZX_ENA_GETPUT

/* FUNC(zx_sa_Assertion_NUM_xasacd1_XACMLPolicyStatement) */

int zx_sa_Assertion_NUM_xasacd1_XACMLPolicyStatement(struct zx_sa_Assertion_s* x)
{
  struct zx_xasacd1_XACMLPolicyStatement_s* y;
  int n = 0;
  if (!x) return 0;
  for (y = x->xasacd1_XACMLPolicyStatement; y; ++n, y = (struct zx_xasacd1_XACMLPolicyStatement_s*)y->gg.g.n) ;
  return n;
}

/* FUNC(zx_sa_Assertion_GET_xasacd1_XACMLPolicyStatement) */

struct zx_xasacd1_XACMLPolicyStatement_s* zx_sa_Assertion_GET_xasacd1_XACMLPolicyStatement(struct zx_sa_Assertion_s* x, int n)
{
  struct zx_xasacd1_XACMLPolicyStatement_s* y;
  if (!x) return 0;
  for (y = x->xasacd1_XACMLPolicyStatement; n>=0 && y; --n, y = (struct zx_xasacd1_XACMLPolicyStatement_s*)y->gg.g.n) ;
  return y;
}

/* FUNC(zx_sa_Assertion_POP_xasacd1_XACMLPolicyStatement) */

struct zx_xasacd1_XACMLPolicyStatement_s* zx_sa_Assertion_POP_xasacd1_XACMLPolicyStatement(struct zx_sa_Assertion_s* x)
{
  struct zx_xasacd1_XACMLPolicyStatement_s* y;
  if (!x) return 0;
  y = x->xasacd1_XACMLPolicyStatement;
  if (y)
    x->xasacd1_XACMLPolicyStatement = (struct zx_xasacd1_XACMLPolicyStatement_s*)y->gg.g.n;
  return y;
}

/* FUNC(zx_sa_Assertion_PUSH_xasacd1_XACMLPolicyStatement) */

void zx_sa_Assertion_PUSH_xasacd1_XACMLPolicyStatement(struct zx_sa_Assertion_s* x, struct zx_xasacd1_XACMLPolicyStatement_s* z)
{
  if (!x || !z) return;
  z->gg.g.n = &x->xasacd1_XACMLPolicyStatement->gg.g;
  x->xasacd1_XACMLPolicyStatement = z;
}

/* FUNC(zx_sa_Assertion_REV_xasacd1_XACMLPolicyStatement) */

void zx_sa_Assertion_REV_xasacd1_XACMLPolicyStatement(struct zx_sa_Assertion_s* x)
{
  struct zx_xasacd1_XACMLPolicyStatement_s* nxt;
  struct zx_xasacd1_XACMLPolicyStatement_s* y;
  if (!x) return;
  y = x->xasacd1_XACMLPolicyStatement;
  if (!y) return;
  x->xasacd1_XACMLPolicyStatement = 0;
  while (y) {
    nxt = (struct zx_xasacd1_XACMLPolicyStatement_s*)y->gg.g.n;
    y->gg.g.n = &x->xasacd1_XACMLPolicyStatement->gg.g;
    x->xasacd1_XACMLPolicyStatement = y;
    y = nxt;
  }
}

/* FUNC(zx_sa_Assertion_PUT_xasacd1_XACMLPolicyStatement) */

void zx_sa_Assertion_PUT_xasacd1_XACMLPolicyStatement(struct zx_sa_Assertion_s* x, int n, struct zx_xasacd1_XACMLPolicyStatement_s* z)
{
  struct zx_xasacd1_XACMLPolicyStatement_s* y;
  if (!x || !z) return;
  y = x->xasacd1_XACMLPolicyStatement;
  if (!y) return;
  switch (n) {
  case 0:
    z->gg.g.n = y->gg.g.n;
    x->xasacd1_XACMLPolicyStatement = z;
    return;
  default:
    for (; n > 1 && y->gg.g.n; --n, y = (struct zx_xasacd1_XACMLPolicyStatement_s*)y->gg.g.n) ;
    if (!y->gg.g.n) return;
    z->gg.g.n = y->gg.g.n->n;
    y->gg.g.n = &z->gg.g;
  }
}

/* FUNC(zx_sa_Assertion_ADD_xasacd1_XACMLPolicyStatement) */

void zx_sa_Assertion_ADD_xasacd1_XACMLPolicyStatement(struct zx_sa_Assertion_s* x, int n, struct zx_xasacd1_XACMLPolicyStatement_s* z)
{
  struct zx_xasacd1_XACMLPolicyStatement_s* y;
  if (!x || !z) return;
  switch (n) {
  case 0:
  add_to_start:
    z->gg.g.n = &x->xasacd1_XACMLPolicyStatement->gg.g;
    x->xasacd1_XACMLPolicyStatement = z;
    return;
  case -1:
    y = x->xasacd1_XACMLPolicyStatement;
    if (!y) goto add_to_start;
    for (; y->gg.g.n; y = (struct zx_xasacd1_XACMLPolicyStatement_s*)y->gg.g.n) ;
    break;
  default:
    for (y = x->xasacd1_XACMLPolicyStatement; n > 1 && y; --n, y = (struct zx_xasacd1_XACMLPolicyStatement_s*)y->gg.g.n) ;
    if (!y) return;
  }
  z->gg.g.n = y->gg.g.n;
  y->gg.g.n = &z->gg.g;
}

/* FUNC(zx_sa_Assertion_DEL_xasacd1_XACMLPolicyStatement) */

void zx_sa_Assertion_DEL_xasacd1_XACMLPolicyStatement(struct zx_sa_Assertion_s* x, int n)
{
  struct zx_xasacd1_XACMLPolicyStatement_s* y;
  if (!x) return;
  switch (n) {
  case 0:
    x->xasacd1_XACMLPolicyStatement = (struct zx_xasacd1_XACMLPolicyStatement_s*)x->xasacd1_XACMLPolicyStatement->gg.g.n;
    return;
  case -1:
    y = (struct zx_xasacd1_XACMLPolicyStatement_s*)x->xasacd1_XACMLPolicyStatement;
    if (!y) return;
    for (; y->gg.g.n; y = (struct zx_xasacd1_XACMLPolicyStatement_s*)y->gg.g.n) ;
    break;
  default:
    for (y = x->xasacd1_XACMLPolicyStatement; n > 1 && y->gg.g.n; --n, y = (struct zx_xasacd1_XACMLPolicyStatement_s*)y->gg.g.n) ;
    if (!y->gg.g.n) return;
  }
  y->gg.g.n = y->gg.g.n->n;
}

#endif

/* FUNC(zx_sa_Assertion_GET_ID) */
struct zx_str* zx_sa_Assertion_GET_ID(struct zx_sa_Assertion_s* x) { return x->ID; }
/* FUNC(zx_sa_Assertion_PUT_ID) */
void zx_sa_Assertion_PUT_ID(struct zx_sa_Assertion_s* x, struct zx_str* y) { x->ID = y; }
/* FUNC(zx_sa_Assertion_GET_IssueInstant) */
struct zx_str* zx_sa_Assertion_GET_IssueInstant(struct zx_sa_Assertion_s* x) { return x->IssueInstant; }
/* FUNC(zx_sa_Assertion_PUT_IssueInstant) */
void zx_sa_Assertion_PUT_IssueInstant(struct zx_sa_Assertion_s* x, struct zx_str* y) { x->IssueInstant = y; }
/* FUNC(zx_sa_Assertion_GET_Version) */
struct zx_str* zx_sa_Assertion_GET_Version(struct zx_sa_Assertion_s* x) { return x->Version; }
/* FUNC(zx_sa_Assertion_PUT_Version) */
void zx_sa_Assertion_PUT_Version(struct zx_sa_Assertion_s* x, struct zx_str* y) { x->Version = y; }







#ifdef ZX_ENA_GETPUT

/* FUNC(zx_sa_Attribute_NUM_AttributeValue) */

int zx_sa_Attribute_NUM_AttributeValue(struct zx_sa_Attribute_s* x)
{
  struct zx_sa_AttributeValue_s* y;
  int n = 0;
  if (!x) return 0;
  for (y = x->AttributeValue; y; ++n, y = (struct zx_sa_AttributeValue_s*)y->gg.g.n) ;
  return n;
}

/* FUNC(zx_sa_Attribute_GET_AttributeValue) */

struct zx_sa_AttributeValue_s* zx_sa_Attribute_GET_AttributeValue(struct zx_sa_Attribute_s* x, int n)
{
  struct zx_sa_AttributeValue_s* y;
  if (!x) return 0;
  for (y = x->AttributeValue; n>=0 && y; --n, y = (struct zx_sa_AttributeValue_s*)y->gg.g.n) ;
  return y;
}

/* FUNC(zx_sa_Attribute_POP_AttributeValue) */

struct zx_sa_AttributeValue_s* zx_sa_Attribute_POP_AttributeValue(struct zx_sa_Attribute_s* x)
{
  struct zx_sa_AttributeValue_s* y;
  if (!x) return 0;
  y = x->AttributeValue;
  if (y)
    x->AttributeValue = (struct zx_sa_AttributeValue_s*)y->gg.g.n;
  return y;
}

/* FUNC(zx_sa_Attribute_PUSH_AttributeValue) */

void zx_sa_Attribute_PUSH_AttributeValue(struct zx_sa_Attribute_s* x, struct zx_sa_AttributeValue_s* z)
{
  if (!x || !z) return;
  z->gg.g.n = &x->AttributeValue->gg.g;
  x->AttributeValue = z;
}

/* FUNC(zx_sa_Attribute_REV_AttributeValue) */

void zx_sa_Attribute_REV_AttributeValue(struct zx_sa_Attribute_s* x)
{
  struct zx_sa_AttributeValue_s* nxt;
  struct zx_sa_AttributeValue_s* y;
  if (!x) return;
  y = x->AttributeValue;
  if (!y) return;
  x->AttributeValue = 0;
  while (y) {
    nxt = (struct zx_sa_AttributeValue_s*)y->gg.g.n;
    y->gg.g.n = &x->AttributeValue->gg.g;
    x->AttributeValue = y;
    y = nxt;
  }
}

/* FUNC(zx_sa_Attribute_PUT_AttributeValue) */

void zx_sa_Attribute_PUT_AttributeValue(struct zx_sa_Attribute_s* x, int n, struct zx_sa_AttributeValue_s* z)
{
  struct zx_sa_AttributeValue_s* y;
  if (!x || !z) return;
  y = x->AttributeValue;
  if (!y) return;
  switch (n) {
  case 0:
    z->gg.g.n = y->gg.g.n;
    x->AttributeValue = z;
    return;
  default:
    for (; n > 1 && y->gg.g.n; --n, y = (struct zx_sa_AttributeValue_s*)y->gg.g.n) ;
    if (!y->gg.g.n) return;
    z->gg.g.n = y->gg.g.n->n;
    y->gg.g.n = &z->gg.g;
  }
}

/* FUNC(zx_sa_Attribute_ADD_AttributeValue) */

void zx_sa_Attribute_ADD_AttributeValue(struct zx_sa_Attribute_s* x, int n, struct zx_sa_AttributeValue_s* z)
{
  struct zx_sa_AttributeValue_s* y;
  if (!x || !z) return;
  switch (n) {
  case 0:
  add_to_start:
    z->gg.g.n = &x->AttributeValue->gg.g;
    x->AttributeValue = z;
    return;
  case -1:
    y = x->AttributeValue;
    if (!y) goto add_to_start;
    for (; y->gg.g.n; y = (struct zx_sa_AttributeValue_s*)y->gg.g.n) ;
    break;
  default:
    for (y = x->AttributeValue; n > 1 && y; --n, y = (struct zx_sa_AttributeValue_s*)y->gg.g.n) ;
    if (!y) return;
  }
  z->gg.g.n = y->gg.g.n;
  y->gg.g.n = &z->gg.g;
}

/* FUNC(zx_sa_Attribute_DEL_AttributeValue) */

void zx_sa_Attribute_DEL_AttributeValue(struct zx_sa_Attribute_s* x, int n)
{
  struct zx_sa_AttributeValue_s* y;
  if (!x) return;
  switch (n) {
  case 0:
    x->AttributeValue = (struct zx_sa_AttributeValue_s*)x->AttributeValue->gg.g.n;
    return;
  case -1:
    y = (struct zx_sa_AttributeValue_s*)x->AttributeValue;
    if (!y) return;
    for (; y->gg.g.n; y = (struct zx_sa_AttributeValue_s*)y->gg.g.n) ;
    break;
  default:
    for (y = x->AttributeValue; n > 1 && y->gg.g.n; --n, y = (struct zx_sa_AttributeValue_s*)y->gg.g.n) ;
    if (!y->gg.g.n) return;
  }
  y->gg.g.n = y->gg.g.n->n;
}

#endif

/* FUNC(zx_sa_Attribute_GET_FriendlyName) */
struct zx_str* zx_sa_Attribute_GET_FriendlyName(struct zx_sa_Attribute_s* x) { return x->FriendlyName; }
/* FUNC(zx_sa_Attribute_PUT_FriendlyName) */
void zx_sa_Attribute_PUT_FriendlyName(struct zx_sa_Attribute_s* x, struct zx_str* y) { x->FriendlyName = y; }
/* FUNC(zx_sa_Attribute_GET_Name) */
struct zx_str* zx_sa_Attribute_GET_Name(struct zx_sa_Attribute_s* x) { return x->Name; }
/* FUNC(zx_sa_Attribute_PUT_Name) */
void zx_sa_Attribute_PUT_Name(struct zx_sa_Attribute_s* x, struct zx_str* y) { x->Name = y; }
/* FUNC(zx_sa_Attribute_GET_NameFormat) */
struct zx_str* zx_sa_Attribute_GET_NameFormat(struct zx_sa_Attribute_s* x) { return x->NameFormat; }
/* FUNC(zx_sa_Attribute_PUT_NameFormat) */
void zx_sa_Attribute_PUT_NameFormat(struct zx_sa_Attribute_s* x, struct zx_str* y) { x->NameFormat = y; }







#ifdef ZX_ENA_GETPUT

/* FUNC(zx_sa_AttributeStatement_NUM_Attribute) */

int zx_sa_AttributeStatement_NUM_Attribute(struct zx_sa_AttributeStatement_s* x)
{
  struct zx_sa_Attribute_s* y;
  int n = 0;
  if (!x) return 0;
  for (y = x->Attribute; y; ++n, y = (struct zx_sa_Attribute_s*)y->gg.g.n) ;
  return n;
}

/* FUNC(zx_sa_AttributeStatement_GET_Attribute) */

struct zx_sa_Attribute_s* zx_sa_AttributeStatement_GET_Attribute(struct zx_sa_AttributeStatement_s* x, int n)
{
  struct zx_sa_Attribute_s* y;
  if (!x) return 0;
  for (y = x->Attribute; n>=0 && y; --n, y = (struct zx_sa_Attribute_s*)y->gg.g.n) ;
  return y;
}

/* FUNC(zx_sa_AttributeStatement_POP_Attribute) */

struct zx_sa_Attribute_s* zx_sa_AttributeStatement_POP_Attribute(struct zx_sa_AttributeStatement_s* x)
{
  struct zx_sa_Attribute_s* y;
  if (!x) return 0;
  y = x->Attribute;
  if (y)
    x->Attribute = (struct zx_sa_Attribute_s*)y->gg.g.n;
  return y;
}

/* FUNC(zx_sa_AttributeStatement_PUSH_Attribute) */

void zx_sa_AttributeStatement_PUSH_Attribute(struct zx_sa_AttributeStatement_s* x, struct zx_sa_Attribute_s* z)
{
  if (!x || !z) return;
  z->gg.g.n = &x->Attribute->gg.g;
  x->Attribute = z;
}

/* FUNC(zx_sa_AttributeStatement_REV_Attribute) */

void zx_sa_AttributeStatement_REV_Attribute(struct zx_sa_AttributeStatement_s* x)
{
  struct zx_sa_Attribute_s* nxt;
  struct zx_sa_Attribute_s* y;
  if (!x) return;
  y = x->Attribute;
  if (!y) return;
  x->Attribute = 0;
  while (y) {
    nxt = (struct zx_sa_Attribute_s*)y->gg.g.n;
    y->gg.g.n = &x->Attribute->gg.g;
    x->Attribute = y;
    y = nxt;
  }
}

/* FUNC(zx_sa_AttributeStatement_PUT_Attribute) */

void zx_sa_AttributeStatement_PUT_Attribute(struct zx_sa_AttributeStatement_s* x, int n, struct zx_sa_Attribute_s* z)
{
  struct zx_sa_Attribute_s* y;
  if (!x || !z) return;
  y = x->Attribute;
  if (!y) return;
  switch (n) {
  case 0:
    z->gg.g.n = y->gg.g.n;
    x->Attribute = z;
    return;
  default:
    for (; n > 1 && y->gg.g.n; --n, y = (struct zx_sa_Attribute_s*)y->gg.g.n) ;
    if (!y->gg.g.n) return;
    z->gg.g.n = y->gg.g.n->n;
    y->gg.g.n = &z->gg.g;
  }
}

/* FUNC(zx_sa_AttributeStatement_ADD_Attribute) */

void zx_sa_AttributeStatement_ADD_Attribute(struct zx_sa_AttributeStatement_s* x, int n, struct zx_sa_Attribute_s* z)
{
  struct zx_sa_Attribute_s* y;
  if (!x || !z) return;
  switch (n) {
  case 0:
  add_to_start:
    z->gg.g.n = &x->Attribute->gg.g;
    x->Attribute = z;
    return;
  case -1:
    y = x->Attribute;
    if (!y) goto add_to_start;
    for (; y->gg.g.n; y = (struct zx_sa_Attribute_s*)y->gg.g.n) ;
    break;
  default:
    for (y = x->Attribute; n > 1 && y; --n, y = (struct zx_sa_Attribute_s*)y->gg.g.n) ;
    if (!y) return;
  }
  z->gg.g.n = y->gg.g.n;
  y->gg.g.n = &z->gg.g;
}

/* FUNC(zx_sa_AttributeStatement_DEL_Attribute) */

void zx_sa_AttributeStatement_DEL_Attribute(struct zx_sa_AttributeStatement_s* x, int n)
{
  struct zx_sa_Attribute_s* y;
  if (!x) return;
  switch (n) {
  case 0:
    x->Attribute = (struct zx_sa_Attribute_s*)x->Attribute->gg.g.n;
    return;
  case -1:
    y = (struct zx_sa_Attribute_s*)x->Attribute;
    if (!y) return;
    for (; y->gg.g.n; y = (struct zx_sa_Attribute_s*)y->gg.g.n) ;
    break;
  default:
    for (y = x->Attribute; n > 1 && y->gg.g.n; --n, y = (struct zx_sa_Attribute_s*)y->gg.g.n) ;
    if (!y->gg.g.n) return;
  }
  y->gg.g.n = y->gg.g.n->n;
}

#endif



#ifdef ZX_ENA_GETPUT

/* FUNC(zx_sa_AttributeStatement_NUM_EncryptedAttribute) */

int zx_sa_AttributeStatement_NUM_EncryptedAttribute(struct zx_sa_AttributeStatement_s* x)
{
  struct zx_sa_EncryptedAttribute_s* y;
  int n = 0;
  if (!x) return 0;
  for (y = x->EncryptedAttribute; y; ++n, y = (struct zx_sa_EncryptedAttribute_s*)y->gg.g.n) ;
  return n;
}

/* FUNC(zx_sa_AttributeStatement_GET_EncryptedAttribute) */

struct zx_sa_EncryptedAttribute_s* zx_sa_AttributeStatement_GET_EncryptedAttribute(struct zx_sa_AttributeStatement_s* x, int n)
{
  struct zx_sa_EncryptedAttribute_s* y;
  if (!x) return 0;
  for (y = x->EncryptedAttribute; n>=0 && y; --n, y = (struct zx_sa_EncryptedAttribute_s*)y->gg.g.n) ;
  return y;
}

/* FUNC(zx_sa_AttributeStatement_POP_EncryptedAttribute) */

struct zx_sa_EncryptedAttribute_s* zx_sa_AttributeStatement_POP_EncryptedAttribute(struct zx_sa_AttributeStatement_s* x)
{
  struct zx_sa_EncryptedAttribute_s* y;
  if (!x) return 0;
  y = x->EncryptedAttribute;
  if (y)
    x->EncryptedAttribute = (struct zx_sa_EncryptedAttribute_s*)y->gg.g.n;
  return y;
}

/* FUNC(zx_sa_AttributeStatement_PUSH_EncryptedAttribute) */

void zx_sa_AttributeStatement_PUSH_EncryptedAttribute(struct zx_sa_AttributeStatement_s* x, struct zx_sa_EncryptedAttribute_s* z)
{
  if (!x || !z) return;
  z->gg.g.n = &x->EncryptedAttribute->gg.g;
  x->EncryptedAttribute = z;
}

/* FUNC(zx_sa_AttributeStatement_REV_EncryptedAttribute) */

void zx_sa_AttributeStatement_REV_EncryptedAttribute(struct zx_sa_AttributeStatement_s* x)
{
  struct zx_sa_EncryptedAttribute_s* nxt;
  struct zx_sa_EncryptedAttribute_s* y;
  if (!x) return;
  y = x->EncryptedAttribute;
  if (!y) return;
  x->EncryptedAttribute = 0;
  while (y) {
    nxt = (struct zx_sa_EncryptedAttribute_s*)y->gg.g.n;
    y->gg.g.n = &x->EncryptedAttribute->gg.g;
    x->EncryptedAttribute = y;
    y = nxt;
  }
}

/* FUNC(zx_sa_AttributeStatement_PUT_EncryptedAttribute) */

void zx_sa_AttributeStatement_PUT_EncryptedAttribute(struct zx_sa_AttributeStatement_s* x, int n, struct zx_sa_EncryptedAttribute_s* z)
{
  struct zx_sa_EncryptedAttribute_s* y;
  if (!x || !z) return;
  y = x->EncryptedAttribute;
  if (!y) return;
  switch (n) {
  case 0:
    z->gg.g.n = y->gg.g.n;
    x->EncryptedAttribute = z;
    return;
  default:
    for (; n > 1 && y->gg.g.n; --n, y = (struct zx_sa_EncryptedAttribute_s*)y->gg.g.n) ;
    if (!y->gg.g.n) return;
    z->gg.g.n = y->gg.g.n->n;
    y->gg.g.n = &z->gg.g;
  }
}

/* FUNC(zx_sa_AttributeStatement_ADD_EncryptedAttribute) */

void zx_sa_AttributeStatement_ADD_EncryptedAttribute(struct zx_sa_AttributeStatement_s* x, int n, struct zx_sa_EncryptedAttribute_s* z)
{
  struct zx_sa_EncryptedAttribute_s* y;
  if (!x || !z) return;
  switch (n) {
  case 0:
  add_to_start:
    z->gg.g.n = &x->EncryptedAttribute->gg.g;
    x->EncryptedAttribute = z;
    return;
  case -1:
    y = x->EncryptedAttribute;
    if (!y) goto add_to_start;
    for (; y->gg.g.n; y = (struct zx_sa_EncryptedAttribute_s*)y->gg.g.n) ;
    break;
  default:
    for (y = x->EncryptedAttribute; n > 1 && y; --n, y = (struct zx_sa_EncryptedAttribute_s*)y->gg.g.n) ;
    if (!y) return;
  }
  z->gg.g.n = y->gg.g.n;
  y->gg.g.n = &z->gg.g;
}

/* FUNC(zx_sa_AttributeStatement_DEL_EncryptedAttribute) */

void zx_sa_AttributeStatement_DEL_EncryptedAttribute(struct zx_sa_AttributeStatement_s* x, int n)
{
  struct zx_sa_EncryptedAttribute_s* y;
  if (!x) return;
  switch (n) {
  case 0:
    x->EncryptedAttribute = (struct zx_sa_EncryptedAttribute_s*)x->EncryptedAttribute->gg.g.n;
    return;
  case -1:
    y = (struct zx_sa_EncryptedAttribute_s*)x->EncryptedAttribute;
    if (!y) return;
    for (; y->gg.g.n; y = (struct zx_sa_EncryptedAttribute_s*)y->gg.g.n) ;
    break;
  default:
    for (y = x->EncryptedAttribute; n > 1 && y->gg.g.n; --n, y = (struct zx_sa_EncryptedAttribute_s*)y->gg.g.n) ;
    if (!y->gg.g.n) return;
  }
  y->gg.g.n = y->gg.g.n->n;
}

#endif








#ifdef ZX_ENA_GETPUT

/* FUNC(zx_sa_AttributeValue_NUM_ResourceOffering) */

int zx_sa_AttributeValue_NUM_ResourceOffering(struct zx_sa_AttributeValue_s* x)
{
  struct zx_di12_ResourceOffering_s* y;
  int n = 0;
  if (!x) return 0;
  for (y = x->ResourceOffering; y; ++n, y = (struct zx_di12_ResourceOffering_s*)y->gg.g.n) ;
  return n;
}

/* FUNC(zx_sa_AttributeValue_GET_ResourceOffering) */

struct zx_di12_ResourceOffering_s* zx_sa_AttributeValue_GET_ResourceOffering(struct zx_sa_AttributeValue_s* x, int n)
{
  struct zx_di12_ResourceOffering_s* y;
  if (!x) return 0;
  for (y = x->ResourceOffering; n>=0 && y; --n, y = (struct zx_di12_ResourceOffering_s*)y->gg.g.n) ;
  return y;
}

/* FUNC(zx_sa_AttributeValue_POP_ResourceOffering) */

struct zx_di12_ResourceOffering_s* zx_sa_AttributeValue_POP_ResourceOffering(struct zx_sa_AttributeValue_s* x)
{
  struct zx_di12_ResourceOffering_s* y;
  if (!x) return 0;
  y = x->ResourceOffering;
  if (y)
    x->ResourceOffering = (struct zx_di12_ResourceOffering_s*)y->gg.g.n;
  return y;
}

/* FUNC(zx_sa_AttributeValue_PUSH_ResourceOffering) */

void zx_sa_AttributeValue_PUSH_ResourceOffering(struct zx_sa_AttributeValue_s* x, struct zx_di12_ResourceOffering_s* z)
{
  if (!x || !z) return;
  z->gg.g.n = &x->ResourceOffering->gg.g;
  x->ResourceOffering = z;
}

/* FUNC(zx_sa_AttributeValue_REV_ResourceOffering) */

void zx_sa_AttributeValue_REV_ResourceOffering(struct zx_sa_AttributeValue_s* x)
{
  struct zx_di12_ResourceOffering_s* nxt;
  struct zx_di12_ResourceOffering_s* y;
  if (!x) return;
  y = x->ResourceOffering;
  if (!y) return;
  x->ResourceOffering = 0;
  while (y) {
    nxt = (struct zx_di12_ResourceOffering_s*)y->gg.g.n;
    y->gg.g.n = &x->ResourceOffering->gg.g;
    x->ResourceOffering = y;
    y = nxt;
  }
}

/* FUNC(zx_sa_AttributeValue_PUT_ResourceOffering) */

void zx_sa_AttributeValue_PUT_ResourceOffering(struct zx_sa_AttributeValue_s* x, int n, struct zx_di12_ResourceOffering_s* z)
{
  struct zx_di12_ResourceOffering_s* y;
  if (!x || !z) return;
  y = x->ResourceOffering;
  if (!y) return;
  switch (n) {
  case 0:
    z->gg.g.n = y->gg.g.n;
    x->ResourceOffering = z;
    return;
  default:
    for (; n > 1 && y->gg.g.n; --n, y = (struct zx_di12_ResourceOffering_s*)y->gg.g.n) ;
    if (!y->gg.g.n) return;
    z->gg.g.n = y->gg.g.n->n;
    y->gg.g.n = &z->gg.g;
  }
}

/* FUNC(zx_sa_AttributeValue_ADD_ResourceOffering) */

void zx_sa_AttributeValue_ADD_ResourceOffering(struct zx_sa_AttributeValue_s* x, int n, struct zx_di12_ResourceOffering_s* z)
{
  struct zx_di12_ResourceOffering_s* y;
  if (!x || !z) return;
  switch (n) {
  case 0:
  add_to_start:
    z->gg.g.n = &x->ResourceOffering->gg.g;
    x->ResourceOffering = z;
    return;
  case -1:
    y = x->ResourceOffering;
    if (!y) goto add_to_start;
    for (; y->gg.g.n; y = (struct zx_di12_ResourceOffering_s*)y->gg.g.n) ;
    break;
  default:
    for (y = x->ResourceOffering; n > 1 && y; --n, y = (struct zx_di12_ResourceOffering_s*)y->gg.g.n) ;
    if (!y) return;
  }
  z->gg.g.n = y->gg.g.n;
  y->gg.g.n = &z->gg.g;
}

/* FUNC(zx_sa_AttributeValue_DEL_ResourceOffering) */

void zx_sa_AttributeValue_DEL_ResourceOffering(struct zx_sa_AttributeValue_s* x, int n)
{
  struct zx_di12_ResourceOffering_s* y;
  if (!x) return;
  switch (n) {
  case 0:
    x->ResourceOffering = (struct zx_di12_ResourceOffering_s*)x->ResourceOffering->gg.g.n;
    return;
  case -1:
    y = (struct zx_di12_ResourceOffering_s*)x->ResourceOffering;
    if (!y) return;
    for (; y->gg.g.n; y = (struct zx_di12_ResourceOffering_s*)y->gg.g.n) ;
    break;
  default:
    for (y = x->ResourceOffering; n > 1 && y->gg.g.n; --n, y = (struct zx_di12_ResourceOffering_s*)y->gg.g.n) ;
    if (!y->gg.g.n) return;
  }
  y->gg.g.n = y->gg.g.n->n;
}

#endif



#ifdef ZX_ENA_GETPUT

/* FUNC(zx_sa_AttributeValue_NUM_EndpointReference) */

int zx_sa_AttributeValue_NUM_EndpointReference(struct zx_sa_AttributeValue_s* x)
{
  struct zx_a_EndpointReference_s* y;
  int n = 0;
  if (!x) return 0;
  for (y = x->EndpointReference; y; ++n, y = (struct zx_a_EndpointReference_s*)y->gg.g.n) ;
  return n;
}

/* FUNC(zx_sa_AttributeValue_GET_EndpointReference) */

struct zx_a_EndpointReference_s* zx_sa_AttributeValue_GET_EndpointReference(struct zx_sa_AttributeValue_s* x, int n)
{
  struct zx_a_EndpointReference_s* y;
  if (!x) return 0;
  for (y = x->EndpointReference; n>=0 && y; --n, y = (struct zx_a_EndpointReference_s*)y->gg.g.n) ;
  return y;
}

/* FUNC(zx_sa_AttributeValue_POP_EndpointReference) */

struct zx_a_EndpointReference_s* zx_sa_AttributeValue_POP_EndpointReference(struct zx_sa_AttributeValue_s* x)
{
  struct zx_a_EndpointReference_s* y;
  if (!x) return 0;
  y = x->EndpointReference;
  if (y)
    x->EndpointReference = (struct zx_a_EndpointReference_s*)y->gg.g.n;
  return y;
}

/* FUNC(zx_sa_AttributeValue_PUSH_EndpointReference) */

void zx_sa_AttributeValue_PUSH_EndpointReference(struct zx_sa_AttributeValue_s* x, struct zx_a_EndpointReference_s* z)
{
  if (!x || !z) return;
  z->gg.g.n = &x->EndpointReference->gg.g;
  x->EndpointReference = z;
}

/* FUNC(zx_sa_AttributeValue_REV_EndpointReference) */

void zx_sa_AttributeValue_REV_EndpointReference(struct zx_sa_AttributeValue_s* x)
{
  struct zx_a_EndpointReference_s* nxt;
  struct zx_a_EndpointReference_s* y;
  if (!x) return;
  y = x->EndpointReference;
  if (!y) return;
  x->EndpointReference = 0;
  while (y) {
    nxt = (struct zx_a_EndpointReference_s*)y->gg.g.n;
    y->gg.g.n = &x->EndpointReference->gg.g;
    x->EndpointReference = y;
    y = nxt;
  }
}

/* FUNC(zx_sa_AttributeValue_PUT_EndpointReference) */

void zx_sa_AttributeValue_PUT_EndpointReference(struct zx_sa_AttributeValue_s* x, int n, struct zx_a_EndpointReference_s* z)
{
  struct zx_a_EndpointReference_s* y;
  if (!x || !z) return;
  y = x->EndpointReference;
  if (!y) return;
  switch (n) {
  case 0:
    z->gg.g.n = y->gg.g.n;
    x->EndpointReference = z;
    return;
  default:
    for (; n > 1 && y->gg.g.n; --n, y = (struct zx_a_EndpointReference_s*)y->gg.g.n) ;
    if (!y->gg.g.n) return;
    z->gg.g.n = y->gg.g.n->n;
    y->gg.g.n = &z->gg.g;
  }
}

/* FUNC(zx_sa_AttributeValue_ADD_EndpointReference) */

void zx_sa_AttributeValue_ADD_EndpointReference(struct zx_sa_AttributeValue_s* x, int n, struct zx_a_EndpointReference_s* z)
{
  struct zx_a_EndpointReference_s* y;
  if (!x || !z) return;
  switch (n) {
  case 0:
  add_to_start:
    z->gg.g.n = &x->EndpointReference->gg.g;
    x->EndpointReference = z;
    return;
  case -1:
    y = x->EndpointReference;
    if (!y) goto add_to_start;
    for (; y->gg.g.n; y = (struct zx_a_EndpointReference_s*)y->gg.g.n) ;
    break;
  default:
    for (y = x->EndpointReference; n > 1 && y; --n, y = (struct zx_a_EndpointReference_s*)y->gg.g.n) ;
    if (!y) return;
  }
  z->gg.g.n = y->gg.g.n;
  y->gg.g.n = &z->gg.g;
}

/* FUNC(zx_sa_AttributeValue_DEL_EndpointReference) */

void zx_sa_AttributeValue_DEL_EndpointReference(struct zx_sa_AttributeValue_s* x, int n)
{
  struct zx_a_EndpointReference_s* y;
  if (!x) return;
  switch (n) {
  case 0:
    x->EndpointReference = (struct zx_a_EndpointReference_s*)x->EndpointReference->gg.g.n;
    return;
  case -1:
    y = (struct zx_a_EndpointReference_s*)x->EndpointReference;
    if (!y) return;
    for (; y->gg.g.n; y = (struct zx_a_EndpointReference_s*)y->gg.g.n) ;
    break;
  default:
    for (y = x->EndpointReference; n > 1 && y->gg.g.n; --n, y = (struct zx_a_EndpointReference_s*)y->gg.g.n) ;
    if (!y->gg.g.n) return;
  }
  y->gg.g.n = y->gg.g.n->n;
}

#endif








#ifdef ZX_ENA_GETPUT

/* FUNC(zx_sa_AudienceRestriction_NUM_Audience) */

int zx_sa_AudienceRestriction_NUM_Audience(struct zx_sa_AudienceRestriction_s* x)
{
  struct zx_elem_s* y;
  int n = 0;
  if (!x) return 0;
  for (y = x->Audience; y; ++n, y = (struct zx_elem_s*)y->g.n) ;
  return n;
}

/* FUNC(zx_sa_AudienceRestriction_GET_Audience) */

struct zx_elem_s* zx_sa_AudienceRestriction_GET_Audience(struct zx_sa_AudienceRestriction_s* x, int n)
{
  struct zx_elem_s* y;
  if (!x) return 0;
  for (y = x->Audience; n>=0 && y; --n, y = (struct zx_elem_s*)y->g.n) ;
  return y;
}

/* FUNC(zx_sa_AudienceRestriction_POP_Audience) */

struct zx_elem_s* zx_sa_AudienceRestriction_POP_Audience(struct zx_sa_AudienceRestriction_s* x)
{
  struct zx_elem_s* y;
  if (!x) return 0;
  y = x->Audience;
  if (y)
    x->Audience = (struct zx_elem_s*)y->g.n;
  return y;
}

/* FUNC(zx_sa_AudienceRestriction_PUSH_Audience) */

void zx_sa_AudienceRestriction_PUSH_Audience(struct zx_sa_AudienceRestriction_s* x, struct zx_elem_s* z)
{
  if (!x || !z) return;
  z->g.n = &x->Audience->g;
  x->Audience = z;
}

/* FUNC(zx_sa_AudienceRestriction_REV_Audience) */

void zx_sa_AudienceRestriction_REV_Audience(struct zx_sa_AudienceRestriction_s* x)
{
  struct zx_elem_s* nxt;
  struct zx_elem_s* y;
  if (!x) return;
  y = x->Audience;
  if (!y) return;
  x->Audience = 0;
  while (y) {
    nxt = (struct zx_elem_s*)y->g.n;
    y->g.n = &x->Audience->g;
    x->Audience = y;
    y = nxt;
  }
}

/* FUNC(zx_sa_AudienceRestriction_PUT_Audience) */

void zx_sa_AudienceRestriction_PUT_Audience(struct zx_sa_AudienceRestriction_s* x, int n, struct zx_elem_s* z)
{
  struct zx_elem_s* y;
  if (!x || !z) return;
  y = x->Audience;
  if (!y) return;
  switch (n) {
  case 0:
    z->g.n = y->g.n;
    x->Audience = z;
    return;
  default:
    for (; n > 1 && y->g.n; --n, y = (struct zx_elem_s*)y->g.n) ;
    if (!y->g.n) return;
    z->g.n = y->g.n->n;
    y->g.n = &z->g;
  }
}

/* FUNC(zx_sa_AudienceRestriction_ADD_Audience) */

void zx_sa_AudienceRestriction_ADD_Audience(struct zx_sa_AudienceRestriction_s* x, int n, struct zx_elem_s* z)
{
  struct zx_elem_s* y;
  if (!x || !z) return;
  switch (n) {
  case 0:
  add_to_start:
    z->g.n = &x->Audience->g;
    x->Audience = z;
    return;
  case -1:
    y = x->Audience;
    if (!y) goto add_to_start;
    for (; y->g.n; y = (struct zx_elem_s*)y->g.n) ;
    break;
  default:
    for (y = x->Audience; n > 1 && y; --n, y = (struct zx_elem_s*)y->g.n) ;
    if (!y) return;
  }
  z->g.n = y->g.n;
  y->g.n = &z->g;
}

/* FUNC(zx_sa_AudienceRestriction_DEL_Audience) */

void zx_sa_AudienceRestriction_DEL_Audience(struct zx_sa_AudienceRestriction_s* x, int n)
{
  struct zx_elem_s* y;
  if (!x) return;
  switch (n) {
  case 0:
    x->Audience = (struct zx_elem_s*)x->Audience->g.n;
    return;
  case -1:
    y = (struct zx_elem_s*)x->Audience;
    if (!y) return;
    for (; y->g.n; y = (struct zx_elem_s*)y->g.n) ;
    break;
  default:
    for (y = x->Audience; n > 1 && y->g.n; --n, y = (struct zx_elem_s*)y->g.n) ;
    if (!y->g.n) return;
  }
  y->g.n = y->g.n->n;
}

#endif








#ifdef ZX_ENA_GETPUT

/* FUNC(zx_sa_AuthnContext_NUM_AuthnContextClassRef) */

int zx_sa_AuthnContext_NUM_AuthnContextClassRef(struct zx_sa_AuthnContext_s* x)
{
  struct zx_elem_s* y;
  int n = 0;
  if (!x) return 0;
  for (y = x->AuthnContextClassRef; y; ++n, y = (struct zx_elem_s*)y->g.n) ;
  return n;
}

/* FUNC(zx_sa_AuthnContext_GET_AuthnContextClassRef) */

struct zx_elem_s* zx_sa_AuthnContext_GET_AuthnContextClassRef(struct zx_sa_AuthnContext_s* x, int n)
{
  struct zx_elem_s* y;
  if (!x) return 0;
  for (y = x->AuthnContextClassRef; n>=0 && y; --n, y = (struct zx_elem_s*)y->g.n) ;
  return y;
}

/* FUNC(zx_sa_AuthnContext_POP_AuthnContextClassRef) */

struct zx_elem_s* zx_sa_AuthnContext_POP_AuthnContextClassRef(struct zx_sa_AuthnContext_s* x)
{
  struct zx_elem_s* y;
  if (!x) return 0;
  y = x->AuthnContextClassRef;
  if (y)
    x->AuthnContextClassRef = (struct zx_elem_s*)y->g.n;
  return y;
}

/* FUNC(zx_sa_AuthnContext_PUSH_AuthnContextClassRef) */

void zx_sa_AuthnContext_PUSH_AuthnContextClassRef(struct zx_sa_AuthnContext_s* x, struct zx_elem_s* z)
{
  if (!x || !z) return;
  z->g.n = &x->AuthnContextClassRef->g;
  x->AuthnContextClassRef = z;
}

/* FUNC(zx_sa_AuthnContext_REV_AuthnContextClassRef) */

void zx_sa_AuthnContext_REV_AuthnContextClassRef(struct zx_sa_AuthnContext_s* x)
{
  struct zx_elem_s* nxt;
  struct zx_elem_s* y;
  if (!x) return;
  y = x->AuthnContextClassRef;
  if (!y) return;
  x->AuthnContextClassRef = 0;
  while (y) {
    nxt = (struct zx_elem_s*)y->g.n;
    y->g.n = &x->AuthnContextClassRef->g;
    x->AuthnContextClassRef = y;
    y = nxt;
  }
}

/* FUNC(zx_sa_AuthnContext_PUT_AuthnContextClassRef) */

void zx_sa_AuthnContext_PUT_AuthnContextClassRef(struct zx_sa_AuthnContext_s* x, int n, struct zx_elem_s* z)
{
  struct zx_elem_s* y;
  if (!x || !z) return;
  y = x->AuthnContextClassRef;
  if (!y) return;
  switch (n) {
  case 0:
    z->g.n = y->g.n;
    x->AuthnContextClassRef = z;
    return;
  default:
    for (; n > 1 && y->g.n; --n, y = (struct zx_elem_s*)y->g.n) ;
    if (!y->g.n) return;
    z->g.n = y->g.n->n;
    y->g.n = &z->g;
  }
}

/* FUNC(zx_sa_AuthnContext_ADD_AuthnContextClassRef) */

void zx_sa_AuthnContext_ADD_AuthnContextClassRef(struct zx_sa_AuthnContext_s* x, int n, struct zx_elem_s* z)
{
  struct zx_elem_s* y;
  if (!x || !z) return;
  switch (n) {
  case 0:
  add_to_start:
    z->g.n = &x->AuthnContextClassRef->g;
    x->AuthnContextClassRef = z;
    return;
  case -1:
    y = x->AuthnContextClassRef;
    if (!y) goto add_to_start;
    for (; y->g.n; y = (struct zx_elem_s*)y->g.n) ;
    break;
  default:
    for (y = x->AuthnContextClassRef; n > 1 && y; --n, y = (struct zx_elem_s*)y->g.n) ;
    if (!y) return;
  }
  z->g.n = y->g.n;
  y->g.n = &z->g;
}

/* FUNC(zx_sa_AuthnContext_DEL_AuthnContextClassRef) */

void zx_sa_AuthnContext_DEL_AuthnContextClassRef(struct zx_sa_AuthnContext_s* x, int n)
{
  struct zx_elem_s* y;
  if (!x) return;
  switch (n) {
  case 0:
    x->AuthnContextClassRef = (struct zx_elem_s*)x->AuthnContextClassRef->g.n;
    return;
  case -1:
    y = (struct zx_elem_s*)x->AuthnContextClassRef;
    if (!y) return;
    for (; y->g.n; y = (struct zx_elem_s*)y->g.n) ;
    break;
  default:
    for (y = x->AuthnContextClassRef; n > 1 && y->g.n; --n, y = (struct zx_elem_s*)y->g.n) ;
    if (!y->g.n) return;
  }
  y->g.n = y->g.n->n;
}

#endif



#ifdef ZX_ENA_GETPUT

/* FUNC(zx_sa_AuthnContext_NUM_AuthnContextDecl) */

int zx_sa_AuthnContext_NUM_AuthnContextDecl(struct zx_sa_AuthnContext_s* x)
{
  struct zx_elem_s* y;
  int n = 0;
  if (!x) return 0;
  for (y = x->AuthnContextDecl; y; ++n, y = (struct zx_elem_s*)y->g.n) ;
  return n;
}

/* FUNC(zx_sa_AuthnContext_GET_AuthnContextDecl) */

struct zx_elem_s* zx_sa_AuthnContext_GET_AuthnContextDecl(struct zx_sa_AuthnContext_s* x, int n)
{
  struct zx_elem_s* y;
  if (!x) return 0;
  for (y = x->AuthnContextDecl; n>=0 && y; --n, y = (struct zx_elem_s*)y->g.n) ;
  return y;
}

/* FUNC(zx_sa_AuthnContext_POP_AuthnContextDecl) */

struct zx_elem_s* zx_sa_AuthnContext_POP_AuthnContextDecl(struct zx_sa_AuthnContext_s* x)
{
  struct zx_elem_s* y;
  if (!x) return 0;
  y = x->AuthnContextDecl;
  if (y)
    x->AuthnContextDecl = (struct zx_elem_s*)y->g.n;
  return y;
}

/* FUNC(zx_sa_AuthnContext_PUSH_AuthnContextDecl) */

void zx_sa_AuthnContext_PUSH_AuthnContextDecl(struct zx_sa_AuthnContext_s* x, struct zx_elem_s* z)
{
  if (!x || !z) return;
  z->g.n = &x->AuthnContextDecl->g;
  x->AuthnContextDecl = z;
}

/* FUNC(zx_sa_AuthnContext_REV_AuthnContextDecl) */

void zx_sa_AuthnContext_REV_AuthnContextDecl(struct zx_sa_AuthnContext_s* x)
{
  struct zx_elem_s* nxt;
  struct zx_elem_s* y;
  if (!x) return;
  y = x->AuthnContextDecl;
  if (!y) return;
  x->AuthnContextDecl = 0;
  while (y) {
    nxt = (struct zx_elem_s*)y->g.n;
    y->g.n = &x->AuthnContextDecl->g;
    x->AuthnContextDecl = y;
    y = nxt;
  }
}

/* FUNC(zx_sa_AuthnContext_PUT_AuthnContextDecl) */

void zx_sa_AuthnContext_PUT_AuthnContextDecl(struct zx_sa_AuthnContext_s* x, int n, struct zx_elem_s* z)
{
  struct zx_elem_s* y;
  if (!x || !z) return;
  y = x->AuthnContextDecl;
  if (!y) return;
  switch (n) {
  case 0:
    z->g.n = y->g.n;
    x->AuthnContextDecl = z;
    return;
  default:
    for (; n > 1 && y->g.n; --n, y = (struct zx_elem_s*)y->g.n) ;
    if (!y->g.n) return;
    z->g.n = y->g.n->n;
    y->g.n = &z->g;
  }
}

/* FUNC(zx_sa_AuthnContext_ADD_AuthnContextDecl) */

void zx_sa_AuthnContext_ADD_AuthnContextDecl(struct zx_sa_AuthnContext_s* x, int n, struct zx_elem_s* z)
{
  struct zx_elem_s* y;
  if (!x || !z) return;
  switch (n) {
  case 0:
  add_to_start:
    z->g.n = &x->AuthnContextDecl->g;
    x->AuthnContextDecl = z;
    return;
  case -1:
    y = x->AuthnContextDecl;
    if (!y) goto add_to_start;
    for (; y->g.n; y = (struct zx_elem_s*)y->g.n) ;
    break;
  default:
    for (y = x->AuthnContextDecl; n > 1 && y; --n, y = (struct zx_elem_s*)y->g.n) ;
    if (!y) return;
  }
  z->g.n = y->g.n;
  y->g.n = &z->g;
}

/* FUNC(zx_sa_AuthnContext_DEL_AuthnContextDecl) */

void zx_sa_AuthnContext_DEL_AuthnContextDecl(struct zx_sa_AuthnContext_s* x, int n)
{
  struct zx_elem_s* y;
  if (!x) return;
  switch (n) {
  case 0:
    x->AuthnContextDecl = (struct zx_elem_s*)x->AuthnContextDecl->g.n;
    return;
  case -1:
    y = (struct zx_elem_s*)x->AuthnContextDecl;
    if (!y) return;
    for (; y->g.n; y = (struct zx_elem_s*)y->g.n) ;
    break;
  default:
    for (y = x->AuthnContextDecl; n > 1 && y->g.n; --n, y = (struct zx_elem_s*)y->g.n) ;
    if (!y->g.n) return;
  }
  y->g.n = y->g.n->n;
}

#endif



#ifdef ZX_ENA_GETPUT

/* FUNC(zx_sa_AuthnContext_NUM_AuthnContextDeclRef) */

int zx_sa_AuthnContext_NUM_AuthnContextDeclRef(struct zx_sa_AuthnContext_s* x)
{
  struct zx_elem_s* y;
  int n = 0;
  if (!x) return 0;
  for (y = x->AuthnContextDeclRef; y; ++n, y = (struct zx_elem_s*)y->g.n) ;
  return n;
}

/* FUNC(zx_sa_AuthnContext_GET_AuthnContextDeclRef) */

struct zx_elem_s* zx_sa_AuthnContext_GET_AuthnContextDeclRef(struct zx_sa_AuthnContext_s* x, int n)
{
  struct zx_elem_s* y;
  if (!x) return 0;
  for (y = x->AuthnContextDeclRef; n>=0 && y; --n, y = (struct zx_elem_s*)y->g.n) ;
  return y;
}

/* FUNC(zx_sa_AuthnContext_POP_AuthnContextDeclRef) */

struct zx_elem_s* zx_sa_AuthnContext_POP_AuthnContextDeclRef(struct zx_sa_AuthnContext_s* x)
{
  struct zx_elem_s* y;
  if (!x) return 0;
  y = x->AuthnContextDeclRef;
  if (y)
    x->AuthnContextDeclRef = (struct zx_elem_s*)y->g.n;
  return y;
}

/* FUNC(zx_sa_AuthnContext_PUSH_AuthnContextDeclRef) */

void zx_sa_AuthnContext_PUSH_AuthnContextDeclRef(struct zx_sa_AuthnContext_s* x, struct zx_elem_s* z)
{
  if (!x || !z) return;
  z->g.n = &x->AuthnContextDeclRef->g;
  x->AuthnContextDeclRef = z;
}

/* FUNC(zx_sa_AuthnContext_REV_AuthnContextDeclRef) */

void zx_sa_AuthnContext_REV_AuthnContextDeclRef(struct zx_sa_AuthnContext_s* x)
{
  struct zx_elem_s* nxt;
  struct zx_elem_s* y;
  if (!x) return;
  y = x->AuthnContextDeclRef;
  if (!y) return;
  x->AuthnContextDeclRef = 0;
  while (y) {
    nxt = (struct zx_elem_s*)y->g.n;
    y->g.n = &x->AuthnContextDeclRef->g;
    x->AuthnContextDeclRef = y;
    y = nxt;
  }
}

/* FUNC(zx_sa_AuthnContext_PUT_AuthnContextDeclRef) */

void zx_sa_AuthnContext_PUT_AuthnContextDeclRef(struct zx_sa_AuthnContext_s* x, int n, struct zx_elem_s* z)
{
  struct zx_elem_s* y;
  if (!x || !z) return;
  y = x->AuthnContextDeclRef;
  if (!y) return;
  switch (n) {
  case 0:
    z->g.n = y->g.n;
    x->AuthnContextDeclRef = z;
    return;
  default:
    for (; n > 1 && y->g.n; --n, y = (struct zx_elem_s*)y->g.n) ;
    if (!y->g.n) return;
    z->g.n = y->g.n->n;
    y->g.n = &z->g;
  }
}

/* FUNC(zx_sa_AuthnContext_ADD_AuthnContextDeclRef) */

void zx_sa_AuthnContext_ADD_AuthnContextDeclRef(struct zx_sa_AuthnContext_s* x, int n, struct zx_elem_s* z)
{
  struct zx_elem_s* y;
  if (!x || !z) return;
  switch (n) {
  case 0:
  add_to_start:
    z->g.n = &x->AuthnContextDeclRef->g;
    x->AuthnContextDeclRef = z;
    return;
  case -1:
    y = x->AuthnContextDeclRef;
    if (!y) goto add_to_start;
    for (; y->g.n; y = (struct zx_elem_s*)y->g.n) ;
    break;
  default:
    for (y = x->AuthnContextDeclRef; n > 1 && y; --n, y = (struct zx_elem_s*)y->g.n) ;
    if (!y) return;
  }
  z->g.n = y->g.n;
  y->g.n = &z->g;
}

/* FUNC(zx_sa_AuthnContext_DEL_AuthnContextDeclRef) */

void zx_sa_AuthnContext_DEL_AuthnContextDeclRef(struct zx_sa_AuthnContext_s* x, int n)
{
  struct zx_elem_s* y;
  if (!x) return;
  switch (n) {
  case 0:
    x->AuthnContextDeclRef = (struct zx_elem_s*)x->AuthnContextDeclRef->g.n;
    return;
  case -1:
    y = (struct zx_elem_s*)x->AuthnContextDeclRef;
    if (!y) return;
    for (; y->g.n; y = (struct zx_elem_s*)y->g.n) ;
    break;
  default:
    for (y = x->AuthnContextDeclRef; n > 1 && y->g.n; --n, y = (struct zx_elem_s*)y->g.n) ;
    if (!y->g.n) return;
  }
  y->g.n = y->g.n->n;
}

#endif



#ifdef ZX_ENA_GETPUT

/* FUNC(zx_sa_AuthnContext_NUM_AuthenticatingAuthority) */

int zx_sa_AuthnContext_NUM_AuthenticatingAuthority(struct zx_sa_AuthnContext_s* x)
{
  struct zx_elem_s* y;
  int n = 0;
  if (!x) return 0;
  for (y = x->AuthenticatingAuthority; y; ++n, y = (struct zx_elem_s*)y->g.n) ;
  return n;
}

/* FUNC(zx_sa_AuthnContext_GET_AuthenticatingAuthority) */

struct zx_elem_s* zx_sa_AuthnContext_GET_AuthenticatingAuthority(struct zx_sa_AuthnContext_s* x, int n)
{
  struct zx_elem_s* y;
  if (!x) return 0;
  for (y = x->AuthenticatingAuthority; n>=0 && y; --n, y = (struct zx_elem_s*)y->g.n) ;
  return y;
}

/* FUNC(zx_sa_AuthnContext_POP_AuthenticatingAuthority) */

struct zx_elem_s* zx_sa_AuthnContext_POP_AuthenticatingAuthority(struct zx_sa_AuthnContext_s* x)
{
  struct zx_elem_s* y;
  if (!x) return 0;
  y = x->AuthenticatingAuthority;
  if (y)
    x->AuthenticatingAuthority = (struct zx_elem_s*)y->g.n;
  return y;
}

/* FUNC(zx_sa_AuthnContext_PUSH_AuthenticatingAuthority) */

void zx_sa_AuthnContext_PUSH_AuthenticatingAuthority(struct zx_sa_AuthnContext_s* x, struct zx_elem_s* z)
{
  if (!x || !z) return;
  z->g.n = &x->AuthenticatingAuthority->g;
  x->AuthenticatingAuthority = z;
}

/* FUNC(zx_sa_AuthnContext_REV_AuthenticatingAuthority) */

void zx_sa_AuthnContext_REV_AuthenticatingAuthority(struct zx_sa_AuthnContext_s* x)
{
  struct zx_elem_s* nxt;
  struct zx_elem_s* y;
  if (!x) return;
  y = x->AuthenticatingAuthority;
  if (!y) return;
  x->AuthenticatingAuthority = 0;
  while (y) {
    nxt = (struct zx_elem_s*)y->g.n;
    y->g.n = &x->AuthenticatingAuthority->g;
    x->AuthenticatingAuthority = y;
    y = nxt;
  }
}

/* FUNC(zx_sa_AuthnContext_PUT_AuthenticatingAuthority) */

void zx_sa_AuthnContext_PUT_AuthenticatingAuthority(struct zx_sa_AuthnContext_s* x, int n, struct zx_elem_s* z)
{
  struct zx_elem_s* y;
  if (!x || !z) return;
  y = x->AuthenticatingAuthority;
  if (!y) return;
  switch (n) {
  case 0:
    z->g.n = y->g.n;
    x->AuthenticatingAuthority = z;
    return;
  default:
    for (; n > 1 && y->g.n; --n, y = (struct zx_elem_s*)y->g.n) ;
    if (!y->g.n) return;
    z->g.n = y->g.n->n;
    y->g.n = &z->g;
  }
}

/* FUNC(zx_sa_AuthnContext_ADD_AuthenticatingAuthority) */

void zx_sa_AuthnContext_ADD_AuthenticatingAuthority(struct zx_sa_AuthnContext_s* x, int n, struct zx_elem_s* z)
{
  struct zx_elem_s* y;
  if (!x || !z) return;
  switch (n) {
  case 0:
  add_to_start:
    z->g.n = &x->AuthenticatingAuthority->g;
    x->AuthenticatingAuthority = z;
    return;
  case -1:
    y = x->AuthenticatingAuthority;
    if (!y) goto add_to_start;
    for (; y->g.n; y = (struct zx_elem_s*)y->g.n) ;
    break;
  default:
    for (y = x->AuthenticatingAuthority; n > 1 && y; --n, y = (struct zx_elem_s*)y->g.n) ;
    if (!y) return;
  }
  z->g.n = y->g.n;
  y->g.n = &z->g;
}

/* FUNC(zx_sa_AuthnContext_DEL_AuthenticatingAuthority) */

void zx_sa_AuthnContext_DEL_AuthenticatingAuthority(struct zx_sa_AuthnContext_s* x, int n)
{
  struct zx_elem_s* y;
  if (!x) return;
  switch (n) {
  case 0:
    x->AuthenticatingAuthority = (struct zx_elem_s*)x->AuthenticatingAuthority->g.n;
    return;
  case -1:
    y = (struct zx_elem_s*)x->AuthenticatingAuthority;
    if (!y) return;
    for (; y->g.n; y = (struct zx_elem_s*)y->g.n) ;
    break;
  default:
    for (y = x->AuthenticatingAuthority; n > 1 && y->g.n; --n, y = (struct zx_elem_s*)y->g.n) ;
    if (!y->g.n) return;
  }
  y->g.n = y->g.n->n;
}

#endif








#ifdef ZX_ENA_GETPUT

/* FUNC(zx_sa_AuthnStatement_NUM_SubjectLocality) */

int zx_sa_AuthnStatement_NUM_SubjectLocality(struct zx_sa_AuthnStatement_s* x)
{
  struct zx_sa_SubjectLocality_s* y;
  int n = 0;
  if (!x) return 0;
  for (y = x->SubjectLocality; y; ++n, y = (struct zx_sa_SubjectLocality_s*)y->gg.g.n) ;
  return n;
}

/* FUNC(zx_sa_AuthnStatement_GET_SubjectLocality) */

struct zx_sa_SubjectLocality_s* zx_sa_AuthnStatement_GET_SubjectLocality(struct zx_sa_AuthnStatement_s* x, int n)
{
  struct zx_sa_SubjectLocality_s* y;
  if (!x) return 0;
  for (y = x->SubjectLocality; n>=0 && y; --n, y = (struct zx_sa_SubjectLocality_s*)y->gg.g.n) ;
  return y;
}

/* FUNC(zx_sa_AuthnStatement_POP_SubjectLocality) */

struct zx_sa_SubjectLocality_s* zx_sa_AuthnStatement_POP_SubjectLocality(struct zx_sa_AuthnStatement_s* x)
{
  struct zx_sa_SubjectLocality_s* y;
  if (!x) return 0;
  y = x->SubjectLocality;
  if (y)
    x->SubjectLocality = (struct zx_sa_SubjectLocality_s*)y->gg.g.n;
  return y;
}

/* FUNC(zx_sa_AuthnStatement_PUSH_SubjectLocality) */

void zx_sa_AuthnStatement_PUSH_SubjectLocality(struct zx_sa_AuthnStatement_s* x, struct zx_sa_SubjectLocality_s* z)
{
  if (!x || !z) return;
  z->gg.g.n = &x->SubjectLocality->gg.g;
  x->SubjectLocality = z;
}

/* FUNC(zx_sa_AuthnStatement_REV_SubjectLocality) */

void zx_sa_AuthnStatement_REV_SubjectLocality(struct zx_sa_AuthnStatement_s* x)
{
  struct zx_sa_SubjectLocality_s* nxt;
  struct zx_sa_SubjectLocality_s* y;
  if (!x) return;
  y = x->SubjectLocality;
  if (!y) return;
  x->SubjectLocality = 0;
  while (y) {
    nxt = (struct zx_sa_SubjectLocality_s*)y->gg.g.n;
    y->gg.g.n = &x->SubjectLocality->gg.g;
    x->SubjectLocality = y;
    y = nxt;
  }
}

/* FUNC(zx_sa_AuthnStatement_PUT_SubjectLocality) */

void zx_sa_AuthnStatement_PUT_SubjectLocality(struct zx_sa_AuthnStatement_s* x, int n, struct zx_sa_SubjectLocality_s* z)
{
  struct zx_sa_SubjectLocality_s* y;
  if (!x || !z) return;
  y = x->SubjectLocality;
  if (!y) return;
  switch (n) {
  case 0:
    z->gg.g.n = y->gg.g.n;
    x->SubjectLocality = z;
    return;
  default:
    for (; n > 1 && y->gg.g.n; --n, y = (struct zx_sa_SubjectLocality_s*)y->gg.g.n) ;
    if (!y->gg.g.n) return;
    z->gg.g.n = y->gg.g.n->n;
    y->gg.g.n = &z->gg.g;
  }
}

/* FUNC(zx_sa_AuthnStatement_ADD_SubjectLocality) */

void zx_sa_AuthnStatement_ADD_SubjectLocality(struct zx_sa_AuthnStatement_s* x, int n, struct zx_sa_SubjectLocality_s* z)
{
  struct zx_sa_SubjectLocality_s* y;
  if (!x || !z) return;
  switch (n) {
  case 0:
  add_to_start:
    z->gg.g.n = &x->SubjectLocality->gg.g;
    x->SubjectLocality = z;
    return;
  case -1:
    y = x->SubjectLocality;
    if (!y) goto add_to_start;
    for (; y->gg.g.n; y = (struct zx_sa_SubjectLocality_s*)y->gg.g.n) ;
    break;
  default:
    for (y = x->SubjectLocality; n > 1 && y; --n, y = (struct zx_sa_SubjectLocality_s*)y->gg.g.n) ;
    if (!y) return;
  }
  z->gg.g.n = y->gg.g.n;
  y->gg.g.n = &z->gg.g;
}

/* FUNC(zx_sa_AuthnStatement_DEL_SubjectLocality) */

void zx_sa_AuthnStatement_DEL_SubjectLocality(struct zx_sa_AuthnStatement_s* x, int n)
{
  struct zx_sa_SubjectLocality_s* y;
  if (!x) return;
  switch (n) {
  case 0:
    x->SubjectLocality = (struct zx_sa_SubjectLocality_s*)x->SubjectLocality->gg.g.n;
    return;
  case -1:
    y = (struct zx_sa_SubjectLocality_s*)x->SubjectLocality;
    if (!y) return;
    for (; y->gg.g.n; y = (struct zx_sa_SubjectLocality_s*)y->gg.g.n) ;
    break;
  default:
    for (y = x->SubjectLocality; n > 1 && y->gg.g.n; --n, y = (struct zx_sa_SubjectLocality_s*)y->gg.g.n) ;
    if (!y->gg.g.n) return;
  }
  y->gg.g.n = y->gg.g.n->n;
}

#endif



#ifdef ZX_ENA_GETPUT

/* FUNC(zx_sa_AuthnStatement_NUM_AuthnContext) */

int zx_sa_AuthnStatement_NUM_AuthnContext(struct zx_sa_AuthnStatement_s* x)
{
  struct zx_sa_AuthnContext_s* y;
  int n = 0;
  if (!x) return 0;
  for (y = x->AuthnContext; y; ++n, y = (struct zx_sa_AuthnContext_s*)y->gg.g.n) ;
  return n;
}

/* FUNC(zx_sa_AuthnStatement_GET_AuthnContext) */

struct zx_sa_AuthnContext_s* zx_sa_AuthnStatement_GET_AuthnContext(struct zx_sa_AuthnStatement_s* x, int n)
{
  struct zx_sa_AuthnContext_s* y;
  if (!x) return 0;
  for (y = x->AuthnContext; n>=0 && y; --n, y = (struct zx_sa_AuthnContext_s*)y->gg.g.n) ;
  return y;
}

/* FUNC(zx_sa_AuthnStatement_POP_AuthnContext) */

struct zx_sa_AuthnContext_s* zx_sa_AuthnStatement_POP_AuthnContext(struct zx_sa_AuthnStatement_s* x)
{
  struct zx_sa_AuthnContext_s* y;
  if (!x) return 0;
  y = x->AuthnContext;
  if (y)
    x->AuthnContext = (struct zx_sa_AuthnContext_s*)y->gg.g.n;
  return y;
}

/* FUNC(zx_sa_AuthnStatement_PUSH_AuthnContext) */

void zx_sa_AuthnStatement_PUSH_AuthnContext(struct zx_sa_AuthnStatement_s* x, struct zx_sa_AuthnContext_s* z)
{
  if (!x || !z) return;
  z->gg.g.n = &x->AuthnContext->gg.g;
  x->AuthnContext = z;
}

/* FUNC(zx_sa_AuthnStatement_REV_AuthnContext) */

void zx_sa_AuthnStatement_REV_AuthnContext(struct zx_sa_AuthnStatement_s* x)
{
  struct zx_sa_AuthnContext_s* nxt;
  struct zx_sa_AuthnContext_s* y;
  if (!x) return;
  y = x->AuthnContext;
  if (!y) return;
  x->AuthnContext = 0;
  while (y) {
    nxt = (struct zx_sa_AuthnContext_s*)y->gg.g.n;
    y->gg.g.n = &x->AuthnContext->gg.g;
    x->AuthnContext = y;
    y = nxt;
  }
}

/* FUNC(zx_sa_AuthnStatement_PUT_AuthnContext) */

void zx_sa_AuthnStatement_PUT_AuthnContext(struct zx_sa_AuthnStatement_s* x, int n, struct zx_sa_AuthnContext_s* z)
{
  struct zx_sa_AuthnContext_s* y;
  if (!x || !z) return;
  y = x->AuthnContext;
  if (!y) return;
  switch (n) {
  case 0:
    z->gg.g.n = y->gg.g.n;
    x->AuthnContext = z;
    return;
  default:
    for (; n > 1 && y->gg.g.n; --n, y = (struct zx_sa_AuthnContext_s*)y->gg.g.n) ;
    if (!y->gg.g.n) return;
    z->gg.g.n = y->gg.g.n->n;
    y->gg.g.n = &z->gg.g;
  }
}

/* FUNC(zx_sa_AuthnStatement_ADD_AuthnContext) */

void zx_sa_AuthnStatement_ADD_AuthnContext(struct zx_sa_AuthnStatement_s* x, int n, struct zx_sa_AuthnContext_s* z)
{
  struct zx_sa_AuthnContext_s* y;
  if (!x || !z) return;
  switch (n) {
  case 0:
  add_to_start:
    z->gg.g.n = &x->AuthnContext->gg.g;
    x->AuthnContext = z;
    return;
  case -1:
    y = x->AuthnContext;
    if (!y) goto add_to_start;
    for (; y->gg.g.n; y = (struct zx_sa_AuthnContext_s*)y->gg.g.n) ;
    break;
  default:
    for (y = x->AuthnContext; n > 1 && y; --n, y = (struct zx_sa_AuthnContext_s*)y->gg.g.n) ;
    if (!y) return;
  }
  z->gg.g.n = y->gg.g.n;
  y->gg.g.n = &z->gg.g;
}

/* FUNC(zx_sa_AuthnStatement_DEL_AuthnContext) */

void zx_sa_AuthnStatement_DEL_AuthnContext(struct zx_sa_AuthnStatement_s* x, int n)
{
  struct zx_sa_AuthnContext_s* y;
  if (!x) return;
  switch (n) {
  case 0:
    x->AuthnContext = (struct zx_sa_AuthnContext_s*)x->AuthnContext->gg.g.n;
    return;
  case -1:
    y = (struct zx_sa_AuthnContext_s*)x->AuthnContext;
    if (!y) return;
    for (; y->gg.g.n; y = (struct zx_sa_AuthnContext_s*)y->gg.g.n) ;
    break;
  default:
    for (y = x->AuthnContext; n > 1 && y->gg.g.n; --n, y = (struct zx_sa_AuthnContext_s*)y->gg.g.n) ;
    if (!y->gg.g.n) return;
  }
  y->gg.g.n = y->gg.g.n->n;
}

#endif

/* FUNC(zx_sa_AuthnStatement_GET_AuthnInstant) */
struct zx_str* zx_sa_AuthnStatement_GET_AuthnInstant(struct zx_sa_AuthnStatement_s* x) { return x->AuthnInstant; }
/* FUNC(zx_sa_AuthnStatement_PUT_AuthnInstant) */
void zx_sa_AuthnStatement_PUT_AuthnInstant(struct zx_sa_AuthnStatement_s* x, struct zx_str* y) { x->AuthnInstant = y; }
/* FUNC(zx_sa_AuthnStatement_GET_SessionIndex) */
struct zx_str* zx_sa_AuthnStatement_GET_SessionIndex(struct zx_sa_AuthnStatement_s* x) { return x->SessionIndex; }
/* FUNC(zx_sa_AuthnStatement_PUT_SessionIndex) */
void zx_sa_AuthnStatement_PUT_SessionIndex(struct zx_sa_AuthnStatement_s* x, struct zx_str* y) { x->SessionIndex = y; }
/* FUNC(zx_sa_AuthnStatement_GET_SessionNotOnOrAfter) */
struct zx_str* zx_sa_AuthnStatement_GET_SessionNotOnOrAfter(struct zx_sa_AuthnStatement_s* x) { return x->SessionNotOnOrAfter; }
/* FUNC(zx_sa_AuthnStatement_PUT_SessionNotOnOrAfter) */
void zx_sa_AuthnStatement_PUT_SessionNotOnOrAfter(struct zx_sa_AuthnStatement_s* x, struct zx_str* y) { x->SessionNotOnOrAfter = y; }







#ifdef ZX_ENA_GETPUT

/* FUNC(zx_sa_AuthzDecisionStatement_NUM_Action) */

int zx_sa_AuthzDecisionStatement_NUM_Action(struct zx_sa_AuthzDecisionStatement_s* x)
{
  struct zx_sa_Action_s* y;
  int n = 0;
  if (!x) return 0;
  for (y = x->Action; y; ++n, y = (struct zx_sa_Action_s*)y->gg.g.n) ;
  return n;
}

/* FUNC(zx_sa_AuthzDecisionStatement_GET_Action) */

struct zx_sa_Action_s* zx_sa_AuthzDecisionStatement_GET_Action(struct zx_sa_AuthzDecisionStatement_s* x, int n)
{
  struct zx_sa_Action_s* y;
  if (!x) return 0;
  for (y = x->Action; n>=0 && y; --n, y = (struct zx_sa_Action_s*)y->gg.g.n) ;
  return y;
}

/* FUNC(zx_sa_AuthzDecisionStatement_POP_Action) */

struct zx_sa_Action_s* zx_sa_AuthzDecisionStatement_POP_Action(struct zx_sa_AuthzDecisionStatement_s* x)
{
  struct zx_sa_Action_s* y;
  if (!x) return 0;
  y = x->Action;
  if (y)
    x->Action = (struct zx_sa_Action_s*)y->gg.g.n;
  return y;
}

/* FUNC(zx_sa_AuthzDecisionStatement_PUSH_Action) */

void zx_sa_AuthzDecisionStatement_PUSH_Action(struct zx_sa_AuthzDecisionStatement_s* x, struct zx_sa_Action_s* z)
{
  if (!x || !z) return;
  z->gg.g.n = &x->Action->gg.g;
  x->Action = z;
}

/* FUNC(zx_sa_AuthzDecisionStatement_REV_Action) */

void zx_sa_AuthzDecisionStatement_REV_Action(struct zx_sa_AuthzDecisionStatement_s* x)
{
  struct zx_sa_Action_s* nxt;
  struct zx_sa_Action_s* y;
  if (!x) return;
  y = x->Action;
  if (!y) return;
  x->Action = 0;
  while (y) {
    nxt = (struct zx_sa_Action_s*)y->gg.g.n;
    y->gg.g.n = &x->Action->gg.g;
    x->Action = y;
    y = nxt;
  }
}

/* FUNC(zx_sa_AuthzDecisionStatement_PUT_Action) */

void zx_sa_AuthzDecisionStatement_PUT_Action(struct zx_sa_AuthzDecisionStatement_s* x, int n, struct zx_sa_Action_s* z)
{
  struct zx_sa_Action_s* y;
  if (!x || !z) return;
  y = x->Action;
  if (!y) return;
  switch (n) {
  case 0:
    z->gg.g.n = y->gg.g.n;
    x->Action = z;
    return;
  default:
    for (; n > 1 && y->gg.g.n; --n, y = (struct zx_sa_Action_s*)y->gg.g.n) ;
    if (!y->gg.g.n) return;
    z->gg.g.n = y->gg.g.n->n;
    y->gg.g.n = &z->gg.g;
  }
}

/* FUNC(zx_sa_AuthzDecisionStatement_ADD_Action) */

void zx_sa_AuthzDecisionStatement_ADD_Action(struct zx_sa_AuthzDecisionStatement_s* x, int n, struct zx_sa_Action_s* z)
{
  struct zx_sa_Action_s* y;
  if (!x || !z) return;
  switch (n) {
  case 0:
  add_to_start:
    z->gg.g.n = &x->Action->gg.g;
    x->Action = z;
    return;
  case -1:
    y = x->Action;
    if (!y) goto add_to_start;
    for (; y->gg.g.n; y = (struct zx_sa_Action_s*)y->gg.g.n) ;
    break;
  default:
    for (y = x->Action; n > 1 && y; --n, y = (struct zx_sa_Action_s*)y->gg.g.n) ;
    if (!y) return;
  }
  z->gg.g.n = y->gg.g.n;
  y->gg.g.n = &z->gg.g;
}

/* FUNC(zx_sa_AuthzDecisionStatement_DEL_Action) */

void zx_sa_AuthzDecisionStatement_DEL_Action(struct zx_sa_AuthzDecisionStatement_s* x, int n)
{
  struct zx_sa_Action_s* y;
  if (!x) return;
  switch (n) {
  case 0:
    x->Action = (struct zx_sa_Action_s*)x->Action->gg.g.n;
    return;
  case -1:
    y = (struct zx_sa_Action_s*)x->Action;
    if (!y) return;
    for (; y->gg.g.n; y = (struct zx_sa_Action_s*)y->gg.g.n) ;
    break;
  default:
    for (y = x->Action; n > 1 && y->gg.g.n; --n, y = (struct zx_sa_Action_s*)y->gg.g.n) ;
    if (!y->gg.g.n) return;
  }
  y->gg.g.n = y->gg.g.n->n;
}

#endif



#ifdef ZX_ENA_GETPUT

/* FUNC(zx_sa_AuthzDecisionStatement_NUM_Evidence) */

int zx_sa_AuthzDecisionStatement_NUM_Evidence(struct zx_sa_AuthzDecisionStatement_s* x)
{
  struct zx_sa_Evidence_s* y;
  int n = 0;
  if (!x) return 0;
  for (y = x->Evidence; y; ++n, y = (struct zx_sa_Evidence_s*)y->gg.g.n) ;
  return n;
}

/* FUNC(zx_sa_AuthzDecisionStatement_GET_Evidence) */

struct zx_sa_Evidence_s* zx_sa_AuthzDecisionStatement_GET_Evidence(struct zx_sa_AuthzDecisionStatement_s* x, int n)
{
  struct zx_sa_Evidence_s* y;
  if (!x) return 0;
  for (y = x->Evidence; n>=0 && y; --n, y = (struct zx_sa_Evidence_s*)y->gg.g.n) ;
  return y;
}

/* FUNC(zx_sa_AuthzDecisionStatement_POP_Evidence) */

struct zx_sa_Evidence_s* zx_sa_AuthzDecisionStatement_POP_Evidence(struct zx_sa_AuthzDecisionStatement_s* x)
{
  struct zx_sa_Evidence_s* y;
  if (!x) return 0;
  y = x->Evidence;
  if (y)
    x->Evidence = (struct zx_sa_Evidence_s*)y->gg.g.n;
  return y;
}

/* FUNC(zx_sa_AuthzDecisionStatement_PUSH_Evidence) */

void zx_sa_AuthzDecisionStatement_PUSH_Evidence(struct zx_sa_AuthzDecisionStatement_s* x, struct zx_sa_Evidence_s* z)
{
  if (!x || !z) return;
  z->gg.g.n = &x->Evidence->gg.g;
  x->Evidence = z;
}

/* FUNC(zx_sa_AuthzDecisionStatement_REV_Evidence) */

void zx_sa_AuthzDecisionStatement_REV_Evidence(struct zx_sa_AuthzDecisionStatement_s* x)
{
  struct zx_sa_Evidence_s* nxt;
  struct zx_sa_Evidence_s* y;
  if (!x) return;
  y = x->Evidence;
  if (!y) return;
  x->Evidence = 0;
  while (y) {
    nxt = (struct zx_sa_Evidence_s*)y->gg.g.n;
    y->gg.g.n = &x->Evidence->gg.g;
    x->Evidence = y;
    y = nxt;
  }
}

/* FUNC(zx_sa_AuthzDecisionStatement_PUT_Evidence) */

void zx_sa_AuthzDecisionStatement_PUT_Evidence(struct zx_sa_AuthzDecisionStatement_s* x, int n, struct zx_sa_Evidence_s* z)
{
  struct zx_sa_Evidence_s* y;
  if (!x || !z) return;
  y = x->Evidence;
  if (!y) return;
  switch (n) {
  case 0:
    z->gg.g.n = y->gg.g.n;
    x->Evidence = z;
    return;
  default:
    for (; n > 1 && y->gg.g.n; --n, y = (struct zx_sa_Evidence_s*)y->gg.g.n) ;
    if (!y->gg.g.n) return;
    z->gg.g.n = y->gg.g.n->n;
    y->gg.g.n = &z->gg.g;
  }
}

/* FUNC(zx_sa_AuthzDecisionStatement_ADD_Evidence) */

void zx_sa_AuthzDecisionStatement_ADD_Evidence(struct zx_sa_AuthzDecisionStatement_s* x, int n, struct zx_sa_Evidence_s* z)
{
  struct zx_sa_Evidence_s* y;
  if (!x || !z) return;
  switch (n) {
  case 0:
  add_to_start:
    z->gg.g.n = &x->Evidence->gg.g;
    x->Evidence = z;
    return;
  case -1:
    y = x->Evidence;
    if (!y) goto add_to_start;
    for (; y->gg.g.n; y = (struct zx_sa_Evidence_s*)y->gg.g.n) ;
    break;
  default:
    for (y = x->Evidence; n > 1 && y; --n, y = (struct zx_sa_Evidence_s*)y->gg.g.n) ;
    if (!y) return;
  }
  z->gg.g.n = y->gg.g.n;
  y->gg.g.n = &z->gg.g;
}

/* FUNC(zx_sa_AuthzDecisionStatement_DEL_Evidence) */

void zx_sa_AuthzDecisionStatement_DEL_Evidence(struct zx_sa_AuthzDecisionStatement_s* x, int n)
{
  struct zx_sa_Evidence_s* y;
  if (!x) return;
  switch (n) {
  case 0:
    x->Evidence = (struct zx_sa_Evidence_s*)x->Evidence->gg.g.n;
    return;
  case -1:
    y = (struct zx_sa_Evidence_s*)x->Evidence;
    if (!y) return;
    for (; y->gg.g.n; y = (struct zx_sa_Evidence_s*)y->gg.g.n) ;
    break;
  default:
    for (y = x->Evidence; n > 1 && y->gg.g.n; --n, y = (struct zx_sa_Evidence_s*)y->gg.g.n) ;
    if (!y->gg.g.n) return;
  }
  y->gg.g.n = y->gg.g.n->n;
}

#endif

/* FUNC(zx_sa_AuthzDecisionStatement_GET_Decision) */
struct zx_str* zx_sa_AuthzDecisionStatement_GET_Decision(struct zx_sa_AuthzDecisionStatement_s* x) { return x->Decision; }
/* FUNC(zx_sa_AuthzDecisionStatement_PUT_Decision) */
void zx_sa_AuthzDecisionStatement_PUT_Decision(struct zx_sa_AuthzDecisionStatement_s* x, struct zx_str* y) { x->Decision = y; }
/* FUNC(zx_sa_AuthzDecisionStatement_GET_Resource) */
struct zx_str* zx_sa_AuthzDecisionStatement_GET_Resource(struct zx_sa_AuthzDecisionStatement_s* x) { return x->Resource; }
/* FUNC(zx_sa_AuthzDecisionStatement_PUT_Resource) */
void zx_sa_AuthzDecisionStatement_PUT_Resource(struct zx_sa_AuthzDecisionStatement_s* x, struct zx_str* y) { x->Resource = y; }





/* FUNC(zx_sa_BaseID_GET_NameQualifier) */
struct zx_str* zx_sa_BaseID_GET_NameQualifier(struct zx_sa_BaseID_s* x) { return x->NameQualifier; }
/* FUNC(zx_sa_BaseID_PUT_NameQualifier) */
void zx_sa_BaseID_PUT_NameQualifier(struct zx_sa_BaseID_s* x, struct zx_str* y) { x->NameQualifier = y; }
/* FUNC(zx_sa_BaseID_GET_SPNameQualifier) */
struct zx_str* zx_sa_BaseID_GET_SPNameQualifier(struct zx_sa_BaseID_s* x) { return x->SPNameQualifier; }
/* FUNC(zx_sa_BaseID_PUT_SPNameQualifier) */
void zx_sa_BaseID_PUT_SPNameQualifier(struct zx_sa_BaseID_s* x, struct zx_str* y) { x->SPNameQualifier = y; }







#ifdef ZX_ENA_GETPUT

/* FUNC(zx_sa_Conditions_NUM_Condition) */

int zx_sa_Conditions_NUM_Condition(struct zx_sa_Conditions_s* x)
{
  struct zx_elem_s* y;
  int n = 0;
  if (!x) return 0;
  for (y = x->Condition; y; ++n, y = (struct zx_elem_s*)y->g.n) ;
  return n;
}

/* FUNC(zx_sa_Conditions_GET_Condition) */

struct zx_elem_s* zx_sa_Conditions_GET_Condition(struct zx_sa_Conditions_s* x, int n)
{
  struct zx_elem_s* y;
  if (!x) return 0;
  for (y = x->Condition; n>=0 && y; --n, y = (struct zx_elem_s*)y->g.n) ;
  return y;
}

/* FUNC(zx_sa_Conditions_POP_Condition) */

struct zx_elem_s* zx_sa_Conditions_POP_Condition(struct zx_sa_Conditions_s* x)
{
  struct zx_elem_s* y;
  if (!x) return 0;
  y = x->Condition;
  if (y)
    x->Condition = (struct zx_elem_s*)y->g.n;
  return y;
}

/* FUNC(zx_sa_Conditions_PUSH_Condition) */

void zx_sa_Conditions_PUSH_Condition(struct zx_sa_Conditions_s* x, struct zx_elem_s* z)
{
  if (!x || !z) return;
  z->g.n = &x->Condition->g;
  x->Condition = z;
}

/* FUNC(zx_sa_Conditions_REV_Condition) */

void zx_sa_Conditions_REV_Condition(struct zx_sa_Conditions_s* x)
{
  struct zx_elem_s* nxt;
  struct zx_elem_s* y;
  if (!x) return;
  y = x->Condition;
  if (!y) return;
  x->Condition = 0;
  while (y) {
    nxt = (struct zx_elem_s*)y->g.n;
    y->g.n = &x->Condition->g;
    x->Condition = y;
    y = nxt;
  }
}

/* FUNC(zx_sa_Conditions_PUT_Condition) */

void zx_sa_Conditions_PUT_Condition(struct zx_sa_Conditions_s* x, int n, struct zx_elem_s* z)
{
  struct zx_elem_s* y;
  if (!x || !z) return;
  y = x->Condition;
  if (!y) return;
  switch (n) {
  case 0:
    z->g.n = y->g.n;
    x->Condition = z;
    return;
  default:
    for (; n > 1 && y->g.n; --n, y = (struct zx_elem_s*)y->g.n) ;
    if (!y->g.n) return;
    z->g.n = y->g.n->n;
    y->g.n = &z->g;
  }
}

/* FUNC(zx_sa_Conditions_ADD_Condition) */

void zx_sa_Conditions_ADD_Condition(struct zx_sa_Conditions_s* x, int n, struct zx_elem_s* z)
{
  struct zx_elem_s* y;
  if (!x || !z) return;
  switch (n) {
  case 0:
  add_to_start:
    z->g.n = &x->Condition->g;
    x->Condition = z;
    return;
  case -1:
    y = x->Condition;
    if (!y) goto add_to_start;
    for (; y->g.n; y = (struct zx_elem_s*)y->g.n) ;
    break;
  default:
    for (y = x->Condition; n > 1 && y; --n, y = (struct zx_elem_s*)y->g.n) ;
    if (!y) return;
  }
  z->g.n = y->g.n;
  y->g.n = &z->g;
}

/* FUNC(zx_sa_Conditions_DEL_Condition) */

void zx_sa_Conditions_DEL_Condition(struct zx_sa_Conditions_s* x, int n)
{
  struct zx_elem_s* y;
  if (!x) return;
  switch (n) {
  case 0:
    x->Condition = (struct zx_elem_s*)x->Condition->g.n;
    return;
  case -1:
    y = (struct zx_elem_s*)x->Condition;
    if (!y) return;
    for (; y->g.n; y = (struct zx_elem_s*)y->g.n) ;
    break;
  default:
    for (y = x->Condition; n > 1 && y->g.n; --n, y = (struct zx_elem_s*)y->g.n) ;
    if (!y->g.n) return;
  }
  y->g.n = y->g.n->n;
}

#endif



#ifdef ZX_ENA_GETPUT

/* FUNC(zx_sa_Conditions_NUM_AudienceRestriction) */

int zx_sa_Conditions_NUM_AudienceRestriction(struct zx_sa_Conditions_s* x)
{
  struct zx_sa_AudienceRestriction_s* y;
  int n = 0;
  if (!x) return 0;
  for (y = x->AudienceRestriction; y; ++n, y = (struct zx_sa_AudienceRestriction_s*)y->gg.g.n) ;
  return n;
}

/* FUNC(zx_sa_Conditions_GET_AudienceRestriction) */

struct zx_sa_AudienceRestriction_s* zx_sa_Conditions_GET_AudienceRestriction(struct zx_sa_Conditions_s* x, int n)
{
  struct zx_sa_AudienceRestriction_s* y;
  if (!x) return 0;
  for (y = x->AudienceRestriction; n>=0 && y; --n, y = (struct zx_sa_AudienceRestriction_s*)y->gg.g.n) ;
  return y;
}

/* FUNC(zx_sa_Conditions_POP_AudienceRestriction) */

struct zx_sa_AudienceRestriction_s* zx_sa_Conditions_POP_AudienceRestriction(struct zx_sa_Conditions_s* x)
{
  struct zx_sa_AudienceRestriction_s* y;
  if (!x) return 0;
  y = x->AudienceRestriction;
  if (y)
    x->AudienceRestriction = (struct zx_sa_AudienceRestriction_s*)y->gg.g.n;
  return y;
}

/* FUNC(zx_sa_Conditions_PUSH_AudienceRestriction) */

void zx_sa_Conditions_PUSH_AudienceRestriction(struct zx_sa_Conditions_s* x, struct zx_sa_AudienceRestriction_s* z)
{
  if (!x || !z) return;
  z->gg.g.n = &x->AudienceRestriction->gg.g;
  x->AudienceRestriction = z;
}

/* FUNC(zx_sa_Conditions_REV_AudienceRestriction) */

void zx_sa_Conditions_REV_AudienceRestriction(struct zx_sa_Conditions_s* x)
{
  struct zx_sa_AudienceRestriction_s* nxt;
  struct zx_sa_AudienceRestriction_s* y;
  if (!x) return;
  y = x->AudienceRestriction;
  if (!y) return;
  x->AudienceRestriction = 0;
  while (y) {
    nxt = (struct zx_sa_AudienceRestriction_s*)y->gg.g.n;
    y->gg.g.n = &x->AudienceRestriction->gg.g;
    x->AudienceRestriction = y;
    y = nxt;
  }
}

/* FUNC(zx_sa_Conditions_PUT_AudienceRestriction) */

void zx_sa_Conditions_PUT_AudienceRestriction(struct zx_sa_Conditions_s* x, int n, struct zx_sa_AudienceRestriction_s* z)
{
  struct zx_sa_AudienceRestriction_s* y;
  if (!x || !z) return;
  y = x->AudienceRestriction;
  if (!y) return;
  switch (n) {
  case 0:
    z->gg.g.n = y->gg.g.n;
    x->AudienceRestriction = z;
    return;
  default:
    for (; n > 1 && y->gg.g.n; --n, y = (struct zx_sa_AudienceRestriction_s*)y->gg.g.n) ;
    if (!y->gg.g.n) return;
    z->gg.g.n = y->gg.g.n->n;
    y->gg.g.n = &z->gg.g;
  }
}

/* FUNC(zx_sa_Conditions_ADD_AudienceRestriction) */

void zx_sa_Conditions_ADD_AudienceRestriction(struct zx_sa_Conditions_s* x, int n, struct zx_sa_AudienceRestriction_s* z)
{
  struct zx_sa_AudienceRestriction_s* y;
  if (!x || !z) return;
  switch (n) {
  case 0:
  add_to_start:
    z->gg.g.n = &x->AudienceRestriction->gg.g;
    x->AudienceRestriction = z;
    return;
  case -1:
    y = x->AudienceRestriction;
    if (!y) goto add_to_start;
    for (; y->gg.g.n; y = (struct zx_sa_AudienceRestriction_s*)y->gg.g.n) ;
    break;
  default:
    for (y = x->AudienceRestriction; n > 1 && y; --n, y = (struct zx_sa_AudienceRestriction_s*)y->gg.g.n) ;
    if (!y) return;
  }
  z->gg.g.n = y->gg.g.n;
  y->gg.g.n = &z->gg.g;
}

/* FUNC(zx_sa_Conditions_DEL_AudienceRestriction) */

void zx_sa_Conditions_DEL_AudienceRestriction(struct zx_sa_Conditions_s* x, int n)
{
  struct zx_sa_AudienceRestriction_s* y;
  if (!x) return;
  switch (n) {
  case 0:
    x->AudienceRestriction = (struct zx_sa_AudienceRestriction_s*)x->AudienceRestriction->gg.g.n;
    return;
  case -1:
    y = (struct zx_sa_AudienceRestriction_s*)x->AudienceRestriction;
    if (!y) return;
    for (; y->gg.g.n; y = (struct zx_sa_AudienceRestriction_s*)y->gg.g.n) ;
    break;
  default:
    for (y = x->AudienceRestriction; n > 1 && y->gg.g.n; --n, y = (struct zx_sa_AudienceRestriction_s*)y->gg.g.n) ;
    if (!y->gg.g.n) return;
  }
  y->gg.g.n = y->gg.g.n->n;
}

#endif



#ifdef ZX_ENA_GETPUT

/* FUNC(zx_sa_Conditions_NUM_OneTimeUse) */

int zx_sa_Conditions_NUM_OneTimeUse(struct zx_sa_Conditions_s* x)
{
  struct zx_sa_OneTimeUse_s* y;
  int n = 0;
  if (!x) return 0;
  for (y = x->OneTimeUse; y; ++n, y = (struct zx_sa_OneTimeUse_s*)y->gg.g.n) ;
  return n;
}

/* FUNC(zx_sa_Conditions_GET_OneTimeUse) */

struct zx_sa_OneTimeUse_s* zx_sa_Conditions_GET_OneTimeUse(struct zx_sa_Conditions_s* x, int n)
{
  struct zx_sa_OneTimeUse_s* y;
  if (!x) return 0;
  for (y = x->OneTimeUse; n>=0 && y; --n, y = (struct zx_sa_OneTimeUse_s*)y->gg.g.n) ;
  return y;
}

/* FUNC(zx_sa_Conditions_POP_OneTimeUse) */

struct zx_sa_OneTimeUse_s* zx_sa_Conditions_POP_OneTimeUse(struct zx_sa_Conditions_s* x)
{
  struct zx_sa_OneTimeUse_s* y;
  if (!x) return 0;
  y = x->OneTimeUse;
  if (y)
    x->OneTimeUse = (struct zx_sa_OneTimeUse_s*)y->gg.g.n;
  return y;
}

/* FUNC(zx_sa_Conditions_PUSH_OneTimeUse) */

void zx_sa_Conditions_PUSH_OneTimeUse(struct zx_sa_Conditions_s* x, struct zx_sa_OneTimeUse_s* z)
{
  if (!x || !z) return;
  z->gg.g.n = &x->OneTimeUse->gg.g;
  x->OneTimeUse = z;
}

/* FUNC(zx_sa_Conditions_REV_OneTimeUse) */

void zx_sa_Conditions_REV_OneTimeUse(struct zx_sa_Conditions_s* x)
{
  struct zx_sa_OneTimeUse_s* nxt;
  struct zx_sa_OneTimeUse_s* y;
  if (!x) return;
  y = x->OneTimeUse;
  if (!y) return;
  x->OneTimeUse = 0;
  while (y) {
    nxt = (struct zx_sa_OneTimeUse_s*)y->gg.g.n;
    y->gg.g.n = &x->OneTimeUse->gg.g;
    x->OneTimeUse = y;
    y = nxt;
  }
}

/* FUNC(zx_sa_Conditions_PUT_OneTimeUse) */

void zx_sa_Conditions_PUT_OneTimeUse(struct zx_sa_Conditions_s* x, int n, struct zx_sa_OneTimeUse_s* z)
{
  struct zx_sa_OneTimeUse_s* y;
  if (!x || !z) return;
  y = x->OneTimeUse;
  if (!y) return;
  switch (n) {
  case 0:
    z->gg.g.n = y->gg.g.n;
    x->OneTimeUse = z;
    return;
  default:
    for (; n > 1 && y->gg.g.n; --n, y = (struct zx_sa_OneTimeUse_s*)y->gg.g.n) ;
    if (!y->gg.g.n) return;
    z->gg.g.n = y->gg.g.n->n;
    y->gg.g.n = &z->gg.g;
  }
}

/* FUNC(zx_sa_Conditions_ADD_OneTimeUse) */

void zx_sa_Conditions_ADD_OneTimeUse(struct zx_sa_Conditions_s* x, int n, struct zx_sa_OneTimeUse_s* z)
{
  struct zx_sa_OneTimeUse_s* y;
  if (!x || !z) return;
  switch (n) {
  case 0:
  add_to_start:
    z->gg.g.n = &x->OneTimeUse->gg.g;
    x->OneTimeUse = z;
    return;
  case -1:
    y = x->OneTimeUse;
    if (!y) goto add_to_start;
    for (; y->gg.g.n; y = (struct zx_sa_OneTimeUse_s*)y->gg.g.n) ;
    break;
  default:
    for (y = x->OneTimeUse; n > 1 && y; --n, y = (struct zx_sa_OneTimeUse_s*)y->gg.g.n) ;
    if (!y) return;
  }
  z->gg.g.n = y->gg.g.n;
  y->gg.g.n = &z->gg.g;
}

/* FUNC(zx_sa_Conditions_DEL_OneTimeUse) */

void zx_sa_Conditions_DEL_OneTimeUse(struct zx_sa_Conditions_s* x, int n)
{
  struct zx_sa_OneTimeUse_s* y;
  if (!x) return;
  switch (n) {
  case 0:
    x->OneTimeUse = (struct zx_sa_OneTimeUse_s*)x->OneTimeUse->gg.g.n;
    return;
  case -1:
    y = (struct zx_sa_OneTimeUse_s*)x->OneTimeUse;
    if (!y) return;
    for (; y->gg.g.n; y = (struct zx_sa_OneTimeUse_s*)y->gg.g.n) ;
    break;
  default:
    for (y = x->OneTimeUse; n > 1 && y->gg.g.n; --n, y = (struct zx_sa_OneTimeUse_s*)y->gg.g.n) ;
    if (!y->gg.g.n) return;
  }
  y->gg.g.n = y->gg.g.n->n;
}

#endif



#ifdef ZX_ENA_GETPUT

/* FUNC(zx_sa_Conditions_NUM_ProxyRestriction) */

int zx_sa_Conditions_NUM_ProxyRestriction(struct zx_sa_Conditions_s* x)
{
  struct zx_sa_ProxyRestriction_s* y;
  int n = 0;
  if (!x) return 0;
  for (y = x->ProxyRestriction; y; ++n, y = (struct zx_sa_ProxyRestriction_s*)y->gg.g.n) ;
  return n;
}

/* FUNC(zx_sa_Conditions_GET_ProxyRestriction) */

struct zx_sa_ProxyRestriction_s* zx_sa_Conditions_GET_ProxyRestriction(struct zx_sa_Conditions_s* x, int n)
{
  struct zx_sa_ProxyRestriction_s* y;
  if (!x) return 0;
  for (y = x->ProxyRestriction; n>=0 && y; --n, y = (struct zx_sa_ProxyRestriction_s*)y->gg.g.n) ;
  return y;
}

/* FUNC(zx_sa_Conditions_POP_ProxyRestriction) */

struct zx_sa_ProxyRestriction_s* zx_sa_Conditions_POP_ProxyRestriction(struct zx_sa_Conditions_s* x)
{
  struct zx_sa_ProxyRestriction_s* y;
  if (!x) return 0;
  y = x->ProxyRestriction;
  if (y)
    x->ProxyRestriction = (struct zx_sa_ProxyRestriction_s*)y->gg.g.n;
  return y;
}

/* FUNC(zx_sa_Conditions_PUSH_ProxyRestriction) */

void zx_sa_Conditions_PUSH_ProxyRestriction(struct zx_sa_Conditions_s* x, struct zx_sa_ProxyRestriction_s* z)
{
  if (!x || !z) return;
  z->gg.g.n = &x->ProxyRestriction->gg.g;
  x->ProxyRestriction = z;
}

/* FUNC(zx_sa_Conditions_REV_ProxyRestriction) */

void zx_sa_Conditions_REV_ProxyRestriction(struct zx_sa_Conditions_s* x)
{
  struct zx_sa_ProxyRestriction_s* nxt;
  struct zx_sa_ProxyRestriction_s* y;
  if (!x) return;
  y = x->ProxyRestriction;
  if (!y) return;
  x->ProxyRestriction = 0;
  while (y) {
    nxt = (struct zx_sa_ProxyRestriction_s*)y->gg.g.n;
    y->gg.g.n = &x->ProxyRestriction->gg.g;
    x->ProxyRestriction = y;
    y = nxt;
  }
}

/* FUNC(zx_sa_Conditions_PUT_ProxyRestriction) */

void zx_sa_Conditions_PUT_ProxyRestriction(struct zx_sa_Conditions_s* x, int n, struct zx_sa_ProxyRestriction_s* z)
{
  struct zx_sa_ProxyRestriction_s* y;
  if (!x || !z) return;
  y = x->ProxyRestriction;
  if (!y) return;
  switch (n) {
  case 0:
    z->gg.g.n = y->gg.g.n;
    x->ProxyRestriction = z;
    return;
  default:
    for (; n > 1 && y->gg.g.n; --n, y = (struct zx_sa_ProxyRestriction_s*)y->gg.g.n) ;
    if (!y->gg.g.n) return;
    z->gg.g.n = y->gg.g.n->n;
    y->gg.g.n = &z->gg.g;
  }
}

/* FUNC(zx_sa_Conditions_ADD_ProxyRestriction) */

void zx_sa_Conditions_ADD_ProxyRestriction(struct zx_sa_Conditions_s* x, int n, struct zx_sa_ProxyRestriction_s* z)
{
  struct zx_sa_ProxyRestriction_s* y;
  if (!x || !z) return;
  switch (n) {
  case 0:
  add_to_start:
    z->gg.g.n = &x->ProxyRestriction->gg.g;
    x->ProxyRestriction = z;
    return;
  case -1:
    y = x->ProxyRestriction;
    if (!y) goto add_to_start;
    for (; y->gg.g.n; y = (struct zx_sa_ProxyRestriction_s*)y->gg.g.n) ;
    break;
  default:
    for (y = x->ProxyRestriction; n > 1 && y; --n, y = (struct zx_sa_ProxyRestriction_s*)y->gg.g.n) ;
    if (!y) return;
  }
  z->gg.g.n = y->gg.g.n;
  y->gg.g.n = &z->gg.g;
}

/* FUNC(zx_sa_Conditions_DEL_ProxyRestriction) */

void zx_sa_Conditions_DEL_ProxyRestriction(struct zx_sa_Conditions_s* x, int n)
{
  struct zx_sa_ProxyRestriction_s* y;
  if (!x) return;
  switch (n) {
  case 0:
    x->ProxyRestriction = (struct zx_sa_ProxyRestriction_s*)x->ProxyRestriction->gg.g.n;
    return;
  case -1:
    y = (struct zx_sa_ProxyRestriction_s*)x->ProxyRestriction;
    if (!y) return;
    for (; y->gg.g.n; y = (struct zx_sa_ProxyRestriction_s*)y->gg.g.n) ;
    break;
  default:
    for (y = x->ProxyRestriction; n > 1 && y->gg.g.n; --n, y = (struct zx_sa_ProxyRestriction_s*)y->gg.g.n) ;
    if (!y->gg.g.n) return;
  }
  y->gg.g.n = y->gg.g.n->n;
}

#endif



#ifdef ZX_ENA_GETPUT

/* FUNC(zx_sa_Conditions_NUM_SubjectRestriction) */

int zx_sa_Conditions_NUM_SubjectRestriction(struct zx_sa_Conditions_s* x)
{
  struct zx_idp_SubjectRestriction_s* y;
  int n = 0;
  if (!x) return 0;
  for (y = x->SubjectRestriction; y; ++n, y = (struct zx_idp_SubjectRestriction_s*)y->gg.g.n) ;
  return n;
}

/* FUNC(zx_sa_Conditions_GET_SubjectRestriction) */

struct zx_idp_SubjectRestriction_s* zx_sa_Conditions_GET_SubjectRestriction(struct zx_sa_Conditions_s* x, int n)
{
  struct zx_idp_SubjectRestriction_s* y;
  if (!x) return 0;
  for (y = x->SubjectRestriction; n>=0 && y; --n, y = (struct zx_idp_SubjectRestriction_s*)y->gg.g.n) ;
  return y;
}

/* FUNC(zx_sa_Conditions_POP_SubjectRestriction) */

struct zx_idp_SubjectRestriction_s* zx_sa_Conditions_POP_SubjectRestriction(struct zx_sa_Conditions_s* x)
{
  struct zx_idp_SubjectRestriction_s* y;
  if (!x) return 0;
  y = x->SubjectRestriction;
  if (y)
    x->SubjectRestriction = (struct zx_idp_SubjectRestriction_s*)y->gg.g.n;
  return y;
}

/* FUNC(zx_sa_Conditions_PUSH_SubjectRestriction) */

void zx_sa_Conditions_PUSH_SubjectRestriction(struct zx_sa_Conditions_s* x, struct zx_idp_SubjectRestriction_s* z)
{
  if (!x || !z) return;
  z->gg.g.n = &x->SubjectRestriction->gg.g;
  x->SubjectRestriction = z;
}

/* FUNC(zx_sa_Conditions_REV_SubjectRestriction) */

void zx_sa_Conditions_REV_SubjectRestriction(struct zx_sa_Conditions_s* x)
{
  struct zx_idp_SubjectRestriction_s* nxt;
  struct zx_idp_SubjectRestriction_s* y;
  if (!x) return;
  y = x->SubjectRestriction;
  if (!y) return;
  x->SubjectRestriction = 0;
  while (y) {
    nxt = (struct zx_idp_SubjectRestriction_s*)y->gg.g.n;
    y->gg.g.n = &x->SubjectRestriction->gg.g;
    x->SubjectRestriction = y;
    y = nxt;
  }
}

/* FUNC(zx_sa_Conditions_PUT_SubjectRestriction) */

void zx_sa_Conditions_PUT_SubjectRestriction(struct zx_sa_Conditions_s* x, int n, struct zx_idp_SubjectRestriction_s* z)
{
  struct zx_idp_SubjectRestriction_s* y;
  if (!x || !z) return;
  y = x->SubjectRestriction;
  if (!y) return;
  switch (n) {
  case 0:
    z->gg.g.n = y->gg.g.n;
    x->SubjectRestriction = z;
    return;
  default:
    for (; n > 1 && y->gg.g.n; --n, y = (struct zx_idp_SubjectRestriction_s*)y->gg.g.n) ;
    if (!y->gg.g.n) return;
    z->gg.g.n = y->gg.g.n->n;
    y->gg.g.n = &z->gg.g;
  }
}

/* FUNC(zx_sa_Conditions_ADD_SubjectRestriction) */

void zx_sa_Conditions_ADD_SubjectRestriction(struct zx_sa_Conditions_s* x, int n, struct zx_idp_SubjectRestriction_s* z)
{
  struct zx_idp_SubjectRestriction_s* y;
  if (!x || !z) return;
  switch (n) {
  case 0:
  add_to_start:
    z->gg.g.n = &x->SubjectRestriction->gg.g;
    x->SubjectRestriction = z;
    return;
  case -1:
    y = x->SubjectRestriction;
    if (!y) goto add_to_start;
    for (; y->gg.g.n; y = (struct zx_idp_SubjectRestriction_s*)y->gg.g.n) ;
    break;
  default:
    for (y = x->SubjectRestriction; n > 1 && y; --n, y = (struct zx_idp_SubjectRestriction_s*)y->gg.g.n) ;
    if (!y) return;
  }
  z->gg.g.n = y->gg.g.n;
  y->gg.g.n = &z->gg.g;
}

/* FUNC(zx_sa_Conditions_DEL_SubjectRestriction) */

void zx_sa_Conditions_DEL_SubjectRestriction(struct zx_sa_Conditions_s* x, int n)
{
  struct zx_idp_SubjectRestriction_s* y;
  if (!x) return;
  switch (n) {
  case 0:
    x->SubjectRestriction = (struct zx_idp_SubjectRestriction_s*)x->SubjectRestriction->gg.g.n;
    return;
  case -1:
    y = (struct zx_idp_SubjectRestriction_s*)x->SubjectRestriction;
    if (!y) return;
    for (; y->gg.g.n; y = (struct zx_idp_SubjectRestriction_s*)y->gg.g.n) ;
    break;
  default:
    for (y = x->SubjectRestriction; n > 1 && y->gg.g.n; --n, y = (struct zx_idp_SubjectRestriction_s*)y->gg.g.n) ;
    if (!y->gg.g.n) return;
  }
  y->gg.g.n = y->gg.g.n->n;
}

#endif

/* FUNC(zx_sa_Conditions_GET_NotBefore) */
struct zx_str* zx_sa_Conditions_GET_NotBefore(struct zx_sa_Conditions_s* x) { return x->NotBefore; }
/* FUNC(zx_sa_Conditions_PUT_NotBefore) */
void zx_sa_Conditions_PUT_NotBefore(struct zx_sa_Conditions_s* x, struct zx_str* y) { x->NotBefore = y; }
/* FUNC(zx_sa_Conditions_GET_NotOnOrAfter) */
struct zx_str* zx_sa_Conditions_GET_NotOnOrAfter(struct zx_sa_Conditions_s* x) { return x->NotOnOrAfter; }
/* FUNC(zx_sa_Conditions_PUT_NotOnOrAfter) */
void zx_sa_Conditions_PUT_NotOnOrAfter(struct zx_sa_Conditions_s* x, struct zx_str* y) { x->NotOnOrAfter = y; }







#ifdef ZX_ENA_GETPUT

/* FUNC(zx_sa_EncryptedAssertion_NUM_EncryptedData) */

int zx_sa_EncryptedAssertion_NUM_EncryptedData(struct zx_sa_EncryptedAssertion_s* x)
{
  struct zx_xenc_EncryptedData_s* y;
  int n = 0;
  if (!x) return 0;
  for (y = x->EncryptedData; y; ++n, y = (struct zx_xenc_EncryptedData_s*)y->gg.g.n) ;
  return n;
}

/* FUNC(zx_sa_EncryptedAssertion_GET_EncryptedData) */

struct zx_xenc_EncryptedData_s* zx_sa_EncryptedAssertion_GET_EncryptedData(struct zx_sa_EncryptedAssertion_s* x, int n)
{
  struct zx_xenc_EncryptedData_s* y;
  if (!x) return 0;
  for (y = x->EncryptedData; n>=0 && y; --n, y = (struct zx_xenc_EncryptedData_s*)y->gg.g.n) ;
  return y;
}

/* FUNC(zx_sa_EncryptedAssertion_POP_EncryptedData) */

struct zx_xenc_EncryptedData_s* zx_sa_EncryptedAssertion_POP_EncryptedData(struct zx_sa_EncryptedAssertion_s* x)
{
  struct zx_xenc_EncryptedData_s* y;
  if (!x) return 0;
  y = x->EncryptedData;
  if (y)
    x->EncryptedData = (struct zx_xenc_EncryptedData_s*)y->gg.g.n;
  return y;
}

/* FUNC(zx_sa_EncryptedAssertion_PUSH_EncryptedData) */

void zx_sa_EncryptedAssertion_PUSH_EncryptedData(struct zx_sa_EncryptedAssertion_s* x, struct zx_xenc_EncryptedData_s* z)
{
  if (!x || !z) return;
  z->gg.g.n = &x->EncryptedData->gg.g;
  x->EncryptedData = z;
}

/* FUNC(zx_sa_EncryptedAssertion_REV_EncryptedData) */

void zx_sa_EncryptedAssertion_REV_EncryptedData(struct zx_sa_EncryptedAssertion_s* x)
{
  struct zx_xenc_EncryptedData_s* nxt;
  struct zx_xenc_EncryptedData_s* y;
  if (!x) return;
  y = x->EncryptedData;
  if (!y) return;
  x->EncryptedData = 0;
  while (y) {
    nxt = (struct zx_xenc_EncryptedData_s*)y->gg.g.n;
    y->gg.g.n = &x->EncryptedData->gg.g;
    x->EncryptedData = y;
    y = nxt;
  }
}

/* FUNC(zx_sa_EncryptedAssertion_PUT_EncryptedData) */

void zx_sa_EncryptedAssertion_PUT_EncryptedData(struct zx_sa_EncryptedAssertion_s* x, int n, struct zx_xenc_EncryptedData_s* z)
{
  struct zx_xenc_EncryptedData_s* y;
  if (!x || !z) return;
  y = x->EncryptedData;
  if (!y) return;
  switch (n) {
  case 0:
    z->gg.g.n = y->gg.g.n;
    x->EncryptedData = z;
    return;
  default:
    for (; n > 1 && y->gg.g.n; --n, y = (struct zx_xenc_EncryptedData_s*)y->gg.g.n) ;
    if (!y->gg.g.n) return;
    z->gg.g.n = y->gg.g.n->n;
    y->gg.g.n = &z->gg.g;
  }
}

/* FUNC(zx_sa_EncryptedAssertion_ADD_EncryptedData) */

void zx_sa_EncryptedAssertion_ADD_EncryptedData(struct zx_sa_EncryptedAssertion_s* x, int n, struct zx_xenc_EncryptedData_s* z)
{
  struct zx_xenc_EncryptedData_s* y;
  if (!x || !z) return;
  switch (n) {
  case 0:
  add_to_start:
    z->gg.g.n = &x->EncryptedData->gg.g;
    x->EncryptedData = z;
    return;
  case -1:
    y = x->EncryptedData;
    if (!y) goto add_to_start;
    for (; y->gg.g.n; y = (struct zx_xenc_EncryptedData_s*)y->gg.g.n) ;
    break;
  default:
    for (y = x->EncryptedData; n > 1 && y; --n, y = (struct zx_xenc_EncryptedData_s*)y->gg.g.n) ;
    if (!y) return;
  }
  z->gg.g.n = y->gg.g.n;
  y->gg.g.n = &z->gg.g;
}

/* FUNC(zx_sa_EncryptedAssertion_DEL_EncryptedData) */

void zx_sa_EncryptedAssertion_DEL_EncryptedData(struct zx_sa_EncryptedAssertion_s* x, int n)
{
  struct zx_xenc_EncryptedData_s* y;
  if (!x) return;
  switch (n) {
  case 0:
    x->EncryptedData = (struct zx_xenc_EncryptedData_s*)x->EncryptedData->gg.g.n;
    return;
  case -1:
    y = (struct zx_xenc_EncryptedData_s*)x->EncryptedData;
    if (!y) return;
    for (; y->gg.g.n; y = (struct zx_xenc_EncryptedData_s*)y->gg.g.n) ;
    break;
  default:
    for (y = x->EncryptedData; n > 1 && y->gg.g.n; --n, y = (struct zx_xenc_EncryptedData_s*)y->gg.g.n) ;
    if (!y->gg.g.n) return;
  }
  y->gg.g.n = y->gg.g.n->n;
}

#endif



#ifdef ZX_ENA_GETPUT

/* FUNC(zx_sa_EncryptedAssertion_NUM_EncryptedKey) */

int zx_sa_EncryptedAssertion_NUM_EncryptedKey(struct zx_sa_EncryptedAssertion_s* x)
{
  struct zx_xenc_EncryptedKey_s* y;
  int n = 0;
  if (!x) return 0;
  for (y = x->EncryptedKey; y; ++n, y = (struct zx_xenc_EncryptedKey_s*)y->gg.g.n) ;
  return n;
}

/* FUNC(zx_sa_EncryptedAssertion_GET_EncryptedKey) */

struct zx_xenc_EncryptedKey_s* zx_sa_EncryptedAssertion_GET_EncryptedKey(struct zx_sa_EncryptedAssertion_s* x, int n)
{
  struct zx_xenc_EncryptedKey_s* y;
  if (!x) return 0;
  for (y = x->EncryptedKey; n>=0 && y; --n, y = (struct zx_xenc_EncryptedKey_s*)y->gg.g.n) ;
  return y;
}

/* FUNC(zx_sa_EncryptedAssertion_POP_EncryptedKey) */

struct zx_xenc_EncryptedKey_s* zx_sa_EncryptedAssertion_POP_EncryptedKey(struct zx_sa_EncryptedAssertion_s* x)
{
  struct zx_xenc_EncryptedKey_s* y;
  if (!x) return 0;
  y = x->EncryptedKey;
  if (y)
    x->EncryptedKey = (struct zx_xenc_EncryptedKey_s*)y->gg.g.n;
  return y;
}

/* FUNC(zx_sa_EncryptedAssertion_PUSH_EncryptedKey) */

void zx_sa_EncryptedAssertion_PUSH_EncryptedKey(struct zx_sa_EncryptedAssertion_s* x, struct zx_xenc_EncryptedKey_s* z)
{
  if (!x || !z) return;
  z->gg.g.n = &x->EncryptedKey->gg.g;
  x->EncryptedKey = z;
}

/* FUNC(zx_sa_EncryptedAssertion_REV_EncryptedKey) */

void zx_sa_EncryptedAssertion_REV_EncryptedKey(struct zx_sa_EncryptedAssertion_s* x)
{
  struct zx_xenc_EncryptedKey_s* nxt;
  struct zx_xenc_EncryptedKey_s* y;
  if (!x) return;
  y = x->EncryptedKey;
  if (!y) return;
  x->EncryptedKey = 0;
  while (y) {
    nxt = (struct zx_xenc_EncryptedKey_s*)y->gg.g.n;
    y->gg.g.n = &x->EncryptedKey->gg.g;
    x->EncryptedKey = y;
    y = nxt;
  }
}

/* FUNC(zx_sa_EncryptedAssertion_PUT_EncryptedKey) */

void zx_sa_EncryptedAssertion_PUT_EncryptedKey(struct zx_sa_EncryptedAssertion_s* x, int n, struct zx_xenc_EncryptedKey_s* z)
{
  struct zx_xenc_EncryptedKey_s* y;
  if (!x || !z) return;
  y = x->EncryptedKey;
  if (!y) return;
  switch (n) {
  case 0:
    z->gg.g.n = y->gg.g.n;
    x->EncryptedKey = z;
    return;
  default:
    for (; n > 1 && y->gg.g.n; --n, y = (struct zx_xenc_EncryptedKey_s*)y->gg.g.n) ;
    if (!y->gg.g.n) return;
    z->gg.g.n = y->gg.g.n->n;
    y->gg.g.n = &z->gg.g;
  }
}

/* FUNC(zx_sa_EncryptedAssertion_ADD_EncryptedKey) */

void zx_sa_EncryptedAssertion_ADD_EncryptedKey(struct zx_sa_EncryptedAssertion_s* x, int n, struct zx_xenc_EncryptedKey_s* z)
{
  struct zx_xenc_EncryptedKey_s* y;
  if (!x || !z) return;
  switch (n) {
  case 0:
  add_to_start:
    z->gg.g.n = &x->EncryptedKey->gg.g;
    x->EncryptedKey = z;
    return;
  case -1:
    y = x->EncryptedKey;
    if (!y) goto add_to_start;
    for (; y->gg.g.n; y = (struct zx_xenc_EncryptedKey_s*)y->gg.g.n) ;
    break;
  default:
    for (y = x->EncryptedKey; n > 1 && y; --n, y = (struct zx_xenc_EncryptedKey_s*)y->gg.g.n) ;
    if (!y) return;
  }
  z->gg.g.n = y->gg.g.n;
  y->gg.g.n = &z->gg.g;
}

/* FUNC(zx_sa_EncryptedAssertion_DEL_EncryptedKey) */

void zx_sa_EncryptedAssertion_DEL_EncryptedKey(struct zx_sa_EncryptedAssertion_s* x, int n)
{
  struct zx_xenc_EncryptedKey_s* y;
  if (!x) return;
  switch (n) {
  case 0:
    x->EncryptedKey = (struct zx_xenc_EncryptedKey_s*)x->EncryptedKey->gg.g.n;
    return;
  case -1:
    y = (struct zx_xenc_EncryptedKey_s*)x->EncryptedKey;
    if (!y) return;
    for (; y->gg.g.n; y = (struct zx_xenc_EncryptedKey_s*)y->gg.g.n) ;
    break;
  default:
    for (y = x->EncryptedKey; n > 1 && y->gg.g.n; --n, y = (struct zx_xenc_EncryptedKey_s*)y->gg.g.n) ;
    if (!y->gg.g.n) return;
  }
  y->gg.g.n = y->gg.g.n->n;
}

#endif








#ifdef ZX_ENA_GETPUT

/* FUNC(zx_sa_EncryptedAttribute_NUM_EncryptedData) */

int zx_sa_EncryptedAttribute_NUM_EncryptedData(struct zx_sa_EncryptedAttribute_s* x)
{
  struct zx_xenc_EncryptedData_s* y;
  int n = 0;
  if (!x) return 0;
  for (y = x->EncryptedData; y; ++n, y = (struct zx_xenc_EncryptedData_s*)y->gg.g.n) ;
  return n;
}

/* FUNC(zx_sa_EncryptedAttribute_GET_EncryptedData) */

struct zx_xenc_EncryptedData_s* zx_sa_EncryptedAttribute_GET_EncryptedData(struct zx_sa_EncryptedAttribute_s* x, int n)
{
  struct zx_xenc_EncryptedData_s* y;
  if (!x) return 0;
  for (y = x->EncryptedData; n>=0 && y; --n, y = (struct zx_xenc_EncryptedData_s*)y->gg.g.n) ;
  return y;
}

/* FUNC(zx_sa_EncryptedAttribute_POP_EncryptedData) */

struct zx_xenc_EncryptedData_s* zx_sa_EncryptedAttribute_POP_EncryptedData(struct zx_sa_EncryptedAttribute_s* x)
{
  struct zx_xenc_EncryptedData_s* y;
  if (!x) return 0;
  y = x->EncryptedData;
  if (y)
    x->EncryptedData = (struct zx_xenc_EncryptedData_s*)y->gg.g.n;
  return y;
}

/* FUNC(zx_sa_EncryptedAttribute_PUSH_EncryptedData) */

void zx_sa_EncryptedAttribute_PUSH_EncryptedData(struct zx_sa_EncryptedAttribute_s* x, struct zx_xenc_EncryptedData_s* z)
{
  if (!x || !z) return;
  z->gg.g.n = &x->EncryptedData->gg.g;
  x->EncryptedData = z;
}

/* FUNC(zx_sa_EncryptedAttribute_REV_EncryptedData) */

void zx_sa_EncryptedAttribute_REV_EncryptedData(struct zx_sa_EncryptedAttribute_s* x)
{
  struct zx_xenc_EncryptedData_s* nxt;
  struct zx_xenc_EncryptedData_s* y;
  if (!x) return;
  y = x->EncryptedData;
  if (!y) return;
  x->EncryptedData = 0;
  while (y) {
    nxt = (struct zx_xenc_EncryptedData_s*)y->gg.g.n;
    y->gg.g.n = &x->EncryptedData->gg.g;
    x->EncryptedData = y;
    y = nxt;
  }
}

/* FUNC(zx_sa_EncryptedAttribute_PUT_EncryptedData) */

void zx_sa_EncryptedAttribute_PUT_EncryptedData(struct zx_sa_EncryptedAttribute_s* x, int n, struct zx_xenc_EncryptedData_s* z)
{
  struct zx_xenc_EncryptedData_s* y;
  if (!x || !z) return;
  y = x->EncryptedData;
  if (!y) return;
  switch (n) {
  case 0:
    z->gg.g.n = y->gg.g.n;
    x->EncryptedData = z;
    return;
  default:
    for (; n > 1 && y->gg.g.n; --n, y = (struct zx_xenc_EncryptedData_s*)y->gg.g.n) ;
    if (!y->gg.g.n) return;
    z->gg.g.n = y->gg.g.n->n;
    y->gg.g.n = &z->gg.g;
  }
}

/* FUNC(zx_sa_EncryptedAttribute_ADD_EncryptedData) */

void zx_sa_EncryptedAttribute_ADD_EncryptedData(struct zx_sa_EncryptedAttribute_s* x, int n, struct zx_xenc_EncryptedData_s* z)
{
  struct zx_xenc_EncryptedData_s* y;
  if (!x || !z) return;
  switch (n) {
  case 0:
  add_to_start:
    z->gg.g.n = &x->EncryptedData->gg.g;
    x->EncryptedData = z;
    return;
  case -1:
    y = x->EncryptedData;
    if (!y) goto add_to_start;
    for (; y->gg.g.n; y = (struct zx_xenc_EncryptedData_s*)y->gg.g.n) ;
    break;
  default:
    for (y = x->EncryptedData; n > 1 && y; --n, y = (struct zx_xenc_EncryptedData_s*)y->gg.g.n) ;
    if (!y) return;
  }
  z->gg.g.n = y->gg.g.n;
  y->gg.g.n = &z->gg.g;
}

/* FUNC(zx_sa_EncryptedAttribute_DEL_EncryptedData) */

void zx_sa_EncryptedAttribute_DEL_EncryptedData(struct zx_sa_EncryptedAttribute_s* x, int n)
{
  struct zx_xenc_EncryptedData_s* y;
  if (!x) return;
  switch (n) {
  case 0:
    x->EncryptedData = (struct zx_xenc_EncryptedData_s*)x->EncryptedData->gg.g.n;
    return;
  case -1:
    y = (struct zx_xenc_EncryptedData_s*)x->EncryptedData;
    if (!y) return;
    for (; y->gg.g.n; y = (struct zx_xenc_EncryptedData_s*)y->gg.g.n) ;
    break;
  default:
    for (y = x->EncryptedData; n > 1 && y->gg.g.n; --n, y = (struct zx_xenc_EncryptedData_s*)y->gg.g.n) ;
    if (!y->gg.g.n) return;
  }
  y->gg.g.n = y->gg.g.n->n;
}

#endif



#ifdef ZX_ENA_GETPUT

/* FUNC(zx_sa_EncryptedAttribute_NUM_EncryptedKey) */

int zx_sa_EncryptedAttribute_NUM_EncryptedKey(struct zx_sa_EncryptedAttribute_s* x)
{
  struct zx_xenc_EncryptedKey_s* y;
  int n = 0;
  if (!x) return 0;
  for (y = x->EncryptedKey; y; ++n, y = (struct zx_xenc_EncryptedKey_s*)y->gg.g.n) ;
  return n;
}

/* FUNC(zx_sa_EncryptedAttribute_GET_EncryptedKey) */

struct zx_xenc_EncryptedKey_s* zx_sa_EncryptedAttribute_GET_EncryptedKey(struct zx_sa_EncryptedAttribute_s* x, int n)
{
  struct zx_xenc_EncryptedKey_s* y;
  if (!x) return 0;
  for (y = x->EncryptedKey; n>=0 && y; --n, y = (struct zx_xenc_EncryptedKey_s*)y->gg.g.n) ;
  return y;
}

/* FUNC(zx_sa_EncryptedAttribute_POP_EncryptedKey) */

struct zx_xenc_EncryptedKey_s* zx_sa_EncryptedAttribute_POP_EncryptedKey(struct zx_sa_EncryptedAttribute_s* x)
{
  struct zx_xenc_EncryptedKey_s* y;
  if (!x) return 0;
  y = x->EncryptedKey;
  if (y)
    x->EncryptedKey = (struct zx_xenc_EncryptedKey_s*)y->gg.g.n;
  return y;
}

/* FUNC(zx_sa_EncryptedAttribute_PUSH_EncryptedKey) */

void zx_sa_EncryptedAttribute_PUSH_EncryptedKey(struct zx_sa_EncryptedAttribute_s* x, struct zx_xenc_EncryptedKey_s* z)
{
  if (!x || !z) return;
  z->gg.g.n = &x->EncryptedKey->gg.g;
  x->EncryptedKey = z;
}

/* FUNC(zx_sa_EncryptedAttribute_REV_EncryptedKey) */

void zx_sa_EncryptedAttribute_REV_EncryptedKey(struct zx_sa_EncryptedAttribute_s* x)
{
  struct zx_xenc_EncryptedKey_s* nxt;
  struct zx_xenc_EncryptedKey_s* y;
  if (!x) return;
  y = x->EncryptedKey;
  if (!y) return;
  x->EncryptedKey = 0;
  while (y) {
    nxt = (struct zx_xenc_EncryptedKey_s*)y->gg.g.n;
    y->gg.g.n = &x->EncryptedKey->gg.g;
    x->EncryptedKey = y;
    y = nxt;
  }
}

/* FUNC(zx_sa_EncryptedAttribute_PUT_EncryptedKey) */

void zx_sa_EncryptedAttribute_PUT_EncryptedKey(struct zx_sa_EncryptedAttribute_s* x, int n, struct zx_xenc_EncryptedKey_s* z)
{
  struct zx_xenc_EncryptedKey_s* y;
  if (!x || !z) return;
  y = x->EncryptedKey;
  if (!y) return;
  switch (n) {
  case 0:
    z->gg.g.n = y->gg.g.n;
    x->EncryptedKey = z;
    return;
  default:
    for (; n > 1 && y->gg.g.n; --n, y = (struct zx_xenc_EncryptedKey_s*)y->gg.g.n) ;
    if (!y->gg.g.n) return;
    z->gg.g.n = y->gg.g.n->n;
    y->gg.g.n = &z->gg.g;
  }
}

/* FUNC(zx_sa_EncryptedAttribute_ADD_EncryptedKey) */

void zx_sa_EncryptedAttribute_ADD_EncryptedKey(struct zx_sa_EncryptedAttribute_s* x, int n, struct zx_xenc_EncryptedKey_s* z)
{
  struct zx_xenc_EncryptedKey_s* y;
  if (!x || !z) return;
  switch (n) {
  case 0:
  add_to_start:
    z->gg.g.n = &x->EncryptedKey->gg.g;
    x->EncryptedKey = z;
    return;
  case -1:
    y = x->EncryptedKey;
    if (!y) goto add_to_start;
    for (; y->gg.g.n; y = (struct zx_xenc_EncryptedKey_s*)y->gg.g.n) ;
    break;
  default:
    for (y = x->EncryptedKey; n > 1 && y; --n, y = (struct zx_xenc_EncryptedKey_s*)y->gg.g.n) ;
    if (!y) return;
  }
  z->gg.g.n = y->gg.g.n;
  y->gg.g.n = &z->gg.g;
}

/* FUNC(zx_sa_EncryptedAttribute_DEL_EncryptedKey) */

void zx_sa_EncryptedAttribute_DEL_EncryptedKey(struct zx_sa_EncryptedAttribute_s* x, int n)
{
  struct zx_xenc_EncryptedKey_s* y;
  if (!x) return;
  switch (n) {
  case 0:
    x->EncryptedKey = (struct zx_xenc_EncryptedKey_s*)x->EncryptedKey->gg.g.n;
    return;
  case -1:
    y = (struct zx_xenc_EncryptedKey_s*)x->EncryptedKey;
    if (!y) return;
    for (; y->gg.g.n; y = (struct zx_xenc_EncryptedKey_s*)y->gg.g.n) ;
    break;
  default:
    for (y = x->EncryptedKey; n > 1 && y->gg.g.n; --n, y = (struct zx_xenc_EncryptedKey_s*)y->gg.g.n) ;
    if (!y->gg.g.n) return;
  }
  y->gg.g.n = y->gg.g.n->n;
}

#endif








#ifdef ZX_ENA_GETPUT

/* FUNC(zx_sa_EncryptedID_NUM_EncryptedData) */

int zx_sa_EncryptedID_NUM_EncryptedData(struct zx_sa_EncryptedID_s* x)
{
  struct zx_xenc_EncryptedData_s* y;
  int n = 0;
  if (!x) return 0;
  for (y = x->EncryptedData; y; ++n, y = (struct zx_xenc_EncryptedData_s*)y->gg.g.n) ;
  return n;
}

/* FUNC(zx_sa_EncryptedID_GET_EncryptedData) */

struct zx_xenc_EncryptedData_s* zx_sa_EncryptedID_GET_EncryptedData(struct zx_sa_EncryptedID_s* x, int n)
{
  struct zx_xenc_EncryptedData_s* y;
  if (!x) return 0;
  for (y = x->EncryptedData; n>=0 && y; --n, y = (struct zx_xenc_EncryptedData_s*)y->gg.g.n) ;
  return y;
}

/* FUNC(zx_sa_EncryptedID_POP_EncryptedData) */

struct zx_xenc_EncryptedData_s* zx_sa_EncryptedID_POP_EncryptedData(struct zx_sa_EncryptedID_s* x)
{
  struct zx_xenc_EncryptedData_s* y;
  if (!x) return 0;
  y = x->EncryptedData;
  if (y)
    x->EncryptedData = (struct zx_xenc_EncryptedData_s*)y->gg.g.n;
  return y;
}

/* FUNC(zx_sa_EncryptedID_PUSH_EncryptedData) */

void zx_sa_EncryptedID_PUSH_EncryptedData(struct zx_sa_EncryptedID_s* x, struct zx_xenc_EncryptedData_s* z)
{
  if (!x || !z) return;
  z->gg.g.n = &x->EncryptedData->gg.g;
  x->EncryptedData = z;
}

/* FUNC(zx_sa_EncryptedID_REV_EncryptedData) */

void zx_sa_EncryptedID_REV_EncryptedData(struct zx_sa_EncryptedID_s* x)
{
  struct zx_xenc_EncryptedData_s* nxt;
  struct zx_xenc_EncryptedData_s* y;
  if (!x) return;
  y = x->EncryptedData;
  if (!y) return;
  x->EncryptedData = 0;
  while (y) {
    nxt = (struct zx_xenc_EncryptedData_s*)y->gg.g.n;
    y->gg.g.n = &x->EncryptedData->gg.g;
    x->EncryptedData = y;
    y = nxt;
  }
}

/* FUNC(zx_sa_EncryptedID_PUT_EncryptedData) */

void zx_sa_EncryptedID_PUT_EncryptedData(struct zx_sa_EncryptedID_s* x, int n, struct zx_xenc_EncryptedData_s* z)
{
  struct zx_xenc_EncryptedData_s* y;
  if (!x || !z) return;
  y = x->EncryptedData;
  if (!y) return;
  switch (n) {
  case 0:
    z->gg.g.n = y->gg.g.n;
    x->EncryptedData = z;
    return;
  default:
    for (; n > 1 && y->gg.g.n; --n, y = (struct zx_xenc_EncryptedData_s*)y->gg.g.n) ;
    if (!y->gg.g.n) return;
    z->gg.g.n = y->gg.g.n->n;
    y->gg.g.n = &z->gg.g;
  }
}

/* FUNC(zx_sa_EncryptedID_ADD_EncryptedData) */

void zx_sa_EncryptedID_ADD_EncryptedData(struct zx_sa_EncryptedID_s* x, int n, struct zx_xenc_EncryptedData_s* z)
{
  struct zx_xenc_EncryptedData_s* y;
  if (!x || !z) return;
  switch (n) {
  case 0:
  add_to_start:
    z->gg.g.n = &x->EncryptedData->gg.g;
    x->EncryptedData = z;
    return;
  case -1:
    y = x->EncryptedData;
    if (!y) goto add_to_start;
    for (; y->gg.g.n; y = (struct zx_xenc_EncryptedData_s*)y->gg.g.n) ;
    break;
  default:
    for (y = x->EncryptedData; n > 1 && y; --n, y = (struct zx_xenc_EncryptedData_s*)y->gg.g.n) ;
    if (!y) return;
  }
  z->gg.g.n = y->gg.g.n;
  y->gg.g.n = &z->gg.g;
}

/* FUNC(zx_sa_EncryptedID_DEL_EncryptedData) */

void zx_sa_EncryptedID_DEL_EncryptedData(struct zx_sa_EncryptedID_s* x, int n)
{
  struct zx_xenc_EncryptedData_s* y;
  if (!x) return;
  switch (n) {
  case 0:
    x->EncryptedData = (struct zx_xenc_EncryptedData_s*)x->EncryptedData->gg.g.n;
    return;
  case -1:
    y = (struct zx_xenc_EncryptedData_s*)x->EncryptedData;
    if (!y) return;
    for (; y->gg.g.n; y = (struct zx_xenc_EncryptedData_s*)y->gg.g.n) ;
    break;
  default:
    for (y = x->EncryptedData; n > 1 && y->gg.g.n; --n, y = (struct zx_xenc_EncryptedData_s*)y->gg.g.n) ;
    if (!y->gg.g.n) return;
  }
  y->gg.g.n = y->gg.g.n->n;
}

#endif



#ifdef ZX_ENA_GETPUT

/* FUNC(zx_sa_EncryptedID_NUM_EncryptedKey) */

int zx_sa_EncryptedID_NUM_EncryptedKey(struct zx_sa_EncryptedID_s* x)
{
  struct zx_xenc_EncryptedKey_s* y;
  int n = 0;
  if (!x) return 0;
  for (y = x->EncryptedKey; y; ++n, y = (struct zx_xenc_EncryptedKey_s*)y->gg.g.n) ;
  return n;
}

/* FUNC(zx_sa_EncryptedID_GET_EncryptedKey) */

struct zx_xenc_EncryptedKey_s* zx_sa_EncryptedID_GET_EncryptedKey(struct zx_sa_EncryptedID_s* x, int n)
{
  struct zx_xenc_EncryptedKey_s* y;
  if (!x) return 0;
  for (y = x->EncryptedKey; n>=0 && y; --n, y = (struct zx_xenc_EncryptedKey_s*)y->gg.g.n) ;
  return y;
}

/* FUNC(zx_sa_EncryptedID_POP_EncryptedKey) */

struct zx_xenc_EncryptedKey_s* zx_sa_EncryptedID_POP_EncryptedKey(struct zx_sa_EncryptedID_s* x)
{
  struct zx_xenc_EncryptedKey_s* y;
  if (!x) return 0;
  y = x->EncryptedKey;
  if (y)
    x->EncryptedKey = (struct zx_xenc_EncryptedKey_s*)y->gg.g.n;
  return y;
}

/* FUNC(zx_sa_EncryptedID_PUSH_EncryptedKey) */

void zx_sa_EncryptedID_PUSH_EncryptedKey(struct zx_sa_EncryptedID_s* x, struct zx_xenc_EncryptedKey_s* z)
{
  if (!x || !z) return;
  z->gg.g.n = &x->EncryptedKey->gg.g;
  x->EncryptedKey = z;
}

/* FUNC(zx_sa_EncryptedID_REV_EncryptedKey) */

void zx_sa_EncryptedID_REV_EncryptedKey(struct zx_sa_EncryptedID_s* x)
{
  struct zx_xenc_EncryptedKey_s* nxt;
  struct zx_xenc_EncryptedKey_s* y;
  if (!x) return;
  y = x->EncryptedKey;
  if (!y) return;
  x->EncryptedKey = 0;
  while (y) {
    nxt = (struct zx_xenc_EncryptedKey_s*)y->gg.g.n;
    y->gg.g.n = &x->EncryptedKey->gg.g;
    x->EncryptedKey = y;
    y = nxt;
  }
}

/* FUNC(zx_sa_EncryptedID_PUT_EncryptedKey) */

void zx_sa_EncryptedID_PUT_EncryptedKey(struct zx_sa_EncryptedID_s* x, int n, struct zx_xenc_EncryptedKey_s* z)
{
  struct zx_xenc_EncryptedKey_s* y;
  if (!x || !z) return;
  y = x->EncryptedKey;
  if (!y) return;
  switch (n) {
  case 0:
    z->gg.g.n = y->gg.g.n;
    x->EncryptedKey = z;
    return;
  default:
    for (; n > 1 && y->gg.g.n; --n, y = (struct zx_xenc_EncryptedKey_s*)y->gg.g.n) ;
    if (!y->gg.g.n) return;
    z->gg.g.n = y->gg.g.n->n;
    y->gg.g.n = &z->gg.g;
  }
}

/* FUNC(zx_sa_EncryptedID_ADD_EncryptedKey) */

void zx_sa_EncryptedID_ADD_EncryptedKey(struct zx_sa_EncryptedID_s* x, int n, struct zx_xenc_EncryptedKey_s* z)
{
  struct zx_xenc_EncryptedKey_s* y;
  if (!x || !z) return;
  switch (n) {
  case 0:
  add_to_start:
    z->gg.g.n = &x->EncryptedKey->gg.g;
    x->EncryptedKey = z;
    return;
  case -1:
    y = x->EncryptedKey;
    if (!y) goto add_to_start;
    for (; y->gg.g.n; y = (struct zx_xenc_EncryptedKey_s*)y->gg.g.n) ;
    break;
  default:
    for (y = x->EncryptedKey; n > 1 && y; --n, y = (struct zx_xenc_EncryptedKey_s*)y->gg.g.n) ;
    if (!y) return;
  }
  z->gg.g.n = y->gg.g.n;
  y->gg.g.n = &z->gg.g;
}

/* FUNC(zx_sa_EncryptedID_DEL_EncryptedKey) */

void zx_sa_EncryptedID_DEL_EncryptedKey(struct zx_sa_EncryptedID_s* x, int n)
{
  struct zx_xenc_EncryptedKey_s* y;
  if (!x) return;
  switch (n) {
  case 0:
    x->EncryptedKey = (struct zx_xenc_EncryptedKey_s*)x->EncryptedKey->gg.g.n;
    return;
  case -1:
    y = (struct zx_xenc_EncryptedKey_s*)x->EncryptedKey;
    if (!y) return;
    for (; y->gg.g.n; y = (struct zx_xenc_EncryptedKey_s*)y->gg.g.n) ;
    break;
  default:
    for (y = x->EncryptedKey; n > 1 && y->gg.g.n; --n, y = (struct zx_xenc_EncryptedKey_s*)y->gg.g.n) ;
    if (!y->gg.g.n) return;
  }
  y->gg.g.n = y->gg.g.n->n;
}

#endif








#ifdef ZX_ENA_GETPUT

/* FUNC(zx_sa_Evidence_NUM_AssertionIDRef) */

int zx_sa_Evidence_NUM_AssertionIDRef(struct zx_sa_Evidence_s* x)
{
  struct zx_elem_s* y;
  int n = 0;
  if (!x) return 0;
  for (y = x->AssertionIDRef; y; ++n, y = (struct zx_elem_s*)y->g.n) ;
  return n;
}

/* FUNC(zx_sa_Evidence_GET_AssertionIDRef) */

struct zx_elem_s* zx_sa_Evidence_GET_AssertionIDRef(struct zx_sa_Evidence_s* x, int n)
{
  struct zx_elem_s* y;
  if (!x) return 0;
  for (y = x->AssertionIDRef; n>=0 && y; --n, y = (struct zx_elem_s*)y->g.n) ;
  return y;
}

/* FUNC(zx_sa_Evidence_POP_AssertionIDRef) */

struct zx_elem_s* zx_sa_Evidence_POP_AssertionIDRef(struct zx_sa_Evidence_s* x)
{
  struct zx_elem_s* y;
  if (!x) return 0;
  y = x->AssertionIDRef;
  if (y)
    x->AssertionIDRef = (struct zx_elem_s*)y->g.n;
  return y;
}

/* FUNC(zx_sa_Evidence_PUSH_AssertionIDRef) */

void zx_sa_Evidence_PUSH_AssertionIDRef(struct zx_sa_Evidence_s* x, struct zx_elem_s* z)
{
  if (!x || !z) return;
  z->g.n = &x->AssertionIDRef->g;
  x->AssertionIDRef = z;
}

/* FUNC(zx_sa_Evidence_REV_AssertionIDRef) */

void zx_sa_Evidence_REV_AssertionIDRef(struct zx_sa_Evidence_s* x)
{
  struct zx_elem_s* nxt;
  struct zx_elem_s* y;
  if (!x) return;
  y = x->AssertionIDRef;
  if (!y) return;
  x->AssertionIDRef = 0;
  while (y) {
    nxt = (struct zx_elem_s*)y->g.n;
    y->g.n = &x->AssertionIDRef->g;
    x->AssertionIDRef = y;
    y = nxt;
  }
}

/* FUNC(zx_sa_Evidence_PUT_AssertionIDRef) */

void zx_sa_Evidence_PUT_AssertionIDRef(struct zx_sa_Evidence_s* x, int n, struct zx_elem_s* z)
{
  struct zx_elem_s* y;
  if (!x || !z) return;
  y = x->AssertionIDRef;
  if (!y) return;
  switch (n) {
  case 0:
    z->g.n = y->g.n;
    x->AssertionIDRef = z;
    return;
  default:
    for (; n > 1 && y->g.n; --n, y = (struct zx_elem_s*)y->g.n) ;
    if (!y->g.n) return;
    z->g.n = y->g.n->n;
    y->g.n = &z->g;
  }
}

/* FUNC(zx_sa_Evidence_ADD_AssertionIDRef) */

void zx_sa_Evidence_ADD_AssertionIDRef(struct zx_sa_Evidence_s* x, int n, struct zx_elem_s* z)
{
  struct zx_elem_s* y;
  if (!x || !z) return;
  switch (n) {
  case 0:
  add_to_start:
    z->g.n = &x->AssertionIDRef->g;
    x->AssertionIDRef = z;
    return;
  case -1:
    y = x->AssertionIDRef;
    if (!y) goto add_to_start;
    for (; y->g.n; y = (struct zx_elem_s*)y->g.n) ;
    break;
  default:
    for (y = x->AssertionIDRef; n > 1 && y; --n, y = (struct zx_elem_s*)y->g.n) ;
    if (!y) return;
  }
  z->g.n = y->g.n;
  y->g.n = &z->g;
}

/* FUNC(zx_sa_Evidence_DEL_AssertionIDRef) */

void zx_sa_Evidence_DEL_AssertionIDRef(struct zx_sa_Evidence_s* x, int n)
{
  struct zx_elem_s* y;
  if (!x) return;
  switch (n) {
  case 0:
    x->AssertionIDRef = (struct zx_elem_s*)x->AssertionIDRef->g.n;
    return;
  case -1:
    y = (struct zx_elem_s*)x->AssertionIDRef;
    if (!y) return;
    for (; y->g.n; y = (struct zx_elem_s*)y->g.n) ;
    break;
  default:
    for (y = x->AssertionIDRef; n > 1 && y->g.n; --n, y = (struct zx_elem_s*)y->g.n) ;
    if (!y->g.n) return;
  }
  y->g.n = y->g.n->n;
}

#endif



#ifdef ZX_ENA_GETPUT

/* FUNC(zx_sa_Evidence_NUM_AssertionURIRef) */

int zx_sa_Evidence_NUM_AssertionURIRef(struct zx_sa_Evidence_s* x)
{
  struct zx_elem_s* y;
  int n = 0;
  if (!x) return 0;
  for (y = x->AssertionURIRef; y; ++n, y = (struct zx_elem_s*)y->g.n) ;
  return n;
}

/* FUNC(zx_sa_Evidence_GET_AssertionURIRef) */

struct zx_elem_s* zx_sa_Evidence_GET_AssertionURIRef(struct zx_sa_Evidence_s* x, int n)
{
  struct zx_elem_s* y;
  if (!x) return 0;
  for (y = x->AssertionURIRef; n>=0 && y; --n, y = (struct zx_elem_s*)y->g.n) ;
  return y;
}

/* FUNC(zx_sa_Evidence_POP_AssertionURIRef) */

struct zx_elem_s* zx_sa_Evidence_POP_AssertionURIRef(struct zx_sa_Evidence_s* x)
{
  struct zx_elem_s* y;
  if (!x) return 0;
  y = x->AssertionURIRef;
  if (y)
    x->AssertionURIRef = (struct zx_elem_s*)y->g.n;
  return y;
}

/* FUNC(zx_sa_Evidence_PUSH_AssertionURIRef) */

void zx_sa_Evidence_PUSH_AssertionURIRef(struct zx_sa_Evidence_s* x, struct zx_elem_s* z)
{
  if (!x || !z) return;
  z->g.n = &x->AssertionURIRef->g;
  x->AssertionURIRef = z;
}

/* FUNC(zx_sa_Evidence_REV_AssertionURIRef) */

void zx_sa_Evidence_REV_AssertionURIRef(struct zx_sa_Evidence_s* x)
{
  struct zx_elem_s* nxt;
  struct zx_elem_s* y;
  if (!x) return;
  y = x->AssertionURIRef;
  if (!y) return;
  x->AssertionURIRef = 0;
  while (y) {
    nxt = (struct zx_elem_s*)y->g.n;
    y->g.n = &x->AssertionURIRef->g;
    x->AssertionURIRef = y;
    y = nxt;
  }
}

/* FUNC(zx_sa_Evidence_PUT_AssertionURIRef) */

void zx_sa_Evidence_PUT_AssertionURIRef(struct zx_sa_Evidence_s* x, int n, struct zx_elem_s* z)
{
  struct zx_elem_s* y;
  if (!x || !z) return;
  y = x->AssertionURIRef;
  if (!y) return;
  switch (n) {
  case 0:
    z->g.n = y->g.n;
    x->AssertionURIRef = z;
    return;
  default:
    for (; n > 1 && y->g.n; --n, y = (struct zx_elem_s*)y->g.n) ;
    if (!y->g.n) return;
    z->g.n = y->g.n->n;
    y->g.n = &z->g;
  }
}

/* FUNC(zx_sa_Evidence_ADD_AssertionURIRef) */

void zx_sa_Evidence_ADD_AssertionURIRef(struct zx_sa_Evidence_s* x, int n, struct zx_elem_s* z)
{
  struct zx_elem_s* y;
  if (!x || !z) return;
  switch (n) {
  case 0:
  add_to_start:
    z->g.n = &x->AssertionURIRef->g;
    x->AssertionURIRef = z;
    return;
  case -1:
    y = x->AssertionURIRef;
    if (!y) goto add_to_start;
    for (; y->g.n; y = (struct zx_elem_s*)y->g.n) ;
    break;
  default:
    for (y = x->AssertionURIRef; n > 1 && y; --n, y = (struct zx_elem_s*)y->g.n) ;
    if (!y) return;
  }
  z->g.n = y->g.n;
  y->g.n = &z->g;
}

/* FUNC(zx_sa_Evidence_DEL_AssertionURIRef) */

void zx_sa_Evidence_DEL_AssertionURIRef(struct zx_sa_Evidence_s* x, int n)
{
  struct zx_elem_s* y;
  if (!x) return;
  switch (n) {
  case 0:
    x->AssertionURIRef = (struct zx_elem_s*)x->AssertionURIRef->g.n;
    return;
  case -1:
    y = (struct zx_elem_s*)x->AssertionURIRef;
    if (!y) return;
    for (; y->g.n; y = (struct zx_elem_s*)y->g.n) ;
    break;
  default:
    for (y = x->AssertionURIRef; n > 1 && y->g.n; --n, y = (struct zx_elem_s*)y->g.n) ;
    if (!y->g.n) return;
  }
  y->g.n = y->g.n->n;
}

#endif



#ifdef ZX_ENA_GETPUT

/* FUNC(zx_sa_Evidence_NUM_Assertion) */

int zx_sa_Evidence_NUM_Assertion(struct zx_sa_Evidence_s* x)
{
  struct zx_sa_Assertion_s* y;
  int n = 0;
  if (!x) return 0;
  for (y = x->Assertion; y; ++n, y = (struct zx_sa_Assertion_s*)y->gg.g.n) ;
  return n;
}

/* FUNC(zx_sa_Evidence_GET_Assertion) */

struct zx_sa_Assertion_s* zx_sa_Evidence_GET_Assertion(struct zx_sa_Evidence_s* x, int n)
{
  struct zx_sa_Assertion_s* y;
  if (!x) return 0;
  for (y = x->Assertion; n>=0 && y; --n, y = (struct zx_sa_Assertion_s*)y->gg.g.n) ;
  return y;
}

/* FUNC(zx_sa_Evidence_POP_Assertion) */

struct zx_sa_Assertion_s* zx_sa_Evidence_POP_Assertion(struct zx_sa_Evidence_s* x)
{
  struct zx_sa_Assertion_s* y;
  if (!x) return 0;
  y = x->Assertion;
  if (y)
    x->Assertion = (struct zx_sa_Assertion_s*)y->gg.g.n;
  return y;
}

/* FUNC(zx_sa_Evidence_PUSH_Assertion) */

void zx_sa_Evidence_PUSH_Assertion(struct zx_sa_Evidence_s* x, struct zx_sa_Assertion_s* z)
{
  if (!x || !z) return;
  z->gg.g.n = &x->Assertion->gg.g;
  x->Assertion = z;
}

/* FUNC(zx_sa_Evidence_REV_Assertion) */

void zx_sa_Evidence_REV_Assertion(struct zx_sa_Evidence_s* x)
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

/* FUNC(zx_sa_Evidence_PUT_Assertion) */

void zx_sa_Evidence_PUT_Assertion(struct zx_sa_Evidence_s* x, int n, struct zx_sa_Assertion_s* z)
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

/* FUNC(zx_sa_Evidence_ADD_Assertion) */

void zx_sa_Evidence_ADD_Assertion(struct zx_sa_Evidence_s* x, int n, struct zx_sa_Assertion_s* z)
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

/* FUNC(zx_sa_Evidence_DEL_Assertion) */

void zx_sa_Evidence_DEL_Assertion(struct zx_sa_Evidence_s* x, int n)
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

/* FUNC(zx_sa_Evidence_NUM_EncryptedAssertion) */

int zx_sa_Evidence_NUM_EncryptedAssertion(struct zx_sa_Evidence_s* x)
{
  struct zx_sa_EncryptedAssertion_s* y;
  int n = 0;
  if (!x) return 0;
  for (y = x->EncryptedAssertion; y; ++n, y = (struct zx_sa_EncryptedAssertion_s*)y->gg.g.n) ;
  return n;
}

/* FUNC(zx_sa_Evidence_GET_EncryptedAssertion) */

struct zx_sa_EncryptedAssertion_s* zx_sa_Evidence_GET_EncryptedAssertion(struct zx_sa_Evidence_s* x, int n)
{
  struct zx_sa_EncryptedAssertion_s* y;
  if (!x) return 0;
  for (y = x->EncryptedAssertion; n>=0 && y; --n, y = (struct zx_sa_EncryptedAssertion_s*)y->gg.g.n) ;
  return y;
}

/* FUNC(zx_sa_Evidence_POP_EncryptedAssertion) */

struct zx_sa_EncryptedAssertion_s* zx_sa_Evidence_POP_EncryptedAssertion(struct zx_sa_Evidence_s* x)
{
  struct zx_sa_EncryptedAssertion_s* y;
  if (!x) return 0;
  y = x->EncryptedAssertion;
  if (y)
    x->EncryptedAssertion = (struct zx_sa_EncryptedAssertion_s*)y->gg.g.n;
  return y;
}

/* FUNC(zx_sa_Evidence_PUSH_EncryptedAssertion) */

void zx_sa_Evidence_PUSH_EncryptedAssertion(struct zx_sa_Evidence_s* x, struct zx_sa_EncryptedAssertion_s* z)
{
  if (!x || !z) return;
  z->gg.g.n = &x->EncryptedAssertion->gg.g;
  x->EncryptedAssertion = z;
}

/* FUNC(zx_sa_Evidence_REV_EncryptedAssertion) */

void zx_sa_Evidence_REV_EncryptedAssertion(struct zx_sa_Evidence_s* x)
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

/* FUNC(zx_sa_Evidence_PUT_EncryptedAssertion) */

void zx_sa_Evidence_PUT_EncryptedAssertion(struct zx_sa_Evidence_s* x, int n, struct zx_sa_EncryptedAssertion_s* z)
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

/* FUNC(zx_sa_Evidence_ADD_EncryptedAssertion) */

void zx_sa_Evidence_ADD_EncryptedAssertion(struct zx_sa_Evidence_s* x, int n, struct zx_sa_EncryptedAssertion_s* z)
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

/* FUNC(zx_sa_Evidence_DEL_EncryptedAssertion) */

void zx_sa_Evidence_DEL_EncryptedAssertion(struct zx_sa_Evidence_s* x, int n)
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






/* FUNC(zx_sa_Issuer_GET_Format) */
struct zx_str* zx_sa_Issuer_GET_Format(struct zx_sa_Issuer_s* x) { return x->Format; }
/* FUNC(zx_sa_Issuer_PUT_Format) */
void zx_sa_Issuer_PUT_Format(struct zx_sa_Issuer_s* x, struct zx_str* y) { x->Format = y; }
/* FUNC(zx_sa_Issuer_GET_NameQualifier) */
struct zx_str* zx_sa_Issuer_GET_NameQualifier(struct zx_sa_Issuer_s* x) { return x->NameQualifier; }
/* FUNC(zx_sa_Issuer_PUT_NameQualifier) */
void zx_sa_Issuer_PUT_NameQualifier(struct zx_sa_Issuer_s* x, struct zx_str* y) { x->NameQualifier = y; }
/* FUNC(zx_sa_Issuer_GET_SPNameQualifier) */
struct zx_str* zx_sa_Issuer_GET_SPNameQualifier(struct zx_sa_Issuer_s* x) { return x->SPNameQualifier; }
/* FUNC(zx_sa_Issuer_PUT_SPNameQualifier) */
void zx_sa_Issuer_PUT_SPNameQualifier(struct zx_sa_Issuer_s* x, struct zx_str* y) { x->SPNameQualifier = y; }
/* FUNC(zx_sa_Issuer_GET_SPProvidedID) */
struct zx_str* zx_sa_Issuer_GET_SPProvidedID(struct zx_sa_Issuer_s* x) { return x->SPProvidedID; }
/* FUNC(zx_sa_Issuer_PUT_SPProvidedID) */
void zx_sa_Issuer_PUT_SPProvidedID(struct zx_sa_Issuer_s* x, struct zx_str* y) { x->SPProvidedID = y; }





/* FUNC(zx_sa_NameID_GET_Format) */
struct zx_str* zx_sa_NameID_GET_Format(struct zx_sa_NameID_s* x) { return x->Format; }
/* FUNC(zx_sa_NameID_PUT_Format) */
void zx_sa_NameID_PUT_Format(struct zx_sa_NameID_s* x, struct zx_str* y) { x->Format = y; }
/* FUNC(zx_sa_NameID_GET_NameQualifier) */
struct zx_str* zx_sa_NameID_GET_NameQualifier(struct zx_sa_NameID_s* x) { return x->NameQualifier; }
/* FUNC(zx_sa_NameID_PUT_NameQualifier) */
void zx_sa_NameID_PUT_NameQualifier(struct zx_sa_NameID_s* x, struct zx_str* y) { x->NameQualifier = y; }
/* FUNC(zx_sa_NameID_GET_SPNameQualifier) */
struct zx_str* zx_sa_NameID_GET_SPNameQualifier(struct zx_sa_NameID_s* x) { return x->SPNameQualifier; }
/* FUNC(zx_sa_NameID_PUT_SPNameQualifier) */
void zx_sa_NameID_PUT_SPNameQualifier(struct zx_sa_NameID_s* x, struct zx_str* y) { x->SPNameQualifier = y; }
/* FUNC(zx_sa_NameID_GET_SPProvidedID) */
struct zx_str* zx_sa_NameID_GET_SPProvidedID(struct zx_sa_NameID_s* x) { return x->SPProvidedID; }
/* FUNC(zx_sa_NameID_PUT_SPProvidedID) */
void zx_sa_NameID_PUT_SPProvidedID(struct zx_sa_NameID_s* x, struct zx_str* y) { x->SPProvidedID = y; }












#ifdef ZX_ENA_GETPUT

/* FUNC(zx_sa_ProxyRestriction_NUM_Audience) */

int zx_sa_ProxyRestriction_NUM_Audience(struct zx_sa_ProxyRestriction_s* x)
{
  struct zx_elem_s* y;
  int n = 0;
  if (!x) return 0;
  for (y = x->Audience; y; ++n, y = (struct zx_elem_s*)y->g.n) ;
  return n;
}

/* FUNC(zx_sa_ProxyRestriction_GET_Audience) */

struct zx_elem_s* zx_sa_ProxyRestriction_GET_Audience(struct zx_sa_ProxyRestriction_s* x, int n)
{
  struct zx_elem_s* y;
  if (!x) return 0;
  for (y = x->Audience; n>=0 && y; --n, y = (struct zx_elem_s*)y->g.n) ;
  return y;
}

/* FUNC(zx_sa_ProxyRestriction_POP_Audience) */

struct zx_elem_s* zx_sa_ProxyRestriction_POP_Audience(struct zx_sa_ProxyRestriction_s* x)
{
  struct zx_elem_s* y;
  if (!x) return 0;
  y = x->Audience;
  if (y)
    x->Audience = (struct zx_elem_s*)y->g.n;
  return y;
}

/* FUNC(zx_sa_ProxyRestriction_PUSH_Audience) */

void zx_sa_ProxyRestriction_PUSH_Audience(struct zx_sa_ProxyRestriction_s* x, struct zx_elem_s* z)
{
  if (!x || !z) return;
  z->g.n = &x->Audience->g;
  x->Audience = z;
}

/* FUNC(zx_sa_ProxyRestriction_REV_Audience) */

void zx_sa_ProxyRestriction_REV_Audience(struct zx_sa_ProxyRestriction_s* x)
{
  struct zx_elem_s* nxt;
  struct zx_elem_s* y;
  if (!x) return;
  y = x->Audience;
  if (!y) return;
  x->Audience = 0;
  while (y) {
    nxt = (struct zx_elem_s*)y->g.n;
    y->g.n = &x->Audience->g;
    x->Audience = y;
    y = nxt;
  }
}

/* FUNC(zx_sa_ProxyRestriction_PUT_Audience) */

void zx_sa_ProxyRestriction_PUT_Audience(struct zx_sa_ProxyRestriction_s* x, int n, struct zx_elem_s* z)
{
  struct zx_elem_s* y;
  if (!x || !z) return;
  y = x->Audience;
  if (!y) return;
  switch (n) {
  case 0:
    z->g.n = y->g.n;
    x->Audience = z;
    return;
  default:
    for (; n > 1 && y->g.n; --n, y = (struct zx_elem_s*)y->g.n) ;
    if (!y->g.n) return;
    z->g.n = y->g.n->n;
    y->g.n = &z->g;
  }
}

/* FUNC(zx_sa_ProxyRestriction_ADD_Audience) */

void zx_sa_ProxyRestriction_ADD_Audience(struct zx_sa_ProxyRestriction_s* x, int n, struct zx_elem_s* z)
{
  struct zx_elem_s* y;
  if (!x || !z) return;
  switch (n) {
  case 0:
  add_to_start:
    z->g.n = &x->Audience->g;
    x->Audience = z;
    return;
  case -1:
    y = x->Audience;
    if (!y) goto add_to_start;
    for (; y->g.n; y = (struct zx_elem_s*)y->g.n) ;
    break;
  default:
    for (y = x->Audience; n > 1 && y; --n, y = (struct zx_elem_s*)y->g.n) ;
    if (!y) return;
  }
  z->g.n = y->g.n;
  y->g.n = &z->g;
}

/* FUNC(zx_sa_ProxyRestriction_DEL_Audience) */

void zx_sa_ProxyRestriction_DEL_Audience(struct zx_sa_ProxyRestriction_s* x, int n)
{
  struct zx_elem_s* y;
  if (!x) return;
  switch (n) {
  case 0:
    x->Audience = (struct zx_elem_s*)x->Audience->g.n;
    return;
  case -1:
    y = (struct zx_elem_s*)x->Audience;
    if (!y) return;
    for (; y->g.n; y = (struct zx_elem_s*)y->g.n) ;
    break;
  default:
    for (y = x->Audience; n > 1 && y->g.n; --n, y = (struct zx_elem_s*)y->g.n) ;
    if (!y->g.n) return;
  }
  y->g.n = y->g.n->n;
}

#endif

/* FUNC(zx_sa_ProxyRestriction_GET_Count) */
struct zx_str* zx_sa_ProxyRestriction_GET_Count(struct zx_sa_ProxyRestriction_s* x) { return x->Count; }
/* FUNC(zx_sa_ProxyRestriction_PUT_Count) */
void zx_sa_ProxyRestriction_PUT_Count(struct zx_sa_ProxyRestriction_s* x, struct zx_str* y) { x->Count = y; }







#ifdef ZX_ENA_GETPUT

/* FUNC(zx_sa_Statement_NUM_Response) */

int zx_sa_Statement_NUM_Response(struct zx_sa_Statement_s* x)
{
  struct zx_xac_Response_s* y;
  int n = 0;
  if (!x) return 0;
  for (y = x->Response; y; ++n, y = (struct zx_xac_Response_s*)y->gg.g.n) ;
  return n;
}

/* FUNC(zx_sa_Statement_GET_Response) */

struct zx_xac_Response_s* zx_sa_Statement_GET_Response(struct zx_sa_Statement_s* x, int n)
{
  struct zx_xac_Response_s* y;
  if (!x) return 0;
  for (y = x->Response; n>=0 && y; --n, y = (struct zx_xac_Response_s*)y->gg.g.n) ;
  return y;
}

/* FUNC(zx_sa_Statement_POP_Response) */

struct zx_xac_Response_s* zx_sa_Statement_POP_Response(struct zx_sa_Statement_s* x)
{
  struct zx_xac_Response_s* y;
  if (!x) return 0;
  y = x->Response;
  if (y)
    x->Response = (struct zx_xac_Response_s*)y->gg.g.n;
  return y;
}

/* FUNC(zx_sa_Statement_PUSH_Response) */

void zx_sa_Statement_PUSH_Response(struct zx_sa_Statement_s* x, struct zx_xac_Response_s* z)
{
  if (!x || !z) return;
  z->gg.g.n = &x->Response->gg.g;
  x->Response = z;
}

/* FUNC(zx_sa_Statement_REV_Response) */

void zx_sa_Statement_REV_Response(struct zx_sa_Statement_s* x)
{
  struct zx_xac_Response_s* nxt;
  struct zx_xac_Response_s* y;
  if (!x) return;
  y = x->Response;
  if (!y) return;
  x->Response = 0;
  while (y) {
    nxt = (struct zx_xac_Response_s*)y->gg.g.n;
    y->gg.g.n = &x->Response->gg.g;
    x->Response = y;
    y = nxt;
  }
}

/* FUNC(zx_sa_Statement_PUT_Response) */

void zx_sa_Statement_PUT_Response(struct zx_sa_Statement_s* x, int n, struct zx_xac_Response_s* z)
{
  struct zx_xac_Response_s* y;
  if (!x || !z) return;
  y = x->Response;
  if (!y) return;
  switch (n) {
  case 0:
    z->gg.g.n = y->gg.g.n;
    x->Response = z;
    return;
  default:
    for (; n > 1 && y->gg.g.n; --n, y = (struct zx_xac_Response_s*)y->gg.g.n) ;
    if (!y->gg.g.n) return;
    z->gg.g.n = y->gg.g.n->n;
    y->gg.g.n = &z->gg.g;
  }
}

/* FUNC(zx_sa_Statement_ADD_Response) */

void zx_sa_Statement_ADD_Response(struct zx_sa_Statement_s* x, int n, struct zx_xac_Response_s* z)
{
  struct zx_xac_Response_s* y;
  if (!x || !z) return;
  switch (n) {
  case 0:
  add_to_start:
    z->gg.g.n = &x->Response->gg.g;
    x->Response = z;
    return;
  case -1:
    y = x->Response;
    if (!y) goto add_to_start;
    for (; y->gg.g.n; y = (struct zx_xac_Response_s*)y->gg.g.n) ;
    break;
  default:
    for (y = x->Response; n > 1 && y; --n, y = (struct zx_xac_Response_s*)y->gg.g.n) ;
    if (!y) return;
  }
  z->gg.g.n = y->gg.g.n;
  y->gg.g.n = &z->gg.g;
}

/* FUNC(zx_sa_Statement_DEL_Response) */

void zx_sa_Statement_DEL_Response(struct zx_sa_Statement_s* x, int n)
{
  struct zx_xac_Response_s* y;
  if (!x) return;
  switch (n) {
  case 0:
    x->Response = (struct zx_xac_Response_s*)x->Response->gg.g.n;
    return;
  case -1:
    y = (struct zx_xac_Response_s*)x->Response;
    if (!y) return;
    for (; y->gg.g.n; y = (struct zx_xac_Response_s*)y->gg.g.n) ;
    break;
  default:
    for (y = x->Response; n > 1 && y->gg.g.n; --n, y = (struct zx_xac_Response_s*)y->gg.g.n) ;
    if (!y->gg.g.n) return;
  }
  y->gg.g.n = y->gg.g.n->n;
}

#endif



#ifdef ZX_ENA_GETPUT

/* FUNC(zx_sa_Statement_NUM_Request) */

int zx_sa_Statement_NUM_Request(struct zx_sa_Statement_s* x)
{
  struct zx_xac_Request_s* y;
  int n = 0;
  if (!x) return 0;
  for (y = x->Request; y; ++n, y = (struct zx_xac_Request_s*)y->gg.g.n) ;
  return n;
}

/* FUNC(zx_sa_Statement_GET_Request) */

struct zx_xac_Request_s* zx_sa_Statement_GET_Request(struct zx_sa_Statement_s* x, int n)
{
  struct zx_xac_Request_s* y;
  if (!x) return 0;
  for (y = x->Request; n>=0 && y; --n, y = (struct zx_xac_Request_s*)y->gg.g.n) ;
  return y;
}

/* FUNC(zx_sa_Statement_POP_Request) */

struct zx_xac_Request_s* zx_sa_Statement_POP_Request(struct zx_sa_Statement_s* x)
{
  struct zx_xac_Request_s* y;
  if (!x) return 0;
  y = x->Request;
  if (y)
    x->Request = (struct zx_xac_Request_s*)y->gg.g.n;
  return y;
}

/* FUNC(zx_sa_Statement_PUSH_Request) */

void zx_sa_Statement_PUSH_Request(struct zx_sa_Statement_s* x, struct zx_xac_Request_s* z)
{
  if (!x || !z) return;
  z->gg.g.n = &x->Request->gg.g;
  x->Request = z;
}

/* FUNC(zx_sa_Statement_REV_Request) */

void zx_sa_Statement_REV_Request(struct zx_sa_Statement_s* x)
{
  struct zx_xac_Request_s* nxt;
  struct zx_xac_Request_s* y;
  if (!x) return;
  y = x->Request;
  if (!y) return;
  x->Request = 0;
  while (y) {
    nxt = (struct zx_xac_Request_s*)y->gg.g.n;
    y->gg.g.n = &x->Request->gg.g;
    x->Request = y;
    y = nxt;
  }
}

/* FUNC(zx_sa_Statement_PUT_Request) */

void zx_sa_Statement_PUT_Request(struct zx_sa_Statement_s* x, int n, struct zx_xac_Request_s* z)
{
  struct zx_xac_Request_s* y;
  if (!x || !z) return;
  y = x->Request;
  if (!y) return;
  switch (n) {
  case 0:
    z->gg.g.n = y->gg.g.n;
    x->Request = z;
    return;
  default:
    for (; n > 1 && y->gg.g.n; --n, y = (struct zx_xac_Request_s*)y->gg.g.n) ;
    if (!y->gg.g.n) return;
    z->gg.g.n = y->gg.g.n->n;
    y->gg.g.n = &z->gg.g;
  }
}

/* FUNC(zx_sa_Statement_ADD_Request) */

void zx_sa_Statement_ADD_Request(struct zx_sa_Statement_s* x, int n, struct zx_xac_Request_s* z)
{
  struct zx_xac_Request_s* y;
  if (!x || !z) return;
  switch (n) {
  case 0:
  add_to_start:
    z->gg.g.n = &x->Request->gg.g;
    x->Request = z;
    return;
  case -1:
    y = x->Request;
    if (!y) goto add_to_start;
    for (; y->gg.g.n; y = (struct zx_xac_Request_s*)y->gg.g.n) ;
    break;
  default:
    for (y = x->Request; n > 1 && y; --n, y = (struct zx_xac_Request_s*)y->gg.g.n) ;
    if (!y) return;
  }
  z->gg.g.n = y->gg.g.n;
  y->gg.g.n = &z->gg.g;
}

/* FUNC(zx_sa_Statement_DEL_Request) */

void zx_sa_Statement_DEL_Request(struct zx_sa_Statement_s* x, int n)
{
  struct zx_xac_Request_s* y;
  if (!x) return;
  switch (n) {
  case 0:
    x->Request = (struct zx_xac_Request_s*)x->Request->gg.g.n;
    return;
  case -1:
    y = (struct zx_xac_Request_s*)x->Request;
    if (!y) return;
    for (; y->gg.g.n; y = (struct zx_xac_Request_s*)y->gg.g.n) ;
    break;
  default:
    for (y = x->Request; n > 1 && y->gg.g.n; --n, y = (struct zx_xac_Request_s*)y->gg.g.n) ;
    if (!y->gg.g.n) return;
  }
  y->gg.g.n = y->gg.g.n->n;
}

#endif

/* FUNC(zx_sa_Statement_GET_type) */
struct zx_str* zx_sa_Statement_GET_type(struct zx_sa_Statement_s* x) { return x->type; }
/* FUNC(zx_sa_Statement_PUT_type) */
void zx_sa_Statement_PUT_type(struct zx_sa_Statement_s* x, struct zx_str* y) { x->type = y; }







#ifdef ZX_ENA_GETPUT

/* FUNC(zx_sa_Subject_NUM_BaseID) */

int zx_sa_Subject_NUM_BaseID(struct zx_sa_Subject_s* x)
{
  struct zx_sa_BaseID_s* y;
  int n = 0;
  if (!x) return 0;
  for (y = x->BaseID; y; ++n, y = (struct zx_sa_BaseID_s*)y->gg.g.n) ;
  return n;
}

/* FUNC(zx_sa_Subject_GET_BaseID) */

struct zx_sa_BaseID_s* zx_sa_Subject_GET_BaseID(struct zx_sa_Subject_s* x, int n)
{
  struct zx_sa_BaseID_s* y;
  if (!x) return 0;
  for (y = x->BaseID; n>=0 && y; --n, y = (struct zx_sa_BaseID_s*)y->gg.g.n) ;
  return y;
}

/* FUNC(zx_sa_Subject_POP_BaseID) */

struct zx_sa_BaseID_s* zx_sa_Subject_POP_BaseID(struct zx_sa_Subject_s* x)
{
  struct zx_sa_BaseID_s* y;
  if (!x) return 0;
  y = x->BaseID;
  if (y)
    x->BaseID = (struct zx_sa_BaseID_s*)y->gg.g.n;
  return y;
}

/* FUNC(zx_sa_Subject_PUSH_BaseID) */

void zx_sa_Subject_PUSH_BaseID(struct zx_sa_Subject_s* x, struct zx_sa_BaseID_s* z)
{
  if (!x || !z) return;
  z->gg.g.n = &x->BaseID->gg.g;
  x->BaseID = z;
}

/* FUNC(zx_sa_Subject_REV_BaseID) */

void zx_sa_Subject_REV_BaseID(struct zx_sa_Subject_s* x)
{
  struct zx_sa_BaseID_s* nxt;
  struct zx_sa_BaseID_s* y;
  if (!x) return;
  y = x->BaseID;
  if (!y) return;
  x->BaseID = 0;
  while (y) {
    nxt = (struct zx_sa_BaseID_s*)y->gg.g.n;
    y->gg.g.n = &x->BaseID->gg.g;
    x->BaseID = y;
    y = nxt;
  }
}

/* FUNC(zx_sa_Subject_PUT_BaseID) */

void zx_sa_Subject_PUT_BaseID(struct zx_sa_Subject_s* x, int n, struct zx_sa_BaseID_s* z)
{
  struct zx_sa_BaseID_s* y;
  if (!x || !z) return;
  y = x->BaseID;
  if (!y) return;
  switch (n) {
  case 0:
    z->gg.g.n = y->gg.g.n;
    x->BaseID = z;
    return;
  default:
    for (; n > 1 && y->gg.g.n; --n, y = (struct zx_sa_BaseID_s*)y->gg.g.n) ;
    if (!y->gg.g.n) return;
    z->gg.g.n = y->gg.g.n->n;
    y->gg.g.n = &z->gg.g;
  }
}

/* FUNC(zx_sa_Subject_ADD_BaseID) */

void zx_sa_Subject_ADD_BaseID(struct zx_sa_Subject_s* x, int n, struct zx_sa_BaseID_s* z)
{
  struct zx_sa_BaseID_s* y;
  if (!x || !z) return;
  switch (n) {
  case 0:
  add_to_start:
    z->gg.g.n = &x->BaseID->gg.g;
    x->BaseID = z;
    return;
  case -1:
    y = x->BaseID;
    if (!y) goto add_to_start;
    for (; y->gg.g.n; y = (struct zx_sa_BaseID_s*)y->gg.g.n) ;
    break;
  default:
    for (y = x->BaseID; n > 1 && y; --n, y = (struct zx_sa_BaseID_s*)y->gg.g.n) ;
    if (!y) return;
  }
  z->gg.g.n = y->gg.g.n;
  y->gg.g.n = &z->gg.g;
}

/* FUNC(zx_sa_Subject_DEL_BaseID) */

void zx_sa_Subject_DEL_BaseID(struct zx_sa_Subject_s* x, int n)
{
  struct zx_sa_BaseID_s* y;
  if (!x) return;
  switch (n) {
  case 0:
    x->BaseID = (struct zx_sa_BaseID_s*)x->BaseID->gg.g.n;
    return;
  case -1:
    y = (struct zx_sa_BaseID_s*)x->BaseID;
    if (!y) return;
    for (; y->gg.g.n; y = (struct zx_sa_BaseID_s*)y->gg.g.n) ;
    break;
  default:
    for (y = x->BaseID; n > 1 && y->gg.g.n; --n, y = (struct zx_sa_BaseID_s*)y->gg.g.n) ;
    if (!y->gg.g.n) return;
  }
  y->gg.g.n = y->gg.g.n->n;
}

#endif



#ifdef ZX_ENA_GETPUT

/* FUNC(zx_sa_Subject_NUM_NameID) */

int zx_sa_Subject_NUM_NameID(struct zx_sa_Subject_s* x)
{
  struct zx_sa_NameID_s* y;
  int n = 0;
  if (!x) return 0;
  for (y = x->NameID; y; ++n, y = (struct zx_sa_NameID_s*)y->gg.g.n) ;
  return n;
}

/* FUNC(zx_sa_Subject_GET_NameID) */

struct zx_sa_NameID_s* zx_sa_Subject_GET_NameID(struct zx_sa_Subject_s* x, int n)
{
  struct zx_sa_NameID_s* y;
  if (!x) return 0;
  for (y = x->NameID; n>=0 && y; --n, y = (struct zx_sa_NameID_s*)y->gg.g.n) ;
  return y;
}

/* FUNC(zx_sa_Subject_POP_NameID) */

struct zx_sa_NameID_s* zx_sa_Subject_POP_NameID(struct zx_sa_Subject_s* x)
{
  struct zx_sa_NameID_s* y;
  if (!x) return 0;
  y = x->NameID;
  if (y)
    x->NameID = (struct zx_sa_NameID_s*)y->gg.g.n;
  return y;
}

/* FUNC(zx_sa_Subject_PUSH_NameID) */

void zx_sa_Subject_PUSH_NameID(struct zx_sa_Subject_s* x, struct zx_sa_NameID_s* z)
{
  if (!x || !z) return;
  z->gg.g.n = &x->NameID->gg.g;
  x->NameID = z;
}

/* FUNC(zx_sa_Subject_REV_NameID) */

void zx_sa_Subject_REV_NameID(struct zx_sa_Subject_s* x)
{
  struct zx_sa_NameID_s* nxt;
  struct zx_sa_NameID_s* y;
  if (!x) return;
  y = x->NameID;
  if (!y) return;
  x->NameID = 0;
  while (y) {
    nxt = (struct zx_sa_NameID_s*)y->gg.g.n;
    y->gg.g.n = &x->NameID->gg.g;
    x->NameID = y;
    y = nxt;
  }
}

/* FUNC(zx_sa_Subject_PUT_NameID) */

void zx_sa_Subject_PUT_NameID(struct zx_sa_Subject_s* x, int n, struct zx_sa_NameID_s* z)
{
  struct zx_sa_NameID_s* y;
  if (!x || !z) return;
  y = x->NameID;
  if (!y) return;
  switch (n) {
  case 0:
    z->gg.g.n = y->gg.g.n;
    x->NameID = z;
    return;
  default:
    for (; n > 1 && y->gg.g.n; --n, y = (struct zx_sa_NameID_s*)y->gg.g.n) ;
    if (!y->gg.g.n) return;
    z->gg.g.n = y->gg.g.n->n;
    y->gg.g.n = &z->gg.g;
  }
}

/* FUNC(zx_sa_Subject_ADD_NameID) */

void zx_sa_Subject_ADD_NameID(struct zx_sa_Subject_s* x, int n, struct zx_sa_NameID_s* z)
{
  struct zx_sa_NameID_s* y;
  if (!x || !z) return;
  switch (n) {
  case 0:
  add_to_start:
    z->gg.g.n = &x->NameID->gg.g;
    x->NameID = z;
    return;
  case -1:
    y = x->NameID;
    if (!y) goto add_to_start;
    for (; y->gg.g.n; y = (struct zx_sa_NameID_s*)y->gg.g.n) ;
    break;
  default:
    for (y = x->NameID; n > 1 && y; --n, y = (struct zx_sa_NameID_s*)y->gg.g.n) ;
    if (!y) return;
  }
  z->gg.g.n = y->gg.g.n;
  y->gg.g.n = &z->gg.g;
}

/* FUNC(zx_sa_Subject_DEL_NameID) */

void zx_sa_Subject_DEL_NameID(struct zx_sa_Subject_s* x, int n)
{
  struct zx_sa_NameID_s* y;
  if (!x) return;
  switch (n) {
  case 0:
    x->NameID = (struct zx_sa_NameID_s*)x->NameID->gg.g.n;
    return;
  case -1:
    y = (struct zx_sa_NameID_s*)x->NameID;
    if (!y) return;
    for (; y->gg.g.n; y = (struct zx_sa_NameID_s*)y->gg.g.n) ;
    break;
  default:
    for (y = x->NameID; n > 1 && y->gg.g.n; --n, y = (struct zx_sa_NameID_s*)y->gg.g.n) ;
    if (!y->gg.g.n) return;
  }
  y->gg.g.n = y->gg.g.n->n;
}

#endif



#ifdef ZX_ENA_GETPUT

/* FUNC(zx_sa_Subject_NUM_EncryptedID) */

int zx_sa_Subject_NUM_EncryptedID(struct zx_sa_Subject_s* x)
{
  struct zx_sa_EncryptedID_s* y;
  int n = 0;
  if (!x) return 0;
  for (y = x->EncryptedID; y; ++n, y = (struct zx_sa_EncryptedID_s*)y->gg.g.n) ;
  return n;
}

/* FUNC(zx_sa_Subject_GET_EncryptedID) */

struct zx_sa_EncryptedID_s* zx_sa_Subject_GET_EncryptedID(struct zx_sa_Subject_s* x, int n)
{
  struct zx_sa_EncryptedID_s* y;
  if (!x) return 0;
  for (y = x->EncryptedID; n>=0 && y; --n, y = (struct zx_sa_EncryptedID_s*)y->gg.g.n) ;
  return y;
}

/* FUNC(zx_sa_Subject_POP_EncryptedID) */

struct zx_sa_EncryptedID_s* zx_sa_Subject_POP_EncryptedID(struct zx_sa_Subject_s* x)
{
  struct zx_sa_EncryptedID_s* y;
  if (!x) return 0;
  y = x->EncryptedID;
  if (y)
    x->EncryptedID = (struct zx_sa_EncryptedID_s*)y->gg.g.n;
  return y;
}

/* FUNC(zx_sa_Subject_PUSH_EncryptedID) */

void zx_sa_Subject_PUSH_EncryptedID(struct zx_sa_Subject_s* x, struct zx_sa_EncryptedID_s* z)
{
  if (!x || !z) return;
  z->gg.g.n = &x->EncryptedID->gg.g;
  x->EncryptedID = z;
}

/* FUNC(zx_sa_Subject_REV_EncryptedID) */

void zx_sa_Subject_REV_EncryptedID(struct zx_sa_Subject_s* x)
{
  struct zx_sa_EncryptedID_s* nxt;
  struct zx_sa_EncryptedID_s* y;
  if (!x) return;
  y = x->EncryptedID;
  if (!y) return;
  x->EncryptedID = 0;
  while (y) {
    nxt = (struct zx_sa_EncryptedID_s*)y->gg.g.n;
    y->gg.g.n = &x->EncryptedID->gg.g;
    x->EncryptedID = y;
    y = nxt;
  }
}

/* FUNC(zx_sa_Subject_PUT_EncryptedID) */

void zx_sa_Subject_PUT_EncryptedID(struct zx_sa_Subject_s* x, int n, struct zx_sa_EncryptedID_s* z)
{
  struct zx_sa_EncryptedID_s* y;
  if (!x || !z) return;
  y = x->EncryptedID;
  if (!y) return;
  switch (n) {
  case 0:
    z->gg.g.n = y->gg.g.n;
    x->EncryptedID = z;
    return;
  default:
    for (; n > 1 && y->gg.g.n; --n, y = (struct zx_sa_EncryptedID_s*)y->gg.g.n) ;
    if (!y->gg.g.n) return;
    z->gg.g.n = y->gg.g.n->n;
    y->gg.g.n = &z->gg.g;
  }
}

/* FUNC(zx_sa_Subject_ADD_EncryptedID) */

void zx_sa_Subject_ADD_EncryptedID(struct zx_sa_Subject_s* x, int n, struct zx_sa_EncryptedID_s* z)
{
  struct zx_sa_EncryptedID_s* y;
  if (!x || !z) return;
  switch (n) {
  case 0:
  add_to_start:
    z->gg.g.n = &x->EncryptedID->gg.g;
    x->EncryptedID = z;
    return;
  case -1:
    y = x->EncryptedID;
    if (!y) goto add_to_start;
    for (; y->gg.g.n; y = (struct zx_sa_EncryptedID_s*)y->gg.g.n) ;
    break;
  default:
    for (y = x->EncryptedID; n > 1 && y; --n, y = (struct zx_sa_EncryptedID_s*)y->gg.g.n) ;
    if (!y) return;
  }
  z->gg.g.n = y->gg.g.n;
  y->gg.g.n = &z->gg.g;
}

/* FUNC(zx_sa_Subject_DEL_EncryptedID) */

void zx_sa_Subject_DEL_EncryptedID(struct zx_sa_Subject_s* x, int n)
{
  struct zx_sa_EncryptedID_s* y;
  if (!x) return;
  switch (n) {
  case 0:
    x->EncryptedID = (struct zx_sa_EncryptedID_s*)x->EncryptedID->gg.g.n;
    return;
  case -1:
    y = (struct zx_sa_EncryptedID_s*)x->EncryptedID;
    if (!y) return;
    for (; y->gg.g.n; y = (struct zx_sa_EncryptedID_s*)y->gg.g.n) ;
    break;
  default:
    for (y = x->EncryptedID; n > 1 && y->gg.g.n; --n, y = (struct zx_sa_EncryptedID_s*)y->gg.g.n) ;
    if (!y->gg.g.n) return;
  }
  y->gg.g.n = y->gg.g.n->n;
}

#endif



#ifdef ZX_ENA_GETPUT

/* FUNC(zx_sa_Subject_NUM_SubjectConfirmation) */

int zx_sa_Subject_NUM_SubjectConfirmation(struct zx_sa_Subject_s* x)
{
  struct zx_sa_SubjectConfirmation_s* y;
  int n = 0;
  if (!x) return 0;
  for (y = x->SubjectConfirmation; y; ++n, y = (struct zx_sa_SubjectConfirmation_s*)y->gg.g.n) ;
  return n;
}

/* FUNC(zx_sa_Subject_GET_SubjectConfirmation) */

struct zx_sa_SubjectConfirmation_s* zx_sa_Subject_GET_SubjectConfirmation(struct zx_sa_Subject_s* x, int n)
{
  struct zx_sa_SubjectConfirmation_s* y;
  if (!x) return 0;
  for (y = x->SubjectConfirmation; n>=0 && y; --n, y = (struct zx_sa_SubjectConfirmation_s*)y->gg.g.n) ;
  return y;
}

/* FUNC(zx_sa_Subject_POP_SubjectConfirmation) */

struct zx_sa_SubjectConfirmation_s* zx_sa_Subject_POP_SubjectConfirmation(struct zx_sa_Subject_s* x)
{
  struct zx_sa_SubjectConfirmation_s* y;
  if (!x) return 0;
  y = x->SubjectConfirmation;
  if (y)
    x->SubjectConfirmation = (struct zx_sa_SubjectConfirmation_s*)y->gg.g.n;
  return y;
}

/* FUNC(zx_sa_Subject_PUSH_SubjectConfirmation) */

void zx_sa_Subject_PUSH_SubjectConfirmation(struct zx_sa_Subject_s* x, struct zx_sa_SubjectConfirmation_s* z)
{
  if (!x || !z) return;
  z->gg.g.n = &x->SubjectConfirmation->gg.g;
  x->SubjectConfirmation = z;
}

/* FUNC(zx_sa_Subject_REV_SubjectConfirmation) */

void zx_sa_Subject_REV_SubjectConfirmation(struct zx_sa_Subject_s* x)
{
  struct zx_sa_SubjectConfirmation_s* nxt;
  struct zx_sa_SubjectConfirmation_s* y;
  if (!x) return;
  y = x->SubjectConfirmation;
  if (!y) return;
  x->SubjectConfirmation = 0;
  while (y) {
    nxt = (struct zx_sa_SubjectConfirmation_s*)y->gg.g.n;
    y->gg.g.n = &x->SubjectConfirmation->gg.g;
    x->SubjectConfirmation = y;
    y = nxt;
  }
}

/* FUNC(zx_sa_Subject_PUT_SubjectConfirmation) */

void zx_sa_Subject_PUT_SubjectConfirmation(struct zx_sa_Subject_s* x, int n, struct zx_sa_SubjectConfirmation_s* z)
{
  struct zx_sa_SubjectConfirmation_s* y;
  if (!x || !z) return;
  y = x->SubjectConfirmation;
  if (!y) return;
  switch (n) {
  case 0:
    z->gg.g.n = y->gg.g.n;
    x->SubjectConfirmation = z;
    return;
  default:
    for (; n > 1 && y->gg.g.n; --n, y = (struct zx_sa_SubjectConfirmation_s*)y->gg.g.n) ;
    if (!y->gg.g.n) return;
    z->gg.g.n = y->gg.g.n->n;
    y->gg.g.n = &z->gg.g;
  }
}

/* FUNC(zx_sa_Subject_ADD_SubjectConfirmation) */

void zx_sa_Subject_ADD_SubjectConfirmation(struct zx_sa_Subject_s* x, int n, struct zx_sa_SubjectConfirmation_s* z)
{
  struct zx_sa_SubjectConfirmation_s* y;
  if (!x || !z) return;
  switch (n) {
  case 0:
  add_to_start:
    z->gg.g.n = &x->SubjectConfirmation->gg.g;
    x->SubjectConfirmation = z;
    return;
  case -1:
    y = x->SubjectConfirmation;
    if (!y) goto add_to_start;
    for (; y->gg.g.n; y = (struct zx_sa_SubjectConfirmation_s*)y->gg.g.n) ;
    break;
  default:
    for (y = x->SubjectConfirmation; n > 1 && y; --n, y = (struct zx_sa_SubjectConfirmation_s*)y->gg.g.n) ;
    if (!y) return;
  }
  z->gg.g.n = y->gg.g.n;
  y->gg.g.n = &z->gg.g;
}

/* FUNC(zx_sa_Subject_DEL_SubjectConfirmation) */

void zx_sa_Subject_DEL_SubjectConfirmation(struct zx_sa_Subject_s* x, int n)
{
  struct zx_sa_SubjectConfirmation_s* y;
  if (!x) return;
  switch (n) {
  case 0:
    x->SubjectConfirmation = (struct zx_sa_SubjectConfirmation_s*)x->SubjectConfirmation->gg.g.n;
    return;
  case -1:
    y = (struct zx_sa_SubjectConfirmation_s*)x->SubjectConfirmation;
    if (!y) return;
    for (; y->gg.g.n; y = (struct zx_sa_SubjectConfirmation_s*)y->gg.g.n) ;
    break;
  default:
    for (y = x->SubjectConfirmation; n > 1 && y->gg.g.n; --n, y = (struct zx_sa_SubjectConfirmation_s*)y->gg.g.n) ;
    if (!y->gg.g.n) return;
  }
  y->gg.g.n = y->gg.g.n->n;
}

#endif








#ifdef ZX_ENA_GETPUT

/* FUNC(zx_sa_SubjectConfirmation_NUM_BaseID) */

int zx_sa_SubjectConfirmation_NUM_BaseID(struct zx_sa_SubjectConfirmation_s* x)
{
  struct zx_sa_BaseID_s* y;
  int n = 0;
  if (!x) return 0;
  for (y = x->BaseID; y; ++n, y = (struct zx_sa_BaseID_s*)y->gg.g.n) ;
  return n;
}

/* FUNC(zx_sa_SubjectConfirmation_GET_BaseID) */

struct zx_sa_BaseID_s* zx_sa_SubjectConfirmation_GET_BaseID(struct zx_sa_SubjectConfirmation_s* x, int n)
{
  struct zx_sa_BaseID_s* y;
  if (!x) return 0;
  for (y = x->BaseID; n>=0 && y; --n, y = (struct zx_sa_BaseID_s*)y->gg.g.n) ;
  return y;
}

/* FUNC(zx_sa_SubjectConfirmation_POP_BaseID) */

struct zx_sa_BaseID_s* zx_sa_SubjectConfirmation_POP_BaseID(struct zx_sa_SubjectConfirmation_s* x)
{
  struct zx_sa_BaseID_s* y;
  if (!x) return 0;
  y = x->BaseID;
  if (y)
    x->BaseID = (struct zx_sa_BaseID_s*)y->gg.g.n;
  return y;
}

/* FUNC(zx_sa_SubjectConfirmation_PUSH_BaseID) */

void zx_sa_SubjectConfirmation_PUSH_BaseID(struct zx_sa_SubjectConfirmation_s* x, struct zx_sa_BaseID_s* z)
{
  if (!x || !z) return;
  z->gg.g.n = &x->BaseID->gg.g;
  x->BaseID = z;
}

/* FUNC(zx_sa_SubjectConfirmation_REV_BaseID) */

void zx_sa_SubjectConfirmation_REV_BaseID(struct zx_sa_SubjectConfirmation_s* x)
{
  struct zx_sa_BaseID_s* nxt;
  struct zx_sa_BaseID_s* y;
  if (!x) return;
  y = x->BaseID;
  if (!y) return;
  x->BaseID = 0;
  while (y) {
    nxt = (struct zx_sa_BaseID_s*)y->gg.g.n;
    y->gg.g.n = &x->BaseID->gg.g;
    x->BaseID = y;
    y = nxt;
  }
}

/* FUNC(zx_sa_SubjectConfirmation_PUT_BaseID) */

void zx_sa_SubjectConfirmation_PUT_BaseID(struct zx_sa_SubjectConfirmation_s* x, int n, struct zx_sa_BaseID_s* z)
{
  struct zx_sa_BaseID_s* y;
  if (!x || !z) return;
  y = x->BaseID;
  if (!y) return;
  switch (n) {
  case 0:
    z->gg.g.n = y->gg.g.n;
    x->BaseID = z;
    return;
  default:
    for (; n > 1 && y->gg.g.n; --n, y = (struct zx_sa_BaseID_s*)y->gg.g.n) ;
    if (!y->gg.g.n) return;
    z->gg.g.n = y->gg.g.n->n;
    y->gg.g.n = &z->gg.g;
  }
}

/* FUNC(zx_sa_SubjectConfirmation_ADD_BaseID) */

void zx_sa_SubjectConfirmation_ADD_BaseID(struct zx_sa_SubjectConfirmation_s* x, int n, struct zx_sa_BaseID_s* z)
{
  struct zx_sa_BaseID_s* y;
  if (!x || !z) return;
  switch (n) {
  case 0:
  add_to_start:
    z->gg.g.n = &x->BaseID->gg.g;
    x->BaseID = z;
    return;
  case -1:
    y = x->BaseID;
    if (!y) goto add_to_start;
    for (; y->gg.g.n; y = (struct zx_sa_BaseID_s*)y->gg.g.n) ;
    break;
  default:
    for (y = x->BaseID; n > 1 && y; --n, y = (struct zx_sa_BaseID_s*)y->gg.g.n) ;
    if (!y) return;
  }
  z->gg.g.n = y->gg.g.n;
  y->gg.g.n = &z->gg.g;
}

/* FUNC(zx_sa_SubjectConfirmation_DEL_BaseID) */

void zx_sa_SubjectConfirmation_DEL_BaseID(struct zx_sa_SubjectConfirmation_s* x, int n)
{
  struct zx_sa_BaseID_s* y;
  if (!x) return;
  switch (n) {
  case 0:
    x->BaseID = (struct zx_sa_BaseID_s*)x->BaseID->gg.g.n;
    return;
  case -1:
    y = (struct zx_sa_BaseID_s*)x->BaseID;
    if (!y) return;
    for (; y->gg.g.n; y = (struct zx_sa_BaseID_s*)y->gg.g.n) ;
    break;
  default:
    for (y = x->BaseID; n > 1 && y->gg.g.n; --n, y = (struct zx_sa_BaseID_s*)y->gg.g.n) ;
    if (!y->gg.g.n) return;
  }
  y->gg.g.n = y->gg.g.n->n;
}

#endif



#ifdef ZX_ENA_GETPUT

/* FUNC(zx_sa_SubjectConfirmation_NUM_NameID) */

int zx_sa_SubjectConfirmation_NUM_NameID(struct zx_sa_SubjectConfirmation_s* x)
{
  struct zx_sa_NameID_s* y;
  int n = 0;
  if (!x) return 0;
  for (y = x->NameID; y; ++n, y = (struct zx_sa_NameID_s*)y->gg.g.n) ;
  return n;
}

/* FUNC(zx_sa_SubjectConfirmation_GET_NameID) */

struct zx_sa_NameID_s* zx_sa_SubjectConfirmation_GET_NameID(struct zx_sa_SubjectConfirmation_s* x, int n)
{
  struct zx_sa_NameID_s* y;
  if (!x) return 0;
  for (y = x->NameID; n>=0 && y; --n, y = (struct zx_sa_NameID_s*)y->gg.g.n) ;
  return y;
}

/* FUNC(zx_sa_SubjectConfirmation_POP_NameID) */

struct zx_sa_NameID_s* zx_sa_SubjectConfirmation_POP_NameID(struct zx_sa_SubjectConfirmation_s* x)
{
  struct zx_sa_NameID_s* y;
  if (!x) return 0;
  y = x->NameID;
  if (y)
    x->NameID = (struct zx_sa_NameID_s*)y->gg.g.n;
  return y;
}

/* FUNC(zx_sa_SubjectConfirmation_PUSH_NameID) */

void zx_sa_SubjectConfirmation_PUSH_NameID(struct zx_sa_SubjectConfirmation_s* x, struct zx_sa_NameID_s* z)
{
  if (!x || !z) return;
  z->gg.g.n = &x->NameID->gg.g;
  x->NameID = z;
}

/* FUNC(zx_sa_SubjectConfirmation_REV_NameID) */

void zx_sa_SubjectConfirmation_REV_NameID(struct zx_sa_SubjectConfirmation_s* x)
{
  struct zx_sa_NameID_s* nxt;
  struct zx_sa_NameID_s* y;
  if (!x) return;
  y = x->NameID;
  if (!y) return;
  x->NameID = 0;
  while (y) {
    nxt = (struct zx_sa_NameID_s*)y->gg.g.n;
    y->gg.g.n = &x->NameID->gg.g;
    x->NameID = y;
    y = nxt;
  }
}

/* FUNC(zx_sa_SubjectConfirmation_PUT_NameID) */

void zx_sa_SubjectConfirmation_PUT_NameID(struct zx_sa_SubjectConfirmation_s* x, int n, struct zx_sa_NameID_s* z)
{
  struct zx_sa_NameID_s* y;
  if (!x || !z) return;
  y = x->NameID;
  if (!y) return;
  switch (n) {
  case 0:
    z->gg.g.n = y->gg.g.n;
    x->NameID = z;
    return;
  default:
    for (; n > 1 && y->gg.g.n; --n, y = (struct zx_sa_NameID_s*)y->gg.g.n) ;
    if (!y->gg.g.n) return;
    z->gg.g.n = y->gg.g.n->n;
    y->gg.g.n = &z->gg.g;
  }
}

/* FUNC(zx_sa_SubjectConfirmation_ADD_NameID) */

void zx_sa_SubjectConfirmation_ADD_NameID(struct zx_sa_SubjectConfirmation_s* x, int n, struct zx_sa_NameID_s* z)
{
  struct zx_sa_NameID_s* y;
  if (!x || !z) return;
  switch (n) {
  case 0:
  add_to_start:
    z->gg.g.n = &x->NameID->gg.g;
    x->NameID = z;
    return;
  case -1:
    y = x->NameID;
    if (!y) goto add_to_start;
    for (; y->gg.g.n; y = (struct zx_sa_NameID_s*)y->gg.g.n) ;
    break;
  default:
    for (y = x->NameID; n > 1 && y; --n, y = (struct zx_sa_NameID_s*)y->gg.g.n) ;
    if (!y) return;
  }
  z->gg.g.n = y->gg.g.n;
  y->gg.g.n = &z->gg.g;
}

/* FUNC(zx_sa_SubjectConfirmation_DEL_NameID) */

void zx_sa_SubjectConfirmation_DEL_NameID(struct zx_sa_SubjectConfirmation_s* x, int n)
{
  struct zx_sa_NameID_s* y;
  if (!x) return;
  switch (n) {
  case 0:
    x->NameID = (struct zx_sa_NameID_s*)x->NameID->gg.g.n;
    return;
  case -1:
    y = (struct zx_sa_NameID_s*)x->NameID;
    if (!y) return;
    for (; y->gg.g.n; y = (struct zx_sa_NameID_s*)y->gg.g.n) ;
    break;
  default:
    for (y = x->NameID; n > 1 && y->gg.g.n; --n, y = (struct zx_sa_NameID_s*)y->gg.g.n) ;
    if (!y->gg.g.n) return;
  }
  y->gg.g.n = y->gg.g.n->n;
}

#endif



#ifdef ZX_ENA_GETPUT

/* FUNC(zx_sa_SubjectConfirmation_NUM_EncryptedID) */

int zx_sa_SubjectConfirmation_NUM_EncryptedID(struct zx_sa_SubjectConfirmation_s* x)
{
  struct zx_sa_EncryptedID_s* y;
  int n = 0;
  if (!x) return 0;
  for (y = x->EncryptedID; y; ++n, y = (struct zx_sa_EncryptedID_s*)y->gg.g.n) ;
  return n;
}

/* FUNC(zx_sa_SubjectConfirmation_GET_EncryptedID) */

struct zx_sa_EncryptedID_s* zx_sa_SubjectConfirmation_GET_EncryptedID(struct zx_sa_SubjectConfirmation_s* x, int n)
{
  struct zx_sa_EncryptedID_s* y;
  if (!x) return 0;
  for (y = x->EncryptedID; n>=0 && y; --n, y = (struct zx_sa_EncryptedID_s*)y->gg.g.n) ;
  return y;
}

/* FUNC(zx_sa_SubjectConfirmation_POP_EncryptedID) */

struct zx_sa_EncryptedID_s* zx_sa_SubjectConfirmation_POP_EncryptedID(struct zx_sa_SubjectConfirmation_s* x)
{
  struct zx_sa_EncryptedID_s* y;
  if (!x) return 0;
  y = x->EncryptedID;
  if (y)
    x->EncryptedID = (struct zx_sa_EncryptedID_s*)y->gg.g.n;
  return y;
}

/* FUNC(zx_sa_SubjectConfirmation_PUSH_EncryptedID) */

void zx_sa_SubjectConfirmation_PUSH_EncryptedID(struct zx_sa_SubjectConfirmation_s* x, struct zx_sa_EncryptedID_s* z)
{
  if (!x || !z) return;
  z->gg.g.n = &x->EncryptedID->gg.g;
  x->EncryptedID = z;
}

/* FUNC(zx_sa_SubjectConfirmation_REV_EncryptedID) */

void zx_sa_SubjectConfirmation_REV_EncryptedID(struct zx_sa_SubjectConfirmation_s* x)
{
  struct zx_sa_EncryptedID_s* nxt;
  struct zx_sa_EncryptedID_s* y;
  if (!x) return;
  y = x->EncryptedID;
  if (!y) return;
  x->EncryptedID = 0;
  while (y) {
    nxt = (struct zx_sa_EncryptedID_s*)y->gg.g.n;
    y->gg.g.n = &x->EncryptedID->gg.g;
    x->EncryptedID = y;
    y = nxt;
  }
}

/* FUNC(zx_sa_SubjectConfirmation_PUT_EncryptedID) */

void zx_sa_SubjectConfirmation_PUT_EncryptedID(struct zx_sa_SubjectConfirmation_s* x, int n, struct zx_sa_EncryptedID_s* z)
{
  struct zx_sa_EncryptedID_s* y;
  if (!x || !z) return;
  y = x->EncryptedID;
  if (!y) return;
  switch (n) {
  case 0:
    z->gg.g.n = y->gg.g.n;
    x->EncryptedID = z;
    return;
  default:
    for (; n > 1 && y->gg.g.n; --n, y = (struct zx_sa_EncryptedID_s*)y->gg.g.n) ;
    if (!y->gg.g.n) return;
    z->gg.g.n = y->gg.g.n->n;
    y->gg.g.n = &z->gg.g;
  }
}

/* FUNC(zx_sa_SubjectConfirmation_ADD_EncryptedID) */

void zx_sa_SubjectConfirmation_ADD_EncryptedID(struct zx_sa_SubjectConfirmation_s* x, int n, struct zx_sa_EncryptedID_s* z)
{
  struct zx_sa_EncryptedID_s* y;
  if (!x || !z) return;
  switch (n) {
  case 0:
  add_to_start:
    z->gg.g.n = &x->EncryptedID->gg.g;
    x->EncryptedID = z;
    return;
  case -1:
    y = x->EncryptedID;
    if (!y) goto add_to_start;
    for (; y->gg.g.n; y = (struct zx_sa_EncryptedID_s*)y->gg.g.n) ;
    break;
  default:
    for (y = x->EncryptedID; n > 1 && y; --n, y = (struct zx_sa_EncryptedID_s*)y->gg.g.n) ;
    if (!y) return;
  }
  z->gg.g.n = y->gg.g.n;
  y->gg.g.n = &z->gg.g;
}

/* FUNC(zx_sa_SubjectConfirmation_DEL_EncryptedID) */

void zx_sa_SubjectConfirmation_DEL_EncryptedID(struct zx_sa_SubjectConfirmation_s* x, int n)
{
  struct zx_sa_EncryptedID_s* y;
  if (!x) return;
  switch (n) {
  case 0:
    x->EncryptedID = (struct zx_sa_EncryptedID_s*)x->EncryptedID->gg.g.n;
    return;
  case -1:
    y = (struct zx_sa_EncryptedID_s*)x->EncryptedID;
    if (!y) return;
    for (; y->gg.g.n; y = (struct zx_sa_EncryptedID_s*)y->gg.g.n) ;
    break;
  default:
    for (y = x->EncryptedID; n > 1 && y->gg.g.n; --n, y = (struct zx_sa_EncryptedID_s*)y->gg.g.n) ;
    if (!y->gg.g.n) return;
  }
  y->gg.g.n = y->gg.g.n->n;
}

#endif



#ifdef ZX_ENA_GETPUT

/* FUNC(zx_sa_SubjectConfirmation_NUM_SubjectConfirmationData) */

int zx_sa_SubjectConfirmation_NUM_SubjectConfirmationData(struct zx_sa_SubjectConfirmation_s* x)
{
  struct zx_sa_SubjectConfirmationData_s* y;
  int n = 0;
  if (!x) return 0;
  for (y = x->SubjectConfirmationData; y; ++n, y = (struct zx_sa_SubjectConfirmationData_s*)y->gg.g.n) ;
  return n;
}

/* FUNC(zx_sa_SubjectConfirmation_GET_SubjectConfirmationData) */

struct zx_sa_SubjectConfirmationData_s* zx_sa_SubjectConfirmation_GET_SubjectConfirmationData(struct zx_sa_SubjectConfirmation_s* x, int n)
{
  struct zx_sa_SubjectConfirmationData_s* y;
  if (!x) return 0;
  for (y = x->SubjectConfirmationData; n>=0 && y; --n, y = (struct zx_sa_SubjectConfirmationData_s*)y->gg.g.n) ;
  return y;
}

/* FUNC(zx_sa_SubjectConfirmation_POP_SubjectConfirmationData) */

struct zx_sa_SubjectConfirmationData_s* zx_sa_SubjectConfirmation_POP_SubjectConfirmationData(struct zx_sa_SubjectConfirmation_s* x)
{
  struct zx_sa_SubjectConfirmationData_s* y;
  if (!x) return 0;
  y = x->SubjectConfirmationData;
  if (y)
    x->SubjectConfirmationData = (struct zx_sa_SubjectConfirmationData_s*)y->gg.g.n;
  return y;
}

/* FUNC(zx_sa_SubjectConfirmation_PUSH_SubjectConfirmationData) */

void zx_sa_SubjectConfirmation_PUSH_SubjectConfirmationData(struct zx_sa_SubjectConfirmation_s* x, struct zx_sa_SubjectConfirmationData_s* z)
{
  if (!x || !z) return;
  z->gg.g.n = &x->SubjectConfirmationData->gg.g;
  x->SubjectConfirmationData = z;
}

/* FUNC(zx_sa_SubjectConfirmation_REV_SubjectConfirmationData) */

void zx_sa_SubjectConfirmation_REV_SubjectConfirmationData(struct zx_sa_SubjectConfirmation_s* x)
{
  struct zx_sa_SubjectConfirmationData_s* nxt;
  struct zx_sa_SubjectConfirmationData_s* y;
  if (!x) return;
  y = x->SubjectConfirmationData;
  if (!y) return;
  x->SubjectConfirmationData = 0;
  while (y) {
    nxt = (struct zx_sa_SubjectConfirmationData_s*)y->gg.g.n;
    y->gg.g.n = &x->SubjectConfirmationData->gg.g;
    x->SubjectConfirmationData = y;
    y = nxt;
  }
}

/* FUNC(zx_sa_SubjectConfirmation_PUT_SubjectConfirmationData) */

void zx_sa_SubjectConfirmation_PUT_SubjectConfirmationData(struct zx_sa_SubjectConfirmation_s* x, int n, struct zx_sa_SubjectConfirmationData_s* z)
{
  struct zx_sa_SubjectConfirmationData_s* y;
  if (!x || !z) return;
  y = x->SubjectConfirmationData;
  if (!y) return;
  switch (n) {
  case 0:
    z->gg.g.n = y->gg.g.n;
    x->SubjectConfirmationData = z;
    return;
  default:
    for (; n > 1 && y->gg.g.n; --n, y = (struct zx_sa_SubjectConfirmationData_s*)y->gg.g.n) ;
    if (!y->gg.g.n) return;
    z->gg.g.n = y->gg.g.n->n;
    y->gg.g.n = &z->gg.g;
  }
}

/* FUNC(zx_sa_SubjectConfirmation_ADD_SubjectConfirmationData) */

void zx_sa_SubjectConfirmation_ADD_SubjectConfirmationData(struct zx_sa_SubjectConfirmation_s* x, int n, struct zx_sa_SubjectConfirmationData_s* z)
{
  struct zx_sa_SubjectConfirmationData_s* y;
  if (!x || !z) return;
  switch (n) {
  case 0:
  add_to_start:
    z->gg.g.n = &x->SubjectConfirmationData->gg.g;
    x->SubjectConfirmationData = z;
    return;
  case -1:
    y = x->SubjectConfirmationData;
    if (!y) goto add_to_start;
    for (; y->gg.g.n; y = (struct zx_sa_SubjectConfirmationData_s*)y->gg.g.n) ;
    break;
  default:
    for (y = x->SubjectConfirmationData; n > 1 && y; --n, y = (struct zx_sa_SubjectConfirmationData_s*)y->gg.g.n) ;
    if (!y) return;
  }
  z->gg.g.n = y->gg.g.n;
  y->gg.g.n = &z->gg.g;
}

/* FUNC(zx_sa_SubjectConfirmation_DEL_SubjectConfirmationData) */

void zx_sa_SubjectConfirmation_DEL_SubjectConfirmationData(struct zx_sa_SubjectConfirmation_s* x, int n)
{
  struct zx_sa_SubjectConfirmationData_s* y;
  if (!x) return;
  switch (n) {
  case 0:
    x->SubjectConfirmationData = (struct zx_sa_SubjectConfirmationData_s*)x->SubjectConfirmationData->gg.g.n;
    return;
  case -1:
    y = (struct zx_sa_SubjectConfirmationData_s*)x->SubjectConfirmationData;
    if (!y) return;
    for (; y->gg.g.n; y = (struct zx_sa_SubjectConfirmationData_s*)y->gg.g.n) ;
    break;
  default:
    for (y = x->SubjectConfirmationData; n > 1 && y->gg.g.n; --n, y = (struct zx_sa_SubjectConfirmationData_s*)y->gg.g.n) ;
    if (!y->gg.g.n) return;
  }
  y->gg.g.n = y->gg.g.n->n;
}

#endif

/* FUNC(zx_sa_SubjectConfirmation_GET_Method) */
struct zx_str* zx_sa_SubjectConfirmation_GET_Method(struct zx_sa_SubjectConfirmation_s* x) { return x->Method; }
/* FUNC(zx_sa_SubjectConfirmation_PUT_Method) */
void zx_sa_SubjectConfirmation_PUT_Method(struct zx_sa_SubjectConfirmation_s* x, struct zx_str* y) { x->Method = y; }







#ifdef ZX_ENA_GETPUT

/* FUNC(zx_sa_SubjectConfirmationData_NUM_KeyInfo) */

int zx_sa_SubjectConfirmationData_NUM_KeyInfo(struct zx_sa_SubjectConfirmationData_s* x)
{
  struct zx_ds_KeyInfo_s* y;
  int n = 0;
  if (!x) return 0;
  for (y = x->KeyInfo; y; ++n, y = (struct zx_ds_KeyInfo_s*)y->gg.g.n) ;
  return n;
}

/* FUNC(zx_sa_SubjectConfirmationData_GET_KeyInfo) */

struct zx_ds_KeyInfo_s* zx_sa_SubjectConfirmationData_GET_KeyInfo(struct zx_sa_SubjectConfirmationData_s* x, int n)
{
  struct zx_ds_KeyInfo_s* y;
  if (!x) return 0;
  for (y = x->KeyInfo; n>=0 && y; --n, y = (struct zx_ds_KeyInfo_s*)y->gg.g.n) ;
  return y;
}

/* FUNC(zx_sa_SubjectConfirmationData_POP_KeyInfo) */

struct zx_ds_KeyInfo_s* zx_sa_SubjectConfirmationData_POP_KeyInfo(struct zx_sa_SubjectConfirmationData_s* x)
{
  struct zx_ds_KeyInfo_s* y;
  if (!x) return 0;
  y = x->KeyInfo;
  if (y)
    x->KeyInfo = (struct zx_ds_KeyInfo_s*)y->gg.g.n;
  return y;
}

/* FUNC(zx_sa_SubjectConfirmationData_PUSH_KeyInfo) */

void zx_sa_SubjectConfirmationData_PUSH_KeyInfo(struct zx_sa_SubjectConfirmationData_s* x, struct zx_ds_KeyInfo_s* z)
{
  if (!x || !z) return;
  z->gg.g.n = &x->KeyInfo->gg.g;
  x->KeyInfo = z;
}

/* FUNC(zx_sa_SubjectConfirmationData_REV_KeyInfo) */

void zx_sa_SubjectConfirmationData_REV_KeyInfo(struct zx_sa_SubjectConfirmationData_s* x)
{
  struct zx_ds_KeyInfo_s* nxt;
  struct zx_ds_KeyInfo_s* y;
  if (!x) return;
  y = x->KeyInfo;
  if (!y) return;
  x->KeyInfo = 0;
  while (y) {
    nxt = (struct zx_ds_KeyInfo_s*)y->gg.g.n;
    y->gg.g.n = &x->KeyInfo->gg.g;
    x->KeyInfo = y;
    y = nxt;
  }
}

/* FUNC(zx_sa_SubjectConfirmationData_PUT_KeyInfo) */

void zx_sa_SubjectConfirmationData_PUT_KeyInfo(struct zx_sa_SubjectConfirmationData_s* x, int n, struct zx_ds_KeyInfo_s* z)
{
  struct zx_ds_KeyInfo_s* y;
  if (!x || !z) return;
  y = x->KeyInfo;
  if (!y) return;
  switch (n) {
  case 0:
    z->gg.g.n = y->gg.g.n;
    x->KeyInfo = z;
    return;
  default:
    for (; n > 1 && y->gg.g.n; --n, y = (struct zx_ds_KeyInfo_s*)y->gg.g.n) ;
    if (!y->gg.g.n) return;
    z->gg.g.n = y->gg.g.n->n;
    y->gg.g.n = &z->gg.g;
  }
}

/* FUNC(zx_sa_SubjectConfirmationData_ADD_KeyInfo) */

void zx_sa_SubjectConfirmationData_ADD_KeyInfo(struct zx_sa_SubjectConfirmationData_s* x, int n, struct zx_ds_KeyInfo_s* z)
{
  struct zx_ds_KeyInfo_s* y;
  if (!x || !z) return;
  switch (n) {
  case 0:
  add_to_start:
    z->gg.g.n = &x->KeyInfo->gg.g;
    x->KeyInfo = z;
    return;
  case -1:
    y = x->KeyInfo;
    if (!y) goto add_to_start;
    for (; y->gg.g.n; y = (struct zx_ds_KeyInfo_s*)y->gg.g.n) ;
    break;
  default:
    for (y = x->KeyInfo; n > 1 && y; --n, y = (struct zx_ds_KeyInfo_s*)y->gg.g.n) ;
    if (!y) return;
  }
  z->gg.g.n = y->gg.g.n;
  y->gg.g.n = &z->gg.g;
}

/* FUNC(zx_sa_SubjectConfirmationData_DEL_KeyInfo) */

void zx_sa_SubjectConfirmationData_DEL_KeyInfo(struct zx_sa_SubjectConfirmationData_s* x, int n)
{
  struct zx_ds_KeyInfo_s* y;
  if (!x) return;
  switch (n) {
  case 0:
    x->KeyInfo = (struct zx_ds_KeyInfo_s*)x->KeyInfo->gg.g.n;
    return;
  case -1:
    y = (struct zx_ds_KeyInfo_s*)x->KeyInfo;
    if (!y) return;
    for (; y->gg.g.n; y = (struct zx_ds_KeyInfo_s*)y->gg.g.n) ;
    break;
  default:
    for (y = x->KeyInfo; n > 1 && y->gg.g.n; --n, y = (struct zx_ds_KeyInfo_s*)y->gg.g.n) ;
    if (!y->gg.g.n) return;
  }
  y->gg.g.n = y->gg.g.n->n;
}

#endif

/* FUNC(zx_sa_SubjectConfirmationData_GET_Address) */
struct zx_str* zx_sa_SubjectConfirmationData_GET_Address(struct zx_sa_SubjectConfirmationData_s* x) { return x->Address; }
/* FUNC(zx_sa_SubjectConfirmationData_PUT_Address) */
void zx_sa_SubjectConfirmationData_PUT_Address(struct zx_sa_SubjectConfirmationData_s* x, struct zx_str* y) { x->Address = y; }
/* FUNC(zx_sa_SubjectConfirmationData_GET_InResponseTo) */
struct zx_str* zx_sa_SubjectConfirmationData_GET_InResponseTo(struct zx_sa_SubjectConfirmationData_s* x) { return x->InResponseTo; }
/* FUNC(zx_sa_SubjectConfirmationData_PUT_InResponseTo) */
void zx_sa_SubjectConfirmationData_PUT_InResponseTo(struct zx_sa_SubjectConfirmationData_s* x, struct zx_str* y) { x->InResponseTo = y; }
/* FUNC(zx_sa_SubjectConfirmationData_GET_NotBefore) */
struct zx_str* zx_sa_SubjectConfirmationData_GET_NotBefore(struct zx_sa_SubjectConfirmationData_s* x) { return x->NotBefore; }
/* FUNC(zx_sa_SubjectConfirmationData_PUT_NotBefore) */
void zx_sa_SubjectConfirmationData_PUT_NotBefore(struct zx_sa_SubjectConfirmationData_s* x, struct zx_str* y) { x->NotBefore = y; }
/* FUNC(zx_sa_SubjectConfirmationData_GET_NotOnOrAfter) */
struct zx_str* zx_sa_SubjectConfirmationData_GET_NotOnOrAfter(struct zx_sa_SubjectConfirmationData_s* x) { return x->NotOnOrAfter; }
/* FUNC(zx_sa_SubjectConfirmationData_PUT_NotOnOrAfter) */
void zx_sa_SubjectConfirmationData_PUT_NotOnOrAfter(struct zx_sa_SubjectConfirmationData_s* x, struct zx_str* y) { x->NotOnOrAfter = y; }
/* FUNC(zx_sa_SubjectConfirmationData_GET_Recipient) */
struct zx_str* zx_sa_SubjectConfirmationData_GET_Recipient(struct zx_sa_SubjectConfirmationData_s* x) { return x->Recipient; }
/* FUNC(zx_sa_SubjectConfirmationData_PUT_Recipient) */
void zx_sa_SubjectConfirmationData_PUT_Recipient(struct zx_sa_SubjectConfirmationData_s* x, struct zx_str* y) { x->Recipient = y; }
/* FUNC(zx_sa_SubjectConfirmationData_GET_type) */
struct zx_str* zx_sa_SubjectConfirmationData_GET_type(struct zx_sa_SubjectConfirmationData_s* x) { return x->type; }
/* FUNC(zx_sa_SubjectConfirmationData_PUT_type) */
void zx_sa_SubjectConfirmationData_PUT_type(struct zx_sa_SubjectConfirmationData_s* x, struct zx_str* y) { x->type = y; }





/* FUNC(zx_sa_SubjectLocality_GET_Address) */
struct zx_str* zx_sa_SubjectLocality_GET_Address(struct zx_sa_SubjectLocality_s* x) { return x->Address; }
/* FUNC(zx_sa_SubjectLocality_PUT_Address) */
void zx_sa_SubjectLocality_PUT_Address(struct zx_sa_SubjectLocality_s* x, struct zx_str* y) { x->Address = y; }
/* FUNC(zx_sa_SubjectLocality_GET_DNSName) */
struct zx_str* zx_sa_SubjectLocality_GET_DNSName(struct zx_sa_SubjectLocality_s* x) { return x->DNSName; }
/* FUNC(zx_sa_SubjectLocality_PUT_DNSName) */
void zx_sa_SubjectLocality_PUT_DNSName(struct zx_sa_SubjectLocality_s* x, struct zx_str* y) { x->DNSName = y; }







#ifdef ZX_ENA_GETPUT

/* FUNC(zx_sa_TestElem_NUM_AttributeValue) */

int zx_sa_TestElem_NUM_AttributeValue(struct zx_sa_TestElem_s* x)
{
  struct zx_sa_AttributeValue_s* y;
  int n = 0;
  if (!x) return 0;
  for (y = x->AttributeValue; y; ++n, y = (struct zx_sa_AttributeValue_s*)y->gg.g.n) ;
  return n;
}

/* FUNC(zx_sa_TestElem_GET_AttributeValue) */

struct zx_sa_AttributeValue_s* zx_sa_TestElem_GET_AttributeValue(struct zx_sa_TestElem_s* x, int n)
{
  struct zx_sa_AttributeValue_s* y;
  if (!x) return 0;
  for (y = x->AttributeValue; n>=0 && y; --n, y = (struct zx_sa_AttributeValue_s*)y->gg.g.n) ;
  return y;
}

/* FUNC(zx_sa_TestElem_POP_AttributeValue) */

struct zx_sa_AttributeValue_s* zx_sa_TestElem_POP_AttributeValue(struct zx_sa_TestElem_s* x)
{
  struct zx_sa_AttributeValue_s* y;
  if (!x) return 0;
  y = x->AttributeValue;
  if (y)
    x->AttributeValue = (struct zx_sa_AttributeValue_s*)y->gg.g.n;
  return y;
}

/* FUNC(zx_sa_TestElem_PUSH_AttributeValue) */

void zx_sa_TestElem_PUSH_AttributeValue(struct zx_sa_TestElem_s* x, struct zx_sa_AttributeValue_s* z)
{
  if (!x || !z) return;
  z->gg.g.n = &x->AttributeValue->gg.g;
  x->AttributeValue = z;
}

/* FUNC(zx_sa_TestElem_REV_AttributeValue) */

void zx_sa_TestElem_REV_AttributeValue(struct zx_sa_TestElem_s* x)
{
  struct zx_sa_AttributeValue_s* nxt;
  struct zx_sa_AttributeValue_s* y;
  if (!x) return;
  y = x->AttributeValue;
  if (!y) return;
  x->AttributeValue = 0;
  while (y) {
    nxt = (struct zx_sa_AttributeValue_s*)y->gg.g.n;
    y->gg.g.n = &x->AttributeValue->gg.g;
    x->AttributeValue = y;
    y = nxt;
  }
}

/* FUNC(zx_sa_TestElem_PUT_AttributeValue) */

void zx_sa_TestElem_PUT_AttributeValue(struct zx_sa_TestElem_s* x, int n, struct zx_sa_AttributeValue_s* z)
{
  struct zx_sa_AttributeValue_s* y;
  if (!x || !z) return;
  y = x->AttributeValue;
  if (!y) return;
  switch (n) {
  case 0:
    z->gg.g.n = y->gg.g.n;
    x->AttributeValue = z;
    return;
  default:
    for (; n > 1 && y->gg.g.n; --n, y = (struct zx_sa_AttributeValue_s*)y->gg.g.n) ;
    if (!y->gg.g.n) return;
    z->gg.g.n = y->gg.g.n->n;
    y->gg.g.n = &z->gg.g;
  }
}

/* FUNC(zx_sa_TestElem_ADD_AttributeValue) */

void zx_sa_TestElem_ADD_AttributeValue(struct zx_sa_TestElem_s* x, int n, struct zx_sa_AttributeValue_s* z)
{
  struct zx_sa_AttributeValue_s* y;
  if (!x || !z) return;
  switch (n) {
  case 0:
  add_to_start:
    z->gg.g.n = &x->AttributeValue->gg.g;
    x->AttributeValue = z;
    return;
  case -1:
    y = x->AttributeValue;
    if (!y) goto add_to_start;
    for (; y->gg.g.n; y = (struct zx_sa_AttributeValue_s*)y->gg.g.n) ;
    break;
  default:
    for (y = x->AttributeValue; n > 1 && y; --n, y = (struct zx_sa_AttributeValue_s*)y->gg.g.n) ;
    if (!y) return;
  }
  z->gg.g.n = y->gg.g.n;
  y->gg.g.n = &z->gg.g;
}

/* FUNC(zx_sa_TestElem_DEL_AttributeValue) */

void zx_sa_TestElem_DEL_AttributeValue(struct zx_sa_TestElem_s* x, int n)
{
  struct zx_sa_AttributeValue_s* y;
  if (!x) return;
  switch (n) {
  case 0:
    x->AttributeValue = (struct zx_sa_AttributeValue_s*)x->AttributeValue->gg.g.n;
    return;
  case -1:
    y = (struct zx_sa_AttributeValue_s*)x->AttributeValue;
    if (!y) return;
    for (; y->gg.g.n; y = (struct zx_sa_AttributeValue_s*)y->gg.g.n) ;
    break;
  default:
    for (y = x->AttributeValue; n > 1 && y->gg.g.n; --n, y = (struct zx_sa_AttributeValue_s*)y->gg.g.n) ;
    if (!y->gg.g.n) return;
  }
  y->gg.g.n = y->gg.g.n->n;
}

#endif






/* EOF -- c/zx-sa-getput.c */
