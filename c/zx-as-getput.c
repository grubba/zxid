/* c/zx-as-getput.c - WARNING: This file was automatically generated. DO NOT EDIT!
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
#include "c/zx-as-data.h"






/* FUNC(zx_as_Parameter_GET_name) */
struct zx_str* zx_as_Parameter_GET_name(struct zx_as_Parameter_s* x) { return x->name; }
/* FUNC(zx_as_Parameter_PUT_name) */
void zx_as_Parameter_PUT_name(struct zx_as_Parameter_s* x, struct zx_str* y) { x->name = y; }







#ifdef ZX_ENA_GETPUT

/* FUNC(zx_as_PasswordTransforms_NUM_Transform) */

int zx_as_PasswordTransforms_NUM_Transform(struct zx_as_PasswordTransforms_s* x)
{
  struct zx_as_Transform_s* y;
  int n = 0;
  if (!x) return 0;
  for (y = x->Transform; y; ++n, y = (struct zx_as_Transform_s*)y->gg.g.n) ;
  return n;
}

/* FUNC(zx_as_PasswordTransforms_GET_Transform) */

struct zx_as_Transform_s* zx_as_PasswordTransforms_GET_Transform(struct zx_as_PasswordTransforms_s* x, int n)
{
  struct zx_as_Transform_s* y;
  if (!x) return 0;
  for (y = x->Transform; n>=0 && y; --n, y = (struct zx_as_Transform_s*)y->gg.g.n) ;
  return y;
}

/* FUNC(zx_as_PasswordTransforms_POP_Transform) */

struct zx_as_Transform_s* zx_as_PasswordTransforms_POP_Transform(struct zx_as_PasswordTransforms_s* x)
{
  struct zx_as_Transform_s* y;
  if (!x) return 0;
  y = x->Transform;
  if (y)
    x->Transform = (struct zx_as_Transform_s*)y->gg.g.n;
  return y;
}

/* FUNC(zx_as_PasswordTransforms_PUSH_Transform) */

void zx_as_PasswordTransforms_PUSH_Transform(struct zx_as_PasswordTransforms_s* x, struct zx_as_Transform_s* z)
{
  if (!x || !z) return;
  z->gg.g.n = &x->Transform->gg.g;
  x->Transform = z;
}

/* FUNC(zx_as_PasswordTransforms_REV_Transform) */

void zx_as_PasswordTransforms_REV_Transform(struct zx_as_PasswordTransforms_s* x)
{
  struct zx_as_Transform_s* nxt;
  struct zx_as_Transform_s* y;
  if (!x) return;
  y = x->Transform;
  if (!y) return;
  x->Transform = 0;
  while (y) {
    nxt = (struct zx_as_Transform_s*)y->gg.g.n;
    y->gg.g.n = &x->Transform->gg.g;
    x->Transform = y;
    y = nxt;
  }
}

/* FUNC(zx_as_PasswordTransforms_PUT_Transform) */

void zx_as_PasswordTransforms_PUT_Transform(struct zx_as_PasswordTransforms_s* x, int n, struct zx_as_Transform_s* z)
{
  struct zx_as_Transform_s* y;
  if (!x || !z) return;
  y = x->Transform;
  if (!y) return;
  switch (n) {
  case 0:
    z->gg.g.n = y->gg.g.n;
    x->Transform = z;
    return;
  default:
    for (; n > 1 && y->gg.g.n; --n, y = (struct zx_as_Transform_s*)y->gg.g.n) ;
    if (!y->gg.g.n) return;
    z->gg.g.n = y->gg.g.n->n;
    y->gg.g.n = &z->gg.g;
  }
}

/* FUNC(zx_as_PasswordTransforms_ADD_Transform) */

void zx_as_PasswordTransforms_ADD_Transform(struct zx_as_PasswordTransforms_s* x, int n, struct zx_as_Transform_s* z)
{
  struct zx_as_Transform_s* y;
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
    for (; y->gg.g.n; y = (struct zx_as_Transform_s*)y->gg.g.n) ;
    break;
  default:
    for (y = x->Transform; n > 1 && y; --n, y = (struct zx_as_Transform_s*)y->gg.g.n) ;
    if (!y) return;
  }
  z->gg.g.n = y->gg.g.n;
  y->gg.g.n = &z->gg.g;
}

/* FUNC(zx_as_PasswordTransforms_DEL_Transform) */

void zx_as_PasswordTransforms_DEL_Transform(struct zx_as_PasswordTransforms_s* x, int n)
{
  struct zx_as_Transform_s* y;
  if (!x) return;
  switch (n) {
  case 0:
    x->Transform = (struct zx_as_Transform_s*)x->Transform->gg.g.n;
    return;
  case -1:
    y = (struct zx_as_Transform_s*)x->Transform;
    if (!y) return;
    for (; y->gg.g.n; y = (struct zx_as_Transform_s*)y->gg.g.n) ;
    break;
  default:
    for (y = x->Transform; n > 1 && y->gg.g.n; --n, y = (struct zx_as_Transform_s*)y->gg.g.n) ;
    if (!y->gg.g.n) return;
  }
  y->gg.g.n = y->gg.g.n->n;
}

