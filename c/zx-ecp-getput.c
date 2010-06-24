/* c/zx-ecp-getput.c - WARNING: This file was automatically generated. DO NOT EDIT!
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
#include "c/zx-ecp-data.h"

/* FUNC(zx_ecp_RelayState_GET_actor) */
struct zx_str* zx_ecp_RelayState_GET_actor(struct zx_ecp_RelayState_s* x) { return x->actor; }
/* FUNC(zx_ecp_RelayState_PUT_actor) */
void zx_ecp_RelayState_PUT_actor(struct zx_ecp_RelayState_s* x, struct zx_str* y) { x->actor = y; }
/* FUNC(zx_ecp_RelayState_GET_mustUnderstand) */
struct zx_str* zx_ecp_RelayState_GET_mustUnderstand(struct zx_ecp_RelayState_s* x) { return x->mustUnderstand; }
/* FUNC(zx_ecp_RelayState_PUT_mustUnderstand) */
void zx_ecp_RelayState_PUT_mustUnderstand(struct zx_ecp_RelayState_s* x, struct zx_str* y) { x->mustUnderstand = y; }







#ifdef ZX_ENA_GETPUT

/* FUNC(zx_ecp_Request_NUM_Issuer) */

int zx_ecp_Request_NUM_Issuer(struct zx_ecp_Request_s* x)
{
  struct zx_sa_Issuer_s* y;
  int n = 0;
  if (!x) return 0;
  for (y = x->Issuer; y; ++n, y = (struct zx_sa_Issuer_s*)y->gg.g.n) ;
  return n;
}

/* FUNC(zx_ecp_Request_GET_Issuer) */

struct zx_sa_Issuer_s* zx_ecp_Request_GET_Issuer(struct zx_ecp_Request_s* x, int n)
{
  struct zx_sa_Issuer_s* y;
  if (!x) return 0;
  for (y = x->Issuer; n>=0 && y; --n, y = (struct zx_sa_Issuer_s*)y->gg.g.n) ;
  return y;
}

/* FUNC(zx_ecp_Request_POP_Issuer) */

struct zx_sa_Issuer_s* zx_ecp_Request_POP_Issuer(struct zx_ecp_Request_s* x)
{
  struct zx_sa_Issuer_s* y;
  if (!x) return 0;
  y = x->Issuer;
  if (y)
    x->Issuer = (struct zx_sa_Issuer_s*)y->gg.g.n;
  return y;
}

/* FUNC(zx_ecp_Request_PUSH_Issuer) */

void zx_ecp_Request_PUSH_Issuer(struct zx_ecp_Request_s* x, struct zx_sa_Issuer_s* z)
{
  if (!x || !z) return;
  z->gg.g.n = &x->Issuer->gg.g;
  x->Issuer = z;
}

/* FUNC(zx_ecp_Request_REV_Issuer) */

void zx_ecp_Request_REV_Issuer(struct zx_ecp_Request_s* x)
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

/* FUNC(zx_ecp_Request_PUT_Issuer) */

void zx_ecp_Request_PUT_Issuer(struct zx_ecp_Request_s* x, int n, struct zx_sa_Issuer_s* z)
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

/* FUNC(zx_ecp_Request_ADD_Issuer) */

void zx_ecp_Request_ADD_Issuer(struct zx_ecp_Request_s* x, int n, struct zx_sa_Issuer_s* z)
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

/* FUNC(zx_ecp_Request_DEL_Issuer) */

void zx_ecp_Request_DEL_Issuer(struct zx_ecp_Request_s* x, int n)
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

/* FUNC(zx_ecp_Request_NUM_IDPList) */

int zx_ecp_Request_NUM_IDPList(struct zx_ecp_Request_s* x)
{
  struct zx_sp_IDPList_s* y;
  int n = 0;
  if (!x) return 0;
  for (y = x->IDPList; y; ++n, y = (struct zx_sp_IDPList_s*)y->gg.g.n) ;
  return n;
}

/* FUNC(zx_ecp_Request_GET_IDPList) */

struct zx_sp_IDPList_s* zx_ecp_Request_GET_IDPList(struct zx_ecp_Request_s* x, int n)
{
  struct zx_sp_IDPList_s* y;
  if (!x) return 0;
  for (y = x->IDPList; n>=0 && y; --n, y = (struct zx_sp_IDPList_s*)y->gg.g.n) ;
  return y;
}

/* FUNC(zx_ecp_Request_POP_IDPList) */

struct zx_sp_IDPList_s* zx_ecp_Request_POP_IDPList(struct zx_ecp_Request_s* x)
{
  struct zx_sp_IDPList_s* y;
  if (!x) return 0;
  y = x->IDPList;
  if (y)
    x->IDPList = (struct zx_sp_IDPList_s*)y->gg.g.n;
  return y;
}

/* FUNC(zx_ecp_Request_PUSH_IDPList) */

void zx_ecp_Request_PUSH_IDPList(struct zx_ecp_Request_s* x, struct zx_sp_IDPList_s* z)
{
  if (!x || !z) return;
  z->gg.g.n = &x->IDPList->gg.g;
  x->IDPList = z;
}

/* FUNC(zx_ecp_Request_REV_IDPList) */

void zx_ecp_Request_REV_IDPList(struct zx_ecp_Request_s* x)
{
  struct zx_sp_IDPList_s* nxt;
  struct zx_sp_IDPList_s* y;
  if (!x) return;
  y = x->IDPList;
  if (!y) return;
  x->IDPList = 0;
  while (y) {
    nxt = (struct zx_sp_IDPList_s*)y->gg.g.n;
    y->gg.g.n = &x->IDPList->gg.g;
    x->IDPList = y;
    y = nxt;
  }
}

