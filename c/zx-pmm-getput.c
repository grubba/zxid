/* c/zx-pmm-getput.c - WARNING: This file was automatically generated. DO NOT EDIT!
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
#include "c/zx-pmm-data.h"



#ifdef ZX_ENA_GETPUT

/* FUNC(zx_pmm_PMActivate_NUM_PMActivateItem) */

int zx_pmm_PMActivate_NUM_PMActivateItem(struct zx_pmm_PMActivate_s* x)
{
  struct zx_pmm_PMActivateItem_s* y;
  int n = 0;
  if (!x) return 0;
  for (y = x->PMActivateItem; y; ++n, y = (struct zx_pmm_PMActivateItem_s*)y->gg.g.n) ;
  return n;
}

/* FUNC(zx_pmm_PMActivate_GET_PMActivateItem) */

struct zx_pmm_PMActivateItem_s* zx_pmm_PMActivate_GET_PMActivateItem(struct zx_pmm_PMActivate_s* x, int n)
{
  struct zx_pmm_PMActivateItem_s* y;
  if (!x) return 0;
  for (y = x->PMActivateItem; n>=0 && y; --n, y = (struct zx_pmm_PMActivateItem_s*)y->gg.g.n) ;
  return y;
}

/* FUNC(zx_pmm_PMActivate_POP_PMActivateItem) */

struct zx_pmm_PMActivateItem_s* zx_pmm_PMActivate_POP_PMActivateItem(struct zx_pmm_PMActivate_s* x)
{
  struct zx_pmm_PMActivateItem_s* y;
  if (!x) return 0;
  y = x->PMActivateItem;
  if (y)
    x->PMActivateItem = (struct zx_pmm_PMActivateItem_s*)y->gg.g.n;
  return y;
}

/* FUNC(zx_pmm_PMActivate_PUSH_PMActivateItem) */

void zx_pmm_PMActivate_PUSH_PMActivateItem(struct zx_pmm_PMActivate_s* x, struct zx_pmm_PMActivateItem_s* z)
{
  if (!x || !z) return;
  z->gg.g.n = &x->PMActivateItem->gg.g;
  x->PMActivateItem = z;
}

/* FUNC(zx_pmm_PMActivate_REV_PMActivateItem) */

void zx_pmm_PMActivate_REV_PMActivateItem(struct zx_pmm_PMActivate_s* x)
{
  struct zx_pmm_PMActivateItem_s* nxt;
  struct zx_pmm_PMActivateItem_s* y;
  if (!x) return;
  y = x->PMActivateItem;
  if (!y) return;
  x->PMActivateItem = 0;
  while (y) {
    nxt = (struct zx_pmm_PMActivateItem_s*)y->gg.g.n;
    y->gg.g.n = &x->PMActivateItem->gg.g;
    x->PMActivateItem = y;
    y = nxt;
  }
}

/* FUNC(zx_pmm_PMActivate_PUT_PMActivateItem) */

void zx_pmm_PMActivate_PUT_PMActivateItem(struct zx_pmm_PMActivate_s* x, int n, struct zx_pmm_PMActivateItem_s* z)
{
  struct zx_pmm_PMActivateItem_s* y;
  if (!x || !z) return;
  y = x->PMActivateItem;
  if (!y) return;
  switch (n) {
  case 0:
    z->gg.g.n = y->gg.g.n;
    x->PMActivateItem = z;
    return;
  default:
    for (; n > 1 && y->gg.g.n; --n, y = (struct zx_pmm_PMActivateItem_s*)y->gg.g.n) ;
    if (!y->gg.g.n) return;
    z->gg.g.n = y->gg.g.n->n;
    y->gg.g.n = &z->gg.g;
  }
}

/* FUNC(zx_pmm_PMActivate_ADD_PMActivateItem) */

void zx_pmm_PMActivate_ADD_PMActivateItem(struct zx_pmm_PMActivate_s* x, int n, struct zx_pmm_PMActivateItem_s* z)
{
  struct zx_pmm_PMActivateItem_s* y;
  if (!x || !z) return;
  switch (n) {
  case 0:
  add_to_start:
    z->gg.g.n = &x->PMActivateItem->gg.g;
    x->PMActivateItem = z;
    return;
  case -1:
    y = x->PMActivateItem;
    if (!y) goto add_to_start;
    for (; y->gg.g.n; y = (struct zx_pmm_PMActivateItem_s*)y->gg.g.n) ;
    break;
  default:
    for (y = x->PMActivateItem; n > 1 && y; --n, y = (struct zx_pmm_PMActivateItem_s*)y->gg.g.n) ;
    if (!y) return;
  }
  z->gg.g.n = y->gg.g.n;
  y->gg.g.n = &z->gg.g;
}

/* FUNC(zx_pmm_PMActivate_DEL_PMActivateItem) */

void zx_pmm_PMActivate_DEL_PMActivateItem(struct zx_pmm_PMActivate_s* x, int n)
{
  struct zx_pmm_PMActivateItem_s* y;
  if (!x) return;
  switch (n) {
  case 0:
    x->PMActivateItem = (struct zx_pmm_PMActivateItem_s*)x->PMActivateItem->gg.g.n;
    return;
  case -1:
    y = (struct zx_pmm_PMActivateItem_s*)x->PMActivateItem;
    if (!y) return;
    for (; y->gg.g.n; y = (struct zx_pmm_PMActivateItem_s*)y->gg.g.n) ;
    break;
  default:
    for (y = x->PMActivateItem; n > 1 && y->gg.g.n; --n, y = (struct zx_pmm_PMActivateItem_s*)y->gg.g.n) ;
    if (!y->gg.g.n) return;
  }
  y->gg.g.n = y->gg.g.n->n;
}

#endif



#ifdef ZX_ENA_GETPUT

/* FUNC(zx_pmm_PMActivate_NUM_NotifyTo) */

int zx_pmm_PMActivate_NUM_NotifyTo(struct zx_pmm_PMActivate_s* x)
{
  struct zx_elem_s* y;
  int n = 0;
  if (!x) return 0;
  for (y = x->NotifyTo; y; ++n, y = (struct zx_elem_s*)y->g.n) ;
  return n;
}

/* FUNC(zx_pmm_PMActivate_GET_NotifyTo) */

struct zx_elem_s* zx_pmm_PMActivate_GET_NotifyTo(struct zx_pmm_PMActivate_s* x, int n)
{
  struct zx_elem_s* y;
  if (!x) return 0;
  for (y = x->NotifyTo; n>=0 && y; --n, y = (struct zx_elem_s*)y->g.n) ;
  return y;
}

/* FUNC(zx_pmm_PMActivate_POP_NotifyTo) */

struct zx_elem_s* zx_pmm_PMActivate_POP_NotifyTo(struct zx_pmm_PMActivate_s* x)
{
  struct zx_elem_s* y;
  if (!x) return 0;
  y = x->NotifyTo;
  if (y)
    x->NotifyTo = (struct zx_elem_s*)y->g.n;
  return y;
}

/* FUNC(zx_pmm_PMActivate_PUSH_NotifyTo) */

void zx_pmm_PMActivate_PUSH_NotifyTo(struct zx_pmm_PMActivate_s* x, struct zx_elem_s* z)
{
  if (!x || !z) return;
  z->g.n = &x->NotifyTo->g;
  x->NotifyTo = z;
}

/* FUNC(zx_pmm_PMActivate_REV_NotifyTo) */

void zx_pmm_PMActivate_REV_NotifyTo(struct zx_pmm_PMActivate_s* x)
{
  struct zx_elem_s* nxt;
  struct zx_elem_s* y;
  if (!x) return;
  y = x->NotifyTo;
  if (!y) return;
  x->NotifyTo = 0;
  while (y) {
    nxt = (struct zx_elem_s*)y->g.n;
    y->g.n = &x->NotifyTo->g;
    x->NotifyTo = y;
    y = nxt;
  }
}

/* FUNC(zx_pmm_PMActivate_PUT_NotifyTo) */

void zx_pmm_PMActivate_PUT_NotifyTo(struct zx_pmm_PMActivate_s* x, int n, struct zx_elem_s* z)
{
  struct zx_elem_s* y;
  if (!x || !z) return;
  y = x->NotifyTo;
  if (!y) return;
  switch (n) {
  case 0:
    z->g.n = y->g.n;
    x->NotifyTo = z;
    return;
  default:
    for (; n > 1 && y->g.n; --n, y = (struct zx_elem_s*)y->g.n) ;
    if (!y->g.n) return;
    z->g.n = y->g.n->n;
    y->g.n = &z->g;
  }
}

/* FUNC(zx_pmm_PMActivate_ADD_NotifyTo) */

void zx_pmm_PMActivate_ADD_NotifyTo(struct zx_pmm_PMActivate_s* x, int n, struct zx_elem_s* z)
{
  struct zx_elem_s* y;
  if (!x || !z) return;
  switch (n) {
  case 0:
  add_to_start:
    z->g.n = &x->NotifyTo->g;
    x->NotifyTo = z;
    return;
  case -1:
    y = x->NotifyTo;
    if (!y) goto add_to_start;
    for (; y->g.n; y = (struct zx_elem_s*)y->g.n) ;
    break;
  default:
    for (y = x->NotifyTo; n > 1 && y; --n, y = (struct zx_elem_s*)y->g.n) ;
    if (!y) return;
  }
  z->g.n = y->g.n;
  y->g.n = &z->g;
}

/* FUNC(zx_pmm_PMActivate_DEL_NotifyTo) */

void zx_pmm_PMActivate_DEL_NotifyTo(struct zx_pmm_PMActivate_s* x, int n)
{
  struct zx_elem_s* y;
  if (!x) return;
  switch (n) {
  case 0:
    x->NotifyTo = (struct zx_elem_s*)x->NotifyTo->g.n;
    return;
  case -1:
    y = (struct zx_elem_s*)x->NotifyTo;
    if (!y) return;
    for (; y->g.n; y = (struct zx_elem_s*)y->g.n) ;
    break;
  default:
    for (y = x->NotifyTo; n > 1 && y->g.n; --n, y = (struct zx_elem_s*)y->g.n) ;
    if (!y->g.n) return;
  }
  y->g.n = y->g.n->n;
}

#endif








#ifdef ZX_ENA_GETPUT

/* FUNC(zx_pmm_PMActivateItem_NUM_PMID) */

int zx_pmm_PMActivateItem_NUM_PMID(struct zx_pmm_PMActivateItem_s* x)
{
  struct zx_prov_PMID_s* y;
  int n = 0;
  if (!x) return 0;
  for (y = x->PMID; y; ++n, y = (struct zx_prov_PMID_s*)y->gg.g.n) ;
  return n;
}

/* FUNC(zx_pmm_PMActivateItem_GET_PMID) */

struct zx_prov_PMID_s* zx_pmm_PMActivateItem_GET_PMID(struct zx_pmm_PMActivateItem_s* x, int n)
{
  struct zx_prov_PMID_s* y;
  if (!x) return 0;
  for (y = x->PMID; n>=0 && y; --n, y = (struct zx_prov_PMID_s*)y->gg.g.n) ;
  return y;
}

/* FUNC(zx_pmm_PMActivateItem_POP_PMID) */

struct zx_prov_PMID_s* zx_pmm_PMActivateItem_POP_PMID(struct zx_pmm_PMActivateItem_s* x)
{
  struct zx_prov_PMID_s* y;
  if (!x) return 0;
  y = x->PMID;
  if (y)
    x->PMID = (struct zx_prov_PMID_s*)y->gg.g.n;
  return y;
}

/* FUNC(zx_pmm_PMActivateItem_PUSH_PMID) */

void zx_pmm_PMActivateItem_PUSH_PMID(struct zx_pmm_PMActivateItem_s* x, struct zx_prov_PMID_s* z)
{
  if (!x || !z) return;
  z->gg.g.n = &x->PMID->gg.g;
  x->PMID = z;
}

/* FUNC(zx_pmm_PMActivateItem_REV_PMID) */

void zx_pmm_PMActivateItem_REV_PMID(struct zx_pmm_PMActivateItem_s* x)
{
  struct zx_prov_PMID_s* nxt;
  struct zx_prov_PMID_s* y;
  if (!x) return;
  y = x->PMID;
  if (!y) return;
  x->PMID = 0;
  while (y) {
    nxt = (struct zx_prov_PMID_s*)y->gg.g.n;
    y->gg.g.n = &x->PMID->gg.g;
    x->PMID = y;
    y = nxt;
  }
}

/* FUNC(zx_pmm_PMActivateItem_PUT_PMID) */

void zx_pmm_PMActivateItem_PUT_PMID(struct zx_pmm_PMActivateItem_s* x, int n, struct zx_prov_PMID_s* z)
{
  struct zx_prov_PMID_s* y;
  if (!x || !z) return;
  y = x->PMID;
  if (!y) return;
  switch (n) {
  case 0:
    z->gg.g.n = y->gg.g.n;
    x->PMID = z;
    return;
  default:
    for (; n > 1 && y->gg.g.n; --n, y = (struct zx_prov_PMID_s*)y->gg.g.n) ;
    if (!y->gg.g.n) return;
    z->gg.g.n = y->gg.g.n->n;
    y->gg.g.n = &z->gg.g;
  }
}

/* FUNC(zx_pmm_PMActivateItem_ADD_PMID) */