#endif








#ifdef ZX_ENA_GETPUT

/* FUNC(zx_as_SASLRequest_NUM_Data) */

int zx_as_SASLRequest_NUM_Data(struct zx_as_SASLRequest_s* x)
{
  struct zx_elem_s* y;
  int n = 0;
  if (!x) return 0;
  for (y = x->Data; y; ++n, y = (struct zx_elem_s*)y->g.n) ;
  return n;
}

/* FUNC(zx_as_SASLRequest_GET_Data) */

struct zx_elem_s* zx_as_SASLRequest_GET_Data(struct zx_as_SASLRequest_s* x, int n)
{
  struct zx_elem_s* y;
  if (!x) return 0;
  for (y = x->Data; n>=0 && y; --n, y = (struct zx_elem_s*)y->g.n) ;
  return y;
}

/* FUNC(zx_as_SASLRequest_POP_Data) */

struct zx_elem_s* zx_as_SASLRequest_POP_Data(struct zx_as_SASLRequest_s* x)
{
  struct zx_elem_s* y;
  if (!x) return 0;
  y = x->Data;
  if (y)
    x->Data = (struct zx_elem_s*)y->g.n;
  return y;
}

/* FUNC(zx_as_SASLRequest_PUSH_Data) */

void zx_as_SASLRequest_PUSH_Data(struct zx_as_SASLRequest_s* x, struct zx_elem_s* z)
{
  if (!x || !z) return;
  z->g.n = &x->Data->g;
  x->Data = z;
}

/* FUNC(zx_as_SASLRequest_REV_Data) */

void zx_as_SASLRequest_REV_Data(struct zx_as_SASLRequest_s* x)
{
  struct zx_elem_s* nxt;
  struct zx_elem_s* y;
  if (!x) return;
  y = x->Data;
  if (!y) return;
  x->Data = 0;
  while (y) {
    nxt = (struct zx_elem_s*)y->g.n;
    y->g.n = &x->Data->g;
    x->Data = y;
    y = nxt;
  }
}

/* FUNC(zx_as_SASLRequest_PUT_Data) */

void zx_as_SASLRequest_PUT_Data(struct zx_as_SASLRequest_s* x, int n, struct zx_elem_s* z)
{
  struct zx_elem_s* y;
  if (!x || !z) return;
  y = x->Data;
  if (!y) return;
  switch (n) {
  case 0:
    z->g.n = y->g.n;
    x->Data = z;
    return;
  default:
    for (; n > 1 && y->g.n; --n, y = (struct zx_elem_s*)y->g.n) ;
    if (!y->g.n) return;
    z->g.n = y->g.n->n;
    y->g.n = &z->g;
  }
}

/* FUNC(zx_as_SASLRequest_ADD_Data) */

void zx_as_SASLRequest_ADD_Data(struct zx_as_SASLRequest_s* x, int n, struct zx_elem_s* z)
{
  struct zx_elem_s* y;
  if (!x || !z) return;
  switch (n) {
  case 0:
  add_to_start:
    z->g.n = &x->Data->g;
    x->Data = z;
    return;
  case -1:
    y = x->Data;
    if (!y) goto add_to_start;
    for (; y->g.n; y = (struct zx_elem_s*)y->g.n) ;
    break;
  default:
    for (y = x->Data; n > 1 && y; --n, y = (struct zx_elem_s*)y->g.n) ;
    if (!y) return;
  }
  z->g.n = y->g.n;
  y->g.n = &z->g;
}

/* FUNC(zx_as_SASLRequest_DEL_Data) */

void zx_as_SASLRequest_DEL_Data(struct zx_as_SASLRequest_s* x, int n)
{
  struct zx_elem_s* y;
  if (!x) return;
  switch (n) {
  case 0:
    x->Data = (struct zx_elem_s*)x->Data->g.n;
    return;
  case -1:
    y = (struct zx_elem_s*)x->Data;
    if (!y) return;
    for (; y->g.n; y = (struct zx_elem_s*)y->g.n) ;
    break;
  default:
    for (y = x->Data; n > 1 && y->g.n; --n, y = (struct zx_elem_s*)y->g.n) ;
    if (!y->g.n) return;
  }
  y->g.n = y->g.n->n;
}

#endif



#ifdef ZX_ENA_GETPUT

/* FUNC(zx_as_SASLRequest_NUM_RequestedAuthnContext) */

int zx_as_SASLRequest_NUM_RequestedAuthnContext(struct zx_as_SASLRequest_s* x)
{
  struct zx_sp_RequestedAuthnContext_s* y;
  int n = 0;
  if (!x) return 0;
  for (y = x->RequestedAuthnContext; y; ++n, y = (struct zx_sp_RequestedAuthnContext_s*)y->gg.g.n) ;
  return n;
}

