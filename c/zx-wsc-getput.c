/* c/zx-wsc-getput.c - WARNING: This file was automatically generated. DO NOT EDIT!
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
#include "c/zx-wsc-data.h"



#ifdef ZX_ENA_GETPUT

/* FUNC(zx_wsc_DerivedKeyToken_NUM_SecurityTokenReference) */

int zx_wsc_DerivedKeyToken_NUM_SecurityTokenReference(struct zx_wsc_DerivedKeyToken_s* x)
{
  struct zx_wsse_SecurityTokenReference_s* y;
  int n = 0;
  if (!x) return 0;
  for (y = x->SecurityTokenReference; y; ++n, y = (struct zx_wsse_SecurityTokenReference_s*)y->gg.g.n) ;
  return n;
}

/* FUNC(zx_wsc_DerivedKeyToken_GET_SecurityTokenReference) */

struct zx_wsse_SecurityTokenReference_s* zx_wsc_DerivedKeyToken_GET_SecurityTokenReference(struct zx_wsc_DerivedKeyToken_s* x, int n)
{
  struct zx_wsse_SecurityTokenReference_s* y;
  if (!x) return 0;
  for (y = x->SecurityTokenReference; n>=0 && y; --n, y = (struct zx_wsse_SecurityTokenReference_s*)y->gg.g.n) ;
  return y;
}

/* FUNC(zx_wsc_DerivedKeyToken_POP_SecurityTokenReference) */

struct zx_wsse_SecurityTokenReference_s* zx_wsc_DerivedKeyToken_POP_SecurityTokenReference(struct zx_wsc_DerivedKeyToken_s* x)
{
  struct zx_wsse_SecurityTokenReference_s* y;
  if (!x) return 0;
  y = x->SecurityTokenReference;
  if (y)
    x->SecurityTokenReference = (struct zx_wsse_SecurityTokenReference_s*)y->gg.g.n;
  return y;
}

/* FUNC(zx_wsc_DerivedKeyToken_PUSH_SecurityTokenReference) */

void zx_wsc_DerivedKeyToken_PUSH_SecurityTokenReference(struct zx_wsc_DerivedKeyToken_s* x, struct zx_wsse_SecurityTokenReference_s* z)
{
  if (!x || !z) return;
  z->gg.g.n = &x->SecurityTokenReference->gg.g;
  x->SecurityTokenReference = z;
}

/* FUNC(zx_wsc_DerivedKeyToken_REV_SecurityTokenReference) */

void zx_wsc_DerivedKeyToken_REV_SecurityTokenReference(struct zx_wsc_DerivedKeyToken_s* x)
{
  struct zx_wsse_SecurityTokenReference_s* nxt;
  struct zx_wsse_SecurityTokenReference_s* y;
  if (!x) return;
  y = x->SecurityTokenReference;
  if (!y) return;
  x->SecurityTokenReference = 0;
  while (y) {
    nxt = (struct zx_wsse_SecurityTokenReference_s*)y->gg.g.n;
    y->gg.g.n = &x->SecurityTokenReference->gg.g;
    x->SecurityTokenReference = y;
    y = nxt;
  }
}

/* FUNC(zx_wsc_DerivedKeyToken_PUT_SecurityTokenReference) */

void zx_wsc_DerivedKeyToken_PUT_SecurityTokenReference(struct zx_wsc_DerivedKeyToken_s* x, int n, struct zx_wsse_SecurityTokenReference_s* z)
{
  struct zx_wsse_SecurityTokenReference_s* y;
  if (!x || !z) return;
  y = x->SecurityTokenReference;
  if (!y) return;
  switch (n) {
  case 0:
    z->gg.g.n = y->gg.g.n;
    x->SecurityTokenReference = z;
    return;
  default:
    for (; n > 1 && y->gg.g.n; --n, y = (struct zx_wsse_SecurityTokenReference_s*)y->gg.g.n) ;
    if (!y->gg.g.n) return;
    z->gg.g.n = y->gg.g.n->n;
    y->gg.g.n = &z->gg.g;
  }
}

/* FUNC(zx_wsc_DerivedKeyToken_ADD_SecurityTokenReference) */

