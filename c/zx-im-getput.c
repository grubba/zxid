/* c/zx-im-getput.c - WARNING: This file was automatically generated. DO NOT EDIT!
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
#include "c/zx-im-data.h"



#ifdef ZX_ENA_GETPUT

/* FUNC(zx_im_IdentityMappingRequest_NUM_MappingInput) */

int zx_im_IdentityMappingRequest_NUM_MappingInput(struct zx_im_IdentityMappingRequest_s* x)
{
  struct zx_im_MappingInput_s* y;
  int n = 0;
  if (!x) return 0;
  for (y = x->MappingInput; y; ++n, y = (struct zx_im_MappingInput_s*)y->gg.g.n) ;
  return n;
}

/* FUNC(zx_im_IdentityMappingRequest_GET_MappingInput) */

struct zx_im_MappingInput_s* zx_im_IdentityMappingRequest_GET_MappingInput(struct zx_im_IdentityMappingRequest_s* x, int n)
{
  struct zx_im_MappingInput_s* y;
  if (!x) return 0;
  for (y = x->MappingInput; n>=0 && y; --n, y = (struct zx_im_MappingInput_s*)y->gg.g.n) ;
  return y;
}

/* FUNC(zx_im_IdentityMappingRequest_POP_MappingInput) */

struct zx_im_MappingInput_s* zx_im_IdentityMappingRequest_POP_MappingInput(struct zx_im_IdentityMappingRequest_s* x)
{
  struct zx_im_MappingInput_s* y;
  if (!x) return 0;
  y = x->MappingInput;
  if (y)
    x->MappingInput = (struct zx_im_MappingInput_s*)y->gg.g.n;
  return y;
}

/* FUNC(zx_im_IdentityMappingRequest_PUSH_MappingInput) */

void zx_im_IdentityMappingRequest_PUSH_MappingInput(struct zx_im_IdentityMappingRequest_s* x, struct zx_im_MappingInput_s* z)
{
  if (!x || !z) return;
  z->gg.g.n = &x->MappingInput->gg.g;
  x->MappingInput = z;
}

/* FUNC(zx_im_IdentityMappingRequest_REV_MappingInput) */

void zx_im_IdentityMappingRequest_REV_MappingInput(struct zx_im_IdentityMappingRequest_s* x)
{
  struct zx_im_MappingInput_s* nxt;
  struct zx_im_MappingInput_s* y;
  if (!x) return;
  y = x->MappingInput;
  if (!y) return;
  x->MappingInput = 0;
  while (y) {
    nxt = (struct zx_im_MappingInput_s*)y->gg.g.n;
    y->gg.g.n = &x->MappingInput->gg.g;
    x->MappingInput = y;
    y = nxt;
  }
}

/* FUNC(zx_im_IdentityMappingRequest_PUT_MappingInput) */

void zx_im_IdentityMappingRequest_PUT_MappingInput(struct zx_im_IdentityMappingRequest_s* x, int n, struct zx_im_MappingInput_s* z)
{
  struct zx_im_MappingInput_s* y;
  if (!x || !z) return;
  y = x->MappingInput;
  if (!y) return;
  switch (n) {
  case 0:
    z->gg.g.n = y->gg.g.n;
    x->MappingInput = z;
    return;
  default:
    for (; n > 1 && y->gg.g.n; --n, y = (struct zx_im_MappingInput_s*)y->gg.g.n) ;
    if (!y->gg.g.n) return;
    z->gg.g.n = y->gg.g.n->n;
    y->gg.g.n = &z->gg.g;
  }
}

/* FUNC(zx_im_IdentityMappingRequest_ADD_MappingInput) */

void zx_im_IdentityMappingRequest_ADD_MappingInput(struct zx_im_IdentityMappingRequest_s* x, int n, struct zx_im_MappingInput_s* z)
{
  struct zx_im_MappingInput_s* y;
  if (!x || !z) return;
  switch (n) {
  case 0:
  add_to_start:
    z->gg.g.n = &x->MappingInput->gg.g;
    x->MappingInput = z;
    return;
  case -1:
    y = x->MappingInput;
    if (!y) goto add_to_start;
    for (; y->gg.g.n; y = (struct zx_im_MappingInput_s*)y->gg.g.n) ;
    break;
  default:
    for (y = x->MappingInput; n > 1 && y; --n, y = (struct zx_im_MappingInput_s*)y->gg.g.n) ;
    if (!y) return;
  }
  z->gg.g.n = y->gg.g.n;
  y->gg.g.n = &z->gg.g;
}

