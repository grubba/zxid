/* c/zx-sa11-getput.c - WARNING: This file was automatically generated. DO NOT EDIT!
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
#include "c/zx-sa11-data.h"

/* FUNC(zx_sa11_Action_GET_Namespace) */
struct zx_str* zx_sa11_Action_GET_Namespace(struct zx_sa11_Action_s* x) { return x->Namespace; }
/* FUNC(zx_sa11_Action_PUT_Namespace) */
void zx_sa11_Action_PUT_Namespace(struct zx_sa11_Action_s* x, struct zx_str* y) { x->Namespace = y; }







#ifdef ZX_ENA_GETPUT

/* FUNC(zx_sa11_Advice_NUM_AssertionIDReference) */

int zx_sa11_Advice_NUM_AssertionIDReference(struct zx_sa11_Advice_s* x)
{
  struct zx_elem_s* y;
  int n = 0;
  if (!x) return 0;
  for (y = x->AssertionIDReference; y; ++n, y = (struct zx_elem_s*)y->g.n) ;
  return n;
}

/* FUNC(zx_sa11_Advice_GET_AssertionIDReference) */

struct zx_elem_s* zx_sa11_Advice_GET_AssertionIDReference(struct zx_sa11_Advice_s* x, int n)
{
  struct zx_elem_s* y;
  if (!x) return 0;
  for (y = x->AssertionIDReference; n>=0 && y; --n, y = (struct zx_elem_s*)y->g.n) ;
  return y;
}

/* FUNC(zx_sa11_Advice_POP_AssertionIDReference) */

struct zx_elem_s* zx_sa11_Advice_POP_AssertionIDReference(struct zx_sa11_Advice_s* x)
{
  struct zx_elem_s* y;
  if (!x) return 0;
  y = x->AssertionIDReference;
  if (y)
    x->AssertionIDReference = (struct zx_elem_s*)y->g.n;
  return y;
}

/* FUNC(zx_sa11_Advice_PUSH_AssertionIDReference) */

void zx_sa11_Advice_PUSH_AssertionIDReference(struct zx_sa11_Advice_s* x, struct zx_elem_s* z)
{
  if (!x || !z) return;
  z->g.n = &x->AssertionIDReference->g;
  x->AssertionIDReference = z;
}

/* FUNC(zx_sa11_Advice_REV_AssertionIDReference) */

void zx_sa11_Advice_REV_AssertionIDReference(struct zx_sa11_Advice_s* x)
{
  struct zx_elem_s* nxt;
  struct zx_elem_s* y;
  if (!x) return;
  y = x->AssertionIDReference;
  if (!y) return;
  x->AssertionIDReference = 0;
  while (y) {
    nxt = (struct zx_elem_s*)y->g.n;
    y->g.n = &x->AssertionIDReference->g;
    x->AssertionIDReference = y;
    y = nxt;
  }
}

/* FUNC(zx_sa11_Advice_PUT_AssertionIDReference) */

void zx_sa11_Advice_PUT_AssertionIDReference(struct zx_sa11_Advice_s* x, int n, struct zx_elem_s* z)
{
  struct zx_elem_s* y;
  if (!x || !z) return;
  y = x->AssertionIDReference;
  if (!y) return;
  switch (n) {
  case 0:
    z->g.n = y->g.n;
    x->AssertionIDReference = z;
    return;
  default:
    for (; n > 1 && y->g.n; --n, y = (struct zx_elem_s*)y->g.n) ;
    if (!y->g.n) return;
    z->g.n = y->g.n->n;
    y->g.n = &z->g;
  }
}

/* FUNC(zx_sa11_Advice_ADD_AssertionIDReference) */

void zx_sa11_Advice_ADD_AssertionIDReference(struct zx_sa11_Advice_s* x, int n, struct zx_elem_s* z)
{
  struct zx_elem_s* y;
  if (!x || !z) return;
  switch (n) {
  case 0:
  add_to_start:
    z->g.n = &x->AssertionIDReference->g;
    x->AssertionIDReference = z;
    return;
  case -1:
    y = x->AssertionIDReference;
    if (!y) goto add_to_start;
    for (; y->g.n; y = (struct zx_elem_s*)y->g.n) ;
    break;
  default:
    for (y = x->AssertionIDReference; n > 1 && y; --n, y = (struct zx_elem_s*)y->g.n) ;
    if (!y) return;
  }
  z->g.n = y->g.n;
  y->g.n = &z->g;
}

/* FUNC(zx_sa11_Advice_DEL_AssertionIDReference) */

void zx_sa11_Advice_DEL_AssertionIDReference(struct zx_sa11_Advice_s* x, int n)
{
  struct zx_elem_s* y;
  if (!x) return;
  switch (n) {
  case 0:
    x->AssertionIDReference = (struct zx_elem_s*)x->AssertionIDReference->g.n;
    return;
  case -1:
    y = (struct zx_elem_s*)x->AssertionIDReference;
    if (!y) return;
    for (; y->g.n; y = (struct zx_elem_s*)y->g.n) ;
    break;
  default:
    for (y = x->AssertionIDReference; n > 1 && y->g.n; --n, y = (struct zx_elem_s*)y->g.n) ;
    if (!y->g.n) return;
  }
  y->g.n = y->g.n->n;
}

#endif



#ifdef ZX_ENA_GETPUT

/* FUNC(zx_sa11_Advice_NUM_Assertion) */

int zx_sa11_Advice_NUM_Assertion(struct zx_sa11_Advice_s* x)
{
  struct zx_sa11_Assertion_s* y;
  int n = 0;
  if (!x) return 0;
  for (y = x->Assertion; y; ++n, y = (struct zx_sa11_Assertion_s*)y->gg.g.n) ;
  return n;
}

/* FUNC(zx_sa11_Advice_GET_Assertion) */

struct zx_sa11_Assertion_s* zx_sa11_Advice_GET_Assertion(struct zx_sa11_Advice_s* x, int n)
{
  struct zx_sa11_Assertion_s* y;
  if (!x) return 0;
  for (y = x->Assertion; n>=0 && y; --n, y = (struct zx_sa11_Assertion_s*)y->gg.g.n) ;
  return y;
}

/* FUNC(zx_sa11_Advice_POP_Assertion) */

struct zx_sa11_Assertion_s* zx_sa11_Advice_POP_Assertion(struct zx_sa11_Advice_s* x)
{
  struct zx_sa11_Assertion_s* y;
  if (!x) return 0;
  y = x->Assertion;
  if (y)
    x->Assertion = (struct zx_sa11_Assertion_s*)y->gg.g.n;
  return y;
}

/* FUNC(zx_sa11_Advice_PUSH_Assertion) */

void zx_sa11_Advice_PUSH_Assertion(struct zx_sa11_Advice_s* x, struct zx_sa11_Assertion_s* z)
{
  if (!x || !z) return;
  z->gg.g.n = &x->Assertion->gg.g;
  x->Assertion = z;
}

/* FUNC(zx_sa11_Advice_REV_Assertion) */

void zx_sa11_Advice_REV_Assertion(struct zx_sa11_Advice_s* x)
{
  struct zx_sa11_Assertion_s* nxt;
  struct zx_sa11_Assertion_s* y;
  if (!x) return;
  y = x->Assertion;
  if (!y) return;
  x->Assertion = 0;
  while (y) {
    nxt = (struct zx_sa11_Assertion_s*)y->gg.g.n;
    y->gg.g.n = &x->Assertion->gg.g;
    x->Assertion = y;
    y = nxt;
  }
}

/* FUNC(zx_sa11_Advice_PUT_Assertion) */

void zx_sa11_Advice_PUT_Assertion(struct zx_sa11_Advice_s* x, int n, struct zx_sa11_Assertion_s* z)
{
  struct zx_sa11_Assertion_s* y;
  if (!x || !z) return;
  y = x->Assertion;
  if (!y) return;
  switch (n) {
  case 0:
    z->gg.g.n = y->gg.g.n;
    x->Assertion = z;
    return;
  default:
    for (; n > 1 && y->gg.g.n; --n, y = (struct zx_sa11_Assertion_s*)y->gg.g.n) ;
    if (!y->gg.g.n) return;
    z->gg.g.n = y->gg.g.n->n;
    y->gg.g.n = &z->gg.g;
  }
}

/* FUNC(zx_sa11_Advice_ADD_Assertion) */

void zx_sa11_Advice_ADD_Assertion(struct zx_sa11_Advice_s* x, int n, struct zx_sa11_Assertion_s* z)
{
  struct zx_sa11_Assertion_s* y;
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
    for (; y->gg.g.n; y = (struct zx_sa11_Assertion_s*)y->gg.g.n) ;
    break;
  default:
    for (y = x->Assertion; n > 1 && y; --n, y = (struct zx_sa11_Assertion_s*)y->gg.g.n) ;
    if (!y) return;
  }
  z->gg.g.n = y->gg.g.n;
  y->gg.g.n = &z->gg.g;
}

/* FUNC(zx_sa11_Advice_DEL_Assertion) */

void zx_sa11_Advice_DEL_Assertion(struct zx_sa11_Advice_s* x, int n)
{
  struct zx_sa11_Assertion_s* y;
  if (!x) return;
  switch (n) {
  case 0:
    x->Assertion = (struct zx_sa11_Assertion_s*)x->Assertion->gg.g.n;
    return;
  case -1:
    y = (struct zx_sa11_Assertion_s*)x->Assertion;
    if (!y) return;
    for (; y->gg.g.n; y = (struct zx_sa11_Assertion_s*)y->gg.g.n) ;
    break;
  default:
    for (y = x->Assertion; n > 1 && y->gg.g.n; --n, y = (struct zx_sa11_Assertion_s*)y->gg.g.n) ;
    if (!y->gg.g.n) return;
  }
  y->gg.g.n = y->gg.g.n->n;
}

#endif



#ifdef ZX_ENA_GETPUT

/* FUNC(zx_sa11_Advice_NUM_ff12_Assertion) */

int zx_sa11_Advice_NUM_ff12_Assertion(struct zx_sa11_Advice_s* x)
{
  struct zx_ff12_Assertion_s* y;
  int n = 0;
  if (!x) return 0;
  for (y = x->ff12_Assertion; y; ++n, y = (struct zx_ff12_Assertion_s*)y->gg.g.n) ;
  return n;
}

/* FUNC(zx_sa11_Advice_GET_ff12_Assertion) */

struct zx_ff12_Assertion_s* zx_sa11_Advice_GET_ff12_Assertion(struct zx_sa11_Advice_s* x, int n)
{
  struct zx_ff12_Assertion_s* y;
  if (!x) return 0;
  for (y = x->ff12_Assertion; n>=0 && y; --n, y = (struct zx_ff12_Assertion_s*)y->gg.g.n) ;
  return y;
}

/* FUNC(zx_sa11_Advice_POP_ff12_Assertion) */

struct zx_ff12_Assertion_s* zx_sa11_Advice_POP_ff12_Assertion(struct zx_sa11_Advice_s* x)
{
  struct zx_ff12_Assertion_s* y;
  if (!x) return 0;
  y = x->ff12_Assertion;
  if (y)
    x->ff12_Assertion = (struct zx_ff12_Assertion_s*)y->gg.g.n;
  return y;
}

/* FUNC(zx_sa11_Advice_PUSH_ff12_Assertion) */

void zx_sa11_Advice_PUSH_ff12_Assertion(struct zx_sa11_Advice_s* x, struct zx_ff12_Assertion_s* z)
{
  if (!x || !z) return;
  z->gg.g.n = &x->ff12_Assertion->gg.g;
  x->ff12_Assertion = z;
}

/* FUNC(zx_sa11_Advice_REV_ff12_Assertion) */

void zx_sa11_Advice_REV_ff12_Assertion(struct zx_sa11_Advice_s* x)
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

/* FUNC(zx_sa11_Advice_PUT_ff12_Assertion) */

void zx_sa11_Advice_PUT_ff12_Assertion(struct zx_sa11_Advice_s* x, int n, struct zx_ff12_Assertion_s* z)
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

/* FUNC(zx_sa11_Advice_ADD_ff12_Assertion) */

void zx_sa11_Advice_ADD_ff12_Assertion(struct zx_sa11_Advice_s* x, int n, struct zx_ff12_Assertion_s* z)
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

/* FUNC(zx_sa11_Advice_DEL_ff12_Assertion) */

void zx_sa11_Advice_DEL_ff12_Assertion(struct zx_sa11_Advice_s* x, int n)
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

/* FUNC(zx_sa11_Advice_NUM_sa_Assertion) */

int zx_sa11_Advice_NUM_sa_Assertion(struct zx_sa11_Advice_s* x)
{
  struct zx_sa_Assertion_s* y;
  int n = 0;
  if (!x) return 0;
  for (y = x->sa_Assertion; y; ++n, y = (struct zx_sa_Assertion_s*)y->gg.g.n) ;
  return n;
}

/* FUNC(zx_sa11_Advice_GET_sa_Assertion) */

struct zx_sa_Assertion_s* zx_sa11_Advice_GET_sa_Assertion(struct zx_sa11_Advice_s* x, int n)
{
  struct zx_sa_Assertion_s* y;
  if (!x) return 0;
  for (y = x->sa_Assertion; n>=0 && y; --n, y = (struct zx_sa_Assertion_s*)y->gg.g.n) ;
  return y;
}

/* FUNC(zx_sa11_Advice_POP_sa_Assertion) */

struct zx_sa_Assertion_s* zx_sa11_Advice_POP_sa_Assertion(struct zx_sa11_Advice_s* x)
{
  struct zx_sa_Assertion_s* y;
  if (!x) return 0;
  y = x->sa_Assertion;
  if (y)
    x->sa_Assertion = (struct zx_sa_Assertion_s*)y->gg.g.n;
  return y;
}

/* FUNC(zx_sa11_Advice_PUSH_sa_Assertion) */

void zx_sa11_Advice_PUSH_sa_Assertion(struct zx_sa11_Advice_s* x, struct zx_sa_Assertion_s* z)
{
  if (!x || !z) return;
  z->gg.g.n = &x->sa_Assertion->gg.g;
  x->sa_Assertion = z;
}

/* FUNC(zx_sa11_Advice_REV_sa_Assertion) */

void zx_sa11_Advice_REV_sa_Assertion(struct zx_sa11_Advice_s* x)
{
  struct zx_sa_Assertion_s* nxt;
  struct zx_sa_Assertion_s* y;
  if (!x) return;
  y = x->sa_Assertion;
  if (!y) return;
  x->sa_Assertion = 0;
  while (y) {
    nxt = (struct zx_sa_Assertion_s*)y->gg.g.n;
    y->gg.g.n = &x->sa_Assertion->gg.g;
    x->sa_Assertion = y;
    y = nxt;
  }
}

/* FUNC(zx_sa11_Advice_PUT_sa_Assertion) */

void zx_sa11_Advice_PUT_sa_Assertion(struct zx_sa11_Advice_s* x, int n, struct zx_sa_Assertion_s* z)
{
  struct zx_sa_Assertion_s* y;
  if (!x || !z) return;
  y = x->sa_Assertion;
  if (!y) return;
  switch (n) {
  case 0:
    z->gg.g.n = y->gg.g.n;
    x->sa_Assertion = z;
    return;
  default:
    for (; n > 1 && y->gg.g.n; --n, y = (struct zx_sa_Assertion_s*)y->gg.g.n) ;
    if (!y->gg.g.n) return;
    z->gg.g.n = y->gg.g.n->n;
    y->gg.g.n = &z->gg.g;
  }
}

/* FUNC(zx_sa11_Advice_ADD_sa_Assertion) */

void zx_sa11_Advice_ADD_sa_Assertion(struct zx_sa11_Advice_s* x, int n, struct zx_sa_Assertion_s* z)
{
  struct zx_sa_Assertion_s* y;
  if (!x || !z) return;
  switch (n) {
  case 0:
  add_to_start:
    z->gg.g.n = &x->sa_Assertion->gg.g;
    x->sa_Assertion = z;
    return;
  case -1:
    y = x->sa_Assertion;
    if (!y) goto add_to_start;
    for (; y->gg.g.n; y = (struct zx_sa_Assertion_s*)y->gg.g.n) ;
    break;
  default:
    for (y = x->sa_Assertion; n > 1 && y; --n, y = (struct zx_sa_Assertion_s*)y->gg.g.n) ;
    if (!y) return;
  }
  z->gg.g.n = y->gg.g.n;
  y->gg.g.n = &z->gg.g;
}

/* FUNC(zx_sa11_Advice_DEL_sa_Assertion) */

void zx_sa11_Advice_DEL_sa_Assertion(struct zx_sa11_Advice_s* x, int n)
{
  struct zx_sa_Assertion_s* y;
  if (!x) return;
  switch (n) {
  case 0:
    x->sa_Assertion = (struct zx_sa_Assertion_s*)x->sa_Assertion->gg.g.n;
    return;
  case -1:
    y = (struct zx_sa_Assertion_s*)x->sa_Assertion;
    if (!y) return;
    for (; y->gg.g.n; y = (struct zx_sa_Assertion_s*)y->gg.g.n) ;
    break;
  default:
    for (y = x->sa_Assertion; n > 1 && y->gg.g.n; --n, y = (struct zx_sa_Assertion_s*)y->gg.g.n) ;
    if (!y->gg.g.n) return;
  }
  y->gg.g.n = y->gg.g.n->n;
}

#endif








#ifdef ZX_ENA_GETPUT

/* FUNC(zx_sa11_Assertion_NUM_Conditions) */

int zx_sa11_Assertion_NUM_Conditions(struct zx_sa11_Assertion_s* x)
{
  struct zx_sa11_Conditions_s* y;
  int n = 0;
  if (!x) return 0;
  for (y = x->Conditions; y; ++n, y = (struct zx_sa11_Conditions_s*)y->gg.g.n) ;
  return n;
}

/* FUNC(zx_sa11_Assertion_GET_Conditions) */

struct zx_sa11_Conditions_s* zx_sa11_Assertion_GET_Conditions(struct zx_sa11_Assertion_s* x, int n)
{
  struct zx_sa11_Conditions_s* y;
  if (!x) return 0;
  for (y = x->Conditions; n>=0 && y; --n, y = (struct zx_sa11_Conditions_s*)y->gg.g.n) ;
  return y;
}

/* FUNC(zx_sa11_Assertion_POP_Conditions) */

struct zx_sa11_Conditions_s* zx_sa11_Assertion_POP_Conditions(struct zx_sa11_Assertion_s* x)
{
  struct zx_sa11_Conditions_s* y;
  if (!x) return 0;
  y = x->Conditions;
  if (y)
    x->Conditions = (struct zx_sa11_Conditions_s*)y->gg.g.n;
  return y;
}

/* FUNC(zx_sa11_Assertion_PUSH_Conditions) */

void zx_sa11_Assertion_PUSH_Conditions(struct zx_sa11_Assertion_s* x, struct zx_sa11_Conditions_s* z)
{
  if (!x || !z) return;
  z->gg.g.n = &x->Conditions->gg.g;
  x->Conditions = z;
}

/* FUNC(zx_sa11_Assertion_REV_Conditions) */

void zx_sa11_Assertion_REV_Conditions(struct zx_sa11_Assertion_s* x)
{
  struct zx_sa11_Conditions_s* nxt;
  struct zx_sa11_Conditions_s* y;
  if (!x) return;
  y = x->Conditions;
  if (!y) return;
  x->Conditions = 0;
  while (y) {
    nxt = (struct zx_sa11_Conditions_s*)y->gg.g.n;
    y->gg.g.n = &x->Conditions->gg.g;
    x->Conditions = y;
    y = nxt;
  }
}

/* FUNC(zx_sa11_Assertion_PUT_Conditions) */

void zx_sa11_Assertion_PUT_Conditions(struct zx_sa11_Assertion_s* x, int n, struct zx_sa11_Conditions_s* z)
{
  struct zx_sa11_Conditions_s* y;
  if (!x || !z) return;
  y = x->Conditions;
  if (!y) return;
  switch (n) {
  case 0:
    z->gg.g.n = y->gg.g.n;
    x->Conditions = z;
    return;
  default:
    for (; n > 1 && y->gg.g.n; --n, y = (struct zx_sa11_Conditions_s*)y->gg.g.n) ;
    if (!y->gg.g.n) return;
    z->gg.g.n = y->gg.g.n->n;
    y->gg.g.n = &z->gg.g;
  }
}

/* FUNC(zx_sa11_Assertion_ADD_Conditions) */

void zx_sa11_Assertion_ADD_Conditions(struct zx_sa11_Assertion_s* x, int n, struct zx_sa11_Conditions_s* z)
{
  struct zx_sa11_Conditions_s* y;
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
    for (; y->gg.g.n; y = (struct zx_sa11_Conditions_s*)y->gg.g.n) ;
    break;
  default:
    for (y = x->Conditions; n > 1 && y; --n, y = (struct zx_sa11_Conditions_s*)y->gg.g.n) ;
    if (!y) return;
  }
  z->gg.g.n = y->gg.g.n;
  y->gg.g.n = &z->gg.g;
}

/* FUNC(zx_sa11_Assertion_DEL_Conditions) */

void zx_sa11_Assertion_DEL_Conditions(struct zx_sa11_Assertion_s* x, int n)
{
  struct zx_sa11_Conditions_s* y;
  if (!x) return;
  switch (n) {
  case 0:
    x->Conditions = (struct zx_sa11_Conditions_s*)x->Conditions->gg.g.n;
    return;
  case -1:
    y = (struct zx_sa11_Conditions_s*)x->Conditions;
    if (!y) return;
    for (; y->gg.g.n; y = (struct zx_sa11_Conditions_s*)y->gg.g.n) ;
    break;
  default:
    for (y = x->Conditions; n > 1 && y->gg.g.n; --n, y = (struct zx_sa11_Conditions_s*)y->gg.g.n) ;
    if (!y->gg.g.n) return;
  }
  y->gg.g.n = y->gg.g.n->n;
}

#endif



#ifdef ZX_ENA_GETPUT

/* FUNC(zx_sa11_Assertion_NUM_Advice) */

int zx_sa11_Assertion_NUM_Advice(struct zx_sa11_Assertion_s* x)
{
  struct zx_sa11_Advice_s* y;
  int n = 0;
  if (!x) return 0;
  for (y = x->Advice; y; ++n, y = (struct zx_sa11_Advice_s*)y->gg.g.n) ;
  return n;
}

/* FUNC(zx_sa11_Assertion_GET_Advice) */

struct zx_sa11_Advice_s* zx_sa11_Assertion_GET_Advice(struct zx_sa11_Assertion_s* x, int n)
{
  struct zx_sa11_Advice_s* y;
  if (!x) return 0;
  for (y = x->Advice; n>=0 && y; --n, y = (struct zx_sa11_Advice_s*)y->gg.g.n) ;
  return y;
}

/* FUNC(zx_sa11_Assertion_POP_Advice) */