void zx_pmm_PMActivateItem_ADD_PMID(struct zx_pmm_PMActivateItem_s* x, int n, struct zx_prov_PMID_s* z)
{
  struct zx_prov_PMID_s* y;
  if (!x || !z) return;
  switch (n) {
  case 0:
  add_to_start:
    z->gg.g.n = &x->PMID->gg.g;
    x->PMID = z;
    return;
  case -1:
    y = x->PMID;
    if (!y) goto add_to_start;
    for (; y->gg.g.n; y = (struct zx_prov_PMID_s*)y->gg.g.n) ;
    break;
  default:
    for (y = x->PMID; n > 1 && y; --n, y = (struct zx_prov_PMID_s*)y->gg.g.n) ;
    if (!y) return;
  }
  z->gg.g.n = y->gg.g.n;
  y->gg.g.n = &z->gg.g;
}

/* FUNC(zx_pmm_PMActivateItem_DEL_PMID) */

void zx_pmm_PMActivateItem_DEL_PMID(struct zx_pmm_PMActivateItem_s* x, int n)
{
  struct zx_prov_PMID_s* y;
  if (!x) return;
  switch (n) {
  case 0:
    x->PMID = (struct zx_prov_PMID_s*)x->PMID->gg.g.n;
    return;
  case -1:
    y = (struct zx_prov_PMID_s*)x->PMID;
    if (!y) return;
    for (; y->gg.g.n; y = (struct zx_prov_PMID_s*)y->gg.g.n) ;
    break;
  default:
    for (y = x->PMID; n > 1 && y->gg.g.n; --n, y = (struct zx_prov_PMID_s*)y->gg.g.n) ;
    if (!y->gg.g.n) return;
  }
  y->gg.g.n = y->gg.g.n->n;
}

#endif

/* FUNC(zx_pmm_PMActivateItem_GET_at) */
struct zx_str* zx_pmm_PMActivateItem_GET_at(struct zx_pmm_PMActivateItem_s* x) { return x->at; }
/* FUNC(zx_pmm_PMActivateItem_PUT_at) */
void zx_pmm_PMActivateItem_PUT_at(struct zx_pmm_PMActivateItem_s* x, struct zx_str* y) { x->at = y; }
/* FUNC(zx_pmm_PMActivateItem_GET_itemID) */
struct zx_str* zx_pmm_PMActivateItem_GET_itemID(struct zx_pmm_PMActivateItem_s* x) { return x->itemID; }
/* FUNC(zx_pmm_PMActivateItem_PUT_itemID) */
void zx_pmm_PMActivateItem_PUT_itemID(struct zx_pmm_PMActivateItem_s* x, struct zx_str* y) { x->itemID = y; }







#ifdef ZX_ENA_GETPUT

/* FUNC(zx_pmm_PMActivateResponse_NUM_Status) */

int zx_pmm_PMActivateResponse_NUM_Status(struct zx_pmm_PMActivateResponse_s* x)
{
  struct zx_lu_Status_s* y;
  int n = 0;
  if (!x) return 0;
  for (y = x->Status; y; ++n, y = (struct zx_lu_Status_s*)y->gg.g.n) ;
  return n;
}

/* FUNC(zx_pmm_PMActivateResponse_GET_Status) */

struct zx_lu_Status_s* zx_pmm_PMActivateResponse_GET_Status(struct zx_pmm_PMActivateResponse_s* x, int n)
{
  struct zx_lu_Status_s* y;
  if (!x) return 0;
  for (y = x->Status; n>=0 && y; --n, y = (struct zx_lu_Status_s*)y->gg.g.n) ;
  return y;
}

/* FUNC(zx_pmm_PMActivateResponse_POP_Status) */

struct zx_lu_Status_s* zx_pmm_PMActivateResponse_POP_Status(struct zx_pmm_PMActivateResponse_s* x)
{
  struct zx_lu_Status_s* y;
  if (!x) return 0;
  y = x->Status;
  if (y)
    x->Status = (struct zx_lu_Status_s*)y->gg.g.n;
  return y;
}

/* FUNC(zx_pmm_PMActivateResponse_PUSH_Status) */

void zx_pmm_PMActivateResponse_PUSH_Status(struct zx_pmm_PMActivateResponse_s* x, struct zx_lu_Status_s* z)
{
  if (!x || !z) return;
  z->gg.g.n = &x->Status->gg.g;
  x->Status = z;
}

/* FUNC(zx_pmm_PMActivateResponse_REV_Status) */

void zx_pmm_PMActivateResponse_REV_Status(struct zx_pmm_PMActivateResponse_s* x)
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

/* FUNC(zx_pmm_PMActivateResponse_PUT_Status) */

void zx_pmm_PMActivateResponse_PUT_Status(struct zx_pmm_PMActivateResponse_s* x, int n, struct zx_lu_Status_s* z)
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

/* FUNC(zx_pmm_PMActivateResponse_ADD_Status) */

void zx_pmm_PMActivateResponse_ADD_Status(struct zx_pmm_PMActivateResponse_s* x, int n, struct zx_lu_Status_s* z)
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

/* FUNC(zx_pmm_PMActivateResponse_DEL_Status) */

void zx_pmm_PMActivateResponse_DEL_Status(struct zx_pmm_PMActivateResponse_s* x, int n)
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

/* FUNC(zx_pmm_PMDeactivate_NUM_PMDeactivateItem) */

int zx_pmm_PMDeactivate_NUM_PMDeactivateItem(struct zx_pmm_PMDeactivate_s* x)
{
  struct zx_pmm_PMDeactivateItem_s* y;
  int n = 0;
  if (!x) return 0;
  for (y = x->PMDeactivateItem; y; ++n, y = (struct zx_pmm_PMDeactivateItem_s*)y->gg.g.n) ;
  return n;
}

/* FUNC(zx_pmm_PMDeactivate_GET_PMDeactivateItem) */

struct zx_pmm_PMDeactivateItem_s* zx_pmm_PMDeactivate_GET_PMDeactivateItem(struct zx_pmm_PMDeactivate_s* x, int n)
{
  struct zx_pmm_PMDeactivateItem_s* y;
  if (!x) return 0;
  for (y = x->PMDeactivateItem; n>=0 && y; --n, y = (struct zx_pmm_PMDeactivateItem_s*)y->gg.g.n) ;
  return y;
}

/* FUNC(zx_pmm_PMDeactivate_POP_PMDeactivateItem) */

struct zx_pmm_PMDeactivateItem_s* zx_pmm_PMDeactivate_POP_PMDeactivateItem(struct zx_pmm_PMDeactivate_s* x)
{
  struct zx_pmm_PMDeactivateItem_s* y;
  if (!x) return 0;
  y = x->PMDeactivateItem;
  if (y)
    x->PMDeactivateItem = (struct zx_pmm_PMDeactivateItem_s*)y->gg.g.n;
  return y;
}

/* FUNC(zx_pmm_PMDeactivate_PUSH_PMDeactivateItem) */

void zx_pmm_PMDeactivate_PUSH_PMDeactivateItem(struct zx_pmm_PMDeactivate_s* x, struct zx_pmm_PMDeactivateItem_s* z)
{
  if (!x || !z) return;
  z->gg.g.n = &x->PMDeactivateItem->gg.g;
  x->PMDeactivateItem = z;
}

/* FUNC(zx_pmm_PMDeactivate_REV_PMDeactivateItem) */

void zx_pmm_PMDeactivate_REV_PMDeactivateItem(struct zx_pmm_PMDeactivate_s* x)
{
  struct zx_pmm_PMDeactivateItem_s* nxt;
  struct zx_pmm_PMDeactivateItem_s* y;
  if (!x) return;
  y = x->PMDeactivateItem;
  if (!y) return;
  x->PMDeactivateItem = 0;
  while (y) {
    nxt = (struct zx_pmm_PMDeactivateItem_s*)y->gg.g.n;
    y->gg.g.n = &x->PMDeactivateItem->gg.g;
    x->PMDeactivateItem = y;
    y = nxt;
  }
}

/* FUNC(zx_pmm_PMDeactivate_PUT_PMDeactivateItem) */

void zx_pmm_PMDeactivate_PUT_PMDeactivateItem(struct zx_pmm_PMDeactivate_s* x, int n, struct zx_pmm_PMDeactivateItem_s* z)
{
  struct zx_pmm_PMDeactivateItem_s* y;
  if (!x || !z) return;
  y = x->PMDeactivateItem;
  if (!y) return;
  switch (n) {
  case 0:
    z->gg.g.n = y->gg.g.n;
    x->PMDeactivateItem = z;
    return;
  default:
    for (; n > 1 && y->gg.g.n; --n, y = (struct zx_pmm_PMDeactivateItem_s*)y->gg.g.n) ;
    if (!y->gg.g.n) return;
    z->gg.g.n = y->gg.g.n->n;
    y->gg.g.n = &z->gg.g;
  }
}

/* FUNC(zx_pmm_PMDeactivate_ADD_PMDeactivateItem) */

void zx_pmm_PMDeactivate_ADD_PMDeactivateItem(struct zx_pmm_PMDeactivate_s* x, int n, struct zx_pmm_PMDeactivateItem_s* z)
{
  struct zx_pmm_PMDeactivateItem_s* y;
  if (!x || !z) return;
  switch (n) {
  case 0:
  add_to_start:
    z->gg.g.n = &x->PMDeactivateItem->gg.g;
    x->PMDeactivateItem = z;
    return;
  case -1:
    y = x->PMDeactivateItem;
    if (!y) goto add_to_start;
    for (; y->gg.g.n; y = (struct zx_pmm_PMDeactivateItem_s*)y->gg.g.n) ;
    break;
  default:
    for (y = x->PMDeactivateItem; n > 1 && y; --n, y = (struct zx_pmm_PMDeactivateItem_s*)y->gg.g.n) ;
    if (!y) return;
  }
  z->gg.g.n = y->gg.g.n;
  y->gg.g.n = &z->gg.g;
}

/* FUNC(zx_pmm_PMDeactivate_DEL_PMDeactivateItem) */

void zx_pmm_PMDeactivate_DEL_PMDeactivateItem(struct zx_pmm_PMDeactivate_s* x, int n)
{
  struct zx_pmm_PMDeactivateItem_s* y;
  if (!x) return;
  switch (n) {
  case 0:
    x->PMDeactivateItem = (struct zx_pmm_PMDeactivateItem_s*)x->PMDeactivateItem->gg.g.n;
    return;
  case -1:
    y = (struct zx_pmm_PMDeactivateItem_s*)x->PMDeactivateItem;
    if (!y) return;
    for (; y->gg.g.n; y = (struct zx_pmm_PMDeactivateItem_s*)y->gg.g.n) ;
    break;
  default:
    for (y = x->PMDeactivateItem; n > 1 && y->gg.g.n; --n, y = (struct zx_pmm_PMDeactivateItem_s*)y->gg.g.n) ;
    if (!y->gg.g.n) return;
  }
  y->gg.g.n = y->gg.g.n->n;
}

#endif



#ifdef ZX_ENA_GETPUT

/* FUNC(zx_pmm_PMDeactivate_NUM_NotifyTo) */

int zx_pmm_PMDeactivate_NUM_NotifyTo(struct zx_pmm_PMDeactivate_s* x)
{
  struct zx_elem_s* y;
  int n = 0;
  if (!x) return 0;
  for (y = x->NotifyTo; y; ++n, y = (struct zx_elem_s*)y->g.n) ;
  return n;
}

/* FUNC(zx_pmm_PMDeactivate_GET_NotifyTo) */

struct zx_elem_s* zx_pmm_PMDeactivate_GET_NotifyTo(struct zx_pmm_PMDeactivate_s* x, int n)
{
  struct zx_elem_s* y;
  if (!x) return 0;
  for (y = x->NotifyTo; n>=0 && y; --n, y = (struct zx_elem_s*)y->g.n) ;
  return y;
}

/* FUNC(zx_pmm_PMDeactivate_POP_NotifyTo) */

struct zx_elem_s* zx_pmm_PMDeactivate_POP_NotifyTo(struct zx_pmm_PMDeactivate_s* x)
{
  struct zx_elem_s* y;
  if (!x) return 0;
  y = x->NotifyTo;
  if (y)
    x->NotifyTo = (struct zx_elem_s*)y->g.n;
  return y;
}

/* FUNC(zx_pmm_PMDeactivate_PUSH_NotifyTo) */

void zx_pmm_PMDeactivate_PUSH_NotifyTo(struct zx_pmm_PMDeactivate_s* x, struct zx_elem_s* z)
{
  if (!x || !z) return;
  z->g.n = &x->NotifyTo->g;
  x->NotifyTo = z;
}

/* FUNC(zx_pmm_PMDeactivate_REV_NotifyTo) */

void zx_pmm_PMDeactivate_REV_NotifyTo(struct zx_pmm_PMDeactivate_s* x)
{
  struct zx_elem_s* nxt;
  struct zx_elem_s* y;
  if (!x) return;
  y = x->NotifyTo;
  if (!y) return;
  x->NotifyTo = 0;
  while (y) {
    nxt = (struct zx_elem_s*)y->g.n;
    y->g.n = &x->NotifyTo->g;
    x->NotifyTo = y;
    y = nxt;
  }
}

/* FUNC(zx_pmm_PMDeactivate_PUT_NotifyTo) */

void zx_pmm_PMDeactivate_PUT_NotifyTo(struct zx_pmm_PMDeactivate_s* x, int n, struct zx_elem_s* z)
{
  struct zx_elem_s* y;
  if (!x || !z) return;
  y = x->NotifyTo;
  if (!y) return;
  switch (n) {
  case 0:
    z->g.n = y->g.n;
    x->NotifyTo = z;
    return;
  default:
    for (; n > 1 && y->g.n; --n, y = (struct zx_elem_s*)y->g.n) ;
    if (!y->g.n) return;
    z->g.n = y->g.n->n;
    y->g.n = &z->g;
  }
}

/* FUNC(zx_pmm_PMDeactivate_ADD_NotifyTo) */