/* FUNC(zx_im_IdentityMappingRequest_DEL_MappingInput) */

void zx_im_IdentityMappingRequest_DEL_MappingInput(struct zx_im_IdentityMappingRequest_s* x, int n)
{
  struct zx_im_MappingInput_s* y;
  if (!x) return;
  switch (n) {
  case 0:
    x->MappingInput = (struct zx_im_MappingInput_s*)x->MappingInput->gg.g.n;
    return;
  case -1:
    y = (struct zx_im_MappingInput_s*)x->MappingInput;
    if (!y) return;
    for (; y->gg.g.n; y = (struct zx_im_MappingInput_s*)y->gg.g.n) ;
    break;
  default:
    for (y = x->MappingInput; n > 1 && y->gg.g.n; --n, y = (struct zx_im_MappingInput_s*)y->gg.g.n) ;
    if (!y->gg.g.n) return;
  }
  y->gg.g.n = y->gg.g.n->n;
}

#endif








#ifdef ZX_ENA_GETPUT

/* FUNC(zx_im_IdentityMappingResponse_NUM_Status) */

int zx_im_IdentityMappingResponse_NUM_Status(struct zx_im_IdentityMappingResponse_s* x)
{
  struct zx_lu_Status_s* y;
  int n = 0;
  if (!x) return 0;
  for (y = x->Status; y; ++n, y = (struct zx_lu_Status_s*)y->gg.g.n) ;
  return n;
}

/* FUNC(zx_im_IdentityMappingResponse_GET_Status) */

struct zx_lu_Status_s* zx_im_IdentityMappingResponse_GET_Status(struct zx_im_IdentityMappingResponse_s* x, int n)
{
  struct zx_lu_Status_s* y;
  if (!x) return 0;
  for (y = x->Status; n>=0 && y; --n, y = (struct zx_lu_Status_s*)y->gg.g.n) ;
  return y;
}

/* FUNC(zx_im_IdentityMappingResponse_POP_Status) */

struct zx_lu_Status_s* zx_im_IdentityMappingResponse_POP_Status(struct zx_im_IdentityMappingResponse_s* x)
{
  struct zx_lu_Status_s* y;
  if (!x) return 0;
  y = x->Status;
  if (y)
    x->Status = (struct zx_lu_Status_s*)y->gg.g.n;
  return y;
}

/* FUNC(zx_im_IdentityMappingResponse_PUSH_Status) */

void zx_im_IdentityMappingResponse_PUSH_Status(struct zx_im_IdentityMappingResponse_s* x, struct zx_lu_Status_s* z)
{
  if (!x || !z) return;
  z->gg.g.n = &x->Status->gg.g;
  x->Status = z;
}

/* FUNC(zx_im_IdentityMappingResponse_REV_Status) */

void zx_im_IdentityMappingResponse_REV_Status(struct zx_im_IdentityMappingResponse_s* x)
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

/* FUNC(zx_im_IdentityMappingResponse_PUT_Status) */

void zx_im_IdentityMappingResponse_PUT_Status(struct zx_im_IdentityMappingResponse_s* x, int n, struct zx_lu_Status_s* z)
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

/* FUNC(zx_im_IdentityMappingResponse_ADD_Status) */

void zx_im_IdentityMappingResponse_ADD_Status(struct zx_im_IdentityMappingResponse_s* x, int n, struct zx_lu_Status_s* z)
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

/* FUNC(zx_im_IdentityMappingResponse_DEL_Status) */

void zx_im_IdentityMappingResponse_DEL_Status(struct zx_im_IdentityMappingResponse_s* x, int n)
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

/* FUNC(zx_im_IdentityMappingResponse_NUM_MappingOutput) */

int zx_im_IdentityMappingResponse_NUM_MappingOutput(struct zx_im_IdentityMappingResponse_s* x)
{
  struct zx_im_MappingOutput_s* y;
  int n = 0;
  if (!x) return 0;
  for (y = x->MappingOutput; y; ++n, y = (struct zx_im_MappingOutput_s*)y->gg.g.n) ;
  return n;
}

/* FUNC(zx_im_IdentityMappingResponse_GET_MappingOutput) */

