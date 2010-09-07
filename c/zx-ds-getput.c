/* c/zx-ds-getput.c - WARNING: This file was automatically generated. DO NOT EDIT!
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
#include "c/zx-ds-data.h"

/* FUNC(zx_ds_CanonicalizationMethod_GET_Algorithm) */
struct zx_str* zx_ds_CanonicalizationMethod_GET_Algorithm(struct zx_ds_CanonicalizationMethod_s* x) { return x->Algorithm; }
/* FUNC(zx_ds_CanonicalizationMethod_PUT_Algorithm) */
void zx_ds_CanonicalizationMethod_PUT_Algorithm(struct zx_ds_CanonicalizationMethod_s* x, struct zx_str* y) { x->Algorithm = y; }







#ifdef ZX_ENA_GETPUT

/* FUNC(zx_ds_DSAKeyValue_NUM_P) */

int zx_ds_DSAKeyValue_NUM_P(struct zx_ds_DSAKeyValue_s* x)
{
  struct zx_elem_s* y;
  int n = 0;
  if (!x) return 0;
  for (y = x->P; y; ++n, y = (struct zx_elem_s*)y->g.n) ;
  return n;
}

/* FUNC(zx_ds_DSAKeyValue_GET_P) */

struct zx_elem_s* zx_ds_DSAKeyValue_GET_P(struct zx_ds_DSAKeyValue_s* x, int n)
{
  struct zx_elem_s* y;
  if (!x) return 0;
  for (y = x->P; n>=0 && y; --n, y = (struct zx_elem_s*)y->g.n) ;
  return y;
}

/* FUNC(zx_ds_DSAKeyValue_POP_P) */

struct zx_elem_s* zx_ds_DSAKeyValue_POP_P(struct zx_ds_DSAKeyValue_s* x)
{
  struct zx_elem_s* y;
  if (!x) return 0;
  y = x->P;
  if (y)
    x->P = (struct zx_elem_s*)y->g.n;
  return y;
}

/* FUNC(zx_ds_DSAKeyValue_PUSH_P) */

void zx_ds_DSAKeyValue_PUSH_P(struct zx_ds_DSAKeyValue_s* x, struct zx_elem_s* z)
{
  if (!x || !z) return;
  z->g.n = &x->P->g;
  x->P = z;
}

/* FUNC(zx_ds_DSAKeyValue_REV_P) */

void zx_ds_DSAKeyValue_REV_P(struct zx_ds_DSAKeyValue_s* x)
{
  struct zx_elem_s* nxt;
  struct zx_elem_s* y;
  if (!x) return;
  y = x->P;
  if (!y) return;
  x->P = 0;
  while (y) {
    nxt = (struct zx_elem_s*)y->g.n;
    y->g.n = &x->P->g;
    x->P = y;
    y = nxt;
  }
}

/* FUNC(zx_ds_DSAKeyValue_PUT_P) */

void zx_ds_DSAKeyValue_PUT_P(struct zx_ds_DSAKeyValue_s* x, int n, struct zx_elem_s* z)
{
  struct zx_elem_s* y;
  if (!x || !z) return;
  y = x->P;
  if (!y) return;
  switch (n) {
  case 0:
    z->g.n = y->g.n;
    x->P = z;
    return;
  default:
    for (; n > 1 && y->g.n; --n, y = (struct zx_elem_s*)y->g.n) ;
    if (!y->g.n) return;
    z->g.n = y->g.n->n;
    y->g.n = &z->g;
  }
}

/* FUNC(zx_ds_DSAKeyValue_ADD_P) */

void zx_ds_DSAKeyValue_ADD_P(struct zx_ds_DSAKeyValue_s* x, int n, struct zx_elem_s* z)
{
  struct zx_elem_s* y;
  if (!x || !z) return;
  switch (n) {
  case 0:
  add_to_start:
    z->g.n = &x->P->g;
    x->P = z;
    return;
  case -1:
    y = x->P;
    if (!y) goto add_to_start;
    for (; y->g.n; y = (struct zx_elem_s*)y->g.n) ;
    break;
  default:
    for (y = x->P; n > 1 && y; --n, y = (struct zx_elem_s*)y->g.n) ;
    if (!y) return;
  }
  z->g.n = y->g.n;
  y->g.n = &z->g;
}

/* FUNC(zx_ds_DSAKeyValue_DEL_P) */

void zx_ds_DSAKeyValue_DEL_P(struct zx_ds_DSAKeyValue_s* x, int n)
{
  struct zx_elem_s* y;
  if (!x) return;
  switch (n) {
  case 0:
    x->P = (struct zx_elem_s*)x->P->g.n;
    return;
  case -1:
    y = (struct zx_elem_s*)x->P;
    if (!y) return;
    for (; y->g.n; y = (struct zx_elem_s*)y->g.n) ;
    break;
  default:
    for (y = x->P; n > 1 && y->g.n; --n, y = (struct zx_elem_s*)y->g.n) ;
    if (!y->g.n) return;
  }
  y->g.n = y->g.n->n;
}

#endif



#ifdef ZX_ENA_GETPUT

/* FUNC(zx_ds_DSAKeyValue_NUM_Q) */

int zx_ds_DSAKeyValue_NUM_Q(struct zx_ds_DSAKeyValue_s* x)
{
  struct zx_elem_s* y;
  int n = 0;
  if (!x) return 0;
  for (y = x->Q; y; ++n, y = (struct zx_elem_s*)y->g.n) ;
  return n;
}

/* FUNC(zx_ds_DSAKeyValue_GET_Q) */

struct zx_elem_s* zx_ds_DSAKeyValue_GET_Q(struct zx_ds_DSAKeyValue_s* x, int n)
{
  struct zx_elem_s* y;
  if (!x) return 0;
  for (y = x->Q; n>=0 && y; --n, y = (struct zx_elem_s*)y->g.n) ;
  return y;
}

/* FUNC(zx_ds_DSAKeyValue_POP_Q) */

struct zx_elem_s* zx_ds_DSAKeyValue_POP_Q(struct zx_ds_DSAKeyValue_s* x)
{
  struct zx_elem_s* y;
  if (!x) return 0;
  y = x->Q;
  if (y)
    x->Q = (struct zx_elem_s*)y->g.n;
  return y;
}

/* FUNC(zx_ds_DSAKeyValue_PUSH_Q) */

void zx_ds_DSAKeyValue_PUSH_Q(struct zx_ds_DSAKeyValue_s* x, struct zx_elem_s* z)
{
  if (!x || !z) return;
  z->g.n = &x->Q->g;
  x->Q = z;
}

/* FUNC(zx_ds_DSAKeyValue_REV_Q) */

void zx_ds_DSAKeyValue_REV_Q(struct zx_ds_DSAKeyValue_s* x)
{
  struct zx_elem_s* nxt;
  struct zx_elem_s* y;
  if (!x) return;
  y = x->Q;
  if (!y) return;
  x->Q = 0;
  while (y) {
    nxt = (struct zx_elem_s*)y->g.n;
    y->g.n = &x->Q->g;
    x->Q = y;
    y = nxt;
  }
}

/* FUNC(zx_ds_DSAKeyValue_PUT_Q) */

void zx_ds_DSAKeyValue_PUT_Q(struct zx_ds_DSAKeyValue_s* x, int n, struct zx_elem_s* z)
{
  struct zx_elem_s* y;
  if (!x || !z) return;
  y = x->Q;
  if (!y) return;
  switch (n) {
  case 0:
    z->g.n = y->g.n;
    x->Q = z;
    return;
  default:
    for (; n > 1 && y->g.n; --n, y = (struct zx_elem_s*)y->g.n) ;
    if (!y->g.n) return;
    z->g.n = y->g.n->n;
    y->g.n = &z->g;
  }
}

/* FUNC(zx_ds_DSAKeyValue_ADD_Q) */

void zx_ds_DSAKeyValue_ADD_Q(struct zx_ds_DSAKeyValue_s* x, int n, struct zx_elem_s* z)
{
  struct zx_elem_s* y;
  if (!x || !z) return;
  switch (n) {
  case 0:
  add_to_start:
    z->g.n = &x->Q->g;
    x->Q = z;
    return;
  case -1:
    y = x->Q;
    if (!y) goto add_to_start;
    for (; y->g.n; y = (struct zx_elem_s*)y->g.n) ;
    break;
  default:
    for (y = x->Q; n > 1 && y; --n, y = (struct zx_elem_s*)y->g.n) ;
    if (!y) return;
  }
  z->g.n = y->g.n;
  y->g.n = &z->g;
}

/* FUNC(zx_ds_DSAKeyValue_DEL_Q) */

void zx_ds_DSAKeyValue_DEL_Q(struct zx_ds_DSAKeyValue_s* x, int n)
{
  struct zx_elem_s* y;
  if (!x) return;
  switch (n) {
  case 0:
    x->Q = (struct zx_elem_s*)x->Q->g.n;
    return;
  case -1:
    y = (struct zx_elem_s*)x->Q;
    if (!y) return;
    for (; y->g.n; y = (struct zx_elem_s*)y->g.n) ;
    break;
  default:
    for (y = x->Q; n > 1 && y->g.n; --n, y = (struct zx_elem_s*)y->g.n) ;
    if (!y->g.n) return;
  }
  y->g.n = y->g.n->n;
}

#endif



#ifdef ZX_ENA_GETPUT

/* FUNC(zx_ds_DSAKeyValue_NUM_G) */

int zx_ds_DSAKeyValue_NUM_G(struct zx_ds_DSAKeyValue_s* x)
{
  struct zx_elem_s* y;
  int n = 0;
  if (!x) return 0;
  for (y = x->G; y; ++n, y = (struct zx_elem_s*)y->g.n) ;
  return n;
}

/* FUNC(zx_ds_DSAKeyValue_GET_G) */

struct zx_elem_s* zx_ds_DSAKeyValue_GET_G(struct zx_ds_DSAKeyValue_s* x, int n)
{
  struct zx_elem_s* y;
  if (!x) return 0;
  for (y = x->G; n>=0 && y; --n, y = (struct zx_elem_s*)y->g.n) ;
  return y;
}

/* FUNC(zx_ds_DSAKeyValue_POP_G) */

struct zx_elem_s* zx_ds_DSAKeyValue_POP_G(struct zx_ds_DSAKeyValue_s* x)
{
  struct zx_elem_s* y;
  if (!x) return 0;
  y = x->G;
  if (y)
    x->G = (struct zx_elem_s*)y->g.n;
  return y;
}

/* FUNC(zx_ds_DSAKeyValue_PUSH_G) */

void zx_ds_DSAKeyValue_PUSH_G(struct zx_ds_DSAKeyValue_s* x, struct zx_elem_s* z)
{
  if (!x || !z) return;
  z->g.n = &x->G->g;
  x->G = z;
}

/* FUNC(zx_ds_DSAKeyValue_REV_G) */

void zx_ds_DSAKeyValue_REV_G(struct zx_ds_DSAKeyValue_s* x)
{
  struct zx_elem_s* nxt;
  struct zx_elem_s* y;
  if (!x) return;
  y = x->G;
  if (!y) return;
  x->G = 0;
  while (y) {
    nxt = (struct zx_elem_s*)y->g.n;
    y->g.n = &x->G->g;
    x->G = y;
    y = nxt;
  }
}

/* FUNC(zx_ds_DSAKeyValue_PUT_G) */

void zx_ds_DSAKeyValue_PUT_G(struct zx_ds_DSAKeyValue_s* x, int n, struct zx_elem_s* z)
{
  struct zx_elem_s* y;
  if (!x || !z) return;
  y = x->G;
  if (!y) return;
  switch (n) {
  case 0:
    z->g.n = y->g.n;
    x->G = z;
    return;
  default:
    for (; n > 1 && y->g.n; --n, y = (struct zx_elem_s*)y->g.n) ;
    if (!y->g.n) return;
    z->g.n = y->g.n->n;
    y->g.n = &z->g;
  }
}

/* FUNC(zx_ds_DSAKeyValue_ADD_G) */

void zx_ds_DSAKeyValue_ADD_G(struct zx_ds_DSAKeyValue_s* x, int n, struct zx_elem_s* z)
{
  struct zx_elem_s* y;
  if (!x || !z) return;
  switch (n) {
  case 0:
  add_to_start:
    z->g.n = &x->G->g;
    x->G = z;
    return;
  case -1:
    y = x->G;
    if (!y) goto add_to_start;
    for (; y->g.n; y = (struct zx_elem_s*)y->g.n) ;
    break;
  default:
    for (y = x->G; n > 1 && y; --n, y = (struct zx_elem_s*)y->g.n) ;
    if (!y) return;
  }
  z->g.n = y->g.n;
  y->g.n = &z->g;
}

/* FUNC(zx_ds_DSAKeyValue_DEL_G) */

void zx_ds_DSAKeyValue_DEL_G(struct zx_ds_DSAKeyValue_s* x, int n)
{
  struct zx_elem_s* y;
  if (!x) return;
  switch (n) {
  case 0:
    x->G = (struct zx_elem_s*)x->G->g.n;
    return;
  case -1:
    y = (struct zx_elem_s*)x->G;
    if (!y) return;
    for (; y->g.n; y = (struct zx_elem_s*)y->g.n) ;
    break;
  default:
    for (y = x->G; n > 1 && y->g.n; --n, y = (struct zx_elem_s*)y->g.n) ;
    if (!y->g.n) return;
  }
  y->g.n = y->g.n->n;
}

#endif



#ifdef ZX_ENA_GETPUT

/* FUNC(zx_ds_DSAKeyValue_NUM_Y) */

int zx_ds_DSAKeyValue_NUM_Y(struct zx_ds_DSAKeyValue_s* x)
{
  struct zx_elem_s* y;
  int n = 0;
  if (!x) return 0;
  for (y = x->Y; y; ++n, y = (struct zx_elem_s*)y->g.n) ;
  return n;
}

/* FUNC(zx_ds_DSAKeyValue_GET_Y) */

struct zx_elem_s* zx_ds_DSAKeyValue_GET_Y(struct zx_ds_DSAKeyValue_s* x, int n)
{
  struct zx_elem_s* y;
  if (!x) return 0;
  for (y = x->Y; n>=0 && y; --n, y = (struct zx_elem_s*)y->g.n) ;
  return y;
}

/* FUNC(zx_ds_DSAKeyValue_POP_Y) */

struct zx_elem_s* zx_ds_DSAKeyValue_POP_Y(struct zx_ds_DSAKeyValue_s* x)
{
  struct zx_elem_s* y;
  if (!x) return 0;
  y = x->Y;
  if (y)
    x->Y = (struct zx_elem_s*)y->g.n;
  return y;
}

/* FUNC(zx_ds_DSAKeyValue_PUSH_Y) */

void zx_ds_DSAKeyValue_PUSH_Y(struct zx_ds_DSAKeyValue_s* x, struct zx_elem_s* z)
{
  if (!x || !z) return;
  z->g.n = &x->Y->g;
  x->Y = z;
}

/* FUNC(zx_ds_DSAKeyValue_REV_Y) */

void zx_ds_DSAKeyValue_REV_Y(struct zx_ds_DSAKeyValue_s* x)
{
  struct zx_elem_s* nxt;
  struct zx_elem_s* y;
  if (!x) return;
  y = x->Y;
  if (!y) return;
  x->Y = 0;
  while (y) {
    nxt = (struct zx_elem_s*)y->g.n;
    y->g.n = &x->Y->g;
    x->Y = y;
    y = nxt;
  }
}

/* FUNC(zx_ds_DSAKeyValue_PUT_Y) */

void zx_ds_DSAKeyValue_PUT_Y(struct zx_ds_DSAKeyValue_s* x, int n, struct zx_elem_s* z)
{
  struct zx_elem_s* y;
  if (!x || !z) return;
  y = x->Y;
  if (!y) return;
  switch (n) {
  case 0:
    z->g.n = y->g.n;
    x->Y = z;
    return;
  default:
    for (; n > 1 && y->g.n; --n, y = (struct zx_elem_s*)y->g.n) ;
    if (!y->g.n) return;
    z->g.n = y->g.n->n;
    y->g.n = &z->g;
  }
}

/* FUNC(zx_ds_DSAKeyValue_ADD_Y) */

void zx_ds_DSAKeyValue_ADD_Y(struct zx_ds_DSAKeyValue_s* x, int n, struct zx_elem_s* z)
{
  struct zx_elem_s* y;
  if (!x || !z) return;
  switch (n) {
  case 0:
  add_to_start:
    z->g.n = &x->Y->g;
    x->Y = z;
    return;
  case -1:
    y = x->Y;
    if (!y) goto add_to_start;
    for (; y->g.n; y = (struct zx_elem_s*)y->g.n) ;
    break;
  default:
    for (y = x->Y; n > 1 && y; --n, y = (struct zx_elem_s*)y->g.n) ;
    if (!y) return;
  }
  z->g.n = y->g.n;
  y->g.n = &z->g;
}

/* FUNC(zx_ds_DSAKeyValue_DEL_Y) */

void zx_ds_DSAKeyValue_DEL_Y(struct zx_ds_DSAKeyValue_s* x, int n)
{
  struct zx_elem_s* y;
  if (!x) return;
  switch (n) {
  case 0:
    x->Y = (struct zx_elem_s*)x->Y->g.n;
    return;
  case -1:
    y = (struct zx_elem_s*)x->Y;
    if (!y) return;
    for (; y->g.n; y = (struct zx_elem_s*)y->g.n) ;
    break;
  default:
    for (y = x->Y; n > 1 && y->g.n; --n, y = (struct zx_elem_s*)y->g.n) ;
    if (!y->g.n) return;
  }
  y->g.n = y->g.n->n;
}

#endif



#ifdef ZX_ENA_GETPUT

/* FUNC(zx_ds_DSAKeyValue_NUM_J) */

int zx_ds_DSAKeyValue_NUM_J(struct zx_ds_DSAKeyValue_s* x)
{
  struct zx_elem_s* y;
  int n = 0;
  if (!x) return 0;
  for (y = x->J; y; ++n, y = (struct zx_elem_s*)y->g.n) ;
  return n;
}

/* FUNC(zx_ds_DSAKeyValue_GET_J) */

struct zx_elem_s* zx_ds_DSAKeyValue_GET_J(struct zx_ds_DSAKeyValue_s* x, int n)
{
  struct zx_elem_s* y;
  if (!x) return 0;
  for (y = x->J; n>=0 && y; --n, y = (struct zx_elem_s*)y->g.n) ;
  return y;
}

/* FUNC(zx_ds_DSAKeyValue_POP_J) */

struct zx_elem_s* zx_ds_DSAKeyValue_POP_J(struct zx_ds_DSAKeyValue_s* x)
{
  struct zx_elem_s* y;
  if (!x) return 0;
  y = x->J;
  if (y)
    x->J = (struct zx_elem_s*)y->g.n;
  return y;
}

/* FUNC(zx_ds_DSAKeyValue_PUSH_J) */

void zx_ds_DSAKeyValue_PUSH_J(struct zx_ds_DSAKeyValue_s* x, struct zx_elem_s* z)
{
  if (!x || !z) return;
  z->g.n = &x->J->g;
  x->J = z;
}

/* FUNC(zx_ds_DSAKeyValue_REV_J) */

void zx_ds_DSAKeyValue_REV_J(struct zx_ds_DSAKeyValue_s* x)
{
  struct zx_elem_s* nxt;
  struct zx_elem_s* y;
  if (!x) return;
  y = x->J;
  if (!y) return;
  x->J = 0;
  while (y) {
    nxt = (struct zx_elem_s*)y->g.n;
    y->g.n = &x->J->g;
    x->J = y;
    y = nxt;
  }
}

/* FUNC(zx_ds_DSAKeyValue_PUT_J) */

void zx_ds_DSAKeyValue_PUT_J(struct zx_ds_DSAKeyValue_s* x, int n, struct zx_elem_s* z)
{
  struct zx_elem_s* y;
  if (!x || !z) return;
  y = x->J;
  if (!y) return;
  switch (n) {
  case 0:
    z->g.n = y->g.n;
    x->J = z;
    return;
  default:
    for (; n > 1 && y->g.n; --n, y = (struct zx_elem_s*)y->g.n) ;
    if (!y->g.n) return;
    z->g.n = y->g.n->n;
    y->g.n = &z->g;
  }
}

/* FUNC(zx_ds_DSAKeyValue_ADD_J) */

void zx_ds_DSAKeyValue_ADD_J(struct zx_ds_DSAKeyValue_s* x, int n, struct zx_elem_s* z)
{
  struct zx_elem_s* y;
  if (!x || !z) return;
  switch (n) {
  case 0:
  add_to_start:
    z->g.n = &x->J->g;
    x->J = z;
    return;
  case -1:
    y = x->J;
    if (!y) goto add_to_start;
    for (; y->g.n; y = (struct zx_elem_s*)y->g.n) ;
    break;
  default:
    for (y = x->J; n > 1 && y; --n, y = (struct zx_elem_s*)y->g.n) ;
    if (!y) return;
  }
  z->g.n = y->g.n;
  y->g.n = &z->g;
}

/* FUNC(zx_ds_DSAKeyValue_DEL_J) */

void zx_ds_DSAKeyValue_DEL_J(struct zx_ds_DSAKeyValue_s* x, int n)
{
  struct zx_elem_s* y;
  if (!x) return;
  switch (n) {
  case 0:
    x->J = (struct zx_elem_s*)x->J->g.n;
    return;
  case -1:
    y = (struct zx_elem_s*)x->J;
    if (!y) return;
    for (; y->g.n; y = (struct zx_elem_s*)y->g.n) ;
    break;
  default:
    for (y = x->J; n > 1 && y->g.n; --n, y = (struct zx_elem_s*)y->g.n) ;
    if (!y->g.n) return;
  }
  y->g.n = y->g.n->n;
}

#endif



#ifdef ZX_ENA_GETPUT

/* FUNC(zx_ds_DSAKeyValue_NUM_Seed) */

int zx_ds_DSAKeyValue_NUM_Seed(struct zx_ds_DSAKeyValue_s* x)
{
  struct zx_elem_s* y;
  int n = 0;
  if (!x) return 0;
  for (y = x->Seed; y; ++n, y = (struct zx_elem_s*)y->g.n) ;
  return n;
}

/* FUNC(zx_ds_DSAKeyValue_GET_Seed) */

struct zx_elem_s* zx_ds_DSAKeyValue_GET_Seed(struct zx_ds_DSAKeyValue_s* x, int n)
{
  struct zx_elem_s* y;
  if (!x) return 0;
  for (y = x->Seed; n>=0 && y; --n, y = (struct zx_elem_s*)y->g.n) ;
  return y;
}

/* FUNC(zx_ds_DSAKeyValue_POP_Seed) */

struct zx_elem_s* zx_ds_DSAKeyValue_POP_Seed(struct zx_ds_DSAKeyValue_s* x)
{
  struct zx_elem_s* y;
  if (!x) return 0;
  y = x->Seed;
  if (y)
    x->Seed = (struct zx_elem_s*)y->g.n;
  return y;
}

/* FUNC(zx_ds_DSAKeyValue_PUSH_Seed) */

void zx_ds_DSAKeyValue_PUSH_Seed(struct zx_ds_DSAKeyValue_s* x, struct zx_elem_s* z)
{
  if (!x || !z) return;
  z->g.n = &x->Seed->g;
  x->Seed = z;
}

/* FUNC(zx_ds_DSAKeyValue_REV_Seed) */

void zx_ds_DSAKeyValue_REV_Seed(struct zx_ds_DSAKeyValue_s* x)
{
  struct zx_elem_s* nxt;
  struct zx_elem_s* y;
  if (!x) return;
  y = x->Seed;
  if (!y) return;
  x->Seed = 0;
  while (y) {
    nxt = (struct zx_elem_s*)y->g.n;
    y->g.n = &x->Seed->g;
    x->Seed = y;
    y = nxt;
  }
}

/* FUNC(zx_ds_DSAKeyValue_PUT_Seed) */

void zx_ds_DSAKeyValue_PUT_Seed(struct zx_ds_DSAKeyValue_s* x, int n, struct zx_elem_s* z)
{
  struct zx_elem_s* y;
  if (!x || !z) return;
  y = x->Seed;
  if (!y) return;
  switch (n) {
  case 0:
    z->g.n = y->g.n;
    x->Seed = z;
    return;
  default:
    for (; n > 1 && y->g.n; --n, y = (struct zx_elem_s*)y->g.n) ;
    if (!y->g.n) return;
    z->g.n = y->g.n->n;
    y->g.n = &z->g;
  }
}

/* FUNC(zx_ds_DSAKeyValue_ADD_Seed) */

void zx_ds_DSAKeyValue_ADD_Seed(struct zx_ds_DSAKeyValue_s* x, int n, struct zx_elem_s* z)
{
  struct zx_elem_s* y;
  if (!x || !z) return;
  switch (n) {
  case 0:
  add_to_start:
    z->g.n = &x->Seed->g;
    x->Seed = z;
    return;
  case -1:
    y = x->Seed;
    if (!y) goto add_to_start;
    for (; y->g.n; y = (struct zx_elem_s*)y->g.n) ;
    break;
  default:
    for (y = x->Seed; n > 1 && y; --n, y = (struct zx_elem_s*)y->g.n) ;
    if (!y) return;
  }
  z->g.n = y->g.n;
  y->g.n = &z->g;
}

/* FUNC(zx_ds_DSAKeyValue_DEL_Seed) */

void zx_ds_DSAKeyValue_DEL_Seed(struct zx_ds_DSAKeyValue_s* x, int n)
{
  struct zx_elem_s* y;
  if (!x) return;
  switch (n) {
  case 0:
    x->Seed = (struct zx_elem_s*)x->Seed->g.n;
    return;
  case -1:
    y = (struct zx_elem_s*)x->Seed;
    if (!y) return;
    for (; y->g.n; y = (struct zx_elem_s*)y->g.n) ;
    break;
  default:
    for (y = x->Seed; n > 1 && y->g.n; --n, y = (struct zx_elem_s*)y->g.n) ;
    if (!y->g.n) return;
  }
  y->g.n = y->g.n->n;
}

#endif



#ifdef ZX_ENA_GETPUT

/* FUNC(zx_ds_DSAKeyValue_NUM_PgenCounter) */

int zx_ds_DSAKeyValue_NUM_PgenCounter(struct zx_ds_DSAKeyValue_s* x)
{
  struct zx_elem_s* y;
  int n = 0;
  if (!x) return 0;
  for (y = x->PgenCounter; y; ++n, y = (struct zx_elem_s*)y->g.n) ;
  return n;
}

/* FUNC(zx_ds_DSAKeyValue_GET_PgenCounter) */

struct zx_elem_s* zx_ds_DSAKeyValue_GET_PgenCounter(struct zx_ds_DSAKeyValue_s* x, int n)
{
  struct zx_elem_s* y;
  if (!x) return 0;
  for (y = x->PgenCounter; n>=0 && y; --n, y = (struct zx_elem_s*)y->g.n) ;
  return y;
}

/* FUNC(zx_ds_DSAKeyValue_POP_PgenCounter) */

struct zx_elem_s* zx_ds_DSAKeyValue_POP_PgenCounter(struct zx_ds_DSAKeyValue_s* x)
{
  struct zx_elem_s* y;
  if (!x) return 0;
  y = x->PgenCounter;
  if (y)
    x->PgenCounter = (struct zx_elem_s*)y->g.n;
  return y;
}

/* FUNC(zx_ds_DSAKeyValue_PUSH_PgenCounter) */

void zx_ds_DSAKeyValue_PUSH_PgenCounter(struct zx_ds_DSAKeyValue_s* x, struct zx_elem_s* z)
{
  if (!x || !z) return;
  z->g.n = &x->PgenCounter->g;
  x->PgenCounter = z;
}

