/* c/zx-xaspcd1-getput.c - WARNING: This file was automatically generated. DO NOT EDIT!
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
#include "c/zx-xaspcd1-data.h"



#ifdef ZX_ENA_GETPUT

/* FUNC(zx_xaspcd1_XACMLAuthzDecisionQuery_NUM_Issuer) */

int zx_xaspcd1_XACMLAuthzDecisionQuery_NUM_Issuer(struct zx_xaspcd1_XACMLAuthzDecisionQuery_s* x)
{
  struct zx_sa_Issuer_s* y;
  int n = 0;
  if (!x) return 0;
  for (y = x->Issuer; y; ++n, y = (struct zx_sa_Issuer_s*)y->gg.g.n) ;
  return n;
}

/* FUNC(zx_xaspcd1_XACMLAuthzDecisionQuery_GET_Issuer) */

struct zx_sa_Issuer_s* zx_xaspcd1_XACMLAuthzDecisionQuery_GET_Issuer(struct zx_xaspcd1_XACMLAuthzDecisionQuery_s* x, int n)
{
  struct zx_sa_Issuer_s* y;
  if (!x) return 0;
  for (y = x->Issuer; n>=0 && y; --n, y = (struct zx_sa_Issuer_s*)y->gg.g.n) ;
  return y;
}

/* FUNC(zx_xaspcd1_XACMLAuthzDecisionQuery_POP_Issuer) */

struct zx_sa_Issuer_s* zx_xaspcd1_XACMLAuthzDecisionQuery_POP_Issuer(struct zx_xaspcd1_XACMLAuthzDecisionQuery_s* x)
{
  struct zx_sa_Issuer_s* y;
  if (!x) return 0;
  y = x->Issuer;
  if (y)
    x->Issuer = (struct zx_sa_Issuer_s*)y->gg.g.n;
  return y;
}

/* FUNC(zx_xaspcd1_XACMLAuthzDecisionQuery_PUSH_Issuer) */

void zx_xaspcd1_XACMLAuthzDecisionQuery_PUSH_Issuer(struct zx_xaspcd1_XACMLAuthzDecisionQuery_s* x, struct zx_sa_Issuer_s* z)
{
  if (!x || !z) return;
  z->gg.g.n = &x->Issuer->gg.g;
  x->Issuer = z;
}

/* FUNC(zx_xaspcd1_XACMLAuthzDecisionQuery_REV_Issuer) */

void zx_xaspcd1_XACMLAuthzDecisionQuery_REV_Issuer(struct zx_xaspcd1_XACMLAuthzDecisionQuery_s* x)
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

/* FUNC(zx_xaspcd1_XACMLAuthzDecisionQuery_PUT_Issuer) */

void zx_xaspcd1_XACMLAuthzDecisionQuery_PUT_Issuer(struct zx_xaspcd1_XACMLAuthzDecisionQuery_s* x, int n, struct zx_sa_Issuer_s* z)
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

/* FUNC(zx_xaspcd1_XACMLAuthzDecisionQuery_ADD_Issuer) */

void zx_xaspcd1_XACMLAuthzDecisionQuery_ADD_Issuer(struct zx_xaspcd1_XACMLAuthzDecisionQuery_s* x, int n, struct zx_sa_Issuer_s* z)
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

/* FUNC(zx_xaspcd1_XACMLAuthzDecisionQuery_DEL_Issuer) */

void zx_xaspcd1_XACMLAuthzDecisionQuery_DEL_Issuer(struct zx_xaspcd1_XACMLAuthzDecisionQuery_s* x, int n)
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

/* FUNC(zx_xaspcd1_XACMLAuthzDecisionQuery_NUM_Signature) */

int zx_xaspcd1_XACMLAuthzDecisionQuery_NUM_Signature(struct zx_xaspcd1_XACMLAuthzDecisionQuery_s* x)
{
  struct zx_ds_Signature_s* y;
  int n = 0;
  if (!x) return 0;
  for (y = x->Signature; y; ++n, y = (struct zx_ds_Signature_s*)y->gg.g.n) ;
  return n;
}

/* FUNC(zx_xaspcd1_XACMLAuthzDecisionQuery_GET_Signature) */

struct zx_ds_Signature_s* zx_xaspcd1_XACMLAuthzDecisionQuery_GET_Signature(struct zx_xaspcd1_XACMLAuthzDecisionQuery_s* x, int n)
{
  struct zx_ds_Signature_s* y;
  if (!x) return 0;
  for (y = x->Signature; n>=0 && y; --n, y = (struct zx_ds_Signature_s*)y->gg.g.n) ;
  return y;
}

/* FUNC(zx_xaspcd1_XACMLAuthzDecisionQuery_POP_Signature) */

struct zx_ds_Signature_s* zx_xaspcd1_XACMLAuthzDecisionQuery_POP_Signature(struct zx_xaspcd1_XACMLAuthzDecisionQuery_s* x)
{
  struct zx_ds_Signature_s* y;
  if (!x) return 0;
  y = x->Signature;
  if (y)
    x->Signature = (struct zx_ds_Signature_s*)y->gg.g.n;
  return y;
}

/* FUNC(zx_xaspcd1_XACMLAuthzDecisionQuery_PUSH_Signature) */

void zx_xaspcd1_XACMLAuthzDecisionQuery_PUSH_Signature(struct zx_xaspcd1_XACMLAuthzDecisionQuery_s* x, struct zx_ds_Signature_s* z)
{
  if (!x || !z) return;
  z->gg.g.n = &x->Signature->gg.g;
  x->Signature = z;
}

/* FUNC(zx_xaspcd1_XACMLAuthzDecisionQuery_REV_Signature) */

void zx_xaspcd1_XACMLAuthzDecisionQuery_REV_Signature(struct zx_xaspcd1_XACMLAuthzDecisionQuery_s* x)
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

/* FUNC(zx_xaspcd1_XACMLAuthzDecisionQuery_PUT_Signature) */

void zx_xaspcd1_XACMLAuthzDecisionQuery_PUT_Signature(struct zx_xaspcd1_XACMLAuthzDecisionQuery_s* x, int n, struct zx_ds_Signature_s* z)
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

/* FUNC(zx_xaspcd1_XACMLAuthzDecisionQuery_ADD_Signature) */

void zx_xaspcd1_XACMLAuthzDecisionQuery_ADD_Signature(struct zx_xaspcd1_XACMLAuthzDecisionQuery_s* x, int n, struct zx_ds_Signature_s* z)
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

/* FUNC(zx_xaspcd1_XACMLAuthzDecisionQuery_DEL_Signature) */

void zx_xaspcd1_XACMLAuthzDecisionQuery_DEL_Signature(struct zx_xaspcd1_XACMLAuthzDecisionQuery_s* x, int n)
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

/* FUNC(zx_xaspcd1_XACMLAuthzDecisionQuery_NUM_Extensions) */

int zx_xaspcd1_XACMLAuthzDecisionQuery_NUM_Extensions(struct zx_xaspcd1_XACMLAuthzDecisionQuery_s* x)
{
  struct zx_sp_Extensions_s* y;
  int n = 0;
  if (!x) return 0;
  for (y = x->Extensions; y; ++n, y = (struct zx_sp_Extensions_s*)y->gg.g.n) ;
  return n;
}

/* FUNC(zx_xaspcd1_XACMLAuthzDecisionQuery_GET_Extensions) */

struct zx_sp_Extensions_s* zx_xaspcd1_XACMLAuthzDecisionQuery_GET_Extensions(struct zx_xaspcd1_XACMLAuthzDecisionQuery_s* x, int n)
{
  struct zx_sp_Extensions_s* y;
  if (!x) return 0;
  for (y = x->Extensions; n>=0 && y; --n, y = (struct zx_sp_Extensions_s*)y->gg.g.n) ;
  return y;
}

/* FUNC(zx_xaspcd1_XACMLAuthzDecisionQuery_POP_Extensions) */

struct zx_sp_Extensions_s* zx_xaspcd1_XACMLAuthzDecisionQuery_POP_Extensions(struct zx_xaspcd1_XACMLAuthzDecisionQuery_s* x)
{
  struct zx_sp_Extensions_s* y;
  if (!x) return 0;
  y = x->Extensions;
  if (y)
    x->Extensions = (struct zx_sp_Extensions_s*)y->gg.g.n;
  return y;
}

/* FUNC(zx_xaspcd1_XACMLAuthzDecisionQuery_PUSH_Extensions) */

void zx_xaspcd1_XACMLAuthzDecisionQuery_PUSH_Extensions(struct zx_xaspcd1_XACMLAuthzDecisionQuery_s* x, struct zx_sp_Extensions_s* z)
{
  if (!x || !z) return;
  z->gg.g.n = &x->Extensions->gg.g;
  x->Extensions = z;
}

/* FUNC(zx_xaspcd1_XACMLAuthzDecisionQuery_REV_Extensions) */