void zx_pmm_PMDeactivate_ADD_NotifyTo(struct zx_pmm_PMDeactivate_s* x, int n, struct zx_elem_s* z)
{
  struct zx_elem_s* y;
  if (!x || !z) return;
  switch (n) {
  case 0:
  add_to_start:
    z->g.n = &x->NotifyTo->g;
    x->NotifyTo = z;
    return;
  case -1:
    y = x->NotifyTo;
    if (!y) goto add_to_start;
    for (; y->g.n; y = (struct zx_elem_s*)y->g.n) ;
    break;
  default:
    for (y = x->NotifyTo; n > 1 && y; --n, y = (struct zx_elem_s*)y->g.n) ;
    if (!y) return;
  }
  z->g.n = y->g.n;
  y->g.n = &z->g;
}

/* FUNC(zx_pmm_PMDeactivate_DEL_NotifyTo) */

void zx_pmm_PMDeactivate_DEL_NotifyTo(struct zx_pmm_PMDeactivate_s* x, int n)
{
  struct zx_elem_s* y;
  if (!x) return;
  switch (n) {
  case 0:
    x->NotifyTo = (struct zx_elem_s*)x->NotifyTo->g.n;
    return;
  case -1:
    y = (struct zx_elem_s*)x->NotifyTo;
    if (!y) return;
    for (; y->g.n; y = (struct zx_elem_s*)y->g.n) ;
    break;
  default:
    for (y = x->NotifyTo; n > 1 && y->g.n; --n, y = (struct zx_elem_s*)y->g.n) ;
    if (!y->g.n) return;
  }
  y->g.n = y->g.n->n;
}

#endif








#ifdef ZX_ENA_GETPUT

/* FUNC(zx_pmm_PMDeactivateItem_NUM_PMID) */

int zx_pmm_PMDeactivateItem_NUM_PMID(struct zx_pmm_PMDeactivateItem_s* x)
{
  struct zx_prov_PMID_s* y;
  int n = 0;
  if (!x) return 0;
  for (y = x->PMID; y; ++n, y = (struct zx_prov_PMID_s*)y->gg.g.n) ;
  return n;
}

/* FUNC(zx_pmm_PMDeactivateItem_GET_PMID) */

struct zx_prov_PMID_s* zx_pmm_PMDeactivateItem_GET_PMID(struct zx_pmm_PMDeactivateItem_s* x, int n)
{
  struct zx_prov_PMID_s* y;
  if (!x) return 0;
  for (y = x->PMID; n>=0 && y; --n, y = (struct zx_prov_PMID_s*)y->gg.g.n) ;
  return y;
}

/* FUNC(zx_pmm_PMDeactivateItem_POP_PMID) */

struct zx_prov_PMID_s* zx_pmm_PMDeactivateItem_POP_PMID(struct zx_pmm_PMDeactivateItem_s* x)
{
  struct zx_prov_PMID_s* y;
  if (!x) return 0;
  y = x->PMID;
  if (y)
    x->PMID = (struct zx_prov_PMID_s*)y->gg.g.n;
  return y;
}

/* FUNC(zx_pmm_PMDeactivateItem_PUSH_PMID) */

void zx_pmm_PMDeactivateItem_PUSH_PMID(struct zx_pmm_PMDeactivateItem_s* x, struct zx_prov_PMID_s* z)
{
  if (!x || !z) return;
  z->gg.g.n = &x->PMID->gg.g;
  x->PMID = z;
}

/* FUNC(zx_pmm_PMDeactivateItem_REV_PMID) */

void zx_pmm_PMDeactivateItem_REV_PMID(struct zx_pmm_PMDeactivateItem_s* x)
{
  struct zx_prov_PMID_s* nxt;
  struct zx_prov_PMID_s* y;
  if (!x) return;
  y = x->PMID;
  if (!y) return;
  x->PMID = 0;
  while (y) {
    nxt = (struct zx_prov_PMID_s*)y->gg.g.n;
    y->gg.g.n = &x->PMID->gg.g;
    x->PMID = y;
    y = nxt;
  }
}

/* FUNC(zx_pmm_PMDeactivateItem_PUT_PMID) */

void zx_pmm_PMDeactivateItem_PUT_PMID(struct zx_pmm_PMDeactivateItem_s* x, int n, struct zx_prov_PMID_s* z)
{
  struct zx_prov_PMID_s* y;
  if (!x || !z) return;
  y = x->PMID;
  if (!y) return;
  switch (n) {
  case 0:
    z->gg.g.n = y->gg.g.n;
    x->PMID = z;
    return;
  default:
    for (; n > 1 && y->gg.g.n; --n, y = (struct zx_prov_PMID_s*)y->gg.g.n) ;
    if (!y->gg.g.n) return;
    z->gg.g.n = y->gg.g.n->n;
    y->gg.g.n = &z->gg.g;
  }
}

/* FUNC(zx_pmm_PMDeactivateItem_ADD_PMID) */

void zx_pmm_PMDeactivateItem_ADD_PMID(struct zx_pmm_PMDeactivateItem_s* x, int n, struct zx_prov_PMID_s* z)
{
  struct zx_prov_PMID_s* y;
  if (!x || !z) return;
  switch (n) {
  case 0:
  add_to_start:
    z->gg.g.n = &x->PMID->gg.g;
    x->PMID = z;
    return;
  case -1:
    y = x->PMID;
    if (!y) goto add_to_start;
    for (; y->gg.g.n; y = (struct zx_prov_PMID_s*)y->gg.g.n) ;
    break;
  default:
    for (y = x->PMID; n > 1 && y; --n, y = (struct zx_prov_PMID_s*)y->gg.g.n) ;
    if (!y) return;
  }
  z->gg.g.n = y->gg.g.n;
  y->gg.g.n = &z->gg.g;
}

/* FUNC(zx_pmm_PMDeactivateItem_DEL_PMID) */

void zx_pmm_PMDeactivateItem_DEL_PMID(struct zx_pmm_PMDeactivateItem_s* x, int n)
{
  struct zx_prov_PMID_s* y;
  if (!x) return;
  switch (n) {
  case 0:
    x->PMID = (struct zx_prov_PMID_s*)x->PMID->gg.g.n;
    return;
  case -1:
    y = (struct zx_prov_PMID_s*)x->PMID;
    if (!y) return;
    for (; y->gg.g.n; y = (struct zx_prov_PMID_s*)y->gg.g.n) ;
    break;
  default:
    for (y = x->PMID; n > 1 && y->gg.g.n; --n, y = (struct zx_prov_PMID_s*)y->gg.g.n) ;
    if (!y->gg.g.n) return;
  }
  y->gg.g.n = y->gg.g.n->n;
}

#endif

/* FUNC(zx_pmm_PMDeactivateItem_GET_at) */
struct zx_str* zx_pmm_PMDeactivateItem_GET_at(struct zx_pmm_PMDeactivateItem_s* x) { return x->at; }
/* FUNC(zx_pmm_PMDeactivateItem_PUT_at) */
void zx_pmm_PMDeactivateItem_PUT_at(struct zx_pmm_PMDeactivateItem_s* x, struct zx_str* y) { x->at = y; }
/* FUNC(zx_pmm_PMDeactivateItem_GET_itemID) */
struct zx_str* zx_pmm_PMDeactivateItem_GET_itemID(struct zx_pmm_PMDeactivateItem_s* x) { return x->itemID; }
/* FUNC(zx_pmm_PMDeactivateItem_PUT_itemID) */
void zx_pmm_PMDeactivateItem_PUT_itemID(struct zx_pmm_PMDeactivateItem_s* x, struct zx_str* y) { x->itemID = y; }







#ifdef ZX_ENA_GETPUT

/* FUNC(zx_pmm_PMDeactivateResponse_NUM_Status) */

int zx_pmm_PMDeactivateResponse_NUM_Status(struct zx_pmm_PMDeactivateResponse_s* x)
{
  struct zx_lu_Status_s* y;
  int n = 0;
  if (!x) return 0;
  for (y = x->Status; y; ++n, y = (struct zx_lu_Status_s*)y->gg.g.n) ;
  return n;
}

/* FUNC(zx_pmm_PMDeactivateResponse_GET_Status) */

struct zx_lu_Status_s* zx_pmm_PMDeactivateResponse_GET_Status(struct zx_pmm_PMDeactivateResponse_s* x, int n)
{
  struct zx_lu_Status_s* y;
  if (!x) return 0;
  for (y = x->Status; n>=0 && y; --n, y = (struct zx_lu_Status_s*)y->gg.g.n) ;
  return y;
}

/* FUNC(zx_pmm_PMDeactivateResponse_POP_Status) */

struct zx_lu_Status_s* zx_pmm_PMDeactivateResponse_POP_Status(struct zx_pmm_PMDeactivateResponse_s* x)
{
  struct zx_lu_Status_s* y;
  if (!x) return 0;
  y = x->Status;
  if (y)
    x->Status = (struct zx_lu_Status_s*)y->gg.g.n;
  return y;
}

/* FUNC(zx_pmm_PMDeactivateResponse_PUSH_Status) */

void zx_pmm_PMDeactivateResponse_PUSH_Status(struct zx_pmm_PMDeactivateResponse_s* x, struct zx_lu_Status_s* z)
{
  if (!x || !z) return;
  z->gg.g.n = &x->Status->gg.g;
  x->Status = z;
}

/* FUNC(zx_pmm_PMDeactivateResponse_REV_Status) */

void zx_pmm_PMDeactivateResponse_REV_Status(struct zx_pmm_PMDeactivateResponse_s* x)
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

/* FUNC(zx_pmm_PMDeactivateResponse_PUT_Status) */

void zx_pmm_PMDeactivateResponse_PUT_Status(struct zx_pmm_PMDeactivateResponse_s* x, int n, struct zx_lu_Status_s* z)
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

/* FUNC(zx_pmm_PMDeactivateResponse_ADD_Status) */

void zx_pmm_PMDeactivateResponse_ADD_Status(struct zx_pmm_PMDeactivateResponse_s* x, int n, struct zx_lu_Status_s* z)
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

/* FUNC(zx_pmm_PMDeactivateResponse_DEL_Status) */

void zx_pmm_PMDeactivateResponse_DEL_Status(struct zx_pmm_PMDeactivateResponse_s* x, int n)
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

/* FUNC(zx_pmm_PMDelete_NUM_PMDeleteItem) */

int zx_pmm_PMDelete_NUM_PMDeleteItem(struct zx_pmm_PMDelete_s* x)
{
  struct zx_pmm_PMDeleteItem_s* y;
  int n = 0;
  if (!x) return 0;
  for (y = x->PMDeleteItem; y; ++n, y = (struct zx_pmm_PMDeleteItem_s*)y->gg.g.n) ;
  return n;
}

/* FUNC(zx_pmm_PMDelete_GET_PMDeleteItem) */

struct zx_pmm_PMDeleteItem_s* zx_pmm_PMDelete_GET_PMDeleteItem(struct zx_pmm_PMDelete_s* x, int n)
{
  struct zx_pmm_PMDeleteItem_s* y;
  if (!x) return 0;
  for (y = x->PMDeleteItem; n>=0 && y; --n, y = (struct zx_pmm_PMDeleteItem_s*)y->gg.g.n) ;
  return y;
}

/* FUNC(zx_pmm_PMDelete_POP_PMDeleteItem) */

struct zx_pmm_PMDeleteItem_s* zx_pmm_PMDelete_POP_PMDeleteItem(struct zx_pmm_PMDelete_s* x)
{
  struct zx_pmm_PMDeleteItem_s* y;
  if (!x) return 0;
  y = x->PMDeleteItem;
  if (y)
    x->PMDeleteItem = (struct zx_pmm_PMDeleteItem_s*)y->gg.g.n;
  return y;
}

/* FUNC(zx_pmm_PMDelete_PUSH_PMDeleteItem) */

void zx_pmm_PMDelete_PUSH_PMDeleteItem(struct zx_pmm_PMDelete_s* x, struct zx_pmm_PMDeleteItem_s* z)
{
  if (!x || !z) return;
  z->gg.g.n = &x->PMDeleteItem->gg.g;
  x->PMDeleteItem = z;
}

/* FUNC(zx_pmm_PMDelete_REV_PMDeleteItem) */

void zx_pmm_PMDelete_REV_PMDeleteItem(struct zx_pmm_PMDelete_s* x)
{
  struct zx_pmm_PMDeleteItem_s* nxt;
  struct zx_pmm_PMDeleteItem_s* y;
  if (!x) return;
  y = x->PMDeleteItem;
  if (!y) return;
  x->PMDeleteItem = 0;
  while (y) {
    nxt = (struct zx_pmm_PMDeleteItem_s*)y->gg.g.n;
    y->gg.g.n = &x->PMDeleteItem->gg.g;
    x->PMDeleteItem = y;
    y = nxt;
  }
}

/* FUNC(zx_pmm_PMDelete_PUT_PMDeleteItem) */

void zx_pmm_PMDelete_PUT_PMDeleteItem(struct zx_pmm_PMDelete_s* x, int n, struct zx_pmm_PMDeleteItem_s* z)
{
  struct zx_pmm_PMDeleteItem_s* y;
  if (!x || !z) return;
  y = x->PMDeleteItem;
  if (!y) return;
  switch (n) {
  case 0:
    z->gg.g.n = y->gg.g.n;
    x->PMDeleteItem = z;
    return;
  default:
    for (; n > 1 && y->gg.g.n; --n, y = (struct zx_pmm_PMDeleteItem_s*)y->gg.g.n) ;
    if (!y->gg.g.n) return;
    z->gg.g.n = y->gg.g.n->n;
    y->gg.g.n = &z->gg.g;
  }
}

/* FUNC(zx_pmm_PMDelete_ADD_PMDeleteItem) */