/* FUNC(zx_ds_DSAKeyValue_REV_PgenCounter) */

void zx_ds_DSAKeyValue_REV_PgenCounter(struct zx_ds_DSAKeyValue_s* x)
{
  struct zx_elem_s* nxt;
  struct zx_elem_s* y;
  if (!x) return;
  y = x->PgenCounter;
  if (!y) return;
  x->PgenCounter = 0;
  while (y) {
    nxt = (struct zx_elem_s*)y->g.n;
    y->g.n = &x->PgenCounter->g;
    x->PgenCounter = y;
    y = nxt;
  }
}

/* FUNC(zx_ds_DSAKeyValue_PUT_PgenCounter) */

void zx_ds_DSAKeyValue_PUT_PgenCounter(struct zx_ds_DSAKeyValue_s* x, int n, struct zx_elem_s* z)
{
  struct zx_elem_s* y;
  if (!x || !z) return;
  y = x->PgenCounter;
  if (!y) return;
  switch (n) {
  case 0:
    z->g.n = y->g.n;
    x->PgenCounter = z;
    return;
  default:
    for (; n > 1 && y->g.n; --n, y = (struct zx_elem_s*)y->g.n) ;
    if (!y->g.n) return;
    z->g.n = y->g.n->n;
    y->g.n = &z->g;
  }
}

/* FUNC(zx_ds_DSAKeyValue_ADD_PgenCounter) */

void zx_ds_DSAKeyValue_ADD_PgenCounter(struct zx_ds_DSAKeyValue_s* x, int n, struct zx_elem_s* z)
{
  struct zx_elem_s* y;
  if (!x || !z) return;
  switch (n) {
  case 0:
  add_to_start:
    z->g.n = &x->PgenCounter->g;
    x->PgenCounter = z;
    return;
  case -1:
    y = x->PgenCounter;
    if (!y) goto add_to_start;
    for (; y->g.n; y = (struct zx_elem_s*)y->g.n) ;
    break;
  default:
    for (y = x->PgenCounter; n > 1 && y; --n, y = (struct zx_elem_s*)y->g.n) ;
    if (!y) return;
  }
  z->g.n = y->g.n;
  y->g.n = &z->g;
}

/* FUNC(zx_ds_DSAKeyValue_DEL_PgenCounter) */

void zx_ds_DSAKeyValue_DEL_PgenCounter(struct zx_ds_DSAKeyValue_s* x, int n)
{
  struct zx_elem_s* y;
  if (!x) return;
  switch (n) {
  case 0:
    x->PgenCounter = (struct zx_elem_s*)x->PgenCounter->g.n;
    return;
  case -1:
    y = (struct zx_elem_s*)x->PgenCounter;
    if (!y) return;
    for (; y->g.n; y = (struct zx_elem_s*)y->g.n) ;
    break;
  default:
    for (y = x->PgenCounter; n > 1 && y->g.n; --n, y = (struct zx_elem_s*)y->g.n) ;
    if (!y->g.n) return;
  }
  y->g.n = y->g.n->n;
}

#endif






/* FUNC(zx_ds_DigestMethod_GET_Algorithm) */
struct zx_str* zx_ds_DigestMethod_GET_Algorithm(struct zx_ds_DigestMethod_s* x) { return x->Algorithm; }
/* FUNC(zx_ds_DigestMethod_PUT_Algorithm) */
void zx_ds_DigestMethod_PUT_Algorithm(struct zx_ds_DigestMethod_s* x, struct zx_str* y) { x->Algorithm = y; }







#ifdef ZX_ENA_GETPUT

/* FUNC(zx_ds_KeyInfo_NUM_KeyName) */

int zx_ds_KeyInfo_NUM_KeyName(struct zx_ds_KeyInfo_s* x)
{
  struct zx_elem_s* y;
  int n = 0;
  if (!x) return 0;
  for (y = x->KeyName; y; ++n, y = (struct zx_elem_s*)y->g.n) ;
  return n;
}

/* FUNC(zx_ds_KeyInfo_GET_KeyName) */

struct zx_elem_s* zx_ds_KeyInfo_GET_KeyName(struct zx_ds_KeyInfo_s* x, int n)
{
  struct zx_elem_s* y;
  if (!x) return 0;
  for (y = x->KeyName; n>=0 && y; --n, y = (struct zx_elem_s*)y->g.n) ;
  return y;
}

/* FUNC(zx_ds_KeyInfo_POP_KeyName) */

struct zx_elem_s* zx_ds_KeyInfo_POP_KeyName(struct zx_ds_KeyInfo_s* x)
{
  struct zx_elem_s* y;
  if (!x) return 0;
  y = x->KeyName;
  if (y)
    x->KeyName = (struct zx_elem_s*)y->g.n;
  return y;
}

/* FUNC(zx_ds_KeyInfo_PUSH_KeyName) */

void zx_ds_KeyInfo_PUSH_KeyName(struct zx_ds_KeyInfo_s* x, struct zx_elem_s* z)
{
  if (!x || !z) return;
  z->g.n = &x->KeyName->g;
  x->KeyName = z;
}

/* FUNC(zx_ds_KeyInfo_REV_KeyName) */

void zx_ds_KeyInfo_REV_KeyName(struct zx_ds_KeyInfo_s* x)
{
  struct zx_elem_s* nxt;
  struct zx_elem_s* y;
  if (!x) return;
  y = x->KeyName;
  if (!y) return;
  x->KeyName = 0;
  while (y) {
    nxt = (struct zx_elem_s*)y->g.n;
    y->g.n = &x->KeyName->g;
    x->KeyName = y;
    y = nxt;
  }
}

/* FUNC(zx_ds_KeyInfo_PUT_KeyName) */

void zx_ds_KeyInfo_PUT_KeyName(struct zx_ds_KeyInfo_s* x, int n, struct zx_elem_s* z)
{
  struct zx_elem_s* y;
  if (!x || !z) return;
  y = x->KeyName;
  if (!y) return;
  switch (n) {
  case 0:
    z->g.n = y->g.n;
    x->KeyName = z;
    return;
  default:
    for (; n > 1 && y->g.n; --n, y = (struct zx_elem_s*)y->g.n) ;
    if (!y->g.n) return;
    z->g.n = y->g.n->n;
    y->g.n = &z->g;
  }
}

/* FUNC(zx_ds_KeyInfo_ADD_KeyName) */

void zx_ds_KeyInfo_ADD_KeyName(struct zx_ds_KeyInfo_s* x, int n, struct zx_elem_s* z)
{
  struct zx_elem_s* y;
  if (!x || !z) return;
  switch (n) {
  case 0:
  add_to_start:
    z->g.n = &x->KeyName->g;
    x->KeyName = z;
    return;
  case -1:
    y = x->KeyName;
    if (!y) goto add_to_start;
    for (; y->g.n; y = (struct zx_elem_s*)y->g.n) ;
    break;
  default:
    for (y = x->KeyName; n > 1 && y; --n, y = (struct zx_elem_s*)y->g.n) ;
    if (!y) return;
  }
  z->g.n = y->g.n;
  y->g.n = &z->g;
}

/* FUNC(zx_ds_KeyInfo_DEL_KeyName) */

void zx_ds_KeyInfo_DEL_KeyName(struct zx_ds_KeyInfo_s* x, int n)
{
  struct zx_elem_s* y;
  if (!x) return;
  switch (n) {
  case 0:
    x->KeyName = (struct zx_elem_s*)x->KeyName->g.n;
    return;
  case -1:
    y = (struct zx_elem_s*)x->KeyName;
    if (!y) return;
    for (; y->g.n; y = (struct zx_elem_s*)y->g.n) ;
    break;
  default:
    for (y = x->KeyName; n > 1 && y->g.n; --n, y = (struct zx_elem_s*)y->g.n) ;
    if (!y->g.n) return;
  }
  y->g.n = y->g.n->n;
}

#endif



#ifdef ZX_ENA_GETPUT

/* FUNC(zx_ds_KeyInfo_NUM_KeyValue) */

int zx_ds_KeyInfo_NUM_KeyValue(struct zx_ds_KeyInfo_s* x)
{
  struct zx_ds_KeyValue_s* y;
  int n = 0;
  if (!x) return 0;
  for (y = x->KeyValue; y; ++n, y = (struct zx_ds_KeyValue_s*)y->gg.g.n) ;
  return n;
}

/* FUNC(zx_ds_KeyInfo_GET_KeyValue) */

struct zx_ds_KeyValue_s* zx_ds_KeyInfo_GET_KeyValue(struct zx_ds_KeyInfo_s* x, int n)
{
  struct zx_ds_KeyValue_s* y;
  if (!x) return 0;
  for (y = x->KeyValue; n>=0 && y; --n, y = (struct zx_ds_KeyValue_s*)y->gg.g.n) ;
  return y;
}

/* FUNC(zx_ds_KeyInfo_POP_KeyValue) */

struct zx_ds_KeyValue_s* zx_ds_KeyInfo_POP_KeyValue(struct zx_ds_KeyInfo_s* x)
{
  struct zx_ds_KeyValue_s* y;
  if (!x) return 0;
  y = x->KeyValue;
  if (y)
    x->KeyValue = (struct zx_ds_KeyValue_s*)y->gg.g.n;
  return y;
}

/* FUNC(zx_ds_KeyInfo_PUSH_KeyValue) */

void zx_ds_KeyInfo_PUSH_KeyValue(struct zx_ds_KeyInfo_s* x, struct zx_ds_KeyValue_s* z)
{
  if (!x || !z) return;
  z->gg.g.n = &x->KeyValue->gg.g;
  x->KeyValue = z;
}

/* FUNC(zx_ds_KeyInfo_REV_KeyValue) */

void zx_ds_KeyInfo_REV_KeyValue(struct zx_ds_KeyInfo_s* x)
{
  struct zx_ds_KeyValue_s* nxt;
  struct zx_ds_KeyValue_s* y;
  if (!x) return;
  y = x->KeyValue;
  if (!y) return;
  x->KeyValue = 0;
  while (y) {
    nxt = (struct zx_ds_KeyValue_s*)y->gg.g.n;
    y->gg.g.n = &x->KeyValue->gg.g;
    x->KeyValue = y;
    y = nxt;
  }
}

/* FUNC(zx_ds_KeyInfo_PUT_KeyValue) */

void zx_ds_KeyInfo_PUT_KeyValue(struct zx_ds_KeyInfo_s* x, int n, struct zx_ds_KeyValue_s* z)
{
  struct zx_ds_KeyValue_s* y;
  if (!x || !z) return;
  y = x->KeyValue;
  if (!y) return;
  switch (n) {
  case 0:
    z->gg.g.n = y->gg.g.n;
    x->KeyValue = z;
    return;
  default:
    for (; n > 1 && y->gg.g.n; --n, y = (struct zx_ds_KeyValue_s*)y->gg.g.n) ;
    if (!y->gg.g.n) return;
    z->gg.g.n = y->gg.g.n->n;
    y->gg.g.n = &z->gg.g;
  }
}

/* FUNC(zx_ds_KeyInfo_ADD_KeyValue) */

void zx_ds_KeyInfo_ADD_KeyValue(struct zx_ds_KeyInfo_s* x, int n, struct zx_ds_KeyValue_s* z)
{
  struct zx_ds_KeyValue_s* y;
  if (!x || !z) return;
  switch (n) {
  case 0:
  add_to_start:
    z->gg.g.n = &x->KeyValue->gg.g;
    x->KeyValue = z;
    return;
  case -1:
    y = x->KeyValue;
    if (!y) goto add_to_start;
    for (; y->gg.g.n; y = (struct zx_ds_KeyValue_s*)y->gg.g.n) ;
    break;
  default:
    for (y = x->KeyValue; n > 1 && y; --n, y = (struct zx_ds_KeyValue_s*)y->gg.g.n) ;
    if (!y) return;
  }
  z->gg.g.n = y->gg.g.n;
  y->gg.g.n = &z->gg.g;
}

/* FUNC(zx_ds_KeyInfo_DEL_KeyValue) */

void zx_ds_KeyInfo_DEL_KeyValue(struct zx_ds_KeyInfo_s* x, int n)
{
  struct zx_ds_KeyValue_s* y;
  if (!x) return;
  switch (n) {
  case 0:
    x->KeyValue = (struct zx_ds_KeyValue_s*)x->KeyValue->gg.g.n;
    return;
  case -1:
    y = (struct zx_ds_KeyValue_s*)x->KeyValue;
    if (!y) return;
    for (; y->gg.g.n; y = (struct zx_ds_KeyValue_s*)y->gg.g.n) ;
    break;
  default:
    for (y = x->KeyValue; n > 1 && y->gg.g.n; --n, y = (struct zx_ds_KeyValue_s*)y->gg.g.n) ;
    if (!y->gg.g.n) return;
  }
  y->gg.g.n = y->gg.g.n->n;
}

#endif



#ifdef ZX_ENA_GETPUT

/* FUNC(zx_ds_KeyInfo_NUM_RetrievalMethod) */

int zx_ds_KeyInfo_NUM_RetrievalMethod(struct zx_ds_KeyInfo_s* x)
{
  struct zx_ds_RetrievalMethod_s* y;
  int n = 0;
  if (!x) return 0;
  for (y = x->RetrievalMethod; y; ++n, y = (struct zx_ds_RetrievalMethod_s*)y->gg.g.n) ;
  return n;
}

/* FUNC(zx_ds_KeyInfo_GET_RetrievalMethod) */

struct zx_ds_RetrievalMethod_s* zx_ds_KeyInfo_GET_RetrievalMethod(struct zx_ds_KeyInfo_s* x, int n)
{
  struct zx_ds_RetrievalMethod_s* y;
  if (!x) return 0;
  for (y = x->RetrievalMethod; n>=0 && y; --n, y = (struct zx_ds_RetrievalMethod_s*)y->gg.g.n) ;
  return y;
}

/* FUNC(zx_ds_KeyInfo_POP_RetrievalMethod) */

struct zx_ds_RetrievalMethod_s* zx_ds_KeyInfo_POP_RetrievalMethod(struct zx_ds_KeyInfo_s* x)
{
  struct zx_ds_RetrievalMethod_s* y;
  if (!x) return 0;
  y = x->RetrievalMethod;
  if (y)
    x->RetrievalMethod = (struct zx_ds_RetrievalMethod_s*)y->gg.g.n;
  return y;
}

/* FUNC(zx_ds_KeyInfo_PUSH_RetrievalMethod) */

void zx_ds_KeyInfo_PUSH_RetrievalMethod(struct zx_ds_KeyInfo_s* x, struct zx_ds_RetrievalMethod_s* z)
{
  if (!x || !z) return;
  z->gg.g.n = &x->RetrievalMethod->gg.g;
  x->RetrievalMethod = z;
}

/* FUNC(zx_ds_KeyInfo_REV_RetrievalMethod) */

void zx_ds_KeyInfo_REV_RetrievalMethod(struct zx_ds_KeyInfo_s* x)
{
  struct zx_ds_RetrievalMethod_s* nxt;
  struct zx_ds_RetrievalMethod_s* y;
  if (!x) return;
  y = x->RetrievalMethod;
  if (!y) return;
  x->RetrievalMethod = 0;
  while (y) {
    nxt = (struct zx_ds_RetrievalMethod_s*)y->gg.g.n;
    y->gg.g.n = &x->RetrievalMethod->gg.g;
    x->RetrievalMethod = y;
    y = nxt;
  }
}

/* FUNC(zx_ds_KeyInfo_PUT_RetrievalMethod) */

void zx_ds_KeyInfo_PUT_RetrievalMethod(struct zx_ds_KeyInfo_s* x, int n, struct zx_ds_RetrievalMethod_s* z)
{
  struct zx_ds_RetrievalMethod_s* y;
  if (!x || !z) return;
  y = x->RetrievalMethod;
  if (!y) return;
  switch (n) {
  case 0:
    z->gg.g.n = y->gg.g.n;
    x->RetrievalMethod = z;
    return;
  default:
    for (; n > 1 && y->gg.g.n; --n, y = (struct zx_ds_RetrievalMethod_s*)y->gg.g.n) ;
    if (!y->gg.g.n) return;
    z->gg.g.n = y->gg.g.n->n;
    y->gg.g.n = &z->gg.g;
  }
}

/* FUNC(zx_ds_KeyInfo_ADD_RetrievalMethod) */

void zx_ds_KeyInfo_ADD_RetrievalMethod(struct zx_ds_KeyInfo_s* x, int n, struct zx_ds_RetrievalMethod_s* z)
{
  struct zx_ds_RetrievalMethod_s* y;
  if (!x || !z) return;
  switch (n) {
  case 0:
  add_to_start:
    z->gg.g.n = &x->RetrievalMethod->gg.g;
    x->RetrievalMethod = z;
    return;
  case -1:
    y = x->RetrievalMethod;
    if (!y) goto add_to_start;
    for (; y->gg.g.n; y = (struct zx_ds_RetrievalMethod_s*)y->gg.g.n) ;
    break;
  default:
    for (y = x->RetrievalMethod; n > 1 && y; --n, y = (struct zx_ds_RetrievalMethod_s*)y->gg.g.n) ;
    if (!y) return;
  }
  z->gg.g.n = y->gg.g.n;
  y->gg.g.n = &z->gg.g;
}

/* FUNC(zx_ds_KeyInfo_DEL_RetrievalMethod) */

void zx_ds_KeyInfo_DEL_RetrievalMethod(struct zx_ds_KeyInfo_s* x, int n)
{
  struct zx_ds_RetrievalMethod_s* y;
  if (!x) return;
  switch (n) {
  case 0:
    x->RetrievalMethod = (struct zx_ds_RetrievalMethod_s*)x->RetrievalMethod->gg.g.n;
    return;
  case -1:
    y = (struct zx_ds_RetrievalMethod_s*)x->RetrievalMethod;
    if (!y) return;
    for (; y->gg.g.n; y = (struct zx_ds_RetrievalMethod_s*)y->gg.g.n) ;
    break;
  default:
    for (y = x->RetrievalMethod; n > 1 && y->gg.g.n; --n, y = (struct zx_ds_RetrievalMethod_s*)y->gg.g.n) ;
    if (!y->gg.g.n) return;
  }
  y->gg.g.n = y->gg.g.n->n;
}

#endif



#ifdef ZX_ENA_GETPUT

/* FUNC(zx_ds_KeyInfo_NUM_X509Data) */

int zx_ds_KeyInfo_NUM_X509Data(struct zx_ds_KeyInfo_s* x)
{
  struct zx_ds_X509Data_s* y;
  int n = 0;
  if (!x) return 0;
  for (y = x->X509Data; y; ++n, y = (struct zx_ds_X509Data_s*)y->gg.g.n) ;
  return n;
}

/* FUNC(zx_ds_KeyInfo_GET_X509Data) */

struct zx_ds_X509Data_s* zx_ds_KeyInfo_GET_X509Data(struct zx_ds_KeyInfo_s* x, int n)
{
  struct zx_ds_X509Data_s* y;
  if (!x) return 0;
  for (y = x->X509Data; n>=0 && y; --n, y = (struct zx_ds_X509Data_s*)y->gg.g.n) ;
  return y;
}

/* FUNC(zx_ds_KeyInfo_POP_X509Data) */

struct zx_ds_X509Data_s* zx_ds_KeyInfo_POP_X509Data(struct zx_ds_KeyInfo_s* x)
{
  struct zx_ds_X509Data_s* y;
  if (!x) return 0;
  y = x->X509Data;
  if (y)
    x->X509Data = (struct zx_ds_X509Data_s*)y->gg.g.n;
  return y;
}

/* FUNC(zx_ds_KeyInfo_PUSH_X509Data) */

void zx_ds_KeyInfo_PUSH_X509Data(struct zx_ds_KeyInfo_s* x, struct zx_ds_X509Data_s* z)
{
  if (!x || !z) return;
  z->gg.g.n = &x->X509Data->gg.g;
  x->X509Data = z;
}

/* FUNC(zx_ds_KeyInfo_REV_X509Data) */

void zx_ds_KeyInfo_REV_X509Data(struct zx_ds_KeyInfo_s* x)
{
  struct zx_ds_X509Data_s* nxt;
  struct zx_ds_X509Data_s* y;
  if (!x) return;
  y = x->X509Data;
  if (!y) return;
  x->X509Data = 0;
  while (y) {
    nxt = (struct zx_ds_X509Data_s*)y->gg.g.n;
    y->gg.g.n = &x->X509Data->gg.g;
    x->X509Data = y;
    y = nxt;
  }
}

/* FUNC(zx_ds_KeyInfo_PUT_X509Data) */

void zx_ds_KeyInfo_PUT_X509Data(struct zx_ds_KeyInfo_s* x, int n, struct zx_ds_X509Data_s* z)
{
  struct zx_ds_X509Data_s* y;
  if (!x || !z) return;
  y = x->X509Data;
  if (!y) return;
  switch (n) {
  case 0:
    z->gg.g.n = y->gg.g.n;
    x->X509Data = z;
    return;
  default:
    for (; n > 1 && y->gg.g.n; --n, y = (struct zx_ds_X509Data_s*)y->gg.g.n) ;
    if (!y->gg.g.n) return;
    z->gg.g.n = y->gg.g.n->n;
    y->gg.g.n = &z->gg.g;
  }
}

/* FUNC(zx_ds_KeyInfo_ADD_X509Data) */

void zx_ds_KeyInfo_ADD_X509Data(struct zx_ds_KeyInfo_s* x, int n, struct zx_ds_X509Data_s* z)
{
  struct zx_ds_X509Data_s* y;
  if (!x || !z) return;
  switch (n) {
  case 0:
  add_to_start:
    z->gg.g.n = &x->X509Data->gg.g;
    x->X509Data = z;
    return;
  case -1:
    y = x->X509Data;
    if (!y) goto add_to_start;
    for (; y->gg.g.n; y = (struct zx_ds_X509Data_s*)y->gg.g.n) ;
    break;
  default:
    for (y = x->X509Data; n > 1 && y; --n, y = (struct zx_ds_X509Data_s*)y->gg.g.n) ;
    if (!y) return;
  }
  z->gg.g.n = y->gg.g.n;
  y->gg.g.n = &z->gg.g;
}

/* FUNC(zx_ds_KeyInfo_DEL_X509Data) */

void zx_ds_KeyInfo_DEL_X509Data(struct zx_ds_KeyInfo_s* x, int n)
{
  struct zx_ds_X509Data_s* y;
  if (!x) return;
  switch (n) {
  case 0:
    x->X509Data = (struct zx_ds_X509Data_s*)x->X509Data->gg.g.n;
    return;
  case -1:
    y = (struct zx_ds_X509Data_s*)x->X509Data;
    if (!y) return;
    for (; y->gg.g.n; y = (struct zx_ds_X509Data_s*)y->gg.g.n) ;
    break;
  default:
    for (y = x->X509Data; n > 1 && y->gg.g.n; --n, y = (struct zx_ds_X509Data_s*)y->gg.g.n) ;
    if (!y->gg.g.n) return;
  }
  y->gg.g.n = y->gg.g.n->n;
}

#endif



#ifdef ZX_ENA_GETPUT

/* FUNC(zx_ds_KeyInfo_NUM_PGPData) */

int zx_ds_KeyInfo_NUM_PGPData(struct zx_ds_KeyInfo_s* x)
{
  struct zx_ds_PGPData_s* y;
  int n = 0;
  if (!x) return 0;
  for (y = x->PGPData; y; ++n, y = (struct zx_ds_PGPData_s*)y->gg.g.n) ;
  return n;
}

/* FUNC(zx_ds_KeyInfo_GET_PGPData) */

struct zx_ds_PGPData_s* zx_ds_KeyInfo_GET_PGPData(struct zx_ds_KeyInfo_s* x, int n)
{
  struct zx_ds_PGPData_s* y;
  if (!x) return 0;
  for (y = x->PGPData; n>=0 && y; --n, y = (struct zx_ds_PGPData_s*)y->gg.g.n) ;
  return y;
}

/* FUNC(zx_ds_KeyInfo_POP_PGPData) */

struct zx_ds_PGPData_s* zx_ds_KeyInfo_POP_PGPData(struct zx_ds_KeyInfo_s* x)
{
  struct zx_ds_PGPData_s* y;
  if (!x) return 0;
  y = x->PGPData;
  if (y)
    x->PGPData = (struct zx_ds_PGPData_s*)y->gg.g.n;
  return y;
}

/* FUNC(zx_ds_KeyInfo_PUSH_PGPData) */

void zx_ds_KeyInfo_PUSH_PGPData(struct zx_ds_KeyInfo_s* x, struct zx_ds_PGPData_s* z)
{
  if (!x || !z) return;
  z->gg.g.n = &x->PGPData->gg.g;
  x->PGPData = z;
}

/* FUNC(zx_ds_KeyInfo_REV_PGPData) */

void zx_ds_KeyInfo_REV_PGPData(struct zx_ds_KeyInfo_s* x)
{
  struct zx_ds_PGPData_s* nxt;
  struct zx_ds_PGPData_s* y;
  if (!x) return;
  y = x->PGPData;
  if (!y) return;
  x->PGPData = 0;
  while (y) {
    nxt = (struct zx_ds_PGPData_s*)y->gg.g.n;
    y->gg.g.n = &x->PGPData->gg.g;
    x->PGPData = y;
    y = nxt;
  }
}

/* FUNC(zx_ds_KeyInfo_PUT_PGPData) */

void zx_ds_KeyInfo_PUT_PGPData(struct zx_ds_KeyInfo_s* x, int n, struct zx_ds_PGPData_s* z)
{
  struct zx_ds_PGPData_s* y;
  if (!x || !z) return;
  y = x->PGPData;
  if (!y) return;
  switch (n) {
  case 0:
    z->gg.g.n = y->gg.g.n;
    x->PGPData = z;
    return;
  default:
    for (; n > 1 && y->gg.g.n; --n, y = (struct zx_ds_PGPData_s*)y->gg.g.n) ;
    if (!y->gg.g.n) return;
    z->gg.g.n = y->gg.g.n->n;
    y->gg.g.n = &z->gg.g;
  }
}

/* FUNC(zx_ds_KeyInfo_ADD_PGPData) */

void zx_ds_KeyInfo_ADD_PGPData(struct zx_ds_KeyInfo_s* x, int n, struct zx_ds_PGPData_s* z)
{
  struct zx_ds_PGPData_s* y;
  if (!x || !z) return;
  switch (n) {
  case 0:
  add_to_start:
    z->gg.g.n = &x->PGPData->gg.g;
    x->PGPData = z;
    return;
  case -1:
    y = x->PGPData;
    if (!y) goto add_to_start;
    for (; y->gg.g.n; y = (struct zx_ds_PGPData_s*)y->gg.g.n) ;
    break;
  default:
    for (y = x->PGPData; n > 1 && y; --n, y = (struct zx_ds_PGPData_s*)y->gg.g.n) ;
    if (!y) return;
  }
  z->gg.g.n = y->gg.g.n;
  y->gg.g.n = &z->gg.g;
}

/* FUNC(zx_ds_KeyInfo_DEL_PGPData) */

void zx_ds_KeyInfo_DEL_PGPData(struct zx_ds_KeyInfo_s* x, int n)
{
  struct zx_ds_PGPData_s* y;
  if (!x) return;
  switch (n) {
  case 0:
    x->PGPData = (struct zx_ds_PGPData_s*)x->PGPData->gg.g.n;
    return;
  case -1:
    y = (struct zx_ds_PGPData_s*)x->PGPData;
    if (!y) return;
    for (; y->gg.g.n; y = (struct zx_ds_PGPData_s*)y->gg.g.n) ;
    break;
  default:
    for (y = x->PGPData; n > 1 && y->gg.g.n; --n, y = (struct zx_ds_PGPData_s*)y->gg.g.n) ;
    if (!y->gg.g.n) return;
  }
  y->gg.g.n = y->gg.g.n->n;
}