void zx_wsc_DerivedKeyToken_ADD_SecurityTokenReference(struct zx_wsc_DerivedKeyToken_s* x, int n, struct zx_wsse_SecurityTokenReference_s* z)
{
  struct zx_wsse_SecurityTokenReference_s* y;
  if (!x || !z) return;
  switch (n) {
  case 0:
  add_to_start:
    z->gg.g.n = &x->SecurityTokenReference->gg.g;
    x->SecurityTokenReference = z;
    return;
  case -1:
    y = x->SecurityTokenReference;
    if (!y) goto add_to_start;
    for (; y->gg.g.n; y = (struct zx_wsse_SecurityTokenReference_s*)y->gg.g.n) ;
    break;
  default:
    for (y = x->SecurityTokenReference; n > 1 && y; --n, y = (struct zx_wsse_SecurityTokenReference_s*)y->gg.g.n) ;
    if (!y) return;
  }
  z->gg.g.n = y->gg.g.n;
  y->gg.g.n = &z->gg.g;
}

/* FUNC(zx_wsc_DerivedKeyToken_DEL_SecurityTokenReference) */

void zx_wsc_DerivedKeyToken_DEL_SecurityTokenReference(struct zx_wsc_DerivedKeyToken_s* x, int n)
{
  struct zx_wsse_SecurityTokenReference_s* y;
  if (!x) return;
  switch (n) {
  case 0:
    x->SecurityTokenReference = (struct zx_wsse_SecurityTokenReference_s*)x->SecurityTokenReference->gg.g.n;
    return;
  case -1:
    y = (struct zx_wsse_SecurityTokenReference_s*)x->SecurityTokenReference;
    if (!y) return;
    for (; y->gg.g.n; y = (struct zx_wsse_SecurityTokenReference_s*)y->gg.g.n) ;
    break;
  default:
    for (y = x->SecurityTokenReference; n > 1 && y->gg.g.n; --n, y = (struct zx_wsse_SecurityTokenReference_s*)y->gg.g.n) ;
    if (!y->gg.g.n) return;
  }
  y->gg.g.n = y->gg.g.n->n;
}

#endif



#ifdef ZX_ENA_GETPUT

/* FUNC(zx_wsc_DerivedKeyToken_NUM_Properties) */

int zx_wsc_DerivedKeyToken_NUM_Properties(struct zx_wsc_DerivedKeyToken_s* x)
{
  struct zx_wsc_Properties_s* y;
  int n = 0;
  if (!x) return 0;
  for (y = x->Properties; y; ++n, y = (struct zx_wsc_Properties_s*)y->gg.g.n) ;
  return n;
}

/* FUNC(zx_wsc_DerivedKeyToken_GET_Properties) */

struct zx_wsc_Properties_s* zx_wsc_DerivedKeyToken_GET_Properties(struct zx_wsc_DerivedKeyToken_s* x, int n)
{
  struct zx_wsc_Properties_s* y;
  if (!x) return 0;
  for (y = x->Properties; n>=0 && y; --n, y = (struct zx_wsc_Properties_s*)y->gg.g.n) ;
  return y;
}

/* FUNC(zx_wsc_DerivedKeyToken_POP_Properties) */

struct zx_wsc_Properties_s* zx_wsc_DerivedKeyToken_POP_Properties(struct zx_wsc_DerivedKeyToken_s* x)
{
  struct zx_wsc_Properties_s* y;
  if (!x) return 0;
  y = x->Properties;
  if (y)
    x->Properties = (struct zx_wsc_Properties_s*)y->gg.g.n;
  return y;
}

/* FUNC(zx_wsc_DerivedKeyToken_PUSH_Properties) */

void zx_wsc_DerivedKeyToken_PUSH_Properties(struct zx_wsc_DerivedKeyToken_s* x, struct zx_wsc_Properties_s* z)
{
  if (!x || !z) return;
  z->gg.g.n = &x->Properties->gg.g;
  x->Properties = z;
}

/* FUNC(zx_wsc_DerivedKeyToken_REV_Properties) */

void zx_wsc_DerivedKeyToken_REV_Properties(struct zx_wsc_DerivedKeyToken_s* x)
{
  struct zx_wsc_Properties_s* nxt;
  struct zx_wsc_Properties_s* y;
  if (!x) return;
  y = x->Properties;
  if (!y) return;
  x->Properties = 0;
  while (y) {
    nxt = (struct zx_wsc_Properties_s*)y->gg.g.n;
    y->gg.g.n = &x->Properties->gg.g;
    x->Properties = y;
    y = nxt;
  }
}

/* FUNC(zx_wsc_DerivedKeyToken_PUT_Properties) */