void zx_pmm_PMDelete_ADD_PMDeleteItem(struct zx_pmm_PMDelete_s* x, int n, struct zx_pmm_PMDeleteItem_s* z)
{
  struct zx_pmm_PMDeleteItem_s* y;
  if (!x || !z) return;
  switch (n) {
  case 0:
  add_to_start:
    z->gg.g.n = &x->PMDeleteItem->gg.g;
    x->PMDeleteItem = z;
    return;
  case -1:
    y = x->PMDeleteItem;
    if (!y) goto add_to_start;
    for (; y->gg.g.n; y = (struct zx_pmm_PMDeleteItem_s*)y->gg.g.n) ;
    break;
  default:
    for (y = x->PMDeleteItem; n > 1 && y; --n, y = (struct zx_pmm_PMDeleteItem_s*)y->gg.g.n) ;
    if (!y) return;
  }
  z->gg.g.n = y->gg.g.n;
  y->gg.g.n = &z->gg.g;
}

/* FUNC(zx_pmm_PMDelete_DEL_PMDeleteItem) */

void zx_pmm_PMDelete_DEL_PMDeleteItem(struct zx_pmm_PMDelete_s* x, int n)
{
  struct zx_pmm_PMDeleteItem_s* y;
  if (!x) return;
  switch (n) {
  case 0:
    x->PMDeleteItem = (struct zx_pmm_PMDeleteItem_s*)x->PMDeleteItem->gg.g.n;
    return;
  case -1:
    y = (struct zx_pmm_PMDeleteItem_s*)x->PMDeleteItem;
    if (!y) return;
    for (; y->gg.g.n; y = (struct zx_pmm_PMDeleteItem_s*)y->gg.g.n) ;
    break;
  default:
    for (y = x->PMDeleteItem; n > 1 && y->gg.g.n; --n, y = (struct zx_pmm_PMDeleteItem_s*)y->gg.g.n) ;
    if (!y->gg.g.n) return;
  }
  y->gg.g.n = y->gg.g.n->n;
}

#endif








#ifdef ZX_ENA_GETPUT

/* FUNC(zx_pmm_PMDeleteItem_NUM_PMID) */

int zx_pmm_PMDeleteItem_NUM_PMID(struct zx_pmm_PMDeleteItem_s* x)
{
  struct zx_prov_PMID_s* y;
  int n = 0;
  if (!x) return 0;
  for (y = x->PMID; y; ++n, y = (struct zx_prov_PMID_s*)y->gg.g.n) ;
  return n;
}

/* FUNC(zx_pmm_PMDeleteItem_GET_PMID) */

struct zx_prov_PMID_s* zx_pmm_PMDeleteItem_GET_PMID(struct zx_pmm_PMDeleteItem_s* x, int n)
{
  struct zx_prov_PMID_s* y;
  if (!x) return 0;
  for (y = x->PMID; n>=0 && y; --n, y = (struct zx_prov_PMID_s*)y->gg.g.n) ;
  return y;
}

/* FUNC(zx_pmm_PMDeleteItem_POP_PMID) */

struct zx_prov_PMID_s* zx_pmm_PMDeleteItem_POP_PMID(struct zx_pmm_PMDeleteItem_s* x)
{
  struct zx_prov_PMID_s* y;
  if (!x) return 0;
  y = x->PMID;
  if (y)
    x->PMID = (struct zx_prov_PMID_s*)y->gg.g.n;
  return y;
}

/* FUNC(zx_pmm_PMDeleteItem_PUSH_PMID) */

void zx_pmm_PMDeleteItem_PUSH_PMID(struct zx_pmm_PMDeleteItem_s* x, struct zx_prov_PMID_s* z)
{
  if (!x || !z) return;
  z->gg.g.n = &x->PMID->gg.g;
  x->PMID = z;
}

/* FUNC(zx_pmm_PMDeleteItem_REV_PMID) */

void zx_pmm_PMDeleteItem_REV_PMID(struct zx_pmm_PMDeleteItem_s* x)
{
  struct zx_prov_PMID_s* nxt;
  struct zx_prov_PMID_s* y;
  if (!x) return;
  y = x->PMID;
  if (!y) return;
  x->PMID = 0;
  while (y) {
    nxt = (struct zx_prov_PMID_s*)y->gg.g.n;
    y->gg.g.n = &x->PMID->gg.g;
    x->PMID = y;
    y = nxt;
  }
}

/* FUNC(zx_pmm_PMDeleteItem_PUT_PMID) */

void zx_pmm_PMDeleteItem_PUT_PMID(struct zx_pmm_PMDeleteItem_s* x, int n, struct zx_prov_PMID_s* z)
{
  struct zx_prov_PMID_s* y;
  if (!x || !z) return;
  y = x->PMID;
  if (!y) return;
  switch (n) {
  case 0:
    z->gg.g.n = y->gg.g.n;
    x->PMID = z;
    return;
  default:
    for (; n > 1 && y->gg.g.n; --n, y = (struct zx_prov_PMID_s*)y->gg.g.n) ;
    if (!y->gg.g.n) return;
    z->gg.g.n = y->gg.g.n->n;
    y->gg.g.n = &z->gg.g;
  }
}

/* FUNC(zx_pmm_PMDeleteItem_ADD_PMID) */

void zx_pmm_PMDeleteItem_ADD_PMID(struct zx_pmm_PMDeleteItem_s* x, int n, struct zx_prov_PMID_s* z)
{
  struct zx_prov_PMID_s* y;
  if (!x || !z) return;
  switch (n) {
  case 0:
  add_to_start:
    z->gg.g.n = &x->PMID->gg.g;
    x->PMID = z;
    return;
  case -1:
    y = x->PMID;
    if (!y) goto add_to_start;
    for (; y->gg.g.n; y = (struct zx_prov_PMID_s*)y->gg.g.n) ;
    break;
  default:
    for (y = x->PMID; n > 1 && y; --n, y = (struct zx_prov_PMID_s*)y->gg.g.n) ;
    if (!y) return;
  }
  z->gg.g.n = y->gg.g.n;
  y->gg.g.n = &z->gg.g;
}

/* FUNC(zx_pmm_PMDeleteItem_DEL_PMID) */

void zx_pmm_PMDeleteItem_DEL_PMID(struct zx_pmm_PMDeleteItem_s* x, int n)
{
  struct zx_prov_PMID_s* y;
  if (!x) return;
  switch (n) {
  case 0:
    x->PMID = (struct zx_prov_PMID_s*)x->PMID->gg.g.n;
    return;
  case -1:
    y = (struct zx_prov_PMID_s*)x->PMID;
    if (!y) return;
    for (; y->gg.g.n; y = (struct zx_prov_PMID_s*)y->gg.g.n) ;
    break;
  default:
    for (y = x->PMID; n > 1 && y->gg.g.n; --n, y = (struct zx_prov_PMID_s*)y->gg.g.n) ;
    if (!y->gg.g.n) return;
  }
  y->gg.g.n = y->gg.g.n->n;
}

#endif

/* FUNC(zx_pmm_PMDeleteItem_GET_itemID) */
struct zx_str* zx_pmm_PMDeleteItem_GET_itemID(struct zx_pmm_PMDeleteItem_s* x) { return x->itemID; }
/* FUNC(zx_pmm_PMDeleteItem_PUT_itemID) */
void zx_pmm_PMDeleteItem_PUT_itemID(struct zx_pmm_PMDeleteItem_s* x, struct zx_str* y) { x->itemID = y; }







#ifdef ZX_ENA_GETPUT

/* FUNC(zx_pmm_PMDeleteResponse_NUM_Status) */

int zx_pmm_PMDeleteResponse_NUM_Status(struct zx_pmm_PMDeleteResponse_s* x)
{
  struct zx_lu_Status_s* y;
  int n = 0;
  if (!x) return 0;
  for (y = x->Status; y; ++n, y = (struct zx_lu_Status_s*)y->gg.g.n) ;
  return n;
}

/* FUNC(zx_pmm_PMDeleteResponse_GET_Status) */

struct zx_lu_Status_s* zx_pmm_PMDeleteResponse_GET_Status(struct zx_pmm_PMDeleteResponse_s* x, int n)
{
  struct zx_lu_Status_s* y;
  if (!x) return 0;
  for (y = x->Status; n>=0 && y; --n, y = (struct zx_lu_Status_s*)y->gg.g.n) ;
  return y;
}

/* FUNC(zx_pmm_PMDeleteResponse_POP_Status) */

struct zx_lu_Status_s* zx_pmm_PMDeleteResponse_POP_Status(struct zx_pmm_PMDeleteResponse_s* x)
{
  struct zx_lu_Status_s* y;
  if (!x) return 0;
  y = x->Status;
  if (y)
    x->Status = (struct zx_lu_Status_s*)y->gg.g.n;
  return y;
}

/* FUNC(zx_pmm_PMDeleteResponse_PUSH_Status) */

void zx_pmm_PMDeleteResponse_PUSH_Status(struct zx_pmm_PMDeleteResponse_s* x, struct zx_lu_Status_s* z)
{
  if (!x || !z) return;
  z->gg.g.n = &x->Status->gg.g;
  x->Status = z;
}

/* FUNC(zx_pmm_PMDeleteResponse_REV_Status) */

void zx_pmm_PMDeleteResponse_REV_Status(struct zx_pmm_PMDeleteResponse_s* x)
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

/* FUNC(zx_pmm_PMDeleteResponse_PUT_Status) */

void zx_pmm_PMDeleteResponse_PUT_Status(struct zx_pmm_PMDeleteResponse_s* x, int n, struct zx_lu_Status_s* z)
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

/* FUNC(zx_pmm_PMDeleteResponse_ADD_Status) */

void zx_pmm_PMDeleteResponse_ADD_Status(struct zx_pmm_PMDeleteResponse_s* x, int n, struct zx_lu_Status_s* z)
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

/* FUNC(zx_pmm_PMDeleteResponse_DEL_Status) */

void zx_pmm_PMDeleteResponse_DEL_Status(struct zx_pmm_PMDeleteResponse_s* x, int n)
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

/* FUNC(zx_pmm_PMGetStatus_NUM_PMID) */

int zx_pmm_PMGetStatus_NUM_PMID(struct zx_pmm_PMGetStatus_s* x)
{
  struct zx_prov_PMID_s* y;
  int n = 0;
  if (!x) return 0;
  for (y = x->PMID; y; ++n, y = (struct zx_prov_PMID_s*)y->gg.g.n) ;
  return n;
}

/* FUNC(zx_pmm_PMGetStatus_GET_PMID) */

struct zx_prov_PMID_s* zx_pmm_PMGetStatus_GET_PMID(struct zx_pmm_PMGetStatus_s* x, int n)
{
  struct zx_prov_PMID_s* y;
  if (!x) return 0;
  for (y = x->PMID; n>=0 && y; --n, y = (struct zx_prov_PMID_s*)y->gg.g.n) ;
  return y;
}

/* FUNC(zx_pmm_PMGetStatus_POP_PMID) */

struct zx_prov_PMID_s* zx_pmm_PMGetStatus_POP_PMID(struct zx_pmm_PMGetStatus_s* x)
{
  struct zx_prov_PMID_s* y;
  if (!x) return 0;
  y = x->PMID;
  if (y)
    x->PMID = (struct zx_prov_PMID_s*)y->gg.g.n;
  return y;
}

/* FUNC(zx_pmm_PMGetStatus_PUSH_PMID) */

void zx_pmm_PMGetStatus_PUSH_PMID(struct zx_pmm_PMGetStatus_s* x, struct zx_prov_PMID_s* z)
{
  if (!x || !z) return;
  z->gg.g.n = &x->PMID->gg.g;
  x->PMID = z;
}

/* FUNC(zx_pmm_PMGetStatus_REV_PMID) */

void zx_pmm_PMGetStatus_REV_PMID(struct zx_pmm_PMGetStatus_s* x)
{
  struct zx_prov_PMID_s* nxt;
  struct zx_prov_PMID_s* y;
  if (!x) return;
  y = x->PMID;
  if (!y) return;
  x->PMID = 0;
  while (y) {
    nxt = (struct zx_prov_PMID_s*)y->gg.g.n;
    y->gg.g.n = &x->PMID->gg.g;
    x->PMID = y;
    y = nxt;
  }
}

/* FUNC(zx_pmm_PMGetStatus_PUT_PMID) */

void zx_pmm_PMGetStatus_PUT_PMID(struct zx_pmm_PMGetStatus_s* x, int n, struct zx_prov_PMID_s* z)
{
  struct zx_prov_PMID_s* y;
  if (!x || !z) return;
  y = x->PMID;
  if (!y) return;
  switch (n) {
  case 0:
    z->gg.g.n = y->gg.g.n;
    x->PMID = z;
    return;
  default:
    for (; n > 1 && y->gg.g.n; --n, y = (struct zx_prov_PMID_s*)y->gg.g.n) ;
    if (!y->gg.g.n) return;
    z->gg.g.n = y->gg.g.n->n;
    y->gg.g.n = &z->gg.g;
  }
}

/* FUNC(zx_pmm_PMGetStatus_ADD_PMID) */

void zx_pmm_PMGetStatus_ADD_PMID(struct zx_pmm_PMGetStatus_s* x, int n, struct zx_prov_PMID_s* z)
{
  struct zx_prov_PMID_s* y;
  if (!x || !z) return;
  switch (n) {
  case 0:
  add_to_start:
    z->gg.g.n = &x->PMID->gg.g;
    x->PMID = z;
    return;
  case -1:
    y = x->PMID;
    if (!y) goto add_to_start;
    for (; y->gg.g.n; y = (struct zx_prov_PMID_s*)y->gg.g.n) ;
    break;
  default:
    for (y = x->PMID; n > 1 && y; --n, y = (struct zx_prov_PMID_s*)y->gg.g.n) ;
    if (!y) return;
  }
  z->gg.g.n = y->gg.g.n;
  y->gg.g.n = &z->gg.g;
}

