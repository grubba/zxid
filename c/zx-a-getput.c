/* c/zx-a-getput.c - WARNING: This file was automatically generated. DO NOT EDIT!
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
#include "c/zx-a-data.h"

/* FUNC(zx_a_Action_GET_ID) */
struct zx_str* zx_a_Action_GET_ID(struct zx_a_Action_s* x) { return x->ID; }
/* FUNC(zx_a_Action_PUT_ID) */
void zx_a_Action_PUT_ID(struct zx_a_Action_s* x, struct zx_str* y) { x->ID = y; }
/* FUNC(zx_a_Action_GET_id) */
struct zx_str* zx_a_Action_GET_id(struct zx_a_Action_s* x) { return x->id; }
/* FUNC(zx_a_Action_PUT_id) */
void zx_a_Action_PUT_id(struct zx_a_Action_s* x, struct zx_str* y) { x->id = y; }
/* FUNC(zx_a_Action_GET_Id) */
struct zx_str* zx_a_Action_GET_Id(struct zx_a_Action_s* x) { return x->Id; }
/* FUNC(zx_a_Action_PUT_Id) */
void zx_a_Action_PUT_Id(struct zx_a_Action_s* x, struct zx_str* y) { x->Id = y; }
/* FUNC(zx_a_Action_GET_actor) */
struct zx_str* zx_a_Action_GET_actor(struct zx_a_Action_s* x) { return x->actor; }
/* FUNC(zx_a_Action_PUT_actor) */
void zx_a_Action_PUT_actor(struct zx_a_Action_s* x, struct zx_str* y) { x->actor = y; }
/* FUNC(zx_a_Action_GET_mustUnderstand) */
struct zx_str* zx_a_Action_GET_mustUnderstand(struct zx_a_Action_s* x) { return x->mustUnderstand; }
/* FUNC(zx_a_Action_PUT_mustUnderstand) */
void zx_a_Action_PUT_mustUnderstand(struct zx_a_Action_s* x, struct zx_str* y) { x->mustUnderstand = y; }





/* FUNC(zx_a_Address_GET_ID) */
struct zx_str* zx_a_Address_GET_ID(struct zx_a_Address_s* x) { return x->ID; }
/* FUNC(zx_a_Address_PUT_ID) */
void zx_a_Address_PUT_ID(struct zx_a_Address_s* x, struct zx_str* y) { x->ID = y; }
/* FUNC(zx_a_Address_GET_id) */
struct zx_str* zx_a_Address_GET_id(struct zx_a_Address_s* x) { return x->id; }
/* FUNC(zx_a_Address_PUT_id) */
void zx_a_Address_PUT_id(struct zx_a_Address_s* x, struct zx_str* y) { x->id = y; }
/* FUNC(zx_a_Address_GET_Id) */
struct zx_str* zx_a_Address_GET_Id(struct zx_a_Address_s* x) { return x->Id; }
/* FUNC(zx_a_Address_PUT_Id) */
void zx_a_Address_PUT_Id(struct zx_a_Address_s* x, struct zx_str* y) { x->Id = y; }
/* FUNC(zx_a_Address_GET_actor) */
struct zx_str* zx_a_Address_GET_actor(struct zx_a_Address_s* x) { return x->actor; }
/* FUNC(zx_a_Address_PUT_actor) */
void zx_a_Address_PUT_actor(struct zx_a_Address_s* x, struct zx_str* y) { x->actor = y; }
/* FUNC(zx_a_Address_GET_mustUnderstand) */
struct zx_str* zx_a_Address_GET_mustUnderstand(struct zx_a_Address_s* x) { return x->mustUnderstand; }
/* FUNC(zx_a_Address_PUT_mustUnderstand) */
void zx_a_Address_PUT_mustUnderstand(struct zx_a_Address_s* x, struct zx_str* y) { x->mustUnderstand = y; }







#ifdef ZX_ENA_GETPUT

/* FUNC(zx_a_EndpointReference_NUM_Address) */

int zx_a_EndpointReference_NUM_Address(struct zx_a_EndpointReference_s* x)
{
  struct zx_a_Address_s* y;
  int n = 0;
  if (!x) return 0;
  for (y = x->Address; y; ++n, y = (struct zx_a_Address_s*)y->gg.g.n) ;
  return n;
}

/* FUNC(zx_a_EndpointReference_GET_Address) */

struct zx_a_Address_s* zx_a_EndpointReference_GET_Address(struct zx_a_EndpointReference_s* x, int n)
{
  struct zx_a_Address_s* y;
  if (!x) return 0;
  for (y = x->Address; n>=0 && y; --n, y = (struct zx_a_Address_s*)y->gg.g.n) ;
  return y;
}

/* FUNC(zx_a_EndpointReference_POP_Address) */

struct zx_a_Address_s* zx_a_EndpointReference_POP_Address(struct zx_a_EndpointReference_s* x)
{
  struct zx_a_Address_s* y;
  if (!x) return 0;
  y = x->Address;
  if (y)
    x->Address = (struct zx_a_Address_s*)y->gg.g.n;
  return y;
}

/* FUNC(zx_a_EndpointReference_PUSH_Address) */

void zx_a_EndpointReference_PUSH_Address(struct zx_a_EndpointReference_s* x, struct zx_a_Address_s* z)
{
  if (!x || !z) return;
  z->gg.g.n = &x->Address->gg.g;
  x->Address = z;
}

/* FUNC(zx_a_EndpointReference_REV_Address) */

void zx_a_EndpointReference_REV_Address(struct zx_a_EndpointReference_s* x)
{
  struct zx_a_Address_s* nxt;
  struct zx_a_Address_s* y;
  if (!x) return;
  y = x->Address;
  if (!y) return;
  x->Address = 0;
  while (y) {
    nxt = (struct zx_a_Address_s*)y->gg.g.n;
    y->gg.g.n = &x->Address->gg.g;
    x->Address = y;
    y = nxt;
  }
}

/* FUNC(zx_a_EndpointReference_PUT_Address) */

void zx_a_EndpointReference_PUT_Address(struct zx_a_EndpointReference_s* x, int n, struct zx_a_Address_s* z)
{
  struct zx_a_Address_s* y;
  if (!x || !z) return;
  y = x->Address;
  if (!y) return;
  switch (n) {
  case 0:
    z->gg.g.n = y->gg.g.n;
    x->Address = z;
    return;
  default:
    for (; n > 1 && y->gg.g.n; --n, y = (struct zx_a_Address_s*)y->gg.g.n) ;
    if (!y->gg.g.n) return;
    z->gg.g.n = y->gg.g.n->n;
    y->gg.g.n = &z->gg.g;
  }
}

/* FUNC(zx_a_EndpointReference_ADD_Address) */

void zx_a_EndpointReference_ADD_Address(struct zx_a_EndpointReference_s* x, int n, struct zx_a_Address_s* z)
{
  struct zx_a_Address_s* y;
  if (!x || !z) return;
  switch (n) {
  case 0:
  add_to_start:
    z->gg.g.n = &x->Address->gg.g;
    x->Address = z;
    return;
  case -1:
    y = x->Address;
    if (!y) goto add_to_start;
    for (; y->gg.g.n; y = (struct zx_a_Address_s*)y->gg.g.n) ;
    break;
  default:
    for (y = x->Address; n > 1 && y; --n, y = (struct zx_a_Address_s*)y->gg.g.n) ;
    if (!y) return;
  }
  z->gg.g.n = y->gg.g.n;
  y->gg.g.n = &z->gg.g;
}

/* FUNC(zx_a_EndpointReference_DEL_Address) */

void zx_a_EndpointReference_DEL_Address(struct zx_a_EndpointReference_s* x, int n)
{
  struct zx_a_Address_s* y;
  if (!x) return;
  switch (n) {
  case 0:
    x->Address = (struct zx_a_Address_s*)x->Address->gg.g.n;
    return;
  case -1:
    y = (struct zx_a_Address_s*)x->Address;
    if (!y) return;
    for (; y->gg.g.n; y = (struct zx_a_Address_s*)y->gg.g.n) ;
    break;
  default:
    for (y = x->Address; n > 1 && y->gg.g.n; --n, y = (struct zx_a_Address_s*)y->gg.g.n) ;
    if (!y->gg.g.n) return;
  }
  y->gg.g.n = y->gg.g.n->n;
}

#endif



#ifdef ZX_ENA_GETPUT

/* FUNC(zx_a_EndpointReference_NUM_ReferenceParameters) */

int zx_a_EndpointReference_NUM_ReferenceParameters(struct zx_a_EndpointReference_s* x)
{
  struct zx_a_ReferenceParameters_s* y;
  int n = 0;
  if (!x) return 0;
  for (y = x->ReferenceParameters; y; ++n, y = (struct zx_a_ReferenceParameters_s*)y->gg.g.n) ;
  return n;
}

/* FUNC(zx_a_EndpointReference_GET_ReferenceParameters) */

struct zx_a_ReferenceParameters_s* zx_a_EndpointReference_GET_ReferenceParameters(struct zx_a_EndpointReference_s* x, int n)
{
  struct zx_a_ReferenceParameters_s* y;
  if (!x) return 0;
  for (y = x->ReferenceParameters; n>=0 && y; --n, y = (struct zx_a_ReferenceParameters_s*)y->gg.g.n) ;
  return y;
}

/* FUNC(zx_a_EndpointReference_POP_ReferenceParameters) */

struct zx_a_ReferenceParameters_s* zx_a_EndpointReference_POP_ReferenceParameters(struct zx_a_EndpointReference_s* x)
{
  struct zx_a_ReferenceParameters_s* y;
  if (!x) return 0;
  y = x->ReferenceParameters;
  if (y)
    x->ReferenceParameters = (struct zx_a_ReferenceParameters_s*)y->gg.g.n;
  return y;
}

/* FUNC(zx_a_EndpointReference_PUSH_ReferenceParameters) */

void zx_a_EndpointReference_PUSH_ReferenceParameters(struct zx_a_EndpointReference_s* x, struct zx_a_ReferenceParameters_s* z)
{
  if (!x || !z) return;
  z->gg.g.n = &x->ReferenceParameters->gg.g;
  x->ReferenceParameters = z;
}

/* FUNC(zx_a_EndpointReference_REV_ReferenceParameters) */

void zx_a_EndpointReference_REV_ReferenceParameters(struct zx_a_EndpointReference_s* x)
{
  struct zx_a_ReferenceParameters_s* nxt;
  struct zx_a_ReferenceParameters_s* y;
  if (!x) return;
  y = x->ReferenceParameters;
  if (!y) return;
  x->ReferenceParameters = 0;
  while (y) {
    nxt = (struct zx_a_ReferenceParameters_s*)y->gg.g.n;
    y->gg.g.n = &x->ReferenceParameters->gg.g;
    x->ReferenceParameters = y;
    y = nxt;
  }
}

/* FUNC(zx_a_EndpointReference_PUT_ReferenceParameters) */

void zx_a_EndpointReference_PUT_ReferenceParameters(struct zx_a_EndpointReference_s* x, int n, struct zx_a_ReferenceParameters_s* z)
{
  struct zx_a_ReferenceParameters_s* y;
  if (!x || !z) return;
  y = x->ReferenceParameters;
  if (!y) return;
  switch (n) {
  case 0:
    z->gg.g.n = y->gg.g.n;
    x->ReferenceParameters = z;
    return;
  default:
    for (; n > 1 && y->gg.g.n; --n, y = (struct zx_a_ReferenceParameters_s*)y->gg.g.n) ;
    if (!y->gg.g.n) return;
    z->gg.g.n = y->gg.g.n->n;
    y->gg.g.n = &z->gg.g;
  }
}

/* FUNC(zx_a_EndpointReference_ADD_ReferenceParameters) */

void zx_a_EndpointReference_ADD_ReferenceParameters(struct zx_a_EndpointReference_s* x, int n, struct zx_a_ReferenceParameters_s* z)
{
  struct zx_a_ReferenceParameters_s* y;
  if (!x || !z) return;
  switch (n) {
  case 0:
  add_to_start:
    z->gg.g.n = &x->ReferenceParameters->gg.g;
    x->ReferenceParameters = z;
    return;
  case -1:
    y = x->ReferenceParameters;
    if (!y) goto add_to_start;
    for (; y->gg.g.n; y = (struct zx_a_ReferenceParameters_s*)y->gg.g.n) ;
    break;
  default:
    for (y = x->ReferenceParameters; n > 1 && y; --n, y = (struct zx_a_ReferenceParameters_s*)y->gg.g.n) ;
    if (!y) return;
  }
  z->gg.g.n = y->gg.g.n;
  y->gg.g.n = &z->gg.g;
}

/* FUNC(zx_a_EndpointReference_DEL_ReferenceParameters) */

void zx_a_EndpointReference_DEL_ReferenceParameters(struct zx_a_EndpointReference_s* x, int n)
{
  struct zx_a_ReferenceParameters_s* y;
  if (!x) return;
  switch (n) {
  case 0:
    x->ReferenceParameters = (struct zx_a_ReferenceParameters_s*)x->ReferenceParameters->gg.g.n;
    return;
  case -1:
    y = (struct zx_a_ReferenceParameters_s*)x->ReferenceParameters;
    if (!y) return;
    for (; y->gg.g.n; y = (struct zx_a_ReferenceParameters_s*)y->gg.g.n) ;
    break;
  default:
    for (y = x->ReferenceParameters; n > 1 && y->gg.g.n; --n, y = (struct zx_a_ReferenceParameters_s*)y->gg.g.n) ;
    if (!y->gg.g.n) return;
  }
  y->gg.g.n = y->gg.g.n->n;
}

#endif



#ifdef ZX_ENA_GETPUT

/* FUNC(zx_a_EndpointReference_NUM_Metadata) */

int zx_a_EndpointReference_NUM_Metadata(struct zx_a_EndpointReference_s* x)
{
  struct zx_a_Metadata_s* y;
  int n = 0;
  if (!x) return 0;
  for (y = x->Metadata; y; ++n, y = (struct zx_a_Metadata_s*)y->gg.g.n) ;
  return n;
}

/* FUNC(zx_a_EndpointReference_GET_Metadata) */

struct zx_a_Metadata_s* zx_a_EndpointReference_GET_Metadata(struct zx_a_EndpointReference_s* x, int n)
{
  struct zx_a_Metadata_s* y;
  if (!x) return 0;
  for (y = x->Metadata; n>=0 && y; --n, y = (struct zx_a_Metadata_s*)y->gg.g.n) ;
  return y;
}

/* FUNC(zx_a_EndpointReference_POP_Metadata) */

struct zx_a_Metadata_s* zx_a_EndpointReference_POP_Metadata(struct zx_a_EndpointReference_s* x)
{
  struct zx_a_Metadata_s* y;
  if (!x) return 0;
  y = x->Metadata;
  if (y)
    x->Metadata = (struct zx_a_Metadata_s*)y->gg.g.n;
  return y;
}

/* FUNC(zx_a_EndpointReference_PUSH_Metadata) */

void zx_a_EndpointReference_PUSH_Metadata(struct zx_a_EndpointReference_s* x, struct zx_a_Metadata_s* z)
{
  if (!x || !z) return;
  z->gg.g.n = &x->Metadata->gg.g;
  x->Metadata = z;
}

/* FUNC(zx_a_EndpointReference_REV_Metadata) */

void zx_a_EndpointReference_REV_Metadata(struct zx_a_EndpointReference_s* x)
{
  struct zx_a_Metadata_s* nxt;
  struct zx_a_Metadata_s* y;
  if (!x) return;
  y = x->Metadata;
  if (!y) return;
  x->Metadata = 0;
  while (y) {
    nxt = (struct zx_a_Metadata_s*)y->gg.g.n;
    y->gg.g.n = &x->Metadata->gg.g;
    x->Metadata = y;
    y = nxt;
  }
}

