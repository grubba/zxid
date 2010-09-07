/* c/zx-lu-getput.c - WARNING: This file was automatically generated. DO NOT EDIT!
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
#include "c/zx-lu-data.h"








#ifdef ZX_ENA_GETPUT

/* FUNC(zx_lu_Status_NUM_Status) */

int zx_lu_Status_NUM_Status(struct zx_lu_Status_s* x)
{
  struct zx_lu_Status_s* y;
  int n = 0;
  if (!x) return 0;
  for (y = x->Status; y; ++n, y = (struct zx_lu_Status_s*)y->gg.g.n) ;
  return n;
}

/* FUNC(zx_lu_Status_GET_Status) */

struct zx_lu_Status_s* zx_lu_Status_GET_Status(struct zx_lu_Status_s* x, int n)
{
  struct zx_lu_Status_s* y;
  if (!x) return 0;
  for (y = x->Status; n>=0 && y; --n, y = (struct zx_lu_Status_s*)y->gg.g.n) ;
  return y;
}

/* FUNC(zx_lu_Status_POP_Status) */

struct zx_lu_Status_s* zx_lu_Status_POP_Status(struct zx_lu_Status_s* x)
{
  struct zx_lu_Status_s* y;
  if (!x) return 0;
  y = x->Status;
  if (y)
    x->Status = (struct zx_lu_Status_s*)y->gg.g.n;
  return y;
}

/* FUNC(zx_lu_Status_PUSH_Status) */

void zx_lu_Status_PUSH_Status(struct zx_lu_Status_s* x, struct zx_lu_Status_s* z)
{
  if (!x || !z) return;
  z->gg.g.n = &x->Status->gg.g;
  x->Status = z;
}

/* FUNC(zx_lu_Status_REV_Status) */

void zx_lu_Status_REV_Status(struct zx_lu_Status_s* x)
{
  struct zx_lu_Status_s* nxt;
  struct zx_lu_Status_s* y;
  if (!x) return;
  y = x->Status;
  if (!y) return;
  x->Status = 0;
  while (y) {
    nxt = (struct zx_lu_Status_s*)y->gg.g.n;
    y->gg.g.n = &x->Status->gg.g;
    x->Status = y;
    y = nxt;
  }
}

/* FUNC(zx_lu_Status_PUT_Status) */

void zx_lu_Status_PUT_Status(struct zx_lu_Status_s* x, int n, struct zx_lu_Status_s* z)
{
  struct zx_lu_Status_s* y;
  if (!x || !z) return;
  y = x->Status;
  if (!y) return;
  switch (n) {
  case 0:
    z->gg.g.n = y->gg.g.n;
    x->Status = z;
    return;
  default:
    for (; n > 1 && y->gg.g.n; --n, y = (struct zx_lu_Status_s*)y->gg.g.n) ;
    if (!y->gg.g.n) return;
    z->gg.g.n = y->gg.g.n->n;
    y->gg.g.n = &z->gg.g;
  }
}

/* FUNC(zx_lu_Status_ADD_Status) */

void zx_lu_Status_ADD_Status(struct zx_lu_Status_s* x, int n, struct zx_lu_Status_s* z)
{
  struct zx_lu_Status_s* y;
  if (!x || !z) return;
  switch (n) {
  case 0:
  add_to_start:
    z->gg.g.n = &x->Status->gg.g;
    x->Status = z;
    return;
  case -1:
    y = x->Status;
    if (!y) goto add_to_start;
    for (; y->gg.g.n; y = (struct zx_lu_Status_s*)y->gg.g.n) ;
    break;
  default:
    for (y = x->Status; n > 1 && y; --n, y = (struct zx_lu_Status_s*)y->gg.g.n) ;
    if (!y) return;
  }
  z->gg.g.n = y->gg.g.n;
  y->gg.g.n = &z->gg.g;
}

/* FUNC(zx_lu_Status_DEL_Status) */

void zx_lu_Status_DEL_Status(struct zx_lu_Status_s* x, int n)
{
  struct zx_lu_Status_s* y;
  if (!x) return;
  switch (n) {
  case 0:
    x->Status = (struct zx_lu_Status_s*)x->Status->gg.g.n;
    return;
  case -1:
    y = (struct zx_lu_Status_s*)x->Status;
    if (!y) return;
    for (; y->gg.g.n; y = (struct zx_lu_Status_s*)y->gg.g.n) ;
    break;
  default:
    for (y = x->Status; n > 1 && y->gg.g.n; --n, y = (struct zx_lu_Status_s*)y->gg.g.n) ;
    if (!y->gg.g.n) return;
  }
  y->gg.g.n = y->gg.g.n->n;
}

#endif

/* FUNC(zx_lu_Status_GET_code) */
struct zx_str* zx_lu_Status_GET_code(struct zx_lu_Status_s* x) { return x->code; }
/* FUNC(zx_lu_Status_PUT_code) */
void zx_lu_Status_PUT_code(struct zx_lu_Status_s* x, struct zx_str* y) { x->code = y; }
/* FUNC(zx_lu_Status_GET_comment) */
struct zx_str* zx_lu_Status_GET_comment(struct zx_lu_Status_s* x) { return x->comment; }
/* FUNC(zx_lu_Status_PUT_comment) */
void zx_lu_Status_PUT_comment(struct zx_lu_Status_s* x, struct zx_str* y) { x->comment = y; }
/* FUNC(zx_lu_Status_GET_ref) */
struct zx_str* zx_lu_Status_GET_ref(struct zx_lu_Status_s* x) { return x->ref; }
/* FUNC(zx_lu_Status_PUT_ref) */
void zx_lu_Status_PUT_ref(struct zx_lu_Status_s* x, struct zx_str* y) { x->ref = y; }





/* FUNC(zx_lu_TestResult_GET_itemIDRef) */
struct zx_str* zx_lu_TestResult_GET_itemIDRef(struct zx_lu_TestResult_s* x) { return x->itemIDRef; }
/* FUNC(zx_lu_TestResult_PUT_itemIDRef) */
void zx_lu_TestResult_PUT_itemIDRef(struct zx_lu_TestResult_s* x, struct zx_str* y) { x->itemIDRef = y; }





/* EOF -- c/zx-lu-getput.c */