void zx_xaspcd1_XACMLAuthzDecisionQuery_REV_Extensions(struct zx_xaspcd1_XACMLAuthzDecisionQuery_s* x)
{
  struct zx_sp_Extensions_s* nxt;
  struct zx_sp_Extensions_s* y;
  if (!x) return;
  y = x->Extensions;
  if (!y) return;
  x->Extensions = 0;
  while (y) {
    nxt = (struct zx_sp_Extensions_s*)y->gg.g.n;
    y->gg.g.n = &x->Extensions->gg.g;
    x->Extensions = y;
    y = nxt;
  }
}

/* FUNC(zx_xaspcd1_XACMLAuthzDecisionQuery_PUT_Extensions) */

void zx_xaspcd1_XACMLAuthzDecisionQuery_PUT_Extensions(struct zx_xaspcd1_XACMLAuthzDecisionQuery_s* x, int n, struct zx_sp_Extensions_s* z)
{
  struct zx_sp_Extensions_s* y;
  if (!x || !z) return;
  y = x->Extensions;
  if (!y) return;
  switch (n) {
  case 0:
    z->gg.g.n = y->gg.g.n;
    x->Extensions = z;
    return;
  default:
    for (; n > 1 && y->gg.g.n; --n, y = (struct zx_sp_Extensions_s*)y->gg.g.n) ;
    if (!y->gg.g.n) return;
    z->gg.g.n = y->gg.g.n->n;
    y->gg.g.n = &z->gg.g;
  }
}

/* FUNC(zx_xaspcd1_XACMLAuthzDecisionQuery_ADD_Extensions) */

void zx_xaspcd1_XACMLAuthzDecisionQuery_ADD_Extensions(struct zx_xaspcd1_XACMLAuthzDecisionQuery_s* x, int n, struct zx_sp_Extensions_s* z)
{
  struct zx_sp_Extensions_s* y;
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
    for (; y->gg.g.n; y = (struct zx_sp_Extensions_s*)y->gg.g.n) ;
    break;
  default:
    for (y = x->Extensions; n > 1 && y; --n, y = (struct zx_sp_Extensions_s*)y->gg.g.n) ;
    if (!y) return;
  }
  z->gg.g.n = y->gg.g.n;
  y->gg.g.n = &z->gg.g;
}

/* FUNC(zx_xaspcd1_XACMLAuthzDecisionQuery_DEL_Extensions) */

void zx_xaspcd1_XACMLAuthzDecisionQuery_DEL_Extensions(struct zx_xaspcd1_XACMLAuthzDecisionQuery_s* x, int n)
{
  struct zx_sp_Extensions_s* y;
  if (!x) return;
  switch (n) {
  case 0:
    x->Extensions = (struct zx_sp_Extensions_s*)x->Extensions->gg.g.n;
    return;
  case -1:
    y = (struct zx_sp_Extensions_s*)x->Extensions;
    if (!y) return;
    for (; y->gg.g.n; y = (struct zx_sp_Extensions_s*)y->gg.g.n) ;
    break;
  default:
    for (y = x->Extensions; n > 1 && y->gg.g.n; --n, y = (struct zx_sp_Extensions_s*)y->gg.g.n) ;
    if (!y->gg.g.n) return;
  }
  y->gg.g.n = y->gg.g.n->n;
}

#endif



#ifdef ZX_ENA_GETPUT

/* FUNC(zx_xaspcd1_XACMLAuthzDecisionQuery_NUM_Request) */

int zx_xaspcd1_XACMLAuthzDecisionQuery_NUM_Request(struct zx_xaspcd1_XACMLAuthzDecisionQuery_s* x)
{
  struct zx_xac_Request_s* y;
  int n = 0;
  if (!x) return 0;
  for (y = x->Request; y; ++n, y = (struct zx_xac_Request_s*)y->gg.g.n) ;
  return n;
}

/* FUNC(zx_xaspcd1_XACMLAuthzDecisionQuery_GET_Request) */

struct zx_xac_Request_s* zx_xaspcd1_XACMLAuthzDecisionQuery_GET_Request(struct zx_xaspcd1_XACMLAuthzDecisionQuery_s* x, int n)
{
  struct zx_xac_Request_s* y;
  if (!x) return 0;
  for (y = x->Request; n>=0 && y; --n, y = (struct zx_xac_Request_s*)y->gg.g.n) ;
  return y;
}

/* FUNC(zx_xaspcd1_XACMLAuthzDecisionQuery_POP_Request) */

struct zx_xac_Request_s* zx_xaspcd1_XACMLAuthzDecisionQuery_POP_Request(struct zx_xaspcd1_XACMLAuthzDecisionQuery_s* x)
{
  struct zx_xac_Request_s* y;
  if (!x) return 0;
  y = x->Request;
  if (y)
    x->Request = (struct zx_xac_Request_s*)y->gg.g.n;
  return y;
}

/* FUNC(zx_xaspcd1_XACMLAuthzDecisionQuery_PUSH_Request) */

void zx_xaspcd1_XACMLAuthzDecisionQuery_PUSH_Request(struct zx_xaspcd1_XACMLAuthzDecisionQuery_s* x, struct zx_xac_Request_s* z)
{
  if (!x || !z) return;
  z->gg.g.n = &x->Request->gg.g;
  x->Request = z;
}

/* FUNC(zx_xaspcd1_XACMLAuthzDecisionQuery_REV_Request) */

void zx_xaspcd1_XACMLAuthzDecisionQuery_REV_Request(struct zx_xaspcd1_XACMLAuthzDecisionQuery_s* x)
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

/* FUNC(zx_xaspcd1_XACMLAuthzDecisionQuery_PUT_Request) */

void zx_xaspcd1_XACMLAuthzDecisionQuery_PUT_Request(struct zx_xaspcd1_XACMLAuthzDecisionQuery_s* x, int n, struct zx_xac_Request_s* z)
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

/* FUNC(zx_xaspcd1_XACMLAuthzDecisionQuery_ADD_Request) */

void zx_xaspcd1_XACMLAuthzDecisionQuery_ADD_Request(struct zx_xaspcd1_XACMLAuthzDecisionQuery_s* x, int n, struct zx_xac_Request_s* z)
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

/* FUNC(zx_xaspcd1_XACMLAuthzDecisionQuery_DEL_Request) */

void zx_xaspcd1_XACMLAuthzDecisionQuery_DEL_Request(struct zx_xaspcd1_XACMLAuthzDecisionQuery_s* x, int n)
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



#ifdef ZX_ENA_GETPUT

/* FUNC(zx_xaspcd1_XACMLAuthzDecisionQuery_NUM_Policy) */

int zx_xaspcd1_XACMLAuthzDecisionQuery_NUM_Policy(struct zx_xaspcd1_XACMLAuthzDecisionQuery_s* x)
{
  struct zx_xa_Policy_s* y;
  int n = 0;
  if (!x) return 0;
  for (y = x->Policy; y; ++n, y = (struct zx_xa_Policy_s*)y->gg.g.n) ;
  return n;
}

/* FUNC(zx_xaspcd1_XACMLAuthzDecisionQuery_GET_Policy) */

struct zx_xa_Policy_s* zx_xaspcd1_XACMLAuthzDecisionQuery_GET_Policy(struct zx_xaspcd1_XACMLAuthzDecisionQuery_s* x, int n)
{
  struct zx_xa_Policy_s* y;
  if (!x) return 0;
  for (y = x->Policy; n>=0 && y; --n, y = (struct zx_xa_Policy_s*)y->gg.g.n) ;
  return y;
}

/* FUNC(zx_xaspcd1_XACMLAuthzDecisionQuery_POP_Policy) */

struct zx_xa_Policy_s* zx_xaspcd1_XACMLAuthzDecisionQuery_POP_Policy(struct zx_xaspcd1_XACMLAuthzDecisionQuery_s* x)
{
  struct zx_xa_Policy_s* y;
  if (!x) return 0;
  y = x->Policy;
  if (y)
    x->Policy = (struct zx_xa_Policy_s*)y->gg.g.n;
  return y;
}

/* FUNC(zx_xaspcd1_XACMLAuthzDecisionQuery_PUSH_Policy) */

void zx_xaspcd1_XACMLAuthzDecisionQuery_PUSH_Policy(struct zx_xaspcd1_XACMLAuthzDecisionQuery_s* x, struct zx_xa_Policy_s* z)
{
  if (!x || !z) return;
  z->gg.g.n = &x->Policy->gg.g;
  x->Policy = z;
}

/* FUNC(zx_xaspcd1_XACMLAuthzDecisionQuery_REV_Policy) */

void zx_xaspcd1_XACMLAuthzDecisionQuery_REV_Policy(struct zx_xaspcd1_XACMLAuthzDecisionQuery_s* x)
{
  struct zx_xa_Policy_s* nxt;
  struct zx_xa_Policy_s* y;
  if (!x) return;
  y = x->Policy;
  if (!y) return;
  x->Policy = 0;
  while (y) {
    nxt = (struct zx_xa_Policy_s*)y->gg.g.n;
    y->gg.g.n = &x->Policy->gg.g;
    x->Policy = y;
    y = nxt;
  }
}

/* FUNC(zx_xaspcd1_XACMLAuthzDecisionQuery_PUT_Policy) */