/* FUNC(zx_a_EndpointReference_PUT_Metadata) */

void zx_a_EndpointReference_PUT_Metadata(struct zx_a_EndpointReference_s* x, int n, struct zx_a_Metadata_s* z)
{
  struct zx_a_Metadata_s* y;
  if (!x || !z) return;
  y = x->Metadata;
  if (!y) return;
  switch (n) {
  case 0:
    z->gg.g.n = y->gg.g.n;
    x->Metadata = z;
    return;
  default:
    for (; n > 1 && y->gg.g.n; --n, y = (struct zx_a_Metadata_s*)y->gg.g.n) ;
    if (!y->gg.g.n) return;
    z->gg.g.n = y->gg.g.n->n;
    y->gg.g.n = &z->gg.g;
  }
}

/* FUNC(zx_a_EndpointReference_ADD_Metadata) */

void zx_a_EndpointReference_ADD_Metadata(struct zx_a_EndpointReference_s* x, int n, struct zx_a_Metadata_s* z)
{
  struct zx_a_Metadata_s* y;
  if (!x || !z) return;
  switch (n) {
  case 0:
  add_to_start:
    z->gg.g.n = &x->Metadata->gg.g;
    x->Metadata = z;
    return;
  case -1:
    y = x->Metadata;
    if (!y) goto add_to_start;
    for (; y->gg.g.n; y = (struct zx_a_Metadata_s*)y->gg.g.n) ;
    break;
  default:
    for (y = x->Metadata; n > 1 && y; --n, y = (struct zx_a_Metadata_s*)y->gg.g.n) ;
    if (!y) return;
  }
  z->gg.g.n = y->gg.g.n;
  y->gg.g.n = &z->gg.g;
}

/* FUNC(zx_a_EndpointReference_DEL_Metadata) */

void zx_a_EndpointReference_DEL_Metadata(struct zx_a_EndpointReference_s* x, int n)
{
  struct zx_a_Metadata_s* y;
  if (!x) return;
  switch (n) {
  case 0:
    x->Metadata = (struct zx_a_Metadata_s*)x->Metadata->gg.g.n;
    return;
  case -1:
    y = (struct zx_a_Metadata_s*)x->Metadata;
    if (!y) return;
    for (; y->gg.g.n; y = (struct zx_a_Metadata_s*)y->gg.g.n) ;
    break;
  default:
    for (y = x->Metadata; n > 1 && y->gg.g.n; --n, y = (struct zx_a_Metadata_s*)y->gg.g.n) ;
    if (!y->gg.g.n) return;
  }
  y->gg.g.n = y->gg.g.n->n;
}

#endif

/* FUNC(zx_a_EndpointReference_GET_ID) */
struct zx_str* zx_a_EndpointReference_GET_ID(struct zx_a_EndpointReference_s* x) { return x->ID; }
/* FUNC(zx_a_EndpointReference_PUT_ID) */
void zx_a_EndpointReference_PUT_ID(struct zx_a_EndpointReference_s* x, struct zx_str* y) { x->ID = y; }
/* FUNC(zx_a_EndpointReference_GET_id) */
struct zx_str* zx_a_EndpointReference_GET_id(struct zx_a_EndpointReference_s* x) { return x->id; }
/* FUNC(zx_a_EndpointReference_PUT_id) */
void zx_a_EndpointReference_PUT_id(struct zx_a_EndpointReference_s* x, struct zx_str* y) { x->id = y; }
/* FUNC(zx_a_EndpointReference_GET_notOnOrAfter) */
struct zx_str* zx_a_EndpointReference_GET_notOnOrAfter(struct zx_a_EndpointReference_s* x) { return x->notOnOrAfter; }
/* FUNC(zx_a_EndpointReference_PUT_notOnOrAfter) */
void zx_a_EndpointReference_PUT_notOnOrAfter(struct zx_a_EndpointReference_s* x, struct zx_str* y) { x->notOnOrAfter = y; }
/* FUNC(zx_a_EndpointReference_GET_Id) */
struct zx_str* zx_a_EndpointReference_GET_Id(struct zx_a_EndpointReference_s* x) { return x->Id; }
/* FUNC(zx_a_EndpointReference_PUT_Id) */
void zx_a_EndpointReference_PUT_Id(struct zx_a_EndpointReference_s* x, struct zx_str* y) { x->Id = y; }
/* FUNC(zx_a_EndpointReference_GET_actor) */
struct zx_str* zx_a_EndpointReference_GET_actor(struct zx_a_EndpointReference_s* x) { return x->actor; }
/* FUNC(zx_a_EndpointReference_PUT_actor) */
void zx_a_EndpointReference_PUT_actor(struct zx_a_EndpointReference_s* x, struct zx_str* y) { x->actor = y; }
/* FUNC(zx_a_EndpointReference_GET_mustUnderstand) */
struct zx_str* zx_a_EndpointReference_GET_mustUnderstand(struct zx_a_EndpointReference_s* x) { return x->mustUnderstand; }
/* FUNC(zx_a_EndpointReference_PUT_mustUnderstand) */
void zx_a_EndpointReference_PUT_mustUnderstand(struct zx_a_EndpointReference_s* x, struct zx_str* y) { x->mustUnderstand = y; }







#ifdef ZX_ENA_GETPUT

/* FUNC(zx_a_FaultTo_NUM_Address) */

int zx_a_FaultTo_NUM_Address(struct zx_a_FaultTo_s* x)
{
  struct zx_a_Address_s* y;
  int n = 0;
  if (!x) return 0;
  for (y = x->Address; y; ++n, y = (struct zx_a_Address_s*)y->gg.g.n) ;
  return n;
}

/* FUNC(zx_a_FaultTo_GET_Address) */

struct zx_a_Address_s* zx_a_FaultTo_GET_Address(struct zx_a_FaultTo_s* x, int n)
{
  struct zx_a_Address_s* y;
  if (!x) return 0;
  for (y = x->Address; n>=0 && y; --n, y = (struct zx_a_Address_s*)y->gg.g.n) ;
  return y;
}

/* FUNC(zx_a_FaultTo_POP_Address) */

struct zx_a_Address_s* zx_a_FaultTo_POP_Address(struct zx_a_FaultTo_s* x)
{
  struct zx_a_Address_s* y;
  if (!x) return 0;
  y = x->Address;
  if (y)
    x->Address = (struct zx_a_Address_s*)y->gg.g.n;
  return y;
}

/* FUNC(zx_a_FaultTo_PUSH_Address) */

void zx_a_FaultTo_PUSH_Address(struct zx_a_FaultTo_s* x, struct zx_a_Address_s* z)
{
  if (!x || !z) return;
  z->gg.g.n = &x->Address->gg.g;
  x->Address = z;
}

/* FUNC(zx_a_FaultTo_REV_Address) */

void zx_a_FaultTo_REV_Address(struct zx_a_FaultTo_s* x)
{
  struct zx_a_Address_s* nxt;
  struct zx_a_Address_s* y;
  if (!x) return;
  y = x->Address;
  if (!y) return;
  x->Address = 0;
  while (y) {
    nxt = (struct zx_a_Address_s*)y->gg.g.n;
    y->gg.g.n = &x->Address->gg.g;
    x->Address = y;
    y = nxt;
  }
}

/* FUNC(zx_a_FaultTo_PUT_Address) */

void zx_a_FaultTo_PUT_Address(struct zx_a_FaultTo_s* x, int n, struct zx_a_Address_s* z)
{
  struct zx_a_Address_s* y;
  if (!x || !z) return;
  y = x->Address;
  if (!y) return;
  switch (n) {
  case 0:
    z->gg.g.n = y->gg.g.n;
    x->Address = z;
    return;
  default:
    for (; n > 1 && y->gg.g.n; --n, y = (struct zx_a_Address_s*)y->gg.g.n) ;
    if (!y->gg.g.n) return;
    z->gg.g.n = y->gg.g.n->n;
    y->gg.g.n = &z->gg.g;
  }
}

/* FUNC(zx_a_FaultTo_ADD_Address) */

void zx_a_FaultTo_ADD_Address(struct zx_a_FaultTo_s* x, int n, struct zx_a_Address_s* z)
{
  struct zx_a_Address_s* y;
  if (!x || !z) return;
  switch (n) {
  case 0:
  add_to_start:
    z->gg.g.n = &x->Address->gg.g;
    x->Address = z;
    return;
  case -1:
    y = x->Address;
    if (!y) goto add_to_start;
    for (; y->gg.g.n; y = (struct zx_a_Address_s*)y->gg.g.n) ;
    break;
  default:
    for (y = x->Address; n > 1 && y; --n, y = (struct zx_a_Address_s*)y->gg.g.n) ;
    if (!y) return;
  }
  z->gg.g.n = y->gg.g.n;
  y->gg.g.n = &z->gg.g;
}

/* FUNC(zx_a_FaultTo_DEL_Address) */

void zx_a_FaultTo_DEL_Address(struct zx_a_FaultTo_s* x, int n)
{
  struct zx_a_Address_s* y;
  if (!x) return;
  switch (n) {
  case 0:
    x->Address = (struct zx_a_Address_s*)x->Address->gg.g.n;
    return;
  case -1:
    y = (struct zx_a_Address_s*)x->Address;
    if (!y) return;
    for (; y->gg.g.n; y = (struct zx_a_Address_s*)y->gg.g.n) ;
    break;
  default:
    for (y = x->Address; n > 1 && y->gg.g.n; --n, y = (struct zx_a_Address_s*)y->gg.g.n) ;
    if (!y->gg.g.n) return;
  }
  y->gg.g.n = y->gg.g.n->n;
}

#endif



#ifdef ZX_ENA_GETPUT

/* FUNC(zx_a_FaultTo_NUM_ReferenceParameters) */

int zx_a_FaultTo_NUM_ReferenceParameters(struct zx_a_FaultTo_s* x)
{
  struct zx_a_ReferenceParameters_s* y;
  int n = 0;
  if (!x) return 0;
  for (y = x->ReferenceParameters; y; ++n, y = (struct zx_a_ReferenceParameters_s*)y->gg.g.n) ;
  return n;
}

/* FUNC(zx_a_FaultTo_GET_ReferenceParameters) */

struct zx_a_ReferenceParameters_s* zx_a_FaultTo_GET_ReferenceParameters(struct zx_a_FaultTo_s* x, int n)
{
  struct zx_a_ReferenceParameters_s* y;
  if (!x) return 0;
  for (y = x->ReferenceParameters; n>=0 && y; --n, y = (struct zx_a_ReferenceParameters_s*)y->gg.g.n) ;
  return y;
}

/* FUNC(zx_a_FaultTo_POP_ReferenceParameters) */

struct zx_a_ReferenceParameters_s* zx_a_FaultTo_POP_ReferenceParameters(struct zx_a_FaultTo_s* x)
{
  struct zx_a_ReferenceParameters_s* y;
  if (!x) return 0;
  y = x->ReferenceParameters;
  if (y)
    x->ReferenceParameters = (struct zx_a_ReferenceParameters_s*)y->gg.g.n;
  return y;
}

/* FUNC(zx_a_FaultTo_PUSH_ReferenceParameters) */

void zx_a_FaultTo_PUSH_ReferenceParameters(struct zx_a_FaultTo_s* x, struct zx_a_ReferenceParameters_s* z)
{
  if (!x || !z) return;
  z->gg.g.n = &x->ReferenceParameters->gg.g;
  x->ReferenceParameters = z;
}

/* FUNC(zx_a_FaultTo_REV_ReferenceParameters) */

void zx_a_FaultTo_REV_ReferenceParameters(struct zx_a_FaultTo_s* x)
{
  struct zx_a_ReferenceParameters_s* nxt;
  struct zx_a_ReferenceParameters_s* y;
  if (!x) return;
  y = x->ReferenceParameters;
  if (!y) return;
  x->ReferenceParameters = 0;
  while (y) {
    nxt = (struct zx_a_ReferenceParameters_s*)y->gg.g.n;
    y->gg.g.n = &x->ReferenceParameters->gg.g;
    x->ReferenceParameters = y;
    y = nxt;
  }
}

/* FUNC(zx_a_FaultTo_PUT_ReferenceParameters) */

void zx_a_FaultTo_PUT_ReferenceParameters(struct zx_a_FaultTo_s* x, int n, struct zx_a_ReferenceParameters_s* z)
{
  struct zx_a_ReferenceParameters_s* y;
  if (!x || !z) return;
  y = x->ReferenceParameters;
  if (!y) return;
  switch (n) {
  case 0:
    z->gg.g.n = y->gg.g.n;
    x->ReferenceParameters = z;
    return;
  default:
    for (; n > 1 && y->gg.g.n; --n, y = (struct zx_a_ReferenceParameters_s*)y->gg.g.n) ;
    if (!y->gg.g.n) return;
    z->gg.g.n = y->gg.g.n->n;
    y->gg.g.n = &z->gg.g;
  }
}

/* FUNC(zx_a_FaultTo_ADD_ReferenceParameters) */

void zx_a_FaultTo_ADD_ReferenceParameters(struct zx_a_FaultTo_s* x, int n, struct zx_a_ReferenceParameters_s* z)
{
  struct zx_a_ReferenceParameters_s* y;
  if (!x || !z) return;
  switch (n) {
  case 0:
  add_to_start:
    z->gg.g.n = &x->ReferenceParameters->gg.g;
    x->ReferenceParameters = z;
    return;
  case -1:
    y = x->ReferenceParameters;
    if (!y) goto add_to_start;
    for (; y->gg.g.n; y = (struct zx_a_ReferenceParameters_s*)y->gg.g.n) ;
    break;
  default:
    for (y = x->ReferenceParameters; n > 1 && y; --n, y = (struct zx_a_ReferenceParameters_s*)y->gg.g.n) ;
    if (!y) return;
  }
  z->gg.g.n = y->gg.g.n;
  y->gg.g.n = &z->gg.g;
}

/* FUNC(zx_a_FaultTo_DEL_ReferenceParameters) */

void zx_a_FaultTo_DEL_ReferenceParameters(struct zx_a_FaultTo_s* x, int n)
{
  struct zx_a_ReferenceParameters_s* y;
  if (!x) return;
  switch (n) {
  case 0:
    x->ReferenceParameters = (struct zx_a_ReferenceParameters_s*)x->ReferenceParameters->gg.g.n;
    return;
  case -1:
    y = (struct zx_a_ReferenceParameters_s*)x->ReferenceParameters;
    if (!y) return;
    for (; y->gg.g.n; y = (struct zx_a_ReferenceParameters_s*)y->gg.g.n) ;
    break;
  default:
    for (y = x->ReferenceParameters; n > 1 && y->gg.g.n; --n, y = (struct zx_a_ReferenceParameters_s*)y->gg.g.n) ;
    if (!y->gg.g.n) return;
  }
  y->gg.g.n = y->gg.g.n->n;
}

#endif



#ifdef ZX_ENA_GETPUT

/* FUNC(zx_a_FaultTo_NUM_Metadata) */

int zx_a_FaultTo_NUM_Metadata(struct zx_a_FaultTo_s* x)
{
  struct zx_a_Metadata_s* y;
  int n = 0;
  if (!x) return 0;
  for (y = x->Metadata; y; ++n, y = (struct zx_a_Metadata_s*)y->gg.g.n) ;
  return n;
}

/* FUNC(zx_a_FaultTo_GET_Metadata) */

struct zx_a_Metadata_s* zx_a_FaultTo_GET_Metadata(struct zx_a_FaultTo_s* x, int n)
{
  struct zx_a_Metadata_s* y;
  if (!x) return 0;
  for (y = x->Metadata; n>=0 && y; --n, y = (struct zx_a_Metadata_s*)y->gg.g.n) ;
  return y;
}

/* FUNC(zx_a_FaultTo_POP_Metadata) */

