/* c/zx-wsu-getput.c - WARNING: This file was automatically generated. DO NOT EDIT!
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
#include "c/zx-wsu-data.h"

/* FUNC(zx_wsu_Created_GET_ID) */
struct zx_str* zx_wsu_Created_GET_ID(struct zx_wsu_Created_s* x) { return x->ID; }
/* FUNC(zx_wsu_Created_PUT_ID) */
void zx_wsu_Created_PUT_ID(struct zx_wsu_Created_s* x, struct zx_str* y) { x->ID = y; }
/* FUNC(zx_wsu_Created_GET_id) */
struct zx_str* zx_wsu_Created_GET_id(struct zx_wsu_Created_s* x) { return x->id; }
/* FUNC(zx_wsu_Created_PUT_id) */
void zx_wsu_Created_PUT_id(struct zx_wsu_Created_s* x, struct zx_str* y) { x->id = y; }
/* FUNC(zx_wsu_Created_GET_Id) */
struct zx_str* zx_wsu_Created_GET_Id(struct zx_wsu_Created_s* x) { return x->Id; }
/* FUNC(zx_wsu_Created_PUT_Id) */
void zx_wsu_Created_PUT_Id(struct zx_wsu_Created_s* x, struct zx_str* y) { x->Id = y; }





/* FUNC(zx_wsu_Expires_GET_ID) */
struct zx_str* zx_wsu_Expires_GET_ID(struct zx_wsu_Expires_s* x) { return x->ID; }
/* FUNC(zx_wsu_Expires_PUT_ID) */
void zx_wsu_Expires_PUT_ID(struct zx_wsu_Expires_s* x, struct zx_str* y) { x->ID = y; }
/* FUNC(zx_wsu_Expires_GET_id) */
struct zx_str* zx_wsu_Expires_GET_id(struct zx_wsu_Expires_s* x) { return x->id; }
/* FUNC(zx_wsu_Expires_PUT_id) */
void zx_wsu_Expires_PUT_id(struct zx_wsu_Expires_s* x, struct zx_str* y) { x->id = y; }
/* FUNC(zx_wsu_Expires_GET_Id) */
struct zx_str* zx_wsu_Expires_GET_Id(struct zx_wsu_Expires_s* x) { return x->Id; }
/* FUNC(zx_wsu_Expires_PUT_Id) */
void zx_wsu_Expires_PUT_Id(struct zx_wsu_Expires_s* x, struct zx_str* y) { x->Id = y; }







#ifdef ZX_ENA_GETPUT

/* FUNC(zx_wsu_Timestamp_NUM_Created) */

int zx_wsu_Timestamp_NUM_Created(struct zx_wsu_Timestamp_s* x)
{
  struct zx_wsu_Created_s* y;
  int n = 0;
  if (!x) return 0;
  for (y = x->Created; y; ++n, y = (struct zx_wsu_Created_s*)y->gg.g.n) ;
  return n;
}

/* FUNC(zx_wsu_Timestamp_GET_Created) */

struct zx_wsu_Created_s* zx_wsu_Timestamp_GET_Created(struct zx_wsu_Timestamp_s* x, int n)
{
  struct zx_wsu_Created_s* y;
  if (!x) return 0;
  for (y = x->Created; n>=0 && y; --n, y = (struct zx_wsu_Created_s*)y->gg.g.n) ;
  return y;
}

/* FUNC(zx_wsu_Timestamp_POP_Created) */

struct zx_wsu_Created_s* zx_wsu_Timestamp_POP_Created(struct zx_wsu_Timestamp_s* x)
{
  struct zx_wsu_Created_s* y;
  if (!x) return 0;
  y = x->Created;
  if (y)
    x->Created = (struct zx_wsu_Created_s*)y->gg.g.n;
  return y;
}

/* FUNC(zx_wsu_Timestamp_PUSH_Created) */

void zx_wsu_Timestamp_PUSH_Created(struct zx_wsu_Timestamp_s* x, struct zx_wsu_Created_s* z)
{
  if (!x || !z) return;
  z->gg.g.n = &x->Created->gg.g;
  x->Created = z;
}

/* FUNC(zx_wsu_Timestamp_REV_Created) */

void zx_wsu_Timestamp_REV_Created(struct zx_wsu_Timestamp_s* x)
{
  struct zx_wsu_Created_s* nxt;
  struct zx_wsu_Created_s* y;
  if (!x) return;
  y = x->Created;
  if (!y) return;
  x->Created = 0;
  while (y) {
    nxt = (struct zx_wsu_Created_s*)y->gg.g.n;
    y->gg.g.n = &x->Created->gg.g;
    x->Created = y;
    y = nxt;
  }
}