struct zx_sa11_Advice_s* zx_sa11_Assertion_POP_Advice(struct zx_sa11_Assertion_s* x)
{
  struct zx_sa11_Advice_s* y;
  if (!x) return 0;
  y = x->Advice;
  if (y)
    x->Advice = (struct zx_sa11_Advice_s*)y->gg.g.n;
  return y;
}

/* FUNC(zx_sa11_Assertion_PUSH_Advice) */

void zx_sa11_Assertion_PUSH_Advice(struct zx_sa11_Assertion_s* x, struct zx_sa11_Advice_s* z)
{
  if (!x || !z) return;
  z->gg.g.n = &x->Advice->gg.g;
  x->Advice = z;
}

/* FUNC(zx_sa11_Assertion_REV_Advice) */

void zx_sa11_Assertion_REV_Advice(struct zx_sa11_Assertion_s* x)
{
  struct zx_sa11_Advice_s* nxt;
  struct zx_sa11_Advice_s* y;
  if (!x) return;
  y = x->Advice;
  if (!y) return;
  x->Advice = 0;
  while (y) {
    nxt = (struct zx_sa11_Advice_s*)y->gg.g.n;
    y->gg.g.n = &x->Advice->gg.g;
    x->Advice = y;
    y = nxt;
  }
}

/* FUNC(zx_sa11_Assertion_PUT_Advice) */

void zx_sa11_Assertion_PUT_Advice(struct zx_sa11_Assertion_s* x, int n, struct zx_sa11_Advice_s* z)
{
  struct zx_sa11_Advice_s* y;
  if (!x || !z) return;
  y = x->Advice;
  if (!y) return;
  switch (n) {
  case 0:
    z->gg.g.n = y->gg.g.n;
    x->Advice = z;
    return;
  default:
    for (; n > 1 && y->gg.g.n; --n, y = (struct zx_sa11_Advice_s*)y->gg.g.n) ;
    if (!y->gg.g.n) return;
    z->gg.g.n = y->gg.g.n->n;
    y->gg.g.n = &z->gg.g;
  }
}

/* FUNC(zx_sa11_Assertion_ADD_Advice) */

void zx_sa11_Assertion_ADD_Advice(struct zx_sa11_Assertion_s* x, int n, struct zx_sa11_Advice_s* z)
{
  struct zx_sa11_Advice_s* y;
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
    for (; y->gg.g.n; y = (struct zx_sa11_Advice_s*)y->gg.g.n) ;
    break;
  default:
    for (y = x->Advice; n > 1 && y; --n, y = (struct zx_sa11_Advice_s*)y->gg.g.n) ;
    if (!y) return;
  }
  z->gg.g.n = y->gg.g.n;
  y->gg.g.n = &z->gg.g;
}

/* FUNC(zx_sa11_Assertion_DEL_Advice) */

void zx_sa11_Assertion_DEL_Advice(struct zx_sa11_Assertion_s* x, int n)
{
  struct zx_sa11_Advice_s* y;
  if (!x) return;
  switch (n) {
  case 0:
    x->Advice = (struct zx_sa11_Advice_s*)x->Advice->gg.g.n;
    return;
  case -1:
    y = (struct zx_sa11_Advice_s*)x->Advice;
    if (!y) return;
    for (; y->gg.g.n; y = (struct zx_sa11_Advice_s*)y->gg.g.n) ;
    break;
  default:
    for (y = x->Advice; n > 1 && y->gg.g.n; --n, y = (struct zx_sa11_Advice_s*)y->gg.g.n) ;
    if (!y->gg.g.n) return;
  }
  y->gg.g.n = y->gg.g.n->n;
}

#endif



#ifdef ZX_ENA_GETPUT

/* FUNC(zx_sa11_Assertion_NUM_Statement) */

int zx_sa11_Assertion_NUM_Statement(struct zx_sa11_Assertion_s* x)
{
  struct zx_elem_s* y;
  int n = 0;
  if (!x) return 0;
  for (y = x->Statement; y; ++n, y = (struct zx_elem_s*)y->g.n) ;
  return n;
}

/* FUNC(zx_sa11_Assertion_GET_Statement) */

struct zx_elem_s* zx_sa11_Assertion_GET_Statement(struct zx_sa11_Assertion_s* x, int n)
{
  struct zx_elem_s* y;
  if (!x) return 0;
  for (y = x->Statement; n>=0 && y; --n, y = (struct zx_elem_s*)y->g.n) ;
  return y;
}

/* FUNC(zx_sa11_Assertion_POP_Statement) */

struct zx_elem_s* zx_sa11_Assertion_POP_Statement(struct zx_sa11_Assertion_s* x)
{
  struct zx_elem_s* y;
  if (!x) return 0;
  y = x->Statement;
  if (y)
    x->Statement = (struct zx_elem_s*)y->g.n;
  return y;
}

/* FUNC(zx_sa11_Assertion_PUSH_Statement) */

void zx_sa11_Assertion_PUSH_Statement(struct zx_sa11_Assertion_s* x, struct zx_elem_s* z)
{
  if (!x || !z) return;
  z->g.n = &x->Statement->g;
  x->Statement = z;
}

/* FUNC(zx_sa11_Assertion_REV_Statement) */

void zx_sa11_Assertion_REV_Statement(struct zx_sa11_Assertion_s* x)
{
  struct zx_elem_s* nxt;
  struct zx_elem_s* y;
  if (!x) return;
  y = x->Statement;
  if (!y) return;
  x->Statement = 0;
  while (y) {
    nxt = (struct zx_elem_s*)y->g.n;
    y->g.n = &x->Statement->g;
    x->Statement = y;
    y = nxt;
  }
}

/* FUNC(zx_sa11_Assertion_PUT_Statement) */

void zx_sa11_Assertion_PUT_Statement(struct zx_sa11_Assertion_s* x, int n, struct zx_elem_s* z)
{
  struct zx_elem_s* y;
  if (!x || !z) return;
  y = x->Statement;
  if (!y) return;
  switch (n) {
  case 0:
    z->g.n = y->g.n;
    x->Statement = z;
    return;
  default:
    for (; n > 1 && y->g.n; --n, y = (struct zx_elem_s*)y->g.n) ;
    if (!y->g.n) return;
    z->g.n = y->g.n->n;
    y->g.n = &z->g;
  }
}

/* FUNC(zx_sa11_Assertion_ADD_Statement) */

void zx_sa11_Assertion_ADD_Statement(struct zx_sa11_Assertion_s* x, int n, struct zx_elem_s* z)
{
  struct zx_elem_s* y;
  if (!x || !z) return;
  switch (n) {
  case 0:
  add_to_start:
    z->g.n = &x->Statement->g;
    x->Statement = z;
    return;
  case -1:
    y = x->Statement;
    if (!y) goto add_to_start;
    for (; y->g.n; y = (struct zx_elem_s*)y->g.n) ;
    break;
  default:
    for (y = x->Statement; n > 1 && y; --n, y = (struct zx_elem_s*)y->g.n) ;
    if (!y) return;
  }
  z->g.n = y->g.n;
  y->g.n = &z->g;
}

/* FUNC(zx_sa11_Assertion_DEL_Statement) */

void zx_sa11_Assertion_DEL_Statement(struct zx_sa11_Assertion_s* x, int n)
{
  struct zx_elem_s* y;
  if (!x) return;
  switch (n) {
  case 0:
    x->Statement = (struct zx_elem_s*)x->Statement->g.n;
    return;
  case -1:
    y = (struct zx_elem_s*)x->Statement;
    if (!y) return;
    for (; y->g.n; y = (struct zx_elem_s*)y->g.n) ;
    break;
  default:
    for (y = x->Statement; n > 1 && y->g.n; --n, y = (struct zx_elem_s*)y->g.n) ;
    if (!y->g.n) return;
  }
  y->g.n = y->g.n->n;
}

#endif



#ifdef ZX_ENA_GETPUT

/* FUNC(zx_sa11_Assertion_NUM_SubjectStatement) */

int zx_sa11_Assertion_NUM_SubjectStatement(struct zx_sa11_Assertion_s* x)
{
  struct zx_sa11_SubjectStatement_s* y;
  int n = 0;
  if (!x) return 0;
  for (y = x->SubjectStatement; y; ++n, y = (struct zx_sa11_SubjectStatement_s*)y->gg.g.n) ;
  return n;
}

/* FUNC(zx_sa11_Assertion_GET_SubjectStatement) */

struct zx_sa11_SubjectStatement_s* zx_sa11_Assertion_GET_SubjectStatement(struct zx_sa11_Assertion_s* x, int n)
{
  struct zx_sa11_SubjectStatement_s* y;
  if (!x) return 0;
  for (y = x->SubjectStatement; n>=0 && y; --n, y = (struct zx_sa11_SubjectStatement_s*)y->gg.g.n) ;
  return y;
}

/* FUNC(zx_sa11_Assertion_POP_SubjectStatement) */

struct zx_sa11_SubjectStatement_s* zx_sa11_Assertion_POP_SubjectStatement(struct zx_sa11_Assertion_s* x)
{
  struct zx_sa11_SubjectStatement_s* y;
  if (!x) return 0;
  y = x->SubjectStatement;
  if (y)
    x->SubjectStatement = (struct zx_sa11_SubjectStatement_s*)y->gg.g.n;
  return y;
}

/* FUNC(zx_sa11_Assertion_PUSH_SubjectStatement) */

void zx_sa11_Assertion_PUSH_SubjectStatement(struct zx_sa11_Assertion_s* x, struct zx_sa11_SubjectStatement_s* z)
{
  if (!x || !z) return;
  z->gg.g.n = &x->SubjectStatement->gg.g;
  x->SubjectStatement = z;
}

/* FUNC(zx_sa11_Assertion_REV_SubjectStatement) */

void zx_sa11_Assertion_REV_SubjectStatement(struct zx_sa11_Assertion_s* x)
{
  struct zx_sa11_SubjectStatement_s* nxt;
  struct zx_sa11_SubjectStatement_s* y;
  if (!x) return;
  y = x->SubjectStatement;
  if (!y) return;
  x->SubjectStatement = 0;
  while (y) {
    nxt = (struct zx_sa11_SubjectStatement_s*)y->gg.g.n;
    y->gg.g.n = &x->SubjectStatement->gg.g;
    x->SubjectStatement = y;
    y = nxt;
  }
}

/* FUNC(zx_sa11_Assertion_PUT_SubjectStatement) */

void zx_sa11_Assertion_PUT_SubjectStatement(struct zx_sa11_Assertion_s* x, int n, struct zx_sa11_SubjectStatement_s* z)
{
  struct zx_sa11_SubjectStatement_s* y;
  if (!x || !z) return;
  y = x->SubjectStatement;
  if (!y) return;
  switch (n) {
  case 0:
    z->gg.g.n = y->gg.g.n;
    x->SubjectStatement = z;
    return;
  default:
    for (; n > 1 && y->gg.g.n; --n, y = (struct zx_sa11_SubjectStatement_s*)y->gg.g.n) ;
    if (!y->gg.g.n) return;
    z->gg.g.n = y->gg.g.n->n;
    y->gg.g.n = &z->gg.g;
  }
}

/* FUNC(zx_sa11_Assertion_ADD_SubjectStatement) */

void zx_sa11_Assertion_ADD_SubjectStatement(struct zx_sa11_Assertion_s* x, int n, struct zx_sa11_SubjectStatement_s* z)
{
  struct zx_sa11_SubjectStatement_s* y;
  if (!x || !z) return;
  switch (n) {
  case 0:
  add_to_start:
    z->gg.g.n = &x->SubjectStatement->gg.g;
    x->SubjectStatement = z;
    return;
  case -1:
    y = x->SubjectStatement;
    if (!y) goto add_to_start;
    for (; y->gg.g.n; y = (struct zx_sa11_SubjectStatement_s*)y->gg.g.n) ;
    break;
  default:
    for (y = x->SubjectStatement; n > 1 && y; --n, y = (struct zx_sa11_SubjectStatement_s*)y->gg.g.n) ;
    if (!y) return;
  }
  z->gg.g.n = y->gg.g.n;
  y->gg.g.n = &z->gg.g;
}

/* FUNC(zx_sa11_Assertion_DEL_SubjectStatement) */

void zx_sa11_Assertion_DEL_SubjectStatement(struct zx_sa11_Assertion_s* x, int n)
{
  struct zx_sa11_SubjectStatement_s* y;
  if (!x) return;
  switch (n) {
  case 0:
    x->SubjectStatement = (struct zx_sa11_SubjectStatement_s*)x->SubjectStatement->gg.g.n;
    return;
  case -1:
    y = (struct zx_sa11_SubjectStatement_s*)x->SubjectStatement;
    if (!y) return;
    for (; y->gg.g.n; y = (struct zx_sa11_SubjectStatement_s*)y->gg.g.n) ;
    break;
  default:
    for (y = x->SubjectStatement; n > 1 && y->gg.g.n; --n, y = (struct zx_sa11_SubjectStatement_s*)y->gg.g.n) ;
    if (!y->gg.g.n) return;
  }
  y->gg.g.n = y->gg.g.n->n;
}

#endif



#ifdef ZX_ENA_GETPUT

/* FUNC(zx_sa11_Assertion_NUM_AuthenticationStatement) */

int zx_sa11_Assertion_NUM_AuthenticationStatement(struct zx_sa11_Assertion_s* x)
{
  struct zx_sa11_AuthenticationStatement_s* y;
  int n = 0;
  if (!x) return 0;
  for (y = x->AuthenticationStatement; y; ++n, y = (struct zx_sa11_AuthenticationStatement_s*)y->gg.g.n) ;
  return n;
}

/* FUNC(zx_sa11_Assertion_GET_AuthenticationStatement) */

struct zx_sa11_AuthenticationStatement_s* zx_sa11_Assertion_GET_AuthenticationStatement(struct zx_sa11_Assertion_s* x, int n)
{
  struct zx_sa11_AuthenticationStatement_s* y;
  if (!x) return 0;
  for (y = x->AuthenticationStatement; n>=0 && y; --n, y = (struct zx_sa11_AuthenticationStatement_s*)y->gg.g.n) ;
  return y;
}

/* FUNC(zx_sa11_Assertion_POP_AuthenticationStatement) */

struct zx_sa11_AuthenticationStatement_s* zx_sa11_Assertion_POP_AuthenticationStatement(struct zx_sa11_Assertion_s* x)
{
  struct zx_sa11_AuthenticationStatement_s* y;
  if (!x) return 0;
  y = x->AuthenticationStatement;
  if (y)
    x->AuthenticationStatement = (struct zx_sa11_AuthenticationStatement_s*)y->gg.g.n;
  return y;
}

/* FUNC(zx_sa11_Assertion_PUSH_AuthenticationStatement) */

void zx_sa11_Assertion_PUSH_AuthenticationStatement(struct zx_sa11_Assertion_s* x, struct zx_sa11_AuthenticationStatement_s* z)
{
  if (!x || !z) return;
  z->gg.g.n = &x->AuthenticationStatement->gg.g;
  x->AuthenticationStatement = z;
}

/* FUNC(zx_sa11_Assertion_REV_AuthenticationStatement) */

void zx_sa11_Assertion_REV_AuthenticationStatement(struct zx_sa11_Assertion_s* x)
{
  struct zx_sa11_AuthenticationStatement_s* nxt;
  struct zx_sa11_AuthenticationStatement_s* y;
  if (!x) return;
  y = x->AuthenticationStatement;
  if (!y) return;
  x->AuthenticationStatement = 0;
  while (y) {
    nxt = (struct zx_sa11_AuthenticationStatement_s*)y->gg.g.n;
    y->gg.g.n = &x->AuthenticationStatement->gg.g;
    x->AuthenticationStatement = y;
    y = nxt;
  }
}

/* FUNC(zx_sa11_Assertion_PUT_AuthenticationStatement) */

void zx_sa11_Assertion_PUT_AuthenticationStatement(struct zx_sa11_Assertion_s* x, int n, struct zx_sa11_AuthenticationStatement_s* z)
{
  struct zx_sa11_AuthenticationStatement_s* y;
  if (!x || !z) return;
  y = x->AuthenticationStatement;
  if (!y) return;
  switch (n) {
  case 0:
    z->gg.g.n = y->gg.g.n;
    x->AuthenticationStatement = z;
    return;
  default:
    for (; n > 1 && y->gg.g.n; --n, y = (struct zx_sa11_AuthenticationStatement_s*)y->gg.g.n) ;
    if (!y->gg.g.n) return;
    z->gg.g.n = y->gg.g.n->n;
    y->gg.g.n = &z->gg.g;
  }
}

/* FUNC(zx_sa11_Assertion_ADD_AuthenticationStatement) */

void zx_sa11_Assertion_ADD_AuthenticationStatement(struct zx_sa11_Assertion_s* x, int n, struct zx_sa11_AuthenticationStatement_s* z)
{
  struct zx_sa11_AuthenticationStatement_s* y;
  if (!x || !z) return;
  switch (n) {
  case 0:
  add_to_start:
    z->gg.g.n = &x->AuthenticationStatement->gg.g;
    x->AuthenticationStatement = z;
    return;
  case -1:
    y = x->AuthenticationStatement;
    if (!y) goto add_to_start;
    for (; y->gg.g.n; y = (struct zx_sa11_AuthenticationStatement_s*)y->gg.g.n) ;
    break;
  default:
    for (y = x->AuthenticationStatement; n > 1 && y; --n, y = (struct zx_sa11_AuthenticationStatement_s*)y->gg.g.n) ;
    if (!y) return;
  }
  z->gg.g.n = y->gg.g.n;
  y->gg.g.n = &z->gg.g;
}

/* FUNC(zx_sa11_Assertion_DEL_AuthenticationStatement) */

void zx_sa11_Assertion_DEL_AuthenticationStatement(struct zx_sa11_Assertion_s* x, int n)
{
  struct zx_sa11_AuthenticationStatement_s* y;
  if (!x) return;
  switch (n) {
  case 0:
    x->AuthenticationStatement = (struct zx_sa11_AuthenticationStatement_s*)x->AuthenticationStatement->gg.g.n;
    return;
  case -1:
    y = (struct zx_sa11_AuthenticationStatement_s*)x->AuthenticationStatement;
    if (!y) return;
    for (; y->gg.g.n; y = (struct zx_sa11_AuthenticationStatement_s*)y->gg.g.n) ;
    break;
  default:
    for (y = x->AuthenticationStatement; n > 1 && y->gg.g.n; --n, y = (struct zx_sa11_AuthenticationStatement_s*)y->gg.g.n) ;
    if (!y->gg.g.n) return;
  }
  y->gg.g.n = y->gg.g.n->n;
}

#endif



#ifdef ZX_ENA_GETPUT

/* FUNC(zx_sa11_Assertion_NUM_AuthorizationDecisionStatement) */

int zx_sa11_Assertion_NUM_AuthorizationDecisionStatement(struct zx_sa11_Assertion_s* x)
{
  struct zx_sa11_AuthorizationDecisionStatement_s* y;
  int n = 0;
  if (!x) return 0;
  for (y = x->AuthorizationDecisionStatement; y; ++n, y = (struct zx_sa11_AuthorizationDecisionStatement_s*)y->gg.g.n) ;
  return n;
}

/* FUNC(zx_sa11_Assertion_GET_AuthorizationDecisionStatement) */

struct zx_sa11_AuthorizationDecisionStatement_s* zx_sa11_Assertion_GET_AuthorizationDecisionStatement(struct zx_sa11_Assertion_s* x, int n)
{
  struct zx_sa11_AuthorizationDecisionStatement_s* y;
  if (!x) return 0;
  for (y = x->AuthorizationDecisionStatement; n>=0 && y; --n, y = (struct zx_sa11_AuthorizationDecisionStatement_s*)y->gg.g.n) ;
  return y;
}

/* FUNC(zx_sa11_Assertion_POP_AuthorizationDecisionStatement) */

struct zx_sa11_AuthorizationDecisionStatement_s* zx_sa11_Assertion_POP_AuthorizationDecisionStatement(struct zx_sa11_Assertion_s* x)
{
  struct zx_sa11_AuthorizationDecisionStatement_s* y;
  if (!x) return 0;
  y = x->AuthorizationDecisionStatement;
  if (y)
    x->AuthorizationDecisionStatement = (struct zx_sa11_AuthorizationDecisionStatement_s*)y->gg.g.n;
  return y;
}

/* FUNC(zx_sa11_Assertion_PUSH_AuthorizationDecisionStatement) */

void zx_sa11_Assertion_PUSH_AuthorizationDecisionStatement(struct zx_sa11_Assertion_s* x, struct zx_sa11_AuthorizationDecisionStatement_s* z)
{
  if (!x || !z) return;
  z->gg.g.n = &x->AuthorizationDecisionStatement->gg.g;
  x->AuthorizationDecisionStatement = z;
}

/* FUNC(zx_sa11_Assertion_REV_AuthorizationDecisionStatement) */

void zx_sa11_Assertion_REV_AuthorizationDecisionStatement(struct zx_sa11_Assertion_s* x)
{
  struct zx_sa11_AuthorizationDecisionStatement_s* nxt;
  struct zx_sa11_AuthorizationDecisionStatement_s* y;
  if (!x) return;
  y = x->AuthorizationDecisionStatement;
  if (!y) return;
  x->AuthorizationDecisionStatement = 0;
  while (y) {
    nxt = (struct zx_sa11_AuthorizationDecisionStatement_s*)y->gg.g.n;
    y->gg.g.n = &x->AuthorizationDecisionStatement->gg.g;
    x->AuthorizationDecisionStatement = y;
    y = nxt;
  }
}

/* FUNC(zx_sa11_Assertion_PUT_AuthorizationDecisionStatement) */

void zx_sa11_Assertion_PUT_AuthorizationDecisionStatement(struct zx_sa11_Assertion_s* x, int n, struct zx_sa11_AuthorizationDecisionStatement_s* z)
{
  struct zx_sa11_AuthorizationDecisionStatement_s* y;
  if (!x || !z) return;
  y = x->AuthorizationDecisionStatement;
  if (!y) return;
  switch (n) {
  case 0:
    z->gg.g.n = y->gg.g.n;
    x->AuthorizationDecisionStatement = z;
    return;
  default:
    for (; n > 1 && y->gg.g.n; --n, y = (struct zx_sa11_AuthorizationDecisionStatement_s*)y->gg.g.n) ;
    if (!y->gg.g.n) return;
    z->gg.g.n = y->gg.g.n->n;
    y->gg.g.n = &z->gg.g;
  }
}

/* FUNC(zx_sa11_Assertion_ADD_AuthorizationDecisionStatement) */

void zx_sa11_Assertion_ADD_AuthorizationDecisionStatement(struct zx_sa11_Assertion_s* x, int n, struct zx_sa11_AuthorizationDecisionStatement_s* z)
{
  struct zx_sa11_AuthorizationDecisionStatement_s* y;
  if (!x || !z) return;
  switch (n) {
  case 0:
  add_to_start:
    z->gg.g.n = &x->AuthorizationDecisionStatement->gg.g;
    x->AuthorizationDecisionStatement = z;
    return;
  case -1:
    y = x->AuthorizationDecisionStatement;
    if (!y) goto add_to_start;
    for (; y->gg.g.n; y = (struct zx_sa11_AuthorizationDecisionStatement_s*)y->gg.g.n) ;
    break;
  default:
    for (y = x->AuthorizationDecisionStatement; n > 1 && y; --n, y = (struct zx_sa11_AuthorizationDecisionStatement_s*)y->gg.g.n) ;
    if (!y) return;
  }
  z->gg.g.n = y->gg.g.n;
  y->gg.g.n = &z->gg.g;
}