void zx_xaspcd1_XACMLAuthzDecisionQuery_PUT_Policy(struct zx_xaspcd1_XACMLAuthzDecisionQuery_s* x, int n, struct zx_xa_Policy_s* z)
{
  struct zx_xa_Policy_s* y;
  if (!x || !z) return;
  y = x->Policy;
  if (!y) return;
  switch (n) {
  case 0:
    z->gg.g.n = y->gg.g.n;
    x->Policy = z;
    return;
  default:
    for (; n > 1 && y->gg.g.n; --n, y = (struct zx_xa_Policy_s*)y->gg.g.n) ;
    if (!y->gg.g.n) return;
    z->gg.g.n = y->gg.g.n->n;
    y->gg.g.n = &z->gg.g;
  }
}

/* FUNC(zx_xaspcd1_XACMLAuthzDecisionQuery_ADD_Policy) */

void zx_xaspcd1_XACMLAuthzDecisionQuery_ADD_Policy(struct zx_xaspcd1_XACMLAuthzDecisionQuery_s* x, int n, struct zx_xa_Policy_s* z)
{
  struct zx_xa_Policy_s* y;
  if (!x || !z) return;
  switch (n) {
  case 0:
  add_to_start:
    z->gg.g.n = &x->Policy->gg.g;
    x->Policy = z;
    return;
  case -1:
    y = x->Policy;
    if (!y) goto add_to_start;
    for (; y->gg.g.n; y = (struct zx_xa_Policy_s*)y->gg.g.n) ;
    break;
  default:
    for (y = x->Policy; n > 1 && y; --n, y = (struct zx_xa_Policy_s*)y->gg.g.n) ;
    if (!y) return;
  }
  z->gg.g.n = y->gg.g.n;
  y->gg.g.n = &z->gg.g;
}

/* FUNC(zx_xaspcd1_XACMLAuthzDecisionQuery_DEL_Policy) */

void zx_xaspcd1_XACMLAuthzDecisionQuery_DEL_Policy(struct zx_xaspcd1_XACMLAuthzDecisionQuery_s* x, int n)
{
  struct zx_xa_Policy_s* y;
  if (!x) return;
  switch (n) {
  case 0:
    x->Policy = (struct zx_xa_Policy_s*)x->Policy->gg.g.n;
    return;
  case -1:
    y = (struct zx_xa_Policy_s*)x->Policy;
    if (!y) return;
    for (; y->gg.g.n; y = (struct zx_xa_Policy_s*)y->gg.g.n) ;
    break;
  default:
    for (y = x->Policy; n > 1 && y->gg.g.n; --n, y = (struct zx_xa_Policy_s*)y->gg.g.n) ;
    if (!y->gg.g.n) return;
  }
  y->gg.g.n = y->gg.g.n->n;
}

#endif



#ifdef ZX_ENA_GETPUT

/* FUNC(zx_xaspcd1_XACMLAuthzDecisionQuery_NUM_PolicySet) */

int zx_xaspcd1_XACMLAuthzDecisionQuery_NUM_PolicySet(struct zx_xaspcd1_XACMLAuthzDecisionQuery_s* x)
{
  struct zx_xa_PolicySet_s* y;
  int n = 0;
  if (!x) return 0;
  for (y = x->PolicySet; y; ++n, y = (struct zx_xa_PolicySet_s*)y->gg.g.n) ;
  return n;
}

/* FUNC(zx_xaspcd1_XACMLAuthzDecisionQuery_GET_PolicySet) */

struct zx_xa_PolicySet_s* zx_xaspcd1_XACMLAuthzDecisionQuery_GET_PolicySet(struct zx_xaspcd1_XACMLAuthzDecisionQuery_s* x, int n)
{
  struct zx_xa_PolicySet_s* y;
  if (!x) return 0;
  for (y = x->PolicySet; n>=0 && y; --n, y = (struct zx_xa_PolicySet_s*)y->gg.g.n) ;
  return y;
}

/* FUNC(zx_xaspcd1_XACMLAuthzDecisionQuery_POP_PolicySet) */

struct zx_xa_PolicySet_s* zx_xaspcd1_XACMLAuthzDecisionQuery_POP_PolicySet(struct zx_xaspcd1_XACMLAuthzDecisionQuery_s* x)
{
  struct zx_xa_PolicySet_s* y;
  if (!x) return 0;
  y = x->PolicySet;
  if (y)
    x->PolicySet = (struct zx_xa_PolicySet_s*)y->gg.g.n;
  return y;
}

/* FUNC(zx_xaspcd1_XACMLAuthzDecisionQuery_PUSH_PolicySet) */

void zx_xaspcd1_XACMLAuthzDecisionQuery_PUSH_PolicySet(struct zx_xaspcd1_XACMLAuthzDecisionQuery_s* x, struct zx_xa_PolicySet_s* z)
{
  if (!x || !z) return;
  z->gg.g.n = &x->PolicySet->gg.g;
  x->PolicySet = z;
}

/* FUNC(zx_xaspcd1_XACMLAuthzDecisionQuery_REV_PolicySet) */

void zx_xaspcd1_XACMLAuthzDecisionQuery_REV_PolicySet(struct zx_xaspcd1_XACMLAuthzDecisionQuery_s* x)
{
  struct zx_xa_PolicySet_s* nxt;
  struct zx_xa_PolicySet_s* y;
  if (!x) return;
  y = x->PolicySet;
  if (!y) return;
  x->PolicySet = 0;
  while (y) {
    nxt = (struct zx_xa_PolicySet_s*)y->gg.g.n;
    y->gg.g.n = &x->PolicySet->gg.g;
    x->PolicySet = y;
    y = nxt;
  }
}

/* FUNC(zx_xaspcd1_XACMLAuthzDecisionQuery_PUT_PolicySet) */

void zx_xaspcd1_XACMLAuthzDecisionQuery_PUT_PolicySet(struct zx_xaspcd1_XACMLAuthzDecisionQuery_s* x, int n, struct zx_xa_PolicySet_s* z)
{
  struct zx_xa_PolicySet_s* y;
  if (!x || !z) return;
  y = x->PolicySet;
  if (!y) return;
  switch (n) {
  case 0:
    z->gg.g.n = y->gg.g.n;
    x->PolicySet = z;
    return;
  default:
    for (; n > 1 && y->gg.g.n; --n, y = (struct zx_xa_PolicySet_s*)y->gg.g.n) ;
    if (!y->gg.g.n) return;
    z->gg.g.n = y->gg.g.n->n;
    y->gg.g.n = &z->gg.g;
  }
}

/* FUNC(zx_xaspcd1_XACMLAuthzDecisionQuery_ADD_PolicySet) */

void zx_xaspcd1_XACMLAuthzDecisionQuery_ADD_PolicySet(struct zx_xaspcd1_XACMLAuthzDecisionQuery_s* x, int n, struct zx_xa_PolicySet_s* z)
{
  struct zx_xa_PolicySet_s* y;
  if (!x || !z) return;
  switch (n) {
  case 0:
  add_to_start:
    z->gg.g.n = &x->PolicySet->gg.g;
    x->PolicySet = z;
    return;
  case -1:
    y = x->PolicySet;
    if (!y) goto add_to_start;
    for (; y->gg.g.n; y = (struct zx_xa_PolicySet_s*)y->gg.g.n) ;
    break;
  default:
    for (y = x->PolicySet; n > 1 && y; --n, y = (struct zx_xa_PolicySet_s*)y->gg.g.n) ;
    if (!y) return;
  }
  z->gg.g.n = y->gg.g.n;
  y->gg.g.n = &z->gg.g;
}

/* FUNC(zx_xaspcd1_XACMLAuthzDecisionQuery_DEL_PolicySet) */

void zx_xaspcd1_XACMLAuthzDecisionQuery_DEL_PolicySet(struct zx_xaspcd1_XACMLAuthzDecisionQuery_s* x, int n)
{
  struct zx_xa_PolicySet_s* y;
  if (!x) return;
  switch (n) {
  case 0:
    x->PolicySet = (struct zx_xa_PolicySet_s*)x->PolicySet->gg.g.n;
    return;
  case -1:
    y = (struct zx_xa_PolicySet_s*)x->PolicySet;
    if (!y) return;
    for (; y->gg.g.n; y = (struct zx_xa_PolicySet_s*)y->gg.g.n) ;
    break;
  default:
    for (y = x->PolicySet; n > 1 && y->gg.g.n; --n, y = (struct zx_xa_PolicySet_s*)y->gg.g.n) ;
    if (!y->gg.g.n) return;
  }
  y->gg.g.n = y->gg.g.n->n;
}

#endif



#ifdef ZX_ENA_GETPUT

/* FUNC(zx_xaspcd1_XACMLAuthzDecisionQuery_NUM_ReferencedPolicies) */

int zx_xaspcd1_XACMLAuthzDecisionQuery_NUM_ReferencedPolicies(struct zx_xaspcd1_XACMLAuthzDecisionQuery_s* x)
{
  struct zx_xasacd1_ReferencedPolicies_s* y;
  int n = 0;
  if (!x) return 0;
  for (y = x->ReferencedPolicies; y; ++n, y = (struct zx_xasacd1_ReferencedPolicies_s*)y->gg.g.n) ;
  return n;
}

/* FUNC(zx_xaspcd1_XACMLAuthzDecisionQuery_GET_ReferencedPolicies) */