void zx_wsc_DerivedKeyToken_PUT_Properties(struct zx_wsc_DerivedKeyToken_s* x, int n, struct zx_wsc_Properties_s* z)
{
  struct zx_wsc_Properties_s* y;
  if (!x || !z) return;
  y = x->Properties;
  if (!y) return;
  switch (n) {
  case 0:
    z->gg.g.n = y->gg.g.n;
    x->Properties = z;
    return;
  default:
    for (; n > 1 && y->gg.g.n; --n, y = (struct zx_wsc_Properties_s*)y->gg.g.n) ;
    if (!y->gg.g.n) return;
    z->gg.g.n = y->gg.g.n->n;
    y->gg.g.n = &z->gg.g;
  }
}

/* FUNC(zx_wsc_DerivedKeyToken_ADD_Properties) */

void zx_wsc_DerivedKeyToken_ADD_Properties(struct zx_wsc_DerivedKeyToken_s* x, int n, struct zx_wsc_Properties_s* z)
{
  struct zx_wsc_Properties_s* y;
  if (!x || !z) return;
  switch (n) {
  case 0:
  add_to_start:
    z->gg.g.n = &x->Properties->gg.g;
    x->Properties = z;
    return;
  case -1:
    y = x->Properties;
    if (!y) goto add_to_start;
    for (; y->gg.g.n; y = (struct zx_wsc_Properties_s*)y->gg.g.n) ;
    break;
  default:
    for (y = x->Properties; n > 1 && y; --n, y = (struct zx_wsc_Properties_s*)y->gg.g.n) ;
    if (!y) return;
  }
  z->gg.g.n = y->gg.g.n;
  y->gg.g.n = &z->gg.g;
}

/* FUNC(zx_wsc_DerivedKeyToken_DEL_Properties) */

void zx_wsc_DerivedKeyToken_DEL_Properties(struct zx_wsc_DerivedKeyToken_s* x, int n)
{
  struct zx_wsc_Properties_s* y;
  if (!x) return;
  switch (n) {
  case 0:
    x->Properties = (struct zx_wsc_Properties_s*)x->Properties->gg.g.n;
    return;
  case -1:
    y = (struct zx_wsc_Properties_s*)x->Properties;
    if (!y) return;
    for (; y->gg.g.n; y = (struct zx_wsc_Properties_s*)y->gg.g.n) ;
    break;
  default:
    for (y = x->Properties; n > 1 && y->gg.g.n; --n, y = (struct zx_wsc_Properties_s*)y->gg.g.n) ;
    if (!y->gg.g.n) return;
  }
  y->gg.g.n = y->gg.g.n->n;
}

#endif



#ifdef ZX_ENA_GETPUT

/* FUNC(zx_wsc_DerivedKeyToken_NUM_Generation) */

int zx_wsc_DerivedKeyToken_NUM_Generation(struct zx_wsc_DerivedKeyToken_s* x)
{
  struct zx_elem_s* y;
  int n = 0;
  if (!x) return 0;
  for (y = x->Generation; y; ++n, y = (struct zx_elem_s*)y->g.n) ;
  return n;
}

/* FUNC(zx_wsc_DerivedKeyToken_GET_Generation) */

struct zx_elem_s* zx_wsc_DerivedKeyToken_GET_Generation(struct zx_wsc_DerivedKeyToken_s* x, int n)
{
  struct zx_elem_s* y;
  if (!x) return 0;
  for (y = x->Generation; n>=0 && y; --n, y = (struct zx_elem_s*)y->g.n) ;
  return y;
}

/* FUNC(zx_wsc_DerivedKeyToken_POP_Generation) */

struct zx_elem_s* zx_wsc_DerivedKeyToken_POP_Generation(struct zx_wsc_DerivedKeyToken_s* x)
{
  struct zx_elem_s* y;
  if (!x) return 0;
  y = x->Generation;
  if (y)
    x->Generation = (struct zx_elem_s*)y->g.n;
  return y;
}

/* FUNC(zx_wsc_DerivedKeyToken_PUSH_Generation) */

void zx_wsc_DerivedKeyToken_PUSH_Generation(struct zx_wsc_DerivedKeyToken_s* x, struct zx_elem_s* z)
{
  if (!x || !z) return;
  z->g.n = &x->Generation->g;
  x->Generation = z;
}

/* FUNC(zx_wsc_DerivedKeyToken_REV_Generation) */

void zx_wsc_DerivedKeyToken_REV_Generation(struct zx_wsc_DerivedKeyToken_s* x)
{
  struct zx_elem_s* nxt;
  struct zx_elem_s* y;
  if (!x) return;
  y = x->Generation;
  if (!y) return;
  x->Generation = 0;
  while (y) {
    nxt = (struct zx_elem_s*)y->g.n;
    y->g.n = &x->Generation->g;
    x->Generation = y;
    y = nxt;
  }
}