/* FUNC(zx_as_SASLRequest_GET_RequestedAuthnContext) */

struct zx_sp_RequestedAuthnContext_s* zx_as_SASLRequest_GET_RequestedAuthnContext(struct zx_as_SASLRequest_s* x, int n)
{
  struct zx_sp_RequestedAuthnContext_s* y;
  if (!x) return 0;
  for (y = x->RequestedAuthnContext; n>=0 && y; --n, y = (struct zx_sp_RequestedAuthnContext_s*)y->gg.g.n) ;
  return y;
}

/* FUNC(zx_as_SASLRequest_POP_RequestedAuthnContext) */

struct zx_sp_RequestedAuthnContext_s* zx_as_SASLRequest_POP_RequestedAuthnContext(struct zx_as_SASLRequest_s* x)
{
  struct zx_sp_RequestedAuthnContext_s* y;
  if (!x) return 0;
  y = x->RequestedAuthnContext;
  if (y)
    x->RequestedAuthnContext = (struct zx_sp_RequestedAuthnContext_s*)y->gg.g.n;
  return y;
}

/* FUNC(zx_as_SASLRequest_PUSH_RequestedAuthnContext) */

void zx_as_SASLRequest_PUSH_RequestedAuthnContext(struct zx_as_SASLRequest_s* x, struct zx_sp_RequestedAuthnContext_s* z)
{
  if (!x || !z) return;
  z->gg.g.n = &x->RequestedAuthnContext->gg.g;
  x->RequestedAuthnContext = z;
}

/* FUNC(zx_as_SASLRequest_REV_RequestedAuthnContext) */

void zx_as_SASLRequest_REV_RequestedAuthnContext(struct zx_as_SASLRequest_s* x)
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

/* FUNC(zx_as_SASLRequest_PUT_RequestedAuthnContext) */

void zx_as_SASLRequest_PUT_RequestedAuthnContext(struct zx_as_SASLRequest_s* x, int n, struct zx_sp_RequestedAuthnContext_s* z)
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

/* FUNC(zx_as_SASLRequest_ADD_RequestedAuthnContext) */

void zx_as_SASLRequest_ADD_RequestedAuthnContext(struct zx_as_SASLRequest_s* x, int n, struct zx_sp_RequestedAuthnContext_s* z)
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

/* FUNC(zx_as_SASLRequest_DEL_RequestedAuthnContext) */

void zx_as_SASLRequest_DEL_RequestedAuthnContext(struct zx_as_SASLRequest_s* x, int n)
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

/* FUNC(zx_as_SASLRequest_NUM_Extensions) */

int zx_as_SASLRequest_NUM_Extensions(struct zx_as_SASLRequest_s* x)
{
  struct zx_as_Extensions_s* y;
  int n = 0;
  if (!x) return 0;
  for (y = x->Extensions; y; ++n, y = (struct zx_as_Extensions_s*)y->gg.g.n) ;
  return n;
}

/* FUNC(zx_as_SASLRequest_GET_Extensions) */

struct zx_as_Extensions_s* zx_as_SASLRequest_GET_Extensions(struct zx_as_SASLRequest_s* x, int n)
{
  struct zx_as_Extensions_s* y;
  if (!x) return 0;
  for (y = x->Extensions; n>=0 && y; --n, y = (struct zx_as_Extensions_s*)y->gg.g.n) ;
  return y;
}

/* FUNC(zx_as_SASLRequest_POP_Extensions) */

struct zx_as_Extensions_s* zx_as_SASLRequest_POP_Extensions(struct zx_as_SASLRequest_s* x)
{
  struct zx_as_Extensions_s* y;
  if (!x) return 0;
  y = x->Extensions;
  if (y)
    x->Extensions = (struct zx_as_Extensions_s*)y->gg.g.n;
  return y;
}

/* FUNC(zx_as_SASLRequest_PUSH_Extensions) */

void zx_as_SASLRequest_PUSH_Extensions(struct zx_as_SASLRequest_s* x, struct zx_as_Extensions_s* z)
{
  if (!x || !z) return;
  z->gg.g.n = &x->Extensions->gg.g;
  x->Extensions = z;
}

/* FUNC(zx_as_SASLRequest_REV_Extensions) */

void zx_as_SASLRequest_REV_Extensions(struct zx_as_SASLRequest_s* x)
{
  struct zx_as_Extensions_s* nxt;
  struct zx_as_Extensions_s* y;
  if (!x) return;
  y = x->Extensions;
  if (!y) return;
  x->Extensions = 0;
  while (y) {
    nxt = (struct zx_as_Extensions_s*)y->gg.g.n;
    y->gg.g.n = &x->Extensions->gg.g;
    x->Extensions = y;
    y = nxt;
  }
}