struct zx_xasacd1_ReferencedPolicies_s* zx_xaspcd1_XACMLAuthzDecisionQuery_GET_ReferencedPolicies(struct zx_xaspcd1_XACMLAuthzDecisionQuery_s* x, int n)
{
  struct zx_xasacd1_ReferencedPolicies_s* y;
  if (!x) return 0;
  for (y = x->ReferencedPolicies; n>=0 && y; --n, y = (struct zx_xasacd1_ReferencedPolicies_s*)y->gg.g.n) ;
  return y;
}

/* FUNC(zx_xaspcd1_XACMLAuthzDecisionQuery_POP_ReferencedPolicies) */

struct zx_xasacd1_ReferencedPolicies_s* zx_xaspcd1_XACMLAuthzDecisionQuery_POP_ReferencedPolicies(struct zx_xaspcd1_XACMLAuthzDecisionQuery_s* x)
{
  struct zx_xasacd1_ReferencedPolicies_s* y;
  if (!x) return 0;
  y = x->ReferencedPolicies;
  if (y)
    x->ReferencedPolicies = (struct zx_xasacd1_ReferencedPolicies_s*)y->gg.g.n;
  return y;
}

/* FUNC(zx_xaspcd1_XACMLAuthzDecisionQuery_PUSH_ReferencedPolicies) */

void zx_xaspcd1_XACMLAuthzDecisionQuery_PUSH_ReferencedPolicies(struct zx_xaspcd1_XACMLAuthzDecisionQuery_s* x, struct zx_xasacd1_ReferencedPolicies_s* z)
{
  if (!x || !z) return;
  z->gg.g.n = &x->ReferencedPolicies->gg.g;
  x->ReferencedPolicies = z;
}

/* FUNC(zx_xaspcd1_XACMLAuthzDecisionQuery_REV_ReferencedPolicies) */

void zx_xaspcd1_XACMLAuthzDecisionQuery_REV_ReferencedPolicies(struct zx_xaspcd1_XACMLAuthzDecisionQuery_s* x)
{
  struct zx_xasacd1_ReferencedPolicies_s* nxt;
  struct zx_xasacd1_ReferencedPolicies_s* y;
  if (!x) return;
  y = x->ReferencedPolicies;
  if (!y) return;
  x->ReferencedPolicies = 0;
  while (y) {
    nxt = (struct zx_xasacd1_ReferencedPolicies_s*)y->gg.g.n;
    y->gg.g.n = &x->ReferencedPolicies->gg.g;
    x->ReferencedPolicies = y;
    y = nxt;
  }
}

/* FUNC(zx_xaspcd1_XACMLAuthzDecisionQuery_PUT_ReferencedPolicies) */

void zx_xaspcd1_XACMLAuthzDecisionQuery_PUT_ReferencedPolicies(struct zx_xaspcd1_XACMLAuthzDecisionQuery_s* x, int n, struct zx_xasacd1_ReferencedPolicies_s* z)
{
  struct zx_xasacd1_ReferencedPolicies_s* y;
  if (!x || !z) return;
  y = x->ReferencedPolicies;
  if (!y) return;
  switch (n) {
  case 0:
    z->gg.g.n = y->gg.g.n;
    x->ReferencedPolicies = z;
    return;
  default:
    for (; n > 1 && y->gg.g.n; --n, y = (struct zx_xasacd1_ReferencedPolicies_s*)y->gg.g.n) ;
    if (!y->gg.g.n) return;
    z->gg.g.n = y->gg.g.n->n;
    y->gg.g.n = &z->gg.g;
  }
}

/* FUNC(zx_xaspcd1_XACMLAuthzDecisionQuery_ADD_ReferencedPolicies) */

void zx_xaspcd1_XACMLAuthzDecisionQuery_ADD_ReferencedPolicies(struct zx_xaspcd1_XACMLAuthzDecisionQuery_s* x, int n, struct zx_xasacd1_ReferencedPolicies_s* z)
{
  struct zx_xasacd1_ReferencedPolicies_s* y;
  if (!x || !z) return;
  switch (n) {
  case 0:
  add_to_start:
    z->gg.g.n = &x->ReferencedPolicies->gg.g;
    x->ReferencedPolicies = z;
    return;
  case -1:
    y = x->ReferencedPolicies;
    if (!y) goto add_to_start;
    for (; y->gg.g.n; y = (struct zx_xasacd1_ReferencedPolicies_s*)y->gg.g.n) ;
    break;
  default:
    for (y = x->ReferencedPolicies; n > 1 && y; --n, y = (struct zx_xasacd1_ReferencedPolicies_s*)y->gg.g.n) ;
    if (!y) return;
  }
  z->gg.g.n = y->gg.g.n;
  y->gg.g.n = &z->gg.g;
}

/* FUNC(zx_xaspcd1_XACMLAuthzDecisionQuery_DEL_ReferencedPolicies) */

void zx_xaspcd1_XACMLAuthzDecisionQuery_DEL_ReferencedPolicies(struct zx_xaspcd1_XACMLAuthzDecisionQuery_s* x, int n)
{
  struct zx_xasacd1_ReferencedPolicies_s* y;
  if (!x) return;
  switch (n) {
  case 0:
    x->ReferencedPolicies = (struct zx_xasacd1_ReferencedPolicies_s*)x->ReferencedPolicies->gg.g.n;
    return;
  case -1:
    y = (struct zx_xasacd1_ReferencedPolicies_s*)x->ReferencedPolicies;
    if (!y) return;
    for (; y->gg.g.n; y = (struct zx_xasacd1_ReferencedPolicies_s*)y->gg.g.n) ;
    break;
  default:
    for (y = x->ReferencedPolicies; n > 1 && y->gg.g.n; --n, y = (struct zx_xasacd1_ReferencedPolicies_s*)y->gg.g.n) ;
    if (!y->gg.g.n) return;
  }
  y->gg.g.n = y->gg.g.n->n;
}

#endif

/* FUNC(zx_xaspcd1_XACMLAuthzDecisionQuery_GET_CombinePolicies) */
struct zx_str* zx_xaspcd1_XACMLAuthzDecisionQuery_GET_CombinePolicies(struct zx_xaspcd1_XACMLAuthzDecisionQuery_s* x) { return x->CombinePolicies; }
/* FUNC(zx_xaspcd1_XACMLAuthzDecisionQuery_PUT_CombinePolicies) */
void zx_xaspcd1_XACMLAuthzDecisionQuery_PUT_CombinePolicies(struct zx_xaspcd1_XACMLAuthzDecisionQuery_s* x, struct zx_str* y) { x->CombinePolicies = y; }
/* FUNC(zx_xaspcd1_XACMLAuthzDecisionQuery_GET_Consent) */
struct zx_str* zx_xaspcd1_XACMLAuthzDecisionQuery_GET_Consent(struct zx_xaspcd1_XACMLAuthzDecisionQuery_s* x) { return x->Consent; }
/* FUNC(zx_xaspcd1_XACMLAuthzDecisionQuery_PUT_Consent) */
void zx_xaspcd1_XACMLAuthzDecisionQuery_PUT_Consent(struct zx_xaspcd1_XACMLAuthzDecisionQuery_s* x, struct zx_str* y) { x->Consent = y; }
/* FUNC(zx_xaspcd1_XACMLAuthzDecisionQuery_GET_Destination) */
struct zx_str* zx_xaspcd1_XACMLAuthzDecisionQuery_GET_Destination(struct zx_xaspcd1_XACMLAuthzDecisionQuery_s* x) { return x->Destination; }
/* FUNC(zx_xaspcd1_XACMLAuthzDecisionQuery_PUT_Destination) */
void zx_xaspcd1_XACMLAuthzDecisionQuery_PUT_Destination(struct zx_xaspcd1_XACMLAuthzDecisionQuery_s* x, struct zx_str* y) { x->Destination = y; }
/* FUNC(zx_xaspcd1_XACMLAuthzDecisionQuery_GET_ID) */
struct zx_str* zx_xaspcd1_XACMLAuthzDecisionQuery_GET_ID(struct zx_xaspcd1_XACMLAuthzDecisionQuery_s* x) { return x->ID; }
/* FUNC(zx_xaspcd1_XACMLAuthzDecisionQuery_PUT_ID) */
void zx_xaspcd1_XACMLAuthzDecisionQuery_PUT_ID(struct zx_xaspcd1_XACMLAuthzDecisionQuery_s* x, struct zx_str* y) { x->ID = y; }
/* FUNC(zx_xaspcd1_XACMLAuthzDecisionQuery_GET_InputContextOnly) */
struct zx_str* zx_xaspcd1_XACMLAuthzDecisionQuery_GET_InputContextOnly(struct zx_xaspcd1_XACMLAuthzDecisionQuery_s* x) { return x->InputContextOnly; }
/* FUNC(zx_xaspcd1_XACMLAuthzDecisionQuery_PUT_InputContextOnly) */
void zx_xaspcd1_XACMLAuthzDecisionQuery_PUT_InputContextOnly(struct zx_xaspcd1_XACMLAuthzDecisionQuery_s* x, struct zx_str* y) { x->InputContextOnly = y; }
/* FUNC(zx_xaspcd1_XACMLAuthzDecisionQuery_GET_IssueInstant) */
struct zx_str* zx_xaspcd1_XACMLAuthzDecisionQuery_GET_IssueInstant(struct zx_xaspcd1_XACMLAuthzDecisionQuery_s* x) { return x->IssueInstant; }
/* FUNC(zx_xaspcd1_XACMLAuthzDecisionQuery_PUT_IssueInstant) */
void zx_xaspcd1_XACMLAuthzDecisionQuery_PUT_IssueInstant(struct zx_xaspcd1_XACMLAuthzDecisionQuery_s* x, struct zx_str* y) { x->IssueInstant = y; }
/* FUNC(zx_xaspcd1_XACMLAuthzDecisionQuery_GET_ReturnContext) */
struct zx_str* zx_xaspcd1_XACMLAuthzDecisionQuery_GET_ReturnContext(struct zx_xaspcd1_XACMLAuthzDecisionQuery_s* x) { return x->ReturnContext; }
/* FUNC(zx_xaspcd1_XACMLAuthzDecisionQuery_PUT_ReturnContext) */
void zx_xaspcd1_XACMLAuthzDecisionQuery_PUT_ReturnContext(struct zx_xaspcd1_XACMLAuthzDecisionQuery_s* x, struct zx_str* y) { x->ReturnContext = y; }
/* FUNC(zx_xaspcd1_XACMLAuthzDecisionQuery_GET_Version) */
struct zx_str* zx_xaspcd1_XACMLAuthzDecisionQuery_GET_Version(struct zx_xaspcd1_XACMLAuthzDecisionQuery_s* x) { return x->Version; }
/* FUNC(zx_xaspcd1_XACMLAuthzDecisionQuery_PUT_Version) */
void zx_xaspcd1_XACMLAuthzDecisionQuery_PUT_Version(struct zx_xaspcd1_XACMLAuthzDecisionQuery_s* x, struct zx_str* y) { x->Version = y; }