/* FUNC(zx_wsc_DerivedKeyToken_PUT_Generation) */

void zx_wsc_DerivedKeyToken_PUT_Generation(struct zx_wsc_DerivedKeyToken_s* x, int n, struct zx_elem_s* z)
{
  struct zx_elem_s* y;
  if (!x || !z) return;
  y = x->Generation;
  if (!y) return;
  switch (n) {
  case 0:
    z->g.n = y->g.n;
    x->Generation = z;
    return;
  default:
    for (; n > 1 && y->g.n; --n, y = (struct zx_elem_s*)y->g.n) ;
    if (!y->g.n) return;
    z->g.n = y->g.n->n;
    y->g.n = &z->g;
  }
}

/* FUNC(zx_wsc_DerivedKeyToken_ADD_Generation) */

void zx_wsc_DerivedKeyToken_ADD_Generation(struct zx_wsc_DerivedKeyToken_s* x, int n, struct zx_elem_s* z)
{
  struct zx_elem_s* y;
  if (!x || !z) return;
  switch (n) {
  case 0:
  add_to_start:
    z->g.n = &x->Generation->g;
    x->Generation = z;
    return;
  case -1:
    y = x->Generation;
    if (!y) goto add_to_start;
    for (; y->g.n; y = (struct zx_elem_s*)y->g.n) ;
    break;
  default:
    for (y = x->Generation; n > 1 && y; --n, y = (struct zx_elem_s*)y->g.n) ;
    if (!y) return;
  }
  z->g.n = y->g.n;
  y->g.n = &z->g;
}

/* FUNC(zx_wsc_DerivedKeyToken_DEL_Generation) */

void zx_wsc_DerivedKeyToken_DEL_Generation(struct zx_wsc_DerivedKeyToken_s* x, int n)
{
  struct zx_elem_s* y;
  if (!x) return;
  switch (n) {
  case 0:
    x->Generation = (struct zx_elem_s*)x->Generation->g.n;
    return;
  case -1:
    y = (struct zx_elem_s*)x->Generation;
    if (!y) return;
    for (; y->g.n; y = (struct zx_elem_s*)y->g.n) ;
    break;
  default:
    for (y = x->Generation; n > 1 && y->g.n; --n, y = (struct zx_elem_s*)y->g.n) ;
    if (!y->g.n) return;
  }
  y->g.n = y->g.n->n;
}

#endif



#ifdef ZX_ENA_GETPUT

/* FUNC(zx_wsc_DerivedKeyToken_NUM_Offset) */

int zx_wsc_DerivedKeyToken_NUM_Offset(struct zx_wsc_DerivedKeyToken_s* x)
{
  struct zx_elem_s* y;
  int n = 0;
  if (!x) return 0;
  for (y = x->Offset; y; ++n, y = (struct zx_elem_s*)y->g.n) ;
  return n;
}

/* FUNC(zx_wsc_DerivedKeyToken_GET_Offset) */

struct zx_elem_s* zx_wsc_DerivedKeyToken_GET_Offset(struct zx_wsc_DerivedKeyToken_s* x, int n)
{
  struct zx_elem_s* y;
  if (!x) return 0;
  for (y = x->Offset; n>=0 && y; --n, y = (struct zx_elem_s*)y->g.n) ;
  return y;
}

/* FUNC(zx_wsc_DerivedKeyToken_POP_Offset) */

struct zx_elem_s* zx_wsc_DerivedKeyToken_POP_Offset(struct zx_wsc_DerivedKeyToken_s* x)
{
  struct zx_elem_s* y;
  if (!x) return 0;
  y = x->Offset;
  if (y)
    x->Offset = (struct zx_elem_s*)y->g.n;
  return y;
}

/* FUNC(zx_wsc_DerivedKeyToken_PUSH_Offset) */

void zx_wsc_DerivedKeyToken_PUSH_Offset(struct zx_wsc_DerivedKeyToken_s* x, struct zx_elem_s* z)
{
  if (!x || !z) return;
  z->g.n = &x->Offset->g;
  x->Offset = z;
}

/* FUNC(zx_wsc_DerivedKeyToken_REV_Offset) */