/* FUNC(zx_sa11_Assertion_DEL_AuthorizationDecisionStatement) */

void zx_sa11_Assertion_DEL_AuthorizationDecisionStatement(struct zx_sa11_Assertion_s* x, int n)
{
  struct zx_sa11_AuthorizationDecisionStatement_s* y;
  if (!x) return;
  switch (n) {
  case 0:
    x->AuthorizationDecisionStatement = (struct zx_sa11_AuthorizationDecisionStatement_s*)x->AuthorizationDecisionStatement->gg.g.n;
    return;
  case -1:
    y = (struct zx_sa11_AuthorizationDecisionStatement_s*)x->AuthorizationDecisionStatement;
    if (!y) return;
    for (; y->gg.g.n; y = (struct zx_sa11_AuthorizationDecisionStatement_s*)y->gg.g.n) ;
    break;
  default:
    for (y = x->AuthorizationDecisionStatement; n > 1 && y->gg.g.n; --n, y = (struct zx_sa11_AuthorizationDecisionStatement_s*)y->gg.g.n) ;
    if (!y->gg.g.n) return;
  }
  y->gg.g.n = y->gg.g.n->n;
}

#endif



#ifdef ZX_ENA_GETPUT

/* FUNC(zx_sa11_Assertion_NUM_AttributeStatement) */

int zx_sa11_Assertion_NUM_AttributeStatement(struct zx_sa11_Assertion_s* x)
{
  struct zx_sa11_AttributeStatement_s* y;
  int n = 0;
  if (!x) return 0;
  for (y = x->AttributeStatement; y; ++n, y = (struct zx_sa11_AttributeStatement_s*)y->gg.g.n) ;
  return n;
}

/* FUNC(zx_sa11_Assertion_GET_AttributeStatement) */

struct zx_sa11_AttributeStatement_s* zx_sa11_Assertion_GET_AttributeStatement(struct zx_sa11_Assertion_s* x, int n)
{
  struct zx_sa11_AttributeStatement_s* y;
  if (!x) return 0;
  for (y = x->AttributeStatement; n>=0 && y; --n, y = (struct zx_sa11_AttributeStatement_s*)y->gg.g.n) ;
  return y;
}

/* FUNC(zx_sa11_Assertion_POP_AttributeStatement) */

struct zx_sa11_AttributeStatement_s* zx_sa11_Assertion_POP_AttributeStatement(struct zx_sa11_Assertion_s* x)
{
  struct zx_sa11_AttributeStatement_s* y;
  if (!x) return 0;
  y = x->AttributeStatement;
  if (y)
    x->AttributeStatement = (struct zx_sa11_AttributeStatement_s*)y->gg.g.n;
  return y;
}

/* FUNC(zx_sa11_Assertion_PUSH_AttributeStatement) */

void zx_sa11_Assertion_PUSH_AttributeStatement(struct zx_sa11_Assertion_s* x, struct zx_sa11_AttributeStatement_s* z)
{
  if (!x || !z) return;
  z->gg.g.n = &x->AttributeStatement->gg.g;
  x->AttributeStatement = z;
}

/* FUNC(zx_sa11_Assertion_REV_AttributeStatement) */

void zx_sa11_Assertion_REV_AttributeStatement(struct zx_sa11_Assertion_s* x)
{
  struct zx_sa11_AttributeStatement_s* nxt;
  struct zx_sa11_AttributeStatement_s* y;
  if (!x) return;
  y = x->AttributeStatement;
  if (!y) return;
  x->AttributeStatement = 0;
  while (y) {
    nxt = (struct zx_sa11_AttributeStatement_s*)y->gg.g.n;
    y->gg.g.n = &x->AttributeStatement->gg.g;
    x->AttributeStatement = y;
    y = nxt;
  }
}

/* FUNC(zx_sa11_Assertion_PUT_AttributeStatement) */

void zx_sa11_Assertion_PUT_AttributeStatement(struct zx_sa11_Assertion_s* x, int n, struct zx_sa11_AttributeStatement_s* z)
{
  struct zx_sa11_AttributeStatement_s* y;
  if (!x || !z) return;
  y = x->AttributeStatement;
  if (!y) return;
  switch (n) {
  case 0:
    z->gg.g.n = y->gg.g.n;
    x->AttributeStatement = z;
    return;
  default:
    for (; n > 1 && y->gg.g.n; --n, y = (struct zx_sa11_AttributeStatement_s*)y->gg.g.n) ;
    if (!y->gg.g.n) return;
    z->gg.g.n = y->gg.g.n->n;
    y->gg.g.n = &z->gg.g;
  }
}

/* FUNC(zx_sa11_Assertion_ADD_AttributeStatement) */

void zx_sa11_Assertion_ADD_AttributeStatement(struct zx_sa11_Assertion_s* x, int n, struct zx_sa11_AttributeStatement_s* z)
{
  struct zx_sa11_AttributeStatement_s* y;
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
    for (; y->gg.g.n; y = (struct zx_sa11_AttributeStatement_s*)y->gg.g.n) ;
    break;
  default:
    for (y = x->AttributeStatement; n > 1 && y; --n, y = (struct zx_sa11_AttributeStatement_s*)y->gg.g.n) ;
    if (!y) return;
  }
  z->gg.g.n = y->gg.g.n;
  y->gg.g.n = &z->gg.g;
}

/* FUNC(zx_sa11_Assertion_DEL_AttributeStatement) */

void zx_sa11_Assertion_DEL_AttributeStatement(struct zx_sa11_Assertion_s* x, int n)
{
  struct zx_sa11_AttributeStatement_s* y;
  if (!x) return;
  switch (n) {
  case 0:
    x->AttributeStatement = (struct zx_sa11_AttributeStatement_s*)x->AttributeStatement->gg.g.n;
    return;
  case -1:
    y = (struct zx_sa11_AttributeStatement_s*)x->AttributeStatement;
    if (!y) return;
    for (; y->gg.g.n; y = (struct zx_sa11_AttributeStatement_s*)y->gg.g.n) ;
    break;
  default:
    for (y = x->AttributeStatement; n > 1 && y->gg.g.n; --n, y = (struct zx_sa11_AttributeStatement_s*)y->gg.g.n) ;
    if (!y->gg.g.n) return;
  }
  y->gg.g.n = y->gg.g.n->n;
}

#endif



#ifdef ZX_ENA_GETPUT

/* FUNC(zx_sa11_Assertion_NUM_XACMLAuthzDecisionStatement) */

int zx_sa11_Assertion_NUM_XACMLAuthzDecisionStatement(struct zx_sa11_Assertion_s* x)
{
  struct zx_xasa_XACMLAuthzDecisionStatement_s* y;
  int n = 0;
  if (!x) return 0;
  for (y = x->XACMLAuthzDecisionStatement; y; ++n, y = (struct zx_xasa_XACMLAuthzDecisionStatement_s*)y->gg.g.n) ;
  return n;
}

/* FUNC(zx_sa11_Assertion_GET_XACMLAuthzDecisionStatement) */

struct zx_xasa_XACMLAuthzDecisionStatement_s* zx_sa11_Assertion_GET_XACMLAuthzDecisionStatement(struct zx_sa11_Assertion_s* x, int n)
{
  struct zx_xasa_XACMLAuthzDecisionStatement_s* y;
  if (!x) return 0;
  for (y = x->XACMLAuthzDecisionStatement; n>=0 && y; --n, y = (struct zx_xasa_XACMLAuthzDecisionStatement_s*)y->gg.g.n) ;
  return y;
}

/* FUNC(zx_sa11_Assertion_POP_XACMLAuthzDecisionStatement) */

struct zx_xasa_XACMLAuthzDecisionStatement_s* zx_sa11_Assertion_POP_XACMLAuthzDecisionStatement(struct zx_sa11_Assertion_s* x)
{
  struct zx_xasa_XACMLAuthzDecisionStatement_s* y;
  if (!x) return 0;
  y = x->XACMLAuthzDecisionStatement;
  if (y)
    x->XACMLAuthzDecisionStatement = (struct zx_xasa_XACMLAuthzDecisionStatement_s*)y->gg.g.n;
  return y;
}

/* FUNC(zx_sa11_Assertion_PUSH_XACMLAuthzDecisionStatement) */

void zx_sa11_Assertion_PUSH_XACMLAuthzDecisionStatement(struct zx_sa11_Assertion_s* x, struct zx_xasa_XACMLAuthzDecisionStatement_s* z)
{
  if (!x || !z) return;
  z->gg.g.n = &x->XACMLAuthzDecisionStatement->gg.g;
  x->XACMLAuthzDecisionStatement = z;
}

/* FUNC(zx_sa11_Assertion_REV_XACMLAuthzDecisionStatement) */

void zx_sa11_Assertion_REV_XACMLAuthzDecisionStatement(struct zx_sa11_Assertion_s* x)
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

/* FUNC(zx_sa11_Assertion_PUT_XACMLAuthzDecisionStatement) */

void zx_sa11_Assertion_PUT_XACMLAuthzDecisionStatement(struct zx_sa11_Assertion_s* x, int n, struct zx_xasa_XACMLAuthzDecisionStatement_s* z)
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

/* FUNC(zx_sa11_Assertion_ADD_XACMLAuthzDecisionStatement) */

void zx_sa11_Assertion_ADD_XACMLAuthzDecisionStatement(struct zx_sa11_Assertion_s* x, int n, struct zx_xasa_XACMLAuthzDecisionStatement_s* z)
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

/* FUNC(zx_sa11_Assertion_DEL_XACMLAuthzDecisionStatement) */

void zx_sa11_Assertion_DEL_XACMLAuthzDecisionStatement(struct zx_sa11_Assertion_s* x, int n)
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

/* FUNC(zx_sa11_Assertion_NUM_XACMLPolicyStatement) */

int zx_sa11_Assertion_NUM_XACMLPolicyStatement(struct zx_sa11_Assertion_s* x)
{
  struct zx_xasa_XACMLPolicyStatement_s* y;
  int n = 0;
  if (!x) return 0;
  for (y = x->XACMLPolicyStatement; y; ++n, y = (struct zx_xasa_XACMLPolicyStatement_s*)y->gg.g.n) ;
  return n;
}

/* FUNC(zx_sa11_Assertion_GET_XACMLPolicyStatement) */

struct zx_xasa_XACMLPolicyStatement_s* zx_sa11_Assertion_GET_XACMLPolicyStatement(struct zx_sa11_Assertion_s* x, int n)
{
  struct zx_xasa_XACMLPolicyStatement_s* y;
  if (!x) return 0;
  for (y = x->XACMLPolicyStatement; n>=0 && y; --n, y = (struct zx_xasa_XACMLPolicyStatement_s*)y->gg.g.n) ;
  return y;
}

/* FUNC(zx_sa11_Assertion_POP_XACMLPolicyStatement) */

struct zx_xasa_XACMLPolicyStatement_s* zx_sa11_Assertion_POP_XACMLPolicyStatement(struct zx_sa11_Assertion_s* x)
{
  struct zx_xasa_XACMLPolicyStatement_s* y;
  if (!x) return 0;
  y = x->XACMLPolicyStatement;
  if (y)
    x->XACMLPolicyStatement = (struct zx_xasa_XACMLPolicyStatement_s*)y->gg.g.n;
  return y;
}

/* FUNC(zx_sa11_Assertion_PUSH_XACMLPolicyStatement) */

void zx_sa11_Assertion_PUSH_XACMLPolicyStatement(struct zx_sa11_Assertion_s* x, struct zx_xasa_XACMLPolicyStatement_s* z)
{
  if (!x || !z) return;
  z->gg.g.n = &x->XACMLPolicyStatement->gg.g;
  x->XACMLPolicyStatement = z;
}

/* FUNC(zx_sa11_Assertion_REV_XACMLPolicyStatement) */

void zx_sa11_Assertion_REV_XACMLPolicyStatement(struct zx_sa11_Assertion_s* x)
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

/* FUNC(zx_sa11_Assertion_PUT_XACMLPolicyStatement) */

void zx_sa11_Assertion_PUT_XACMLPolicyStatement(struct zx_sa11_Assertion_s* x, int n, struct zx_xasa_XACMLPolicyStatement_s* z)
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

/* FUNC(zx_sa11_Assertion_ADD_XACMLPolicyStatement) */

void zx_sa11_Assertion_ADD_XACMLPolicyStatement(struct zx_sa11_Assertion_s* x, int n, struct zx_xasa_XACMLPolicyStatement_s* z)
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

/* FUNC(zx_sa11_Assertion_DEL_XACMLPolicyStatement) */

void zx_sa11_Assertion_DEL_XACMLPolicyStatement(struct zx_sa11_Assertion_s* x, int n)
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

/* FUNC(zx_sa11_Assertion_NUM_xasacd1_XACMLAuthzDecisionStatement) */

int zx_sa11_Assertion_NUM_xasacd1_XACMLAuthzDecisionStatement(struct zx_sa11_Assertion_s* x)
{
  struct zx_xasacd1_XACMLAuthzDecisionStatement_s* y;
  int n = 0;
  if (!x) return 0;
  for (y = x->xasacd1_XACMLAuthzDecisionStatement; y; ++n, y = (struct zx_xasacd1_XACMLAuthzDecisionStatement_s*)y->gg.g.n) ;
  return n;
}

/* FUNC(zx_sa11_Assertion_GET_xasacd1_XACMLAuthzDecisionStatement) */

struct zx_xasacd1_XACMLAuthzDecisionStatement_s* zx_sa11_Assertion_GET_xasacd1_XACMLAuthzDecisionStatement(struct zx_sa11_Assertion_s* x, int n)
{
  struct zx_xasacd1_XACMLAuthzDecisionStatement_s* y;
  if (!x) return 0;
  for (y = x->xasacd1_XACMLAuthzDecisionStatement; n>=0 && y; --n, y = (struct zx_xasacd1_XACMLAuthzDecisionStatement_s*)y->gg.g.n) ;
  return y;
}

/* FUNC(zx_sa11_Assertion_POP_xasacd1_XACMLAuthzDecisionStatement) */

struct zx_xasacd1_XACMLAuthzDecisionStatement_s* zx_sa11_Assertion_POP_xasacd1_XACMLAuthzDecisionStatement(struct zx_sa11_Assertion_s* x)
{
  struct zx_xasacd1_XACMLAuthzDecisionStatement_s* y;
  if (!x) return 0;
  y = x->xasacd1_XACMLAuthzDecisionStatement;
  if (y)
    x->xasacd1_XACMLAuthzDecisionStatement = (struct zx_xasacd1_XACMLAuthzDecisionStatement_s*)y->gg.g.n;
  return y;
}

/* FUNC(zx_sa11_Assertion_PUSH_xasacd1_XACMLAuthzDecisionStatement) */

void zx_sa11_Assertion_PUSH_xasacd1_XACMLAuthzDecisionStatement(struct zx_sa11_Assertion_s* x, struct zx_xasacd1_XACMLAuthzDecisionStatement_s* z)
{
  if (!x || !z) return;
  z->gg.g.n = &x->xasacd1_XACMLAuthzDecisionStatement->gg.g;
  x->xasacd1_XACMLAuthzDecisionStatement = z;
}

/* FUNC(zx_sa11_Assertion_REV_xasacd1_XACMLAuthzDecisionStatement) */

void zx_sa11_Assertion_REV_xasacd1_XACMLAuthzDecisionStatement(struct zx_sa11_Assertion_s* x)
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

/* FUNC(zx_sa11_Assertion_PUT_xasacd1_XACMLAuthzDecisionStatement) */

void zx_sa11_Assertion_PUT_xasacd1_XACMLAuthzDecisionStatement(struct zx_sa11_Assertion_s* x, int n, struct zx_xasacd1_XACMLAuthzDecisionStatement_s* z)
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

/* FUNC(zx_sa11_Assertion_ADD_xasacd1_XACMLAuthzDecisionStatement) */

void zx_sa11_Assertion_ADD_xasacd1_XACMLAuthzDecisionStatement(struct zx_sa11_Assertion_s* x, int n, struct zx_xasacd1_XACMLAuthzDecisionStatement_s* z)
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

/* FUNC(zx_sa11_Assertion_DEL_xasacd1_XACMLAuthzDecisionStatement) */

void zx_sa11_Assertion_DEL_xasacd1_XACMLAuthzDecisionStatement(struct zx_sa11_Assertion_s* x, int n)
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

/* FUNC(zx_sa11_Assertion_NUM_xasacd1_XACMLPolicyStatement) */

int zx_sa11_Assertion_NUM_xasacd1_XACMLPolicyStatement(struct zx_sa11_Assertion_s* x)
{
  struct zx_xasacd1_XACMLPolicyStatement_s* y;
  int n = 0;
  if (!x) return 0;
  for (y = x->xasacd1_XACMLPolicyStatement; y; ++n, y = (struct zx_xasacd1_XACMLPolicyStatement_s*)y->gg.g.n) ;
  return n;
}

/* FUNC(zx_sa11_Assertion_GET_xasacd1_XACMLPolicyStatement) */

struct zx_xasacd1_XACMLPolicyStatement_s* zx_sa11_Assertion_GET_xasacd1_XACMLPolicyStatement(struct zx_sa11_Assertion_s* x, int n)
{
  struct zx_xasacd1_XACMLPolicyStatement_s* y;
  if (!x) return 0;
  for (y = x->xasacd1_XACMLPolicyStatement; n>=0 && y; --n, y = (struct zx_xasacd1_XACMLPolicyStatement_s*)y->gg.g.n) ;
  return y;
}

/* FUNC(zx_sa11_Assertion_POP_xasacd1_XACMLPolicyStatement) */

struct zx_xasacd1_XACMLPolicyStatement_s* zx_sa11_Assertion_POP_xasacd1_XACMLPolicyStatement(struct zx_sa11_Assertion_s* x)
{
  struct zx_xasacd1_XACMLPolicyStatement_s* y;
  if (!x) return 0;
  y = x->xasacd1_XACMLPolicyStatement;
  if (y)
    x->xasacd1_XACMLPolicyStatement = (struct zx_xasacd1_XACMLPolicyStatement_s*)y->gg.g.n;
  return y;
}

/* FUNC(zx_sa11_Assertion_PUSH_xasacd1_XACMLPolicyStatement) */

void zx_sa11_Assertion_PUSH_xasacd1_XACMLPolicyStatement(struct zx_sa11_Assertion_s* x, struct zx_xasacd1_XACMLPolicyStatement_s* z)
{
  if (!x || !z) return;
  z->gg.g.n = &x->xasacd1_XACMLPolicyStatement->gg.g;
  x->xasacd1_XACMLPolicyStatement = z;
}

/* FUNC(zx_sa11_Assertion_REV_xasacd1_XACMLPolicyStatement) */

void zx_sa11_Assertion_REV_xasacd1_XACMLPolicyStatement(struct zx_sa11_Assertion_s* x)
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

/* FUNC(zx_sa11_Assertion_PUT_xasacd1_XACMLPolicyStatement) */

void zx_sa11_Assertion_PUT_xasacd1_XACMLPolicyStatement(struct zx_sa11_Assertion_s* x, int n, struct zx_xasacd1_XACMLPolicyStatement_s* z)
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

/* FUNC(zx_sa11_Assertion_ADD_xasacd1_XACMLPolicyStatement) */

void zx_sa11_Assertion_ADD_xasacd1_XACMLPolicyStatement(struct zx_sa11_Assertion_s* x, int n, struct zx_xasacd1_XACMLPolicyStatement_s* z)
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

/* FUNC(zx_sa11_Assertion_DEL_xasacd1_XACMLPolicyStatement) */

void zx_sa11_Assertion_DEL_xasacd1_XACMLPolicyStatement(struct zx_sa11_Assertion_s* x, int n)
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



#ifdef ZX_ENA_GETPUT

/* FUNC(zx_sa11_Assertion_NUM_Signature) */

int zx_sa11_Assertion_NUM_Signature(struct zx_sa11_Assertion_s* x)
{
  struct zx_ds_Signature_s* y;
  int n = 0;
  if (!x) return 0;
  for (y = x->Signature; y; ++n, y = (struct zx_ds_Signature_s*)y->gg.g.n) ;
  return n;
}

/* FUNC(zx_sa11_Assertion_GET_Signature) */

struct zx_ds_Signature_s* zx_sa11_Assertion_GET_Signature(struct zx_sa11_Assertion_s* x, int n)
{
  struct zx_ds_Signature_s* y;
  if (!x) return 0;
  for (y = x->Signature; n>=0 && y; --n, y = (struct zx_ds_Signature_s*)y->gg.g.n) ;
  return y;
}

/* FUNC(zx_sa11_Assertion_POP_Signature) */

struct zx_ds_Signature_s* zx_sa11_Assertion_POP_Signature(struct zx_sa11_Assertion_s* x)
{
  struct zx_ds_Signature_s* y;
  if (!x) return 0;
  y = x->Signature;
  if (y)
    x->Signature = (struct zx_ds_Signature_s*)y->gg.g.n;
  return y;
}

/* FUNC(zx_sa11_Assertion_PUSH_Signature) */

void zx_sa11_Assertion_PUSH_Signature(struct zx_sa11_Assertion_s* x, struct zx_ds_Signature_s* z)
{
  if (!x || !z) return;
  z->gg.g.n = &x->Signature->gg.g;
  x->Signature = z;
}

/* FUNC(zx_sa11_Assertion_REV_Signature) */

void zx_sa11_Assertion_REV_Signature(struct zx_sa11_Assertion_s* x)
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

/* FUNC(zx_sa11_Assertion_PUT_Signature) */

void zx_sa11_Assertion_PUT_Signature(struct zx_sa11_Assertion_s* x, int n, struct zx_ds_Signature_s* z)
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

/* FUNC(zx_sa11_Assertion_ADD_Signature) */

void zx_sa11_Assertion_ADD_Signature(struct zx_sa11_Assertion_s* x, int n, struct zx_ds_Signature_s* z)
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

/* FUNC(zx_sa11_Assertion_DEL_Signature) */

void zx_sa11_Assertion_DEL_Signature(struct zx_sa11_Assertion_s* x, int n)
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