struct zx_a_Metadata_s* zx_a_FaultTo_POP_Metadata(struct zx_a_FaultTo_s* x)
{
  struct zx_a_Metadata_s* y;
  if (!x) return 0;
  y = x->Metadata;
  if (y)
    x->Metadata = (struct zx_a_Metadata_s*)y->gg.g.n;
  return y;
}

/* FUNC(zx_a_FaultTo_PUSH_Metadata) */

void zx_a_FaultTo_PUSH_Metadata(struct zx_a_FaultTo_s* x, struct zx_a_Metadata_s* z)
{
  if (!x || !z) return;
  z->gg.g.n = &x->Metadata->gg.g;
  x->Metadata = z;
}

/* FUNC(zx_a_FaultTo_REV_Metadata) */

void zx_a_FaultTo_REV_Metadata(struct zx_a_FaultTo_s* x)
{
  struct zx_a_Metadata_s* nxt;
  struct zx_a_Metadata_s* y;
  if (!x) return;
  y = x->Metadata;
  if (!y) return;
  x->Metadata = 0;
  while (y) {
    nxt = (struct zx_a_Metadata_s*)y->gg.g.n;
    y->gg.g.n = &x->Metadata->gg.g;
    x->Metadata = y;
    y = nxt;
  }
}

/* FUNC(zx_a_FaultTo_PUT_Metadata) */

void zx_a_FaultTo_PUT_Metadata(struct zx_a_FaultTo_s* x, int n, struct zx_a_Metadata_s* z)
{
  struct zx_a_Metadata_s* y;
  if (!x || !z) return;
  y = x->Metadata;
  if (!y) return;
  switch (n) {
  case 0:
    z->gg.g.n = y->gg.g.n;
    x->Metadata = z;
    return;
  default:
    for (; n > 1 && y->gg.g.n; --n, y = (struct zx_a_Metadata_s*)y->gg.g.n) ;
    if (!y->gg.g.n) return;
    z->gg.g.n = y->gg.g.n->n;
    y->gg.g.n = &z->gg.g;
  }
}

/* FUNC(zx_a_FaultTo_ADD_Metadata) */

void zx_a_FaultTo_ADD_Metadata(struct zx_a_FaultTo_s* x, int n, struct zx_a_Metadata_s* z)
{
  struct zx_a_Metadata_s* y;
  if (!x || !z) return;
  switch (n) {
  case 0:
  add_to_start:
    z->gg.g.n = &x->Metadata->gg.g;
    x->Metadata = z;
    return;
  case -1:
    y = x->Metadata;
    if (!y) goto add_to_start;
    for (; y->gg.g.n; y = (struct zx_a_Metadata_s*)y->gg.g.n) ;
    break;
  default:
    for (y = x->Metadata; n > 1 && y; --n, y = (struct zx_a_Metadata_s*)y->gg.g.n) ;
    if (!y) return;
  }
  z->gg.g.n = y->gg.g.n;
  y->gg.g.n = &z->gg.g;
}

/* FUNC(zx_a_FaultTo_DEL_Metadata) */

void zx_a_FaultTo_DEL_Metadata(struct zx_a_FaultTo_s* x, int n)
{
  struct zx_a_Metadata_s* y;
  if (!x) return;
  switch (n) {
  case 0:
    x->Metadata = (struct zx_a_Metadata_s*)x->Metadata->gg.g.n;
    return;
  case -1:
    y = (struct zx_a_Metadata_s*)x->Metadata;
    if (!y) return;
    for (; y->gg.g.n; y = (struct zx_a_Metadata_s*)y->gg.g.n) ;
    break;
  default:
    for (y = x->Metadata; n > 1 && y->gg.g.n; --n, y = (struct zx_a_Metadata_s*)y->gg.g.n) ;
    if (!y->gg.g.n) return;
  }
  y->gg.g.n = y->gg.g.n->n;
}

#endif

/* FUNC(zx_a_FaultTo_GET_ID) */
struct zx_str* zx_a_FaultTo_GET_ID(struct zx_a_FaultTo_s* x) { return x->ID; }
/* FUNC(zx_a_FaultTo_PUT_ID) */
void zx_a_FaultTo_PUT_ID(struct zx_a_FaultTo_s* x, struct zx_str* y) { x->ID = y; }
/* FUNC(zx_a_FaultTo_GET_id) */
struct zx_str* zx_a_FaultTo_GET_id(struct zx_a_FaultTo_s* x) { return x->id; }
/* FUNC(zx_a_FaultTo_PUT_id) */
void zx_a_FaultTo_PUT_id(struct zx_a_FaultTo_s* x, struct zx_str* y) { x->id = y; }
/* FUNC(zx_a_FaultTo_GET_notOnOrAfter) */
struct zx_str* zx_a_FaultTo_GET_notOnOrAfter(struct zx_a_FaultTo_s* x) { return x->notOnOrAfter; }
/* FUNC(zx_a_FaultTo_PUT_notOnOrAfter) */
void zx_a_FaultTo_PUT_notOnOrAfter(struct zx_a_FaultTo_s* x, struct zx_str* y) { x->notOnOrAfter = y; }
/* FUNC(zx_a_FaultTo_GET_Id) */
struct zx_str* zx_a_FaultTo_GET_Id(struct zx_a_FaultTo_s* x) { return x->Id; }
/* FUNC(zx_a_FaultTo_PUT_Id) */
void zx_a_FaultTo_PUT_Id(struct zx_a_FaultTo_s* x, struct zx_str* y) { x->Id = y; }
/* FUNC(zx_a_FaultTo_GET_actor) */
struct zx_str* zx_a_FaultTo_GET_actor(struct zx_a_FaultTo_s* x) { return x->actor; }
/* FUNC(zx_a_FaultTo_PUT_actor) */
void zx_a_FaultTo_PUT_actor(struct zx_a_FaultTo_s* x, struct zx_str* y) { x->actor = y; }
/* FUNC(zx_a_FaultTo_GET_mustUnderstand) */
struct zx_str* zx_a_FaultTo_GET_mustUnderstand(struct zx_a_FaultTo_s* x) { return x->mustUnderstand; }
/* FUNC(zx_a_FaultTo_PUT_mustUnderstand) */
void zx_a_FaultTo_PUT_mustUnderstand(struct zx_a_FaultTo_s* x, struct zx_str* y) { x->mustUnderstand = y; }







#ifdef ZX_ENA_GETPUT

/* FUNC(zx_a_From_NUM_Address) */

int zx_a_From_NUM_Address(struct zx_a_From_s* x)
{
  struct zx_a_Address_s* y;
  int n = 0;
  if (!x) return 0;
  for (y = x->Address; y; ++n, y = (struct zx_a_Address_s*)y->gg.g.n) ;
  return n;
}

/* FUNC(zx_a_From_GET_Address) */

struct zx_a_Address_s* zx_a_From_GET_Address(struct zx_a_From_s* x, int n)
{
  struct zx_a_Address_s* y;
  if (!x) return 0;
  for (y = x->Address; n>=0 && y; --n, y = (struct zx_a_Address_s*)y->gg.g.n) ;
  return y;
}

/* FUNC(zx_a_From_POP_Address) */

struct zx_a_Address_s* zx_a_From_POP_Address(struct zx_a_From_s* x)
{
  struct zx_a_Address_s* y;
  if (!x) return 0;
  y = x->Address;
  if (y)
    x->Address = (struct zx_a_Address_s*)y->gg.g.n;
  return y;
}

/* FUNC(zx_a_From_PUSH_Address) */

void zx_a_From_PUSH_Address(struct zx_a_From_s* x, struct zx_a_Address_s* z)
{
  if (!x || !z) return;
  z->gg.g.n = &x->Address->gg.g;
  x->Address = z;
}

/* FUNC(zx_a_From_REV_Address) */

void zx_a_From_REV_Address(struct zx_a_From_s* x)
{
  struct zx_a_Address_s* nxt;
  struct zx_a_Address_s* y;
  if (!x) return;
  y = x->Address;
  if (!y) return;
  x->Address = 0;
  while (y) {
    nxt = (struct zx_a_Address_s*)y->gg.g.n;
    y->gg.g.n = &x->Address->gg.g;
    x->Address = y;
    y = nxt;
  }
}

/* FUNC(zx_a_From_PUT_Address) */

void zx_a_From_PUT_Address(struct zx_a_From_s* x, int n, struct zx_a_Address_s* z)
{
  struct zx_a_Address_s* y;
  if (!x || !z) return;
  y = x->Address;
  if (!y) return;
  switch (n) {
  case 0:
    z->gg.g.n = y->gg.g.n;
    x->Address = z;
    return;
  default:
    for (; n > 1 && y->gg.g.n; --n, y = (struct zx_a_Address_s*)y->gg.g.n) ;
    if (!y->gg.g.n) return;
    z->gg.g.n = y->gg.g.n->n;
    y->gg.g.n = &z->gg.g;
  }
}

/* FUNC(zx_a_From_ADD_Address) */

void zx_a_From_ADD_Address(struct zx_a_From_s* x, int n, struct zx_a_Address_s* z)
{
  struct zx_a_Address_s* y;
  if (!x || !z) return;
  switch (n) {
  case 0:
  add_to_start:
    z->gg.g.n = &x->Address->gg.g;
    x->Address = z;
    return;
  case -1:
    y = x->Address;
    if (!y) goto add_to_start;
    for (; y->gg.g.n; y = (struct zx_a_Address_s*)y->gg.g.n) ;
    break;
  default:
    for (y = x->Address; n > 1 && y; --n, y = (struct zx_a_Address_s*)y->gg.g.n) ;
    if (!y) return;
  }
  z->gg.g.n = y->gg.g.n;
  y->gg.g.n = &z->gg.g;
}

/* FUNC(zx_a_From_DEL_Address) */

void zx_a_From_DEL_Address(struct zx_a_From_s* x, int n)
{
  struct zx_a_Address_s* y;
  if (!x) return;
  switch (n) {
  case 0:
    x->Address = (struct zx_a_Address_s*)x->Address->gg.g.n;
    return;
  case -1:
    y = (struct zx_a_Address_s*)x->Address;
    if (!y) return;
    for (; y->gg.g.n; y = (struct zx_a_Address_s*)y->gg.g.n) ;
    break;
  default:
    for (y = x->Address; n > 1 && y->gg.g.n; --n, y = (struct zx_a_Address_s*)y->gg.g.n) ;
    if (!y->gg.g.n) return;
  }
  y->gg.g.n = y->gg.g.n->n;
}

#endif



#ifdef ZX_ENA_GETPUT

/* FUNC(zx_a_From_NUM_ReferenceParameters) */

int zx_a_From_NUM_ReferenceParameters(struct zx_a_From_s* x)
{
  struct zx_a_ReferenceParameters_s* y;
  int n = 0;
  if (!x) return 0;
  for (y = x->ReferenceParameters; y; ++n, y = (struct zx_a_ReferenceParameters_s*)y->gg.g.n) ;
  return n;
}

/* FUNC(zx_a_From_GET_ReferenceParameters) */

struct zx_a_ReferenceParameters_s* zx_a_From_GET_ReferenceParameters(struct zx_a_From_s* x, int n)
{
  struct zx_a_ReferenceParameters_s* y;
  if (!x) return 0;
  for (y = x->ReferenceParameters; n>=0 && y; --n, y = (struct zx_a_ReferenceParameters_s*)y->gg.g.n) ;
  return y;
}

/* FUNC(zx_a_From_POP_ReferenceParameters) */

struct zx_a_ReferenceParameters_s* zx_a_From_POP_ReferenceParameters(struct zx_a_From_s* x)
{
  struct zx_a_ReferenceParameters_s* y;
  if (!x) return 0;
  y = x->ReferenceParameters;
  if (y)
    x->ReferenceParameters = (struct zx_a_ReferenceParameters_s*)y->gg.g.n;
  return y;
}

/* FUNC(zx_a_From_PUSH_ReferenceParameters) */

void zx_a_From_PUSH_ReferenceParameters(struct zx_a_From_s* x, struct zx_a_ReferenceParameters_s* z)
{
  if (!x || !z) return;
  z->gg.g.n = &x->ReferenceParameters->gg.g;
  x->ReferenceParameters = z;
}

/* FUNC(zx_a_From_REV_ReferenceParameters) */

void zx_a_From_REV_ReferenceParameters(struct zx_a_From_s* x)
{
  struct zx_a_ReferenceParameters_s* nxt;
  struct zx_a_ReferenceParameters_s* y;
  if (!x) return;
  y = x->ReferenceParameters;
  if (!y) return;
  x->ReferenceParameters = 0;
  while (y) {
    nxt = (struct zx_a_ReferenceParameters_s*)y->gg.g.n;
    y->gg.g.n = &x->ReferenceParameters->gg.g;
    x->ReferenceParameters = y;
    y = nxt;
  }
}

/* FUNC(zx_a_From_PUT_ReferenceParameters) */

void zx_a_From_PUT_ReferenceParameters(struct zx_a_From_s* x, int n, struct zx_a_ReferenceParameters_s* z)
{
  struct zx_a_ReferenceParameters_s* y;
  if (!x || !z) return;
  y = x->ReferenceParameters;
  if (!y) return;
  switch (n) {
  case 0:
    z->gg.g.n = y->gg.g.n;
    x->ReferenceParameters = z;
    return;
  default:
    for (; n > 1 && y->gg.g.n; --n, y = (struct zx_a_ReferenceParameters_s*)y->gg.g.n) ;
    if (!y->gg.g.n) return;
    z->gg.g.n = y->gg.g.n->n;
    y->gg.g.n = &z->gg.g;
  }
}

/* FUNC(zx_a_From_ADD_ReferenceParameters) */

void zx_a_From_ADD_ReferenceParameters(struct zx_a_From_s* x, int n, struct zx_a_ReferenceParameters_s* z)
{
  struct zx_a_ReferenceParameters_s* y;
  if (!x || !z) return;
  switch (n) {
  case 0:
  add_to_start:
    z->gg.g.n = &x->ReferenceParameters->gg.g;
    x->ReferenceParameters = z;
    return;
  case -1:
    y = x->ReferenceParameters;
    if (!y) goto add_to_start;
    for (; y->gg.g.n; y = (struct zx_a_ReferenceParameters_s*)y->gg.g.n) ;
    break;
  default:
    for (y = x->ReferenceParameters; n > 1 && y; --n, y = (struct zx_a_ReferenceParameters_s*)y->gg.g.n) ;
    if (!y) return;
  }
  z->gg.g.n = y->gg.g.n;
  y->gg.g.n = &z->gg.g;
}

/* FUNC(zx_a_From_DEL_ReferenceParameters) */

void zx_a_From_DEL_ReferenceParameters(struct zx_a_From_s* x, int n)
{
  struct zx_a_ReferenceParameters_s* y;
  if (!x) return;
  switch (n) {
  case 0:
    x->ReferenceParameters = (struct zx_a_ReferenceParameters_s*)x->ReferenceParameters->gg.g.n;
    return;
  case -1:
    y = (struct zx_a_ReferenceParameters_s*)x->ReferenceParameters;
    if (!y) return;
    for (; y->gg.g.n; y = (struct zx_a_ReferenceParameters_s*)y->gg.g.n) ;
    break;
  default:
    for (y = x->ReferenceParameters; n > 1 && y->gg.g.n; --n, y = (struct zx_a_ReferenceParameters_s*)y->gg.g.n) ;
    if (!y->gg.g.n) return;
  }
  y->gg.g.n = y->gg.g.n->n;
}

#endif



#ifdef ZX_ENA_GETPUT

/* FUNC(zx_a_From_NUM_Metadata) */

int zx_a_From_NUM_Metadata(struct zx_a_From_s* x)
{
  struct zx_a_Metadata_s* y;
  int n = 0;
  if (!x) return 0;
  for (y = x->Metadata; y; ++n, y = (struct zx_a_Metadata_s*)y->gg.g.n) ;
  return n;
}