void zx_wsc_DerivedKeyToken_REV_Offset(struct zx_wsc_DerivedKeyToken_s* x)
{
  struct zx_elem_s* nxt;
  struct zx_elem_s* y;
  if (!x) return;
  y = x->Offset;
  if (!y) return;
  x->Offset = 0;
  while (y) {
    nxt = (struct zx_elem_s*)y->g.n;
    y->g.n = &x->Offset->g;
    x->Offset = y;
    y = nxt;
  }
}

/* FUNC(zx_wsc_DerivedKeyToken_PUT_Offset) */

void zx_wsc_DerivedKeyToken_PUT_Offset(struct zx_wsc_DerivedKeyToken_s* x, int n, struct zx_elem_s* z)
{
  struct zx_elem_s* y;
  if (!x || !z) return;
  y = x->Offset;
  if (!y) return;
  switch (n) {
  case 0:
    z->g.n = y->g.n;
    x->Offset = z;
    return;
  default:
    for (; n > 1 && y->g.n; --n, y = (struct zx_elem_s*)y->g.n) ;
    if (!y->g.n) return;
    z->g.n = y->g.n->n;
    y->g.n = &z->g;
  }
}

/* FUNC(zx_wsc_DerivedKeyToken_ADD_Offset) */

void zx_wsc_DerivedKeyToken_ADD_Offset(struct zx_wsc_DerivedKeyToken_s* x, int n, struct zx_elem_s* z)
{
  struct zx_elem_s* y;
  if (!x || !z) return;
  switch (n) {
  case 0:
  add_to_start:
    z->g.n = &x->Offset->g;
    x->Offset = z;
    return;
  case -1:
    y = x->Offset;
    if (!y) goto add_to_start;
    for (; y->g.n; y = (struct zx_elem_s*)y->g.n) ;
    break;
  default:
    for (y = x->Offset; n > 1 && y; --n, y = (struct zx_elem_s*)y->g.n) ;
    if (!y) return;
  }
  z->g.n = y->g.n;
  y->g.n = &z->g;
}

/* FUNC(zx_wsc_DerivedKeyToken_DEL_Offset) */

void zx_wsc_DerivedKeyToken_DEL_Offset(struct zx_wsc_DerivedKeyToken_s* x, int n)
{
  struct zx_elem_s* y;
  if (!x) return;
  switch (n) {
  case 0:
    x->Offset = (struct zx_elem_s*)x->Offset->g.n;
    return;
  case -1:
    y = (struct zx_elem_s*)x->Offset;
    if (!y) return;
    for (; y->g.n; y = (struct zx_elem_s*)y->g.n) ;
    break;
  default:
    for (y = x->Offset; n > 1 && y->g.n; --n, y = (struct zx_elem_s*)y->g.n) ;
    if (!y->g.n) return;
  }
  y->g.n = y->g.n->n;
}

#endif



#ifdef ZX_ENA_GETPUT

/* FUNC(zx_wsc_DerivedKeyToken_NUM_Length) */

int zx_wsc_DerivedKeyToken_NUM_Length(struct zx_wsc_DerivedKeyToken_s* x)
{
  struct zx_elem_s* y;
  int n = 0;
  if (!x) return 0;
  for (y = x->Length; y; ++n, y = (struct zx_elem_s*)y->g.n) ;
  return n;
}

/* FUNC(zx_wsc_DerivedKeyToken_GET_Length) */

struct zx_elem_s* zx_wsc_DerivedKeyToken_GET_Length(struct zx_wsc_DerivedKeyToken_s* x, int n)
{
  struct zx_elem_s* y;
  if (!x) return 0;
  for (y = x->Length; n>=0 && y; --n, y = (struct zx_elem_s*)y->g.n) ;
  return y;
}

/* FUNC(zx_wsc_DerivedKeyToken_POP_Length) */

struct zx_elem_s* zx_wsc_DerivedKeyToken_POP_Length(struct zx_wsc_DerivedKeyToken_s* x)
{
  struct zx_elem_s* y;
  if (!x) return 0;
  y = x->Length;
  if (y)
    x->Length = (struct zx_elem_s*)y->g.n;
  return y;
}

/* FUNC(zx_wsc_DerivedKeyToken_PUSH_Length) */

void zx_wsc_DerivedKeyToken_PUSH_Length(struct zx_wsc_DerivedKeyToken_s* x, struct zx_elem_s* z)
{
  if (!x || !z) return;
  z->g.n = &x->Length->g;
  x->Length = z;
}

/* FUNC(zx_wsc_DerivedKeyToken_REV_Length) */