/* FUNC(zx_sa11_Assertion_GET_AssertionID) */
struct zx_str* zx_sa11_Assertion_GET_AssertionID(struct zx_sa11_Assertion_s* x) { return x->AssertionID; }
/* FUNC(zx_sa11_Assertion_PUT_AssertionID) */
void zx_sa11_Assertion_PUT_AssertionID(struct zx_sa11_Assertion_s* x, struct zx_str* y) { x->AssertionID = y; }
/* FUNC(zx_sa11_Assertion_GET_IssueInstant) */
struct zx_str* zx_sa11_Assertion_GET_IssueInstant(struct zx_sa11_Assertion_s* x) { return x->IssueInstant; }
/* FUNC(zx_sa11_Assertion_PUT_IssueInstant) */
void zx_sa11_Assertion_PUT_IssueInstant(struct zx_sa11_Assertion_s* x, struct zx_str* y) { x->IssueInstant = y; }
/* FUNC(zx_sa11_Assertion_GET_Issuer) */
struct zx_str* zx_sa11_Assertion_GET_Issuer(struct zx_sa11_Assertion_s* x) { return x->Issuer; }
/* FUNC(zx_sa11_Assertion_PUT_Issuer) */
void zx_sa11_Assertion_PUT_Issuer(struct zx_sa11_Assertion_s* x, struct zx_str* y) { x->Issuer = y; }
/* FUNC(zx_sa11_Assertion_GET_MajorVersion) */
struct zx_str* zx_sa11_Assertion_GET_MajorVersion(struct zx_sa11_Assertion_s* x) { return x->MajorVersion; }
/* FUNC(zx_sa11_Assertion_PUT_MajorVersion) */
void zx_sa11_Assertion_PUT_MajorVersion(struct zx_sa11_Assertion_s* x, struct zx_str* y) { x->MajorVersion = y; }
/* FUNC(zx_sa11_Assertion_GET_MinorVersion) */
struct zx_str* zx_sa11_Assertion_GET_MinorVersion(struct zx_sa11_Assertion_s* x) { return x->MinorVersion; }
/* FUNC(zx_sa11_Assertion_PUT_MinorVersion) */
void zx_sa11_Assertion_PUT_MinorVersion(struct zx_sa11_Assertion_s* x, struct zx_str* y) { x->MinorVersion = y; }







#ifdef ZX_ENA_GETPUT

/* FUNC(zx_sa11_Attribute_NUM_AttributeValue) */

int zx_sa11_Attribute_NUM_AttributeValue(struct zx_sa11_Attribute_s* x)
{
  struct zx_sa11_AttributeValue_s* y;
  int n = 0;
  if (!x) return 0;
  for (y = x->AttributeValue; y; ++n, y = (struct zx_sa11_AttributeValue_s*)y->gg.g.n) ;
  return n;
}

/* FUNC(zx_sa11_Attribute_GET_AttributeValue) */

struct zx_sa11_AttributeValue_s* zx_sa11_Attribute_GET_AttributeValue(struct zx_sa11_Attribute_s* x, int n)
{
  struct zx_sa11_AttributeValue_s* y;
  if (!x) return 0;
  for (y = x->AttributeValue; n>=0 && y; --n, y = (struct zx_sa11_AttributeValue_s*)y->gg.g.n) ;
  return y;
}

/* FUNC(zx_sa11_Attribute_POP_AttributeValue) */

struct zx_sa11_AttributeValue_s* zx_sa11_Attribute_POP_AttributeValue(struct zx_sa11_Attribute_s* x)
{
  struct zx_sa11_AttributeValue_s* y;
  if (!x) return 0;
  y = x->AttributeValue;
  if (y)
    x->AttributeValue = (struct zx_sa11_AttributeValue_s*)y->gg.g.n;
  return y;
}

/* FUNC(zx_sa11_Attribute_PUSH_AttributeValue) */

void zx_sa11_Attribute_PUSH_AttributeValue(struct zx_sa11_Attribute_s* x, struct zx_sa11_AttributeValue_s* z)
{
  if (!x || !z) return;
  z->gg.g.n = &x->AttributeValue->gg.g;
  x->AttributeValue = z;
}

/* FUNC(zx_sa11_Attribute_REV_AttributeValue) */

void zx_sa11_Attribute_REV_AttributeValue(struct zx_sa11_Attribute_s* x)
{
  struct zx_sa11_AttributeValue_s* nxt;
  struct zx_sa11_AttributeValue_s* y;
  if (!x) return;
  y = x->AttributeValue;
  if (!y) return;
  x->AttributeValue = 0;
  while (y) {
    nxt = (struct zx_sa11_AttributeValue_s*)y->gg.g.n;
    y->gg.g.n = &x->AttributeValue->gg.g;
    x->AttributeValue = y;
    y = nxt;
  }
}

/* FUNC(zx_sa11_Attribute_PUT_AttributeValue) */

void zx_sa11_Attribute_PUT_AttributeValue(struct zx_sa11_Attribute_s* x, int n, struct zx_sa11_AttributeValue_s* z)
{
  struct zx_sa11_AttributeValue_s* y;
  if (!x || !z) return;
  y = x->AttributeValue;
  if (!y) return;
  switch (n) {
  case 0:
    z->gg.g.n = y->gg.g.n;
    x->AttributeValue = z;
    return;
  default:
    for (; n > 1 && y->gg.g.n; --n, y = (struct zx_sa11_AttributeValue_s*)y->gg.g.n) ;
    if (!y->gg.g.n) return;
    z->gg.g.n = y->gg.g.n->n;
    y->gg.g.n = &z->gg.g;
  }
}

/* FUNC(zx_sa11_Attribute_ADD_AttributeValue) */

void zx_sa11_Attribute_ADD_AttributeValue(struct zx_sa11_Attribute_s* x, int n, struct zx_sa11_AttributeValue_s* z)
{
  struct zx_sa11_AttributeValue_s* y;
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
    for (; y->gg.g.n; y = (struct zx_sa11_AttributeValue_s*)y->gg.g.n) ;
    break;
  default:
    for (y = x->AttributeValue; n > 1 && y; --n, y = (struct zx_sa11_AttributeValue_s*)y->gg.g.n) ;
    if (!y) return;
  }
  z->gg.g.n = y->gg.g.n;
  y->gg.g.n = &z->gg.g;
}

/* FUNC(zx_sa11_Attribute_DEL_AttributeValue) */

void zx_sa11_Attribute_DEL_AttributeValue(struct zx_sa11_Attribute_s* x, int n)
{
  struct zx_sa11_AttributeValue_s* y;
  if (!x) return;
  switch (n) {
  case 0:
    x->AttributeValue = (struct zx_sa11_AttributeValue_s*)x->AttributeValue->gg.g.n;
    return;
  case -1:
    y = (struct zx_sa11_AttributeValue_s*)x->AttributeValue;
    if (!y) return;
    for (; y->gg.g.n; y = (struct zx_sa11_AttributeValue_s*)y->gg.g.n) ;
    break;
  default:
    for (y = x->AttributeValue; n > 1 && y->gg.g.n; --n, y = (struct zx_sa11_AttributeValue_s*)y->gg.g.n) ;
    if (!y->gg.g.n) return;
  }
  y->gg.g.n = y->gg.g.n->n;
}

#endif

/* FUNC(zx_sa11_Attribute_GET_AttributeName) */
struct zx_str* zx_sa11_Attribute_GET_AttributeName(struct zx_sa11_Attribute_s* x) { return x->AttributeName; }
/* FUNC(zx_sa11_Attribute_PUT_AttributeName) */
void zx_sa11_Attribute_PUT_AttributeName(struct zx_sa11_Attribute_s* x, struct zx_str* y) { x->AttributeName = y; }
/* FUNC(zx_sa11_Attribute_GET_AttributeNamespace) */
struct zx_str* zx_sa11_Attribute_GET_AttributeNamespace(struct zx_sa11_Attribute_s* x) { return x->AttributeNamespace; }
/* FUNC(zx_sa11_Attribute_PUT_AttributeNamespace) */
void zx_sa11_Attribute_PUT_AttributeNamespace(struct zx_sa11_Attribute_s* x, struct zx_str* y) { x->AttributeNamespace = y; }





/* FUNC(zx_sa11_AttributeDesignator_GET_AttributeName) */
struct zx_str* zx_sa11_AttributeDesignator_GET_AttributeName(struct zx_sa11_AttributeDesignator_s* x) { return x->AttributeName; }
/* FUNC(zx_sa11_AttributeDesignator_PUT_AttributeName) */
void zx_sa11_AttributeDesignator_PUT_AttributeName(struct zx_sa11_AttributeDesignator_s* x, struct zx_str* y) { x->AttributeName = y; }
/* FUNC(zx_sa11_AttributeDesignator_GET_AttributeNamespace) */
struct zx_str* zx_sa11_AttributeDesignator_GET_AttributeNamespace(struct zx_sa11_AttributeDesignator_s* x) { return x->AttributeNamespace; }
/* FUNC(zx_sa11_AttributeDesignator_PUT_AttributeNamespace) */
void zx_sa11_AttributeDesignator_PUT_AttributeNamespace(struct zx_sa11_AttributeDesignator_s* x, struct zx_str* y) { x->AttributeNamespace = y; }







#ifdef ZX_ENA_GETPUT

/* FUNC(zx_sa11_AttributeStatement_NUM_Subject) */

int zx_sa11_AttributeStatement_NUM_Subject(struct zx_sa11_AttributeStatement_s* x)
{
  struct zx_sa11_Subject_s* y;
  int n = 0;
  if (!x) return 0;
  for (y = x->Subject; y; ++n, y = (struct zx_sa11_Subject_s*)y->gg.g.n) ;
  return n;
}

/* FUNC(zx_sa11_AttributeStatement_GET_Subject) */

struct zx_sa11_Subject_s* zx_sa11_AttributeStatement_GET_Subject(struct zx_sa11_AttributeStatement_s* x, int n)
{
  struct zx_sa11_Subject_s* y;
  if (!x) return 0;
  for (y = x->Subject; n>=0 && y; --n, y = (struct zx_sa11_Subject_s*)y->gg.g.n) ;
  return y;
}

/* FUNC(zx_sa11_AttributeStatement_POP_Subject) */

struct zx_sa11_Subject_s* zx_sa11_AttributeStatement_POP_Subject(struct zx_sa11_AttributeStatement_s* x)
{
  struct zx_sa11_Subject_s* y;
  if (!x) return 0;
  y = x->Subject;
  if (y)
    x->Subject = (struct zx_sa11_Subject_s*)y->gg.g.n;
  return y;
}

/* FUNC(zx_sa11_AttributeStatement_PUSH_Subject) */

void zx_sa11_AttributeStatement_PUSH_Subject(struct zx_sa11_AttributeStatement_s* x, struct zx_sa11_Subject_s* z)
{
  if (!x || !z) return;
  z->gg.g.n = &x->Subject->gg.g;
  x->Subject = z;
}

/* FUNC(zx_sa11_AttributeStatement_REV_Subject) */

void zx_sa11_AttributeStatement_REV_Subject(struct zx_sa11_AttributeStatement_s* x)
{
  struct zx_sa11_Subject_s* nxt;
  struct zx_sa11_Subject_s* y;
  if (!x) return;
  y = x->Subject;
  if (!y) return;
  x->Subject = 0;
  while (y) {
    nxt = (struct zx_sa11_Subject_s*)y->gg.g.n;
    y->gg.g.n = &x->Subject->gg.g;
    x->Subject = y;
    y = nxt;
  }
}

/* FUNC(zx_sa11_AttributeStatement_PUT_Subject) */

void zx_sa11_AttributeStatement_PUT_Subject(struct zx_sa11_AttributeStatement_s* x, int n, struct zx_sa11_Subject_s* z)
{
  struct zx_sa11_Subject_s* y;
  if (!x || !z) return;
  y = x->Subject;
  if (!y) return;
  switch (n) {
  case 0:
    z->gg.g.n = y->gg.g.n;
    x->Subject = z;
    return;
  default:
    for (; n > 1 && y->gg.g.n; --n, y = (struct zx_sa11_Subject_s*)y->gg.g.n) ;
    if (!y->gg.g.n) return;
    z->gg.g.n = y->gg.g.n->n;
    y->gg.g.n = &z->gg.g;
  }
}

/* FUNC(zx_sa11_AttributeStatement_ADD_Subject) */

void zx_sa11_AttributeStatement_ADD_Subject(struct zx_sa11_AttributeStatement_s* x, int n, struct zx_sa11_Subject_s* z)
{
  struct zx_sa11_Subject_s* y;
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
    for (; y->gg.g.n; y = (struct zx_sa11_Subject_s*)y->gg.g.n) ;
    break;
  default:
    for (y = x->Subject; n > 1 && y; --n, y = (struct zx_sa11_Subject_s*)y->gg.g.n) ;
    if (!y) return;
  }
  z->gg.g.n = y->gg.g.n;
  y->gg.g.n = &z->gg.g;
}

/* FUNC(zx_sa11_AttributeStatement_DEL_Subject) */

void zx_sa11_AttributeStatement_DEL_Subject(struct zx_sa11_AttributeStatement_s* x, int n)
{
  struct zx_sa11_Subject_s* y;
  if (!x) return;
  switch (n) {
  case 0:
    x->Subject = (struct zx_sa11_Subject_s*)x->Subject->gg.g.n;
    return;
  case -1:
    y = (struct zx_sa11_Subject_s*)x->Subject;
    if (!y) return;
    for (; y->gg.g.n; y = (struct zx_sa11_Subject_s*)y->gg.g.n) ;
    break;
  default:
    for (y = x->Subject; n > 1 && y->gg.g.n; --n, y = (struct zx_sa11_Subject_s*)y->gg.g.n) ;
    if (!y->gg.g.n) return;
  }
  y->gg.g.n = y->gg.g.n->n;
}

#endif



#ifdef ZX_ENA_GETPUT

/* FUNC(zx_sa11_AttributeStatement_NUM_Attribute) */

int zx_sa11_AttributeStatement_NUM_Attribute(struct zx_sa11_AttributeStatement_s* x)
{
  struct zx_sa11_Attribute_s* y;
  int n = 0;
  if (!x) return 0;
  for (y = x->Attribute; y; ++n, y = (struct zx_sa11_Attribute_s*)y->gg.g.n) ;
  return n;
}

/* FUNC(zx_sa11_AttributeStatement_GET_Attribute) */

struct zx_sa11_Attribute_s* zx_sa11_AttributeStatement_GET_Attribute(struct zx_sa11_AttributeStatement_s* x, int n)
{
  struct zx_sa11_Attribute_s* y;
  if (!x) return 0;
  for (y = x->Attribute; n>=0 && y; --n, y = (struct zx_sa11_Attribute_s*)y->gg.g.n) ;
  return y;
}

/* FUNC(zx_sa11_AttributeStatement_POP_Attribute) */

struct zx_sa11_Attribute_s* zx_sa11_AttributeStatement_POP_Attribute(struct zx_sa11_AttributeStatement_s* x)
{
  struct zx_sa11_Attribute_s* y;
  if (!x) return 0;
  y = x->Attribute;
  if (y)
    x->Attribute = (struct zx_sa11_Attribute_s*)y->gg.g.n;
  return y;
}

/* FUNC(zx_sa11_AttributeStatement_PUSH_Attribute) */

void zx_sa11_AttributeStatement_PUSH_Attribute(struct zx_sa11_AttributeStatement_s* x, struct zx_sa11_Attribute_s* z)
{
  if (!x || !z) return;
  z->gg.g.n = &x->Attribute->gg.g;
  x->Attribute = z;
}

/* FUNC(zx_sa11_AttributeStatement_REV_Attribute) */

void zx_sa11_AttributeStatement_REV_Attribute(struct zx_sa11_AttributeStatement_s* x)
{
  struct zx_sa11_Attribute_s* nxt;
  struct zx_sa11_Attribute_s* y;
  if (!x) return;
  y = x->Attribute;
  if (!y) return;
  x->Attribute = 0;
  while (y) {
    nxt = (struct zx_sa11_Attribute_s*)y->gg.g.n;
    y->gg.g.n = &x->Attribute->gg.g;
    x->Attribute = y;
    y = nxt;
  }
}

/* FUNC(zx_sa11_AttributeStatement_PUT_Attribute) */

void zx_sa11_AttributeStatement_PUT_Attribute(struct zx_sa11_AttributeStatement_s* x, int n, struct zx_sa11_Attribute_s* z)
{
  struct zx_sa11_Attribute_s* y;
  if (!x || !z) return;
  y = x->Attribute;
  if (!y) return;
  switch (n) {
  case 0:
    z->gg.g.n = y->gg.g.n;
    x->Attribute = z;
    return;
  default:
    for (; n > 1 && y->gg.g.n; --n, y = (struct zx_sa11_Attribute_s*)y->gg.g.n) ;
    if (!y->gg.g.n) return;
    z->gg.g.n = y->gg.g.n->n;
    y->gg.g.n = &z->gg.g;
  }
}

/* FUNC(zx_sa11_AttributeStatement_ADD_Attribute) */

void zx_sa11_AttributeStatement_ADD_Attribute(struct zx_sa11_AttributeStatement_s* x, int n, struct zx_sa11_Attribute_s* z)
{
  struct zx_sa11_Attribute_s* y;
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
    for (; y->gg.g.n; y = (struct zx_sa11_Attribute_s*)y->gg.g.n) ;
    break;
  default:
    for (y = x->Attribute; n > 1 && y; --n, y = (struct zx_sa11_Attribute_s*)y->gg.g.n) ;
    if (!y) return;
  }
  z->gg.g.n = y->gg.g.n;
  y->gg.g.n = &z->gg.g;
}

/* FUNC(zx_sa11_AttributeStatement_DEL_Attribute) */

void zx_sa11_AttributeStatement_DEL_Attribute(struct zx_sa11_AttributeStatement_s* x, int n)
{
  struct zx_sa11_Attribute_s* y;
  if (!x) return;
  switch (n) {
  case 0:
    x->Attribute = (struct zx_sa11_Attribute_s*)x->Attribute->gg.g.n;
    return;
  case -1:
    y = (struct zx_sa11_Attribute_s*)x->Attribute;
    if (!y) return;
    for (; y->gg.g.n; y = (struct zx_sa11_Attribute_s*)y->gg.g.n) ;
    break;
  default:
    for (y = x->Attribute; n > 1 && y->gg.g.n; --n, y = (struct zx_sa11_Attribute_s*)y->gg.g.n) ;
    if (!y->gg.g.n) return;
  }
  y->gg.g.n = y->gg.g.n->n;
}

#endif








#ifdef ZX_ENA_GETPUT

/* FUNC(zx_sa11_AttributeValue_NUM_ResourceOffering) */

int zx_sa11_AttributeValue_NUM_ResourceOffering(struct zx_sa11_AttributeValue_s* x)
{
  struct zx_di12_ResourceOffering_s* y;
  int n = 0;
  if (!x) return 0;
  for (y = x->ResourceOffering; y; ++n, y = (struct zx_di12_ResourceOffering_s*)y->gg.g.n) ;
  return n;
}

/* FUNC(zx_sa11_AttributeValue_GET_ResourceOffering) */

struct zx_di12_ResourceOffering_s* zx_sa11_AttributeValue_GET_ResourceOffering(struct zx_sa11_AttributeValue_s* x, int n)
{
  struct zx_di12_ResourceOffering_s* y;
  if (!x) return 0;
  for (y = x->ResourceOffering; n>=0 && y; --n, y = (struct zx_di12_ResourceOffering_s*)y->gg.g.n) ;
  return y;
}

/* FUNC(zx_sa11_AttributeValue_POP_ResourceOffering) */

struct zx_di12_ResourceOffering_s* zx_sa11_AttributeValue_POP_ResourceOffering(struct zx_sa11_AttributeValue_s* x)
{
  struct zx_di12_ResourceOffering_s* y;
  if (!x) return 0;
  y = x->ResourceOffering;
  if (y)
    x->ResourceOffering = (struct zx_di12_ResourceOffering_s*)y->gg.g.n;
  return y;
}

/* FUNC(zx_sa11_AttributeValue_PUSH_ResourceOffering) */

void zx_sa11_AttributeValue_PUSH_ResourceOffering(struct zx_sa11_AttributeValue_s* x, struct zx_di12_ResourceOffering_s* z)
{
  if (!x || !z) return;
  z->gg.g.n = &x->ResourceOffering->gg.g;
  x->ResourceOffering = z;
}

/* FUNC(zx_sa11_AttributeValue_REV_ResourceOffering) */

void zx_sa11_AttributeValue_REV_ResourceOffering(struct zx_sa11_AttributeValue_s* x)
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

/* FUNC(zx_sa11_AttributeValue_PUT_ResourceOffering) */

void zx_sa11_AttributeValue_PUT_ResourceOffering(struct zx_sa11_AttributeValue_s* x, int n, struct zx_di12_ResourceOffering_s* z)
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

/* FUNC(zx_sa11_AttributeValue_ADD_ResourceOffering) */

void zx_sa11_AttributeValue_ADD_ResourceOffering(struct zx_sa11_AttributeValue_s* x, int n, struct zx_di12_ResourceOffering_s* z)
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

/* FUNC(zx_sa11_AttributeValue_DEL_ResourceOffering) */

void zx_sa11_AttributeValue_DEL_ResourceOffering(struct zx_sa11_AttributeValue_s* x, int n)
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

/* FUNC(zx_sa11_AttributeValue_NUM_EndpointReference) */

int zx_sa11_AttributeValue_NUM_EndpointReference(struct zx_sa11_AttributeValue_s* x)
{
  struct zx_a_EndpointReference_s* y;
  int n = 0;
  if (!x) return 0;
  for (y = x->EndpointReference; y; ++n, y = (struct zx_a_EndpointReference_s*)y->gg.g.n) ;
  return n;
}

/* FUNC(zx_sa11_AttributeValue_GET_EndpointReference) */

struct zx_a_EndpointReference_s* zx_sa11_AttributeValue_GET_EndpointReference(struct zx_sa11_AttributeValue_s* x, int n)
{
  struct zx_a_EndpointReference_s* y;
  if (!x) return 0;
  for (y = x->EndpointReference; n>=0 && y; --n, y = (struct zx_a_EndpointReference_s*)y->gg.g.n) ;
  return y;
}

/* FUNC(zx_sa11_AttributeValue_POP_EndpointReference) */

struct zx_a_EndpointReference_s* zx_sa11_AttributeValue_POP_EndpointReference(struct zx_sa11_AttributeValue_s* x)
{
  struct zx_a_EndpointReference_s* y;
  if (!x) return 0;
  y = x->EndpointReference;
  if (y)
    x->EndpointReference = (struct zx_a_EndpointReference_s*)y->gg.g.n;
  return y;
}

/* FUNC(zx_sa11_AttributeValue_PUSH_EndpointReference) */

void zx_sa11_AttributeValue_PUSH_EndpointReference(struct zx_sa11_AttributeValue_s* x, struct zx_a_EndpointReference_s* z)
{
  if (!x || !z) return;
  z->gg.g.n = &x->EndpointReference->gg.g;
  x->EndpointReference = z;
}

/* FUNC(zx_sa11_AttributeValue_REV_EndpointReference) */

void zx_sa11_AttributeValue_REV_EndpointReference(struct zx_sa11_AttributeValue_s* x)
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

/* FUNC(zx_sa11_AttributeValue_PUT_EndpointReference) */