/* FUNC(zx_a_From_GET_Metadata) */

struct zx_a_Metadata_s* zx_a_From_GET_Metadata(struct zx_a_From_s* x, int n)
{
  struct zx_a_Metadata_s* y;
  if (!x) return 0;
  for (y = x->Metadata; n>=0 && y; --n, y = (struct zx_a_Metadata_s*)y->gg.g.n) ;
  return y;
}

/* FUNC(zx_a_From_POP_Metadata) */

struct zx_a_Metadata_s* zx_a_From_POP_Metadata(struct zx_a_From_s* x)
{
  struct zx_a_Metadata_s* y;
  if (!x) return 0;
  y = x->Metadata;
  if (y)
    x->Metadata = (struct zx_a_Metadata_s*)y->gg.g.n;
  return y;
}

/* FUNC(zx_a_From_PUSH_Metadata) */

void zx_a_From_PUSH_Metadata(struct zx_a_From_s* x, struct zx_a_Metadata_s* z)
{
  if (!x || !z) return;
  z->gg.g.n = &x->Metadata->gg.g;
  x->Metadata = z;
}

/* FUNC(zx_a_From_REV_Metadata) */

void zx_a_From_REV_Metadata(struct zx_a_From_s* x)
{
  struct zx_a_Metadata_s* nxt;
  struct zx_a_Metadata_s* y;
  if (!x) return;
  y = x->Metadata;
  if (!y) return;
  x->Metadata = 0;
  while (y) {
    nxt = (struct zx_a_Metadata_s*)y->gg.g.n;
    y->gg.g.n = &x->Metadata->gg.g;
    x->Metadata = y;
    y = nxt;
  }
}

/* FUNC(zx_a_From_PUT_Metadata) */

void zx_a_From_PUT_Metadata(struct zx_a_From_s* x, int n, struct zx_a_Metadata_s* z)
{
  struct zx_a_Metadata_s* y;
  if (!x || !z) return;
  y = x->Metadata;
  if (!y) return;
  switch (n) {
  case 0:
    z->gg.g.n = y->gg.g.n;
    x->Metadata = z;
    return;
  default:
    for (; n > 1 && y->gg.g.n; --n, y = (struct zx_a_Metadata_s*)y->gg.g.n) ;
    if (!y->gg.g.n) return;
    z->gg.g.n = y->gg.g.n->n;
    y->gg.g.n = &z->gg.g;
  }
}

/* FUNC(zx_a_From_ADD_Metadata) */

void zx_a_From_ADD_Metadata(struct zx_a_From_s* x, int n, struct zx_a_Metadata_s* z)
{
  struct zx_a_Metadata_s* y;
  if (!x || !z) return;
  switch (n) {
  case 0:
  add_to_start:
    z->gg.g.n = &x->Metadata->gg.g;
    x->Metadata = z;
    return;
  case -1:
    y = x->Metadata;
    if (!y) goto add_to_start;
    for (; y->gg.g.n; y = (struct zx_a_Metadata_s*)y->gg.g.n) ;
    break;
  default:
    for (y = x->Metadata; n > 1 && y; --n, y = (struct zx_a_Metadata_s*)y->gg.g.n) ;
    if (!y) return;
  }
  z->gg.g.n = y->gg.g.n;
  y->gg.g.n = &z->gg.g;
}

/* FUNC(zx_a_From_DEL_Metadata) */

void zx_a_From_DEL_Metadata(struct zx_a_From_s* x, int n)
{
  struct zx_a_Metadata_s* y;
  if (!x) return;
  switch (n) {
  case 0:
    x->Metadata = (struct zx_a_Metadata_s*)x->Metadata->gg.g.n;
    return;
  case -1:
    y = (struct zx_a_Metadata_s*)x->Metadata;
    if (!y) return;
    for (; y->gg.g.n; y = (struct zx_a_Metadata_s*)y->gg.g.n) ;
    break;
  default:
    for (y = x->Metadata; n > 1 && y->gg.g.n; --n, y = (struct zx_a_Metadata_s*)y->gg.g.n) ;
    if (!y->gg.g.n) return;
  }
  y->gg.g.n = y->gg.g.n->n;
}

#endif

/* FUNC(zx_a_From_GET_ID) */
struct zx_str* zx_a_From_GET_ID(struct zx_a_From_s* x) { return x->ID; }
/* FUNC(zx_a_From_PUT_ID) */
void zx_a_From_PUT_ID(struct zx_a_From_s* x, struct zx_str* y) { x->ID = y; }
/* FUNC(zx_a_From_GET_id) */
struct zx_str* zx_a_From_GET_id(struct zx_a_From_s* x) { return x->id; }
/* FUNC(zx_a_From_PUT_id) */
void zx_a_From_PUT_id(struct zx_a_From_s* x, struct zx_str* y) { x->id = y; }
/* FUNC(zx_a_From_GET_notOnOrAfter) */
struct zx_str* zx_a_From_GET_notOnOrAfter(struct zx_a_From_s* x) { return x->notOnOrAfter; }
/* FUNC(zx_a_From_PUT_notOnOrAfter) */
void zx_a_From_PUT_notOnOrAfter(struct zx_a_From_s* x, struct zx_str* y) { x->notOnOrAfter = y; }
/* FUNC(zx_a_From_GET_Id) */
struct zx_str* zx_a_From_GET_Id(struct zx_a_From_s* x) { return x->Id; }
/* FUNC(zx_a_From_PUT_Id) */
void zx_a_From_PUT_Id(struct zx_a_From_s* x, struct zx_str* y) { x->Id = y; }
/* FUNC(zx_a_From_GET_actor) */
struct zx_str* zx_a_From_GET_actor(struct zx_a_From_s* x) { return x->actor; }
/* FUNC(zx_a_From_PUT_actor) */
void zx_a_From_PUT_actor(struct zx_a_From_s* x, struct zx_str* y) { x->actor = y; }
/* FUNC(zx_a_From_GET_mustUnderstand) */
struct zx_str* zx_a_From_GET_mustUnderstand(struct zx_a_From_s* x) { return x->mustUnderstand; }
/* FUNC(zx_a_From_PUT_mustUnderstand) */
void zx_a_From_PUT_mustUnderstand(struct zx_a_From_s* x, struct zx_str* y) { x->mustUnderstand = y; }





/* FUNC(zx_a_MessageID_GET_ID) */
struct zx_str* zx_a_MessageID_GET_ID(struct zx_a_MessageID_s* x) { return x->ID; }
/* FUNC(zx_a_MessageID_PUT_ID) */
void zx_a_MessageID_PUT_ID(struct zx_a_MessageID_s* x, struct zx_str* y) { x->ID = y; }
/* FUNC(zx_a_MessageID_GET_id) */
struct zx_str* zx_a_MessageID_GET_id(struct zx_a_MessageID_s* x) { return x->id; }
/* FUNC(zx_a_MessageID_PUT_id) */
void zx_a_MessageID_PUT_id(struct zx_a_MessageID_s* x, struct zx_str* y) { x->id = y; }
/* FUNC(zx_a_MessageID_GET_Id) */
struct zx_str* zx_a_MessageID_GET_Id(struct zx_a_MessageID_s* x) { return x->Id; }
/* FUNC(zx_a_MessageID_PUT_Id) */
void zx_a_MessageID_PUT_Id(struct zx_a_MessageID_s* x, struct zx_str* y) { x->Id = y; }
/* FUNC(zx_a_MessageID_GET_actor) */
struct zx_str* zx_a_MessageID_GET_actor(struct zx_a_MessageID_s* x) { return x->actor; }
/* FUNC(zx_a_MessageID_PUT_actor) */
void zx_a_MessageID_PUT_actor(struct zx_a_MessageID_s* x, struct zx_str* y) { x->actor = y; }
/* FUNC(zx_a_MessageID_GET_mustUnderstand) */
struct zx_str* zx_a_MessageID_GET_mustUnderstand(struct zx_a_MessageID_s* x) { return x->mustUnderstand; }
/* FUNC(zx_a_MessageID_PUT_mustUnderstand) */
void zx_a_MessageID_PUT_mustUnderstand(struct zx_a_MessageID_s* x, struct zx_str* y) { x->mustUnderstand = y; }







#ifdef ZX_ENA_GETPUT

/* FUNC(zx_a_Metadata_NUM_Framework) */

int zx_a_Metadata_NUM_Framework(struct zx_a_Metadata_s* x)
{
  struct zx_sbf_Framework_s* y;
  int n = 0;
  if (!x) return 0;
  for (y = x->Framework; y; ++n, y = (struct zx_sbf_Framework_s*)y->gg.g.n) ;
  return n;
}

/* FUNC(zx_a_Metadata_GET_Framework) */

struct zx_sbf_Framework_s* zx_a_Metadata_GET_Framework(struct zx_a_Metadata_s* x, int n)
{
  struct zx_sbf_Framework_s* y;
  if (!x) return 0;
  for (y = x->Framework; n>=0 && y; --n, y = (struct zx_sbf_Framework_s*)y->gg.g.n) ;
  return y;
}

/* FUNC(zx_a_Metadata_POP_Framework) */

struct zx_sbf_Framework_s* zx_a_Metadata_POP_Framework(struct zx_a_Metadata_s* x)
{
  struct zx_sbf_Framework_s* y;
  if (!x) return 0;
  y = x->Framework;
  if (y)
    x->Framework = (struct zx_sbf_Framework_s*)y->gg.g.n;
  return y;
}

/* FUNC(zx_a_Metadata_PUSH_Framework) */

void zx_a_Metadata_PUSH_Framework(struct zx_a_Metadata_s* x, struct zx_sbf_Framework_s* z)
{
  if (!x || !z) return;
  z->gg.g.n = &x->Framework->gg.g;
  x->Framework = z;
}

/* FUNC(zx_a_Metadata_REV_Framework) */

void zx_a_Metadata_REV_Framework(struct zx_a_Metadata_s* x)
{
  struct zx_sbf_Framework_s* nxt;
  struct zx_sbf_Framework_s* y;
  if (!x) return;
  y = x->Framework;
  if (!y) return;
  x->Framework = 0;
  while (y) {
    nxt = (struct zx_sbf_Framework_s*)y->gg.g.n;
    y->gg.g.n = &x->Framework->gg.g;
    x->Framework = y;
    y = nxt;
  }
}

/* FUNC(zx_a_Metadata_PUT_Framework) */

void zx_a_Metadata_PUT_Framework(struct zx_a_Metadata_s* x, int n, struct zx_sbf_Framework_s* z)
{
  struct zx_sbf_Framework_s* y;
  if (!x || !z) return;
  y = x->Framework;
  if (!y) return;
  switch (n) {
  case 0:
    z->gg.g.n = y->gg.g.n;
    x->Framework = z;
    return;
  default:
    for (; n > 1 && y->gg.g.n; --n, y = (struct zx_sbf_Framework_s*)y->gg.g.n) ;
    if (!y->gg.g.n) return;
    z->gg.g.n = y->gg.g.n->n;
    y->gg.g.n = &z->gg.g;
  }
}

/* FUNC(zx_a_Metadata_ADD_Framework) */

void zx_a_Metadata_ADD_Framework(struct zx_a_Metadata_s* x, int n, struct zx_sbf_Framework_s* z)
{
  struct zx_sbf_Framework_s* y;
  if (!x || !z) return;
  switch (n) {
  case 0:
  add_to_start:
    z->gg.g.n = &x->Framework->gg.g;
    x->Framework = z;
    return;
  case -1:
    y = x->Framework;
    if (!y) goto add_to_start;
    for (; y->gg.g.n; y = (struct zx_sbf_Framework_s*)y->gg.g.n) ;
    break;
  default:
    for (y = x->Framework; n > 1 && y; --n, y = (struct zx_sbf_Framework_s*)y->gg.g.n) ;
    if (!y) return;
  }
  z->gg.g.n = y->gg.g.n;
  y->gg.g.n = &z->gg.g;
}

/* FUNC(zx_a_Metadata_DEL_Framework) */

void zx_a_Metadata_DEL_Framework(struct zx_a_Metadata_s* x, int n)
{
  struct zx_sbf_Framework_s* y;
  if (!x) return;
  switch (n) {
  case 0:
    x->Framework = (struct zx_sbf_Framework_s*)x->Framework->gg.g.n;
    return;
  case -1:
    y = (struct zx_sbf_Framework_s*)x->Framework;
    if (!y) return;
    for (; y->gg.g.n; y = (struct zx_sbf_Framework_s*)y->gg.g.n) ;
    break;
  default:
    for (y = x->Framework; n > 1 && y->gg.g.n; --n, y = (struct zx_sbf_Framework_s*)y->gg.g.n) ;
    if (!y->gg.g.n) return;
  }
  y->gg.g.n = y->gg.g.n->n;
}

#endif



#ifdef ZX_ENA_GETPUT

/* FUNC(zx_a_Metadata_NUM_Abstract) */

int zx_a_Metadata_NUM_Abstract(struct zx_a_Metadata_s* x)
{
  struct zx_elem_s* y;
  int n = 0;
  if (!x) return 0;
  for (y = x->Abstract; y; ++n, y = (struct zx_elem_s*)y->g.n) ;
  return n;
}

/* FUNC(zx_a_Metadata_GET_Abstract) */

struct zx_elem_s* zx_a_Metadata_GET_Abstract(struct zx_a_Metadata_s* x, int n)
{
  struct zx_elem_s* y;
  if (!x) return 0;
  for (y = x->Abstract; n>=0 && y; --n, y = (struct zx_elem_s*)y->g.n) ;
  return y;
}

/* FUNC(zx_a_Metadata_POP_Abstract) */

struct zx_elem_s* zx_a_Metadata_POP_Abstract(struct zx_a_Metadata_s* x)
{
  struct zx_elem_s* y;
  if (!x) return 0;
  y = x->Abstract;
  if (y)
    x->Abstract = (struct zx_elem_s*)y->g.n;
  return y;
}

/* FUNC(zx_a_Metadata_PUSH_Abstract) */

void zx_a_Metadata_PUSH_Abstract(struct zx_a_Metadata_s* x, struct zx_elem_s* z)
{
  if (!x || !z) return;
  z->g.n = &x->Abstract->g;
  x->Abstract = z;
}

/* FUNC(zx_a_Metadata_REV_Abstract) */

void zx_a_Metadata_REV_Abstract(struct zx_a_Metadata_s* x)
{
  struct zx_elem_s* nxt;
  struct zx_elem_s* y;
  if (!x) return;
  y = x->Abstract;
  if (!y) return;
  x->Abstract = 0;
  while (y) {
    nxt = (struct zx_elem_s*)y->g.n;
    y->g.n = &x->Abstract->g;
    x->Abstract = y;
    y = nxt;
  }
}

/* FUNC(zx_a_Metadata_PUT_Abstract) */

void zx_a_Metadata_PUT_Abstract(struct zx_a_Metadata_s* x, int n, struct zx_elem_s* z)
{
  struct zx_elem_s* y;
  if (!x || !z) return;
  y = x->Abstract;
  if (!y) return;
  switch (n) {
  case 0:
    z->g.n = y->g.n;
    x->Abstract = z;
    return;
  default:
    for (; n > 1 && y->g.n; --n, y = (struct zx_elem_s*)y->g.n) ;
    if (!y->g.n) return;
    z->g.n = y->g.n->n;
    y->g.n = &z->g;
  }
}

/* FUNC(zx_a_Metadata_ADD_Abstract) */