#ifdef ZX_ENA_GETPUT

/* FUNC(zx_xaspcd1_XACMLPolicyQuery_NUM_Issuer) */

int zx_xaspcd1_XACMLPolicyQuery_NUM_Issuer(struct zx_xaspcd1_XACMLPolicyQuery_s* x)
{
  struct zx_sa_Issuer_s* y;
  int n = 0;
  if (!x) return 0;
  for (y = x->Issuer; y; ++n, y = (struct zx_sa_Issuer_s*)y->gg.g.n) ;
  return n;
}

/* FUNC(zx_xaspcd1_XACMLPolicyQuery_GET_Issuer) */

struct zx_sa_Issuer_s* zx_xaspcd1_XACMLPolicyQuery_GET_Issuer(struct zx_xaspcd1_XACMLPolicyQuery_s* x, int n)
{
  struct zx_sa_Issuer_s* y;
  if (!x) return 0;
  for (y = x->Issuer; n>=0 && y; --n, y = (struct zx_sa_Issuer_s*)y->gg.g.n) ;
  return y;
}

/* FUNC(zx_xaspcd1_XACMLPolicyQuery_POP_Issuer) */

struct zx_sa_Issuer_s* zx_xaspcd1_XACMLPolicyQuery_POP_Issuer(struct zx_xaspcd1_XACMLPolicyQuery_s* x)
{
  struct zx_sa_Issuer_s* y;
  if (!x) return 0;
  y = x->Issuer;
  if (y)
    x->Issuer = (struct zx_sa_Issuer_s*)y->gg.g.n;
  return y;
}

/* FUNC(zx_xaspcd1_XACMLPolicyQuery_PUSH_Issuer) */

void zx_xaspcd1_XACMLPolicyQuery_PUSH_Issuer(struct zx_xaspcd1_XACMLPolicyQuery_s* x, struct zx_sa_Issuer_s* z)
{
  if (!x || !z) return;
  z->gg.g.n = &x->Issuer->gg.g;
  x->Issuer = z;
}

/* FUNC(zx_xaspcd1_XACMLPolicyQuery_REV_Issuer) */

void zx_xaspcd1_XACMLPolicyQuery_REV_Issuer(struct zx_xaspcd1_XACMLPolicyQuery_s* x)
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

/* FUNC(zx_xaspcd1_XACMLPolicyQuery_PUT_Issuer) */

void zx_xaspcd1_XACMLPolicyQuery_PUT_Issuer(struct zx_xaspcd1_XACMLPolicyQuery_s* x, int n, struct zx_sa_Issuer_s* z)
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

/* FUNC(zx_xaspcd1_XACMLPolicyQuery_ADD_Issuer) */

void zx_xaspcd1_XACMLPolicyQuery_ADD_Issuer(struct zx_xaspcd1_XACMLPolicyQuery_s* x, int n, struct zx_sa_Issuer_s* z)
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

/* FUNC(zx_xaspcd1_XACMLPolicyQuery_DEL_Issuer) */

void zx_xaspcd1_XACMLPolicyQuery_DEL_Issuer(struct zx_xaspcd1_XACMLPolicyQuery_s* x, int n)
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

/* FUNC(zx_xaspcd1_XACMLPolicyQuery_NUM_Signature) */

int zx_xaspcd1_XACMLPolicyQuery_NUM_Signature(struct zx_xaspcd1_XACMLPolicyQuery_s* x)
{
  struct zx_ds_Signature_s* y;
  int n = 0;
  if (!x) return 0;
  for (y = x->Signature; y; ++n, y = (struct zx_ds_Signature_s*)y->gg.g.n) ;
  return n;
}

/* FUNC(zx_xaspcd1_XACMLPolicyQuery_GET_Signature) */

struct zx_ds_Signature_s* zx_xaspcd1_XACMLPolicyQuery_GET_Signature(struct zx_xaspcd1_XACMLPolicyQuery_s* x, int n)
{
  struct zx_ds_Signature_s* y;
  if (!x) return 0;
  for (y = x->Signature; n>=0 && y; --n, y = (struct zx_ds_Signature_s*)y->gg.g.n) ;
  return y;
}

/* FUNC(zx_xaspcd1_XACMLPolicyQuery_POP_Signature) */

struct zx_ds_Signature_s* zx_xaspcd1_XACMLPolicyQuery_POP_Signature(struct zx_xaspcd1_XACMLPolicyQuery_s* x)
{
  struct zx_ds_Signature_s* y;
  if (!x) return 0;
  y = x->Signature;
  if (y)
    x->Signature = (struct zx_ds_Signature_s*)y->gg.g.n;
  return y;
}

/* FUNC(zx_xaspcd1_XACMLPolicyQuery_PUSH_Signature) */

void zx_xaspcd1_XACMLPolicyQuery_PUSH_Signature(struct zx_xaspcd1_XACMLPolicyQuery_s* x, struct zx_ds_Signature_s* z)
{
  if (!x || !z) return;
  z->gg.g.n = &x->Signature->gg.g;
  x->Signature = z;
}

/* FUNC(zx_xaspcd1_XACMLPolicyQuery_REV_Signature) */

void zx_xaspcd1_XACMLPolicyQuery_REV_Signature(struct zx_xaspcd1_XACMLPolicyQuery_s* x)
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

/* FUNC(zx_xaspcd1_XACMLPolicyQuery_PUT_Signature) */

void zx_xaspcd1_XACMLPolicyQuery_PUT_Signature(struct zx_xaspcd1_XACMLPolicyQuery_s* x, int n, struct zx_ds_Signature_s* z)
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

/* FUNC(zx_xaspcd1_XACMLPolicyQuery_ADD_Signature) */

void zx_xaspcd1_XACMLPolicyQuery_ADD_Signature(struct zx_xaspcd1_XACMLPolicyQuery_s* x, int n, struct zx_ds_Signature_s* z)
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

/* FUNC(zx_xaspcd1_XACMLPolicyQuery_DEL_Signature) */

void zx_xaspcd1_XACMLPolicyQuery_DEL_Signature(struct zx_xaspcd1_XACMLPolicyQuery_s* x, int n)
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

/* FUNC(zx_xaspcd1_XACMLPolicyQuery_NUM_Extensions) */

int zx_xaspcd1_XACMLPolicyQuery_NUM_Extensions(struct zx_xaspcd1_XACMLPolicyQuery_s* x)
{
  struct zx_sp_Extensions_s* y;
  int n = 0;
  if (!x) return 0;
  for (y = x->Extensions; y; ++n, y = (struct zx_sp_Extensions_s*)y->gg.g.n) ;
  return n;
}

/* FUNC(zx_xaspcd1_XACMLPolicyQuery_GET_Extensions) */

struct zx_sp_Extensions_s* zx_xaspcd1_XACMLPolicyQuery_GET_Extensions(struct zx_xaspcd1_XACMLPolicyQuery_s* x, int n)
{
  struct zx_sp_Extensions_s* y;
  if (!x) return 0;
  for (y = x->Extensions; n>=0 && y; --n, y = (struct zx_sp_Extensions_s*)y->gg.g.n) ;
  return y;
}

/* FUNC(zx_xaspcd1_XACMLPolicyQuery_POP_Extensions) */