void zx_sa11_AttributeValue_PUT_EndpointReference(struct zx_sa11_AttributeValue_s* x, int n, struct zx_a_EndpointReference_s* z)
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

/* FUNC(zx_sa11_AttributeValue_ADD_EndpointReference) */

void zx_sa11_AttributeValue_ADD_EndpointReference(struct zx_sa11_AttributeValue_s* x, int n, struct zx_a_EndpointReference_s* z)
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

/* FUNC(zx_sa11_AttributeValue_DEL_EndpointReference) */

void zx_sa11_AttributeValue_DEL_EndpointReference(struct zx_sa11_AttributeValue_s* x, int n)
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

/* FUNC(zx_sa11_AudienceRestrictionCondition_NUM_Audience) */

int zx_sa11_AudienceRestrictionCondition_NUM_Audience(struct zx_sa11_AudienceRestrictionCondition_s* x)
{
  struct zx_elem_s* y;
  int n = 0;
  if (!x) return 0;
  for (y = x->Audience; y; ++n, y = (struct zx_elem_s*)y->g.n) ;
  return n;
}

/* FUNC(zx_sa11_AudienceRestrictionCondition_GET_Audience) */

struct zx_elem_s* zx_sa11_AudienceRestrictionCondition_GET_Audience(struct zx_sa11_AudienceRestrictionCondition_s* x, int n)
{
  struct zx_elem_s* y;
  if (!x) return 0;
  for (y = x->Audience; n>=0 && y; --n, y = (struct zx_elem_s*)y->g.n) ;
  return y;
}

/* FUNC(zx_sa11_AudienceRestrictionCondition_POP_Audience) */

struct zx_elem_s* zx_sa11_AudienceRestrictionCondition_POP_Audience(struct zx_sa11_AudienceRestrictionCondition_s* x)
{
  struct zx_elem_s* y;
  if (!x) return 0;
  y = x->Audience;
  if (y)
    x->Audience = (struct zx_elem_s*)y->g.n;
  return y;
}

/* FUNC(zx_sa11_AudienceRestrictionCondition_PUSH_Audience) */

void zx_sa11_AudienceRestrictionCondition_PUSH_Audience(struct zx_sa11_AudienceRestrictionCondition_s* x, struct zx_elem_s* z)
{
  if (!x || !z) return;
  z->g.n = &x->Audience->g;
  x->Audience = z;
}

/* FUNC(zx_sa11_AudienceRestrictionCondition_REV_Audience) */

void zx_sa11_AudienceRestrictionCondition_REV_Audience(struct zx_sa11_AudienceRestrictionCondition_s* x)
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

/* FUNC(zx_sa11_AudienceRestrictionCondition_PUT_Audience) */

void zx_sa11_AudienceRestrictionCondition_PUT_Audience(struct zx_sa11_AudienceRestrictionCondition_s* x, int n, struct zx_elem_s* z)
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

/* FUNC(zx_sa11_AudienceRestrictionCondition_ADD_Audience) */

void zx_sa11_AudienceRestrictionCondition_ADD_Audience(struct zx_sa11_AudienceRestrictionCondition_s* x, int n, struct zx_elem_s* z)
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

/* FUNC(zx_sa11_AudienceRestrictionCondition_DEL_Audience) */

void zx_sa11_AudienceRestrictionCondition_DEL_Audience(struct zx_sa11_AudienceRestrictionCondition_s* x, int n)
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

/* FUNC(zx_sa11_AuthenticationStatement_NUM_Subject) */

int zx_sa11_AuthenticationStatement_NUM_Subject(struct zx_sa11_AuthenticationStatement_s* x)
{
  struct zx_sa11_Subject_s* y;
  int n = 0;
  if (!x) return 0;
  for (y = x->Subject; y; ++n, y = (struct zx_sa11_Subject_s*)y->gg.g.n) ;
  return n;
}

/* FUNC(zx_sa11_AuthenticationStatement_GET_Subject) */

struct zx_sa11_Subject_s* zx_sa11_AuthenticationStatement_GET_Subject(struct zx_sa11_AuthenticationStatement_s* x, int n)
{
  struct zx_sa11_Subject_s* y;
  if (!x) return 0;
  for (y = x->Subject; n>=0 && y; --n, y = (struct zx_sa11_Subject_s*)y->gg.g.n) ;
  return y;
}

/* FUNC(zx_sa11_AuthenticationStatement_POP_Subject) */

struct zx_sa11_Subject_s* zx_sa11_AuthenticationStatement_POP_Subject(struct zx_sa11_AuthenticationStatement_s* x)
{
  struct zx_sa11_Subject_s* y;
  if (!x) return 0;
  y = x->Subject;
  if (y)
    x->Subject = (struct zx_sa11_Subject_s*)y->gg.g.n;
  return y;
}

/* FUNC(zx_sa11_AuthenticationStatement_PUSH_Subject) */

void zx_sa11_AuthenticationStatement_PUSH_Subject(struct zx_sa11_AuthenticationStatement_s* x, struct zx_sa11_Subject_s* z)
{
  if (!x || !z) return;
  z->gg.g.n = &x->Subject->gg.g;
  x->Subject = z;
}

/* FUNC(zx_sa11_AuthenticationStatement_REV_Subject) */

void zx_sa11_AuthenticationStatement_REV_Subject(struct zx_sa11_AuthenticationStatement_s* x)
{
  struct zx_sa11_Subject_s* nxt;
  struct zx_sa11_Subject_s* y;
  if (!x) return;
  y = x->Subject;
  if (!y) return;
  x->Subject = 0;
  while (y) {
    nxt = (struct zx_sa11_Subject_s*)y->gg.g.n;
    y->gg.g.n = &x->Subject->gg.g;
    x->Subject = y;
    y = nxt;
  }
}

/* FUNC(zx_sa11_AuthenticationStatement_PUT_Subject) */

void zx_sa11_AuthenticationStatement_PUT_Subject(struct zx_sa11_AuthenticationStatement_s* x, int n, struct zx_sa11_Subject_s* z)
{
  struct zx_sa11_Subject_s* y;
  if (!x || !z) return;
  y = x->Subject;
  if (!y) return;
  switch (n) {
  case 0:
    z->gg.g.n = y->gg.g.n;
    x->Subject = z;
    return;
  default:
    for (; n > 1 && y->gg.g.n; --n, y = (struct zx_sa11_Subject_s*)y->gg.g.n) ;
    if (!y->gg.g.n) return;
    z->gg.g.n = y->gg.g.n->n;
    y->gg.g.n = &z->gg.g;
  }
}

/* FUNC(zx_sa11_AuthenticationStatement_ADD_Subject) */

void zx_sa11_AuthenticationStatement_ADD_Subject(struct zx_sa11_AuthenticationStatement_s* x, int n, struct zx_sa11_Subject_s* z)
{
  struct zx_sa11_Subject_s* y;
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
    for (; y->gg.g.n; y = (struct zx_sa11_Subject_s*)y->gg.g.n) ;
    break;
  default:
    for (y = x->Subject; n > 1 && y; --n, y = (struct zx_sa11_Subject_s*)y->gg.g.n) ;
    if (!y) return;
  }
  z->gg.g.n = y->gg.g.n;
  y->gg.g.n = &z->gg.g;
}

/* FUNC(zx_sa11_AuthenticationStatement_DEL_Subject) */

void zx_sa11_AuthenticationStatement_DEL_Subject(struct zx_sa11_AuthenticationStatement_s* x, int n)
{
  struct zx_sa11_Subject_s* y;
  if (!x) return;
  switch (n) {
  case 0:
    x->Subject = (struct zx_sa11_Subject_s*)x->Subject->gg.g.n;
    return;
  case -1:
    y = (struct zx_sa11_Subject_s*)x->Subject;
    if (!y) return;
    for (; y->gg.g.n; y = (struct zx_sa11_Subject_s*)y->gg.g.n) ;
    break;
  default:
    for (y = x->Subject; n > 1 && y->gg.g.n; --n, y = (struct zx_sa11_Subject_s*)y->gg.g.n) ;
    if (!y->gg.g.n) return;
  }
  y->gg.g.n = y->gg.g.n->n;
}

#endif



#ifdef ZX_ENA_GETPUT

/* FUNC(zx_sa11_AuthenticationStatement_NUM_SubjectLocality) */

int zx_sa11_AuthenticationStatement_NUM_SubjectLocality(struct zx_sa11_AuthenticationStatement_s* x)
{
  struct zx_sa11_SubjectLocality_s* y;
  int n = 0;
  if (!x) return 0;
  for (y = x->SubjectLocality; y; ++n, y = (struct zx_sa11_SubjectLocality_s*)y->gg.g.n) ;
  return n;
}

/* FUNC(zx_sa11_AuthenticationStatement_GET_SubjectLocality) */

struct zx_sa11_SubjectLocality_s* zx_sa11_AuthenticationStatement_GET_SubjectLocality(struct zx_sa11_AuthenticationStatement_s* x, int n)
{
  struct zx_sa11_SubjectLocality_s* y;
  if (!x) return 0;
  for (y = x->SubjectLocality; n>=0 && y; --n, y = (struct zx_sa11_SubjectLocality_s*)y->gg.g.n) ;
  return y;
}

/* FUNC(zx_sa11_AuthenticationStatement_POP_SubjectLocality) */

struct zx_sa11_SubjectLocality_s* zx_sa11_AuthenticationStatement_POP_SubjectLocality(struct zx_sa11_AuthenticationStatement_s* x)
{
  struct zx_sa11_SubjectLocality_s* y;
  if (!x) return 0;
  y = x->SubjectLocality;
  if (y)
    x->SubjectLocality = (struct zx_sa11_SubjectLocality_s*)y->gg.g.n;
  return y;
}

/* FUNC(zx_sa11_AuthenticationStatement_PUSH_SubjectLocality) */

void zx_sa11_AuthenticationStatement_PUSH_SubjectLocality(struct zx_sa11_AuthenticationStatement_s* x, struct zx_sa11_SubjectLocality_s* z)
{
  if (!x || !z) return;
  z->gg.g.n = &x->SubjectLocality->gg.g;
  x->SubjectLocality = z;
}

/* FUNC(zx_sa11_AuthenticationStatement_REV_SubjectLocality) */

void zx_sa11_AuthenticationStatement_REV_SubjectLocality(struct zx_sa11_AuthenticationStatement_s* x)
{
  struct zx_sa11_SubjectLocality_s* nxt;
  struct zx_sa11_SubjectLocality_s* y;
  if (!x) return;
  y = x->SubjectLocality;
  if (!y) return;
  x->SubjectLocality = 0;
  while (y) {
    nxt = (struct zx_sa11_SubjectLocality_s*)y->gg.g.n;
    y->gg.g.n = &x->SubjectLocality->gg.g;
    x->SubjectLocality = y;
    y = nxt;
  }
}

/* FUNC(zx_sa11_AuthenticationStatement_PUT_SubjectLocality) */

void zx_sa11_AuthenticationStatement_PUT_SubjectLocality(struct zx_sa11_AuthenticationStatement_s* x, int n, struct zx_sa11_SubjectLocality_s* z)
{
  struct zx_sa11_SubjectLocality_s* y;
  if (!x || !z) return;
  y = x->SubjectLocality;
  if (!y) return;
  switch (n) {
  case 0:
    z->gg.g.n = y->gg.g.n;
    x->SubjectLocality = z;
    return;
  default:
    for (; n > 1 && y->gg.g.n; --n, y = (struct zx_sa11_SubjectLocality_s*)y->gg.g.n) ;
    if (!y->gg.g.n) return;
    z->gg.g.n = y->gg.g.n->n;
    y->gg.g.n = &z->gg.g;
  }
}

/* FUNC(zx_sa11_AuthenticationStatement_ADD_SubjectLocality) */

void zx_sa11_AuthenticationStatement_ADD_SubjectLocality(struct zx_sa11_AuthenticationStatement_s* x, int n, struct zx_sa11_SubjectLocality_s* z)
{
  struct zx_sa11_SubjectLocality_s* y;
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
    for (; y->gg.g.n; y = (struct zx_sa11_SubjectLocality_s*)y->gg.g.n) ;
    break;
  default:
    for (y = x->SubjectLocality; n > 1 && y; --n, y = (struct zx_sa11_SubjectLocality_s*)y->gg.g.n) ;
    if (!y) return;
  }
  z->gg.g.n = y->gg.g.n;
  y->gg.g.n = &z->gg.g;
}

/* FUNC(zx_sa11_AuthenticationStatement_DEL_SubjectLocality) */

void zx_sa11_AuthenticationStatement_DEL_SubjectLocality(struct zx_sa11_AuthenticationStatement_s* x, int n)
{
  struct zx_sa11_SubjectLocality_s* y;
  if (!x) return;
  switch (n) {
  case 0:
    x->SubjectLocality = (struct zx_sa11_SubjectLocality_s*)x->SubjectLocality->gg.g.n;
    return;
  case -1:
    y = (struct zx_sa11_SubjectLocality_s*)x->SubjectLocality;
    if (!y) return;
    for (; y->gg.g.n; y = (struct zx_sa11_SubjectLocality_s*)y->gg.g.n) ;
    break;
  default:
    for (y = x->SubjectLocality; n > 1 && y->gg.g.n; --n, y = (struct zx_sa11_SubjectLocality_s*)y->gg.g.n) ;
    if (!y->gg.g.n) return;
  }
  y->gg.g.n = y->gg.g.n->n;
}

#endif



#ifdef ZX_ENA_GETPUT

/* FUNC(zx_sa11_AuthenticationStatement_NUM_AuthorityBinding) */

int zx_sa11_AuthenticationStatement_NUM_AuthorityBinding(struct zx_sa11_AuthenticationStatement_s* x)
{
  struct zx_sa11_AuthorityBinding_s* y;
  int n = 0;
  if (!x) return 0;
  for (y = x->AuthorityBinding; y; ++n, y = (struct zx_sa11_AuthorityBinding_s*)y->gg.g.n) ;
  return n;
}

/* FUNC(zx_sa11_AuthenticationStatement_GET_AuthorityBinding) */

struct zx_sa11_AuthorityBinding_s* zx_sa11_AuthenticationStatement_GET_AuthorityBinding(struct zx_sa11_AuthenticationStatement_s* x, int n)
{
  struct zx_sa11_AuthorityBinding_s* y;
  if (!x) return 0;
  for (y = x->AuthorityBinding; n>=0 && y; --n, y = (struct zx_sa11_AuthorityBinding_s*)y->gg.g.n) ;
  return y;
}

/* FUNC(zx_sa11_AuthenticationStatement_POP_AuthorityBinding) */

struct zx_sa11_AuthorityBinding_s* zx_sa11_AuthenticationStatement_POP_AuthorityBinding(struct zx_sa11_AuthenticationStatement_s* x)
{
  struct zx_sa11_AuthorityBinding_s* y;
  if (!x) return 0;
  y = x->AuthorityBinding;
  if (y)
    x->AuthorityBinding = (struct zx_sa11_AuthorityBinding_s*)y->gg.g.n;
  return y;
}

/* FUNC(zx_sa11_AuthenticationStatement_PUSH_AuthorityBinding) */

void zx_sa11_AuthenticationStatement_PUSH_AuthorityBinding(struct zx_sa11_AuthenticationStatement_s* x, struct zx_sa11_AuthorityBinding_s* z)
{
  if (!x || !z) return;
  z->gg.g.n = &x->AuthorityBinding->gg.g;
  x->AuthorityBinding = z;
}

/* FUNC(zx_sa11_AuthenticationStatement_REV_AuthorityBinding) */

void zx_sa11_AuthenticationStatement_REV_AuthorityBinding(struct zx_sa11_AuthenticationStatement_s* x)
{
  struct zx_sa11_AuthorityBinding_s* nxt;
  struct zx_sa11_AuthorityBinding_s* y;
  if (!x) return;
  y = x->AuthorityBinding;
  if (!y) return;
  x->AuthorityBinding = 0;
  while (y) {
    nxt = (struct zx_sa11_AuthorityBinding_s*)y->gg.g.n;
    y->gg.g.n = &x->AuthorityBinding->gg.g;
    x->AuthorityBinding = y;
    y = nxt;
  }
}

/* FUNC(zx_sa11_AuthenticationStatement_PUT_AuthorityBinding) */

void zx_sa11_AuthenticationStatement_PUT_AuthorityBinding(struct zx_sa11_AuthenticationStatement_s* x, int n, struct zx_sa11_AuthorityBinding_s* z)
{
  struct zx_sa11_AuthorityBinding_s* y;
  if (!x || !z) return;
  y = x->AuthorityBinding;
  if (!y) return;
  switch (n) {
  case 0:
    z->gg.g.n = y->gg.g.n;
    x->AuthorityBinding = z;
    return;
  default:
    for (; n > 1 && y->gg.g.n; --n, y = (struct zx_sa11_AuthorityBinding_s*)y->gg.g.n) ;
    if (!y->gg.g.n) return;
    z->gg.g.n = y->gg.g.n->n;
    y->gg.g.n = &z->gg.g;
  }
}

/* FUNC(zx_sa11_AuthenticationStatement_ADD_AuthorityBinding) */

void zx_sa11_AuthenticationStatement_ADD_AuthorityBinding(struct zx_sa11_AuthenticationStatement_s* x, int n, struct zx_sa11_AuthorityBinding_s* z)
{
  struct zx_sa11_AuthorityBinding_s* y;
  if (!x || !z) return;
  switch (n) {
  case 0:
  add_to_start:
    z->gg.g.n = &x->AuthorityBinding->gg.g;
    x->AuthorityBinding = z;
    return;
  case -1:
    y = x->AuthorityBinding;
    if (!y) goto add_to_start;
    for (; y->gg.g.n; y = (struct zx_sa11_AuthorityBinding_s*)y->gg.g.n) ;
    break;
  default:
    for (y = x->AuthorityBinding; n > 1 && y; --n, y = (struct zx_sa11_AuthorityBinding_s*)y->gg.g.n) ;
    if (!y) return;
  }
  z->gg.g.n = y->gg.g.n;
  y->gg.g.n = &z->gg.g;
}

/* FUNC(zx_sa11_AuthenticationStatement_DEL_AuthorityBinding) */

void zx_sa11_AuthenticationStatement_DEL_AuthorityBinding(struct zx_sa11_AuthenticationStatement_s* x, int n)
{
  struct zx_sa11_AuthorityBinding_s* y;
  if (!x) return;
  switch (n) {
  case 0:
    x->AuthorityBinding = (struct zx_sa11_AuthorityBinding_s*)x->AuthorityBinding->gg.g.n;
    return;
  case -1:
    y = (struct zx_sa11_AuthorityBinding_s*)x->AuthorityBinding;
    if (!y) return;
    for (; y->gg.g.n; y = (struct zx_sa11_AuthorityBinding_s*)y->gg.g.n) ;
    break;
  default:
    for (y = x->AuthorityBinding; n > 1 && y->gg.g.n; --n, y = (struct zx_sa11_AuthorityBinding_s*)y->gg.g.n) ;
    if (!y->gg.g.n) return;
  }
  y->gg.g.n = y->gg.g.n->n;
}

#endif

/* FUNC(zx_sa11_AuthenticationStatement_GET_AuthenticationInstant) */
struct zx_str* zx_sa11_AuthenticationStatement_GET_AuthenticationInstant(struct zx_sa11_AuthenticationStatement_s* x) { return x->AuthenticationInstant; }
/* FUNC(zx_sa11_AuthenticationStatement_PUT_AuthenticationInstant) */
void zx_sa11_AuthenticationStatement_PUT_AuthenticationInstant(struct zx_sa11_AuthenticationStatement_s* x, struct zx_str* y) { x->AuthenticationInstant = y; }
/* FUNC(zx_sa11_AuthenticationStatement_GET_AuthenticationMethod) */
struct zx_str* zx_sa11_AuthenticationStatement_GET_AuthenticationMethod(struct zx_sa11_AuthenticationStatement_s* x) { return x->AuthenticationMethod; }
/* FUNC(zx_sa11_AuthenticationStatement_PUT_AuthenticationMethod) */
void zx_sa11_AuthenticationStatement_PUT_AuthenticationMethod(struct zx_sa11_AuthenticationStatement_s* x, struct zx_str* y) { x->AuthenticationMethod = y; }





/* FUNC(zx_sa11_AuthorityBinding_GET_AuthorityKind) */
struct zx_str* zx_sa11_AuthorityBinding_GET_AuthorityKind(struct zx_sa11_AuthorityBinding_s* x) { return x->AuthorityKind; }
/* FUNC(zx_sa11_AuthorityBinding_PUT_AuthorityKind) */
void zx_sa11_AuthorityBinding_PUT_AuthorityKind(struct zx_sa11_AuthorityBinding_s* x, struct zx_str* y) { x->AuthorityKind = y; }
/* FUNC(zx_sa11_AuthorityBinding_GET_Binding) */
struct zx_str* zx_sa11_AuthorityBinding_GET_Binding(struct zx_sa11_AuthorityBinding_s* x) { return x->Binding; }
/* FUNC(zx_sa11_AuthorityBinding_PUT_Binding) */
void zx_sa11_AuthorityBinding_PUT_Binding(struct zx_sa11_AuthorityBinding_s* x, struct zx_str* y) { x->Binding = y; }
/* FUNC(zx_sa11_AuthorityBinding_GET_Location) */
struct zx_str* zx_sa11_AuthorityBinding_GET_Location(struct zx_sa11_AuthorityBinding_s* x) { return x->Location; }
/* FUNC(zx_sa11_AuthorityBinding_PUT_Location) */
void zx_sa11_AuthorityBinding_PUT_Location(struct zx_sa11_AuthorityBinding_s* x, struct zx_str* y) { x->Location = y; }







#ifdef ZX_ENA_GETPUT

/* FUNC(zx_sa11_AuthorizationDecisionStatement_NUM_Subject) */

int zx_sa11_AuthorizationDecisionStatement_NUM_Subject(struct zx_sa11_AuthorizationDecisionStatement_s* x)
{
  struct zx_sa11_Subject_s* y;
  int n = 0;
  if (!x) return 0;
  for (y = x->Subject; y; ++n, y = (struct zx_sa11_Subject_s*)y->gg.g.n) ;
  return n;
}

/* FUNC(zx_sa11_AuthorizationDecisionStatement_GET_Subject) */

struct zx_sa11_Subject_s* zx_sa11_AuthorizationDecisionStatement_GET_Subject(struct zx_sa11_AuthorizationDecisionStatement_s* x, int n)
{
  struct zx_sa11_Subject_s* y;
  if (!x) return 0;
  for (y = x->Subject; n>=0 && y; --n, y = (struct zx_sa11_Subject_s*)y->gg.g.n) ;
  return y;
}

/* FUNC(zx_sa11_AuthorizationDecisionStatement_POP_Subject) */

struct zx_sa11_Subject_s* zx_sa11_AuthorizationDecisionStatement_POP_Subject(struct zx_sa11_AuthorizationDecisionStatement_s* x)
{
  struct zx_sa11_Subject_s* y;
  if (!x) return 0;
  y = x->Subject;
  if (y)
    x->Subject = (struct zx_sa11_Subject_s*)y->gg.g.n;
  return y;
}