void zx_wsc_DerivedKeyToken_REV_Length(struct zx_wsc_DerivedKeyToken_s* x)
{
  struct zx_elem_s* nxt;
  struct zx_elem_s* y;
  if (!x) return;
  y = x->Length;
  if (!y) return;
  x->Length = 0;
  while (y) {
    nxt = (struct zx_elem_s*)y->g.n;
    y->g.n = &x->Length->g;
    x->Length = y;
    y = nxt;
  }
}

/* FUNC(zx_wsc_DerivedKeyToken_PUT_Length) */

void zx_wsc_DerivedKeyToken_PUT_Length(struct zx_wsc_DerivedKeyToken_s* x, int n, struct zx_elem_s* z)
{
  struct zx_elem_s* y;
  if (!x || !z) return;
  y = x->Length;
  if (!y) return;
  switch (n) {
  case 0:
    z->g.n = y->g.n;
    x->Length = z;
    return;
  default:
    for (; n > 1 && y->g.n; --n, y = (struct zx_elem_s*)y->g.n) ;
    if (!y->g.n) return;
    z->g.n = y->g.n->n;
    y->g.n = &z->g;
  }
}

/* FUNC(zx_wsc_DerivedKeyToken_ADD_Length) */

void zx_wsc_DerivedKeyToken_ADD_Length(struct zx_wsc_DerivedKeyToken_s* x, int n, struct zx_elem_s* z)
{
  struct zx_elem_s* y;
  if (!x || !z) return;
  switch (n) {
  case 0:
  add_to_start:
    z->g.n = &x->Length->g;
    x->Length = z;
    return;
  case -1:
    y = x->Length;
    if (!y) goto add_to_start;
    for (; y->g.n; y = (struct zx_elem_s*)y->g.n) ;
    break;
  default:
    for (y = x->Length; n > 1 && y; --n, y = (struct zx_elem_s*)y->g.n) ;
    if (!y) return;
  }
  z->g.n = y->g.n;
  y->g.n = &z->g;
}

/* FUNC(zx_wsc_DerivedKeyToken_DEL_Length) */

void zx_wsc_DerivedKeyToken_DEL_Length(struct zx_wsc_DerivedKeyToken_s* x, int n)
{
  struct zx_elem_s* y;
  if (!x) return;
  switch (n) {
  case 0:
    x->Length = (struct zx_elem_s*)x->Length->g.n;
    return;
  case -1:
    y = (struct zx_elem_s*)x->Length;
    if (!y) return;
    for (; y->g.n; y = (struct zx_elem_s*)y->g.n) ;
    break;
  default:
    for (y = x->Length; n > 1 && y->g.n; --n, y = (struct zx_elem_s*)y->g.n) ;
    if (!y->g.n) return;
  }
  y->g.n = y->g.n->n;
}

#endif



#ifdef ZX_ENA_GETPUT

/* FUNC(zx_wsc_DerivedKeyToken_NUM_Label) */

int zx_wsc_DerivedKeyToken_NUM_Label(struct zx_wsc_DerivedKeyToken_s* x)
{
  struct zx_elem_s* y;
  int n = 0;
  if (!x) return 0;
  for (y = x->Label; y; ++n, y = (struct zx_elem_s*)y->g.n) ;
  return n;
}

/* FUNC(zx_wsc_DerivedKeyToken_GET_Label) */

struct zx_elem_s* zx_wsc_DerivedKeyToken_GET_Label(struct zx_wsc_DerivedKeyToken_s* x, int n)
{
  struct zx_elem_s* y;
  if (!x) return 0;
  for (y = x->Label; n>=0 && y; --n, y = (struct zx_elem_s*)y->g.n) ;
  return y;
}

/* FUNC(zx_wsc_DerivedKeyToken_POP_Label) */

struct zx_elem_s* zx_wsc_DerivedKeyToken_POP_Label(struct zx_wsc_DerivedKeyToken_s* x)
{
  struct zx_elem_s* y;
  if (!x) return 0;
  y = x->Label;
  if (y)
    x->Label = (struct zx_elem_s*)y->g.n;
  return y;
}

/* FUNC(zx_wsc_DerivedKeyToken_PUSH_Label) */

void zx_wsc_DerivedKeyToken_PUSH_Label(struct zx_wsc_DerivedKeyToken_s* x, struct zx_elem_s* z)
{
  if (!x || !z) return;
  z->g.n = &x->Label->g;
  x->Label = z;
}

/* FUNC(zx_wsc_DerivedKeyToken_REV_Label) */