struct zx_im_MappingOutput_s* zx_im_IdentityMappingResponse_GET_MappingOutput(struct zx_im_IdentityMappingResponse_s* x, int n)
{
  struct zx_im_MappingOutput_s* y;
  if (!x) return 0;
  for (y = x->MappingOutput; n>=0 && y; --n, y = (struct zx_im_MappingOutput_s*)y->gg.g.n) ;
  return y;
}

/* FUNC(zx_im_IdentityMappingResponse_POP_MappingOutput) */

struct zx_im_MappingOutput_s* zx_im_IdentityMappingResponse_POP_MappingOutput(struct zx_im_IdentityMappingResponse_s* x)
{
  struct zx_im_MappingOutput_s* y;
  if (!x) return 0;
  y = x->MappingOutput;
  if (y)
    x->MappingOutput = (struct zx_im_MappingOutput_s*)y->gg.g.n;
  return y;
}

/* FUNC(zx_im_IdentityMappingResponse_PUSH_MappingOutput) */

void zx_im_IdentityMappingResponse_PUSH_MappingOutput(struct zx_im_IdentityMappingResponse_s* x, struct zx_im_MappingOutput_s* z)
{
  if (!x || !z) return;
  z->gg.g.n = &x->MappingOutput->gg.g;
  x->MappingOutput = z;
}

/* FUNC(zx_im_IdentityMappingResponse_REV_MappingOutput) */

void zx_im_IdentityMappingResponse_REV_MappingOutput(struct zx_im_IdentityMappingResponse_s* x)
{
  struct zx_im_MappingOutput_s* nxt;
  struct zx_im_MappingOutput_s* y;
  if (!x) return;
  y = x->MappingOutput;
  if (!y) return;
  x->MappingOutput = 0;
  while (y) {
    nxt = (struct zx_im_MappingOutput_s*)y->gg.g.n;
    y->gg.g.n = &x->MappingOutput->gg.g;
    x->MappingOutput = y;
    y = nxt;
  }
}

/* FUNC(zx_im_IdentityMappingResponse_PUT_MappingOutput) */

void zx_im_IdentityMappingResponse_PUT_MappingOutput(struct zx_im_IdentityMappingResponse_s* x, int n, struct zx_im_MappingOutput_s* z)
{
  struct zx_im_MappingOutput_s* y;
  if (!x || !z) return;
  y = x->MappingOutput;
  if (!y) return;
  switch (n) {
  case 0:
    z->gg.g.n = y->gg.g.n;
    x->MappingOutput = z;
    return;
  default:
    for (; n > 1 && y->gg.g.n; --n, y = (struct zx_im_MappingOutput_s*)y->gg.g.n) ;
    if (!y->gg.g.n) return;
    z->gg.g.n = y->gg.g.n->n;
    y->gg.g.n = &z->gg.g;
  }
}

/* FUNC(zx_im_IdentityMappingResponse_ADD_MappingOutput) */

void zx_im_IdentityMappingResponse_ADD_MappingOutput(struct zx_im_IdentityMappingResponse_s* x, int n, struct zx_im_MappingOutput_s* z)
{
  struct zx_im_MappingOutput_s* y;
  if (!x || !z) return;
  switch (n) {
  case 0:
  add_to_start:
    z->gg.g.n = &x->MappingOutput->gg.g;
    x->MappingOutput = z;
    return;
  case -1:
    y = x->MappingOutput;
    if (!y) goto add_to_start;
    for (; y->gg.g.n; y = (struct zx_im_MappingOutput_s*)y->gg.g.n) ;
    break;
  default:
    for (y = x->MappingOutput; n > 1 && y; --n, y = (struct zx_im_MappingOutput_s*)y->gg.g.n) ;
    if (!y) return;
  }
  z->gg.g.n = y->gg.g.n;
  y->gg.g.n = &z->gg.g;
}

/* FUNC(zx_im_IdentityMappingResponse_DEL_MappingOutput) */

void zx_im_IdentityMappingResponse_DEL_MappingOutput(struct zx_im_IdentityMappingResponse_s* x, int n)
{
  struct zx_im_MappingOutput_s* y;
  if (!x) return;
  switch (n) {
  case 0:
    x->MappingOutput = (struct zx_im_MappingOutput_s*)x->MappingOutput->gg.g.n;
    return;
  case -1:
    y = (struct zx_im_MappingOutput_s*)x->MappingOutput;
    if (!y) return;
    for (; y->gg.g.n; y = (struct zx_im_MappingOutput_s*)y->gg.g.n) ;
    break;
  default:
    for (y = x->MappingOutput; n > 1 && y->gg.g.n; --n, y = (struct zx_im_MappingOutput_s*)y->gg.g.n) ;
    if (!y->gg.g.n) return;
  }
  y->gg.g.n = y->gg.g.n->n;
}

