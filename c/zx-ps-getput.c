/* c/zx-ps-getput.c - WARNING: This file was automatically generated. DO NOT EDIT!
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
#include "c/zx-ps-data.h"



#ifdef ZX_ENA_GETPUT

/* FUNC(zx_ps_AddCollectionRequest_NUM_Object) */

int zx_ps_AddCollectionRequest_NUM_Object(struct zx_ps_AddCollectionRequest_s* x)
{
  struct zx_ps_Object_s* y;
  int n = 0;
  if (!x) return 0;
  for (y = x->Object; y; ++n, y = (struct zx_ps_Object_s*)y->gg.g.n) ;
  return n;
}

/* FUNC(zx_ps_AddCollectionRequest_GET_Object) */

struct zx_ps_Object_s* zx_ps_AddCollectionRequest_GET_Object(struct zx_ps_AddCollectionRequest_s* x, int n)
{
  struct zx_ps_Object_s* y;
  if (!x) return 0;
  for (y = x->Object; n>=0 && y; --n, y = (struct zx_ps_Object_s*)y->gg.g.n) ;
  return y;
}

/* FUNC(zx_ps_AddCollectionRequest_POP_Object) */

struct zx_ps_Object_s* zx_ps_AddCollectionRequest_POP_Object(struct zx_ps_AddCollectionRequest_s* x)
{
  struct zx_ps_Object_s* y;
  if (!x) return 0;
  y = x->Object;
  if (y)
    x->Object = (struct zx_ps_Object_s*)y->gg.g.n;
  return y;
}

/* FUNC(zx_ps_AddCollectionRequest_PUSH_Object) */

void zx_ps_AddCollectionRequest_PUSH_Object(struct zx_ps_AddCollectionRequest_s* x, struct zx_ps_Object_s* z)
{
  if (!x || !z) return;
  z->gg.g.n = &x->Object->gg.g;
  x->Object = z;
}

/* FUNC(zx_ps_AddCollectionRequest_REV_Object) */

void zx_ps_AddCollectionRequest_REV_Object(struct zx_ps_AddCollectionRequest_s* x)
{
  struct zx_ps_Object_s* nxt;
  struct zx_ps_Object_s* y;
  if (!x) return;
  y = x->Object;
  if (!y) return;
  x->Object = 0;
  while (y) {
    nxt = (struct zx_ps_Object_s*)y->gg.g.n;
    y->gg.g.n = &x->Object->gg.g;
    x->Object = y;
    y = nxt;
  }
}

/* FUNC(zx_ps_AddCollectionRequest_PUT_Object) */

void zx_ps_AddCollectionRequest_PUT_Object(struct zx_ps_AddCollectionRequest_s* x, int n, struct zx_ps_Object_s* z)
{
  struct zx_ps_Object_s* y;
  if (!x || !z) return;
  y = x->Object;
  if (!y) return;
  switch (n) {
  case 0:
    z->gg.g.n = y->gg.g.n;
    x->Object = z;
    return;
  default:
    for (; n > 1 && y->gg.g.n; --n, y = (struct zx_ps_Object_s*)y->gg.g.n) ;
    if (!y->gg.g.n) return;
    z->gg.g.n = y->gg.g.n->n;
    y->gg.g.n = &z->gg.g;
  }
}

/* FUNC(zx_ps_AddCollectionRequest_ADD_Object) */

void zx_ps_AddCollectionRequest_ADD_Object(struct zx_ps_AddCollectionRequest_s* x, int n, struct zx_ps_Object_s* z)
{
  struct zx_ps_Object_s* y;
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
    for (; y->gg.g.n; y = (struct zx_ps_Object_s*)y->gg.g.n) ;
    break;
  default:
    for (y = x->Object; n > 1 && y; --n, y = (struct zx_ps_Object_s*)y->gg.g.n) ;
    if (!y) return;
  }
  z->gg.g.n = y->gg.g.n;
  y->gg.g.n = &z->gg.g;
}

/* FUNC(zx_ps_AddCollectionRequest_DEL_Object) */

void zx_ps_AddCollectionRequest_DEL_Object(struct zx_ps_AddCollectionRequest_s* x, int n)
{
  struct zx_ps_Object_s* y;
  if (!x) return;
  switch (n) {
  case 0:
    x->Object = (struct zx_ps_Object_s*)x->Object->gg.g.n;
    return;
  case -1:
    y = (struct zx_ps_Object_s*)x->Object;
    if (!y) return;
    for (; y->gg.g.n; y = (struct zx_ps_Object_s*)y->gg.g.n) ;
    break;
  default:
    for (y = x->Object; n > 1 && y->gg.g.n; --n, y = (struct zx_ps_Object_s*)y->gg.g.n) ;
    if (!y->gg.g.n) return;
  }
  y->gg.g.n = y->gg.g.n->n;
}

#endif



#ifdef ZX_ENA_GETPUT

/* FUNC(zx_ps_AddCollectionRequest_NUM_Subscription) */

int zx_ps_AddCollectionRequest_NUM_Subscription(struct zx_ps_AddCollectionRequest_s* x)
{
  struct zx_ps_Subscription_s* y;
  int n = 0;
  if (!x) return 0;
  for (y = x->Subscription; y; ++n, y = (struct zx_ps_Subscription_s*)y->gg.g.n) ;
  return n;
}

/* FUNC(zx_ps_AddCollectionRequest_GET_Subscription) */

struct zx_ps_Subscription_s* zx_ps_AddCollectionRequest_GET_Subscription(struct zx_ps_AddCollectionRequest_s* x, int n)
{
  struct zx_ps_Subscription_s* y;
  if (!x) return 0;
  for (y = x->Subscription; n>=0 && y; --n, y = (struct zx_ps_Subscription_s*)y->gg.g.n) ;
  return y;
}

/* FUNC(zx_ps_AddCollectionRequest_POP_Subscription) */

struct zx_ps_Subscription_s* zx_ps_AddCollectionRequest_POP_Subscription(struct zx_ps_AddCollectionRequest_s* x)
{
  struct zx_ps_Subscription_s* y;
  if (!x) return 0;
  y = x->Subscription;
  if (y)
    x->Subscription = (struct zx_ps_Subscription_s*)y->gg.g.n;
  return y;
}

/* FUNC(zx_ps_AddCollectionRequest_PUSH_Subscription) */

void zx_ps_AddCollectionRequest_PUSH_Subscription(struct zx_ps_AddCollectionRequest_s* x, struct zx_ps_Subscription_s* z)
{
  if (!x || !z) return;
  z->gg.g.n = &x->Subscription->gg.g;
  x->Subscription = z;
}

/* FUNC(zx_ps_AddCollectionRequest_REV_Subscription) */

void zx_ps_AddCollectionRequest_REV_Subscription(struct zx_ps_AddCollectionRequest_s* x)
{
  struct zx_ps_Subscription_s* nxt;
  struct zx_ps_Subscription_s* y;
  if (!x) return;
  y = x->Subscription;
  if (!y) return;
  x->Subscription = 0;
  while (y) {
    nxt = (struct zx_ps_Subscription_s*)y->gg.g.n;
    y->gg.g.n = &x->Subscription->gg.g;
    x->Subscription = y;
    y = nxt;
  }
}

/* FUNC(zx_ps_AddCollectionRequest_PUT_Subscription) */

void zx_ps_AddCollectionRequest_PUT_Subscription(struct zx_ps_AddCollectionRequest_s* x, int n, struct zx_ps_Subscription_s* z)
{
  struct zx_ps_Subscription_s* y;
  if (!x || !z) return;
  y = x->Subscription;
  if (!y) return;
  switch (n) {
  case 0:
    z->gg.g.n = y->gg.g.n;
    x->Subscription = z;
    return;
  default:
    for (; n > 1 && y->gg.g.n; --n, y = (struct zx_ps_Subscription_s*)y->gg.g.n) ;
    if (!y->gg.g.n) return;
    z->gg.g.n = y->gg.g.n->n;
    y->gg.g.n = &z->gg.g;
  }
}

/* FUNC(zx_ps_AddCollectionRequest_ADD_Subscription) */

void zx_ps_AddCollectionRequest_ADD_Subscription(struct zx_ps_AddCollectionRequest_s* x, int n, struct zx_ps_Subscription_s* z)
{
  struct zx_ps_Subscription_s* y;
  if (!x || !z) return;
  switch (n) {
  case 0:
  add_to_start:
    z->gg.g.n = &x->Subscription->gg.g;
    x->Subscription = z;
    return;
  case -1:
    y = x->Subscription;
    if (!y) goto add_to_start;
    for (; y->gg.g.n; y = (struct zx_ps_Subscription_s*)y->gg.g.n) ;
    break;
  default:
    for (y = x->Subscription; n > 1 && y; --n, y = (struct zx_ps_Subscription_s*)y->gg.g.n) ;
    if (!y) return;
  }
  z->gg.g.n = y->gg.g.n;
  y->gg.g.n = &z->gg.g;
}

/* FUNC(zx_ps_AddCollectionRequest_DEL_Subscription) */

void zx_ps_AddCollectionRequest_DEL_Subscription(struct zx_ps_AddCollectionRequest_s* x, int n)
{
  struct zx_ps_Subscription_s* y;
  if (!x) return;
  switch (n) {
  case 0:
    x->Subscription = (struct zx_ps_Subscription_s*)x->Subscription->gg.g.n;
    return;
  case -1:
    y = (struct zx_ps_Subscription_s*)x->Subscription;
    if (!y) return;
    for (; y->gg.g.n; y = (struct zx_ps_Subscription_s*)y->gg.g.n) ;
    break;
  default:
    for (y = x->Subscription; n > 1 && y->gg.g.n; --n, y = (struct zx_ps_Subscription_s*)y->gg.g.n) ;
    if (!y->gg.g.n) return;
  }
  y->gg.g.n = y->gg.g.n->n;
}

#endif

/* FUNC(zx_ps_AddCollectionRequest_GET_id) */
struct zx_str* zx_ps_AddCollectionRequest_GET_id(struct zx_ps_AddCollectionRequest_s* x) { return x->id; }
/* FUNC(zx_ps_AddCollectionRequest_PUT_id) */
void zx_ps_AddCollectionRequest_PUT_id(struct zx_ps_AddCollectionRequest_s* x, struct zx_str* y) { x->id = y; }







#ifdef ZX_ENA_GETPUT

/* FUNC(zx_ps_AddCollectionResponse_NUM_Status) */

int zx_ps_AddCollectionResponse_NUM_Status(struct zx_ps_AddCollectionResponse_s* x)
{
  struct zx_lu_Status_s* y;
  int n = 0;
  if (!x) return 0;
  for (y = x->Status; y; ++n, y = (struct zx_lu_Status_s*)y->gg.g.n) ;
  return n;
}

/* FUNC(zx_ps_AddCollectionResponse_GET_Status) */

struct zx_lu_Status_s* zx_ps_AddCollectionResponse_GET_Status(struct zx_ps_AddCollectionResponse_s* x, int n)
{
  struct zx_lu_Status_s* y;
  if (!x) return 0;
  for (y = x->Status; n>=0 && y; --n, y = (struct zx_lu_Status_s*)y->gg.g.n) ;
  return y;
}

/* FUNC(zx_ps_AddCollectionResponse_POP_Status) */

struct zx_lu_Status_s* zx_ps_AddCollectionResponse_POP_Status(struct zx_ps_AddCollectionResponse_s* x)
{
  struct zx_lu_Status_s* y;
  if (!x) return 0;
  y = x->Status;
  if (y)
    x->Status = (struct zx_lu_Status_s*)y->gg.g.n;
  return y;
}

/* FUNC(zx_ps_AddCollectionResponse_PUSH_Status) */

void zx_ps_AddCollectionResponse_PUSH_Status(struct zx_ps_AddCollectionResponse_s* x, struct zx_lu_Status_s* z)
{
  if (!x || !z) return;
  z->gg.g.n = &x->Status->gg.g;
  x->Status = z;
}

/* FUNC(zx_ps_AddCollectionResponse_REV_Status) */

void zx_ps_AddCollectionResponse_REV_Status(struct zx_ps_AddCollectionResponse_s* x)
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

/* FUNC(zx_ps_AddCollectionResponse_PUT_Status) */

void zx_ps_AddCollectionResponse_PUT_Status(struct zx_ps_AddCollectionResponse_s* x, int n, struct zx_lu_Status_s* z)
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

/* FUNC(zx_ps_AddCollectionResponse_ADD_Status) */

void zx_ps_AddCollectionResponse_ADD_Status(struct zx_ps_AddCollectionResponse_s* x, int n, struct zx_lu_Status_s* z)
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

/* FUNC(zx_ps_AddCollectionResponse_DEL_Status) */

void zx_ps_AddCollectionResponse_DEL_Status(struct zx_ps_AddCollectionResponse_s* x, int n)
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



#ifdef ZX_ENA_GETPUT

/* FUNC(zx_ps_AddCollectionResponse_NUM_Object) */

int zx_ps_AddCollectionResponse_NUM_Object(struct zx_ps_AddCollectionResponse_s* x)
{
  struct zx_ps_Object_s* y;
  int n = 0;
  if (!x) return 0;
  for (y = x->Object; y; ++n, y = (struct zx_ps_Object_s*)y->gg.g.n) ;
  return n;
}

/* FUNC(zx_ps_AddCollectionResponse_GET_Object) */

struct zx_ps_Object_s* zx_ps_AddCollectionResponse_GET_Object(struct zx_ps_AddCollectionResponse_s* x, int n)
{
  struct zx_ps_Object_s* y;
  if (!x) return 0;
  for (y = x->Object; n>=0 && y; --n, y = (struct zx_ps_Object_s*)y->gg.g.n) ;
  return y;
}

/* FUNC(zx_ps_AddCollectionResponse_POP_Object) */

struct zx_ps_Object_s* zx_ps_AddCollectionResponse_POP_Object(struct zx_ps_AddCollectionResponse_s* x)
{
  struct zx_ps_Object_s* y;
  if (!x) return 0;
  y = x->Object;
  if (y)
    x->Object = (struct zx_ps_Object_s*)y->gg.g.n;
  return y;
}

/* FUNC(zx_ps_AddCollectionResponse_PUSH_Object) */

void zx_ps_AddCollectionResponse_PUSH_Object(struct zx_ps_AddCollectionResponse_s* x, struct zx_ps_Object_s* z)
{
  if (!x || !z) return;
  z->gg.g.n = &x->Object->gg.g;
  x->Object = z;
}

/* FUNC(zx_ps_AddCollectionResponse_REV_Object) */

void zx_ps_AddCollectionResponse_REV_Object(struct zx_ps_AddCollectionResponse_s* x)
{
  struct zx_ps_Object_s* nxt;
  struct zx_ps_Object_s* y;
  if (!x) return;
  y = x->Object;
  if (!y) return;
  x->Object = 0;
  while (y) {
    nxt = (struct zx_ps_Object_s*)y->gg.g.n;
    y->gg.g.n = &x->Object->gg.g;
    x->Object = y;
    y = nxt;
  }
}

/* FUNC(zx_ps_AddCollectionResponse_PUT_Object) */

void zx_ps_AddCollectionResponse_PUT_Object(struct zx_ps_AddCollectionResponse_s* x, int n, struct zx_ps_Object_s* z)
{
  struct zx_ps_Object_s* y;
  if (!x || !z) return;
  y = x->Object;
  if (!y) return;
  switch (n) {
  case 0:
    z->gg.g.n = y->gg.g.n;
    x->Object = z;
    return;
  default:
    for (; n > 1 && y->gg.g.n; --n, y = (struct zx_ps_Object_s*)y->gg.g.n) ;
    if (!y->gg.g.n) return;
    z->gg.g.n = y->gg.g.n->n;
    y->gg.g.n = &z->gg.g;
  }
}

/* FUNC(zx_ps_AddCollectionResponse_ADD_Object) */

void zx_ps_AddCollectionResponse_ADD_Object(struct zx_ps_AddCollectionResponse_s* x, int n, struct zx_ps_Object_s* z)
{
  struct zx_ps_Object_s* y;
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
    for (; y->gg.g.n; y = (struct zx_ps_Object_s*)y->gg.g.n) ;
    break;
  default:
    for (y = x->Object; n > 1 && y; --n, y = (struct zx_ps_Object_s*)y->gg.g.n) ;
    if (!y) return;
  }
  z->gg.g.n = y->gg.g.n;
  y->gg.g.n = &z->gg.g;
}

/* FUNC(zx_ps_AddCollectionResponse_DEL_Object) */

void zx_ps_AddCollectionResponse_DEL_Object(struct zx_ps_AddCollectionResponse_s* x, int n)
{
  struct zx_ps_Object_s* y;
  if (!x) return;
  switch (n) {
  case 0:
    x->Object = (struct zx_ps_Object_s*)x->Object->gg.g.n;
    return;
  case -1:
    y = (struct zx_ps_Object_s*)x->Object;
    if (!y) return;
    for (; y->gg.g.n; y = (struct zx_ps_Object_s*)y->gg.g.n) ;
    break;
  default:
    for (y = x->Object; n > 1 && y->gg.g.n; --n, y = (struct zx_ps_Object_s*)y->gg.g.n) ;
    if (!y->gg.g.n) return;
  }
  y->gg.g.n = y->gg.g.n->n;
}

#endif

/* FUNC(zx_ps_AddCollectionResponse_GET_TimeStamp) */
struct zx_str* zx_ps_AddCollectionResponse_GET_TimeStamp(struct zx_ps_AddCollectionResponse_s* x) { return x->TimeStamp; }
/* FUNC(zx_ps_AddCollectionResponse_PUT_TimeStamp) */
void zx_ps_AddCollectionResponse_PUT_TimeStamp(struct zx_ps_AddCollectionResponse_s* x, struct zx_str* y) { x->TimeStamp = y; }
/* FUNC(zx_ps_AddCollectionResponse_GET_id) */
struct zx_str* zx_ps_AddCollectionResponse_GET_id(struct zx_ps_AddCollectionResponse_s* x) { return x->id; }
/* FUNC(zx_ps_AddCollectionResponse_PUT_id) */
void zx_ps_AddCollectionResponse_PUT_id(struct zx_ps_AddCollectionResponse_s* x, struct zx_str* y) { x->id = y; }







#ifdef ZX_ENA_GETPUT

/* FUNC(zx_ps_AddEntityRequest_NUM_Object) */

int zx_ps_AddEntityRequest_NUM_Object(struct zx_ps_AddEntityRequest_s* x)
{
  struct zx_ps_Object_s* y;
  int n = 0;
  if (!x) return 0;
  for (y = x->Object; y; ++n, y = (struct zx_ps_Object_s*)y->gg.g.n) ;
  return n;
}

/* FUNC(zx_ps_AddEntityRequest_GET_Object) */

struct zx_ps_Object_s* zx_ps_AddEntityRequest_GET_Object(struct zx_ps_AddEntityRequest_s* x, int n)
{
  struct zx_ps_Object_s* y;
  if (!x) return 0;
  for (y = x->Object; n>=0 && y; --n, y = (struct zx_ps_Object_s*)y->gg.g.n) ;
  return y;
}

/* FUNC(zx_ps_AddEntityRequest_POP_Object) */

struct zx_ps_Object_s* zx_ps_AddEntityRequest_POP_Object(struct zx_ps_AddEntityRequest_s* x)
{
  struct zx_ps_Object_s* y;
  if (!x) return 0;
  y = x->Object;
  if (y)
    x->Object = (struct zx_ps_Object_s*)y->gg.g.n;
  return y;
}

/* FUNC(zx_ps_AddEntityRequest_PUSH_Object) */

void zx_ps_AddEntityRequest_PUSH_Object(struct zx_ps_AddEntityRequest_s* x, struct zx_ps_Object_s* z)
{
  if (!x || !z) return;
  z->gg.g.n = &x->Object->gg.g;
  x->Object = z;
}

/* FUNC(zx_ps_AddEntityRequest_REV_Object) */

void zx_ps_AddEntityRequest_REV_Object(struct zx_ps_AddEntityRequest_s* x)
{
  struct zx_ps_Object_s* nxt;
  struct zx_ps_Object_s* y;
  if (!x) return;
  y = x->Object;
  if (!y) return;
  x->Object = 0;
  while (y) {
    nxt = (struct zx_ps_Object_s*)y->gg.g.n;
    y->gg.g.n = &x->Object->gg.g;
    x->Object = y;
    y = nxt;
  }
}

/* FUNC(zx_ps_AddEntityRequest_PUT_Object) */

void zx_ps_AddEntityRequest_PUT_Object(struct zx_ps_AddEntityRequest_s* x, int n, struct zx_ps_Object_s* z)
{
  struct zx_ps_Object_s* y;
  if (!x || !z) return;
  y = x->Object;
  if (!y) return;
  switch (n) {
  case 0:
    z->gg.g.n = y->gg.g.n;
    x->Object = z;
    return;
  default:
    for (; n > 1 && y->gg.g.n; --n, y = (struct zx_ps_Object_s*)y->gg.g.n) ;
    if (!y->gg.g.n) return;
    z->gg.g.n = y->gg.g.n->n;
    y->gg.g.n = &z->gg.g;
  }
}

/* FUNC(zx_ps_AddEntityRequest_ADD_Object) */

void zx_ps_AddEntityRequest_ADD_Object(struct zx_ps_AddEntityRequest_s* x, int n, struct zx_ps_Object_s* z)
{
  struct zx_ps_Object_s* y;
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
    for (; y->gg.g.n; y = (struct zx_ps_Object_s*)y->gg.g.n) ;
    break;
  default:
    for (y = x->Object; n > 1 && y; --n, y = (struct zx_ps_Object_s*)y->gg.g.n) ;
    if (!y) return;
  }
  z->gg.g.n = y->gg.g.n;
  y->gg.g.n = &z->gg.g;
}

/* FUNC(zx_ps_AddEntityRequest_DEL_Object) */

void zx_ps_AddEntityRequest_DEL_Object(struct zx_ps_AddEntityRequest_s* x, int n)
{
  struct zx_ps_Object_s* y;
  if (!x) return;
  switch (n) {
  case 0:
    x->Object = (struct zx_ps_Object_s*)x->Object->gg.g.n;
    return;
  case -1:
    y = (struct zx_ps_Object_s*)x->Object;
    if (!y) return;
    for (; y->gg.g.n; y = (struct zx_ps_Object_s*)y->gg.g.n) ;
    break;
  default:
    for (y = x->Object; n > 1 && y->gg.g.n; --n, y = (struct zx_ps_Object_s*)y->gg.g.n) ;
    if (!y->gg.g.n) return;
  }
  y->gg.g.n = y->gg.g.n->n;
}

#endif



#ifdef ZX_ENA_GETPUT

/* FUNC(zx_ps_AddEntityRequest_NUM_PStoSPRedirectURL) */

int zx_ps_AddEntityRequest_NUM_PStoSPRedirectURL(struct zx_ps_AddEntityRequest_s* x)
{
  struct zx_elem_s* y;
  int n = 0;
  if (!x) return 0;
  for (y = x->PStoSPRedirectURL; y; ++n, y = (struct zx_elem_s*)y->g.n) ;
  return n;
}

/* FUNC(zx_ps_AddEntityRequest_GET_PStoSPRedirectURL) */

struct zx_elem_s* zx_ps_AddEntityRequest_GET_PStoSPRedirectURL(struct zx_ps_AddEntityRequest_s* x, int n)
{
  struct zx_elem_s* y;
  if (!x) return 0;
  for (y = x->PStoSPRedirectURL; n>=0 && y; --n, y = (struct zx_elem_s*)y->g.n) ;
  return y;
}

/* FUNC(zx_ps_AddEntityRequest_POP_PStoSPRedirectURL) */

struct zx_elem_s* zx_ps_AddEntityRequest_POP_PStoSPRedirectURL(struct zx_ps_AddEntityRequest_s* x)
{
  struct zx_elem_s* y;
  if (!x) return 0;
  y = x->PStoSPRedirectURL;
  if (y)
    x->PStoSPRedirectURL = (struct zx_elem_s*)y->g.n;
  return y;
}

/* FUNC(zx_ps_AddEntityRequest_PUSH_PStoSPRedirectURL) */

void zx_ps_AddEntityRequest_PUSH_PStoSPRedirectURL(struct zx_ps_AddEntityRequest_s* x, struct zx_elem_s* z)
{
  if (!x || !z) return;
  z->g.n = &x->PStoSPRedirectURL->g;
  x->PStoSPRedirectURL = z;
}

/* FUNC(zx_ps_AddEntityRequest_REV_PStoSPRedirectURL) */

void zx_ps_AddEntityRequest_REV_PStoSPRedirectURL(struct zx_ps_AddEntityRequest_s* x)
{
  struct zx_elem_s* nxt;
  struct zx_elem_s* y;
  if (!x) return;
  y = x->PStoSPRedirectURL;
  if (!y) return;
  x->PStoSPRedirectURL = 0;
  while (y) {
    nxt = (struct zx_elem_s*)y->g.n;
    y->g.n = &x->PStoSPRedirectURL->g;
    x->PStoSPRedirectURL = y;
    y = nxt;
  }
}

/* FUNC(zx_ps_AddEntityRequest_PUT_PStoSPRedirectURL) */

void zx_ps_AddEntityRequest_PUT_PStoSPRedirectURL(struct zx_ps_AddEntityRequest_s* x, int n, struct zx_elem_s* z)
{
  struct zx_elem_s* y;
  if (!x || !z) return;
  y = x->PStoSPRedirectURL;
  if (!y) return;
  switch (n) {
  case 0:
    z->g.n = y->g.n;
    x->PStoSPRedirectURL = z;
    return;
  default:
    for (; n > 1 && y->g.n; --n, y = (struct zx_elem_s*)y->g.n) ;
    if (!y->g.n) return;
    z->g.n = y->g.n->n;
    y->g.n = &z->g;
  }
}

/* FUNC(zx_ps_AddEntityRequest_ADD_PStoSPRedirectURL) */

void zx_ps_AddEntityRequest_ADD_PStoSPRedirectURL(struct zx_ps_AddEntityRequest_s* x, int n, struct zx_elem_s* z)
{
  struct zx_elem_s* y;
  if (!x || !z) return;
  switch (n) {
  case 0:
  add_to_start:
    z->g.n = &x->PStoSPRedirectURL->g;
    x->PStoSPRedirectURL = z;
    return;
  case -1:
    y = x->PStoSPRedirectURL;
    if (!y) goto add_to_start;
    for (; y->g.n; y = (struct zx_elem_s*)y->g.n) ;
    break;
  default:
    for (y = x->PStoSPRedirectURL; n > 1 && y; --n, y = (struct zx_elem_s*)y->g.n) ;
    if (!y) return;
  }
  z->g.n = y->g.n;
  y->g.n = &z->g;
}

/* FUNC(zx_ps_AddEntityRequest_DEL_PStoSPRedirectURL) */

void zx_ps_AddEntityRequest_DEL_PStoSPRedirectURL(struct zx_ps_AddEntityRequest_s* x, int n)
{
  struct zx_elem_s* y;
  if (!x) return;
  switch (n) {
  case 0:
    x->PStoSPRedirectURL = (struct zx_elem_s*)x->PStoSPRedirectURL->g.n;
    return;
  case -1:
    y = (struct zx_elem_s*)x->PStoSPRedirectURL;
    if (!y) return;
    for (; y->g.n; y = (struct zx_elem_s*)y->g.n) ;
    break;
  default:
    for (y = x->PStoSPRedirectURL; n > 1 && y->g.n; --n, y = (struct zx_elem_s*)y->g.n) ;
    if (!y->g.n) return;
  }
  y->g.n = y->g.n->n;
}

#endif



#ifdef ZX_ENA_GETPUT

/* FUNC(zx_ps_AddEntityRequest_NUM_CreatePSObject) */

int zx_ps_AddEntityRequest_NUM_CreatePSObject(struct zx_ps_AddEntityRequest_s* x)
{
  struct zx_ps_CreatePSObject_s* y;
  int n = 0;
  if (!x) return 0;
  for (y = x->CreatePSObject; y; ++n, y = (struct zx_ps_CreatePSObject_s*)y->gg.g.n) ;
  return n;
}

/* FUNC(zx_ps_AddEntityRequest_GET_CreatePSObject) */

struct zx_ps_CreatePSObject_s* zx_ps_AddEntityRequest_GET_CreatePSObject(struct zx_ps_AddEntityRequest_s* x, int n)
{
  struct zx_ps_CreatePSObject_s* y;
  if (!x) return 0;
  for (y = x->CreatePSObject; n>=0 && y; --n, y = (struct zx_ps_CreatePSObject_s*)y->gg.g.n) ;
  return y;
}

/* FUNC(zx_ps_AddEntityRequest_POP_CreatePSObject) */

struct zx_ps_CreatePSObject_s* zx_ps_AddEntityRequest_POP_CreatePSObject(struct zx_ps_AddEntityRequest_s* x)
{
  struct zx_ps_CreatePSObject_s* y;
  if (!x) return 0;
  y = x->CreatePSObject;
  if (y)
    x->CreatePSObject = (struct zx_ps_CreatePSObject_s*)y->gg.g.n;
  return y;
}

/* FUNC(zx_ps_AddEntityRequest_PUSH_CreatePSObject) */

void zx_ps_AddEntityRequest_PUSH_CreatePSObject(struct zx_ps_AddEntityRequest_s* x, struct zx_ps_CreatePSObject_s* z)
{
  if (!x || !z) return;
  z->gg.g.n = &x->CreatePSObject->gg.g;
  x->CreatePSObject = z;
}

/* FUNC(zx_ps_AddEntityRequest_REV_CreatePSObject) */

void zx_ps_AddEntityRequest_REV_CreatePSObject(struct zx_ps_AddEntityRequest_s* x)
{
  struct zx_ps_CreatePSObject_s* nxt;
  struct zx_ps_CreatePSObject_s* y;
  if (!x) return;
  y = x->CreatePSObject;
  if (!y) return;
  x->CreatePSObject = 0;
  while (y) {
    nxt = (struct zx_ps_CreatePSObject_s*)y->gg.g.n;
    y->gg.g.n = &x->CreatePSObject->gg.g;
    x->CreatePSObject = y;
    y = nxt;
  }
}

/* FUNC(zx_ps_AddEntityRequest_PUT_CreatePSObject) */

void zx_ps_AddEntityRequest_PUT_CreatePSObject(struct zx_ps_AddEntityRequest_s* x, int n, struct zx_ps_CreatePSObject_s* z)
{
  struct zx_ps_CreatePSObject_s* y;
  if (!x || !z) return;
  y = x->CreatePSObject;
  if (!y) return;
  switch (n) {
  case 0:
    z->gg.g.n = y->gg.g.n;
    x->CreatePSObject = z;
    return;
  default:
    for (; n > 1 && y->gg.g.n; --n, y = (struct zx_ps_CreatePSObject_s*)y->gg.g.n) ;
    if (!y->gg.g.n) return;
    z->gg.g.n = y->gg.g.n->n;
    y->gg.g.n = &z->gg.g;
  }
}

/* FUNC(zx_ps_AddEntityRequest_ADD_CreatePSObject) */

void zx_ps_AddEntityRequest_ADD_CreatePSObject(struct zx_ps_AddEntityRequest_s* x, int n, struct zx_ps_CreatePSObject_s* z)
{
  struct zx_ps_CreatePSObject_s* y;
  if (!x || !z) return;
  switch (n) {
  case 0:
  add_to_start:
    z->gg.g.n = &x->CreatePSObject->gg.g;
    x->CreatePSObject = z;
    return;
  case -1:
    y = x->CreatePSObject;
    if (!y) goto add_to_start;
    for (; y->gg.g.n; y = (struct zx_ps_CreatePSObject_s*)y->gg.g.n) ;
    break;
  default:
    for (y = x->CreatePSObject; n > 1 && y; --n, y = (struct zx_ps_CreatePSObject_s*)y->gg.g.n) ;
    if (!y) return;
  }
  z->gg.g.n = y->gg.g.n;
  y->gg.g.n = &z->gg.g;
}

/* FUNC(zx_ps_AddEntityRequest_DEL_CreatePSObject) */

void zx_ps_AddEntityRequest_DEL_CreatePSObject(struct zx_ps_AddEntityRequest_s* x, int n)
{
  struct zx_ps_CreatePSObject_s* y;
  if (!x) return;
  switch (n) {
  case 0:
    x->CreatePSObject = (struct zx_ps_CreatePSObject_s*)x->CreatePSObject->gg.g.n;
    return;
  case -1:
    y = (struct zx_ps_CreatePSObject_s*)x->CreatePSObject;
    if (!y) return;
    for (; y->gg.g.n; y = (struct zx_ps_CreatePSObject_s*)y->gg.g.n) ;
    break;
  default:
    for (y = x->CreatePSObject; n > 1 && y->gg.g.n; --n, y = (struct zx_ps_CreatePSObject_s*)y->gg.g.n) ;
    if (!y->gg.g.n) return;
  }
  y->gg.g.n = y->gg.g.n->n;
}

#endif



#ifdef ZX_ENA_GETPUT

/* FUNC(zx_ps_AddEntityRequest_NUM_Subscription) */

int zx_ps_AddEntityRequest_NUM_Subscription(struct zx_ps_AddEntityRequest_s* x)
{
  struct zx_ps_Subscription_s* y;
  int n = 0;
  if (!x) return 0;
  for (y = x->Subscription; y; ++n, y = (struct zx_ps_Subscription_s*)y->gg.g.n) ;
  return n;
}

/* FUNC(zx_ps_AddEntityRequest_GET_Subscription) */

struct zx_ps_Subscription_s* zx_ps_AddEntityRequest_GET_Subscription(struct zx_ps_AddEntityRequest_s* x, int n)
{
  struct zx_ps_Subscription_s* y;
  if (!x) return 0;
  for (y = x->Subscription; n>=0 && y; --n, y = (struct zx_ps_Subscription_s*)y->gg.g.n) ;
  return y;
}

/* FUNC(zx_ps_AddEntityRequest_POP_Subscription) */

struct zx_ps_Subscription_s* zx_ps_AddEntityRequest_POP_Subscription(struct zx_ps_AddEntityRequest_s* x)
{
  struct zx_ps_Subscription_s* y;
  if (!x) return 0;
  y = x->Subscription;
  if (y)
    x->Subscription = (struct zx_ps_Subscription_s*)y->gg.g.n;
  return y;
}

/* FUNC(zx_ps_AddEntityRequest_PUSH_Subscription) */

void zx_ps_AddEntityRequest_PUSH_Subscription(struct zx_ps_AddEntityRequest_s* x, struct zx_ps_Subscription_s* z)
{
  if (!x || !z) return;
  z->gg.g.n = &x->Subscription->gg.g;
  x->Subscription = z;
}

/* FUNC(zx_ps_AddEntityRequest_REV_Subscription) */

void zx_ps_AddEntityRequest_REV_Subscription(struct zx_ps_AddEntityRequest_s* x)
{
  struct zx_ps_Subscription_s* nxt;
  struct zx_ps_Subscription_s* y;
  if (!x) return;
  y = x->Subscription;
  if (!y) return;
  x->Subscription = 0;
  while (y) {
    nxt = (struct zx_ps_Subscription_s*)y->gg.g.n;
    y->gg.g.n = &x->Subscription->gg.g;
    x->Subscription = y;
    y = nxt;
  }
}

/* FUNC(zx_ps_AddEntityRequest_PUT_Subscription) */

void zx_ps_AddEntityRequest_PUT_Subscription(struct zx_ps_AddEntityRequest_s* x, int n, struct zx_ps_Subscription_s* z)
{
  struct zx_ps_Subscription_s* y;
  if (!x || !z) return;
  y = x->Subscription;
  if (!y) return;
  switch (n) {
  case 0:
    z->gg.g.n = y->gg.g.n;
    x->Subscription = z;
    return;
  default:
    for (; n > 1 && y->gg.g.n; --n, y = (struct zx_ps_Subscription_s*)y->gg.g.n) ;
    if (!y->gg.g.n) return;
    z->gg.g.n = y->gg.g.n->n;
    y->gg.g.n = &z->gg.g;
  }
}

/* FUNC(zx_ps_AddEntityRequest_ADD_Subscription) */

void zx_ps_AddEntityRequest_ADD_Subscription(struct zx_ps_AddEntityRequest_s* x, int n, struct zx_ps_Subscription_s* z)
{
  struct zx_ps_Subscription_s* y;
  if (!x || !z) return;
  switch (n) {
  case 0:
  add_to_start:
    z->gg.g.n = &x->Subscription->gg.g;
    x->Subscription = z;
    return;
  case -1:
    y = x->Subscription;
    if (!y) goto add_to_start;
    for (; y->gg.g.n; y = (struct zx_ps_Subscription_s*)y->gg.g.n) ;
    break;
  default:
    for (y = x->Subscription; n > 1 && y; --n, y = (struct zx_ps_Subscription_s*)y->gg.g.n) ;
    if (!y) return;
  }
  z->gg.g.n = y->gg.g.n;
  y->gg.g.n = &z->gg.g;
}

/* FUNC(zx_ps_AddEntityRequest_DEL_Subscription) */

void zx_ps_AddEntityRequest_DEL_Subscription(struct zx_ps_AddEntityRequest_s* x, int n)
{
  struct zx_ps_Subscription_s* y;
  if (!x) return;
  switch (n) {
  case 0:
    x->Subscription = (struct zx_ps_Subscription_s*)x->Subscription->gg.g.n;
    return;
  case -1:
    y = (struct zx_ps_Subscription_s*)x->Subscription;
    if (!y) return;
    for (; y->gg.g.n; y = (struct zx_ps_Subscription_s*)y->gg.g.n) ;
    break;
  default:
    for (y = x->Subscription; n > 1 && y->gg.g.n; --n, y = (struct zx_ps_Subscription_s*)y->gg.g.n) ;
    if (!y->gg.g.n) return;
  }
  y->gg.g.n = y->gg.g.n->n;
}

#endif



#ifdef ZX_ENA_GETPUT

/* FUNC(zx_ps_AddEntityRequest_NUM_TokenPolicy) */

int zx_ps_AddEntityRequest_NUM_TokenPolicy(struct zx_ps_AddEntityRequest_s* x)
{
  struct zx_sec_TokenPolicy_s* y;
  int n = 0;
  if (!x) return 0;
  for (y = x->TokenPolicy; y; ++n, y = (struct zx_sec_TokenPolicy_s*)y->gg.g.n) ;
  return n;
}

/* FUNC(zx_ps_AddEntityRequest_GET_TokenPolicy) */

struct zx_sec_TokenPolicy_s* zx_ps_AddEntityRequest_GET_TokenPolicy(struct zx_ps_AddEntityRequest_s* x, int n)
{
  struct zx_sec_TokenPolicy_s* y;
  if (!x) return 0;
  for (y = x->TokenPolicy; n>=0 && y; --n, y = (struct zx_sec_TokenPolicy_s*)y->gg.g.n) ;
  return y;
}

/* FUNC(zx_ps_AddEntityRequest_POP_TokenPolicy) */

struct zx_sec_TokenPolicy_s* zx_ps_AddEntityRequest_POP_TokenPolicy(struct zx_ps_AddEntityRequest_s* x)
{
  struct zx_sec_TokenPolicy_s* y;
  if (!x) return 0;
  y = x->TokenPolicy;
  if (y)
    x->TokenPolicy = (struct zx_sec_TokenPolicy_s*)y->gg.g.n;
  return y;
}

/* FUNC(zx_ps_AddEntityRequest_PUSH_TokenPolicy) */

void zx_ps_AddEntityRequest_PUSH_TokenPolicy(struct zx_ps_AddEntityRequest_s* x, struct zx_sec_TokenPolicy_s* z)
{
  if (!x || !z) return;
  z->gg.g.n = &x->TokenPolicy->gg.g;
  x->TokenPolicy = z;
}

/* FUNC(zx_ps_AddEntityRequest_REV_TokenPolicy) */

void zx_ps_AddEntityRequest_REV_TokenPolicy(struct zx_ps_AddEntityRequest_s* x)
{
  struct zx_sec_TokenPolicy_s* nxt;
  struct zx_sec_TokenPolicy_s* y;
  if (!x) return;
  y = x->TokenPolicy;
  if (!y) return;
  x->TokenPolicy = 0;
  while (y) {
    nxt = (struct zx_sec_TokenPolicy_s*)y->gg.g.n;
    y->gg.g.n = &x->TokenPolicy->gg.g;
    x->TokenPolicy = y;
    y = nxt;
  }
}

/* FUNC(zx_ps_AddEntityRequest_PUT_TokenPolicy) */

void zx_ps_AddEntityRequest_PUT_TokenPolicy(struct zx_ps_AddEntityRequest_s* x, int n, struct zx_sec_TokenPolicy_s* z)
{
  struct zx_sec_TokenPolicy_s* y;
  if (!x || !z) return;
  y = x->TokenPolicy;
  if (!y) return;
  switch (n) {
  case 0:
    z->gg.g.n = y->gg.g.n;
    x->TokenPolicy = z;
    return;
  default:
    for (; n > 1 && y->gg.g.n; --n, y = (struct zx_sec_TokenPolicy_s*)y->gg.g.n) ;
    if (!y->gg.g.n) return;
    z->gg.g.n = y->gg.g.n->n;
    y->gg.g.n = &z->gg.g;
  }
}

/* FUNC(zx_ps_AddEntityRequest_ADD_TokenPolicy) */

void zx_ps_AddEntityRequest_ADD_TokenPolicy(struct zx_ps_AddEntityRequest_s* x, int n, struct zx_sec_TokenPolicy_s* z)
{
  struct zx_sec_TokenPolicy_s* y;
  if (!x || !z) return;
  switch (n) {
  case 0:
  add_to_start:
    z->gg.g.n = &x->TokenPolicy->gg.g;
    x->TokenPolicy = z;
    return;
  case -1:
    y = x->TokenPolicy;
    if (!y) goto add_to_start;
    for (; y->gg.g.n; y = (struct zx_sec_TokenPolicy_s*)y->gg.g.n) ;
    break;
  default:
    for (y = x->TokenPolicy; n > 1 && y; --n, y = (struct zx_sec_TokenPolicy_s*)y->gg.g.n) ;
    if (!y) return;
  }
  z->gg.g.n = y->gg.g.n;
  y->gg.g.n = &z->gg.g;
}

/* FUNC(zx_ps_AddEntityRequest_DEL_TokenPolicy) */

void zx_ps_AddEntityRequest_DEL_TokenPolicy(struct zx_ps_AddEntityRequest_s* x, int n)
{
  struct zx_sec_TokenPolicy_s* y;
  if (!x) return;
  switch (n) {
  case 0:
    x->TokenPolicy = (struct zx_sec_TokenPolicy_s*)x->TokenPolicy->gg.g.n;
    return;
  case -1:
    y = (struct zx_sec_TokenPolicy_s*)x->TokenPolicy;
    if (!y) return;
    for (; y->gg.g.n; y = (struct zx_sec_TokenPolicy_s*)y->gg.g.n) ;
    break;
  default:
    for (y = x->TokenPolicy; n > 1 && y->gg.g.n; --n, y = (struct zx_sec_TokenPolicy_s*)y->gg.g.n) ;
    if (!y->gg.g.n) return;
  }
  y->gg.g.n = y->gg.g.n->n;
}

#endif

/* FUNC(zx_ps_AddEntityRequest_GET_id) */
struct zx_str* zx_ps_AddEntityRequest_GET_id(struct zx_ps_AddEntityRequest_s* x) { return x->id; }
/* FUNC(zx_ps_AddEntityRequest_PUT_id) */
void zx_ps_AddEntityRequest_PUT_id(struct zx_ps_AddEntityRequest_s* x, struct zx_str* y) { x->id = y; }







#ifdef ZX_ENA_GETPUT

/* FUNC(zx_ps_AddEntityResponse_NUM_Status) */

int zx_ps_AddEntityResponse_NUM_Status(struct zx_ps_AddEntityResponse_s* x)
{
  struct zx_lu_Status_s* y;
  int n = 0;
  if (!x) return 0;
  for (y = x->Status; y; ++n, y = (struct zx_lu_Status_s*)y->gg.g.n) ;
  return n;
}

/* FUNC(zx_ps_AddEntityResponse_GET_Status) */

struct zx_lu_Status_s* zx_ps_AddEntityResponse_GET_Status(struct zx_ps_AddEntityResponse_s* x, int n)
{
  struct zx_lu_Status_s* y;
  if (!x) return 0;
  for (y = x->Status; n>=0 && y; --n, y = (struct zx_lu_Status_s*)y->gg.g.n) ;
  return y;
}

/* FUNC(zx_ps_AddEntityResponse_POP_Status) */

struct zx_lu_Status_s* zx_ps_AddEntityResponse_POP_Status(struct zx_ps_AddEntityResponse_s* x)
{
  struct zx_lu_Status_s* y;
  if (!x) return 0;
  y = x->Status;
  if (y)
    x->Status = (struct zx_lu_Status_s*)y->gg.g.n;
  return y;
}

/* FUNC(zx_ps_AddEntityResponse_PUSH_Status) */

void zx_ps_AddEntityResponse_PUSH_Status(struct zx_ps_AddEntityResponse_s* x, struct zx_lu_Status_s* z)
{
  if (!x || !z) return;
  z->gg.g.n = &x->Status->gg.g;
  x->Status = z;
}

/* FUNC(zx_ps_AddEntityResponse_REV_Status) */

void zx_ps_AddEntityResponse_REV_Status(struct zx_ps_AddEntityResponse_s* x)
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

/* FUNC(zx_ps_AddEntityResponse_PUT_Status) */

void zx_ps_AddEntityResponse_PUT_Status(struct zx_ps_AddEntityResponse_s* x, int n, struct zx_lu_Status_s* z)
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

/* FUNC(zx_ps_AddEntityResponse_ADD_Status) */

void zx_ps_AddEntityResponse_ADD_Status(struct zx_ps_AddEntityResponse_s* x, int n, struct zx_lu_Status_s* z)
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

/* FUNC(zx_ps_AddEntityResponse_DEL_Status) */

void zx_ps_AddEntityResponse_DEL_Status(struct zx_ps_AddEntityResponse_s* x, int n)
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



#ifdef ZX_ENA_GETPUT

/* FUNC(zx_ps_AddEntityResponse_NUM_Object) */

int zx_ps_AddEntityResponse_NUM_Object(struct zx_ps_AddEntityResponse_s* x)
{
  struct zx_ps_Object_s* y;
  int n = 0;
  if (!x) return 0;
  for (y = x->Object; y; ++n, y = (struct zx_ps_Object_s*)y->gg.g.n) ;
  return n;
}

/* FUNC(zx_ps_AddEntityResponse_GET_Object) */

struct zx_ps_Object_s* zx_ps_AddEntityResponse_GET_Object(struct zx_ps_AddEntityResponse_s* x, int n)
{
  struct zx_ps_Object_s* y;
  if (!x) return 0;
  for (y = x->Object; n>=0 && y; --n, y = (struct zx_ps_Object_s*)y->gg.g.n) ;
  return y;
}

/* FUNC(zx_ps_AddEntityResponse_POP_Object) */

struct zx_ps_Object_s* zx_ps_AddEntityResponse_POP_Object(struct zx_ps_AddEntityResponse_s* x)
{
  struct zx_ps_Object_s* y;
  if (!x) return 0;
  y = x->Object;
  if (y)
    x->Object = (struct zx_ps_Object_s*)y->gg.g.n;
  return y;
}

/* FUNC(zx_ps_AddEntityResponse_PUSH_Object) */

void zx_ps_AddEntityResponse_PUSH_Object(struct zx_ps_AddEntityResponse_s* x, struct zx_ps_Object_s* z)
{
  if (!x || !z) return;
  z->gg.g.n = &x->Object->gg.g;
  x->Object = z;
}

/* FUNC(zx_ps_AddEntityResponse_REV_Object) */

void zx_ps_AddEntityResponse_REV_Object(struct zx_ps_AddEntityResponse_s* x)
{
  struct zx_ps_Object_s* nxt;
  struct zx_ps_Object_s* y;
  if (!x) return;
  y = x->Object;
  if (!y) return;
  x->Object = 0;
  while (y) {
    nxt = (struct zx_ps_Object_s*)y->gg.g.n;
    y->gg.g.n = &x->Object->gg.g;
    x->Object = y;
    y = nxt;
  }
}

/* FUNC(zx_ps_AddEntityResponse_PUT_Object) */

void zx_ps_AddEntityResponse_PUT_Object(struct zx_ps_AddEntityResponse_s* x, int n, struct zx_ps_Object_s* z)
{
  struct zx_ps_Object_s* y;
  if (!x || !z) return;
  y = x->Object;
  if (!y) return;
  switch (n) {
  case 0:
    z->gg.g.n = y->gg.g.n;
    x->Object = z;
    return;
  default:
    for (; n > 1 && y->gg.g.n; --n, y = (struct zx_ps_Object_s*)y->gg.g.n) ;
    if (!y->gg.g.n) return;
    z->gg.g.n = y->gg.g.n->n;
    y->gg.g.n = &z->gg.g;
  }
}

/* FUNC(zx_ps_AddEntityResponse_ADD_Object) */

void zx_ps_AddEntityResponse_ADD_Object(struct zx_ps_AddEntityResponse_s* x, int n, struct zx_ps_Object_s* z)
{
  struct zx_ps_Object_s* y;
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
    for (; y->gg.g.n; y = (struct zx_ps_Object_s*)y->gg.g.n) ;
    break;
  default:
    for (y = x->Object; n > 1 && y; --n, y = (struct zx_ps_Object_s*)y->gg.g.n) ;
    if (!y) return;
  }
  z->gg.g.n = y->gg.g.n;
  y->gg.g.n = &z->gg.g;
}

/* FUNC(zx_ps_AddEntityResponse_DEL_Object) */

void zx_ps_AddEntityResponse_DEL_Object(struct zx_ps_AddEntityResponse_s* x, int n)
{
  struct zx_ps_Object_s* y;
  if (!x) return;
  switch (n) {
  case 0:
    x->Object = (struct zx_ps_Object_s*)x->Object->gg.g.n;
    return;
  case -1:
    y = (struct zx_ps_Object_s*)x->Object;
    if (!y) return;
    for (; y->gg.g.n; y = (struct zx_ps_Object_s*)y->gg.g.n) ;
    break;
  default:
    for (y = x->Object; n > 1 && y->gg.g.n; --n, y = (struct zx_ps_Object_s*)y->gg.g.n) ;
    if (!y->gg.g.n) return;
  }
  y->gg.g.n = y->gg.g.n->n;
}

#endif



#ifdef ZX_ENA_GETPUT

/* FUNC(zx_ps_AddEntityResponse_NUM_SPtoPSRedirectURL) */

int zx_ps_AddEntityResponse_NUM_SPtoPSRedirectURL(struct zx_ps_AddEntityResponse_s* x)
{
  struct zx_elem_s* y;
  int n = 0;
  if (!x) return 0;
  for (y = x->SPtoPSRedirectURL; y; ++n, y = (struct zx_elem_s*)y->g.n) ;
  return n;
}

/* FUNC(zx_ps_AddEntityResponse_GET_SPtoPSRedirectURL) */

struct zx_elem_s* zx_ps_AddEntityResponse_GET_SPtoPSRedirectURL(struct zx_ps_AddEntityResponse_s* x, int n)
{
  struct zx_elem_s* y;
  if (!x) return 0;
  for (y = x->SPtoPSRedirectURL; n>=0 && y; --n, y = (struct zx_elem_s*)y->g.n) ;
  return y;
}

/* FUNC(zx_ps_AddEntityResponse_POP_SPtoPSRedirectURL) */

struct zx_elem_s* zx_ps_AddEntityResponse_POP_SPtoPSRedirectURL(struct zx_ps_AddEntityResponse_s* x)
{
  struct zx_elem_s* y;
  if (!x) return 0;
  y = x->SPtoPSRedirectURL;
  if (y)
    x->SPtoPSRedirectURL = (struct zx_elem_s*)y->g.n;
  return y;
}

/* FUNC(zx_ps_AddEntityResponse_PUSH_SPtoPSRedirectURL) */

void zx_ps_AddEntityResponse_PUSH_SPtoPSRedirectURL(struct zx_ps_AddEntityResponse_s* x, struct zx_elem_s* z)
{
  if (!x || !z) return;
  z->g.n = &x->SPtoPSRedirectURL->g;
  x->SPtoPSRedirectURL = z;
}

/* FUNC(zx_ps_AddEntityResponse_REV_SPtoPSRedirectURL) */

void zx_ps_AddEntityResponse_REV_SPtoPSRedirectURL(struct zx_ps_AddEntityResponse_s* x)
{
  struct zx_elem_s* nxt;
  struct zx_elem_s* y;
  if (!x) return;
  y = x->SPtoPSRedirectURL;
  if (!y) return;
  x->SPtoPSRedirectURL = 0;
  while (y) {
    nxt = (struct zx_elem_s*)y->g.n;
    y->g.n = &x->SPtoPSRedirectURL->g;
    x->SPtoPSRedirectURL = y;
    y = nxt;
  }
}

/* FUNC(zx_ps_AddEntityResponse_PUT_SPtoPSRedirectURL) */

void zx_ps_AddEntityResponse_PUT_SPtoPSRedirectURL(struct zx_ps_AddEntityResponse_s* x, int n, struct zx_elem_s* z)
{
  struct zx_elem_s* y;
  if (!x || !z) return;
  y = x->SPtoPSRedirectURL;
  if (!y) return;
  switch (n) {
  case 0:
    z->g.n = y->g.n;
    x->SPtoPSRedirectURL = z;
    return;
  default:
    for (; n > 1 && y->g.n; --n, y = (struct zx_elem_s*)y->g.n) ;
    if (!y->g.n) return;
    z->g.n = y->g.n->n;
    y->g.n = &z->g;
  }
}

/* FUNC(zx_ps_AddEntityResponse_ADD_SPtoPSRedirectURL) */

void zx_ps_AddEntityResponse_ADD_SPtoPSRedirectURL(struct zx_ps_AddEntityResponse_s* x, int n, struct zx_elem_s* z)
{
  struct zx_elem_s* y;
  if (!x || !z) return;
  switch (n) {
  case 0:
  add_to_start:
    z->g.n = &x->SPtoPSRedirectURL->g;
    x->SPtoPSRedirectURL = z;
    return;
  case -1:
    y = x->SPtoPSRedirectURL;
    if (!y) goto add_to_start;
    for (; y->g.n; y = (struct zx_elem_s*)y->g.n) ;
    break;
  default:
    for (y = x->SPtoPSRedirectURL; n > 1 && y; --n, y = (struct zx_elem_s*)y->g.n) ;
    if (!y) return;
  }
  z->g.n = y->g.n;
  y->g.n = &z->g;
}

/* FUNC(zx_ps_AddEntityResponse_DEL_SPtoPSRedirectURL) */

void zx_ps_AddEntityResponse_DEL_SPtoPSRedirectURL(struct zx_ps_AddEntityResponse_s* x, int n)
{
  struct zx_elem_s* y;
  if (!x) return;
  switch (n) {
  case 0:
    x->SPtoPSRedirectURL = (struct zx_elem_s*)x->SPtoPSRedirectURL->g.n;
    return;
  case -1:
    y = (struct zx_elem_s*)x->SPtoPSRedirectURL;
    if (!y) return;
    for (; y->g.n; y = (struct zx_elem_s*)y->g.n) ;
    break;
  default:
    for (y = x->SPtoPSRedirectURL; n > 1 && y->g.n; --n, y = (struct zx_elem_s*)y->g.n) ;
    if (!y->g.n) return;
  }
  y->g.n = y->g.n->n;
}

#endif



#ifdef ZX_ENA_GETPUT

/* FUNC(zx_ps_AddEntityResponse_NUM_QueryString) */

int zx_ps_AddEntityResponse_NUM_QueryString(struct zx_ps_AddEntityResponse_s* x)
{
  struct zx_elem_s* y;
  int n = 0;
  if (!x) return 0;
  for (y = x->QueryString; y; ++n, y = (struct zx_elem_s*)y->g.n) ;
  return n;
}

/* FUNC(zx_ps_AddEntityResponse_GET_QueryString) */

struct zx_elem_s* zx_ps_AddEntityResponse_GET_QueryString(struct zx_ps_AddEntityResponse_s* x, int n)
{
  struct zx_elem_s* y;
  if (!x) return 0;
  for (y = x->QueryString; n>=0 && y; --n, y = (struct zx_elem_s*)y->g.n) ;
  return y;
}

/* FUNC(zx_ps_AddEntityResponse_POP_QueryString) */

struct zx_elem_s* zx_ps_AddEntityResponse_POP_QueryString(struct zx_ps_AddEntityResponse_s* x)
{
  struct zx_elem_s* y;
  if (!x) return 0;
  y = x->QueryString;
  if (y)
    x->QueryString = (struct zx_elem_s*)y->g.n;
  return y;
}

/* FUNC(zx_ps_AddEntityResponse_PUSH_QueryString) */

void zx_ps_AddEntityResponse_PUSH_QueryString(struct zx_ps_AddEntityResponse_s* x, struct zx_elem_s* z)
{
  if (!x || !z) return;
  z->g.n = &x->QueryString->g;
  x->QueryString = z;
}

/* FUNC(zx_ps_AddEntityResponse_REV_QueryString) */

void zx_ps_AddEntityResponse_REV_QueryString(struct zx_ps_AddEntityResponse_s* x)
{
  struct zx_elem_s* nxt;
  struct zx_elem_s* y;
  if (!x) return;
  y = x->QueryString;
  if (!y) return;
  x->QueryString = 0;
  while (y) {
    nxt = (struct zx_elem_s*)y->g.n;
    y->g.n = &x->QueryString->g;
    x->QueryString = y;
    y = nxt;
  }
}

/* FUNC(zx_ps_AddEntityResponse_PUT_QueryString) */

void zx_ps_AddEntityResponse_PUT_QueryString(struct zx_ps_AddEntityResponse_s* x, int n, struct zx_elem_s* z)
{
  struct zx_elem_s* y;
  if (!x || !z) return;
  y = x->QueryString;
  if (!y) return;
  switch (n) {
  case 0:
    z->g.n = y->g.n;
    x->QueryString = z;
    return;
  default:
    for (; n > 1 && y->g.n; --n, y = (struct zx_elem_s*)y->g.n) ;
    if (!y->g.n) return;
    z->g.n = y->g.n->n;
    y->g.n = &z->g;
  }
}

/* FUNC(zx_ps_AddEntityResponse_ADD_QueryString) */

void zx_ps_AddEntityResponse_ADD_QueryString(struct zx_ps_AddEntityResponse_s* x, int n, struct zx_elem_s* z)
{
  struct zx_elem_s* y;
  if (!x || !z) return;
  switch (n) {
  case 0:
  add_to_start:
    z->g.n = &x->QueryString->g;
    x->QueryString = z;
    return;
  case -1:
    y = x->QueryString;
    if (!y) goto add_to_start;
    for (; y->g.n; y = (struct zx_elem_s*)y->g.n) ;
    break;
  default:
    for (y = x->QueryString; n > 1 && y; --n, y = (struct zx_elem_s*)y->g.n) ;
    if (!y) return;
  }
  z->g.n = y->g.n;
  y->g.n = &z->g;
}

/* FUNC(zx_ps_AddEntityResponse_DEL_QueryString) */

void zx_ps_AddEntityResponse_DEL_QueryString(struct zx_ps_AddEntityResponse_s* x, int n)
{
  struct zx_elem_s* y;
  if (!x) return;
  switch (n) {
  case 0:
    x->QueryString = (struct zx_elem_s*)x->QueryString->g.n;
    return;
  case -1:
    y = (struct zx_elem_s*)x->QueryString;
    if (!y) return;
    for (; y->g.n; y = (struct zx_elem_s*)y->g.n) ;
    break;
  default:
    for (y = x->QueryString; n > 1 && y->g.n; --n, y = (struct zx_elem_s*)y->g.n) ;
    if (!y->g.n) return;
  }
  y->g.n = y->g.n->n;
}

#endif

/* FUNC(zx_ps_AddEntityResponse_GET_TimeStamp) */
struct zx_str* zx_ps_AddEntityResponse_GET_TimeStamp(struct zx_ps_AddEntityResponse_s* x) { return x->TimeStamp; }
/* FUNC(zx_ps_AddEntityResponse_PUT_TimeStamp) */
void zx_ps_AddEntityResponse_PUT_TimeStamp(struct zx_ps_AddEntityResponse_s* x, struct zx_str* y) { x->TimeStamp = y; }
/* FUNC(zx_ps_AddEntityResponse_GET_id) */
struct zx_str* zx_ps_AddEntityResponse_GET_id(struct zx_ps_AddEntityResponse_s* x) { return x->id; }
/* FUNC(zx_ps_AddEntityResponse_PUT_id) */
void zx_ps_AddEntityResponse_PUT_id(struct zx_ps_AddEntityResponse_s* x, struct zx_str* y) { x->id = y; }







#ifdef ZX_ENA_GETPUT

/* FUNC(zx_ps_AddKnownEntityRequest_NUM_Object) */

int zx_ps_AddKnownEntityRequest_NUM_Object(struct zx_ps_AddKnownEntityRequest_s* x)
{
  struct zx_ps_Object_s* y;
  int n = 0;
  if (!x) return 0;
  for (y = x->Object; y; ++n, y = (struct zx_ps_Object_s*)y->gg.g.n) ;
  return n;
}

/* FUNC(zx_ps_AddKnownEntityRequest_GET_Object) */

struct zx_ps_Object_s* zx_ps_AddKnownEntityRequest_GET_Object(struct zx_ps_AddKnownEntityRequest_s* x, int n)
{
  struct zx_ps_Object_s* y;
  if (!x) return 0;
  for (y = x->Object; n>=0 && y; --n, y = (struct zx_ps_Object_s*)y->gg.g.n) ;
  return y;
}

/* FUNC(zx_ps_AddKnownEntityRequest_POP_Object) */

struct zx_ps_Object_s* zx_ps_AddKnownEntityRequest_POP_Object(struct zx_ps_AddKnownEntityRequest_s* x)
{
  struct zx_ps_Object_s* y;
  if (!x) return 0;
  y = x->Object;
  if (y)
    x->Object = (struct zx_ps_Object_s*)y->gg.g.n;
  return y;
}

/* FUNC(zx_ps_AddKnownEntityRequest_PUSH_Object) */

void zx_ps_AddKnownEntityRequest_PUSH_Object(struct zx_ps_AddKnownEntityRequest_s* x, struct zx_ps_Object_s* z)
{
  if (!x || !z) return;
  z->gg.g.n = &x->Object->gg.g;
  x->Object = z;
}

/* FUNC(zx_ps_AddKnownEntityRequest_REV_Object) */

void zx_ps_AddKnownEntityRequest_REV_Object(struct zx_ps_AddKnownEntityRequest_s* x)
{
  struct zx_ps_Object_s* nxt;
  struct zx_ps_Object_s* y;
  if (!x) return;
  y = x->Object;
  if (!y) return;
  x->Object = 0;
  while (y) {
    nxt = (struct zx_ps_Object_s*)y->gg.g.n;
    y->gg.g.n = &x->Object->gg.g;
    x->Object = y;
    y = nxt;
  }
}

/* FUNC(zx_ps_AddKnownEntityRequest_PUT_Object) */

void zx_ps_AddKnownEntityRequest_PUT_Object(struct zx_ps_AddKnownEntityRequest_s* x, int n, struct zx_ps_Object_s* z)
{
  struct zx_ps_Object_s* y;
  if (!x || !z) return;
  y = x->Object;
  if (!y) return;
  switch (n) {
  case 0:
    z->gg.g.n = y->gg.g.n;
    x->Object = z;
    return;
  default:
    for (; n > 1 && y->gg.g.n; --n, y = (struct zx_ps_Object_s*)y->gg.g.n) ;
    if (!y->gg.g.n) return;
    z->gg.g.n = y->gg.g.n->n;
    y->gg.g.n = &z->gg.g;
  }
}

/* FUNC(zx_ps_AddKnownEntityRequest_ADD_Object) */

void zx_ps_AddKnownEntityRequest_ADD_Object(struct zx_ps_AddKnownEntityRequest_s* x, int n, struct zx_ps_Object_s* z)
{
  struct zx_ps_Object_s* y;
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
    for (; y->gg.g.n; y = (struct zx_ps_Object_s*)y->gg.g.n) ;
    break;
  default:
    for (y = x->Object; n > 1 && y; --n, y = (struct zx_ps_Object_s*)y->gg.g.n) ;
    if (!y) return;
  }
  z->gg.g.n = y->gg.g.n;
  y->gg.g.n = &z->gg.g;
}

/* FUNC(zx_ps_AddKnownEntityRequest_DEL_Object) */

void zx_ps_AddKnownEntityRequest_DEL_Object(struct zx_ps_AddKnownEntityRequest_s* x, int n)
{
  struct zx_ps_Object_s* y;
  if (!x) return;
  switch (n) {
  case 0:
    x->Object = (struct zx_ps_Object_s*)x->Object->gg.g.n;
    return;
  case -1:
    y = (struct zx_ps_Object_s*)x->Object;
    if (!y) return;
    for (; y->gg.g.n; y = (struct zx_ps_Object_s*)y->gg.g.n) ;
    break;
  default:
    for (y = x->Object; n > 1 && y->gg.g.n; --n, y = (struct zx_ps_Object_s*)y->gg.g.n) ;
    if (!y->gg.g.n) return;
  }
  y->gg.g.n = y->gg.g.n->n;
}

#endif



#ifdef ZX_ENA_GETPUT

/* FUNC(zx_ps_AddKnownEntityRequest_NUM_Token) */

int zx_ps_AddKnownEntityRequest_NUM_Token(struct zx_ps_AddKnownEntityRequest_s* x)
{
  struct zx_sec_Token_s* y;
  int n = 0;
  if (!x) return 0;
  for (y = x->Token; y; ++n, y = (struct zx_sec_Token_s*)y->gg.g.n) ;
  return n;
}

/* FUNC(zx_ps_AddKnownEntityRequest_GET_Token) */

struct zx_sec_Token_s* zx_ps_AddKnownEntityRequest_GET_Token(struct zx_ps_AddKnownEntityRequest_s* x, int n)
{
  struct zx_sec_Token_s* y;
  if (!x) return 0;
  for (y = x->Token; n>=0 && y; --n, y = (struct zx_sec_Token_s*)y->gg.g.n) ;
  return y;
}

/* FUNC(zx_ps_AddKnownEntityRequest_POP_Token) */

struct zx_sec_Token_s* zx_ps_AddKnownEntityRequest_POP_Token(struct zx_ps_AddKnownEntityRequest_s* x)
{
  struct zx_sec_Token_s* y;
  if (!x) return 0;
  y = x->Token;
  if (y)
    x->Token = (struct zx_sec_Token_s*)y->gg.g.n;
  return y;
}

/* FUNC(zx_ps_AddKnownEntityRequest_PUSH_Token) */

void zx_ps_AddKnownEntityRequest_PUSH_Token(struct zx_ps_AddKnownEntityRequest_s* x, struct zx_sec_Token_s* z)
{
  if (!x || !z) return;
  z->gg.g.n = &x->Token->gg.g;
  x->Token = z;
}

/* FUNC(zx_ps_AddKnownEntityRequest_REV_Token) */

void zx_ps_AddKnownEntityRequest_REV_Token(struct zx_ps_AddKnownEntityRequest_s* x)
{
  struct zx_sec_Token_s* nxt;
  struct zx_sec_Token_s* y;
  if (!x) return;
  y = x->Token;
  if (!y) return;
  x->Token = 0;
  while (y) {
    nxt = (struct zx_sec_Token_s*)y->gg.g.n;
    y->gg.g.n = &x->Token->gg.g;
    x->Token = y;
    y = nxt;
  }
}

/* FUNC(zx_ps_AddKnownEntityRequest_PUT_Token) */

void zx_ps_AddKnownEntityRequest_PUT_Token(struct zx_ps_AddKnownEntityRequest_s* x, int n, struct zx_sec_Token_s* z)
{
  struct zx_sec_Token_s* y;
  if (!x || !z) return;
  y = x->Token;
  if (!y) return;
  switch (n) {
  case 0:
    z->gg.g.n = y->gg.g.n;
    x->Token = z;
    return;
  default:
    for (; n > 1 && y->gg.g.n; --n, y = (struct zx_sec_Token_s*)y->gg.g.n) ;
    if (!y->gg.g.n) return;
    z->gg.g.n = y->gg.g.n->n;
    y->gg.g.n = &z->gg.g;
  }
}

/* FUNC(zx_ps_AddKnownEntityRequest_ADD_Token) */

void zx_ps_AddKnownEntityRequest_ADD_Token(struct zx_ps_AddKnownEntityRequest_s* x, int n, struct zx_sec_Token_s* z)
{
  struct zx_sec_Token_s* y;
  if (!x || !z) return;
  switch (n) {
  case 0:
  add_to_start:
    z->gg.g.n = &x->Token->gg.g;
    x->Token = z;
    return;
  case -1:
    y = x->Token;
    if (!y) goto add_to_start;
    for (; y->gg.g.n; y = (struct zx_sec_Token_s*)y->gg.g.n) ;
    break;
  default:
    for (y = x->Token; n > 1 && y; --n, y = (struct zx_sec_Token_s*)y->gg.g.n) ;
    if (!y) return;
  }
  z->gg.g.n = y->gg.g.n;
  y->gg.g.n = &z->gg.g;
}

/* FUNC(zx_ps_AddKnownEntityRequest_DEL_Token) */

void zx_ps_AddKnownEntityRequest_DEL_Token(struct zx_ps_AddKnownEntityRequest_s* x, int n)
{
  struct zx_sec_Token_s* y;
  if (!x) return;
  switch (n) {
  case 0:
    x->Token = (struct zx_sec_Token_s*)x->Token->gg.g.n;
    return;
  case -1:
    y = (struct zx_sec_Token_s*)x->Token;
    if (!y) return;
    for (; y->gg.g.n; y = (struct zx_sec_Token_s*)y->gg.g.n) ;
    break;
  default:
    for (y = x->Token; n > 1 && y->gg.g.n; --n, y = (struct zx_sec_Token_s*)y->gg.g.n) ;
    if (!y->gg.g.n) return;
  }
  y->gg.g.n = y->gg.g.n->n;
}

#endif



#ifdef ZX_ENA_GETPUT

/* FUNC(zx_ps_AddKnownEntityRequest_NUM_CreatePSObject) */

int zx_ps_AddKnownEntityRequest_NUM_CreatePSObject(struct zx_ps_AddKnownEntityRequest_s* x)
{
  struct zx_ps_CreatePSObject_s* y;
  int n = 0;
  if (!x) return 0;
  for (y = x->CreatePSObject; y; ++n, y = (struct zx_ps_CreatePSObject_s*)y->gg.g.n) ;
  return n;
}

/* FUNC(zx_ps_AddKnownEntityRequest_GET_CreatePSObject) */

struct zx_ps_CreatePSObject_s* zx_ps_AddKnownEntityRequest_GET_CreatePSObject(struct zx_ps_AddKnownEntityRequest_s* x, int n)
{
  struct zx_ps_CreatePSObject_s* y;
  if (!x) return 0;
  for (y = x->CreatePSObject; n>=0 && y; --n, y = (struct zx_ps_CreatePSObject_s*)y->gg.g.n) ;
  return y;
}

/* FUNC(zx_ps_AddKnownEntityRequest_POP_CreatePSObject) */

struct zx_ps_CreatePSObject_s* zx_ps_AddKnownEntityRequest_POP_CreatePSObject(struct zx_ps_AddKnownEntityRequest_s* x)
{
  struct zx_ps_CreatePSObject_s* y;
  if (!x) return 0;
  y = x->CreatePSObject;
  if (y)
    x->CreatePSObject = (struct zx_ps_CreatePSObject_s*)y->gg.g.n;
  return y;
}

/* FUNC(zx_ps_AddKnownEntityRequest_PUSH_CreatePSObject) */

void zx_ps_AddKnownEntityRequest_PUSH_CreatePSObject(struct zx_ps_AddKnownEntityRequest_s* x, struct zx_ps_CreatePSObject_s* z)
{
  if (!x || !z) return;
  z->gg.g.n = &x->CreatePSObject->gg.g;
  x->CreatePSObject = z;
}

/* FUNC(zx_ps_AddKnownEntityRequest_REV_CreatePSObject) */

void zx_ps_AddKnownEntityRequest_REV_CreatePSObject(struct zx_ps_AddKnownEntityRequest_s* x)
{
  struct zx_ps_CreatePSObject_s* nxt;
  struct zx_ps_CreatePSObject_s* y;
  if (!x) return;
  y = x->CreatePSObject;
  if (!y) return;
  x->CreatePSObject = 0;
  while (y) {
    nxt = (struct zx_ps_CreatePSObject_s*)y->gg.g.n;
    y->gg.g.n = &x->CreatePSObject->gg.g;
    x->CreatePSObject = y;
    y = nxt;
  }
}

/* FUNC(zx_ps_AddKnownEntityRequest_PUT_CreatePSObject) */

void zx_ps_AddKnownEntityRequest_PUT_CreatePSObject(struct zx_ps_AddKnownEntityRequest_s* x, int n, struct zx_ps_CreatePSObject_s* z)
{
  struct zx_ps_CreatePSObject_s* y;
  if (!x || !z) return;
  y = x->CreatePSObject;
  if (!y) return;
  switch (n) {
  case 0:
    z->gg.g.n = y->gg.g.n;
    x->CreatePSObject = z;
    return;
  default:
    for (; n > 1 && y->gg.g.n; --n, y = (struct zx_ps_CreatePSObject_s*)y->gg.g.n) ;
    if (!y->gg.g.n) return;
    z->gg.g.n = y->gg.g.n->n;
    y->gg.g.n = &z->gg.g;
  }
}

/* FUNC(zx_ps_AddKnownEntityRequest_ADD_CreatePSObject) */

void zx_ps_AddKnownEntityRequest_ADD_CreatePSObject(struct zx_ps_AddKnownEntityRequest_s* x, int n, struct zx_ps_CreatePSObject_s* z)
{
  struct zx_ps_CreatePSObject_s* y;
  if (!x || !z) return;
  switch (n) {
  case 0:
  add_to_start:
    z->gg.g.n = &x->CreatePSObject->gg.g;
    x->CreatePSObject = z;
    return;
  case -1:
    y = x->CreatePSObject;
    if (!y) goto add_to_start;
    for (; y->gg.g.n; y = (struct zx_ps_CreatePSObject_s*)y->gg.g.n) ;
    break;
  default:
    for (y = x->CreatePSObject; n > 1 && y; --n, y = (struct zx_ps_CreatePSObject_s*)y->gg.g.n) ;
    if (!y) return;
  }
  z->gg.g.n = y->gg.g.n;
  y->gg.g.n = &z->gg.g;
}

/* FUNC(zx_ps_AddKnownEntityRequest_DEL_CreatePSObject) */

void zx_ps_AddKnownEntityRequest_DEL_CreatePSObject(struct zx_ps_AddKnownEntityRequest_s* x, int n)
{
  struct zx_ps_CreatePSObject_s* y;
  if (!x) return;
  switch (n) {
  case 0:
    x->CreatePSObject = (struct zx_ps_CreatePSObject_s*)x->CreatePSObject->gg.g.n;
    return;
  case -1:
    y = (struct zx_ps_CreatePSObject_s*)x->CreatePSObject;
    if (!y) return;
    for (; y->gg.g.n; y = (struct zx_ps_CreatePSObject_s*)y->gg.g.n) ;
    break;
  default:
    for (y = x->CreatePSObject; n > 1 && y->gg.g.n; --n, y = (struct zx_ps_CreatePSObject_s*)y->gg.g.n) ;
    if (!y->gg.g.n) return;
  }
  y->gg.g.n = y->gg.g.n->n;
}

#endif



#ifdef ZX_ENA_GETPUT

/* FUNC(zx_ps_AddKnownEntityRequest_NUM_Subscription) */

int zx_ps_AddKnownEntityRequest_NUM_Subscription(struct zx_ps_AddKnownEntityRequest_s* x)
{
  struct zx_ps_Subscription_s* y;
  int n = 0;
  if (!x) return 0;
  for (y = x->Subscription; y; ++n, y = (struct zx_ps_Subscription_s*)y->gg.g.n) ;
  return n;
}

/* FUNC(zx_ps_AddKnownEntityRequest_GET_Subscription) */

struct zx_ps_Subscription_s* zx_ps_AddKnownEntityRequest_GET_Subscription(struct zx_ps_AddKnownEntityRequest_s* x, int n)
{
  struct zx_ps_Subscription_s* y;
  if (!x) return 0;
  for (y = x->Subscription; n>=0 && y; --n, y = (struct zx_ps_Subscription_s*)y->gg.g.n) ;
  return y;
}

/* FUNC(zx_ps_AddKnownEntityRequest_POP_Subscription) */

struct zx_ps_Subscription_s* zx_ps_AddKnownEntityRequest_POP_Subscription(struct zx_ps_AddKnownEntityRequest_s* x)
{
  struct zx_ps_Subscription_s* y;
  if (!x) return 0;
  y = x->Subscription;
  if (y)
    x->Subscription = (struct zx_ps_Subscription_s*)y->gg.g.n;
  return y;
}

/* FUNC(zx_ps_AddKnownEntityRequest_PUSH_Subscription) */

void zx_ps_AddKnownEntityRequest_PUSH_Subscription(struct zx_ps_AddKnownEntityRequest_s* x, struct zx_ps_Subscription_s* z)
{
  if (!x || !z) return;
  z->gg.g.n = &x->Subscription->gg.g;
  x->Subscription = z;
}

/* FUNC(zx_ps_AddKnownEntityRequest_REV_Subscription) */

void zx_ps_AddKnownEntityRequest_REV_Subscription(struct zx_ps_AddKnownEntityRequest_s* x)
{
  struct zx_ps_Subscription_s* nxt;
  struct zx_ps_Subscription_s* y;
  if (!x) return;
  y = x->Subscription;
  if (!y) return;
  x->Subscription = 0;
  while (y) {
    nxt = (struct zx_ps_Subscription_s*)y->gg.g.n;
    y->gg.g.n = &x->Subscription->gg.g;
    x->Subscription = y;
    y = nxt;
  }
}

/* FUNC(zx_ps_AddKnownEntityRequest_PUT_Subscription) */

void zx_ps_AddKnownEntityRequest_PUT_Subscription(struct zx_ps_AddKnownEntityRequest_s* x, int n, struct zx_ps_Subscription_s* z)
{
  struct zx_ps_Subscription_s* y;
  if (!x || !z) return;
  y = x->Subscription;
  if (!y) return;
  switch (n) {
  case 0:
    z->gg.g.n = y->gg.g.n;
    x->Subscription = z;
    return;
  default:
    for (; n > 1 && y->gg.g.n; --n, y = (struct zx_ps_Subscription_s*)y->gg.g.n) ;
    if (!y->gg.g.n) return;
    z->gg.g.n = y->gg.g.n->n;
    y->gg.g.n = &z->gg.g;
  }
}

/* FUNC(zx_ps_AddKnownEntityRequest_ADD_Subscription) */

void zx_ps_AddKnownEntityRequest_ADD_Subscription(struct zx_ps_AddKnownEntityRequest_s* x, int n, struct zx_ps_Subscription_s* z)
{
  struct zx_ps_Subscription_s* y;
  if (!x || !z) return;
  switch (n) {
  case 0:
  add_to_start:
    z->gg.g.n = &x->Subscription->gg.g;
    x->Subscription = z;
    return;
  case -1:
    y = x->Subscription;
    if (!y) goto add_to_start;
    for (; y->gg.g.n; y = (struct zx_ps_Subscription_s*)y->gg.g.n) ;
    break;
  default:
    for (y = x->Subscription; n > 1 && y; --n, y = (struct zx_ps_Subscription_s*)y->gg.g.n) ;
    if (!y) return;
  }
  z->gg.g.n = y->gg.g.n;
  y->gg.g.n = &z->gg.g;
}

/* FUNC(zx_ps_AddKnownEntityRequest_DEL_Subscription) */

void zx_ps_AddKnownEntityRequest_DEL_Subscription(struct zx_ps_AddKnownEntityRequest_s* x, int n)
{
  struct zx_ps_Subscription_s* y;
  if (!x) return;
  switch (n) {
  case 0:
    x->Subscription = (struct zx_ps_Subscription_s*)x->Subscription->gg.g.n;
    return;
  case -1:
    y = (struct zx_ps_Subscription_s*)x->Subscription;
    if (!y) return;
    for (; y->gg.g.n; y = (struct zx_ps_Subscription_s*)y->gg.g.n) ;
    break;
  default:
    for (y = x->Subscription; n > 1 && y->gg.g.n; --n, y = (struct zx_ps_Subscription_s*)y->gg.g.n) ;
    if (!y->gg.g.n) return;
  }
  y->gg.g.n = y->gg.g.n->n;
}

#endif



#ifdef ZX_ENA_GETPUT

/* FUNC(zx_ps_AddKnownEntityRequest_NUM_TokenPolicy) */

int zx_ps_AddKnownEntityRequest_NUM_TokenPolicy(struct zx_ps_AddKnownEntityRequest_s* x)
{
  struct zx_sec_TokenPolicy_s* y;
  int n = 0;
  if (!x) return 0;
  for (y = x->TokenPolicy; y; ++n, y = (struct zx_sec_TokenPolicy_s*)y->gg.g.n) ;
  return n;
}

/* FUNC(zx_ps_AddKnownEntityRequest_GET_TokenPolicy) */

struct zx_sec_TokenPolicy_s* zx_ps_AddKnownEntityRequest_GET_TokenPolicy(struct zx_ps_AddKnownEntityRequest_s* x, int n)
{
  struct zx_sec_TokenPolicy_s* y;
  if (!x) return 0;
  for (y = x->TokenPolicy; n>=0 && y; --n, y = (struct zx_sec_TokenPolicy_s*)y->gg.g.n) ;
  return y;
}

/* FUNC(zx_ps_AddKnownEntityRequest_POP_TokenPolicy) */

struct zx_sec_TokenPolicy_s* zx_ps_AddKnownEntityRequest_POP_TokenPolicy(struct zx_ps_AddKnownEntityRequest_s* x)
{
  struct zx_sec_TokenPolicy_s* y;
  if (!x) return 0;
  y = x->TokenPolicy;
  if (y)
    x->TokenPolicy = (struct zx_sec_TokenPolicy_s*)y->gg.g.n;
  return y;
}

/* FUNC(zx_ps_AddKnownEntityRequest_PUSH_TokenPolicy) */

void zx_ps_AddKnownEntityRequest_PUSH_TokenPolicy(struct zx_ps_AddKnownEntityRequest_s* x, struct zx_sec_TokenPolicy_s* z)
{
  if (!x || !z) return;
  z->gg.g.n = &x->TokenPolicy->gg.g;
  x->TokenPolicy = z;
}

/* FUNC(zx_ps_AddKnownEntityRequest_REV_TokenPolicy) */

void zx_ps_AddKnownEntityRequest_REV_TokenPolicy(struct zx_ps_AddKnownEntityRequest_s* x)
{
  struct zx_sec_TokenPolicy_s* nxt;
  struct zx_sec_TokenPolicy_s* y;
  if (!x) return;
  y = x->TokenPolicy;
  if (!y) return;
  x->TokenPolicy = 0;
  while (y) {
    nxt = (struct zx_sec_TokenPolicy_s*)y->gg.g.n;
    y->gg.g.n = &x->TokenPolicy->gg.g;
    x->TokenPolicy = y;
    y = nxt;
  }
}

/* FUNC(zx_ps_AddKnownEntityRequest_PUT_TokenPolicy) */

void zx_ps_AddKnownEntityRequest_PUT_TokenPolicy(struct zx_ps_AddKnownEntityRequest_s* x, int n, struct zx_sec_TokenPolicy_s* z)
{
  struct zx_sec_TokenPolicy_s* y;
  if (!x || !z) return;
  y = x->TokenPolicy;
  if (!y) return;
  switch (n) {
  case 0:
    z->gg.g.n = y->gg.g.n;
    x->TokenPolicy = z;
    return;
  default:
    for (; n > 1 && y->gg.g.n; --n, y = (struct zx_sec_TokenPolicy_s*)y->gg.g.n) ;
    if (!y->gg.g.n) return;
    z->gg.g.n = y->gg.g.n->n;
    y->gg.g.n = &z->gg.g;
  }
}

/* FUNC(zx_ps_AddKnownEntityRequest_ADD_TokenPolicy) */

void zx_ps_AddKnownEntityRequest_ADD_TokenPolicy(struct zx_ps_AddKnownEntityRequest_s* x, int n, struct zx_sec_TokenPolicy_s* z)
{
  struct zx_sec_TokenPolicy_s* y;
  if (!x || !z) return;
  switch (n) {
  case 0:
  add_to_start:
    z->gg.g.n = &x->TokenPolicy->gg.g;
    x->TokenPolicy = z;
    return;
  case -1:
    y = x->TokenPolicy;
    if (!y) goto add_to_start;
    for (; y->gg.g.n; y = (struct zx_sec_TokenPolicy_s*)y->gg.g.n) ;
    break;
  default:
    for (y = x->TokenPolicy; n > 1 && y; --n, y = (struct zx_sec_TokenPolicy_s*)y->gg.g.n) ;
    if (!y) return;
  }
  z->gg.g.n = y->gg.g.n;
  y->gg.g.n = &z->gg.g;
}

/* FUNC(zx_ps_AddKnownEntityRequest_DEL_TokenPolicy) */

void zx_ps_AddKnownEntityRequest_DEL_TokenPolicy(struct zx_ps_AddKnownEntityRequest_s* x, int n)
{
  struct zx_sec_TokenPolicy_s* y;
  if (!x) return;
  switch (n) {
  case 0:
    x->TokenPolicy = (struct zx_sec_TokenPolicy_s*)x->TokenPolicy->gg.g.n;
    return;
  case -1:
    y = (struct zx_sec_TokenPolicy_s*)x->TokenPolicy;
    if (!y) return;
    for (; y->gg.g.n; y = (struct zx_sec_TokenPolicy_s*)y->gg.g.n) ;
    break;
  default:
    for (y = x->TokenPolicy; n > 1 && y->gg.g.n; --n, y = (struct zx_sec_TokenPolicy_s*)y->gg.g.n) ;
    if (!y->gg.g.n) return;
  }
  y->gg.g.n = y->gg.g.n->n;
}

#endif

/* FUNC(zx_ps_AddKnownEntityRequest_GET_id) */
struct zx_str* zx_ps_AddKnownEntityRequest_GET_id(struct zx_ps_AddKnownEntityRequest_s* x) { return x->id; }
/* FUNC(zx_ps_AddKnownEntityRequest_PUT_id) */
void zx_ps_AddKnownEntityRequest_PUT_id(struct zx_ps_AddKnownEntityRequest_s* x, struct zx_str* y) { x->id = y; }







#ifdef ZX_ENA_GETPUT

/* FUNC(zx_ps_AddKnownEntityResponse_NUM_Status) */

int zx_ps_AddKnownEntityResponse_NUM_Status(struct zx_ps_AddKnownEntityResponse_s* x)
{
  struct zx_lu_Status_s* y;
  int n = 0;
  if (!x) return 0;
  for (y = x->Status; y; ++n, y = (struct zx_lu_Status_s*)y->gg.g.n) ;
  return n;
}

/* FUNC(zx_ps_AddKnownEntityResponse_GET_Status) */

struct zx_lu_Status_s* zx_ps_AddKnownEntityResponse_GET_Status(struct zx_ps_AddKnownEntityResponse_s* x, int n)
{
  struct zx_lu_Status_s* y;
  if (!x) return 0;
  for (y = x->Status; n>=0 && y; --n, y = (struct zx_lu_Status_s*)y->gg.g.n) ;
  return y;
}

/* FUNC(zx_ps_AddKnownEntityResponse_POP_Status) */

struct zx_lu_Status_s* zx_ps_AddKnownEntityResponse_POP_Status(struct zx_ps_AddKnownEntityResponse_s* x)
{
  struct zx_lu_Status_s* y;
  if (!x) return 0;
  y = x->Status;
  if (y)
    x->Status = (struct zx_lu_Status_s*)y->gg.g.n;
  return y;
}

/* FUNC(zx_ps_AddKnownEntityResponse_PUSH_Status) */

void zx_ps_AddKnownEntityResponse_PUSH_Status(struct zx_ps_AddKnownEntityResponse_s* x, struct zx_lu_Status_s* z)
{
  if (!x || !z) return;
  z->gg.g.n = &x->Status->gg.g;
  x->Status = z;
}

/* FUNC(zx_ps_AddKnownEntityResponse_REV_Status) */

void zx_ps_AddKnownEntityResponse_REV_Status(struct zx_ps_AddKnownEntityResponse_s* x)
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

/* FUNC(zx_ps_AddKnownEntityResponse_PUT_Status) */

void zx_ps_AddKnownEntityResponse_PUT_Status(struct zx_ps_AddKnownEntityResponse_s* x, int n, struct zx_lu_Status_s* z)
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

/* FUNC(zx_ps_AddKnownEntityResponse_ADD_Status) */

void zx_ps_AddKnownEntityResponse_ADD_Status(struct zx_ps_AddKnownEntityResponse_s* x, int n, struct zx_lu_Status_s* z)
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

/* FUNC(zx_ps_AddKnownEntityResponse_DEL_Status) */

void zx_ps_AddKnownEntityResponse_DEL_Status(struct zx_ps_AddKnownEntityResponse_s* x, int n)
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



#ifdef ZX_ENA_GETPUT

/* FUNC(zx_ps_AddKnownEntityResponse_NUM_Object) */

int zx_ps_AddKnownEntityResponse_NUM_Object(struct zx_ps_AddKnownEntityResponse_s* x)
{
  struct zx_ps_Object_s* y;
  int n = 0;
  if (!x) return 0;
  for (y = x->Object; y; ++n, y = (struct zx_ps_Object_s*)y->gg.g.n) ;
  return n;
}

/* FUNC(zx_ps_AddKnownEntityResponse_GET_Object) */

struct zx_ps_Object_s* zx_ps_AddKnownEntityResponse_GET_Object(struct zx_ps_AddKnownEntityResponse_s* x, int n)
{
  struct zx_ps_Object_s* y;
  if (!x) return 0;
  for (y = x->Object; n>=0 && y; --n, y = (struct zx_ps_Object_s*)y->gg.g.n) ;
  return y;
}

/* FUNC(zx_ps_AddKnownEntityResponse_POP_Object) */

struct zx_ps_Object_s* zx_ps_AddKnownEntityResponse_POP_Object(struct zx_ps_AddKnownEntityResponse_s* x)
{
  struct zx_ps_Object_s* y;
  if (!x) return 0;
  y = x->Object;
  if (y)
    x->Object = (struct zx_ps_Object_s*)y->gg.g.n;
  return y;
}

/* FUNC(zx_ps_AddKnownEntityResponse_PUSH_Object) */

void zx_ps_AddKnownEntityResponse_PUSH_Object(struct zx_ps_AddKnownEntityResponse_s* x, struct zx_ps_Object_s* z)
{
  if (!x || !z) return;
  z->gg.g.n = &x->Object->gg.g;
  x->Object = z;
}

/* FUNC(zx_ps_AddKnownEntityResponse_REV_Object) */

void zx_ps_AddKnownEntityResponse_REV_Object(struct zx_ps_AddKnownEntityResponse_s* x)
{
  struct zx_ps_Object_s* nxt;
  struct zx_ps_Object_s* y;
  if (!x) return;
  y = x->Object;
  if (!y) return;
  x->Object = 0;
  while (y) {
    nxt = (struct zx_ps_Object_s*)y->gg.g.n;
    y->gg.g.n = &x->Object->gg.g;
    x->Object = y;
    y = nxt;
  }
}

/* FUNC(zx_ps_AddKnownEntityResponse_PUT_Object) */

void zx_ps_AddKnownEntityResponse_PUT_Object(struct zx_ps_AddKnownEntityResponse_s* x, int n, struct zx_ps_Object_s* z)
{
  struct zx_ps_Object_s* y;
  if (!x || !z) return;
  y = x->Object;
  if (!y) return;
  switch (n) {
  case 0:
    z->gg.g.n = y->gg.g.n;
    x->Object = z;
    return;
  default:
    for (; n > 1 && y->gg.g.n; --n, y = (struct zx_ps_Object_s*)y->gg.g.n) ;
    if (!y->gg.g.n) return;
    z->gg.g.n = y->gg.g.n->n;
    y->gg.g.n = &z->gg.g;
  }
}

/* FUNC(zx_ps_AddKnownEntityResponse_ADD_Object) */

void zx_ps_AddKnownEntityResponse_ADD_Object(struct zx_ps_AddKnownEntityResponse_s* x, int n, struct zx_ps_Object_s* z)
{
  struct zx_ps_Object_s* y;
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
    for (; y->gg.g.n; y = (struct zx_ps_Object_s*)y->gg.g.n) ;
    break;
  default:
    for (y = x->Object; n > 1 && y; --n, y = (struct zx_ps_Object_s*)y->gg.g.n) ;
    if (!y) return;
  }
  z->gg.g.n = y->gg.g.n;
  y->gg.g.n = &z->gg.g;
}

/* FUNC(zx_ps_AddKnownEntityResponse_DEL_Object) */

void zx_ps_AddKnownEntityResponse_DEL_Object(struct zx_ps_AddKnownEntityResponse_s* x, int n)
{
  struct zx_ps_Object_s* y;
  if (!x) return;
  switch (n) {
  case 0:
    x->Object = (struct zx_ps_Object_s*)x->Object->gg.g.n;
    return;
  case -1:
    y = (struct zx_ps_Object_s*)x->Object;
    if (!y) return;
    for (; y->gg.g.n; y = (struct zx_ps_Object_s*)y->gg.g.n) ;
    break;
  default:
    for (y = x->Object; n > 1 && y->gg.g.n; --n, y = (struct zx_ps_Object_s*)y->gg.g.n) ;
    if (!y->gg.g.n) return;
  }
  y->gg.g.n = y->gg.g.n->n;
}

#endif



#ifdef ZX_ENA_GETPUT

/* FUNC(zx_ps_AddKnownEntityResponse_NUM_SPtoPSRedirectURL) */

int zx_ps_AddKnownEntityResponse_NUM_SPtoPSRedirectURL(struct zx_ps_AddKnownEntityResponse_s* x)
{
  struct zx_elem_s* y;
  int n = 0;
  if (!x) return 0;
  for (y = x->SPtoPSRedirectURL; y; ++n, y = (struct zx_elem_s*)y->g.n) ;
  return n;
}

/* FUNC(zx_ps_AddKnownEntityResponse_GET_SPtoPSRedirectURL) */

struct zx_elem_s* zx_ps_AddKnownEntityResponse_GET_SPtoPSRedirectURL(struct zx_ps_AddKnownEntityResponse_s* x, int n)
{
  struct zx_elem_s* y;
  if (!x) return 0;
  for (y = x->SPtoPSRedirectURL; n>=0 && y; --n, y = (struct zx_elem_s*)y->g.n) ;
  return y;
}

/* FUNC(zx_ps_AddKnownEntityResponse_POP_SPtoPSRedirectURL) */

struct zx_elem_s* zx_ps_AddKnownEntityResponse_POP_SPtoPSRedirectURL(struct zx_ps_AddKnownEntityResponse_s* x)
{
  struct zx_elem_s* y;
  if (!x) return 0;
  y = x->SPtoPSRedirectURL;
  if (y)
    x->SPtoPSRedirectURL = (struct zx_elem_s*)y->g.n;
  return y;
}

/* FUNC(zx_ps_AddKnownEntityResponse_PUSH_SPtoPSRedirectURL) */

void zx_ps_AddKnownEntityResponse_PUSH_SPtoPSRedirectURL(struct zx_ps_AddKnownEntityResponse_s* x, struct zx_elem_s* z)
{
  if (!x || !z) return;
  z->g.n = &x->SPtoPSRedirectURL->g;
  x->SPtoPSRedirectURL = z;
}

/* FUNC(zx_ps_AddKnownEntityResponse_REV_SPtoPSRedirectURL) */

void zx_ps_AddKnownEntityResponse_REV_SPtoPSRedirectURL(struct zx_ps_AddKnownEntityResponse_s* x)
{
  struct zx_elem_s* nxt;
  struct zx_elem_s* y;
  if (!x) return;
  y = x->SPtoPSRedirectURL;
  if (!y) return;
  x->SPtoPSRedirectURL = 0;
  while (y) {
    nxt = (struct zx_elem_s*)y->g.n;
    y->g.n = &x->SPtoPSRedirectURL->g;
    x->SPtoPSRedirectURL = y;
    y = nxt;
  }
}

/* FUNC(zx_ps_AddKnownEntityResponse_PUT_SPtoPSRedirectURL) */

void zx_ps_AddKnownEntityResponse_PUT_SPtoPSRedirectURL(struct zx_ps_AddKnownEntityResponse_s* x, int n, struct zx_elem_s* z)
{
  struct zx_elem_s* y;
  if (!x || !z) return;
  y = x->SPtoPSRedirectURL;
  if (!y) return;
  switch (n) {
  case 0:
    z->g.n = y->g.n;
    x->SPtoPSRedirectURL = z;
    return;
  default:
    for (; n > 1 && y->g.n; --n, y = (struct zx_elem_s*)y->g.n) ;
    if (!y->g.n) return;
    z->g.n = y->g.n->n;
    y->g.n = &z->g;
  }
}

/* FUNC(zx_ps_AddKnownEntityResponse_ADD_SPtoPSRedirectURL) */

void zx_ps_AddKnownEntityResponse_ADD_SPtoPSRedirectURL(struct zx_ps_AddKnownEntityResponse_s* x, int n, struct zx_elem_s* z)
{
  struct zx_elem_s* y;
  if (!x || !z) return;
  switch (n) {
  case 0:
  add_to_start:
    z->g.n = &x->SPtoPSRedirectURL->g;
    x->SPtoPSRedirectURL = z;
    return;
  case -1:
    y = x->SPtoPSRedirectURL;
    if (!y) goto add_to_start;
    for (; y->g.n; y = (struct zx_elem_s*)y->g.n) ;
    break;
  default:
    for (y = x->SPtoPSRedirectURL; n > 1 && y; --n, y = (struct zx_elem_s*)y->g.n) ;
    if (!y) return;
  }
  z->g.n = y->g.n;
  y->g.n = &z->g;
}

/* FUNC(zx_ps_AddKnownEntityResponse_DEL_SPtoPSRedirectURL) */

void zx_ps_AddKnownEntityResponse_DEL_SPtoPSRedirectURL(struct zx_ps_AddKnownEntityResponse_s* x, int n)
{
  struct zx_elem_s* y;
  if (!x) return;
  switch (n) {
  case 0:
    x->SPtoPSRedirectURL = (struct zx_elem_s*)x->SPtoPSRedirectURL->g.n;
    return;
  case -1:
    y = (struct zx_elem_s*)x->SPtoPSRedirectURL;
    if (!y) return;
    for (; y->g.n; y = (struct zx_elem_s*)y->g.n) ;
    break;
  default:
    for (y = x->SPtoPSRedirectURL; n > 1 && y->g.n; --n, y = (struct zx_elem_s*)y->g.n) ;
    if (!y->g.n) return;
  }
  y->g.n = y->g.n->n;
}

#endif



#ifdef ZX_ENA_GETPUT

/* FUNC(zx_ps_AddKnownEntityResponse_NUM_QueryString) */

int zx_ps_AddKnownEntityResponse_NUM_QueryString(struct zx_ps_AddKnownEntityResponse_s* x)
{
  struct zx_elem_s* y;
  int n = 0;
  if (!x) return 0;
  for (y = x->QueryString; y; ++n, y = (struct zx_elem_s*)y->g.n) ;
  return n;
}

/* FUNC(zx_ps_AddKnownEntityResponse_GET_QueryString) */

struct zx_elem_s* zx_ps_AddKnownEntityResponse_GET_QueryString(struct zx_ps_AddKnownEntityResponse_s* x, int n)
{
  struct zx_elem_s* y;
  if (!x) return 0;
  for (y = x->QueryString; n>=0 && y; --n, y = (struct zx_elem_s*)y->g.n) ;
  return y;
}

/* FUNC(zx_ps_AddKnownEntityResponse_POP_QueryString) */

struct zx_elem_s* zx_ps_AddKnownEntityResponse_POP_QueryString(struct zx_ps_AddKnownEntityResponse_s* x)
{
  struct zx_elem_s* y;
  if (!x) return 0;
  y = x->QueryString;
  if (y)
    x->QueryString = (struct zx_elem_s*)y->g.n;
  return y;
}

/* FUNC(zx_ps_AddKnownEntityResponse_PUSH_QueryString) */

void zx_ps_AddKnownEntityResponse_PUSH_QueryString(struct zx_ps_AddKnownEntityResponse_s* x, struct zx_elem_s* z)
{
  if (!x || !z) return;
  z->g.n = &x->QueryString->g;
  x->QueryString = z;
}

/* FUNC(zx_ps_AddKnownEntityResponse_REV_QueryString) */

void zx_ps_AddKnownEntityResponse_REV_QueryString(struct zx_ps_AddKnownEntityResponse_s* x)
{
  struct zx_elem_s* nxt;
  struct zx_elem_s* y;
  if (!x) return;
  y = x->QueryString;
  if (!y) return;
  x->QueryString = 0;
  while (y) {
    nxt = (struct zx_elem_s*)y->g.n;
    y->g.n = &x->QueryString->g;
    x->QueryString = y;
    y = nxt;
  }
}

/* FUNC(zx_ps_AddKnownEntityResponse_PUT_QueryString) */

void zx_ps_AddKnownEntityResponse_PUT_QueryString(struct zx_ps_AddKnownEntityResponse_s* x, int n, struct zx_elem_s* z)
{
  struct zx_elem_s* y;
  if (!x || !z) return;
  y = x->QueryString;
  if (!y) return;
  switch (n) {
  case 0:
    z->g.n = y->g.n;
    x->QueryString = z;
    return;
  default:
    for (; n > 1 && y->g.n; --n, y = (struct zx_elem_s*)y->g.n) ;
    if (!y->g.n) return;
    z->g.n = y->g.n->n;
    y->g.n = &z->g;
  }
}

/* FUNC(zx_ps_AddKnownEntityResponse_ADD_QueryString) */

void zx_ps_AddKnownEntityResponse_ADD_QueryString(struct zx_ps_AddKnownEntityResponse_s* x, int n, struct zx_elem_s* z)
{
  struct zx_elem_s* y;
  if (!x || !z) return;
  switch (n) {
  case 0:
  add_to_start:
    z->g.n = &x->QueryString->g;
    x->QueryString = z;
    return;
  case -1:
    y = x->QueryString;
    if (!y) goto add_to_start;
    for (; y->g.n; y = (struct zx_elem_s*)y->g.n) ;
    break;
  default:
    for (y = x->QueryString; n > 1 && y; --n, y = (struct zx_elem_s*)y->g.n) ;
    if (!y) return;
  }
  z->g.n = y->g.n;
  y->g.n = &z->g;
}

/* FUNC(zx_ps_AddKnownEntityResponse_DEL_QueryString) */

void zx_ps_AddKnownEntityResponse_DEL_QueryString(struct zx_ps_AddKnownEntityResponse_s* x, int n)
{
  struct zx_elem_s* y;
  if (!x) return;
  switch (n) {
  case 0:
    x->QueryString = (struct zx_elem_s*)x->QueryString->g.n;
    return;
  case -1:
    y = (struct zx_elem_s*)x->QueryString;
    if (!y) return;
    for (; y->g.n; y = (struct zx_elem_s*)y->g.n) ;
    break;
  default:
    for (y = x->QueryString; n > 1 && y->g.n; --n, y = (struct zx_elem_s*)y->g.n) ;
    if (!y->g.n) return;
  }
  y->g.n = y->g.n->n;
}

#endif

/* FUNC(zx_ps_AddKnownEntityResponse_GET_TimeStamp) */
struct zx_str* zx_ps_AddKnownEntityResponse_GET_TimeStamp(struct zx_ps_AddKnownEntityResponse_s* x) { return x->TimeStamp; }
/* FUNC(zx_ps_AddKnownEntityResponse_PUT_TimeStamp) */
void zx_ps_AddKnownEntityResponse_PUT_TimeStamp(struct zx_ps_AddKnownEntityResponse_s* x, struct zx_str* y) { x->TimeStamp = y; }
/* FUNC(zx_ps_AddKnownEntityResponse_GET_id) */
struct zx_str* zx_ps_AddKnownEntityResponse_GET_id(struct zx_ps_AddKnownEntityResponse_s* x) { return x->id; }
/* FUNC(zx_ps_AddKnownEntityResponse_PUT_id) */
void zx_ps_AddKnownEntityResponse_PUT_id(struct zx_ps_AddKnownEntityResponse_s* x, struct zx_str* y) { x->id = y; }







#ifdef ZX_ENA_GETPUT

/* FUNC(zx_ps_AddToCollectionRequest_NUM_TargetObjectID) */

int zx_ps_AddToCollectionRequest_NUM_TargetObjectID(struct zx_ps_AddToCollectionRequest_s* x)
{
  struct zx_elem_s* y;
  int n = 0;
  if (!x) return 0;
  for (y = x->TargetObjectID; y; ++n, y = (struct zx_elem_s*)y->g.n) ;
  return n;
}

/* FUNC(zx_ps_AddToCollectionRequest_GET_TargetObjectID) */

struct zx_elem_s* zx_ps_AddToCollectionRequest_GET_TargetObjectID(struct zx_ps_AddToCollectionRequest_s* x, int n)
{
  struct zx_elem_s* y;
  if (!x) return 0;
  for (y = x->TargetObjectID; n>=0 && y; --n, y = (struct zx_elem_s*)y->g.n) ;
  return y;
}

/* FUNC(zx_ps_AddToCollectionRequest_POP_TargetObjectID) */

struct zx_elem_s* zx_ps_AddToCollectionRequest_POP_TargetObjectID(struct zx_ps_AddToCollectionRequest_s* x)
{
  struct zx_elem_s* y;
  if (!x) return 0;
  y = x->TargetObjectID;
  if (y)
    x->TargetObjectID = (struct zx_elem_s*)y->g.n;
  return y;
}

/* FUNC(zx_ps_AddToCollectionRequest_PUSH_TargetObjectID) */

void zx_ps_AddToCollectionRequest_PUSH_TargetObjectID(struct zx_ps_AddToCollectionRequest_s* x, struct zx_elem_s* z)
{
  if (!x || !z) return;
  z->g.n = &x->TargetObjectID->g;
  x->TargetObjectID = z;
}

/* FUNC(zx_ps_AddToCollectionRequest_REV_TargetObjectID) */

void zx_ps_AddToCollectionRequest_REV_TargetObjectID(struct zx_ps_AddToCollectionRequest_s* x)
{
  struct zx_elem_s* nxt;
  struct zx_elem_s* y;
  if (!x) return;
  y = x->TargetObjectID;
  if (!y) return;
  x->TargetObjectID = 0;
  while (y) {
    nxt = (struct zx_elem_s*)y->g.n;
    y->g.n = &x->TargetObjectID->g;
    x->TargetObjectID = y;
    y = nxt;
  }
}

/* FUNC(zx_ps_AddToCollectionRequest_PUT_TargetObjectID) */

void zx_ps_AddToCollectionRequest_PUT_TargetObjectID(struct zx_ps_AddToCollectionRequest_s* x, int n, struct zx_elem_s* z)
{
  struct zx_elem_s* y;
  if (!x || !z) return;
  y = x->TargetObjectID;
  if (!y) return;
  switch (n) {
  case 0:
    z->g.n = y->g.n;
    x->TargetObjectID = z;
    return;
  default:
    for (; n > 1 && y->g.n; --n, y = (struct zx_elem_s*)y->g.n) ;
    if (!y->g.n) return;
    z->g.n = y->g.n->n;
    y->g.n = &z->g;
  }
}

/* FUNC(zx_ps_AddToCollectionRequest_ADD_TargetObjectID) */

void zx_ps_AddToCollectionRequest_ADD_TargetObjectID(struct zx_ps_AddToCollectionRequest_s* x, int n, struct zx_elem_s* z)
{
  struct zx_elem_s* y;
  if (!x || !z) return;
  switch (n) {
  case 0:
  add_to_start:
    z->g.n = &x->TargetObjectID->g;
    x->TargetObjectID = z;
    return;
  case -1:
    y = x->TargetObjectID;
    if (!y) goto add_to_start;
    for (; y->g.n; y = (struct zx_elem_s*)y->g.n) ;
    break;
  default:
    for (y = x->TargetObjectID; n > 1 && y; --n, y = (struct zx_elem_s*)y->g.n) ;
    if (!y) return;
  }
  z->g.n = y->g.n;
  y->g.n = &z->g;
}

/* FUNC(zx_ps_AddToCollectionRequest_DEL_TargetObjectID) */

void zx_ps_AddToCollectionRequest_DEL_TargetObjectID(struct zx_ps_AddToCollectionRequest_s* x, int n)
{
  struct zx_elem_s* y;
  if (!x) return;
  switch (n) {
  case 0:
    x->TargetObjectID = (struct zx_elem_s*)x->TargetObjectID->g.n;
    return;
  case -1:
    y = (struct zx_elem_s*)x->TargetObjectID;
    if (!y) return;
    for (; y->g.n; y = (struct zx_elem_s*)y->g.n) ;
    break;
  default:
    for (y = x->TargetObjectID; n > 1 && y->g.n; --n, y = (struct zx_elem_s*)y->g.n) ;
    if (!y->g.n) return;
  }
  y->g.n = y->g.n->n;
}

#endif



#ifdef ZX_ENA_GETPUT

/* FUNC(zx_ps_AddToCollectionRequest_NUM_ObjectID) */

int zx_ps_AddToCollectionRequest_NUM_ObjectID(struct zx_ps_AddToCollectionRequest_s* x)
{
  struct zx_elem_s* y;
  int n = 0;
  if (!x) return 0;
  for (y = x->ObjectID; y; ++n, y = (struct zx_elem_s*)y->g.n) ;
  return n;
}

/* FUNC(zx_ps_AddToCollectionRequest_GET_ObjectID) */

struct zx_elem_s* zx_ps_AddToCollectionRequest_GET_ObjectID(struct zx_ps_AddToCollectionRequest_s* x, int n)
{
  struct zx_elem_s* y;
  if (!x) return 0;
  for (y = x->ObjectID; n>=0 && y; --n, y = (struct zx_elem_s*)y->g.n) ;
  return y;
}

/* FUNC(zx_ps_AddToCollectionRequest_POP_ObjectID) */

struct zx_elem_s* zx_ps_AddToCollectionRequest_POP_ObjectID(struct zx_ps_AddToCollectionRequest_s* x)
{
  struct zx_elem_s* y;
  if (!x) return 0;
  y = x->ObjectID;
  if (y)
    x->ObjectID = (struct zx_elem_s*)y->g.n;
  return y;
}

/* FUNC(zx_ps_AddToCollectionRequest_PUSH_ObjectID) */

void zx_ps_AddToCollectionRequest_PUSH_ObjectID(struct zx_ps_AddToCollectionRequest_s* x, struct zx_elem_s* z)
{
  if (!x || !z) return;
  z->g.n = &x->ObjectID->g;
  x->ObjectID = z;
}

/* FUNC(zx_ps_AddToCollectionRequest_REV_ObjectID) */

void zx_ps_AddToCollectionRequest_REV_ObjectID(struct zx_ps_AddToCollectionRequest_s* x)
{
  struct zx_elem_s* nxt;
  struct zx_elem_s* y;
  if (!x) return;
  y = x->ObjectID;
  if (!y) return;
  x->ObjectID = 0;
  while (y) {
    nxt = (struct zx_elem_s*)y->g.n;
    y->g.n = &x->ObjectID->g;
    x->ObjectID = y;
    y = nxt;
  }
}

/* FUNC(zx_ps_AddToCollectionRequest_PUT_ObjectID) */

void zx_ps_AddToCollectionRequest_PUT_ObjectID(struct zx_ps_AddToCollectionRequest_s* x, int n, struct zx_elem_s* z)
{
  struct zx_elem_s* y;
  if (!x || !z) return;
  y = x->ObjectID;
  if (!y) return;
  switch (n) {
  case 0:
    z->g.n = y->g.n;
    x->ObjectID = z;
    return;
  default:
    for (; n > 1 && y->g.n; --n, y = (struct zx_elem_s*)y->g.n) ;
    if (!y->g.n) return;
    z->g.n = y->g.n->n;
    y->g.n = &z->g;
  }
}

/* FUNC(zx_ps_AddToCollectionRequest_ADD_ObjectID) */

void zx_ps_AddToCollectionRequest_ADD_ObjectID(struct zx_ps_AddToCollectionRequest_s* x, int n, struct zx_elem_s* z)
{
  struct zx_elem_s* y;
  if (!x || !z) return;
  switch (n) {
  case 0:
  add_to_start:
    z->g.n = &x->ObjectID->g;
    x->ObjectID = z;
    return;
  case -1:
    y = x->ObjectID;
    if (!y) goto add_to_start;
    for (; y->g.n; y = (struct zx_elem_s*)y->g.n) ;
    break;
  default:
    for (y = x->ObjectID; n > 1 && y; --n, y = (struct zx_elem_s*)y->g.n) ;
    if (!y) return;
  }
  z->g.n = y->g.n;
  y->g.n = &z->g;
}

/* FUNC(zx_ps_AddToCollectionRequest_DEL_ObjectID) */

void zx_ps_AddToCollectionRequest_DEL_ObjectID(struct zx_ps_AddToCollectionRequest_s* x, int n)
{
  struct zx_elem_s* y;
  if (!x) return;
  switch (n) {
  case 0:
    x->ObjectID = (struct zx_elem_s*)x->ObjectID->g.n;
    return;
  case -1:
    y = (struct zx_elem_s*)x->ObjectID;
    if (!y) return;
    for (; y->g.n; y = (struct zx_elem_s*)y->g.n) ;
    break;
  default:
    for (y = x->ObjectID; n > 1 && y->g.n; --n, y = (struct zx_elem_s*)y->g.n) ;
    if (!y->g.n) return;
  }
  y->g.n = y->g.n->n;
}

#endif



#ifdef ZX_ENA_GETPUT

/* FUNC(zx_ps_AddToCollectionRequest_NUM_Subscription) */

int zx_ps_AddToCollectionRequest_NUM_Subscription(struct zx_ps_AddToCollectionRequest_s* x)
{
  struct zx_ps_Subscription_s* y;
  int n = 0;
  if (!x) return 0;
  for (y = x->Subscription; y; ++n, y = (struct zx_ps_Subscription_s*)y->gg.g.n) ;
  return n;
}

/* FUNC(zx_ps_AddToCollectionRequest_GET_Subscription) */

struct zx_ps_Subscription_s* zx_ps_AddToCollectionRequest_GET_Subscription(struct zx_ps_AddToCollectionRequest_s* x, int n)
{
  struct zx_ps_Subscription_s* y;
  if (!x) return 0;
  for (y = x->Subscription; n>=0 && y; --n, y = (struct zx_ps_Subscription_s*)y->gg.g.n) ;
  return y;
}

/* FUNC(zx_ps_AddToCollectionRequest_POP_Subscription) */

struct zx_ps_Subscription_s* zx_ps_AddToCollectionRequest_POP_Subscription(struct zx_ps_AddToCollectionRequest_s* x)
{
  struct zx_ps_Subscription_s* y;
  if (!x) return 0;
  y = x->Subscription;
  if (y)
    x->Subscription = (struct zx_ps_Subscription_s*)y->gg.g.n;
  return y;
}

/* FUNC(zx_ps_AddToCollectionRequest_PUSH_Subscription) */

void zx_ps_AddToCollectionRequest_PUSH_Subscription(struct zx_ps_AddToCollectionRequest_s* x, struct zx_ps_Subscription_s* z)
{
  if (!x || !z) return;
  z->gg.g.n = &x->Subscription->gg.g;
  x->Subscription = z;
}

/* FUNC(zx_ps_AddToCollectionRequest_REV_Subscription) */

void zx_ps_AddToCollectionRequest_REV_Subscription(struct zx_ps_AddToCollectionRequest_s* x)
{
  struct zx_ps_Subscription_s* nxt;
  struct zx_ps_Subscription_s* y;
  if (!x) return;
  y = x->Subscription;
  if (!y) return;
  x->Subscription = 0;
  while (y) {
    nxt = (struct zx_ps_Subscription_s*)y->gg.g.n;
    y->gg.g.n = &x->Subscription->gg.g;
    x->Subscription = y;
    y = nxt;
  }
}

/* FUNC(zx_ps_AddToCollectionRequest_PUT_Subscription) */

void zx_ps_AddToCollectionRequest_PUT_Subscription(struct zx_ps_AddToCollectionRequest_s* x, int n, struct zx_ps_Subscription_s* z)
{
  struct zx_ps_Subscription_s* y;
  if (!x || !z) return;
  y = x->Subscription;
  if (!y) return;
  switch (n) {
  case 0:
    z->gg.g.n = y->gg.g.n;
    x->Subscription = z;
    return;
  default:
    for (; n > 1 && y->gg.g.n; --n, y = (struct zx_ps_Subscription_s*)y->gg.g.n) ;
    if (!y->gg.g.n) return;
    z->gg.g.n = y->gg.g.n->n;
    y->gg.g.n = &z->gg.g;
  }
}

/* FUNC(zx_ps_AddToCollectionRequest_ADD_Subscription) */

void zx_ps_AddToCollectionRequest_ADD_Subscription(struct zx_ps_AddToCollectionRequest_s* x, int n, struct zx_ps_Subscription_s* z)
{
  struct zx_ps_Subscription_s* y;
  if (!x || !z) return;
  switch (n) {
  case 0:
  add_to_start:
    z->gg.g.n = &x->Subscription->gg.g;
    x->Subscription = z;
    return;
  case -1:
    y = x->Subscription;
    if (!y) goto add_to_start;
    for (; y->gg.g.n; y = (struct zx_ps_Subscription_s*)y->gg.g.n) ;
    break;
  default:
    for (y = x->Subscription; n > 1 && y; --n, y = (struct zx_ps_Subscription_s*)y->gg.g.n) ;
    if (!y) return;
  }
  z->gg.g.n = y->gg.g.n;
  y->gg.g.n = &z->gg.g;
}

/* FUNC(zx_ps_AddToCollectionRequest_DEL_Subscription) */

void zx_ps_AddToCollectionRequest_DEL_Subscription(struct zx_ps_AddToCollectionRequest_s* x, int n)
{
  struct zx_ps_Subscription_s* y;
  if (!x) return;
  switch (n) {
  case 0:
    x->Subscription = (struct zx_ps_Subscription_s*)x->Subscription->gg.g.n;
    return;
  case -1:
    y = (struct zx_ps_Subscription_s*)x->Subscription;
    if (!y) return;
    for (; y->gg.g.n; y = (struct zx_ps_Subscription_s*)y->gg.g.n) ;
    break;
  default:
    for (y = x->Subscription; n > 1 && y->gg.g.n; --n, y = (struct zx_ps_Subscription_s*)y->gg.g.n) ;
    if (!y->gg.g.n) return;
  }
  y->gg.g.n = y->gg.g.n->n;
}

#endif

/* FUNC(zx_ps_AddToCollectionRequest_GET_id) */
struct zx_str* zx_ps_AddToCollectionRequest_GET_id(struct zx_ps_AddToCollectionRequest_s* x) { return x->id; }
/* FUNC(zx_ps_AddToCollectionRequest_PUT_id) */
void zx_ps_AddToCollectionRequest_PUT_id(struct zx_ps_AddToCollectionRequest_s* x, struct zx_str* y) { x->id = y; }







#ifdef ZX_ENA_GETPUT

/* FUNC(zx_ps_AddToCollectionResponse_NUM_Status) */

int zx_ps_AddToCollectionResponse_NUM_Status(struct zx_ps_AddToCollectionResponse_s* x)
{
  struct zx_lu_Status_s* y;
  int n = 0;
  if (!x) return 0;
  for (y = x->Status; y; ++n, y = (struct zx_lu_Status_s*)y->gg.g.n) ;
  return n;
}

/* FUNC(zx_ps_AddToCollectionResponse_GET_Status) */

struct zx_lu_Status_s* zx_ps_AddToCollectionResponse_GET_Status(struct zx_ps_AddToCollectionResponse_s* x, int n)
{
  struct zx_lu_Status_s* y;
  if (!x) return 0;
  for (y = x->Status; n>=0 && y; --n, y = (struct zx_lu_Status_s*)y->gg.g.n) ;
  return y;
}

/* FUNC(zx_ps_AddToCollectionResponse_POP_Status) */

struct zx_lu_Status_s* zx_ps_AddToCollectionResponse_POP_Status(struct zx_ps_AddToCollectionResponse_s* x)
{
  struct zx_lu_Status_s* y;
  if (!x) return 0;
  y = x->Status;
  if (y)
    x->Status = (struct zx_lu_Status_s*)y->gg.g.n;
  return y;
}

/* FUNC(zx_ps_AddToCollectionResponse_PUSH_Status) */

void zx_ps_AddToCollectionResponse_PUSH_Status(struct zx_ps_AddToCollectionResponse_s* x, struct zx_lu_Status_s* z)
{
  if (!x || !z) return;
  z->gg.g.n = &x->Status->gg.g;
  x->Status = z;
}

/* FUNC(zx_ps_AddToCollectionResponse_REV_Status) */

void zx_ps_AddToCollectionResponse_REV_Status(struct zx_ps_AddToCollectionResponse_s* x)
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

/* FUNC(zx_ps_AddToCollectionResponse_PUT_Status) */

void zx_ps_AddToCollectionResponse_PUT_Status(struct zx_ps_AddToCollectionResponse_s* x, int n, struct zx_lu_Status_s* z)
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

/* FUNC(zx_ps_AddToCollectionResponse_ADD_Status) */

void zx_ps_AddToCollectionResponse_ADD_Status(struct zx_ps_AddToCollectionResponse_s* x, int n, struct zx_lu_Status_s* z)
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

/* FUNC(zx_ps_AddToCollectionResponse_DEL_Status) */

void zx_ps_AddToCollectionResponse_DEL_Status(struct zx_ps_AddToCollectionResponse_s* x, int n)
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

/* FUNC(zx_ps_AddToCollectionResponse_GET_TimeStamp) */
struct zx_str* zx_ps_AddToCollectionResponse_GET_TimeStamp(struct zx_ps_AddToCollectionResponse_s* x) { return x->TimeStamp; }
/* FUNC(zx_ps_AddToCollectionResponse_PUT_TimeStamp) */
void zx_ps_AddToCollectionResponse_PUT_TimeStamp(struct zx_ps_AddToCollectionResponse_s* x, struct zx_str* y) { x->TimeStamp = y; }
/* FUNC(zx_ps_AddToCollectionResponse_GET_id) */
struct zx_str* zx_ps_AddToCollectionResponse_GET_id(struct zx_ps_AddToCollectionResponse_s* x) { return x->id; }
/* FUNC(zx_ps_AddToCollectionResponse_PUT_id) */
void zx_ps_AddToCollectionResponse_PUT_id(struct zx_ps_AddToCollectionResponse_s* x, struct zx_str* y) { x->id = y; }










/* FUNC(zx_ps_DisplayName_GET_IsDefault) */
struct zx_str* zx_ps_DisplayName_GET_IsDefault(struct zx_ps_DisplayName_s* x) { return x->IsDefault; }
/* FUNC(zx_ps_DisplayName_PUT_IsDefault) */
void zx_ps_DisplayName_PUT_IsDefault(struct zx_ps_DisplayName_s* x, struct zx_str* y) { x->IsDefault = y; }
/* FUNC(zx_ps_DisplayName_GET_Locale) */
struct zx_str* zx_ps_DisplayName_GET_Locale(struct zx_ps_DisplayName_s* x) { return x->Locale; }
/* FUNC(zx_ps_DisplayName_PUT_Locale) */
void zx_ps_DisplayName_PUT_Locale(struct zx_ps_DisplayName_s* x, struct zx_str* y) { x->Locale = y; }







#ifdef ZX_ENA_GETPUT

/* FUNC(zx_ps_GetObjectInfoRequest_NUM_TargetObjectID) */

int zx_ps_GetObjectInfoRequest_NUM_TargetObjectID(struct zx_ps_GetObjectInfoRequest_s* x)
{
  struct zx_elem_s* y;
  int n = 0;
  if (!x) return 0;
  for (y = x->TargetObjectID; y; ++n, y = (struct zx_elem_s*)y->g.n) ;
  return n;
}

/* FUNC(zx_ps_GetObjectInfoRequest_GET_TargetObjectID) */

struct zx_elem_s* zx_ps_GetObjectInfoRequest_GET_TargetObjectID(struct zx_ps_GetObjectInfoRequest_s* x, int n)
{
  struct zx_elem_s* y;
  if (!x) return 0;
  for (y = x->TargetObjectID; n>=0 && y; --n, y = (struct zx_elem_s*)y->g.n) ;
  return y;
}

/* FUNC(zx_ps_GetObjectInfoRequest_POP_TargetObjectID) */

struct zx_elem_s* zx_ps_GetObjectInfoRequest_POP_TargetObjectID(struct zx_ps_GetObjectInfoRequest_s* x)
{
  struct zx_elem_s* y;
  if (!x) return 0;
  y = x->TargetObjectID;
  if (y)
    x->TargetObjectID = (struct zx_elem_s*)y->g.n;
  return y;
}

/* FUNC(zx_ps_GetObjectInfoRequest_PUSH_TargetObjectID) */

void zx_ps_GetObjectInfoRequest_PUSH_TargetObjectID(struct zx_ps_GetObjectInfoRequest_s* x, struct zx_elem_s* z)
{
  if (!x || !z) return;
  z->g.n = &x->TargetObjectID->g;
  x->TargetObjectID = z;
}

/* FUNC(zx_ps_GetObjectInfoRequest_REV_TargetObjectID) */

void zx_ps_GetObjectInfoRequest_REV_TargetObjectID(struct zx_ps_GetObjectInfoRequest_s* x)
{
  struct zx_elem_s* nxt;
  struct zx_elem_s* y;
  if (!x) return;
  y = x->TargetObjectID;
  if (!y) return;
  x->TargetObjectID = 0;
  while (y) {
    nxt = (struct zx_elem_s*)y->g.n;
    y->g.n = &x->TargetObjectID->g;
    x->TargetObjectID = y;
    y = nxt;
  }
}

/* FUNC(zx_ps_GetObjectInfoRequest_PUT_TargetObjectID) */

void zx_ps_GetObjectInfoRequest_PUT_TargetObjectID(struct zx_ps_GetObjectInfoRequest_s* x, int n, struct zx_elem_s* z)
{
  struct zx_elem_s* y;
  if (!x || !z) return;
  y = x->TargetObjectID;
  if (!y) return;
  switch (n) {
  case 0:
    z->g.n = y->g.n;
    x->TargetObjectID = z;
    return;
  default:
    for (; n > 1 && y->g.n; --n, y = (struct zx_elem_s*)y->g.n) ;
    if (!y->g.n) return;
    z->g.n = y->g.n->n;
    y->g.n = &z->g;
  }
}

/* FUNC(zx_ps_GetObjectInfoRequest_ADD_TargetObjectID) */

void zx_ps_GetObjectInfoRequest_ADD_TargetObjectID(struct zx_ps_GetObjectInfoRequest_s* x, int n, struct zx_elem_s* z)
{
  struct zx_elem_s* y;
  if (!x || !z) return;
  switch (n) {
  case 0:
  add_to_start:
    z->g.n = &x->TargetObjectID->g;
    x->TargetObjectID = z;
    return;
  case -1:
    y = x->TargetObjectID;
    if (!y) goto add_to_start;
    for (; y->g.n; y = (struct zx_elem_s*)y->g.n) ;
    break;
  default:
    for (y = x->TargetObjectID; n > 1 && y; --n, y = (struct zx_elem_s*)y->g.n) ;
    if (!y) return;
  }
  z->g.n = y->g.n;
  y->g.n = &z->g;
}

/* FUNC(zx_ps_GetObjectInfoRequest_DEL_TargetObjectID) */

void zx_ps_GetObjectInfoRequest_DEL_TargetObjectID(struct zx_ps_GetObjectInfoRequest_s* x, int n)
{
  struct zx_elem_s* y;
  if (!x) return;
  switch (n) {
  case 0:
    x->TargetObjectID = (struct zx_elem_s*)x->TargetObjectID->g.n;
    return;
  case -1:
    y = (struct zx_elem_s*)x->TargetObjectID;
    if (!y) return;
    for (; y->g.n; y = (struct zx_elem_s*)y->g.n) ;
    break;
  default:
    for (y = x->TargetObjectID; n > 1 && y->g.n; --n, y = (struct zx_elem_s*)y->g.n) ;
    if (!y->g.n) return;
  }
  y->g.n = y->g.n->n;
}

#endif



#ifdef ZX_ENA_GETPUT

/* FUNC(zx_ps_GetObjectInfoRequest_NUM_Subscription) */

int zx_ps_GetObjectInfoRequest_NUM_Subscription(struct zx_ps_GetObjectInfoRequest_s* x)
{
  struct zx_ps_Subscription_s* y;
  int n = 0;
  if (!x) return 0;
  for (y = x->Subscription; y; ++n, y = (struct zx_ps_Subscription_s*)y->gg.g.n) ;
  return n;
}

/* FUNC(zx_ps_GetObjectInfoRequest_GET_Subscription) */

struct zx_ps_Subscription_s* zx_ps_GetObjectInfoRequest_GET_Subscription(struct zx_ps_GetObjectInfoRequest_s* x, int n)
{
  struct zx_ps_Subscription_s* y;
  if (!x) return 0;
  for (y = x->Subscription; n>=0 && y; --n, y = (struct zx_ps_Subscription_s*)y->gg.g.n) ;
  return y;
}

/* FUNC(zx_ps_GetObjectInfoRequest_POP_Subscription) */

struct zx_ps_Subscription_s* zx_ps_GetObjectInfoRequest_POP_Subscription(struct zx_ps_GetObjectInfoRequest_s* x)
{
  struct zx_ps_Subscription_s* y;
  if (!x) return 0;
  y = x->Subscription;
  if (y)
    x->Subscription = (struct zx_ps_Subscription_s*)y->gg.g.n;
  return y;
}

/* FUNC(zx_ps_GetObjectInfoRequest_PUSH_Subscription) */

void zx_ps_GetObjectInfoRequest_PUSH_Subscription(struct zx_ps_GetObjectInfoRequest_s* x, struct zx_ps_Subscription_s* z)
{
  if (!x || !z) return;
  z->gg.g.n = &x->Subscription->gg.g;
  x->Subscription = z;
}

/* FUNC(zx_ps_GetObjectInfoRequest_REV_Subscription) */

void zx_ps_GetObjectInfoRequest_REV_Subscription(struct zx_ps_GetObjectInfoRequest_s* x)
{
  struct zx_ps_Subscription_s* nxt;
  struct zx_ps_Subscription_s* y;
  if (!x) return;
  y = x->Subscription;
  if (!y) return;
  x->Subscription = 0;
  while (y) {
    nxt = (struct zx_ps_Subscription_s*)y->gg.g.n;
    y->gg.g.n = &x->Subscription->gg.g;
    x->Subscription = y;
    y = nxt;
  }
}

/* FUNC(zx_ps_GetObjectInfoRequest_PUT_Subscription) */

void zx_ps_GetObjectInfoRequest_PUT_Subscription(struct zx_ps_GetObjectInfoRequest_s* x, int n, struct zx_ps_Subscription_s* z)
{
  struct zx_ps_Subscription_s* y;
  if (!x || !z) return;
  y = x->Subscription;
  if (!y) return;
  switch (n) {
  case 0:
    z->gg.g.n = y->gg.g.n;
    x->Subscription = z;
    return;
  default:
    for (; n > 1 && y->gg.g.n; --n, y = (struct zx_ps_Subscription_s*)y->gg.g.n) ;
    if (!y->gg.g.n) return;
    z->gg.g.n = y->gg.g.n->n;
    y->gg.g.n = &z->gg.g;
  }
}

/* FUNC(zx_ps_GetObjectInfoRequest_ADD_Subscription) */

void zx_ps_GetObjectInfoRequest_ADD_Subscription(struct zx_ps_GetObjectInfoRequest_s* x, int n, struct zx_ps_Subscription_s* z)
{
  struct zx_ps_Subscription_s* y;
  if (!x || !z) return;
  switch (n) {
  case 0:
  add_to_start:
    z->gg.g.n = &x->Subscription->gg.g;
    x->Subscription = z;
    return;
  case -1:
    y = x->Subscription;
    if (!y) goto add_to_start;
    for (; y->gg.g.n; y = (struct zx_ps_Subscription_s*)y->gg.g.n) ;
    break;
  default:
    for (y = x->Subscription; n > 1 && y; --n, y = (struct zx_ps_Subscription_s*)y->gg.g.n) ;
    if (!y) return;
  }
  z->gg.g.n = y->gg.g.n;
  y->gg.g.n = &z->gg.g;
}

/* FUNC(zx_ps_GetObjectInfoRequest_DEL_Subscription) */

void zx_ps_GetObjectInfoRequest_DEL_Subscription(struct zx_ps_GetObjectInfoRequest_s* x, int n)
{
  struct zx_ps_Subscription_s* y;
  if (!x) return;
  switch (n) {
  case 0:
    x->Subscription = (struct zx_ps_Subscription_s*)x->Subscription->gg.g.n;
    return;
  case -1:
    y = (struct zx_ps_Subscription_s*)x->Subscription;
    if (!y) return;
    for (; y->gg.g.n; y = (struct zx_ps_Subscription_s*)y->gg.g.n) ;
    break;
  default:
    for (y = x->Subscription; n > 1 && y->gg.g.n; --n, y = (struct zx_ps_Subscription_s*)y->gg.g.n) ;
    if (!y->gg.g.n) return;
  }
  y->gg.g.n = y->gg.g.n->n;
}

#endif

/* FUNC(zx_ps_GetObjectInfoRequest_GET_id) */
struct zx_str* zx_ps_GetObjectInfoRequest_GET_id(struct zx_ps_GetObjectInfoRequest_s* x) { return x->id; }
/* FUNC(zx_ps_GetObjectInfoRequest_PUT_id) */
void zx_ps_GetObjectInfoRequest_PUT_id(struct zx_ps_GetObjectInfoRequest_s* x, struct zx_str* y) { x->id = y; }







#ifdef ZX_ENA_GETPUT

/* FUNC(zx_ps_GetObjectInfoResponse_NUM_Status) */

int zx_ps_GetObjectInfoResponse_NUM_Status(struct zx_ps_GetObjectInfoResponse_s* x)
{
  struct zx_lu_Status_s* y;
  int n = 0;
  if (!x) return 0;
  for (y = x->Status; y; ++n, y = (struct zx_lu_Status_s*)y->gg.g.n) ;
  return n;
}

/* FUNC(zx_ps_GetObjectInfoResponse_GET_Status) */

struct zx_lu_Status_s* zx_ps_GetObjectInfoResponse_GET_Status(struct zx_ps_GetObjectInfoResponse_s* x, int n)
{
  struct zx_lu_Status_s* y;
  if (!x) return 0;
  for (y = x->Status; n>=0 && y; --n, y = (struct zx_lu_Status_s*)y->gg.g.n) ;
  return y;
}

/* FUNC(zx_ps_GetObjectInfoResponse_POP_Status) */

struct zx_lu_Status_s* zx_ps_GetObjectInfoResponse_POP_Status(struct zx_ps_GetObjectInfoResponse_s* x)
{
  struct zx_lu_Status_s* y;
  if (!x) return 0;
  y = x->Status;
  if (y)
    x->Status = (struct zx_lu_Status_s*)y->gg.g.n;
  return y;
}

/* FUNC(zx_ps_GetObjectInfoResponse_PUSH_Status) */

void zx_ps_GetObjectInfoResponse_PUSH_Status(struct zx_ps_GetObjectInfoResponse_s* x, struct zx_lu_Status_s* z)
{
  if (!x || !z) return;
  z->gg.g.n = &x->Status->gg.g;
  x->Status = z;
}

/* FUNC(zx_ps_GetObjectInfoResponse_REV_Status) */

void zx_ps_GetObjectInfoResponse_REV_Status(struct zx_ps_GetObjectInfoResponse_s* x)
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

/* FUNC(zx_ps_GetObjectInfoResponse_PUT_Status) */

void zx_ps_GetObjectInfoResponse_PUT_Status(struct zx_ps_GetObjectInfoResponse_s* x, int n, struct zx_lu_Status_s* z)
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

/* FUNC(zx_ps_GetObjectInfoResponse_ADD_Status) */

void zx_ps_GetObjectInfoResponse_ADD_Status(struct zx_ps_GetObjectInfoResponse_s* x, int n, struct zx_lu_Status_s* z)
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

/* FUNC(zx_ps_GetObjectInfoResponse_DEL_Status) */

void zx_ps_GetObjectInfoResponse_DEL_Status(struct zx_ps_GetObjectInfoResponse_s* x, int n)
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



#ifdef ZX_ENA_GETPUT

/* FUNC(zx_ps_GetObjectInfoResponse_NUM_Object) */

int zx_ps_GetObjectInfoResponse_NUM_Object(struct zx_ps_GetObjectInfoResponse_s* x)
{
  struct zx_ps_Object_s* y;
  int n = 0;
  if (!x) return 0;
  for (y = x->Object; y; ++n, y = (struct zx_ps_Object_s*)y->gg.g.n) ;
  return n;
}

/* FUNC(zx_ps_GetObjectInfoResponse_GET_Object) */

struct zx_ps_Object_s* zx_ps_GetObjectInfoResponse_GET_Object(struct zx_ps_GetObjectInfoResponse_s* x, int n)
{
  struct zx_ps_Object_s* y;
  if (!x) return 0;
  for (y = x->Object; n>=0 && y; --n, y = (struct zx_ps_Object_s*)y->gg.g.n) ;
  return y;
}

/* FUNC(zx_ps_GetObjectInfoResponse_POP_Object) */

struct zx_ps_Object_s* zx_ps_GetObjectInfoResponse_POP_Object(struct zx_ps_GetObjectInfoResponse_s* x)
{
  struct zx_ps_Object_s* y;
  if (!x) return 0;
  y = x->Object;
  if (y)
    x->Object = (struct zx_ps_Object_s*)y->gg.g.n;
  return y;
}

/* FUNC(zx_ps_GetObjectInfoResponse_PUSH_Object) */

void zx_ps_GetObjectInfoResponse_PUSH_Object(struct zx_ps_GetObjectInfoResponse_s* x, struct zx_ps_Object_s* z)
{
  if (!x || !z) return;
  z->gg.g.n = &x->Object->gg.g;
  x->Object = z;
}

/* FUNC(zx_ps_GetObjectInfoResponse_REV_Object) */

void zx_ps_GetObjectInfoResponse_REV_Object(struct zx_ps_GetObjectInfoResponse_s* x)
{
  struct zx_ps_Object_s* nxt;
  struct zx_ps_Object_s* y;
  if (!x) return;
  y = x->Object;
  if (!y) return;
  x->Object = 0;
  while (y) {
    nxt = (struct zx_ps_Object_s*)y->gg.g.n;
    y->gg.g.n = &x->Object->gg.g;
    x->Object = y;
    y = nxt;
  }
}

/* FUNC(zx_ps_GetObjectInfoResponse_PUT_Object) */

void zx_ps_GetObjectInfoResponse_PUT_Object(struct zx_ps_GetObjectInfoResponse_s* x, int n, struct zx_ps_Object_s* z)
{
  struct zx_ps_Object_s* y;
  if (!x || !z) return;
  y = x->Object;
  if (!y) return;
  switch (n) {
  case 0:
    z->gg.g.n = y->gg.g.n;
    x->Object = z;
    return;
  default:
    for (; n > 1 && y->gg.g.n; --n, y = (struct zx_ps_Object_s*)y->gg.g.n) ;
    if (!y->gg.g.n) return;
    z->gg.g.n = y->gg.g.n->n;
    y->gg.g.n = &z->gg.g;
  }
}

/* FUNC(zx_ps_GetObjectInfoResponse_ADD_Object) */

void zx_ps_GetObjectInfoResponse_ADD_Object(struct zx_ps_GetObjectInfoResponse_s* x, int n, struct zx_ps_Object_s* z)
{
  struct zx_ps_Object_s* y;
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
    for (; y->gg.g.n; y = (struct zx_ps_Object_s*)y->gg.g.n) ;
    break;
  default:
    for (y = x->Object; n > 1 && y; --n, y = (struct zx_ps_Object_s*)y->gg.g.n) ;
    if (!y) return;
  }
  z->gg.g.n = y->gg.g.n;
  y->gg.g.n = &z->gg.g;
}

/* FUNC(zx_ps_GetObjectInfoResponse_DEL_Object) */

void zx_ps_GetObjectInfoResponse_DEL_Object(struct zx_ps_GetObjectInfoResponse_s* x, int n)
{
  struct zx_ps_Object_s* y;
  if (!x) return;
  switch (n) {
  case 0:
    x->Object = (struct zx_ps_Object_s*)x->Object->gg.g.n;
    return;
  case -1:
    y = (struct zx_ps_Object_s*)x->Object;
    if (!y) return;
    for (; y->gg.g.n; y = (struct zx_ps_Object_s*)y->gg.g.n) ;
    break;
  default:
    for (y = x->Object; n > 1 && y->gg.g.n; --n, y = (struct zx_ps_Object_s*)y->gg.g.n) ;
    if (!y->gg.g.n) return;
  }
  y->gg.g.n = y->gg.g.n->n;
}

#endif

/* FUNC(zx_ps_GetObjectInfoResponse_GET_TimeStamp) */
struct zx_str* zx_ps_GetObjectInfoResponse_GET_TimeStamp(struct zx_ps_GetObjectInfoResponse_s* x) { return x->TimeStamp; }
/* FUNC(zx_ps_GetObjectInfoResponse_PUT_TimeStamp) */
void zx_ps_GetObjectInfoResponse_PUT_TimeStamp(struct zx_ps_GetObjectInfoResponse_s* x, struct zx_str* y) { x->TimeStamp = y; }
/* FUNC(zx_ps_GetObjectInfoResponse_GET_id) */
struct zx_str* zx_ps_GetObjectInfoResponse_GET_id(struct zx_ps_GetObjectInfoResponse_s* x) { return x->id; }
/* FUNC(zx_ps_GetObjectInfoResponse_PUT_id) */
void zx_ps_GetObjectInfoResponse_PUT_id(struct zx_ps_GetObjectInfoResponse_s* x, struct zx_str* y) { x->id = y; }







#ifdef ZX_ENA_GETPUT

/* FUNC(zx_ps_ItemData_NUM_Object) */

int zx_ps_ItemData_NUM_Object(struct zx_ps_ItemData_s* x)
{
  struct zx_ps_Object_s* y;
  int n = 0;
  if (!x) return 0;
  for (y = x->Object; y; ++n, y = (struct zx_ps_Object_s*)y->gg.g.n) ;
  return n;
}

/* FUNC(zx_ps_ItemData_GET_Object) */

struct zx_ps_Object_s* zx_ps_ItemData_GET_Object(struct zx_ps_ItemData_s* x, int n)
{
  struct zx_ps_Object_s* y;
  if (!x) return 0;
  for (y = x->Object; n>=0 && y; --n, y = (struct zx_ps_Object_s*)y->gg.g.n) ;
  return y;
}

/* FUNC(zx_ps_ItemData_POP_Object) */

struct zx_ps_Object_s* zx_ps_ItemData_POP_Object(struct zx_ps_ItemData_s* x)
{
  struct zx_ps_Object_s* y;
  if (!x) return 0;
  y = x->Object;
  if (y)
    x->Object = (struct zx_ps_Object_s*)y->gg.g.n;
  return y;
}

/* FUNC(zx_ps_ItemData_PUSH_Object) */

void zx_ps_ItemData_PUSH_Object(struct zx_ps_ItemData_s* x, struct zx_ps_Object_s* z)
{
  if (!x || !z) return;
  z->gg.g.n = &x->Object->gg.g;
  x->Object = z;
}

/* FUNC(zx_ps_ItemData_REV_Object) */

void zx_ps_ItemData_REV_Object(struct zx_ps_ItemData_s* x)
{
  struct zx_ps_Object_s* nxt;
  struct zx_ps_Object_s* y;
  if (!x) return;
  y = x->Object;
  if (!y) return;
  x->Object = 0;
  while (y) {
    nxt = (struct zx_ps_Object_s*)y->gg.g.n;
    y->gg.g.n = &x->Object->gg.g;
    x->Object = y;
    y = nxt;
  }
}

/* FUNC(zx_ps_ItemData_PUT_Object) */

void zx_ps_ItemData_PUT_Object(struct zx_ps_ItemData_s* x, int n, struct zx_ps_Object_s* z)
{
  struct zx_ps_Object_s* y;
  if (!x || !z) return;
  y = x->Object;
  if (!y) return;
  switch (n) {
  case 0:
    z->gg.g.n = y->gg.g.n;
    x->Object = z;
    return;
  default:
    for (; n > 1 && y->gg.g.n; --n, y = (struct zx_ps_Object_s*)y->gg.g.n) ;
    if (!y->gg.g.n) return;
    z->gg.g.n = y->gg.g.n->n;
    y->gg.g.n = &z->gg.g;
  }
}

/* FUNC(zx_ps_ItemData_ADD_Object) */

void zx_ps_ItemData_ADD_Object(struct zx_ps_ItemData_s* x, int n, struct zx_ps_Object_s* z)
{
  struct zx_ps_Object_s* y;
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
    for (; y->gg.g.n; y = (struct zx_ps_Object_s*)y->gg.g.n) ;
    break;
  default:
    for (y = x->Object; n > 1 && y; --n, y = (struct zx_ps_Object_s*)y->gg.g.n) ;
    if (!y) return;
  }
  z->gg.g.n = y->gg.g.n;
  y->gg.g.n = &z->gg.g;
}

/* FUNC(zx_ps_ItemData_DEL_Object) */

void zx_ps_ItemData_DEL_Object(struct zx_ps_ItemData_s* x, int n)
{
  struct zx_ps_Object_s* y;
  if (!x) return;
  switch (n) {
  case 0:
    x->Object = (struct zx_ps_Object_s*)x->Object->gg.g.n;
    return;
  case -1:
    y = (struct zx_ps_Object_s*)x->Object;
    if (!y) return;
    for (; y->gg.g.n; y = (struct zx_ps_Object_s*)y->gg.g.n) ;
    break;
  default:
    for (y = x->Object; n > 1 && y->gg.g.n; --n, y = (struct zx_ps_Object_s*)y->gg.g.n) ;
    if (!y->gg.g.n) return;
  }
  y->gg.g.n = y->gg.g.n->n;
}

#endif








#ifdef ZX_ENA_GETPUT

/* FUNC(zx_ps_ListMembersRequest_NUM_TargetObjectID) */

int zx_ps_ListMembersRequest_NUM_TargetObjectID(struct zx_ps_ListMembersRequest_s* x)
{
  struct zx_elem_s* y;
  int n = 0;
  if (!x) return 0;
  for (y = x->TargetObjectID; y; ++n, y = (struct zx_elem_s*)y->g.n) ;
  return n;
}

/* FUNC(zx_ps_ListMembersRequest_GET_TargetObjectID) */

struct zx_elem_s* zx_ps_ListMembersRequest_GET_TargetObjectID(struct zx_ps_ListMembersRequest_s* x, int n)
{
  struct zx_elem_s* y;
  if (!x) return 0;
  for (y = x->TargetObjectID; n>=0 && y; --n, y = (struct zx_elem_s*)y->g.n) ;
  return y;
}

/* FUNC(zx_ps_ListMembersRequest_POP_TargetObjectID) */

struct zx_elem_s* zx_ps_ListMembersRequest_POP_TargetObjectID(struct zx_ps_ListMembersRequest_s* x)
{
  struct zx_elem_s* y;
  if (!x) return 0;
  y = x->TargetObjectID;
  if (y)
    x->TargetObjectID = (struct zx_elem_s*)y->g.n;
  return y;
}

/* FUNC(zx_ps_ListMembersRequest_PUSH_TargetObjectID) */

void zx_ps_ListMembersRequest_PUSH_TargetObjectID(struct zx_ps_ListMembersRequest_s* x, struct zx_elem_s* z)
{
  if (!x || !z) return;
  z->g.n = &x->TargetObjectID->g;
  x->TargetObjectID = z;
}

/* FUNC(zx_ps_ListMembersRequest_REV_TargetObjectID) */

void zx_ps_ListMembersRequest_REV_TargetObjectID(struct zx_ps_ListMembersRequest_s* x)
{
  struct zx_elem_s* nxt;
  struct zx_elem_s* y;
  if (!x) return;
  y = x->TargetObjectID;
  if (!y) return;
  x->TargetObjectID = 0;
  while (y) {
    nxt = (struct zx_elem_s*)y->g.n;
    y->g.n = &x->TargetObjectID->g;
    x->TargetObjectID = y;
    y = nxt;
  }
}

/* FUNC(zx_ps_ListMembersRequest_PUT_TargetObjectID) */

void zx_ps_ListMembersRequest_PUT_TargetObjectID(struct zx_ps_ListMembersRequest_s* x, int n, struct zx_elem_s* z)
{
  struct zx_elem_s* y;
  if (!x || !z) return;
  y = x->TargetObjectID;
  if (!y) return;
  switch (n) {
  case 0:
    z->g.n = y->g.n;
    x->TargetObjectID = z;
    return;
  default:
    for (; n > 1 && y->g.n; --n, y = (struct zx_elem_s*)y->g.n) ;
    if (!y->g.n) return;
    z->g.n = y->g.n->n;
    y->g.n = &z->g;
  }
}

/* FUNC(zx_ps_ListMembersRequest_ADD_TargetObjectID) */

void zx_ps_ListMembersRequest_ADD_TargetObjectID(struct zx_ps_ListMembersRequest_s* x, int n, struct zx_elem_s* z)
{
  struct zx_elem_s* y;
  if (!x || !z) return;
  switch (n) {
  case 0:
  add_to_start:
    z->g.n = &x->TargetObjectID->g;
    x->TargetObjectID = z;
    return;
  case -1:
    y = x->TargetObjectID;
    if (!y) goto add_to_start;
    for (; y->g.n; y = (struct zx_elem_s*)y->g.n) ;
    break;
  default:
    for (y = x->TargetObjectID; n > 1 && y; --n, y = (struct zx_elem_s*)y->g.n) ;
    if (!y) return;
  }
  z->g.n = y->g.n;
  y->g.n = &z->g;
}

/* FUNC(zx_ps_ListMembersRequest_DEL_TargetObjectID) */

void zx_ps_ListMembersRequest_DEL_TargetObjectID(struct zx_ps_ListMembersRequest_s* x, int n)
{
  struct zx_elem_s* y;
  if (!x) return;
  switch (n) {
  case 0:
    x->TargetObjectID = (struct zx_elem_s*)x->TargetObjectID->g.n;
    return;
  case -1:
    y = (struct zx_elem_s*)x->TargetObjectID;
    if (!y) return;
    for (; y->g.n; y = (struct zx_elem_s*)y->g.n) ;
    break;
  default:
    for (y = x->TargetObjectID; n > 1 && y->g.n; --n, y = (struct zx_elem_s*)y->g.n) ;
    if (!y->g.n) return;
  }
  y->g.n = y->g.n->n;
}

#endif



#ifdef ZX_ENA_GETPUT

/* FUNC(zx_ps_ListMembersRequest_NUM_Subscription) */

int zx_ps_ListMembersRequest_NUM_Subscription(struct zx_ps_ListMembersRequest_s* x)
{
  struct zx_ps_Subscription_s* y;
  int n = 0;
  if (!x) return 0;
  for (y = x->Subscription; y; ++n, y = (struct zx_ps_Subscription_s*)y->gg.g.n) ;
  return n;
}

/* FUNC(zx_ps_ListMembersRequest_GET_Subscription) */

struct zx_ps_Subscription_s* zx_ps_ListMembersRequest_GET_Subscription(struct zx_ps_ListMembersRequest_s* x, int n)
{
  struct zx_ps_Subscription_s* y;
  if (!x) return 0;
  for (y = x->Subscription; n>=0 && y; --n, y = (struct zx_ps_Subscription_s*)y->gg.g.n) ;
  return y;
}

/* FUNC(zx_ps_ListMembersRequest_POP_Subscription) */

struct zx_ps_Subscription_s* zx_ps_ListMembersRequest_POP_Subscription(struct zx_ps_ListMembersRequest_s* x)
{
  struct zx_ps_Subscription_s* y;
  if (!x) return 0;
  y = x->Subscription;
  if (y)
    x->Subscription = (struct zx_ps_Subscription_s*)y->gg.g.n;
  return y;
}

/* FUNC(zx_ps_ListMembersRequest_PUSH_Subscription) */

void zx_ps_ListMembersRequest_PUSH_Subscription(struct zx_ps_ListMembersRequest_s* x, struct zx_ps_Subscription_s* z)
{
  if (!x || !z) return;
  z->gg.g.n = &x->Subscription->gg.g;
  x->Subscription = z;
}

/* FUNC(zx_ps_ListMembersRequest_REV_Subscription) */

void zx_ps_ListMembersRequest_REV_Subscription(struct zx_ps_ListMembersRequest_s* x)
{
  struct zx_ps_Subscription_s* nxt;
  struct zx_ps_Subscription_s* y;
  if (!x) return;
  y = x->Subscription;
  if (!y) return;
  x->Subscription = 0;
  while (y) {
    nxt = (struct zx_ps_Subscription_s*)y->gg.g.n;
    y->gg.g.n = &x->Subscription->gg.g;
    x->Subscription = y;
    y = nxt;
  }
}

/* FUNC(zx_ps_ListMembersRequest_PUT_Subscription) */

void zx_ps_ListMembersRequest_PUT_Subscription(struct zx_ps_ListMembersRequest_s* x, int n, struct zx_ps_Subscription_s* z)
{
  struct zx_ps_Subscription_s* y;
  if (!x || !z) return;
  y = x->Subscription;
  if (!y) return;
  switch (n) {
  case 0:
    z->gg.g.n = y->gg.g.n;
    x->Subscription = z;
    return;
  default:
    for (; n > 1 && y->gg.g.n; --n, y = (struct zx_ps_Subscription_s*)y->gg.g.n) ;
    if (!y->gg.g.n) return;
    z->gg.g.n = y->gg.g.n->n;
    y->gg.g.n = &z->gg.g;
  }
}

/* FUNC(zx_ps_ListMembersRequest_ADD_Subscription) */

void zx_ps_ListMembersRequest_ADD_Subscription(struct zx_ps_ListMembersRequest_s* x, int n, struct zx_ps_Subscription_s* z)
{
  struct zx_ps_Subscription_s* y;
  if (!x || !z) return;
  switch (n) {
  case 0:
  add_to_start:
    z->gg.g.n = &x->Subscription->gg.g;
    x->Subscription = z;
    return;
  case -1:
    y = x->Subscription;
    if (!y) goto add_to_start;
    for (; y->gg.g.n; y = (struct zx_ps_Subscription_s*)y->gg.g.n) ;
    break;
  default:
    for (y = x->Subscription; n > 1 && y; --n, y = (struct zx_ps_Subscription_s*)y->gg.g.n) ;
    if (!y) return;
  }
  z->gg.g.n = y->gg.g.n;
  y->gg.g.n = &z->gg.g;
}

/* FUNC(zx_ps_ListMembersRequest_DEL_Subscription) */

void zx_ps_ListMembersRequest_DEL_Subscription(struct zx_ps_ListMembersRequest_s* x, int n)
{
  struct zx_ps_Subscription_s* y;
  if (!x) return;
  switch (n) {
  case 0:
    x->Subscription = (struct zx_ps_Subscription_s*)x->Subscription->gg.g.n;
    return;
  case -1:
    y = (struct zx_ps_Subscription_s*)x->Subscription;
    if (!y) return;
    for (; y->gg.g.n; y = (struct zx_ps_Subscription_s*)y->gg.g.n) ;
    break;
  default:
    for (y = x->Subscription; n > 1 && y->gg.g.n; --n, y = (struct zx_ps_Subscription_s*)y->gg.g.n) ;
    if (!y->gg.g.n) return;
  }
  y->gg.g.n = y->gg.g.n->n;
}

#endif

/* FUNC(zx_ps_ListMembersRequest_GET_Count) */
struct zx_str* zx_ps_ListMembersRequest_GET_Count(struct zx_ps_ListMembersRequest_s* x) { return x->Count; }
/* FUNC(zx_ps_ListMembersRequest_PUT_Count) */
void zx_ps_ListMembersRequest_PUT_Count(struct zx_ps_ListMembersRequest_s* x, struct zx_str* y) { x->Count = y; }
/* FUNC(zx_ps_ListMembersRequest_GET_Offset) */
struct zx_str* zx_ps_ListMembersRequest_GET_Offset(struct zx_ps_ListMembersRequest_s* x) { return x->Offset; }
/* FUNC(zx_ps_ListMembersRequest_PUT_Offset) */
void zx_ps_ListMembersRequest_PUT_Offset(struct zx_ps_ListMembersRequest_s* x, struct zx_str* y) { x->Offset = y; }
/* FUNC(zx_ps_ListMembersRequest_GET_Structured) */
struct zx_str* zx_ps_ListMembersRequest_GET_Structured(struct zx_ps_ListMembersRequest_s* x) { return x->Structured; }
/* FUNC(zx_ps_ListMembersRequest_PUT_Structured) */
void zx_ps_ListMembersRequest_PUT_Structured(struct zx_ps_ListMembersRequest_s* x, struct zx_str* y) { x->Structured = y; }
/* FUNC(zx_ps_ListMembersRequest_GET_id) */
struct zx_str* zx_ps_ListMembersRequest_GET_id(struct zx_ps_ListMembersRequest_s* x) { return x->id; }
/* FUNC(zx_ps_ListMembersRequest_PUT_id) */
void zx_ps_ListMembersRequest_PUT_id(struct zx_ps_ListMembersRequest_s* x, struct zx_str* y) { x->id = y; }







#ifdef ZX_ENA_GETPUT

/* FUNC(zx_ps_ListMembersResponse_NUM_Status) */

int zx_ps_ListMembersResponse_NUM_Status(struct zx_ps_ListMembersResponse_s* x)
{
  struct zx_lu_Status_s* y;
  int n = 0;
  if (!x) return 0;
  for (y = x->Status; y; ++n, y = (struct zx_lu_Status_s*)y->gg.g.n) ;
  return n;
}

/* FUNC(zx_ps_ListMembersResponse_GET_Status) */

struct zx_lu_Status_s* zx_ps_ListMembersResponse_GET_Status(struct zx_ps_ListMembersResponse_s* x, int n)
{
  struct zx_lu_Status_s* y;
  if (!x) return 0;
  for (y = x->Status; n>=0 && y; --n, y = (struct zx_lu_Status_s*)y->gg.g.n) ;
  return y;
}

/* FUNC(zx_ps_ListMembersResponse_POP_Status) */

struct zx_lu_Status_s* zx_ps_ListMembersResponse_POP_Status(struct zx_ps_ListMembersResponse_s* x)
{
  struct zx_lu_Status_s* y;
  if (!x) return 0;
  y = x->Status;
  if (y)
    x->Status = (struct zx_lu_Status_s*)y->gg.g.n;
  return y;
}

/* FUNC(zx_ps_ListMembersResponse_PUSH_Status) */

void zx_ps_ListMembersResponse_PUSH_Status(struct zx_ps_ListMembersResponse_s* x, struct zx_lu_Status_s* z)
{
  if (!x || !z) return;
  z->gg.g.n = &x->Status->gg.g;
  x->Status = z;
}

/* FUNC(zx_ps_ListMembersResponse_REV_Status) */

void zx_ps_ListMembersResponse_REV_Status(struct zx_ps_ListMembersResponse_s* x)
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

/* FUNC(zx_ps_ListMembersResponse_PUT_Status) */

void zx_ps_ListMembersResponse_PUT_Status(struct zx_ps_ListMembersResponse_s* x, int n, struct zx_lu_Status_s* z)
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

/* FUNC(zx_ps_ListMembersResponse_ADD_Status) */

void zx_ps_ListMembersResponse_ADD_Status(struct zx_ps_ListMembersResponse_s* x, int n, struct zx_lu_Status_s* z)
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

/* FUNC(zx_ps_ListMembersResponse_DEL_Status) */

void zx_ps_ListMembersResponse_DEL_Status(struct zx_ps_ListMembersResponse_s* x, int n)
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



#ifdef ZX_ENA_GETPUT

/* FUNC(zx_ps_ListMembersResponse_NUM_Object) */

int zx_ps_ListMembersResponse_NUM_Object(struct zx_ps_ListMembersResponse_s* x)
{
  struct zx_ps_Object_s* y;
  int n = 0;
  if (!x) return 0;
  for (y = x->Object; y; ++n, y = (struct zx_ps_Object_s*)y->gg.g.n) ;
  return n;
}

/* FUNC(zx_ps_ListMembersResponse_GET_Object) */

struct zx_ps_Object_s* zx_ps_ListMembersResponse_GET_Object(struct zx_ps_ListMembersResponse_s* x, int n)
{
  struct zx_ps_Object_s* y;
  if (!x) return 0;
  for (y = x->Object; n>=0 && y; --n, y = (struct zx_ps_Object_s*)y->gg.g.n) ;
  return y;
}

/* FUNC(zx_ps_ListMembersResponse_POP_Object) */

struct zx_ps_Object_s* zx_ps_ListMembersResponse_POP_Object(struct zx_ps_ListMembersResponse_s* x)
{
  struct zx_ps_Object_s* y;
  if (!x) return 0;
  y = x->Object;
  if (y)
    x->Object = (struct zx_ps_Object_s*)y->gg.g.n;
  return y;
}

/* FUNC(zx_ps_ListMembersResponse_PUSH_Object) */

void zx_ps_ListMembersResponse_PUSH_Object(struct zx_ps_ListMembersResponse_s* x, struct zx_ps_Object_s* z)
{
  if (!x || !z) return;
  z->gg.g.n = &x->Object->gg.g;
  x->Object = z;
}

/* FUNC(zx_ps_ListMembersResponse_REV_Object) */

void zx_ps_ListMembersResponse_REV_Object(struct zx_ps_ListMembersResponse_s* x)
{
  struct zx_ps_Object_s* nxt;
  struct zx_ps_Object_s* y;
  if (!x) return;
  y = x->Object;
  if (!y) return;
  x->Object = 0;
  while (y) {
    nxt = (struct zx_ps_Object_s*)y->gg.g.n;
    y->gg.g.n = &x->Object->gg.g;
    x->Object = y;
    y = nxt;
  }
}

/* FUNC(zx_ps_ListMembersResponse_PUT_Object) */

void zx_ps_ListMembersResponse_PUT_Object(struct zx_ps_ListMembersResponse_s* x, int n, struct zx_ps_Object_s* z)
{
  struct zx_ps_Object_s* y;
  if (!x || !z) return;
  y = x->Object;
  if (!y) return;
  switch (n) {
  case 0:
    z->gg.g.n = y->gg.g.n;
    x->Object = z;
    return;
  default:
    for (; n > 1 && y->gg.g.n; --n, y = (struct zx_ps_Object_s*)y->gg.g.n) ;
    if (!y->gg.g.n) return;
    z->gg.g.n = y->gg.g.n->n;
    y->gg.g.n = &z->gg.g;
  }
}

/* FUNC(zx_ps_ListMembersResponse_ADD_Object) */

void zx_ps_ListMembersResponse_ADD_Object(struct zx_ps_ListMembersResponse_s* x, int n, struct zx_ps_Object_s* z)
{
  struct zx_ps_Object_s* y;
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
    for (; y->gg.g.n; y = (struct zx_ps_Object_s*)y->gg.g.n) ;
    break;
  default:
    for (y = x->Object; n > 1 && y; --n, y = (struct zx_ps_Object_s*)y->gg.g.n) ;
    if (!y) return;
  }
  z->gg.g.n = y->gg.g.n;
  y->gg.g.n = &z->gg.g;
}

/* FUNC(zx_ps_ListMembersResponse_DEL_Object) */

void zx_ps_ListMembersResponse_DEL_Object(struct zx_ps_ListMembersResponse_s* x, int n)
{
  struct zx_ps_Object_s* y;
  if (!x) return;
  switch (n) {
  case 0:
    x->Object = (struct zx_ps_Object_s*)x->Object->gg.g.n;
    return;
  case -1:
    y = (struct zx_ps_Object_s*)x->Object;
    if (!y) return;
    for (; y->gg.g.n; y = (struct zx_ps_Object_s*)y->gg.g.n) ;
    break;
  default:
    for (y = x->Object; n > 1 && y->gg.g.n; --n, y = (struct zx_ps_Object_s*)y->gg.g.n) ;
    if (!y->gg.g.n) return;
  }
  y->gg.g.n = y->gg.g.n->n;
}

#endif

/* FUNC(zx_ps_ListMembersResponse_GET_TimeStamp) */
struct zx_str* zx_ps_ListMembersResponse_GET_TimeStamp(struct zx_ps_ListMembersResponse_s* x) { return x->TimeStamp; }
/* FUNC(zx_ps_ListMembersResponse_PUT_TimeStamp) */
void zx_ps_ListMembersResponse_PUT_TimeStamp(struct zx_ps_ListMembersResponse_s* x, struct zx_str* y) { x->TimeStamp = y; }
/* FUNC(zx_ps_ListMembersResponse_GET_id) */
struct zx_str* zx_ps_ListMembersResponse_GET_id(struct zx_ps_ListMembersResponse_s* x) { return x->id; }
/* FUNC(zx_ps_ListMembersResponse_PUT_id) */
void zx_ps_ListMembersResponse_PUT_id(struct zx_ps_ListMembersResponse_s* x, struct zx_str* y) { x->id = y; }







#ifdef ZX_ENA_GETPUT

/* FUNC(zx_ps_Notification_NUM_TestResult) */

int zx_ps_Notification_NUM_TestResult(struct zx_ps_Notification_s* x)
{
  struct zx_lu_TestResult_s* y;
  int n = 0;
  if (!x) return 0;
  for (y = x->TestResult; y; ++n, y = (struct zx_lu_TestResult_s*)y->gg.g.n) ;
  return n;
}

/* FUNC(zx_ps_Notification_GET_TestResult) */

struct zx_lu_TestResult_s* zx_ps_Notification_GET_TestResult(struct zx_ps_Notification_s* x, int n)
{
  struct zx_lu_TestResult_s* y;
  if (!x) return 0;
  for (y = x->TestResult; n>=0 && y; --n, y = (struct zx_lu_TestResult_s*)y->gg.g.n) ;
  return y;
}

/* FUNC(zx_ps_Notification_POP_TestResult) */

struct zx_lu_TestResult_s* zx_ps_Notification_POP_TestResult(struct zx_ps_Notification_s* x)
{
  struct zx_lu_TestResult_s* y;
  if (!x) return 0;
  y = x->TestResult;
  if (y)
    x->TestResult = (struct zx_lu_TestResult_s*)y->gg.g.n;
  return y;
}

/* FUNC(zx_ps_Notification_PUSH_TestResult) */

void zx_ps_Notification_PUSH_TestResult(struct zx_ps_Notification_s* x, struct zx_lu_TestResult_s* z)
{
  if (!x || !z) return;
  z->gg.g.n = &x->TestResult->gg.g;
  x->TestResult = z;
}

/* FUNC(zx_ps_Notification_REV_TestResult) */

void zx_ps_Notification_REV_TestResult(struct zx_ps_Notification_s* x)
{
  struct zx_lu_TestResult_s* nxt;
  struct zx_lu_TestResult_s* y;
  if (!x) return;
  y = x->TestResult;
  if (!y) return;
  x->TestResult = 0;
  while (y) {
    nxt = (struct zx_lu_TestResult_s*)y->gg.g.n;
    y->gg.g.n = &x->TestResult->gg.g;
    x->TestResult = y;
    y = nxt;
  }
}

/* FUNC(zx_ps_Notification_PUT_TestResult) */

void zx_ps_Notification_PUT_TestResult(struct zx_ps_Notification_s* x, int n, struct zx_lu_TestResult_s* z)
{
  struct zx_lu_TestResult_s* y;
  if (!x || !z) return;
  y = x->TestResult;
  if (!y) return;
  switch (n) {
  case 0:
    z->gg.g.n = y->gg.g.n;
    x->TestResult = z;
    return;
  default:
    for (; n > 1 && y->gg.g.n; --n, y = (struct zx_lu_TestResult_s*)y->gg.g.n) ;
    if (!y->gg.g.n) return;
    z->gg.g.n = y->gg.g.n->n;
    y->gg.g.n = &z->gg.g;
  }
}

/* FUNC(zx_ps_Notification_ADD_TestResult) */

void zx_ps_Notification_ADD_TestResult(struct zx_ps_Notification_s* x, int n, struct zx_lu_TestResult_s* z)
{
  struct zx_lu_TestResult_s* y;
  if (!x || !z) return;
  switch (n) {
  case 0:
  add_to_start:
    z->gg.g.n = &x->TestResult->gg.g;
    x->TestResult = z;
    return;
  case -1:
    y = x->TestResult;
    if (!y) goto add_to_start;
    for (; y->gg.g.n; y = (struct zx_lu_TestResult_s*)y->gg.g.n) ;
    break;
  default:
    for (y = x->TestResult; n > 1 && y; --n, y = (struct zx_lu_TestResult_s*)y->gg.g.n) ;
    if (!y) return;
  }
  z->gg.g.n = y->gg.g.n;
  y->gg.g.n = &z->gg.g;
}

/* FUNC(zx_ps_Notification_DEL_TestResult) */

void zx_ps_Notification_DEL_TestResult(struct zx_ps_Notification_s* x, int n)
{
  struct zx_lu_TestResult_s* y;
  if (!x) return;
  switch (n) {
  case 0:
    x->TestResult = (struct zx_lu_TestResult_s*)x->TestResult->gg.g.n;
    return;
  case -1:
    y = (struct zx_lu_TestResult_s*)x->TestResult;
    if (!y) return;
    for (; y->gg.g.n; y = (struct zx_lu_TestResult_s*)y->gg.g.n) ;
    break;
  default:
    for (y = x->TestResult; n > 1 && y->gg.g.n; --n, y = (struct zx_lu_TestResult_s*)y->gg.g.n) ;
    if (!y->gg.g.n) return;
  }
  y->gg.g.n = y->gg.g.n->n;
}

#endif



#ifdef ZX_ENA_GETPUT

/* FUNC(zx_ps_Notification_NUM_ItemData) */

int zx_ps_Notification_NUM_ItemData(struct zx_ps_Notification_s* x)
{
  struct zx_ps_ItemData_s* y;
  int n = 0;
  if (!x) return 0;
  for (y = x->ItemData; y; ++n, y = (struct zx_ps_ItemData_s*)y->gg.g.n) ;
  return n;
}

/* FUNC(zx_ps_Notification_GET_ItemData) */

struct zx_ps_ItemData_s* zx_ps_Notification_GET_ItemData(struct zx_ps_Notification_s* x, int n)
{
  struct zx_ps_ItemData_s* y;
  if (!x) return 0;
  for (y = x->ItemData; n>=0 && y; --n, y = (struct zx_ps_ItemData_s*)y->gg.g.n) ;
  return y;
}

/* FUNC(zx_ps_Notification_POP_ItemData) */

struct zx_ps_ItemData_s* zx_ps_Notification_POP_ItemData(struct zx_ps_Notification_s* x)
{
  struct zx_ps_ItemData_s* y;
  if (!x) return 0;
  y = x->ItemData;
  if (y)
    x->ItemData = (struct zx_ps_ItemData_s*)y->gg.g.n;
  return y;
}

/* FUNC(zx_ps_Notification_PUSH_ItemData) */

void zx_ps_Notification_PUSH_ItemData(struct zx_ps_Notification_s* x, struct zx_ps_ItemData_s* z)
{
  if (!x || !z) return;
  z->gg.g.n = &x->ItemData->gg.g;
  x->ItemData = z;
}

/* FUNC(zx_ps_Notification_REV_ItemData) */

void zx_ps_Notification_REV_ItemData(struct zx_ps_Notification_s* x)
{
  struct zx_ps_ItemData_s* nxt;
  struct zx_ps_ItemData_s* y;
  if (!x) return;
  y = x->ItemData;
  if (!y) return;
  x->ItemData = 0;
  while (y) {
    nxt = (struct zx_ps_ItemData_s*)y->gg.g.n;
    y->gg.g.n = &x->ItemData->gg.g;
    x->ItemData = y;
    y = nxt;
  }
}

/* FUNC(zx_ps_Notification_PUT_ItemData) */

void zx_ps_Notification_PUT_ItemData(struct zx_ps_Notification_s* x, int n, struct zx_ps_ItemData_s* z)
{
  struct zx_ps_ItemData_s* y;
  if (!x || !z) return;
  y = x->ItemData;
  if (!y) return;
  switch (n) {
  case 0:
    z->gg.g.n = y->gg.g.n;
    x->ItemData = z;
    return;
  default:
    for (; n > 1 && y->gg.g.n; --n, y = (struct zx_ps_ItemData_s*)y->gg.g.n) ;
    if (!y->gg.g.n) return;
    z->gg.g.n = y->gg.g.n->n;
    y->gg.g.n = &z->gg.g;
  }
}

/* FUNC(zx_ps_Notification_ADD_ItemData) */

void zx_ps_Notification_ADD_ItemData(struct zx_ps_Notification_s* x, int n, struct zx_ps_ItemData_s* z)
{
  struct zx_ps_ItemData_s* y;
  if (!x || !z) return;
  switch (n) {
  case 0:
  add_to_start:
    z->gg.g.n = &x->ItemData->gg.g;
    x->ItemData = z;
    return;
  case -1:
    y = x->ItemData;
    if (!y) goto add_to_start;
    for (; y->gg.g.n; y = (struct zx_ps_ItemData_s*)y->gg.g.n) ;
    break;
  default:
    for (y = x->ItemData; n > 1 && y; --n, y = (struct zx_ps_ItemData_s*)y->gg.g.n) ;
    if (!y) return;
  }
  z->gg.g.n = y->gg.g.n;
  y->gg.g.n = &z->gg.g;
}

/* FUNC(zx_ps_Notification_DEL_ItemData) */

void zx_ps_Notification_DEL_ItemData(struct zx_ps_Notification_s* x, int n)
{
  struct zx_ps_ItemData_s* y;
  if (!x) return;
  switch (n) {
  case 0:
    x->ItemData = (struct zx_ps_ItemData_s*)x->ItemData->gg.g.n;
    return;
  case -1:
    y = (struct zx_ps_ItemData_s*)x->ItemData;
    if (!y) return;
    for (; y->gg.g.n; y = (struct zx_ps_ItemData_s*)y->gg.g.n) ;
    break;
  default:
    for (y = x->ItemData; n > 1 && y->gg.g.n; --n, y = (struct zx_ps_ItemData_s*)y->gg.g.n) ;
    if (!y->gg.g.n) return;
  }
  y->gg.g.n = y->gg.g.n->n;
}

#endif

/* FUNC(zx_ps_Notification_GET_endReason) */
struct zx_str* zx_ps_Notification_GET_endReason(struct zx_ps_Notification_s* x) { return x->endReason; }
/* FUNC(zx_ps_Notification_PUT_endReason) */
void zx_ps_Notification_PUT_endReason(struct zx_ps_Notification_s* x, struct zx_str* y) { x->endReason = y; }
/* FUNC(zx_ps_Notification_GET_expires) */
struct zx_str* zx_ps_Notification_GET_expires(struct zx_ps_Notification_s* x) { return x->expires; }
/* FUNC(zx_ps_Notification_PUT_expires) */
void zx_ps_Notification_PUT_expires(struct zx_ps_Notification_s* x, struct zx_str* y) { x->expires = y; }
/* FUNC(zx_ps_Notification_GET_id) */
struct zx_str* zx_ps_Notification_GET_id(struct zx_ps_Notification_s* x) { return x->id; }
/* FUNC(zx_ps_Notification_PUT_id) */
void zx_ps_Notification_PUT_id(struct zx_ps_Notification_s* x, struct zx_str* y) { x->id = y; }
/* FUNC(zx_ps_Notification_GET_subscriptionID) */
struct zx_str* zx_ps_Notification_GET_subscriptionID(struct zx_ps_Notification_s* x) { return x->subscriptionID; }
/* FUNC(zx_ps_Notification_PUT_subscriptionID) */
void zx_ps_Notification_PUT_subscriptionID(struct zx_ps_Notification_s* x, struct zx_str* y) { x->subscriptionID = y; }







#ifdef ZX_ENA_GETPUT

/* FUNC(zx_ps_Notify_NUM_Notification) */

int zx_ps_Notify_NUM_Notification(struct zx_ps_Notify_s* x)
{
  struct zx_ps_Notification_s* y;
  int n = 0;
  if (!x) return 0;
  for (y = x->Notification; y; ++n, y = (struct zx_ps_Notification_s*)y->gg.g.n) ;
  return n;
}

/* FUNC(zx_ps_Notify_GET_Notification) */

struct zx_ps_Notification_s* zx_ps_Notify_GET_Notification(struct zx_ps_Notify_s* x, int n)
{
  struct zx_ps_Notification_s* y;
  if (!x) return 0;
  for (y = x->Notification; n>=0 && y; --n, y = (struct zx_ps_Notification_s*)y->gg.g.n) ;
  return y;
}

/* FUNC(zx_ps_Notify_POP_Notification) */

struct zx_ps_Notification_s* zx_ps_Notify_POP_Notification(struct zx_ps_Notify_s* x)
{
  struct zx_ps_Notification_s* y;
  if (!x) return 0;
  y = x->Notification;
  if (y)
    x->Notification = (struct zx_ps_Notification_s*)y->gg.g.n;
  return y;
}

/* FUNC(zx_ps_Notify_PUSH_Notification) */

void zx_ps_Notify_PUSH_Notification(struct zx_ps_Notify_s* x, struct zx_ps_Notification_s* z)
{
  if (!x || !z) return;
  z->gg.g.n = &x->Notification->gg.g;
  x->Notification = z;
}

/* FUNC(zx_ps_Notify_REV_Notification) */

void zx_ps_Notify_REV_Notification(struct zx_ps_Notify_s* x)
{
  struct zx_ps_Notification_s* nxt;
  struct zx_ps_Notification_s* y;
  if (!x) return;
  y = x->Notification;
  if (!y) return;
  x->Notification = 0;
  while (y) {
    nxt = (struct zx_ps_Notification_s*)y->gg.g.n;
    y->gg.g.n = &x->Notification->gg.g;
    x->Notification = y;
    y = nxt;
  }
}

/* FUNC(zx_ps_Notify_PUT_Notification) */

void zx_ps_Notify_PUT_Notification(struct zx_ps_Notify_s* x, int n, struct zx_ps_Notification_s* z)
{
  struct zx_ps_Notification_s* y;
  if (!x || !z) return;
  y = x->Notification;
  if (!y) return;
  switch (n) {
  case 0:
    z->gg.g.n = y->gg.g.n;
    x->Notification = z;
    return;
  default:
    for (; n > 1 && y->gg.g.n; --n, y = (struct zx_ps_Notification_s*)y->gg.g.n) ;
    if (!y->gg.g.n) return;
    z->gg.g.n = y->gg.g.n->n;
    y->gg.g.n = &z->gg.g;
  }
}

/* FUNC(zx_ps_Notify_ADD_Notification) */

void zx_ps_Notify_ADD_Notification(struct zx_ps_Notify_s* x, int n, struct zx_ps_Notification_s* z)
{
  struct zx_ps_Notification_s* y;
  if (!x || !z) return;
  switch (n) {
  case 0:
  add_to_start:
    z->gg.g.n = &x->Notification->gg.g;
    x->Notification = z;
    return;
  case -1:
    y = x->Notification;
    if (!y) goto add_to_start;
    for (; y->gg.g.n; y = (struct zx_ps_Notification_s*)y->gg.g.n) ;
    break;
  default:
    for (y = x->Notification; n > 1 && y; --n, y = (struct zx_ps_Notification_s*)y->gg.g.n) ;
    if (!y) return;
  }
  z->gg.g.n = y->gg.g.n;
  y->gg.g.n = &z->gg.g;
}

/* FUNC(zx_ps_Notify_DEL_Notification) */

void zx_ps_Notify_DEL_Notification(struct zx_ps_Notify_s* x, int n)
{
  struct zx_ps_Notification_s* y;
  if (!x) return;
  switch (n) {
  case 0:
    x->Notification = (struct zx_ps_Notification_s*)x->Notification->gg.g.n;
    return;
  case -1:
    y = (struct zx_ps_Notification_s*)x->Notification;
    if (!y) return;
    for (; y->gg.g.n; y = (struct zx_ps_Notification_s*)y->gg.g.n) ;
    break;
  default:
    for (y = x->Notification; n > 1 && y->gg.g.n; --n, y = (struct zx_ps_Notification_s*)y->gg.g.n) ;
    if (!y->gg.g.n) return;
  }
  y->gg.g.n = y->gg.g.n->n;
}

#endif

/* FUNC(zx_ps_Notify_GET_id) */
struct zx_str* zx_ps_Notify_GET_id(struct zx_ps_Notify_s* x) { return x->id; }
/* FUNC(zx_ps_Notify_PUT_id) */
void zx_ps_Notify_PUT_id(struct zx_ps_Notify_s* x, struct zx_str* y) { x->id = y; }
/* FUNC(zx_ps_Notify_GET_timeStamp) */
struct zx_str* zx_ps_Notify_GET_timeStamp(struct zx_ps_Notify_s* x) { return x->timeStamp; }
/* FUNC(zx_ps_Notify_PUT_timeStamp) */
void zx_ps_Notify_PUT_timeStamp(struct zx_ps_Notify_s* x, struct zx_str* y) { x->timeStamp = y; }







#ifdef ZX_ENA_GETPUT

/* FUNC(zx_ps_NotifyResponse_NUM_Status) */

int zx_ps_NotifyResponse_NUM_Status(struct zx_ps_NotifyResponse_s* x)
{
  struct zx_lu_Status_s* y;
  int n = 0;
  if (!x) return 0;
  for (y = x->Status; y; ++n, y = (struct zx_lu_Status_s*)y->gg.g.n) ;
  return n;
}

/* FUNC(zx_ps_NotifyResponse_GET_Status) */

struct zx_lu_Status_s* zx_ps_NotifyResponse_GET_Status(struct zx_ps_NotifyResponse_s* x, int n)
{
  struct zx_lu_Status_s* y;
  if (!x) return 0;
  for (y = x->Status; n>=0 && y; --n, y = (struct zx_lu_Status_s*)y->gg.g.n) ;
  return y;
}

/* FUNC(zx_ps_NotifyResponse_POP_Status) */

struct zx_lu_Status_s* zx_ps_NotifyResponse_POP_Status(struct zx_ps_NotifyResponse_s* x)
{
  struct zx_lu_Status_s* y;
  if (!x) return 0;
  y = x->Status;
  if (y)
    x->Status = (struct zx_lu_Status_s*)y->gg.g.n;
  return y;
}

/* FUNC(zx_ps_NotifyResponse_PUSH_Status) */

void zx_ps_NotifyResponse_PUSH_Status(struct zx_ps_NotifyResponse_s* x, struct zx_lu_Status_s* z)
{
  if (!x || !z) return;
  z->gg.g.n = &x->Status->gg.g;
  x->Status = z;
}

/* FUNC(zx_ps_NotifyResponse_REV_Status) */

void zx_ps_NotifyResponse_REV_Status(struct zx_ps_NotifyResponse_s* x)
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

/* FUNC(zx_ps_NotifyResponse_PUT_Status) */

void zx_ps_NotifyResponse_PUT_Status(struct zx_ps_NotifyResponse_s* x, int n, struct zx_lu_Status_s* z)
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

/* FUNC(zx_ps_NotifyResponse_ADD_Status) */

void zx_ps_NotifyResponse_ADD_Status(struct zx_ps_NotifyResponse_s* x, int n, struct zx_lu_Status_s* z)
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

/* FUNC(zx_ps_NotifyResponse_DEL_Status) */

void zx_ps_NotifyResponse_DEL_Status(struct zx_ps_NotifyResponse_s* x, int n)
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



#ifdef ZX_ENA_GETPUT

/* FUNC(zx_ps_NotifyResponse_NUM_Extension) */

int zx_ps_NotifyResponse_NUM_Extension(struct zx_ps_NotifyResponse_s* x)
{
  struct zx_lu_Extension_s* y;
  int n = 0;
  if (!x) return 0;
  for (y = x->Extension; y; ++n, y = (struct zx_lu_Extension_s*)y->gg.g.n) ;
  return n;
}

/* FUNC(zx_ps_NotifyResponse_GET_Extension) */

struct zx_lu_Extension_s* zx_ps_NotifyResponse_GET_Extension(struct zx_ps_NotifyResponse_s* x, int n)
{
  struct zx_lu_Extension_s* y;
  if (!x) return 0;
  for (y = x->Extension; n>=0 && y; --n, y = (struct zx_lu_Extension_s*)y->gg.g.n) ;
  return y;
}

/* FUNC(zx_ps_NotifyResponse_POP_Extension) */

struct zx_lu_Extension_s* zx_ps_NotifyResponse_POP_Extension(struct zx_ps_NotifyResponse_s* x)
{
  struct zx_lu_Extension_s* y;
  if (!x) return 0;
  y = x->Extension;
  if (y)
    x->Extension = (struct zx_lu_Extension_s*)y->gg.g.n;
  return y;
}

/* FUNC(zx_ps_NotifyResponse_PUSH_Extension) */

void zx_ps_NotifyResponse_PUSH_Extension(struct zx_ps_NotifyResponse_s* x, struct zx_lu_Extension_s* z)
{
  if (!x || !z) return;
  z->gg.g.n = &x->Extension->gg.g;
  x->Extension = z;
}

/* FUNC(zx_ps_NotifyResponse_REV_Extension) */

void zx_ps_NotifyResponse_REV_Extension(struct zx_ps_NotifyResponse_s* x)
{
  struct zx_lu_Extension_s* nxt;
  struct zx_lu_Extension_s* y;
  if (!x) return;
  y = x->Extension;
  if (!y) return;
  x->Extension = 0;
  while (y) {
    nxt = (struct zx_lu_Extension_s*)y->gg.g.n;
    y->gg.g.n = &x->Extension->gg.g;
    x->Extension = y;
    y = nxt;
  }
}

/* FUNC(zx_ps_NotifyResponse_PUT_Extension) */

void zx_ps_NotifyResponse_PUT_Extension(struct zx_ps_NotifyResponse_s* x, int n, struct zx_lu_Extension_s* z)
{
  struct zx_lu_Extension_s* y;
  if (!x || !z) return;
  y = x->Extension;
  if (!y) return;
  switch (n) {
  case 0:
    z->gg.g.n = y->gg.g.n;
    x->Extension = z;
    return;
  default:
    for (; n > 1 && y->gg.g.n; --n, y = (struct zx_lu_Extension_s*)y->gg.g.n) ;
    if (!y->gg.g.n) return;
    z->gg.g.n = y->gg.g.n->n;
    y->gg.g.n = &z->gg.g;
  }
}

/* FUNC(zx_ps_NotifyResponse_ADD_Extension) */

void zx_ps_NotifyResponse_ADD_Extension(struct zx_ps_NotifyResponse_s* x, int n, struct zx_lu_Extension_s* z)
{
  struct zx_lu_Extension_s* y;
  if (!x || !z) return;
  switch (n) {
  case 0:
  add_to_start:
    z->gg.g.n = &x->Extension->gg.g;
    x->Extension = z;
    return;
  case -1:
    y = x->Extension;
    if (!y) goto add_to_start;
    for (; y->gg.g.n; y = (struct zx_lu_Extension_s*)y->gg.g.n) ;
    break;
  default:
    for (y = x->Extension; n > 1 && y; --n, y = (struct zx_lu_Extension_s*)y->gg.g.n) ;
    if (!y) return;
  }
  z->gg.g.n = y->gg.g.n;
  y->gg.g.n = &z->gg.g;
}

/* FUNC(zx_ps_NotifyResponse_DEL_Extension) */

void zx_ps_NotifyResponse_DEL_Extension(struct zx_ps_NotifyResponse_s* x, int n)
{
  struct zx_lu_Extension_s* y;
  if (!x) return;
  switch (n) {
  case 0:
    x->Extension = (struct zx_lu_Extension_s*)x->Extension->gg.g.n;
    return;
  case -1:
    y = (struct zx_lu_Extension_s*)x->Extension;
    if (!y) return;
    for (; y->gg.g.n; y = (struct zx_lu_Extension_s*)y->gg.g.n) ;
    break;
  default:
    for (y = x->Extension; n > 1 && y->gg.g.n; --n, y = (struct zx_lu_Extension_s*)y->gg.g.n) ;
    if (!y->gg.g.n) return;
  }
  y->gg.g.n = y->gg.g.n->n;
}

#endif

/* FUNC(zx_ps_NotifyResponse_GET_itemIDRef) */
struct zx_str* zx_ps_NotifyResponse_GET_itemIDRef(struct zx_ps_NotifyResponse_s* x) { return x->itemIDRef; }
/* FUNC(zx_ps_NotifyResponse_PUT_itemIDRef) */
void zx_ps_NotifyResponse_PUT_itemIDRef(struct zx_ps_NotifyResponse_s* x, struct zx_str* y) { x->itemIDRef = y; }







#ifdef ZX_ENA_GETPUT

/* FUNC(zx_ps_Object_NUM_ObjectID) */

int zx_ps_Object_NUM_ObjectID(struct zx_ps_Object_s* x)
{
  struct zx_elem_s* y;
  int n = 0;
  if (!x) return 0;
  for (y = x->ObjectID; y; ++n, y = (struct zx_elem_s*)y->g.n) ;
  return n;
}

/* FUNC(zx_ps_Object_GET_ObjectID) */

struct zx_elem_s* zx_ps_Object_GET_ObjectID(struct zx_ps_Object_s* x, int n)
{
  struct zx_elem_s* y;
  if (!x) return 0;
  for (y = x->ObjectID; n>=0 && y; --n, y = (struct zx_elem_s*)y->g.n) ;
  return y;
}

/* FUNC(zx_ps_Object_POP_ObjectID) */

struct zx_elem_s* zx_ps_Object_POP_ObjectID(struct zx_ps_Object_s* x)
{
  struct zx_elem_s* y;
  if (!x) return 0;
  y = x->ObjectID;
  if (y)
    x->ObjectID = (struct zx_elem_s*)y->g.n;
  return y;
}

/* FUNC(zx_ps_Object_PUSH_ObjectID) */

void zx_ps_Object_PUSH_ObjectID(struct zx_ps_Object_s* x, struct zx_elem_s* z)
{
  if (!x || !z) return;
  z->g.n = &x->ObjectID->g;
  x->ObjectID = z;
}

/* FUNC(zx_ps_Object_REV_ObjectID) */

void zx_ps_Object_REV_ObjectID(struct zx_ps_Object_s* x)
{
  struct zx_elem_s* nxt;
  struct zx_elem_s* y;
  if (!x) return;
  y = x->ObjectID;
  if (!y) return;
  x->ObjectID = 0;
  while (y) {
    nxt = (struct zx_elem_s*)y->g.n;
    y->g.n = &x->ObjectID->g;
    x->ObjectID = y;
    y = nxt;
  }
}

/* FUNC(zx_ps_Object_PUT_ObjectID) */

void zx_ps_Object_PUT_ObjectID(struct zx_ps_Object_s* x, int n, struct zx_elem_s* z)
{
  struct zx_elem_s* y;
  if (!x || !z) return;
  y = x->ObjectID;
  if (!y) return;
  switch (n) {
  case 0:
    z->g.n = y->g.n;
    x->ObjectID = z;
    return;
  default:
    for (; n > 1 && y->g.n; --n, y = (struct zx_elem_s*)y->g.n) ;
    if (!y->g.n) return;
    z->g.n = y->g.n->n;
    y->g.n = &z->g;
  }
}

/* FUNC(zx_ps_Object_ADD_ObjectID) */

void zx_ps_Object_ADD_ObjectID(struct zx_ps_Object_s* x, int n, struct zx_elem_s* z)
{
  struct zx_elem_s* y;
  if (!x || !z) return;
  switch (n) {
  case 0:
  add_to_start:
    z->g.n = &x->ObjectID->g;
    x->ObjectID = z;
    return;
  case -1:
    y = x->ObjectID;
    if (!y) goto add_to_start;
    for (; y->g.n; y = (struct zx_elem_s*)y->g.n) ;
    break;
  default:
    for (y = x->ObjectID; n > 1 && y; --n, y = (struct zx_elem_s*)y->g.n) ;
    if (!y) return;
  }
  z->g.n = y->g.n;
  y->g.n = &z->g;
}

/* FUNC(zx_ps_Object_DEL_ObjectID) */

void zx_ps_Object_DEL_ObjectID(struct zx_ps_Object_s* x, int n)
{
  struct zx_elem_s* y;
  if (!x) return;
  switch (n) {
  case 0:
    x->ObjectID = (struct zx_elem_s*)x->ObjectID->g.n;
    return;
  case -1:
    y = (struct zx_elem_s*)x->ObjectID;
    if (!y) return;
    for (; y->g.n; y = (struct zx_elem_s*)y->g.n) ;
    break;
  default:
    for (y = x->ObjectID; n > 1 && y->g.n; --n, y = (struct zx_elem_s*)y->g.n) ;
    if (!y->g.n) return;
  }
  y->g.n = y->g.n->n;
}

#endif



#ifdef ZX_ENA_GETPUT

/* FUNC(zx_ps_Object_NUM_DisplayName) */

int zx_ps_Object_NUM_DisplayName(struct zx_ps_Object_s* x)
{
  struct zx_ps_DisplayName_s* y;
  int n = 0;
  if (!x) return 0;
  for (y = x->DisplayName; y; ++n, y = (struct zx_ps_DisplayName_s*)y->gg.g.n) ;
  return n;
}

/* FUNC(zx_ps_Object_GET_DisplayName) */

struct zx_ps_DisplayName_s* zx_ps_Object_GET_DisplayName(struct zx_ps_Object_s* x, int n)
{
  struct zx_ps_DisplayName_s* y;
  if (!x) return 0;
  for (y = x->DisplayName; n>=0 && y; --n, y = (struct zx_ps_DisplayName_s*)y->gg.g.n) ;
  return y;
}

/* FUNC(zx_ps_Object_POP_DisplayName) */

struct zx_ps_DisplayName_s* zx_ps_Object_POP_DisplayName(struct zx_ps_Object_s* x)
{
  struct zx_ps_DisplayName_s* y;
  if (!x) return 0;
  y = x->DisplayName;
  if (y)
    x->DisplayName = (struct zx_ps_DisplayName_s*)y->gg.g.n;
  return y;
}

/* FUNC(zx_ps_Object_PUSH_DisplayName) */

void zx_ps_Object_PUSH_DisplayName(struct zx_ps_Object_s* x, struct zx_ps_DisplayName_s* z)
{
  if (!x || !z) return;
  z->gg.g.n = &x->DisplayName->gg.g;
  x->DisplayName = z;
}

/* FUNC(zx_ps_Object_REV_DisplayName) */

void zx_ps_Object_REV_DisplayName(struct zx_ps_Object_s* x)
{
  struct zx_ps_DisplayName_s* nxt;
  struct zx_ps_DisplayName_s* y;
  if (!x) return;
  y = x->DisplayName;
  if (!y) return;
  x->DisplayName = 0;
  while (y) {
    nxt = (struct zx_ps_DisplayName_s*)y->gg.g.n;
    y->gg.g.n = &x->DisplayName->gg.g;
    x->DisplayName = y;
    y = nxt;
  }
}

/* FUNC(zx_ps_Object_PUT_DisplayName) */

void zx_ps_Object_PUT_DisplayName(struct zx_ps_Object_s* x, int n, struct zx_ps_DisplayName_s* z)
{
  struct zx_ps_DisplayName_s* y;
  if (!x || !z) return;
  y = x->DisplayName;
  if (!y) return;
  switch (n) {
  case 0:
    z->gg.g.n = y->gg.g.n;
    x->DisplayName = z;
    return;
  default:
    for (; n > 1 && y->gg.g.n; --n, y = (struct zx_ps_DisplayName_s*)y->gg.g.n) ;
    if (!y->gg.g.n) return;
    z->gg.g.n = y->gg.g.n->n;
    y->gg.g.n = &z->gg.g;
  }
}

/* FUNC(zx_ps_Object_ADD_DisplayName) */

void zx_ps_Object_ADD_DisplayName(struct zx_ps_Object_s* x, int n, struct zx_ps_DisplayName_s* z)
{
  struct zx_ps_DisplayName_s* y;
  if (!x || !z) return;
  switch (n) {
  case 0:
  add_to_start:
    z->gg.g.n = &x->DisplayName->gg.g;
    x->DisplayName = z;
    return;
  case -1:
    y = x->DisplayName;
    if (!y) goto add_to_start;
    for (; y->gg.g.n; y = (struct zx_ps_DisplayName_s*)y->gg.g.n) ;
    break;
  default:
    for (y = x->DisplayName; n > 1 && y; --n, y = (struct zx_ps_DisplayName_s*)y->gg.g.n) ;
    if (!y) return;
  }
  z->gg.g.n = y->gg.g.n;
  y->gg.g.n = &z->gg.g;
}

/* FUNC(zx_ps_Object_DEL_DisplayName) */

void zx_ps_Object_DEL_DisplayName(struct zx_ps_Object_s* x, int n)
{
  struct zx_ps_DisplayName_s* y;
  if (!x) return;
  switch (n) {
  case 0:
    x->DisplayName = (struct zx_ps_DisplayName_s*)x->DisplayName->gg.g.n;
    return;
  case -1:
    y = (struct zx_ps_DisplayName_s*)x->DisplayName;
    if (!y) return;
    for (; y->gg.g.n; y = (struct zx_ps_DisplayName_s*)y->gg.g.n) ;
    break;
  default:
    for (y = x->DisplayName; n > 1 && y->gg.g.n; --n, y = (struct zx_ps_DisplayName_s*)y->gg.g.n) ;
    if (!y->gg.g.n) return;
  }
  y->gg.g.n = y->gg.g.n->n;
}

#endif



#ifdef ZX_ENA_GETPUT

/* FUNC(zx_ps_Object_NUM_Tag) */

int zx_ps_Object_NUM_Tag(struct zx_ps_Object_s* x)
{
  struct zx_ps_Tag_s* y;
  int n = 0;
  if (!x) return 0;
  for (y = x->Tag; y; ++n, y = (struct zx_ps_Tag_s*)y->gg.g.n) ;
  return n;
}

/* FUNC(zx_ps_Object_GET_Tag) */

struct zx_ps_Tag_s* zx_ps_Object_GET_Tag(struct zx_ps_Object_s* x, int n)
{
  struct zx_ps_Tag_s* y;
  if (!x) return 0;
  for (y = x->Tag; n>=0 && y; --n, y = (struct zx_ps_Tag_s*)y->gg.g.n) ;
  return y;
}

/* FUNC(zx_ps_Object_POP_Tag) */

struct zx_ps_Tag_s* zx_ps_Object_POP_Tag(struct zx_ps_Object_s* x)
{
  struct zx_ps_Tag_s* y;
  if (!x) return 0;
  y = x->Tag;
  if (y)
    x->Tag = (struct zx_ps_Tag_s*)y->gg.g.n;
  return y;
}

/* FUNC(zx_ps_Object_PUSH_Tag) */

void zx_ps_Object_PUSH_Tag(struct zx_ps_Object_s* x, struct zx_ps_Tag_s* z)
{
  if (!x || !z) return;
  z->gg.g.n = &x->Tag->gg.g;
  x->Tag = z;
}

/* FUNC(zx_ps_Object_REV_Tag) */

void zx_ps_Object_REV_Tag(struct zx_ps_Object_s* x)
{
  struct zx_ps_Tag_s* nxt;
  struct zx_ps_Tag_s* y;
  if (!x) return;
  y = x->Tag;
  if (!y) return;
  x->Tag = 0;
  while (y) {
    nxt = (struct zx_ps_Tag_s*)y->gg.g.n;
    y->gg.g.n = &x->Tag->gg.g;
    x->Tag = y;
    y = nxt;
  }
}

/* FUNC(zx_ps_Object_PUT_Tag) */

void zx_ps_Object_PUT_Tag(struct zx_ps_Object_s* x, int n, struct zx_ps_Tag_s* z)
{
  struct zx_ps_Tag_s* y;
  if (!x || !z) return;
  y = x->Tag;
  if (!y) return;
  switch (n) {
  case 0:
    z->gg.g.n = y->gg.g.n;
    x->Tag = z;
    return;
  default:
    for (; n > 1 && y->gg.g.n; --n, y = (struct zx_ps_Tag_s*)y->gg.g.n) ;
    if (!y->gg.g.n) return;
    z->gg.g.n = y->gg.g.n->n;
    y->gg.g.n = &z->gg.g;
  }
}

/* FUNC(zx_ps_Object_ADD_Tag) */

void zx_ps_Object_ADD_Tag(struct zx_ps_Object_s* x, int n, struct zx_ps_Tag_s* z)
{
  struct zx_ps_Tag_s* y;
  if (!x || !z) return;
  switch (n) {
  case 0:
  add_to_start:
    z->gg.g.n = &x->Tag->gg.g;
    x->Tag = z;
    return;
  case -1:
    y = x->Tag;
    if (!y) goto add_to_start;
    for (; y->gg.g.n; y = (struct zx_ps_Tag_s*)y->gg.g.n) ;
    break;
  default:
    for (y = x->Tag; n > 1 && y; --n, y = (struct zx_ps_Tag_s*)y->gg.g.n) ;
    if (!y) return;
  }
  z->gg.g.n = y->gg.g.n;
  y->gg.g.n = &z->gg.g;
}

/* FUNC(zx_ps_Object_DEL_Tag) */

void zx_ps_Object_DEL_Tag(struct zx_ps_Object_s* x, int n)
{
  struct zx_ps_Tag_s* y;
  if (!x) return;
  switch (n) {
  case 0:
    x->Tag = (struct zx_ps_Tag_s*)x->Tag->gg.g.n;
    return;
  case -1:
    y = (struct zx_ps_Tag_s*)x->Tag;
    if (!y) return;
    for (; y->gg.g.n; y = (struct zx_ps_Tag_s*)y->gg.g.n) ;
    break;
  default:
    for (y = x->Tag; n > 1 && y->gg.g.n; --n, y = (struct zx_ps_Tag_s*)y->gg.g.n) ;
    if (!y->gg.g.n) return;
  }
  y->gg.g.n = y->gg.g.n->n;
}

#endif



#ifdef ZX_ENA_GETPUT

/* FUNC(zx_ps_Object_NUM_Object) */

int zx_ps_Object_NUM_Object(struct zx_ps_Object_s* x)
{
  struct zx_ps_Object_s* y;
  int n = 0;
  if (!x) return 0;
  for (y = x->Object; y; ++n, y = (struct zx_ps_Object_s*)y->gg.g.n) ;
  return n;
}

/* FUNC(zx_ps_Object_GET_Object) */

struct zx_ps_Object_s* zx_ps_Object_GET_Object(struct zx_ps_Object_s* x, int n)
{
  struct zx_ps_Object_s* y;
  if (!x) return 0;
  for (y = x->Object; n>=0 && y; --n, y = (struct zx_ps_Object_s*)y->gg.g.n) ;
  return y;
}

/* FUNC(zx_ps_Object_POP_Object) */

struct zx_ps_Object_s* zx_ps_Object_POP_Object(struct zx_ps_Object_s* x)
{
  struct zx_ps_Object_s* y;
  if (!x) return 0;
  y = x->Object;
  if (y)
    x->Object = (struct zx_ps_Object_s*)y->gg.g.n;
  return y;
}

/* FUNC(zx_ps_Object_PUSH_Object) */

void zx_ps_Object_PUSH_Object(struct zx_ps_Object_s* x, struct zx_ps_Object_s* z)
{
  if (!x || !z) return;
  z->gg.g.n = &x->Object->gg.g;
  x->Object = z;
}

/* FUNC(zx_ps_Object_REV_Object) */

void zx_ps_Object_REV_Object(struct zx_ps_Object_s* x)
{
  struct zx_ps_Object_s* nxt;
  struct zx_ps_Object_s* y;
  if (!x) return;
  y = x->Object;
  if (!y) return;
  x->Object = 0;
  while (y) {
    nxt = (struct zx_ps_Object_s*)y->gg.g.n;
    y->gg.g.n = &x->Object->gg.g;
    x->Object = y;
    y = nxt;
  }
}

/* FUNC(zx_ps_Object_PUT_Object) */

void zx_ps_Object_PUT_Object(struct zx_ps_Object_s* x, int n, struct zx_ps_Object_s* z)
{
  struct zx_ps_Object_s* y;
  if (!x || !z) return;
  y = x->Object;
  if (!y) return;
  switch (n) {
  case 0:
    z->gg.g.n = y->gg.g.n;
    x->Object = z;
    return;
  default:
    for (; n > 1 && y->gg.g.n; --n, y = (struct zx_ps_Object_s*)y->gg.g.n) ;
    if (!y->gg.g.n) return;
    z->gg.g.n = y->gg.g.n->n;
    y->gg.g.n = &z->gg.g;
  }
}

/* FUNC(zx_ps_Object_ADD_Object) */

void zx_ps_Object_ADD_Object(struct zx_ps_Object_s* x, int n, struct zx_ps_Object_s* z)
{
  struct zx_ps_Object_s* y;
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
    for (; y->gg.g.n; y = (struct zx_ps_Object_s*)y->gg.g.n) ;
    break;
  default:
    for (y = x->Object; n > 1 && y; --n, y = (struct zx_ps_Object_s*)y->gg.g.n) ;
    if (!y) return;
  }
  z->gg.g.n = y->gg.g.n;
  y->gg.g.n = &z->gg.g;
}

/* FUNC(zx_ps_Object_DEL_Object) */

void zx_ps_Object_DEL_Object(struct zx_ps_Object_s* x, int n)
{
  struct zx_ps_Object_s* y;
  if (!x) return;
  switch (n) {
  case 0:
    x->Object = (struct zx_ps_Object_s*)x->Object->gg.g.n;
    return;
  case -1:
    y = (struct zx_ps_Object_s*)x->Object;
    if (!y) return;
    for (; y->gg.g.n; y = (struct zx_ps_Object_s*)y->gg.g.n) ;
    break;
  default:
    for (y = x->Object; n > 1 && y->gg.g.n; --n, y = (struct zx_ps_Object_s*)y->gg.g.n) ;
    if (!y->gg.g.n) return;
  }
  y->gg.g.n = y->gg.g.n->n;
}

#endif



#ifdef ZX_ENA_GETPUT

/* FUNC(zx_ps_Object_NUM_ObjectRef) */

int zx_ps_Object_NUM_ObjectRef(struct zx_ps_Object_s* x)
{
  struct zx_elem_s* y;
  int n = 0;
  if (!x) return 0;
  for (y = x->ObjectRef; y; ++n, y = (struct zx_elem_s*)y->g.n) ;
  return n;
}

/* FUNC(zx_ps_Object_GET_ObjectRef) */

struct zx_elem_s* zx_ps_Object_GET_ObjectRef(struct zx_ps_Object_s* x, int n)
{
  struct zx_elem_s* y;
  if (!x) return 0;
  for (y = x->ObjectRef; n>=0 && y; --n, y = (struct zx_elem_s*)y->g.n) ;
  return y;
}

/* FUNC(zx_ps_Object_POP_ObjectRef) */

struct zx_elem_s* zx_ps_Object_POP_ObjectRef(struct zx_ps_Object_s* x)
{
  struct zx_elem_s* y;
  if (!x) return 0;
  y = x->ObjectRef;
  if (y)
    x->ObjectRef = (struct zx_elem_s*)y->g.n;
  return y;
}

/* FUNC(zx_ps_Object_PUSH_ObjectRef) */

void zx_ps_Object_PUSH_ObjectRef(struct zx_ps_Object_s* x, struct zx_elem_s* z)
{
  if (!x || !z) return;
  z->g.n = &x->ObjectRef->g;
  x->ObjectRef = z;
}

/* FUNC(zx_ps_Object_REV_ObjectRef) */

void zx_ps_Object_REV_ObjectRef(struct zx_ps_Object_s* x)
{
  struct zx_elem_s* nxt;
  struct zx_elem_s* y;
  if (!x) return;
  y = x->ObjectRef;
  if (!y) return;
  x->ObjectRef = 0;
  while (y) {
    nxt = (struct zx_elem_s*)y->g.n;
    y->g.n = &x->ObjectRef->g;
    x->ObjectRef = y;
    y = nxt;
  }
}

/* FUNC(zx_ps_Object_PUT_ObjectRef) */

void zx_ps_Object_PUT_ObjectRef(struct zx_ps_Object_s* x, int n, struct zx_elem_s* z)
{
  struct zx_elem_s* y;
  if (!x || !z) return;
  y = x->ObjectRef;
  if (!y) return;
  switch (n) {
  case 0:
    z->g.n = y->g.n;
    x->ObjectRef = z;
    return;
  default:
    for (; n > 1 && y->g.n; --n, y = (struct zx_elem_s*)y->g.n) ;
    if (!y->g.n) return;
    z->g.n = y->g.n->n;
    y->g.n = &z->g;
  }
}

/* FUNC(zx_ps_Object_ADD_ObjectRef) */

void zx_ps_Object_ADD_ObjectRef(struct zx_ps_Object_s* x, int n, struct zx_elem_s* z)
{
  struct zx_elem_s* y;
  if (!x || !z) return;
  switch (n) {
  case 0:
  add_to_start:
    z->g.n = &x->ObjectRef->g;
    x->ObjectRef = z;
    return;
  case -1:
    y = x->ObjectRef;
    if (!y) goto add_to_start;
    for (; y->g.n; y = (struct zx_elem_s*)y->g.n) ;
    break;
  default:
    for (y = x->ObjectRef; n > 1 && y; --n, y = (struct zx_elem_s*)y->g.n) ;
    if (!y) return;
  }
  z->g.n = y->g.n;
  y->g.n = &z->g;
}

/* FUNC(zx_ps_Object_DEL_ObjectRef) */

void zx_ps_Object_DEL_ObjectRef(struct zx_ps_Object_s* x, int n)
{
  struct zx_elem_s* y;
  if (!x) return;
  switch (n) {
  case 0:
    x->ObjectRef = (struct zx_elem_s*)x->ObjectRef->g.n;
    return;
  case -1:
    y = (struct zx_elem_s*)x->ObjectRef;
    if (!y) return;
    for (; y->g.n; y = (struct zx_elem_s*)y->g.n) ;
    break;
  default:
    for (y = x->ObjectRef; n > 1 && y->g.n; --n, y = (struct zx_elem_s*)y->g.n) ;
    if (!y->g.n) return;
  }
  y->g.n = y->g.n->n;
}

#endif

/* FUNC(zx_ps_Object_GET_CreatedDateTime) */
struct zx_str* zx_ps_Object_GET_CreatedDateTime(struct zx_ps_Object_s* x) { return x->CreatedDateTime; }
/* FUNC(zx_ps_Object_PUT_CreatedDateTime) */
void zx_ps_Object_PUT_CreatedDateTime(struct zx_ps_Object_s* x, struct zx_str* y) { x->CreatedDateTime = y; }
/* FUNC(zx_ps_Object_GET_ModifiedDateTime) */
struct zx_str* zx_ps_Object_GET_ModifiedDateTime(struct zx_ps_Object_s* x) { return x->ModifiedDateTime; }
/* FUNC(zx_ps_Object_PUT_ModifiedDateTime) */
void zx_ps_Object_PUT_ModifiedDateTime(struct zx_ps_Object_s* x, struct zx_str* y) { x->ModifiedDateTime = y; }
/* FUNC(zx_ps_Object_GET_NodeType) */
struct zx_str* zx_ps_Object_GET_NodeType(struct zx_ps_Object_s* x) { return x->NodeType; }
/* FUNC(zx_ps_Object_PUT_NodeType) */
void zx_ps_Object_PUT_NodeType(struct zx_ps_Object_s* x, struct zx_str* y) { x->NodeType = y; }







#ifdef ZX_ENA_GETPUT

/* FUNC(zx_ps_QueryObjectsRequest_NUM_Filter) */

int zx_ps_QueryObjectsRequest_NUM_Filter(struct zx_ps_QueryObjectsRequest_s* x)
{
  struct zx_elem_s* y;
  int n = 0;
  if (!x) return 0;
  for (y = x->Filter; y; ++n, y = (struct zx_elem_s*)y->g.n) ;
  return n;
}

/* FUNC(zx_ps_QueryObjectsRequest_GET_Filter) */

struct zx_elem_s* zx_ps_QueryObjectsRequest_GET_Filter(struct zx_ps_QueryObjectsRequest_s* x, int n)
{
  struct zx_elem_s* y;
  if (!x) return 0;
  for (y = x->Filter; n>=0 && y; --n, y = (struct zx_elem_s*)y->g.n) ;
  return y;
}

/* FUNC(zx_ps_QueryObjectsRequest_POP_Filter) */

struct zx_elem_s* zx_ps_QueryObjectsRequest_POP_Filter(struct zx_ps_QueryObjectsRequest_s* x)
{
  struct zx_elem_s* y;
  if (!x) return 0;
  y = x->Filter;
  if (y)
    x->Filter = (struct zx_elem_s*)y->g.n;
  return y;
}

/* FUNC(zx_ps_QueryObjectsRequest_PUSH_Filter) */

void zx_ps_QueryObjectsRequest_PUSH_Filter(struct zx_ps_QueryObjectsRequest_s* x, struct zx_elem_s* z)
{
  if (!x || !z) return;
  z->g.n = &x->Filter->g;
  x->Filter = z;
}

/* FUNC(zx_ps_QueryObjectsRequest_REV_Filter) */

void zx_ps_QueryObjectsRequest_REV_Filter(struct zx_ps_QueryObjectsRequest_s* x)
{
  struct zx_elem_s* nxt;
  struct zx_elem_s* y;
  if (!x) return;
  y = x->Filter;
  if (!y) return;
  x->Filter = 0;
  while (y) {
    nxt = (struct zx_elem_s*)y->g.n;
    y->g.n = &x->Filter->g;
    x->Filter = y;
    y = nxt;
  }
}

/* FUNC(zx_ps_QueryObjectsRequest_PUT_Filter) */

void zx_ps_QueryObjectsRequest_PUT_Filter(struct zx_ps_QueryObjectsRequest_s* x, int n, struct zx_elem_s* z)
{
  struct zx_elem_s* y;
  if (!x || !z) return;
  y = x->Filter;
  if (!y) return;
  switch (n) {
  case 0:
    z->g.n = y->g.n;
    x->Filter = z;
    return;
  default:
    for (; n > 1 && y->g.n; --n, y = (struct zx_elem_s*)y->g.n) ;
    if (!y->g.n) return;
    z->g.n = y->g.n->n;
    y->g.n = &z->g;
  }
}

/* FUNC(zx_ps_QueryObjectsRequest_ADD_Filter) */

void zx_ps_QueryObjectsRequest_ADD_Filter(struct zx_ps_QueryObjectsRequest_s* x, int n, struct zx_elem_s* z)
{
  struct zx_elem_s* y;
  if (!x || !z) return;
  switch (n) {
  case 0:
  add_to_start:
    z->g.n = &x->Filter->g;
    x->Filter = z;
    return;
  case -1:
    y = x->Filter;
    if (!y) goto add_to_start;
    for (; y->g.n; y = (struct zx_elem_s*)y->g.n) ;
    break;
  default:
    for (y = x->Filter; n > 1 && y; --n, y = (struct zx_elem_s*)y->g.n) ;
    if (!y) return;
  }
  z->g.n = y->g.n;
  y->g.n = &z->g;
}

/* FUNC(zx_ps_QueryObjectsRequest_DEL_Filter) */

void zx_ps_QueryObjectsRequest_DEL_Filter(struct zx_ps_QueryObjectsRequest_s* x, int n)
{
  struct zx_elem_s* y;
  if (!x) return;
  switch (n) {
  case 0:
    x->Filter = (struct zx_elem_s*)x->Filter->g.n;
    return;
  case -1:
    y = (struct zx_elem_s*)x->Filter;
    if (!y) return;
    for (; y->g.n; y = (struct zx_elem_s*)y->g.n) ;
    break;
  default:
    for (y = x->Filter; n > 1 && y->g.n; --n, y = (struct zx_elem_s*)y->g.n) ;
    if (!y->g.n) return;
  }
  y->g.n = y->g.n->n;
}

#endif



#ifdef ZX_ENA_GETPUT

/* FUNC(zx_ps_QueryObjectsRequest_NUM_Subscription) */

int zx_ps_QueryObjectsRequest_NUM_Subscription(struct zx_ps_QueryObjectsRequest_s* x)
{
  struct zx_ps_Subscription_s* y;
  int n = 0;
  if (!x) return 0;
  for (y = x->Subscription; y; ++n, y = (struct zx_ps_Subscription_s*)y->gg.g.n) ;
  return n;
}

/* FUNC(zx_ps_QueryObjectsRequest_GET_Subscription) */

struct zx_ps_Subscription_s* zx_ps_QueryObjectsRequest_GET_Subscription(struct zx_ps_QueryObjectsRequest_s* x, int n)
{
  struct zx_ps_Subscription_s* y;
  if (!x) return 0;
  for (y = x->Subscription; n>=0 && y; --n, y = (struct zx_ps_Subscription_s*)y->gg.g.n) ;
  return y;
}

/* FUNC(zx_ps_QueryObjectsRequest_POP_Subscription) */

struct zx_ps_Subscription_s* zx_ps_QueryObjectsRequest_POP_Subscription(struct zx_ps_QueryObjectsRequest_s* x)
{
  struct zx_ps_Subscription_s* y;
  if (!x) return 0;
  y = x->Subscription;
  if (y)
    x->Subscription = (struct zx_ps_Subscription_s*)y->gg.g.n;
  return y;
}

/* FUNC(zx_ps_QueryObjectsRequest_PUSH_Subscription) */

void zx_ps_QueryObjectsRequest_PUSH_Subscription(struct zx_ps_QueryObjectsRequest_s* x, struct zx_ps_Subscription_s* z)
{
  if (!x || !z) return;
  z->gg.g.n = &x->Subscription->gg.g;
  x->Subscription = z;
}

/* FUNC(zx_ps_QueryObjectsRequest_REV_Subscription) */

void zx_ps_QueryObjectsRequest_REV_Subscription(struct zx_ps_QueryObjectsRequest_s* x)
{
  struct zx_ps_Subscription_s* nxt;
  struct zx_ps_Subscription_s* y;
  if (!x) return;
  y = x->Subscription;
  if (!y) return;
  x->Subscription = 0;
  while (y) {
    nxt = (struct zx_ps_Subscription_s*)y->gg.g.n;
    y->gg.g.n = &x->Subscription->gg.g;
    x->Subscription = y;
    y = nxt;
  }
}

/* FUNC(zx_ps_QueryObjectsRequest_PUT_Subscription) */

void zx_ps_QueryObjectsRequest_PUT_Subscription(struct zx_ps_QueryObjectsRequest_s* x, int n, struct zx_ps_Subscription_s* z)
{
  struct zx_ps_Subscription_s* y;
  if (!x || !z) return;
  y = x->Subscription;
  if (!y) return;
  switch (n) {
  case 0:
    z->gg.g.n = y->gg.g.n;
    x->Subscription = z;
    return;
  default:
    for (; n > 1 && y->gg.g.n; --n, y = (struct zx_ps_Subscription_s*)y->gg.g.n) ;
    if (!y->gg.g.n) return;
    z->gg.g.n = y->gg.g.n->n;
    y->gg.g.n = &z->gg.g;
  }
}

/* FUNC(zx_ps_QueryObjectsRequest_ADD_Subscription) */

void zx_ps_QueryObjectsRequest_ADD_Subscription(struct zx_ps_QueryObjectsRequest_s* x, int n, struct zx_ps_Subscription_s* z)
{
  struct zx_ps_Subscription_s* y;
  if (!x || !z) return;
  switch (n) {
  case 0:
  add_to_start:
    z->gg.g.n = &x->Subscription->gg.g;
    x->Subscription = z;
    return;
  case -1:
    y = x->Subscription;
    if (!y) goto add_to_start;
    for (; y->gg.g.n; y = (struct zx_ps_Subscription_s*)y->gg.g.n) ;
    break;
  default:
    for (y = x->Subscription; n > 1 && y; --n, y = (struct zx_ps_Subscription_s*)y->gg.g.n) ;
    if (!y) return;
  }
  z->gg.g.n = y->gg.g.n;
  y->gg.g.n = &z->gg.g;
}

/* FUNC(zx_ps_QueryObjectsRequest_DEL_Subscription) */

void zx_ps_QueryObjectsRequest_DEL_Subscription(struct zx_ps_QueryObjectsRequest_s* x, int n)
{
  struct zx_ps_Subscription_s* y;
  if (!x) return;
  switch (n) {
  case 0:
    x->Subscription = (struct zx_ps_Subscription_s*)x->Subscription->gg.g.n;
    return;
  case -1:
    y = (struct zx_ps_Subscription_s*)x->Subscription;
    if (!y) return;
    for (; y->gg.g.n; y = (struct zx_ps_Subscription_s*)y->gg.g.n) ;
    break;
  default:
    for (y = x->Subscription; n > 1 && y->gg.g.n; --n, y = (struct zx_ps_Subscription_s*)y->gg.g.n) ;
    if (!y->gg.g.n) return;
  }
  y->gg.g.n = y->gg.g.n->n;
}

#endif

/* FUNC(zx_ps_QueryObjectsRequest_GET_Count) */
struct zx_str* zx_ps_QueryObjectsRequest_GET_Count(struct zx_ps_QueryObjectsRequest_s* x) { return x->Count; }
/* FUNC(zx_ps_QueryObjectsRequest_PUT_Count) */
void zx_ps_QueryObjectsRequest_PUT_Count(struct zx_ps_QueryObjectsRequest_s* x, struct zx_str* y) { x->Count = y; }
/* FUNC(zx_ps_QueryObjectsRequest_GET_Offset) */
struct zx_str* zx_ps_QueryObjectsRequest_GET_Offset(struct zx_ps_QueryObjectsRequest_s* x) { return x->Offset; }
/* FUNC(zx_ps_QueryObjectsRequest_PUT_Offset) */
void zx_ps_QueryObjectsRequest_PUT_Offset(struct zx_ps_QueryObjectsRequest_s* x, struct zx_str* y) { x->Offset = y; }
/* FUNC(zx_ps_QueryObjectsRequest_GET_id) */
struct zx_str* zx_ps_QueryObjectsRequest_GET_id(struct zx_ps_QueryObjectsRequest_s* x) { return x->id; }
/* FUNC(zx_ps_QueryObjectsRequest_PUT_id) */
void zx_ps_QueryObjectsRequest_PUT_id(struct zx_ps_QueryObjectsRequest_s* x, struct zx_str* y) { x->id = y; }







#ifdef ZX_ENA_GETPUT

/* FUNC(zx_ps_QueryObjectsResponse_NUM_Status) */

int zx_ps_QueryObjectsResponse_NUM_Status(struct zx_ps_QueryObjectsResponse_s* x)
{
  struct zx_lu_Status_s* y;
  int n = 0;
  if (!x) return 0;
  for (y = x->Status; y; ++n, y = (struct zx_lu_Status_s*)y->gg.g.n) ;
  return n;
}

/* FUNC(zx_ps_QueryObjectsResponse_GET_Status) */

struct zx_lu_Status_s* zx_ps_QueryObjectsResponse_GET_Status(struct zx_ps_QueryObjectsResponse_s* x, int n)
{
  struct zx_lu_Status_s* y;
  if (!x) return 0;
  for (y = x->Status; n>=0 && y; --n, y = (struct zx_lu_Status_s*)y->gg.g.n) ;
  return y;
}

/* FUNC(zx_ps_QueryObjectsResponse_POP_Status) */

struct zx_lu_Status_s* zx_ps_QueryObjectsResponse_POP_Status(struct zx_ps_QueryObjectsResponse_s* x)
{
  struct zx_lu_Status_s* y;
  if (!x) return 0;
  y = x->Status;
  if (y)
    x->Status = (struct zx_lu_Status_s*)y->gg.g.n;
  return y;
}

/* FUNC(zx_ps_QueryObjectsResponse_PUSH_Status) */

void zx_ps_QueryObjectsResponse_PUSH_Status(struct zx_ps_QueryObjectsResponse_s* x, struct zx_lu_Status_s* z)
{
  if (!x || !z) return;
  z->gg.g.n = &x->Status->gg.g;
  x->Status = z;
}

/* FUNC(zx_ps_QueryObjectsResponse_REV_Status) */

void zx_ps_QueryObjectsResponse_REV_Status(struct zx_ps_QueryObjectsResponse_s* x)
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

/* FUNC(zx_ps_QueryObjectsResponse_PUT_Status) */

void zx_ps_QueryObjectsResponse_PUT_Status(struct zx_ps_QueryObjectsResponse_s* x, int n, struct zx_lu_Status_s* z)
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

/* FUNC(zx_ps_QueryObjectsResponse_ADD_Status) */

void zx_ps_QueryObjectsResponse_ADD_Status(struct zx_ps_QueryObjectsResponse_s* x, int n, struct zx_lu_Status_s* z)
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

/* FUNC(zx_ps_QueryObjectsResponse_DEL_Status) */

void zx_ps_QueryObjectsResponse_DEL_Status(struct zx_ps_QueryObjectsResponse_s* x, int n)
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



#ifdef ZX_ENA_GETPUT

/* FUNC(zx_ps_QueryObjectsResponse_NUM_Object) */

int zx_ps_QueryObjectsResponse_NUM_Object(struct zx_ps_QueryObjectsResponse_s* x)
{
  struct zx_ps_Object_s* y;
  int n = 0;
  if (!x) return 0;
  for (y = x->Object; y; ++n, y = (struct zx_ps_Object_s*)y->gg.g.n) ;
  return n;
}

/* FUNC(zx_ps_QueryObjectsResponse_GET_Object) */

struct zx_ps_Object_s* zx_ps_QueryObjectsResponse_GET_Object(struct zx_ps_QueryObjectsResponse_s* x, int n)
{
  struct zx_ps_Object_s* y;
  if (!x) return 0;
  for (y = x->Object; n>=0 && y; --n, y = (struct zx_ps_Object_s*)y->gg.g.n) ;
  return y;
}

/* FUNC(zx_ps_QueryObjectsResponse_POP_Object) */

struct zx_ps_Object_s* zx_ps_QueryObjectsResponse_POP_Object(struct zx_ps_QueryObjectsResponse_s* x)
{
  struct zx_ps_Object_s* y;
  if (!x) return 0;
  y = x->Object;
  if (y)
    x->Object = (struct zx_ps_Object_s*)y->gg.g.n;
  return y;
}

/* FUNC(zx_ps_QueryObjectsResponse_PUSH_Object) */

void zx_ps_QueryObjectsResponse_PUSH_Object(struct zx_ps_QueryObjectsResponse_s* x, struct zx_ps_Object_s* z)
{
  if (!x || !z) return;
  z->gg.g.n = &x->Object->gg.g;
  x->Object = z;
}

/* FUNC(zx_ps_QueryObjectsResponse_REV_Object) */

void zx_ps_QueryObjectsResponse_REV_Object(struct zx_ps_QueryObjectsResponse_s* x)
{
  struct zx_ps_Object_s* nxt;
  struct zx_ps_Object_s* y;
  if (!x) return;
  y = x->Object;
  if (!y) return;
  x->Object = 0;
  while (y) {
    nxt = (struct zx_ps_Object_s*)y->gg.g.n;
    y->gg.g.n = &x->Object->gg.g;
    x->Object = y;
    y = nxt;
  }
}

/* FUNC(zx_ps_QueryObjectsResponse_PUT_Object) */

void zx_ps_QueryObjectsResponse_PUT_Object(struct zx_ps_QueryObjectsResponse_s* x, int n, struct zx_ps_Object_s* z)
{
  struct zx_ps_Object_s* y;
  if (!x || !z) return;
  y = x->Object;
  if (!y) return;
  switch (n) {
  case 0:
    z->gg.g.n = y->gg.g.n;
    x->Object = z;
    return;
  default:
    for (; n > 1 && y->gg.g.n; --n, y = (struct zx_ps_Object_s*)y->gg.g.n) ;
    if (!y->gg.g.n) return;
    z->gg.g.n = y->gg.g.n->n;
    y->gg.g.n = &z->gg.g;
  }
}

/* FUNC(zx_ps_QueryObjectsResponse_ADD_Object) */

void zx_ps_QueryObjectsResponse_ADD_Object(struct zx_ps_QueryObjectsResponse_s* x, int n, struct zx_ps_Object_s* z)
{
  struct zx_ps_Object_s* y;
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
    for (; y->gg.g.n; y = (struct zx_ps_Object_s*)y->gg.g.n) ;
    break;
  default:
    for (y = x->Object; n > 1 && y; --n, y = (struct zx_ps_Object_s*)y->gg.g.n) ;
    if (!y) return;
  }
  z->gg.g.n = y->gg.g.n;
  y->gg.g.n = &z->gg.g;
}

/* FUNC(zx_ps_QueryObjectsResponse_DEL_Object) */

void zx_ps_QueryObjectsResponse_DEL_Object(struct zx_ps_QueryObjectsResponse_s* x, int n)
{
  struct zx_ps_Object_s* y;
  if (!x) return;
  switch (n) {
  case 0:
    x->Object = (struct zx_ps_Object_s*)x->Object->gg.g.n;
    return;
  case -1:
    y = (struct zx_ps_Object_s*)x->Object;
    if (!y) return;
    for (; y->gg.g.n; y = (struct zx_ps_Object_s*)y->gg.g.n) ;
    break;
  default:
    for (y = x->Object; n > 1 && y->gg.g.n; --n, y = (struct zx_ps_Object_s*)y->gg.g.n) ;
    if (!y->gg.g.n) return;
  }
  y->gg.g.n = y->gg.g.n->n;
}

#endif

/* FUNC(zx_ps_QueryObjectsResponse_GET_TimeStamp) */
struct zx_str* zx_ps_QueryObjectsResponse_GET_TimeStamp(struct zx_ps_QueryObjectsResponse_s* x) { return x->TimeStamp; }
/* FUNC(zx_ps_QueryObjectsResponse_PUT_TimeStamp) */
void zx_ps_QueryObjectsResponse_PUT_TimeStamp(struct zx_ps_QueryObjectsResponse_s* x, struct zx_str* y) { x->TimeStamp = y; }
/* FUNC(zx_ps_QueryObjectsResponse_GET_id) */
struct zx_str* zx_ps_QueryObjectsResponse_GET_id(struct zx_ps_QueryObjectsResponse_s* x) { return x->id; }
/* FUNC(zx_ps_QueryObjectsResponse_PUT_id) */
void zx_ps_QueryObjectsResponse_PUT_id(struct zx_ps_QueryObjectsResponse_s* x, struct zx_str* y) { x->id = y; }







#ifdef ZX_ENA_GETPUT

/* FUNC(zx_ps_RemoveCollectionRequest_NUM_TargetObjectID) */

int zx_ps_RemoveCollectionRequest_NUM_TargetObjectID(struct zx_ps_RemoveCollectionRequest_s* x)
{
  struct zx_elem_s* y;
  int n = 0;
  if (!x) return 0;
  for (y = x->TargetObjectID; y; ++n, y = (struct zx_elem_s*)y->g.n) ;
  return n;
}

/* FUNC(zx_ps_RemoveCollectionRequest_GET_TargetObjectID) */

struct zx_elem_s* zx_ps_RemoveCollectionRequest_GET_TargetObjectID(struct zx_ps_RemoveCollectionRequest_s* x, int n)
{
  struct zx_elem_s* y;
  if (!x) return 0;
  for (y = x->TargetObjectID; n>=0 && y; --n, y = (struct zx_elem_s*)y->g.n) ;
  return y;
}

/* FUNC(zx_ps_RemoveCollectionRequest_POP_TargetObjectID) */

struct zx_elem_s* zx_ps_RemoveCollectionRequest_POP_TargetObjectID(struct zx_ps_RemoveCollectionRequest_s* x)
{
  struct zx_elem_s* y;
  if (!x) return 0;
  y = x->TargetObjectID;
  if (y)
    x->TargetObjectID = (struct zx_elem_s*)y->g.n;
  return y;
}

/* FUNC(zx_ps_RemoveCollectionRequest_PUSH_TargetObjectID) */

void zx_ps_RemoveCollectionRequest_PUSH_TargetObjectID(struct zx_ps_RemoveCollectionRequest_s* x, struct zx_elem_s* z)
{
  if (!x || !z) return;
  z->g.n = &x->TargetObjectID->g;
  x->TargetObjectID = z;
}

/* FUNC(zx_ps_RemoveCollectionRequest_REV_TargetObjectID) */

void zx_ps_RemoveCollectionRequest_REV_TargetObjectID(struct zx_ps_RemoveCollectionRequest_s* x)
{
  struct zx_elem_s* nxt;
  struct zx_elem_s* y;
  if (!x) return;
  y = x->TargetObjectID;
  if (!y) return;
  x->TargetObjectID = 0;
  while (y) {
    nxt = (struct zx_elem_s*)y->g.n;
    y->g.n = &x->TargetObjectID->g;
    x->TargetObjectID = y;
    y = nxt;
  }
}

/* FUNC(zx_ps_RemoveCollectionRequest_PUT_TargetObjectID) */

void zx_ps_RemoveCollectionRequest_PUT_TargetObjectID(struct zx_ps_RemoveCollectionRequest_s* x, int n, struct zx_elem_s* z)
{
  struct zx_elem_s* y;
  if (!x || !z) return;
  y = x->TargetObjectID;
  if (!y) return;
  switch (n) {
  case 0:
    z->g.n = y->g.n;
    x->TargetObjectID = z;
    return;
  default:
    for (; n > 1 && y->g.n; --n, y = (struct zx_elem_s*)y->g.n) ;
    if (!y->g.n) return;
    z->g.n = y->g.n->n;
    y->g.n = &z->g;
  }
}

/* FUNC(zx_ps_RemoveCollectionRequest_ADD_TargetObjectID) */

void zx_ps_RemoveCollectionRequest_ADD_TargetObjectID(struct zx_ps_RemoveCollectionRequest_s* x, int n, struct zx_elem_s* z)
{
  struct zx_elem_s* y;
  if (!x || !z) return;
  switch (n) {
  case 0:
  add_to_start:
    z->g.n = &x->TargetObjectID->g;
    x->TargetObjectID = z;
    return;
  case -1:
    y = x->TargetObjectID;
    if (!y) goto add_to_start;
    for (; y->g.n; y = (struct zx_elem_s*)y->g.n) ;
    break;
  default:
    for (y = x->TargetObjectID; n > 1 && y; --n, y = (struct zx_elem_s*)y->g.n) ;
    if (!y) return;
  }
  z->g.n = y->g.n;
  y->g.n = &z->g;
}

/* FUNC(zx_ps_RemoveCollectionRequest_DEL_TargetObjectID) */

void zx_ps_RemoveCollectionRequest_DEL_TargetObjectID(struct zx_ps_RemoveCollectionRequest_s* x, int n)
{
  struct zx_elem_s* y;
  if (!x) return;
  switch (n) {
  case 0:
    x->TargetObjectID = (struct zx_elem_s*)x->TargetObjectID->g.n;
    return;
  case -1:
    y = (struct zx_elem_s*)x->TargetObjectID;
    if (!y) return;
    for (; y->g.n; y = (struct zx_elem_s*)y->g.n) ;
    break;
  default:
    for (y = x->TargetObjectID; n > 1 && y->g.n; --n, y = (struct zx_elem_s*)y->g.n) ;
    if (!y->g.n) return;
  }
  y->g.n = y->g.n->n;
}

#endif

/* FUNC(zx_ps_RemoveCollectionRequest_GET_id) */
struct zx_str* zx_ps_RemoveCollectionRequest_GET_id(struct zx_ps_RemoveCollectionRequest_s* x) { return x->id; }
/* FUNC(zx_ps_RemoveCollectionRequest_PUT_id) */
void zx_ps_RemoveCollectionRequest_PUT_id(struct zx_ps_RemoveCollectionRequest_s* x, struct zx_str* y) { x->id = y; }







#ifdef ZX_ENA_GETPUT

/* FUNC(zx_ps_RemoveCollectionResponse_NUM_Status) */

int zx_ps_RemoveCollectionResponse_NUM_Status(struct zx_ps_RemoveCollectionResponse_s* x)
{
  struct zx_lu_Status_s* y;
  int n = 0;
  if (!x) return 0;
  for (y = x->Status; y; ++n, y = (struct zx_lu_Status_s*)y->gg.g.n) ;
  return n;
}

/* FUNC(zx_ps_RemoveCollectionResponse_GET_Status) */

struct zx_lu_Status_s* zx_ps_RemoveCollectionResponse_GET_Status(struct zx_ps_RemoveCollectionResponse_s* x, int n)
{
  struct zx_lu_Status_s* y;
  if (!x) return 0;
  for (y = x->Status; n>=0 && y; --n, y = (struct zx_lu_Status_s*)y->gg.g.n) ;
  return y;
}

/* FUNC(zx_ps_RemoveCollectionResponse_POP_Status) */

struct zx_lu_Status_s* zx_ps_RemoveCollectionResponse_POP_Status(struct zx_ps_RemoveCollectionResponse_s* x)
{
  struct zx_lu_Status_s* y;
  if (!x) return 0;
  y = x->Status;
  if (y)
    x->Status = (struct zx_lu_Status_s*)y->gg.g.n;
  return y;
}

/* FUNC(zx_ps_RemoveCollectionResponse_PUSH_Status) */

void zx_ps_RemoveCollectionResponse_PUSH_Status(struct zx_ps_RemoveCollectionResponse_s* x, struct zx_lu_Status_s* z)
{
  if (!x || !z) return;
  z->gg.g.n = &x->Status->gg.g;
  x->Status = z;
}

/* FUNC(zx_ps_RemoveCollectionResponse_REV_Status) */

void zx_ps_RemoveCollectionResponse_REV_Status(struct zx_ps_RemoveCollectionResponse_s* x)
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

/* FUNC(zx_ps_RemoveCollectionResponse_PUT_Status) */

void zx_ps_RemoveCollectionResponse_PUT_Status(struct zx_ps_RemoveCollectionResponse_s* x, int n, struct zx_lu_Status_s* z)
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

/* FUNC(zx_ps_RemoveCollectionResponse_ADD_Status) */

void zx_ps_RemoveCollectionResponse_ADD_Status(struct zx_ps_RemoveCollectionResponse_s* x, int n, struct zx_lu_Status_s* z)
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

/* FUNC(zx_ps_RemoveCollectionResponse_DEL_Status) */

void zx_ps_RemoveCollectionResponse_DEL_Status(struct zx_ps_RemoveCollectionResponse_s* x, int n)
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

/* FUNC(zx_ps_RemoveCollectionResponse_GET_TimeStamp) */
struct zx_str* zx_ps_RemoveCollectionResponse_GET_TimeStamp(struct zx_ps_RemoveCollectionResponse_s* x) { return x->TimeStamp; }
/* FUNC(zx_ps_RemoveCollectionResponse_PUT_TimeStamp) */
void zx_ps_RemoveCollectionResponse_PUT_TimeStamp(struct zx_ps_RemoveCollectionResponse_s* x, struct zx_str* y) { x->TimeStamp = y; }
/* FUNC(zx_ps_RemoveCollectionResponse_GET_id) */
struct zx_str* zx_ps_RemoveCollectionResponse_GET_id(struct zx_ps_RemoveCollectionResponse_s* x) { return x->id; }
/* FUNC(zx_ps_RemoveCollectionResponse_PUT_id) */
void zx_ps_RemoveCollectionResponse_PUT_id(struct zx_ps_RemoveCollectionResponse_s* x, struct zx_str* y) { x->id = y; }







#ifdef ZX_ENA_GETPUT

/* FUNC(zx_ps_RemoveEntityRequest_NUM_TargetObjectID) */

int zx_ps_RemoveEntityRequest_NUM_TargetObjectID(struct zx_ps_RemoveEntityRequest_s* x)
{
  struct zx_elem_s* y;
  int n = 0;
  if (!x) return 0;
  for (y = x->TargetObjectID; y; ++n, y = (struct zx_elem_s*)y->g.n) ;
  return n;
}

/* FUNC(zx_ps_RemoveEntityRequest_GET_TargetObjectID) */

struct zx_elem_s* zx_ps_RemoveEntityRequest_GET_TargetObjectID(struct zx_ps_RemoveEntityRequest_s* x, int n)
{
  struct zx_elem_s* y;
  if (!x) return 0;
  for (y = x->TargetObjectID; n>=0 && y; --n, y = (struct zx_elem_s*)y->g.n) ;
  return y;
}

/* FUNC(zx_ps_RemoveEntityRequest_POP_TargetObjectID) */

struct zx_elem_s* zx_ps_RemoveEntityRequest_POP_TargetObjectID(struct zx_ps_RemoveEntityRequest_s* x)
{
  struct zx_elem_s* y;
  if (!x) return 0;
  y = x->TargetObjectID;
  if (y)
    x->TargetObjectID = (struct zx_elem_s*)y->g.n;
  return y;
}

/* FUNC(zx_ps_RemoveEntityRequest_PUSH_TargetObjectID) */

void zx_ps_RemoveEntityRequest_PUSH_TargetObjectID(struct zx_ps_RemoveEntityRequest_s* x, struct zx_elem_s* z)
{
  if (!x || !z) return;
  z->g.n = &x->TargetObjectID->g;
  x->TargetObjectID = z;
}

/* FUNC(zx_ps_RemoveEntityRequest_REV_TargetObjectID) */

void zx_ps_RemoveEntityRequest_REV_TargetObjectID(struct zx_ps_RemoveEntityRequest_s* x)
{
  struct zx_elem_s* nxt;
  struct zx_elem_s* y;
  if (!x) return;
  y = x->TargetObjectID;
  if (!y) return;
  x->TargetObjectID = 0;
  while (y) {
    nxt = (struct zx_elem_s*)y->g.n;
    y->g.n = &x->TargetObjectID->g;
    x->TargetObjectID = y;
    y = nxt;
  }
}

/* FUNC(zx_ps_RemoveEntityRequest_PUT_TargetObjectID) */

void zx_ps_RemoveEntityRequest_PUT_TargetObjectID(struct zx_ps_RemoveEntityRequest_s* x, int n, struct zx_elem_s* z)
{
  struct zx_elem_s* y;
  if (!x || !z) return;
  y = x->TargetObjectID;
  if (!y) return;
  switch (n) {
  case 0:
    z->g.n = y->g.n;
    x->TargetObjectID = z;
    return;
  default:
    for (; n > 1 && y->g.n; --n, y = (struct zx_elem_s*)y->g.n) ;
    if (!y->g.n) return;
    z->g.n = y->g.n->n;
    y->g.n = &z->g;
  }
}

/* FUNC(zx_ps_RemoveEntityRequest_ADD_TargetObjectID) */

void zx_ps_RemoveEntityRequest_ADD_TargetObjectID(struct zx_ps_RemoveEntityRequest_s* x, int n, struct zx_elem_s* z)
{
  struct zx_elem_s* y;
  if (!x || !z) return;
  switch (n) {
  case 0:
  add_to_start:
    z->g.n = &x->TargetObjectID->g;
    x->TargetObjectID = z;
    return;
  case -1:
    y = x->TargetObjectID;
    if (!y) goto add_to_start;
    for (; y->g.n; y = (struct zx_elem_s*)y->g.n) ;
    break;
  default:
    for (y = x->TargetObjectID; n > 1 && y; --n, y = (struct zx_elem_s*)y->g.n) ;
    if (!y) return;
  }
  z->g.n = y->g.n;
  y->g.n = &z->g;
}

/* FUNC(zx_ps_RemoveEntityRequest_DEL_TargetObjectID) */

void zx_ps_RemoveEntityRequest_DEL_TargetObjectID(struct zx_ps_RemoveEntityRequest_s* x, int n)
{
  struct zx_elem_s* y;
  if (!x) return;
  switch (n) {
  case 0:
    x->TargetObjectID = (struct zx_elem_s*)x->TargetObjectID->g.n;
    return;
  case -1:
    y = (struct zx_elem_s*)x->TargetObjectID;
    if (!y) return;
    for (; y->g.n; y = (struct zx_elem_s*)y->g.n) ;
    break;
  default:
    for (y = x->TargetObjectID; n > 1 && y->g.n; --n, y = (struct zx_elem_s*)y->g.n) ;
    if (!y->g.n) return;
  }
  y->g.n = y->g.n->n;
}

#endif

/* FUNC(zx_ps_RemoveEntityRequest_GET_id) */
struct zx_str* zx_ps_RemoveEntityRequest_GET_id(struct zx_ps_RemoveEntityRequest_s* x) { return x->id; }
/* FUNC(zx_ps_RemoveEntityRequest_PUT_id) */
void zx_ps_RemoveEntityRequest_PUT_id(struct zx_ps_RemoveEntityRequest_s* x, struct zx_str* y) { x->id = y; }







#ifdef ZX_ENA_GETPUT

/* FUNC(zx_ps_RemoveEntityResponse_NUM_Status) */

int zx_ps_RemoveEntityResponse_NUM_Status(struct zx_ps_RemoveEntityResponse_s* x)
{
  struct zx_lu_Status_s* y;
  int n = 0;
  if (!x) return 0;
  for (y = x->Status; y; ++n, y = (struct zx_lu_Status_s*)y->gg.g.n) ;
  return n;
}

/* FUNC(zx_ps_RemoveEntityResponse_GET_Status) */

struct zx_lu_Status_s* zx_ps_RemoveEntityResponse_GET_Status(struct zx_ps_RemoveEntityResponse_s* x, int n)
{
  struct zx_lu_Status_s* y;
  if (!x) return 0;
  for (y = x->Status; n>=0 && y; --n, y = (struct zx_lu_Status_s*)y->gg.g.n) ;
  return y;
}

/* FUNC(zx_ps_RemoveEntityResponse_POP_Status) */

struct zx_lu_Status_s* zx_ps_RemoveEntityResponse_POP_Status(struct zx_ps_RemoveEntityResponse_s* x)
{
  struct zx_lu_Status_s* y;
  if (!x) return 0;
  y = x->Status;
  if (y)
    x->Status = (struct zx_lu_Status_s*)y->gg.g.n;
  return y;
}

/* FUNC(zx_ps_RemoveEntityResponse_PUSH_Status) */

void zx_ps_RemoveEntityResponse_PUSH_Status(struct zx_ps_RemoveEntityResponse_s* x, struct zx_lu_Status_s* z)
{
  if (!x || !z) return;
  z->gg.g.n = &x->Status->gg.g;
  x->Status = z;
}

/* FUNC(zx_ps_RemoveEntityResponse_REV_Status) */

void zx_ps_RemoveEntityResponse_REV_Status(struct zx_ps_RemoveEntityResponse_s* x)
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

/* FUNC(zx_ps_RemoveEntityResponse_PUT_Status) */

void zx_ps_RemoveEntityResponse_PUT_Status(struct zx_ps_RemoveEntityResponse_s* x, int n, struct zx_lu_Status_s* z)
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

/* FUNC(zx_ps_RemoveEntityResponse_ADD_Status) */

void zx_ps_RemoveEntityResponse_ADD_Status(struct zx_ps_RemoveEntityResponse_s* x, int n, struct zx_lu_Status_s* z)
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

/* FUNC(zx_ps_RemoveEntityResponse_DEL_Status) */

void zx_ps_RemoveEntityResponse_DEL_Status(struct zx_ps_RemoveEntityResponse_s* x, int n)
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

/* FUNC(zx_ps_RemoveEntityResponse_GET_TimeStamp) */
struct zx_str* zx_ps_RemoveEntityResponse_GET_TimeStamp(struct zx_ps_RemoveEntityResponse_s* x) { return x->TimeStamp; }
/* FUNC(zx_ps_RemoveEntityResponse_PUT_TimeStamp) */
void zx_ps_RemoveEntityResponse_PUT_TimeStamp(struct zx_ps_RemoveEntityResponse_s* x, struct zx_str* y) { x->TimeStamp = y; }
/* FUNC(zx_ps_RemoveEntityResponse_GET_id) */
struct zx_str* zx_ps_RemoveEntityResponse_GET_id(struct zx_ps_RemoveEntityResponse_s* x) { return x->id; }
/* FUNC(zx_ps_RemoveEntityResponse_PUT_id) */
void zx_ps_RemoveEntityResponse_PUT_id(struct zx_ps_RemoveEntityResponse_s* x, struct zx_str* y) { x->id = y; }







#ifdef ZX_ENA_GETPUT

/* FUNC(zx_ps_RemoveFromCollectionRequest_NUM_TargetObjectID) */

int zx_ps_RemoveFromCollectionRequest_NUM_TargetObjectID(struct zx_ps_RemoveFromCollectionRequest_s* x)
{
  struct zx_elem_s* y;
  int n = 0;
  if (!x) return 0;
  for (y = x->TargetObjectID; y; ++n, y = (struct zx_elem_s*)y->g.n) ;
  return n;
}

/* FUNC(zx_ps_RemoveFromCollectionRequest_GET_TargetObjectID) */

struct zx_elem_s* zx_ps_RemoveFromCollectionRequest_GET_TargetObjectID(struct zx_ps_RemoveFromCollectionRequest_s* x, int n)
{
  struct zx_elem_s* y;
  if (!x) return 0;
  for (y = x->TargetObjectID; n>=0 && y; --n, y = (struct zx_elem_s*)y->g.n) ;
  return y;
}

/* FUNC(zx_ps_RemoveFromCollectionRequest_POP_TargetObjectID) */

struct zx_elem_s* zx_ps_RemoveFromCollectionRequest_POP_TargetObjectID(struct zx_ps_RemoveFromCollectionRequest_s* x)
{
  struct zx_elem_s* y;
  if (!x) return 0;
  y = x->TargetObjectID;
  if (y)
    x->TargetObjectID = (struct zx_elem_s*)y->g.n;
  return y;
}

/* FUNC(zx_ps_RemoveFromCollectionRequest_PUSH_TargetObjectID) */

void zx_ps_RemoveFromCollectionRequest_PUSH_TargetObjectID(struct zx_ps_RemoveFromCollectionRequest_s* x, struct zx_elem_s* z)
{
  if (!x || !z) return;
  z->g.n = &x->TargetObjectID->g;
  x->TargetObjectID = z;
}

/* FUNC(zx_ps_RemoveFromCollectionRequest_REV_TargetObjectID) */

void zx_ps_RemoveFromCollectionRequest_REV_TargetObjectID(struct zx_ps_RemoveFromCollectionRequest_s* x)
{
  struct zx_elem_s* nxt;
  struct zx_elem_s* y;
  if (!x) return;
  y = x->TargetObjectID;
  if (!y) return;
  x->TargetObjectID = 0;
  while (y) {
    nxt = (struct zx_elem_s*)y->g.n;
    y->g.n = &x->TargetObjectID->g;
    x->TargetObjectID = y;
    y = nxt;
  }
}

/* FUNC(zx_ps_RemoveFromCollectionRequest_PUT_TargetObjectID) */

void zx_ps_RemoveFromCollectionRequest_PUT_TargetObjectID(struct zx_ps_RemoveFromCollectionRequest_s* x, int n, struct zx_elem_s* z)
{
  struct zx_elem_s* y;
  if (!x || !z) return;
  y = x->TargetObjectID;
  if (!y) return;
  switch (n) {
  case 0:
    z->g.n = y->g.n;
    x->TargetObjectID = z;
    return;
  default:
    for (; n > 1 && y->g.n; --n, y = (struct zx_elem_s*)y->g.n) ;
    if (!y->g.n) return;
    z->g.n = y->g.n->n;
    y->g.n = &z->g;
  }
}

/* FUNC(zx_ps_RemoveFromCollectionRequest_ADD_TargetObjectID) */

void zx_ps_RemoveFromCollectionRequest_ADD_TargetObjectID(struct zx_ps_RemoveFromCollectionRequest_s* x, int n, struct zx_elem_s* z)
{
  struct zx_elem_s* y;
  if (!x || !z) return;
  switch (n) {
  case 0:
  add_to_start:
    z->g.n = &x->TargetObjectID->g;
    x->TargetObjectID = z;
    return;
  case -1:
    y = x->TargetObjectID;
    if (!y) goto add_to_start;
    for (; y->g.n; y = (struct zx_elem_s*)y->g.n) ;
    break;
  default:
    for (y = x->TargetObjectID; n > 1 && y; --n, y = (struct zx_elem_s*)y->g.n) ;
    if (!y) return;
  }
  z->g.n = y->g.n;
  y->g.n = &z->g;
}

/* FUNC(zx_ps_RemoveFromCollectionRequest_DEL_TargetObjectID) */

void zx_ps_RemoveFromCollectionRequest_DEL_TargetObjectID(struct zx_ps_RemoveFromCollectionRequest_s* x, int n)
{
  struct zx_elem_s* y;
  if (!x) return;
  switch (n) {
  case 0:
    x->TargetObjectID = (struct zx_elem_s*)x->TargetObjectID->g.n;
    return;
  case -1:
    y = (struct zx_elem_s*)x->TargetObjectID;
    if (!y) return;
    for (; y->g.n; y = (struct zx_elem_s*)y->g.n) ;
    break;
  default:
    for (y = x->TargetObjectID; n > 1 && y->g.n; --n, y = (struct zx_elem_s*)y->g.n) ;
    if (!y->g.n) return;
  }
  y->g.n = y->g.n->n;
}

#endif



#ifdef ZX_ENA_GETPUT

/* FUNC(zx_ps_RemoveFromCollectionRequest_NUM_ObjectID) */

int zx_ps_RemoveFromCollectionRequest_NUM_ObjectID(struct zx_ps_RemoveFromCollectionRequest_s* x)
{
  struct zx_elem_s* y;
  int n = 0;
  if (!x) return 0;
  for (y = x->ObjectID; y; ++n, y = (struct zx_elem_s*)y->g.n) ;
  return n;
}

/* FUNC(zx_ps_RemoveFromCollectionRequest_GET_ObjectID) */

struct zx_elem_s* zx_ps_RemoveFromCollectionRequest_GET_ObjectID(struct zx_ps_RemoveFromCollectionRequest_s* x, int n)
{
  struct zx_elem_s* y;
  if (!x) return 0;
  for (y = x->ObjectID; n>=0 && y; --n, y = (struct zx_elem_s*)y->g.n) ;
  return y;
}

/* FUNC(zx_ps_RemoveFromCollectionRequest_POP_ObjectID) */

struct zx_elem_s* zx_ps_RemoveFromCollectionRequest_POP_ObjectID(struct zx_ps_RemoveFromCollectionRequest_s* x)
{
  struct zx_elem_s* y;
  if (!x) return 0;
  y = x->ObjectID;
  if (y)
    x->ObjectID = (struct zx_elem_s*)y->g.n;
  return y;
}

/* FUNC(zx_ps_RemoveFromCollectionRequest_PUSH_ObjectID) */

void zx_ps_RemoveFromCollectionRequest_PUSH_ObjectID(struct zx_ps_RemoveFromCollectionRequest_s* x, struct zx_elem_s* z)
{
  if (!x || !z) return;
  z->g.n = &x->ObjectID->g;
  x->ObjectID = z;
}

/* FUNC(zx_ps_RemoveFromCollectionRequest_REV_ObjectID) */

void zx_ps_RemoveFromCollectionRequest_REV_ObjectID(struct zx_ps_RemoveFromCollectionRequest_s* x)
{
  struct zx_elem_s* nxt;
  struct zx_elem_s* y;
  if (!x) return;
  y = x->ObjectID;
  if (!y) return;
  x->ObjectID = 0;
  while (y) {
    nxt = (struct zx_elem_s*)y->g.n;
    y->g.n = &x->ObjectID->g;
    x->ObjectID = y;
    y = nxt;
  }
}

/* FUNC(zx_ps_RemoveFromCollectionRequest_PUT_ObjectID) */

void zx_ps_RemoveFromCollectionRequest_PUT_ObjectID(struct zx_ps_RemoveFromCollectionRequest_s* x, int n, struct zx_elem_s* z)
{
  struct zx_elem_s* y;
  if (!x || !z) return;
  y = x->ObjectID;
  if (!y) return;
  switch (n) {
  case 0:
    z->g.n = y->g.n;
    x->ObjectID = z;
    return;
  default:
    for (; n > 1 && y->g.n; --n, y = (struct zx_elem_s*)y->g.n) ;
    if (!y->g.n) return;
    z->g.n = y->g.n->n;
    y->g.n = &z->g;
  }
}

/* FUNC(zx_ps_RemoveFromCollectionRequest_ADD_ObjectID) */

void zx_ps_RemoveFromCollectionRequest_ADD_ObjectID(struct zx_ps_RemoveFromCollectionRequest_s* x, int n, struct zx_elem_s* z)
{
  struct zx_elem_s* y;
  if (!x || !z) return;
  switch (n) {
  case 0:
  add_to_start:
    z->g.n = &x->ObjectID->g;
    x->ObjectID = z;
    return;
  case -1:
    y = x->ObjectID;
    if (!y) goto add_to_start;
    for (; y->g.n; y = (struct zx_elem_s*)y->g.n) ;
    break;
  default:
    for (y = x->ObjectID; n > 1 && y; --n, y = (struct zx_elem_s*)y->g.n) ;
    if (!y) return;
  }
  z->g.n = y->g.n;
  y->g.n = &z->g;
}

/* FUNC(zx_ps_RemoveFromCollectionRequest_DEL_ObjectID) */

void zx_ps_RemoveFromCollectionRequest_DEL_ObjectID(struct zx_ps_RemoveFromCollectionRequest_s* x, int n)
{
  struct zx_elem_s* y;
  if (!x) return;
  switch (n) {
  case 0:
    x->ObjectID = (struct zx_elem_s*)x->ObjectID->g.n;
    return;
  case -1:
    y = (struct zx_elem_s*)x->ObjectID;
    if (!y) return;
    for (; y->g.n; y = (struct zx_elem_s*)y->g.n) ;
    break;
  default:
    for (y = x->ObjectID; n > 1 && y->g.n; --n, y = (struct zx_elem_s*)y->g.n) ;
    if (!y->g.n) return;
  }
  y->g.n = y->g.n->n;
}

#endif



#ifdef ZX_ENA_GETPUT

/* FUNC(zx_ps_RemoveFromCollectionRequest_NUM_Subscription) */

int zx_ps_RemoveFromCollectionRequest_NUM_Subscription(struct zx_ps_RemoveFromCollectionRequest_s* x)
{
  struct zx_ps_Subscription_s* y;
  int n = 0;
  if (!x) return 0;
  for (y = x->Subscription; y; ++n, y = (struct zx_ps_Subscription_s*)y->gg.g.n) ;
  return n;
}

/* FUNC(zx_ps_RemoveFromCollectionRequest_GET_Subscription) */

struct zx_ps_Subscription_s* zx_ps_RemoveFromCollectionRequest_GET_Subscription(struct zx_ps_RemoveFromCollectionRequest_s* x, int n)
{
  struct zx_ps_Subscription_s* y;
  if (!x) return 0;
  for (y = x->Subscription; n>=0 && y; --n, y = (struct zx_ps_Subscription_s*)y->gg.g.n) ;
  return y;
}

/* FUNC(zx_ps_RemoveFromCollectionRequest_POP_Subscription) */

struct zx_ps_Subscription_s* zx_ps_RemoveFromCollectionRequest_POP_Subscription(struct zx_ps_RemoveFromCollectionRequest_s* x)
{
  struct zx_ps_Subscription_s* y;
  if (!x) return 0;
  y = x->Subscription;
  if (y)
    x->Subscription = (struct zx_ps_Subscription_s*)y->gg.g.n;
  return y;
}

/* FUNC(zx_ps_RemoveFromCollectionRequest_PUSH_Subscription) */

void zx_ps_RemoveFromCollectionRequest_PUSH_Subscription(struct zx_ps_RemoveFromCollectionRequest_s* x, struct zx_ps_Subscription_s* z)
{
  if (!x || !z) return;
  z->gg.g.n = &x->Subscription->gg.g;
  x->Subscription = z;
}

/* FUNC(zx_ps_RemoveFromCollectionRequest_REV_Subscription) */

void zx_ps_RemoveFromCollectionRequest_REV_Subscription(struct zx_ps_RemoveFromCollectionRequest_s* x)
{
  struct zx_ps_Subscription_s* nxt;
  struct zx_ps_Subscription_s* y;
  if (!x) return;
  y = x->Subscription;
  if (!y) return;
  x->Subscription = 0;
  while (y) {
    nxt = (struct zx_ps_Subscription_s*)y->gg.g.n;
    y->gg.g.n = &x->Subscription->gg.g;
    x->Subscription = y;
    y = nxt;
  }
}

/* FUNC(zx_ps_RemoveFromCollectionRequest_PUT_Subscription) */

void zx_ps_RemoveFromCollectionRequest_PUT_Subscription(struct zx_ps_RemoveFromCollectionRequest_s* x, int n, struct zx_ps_Subscription_s* z)
{
  struct zx_ps_Subscription_s* y;
  if (!x || !z) return;
  y = x->Subscription;
  if (!y) return;
  switch (n) {
  case 0:
    z->gg.g.n = y->gg.g.n;
    x->Subscription = z;
    return;
  default:
    for (; n > 1 && y->gg.g.n; --n, y = (struct zx_ps_Subscription_s*)y->gg.g.n) ;
    if (!y->gg.g.n) return;
    z->gg.g.n = y->gg.g.n->n;
    y->gg.g.n = &z->gg.g;
  }
}

/* FUNC(zx_ps_RemoveFromCollectionRequest_ADD_Subscription) */

void zx_ps_RemoveFromCollectionRequest_ADD_Subscription(struct zx_ps_RemoveFromCollectionRequest_s* x, int n, struct zx_ps_Subscription_s* z)
{
  struct zx_ps_Subscription_s* y;
  if (!x || !z) return;
  switch (n) {
  case 0:
  add_to_start:
    z->gg.g.n = &x->Subscription->gg.g;
    x->Subscription = z;
    return;
  case -1:
    y = x->Subscription;
    if (!y) goto add_to_start;
    for (; y->gg.g.n; y = (struct zx_ps_Subscription_s*)y->gg.g.n) ;
    break;
  default:
    for (y = x->Subscription; n > 1 && y; --n, y = (struct zx_ps_Subscription_s*)y->gg.g.n) ;
    if (!y) return;
  }
  z->gg.g.n = y->gg.g.n;
  y->gg.g.n = &z->gg.g;
}

/* FUNC(zx_ps_RemoveFromCollectionRequest_DEL_Subscription) */

void zx_ps_RemoveFromCollectionRequest_DEL_Subscription(struct zx_ps_RemoveFromCollectionRequest_s* x, int n)
{
  struct zx_ps_Subscription_s* y;
  if (!x) return;
  switch (n) {
  case 0:
    x->Subscription = (struct zx_ps_Subscription_s*)x->Subscription->gg.g.n;
    return;
  case -1:
    y = (struct zx_ps_Subscription_s*)x->Subscription;
    if (!y) return;
    for (; y->gg.g.n; y = (struct zx_ps_Subscription_s*)y->gg.g.n) ;
    break;
  default:
    for (y = x->Subscription; n > 1 && y->gg.g.n; --n, y = (struct zx_ps_Subscription_s*)y->gg.g.n) ;
    if (!y->gg.g.n) return;
  }
  y->gg.g.n = y->gg.g.n->n;
}

#endif

/* FUNC(zx_ps_RemoveFromCollectionRequest_GET_id) */
struct zx_str* zx_ps_RemoveFromCollectionRequest_GET_id(struct zx_ps_RemoveFromCollectionRequest_s* x) { return x->id; }
/* FUNC(zx_ps_RemoveFromCollectionRequest_PUT_id) */
void zx_ps_RemoveFromCollectionRequest_PUT_id(struct zx_ps_RemoveFromCollectionRequest_s* x, struct zx_str* y) { x->id = y; }







#ifdef ZX_ENA_GETPUT

/* FUNC(zx_ps_RemoveFromCollectionResponse_NUM_Status) */

int zx_ps_RemoveFromCollectionResponse_NUM_Status(struct zx_ps_RemoveFromCollectionResponse_s* x)
{
  struct zx_lu_Status_s* y;
  int n = 0;
  if (!x) return 0;
  for (y = x->Status; y; ++n, y = (struct zx_lu_Status_s*)y->gg.g.n) ;
  return n;
}

/* FUNC(zx_ps_RemoveFromCollectionResponse_GET_Status) */

struct zx_lu_Status_s* zx_ps_RemoveFromCollectionResponse_GET_Status(struct zx_ps_RemoveFromCollectionResponse_s* x, int n)
{
  struct zx_lu_Status_s* y;
  if (!x) return 0;
  for (y = x->Status; n>=0 && y; --n, y = (struct zx_lu_Status_s*)y->gg.g.n) ;
  return y;
}

/* FUNC(zx_ps_RemoveFromCollectionResponse_POP_Status) */

struct zx_lu_Status_s* zx_ps_RemoveFromCollectionResponse_POP_Status(struct zx_ps_RemoveFromCollectionResponse_s* x)
{
  struct zx_lu_Status_s* y;
  if (!x) return 0;
  y = x->Status;
  if (y)
    x->Status = (struct zx_lu_Status_s*)y->gg.g.n;
  return y;
}

/* FUNC(zx_ps_RemoveFromCollectionResponse_PUSH_Status) */

void zx_ps_RemoveFromCollectionResponse_PUSH_Status(struct zx_ps_RemoveFromCollectionResponse_s* x, struct zx_lu_Status_s* z)
{
  if (!x || !z) return;
  z->gg.g.n = &x->Status->gg.g;
  x->Status = z;
}

/* FUNC(zx_ps_RemoveFromCollectionResponse_REV_Status) */

void zx_ps_RemoveFromCollectionResponse_REV_Status(struct zx_ps_RemoveFromCollectionResponse_s* x)
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

/* FUNC(zx_ps_RemoveFromCollectionResponse_PUT_Status) */

void zx_ps_RemoveFromCollectionResponse_PUT_Status(struct zx_ps_RemoveFromCollectionResponse_s* x, int n, struct zx_lu_Status_s* z)
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

/* FUNC(zx_ps_RemoveFromCollectionResponse_ADD_Status) */

void zx_ps_RemoveFromCollectionResponse_ADD_Status(struct zx_ps_RemoveFromCollectionResponse_s* x, int n, struct zx_lu_Status_s* z)
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

/* FUNC(zx_ps_RemoveFromCollectionResponse_DEL_Status) */

void zx_ps_RemoveFromCollectionResponse_DEL_Status(struct zx_ps_RemoveFromCollectionResponse_s* x, int n)
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

/* FUNC(zx_ps_RemoveFromCollectionResponse_GET_TimeStamp) */
struct zx_str* zx_ps_RemoveFromCollectionResponse_GET_TimeStamp(struct zx_ps_RemoveFromCollectionResponse_s* x) { return x->TimeStamp; }
/* FUNC(zx_ps_RemoveFromCollectionResponse_PUT_TimeStamp) */
void zx_ps_RemoveFromCollectionResponse_PUT_TimeStamp(struct zx_ps_RemoveFromCollectionResponse_s* x, struct zx_str* y) { x->TimeStamp = y; }
/* FUNC(zx_ps_RemoveFromCollectionResponse_GET_id) */
struct zx_str* zx_ps_RemoveFromCollectionResponse_GET_id(struct zx_ps_RemoveFromCollectionResponse_s* x) { return x->id; }
/* FUNC(zx_ps_RemoveFromCollectionResponse_PUT_id) */
void zx_ps_RemoveFromCollectionResponse_PUT_id(struct zx_ps_RemoveFromCollectionResponse_s* x, struct zx_str* y) { x->id = y; }







#ifdef ZX_ENA_GETPUT

/* FUNC(zx_ps_ResolveIdentifierRequest_NUM_ResolveInput) */

int zx_ps_ResolveIdentifierRequest_NUM_ResolveInput(struct zx_ps_ResolveIdentifierRequest_s* x)
{
  struct zx_ps_ResolveInput_s* y;
  int n = 0;
  if (!x) return 0;
  for (y = x->ResolveInput; y; ++n, y = (struct zx_ps_ResolveInput_s*)y->gg.g.n) ;
  return n;
}

/* FUNC(zx_ps_ResolveIdentifierRequest_GET_ResolveInput) */

struct zx_ps_ResolveInput_s* zx_ps_ResolveIdentifierRequest_GET_ResolveInput(struct zx_ps_ResolveIdentifierRequest_s* x, int n)
{
  struct zx_ps_ResolveInput_s* y;
  if (!x) return 0;
  for (y = x->ResolveInput; n>=0 && y; --n, y = (struct zx_ps_ResolveInput_s*)y->gg.g.n) ;
  return y;
}

/* FUNC(zx_ps_ResolveIdentifierRequest_POP_ResolveInput) */

struct zx_ps_ResolveInput_s* zx_ps_ResolveIdentifierRequest_POP_ResolveInput(struct zx_ps_ResolveIdentifierRequest_s* x)
{
  struct zx_ps_ResolveInput_s* y;
  if (!x) return 0;
  y = x->ResolveInput;
  if (y)
    x->ResolveInput = (struct zx_ps_ResolveInput_s*)y->gg.g.n;
  return y;
}

/* FUNC(zx_ps_ResolveIdentifierRequest_PUSH_ResolveInput) */

void zx_ps_ResolveIdentifierRequest_PUSH_ResolveInput(struct zx_ps_ResolveIdentifierRequest_s* x, struct zx_ps_ResolveInput_s* z)
{
  if (!x || !z) return;
  z->gg.g.n = &x->ResolveInput->gg.g;
  x->ResolveInput = z;
}

/* FUNC(zx_ps_ResolveIdentifierRequest_REV_ResolveInput) */

void zx_ps_ResolveIdentifierRequest_REV_ResolveInput(struct zx_ps_ResolveIdentifierRequest_s* x)
{
  struct zx_ps_ResolveInput_s* nxt;
  struct zx_ps_ResolveInput_s* y;
  if (!x) return;
  y = x->ResolveInput;
  if (!y) return;
  x->ResolveInput = 0;
  while (y) {
    nxt = (struct zx_ps_ResolveInput_s*)y->gg.g.n;
    y->gg.g.n = &x->ResolveInput->gg.g;
    x->ResolveInput = y;
    y = nxt;
  }
}

/* FUNC(zx_ps_ResolveIdentifierRequest_PUT_ResolveInput) */

void zx_ps_ResolveIdentifierRequest_PUT_ResolveInput(struct zx_ps_ResolveIdentifierRequest_s* x, int n, struct zx_ps_ResolveInput_s* z)
{
  struct zx_ps_ResolveInput_s* y;
  if (!x || !z) return;
  y = x->ResolveInput;
  if (!y) return;
  switch (n) {
  case 0:
    z->gg.g.n = y->gg.g.n;
    x->ResolveInput = z;
    return;
  default:
    for (; n > 1 && y->gg.g.n; --n, y = (struct zx_ps_ResolveInput_s*)y->gg.g.n) ;
    if (!y->gg.g.n) return;
    z->gg.g.n = y->gg.g.n->n;
    y->gg.g.n = &z->gg.g;
  }
}

/* FUNC(zx_ps_ResolveIdentifierRequest_ADD_ResolveInput) */

void zx_ps_ResolveIdentifierRequest_ADD_ResolveInput(struct zx_ps_ResolveIdentifierRequest_s* x, int n, struct zx_ps_ResolveInput_s* z)
{
  struct zx_ps_ResolveInput_s* y;
  if (!x || !z) return;
  switch (n) {
  case 0:
  add_to_start:
    z->gg.g.n = &x->ResolveInput->gg.g;
    x->ResolveInput = z;
    return;
  case -1:
    y = x->ResolveInput;
    if (!y) goto add_to_start;
    for (; y->gg.g.n; y = (struct zx_ps_ResolveInput_s*)y->gg.g.n) ;
    break;
  default:
    for (y = x->ResolveInput; n > 1 && y; --n, y = (struct zx_ps_ResolveInput_s*)y->gg.g.n) ;
    if (!y) return;
  }
  z->gg.g.n = y->gg.g.n;
  y->gg.g.n = &z->gg.g;
}

/* FUNC(zx_ps_ResolveIdentifierRequest_DEL_ResolveInput) */

void zx_ps_ResolveIdentifierRequest_DEL_ResolveInput(struct zx_ps_ResolveIdentifierRequest_s* x, int n)
{
  struct zx_ps_ResolveInput_s* y;
  if (!x) return;
  switch (n) {
  case 0:
    x->ResolveInput = (struct zx_ps_ResolveInput_s*)x->ResolveInput->gg.g.n;
    return;
  case -1:
    y = (struct zx_ps_ResolveInput_s*)x->ResolveInput;
    if (!y) return;
    for (; y->gg.g.n; y = (struct zx_ps_ResolveInput_s*)y->gg.g.n) ;
    break;
  default:
    for (y = x->ResolveInput; n > 1 && y->gg.g.n; --n, y = (struct zx_ps_ResolveInput_s*)y->gg.g.n) ;
    if (!y->gg.g.n) return;
  }
  y->gg.g.n = y->gg.g.n->n;
}

#endif

/* FUNC(zx_ps_ResolveIdentifierRequest_GET_id) */
struct zx_str* zx_ps_ResolveIdentifierRequest_GET_id(struct zx_ps_ResolveIdentifierRequest_s* x) { return x->id; }
/* FUNC(zx_ps_ResolveIdentifierRequest_PUT_id) */
void zx_ps_ResolveIdentifierRequest_PUT_id(struct zx_ps_ResolveIdentifierRequest_s* x, struct zx_str* y) { x->id = y; }







#ifdef ZX_ENA_GETPUT

/* FUNC(zx_ps_ResolveIdentifierResponse_NUM_Status) */

int zx_ps_ResolveIdentifierResponse_NUM_Status(struct zx_ps_ResolveIdentifierResponse_s* x)
{
  struct zx_lu_Status_s* y;
  int n = 0;
  if (!x) return 0;
  for (y = x->Status; y; ++n, y = (struct zx_lu_Status_s*)y->gg.g.n) ;
  return n;
}

/* FUNC(zx_ps_ResolveIdentifierResponse_GET_Status) */

struct zx_lu_Status_s* zx_ps_ResolveIdentifierResponse_GET_Status(struct zx_ps_ResolveIdentifierResponse_s* x, int n)
{
  struct zx_lu_Status_s* y;
  if (!x) return 0;
  for (y = x->Status; n>=0 && y; --n, y = (struct zx_lu_Status_s*)y->gg.g.n) ;
  return y;
}

/* FUNC(zx_ps_ResolveIdentifierResponse_POP_Status) */

struct zx_lu_Status_s* zx_ps_ResolveIdentifierResponse_POP_Status(struct zx_ps_ResolveIdentifierResponse_s* x)
{
  struct zx_lu_Status_s* y;
  if (!x) return 0;
  y = x->Status;
  if (y)
    x->Status = (struct zx_lu_Status_s*)y->gg.g.n;
  return y;
}

/* FUNC(zx_ps_ResolveIdentifierResponse_PUSH_Status) */

void zx_ps_ResolveIdentifierResponse_PUSH_Status(struct zx_ps_ResolveIdentifierResponse_s* x, struct zx_lu_Status_s* z)
{
  if (!x || !z) return;
  z->gg.g.n = &x->Status->gg.g;
  x->Status = z;
}

/* FUNC(zx_ps_ResolveIdentifierResponse_REV_Status) */

void zx_ps_ResolveIdentifierResponse_REV_Status(struct zx_ps_ResolveIdentifierResponse_s* x)
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

/* FUNC(zx_ps_ResolveIdentifierResponse_PUT_Status) */

void zx_ps_ResolveIdentifierResponse_PUT_Status(struct zx_ps_ResolveIdentifierResponse_s* x, int n, struct zx_lu_Status_s* z)
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

/* FUNC(zx_ps_ResolveIdentifierResponse_ADD_Status) */

void zx_ps_ResolveIdentifierResponse_ADD_Status(struct zx_ps_ResolveIdentifierResponse_s* x, int n, struct zx_lu_Status_s* z)
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

/* FUNC(zx_ps_ResolveIdentifierResponse_DEL_Status) */

void zx_ps_ResolveIdentifierResponse_DEL_Status(struct zx_ps_ResolveIdentifierResponse_s* x, int n)
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



#ifdef ZX_ENA_GETPUT

/* FUNC(zx_ps_ResolveIdentifierResponse_NUM_ResolveOutput) */

int zx_ps_ResolveIdentifierResponse_NUM_ResolveOutput(struct zx_ps_ResolveIdentifierResponse_s* x)
{
  struct zx_ps_ResolveOutput_s* y;
  int n = 0;
  if (!x) return 0;
  for (y = x->ResolveOutput; y; ++n, y = (struct zx_ps_ResolveOutput_s*)y->gg.g.n) ;
  return n;
}

/* FUNC(zx_ps_ResolveIdentifierResponse_GET_ResolveOutput) */

struct zx_ps_ResolveOutput_s* zx_ps_ResolveIdentifierResponse_GET_ResolveOutput(struct zx_ps_ResolveIdentifierResponse_s* x, int n)
{
  struct zx_ps_ResolveOutput_s* y;
  if (!x) return 0;
  for (y = x->ResolveOutput; n>=0 && y; --n, y = (struct zx_ps_ResolveOutput_s*)y->gg.g.n) ;
  return y;
}

/* FUNC(zx_ps_ResolveIdentifierResponse_POP_ResolveOutput) */

struct zx_ps_ResolveOutput_s* zx_ps_ResolveIdentifierResponse_POP_ResolveOutput(struct zx_ps_ResolveIdentifierResponse_s* x)
{
  struct zx_ps_ResolveOutput_s* y;
  if (!x) return 0;
  y = x->ResolveOutput;
  if (y)
    x->ResolveOutput = (struct zx_ps_ResolveOutput_s*)y->gg.g.n;
  return y;
}

/* FUNC(zx_ps_ResolveIdentifierResponse_PUSH_ResolveOutput) */

void zx_ps_ResolveIdentifierResponse_PUSH_ResolveOutput(struct zx_ps_ResolveIdentifierResponse_s* x, struct zx_ps_ResolveOutput_s* z)
{
  if (!x || !z) return;
  z->gg.g.n = &x->ResolveOutput->gg.g;
  x->ResolveOutput = z;
}

/* FUNC(zx_ps_ResolveIdentifierResponse_REV_ResolveOutput) */

void zx_ps_ResolveIdentifierResponse_REV_ResolveOutput(struct zx_ps_ResolveIdentifierResponse_s* x)
{
  struct zx_ps_ResolveOutput_s* nxt;
  struct zx_ps_ResolveOutput_s* y;
  if (!x) return;
  y = x->ResolveOutput;
  if (!y) return;
  x->ResolveOutput = 0;
  while (y) {
    nxt = (struct zx_ps_ResolveOutput_s*)y->gg.g.n;
    y->gg.g.n = &x->ResolveOutput->gg.g;
    x->ResolveOutput = y;
    y = nxt;
  }
}

/* FUNC(zx_ps_ResolveIdentifierResponse_PUT_ResolveOutput) */

void zx_ps_ResolveIdentifierResponse_PUT_ResolveOutput(struct zx_ps_ResolveIdentifierResponse_s* x, int n, struct zx_ps_ResolveOutput_s* z)
{
  struct zx_ps_ResolveOutput_s* y;
  if (!x || !z) return;
  y = x->ResolveOutput;
  if (!y) return;
  switch (n) {
  case 0:
    z->gg.g.n = y->gg.g.n;
    x->ResolveOutput = z;
    return;
  default:
    for (; n > 1 && y->gg.g.n; --n, y = (struct zx_ps_ResolveOutput_s*)y->gg.g.n) ;
    if (!y->gg.g.n) return;
    z->gg.g.n = y->gg.g.n->n;
    y->gg.g.n = &z->gg.g;
  }
}

/* FUNC(zx_ps_ResolveIdentifierResponse_ADD_ResolveOutput) */

void zx_ps_ResolveIdentifierResponse_ADD_ResolveOutput(struct zx_ps_ResolveIdentifierResponse_s* x, int n, struct zx_ps_ResolveOutput_s* z)
{
  struct zx_ps_ResolveOutput_s* y;
  if (!x || !z) return;
  switch (n) {
  case 0:
  add_to_start:
    z->gg.g.n = &x->ResolveOutput->gg.g;
    x->ResolveOutput = z;
    return;
  case -1:
    y = x->ResolveOutput;
    if (!y) goto add_to_start;
    for (; y->gg.g.n; y = (struct zx_ps_ResolveOutput_s*)y->gg.g.n) ;
    break;
  default:
    for (y = x->ResolveOutput; n > 1 && y; --n, y = (struct zx_ps_ResolveOutput_s*)y->gg.g.n) ;
    if (!y) return;
  }
  z->gg.g.n = y->gg.g.n;
  y->gg.g.n = &z->gg.g;
}

/* FUNC(zx_ps_ResolveIdentifierResponse_DEL_ResolveOutput) */

void zx_ps_ResolveIdentifierResponse_DEL_ResolveOutput(struct zx_ps_ResolveIdentifierResponse_s* x, int n)
{
  struct zx_ps_ResolveOutput_s* y;
  if (!x) return;
  switch (n) {
  case 0:
    x->ResolveOutput = (struct zx_ps_ResolveOutput_s*)x->ResolveOutput->gg.g.n;
    return;
  case -1:
    y = (struct zx_ps_ResolveOutput_s*)x->ResolveOutput;
    if (!y) return;
    for (; y->gg.g.n; y = (struct zx_ps_ResolveOutput_s*)y->gg.g.n) ;
    break;
  default:
    for (y = x->ResolveOutput; n > 1 && y->gg.g.n; --n, y = (struct zx_ps_ResolveOutput_s*)y->gg.g.n) ;
    if (!y->gg.g.n) return;
  }
  y->gg.g.n = y->gg.g.n->n;
}

#endif

/* FUNC(zx_ps_ResolveIdentifierResponse_GET_TimeStamp) */
struct zx_str* zx_ps_ResolveIdentifierResponse_GET_TimeStamp(struct zx_ps_ResolveIdentifierResponse_s* x) { return x->TimeStamp; }
/* FUNC(zx_ps_ResolveIdentifierResponse_PUT_TimeStamp) */
void zx_ps_ResolveIdentifierResponse_PUT_TimeStamp(struct zx_ps_ResolveIdentifierResponse_s* x, struct zx_str* y) { x->TimeStamp = y; }
/* FUNC(zx_ps_ResolveIdentifierResponse_GET_id) */
struct zx_str* zx_ps_ResolveIdentifierResponse_GET_id(struct zx_ps_ResolveIdentifierResponse_s* x) { return x->id; }
/* FUNC(zx_ps_ResolveIdentifierResponse_PUT_id) */
void zx_ps_ResolveIdentifierResponse_PUT_id(struct zx_ps_ResolveIdentifierResponse_s* x, struct zx_str* y) { x->id = y; }







#ifdef ZX_ENA_GETPUT

/* FUNC(zx_ps_ResolveInput_NUM_TokenPolicy) */

int zx_ps_ResolveInput_NUM_TokenPolicy(struct zx_ps_ResolveInput_s* x)
{
  struct zx_sec_TokenPolicy_s* y;
  int n = 0;
  if (!x) return 0;
  for (y = x->TokenPolicy; y; ++n, y = (struct zx_sec_TokenPolicy_s*)y->gg.g.n) ;
  return n;
}

/* FUNC(zx_ps_ResolveInput_GET_TokenPolicy) */

struct zx_sec_TokenPolicy_s* zx_ps_ResolveInput_GET_TokenPolicy(struct zx_ps_ResolveInput_s* x, int n)
{
  struct zx_sec_TokenPolicy_s* y;
  if (!x) return 0;
  for (y = x->TokenPolicy; n>=0 && y; --n, y = (struct zx_sec_TokenPolicy_s*)y->gg.g.n) ;
  return y;
}

/* FUNC(zx_ps_ResolveInput_POP_TokenPolicy) */

struct zx_sec_TokenPolicy_s* zx_ps_ResolveInput_POP_TokenPolicy(struct zx_ps_ResolveInput_s* x)
{
  struct zx_sec_TokenPolicy_s* y;
  if (!x) return 0;
  y = x->TokenPolicy;
  if (y)
    x->TokenPolicy = (struct zx_sec_TokenPolicy_s*)y->gg.g.n;
  return y;
}

/* FUNC(zx_ps_ResolveInput_PUSH_TokenPolicy) */

void zx_ps_ResolveInput_PUSH_TokenPolicy(struct zx_ps_ResolveInput_s* x, struct zx_sec_TokenPolicy_s* z)
{
  if (!x || !z) return;
  z->gg.g.n = &x->TokenPolicy->gg.g;
  x->TokenPolicy = z;
}

/* FUNC(zx_ps_ResolveInput_REV_TokenPolicy) */

void zx_ps_ResolveInput_REV_TokenPolicy(struct zx_ps_ResolveInput_s* x)
{
  struct zx_sec_TokenPolicy_s* nxt;
  struct zx_sec_TokenPolicy_s* y;
  if (!x) return;
  y = x->TokenPolicy;
  if (!y) return;
  x->TokenPolicy = 0;
  while (y) {
    nxt = (struct zx_sec_TokenPolicy_s*)y->gg.g.n;
    y->gg.g.n = &x->TokenPolicy->gg.g;
    x->TokenPolicy = y;
    y = nxt;
  }
}

/* FUNC(zx_ps_ResolveInput_PUT_TokenPolicy) */

void zx_ps_ResolveInput_PUT_TokenPolicy(struct zx_ps_ResolveInput_s* x, int n, struct zx_sec_TokenPolicy_s* z)
{
  struct zx_sec_TokenPolicy_s* y;
  if (!x || !z) return;
  y = x->TokenPolicy;
  if (!y) return;
  switch (n) {
  case 0:
    z->gg.g.n = y->gg.g.n;
    x->TokenPolicy = z;
    return;
  default:
    for (; n > 1 && y->gg.g.n; --n, y = (struct zx_sec_TokenPolicy_s*)y->gg.g.n) ;
    if (!y->gg.g.n) return;
    z->gg.g.n = y->gg.g.n->n;
    y->gg.g.n = &z->gg.g;
  }
}

/* FUNC(zx_ps_ResolveInput_ADD_TokenPolicy) */

void zx_ps_ResolveInput_ADD_TokenPolicy(struct zx_ps_ResolveInput_s* x, int n, struct zx_sec_TokenPolicy_s* z)
{
  struct zx_sec_TokenPolicy_s* y;
  if (!x || !z) return;
  switch (n) {
  case 0:
  add_to_start:
    z->gg.g.n = &x->TokenPolicy->gg.g;
    x->TokenPolicy = z;
    return;
  case -1:
    y = x->TokenPolicy;
    if (!y) goto add_to_start;
    for (; y->gg.g.n; y = (struct zx_sec_TokenPolicy_s*)y->gg.g.n) ;
    break;
  default:
    for (y = x->TokenPolicy; n > 1 && y; --n, y = (struct zx_sec_TokenPolicy_s*)y->gg.g.n) ;
    if (!y) return;
  }
  z->gg.g.n = y->gg.g.n;
  y->gg.g.n = &z->gg.g;
}

/* FUNC(zx_ps_ResolveInput_DEL_TokenPolicy) */

void zx_ps_ResolveInput_DEL_TokenPolicy(struct zx_ps_ResolveInput_s* x, int n)
{
  struct zx_sec_TokenPolicy_s* y;
  if (!x) return;
  switch (n) {
  case 0:
    x->TokenPolicy = (struct zx_sec_TokenPolicy_s*)x->TokenPolicy->gg.g.n;
    return;
  case -1:
    y = (struct zx_sec_TokenPolicy_s*)x->TokenPolicy;
    if (!y) return;
    for (; y->gg.g.n; y = (struct zx_sec_TokenPolicy_s*)y->gg.g.n) ;
    break;
  default:
    for (y = x->TokenPolicy; n > 1 && y->gg.g.n; --n, y = (struct zx_sec_TokenPolicy_s*)y->gg.g.n) ;
    if (!y->gg.g.n) return;
  }
  y->gg.g.n = y->gg.g.n->n;
}

#endif



#ifdef ZX_ENA_GETPUT

/* FUNC(zx_ps_ResolveInput_NUM_Token) */

int zx_ps_ResolveInput_NUM_Token(struct zx_ps_ResolveInput_s* x)
{
  struct zx_sec_Token_s* y;
  int n = 0;
  if (!x) return 0;
  for (y = x->Token; y; ++n, y = (struct zx_sec_Token_s*)y->gg.g.n) ;
  return n;
}

/* FUNC(zx_ps_ResolveInput_GET_Token) */

struct zx_sec_Token_s* zx_ps_ResolveInput_GET_Token(struct zx_ps_ResolveInput_s* x, int n)
{
  struct zx_sec_Token_s* y;
  if (!x) return 0;
  for (y = x->Token; n>=0 && y; --n, y = (struct zx_sec_Token_s*)y->gg.g.n) ;
  return y;
}

/* FUNC(zx_ps_ResolveInput_POP_Token) */

struct zx_sec_Token_s* zx_ps_ResolveInput_POP_Token(struct zx_ps_ResolveInput_s* x)
{
  struct zx_sec_Token_s* y;
  if (!x) return 0;
  y = x->Token;
  if (y)
    x->Token = (struct zx_sec_Token_s*)y->gg.g.n;
  return y;
}

/* FUNC(zx_ps_ResolveInput_PUSH_Token) */

void zx_ps_ResolveInput_PUSH_Token(struct zx_ps_ResolveInput_s* x, struct zx_sec_Token_s* z)
{
  if (!x || !z) return;
  z->gg.g.n = &x->Token->gg.g;
  x->Token = z;
}

/* FUNC(zx_ps_ResolveInput_REV_Token) */

void zx_ps_ResolveInput_REV_Token(struct zx_ps_ResolveInput_s* x)
{
  struct zx_sec_Token_s* nxt;
  struct zx_sec_Token_s* y;
  if (!x) return;
  y = x->Token;
  if (!y) return;
  x->Token = 0;
  while (y) {
    nxt = (struct zx_sec_Token_s*)y->gg.g.n;
    y->gg.g.n = &x->Token->gg.g;
    x->Token = y;
    y = nxt;
  }
}

/* FUNC(zx_ps_ResolveInput_PUT_Token) */

void zx_ps_ResolveInput_PUT_Token(struct zx_ps_ResolveInput_s* x, int n, struct zx_sec_Token_s* z)
{
  struct zx_sec_Token_s* y;
  if (!x || !z) return;
  y = x->Token;
  if (!y) return;
  switch (n) {
  case 0:
    z->gg.g.n = y->gg.g.n;
    x->Token = z;
    return;
  default:
    for (; n > 1 && y->gg.g.n; --n, y = (struct zx_sec_Token_s*)y->gg.g.n) ;
    if (!y->gg.g.n) return;
    z->gg.g.n = y->gg.g.n->n;
    y->gg.g.n = &z->gg.g;
  }
}

/* FUNC(zx_ps_ResolveInput_ADD_Token) */

void zx_ps_ResolveInput_ADD_Token(struct zx_ps_ResolveInput_s* x, int n, struct zx_sec_Token_s* z)
{
  struct zx_sec_Token_s* y;
  if (!x || !z) return;
  switch (n) {
  case 0:
  add_to_start:
    z->gg.g.n = &x->Token->gg.g;
    x->Token = z;
    return;
  case -1:
    y = x->Token;
    if (!y) goto add_to_start;
    for (; y->gg.g.n; y = (struct zx_sec_Token_s*)y->gg.g.n) ;
    break;
  default:
    for (y = x->Token; n > 1 && y; --n, y = (struct zx_sec_Token_s*)y->gg.g.n) ;
    if (!y) return;
  }
  z->gg.g.n = y->gg.g.n;
  y->gg.g.n = &z->gg.g;
}

/* FUNC(zx_ps_ResolveInput_DEL_Token) */

void zx_ps_ResolveInput_DEL_Token(struct zx_ps_ResolveInput_s* x, int n)
{
  struct zx_sec_Token_s* y;
  if (!x) return;
  switch (n) {
  case 0:
    x->Token = (struct zx_sec_Token_s*)x->Token->gg.g.n;
    return;
  case -1:
    y = (struct zx_sec_Token_s*)x->Token;
    if (!y) return;
    for (; y->gg.g.n; y = (struct zx_sec_Token_s*)y->gg.g.n) ;
    break;
  default:
    for (y = x->Token; n > 1 && y->gg.g.n; --n, y = (struct zx_sec_Token_s*)y->gg.g.n) ;
    if (!y->gg.g.n) return;
  }
  y->gg.g.n = y->gg.g.n->n;
}

#endif



#ifdef ZX_ENA_GETPUT

/* FUNC(zx_ps_ResolveInput_NUM_TargetObjectID) */

int zx_ps_ResolveInput_NUM_TargetObjectID(struct zx_ps_ResolveInput_s* x)
{
  struct zx_elem_s* y;
  int n = 0;
  if (!x) return 0;
  for (y = x->TargetObjectID; y; ++n, y = (struct zx_elem_s*)y->g.n) ;
  return n;
}

/* FUNC(zx_ps_ResolveInput_GET_TargetObjectID) */

struct zx_elem_s* zx_ps_ResolveInput_GET_TargetObjectID(struct zx_ps_ResolveInput_s* x, int n)
{
  struct zx_elem_s* y;
  if (!x) return 0;
  for (y = x->TargetObjectID; n>=0 && y; --n, y = (struct zx_elem_s*)y->g.n) ;
  return y;
}

/* FUNC(zx_ps_ResolveInput_POP_TargetObjectID) */

struct zx_elem_s* zx_ps_ResolveInput_POP_TargetObjectID(struct zx_ps_ResolveInput_s* x)
{
  struct zx_elem_s* y;
  if (!x) return 0;
  y = x->TargetObjectID;
  if (y)
    x->TargetObjectID = (struct zx_elem_s*)y->g.n;
  return y;
}

/* FUNC(zx_ps_ResolveInput_PUSH_TargetObjectID) */

void zx_ps_ResolveInput_PUSH_TargetObjectID(struct zx_ps_ResolveInput_s* x, struct zx_elem_s* z)
{
  if (!x || !z) return;
  z->g.n = &x->TargetObjectID->g;
  x->TargetObjectID = z;
}

/* FUNC(zx_ps_ResolveInput_REV_TargetObjectID) */

void zx_ps_ResolveInput_REV_TargetObjectID(struct zx_ps_ResolveInput_s* x)
{
  struct zx_elem_s* nxt;
  struct zx_elem_s* y;
  if (!x) return;
  y = x->TargetObjectID;
  if (!y) return;
  x->TargetObjectID = 0;
  while (y) {
    nxt = (struct zx_elem_s*)y->g.n;
    y->g.n = &x->TargetObjectID->g;
    x->TargetObjectID = y;
    y = nxt;
  }
}

/* FUNC(zx_ps_ResolveInput_PUT_TargetObjectID) */

void zx_ps_ResolveInput_PUT_TargetObjectID(struct zx_ps_ResolveInput_s* x, int n, struct zx_elem_s* z)
{
  struct zx_elem_s* y;
  if (!x || !z) return;
  y = x->TargetObjectID;
  if (!y) return;
  switch (n) {
  case 0:
    z->g.n = y->g.n;
    x->TargetObjectID = z;
    return;
  default:
    for (; n > 1 && y->g.n; --n, y = (struct zx_elem_s*)y->g.n) ;
    if (!y->g.n) return;
    z->g.n = y->g.n->n;
    y->g.n = &z->g;
  }
}

/* FUNC(zx_ps_ResolveInput_ADD_TargetObjectID) */

void zx_ps_ResolveInput_ADD_TargetObjectID(struct zx_ps_ResolveInput_s* x, int n, struct zx_elem_s* z)
{
  struct zx_elem_s* y;
  if (!x || !z) return;
  switch (n) {
  case 0:
  add_to_start:
    z->g.n = &x->TargetObjectID->g;
    x->TargetObjectID = z;
    return;
  case -1:
    y = x->TargetObjectID;
    if (!y) goto add_to_start;
    for (; y->g.n; y = (struct zx_elem_s*)y->g.n) ;
    break;
  default:
    for (y = x->TargetObjectID; n > 1 && y; --n, y = (struct zx_elem_s*)y->g.n) ;
    if (!y) return;
  }
  z->g.n = y->g.n;
  y->g.n = &z->g;
}

/* FUNC(zx_ps_ResolveInput_DEL_TargetObjectID) */

void zx_ps_ResolveInput_DEL_TargetObjectID(struct zx_ps_ResolveInput_s* x, int n)
{
  struct zx_elem_s* y;
  if (!x) return;
  switch (n) {
  case 0:
    x->TargetObjectID = (struct zx_elem_s*)x->TargetObjectID->g.n;
    return;
  case -1:
    y = (struct zx_elem_s*)x->TargetObjectID;
    if (!y) return;
    for (; y->g.n; y = (struct zx_elem_s*)y->g.n) ;
    break;
  default:
    for (y = x->TargetObjectID; n > 1 && y->g.n; --n, y = (struct zx_elem_s*)y->g.n) ;
    if (!y->g.n) return;
  }
  y->g.n = y->g.n->n;
}

#endif

/* FUNC(zx_ps_ResolveInput_GET_reqID) */
struct zx_str* zx_ps_ResolveInput_GET_reqID(struct zx_ps_ResolveInput_s* x) { return x->reqID; }
/* FUNC(zx_ps_ResolveInput_PUT_reqID) */
void zx_ps_ResolveInput_PUT_reqID(struct zx_ps_ResolveInput_s* x, struct zx_str* y) { x->reqID = y; }







#ifdef ZX_ENA_GETPUT

/* FUNC(zx_ps_ResolveOutput_NUM_Token) */

int zx_ps_ResolveOutput_NUM_Token(struct zx_ps_ResolveOutput_s* x)
{
  struct zx_sec_Token_s* y;
  int n = 0;
  if (!x) return 0;
  for (y = x->Token; y; ++n, y = (struct zx_sec_Token_s*)y->gg.g.n) ;
  return n;
}

/* FUNC(zx_ps_ResolveOutput_GET_Token) */

struct zx_sec_Token_s* zx_ps_ResolveOutput_GET_Token(struct zx_ps_ResolveOutput_s* x, int n)
{
  struct zx_sec_Token_s* y;
  if (!x) return 0;
  for (y = x->Token; n>=0 && y; --n, y = (struct zx_sec_Token_s*)y->gg.g.n) ;
  return y;
}

/* FUNC(zx_ps_ResolveOutput_POP_Token) */

struct zx_sec_Token_s* zx_ps_ResolveOutput_POP_Token(struct zx_ps_ResolveOutput_s* x)
{
  struct zx_sec_Token_s* y;
  if (!x) return 0;
  y = x->Token;
  if (y)
    x->Token = (struct zx_sec_Token_s*)y->gg.g.n;
  return y;
}

/* FUNC(zx_ps_ResolveOutput_PUSH_Token) */

void zx_ps_ResolveOutput_PUSH_Token(struct zx_ps_ResolveOutput_s* x, struct zx_sec_Token_s* z)
{
  if (!x || !z) return;
  z->gg.g.n = &x->Token->gg.g;
  x->Token = z;
}

/* FUNC(zx_ps_ResolveOutput_REV_Token) */

void zx_ps_ResolveOutput_REV_Token(struct zx_ps_ResolveOutput_s* x)
{
  struct zx_sec_Token_s* nxt;
  struct zx_sec_Token_s* y;
  if (!x) return;
  y = x->Token;
  if (!y) return;
  x->Token = 0;
  while (y) {
    nxt = (struct zx_sec_Token_s*)y->gg.g.n;
    y->gg.g.n = &x->Token->gg.g;
    x->Token = y;
    y = nxt;
  }
}

/* FUNC(zx_ps_ResolveOutput_PUT_Token) */

void zx_ps_ResolveOutput_PUT_Token(struct zx_ps_ResolveOutput_s* x, int n, struct zx_sec_Token_s* z)
{
  struct zx_sec_Token_s* y;
  if (!x || !z) return;
  y = x->Token;
  if (!y) return;
  switch (n) {
  case 0:
    z->gg.g.n = y->gg.g.n;
    x->Token = z;
    return;
  default:
    for (; n > 1 && y->gg.g.n; --n, y = (struct zx_sec_Token_s*)y->gg.g.n) ;
    if (!y->gg.g.n) return;
    z->gg.g.n = y->gg.g.n->n;
    y->gg.g.n = &z->gg.g;
  }
}

/* FUNC(zx_ps_ResolveOutput_ADD_Token) */

void zx_ps_ResolveOutput_ADD_Token(struct zx_ps_ResolveOutput_s* x, int n, struct zx_sec_Token_s* z)
{
  struct zx_sec_Token_s* y;
  if (!x || !z) return;
  switch (n) {
  case 0:
  add_to_start:
    z->gg.g.n = &x->Token->gg.g;
    x->Token = z;
    return;
  case -1:
    y = x->Token;
    if (!y) goto add_to_start;
    for (; y->gg.g.n; y = (struct zx_sec_Token_s*)y->gg.g.n) ;
    break;
  default:
    for (y = x->Token; n > 1 && y; --n, y = (struct zx_sec_Token_s*)y->gg.g.n) ;
    if (!y) return;
  }
  z->gg.g.n = y->gg.g.n;
  y->gg.g.n = &z->gg.g;
}

/* FUNC(zx_ps_ResolveOutput_DEL_Token) */

void zx_ps_ResolveOutput_DEL_Token(struct zx_ps_ResolveOutput_s* x, int n)
{
  struct zx_sec_Token_s* y;
  if (!x) return;
  switch (n) {
  case 0:
    x->Token = (struct zx_sec_Token_s*)x->Token->gg.g.n;
    return;
  case -1:
    y = (struct zx_sec_Token_s*)x->Token;
    if (!y) return;
    for (; y->gg.g.n; y = (struct zx_sec_Token_s*)y->gg.g.n) ;
    break;
  default:
    for (y = x->Token; n > 1 && y->gg.g.n; --n, y = (struct zx_sec_Token_s*)y->gg.g.n) ;
    if (!y->gg.g.n) return;
  }
  y->gg.g.n = y->gg.g.n->n;
}

#endif

/* FUNC(zx_ps_ResolveOutput_GET_reqRef) */
struct zx_str* zx_ps_ResolveOutput_GET_reqRef(struct zx_ps_ResolveOutput_s* x) { return x->reqRef; }
/* FUNC(zx_ps_ResolveOutput_PUT_reqRef) */
void zx_ps_ResolveOutput_PUT_reqRef(struct zx_ps_ResolveOutput_s* x, struct zx_str* y) { x->reqRef = y; }







#ifdef ZX_ENA_GETPUT

/* FUNC(zx_ps_SetObjectInfoRequest_NUM_Object) */

int zx_ps_SetObjectInfoRequest_NUM_Object(struct zx_ps_SetObjectInfoRequest_s* x)
{
  struct zx_ps_Object_s* y;
  int n = 0;
  if (!x) return 0;
  for (y = x->Object; y; ++n, y = (struct zx_ps_Object_s*)y->gg.g.n) ;
  return n;
}

/* FUNC(zx_ps_SetObjectInfoRequest_GET_Object) */

struct zx_ps_Object_s* zx_ps_SetObjectInfoRequest_GET_Object(struct zx_ps_SetObjectInfoRequest_s* x, int n)
{
  struct zx_ps_Object_s* y;
  if (!x) return 0;
  for (y = x->Object; n>=0 && y; --n, y = (struct zx_ps_Object_s*)y->gg.g.n) ;
  return y;
}

/* FUNC(zx_ps_SetObjectInfoRequest_POP_Object) */

struct zx_ps_Object_s* zx_ps_SetObjectInfoRequest_POP_Object(struct zx_ps_SetObjectInfoRequest_s* x)
{
  struct zx_ps_Object_s* y;
  if (!x) return 0;
  y = x->Object;
  if (y)
    x->Object = (struct zx_ps_Object_s*)y->gg.g.n;
  return y;
}

/* FUNC(zx_ps_SetObjectInfoRequest_PUSH_Object) */

void zx_ps_SetObjectInfoRequest_PUSH_Object(struct zx_ps_SetObjectInfoRequest_s* x, struct zx_ps_Object_s* z)
{
  if (!x || !z) return;
  z->gg.g.n = &x->Object->gg.g;
  x->Object = z;
}

/* FUNC(zx_ps_SetObjectInfoRequest_REV_Object) */

void zx_ps_SetObjectInfoRequest_REV_Object(struct zx_ps_SetObjectInfoRequest_s* x)
{
  struct zx_ps_Object_s* nxt;
  struct zx_ps_Object_s* y;
  if (!x) return;
  y = x->Object;
  if (!y) return;
  x->Object = 0;
  while (y) {
    nxt = (struct zx_ps_Object_s*)y->gg.g.n;
    y->gg.g.n = &x->Object->gg.g;
    x->Object = y;
    y = nxt;
  }
}

/* FUNC(zx_ps_SetObjectInfoRequest_PUT_Object) */

void zx_ps_SetObjectInfoRequest_PUT_Object(struct zx_ps_SetObjectInfoRequest_s* x, int n, struct zx_ps_Object_s* z)
{
  struct zx_ps_Object_s* y;
  if (!x || !z) return;
  y = x->Object;
  if (!y) return;
  switch (n) {
  case 0:
    z->gg.g.n = y->gg.g.n;
    x->Object = z;
    return;
  default:
    for (; n > 1 && y->gg.g.n; --n, y = (struct zx_ps_Object_s*)y->gg.g.n) ;
    if (!y->gg.g.n) return;
    z->gg.g.n = y->gg.g.n->n;
    y->gg.g.n = &z->gg.g;
  }
}

/* FUNC(zx_ps_SetObjectInfoRequest_ADD_Object) */

void zx_ps_SetObjectInfoRequest_ADD_Object(struct zx_ps_SetObjectInfoRequest_s* x, int n, struct zx_ps_Object_s* z)
{
  struct zx_ps_Object_s* y;
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
    for (; y->gg.g.n; y = (struct zx_ps_Object_s*)y->gg.g.n) ;
    break;
  default:
    for (y = x->Object; n > 1 && y; --n, y = (struct zx_ps_Object_s*)y->gg.g.n) ;
    if (!y) return;
  }
  z->gg.g.n = y->gg.g.n;
  y->gg.g.n = &z->gg.g;
}

/* FUNC(zx_ps_SetObjectInfoRequest_DEL_Object) */

void zx_ps_SetObjectInfoRequest_DEL_Object(struct zx_ps_SetObjectInfoRequest_s* x, int n)
{
  struct zx_ps_Object_s* y;
  if (!x) return;
  switch (n) {
  case 0:
    x->Object = (struct zx_ps_Object_s*)x->Object->gg.g.n;
    return;
  case -1:
    y = (struct zx_ps_Object_s*)x->Object;
    if (!y) return;
    for (; y->gg.g.n; y = (struct zx_ps_Object_s*)y->gg.g.n) ;
    break;
  default:
    for (y = x->Object; n > 1 && y->gg.g.n; --n, y = (struct zx_ps_Object_s*)y->gg.g.n) ;
    if (!y->gg.g.n) return;
  }
  y->gg.g.n = y->gg.g.n->n;
}

#endif



#ifdef ZX_ENA_GETPUT

/* FUNC(zx_ps_SetObjectInfoRequest_NUM_Subscription) */

int zx_ps_SetObjectInfoRequest_NUM_Subscription(struct zx_ps_SetObjectInfoRequest_s* x)
{
  struct zx_ps_Subscription_s* y;
  int n = 0;
  if (!x) return 0;
  for (y = x->Subscription; y; ++n, y = (struct zx_ps_Subscription_s*)y->gg.g.n) ;
  return n;
}

/* FUNC(zx_ps_SetObjectInfoRequest_GET_Subscription) */

struct zx_ps_Subscription_s* zx_ps_SetObjectInfoRequest_GET_Subscription(struct zx_ps_SetObjectInfoRequest_s* x, int n)
{
  struct zx_ps_Subscription_s* y;
  if (!x) return 0;
  for (y = x->Subscription; n>=0 && y; --n, y = (struct zx_ps_Subscription_s*)y->gg.g.n) ;
  return y;
}

/* FUNC(zx_ps_SetObjectInfoRequest_POP_Subscription) */

struct zx_ps_Subscription_s* zx_ps_SetObjectInfoRequest_POP_Subscription(struct zx_ps_SetObjectInfoRequest_s* x)
{
  struct zx_ps_Subscription_s* y;
  if (!x) return 0;
  y = x->Subscription;
  if (y)
    x->Subscription = (struct zx_ps_Subscription_s*)y->gg.g.n;
  return y;
}

/* FUNC(zx_ps_SetObjectInfoRequest_PUSH_Subscription) */

void zx_ps_SetObjectInfoRequest_PUSH_Subscription(struct zx_ps_SetObjectInfoRequest_s* x, struct zx_ps_Subscription_s* z)
{
  if (!x || !z) return;
  z->gg.g.n = &x->Subscription->gg.g;
  x->Subscription = z;
}

/* FUNC(zx_ps_SetObjectInfoRequest_REV_Subscription) */

void zx_ps_SetObjectInfoRequest_REV_Subscription(struct zx_ps_SetObjectInfoRequest_s* x)
{
  struct zx_ps_Subscription_s* nxt;
  struct zx_ps_Subscription_s* y;
  if (!x) return;
  y = x->Subscription;
  if (!y) return;
  x->Subscription = 0;
  while (y) {
    nxt = (struct zx_ps_Subscription_s*)y->gg.g.n;
    y->gg.g.n = &x->Subscription->gg.g;
    x->Subscription = y;
    y = nxt;
  }
}

/* FUNC(zx_ps_SetObjectInfoRequest_PUT_Subscription) */

void zx_ps_SetObjectInfoRequest_PUT_Subscription(struct zx_ps_SetObjectInfoRequest_s* x, int n, struct zx_ps_Subscription_s* z)
{
  struct zx_ps_Subscription_s* y;
  if (!x || !z) return;
  y = x->Subscription;
  if (!y) return;
  switch (n) {
  case 0:
    z->gg.g.n = y->gg.g.n;
    x->Subscription = z;
    return;
  default:
    for (; n > 1 && y->gg.g.n; --n, y = (struct zx_ps_Subscription_s*)y->gg.g.n) ;
    if (!y->gg.g.n) return;
    z->gg.g.n = y->gg.g.n->n;
    y->gg.g.n = &z->gg.g;
  }
}

/* FUNC(zx_ps_SetObjectInfoRequest_ADD_Subscription) */

void zx_ps_SetObjectInfoRequest_ADD_Subscription(struct zx_ps_SetObjectInfoRequest_s* x, int n, struct zx_ps_Subscription_s* z)
{
  struct zx_ps_Subscription_s* y;
  if (!x || !z) return;
  switch (n) {
  case 0:
  add_to_start:
    z->gg.g.n = &x->Subscription->gg.g;
    x->Subscription = z;
    return;
  case -1:
    y = x->Subscription;
    if (!y) goto add_to_start;
    for (; y->gg.g.n; y = (struct zx_ps_Subscription_s*)y->gg.g.n) ;
    break;
  default:
    for (y = x->Subscription; n > 1 && y; --n, y = (struct zx_ps_Subscription_s*)y->gg.g.n) ;
    if (!y) return;
  }
  z->gg.g.n = y->gg.g.n;
  y->gg.g.n = &z->gg.g;
}

/* FUNC(zx_ps_SetObjectInfoRequest_DEL_Subscription) */

void zx_ps_SetObjectInfoRequest_DEL_Subscription(struct zx_ps_SetObjectInfoRequest_s* x, int n)
{
  struct zx_ps_Subscription_s* y;
  if (!x) return;
  switch (n) {
  case 0:
    x->Subscription = (struct zx_ps_Subscription_s*)x->Subscription->gg.g.n;
    return;
  case -1:
    y = (struct zx_ps_Subscription_s*)x->Subscription;
    if (!y) return;
    for (; y->gg.g.n; y = (struct zx_ps_Subscription_s*)y->gg.g.n) ;
    break;
  default:
    for (y = x->Subscription; n > 1 && y->gg.g.n; --n, y = (struct zx_ps_Subscription_s*)y->gg.g.n) ;
    if (!y->gg.g.n) return;
  }
  y->gg.g.n = y->gg.g.n->n;
}

#endif

/* FUNC(zx_ps_SetObjectInfoRequest_GET_id) */
struct zx_str* zx_ps_SetObjectInfoRequest_GET_id(struct zx_ps_SetObjectInfoRequest_s* x) { return x->id; }
/* FUNC(zx_ps_SetObjectInfoRequest_PUT_id) */
void zx_ps_SetObjectInfoRequest_PUT_id(struct zx_ps_SetObjectInfoRequest_s* x, struct zx_str* y) { x->id = y; }







#ifdef ZX_ENA_GETPUT

/* FUNC(zx_ps_SetObjectInfoResponse_NUM_Status) */

int zx_ps_SetObjectInfoResponse_NUM_Status(struct zx_ps_SetObjectInfoResponse_s* x)
{
  struct zx_lu_Status_s* y;
  int n = 0;
  if (!x) return 0;
  for (y = x->Status; y; ++n, y = (struct zx_lu_Status_s*)y->gg.g.n) ;
  return n;
}

/* FUNC(zx_ps_SetObjectInfoResponse_GET_Status) */

struct zx_lu_Status_s* zx_ps_SetObjectInfoResponse_GET_Status(struct zx_ps_SetObjectInfoResponse_s* x, int n)
{
  struct zx_lu_Status_s* y;
  if (!x) return 0;
  for (y = x->Status; n>=0 && y; --n, y = (struct zx_lu_Status_s*)y->gg.g.n) ;
  return y;
}

/* FUNC(zx_ps_SetObjectInfoResponse_POP_Status) */

struct zx_lu_Status_s* zx_ps_SetObjectInfoResponse_POP_Status(struct zx_ps_SetObjectInfoResponse_s* x)
{
  struct zx_lu_Status_s* y;
  if (!x) return 0;
  y = x->Status;
  if (y)
    x->Status = (struct zx_lu_Status_s*)y->gg.g.n;
  return y;
}

/* FUNC(zx_ps_SetObjectInfoResponse_PUSH_Status) */

void zx_ps_SetObjectInfoResponse_PUSH_Status(struct zx_ps_SetObjectInfoResponse_s* x, struct zx_lu_Status_s* z)
{
  if (!x || !z) return;
  z->gg.g.n = &x->Status->gg.g;
  x->Status = z;
}

/* FUNC(zx_ps_SetObjectInfoResponse_REV_Status) */

void zx_ps_SetObjectInfoResponse_REV_Status(struct zx_ps_SetObjectInfoResponse_s* x)
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

/* FUNC(zx_ps_SetObjectInfoResponse_PUT_Status) */

void zx_ps_SetObjectInfoResponse_PUT_Status(struct zx_ps_SetObjectInfoResponse_s* x, int n, struct zx_lu_Status_s* z)
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

/* FUNC(zx_ps_SetObjectInfoResponse_ADD_Status) */

void zx_ps_SetObjectInfoResponse_ADD_Status(struct zx_ps_SetObjectInfoResponse_s* x, int n, struct zx_lu_Status_s* z)
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

/* FUNC(zx_ps_SetObjectInfoResponse_DEL_Status) */

void zx_ps_SetObjectInfoResponse_DEL_Status(struct zx_ps_SetObjectInfoResponse_s* x, int n)
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

/* FUNC(zx_ps_SetObjectInfoResponse_GET_TimeStamp) */
struct zx_str* zx_ps_SetObjectInfoResponse_GET_TimeStamp(struct zx_ps_SetObjectInfoResponse_s* x) { return x->TimeStamp; }
/* FUNC(zx_ps_SetObjectInfoResponse_PUT_TimeStamp) */
void zx_ps_SetObjectInfoResponse_PUT_TimeStamp(struct zx_ps_SetObjectInfoResponse_s* x, struct zx_str* y) { x->TimeStamp = y; }
/* FUNC(zx_ps_SetObjectInfoResponse_GET_id) */
struct zx_str* zx_ps_SetObjectInfoResponse_GET_id(struct zx_ps_SetObjectInfoResponse_s* x) { return x->id; }
/* FUNC(zx_ps_SetObjectInfoResponse_PUT_id) */
void zx_ps_SetObjectInfoResponse_PUT_id(struct zx_ps_SetObjectInfoResponse_s* x, struct zx_str* y) { x->id = y; }







#ifdef ZX_ENA_GETPUT

/* FUNC(zx_ps_Subscription_NUM_RefItem) */

int zx_ps_Subscription_NUM_RefItem(struct zx_ps_Subscription_s* x)
{
  struct zx_subs_RefItem_s* y;
  int n = 0;
  if (!x) return 0;
  for (y = x->RefItem; y; ++n, y = (struct zx_subs_RefItem_s*)y->gg.g.n) ;
  return n;
}

/* FUNC(zx_ps_Subscription_GET_RefItem) */

struct zx_subs_RefItem_s* zx_ps_Subscription_GET_RefItem(struct zx_ps_Subscription_s* x, int n)
{
  struct zx_subs_RefItem_s* y;
  if (!x) return 0;
  for (y = x->RefItem; n>=0 && y; --n, y = (struct zx_subs_RefItem_s*)y->gg.g.n) ;
  return y;
}

/* FUNC(zx_ps_Subscription_POP_RefItem) */

struct zx_subs_RefItem_s* zx_ps_Subscription_POP_RefItem(struct zx_ps_Subscription_s* x)
{
  struct zx_subs_RefItem_s* y;
  if (!x) return 0;
  y = x->RefItem;
  if (y)
    x->RefItem = (struct zx_subs_RefItem_s*)y->gg.g.n;
  return y;
}

/* FUNC(zx_ps_Subscription_PUSH_RefItem) */

void zx_ps_Subscription_PUSH_RefItem(struct zx_ps_Subscription_s* x, struct zx_subs_RefItem_s* z)
{
  if (!x || !z) return;
  z->gg.g.n = &x->RefItem->gg.g;
  x->RefItem = z;
}

/* FUNC(zx_ps_Subscription_REV_RefItem) */

void zx_ps_Subscription_REV_RefItem(struct zx_ps_Subscription_s* x)
{
  struct zx_subs_RefItem_s* nxt;
  struct zx_subs_RefItem_s* y;
  if (!x) return;
  y = x->RefItem;
  if (!y) return;
  x->RefItem = 0;
  while (y) {
    nxt = (struct zx_subs_RefItem_s*)y->gg.g.n;
    y->gg.g.n = &x->RefItem->gg.g;
    x->RefItem = y;
    y = nxt;
  }
}

/* FUNC(zx_ps_Subscription_PUT_RefItem) */

void zx_ps_Subscription_PUT_RefItem(struct zx_ps_Subscription_s* x, int n, struct zx_subs_RefItem_s* z)
{
  struct zx_subs_RefItem_s* y;
  if (!x || !z) return;
  y = x->RefItem;
  if (!y) return;
  switch (n) {
  case 0:
    z->gg.g.n = y->gg.g.n;
    x->RefItem = z;
    return;
  default:
    for (; n > 1 && y->gg.g.n; --n, y = (struct zx_subs_RefItem_s*)y->gg.g.n) ;
    if (!y->gg.g.n) return;
    z->gg.g.n = y->gg.g.n->n;
    y->gg.g.n = &z->gg.g;
  }
}

/* FUNC(zx_ps_Subscription_ADD_RefItem) */

void zx_ps_Subscription_ADD_RefItem(struct zx_ps_Subscription_s* x, int n, struct zx_subs_RefItem_s* z)
{
  struct zx_subs_RefItem_s* y;
  if (!x || !z) return;
  switch (n) {
  case 0:
  add_to_start:
    z->gg.g.n = &x->RefItem->gg.g;
    x->RefItem = z;
    return;
  case -1:
    y = x->RefItem;
    if (!y) goto add_to_start;
    for (; y->gg.g.n; y = (struct zx_subs_RefItem_s*)y->gg.g.n) ;
    break;
  default:
    for (y = x->RefItem; n > 1 && y; --n, y = (struct zx_subs_RefItem_s*)y->gg.g.n) ;
    if (!y) return;
  }
  z->gg.g.n = y->gg.g.n;
  y->gg.g.n = &z->gg.g;
}

/* FUNC(zx_ps_Subscription_DEL_RefItem) */

void zx_ps_Subscription_DEL_RefItem(struct zx_ps_Subscription_s* x, int n)
{
  struct zx_subs_RefItem_s* y;
  if (!x) return;
  switch (n) {
  case 0:
    x->RefItem = (struct zx_subs_RefItem_s*)x->RefItem->gg.g.n;
    return;
  case -1:
    y = (struct zx_subs_RefItem_s*)x->RefItem;
    if (!y) return;
    for (; y->gg.g.n; y = (struct zx_subs_RefItem_s*)y->gg.g.n) ;
    break;
  default:
    for (y = x->RefItem; n > 1 && y->gg.g.n; --n, y = (struct zx_subs_RefItem_s*)y->gg.g.n) ;
    if (!y->gg.g.n) return;
  }
  y->gg.g.n = y->gg.g.n->n;
}

#endif



#ifdef ZX_ENA_GETPUT

/* FUNC(zx_ps_Subscription_NUM_Extension) */

int zx_ps_Subscription_NUM_Extension(struct zx_ps_Subscription_s* x)
{
  struct zx_lu_Extension_s* y;
  int n = 0;
  if (!x) return 0;
  for (y = x->Extension; y; ++n, y = (struct zx_lu_Extension_s*)y->gg.g.n) ;
  return n;
}

/* FUNC(zx_ps_Subscription_GET_Extension) */

struct zx_lu_Extension_s* zx_ps_Subscription_GET_Extension(struct zx_ps_Subscription_s* x, int n)
{
  struct zx_lu_Extension_s* y;
  if (!x) return 0;
  for (y = x->Extension; n>=0 && y; --n, y = (struct zx_lu_Extension_s*)y->gg.g.n) ;
  return y;
}

/* FUNC(zx_ps_Subscription_POP_Extension) */

struct zx_lu_Extension_s* zx_ps_Subscription_POP_Extension(struct zx_ps_Subscription_s* x)
{
  struct zx_lu_Extension_s* y;
  if (!x) return 0;
  y = x->Extension;
  if (y)
    x->Extension = (struct zx_lu_Extension_s*)y->gg.g.n;
  return y;
}

/* FUNC(zx_ps_Subscription_PUSH_Extension) */

void zx_ps_Subscription_PUSH_Extension(struct zx_ps_Subscription_s* x, struct zx_lu_Extension_s* z)
{
  if (!x || !z) return;
  z->gg.g.n = &x->Extension->gg.g;
  x->Extension = z;
}

/* FUNC(zx_ps_Subscription_REV_Extension) */

void zx_ps_Subscription_REV_Extension(struct zx_ps_Subscription_s* x)
{
  struct zx_lu_Extension_s* nxt;
  struct zx_lu_Extension_s* y;
  if (!x) return;
  y = x->Extension;
  if (!y) return;
  x->Extension = 0;
  while (y) {
    nxt = (struct zx_lu_Extension_s*)y->gg.g.n;
    y->gg.g.n = &x->Extension->gg.g;
    x->Extension = y;
    y = nxt;
  }
}

/* FUNC(zx_ps_Subscription_PUT_Extension) */

void zx_ps_Subscription_PUT_Extension(struct zx_ps_Subscription_s* x, int n, struct zx_lu_Extension_s* z)
{
  struct zx_lu_Extension_s* y;
  if (!x || !z) return;
  y = x->Extension;
  if (!y) return;
  switch (n) {
  case 0:
    z->gg.g.n = y->gg.g.n;
    x->Extension = z;
    return;
  default:
    for (; n > 1 && y->gg.g.n; --n, y = (struct zx_lu_Extension_s*)y->gg.g.n) ;
    if (!y->gg.g.n) return;
    z->gg.g.n = y->gg.g.n->n;
    y->gg.g.n = &z->gg.g;
  }
}

/* FUNC(zx_ps_Subscription_ADD_Extension) */

void zx_ps_Subscription_ADD_Extension(struct zx_ps_Subscription_s* x, int n, struct zx_lu_Extension_s* z)
{
  struct zx_lu_Extension_s* y;
  if (!x || !z) return;
  switch (n) {
  case 0:
  add_to_start:
    z->gg.g.n = &x->Extension->gg.g;
    x->Extension = z;
    return;
  case -1:
    y = x->Extension;
    if (!y) goto add_to_start;
    for (; y->gg.g.n; y = (struct zx_lu_Extension_s*)y->gg.g.n) ;
    break;
  default:
    for (y = x->Extension; n > 1 && y; --n, y = (struct zx_lu_Extension_s*)y->gg.g.n) ;
    if (!y) return;
  }
  z->gg.g.n = y->gg.g.n;
  y->gg.g.n = &z->gg.g;
}

/* FUNC(zx_ps_Subscription_DEL_Extension) */

void zx_ps_Subscription_DEL_Extension(struct zx_ps_Subscription_s* x, int n)
{
  struct zx_lu_Extension_s* y;
  if (!x) return;
  switch (n) {
  case 0:
    x->Extension = (struct zx_lu_Extension_s*)x->Extension->gg.g.n;
    return;
  case -1:
    y = (struct zx_lu_Extension_s*)x->Extension;
    if (!y) return;
    for (; y->gg.g.n; y = (struct zx_lu_Extension_s*)y->gg.g.n) ;
    break;
  default:
    for (y = x->Extension; n > 1 && y->gg.g.n; --n, y = (struct zx_lu_Extension_s*)y->gg.g.n) ;
    if (!y->gg.g.n) return;
  }
  y->gg.g.n = y->gg.g.n->n;
}

#endif

/* FUNC(zx_ps_Subscription_GET_adminNotifyToRef) */
struct zx_str* zx_ps_Subscription_GET_adminNotifyToRef(struct zx_ps_Subscription_s* x) { return x->adminNotifyToRef; }
/* FUNC(zx_ps_Subscription_PUT_adminNotifyToRef) */
void zx_ps_Subscription_PUT_adminNotifyToRef(struct zx_ps_Subscription_s* x, struct zx_str* y) { x->adminNotifyToRef = y; }
/* FUNC(zx_ps_Subscription_GET_expires) */
struct zx_str* zx_ps_Subscription_GET_expires(struct zx_ps_Subscription_s* x) { return x->expires; }
/* FUNC(zx_ps_Subscription_PUT_expires) */
void zx_ps_Subscription_PUT_expires(struct zx_ps_Subscription_s* x, struct zx_str* y) { x->expires = y; }
/* FUNC(zx_ps_Subscription_GET_id) */
struct zx_str* zx_ps_Subscription_GET_id(struct zx_ps_Subscription_s* x) { return x->id; }
/* FUNC(zx_ps_Subscription_PUT_id) */
void zx_ps_Subscription_PUT_id(struct zx_ps_Subscription_s* x, struct zx_str* y) { x->id = y; }
/* FUNC(zx_ps_Subscription_GET_includeData) */
struct zx_str* zx_ps_Subscription_GET_includeData(struct zx_ps_Subscription_s* x) { return x->includeData; }
/* FUNC(zx_ps_Subscription_PUT_includeData) */
void zx_ps_Subscription_PUT_includeData(struct zx_ps_Subscription_s* x, struct zx_str* y) { x->includeData = y; }
/* FUNC(zx_ps_Subscription_GET_notifyToRef) */
struct zx_str* zx_ps_Subscription_GET_notifyToRef(struct zx_ps_Subscription_s* x) { return x->notifyToRef; }
/* FUNC(zx_ps_Subscription_PUT_notifyToRef) */
void zx_ps_Subscription_PUT_notifyToRef(struct zx_ps_Subscription_s* x, struct zx_str* y) { x->notifyToRef = y; }
/* FUNC(zx_ps_Subscription_GET_starts) */
struct zx_str* zx_ps_Subscription_GET_starts(struct zx_ps_Subscription_s* x) { return x->starts; }
/* FUNC(zx_ps_Subscription_PUT_starts) */
void zx_ps_Subscription_PUT_starts(struct zx_ps_Subscription_s* x, struct zx_str* y) { x->starts = y; }
/* FUNC(zx_ps_Subscription_GET_subscriptionID) */
struct zx_str* zx_ps_Subscription_GET_subscriptionID(struct zx_ps_Subscription_s* x) { return x->subscriptionID; }
/* FUNC(zx_ps_Subscription_PUT_subscriptionID) */
void zx_ps_Subscription_PUT_subscriptionID(struct zx_ps_Subscription_s* x, struct zx_str* y) { x->subscriptionID = y; }





/* FUNC(zx_ps_Tag_GET_Ref) */
struct zx_str* zx_ps_Tag_GET_Ref(struct zx_ps_Tag_s* x) { return x->Ref; }
/* FUNC(zx_ps_Tag_PUT_Ref) */
void zx_ps_Tag_PUT_Ref(struct zx_ps_Tag_s* x, struct zx_str* y) { x->Ref = y; }







#ifdef ZX_ENA_GETPUT

/* FUNC(zx_ps_TestMembershipRequest_NUM_TargetObjectID) */

int zx_ps_TestMembershipRequest_NUM_TargetObjectID(struct zx_ps_TestMembershipRequest_s* x)
{
  struct zx_elem_s* y;
  int n = 0;
  if (!x) return 0;
  for (y = x->TargetObjectID; y; ++n, y = (struct zx_elem_s*)y->g.n) ;
  return n;
}

/* FUNC(zx_ps_TestMembershipRequest_GET_TargetObjectID) */

struct zx_elem_s* zx_ps_TestMembershipRequest_GET_TargetObjectID(struct zx_ps_TestMembershipRequest_s* x, int n)
{
  struct zx_elem_s* y;
  if (!x) return 0;
  for (y = x->TargetObjectID; n>=0 && y; --n, y = (struct zx_elem_s*)y->g.n) ;
  return y;
}

/* FUNC(zx_ps_TestMembershipRequest_POP_TargetObjectID) */

struct zx_elem_s* zx_ps_TestMembershipRequest_POP_TargetObjectID(struct zx_ps_TestMembershipRequest_s* x)
{
  struct zx_elem_s* y;
  if (!x) return 0;
  y = x->TargetObjectID;
  if (y)
    x->TargetObjectID = (struct zx_elem_s*)y->g.n;
  return y;
}

/* FUNC(zx_ps_TestMembershipRequest_PUSH_TargetObjectID) */

void zx_ps_TestMembershipRequest_PUSH_TargetObjectID(struct zx_ps_TestMembershipRequest_s* x, struct zx_elem_s* z)
{
  if (!x || !z) return;
  z->g.n = &x->TargetObjectID->g;
  x->TargetObjectID = z;
}

/* FUNC(zx_ps_TestMembershipRequest_REV_TargetObjectID) */

void zx_ps_TestMembershipRequest_REV_TargetObjectID(struct zx_ps_TestMembershipRequest_s* x)
{
  struct zx_elem_s* nxt;
  struct zx_elem_s* y;
  if (!x) return;
  y = x->TargetObjectID;
  if (!y) return;
  x->TargetObjectID = 0;
  while (y) {
    nxt = (struct zx_elem_s*)y->g.n;
    y->g.n = &x->TargetObjectID->g;
    x->TargetObjectID = y;
    y = nxt;
  }
}

/* FUNC(zx_ps_TestMembershipRequest_PUT_TargetObjectID) */

void zx_ps_TestMembershipRequest_PUT_TargetObjectID(struct zx_ps_TestMembershipRequest_s* x, int n, struct zx_elem_s* z)
{
  struct zx_elem_s* y;
  if (!x || !z) return;
  y = x->TargetObjectID;
  if (!y) return;
  switch (n) {
  case 0:
    z->g.n = y->g.n;
    x->TargetObjectID = z;
    return;
  default:
    for (; n > 1 && y->g.n; --n, y = (struct zx_elem_s*)y->g.n) ;
    if (!y->g.n) return;
    z->g.n = y->g.n->n;
    y->g.n = &z->g;
  }
}

/* FUNC(zx_ps_TestMembershipRequest_ADD_TargetObjectID) */

void zx_ps_TestMembershipRequest_ADD_TargetObjectID(struct zx_ps_TestMembershipRequest_s* x, int n, struct zx_elem_s* z)
{
  struct zx_elem_s* y;
  if (!x || !z) return;
  switch (n) {
  case 0:
  add_to_start:
    z->g.n = &x->TargetObjectID->g;
    x->TargetObjectID = z;
    return;
  case -1:
    y = x->TargetObjectID;
    if (!y) goto add_to_start;
    for (; y->g.n; y = (struct zx_elem_s*)y->g.n) ;
    break;
  default:
    for (y = x->TargetObjectID; n > 1 && y; --n, y = (struct zx_elem_s*)y->g.n) ;
    if (!y) return;
  }
  z->g.n = y->g.n;
  y->g.n = &z->g;
}

/* FUNC(zx_ps_TestMembershipRequest_DEL_TargetObjectID) */

void zx_ps_TestMembershipRequest_DEL_TargetObjectID(struct zx_ps_TestMembershipRequest_s* x, int n)
{
  struct zx_elem_s* y;
  if (!x) return;
  switch (n) {
  case 0:
    x->TargetObjectID = (struct zx_elem_s*)x->TargetObjectID->g.n;
    return;
  case -1:
    y = (struct zx_elem_s*)x->TargetObjectID;
    if (!y) return;
    for (; y->g.n; y = (struct zx_elem_s*)y->g.n) ;
    break;
  default:
    for (y = x->TargetObjectID; n > 1 && y->g.n; --n, y = (struct zx_elem_s*)y->g.n) ;
    if (!y->g.n) return;
  }
  y->g.n = y->g.n->n;
}

#endif



#ifdef ZX_ENA_GETPUT

/* FUNC(zx_ps_TestMembershipRequest_NUM_Token) */

int zx_ps_TestMembershipRequest_NUM_Token(struct zx_ps_TestMembershipRequest_s* x)
{
  struct zx_sec_Token_s* y;
  int n = 0;
  if (!x) return 0;
  for (y = x->Token; y; ++n, y = (struct zx_sec_Token_s*)y->gg.g.n) ;
  return n;
}

/* FUNC(zx_ps_TestMembershipRequest_GET_Token) */

struct zx_sec_Token_s* zx_ps_TestMembershipRequest_GET_Token(struct zx_ps_TestMembershipRequest_s* x, int n)
{
  struct zx_sec_Token_s* y;
  if (!x) return 0;
  for (y = x->Token; n>=0 && y; --n, y = (struct zx_sec_Token_s*)y->gg.g.n) ;
  return y;
}

/* FUNC(zx_ps_TestMembershipRequest_POP_Token) */

struct zx_sec_Token_s* zx_ps_TestMembershipRequest_POP_Token(struct zx_ps_TestMembershipRequest_s* x)
{
  struct zx_sec_Token_s* y;
  if (!x) return 0;
  y = x->Token;
  if (y)
    x->Token = (struct zx_sec_Token_s*)y->gg.g.n;
  return y;
}

/* FUNC(zx_ps_TestMembershipRequest_PUSH_Token) */

void zx_ps_TestMembershipRequest_PUSH_Token(struct zx_ps_TestMembershipRequest_s* x, struct zx_sec_Token_s* z)
{
  if (!x || !z) return;
  z->gg.g.n = &x->Token->gg.g;
  x->Token = z;
}

/* FUNC(zx_ps_TestMembershipRequest_REV_Token) */

void zx_ps_TestMembershipRequest_REV_Token(struct zx_ps_TestMembershipRequest_s* x)
{
  struct zx_sec_Token_s* nxt;
  struct zx_sec_Token_s* y;
  if (!x) return;
  y = x->Token;
  if (!y) return;
  x->Token = 0;
  while (y) {
    nxt = (struct zx_sec_Token_s*)y->gg.g.n;
    y->gg.g.n = &x->Token->gg.g;
    x->Token = y;
    y = nxt;
  }
}

/* FUNC(zx_ps_TestMembershipRequest_PUT_Token) */

void zx_ps_TestMembershipRequest_PUT_Token(struct zx_ps_TestMembershipRequest_s* x, int n, struct zx_sec_Token_s* z)
{
  struct zx_sec_Token_s* y;
  if (!x || !z) return;
  y = x->Token;
  if (!y) return;
  switch (n) {
  case 0:
    z->gg.g.n = y->gg.g.n;
    x->Token = z;
    return;
  default:
    for (; n > 1 && y->gg.g.n; --n, y = (struct zx_sec_Token_s*)y->gg.g.n) ;
    if (!y->gg.g.n) return;
    z->gg.g.n = y->gg.g.n->n;
    y->gg.g.n = &z->gg.g;
  }
}

/* FUNC(zx_ps_TestMembershipRequest_ADD_Token) */

void zx_ps_TestMembershipRequest_ADD_Token(struct zx_ps_TestMembershipRequest_s* x, int n, struct zx_sec_Token_s* z)
{
  struct zx_sec_Token_s* y;
  if (!x || !z) return;
  switch (n) {
  case 0:
  add_to_start:
    z->gg.g.n = &x->Token->gg.g;
    x->Token = z;
    return;
  case -1:
    y = x->Token;
    if (!y) goto add_to_start;
    for (; y->gg.g.n; y = (struct zx_sec_Token_s*)y->gg.g.n) ;
    break;
  default:
    for (y = x->Token; n > 1 && y; --n, y = (struct zx_sec_Token_s*)y->gg.g.n) ;
    if (!y) return;
  }
  z->gg.g.n = y->gg.g.n;
  y->gg.g.n = &z->gg.g;
}

/* FUNC(zx_ps_TestMembershipRequest_DEL_Token) */

void zx_ps_TestMembershipRequest_DEL_Token(struct zx_ps_TestMembershipRequest_s* x, int n)
{
  struct zx_sec_Token_s* y;
  if (!x) return;
  switch (n) {
  case 0:
    x->Token = (struct zx_sec_Token_s*)x->Token->gg.g.n;
    return;
  case -1:
    y = (struct zx_sec_Token_s*)x->Token;
    if (!y) return;
    for (; y->gg.g.n; y = (struct zx_sec_Token_s*)y->gg.g.n) ;
    break;
  default:
    for (y = x->Token; n > 1 && y->gg.g.n; --n, y = (struct zx_sec_Token_s*)y->gg.g.n) ;
    if (!y->gg.g.n) return;
  }
  y->gg.g.n = y->gg.g.n->n;
}

#endif



#ifdef ZX_ENA_GETPUT

/* FUNC(zx_ps_TestMembershipRequest_NUM_Subscription) */

int zx_ps_TestMembershipRequest_NUM_Subscription(struct zx_ps_TestMembershipRequest_s* x)
{
  struct zx_ps_Subscription_s* y;
  int n = 0;
  if (!x) return 0;
  for (y = x->Subscription; y; ++n, y = (struct zx_ps_Subscription_s*)y->gg.g.n) ;
  return n;
}

/* FUNC(zx_ps_TestMembershipRequest_GET_Subscription) */

struct zx_ps_Subscription_s* zx_ps_TestMembershipRequest_GET_Subscription(struct zx_ps_TestMembershipRequest_s* x, int n)
{
  struct zx_ps_Subscription_s* y;
  if (!x) return 0;
  for (y = x->Subscription; n>=0 && y; --n, y = (struct zx_ps_Subscription_s*)y->gg.g.n) ;
  return y;
}

/* FUNC(zx_ps_TestMembershipRequest_POP_Subscription) */

struct zx_ps_Subscription_s* zx_ps_TestMembershipRequest_POP_Subscription(struct zx_ps_TestMembershipRequest_s* x)
{
  struct zx_ps_Subscription_s* y;
  if (!x) return 0;
  y = x->Subscription;
  if (y)
    x->Subscription = (struct zx_ps_Subscription_s*)y->gg.g.n;
  return y;
}

/* FUNC(zx_ps_TestMembershipRequest_PUSH_Subscription) */

void zx_ps_TestMembershipRequest_PUSH_Subscription(struct zx_ps_TestMembershipRequest_s* x, struct zx_ps_Subscription_s* z)
{
  if (!x || !z) return;
  z->gg.g.n = &x->Subscription->gg.g;
  x->Subscription = z;
}

/* FUNC(zx_ps_TestMembershipRequest_REV_Subscription) */

void zx_ps_TestMembershipRequest_REV_Subscription(struct zx_ps_TestMembershipRequest_s* x)
{
  struct zx_ps_Subscription_s* nxt;
  struct zx_ps_Subscription_s* y;
  if (!x) return;
  y = x->Subscription;
  if (!y) return;
  x->Subscription = 0;
  while (y) {
    nxt = (struct zx_ps_Subscription_s*)y->gg.g.n;
    y->gg.g.n = &x->Subscription->gg.g;
    x->Subscription = y;
    y = nxt;
  }
}

/* FUNC(zx_ps_TestMembershipRequest_PUT_Subscription) */

void zx_ps_TestMembershipRequest_PUT_Subscription(struct zx_ps_TestMembershipRequest_s* x, int n, struct zx_ps_Subscription_s* z)
{
  struct zx_ps_Subscription_s* y;
  if (!x || !z) return;
  y = x->Subscription;
  if (!y) return;
  switch (n) {
  case 0:
    z->gg.g.n = y->gg.g.n;
    x->Subscription = z;
    return;
  default:
    for (; n > 1 && y->gg.g.n; --n, y = (struct zx_ps_Subscription_s*)y->gg.g.n) ;
    if (!y->gg.g.n) return;
    z->gg.g.n = y->gg.g.n->n;
    y->gg.g.n = &z->gg.g;
  }
}

/* FUNC(zx_ps_TestMembershipRequest_ADD_Subscription) */

void zx_ps_TestMembershipRequest_ADD_Subscription(struct zx_ps_TestMembershipRequest_s* x, int n, struct zx_ps_Subscription_s* z)
{
  struct zx_ps_Subscription_s* y;
  if (!x || !z) return;
  switch (n) {
  case 0:
  add_to_start:
    z->gg.g.n = &x->Subscription->gg.g;
    x->Subscription = z;
    return;
  case -1:
    y = x->Subscription;
    if (!y) goto add_to_start;
    for (; y->gg.g.n; y = (struct zx_ps_Subscription_s*)y->gg.g.n) ;
    break;
  default:
    for (y = x->Subscription; n > 1 && y; --n, y = (struct zx_ps_Subscription_s*)y->gg.g.n) ;
    if (!y) return;
  }
  z->gg.g.n = y->gg.g.n;
  y->gg.g.n = &z->gg.g;
}

/* FUNC(zx_ps_TestMembershipRequest_DEL_Subscription) */

void zx_ps_TestMembershipRequest_DEL_Subscription(struct zx_ps_TestMembershipRequest_s* x, int n)
{
  struct zx_ps_Subscription_s* y;
  if (!x) return;
  switch (n) {
  case 0:
    x->Subscription = (struct zx_ps_Subscription_s*)x->Subscription->gg.g.n;
    return;
  case -1:
    y = (struct zx_ps_Subscription_s*)x->Subscription;
    if (!y) return;
    for (; y->gg.g.n; y = (struct zx_ps_Subscription_s*)y->gg.g.n) ;
    break;
  default:
    for (y = x->Subscription; n > 1 && y->gg.g.n; --n, y = (struct zx_ps_Subscription_s*)y->gg.g.n) ;
    if (!y->gg.g.n) return;
  }
  y->gg.g.n = y->gg.g.n->n;
}

#endif

/* FUNC(zx_ps_TestMembershipRequest_GET_id) */
struct zx_str* zx_ps_TestMembershipRequest_GET_id(struct zx_ps_TestMembershipRequest_s* x) { return x->id; }
/* FUNC(zx_ps_TestMembershipRequest_PUT_id) */
void zx_ps_TestMembershipRequest_PUT_id(struct zx_ps_TestMembershipRequest_s* x, struct zx_str* y) { x->id = y; }







#ifdef ZX_ENA_GETPUT

/* FUNC(zx_ps_TestMembershipResponse_NUM_Status) */

int zx_ps_TestMembershipResponse_NUM_Status(struct zx_ps_TestMembershipResponse_s* x)
{
  struct zx_lu_Status_s* y;
  int n = 0;
  if (!x) return 0;
  for (y = x->Status; y; ++n, y = (struct zx_lu_Status_s*)y->gg.g.n) ;
  return n;
}

/* FUNC(zx_ps_TestMembershipResponse_GET_Status) */

struct zx_lu_Status_s* zx_ps_TestMembershipResponse_GET_Status(struct zx_ps_TestMembershipResponse_s* x, int n)
{
  struct zx_lu_Status_s* y;
  if (!x) return 0;
  for (y = x->Status; n>=0 && y; --n, y = (struct zx_lu_Status_s*)y->gg.g.n) ;
  return y;
}

/* FUNC(zx_ps_TestMembershipResponse_POP_Status) */

struct zx_lu_Status_s* zx_ps_TestMembershipResponse_POP_Status(struct zx_ps_TestMembershipResponse_s* x)
{
  struct zx_lu_Status_s* y;
  if (!x) return 0;
  y = x->Status;
  if (y)
    x->Status = (struct zx_lu_Status_s*)y->gg.g.n;
  return y;
}

/* FUNC(zx_ps_TestMembershipResponse_PUSH_Status) */

void zx_ps_TestMembershipResponse_PUSH_Status(struct zx_ps_TestMembershipResponse_s* x, struct zx_lu_Status_s* z)
{
  if (!x || !z) return;
  z->gg.g.n = &x->Status->gg.g;
  x->Status = z;
}

/* FUNC(zx_ps_TestMembershipResponse_REV_Status) */

void zx_ps_TestMembershipResponse_REV_Status(struct zx_ps_TestMembershipResponse_s* x)
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

/* FUNC(zx_ps_TestMembershipResponse_PUT_Status) */

void zx_ps_TestMembershipResponse_PUT_Status(struct zx_ps_TestMembershipResponse_s* x, int n, struct zx_lu_Status_s* z)
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

/* FUNC(zx_ps_TestMembershipResponse_ADD_Status) */

void zx_ps_TestMembershipResponse_ADD_Status(struct zx_ps_TestMembershipResponse_s* x, int n, struct zx_lu_Status_s* z)
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

/* FUNC(zx_ps_TestMembershipResponse_DEL_Status) */

void zx_ps_TestMembershipResponse_DEL_Status(struct zx_ps_TestMembershipResponse_s* x, int n)
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



#ifdef ZX_ENA_GETPUT

/* FUNC(zx_ps_TestMembershipResponse_NUM_Result) */

int zx_ps_TestMembershipResponse_NUM_Result(struct zx_ps_TestMembershipResponse_s* x)
{
  struct zx_elem_s* y;
  int n = 0;
  if (!x) return 0;
  for (y = x->Result; y; ++n, y = (struct zx_elem_s*)y->g.n) ;
  return n;
}

/* FUNC(zx_ps_TestMembershipResponse_GET_Result) */

struct zx_elem_s* zx_ps_TestMembershipResponse_GET_Result(struct zx_ps_TestMembershipResponse_s* x, int n)
{
  struct zx_elem_s* y;
  if (!x) return 0;
  for (y = x->Result; n>=0 && y; --n, y = (struct zx_elem_s*)y->g.n) ;
  return y;
}

/* FUNC(zx_ps_TestMembershipResponse_POP_Result) */

struct zx_elem_s* zx_ps_TestMembershipResponse_POP_Result(struct zx_ps_TestMembershipResponse_s* x)
{
  struct zx_elem_s* y;
  if (!x) return 0;
  y = x->Result;
  if (y)
    x->Result = (struct zx_elem_s*)y->g.n;
  return y;
}

/* FUNC(zx_ps_TestMembershipResponse_PUSH_Result) */

void zx_ps_TestMembershipResponse_PUSH_Result(struct zx_ps_TestMembershipResponse_s* x, struct zx_elem_s* z)
{
  if (!x || !z) return;
  z->g.n = &x->Result->g;
  x->Result = z;
}

/* FUNC(zx_ps_TestMembershipResponse_REV_Result) */

void zx_ps_TestMembershipResponse_REV_Result(struct zx_ps_TestMembershipResponse_s* x)
{
  struct zx_elem_s* nxt;
  struct zx_elem_s* y;
  if (!x) return;
  y = x->Result;
  if (!y) return;
  x->Result = 0;
  while (y) {
    nxt = (struct zx_elem_s*)y->g.n;
    y->g.n = &x->Result->g;
    x->Result = y;
    y = nxt;
  }
}

/* FUNC(zx_ps_TestMembershipResponse_PUT_Result) */

void zx_ps_TestMembershipResponse_PUT_Result(struct zx_ps_TestMembershipResponse_s* x, int n, struct zx_elem_s* z)
{
  struct zx_elem_s* y;
  if (!x || !z) return;
  y = x->Result;
  if (!y) return;
  switch (n) {
  case 0:
    z->g.n = y->g.n;
    x->Result = z;
    return;
  default:
    for (; n > 1 && y->g.n; --n, y = (struct zx_elem_s*)y->g.n) ;
    if (!y->g.n) return;
    z->g.n = y->g.n->n;
    y->g.n = &z->g;
  }
}

/* FUNC(zx_ps_TestMembershipResponse_ADD_Result) */

void zx_ps_TestMembershipResponse_ADD_Result(struct zx_ps_TestMembershipResponse_s* x, int n, struct zx_elem_s* z)
{
  struct zx_elem_s* y;
  if (!x || !z) return;
  switch (n) {
  case 0:
  add_to_start:
    z->g.n = &x->Result->g;
    x->Result = z;
    return;
  case -1:
    y = x->Result;
    if (!y) goto add_to_start;
    for (; y->g.n; y = (struct zx_elem_s*)y->g.n) ;
    break;
  default:
    for (y = x->Result; n > 1 && y; --n, y = (struct zx_elem_s*)y->g.n) ;
    if (!y) return;
  }
  z->g.n = y->g.n;
  y->g.n = &z->g;
}

/* FUNC(zx_ps_TestMembershipResponse_DEL_Result) */

void zx_ps_TestMembershipResponse_DEL_Result(struct zx_ps_TestMembershipResponse_s* x, int n)
{
  struct zx_elem_s* y;
  if (!x) return;
  switch (n) {
  case 0:
    x->Result = (struct zx_elem_s*)x->Result->g.n;
    return;
  case -1:
    y = (struct zx_elem_s*)x->Result;
    if (!y) return;
    for (; y->g.n; y = (struct zx_elem_s*)y->g.n) ;
    break;
  default:
    for (y = x->Result; n > 1 && y->g.n; --n, y = (struct zx_elem_s*)y->g.n) ;
    if (!y->g.n) return;
  }
  y->g.n = y->g.n->n;
}

#endif

/* FUNC(zx_ps_TestMembershipResponse_GET_TimeStamp) */
struct zx_str* zx_ps_TestMembershipResponse_GET_TimeStamp(struct zx_ps_TestMembershipResponse_s* x) { return x->TimeStamp; }
/* FUNC(zx_ps_TestMembershipResponse_PUT_TimeStamp) */
void zx_ps_TestMembershipResponse_PUT_TimeStamp(struct zx_ps_TestMembershipResponse_s* x, struct zx_str* y) { x->TimeStamp = y; }
/* FUNC(zx_ps_TestMembershipResponse_GET_id) */
struct zx_str* zx_ps_TestMembershipResponse_GET_id(struct zx_ps_TestMembershipResponse_s* x) { return x->id; }
/* FUNC(zx_ps_TestMembershipResponse_PUT_id) */
void zx_ps_TestMembershipResponse_PUT_id(struct zx_ps_TestMembershipResponse_s* x, struct zx_str* y) { x->id = y; }





/* EOF -- c/zx-ps-getput.c */