void zx_wsc_DerivedKeyToken_REV_Label(struct zx_wsc_DerivedKeyToken_s* x)
{
  struct zx_elem_s* nxt;
  struct zx_elem_s* y;
  if (!x) return;
  y = x->Label;
  if (!y) return;
  x->Label = 0;
  while (y) {
    nxt = (struct zx_elem_s*)y->g.n;
    y->g.n = &x->Label->g;
    x->Label = y;
    y = nxt;
  }
}

/* FUNC(zx_wsc_DerivedKeyToken_PUT_Label) */

void zx_wsc_DerivedKeyToken_PUT_Label(struct zx_wsc_DerivedKeyToken_s* x, int n, struct zx_elem_s* z)
{
  struct zx_elem_s* y;
  if (!x || !z) return;
  y = x->Label;
  if (!y) return;
  switch (n) {
  case 0:
    z->g.n = y->g.n;
    x->Label = z;
    return;
  default:
    for (; n > 1 && y->g.n; --n, y = (struct zx_elem_s*)y->g.n) ;
    if (!y->g.n) return;
    z->g.n = y->g.n->n;
    y->g.n = &z->g;
  }
}

/* FUNC(zx_wsc_DerivedKeyToken_ADD_Label) */

void zx_wsc_DerivedKeyToken_ADD_Label(struct zx_wsc_DerivedKeyToken_s* x, int n, struct zx_elem_s* z)
{
  struct zx_elem_s* y;
  if (!x || !z) return;
  switch (n) {
  case 0:
  add_to_start:
    z->g.n = &x->Label->g;
    x->Label = z;
    return;
  case -1:
    y = x->Label;
    if (!y) goto add_to_start;
    for (; y->g.n; y = (struct zx_elem_s*)y->g.n) ;
    break;
  default:
    for (y = x->Label; n > 1 && y; --n, y = (struct zx_elem_s*)y->g.n) ;
    if (!y) return;
  }
  z->g.n = y->g.n;
  y->g.n = &z->g;
}

/* FUNC(zx_wsc_DerivedKeyToken_DEL_Label) */

void zx_wsc_DerivedKeyToken_DEL_Label(struct zx_wsc_DerivedKeyToken_s* x, int n)
{
  struct zx_elem_s* y;
  if (!x) return;
  switch (n) {
  case 0:
    x->Label = (struct zx_elem_s*)x->Label->g.n;
    return;
  case -1:
    y = (struct zx_elem_s*)x->Label;
    if (!y) return;
    for (; y->g.n; y = (struct zx_elem_s*)y->g.n) ;
    break;
  default:
    for (y = x->Label; n > 1 && y->g.n; --n, y = (struct zx_elem_s*)y->g.n) ;
    if (!y->g.n) return;
  }
  y->g.n = y->g.n->n;
}

#endif



#ifdef ZX_ENA_GETPUT

/* FUNC(zx_wsc_DerivedKeyToken_NUM_Nonce) */

int zx_wsc_DerivedKeyToken_NUM_Nonce(struct zx_wsc_DerivedKeyToken_s* x)
{
  struct zx_elem_s* y;
  int n = 0;
  if (!x) return 0;
  for (y = x->Nonce; y; ++n, y = (struct zx_elem_s*)y->g.n) ;
  return n;
}

/* FUNC(zx_wsc_DerivedKeyToken_GET_Nonce) */

struct zx_elem_s* zx_wsc_DerivedKeyToken_GET_Nonce(struct zx_wsc_DerivedKeyToken_s* x, int n)
{
  struct zx_elem_s* y;
  if (!x) return 0;
  for (y = x->Nonce; n>=0 && y; --n, y = (struct zx_elem_s*)y->g.n) ;
  return y;
}

/* FUNC(zx_wsc_DerivedKeyToken_POP_Nonce) */

struct zx_elem_s* zx_wsc_DerivedKeyToken_POP_Nonce(struct zx_wsc_DerivedKeyToken_s* x)
{
  struct zx_elem_s* y;
  if (!x) return 0;
  y = x->Nonce;
  if (y)
    x->Nonce = (struct zx_elem_s*)y->g.n;
  return y;
}

/* FUNC(zx_wsc_DerivedKeyToken_PUSH_Nonce) */

void zx_wsc_DerivedKeyToken_PUSH_Nonce(struct zx_wsc_DerivedKeyToken_s* x, struct zx_elem_s* z)
{
  if (!x || !z) return;
  z->g.n = &x->Nonce->g;
  x->Nonce = z;
}

/* FUNC(zx_wsc_DerivedKeyToken_REV_Nonce) */