/* FUNC(zx_as_SASLRequest_PUT_Extensions) */

void zx_as_SASLRequest_PUT_Extensions(struct zx_as_SASLRequest_s* x, int n, struct zx_as_Extensions_s* z)
{
  struct zx_as_Extensions_s* y;
  if (!x || !z) return;
  y = x->Extensions;
  if (!y) return;
  switch (n) {
  case 0:
    z->gg.g.n = y->gg.g.n;
    x->Extensions = z;
    return;
  default:
    for (; n > 1 && y->gg.g.n; --n, y = (struct zx_as_Extensions_s*)y->gg.g.n) ;
    if (!y->gg.g.n) return;
    z->gg.g.n = y->gg.g.n->n;
    y->gg.g.n = &z->gg.g;
  }
}

/* FUNC(zx_as_SASLRequest_ADD_Extensions) */

void zx_as_SASLRequest_ADD_Extensions(struct zx_as_SASLRequest_s* x, int n, struct zx_as_Extensions_s* z)
{
  struct zx_as_Extensions_s* y;
  if (!x || !z) return;
  switch (n) {
  case 0:
  add_to_start:
    z->gg.g.n = &x->Extensions->gg.g;
    x->Extensions = z;
    return;
  case -1:
    y = x->Extensions;
    if (!y) goto add_to_start;
    for (; y->gg.g.n; y = (struct zx_as_Extensions_s*)y->gg.g.n) ;
    break;
  default:
    for (y = x->Extensions; n > 1 && y; --n, y = (struct zx_as_Extensions_s*)y->gg.g.n) ;
    if (!y) return;
  }
  z->gg.g.n = y->gg.g.n;
  y->gg.g.n = &z->gg.g;
}

/* FUNC(zx_as_SASLRequest_DEL_Extensions) */

void zx_as_SASLRequest_DEL_Extensions(struct zx_as_SASLRequest_s* x, int n)
{
  struct zx_as_Extensions_s* y;
  if (!x) return;
  switch (n) {
  case 0:
    x->Extensions = (struct zx_as_Extensions_s*)x->Extensions->gg.g.n;
    return;
  case -1:
    y = (struct zx_as_Extensions_s*)x->Extensions;
    if (!y) return;
    for (; y->gg.g.n; y = (struct zx_as_Extensions_s*)y->gg.g.n) ;
    break;
  default:
    for (y = x->Extensions; n > 1 && y->gg.g.n; --n, y = (struct zx_as_Extensions_s*)y->gg.g.n) ;
    if (!y->gg.g.n) return;
  }
  y->gg.g.n = y->gg.g.n->n;
}

#endif

/* FUNC(zx_as_SASLRequest_GET_advisoryAuthnID) */
struct zx_str* zx_as_SASLRequest_GET_advisoryAuthnID(struct zx_as_SASLRequest_s* x) { return x->advisoryAuthnID; }
/* FUNC(zx_as_SASLRequest_PUT_advisoryAuthnID) */
void zx_as_SASLRequest_PUT_advisoryAuthnID(struct zx_as_SASLRequest_s* x, struct zx_str* y) { x->advisoryAuthnID = y; }
/* FUNC(zx_as_SASLRequest_GET_authzID) */
struct zx_str* zx_as_SASLRequest_GET_authzID(struct zx_as_SASLRequest_s* x) { return x->authzID; }
/* FUNC(zx_as_SASLRequest_PUT_authzID) */
void zx_as_SASLRequest_PUT_authzID(struct zx_as_SASLRequest_s* x, struct zx_str* y) { x->authzID = y; }
/* FUNC(zx_as_SASLRequest_GET_mechanism) */
struct zx_str* zx_as_SASLRequest_GET_mechanism(struct zx_as_SASLRequest_s* x) { return x->mechanism; }
/* FUNC(zx_as_SASLRequest_PUT_mechanism) */
void zx_as_SASLRequest_PUT_mechanism(struct zx_as_SASLRequest_s* x, struct zx_str* y) { x->mechanism = y; }







#ifdef ZX_ENA_GETPUT

/* FUNC(zx_as_SASLResponse_NUM_Status) */

int zx_as_SASLResponse_NUM_Status(struct zx_as_SASLResponse_s* x)
{
  struct zx_lu_Status_s* y;
  int n = 0;
  if (!x) return 0;
  for (y = x->Status; y; ++n, y = (struct zx_lu_Status_s*)y->gg.g.n) ;
  return n;
}

/* FUNC(zx_as_SASLResponse_GET_Status) */

struct zx_lu_Status_s* zx_as_SASLResponse_GET_Status(struct zx_as_SASLResponse_s* x, int n)
{
  struct zx_lu_Status_s* y;
  if (!x) return 0;
  for (y = x->Status; n>=0 && y; --n, y = (struct zx_lu_Status_s*)y->gg.g.n) ;
  return y;
}