/* FUNC(zx_pmm_PMGetStatus_DEL_PMID) */

void zx_pmm_PMGetStatus_DEL_PMID(struct zx_pmm_PMGetStatus_s* x, int n)
{
  struct zx_prov_PMID_s* y;
  if (!x) return;
  switch (n) {
  case 0:
    x->PMID = (struct zx_prov_PMID_s*)x->PMID->gg.g.n;
    return;
  case -1:
    y = (struct zx_prov_PMID_s*)x->PMID;
    if (!y) return;
    for (; y->gg.g.n; y = (struct zx_prov_PMID_s*)y->gg.g.n) ;
    break;
  default:
    for (y = x->PMID; n > 1 && y->gg.g.n; --n, y = (struct zx_prov_PMID_s*)y->gg.g.n) ;
    if (!y->gg.g.n) return;
  }
  y->gg.g.n = y->gg.g.n->n;
}

#endif








#ifdef ZX_ENA_GETPUT

/* FUNC(zx_pmm_PMGetStatusResponse_NUM_Status) */

int zx_pmm_PMGetStatusResponse_NUM_Status(struct zx_pmm_PMGetStatusResponse_s* x)
{
  struct zx_lu_Status_s* y;
  int n = 0;
  if (!x) return 0;
  for (y = x->Status; y; ++n, y = (struct zx_lu_Status_s*)y->gg.g.n) ;
  return n;
}

/* FUNC(zx_pmm_PMGetStatusResponse_GET_Status) */

struct zx_lu_Status_s* zx_pmm_PMGetStatusResponse_GET_Status(struct zx_pmm_PMGetStatusResponse_s* x, int n)
{
  struct zx_lu_Status_s* y;
  if (!x) return 0;
  for (y = x->Status; n>=0 && y; --n, y = (struct zx_lu_Status_s*)y->gg.g.n) ;
  return y;
}

/* FUNC(zx_pmm_PMGetStatusResponse_POP_Status) */

struct zx_lu_Status_s* zx_pmm_PMGetStatusResponse_POP_Status(struct zx_pmm_PMGetStatusResponse_s* x)
{
  struct zx_lu_Status_s* y;
  if (!x) return 0;
  y = x->Status;
  if (y)
    x->Status = (struct zx_lu_Status_s*)y->gg.g.n;
  return y;
}

/* FUNC(zx_pmm_PMGetStatusResponse_PUSH_Status) */

void zx_pmm_PMGetStatusResponse_PUSH_Status(struct zx_pmm_PMGetStatusResponse_s* x, struct zx_lu_Status_s* z)
{
  if (!x || !z) return;
  z->gg.g.n = &x->Status->gg.g;
  x->Status = z;
}

/* FUNC(zx_pmm_PMGetStatusResponse_REV_Status) */

void zx_pmm_PMGetStatusResponse_REV_Status(struct zx_pmm_PMGetStatusResponse_s* x)
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

/* FUNC(zx_pmm_PMGetStatusResponse_PUT_Status) */

void zx_pmm_PMGetStatusResponse_PUT_Status(struct zx_pmm_PMGetStatusResponse_s* x, int n, struct zx_lu_Status_s* z)
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

/* FUNC(zx_pmm_PMGetStatusResponse_ADD_Status) */

void zx_pmm_PMGetStatusResponse_ADD_Status(struct zx_pmm_PMGetStatusResponse_s* x, int n, struct zx_lu_Status_s* z)
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

/* FUNC(zx_pmm_PMGetStatusResponse_DEL_Status) */

void zx_pmm_PMGetStatusResponse_DEL_Status(struct zx_pmm_PMGetStatusResponse_s* x, int n)
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

/* FUNC(zx_pmm_PMGetStatusResponse_NUM_PMStatus) */

int zx_pmm_PMGetStatusResponse_NUM_PMStatus(struct zx_pmm_PMGetStatusResponse_s* x)
{
  struct zx_prov_PMStatus_s* y;
  int n = 0;
  if (!x) return 0;
  for (y = x->PMStatus; y; ++n, y = (struct zx_prov_PMStatus_s*)y->gg.g.n) ;
  return n;
}

/* FUNC(zx_pmm_PMGetStatusResponse_GET_PMStatus) */

struct zx_prov_PMStatus_s* zx_pmm_PMGetStatusResponse_GET_PMStatus(struct zx_pmm_PMGetStatusResponse_s* x, int n)
{
  struct zx_prov_PMStatus_s* y;
  if (!x) return 0;
  for (y = x->PMStatus; n>=0 && y; --n, y = (struct zx_prov_PMStatus_s*)y->gg.g.n) ;
  return y;
}

/* FUNC(zx_pmm_PMGetStatusResponse_POP_PMStatus) */

struct zx_prov_PMStatus_s* zx_pmm_PMGetStatusResponse_POP_PMStatus(struct zx_pmm_PMGetStatusResponse_s* x)
{
  struct zx_prov_PMStatus_s* y;
  if (!x) return 0;
  y = x->PMStatus;
  if (y)
    x->PMStatus = (struct zx_prov_PMStatus_s*)y->gg.g.n;
  return y;
}

/* FUNC(zx_pmm_PMGetStatusResponse_PUSH_PMStatus) */

void zx_pmm_PMGetStatusResponse_PUSH_PMStatus(struct zx_pmm_PMGetStatusResponse_s* x, struct zx_prov_PMStatus_s* z)
{
  if (!x || !z) return;
  z->gg.g.n = &x->PMStatus->gg.g;
  x->PMStatus = z;
}

/* FUNC(zx_pmm_PMGetStatusResponse_REV_PMStatus) */

void zx_pmm_PMGetStatusResponse_REV_PMStatus(struct zx_pmm_PMGetStatusResponse_s* x)
{
  struct zx_prov_PMStatus_s* nxt;
  struct zx_prov_PMStatus_s* y;
  if (!x) return;
  y = x->PMStatus;
  if (!y) return;
  x->PMStatus = 0;
  while (y) {
    nxt = (struct zx_prov_PMStatus_s*)y->gg.g.n;
    y->gg.g.n = &x->PMStatus->gg.g;
    x->PMStatus = y;
    y = nxt;
  }
}

/* FUNC(zx_pmm_PMGetStatusResponse_PUT_PMStatus) */

void zx_pmm_PMGetStatusResponse_PUT_PMStatus(struct zx_pmm_PMGetStatusResponse_s* x, int n, struct zx_prov_PMStatus_s* z)
{
  struct zx_prov_PMStatus_s* y;
  if (!x || !z) return;
  y = x->PMStatus;
  if (!y) return;
  switch (n) {
  case 0:
    z->gg.g.n = y->gg.g.n;
    x->PMStatus = z;
    return;
  default:
    for (; n > 1 && y->gg.g.n; --n, y = (struct zx_prov_PMStatus_s*)y->gg.g.n) ;
    if (!y->gg.g.n) return;
    z->gg.g.n = y->gg.g.n->n;
    y->gg.g.n = &z->gg.g;
  }
}

/* FUNC(zx_pmm_PMGetStatusResponse_ADD_PMStatus) */

void zx_pmm_PMGetStatusResponse_ADD_PMStatus(struct zx_pmm_PMGetStatusResponse_s* x, int n, struct zx_prov_PMStatus_s* z)
{
  struct zx_prov_PMStatus_s* y;
  if (!x || !z) return;
  switch (n) {
  case 0:
  add_to_start:
    z->gg.g.n = &x->PMStatus->gg.g;
    x->PMStatus = z;
    return;
  case -1:
    y = x->PMStatus;
    if (!y) goto add_to_start;
    for (; y->gg.g.n; y = (struct zx_prov_PMStatus_s*)y->gg.g.n) ;
    break;
  default:
    for (y = x->PMStatus; n > 1 && y; --n, y = (struct zx_prov_PMStatus_s*)y->gg.g.n) ;
    if (!y) return;
  }
  z->gg.g.n = y->gg.g.n;
  y->gg.g.n = &z->gg.g;
}

/* FUNC(zx_pmm_PMGetStatusResponse_DEL_PMStatus) */

void zx_pmm_PMGetStatusResponse_DEL_PMStatus(struct zx_pmm_PMGetStatusResponse_s* x, int n)
{
  struct zx_prov_PMStatus_s* y;
  if (!x) return;
  switch (n) {
  case 0:
    x->PMStatus = (struct zx_prov_PMStatus_s*)x->PMStatus->gg.g.n;
    return;
  case -1:
    y = (struct zx_prov_PMStatus_s*)x->PMStatus;
    if (!y) return;
    for (; y->gg.g.n; y = (struct zx_prov_PMStatus_s*)y->gg.g.n) ;
    break;
  default:
    for (y = x->PMStatus; n > 1 && y->gg.g.n; --n, y = (struct zx_prov_PMStatus_s*)y->gg.g.n) ;
    if (!y->gg.g.n) return;
  }
  y->gg.g.n = y->gg.g.n->n;
}

#endif








#ifdef ZX_ENA_GETPUT

/* FUNC(zx_pmm_PMSetStatus_NUM_PMStatus) */

int zx_pmm_PMSetStatus_NUM_PMStatus(struct zx_pmm_PMSetStatus_s* x)
{
  struct zx_prov_PMStatus_s* y;
  int n = 0;
  if (!x) return 0;
  for (y = x->PMStatus; y; ++n, y = (struct zx_prov_PMStatus_s*)y->gg.g.n) ;
  return n;
}

/* FUNC(zx_pmm_PMSetStatus_GET_PMStatus) */

struct zx_prov_PMStatus_s* zx_pmm_PMSetStatus_GET_PMStatus(struct zx_pmm_PMSetStatus_s* x, int n)
{
  struct zx_prov_PMStatus_s* y;
  if (!x) return 0;
  for (y = x->PMStatus; n>=0 && y; --n, y = (struct zx_prov_PMStatus_s*)y->gg.g.n) ;
  return y;
}

/* FUNC(zx_pmm_PMSetStatus_POP_PMStatus) */

struct zx_prov_PMStatus_s* zx_pmm_PMSetStatus_POP_PMStatus(struct zx_pmm_PMSetStatus_s* x)
{
  struct zx_prov_PMStatus_s* y;
  if (!x) return 0;
  y = x->PMStatus;
  if (y)
    x->PMStatus = (struct zx_prov_PMStatus_s*)y->gg.g.n;
  return y;
}

/* FUNC(zx_pmm_PMSetStatus_PUSH_PMStatus) */

void zx_pmm_PMSetStatus_PUSH_PMStatus(struct zx_pmm_PMSetStatus_s* x, struct zx_prov_PMStatus_s* z)
{
  if (!x || !z) return;
  z->gg.g.n = &x->PMStatus->gg.g;
  x->PMStatus = z;
}

/* FUNC(zx_pmm_PMSetStatus_REV_PMStatus) */

void zx_pmm_PMSetStatus_REV_PMStatus(struct zx_pmm_PMSetStatus_s* x)
{
  struct zx_prov_PMStatus_s* nxt;
  struct zx_prov_PMStatus_s* y;
  if (!x) return;
  y = x->PMStatus;
  if (!y) return;
  x->PMStatus = 0;
  while (y) {
    nxt = (struct zx_prov_PMStatus_s*)y->gg.g.n;
    y->gg.g.n = &x->PMStatus->gg.g;
    x->PMStatus = y;
    y = nxt;
  }
}

/* FUNC(zx_pmm_PMSetStatus_PUT_PMStatus) */

void zx_pmm_PMSetStatus_PUT_PMStatus(struct zx_pmm_PMSetStatus_s* x, int n, struct zx_prov_PMStatus_s* z)
{
  struct zx_prov_PMStatus_s* y;
  if (!x || !z) return;
  y = x->PMStatus;
  if (!y) return;
  switch (n) {
  case 0:
    z->gg.g.n = y->gg.g.n;
    x->PMStatus = z;
    return;
  default:
    for (; n > 1 && y->gg.g.n; --n, y = (struct zx_prov_PMStatus_s*)y->gg.g.n) ;
    if (!y->gg.g.n) return;
    z->gg.g.n = y->gg.g.n->n;
    y->gg.g.n = &z->gg.g;
  }
}

/* FUNC(zx_pmm_PMSetStatus_ADD_PMStatus) */

void zx_pmm_PMSetStatus_ADD_PMStatus(struct zx_pmm_PMSetStatus_s* x, int n, struct zx_prov_PMStatus_s* z)
{
  struct zx_prov_PMStatus_s* y;
  if (!x || !z) return;
  switch (n) {
  case 0:
  add_to_start:
    z->gg.g.n = &x->PMStatus->gg.g;
    x->PMStatus = z;
    return;
  case -1:
    y = x->PMStatus;
    if (!y) goto add_to_start;
    for (; y->gg.g.n; y = (struct zx_prov_PMStatus_s*)y->gg.g.n) ;
    break;
  default:
    for (y = x->PMStatus; n > 1 && y; --n, y = (struct zx_prov_PMStatus_s*)y->gg.g.n) ;
    if (!y) return;
  }
  z->gg.g.n = y->gg.g.n;
  y->gg.g.n = &z->gg.g;
}

/* FUNC(zx_pmm_PMSetStatus_DEL_PMStatus) */