void zx_a_Metadata_ADD_Abstract(struct zx_a_Metadata_s* x, int n, struct zx_elem_s* z)
{
  struct zx_elem_s* y;
  if (!x || !z) return;
  switch (n) {
  case 0:
  add_to_start:
    z->g.n = &x->Abstract->g;
    x->Abstract = z;
    return;
  case -1:
    y = x->Abstract;
    if (!y) goto add_to_start;
    for (; y->g.n; y = (struct zx_elem_s*)y->g.n) ;
    break;
  default:
    for (y = x->Abstract; n > 1 && y; --n, y = (struct zx_elem_s*)y->g.n) ;
    if (!y) return;
  }
  z->g.n = y->g.n;
  y->g.n = &z->g;
}

/* FUNC(zx_a_Metadata_DEL_Abstract) */

void zx_a_Metadata_DEL_Abstract(struct zx_a_Metadata_s* x, int n)
{
  struct zx_elem_s* y;
  if (!x) return;
  switch (n) {
  case 0:
    x->Abstract = (struct zx_elem_s*)x->Abstract->g.n;
    return;
  case -1:
    y = (struct zx_elem_s*)x->Abstract;
    if (!y) return;
    for (; y->g.n; y = (struct zx_elem_s*)y->g.n) ;
    break;
  default:
    for (y = x->Abstract; n > 1 && y->g.n; --n, y = (struct zx_elem_s*)y->g.n) ;
    if (!y->g.n) return;
  }
  y->g.n = y->g.n->n;
}

#endif



#ifdef ZX_ENA_GETPUT

/* FUNC(zx_a_Metadata_NUM_ProviderID) */

int zx_a_Metadata_NUM_ProviderID(struct zx_a_Metadata_s* x)
{
  struct zx_elem_s* y;
  int n = 0;
  if (!x) return 0;
  for (y = x->ProviderID; y; ++n, y = (struct zx_elem_s*)y->g.n) ;
  return n;
}

/* FUNC(zx_a_Metadata_GET_ProviderID) */

struct zx_elem_s* zx_a_Metadata_GET_ProviderID(struct zx_a_Metadata_s* x, int n)
{
  struct zx_elem_s* y;
  if (!x) return 0;
  for (y = x->ProviderID; n>=0 && y; --n, y = (struct zx_elem_s*)y->g.n) ;
  return y;
}

/* FUNC(zx_a_Metadata_POP_ProviderID) */

struct zx_elem_s* zx_a_Metadata_POP_ProviderID(struct zx_a_Metadata_s* x)
{
  struct zx_elem_s* y;
  if (!x) return 0;
  y = x->ProviderID;
  if (y)
    x->ProviderID = (struct zx_elem_s*)y->g.n;
  return y;
}

/* FUNC(zx_a_Metadata_PUSH_ProviderID) */

void zx_a_Metadata_PUSH_ProviderID(struct zx_a_Metadata_s* x, struct zx_elem_s* z)
{
  if (!x || !z) return;
  z->g.n = &x->ProviderID->g;
  x->ProviderID = z;
}

/* FUNC(zx_a_Metadata_REV_ProviderID) */

void zx_a_Metadata_REV_ProviderID(struct zx_a_Metadata_s* x)
{
  struct zx_elem_s* nxt;
  struct zx_elem_s* y;
  if (!x) return;
  y = x->ProviderID;
  if (!y) return;
  x->ProviderID = 0;
  while (y) {
    nxt = (struct zx_elem_s*)y->g.n;
    y->g.n = &x->ProviderID->g;
    x->ProviderID = y;
    y = nxt;
  }
}

/* FUNC(zx_a_Metadata_PUT_ProviderID) */

void zx_a_Metadata_PUT_ProviderID(struct zx_a_Metadata_s* x, int n, struct zx_elem_s* z)
{
  struct zx_elem_s* y;
  if (!x || !z) return;
  y = x->ProviderID;
  if (!y) return;
  switch (n) {
  case 0:
    z->g.n = y->g.n;
    x->ProviderID = z;
    return;
  default:
    for (; n > 1 && y->g.n; --n, y = (struct zx_elem_s*)y->g.n) ;
    if (!y->g.n) return;
    z->g.n = y->g.n->n;
    y->g.n = &z->g;
  }
}

/* FUNC(zx_a_Metadata_ADD_ProviderID) */

void zx_a_Metadata_ADD_ProviderID(struct zx_a_Metadata_s* x, int n, struct zx_elem_s* z)
{
  struct zx_elem_s* y;
  if (!x || !z) return;
  switch (n) {
  case 0:
  add_to_start:
    z->g.n = &x->ProviderID->g;
    x->ProviderID = z;
    return;
  case -1:
    y = x->ProviderID;
    if (!y) goto add_to_start;
    for (; y->g.n; y = (struct zx_elem_s*)y->g.n) ;
    break;
  default:
    for (y = x->ProviderID; n > 1 && y; --n, y = (struct zx_elem_s*)y->g.n) ;
    if (!y) return;
  }
  z->g.n = y->g.n;
  y->g.n = &z->g;
}

/* FUNC(zx_a_Metadata_DEL_ProviderID) */

void zx_a_Metadata_DEL_ProviderID(struct zx_a_Metadata_s* x, int n)
{
  struct zx_elem_s* y;
  if (!x) return;
  switch (n) {
  case 0:
    x->ProviderID = (struct zx_elem_s*)x->ProviderID->g.n;
    return;
  case -1:
    y = (struct zx_elem_s*)x->ProviderID;
    if (!y) return;
    for (; y->g.n; y = (struct zx_elem_s*)y->g.n) ;
    break;
  default:
    for (y = x->ProviderID; n > 1 && y->g.n; --n, y = (struct zx_elem_s*)y->g.n) ;
    if (!y->g.n) return;
  }
  y->g.n = y->g.n->n;
}

#endif



#ifdef ZX_ENA_GETPUT

/* FUNC(zx_a_Metadata_NUM_ServiceType) */

int zx_a_Metadata_NUM_ServiceType(struct zx_a_Metadata_s* x)
{
  struct zx_elem_s* y;
  int n = 0;
  if (!x) return 0;
  for (y = x->ServiceType; y; ++n, y = (struct zx_elem_s*)y->g.n) ;
  return n;
}

/* FUNC(zx_a_Metadata_GET_ServiceType) */

struct zx_elem_s* zx_a_Metadata_GET_ServiceType(struct zx_a_Metadata_s* x, int n)
{
  struct zx_elem_s* y;
  if (!x) return 0;
  for (y = x->ServiceType; n>=0 && y; --n, y = (struct zx_elem_s*)y->g.n) ;
  return y;
}

/* FUNC(zx_a_Metadata_POP_ServiceType) */

struct zx_elem_s* zx_a_Metadata_POP_ServiceType(struct zx_a_Metadata_s* x)
{
  struct zx_elem_s* y;
  if (!x) return 0;
  y = x->ServiceType;
  if (y)
    x->ServiceType = (struct zx_elem_s*)y->g.n;
  return y;
}

/* FUNC(zx_a_Metadata_PUSH_ServiceType) */

void zx_a_Metadata_PUSH_ServiceType(struct zx_a_Metadata_s* x, struct zx_elem_s* z)
{
  if (!x || !z) return;
  z->g.n = &x->ServiceType->g;
  x->ServiceType = z;
}

/* FUNC(zx_a_Metadata_REV_ServiceType) */

void zx_a_Metadata_REV_ServiceType(struct zx_a_Metadata_s* x)
{
  struct zx_elem_s* nxt;
  struct zx_elem_s* y;
  if (!x) return;
  y = x->ServiceType;
  if (!y) return;
  x->ServiceType = 0;
  while (y) {
    nxt = (struct zx_elem_s*)y->g.n;
    y->g.n = &x->ServiceType->g;
    x->ServiceType = y;
    y = nxt;
  }
}

/* FUNC(zx_a_Metadata_PUT_ServiceType) */

void zx_a_Metadata_PUT_ServiceType(struct zx_a_Metadata_s* x, int n, struct zx_elem_s* z)
{
  struct zx_elem_s* y;
  if (!x || !z) return;
  y = x->ServiceType;
  if (!y) return;
  switch (n) {
  case 0:
    z->g.n = y->g.n;
    x->ServiceType = z;
    return;
  default:
    for (; n > 1 && y->g.n; --n, y = (struct zx_elem_s*)y->g.n) ;
    if (!y->g.n) return;
    z->g.n = y->g.n->n;
    y->g.n = &z->g;
  }
}

/* FUNC(zx_a_Metadata_ADD_ServiceType) */

void zx_a_Metadata_ADD_ServiceType(struct zx_a_Metadata_s* x, int n, struct zx_elem_s* z)
{
  struct zx_elem_s* y;
  if (!x || !z) return;
  switch (n) {
  case 0:
  add_to_start:
    z->g.n = &x->ServiceType->g;
    x->ServiceType = z;
    return;
  case -1:
    y = x->ServiceType;
    if (!y) goto add_to_start;
    for (; y->g.n; y = (struct zx_elem_s*)y->g.n) ;
    break;
  default:
    for (y = x->ServiceType; n > 1 && y; --n, y = (struct zx_elem_s*)y->g.n) ;
    if (!y) return;
  }
  z->g.n = y->g.n;
  y->g.n = &z->g;
}

/* FUNC(zx_a_Metadata_DEL_ServiceType) */

void zx_a_Metadata_DEL_ServiceType(struct zx_a_Metadata_s* x, int n)
{
  struct zx_elem_s* y;
  if (!x) return;
  switch (n) {
  case 0:
    x->ServiceType = (struct zx_elem_s*)x->ServiceType->g.n;
    return;
  case -1:
    y = (struct zx_elem_s*)x->ServiceType;
    if (!y) return;
    for (; y->g.n; y = (struct zx_elem_s*)y->g.n) ;
    break;
  default:
    for (y = x->ServiceType; n > 1 && y->g.n; --n, y = (struct zx_elem_s*)y->g.n) ;
    if (!y->g.n) return;
  }
  y->g.n = y->g.n->n;
}

#endif



#ifdef ZX_ENA_GETPUT

/* FUNC(zx_a_Metadata_NUM_SecurityContext) */

int zx_a_Metadata_NUM_SecurityContext(struct zx_a_Metadata_s* x)
{
  struct zx_di_SecurityContext_s* y;
  int n = 0;
  if (!x) return 0;
  for (y = x->SecurityContext; y; ++n, y = (struct zx_di_SecurityContext_s*)y->gg.g.n) ;
  return n;
}

/* FUNC(zx_a_Metadata_GET_SecurityContext) */

struct zx_di_SecurityContext_s* zx_a_Metadata_GET_SecurityContext(struct zx_a_Metadata_s* x, int n)
{
  struct zx_di_SecurityContext_s* y;
  if (!x) return 0;
  for (y = x->SecurityContext; n>=0 && y; --n, y = (struct zx_di_SecurityContext_s*)y->gg.g.n) ;
  return y;
}

/* FUNC(zx_a_Metadata_POP_SecurityContext) */

struct zx_di_SecurityContext_s* zx_a_Metadata_POP_SecurityContext(struct zx_a_Metadata_s* x)
{
  struct zx_di_SecurityContext_s* y;
  if (!x) return 0;
  y = x->SecurityContext;
  if (y)
    x->SecurityContext = (struct zx_di_SecurityContext_s*)y->gg.g.n;
  return y;
}

/* FUNC(zx_a_Metadata_PUSH_SecurityContext) */

void zx_a_Metadata_PUSH_SecurityContext(struct zx_a_Metadata_s* x, struct zx_di_SecurityContext_s* z)
{
  if (!x || !z) return;
  z->gg.g.n = &x->SecurityContext->gg.g;
  x->SecurityContext = z;
}

/* FUNC(zx_a_Metadata_REV_SecurityContext) */

void zx_a_Metadata_REV_SecurityContext(struct zx_a_Metadata_s* x)
{
  struct zx_di_SecurityContext_s* nxt;
  struct zx_di_SecurityContext_s* y;
  if (!x) return;
  y = x->SecurityContext;
  if (!y) return;
  x->SecurityContext = 0;
  while (y) {
    nxt = (struct zx_di_SecurityContext_s*)y->gg.g.n;
    y->gg.g.n = &x->SecurityContext->gg.g;
    x->SecurityContext = y;
    y = nxt;
  }
}

/* FUNC(zx_a_Metadata_PUT_SecurityContext) */

void zx_a_Metadata_PUT_SecurityContext(struct zx_a_Metadata_s* x, int n, struct zx_di_SecurityContext_s* z)
{
  struct zx_di_SecurityContext_s* y;
  if (!x || !z) return;
  y = x->SecurityContext;
  if (!y) return;
  switch (n) {
  case 0:
    z->gg.g.n = y->gg.g.n;
    x->SecurityContext = z;
    return;
  default:
    for (; n > 1 && y->gg.g.n; --n, y = (struct zx_di_SecurityContext_s*)y->gg.g.n) ;
    if (!y->gg.g.n) return;
    z->gg.g.n = y->gg.g.n->n;
    y->gg.g.n = &z->gg.g;
  }
}

/* FUNC(zx_a_Metadata_ADD_SecurityContext) */

void zx_a_Metadata_ADD_SecurityContext(struct zx_a_Metadata_s* x, int n, struct zx_di_SecurityContext_s* z)
{
  struct zx_di_SecurityContext_s* y;
  if (!x || !z) return;
  switch (n) {
  case 0:
  add_to_start:
    z->gg.g.n = &x->SecurityContext->gg.g;
    x->SecurityContext = z;
    return;
  case -1:
    y = x->SecurityContext;
    if (!y) goto add_to_start;
    for (; y->gg.g.n; y = (struct zx_di_SecurityContext_s*)y->gg.g.n) ;
    break;
  default:
    for (y = x->SecurityContext; n > 1 && y; --n, y = (struct zx_di_SecurityContext_s*)y->gg.g.n) ;
    if (!y) return;
  }
  z->gg.g.n = y->gg.g.n;
  y->gg.g.n = &z->gg.g;
}

/* FUNC(zx_a_Metadata_DEL_SecurityContext) */

void zx_a_Metadata_DEL_SecurityContext(struct zx_a_Metadata_s* x, int n)
{
  struct zx_di_SecurityContext_s* y;
  if (!x) return;
  switch (n) {
  case 0:
    x->SecurityContext = (struct zx_di_SecurityContext_s*)x->SecurityContext->gg.g.n;
    return;
  case -1:
    y = (struct zx_di_SecurityContext_s*)x->SecurityContext;
    if (!y) return;
    for (; y->gg.g.n; y = (struct zx_di_SecurityContext_s*)y->gg.g.n) ;
    break;
  default:
    for (y = x->SecurityContext; n > 1 && y->gg.g.n; --n, y = (struct zx_di_SecurityContext_s*)y->gg.g.n) ;
    if (!y->gg.g.n) return;
  }
  y->gg.g.n = y->gg.g.n->n;
}

#endif








#ifdef ZX_ENA_GETPUT

/* FUNC(zx_a_ProblemAction_NUM_Action) */

int zx_a_ProblemAction_NUM_Action(struct zx_a_ProblemAction_s* x)
{
  struct zx_a_Action_s* y;
  int n = 0;
  if (!x) return 0;
  for (y = x->Action; y; ++n, y = (struct zx_a_Action_s*)y->gg.g.n) ;
  return n;
}

/* FUNC(zx_a_ProblemAction_GET_Action) */

struct zx_a_Action_s* zx_a_ProblemAction_GET_Action(struct zx_a_ProblemAction_s* x, int n)
{
  struct zx_a_Action_s* y;
  if (!x) return 0;
  for (y = x->Action; n>=0 && y; --n, y = (struct zx_a_Action_s*)y->gg.g.n) ;
  return y;
}

/* FUNC(zx_a_ProblemAction_POP_Action) */

struct zx_a_Action_s* zx_a_ProblemAction_POP_Action(struct zx_a_ProblemAction_s* x)
{
  struct zx_a_Action_s* y;
  if (!x) return 0;
  y = x->Action;
  if (y)
    x->Action = (struct zx_a_Action_s*)y->gg.g.n;
  return y;
}