#endif








#ifdef ZX_ENA_GETPUT

/* FUNC(zx_im_MappingInput_NUM_TokenPolicy) */

int zx_im_MappingInput_NUM_TokenPolicy(struct zx_im_MappingInput_s* x)
{
  struct zx_sec_TokenPolicy_s* y;
  int n = 0;
  if (!x) return 0;
  for (y = x->TokenPolicy; y; ++n, y = (struct zx_sec_TokenPolicy_s*)y->gg.g.n) ;
  return n;
}

/* FUNC(zx_im_MappingInput_GET_TokenPolicy) */

struct zx_sec_TokenPolicy_s* zx_im_MappingInput_GET_TokenPolicy(struct zx_im_MappingInput_s* x, int n)
{
  struct zx_sec_TokenPolicy_s* y;
  if (!x) return 0;
  for (y = x->TokenPolicy; n>=0 && y; --n, y = (struct zx_sec_TokenPolicy_s*)y->gg.g.n) ;
  return y;
}

/* FUNC(zx_im_MappingInput_POP_TokenPolicy) */

struct zx_sec_TokenPolicy_s* zx_im_MappingInput_POP_TokenPolicy(struct zx_im_MappingInput_s* x)
{
  struct zx_sec_TokenPolicy_s* y;
  if (!x) return 0;
  y = x->TokenPolicy;
  if (y)
    x->TokenPolicy = (struct zx_sec_TokenPolicy_s*)y->gg.g.n;
  return y;
}

/* FUNC(zx_im_MappingInput_PUSH_TokenPolicy) */

void zx_im_MappingInput_PUSH_TokenPolicy(struct zx_im_MappingInput_s* x, struct zx_sec_TokenPolicy_s* z)
{
  if (!x || !z) return;
  z->gg.g.n = &x->TokenPolicy->gg.g;
  x->TokenPolicy = z;
}

/* FUNC(zx_im_MappingInput_REV_TokenPolicy) */

void zx_im_MappingInput_REV_TokenPolicy(struct zx_im_MappingInput_s* x)
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

/* FUNC(zx_im_MappingInput_PUT_TokenPolicy) */

void zx_im_MappingInput_PUT_TokenPolicy(struct zx_im_MappingInput_s* x, int n, struct zx_sec_TokenPolicy_s* z)
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

/* FUNC(zx_im_MappingInput_ADD_TokenPolicy) */

void zx_im_MappingInput_ADD_TokenPolicy(struct zx_im_MappingInput_s* x, int n, struct zx_sec_TokenPolicy_s* z)
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

/* FUNC(zx_im_MappingInput_DEL_TokenPolicy) */

void zx_im_MappingInput_DEL_TokenPolicy(struct zx_im_MappingInput_s* x, int n)
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

/* FUNC(zx_im_MappingInput_NUM_Token) */

int zx_im_MappingInput_NUM_Token(struct zx_im_MappingInput_s* x)
{
  struct zx_sec_Token_s* y;
  int n = 0;
  if (!x) return 0;
  for (y = x->Token; y; ++n, y = (struct zx_sec_Token_s*)y->gg.g.n) ;
  return n;
}

/* FUNC(zx_im_MappingInput_GET_Token) */

struct zx_sec_Token_s* zx_im_MappingInput_GET_Token(struct zx_im_MappingInput_s* x, int n)
{
  struct zx_sec_Token_s* y;
  if (!x) return 0;
  for (y = x->Token; n>=0 && y; --n, y = (struct zx_sec_Token_s*)y->gg.g.n) ;
  return y;
}

/* FUNC(zx_im_MappingInput_POP_Token) */

struct zx_sec_Token_s* zx_im_MappingInput_POP_Token(struct zx_im_MappingInput_s* x)
{
  struct zx_sec_Token_s* y;
  if (!x) return 0;
  y = x->Token;
  if (y)
    x->Token = (struct zx_sec_Token_s*)y->gg.g.n;
  return y;
}