#endif



#ifdef ZX_ENA_GETPUT

/* FUNC(zx_ds_KeyInfo_NUM_SPKIData) */

int zx_ds_KeyInfo_NUM_SPKIData(struct zx_ds_KeyInfo_s* x)
{
  struct zx_ds_SPKIData_s* y;
  int n = 0;
  if (!x) return 0;
  for (y = x->SPKIData; y; ++n, y = (struct zx_ds_SPKIData_s*)y->gg.g.n) ;
  return n;
}

/* FUNC(zx_ds_KeyInfo_GET_SPKIData) */

struct zx_ds_SPKIData_s* zx_ds_KeyInfo_GET_SPKIData(struct zx_ds_KeyInfo_s* x, int n)
{
  struct zx_ds_SPKIData_s* y;
  if (!x) return 0;
  for (y = x->SPKIData; n>=0 && y; --n, y = (struct zx_ds_SPKIData_s*)y->gg.g.n) ;
  return y;
}

/* FUNC(zx_ds_KeyInfo_POP_SPKIData) */

struct zx_ds_SPKIData_s* zx_ds_KeyInfo_POP_SPKIData(struct zx_ds_KeyInfo_s* x)
{
  struct zx_ds_SPKIData_s* y;
  if (!x) return 0;
  y = x->SPKIData;
  if (y)
    x->SPKIData = (struct zx_ds_SPKIData_s*)y->gg.g.n;
  return y;
}

/* FUNC(zx_ds_KeyInfo_PUSH_SPKIData) */

void zx_ds_KeyInfo_PUSH_SPKIData(struct zx_ds_KeyInfo_s* x, struct zx_ds_SPKIData_s* z)
{
  if (!x || !z) return;
  z->gg.g.n = &x->SPKIData->gg.g;
  x->SPKIData = z;
}

/* FUNC(zx_ds_KeyInfo_REV_SPKIData) */

void zx_ds_KeyInfo_REV_SPKIData(struct zx_ds_KeyInfo_s* x)
{
  struct zx_ds_SPKIData_s* nxt;
  struct zx_ds_SPKIData_s* y;
  if (!x) return;
  y = x->SPKIData;
  if (!y) return;
  x->SPKIData = 0;
  while (y) {
    nxt = (struct zx_ds_SPKIData_s*)y->gg.g.n;
    y->gg.g.n = &x->SPKIData->gg.g;
    x->SPKIData = y;
    y = nxt;
  }
}

/* FUNC(zx_ds_KeyInfo_PUT_SPKIData) */

void zx_ds_KeyInfo_PUT_SPKIData(struct zx_ds_KeyInfo_s* x, int n, struct zx_ds_SPKIData_s* z)
{
  struct zx_ds_SPKIData_s* y;
  if (!x || !z) return;
  y = x->SPKIData;
  if (!y) return;
  switch (n) {
  case 0:
    z->gg.g.n = y->gg.g.n;
    x->SPKIData = z;
    return;
  default:
    for (; n > 1 && y->gg.g.n; --n, y = (struct zx_ds_SPKIData_s*)y->gg.g.n) ;
    if (!y->gg.g.n) return;
    z->gg.g.n = y->gg.g.n->n;
    y->gg.g.n = &z->gg.g;
  }
}

/* FUNC(zx_ds_KeyInfo_ADD_SPKIData) */

void zx_ds_KeyInfo_ADD_SPKIData(struct zx_ds_KeyInfo_s* x, int n, struct zx_ds_SPKIData_s* z)
{
  struct zx_ds_SPKIData_s* y;
  if (!x || !z) return;
  switch (n) {
  case 0:
  add_to_start:
    z->gg.g.n = &x->SPKIData->gg.g;
    x->SPKIData = z;
    return;
  case -1:
    y = x->SPKIData;
    if (!y) goto add_to_start;
    for (; y->gg.g.n; y = (struct zx_ds_SPKIData_s*)y->gg.g.n) ;
    break;
  default:
    for (y = x->SPKIData; n > 1 && y; --n, y = (struct zx_ds_SPKIData_s*)y->gg.g.n) ;
    if (!y) return;
  }
  z->gg.g.n = y->gg.g.n;
  y->gg.g.n = &z->gg.g;
}

/* FUNC(zx_ds_KeyInfo_DEL_SPKIData) */

void zx_ds_KeyInfo_DEL_SPKIData(struct zx_ds_KeyInfo_s* x, int n)
{
  struct zx_ds_SPKIData_s* y;
  if (!x) return;
  switch (n) {
  case 0:
    x->SPKIData = (struct zx_ds_SPKIData_s*)x->SPKIData->gg.g.n;
    return;
  case -1:
    y = (struct zx_ds_SPKIData_s*)x->SPKIData;
    if (!y) return;
    for (; y->gg.g.n; y = (struct zx_ds_SPKIData_s*)y->gg.g.n) ;
    break;
  default:
    for (y = x->SPKIData; n > 1 && y->gg.g.n; --n, y = (struct zx_ds_SPKIData_s*)y->gg.g.n) ;
    if (!y->gg.g.n) return;
  }
  y->gg.g.n = y->gg.g.n->n;
}

#endif



#ifdef ZX_ENA_GETPUT

/* FUNC(zx_ds_KeyInfo_NUM_MgmtData) */

int zx_ds_KeyInfo_NUM_MgmtData(struct zx_ds_KeyInfo_s* x)
{
  struct zx_elem_s* y;
  int n = 0;
  if (!x) return 0;
  for (y = x->MgmtData; y; ++n, y = (struct zx_elem_s*)y->g.n) ;
  return n;
}

/* FUNC(zx_ds_KeyInfo_GET_MgmtData) */

struct zx_elem_s* zx_ds_KeyInfo_GET_MgmtData(struct zx_ds_KeyInfo_s* x, int n)
{
  struct zx_elem_s* y;
  if (!x) return 0;
  for (y = x->MgmtData; n>=0 && y; --n, y = (struct zx_elem_s*)y->g.n) ;
  return y;
}

/* FUNC(zx_ds_KeyInfo_POP_MgmtData) */

struct zx_elem_s* zx_ds_KeyInfo_POP_MgmtData(struct zx_ds_KeyInfo_s* x)
{
  struct zx_elem_s* y;
  if (!x) return 0;
  y = x->MgmtData;
  if (y)
    x->MgmtData = (struct zx_elem_s*)y->g.n;
  return y;
}

/* FUNC(zx_ds_KeyInfo_PUSH_MgmtData) */

void zx_ds_KeyInfo_PUSH_MgmtData(struct zx_ds_KeyInfo_s* x, struct zx_elem_s* z)
{
  if (!x || !z) return;
  z->g.n = &x->MgmtData->g;
  x->MgmtData = z;
}

/* FUNC(zx_ds_KeyInfo_REV_MgmtData) */

void zx_ds_KeyInfo_REV_MgmtData(struct zx_ds_KeyInfo_s* x)
{
  struct zx_elem_s* nxt;
  struct zx_elem_s* y;
  if (!x) return;
  y = x->MgmtData;
  if (!y) return;
  x->MgmtData = 0;
  while (y) {
    nxt = (struct zx_elem_s*)y->g.n;
    y->g.n = &x->MgmtData->g;
    x->MgmtData = y;
    y = nxt;
  }
}

/* FUNC(zx_ds_KeyInfo_PUT_MgmtData) */

void zx_ds_KeyInfo_PUT_MgmtData(struct zx_ds_KeyInfo_s* x, int n, struct zx_elem_s* z)
{
  struct zx_elem_s* y;
  if (!x || !z) return;
  y = x->MgmtData;
  if (!y) return;
  switch (n) {
  case 0:
    z->g.n = y->g.n;
    x->MgmtData = z;
    return;
  default:
    for (; n > 1 && y->g.n; --n, y = (struct zx_elem_s*)y->g.n) ;
    if (!y->g.n) return;
    z->g.n = y->g.n->n;
    y->g.n = &z->g;
  }
}

/* FUNC(zx_ds_KeyInfo_ADD_MgmtData) */

void zx_ds_KeyInfo_ADD_MgmtData(struct zx_ds_KeyInfo_s* x, int n, struct zx_elem_s* z)
{
  struct zx_elem_s* y;
  if (!x || !z) return;
  switch (n) {
  case 0:
  add_to_start:
    z->g.n = &x->MgmtData->g;
    x->MgmtData = z;
    return;
  case -1:
    y = x->MgmtData;
    if (!y) goto add_to_start;
    for (; y->g.n; y = (struct zx_elem_s*)y->g.n) ;
    break;
  default:
    for (y = x->MgmtData; n > 1 && y; --n, y = (struct zx_elem_s*)y->g.n) ;
    if (!y) return;
  }
  z->g.n = y->g.n;
  y->g.n = &z->g;
}

/* FUNC(zx_ds_KeyInfo_DEL_MgmtData) */

void zx_ds_KeyInfo_DEL_MgmtData(struct zx_ds_KeyInfo_s* x, int n)
{
  struct zx_elem_s* y;
  if (!x) return;
  switch (n) {
  case 0:
    x->MgmtData = (struct zx_elem_s*)x->MgmtData->g.n;
    return;
  case -1:
    y = (struct zx_elem_s*)x->MgmtData;
    if (!y) return;
    for (; y->g.n; y = (struct zx_elem_s*)y->g.n) ;
    break;
  default:
    for (y = x->MgmtData; n > 1 && y->g.n; --n, y = (struct zx_elem_s*)y->g.n) ;
    if (!y->g.n) return;
  }
  y->g.n = y->g.n->n;
}

#endif



#ifdef ZX_ENA_GETPUT

/* FUNC(zx_ds_KeyInfo_NUM_EncryptedKey) */

int zx_ds_KeyInfo_NUM_EncryptedKey(struct zx_ds_KeyInfo_s* x)
{
  struct zx_xenc_EncryptedKey_s* y;
  int n = 0;
  if (!x) return 0;
  for (y = x->EncryptedKey; y; ++n, y = (struct zx_xenc_EncryptedKey_s*)y->gg.g.n) ;
  return n;
}

/* FUNC(zx_ds_KeyInfo_GET_EncryptedKey) */

struct zx_xenc_EncryptedKey_s* zx_ds_KeyInfo_GET_EncryptedKey(struct zx_ds_KeyInfo_s* x, int n)
{
  struct zx_xenc_EncryptedKey_s* y;
  if (!x) return 0;
  for (y = x->EncryptedKey; n>=0 && y; --n, y = (struct zx_xenc_EncryptedKey_s*)y->gg.g.n) ;
  return y;
}

/* FUNC(zx_ds_KeyInfo_POP_EncryptedKey) */

struct zx_xenc_EncryptedKey_s* zx_ds_KeyInfo_POP_EncryptedKey(struct zx_ds_KeyInfo_s* x)
{
  struct zx_xenc_EncryptedKey_s* y;
  if (!x) return 0;
  y = x->EncryptedKey;
  if (y)
    x->EncryptedKey = (struct zx_xenc_EncryptedKey_s*)y->gg.g.n;
  return y;
}

/* FUNC(zx_ds_KeyInfo_PUSH_EncryptedKey) */

void zx_ds_KeyInfo_PUSH_EncryptedKey(struct zx_ds_KeyInfo_s* x, struct zx_xenc_EncryptedKey_s* z)
{
  if (!x || !z) return;
  z->gg.g.n = &x->EncryptedKey->gg.g;
  x->EncryptedKey = z;
}

/* FUNC(zx_ds_KeyInfo_REV_EncryptedKey) */

void zx_ds_KeyInfo_REV_EncryptedKey(struct zx_ds_KeyInfo_s* x)
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

/* FUNC(zx_ds_KeyInfo_PUT_EncryptedKey) */

void zx_ds_KeyInfo_PUT_EncryptedKey(struct zx_ds_KeyInfo_s* x, int n, struct zx_xenc_EncryptedKey_s* z)
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

/* FUNC(zx_ds_KeyInfo_ADD_EncryptedKey) */

void zx_ds_KeyInfo_ADD_EncryptedKey(struct zx_ds_KeyInfo_s* x, int n, struct zx_xenc_EncryptedKey_s* z)
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

/* FUNC(zx_ds_KeyInfo_DEL_EncryptedKey) */

void zx_ds_KeyInfo_DEL_EncryptedKey(struct zx_ds_KeyInfo_s* x, int n)
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

/* FUNC(zx_ds_KeyInfo_GET_Id) */
struct zx_str* zx_ds_KeyInfo_GET_Id(struct zx_ds_KeyInfo_s* x) { return x->Id; }
/* FUNC(zx_ds_KeyInfo_PUT_Id) */
void zx_ds_KeyInfo_PUT_Id(struct zx_ds_KeyInfo_s* x, struct zx_str* y) { x->Id = y; }







#ifdef ZX_ENA_GETPUT

/* FUNC(zx_ds_KeyValue_NUM_DSAKeyValue) */

int zx_ds_KeyValue_NUM_DSAKeyValue(struct zx_ds_KeyValue_s* x)
{
  struct zx_ds_DSAKeyValue_s* y;
  int n = 0;
  if (!x) return 0;
  for (y = x->DSAKeyValue; y; ++n, y = (struct zx_ds_DSAKeyValue_s*)y->gg.g.n) ;
  return n;
}

/* FUNC(zx_ds_KeyValue_GET_DSAKeyValue) */

struct zx_ds_DSAKeyValue_s* zx_ds_KeyValue_GET_DSAKeyValue(struct zx_ds_KeyValue_s* x, int n)
{
  struct zx_ds_DSAKeyValue_s* y;
  if (!x) return 0;
  for (y = x->DSAKeyValue; n>=0 && y; --n, y = (struct zx_ds_DSAKeyValue_s*)y->gg.g.n) ;
  return y;
}

/* FUNC(zx_ds_KeyValue_POP_DSAKeyValue) */

struct zx_ds_DSAKeyValue_s* zx_ds_KeyValue_POP_DSAKeyValue(struct zx_ds_KeyValue_s* x)
{
  struct zx_ds_DSAKeyValue_s* y;
  if (!x) return 0;
  y = x->DSAKeyValue;
  if (y)
    x->DSAKeyValue = (struct zx_ds_DSAKeyValue_s*)y->gg.g.n;
  return y;
}

/* FUNC(zx_ds_KeyValue_PUSH_DSAKeyValue) */

void zx_ds_KeyValue_PUSH_DSAKeyValue(struct zx_ds_KeyValue_s* x, struct zx_ds_DSAKeyValue_s* z)
{
  if (!x || !z) return;
  z->gg.g.n = &x->DSAKeyValue->gg.g;
  x->DSAKeyValue = z;
}

/* FUNC(zx_ds_KeyValue_REV_DSAKeyValue) */

void zx_ds_KeyValue_REV_DSAKeyValue(struct zx_ds_KeyValue_s* x)
{
  struct zx_ds_DSAKeyValue_s* nxt;
  struct zx_ds_DSAKeyValue_s* y;
  if (!x) return;
  y = x->DSAKeyValue;
  if (!y) return;
  x->DSAKeyValue = 0;
  while (y) {
    nxt = (struct zx_ds_DSAKeyValue_s*)y->gg.g.n;
    y->gg.g.n = &x->DSAKeyValue->gg.g;
    x->DSAKeyValue = y;
    y = nxt;
  }
}

/* FUNC(zx_ds_KeyValue_PUT_DSAKeyValue) */

void zx_ds_KeyValue_PUT_DSAKeyValue(struct zx_ds_KeyValue_s* x, int n, struct zx_ds_DSAKeyValue_s* z)
{
  struct zx_ds_DSAKeyValue_s* y;
  if (!x || !z) return;
  y = x->DSAKeyValue;
  if (!y) return;
  switch (n) {
  case 0:
    z->gg.g.n = y->gg.g.n;
    x->DSAKeyValue = z;
    return;
  default:
    for (; n > 1 && y->gg.g.n; --n, y = (struct zx_ds_DSAKeyValue_s*)y->gg.g.n) ;
    if (!y->gg.g.n) return;
    z->gg.g.n = y->gg.g.n->n;
    y->gg.g.n = &z->gg.g;
  }
}

/* FUNC(zx_ds_KeyValue_ADD_DSAKeyValue) */

void zx_ds_KeyValue_ADD_DSAKeyValue(struct zx_ds_KeyValue_s* x, int n, struct zx_ds_DSAKeyValue_s* z)
{
  struct zx_ds_DSAKeyValue_s* y;
  if (!x || !z) return;
  switch (n) {
  case 0:
  add_to_start:
    z->gg.g.n = &x->DSAKeyValue->gg.g;
    x->DSAKeyValue = z;
    return;
  case -1:
    y = x->DSAKeyValue;
    if (!y) goto add_to_start;
    for (; y->gg.g.n; y = (struct zx_ds_DSAKeyValue_s*)y->gg.g.n) ;
    break;
  default:
    for (y = x->DSAKeyValue; n > 1 && y; --n, y = (struct zx_ds_DSAKeyValue_s*)y->gg.g.n) ;
    if (!y) return;
  }
  z->gg.g.n = y->gg.g.n;
  y->gg.g.n = &z->gg.g;
}

/* FUNC(zx_ds_KeyValue_DEL_DSAKeyValue) */

void zx_ds_KeyValue_DEL_DSAKeyValue(struct zx_ds_KeyValue_s* x, int n)
{
  struct zx_ds_DSAKeyValue_s* y;
  if (!x) return;
  switch (n) {
  case 0:
    x->DSAKeyValue = (struct zx_ds_DSAKeyValue_s*)x->DSAKeyValue->gg.g.n;
    return;
  case -1:
    y = (struct zx_ds_DSAKeyValue_s*)x->DSAKeyValue;
    if (!y) return;
    for (; y->gg.g.n; y = (struct zx_ds_DSAKeyValue_s*)y->gg.g.n) ;
    break;
  default:
    for (y = x->DSAKeyValue; n > 1 && y->gg.g.n; --n, y = (struct zx_ds_DSAKeyValue_s*)y->gg.g.n) ;
    if (!y->gg.g.n) return;
  }
  y->gg.g.n = y->gg.g.n->n;
}

#endif



#ifdef ZX_ENA_GETPUT

/* FUNC(zx_ds_KeyValue_NUM_RSAKeyValue) */

int zx_ds_KeyValue_NUM_RSAKeyValue(struct zx_ds_KeyValue_s* x)
{
  struct zx_ds_RSAKeyValue_s* y;
  int n = 0;
  if (!x) return 0;
  for (y = x->RSAKeyValue; y; ++n, y = (struct zx_ds_RSAKeyValue_s*)y->gg.g.n) ;
  return n;
}

/* FUNC(zx_ds_KeyValue_GET_RSAKeyValue) */

struct zx_ds_RSAKeyValue_s* zx_ds_KeyValue_GET_RSAKeyValue(struct zx_ds_KeyValue_s* x, int n)
{
  struct zx_ds_RSAKeyValue_s* y;
  if (!x) return 0;
  for (y = x->RSAKeyValue; n>=0 && y; --n, y = (struct zx_ds_RSAKeyValue_s*)y->gg.g.n) ;
  return y;
}

/* FUNC(zx_ds_KeyValue_POP_RSAKeyValue) */

struct zx_ds_RSAKeyValue_s* zx_ds_KeyValue_POP_RSAKeyValue(struct zx_ds_KeyValue_s* x)
{
  struct zx_ds_RSAKeyValue_s* y;
  if (!x) return 0;
  y = x->RSAKeyValue;
  if (y)
    x->RSAKeyValue = (struct zx_ds_RSAKeyValue_s*)y->gg.g.n;
  return y;
}

/* FUNC(zx_ds_KeyValue_PUSH_RSAKeyValue) */

void zx_ds_KeyValue_PUSH_RSAKeyValue(struct zx_ds_KeyValue_s* x, struct zx_ds_RSAKeyValue_s* z)
{
  if (!x || !z) return;
  z->gg.g.n = &x->RSAKeyValue->gg.g;
  x->RSAKeyValue = z;
}

/* FUNC(zx_ds_KeyValue_REV_RSAKeyValue) */

void zx_ds_KeyValue_REV_RSAKeyValue(struct zx_ds_KeyValue_s* x)
{
  struct zx_ds_RSAKeyValue_s* nxt;
  struct zx_ds_RSAKeyValue_s* y;
  if (!x) return;
  y = x->RSAKeyValue;
  if (!y) return;
  x->RSAKeyValue = 0;
  while (y) {
    nxt = (struct zx_ds_RSAKeyValue_s*)y->gg.g.n;
    y->gg.g.n = &x->RSAKeyValue->gg.g;
    x->RSAKeyValue = y;
    y = nxt;
  }
}

/* FUNC(zx_ds_KeyValue_PUT_RSAKeyValue) */

void zx_ds_KeyValue_PUT_RSAKeyValue(struct zx_ds_KeyValue_s* x, int n, struct zx_ds_RSAKeyValue_s* z)
{
  struct zx_ds_RSAKeyValue_s* y;
  if (!x || !z) return;
  y = x->RSAKeyValue;
  if (!y) return;
  switch (n) {
  case 0:
    z->gg.g.n = y->gg.g.n;
    x->RSAKeyValue = z;
    return;
  default:
    for (; n > 1 && y->gg.g.n; --n, y = (struct zx_ds_RSAKeyValue_s*)y->gg.g.n) ;
    if (!y->gg.g.n) return;
    z->gg.g.n = y->gg.g.n->n;
    y->gg.g.n = &z->gg.g;
  }
}

/* FUNC(zx_ds_KeyValue_ADD_RSAKeyValue) */

void zx_ds_KeyValue_ADD_RSAKeyValue(struct zx_ds_KeyValue_s* x, int n, struct zx_ds_RSAKeyValue_s* z)
{
  struct zx_ds_RSAKeyValue_s* y;
  if (!x || !z) return;
  switch (n) {
  case 0:
  add_to_start:
    z->gg.g.n = &x->RSAKeyValue->gg.g;
    x->RSAKeyValue = z;
    return;
  case -1:
    y = x->RSAKeyValue;
    if (!y) goto add_to_start;
    for (; y->gg.g.n; y = (struct zx_ds_RSAKeyValue_s*)y->gg.g.n) ;
    break;
  default:
    for (y = x->RSAKeyValue; n > 1 && y; --n, y = (struct zx_ds_RSAKeyValue_s*)y->gg.g.n) ;
    if (!y) return;
  }
  z->gg.g.n = y->gg.g.n;
  y->gg.g.n = &z->gg.g;
}

/* FUNC(zx_ds_KeyValue_DEL_RSAKeyValue) */

void zx_ds_KeyValue_DEL_RSAKeyValue(struct zx_ds_KeyValue_s* x, int n)
{
  struct zx_ds_RSAKeyValue_s* y;
  if (!x) return;
  switch (n) {
  case 0:
    x->RSAKeyValue = (struct zx_ds_RSAKeyValue_s*)x->RSAKeyValue->gg.g.n;
    return;
  case -1:
    y = (struct zx_ds_RSAKeyValue_s*)x->RSAKeyValue;
    if (!y) return;
    for (; y->gg.g.n; y = (struct zx_ds_RSAKeyValue_s*)y->gg.g.n) ;
    break;
  default:
    for (y = x->RSAKeyValue; n > 1 && y->gg.g.n; --n, y = (struct zx_ds_RSAKeyValue_s*)y->gg.g.n) ;
    if (!y->gg.g.n) return;
  }
  y->gg.g.n = y->gg.g.n->n;
}

#endif








#ifdef ZX_ENA_GETPUT

/* FUNC(zx_ds_Manifest_NUM_Reference) */

int zx_ds_Manifest_NUM_Reference(struct zx_ds_Manifest_s* x)
{
  struct zx_ds_Reference_s* y;
  int n = 0;
  if (!x) return 0;
  for (y = x->Reference; y; ++n, y = (struct zx_ds_Reference_s*)y->gg.g.n) ;
  return n;
}

/* FUNC(zx_ds_Manifest_GET_Reference) */

struct zx_ds_Reference_s* zx_ds_Manifest_GET_Reference(struct zx_ds_Manifest_s* x, int n)
{
  struct zx_ds_Reference_s* y;
  if (!x) return 0;
  for (y = x->Reference; n>=0 && y; --n, y = (struct zx_ds_Reference_s*)y->gg.g.n) ;
  return y;
}

/* FUNC(zx_ds_Manifest_POP_Reference) */

struct zx_ds_Reference_s* zx_ds_Manifest_POP_Reference(struct zx_ds_Manifest_s* x)
{
  struct zx_ds_Reference_s* y;
  if (!x) return 0;
  y = x->Reference;
  if (y)
    x->Reference = (struct zx_ds_Reference_s*)y->gg.g.n;
  return y;
}

/* FUNC(zx_ds_Manifest_PUSH_Reference) */

void zx_ds_Manifest_PUSH_Reference(struct zx_ds_Manifest_s* x, struct zx_ds_Reference_s* z)
{
  if (!x || !z) return;
  z->gg.g.n = &x->Reference->gg.g;
  x->Reference = z;
}

/* FUNC(zx_ds_Manifest_REV_Reference) */

void zx_ds_Manifest_REV_Reference(struct zx_ds_Manifest_s* x)
{
  struct zx_ds_Reference_s* nxt;
  struct zx_ds_Reference_s* y;
  if (!x) return;
  y = x->Reference;
  if (!y) return;
  x->Reference = 0;
  while (y) {
    nxt = (struct zx_ds_Reference_s*)y->gg.g.n;
    y->gg.g.n = &x->Reference->gg.g;
    x->Reference = y;
    y = nxt;
  }
}

/* FUNC(zx_ds_Manifest_PUT_Reference) */

void zx_ds_Manifest_PUT_Reference(struct zx_ds_Manifest_s* x, int n, struct zx_ds_Reference_s* z)
{
  struct zx_ds_Reference_s* y;
  if (!x || !z) return;
  y = x->Reference;
  if (!y) return;
  switch (n) {
  case 0:
    z->gg.g.n = y->gg.g.n;
    x->Reference = z;
    return;
  default:
    for (; n > 1 && y->gg.g.n; --n, y = (struct zx_ds_Reference_s*)y->gg.g.n) ;
    if (!y->gg.g.n) return;
    z->gg.g.n = y->gg.g.n->n;
    y->gg.g.n = &z->gg.g;
  }
}

/* FUNC(zx_ds_Manifest_ADD_Reference) */

void zx_ds_Manifest_ADD_Reference(struct zx_ds_Manifest_s* x, int n, struct zx_ds_Reference_s* z)
{
  struct zx_ds_Reference_s* y;
  if (!x || !z) return;
  switch (n) {
  case 0:
  add_to_start:
    z->gg.g.n = &x->Reference->gg.g;
    x->Reference = z;
    return;
  case -1:
    y = x->Reference;
    if (!y) goto add_to_start;
    for (; y->gg.g.n; y = (struct zx_ds_Reference_s*)y->gg.g.n) ;
    break;
  default:
    for (y = x->Reference; n > 1 && y; --n, y = (struct zx_ds_Reference_s*)y->gg.g.n) ;
    if (!y) return;
  }
  z->gg.g.n = y->gg.g.n;
  y->gg.g.n = &z->gg.g;
}

/* FUNC(zx_ds_Manifest_DEL_Reference) */