/* FUNC(zx_as_SASLResponse_POP_Status) */

struct zx_lu_Status_s* zx_as_SASLResponse_POP_Status(struct zx_as_SASLResponse_s* x)
{
  struct zx_lu_Status_s* y;
  if (!x) return 0;
  y = x->Status;
  if (y)
    x->Status = (struct zx_lu_Status_s*)y->gg.g.n;
  return y;
}

/* FUNC(zx_as_SASLResponse_PUSH_Status) */

void zx_as_SASLResponse_PUSH_Status(struct zx_as_SASLResponse_s* x, struct zx_lu_Status_s* z)
{
  if (!x || !z) return;
  z->gg.g.n = &x->Status->gg.g;
  x->Status = z;
}

/* FUNC(zx_as_SASLResponse_REV_Status) */

void zx_as_SASLResponse_REV_Status(struct zx_as_SASLResponse_s* x)
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

/* FUNC(zx_as_SASLResponse_PUT_Status) */

void zx_as_SASLResponse_PUT_Status(struct zx_as_SASLResponse_s* x, int n, struct zx_lu_Status_s* z)
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

/* FUNC(zx_as_SASLResponse_ADD_Status) */

void zx_as_SASLResponse_ADD_Status(struct zx_as_SASLResponse_s* x, int n, struct zx_lu_Status_s* z)
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

/* FUNC(zx_as_SASLResponse_DEL_Status) */

void zx_as_SASLResponse_DEL_Status(struct zx_as_SASLResponse_s* x, int n)
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

/* FUNC(zx_as_SASLResponse_NUM_PasswordTransforms) */

int zx_as_SASLResponse_NUM_PasswordTransforms(struct zx_as_SASLResponse_s* x)
{
  struct zx_as_PasswordTransforms_s* y;
  int n = 0;
  if (!x) return 0;
  for (y = x->PasswordTransforms; y; ++n, y = (struct zx_as_PasswordTransforms_s*)y->gg.g.n) ;
  return n;
}

/* FUNC(zx_as_SASLResponse_GET_PasswordTransforms) */

struct zx_as_PasswordTransforms_s* zx_as_SASLResponse_GET_PasswordTransforms(struct zx_as_SASLResponse_s* x, int n)
{
  struct zx_as_PasswordTransforms_s* y;
  if (!x) return 0;
  for (y = x->PasswordTransforms; n>=0 && y; --n, y = (struct zx_as_PasswordTransforms_s*)y->gg.g.n) ;
  return y;
}

/* FUNC(zx_as_SASLResponse_POP_PasswordTransforms) */

struct zx_as_PasswordTransforms_s* zx_as_SASLResponse_POP_PasswordTransforms(struct zx_as_SASLResponse_s* x)
{
  struct zx_as_PasswordTransforms_s* y;
  if (!x) return 0;
  y = x->PasswordTransforms;
  if (y)
    x->PasswordTransforms = (struct zx_as_PasswordTransforms_s*)y->gg.g.n;
  return y;
}

/* FUNC(zx_as_SASLResponse_PUSH_PasswordTransforms) */

void zx_as_SASLResponse_PUSH_PasswordTransforms(struct zx_as_SASLResponse_s* x, struct zx_as_PasswordTransforms_s* z)
{
  if (!x || !z) return;
  z->gg.g.n = &x->PasswordTransforms->gg.g;
  x->PasswordTransforms = z;
}

/* FUNC(zx_as_SASLResponse_REV_PasswordTransforms) */

void zx_as_SASLResponse_REV_PasswordTransforms(struct zx_as_SASLResponse_s* x)
{
  struct zx_as_PasswordTransforms_s* nxt;
  struct zx_as_PasswordTransforms_s* y;
  if (!x) return;
  y = x->PasswordTransforms;
  if (!y) return;
  x->PasswordTransforms = 0;
  while (y) {
    nxt = (struct zx_as_PasswordTransforms_s*)y->gg.g.n;
    y->gg.g.n = &x->PasswordTransforms->gg.g;
    x->PasswordTransforms = y;
    y = nxt;
  }
}

/* FUNC(zx_as_SASLResponse_PUT_PasswordTransforms) */

void zx_as_SASLResponse_PUT_PasswordTransforms(struct zx_as_SASLResponse_s* x, int n, struct zx_as_PasswordTransforms_s* z)
{
  struct zx_as_PasswordTransforms_s* y;
  if (!x || !z) return;
  y = x->PasswordTransforms;
  if (!y) return;
  switch (n) {
  case 0:
    z->gg.g.n = y->gg.g.n;
    x->PasswordTransforms = z;
    return;
  default:
    for (; n > 1 && y->gg.g.n; --n, y = (struct zx_as_PasswordTransforms_s*)y->gg.g.n) ;
    if (!y->gg.g.n) return;
    z->gg.g.n = y->gg.g.n->n;
    y->gg.g.n = &z->gg.g;
  }
}