/* FUNC(zx_wsu_Timestamp_PUT_Created) */

void zx_wsu_Timestamp_PUT_Created(struct zx_wsu_Timestamp_s* x, int n, struct zx_wsu_Created_s* z)
{
  struct zx_wsu_Created_s* y;
  if (!x || !z) return;
  y = x->Created;
  if (!y) return;
  switch (n) {
  case 0:
    z->gg.g.n = y->gg.g.n;
    x->Created = z;
    return;
  default:
    for (; n > 1 && y->gg.g.n; --n, y = (struct zx_wsu_Created_s*)y->gg.g.n) ;
    if (!y->gg.g.n) return;
    z->gg.g.n = y->gg.g.n->n;
    y->gg.g.n = &z->gg.g;
  }
}

/* FUNC(zx_wsu_Timestamp_ADD_Created) */

void zx_wsu_Timestamp_ADD_Created(struct zx_wsu_Timestamp_s* x, int n, struct zx_wsu_Created_s* z)
{
  struct zx_wsu_Created_s* y;
  if (!x || !z) return;
  switch (n) {
  case 0:
  add_to_start:
    z->gg.g.n = &x->Created->gg.g;
    x->Created = z;
    return;
  case -1:
    y = x->Created;
    if (!y) goto add_to_start;
    for (; y->gg.g.n; y = (struct zx_wsu_Created_s*)y->gg.g.n) ;
    break;
  default:
    for (y = x->Created; n > 1 && y; --n, y = (struct zx_wsu_Created_s*)y->gg.g.n) ;
    if (!y) return;
  }
  z->gg.g.n = y->gg.g.n;
  y->gg.g.n = &z->gg.g;
}

/* FUNC(zx_wsu_Timestamp_DEL_Created) */

void zx_wsu_Timestamp_DEL_Created(struct zx_wsu_Timestamp_s* x, int n)
{
  struct zx_wsu_Created_s* y;
  if (!x) return;
  switch (n) {
  case 0:
    x->Created = (struct zx_wsu_Created_s*)x->Created->gg.g.n;
    return;
  case -1:
    y = (struct zx_wsu_Created_s*)x->Created;
    if (!y) return;
    for (; y->gg.g.n; y = (struct zx_wsu_Created_s*)y->gg.g.n) ;
    break;
  default:
    for (y = x->Created; n > 1 && y->gg.g.n; --n, y = (struct zx_wsu_Created_s*)y->gg.g.n) ;
    if (!y->gg.g.n) return;
  }
  y->gg.g.n = y->gg.g.n->n;
}

#endif



#ifdef ZX_ENA_GETPUT

/* FUNC(zx_wsu_Timestamp_NUM_Expires) */

int zx_wsu_Timestamp_NUM_Expires(struct zx_wsu_Timestamp_s* x)
{
  struct zx_wsu_Expires_s* y;
  int n = 0;
  if (!x) return 0;
  for (y = x->Expires; y; ++n, y = (struct zx_wsu_Expires_s*)y->gg.g.n) ;
  return n;
}

/* FUNC(zx_wsu_Timestamp_GET_Expires) */

struct zx_wsu_Expires_s* zx_wsu_Timestamp_GET_Expires(struct zx_wsu_Timestamp_s* x, int n)
{
  struct zx_wsu_Expires_s* y;
  if (!x) return 0;
  for (y = x->Expires; n>=0 && y; --n, y = (struct zx_wsu_Expires_s*)y->gg.g.n) ;
  return y;
}

/* FUNC(zx_wsu_Timestamp_POP_Expires) */

struct zx_wsu_Expires_s* zx_wsu_Timestamp_POP_Expires(struct zx_wsu_Timestamp_s* x)
{
  struct zx_wsu_Expires_s* y;
  if (!x) return 0;
  y = x->Expires;
  if (y)
    x->Expires = (struct zx_wsu_Expires_s*)y->gg.g.n;
  return y;
}

/* FUNC(zx_wsu_Timestamp_PUSH_Expires) */

void zx_wsu_Timestamp_PUSH_Expires(struct zx_wsu_Timestamp_s* x, struct zx_wsu_Expires_s* z)
{
  if (!x || !z) return;
  z->gg.g.n = &x->Expires->gg.g;
  x->Expires = z;
}

/* FUNC(zx_wsu_Timestamp_REV_Expires) */