void zx_pmm_PMSetStatus_DEL_PMStatus(struct zx_pmm_PMSetStatus_s* x, int n)
{
  struct zx_prov_PMStatus_s* y;
  if (!x) return;
  switch (n) {
  case 0:
    x->PMStatus = (struct zx_prov_PMStatus_s*)x->PMStatus->gg.g.n;
    return;
  case -1:
    y = (struct zx_prov_PMStatus_s*)x->PMStatus;
    if (!y) return;
    for (; y->gg.g.n; y = (struct zx_prov_PMStatus_s*)y->gg.g.n) ;
    break;
  default:
    for (y = x->PMStatus; n > 1 && y->gg.g.n; --n, y = (struct zx_prov_PMStatus_s*)y->gg.g.n) ;
    if (!y->gg.g.n) return;
  }
  y->gg.g.n = y->gg.g.n->n;
}

#endif








#ifdef ZX_ENA_GETPUT

/* FUNC(zx_pmm_PMSetStatusResponse_NUM_Status) */

int zx_pmm_PMSetStatusResponse_NUM_Status(struct zx_pmm_PMSetStatusResponse_s* x)
{
  struct zx_lu_Status_s* y;
  int n = 0;
  if (!x) return 0;
  for (y = x->Status; y; ++n, y = (struct zx_lu_Status_s*)y->gg.g.n) ;
  return n;
}

/* FUNC(zx_pmm_PMSetStatusResponse_GET_Status) */

struct zx_lu_Status_s* zx_pmm_PMSetStatusResponse_GET_Status(struct zx_pmm_PMSetStatusResponse_s* x, int n)
{
  struct zx_lu_Status_s* y;
  if (!x) return 0;
  for (y = x->Status; n>=0 && y; --n, y = (struct zx_lu_Status_s*)y->gg.g.n) ;
  return y;
}

/* FUNC(zx_pmm_PMSetStatusResponse_POP_Status) */

struct zx_lu_Status_s* zx_pmm_PMSetStatusResponse_POP_Status(struct zx_pmm_PMSetStatusResponse_s* x)
{
  struct zx_lu_Status_s* y;
  if (!x) return 0;
  y = x->Status;
  if (y)
    x->Status = (struct zx_lu_Status_s*)y->gg.g.n;
  return y;
}

/* FUNC(zx_pmm_PMSetStatusResponse_PUSH_Status) */

void zx_pmm_PMSetStatusResponse_PUSH_Status(struct zx_pmm_PMSetStatusResponse_s* x, struct zx_lu_Status_s* z)
{
  if (!x || !z) return;
  z->gg.g.n = &x->Status->gg.g;
  x->Status = z;
}

/* FUNC(zx_pmm_PMSetStatusResponse_REV_Status) */

void zx_pmm_PMSetStatusResponse_REV_Status(struct zx_pmm_PMSetStatusResponse_s* x)
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

/* FUNC(zx_pmm_PMSetStatusResponse_PUT_Status) */

void zx_pmm_PMSetStatusResponse_PUT_Status(struct zx_pmm_PMSetStatusResponse_s* x, int n, struct zx_lu_Status_s* z)
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

/* FUNC(zx_pmm_PMSetStatusResponse_ADD_Status) */

void zx_pmm_PMSetStatusResponse_ADD_Status(struct zx_pmm_PMSetStatusResponse_s* x, int n, struct zx_lu_Status_s* z)
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

/* FUNC(zx_pmm_PMSetStatusResponse_DEL_Status) */

void zx_pmm_PMSetStatusResponse_DEL_Status(struct zx_pmm_PMSetStatusResponse_s* x, int n)
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

/* FUNC(zx_pmm_PMUpdate_NUM_PMUpdateItem) */

int zx_pmm_PMUpdate_NUM_PMUpdateItem(struct zx_pmm_PMUpdate_s* x)
{
  struct zx_pmm_PMUpdateItem_s* y;
  int n = 0;
  if (!x) return 0;
  for (y = x->PMUpdateItem; y; ++n, y = (struct zx_pmm_PMUpdateItem_s*)y->gg.g.n) ;
  return n;
}

/* FUNC(zx_pmm_PMUpdate_GET_PMUpdateItem) */

struct zx_pmm_PMUpdateItem_s* zx_pmm_PMUpdate_GET_PMUpdateItem(struct zx_pmm_PMUpdate_s* x, int n)
{
  struct zx_pmm_PMUpdateItem_s* y;
  if (!x) return 0;
  for (y = x->PMUpdateItem; n>=0 && y; --n, y = (struct zx_pmm_PMUpdateItem_s*)y->gg.g.n) ;
  return y;
}

/* FUNC(zx_pmm_PMUpdate_POP_PMUpdateItem) */

struct zx_pmm_PMUpdateItem_s* zx_pmm_PMUpdate_POP_PMUpdateItem(struct zx_pmm_PMUpdate_s* x)
{
  struct zx_pmm_PMUpdateItem_s* y;
  if (!x) return 0;
  y = x->PMUpdateItem;
  if (y)
    x->PMUpdateItem = (struct zx_pmm_PMUpdateItem_s*)y->gg.g.n;
  return y;
}

/* FUNC(zx_pmm_PMUpdate_PUSH_PMUpdateItem) */

void zx_pmm_PMUpdate_PUSH_PMUpdateItem(struct zx_pmm_PMUpdate_s* x, struct zx_pmm_PMUpdateItem_s* z)
{
  if (!x || !z) return;
  z->gg.g.n = &x->PMUpdateItem->gg.g;
  x->PMUpdateItem = z;
}

/* FUNC(zx_pmm_PMUpdate_REV_PMUpdateItem) */

void zx_pmm_PMUpdate_REV_PMUpdateItem(struct zx_pmm_PMUpdate_s* x)
{
  struct zx_pmm_PMUpdateItem_s* nxt;
  struct zx_pmm_PMUpdateItem_s* y;
  if (!x) return;
  y = x->PMUpdateItem;
  if (!y) return;
  x->PMUpdateItem = 0;
  while (y) {
    nxt = (struct zx_pmm_PMUpdateItem_s*)y->gg.g.n;
    y->gg.g.n = &x->PMUpdateItem->gg.g;
    x->PMUpdateItem = y;
    y = nxt;
  }
}

/* FUNC(zx_pmm_PMUpdate_PUT_PMUpdateItem) */

void zx_pmm_PMUpdate_PUT_PMUpdateItem(struct zx_pmm_PMUpdate_s* x, int n, struct zx_pmm_PMUpdateItem_s* z)
{
  struct zx_pmm_PMUpdateItem_s* y;
  if (!x || !z) return;
  y = x->PMUpdateItem;
  if (!y) return;
  switch (n) {
  case 0:
    z->gg.g.n = y->gg.g.n;
    x->PMUpdateItem = z;
    return;
  default:
    for (; n > 1 && y->gg.g.n; --n, y = (struct zx_pmm_PMUpdateItem_s*)y->gg.g.n) ;
    if (!y->gg.g.n) return;
    z->gg.g.n = y->gg.g.n->n;
    y->gg.g.n = &z->gg.g;
  }
}

/* FUNC(zx_pmm_PMUpdate_ADD_PMUpdateItem) */

void zx_pmm_PMUpdate_ADD_PMUpdateItem(struct zx_pmm_PMUpdate_s* x, int n, struct zx_pmm_PMUpdateItem_s* z)
{
  struct zx_pmm_PMUpdateItem_s* y;
  if (!x || !z) return;
  switch (n) {
  case 0:
  add_to_start:
    z->gg.g.n = &x->PMUpdateItem->gg.g;
    x->PMUpdateItem = z;
    return;
  case -1:
    y = x->PMUpdateItem;
    if (!y) goto add_to_start;
    for (; y->gg.g.n; y = (struct zx_pmm_PMUpdateItem_s*)y->gg.g.n) ;
    break;
  default:
    for (y = x->PMUpdateItem; n > 1 && y; --n, y = (struct zx_pmm_PMUpdateItem_s*)y->gg.g.n) ;
    if (!y) return;
  }
  z->gg.g.n = y->gg.g.n;
  y->gg.g.n = &z->gg.g;
}

/* FUNC(zx_pmm_PMUpdate_DEL_PMUpdateItem) */

void zx_pmm_PMUpdate_DEL_PMUpdateItem(struct zx_pmm_PMUpdate_s* x, int n)
{
  struct zx_pmm_PMUpdateItem_s* y;
  if (!x) return;
  switch (n) {
  case 0:
    x->PMUpdateItem = (struct zx_pmm_PMUpdateItem_s*)x->PMUpdateItem->gg.g.n;
    return;
  case -1:
    y = (struct zx_pmm_PMUpdateItem_s*)x->PMUpdateItem;
    if (!y) return;
    for (; y->gg.g.n; y = (struct zx_pmm_PMUpdateItem_s*)y->gg.g.n) ;
    break;
  default:
    for (y = x->PMUpdateItem; n > 1 && y->gg.g.n; --n, y = (struct zx_pmm_PMUpdateItem_s*)y->gg.g.n) ;
    if (!y->gg.g.n) return;
  }
  y->gg.g.n = y->gg.g.n->n;
}

#endif



#ifdef ZX_ENA_GETPUT

/* FUNC(zx_pmm_PMUpdate_NUM_NotifyTo) */

int zx_pmm_PMUpdate_NUM_NotifyTo(struct zx_pmm_PMUpdate_s* x)
{
  struct zx_elem_s* y;
  int n = 0;
  if (!x) return 0;
  for (y = x->NotifyTo; y; ++n, y = (struct zx_elem_s*)y->g.n) ;
  return n;
}

/* FUNC(zx_pmm_PMUpdate_GET_NotifyTo) */

struct zx_elem_s* zx_pmm_PMUpdate_GET_NotifyTo(struct zx_pmm_PMUpdate_s* x, int n)
{
  struct zx_elem_s* y;
  if (!x) return 0;
  for (y = x->NotifyTo; n>=0 && y; --n, y = (struct zx_elem_s*)y->g.n) ;
  return y;
}

/* FUNC(zx_pmm_PMUpdate_POP_NotifyTo) */

struct zx_elem_s* zx_pmm_PMUpdate_POP_NotifyTo(struct zx_pmm_PMUpdate_s* x)
{
  struct zx_elem_s* y;
  if (!x) return 0;
  y = x->NotifyTo;
  if (y)
    x->NotifyTo = (struct zx_elem_s*)y->g.n;
  return y;
}

/* FUNC(zx_pmm_PMUpdate_PUSH_NotifyTo) */

void zx_pmm_PMUpdate_PUSH_NotifyTo(struct zx_pmm_PMUpdate_s* x, struct zx_elem_s* z)
{
  if (!x || !z) return;
  z->g.n = &x->NotifyTo->g;
  x->NotifyTo = z;
}

/* FUNC(zx_pmm_PMUpdate_REV_NotifyTo) */

void zx_pmm_PMUpdate_REV_NotifyTo(struct zx_pmm_PMUpdate_s* x)
{
  struct zx_elem_s* nxt;
  struct zx_elem_s* y;
  if (!x) return;
  y = x->NotifyTo;
  if (!y) return;
  x->NotifyTo = 0;
  while (y) {
    nxt = (struct zx_elem_s*)y->g.n;
    y->g.n = &x->NotifyTo->g;
    x->NotifyTo = y;
    y = nxt;
  }
}

/* FUNC(zx_pmm_PMUpdate_PUT_NotifyTo) */

void zx_pmm_PMUpdate_PUT_NotifyTo(struct zx_pmm_PMUpdate_s* x, int n, struct zx_elem_s* z)
{
  struct zx_elem_s* y;
  if (!x || !z) return;
  y = x->NotifyTo;
  if (!y) return;
  switch (n) {
  case 0:
    z->g.n = y->g.n;
    x->NotifyTo = z;
    return;
  default:
    for (; n > 1 && y->g.n; --n, y = (struct zx_elem_s*)y->g.n) ;
    if (!y->g.n) return;
    z->g.n = y->g.n->n;
    y->g.n = &z->g;
  }
}

/* FUNC(zx_pmm_PMUpdate_ADD_NotifyTo) */

void zx_pmm_PMUpdate_ADD_NotifyTo(struct zx_pmm_PMUpdate_s* x, int n, struct zx_elem_s* z)
{
  struct zx_elem_s* y;
  if (!x || !z) return;
  switch (n) {
  case 0:
  add_to_start:
    z->g.n = &x->NotifyTo->g;
    x->NotifyTo = z;
    return;
  case -1:
    y = x->NotifyTo;
    if (!y) goto add_to_start;
    for (; y->g.n; y = (struct zx_elem_s*)y->g.n) ;
    break;
  default:
    for (y = x->NotifyTo; n > 1 && y; --n, y = (struct zx_elem_s*)y->g.n) ;
    if (!y) return;
  }
  z->g.n = y->g.n;
  y->g.n = &z->g;
}

/* FUNC(zx_pmm_PMUpdate_DEL_NotifyTo) */

void zx_pmm_PMUpdate_DEL_NotifyTo(struct zx_pmm_PMUpdate_s* x, int n)
{
  struct zx_elem_s* y;
  if (!x) return;
  switch (n) {
  case 0:
    x->NotifyTo = (struct zx_elem_s*)x->NotifyTo->g.n;
    return;
  case -1:
    y = (struct zx_elem_s*)x->NotifyTo;
    if (!y) return;
    for (; y->g.n; y = (struct zx_elem_s*)y->g.n) ;
    break;
  default:
    for (y = x->NotifyTo; n > 1 && y->g.n; --n, y = (struct zx_elem_s*)y->g.n) ;
    if (!y->g.n) return;
  }
  y->g.n = y->g.n->n;
}

#endif








#ifdef ZX_ENA_GETPUT

/* FUNC(zx_pmm_PMUpdateItem_NUM_PMDescriptor) */