struct zx_sp_Extensions_s* zx_xaspcd1_XACMLPolicyQuery_POP_Extensions(struct zx_xaspcd1_XACMLPolicyQuery_s* x)
{
  struct zx_sp_Extensions_s* y;
  if (!x) return 0;
  y = x->Extensions;
  if (y)
    x->Extensions = (struct zx_sp_Extensions_s*)y->gg.g.n;
  return y;
}

/* FUNC(zx_xaspcd1_XACMLPolicyQuery_PUSH_Extensions) */

void zx_xaspcd1_XACMLPolicyQuery_PUSH_Extensions(struct zx_xaspcd1_XACMLPolicyQuery_s* x, struct zx_sp_Extensions_s* z)
{
  if (!x || !z) return;
  z->gg.g.n = &x->Extensions->gg.g;
  x->Extensions = z;
}

/* FUNC(zx_xaspcd1_XACMLPolicyQuery_REV_Extensions) */

void zx_xaspcd1_XACMLPolicyQuery_REV_Extensions(struct zx_xaspcd1_XACMLPolicyQuery_s* x)
{
  struct zx_sp_Extensions_s* nxt;
  struct zx_sp_Extensions_s* y;
  if (!x) return;
  y = x->Extensions;
  if (!y) return;
  x->Extensions = 0;
  while (y) {
    nxt = (struct zx_sp_Extensions_s*)y->gg.g.n;
    y->gg.g.n = &x->Extensions->gg.g;
    x->Extensions = y;
    y = nxt;
  }
}

/* FUNC(zx_xaspcd1_XACMLPolicyQuery_PUT_Extensions) */

void zx_xaspcd1_XACMLPolicyQuery_PUT_Extensions(struct zx_xaspcd1_XACMLPolicyQuery_s* x, int n, struct zx_sp_Extensions_s* z)
{
  struct zx_sp_Extensions_s* y;
  if (!x || !z) return;
  y = x->Extensions;
  if (!y) return;
  switch (n) {
  case 0:
    z->gg.g.n = y->gg.g.n;
    x->Extensions = z;
    return;
  default:
    for (; n > 1 && y->gg.g.n; --n, y = (struct zx_sp_Extensions_s*)y->gg.g.n) ;
    if (!y->gg.g.n) return;
    z->gg.g.n = y->gg.g.n->n;
    y->gg.g.n = &z->gg.g;
  }
}

/* FUNC(zx_xaspcd1_XACMLPolicyQuery_ADD_Extensions) */

void zx_xaspcd1_XACMLPolicyQuery_ADD_Extensions(struct zx_xaspcd1_XACMLPolicyQuery_s* x, int n, struct zx_sp_Extensions_s* z)
{
  struct zx_sp_Extensions_s* y;
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
    for (; y->gg.g.n; y = (struct zx_sp_Extensions_s*)y->gg.g.n) ;
    break;
  default:
    for (y = x->Extensions; n > 1 && y; --n, y = (struct zx_sp_Extensions_s*)y->gg.g.n) ;
    if (!y) return;
  }
  z->gg.g.n = y->gg.g.n;
  y->gg.g.n = &z->gg.g;
}

/* FUNC(zx_xaspcd1_XACMLPolicyQuery_DEL_Extensions) */

void zx_xaspcd1_XACMLPolicyQuery_DEL_Extensions(struct zx_xaspcd1_XACMLPolicyQuery_s* x, int n)
{
  struct zx_sp_Extensions_s* y;
  if (!x) return;
  switch (n) {
  case 0:
    x->Extensions = (struct zx_sp_Extensions_s*)x->Extensions->gg.g.n;
    return;
  case -1:
    y = (struct zx_sp_Extensions_s*)x->Extensions;
    if (!y) return;
    for (; y->gg.g.n; y = (struct zx_sp_Extensions_s*)y->gg.g.n) ;
    break;
  default:
    for (y = x->Extensions; n > 1 && y->gg.g.n; --n, y = (struct zx_sp_Extensions_s*)y->gg.g.n) ;
    if (!y->gg.g.n) return;
  }
  y->gg.g.n = y->gg.g.n->n;
}

#endif



#ifdef ZX_ENA_GETPUT

/* FUNC(zx_xaspcd1_XACMLPolicyQuery_NUM_Request) */

int zx_xaspcd1_XACMLPolicyQuery_NUM_Request(struct zx_xaspcd1_XACMLPolicyQuery_s* x)
{
  struct zx_xac_Request_s* y;
  int n = 0;
  if (!x) return 0;
  for (y = x->Request; y; ++n, y = (struct zx_xac_Request_s*)y->gg.g.n) ;
  return n;
}

/* FUNC(zx_xaspcd1_XACMLPolicyQuery_GET_Request) */

struct zx_xac_Request_s* zx_xaspcd1_XACMLPolicyQuery_GET_Request(struct zx_xaspcd1_XACMLPolicyQuery_s* x, int n)
{
  struct zx_xac_Request_s* y;
  if (!x) return 0;
  for (y = x->Request; n>=0 && y; --n, y = (struct zx_xac_Request_s*)y->gg.g.n) ;
  return y;
}

/* FUNC(zx_xaspcd1_XACMLPolicyQuery_POP_Request) */

struct zx_xac_Request_s* zx_xaspcd1_XACMLPolicyQuery_POP_Request(struct zx_xaspcd1_XACMLPolicyQuery_s* x)
{
  struct zx_xac_Request_s* y;
  if (!x) return 0;
  y = x->Request;
  if (y)
    x->Request = (struct zx_xac_Request_s*)y->gg.g.n;
  return y;
}

/* FUNC(zx_xaspcd1_XACMLPolicyQuery_PUSH_Request) */

void zx_xaspcd1_XACMLPolicyQuery_PUSH_Request(struct zx_xaspcd1_XACMLPolicyQuery_s* x, struct zx_xac_Request_s* z)
{
  if (!x || !z) return;
  z->gg.g.n = &x->Request->gg.g;
  x->Request = z;
}

/* FUNC(zx_xaspcd1_XACMLPolicyQuery_REV_Request) */

void zx_xaspcd1_XACMLPolicyQuery_REV_Request(struct zx_xaspcd1_XACMLPolicyQuery_s* x)
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

/* FUNC(zx_xaspcd1_XACMLPolicyQuery_PUT_Request) */

void zx_xaspcd1_XACMLPolicyQuery_PUT_Request(struct zx_xaspcd1_XACMLPolicyQuery_s* x, int n, struct zx_xac_Request_s* z)
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

/* FUNC(zx_xaspcd1_XACMLPolicyQuery_ADD_Request) */

void zx_xaspcd1_XACMLPolicyQuery_ADD_Request(struct zx_xaspcd1_XACMLPolicyQuery_s* x, int n, struct zx_xac_Request_s* z)
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

/* FUNC(zx_xaspcd1_XACMLPolicyQuery_DEL_Request) */

void zx_xaspcd1_XACMLPolicyQuery_DEL_Request(struct zx_xaspcd1_XACMLPolicyQuery_s* x, int n)
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



#ifdef ZX_ENA_GETPUT

/* FUNC(zx_xaspcd1_XACMLPolicyQuery_NUM_Target) */

int zx_xaspcd1_XACMLPolicyQuery_NUM_Target(struct zx_xaspcd1_XACMLPolicyQuery_s* x)
{
  struct zx_xa_Target_s* y;
  int n = 0;
  if (!x) return 0;
  for (y = x->Target; y; ++n, y = (struct zx_xa_Target_s*)y->gg.g.n) ;
  return n;
}

/* FUNC(zx_xaspcd1_XACMLPolicyQuery_GET_Target) */

struct zx_xa_Target_s* zx_xaspcd1_XACMLPolicyQuery_GET_Target(struct zx_xaspcd1_XACMLPolicyQuery_s* x, int n)
{
  struct zx_xa_Target_s* y;
  if (!x) return 0;
  for (y = x->Target; n>=0 && y; --n, y = (struct zx_xa_Target_s*)y->gg.g.n) ;
  return y;
}

/* FUNC(zx_xaspcd1_XACMLPolicyQuery_POP_Target) */

struct zx_xa_Target_s* zx_xaspcd1_XACMLPolicyQuery_POP_Target(struct zx_xaspcd1_XACMLPolicyQuery_s* x)
{
  struct zx_xa_Target_s* y;
  if (!x) return 0;
  y = x->Target;
  if (y)
    x->Target = (struct zx_xa_Target_s*)y->gg.g.n;
  return y;
}

/* FUNC(zx_xaspcd1_XACMLPolicyQuery_PUSH_Target) */

void zx_xaspcd1_XACMLPolicyQuery_PUSH_Target(struct zx_xaspcd1_XACMLPolicyQuery_s* x, struct zx_xa_Target_s* z)
{
  if (!x || !z) return;
  z->gg.g.n = &x->Target->gg.g;
  x->Target = z;
}

/* FUNC(zx_xaspcd1_XACMLPolicyQuery_REV_Target) */