/* FUNC(zx_a_ProblemAction_PUSH_Action) */

void zx_a_ProblemAction_PUSH_Action(struct zx_a_ProblemAction_s* x, struct zx_a_Action_s* z)
{
  if (!x || !z) return;
  z->gg.g.n = &x->Action->gg.g;
  x->Action = z;
}

/* FUNC(zx_a_ProblemAction_REV_Action) */

void zx_a_ProblemAction_REV_Action(struct zx_a_ProblemAction_s* x)
{
  struct zx_a_Action_s* nxt;
  struct zx_a_Action_s* y;
  if (!x) return;
  y = x->Action;
  if (!y) return;
  x->Action = 0;
  while (y) {
    nxt = (struct zx_a_Action_s*)y->gg.g.n;
    y->gg.g.n = &x->Action->gg.g;
    x->Action = y;
    y = nxt;
  }
}

/* FUNC(zx_a_ProblemAction_PUT_Action) */

void zx_a_ProblemAction_PUT_Action(struct zx_a_ProblemAction_s* x, int n, struct zx_a_Action_s* z)
{
  struct zx_a_Action_s* y;
  if (!x || !z) return;
  y = x->Action;
  if (!y) return;
  switch (n) {
  case 0:
    z->gg.g.n = y->gg.g.n;
    x->Action = z;
    return;
  default:
    for (; n > 1 && y->gg.g.n; --n, y = (struct zx_a_Action_s*)y->gg.g.n) ;
    if (!y->gg.g.n) return;
    z->gg.g.n = y->gg.g.n->n;
    y->gg.g.n = &z->gg.g;
  }
}

/* FUNC(zx_a_ProblemAction_ADD_Action) */

void zx_a_ProblemAction_ADD_Action(struct zx_a_ProblemAction_s* x, int n, struct zx_a_Action_s* z)
{
  struct zx_a_Action_s* y;
  if (!x || !z) return;
  switch (n) {
  case 0:
  add_to_start:
    z->gg.g.n = &x->Action->gg.g;
    x->Action = z;
    return;
  case -1:
    y = x->Action;
    if (!y) goto add_to_start;
    for (; y->gg.g.n; y = (struct zx_a_Action_s*)y->gg.g.n) ;
    break;
  default:
    for (y = x->Action; n > 1 && y; --n, y = (struct zx_a_Action_s*)y->gg.g.n) ;
    if (!y) return;
  }
  z->gg.g.n = y->gg.g.n;
  y->gg.g.n = &z->gg.g;
}

/* FUNC(zx_a_ProblemAction_DEL_Action) */

void zx_a_ProblemAction_DEL_Action(struct zx_a_ProblemAction_s* x, int n)
{
  struct zx_a_Action_s* y;
  if (!x) return;
  switch (n) {
  case 0:
    x->Action = (struct zx_a_Action_s*)x->Action->gg.g.n;
    return;
  case -1:
    y = (struct zx_a_Action_s*)x->Action;
    if (!y) return;
    for (; y->gg.g.n; y = (struct zx_a_Action_s*)y->gg.g.n) ;
    break;
  default:
    for (y = x->Action; n > 1 && y->gg.g.n; --n, y = (struct zx_a_Action_s*)y->gg.g.n) ;
    if (!y->gg.g.n) return;
  }
  y->gg.g.n = y->gg.g.n->n;
}

#endif



#ifdef ZX_ENA_GETPUT

/* FUNC(zx_a_ProblemAction_NUM_SoapAction) */

int zx_a_ProblemAction_NUM_SoapAction(struct zx_a_ProblemAction_s* x)
{
  struct zx_elem_s* y;
  int n = 0;
  if (!x) return 0;
  for (y = x->SoapAction; y; ++n, y = (struct zx_elem_s*)y->g.n) ;
  return n;
}

/* FUNC(zx_a_ProblemAction_GET_SoapAction) */

struct zx_elem_s* zx_a_ProblemAction_GET_SoapAction(struct zx_a_ProblemAction_s* x, int n)
{
  struct zx_elem_s* y;
  if (!x) return 0;
  for (y = x->SoapAction; n>=0 && y; --n, y = (struct zx_elem_s*)y->g.n) ;
  return y;
}

/* FUNC(zx_a_ProblemAction_POP_SoapAction) */

struct zx_elem_s* zx_a_ProblemAction_POP_SoapAction(struct zx_a_ProblemAction_s* x)
{
  struct zx_elem_s* y;
  if (!x) return 0;
  y = x->SoapAction;
  if (y)
    x->SoapAction = (struct zx_elem_s*)y->g.n;
  return y;
}

/* FUNC(zx_a_ProblemAction_PUSH_SoapAction) */

void zx_a_ProblemAction_PUSH_SoapAction(struct zx_a_ProblemAction_s* x, struct zx_elem_s* z)
{
  if (!x || !z) return;
  z->g.n = &x->SoapAction->g;
  x->SoapAction = z;
}

/* FUNC(zx_a_ProblemAction_REV_SoapAction) */

void zx_a_ProblemAction_REV_SoapAction(struct zx_a_ProblemAction_s* x)
{
  struct zx_elem_s* nxt;
  struct zx_elem_s* y;
  if (!x) return;
  y = x->SoapAction;
  if (!y) return;
  x->SoapAction = 0;
  while (y) {
    nxt = (struct zx_elem_s*)y->g.n;
    y->g.n = &x->SoapAction->g;
    x->SoapAction = y;
    y = nxt;
  }
}

/* FUNC(zx_a_ProblemAction_PUT_SoapAction) */

void zx_a_ProblemAction_PUT_SoapAction(struct zx_a_ProblemAction_s* x, int n, struct zx_elem_s* z)
{
  struct zx_elem_s* y;
  if (!x || !z) return;
  y = x->SoapAction;
  if (!y) return;
  switch (n) {
  case 0:
    z->g.n = y->g.n;
    x->SoapAction = z;
    return;
  default:
    for (; n > 1 && y->g.n; --n, y = (struct zx_elem_s*)y->g.n) ;
    if (!y->g.n) return;
    z->g.n = y->g.n->n;
    y->g.n = &z->g;
  }
}

/* FUNC(zx_a_ProblemAction_ADD_SoapAction) */

void zx_a_ProblemAction_ADD_SoapAction(struct zx_a_ProblemAction_s* x, int n, struct zx_elem_s* z)
{
  struct zx_elem_s* y;
  if (!x || !z) return;
  switch (n) {
  case 0:
  add_to_start:
    z->g.n = &x->SoapAction->g;
    x->SoapAction = z;
    return;
  case -1:
    y = x->SoapAction;
    if (!y) goto add_to_start;
    for (; y->g.n; y = (struct zx_elem_s*)y->g.n) ;
    break;
  default:
    for (y = x->SoapAction; n > 1 && y; --n, y = (struct zx_elem_s*)y->g.n) ;
    if (!y) return;
  }
  z->g.n = y->g.n;
  y->g.n = &z->g;
}

/* FUNC(zx_a_ProblemAction_DEL_SoapAction) */

void zx_a_ProblemAction_DEL_SoapAction(struct zx_a_ProblemAction_s* x, int n)
{
  struct zx_elem_s* y;
  if (!x) return;
  switch (n) {
  case 0:
    x->SoapAction = (struct zx_elem_s*)x->SoapAction->g.n;
    return;
  case -1:
    y = (struct zx_elem_s*)x->SoapAction;
    if (!y) return;
    for (; y->g.n; y = (struct zx_elem_s*)y->g.n) ;
    break;
  default:
    for (y = x->SoapAction; n > 1 && y->g.n; --n, y = (struct zx_elem_s*)y->g.n) ;
    if (!y->g.n) return;
  }
  y->g.n = y->g.n->n;
}

#endif

/* FUNC(zx_a_ProblemAction_GET_ID) */
struct zx_str* zx_a_ProblemAction_GET_ID(struct zx_a_ProblemAction_s* x) { return x->ID; }
/* FUNC(zx_a_ProblemAction_PUT_ID) */
void zx_a_ProblemAction_PUT_ID(struct zx_a_ProblemAction_s* x, struct zx_str* y) { x->ID = y; }
/* FUNC(zx_a_ProblemAction_GET_id) */
struct zx_str* zx_a_ProblemAction_GET_id(struct zx_a_ProblemAction_s* x) { return x->id; }
/* FUNC(zx_a_ProblemAction_PUT_id) */
void zx_a_ProblemAction_PUT_id(struct zx_a_ProblemAction_s* x, struct zx_str* y) { x->id = y; }
/* FUNC(zx_a_ProblemAction_GET_Id) */
struct zx_str* zx_a_ProblemAction_GET_Id(struct zx_a_ProblemAction_s* x) { return x->Id; }
/* FUNC(zx_a_ProblemAction_PUT_Id) */
void zx_a_ProblemAction_PUT_Id(struct zx_a_ProblemAction_s* x, struct zx_str* y) { x->Id = y; }
/* FUNC(zx_a_ProblemAction_GET_actor) */
struct zx_str* zx_a_ProblemAction_GET_actor(struct zx_a_ProblemAction_s* x) { return x->actor; }
/* FUNC(zx_a_ProblemAction_PUT_actor) */
void zx_a_ProblemAction_PUT_actor(struct zx_a_ProblemAction_s* x, struct zx_str* y) { x->actor = y; }
/* FUNC(zx_a_ProblemAction_GET_mustUnderstand) */
struct zx_str* zx_a_ProblemAction_GET_mustUnderstand(struct zx_a_ProblemAction_s* x) { return x->mustUnderstand; }
/* FUNC(zx_a_ProblemAction_PUT_mustUnderstand) */
void zx_a_ProblemAction_PUT_mustUnderstand(struct zx_a_ProblemAction_s* x, struct zx_str* y) { x->mustUnderstand = y; }





/* FUNC(zx_a_ProblemHeader_GET_ID) */
struct zx_str* zx_a_ProblemHeader_GET_ID(struct zx_a_ProblemHeader_s* x) { return x->ID; }
/* FUNC(zx_a_ProblemHeader_PUT_ID) */
void zx_a_ProblemHeader_PUT_ID(struct zx_a_ProblemHeader_s* x, struct zx_str* y) { x->ID = y; }
/* FUNC(zx_a_ProblemHeader_GET_id) */
struct zx_str* zx_a_ProblemHeader_GET_id(struct zx_a_ProblemHeader_s* x) { return x->id; }
/* FUNC(zx_a_ProblemHeader_PUT_id) */
void zx_a_ProblemHeader_PUT_id(struct zx_a_ProblemHeader_s* x, struct zx_str* y) { x->id = y; }
/* FUNC(zx_a_ProblemHeader_GET_Id) */
struct zx_str* zx_a_ProblemHeader_GET_Id(struct zx_a_ProblemHeader_s* x) { return x->Id; }
/* FUNC(zx_a_ProblemHeader_PUT_Id) */
void zx_a_ProblemHeader_PUT_Id(struct zx_a_ProblemHeader_s* x, struct zx_str* y) { x->Id = y; }
/* FUNC(zx_a_ProblemHeader_GET_actor) */
struct zx_str* zx_a_ProblemHeader_GET_actor(struct zx_a_ProblemHeader_s* x) { return x->actor; }
/* FUNC(zx_a_ProblemHeader_PUT_actor) */
void zx_a_ProblemHeader_PUT_actor(struct zx_a_ProblemHeader_s* x, struct zx_str* y) { x->actor = y; }
/* FUNC(zx_a_ProblemHeader_GET_mustUnderstand) */
struct zx_str* zx_a_ProblemHeader_GET_mustUnderstand(struct zx_a_ProblemHeader_s* x) { return x->mustUnderstand; }
/* FUNC(zx_a_ProblemHeader_PUT_mustUnderstand) */
void zx_a_ProblemHeader_PUT_mustUnderstand(struct zx_a_ProblemHeader_s* x, struct zx_str* y) { x->mustUnderstand = y; }





/* FUNC(zx_a_ProblemHeaderQName_GET_ID) */
struct zx_str* zx_a_ProblemHeaderQName_GET_ID(struct zx_a_ProblemHeaderQName_s* x) { return x->ID; }
/* FUNC(zx_a_ProblemHeaderQName_PUT_ID) */
void zx_a_ProblemHeaderQName_PUT_ID(struct zx_a_ProblemHeaderQName_s* x, struct zx_str* y) { x->ID = y; }
/* FUNC(zx_a_ProblemHeaderQName_GET_id) */
struct zx_str* zx_a_ProblemHeaderQName_GET_id(struct zx_a_ProblemHeaderQName_s* x) { return x->id; }
/* FUNC(zx_a_ProblemHeaderQName_PUT_id) */
void zx_a_ProblemHeaderQName_PUT_id(struct zx_a_ProblemHeaderQName_s* x, struct zx_str* y) { x->id = y; }
/* FUNC(zx_a_ProblemHeaderQName_GET_Id) */
struct zx_str* zx_a_ProblemHeaderQName_GET_Id(struct zx_a_ProblemHeaderQName_s* x) { return x->Id; }
/* FUNC(zx_a_ProblemHeaderQName_PUT_Id) */
void zx_a_ProblemHeaderQName_PUT_Id(struct zx_a_ProblemHeaderQName_s* x, struct zx_str* y) { x->Id = y; }
/* FUNC(zx_a_ProblemHeaderQName_GET_actor) */
struct zx_str* zx_a_ProblemHeaderQName_GET_actor(struct zx_a_ProblemHeaderQName_s* x) { return x->actor; }
/* FUNC(zx_a_ProblemHeaderQName_PUT_actor) */
void zx_a_ProblemHeaderQName_PUT_actor(struct zx_a_ProblemHeaderQName_s* x, struct zx_str* y) { x->actor = y; }
/* FUNC(zx_a_ProblemHeaderQName_GET_mustUnderstand) */
struct zx_str* zx_a_ProblemHeaderQName_GET_mustUnderstand(struct zx_a_ProblemHeaderQName_s* x) { return x->mustUnderstand; }
/* FUNC(zx_a_ProblemHeaderQName_PUT_mustUnderstand) */
void zx_a_ProblemHeaderQName_PUT_mustUnderstand(struct zx_a_ProblemHeaderQName_s* x, struct zx_str* y) { x->mustUnderstand = y; }





/* FUNC(zx_a_ProblemURI_GET_ID) */
struct zx_str* zx_a_ProblemURI_GET_ID(struct zx_a_ProblemURI_s* x) { return x->ID; }
/* FUNC(zx_a_ProblemURI_PUT_ID) */
void zx_a_ProblemURI_PUT_ID(struct zx_a_ProblemURI_s* x, struct zx_str* y) { x->ID = y; }
/* FUNC(zx_a_ProblemURI_GET_id) */
struct zx_str* zx_a_ProblemURI_GET_id(struct zx_a_ProblemURI_s* x) { return x->id; }
/* FUNC(zx_a_ProblemURI_PUT_id) */
void zx_a_ProblemURI_PUT_id(struct zx_a_ProblemURI_s* x, struct zx_str* y) { x->id = y; }
/* FUNC(zx_a_ProblemURI_GET_Id) */
struct zx_str* zx_a_ProblemURI_GET_Id(struct zx_a_ProblemURI_s* x) { return x->Id; }
/* FUNC(zx_a_ProblemURI_PUT_Id) */
void zx_a_ProblemURI_PUT_Id(struct zx_a_ProblemURI_s* x, struct zx_str* y) { x->Id = y; }
/* FUNC(zx_a_ProblemURI_GET_actor) */
struct zx_str* zx_a_ProblemURI_GET_actor(struct zx_a_ProblemURI_s* x) { return x->actor; }
/* FUNC(zx_a_ProblemURI_PUT_actor) */
void zx_a_ProblemURI_PUT_actor(struct zx_a_ProblemURI_s* x, struct zx_str* y) { x->actor = y; }
/* FUNC(zx_a_ProblemURI_GET_mustUnderstand) */
struct zx_str* zx_a_ProblemURI_GET_mustUnderstand(struct zx_a_ProblemURI_s* x) { return x->mustUnderstand; }
/* FUNC(zx_a_ProblemURI_PUT_mustUnderstand) */
void zx_a_ProblemURI_PUT_mustUnderstand(struct zx_a_ProblemURI_s* x, struct zx_str* y) { x->mustUnderstand = y; }