/* FUNC(zx_as_SASLResponse_ADD_PasswordTransforms) */

void zx_as_SASLResponse_ADD_PasswordTransforms(struct zx_as_SASLResponse_s* x, int n, struct zx_as_PasswordTransforms_s* z)
{
  struct zx_as_PasswordTransforms_s* y;
  if (!x || !z) return;
  switch (n) {
  case 0:
  add_to_start:
    z->gg.g.n = &x->PasswordTransforms->gg.g;
    x->PasswordTransforms = z;
    return;
  case -1:
    y = x->PasswordTransforms;
    if (!y) goto add_to_start;
    for (; y->gg.g.n; y = (struct zx_as_PasswordTransforms_s*)y->gg.g.n) ;
    break;
  default:
    for (y = x->PasswordTransforms; n > 1 && y; --n, y = (struct zx_as_PasswordTransforms_s*)y->gg.g.n) ;
    if (!y) return;
  }
  z->gg.g.n = y->gg.g.n;
  y->gg.g.n = &z->gg.g;
}

/* FUNC(zx_as_SASLResponse_DEL_PasswordTransforms) */

void zx_as_SASLResponse_DEL_PasswordTransforms(struct zx_as_SASLResponse_s* x, int n)
{
  struct zx_as_PasswordTransforms_s* y;
  if (!x) return;
  switch (n) {
  case 0:
    x->PasswordTransforms = (struct zx_as_PasswordTransforms_s*)x->PasswordTransforms->gg.g.n;
    return;
  case -1:
    y = (struct zx_as_PasswordTransforms_s*)x->PasswordTransforms;
    if (!y) return;
    for (; y->gg.g.n; y = (struct zx_as_PasswordTransforms_s*)y->gg.g.n) ;
    break;
  default:
    for (y = x->PasswordTransforms; n > 1 && y->gg.g.n; --n, y = (struct zx_as_PasswordTransforms_s*)y->gg.g.n) ;
    if (!y->gg.g.n) return;
  }
  y->gg.g.n = y->gg.g.n->n;
}

#endif



#ifdef ZX_ENA_GETPUT

/* FUNC(zx_as_SASLResponse_NUM_Data) */

int zx_as_SASLResponse_NUM_Data(struct zx_as_SASLResponse_s* x)
{
  struct zx_elem_s* y;
  int n = 0;
  if (!x) return 0;
  for (y = x->Data; y; ++n, y = (struct zx_elem_s*)y->g.n) ;
  return n;
}

/* FUNC(zx_as_SASLResponse_GET_Data) */

struct zx_elem_s* zx_as_SASLResponse_GET_Data(struct zx_as_SASLResponse_s* x, int n)
{
  struct zx_elem_s* y;
  if (!x) return 0;
  for (y = x->Data; n>=0 && y; --n, y = (struct zx_elem_s*)y->g.n) ;
  return y;
}

/* FUNC(zx_as_SASLResponse_POP_Data) */

struct zx_elem_s* zx_as_SASLResponse_POP_Data(struct zx_as_SASLResponse_s* x)
{
  struct zx_elem_s* y;
  if (!x) return 0;
  y = x->Data;
  if (y)
    x->Data = (struct zx_elem_s*)y->g.n;
  return y;
}

/* FUNC(zx_as_SASLResponse_PUSH_Data) */

void zx_as_SASLResponse_PUSH_Data(struct zx_as_SASLResponse_s* x, struct zx_elem_s* z)
{
  if (!x || !z) return;
  z->g.n = &x->Data->g;
  x->Data = z;
}

/* FUNC(zx_as_SASLResponse_REV_Data) */

void zx_as_SASLResponse_REV_Data(struct zx_as_SASLResponse_s* x)
{
  struct zx_elem_s* nxt;
  struct zx_elem_s* y;
  if (!x) return;
  y = x->Data;
  if (!y) return;
  x->Data = 0;
  while (y) {
    nxt = (struct zx_elem_s*)y->g.n;
    y->g.n = &x->Data->g;
    x->Data = y;
    y = nxt;
  }
}

/* FUNC(zx_as_SASLResponse_PUT_Data) */

void zx_as_SASLResponse_PUT_Data(struct zx_as_SASLResponse_s* x, int n, struct zx_elem_s* z)
{
  struct zx_elem_s* y;
  if (!x || !z) return;
  y = x->Data;
  if (!y) return;
  switch (n) {
  case 0:
    z->g.n = y->g.n;
    x->Data = z;
    return;
  default:
    for (; n > 1 && y->g.n; --n, y = (struct zx_elem_s*)y->g.n) ;
    if (!y->g.n) return;
    z->g.n = y->g.n->n;
    y->g.n = &z->g;
  }
}

/* FUNC(zx_as_SASLResponse_ADD_Data) */