void zx_xaspcd1_XACMLPolicyQuery_REV_Target(struct zx_xaspcd1_XACMLPolicyQuery_s* x)
{
  struct zx_xa_Target_s* nxt;
  struct zx_xa_Target_s* y;
  if (!x) return;
  y = x->Target;
  if (!y) return;
  x->Target = 0;
  while (y) {
    nxt = (struct zx_xa_Target_s*)y->gg.g.n;
    y->gg.g.n = &x->Target->gg.g;
    x->Target = y;
    y = nxt;
  }
}

/* FUNC(zx_xaspcd1_XACMLPolicyQuery_PUT_Target) */

void zx_xaspcd1_XACMLPolicyQuery_PUT_Target(struct zx_xaspcd1_XACMLPolicyQuery_s* x, int n, struct zx_xa_Target_s* z)
{
  struct zx_xa_Target_s* y;
  if (!x || !z) return;
  y = x->Target;
  if (!y) return;
  switch (n) {
  case 0:
    z->gg.g.n = y->gg.g.n;
    x->Target = z;
    return;
  default:
    for (; n > 1 && y->gg.g.n; --n, y = (struct zx_xa_Target_s*)y->gg.g.n) ;
    if (!y->gg.g.n) return;
    z->gg.g.n = y->gg.g.n->n;
    y->gg.g.n = &z->gg.g;
  }
}

/* FUNC(zx_xaspcd1_XACMLPolicyQuery_ADD_Target) */

void zx_xaspcd1_XACMLPolicyQuery_ADD_Target(struct zx_xaspcd1_XACMLPolicyQuery_s* x, int n, struct zx_xa_Target_s* z)
{
  struct zx_xa_Target_s* y;
  if (!x || !z) return;
  switch (n) {
  case 0:
  add_to_start:
    z->gg.g.n = &x->Target->gg.g;
    x->Target = z;
    return;
  case -1:
    y = x->Target;
    if (!y) goto add_to_start;
    for (; y->gg.g.n; y = (struct zx_xa_Target_s*)y->gg.g.n) ;
    break;
  default:
    for (y = x->Target; n > 1 && y; --n, y = (struct zx_xa_Target_s*)y->gg.g.n) ;
    if (!y) return;
  }
  z->gg.g.n = y->gg.g.n;
  y->gg.g.n = &z->gg.g;
}

/* FUNC(zx_xaspcd1_XACMLPolicyQuery_DEL_Target) */

void zx_xaspcd1_XACMLPolicyQuery_DEL_Target(struct zx_xaspcd1_XACMLPolicyQuery_s* x, int n)
{
  struct zx_xa_Target_s* y;
  if (!x) return;
  switch (n) {
  case 0:
    x->Target = (struct zx_xa_Target_s*)x->Target->gg.g.n;
    return;
  case -1:
    y = (struct zx_xa_Target_s*)x->Target;
    if (!y) return;
    for (; y->gg.g.n; y = (struct zx_xa_Target_s*)y->gg.g.n) ;
    break;
  default:
    for (y = x->Target; n > 1 && y->gg.g.n; --n, y = (struct zx_xa_Target_s*)y->gg.g.n) ;
    if (!y->gg.g.n) return;
  }
  y->gg.g.n = y->gg.g.n->n;
}

#endif



#ifdef ZX_ENA_GETPUT

/* FUNC(zx_xaspcd1_XACMLPolicyQuery_NUM_PolicySetIdReference) */

int zx_xaspcd1_XACMLPolicyQuery_NUM_PolicySetIdReference(struct zx_xaspcd1_XACMLPolicyQuery_s* x)
{
  struct zx_xa_PolicySetIdReference_s* y;
  int n = 0;
  if (!x) return 0;
  for (y = x->PolicySetIdReference; y; ++n, y = (struct zx_xa_PolicySetIdReference_s*)y->gg.g.n) ;
  return n;
}

/* FUNC(zx_xaspcd1_XACMLPolicyQuery_GET_PolicySetIdReference) */

struct zx_xa_PolicySetIdReference_s* zx_xaspcd1_XACMLPolicyQuery_GET_PolicySetIdReference(struct zx_xaspcd1_XACMLPolicyQuery_s* x, int n)
{
  struct zx_xa_PolicySetIdReference_s* y;
  if (!x) return 0;
  for (y = x->PolicySetIdReference; n>=0 && y; --n, y = (struct zx_xa_PolicySetIdReference_s*)y->gg.g.n) ;
  return y;
}

/* FUNC(zx_xaspcd1_XACMLPolicyQuery_POP_PolicySetIdReference) */

struct zx_xa_PolicySetIdReference_s* zx_xaspcd1_XACMLPolicyQuery_POP_PolicySetIdReference(struct zx_xaspcd1_XACMLPolicyQuery_s* x)
{
  struct zx_xa_PolicySetIdReference_s* y;
  if (!x) return 0;
  y = x->PolicySetIdReference;
  if (y)
    x->PolicySetIdReference = (struct zx_xa_PolicySetIdReference_s*)y->gg.g.n;
  return y;
}

/* FUNC(zx_xaspcd1_XACMLPolicyQuery_PUSH_PolicySetIdReference) */

void zx_xaspcd1_XACMLPolicyQuery_PUSH_PolicySetIdReference(struct zx_xaspcd1_XACMLPolicyQuery_s* x, struct zx_xa_PolicySetIdReference_s* z)
{
  if (!x || !z) return;
  z->gg.g.n = &x->PolicySetIdReference->gg.g;
  x->PolicySetIdReference = z;
}

/* FUNC(zx_xaspcd1_XACMLPolicyQuery_REV_PolicySetIdReference) */

void zx_xaspcd1_XACMLPolicyQuery_REV_PolicySetIdReference(struct zx_xaspcd1_XACMLPolicyQuery_s* x)
{
  struct zx_xa_PolicySetIdReference_s* nxt;
  struct zx_xa_PolicySetIdReference_s* y;
  if (!x) return;
  y = x->PolicySetIdReference;
  if (!y) return;
  x->PolicySetIdReference = 0;
  while (y) {
    nxt = (struct zx_xa_PolicySetIdReference_s*)y->gg.g.n;
    y->gg.g.n = &x->PolicySetIdReference->gg.g;
    x->PolicySetIdReference = y;
    y = nxt;
  }
}

/* FUNC(zx_xaspcd1_XACMLPolicyQuery_PUT_PolicySetIdReference) */

void zx_xaspcd1_XACMLPolicyQuery_PUT_PolicySetIdReference(struct zx_xaspcd1_XACMLPolicyQuery_s* x, int n, struct zx_xa_PolicySetIdReference_s* z)
{
  struct zx_xa_PolicySetIdReference_s* y;
  if (!x || !z) return;
  y = x->PolicySetIdReference;
  if (!y) return;
  switch (n) {
  case 0:
    z->gg.g.n = y->gg.g.n;
    x->PolicySetIdReference = z;
    return;
  default:
    for (; n > 1 && y->gg.g.n; --n, y = (struct zx_xa_PolicySetIdReference_s*)y->gg.g.n) ;
    if (!y->gg.g.n) return;
    z->gg.g.n = y->gg.g.n->n;
    y->gg.g.n = &z->gg.g;
  }
}

/* FUNC(zx_xaspcd1_XACMLPolicyQuery_ADD_PolicySetIdReference) */

void zx_xaspcd1_XACMLPolicyQuery_ADD_PolicySetIdReference(struct zx_xaspcd1_XACMLPolicyQuery_s* x, int n, struct zx_xa_PolicySetIdReference_s* z)
{
  struct zx_xa_PolicySetIdReference_s* y;
  if (!x || !z) return;
  switch (n) {
  case 0:
  add_to_start:
    z->gg.g.n = &x->PolicySetIdReference->gg.g;
    x->PolicySetIdReference = z;
    return;
  case -1:
    y = x->PolicySetIdReference;
    if (!y) goto add_to_start;
    for (; y->gg.g.n; y = (struct zx_xa_PolicySetIdReference_s*)y->gg.g.n) ;
    break;
  default:
    for (y = x->PolicySetIdReference; n > 1 && y; --n, y = (struct zx_xa_PolicySetIdReference_s*)y->gg.g.n) ;
    if (!y) return;
  }
  z->gg.g.n = y->gg.g.n;
  y->gg.g.n = &z->gg.g;
}

/* FUNC(zx_xaspcd1_XACMLPolicyQuery_DEL_PolicySetIdReference) */

void zx_xaspcd1_XACMLPolicyQuery_DEL_PolicySetIdReference(struct zx_xaspcd1_XACMLPolicyQuery_s* x, int n)
{
  struct zx_xa_PolicySetIdReference_s* y;
  if (!x) return;
  switch (n) {
  case 0:
    x->PolicySetIdReference = (struct zx_xa_PolicySetIdReference_s*)x->PolicySetIdReference->gg.g.n;
    return;
  case -1:
    y = (struct zx_xa_PolicySetIdReference_s*)x->PolicySetIdReference;
    if (!y) return;
    for (; y->gg.g.n; y = (struct zx_xa_PolicySetIdReference_s*)y->gg.g.n) ;
    break;
  default:
    for (y = x->PolicySetIdReference; n > 1 && y->gg.g.n; --n, y = (struct zx_xa_PolicySetIdReference_s*)y->gg.g.n) ;
    if (!y->gg.g.n) return;
  }
  y->gg.g.n = y->gg.g.n->n;
}