void zx_ds_Manifest_DEL_Reference(struct zx_ds_Manifest_s* x, int n)
{
  struct zx_ds_Reference_s* y;
  if (!x) return;
  switch (n) {
  case 0:
    x->Reference = (struct zx_ds_Reference_s*)x->Reference->gg.g.n;
    return;
  case -1:
    y = (struct zx_ds_Reference_s*)x->Reference;
    if (!y) return;
    for (; y->gg.g.n; y = (struct zx_ds_Reference_s*)y->gg.g.n) ;
    break;
  default:
    for (y = x->Reference; n > 1 && y->gg.g.n; --n, y = (struct zx_ds_Reference_s*)y->gg.g.n) ;
    if (!y->gg.g.n) return;
  }
  y->gg.g.n = y->gg.g.n->n;
}

#endif

/* FUNC(zx_ds_Manifest_GET_Id) */
struct zx_str* zx_ds_Manifest_GET_Id(struct zx_ds_Manifest_s* x) { return x->Id; }
/* FUNC(zx_ds_Manifest_PUT_Id) */
void zx_ds_Manifest_PUT_Id(struct zx_ds_Manifest_s* x, struct zx_str* y) { x->Id = y; }





/* FUNC(zx_ds_Object_GET_Encoding) */
struct zx_str* zx_ds_Object_GET_Encoding(struct zx_ds_Object_s* x) { return x->Encoding; }
/* FUNC(zx_ds_Object_PUT_Encoding) */
void zx_ds_Object_PUT_Encoding(struct zx_ds_Object_s* x, struct zx_str* y) { x->Encoding = y; }
/* FUNC(zx_ds_Object_GET_Id) */
struct zx_str* zx_ds_Object_GET_Id(struct zx_ds_Object_s* x) { return x->Id; }
/* FUNC(zx_ds_Object_PUT_Id) */
void zx_ds_Object_PUT_Id(struct zx_ds_Object_s* x, struct zx_str* y) { x->Id = y; }
/* FUNC(zx_ds_Object_GET_MimeType) */
struct zx_str* zx_ds_Object_GET_MimeType(struct zx_ds_Object_s* x) { return x->MimeType; }
/* FUNC(zx_ds_Object_PUT_MimeType) */
void zx_ds_Object_PUT_MimeType(struct zx_ds_Object_s* x, struct zx_str* y) { x->MimeType = y; }







#ifdef ZX_ENA_GETPUT

/* FUNC(zx_ds_PGPData_NUM_PGPKeyID) */

int zx_ds_PGPData_NUM_PGPKeyID(struct zx_ds_PGPData_s* x)
{
  struct zx_elem_s* y;
  int n = 0;
  if (!x) return 0;
  for (y = x->PGPKeyID; y; ++n, y = (struct zx_elem_s*)y->g.n) ;
  return n;
}

/* FUNC(zx_ds_PGPData_GET_PGPKeyID) */

struct zx_elem_s* zx_ds_PGPData_GET_PGPKeyID(struct zx_ds_PGPData_s* x, int n)
{
  struct zx_elem_s* y;
  if (!x) return 0;
  for (y = x->PGPKeyID; n>=0 && y; --n, y = (struct zx_elem_s*)y->g.n) ;
  return y;
}

/* FUNC(zx_ds_PGPData_POP_PGPKeyID) */

struct zx_elem_s* zx_ds_PGPData_POP_PGPKeyID(struct zx_ds_PGPData_s* x)
{
  struct zx_elem_s* y;
  if (!x) return 0;
  y = x->PGPKeyID;
  if (y)
    x->PGPKeyID = (struct zx_elem_s*)y->g.n;
  return y;
}

/* FUNC(zx_ds_PGPData_PUSH_PGPKeyID) */

void zx_ds_PGPData_PUSH_PGPKeyID(struct zx_ds_PGPData_s* x, struct zx_elem_s* z)
{
  if (!x || !z) return;
  z->g.n = &x->PGPKeyID->g;
  x->PGPKeyID = z;
}

/* FUNC(zx_ds_PGPData_REV_PGPKeyID) */

void zx_ds_PGPData_REV_PGPKeyID(struct zx_ds_PGPData_s* x)
{
  struct zx_elem_s* nxt;
  struct zx_elem_s* y;
  if (!x) return;
  y = x->PGPKeyID;
  if (!y) return;
  x->PGPKeyID = 0;
  while (y) {
    nxt = (struct zx_elem_s*)y->g.n;
    y->g.n = &x->PGPKeyID->g;
    x->PGPKeyID = y;
    y = nxt;
  }
}

/* FUNC(zx_ds_PGPData_PUT_PGPKeyID) */

void zx_ds_PGPData_PUT_PGPKeyID(struct zx_ds_PGPData_s* x, int n, struct zx_elem_s* z)
{
  struct zx_elem_s* y;
  if (!x || !z) return;
  y = x->PGPKeyID;
  if (!y) return;
  switch (n) {
  case 0:
    z->g.n = y->g.n;
    x->PGPKeyID = z;
    return;
  default:
    for (; n > 1 && y->g.n; --n, y = (struct zx_elem_s*)y->g.n) ;
    if (!y->g.n) return;
    z->g.n = y->g.n->n;
    y->g.n = &z->g;
  }
}

/* FUNC(zx_ds_PGPData_ADD_PGPKeyID) */

void zx_ds_PGPData_ADD_PGPKeyID(struct zx_ds_PGPData_s* x, int n, struct zx_elem_s* z)
{
  struct zx_elem_s* y;
  if (!x || !z) return;
  switch (n) {
  case 0:
  add_to_start:
    z->g.n = &x->PGPKeyID->g;
    x->PGPKeyID = z;
    return;
  case -1:
    y = x->PGPKeyID;
    if (!y) goto add_to_start;
    for (; y->g.n; y = (struct zx_elem_s*)y->g.n) ;
    break;
  default:
    for (y = x->PGPKeyID; n > 1 && y; --n, y = (struct zx_elem_s*)y->g.n) ;
    if (!y) return;
  }
  z->g.n = y->g.n;
  y->g.n = &z->g;
}

/* FUNC(zx_ds_PGPData_DEL_PGPKeyID) */

void zx_ds_PGPData_DEL_PGPKeyID(struct zx_ds_PGPData_s* x, int n)
{
  struct zx_elem_s* y;
  if (!x) return;
  switch (n) {
  case 0:
    x->PGPKeyID = (struct zx_elem_s*)x->PGPKeyID->g.n;
    return;
  case -1:
    y = (struct zx_elem_s*)x->PGPKeyID;
    if (!y) return;
    for (; y->g.n; y = (struct zx_elem_s*)y->g.n) ;
    break;
  default:
    for (y = x->PGPKeyID; n > 1 && y->g.n; --n, y = (struct zx_elem_s*)y->g.n) ;
    if (!y->g.n) return;
  }
  y->g.n = y->g.n->n;
}

#endif



#ifdef ZX_ENA_GETPUT

/* FUNC(zx_ds_PGPData_NUM_PGPKeyPacket) */

int zx_ds_PGPData_NUM_PGPKeyPacket(struct zx_ds_PGPData_s* x)
{
  struct zx_elem_s* y;
  int n = 0;
  if (!x) return 0;
  for (y = x->PGPKeyPacket; y; ++n, y = (struct zx_elem_s*)y->g.n) ;
  return n;
}

/* FUNC(zx_ds_PGPData_GET_PGPKeyPacket) */

struct zx_elem_s* zx_ds_PGPData_GET_PGPKeyPacket(struct zx_ds_PGPData_s* x, int n)
{
  struct zx_elem_s* y;
  if (!x) return 0;
  for (y = x->PGPKeyPacket; n>=0 && y; --n, y = (struct zx_elem_s*)y->g.n) ;
  return y;
}

/* FUNC(zx_ds_PGPData_POP_PGPKeyPacket) */

struct zx_elem_s* zx_ds_PGPData_POP_PGPKeyPacket(struct zx_ds_PGPData_s* x)
{
  struct zx_elem_s* y;
  if (!x) return 0;
  y = x->PGPKeyPacket;
  if (y)
    x->PGPKeyPacket = (struct zx_elem_s*)y->g.n;
  return y;
}

/* FUNC(zx_ds_PGPData_PUSH_PGPKeyPacket) */

void zx_ds_PGPData_PUSH_PGPKeyPacket(struct zx_ds_PGPData_s* x, struct zx_elem_s* z)
{
  if (!x || !z) return;
  z->g.n = &x->PGPKeyPacket->g;
  x->PGPKeyPacket = z;
}

/* FUNC(zx_ds_PGPData_REV_PGPKeyPacket) */

void zx_ds_PGPData_REV_PGPKeyPacket(struct zx_ds_PGPData_s* x)
{
  struct zx_elem_s* nxt;
  struct zx_elem_s* y;
  if (!x) return;
  y = x->PGPKeyPacket;
  if (!y) return;
  x->PGPKeyPacket = 0;
  while (y) {
    nxt = (struct zx_elem_s*)y->g.n;
    y->g.n = &x->PGPKeyPacket->g;
    x->PGPKeyPacket = y;
    y = nxt;
  }
}

/* FUNC(zx_ds_PGPData_PUT_PGPKeyPacket) */

void zx_ds_PGPData_PUT_PGPKeyPacket(struct zx_ds_PGPData_s* x, int n, struct zx_elem_s* z)
{
  struct zx_elem_s* y;
  if (!x || !z) return;
  y = x->PGPKeyPacket;
  if (!y) return;
  switch (n) {
  case 0:
    z->g.n = y->g.n;
    x->PGPKeyPacket = z;
    return;
  default:
    for (; n > 1 && y->g.n; --n, y = (struct zx_elem_s*)y->g.n) ;
    if (!y->g.n) return;
    z->g.n = y->g.n->n;
    y->g.n = &z->g;
  }
}

/* FUNC(zx_ds_PGPData_ADD_PGPKeyPacket) */

void zx_ds_PGPData_ADD_PGPKeyPacket(struct zx_ds_PGPData_s* x, int n, struct zx_elem_s* z)
{
  struct zx_elem_s* y;
  if (!x || !z) return;
  switch (n) {
  case 0:
  add_to_start:
    z->g.n = &x->PGPKeyPacket->g;
    x->PGPKeyPacket = z;
    return;
  case -1:
    y = x->PGPKeyPacket;
    if (!y) goto add_to_start;
    for (; y->g.n; y = (struct zx_elem_s*)y->g.n) ;
    break;
  default:
    for (y = x->PGPKeyPacket; n > 1 && y; --n, y = (struct zx_elem_s*)y->g.n) ;
    if (!y) return;
  }
  z->g.n = y->g.n;
  y->g.n = &z->g;
}

/* FUNC(zx_ds_PGPData_DEL_PGPKeyPacket) */

void zx_ds_PGPData_DEL_PGPKeyPacket(struct zx_ds_PGPData_s* x, int n)
{
  struct zx_elem_s* y;
  if (!x) return;
  switch (n) {
  case 0:
    x->PGPKeyPacket = (struct zx_elem_s*)x->PGPKeyPacket->g.n;
    return;
  case -1:
    y = (struct zx_elem_s*)x->PGPKeyPacket;
    if (!y) return;
    for (; y->g.n; y = (struct zx_elem_s*)y->g.n) ;
    break;
  default:
    for (y = x->PGPKeyPacket; n > 1 && y->g.n; --n, y = (struct zx_elem_s*)y->g.n) ;
    if (!y->g.n) return;
  }
  y->g.n = y->g.n->n;
}

#endif








#ifdef ZX_ENA_GETPUT

/* FUNC(zx_ds_RSAKeyValue_NUM_Modulus) */

int zx_ds_RSAKeyValue_NUM_Modulus(struct zx_ds_RSAKeyValue_s* x)
{
  struct zx_elem_s* y;
  int n = 0;
  if (!x) return 0;
  for (y = x->Modulus; y; ++n, y = (struct zx_elem_s*)y->g.n) ;
  return n;
}

/* FUNC(zx_ds_RSAKeyValue_GET_Modulus) */

struct zx_elem_s* zx_ds_RSAKeyValue_GET_Modulus(struct zx_ds_RSAKeyValue_s* x, int n)
{
  struct zx_elem_s* y;
  if (!x) return 0;
  for (y = x->Modulus; n>=0 && y; --n, y = (struct zx_elem_s*)y->g.n) ;
  return y;
}

/* FUNC(zx_ds_RSAKeyValue_POP_Modulus) */

struct zx_elem_s* zx_ds_RSAKeyValue_POP_Modulus(struct zx_ds_RSAKeyValue_s* x)
{
  struct zx_elem_s* y;
  if (!x) return 0;
  y = x->Modulus;
  if (y)
    x->Modulus = (struct zx_elem_s*)y->g.n;
  return y;
}

/* FUNC(zx_ds_RSAKeyValue_PUSH_Modulus) */

void zx_ds_RSAKeyValue_PUSH_Modulus(struct zx_ds_RSAKeyValue_s* x, struct zx_elem_s* z)
{
  if (!x || !z) return;
  z->g.n = &x->Modulus->g;
  x->Modulus = z;
}

/* FUNC(zx_ds_RSAKeyValue_REV_Modulus) */

void zx_ds_RSAKeyValue_REV_Modulus(struct zx_ds_RSAKeyValue_s* x)
{
  struct zx_elem_s* nxt;
  struct zx_elem_s* y;
  if (!x) return;
  y = x->Modulus;
  if (!y) return;
  x->Modulus = 0;
  while (y) {
    nxt = (struct zx_elem_s*)y->g.n;
    y->g.n = &x->Modulus->g;
    x->Modulus = y;
    y = nxt;
  }
}

/* FUNC(zx_ds_RSAKeyValue_PUT_Modulus) */

void zx_ds_RSAKeyValue_PUT_Modulus(struct zx_ds_RSAKeyValue_s* x, int n, struct zx_elem_s* z)
{
  struct zx_elem_s* y;
  if (!x || !z) return;
  y = x->Modulus;
  if (!y) return;
  switch (n) {
  case 0:
    z->g.n = y->g.n;
    x->Modulus = z;
    return;
  default:
    for (; n > 1 && y->g.n; --n, y = (struct zx_elem_s*)y->g.n) ;
    if (!y->g.n) return;
    z->g.n = y->g.n->n;
    y->g.n = &z->g;
  }
}

/* FUNC(zx_ds_RSAKeyValue_ADD_Modulus) */

void zx_ds_RSAKeyValue_ADD_Modulus(struct zx_ds_RSAKeyValue_s* x, int n, struct zx_elem_s* z)
{
  struct zx_elem_s* y;
  if (!x || !z) return;
  switch (n) {
  case 0:
  add_to_start:
    z->g.n = &x->Modulus->g;
    x->Modulus = z;
    return;
  case -1:
    y = x->Modulus;
    if (!y) goto add_to_start;
    for (; y->g.n; y = (struct zx_elem_s*)y->g.n) ;
    break;
  default:
    for (y = x->Modulus; n > 1 && y; --n, y = (struct zx_elem_s*)y->g.n) ;
    if (!y) return;
  }
  z->g.n = y->g.n;
  y->g.n = &z->g;
}

/* FUNC(zx_ds_RSAKeyValue_DEL_Modulus) */

void zx_ds_RSAKeyValue_DEL_Modulus(struct zx_ds_RSAKeyValue_s* x, int n)
{
  struct zx_elem_s* y;
  if (!x) return;
  switch (n) {
  case 0:
    x->Modulus = (struct zx_elem_s*)x->Modulus->g.n;
    return;
  case -1:
    y = (struct zx_elem_s*)x->Modulus;
    if (!y) return;
    for (; y->g.n; y = (struct zx_elem_s*)y->g.n) ;
    break;
  default:
    for (y = x->Modulus; n > 1 && y->g.n; --n, y = (struct zx_elem_s*)y->g.n) ;
    if (!y->g.n) return;
  }
  y->g.n = y->g.n->n;
}

#endif



#ifdef ZX_ENA_GETPUT

/* FUNC(zx_ds_RSAKeyValue_NUM_Exponent) */

int zx_ds_RSAKeyValue_NUM_Exponent(struct zx_ds_RSAKeyValue_s* x)
{
  struct zx_elem_s* y;
  int n = 0;
  if (!x) return 0;
  for (y = x->Exponent; y; ++n, y = (struct zx_elem_s*)y->g.n) ;
  return n;
}

/* FUNC(zx_ds_RSAKeyValue_GET_Exponent) */

struct zx_elem_s* zx_ds_RSAKeyValue_GET_Exponent(struct zx_ds_RSAKeyValue_s* x, int n)
{
  struct zx_elem_s* y;
  if (!x) return 0;
  for (y = x->Exponent; n>=0 && y; --n, y = (struct zx_elem_s*)y->g.n) ;
  return y;
}

/* FUNC(zx_ds_RSAKeyValue_POP_Exponent) */

struct zx_elem_s* zx_ds_RSAKeyValue_POP_Exponent(struct zx_ds_RSAKeyValue_s* x)
{
  struct zx_elem_s* y;
  if (!x) return 0;
  y = x->Exponent;
  if (y)
    x->Exponent = (struct zx_elem_s*)y->g.n;
  return y;
}

/* FUNC(zx_ds_RSAKeyValue_PUSH_Exponent) */

void zx_ds_RSAKeyValue_PUSH_Exponent(struct zx_ds_RSAKeyValue_s* x, struct zx_elem_s* z)
{
  if (!x || !z) return;
  z->g.n = &x->Exponent->g;
  x->Exponent = z;
}

/* FUNC(zx_ds_RSAKeyValue_REV_Exponent) */

void zx_ds_RSAKeyValue_REV_Exponent(struct zx_ds_RSAKeyValue_s* x)
{
  struct zx_elem_s* nxt;
  struct zx_elem_s* y;
  if (!x) return;
  y = x->Exponent;
  if (!y) return;
  x->Exponent = 0;
  while (y) {
    nxt = (struct zx_elem_s*)y->g.n;
    y->g.n = &x->Exponent->g;
    x->Exponent = y;
    y = nxt;
  }
}

/* FUNC(zx_ds_RSAKeyValue_PUT_Exponent) */

void zx_ds_RSAKeyValue_PUT_Exponent(struct zx_ds_RSAKeyValue_s* x, int n, struct zx_elem_s* z)
{
  struct zx_elem_s* y;
  if (!x || !z) return;
  y = x->Exponent;
  if (!y) return;
  switch (n) {
  case 0:
    z->g.n = y->g.n;
    x->Exponent = z;
    return;
  default:
    for (; n > 1 && y->g.n; --n, y = (struct zx_elem_s*)y->g.n) ;
    if (!y->g.n) return;
    z->g.n = y->g.n->n;
    y->g.n = &z->g;
  }
}

/* FUNC(zx_ds_RSAKeyValue_ADD_Exponent) */

void zx_ds_RSAKeyValue_ADD_Exponent(struct zx_ds_RSAKeyValue_s* x, int n, struct zx_elem_s* z)
{
  struct zx_elem_s* y;
  if (!x || !z) return;
  switch (n) {
  case 0:
  add_to_start:
    z->g.n = &x->Exponent->g;
    x->Exponent = z;
    return;
  case -1:
    y = x->Exponent;
    if (!y) goto add_to_start;
    for (; y->g.n; y = (struct zx_elem_s*)y->g.n) ;
    break;
  default:
    for (y = x->Exponent; n > 1 && y; --n, y = (struct zx_elem_s*)y->g.n) ;
    if (!y) return;
  }
  z->g.n = y->g.n;
  y->g.n = &z->g;
}

/* FUNC(zx_ds_RSAKeyValue_DEL_Exponent) */

void zx_ds_RSAKeyValue_DEL_Exponent(struct zx_ds_RSAKeyValue_s* x, int n)
{
  struct zx_elem_s* y;
  if (!x) return;
  switch (n) {
  case 0:
    x->Exponent = (struct zx_elem_s*)x->Exponent->g.n;
    return;
  case -1:
    y = (struct zx_elem_s*)x->Exponent;
    if (!y) return;
    for (; y->g.n; y = (struct zx_elem_s*)y->g.n) ;
    break;
  default:
    for (y = x->Exponent; n > 1 && y->g.n; --n, y = (struct zx_elem_s*)y->g.n) ;
    if (!y->g.n) return;
  }
  y->g.n = y->g.n->n;
}

#endif








#ifdef ZX_ENA_GETPUT

/* FUNC(zx_ds_Reference_NUM_Transforms) */

int zx_ds_Reference_NUM_Transforms(struct zx_ds_Reference_s* x)
{
  struct zx_ds_Transforms_s* y;
  int n = 0;
  if (!x) return 0;
  for (y = x->Transforms; y; ++n, y = (struct zx_ds_Transforms_s*)y->gg.g.n) ;
  return n;
}

/* FUNC(zx_ds_Reference_GET_Transforms) */

struct zx_ds_Transforms_s* zx_ds_Reference_GET_Transforms(struct zx_ds_Reference_s* x, int n)
{
  struct zx_ds_Transforms_s* y;
  if (!x) return 0;
  for (y = x->Transforms; n>=0 && y; --n, y = (struct zx_ds_Transforms_s*)y->gg.g.n) ;
  return y;
}

/* FUNC(zx_ds_Reference_POP_Transforms) */

struct zx_ds_Transforms_s* zx_ds_Reference_POP_Transforms(struct zx_ds_Reference_s* x)
{
  struct zx_ds_Transforms_s* y;
  if (!x) return 0;
  y = x->Transforms;
  if (y)
    x->Transforms = (struct zx_ds_Transforms_s*)y->gg.g.n;
  return y;
}

/* FUNC(zx_ds_Reference_PUSH_Transforms) */

void zx_ds_Reference_PUSH_Transforms(struct zx_ds_Reference_s* x, struct zx_ds_Transforms_s* z)
{
  if (!x || !z) return;
  z->gg.g.n = &x->Transforms->gg.g;
  x->Transforms = z;
}

/* FUNC(zx_ds_Reference_REV_Transforms) */

void zx_ds_Reference_REV_Transforms(struct zx_ds_Reference_s* x)
{
  struct zx_ds_Transforms_s* nxt;
  struct zx_ds_Transforms_s* y;
  if (!x) return;
  y = x->Transforms;
  if (!y) return;
  x->Transforms = 0;
  while (y) {
    nxt = (struct zx_ds_Transforms_s*)y->gg.g.n;
    y->gg.g.n = &x->Transforms->gg.g;
    x->Transforms = y;
    y = nxt;
  }
}

/* FUNC(zx_ds_Reference_PUT_Transforms) */

void zx_ds_Reference_PUT_Transforms(struct zx_ds_Reference_s* x, int n, struct zx_ds_Transforms_s* z)
{
  struct zx_ds_Transforms_s* y;
  if (!x || !z) return;
  y = x->Transforms;
  if (!y) return;
  switch (n) {
  case 0:
    z->gg.g.n = y->gg.g.n;
    x->Transforms = z;
    return;
  default:
    for (; n > 1 && y->gg.g.n; --n, y = (struct zx_ds_Transforms_s*)y->gg.g.n) ;
    if (!y->gg.g.n) return;
    z->gg.g.n = y->gg.g.n->n;
    y->gg.g.n = &z->gg.g;
  }
}

/* FUNC(zx_ds_Reference_ADD_Transforms) */

void zx_ds_Reference_ADD_Transforms(struct zx_ds_Reference_s* x, int n, struct zx_ds_Transforms_s* z)
{
  struct zx_ds_Transforms_s* y;
  if (!x || !z) return;
  switch (n) {
  case 0:
  add_to_start:
    z->gg.g.n = &x->Transforms->gg.g;
    x->Transforms = z;
    return;
  case -1:
    y = x->Transforms;
    if (!y) goto add_to_start;
    for (; y->gg.g.n; y = (struct zx_ds_Transforms_s*)y->gg.g.n) ;
    break;
  default:
    for (y = x->Transforms; n > 1 && y; --n, y = (struct zx_ds_Transforms_s*)y->gg.g.n) ;
    if (!y) return;
  }
  z->gg.g.n = y->gg.g.n;
  y->gg.g.n = &z->gg.g;
}

/* FUNC(zx_ds_Reference_DEL_Transforms) */

void zx_ds_Reference_DEL_Transforms(struct zx_ds_Reference_s* x, int n)
{
  struct zx_ds_Transforms_s* y;
  if (!x) return;
  switch (n) {
  case 0:
    x->Transforms = (struct zx_ds_Transforms_s*)x->Transforms->gg.g.n;
    return;
  case -1:
    y = (struct zx_ds_Transforms_s*)x->Transforms;
    if (!y) return;
    for (; y->gg.g.n; y = (struct zx_ds_Transforms_s*)y->gg.g.n) ;
    break;
  default:
    for (y = x->Transforms; n > 1 && y->gg.g.n; --n, y = (struct zx_ds_Transforms_s*)y->gg.g.n) ;
    if (!y->gg.g.n) return;
  }
  y->gg.g.n = y->gg.g.n->n;
}

#endif



#ifdef ZX_ENA_GETPUT

/* FUNC(zx_ds_Reference_NUM_DigestMethod) */

int zx_ds_Reference_NUM_DigestMethod(struct zx_ds_Reference_s* x)
{
  struct zx_ds_DigestMethod_s* y;
  int n = 0;
  if (!x) return 0;
  for (y = x->DigestMethod; y; ++n, y = (struct zx_ds_DigestMethod_s*)y->gg.g.n) ;
  return n;
}

/* FUNC(zx_ds_Reference_GET_DigestMethod) */

struct zx_ds_DigestMethod_s* zx_ds_Reference_GET_DigestMethod(struct zx_ds_Reference_s* x, int n)
{
  struct zx_ds_DigestMethod_s* y;
  if (!x) return 0;
  for (y = x->DigestMethod; n>=0 && y; --n, y = (struct zx_ds_DigestMethod_s*)y->gg.g.n) ;
  return y;
}

/* FUNC(zx_ds_Reference_POP_DigestMethod) */

struct zx_ds_DigestMethod_s* zx_ds_Reference_POP_DigestMethod(struct zx_ds_Reference_s* x)
{
  struct zx_ds_DigestMethod_s* y;
  if (!x) return 0;
  y = x->DigestMethod;
  if (y)
    x->DigestMethod = (struct zx_ds_DigestMethod_s*)y->gg.g.n;
  return y;
}

/* FUNC(zx_ds_Reference_PUSH_DigestMethod) */

void zx_ds_Reference_PUSH_DigestMethod(struct zx_ds_Reference_s* x, struct zx_ds_DigestMethod_s* z)
{
  if (!x || !z) return;
  z->gg.g.n = &x->DigestMethod->gg.g;
  x->DigestMethod = z;
}

/* FUNC(zx_ds_Reference_REV_DigestMethod) */

void zx_ds_Reference_REV_DigestMethod(struct zx_ds_Reference_s* x)
{
  struct zx_ds_DigestMethod_s* nxt;
  struct zx_ds_DigestMethod_s* y;
  if (!x) return;
  y = x->DigestMethod;
  if (!y) return;
  x->DigestMethod = 0;
  while (y) {
    nxt = (struct zx_ds_DigestMethod_s*)y->gg.g.n;
    y->gg.g.n = &x->DigestMethod->gg.g;
    x->DigestMethod = y;
    y = nxt;
  }
}

/* FUNC(zx_ds_Reference_PUT_DigestMethod) */

void zx_ds_Reference_PUT_DigestMethod(struct zx_ds_Reference_s* x, int n, struct zx_ds_DigestMethod_s* z)
{
  struct zx_ds_DigestMethod_s* y;
  if (!x || !z) return;
  y = x->DigestMethod;
  if (!y) return;
  switch (n) {
  case 0:
    z->gg.g.n = y->gg.g.n;
    x->DigestMethod = z;
    return;
  default:
    for (; n > 1 && y->gg.g.n; --n, y = (struct zx_ds_DigestMethod_s*)y->gg.g.n) ;
    if (!y->gg.g.n) return;
    z->gg.g.n = y->gg.g.n->n;
    y->gg.g.n = &z->gg.g;
  }
}