void zx_as_SASLResponse_ADD_Data(struct zx_as_SASLResponse_s* x, int n, struct zx_elem_s* z)
{
  struct zx_elem_s* y;
  if (!x || !z) return;
  switch (n) {
  case 0:
  add_to_start:
    z->g.n = &x->Data->g;
    x->Data = z;
    return;
  case -1:
    y = x->Data;
    if (!y) goto add_to_start;
    for (; y->g.n; y = (struct zx_elem_s*)y->g.n) ;
    break;
  default:
    for (y = x->Data; n > 1 && y; --n, y = (struct zx_elem_s*)y->g.n) ;
    if (!y) return;
  }
  z->g.n = y->g.n;
  y->g.n = &z->g;
}

/* FUNC(zx_as_SASLResponse_DEL_Data) */

void zx_as_SASLResponse_DEL_Data(struct zx_as_SASLResponse_s* x, int n)
{
  struct zx_elem_s* y;
  if (!x) return;
  switch (n) {
  case 0:
    x->Data = (struct zx_elem_s*)x->Data->g.n;
    return;
  case -1:
    y = (struct zx_elem_s*)x->Data;
    if (!y) return;
    for (; y->g.n; y = (struct zx_elem_s*)y->g.n) ;
    break;
  default:
    for (y = x->Data; n > 1 && y->g.n; --n, y = (struct zx_elem_s*)y->g.n) ;
    if (!y->g.n) return;
  }
  y->g.n = y->g.n->n;
}

#endif



#ifdef ZX_ENA_GETPUT

/* FUNC(zx_as_SASLResponse_NUM_EndpointReference) */

int zx_as_SASLResponse_NUM_EndpointReference(struct zx_as_SASLResponse_s* x)
{
  struct zx_a_EndpointReference_s* y;
  int n = 0;
  if (!x) return 0;
  for (y = x->EndpointReference; y; ++n, y = (struct zx_a_EndpointReference_s*)y->gg.g.n) ;
  return n;
}

/* FUNC(zx_as_SASLResponse_GET_EndpointReference) */

struct zx_a_EndpointReference_s* zx_as_SASLResponse_GET_EndpointReference(struct zx_as_SASLResponse_s* x, int n)
{
  struct zx_a_EndpointReference_s* y;
  if (!x) return 0;
  for (y = x->EndpointReference; n>=0 && y; --n, y = (struct zx_a_EndpointReference_s*)y->gg.g.n) ;
  return y;
}

/* FUNC(zx_as_SASLResponse_POP_EndpointReference) */

struct zx_a_EndpointReference_s* zx_as_SASLResponse_POP_EndpointReference(struct zx_as_SASLResponse_s* x)
{
  struct zx_a_EndpointReference_s* y;
  if (!x) return 0;
  y = x->EndpointReference;
  if (y)
    x->EndpointReference = (struct zx_a_EndpointReference_s*)y->gg.g.n;
  return y;
}

/* FUNC(zx_as_SASLResponse_PUSH_EndpointReference) */

void zx_as_SASLResponse_PUSH_EndpointReference(struct zx_as_SASLResponse_s* x, struct zx_a_EndpointReference_s* z)
{
  if (!x || !z) return;
  z->gg.g.n = &x->EndpointReference->gg.g;
  x->EndpointReference = z;
}

/* FUNC(zx_as_SASLResponse_REV_EndpointReference) */

void zx_as_SASLResponse_REV_EndpointReference(struct zx_as_SASLResponse_s* x)
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

/* FUNC(zx_as_SASLResponse_PUT_EndpointReference) */

void zx_as_SASLResponse_PUT_EndpointReference(struct zx_as_SASLResponse_s* x, int n, struct zx_a_EndpointReference_s* z)
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

/* FUNC(zx_as_SASLResponse_ADD_EndpointReference) */

void zx_as_SASLResponse_ADD_EndpointReference(struct zx_as_SASLResponse_s* x, int n, struct zx_a_EndpointReference_s* z)
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

/* FUNC(zx_as_SASLResponse_DEL_EndpointReference) */

void zx_as_SASLResponse_DEL_EndpointReference(struct zx_as_SASLResponse_s* x, int n)
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

/* FUNC(zx_as_SASLResponse_GET_serverMechanism) */
struct zx_str* zx_as_SASLResponse_GET_serverMechanism(struct zx_as_SASLResponse_s* x) { return x->serverMechanism; }
/* FUNC(zx_as_SASLResponse_PUT_serverMechanism) */
void zx_as_SASLResponse_PUT_serverMechanism(struct zx_as_SASLResponse_s* x, struct zx_str* y) { x->serverMechanism = y; }







#ifdef ZX_ENA_GETPUT

/* FUNC(zx_as_Transform_NUM_Parameter) */