void zx_wsu_Timestamp_REV_Expires(struct zx_wsu_Timestamp_s* x)
{
  struct zx_wsu_Expires_s* nxt;
  struct zx_wsu_Expires_s* y;
  if (!x) return;
  y = x->Expires;
  if (!y) return;
  x->Expires = 0;
  while (y) {
    nxt = (struct zx_wsu_Expires_s*)y->gg.g.n;
    y->gg.g.n = &x->Expires->gg.g;
    x->Expires = y;
    y = nxt;
  }
}

/* FUNC(zx_wsu_Timestamp_PUT_Expires) */

void zx_wsu_Timestamp_PUT_Expires(struct zx_wsu_Timestamp_s* x, int n, struct zx_wsu_Expires_s* z)
{
  struct zx_wsu_Expires_s* y;
  if (!x || !z) return;
  y = x->Expires;
  if (!y) return;
  switch (n) {
  case 0:
    z->gg.g.n = y->gg.g.n;
    x->Expires = z;
    return;
  default:
    for (; n > 1 && y->gg.g.n; --n, y = (struct zx_wsu_Expires_s*)y->gg.g.n) ;
    if (!y->gg.g.n) return;
    z->gg.g.n = y->gg.g.n->n;
    y->gg.g.n = &z->gg.g;
  }
}

/* FUNC(zx_wsu_Timestamp_ADD_Expires) */

void zx_wsu_Timestamp_ADD_Expires(struct zx_wsu_Timestamp_s* x, int n, struct zx_wsu_Expires_s* z)
{
  struct zx_wsu_Expires_s* y;
  if (!x || !z) return;
  switch (n) {
  case 0:
  add_to_start:
    z->gg.g.n = &x->Expires->gg.g;
    x->Expires = z;
    return;
  case -1:
    y = x->Expires;
    if (!y) goto add_to_start;
    for (; y->gg.g.n; y = (struct zx_wsu_Expires_s*)y->gg.g.n) ;
    break;
  default:
    for (y = x->Expires; n > 1 && y; --n, y = (struct zx_wsu_Expires_s*)y->gg.g.n) ;
    if (!y) return;
  }
  z->gg.g.n = y->gg.g.n;
  y->gg.g.n = &z->gg.g;
}

/* FUNC(zx_wsu_Timestamp_DEL_Expires) */

void zx_wsu_Timestamp_DEL_Expires(struct zx_wsu_Timestamp_s* x, int n)
{
  struct zx_wsu_Expires_s* y;
  if (!x) return;
  switch (n) {
  case 0:
    x->Expires = (struct zx_wsu_Expires_s*)x->Expires->gg.g.n;
    return;
  case -1:
    y = (struct zx_wsu_Expires_s*)x->Expires;
    if (!y) return;
    for (; y->gg.g.n; y = (struct zx_wsu_Expires_s*)y->gg.g.n) ;
    break;
  default:
    for (y = x->Expires; n > 1 && y->gg.g.n; --n, y = (struct zx_wsu_Expires_s*)y->gg.g.n) ;
    if (!y->gg.g.n) return;
  }
  y->gg.g.n = y->gg.g.n->n;
}

#endif

/* FUNC(zx_wsu_Timestamp_GET_ID) */
struct zx_str* zx_wsu_Timestamp_GET_ID(struct zx_wsu_Timestamp_s* x) { return x->ID; }
/* FUNC(zx_wsu_Timestamp_PUT_ID) */
void zx_wsu_Timestamp_PUT_ID(struct zx_wsu_Timestamp_s* x, struct zx_str* y) { x->ID = y; }
/* FUNC(zx_wsu_Timestamp_GET_id) */
struct zx_str* zx_wsu_Timestamp_GET_id(struct zx_wsu_Timestamp_s* x) { return x->id; }
/* FUNC(zx_wsu_Timestamp_PUT_id) */
void zx_wsu_Timestamp_PUT_id(struct zx_wsu_Timestamp_s* x, struct zx_str* y) { x->id = y; }
/* FUNC(zx_wsu_Timestamp_GET_Id) */
struct zx_str* zx_wsu_Timestamp_GET_Id(struct zx_wsu_Timestamp_s* x) { return x->Id; }
/* FUNC(zx_wsu_Timestamp_PUT_Id) */
void zx_wsu_Timestamp_PUT_Id(struct zx_wsu_Timestamp_s* x, struct zx_str* y) { x->Id = y; }





/* EOF -- c/zx-wsu-getput.c */