#ifdef ZX_ENA_GETPUT

/* FUNC(zx_a_ReferenceParameters_NUM_TargetIdentity) */

int zx_a_ReferenceParameters_NUM_TargetIdentity(struct zx_a_ReferenceParameters_s* x)
{
  struct zx_b_TargetIdentity_s* y;
  int n = 0;
  if (!x) return 0;
  for (y = x->TargetIdentity; y; ++n, y = (struct zx_b_TargetIdentity_s*)y->gg.g.n) ;
  return n;
}

/* FUNC(zx_a_ReferenceParameters_GET_TargetIdentity) */

struct zx_b_TargetIdentity_s* zx_a_ReferenceParameters_GET_TargetIdentity(struct zx_a_ReferenceParameters_s* x, int n)
{
  struct zx_b_TargetIdentity_s* y;
  if (!x) return 0;
  for (y = x->TargetIdentity; n>=0 && y; --n, y = (struct zx_b_TargetIdentity_s*)y->gg.g.n) ;
  return y;
}

/* FUNC(zx_a_ReferenceParameters_POP_TargetIdentity) */

struct zx_b_TargetIdentity_s* zx_a_ReferenceParameters_POP_TargetIdentity(struct zx_a_ReferenceParameters_s* x)
{
  struct zx_b_TargetIdentity_s* y;
  if (!x) return 0;
  y = x->TargetIdentity;
  if (y)
    x->TargetIdentity = (struct zx_b_TargetIdentity_s*)y->gg.g.n;
  return y;
}

/* FUNC(zx_a_ReferenceParameters_PUSH_TargetIdentity) */

void zx_a_ReferenceParameters_PUSH_TargetIdentity(struct zx_a_ReferenceParameters_s* x, struct zx_b_TargetIdentity_s* z)
{
  if (!x || !z) return;
  z->gg.g.n = &x->TargetIdentity->gg.g;
  x->TargetIdentity = z;
}

/* FUNC(zx_a_ReferenceParameters_REV_TargetIdentity) */

void zx_a_ReferenceParameters_REV_TargetIdentity(struct zx_a_ReferenceParameters_s* x)
{
  struct zx_b_TargetIdentity_s* nxt;
  struct zx_b_TargetIdentity_s* y;
  if (!x) return;
  y = x->TargetIdentity;
  if (!y) return;
  x->TargetIdentity = 0;
  while (y) {
    nxt = (struct zx_b_TargetIdentity_s*)y->gg.g.n;
    y->gg.g.n = &x->TargetIdentity->gg.g;
    x->TargetIdentity = y;
    y = nxt;
  }
}

/* FUNC(zx_a_ReferenceParameters_PUT_TargetIdentity) */

void zx_a_ReferenceParameters_PUT_TargetIdentity(struct zx_a_ReferenceParameters_s* x, int n, struct zx_b_TargetIdentity_s* z)
{
  struct zx_b_TargetIdentity_s* y;
  if (!x || !z) return;
  y = x->TargetIdentity;
  if (!y) return;
  switch (n) {
  case 0:
    z->gg.g.n = y->gg.g.n;
    x->TargetIdentity = z;
    return;
  default:
    for (; n > 1 && y->gg.g.n; --n, y = (struct zx_b_TargetIdentity_s*)y->gg.g.n) ;
    if (!y->gg.g.n) return;
    z->gg.g.n = y->gg.g.n->n;
    y->gg.g.n = &z->gg.g;
  }
}

/* FUNC(zx_a_ReferenceParameters_ADD_TargetIdentity) */

void zx_a_ReferenceParameters_ADD_TargetIdentity(struct zx_a_ReferenceParameters_s* x, int n, struct zx_b_TargetIdentity_s* z)
{
  struct zx_b_TargetIdentity_s* y;
  if (!x || !z) return;
  switch (n) {
  case 0:
  add_to_start:
    z->gg.g.n = &x->TargetIdentity->gg.g;
    x->TargetIdentity = z;
    return;
  case -1:
    y = x->TargetIdentity;
    if (!y) goto add_to_start;
    for (; y->gg.g.n; y = (struct zx_b_TargetIdentity_s*)y->gg.g.n) ;
    break;
  default:
    for (y = x->TargetIdentity; n > 1 && y; --n, y = (struct zx_b_TargetIdentity_s*)y->gg.g.n) ;
    if (!y) return;
  }
  z->gg.g.n = y->gg.g.n;
  y->gg.g.n = &z->gg.g;
}

/* FUNC(zx_a_ReferenceParameters_DEL_TargetIdentity) */

void zx_a_ReferenceParameters_DEL_TargetIdentity(struct zx_a_ReferenceParameters_s* x, int n)
{
  struct zx_b_TargetIdentity_s* y;
  if (!x) return;
  switch (n) {
  case 0:
    x->TargetIdentity = (struct zx_b_TargetIdentity_s*)x->TargetIdentity->gg.g.n;
    return;
  case -1:
    y = (struct zx_b_TargetIdentity_s*)x->TargetIdentity;
    if (!y) return;
    for (; y->gg.g.n; y = (struct zx_b_TargetIdentity_s*)y->gg.g.n) ;
    break;
  default:
    for (y = x->TargetIdentity; n > 1 && y->gg.g.n; --n, y = (struct zx_b_TargetIdentity_s*)y->gg.g.n) ;
    if (!y->gg.g.n) return;
  }
  y->gg.g.n = y->gg.g.n->n;
}

#endif

/* FUNC(zx_a_ReferenceParameters_GET_ID) */
struct zx_str* zx_a_ReferenceParameters_GET_ID(struct zx_a_ReferenceParameters_s* x) { return x->ID; }
/* FUNC(zx_a_ReferenceParameters_PUT_ID) */
void zx_a_ReferenceParameters_PUT_ID(struct zx_a_ReferenceParameters_s* x, struct zx_str* y) { x->ID = y; }
/* FUNC(zx_a_ReferenceParameters_GET_id) */
struct zx_str* zx_a_ReferenceParameters_GET_id(struct zx_a_ReferenceParameters_s* x) { return x->id; }
/* FUNC(zx_a_ReferenceParameters_PUT_id) */
void zx_a_ReferenceParameters_PUT_id(struct zx_a_ReferenceParameters_s* x, struct zx_str* y) { x->id = y; }
/* FUNC(zx_a_ReferenceParameters_GET_Id) */
struct zx_str* zx_a_ReferenceParameters_GET_Id(struct zx_a_ReferenceParameters_s* x) { return x->Id; }
/* FUNC(zx_a_ReferenceParameters_PUT_Id) */
void zx_a_ReferenceParameters_PUT_Id(struct zx_a_ReferenceParameters_s* x, struct zx_str* y) { x->Id = y; }
/* FUNC(zx_a_ReferenceParameters_GET_actor) */
struct zx_str* zx_a_ReferenceParameters_GET_actor(struct zx_a_ReferenceParameters_s* x) { return x->actor; }
/* FUNC(zx_a_ReferenceParameters_PUT_actor) */
void zx_a_ReferenceParameters_PUT_actor(struct zx_a_ReferenceParameters_s* x, struct zx_str* y) { x->actor = y; }
/* FUNC(zx_a_ReferenceParameters_GET_mustUnderstand) */
struct zx_str* zx_a_ReferenceParameters_GET_mustUnderstand(struct zx_a_ReferenceParameters_s* x) { return x->mustUnderstand; }
/* FUNC(zx_a_ReferenceParameters_PUT_mustUnderstand) */
void zx_a_ReferenceParameters_PUT_mustUnderstand(struct zx_a_ReferenceParameters_s* x, struct zx_str* y) { x->mustUnderstand = y; }





/* FUNC(zx_a_RelatesTo_GET_ID) */
struct zx_str* zx_a_RelatesTo_GET_ID(struct zx_a_RelatesTo_s* x) { return x->ID; }
/* FUNC(zx_a_RelatesTo_PUT_ID) */
void zx_a_RelatesTo_PUT_ID(struct zx_a_RelatesTo_s* x, struct zx_str* y) { x->ID = y; }
/* FUNC(zx_a_RelatesTo_GET_RelationshipType) */
struct zx_str* zx_a_RelatesTo_GET_RelationshipType(struct zx_a_RelatesTo_s* x) { return x->RelationshipType; }
/* FUNC(zx_a_RelatesTo_PUT_RelationshipType) */
void zx_a_RelatesTo_PUT_RelationshipType(struct zx_a_RelatesTo_s* x, struct zx_str* y) { x->RelationshipType = y; }
/* FUNC(zx_a_RelatesTo_GET_id) */
struct zx_str* zx_a_RelatesTo_GET_id(struct zx_a_RelatesTo_s* x) { return x->id; }
/* FUNC(zx_a_RelatesTo_PUT_id) */
void zx_a_RelatesTo_PUT_id(struct zx_a_RelatesTo_s* x, struct zx_str* y) { x->id = y; }
/* FUNC(zx_a_RelatesTo_GET_Id) */
struct zx_str* zx_a_RelatesTo_GET_Id(struct zx_a_RelatesTo_s* x) { return x->Id; }
/* FUNC(zx_a_RelatesTo_PUT_Id) */
void zx_a_RelatesTo_PUT_Id(struct zx_a_RelatesTo_s* x, struct zx_str* y) { x->Id = y; }
/* FUNC(zx_a_RelatesTo_GET_actor) */
struct zx_str* zx_a_RelatesTo_GET_actor(struct zx_a_RelatesTo_s* x) { return x->actor; }
/* FUNC(zx_a_RelatesTo_PUT_actor) */
void zx_a_RelatesTo_PUT_actor(struct zx_a_RelatesTo_s* x, struct zx_str* y) { x->actor = y; }
/* FUNC(zx_a_RelatesTo_GET_mustUnderstand) */
struct zx_str* zx_a_RelatesTo_GET_mustUnderstand(struct zx_a_RelatesTo_s* x) { return x->mustUnderstand; }
/* FUNC(zx_a_RelatesTo_PUT_mustUnderstand) */
void zx_a_RelatesTo_PUT_mustUnderstand(struct zx_a_RelatesTo_s* x, struct zx_str* y) { x->mustUnderstand = y; }







#ifdef ZX_ENA_GETPUT

/* FUNC(zx_a_ReplyTo_NUM_Address) */

int zx_a_ReplyTo_NUM_Address(struct zx_a_ReplyTo_s* x)
{
  struct zx_a_Address_s* y;
  int n = 0;
  if (!x) return 0;
  for (y = x->Address; y; ++n, y = (struct zx_a_Address_s*)y->gg.g.n) ;
  return n;
}

/* FUNC(zx_a_ReplyTo_GET_Address) */

struct zx_a_Address_s* zx_a_ReplyTo_GET_Address(struct zx_a_ReplyTo_s* x, int n)
{
  struct zx_a_Address_s* y;
  if (!x) return 0;
  for (y = x->Address; n>=0 && y; --n, y = (struct zx_a_Address_s*)y->gg.g.n) ;
  return y;
}

/* FUNC(zx_a_ReplyTo_POP_Address) */

struct zx_a_Address_s* zx_a_ReplyTo_POP_Address(struct zx_a_ReplyTo_s* x)
{
  struct zx_a_Address_s* y;
  if (!x) return 0;
  y = x->Address;
  if (y)
    x->Address = (struct zx_a_Address_s*)y->gg.g.n;
  return y;
}

/* FUNC(zx_a_ReplyTo_PUSH_Address) */

void zx_a_ReplyTo_PUSH_Address(struct zx_a_ReplyTo_s* x, struct zx_a_Address_s* z)
{
  if (!x || !z) return;
  z->gg.g.n = &x->Address->gg.g;
  x->Address = z;
}

/* FUNC(zx_a_ReplyTo_REV_Address) */

void zx_a_ReplyTo_REV_Address(struct zx_a_ReplyTo_s* x)
{
  struct zx_a_Address_s* nxt;
  struct zx_a_Address_s* y;
  if (!x) return;
  y = x->Address;
  if (!y) return;
  x->Address = 0;
  while (y) {
    nxt = (struct zx_a_Address_s*)y->gg.g.n;
    y->gg.g.n = &x->Address->gg.g;
    x->Address = y;
    y = nxt;
  }
}

/* FUNC(zx_a_ReplyTo_PUT_Address) */

void zx_a_ReplyTo_PUT_Address(struct zx_a_ReplyTo_s* x, int n, struct zx_a_Address_s* z)
{
  struct zx_a_Address_s* y;
  if (!x || !z) return;
  y = x->Address;
  if (!y) return;
  switch (n) {
  case 0:
    z->gg.g.n = y->gg.g.n;
    x->Address = z;
    return;
  default:
    for (; n > 1 && y->gg.g.n; --n, y = (struct zx_a_Address_s*)y->gg.g.n) ;
    if (!y->gg.g.n) return;
    z->gg.g.n = y->gg.g.n->n;
    y->gg.g.n = &z->gg.g;
  }
}

/* FUNC(zx_a_ReplyTo_ADD_Address) */

void zx_a_ReplyTo_ADD_Address(struct zx_a_ReplyTo_s* x, int n, struct zx_a_Address_s* z)
{
  struct zx_a_Address_s* y;
  if (!x || !z) return;
  switch (n) {
  case 0:
  add_to_start:
    z->gg.g.n = &x->Address->gg.g;
    x->Address = z;
    return;
  case -1:
    y = x->Address;
    if (!y) goto add_to_start;
    for (; y->gg.g.n; y = (struct zx_a_Address_s*)y->gg.g.n) ;
    break;
  default:
    for (y = x->Address; n > 1 && y; --n, y = (struct zx_a_Address_s*)y->gg.g.n) ;
    if (!y) return;
  }
  z->gg.g.n = y->gg.g.n;
  y->gg.g.n = &z->gg.g;
}

/* FUNC(zx_a_ReplyTo_DEL_Address) */

void zx_a_ReplyTo_DEL_Address(struct zx_a_ReplyTo_s* x, int n)
{
  struct zx_a_Address_s* y;
  if (!x) return;
  switch (n) {
  case 0:
    x->Address = (struct zx_a_Address_s*)x->Address->gg.g.n;
    return;
  case -1:
    y = (struct zx_a_Address_s*)x->Address;
    if (!y) return;
    for (; y->gg.g.n; y = (struct zx_a_Address_s*)y->gg.g.n) ;
    break;
  default:
    for (y = x->Address; n > 1 && y->gg.g.n; --n, y = (struct zx_a_Address_s*)y->gg.g.n) ;
    if (!y->gg.g.n) return;
  }
  y->gg.g.n = y->gg.g.n->n;
}

#endif



#ifdef ZX_ENA_GETPUT

/* FUNC(zx_a_ReplyTo_NUM_ReferenceParameters) */

int zx_a_ReplyTo_NUM_ReferenceParameters(struct zx_a_ReplyTo_s* x)
{
  struct zx_a_ReferenceParameters_s* y;
  int n = 0;
  if (!x) return 0;
  for (y = x->ReferenceParameters; y; ++n, y = (struct zx_a_ReferenceParameters_s*)y->gg.g.n) ;
  return n;
}

/* FUNC(zx_a_ReplyTo_GET_ReferenceParameters) */