/* FUNC(zx_sa11_AuthorizationDecisionStatement_PUSH_Subject) */

void zx_sa11_AuthorizationDecisionStatement_PUSH_Subject(struct zx_sa11_AuthorizationDecisionStatement_s* x, struct zx_sa11_Subject_s* z)
{
  if (!x || !z) return;
  z->gg.g.n = &x->Subject->gg.g;
  x->Subject = z;
}

/* FUNC(zx_sa11_AuthorizationDecisionStatement_REV_Subject) */

void zx_sa11_AuthorizationDecisionStatement_REV_Subject(struct zx_sa11_AuthorizationDecisionStatement_s* x)
{
  struct zx_sa11_Subject_s* nxt;
  struct zx_sa11_Subject_s* y;
  if (!x) return;
  y = x->Subject;
  if (!y) return;
  x->Subject = 0;
  while (y) {
    nxt = (struct zx_sa11_Subject_s*)y->gg.g.n;
    y->gg.g.n = &x->Subject->gg.g;
    x->Subject = y;
    y = nxt;
  }
}

/* FUNC(zx_sa11_AuthorizationDecisionStatement_PUT_Subject) */

void zx_sa11_AuthorizationDecisionStatement_PUT_Subject(struct zx_sa11_AuthorizationDecisionStatement_s* x, int n, struct zx_sa11_Subject_s* z)
{
  struct zx_sa11_Subject_s* y;
  if (!x || !z) return;
  y = x->Subject;
  if (!y) return;
  switch (n) {
  case 0:
    z->gg.g.n = y->gg.g.n;
    x->Subject = z;
    return;
  default:
    for (; n > 1 && y->gg.g.n; --n, y = (struct zx_sa11_Subject_s*)y->gg.g.n) ;
    if (!y->gg.g.n) return;
    z->gg.g.n = y->gg.g.n->n;
    y->gg.g.n = &z->gg.g;
  }
}

/* FUNC(zx_sa11_AuthorizationDecisionStatement_ADD_Subject) */

void zx_sa11_AuthorizationDecisionStatement_ADD_Subject(struct zx_sa11_AuthorizationDecisionStatement_s* x, int n, struct zx_sa11_Subject_s* z)
{
  struct zx_sa11_Subject_s* y;
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
    for (; y->gg.g.n; y = (struct zx_sa11_Subject_s*)y->gg.g.n) ;
    break;
  default:
    for (y = x->Subject; n > 1 && y; --n, y = (struct zx_sa11_Subject_s*)y->gg.g.n) ;
    if (!y) return;
  }
  z->gg.g.n = y->gg.g.n;
  y->gg.g.n = &z->gg.g;
}

/* FUNC(zx_sa11_AuthorizationDecisionStatement_DEL_Subject) */

void zx_sa11_AuthorizationDecisionStatement_DEL_Subject(struct zx_sa11_AuthorizationDecisionStatement_s* x, int n)
{
  struct zx_sa11_Subject_s* y;
  if (!x) return;
  switch (n) {
  case 0:
    x->Subject = (struct zx_sa11_Subject_s*)x->Subject->gg.g.n;
    return;
  case -1:
    y = (struct zx_sa11_Subject_s*)x->Subject;
    if (!y) return;
    for (; y->gg.g.n; y = (struct zx_sa11_Subject_s*)y->gg.g.n) ;
    break;
  default:
    for (y = x->Subject; n > 1 && y->gg.g.n; --n, y = (struct zx_sa11_Subject_s*)y->gg.g.n) ;
    if (!y->gg.g.n) return;
  }
  y->gg.g.n = y->gg.g.n->n;
}

#endif



#ifdef ZX_ENA_GETPUT

/* FUNC(zx_sa11_AuthorizationDecisionStatement_NUM_Action) */

int zx_sa11_AuthorizationDecisionStatement_NUM_Action(struct zx_sa11_AuthorizationDecisionStatement_s* x)
{
  struct zx_sa11_Action_s* y;
  int n = 0;
  if (!x) return 0;
  for (y = x->Action; y; ++n, y = (struct zx_sa11_Action_s*)y->gg.g.n) ;
  return n;
}

/* FUNC(zx_sa11_AuthorizationDecisionStatement_GET_Action) */

struct zx_sa11_Action_s* zx_sa11_AuthorizationDecisionStatement_GET_Action(struct zx_sa11_AuthorizationDecisionStatement_s* x, int n)
{
  struct zx_sa11_Action_s* y;
  if (!x) return 0;
  for (y = x->Action; n>=0 && y; --n, y = (struct zx_sa11_Action_s*)y->gg.g.n) ;
  return y;
}

/* FUNC(zx_sa11_AuthorizationDecisionStatement_POP_Action) */

struct zx_sa11_Action_s* zx_sa11_AuthorizationDecisionStatement_POP_Action(struct zx_sa11_AuthorizationDecisionStatement_s* x)
{
  struct zx_sa11_Action_s* y;
  if (!x) return 0;
  y = x->Action;
  if (y)
    x->Action = (struct zx_sa11_Action_s*)y->gg.g.n;
  return y;
}

/* FUNC(zx_sa11_AuthorizationDecisionStatement_PUSH_Action) */

void zx_sa11_AuthorizationDecisionStatement_PUSH_Action(struct zx_sa11_AuthorizationDecisionStatement_s* x, struct zx_sa11_Action_s* z)
{
  if (!x || !z) return;
  z->gg.g.n = &x->Action->gg.g;
  x->Action = z;
}

/* FUNC(zx_sa11_AuthorizationDecisionStatement_REV_Action) */

void zx_sa11_AuthorizationDecisionStatement_REV_Action(struct zx_sa11_AuthorizationDecisionStatement_s* x)
{
  struct zx_sa11_Action_s* nxt;
  struct zx_sa11_Action_s* y;
  if (!x) return;
  y = x->Action;
  if (!y) return;
  x->Action = 0;
  while (y) {
    nxt = (struct zx_sa11_Action_s*)y->gg.g.n;
    y->gg.g.n = &x->Action->gg.g;
    x->Action = y;
    y = nxt;
  }
}

/* FUNC(zx_sa11_AuthorizationDecisionStatement_PUT_Action) */

void zx_sa11_AuthorizationDecisionStatement_PUT_Action(struct zx_sa11_AuthorizationDecisionStatement_s* x, int n, struct zx_sa11_Action_s* z)
{
  struct zx_sa11_Action_s* y;
  if (!x || !z) return;
  y = x->Action;
  if (!y) return;
  switch (n) {
  case 0:
    z->gg.g.n = y->gg.g.n;
    x->Action = z;
    return;
  default:
    for (; n > 1 && y->gg.g.n; --n, y = (struct zx_sa11_Action_s*)y->gg.g.n) ;
    if (!y->gg.g.n) return;
    z->gg.g.n = y->gg.g.n->n;
    y->gg.g.n = &z->gg.g;
  }
}

/* FUNC(zx_sa11_AuthorizationDecisionStatement_ADD_Action) */

void zx_sa11_AuthorizationDecisionStatement_ADD_Action(struct zx_sa11_AuthorizationDecisionStatement_s* x, int n, struct zx_sa11_Action_s* z)
{
  struct zx_sa11_Action_s* y;
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
    for (; y->gg.g.n; y = (struct zx_sa11_Action_s*)y->gg.g.n) ;
    break;
  default:
    for (y = x->Action; n > 1 && y; --n, y = (struct zx_sa11_Action_s*)y->gg.g.n) ;
    if (!y) return;
  }
  z->gg.g.n = y->gg.g.n;
  y->gg.g.n = &z->gg.g;
}

/* FUNC(zx_sa11_AuthorizationDecisionStatement_DEL_Action) */

void zx_sa11_AuthorizationDecisionStatement_DEL_Action(struct zx_sa11_AuthorizationDecisionStatement_s* x, int n)
{
  struct zx_sa11_Action_s* y;
  if (!x) return;
  switch (n) {
  case 0:
    x->Action = (struct zx_sa11_Action_s*)x->Action->gg.g.n;
    return;
  case -1:
    y = (struct zx_sa11_Action_s*)x->Action;
    if (!y) return;
    for (; y->gg.g.n; y = (struct zx_sa11_Action_s*)y->gg.g.n) ;
    break;
  default:
    for (y = x->Action; n > 1 && y->gg.g.n; --n, y = (struct zx_sa11_Action_s*)y->gg.g.n) ;
    if (!y->gg.g.n) return;
  }
  y->gg.g.n = y->gg.g.n->n;
}

#endif



#ifdef ZX_ENA_GETPUT

/* FUNC(zx_sa11_AuthorizationDecisionStatement_NUM_Evidence) */

int zx_sa11_AuthorizationDecisionStatement_NUM_Evidence(struct zx_sa11_AuthorizationDecisionStatement_s* x)
{
  struct zx_sa11_Evidence_s* y;
  int n = 0;
  if (!x) return 0;
  for (y = x->Evidence; y; ++n, y = (struct zx_sa11_Evidence_s*)y->gg.g.n) ;
  return n;
}

/* FUNC(zx_sa11_AuthorizationDecisionStatement_GET_Evidence) */

struct zx_sa11_Evidence_s* zx_sa11_AuthorizationDecisionStatement_GET_Evidence(struct zx_sa11_AuthorizationDecisionStatement_s* x, int n)
{
  struct zx_sa11_Evidence_s* y;
  if (!x) return 0;
  for (y = x->Evidence; n>=0 && y; --n, y = (struct zx_sa11_Evidence_s*)y->gg.g.n) ;
  return y;
}

/* FUNC(zx_sa11_AuthorizationDecisionStatement_POP_Evidence) */

struct zx_sa11_Evidence_s* zx_sa11_AuthorizationDecisionStatement_POP_Evidence(struct zx_sa11_AuthorizationDecisionStatement_s* x)
{
  struct zx_sa11_Evidence_s* y;
  if (!x) return 0;
  y = x->Evidence;
  if (y)
    x->Evidence = (struct zx_sa11_Evidence_s*)y->gg.g.n;
  return y;
}

/* FUNC(zx_sa11_AuthorizationDecisionStatement_PUSH_Evidence) */

void zx_sa11_AuthorizationDecisionStatement_PUSH_Evidence(struct zx_sa11_AuthorizationDecisionStatement_s* x, struct zx_sa11_Evidence_s* z)
{
  if (!x || !z) return;
  z->gg.g.n = &x->Evidence->gg.g;
  x->Evidence = z;
}

/* FUNC(zx_sa11_AuthorizationDecisionStatement_REV_Evidence) */

void zx_sa11_AuthorizationDecisionStatement_REV_Evidence(struct zx_sa11_AuthorizationDecisionStatement_s* x)
{
  struct zx_sa11_Evidence_s* nxt;
  struct zx_sa11_Evidence_s* y;
  if (!x) return;
  y = x->Evidence;
  if (!y) return;
  x->Evidence = 0;
  while (y) {
    nxt = (struct zx_sa11_Evidence_s*)y->gg.g.n;
    y->gg.g.n = &x->Evidence->gg.g;
    x->Evidence = y;
    y = nxt;
  }
}

/* FUNC(zx_sa11_AuthorizationDecisionStatement_PUT_Evidence) */

void zx_sa11_AuthorizationDecisionStatement_PUT_Evidence(struct zx_sa11_AuthorizationDecisionStatement_s* x, int n, struct zx_sa11_Evidence_s* z)
{
  struct zx_sa11_Evidence_s* y;
  if (!x || !z) return;
  y = x->Evidence;
  if (!y) return;
  switch (n) {
  case 0:
    z->gg.g.n = y->gg.g.n;
    x->Evidence = z;
    return;
  default:
    for (; n > 1 && y->gg.g.n; --n, y = (struct zx_sa11_Evidence_s*)y->gg.g.n) ;
    if (!y->gg.g.n) return;
    z->gg.g.n = y->gg.g.n->n;
    y->gg.g.n = &z->gg.g;
  }
}

/* FUNC(zx_sa11_AuthorizationDecisionStatement_ADD_Evidence) */

void zx_sa11_AuthorizationDecisionStatement_ADD_Evidence(struct zx_sa11_AuthorizationDecisionStatement_s* x, int n, struct zx_sa11_Evidence_s* z)
{
  struct zx_sa11_Evidence_s* y;
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
    for (; y->gg.g.n; y = (struct zx_sa11_Evidence_s*)y->gg.g.n) ;
    break;
  default:
    for (y = x->Evidence; n > 1 && y; --n, y = (struct zx_sa11_Evidence_s*)y->gg.g.n) ;
    if (!y) return;
  }
  z->gg.g.n = y->gg.g.n;
  y->gg.g.n = &z->gg.g;
}

/* FUNC(zx_sa11_AuthorizationDecisionStatement_DEL_Evidence) */

void zx_sa11_AuthorizationDecisionStatement_DEL_Evidence(struct zx_sa11_AuthorizationDecisionStatement_s* x, int n)
{
  struct zx_sa11_Evidence_s* y;
  if (!x) return;
  switch (n) {
  case 0:
    x->Evidence = (struct zx_sa11_Evidence_s*)x->Evidence->gg.g.n;
    return;
  case -1:
    y = (struct zx_sa11_Evidence_s*)x->Evidence;
    if (!y) return;
    for (; y->gg.g.n; y = (struct zx_sa11_Evidence_s*)y->gg.g.n) ;
    break;
  default:
    for (y = x->Evidence; n > 1 && y->gg.g.n; --n, y = (struct zx_sa11_Evidence_s*)y->gg.g.n) ;
    if (!y->gg.g.n) return;
  }
  y->gg.g.n = y->gg.g.n->n;
}

#endif

/* FUNC(zx_sa11_AuthorizationDecisionStatement_GET_Decision) */
struct zx_str* zx_sa11_AuthorizationDecisionStatement_GET_Decision(struct zx_sa11_AuthorizationDecisionStatement_s* x) { return x->Decision; }
/* FUNC(zx_sa11_AuthorizationDecisionStatement_PUT_Decision) */
void zx_sa11_AuthorizationDecisionStatement_PUT_Decision(struct zx_sa11_AuthorizationDecisionStatement_s* x, struct zx_str* y) { x->Decision = y; }
/* FUNC(zx_sa11_AuthorizationDecisionStatement_GET_Resource) */
struct zx_str* zx_sa11_AuthorizationDecisionStatement_GET_Resource(struct zx_sa11_AuthorizationDecisionStatement_s* x) { return x->Resource; }
/* FUNC(zx_sa11_AuthorizationDecisionStatement_PUT_Resource) */
void zx_sa11_AuthorizationDecisionStatement_PUT_Resource(struct zx_sa11_AuthorizationDecisionStatement_s* x, struct zx_str* y) { x->Resource = y; }







#ifdef ZX_ENA_GETPUT

/* FUNC(zx_sa11_Conditions_NUM_AudienceRestrictionCondition) */

int zx_sa11_Conditions_NUM_AudienceRestrictionCondition(struct zx_sa11_Conditions_s* x)
{
  struct zx_sa11_AudienceRestrictionCondition_s* y;
  int n = 0;
  if (!x) return 0;
  for (y = x->AudienceRestrictionCondition; y; ++n, y = (struct zx_sa11_AudienceRestrictionCondition_s*)y->gg.g.n) ;
  return n;
}

/* FUNC(zx_sa11_Conditions_GET_AudienceRestrictionCondition) */

struct zx_sa11_AudienceRestrictionCondition_s* zx_sa11_Conditions_GET_AudienceRestrictionCondition(struct zx_sa11_Conditions_s* x, int n)
{
  struct zx_sa11_AudienceRestrictionCondition_s* y;
  if (!x) return 0;
  for (y = x->AudienceRestrictionCondition; n>=0 && y; --n, y = (struct zx_sa11_AudienceRestrictionCondition_s*)y->gg.g.n) ;
  return y;
}

/* FUNC(zx_sa11_Conditions_POP_AudienceRestrictionCondition) */

struct zx_sa11_AudienceRestrictionCondition_s* zx_sa11_Conditions_POP_AudienceRestrictionCondition(struct zx_sa11_Conditions_s* x)
{
  struct zx_sa11_AudienceRestrictionCondition_s* y;
  if (!x) return 0;
  y = x->AudienceRestrictionCondition;
  if (y)
    x->AudienceRestrictionCondition = (struct zx_sa11_AudienceRestrictionCondition_s*)y->gg.g.n;
  return y;
}

/* FUNC(zx_sa11_Conditions_PUSH_AudienceRestrictionCondition) */

void zx_sa11_Conditions_PUSH_AudienceRestrictionCondition(struct zx_sa11_Conditions_s* x, struct zx_sa11_AudienceRestrictionCondition_s* z)
{
  if (!x || !z) return;
  z->gg.g.n = &x->AudienceRestrictionCondition->gg.g;
  x->AudienceRestrictionCondition = z;
}

/* FUNC(zx_sa11_Conditions_REV_AudienceRestrictionCondition) */

void zx_sa11_Conditions_REV_AudienceRestrictionCondition(struct zx_sa11_Conditions_s* x)
{
  struct zx_sa11_AudienceRestrictionCondition_s* nxt;
  struct zx_sa11_AudienceRestrictionCondition_s* y;
  if (!x) return;
  y = x->AudienceRestrictionCondition;
  if (!y) return;
  x->AudienceRestrictionCondition = 0;
  while (y) {
    nxt = (struct zx_sa11_AudienceRestrictionCondition_s*)y->gg.g.n;
    y->gg.g.n = &x->AudienceRestrictionCondition->gg.g;
    x->AudienceRestrictionCondition = y;
    y = nxt;
  }
}

/* FUNC(zx_sa11_Conditions_PUT_AudienceRestrictionCondition) */

void zx_sa11_Conditions_PUT_AudienceRestrictionCondition(struct zx_sa11_Conditions_s* x, int n, struct zx_sa11_AudienceRestrictionCondition_s* z)
{
  struct zx_sa11_AudienceRestrictionCondition_s* y;
  if (!x || !z) return;
  y = x->AudienceRestrictionCondition;
  if (!y) return;
  switch (n) {
  case 0:
    z->gg.g.n = y->gg.g.n;
    x->AudienceRestrictionCondition = z;
    return;
  default:
    for (; n > 1 && y->gg.g.n; --n, y = (struct zx_sa11_AudienceRestrictionCondition_s*)y->gg.g.n) ;
    if (!y->gg.g.n) return;
    z->gg.g.n = y->gg.g.n->n;
    y->gg.g.n = &z->gg.g;
  }
}

/* FUNC(zx_sa11_Conditions_ADD_AudienceRestrictionCondition) */

void zx_sa11_Conditions_ADD_AudienceRestrictionCondition(struct zx_sa11_Conditions_s* x, int n, struct zx_sa11_AudienceRestrictionCondition_s* z)
{
  struct zx_sa11_AudienceRestrictionCondition_s* y;
  if (!x || !z) return;
  switch (n) {
  case 0:
  add_to_start:
    z->gg.g.n = &x->AudienceRestrictionCondition->gg.g;
    x->AudienceRestrictionCondition = z;
    return;
  case -1:
    y = x->AudienceRestrictionCondition;
    if (!y) goto add_to_start;
    for (; y->gg.g.n; y = (struct zx_sa11_AudienceRestrictionCondition_s*)y->gg.g.n) ;
    break;
  default:
    for (y = x->AudienceRestrictionCondition; n > 1 && y; --n, y = (struct zx_sa11_AudienceRestrictionCondition_s*)y->gg.g.n) ;
    if (!y) return;
  }
  z->gg.g.n = y->gg.g.n;
  y->gg.g.n = &z->gg.g;
}

/* FUNC(zx_sa11_Conditions_DEL_AudienceRestrictionCondition) */

void zx_sa11_Conditions_DEL_AudienceRestrictionCondition(struct zx_sa11_Conditions_s* x, int n)
{
  struct zx_sa11_AudienceRestrictionCondition_s* y;
  if (!x) return;
  switch (n) {
  case 0:
    x->AudienceRestrictionCondition = (struct zx_sa11_AudienceRestrictionCondition_s*)x->AudienceRestrictionCondition->gg.g.n;
    return;
  case -1:
    y = (struct zx_sa11_AudienceRestrictionCondition_s*)x->AudienceRestrictionCondition;
    if (!y) return;
    for (; y->gg.g.n; y = (struct zx_sa11_AudienceRestrictionCondition_s*)y->gg.g.n) ;
    break;
  default:
    for (y = x->AudienceRestrictionCondition; n > 1 && y->gg.g.n; --n, y = (struct zx_sa11_AudienceRestrictionCondition_s*)y->gg.g.n) ;
    if (!y->gg.g.n) return;
  }
  y->gg.g.n = y->gg.g.n->n;
}

#endif



#ifdef ZX_ENA_GETPUT

/* FUNC(zx_sa11_Conditions_NUM_DoNotCacheCondition) */

int zx_sa11_Conditions_NUM_DoNotCacheCondition(struct zx_sa11_Conditions_s* x)
{
  struct zx_sa11_DoNotCacheCondition_s* y;
  int n = 0;
  if (!x) return 0;
  for (y = x->DoNotCacheCondition; y; ++n, y = (struct zx_sa11_DoNotCacheCondition_s*)y->gg.g.n) ;
  return n;
}

/* FUNC(zx_sa11_Conditions_GET_DoNotCacheCondition) */

struct zx_sa11_DoNotCacheCondition_s* zx_sa11_Conditions_GET_DoNotCacheCondition(struct zx_sa11_Conditions_s* x, int n)
{
  struct zx_sa11_DoNotCacheCondition_s* y;
  if (!x) return 0;
  for (y = x->DoNotCacheCondition; n>=0 && y; --n, y = (struct zx_sa11_DoNotCacheCondition_s*)y->gg.g.n) ;
  return y;
}

/* FUNC(zx_sa11_Conditions_POP_DoNotCacheCondition) */

struct zx_sa11_DoNotCacheCondition_s* zx_sa11_Conditions_POP_DoNotCacheCondition(struct zx_sa11_Conditions_s* x)
{
  struct zx_sa11_DoNotCacheCondition_s* y;
  if (!x) return 0;
  y = x->DoNotCacheCondition;
  if (y)
    x->DoNotCacheCondition = (struct zx_sa11_DoNotCacheCondition_s*)y->gg.g.n;
  return y;
}

/* FUNC(zx_sa11_Conditions_PUSH_DoNotCacheCondition) */

void zx_sa11_Conditions_PUSH_DoNotCacheCondition(struct zx_sa11_Conditions_s* x, struct zx_sa11_DoNotCacheCondition_s* z)
{
  if (!x || !z) return;
  z->gg.g.n = &x->DoNotCacheCondition->gg.g;
  x->DoNotCacheCondition = z;
}

/* FUNC(zx_sa11_Conditions_REV_DoNotCacheCondition) */