/* FUNC(zx_ds_Reference_ADD_DigestMethod) */

void zx_ds_Reference_ADD_DigestMethod(struct zx_ds_Reference_s* x, int n, struct zx_ds_DigestMethod_s* z)
{
  struct zx_ds_DigestMethod_s* y;
  if (!x || !z) return;
  switch (n) {
  case 0:
  add_to_start:
    z->gg.g.n = &x->DigestMethod->gg.g;
    x->DigestMethod = z;
    return;
  case -1:
    y = x->DigestMethod;
    if (!y) goto add_to_start;
    for (; y->gg.g.n; y = (struct zx_ds_DigestMethod_s*)y->gg.g.n) ;
    break;
  default:
    for (y = x->DigestMethod; n > 1 && y; --n, y = (struct zx_ds_DigestMethod_s*)y->gg.g.n) ;
    if (!y) return;
  }
  z->gg.g.n = y->gg.g.n;
  y->gg.g.n = &z->gg.g;
}

/* FUNC(zx_ds_Reference_DEL_DigestMethod) */

void zx_ds_Reference_DEL_DigestMethod(struct zx_ds_Reference_s* x, int n)
{
  struct zx_ds_DigestMethod_s* y;
  if (!x) return;
  switch (n) {
  case 0:
    x->DigestMethod = (struct zx_ds_DigestMethod_s*)x->DigestMethod->gg.g.n;
    return;
  case -1:
    y = (struct zx_ds_DigestMethod_s*)x->DigestMethod;
    if (!y) return;
    for (; y->gg.g.n; y = (struct zx_ds_DigestMethod_s*)y->gg.g.n) ;
    break;
  default:
    for (y = x->DigestMethod; n > 1 && y->gg.g.n; --n, y = (struct zx_ds_DigestMethod_s*)y->gg.g.n) ;
    if (!y->gg.g.n) return;
  }
  y->gg.g.n = y->gg.g.n->n;
}

#endif



#ifdef ZX_ENA_GETPUT

/* FUNC(zx_ds_Reference_NUM_DigestValue) */

int zx_ds_Reference_NUM_DigestValue(struct zx_ds_Reference_s* x)
{
  struct zx_elem_s* y;
  int n = 0;
  if (!x) return 0;
  for (y = x->DigestValue; y; ++n, y = (struct zx_elem_s*)y->g.n) ;
  return n;
}

/* FUNC(zx_ds_Reference_GET_DigestValue) */

struct zx_elem_s* zx_ds_Reference_GET_DigestValue(struct zx_ds_Reference_s* x, int n)
{
  struct zx_elem_s* y;
  if (!x) return 0;
  for (y = x->DigestValue; n>=0 && y; --n, y = (struct zx_elem_s*)y->g.n) ;
  return y;
}

/* FUNC(zx_ds_Reference_POP_DigestValue) */

struct zx_elem_s* zx_ds_Reference_POP_DigestValue(struct zx_ds_Reference_s* x)
{
  struct zx_elem_s* y;
  if (!x) return 0;
  y = x->DigestValue;
  if (y)
    x->DigestValue = (struct zx_elem_s*)y->g.n;
  return y;
}

/* FUNC(zx_ds_Reference_PUSH_DigestValue) */

void zx_ds_Reference_PUSH_DigestValue(struct zx_ds_Reference_s* x, struct zx_elem_s* z)
{
  if (!x || !z) return;
  z->g.n = &x->DigestValue->g;
  x->DigestValue = z;
}

/* FUNC(zx_ds_Reference_REV_DigestValue) */

void zx_ds_Reference_REV_DigestValue(struct zx_ds_Reference_s* x)
{
  struct zx_elem_s* nxt;
  struct zx_elem_s* y;
  if (!x) return;
  y = x->DigestValue;
  if (!y) return;
  x->DigestValue = 0;
  while (y) {
    nxt = (struct zx_elem_s*)y->g.n;
    y->g.n = &x->DigestValue->g;
    x->DigestValue = y;
    y = nxt;
  }
}

/* FUNC(zx_ds_Reference_PUT_DigestValue) */

void zx_ds_Reference_PUT_DigestValue(struct zx_ds_Reference_s* x, int n, struct zx_elem_s* z)
{
  struct zx_elem_s* y;
  if (!x || !z) return;
  y = x->DigestValue;
  if (!y) return;
  switch (n) {
  case 0:
    z->g.n = y->g.n;
    x->DigestValue = z;
    return;
  default:
    for (; n > 1 && y->g.n; --n, y = (struct zx_elem_s*)y->g.n) ;
    if (!y->g.n) return;
    z->g.n = y->g.n->n;
    y->g.n = &z->g;
  }
}

/* FUNC(zx_ds_Reference_ADD_DigestValue) */

void zx_ds_Reference_ADD_DigestValue(struct zx_ds_Reference_s* x, int n, struct zx_elem_s* z)
{
  struct zx_elem_s* y;
  if (!x || !z) return;
  switch (n) {
  case 0:
  add_to_start:
    z->g.n = &x->DigestValue->g;
    x->DigestValue = z;
    return;
  case -1:
    y = x->DigestValue;
    if (!y) goto add_to_start;
    for (; y->g.n; y = (struct zx_elem_s*)y->g.n) ;
    break;
  default:
    for (y = x->DigestValue; n > 1 && y; --n, y = (struct zx_elem_s*)y->g.n) ;
    if (!y) return;
  }
  z->g.n = y->g.n;
  y->g.n = &z->g;
}

/* FUNC(zx_ds_Reference_DEL_DigestValue) */

void zx_ds_Reference_DEL_DigestValue(struct zx_ds_Reference_s* x, int n)
{
  struct zx_elem_s* y;
  if (!x) return;
  switch (n) {
  case 0:
    x->DigestValue = (struct zx_elem_s*)x->DigestValue->g.n;
    return;
  case -1:
    y = (struct zx_elem_s*)x->DigestValue;
    if (!y) return;
    for (; y->g.n; y = (struct zx_elem_s*)y->g.n) ;
    break;
  default:
    for (y = x->DigestValue; n > 1 && y->g.n; --n, y = (struct zx_elem_s*)y->g.n) ;
    if (!y->g.n) return;
  }
  y->g.n = y->g.n->n;
}

#endif

/* FUNC(zx_ds_Reference_GET_Id) */
struct zx_str* zx_ds_Reference_GET_Id(struct zx_ds_Reference_s* x) { return x->Id; }
/* FUNC(zx_ds_Reference_PUT_Id) */
void zx_ds_Reference_PUT_Id(struct zx_ds_Reference_s* x, struct zx_str* y) { x->Id = y; }
/* FUNC(zx_ds_Reference_GET_Type) */
struct zx_str* zx_ds_Reference_GET_Type(struct zx_ds_Reference_s* x) { return x->Type; }
/* FUNC(zx_ds_Reference_PUT_Type) */
void zx_ds_Reference_PUT_Type(struct zx_ds_Reference_s* x, struct zx_str* y) { x->Type = y; }
/* FUNC(zx_ds_Reference_GET_URI) */
struct zx_str* zx_ds_Reference_GET_URI(struct zx_ds_Reference_s* x) { return x->URI; }
/* FUNC(zx_ds_Reference_PUT_URI) */
void zx_ds_Reference_PUT_URI(struct zx_ds_Reference_s* x, struct zx_str* y) { x->URI = y; }







#ifdef ZX_ENA_GETPUT

/* FUNC(zx_ds_RetrievalMethod_NUM_Transforms) */

int zx_ds_RetrievalMethod_NUM_Transforms(struct zx_ds_RetrievalMethod_s* x)
{
  struct zx_ds_Transforms_s* y;
  int n = 0;
  if (!x) return 0;
  for (y = x->Transforms; y; ++n, y = (struct zx_ds_Transforms_s*)y->gg.g.n) ;
  return n;
}

/* FUNC(zx_ds_RetrievalMethod_GET_Transforms) */

struct zx_ds_Transforms_s* zx_ds_RetrievalMethod_GET_Transforms(struct zx_ds_RetrievalMethod_s* x, int n)
{
  struct zx_ds_Transforms_s* y;
  if (!x) return 0;
  for (y = x->Transforms; n>=0 && y; --n, y = (struct zx_ds_Transforms_s*)y->gg.g.n) ;
  return y;
}

/* FUNC(zx_ds_RetrievalMethod_POP_Transforms) */

struct zx_ds_Transforms_s* zx_ds_RetrievalMethod_POP_Transforms(struct zx_ds_RetrievalMethod_s* x)
{
  struct zx_ds_Transforms_s* y;
  if (!x) return 0;
  y = x->Transforms;
  if (y)
    x->Transforms = (struct zx_ds_Transforms_s*)y->gg.g.n;
  return y;
}

/* FUNC(zx_ds_RetrievalMethod_PUSH_Transforms) */

void zx_ds_RetrievalMethod_PUSH_Transforms(struct zx_ds_RetrievalMethod_s* x, struct zx_ds_Transforms_s* z)
{
  if (!x || !z) return;
  z->gg.g.n = &x->Transforms->gg.g;
  x->Transforms = z;
}

/* FUNC(zx_ds_RetrievalMethod_REV_Transforms) */

void zx_ds_RetrievalMethod_REV_Transforms(struct zx_ds_RetrievalMethod_s* x)
{
  struct zx_ds_Transforms_s* nxt;
  struct zx_ds_Transforms_s* y;
  if (!x) return;
  y = x->Transforms;
  if (!y) return;
  x->Transforms = 0;
  while (y) {
    nxt = (struct zx_ds_Transforms_s*)y->gg.g.n;
    y->gg.g.n = &x->Transforms->gg.g;
    x->Transforms = y;
    y = nxt;
  }
}

/* FUNC(zx_ds_RetrievalMethod_PUT_Transforms) */

void zx_ds_RetrievalMethod_PUT_Transforms(struct zx_ds_RetrievalMethod_s* x, int n, struct zx_ds_Transforms_s* z)
{
  struct zx_ds_Transforms_s* y;
  if (!x || !z) return;
  y = x->Transforms;
  if (!y) return;
  switch (n) {
  case 0:
    z->gg.g.n = y->gg.g.n;
    x->Transforms = z;
    return;
  default:
    for (; n > 1 && y->gg.g.n; --n, y = (struct zx_ds_Transforms_s*)y->gg.g.n) ;
    if (!y->gg.g.n) return;
    z->gg.g.n = y->gg.g.n->n;
    y->gg.g.n = &z->gg.g;
  }
}

/* FUNC(zx_ds_RetrievalMethod_ADD_Transforms) */

void zx_ds_RetrievalMethod_ADD_Transforms(struct zx_ds_RetrievalMethod_s* x, int n, struct zx_ds_Transforms_s* z)
{
  struct zx_ds_Transforms_s* y;
  if (!x || !z) return;
  switch (n) {
  case 0:
  add_to_start:
    z->gg.g.n = &x->Transforms->gg.g;
    x->Transforms = z;
    return;
  case -1:
    y = x->Transforms;
    if (!y) goto add_to_start;
    for (; y->gg.g.n; y = (struct zx_ds_Transforms_s*)y->gg.g.n) ;
    break;
  default:
    for (y = x->Transforms; n > 1 && y; --n, y = (struct zx_ds_Transforms_s*)y->gg.g.n) ;
    if (!y) return;
  }
  z->gg.g.n = y->gg.g.n;
  y->gg.g.n = &z->gg.g;
}

/* FUNC(zx_ds_RetrievalMethod_DEL_Transforms) */

void zx_ds_RetrievalMethod_DEL_Transforms(struct zx_ds_RetrievalMethod_s* x, int n)
{
  struct zx_ds_Transforms_s* y;
  if (!x) return;
  switch (n) {
  case 0:
    x->Transforms = (struct zx_ds_Transforms_s*)x->Transforms->gg.g.n;
    return;
  case -1:
    y = (struct zx_ds_Transforms_s*)x->Transforms;
    if (!y) return;
    for (; y->gg.g.n; y = (struct zx_ds_Transforms_s*)y->gg.g.n) ;
    break;
  default:
    for (y = x->Transforms; n > 1 && y->gg.g.n; --n, y = (struct zx_ds_Transforms_s*)y->gg.g.n) ;
    if (!y->gg.g.n) return;
  }
  y->gg.g.n = y->gg.g.n->n;
}

#endif

/* FUNC(zx_ds_RetrievalMethod_GET_Type) */
struct zx_str* zx_ds_RetrievalMethod_GET_Type(struct zx_ds_RetrievalMethod_s* x) { return x->Type; }
/* FUNC(zx_ds_RetrievalMethod_PUT_Type) */
void zx_ds_RetrievalMethod_PUT_Type(struct zx_ds_RetrievalMethod_s* x, struct zx_str* y) { x->Type = y; }
/* FUNC(zx_ds_RetrievalMethod_GET_URI) */
struct zx_str* zx_ds_RetrievalMethod_GET_URI(struct zx_ds_RetrievalMethod_s* x) { return x->URI; }
/* FUNC(zx_ds_RetrievalMethod_PUT_URI) */
void zx_ds_RetrievalMethod_PUT_URI(struct zx_ds_RetrievalMethod_s* x, struct zx_str* y) { x->URI = y; }







#ifdef ZX_ENA_GETPUT

/* FUNC(zx_ds_SPKIData_NUM_SPKISexp) */

int zx_ds_SPKIData_NUM_SPKISexp(struct zx_ds_SPKIData_s* x)
{
  struct zx_elem_s* y;
  int n = 0;
  if (!x) return 0;
  for (y = x->SPKISexp; y; ++n, y = (struct zx_elem_s*)y->g.n) ;
  return n;
}

/* FUNC(zx_ds_SPKIData_GET_SPKISexp) */

struct zx_elem_s* zx_ds_SPKIData_GET_SPKISexp(struct zx_ds_SPKIData_s* x, int n)
{
  struct zx_elem_s* y;
  if (!x) return 0;
  for (y = x->SPKISexp; n>=0 && y; --n, y = (struct zx_elem_s*)y->g.n) ;
  return y;
}

/* FUNC(zx_ds_SPKIData_POP_SPKISexp) */

struct zx_elem_s* zx_ds_SPKIData_POP_SPKISexp(struct zx_ds_SPKIData_s* x)
{
  struct zx_elem_s* y;
  if (!x) return 0;
  y = x->SPKISexp;
  if (y)
    x->SPKISexp = (struct zx_elem_s*)y->g.n;
  return y;
}

/* FUNC(zx_ds_SPKIData_PUSH_SPKISexp) */

void zx_ds_SPKIData_PUSH_SPKISexp(struct zx_ds_SPKIData_s* x, struct zx_elem_s* z)
{
  if (!x || !z) return;
  z->g.n = &x->SPKISexp->g;
  x->SPKISexp = z;
}

/* FUNC(zx_ds_SPKIData_REV_SPKISexp) */

void zx_ds_SPKIData_REV_SPKISexp(struct zx_ds_SPKIData_s* x)
{
  struct zx_elem_s* nxt;
  struct zx_elem_s* y;
  if (!x) return;
  y = x->SPKISexp;
  if (!y) return;
  x->SPKISexp = 0;
  while (y) {
    nxt = (struct zx_elem_s*)y->g.n;
    y->g.n = &x->SPKISexp->g;
    x->SPKISexp = y;
    y = nxt;
  }
}

/* FUNC(zx_ds_SPKIData_PUT_SPKISexp) */

void zx_ds_SPKIData_PUT_SPKISexp(struct zx_ds_SPKIData_s* x, int n, struct zx_elem_s* z)
{
  struct zx_elem_s* y;
  if (!x || !z) return;
  y = x->SPKISexp;
  if (!y) return;
  switch (n) {
  case 0:
    z->g.n = y->g.n;
    x->SPKISexp = z;
    return;
  default:
    for (; n > 1 && y->g.n; --n, y = (struct zx_elem_s*)y->g.n) ;
    if (!y->g.n) return;
    z->g.n = y->g.n->n;
    y->g.n = &z->g;
  }
}

/* FUNC(zx_ds_SPKIData_ADD_SPKISexp) */

void zx_ds_SPKIData_ADD_SPKISexp(struct zx_ds_SPKIData_s* x, int n, struct zx_elem_s* z)
{
  struct zx_elem_s* y;
  if (!x || !z) return;
  switch (n) {
  case 0:
  add_to_start:
    z->g.n = &x->SPKISexp->g;
    x->SPKISexp = z;
    return;
  case -1:
    y = x->SPKISexp;
    if (!y) goto add_to_start;
    for (; y->g.n; y = (struct zx_elem_s*)y->g.n) ;
    break;
  default:
    for (y = x->SPKISexp; n > 1 && y; --n, y = (struct zx_elem_s*)y->g.n) ;
    if (!y) return;
  }
  z->g.n = y->g.n;
  y->g.n = &z->g;
}

/* FUNC(zx_ds_SPKIData_DEL_SPKISexp) */

void zx_ds_SPKIData_DEL_SPKISexp(struct zx_ds_SPKIData_s* x, int n)
{
  struct zx_elem_s* y;
  if (!x) return;
  switch (n) {
  case 0:
    x->SPKISexp = (struct zx_elem_s*)x->SPKISexp->g.n;
    return;
  case -1:
    y = (struct zx_elem_s*)x->SPKISexp;
    if (!y) return;
    for (; y->g.n; y = (struct zx_elem_s*)y->g.n) ;
    break;
  default:
    for (y = x->SPKISexp; n > 1 && y->g.n; --n, y = (struct zx_elem_s*)y->g.n) ;
    if (!y->g.n) return;
  }
  y->g.n = y->g.n->n;
}

#endif








#ifdef ZX_ENA_GETPUT

/* FUNC(zx_ds_Signature_NUM_SignedInfo) */

int zx_ds_Signature_NUM_SignedInfo(struct zx_ds_Signature_s* x)
{
  struct zx_ds_SignedInfo_s* y;
  int n = 0;
  if (!x) return 0;
  for (y = x->SignedInfo; y; ++n, y = (struct zx_ds_SignedInfo_s*)y->gg.g.n) ;
  return n;
}

/* FUNC(zx_ds_Signature_GET_SignedInfo) */

struct zx_ds_SignedInfo_s* zx_ds_Signature_GET_SignedInfo(struct zx_ds_Signature_s* x, int n)
{
  struct zx_ds_SignedInfo_s* y;
  if (!x) return 0;
  for (y = x->SignedInfo; n>=0 && y; --n, y = (struct zx_ds_SignedInfo_s*)y->gg.g.n) ;
  return y;
}

/* FUNC(zx_ds_Signature_POP_SignedInfo) */

struct zx_ds_SignedInfo_s* zx_ds_Signature_POP_SignedInfo(struct zx_ds_Signature_s* x)
{
  struct zx_ds_SignedInfo_s* y;
  if (!x) return 0;
  y = x->SignedInfo;
  if (y)
    x->SignedInfo = (struct zx_ds_SignedInfo_s*)y->gg.g.n;
  return y;
}

/* FUNC(zx_ds_Signature_PUSH_SignedInfo) */

void zx_ds_Signature_PUSH_SignedInfo(struct zx_ds_Signature_s* x, struct zx_ds_SignedInfo_s* z)
{
  if (!x || !z) return;
  z->gg.g.n = &x->SignedInfo->gg.g;
  x->SignedInfo = z;
}

/* FUNC(zx_ds_Signature_REV_SignedInfo) */

void zx_ds_Signature_REV_SignedInfo(struct zx_ds_Signature_s* x)
{
  struct zx_ds_SignedInfo_s* nxt;
  struct zx_ds_SignedInfo_s* y;
  if (!x) return;
  y = x->SignedInfo;
  if (!y) return;
  x->SignedInfo = 0;
  while (y) {
    nxt = (struct zx_ds_SignedInfo_s*)y->gg.g.n;
    y->gg.g.n = &x->SignedInfo->gg.g;
    x->SignedInfo = y;
    y = nxt;
  }
}

/* FUNC(zx_ds_Signature_PUT_SignedInfo) */

void zx_ds_Signature_PUT_SignedInfo(struct zx_ds_Signature_s* x, int n, struct zx_ds_SignedInfo_s* z)
{
  struct zx_ds_SignedInfo_s* y;
  if (!x || !z) return;
  y = x->SignedInfo;
  if (!y) return;
  switch (n) {
  case 0:
    z->gg.g.n = y->gg.g.n;
    x->SignedInfo = z;
    return;
  default:
    for (; n > 1 && y->gg.g.n; --n, y = (struct zx_ds_SignedInfo_s*)y->gg.g.n) ;
    if (!y->gg.g.n) return;
    z->gg.g.n = y->gg.g.n->n;
    y->gg.g.n = &z->gg.g;
  }
}

/* FUNC(zx_ds_Signature_ADD_SignedInfo) */

void zx_ds_Signature_ADD_SignedInfo(struct zx_ds_Signature_s* x, int n, struct zx_ds_SignedInfo_s* z)
{
  struct zx_ds_SignedInfo_s* y;
  if (!x || !z) return;
  switch (n) {
  case 0:
  add_to_start:
    z->gg.g.n = &x->SignedInfo->gg.g;
    x->SignedInfo = z;
    return;
  case -1:
    y = x->SignedInfo;
    if (!y) goto add_to_start;
    for (; y->gg.g.n; y = (struct zx_ds_SignedInfo_s*)y->gg.g.n) ;
    break;
  default:
    for (y = x->SignedInfo; n > 1 && y; --n, y = (struct zx_ds_SignedInfo_s*)y->gg.g.n) ;
    if (!y) return;
  }
  z->gg.g.n = y->gg.g.n;
  y->gg.g.n = &z->gg.g;
}

/* FUNC(zx_ds_Signature_DEL_SignedInfo) */

void zx_ds_Signature_DEL_SignedInfo(struct zx_ds_Signature_s* x, int n)
{
  struct zx_ds_SignedInfo_s* y;
  if (!x) return;
  switch (n) {
  case 0:
    x->SignedInfo = (struct zx_ds_SignedInfo_s*)x->SignedInfo->gg.g.n;
    return;
  case -1:
    y = (struct zx_ds_SignedInfo_s*)x->SignedInfo;
    if (!y) return;
    for (; y->gg.g.n; y = (struct zx_ds_SignedInfo_s*)y->gg.g.n) ;
    break;
  default:
    for (y = x->SignedInfo; n > 1 && y->gg.g.n; --n, y = (struct zx_ds_SignedInfo_s*)y->gg.g.n) ;
    if (!y->gg.g.n) return;
  }
  y->gg.g.n = y->gg.g.n->n;
}

#endif



#ifdef ZX_ENA_GETPUT

/* FUNC(zx_ds_Signature_NUM_SignatureValue) */

int zx_ds_Signature_NUM_SignatureValue(struct zx_ds_Signature_s* x)
{
  struct zx_ds_SignatureValue_s* y;
  int n = 0;
  if (!x) return 0;
  for (y = x->SignatureValue; y; ++n, y = (struct zx_ds_SignatureValue_s*)y->gg.g.n) ;
  return n;
}

/* FUNC(zx_ds_Signature_GET_SignatureValue) */

struct zx_ds_SignatureValue_s* zx_ds_Signature_GET_SignatureValue(struct zx_ds_Signature_s* x, int n)
{
  struct zx_ds_SignatureValue_s* y;
  if (!x) return 0;
  for (y = x->SignatureValue; n>=0 && y; --n, y = (struct zx_ds_SignatureValue_s*)y->gg.g.n) ;
  return y;
}

/* FUNC(zx_ds_Signature_POP_SignatureValue) */

struct zx_ds_SignatureValue_s* zx_ds_Signature_POP_SignatureValue(struct zx_ds_Signature_s* x)
{
  struct zx_ds_SignatureValue_s* y;
  if (!x) return 0;
  y = x->SignatureValue;
  if (y)
    x->SignatureValue = (struct zx_ds_SignatureValue_s*)y->gg.g.n;
  return y;
}

/* FUNC(zx_ds_Signature_PUSH_SignatureValue) */

void zx_ds_Signature_PUSH_SignatureValue(struct zx_ds_Signature_s* x, struct zx_ds_SignatureValue_s* z)
{
  if (!x || !z) return;
  z->gg.g.n = &x->SignatureValue->gg.g;
  x->SignatureValue = z;
}

/* FUNC(zx_ds_Signature_REV_SignatureValue) */

void zx_ds_Signature_REV_SignatureValue(struct zx_ds_Signature_s* x)
{
  struct zx_ds_SignatureValue_s* nxt;
  struct zx_ds_SignatureValue_s* y;
  if (!x) return;
  y = x->SignatureValue;
  if (!y) return;
  x->SignatureValue = 0;
  while (y) {
    nxt = (struct zx_ds_SignatureValue_s*)y->gg.g.n;
    y->gg.g.n = &x->SignatureValue->gg.g;
    x->SignatureValue = y;
    y = nxt;
  }
}

/* FUNC(zx_ds_Signature_PUT_SignatureValue) */

void zx_ds_Signature_PUT_SignatureValue(struct zx_ds_Signature_s* x, int n, struct zx_ds_SignatureValue_s* z)
{
  struct zx_ds_SignatureValue_s* y;
  if (!x || !z) return;
  y = x->SignatureValue;
  if (!y) return;
  switch (n) {
  case 0:
    z->gg.g.n = y->gg.g.n;
    x->SignatureValue = z;
    return;
  default:
    for (; n > 1 && y->gg.g.n; --n, y = (struct zx_ds_SignatureValue_s*)y->gg.g.n) ;
    if (!y->gg.g.n) return;
    z->gg.g.n = y->gg.g.n->n;
    y->gg.g.n = &z->gg.g;
  }
}

/* FUNC(zx_ds_Signature_ADD_SignatureValue) */

void zx_ds_Signature_ADD_SignatureValue(struct zx_ds_Signature_s* x, int n, struct zx_ds_SignatureValue_s* z)
{
  struct zx_ds_SignatureValue_s* y;
  if (!x || !z) return;
  switch (n) {
  case 0:
  add_to_start:
    z->gg.g.n = &x->SignatureValue->gg.g;
    x->SignatureValue = z;
    return;
  case -1:
    y = x->SignatureValue;
    if (!y) goto add_to_start;
    for (; y->gg.g.n; y = (struct zx_ds_SignatureValue_s*)y->gg.g.n) ;
    break;
  default:
    for (y = x->SignatureValue; n > 1 && y; --n, y = (struct zx_ds_SignatureValue_s*)y->gg.g.n) ;
    if (!y) return;
  }
  z->gg.g.n = y->gg.g.n;
  y->gg.g.n = &z->gg.g;
}

/* FUNC(zx_ds_Signature_DEL_SignatureValue) */

void zx_ds_Signature_DEL_SignatureValue(struct zx_ds_Signature_s* x, int n)
{
  struct zx_ds_SignatureValue_s* y;
  if (!x) return;
  switch (n) {
  case 0:
    x->SignatureValue = (struct zx_ds_SignatureValue_s*)x->SignatureValue->gg.g.n;
    return;
  case -1:
    y = (struct zx_ds_SignatureValue_s*)x->SignatureValue;
    if (!y) return;
    for (; y->gg.g.n; y = (struct zx_ds_SignatureValue_s*)y->gg.g.n) ;
    break;
  default:
    for (y = x->SignatureValue; n > 1 && y->gg.g.n; --n, y = (struct zx_ds_SignatureValue_s*)y->gg.g.n) ;
    if (!y->gg.g.n) return;
  }
  y->gg.g.n = y->gg.g.n->n;
}