/* FUNC(zx_ecp_Request_PUT_IDPList) */

void zx_ecp_Request_PUT_IDPList(struct zx_ecp_Request_s* x, int n, struct zx_sp_IDPList_s* z)
{
  struct zx_sp_IDPList_s* y;
  if (!x || !z) return;
  y = x->IDPList;
  if (!y) return;
  switch (n) {
  case 0:
    z->gg.g.n = y->gg.g.n;
    x->IDPList = z;
    return;
  default:
    for (; n > 1 && y->gg.g.n; --n, y = (struct zx_sp_IDPList_s*)y->gg.g.n) ;
    if (!y->gg.g.n) return;
    z->gg.g.n = y->gg.g.n->n;
    y->gg.g.n = &z->gg.g;
  }
}

/* FUNC(zx_ecp_Request_ADD_IDPList) */

void zx_ecp_Request_ADD_IDPList(struct zx_ecp_Request_s* x, int n, struct zx_sp_IDPList_s* z)
{
  struct zx_sp_IDPList_s* y;
  if (!x || !z) return;
  switch (n) {
  case 0:
  add_to_start:
    z->gg.g.n = &x->IDPList->gg.g;
    x->IDPList = z;
    return;
  case -1:
    y = x->IDPList;
    if (!y) goto add_to_start;
    for (; y->gg.g.n; y = (struct zx_sp_IDPList_s*)y->gg.g.n) ;
    break;
  default:
    for (y = x->IDPList; n > 1 && y; --n, y = (struct zx_sp_IDPList_s*)y->gg.g.n) ;
    if (!y) return;
  }
  z->gg.g.n = y->gg.g.n;
  y->gg.g.n = &z->gg.g;
}

/* FUNC(zx_ecp_Request_DEL_IDPList) */

void zx_ecp_Request_DEL_IDPList(struct zx_ecp_Request_s* x, int n)
{
  struct zx_sp_IDPList_s* y;
  if (!x) return;
  switch (n) {
  case 0:
    x->IDPList = (struct zx_sp_IDPList_s*)x->IDPList->gg.g.n;
    return;
  case -1:
    y = (struct zx_sp_IDPList_s*)x->IDPList;
    if (!y) return;
    for (; y->gg.g.n; y = (struct zx_sp_IDPList_s*)y->gg.g.n) ;
    break;
  default:
    for (y = x->IDPList; n > 1 && y->gg.g.n; --n, y = (struct zx_sp_IDPList_s*)y->gg.g.n) ;
    if (!y->gg.g.n) return;
  }
  y->gg.g.n = y->gg.g.n->n;
}

#endif

/* FUNC(zx_ecp_Request_GET_IsPassive) */
struct zx_str* zx_ecp_Request_GET_IsPassive(struct zx_ecp_Request_s* x) { return x->IsPassive; }
/* FUNC(zx_ecp_Request_PUT_IsPassive) */
void zx_ecp_Request_PUT_IsPassive(struct zx_ecp_Request_s* x, struct zx_str* y) { x->IsPassive = y; }
/* FUNC(zx_ecp_Request_GET_ProviderName) */
struct zx_str* zx_ecp_Request_GET_ProviderName(struct zx_ecp_Request_s* x) { return x->ProviderName; }
/* FUNC(zx_ecp_Request_PUT_ProviderName) */
void zx_ecp_Request_PUT_ProviderName(struct zx_ecp_Request_s* x, struct zx_str* y) { x->ProviderName = y; }
/* FUNC(zx_ecp_Request_GET_actor) */
struct zx_str* zx_ecp_Request_GET_actor(struct zx_ecp_Request_s* x) { return x->actor; }
/* FUNC(zx_ecp_Request_PUT_actor) */
void zx_ecp_Request_PUT_actor(struct zx_ecp_Request_s* x, struct zx_str* y) { x->actor = y; }
/* FUNC(zx_ecp_Request_GET_mustUnderstand) */
struct zx_str* zx_ecp_Request_GET_mustUnderstand(struct zx_ecp_Request_s* x) { return x->mustUnderstand; }
/* FUNC(zx_ecp_Request_PUT_mustUnderstand) */
void zx_ecp_Request_PUT_mustUnderstand(struct zx_ecp_Request_s* x, struct zx_str* y) { x->mustUnderstand = y; }





/* FUNC(zx_ecp_Response_GET_AssertionConsumerServiceURL) */
struct zx_str* zx_ecp_Response_GET_AssertionConsumerServiceURL(struct zx_ecp_Response_s* x) { return x->AssertionConsumerServiceURL; }
/* FUNC(zx_ecp_Response_PUT_AssertionConsumerServiceURL) */
void zx_ecp_Response_PUT_AssertionConsumerServiceURL(struct zx_ecp_Response_s* x, struct zx_str* y) { x->AssertionConsumerServiceURL = y; }
/* FUNC(zx_ecp_Response_GET_actor) */
struct zx_str* zx_ecp_Response_GET_actor(struct zx_ecp_Response_s* x) { return x->actor; }
/* FUNC(zx_ecp_Response_PUT_actor) */
void zx_ecp_Response_PUT_actor(struct zx_ecp_Response_s* x, struct zx_str* y) { x->actor = y; }
/* FUNC(zx_ecp_Response_GET_mustUnderstand) */
struct zx_str* zx_ecp_Response_GET_mustUnderstand(struct zx_ecp_Response_s* x) { return x->mustUnderstand; }
/* FUNC(zx_ecp_Response_PUT_mustUnderstand) */
void zx_ecp_Response_PUT_mustUnderstand(struct zx_ecp_Response_s* x, struct zx_str* y) { x->mustUnderstand = y; }





/* EOF -- c/zx-ecp-getput.c */