#endif



#ifdef ZX_ENA_GETPUT

/* FUNC(zx_xaspcd1_XACMLPolicyQuery_NUM_PolicyIdReference) */

int zx_xaspcd1_XACMLPolicyQuery_NUM_PolicyIdReference(struct zx_xaspcd1_XACMLPolicyQuery_s* x)
{
  struct zx_xa_PolicyIdReference_s* y;
  int n = 0;
  if (!x) return 0;
  for (y = x->PolicyIdReference; y; ++n, y = (struct zx_xa_PolicyIdReference_s*)y->gg.g.n) ;
  return n;
}

/* FUNC(zx_xaspcd1_XACMLPolicyQuery_GET_PolicyIdReference) */

struct zx_xa_PolicyIdReference_s* zx_xaspcd1_XACMLPolicyQuery_GET_PolicyIdReference(struct zx_xaspcd1_XACMLPolicyQuery_s* x, int n)
{
  struct zx_xa_PolicyIdReference_s* y;
  if (!x) return 0;
  for (y = x->PolicyIdReference; n>=0 && y; --n, y = (struct zx_xa_PolicyIdReference_s*)y->gg.g.n) ;
  return y;
}

/* FUNC(zx_xaspcd1_XACMLPolicyQuery_POP_PolicyIdReference) */

struct zx_xa_PolicyIdReference_s* zx_xaspcd1_XACMLPolicyQuery_POP_PolicyIdReference(struct zx_xaspcd1_XACMLPolicyQuery_s* x)
{
  struct zx_xa_PolicyIdReference_s* y;
  if (!x) return 0;
  y = x->PolicyIdReference;
  if (y)
    x->PolicyIdReference = (struct zx_xa_PolicyIdReference_s*)y->gg.g.n;
  return y;
}

/* FUNC(zx_xaspcd1_XACMLPolicyQuery_PUSH_PolicyIdReference) */

void zx_xaspcd1_XACMLPolicyQuery_PUSH_PolicyIdReference(struct zx_xaspcd1_XACMLPolicyQuery_s* x, struct zx_xa_PolicyIdReference_s* z)
{
  if (!x || !z) return;
  z->gg.g.n = &x->PolicyIdReference->gg.g;
  x->PolicyIdReference = z;
}

/* FUNC(zx_xaspcd1_XACMLPolicyQuery_REV_PolicyIdReference) */

void zx_xaspcd1_XACMLPolicyQuery_REV_PolicyIdReference(struct zx_xaspcd1_XACMLPolicyQuery_s* x)
{
  struct zx_xa_PolicyIdReference_s* nxt;
  struct zx_xa_PolicyIdReference_s* y;
  if (!x) return;
  y = x->PolicyIdReference;
  if (!y) return;
  x->PolicyIdReference = 0;
  while (y) {
    nxt = (struct zx_xa_PolicyIdReference_s*)y->gg.g.n;
    y->gg.g.n = &x->PolicyIdReference->gg.g;
    x->PolicyIdReference = y;
    y = nxt;
  }
}

/* FUNC(zx_xaspcd1_XACMLPolicyQuery_PUT_PolicyIdReference) */

void zx_xaspcd1_XACMLPolicyQuery_PUT_PolicyIdReference(struct zx_xaspcd1_XACMLPolicyQuery_s* x, int n, struct zx_xa_PolicyIdReference_s* z)
{
  struct zx_xa_PolicyIdReference_s* y;
  if (!x || !z) return;
  y = x->PolicyIdReference;
  if (!y) return;
  switch (n) {
  case 0:
    z->gg.g.n = y->gg.g.n;
    x->PolicyIdReference = z;
    return;
  default:
    for (; n > 1 && y->gg.g.n; --n, y = (struct zx_xa_PolicyIdReference_s*)y->gg.g.n) ;
    if (!y->gg.g.n) return;
    z->gg.g.n = y->gg.g.n->n;
    y->gg.g.n = &z->gg.g;
  }
}

/* FUNC(zx_xaspcd1_XACMLPolicyQuery_ADD_PolicyIdReference) */

void zx_xaspcd1_XACMLPolicyQuery_ADD_PolicyIdReference(struct zx_xaspcd1_XACMLPolicyQuery_s* x, int n, struct zx_xa_PolicyIdReference_s* z)
{
  struct zx_xa_PolicyIdReference_s* y;
  if (!x || !z) return;
  switch (n) {
  case 0:
  add_to_start:
    z->gg.g.n = &x->PolicyIdReference->gg.g;
    x->PolicyIdReference = z;
    return;
  case -1:
    y = x->PolicyIdReference;
    if (!y) goto add_to_start;
    for (; y->gg.g.n; y = (struct zx_xa_PolicyIdReference_s*)y->gg.g.n) ;
    break;
  default:
    for (y = x->PolicyIdReference; n > 1 && y; --n, y = (struct zx_xa_PolicyIdReference_s*)y->gg.g.n) ;
    if (!y) return;
  }
  z->gg.g.n = y->gg.g.n;
  y->gg.g.n = &z->gg.g;
}

/* FUNC(zx_xaspcd1_XACMLPolicyQuery_DEL_PolicyIdReference) */

void zx_xaspcd1_XACMLPolicyQuery_DEL_PolicyIdReference(struct zx_xaspcd1_XACMLPolicyQuery_s* x, int n)
{
  struct zx_xa_PolicyIdReference_s* y;
  if (!x) return;
  switch (n) {
  case 0:
    x->PolicyIdReference = (struct zx_xa_PolicyIdReference_s*)x->PolicyIdReference->gg.g.n;
    return;
  case -1:
    y = (struct zx_xa_PolicyIdReference_s*)x->PolicyIdReference;
    if (!y) return;
    for (; y->gg.g.n; y = (struct zx_xa_PolicyIdReference_s*)y->gg.g.n) ;
    break;
  default:
    for (y = x->PolicyIdReference; n > 1 && y->gg.g.n; --n, y = (struct zx_xa_PolicyIdReference_s*)y->gg.g.n) ;
    if (!y->gg.g.n) return;
  }
  y->gg.g.n = y->gg.g.n->n;
}

#endif

/* FUNC(zx_xaspcd1_XACMLPolicyQuery_GET_Consent) */
struct zx_str* zx_xaspcd1_XACMLPolicyQuery_GET_Consent(struct zx_xaspcd1_XACMLPolicyQuery_s* x) { return x->Consent; }
/* FUNC(zx_xaspcd1_XACMLPolicyQuery_PUT_Consent) */
void zx_xaspcd1_XACMLPolicyQuery_PUT_Consent(struct zx_xaspcd1_XACMLPolicyQuery_s* x, struct zx_str* y) { x->Consent = y; }
/* FUNC(zx_xaspcd1_XACMLPolicyQuery_GET_Destination) */
struct zx_str* zx_xaspcd1_XACMLPolicyQuery_GET_Destination(struct zx_xaspcd1_XACMLPolicyQuery_s* x) { return x->Destination; }
/* FUNC(zx_xaspcd1_XACMLPolicyQuery_PUT_Destination) */
void zx_xaspcd1_XACMLPolicyQuery_PUT_Destination(struct zx_xaspcd1_XACMLPolicyQuery_s* x, struct zx_str* y) { x->Destination = y; }
/* FUNC(zx_xaspcd1_XACMLPolicyQuery_GET_ID) */
struct zx_str* zx_xaspcd1_XACMLPolicyQuery_GET_ID(struct zx_xaspcd1_XACMLPolicyQuery_s* x) { return x->ID; }
/* FUNC(zx_xaspcd1_XACMLPolicyQuery_PUT_ID) */
void zx_xaspcd1_XACMLPolicyQuery_PUT_ID(struct zx_xaspcd1_XACMLPolicyQuery_s* x, struct zx_str* y) { x->ID = y; }
/* FUNC(zx_xaspcd1_XACMLPolicyQuery_GET_IssueInstant) */
struct zx_str* zx_xaspcd1_XACMLPolicyQuery_GET_IssueInstant(struct zx_xaspcd1_XACMLPolicyQuery_s* x) { return x->IssueInstant; }
/* FUNC(zx_xaspcd1_XACMLPolicyQuery_PUT_IssueInstant) */
void zx_xaspcd1_XACMLPolicyQuery_PUT_IssueInstant(struct zx_xaspcd1_XACMLPolicyQuery_s* x, struct zx_str* y) { x->IssueInstant = y; }
/* FUNC(zx_xaspcd1_XACMLPolicyQuery_GET_Version) */
struct zx_str* zx_xaspcd1_XACMLPolicyQuery_GET_Version(struct zx_xaspcd1_XACMLPolicyQuery_s* x) { return x->Version; }
/* FUNC(zx_xaspcd1_XACMLPolicyQuery_PUT_Version) */
void zx_xaspcd1_XACMLPolicyQuery_PUT_Version(struct zx_xaspcd1_XACMLPolicyQuery_s* x, struct zx_str* y) { x->Version = y; }





/* EOF -- c/zx-xaspcd1-getput.c */