#endif



#ifdef ZX_ENA_GETPUT

/* FUNC(zx_ds_Signature_NUM_KeyInfo) */

int zx_ds_Signature_NUM_KeyInfo(struct zx_ds_Signature_s* x)
{
  struct zx_ds_KeyInfo_s* y;
  int n = 0;
  if (!x) return 0;
  for (y = x->KeyInfo; y; ++n, y = (struct zx_ds_KeyInfo_s*)y->gg.g.n) ;
  return n;
}

/* FUNC(zx_ds_Signature_GET_KeyInfo) */

struct zx_ds_KeyInfo_s* zx_ds_Signature_GET_KeyInfo(struct zx_ds_Signature_s* x, int n)
{
  struct zx_ds_KeyInfo_s* y;
  if (!x) return 0;
  for (y = x->KeyInfo; n>=0 && y; --n, y = (struct zx_ds_KeyInfo_s*)y->gg.g.n) ;
  return y;
}

/* FUNC(zx_ds_Signature_POP_KeyInfo) */

struct zx_ds_KeyInfo_s* zx_ds_Signature_POP_KeyInfo(struct zx_ds_Signature_s* x)
{
  struct zx_ds_KeyInfo_s* y;
  if (!x) return 0;
  y = x->KeyInfo;
  if (y)
    x->KeyInfo = (struct zx_ds_KeyInfo_s*)y->gg.g.n;
  return y;
}

/* FUNC(zx_ds_Signature_PUSH_KeyInfo) */

void zx_ds_Signature_PUSH_KeyInfo(struct zx_ds_Signature_s* x, struct zx_ds_KeyInfo_s* z)
{
  if (!x || !z) return;
  z->gg.g.n = &x->KeyInfo->gg.g;
  x->KeyInfo = z;
}

/* FUNC(zx_ds_Signature_REV_KeyInfo) */

void zx_ds_Signature_REV_KeyInfo(struct zx_ds_Signature_s* x)
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

/* FUNC(zx_ds_Signature_PUT_KeyInfo) */

void zx_ds_Signature_PUT_KeyInfo(struct zx_ds_Signature_s* x, int n, struct zx_ds_KeyInfo_s* z)
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

/* FUNC(zx_ds_Signature_ADD_KeyInfo) */

void zx_ds_Signature_ADD_KeyInfo(struct zx_ds_Signature_s* x, int n, struct zx_ds_KeyInfo_s* z)
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

/* FUNC(zx_ds_Signature_DEL_KeyInfo) */

void zx_ds_Signature_DEL_KeyInfo(struct zx_ds_Signature_s* x, int n)
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



#ifdef ZX_ENA_GETPUT

/* FUNC(zx_ds_Signature_NUM_Object) */

int zx_ds_Signature_NUM_Object(struct zx_ds_Signature_s* x)
{
  struct zx_ds_Object_s* y;
  int n = 0;
  if (!x) return 0;
  for (y = x->Object; y; ++n, y = (struct zx_ds_Object_s*)y->gg.g.n) ;
  return n;
}

/* FUNC(zx_ds_Signature_GET_Object) */

struct zx_ds_Object_s* zx_ds_Signature_GET_Object(struct zx_ds_Signature_s* x, int n)
{
  struct zx_ds_Object_s* y;
  if (!x) return 0;
  for (y = x->Object; n>=0 && y; --n, y = (struct zx_ds_Object_s*)y->gg.g.n) ;
  return y;
}

/* FUNC(zx_ds_Signature_POP_Object) */

struct zx_ds_Object_s* zx_ds_Signature_POP_Object(struct zx_ds_Signature_s* x)
{
  struct zx_ds_Object_s* y;
  if (!x) return 0;
  y = x->Object;
  if (y)
    x->Object = (struct zx_ds_Object_s*)y->gg.g.n;
  return y;
}

/* FUNC(zx_ds_Signature_PUSH_Object) */

void zx_ds_Signature_PUSH_Object(struct zx_ds_Signature_s* x, struct zx_ds_Object_s* z)
{
  if (!x || !z) return;
  z->gg.g.n = &x->Object->gg.g;
  x->Object = z;
}

/* FUNC(zx_ds_Signature_REV_Object) */

void zx_ds_Signature_REV_Object(struct zx_ds_Signature_s* x)
{
  struct zx_ds_Object_s* nxt;
  struct zx_ds_Object_s* y;
  if (!x) return;
  y = x->Object;
  if (!y) return;
  x->Object = 0;
  while (y) {
    nxt = (struct zx_ds_Object_s*)y->gg.g.n;
    y->gg.g.n = &x->Object->gg.g;
    x->Object = y;
    y = nxt;
  }
}

/* FUNC(zx_ds_Signature_PUT_Object) */

void zx_ds_Signature_PUT_Object(struct zx_ds_Signature_s* x, int n, struct zx_ds_Object_s* z)
{
  struct zx_ds_Object_s* y;
  if (!x || !z) return;
  y = x->Object;
  if (!y) return;
  switch (n) {
  case 0:
    z->gg.g.n = y->gg.g.n;
    x->Object = z;
    return;
  default:
    for (; n > 1 && y->gg.g.n; --n, y = (struct zx_ds_Object_s*)y->gg.g.n) ;
    if (!y->gg.g.n) return;
    z->gg.g.n = y->gg.g.n->n;
    y->gg.g.n = &z->gg.g;
  }
}

/* FUNC(zx_ds_Signature_ADD_Object) */

void zx_ds_Signature_ADD_Object(struct zx_ds_Signature_s* x, int n, struct zx_ds_Object_s* z)
{
  struct zx_ds_Object_s* y;
  if (!x || !z) return;
  switch (n) {
  case 0:
  add_to_start:
    z->gg.g.n = &x->Object->gg.g;
    x->Object = z;
    return;
  case -1:
    y = x->Object;
    if (!y) goto add_to_start;
    for (; y->gg.g.n; y = (struct zx_ds_Object_s*)y->gg.g.n) ;
    break;
  default:
    for (y = x->Object; n > 1 && y; --n, y = (struct zx_ds_Object_s*)y->gg.g.n) ;
    if (!y) return;
  }
  z->gg.g.n = y->gg.g.n;
  y->gg.g.n = &z->gg.g;
}

/* FUNC(zx_ds_Signature_DEL_Object) */

void zx_ds_Signature_DEL_Object(struct zx_ds_Signature_s* x, int n)
{
  struct zx_ds_Object_s* y;
  if (!x) return;
  switch (n) {
  case 0:
    x->Object = (struct zx_ds_Object_s*)x->Object->gg.g.n;
    return;
  case -1:
    y = (struct zx_ds_Object_s*)x->Object;
    if (!y) return;
    for (; y->gg.g.n; y = (struct zx_ds_Object_s*)y->gg.g.n) ;
    break;
  default:
    for (y = x->Object; n > 1 && y->gg.g.n; --n, y = (struct zx_ds_Object_s*)y->gg.g.n) ;
    if (!y->gg.g.n) return;
  }
  y->gg.g.n = y->gg.g.n->n;
}

#endif

/* FUNC(zx_ds_Signature_GET_Id) */
struct zx_str* zx_ds_Signature_GET_Id(struct zx_ds_Signature_s* x) { return x->Id; }
/* FUNC(zx_ds_Signature_PUT_Id) */
void zx_ds_Signature_PUT_Id(struct zx_ds_Signature_s* x, struct zx_str* y) { x->Id = y; }







#ifdef ZX_ENA_GETPUT

/* FUNC(zx_ds_SignatureMethod_NUM_HMACOutputLength) */

int zx_ds_SignatureMethod_NUM_HMACOutputLength(struct zx_ds_SignatureMethod_s* x)
{
  struct zx_elem_s* y;
  int n = 0;
  if (!x) return 0;
  for (y = x->HMACOutputLength; y; ++n, y = (struct zx_elem_s*)y->g.n) ;
  return n;
}

/* FUNC(zx_ds_SignatureMethod_GET_HMACOutputLength) */

struct zx_elem_s* zx_ds_SignatureMethod_GET_HMACOutputLength(struct zx_ds_SignatureMethod_s* x, int n)
{
  struct zx_elem_s* y;
  if (!x) return 0;
  for (y = x->HMACOutputLength; n>=0 && y; --n, y = (struct zx_elem_s*)y->g.n) ;
  return y;
}

/* FUNC(zx_ds_SignatureMethod_POP_HMACOutputLength) */

struct zx_elem_s* zx_ds_SignatureMethod_POP_HMACOutputLength(struct zx_ds_SignatureMethod_s* x)
{
  struct zx_elem_s* y;
  if (!x) return 0;
  y = x->HMACOutputLength;
  if (y)
    x->HMACOutputLength = (struct zx_elem_s*)y->g.n;
  return y;
}

/* FUNC(zx_ds_SignatureMethod_PUSH_HMACOutputLength) */

void zx_ds_SignatureMethod_PUSH_HMACOutputLength(struct zx_ds_SignatureMethod_s* x, struct zx_elem_s* z)
{
  if (!x || !z) return;
  z->g.n = &x->HMACOutputLength->g;
  x->HMACOutputLength = z;
}

/* FUNC(zx_ds_SignatureMethod_REV_HMACOutputLength) */

void zx_ds_SignatureMethod_REV_HMACOutputLength(struct zx_ds_SignatureMethod_s* x)
{
  struct zx_elem_s* nxt;
  struct zx_elem_s* y;
  if (!x) return;
  y = x->HMACOutputLength;
  if (!y) return;
  x->HMACOutputLength = 0;
  while (y) {
    nxt = (struct zx_elem_s*)y->g.n;
    y->g.n = &x->HMACOutputLength->g;
    x->HMACOutputLength = y;
    y = nxt;
  }
}

/* FUNC(zx_ds_SignatureMethod_PUT_HMACOutputLength) */

void zx_ds_SignatureMethod_PUT_HMACOutputLength(struct zx_ds_SignatureMethod_s* x, int n, struct zx_elem_s* z)
{
  struct zx_elem_s* y;
  if (!x || !z) return;
  y = x->HMACOutputLength;
  if (!y) return;
  switch (n) {
  case 0:
    z->g.n = y->g.n;
    x->HMACOutputLength = z;
    return;
  default:
    for (; n > 1 && y->g.n; --n, y = (struct zx_elem_s*)y->g.n) ;
    if (!y->g.n) return;
    z->g.n = y->g.n->n;
    y->g.n = &z->g;
  }
}

/* FUNC(zx_ds_SignatureMethod_ADD_HMACOutputLength) */

void zx_ds_SignatureMethod_ADD_HMACOutputLength(struct zx_ds_SignatureMethod_s* x, int n, struct zx_elem_s* z)
{
  struct zx_elem_s* y;
  if (!x || !z) return;
  switch (n) {
  case 0:
  add_to_start:
    z->g.n = &x->HMACOutputLength->g;
    x->HMACOutputLength = z;
    return;
  case -1:
    y = x->HMACOutputLength;
    if (!y) goto add_to_start;
    for (; y->g.n; y = (struct zx_elem_s*)y->g.n) ;
    break;
  default:
    for (y = x->HMACOutputLength; n > 1 && y; --n, y = (struct zx_elem_s*)y->g.n) ;
    if (!y) return;
  }
  z->g.n = y->g.n;
  y->g.n = &z->g;
}

/* FUNC(zx_ds_SignatureMethod_DEL_HMACOutputLength) */

void zx_ds_SignatureMethod_DEL_HMACOutputLength(struct zx_ds_SignatureMethod_s* x, int n)
{
  struct zx_elem_s* y;
  if (!x) return;
  switch (n) {
  case 0:
    x->HMACOutputLength = (struct zx_elem_s*)x->HMACOutputLength->g.n;
    return;
  case -1:
    y = (struct zx_elem_s*)x->HMACOutputLength;
    if (!y) return;
    for (; y->g.n; y = (struct zx_elem_s*)y->g.n) ;
    break;
  default:
    for (y = x->HMACOutputLength; n > 1 && y->g.n; --n, y = (struct zx_elem_s*)y->g.n) ;
    if (!y->g.n) return;
  }
  y->g.n = y->g.n->n;
}

#endif

/* FUNC(zx_ds_SignatureMethod_GET_Algorithm) */
struct zx_str* zx_ds_SignatureMethod_GET_Algorithm(struct zx_ds_SignatureMethod_s* x) { return x->Algorithm; }
/* FUNC(zx_ds_SignatureMethod_PUT_Algorithm) */
void zx_ds_SignatureMethod_PUT_Algorithm(struct zx_ds_SignatureMethod_s* x, struct zx_str* y) { x->Algorithm = y; }







#ifdef ZX_ENA_GETPUT

/* FUNC(zx_ds_SignatureProperties_NUM_SignatureProperty) */

int zx_ds_SignatureProperties_NUM_SignatureProperty(struct zx_ds_SignatureProperties_s* x)
{
  struct zx_ds_SignatureProperty_s* y;
  int n = 0;
  if (!x) return 0;
  for (y = x->SignatureProperty; y; ++n, y = (struct zx_ds_SignatureProperty_s*)y->gg.g.n) ;
  return n;
}

/* FUNC(zx_ds_SignatureProperties_GET_SignatureProperty) */

struct zx_ds_SignatureProperty_s* zx_ds_SignatureProperties_GET_SignatureProperty(struct zx_ds_SignatureProperties_s* x, int n)
{
  struct zx_ds_SignatureProperty_s* y;
  if (!x) return 0;
  for (y = x->SignatureProperty; n>=0 && y; --n, y = (struct zx_ds_SignatureProperty_s*)y->gg.g.n) ;
  return y;
}

/* FUNC(zx_ds_SignatureProperties_POP_SignatureProperty) */

struct zx_ds_SignatureProperty_s* zx_ds_SignatureProperties_POP_SignatureProperty(struct zx_ds_SignatureProperties_s* x)
{
  struct zx_ds_SignatureProperty_s* y;
  if (!x) return 0;
  y = x->SignatureProperty;
  if (y)
    x->SignatureProperty = (struct zx_ds_SignatureProperty_s*)y->gg.g.n;
  return y;
}

/* FUNC(zx_ds_SignatureProperties_PUSH_SignatureProperty) */

void zx_ds_SignatureProperties_PUSH_SignatureProperty(struct zx_ds_SignatureProperties_s* x, struct zx_ds_SignatureProperty_s* z)
{
  if (!x || !z) return;
  z->gg.g.n = &x->SignatureProperty->gg.g;
  x->SignatureProperty = z;
}

/* FUNC(zx_ds_SignatureProperties_REV_SignatureProperty) */

void zx_ds_SignatureProperties_REV_SignatureProperty(struct zx_ds_SignatureProperties_s* x)
{
  struct zx_ds_SignatureProperty_s* nxt;
  struct zx_ds_SignatureProperty_s* y;
  if (!x) return;
  y = x->SignatureProperty;
  if (!y) return;
  x->SignatureProperty = 0;
  while (y) {
    nxt = (struct zx_ds_SignatureProperty_s*)y->gg.g.n;
    y->gg.g.n = &x->SignatureProperty->gg.g;
    x->SignatureProperty = y;
    y = nxt;
  }
}

/* FUNC(zx_ds_SignatureProperties_PUT_SignatureProperty) */

void zx_ds_SignatureProperties_PUT_SignatureProperty(struct zx_ds_SignatureProperties_s* x, int n, struct zx_ds_SignatureProperty_s* z)
{
  struct zx_ds_SignatureProperty_s* y;
  if (!x || !z) return;
  y = x->SignatureProperty;
  if (!y) return;
  switch (n) {
  case 0:
    z->gg.g.n = y->gg.g.n;
    x->SignatureProperty = z;
    return;
  default:
    for (; n > 1 && y->gg.g.n; --n, y = (struct zx_ds_SignatureProperty_s*)y->gg.g.n) ;
    if (!y->gg.g.n) return;
    z->gg.g.n = y->gg.g.n->n;
    y->gg.g.n = &z->gg.g;
  }
}

/* FUNC(zx_ds_SignatureProperties_ADD_SignatureProperty) */

void zx_ds_SignatureProperties_ADD_SignatureProperty(struct zx_ds_SignatureProperties_s* x, int n, struct zx_ds_SignatureProperty_s* z)
{
  struct zx_ds_SignatureProperty_s* y;
  if (!x || !z) return;
  switch (n) {
  case 0:
  add_to_start:
    z->gg.g.n = &x->SignatureProperty->gg.g;
    x->SignatureProperty = z;
    return;
  case -1:
    y = x->SignatureProperty;
    if (!y) goto add_to_start;
    for (; y->gg.g.n; y = (struct zx_ds_SignatureProperty_s*)y->gg.g.n) ;
    break;
  default:
    for (y = x->SignatureProperty; n > 1 && y; --n, y = (struct zx_ds_SignatureProperty_s*)y->gg.g.n) ;
    if (!y) return;
  }
  z->gg.g.n = y->gg.g.n;
  y->gg.g.n = &z->gg.g;
}

/* FUNC(zx_ds_SignatureProperties_DEL_SignatureProperty) */

void zx_ds_SignatureProperties_DEL_SignatureProperty(struct zx_ds_SignatureProperties_s* x, int n)
{
  struct zx_ds_SignatureProperty_s* y;
  if (!x) return;
  switch (n) {
  case 0:
    x->SignatureProperty = (struct zx_ds_SignatureProperty_s*)x->SignatureProperty->gg.g.n;
    return;
  case -1:
    y = (struct zx_ds_SignatureProperty_s*)x->SignatureProperty;
    if (!y) return;
    for (; y->gg.g.n; y = (struct zx_ds_SignatureProperty_s*)y->gg.g.n) ;
    break;
  default:
    for (y = x->SignatureProperty; n > 1 && y->gg.g.n; --n, y = (struct zx_ds_SignatureProperty_s*)y->gg.g.n) ;
    if (!y->gg.g.n) return;
  }
  y->gg.g.n = y->gg.g.n->n;
}

#endif

/* FUNC(zx_ds_SignatureProperties_GET_Id) */
struct zx_str* zx_ds_SignatureProperties_GET_Id(struct zx_ds_SignatureProperties_s* x) { return x->Id; }
/* FUNC(zx_ds_SignatureProperties_PUT_Id) */
void zx_ds_SignatureProperties_PUT_Id(struct zx_ds_SignatureProperties_s* x, struct zx_str* y) { x->Id = y; }





/* FUNC(zx_ds_SignatureProperty_GET_Id) */
struct zx_str* zx_ds_SignatureProperty_GET_Id(struct zx_ds_SignatureProperty_s* x) { return x->Id; }
/* FUNC(zx_ds_SignatureProperty_PUT_Id) */
void zx_ds_SignatureProperty_PUT_Id(struct zx_ds_SignatureProperty_s* x, struct zx_str* y) { x->Id = y; }
/* FUNC(zx_ds_SignatureProperty_GET_Target) */
struct zx_str* zx_ds_SignatureProperty_GET_Target(struct zx_ds_SignatureProperty_s* x) { return x->Target; }
/* FUNC(zx_ds_SignatureProperty_PUT_Target) */
void zx_ds_SignatureProperty_PUT_Target(struct zx_ds_SignatureProperty_s* x, struct zx_str* y) { x->Target = y; }





/* FUNC(zx_ds_SignatureValue_GET_Id) */
struct zx_str* zx_ds_SignatureValue_GET_Id(struct zx_ds_SignatureValue_s* x) { return x->Id; }
/* FUNC(zx_ds_SignatureValue_PUT_Id) */
void zx_ds_SignatureValue_PUT_Id(struct zx_ds_SignatureValue_s* x, struct zx_str* y) { x->Id = y; }







#ifdef ZX_ENA_GETPUT

/* FUNC(zx_ds_SignedInfo_NUM_CanonicalizationMethod) */

int zx_ds_SignedInfo_NUM_CanonicalizationMethod(struct zx_ds_SignedInfo_s* x)
{
  struct zx_ds_CanonicalizationMethod_s* y;
  int n = 0;
  if (!x) return 0;
  for (y = x->CanonicalizationMethod; y; ++n, y = (struct zx_ds_CanonicalizationMethod_s*)y->gg.g.n) ;
  return n;
}

/* FUNC(zx_ds_SignedInfo_GET_CanonicalizationMethod) */

struct zx_ds_CanonicalizationMethod_s* zx_ds_SignedInfo_GET_CanonicalizationMethod(struct zx_ds_SignedInfo_s* x, int n)
{
  struct zx_ds_CanonicalizationMethod_s* y;
  if (!x) return 0;
  for (y = x->CanonicalizationMethod; n>=0 && y; --n, y = (struct zx_ds_CanonicalizationMethod_s*)y->gg.g.n) ;
  return y;
}

/* FUNC(zx_ds_SignedInfo_POP_CanonicalizationMethod) */

struct zx_ds_CanonicalizationMethod_s* zx_ds_SignedInfo_POP_CanonicalizationMethod(struct zx_ds_SignedInfo_s* x)
{
  struct zx_ds_CanonicalizationMethod_s* y;
  if (!x) return 0;
  y = x->CanonicalizationMethod;
  if (y)
    x->CanonicalizationMethod = (struct zx_ds_CanonicalizationMethod_s*)y->gg.g.n;
  return y;
}

/* FUNC(zx_ds_SignedInfo_PUSH_CanonicalizationMethod) */

void zx_ds_SignedInfo_PUSH_CanonicalizationMethod(struct zx_ds_SignedInfo_s* x, struct zx_ds_CanonicalizationMethod_s* z)
{
  if (!x || !z) return;
  z->gg.g.n = &x->CanonicalizationMethod->gg.g;
  x->CanonicalizationMethod = z;
}

/* FUNC(zx_ds_SignedInfo_REV_CanonicalizationMethod) */

void zx_ds_SignedInfo_REV_CanonicalizationMethod(struct zx_ds_SignedInfo_s* x)
{
  struct zx_ds_CanonicalizationMethod_s* nxt;
  struct zx_ds_CanonicalizationMethod_s* y;
  if (!x) return;
  y = x->CanonicalizationMethod;
  if (!y) return;
  x->CanonicalizationMethod = 0;
  while (y) {
    nxt = (struct zx_ds_CanonicalizationMethod_s*)y->gg.g.n;
    y->gg.g.n = &x->CanonicalizationMethod->gg.g;
    x->CanonicalizationMethod = y;
    y = nxt;
  }
}

/* FUNC(zx_ds_SignedInfo_PUT_CanonicalizationMethod) */

void zx_ds_SignedInfo_PUT_CanonicalizationMethod(struct zx_ds_SignedInfo_s* x, int n, struct zx_ds_CanonicalizationMethod_s* z)
{
  struct zx_ds_CanonicalizationMethod_s* y;
  if (!x || !z) return;
  y = x->CanonicalizationMethod;
  if (!y) return;
  switch (n) {
  case 0:
    z->gg.g.n = y->gg.g.n;
    x->CanonicalizationMethod = z;
    return;
  default:
    for (; n > 1 && y->gg.g.n; --n, y = (struct zx_ds_CanonicalizationMethod_s*)y->gg.g.n) ;
    if (!y->gg.g.n) return;
    z->gg.g.n = y->gg.g.n->n;
    y->gg.g.n = &z->gg.g;
  }
}

/* FUNC(zx_ds_SignedInfo_ADD_CanonicalizationMethod) */

void zx_ds_SignedInfo_ADD_CanonicalizationMethod(struct zx_ds_SignedInfo_s* x, int n, struct zx_ds_CanonicalizationMethod_s* z)
{
  struct zx_ds_CanonicalizationMethod_s* y;
  if (!x || !z) return;
  switch (n) {
  case 0:
  add_to_start:
    z->gg.g.n = &x->CanonicalizationMethod->gg.g;
    x->CanonicalizationMethod = z;
    return;
  case -1:
    y = x->CanonicalizationMethod;
    if (!y) goto add_to_start;
    for (; y->gg.g.n; y = (struct zx_ds_CanonicalizationMethod_s*)y->gg.g.n) ;
    break;
  default:
    for (y = x->CanonicalizationMethod; n > 1 && y; --n, y = (struct zx_ds_CanonicalizationMethod_s*)y->gg.g.n) ;
    if (!y) return;
  }
  z->gg.g.n = y->gg.g.n;
  y->gg.g.n = &z->gg.g;
}

/* FUNC(zx_ds_SignedInfo_DEL_CanonicalizationMethod) */

void zx_ds_SignedInfo_DEL_CanonicalizationMethod(struct zx_ds_SignedInfo_s* x, int n)
{
  struct zx_ds_CanonicalizationMethod_s* y;
  if (!x) return;
  switch (n) {
  case 0:
    x->CanonicalizationMethod = (struct zx_ds_CanonicalizationMethod_s*)x->CanonicalizationMethod->gg.g.n;
    return;
  case -1:
    y = (struct zx_ds_CanonicalizationMethod_s*)x->CanonicalizationMethod;
    if (!y) return;
    for (; y->gg.g.n; y = (struct zx_ds_CanonicalizationMethod_s*)y->gg.g.n) ;
    break;
  default:
    for (y = x->CanonicalizationMethod; n > 1 && y->gg.g.n; --n, y = (struct zx_ds_CanonicalizationMethod_s*)y->gg.g.n) ;
    if (!y->gg.g.n) return;
  }
  y->gg.g.n = y->gg.g.n->n;
}

#endif



#ifdef ZX_ENA_GETPUT

/* FUNC(zx_ds_SignedInfo_NUM_SignatureMethod) */

int zx_ds_SignedInfo_NUM_SignatureMethod(struct zx_ds_SignedInfo_s* x)
{
  struct zx_ds_SignatureMethod_s* y;
  int n = 0;
  if (!x) return 0;
  for (y = x->SignatureMethod; y; ++n, y = (struct zx_ds_SignatureMethod_s*)y->gg.g.n) ;
  return n;
}

/* FUNC(zx_ds_SignedInfo_GET_SignatureMethod) */

struct zx_ds_SignatureMethod_s* zx_ds_SignedInfo_GET_SignatureMethod(struct zx_ds_SignedInfo_s* x, int n)
{
  struct zx_ds_SignatureMethod_s* y;
  if (!x) return 0;
  for (y = x->SignatureMethod; n>=0 && y; --n, y = (struct zx_ds_SignatureMethod_s*)y->gg.g.n) ;
  return y;
}

/* FUNC(zx_ds_SignedInfo_POP_SignatureMethod) */

struct zx_ds_SignatureMethod_s* zx_ds_SignedInfo_POP_SignatureMethod(struct zx_ds_SignedInfo_s* x)
{
  struct zx_ds_SignatureMethod_s* y;
  if (!x) return 0;
  y = x->SignatureMethod;
  if (y)
    x->SignatureMethod = (struct zx_ds_SignatureMethod_s*)y->gg.g.n;
  return y;
}

/* FUNC(zx_ds_SignedInfo_PUSH_SignatureMethod) */

void zx_ds_SignedInfo_PUSH_SignatureMethod(struct zx_ds_SignedInfo_s* x, struct zx_ds_SignatureMethod_s* z)
{
  if (!x || !z) return;
  z->gg.g.n = &x->SignatureMethod->gg.g;
  x->SignatureMethod = z;
}

/* FUNC(zx_ds_SignedInfo_REV_SignatureMethod) */

void zx_ds_SignedInfo_REV_SignatureMethod(struct zx_ds_SignedInfo_s* x)
{
  struct zx_ds_SignatureMethod_s* nxt;
  struct zx_ds_SignatureMethod_s* y;
  if (!x) return;
  y = x->SignatureMethod;
  if (!y) return;
  x->SignatureMethod = 0;
  while (y) {
    nxt = (struct zx_ds_SignatureMethod_s*)y->gg.g.n;
    y->gg.g.n = &x->SignatureMethod->gg.g;
    x->SignatureMethod = y;
    y = nxt;
  }
}