int zx_pmm_PMUpdateItem_NUM_PMDescriptor(struct zx_pmm_PMUpdateItem_s* x)
{
  struct zx_prov_PMDescriptor_s* y;
  int n = 0;
  if (!x) return 0;
  for (y = x->PMDescriptor; y; ++n, y = (struct zx_prov_PMDescriptor_s*)y->gg.g.n) ;
  return n;
}

/* FUNC(zx_pmm_PMUpdateItem_GET_PMDescriptor) */

struct zx_prov_PMDescriptor_s* zx_pmm_PMUpdateItem_GET_PMDescriptor(struct zx_pmm_PMUpdateItem_s* x, int n)
{
  struct zx_prov_PMDescriptor_s* y;
  if (!x) return 0;
  for (y = x->PMDescriptor; n>=0 && y; --n, y = (struct zx_prov_PMDescriptor_s*)y->gg.g.n) ;
  return y;
}

/* FUNC(zx_pmm_PMUpdateItem_POP_PMDescriptor) */

struct zx_prov_PMDescriptor_s* zx_pmm_PMUpdateItem_POP_PMDescriptor(struct zx_pmm_PMUpdateItem_s* x)
{
  struct zx_prov_PMDescriptor_s* y;
  if (!x) return 0;
  y = x->PMDescriptor;
  if (y)
    x->PMDescriptor = (struct zx_prov_PMDescriptor_s*)y->gg.g.n;
  return y;
}

/* FUNC(zx_pmm_PMUpdateItem_PUSH_PMDescriptor) */

void zx_pmm_PMUpdateItem_PUSH_PMDescriptor(struct zx_pmm_PMUpdateItem_s* x, struct zx_prov_PMDescriptor_s* z)
{
  if (!x || !z) return;
  z->gg.g.n = &x->PMDescriptor->gg.g;
  x->PMDescriptor = z;
}

/* FUNC(zx_pmm_PMUpdateItem_REV_PMDescriptor) */

void zx_pmm_PMUpdateItem_REV_PMDescriptor(struct zx_pmm_PMUpdateItem_s* x)
{
  struct zx_prov_PMDescriptor_s* nxt;
  struct zx_prov_PMDescriptor_s* y;
  if (!x) return;
  y = x->PMDescriptor;
  if (!y) return;
  x->PMDescriptor = 0;
  while (y) {
    nxt = (struct zx_prov_PMDescriptor_s*)y->gg.g.n;
    y->gg.g.n = &x->PMDescriptor->gg.g;
    x->PMDescriptor = y;
    y = nxt;
  }
}

/* FUNC(zx_pmm_PMUpdateItem_PUT_PMDescriptor) */

void zx_pmm_PMUpdateItem_PUT_PMDescriptor(struct zx_pmm_PMUpdateItem_s* x, int n, struct zx_prov_PMDescriptor_s* z)
{
  struct zx_prov_PMDescriptor_s* y;
  if (!x || !z) return;
  y = x->PMDescriptor;
  if (!y) return;
  switch (n) {
  case 0:
    z->gg.g.n = y->gg.g.n;
    x->PMDescriptor = z;
    return;
  default:
    for (; n > 1 && y->gg.g.n; --n, y = (struct zx_prov_PMDescriptor_s*)y->gg.g.n) ;
    if (!y->gg.g.n) return;
    z->gg.g.n = y->gg.g.n->n;
    y->gg.g.n = &z->gg.g;
  }
}

/* FUNC(zx_pmm_PMUpdateItem_ADD_PMDescriptor) */

void zx_pmm_PMUpdateItem_ADD_PMDescriptor(struct zx_pmm_PMUpdateItem_s* x, int n, struct zx_prov_PMDescriptor_s* z)
{
  struct zx_prov_PMDescriptor_s* y;
  if (!x || !z) return;
  switch (n) {
  case 0:
  add_to_start:
    z->gg.g.n = &x->PMDescriptor->gg.g;
    x->PMDescriptor = z;
    return;
  case -1:
    y = x->PMDescriptor;
    if (!y) goto add_to_start;
    for (; y->gg.g.n; y = (struct zx_prov_PMDescriptor_s*)y->gg.g.n) ;
    break;
  default:
    for (y = x->PMDescriptor; n > 1 && y; --n, y = (struct zx_prov_PMDescriptor_s*)y->gg.g.n) ;
    if (!y) return;
  }
  z->gg.g.n = y->gg.g.n;
  y->gg.g.n = &z->gg.g;
}

/* FUNC(zx_pmm_PMUpdateItem_DEL_PMDescriptor) */

void zx_pmm_PMUpdateItem_DEL_PMDescriptor(struct zx_pmm_PMUpdateItem_s* x, int n)
{
  struct zx_prov_PMDescriptor_s* y;
  if (!x) return;
  switch (n) {
  case 0:
    x->PMDescriptor = (struct zx_prov_PMDescriptor_s*)x->PMDescriptor->gg.g.n;
    return;
  case -1:
    y = (struct zx_prov_PMDescriptor_s*)x->PMDescriptor;
    if (!y) return;
    for (; y->gg.g.n; y = (struct zx_prov_PMDescriptor_s*)y->gg.g.n) ;
    break;
  default:
    for (y = x->PMDescriptor; n > 1 && y->gg.g.n; --n, y = (struct zx_prov_PMDescriptor_s*)y->gg.g.n) ;
    if (!y->gg.g.n) return;
  }
  y->gg.g.n = y->gg.g.n->n;
}

#endif

/* FUNC(zx_pmm_PMUpdateItem_GET_at) */
struct zx_str* zx_pmm_PMUpdateItem_GET_at(struct zx_pmm_PMUpdateItem_s* x) { return x->at; }
/* FUNC(zx_pmm_PMUpdateItem_PUT_at) */
void zx_pmm_PMUpdateItem_PUT_at(struct zx_pmm_PMUpdateItem_s* x, struct zx_str* y) { x->at = y; }
/* FUNC(zx_pmm_PMUpdateItem_GET_itemID) */
struct zx_str* zx_pmm_PMUpdateItem_GET_itemID(struct zx_pmm_PMUpdateItem_s* x) { return x->itemID; }
/* FUNC(zx_pmm_PMUpdateItem_PUT_itemID) */
void zx_pmm_PMUpdateItem_PUT_itemID(struct zx_pmm_PMUpdateItem_s* x, struct zx_str* y) { x->itemID = y; }
/* FUNC(zx_pmm_PMUpdateItem_GET_type) */
struct zx_str* zx_pmm_PMUpdateItem_GET_type(struct zx_pmm_PMUpdateItem_s* x) { return x->type; }
/* FUNC(zx_pmm_PMUpdateItem_PUT_type) */
void zx_pmm_PMUpdateItem_PUT_type(struct zx_pmm_PMUpdateItem_s* x, struct zx_str* y) { x->type = y; }







#ifdef ZX_ENA_GETPUT

/* FUNC(zx_pmm_PMUpdateResponse_NUM_Status) */

int zx_pmm_PMUpdateResponse_NUM_Status(struct zx_pmm_PMUpdateResponse_s* x)
{
  struct zx_lu_Status_s* y;
  int n = 0;
  if (!x) return 0;
  for (y = x->Status; y; ++n, y = (struct zx_lu_Status_s*)y->gg.g.n) ;
  return n;
}

/* FUNC(zx_pmm_PMUpdateResponse_GET_Status) */

struct zx_lu_Status_s* zx_pmm_PMUpdateResponse_GET_Status(struct zx_pmm_PMUpdateResponse_s* x, int n)
{
  struct zx_lu_Status_s* y;
  if (!x) return 0;
  for (y = x->Status; n>=0 && y; --n, y = (struct zx_lu_Status_s*)y->gg.g.n) ;
  return y;
}

/* FUNC(zx_pmm_PMUpdateResponse_POP_Status) */

struct zx_lu_Status_s* zx_pmm_PMUpdateResponse_POP_Status(struct zx_pmm_PMUpdateResponse_s* x)
{
  struct zx_lu_Status_s* y;
  if (!x) return 0;
  y = x->Status;
  if (y)
    x->Status = (struct zx_lu_Status_s*)y->gg.g.n;
  return y;
}

/* FUNC(zx_pmm_PMUpdateResponse_PUSH_Status) */

void zx_pmm_PMUpdateResponse_PUSH_Status(struct zx_pmm_PMUpdateResponse_s* x, struct zx_lu_Status_s* z)
{
  if (!x || !z) return;
  z->gg.g.n = &x->Status->gg.g;
  x->Status = z;
}

/* FUNC(zx_pmm_PMUpdateResponse_REV_Status) */

void zx_pmm_PMUpdateResponse_REV_Status(struct zx_pmm_PMUpdateResponse_s* x)
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

/* FUNC(zx_pmm_PMUpdateResponse_PUT_Status) */

void zx_pmm_PMUpdateResponse_PUT_Status(struct zx_pmm_PMUpdateResponse_s* x, int n, struct zx_lu_Status_s* z)
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

/* FUNC(zx_pmm_PMUpdateResponse_ADD_Status) */

void zx_pmm_PMUpdateResponse_ADD_Status(struct zx_pmm_PMUpdateResponse_s* x, int n, struct zx_lu_Status_s* z)
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

/* FUNC(zx_pmm_PMUpdateResponse_DEL_Status) */

void zx_pmm_PMUpdateResponse_DEL_Status(struct zx_pmm_PMUpdateResponse_s* x, int n)
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

/* FUNC(zx_pmm_Provision_NUM_ProvisioningHandle) */

int zx_pmm_Provision_NUM_ProvisioningHandle(struct zx_pmm_Provision_s* x)
{
  struct zx_prov_ProvisioningHandle_s* y;
  int n = 0;
  if (!x) return 0;
  for (y = x->ProvisioningHandle; y; ++n, y = (struct zx_prov_ProvisioningHandle_s*)y->gg.g.n) ;
  return n;
}

/* FUNC(zx_pmm_Provision_GET_ProvisioningHandle) */

struct zx_prov_ProvisioningHandle_s* zx_pmm_Provision_GET_ProvisioningHandle(struct zx_pmm_Provision_s* x, int n)
{
  struct zx_prov_ProvisioningHandle_s* y;
  if (!x) return 0;
  for (y = x->ProvisioningHandle; n>=0 && y; --n, y = (struct zx_prov_ProvisioningHandle_s*)y->gg.g.n) ;
  return y;
}

/* FUNC(zx_pmm_Provision_POP_ProvisioningHandle) */

struct zx_prov_ProvisioningHandle_s* zx_pmm_Provision_POP_ProvisioningHandle(struct zx_pmm_Provision_s* x)
{
  struct zx_prov_ProvisioningHandle_s* y;
  if (!x) return 0;
  y = x->ProvisioningHandle;
  if (y)
    x->ProvisioningHandle = (struct zx_prov_ProvisioningHandle_s*)y->gg.g.n;
  return y;
}

/* FUNC(zx_pmm_Provision_PUSH_ProvisioningHandle) */

void zx_pmm_Provision_PUSH_ProvisioningHandle(struct zx_pmm_Provision_s* x, struct zx_prov_ProvisioningHandle_s* z)
{
  if (!x || !z) return;
  z->gg.g.n = &x->ProvisioningHandle->gg.g;
  x->ProvisioningHandle = z;
}

/* FUNC(zx_pmm_Provision_REV_ProvisioningHandle) */

void zx_pmm_Provision_REV_ProvisioningHandle(struct zx_pmm_Provision_s* x)
{
  struct zx_prov_ProvisioningHandle_s* nxt;
  struct zx_prov_ProvisioningHandle_s* y;
  if (!x) return;
  y = x->ProvisioningHandle;
  if (!y) return;
  x->ProvisioningHandle = 0;
  while (y) {
    nxt = (struct zx_prov_ProvisioningHandle_s*)y->gg.g.n;
    y->gg.g.n = &x->ProvisioningHandle->gg.g;
    x->ProvisioningHandle = y;
    y = nxt;
  }
}

/* FUNC(zx_pmm_Provision_PUT_ProvisioningHandle) */

void zx_pmm_Provision_PUT_ProvisioningHandle(struct zx_pmm_Provision_s* x, int n, struct zx_prov_ProvisioningHandle_s* z)
{
  struct zx_prov_ProvisioningHandle_s* y;
  if (!x || !z) return;
  y = x->ProvisioningHandle;
  if (!y) return;
  switch (n) {
  case 0:
    z->gg.g.n = y->gg.g.n;
    x->ProvisioningHandle = z;
    return;
  default:
    for (; n > 1 && y->gg.g.n; --n, y = (struct zx_prov_ProvisioningHandle_s*)y->gg.g.n) ;
    if (!y->gg.g.n) return;
    z->gg.g.n = y->gg.g.n->n;
    y->gg.g.n = &z->gg.g;
  }
}

/* FUNC(zx_pmm_Provision_ADD_ProvisioningHandle) */

void zx_pmm_Provision_ADD_ProvisioningHandle(struct zx_pmm_Provision_s* x, int n, struct zx_prov_ProvisioningHandle_s* z)
{
  struct zx_prov_ProvisioningHandle_s* y;
  if (!x || !z) return;
  switch (n) {
  case 0:
  add_to_start:
    z->gg.g.n = &x->ProvisioningHandle->gg.g;
    x->ProvisioningHandle = z;
    return;
  case -1:
    y = x->ProvisioningHandle;
    if (!y) goto add_to_start;
    for (; y->gg.g.n; y = (struct zx_prov_ProvisioningHandle_s*)y->gg.g.n) ;
    break;
  default:
    for (y = x->ProvisioningHandle; n > 1 && y; --n, y = (struct zx_prov_ProvisioningHandle_s*)y->gg.g.n) ;
    if (!y) return;
  }
  z->gg.g.n = y->gg.g.n;
  y->gg.g.n = &z->gg.g;
}