void zx_sa11_Conditions_REV_DoNotCacheCondition(struct zx_sa11_Conditions_s* x)
{
  struct zx_sa11_DoNotCacheCondition_s* nxt;
  struct zx_sa11_DoNotCacheCondition_s* y;
  if (!x) return;
  y = x->DoNotCacheCondition;
  if (!y) return;
  x->DoNotCacheCondition = 0;
  while (y) {
    nxt = (struct zx_sa11_DoNotCacheCondition_s*)y->gg.g.n;
    y->gg.g.n = &x->DoNotCacheCondition->gg.g;
    x->DoNotCacheCondition = y;
    y = nxt;
  }
}

/* FUNC(zx_sa11_Conditions_PUT_DoNotCacheCondition) */

void zx_sa11_Conditions_PUT_DoNotCacheCondition(struct zx_sa11_Conditions_s* x, int n, struct zx_sa11_DoNotCacheCondition_s* z)
{
  struct zx_sa11_DoNotCacheCondition_s* y;
  if (!x || !z) return;
  y = x->DoNotCacheCondition;
  if (!y) return;
  switch (n) {
  case 0:
    z->gg.g.n = y->gg.g.n;
    x->DoNotCacheCondition = z;
    return;
  default:
    for (; n > 1 && y->gg.g.n; --n, y = (struct zx_sa11_DoNotCacheCondition_s*)y->gg.g.n) ;
    if (!y->gg.g.n) return;
    z->gg.g.n = y->gg.g.n->n;
    y->gg.g.n = &z->gg.g;
  }
}

/* FUNC(zx_sa11_Conditions_ADD_DoNotCacheCondition) */

void zx_sa11_Conditions_ADD_DoNotCacheCondition(struct zx_sa11_Conditions_s* x, int n, struct zx_sa11_DoNotCacheCondition_s* z)
{
  struct zx_sa11_DoNotCacheCondition_s* y;
  if (!x || !z) return;
  switch (n) {
  case 0:
  add_to_start:
    z->gg.g.n = &x->DoNotCacheCondition->gg.g;
    x->DoNotCacheCondition = z;
    return;
  case -1:
    y = x->DoNotCacheCondition;
    if (!y) goto add_to_start;
    for (; y->gg.g.n; y = (struct zx_sa11_DoNotCacheCondition_s*)y->gg.g.n) ;
    break;
  default:
    for (y = x->DoNotCacheCondition; n > 1 && y; --n, y = (struct zx_sa11_DoNotCacheCondition_s*)y->gg.g.n) ;
    if (!y) return;
  }
  z->gg.g.n = y->gg.g.n;
  y->gg.g.n = &z->gg.g;
}

/* FUNC(zx_sa11_Conditions_DEL_DoNotCacheCondition) */

void zx_sa11_Conditions_DEL_DoNotCacheCondition(struct zx_sa11_Conditions_s* x, int n)
{
  struct zx_sa11_DoNotCacheCondition_s* y;
  if (!x) return;
  switch (n) {
  case 0:
    x->DoNotCacheCondition = (struct zx_sa11_DoNotCacheCondition_s*)x->DoNotCacheCondition->gg.g.n;
    return;
  case -1:
    y = (struct zx_sa11_DoNotCacheCondition_s*)x->DoNotCacheCondition;
    if (!y) return;
    for (; y->gg.g.n; y = (struct zx_sa11_DoNotCacheCondition_s*)y->gg.g.n) ;
    break;
  default:
    for (y = x->DoNotCacheCondition; n > 1 && y->gg.g.n; --n, y = (struct zx_sa11_DoNotCacheCondition_s*)y->gg.g.n) ;
    if (!y->gg.g.n) return;
  }
  y->gg.g.n = y->gg.g.n->n;
}

#endif



#ifdef ZX_ENA_GETPUT

/* FUNC(zx_sa11_Conditions_NUM_Condition) */

int zx_sa11_Conditions_NUM_Condition(struct zx_sa11_Conditions_s* x)
{
  struct zx_elem_s* y;
  int n = 0;
  if (!x) return 0;
  for (y = x->Condition; y; ++n, y = (struct zx_elem_s*)y->g.n) ;
  return n;
}

/* FUNC(zx_sa11_Conditions_GET_Condition) */

struct zx_elem_s* zx_sa11_Conditions_GET_Condition(struct zx_sa11_Conditions_s* x, int n)
{
  struct zx_elem_s* y;
  if (!x) return 0;
  for (y = x->Condition; n>=0 && y; --n, y = (struct zx_elem_s*)y->g.n) ;
  return y;
}

/* FUNC(zx_sa11_Conditions_POP_Condition) */

struct zx_elem_s* zx_sa11_Conditions_POP_Condition(struct zx_sa11_Conditions_s* x)
{
  struct zx_elem_s* y;
  if (!x) return 0;
  y = x->Condition;
  if (y)
    x->Condition = (struct zx_elem_s*)y->g.n;
  return y;
}

/* FUNC(zx_sa11_Conditions_PUSH_Condition) */

void zx_sa11_Conditions_PUSH_Condition(struct zx_sa11_Conditions_s* x, struct zx_elem_s* z)
{
  if (!x || !z) return;
  z->g.n = &x->Condition->g;
  x->Condition = z;
}

/* FUNC(zx_sa11_Conditions_REV_Condition) */

void zx_sa11_Conditions_REV_Condition(struct zx_sa11_Conditions_s* x)
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

/* FUNC(zx_sa11_Conditions_PUT_Condition) */

void zx_sa11_Conditions_PUT_Condition(struct zx_sa11_Conditions_s* x, int n, struct zx_elem_s* z)
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

/* FUNC(zx_sa11_Conditions_ADD_Condition) */

void zx_sa11_Conditions_ADD_Condition(struct zx_sa11_Conditions_s* x, int n, struct zx_elem_s* z)
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

/* FUNC(zx_sa11_Conditions_DEL_Condition) */

void zx_sa11_Conditions_DEL_Condition(struct zx_sa11_Conditions_s* x, int n)
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

/* FUNC(zx_sa11_Conditions_GET_NotBefore) */
struct zx_str* zx_sa11_Conditions_GET_NotBefore(struct zx_sa11_Conditions_s* x) { return x->NotBefore; }
/* FUNC(zx_sa11_Conditions_PUT_NotBefore) */
void zx_sa11_Conditions_PUT_NotBefore(struct zx_sa11_Conditions_s* x, struct zx_str* y) { x->NotBefore = y; }
/* FUNC(zx_sa11_Conditions_GET_NotOnOrAfter) */
struct zx_str* zx_sa11_Conditions_GET_NotOnOrAfter(struct zx_sa11_Conditions_s* x) { return x->NotOnOrAfter; }
/* FUNC(zx_sa11_Conditions_PUT_NotOnOrAfter) */
void zx_sa11_Conditions_PUT_NotOnOrAfter(struct zx_sa11_Conditions_s* x, struct zx_str* y) { x->NotOnOrAfter = y; }












#ifdef ZX_ENA_GETPUT

/* FUNC(zx_sa11_Evidence_NUM_AssertionIDReference) */

int zx_sa11_Evidence_NUM_AssertionIDReference(struct zx_sa11_Evidence_s* x)
{
  struct zx_elem_s* y;
  int n = 0;
  if (!x) return 0;
  for (y = x->AssertionIDReference; y; ++n, y = (struct zx_elem_s*)y->g.n) ;
  return n;
}

/* FUNC(zx_sa11_Evidence_GET_AssertionIDReference) */

struct zx_elem_s* zx_sa11_Evidence_GET_AssertionIDReference(struct zx_sa11_Evidence_s* x, int n)
{
  struct zx_elem_s* y;
  if (!x) return 0;
  for (y = x->AssertionIDReference; n>=0 && y; --n, y = (struct zx_elem_s*)y->g.n) ;
  return y;
}

/* FUNC(zx_sa11_Evidence_POP_AssertionIDReference) */

struct zx_elem_s* zx_sa11_Evidence_POP_AssertionIDReference(struct zx_sa11_Evidence_s* x)
{
  struct zx_elem_s* y;
  if (!x) return 0;
  y = x->AssertionIDReference;
  if (y)
    x->AssertionIDReference = (struct zx_elem_s*)y->g.n;
  return y;
}

/* FUNC(zx_sa11_Evidence_PUSH_AssertionIDReference) */

void zx_sa11_Evidence_PUSH_AssertionIDReference(struct zx_sa11_Evidence_s* x, struct zx_elem_s* z)
{
  if (!x || !z) return;
  z->g.n = &x->AssertionIDReference->g;
  x->AssertionIDReference = z;
}

/* FUNC(zx_sa11_Evidence_REV_AssertionIDReference) */

void zx_sa11_Evidence_REV_AssertionIDReference(struct zx_sa11_Evidence_s* x)
{
  struct zx_elem_s* nxt;
  struct zx_elem_s* y;
  if (!x) return;
  y = x->AssertionIDReference;
  if (!y) return;
  x->AssertionIDReference = 0;
  while (y) {
    nxt = (struct zx_elem_s*)y->g.n;
    y->g.n = &x->AssertionIDReference->g;
    x->AssertionIDReference = y;
    y = nxt;
  }
}

/* FUNC(zx_sa11_Evidence_PUT_AssertionIDReference) */

void zx_sa11_Evidence_PUT_AssertionIDReference(struct zx_sa11_Evidence_s* x, int n, struct zx_elem_s* z)
{
  struct zx_elem_s* y;
  if (!x || !z) return;
  y = x->AssertionIDReference;
  if (!y) return;
  switch (n) {
  case 0:
    z->g.n = y->g.n;
    x->AssertionIDReference = z;
    return;
  default:
    for (; n > 1 && y->g.n; --n, y = (struct zx_elem_s*)y->g.n) ;
    if (!y->g.n) return;
    z->g.n = y->g.n->n;
    y->g.n = &z->g;
  }
}

/* FUNC(zx_sa11_Evidence_ADD_AssertionIDReference) */

void zx_sa11_Evidence_ADD_AssertionIDReference(struct zx_sa11_Evidence_s* x, int n, struct zx_elem_s* z)
{
  struct zx_elem_s* y;
  if (!x || !z) return;
  switch (n) {
  case 0:
  add_to_start:
    z->g.n = &x->AssertionIDReference->g;
    x->AssertionIDReference = z;
    return;
  case -1:
    y = x->AssertionIDReference;
    if (!y) goto add_to_start;
    for (; y->g.n; y = (struct zx_elem_s*)y->g.n) ;
    break;
  default:
    for (y = x->AssertionIDReference; n > 1 && y; --n, y = (struct zx_elem_s*)y->g.n) ;
    if (!y) return;
  }
  z->g.n = y->g.n;
  y->g.n = &z->g;
}

/* FUNC(zx_sa11_Evidence_DEL_AssertionIDReference) */

void zx_sa11_Evidence_DEL_AssertionIDReference(struct zx_sa11_Evidence_s* x, int n)
{
  struct zx_elem_s* y;
  if (!x) return;
  switch (n) {
  case 0:
    x->AssertionIDReference = (struct zx_elem_s*)x->AssertionIDReference->g.n;
    return;
  case -1:
    y = (struct zx_elem_s*)x->AssertionIDReference;
    if (!y) return;
    for (; y->g.n; y = (struct zx_elem_s*)y->g.n) ;
    break;
  default:
    for (y = x->AssertionIDReference; n > 1 && y->g.n; --n, y = (struct zx_elem_s*)y->g.n) ;
    if (!y->g.n) return;
  }
  y->g.n = y->g.n->n;
}

#endif



#ifdef ZX_ENA_GETPUT

/* FUNC(zx_sa11_Evidence_NUM_Assertion) */

int zx_sa11_Evidence_NUM_Assertion(struct zx_sa11_Evidence_s* x)
{
  struct zx_sa11_Assertion_s* y;
  int n = 0;
  if (!x) return 0;
  for (y = x->Assertion; y; ++n, y = (struct zx_sa11_Assertion_s*)y->gg.g.n) ;
  return n;
}

/* FUNC(zx_sa11_Evidence_GET_Assertion) */

struct zx_sa11_Assertion_s* zx_sa11_Evidence_GET_Assertion(struct zx_sa11_Evidence_s* x, int n)
{
  struct zx_sa11_Assertion_s* y;
  if (!x) return 0;
  for (y = x->Assertion; n>=0 && y; --n, y = (struct zx_sa11_Assertion_s*)y->gg.g.n) ;
  return y;
}

/* FUNC(zx_sa11_Evidence_POP_Assertion) */

struct zx_sa11_Assertion_s* zx_sa11_Evidence_POP_Assertion(struct zx_sa11_Evidence_s* x)
{
  struct zx_sa11_Assertion_s* y;
  if (!x) return 0;
  y = x->Assertion;
  if (y)
    x->Assertion = (struct zx_sa11_Assertion_s*)y->gg.g.n;
  return y;
}

/* FUNC(zx_sa11_Evidence_PUSH_Assertion) */

void zx_sa11_Evidence_PUSH_Assertion(struct zx_sa11_Evidence_s* x, struct zx_sa11_Assertion_s* z)
{
  if (!x || !z) return;
  z->gg.g.n = &x->Assertion->gg.g;
  x->Assertion = z;
}

/* FUNC(zx_sa11_Evidence_REV_Assertion) */

void zx_sa11_Evidence_REV_Assertion(struct zx_sa11_Evidence_s* x)
{
  struct zx_sa11_Assertion_s* nxt;
  struct zx_sa11_Assertion_s* y;
  if (!x) return;
  y = x->Assertion;
  if (!y) return;
  x->Assertion = 0;
  while (y) {
    nxt = (struct zx_sa11_Assertion_s*)y->gg.g.n;
    y->gg.g.n = &x->Assertion->gg.g;
    x->Assertion = y;
    y = nxt;
  }
}

/* FUNC(zx_sa11_Evidence_PUT_Assertion) */

void zx_sa11_Evidence_PUT_Assertion(struct zx_sa11_Evidence_s* x, int n, struct zx_sa11_Assertion_s* z)
{
  struct zx_sa11_Assertion_s* y;
  if (!x || !z) return;
  y = x->Assertion;
  if (!y) return;
  switch (n) {
  case 0:
    z->gg.g.n = y->gg.g.n;
    x->Assertion = z;
    return;
  default:
    for (; n > 1 && y->gg.g.n; --n, y = (struct zx_sa11_Assertion_s*)y->gg.g.n) ;
    if (!y->gg.g.n) return;
    z->gg.g.n = y->gg.g.n->n;
    y->gg.g.n = &z->gg.g;
  }
}

/* FUNC(zx_sa11_Evidence_ADD_Assertion) */

void zx_sa11_Evidence_ADD_Assertion(struct zx_sa11_Evidence_s* x, int n, struct zx_sa11_Assertion_s* z)
{
  struct zx_sa11_Assertion_s* y;
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
    for (; y->gg.g.n; y = (struct zx_sa11_Assertion_s*)y->gg.g.n) ;
    break;
  default:
    for (y = x->Assertion; n > 1 && y; --n, y = (struct zx_sa11_Assertion_s*)y->gg.g.n) ;
    if (!y) return;
  }
  z->gg.g.n = y->gg.g.n;
  y->gg.g.n = &z->gg.g;
}

/* FUNC(zx_sa11_Evidence_DEL_Assertion) */

void zx_sa11_Evidence_DEL_Assertion(struct zx_sa11_Evidence_s* x, int n)
{
  struct zx_sa11_Assertion_s* y;
  if (!x) return;
  switch (n) {
  case 0:
    x->Assertion = (struct zx_sa11_Assertion_s*)x->Assertion->gg.g.n;
    return;
  case -1:
    y = (struct zx_sa11_Assertion_s*)x->Assertion;
    if (!y) return;
    for (; y->gg.g.n; y = (struct zx_sa11_Assertion_s*)y->gg.g.n) ;
    break;
  default:
    for (y = x->Assertion; n > 1 && y->gg.g.n; --n, y = (struct zx_sa11_Assertion_s*)y->gg.g.n) ;
    if (!y->gg.g.n) return;
  }
  y->gg.g.n = y->gg.g.n->n;
}

#endif






/* FUNC(zx_sa11_NameIdentifier_GET_Format) */
struct zx_str* zx_sa11_NameIdentifier_GET_Format(struct zx_sa11_NameIdentifier_s* x) { return x->Format; }
/* FUNC(zx_sa11_NameIdentifier_PUT_Format) */
void zx_sa11_NameIdentifier_PUT_Format(struct zx_sa11_NameIdentifier_s* x, struct zx_str* y) { x->Format = y; }
/* FUNC(zx_sa11_NameIdentifier_GET_NameQualifier) */
struct zx_str* zx_sa11_NameIdentifier_GET_NameQualifier(struct zx_sa11_NameIdentifier_s* x) { return x->NameQualifier; }
/* FUNC(zx_sa11_NameIdentifier_PUT_NameQualifier) */
void zx_sa11_NameIdentifier_PUT_NameQualifier(struct zx_sa11_NameIdentifier_s* x, struct zx_str* y) { x->NameQualifier = y; }







#ifdef ZX_ENA_GETPUT

/* FUNC(zx_sa11_Subject_NUM_NameIdentifier) */

int zx_sa11_Subject_NUM_NameIdentifier(struct zx_sa11_Subject_s* x)
{
  struct zx_sa11_NameIdentifier_s* y;
  int n = 0;
  if (!x) return 0;
  for (y = x->NameIdentifier; y; ++n, y = (struct zx_sa11_NameIdentifier_s*)y->gg.g.n) ;
  return n;
}

/* FUNC(zx_sa11_Subject_GET_NameIdentifier) */

struct zx_sa11_NameIdentifier_s* zx_sa11_Subject_GET_NameIdentifier(struct zx_sa11_Subject_s* x, int n)
{
  struct zx_sa11_NameIdentifier_s* y;
  if (!x) return 0;
  for (y = x->NameIdentifier; n>=0 && y; --n, y = (struct zx_sa11_NameIdentifier_s*)y->gg.g.n) ;
  return y;
}

/* FUNC(zx_sa11_Subject_POP_NameIdentifier) */

struct zx_sa11_NameIdentifier_s* zx_sa11_Subject_POP_NameIdentifier(struct zx_sa11_Subject_s* x)
{
  struct zx_sa11_NameIdentifier_s* y;
  if (!x) return 0;
  y = x->NameIdentifier;
  if (y)
    x->NameIdentifier = (struct zx_sa11_NameIdentifier_s*)y->gg.g.n;
  return y;
}

/* FUNC(zx_sa11_Subject_PUSH_NameIdentifier) */

void zx_sa11_Subject_PUSH_NameIdentifier(struct zx_sa11_Subject_s* x, struct zx_sa11_NameIdentifier_s* z)
{
  if (!x || !z) return;
  z->gg.g.n = &x->NameIdentifier->gg.g;
  x->NameIdentifier = z;
}

/* FUNC(zx_sa11_Subject_REV_NameIdentifier) */

void zx_sa11_Subject_REV_NameIdentifier(struct zx_sa11_Subject_s* x)
{
  struct zx_sa11_NameIdentifier_s* nxt;
  struct zx_sa11_NameIdentifier_s* y;
  if (!x) return;
  y = x->NameIdentifier;
  if (!y) return;
  x->NameIdentifier = 0;
  while (y) {
    nxt = (struct zx_sa11_NameIdentifier_s*)y->gg.g.n;
    y->gg.g.n = &x->NameIdentifier->gg.g;
    x->NameIdentifier = y;
    y = nxt;
  }
}

/* FUNC(zx_sa11_Subject_PUT_NameIdentifier) */

void zx_sa11_Subject_PUT_NameIdentifier(struct zx_sa11_Subject_s* x, int n, struct zx_sa11_NameIdentifier_s* z)
{
  struct zx_sa11_NameIdentifier_s* y;
  if (!x || !z) return;
  y = x->NameIdentifier;
  if (!y) return;
  switch (n) {
  case 0:
    z->gg.g.n = y->gg.g.n;
    x->NameIdentifier = z;
    return;
  default:
    for (; n > 1 && y->gg.g.n; --n, y = (struct zx_sa11_NameIdentifier_s*)y->gg.g.n) ;
    if (!y->gg.g.n) return;
    z->gg.g.n = y->gg.g.n->n;
    y->gg.g.n = &z->gg.g;
  }
}

/* FUNC(zx_sa11_Subject_ADD_NameIdentifier) */

void zx_sa11_Subject_ADD_NameIdentifier(struct zx_sa11_Subject_s* x, int n, struct zx_sa11_NameIdentifier_s* z)
{
  struct zx_sa11_NameIdentifier_s* y;
  if (!x || !z) return;
  switch (n) {
  case 0:
  add_to_start:
    z->gg.g.n = &x->NameIdentifier->gg.g;
    x->NameIdentifier = z;
    return;
  case -1:
    y = x->NameIdentifier;
    if (!y) goto add_to_start;
    for (; y->gg.g.n; y = (struct zx_sa11_NameIdentifier_s*)y->gg.g.n) ;
    break;
  default:
    for (y = x->NameIdentifier; n > 1 && y; --n, y = (struct zx_sa11_NameIdentifier_s*)y->gg.g.n) ;
    if (!y) return;
  }
  z->gg.g.n = y->gg.g.n;
  y->gg.g.n = &z->gg.g;
}

/* FUNC(zx_sa11_Subject_DEL_NameIdentifier) */

void zx_sa11_Subject_DEL_NameIdentifier(struct zx_sa11_Subject_s* x, int n)
{
  struct zx_sa11_NameIdentifier_s* y;
  if (!x) return;
  switch (n) {
  case 0:
    x->NameIdentifier = (struct zx_sa11_NameIdentifier_s*)x->NameIdentifier->gg.g.n;
    return;
  case -1:
    y = (struct zx_sa11_NameIdentifier_s*)x->NameIdentifier;
    if (!y) return;
    for (; y->gg.g.n; y = (struct zx_sa11_NameIdentifier_s*)y->gg.g.n) ;
    break;
  default:
    for (y = x->NameIdentifier; n > 1 && y->gg.g.n; --n, y = (struct zx_sa11_NameIdentifier_s*)y->gg.g.n) ;
    if (!y->gg.g.n) return;
  }
  y->gg.g.n = y->gg.g.n->n;
}

#endif



#ifdef ZX_ENA_GETPUT

/* FUNC(zx_sa11_Subject_NUM_SubjectConfirmation) */

int zx_sa11_Subject_NUM_SubjectConfirmation(struct zx_sa11_Subject_s* x)
{
  struct zx_sa11_SubjectConfirmation_s* y;
  int n = 0;
  if (!x) return 0;
  for (y = x->SubjectConfirmation; y; ++n, y = (struct zx_sa11_SubjectConfirmation_s*)y->gg.g.n) ;
  return n;
}

/* FUNC(zx_sa11_Subject_GET_SubjectConfirmation) */

struct zx_sa11_SubjectConfirmation_s* zx_sa11_Subject_GET_SubjectConfirmation(struct zx_sa11_Subject_s* x, int n)
{
  struct zx_sa11_SubjectConfirmation_s* y;
  if (!x) return 0;
  for (y = x->SubjectConfirmation; n>=0 && y; --n, y = (struct zx_sa11_SubjectConfirmation_s*)y->gg.g.n) ;
  return y;
}