/* FUNC(zx_ds_SignedInfo_PUT_SignatureMethod) */

void zx_ds_SignedInfo_PUT_SignatureMethod(struct zx_ds_SignedInfo_s* x, int n, struct zx_ds_SignatureMethod_s* z)
{
  struct zx_ds_SignatureMethod_s* y;
  if (!x || !z) return;
  y = x->SignatureMethod;
  if (!y) return;
  switch (n) {
  case 0:
    z->gg.g.n = y->gg.g.n;
    x->SignatureMethod = z;
    return;
  default:
    for (; n > 1 && y->gg.g.n; --n, y = (struct zx_ds_SignatureMethod_s*)y->gg.g.n) ;
    if (!y->gg.g.n) return;
    z->gg.g.n = y->gg.g.n->n;
    y->gg.g.n = &z->gg.g;
  }
}

/* FUNC(zx_ds_SignedInfo_ADD_SignatureMethod) */

void zx_ds_SignedInfo_ADD_SignatureMethod(struct zx_ds_SignedInfo_s* x, int n, struct zx_ds_SignatureMethod_s* z)
{
  struct zx_ds_SignatureMethod_s* y;
  if (!x || !z) return;
  switch (n) {
  case 0:
  add_to_start:
    z->gg.g.n = &x->SignatureMethod->gg.g;
    x->SignatureMethod = z;
    return;
  case -1:
    y = x->SignatureMethod;
    if (!y) goto add_to_start;
    for (; y->gg.g.n; y = (struct zx_ds_SignatureMethod_s*)y->gg.g.n) ;
    break;
  default:
    for (y = x->SignatureMethod; n > 1 && y; --n, y = (struct zx_ds_SignatureMethod_s*)y->gg.g.n) ;
    if (!y) return;
  }
  z->gg.g.n = y->gg.g.n;
  y->gg.g.n = &z->gg.g;
}

/* FUNC(zx_ds_SignedInfo_DEL_SignatureMethod) */

void zx_ds_SignedInfo_DEL_SignatureMethod(struct zx_ds_SignedInfo_s* x, int n)
{
  struct zx_ds_SignatureMethod_s* y;
  if (!x) return;
  switch (n) {
  case 0:
    x->SignatureMethod = (struct zx_ds_SignatureMethod_s*)x->SignatureMethod->gg.g.n;
    return;
  case -1:
    y = (struct zx_ds_SignatureMethod_s*)x->SignatureMethod;
    if (!y) return;
    for (; y->gg.g.n; y = (struct zx_ds_SignatureMethod_s*)y->gg.g.n) ;
    break;
  default:
    for (y = x->SignatureMethod; n > 1 && y->gg.g.n; --n, y = (struct zx_ds_SignatureMethod_s*)y->gg.g.n) ;
    if (!y->gg.g.n) return;
  }
  y->gg.g.n = y->gg.g.n->n;
}

#endif



#ifdef ZX_ENA_GETPUT

/* FUNC(zx_ds_SignedInfo_NUM_Reference) */

int zx_ds_SignedInfo_NUM_Reference(struct zx_ds_SignedInfo_s* x)
{
  struct zx_ds_Reference_s* y;
  int n = 0;
  if (!x) return 0;
  for (y = x->Reference; y; ++n, y = (struct zx_ds_Reference_s*)y->gg.g.n) ;
  return n;
}

/* FUNC(zx_ds_SignedInfo_GET_Reference) */

struct zx_ds_Reference_s* zx_ds_SignedInfo_GET_Reference(struct zx_ds_SignedInfo_s* x, int n)
{
  struct zx_ds_Reference_s* y;
  if (!x) return 0;
  for (y = x->Reference; n>=0 && y; --n, y = (struct zx_ds_Reference_s*)y->gg.g.n) ;
  return y;
}

/* FUNC(zx_ds_SignedInfo_POP_Reference) */

struct zx_ds_Reference_s* zx_ds_SignedInfo_POP_Reference(struct zx_ds_SignedInfo_s* x)
{
  struct zx_ds_Reference_s* y;
  if (!x) return 0;
  y = x->Reference;
  if (y)
    x->Reference = (struct zx_ds_Reference_s*)y->gg.g.n;
  return y;
}

/* FUNC(zx_ds_SignedInfo_PUSH_Reference) */

void zx_ds_SignedInfo_PUSH_Reference(struct zx_ds_SignedInfo_s* x, struct zx_ds_Reference_s* z)
{
  if (!x || !z) return;
  z->gg.g.n = &x->Reference->gg.g;
  x->Reference = z;
}

/* FUNC(zx_ds_SignedInfo_REV_Reference) */

void zx_ds_SignedInfo_REV_Reference(struct zx_ds_SignedInfo_s* x)
{
  struct zx_ds_Reference_s* nxt;
  struct zx_ds_Reference_s* y;
  if (!x) return;
  y = x->Reference;
  if (!y) return;
  x->Reference = 0;
  while (y) {
    nxt = (struct zx_ds_Reference_s*)y->gg.g.n;
    y->gg.g.n = &x->Reference->gg.g;
    x->Reference = y;
    y = nxt;
  }
}

/* FUNC(zx_ds_SignedInfo_PUT_Reference) */

void zx_ds_SignedInfo_PUT_Reference(struct zx_ds_SignedInfo_s* x, int n, struct zx_ds_Reference_s* z)
{
  struct zx_ds_Reference_s* y;
  if (!x || !z) return;
  y = x->Reference;
  if (!y) return;
  switch (n) {
  case 0:
    z->gg.g.n = y->gg.g.n;
    x->Reference = z;
    return;
  default:
    for (; n > 1 && y->gg.g.n; --n, y = (struct zx_ds_Reference_s*)y->gg.g.n) ;
    if (!y->gg.g.n) return;
    z->gg.g.n = y->gg.g.n->n;
    y->gg.g.n = &z->gg.g;
  }
}

/* FUNC(zx_ds_SignedInfo_ADD_Reference) */

void zx_ds_SignedInfo_ADD_Reference(struct zx_ds_SignedInfo_s* x, int n, struct zx_ds_Reference_s* z)
{
  struct zx_ds_Reference_s* y;
  if (!x || !z) return;
  switch (n) {
  case 0:
  add_to_start:
    z->gg.g.n = &x->Reference->gg.g;
    x->Reference = z;
    return;
  case -1:
    y = x->Reference;
    if (!y) goto add_to_start;
    for (; y->gg.g.n; y = (struct zx_ds_Reference_s*)y->gg.g.n) ;
    break;
  default:
    for (y = x->Reference; n > 1 && y; --n, y = (struct zx_ds_Reference_s*)y->gg.g.n) ;
    if (!y) return;
  }
  z->gg.g.n = y->gg.g.n;
  y->gg.g.n = &z->gg.g;
}

/* FUNC(zx_ds_SignedInfo_DEL_Reference) */

void zx_ds_SignedInfo_DEL_Reference(struct zx_ds_SignedInfo_s* x, int n)
{
  struct zx_ds_Reference_s* y;
  if (!x) return;
  switch (n) {
  case 0:
    x->Reference = (struct zx_ds_Reference_s*)x->Reference->gg.g.n;
    return;
  case -1:
    y = (struct zx_ds_Reference_s*)x->Reference;
    if (!y) return;
    for (; y->gg.g.n; y = (struct zx_ds_Reference_s*)y->gg.g.n) ;
    break;
  default:
    for (y = x->Reference; n > 1 && y->gg.g.n; --n, y = (struct zx_ds_Reference_s*)y->gg.g.n) ;
    if (!y->gg.g.n) return;
  }
  y->gg.g.n = y->gg.g.n->n;
}

#endif

/* FUNC(zx_ds_SignedInfo_GET_Id) */
struct zx_str* zx_ds_SignedInfo_GET_Id(struct zx_ds_SignedInfo_s* x) { return x->Id; }
/* FUNC(zx_ds_SignedInfo_PUT_Id) */
void zx_ds_SignedInfo_PUT_Id(struct zx_ds_SignedInfo_s* x, struct zx_str* y) { x->Id = y; }







#ifdef ZX_ENA_GETPUT

/* FUNC(zx_ds_Transform_NUM_XPath) */

int zx_ds_Transform_NUM_XPath(struct zx_ds_Transform_s* x)
{
  struct zx_elem_s* y;
  int n = 0;
  if (!x) return 0;
  for (y = x->XPath; y; ++n, y = (struct zx_elem_s*)y->g.n) ;
  return n;
}

/* FUNC(zx_ds_Transform_GET_XPath) */

struct zx_elem_s* zx_ds_Transform_GET_XPath(struct zx_ds_Transform_s* x, int n)
{
  struct zx_elem_s* y;
  if (!x) return 0;
  for (y = x->XPath; n>=0 && y; --n, y = (struct zx_elem_s*)y->g.n) ;
  return y;
}

/* FUNC(zx_ds_Transform_POP_XPath) */

struct zx_elem_s* zx_ds_Transform_POP_XPath(struct zx_ds_Transform_s* x)
{
  struct zx_elem_s* y;
  if (!x) return 0;
  y = x->XPath;
  if (y)
    x->XPath = (struct zx_elem_s*)y->g.n;
  return y;
}

/* FUNC(zx_ds_Transform_PUSH_XPath) */

void zx_ds_Transform_PUSH_XPath(struct zx_ds_Transform_s* x, struct zx_elem_s* z)
{
  if (!x || !z) return;
  z->g.n = &x->XPath->g;
  x->XPath = z;
}

/* FUNC(zx_ds_Transform_REV_XPath) */

void zx_ds_Transform_REV_XPath(struct zx_ds_Transform_s* x)
{
  struct zx_elem_s* nxt;
  struct zx_elem_s* y;
  if (!x) return;
  y = x->XPath;
  if (!y) return;
  x->XPath = 0;
  while (y) {
    nxt = (struct zx_elem_s*)y->g.n;
    y->g.n = &x->XPath->g;
    x->XPath = y;
    y = nxt;
  }
}

/* FUNC(zx_ds_Transform_PUT_XPath) */

void zx_ds_Transform_PUT_XPath(struct zx_ds_Transform_s* x, int n, struct zx_elem_s* z)
{
  struct zx_elem_s* y;
  if (!x || !z) return;
  y = x->XPath;
  if (!y) return;
  switch (n) {
  case 0:
    z->g.n = y->g.n;
    x->XPath = z;
    return;
  default:
    for (; n > 1 && y->g.n; --n, y = (struct zx_elem_s*)y->g.n) ;
    if (!y->g.n) return;
    z->g.n = y->g.n->n;
    y->g.n = &z->g;
  }
}

/* FUNC(zx_ds_Transform_ADD_XPath) */

void zx_ds_Transform_ADD_XPath(struct zx_ds_Transform_s* x, int n, struct zx_elem_s* z)
{
  struct zx_elem_s* y;
  if (!x || !z) return;
  switch (n) {
  case 0:
  add_to_start:
    z->g.n = &x->XPath->g;
    x->XPath = z;
    return;
  case -1:
    y = x->XPath;
    if (!y) goto add_to_start;
    for (; y->g.n; y = (struct zx_elem_s*)y->g.n) ;
    break;
  default:
    for (y = x->XPath; n > 1 && y; --n, y = (struct zx_elem_s*)y->g.n) ;
    if (!y) return;
  }
  z->g.n = y->g.n;
  y->g.n = &z->g;
}

/* FUNC(zx_ds_Transform_DEL_XPath) */

void zx_ds_Transform_DEL_XPath(struct zx_ds_Transform_s* x, int n)
{
  struct zx_elem_s* y;
  if (!x) return;
  switch (n) {
  case 0:
    x->XPath = (struct zx_elem_s*)x->XPath->g.n;
    return;
  case -1:
    y = (struct zx_elem_s*)x->XPath;
    if (!y) return;
    for (; y->g.n; y = (struct zx_elem_s*)y->g.n) ;
    break;
  default:
    for (y = x->XPath; n > 1 && y->g.n; --n, y = (struct zx_elem_s*)y->g.n) ;
    if (!y->g.n) return;
  }
  y->g.n = y->g.n->n;
}

#endif



#ifdef ZX_ENA_GETPUT

/* FUNC(zx_ds_Transform_NUM_InclusiveNamespaces) */

int zx_ds_Transform_NUM_InclusiveNamespaces(struct zx_ds_Transform_s* x)
{
  struct zx_exca_InclusiveNamespaces_s* y;
  int n = 0;
  if (!x) return 0;
  for (y = x->InclusiveNamespaces; y; ++n, y = (struct zx_exca_InclusiveNamespaces_s*)y->gg.g.n) ;
  return n;
}

/* FUNC(zx_ds_Transform_GET_InclusiveNamespaces) */

struct zx_exca_InclusiveNamespaces_s* zx_ds_Transform_GET_InclusiveNamespaces(struct zx_ds_Transform_s* x, int n)
{
  struct zx_exca_InclusiveNamespaces_s* y;
  if (!x) return 0;
  for (y = x->InclusiveNamespaces; n>=0 && y; --n, y = (struct zx_exca_InclusiveNamespaces_s*)y->gg.g.n) ;
  return y;
}

/* FUNC(zx_ds_Transform_POP_InclusiveNamespaces) */

struct zx_exca_InclusiveNamespaces_s* zx_ds_Transform_POP_InclusiveNamespaces(struct zx_ds_Transform_s* x)
{
  struct zx_exca_InclusiveNamespaces_s* y;
  if (!x) return 0;
  y = x->InclusiveNamespaces;
  if (y)
    x->InclusiveNamespaces = (struct zx_exca_InclusiveNamespaces_s*)y->gg.g.n;
  return y;
}

/* FUNC(zx_ds_Transform_PUSH_InclusiveNamespaces) */

void zx_ds_Transform_PUSH_InclusiveNamespaces(struct zx_ds_Transform_s* x, struct zx_exca_InclusiveNamespaces_s* z)
{
  if (!x || !z) return;
  z->gg.g.n = &x->InclusiveNamespaces->gg.g;
  x->InclusiveNamespaces = z;
}

/* FUNC(zx_ds_Transform_REV_InclusiveNamespaces) */

void zx_ds_Transform_REV_InclusiveNamespaces(struct zx_ds_Transform_s* x)
{
  struct zx_exca_InclusiveNamespaces_s* nxt;
  struct zx_exca_InclusiveNamespaces_s* y;
  if (!x) return;
  y = x->InclusiveNamespaces;
  if (!y) return;
  x->InclusiveNamespaces = 0;
  while (y) {
    nxt = (struct zx_exca_InclusiveNamespaces_s*)y->gg.g.n;
    y->gg.g.n = &x->InclusiveNamespaces->gg.g;
    x->InclusiveNamespaces = y;
    y = nxt;
  }
}

/* FUNC(zx_ds_Transform_PUT_InclusiveNamespaces) */

void zx_ds_Transform_PUT_InclusiveNamespaces(struct zx_ds_Transform_s* x, int n, struct zx_exca_InclusiveNamespaces_s* z)
{
  struct zx_exca_InclusiveNamespaces_s* y;
  if (!x || !z) return;
  y = x->InclusiveNamespaces;
  if (!y) return;
  switch (n) {
  case 0:
    z->gg.g.n = y->gg.g.n;
    x->InclusiveNamespaces = z;
    return;
  default:
    for (; n > 1 && y->gg.g.n; --n, y = (struct zx_exca_InclusiveNamespaces_s*)y->gg.g.n) ;
    if (!y->gg.g.n) return;
    z->gg.g.n = y->gg.g.n->n;
    y->gg.g.n = &z->gg.g;
  }
}

/* FUNC(zx_ds_Transform_ADD_InclusiveNamespaces) */

void zx_ds_Transform_ADD_InclusiveNamespaces(struct zx_ds_Transform_s* x, int n, struct zx_exca_InclusiveNamespaces_s* z)
{
  struct zx_exca_InclusiveNamespaces_s* y;
  if (!x || !z) return;
  switch (n) {
  case 0:
  add_to_start:
    z->gg.g.n = &x->InclusiveNamespaces->gg.g;
    x->InclusiveNamespaces = z;
    return;
  case -1:
    y = x->InclusiveNamespaces;
    if (!y) goto add_to_start;
    for (; y->gg.g.n; y = (struct zx_exca_InclusiveNamespaces_s*)y->gg.g.n) ;
    break;
  default:
    for (y = x->InclusiveNamespaces; n > 1 && y; --n, y = (struct zx_exca_InclusiveNamespaces_s*)y->gg.g.n) ;
    if (!y) return;
  }
  z->gg.g.n = y->gg.g.n;
  y->gg.g.n = &z->gg.g;
}

/* FUNC(zx_ds_Transform_DEL_InclusiveNamespaces) */

void zx_ds_Transform_DEL_InclusiveNamespaces(struct zx_ds_Transform_s* x, int n)
{
  struct zx_exca_InclusiveNamespaces_s* y;
  if (!x) return;
  switch (n) {
  case 0:
    x->InclusiveNamespaces = (struct zx_exca_InclusiveNamespaces_s*)x->InclusiveNamespaces->gg.g.n;
    return;
  case -1:
    y = (struct zx_exca_InclusiveNamespaces_s*)x->InclusiveNamespaces;
    if (!y) return;
    for (; y->gg.g.n; y = (struct zx_exca_InclusiveNamespaces_s*)y->gg.g.n) ;
    break;
  default:
    for (y = x->InclusiveNamespaces; n > 1 && y->gg.g.n; --n, y = (struct zx_exca_InclusiveNamespaces_s*)y->gg.g.n) ;
    if (!y->gg.g.n) return;
  }
  y->gg.g.n = y->gg.g.n->n;
}

#endif

/* FUNC(zx_ds_Transform_GET_Algorithm) */
struct zx_str* zx_ds_Transform_GET_Algorithm(struct zx_ds_Transform_s* x) { return x->Algorithm; }
/* FUNC(zx_ds_Transform_PUT_Algorithm) */
void zx_ds_Transform_PUT_Algorithm(struct zx_ds_Transform_s* x, struct zx_str* y) { x->Algorithm = y; }







#ifdef ZX_ENA_GETPUT

/* FUNC(zx_ds_Transforms_NUM_Transform) */

int zx_ds_Transforms_NUM_Transform(struct zx_ds_Transforms_s* x)
{
  struct zx_ds_Transform_s* y;
  int n = 0;
  if (!x) return 0;
  for (y = x->Transform; y; ++n, y = (struct zx_ds_Transform_s*)y->gg.g.n) ;
  return n;
}

/* FUNC(zx_ds_Transforms_GET_Transform) */

struct zx_ds_Transform_s* zx_ds_Transforms_GET_Transform(struct zx_ds_Transforms_s* x, int n)
{
  struct zx_ds_Transform_s* y;
  if (!x) return 0;
  for (y = x->Transform; n>=0 && y; --n, y = (struct zx_ds_Transform_s*)y->gg.g.n) ;
  return y;
}

/* FUNC(zx_ds_Transforms_POP_Transform) */

struct zx_ds_Transform_s* zx_ds_Transforms_POP_Transform(struct zx_ds_Transforms_s* x)
{
  struct zx_ds_Transform_s* y;
  if (!x) return 0;
  y = x->Transform;
  if (y)
    x->Transform = (struct zx_ds_Transform_s*)y->gg.g.n;
  return y;
}

/* FUNC(zx_ds_Transforms_PUSH_Transform) */

void zx_ds_Transforms_PUSH_Transform(struct zx_ds_Transforms_s* x, struct zx_ds_Transform_s* z)
{
  if (!x || !z) return;
  z->gg.g.n = &x->Transform->gg.g;
  x->Transform = z;
}

/* FUNC(zx_ds_Transforms_REV_Transform) */

void zx_ds_Transforms_REV_Transform(struct zx_ds_Transforms_s* x)
{
  struct zx_ds_Transform_s* nxt;
  struct zx_ds_Transform_s* y;
  if (!x) return;
  y = x->Transform;
  if (!y) return;
  x->Transform = 0;
  while (y) {
    nxt = (struct zx_ds_Transform_s*)y->gg.g.n;
    y->gg.g.n = &x->Transform->gg.g;
    x->Transform = y;
    y = nxt;
  }
}

/* FUNC(zx_ds_Transforms_PUT_Transform) */

void zx_ds_Transforms_PUT_Transform(struct zx_ds_Transforms_s* x, int n, struct zx_ds_Transform_s* z)
{
  struct zx_ds_Transform_s* y;
  if (!x || !z) return;
  y = x->Transform;
  if (!y) return;
  switch (n) {
  case 0:
    z->gg.g.n = y->gg.g.n;
    x->Transform = z;
    return;
  default:
    for (; n > 1 && y->gg.g.n; --n, y = (struct zx_ds_Transform_s*)y->gg.g.n) ;
    if (!y->gg.g.n) return;
    z->gg.g.n = y->gg.g.n->n;
    y->gg.g.n = &z->gg.g;
  }
}

/* FUNC(zx_ds_Transforms_ADD_Transform) */

void zx_ds_Transforms_ADD_Transform(struct zx_ds_Transforms_s* x, int n, struct zx_ds_Transform_s* z)
{
  struct zx_ds_Transform_s* y;
  if (!x || !z) return;
  switch (n) {
  case 0:
  add_to_start:
    z->gg.g.n = &x->Transform->gg.g;
    x->Transform = z;
    return;
  case -1:
    y = x->Transform;
    if (!y) goto add_to_start;
    for (; y->gg.g.n; y = (struct zx_ds_Transform_s*)y->gg.g.n) ;
    break;
  default:
    for (y = x->Transform; n > 1 && y; --n, y = (struct zx_ds_Transform_s*)y->gg.g.n) ;
    if (!y) return;
  }
  z->gg.g.n = y->gg.g.n;
  y->gg.g.n = &z->gg.g;
}

/* FUNC(zx_ds_Transforms_DEL_Transform) */

void zx_ds_Transforms_DEL_Transform(struct zx_ds_Transforms_s* x, int n)
{
  struct zx_ds_Transform_s* y;
  if (!x) return;
  switch (n) {
  case 0:
    x->Transform = (struct zx_ds_Transform_s*)x->Transform->gg.g.n;
    return;
  case -1:
    y = (struct zx_ds_Transform_s*)x->Transform;
    if (!y) return;
    for (; y->gg.g.n; y = (struct zx_ds_Transform_s*)y->gg.g.n) ;
    break;
  default:
    for (y = x->Transform; n > 1 && y->gg.g.n; --n, y = (struct zx_ds_Transform_s*)y->gg.g.n) ;
    if (!y->gg.g.n) return;
  }
  y->gg.g.n = y->gg.g.n->n;
}

#endif








#ifdef ZX_ENA_GETPUT

/* FUNC(zx_ds_X509Data_NUM_X509IssuerSerial) */

int zx_ds_X509Data_NUM_X509IssuerSerial(struct zx_ds_X509Data_s* x)
{
  struct zx_ds_X509IssuerSerial_s* y;
  int n = 0;
  if (!x) return 0;
  for (y = x->X509IssuerSerial; y; ++n, y = (struct zx_ds_X509IssuerSerial_s*)y->gg.g.n) ;
  return n;
}

/* FUNC(zx_ds_X509Data_GET_X509IssuerSerial) */

struct zx_ds_X509IssuerSerial_s* zx_ds_X509Data_GET_X509IssuerSerial(struct zx_ds_X509Data_s* x, int n)
{
  struct zx_ds_X509IssuerSerial_s* y;
  if (!x) return 0;
  for (y = x->X509IssuerSerial; n>=0 && y; --n, y = (struct zx_ds_X509IssuerSerial_s*)y->gg.g.n) ;
  return y;
}

/* FUNC(zx_ds_X509Data_POP_X509IssuerSerial) */

struct zx_ds_X509IssuerSerial_s* zx_ds_X509Data_POP_X509IssuerSerial(struct zx_ds_X509Data_s* x)
{
  struct zx_ds_X509IssuerSerial_s* y;
  if (!x) return 0;
  y = x->X509IssuerSerial;
  if (y)
    x->X509IssuerSerial = (struct zx_ds_X509IssuerSerial_s*)y->gg.g.n;
  return y;
}

/* FUNC(zx_ds_X509Data_PUSH_X509IssuerSerial) */

void zx_ds_X509Data_PUSH_X509IssuerSerial(struct zx_ds_X509Data_s* x, struct zx_ds_X509IssuerSerial_s* z)
{
  if (!x || !z) return;
  z->gg.g.n = &x->X509IssuerSerial->gg.g;
  x->X509IssuerSerial = z;
}

/* FUNC(zx_ds_X509Data_REV_X509IssuerSerial) */

void zx_ds_X509Data_REV_X509IssuerSerial(struct zx_ds_X509Data_s* x)
{
  struct zx_ds_X509IssuerSerial_s* nxt;
  struct zx_ds_X509IssuerSerial_s* y;
  if (!x) return;
  y = x->X509IssuerSerial;
  if (!y) return;
  x->X509IssuerSerial = 0;
  while (y) {
    nxt = (struct zx_ds_X509IssuerSerial_s*)y->gg.g.n;
    y->gg.g.n = &x->X509IssuerSerial->gg.g;
    x->X509IssuerSerial = y;
    y = nxt;
  }
}

/* FUNC(zx_ds_X509Data_PUT_X509IssuerSerial) */

void zx_ds_X509Data_PUT_X509IssuerSerial(struct zx_ds_X509Data_s* x, int n, struct zx_ds_X509IssuerSerial_s* z)
{
  struct zx_ds_X509IssuerSerial_s* y;
  if (!x || !z) return;
  y = x->X509IssuerSerial;
  if (!y) return;
  switch (n) {
  case 0:
    z->gg.g.n = y->gg.g.n;
    x->X509IssuerSerial = z;
    return;
  default:
    for (; n > 1 && y->gg.g.n; --n, y = (struct zx_ds_X509IssuerSerial_s*)y->gg.g.n) ;
    if (!y->gg.g.n) return;
    z->gg.g.n = y->gg.g.n->n;
    y->gg.g.n = &z->gg.g;
  }
}

/* FUNC(zx_ds_X509Data_ADD_X509IssuerSerial) */

void zx_ds_X509Data_ADD_X509IssuerSerial(struct zx_ds_X509Data_s* x, int n, struct zx_ds_X509IssuerSerial_s* z)
{
  struct zx_ds_X509IssuerSerial_s* y;
  if (!x || !z) return;
  switch (n) {
  case 0:
  add_to_start:
    z->gg.g.n = &x->X509IssuerSerial->gg.g;
    x->X509IssuerSerial = z;
    return;
  case -1:
    y = x->X509IssuerSerial;
    if (!y) goto add_to_start;
    for (; y->gg.g.n; y = (struct zx_ds_X509IssuerSerial_s*)y->gg.g.n) ;
    break;
  default:
    for (y = x->X509IssuerSerial; n > 1 && y; --n, y = (struct zx_ds_X509IssuerSerial_s*)y->gg.g.n) ;
    if (!y) return;
  }
  z->gg.g.n = y->gg.g.n;
  y->gg.g.n = &z->gg.g;
}

/* FUNC(zx_ds_X509Data_DEL_X509IssuerSerial) */