/* FUNC(zx_pmm_Provision_DEL_ProvisioningHandle) */

void zx_pmm_Provision_DEL_ProvisioningHandle(struct zx_pmm_Provision_s* x, int n)
{
  struct zx_prov_ProvisioningHandle_s* y;
  if (!x) return;
  switch (n) {
  case 0:
    x->ProvisioningHandle = (struct zx_prov_ProvisioningHandle_s*)x->ProvisioningHandle->gg.g.n;
    return;
  case -1:
    y = (struct zx_prov_ProvisioningHandle_s*)x->ProvisioningHandle;
    if (!y) return;
    for (; y->gg.g.n; y = (struct zx_prov_ProvisioningHandle_s*)y->gg.g.n) ;
    break;
  default:
    for (y = x->ProvisioningHandle; n > 1 && y->gg.g.n; --n, y = (struct zx_prov_ProvisioningHandle_s*)y->gg.g.n) ;
    if (!y->gg.g.n) return;
  }
  y->gg.g.n = y->gg.g.n->n;
}

#endif



#ifdef ZX_ENA_GETPUT

/* FUNC(zx_pmm_Provision_NUM_PMDescriptor) */

int zx_pmm_Provision_NUM_PMDescriptor(struct zx_pmm_Provision_s* x)
{
  struct zx_prov_PMDescriptor_s* y;
  int n = 0;
  if (!x) return 0;
  for (y = x->PMDescriptor; y; ++n, y = (struct zx_prov_PMDescriptor_s*)y->gg.g.n) ;
  return n;
}

/* FUNC(zx_pmm_Provision_GET_PMDescriptor) */

struct zx_prov_PMDescriptor_s* zx_pmm_Provision_GET_PMDescriptor(struct zx_pmm_Provision_s* x, int n)
{
  struct zx_prov_PMDescriptor_s* y;
  if (!x) return 0;
  for (y = x->PMDescriptor; n>=0 && y; --n, y = (struct zx_prov_PMDescriptor_s*)y->gg.g.n) ;
  return y;
}

/* FUNC(zx_pmm_Provision_POP_PMDescriptor) */

struct zx_prov_PMDescriptor_s* zx_pmm_Provision_POP_PMDescriptor(struct zx_pmm_Provision_s* x)
{
  struct zx_prov_PMDescriptor_s* y;
  if (!x) return 0;
  y = x->PMDescriptor;
  if (y)
    x->PMDescriptor = (struct zx_prov_PMDescriptor_s*)y->gg.g.n;
  return y;
}

/* FUNC(zx_pmm_Provision_PUSH_PMDescriptor) */

void zx_pmm_Provision_PUSH_PMDescriptor(struct zx_pmm_Provision_s* x, struct zx_prov_PMDescriptor_s* z)
{
  if (!x || !z) return;
  z->gg.g.n = &x->PMDescriptor->gg.g;
  x->PMDescriptor = z;
}

/* FUNC(zx_pmm_Provision_REV_PMDescriptor) */

void zx_pmm_Provision_REV_PMDescriptor(struct zx_pmm_Provision_s* x)
{
  struct zx_prov_PMDescriptor_s* nxt;
  struct zx_prov_PMDescriptor_s* y;
  if (!x) return;
  y = x->PMDescriptor;
  if (!y) return;
  x->PMDescriptor = 0;
  while (y) {
    nxt = (struct zx_prov_PMDescriptor_s*)y->gg.g.n;
    y->gg.g.n = &x->PMDescriptor->gg.g;
    x->PMDescriptor = y;
    y = nxt;
  }
}

/* FUNC(zx_pmm_Provision_PUT_PMDescriptor) */

void zx_pmm_Provision_PUT_PMDescriptor(struct zx_pmm_Provision_s* x, int n, struct zx_prov_PMDescriptor_s* z)
{
  struct zx_prov_PMDescriptor_s* y;
  if (!x || !z) return;
  y = x->PMDescriptor;
  if (!y) return;
  switch (n) {
  case 0:
    z->gg.g.n = y->gg.g.n;
    x->PMDescriptor = z;
    return;
  default:
    for (; n > 1 && y->gg.g.n; --n, y = (struct zx_prov_PMDescriptor_s*)y->gg.g.n) ;
    if (!y->gg.g.n) return;
    z->gg.g.n = y->gg.g.n->n;
    y->gg.g.n = &z->gg.g;
  }
}

/* FUNC(zx_pmm_Provision_ADD_PMDescriptor) */

void zx_pmm_Provision_ADD_PMDescriptor(struct zx_pmm_Provision_s* x, int n, struct zx_prov_PMDescriptor_s* z)
{
  struct zx_prov_PMDescriptor_s* y;
  if (!x || !z) return;
  switch (n) {
  case 0:
  add_to_start:
    z->gg.g.n = &x->PMDescriptor->gg.g;
    x->PMDescriptor = z;
    return;
  case -1:
    y = x->PMDescriptor;
    if (!y) goto add_to_start;
    for (; y->gg.g.n; y = (struct zx_prov_PMDescriptor_s*)y->gg.g.n) ;
    break;
  default:
    for (y = x->PMDescriptor; n > 1 && y; --n, y = (struct zx_prov_PMDescriptor_s*)y->gg.g.n) ;
    if (!y) return;
  }
  z->gg.g.n = y->gg.g.n;
  y->gg.g.n = &z->gg.g;
}

/* FUNC(zx_pmm_Provision_DEL_PMDescriptor) */

void zx_pmm_Provision_DEL_PMDescriptor(struct zx_pmm_Provision_s* x, int n)
{
  struct zx_prov_PMDescriptor_s* y;
  if (!x) return;
  switch (n) {
  case 0:
    x->PMDescriptor = (struct zx_prov_PMDescriptor_s*)x->PMDescriptor->gg.g.n;
    return;
  case -1:
    y = (struct zx_prov_PMDescriptor_s*)x->PMDescriptor;
    if (!y) return;
    for (; y->gg.g.n; y = (struct zx_prov_PMDescriptor_s*)y->gg.g.n) ;
    break;
  default:
    for (y = x->PMDescriptor; n > 1 && y->gg.g.n; --n, y = (struct zx_prov_PMDescriptor_s*)y->gg.g.n) ;
    if (!y->gg.g.n) return;
  }
  y->gg.g.n = y->gg.g.n->n;
}

#endif



#ifdef ZX_ENA_GETPUT

/* FUNC(zx_pmm_Provision_NUM_NotifyTo) */

int zx_pmm_Provision_NUM_NotifyTo(struct zx_pmm_Provision_s* x)
{
  struct zx_elem_s* y;
  int n = 0;
  if (!x) return 0;
  for (y = x->NotifyTo; y; ++n, y = (struct zx_elem_s*)y->g.n) ;
  return n;
}

/* FUNC(zx_pmm_Provision_GET_NotifyTo) */

struct zx_elem_s* zx_pmm_Provision_GET_NotifyTo(struct zx_pmm_Provision_s* x, int n)
{
  struct zx_elem_s* y;
  if (!x) return 0;
  for (y = x->NotifyTo; n>=0 && y; --n, y = (struct zx_elem_s*)y->g.n) ;
  return y;
}

/* FUNC(zx_pmm_Provision_POP_NotifyTo) */

struct zx_elem_s* zx_pmm_Provision_POP_NotifyTo(struct zx_pmm_Provision_s* x)
{
  struct zx_elem_s* y;
  if (!x) return 0;
  y = x->NotifyTo;
  if (y)
    x->NotifyTo = (struct zx_elem_s*)y->g.n;
  return y;
}

/* FUNC(zx_pmm_Provision_PUSH_NotifyTo) */

void zx_pmm_Provision_PUSH_NotifyTo(struct zx_pmm_Provision_s* x, struct zx_elem_s* z)
{
  if (!x || !z) return;
  z->g.n = &x->NotifyTo->g;
  x->NotifyTo = z;
}

/* FUNC(zx_pmm_Provision_REV_NotifyTo) */

void zx_pmm_Provision_REV_NotifyTo(struct zx_pmm_Provision_s* x)
{
  struct zx_elem_s* nxt;
  struct zx_elem_s* y;
  if (!x) return;
  y = x->NotifyTo;
  if (!y) return;
  x->NotifyTo = 0;
  while (y) {
    nxt = (struct zx_elem_s*)y->g.n;
    y->g.n = &x->NotifyTo->g;
    x->NotifyTo = y;
    y = nxt;
  }
}

/* FUNC(zx_pmm_Provision_PUT_NotifyTo) */

void zx_pmm_Provision_PUT_NotifyTo(struct zx_pmm_Provision_s* x, int n, struct zx_elem_s* z)
{
  struct zx_elem_s* y;
  if (!x || !z) return;
  y = x->NotifyTo;
  if (!y) return;
  switch (n) {
  case 0:
    z->g.n = y->g.n;
    x->NotifyTo = z;
    return;
  default:
    for (; n > 1 && y->g.n; --n, y = (struct zx_elem_s*)y->g.n) ;
    if (!y->g.n) return;
    z->g.n = y->g.n->n;
    y->g.n = &z->g;
  }
}

/* FUNC(zx_pmm_Provision_ADD_NotifyTo) */

void zx_pmm_Provision_ADD_NotifyTo(struct zx_pmm_Provision_s* x, int n, struct zx_elem_s* z)
{
  struct zx_elem_s* y;
  if (!x || !z) return;
  switch (n) {
  case 0:
  add_to_start:
    z->g.n = &x->NotifyTo->g;
    x->NotifyTo = z;
    return;
  case -1:
    y = x->NotifyTo;
    if (!y) goto add_to_start;
    for (; y->g.n; y = (struct zx_elem_s*)y->g.n) ;
    break;
  default:
    for (y = x->NotifyTo; n > 1 && y; --n, y = (struct zx_elem_s*)y->g.n) ;
    if (!y) return;
  }
  z->g.n = y->g.n;
  y->g.n = &z->g;
}

/* FUNC(zx_pmm_Provision_DEL_NotifyTo) */

void zx_pmm_Provision_DEL_NotifyTo(struct zx_pmm_Provision_s* x, int n)
{
  struct zx_elem_s* y;
  if (!x) return;
  switch (n) {
  case 0:
    x->NotifyTo = (struct zx_elem_s*)x->NotifyTo->g.n;
    return;
  case -1:
    y = (struct zx_elem_s*)x->NotifyTo;
    if (!y) return;
    for (; y->g.n; y = (struct zx_elem_s*)y->g.n) ;
    break;
  default:
    for (y = x->NotifyTo; n > 1 && y->g.n; --n, y = (struct zx_elem_s*)y->g.n) ;
    if (!y->g.n) return;
  }
  y->g.n = y->g.n->n;
}

#endif

/* FUNC(zx_pmm_Provision_GET_wait) */
struct zx_str* zx_pmm_Provision_GET_wait(struct zx_pmm_Provision_s* x) { return x->wait; }
/* FUNC(zx_pmm_Provision_PUT_wait) */
void zx_pmm_Provision_PUT_wait(struct zx_pmm_Provision_s* x, struct zx_str* y) { x->wait = y; }







#ifdef ZX_ENA_GETPUT

/* FUNC(zx_pmm_ProvisionResponse_NUM_Status) */

int zx_pmm_ProvisionResponse_NUM_Status(struct zx_pmm_ProvisionResponse_s* x)
{
  struct zx_lu_Status_s* y;
  int n = 0;
  if (!x) return 0;
  for (y = x->Status; y; ++n, y = (struct zx_lu_Status_s*)y->gg.g.n) ;
  return n;
}

/* FUNC(zx_pmm_ProvisionResponse_GET_Status) */

struct zx_lu_Status_s* zx_pmm_ProvisionResponse_GET_Status(struct zx_pmm_ProvisionResponse_s* x, int n)
{
  struct zx_lu_Status_s* y;
  if (!x) return 0;
  for (y = x->Status; n>=0 && y; --n, y = (struct zx_lu_Status_s*)y->gg.g.n) ;
  return y;
}

/* FUNC(zx_pmm_ProvisionResponse_POP_Status) */

struct zx_lu_Status_s* zx_pmm_ProvisionResponse_POP_Status(struct zx_pmm_ProvisionResponse_s* x)
{
  struct zx_lu_Status_s* y;
  if (!x) return 0;
  y = x->Status;
  if (y)
    x->Status = (struct zx_lu_Status_s*)y->gg.g.n;
  return y;
}

/* FUNC(zx_pmm_ProvisionResponse_PUSH_Status) */

void zx_pmm_ProvisionResponse_PUSH_Status(struct zx_pmm_ProvisionResponse_s* x, struct zx_lu_Status_s* z)
{
  if (!x || !z) return;
  z->gg.g.n = &x->Status->gg.g;
  x->Status = z;
}

/* FUNC(zx_pmm_ProvisionResponse_REV_Status) */

void zx_pmm_ProvisionResponse_REV_Status(struct zx_pmm_ProvisionResponse_s* x)
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

/* FUNC(zx_pmm_ProvisionResponse_PUT_Status) */

void zx_pmm_ProvisionResponse_PUT_Status(struct zx_pmm_ProvisionResponse_s* x, int n, struct zx_lu_Status_s* z)
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

/* FUNC(zx_pmm_ProvisionResponse_ADD_Status) */

void zx_pmm_ProvisionResponse_ADD_Status(struct zx_pmm_ProvisionResponse_s* x, int n, struct zx_lu_Status_s* z)
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

/* FUNC(zx_pmm_ProvisionResponse_DEL_Status) */

void zx_pmm_ProvisionResponse_DEL_Status(struct zx_pmm_ProvisionResponse_s* x, int n)
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






/* EOF -- c/zx-pmm-getput.c */