/* FUNC(zx_im_MappingInput_PUSH_Token) */

void zx_im_MappingInput_PUSH_Token(struct zx_im_MappingInput_s* x, struct zx_sec_Token_s* z)
{
  if (!x || !z) return;
  z->gg.g.n = &x->Token->gg.g;
  x->Token = z;
}

/* FUNC(zx_im_MappingInput_REV_Token) */

void zx_im_MappingInput_REV_Token(struct zx_im_MappingInput_s* x)
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

/* FUNC(zx_im_MappingInput_PUT_Token) */

void zx_im_MappingInput_PUT_Token(struct zx_im_MappingInput_s* x, int n, struct zx_sec_Token_s* z)
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

/* FUNC(zx_im_MappingInput_ADD_Token) */

void zx_im_MappingInput_ADD_Token(struct zx_im_MappingInput_s* x, int n, struct zx_sec_Token_s* z)
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

/* FUNC(zx_im_MappingInput_DEL_Token) */

void zx_im_MappingInput_DEL_Token(struct zx_im_MappingInput_s* x, int n)
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

/* FUNC(zx_im_MappingInput_GET_reqID) */
struct zx_str* zx_im_MappingInput_GET_reqID(struct zx_im_MappingInput_s* x) { return x->reqID; }
/* FUNC(zx_im_MappingInput_PUT_reqID) */
void zx_im_MappingInput_PUT_reqID(struct zx_im_MappingInput_s* x, struct zx_str* y) { x->reqID = y; }







#ifdef ZX_ENA_GETPUT

/* FUNC(zx_im_MappingOutput_NUM_Token) */

int zx_im_MappingOutput_NUM_Token(struct zx_im_MappingOutput_s* x)
{
  struct zx_sec_Token_s* y;
  int n = 0;
  if (!x) return 0;
  for (y = x->Token; y; ++n, y = (struct zx_sec_Token_s*)y->gg.g.n) ;
  return n;
}

/* FUNC(zx_im_MappingOutput_GET_Token) */

struct zx_sec_Token_s* zx_im_MappingOutput_GET_Token(struct zx_im_MappingOutput_s* x, int n)
{
  struct zx_sec_Token_s* y;
  if (!x) return 0;
  for (y = x->Token; n>=0 && y; --n, y = (struct zx_sec_Token_s*)y->gg.g.n) ;
  return y;
}

/* FUNC(zx_im_MappingOutput_POP_Token) */

struct zx_sec_Token_s* zx_im_MappingOutput_POP_Token(struct zx_im_MappingOutput_s* x)
{
  struct zx_sec_Token_s* y;
  if (!x) return 0;
  y = x->Token;
  if (y)
    x->Token = (struct zx_sec_Token_s*)y->gg.g.n;
  return y;
}

/* FUNC(zx_im_MappingOutput_PUSH_Token) */

void zx_im_MappingOutput_PUSH_Token(struct zx_im_MappingOutput_s* x, struct zx_sec_Token_s* z)
{
  if (!x || !z) return;
  z->gg.g.n = &x->Token->gg.g;
  x->Token = z;
}

/* FUNC(zx_im_MappingOutput_REV_Token) */

void zx_im_MappingOutput_REV_Token(struct zx_im_MappingOutput_s* x)
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

/* FUNC(zx_im_MappingOutput_PUT_Token) */

void zx_im_MappingOutput_PUT_Token(struct zx_im_MappingOutput_s* x, int n, struct zx_sec_Token_s* z)
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

/* FUNC(zx_im_MappingOutput_ADD_Token) */

void zx_im_MappingOutput_ADD_Token(struct zx_im_MappingOutput_s* x, int n, struct zx_sec_Token_s* z)
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

/* FUNC(zx_im_MappingOutput_DEL_Token) */

void zx_im_MappingOutput_DEL_Token(struct zx_im_MappingOutput_s* x, int n)
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

/* FUNC(zx_im_MappingOutput_GET_reqRef) */
struct zx_str* zx_im_MappingOutput_GET_reqRef(struct zx_im_MappingOutput_s* x) { return x->reqRef; }
/* FUNC(zx_im_MappingOutput_PUT_reqRef) */
void zx_im_MappingOutput_PUT_reqRef(struct zx_im_MappingOutput_s* x, struct zx_str* y) { x->reqRef = y; }





/* EOF -- c/zx-im-getput.c */