void zx_ds_X509Data_DEL_X509IssuerSerial(struct zx_ds_X509Data_s* x, int n)
{
  struct zx_ds_X509IssuerSerial_s* y;
  if (!x) return;
  switch (n) {
  case 0:
    x->X509IssuerSerial = (struct zx_ds_X509IssuerSerial_s*)x->X509IssuerSerial->gg.g.n;
    return;
  case -1:
    y = (struct zx_ds_X509IssuerSerial_s*)x->X509IssuerSerial;
    if (!y) return;
    for (; y->gg.g.n; y = (struct zx_ds_X509IssuerSerial_s*)y->gg.g.n) ;
    break;
  default:
    for (y = x->X509IssuerSerial; n > 1 && y->gg.g.n; --n, y = (struct zx_ds_X509IssuerSerial_s*)y->gg.g.n) ;
    if (!y->gg.g.n) return;
  }
  y->gg.g.n = y->gg.g.n->n;
}

#endif



#ifdef ZX_ENA_GETPUT

/* FUNC(zx_ds_X509Data_NUM_X509SKI) */

int zx_ds_X509Data_NUM_X509SKI(struct zx_ds_X509Data_s* x)
{
  struct zx_elem_s* y;
  int n = 0;
  if (!x) return 0;
  for (y = x->X509SKI; y; ++n, y = (struct zx_elem_s*)y->g.n) ;
  return n;
}

/* FUNC(zx_ds_X509Data_GET_X509SKI) */

struct zx_elem_s* zx_ds_X509Data_GET_X509SKI(struct zx_ds_X509Data_s* x, int n)
{
  struct zx_elem_s* y;
  if (!x) return 0;
  for (y = x->X509SKI; n>=0 && y; --n, y = (struct zx_elem_s*)y->g.n) ;
  return y;
}

/* FUNC(zx_ds_X509Data_POP_X509SKI) */

struct zx_elem_s* zx_ds_X509Data_POP_X509SKI(struct zx_ds_X509Data_s* x)
{
  struct zx_elem_s* y;
  if (!x) return 0;
  y = x->X509SKI;
  if (y)
    x->X509SKI = (struct zx_elem_s*)y->g.n;
  return y;
}

/* FUNC(zx_ds_X509Data_PUSH_X509SKI) */

void zx_ds_X509Data_PUSH_X509SKI(struct zx_ds_X509Data_s* x, struct zx_elem_s* z)
{
  if (!x || !z) return;
  z->g.n = &x->X509SKI->g;
  x->X509SKI = z;
}

/* FUNC(zx_ds_X509Data_REV_X509SKI) */

void zx_ds_X509Data_REV_X509SKI(struct zx_ds_X509Data_s* x)
{
  struct zx_elem_s* nxt;
  struct zx_elem_s* y;
  if (!x) return;
  y = x->X509SKI;
  if (!y) return;
  x->X509SKI = 0;
  while (y) {
    nxt = (struct zx_elem_s*)y->g.n;
    y->g.n = &x->X509SKI->g;
    x->X509SKI = y;
    y = nxt;
  }
}

/* FUNC(zx_ds_X509Data_PUT_X509SKI) */

void zx_ds_X509Data_PUT_X509SKI(struct zx_ds_X509Data_s* x, int n, struct zx_elem_s* z)
{
  struct zx_elem_s* y;
  if (!x || !z) return;
  y = x->X509SKI;
  if (!y) return;
  switch (n) {
  case 0:
    z->g.n = y->g.n;
    x->X509SKI = z;
    return;
  default:
    for (; n > 1 && y->g.n; --n, y = (struct zx_elem_s*)y->g.n) ;
    if (!y->g.n) return;
    z->g.n = y->g.n->n;
    y->g.n = &z->g;
  }
}

/* FUNC(zx_ds_X509Data_ADD_X509SKI) */

void zx_ds_X509Data_ADD_X509SKI(struct zx_ds_X509Data_s* x, int n, struct zx_elem_s* z)
{
  struct zx_elem_s* y;
  if (!x || !z) return;
  switch (n) {
  case 0:
  add_to_start:
    z->g.n = &x->X509SKI->g;
    x->X509SKI = z;
    return;
  case -1:
    y = x->X509SKI;
    if (!y) goto add_to_start;
    for (; y->g.n; y = (struct zx_elem_s*)y->g.n) ;
    break;
  default:
    for (y = x->X509SKI; n > 1 && y; --n, y = (struct zx_elem_s*)y->g.n) ;
    if (!y) return;
  }
  z->g.n = y->g.n;
  y->g.n = &z->g;
}

/* FUNC(zx_ds_X509Data_DEL_X509SKI) */

void zx_ds_X509Data_DEL_X509SKI(struct zx_ds_X509Data_s* x, int n)
{
  struct zx_elem_s* y;
  if (!x) return;
  switch (n) {
  case 0:
    x->X509SKI = (struct zx_elem_s*)x->X509SKI->g.n;
    return;
  case -1:
    y = (struct zx_elem_s*)x->X509SKI;
    if (!y) return;
    for (; y->g.n; y = (struct zx_elem_s*)y->g.n) ;
    break;
  default:
    for (y = x->X509SKI; n > 1 && y->g.n; --n, y = (struct zx_elem_s*)y->g.n) ;
    if (!y->g.n) return;
  }
  y->g.n = y->g.n->n;
}

#endif



#ifdef ZX_ENA_GETPUT

/* FUNC(zx_ds_X509Data_NUM_X509SubjectName) */

int zx_ds_X509Data_NUM_X509SubjectName(struct zx_ds_X509Data_s* x)
{
  struct zx_elem_s* y;
  int n = 0;
  if (!x) return 0;
  for (y = x->X509SubjectName; y; ++n, y = (struct zx_elem_s*)y->g.n) ;
  return n;
}

/* FUNC(zx_ds_X509Data_GET_X509SubjectName) */

struct zx_elem_s* zx_ds_X509Data_GET_X509SubjectName(struct zx_ds_X509Data_s* x, int n)
{
  struct zx_elem_s* y;
  if (!x) return 0;
  for (y = x->X509SubjectName; n>=0 && y; --n, y = (struct zx_elem_s*)y->g.n) ;
  return y;
}

/* FUNC(zx_ds_X509Data_POP_X509SubjectName) */

struct zx_elem_s* zx_ds_X509Data_POP_X509SubjectName(struct zx_ds_X509Data_s* x)
{
  struct zx_elem_s* y;
  if (!x) return 0;
  y = x->X509SubjectName;
  if (y)
    x->X509SubjectName = (struct zx_elem_s*)y->g.n;
  return y;
}

/* FUNC(zx_ds_X509Data_PUSH_X509SubjectName) */

void zx_ds_X509Data_PUSH_X509SubjectName(struct zx_ds_X509Data_s* x, struct zx_elem_s* z)
{
  if (!x || !z) return;
  z->g.n = &x->X509SubjectName->g;
  x->X509SubjectName = z;
}

/* FUNC(zx_ds_X509Data_REV_X509SubjectName) */

void zx_ds_X509Data_REV_X509SubjectName(struct zx_ds_X509Data_s* x)
{
  struct zx_elem_s* nxt;
  struct zx_elem_s* y;
  if (!x) return;
  y = x->X509SubjectName;
  if (!y) return;
  x->X509SubjectName = 0;
  while (y) {
    nxt = (struct zx_elem_s*)y->g.n;
    y->g.n = &x->X509SubjectName->g;
    x->X509SubjectName = y;
    y = nxt;
  }
}

/* FUNC(zx_ds_X509Data_PUT_X509SubjectName) */

void zx_ds_X509Data_PUT_X509SubjectName(struct zx_ds_X509Data_s* x, int n, struct zx_elem_s* z)
{
  struct zx_elem_s* y;
  if (!x || !z) return;
  y = x->X509SubjectName;
  if (!y) return;
  switch (n) {
  case 0:
    z->g.n = y->g.n;
    x->X509SubjectName = z;
    return;
  default:
    for (; n > 1 && y->g.n; --n, y = (struct zx_elem_s*)y->g.n) ;
    if (!y->g.n) return;
    z->g.n = y->g.n->n;
    y->g.n = &z->g;
  }
}

/* FUNC(zx_ds_X509Data_ADD_X509SubjectName) */

void zx_ds_X509Data_ADD_X509SubjectName(struct zx_ds_X509Data_s* x, int n, struct zx_elem_s* z)
{
  struct zx_elem_s* y;
  if (!x || !z) return;
  switch (n) {
  case 0:
  add_to_start:
    z->g.n = &x->X509SubjectName->g;
    x->X509SubjectName = z;
    return;
  case -1:
    y = x->X509SubjectName;
    if (!y) goto add_to_start;
    for (; y->g.n; y = (struct zx_elem_s*)y->g.n) ;
    break;
  default:
    for (y = x->X509SubjectName; n > 1 && y; --n, y = (struct zx_elem_s*)y->g.n) ;
    if (!y) return;
  }
  z->g.n = y->g.n;
  y->g.n = &z->g;
}

/* FUNC(zx_ds_X509Data_DEL_X509SubjectName) */

void zx_ds_X509Data_DEL_X509SubjectName(struct zx_ds_X509Data_s* x, int n)
{
  struct zx_elem_s* y;
  if (!x) return;
  switch (n) {
  case 0:
    x->X509SubjectName = (struct zx_elem_s*)x->X509SubjectName->g.n;
    return;
  case -1:
    y = (struct zx_elem_s*)x->X509SubjectName;
    if (!y) return;
    for (; y->g.n; y = (struct zx_elem_s*)y->g.n) ;
    break;
  default:
    for (y = x->X509SubjectName; n > 1 && y->g.n; --n, y = (struct zx_elem_s*)y->g.n) ;
    if (!y->g.n) return;
  }
  y->g.n = y->g.n->n;
}

#endif



#ifdef ZX_ENA_GETPUT

/* FUNC(zx_ds_X509Data_NUM_X509Certificate) */

int zx_ds_X509Data_NUM_X509Certificate(struct zx_ds_X509Data_s* x)
{
  struct zx_elem_s* y;
  int n = 0;
  if (!x) return 0;
  for (y = x->X509Certificate; y; ++n, y = (struct zx_elem_s*)y->g.n) ;
  return n;
}

/* FUNC(zx_ds_X509Data_GET_X509Certificate) */

struct zx_elem_s* zx_ds_X509Data_GET_X509Certificate(struct zx_ds_X509Data_s* x, int n)
{
  struct zx_elem_s* y;
  if (!x) return 0;
  for (y = x->X509Certificate; n>=0 && y; --n, y = (struct zx_elem_s*)y->g.n) ;
  return y;
}

/* FUNC(zx_ds_X509Data_POP_X509Certificate) */

struct zx_elem_s* zx_ds_X509Data_POP_X509Certificate(struct zx_ds_X509Data_s* x)
{
  struct zx_elem_s* y;
  if (!x) return 0;
  y = x->X509Certificate;
  if (y)
    x->X509Certificate = (struct zx_elem_s*)y->g.n;
  return y;
}

/* FUNC(zx_ds_X509Data_PUSH_X509Certificate) */

void zx_ds_X509Data_PUSH_X509Certificate(struct zx_ds_X509Data_s* x, struct zx_elem_s* z)
{
  if (!x || !z) return;
  z->g.n = &x->X509Certificate->g;
  x->X509Certificate = z;
}

/* FUNC(zx_ds_X509Data_REV_X509Certificate) */

void zx_ds_X509Data_REV_X509Certificate(struct zx_ds_X509Data_s* x)
{
  struct zx_elem_s* nxt;
  struct zx_elem_s* y;
  if (!x) return;
  y = x->X509Certificate;
  if (!y) return;
  x->X509Certificate = 0;
  while (y) {
    nxt = (struct zx_elem_s*)y->g.n;
    y->g.n = &x->X509Certificate->g;
    x->X509Certificate = y;
    y = nxt;
  }
}

/* FUNC(zx_ds_X509Data_PUT_X509Certificate) */

void zx_ds_X509Data_PUT_X509Certificate(struct zx_ds_X509Data_s* x, int n, struct zx_elem_s* z)
{
  struct zx_elem_s* y;
  if (!x || !z) return;
  y = x->X509Certificate;
  if (!y) return;
  switch (n) {
  case 0:
    z->g.n = y->g.n;
    x->X509Certificate = z;
    return;
  default:
    for (; n > 1 && y->g.n; --n, y = (struct zx_elem_s*)y->g.n) ;
    if (!y->g.n) return;
    z->g.n = y->g.n->n;
    y->g.n = &z->g;
  }
}

/* FUNC(zx_ds_X509Data_ADD_X509Certificate) */

void zx_ds_X509Data_ADD_X509Certificate(struct zx_ds_X509Data_s* x, int n, struct zx_elem_s* z)
{
  struct zx_elem_s* y;
  if (!x || !z) return;
  switch (n) {
  case 0:
  add_to_start:
    z->g.n = &x->X509Certificate->g;
    x->X509Certificate = z;
    return;
  case -1:
    y = x->X509Certificate;
    if (!y) goto add_to_start;
    for (; y->g.n; y = (struct zx_elem_s*)y->g.n) ;
    break;
  default:
    for (y = x->X509Certificate; n > 1 && y; --n, y = (struct zx_elem_s*)y->g.n) ;
    if (!y) return;
  }
  z->g.n = y->g.n;
  y->g.n = &z->g;
}

/* FUNC(zx_ds_X509Data_DEL_X509Certificate) */

void zx_ds_X509Data_DEL_X509Certificate(struct zx_ds_X509Data_s* x, int n)
{
  struct zx_elem_s* y;
  if (!x) return;
  switch (n) {
  case 0:
    x->X509Certificate = (struct zx_elem_s*)x->X509Certificate->g.n;
    return;
  case -1:
    y = (struct zx_elem_s*)x->X509Certificate;
    if (!y) return;
    for (; y->g.n; y = (struct zx_elem_s*)y->g.n) ;
    break;
  default:
    for (y = x->X509Certificate; n > 1 && y->g.n; --n, y = (struct zx_elem_s*)y->g.n) ;
    if (!y->g.n) return;
  }
  y->g.n = y->g.n->n;
}

#endif



#ifdef ZX_ENA_GETPUT

/* FUNC(zx_ds_X509Data_NUM_X509CRL) */

int zx_ds_X509Data_NUM_X509CRL(struct zx_ds_X509Data_s* x)
{
  struct zx_elem_s* y;
  int n = 0;
  if (!x) return 0;
  for (y = x->X509CRL; y; ++n, y = (struct zx_elem_s*)y->g.n) ;
  return n;
}

/* FUNC(zx_ds_X509Data_GET_X509CRL) */

struct zx_elem_s* zx_ds_X509Data_GET_X509CRL(struct zx_ds_X509Data_s* x, int n)
{
  struct zx_elem_s* y;
  if (!x) return 0;
  for (y = x->X509CRL; n>=0 && y; --n, y = (struct zx_elem_s*)y->g.n) ;
  return y;
}

/* FUNC(zx_ds_X509Data_POP_X509CRL) */

struct zx_elem_s* zx_ds_X509Data_POP_X509CRL(struct zx_ds_X509Data_s* x)
{
  struct zx_elem_s* y;
  if (!x) return 0;
  y = x->X509CRL;
  if (y)
    x->X509CRL = (struct zx_elem_s*)y->g.n;
  return y;
}

/* FUNC(zx_ds_X509Data_PUSH_X509CRL) */

void zx_ds_X509Data_PUSH_X509CRL(struct zx_ds_X509Data_s* x, struct zx_elem_s* z)
{
  if (!x || !z) return;
  z->g.n = &x->X509CRL->g;
  x->X509CRL = z;
}

/* FUNC(zx_ds_X509Data_REV_X509CRL) */

void zx_ds_X509Data_REV_X509CRL(struct zx_ds_X509Data_s* x)
{
  struct zx_elem_s* nxt;
  struct zx_elem_s* y;
  if (!x) return;
  y = x->X509CRL;
  if (!y) return;
  x->X509CRL = 0;
  while (y) {
    nxt = (struct zx_elem_s*)y->g.n;
    y->g.n = &x->X509CRL->g;
    x->X509CRL = y;
    y = nxt;
  }
}

/* FUNC(zx_ds_X509Data_PUT_X509CRL) */

void zx_ds_X509Data_PUT_X509CRL(struct zx_ds_X509Data_s* x, int n, struct zx_elem_s* z)
{
  struct zx_elem_s* y;
  if (!x || !z) return;
  y = x->X509CRL;
  if (!y) return;
  switch (n) {
  case 0:
    z->g.n = y->g.n;
    x->X509CRL = z;
    return;
  default:
    for (; n > 1 && y->g.n; --n, y = (struct zx_elem_s*)y->g.n) ;
    if (!y->g.n) return;
    z->g.n = y->g.n->n;
    y->g.n = &z->g;
  }
}

/* FUNC(zx_ds_X509Data_ADD_X509CRL) */

void zx_ds_X509Data_ADD_X509CRL(struct zx_ds_X509Data_s* x, int n, struct zx_elem_s* z)
{
  struct zx_elem_s* y;
  if (!x || !z) return;
  switch (n) {
  case 0:
  add_to_start:
    z->g.n = &x->X509CRL->g;
    x->X509CRL = z;
    return;
  case -1:
    y = x->X509CRL;
    if (!y) goto add_to_start;
    for (; y->g.n; y = (struct zx_elem_s*)y->g.n) ;
    break;
  default:
    for (y = x->X509CRL; n > 1 && y; --n, y = (struct zx_elem_s*)y->g.n) ;
    if (!y) return;
  }
  z->g.n = y->g.n;
  y->g.n = &z->g;
}

/* FUNC(zx_ds_X509Data_DEL_X509CRL) */

void zx_ds_X509Data_DEL_X509CRL(struct zx_ds_X509Data_s* x, int n)
{
  struct zx_elem_s* y;
  if (!x) return;
  switch (n) {
  case 0:
    x->X509CRL = (struct zx_elem_s*)x->X509CRL->g.n;
    return;
  case -1:
    y = (struct zx_elem_s*)x->X509CRL;
    if (!y) return;
    for (; y->g.n; y = (struct zx_elem_s*)y->g.n) ;
    break;
  default:
    for (y = x->X509CRL; n > 1 && y->g.n; --n, y = (struct zx_elem_s*)y->g.n) ;
    if (!y->g.n) return;
  }
  y->g.n = y->g.n->n;
}

#endif








#ifdef ZX_ENA_GETPUT

/* FUNC(zx_ds_X509IssuerSerial_NUM_X509IssuerName) */

int zx_ds_X509IssuerSerial_NUM_X509IssuerName(struct zx_ds_X509IssuerSerial_s* x)
{
  struct zx_elem_s* y;
  int n = 0;
  if (!x) return 0;
  for (y = x->X509IssuerName; y; ++n, y = (struct zx_elem_s*)y->g.n) ;
  return n;
}

/* FUNC(zx_ds_X509IssuerSerial_GET_X509IssuerName) */

struct zx_elem_s* zx_ds_X509IssuerSerial_GET_X509IssuerName(struct zx_ds_X509IssuerSerial_s* x, int n)
{
  struct zx_elem_s* y;
  if (!x) return 0;
  for (y = x->X509IssuerName; n>=0 && y; --n, y = (struct zx_elem_s*)y->g.n) ;
  return y;
}

/* FUNC(zx_ds_X509IssuerSerial_POP_X509IssuerName) */

struct zx_elem_s* zx_ds_X509IssuerSerial_POP_X509IssuerName(struct zx_ds_X509IssuerSerial_s* x)
{
  struct zx_elem_s* y;
  if (!x) return 0;
  y = x->X509IssuerName;
  if (y)
    x->X509IssuerName = (struct zx_elem_s*)y->g.n;
  return y;
}

/* FUNC(zx_ds_X509IssuerSerial_PUSH_X509IssuerName) */

void zx_ds_X509IssuerSerial_PUSH_X509IssuerName(struct zx_ds_X509IssuerSerial_s* x, struct zx_elem_s* z)
{
  if (!x || !z) return;
  z->g.n = &x->X509IssuerName->g;
  x->X509IssuerName = z;
}

/* FUNC(zx_ds_X509IssuerSerial_REV_X509IssuerName) */

void zx_ds_X509IssuerSerial_REV_X509IssuerName(struct zx_ds_X509IssuerSerial_s* x)
{
  struct zx_elem_s* nxt;
  struct zx_elem_s* y;
  if (!x) return;
  y = x->X509IssuerName;
  if (!y) return;
  x->X509IssuerName = 0;
  while (y) {
    nxt = (struct zx_elem_s*)y->g.n;
    y->g.n = &x->X509IssuerName->g;
    x->X509IssuerName = y;
    y = nxt;
  }
}

/* FUNC(zx_ds_X509IssuerSerial_PUT_X509IssuerName) */

void zx_ds_X509IssuerSerial_PUT_X509IssuerName(struct zx_ds_X509IssuerSerial_s* x, int n, struct zx_elem_s* z)
{
  struct zx_elem_s* y;
  if (!x || !z) return;
  y = x->X509IssuerName;
  if (!y) return;
  switch (n) {
  case 0:
    z->g.n = y->g.n;
    x->X509IssuerName = z;
    return;
  default:
    for (; n > 1 && y->g.n; --n, y = (struct zx_elem_s*)y->g.n) ;
    if (!y->g.n) return;
    z->g.n = y->g.n->n;
    y->g.n = &z->g;
  }
}

/* FUNC(zx_ds_X509IssuerSerial_ADD_X509IssuerName) */

void zx_ds_X509IssuerSerial_ADD_X509IssuerName(struct zx_ds_X509IssuerSerial_s* x, int n, struct zx_elem_s* z)
{
  struct zx_elem_s* y;
  if (!x || !z) return;
  switch (n) {
  case 0:
  add_to_start:
    z->g.n = &x->X509IssuerName->g;
    x->X509IssuerName = z;
    return;
  case -1:
    y = x->X509IssuerName;
    if (!y) goto add_to_start;
    for (; y->g.n; y = (struct zx_elem_s*)y->g.n) ;
    break;
  default:
    for (y = x->X509IssuerName; n > 1 && y; --n, y = (struct zx_elem_s*)y->g.n) ;
    if (!y) return;
  }
  z->g.n = y->g.n;
  y->g.n = &z->g;
}

/* FUNC(zx_ds_X509IssuerSerial_DEL_X509IssuerName) */

void zx_ds_X509IssuerSerial_DEL_X509IssuerName(struct zx_ds_X509IssuerSerial_s* x, int n)
{
  struct zx_elem_s* y;
  if (!x) return;
  switch (n) {
  case 0:
    x->X509IssuerName = (struct zx_elem_s*)x->X509IssuerName->g.n;
    return;
  case -1:
    y = (struct zx_elem_s*)x->X509IssuerName;
    if (!y) return;
    for (; y->g.n; y = (struct zx_elem_s*)y->g.n) ;
    break;
  default:
    for (y = x->X509IssuerName; n > 1 && y->g.n; --n, y = (struct zx_elem_s*)y->g.n) ;
    if (!y->g.n) return;
  }
  y->g.n = y->g.n->n;
}

#endif



#ifdef ZX_ENA_GETPUT

/* FUNC(zx_ds_X509IssuerSerial_NUM_X509SerialNumber) */

int zx_ds_X509IssuerSerial_NUM_X509SerialNumber(struct zx_ds_X509IssuerSerial_s* x)
{
  struct zx_elem_s* y;
  int n = 0;
  if (!x) return 0;
  for (y = x->X509SerialNumber; y; ++n, y = (struct zx_elem_s*)y->g.n) ;
  return n;
}

/* FUNC(zx_ds_X509IssuerSerial_GET_X509SerialNumber) */

struct zx_elem_s* zx_ds_X509IssuerSerial_GET_X509SerialNumber(struct zx_ds_X509IssuerSerial_s* x, int n)
{
  struct zx_elem_s* y;
  if (!x) return 0;
  for (y = x->X509SerialNumber; n>=0 && y; --n, y = (struct zx_elem_s*)y->g.n) ;
  return y;
}

/* FUNC(zx_ds_X509IssuerSerial_POP_X509SerialNumber) */

struct zx_elem_s* zx_ds_X509IssuerSerial_POP_X509SerialNumber(struct zx_ds_X509IssuerSerial_s* x)
{
  struct zx_elem_s* y;
  if (!x) return 0;
  y = x->X509SerialNumber;
  if (y)
    x->X509SerialNumber = (struct zx_elem_s*)y->g.n;
  return y;
}

/* FUNC(zx_ds_X509IssuerSerial_PUSH_X509SerialNumber) */

void zx_ds_X509IssuerSerial_PUSH_X509SerialNumber(struct zx_ds_X509IssuerSerial_s* x, struct zx_elem_s* z)
{
  if (!x || !z) return;
  z->g.n = &x->X509SerialNumber->g;
  x->X509SerialNumber = z;
}

/* FUNC(zx_ds_X509IssuerSerial_REV_X509SerialNumber) */

void zx_ds_X509IssuerSerial_REV_X509SerialNumber(struct zx_ds_X509IssuerSerial_s* x)
{
  struct zx_elem_s* nxt;
  struct zx_elem_s* y;
  if (!x) return;
  y = x->X509SerialNumber;
  if (!y) return;
  x->X509SerialNumber = 0;
  while (y) {
    nxt = (struct zx_elem_s*)y->g.n;
    y->g.n = &x->X509SerialNumber->g;
    x->X509SerialNumber = y;
    y = nxt;
  }
}

/* FUNC(zx_ds_X509IssuerSerial_PUT_X509SerialNumber) */

void zx_ds_X509IssuerSerial_PUT_X509SerialNumber(struct zx_ds_X509IssuerSerial_s* x, int n, struct zx_elem_s* z)
{
  struct zx_elem_s* y;
  if (!x || !z) return;
  y = x->X509SerialNumber;
  if (!y) return;
  switch (n) {
  case 0:
    z->g.n = y->g.n;
    x->X509SerialNumber = z;
    return;
  default:
    for (; n > 1 && y->g.n; --n, y = (struct zx_elem_s*)y->g.n) ;
    if (!y->g.n) return;
    z->g.n = y->g.n->n;
    y->g.n = &z->g;
  }
}

/* FUNC(zx_ds_X509IssuerSerial_ADD_X509SerialNumber) */

void zx_ds_X509IssuerSerial_ADD_X509SerialNumber(struct zx_ds_X509IssuerSerial_s* x, int n, struct zx_elem_s* z)
{
  struct zx_elem_s* y;
  if (!x || !z) return;
  switch (n) {
  case 0:
  add_to_start:
    z->g.n = &x->X509SerialNumber->g;
    x->X509SerialNumber = z;
    return;
  case -1:
    y = x->X509SerialNumber;
    if (!y) goto add_to_start;
    for (; y->g.n; y = (struct zx_elem_s*)y->g.n) ;
    break;
  default:
    for (y = x->X509SerialNumber; n > 1 && y; --n, y = (struct zx_elem_s*)y->g.n) ;
    if (!y) return;
  }
  z->g.n = y->g.n;
  y->g.n = &z->g;
}

/* FUNC(zx_ds_X509IssuerSerial_DEL_X509SerialNumber) */

void zx_ds_X509IssuerSerial_DEL_X509SerialNumber(struct zx_ds_X509IssuerSerial_s* x, int n)
{
  struct zx_elem_s* y;
  if (!x) return;
  switch (n) {
  case 0:
    x->X509SerialNumber = (struct zx_elem_s*)x->X509SerialNumber->g.n;
    return;
  case -1:
    y = (struct zx_elem_s*)x->X509SerialNumber;
    if (!y) return;
    for (; y->g.n; y = (struct zx_elem_s*)y->g.n) ;
    break;
  default:
    for (y = x->X509SerialNumber; n > 1 && y->g.n; --n, y = (struct zx_elem_s*)y->g.n) ;
    if (!y->g.n) return;
  }
  y->g.n = y->g.n->n;
}

#endif






/* EOF -- c/zx-ds-getput.c */