/* FUNC(zx_sa11_Subject_POP_SubjectConfirmation) */

struct zx_sa11_SubjectConfirmation_s* zx_sa11_Subject_POP_SubjectConfirmation(struct zx_sa11_Subject_s* x)
{
  struct zx_sa11_SubjectConfirmation_s* y;
  if (!x) return 0;
  y = x->SubjectConfirmation;
  if (y)
    x->SubjectConfirmation = (struct zx_sa11_SubjectConfirmation_s*)y->gg.g.n;
  return y;
}

/* FUNC(zx_sa11_Subject_PUSH_SubjectConfirmation) */

void zx_sa11_Subject_PUSH_SubjectConfirmation(struct zx_sa11_Subject_s* x, struct zx_sa11_SubjectConfirmation_s* z)
{
  if (!x || !z) return;
  z->gg.g.n = &x->SubjectConfirmation->gg.g;
  x->SubjectConfirmation = z;
}

/* FUNC(zx_sa11_Subject_REV_SubjectConfirmation) */

void zx_sa11_Subject_REV_SubjectConfirmation(struct zx_sa11_Subject_s* x)
{
  struct zx_sa11_SubjectConfirmation_s* nxt;
  struct zx_sa11_SubjectConfirmation_s* y;
  if (!x) return;
  y = x->SubjectConfirmation;
  if (!y) return;
  x->SubjectConfirmation = 0;
  while (y) {
    nxt = (struct zx_sa11_SubjectConfirmation_s*)y->gg.g.n;
    y->gg.g.n = &x->SubjectConfirmation->gg.g;
    x->SubjectConfirmation = y;
    y = nxt;
  }
}

/* FUNC(zx_sa11_Subject_PUT_SubjectConfirmation) */

void zx_sa11_Subject_PUT_SubjectConfirmation(struct zx_sa11_Subject_s* x, int n, struct zx_sa11_SubjectConfirmation_s* z)
{
  struct zx_sa11_SubjectConfirmation_s* y;
  if (!x || !z) return;
  y = x->SubjectConfirmation;
  if (!y) return;
  switch (n) {
  case 0:
    z->gg.g.n = y->gg.g.n;
    x->SubjectConfirmation = z;
    return;
  default:
    for (; n > 1 && y->gg.g.n; --n, y = (struct zx_sa11_SubjectConfirmation_s*)y->gg.g.n) ;
    if (!y->gg.g.n) return;
    z->gg.g.n = y->gg.g.n->n;
    y->gg.g.n = &z->gg.g;
  }
}

/* FUNC(zx_sa11_Subject_ADD_SubjectConfirmation) */

void zx_sa11_Subject_ADD_SubjectConfirmation(struct zx_sa11_Subject_s* x, int n, struct zx_sa11_SubjectConfirmation_s* z)
{
  struct zx_sa11_SubjectConfirmation_s* y;
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
    for (; y->gg.g.n; y = (struct zx_sa11_SubjectConfirmation_s*)y->gg.g.n) ;
    break;
  default:
    for (y = x->SubjectConfirmation; n > 1 && y; --n, y = (struct zx_sa11_SubjectConfirmation_s*)y->gg.g.n) ;
    if (!y) return;
  }
  z->gg.g.n = y->gg.g.n;
  y->gg.g.n = &z->gg.g;
}

/* FUNC(zx_sa11_Subject_DEL_SubjectConfirmation) */

void zx_sa11_Subject_DEL_SubjectConfirmation(struct zx_sa11_Subject_s* x, int n)
{
  struct zx_sa11_SubjectConfirmation_s* y;
  if (!x) return;
  switch (n) {
  case 0:
    x->SubjectConfirmation = (struct zx_sa11_SubjectConfirmation_s*)x->SubjectConfirmation->gg.g.n;
    return;
  case -1:
    y = (struct zx_sa11_SubjectConfirmation_s*)x->SubjectConfirmation;
    if (!y) return;
    for (; y->gg.g.n; y = (struct zx_sa11_SubjectConfirmation_s*)y->gg.g.n) ;
    break;
  default:
    for (y = x->SubjectConfirmation; n > 1 && y->gg.g.n; --n, y = (struct zx_sa11_SubjectConfirmation_s*)y->gg.g.n) ;
    if (!y->gg.g.n) return;
  }
  y->gg.g.n = y->gg.g.n->n;
}

#endif








#ifdef ZX_ENA_GETPUT

/* FUNC(zx_sa11_SubjectConfirmation_NUM_ConfirmationMethod) */

int zx_sa11_SubjectConfirmation_NUM_ConfirmationMethod(struct zx_sa11_SubjectConfirmation_s* x)
{
  struct zx_elem_s* y;
  int n = 0;
  if (!x) return 0;
  for (y = x->ConfirmationMethod; y; ++n, y = (struct zx_elem_s*)y->g.n) ;
  return n;
}

/* FUNC(zx_sa11_SubjectConfirmation_GET_ConfirmationMethod) */

struct zx_elem_s* zx_sa11_SubjectConfirmation_GET_ConfirmationMethod(struct zx_sa11_SubjectConfirmation_s* x, int n)
{
  struct zx_elem_s* y;
  if (!x) return 0;
  for (y = x->ConfirmationMethod; n>=0 && y; --n, y = (struct zx_elem_s*)y->g.n) ;
  return y;
}

/* FUNC(zx_sa11_SubjectConfirmation_POP_ConfirmationMethod) */

struct zx_elem_s* zx_sa11_SubjectConfirmation_POP_ConfirmationMethod(struct zx_sa11_SubjectConfirmation_s* x)
{
  struct zx_elem_s* y;
  if (!x) return 0;
  y = x->ConfirmationMethod;
  if (y)
    x->ConfirmationMethod = (struct zx_elem_s*)y->g.n;
  return y;
}

/* FUNC(zx_sa11_SubjectConfirmation_PUSH_ConfirmationMethod) */

void zx_sa11_SubjectConfirmation_PUSH_ConfirmationMethod(struct zx_sa11_SubjectConfirmation_s* x, struct zx_elem_s* z)
{
  if (!x || !z) return;
  z->g.n = &x->ConfirmationMethod->g;
  x->ConfirmationMethod = z;
}

/* FUNC(zx_sa11_SubjectConfirmation_REV_ConfirmationMethod) */

void zx_sa11_SubjectConfirmation_REV_ConfirmationMethod(struct zx_sa11_SubjectConfirmation_s* x)
{
  struct zx_elem_s* nxt;
  struct zx_elem_s* y;
  if (!x) return;
  y = x->ConfirmationMethod;
  if (!y) return;
  x->ConfirmationMethod = 0;
  while (y) {
    nxt = (struct zx_elem_s*)y->g.n;
    y->g.n = &x->ConfirmationMethod->g;
    x->ConfirmationMethod = y;
    y = nxt;
  }
}

/* FUNC(zx_sa11_SubjectConfirmation_PUT_ConfirmationMethod) */

void zx_sa11_SubjectConfirmation_PUT_ConfirmationMethod(struct zx_sa11_SubjectConfirmation_s* x, int n, struct zx_elem_s* z)
{
  struct zx_elem_s* y;
  if (!x || !z) return;
  y = x->ConfirmationMethod;
  if (!y) return;
  switch (n) {
  case 0:
    z->g.n = y->g.n;
    x->ConfirmationMethod = z;
    return;
  default:
    for (; n > 1 && y->g.n; --n, y = (struct zx_elem_s*)y->g.n) ;
    if (!y->g.n) return;
    z->g.n = y->g.n->n;
    y->g.n = &z->g;
  }
}

/* FUNC(zx_sa11_SubjectConfirmation_ADD_ConfirmationMethod) */

void zx_sa11_SubjectConfirmation_ADD_ConfirmationMethod(struct zx_sa11_SubjectConfirmation_s* x, int n, struct zx_elem_s* z)
{
  struct zx_elem_s* y;
  if (!x || !z) return;
  switch (n) {
  case 0:
  add_to_start:
    z->g.n = &x->ConfirmationMethod->g;
    x->ConfirmationMethod = z;
    return;
  case -1:
    y = x->ConfirmationMethod;
    if (!y) goto add_to_start;
    for (; y->g.n; y = (struct zx_elem_s*)y->g.n) ;
    break;
  default:
    for (y = x->ConfirmationMethod; n > 1 && y; --n, y = (struct zx_elem_s*)y->g.n) ;
    if (!y) return;
  }
  z->g.n = y->g.n;
  y->g.n = &z->g;
}

/* FUNC(zx_sa11_SubjectConfirmation_DEL_ConfirmationMethod) */

void zx_sa11_SubjectConfirmation_DEL_ConfirmationMethod(struct zx_sa11_SubjectConfirmation_s* x, int n)
{
  struct zx_elem_s* y;
  if (!x) return;
  switch (n) {
  case 0:
    x->ConfirmationMethod = (struct zx_elem_s*)x->ConfirmationMethod->g.n;
    return;
  case -1:
    y = (struct zx_elem_s*)x->ConfirmationMethod;
    if (!y) return;
    for (; y->g.n; y = (struct zx_elem_s*)y->g.n) ;
    break;
  default:
    for (y = x->ConfirmationMethod; n > 1 && y->g.n; --n, y = (struct zx_elem_s*)y->g.n) ;
    if (!y->g.n) return;
  }
  y->g.n = y->g.n->n;
}

#endif



#ifdef ZX_ENA_GETPUT

/* FUNC(zx_sa11_SubjectConfirmation_NUM_SubjectConfirmationData) */

int zx_sa11_SubjectConfirmation_NUM_SubjectConfirmationData(struct zx_sa11_SubjectConfirmation_s* x)
{
  struct zx_elem_s* y;
  int n = 0;
  if (!x) return 0;
  for (y = x->SubjectConfirmationData; y; ++n, y = (struct zx_elem_s*)y->g.n) ;
  return n;
}

/* FUNC(zx_sa11_SubjectConfirmation_GET_SubjectConfirmationData) */

struct zx_elem_s* zx_sa11_SubjectConfirmation_GET_SubjectConfirmationData(struct zx_sa11_SubjectConfirmation_s* x, int n)
{
  struct zx_elem_s* y;
  if (!x) return 0;
  for (y = x->SubjectConfirmationData; n>=0 && y; --n, y = (struct zx_elem_s*)y->g.n) ;
  return y;
}

/* FUNC(zx_sa11_SubjectConfirmation_POP_SubjectConfirmationData) */

struct zx_elem_s* zx_sa11_SubjectConfirmation_POP_SubjectConfirmationData(struct zx_sa11_SubjectConfirmation_s* x)
{
  struct zx_elem_s* y;
  if (!x) return 0;
  y = x->SubjectConfirmationData;
  if (y)
    x->SubjectConfirmationData = (struct zx_elem_s*)y->g.n;
  return y;
}

/* FUNC(zx_sa11_SubjectConfirmation_PUSH_SubjectConfirmationData) */

void zx_sa11_SubjectConfirmation_PUSH_SubjectConfirmationData(struct zx_sa11_SubjectConfirmation_s* x, struct zx_elem_s* z)
{
  if (!x || !z) return;
  z->g.n = &x->SubjectConfirmationData->g;
  x->SubjectConfirmationData = z;
}

/* FUNC(zx_sa11_SubjectConfirmation_REV_SubjectConfirmationData) */

void zx_sa11_SubjectConfirmation_REV_SubjectConfirmationData(struct zx_sa11_SubjectConfirmation_s* x)
{
  struct zx_elem_s* nxt;
  struct zx_elem_s* y;
  if (!x) return;
  y = x->SubjectConfirmationData;
  if (!y) return;
  x->SubjectConfirmationData = 0;
  while (y) {
    nxt = (struct zx_elem_s*)y->g.n;
    y->g.n = &x->SubjectConfirmationData->g;
    x->SubjectConfirmationData = y;
    y = nxt;
  }
}

/* FUNC(zx_sa11_SubjectConfirmation_PUT_SubjectConfirmationData) */

void zx_sa11_SubjectConfirmation_PUT_SubjectConfirmationData(struct zx_sa11_SubjectConfirmation_s* x, int n, struct zx_elem_s* z)
{
  struct zx_elem_s* y;
  if (!x || !z) return;
  y = x->SubjectConfirmationData;
  if (!y) return;
  switch (n) {
  case 0:
    z->g.n = y->g.n;
    x->SubjectConfirmationData = z;
    return;
  default:
    for (; n > 1 && y->g.n; --n, y = (struct zx_elem_s*)y->g.n) ;
    if (!y->g.n) return;
    z->g.n = y->g.n->n;
    y->g.n = &z->g;
  }
}

/* FUNC(zx_sa11_SubjectConfirmation_ADD_SubjectConfirmationData) */

void zx_sa11_SubjectConfirmation_ADD_SubjectConfirmationData(struct zx_sa11_SubjectConfirmation_s* x, int n, struct zx_elem_s* z)
{
  struct zx_elem_s* y;
  if (!x || !z) return;
  switch (n) {
  case 0:
  add_to_start:
    z->g.n = &x->SubjectConfirmationData->g;
    x->SubjectConfirmationData = z;
    return;
  case -1:
    y = x->SubjectConfirmationData;
    if (!y) goto add_to_start;
    for (; y->g.n; y = (struct zx_elem_s*)y->g.n) ;
    break;
  default:
    for (y = x->SubjectConfirmationData; n > 1 && y; --n, y = (struct zx_elem_s*)y->g.n) ;
    if (!y) return;
  }
  z->g.n = y->g.n;
  y->g.n = &z->g;
}

/* FUNC(zx_sa11_SubjectConfirmation_DEL_SubjectConfirmationData) */

void zx_sa11_SubjectConfirmation_DEL_SubjectConfirmationData(struct zx_sa11_SubjectConfirmation_s* x, int n)
{
  struct zx_elem_s* y;
  if (!x) return;
  switch (n) {
  case 0:
    x->SubjectConfirmationData = (struct zx_elem_s*)x->SubjectConfirmationData->g.n;
    return;
  case -1:
    y = (struct zx_elem_s*)x->SubjectConfirmationData;
    if (!y) return;
    for (; y->g.n; y = (struct zx_elem_s*)y->g.n) ;
    break;
  default:
    for (y = x->SubjectConfirmationData; n > 1 && y->g.n; --n, y = (struct zx_elem_s*)y->g.n) ;
    if (!y->g.n) return;
  }
  y->g.n = y->g.n->n;
}

#endif



#ifdef ZX_ENA_GETPUT

/* FUNC(zx_sa11_SubjectConfirmation_NUM_KeyInfo) */

int zx_sa11_SubjectConfirmation_NUM_KeyInfo(struct zx_sa11_SubjectConfirmation_s* x)
{
  struct zx_ds_KeyInfo_s* y;
  int n = 0;
  if (!x) return 0;
  for (y = x->KeyInfo; y; ++n, y = (struct zx_ds_KeyInfo_s*)y->gg.g.n) ;
  return n;
}

/* FUNC(zx_sa11_SubjectConfirmation_GET_KeyInfo) */

struct zx_ds_KeyInfo_s* zx_sa11_SubjectConfirmation_GET_KeyInfo(struct zx_sa11_SubjectConfirmation_s* x, int n)
{
  struct zx_ds_KeyInfo_s* y;
  if (!x) return 0;
  for (y = x->KeyInfo; n>=0 && y; --n, y = (struct zx_ds_KeyInfo_s*)y->gg.g.n) ;
  return y;
}

/* FUNC(zx_sa11_SubjectConfirmation_POP_KeyInfo) */

struct zx_ds_KeyInfo_s* zx_sa11_SubjectConfirmation_POP_KeyInfo(struct zx_sa11_SubjectConfirmation_s* x)
{
  struct zx_ds_KeyInfo_s* y;
  if (!x) return 0;
  y = x->KeyInfo;
  if (y)
    x->KeyInfo = (struct zx_ds_KeyInfo_s*)y->gg.g.n;
  return y;
}

/* FUNC(zx_sa11_SubjectConfirmation_PUSH_KeyInfo) */

void zx_sa11_SubjectConfirmation_PUSH_KeyInfo(struct zx_sa11_SubjectConfirmation_s* x, struct zx_ds_KeyInfo_s* z)
{
  if (!x || !z) return;
  z->gg.g.n = &x->KeyInfo->gg.g;
  x->KeyInfo = z;
}

/* FUNC(zx_sa11_SubjectConfirmation_REV_KeyInfo) */

void zx_sa11_SubjectConfirmation_REV_KeyInfo(struct zx_sa11_SubjectConfirmation_s* x)
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

/* FUNC(zx_sa11_SubjectConfirmation_PUT_KeyInfo) */

void zx_sa11_SubjectConfirmation_PUT_KeyInfo(struct zx_sa11_SubjectConfirmation_s* x, int n, struct zx_ds_KeyInfo_s* z)
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

/* FUNC(zx_sa11_SubjectConfirmation_ADD_KeyInfo) */

void zx_sa11_SubjectConfirmation_ADD_KeyInfo(struct zx_sa11_SubjectConfirmation_s* x, int n, struct zx_ds_KeyInfo_s* z)
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

/* FUNC(zx_sa11_SubjectConfirmation_DEL_KeyInfo) */

void zx_sa11_SubjectConfirmation_DEL_KeyInfo(struct zx_sa11_SubjectConfirmation_s* x, int n)
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






/* FUNC(zx_sa11_SubjectLocality_GET_DNSAddress) */
struct zx_str* zx_sa11_SubjectLocality_GET_DNSAddress(struct zx_sa11_SubjectLocality_s* x) { return x->DNSAddress; }
/* FUNC(zx_sa11_SubjectLocality_PUT_DNSAddress) */
void zx_sa11_SubjectLocality_PUT_DNSAddress(struct zx_sa11_SubjectLocality_s* x, struct zx_str* y) { x->DNSAddress = y; }
/* FUNC(zx_sa11_SubjectLocality_GET_IPAddress) */
struct zx_str* zx_sa11_SubjectLocality_GET_IPAddress(struct zx_sa11_SubjectLocality_s* x) { return x->IPAddress; }
/* FUNC(zx_sa11_SubjectLocality_PUT_IPAddress) */
void zx_sa11_SubjectLocality_PUT_IPAddress(struct zx_sa11_SubjectLocality_s* x, struct zx_str* y) { x->IPAddress = y; }







#ifdef ZX_ENA_GETPUT

/* FUNC(zx_sa11_SubjectStatement_NUM_Subject) */

int zx_sa11_SubjectStatement_NUM_Subject(struct zx_sa11_SubjectStatement_s* x)
{
  struct zx_sa11_Subject_s* y;
  int n = 0;
  if (!x) return 0;
  for (y = x->Subject; y; ++n, y = (struct zx_sa11_Subject_s*)y->gg.g.n) ;
  return n;
}

/* FUNC(zx_sa11_SubjectStatement_GET_Subject) */

struct zx_sa11_Subject_s* zx_sa11_SubjectStatement_GET_Subject(struct zx_sa11_SubjectStatement_s* x, int n)
{
  struct zx_sa11_Subject_s* y;
  if (!x) return 0;
  for (y = x->Subject; n>=0 && y; --n, y = (struct zx_sa11_Subject_s*)y->gg.g.n) ;
  return y;
}

/* FUNC(zx_sa11_SubjectStatement_POP_Subject) */

struct zx_sa11_Subject_s* zx_sa11_SubjectStatement_POP_Subject(struct zx_sa11_SubjectStatement_s* x)
{
  struct zx_sa11_Subject_s* y;
  if (!x) return 0;
  y = x->Subject;
  if (y)
    x->Subject = (struct zx_sa11_Subject_s*)y->gg.g.n;
  return y;
}

/* FUNC(zx_sa11_SubjectStatement_PUSH_Subject) */

void zx_sa11_SubjectStatement_PUSH_Subject(struct zx_sa11_SubjectStatement_s* x, struct zx_sa11_Subject_s* z)
{
  if (!x || !z) return;
  z->gg.g.n = &x->Subject->gg.g;
  x->Subject = z;
}

/* FUNC(zx_sa11_SubjectStatement_REV_Subject) */

void zx_sa11_SubjectStatement_REV_Subject(struct zx_sa11_SubjectStatement_s* x)
{
  struct zx_sa11_Subject_s* nxt;
  struct zx_sa11_Subject_s* y;
  if (!x) return;
  y = x->Subject;
  if (!y) return;
  x->Subject = 0;
  while (y) {
    nxt = (struct zx_sa11_Subject_s*)y->gg.g.n;
    y->gg.g.n = &x->Subject->gg.g;
    x->Subject = y;
    y = nxt;
  }
}

/* FUNC(zx_sa11_SubjectStatement_PUT_Subject) */

void zx_sa11_SubjectStatement_PUT_Subject(struct zx_sa11_SubjectStatement_s* x, int n, struct zx_sa11_Subject_s* z)
{
  struct zx_sa11_Subject_s* y;
  if (!x || !z) return;
  y = x->Subject;
  if (!y) return;
  switch (n) {
  case 0:
    z->gg.g.n = y->gg.g.n;
    x->Subject = z;
    return;
  default:
    for (; n > 1 && y->gg.g.n; --n, y = (struct zx_sa11_Subject_s*)y->gg.g.n) ;
    if (!y->gg.g.n) return;
    z->gg.g.n = y->gg.g.n->n;
    y->gg.g.n = &z->gg.g;
  }
}

/* FUNC(zx_sa11_SubjectStatement_ADD_Subject) */

void zx_sa11_SubjectStatement_ADD_Subject(struct zx_sa11_SubjectStatement_s* x, int n, struct zx_sa11_Subject_s* z)
{
  struct zx_sa11_Subject_s* y;
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
    for (; y->gg.g.n; y = (struct zx_sa11_Subject_s*)y->gg.g.n) ;
    break;
  default:
    for (y = x->Subject; n > 1 && y; --n, y = (struct zx_sa11_Subject_s*)y->gg.g.n) ;
    if (!y) return;
  }
  z->gg.g.n = y->gg.g.n;
  y->gg.g.n = &z->gg.g;
}

/* FUNC(zx_sa11_SubjectStatement_DEL_Subject) */

void zx_sa11_SubjectStatement_DEL_Subject(struct zx_sa11_SubjectStatement_s* x, int n)
{
  struct zx_sa11_Subject_s* y;
  if (!x) return;
  switch (n) {
  case 0:
    x->Subject = (struct zx_sa11_Subject_s*)x->Subject->gg.g.n;
    return;
  case -1:
    y = (struct zx_sa11_Subject_s*)x->Subject;
    if (!y) return;
    for (; y->gg.g.n; y = (struct zx_sa11_Subject_s*)y->gg.g.n) ;
    break;
  default:
    for (y = x->Subject; n > 1 && y->gg.g.n; --n, y = (struct zx_sa11_Subject_s*)y->gg.g.n) ;
    if (!y->gg.g.n) return;
  }
  y->gg.g.n = y->gg.g.n->n;
}

#endif






/* EOF -- c/zx-sa11-getput.c */