void zx_wsc_DerivedKeyToken_REV_Nonce(struct zx_wsc_DerivedKeyToken_s* x)
{
  struct zx_elem_s* nxt;
  struct zx_elem_s* y;
  if (!x) return;
  y = x->Nonce;
  if (!y) return;
  x->Nonce = 0;
  while (y) {
    nxt = (struct zx_elem_s*)y->g.n;
    y->g.n = &x->Nonce->g;
    x->Nonce = y;
    y = nxt;
  }
}

/* FUNC(zx_wsc_DerivedKeyToken_PUT_Nonce) */

void zx_wsc_DerivedKeyToken_PUT_Nonce(struct zx_wsc_DerivedKeyToken_s* x, int n, struct zx_elem_s* z)
{
  struct zx_elem_s* y;
  if (!x || !z) return;
  y = x->Nonce;
  if (!y) return;
  switch (n) {
  case 0:
    z->g.n = y->g.n;
    x->Nonce = z;
    return;
  default:
    for (; n > 1 && y->g.n; --n, y = (struct zx_elem_s*)y->g.n) ;
    if (!y->g.n) return;
    z->g.n = y->g.n->n;
    y->g.n = &z->g;
  }
}

/* FUNC(zx_wsc_DerivedKeyToken_ADD_Nonce) */

void zx_wsc_DerivedKeyToken_ADD_Nonce(struct zx_wsc_DerivedKeyToken_s* x, int n, struct zx_elem_s* z)
{
  struct zx_elem_s* y;
  if (!x || !z) return;
  switch (n) {
  case 0:
  add_to_start:
    z->g.n = &x->Nonce->g;
    x->Nonce = z;
    return;
  case -1:
    y = x->Nonce;
    if (!y) goto add_to_start;
    for (; y->g.n; y = (struct zx_elem_s*)y->g.n) ;
    break;
  default:
    for (y = x->Nonce; n > 1 && y; --n, y = (struct zx_elem_s*)y->g.n) ;
    if (!y) return;
  }
  z->g.n = y->g.n;
  y->g.n = &z->g;
}

/* FUNC(zx_wsc_DerivedKeyToken_DEL_Nonce) */

void zx_wsc_DerivedKeyToken_DEL_Nonce(struct zx_wsc_DerivedKeyToken_s* x, int n)
{
  struct zx_elem_s* y;
  if (!x) return;
  switch (n) {
  case 0:
    x->Nonce = (struct zx_elem_s*)x->Nonce->g.n;
    return;
  case -1:
    y = (struct zx_elem_s*)x->Nonce;
    if (!y) return;
    for (; y->g.n; y = (struct zx_elem_s*)y->g.n) ;
    break;
  default:
    for (y = x->Nonce; n > 1 && y->g.n; --n, y = (struct zx_elem_s*)y->g.n) ;
    if (!y->g.n) return;
  }
  y->g.n = y->g.n->n;
}

#endif

/* FUNC(zx_wsc_DerivedKeyToken_GET_Algorithm) */
struct zx_str* zx_wsc_DerivedKeyToken_GET_Algorithm(struct zx_wsc_DerivedKeyToken_s* x) { return x->Algorithm; }
/* FUNC(zx_wsc_DerivedKeyToken_PUT_Algorithm) */
void zx_wsc_DerivedKeyToken_PUT_Algorithm(struct zx_wsc_DerivedKeyToken_s* x, struct zx_str* y) { x->Algorithm = y; }
/* FUNC(zx_wsc_DerivedKeyToken_GET_Id) */
struct zx_str* zx_wsc_DerivedKeyToken_GET_Id(struct zx_wsc_DerivedKeyToken_s* x) { return x->Id; }
/* FUNC(zx_wsc_DerivedKeyToken_PUT_Id) */
void zx_wsc_DerivedKeyToken_PUT_Id(struct zx_wsc_DerivedKeyToken_s* x, struct zx_str* y) { x->Id = y; }










/* FUNC(zx_wsc_SecurityContextToken_GET_Id) */
struct zx_str* zx_wsc_SecurityContextToken_GET_Id(struct zx_wsc_SecurityContextToken_s* x) { return x->Id; }
/* FUNC(zx_wsc_SecurityContextToken_PUT_Id) */
void zx_wsc_SecurityContextToken_PUT_Id(struct zx_wsc_SecurityContextToken_s* x, struct zx_str* y) { x->Id = y; }





/* EOF -- c/zx-wsc-getput.c */