struct zx_a_ReferenceParameters_s* zx_a_ReplyTo_GET_ReferenceParameters(struct zx_a_ReplyTo_s* x, int n)
{
  struct zx_a_ReferenceParameters_s* y;
  if (!x) return 0;
  for (y = x->ReferenceParameters; n>=0 && y; --n, y = (struct zx_a_ReferenceParameters_s*)y->gg.g.n) ;
  return y;
}

/* FUNC(zx_a_ReplyTo_POP_ReferenceParameters) */

struct zx_a_ReferenceParameters_s* zx_a_ReplyTo_POP_ReferenceParameters(struct zx_a_ReplyTo_s* x)
{
  struct zx_a_ReferenceParameters_s* y;
  if (!x) return 0;
  y = x->ReferenceParameters;
  if (y)
    x->ReferenceParameters = (struct zx_a_ReferenceParameters_s*)y->gg.g.n;
  return y;
}

/* FUNC(zx_a_ReplyTo_PUSH_ReferenceParameters) */

void zx_a_ReplyTo_PUSH_ReferenceParameters(struct zx_a_ReplyTo_s* x, struct zx_a_ReferenceParameters_s* z)
{
  if (!x || !z) return;
  z->gg.g.n = &x->ReferenceParameters->gg.g;
  x->ReferenceParameters = z;
}

/* FUNC(zx_a_ReplyTo_REV_ReferenceParameters) */

void zx_a_ReplyTo_REV_ReferenceParameters(struct zx_a_ReplyTo_s* x)
{
  struct zx_a_ReferenceParameters_s* nxt;
  struct zx_a_ReferenceParameters_s* y;
  if (!x) return;
  y = x->ReferenceParameters;
  if (!y) return;
  x->ReferenceParameters = 0;
  while (y) {
    nxt = (struct zx_a_ReferenceParameters_s*)y->gg.g.n;
    y->gg.g.n = &x->ReferenceParameters->gg.g;
    x->ReferenceParameters = y;
    y = nxt;
  }
}

/* FUNC(zx_a_ReplyTo_PUT_ReferenceParameters) */

void zx_a_ReplyTo_PUT_ReferenceParameters(struct zx_a_ReplyTo_s* x, int n, struct zx_a_ReferenceParameters_s* z)
{
  struct zx_a_ReferenceParameters_s* y;
  if (!x || !z) return;
  y = x->ReferenceParameters;
  if (!y) return;
  switch (n) {
  case 0:
    z->gg.g.n = y->gg.g.n;
    x->ReferenceParameters = z;
    return;
  default:
    for (; n > 1 && y->gg.g.n; --n, y = (struct zx_a_ReferenceParameters_s*)y->gg.g.n) ;
    if (!y->gg.g.n) return;
    z->gg.g.n = y->gg.g.n->n;
    y->gg.g.n = &z->gg.g;
  }
}

/* FUNC(zx_a_ReplyTo_ADD_ReferenceParameters) */

void zx_a_ReplyTo_ADD_ReferenceParameters(struct zx_a_ReplyTo_s* x, int n, struct zx_a_ReferenceParameters_s* z)
{
  struct zx_a_ReferenceParameters_s* y;
  if (!x || !z) return;
  switch (n) {
  case 0:
  add_to_start:
    z->gg.g.n = &x->ReferenceParameters->gg.g;
    x->ReferenceParameters = z;
    return;
  case -1:
    y = x->ReferenceParameters;
    if (!y) goto add_to_start;
    for (; y->gg.g.n; y = (struct zx_a_ReferenceParameters_s*)y->gg.g.n) ;
    break;
  default:
    for (y = x->ReferenceParameters; n > 1 && y; --n, y = (struct zx_a_ReferenceParameters_s*)y->gg.g.n) ;
    if (!y) return;
  }
  z->gg.g.n = y->gg.g.n;
  y->gg.g.n = &z->gg.g;
}

/* FUNC(zx_a_ReplyTo_DEL_ReferenceParameters) */

void zx_a_ReplyTo_DEL_ReferenceParameters(struct zx_a_ReplyTo_s* x, int n)
{
  struct zx_a_ReferenceParameters_s* y;
  if (!x) return;
  switch (n) {
  case 0:
    x->ReferenceParameters = (struct zx_a_ReferenceParameters_s*)x->ReferenceParameters->gg.g.n;
    return;
  case -1:
    y = (struct zx_a_ReferenceParameters_s*)x->ReferenceParameters;
    if (!y) return;
    for (; y->gg.g.n; y = (struct zx_a_ReferenceParameters_s*)y->gg.g.n) ;
    break;
  default:
    for (y = x->ReferenceParameters; n > 1 && y->gg.g.n; --n, y = (struct zx_a_ReferenceParameters_s*)y->gg.g.n) ;
    if (!y->gg.g.n) return;
  }
  y->gg.g.n = y->gg.g.n->n;
}

#endif



#ifdef ZX_ENA_GETPUT

/* FUNC(zx_a_ReplyTo_NUM_Metadata) */

int zx_a_ReplyTo_NUM_Metadata(struct zx_a_ReplyTo_s* x)
{
  struct zx_a_Metadata_s* y;
  int n = 0;
  if (!x) return 0;
  for (y = x->Metadata; y; ++n, y = (struct zx_a_Metadata_s*)y->gg.g.n) ;
  return n;
}

/* FUNC(zx_a_ReplyTo_GET_Metadata) */

struct zx_a_Metadata_s* zx_a_ReplyTo_GET_Metadata(struct zx_a_ReplyTo_s* x, int n)
{
  struct zx_a_Metadata_s* y;
  if (!x) return 0;
  for (y = x->Metadata; n>=0 && y; --n, y = (struct zx_a_Metadata_s*)y->gg.g.n) ;
  return y;
}

/* FUNC(zx_a_ReplyTo_POP_Metadata) */

struct zx_a_Metadata_s* zx_a_ReplyTo_POP_Metadata(struct zx_a_ReplyTo_s* x)
{
  struct zx_a_Metadata_s* y;
  if (!x) return 0;
  y = x->Metadata;
  if (y)
    x->Metadata = (struct zx_a_Metadata_s*)y->gg.g.n;
  return y;
}

/* FUNC(zx_a_ReplyTo_PUSH_Metadata) */

void zx_a_ReplyTo_PUSH_Metadata(struct zx_a_ReplyTo_s* x, struct zx_a_Metadata_s* z)
{
  if (!x || !z) return;
  z->gg.g.n = &x->Metadata->gg.g;
  x->Metadata = z;
}

/* FUNC(zx_a_ReplyTo_REV_Metadata) */

void zx_a_ReplyTo_REV_Metadata(struct zx_a_ReplyTo_s* x)
{
  struct zx_a_Metadata_s* nxt;
  struct zx_a_Metadata_s* y;
  if (!x) return;
  y = x->Metadata;
  if (!y) return;
  x->Metadata = 0;
  while (y) {
    nxt = (struct zx_a_Metadata_s*)y->gg.g.n;
    y->gg.g.n = &x->Metadata->gg.g;
    x->Metadata = y;
    y = nxt;
  }
}

/* FUNC(zx_a_ReplyTo_PUT_Metadata) */

void zx_a_ReplyTo_PUT_Metadata(struct zx_a_ReplyTo_s* x, int n, struct zx_a_Metadata_s* z)
{
  struct zx_a_Metadata_s* y;
  if (!x || !z) return;
  y = x->Metadata;
  if (!y) return;
  switch (n) {
  case 0:
    z->gg.g.n = y->gg.g.n;
    x->Metadata = z;
    return;
  default:
    for (; n > 1 && y->gg.g.n; --n, y = (struct zx_a_Metadata_s*)y->gg.g.n) ;
    if (!y->gg.g.n) return;
    z->gg.g.n = y->gg.g.n->n;
    y->gg.g.n = &z->gg.g;
  }
}

/* FUNC(zx_a_ReplyTo_ADD_Metadata) */

void zx_a_ReplyTo_ADD_Metadata(struct zx_a_ReplyTo_s* x, int n, struct zx_a_Metadata_s* z)
{
  struct zx_a_Metadata_s* y;
  if (!x || !z) return;
  switch (n) {
  case 0:
  add_to_start:
    z->gg.g.n = &x->Metadata->gg.g;
    x->Metadata = z;
    return;
  case -1:
    y = x->Metadata;
    if (!y) goto add_to_start;
    for (; y->gg.g.n; y = (struct zx_a_Metadata_s*)y->gg.g.n) ;
    break;
  default:
    for (y = x->Metadata; n > 1 && y; --n, y = (struct zx_a_Metadata_s*)y->gg.g.n) ;
    if (!y) return;
  }
  z->gg.g.n = y->gg.g.n;
  y->gg.g.n = &z->gg.g;
}

/* FUNC(zx_a_ReplyTo_DEL_Metadata) */

void zx_a_ReplyTo_DEL_Metadata(struct zx_a_ReplyTo_s* x, int n)
{
  struct zx_a_Metadata_s* y;
  if (!x) return;
  switch (n) {
  case 0:
    x->Metadata = (struct zx_a_Metadata_s*)x->Metadata->gg.g.n;
    return;
  case -1:
    y = (struct zx_a_Metadata_s*)x->Metadata;
    if (!y) return;
    for (; y->gg.g.n; y = (struct zx_a_Metadata_s*)y->gg.g.n) ;
    break;
  default:
    for (y = x->Metadata; n > 1 && y->gg.g.n; --n, y = (struct zx_a_Metadata_s*)y->gg.g.n) ;
    if (!y->gg.g.n) return;
  }
  y->gg.g.n = y->gg.g.n->n;
}

#endif

/* FUNC(zx_a_ReplyTo_GET_ID) */
struct zx_str* zx_a_ReplyTo_GET_ID(struct zx_a_ReplyTo_s* x) { return x->ID; }
/* FUNC(zx_a_ReplyTo_PUT_ID) */
void zx_a_ReplyTo_PUT_ID(struct zx_a_ReplyTo_s* x, struct zx_str* y) { x->ID = y; }
/* FUNC(zx_a_ReplyTo_GET_id) */
struct zx_str* zx_a_ReplyTo_GET_id(struct zx_a_ReplyTo_s* x) { return x->id; }
/* FUNC(zx_a_ReplyTo_PUT_id) */
void zx_a_ReplyTo_PUT_id(struct zx_a_ReplyTo_s* x, struct zx_str* y) { x->id = y; }
/* FUNC(zx_a_ReplyTo_GET_notOnOrAfter) */
struct zx_str* zx_a_ReplyTo_GET_notOnOrAfter(struct zx_a_ReplyTo_s* x) { return x->notOnOrAfter; }
/* FUNC(zx_a_ReplyTo_PUT_notOnOrAfter) */
void zx_a_ReplyTo_PUT_notOnOrAfter(struct zx_a_ReplyTo_s* x, struct zx_str* y) { x->notOnOrAfter = y; }
/* FUNC(zx_a_ReplyTo_GET_Id) */
struct zx_str* zx_a_ReplyTo_GET_Id(struct zx_a_ReplyTo_s* x) { return x->Id; }
/* FUNC(zx_a_ReplyTo_PUT_Id) */
void zx_a_ReplyTo_PUT_Id(struct zx_a_ReplyTo_s* x, struct zx_str* y) { x->Id = y; }
/* FUNC(zx_a_ReplyTo_GET_actor) */
struct zx_str* zx_a_ReplyTo_GET_actor(struct zx_a_ReplyTo_s* x) { return x->actor; }
/* FUNC(zx_a_ReplyTo_PUT_actor) */
void zx_a_ReplyTo_PUT_actor(struct zx_a_ReplyTo_s* x, struct zx_str* y) { x->actor = y; }
/* FUNC(zx_a_ReplyTo_GET_mustUnderstand) */
struct zx_str* zx_a_ReplyTo_GET_mustUnderstand(struct zx_a_ReplyTo_s* x) { return x->mustUnderstand; }
/* FUNC(zx_a_ReplyTo_PUT_mustUnderstand) */
void zx_a_ReplyTo_PUT_mustUnderstand(struct zx_a_ReplyTo_s* x, struct zx_str* y) { x->mustUnderstand = y; }





/* FUNC(zx_a_RetryAfter_GET_ID) */
struct zx_str* zx_a_RetryAfter_GET_ID(struct zx_a_RetryAfter_s* x) { return x->ID; }
/* FUNC(zx_a_RetryAfter_PUT_ID) */
void zx_a_RetryAfter_PUT_ID(struct zx_a_RetryAfter_s* x, struct zx_str* y) { x->ID = y; }
/* FUNC(zx_a_RetryAfter_GET_id) */
struct zx_str* zx_a_RetryAfter_GET_id(struct zx_a_RetryAfter_s* x) { return x->id; }
/* FUNC(zx_a_RetryAfter_PUT_id) */
void zx_a_RetryAfter_PUT_id(struct zx_a_RetryAfter_s* x, struct zx_str* y) { x->id = y; }
/* FUNC(zx_a_RetryAfter_GET_Id) */
struct zx_str* zx_a_RetryAfter_GET_Id(struct zx_a_RetryAfter_s* x) { return x->Id; }
/* FUNC(zx_a_RetryAfter_PUT_Id) */
void zx_a_RetryAfter_PUT_Id(struct zx_a_RetryAfter_s* x, struct zx_str* y) { x->Id = y; }
/* FUNC(zx_a_RetryAfter_GET_actor) */
struct zx_str* zx_a_RetryAfter_GET_actor(struct zx_a_RetryAfter_s* x) { return x->actor; }
/* FUNC(zx_a_RetryAfter_PUT_actor) */
void zx_a_RetryAfter_PUT_actor(struct zx_a_RetryAfter_s* x, struct zx_str* y) { x->actor = y; }
/* FUNC(zx_a_RetryAfter_GET_mustUnderstand) */
struct zx_str* zx_a_RetryAfter_GET_mustUnderstand(struct zx_a_RetryAfter_s* x) { return x->mustUnderstand; }
/* FUNC(zx_a_RetryAfter_PUT_mustUnderstand) */
void zx_a_RetryAfter_PUT_mustUnderstand(struct zx_a_RetryAfter_s* x, struct zx_str* y) { x->mustUnderstand = y; }





/* FUNC(zx_a_To_GET_ID) */
struct zx_str* zx_a_To_GET_ID(struct zx_a_To_s* x) { return x->ID; }
/* FUNC(zx_a_To_PUT_ID) */
void zx_a_To_PUT_ID(struct zx_a_To_s* x, struct zx_str* y) { x->ID = y; }
/* FUNC(zx_a_To_GET_id) */
struct zx_str* zx_a_To_GET_id(struct zx_a_To_s* x) { return x->id; }
/* FUNC(zx_a_To_PUT_id) */
void zx_a_To_PUT_id(struct zx_a_To_s* x, struct zx_str* y) { x->id = y; }
/* FUNC(zx_a_To_GET_Id) */
struct zx_str* zx_a_To_GET_Id(struct zx_a_To_s* x) { return x->Id; }
/* FUNC(zx_a_To_PUT_Id) */
void zx_a_To_PUT_Id(struct zx_a_To_s* x, struct zx_str* y) { x->Id = y; }
/* FUNC(zx_a_To_GET_actor) */
struct zx_str* zx_a_To_GET_actor(struct zx_a_To_s* x) { return x->actor; }
/* FUNC(zx_a_To_PUT_actor) */
void zx_a_To_PUT_actor(struct zx_a_To_s* x, struct zx_str* y) { x->actor = y; }
/* FUNC(zx_a_To_GET_mustUnderstand) */
struct zx_str* zx_a_To_GET_mustUnderstand(struct zx_a_To_s* x) { return x->mustUnderstand; }
/* FUNC(zx_a_To_PUT_mustUnderstand) */
void zx_a_To_PUT_mustUnderstand(struct zx_a_To_s* x, struct zx_str* y) { x->mustUnderstand = y; }





/* EOF -- c/zx-a-getput.c */