int zx_as_Transform_NUM_Parameter(struct zx_as_Transform_s* x)
{
  struct zx_as_Parameter_s* y;
  int n = 0;
  if (!x) return 0;
  for (y = x->Parameter; y; ++n, y = (struct zx_as_Parameter_s*)y->gg.g.n) ;
  return n;
}

/* FUNC(zx_as_Transform_GET_Parameter) */

struct zx_as_Parameter_s* zx_as_Transform_GET_Parameter(struct zx_as_Transform_s* x, int n)
{
  struct zx_as_Parameter_s* y;
  if (!x) return 0;
  for (y = x->Parameter; n>=0 && y; --n, y = (struct zx_as_Parameter_s*)y->gg.g.n) ;
  return y;
}

/* FUNC(zx_as_Transform_POP_Parameter) */

struct zx_as_Parameter_s* zx_as_Transform_POP_Parameter(struct zx_as_Transform_s* x)
{
  struct zx_as_Parameter_s* y;
  if (!x) return 0;
  y = x->Parameter;
  if (y)
    x->Parameter = (struct zx_as_Parameter_s*)y->gg.g.n;
  return y;
}

/* FUNC(zx_as_Transform_PUSH_Parameter) */

void zx_as_Transform_PUSH_Parameter(struct zx_as_Transform_s* x, struct zx_as_Parameter_s* z)
{
  if (!x || !z) return;
  z->gg.g.n = &x->Parameter->gg.g;
  x->Parameter = z;
}

/* FUNC(zx_as_Transform_REV_Parameter) */

void zx_as_Transform_REV_Parameter(struct zx_as_Transform_s* x)
{
  struct zx_as_Parameter_s* nxt;
  struct zx_as_Parameter_s* y;
  if (!x) return;
  y = x->Parameter;
  if (!y) return;
  x->Parameter = 0;
  while (y) {
    nxt = (struct zx_as_Parameter_s*)y->gg.g.n;
    y->gg.g.n = &x->Parameter->gg.g;
    x->Parameter = y;
    y = nxt;
  }
}

/* FUNC(zx_as_Transform_PUT_Parameter) */

void zx_as_Transform_PUT_Parameter(struct zx_as_Transform_s* x, int n, struct zx_as_Parameter_s* z)
{
  struct zx_as_Parameter_s* y;
  if (!x || !z) return;
  y = x->Parameter;
  if (!y) return;
  switch (n) {
  case 0:
    z->gg.g.n = y->gg.g.n;
    x->Parameter = z;
    return;
  default:
    for (; n > 1 && y->gg.g.n; --n, y = (struct zx_as_Parameter_s*)y->gg.g.n) ;
    if (!y->gg.g.n) return;
    z->gg.g.n = y->gg.g.n->n;
    y->gg.g.n = &z->gg.g;
  }
}

/* FUNC(zx_as_Transform_ADD_Parameter) */

void zx_as_Transform_ADD_Parameter(struct zx_as_Transform_s* x, int n, struct zx_as_Parameter_s* z)
{
  struct zx_as_Parameter_s* y;
  if (!x || !z) return;
  switch (n) {
  case 0:
  add_to_start:
    z->gg.g.n = &x->Parameter->gg.g;
    x->Parameter = z;
    return;
  case -1:
    y = x->Parameter;
    if (!y) goto add_to_start;
    for (; y->gg.g.n; y = (struct zx_as_Parameter_s*)y->gg.g.n) ;
    break;
  default:
    for (y = x->Parameter; n > 1 && y; --n, y = (struct zx_as_Parameter_s*)y->gg.g.n) ;
    if (!y) return;
  }
  z->gg.g.n = y->gg.g.n;
  y->gg.g.n = &z->gg.g;
}

/* FUNC(zx_as_Transform_DEL_Parameter) */

void zx_as_Transform_DEL_Parameter(struct zx_as_Transform_s* x, int n)
{
  struct zx_as_Parameter_s* y;
  if (!x) return;
  switch (n) {
  case 0:
    x->Parameter = (struct zx_as_Parameter_s*)x->Parameter->gg.g.n;
    return;
  case -1:
    y = (struct zx_as_Parameter_s*)x->Parameter;
    if (!y) return;
    for (; y->gg.g.n; y = (struct zx_as_Parameter_s*)y->gg.g.n) ;
    break;
  default:
    for (y = x->Parameter; n > 1 && y->gg.g.n; --n, y = (struct zx_as_Parameter_s*)y->gg.g.n) ;
    if (!y->gg.g.n) return;
  }
  y->gg.g.n = y->gg.g.n->n;
}

#endif

/* FUNC(zx_as_Transform_GET_name) */
struct zx_str* zx_as_Transform_GET_name(struct zx_as_Transform_s* x) { return x->name; }
/* FUNC(zx_as_Transform_PUT_name) */
void zx_as_Transform_PUT_name(struct zx_as_Transform_s* x, struct zx_str* y) { x->name = y; }





/* EOF -- c/zx-as-getput.c */
