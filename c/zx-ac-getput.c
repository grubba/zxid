/* c/zx-ac-getput.c - WARNING: This file was automatically generated. DO NOT EDIT!
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
#include "c/zx-ac-data.h"



#ifdef ZX_ENA_GETPUT

/* FUNC(zx_ac_ActivationLimit_NUM_ActivationLimitDuration) */

int zx_ac_ActivationLimit_NUM_ActivationLimitDuration(struct zx_ac_ActivationLimit_s* x)
{
  struct zx_ac_ActivationLimitDuration_s* y;
  int n = 0;
  if (!x) return 0;
  for (y = x->ActivationLimitDuration; y; ++n, y = (struct zx_ac_ActivationLimitDuration_s*)y->gg.g.n) ;
  return n;
}

/* FUNC(zx_ac_ActivationLimit_GET_ActivationLimitDuration) */

struct zx_ac_ActivationLimitDuration_s* zx_ac_ActivationLimit_GET_ActivationLimitDuration(struct zx_ac_ActivationLimit_s* x, int n)
{
  struct zx_ac_ActivationLimitDuration_s* y;
  if (!x) return 0;
  for (y = x->ActivationLimitDuration; n>=0 && y; --n, y = (struct zx_ac_ActivationLimitDuration_s*)y->gg.g.n) ;
  return y;
}

/* FUNC(zx_ac_ActivationLimit_POP_ActivationLimitDuration) */

struct zx_ac_ActivationLimitDuration_s* zx_ac_ActivationLimit_POP_ActivationLimitDuration(struct zx_ac_ActivationLimit_s* x)
{
  struct zx_ac_ActivationLimitDuration_s* y;
  if (!x) return 0;
  y = x->ActivationLimitDuration;
  if (y)
    x->ActivationLimitDuration = (struct zx_ac_ActivationLimitDuration_s*)y->gg.g.n;
  return y;
}

/* FUNC(zx_ac_ActivationLimit_PUSH_ActivationLimitDuration) */

void zx_ac_ActivationLimit_PUSH_ActivationLimitDuration(struct zx_ac_ActivationLimit_s* x, struct zx_ac_ActivationLimitDuration_s* z)
{
  if (!x || !z) return;
  z->gg.g.n = &x->ActivationLimitDuration->gg.g;
  x->ActivationLimitDuration = z;
}

/* FUNC(zx_ac_ActivationLimit_REV_ActivationLimitDuration) */

void zx_ac_ActivationLimit_REV_ActivationLimitDuration(struct zx_ac_ActivationLimit_s* x)
{
  struct zx_ac_ActivationLimitDuration_s* nxt;
  struct zx_ac_ActivationLimitDuration_s* y;
  if (!x) return;
  y = x->ActivationLimitDuration;
  if (!y) return;
  x->ActivationLimitDuration = 0;
  while (y) {
    nxt = (struct zx_ac_ActivationLimitDuration_s*)y->gg.g.n;
    y->gg.g.n = &x->ActivationLimitDuration->gg.g;
    x->ActivationLimitDuration = y;
    y = nxt;
  }
}

/* FUNC(zx_ac_ActivationLimit_PUT_ActivationLimitDuration) */

void zx_ac_ActivationLimit_PUT_ActivationLimitDuration(struct zx_ac_ActivationLimit_s* x, int n, struct zx_ac_ActivationLimitDuration_s* z)
{
  struct zx_ac_ActivationLimitDuration_s* y;
  if (!x || !z) return;
  y = x->ActivationLimitDuration;
  if (!y) return;
  switch (n) {
  case 0:
    z->gg.g.n = y->gg.g.n;
    x->ActivationLimitDuration = z;
    return;
  default:
    for (; n > 1 && y->gg.g.n; --n, y = (struct zx_ac_ActivationLimitDuration_s*)y->gg.g.n) ;
    if (!y->gg.g.n) return;
    z->gg.g.n = y->gg.g.n->n;
    y->gg.g.n = &z->gg.g;
  }
}

/* FUNC(zx_ac_ActivationLimit_ADD_ActivationLimitDuration) */

void zx_ac_ActivationLimit_ADD_ActivationLimitDuration(struct zx_ac_ActivationLimit_s* x, int n, struct zx_ac_ActivationLimitDuration_s* z)
{
  struct zx_ac_ActivationLimitDuration_s* y;
  if (!x || !z) return;
  switch (n) {
  case 0:
  add_to_start:
    z->gg.g.n = &x->ActivationLimitDuration->gg.g;
    x->ActivationLimitDuration = z;
    return;
  case -1:
    y = x->ActivationLimitDuration;
    if (!y) goto add_to_start;
    for (; y->gg.g.n; y = (struct zx_ac_ActivationLimitDuration_s*)y->gg.g.n) ;
    break;
  default:
    for (y = x->ActivationLimitDuration; n > 1 && y; --n, y = (struct zx_ac_ActivationLimitDuration_s*)y->gg.g.n) ;
    if (!y) return;
  }
  z->gg.g.n = y->gg.g.n;
  y->gg.g.n = &z->gg.g;
}

/* FUNC(zx_ac_ActivationLimit_DEL_ActivationLimitDuration) */

void zx_ac_ActivationLimit_DEL_ActivationLimitDuration(struct zx_ac_ActivationLimit_s* x, int n)
{
  struct zx_ac_ActivationLimitDuration_s* y;
  if (!x) return;
  switch (n) {
  case 0:
    x->ActivationLimitDuration = (struct zx_ac_ActivationLimitDuration_s*)x->ActivationLimitDuration->gg.g.n;
    return;
  case -1:
    y = (struct zx_ac_ActivationLimitDuration_s*)x->ActivationLimitDuration;
    if (!y) return;
    for (; y->gg.g.n; y = (struct zx_ac_ActivationLimitDuration_s*)y->gg.g.n) ;
    break;
  default:
    for (y = x->ActivationLimitDuration; n > 1 && y->gg.g.n; --n, y = (struct zx_ac_ActivationLimitDuration_s*)y->gg.g.n) ;
    if (!y->gg.g.n) return;
  }
  y->gg.g.n = y->gg.g.n->n;
}

#endif



#ifdef ZX_ENA_GETPUT

/* FUNC(zx_ac_ActivationLimit_NUM_ActivationLimitUsages) */

int zx_ac_ActivationLimit_NUM_ActivationLimitUsages(struct zx_ac_ActivationLimit_s* x)
{
  struct zx_ac_ActivationLimitUsages_s* y;
  int n = 0;
  if (!x) return 0;
  for (y = x->ActivationLimitUsages; y; ++n, y = (struct zx_ac_ActivationLimitUsages_s*)y->gg.g.n) ;
  return n;
}

/* FUNC(zx_ac_ActivationLimit_GET_ActivationLimitUsages) */

struct zx_ac_ActivationLimitUsages_s* zx_ac_ActivationLimit_GET_ActivationLimitUsages(struct zx_ac_ActivationLimit_s* x, int n)
{
  struct zx_ac_ActivationLimitUsages_s* y;
  if (!x) return 0;
  for (y = x->ActivationLimitUsages; n>=0 && y; --n, y = (struct zx_ac_ActivationLimitUsages_s*)y->gg.g.n) ;
  return y;
}

/* FUNC(zx_ac_ActivationLimit_POP_ActivationLimitUsages) */

struct zx_ac_ActivationLimitUsages_s* zx_ac_ActivationLimit_POP_ActivationLimitUsages(struct zx_ac_ActivationLimit_s* x)
{
  struct zx_ac_ActivationLimitUsages_s* y;
  if (!x) return 0;
  y = x->ActivationLimitUsages;
  if (y)
    x->ActivationLimitUsages = (struct zx_ac_ActivationLimitUsages_s*)y->gg.g.n;
  return y;
}

/* FUNC(zx_ac_ActivationLimit_PUSH_ActivationLimitUsages) */

void zx_ac_ActivationLimit_PUSH_ActivationLimitUsages(struct zx_ac_ActivationLimit_s* x, struct zx_ac_ActivationLimitUsages_s* z)
{
  if (!x || !z) return;
  z->gg.g.n = &x->ActivationLimitUsages->gg.g;
  x->ActivationLimitUsages = z;
}

/* FUNC(zx_ac_ActivationLimit_REV_ActivationLimitUsages) */

void zx_ac_ActivationLimit_REV_ActivationLimitUsages(struct zx_ac_ActivationLimit_s* x)
{
  struct zx_ac_ActivationLimitUsages_s* nxt;
  struct zx_ac_ActivationLimitUsages_s* y;
  if (!x) return;
  y = x->ActivationLimitUsages;
  if (!y) return;
  x->ActivationLimitUsages = 0;
  while (y) {
    nxt = (struct zx_ac_ActivationLimitUsages_s*)y->gg.g.n;
    y->gg.g.n = &x->ActivationLimitUsages->gg.g;
    x->ActivationLimitUsages = y;
    y = nxt;
  }
}

/* FUNC(zx_ac_ActivationLimit_PUT_ActivationLimitUsages) */

void zx_ac_ActivationLimit_PUT_ActivationLimitUsages(struct zx_ac_ActivationLimit_s* x, int n, struct zx_ac_ActivationLimitUsages_s* z)
{
  struct zx_ac_ActivationLimitUsages_s* y;
  if (!x || !z) return;
  y = x->ActivationLimitUsages;
  if (!y) return;
  switch (n) {
  case 0:
    z->gg.g.n = y->gg.g.n;
    x->ActivationLimitUsages = z;
    return;
  default:
    for (; n > 1 && y->gg.g.n; --n, y = (struct zx_ac_ActivationLimitUsages_s*)y->gg.g.n) ;
    if (!y->gg.g.n) return;
    z->gg.g.n = y->gg.g.n->n;
    y->gg.g.n = &z->gg.g;
  }
}

/* FUNC(zx_ac_ActivationLimit_ADD_ActivationLimitUsages) */

void zx_ac_ActivationLimit_ADD_ActivationLimitUsages(struct zx_ac_ActivationLimit_s* x, int n, struct zx_ac_ActivationLimitUsages_s* z)
{
  struct zx_ac_ActivationLimitUsages_s* y;
  if (!x || !z) return;
  switch (n) {
  case 0:
  add_to_start:
    z->gg.g.n = &x->ActivationLimitUsages->gg.g;
    x->ActivationLimitUsages = z;
    return;
  case -1:
    y = x->ActivationLimitUsages;
    if (!y) goto add_to_start;
    for (; y->gg.g.n; y = (struct zx_ac_ActivationLimitUsages_s*)y->gg.g.n) ;
    break;
  default:
    for (y = x->ActivationLimitUsages; n > 1 && y; --n, y = (struct zx_ac_ActivationLimitUsages_s*)y->gg.g.n) ;
    if (!y) return;
  }
  z->gg.g.n = y->gg.g.n;
  y->gg.g.n = &z->gg.g;
}

/* FUNC(zx_ac_ActivationLimit_DEL_ActivationLimitUsages) */

void zx_ac_ActivationLimit_DEL_ActivationLimitUsages(struct zx_ac_ActivationLimit_s* x, int n)
{
  struct zx_ac_ActivationLimitUsages_s* y;
  if (!x) return;
  switch (n) {
  case 0:
    x->ActivationLimitUsages = (struct zx_ac_ActivationLimitUsages_s*)x->ActivationLimitUsages->gg.g.n;
    return;
  case -1:
    y = (struct zx_ac_ActivationLimitUsages_s*)x->ActivationLimitUsages;
    if (!y) return;
    for (; y->gg.g.n; y = (struct zx_ac_ActivationLimitUsages_s*)y->gg.g.n) ;
    break;
  default:
    for (y = x->ActivationLimitUsages; n > 1 && y->gg.g.n; --n, y = (struct zx_ac_ActivationLimitUsages_s*)y->gg.g.n) ;
    if (!y->gg.g.n) return;
  }
  y->gg.g.n = y->gg.g.n->n;
}

#endif



#ifdef ZX_ENA_GETPUT

/* FUNC(zx_ac_ActivationLimit_NUM_ActivationLimitSession) */

int zx_ac_ActivationLimit_NUM_ActivationLimitSession(struct zx_ac_ActivationLimit_s* x)
{
  struct zx_elem_s* y;
  int n = 0;
  if (!x) return 0;
  for (y = x->ActivationLimitSession; y; ++n, y = (struct zx_elem_s*)y->g.n) ;
  return n;
}

/* FUNC(zx_ac_ActivationLimit_GET_ActivationLimitSession) */

struct zx_elem_s* zx_ac_ActivationLimit_GET_ActivationLimitSession(struct zx_ac_ActivationLimit_s* x, int n)
{
  struct zx_elem_s* y;
  if (!x) return 0;
  for (y = x->ActivationLimitSession; n>=0 && y; --n, y = (struct zx_elem_s*)y->g.n) ;
  return y;
}

/* FUNC(zx_ac_ActivationLimit_POP_ActivationLimitSession) */

struct zx_elem_s* zx_ac_ActivationLimit_POP_ActivationLimitSession(struct zx_ac_ActivationLimit_s* x)
{
  struct zx_elem_s* y;
  if (!x) return 0;
  y = x->ActivationLimitSession;
  if (y)
    x->ActivationLimitSession = (struct zx_elem_s*)y->g.n;
  return y;
}

/* FUNC(zx_ac_ActivationLimit_PUSH_ActivationLimitSession) */

void zx_ac_ActivationLimit_PUSH_ActivationLimitSession(struct zx_ac_ActivationLimit_s* x, struct zx_elem_s* z)
{
  if (!x || !z) return;
  z->g.n = &x->ActivationLimitSession->g;
  x->ActivationLimitSession = z;
}

/* FUNC(zx_ac_ActivationLimit_REV_ActivationLimitSession) */

void zx_ac_ActivationLimit_REV_ActivationLimitSession(struct zx_ac_ActivationLimit_s* x)
{
  struct zx_elem_s* nxt;
  struct zx_elem_s* y;
  if (!x) return;
  y = x->ActivationLimitSession;
  if (!y) return;
  x->ActivationLimitSession = 0;
  while (y) {
    nxt = (struct zx_elem_s*)y->g.n;
    y->g.n = &x->ActivationLimitSession->g;
    x->ActivationLimitSession = y;
    y = nxt;
  }
}

/* FUNC(zx_ac_ActivationLimit_PUT_ActivationLimitSession) */

void zx_ac_ActivationLimit_PUT_ActivationLimitSession(struct zx_ac_ActivationLimit_s* x, int n, struct zx_elem_s* z)
{
  struct zx_elem_s* y;
  if (!x || !z) return;
  y = x->ActivationLimitSession;
  if (!y) return;
  switch (n) {
  case 0:
    z->g.n = y->g.n;
    x->ActivationLimitSession = z;
    return;
  default:
    for (; n > 1 && y->g.n; --n, y = (struct zx_elem_s*)y->g.n) ;
    if (!y->g.n) return;
    z->g.n = y->g.n->n;
    y->g.n = &z->g;
  }
}

/* FUNC(zx_ac_ActivationLimit_ADD_ActivationLimitSession) */

void zx_ac_ActivationLimit_ADD_ActivationLimitSession(struct zx_ac_ActivationLimit_s* x, int n, struct zx_elem_s* z)
{
  struct zx_elem_s* y;
  if (!x || !z) return;
  switch (n) {
  case 0:
  add_to_start:
    z->g.n = &x->ActivationLimitSession->g;
    x->ActivationLimitSession = z;
    return;
  case -1:
    y = x->ActivationLimitSession;
    if (!y) goto add_to_start;
    for (; y->g.n; y = (struct zx_elem_s*)y->g.n) ;
    break;
  default:
    for (y = x->ActivationLimitSession; n > 1 && y; --n, y = (struct zx_elem_s*)y->g.n) ;
    if (!y) return;
  }
  z->g.n = y->g.n;
  y->g.n = &z->g;
}

/* FUNC(zx_ac_ActivationLimit_DEL_ActivationLimitSession) */

void zx_ac_ActivationLimit_DEL_ActivationLimitSession(struct zx_ac_ActivationLimit_s* x, int n)
{
  struct zx_elem_s* y;
  if (!x) return;
  switch (n) {
  case 0:
    x->ActivationLimitSession = (struct zx_elem_s*)x->ActivationLimitSession->g.n;
    return;
  case -1:
    y = (struct zx_elem_s*)x->ActivationLimitSession;
    if (!y) return;
    for (; y->g.n; y = (struct zx_elem_s*)y->g.n) ;
    break;
  default:
    for (y = x->ActivationLimitSession; n > 1 && y->g.n; --n, y = (struct zx_elem_s*)y->g.n) ;
    if (!y->g.n) return;
  }
  y->g.n = y->g.n->n;
}

#endif






/* FUNC(zx_ac_ActivationLimitDuration_GET_duration) */
struct zx_str* zx_ac_ActivationLimitDuration_GET_duration(struct zx_ac_ActivationLimitDuration_s* x) { return x->duration; }
/* FUNC(zx_ac_ActivationLimitDuration_PUT_duration) */
void zx_ac_ActivationLimitDuration_PUT_duration(struct zx_ac_ActivationLimitDuration_s* x, struct zx_str* y) { x->duration = y; }





/* FUNC(zx_ac_ActivationLimitUsages_GET_number) */
struct zx_str* zx_ac_ActivationLimitUsages_GET_number(struct zx_ac_ActivationLimitUsages_s* x) { return x->number; }
/* FUNC(zx_ac_ActivationLimitUsages_PUT_number) */
void zx_ac_ActivationLimitUsages_PUT_number(struct zx_ac_ActivationLimitUsages_s* x, struct zx_str* y) { x->number = y; }







#ifdef ZX_ENA_GETPUT

/* FUNC(zx_ac_ActivationPin_NUM_Length) */

int zx_ac_ActivationPin_NUM_Length(struct zx_ac_ActivationPin_s* x)
{
  struct zx_ac_Length_s* y;
  int n = 0;
  if (!x) return 0;
  for (y = x->Length; y; ++n, y = (struct zx_ac_Length_s*)y->gg.g.n) ;
  return n;
}

/* FUNC(zx_ac_ActivationPin_GET_Length) */

struct zx_ac_Length_s* zx_ac_ActivationPin_GET_Length(struct zx_ac_ActivationPin_s* x, int n)
{
  struct zx_ac_Length_s* y;
  if (!x) return 0;
  for (y = x->Length; n>=0 && y; --n, y = (struct zx_ac_Length_s*)y->gg.g.n) ;
  return y;
}

/* FUNC(zx_ac_ActivationPin_POP_Length) */

struct zx_ac_Length_s* zx_ac_ActivationPin_POP_Length(struct zx_ac_ActivationPin_s* x)
{
  struct zx_ac_Length_s* y;
  if (!x) return 0;
  y = x->Length;
  if (y)
    x->Length = (struct zx_ac_Length_s*)y->gg.g.n;
  return y;
}

/* FUNC(zx_ac_ActivationPin_PUSH_Length) */

void zx_ac_ActivationPin_PUSH_Length(struct zx_ac_ActivationPin_s* x, struct zx_ac_Length_s* z)
{
  if (!x || !z) return;
  z->gg.g.n = &x->Length->gg.g;
  x->Length = z;
}

/* FUNC(zx_ac_ActivationPin_REV_Length) */

void zx_ac_ActivationPin_REV_Length(struct zx_ac_ActivationPin_s* x)
{
  struct zx_ac_Length_s* nxt;
  struct zx_ac_Length_s* y;
  if (!x) return;
  y = x->Length;
  if (!y) return;
  x->Length = 0;
  while (y) {
    nxt = (struct zx_ac_Length_s*)y->gg.g.n;
    y->gg.g.n = &x->Length->gg.g;
    x->Length = y;
    y = nxt;
  }
}

/* FUNC(zx_ac_ActivationPin_PUT_Length) */

void zx_ac_ActivationPin_PUT_Length(struct zx_ac_ActivationPin_s* x, int n, struct zx_ac_Length_s* z)
{
  struct zx_ac_Length_s* y;
  if (!x || !z) return;
  y = x->Length;
  if (!y) return;
  switch (n) {
  case 0:
    z->gg.g.n = y->gg.g.n;
    x->Length = z;
    return;
  default:
    for (; n > 1 && y->gg.g.n; --n, y = (struct zx_ac_Length_s*)y->gg.g.n) ;
    if (!y->gg.g.n) return;
    z->gg.g.n = y->gg.g.n->n;
    y->gg.g.n = &z->gg.g;
  }
}

/* FUNC(zx_ac_ActivationPin_ADD_Length) */

void zx_ac_ActivationPin_ADD_Length(struct zx_ac_ActivationPin_s* x, int n, struct zx_ac_Length_s* z)
{
  struct zx_ac_Length_s* y;
  if (!x || !z) return;
  switch (n) {
  case 0:
  add_to_start:
    z->gg.g.n = &x->Length->gg.g;
    x->Length = z;
    return;
  case -1:
    y = x->Length;
    if (!y) goto add_to_start;
    for (; y->gg.g.n; y = (struct zx_ac_Length_s*)y->gg.g.n) ;
    break;
  default:
    for (y = x->Length; n > 1 && y; --n, y = (struct zx_ac_Length_s*)y->gg.g.n) ;
    if (!y) return;
  }
  z->gg.g.n = y->gg.g.n;
  y->gg.g.n = &z->gg.g;
}

/* FUNC(zx_ac_ActivationPin_DEL_Length) */

void zx_ac_ActivationPin_DEL_Length(struct zx_ac_ActivationPin_s* x, int n)
{
  struct zx_ac_Length_s* y;
  if (!x) return;
  switch (n) {
  case 0:
    x->Length = (struct zx_ac_Length_s*)x->Length->gg.g.n;
    return;
  case -1:
    y = (struct zx_ac_Length_s*)x->Length;
    if (!y) return;
    for (; y->gg.g.n; y = (struct zx_ac_Length_s*)y->gg.g.n) ;
    break;
  default:
    for (y = x->Length; n > 1 && y->gg.g.n; --n, y = (struct zx_ac_Length_s*)y->gg.g.n) ;
    if (!y->gg.g.n) return;
  }
  y->gg.g.n = y->gg.g.n->n;
}

#endif



#ifdef ZX_ENA_GETPUT

/* FUNC(zx_ac_ActivationPin_NUM_Alphabet) */

int zx_ac_ActivationPin_NUM_Alphabet(struct zx_ac_ActivationPin_s* x)
{
  struct zx_ac_Alphabet_s* y;
  int n = 0;
  if (!x) return 0;
  for (y = x->Alphabet; y; ++n, y = (struct zx_ac_Alphabet_s*)y->gg.g.n) ;
  return n;
}

/* FUNC(zx_ac_ActivationPin_GET_Alphabet) */

struct zx_ac_Alphabet_s* zx_ac_ActivationPin_GET_Alphabet(struct zx_ac_ActivationPin_s* x, int n)
{
  struct zx_ac_Alphabet_s* y;
  if (!x) return 0;
  for (y = x->Alphabet; n>=0 && y; --n, y = (struct zx_ac_Alphabet_s*)y->gg.g.n) ;
  return y;
}

/* FUNC(zx_ac_ActivationPin_POP_Alphabet) */

struct zx_ac_Alphabet_s* zx_ac_ActivationPin_POP_Alphabet(struct zx_ac_ActivationPin_s* x)
{
  struct zx_ac_Alphabet_s* y;
  if (!x) return 0;
  y = x->Alphabet;
  if (y)
    x->Alphabet = (struct zx_ac_Alphabet_s*)y->gg.g.n;
  return y;
}

/* FUNC(zx_ac_ActivationPin_PUSH_Alphabet) */

void zx_ac_ActivationPin_PUSH_Alphabet(struct zx_ac_ActivationPin_s* x, struct zx_ac_Alphabet_s* z)
{
  if (!x || !z) return;
  z->gg.g.n = &x->Alphabet->gg.g;
  x->Alphabet = z;
}

/* FUNC(zx_ac_ActivationPin_REV_Alphabet) */

void zx_ac_ActivationPin_REV_Alphabet(struct zx_ac_ActivationPin_s* x)
{
  struct zx_ac_Alphabet_s* nxt;
  struct zx_ac_Alphabet_s* y;
  if (!x) return;
  y = x->Alphabet;
  if (!y) return;
  x->Alphabet = 0;
  while (y) {
    nxt = (struct zx_ac_Alphabet_s*)y->gg.g.n;
    y->gg.g.n = &x->Alphabet->gg.g;
    x->Alphabet = y;
    y = nxt;
  }
}

/* FUNC(zx_ac_ActivationPin_PUT_Alphabet) */

void zx_ac_ActivationPin_PUT_Alphabet(struct zx_ac_ActivationPin_s* x, int n, struct zx_ac_Alphabet_s* z)
{
  struct zx_ac_Alphabet_s* y;
  if (!x || !z) return;
  y = x->Alphabet;
  if (!y) return;
  switch (n) {
  case 0:
    z->gg.g.n = y->gg.g.n;
    x->Alphabet = z;
    return;
  default:
    for (; n > 1 && y->gg.g.n; --n, y = (struct zx_ac_Alphabet_s*)y->gg.g.n) ;
    if (!y->gg.g.n) return;
    z->gg.g.n = y->gg.g.n->n;
    y->gg.g.n = &z->gg.g;
  }
}

/* FUNC(zx_ac_ActivationPin_ADD_Alphabet) */

void zx_ac_ActivationPin_ADD_Alphabet(struct zx_ac_ActivationPin_s* x, int n, struct zx_ac_Alphabet_s* z)
{
  struct zx_ac_Alphabet_s* y;
  if (!x || !z) return;
  switch (n) {
  case 0:
  add_to_start:
    z->gg.g.n = &x->Alphabet->gg.g;
    x->Alphabet = z;
    return;
  case -1:
    y = x->Alphabet;
    if (!y) goto add_to_start;
    for (; y->gg.g.n; y = (struct zx_ac_Alphabet_s*)y->gg.g.n) ;
    break;
  default:
    for (y = x->Alphabet; n > 1 && y; --n, y = (struct zx_ac_Alphabet_s*)y->gg.g.n) ;
    if (!y) return;
  }
  z->gg.g.n = y->gg.g.n;
  y->gg.g.n = &z->gg.g;
}

/* FUNC(zx_ac_ActivationPin_DEL_Alphabet) */

void zx_ac_ActivationPin_DEL_Alphabet(struct zx_ac_ActivationPin_s* x, int n)
{
  struct zx_ac_Alphabet_s* y;
  if (!x) return;
  switch (n) {
  case 0:
    x->Alphabet = (struct zx_ac_Alphabet_s*)x->Alphabet->gg.g.n;
    return;
  case -1:
    y = (struct zx_ac_Alphabet_s*)x->Alphabet;
    if (!y) return;
    for (; y->gg.g.n; y = (struct zx_ac_Alphabet_s*)y->gg.g.n) ;
    break;
  default:
    for (y = x->Alphabet; n > 1 && y->gg.g.n; --n, y = (struct zx_ac_Alphabet_s*)y->gg.g.n) ;
    if (!y->gg.g.n) return;
  }
  y->gg.g.n = y->gg.g.n->n;
}

#endif



#ifdef ZX_ENA_GETPUT

/* FUNC(zx_ac_ActivationPin_NUM_Generation) */

int zx_ac_ActivationPin_NUM_Generation(struct zx_ac_ActivationPin_s* x)
{
  struct zx_ac_Generation_s* y;
  int n = 0;
  if (!x) return 0;
  for (y = x->Generation; y; ++n, y = (struct zx_ac_Generation_s*)y->gg.g.n) ;
  return n;
}

/* FUNC(zx_ac_ActivationPin_GET_Generation) */

struct zx_ac_Generation_s* zx_ac_ActivationPin_GET_Generation(struct zx_ac_ActivationPin_s* x, int n)
{
  struct zx_ac_Generation_s* y;
  if (!x) return 0;
  for (y = x->Generation; n>=0 && y; --n, y = (struct zx_ac_Generation_s*)y->gg.g.n) ;
  return y;
}

/* FUNC(zx_ac_ActivationPin_POP_Generation) */

struct zx_ac_Generation_s* zx_ac_ActivationPin_POP_Generation(struct zx_ac_ActivationPin_s* x)
{
  struct zx_ac_Generation_s* y;
  if (!x) return 0;
  y = x->Generation;
  if (y)
    x->Generation = (struct zx_ac_Generation_s*)y->gg.g.n;
  return y;
}

/* FUNC(zx_ac_ActivationPin_PUSH_Generation) */

void zx_ac_ActivationPin_PUSH_Generation(struct zx_ac_ActivationPin_s* x, struct zx_ac_Generation_s* z)
{
  if (!x || !z) return;
  z->gg.g.n = &x->Generation->gg.g;
  x->Generation = z;
}

/* FUNC(zx_ac_ActivationPin_REV_Generation) */

void zx_ac_ActivationPin_REV_Generation(struct zx_ac_ActivationPin_s* x)
{
  struct zx_ac_Generation_s* nxt;
  struct zx_ac_Generation_s* y;
  if (!x) return;
  y = x->Generation;
  if (!y) return;
  x->Generation = 0;
  while (y) {
    nxt = (struct zx_ac_Generation_s*)y->gg.g.n;
    y->gg.g.n = &x->Generation->gg.g;
    x->Generation = y;
    y = nxt;
  }
}

/* FUNC(zx_ac_ActivationPin_PUT_Generation) */

void zx_ac_ActivationPin_PUT_Generation(struct zx_ac_ActivationPin_s* x, int n, struct zx_ac_Generation_s* z)
{
  struct zx_ac_Generation_s* y;
  if (!x || !z) return;
  y = x->Generation;
  if (!y) return;
  switch (n) {
  case 0:
    z->gg.g.n = y->gg.g.n;
    x->Generation = z;
    return;
  default:
    for (; n > 1 && y->gg.g.n; --n, y = (struct zx_ac_Generation_s*)y->gg.g.n) ;
    if (!y->gg.g.n) return;
    z->gg.g.n = y->gg.g.n->n;
    y->gg.g.n = &z->gg.g;
  }
}

/* FUNC(zx_ac_ActivationPin_ADD_Generation) */

void zx_ac_ActivationPin_ADD_Generation(struct zx_ac_ActivationPin_s* x, int n, struct zx_ac_Generation_s* z)
{
  struct zx_ac_Generation_s* y;
  if (!x || !z) return;
  switch (n) {
  case 0:
  add_to_start:
    z->gg.g.n = &x->Generation->gg.g;
    x->Generation = z;
    return;
  case -1:
    y = x->Generation;
    if (!y) goto add_to_start;
    for (; y->gg.g.n; y = (struct zx_ac_Generation_s*)y->gg.g.n) ;
    break;
  default:
    for (y = x->Generation; n > 1 && y; --n, y = (struct zx_ac_Generation_s*)y->gg.g.n) ;
    if (!y) return;
  }
  z->gg.g.n = y->gg.g.n;
  y->gg.g.n = &z->gg.g;
}

/* FUNC(zx_ac_ActivationPin_DEL_Generation) */

void zx_ac_ActivationPin_DEL_Generation(struct zx_ac_ActivationPin_s* x, int n)
{
  struct zx_ac_Generation_s* y;
  if (!x) return;
  switch (n) {
  case 0:
    x->Generation = (struct zx_ac_Generation_s*)x->Generation->gg.g.n;
    return;
  case -1:
    y = (struct zx_ac_Generation_s*)x->Generation;
    if (!y) return;
    for (; y->gg.g.n; y = (struct zx_ac_Generation_s*)y->gg.g.n) ;
    break;
  default:
    for (y = x->Generation; n > 1 && y->gg.g.n; --n, y = (struct zx_ac_Generation_s*)y->gg.g.n) ;
    if (!y->gg.g.n) return;
  }
  y->gg.g.n = y->gg.g.n->n;
}

#endif



#ifdef ZX_ENA_GETPUT

/* FUNC(zx_ac_ActivationPin_NUM_ActivationLimit) */

int zx_ac_ActivationPin_NUM_ActivationLimit(struct zx_ac_ActivationPin_s* x)
{
  struct zx_ac_ActivationLimit_s* y;
  int n = 0;
  if (!x) return 0;
  for (y = x->ActivationLimit; y; ++n, y = (struct zx_ac_ActivationLimit_s*)y->gg.g.n) ;
  return n;
}

/* FUNC(zx_ac_ActivationPin_GET_ActivationLimit) */

struct zx_ac_ActivationLimit_s* zx_ac_ActivationPin_GET_ActivationLimit(struct zx_ac_ActivationPin_s* x, int n)
{
  struct zx_ac_ActivationLimit_s* y;
  if (!x) return 0;
  for (y = x->ActivationLimit; n>=0 && y; --n, y = (struct zx_ac_ActivationLimit_s*)y->gg.g.n) ;
  return y;
}

/* FUNC(zx_ac_ActivationPin_POP_ActivationLimit) */

struct zx_ac_ActivationLimit_s* zx_ac_ActivationPin_POP_ActivationLimit(struct zx_ac_ActivationPin_s* x)
{
  struct zx_ac_ActivationLimit_s* y;
  if (!x) return 0;
  y = x->ActivationLimit;
  if (y)
    x->ActivationLimit = (struct zx_ac_ActivationLimit_s*)y->gg.g.n;
  return y;
}

/* FUNC(zx_ac_ActivationPin_PUSH_ActivationLimit) */

void zx_ac_ActivationPin_PUSH_ActivationLimit(struct zx_ac_ActivationPin_s* x, struct zx_ac_ActivationLimit_s* z)
{
  if (!x || !z) return;
  z->gg.g.n = &x->ActivationLimit->gg.g;
  x->ActivationLimit = z;
}

/* FUNC(zx_ac_ActivationPin_REV_ActivationLimit) */

void zx_ac_ActivationPin_REV_ActivationLimit(struct zx_ac_ActivationPin_s* x)
{
  struct zx_ac_ActivationLimit_s* nxt;
  struct zx_ac_ActivationLimit_s* y;
  if (!x) return;
  y = x->ActivationLimit;
  if (!y) return;
  x->ActivationLimit = 0;
  while (y) {
    nxt = (struct zx_ac_ActivationLimit_s*)y->gg.g.n;
    y->gg.g.n = &x->ActivationLimit->gg.g;
    x->ActivationLimit = y;
    y = nxt;
  }
}

/* FUNC(zx_ac_ActivationPin_PUT_ActivationLimit) */

void zx_ac_ActivationPin_PUT_ActivationLimit(struct zx_ac_ActivationPin_s* x, int n, struct zx_ac_ActivationLimit_s* z)
{
  struct zx_ac_ActivationLimit_s* y;
  if (!x || !z) return;
  y = x->ActivationLimit;
  if (!y) return;
  switch (n) {
  case 0:
    z->gg.g.n = y->gg.g.n;
    x->ActivationLimit = z;
    return;
  default:
    for (; n > 1 && y->gg.g.n; --n, y = (struct zx_ac_ActivationLimit_s*)y->gg.g.n) ;
    if (!y->gg.g.n) return;
    z->gg.g.n = y->gg.g.n->n;
    y->gg.g.n = &z->gg.g;
  }
}

/* FUNC(zx_ac_ActivationPin_ADD_ActivationLimit) */

void zx_ac_ActivationPin_ADD_ActivationLimit(struct zx_ac_ActivationPin_s* x, int n, struct zx_ac_ActivationLimit_s* z)
{
  struct zx_ac_ActivationLimit_s* y;
  if (!x || !z) return;
  switch (n) {
  case 0:
  add_to_start:
    z->gg.g.n = &x->ActivationLimit->gg.g;
    x->ActivationLimit = z;
    return;
  case -1:
    y = x->ActivationLimit;
    if (!y) goto add_to_start;
    for (; y->gg.g.n; y = (struct zx_ac_ActivationLimit_s*)y->gg.g.n) ;
    break;
  default:
    for (y = x->ActivationLimit; n > 1 && y; --n, y = (struct zx_ac_ActivationLimit_s*)y->gg.g.n) ;
    if (!y) return;
  }
  z->gg.g.n = y->gg.g.n;
  y->gg.g.n = &z->gg.g;
}

/* FUNC(zx_ac_ActivationPin_DEL_ActivationLimit) */

void zx_ac_ActivationPin_DEL_ActivationLimit(struct zx_ac_ActivationPin_s* x, int n)
{
  struct zx_ac_ActivationLimit_s* y;
  if (!x) return;
  switch (n) {
  case 0:
    x->ActivationLimit = (struct zx_ac_ActivationLimit_s*)x->ActivationLimit->gg.g.n;
    return;
  case -1:
    y = (struct zx_ac_ActivationLimit_s*)x->ActivationLimit;
    if (!y) return;
    for (; y->gg.g.n; y = (struct zx_ac_ActivationLimit_s*)y->gg.g.n) ;
    break;
  default:
    for (y = x->ActivationLimit; n > 1 && y->gg.g.n; --n, y = (struct zx_ac_ActivationLimit_s*)y->gg.g.n) ;
    if (!y->gg.g.n) return;
  }
  y->gg.g.n = y->gg.g.n->n;
}

#endif



#ifdef ZX_ENA_GETPUT

/* FUNC(zx_ac_ActivationPin_NUM_Extension) */

int zx_ac_ActivationPin_NUM_Extension(struct zx_ac_ActivationPin_s* x)
{
  struct zx_ac_Extension_s* y;
  int n = 0;
  if (!x) return 0;
  for (y = x->Extension; y; ++n, y = (struct zx_ac_Extension_s*)y->gg.g.n) ;
  return n;
}

/* FUNC(zx_ac_ActivationPin_GET_Extension) */

struct zx_ac_Extension_s* zx_ac_ActivationPin_GET_Extension(struct zx_ac_ActivationPin_s* x, int n)
{
  struct zx_ac_Extension_s* y;
  if (!x) return 0;
  for (y = x->Extension; n>=0 && y; --n, y = (struct zx_ac_Extension_s*)y->gg.g.n) ;
  return y;
}

/* FUNC(zx_ac_ActivationPin_POP_Extension) */

struct zx_ac_Extension_s* zx_ac_ActivationPin_POP_Extension(struct zx_ac_ActivationPin_s* x)
{
  struct zx_ac_Extension_s* y;
  if (!x) return 0;
  y = x->Extension;
  if (y)
    x->Extension = (struct zx_ac_Extension_s*)y->gg.g.n;
  return y;
}

/* FUNC(zx_ac_ActivationPin_PUSH_Extension) */

void zx_ac_ActivationPin_PUSH_Extension(struct zx_ac_ActivationPin_s* x, struct zx_ac_Extension_s* z)
{
  if (!x || !z) return;
  z->gg.g.n = &x->Extension->gg.g;
  x->Extension = z;
}

/* FUNC(zx_ac_ActivationPin_REV_Extension) */

void zx_ac_ActivationPin_REV_Extension(struct zx_ac_ActivationPin_s* x)
{
  struct zx_ac_Extension_s* nxt;
  struct zx_ac_Extension_s* y;
  if (!x) return;
  y = x->Extension;
  if (!y) return;
  x->Extension = 0;
  while (y) {
    nxt = (struct zx_ac_Extension_s*)y->gg.g.n;
    y->gg.g.n = &x->Extension->gg.g;
    x->Extension = y;
    y = nxt;
  }
}

/* FUNC(zx_ac_ActivationPin_PUT_Extension) */

void zx_ac_ActivationPin_PUT_Extension(struct zx_ac_ActivationPin_s* x, int n, struct zx_ac_Extension_s* z)
{
  struct zx_ac_Extension_s* y;
  if (!x || !z) return;
  y = x->Extension;
  if (!y) return;
  switch (n) {
  case 0:
    z->gg.g.n = y->gg.g.n;
    x->Extension = z;
    return;
  default:
    for (; n > 1 && y->gg.g.n; --n, y = (struct zx_ac_Extension_s*)y->gg.g.n) ;
    if (!y->gg.g.n) return;
    z->gg.g.n = y->gg.g.n->n;
    y->gg.g.n = &z->gg.g;
  }
}

/* FUNC(zx_ac_ActivationPin_ADD_Extension) */

void zx_ac_ActivationPin_ADD_Extension(struct zx_ac_ActivationPin_s* x, int n, struct zx_ac_Extension_s* z)
{
  struct zx_ac_Extension_s* y;
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
    for (; y->gg.g.n; y = (struct zx_ac_Extension_s*)y->gg.g.n) ;
    break;
  default:
    for (y = x->Extension; n > 1 && y; --n, y = (struct zx_ac_Extension_s*)y->gg.g.n) ;
    if (!y) return;
  }
  z->gg.g.n = y->gg.g.n;
  y->gg.g.n = &z->gg.g;
}

/* FUNC(zx_ac_ActivationPin_DEL_Extension) */

void zx_ac_ActivationPin_DEL_Extension(struct zx_ac_ActivationPin_s* x, int n)
{
  struct zx_ac_Extension_s* y;
  if (!x) return;
  switch (n) {
  case 0:
    x->Extension = (struct zx_ac_Extension_s*)x->Extension->gg.g.n;
    return;
  case -1:
    y = (struct zx_ac_Extension_s*)x->Extension;
    if (!y) return;
    for (; y->gg.g.n; y = (struct zx_ac_Extension_s*)y->gg.g.n) ;
    break;
  default:
    for (y = x->Extension; n > 1 && y->gg.g.n; --n, y = (struct zx_ac_Extension_s*)y->gg.g.n) ;
    if (!y->gg.g.n) return;
  }
  y->gg.g.n = y->gg.g.n->n;
}

#endif






/* FUNC(zx_ac_Alphabet_GET_case_is_c_keyword) */
struct zx_str* zx_ac_Alphabet_GET_case_is_c_keyword(struct zx_ac_Alphabet_s* x) { return x->case_is_c_keyword; }
/* FUNC(zx_ac_Alphabet_PUT_case_is_c_keyword) */
void zx_ac_Alphabet_PUT_case_is_c_keyword(struct zx_ac_Alphabet_s* x, struct zx_str* y) { x->case_is_c_keyword = y; }
/* FUNC(zx_ac_Alphabet_GET_excludedChars) */
struct zx_str* zx_ac_Alphabet_GET_excludedChars(struct zx_ac_Alphabet_s* x) { return x->excludedChars; }
/* FUNC(zx_ac_Alphabet_PUT_excludedChars) */
void zx_ac_Alphabet_PUT_excludedChars(struct zx_ac_Alphabet_s* x, struct zx_str* y) { x->excludedChars = y; }
/* FUNC(zx_ac_Alphabet_GET_requiredChars) */
struct zx_str* zx_ac_Alphabet_GET_requiredChars(struct zx_ac_Alphabet_s* x) { return x->requiredChars; }
/* FUNC(zx_ac_Alphabet_PUT_requiredChars) */
void zx_ac_Alphabet_PUT_requiredChars(struct zx_ac_Alphabet_s* x, struct zx_str* y) { x->requiredChars = y; }







#ifdef ZX_ENA_GETPUT

/* FUNC(zx_ac_AsymmetricDecryption_NUM_Extension) */

int zx_ac_AsymmetricDecryption_NUM_Extension(struct zx_ac_AsymmetricDecryption_s* x)
{
  struct zx_ac_Extension_s* y;
  int n = 0;
  if (!x) return 0;
  for (y = x->Extension; y; ++n, y = (struct zx_ac_Extension_s*)y->gg.g.n) ;
  return n;
}

/* FUNC(zx_ac_AsymmetricDecryption_GET_Extension) */

struct zx_ac_Extension_s* zx_ac_AsymmetricDecryption_GET_Extension(struct zx_ac_AsymmetricDecryption_s* x, int n)
{
  struct zx_ac_Extension_s* y;
  if (!x) return 0;
  for (y = x->Extension; n>=0 && y; --n, y = (struct zx_ac_Extension_s*)y->gg.g.n) ;
  return y;
}

/* FUNC(zx_ac_AsymmetricDecryption_POP_Extension) */

struct zx_ac_Extension_s* zx_ac_AsymmetricDecryption_POP_Extension(struct zx_ac_AsymmetricDecryption_s* x)
{
  struct zx_ac_Extension_s* y;
  if (!x) return 0;
  y = x->Extension;
  if (y)
    x->Extension = (struct zx_ac_Extension_s*)y->gg.g.n;
  return y;
}

/* FUNC(zx_ac_AsymmetricDecryption_PUSH_Extension) */

void zx_ac_AsymmetricDecryption_PUSH_Extension(struct zx_ac_AsymmetricDecryption_s* x, struct zx_ac_Extension_s* z)
{
  if (!x || !z) return;
  z->gg.g.n = &x->Extension->gg.g;
  x->Extension = z;
}

/* FUNC(zx_ac_AsymmetricDecryption_REV_Extension) */

void zx_ac_AsymmetricDecryption_REV_Extension(struct zx_ac_AsymmetricDecryption_s* x)
{
  struct zx_ac_Extension_s* nxt;
  struct zx_ac_Extension_s* y;
  if (!x) return;
  y = x->Extension;
  if (!y) return;
  x->Extension = 0;
  while (y) {
    nxt = (struct zx_ac_Extension_s*)y->gg.g.n;
    y->gg.g.n = &x->Extension->gg.g;
    x->Extension = y;
    y = nxt;
  }
}

/* FUNC(zx_ac_AsymmetricDecryption_PUT_Extension) */

void zx_ac_AsymmetricDecryption_PUT_Extension(struct zx_ac_AsymmetricDecryption_s* x, int n, struct zx_ac_Extension_s* z)
{
  struct zx_ac_Extension_s* y;
  if (!x || !z) return;
  y = x->Extension;
  if (!y) return;
  switch (n) {
  case 0:
    z->gg.g.n = y->gg.g.n;
    x->Extension = z;
    return;
  default:
    for (; n > 1 && y->gg.g.n; --n, y = (struct zx_ac_Extension_s*)y->gg.g.n) ;
    if (!y->gg.g.n) return;
    z->gg.g.n = y->gg.g.n->n;
    y->gg.g.n = &z->gg.g;
  }
}

/* FUNC(zx_ac_AsymmetricDecryption_ADD_Extension) */

void zx_ac_AsymmetricDecryption_ADD_Extension(struct zx_ac_AsymmetricDecryption_s* x, int n, struct zx_ac_Extension_s* z)
{
  struct zx_ac_Extension_s* y;
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
    for (; y->gg.g.n; y = (struct zx_ac_Extension_s*)y->gg.g.n) ;
    break;
  default:
    for (y = x->Extension; n > 1 && y; --n, y = (struct zx_ac_Extension_s*)y->gg.g.n) ;
    if (!y) return;
  }
  z->gg.g.n = y->gg.g.n;
  y->gg.g.n = &z->gg.g;
}

/* FUNC(zx_ac_AsymmetricDecryption_DEL_Extension) */

void zx_ac_AsymmetricDecryption_DEL_Extension(struct zx_ac_AsymmetricDecryption_s* x, int n)
{
  struct zx_ac_Extension_s* y;
  if (!x) return;
  switch (n) {
  case 0:
    x->Extension = (struct zx_ac_Extension_s*)x->Extension->gg.g.n;
    return;
  case -1:
    y = (struct zx_ac_Extension_s*)x->Extension;
    if (!y) return;
    for (; y->gg.g.n; y = (struct zx_ac_Extension_s*)y->gg.g.n) ;
    break;
  default:
    for (y = x->Extension; n > 1 && y->gg.g.n; --n, y = (struct zx_ac_Extension_s*)y->gg.g.n) ;
    if (!y->gg.g.n) return;
  }
  y->gg.g.n = y->gg.g.n->n;
}

#endif








#ifdef ZX_ENA_GETPUT

/* FUNC(zx_ac_AsymmetricKeyAgreement_NUM_Extension) */

int zx_ac_AsymmetricKeyAgreement_NUM_Extension(struct zx_ac_AsymmetricKeyAgreement_s* x)
{
  struct zx_ac_Extension_s* y;
  int n = 0;
  if (!x) return 0;
  for (y = x->Extension; y; ++n, y = (struct zx_ac_Extension_s*)y->gg.g.n) ;
  return n;
}

/* FUNC(zx_ac_AsymmetricKeyAgreement_GET_Extension) */

struct zx_ac_Extension_s* zx_ac_AsymmetricKeyAgreement_GET_Extension(struct zx_ac_AsymmetricKeyAgreement_s* x, int n)
{
  struct zx_ac_Extension_s* y;
  if (!x) return 0;
  for (y = x->Extension; n>=0 && y; --n, y = (struct zx_ac_Extension_s*)y->gg.g.n) ;
  return y;
}

/* FUNC(zx_ac_AsymmetricKeyAgreement_POP_Extension) */

struct zx_ac_Extension_s* zx_ac_AsymmetricKeyAgreement_POP_Extension(struct zx_ac_AsymmetricKeyAgreement_s* x)
{
  struct zx_ac_Extension_s* y;
  if (!x) return 0;
  y = x->Extension;
  if (y)
    x->Extension = (struct zx_ac_Extension_s*)y->gg.g.n;
  return y;
}

/* FUNC(zx_ac_AsymmetricKeyAgreement_PUSH_Extension) */

void zx_ac_AsymmetricKeyAgreement_PUSH_Extension(struct zx_ac_AsymmetricKeyAgreement_s* x, struct zx_ac_Extension_s* z)
{
  if (!x || !z) return;
  z->gg.g.n = &x->Extension->gg.g;
  x->Extension = z;
}

/* FUNC(zx_ac_AsymmetricKeyAgreement_REV_Extension) */

void zx_ac_AsymmetricKeyAgreement_REV_Extension(struct zx_ac_AsymmetricKeyAgreement_s* x)
{
  struct zx_ac_Extension_s* nxt;
  struct zx_ac_Extension_s* y;
  if (!x) return;
  y = x->Extension;
  if (!y) return;
  x->Extension = 0;
  while (y) {
    nxt = (struct zx_ac_Extension_s*)y->gg.g.n;
    y->gg.g.n = &x->Extension->gg.g;
    x->Extension = y;
    y = nxt;
  }
}

/* FUNC(zx_ac_AsymmetricKeyAgreement_PUT_Extension) */

void zx_ac_AsymmetricKeyAgreement_PUT_Extension(struct zx_ac_AsymmetricKeyAgreement_s* x, int n, struct zx_ac_Extension_s* z)
{
  struct zx_ac_Extension_s* y;
  if (!x || !z) return;
  y = x->Extension;
  if (!y) return;
  switch (n) {
  case 0:
    z->gg.g.n = y->gg.g.n;
    x->Extension = z;
    return;
  default:
    for (; n > 1 && y->gg.g.n; --n, y = (struct zx_ac_Extension_s*)y->gg.g.n) ;
    if (!y->gg.g.n) return;
    z->gg.g.n = y->gg.g.n->n;
    y->gg.g.n = &z->gg.g;
  }
}

/* FUNC(zx_ac_AsymmetricKeyAgreement_ADD_Extension) */

void zx_ac_AsymmetricKeyAgreement_ADD_Extension(struct zx_ac_AsymmetricKeyAgreement_s* x, int n, struct zx_ac_Extension_s* z)
{
  struct zx_ac_Extension_s* y;
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
    for (; y->gg.g.n; y = (struct zx_ac_Extension_s*)y->gg.g.n) ;
    break;
  default:
    for (y = x->Extension; n > 1 && y; --n, y = (struct zx_ac_Extension_s*)y->gg.g.n) ;
    if (!y) return;
  }
  z->gg.g.n = y->gg.g.n;
  y->gg.g.n = &z->gg.g;
}

/* FUNC(zx_ac_AsymmetricKeyAgreement_DEL_Extension) */

void zx_ac_AsymmetricKeyAgreement_DEL_Extension(struct zx_ac_AsymmetricKeyAgreement_s* x, int n)
{
  struct zx_ac_Extension_s* y;
  if (!x) return;
  switch (n) {
  case 0:
    x->Extension = (struct zx_ac_Extension_s*)x->Extension->gg.g.n;
    return;
  case -1:
    y = (struct zx_ac_Extension_s*)x->Extension;
    if (!y) return;
    for (; y->gg.g.n; y = (struct zx_ac_Extension_s*)y->gg.g.n) ;
    break;
  default:
    for (y = x->Extension; n > 1 && y->gg.g.n; --n, y = (struct zx_ac_Extension_s*)y->gg.g.n) ;
    if (!y->gg.g.n) return;
  }
  y->gg.g.n = y->gg.g.n->n;
}

#endif








#ifdef ZX_ENA_GETPUT

/* FUNC(zx_ac_AuthenticatingAuthority_NUM_GoverningAgreements) */

int zx_ac_AuthenticatingAuthority_NUM_GoverningAgreements(struct zx_ac_AuthenticatingAuthority_s* x)
{
  struct zx_ac_GoverningAgreements_s* y;
  int n = 0;
  if (!x) return 0;
  for (y = x->GoverningAgreements; y; ++n, y = (struct zx_ac_GoverningAgreements_s*)y->gg.g.n) ;
  return n;
}

/* FUNC(zx_ac_AuthenticatingAuthority_GET_GoverningAgreements) */

struct zx_ac_GoverningAgreements_s* zx_ac_AuthenticatingAuthority_GET_GoverningAgreements(struct zx_ac_AuthenticatingAuthority_s* x, int n)
{
  struct zx_ac_GoverningAgreements_s* y;
  if (!x) return 0;
  for (y = x->GoverningAgreements; n>=0 && y; --n, y = (struct zx_ac_GoverningAgreements_s*)y->gg.g.n) ;
  return y;
}

/* FUNC(zx_ac_AuthenticatingAuthority_POP_GoverningAgreements) */

struct zx_ac_GoverningAgreements_s* zx_ac_AuthenticatingAuthority_POP_GoverningAgreements(struct zx_ac_AuthenticatingAuthority_s* x)
{
  struct zx_ac_GoverningAgreements_s* y;
  if (!x) return 0;
  y = x->GoverningAgreements;
  if (y)
    x->GoverningAgreements = (struct zx_ac_GoverningAgreements_s*)y->gg.g.n;
  return y;
}

/* FUNC(zx_ac_AuthenticatingAuthority_PUSH_GoverningAgreements) */

void zx_ac_AuthenticatingAuthority_PUSH_GoverningAgreements(struct zx_ac_AuthenticatingAuthority_s* x, struct zx_ac_GoverningAgreements_s* z)
{
  if (!x || !z) return;
  z->gg.g.n = &x->GoverningAgreements->gg.g;
  x->GoverningAgreements = z;
}

/* FUNC(zx_ac_AuthenticatingAuthority_REV_GoverningAgreements) */

void zx_ac_AuthenticatingAuthority_REV_GoverningAgreements(struct zx_ac_AuthenticatingAuthority_s* x)
{
  struct zx_ac_GoverningAgreements_s* nxt;
  struct zx_ac_GoverningAgreements_s* y;
  if (!x) return;
  y = x->GoverningAgreements;
  if (!y) return;
  x->GoverningAgreements = 0;
  while (y) {
    nxt = (struct zx_ac_GoverningAgreements_s*)y->gg.g.n;
    y->gg.g.n = &x->GoverningAgreements->gg.g;
    x->GoverningAgreements = y;
    y = nxt;
  }
}

/* FUNC(zx_ac_AuthenticatingAuthority_PUT_GoverningAgreements) */

void zx_ac_AuthenticatingAuthority_PUT_GoverningAgreements(struct zx_ac_AuthenticatingAuthority_s* x, int n, struct zx_ac_GoverningAgreements_s* z)
{
  struct zx_ac_GoverningAgreements_s* y;
  if (!x || !z) return;
  y = x->GoverningAgreements;
  if (!y) return;
  switch (n) {
  case 0:
    z->gg.g.n = y->gg.g.n;
    x->GoverningAgreements = z;
    return;
  default:
    for (; n > 1 && y->gg.g.n; --n, y = (struct zx_ac_GoverningAgreements_s*)y->gg.g.n) ;
    if (!y->gg.g.n) return;
    z->gg.g.n = y->gg.g.n->n;
    y->gg.g.n = &z->gg.g;
  }
}

/* FUNC(zx_ac_AuthenticatingAuthority_ADD_GoverningAgreements) */

void zx_ac_AuthenticatingAuthority_ADD_GoverningAgreements(struct zx_ac_AuthenticatingAuthority_s* x, int n, struct zx_ac_GoverningAgreements_s* z)
{
  struct zx_ac_GoverningAgreements_s* y;
  if (!x || !z) return;
  switch (n) {
  case 0:
  add_to_start:
    z->gg.g.n = &x->GoverningAgreements->gg.g;
    x->GoverningAgreements = z;
    return;
  case -1:
    y = x->GoverningAgreements;
    if (!y) goto add_to_start;
    for (; y->gg.g.n; y = (struct zx_ac_GoverningAgreements_s*)y->gg.g.n) ;
    break;
  default:
    for (y = x->GoverningAgreements; n > 1 && y; --n, y = (struct zx_ac_GoverningAgreements_s*)y->gg.g.n) ;
    if (!y) return;
  }
  z->gg.g.n = y->gg.g.n;
  y->gg.g.n = &z->gg.g;
}

/* FUNC(zx_ac_AuthenticatingAuthority_DEL_GoverningAgreements) */

void zx_ac_AuthenticatingAuthority_DEL_GoverningAgreements(struct zx_ac_AuthenticatingAuthority_s* x, int n)
{
  struct zx_ac_GoverningAgreements_s* y;
  if (!x) return;
  switch (n) {
  case 0:
    x->GoverningAgreements = (struct zx_ac_GoverningAgreements_s*)x->GoverningAgreements->gg.g.n;
    return;
  case -1:
    y = (struct zx_ac_GoverningAgreements_s*)x->GoverningAgreements;
    if (!y) return;
    for (; y->gg.g.n; y = (struct zx_ac_GoverningAgreements_s*)y->gg.g.n) ;
    break;
  default:
    for (y = x->GoverningAgreements; n > 1 && y->gg.g.n; --n, y = (struct zx_ac_GoverningAgreements_s*)y->gg.g.n) ;
    if (!y->gg.g.n) return;
  }
  y->gg.g.n = y->gg.g.n->n;
}

#endif

/* FUNC(zx_ac_AuthenticatingAuthority_GET_ID) */
struct zx_str* zx_ac_AuthenticatingAuthority_GET_ID(struct zx_ac_AuthenticatingAuthority_s* x) { return x->ID; }
/* FUNC(zx_ac_AuthenticatingAuthority_PUT_ID) */
void zx_ac_AuthenticatingAuthority_PUT_ID(struct zx_ac_AuthenticatingAuthority_s* x, struct zx_str* y) { x->ID = y; }







#ifdef ZX_ENA_GETPUT

/* FUNC(zx_ac_AuthenticationContextStatement_NUM_Identification) */

int zx_ac_AuthenticationContextStatement_NUM_Identification(struct zx_ac_AuthenticationContextStatement_s* x)
{
  struct zx_ac_Identification_s* y;
  int n = 0;
  if (!x) return 0;
  for (y = x->Identification; y; ++n, y = (struct zx_ac_Identification_s*)y->gg.g.n) ;
  return n;
}

/* FUNC(zx_ac_AuthenticationContextStatement_GET_Identification) */

struct zx_ac_Identification_s* zx_ac_AuthenticationContextStatement_GET_Identification(struct zx_ac_AuthenticationContextStatement_s* x, int n)
{
  struct zx_ac_Identification_s* y;
  if (!x) return 0;
  for (y = x->Identification; n>=0 && y; --n, y = (struct zx_ac_Identification_s*)y->gg.g.n) ;
  return y;
}

/* FUNC(zx_ac_AuthenticationContextStatement_POP_Identification) */

struct zx_ac_Identification_s* zx_ac_AuthenticationContextStatement_POP_Identification(struct zx_ac_AuthenticationContextStatement_s* x)
{
  struct zx_ac_Identification_s* y;
  if (!x) return 0;
  y = x->Identification;
  if (y)
    x->Identification = (struct zx_ac_Identification_s*)y->gg.g.n;
  return y;
}

/* FUNC(zx_ac_AuthenticationContextStatement_PUSH_Identification) */

void zx_ac_AuthenticationContextStatement_PUSH_Identification(struct zx_ac_AuthenticationContextStatement_s* x, struct zx_ac_Identification_s* z)
{
  if (!x || !z) return;
  z->gg.g.n = &x->Identification->gg.g;
  x->Identification = z;
}

/* FUNC(zx_ac_AuthenticationContextStatement_REV_Identification) */

void zx_ac_AuthenticationContextStatement_REV_Identification(struct zx_ac_AuthenticationContextStatement_s* x)
{
  struct zx_ac_Identification_s* nxt;
  struct zx_ac_Identification_s* y;
  if (!x) return;
  y = x->Identification;
  if (!y) return;
  x->Identification = 0;
  while (y) {
    nxt = (struct zx_ac_Identification_s*)y->gg.g.n;
    y->gg.g.n = &x->Identification->gg.g;
    x->Identification = y;
    y = nxt;
  }
}

/* FUNC(zx_ac_AuthenticationContextStatement_PUT_Identification) */

void zx_ac_AuthenticationContextStatement_PUT_Identification(struct zx_ac_AuthenticationContextStatement_s* x, int n, struct zx_ac_Identification_s* z)
{
  struct zx_ac_Identification_s* y;
  if (!x || !z) return;
  y = x->Identification;
  if (!y) return;
  switch (n) {
  case 0:
    z->gg.g.n = y->gg.g.n;
    x->Identification = z;
    return;
  default:
    for (; n > 1 && y->gg.g.n; --n, y = (struct zx_ac_Identification_s*)y->gg.g.n) ;
    if (!y->gg.g.n) return;
    z->gg.g.n = y->gg.g.n->n;
    y->gg.g.n = &z->gg.g;
  }
}

/* FUNC(zx_ac_AuthenticationContextStatement_ADD_Identification) */

void zx_ac_AuthenticationContextStatement_ADD_Identification(struct zx_ac_AuthenticationContextStatement_s* x, int n, struct zx_ac_Identification_s* z)
{
  struct zx_ac_Identification_s* y;
  if (!x || !z) return;
  switch (n) {
  case 0:
  add_to_start:
    z->gg.g.n = &x->Identification->gg.g;
    x->Identification = z;
    return;
  case -1:
    y = x->Identification;
    if (!y) goto add_to_start;
    for (; y->gg.g.n; y = (struct zx_ac_Identification_s*)y->gg.g.n) ;
    break;
  default:
    for (y = x->Identification; n > 1 && y; --n, y = (struct zx_ac_Identification_s*)y->gg.g.n) ;
    if (!y) return;
  }
  z->gg.g.n = y->gg.g.n;
  y->gg.g.n = &z->gg.g;
}

/* FUNC(zx_ac_AuthenticationContextStatement_DEL_Identification) */

void zx_ac_AuthenticationContextStatement_DEL_Identification(struct zx_ac_AuthenticationContextStatement_s* x, int n)
{
  struct zx_ac_Identification_s* y;
  if (!x) return;
  switch (n) {
  case 0:
    x->Identification = (struct zx_ac_Identification_s*)x->Identification->gg.g.n;
    return;
  case -1:
    y = (struct zx_ac_Identification_s*)x->Identification;
    if (!y) return;
    for (; y->gg.g.n; y = (struct zx_ac_Identification_s*)y->gg.g.n) ;
    break;
  default:
    for (y = x->Identification; n > 1 && y->gg.g.n; --n, y = (struct zx_ac_Identification_s*)y->gg.g.n) ;
    if (!y->gg.g.n) return;
  }
  y->gg.g.n = y->gg.g.n->n;
}

#endif



#ifdef ZX_ENA_GETPUT

/* FUNC(zx_ac_AuthenticationContextStatement_NUM_TechnicalProtection) */

int zx_ac_AuthenticationContextStatement_NUM_TechnicalProtection(struct zx_ac_AuthenticationContextStatement_s* x)
{
  struct zx_ac_TechnicalProtection_s* y;
  int n = 0;
  if (!x) return 0;
  for (y = x->TechnicalProtection; y; ++n, y = (struct zx_ac_TechnicalProtection_s*)y->gg.g.n) ;
  return n;
}

/* FUNC(zx_ac_AuthenticationContextStatement_GET_TechnicalProtection) */

struct zx_ac_TechnicalProtection_s* zx_ac_AuthenticationContextStatement_GET_TechnicalProtection(struct zx_ac_AuthenticationContextStatement_s* x, int n)
{
  struct zx_ac_TechnicalProtection_s* y;
  if (!x) return 0;
  for (y = x->TechnicalProtection; n>=0 && y; --n, y = (struct zx_ac_TechnicalProtection_s*)y->gg.g.n) ;
  return y;
}

/* FUNC(zx_ac_AuthenticationContextStatement_POP_TechnicalProtection) */

struct zx_ac_TechnicalProtection_s* zx_ac_AuthenticationContextStatement_POP_TechnicalProtection(struct zx_ac_AuthenticationContextStatement_s* x)
{
  struct zx_ac_TechnicalProtection_s* y;
  if (!x) return 0;
  y = x->TechnicalProtection;
  if (y)
    x->TechnicalProtection = (struct zx_ac_TechnicalProtection_s*)y->gg.g.n;
  return y;
}

/* FUNC(zx_ac_AuthenticationContextStatement_PUSH_TechnicalProtection) */

void zx_ac_AuthenticationContextStatement_PUSH_TechnicalProtection(struct zx_ac_AuthenticationContextStatement_s* x, struct zx_ac_TechnicalProtection_s* z)
{
  if (!x || !z) return;
  z->gg.g.n = &x->TechnicalProtection->gg.g;
  x->TechnicalProtection = z;
}

/* FUNC(zx_ac_AuthenticationContextStatement_REV_TechnicalProtection) */

void zx_ac_AuthenticationContextStatement_REV_TechnicalProtection(struct zx_ac_AuthenticationContextStatement_s* x)
{
  struct zx_ac_TechnicalProtection_s* nxt;
  struct zx_ac_TechnicalProtection_s* y;
  if (!x) return;
  y = x->TechnicalProtection;
  if (!y) return;
  x->TechnicalProtection = 0;
  while (y) {
    nxt = (struct zx_ac_TechnicalProtection_s*)y->gg.g.n;
    y->gg.g.n = &x->TechnicalProtection->gg.g;
    x->TechnicalProtection = y;
    y = nxt;
  }
}

/* FUNC(zx_ac_AuthenticationContextStatement_PUT_TechnicalProtection) */

void zx_ac_AuthenticationContextStatement_PUT_TechnicalProtection(struct zx_ac_AuthenticationContextStatement_s* x, int n, struct zx_ac_TechnicalProtection_s* z)
{
  struct zx_ac_TechnicalProtection_s* y;
  if (!x || !z) return;
  y = x->TechnicalProtection;
  if (!y) return;
  switch (n) {
  case 0:
    z->gg.g.n = y->gg.g.n;
    x->TechnicalProtection = z;
    return;
  default:
    for (; n > 1 && y->gg.g.n; --n, y = (struct zx_ac_TechnicalProtection_s*)y->gg.g.n) ;
    if (!y->gg.g.n) return;
    z->gg.g.n = y->gg.g.n->n;
    y->gg.g.n = &z->gg.g;
  }
}

/* FUNC(zx_ac_AuthenticationContextStatement_ADD_TechnicalProtection) */

void zx_ac_AuthenticationContextStatement_ADD_TechnicalProtection(struct zx_ac_AuthenticationContextStatement_s* x, int n, struct zx_ac_TechnicalProtection_s* z)
{
  struct zx_ac_TechnicalProtection_s* y;
  if (!x || !z) return;
  switch (n) {
  case 0:
  add_to_start:
    z->gg.g.n = &x->TechnicalProtection->gg.g;
    x->TechnicalProtection = z;
    return;
  case -1:
    y = x->TechnicalProtection;
    if (!y) goto add_to_start;
    for (; y->gg.g.n; y = (struct zx_ac_TechnicalProtection_s*)y->gg.g.n) ;
    break;
  default:
    for (y = x->TechnicalProtection; n > 1 && y; --n, y = (struct zx_ac_TechnicalProtection_s*)y->gg.g.n) ;
    if (!y) return;
  }
  z->gg.g.n = y->gg.g.n;
  y->gg.g.n = &z->gg.g;
}

/* FUNC(zx_ac_AuthenticationContextStatement_DEL_TechnicalProtection) */

void zx_ac_AuthenticationContextStatement_DEL_TechnicalProtection(struct zx_ac_AuthenticationContextStatement_s* x, int n)
{
  struct zx_ac_TechnicalProtection_s* y;
  if (!x) return;
  switch (n) {
  case 0:
    x->TechnicalProtection = (struct zx_ac_TechnicalProtection_s*)x->TechnicalProtection->gg.g.n;
    return;
  case -1:
    y = (struct zx_ac_TechnicalProtection_s*)x->TechnicalProtection;
    if (!y) return;
    for (; y->gg.g.n; y = (struct zx_ac_TechnicalProtection_s*)y->gg.g.n) ;
    break;
  default:
    for (y = x->TechnicalProtection; n > 1 && y->gg.g.n; --n, y = (struct zx_ac_TechnicalProtection_s*)y->gg.g.n) ;
    if (!y->gg.g.n) return;
  }
  y->gg.g.n = y->gg.g.n->n;
}

#endif



#ifdef ZX_ENA_GETPUT

/* FUNC(zx_ac_AuthenticationContextStatement_NUM_OperationalProtection) */

int zx_ac_AuthenticationContextStatement_NUM_OperationalProtection(struct zx_ac_AuthenticationContextStatement_s* x)
{
  struct zx_ac_OperationalProtection_s* y;
  int n = 0;
  if (!x) return 0;
  for (y = x->OperationalProtection; y; ++n, y = (struct zx_ac_OperationalProtection_s*)y->gg.g.n) ;
  return n;
}

/* FUNC(zx_ac_AuthenticationContextStatement_GET_OperationalProtection) */

struct zx_ac_OperationalProtection_s* zx_ac_AuthenticationContextStatement_GET_OperationalProtection(struct zx_ac_AuthenticationContextStatement_s* x, int n)
{
  struct zx_ac_OperationalProtection_s* y;
  if (!x) return 0;
  for (y = x->OperationalProtection; n>=0 && y; --n, y = (struct zx_ac_OperationalProtection_s*)y->gg.g.n) ;
  return y;
}

/* FUNC(zx_ac_AuthenticationContextStatement_POP_OperationalProtection) */

struct zx_ac_OperationalProtection_s* zx_ac_AuthenticationContextStatement_POP_OperationalProtection(struct zx_ac_AuthenticationContextStatement_s* x)
{
  struct zx_ac_OperationalProtection_s* y;
  if (!x) return 0;
  y = x->OperationalProtection;
  if (y)
    x->OperationalProtection = (struct zx_ac_OperationalProtection_s*)y->gg.g.n;
  return y;
}

/* FUNC(zx_ac_AuthenticationContextStatement_PUSH_OperationalProtection) */

void zx_ac_AuthenticationContextStatement_PUSH_OperationalProtection(struct zx_ac_AuthenticationContextStatement_s* x, struct zx_ac_OperationalProtection_s* z)
{
  if (!x || !z) return;
  z->gg.g.n = &x->OperationalProtection->gg.g;
  x->OperationalProtection = z;
}

/* FUNC(zx_ac_AuthenticationContextStatement_REV_OperationalProtection) */

void zx_ac_AuthenticationContextStatement_REV_OperationalProtection(struct zx_ac_AuthenticationContextStatement_s* x)
{
  struct zx_ac_OperationalProtection_s* nxt;
  struct zx_ac_OperationalProtection_s* y;
  if (!x) return;
  y = x->OperationalProtection;
  if (!y) return;
  x->OperationalProtection = 0;
  while (y) {
    nxt = (struct zx_ac_OperationalProtection_s*)y->gg.g.n;
    y->gg.g.n = &x->OperationalProtection->gg.g;
    x->OperationalProtection = y;
    y = nxt;
  }
}

/* FUNC(zx_ac_AuthenticationContextStatement_PUT_OperationalProtection) */

void zx_ac_AuthenticationContextStatement_PUT_OperationalProtection(struct zx_ac_AuthenticationContextStatement_s* x, int n, struct zx_ac_OperationalProtection_s* z)
{
  struct zx_ac_OperationalProtection_s* y;
  if (!x || !z) return;
  y = x->OperationalProtection;
  if (!y) return;
  switch (n) {
  case 0:
    z->gg.g.n = y->gg.g.n;
    x->OperationalProtection = z;
    return;
  default:
    for (; n > 1 && y->gg.g.n; --n, y = (struct zx_ac_OperationalProtection_s*)y->gg.g.n) ;
    if (!y->gg.g.n) return;
    z->gg.g.n = y->gg.g.n->n;
    y->gg.g.n = &z->gg.g;
  }
}

/* FUNC(zx_ac_AuthenticationContextStatement_ADD_OperationalProtection) */

void zx_ac_AuthenticationContextStatement_ADD_OperationalProtection(struct zx_ac_AuthenticationContextStatement_s* x, int n, struct zx_ac_OperationalProtection_s* z)
{
  struct zx_ac_OperationalProtection_s* y;
  if (!x || !z) return;
  switch (n) {
  case 0:
  add_to_start:
    z->gg.g.n = &x->OperationalProtection->gg.g;
    x->OperationalProtection = z;
    return;
  case -1:
    y = x->OperationalProtection;
    if (!y) goto add_to_start;
    for (; y->gg.g.n; y = (struct zx_ac_OperationalProtection_s*)y->gg.g.n) ;
    break;
  default:
    for (y = x->OperationalProtection; n > 1 && y; --n, y = (struct zx_ac_OperationalProtection_s*)y->gg.g.n) ;
    if (!y) return;
  }
  z->gg.g.n = y->gg.g.n;
  y->gg.g.n = &z->gg.g;
}

/* FUNC(zx_ac_AuthenticationContextStatement_DEL_OperationalProtection) */

void zx_ac_AuthenticationContextStatement_DEL_OperationalProtection(struct zx_ac_AuthenticationContextStatement_s* x, int n)
{
  struct zx_ac_OperationalProtection_s* y;
  if (!x) return;
  switch (n) {
  case 0:
    x->OperationalProtection = (struct zx_ac_OperationalProtection_s*)x->OperationalProtection->gg.g.n;
    return;
  case -1:
    y = (struct zx_ac_OperationalProtection_s*)x->OperationalProtection;
    if (!y) return;
    for (; y->gg.g.n; y = (struct zx_ac_OperationalProtection_s*)y->gg.g.n) ;
    break;
  default:
    for (y = x->OperationalProtection; n > 1 && y->gg.g.n; --n, y = (struct zx_ac_OperationalProtection_s*)y->gg.g.n) ;
    if (!y->gg.g.n) return;
  }
  y->gg.g.n = y->gg.g.n->n;
}

#endif



#ifdef ZX_ENA_GETPUT

/* FUNC(zx_ac_AuthenticationContextStatement_NUM_AuthenticationMethod) */

int zx_ac_AuthenticationContextStatement_NUM_AuthenticationMethod(struct zx_ac_AuthenticationContextStatement_s* x)
{
  struct zx_ac_AuthenticationMethod_s* y;
  int n = 0;
  if (!x) return 0;
  for (y = x->AuthenticationMethod; y; ++n, y = (struct zx_ac_AuthenticationMethod_s*)y->gg.g.n) ;
  return n;
}

/* FUNC(zx_ac_AuthenticationContextStatement_GET_AuthenticationMethod) */

struct zx_ac_AuthenticationMethod_s* zx_ac_AuthenticationContextStatement_GET_AuthenticationMethod(struct zx_ac_AuthenticationContextStatement_s* x, int n)
{
  struct zx_ac_AuthenticationMethod_s* y;
  if (!x) return 0;
  for (y = x->AuthenticationMethod; n>=0 && y; --n, y = (struct zx_ac_AuthenticationMethod_s*)y->gg.g.n) ;
  return y;
}

/* FUNC(zx_ac_AuthenticationContextStatement_POP_AuthenticationMethod) */

struct zx_ac_AuthenticationMethod_s* zx_ac_AuthenticationContextStatement_POP_AuthenticationMethod(struct zx_ac_AuthenticationContextStatement_s* x)
{
  struct zx_ac_AuthenticationMethod_s* y;
  if (!x) return 0;
  y = x->AuthenticationMethod;
  if (y)
    x->AuthenticationMethod = (struct zx_ac_AuthenticationMethod_s*)y->gg.g.n;
  return y;
}

/* FUNC(zx_ac_AuthenticationContextStatement_PUSH_AuthenticationMethod) */

void zx_ac_AuthenticationContextStatement_PUSH_AuthenticationMethod(struct zx_ac_AuthenticationContextStatement_s* x, struct zx_ac_AuthenticationMethod_s* z)
{
  if (!x || !z) return;
  z->gg.g.n = &x->AuthenticationMethod->gg.g;
  x->AuthenticationMethod = z;
}

/* FUNC(zx_ac_AuthenticationContextStatement_REV_AuthenticationMethod) */

void zx_ac_AuthenticationContextStatement_REV_AuthenticationMethod(struct zx_ac_AuthenticationContextStatement_s* x)
{
  struct zx_ac_AuthenticationMethod_s* nxt;
  struct zx_ac_AuthenticationMethod_s* y;
  if (!x) return;
  y = x->AuthenticationMethod;
  if (!y) return;
  x->AuthenticationMethod = 0;
  while (y) {
    nxt = (struct zx_ac_AuthenticationMethod_s*)y->gg.g.n;
    y->gg.g.n = &x->AuthenticationMethod->gg.g;
    x->AuthenticationMethod = y;
    y = nxt;
  }
}

/* FUNC(zx_ac_AuthenticationContextStatement_PUT_AuthenticationMethod) */

void zx_ac_AuthenticationContextStatement_PUT_AuthenticationMethod(struct zx_ac_AuthenticationContextStatement_s* x, int n, struct zx_ac_AuthenticationMethod_s* z)
{
  struct zx_ac_AuthenticationMethod_s* y;
  if (!x || !z) return;
  y = x->AuthenticationMethod;
  if (!y) return;
  switch (n) {
  case 0:
    z->gg.g.n = y->gg.g.n;
    x->AuthenticationMethod = z;
    return;
  default:
    for (; n > 1 && y->gg.g.n; --n, y = (struct zx_ac_AuthenticationMethod_s*)y->gg.g.n) ;
    if (!y->gg.g.n) return;
    z->gg.g.n = y->gg.g.n->n;
    y->gg.g.n = &z->gg.g;
  }
}

/* FUNC(zx_ac_AuthenticationContextStatement_ADD_AuthenticationMethod) */

void zx_ac_AuthenticationContextStatement_ADD_AuthenticationMethod(struct zx_ac_AuthenticationContextStatement_s* x, int n, struct zx_ac_AuthenticationMethod_s* z)
{
  struct zx_ac_AuthenticationMethod_s* y;
  if (!x || !z) return;
  switch (n) {
  case 0:
  add_to_start:
    z->gg.g.n = &x->AuthenticationMethod->gg.g;
    x->AuthenticationMethod = z;
    return;
  case -1:
    y = x->AuthenticationMethod;
    if (!y) goto add_to_start;
    for (; y->gg.g.n; y = (struct zx_ac_AuthenticationMethod_s*)y->gg.g.n) ;
    break;
  default:
    for (y = x->AuthenticationMethod; n > 1 && y; --n, y = (struct zx_ac_AuthenticationMethod_s*)y->gg.g.n) ;
    if (!y) return;
  }
  z->gg.g.n = y->gg.g.n;
  y->gg.g.n = &z->gg.g;
}

/* FUNC(zx_ac_AuthenticationContextStatement_DEL_AuthenticationMethod) */

void zx_ac_AuthenticationContextStatement_DEL_AuthenticationMethod(struct zx_ac_AuthenticationContextStatement_s* x, int n)
{
  struct zx_ac_AuthenticationMethod_s* y;
  if (!x) return;
  switch (n) {
  case 0:
    x->AuthenticationMethod = (struct zx_ac_AuthenticationMethod_s*)x->AuthenticationMethod->gg.g.n;
    return;
  case -1:
    y = (struct zx_ac_AuthenticationMethod_s*)x->AuthenticationMethod;
    if (!y) return;
    for (; y->gg.g.n; y = (struct zx_ac_AuthenticationMethod_s*)y->gg.g.n) ;
    break;
  default:
    for (y = x->AuthenticationMethod; n > 1 && y->gg.g.n; --n, y = (struct zx_ac_AuthenticationMethod_s*)y->gg.g.n) ;
    if (!y->gg.g.n) return;
  }
  y->gg.g.n = y->gg.g.n->n;
}

#endif



#ifdef ZX_ENA_GETPUT

/* FUNC(zx_ac_AuthenticationContextStatement_NUM_GoverningAgreements) */

int zx_ac_AuthenticationContextStatement_NUM_GoverningAgreements(struct zx_ac_AuthenticationContextStatement_s* x)
{
  struct zx_ac_GoverningAgreements_s* y;
  int n = 0;
  if (!x) return 0;
  for (y = x->GoverningAgreements; y; ++n, y = (struct zx_ac_GoverningAgreements_s*)y->gg.g.n) ;
  return n;
}

/* FUNC(zx_ac_AuthenticationContextStatement_GET_GoverningAgreements) */

struct zx_ac_GoverningAgreements_s* zx_ac_AuthenticationContextStatement_GET_GoverningAgreements(struct zx_ac_AuthenticationContextStatement_s* x, int n)
{
  struct zx_ac_GoverningAgreements_s* y;
  if (!x) return 0;
  for (y = x->GoverningAgreements; n>=0 && y; --n, y = (struct zx_ac_GoverningAgreements_s*)y->gg.g.n) ;
  return y;
}

/* FUNC(zx_ac_AuthenticationContextStatement_POP_GoverningAgreements) */

struct zx_ac_GoverningAgreements_s* zx_ac_AuthenticationContextStatement_POP_GoverningAgreements(struct zx_ac_AuthenticationContextStatement_s* x)
{
  struct zx_ac_GoverningAgreements_s* y;
  if (!x) return 0;
  y = x->GoverningAgreements;
  if (y)
    x->GoverningAgreements = (struct zx_ac_GoverningAgreements_s*)y->gg.g.n;
  return y;
}

/* FUNC(zx_ac_AuthenticationContextStatement_PUSH_GoverningAgreements) */

void zx_ac_AuthenticationContextStatement_PUSH_GoverningAgreements(struct zx_ac_AuthenticationContextStatement_s* x, struct zx_ac_GoverningAgreements_s* z)
{
  if (!x || !z) return;
  z->gg.g.n = &x->GoverningAgreements->gg.g;
  x->GoverningAgreements = z;
}

/* FUNC(zx_ac_AuthenticationContextStatement_REV_GoverningAgreements) */

void zx_ac_AuthenticationContextStatement_REV_GoverningAgreements(struct zx_ac_AuthenticationContextStatement_s* x)
{
  struct zx_ac_GoverningAgreements_s* nxt;
  struct zx_ac_GoverningAgreements_s* y;
  if (!x) return;
  y = x->GoverningAgreements;
  if (!y) return;
  x->GoverningAgreements = 0;
  while (y) {
    nxt = (struct zx_ac_GoverningAgreements_s*)y->gg.g.n;
    y->gg.g.n = &x->GoverningAgreements->gg.g;
    x->GoverningAgreements = y;
    y = nxt;
  }
}

/* FUNC(zx_ac_AuthenticationContextStatement_PUT_GoverningAgreements) */

void zx_ac_AuthenticationContextStatement_PUT_GoverningAgreements(struct zx_ac_AuthenticationContextStatement_s* x, int n, struct zx_ac_GoverningAgreements_s* z)
{
  struct zx_ac_GoverningAgreements_s* y;
  if (!x || !z) return;
  y = x->GoverningAgreements;
  if (!y) return;
  switch (n) {
  case 0:
    z->gg.g.n = y->gg.g.n;
    x->GoverningAgreements = z;
    return;
  default:
    for (; n > 1 && y->gg.g.n; --n, y = (struct zx_ac_GoverningAgreements_s*)y->gg.g.n) ;
    if (!y->gg.g.n) return;
    z->gg.g.n = y->gg.g.n->n;
    y->gg.g.n = &z->gg.g;
  }
}

/* FUNC(zx_ac_AuthenticationContextStatement_ADD_GoverningAgreements) */

void zx_ac_AuthenticationContextStatement_ADD_GoverningAgreements(struct zx_ac_AuthenticationContextStatement_s* x, int n, struct zx_ac_GoverningAgreements_s* z)
{
  struct zx_ac_GoverningAgreements_s* y;
  if (!x || !z) return;
  switch (n) {
  case 0:
  add_to_start:
    z->gg.g.n = &x->GoverningAgreements->gg.g;
    x->GoverningAgreements = z;
    return;
  case -1:
    y = x->GoverningAgreements;
    if (!y) goto add_to_start;
    for (; y->gg.g.n; y = (struct zx_ac_GoverningAgreements_s*)y->gg.g.n) ;
    break;
  default:
    for (y = x->GoverningAgreements; n > 1 && y; --n, y = (struct zx_ac_GoverningAgreements_s*)y->gg.g.n) ;
    if (!y) return;
  }
  z->gg.g.n = y->gg.g.n;
  y->gg.g.n = &z->gg.g;
}

/* FUNC(zx_ac_AuthenticationContextStatement_DEL_GoverningAgreements) */

void zx_ac_AuthenticationContextStatement_DEL_GoverningAgreements(struct zx_ac_AuthenticationContextStatement_s* x, int n)
{
  struct zx_ac_GoverningAgreements_s* y;
  if (!x) return;
  switch (n) {
  case 0:
    x->GoverningAgreements = (struct zx_ac_GoverningAgreements_s*)x->GoverningAgreements->gg.g.n;
    return;
  case -1:
    y = (struct zx_ac_GoverningAgreements_s*)x->GoverningAgreements;
    if (!y) return;
    for (; y->gg.g.n; y = (struct zx_ac_GoverningAgreements_s*)y->gg.g.n) ;
    break;
  default:
    for (y = x->GoverningAgreements; n > 1 && y->gg.g.n; --n, y = (struct zx_ac_GoverningAgreements_s*)y->gg.g.n) ;
    if (!y->gg.g.n) return;
  }
  y->gg.g.n = y->gg.g.n->n;
}

#endif



#ifdef ZX_ENA_GETPUT

/* FUNC(zx_ac_AuthenticationContextStatement_NUM_AuthenticatingAuthority) */

int zx_ac_AuthenticationContextStatement_NUM_AuthenticatingAuthority(struct zx_ac_AuthenticationContextStatement_s* x)
{
  struct zx_ac_AuthenticatingAuthority_s* y;
  int n = 0;
  if (!x) return 0;
  for (y = x->AuthenticatingAuthority; y; ++n, y = (struct zx_ac_AuthenticatingAuthority_s*)y->gg.g.n) ;
  return n;
}

/* FUNC(zx_ac_AuthenticationContextStatement_GET_AuthenticatingAuthority) */

struct zx_ac_AuthenticatingAuthority_s* zx_ac_AuthenticationContextStatement_GET_AuthenticatingAuthority(struct zx_ac_AuthenticationContextStatement_s* x, int n)
{
  struct zx_ac_AuthenticatingAuthority_s* y;
  if (!x) return 0;
  for (y = x->AuthenticatingAuthority; n>=0 && y; --n, y = (struct zx_ac_AuthenticatingAuthority_s*)y->gg.g.n) ;
  return y;
}

/* FUNC(zx_ac_AuthenticationContextStatement_POP_AuthenticatingAuthority) */

struct zx_ac_AuthenticatingAuthority_s* zx_ac_AuthenticationContextStatement_POP_AuthenticatingAuthority(struct zx_ac_AuthenticationContextStatement_s* x)
{
  struct zx_ac_AuthenticatingAuthority_s* y;
  if (!x) return 0;
  y = x->AuthenticatingAuthority;
  if (y)
    x->AuthenticatingAuthority = (struct zx_ac_AuthenticatingAuthority_s*)y->gg.g.n;
  return y;
}

/* FUNC(zx_ac_AuthenticationContextStatement_PUSH_AuthenticatingAuthority) */

void zx_ac_AuthenticationContextStatement_PUSH_AuthenticatingAuthority(struct zx_ac_AuthenticationContextStatement_s* x, struct zx_ac_AuthenticatingAuthority_s* z)
{
  if (!x || !z) return;
  z->gg.g.n = &x->AuthenticatingAuthority->gg.g;
  x->AuthenticatingAuthority = z;
}

/* FUNC(zx_ac_AuthenticationContextStatement_REV_AuthenticatingAuthority) */

void zx_ac_AuthenticationContextStatement_REV_AuthenticatingAuthority(struct zx_ac_AuthenticationContextStatement_s* x)
{
  struct zx_ac_AuthenticatingAuthority_s* nxt;
  struct zx_ac_AuthenticatingAuthority_s* y;
  if (!x) return;
  y = x->AuthenticatingAuthority;
  if (!y) return;
  x->AuthenticatingAuthority = 0;
  while (y) {
    nxt = (struct zx_ac_AuthenticatingAuthority_s*)y->gg.g.n;
    y->gg.g.n = &x->AuthenticatingAuthority->gg.g;
    x->AuthenticatingAuthority = y;
    y = nxt;
  }
}

/* FUNC(zx_ac_AuthenticationContextStatement_PUT_AuthenticatingAuthority) */

void zx_ac_AuthenticationContextStatement_PUT_AuthenticatingAuthority(struct zx_ac_AuthenticationContextStatement_s* x, int n, struct zx_ac_AuthenticatingAuthority_s* z)
{
  struct zx_ac_AuthenticatingAuthority_s* y;
  if (!x || !z) return;
  y = x->AuthenticatingAuthority;
  if (!y) return;
  switch (n) {
  case 0:
    z->gg.g.n = y->gg.g.n;
    x->AuthenticatingAuthority = z;
    return;
  default:
    for (; n > 1 && y->gg.g.n; --n, y = (struct zx_ac_AuthenticatingAuthority_s*)y->gg.g.n) ;
    if (!y->gg.g.n) return;
    z->gg.g.n = y->gg.g.n->n;
    y->gg.g.n = &z->gg.g;
  }
}

/* FUNC(zx_ac_AuthenticationContextStatement_ADD_AuthenticatingAuthority) */

void zx_ac_AuthenticationContextStatement_ADD_AuthenticatingAuthority(struct zx_ac_AuthenticationContextStatement_s* x, int n, struct zx_ac_AuthenticatingAuthority_s* z)
{
  struct zx_ac_AuthenticatingAuthority_s* y;
  if (!x || !z) return;
  switch (n) {
  case 0:
  add_to_start:
    z->gg.g.n = &x->AuthenticatingAuthority->gg.g;
    x->AuthenticatingAuthority = z;
    return;
  case -1:
    y = x->AuthenticatingAuthority;
    if (!y) goto add_to_start;
    for (; y->gg.g.n; y = (struct zx_ac_AuthenticatingAuthority_s*)y->gg.g.n) ;
    break;
  default:
    for (y = x->AuthenticatingAuthority; n > 1 && y; --n, y = (struct zx_ac_AuthenticatingAuthority_s*)y->gg.g.n) ;
    if (!y) return;
  }
  z->gg.g.n = y->gg.g.n;
  y->gg.g.n = &z->gg.g;
}

/* FUNC(zx_ac_AuthenticationContextStatement_DEL_AuthenticatingAuthority) */

void zx_ac_AuthenticationContextStatement_DEL_AuthenticatingAuthority(struct zx_ac_AuthenticationContextStatement_s* x, int n)
{
  struct zx_ac_AuthenticatingAuthority_s* y;
  if (!x) return;
  switch (n) {
  case 0:
    x->AuthenticatingAuthority = (struct zx_ac_AuthenticatingAuthority_s*)x->AuthenticatingAuthority->gg.g.n;
    return;
  case -1:
    y = (struct zx_ac_AuthenticatingAuthority_s*)x->AuthenticatingAuthority;
    if (!y) return;
    for (; y->gg.g.n; y = (struct zx_ac_AuthenticatingAuthority_s*)y->gg.g.n) ;
    break;
  default:
    for (y = x->AuthenticatingAuthority; n > 1 && y->gg.g.n; --n, y = (struct zx_ac_AuthenticatingAuthority_s*)y->gg.g.n) ;
    if (!y->gg.g.n) return;
  }
  y->gg.g.n = y->gg.g.n->n;
}

#endif



#ifdef ZX_ENA_GETPUT

/* FUNC(zx_ac_AuthenticationContextStatement_NUM_Extension) */

int zx_ac_AuthenticationContextStatement_NUM_Extension(struct zx_ac_AuthenticationContextStatement_s* x)
{
  struct zx_ac_Extension_s* y;
  int n = 0;
  if (!x) return 0;
  for (y = x->Extension; y; ++n, y = (struct zx_ac_Extension_s*)y->gg.g.n) ;
  return n;
}

/* FUNC(zx_ac_AuthenticationContextStatement_GET_Extension) */

struct zx_ac_Extension_s* zx_ac_AuthenticationContextStatement_GET_Extension(struct zx_ac_AuthenticationContextStatement_s* x, int n)
{
  struct zx_ac_Extension_s* y;
  if (!x) return 0;
  for (y = x->Extension; n>=0 && y; --n, y = (struct zx_ac_Extension_s*)y->gg.g.n) ;
  return y;
}

/* FUNC(zx_ac_AuthenticationContextStatement_POP_Extension) */

struct zx_ac_Extension_s* zx_ac_AuthenticationContextStatement_POP_Extension(struct zx_ac_AuthenticationContextStatement_s* x)
{
  struct zx_ac_Extension_s* y;
  if (!x) return 0;
  y = x->Extension;
  if (y)
    x->Extension = (struct zx_ac_Extension_s*)y->gg.g.n;
  return y;
}

/* FUNC(zx_ac_AuthenticationContextStatement_PUSH_Extension) */

void zx_ac_AuthenticationContextStatement_PUSH_Extension(struct zx_ac_AuthenticationContextStatement_s* x, struct zx_ac_Extension_s* z)
{
  if (!x || !z) return;
  z->gg.g.n = &x->Extension->gg.g;
  x->Extension = z;
}

/* FUNC(zx_ac_AuthenticationContextStatement_REV_Extension) */

void zx_ac_AuthenticationContextStatement_REV_Extension(struct zx_ac_AuthenticationContextStatement_s* x)
{
  struct zx_ac_Extension_s* nxt;
  struct zx_ac_Extension_s* y;
  if (!x) return;
  y = x->Extension;
  if (!y) return;
  x->Extension = 0;
  while (y) {
    nxt = (struct zx_ac_Extension_s*)y->gg.g.n;
    y->gg.g.n = &x->Extension->gg.g;
    x->Extension = y;
    y = nxt;
  }
}

/* FUNC(zx_ac_AuthenticationContextStatement_PUT_Extension) */

void zx_ac_AuthenticationContextStatement_PUT_Extension(struct zx_ac_AuthenticationContextStatement_s* x, int n, struct zx_ac_Extension_s* z)
{
  struct zx_ac_Extension_s* y;
  if (!x || !z) return;
  y = x->Extension;
  if (!y) return;
  switch (n) {
  case 0:
    z->gg.g.n = y->gg.g.n;
    x->Extension = z;
    return;
  default:
    for (; n > 1 && y->gg.g.n; --n, y = (struct zx_ac_Extension_s*)y->gg.g.n) ;
    if (!y->gg.g.n) return;
    z->gg.g.n = y->gg.g.n->n;
    y->gg.g.n = &z->gg.g;
  }
}

/* FUNC(zx_ac_AuthenticationContextStatement_ADD_Extension) */

void zx_ac_AuthenticationContextStatement_ADD_Extension(struct zx_ac_AuthenticationContextStatement_s* x, int n, struct zx_ac_Extension_s* z)
{
  struct zx_ac_Extension_s* y;
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
    for (; y->gg.g.n; y = (struct zx_ac_Extension_s*)y->gg.g.n) ;
    break;
  default:
    for (y = x->Extension; n > 1 && y; --n, y = (struct zx_ac_Extension_s*)y->gg.g.n) ;
    if (!y) return;
  }
  z->gg.g.n = y->gg.g.n;
  y->gg.g.n = &z->gg.g;
}

/* FUNC(zx_ac_AuthenticationContextStatement_DEL_Extension) */

void zx_ac_AuthenticationContextStatement_DEL_Extension(struct zx_ac_AuthenticationContextStatement_s* x, int n)
{
  struct zx_ac_Extension_s* y;
  if (!x) return;
  switch (n) {
  case 0:
    x->Extension = (struct zx_ac_Extension_s*)x->Extension->gg.g.n;
    return;
  case -1:
    y = (struct zx_ac_Extension_s*)x->Extension;
    if (!y) return;
    for (; y->gg.g.n; y = (struct zx_ac_Extension_s*)y->gg.g.n) ;
    break;
  default:
    for (y = x->Extension; n > 1 && y->gg.g.n; --n, y = (struct zx_ac_Extension_s*)y->gg.g.n) ;
    if (!y->gg.g.n) return;
  }
  y->gg.g.n = y->gg.g.n->n;
}

#endif

/* FUNC(zx_ac_AuthenticationContextStatement_GET_ID) */
struct zx_str* zx_ac_AuthenticationContextStatement_GET_ID(struct zx_ac_AuthenticationContextStatement_s* x) { return x->ID; }
/* FUNC(zx_ac_AuthenticationContextStatement_PUT_ID) */
void zx_ac_AuthenticationContextStatement_PUT_ID(struct zx_ac_AuthenticationContextStatement_s* x, struct zx_str* y) { x->ID = y; }







#ifdef ZX_ENA_GETPUT

/* FUNC(zx_ac_AuthenticationMethod_NUM_PrincipalAuthenticationMechanism) */

int zx_ac_AuthenticationMethod_NUM_PrincipalAuthenticationMechanism(struct zx_ac_AuthenticationMethod_s* x)
{
  struct zx_ac_PrincipalAuthenticationMechanism_s* y;
  int n = 0;
  if (!x) return 0;
  for (y = x->PrincipalAuthenticationMechanism; y; ++n, y = (struct zx_ac_PrincipalAuthenticationMechanism_s*)y->gg.g.n) ;
  return n;
}

/* FUNC(zx_ac_AuthenticationMethod_GET_PrincipalAuthenticationMechanism) */

struct zx_ac_PrincipalAuthenticationMechanism_s* zx_ac_AuthenticationMethod_GET_PrincipalAuthenticationMechanism(struct zx_ac_AuthenticationMethod_s* x, int n)
{
  struct zx_ac_PrincipalAuthenticationMechanism_s* y;
  if (!x) return 0;
  for (y = x->PrincipalAuthenticationMechanism; n>=0 && y; --n, y = (struct zx_ac_PrincipalAuthenticationMechanism_s*)y->gg.g.n) ;
  return y;
}

/* FUNC(zx_ac_AuthenticationMethod_POP_PrincipalAuthenticationMechanism) */

struct zx_ac_PrincipalAuthenticationMechanism_s* zx_ac_AuthenticationMethod_POP_PrincipalAuthenticationMechanism(struct zx_ac_AuthenticationMethod_s* x)
{
  struct zx_ac_PrincipalAuthenticationMechanism_s* y;
  if (!x) return 0;
  y = x->PrincipalAuthenticationMechanism;
  if (y)
    x->PrincipalAuthenticationMechanism = (struct zx_ac_PrincipalAuthenticationMechanism_s*)y->gg.g.n;
  return y;
}

/* FUNC(zx_ac_AuthenticationMethod_PUSH_PrincipalAuthenticationMechanism) */

void zx_ac_AuthenticationMethod_PUSH_PrincipalAuthenticationMechanism(struct zx_ac_AuthenticationMethod_s* x, struct zx_ac_PrincipalAuthenticationMechanism_s* z)
{
  if (!x || !z) return;
  z->gg.g.n = &x->PrincipalAuthenticationMechanism->gg.g;
  x->PrincipalAuthenticationMechanism = z;
}

/* FUNC(zx_ac_AuthenticationMethod_REV_PrincipalAuthenticationMechanism) */

void zx_ac_AuthenticationMethod_REV_PrincipalAuthenticationMechanism(struct zx_ac_AuthenticationMethod_s* x)
{
  struct zx_ac_PrincipalAuthenticationMechanism_s* nxt;
  struct zx_ac_PrincipalAuthenticationMechanism_s* y;
  if (!x) return;
  y = x->PrincipalAuthenticationMechanism;
  if (!y) return;
  x->PrincipalAuthenticationMechanism = 0;
  while (y) {
    nxt = (struct zx_ac_PrincipalAuthenticationMechanism_s*)y->gg.g.n;
    y->gg.g.n = &x->PrincipalAuthenticationMechanism->gg.g;
    x->PrincipalAuthenticationMechanism = y;
    y = nxt;
  }
}

/* FUNC(zx_ac_AuthenticationMethod_PUT_PrincipalAuthenticationMechanism) */

void zx_ac_AuthenticationMethod_PUT_PrincipalAuthenticationMechanism(struct zx_ac_AuthenticationMethod_s* x, int n, struct zx_ac_PrincipalAuthenticationMechanism_s* z)
{
  struct zx_ac_PrincipalAuthenticationMechanism_s* y;
  if (!x || !z) return;
  y = x->PrincipalAuthenticationMechanism;
  if (!y) return;
  switch (n) {
  case 0:
    z->gg.g.n = y->gg.g.n;
    x->PrincipalAuthenticationMechanism = z;
    return;
  default:
    for (; n > 1 && y->gg.g.n; --n, y = (struct zx_ac_PrincipalAuthenticationMechanism_s*)y->gg.g.n) ;
    if (!y->gg.g.n) return;
    z->gg.g.n = y->gg.g.n->n;
    y->gg.g.n = &z->gg.g;
  }
}

/* FUNC(zx_ac_AuthenticationMethod_ADD_PrincipalAuthenticationMechanism) */

void zx_ac_AuthenticationMethod_ADD_PrincipalAuthenticationMechanism(struct zx_ac_AuthenticationMethod_s* x, int n, struct zx_ac_PrincipalAuthenticationMechanism_s* z)
{
  struct zx_ac_PrincipalAuthenticationMechanism_s* y;
  if (!x || !z) return;
  switch (n) {
  case 0:
  add_to_start:
    z->gg.g.n = &x->PrincipalAuthenticationMechanism->gg.g;
    x->PrincipalAuthenticationMechanism = z;
    return;
  case -1:
    y = x->PrincipalAuthenticationMechanism;
    if (!y) goto add_to_start;
    for (; y->gg.g.n; y = (struct zx_ac_PrincipalAuthenticationMechanism_s*)y->gg.g.n) ;
    break;
  default:
    for (y = x->PrincipalAuthenticationMechanism; n > 1 && y; --n, y = (struct zx_ac_PrincipalAuthenticationMechanism_s*)y->gg.g.n) ;
    if (!y) return;
  }
  z->gg.g.n = y->gg.g.n;
  y->gg.g.n = &z->gg.g;
}

/* FUNC(zx_ac_AuthenticationMethod_DEL_PrincipalAuthenticationMechanism) */

void zx_ac_AuthenticationMethod_DEL_PrincipalAuthenticationMechanism(struct zx_ac_AuthenticationMethod_s* x, int n)
{
  struct zx_ac_PrincipalAuthenticationMechanism_s* y;
  if (!x) return;
  switch (n) {
  case 0:
    x->PrincipalAuthenticationMechanism = (struct zx_ac_PrincipalAuthenticationMechanism_s*)x->PrincipalAuthenticationMechanism->gg.g.n;
    return;
  case -1:
    y = (struct zx_ac_PrincipalAuthenticationMechanism_s*)x->PrincipalAuthenticationMechanism;
    if (!y) return;
    for (; y->gg.g.n; y = (struct zx_ac_PrincipalAuthenticationMechanism_s*)y->gg.g.n) ;
    break;
  default:
    for (y = x->PrincipalAuthenticationMechanism; n > 1 && y->gg.g.n; --n, y = (struct zx_ac_PrincipalAuthenticationMechanism_s*)y->gg.g.n) ;
    if (!y->gg.g.n) return;
  }
  y->gg.g.n = y->gg.g.n->n;
}

#endif



#ifdef ZX_ENA_GETPUT

/* FUNC(zx_ac_AuthenticationMethod_NUM_Authenticator) */

int zx_ac_AuthenticationMethod_NUM_Authenticator(struct zx_ac_AuthenticationMethod_s* x)
{
  struct zx_ac_Authenticator_s* y;
  int n = 0;
  if (!x) return 0;
  for (y = x->Authenticator; y; ++n, y = (struct zx_ac_Authenticator_s*)y->gg.g.n) ;
  return n;
}

/* FUNC(zx_ac_AuthenticationMethod_GET_Authenticator) */

struct zx_ac_Authenticator_s* zx_ac_AuthenticationMethod_GET_Authenticator(struct zx_ac_AuthenticationMethod_s* x, int n)
{
  struct zx_ac_Authenticator_s* y;
  if (!x) return 0;
  for (y = x->Authenticator; n>=0 && y; --n, y = (struct zx_ac_Authenticator_s*)y->gg.g.n) ;
  return y;
}

/* FUNC(zx_ac_AuthenticationMethod_POP_Authenticator) */

struct zx_ac_Authenticator_s* zx_ac_AuthenticationMethod_POP_Authenticator(struct zx_ac_AuthenticationMethod_s* x)
{
  struct zx_ac_Authenticator_s* y;
  if (!x) return 0;
  y = x->Authenticator;
  if (y)
    x->Authenticator = (struct zx_ac_Authenticator_s*)y->gg.g.n;
  return y;
}

/* FUNC(zx_ac_AuthenticationMethod_PUSH_Authenticator) */

void zx_ac_AuthenticationMethod_PUSH_Authenticator(struct zx_ac_AuthenticationMethod_s* x, struct zx_ac_Authenticator_s* z)
{
  if (!x || !z) return;
  z->gg.g.n = &x->Authenticator->gg.g;
  x->Authenticator = z;
}

/* FUNC(zx_ac_AuthenticationMethod_REV_Authenticator) */

void zx_ac_AuthenticationMethod_REV_Authenticator(struct zx_ac_AuthenticationMethod_s* x)
{
  struct zx_ac_Authenticator_s* nxt;
  struct zx_ac_Authenticator_s* y;
  if (!x) return;
  y = x->Authenticator;
  if (!y) return;
  x->Authenticator = 0;
  while (y) {
    nxt = (struct zx_ac_Authenticator_s*)y->gg.g.n;
    y->gg.g.n = &x->Authenticator->gg.g;
    x->Authenticator = y;
    y = nxt;
  }
}

/* FUNC(zx_ac_AuthenticationMethod_PUT_Authenticator) */

void zx_ac_AuthenticationMethod_PUT_Authenticator(struct zx_ac_AuthenticationMethod_s* x, int n, struct zx_ac_Authenticator_s* z)
{
  struct zx_ac_Authenticator_s* y;
  if (!x || !z) return;
  y = x->Authenticator;
  if (!y) return;
  switch (n) {
  case 0:
    z->gg.g.n = y->gg.g.n;
    x->Authenticator = z;
    return;
  default:
    for (; n > 1 && y->gg.g.n; --n, y = (struct zx_ac_Authenticator_s*)y->gg.g.n) ;
    if (!y->gg.g.n) return;
    z->gg.g.n = y->gg.g.n->n;
    y->gg.g.n = &z->gg.g;
  }
}

/* FUNC(zx_ac_AuthenticationMethod_ADD_Authenticator) */

void zx_ac_AuthenticationMethod_ADD_Authenticator(struct zx_ac_AuthenticationMethod_s* x, int n, struct zx_ac_Authenticator_s* z)
{
  struct zx_ac_Authenticator_s* y;
  if (!x || !z) return;
  switch (n) {
  case 0:
  add_to_start:
    z->gg.g.n = &x->Authenticator->gg.g;
    x->Authenticator = z;
    return;
  case -1:
    y = x->Authenticator;
    if (!y) goto add_to_start;
    for (; y->gg.g.n; y = (struct zx_ac_Authenticator_s*)y->gg.g.n) ;
    break;
  default:
    for (y = x->Authenticator; n > 1 && y; --n, y = (struct zx_ac_Authenticator_s*)y->gg.g.n) ;
    if (!y) return;
  }
  z->gg.g.n = y->gg.g.n;
  y->gg.g.n = &z->gg.g;
}

/* FUNC(zx_ac_AuthenticationMethod_DEL_Authenticator) */

void zx_ac_AuthenticationMethod_DEL_Authenticator(struct zx_ac_AuthenticationMethod_s* x, int n)
{
  struct zx_ac_Authenticator_s* y;
  if (!x) return;
  switch (n) {
  case 0:
    x->Authenticator = (struct zx_ac_Authenticator_s*)x->Authenticator->gg.g.n;
    return;
  case -1:
    y = (struct zx_ac_Authenticator_s*)x->Authenticator;
    if (!y) return;
    for (; y->gg.g.n; y = (struct zx_ac_Authenticator_s*)y->gg.g.n) ;
    break;
  default:
    for (y = x->Authenticator; n > 1 && y->gg.g.n; --n, y = (struct zx_ac_Authenticator_s*)y->gg.g.n) ;
    if (!y->gg.g.n) return;
  }
  y->gg.g.n = y->gg.g.n->n;
}

#endif



#ifdef ZX_ENA_GETPUT

/* FUNC(zx_ac_AuthenticationMethod_NUM_AuthenticatorTransportProtocol) */

int zx_ac_AuthenticationMethod_NUM_AuthenticatorTransportProtocol(struct zx_ac_AuthenticationMethod_s* x)
{
  struct zx_ac_AuthenticatorTransportProtocol_s* y;
  int n = 0;
  if (!x) return 0;
  for (y = x->AuthenticatorTransportProtocol; y; ++n, y = (struct zx_ac_AuthenticatorTransportProtocol_s*)y->gg.g.n) ;
  return n;
}

/* FUNC(zx_ac_AuthenticationMethod_GET_AuthenticatorTransportProtocol) */

struct zx_ac_AuthenticatorTransportProtocol_s* zx_ac_AuthenticationMethod_GET_AuthenticatorTransportProtocol(struct zx_ac_AuthenticationMethod_s* x, int n)
{
  struct zx_ac_AuthenticatorTransportProtocol_s* y;
  if (!x) return 0;
  for (y = x->AuthenticatorTransportProtocol; n>=0 && y; --n, y = (struct zx_ac_AuthenticatorTransportProtocol_s*)y->gg.g.n) ;
  return y;
}

/* FUNC(zx_ac_AuthenticationMethod_POP_AuthenticatorTransportProtocol) */

struct zx_ac_AuthenticatorTransportProtocol_s* zx_ac_AuthenticationMethod_POP_AuthenticatorTransportProtocol(struct zx_ac_AuthenticationMethod_s* x)
{
  struct zx_ac_AuthenticatorTransportProtocol_s* y;
  if (!x) return 0;
  y = x->AuthenticatorTransportProtocol;
  if (y)
    x->AuthenticatorTransportProtocol = (struct zx_ac_AuthenticatorTransportProtocol_s*)y->gg.g.n;
  return y;
}

/* FUNC(zx_ac_AuthenticationMethod_PUSH_AuthenticatorTransportProtocol) */

void zx_ac_AuthenticationMethod_PUSH_AuthenticatorTransportProtocol(struct zx_ac_AuthenticationMethod_s* x, struct zx_ac_AuthenticatorTransportProtocol_s* z)
{
  if (!x || !z) return;
  z->gg.g.n = &x->AuthenticatorTransportProtocol->gg.g;
  x->AuthenticatorTransportProtocol = z;
}

/* FUNC(zx_ac_AuthenticationMethod_REV_AuthenticatorTransportProtocol) */

void zx_ac_AuthenticationMethod_REV_AuthenticatorTransportProtocol(struct zx_ac_AuthenticationMethod_s* x)
{
  struct zx_ac_AuthenticatorTransportProtocol_s* nxt;
  struct zx_ac_AuthenticatorTransportProtocol_s* y;
  if (!x) return;
  y = x->AuthenticatorTransportProtocol;
  if (!y) return;
  x->AuthenticatorTransportProtocol = 0;
  while (y) {
    nxt = (struct zx_ac_AuthenticatorTransportProtocol_s*)y->gg.g.n;
    y->gg.g.n = &x->AuthenticatorTransportProtocol->gg.g;
    x->AuthenticatorTransportProtocol = y;
    y = nxt;
  }
}

/* FUNC(zx_ac_AuthenticationMethod_PUT_AuthenticatorTransportProtocol) */

void zx_ac_AuthenticationMethod_PUT_AuthenticatorTransportProtocol(struct zx_ac_AuthenticationMethod_s* x, int n, struct zx_ac_AuthenticatorTransportProtocol_s* z)
{
  struct zx_ac_AuthenticatorTransportProtocol_s* y;
  if (!x || !z) return;
  y = x->AuthenticatorTransportProtocol;
  if (!y) return;
  switch (n) {
  case 0:
    z->gg.g.n = y->gg.g.n;
    x->AuthenticatorTransportProtocol = z;
    return;
  default:
    for (; n > 1 && y->gg.g.n; --n, y = (struct zx_ac_AuthenticatorTransportProtocol_s*)y->gg.g.n) ;
    if (!y->gg.g.n) return;
    z->gg.g.n = y->gg.g.n->n;
    y->gg.g.n = &z->gg.g;
  }
}

/* FUNC(zx_ac_AuthenticationMethod_ADD_AuthenticatorTransportProtocol) */

void zx_ac_AuthenticationMethod_ADD_AuthenticatorTransportProtocol(struct zx_ac_AuthenticationMethod_s* x, int n, struct zx_ac_AuthenticatorTransportProtocol_s* z)
{
  struct zx_ac_AuthenticatorTransportProtocol_s* y;
  if (!x || !z) return;
  switch (n) {
  case 0:
  add_to_start:
    z->gg.g.n = &x->AuthenticatorTransportProtocol->gg.g;
    x->AuthenticatorTransportProtocol = z;
    return;
  case -1:
    y = x->AuthenticatorTransportProtocol;
    if (!y) goto add_to_start;
    for (; y->gg.g.n; y = (struct zx_ac_AuthenticatorTransportProtocol_s*)y->gg.g.n) ;
    break;
  default:
    for (y = x->AuthenticatorTransportProtocol; n > 1 && y; --n, y = (struct zx_ac_AuthenticatorTransportProtocol_s*)y->gg.g.n) ;
    if (!y) return;
  }
  z->gg.g.n = y->gg.g.n;
  y->gg.g.n = &z->gg.g;
}

/* FUNC(zx_ac_AuthenticationMethod_DEL_AuthenticatorTransportProtocol) */

void zx_ac_AuthenticationMethod_DEL_AuthenticatorTransportProtocol(struct zx_ac_AuthenticationMethod_s* x, int n)
{
  struct zx_ac_AuthenticatorTransportProtocol_s* y;
  if (!x) return;
  switch (n) {
  case 0:
    x->AuthenticatorTransportProtocol = (struct zx_ac_AuthenticatorTransportProtocol_s*)x->AuthenticatorTransportProtocol->gg.g.n;
    return;
  case -1:
    y = (struct zx_ac_AuthenticatorTransportProtocol_s*)x->AuthenticatorTransportProtocol;
    if (!y) return;
    for (; y->gg.g.n; y = (struct zx_ac_AuthenticatorTransportProtocol_s*)y->gg.g.n) ;
    break;
  default:
    for (y = x->AuthenticatorTransportProtocol; n > 1 && y->gg.g.n; --n, y = (struct zx_ac_AuthenticatorTransportProtocol_s*)y->gg.g.n) ;
    if (!y->gg.g.n) return;
  }
  y->gg.g.n = y->gg.g.n->n;
}

#endif



#ifdef ZX_ENA_GETPUT

/* FUNC(zx_ac_AuthenticationMethod_NUM_Extension) */

int zx_ac_AuthenticationMethod_NUM_Extension(struct zx_ac_AuthenticationMethod_s* x)
{
  struct zx_ac_Extension_s* y;
  int n = 0;
  if (!x) return 0;
  for (y = x->Extension; y; ++n, y = (struct zx_ac_Extension_s*)y->gg.g.n) ;
  return n;
}

/* FUNC(zx_ac_AuthenticationMethod_GET_Extension) */

struct zx_ac_Extension_s* zx_ac_AuthenticationMethod_GET_Extension(struct zx_ac_AuthenticationMethod_s* x, int n)
{
  struct zx_ac_Extension_s* y;
  if (!x) return 0;
  for (y = x->Extension; n>=0 && y; --n, y = (struct zx_ac_Extension_s*)y->gg.g.n) ;
  return y;
}

/* FUNC(zx_ac_AuthenticationMethod_POP_Extension) */

struct zx_ac_Extension_s* zx_ac_AuthenticationMethod_POP_Extension(struct zx_ac_AuthenticationMethod_s* x)
{
  struct zx_ac_Extension_s* y;
  if (!x) return 0;
  y = x->Extension;
  if (y)
    x->Extension = (struct zx_ac_Extension_s*)y->gg.g.n;
  return y;
}

/* FUNC(zx_ac_AuthenticationMethod_PUSH_Extension) */

void zx_ac_AuthenticationMethod_PUSH_Extension(struct zx_ac_AuthenticationMethod_s* x, struct zx_ac_Extension_s* z)
{
  if (!x || !z) return;
  z->gg.g.n = &x->Extension->gg.g;
  x->Extension = z;
}

/* FUNC(zx_ac_AuthenticationMethod_REV_Extension) */

void zx_ac_AuthenticationMethod_REV_Extension(struct zx_ac_AuthenticationMethod_s* x)
{
  struct zx_ac_Extension_s* nxt;
  struct zx_ac_Extension_s* y;
  if (!x) return;
  y = x->Extension;
  if (!y) return;
  x->Extension = 0;
  while (y) {
    nxt = (struct zx_ac_Extension_s*)y->gg.g.n;
    y->gg.g.n = &x->Extension->gg.g;
    x->Extension = y;
    y = nxt;
  }
}

/* FUNC(zx_ac_AuthenticationMethod_PUT_Extension) */

void zx_ac_AuthenticationMethod_PUT_Extension(struct zx_ac_AuthenticationMethod_s* x, int n, struct zx_ac_Extension_s* z)
{
  struct zx_ac_Extension_s* y;
  if (!x || !z) return;
  y = x->Extension;
  if (!y) return;
  switch (n) {
  case 0:
    z->gg.g.n = y->gg.g.n;
    x->Extension = z;
    return;
  default:
    for (; n > 1 && y->gg.g.n; --n, y = (struct zx_ac_Extension_s*)y->gg.g.n) ;
    if (!y->gg.g.n) return;
    z->gg.g.n = y->gg.g.n->n;
    y->gg.g.n = &z->gg.g;
  }
}

/* FUNC(zx_ac_AuthenticationMethod_ADD_Extension) */

void zx_ac_AuthenticationMethod_ADD_Extension(struct zx_ac_AuthenticationMethod_s* x, int n, struct zx_ac_Extension_s* z)
{
  struct zx_ac_Extension_s* y;
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
    for (; y->gg.g.n; y = (struct zx_ac_Extension_s*)y->gg.g.n) ;
    break;
  default:
    for (y = x->Extension; n > 1 && y; --n, y = (struct zx_ac_Extension_s*)y->gg.g.n) ;
    if (!y) return;
  }
  z->gg.g.n = y->gg.g.n;
  y->gg.g.n = &z->gg.g;
}

/* FUNC(zx_ac_AuthenticationMethod_DEL_Extension) */

void zx_ac_AuthenticationMethod_DEL_Extension(struct zx_ac_AuthenticationMethod_s* x, int n)
{
  struct zx_ac_Extension_s* y;
  if (!x) return;
  switch (n) {
  case 0:
    x->Extension = (struct zx_ac_Extension_s*)x->Extension->gg.g.n;
    return;
  case -1:
    y = (struct zx_ac_Extension_s*)x->Extension;
    if (!y) return;
    for (; y->gg.g.n; y = (struct zx_ac_Extension_s*)y->gg.g.n) ;
    break;
  default:
    for (y = x->Extension; n > 1 && y->gg.g.n; --n, y = (struct zx_ac_Extension_s*)y->gg.g.n) ;
    if (!y->gg.g.n) return;
  }
  y->gg.g.n = y->gg.g.n->n;
}

#endif








#ifdef ZX_ENA_GETPUT

/* FUNC(zx_ac_Authenticator_NUM_PreviousSession) */

int zx_ac_Authenticator_NUM_PreviousSession(struct zx_ac_Authenticator_s* x)
{
  struct zx_ac_PreviousSession_s* y;
  int n = 0;
  if (!x) return 0;
  for (y = x->PreviousSession; y; ++n, y = (struct zx_ac_PreviousSession_s*)y->gg.g.n) ;
  return n;
}

/* FUNC(zx_ac_Authenticator_GET_PreviousSession) */

struct zx_ac_PreviousSession_s* zx_ac_Authenticator_GET_PreviousSession(struct zx_ac_Authenticator_s* x, int n)
{
  struct zx_ac_PreviousSession_s* y;
  if (!x) return 0;
  for (y = x->PreviousSession; n>=0 && y; --n, y = (struct zx_ac_PreviousSession_s*)y->gg.g.n) ;
  return y;
}

/* FUNC(zx_ac_Authenticator_POP_PreviousSession) */

struct zx_ac_PreviousSession_s* zx_ac_Authenticator_POP_PreviousSession(struct zx_ac_Authenticator_s* x)
{
  struct zx_ac_PreviousSession_s* y;
  if (!x) return 0;
  y = x->PreviousSession;
  if (y)
    x->PreviousSession = (struct zx_ac_PreviousSession_s*)y->gg.g.n;
  return y;
}

/* FUNC(zx_ac_Authenticator_PUSH_PreviousSession) */

void zx_ac_Authenticator_PUSH_PreviousSession(struct zx_ac_Authenticator_s* x, struct zx_ac_PreviousSession_s* z)
{
  if (!x || !z) return;
  z->gg.g.n = &x->PreviousSession->gg.g;
  x->PreviousSession = z;
}

/* FUNC(zx_ac_Authenticator_REV_PreviousSession) */

void zx_ac_Authenticator_REV_PreviousSession(struct zx_ac_Authenticator_s* x)
{
  struct zx_ac_PreviousSession_s* nxt;
  struct zx_ac_PreviousSession_s* y;
  if (!x) return;
  y = x->PreviousSession;
  if (!y) return;
  x->PreviousSession = 0;
  while (y) {
    nxt = (struct zx_ac_PreviousSession_s*)y->gg.g.n;
    y->gg.g.n = &x->PreviousSession->gg.g;
    x->PreviousSession = y;
    y = nxt;
  }
}

/* FUNC(zx_ac_Authenticator_PUT_PreviousSession) */

void zx_ac_Authenticator_PUT_PreviousSession(struct zx_ac_Authenticator_s* x, int n, struct zx_ac_PreviousSession_s* z)
{
  struct zx_ac_PreviousSession_s* y;
  if (!x || !z) return;
  y = x->PreviousSession;
  if (!y) return;
  switch (n) {
  case 0:
    z->gg.g.n = y->gg.g.n;
    x->PreviousSession = z;
    return;
  default:
    for (; n > 1 && y->gg.g.n; --n, y = (struct zx_ac_PreviousSession_s*)y->gg.g.n) ;
    if (!y->gg.g.n) return;
    z->gg.g.n = y->gg.g.n->n;
    y->gg.g.n = &z->gg.g;
  }
}

/* FUNC(zx_ac_Authenticator_ADD_PreviousSession) */

void zx_ac_Authenticator_ADD_PreviousSession(struct zx_ac_Authenticator_s* x, int n, struct zx_ac_PreviousSession_s* z)
{
  struct zx_ac_PreviousSession_s* y;
  if (!x || !z) return;
  switch (n) {
  case 0:
  add_to_start:
    z->gg.g.n = &x->PreviousSession->gg.g;
    x->PreviousSession = z;
    return;
  case -1:
    y = x->PreviousSession;
    if (!y) goto add_to_start;
    for (; y->gg.g.n; y = (struct zx_ac_PreviousSession_s*)y->gg.g.n) ;
    break;
  default:
    for (y = x->PreviousSession; n > 1 && y; --n, y = (struct zx_ac_PreviousSession_s*)y->gg.g.n) ;
    if (!y) return;
  }
  z->gg.g.n = y->gg.g.n;
  y->gg.g.n = &z->gg.g;
}

/* FUNC(zx_ac_Authenticator_DEL_PreviousSession) */

void zx_ac_Authenticator_DEL_PreviousSession(struct zx_ac_Authenticator_s* x, int n)
{
  struct zx_ac_PreviousSession_s* y;
  if (!x) return;
  switch (n) {
  case 0:
    x->PreviousSession = (struct zx_ac_PreviousSession_s*)x->PreviousSession->gg.g.n;
    return;
  case -1:
    y = (struct zx_ac_PreviousSession_s*)x->PreviousSession;
    if (!y) return;
    for (; y->gg.g.n; y = (struct zx_ac_PreviousSession_s*)y->gg.g.n) ;
    break;
  default:
    for (y = x->PreviousSession; n > 1 && y->gg.g.n; --n, y = (struct zx_ac_PreviousSession_s*)y->gg.g.n) ;
    if (!y->gg.g.n) return;
  }
  y->gg.g.n = y->gg.g.n->n;
}

#endif



#ifdef ZX_ENA_GETPUT

/* FUNC(zx_ac_Authenticator_NUM_ResumeSession) */

int zx_ac_Authenticator_NUM_ResumeSession(struct zx_ac_Authenticator_s* x)
{
  struct zx_ac_ResumeSession_s* y;
  int n = 0;
  if (!x) return 0;
  for (y = x->ResumeSession; y; ++n, y = (struct zx_ac_ResumeSession_s*)y->gg.g.n) ;
  return n;
}

/* FUNC(zx_ac_Authenticator_GET_ResumeSession) */

struct zx_ac_ResumeSession_s* zx_ac_Authenticator_GET_ResumeSession(struct zx_ac_Authenticator_s* x, int n)
{
  struct zx_ac_ResumeSession_s* y;
  if (!x) return 0;
  for (y = x->ResumeSession; n>=0 && y; --n, y = (struct zx_ac_ResumeSession_s*)y->gg.g.n) ;
  return y;
}

/* FUNC(zx_ac_Authenticator_POP_ResumeSession) */

struct zx_ac_ResumeSession_s* zx_ac_Authenticator_POP_ResumeSession(struct zx_ac_Authenticator_s* x)
{
  struct zx_ac_ResumeSession_s* y;
  if (!x) return 0;
  y = x->ResumeSession;
  if (y)
    x->ResumeSession = (struct zx_ac_ResumeSession_s*)y->gg.g.n;
  return y;
}

/* FUNC(zx_ac_Authenticator_PUSH_ResumeSession) */

void zx_ac_Authenticator_PUSH_ResumeSession(struct zx_ac_Authenticator_s* x, struct zx_ac_ResumeSession_s* z)
{
  if (!x || !z) return;
  z->gg.g.n = &x->ResumeSession->gg.g;
  x->ResumeSession = z;
}

/* FUNC(zx_ac_Authenticator_REV_ResumeSession) */

void zx_ac_Authenticator_REV_ResumeSession(struct zx_ac_Authenticator_s* x)
{
  struct zx_ac_ResumeSession_s* nxt;
  struct zx_ac_ResumeSession_s* y;
  if (!x) return;
  y = x->ResumeSession;
  if (!y) return;
  x->ResumeSession = 0;
  while (y) {
    nxt = (struct zx_ac_ResumeSession_s*)y->gg.g.n;
    y->gg.g.n = &x->ResumeSession->gg.g;
    x->ResumeSession = y;
    y = nxt;
  }
}

/* FUNC(zx_ac_Authenticator_PUT_ResumeSession) */

void zx_ac_Authenticator_PUT_ResumeSession(struct zx_ac_Authenticator_s* x, int n, struct zx_ac_ResumeSession_s* z)
{
  struct zx_ac_ResumeSession_s* y;
  if (!x || !z) return;
  y = x->ResumeSession;
  if (!y) return;
  switch (n) {
  case 0:
    z->gg.g.n = y->gg.g.n;
    x->ResumeSession = z;
    return;
  default:
    for (; n > 1 && y->gg.g.n; --n, y = (struct zx_ac_ResumeSession_s*)y->gg.g.n) ;
    if (!y->gg.g.n) return;
    z->gg.g.n = y->gg.g.n->n;
    y->gg.g.n = &z->gg.g;
  }
}

/* FUNC(zx_ac_Authenticator_ADD_ResumeSession) */

void zx_ac_Authenticator_ADD_ResumeSession(struct zx_ac_Authenticator_s* x, int n, struct zx_ac_ResumeSession_s* z)
{
  struct zx_ac_ResumeSession_s* y;
  if (!x || !z) return;
  switch (n) {
  case 0:
  add_to_start:
    z->gg.g.n = &x->ResumeSession->gg.g;
    x->ResumeSession = z;
    return;
  case -1:
    y = x->ResumeSession;
    if (!y) goto add_to_start;
    for (; y->gg.g.n; y = (struct zx_ac_ResumeSession_s*)y->gg.g.n) ;
    break;
  default:
    for (y = x->ResumeSession; n > 1 && y; --n, y = (struct zx_ac_ResumeSession_s*)y->gg.g.n) ;
    if (!y) return;
  }
  z->gg.g.n = y->gg.g.n;
  y->gg.g.n = &z->gg.g;
}

/* FUNC(zx_ac_Authenticator_DEL_ResumeSession) */

void zx_ac_Authenticator_DEL_ResumeSession(struct zx_ac_Authenticator_s* x, int n)
{
  struct zx_ac_ResumeSession_s* y;
  if (!x) return;
  switch (n) {
  case 0:
    x->ResumeSession = (struct zx_ac_ResumeSession_s*)x->ResumeSession->gg.g.n;
    return;
  case -1:
    y = (struct zx_ac_ResumeSession_s*)x->ResumeSession;
    if (!y) return;
    for (; y->gg.g.n; y = (struct zx_ac_ResumeSession_s*)y->gg.g.n) ;
    break;
  default:
    for (y = x->ResumeSession; n > 1 && y->gg.g.n; --n, y = (struct zx_ac_ResumeSession_s*)y->gg.g.n) ;
    if (!y->gg.g.n) return;
  }
  y->gg.g.n = y->gg.g.n->n;
}

#endif



#ifdef ZX_ENA_GETPUT

/* FUNC(zx_ac_Authenticator_NUM_DigSig) */

int zx_ac_Authenticator_NUM_DigSig(struct zx_ac_Authenticator_s* x)
{
  struct zx_ac_DigSig_s* y;
  int n = 0;
  if (!x) return 0;
  for (y = x->DigSig; y; ++n, y = (struct zx_ac_DigSig_s*)y->gg.g.n) ;
  return n;
}

/* FUNC(zx_ac_Authenticator_GET_DigSig) */

struct zx_ac_DigSig_s* zx_ac_Authenticator_GET_DigSig(struct zx_ac_Authenticator_s* x, int n)
{
  struct zx_ac_DigSig_s* y;
  if (!x) return 0;
  for (y = x->DigSig; n>=0 && y; --n, y = (struct zx_ac_DigSig_s*)y->gg.g.n) ;
  return y;
}

/* FUNC(zx_ac_Authenticator_POP_DigSig) */

struct zx_ac_DigSig_s* zx_ac_Authenticator_POP_DigSig(struct zx_ac_Authenticator_s* x)
{
  struct zx_ac_DigSig_s* y;
  if (!x) return 0;
  y = x->DigSig;
  if (y)
    x->DigSig = (struct zx_ac_DigSig_s*)y->gg.g.n;
  return y;
}

/* FUNC(zx_ac_Authenticator_PUSH_DigSig) */

void zx_ac_Authenticator_PUSH_DigSig(struct zx_ac_Authenticator_s* x, struct zx_ac_DigSig_s* z)
{
  if (!x || !z) return;
  z->gg.g.n = &x->DigSig->gg.g;
  x->DigSig = z;
}

/* FUNC(zx_ac_Authenticator_REV_DigSig) */

void zx_ac_Authenticator_REV_DigSig(struct zx_ac_Authenticator_s* x)
{
  struct zx_ac_DigSig_s* nxt;
  struct zx_ac_DigSig_s* y;
  if (!x) return;
  y = x->DigSig;
  if (!y) return;
  x->DigSig = 0;
  while (y) {
    nxt = (struct zx_ac_DigSig_s*)y->gg.g.n;
    y->gg.g.n = &x->DigSig->gg.g;
    x->DigSig = y;
    y = nxt;
  }
}

/* FUNC(zx_ac_Authenticator_PUT_DigSig) */

void zx_ac_Authenticator_PUT_DigSig(struct zx_ac_Authenticator_s* x, int n, struct zx_ac_DigSig_s* z)
{
  struct zx_ac_DigSig_s* y;
  if (!x || !z) return;
  y = x->DigSig;
  if (!y) return;
  switch (n) {
  case 0:
    z->gg.g.n = y->gg.g.n;
    x->DigSig = z;
    return;
  default:
    for (; n > 1 && y->gg.g.n; --n, y = (struct zx_ac_DigSig_s*)y->gg.g.n) ;
    if (!y->gg.g.n) return;
    z->gg.g.n = y->gg.g.n->n;
    y->gg.g.n = &z->gg.g;
  }
}

/* FUNC(zx_ac_Authenticator_ADD_DigSig) */

void zx_ac_Authenticator_ADD_DigSig(struct zx_ac_Authenticator_s* x, int n, struct zx_ac_DigSig_s* z)
{
  struct zx_ac_DigSig_s* y;
  if (!x || !z) return;
  switch (n) {
  case 0:
  add_to_start:
    z->gg.g.n = &x->DigSig->gg.g;
    x->DigSig = z;
    return;
  case -1:
    y = x->DigSig;
    if (!y) goto add_to_start;
    for (; y->gg.g.n; y = (struct zx_ac_DigSig_s*)y->gg.g.n) ;
    break;
  default:
    for (y = x->DigSig; n > 1 && y; --n, y = (struct zx_ac_DigSig_s*)y->gg.g.n) ;
    if (!y) return;
  }
  z->gg.g.n = y->gg.g.n;
  y->gg.g.n = &z->gg.g;
}

/* FUNC(zx_ac_Authenticator_DEL_DigSig) */

void zx_ac_Authenticator_DEL_DigSig(struct zx_ac_Authenticator_s* x, int n)
{
  struct zx_ac_DigSig_s* y;
  if (!x) return;
  switch (n) {
  case 0:
    x->DigSig = (struct zx_ac_DigSig_s*)x->DigSig->gg.g.n;
    return;
  case -1:
    y = (struct zx_ac_DigSig_s*)x->DigSig;
    if (!y) return;
    for (; y->gg.g.n; y = (struct zx_ac_DigSig_s*)y->gg.g.n) ;
    break;
  default:
    for (y = x->DigSig; n > 1 && y->gg.g.n; --n, y = (struct zx_ac_DigSig_s*)y->gg.g.n) ;
    if (!y->gg.g.n) return;
  }
  y->gg.g.n = y->gg.g.n->n;
}

#endif



#ifdef ZX_ENA_GETPUT

/* FUNC(zx_ac_Authenticator_NUM_Password) */

int zx_ac_Authenticator_NUM_Password(struct zx_ac_Authenticator_s* x)
{
  struct zx_ac_Password_s* y;
  int n = 0;
  if (!x) return 0;
  for (y = x->Password; y; ++n, y = (struct zx_ac_Password_s*)y->gg.g.n) ;
  return n;
}

/* FUNC(zx_ac_Authenticator_GET_Password) */

struct zx_ac_Password_s* zx_ac_Authenticator_GET_Password(struct zx_ac_Authenticator_s* x, int n)
{
  struct zx_ac_Password_s* y;
  if (!x) return 0;
  for (y = x->Password; n>=0 && y; --n, y = (struct zx_ac_Password_s*)y->gg.g.n) ;
  return y;
}

/* FUNC(zx_ac_Authenticator_POP_Password) */

struct zx_ac_Password_s* zx_ac_Authenticator_POP_Password(struct zx_ac_Authenticator_s* x)
{
  struct zx_ac_Password_s* y;
  if (!x) return 0;
  y = x->Password;
  if (y)
    x->Password = (struct zx_ac_Password_s*)y->gg.g.n;
  return y;
}

/* FUNC(zx_ac_Authenticator_PUSH_Password) */

void zx_ac_Authenticator_PUSH_Password(struct zx_ac_Authenticator_s* x, struct zx_ac_Password_s* z)
{
  if (!x || !z) return;
  z->gg.g.n = &x->Password->gg.g;
  x->Password = z;
}

/* FUNC(zx_ac_Authenticator_REV_Password) */

void zx_ac_Authenticator_REV_Password(struct zx_ac_Authenticator_s* x)
{
  struct zx_ac_Password_s* nxt;
  struct zx_ac_Password_s* y;
  if (!x) return;
  y = x->Password;
  if (!y) return;
  x->Password = 0;
  while (y) {
    nxt = (struct zx_ac_Password_s*)y->gg.g.n;
    y->gg.g.n = &x->Password->gg.g;
    x->Password = y;
    y = nxt;
  }
}

/* FUNC(zx_ac_Authenticator_PUT_Password) */

void zx_ac_Authenticator_PUT_Password(struct zx_ac_Authenticator_s* x, int n, struct zx_ac_Password_s* z)
{
  struct zx_ac_Password_s* y;
  if (!x || !z) return;
  y = x->Password;
  if (!y) return;
  switch (n) {
  case 0:
    z->gg.g.n = y->gg.g.n;
    x->Password = z;
    return;
  default:
    for (; n > 1 && y->gg.g.n; --n, y = (struct zx_ac_Password_s*)y->gg.g.n) ;
    if (!y->gg.g.n) return;
    z->gg.g.n = y->gg.g.n->n;
    y->gg.g.n = &z->gg.g;
  }
}

/* FUNC(zx_ac_Authenticator_ADD_Password) */

void zx_ac_Authenticator_ADD_Password(struct zx_ac_Authenticator_s* x, int n, struct zx_ac_Password_s* z)
{
  struct zx_ac_Password_s* y;
  if (!x || !z) return;
  switch (n) {
  case 0:
  add_to_start:
    z->gg.g.n = &x->Password->gg.g;
    x->Password = z;
    return;
  case -1:
    y = x->Password;
    if (!y) goto add_to_start;
    for (; y->gg.g.n; y = (struct zx_ac_Password_s*)y->gg.g.n) ;
    break;
  default:
    for (y = x->Password; n > 1 && y; --n, y = (struct zx_ac_Password_s*)y->gg.g.n) ;
    if (!y) return;
  }
  z->gg.g.n = y->gg.g.n;
  y->gg.g.n = &z->gg.g;
}

/* FUNC(zx_ac_Authenticator_DEL_Password) */

void zx_ac_Authenticator_DEL_Password(struct zx_ac_Authenticator_s* x, int n)
{
  struct zx_ac_Password_s* y;
  if (!x) return;
  switch (n) {
  case 0:
    x->Password = (struct zx_ac_Password_s*)x->Password->gg.g.n;
    return;
  case -1:
    y = (struct zx_ac_Password_s*)x->Password;
    if (!y) return;
    for (; y->gg.g.n; y = (struct zx_ac_Password_s*)y->gg.g.n) ;
    break;
  default:
    for (y = x->Password; n > 1 && y->gg.g.n; --n, y = (struct zx_ac_Password_s*)y->gg.g.n) ;
    if (!y->gg.g.n) return;
  }
  y->gg.g.n = y->gg.g.n->n;
}

#endif



#ifdef ZX_ENA_GETPUT

/* FUNC(zx_ac_Authenticator_NUM_ZeroKnowledge) */

int zx_ac_Authenticator_NUM_ZeroKnowledge(struct zx_ac_Authenticator_s* x)
{
  struct zx_ac_ZeroKnowledge_s* y;
  int n = 0;
  if (!x) return 0;
  for (y = x->ZeroKnowledge; y; ++n, y = (struct zx_ac_ZeroKnowledge_s*)y->gg.g.n) ;
  return n;
}

/* FUNC(zx_ac_Authenticator_GET_ZeroKnowledge) */

struct zx_ac_ZeroKnowledge_s* zx_ac_Authenticator_GET_ZeroKnowledge(struct zx_ac_Authenticator_s* x, int n)
{
  struct zx_ac_ZeroKnowledge_s* y;
  if (!x) return 0;
  for (y = x->ZeroKnowledge; n>=0 && y; --n, y = (struct zx_ac_ZeroKnowledge_s*)y->gg.g.n) ;
  return y;
}

/* FUNC(zx_ac_Authenticator_POP_ZeroKnowledge) */

struct zx_ac_ZeroKnowledge_s* zx_ac_Authenticator_POP_ZeroKnowledge(struct zx_ac_Authenticator_s* x)
{
  struct zx_ac_ZeroKnowledge_s* y;
  if (!x) return 0;
  y = x->ZeroKnowledge;
  if (y)
    x->ZeroKnowledge = (struct zx_ac_ZeroKnowledge_s*)y->gg.g.n;
  return y;
}

/* FUNC(zx_ac_Authenticator_PUSH_ZeroKnowledge) */

void zx_ac_Authenticator_PUSH_ZeroKnowledge(struct zx_ac_Authenticator_s* x, struct zx_ac_ZeroKnowledge_s* z)
{
  if (!x || !z) return;
  z->gg.g.n = &x->ZeroKnowledge->gg.g;
  x->ZeroKnowledge = z;
}

/* FUNC(zx_ac_Authenticator_REV_ZeroKnowledge) */

void zx_ac_Authenticator_REV_ZeroKnowledge(struct zx_ac_Authenticator_s* x)
{
  struct zx_ac_ZeroKnowledge_s* nxt;
  struct zx_ac_ZeroKnowledge_s* y;
  if (!x) return;
  y = x->ZeroKnowledge;
  if (!y) return;
  x->ZeroKnowledge = 0;
  while (y) {
    nxt = (struct zx_ac_ZeroKnowledge_s*)y->gg.g.n;
    y->gg.g.n = &x->ZeroKnowledge->gg.g;
    x->ZeroKnowledge = y;
    y = nxt;
  }
}

/* FUNC(zx_ac_Authenticator_PUT_ZeroKnowledge) */

void zx_ac_Authenticator_PUT_ZeroKnowledge(struct zx_ac_Authenticator_s* x, int n, struct zx_ac_ZeroKnowledge_s* z)
{
  struct zx_ac_ZeroKnowledge_s* y;
  if (!x || !z) return;
  y = x->ZeroKnowledge;
  if (!y) return;
  switch (n) {
  case 0:
    z->gg.g.n = y->gg.g.n;
    x->ZeroKnowledge = z;
    return;
  default:
    for (; n > 1 && y->gg.g.n; --n, y = (struct zx_ac_ZeroKnowledge_s*)y->gg.g.n) ;
    if (!y->gg.g.n) return;
    z->gg.g.n = y->gg.g.n->n;
    y->gg.g.n = &z->gg.g;
  }
}

/* FUNC(zx_ac_Authenticator_ADD_ZeroKnowledge) */

void zx_ac_Authenticator_ADD_ZeroKnowledge(struct zx_ac_Authenticator_s* x, int n, struct zx_ac_ZeroKnowledge_s* z)
{
  struct zx_ac_ZeroKnowledge_s* y;
  if (!x || !z) return;
  switch (n) {
  case 0:
  add_to_start:
    z->gg.g.n = &x->ZeroKnowledge->gg.g;
    x->ZeroKnowledge = z;
    return;
  case -1:
    y = x->ZeroKnowledge;
    if (!y) goto add_to_start;
    for (; y->gg.g.n; y = (struct zx_ac_ZeroKnowledge_s*)y->gg.g.n) ;
    break;
  default:
    for (y = x->ZeroKnowledge; n > 1 && y; --n, y = (struct zx_ac_ZeroKnowledge_s*)y->gg.g.n) ;
    if (!y) return;
  }
  z->gg.g.n = y->gg.g.n;
  y->gg.g.n = &z->gg.g;
}

/* FUNC(zx_ac_Authenticator_DEL_ZeroKnowledge) */

void zx_ac_Authenticator_DEL_ZeroKnowledge(struct zx_ac_Authenticator_s* x, int n)
{
  struct zx_ac_ZeroKnowledge_s* y;
  if (!x) return;
  switch (n) {
  case 0:
    x->ZeroKnowledge = (struct zx_ac_ZeroKnowledge_s*)x->ZeroKnowledge->gg.g.n;
    return;
  case -1:
    y = (struct zx_ac_ZeroKnowledge_s*)x->ZeroKnowledge;
    if (!y) return;
    for (; y->gg.g.n; y = (struct zx_ac_ZeroKnowledge_s*)y->gg.g.n) ;
    break;
  default:
    for (y = x->ZeroKnowledge; n > 1 && y->gg.g.n; --n, y = (struct zx_ac_ZeroKnowledge_s*)y->gg.g.n) ;
    if (!y->gg.g.n) return;
  }
  y->gg.g.n = y->gg.g.n->n;
}

#endif



#ifdef ZX_ENA_GETPUT

/* FUNC(zx_ac_Authenticator_NUM_SharedSecretChallengeResponse) */

int zx_ac_Authenticator_NUM_SharedSecretChallengeResponse(struct zx_ac_Authenticator_s* x)
{
  struct zx_ac_SharedSecretChallengeResponse_s* y;
  int n = 0;
  if (!x) return 0;
  for (y = x->SharedSecretChallengeResponse; y; ++n, y = (struct zx_ac_SharedSecretChallengeResponse_s*)y->gg.g.n) ;
  return n;
}

/* FUNC(zx_ac_Authenticator_GET_SharedSecretChallengeResponse) */

struct zx_ac_SharedSecretChallengeResponse_s* zx_ac_Authenticator_GET_SharedSecretChallengeResponse(struct zx_ac_Authenticator_s* x, int n)
{
  struct zx_ac_SharedSecretChallengeResponse_s* y;
  if (!x) return 0;
  for (y = x->SharedSecretChallengeResponse; n>=0 && y; --n, y = (struct zx_ac_SharedSecretChallengeResponse_s*)y->gg.g.n) ;
  return y;
}

/* FUNC(zx_ac_Authenticator_POP_SharedSecretChallengeResponse) */

struct zx_ac_SharedSecretChallengeResponse_s* zx_ac_Authenticator_POP_SharedSecretChallengeResponse(struct zx_ac_Authenticator_s* x)
{
  struct zx_ac_SharedSecretChallengeResponse_s* y;
  if (!x) return 0;
  y = x->SharedSecretChallengeResponse;
  if (y)
    x->SharedSecretChallengeResponse = (struct zx_ac_SharedSecretChallengeResponse_s*)y->gg.g.n;
  return y;
}

/* FUNC(zx_ac_Authenticator_PUSH_SharedSecretChallengeResponse) */

void zx_ac_Authenticator_PUSH_SharedSecretChallengeResponse(struct zx_ac_Authenticator_s* x, struct zx_ac_SharedSecretChallengeResponse_s* z)
{
  if (!x || !z) return;
  z->gg.g.n = &x->SharedSecretChallengeResponse->gg.g;
  x->SharedSecretChallengeResponse = z;
}

/* FUNC(zx_ac_Authenticator_REV_SharedSecretChallengeResponse) */

void zx_ac_Authenticator_REV_SharedSecretChallengeResponse(struct zx_ac_Authenticator_s* x)
{
  struct zx_ac_SharedSecretChallengeResponse_s* nxt;
  struct zx_ac_SharedSecretChallengeResponse_s* y;
  if (!x) return;
  y = x->SharedSecretChallengeResponse;
  if (!y) return;
  x->SharedSecretChallengeResponse = 0;
  while (y) {
    nxt = (struct zx_ac_SharedSecretChallengeResponse_s*)y->gg.g.n;
    y->gg.g.n = &x->SharedSecretChallengeResponse->gg.g;
    x->SharedSecretChallengeResponse = y;
    y = nxt;
  }
}

/* FUNC(zx_ac_Authenticator_PUT_SharedSecretChallengeResponse) */

void zx_ac_Authenticator_PUT_SharedSecretChallengeResponse(struct zx_ac_Authenticator_s* x, int n, struct zx_ac_SharedSecretChallengeResponse_s* z)
{
  struct zx_ac_SharedSecretChallengeResponse_s* y;
  if (!x || !z) return;
  y = x->SharedSecretChallengeResponse;
  if (!y) return;
  switch (n) {
  case 0:
    z->gg.g.n = y->gg.g.n;
    x->SharedSecretChallengeResponse = z;
    return;
  default:
    for (; n > 1 && y->gg.g.n; --n, y = (struct zx_ac_SharedSecretChallengeResponse_s*)y->gg.g.n) ;
    if (!y->gg.g.n) return;
    z->gg.g.n = y->gg.g.n->n;
    y->gg.g.n = &z->gg.g;
  }
}

/* FUNC(zx_ac_Authenticator_ADD_SharedSecretChallengeResponse) */

void zx_ac_Authenticator_ADD_SharedSecretChallengeResponse(struct zx_ac_Authenticator_s* x, int n, struct zx_ac_SharedSecretChallengeResponse_s* z)
{
  struct zx_ac_SharedSecretChallengeResponse_s* y;
  if (!x || !z) return;
  switch (n) {
  case 0:
  add_to_start:
    z->gg.g.n = &x->SharedSecretChallengeResponse->gg.g;
    x->SharedSecretChallengeResponse = z;
    return;
  case -1:
    y = x->SharedSecretChallengeResponse;
    if (!y) goto add_to_start;
    for (; y->gg.g.n; y = (struct zx_ac_SharedSecretChallengeResponse_s*)y->gg.g.n) ;
    break;
  default:
    for (y = x->SharedSecretChallengeResponse; n > 1 && y; --n, y = (struct zx_ac_SharedSecretChallengeResponse_s*)y->gg.g.n) ;
    if (!y) return;
  }
  z->gg.g.n = y->gg.g.n;
  y->gg.g.n = &z->gg.g;
}

/* FUNC(zx_ac_Authenticator_DEL_SharedSecretChallengeResponse) */

void zx_ac_Authenticator_DEL_SharedSecretChallengeResponse(struct zx_ac_Authenticator_s* x, int n)
{
  struct zx_ac_SharedSecretChallengeResponse_s* y;
  if (!x) return;
  switch (n) {
  case 0:
    x->SharedSecretChallengeResponse = (struct zx_ac_SharedSecretChallengeResponse_s*)x->SharedSecretChallengeResponse->gg.g.n;
    return;
  case -1:
    y = (struct zx_ac_SharedSecretChallengeResponse_s*)x->SharedSecretChallengeResponse;
    if (!y) return;
    for (; y->gg.g.n; y = (struct zx_ac_SharedSecretChallengeResponse_s*)y->gg.g.n) ;
    break;
  default:
    for (y = x->SharedSecretChallengeResponse; n > 1 && y->gg.g.n; --n, y = (struct zx_ac_SharedSecretChallengeResponse_s*)y->gg.g.n) ;
    if (!y->gg.g.n) return;
  }
  y->gg.g.n = y->gg.g.n->n;
}

#endif



#ifdef ZX_ENA_GETPUT

/* FUNC(zx_ac_Authenticator_NUM_SharedSecretDynamicPlaintext) */

int zx_ac_Authenticator_NUM_SharedSecretDynamicPlaintext(struct zx_ac_Authenticator_s* x)
{
  struct zx_ac_SharedSecretDynamicPlaintext_s* y;
  int n = 0;
  if (!x) return 0;
  for (y = x->SharedSecretDynamicPlaintext; y; ++n, y = (struct zx_ac_SharedSecretDynamicPlaintext_s*)y->gg.g.n) ;
  return n;
}

/* FUNC(zx_ac_Authenticator_GET_SharedSecretDynamicPlaintext) */

struct zx_ac_SharedSecretDynamicPlaintext_s* zx_ac_Authenticator_GET_SharedSecretDynamicPlaintext(struct zx_ac_Authenticator_s* x, int n)
{
  struct zx_ac_SharedSecretDynamicPlaintext_s* y;
  if (!x) return 0;
  for (y = x->SharedSecretDynamicPlaintext; n>=0 && y; --n, y = (struct zx_ac_SharedSecretDynamicPlaintext_s*)y->gg.g.n) ;
  return y;
}

/* FUNC(zx_ac_Authenticator_POP_SharedSecretDynamicPlaintext) */

struct zx_ac_SharedSecretDynamicPlaintext_s* zx_ac_Authenticator_POP_SharedSecretDynamicPlaintext(struct zx_ac_Authenticator_s* x)
{
  struct zx_ac_SharedSecretDynamicPlaintext_s* y;
  if (!x) return 0;
  y = x->SharedSecretDynamicPlaintext;
  if (y)
    x->SharedSecretDynamicPlaintext = (struct zx_ac_SharedSecretDynamicPlaintext_s*)y->gg.g.n;
  return y;
}

/* FUNC(zx_ac_Authenticator_PUSH_SharedSecretDynamicPlaintext) */

void zx_ac_Authenticator_PUSH_SharedSecretDynamicPlaintext(struct zx_ac_Authenticator_s* x, struct zx_ac_SharedSecretDynamicPlaintext_s* z)
{
  if (!x || !z) return;
  z->gg.g.n = &x->SharedSecretDynamicPlaintext->gg.g;
  x->SharedSecretDynamicPlaintext = z;
}

/* FUNC(zx_ac_Authenticator_REV_SharedSecretDynamicPlaintext) */

void zx_ac_Authenticator_REV_SharedSecretDynamicPlaintext(struct zx_ac_Authenticator_s* x)
{
  struct zx_ac_SharedSecretDynamicPlaintext_s* nxt;
  struct zx_ac_SharedSecretDynamicPlaintext_s* y;
  if (!x) return;
  y = x->SharedSecretDynamicPlaintext;
  if (!y) return;
  x->SharedSecretDynamicPlaintext = 0;
  while (y) {
    nxt = (struct zx_ac_SharedSecretDynamicPlaintext_s*)y->gg.g.n;
    y->gg.g.n = &x->SharedSecretDynamicPlaintext->gg.g;
    x->SharedSecretDynamicPlaintext = y;
    y = nxt;
  }
}

/* FUNC(zx_ac_Authenticator_PUT_SharedSecretDynamicPlaintext) */

void zx_ac_Authenticator_PUT_SharedSecretDynamicPlaintext(struct zx_ac_Authenticator_s* x, int n, struct zx_ac_SharedSecretDynamicPlaintext_s* z)
{
  struct zx_ac_SharedSecretDynamicPlaintext_s* y;
  if (!x || !z) return;
  y = x->SharedSecretDynamicPlaintext;
  if (!y) return;
  switch (n) {
  case 0:
    z->gg.g.n = y->gg.g.n;
    x->SharedSecretDynamicPlaintext = z;
    return;
  default:
    for (; n > 1 && y->gg.g.n; --n, y = (struct zx_ac_SharedSecretDynamicPlaintext_s*)y->gg.g.n) ;
    if (!y->gg.g.n) return;
    z->gg.g.n = y->gg.g.n->n;
    y->gg.g.n = &z->gg.g;
  }
}

/* FUNC(zx_ac_Authenticator_ADD_SharedSecretDynamicPlaintext) */

void zx_ac_Authenticator_ADD_SharedSecretDynamicPlaintext(struct zx_ac_Authenticator_s* x, int n, struct zx_ac_SharedSecretDynamicPlaintext_s* z)
{
  struct zx_ac_SharedSecretDynamicPlaintext_s* y;
  if (!x || !z) return;
  switch (n) {
  case 0:
  add_to_start:
    z->gg.g.n = &x->SharedSecretDynamicPlaintext->gg.g;
    x->SharedSecretDynamicPlaintext = z;
    return;
  case -1:
    y = x->SharedSecretDynamicPlaintext;
    if (!y) goto add_to_start;
    for (; y->gg.g.n; y = (struct zx_ac_SharedSecretDynamicPlaintext_s*)y->gg.g.n) ;
    break;
  default:
    for (y = x->SharedSecretDynamicPlaintext; n > 1 && y; --n, y = (struct zx_ac_SharedSecretDynamicPlaintext_s*)y->gg.g.n) ;
    if (!y) return;
  }
  z->gg.g.n = y->gg.g.n;
  y->gg.g.n = &z->gg.g;
}

/* FUNC(zx_ac_Authenticator_DEL_SharedSecretDynamicPlaintext) */

void zx_ac_Authenticator_DEL_SharedSecretDynamicPlaintext(struct zx_ac_Authenticator_s* x, int n)
{
  struct zx_ac_SharedSecretDynamicPlaintext_s* y;
  if (!x) return;
  switch (n) {
  case 0:
    x->SharedSecretDynamicPlaintext = (struct zx_ac_SharedSecretDynamicPlaintext_s*)x->SharedSecretDynamicPlaintext->gg.g.n;
    return;
  case -1:
    y = (struct zx_ac_SharedSecretDynamicPlaintext_s*)x->SharedSecretDynamicPlaintext;
    if (!y) return;
    for (; y->gg.g.n; y = (struct zx_ac_SharedSecretDynamicPlaintext_s*)y->gg.g.n) ;
    break;
  default:
    for (y = x->SharedSecretDynamicPlaintext; n > 1 && y->gg.g.n; --n, y = (struct zx_ac_SharedSecretDynamicPlaintext_s*)y->gg.g.n) ;
    if (!y->gg.g.n) return;
  }
  y->gg.g.n = y->gg.g.n->n;
}

#endif



#ifdef ZX_ENA_GETPUT

/* FUNC(zx_ac_Authenticator_NUM_IPAddress) */

int zx_ac_Authenticator_NUM_IPAddress(struct zx_ac_Authenticator_s* x)
{
  struct zx_ac_IPAddress_s* y;
  int n = 0;
  if (!x) return 0;
  for (y = x->IPAddress; y; ++n, y = (struct zx_ac_IPAddress_s*)y->gg.g.n) ;
  return n;
}

/* FUNC(zx_ac_Authenticator_GET_IPAddress) */

struct zx_ac_IPAddress_s* zx_ac_Authenticator_GET_IPAddress(struct zx_ac_Authenticator_s* x, int n)
{
  struct zx_ac_IPAddress_s* y;
  if (!x) return 0;
  for (y = x->IPAddress; n>=0 && y; --n, y = (struct zx_ac_IPAddress_s*)y->gg.g.n) ;
  return y;
}

/* FUNC(zx_ac_Authenticator_POP_IPAddress) */

struct zx_ac_IPAddress_s* zx_ac_Authenticator_POP_IPAddress(struct zx_ac_Authenticator_s* x)
{
  struct zx_ac_IPAddress_s* y;
  if (!x) return 0;
  y = x->IPAddress;
  if (y)
    x->IPAddress = (struct zx_ac_IPAddress_s*)y->gg.g.n;
  return y;
}

/* FUNC(zx_ac_Authenticator_PUSH_IPAddress) */

void zx_ac_Authenticator_PUSH_IPAddress(struct zx_ac_Authenticator_s* x, struct zx_ac_IPAddress_s* z)
{
  if (!x || !z) return;
  z->gg.g.n = &x->IPAddress->gg.g;
  x->IPAddress = z;
}

/* FUNC(zx_ac_Authenticator_REV_IPAddress) */

void zx_ac_Authenticator_REV_IPAddress(struct zx_ac_Authenticator_s* x)
{
  struct zx_ac_IPAddress_s* nxt;
  struct zx_ac_IPAddress_s* y;
  if (!x) return;
  y = x->IPAddress;
  if (!y) return;
  x->IPAddress = 0;
  while (y) {
    nxt = (struct zx_ac_IPAddress_s*)y->gg.g.n;
    y->gg.g.n = &x->IPAddress->gg.g;
    x->IPAddress = y;
    y = nxt;
  }
}

/* FUNC(zx_ac_Authenticator_PUT_IPAddress) */

void zx_ac_Authenticator_PUT_IPAddress(struct zx_ac_Authenticator_s* x, int n, struct zx_ac_IPAddress_s* z)
{
  struct zx_ac_IPAddress_s* y;
  if (!x || !z) return;
  y = x->IPAddress;
  if (!y) return;
  switch (n) {
  case 0:
    z->gg.g.n = y->gg.g.n;
    x->IPAddress = z;
    return;
  default:
    for (; n > 1 && y->gg.g.n; --n, y = (struct zx_ac_IPAddress_s*)y->gg.g.n) ;
    if (!y->gg.g.n) return;
    z->gg.g.n = y->gg.g.n->n;
    y->gg.g.n = &z->gg.g;
  }
}

/* FUNC(zx_ac_Authenticator_ADD_IPAddress) */

void zx_ac_Authenticator_ADD_IPAddress(struct zx_ac_Authenticator_s* x, int n, struct zx_ac_IPAddress_s* z)
{
  struct zx_ac_IPAddress_s* y;
  if (!x || !z) return;
  switch (n) {
  case 0:
  add_to_start:
    z->gg.g.n = &x->IPAddress->gg.g;
    x->IPAddress = z;
    return;
  case -1:
    y = x->IPAddress;
    if (!y) goto add_to_start;
    for (; y->gg.g.n; y = (struct zx_ac_IPAddress_s*)y->gg.g.n) ;
    break;
  default:
    for (y = x->IPAddress; n > 1 && y; --n, y = (struct zx_ac_IPAddress_s*)y->gg.g.n) ;
    if (!y) return;
  }
  z->gg.g.n = y->gg.g.n;
  y->gg.g.n = &z->gg.g;
}

/* FUNC(zx_ac_Authenticator_DEL_IPAddress) */

void zx_ac_Authenticator_DEL_IPAddress(struct zx_ac_Authenticator_s* x, int n)
{
  struct zx_ac_IPAddress_s* y;
  if (!x) return;
  switch (n) {
  case 0:
    x->IPAddress = (struct zx_ac_IPAddress_s*)x->IPAddress->gg.g.n;
    return;
  case -1:
    y = (struct zx_ac_IPAddress_s*)x->IPAddress;
    if (!y) return;
    for (; y->gg.g.n; y = (struct zx_ac_IPAddress_s*)y->gg.g.n) ;
    break;
  default:
    for (y = x->IPAddress; n > 1 && y->gg.g.n; --n, y = (struct zx_ac_IPAddress_s*)y->gg.g.n) ;
    if (!y->gg.g.n) return;
  }
  y->gg.g.n = y->gg.g.n->n;
}

#endif



#ifdef ZX_ENA_GETPUT

/* FUNC(zx_ac_Authenticator_NUM_AsymmetricDecryption) */

int zx_ac_Authenticator_NUM_AsymmetricDecryption(struct zx_ac_Authenticator_s* x)
{
  struct zx_ac_AsymmetricDecryption_s* y;
  int n = 0;
  if (!x) return 0;
  for (y = x->AsymmetricDecryption; y; ++n, y = (struct zx_ac_AsymmetricDecryption_s*)y->gg.g.n) ;
  return n;
}

/* FUNC(zx_ac_Authenticator_GET_AsymmetricDecryption) */

struct zx_ac_AsymmetricDecryption_s* zx_ac_Authenticator_GET_AsymmetricDecryption(struct zx_ac_Authenticator_s* x, int n)
{
  struct zx_ac_AsymmetricDecryption_s* y;
  if (!x) return 0;
  for (y = x->AsymmetricDecryption; n>=0 && y; --n, y = (struct zx_ac_AsymmetricDecryption_s*)y->gg.g.n) ;
  return y;
}

/* FUNC(zx_ac_Authenticator_POP_AsymmetricDecryption) */

struct zx_ac_AsymmetricDecryption_s* zx_ac_Authenticator_POP_AsymmetricDecryption(struct zx_ac_Authenticator_s* x)
{
  struct zx_ac_AsymmetricDecryption_s* y;
  if (!x) return 0;
  y = x->AsymmetricDecryption;
  if (y)
    x->AsymmetricDecryption = (struct zx_ac_AsymmetricDecryption_s*)y->gg.g.n;
  return y;
}

/* FUNC(zx_ac_Authenticator_PUSH_AsymmetricDecryption) */

void zx_ac_Authenticator_PUSH_AsymmetricDecryption(struct zx_ac_Authenticator_s* x, struct zx_ac_AsymmetricDecryption_s* z)
{
  if (!x || !z) return;
  z->gg.g.n = &x->AsymmetricDecryption->gg.g;
  x->AsymmetricDecryption = z;
}

/* FUNC(zx_ac_Authenticator_REV_AsymmetricDecryption) */

void zx_ac_Authenticator_REV_AsymmetricDecryption(struct zx_ac_Authenticator_s* x)
{
  struct zx_ac_AsymmetricDecryption_s* nxt;
  struct zx_ac_AsymmetricDecryption_s* y;
  if (!x) return;
  y = x->AsymmetricDecryption;
  if (!y) return;
  x->AsymmetricDecryption = 0;
  while (y) {
    nxt = (struct zx_ac_AsymmetricDecryption_s*)y->gg.g.n;
    y->gg.g.n = &x->AsymmetricDecryption->gg.g;
    x->AsymmetricDecryption = y;
    y = nxt;
  }
}

/* FUNC(zx_ac_Authenticator_PUT_AsymmetricDecryption) */

void zx_ac_Authenticator_PUT_AsymmetricDecryption(struct zx_ac_Authenticator_s* x, int n, struct zx_ac_AsymmetricDecryption_s* z)
{
  struct zx_ac_AsymmetricDecryption_s* y;
  if (!x || !z) return;
  y = x->AsymmetricDecryption;
  if (!y) return;
  switch (n) {
  case 0:
    z->gg.g.n = y->gg.g.n;
    x->AsymmetricDecryption = z;
    return;
  default:
    for (; n > 1 && y->gg.g.n; --n, y = (struct zx_ac_AsymmetricDecryption_s*)y->gg.g.n) ;
    if (!y->gg.g.n) return;
    z->gg.g.n = y->gg.g.n->n;
    y->gg.g.n = &z->gg.g;
  }
}

/* FUNC(zx_ac_Authenticator_ADD_AsymmetricDecryption) */

void zx_ac_Authenticator_ADD_AsymmetricDecryption(struct zx_ac_Authenticator_s* x, int n, struct zx_ac_AsymmetricDecryption_s* z)
{
  struct zx_ac_AsymmetricDecryption_s* y;
  if (!x || !z) return;
  switch (n) {
  case 0:
  add_to_start:
    z->gg.g.n = &x->AsymmetricDecryption->gg.g;
    x->AsymmetricDecryption = z;
    return;
  case -1:
    y = x->AsymmetricDecryption;
    if (!y) goto add_to_start;
    for (; y->gg.g.n; y = (struct zx_ac_AsymmetricDecryption_s*)y->gg.g.n) ;
    break;
  default:
    for (y = x->AsymmetricDecryption; n > 1 && y; --n, y = (struct zx_ac_AsymmetricDecryption_s*)y->gg.g.n) ;
    if (!y) return;
  }
  z->gg.g.n = y->gg.g.n;
  y->gg.g.n = &z->gg.g;
}

/* FUNC(zx_ac_Authenticator_DEL_AsymmetricDecryption) */

void zx_ac_Authenticator_DEL_AsymmetricDecryption(struct zx_ac_Authenticator_s* x, int n)
{
  struct zx_ac_AsymmetricDecryption_s* y;
  if (!x) return;
  switch (n) {
  case 0:
    x->AsymmetricDecryption = (struct zx_ac_AsymmetricDecryption_s*)x->AsymmetricDecryption->gg.g.n;
    return;
  case -1:
    y = (struct zx_ac_AsymmetricDecryption_s*)x->AsymmetricDecryption;
    if (!y) return;
    for (; y->gg.g.n; y = (struct zx_ac_AsymmetricDecryption_s*)y->gg.g.n) ;
    break;
  default:
    for (y = x->AsymmetricDecryption; n > 1 && y->gg.g.n; --n, y = (struct zx_ac_AsymmetricDecryption_s*)y->gg.g.n) ;
    if (!y->gg.g.n) return;
  }
  y->gg.g.n = y->gg.g.n->n;
}

#endif



#ifdef ZX_ENA_GETPUT

/* FUNC(zx_ac_Authenticator_NUM_AsymmetricKeyAgreement) */

int zx_ac_Authenticator_NUM_AsymmetricKeyAgreement(struct zx_ac_Authenticator_s* x)
{
  struct zx_ac_AsymmetricKeyAgreement_s* y;
  int n = 0;
  if (!x) return 0;
  for (y = x->AsymmetricKeyAgreement; y; ++n, y = (struct zx_ac_AsymmetricKeyAgreement_s*)y->gg.g.n) ;
  return n;
}

/* FUNC(zx_ac_Authenticator_GET_AsymmetricKeyAgreement) */

struct zx_ac_AsymmetricKeyAgreement_s* zx_ac_Authenticator_GET_AsymmetricKeyAgreement(struct zx_ac_Authenticator_s* x, int n)
{
  struct zx_ac_AsymmetricKeyAgreement_s* y;
  if (!x) return 0;
  for (y = x->AsymmetricKeyAgreement; n>=0 && y; --n, y = (struct zx_ac_AsymmetricKeyAgreement_s*)y->gg.g.n) ;
  return y;
}

/* FUNC(zx_ac_Authenticator_POP_AsymmetricKeyAgreement) */

struct zx_ac_AsymmetricKeyAgreement_s* zx_ac_Authenticator_POP_AsymmetricKeyAgreement(struct zx_ac_Authenticator_s* x)
{
  struct zx_ac_AsymmetricKeyAgreement_s* y;
  if (!x) return 0;
  y = x->AsymmetricKeyAgreement;
  if (y)
    x->AsymmetricKeyAgreement = (struct zx_ac_AsymmetricKeyAgreement_s*)y->gg.g.n;
  return y;
}

/* FUNC(zx_ac_Authenticator_PUSH_AsymmetricKeyAgreement) */

void zx_ac_Authenticator_PUSH_AsymmetricKeyAgreement(struct zx_ac_Authenticator_s* x, struct zx_ac_AsymmetricKeyAgreement_s* z)
{
  if (!x || !z) return;
  z->gg.g.n = &x->AsymmetricKeyAgreement->gg.g;
  x->AsymmetricKeyAgreement = z;
}

/* FUNC(zx_ac_Authenticator_REV_AsymmetricKeyAgreement) */

void zx_ac_Authenticator_REV_AsymmetricKeyAgreement(struct zx_ac_Authenticator_s* x)
{
  struct zx_ac_AsymmetricKeyAgreement_s* nxt;
  struct zx_ac_AsymmetricKeyAgreement_s* y;
  if (!x) return;
  y = x->AsymmetricKeyAgreement;
  if (!y) return;
  x->AsymmetricKeyAgreement = 0;
  while (y) {
    nxt = (struct zx_ac_AsymmetricKeyAgreement_s*)y->gg.g.n;
    y->gg.g.n = &x->AsymmetricKeyAgreement->gg.g;
    x->AsymmetricKeyAgreement = y;
    y = nxt;
  }
}

/* FUNC(zx_ac_Authenticator_PUT_AsymmetricKeyAgreement) */

void zx_ac_Authenticator_PUT_AsymmetricKeyAgreement(struct zx_ac_Authenticator_s* x, int n, struct zx_ac_AsymmetricKeyAgreement_s* z)
{
  struct zx_ac_AsymmetricKeyAgreement_s* y;
  if (!x || !z) return;
  y = x->AsymmetricKeyAgreement;
  if (!y) return;
  switch (n) {
  case 0:
    z->gg.g.n = y->gg.g.n;
    x->AsymmetricKeyAgreement = z;
    return;
  default:
    for (; n > 1 && y->gg.g.n; --n, y = (struct zx_ac_AsymmetricKeyAgreement_s*)y->gg.g.n) ;
    if (!y->gg.g.n) return;
    z->gg.g.n = y->gg.g.n->n;
    y->gg.g.n = &z->gg.g;
  }
}

/* FUNC(zx_ac_Authenticator_ADD_AsymmetricKeyAgreement) */

void zx_ac_Authenticator_ADD_AsymmetricKeyAgreement(struct zx_ac_Authenticator_s* x, int n, struct zx_ac_AsymmetricKeyAgreement_s* z)
{
  struct zx_ac_AsymmetricKeyAgreement_s* y;
  if (!x || !z) return;
  switch (n) {
  case 0:
  add_to_start:
    z->gg.g.n = &x->AsymmetricKeyAgreement->gg.g;
    x->AsymmetricKeyAgreement = z;
    return;
  case -1:
    y = x->AsymmetricKeyAgreement;
    if (!y) goto add_to_start;
    for (; y->gg.g.n; y = (struct zx_ac_AsymmetricKeyAgreement_s*)y->gg.g.n) ;
    break;
  default:
    for (y = x->AsymmetricKeyAgreement; n > 1 && y; --n, y = (struct zx_ac_AsymmetricKeyAgreement_s*)y->gg.g.n) ;
    if (!y) return;
  }
  z->gg.g.n = y->gg.g.n;
  y->gg.g.n = &z->gg.g;
}

/* FUNC(zx_ac_Authenticator_DEL_AsymmetricKeyAgreement) */

void zx_ac_Authenticator_DEL_AsymmetricKeyAgreement(struct zx_ac_Authenticator_s* x, int n)
{
  struct zx_ac_AsymmetricKeyAgreement_s* y;
  if (!x) return;
  switch (n) {
  case 0:
    x->AsymmetricKeyAgreement = (struct zx_ac_AsymmetricKeyAgreement_s*)x->AsymmetricKeyAgreement->gg.g.n;
    return;
  case -1:
    y = (struct zx_ac_AsymmetricKeyAgreement_s*)x->AsymmetricKeyAgreement;
    if (!y) return;
    for (; y->gg.g.n; y = (struct zx_ac_AsymmetricKeyAgreement_s*)y->gg.g.n) ;
    break;
  default:
    for (y = x->AsymmetricKeyAgreement; n > 1 && y->gg.g.n; --n, y = (struct zx_ac_AsymmetricKeyAgreement_s*)y->gg.g.n) ;
    if (!y->gg.g.n) return;
  }
  y->gg.g.n = y->gg.g.n->n;
}

#endif



#ifdef ZX_ENA_GETPUT

/* FUNC(zx_ac_Authenticator_NUM_Extension) */

int zx_ac_Authenticator_NUM_Extension(struct zx_ac_Authenticator_s* x)
{
  struct zx_ac_Extension_s* y;
  int n = 0;
  if (!x) return 0;
  for (y = x->Extension; y; ++n, y = (struct zx_ac_Extension_s*)y->gg.g.n) ;
  return n;
}

/* FUNC(zx_ac_Authenticator_GET_Extension) */

struct zx_ac_Extension_s* zx_ac_Authenticator_GET_Extension(struct zx_ac_Authenticator_s* x, int n)
{
  struct zx_ac_Extension_s* y;
  if (!x) return 0;
  for (y = x->Extension; n>=0 && y; --n, y = (struct zx_ac_Extension_s*)y->gg.g.n) ;
  return y;
}

/* FUNC(zx_ac_Authenticator_POP_Extension) */

struct zx_ac_Extension_s* zx_ac_Authenticator_POP_Extension(struct zx_ac_Authenticator_s* x)
{
  struct zx_ac_Extension_s* y;
  if (!x) return 0;
  y = x->Extension;
  if (y)
    x->Extension = (struct zx_ac_Extension_s*)y->gg.g.n;
  return y;
}

/* FUNC(zx_ac_Authenticator_PUSH_Extension) */

void zx_ac_Authenticator_PUSH_Extension(struct zx_ac_Authenticator_s* x, struct zx_ac_Extension_s* z)
{
  if (!x || !z) return;
  z->gg.g.n = &x->Extension->gg.g;
  x->Extension = z;
}

/* FUNC(zx_ac_Authenticator_REV_Extension) */

void zx_ac_Authenticator_REV_Extension(struct zx_ac_Authenticator_s* x)
{
  struct zx_ac_Extension_s* nxt;
  struct zx_ac_Extension_s* y;
  if (!x) return;
  y = x->Extension;
  if (!y) return;
  x->Extension = 0;
  while (y) {
    nxt = (struct zx_ac_Extension_s*)y->gg.g.n;
    y->gg.g.n = &x->Extension->gg.g;
    x->Extension = y;
    y = nxt;
  }
}

/* FUNC(zx_ac_Authenticator_PUT_Extension) */

void zx_ac_Authenticator_PUT_Extension(struct zx_ac_Authenticator_s* x, int n, struct zx_ac_Extension_s* z)
{
  struct zx_ac_Extension_s* y;
  if (!x || !z) return;
  y = x->Extension;
  if (!y) return;
  switch (n) {
  case 0:
    z->gg.g.n = y->gg.g.n;
    x->Extension = z;
    return;
  default:
    for (; n > 1 && y->gg.g.n; --n, y = (struct zx_ac_Extension_s*)y->gg.g.n) ;
    if (!y->gg.g.n) return;
    z->gg.g.n = y->gg.g.n->n;
    y->gg.g.n = &z->gg.g;
  }
}

/* FUNC(zx_ac_Authenticator_ADD_Extension) */

void zx_ac_Authenticator_ADD_Extension(struct zx_ac_Authenticator_s* x, int n, struct zx_ac_Extension_s* z)
{
  struct zx_ac_Extension_s* y;
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
    for (; y->gg.g.n; y = (struct zx_ac_Extension_s*)y->gg.g.n) ;
    break;
  default:
    for (y = x->Extension; n > 1 && y; --n, y = (struct zx_ac_Extension_s*)y->gg.g.n) ;
    if (!y) return;
  }
  z->gg.g.n = y->gg.g.n;
  y->gg.g.n = &z->gg.g;
}

/* FUNC(zx_ac_Authenticator_DEL_Extension) */

void zx_ac_Authenticator_DEL_Extension(struct zx_ac_Authenticator_s* x, int n)
{
  struct zx_ac_Extension_s* y;
  if (!x) return;
  switch (n) {
  case 0:
    x->Extension = (struct zx_ac_Extension_s*)x->Extension->gg.g.n;
    return;
  case -1:
    y = (struct zx_ac_Extension_s*)x->Extension;
    if (!y) return;
    for (; y->gg.g.n; y = (struct zx_ac_Extension_s*)y->gg.g.n) ;
    break;
  default:
    for (y = x->Extension; n > 1 && y->gg.g.n; --n, y = (struct zx_ac_Extension_s*)y->gg.g.n) ;
    if (!y->gg.g.n) return;
  }
  y->gg.g.n = y->gg.g.n->n;
}

#endif








#ifdef ZX_ENA_GETPUT

/* FUNC(zx_ac_AuthenticatorTransportProtocol_NUM_HTTP) */

int zx_ac_AuthenticatorTransportProtocol_NUM_HTTP(struct zx_ac_AuthenticatorTransportProtocol_s* x)
{
  struct zx_ac_HTTP_s* y;
  int n = 0;
  if (!x) return 0;
  for (y = x->HTTP; y; ++n, y = (struct zx_ac_HTTP_s*)y->gg.g.n) ;
  return n;
}

/* FUNC(zx_ac_AuthenticatorTransportProtocol_GET_HTTP) */

struct zx_ac_HTTP_s* zx_ac_AuthenticatorTransportProtocol_GET_HTTP(struct zx_ac_AuthenticatorTransportProtocol_s* x, int n)
{
  struct zx_ac_HTTP_s* y;
  if (!x) return 0;
  for (y = x->HTTP; n>=0 && y; --n, y = (struct zx_ac_HTTP_s*)y->gg.g.n) ;
  return y;
}

/* FUNC(zx_ac_AuthenticatorTransportProtocol_POP_HTTP) */

struct zx_ac_HTTP_s* zx_ac_AuthenticatorTransportProtocol_POP_HTTP(struct zx_ac_AuthenticatorTransportProtocol_s* x)
{
  struct zx_ac_HTTP_s* y;
  if (!x) return 0;
  y = x->HTTP;
  if (y)
    x->HTTP = (struct zx_ac_HTTP_s*)y->gg.g.n;
  return y;
}

/* FUNC(zx_ac_AuthenticatorTransportProtocol_PUSH_HTTP) */

void zx_ac_AuthenticatorTransportProtocol_PUSH_HTTP(struct zx_ac_AuthenticatorTransportProtocol_s* x, struct zx_ac_HTTP_s* z)
{
  if (!x || !z) return;
  z->gg.g.n = &x->HTTP->gg.g;
  x->HTTP = z;
}

/* FUNC(zx_ac_AuthenticatorTransportProtocol_REV_HTTP) */

void zx_ac_AuthenticatorTransportProtocol_REV_HTTP(struct zx_ac_AuthenticatorTransportProtocol_s* x)
{
  struct zx_ac_HTTP_s* nxt;
  struct zx_ac_HTTP_s* y;
  if (!x) return;
  y = x->HTTP;
  if (!y) return;
  x->HTTP = 0;
  while (y) {
    nxt = (struct zx_ac_HTTP_s*)y->gg.g.n;
    y->gg.g.n = &x->HTTP->gg.g;
    x->HTTP = y;
    y = nxt;
  }
}

/* FUNC(zx_ac_AuthenticatorTransportProtocol_PUT_HTTP) */

void zx_ac_AuthenticatorTransportProtocol_PUT_HTTP(struct zx_ac_AuthenticatorTransportProtocol_s* x, int n, struct zx_ac_HTTP_s* z)
{
  struct zx_ac_HTTP_s* y;
  if (!x || !z) return;
  y = x->HTTP;
  if (!y) return;
  switch (n) {
  case 0:
    z->gg.g.n = y->gg.g.n;
    x->HTTP = z;
    return;
  default:
    for (; n > 1 && y->gg.g.n; --n, y = (struct zx_ac_HTTP_s*)y->gg.g.n) ;
    if (!y->gg.g.n) return;
    z->gg.g.n = y->gg.g.n->n;
    y->gg.g.n = &z->gg.g;
  }
}

/* FUNC(zx_ac_AuthenticatorTransportProtocol_ADD_HTTP) */

void zx_ac_AuthenticatorTransportProtocol_ADD_HTTP(struct zx_ac_AuthenticatorTransportProtocol_s* x, int n, struct zx_ac_HTTP_s* z)
{
  struct zx_ac_HTTP_s* y;
  if (!x || !z) return;
  switch (n) {
  case 0:
  add_to_start:
    z->gg.g.n = &x->HTTP->gg.g;
    x->HTTP = z;
    return;
  case -1:
    y = x->HTTP;
    if (!y) goto add_to_start;
    for (; y->gg.g.n; y = (struct zx_ac_HTTP_s*)y->gg.g.n) ;
    break;
  default:
    for (y = x->HTTP; n > 1 && y; --n, y = (struct zx_ac_HTTP_s*)y->gg.g.n) ;
    if (!y) return;
  }
  z->gg.g.n = y->gg.g.n;
  y->gg.g.n = &z->gg.g;
}

/* FUNC(zx_ac_AuthenticatorTransportProtocol_DEL_HTTP) */

void zx_ac_AuthenticatorTransportProtocol_DEL_HTTP(struct zx_ac_AuthenticatorTransportProtocol_s* x, int n)
{
  struct zx_ac_HTTP_s* y;
  if (!x) return;
  switch (n) {
  case 0:
    x->HTTP = (struct zx_ac_HTTP_s*)x->HTTP->gg.g.n;
    return;
  case -1:
    y = (struct zx_ac_HTTP_s*)x->HTTP;
    if (!y) return;
    for (; y->gg.g.n; y = (struct zx_ac_HTTP_s*)y->gg.g.n) ;
    break;
  default:
    for (y = x->HTTP; n > 1 && y->gg.g.n; --n, y = (struct zx_ac_HTTP_s*)y->gg.g.n) ;
    if (!y->gg.g.n) return;
  }
  y->gg.g.n = y->gg.g.n->n;
}

#endif



#ifdef ZX_ENA_GETPUT

/* FUNC(zx_ac_AuthenticatorTransportProtocol_NUM_SSL) */

int zx_ac_AuthenticatorTransportProtocol_NUM_SSL(struct zx_ac_AuthenticatorTransportProtocol_s* x)
{
  struct zx_ac_SSL_s* y;
  int n = 0;
  if (!x) return 0;
  for (y = x->SSL; y; ++n, y = (struct zx_ac_SSL_s*)y->gg.g.n) ;
  return n;
}

/* FUNC(zx_ac_AuthenticatorTransportProtocol_GET_SSL) */

struct zx_ac_SSL_s* zx_ac_AuthenticatorTransportProtocol_GET_SSL(struct zx_ac_AuthenticatorTransportProtocol_s* x, int n)
{
  struct zx_ac_SSL_s* y;
  if (!x) return 0;
  for (y = x->SSL; n>=0 && y; --n, y = (struct zx_ac_SSL_s*)y->gg.g.n) ;
  return y;
}

/* FUNC(zx_ac_AuthenticatorTransportProtocol_POP_SSL) */

struct zx_ac_SSL_s* zx_ac_AuthenticatorTransportProtocol_POP_SSL(struct zx_ac_AuthenticatorTransportProtocol_s* x)
{
  struct zx_ac_SSL_s* y;
  if (!x) return 0;
  y = x->SSL;
  if (y)
    x->SSL = (struct zx_ac_SSL_s*)y->gg.g.n;
  return y;
}

/* FUNC(zx_ac_AuthenticatorTransportProtocol_PUSH_SSL) */

void zx_ac_AuthenticatorTransportProtocol_PUSH_SSL(struct zx_ac_AuthenticatorTransportProtocol_s* x, struct zx_ac_SSL_s* z)
{
  if (!x || !z) return;
  z->gg.g.n = &x->SSL->gg.g;
  x->SSL = z;
}

/* FUNC(zx_ac_AuthenticatorTransportProtocol_REV_SSL) */

void zx_ac_AuthenticatorTransportProtocol_REV_SSL(struct zx_ac_AuthenticatorTransportProtocol_s* x)
{
  struct zx_ac_SSL_s* nxt;
  struct zx_ac_SSL_s* y;
  if (!x) return;
  y = x->SSL;
  if (!y) return;
  x->SSL = 0;
  while (y) {
    nxt = (struct zx_ac_SSL_s*)y->gg.g.n;
    y->gg.g.n = &x->SSL->gg.g;
    x->SSL = y;
    y = nxt;
  }
}

/* FUNC(zx_ac_AuthenticatorTransportProtocol_PUT_SSL) */

void zx_ac_AuthenticatorTransportProtocol_PUT_SSL(struct zx_ac_AuthenticatorTransportProtocol_s* x, int n, struct zx_ac_SSL_s* z)
{
  struct zx_ac_SSL_s* y;
  if (!x || !z) return;
  y = x->SSL;
  if (!y) return;
  switch (n) {
  case 0:
    z->gg.g.n = y->gg.g.n;
    x->SSL = z;
    return;
  default:
    for (; n > 1 && y->gg.g.n; --n, y = (struct zx_ac_SSL_s*)y->gg.g.n) ;
    if (!y->gg.g.n) return;
    z->gg.g.n = y->gg.g.n->n;
    y->gg.g.n = &z->gg.g;
  }
}

/* FUNC(zx_ac_AuthenticatorTransportProtocol_ADD_SSL) */

void zx_ac_AuthenticatorTransportProtocol_ADD_SSL(struct zx_ac_AuthenticatorTransportProtocol_s* x, int n, struct zx_ac_SSL_s* z)
{
  struct zx_ac_SSL_s* y;
  if (!x || !z) return;
  switch (n) {
  case 0:
  add_to_start:
    z->gg.g.n = &x->SSL->gg.g;
    x->SSL = z;
    return;
  case -1:
    y = x->SSL;
    if (!y) goto add_to_start;
    for (; y->gg.g.n; y = (struct zx_ac_SSL_s*)y->gg.g.n) ;
    break;
  default:
    for (y = x->SSL; n > 1 && y; --n, y = (struct zx_ac_SSL_s*)y->gg.g.n) ;
    if (!y) return;
  }
  z->gg.g.n = y->gg.g.n;
  y->gg.g.n = &z->gg.g;
}

/* FUNC(zx_ac_AuthenticatorTransportProtocol_DEL_SSL) */

void zx_ac_AuthenticatorTransportProtocol_DEL_SSL(struct zx_ac_AuthenticatorTransportProtocol_s* x, int n)
{
  struct zx_ac_SSL_s* y;
  if (!x) return;
  switch (n) {
  case 0:
    x->SSL = (struct zx_ac_SSL_s*)x->SSL->gg.g.n;
    return;
  case -1:
    y = (struct zx_ac_SSL_s*)x->SSL;
    if (!y) return;
    for (; y->gg.g.n; y = (struct zx_ac_SSL_s*)y->gg.g.n) ;
    break;
  default:
    for (y = x->SSL; n > 1 && y->gg.g.n; --n, y = (struct zx_ac_SSL_s*)y->gg.g.n) ;
    if (!y->gg.g.n) return;
  }
  y->gg.g.n = y->gg.g.n->n;
}

#endif



#ifdef ZX_ENA_GETPUT

/* FUNC(zx_ac_AuthenticatorTransportProtocol_NUM_MobileNetworkNoEncryption) */

int zx_ac_AuthenticatorTransportProtocol_NUM_MobileNetworkNoEncryption(struct zx_ac_AuthenticatorTransportProtocol_s* x)
{
  struct zx_ac_MobileNetworkNoEncryption_s* y;
  int n = 0;
  if (!x) return 0;
  for (y = x->MobileNetworkNoEncryption; y; ++n, y = (struct zx_ac_MobileNetworkNoEncryption_s*)y->gg.g.n) ;
  return n;
}

/* FUNC(zx_ac_AuthenticatorTransportProtocol_GET_MobileNetworkNoEncryption) */

struct zx_ac_MobileNetworkNoEncryption_s* zx_ac_AuthenticatorTransportProtocol_GET_MobileNetworkNoEncryption(struct zx_ac_AuthenticatorTransportProtocol_s* x, int n)
{
  struct zx_ac_MobileNetworkNoEncryption_s* y;
  if (!x) return 0;
  for (y = x->MobileNetworkNoEncryption; n>=0 && y; --n, y = (struct zx_ac_MobileNetworkNoEncryption_s*)y->gg.g.n) ;
  return y;
}

/* FUNC(zx_ac_AuthenticatorTransportProtocol_POP_MobileNetworkNoEncryption) */

struct zx_ac_MobileNetworkNoEncryption_s* zx_ac_AuthenticatorTransportProtocol_POP_MobileNetworkNoEncryption(struct zx_ac_AuthenticatorTransportProtocol_s* x)
{
  struct zx_ac_MobileNetworkNoEncryption_s* y;
  if (!x) return 0;
  y = x->MobileNetworkNoEncryption;
  if (y)
    x->MobileNetworkNoEncryption = (struct zx_ac_MobileNetworkNoEncryption_s*)y->gg.g.n;
  return y;
}

/* FUNC(zx_ac_AuthenticatorTransportProtocol_PUSH_MobileNetworkNoEncryption) */

void zx_ac_AuthenticatorTransportProtocol_PUSH_MobileNetworkNoEncryption(struct zx_ac_AuthenticatorTransportProtocol_s* x, struct zx_ac_MobileNetworkNoEncryption_s* z)
{
  if (!x || !z) return;
  z->gg.g.n = &x->MobileNetworkNoEncryption->gg.g;
  x->MobileNetworkNoEncryption = z;
}

/* FUNC(zx_ac_AuthenticatorTransportProtocol_REV_MobileNetworkNoEncryption) */

void zx_ac_AuthenticatorTransportProtocol_REV_MobileNetworkNoEncryption(struct zx_ac_AuthenticatorTransportProtocol_s* x)
{
  struct zx_ac_MobileNetworkNoEncryption_s* nxt;
  struct zx_ac_MobileNetworkNoEncryption_s* y;
  if (!x) return;
  y = x->MobileNetworkNoEncryption;
  if (!y) return;
  x->MobileNetworkNoEncryption = 0;
  while (y) {
    nxt = (struct zx_ac_MobileNetworkNoEncryption_s*)y->gg.g.n;
    y->gg.g.n = &x->MobileNetworkNoEncryption->gg.g;
    x->MobileNetworkNoEncryption = y;
    y = nxt;
  }
}

/* FUNC(zx_ac_AuthenticatorTransportProtocol_PUT_MobileNetworkNoEncryption) */

void zx_ac_AuthenticatorTransportProtocol_PUT_MobileNetworkNoEncryption(struct zx_ac_AuthenticatorTransportProtocol_s* x, int n, struct zx_ac_MobileNetworkNoEncryption_s* z)
{
  struct zx_ac_MobileNetworkNoEncryption_s* y;
  if (!x || !z) return;
  y = x->MobileNetworkNoEncryption;
  if (!y) return;
  switch (n) {
  case 0:
    z->gg.g.n = y->gg.g.n;
    x->MobileNetworkNoEncryption = z;
    return;
  default:
    for (; n > 1 && y->gg.g.n; --n, y = (struct zx_ac_MobileNetworkNoEncryption_s*)y->gg.g.n) ;
    if (!y->gg.g.n) return;
    z->gg.g.n = y->gg.g.n->n;
    y->gg.g.n = &z->gg.g;
  }
}

/* FUNC(zx_ac_AuthenticatorTransportProtocol_ADD_MobileNetworkNoEncryption) */

void zx_ac_AuthenticatorTransportProtocol_ADD_MobileNetworkNoEncryption(struct zx_ac_AuthenticatorTransportProtocol_s* x, int n, struct zx_ac_MobileNetworkNoEncryption_s* z)
{
  struct zx_ac_MobileNetworkNoEncryption_s* y;
  if (!x || !z) return;
  switch (n) {
  case 0:
  add_to_start:
    z->gg.g.n = &x->MobileNetworkNoEncryption->gg.g;
    x->MobileNetworkNoEncryption = z;
    return;
  case -1:
    y = x->MobileNetworkNoEncryption;
    if (!y) goto add_to_start;
    for (; y->gg.g.n; y = (struct zx_ac_MobileNetworkNoEncryption_s*)y->gg.g.n) ;
    break;
  default:
    for (y = x->MobileNetworkNoEncryption; n > 1 && y; --n, y = (struct zx_ac_MobileNetworkNoEncryption_s*)y->gg.g.n) ;
    if (!y) return;
  }
  z->gg.g.n = y->gg.g.n;
  y->gg.g.n = &z->gg.g;
}

/* FUNC(zx_ac_AuthenticatorTransportProtocol_DEL_MobileNetworkNoEncryption) */

void zx_ac_AuthenticatorTransportProtocol_DEL_MobileNetworkNoEncryption(struct zx_ac_AuthenticatorTransportProtocol_s* x, int n)
{
  struct zx_ac_MobileNetworkNoEncryption_s* y;
  if (!x) return;
  switch (n) {
  case 0:
    x->MobileNetworkNoEncryption = (struct zx_ac_MobileNetworkNoEncryption_s*)x->MobileNetworkNoEncryption->gg.g.n;
    return;
  case -1:
    y = (struct zx_ac_MobileNetworkNoEncryption_s*)x->MobileNetworkNoEncryption;
    if (!y) return;
    for (; y->gg.g.n; y = (struct zx_ac_MobileNetworkNoEncryption_s*)y->gg.g.n) ;
    break;
  default:
    for (y = x->MobileNetworkNoEncryption; n > 1 && y->gg.g.n; --n, y = (struct zx_ac_MobileNetworkNoEncryption_s*)y->gg.g.n) ;
    if (!y->gg.g.n) return;
  }
  y->gg.g.n = y->gg.g.n->n;
}

#endif



#ifdef ZX_ENA_GETPUT

/* FUNC(zx_ac_AuthenticatorTransportProtocol_NUM_MobileNetworkRadioEncryption) */

int zx_ac_AuthenticatorTransportProtocol_NUM_MobileNetworkRadioEncryption(struct zx_ac_AuthenticatorTransportProtocol_s* x)
{
  struct zx_ac_MobileNetworkRadioEncryption_s* y;
  int n = 0;
  if (!x) return 0;
  for (y = x->MobileNetworkRadioEncryption; y; ++n, y = (struct zx_ac_MobileNetworkRadioEncryption_s*)y->gg.g.n) ;
  return n;
}

/* FUNC(zx_ac_AuthenticatorTransportProtocol_GET_MobileNetworkRadioEncryption) */

struct zx_ac_MobileNetworkRadioEncryption_s* zx_ac_AuthenticatorTransportProtocol_GET_MobileNetworkRadioEncryption(struct zx_ac_AuthenticatorTransportProtocol_s* x, int n)
{
  struct zx_ac_MobileNetworkRadioEncryption_s* y;
  if (!x) return 0;
  for (y = x->MobileNetworkRadioEncryption; n>=0 && y; --n, y = (struct zx_ac_MobileNetworkRadioEncryption_s*)y->gg.g.n) ;
  return y;
}

/* FUNC(zx_ac_AuthenticatorTransportProtocol_POP_MobileNetworkRadioEncryption) */

struct zx_ac_MobileNetworkRadioEncryption_s* zx_ac_AuthenticatorTransportProtocol_POP_MobileNetworkRadioEncryption(struct zx_ac_AuthenticatorTransportProtocol_s* x)
{
  struct zx_ac_MobileNetworkRadioEncryption_s* y;
  if (!x) return 0;
  y = x->MobileNetworkRadioEncryption;
  if (y)
    x->MobileNetworkRadioEncryption = (struct zx_ac_MobileNetworkRadioEncryption_s*)y->gg.g.n;
  return y;
}

/* FUNC(zx_ac_AuthenticatorTransportProtocol_PUSH_MobileNetworkRadioEncryption) */

void zx_ac_AuthenticatorTransportProtocol_PUSH_MobileNetworkRadioEncryption(struct zx_ac_AuthenticatorTransportProtocol_s* x, struct zx_ac_MobileNetworkRadioEncryption_s* z)
{
  if (!x || !z) return;
  z->gg.g.n = &x->MobileNetworkRadioEncryption->gg.g;
  x->MobileNetworkRadioEncryption = z;
}

/* FUNC(zx_ac_AuthenticatorTransportProtocol_REV_MobileNetworkRadioEncryption) */

void zx_ac_AuthenticatorTransportProtocol_REV_MobileNetworkRadioEncryption(struct zx_ac_AuthenticatorTransportProtocol_s* x)
{
  struct zx_ac_MobileNetworkRadioEncryption_s* nxt;
  struct zx_ac_MobileNetworkRadioEncryption_s* y;
  if (!x) return;
  y = x->MobileNetworkRadioEncryption;
  if (!y) return;
  x->MobileNetworkRadioEncryption = 0;
  while (y) {
    nxt = (struct zx_ac_MobileNetworkRadioEncryption_s*)y->gg.g.n;
    y->gg.g.n = &x->MobileNetworkRadioEncryption->gg.g;
    x->MobileNetworkRadioEncryption = y;
    y = nxt;
  }
}

/* FUNC(zx_ac_AuthenticatorTransportProtocol_PUT_MobileNetworkRadioEncryption) */

void zx_ac_AuthenticatorTransportProtocol_PUT_MobileNetworkRadioEncryption(struct zx_ac_AuthenticatorTransportProtocol_s* x, int n, struct zx_ac_MobileNetworkRadioEncryption_s* z)
{
  struct zx_ac_MobileNetworkRadioEncryption_s* y;
  if (!x || !z) return;
  y = x->MobileNetworkRadioEncryption;
  if (!y) return;
  switch (n) {
  case 0:
    z->gg.g.n = y->gg.g.n;
    x->MobileNetworkRadioEncryption = z;
    return;
  default:
    for (; n > 1 && y->gg.g.n; --n, y = (struct zx_ac_MobileNetworkRadioEncryption_s*)y->gg.g.n) ;
    if (!y->gg.g.n) return;
    z->gg.g.n = y->gg.g.n->n;
    y->gg.g.n = &z->gg.g;
  }
}

/* FUNC(zx_ac_AuthenticatorTransportProtocol_ADD_MobileNetworkRadioEncryption) */

void zx_ac_AuthenticatorTransportProtocol_ADD_MobileNetworkRadioEncryption(struct zx_ac_AuthenticatorTransportProtocol_s* x, int n, struct zx_ac_MobileNetworkRadioEncryption_s* z)
{
  struct zx_ac_MobileNetworkRadioEncryption_s* y;
  if (!x || !z) return;
  switch (n) {
  case 0:
  add_to_start:
    z->gg.g.n = &x->MobileNetworkRadioEncryption->gg.g;
    x->MobileNetworkRadioEncryption = z;
    return;
  case -1:
    y = x->MobileNetworkRadioEncryption;
    if (!y) goto add_to_start;
    for (; y->gg.g.n; y = (struct zx_ac_MobileNetworkRadioEncryption_s*)y->gg.g.n) ;
    break;
  default:
    for (y = x->MobileNetworkRadioEncryption; n > 1 && y; --n, y = (struct zx_ac_MobileNetworkRadioEncryption_s*)y->gg.g.n) ;
    if (!y) return;
  }
  z->gg.g.n = y->gg.g.n;
  y->gg.g.n = &z->gg.g;
}

/* FUNC(zx_ac_AuthenticatorTransportProtocol_DEL_MobileNetworkRadioEncryption) */

void zx_ac_AuthenticatorTransportProtocol_DEL_MobileNetworkRadioEncryption(struct zx_ac_AuthenticatorTransportProtocol_s* x, int n)
{
  struct zx_ac_MobileNetworkRadioEncryption_s* y;
  if (!x) return;
  switch (n) {
  case 0:
    x->MobileNetworkRadioEncryption = (struct zx_ac_MobileNetworkRadioEncryption_s*)x->MobileNetworkRadioEncryption->gg.g.n;
    return;
  case -1:
    y = (struct zx_ac_MobileNetworkRadioEncryption_s*)x->MobileNetworkRadioEncryption;
    if (!y) return;
    for (; y->gg.g.n; y = (struct zx_ac_MobileNetworkRadioEncryption_s*)y->gg.g.n) ;
    break;
  default:
    for (y = x->MobileNetworkRadioEncryption; n > 1 && y->gg.g.n; --n, y = (struct zx_ac_MobileNetworkRadioEncryption_s*)y->gg.g.n) ;
    if (!y->gg.g.n) return;
  }
  y->gg.g.n = y->gg.g.n->n;
}

#endif



#ifdef ZX_ENA_GETPUT

/* FUNC(zx_ac_AuthenticatorTransportProtocol_NUM_MobileNetworkEndToEndEncryption) */

int zx_ac_AuthenticatorTransportProtocol_NUM_MobileNetworkEndToEndEncryption(struct zx_ac_AuthenticatorTransportProtocol_s* x)
{
  struct zx_ac_MobileNetworkEndToEndEncryption_s* y;
  int n = 0;
  if (!x) return 0;
  for (y = x->MobileNetworkEndToEndEncryption; y; ++n, y = (struct zx_ac_MobileNetworkEndToEndEncryption_s*)y->gg.g.n) ;
  return n;
}

/* FUNC(zx_ac_AuthenticatorTransportProtocol_GET_MobileNetworkEndToEndEncryption) */

struct zx_ac_MobileNetworkEndToEndEncryption_s* zx_ac_AuthenticatorTransportProtocol_GET_MobileNetworkEndToEndEncryption(struct zx_ac_AuthenticatorTransportProtocol_s* x, int n)
{
  struct zx_ac_MobileNetworkEndToEndEncryption_s* y;
  if (!x) return 0;
  for (y = x->MobileNetworkEndToEndEncryption; n>=0 && y; --n, y = (struct zx_ac_MobileNetworkEndToEndEncryption_s*)y->gg.g.n) ;
  return y;
}

/* FUNC(zx_ac_AuthenticatorTransportProtocol_POP_MobileNetworkEndToEndEncryption) */

struct zx_ac_MobileNetworkEndToEndEncryption_s* zx_ac_AuthenticatorTransportProtocol_POP_MobileNetworkEndToEndEncryption(struct zx_ac_AuthenticatorTransportProtocol_s* x)
{
  struct zx_ac_MobileNetworkEndToEndEncryption_s* y;
  if (!x) return 0;
  y = x->MobileNetworkEndToEndEncryption;
  if (y)
    x->MobileNetworkEndToEndEncryption = (struct zx_ac_MobileNetworkEndToEndEncryption_s*)y->gg.g.n;
  return y;
}

/* FUNC(zx_ac_AuthenticatorTransportProtocol_PUSH_MobileNetworkEndToEndEncryption) */

void zx_ac_AuthenticatorTransportProtocol_PUSH_MobileNetworkEndToEndEncryption(struct zx_ac_AuthenticatorTransportProtocol_s* x, struct zx_ac_MobileNetworkEndToEndEncryption_s* z)
{
  if (!x || !z) return;
  z->gg.g.n = &x->MobileNetworkEndToEndEncryption->gg.g;
  x->MobileNetworkEndToEndEncryption = z;
}

/* FUNC(zx_ac_AuthenticatorTransportProtocol_REV_MobileNetworkEndToEndEncryption) */

void zx_ac_AuthenticatorTransportProtocol_REV_MobileNetworkEndToEndEncryption(struct zx_ac_AuthenticatorTransportProtocol_s* x)
{
  struct zx_ac_MobileNetworkEndToEndEncryption_s* nxt;
  struct zx_ac_MobileNetworkEndToEndEncryption_s* y;
  if (!x) return;
  y = x->MobileNetworkEndToEndEncryption;
  if (!y) return;
  x->MobileNetworkEndToEndEncryption = 0;
  while (y) {
    nxt = (struct zx_ac_MobileNetworkEndToEndEncryption_s*)y->gg.g.n;
    y->gg.g.n = &x->MobileNetworkEndToEndEncryption->gg.g;
    x->MobileNetworkEndToEndEncryption = y;
    y = nxt;
  }
}

/* FUNC(zx_ac_AuthenticatorTransportProtocol_PUT_MobileNetworkEndToEndEncryption) */

void zx_ac_AuthenticatorTransportProtocol_PUT_MobileNetworkEndToEndEncryption(struct zx_ac_AuthenticatorTransportProtocol_s* x, int n, struct zx_ac_MobileNetworkEndToEndEncryption_s* z)
{
  struct zx_ac_MobileNetworkEndToEndEncryption_s* y;
  if (!x || !z) return;
  y = x->MobileNetworkEndToEndEncryption;
  if (!y) return;
  switch (n) {
  case 0:
    z->gg.g.n = y->gg.g.n;
    x->MobileNetworkEndToEndEncryption = z;
    return;
  default:
    for (; n > 1 && y->gg.g.n; --n, y = (struct zx_ac_MobileNetworkEndToEndEncryption_s*)y->gg.g.n) ;
    if (!y->gg.g.n) return;
    z->gg.g.n = y->gg.g.n->n;
    y->gg.g.n = &z->gg.g;
  }
}

/* FUNC(zx_ac_AuthenticatorTransportProtocol_ADD_MobileNetworkEndToEndEncryption) */

void zx_ac_AuthenticatorTransportProtocol_ADD_MobileNetworkEndToEndEncryption(struct zx_ac_AuthenticatorTransportProtocol_s* x, int n, struct zx_ac_MobileNetworkEndToEndEncryption_s* z)
{
  struct zx_ac_MobileNetworkEndToEndEncryption_s* y;
  if (!x || !z) return;
  switch (n) {
  case 0:
  add_to_start:
    z->gg.g.n = &x->MobileNetworkEndToEndEncryption->gg.g;
    x->MobileNetworkEndToEndEncryption = z;
    return;
  case -1:
    y = x->MobileNetworkEndToEndEncryption;
    if (!y) goto add_to_start;
    for (; y->gg.g.n; y = (struct zx_ac_MobileNetworkEndToEndEncryption_s*)y->gg.g.n) ;
    break;
  default:
    for (y = x->MobileNetworkEndToEndEncryption; n > 1 && y; --n, y = (struct zx_ac_MobileNetworkEndToEndEncryption_s*)y->gg.g.n) ;
    if (!y) return;
  }
  z->gg.g.n = y->gg.g.n;
  y->gg.g.n = &z->gg.g;
}

/* FUNC(zx_ac_AuthenticatorTransportProtocol_DEL_MobileNetworkEndToEndEncryption) */

void zx_ac_AuthenticatorTransportProtocol_DEL_MobileNetworkEndToEndEncryption(struct zx_ac_AuthenticatorTransportProtocol_s* x, int n)
{
  struct zx_ac_MobileNetworkEndToEndEncryption_s* y;
  if (!x) return;
  switch (n) {
  case 0:
    x->MobileNetworkEndToEndEncryption = (struct zx_ac_MobileNetworkEndToEndEncryption_s*)x->MobileNetworkEndToEndEncryption->gg.g.n;
    return;
  case -1:
    y = (struct zx_ac_MobileNetworkEndToEndEncryption_s*)x->MobileNetworkEndToEndEncryption;
    if (!y) return;
    for (; y->gg.g.n; y = (struct zx_ac_MobileNetworkEndToEndEncryption_s*)y->gg.g.n) ;
    break;
  default:
    for (y = x->MobileNetworkEndToEndEncryption; n > 1 && y->gg.g.n; --n, y = (struct zx_ac_MobileNetworkEndToEndEncryption_s*)y->gg.g.n) ;
    if (!y->gg.g.n) return;
  }
  y->gg.g.n = y->gg.g.n->n;
}

#endif



#ifdef ZX_ENA_GETPUT

/* FUNC(zx_ac_AuthenticatorTransportProtocol_NUM_WTLS) */

int zx_ac_AuthenticatorTransportProtocol_NUM_WTLS(struct zx_ac_AuthenticatorTransportProtocol_s* x)
{
  struct zx_ac_WTLS_s* y;
  int n = 0;
  if (!x) return 0;
  for (y = x->WTLS; y; ++n, y = (struct zx_ac_WTLS_s*)y->gg.g.n) ;
  return n;
}

/* FUNC(zx_ac_AuthenticatorTransportProtocol_GET_WTLS) */

struct zx_ac_WTLS_s* zx_ac_AuthenticatorTransportProtocol_GET_WTLS(struct zx_ac_AuthenticatorTransportProtocol_s* x, int n)
{
  struct zx_ac_WTLS_s* y;
  if (!x) return 0;
  for (y = x->WTLS; n>=0 && y; --n, y = (struct zx_ac_WTLS_s*)y->gg.g.n) ;
  return y;
}

/* FUNC(zx_ac_AuthenticatorTransportProtocol_POP_WTLS) */

struct zx_ac_WTLS_s* zx_ac_AuthenticatorTransportProtocol_POP_WTLS(struct zx_ac_AuthenticatorTransportProtocol_s* x)
{
  struct zx_ac_WTLS_s* y;
  if (!x) return 0;
  y = x->WTLS;
  if (y)
    x->WTLS = (struct zx_ac_WTLS_s*)y->gg.g.n;
  return y;
}

/* FUNC(zx_ac_AuthenticatorTransportProtocol_PUSH_WTLS) */

void zx_ac_AuthenticatorTransportProtocol_PUSH_WTLS(struct zx_ac_AuthenticatorTransportProtocol_s* x, struct zx_ac_WTLS_s* z)
{
  if (!x || !z) return;
  z->gg.g.n = &x->WTLS->gg.g;
  x->WTLS = z;
}

/* FUNC(zx_ac_AuthenticatorTransportProtocol_REV_WTLS) */

void zx_ac_AuthenticatorTransportProtocol_REV_WTLS(struct zx_ac_AuthenticatorTransportProtocol_s* x)
{
  struct zx_ac_WTLS_s* nxt;
  struct zx_ac_WTLS_s* y;
  if (!x) return;
  y = x->WTLS;
  if (!y) return;
  x->WTLS = 0;
  while (y) {
    nxt = (struct zx_ac_WTLS_s*)y->gg.g.n;
    y->gg.g.n = &x->WTLS->gg.g;
    x->WTLS = y;
    y = nxt;
  }
}

/* FUNC(zx_ac_AuthenticatorTransportProtocol_PUT_WTLS) */

void zx_ac_AuthenticatorTransportProtocol_PUT_WTLS(struct zx_ac_AuthenticatorTransportProtocol_s* x, int n, struct zx_ac_WTLS_s* z)
{
  struct zx_ac_WTLS_s* y;
  if (!x || !z) return;
  y = x->WTLS;
  if (!y) return;
  switch (n) {
  case 0:
    z->gg.g.n = y->gg.g.n;
    x->WTLS = z;
    return;
  default:
    for (; n > 1 && y->gg.g.n; --n, y = (struct zx_ac_WTLS_s*)y->gg.g.n) ;
    if (!y->gg.g.n) return;
    z->gg.g.n = y->gg.g.n->n;
    y->gg.g.n = &z->gg.g;
  }
}

/* FUNC(zx_ac_AuthenticatorTransportProtocol_ADD_WTLS) */

void zx_ac_AuthenticatorTransportProtocol_ADD_WTLS(struct zx_ac_AuthenticatorTransportProtocol_s* x, int n, struct zx_ac_WTLS_s* z)
{
  struct zx_ac_WTLS_s* y;
  if (!x || !z) return;
  switch (n) {
  case 0:
  add_to_start:
    z->gg.g.n = &x->WTLS->gg.g;
    x->WTLS = z;
    return;
  case -1:
    y = x->WTLS;
    if (!y) goto add_to_start;
    for (; y->gg.g.n; y = (struct zx_ac_WTLS_s*)y->gg.g.n) ;
    break;
  default:
    for (y = x->WTLS; n > 1 && y; --n, y = (struct zx_ac_WTLS_s*)y->gg.g.n) ;
    if (!y) return;
  }
  z->gg.g.n = y->gg.g.n;
  y->gg.g.n = &z->gg.g;
}

/* FUNC(zx_ac_AuthenticatorTransportProtocol_DEL_WTLS) */

void zx_ac_AuthenticatorTransportProtocol_DEL_WTLS(struct zx_ac_AuthenticatorTransportProtocol_s* x, int n)
{
  struct zx_ac_WTLS_s* y;
  if (!x) return;
  switch (n) {
  case 0:
    x->WTLS = (struct zx_ac_WTLS_s*)x->WTLS->gg.g.n;
    return;
  case -1:
    y = (struct zx_ac_WTLS_s*)x->WTLS;
    if (!y) return;
    for (; y->gg.g.n; y = (struct zx_ac_WTLS_s*)y->gg.g.n) ;
    break;
  default:
    for (y = x->WTLS; n > 1 && y->gg.g.n; --n, y = (struct zx_ac_WTLS_s*)y->gg.g.n) ;
    if (!y->gg.g.n) return;
  }
  y->gg.g.n = y->gg.g.n->n;
}

#endif



#ifdef ZX_ENA_GETPUT

/* FUNC(zx_ac_AuthenticatorTransportProtocol_NUM_IPSec) */

int zx_ac_AuthenticatorTransportProtocol_NUM_IPSec(struct zx_ac_AuthenticatorTransportProtocol_s* x)
{
  struct zx_ac_IPSec_s* y;
  int n = 0;
  if (!x) return 0;
  for (y = x->IPSec; y; ++n, y = (struct zx_ac_IPSec_s*)y->gg.g.n) ;
  return n;
}

/* FUNC(zx_ac_AuthenticatorTransportProtocol_GET_IPSec) */

struct zx_ac_IPSec_s* zx_ac_AuthenticatorTransportProtocol_GET_IPSec(struct zx_ac_AuthenticatorTransportProtocol_s* x, int n)
{
  struct zx_ac_IPSec_s* y;
  if (!x) return 0;
  for (y = x->IPSec; n>=0 && y; --n, y = (struct zx_ac_IPSec_s*)y->gg.g.n) ;
  return y;
}

/* FUNC(zx_ac_AuthenticatorTransportProtocol_POP_IPSec) */

struct zx_ac_IPSec_s* zx_ac_AuthenticatorTransportProtocol_POP_IPSec(struct zx_ac_AuthenticatorTransportProtocol_s* x)
{
  struct zx_ac_IPSec_s* y;
  if (!x) return 0;
  y = x->IPSec;
  if (y)
    x->IPSec = (struct zx_ac_IPSec_s*)y->gg.g.n;
  return y;
}

/* FUNC(zx_ac_AuthenticatorTransportProtocol_PUSH_IPSec) */

void zx_ac_AuthenticatorTransportProtocol_PUSH_IPSec(struct zx_ac_AuthenticatorTransportProtocol_s* x, struct zx_ac_IPSec_s* z)
{
  if (!x || !z) return;
  z->gg.g.n = &x->IPSec->gg.g;
  x->IPSec = z;
}

/* FUNC(zx_ac_AuthenticatorTransportProtocol_REV_IPSec) */

void zx_ac_AuthenticatorTransportProtocol_REV_IPSec(struct zx_ac_AuthenticatorTransportProtocol_s* x)
{
  struct zx_ac_IPSec_s* nxt;
  struct zx_ac_IPSec_s* y;
  if (!x) return;
  y = x->IPSec;
  if (!y) return;
  x->IPSec = 0;
  while (y) {
    nxt = (struct zx_ac_IPSec_s*)y->gg.g.n;
    y->gg.g.n = &x->IPSec->gg.g;
    x->IPSec = y;
    y = nxt;
  }
}

/* FUNC(zx_ac_AuthenticatorTransportProtocol_PUT_IPSec) */

void zx_ac_AuthenticatorTransportProtocol_PUT_IPSec(struct zx_ac_AuthenticatorTransportProtocol_s* x, int n, struct zx_ac_IPSec_s* z)
{
  struct zx_ac_IPSec_s* y;
  if (!x || !z) return;
  y = x->IPSec;
  if (!y) return;
  switch (n) {
  case 0:
    z->gg.g.n = y->gg.g.n;
    x->IPSec = z;
    return;
  default:
    for (; n > 1 && y->gg.g.n; --n, y = (struct zx_ac_IPSec_s*)y->gg.g.n) ;
    if (!y->gg.g.n) return;
    z->gg.g.n = y->gg.g.n->n;
    y->gg.g.n = &z->gg.g;
  }
}

/* FUNC(zx_ac_AuthenticatorTransportProtocol_ADD_IPSec) */

void zx_ac_AuthenticatorTransportProtocol_ADD_IPSec(struct zx_ac_AuthenticatorTransportProtocol_s* x, int n, struct zx_ac_IPSec_s* z)
{
  struct zx_ac_IPSec_s* y;
  if (!x || !z) return;
  switch (n) {
  case 0:
  add_to_start:
    z->gg.g.n = &x->IPSec->gg.g;
    x->IPSec = z;
    return;
  case -1:
    y = x->IPSec;
    if (!y) goto add_to_start;
    for (; y->gg.g.n; y = (struct zx_ac_IPSec_s*)y->gg.g.n) ;
    break;
  default:
    for (y = x->IPSec; n > 1 && y; --n, y = (struct zx_ac_IPSec_s*)y->gg.g.n) ;
    if (!y) return;
  }
  z->gg.g.n = y->gg.g.n;
  y->gg.g.n = &z->gg.g;
}

/* FUNC(zx_ac_AuthenticatorTransportProtocol_DEL_IPSec) */

void zx_ac_AuthenticatorTransportProtocol_DEL_IPSec(struct zx_ac_AuthenticatorTransportProtocol_s* x, int n)
{
  struct zx_ac_IPSec_s* y;
  if (!x) return;
  switch (n) {
  case 0:
    x->IPSec = (struct zx_ac_IPSec_s*)x->IPSec->gg.g.n;
    return;
  case -1:
    y = (struct zx_ac_IPSec_s*)x->IPSec;
    if (!y) return;
    for (; y->gg.g.n; y = (struct zx_ac_IPSec_s*)y->gg.g.n) ;
    break;
  default:
    for (y = x->IPSec; n > 1 && y->gg.g.n; --n, y = (struct zx_ac_IPSec_s*)y->gg.g.n) ;
    if (!y->gg.g.n) return;
  }
  y->gg.g.n = y->gg.g.n->n;
}

#endif



#ifdef ZX_ENA_GETPUT

/* FUNC(zx_ac_AuthenticatorTransportProtocol_NUM_Extension) */

int zx_ac_AuthenticatorTransportProtocol_NUM_Extension(struct zx_ac_AuthenticatorTransportProtocol_s* x)
{
  struct zx_ac_Extension_s* y;
  int n = 0;
  if (!x) return 0;
  for (y = x->Extension; y; ++n, y = (struct zx_ac_Extension_s*)y->gg.g.n) ;
  return n;
}

/* FUNC(zx_ac_AuthenticatorTransportProtocol_GET_Extension) */

struct zx_ac_Extension_s* zx_ac_AuthenticatorTransportProtocol_GET_Extension(struct zx_ac_AuthenticatorTransportProtocol_s* x, int n)
{
  struct zx_ac_Extension_s* y;
  if (!x) return 0;
  for (y = x->Extension; n>=0 && y; --n, y = (struct zx_ac_Extension_s*)y->gg.g.n) ;
  return y;
}

/* FUNC(zx_ac_AuthenticatorTransportProtocol_POP_Extension) */

struct zx_ac_Extension_s* zx_ac_AuthenticatorTransportProtocol_POP_Extension(struct zx_ac_AuthenticatorTransportProtocol_s* x)
{
  struct zx_ac_Extension_s* y;
  if (!x) return 0;
  y = x->Extension;
  if (y)
    x->Extension = (struct zx_ac_Extension_s*)y->gg.g.n;
  return y;
}

/* FUNC(zx_ac_AuthenticatorTransportProtocol_PUSH_Extension) */

void zx_ac_AuthenticatorTransportProtocol_PUSH_Extension(struct zx_ac_AuthenticatorTransportProtocol_s* x, struct zx_ac_Extension_s* z)
{
  if (!x || !z) return;
  z->gg.g.n = &x->Extension->gg.g;
  x->Extension = z;
}

/* FUNC(zx_ac_AuthenticatorTransportProtocol_REV_Extension) */

void zx_ac_AuthenticatorTransportProtocol_REV_Extension(struct zx_ac_AuthenticatorTransportProtocol_s* x)
{
  struct zx_ac_Extension_s* nxt;
  struct zx_ac_Extension_s* y;
  if (!x) return;
  y = x->Extension;
  if (!y) return;
  x->Extension = 0;
  while (y) {
    nxt = (struct zx_ac_Extension_s*)y->gg.g.n;
    y->gg.g.n = &x->Extension->gg.g;
    x->Extension = y;
    y = nxt;
  }
}

/* FUNC(zx_ac_AuthenticatorTransportProtocol_PUT_Extension) */

void zx_ac_AuthenticatorTransportProtocol_PUT_Extension(struct zx_ac_AuthenticatorTransportProtocol_s* x, int n, struct zx_ac_Extension_s* z)
{
  struct zx_ac_Extension_s* y;
  if (!x || !z) return;
  y = x->Extension;
  if (!y) return;
  switch (n) {
  case 0:
    z->gg.g.n = y->gg.g.n;
    x->Extension = z;
    return;
  default:
    for (; n > 1 && y->gg.g.n; --n, y = (struct zx_ac_Extension_s*)y->gg.g.n) ;
    if (!y->gg.g.n) return;
    z->gg.g.n = y->gg.g.n->n;
    y->gg.g.n = &z->gg.g;
  }
}

/* FUNC(zx_ac_AuthenticatorTransportProtocol_ADD_Extension) */

void zx_ac_AuthenticatorTransportProtocol_ADD_Extension(struct zx_ac_AuthenticatorTransportProtocol_s* x, int n, struct zx_ac_Extension_s* z)
{
  struct zx_ac_Extension_s* y;
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
    for (; y->gg.g.n; y = (struct zx_ac_Extension_s*)y->gg.g.n) ;
    break;
  default:
    for (y = x->Extension; n > 1 && y; --n, y = (struct zx_ac_Extension_s*)y->gg.g.n) ;
    if (!y) return;
  }
  z->gg.g.n = y->gg.g.n;
  y->gg.g.n = &z->gg.g;
}

/* FUNC(zx_ac_AuthenticatorTransportProtocol_DEL_Extension) */

void zx_ac_AuthenticatorTransportProtocol_DEL_Extension(struct zx_ac_AuthenticatorTransportProtocol_s* x, int n)
{
  struct zx_ac_Extension_s* y;
  if (!x) return;
  switch (n) {
  case 0:
    x->Extension = (struct zx_ac_Extension_s*)x->Extension->gg.g.n;
    return;
  case -1:
    y = (struct zx_ac_Extension_s*)x->Extension;
    if (!y) return;
    for (; y->gg.g.n; y = (struct zx_ac_Extension_s*)y->gg.g.n) ;
    break;
  default:
    for (y = x->Extension; n > 1 && y->gg.g.n; --n, y = (struct zx_ac_Extension_s*)y->gg.g.n) ;
    if (!y->gg.g.n) return;
  }
  y->gg.g.n = y->gg.g.n->n;
}

#endif








#ifdef ZX_ENA_GETPUT

/* FUNC(zx_ac_DeactivationCallCenter_NUM_Extension) */

int zx_ac_DeactivationCallCenter_NUM_Extension(struct zx_ac_DeactivationCallCenter_s* x)
{
  struct zx_ac_Extension_s* y;
  int n = 0;
  if (!x) return 0;
  for (y = x->Extension; y; ++n, y = (struct zx_ac_Extension_s*)y->gg.g.n) ;
  return n;
}

/* FUNC(zx_ac_DeactivationCallCenter_GET_Extension) */

struct zx_ac_Extension_s* zx_ac_DeactivationCallCenter_GET_Extension(struct zx_ac_DeactivationCallCenter_s* x, int n)
{
  struct zx_ac_Extension_s* y;
  if (!x) return 0;
  for (y = x->Extension; n>=0 && y; --n, y = (struct zx_ac_Extension_s*)y->gg.g.n) ;
  return y;
}

/* FUNC(zx_ac_DeactivationCallCenter_POP_Extension) */

struct zx_ac_Extension_s* zx_ac_DeactivationCallCenter_POP_Extension(struct zx_ac_DeactivationCallCenter_s* x)
{
  struct zx_ac_Extension_s* y;
  if (!x) return 0;
  y = x->Extension;
  if (y)
    x->Extension = (struct zx_ac_Extension_s*)y->gg.g.n;
  return y;
}

/* FUNC(zx_ac_DeactivationCallCenter_PUSH_Extension) */

void zx_ac_DeactivationCallCenter_PUSH_Extension(struct zx_ac_DeactivationCallCenter_s* x, struct zx_ac_Extension_s* z)
{
  if (!x || !z) return;
  z->gg.g.n = &x->Extension->gg.g;
  x->Extension = z;
}

/* FUNC(zx_ac_DeactivationCallCenter_REV_Extension) */

void zx_ac_DeactivationCallCenter_REV_Extension(struct zx_ac_DeactivationCallCenter_s* x)
{
  struct zx_ac_Extension_s* nxt;
  struct zx_ac_Extension_s* y;
  if (!x) return;
  y = x->Extension;
  if (!y) return;
  x->Extension = 0;
  while (y) {
    nxt = (struct zx_ac_Extension_s*)y->gg.g.n;
    y->gg.g.n = &x->Extension->gg.g;
    x->Extension = y;
    y = nxt;
  }
}

/* FUNC(zx_ac_DeactivationCallCenter_PUT_Extension) */

void zx_ac_DeactivationCallCenter_PUT_Extension(struct zx_ac_DeactivationCallCenter_s* x, int n, struct zx_ac_Extension_s* z)
{
  struct zx_ac_Extension_s* y;
  if (!x || !z) return;
  y = x->Extension;
  if (!y) return;
  switch (n) {
  case 0:
    z->gg.g.n = y->gg.g.n;
    x->Extension = z;
    return;
  default:
    for (; n > 1 && y->gg.g.n; --n, y = (struct zx_ac_Extension_s*)y->gg.g.n) ;
    if (!y->gg.g.n) return;
    z->gg.g.n = y->gg.g.n->n;
    y->gg.g.n = &z->gg.g;
  }
}

/* FUNC(zx_ac_DeactivationCallCenter_ADD_Extension) */

void zx_ac_DeactivationCallCenter_ADD_Extension(struct zx_ac_DeactivationCallCenter_s* x, int n, struct zx_ac_Extension_s* z)
{
  struct zx_ac_Extension_s* y;
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
    for (; y->gg.g.n; y = (struct zx_ac_Extension_s*)y->gg.g.n) ;
    break;
  default:
    for (y = x->Extension; n > 1 && y; --n, y = (struct zx_ac_Extension_s*)y->gg.g.n) ;
    if (!y) return;
  }
  z->gg.g.n = y->gg.g.n;
  y->gg.g.n = &z->gg.g;
}

/* FUNC(zx_ac_DeactivationCallCenter_DEL_Extension) */

void zx_ac_DeactivationCallCenter_DEL_Extension(struct zx_ac_DeactivationCallCenter_s* x, int n)
{
  struct zx_ac_Extension_s* y;
  if (!x) return;
  switch (n) {
  case 0:
    x->Extension = (struct zx_ac_Extension_s*)x->Extension->gg.g.n;
    return;
  case -1:
    y = (struct zx_ac_Extension_s*)x->Extension;
    if (!y) return;
    for (; y->gg.g.n; y = (struct zx_ac_Extension_s*)y->gg.g.n) ;
    break;
  default:
    for (y = x->Extension; n > 1 && y->gg.g.n; --n, y = (struct zx_ac_Extension_s*)y->gg.g.n) ;
    if (!y->gg.g.n) return;
  }
  y->gg.g.n = y->gg.g.n->n;
}

#endif








#ifdef ZX_ENA_GETPUT

/* FUNC(zx_ac_DigSig_NUM_Extension) */

int zx_ac_DigSig_NUM_Extension(struct zx_ac_DigSig_s* x)
{
  struct zx_ac_Extension_s* y;
  int n = 0;
  if (!x) return 0;
  for (y = x->Extension; y; ++n, y = (struct zx_ac_Extension_s*)y->gg.g.n) ;
  return n;
}

/* FUNC(zx_ac_DigSig_GET_Extension) */

struct zx_ac_Extension_s* zx_ac_DigSig_GET_Extension(struct zx_ac_DigSig_s* x, int n)
{
  struct zx_ac_Extension_s* y;
  if (!x) return 0;
  for (y = x->Extension; n>=0 && y; --n, y = (struct zx_ac_Extension_s*)y->gg.g.n) ;
  return y;
}

/* FUNC(zx_ac_DigSig_POP_Extension) */

struct zx_ac_Extension_s* zx_ac_DigSig_POP_Extension(struct zx_ac_DigSig_s* x)
{
  struct zx_ac_Extension_s* y;
  if (!x) return 0;
  y = x->Extension;
  if (y)
    x->Extension = (struct zx_ac_Extension_s*)y->gg.g.n;
  return y;
}

/* FUNC(zx_ac_DigSig_PUSH_Extension) */

void zx_ac_DigSig_PUSH_Extension(struct zx_ac_DigSig_s* x, struct zx_ac_Extension_s* z)
{
  if (!x || !z) return;
  z->gg.g.n = &x->Extension->gg.g;
  x->Extension = z;
}

/* FUNC(zx_ac_DigSig_REV_Extension) */

void zx_ac_DigSig_REV_Extension(struct zx_ac_DigSig_s* x)
{
  struct zx_ac_Extension_s* nxt;
  struct zx_ac_Extension_s* y;
  if (!x) return;
  y = x->Extension;
  if (!y) return;
  x->Extension = 0;
  while (y) {
    nxt = (struct zx_ac_Extension_s*)y->gg.g.n;
    y->gg.g.n = &x->Extension->gg.g;
    x->Extension = y;
    y = nxt;
  }
}

/* FUNC(zx_ac_DigSig_PUT_Extension) */

void zx_ac_DigSig_PUT_Extension(struct zx_ac_DigSig_s* x, int n, struct zx_ac_Extension_s* z)
{
  struct zx_ac_Extension_s* y;
  if (!x || !z) return;
  y = x->Extension;
  if (!y) return;
  switch (n) {
  case 0:
    z->gg.g.n = y->gg.g.n;
    x->Extension = z;
    return;
  default:
    for (; n > 1 && y->gg.g.n; --n, y = (struct zx_ac_Extension_s*)y->gg.g.n) ;
    if (!y->gg.g.n) return;
    z->gg.g.n = y->gg.g.n->n;
    y->gg.g.n = &z->gg.g;
  }
}

/* FUNC(zx_ac_DigSig_ADD_Extension) */

void zx_ac_DigSig_ADD_Extension(struct zx_ac_DigSig_s* x, int n, struct zx_ac_Extension_s* z)
{
  struct zx_ac_Extension_s* y;
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
    for (; y->gg.g.n; y = (struct zx_ac_Extension_s*)y->gg.g.n) ;
    break;
  default:
    for (y = x->Extension; n > 1 && y; --n, y = (struct zx_ac_Extension_s*)y->gg.g.n) ;
    if (!y) return;
  }
  z->gg.g.n = y->gg.g.n;
  y->gg.g.n = &z->gg.g;
}

/* FUNC(zx_ac_DigSig_DEL_Extension) */

void zx_ac_DigSig_DEL_Extension(struct zx_ac_DigSig_s* x, int n)
{
  struct zx_ac_Extension_s* y;
  if (!x) return;
  switch (n) {
  case 0:
    x->Extension = (struct zx_ac_Extension_s*)x->Extension->gg.g.n;
    return;
  case -1:
    y = (struct zx_ac_Extension_s*)x->Extension;
    if (!y) return;
    for (; y->gg.g.n; y = (struct zx_ac_Extension_s*)y->gg.g.n) ;
    break;
  default:
    for (y = x->Extension; n > 1 && y->gg.g.n; --n, y = (struct zx_ac_Extension_s*)y->gg.g.n) ;
    if (!y->gg.g.n) return;
  }
  y->gg.g.n = y->gg.g.n->n;
}

#endif











/* FUNC(zx_ac_Generation_GET_mechanism) */
struct zx_str* zx_ac_Generation_GET_mechanism(struct zx_ac_Generation_s* x) { return x->mechanism; }
/* FUNC(zx_ac_Generation_PUT_mechanism) */
void zx_ac_Generation_PUT_mechanism(struct zx_ac_Generation_s* x, struct zx_str* y) { x->mechanism = y; }





/* FUNC(zx_ac_GoverningAgreementRef_GET_governingAgreementRef) */
struct zx_str* zx_ac_GoverningAgreementRef_GET_governingAgreementRef(struct zx_ac_GoverningAgreementRef_s* x) { return x->governingAgreementRef; }
/* FUNC(zx_ac_GoverningAgreementRef_PUT_governingAgreementRef) */
void zx_ac_GoverningAgreementRef_PUT_governingAgreementRef(struct zx_ac_GoverningAgreementRef_s* x, struct zx_str* y) { x->governingAgreementRef = y; }







#ifdef ZX_ENA_GETPUT

/* FUNC(zx_ac_GoverningAgreements_NUM_GoverningAgreementRef) */

int zx_ac_GoverningAgreements_NUM_GoverningAgreementRef(struct zx_ac_GoverningAgreements_s* x)
{
  struct zx_ac_GoverningAgreementRef_s* y;
  int n = 0;
  if (!x) return 0;
  for (y = x->GoverningAgreementRef; y; ++n, y = (struct zx_ac_GoverningAgreementRef_s*)y->gg.g.n) ;
  return n;
}

/* FUNC(zx_ac_GoverningAgreements_GET_GoverningAgreementRef) */

struct zx_ac_GoverningAgreementRef_s* zx_ac_GoverningAgreements_GET_GoverningAgreementRef(struct zx_ac_GoverningAgreements_s* x, int n)
{
  struct zx_ac_GoverningAgreementRef_s* y;
  if (!x) return 0;
  for (y = x->GoverningAgreementRef; n>=0 && y; --n, y = (struct zx_ac_GoverningAgreementRef_s*)y->gg.g.n) ;
  return y;
}

/* FUNC(zx_ac_GoverningAgreements_POP_GoverningAgreementRef) */

struct zx_ac_GoverningAgreementRef_s* zx_ac_GoverningAgreements_POP_GoverningAgreementRef(struct zx_ac_GoverningAgreements_s* x)
{
  struct zx_ac_GoverningAgreementRef_s* y;
  if (!x) return 0;
  y = x->GoverningAgreementRef;
  if (y)
    x->GoverningAgreementRef = (struct zx_ac_GoverningAgreementRef_s*)y->gg.g.n;
  return y;
}

/* FUNC(zx_ac_GoverningAgreements_PUSH_GoverningAgreementRef) */

void zx_ac_GoverningAgreements_PUSH_GoverningAgreementRef(struct zx_ac_GoverningAgreements_s* x, struct zx_ac_GoverningAgreementRef_s* z)
{
  if (!x || !z) return;
  z->gg.g.n = &x->GoverningAgreementRef->gg.g;
  x->GoverningAgreementRef = z;
}

/* FUNC(zx_ac_GoverningAgreements_REV_GoverningAgreementRef) */

void zx_ac_GoverningAgreements_REV_GoverningAgreementRef(struct zx_ac_GoverningAgreements_s* x)
{
  struct zx_ac_GoverningAgreementRef_s* nxt;
  struct zx_ac_GoverningAgreementRef_s* y;
  if (!x) return;
  y = x->GoverningAgreementRef;
  if (!y) return;
  x->GoverningAgreementRef = 0;
  while (y) {
    nxt = (struct zx_ac_GoverningAgreementRef_s*)y->gg.g.n;
    y->gg.g.n = &x->GoverningAgreementRef->gg.g;
    x->GoverningAgreementRef = y;
    y = nxt;
  }
}

/* FUNC(zx_ac_GoverningAgreements_PUT_GoverningAgreementRef) */

void zx_ac_GoverningAgreements_PUT_GoverningAgreementRef(struct zx_ac_GoverningAgreements_s* x, int n, struct zx_ac_GoverningAgreementRef_s* z)
{
  struct zx_ac_GoverningAgreementRef_s* y;
  if (!x || !z) return;
  y = x->GoverningAgreementRef;
  if (!y) return;
  switch (n) {
  case 0:
    z->gg.g.n = y->gg.g.n;
    x->GoverningAgreementRef = z;
    return;
  default:
    for (; n > 1 && y->gg.g.n; --n, y = (struct zx_ac_GoverningAgreementRef_s*)y->gg.g.n) ;
    if (!y->gg.g.n) return;
    z->gg.g.n = y->gg.g.n->n;
    y->gg.g.n = &z->gg.g;
  }
}

/* FUNC(zx_ac_GoverningAgreements_ADD_GoverningAgreementRef) */

void zx_ac_GoverningAgreements_ADD_GoverningAgreementRef(struct zx_ac_GoverningAgreements_s* x, int n, struct zx_ac_GoverningAgreementRef_s* z)
{
  struct zx_ac_GoverningAgreementRef_s* y;
  if (!x || !z) return;
  switch (n) {
  case 0:
  add_to_start:
    z->gg.g.n = &x->GoverningAgreementRef->gg.g;
    x->GoverningAgreementRef = z;
    return;
  case -1:
    y = x->GoverningAgreementRef;
    if (!y) goto add_to_start;
    for (; y->gg.g.n; y = (struct zx_ac_GoverningAgreementRef_s*)y->gg.g.n) ;
    break;
  default:
    for (y = x->GoverningAgreementRef; n > 1 && y; --n, y = (struct zx_ac_GoverningAgreementRef_s*)y->gg.g.n) ;
    if (!y) return;
  }
  z->gg.g.n = y->gg.g.n;
  y->gg.g.n = &z->gg.g;
}

/* FUNC(zx_ac_GoverningAgreements_DEL_GoverningAgreementRef) */

void zx_ac_GoverningAgreements_DEL_GoverningAgreementRef(struct zx_ac_GoverningAgreements_s* x, int n)
{
  struct zx_ac_GoverningAgreementRef_s* y;
  if (!x) return;
  switch (n) {
  case 0:
    x->GoverningAgreementRef = (struct zx_ac_GoverningAgreementRef_s*)x->GoverningAgreementRef->gg.g.n;
    return;
  case -1:
    y = (struct zx_ac_GoverningAgreementRef_s*)x->GoverningAgreementRef;
    if (!y) return;
    for (; y->gg.g.n; y = (struct zx_ac_GoverningAgreementRef_s*)y->gg.g.n) ;
    break;
  default:
    for (y = x->GoverningAgreementRef; n > 1 && y->gg.g.n; --n, y = (struct zx_ac_GoverningAgreementRef_s*)y->gg.g.n) ;
    if (!y->gg.g.n) return;
  }
  y->gg.g.n = y->gg.g.n->n;
}

#endif








#ifdef ZX_ENA_GETPUT

/* FUNC(zx_ac_HTTP_NUM_Extension) */

int zx_ac_HTTP_NUM_Extension(struct zx_ac_HTTP_s* x)
{
  struct zx_ac_Extension_s* y;
  int n = 0;
  if (!x) return 0;
  for (y = x->Extension; y; ++n, y = (struct zx_ac_Extension_s*)y->gg.g.n) ;
  return n;
}

/* FUNC(zx_ac_HTTP_GET_Extension) */

struct zx_ac_Extension_s* zx_ac_HTTP_GET_Extension(struct zx_ac_HTTP_s* x, int n)
{
  struct zx_ac_Extension_s* y;
  if (!x) return 0;
  for (y = x->Extension; n>=0 && y; --n, y = (struct zx_ac_Extension_s*)y->gg.g.n) ;
  return y;
}

/* FUNC(zx_ac_HTTP_POP_Extension) */

struct zx_ac_Extension_s* zx_ac_HTTP_POP_Extension(struct zx_ac_HTTP_s* x)
{
  struct zx_ac_Extension_s* y;
  if (!x) return 0;
  y = x->Extension;
  if (y)
    x->Extension = (struct zx_ac_Extension_s*)y->gg.g.n;
  return y;
}

/* FUNC(zx_ac_HTTP_PUSH_Extension) */

void zx_ac_HTTP_PUSH_Extension(struct zx_ac_HTTP_s* x, struct zx_ac_Extension_s* z)
{
  if (!x || !z) return;
  z->gg.g.n = &x->Extension->gg.g;
  x->Extension = z;
}

/* FUNC(zx_ac_HTTP_REV_Extension) */

void zx_ac_HTTP_REV_Extension(struct zx_ac_HTTP_s* x)
{
  struct zx_ac_Extension_s* nxt;
  struct zx_ac_Extension_s* y;
  if (!x) return;
  y = x->Extension;
  if (!y) return;
  x->Extension = 0;
  while (y) {
    nxt = (struct zx_ac_Extension_s*)y->gg.g.n;
    y->gg.g.n = &x->Extension->gg.g;
    x->Extension = y;
    y = nxt;
  }
}

/* FUNC(zx_ac_HTTP_PUT_Extension) */

void zx_ac_HTTP_PUT_Extension(struct zx_ac_HTTP_s* x, int n, struct zx_ac_Extension_s* z)
{
  struct zx_ac_Extension_s* y;
  if (!x || !z) return;
  y = x->Extension;
  if (!y) return;
  switch (n) {
  case 0:
    z->gg.g.n = y->gg.g.n;
    x->Extension = z;
    return;
  default:
    for (; n > 1 && y->gg.g.n; --n, y = (struct zx_ac_Extension_s*)y->gg.g.n) ;
    if (!y->gg.g.n) return;
    z->gg.g.n = y->gg.g.n->n;
    y->gg.g.n = &z->gg.g;
  }
}

/* FUNC(zx_ac_HTTP_ADD_Extension) */

void zx_ac_HTTP_ADD_Extension(struct zx_ac_HTTP_s* x, int n, struct zx_ac_Extension_s* z)
{
  struct zx_ac_Extension_s* y;
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
    for (; y->gg.g.n; y = (struct zx_ac_Extension_s*)y->gg.g.n) ;
    break;
  default:
    for (y = x->Extension; n > 1 && y; --n, y = (struct zx_ac_Extension_s*)y->gg.g.n) ;
    if (!y) return;
  }
  z->gg.g.n = y->gg.g.n;
  y->gg.g.n = &z->gg.g;
}

/* FUNC(zx_ac_HTTP_DEL_Extension) */

void zx_ac_HTTP_DEL_Extension(struct zx_ac_HTTP_s* x, int n)
{
  struct zx_ac_Extension_s* y;
  if (!x) return;
  switch (n) {
  case 0:
    x->Extension = (struct zx_ac_Extension_s*)x->Extension->gg.g.n;
    return;
  case -1:
    y = (struct zx_ac_Extension_s*)x->Extension;
    if (!y) return;
    for (; y->gg.g.n; y = (struct zx_ac_Extension_s*)y->gg.g.n) ;
    break;
  default:
    for (y = x->Extension; n > 1 && y->gg.g.n; --n, y = (struct zx_ac_Extension_s*)y->gg.g.n) ;
    if (!y->gg.g.n) return;
  }
  y->gg.g.n = y->gg.g.n->n;
}

#endif








#ifdef ZX_ENA_GETPUT

/* FUNC(zx_ac_IPAddress_NUM_Extension) */

int zx_ac_IPAddress_NUM_Extension(struct zx_ac_IPAddress_s* x)
{
  struct zx_ac_Extension_s* y;
  int n = 0;
  if (!x) return 0;
  for (y = x->Extension; y; ++n, y = (struct zx_ac_Extension_s*)y->gg.g.n) ;
  return n;
}

/* FUNC(zx_ac_IPAddress_GET_Extension) */

struct zx_ac_Extension_s* zx_ac_IPAddress_GET_Extension(struct zx_ac_IPAddress_s* x, int n)
{
  struct zx_ac_Extension_s* y;
  if (!x) return 0;
  for (y = x->Extension; n>=0 && y; --n, y = (struct zx_ac_Extension_s*)y->gg.g.n) ;
  return y;
}

/* FUNC(zx_ac_IPAddress_POP_Extension) */

struct zx_ac_Extension_s* zx_ac_IPAddress_POP_Extension(struct zx_ac_IPAddress_s* x)
{
  struct zx_ac_Extension_s* y;
  if (!x) return 0;
  y = x->Extension;
  if (y)
    x->Extension = (struct zx_ac_Extension_s*)y->gg.g.n;
  return y;
}

/* FUNC(zx_ac_IPAddress_PUSH_Extension) */

void zx_ac_IPAddress_PUSH_Extension(struct zx_ac_IPAddress_s* x, struct zx_ac_Extension_s* z)
{
  if (!x || !z) return;
  z->gg.g.n = &x->Extension->gg.g;
  x->Extension = z;
}

/* FUNC(zx_ac_IPAddress_REV_Extension) */

void zx_ac_IPAddress_REV_Extension(struct zx_ac_IPAddress_s* x)
{
  struct zx_ac_Extension_s* nxt;
  struct zx_ac_Extension_s* y;
  if (!x) return;
  y = x->Extension;
  if (!y) return;
  x->Extension = 0;
  while (y) {
    nxt = (struct zx_ac_Extension_s*)y->gg.g.n;
    y->gg.g.n = &x->Extension->gg.g;
    x->Extension = y;
    y = nxt;
  }
}

/* FUNC(zx_ac_IPAddress_PUT_Extension) */

void zx_ac_IPAddress_PUT_Extension(struct zx_ac_IPAddress_s* x, int n, struct zx_ac_Extension_s* z)
{
  struct zx_ac_Extension_s* y;
  if (!x || !z) return;
  y = x->Extension;
  if (!y) return;
  switch (n) {
  case 0:
    z->gg.g.n = y->gg.g.n;
    x->Extension = z;
    return;
  default:
    for (; n > 1 && y->gg.g.n; --n, y = (struct zx_ac_Extension_s*)y->gg.g.n) ;
    if (!y->gg.g.n) return;
    z->gg.g.n = y->gg.g.n->n;
    y->gg.g.n = &z->gg.g;
  }
}

/* FUNC(zx_ac_IPAddress_ADD_Extension) */

void zx_ac_IPAddress_ADD_Extension(struct zx_ac_IPAddress_s* x, int n, struct zx_ac_Extension_s* z)
{
  struct zx_ac_Extension_s* y;
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
    for (; y->gg.g.n; y = (struct zx_ac_Extension_s*)y->gg.g.n) ;
    break;
  default:
    for (y = x->Extension; n > 1 && y; --n, y = (struct zx_ac_Extension_s*)y->gg.g.n) ;
    if (!y) return;
  }
  z->gg.g.n = y->gg.g.n;
  y->gg.g.n = &z->gg.g;
}

/* FUNC(zx_ac_IPAddress_DEL_Extension) */

void zx_ac_IPAddress_DEL_Extension(struct zx_ac_IPAddress_s* x, int n)
{
  struct zx_ac_Extension_s* y;
  if (!x) return;
  switch (n) {
  case 0:
    x->Extension = (struct zx_ac_Extension_s*)x->Extension->gg.g.n;
    return;
  case -1:
    y = (struct zx_ac_Extension_s*)x->Extension;
    if (!y) return;
    for (; y->gg.g.n; y = (struct zx_ac_Extension_s*)y->gg.g.n) ;
    break;
  default:
    for (y = x->Extension; n > 1 && y->gg.g.n; --n, y = (struct zx_ac_Extension_s*)y->gg.g.n) ;
    if (!y->gg.g.n) return;
  }
  y->gg.g.n = y->gg.g.n->n;
}

#endif








#ifdef ZX_ENA_GETPUT

/* FUNC(zx_ac_IPSec_NUM_Extension) */

int zx_ac_IPSec_NUM_Extension(struct zx_ac_IPSec_s* x)
{
  struct zx_ac_Extension_s* y;
  int n = 0;
  if (!x) return 0;
  for (y = x->Extension; y; ++n, y = (struct zx_ac_Extension_s*)y->gg.g.n) ;
  return n;
}

/* FUNC(zx_ac_IPSec_GET_Extension) */

struct zx_ac_Extension_s* zx_ac_IPSec_GET_Extension(struct zx_ac_IPSec_s* x, int n)
{
  struct zx_ac_Extension_s* y;
  if (!x) return 0;
  for (y = x->Extension; n>=0 && y; --n, y = (struct zx_ac_Extension_s*)y->gg.g.n) ;
  return y;
}

/* FUNC(zx_ac_IPSec_POP_Extension) */

struct zx_ac_Extension_s* zx_ac_IPSec_POP_Extension(struct zx_ac_IPSec_s* x)
{
  struct zx_ac_Extension_s* y;
  if (!x) return 0;
  y = x->Extension;
  if (y)
    x->Extension = (struct zx_ac_Extension_s*)y->gg.g.n;
  return y;
}

/* FUNC(zx_ac_IPSec_PUSH_Extension) */

void zx_ac_IPSec_PUSH_Extension(struct zx_ac_IPSec_s* x, struct zx_ac_Extension_s* z)
{
  if (!x || !z) return;
  z->gg.g.n = &x->Extension->gg.g;
  x->Extension = z;
}

/* FUNC(zx_ac_IPSec_REV_Extension) */

void zx_ac_IPSec_REV_Extension(struct zx_ac_IPSec_s* x)
{
  struct zx_ac_Extension_s* nxt;
  struct zx_ac_Extension_s* y;
  if (!x) return;
  y = x->Extension;
  if (!y) return;
  x->Extension = 0;
  while (y) {
    nxt = (struct zx_ac_Extension_s*)y->gg.g.n;
    y->gg.g.n = &x->Extension->gg.g;
    x->Extension = y;
    y = nxt;
  }
}

/* FUNC(zx_ac_IPSec_PUT_Extension) */

void zx_ac_IPSec_PUT_Extension(struct zx_ac_IPSec_s* x, int n, struct zx_ac_Extension_s* z)
{
  struct zx_ac_Extension_s* y;
  if (!x || !z) return;
  y = x->Extension;
  if (!y) return;
  switch (n) {
  case 0:
    z->gg.g.n = y->gg.g.n;
    x->Extension = z;
    return;
  default:
    for (; n > 1 && y->gg.g.n; --n, y = (struct zx_ac_Extension_s*)y->gg.g.n) ;
    if (!y->gg.g.n) return;
    z->gg.g.n = y->gg.g.n->n;
    y->gg.g.n = &z->gg.g;
  }
}

/* FUNC(zx_ac_IPSec_ADD_Extension) */

void zx_ac_IPSec_ADD_Extension(struct zx_ac_IPSec_s* x, int n, struct zx_ac_Extension_s* z)
{
  struct zx_ac_Extension_s* y;
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
    for (; y->gg.g.n; y = (struct zx_ac_Extension_s*)y->gg.g.n) ;
    break;
  default:
    for (y = x->Extension; n > 1 && y; --n, y = (struct zx_ac_Extension_s*)y->gg.g.n) ;
    if (!y) return;
  }
  z->gg.g.n = y->gg.g.n;
  y->gg.g.n = &z->gg.g;
}

/* FUNC(zx_ac_IPSec_DEL_Extension) */

void zx_ac_IPSec_DEL_Extension(struct zx_ac_IPSec_s* x, int n)
{
  struct zx_ac_Extension_s* y;
  if (!x) return;
  switch (n) {
  case 0:
    x->Extension = (struct zx_ac_Extension_s*)x->Extension->gg.g.n;
    return;
  case -1:
    y = (struct zx_ac_Extension_s*)x->Extension;
    if (!y) return;
    for (; y->gg.g.n; y = (struct zx_ac_Extension_s*)y->gg.g.n) ;
    break;
  default:
    for (y = x->Extension; n > 1 && y->gg.g.n; --n, y = (struct zx_ac_Extension_s*)y->gg.g.n) ;
    if (!y->gg.g.n) return;
  }
  y->gg.g.n = y->gg.g.n->n;
}

#endif








#ifdef ZX_ENA_GETPUT

/* FUNC(zx_ac_Identification_NUM_PhysicalVerification) */

int zx_ac_Identification_NUM_PhysicalVerification(struct zx_ac_Identification_s* x)
{
  struct zx_ac_PhysicalVerification_s* y;
  int n = 0;
  if (!x) return 0;
  for (y = x->PhysicalVerification; y; ++n, y = (struct zx_ac_PhysicalVerification_s*)y->gg.g.n) ;
  return n;
}

/* FUNC(zx_ac_Identification_GET_PhysicalVerification) */

struct zx_ac_PhysicalVerification_s* zx_ac_Identification_GET_PhysicalVerification(struct zx_ac_Identification_s* x, int n)
{
  struct zx_ac_PhysicalVerification_s* y;
  if (!x) return 0;
  for (y = x->PhysicalVerification; n>=0 && y; --n, y = (struct zx_ac_PhysicalVerification_s*)y->gg.g.n) ;
  return y;
}

/* FUNC(zx_ac_Identification_POP_PhysicalVerification) */

struct zx_ac_PhysicalVerification_s* zx_ac_Identification_POP_PhysicalVerification(struct zx_ac_Identification_s* x)
{
  struct zx_ac_PhysicalVerification_s* y;
  if (!x) return 0;
  y = x->PhysicalVerification;
  if (y)
    x->PhysicalVerification = (struct zx_ac_PhysicalVerification_s*)y->gg.g.n;
  return y;
}

/* FUNC(zx_ac_Identification_PUSH_PhysicalVerification) */

void zx_ac_Identification_PUSH_PhysicalVerification(struct zx_ac_Identification_s* x, struct zx_ac_PhysicalVerification_s* z)
{
  if (!x || !z) return;
  z->gg.g.n = &x->PhysicalVerification->gg.g;
  x->PhysicalVerification = z;
}

/* FUNC(zx_ac_Identification_REV_PhysicalVerification) */

void zx_ac_Identification_REV_PhysicalVerification(struct zx_ac_Identification_s* x)
{
  struct zx_ac_PhysicalVerification_s* nxt;
  struct zx_ac_PhysicalVerification_s* y;
  if (!x) return;
  y = x->PhysicalVerification;
  if (!y) return;
  x->PhysicalVerification = 0;
  while (y) {
    nxt = (struct zx_ac_PhysicalVerification_s*)y->gg.g.n;
    y->gg.g.n = &x->PhysicalVerification->gg.g;
    x->PhysicalVerification = y;
    y = nxt;
  }
}

/* FUNC(zx_ac_Identification_PUT_PhysicalVerification) */

void zx_ac_Identification_PUT_PhysicalVerification(struct zx_ac_Identification_s* x, int n, struct zx_ac_PhysicalVerification_s* z)
{
  struct zx_ac_PhysicalVerification_s* y;
  if (!x || !z) return;
  y = x->PhysicalVerification;
  if (!y) return;
  switch (n) {
  case 0:
    z->gg.g.n = y->gg.g.n;
    x->PhysicalVerification = z;
    return;
  default:
    for (; n > 1 && y->gg.g.n; --n, y = (struct zx_ac_PhysicalVerification_s*)y->gg.g.n) ;
    if (!y->gg.g.n) return;
    z->gg.g.n = y->gg.g.n->n;
    y->gg.g.n = &z->gg.g;
  }
}

/* FUNC(zx_ac_Identification_ADD_PhysicalVerification) */

void zx_ac_Identification_ADD_PhysicalVerification(struct zx_ac_Identification_s* x, int n, struct zx_ac_PhysicalVerification_s* z)
{
  struct zx_ac_PhysicalVerification_s* y;
  if (!x || !z) return;
  switch (n) {
  case 0:
  add_to_start:
    z->gg.g.n = &x->PhysicalVerification->gg.g;
    x->PhysicalVerification = z;
    return;
  case -1:
    y = x->PhysicalVerification;
    if (!y) goto add_to_start;
    for (; y->gg.g.n; y = (struct zx_ac_PhysicalVerification_s*)y->gg.g.n) ;
    break;
  default:
    for (y = x->PhysicalVerification; n > 1 && y; --n, y = (struct zx_ac_PhysicalVerification_s*)y->gg.g.n) ;
    if (!y) return;
  }
  z->gg.g.n = y->gg.g.n;
  y->gg.g.n = &z->gg.g;
}

/* FUNC(zx_ac_Identification_DEL_PhysicalVerification) */

void zx_ac_Identification_DEL_PhysicalVerification(struct zx_ac_Identification_s* x, int n)
{
  struct zx_ac_PhysicalVerification_s* y;
  if (!x) return;
  switch (n) {
  case 0:
    x->PhysicalVerification = (struct zx_ac_PhysicalVerification_s*)x->PhysicalVerification->gg.g.n;
    return;
  case -1:
    y = (struct zx_ac_PhysicalVerification_s*)x->PhysicalVerification;
    if (!y) return;
    for (; y->gg.g.n; y = (struct zx_ac_PhysicalVerification_s*)y->gg.g.n) ;
    break;
  default:
    for (y = x->PhysicalVerification; n > 1 && y->gg.g.n; --n, y = (struct zx_ac_PhysicalVerification_s*)y->gg.g.n) ;
    if (!y->gg.g.n) return;
  }
  y->gg.g.n = y->gg.g.n->n;
}

#endif



#ifdef ZX_ENA_GETPUT

/* FUNC(zx_ac_Identification_NUM_WrittenConsent) */

int zx_ac_Identification_NUM_WrittenConsent(struct zx_ac_Identification_s* x)
{
  struct zx_ac_WrittenConsent_s* y;
  int n = 0;
  if (!x) return 0;
  for (y = x->WrittenConsent; y; ++n, y = (struct zx_ac_WrittenConsent_s*)y->gg.g.n) ;
  return n;
}

/* FUNC(zx_ac_Identification_GET_WrittenConsent) */

struct zx_ac_WrittenConsent_s* zx_ac_Identification_GET_WrittenConsent(struct zx_ac_Identification_s* x, int n)
{
  struct zx_ac_WrittenConsent_s* y;
  if (!x) return 0;
  for (y = x->WrittenConsent; n>=0 && y; --n, y = (struct zx_ac_WrittenConsent_s*)y->gg.g.n) ;
  return y;
}

/* FUNC(zx_ac_Identification_POP_WrittenConsent) */

struct zx_ac_WrittenConsent_s* zx_ac_Identification_POP_WrittenConsent(struct zx_ac_Identification_s* x)
{
  struct zx_ac_WrittenConsent_s* y;
  if (!x) return 0;
  y = x->WrittenConsent;
  if (y)
    x->WrittenConsent = (struct zx_ac_WrittenConsent_s*)y->gg.g.n;
  return y;
}

/* FUNC(zx_ac_Identification_PUSH_WrittenConsent) */

void zx_ac_Identification_PUSH_WrittenConsent(struct zx_ac_Identification_s* x, struct zx_ac_WrittenConsent_s* z)
{
  if (!x || !z) return;
  z->gg.g.n = &x->WrittenConsent->gg.g;
  x->WrittenConsent = z;
}

/* FUNC(zx_ac_Identification_REV_WrittenConsent) */

void zx_ac_Identification_REV_WrittenConsent(struct zx_ac_Identification_s* x)
{
  struct zx_ac_WrittenConsent_s* nxt;
  struct zx_ac_WrittenConsent_s* y;
  if (!x) return;
  y = x->WrittenConsent;
  if (!y) return;
  x->WrittenConsent = 0;
  while (y) {
    nxt = (struct zx_ac_WrittenConsent_s*)y->gg.g.n;
    y->gg.g.n = &x->WrittenConsent->gg.g;
    x->WrittenConsent = y;
    y = nxt;
  }
}

/* FUNC(zx_ac_Identification_PUT_WrittenConsent) */

void zx_ac_Identification_PUT_WrittenConsent(struct zx_ac_Identification_s* x, int n, struct zx_ac_WrittenConsent_s* z)
{
  struct zx_ac_WrittenConsent_s* y;
  if (!x || !z) return;
  y = x->WrittenConsent;
  if (!y) return;
  switch (n) {
  case 0:
    z->gg.g.n = y->gg.g.n;
    x->WrittenConsent = z;
    return;
  default:
    for (; n > 1 && y->gg.g.n; --n, y = (struct zx_ac_WrittenConsent_s*)y->gg.g.n) ;
    if (!y->gg.g.n) return;
    z->gg.g.n = y->gg.g.n->n;
    y->gg.g.n = &z->gg.g;
  }
}

/* FUNC(zx_ac_Identification_ADD_WrittenConsent) */

void zx_ac_Identification_ADD_WrittenConsent(struct zx_ac_Identification_s* x, int n, struct zx_ac_WrittenConsent_s* z)
{
  struct zx_ac_WrittenConsent_s* y;
  if (!x || !z) return;
  switch (n) {
  case 0:
  add_to_start:
    z->gg.g.n = &x->WrittenConsent->gg.g;
    x->WrittenConsent = z;
    return;
  case -1:
    y = x->WrittenConsent;
    if (!y) goto add_to_start;
    for (; y->gg.g.n; y = (struct zx_ac_WrittenConsent_s*)y->gg.g.n) ;
    break;
  default:
    for (y = x->WrittenConsent; n > 1 && y; --n, y = (struct zx_ac_WrittenConsent_s*)y->gg.g.n) ;
    if (!y) return;
  }
  z->gg.g.n = y->gg.g.n;
  y->gg.g.n = &z->gg.g;
}

/* FUNC(zx_ac_Identification_DEL_WrittenConsent) */

void zx_ac_Identification_DEL_WrittenConsent(struct zx_ac_Identification_s* x, int n)
{
  struct zx_ac_WrittenConsent_s* y;
  if (!x) return;
  switch (n) {
  case 0:
    x->WrittenConsent = (struct zx_ac_WrittenConsent_s*)x->WrittenConsent->gg.g.n;
    return;
  case -1:
    y = (struct zx_ac_WrittenConsent_s*)x->WrittenConsent;
    if (!y) return;
    for (; y->gg.g.n; y = (struct zx_ac_WrittenConsent_s*)y->gg.g.n) ;
    break;
  default:
    for (y = x->WrittenConsent; n > 1 && y->gg.g.n; --n, y = (struct zx_ac_WrittenConsent_s*)y->gg.g.n) ;
    if (!y->gg.g.n) return;
  }
  y->gg.g.n = y->gg.g.n->n;
}

#endif



#ifdef ZX_ENA_GETPUT

/* FUNC(zx_ac_Identification_NUM_Extension) */

int zx_ac_Identification_NUM_Extension(struct zx_ac_Identification_s* x)
{
  struct zx_ac_Extension_s* y;
  int n = 0;
  if (!x) return 0;
  for (y = x->Extension; y; ++n, y = (struct zx_ac_Extension_s*)y->gg.g.n) ;
  return n;
}

/* FUNC(zx_ac_Identification_GET_Extension) */

struct zx_ac_Extension_s* zx_ac_Identification_GET_Extension(struct zx_ac_Identification_s* x, int n)
{
  struct zx_ac_Extension_s* y;
  if (!x) return 0;
  for (y = x->Extension; n>=0 && y; --n, y = (struct zx_ac_Extension_s*)y->gg.g.n) ;
  return y;
}

/* FUNC(zx_ac_Identification_POP_Extension) */

struct zx_ac_Extension_s* zx_ac_Identification_POP_Extension(struct zx_ac_Identification_s* x)
{
  struct zx_ac_Extension_s* y;
  if (!x) return 0;
  y = x->Extension;
  if (y)
    x->Extension = (struct zx_ac_Extension_s*)y->gg.g.n;
  return y;
}

/* FUNC(zx_ac_Identification_PUSH_Extension) */

void zx_ac_Identification_PUSH_Extension(struct zx_ac_Identification_s* x, struct zx_ac_Extension_s* z)
{
  if (!x || !z) return;
  z->gg.g.n = &x->Extension->gg.g;
  x->Extension = z;
}

/* FUNC(zx_ac_Identification_REV_Extension) */

void zx_ac_Identification_REV_Extension(struct zx_ac_Identification_s* x)
{
  struct zx_ac_Extension_s* nxt;
  struct zx_ac_Extension_s* y;
  if (!x) return;
  y = x->Extension;
  if (!y) return;
  x->Extension = 0;
  while (y) {
    nxt = (struct zx_ac_Extension_s*)y->gg.g.n;
    y->gg.g.n = &x->Extension->gg.g;
    x->Extension = y;
    y = nxt;
  }
}

/* FUNC(zx_ac_Identification_PUT_Extension) */

void zx_ac_Identification_PUT_Extension(struct zx_ac_Identification_s* x, int n, struct zx_ac_Extension_s* z)
{
  struct zx_ac_Extension_s* y;
  if (!x || !z) return;
  y = x->Extension;
  if (!y) return;
  switch (n) {
  case 0:
    z->gg.g.n = y->gg.g.n;
    x->Extension = z;
    return;
  default:
    for (; n > 1 && y->gg.g.n; --n, y = (struct zx_ac_Extension_s*)y->gg.g.n) ;
    if (!y->gg.g.n) return;
    z->gg.g.n = y->gg.g.n->n;
    y->gg.g.n = &z->gg.g;
  }
}

/* FUNC(zx_ac_Identification_ADD_Extension) */

void zx_ac_Identification_ADD_Extension(struct zx_ac_Identification_s* x, int n, struct zx_ac_Extension_s* z)
{
  struct zx_ac_Extension_s* y;
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
    for (; y->gg.g.n; y = (struct zx_ac_Extension_s*)y->gg.g.n) ;
    break;
  default:
    for (y = x->Extension; n > 1 && y; --n, y = (struct zx_ac_Extension_s*)y->gg.g.n) ;
    if (!y) return;
  }
  z->gg.g.n = y->gg.g.n;
  y->gg.g.n = &z->gg.g;
}

/* FUNC(zx_ac_Identification_DEL_Extension) */

void zx_ac_Identification_DEL_Extension(struct zx_ac_Identification_s* x, int n)
{
  struct zx_ac_Extension_s* y;
  if (!x) return;
  switch (n) {
  case 0:
    x->Extension = (struct zx_ac_Extension_s*)x->Extension->gg.g.n;
    return;
  case -1:
    y = (struct zx_ac_Extension_s*)x->Extension;
    if (!y) return;
    for (; y->gg.g.n; y = (struct zx_ac_Extension_s*)y->gg.g.n) ;
    break;
  default:
    for (y = x->Extension; n > 1 && y->gg.g.n; --n, y = (struct zx_ac_Extension_s*)y->gg.g.n) ;
    if (!y->gg.g.n) return;
  }
  y->gg.g.n = y->gg.g.n->n;
}

#endif

/* FUNC(zx_ac_Identification_GET_nym) */
struct zx_str* zx_ac_Identification_GET_nym(struct zx_ac_Identification_s* x) { return x->nym; }
/* FUNC(zx_ac_Identification_PUT_nym) */
void zx_ac_Identification_PUT_nym(struct zx_ac_Identification_s* x, struct zx_str* y) { x->nym = y; }







#ifdef ZX_ENA_GETPUT

/* FUNC(zx_ac_KeyActivation_NUM_ActivationPin) */

int zx_ac_KeyActivation_NUM_ActivationPin(struct zx_ac_KeyActivation_s* x)
{
  struct zx_ac_ActivationPin_s* y;
  int n = 0;
  if (!x) return 0;
  for (y = x->ActivationPin; y; ++n, y = (struct zx_ac_ActivationPin_s*)y->gg.g.n) ;
  return n;
}

/* FUNC(zx_ac_KeyActivation_GET_ActivationPin) */

struct zx_ac_ActivationPin_s* zx_ac_KeyActivation_GET_ActivationPin(struct zx_ac_KeyActivation_s* x, int n)
{
  struct zx_ac_ActivationPin_s* y;
  if (!x) return 0;
  for (y = x->ActivationPin; n>=0 && y; --n, y = (struct zx_ac_ActivationPin_s*)y->gg.g.n) ;
  return y;
}

/* FUNC(zx_ac_KeyActivation_POP_ActivationPin) */

struct zx_ac_ActivationPin_s* zx_ac_KeyActivation_POP_ActivationPin(struct zx_ac_KeyActivation_s* x)
{
  struct zx_ac_ActivationPin_s* y;
  if (!x) return 0;
  y = x->ActivationPin;
  if (y)
    x->ActivationPin = (struct zx_ac_ActivationPin_s*)y->gg.g.n;
  return y;
}

/* FUNC(zx_ac_KeyActivation_PUSH_ActivationPin) */

void zx_ac_KeyActivation_PUSH_ActivationPin(struct zx_ac_KeyActivation_s* x, struct zx_ac_ActivationPin_s* z)
{
  if (!x || !z) return;
  z->gg.g.n = &x->ActivationPin->gg.g;
  x->ActivationPin = z;
}

/* FUNC(zx_ac_KeyActivation_REV_ActivationPin) */

void zx_ac_KeyActivation_REV_ActivationPin(struct zx_ac_KeyActivation_s* x)
{
  struct zx_ac_ActivationPin_s* nxt;
  struct zx_ac_ActivationPin_s* y;
  if (!x) return;
  y = x->ActivationPin;
  if (!y) return;
  x->ActivationPin = 0;
  while (y) {
    nxt = (struct zx_ac_ActivationPin_s*)y->gg.g.n;
    y->gg.g.n = &x->ActivationPin->gg.g;
    x->ActivationPin = y;
    y = nxt;
  }
}

/* FUNC(zx_ac_KeyActivation_PUT_ActivationPin) */

void zx_ac_KeyActivation_PUT_ActivationPin(struct zx_ac_KeyActivation_s* x, int n, struct zx_ac_ActivationPin_s* z)
{
  struct zx_ac_ActivationPin_s* y;
  if (!x || !z) return;
  y = x->ActivationPin;
  if (!y) return;
  switch (n) {
  case 0:
    z->gg.g.n = y->gg.g.n;
    x->ActivationPin = z;
    return;
  default:
    for (; n > 1 && y->gg.g.n; --n, y = (struct zx_ac_ActivationPin_s*)y->gg.g.n) ;
    if (!y->gg.g.n) return;
    z->gg.g.n = y->gg.g.n->n;
    y->gg.g.n = &z->gg.g;
  }
}

/* FUNC(zx_ac_KeyActivation_ADD_ActivationPin) */

void zx_ac_KeyActivation_ADD_ActivationPin(struct zx_ac_KeyActivation_s* x, int n, struct zx_ac_ActivationPin_s* z)
{
  struct zx_ac_ActivationPin_s* y;
  if (!x || !z) return;
  switch (n) {
  case 0:
  add_to_start:
    z->gg.g.n = &x->ActivationPin->gg.g;
    x->ActivationPin = z;
    return;
  case -1:
    y = x->ActivationPin;
    if (!y) goto add_to_start;
    for (; y->gg.g.n; y = (struct zx_ac_ActivationPin_s*)y->gg.g.n) ;
    break;
  default:
    for (y = x->ActivationPin; n > 1 && y; --n, y = (struct zx_ac_ActivationPin_s*)y->gg.g.n) ;
    if (!y) return;
  }
  z->gg.g.n = y->gg.g.n;
  y->gg.g.n = &z->gg.g;
}

/* FUNC(zx_ac_KeyActivation_DEL_ActivationPin) */

void zx_ac_KeyActivation_DEL_ActivationPin(struct zx_ac_KeyActivation_s* x, int n)
{
  struct zx_ac_ActivationPin_s* y;
  if (!x) return;
  switch (n) {
  case 0:
    x->ActivationPin = (struct zx_ac_ActivationPin_s*)x->ActivationPin->gg.g.n;
    return;
  case -1:
    y = (struct zx_ac_ActivationPin_s*)x->ActivationPin;
    if (!y) return;
    for (; y->gg.g.n; y = (struct zx_ac_ActivationPin_s*)y->gg.g.n) ;
    break;
  default:
    for (y = x->ActivationPin; n > 1 && y->gg.g.n; --n, y = (struct zx_ac_ActivationPin_s*)y->gg.g.n) ;
    if (!y->gg.g.n) return;
  }
  y->gg.g.n = y->gg.g.n->n;
}

#endif



#ifdef ZX_ENA_GETPUT

/* FUNC(zx_ac_KeyActivation_NUM_Extension) */

int zx_ac_KeyActivation_NUM_Extension(struct zx_ac_KeyActivation_s* x)
{
  struct zx_ac_Extension_s* y;
  int n = 0;
  if (!x) return 0;
  for (y = x->Extension; y; ++n, y = (struct zx_ac_Extension_s*)y->gg.g.n) ;
  return n;
}

/* FUNC(zx_ac_KeyActivation_GET_Extension) */

struct zx_ac_Extension_s* zx_ac_KeyActivation_GET_Extension(struct zx_ac_KeyActivation_s* x, int n)
{
  struct zx_ac_Extension_s* y;
  if (!x) return 0;
  for (y = x->Extension; n>=0 && y; --n, y = (struct zx_ac_Extension_s*)y->gg.g.n) ;
  return y;
}

/* FUNC(zx_ac_KeyActivation_POP_Extension) */

struct zx_ac_Extension_s* zx_ac_KeyActivation_POP_Extension(struct zx_ac_KeyActivation_s* x)
{
  struct zx_ac_Extension_s* y;
  if (!x) return 0;
  y = x->Extension;
  if (y)
    x->Extension = (struct zx_ac_Extension_s*)y->gg.g.n;
  return y;
}

/* FUNC(zx_ac_KeyActivation_PUSH_Extension) */

void zx_ac_KeyActivation_PUSH_Extension(struct zx_ac_KeyActivation_s* x, struct zx_ac_Extension_s* z)
{
  if (!x || !z) return;
  z->gg.g.n = &x->Extension->gg.g;
  x->Extension = z;
}

/* FUNC(zx_ac_KeyActivation_REV_Extension) */

void zx_ac_KeyActivation_REV_Extension(struct zx_ac_KeyActivation_s* x)
{
  struct zx_ac_Extension_s* nxt;
  struct zx_ac_Extension_s* y;
  if (!x) return;
  y = x->Extension;
  if (!y) return;
  x->Extension = 0;
  while (y) {
    nxt = (struct zx_ac_Extension_s*)y->gg.g.n;
    y->gg.g.n = &x->Extension->gg.g;
    x->Extension = y;
    y = nxt;
  }
}

/* FUNC(zx_ac_KeyActivation_PUT_Extension) */

void zx_ac_KeyActivation_PUT_Extension(struct zx_ac_KeyActivation_s* x, int n, struct zx_ac_Extension_s* z)
{
  struct zx_ac_Extension_s* y;
  if (!x || !z) return;
  y = x->Extension;
  if (!y) return;
  switch (n) {
  case 0:
    z->gg.g.n = y->gg.g.n;
    x->Extension = z;
    return;
  default:
    for (; n > 1 && y->gg.g.n; --n, y = (struct zx_ac_Extension_s*)y->gg.g.n) ;
    if (!y->gg.g.n) return;
    z->gg.g.n = y->gg.g.n->n;
    y->gg.g.n = &z->gg.g;
  }
}

/* FUNC(zx_ac_KeyActivation_ADD_Extension) */

void zx_ac_KeyActivation_ADD_Extension(struct zx_ac_KeyActivation_s* x, int n, struct zx_ac_Extension_s* z)
{
  struct zx_ac_Extension_s* y;
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
    for (; y->gg.g.n; y = (struct zx_ac_Extension_s*)y->gg.g.n) ;
    break;
  default:
    for (y = x->Extension; n > 1 && y; --n, y = (struct zx_ac_Extension_s*)y->gg.g.n) ;
    if (!y) return;
  }
  z->gg.g.n = y->gg.g.n;
  y->gg.g.n = &z->gg.g;
}

/* FUNC(zx_ac_KeyActivation_DEL_Extension) */

void zx_ac_KeyActivation_DEL_Extension(struct zx_ac_KeyActivation_s* x, int n)
{
  struct zx_ac_Extension_s* y;
  if (!x) return;
  switch (n) {
  case 0:
    x->Extension = (struct zx_ac_Extension_s*)x->Extension->gg.g.n;
    return;
  case -1:
    y = (struct zx_ac_Extension_s*)x->Extension;
    if (!y) return;
    for (; y->gg.g.n; y = (struct zx_ac_Extension_s*)y->gg.g.n) ;
    break;
  default:
    for (y = x->Extension; n > 1 && y->gg.g.n; --n, y = (struct zx_ac_Extension_s*)y->gg.g.n) ;
    if (!y->gg.g.n) return;
  }
  y->gg.g.n = y->gg.g.n->n;
}

#endif






/* FUNC(zx_ac_KeySharing_GET_sharing) */
struct zx_str* zx_ac_KeySharing_GET_sharing(struct zx_ac_KeySharing_s* x) { return x->sharing; }
/* FUNC(zx_ac_KeySharing_PUT_sharing) */
void zx_ac_KeySharing_PUT_sharing(struct zx_ac_KeySharing_s* x, struct zx_str* y) { x->sharing = y; }





/* FUNC(zx_ac_KeyStorage_GET_medium) */
struct zx_str* zx_ac_KeyStorage_GET_medium(struct zx_ac_KeyStorage_s* x) { return x->medium; }
/* FUNC(zx_ac_KeyStorage_PUT_medium) */
void zx_ac_KeyStorage_PUT_medium(struct zx_ac_KeyStorage_s* x, struct zx_str* y) { x->medium = y; }





/* FUNC(zx_ac_Length_GET_max) */
struct zx_str* zx_ac_Length_GET_max(struct zx_ac_Length_s* x) { return x->max; }
/* FUNC(zx_ac_Length_PUT_max) */
void zx_ac_Length_PUT_max(struct zx_ac_Length_s* x, struct zx_str* y) { x->max = y; }
/* FUNC(zx_ac_Length_GET_min) */
struct zx_str* zx_ac_Length_GET_min(struct zx_ac_Length_s* x) { return x->min; }
/* FUNC(zx_ac_Length_PUT_min) */
void zx_ac_Length_PUT_min(struct zx_ac_Length_s* x, struct zx_str* y) { x->min = y; }







#ifdef ZX_ENA_GETPUT

/* FUNC(zx_ac_MobileNetworkEndToEndEncryption_NUM_Extension) */

int zx_ac_MobileNetworkEndToEndEncryption_NUM_Extension(struct zx_ac_MobileNetworkEndToEndEncryption_s* x)
{
  struct zx_ac_Extension_s* y;
  int n = 0;
  if (!x) return 0;
  for (y = x->Extension; y; ++n, y = (struct zx_ac_Extension_s*)y->gg.g.n) ;
  return n;
}

/* FUNC(zx_ac_MobileNetworkEndToEndEncryption_GET_Extension) */

struct zx_ac_Extension_s* zx_ac_MobileNetworkEndToEndEncryption_GET_Extension(struct zx_ac_MobileNetworkEndToEndEncryption_s* x, int n)
{
  struct zx_ac_Extension_s* y;
  if (!x) return 0;
  for (y = x->Extension; n>=0 && y; --n, y = (struct zx_ac_Extension_s*)y->gg.g.n) ;
  return y;
}

/* FUNC(zx_ac_MobileNetworkEndToEndEncryption_POP_Extension) */

struct zx_ac_Extension_s* zx_ac_MobileNetworkEndToEndEncryption_POP_Extension(struct zx_ac_MobileNetworkEndToEndEncryption_s* x)
{
  struct zx_ac_Extension_s* y;
  if (!x) return 0;
  y = x->Extension;
  if (y)
    x->Extension = (struct zx_ac_Extension_s*)y->gg.g.n;
  return y;
}

/* FUNC(zx_ac_MobileNetworkEndToEndEncryption_PUSH_Extension) */

void zx_ac_MobileNetworkEndToEndEncryption_PUSH_Extension(struct zx_ac_MobileNetworkEndToEndEncryption_s* x, struct zx_ac_Extension_s* z)
{
  if (!x || !z) return;
  z->gg.g.n = &x->Extension->gg.g;
  x->Extension = z;
}

/* FUNC(zx_ac_MobileNetworkEndToEndEncryption_REV_Extension) */

void zx_ac_MobileNetworkEndToEndEncryption_REV_Extension(struct zx_ac_MobileNetworkEndToEndEncryption_s* x)
{
  struct zx_ac_Extension_s* nxt;
  struct zx_ac_Extension_s* y;
  if (!x) return;
  y = x->Extension;
  if (!y) return;
  x->Extension = 0;
  while (y) {
    nxt = (struct zx_ac_Extension_s*)y->gg.g.n;
    y->gg.g.n = &x->Extension->gg.g;
    x->Extension = y;
    y = nxt;
  }
}

/* FUNC(zx_ac_MobileNetworkEndToEndEncryption_PUT_Extension) */

void zx_ac_MobileNetworkEndToEndEncryption_PUT_Extension(struct zx_ac_MobileNetworkEndToEndEncryption_s* x, int n, struct zx_ac_Extension_s* z)
{
  struct zx_ac_Extension_s* y;
  if (!x || !z) return;
  y = x->Extension;
  if (!y) return;
  switch (n) {
  case 0:
    z->gg.g.n = y->gg.g.n;
    x->Extension = z;
    return;
  default:
    for (; n > 1 && y->gg.g.n; --n, y = (struct zx_ac_Extension_s*)y->gg.g.n) ;
    if (!y->gg.g.n) return;
    z->gg.g.n = y->gg.g.n->n;
    y->gg.g.n = &z->gg.g;
  }
}

/* FUNC(zx_ac_MobileNetworkEndToEndEncryption_ADD_Extension) */

void zx_ac_MobileNetworkEndToEndEncryption_ADD_Extension(struct zx_ac_MobileNetworkEndToEndEncryption_s* x, int n, struct zx_ac_Extension_s* z)
{
  struct zx_ac_Extension_s* y;
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
    for (; y->gg.g.n; y = (struct zx_ac_Extension_s*)y->gg.g.n) ;
    break;
  default:
    for (y = x->Extension; n > 1 && y; --n, y = (struct zx_ac_Extension_s*)y->gg.g.n) ;
    if (!y) return;
  }
  z->gg.g.n = y->gg.g.n;
  y->gg.g.n = &z->gg.g;
}

/* FUNC(zx_ac_MobileNetworkEndToEndEncryption_DEL_Extension) */

void zx_ac_MobileNetworkEndToEndEncryption_DEL_Extension(struct zx_ac_MobileNetworkEndToEndEncryption_s* x, int n)
{
  struct zx_ac_Extension_s* y;
  if (!x) return;
  switch (n) {
  case 0:
    x->Extension = (struct zx_ac_Extension_s*)x->Extension->gg.g.n;
    return;
  case -1:
    y = (struct zx_ac_Extension_s*)x->Extension;
    if (!y) return;
    for (; y->gg.g.n; y = (struct zx_ac_Extension_s*)y->gg.g.n) ;
    break;
  default:
    for (y = x->Extension; n > 1 && y->gg.g.n; --n, y = (struct zx_ac_Extension_s*)y->gg.g.n) ;
    if (!y->gg.g.n) return;
  }
  y->gg.g.n = y->gg.g.n->n;
}

#endif








#ifdef ZX_ENA_GETPUT

/* FUNC(zx_ac_MobileNetworkNoEncryption_NUM_Extension) */

int zx_ac_MobileNetworkNoEncryption_NUM_Extension(struct zx_ac_MobileNetworkNoEncryption_s* x)
{
  struct zx_ac_Extension_s* y;
  int n = 0;
  if (!x) return 0;
  for (y = x->Extension; y; ++n, y = (struct zx_ac_Extension_s*)y->gg.g.n) ;
  return n;
}

/* FUNC(zx_ac_MobileNetworkNoEncryption_GET_Extension) */

struct zx_ac_Extension_s* zx_ac_MobileNetworkNoEncryption_GET_Extension(struct zx_ac_MobileNetworkNoEncryption_s* x, int n)
{
  struct zx_ac_Extension_s* y;
  if (!x) return 0;
  for (y = x->Extension; n>=0 && y; --n, y = (struct zx_ac_Extension_s*)y->gg.g.n) ;
  return y;
}

/* FUNC(zx_ac_MobileNetworkNoEncryption_POP_Extension) */

struct zx_ac_Extension_s* zx_ac_MobileNetworkNoEncryption_POP_Extension(struct zx_ac_MobileNetworkNoEncryption_s* x)
{
  struct zx_ac_Extension_s* y;
  if (!x) return 0;
  y = x->Extension;
  if (y)
    x->Extension = (struct zx_ac_Extension_s*)y->gg.g.n;
  return y;
}

/* FUNC(zx_ac_MobileNetworkNoEncryption_PUSH_Extension) */

void zx_ac_MobileNetworkNoEncryption_PUSH_Extension(struct zx_ac_MobileNetworkNoEncryption_s* x, struct zx_ac_Extension_s* z)
{
  if (!x || !z) return;
  z->gg.g.n = &x->Extension->gg.g;
  x->Extension = z;
}

/* FUNC(zx_ac_MobileNetworkNoEncryption_REV_Extension) */

void zx_ac_MobileNetworkNoEncryption_REV_Extension(struct zx_ac_MobileNetworkNoEncryption_s* x)
{
  struct zx_ac_Extension_s* nxt;
  struct zx_ac_Extension_s* y;
  if (!x) return;
  y = x->Extension;
  if (!y) return;
  x->Extension = 0;
  while (y) {
    nxt = (struct zx_ac_Extension_s*)y->gg.g.n;
    y->gg.g.n = &x->Extension->gg.g;
    x->Extension = y;
    y = nxt;
  }
}

/* FUNC(zx_ac_MobileNetworkNoEncryption_PUT_Extension) */

void zx_ac_MobileNetworkNoEncryption_PUT_Extension(struct zx_ac_MobileNetworkNoEncryption_s* x, int n, struct zx_ac_Extension_s* z)
{
  struct zx_ac_Extension_s* y;
  if (!x || !z) return;
  y = x->Extension;
  if (!y) return;
  switch (n) {
  case 0:
    z->gg.g.n = y->gg.g.n;
    x->Extension = z;
    return;
  default:
    for (; n > 1 && y->gg.g.n; --n, y = (struct zx_ac_Extension_s*)y->gg.g.n) ;
    if (!y->gg.g.n) return;
    z->gg.g.n = y->gg.g.n->n;
    y->gg.g.n = &z->gg.g;
  }
}

/* FUNC(zx_ac_MobileNetworkNoEncryption_ADD_Extension) */

void zx_ac_MobileNetworkNoEncryption_ADD_Extension(struct zx_ac_MobileNetworkNoEncryption_s* x, int n, struct zx_ac_Extension_s* z)
{
  struct zx_ac_Extension_s* y;
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
    for (; y->gg.g.n; y = (struct zx_ac_Extension_s*)y->gg.g.n) ;
    break;
  default:
    for (y = x->Extension; n > 1 && y; --n, y = (struct zx_ac_Extension_s*)y->gg.g.n) ;
    if (!y) return;
  }
  z->gg.g.n = y->gg.g.n;
  y->gg.g.n = &z->gg.g;
}

/* FUNC(zx_ac_MobileNetworkNoEncryption_DEL_Extension) */

void zx_ac_MobileNetworkNoEncryption_DEL_Extension(struct zx_ac_MobileNetworkNoEncryption_s* x, int n)
{
  struct zx_ac_Extension_s* y;
  if (!x) return;
  switch (n) {
  case 0:
    x->Extension = (struct zx_ac_Extension_s*)x->Extension->gg.g.n;
    return;
  case -1:
    y = (struct zx_ac_Extension_s*)x->Extension;
    if (!y) return;
    for (; y->gg.g.n; y = (struct zx_ac_Extension_s*)y->gg.g.n) ;
    break;
  default:
    for (y = x->Extension; n > 1 && y->gg.g.n; --n, y = (struct zx_ac_Extension_s*)y->gg.g.n) ;
    if (!y->gg.g.n) return;
  }
  y->gg.g.n = y->gg.g.n->n;
}

#endif








#ifdef ZX_ENA_GETPUT

/* FUNC(zx_ac_MobileNetworkRadioEncryption_NUM_Extension) */

int zx_ac_MobileNetworkRadioEncryption_NUM_Extension(struct zx_ac_MobileNetworkRadioEncryption_s* x)
{
  struct zx_ac_Extension_s* y;
  int n = 0;
  if (!x) return 0;
  for (y = x->Extension; y; ++n, y = (struct zx_ac_Extension_s*)y->gg.g.n) ;
  return n;
}

/* FUNC(zx_ac_MobileNetworkRadioEncryption_GET_Extension) */

struct zx_ac_Extension_s* zx_ac_MobileNetworkRadioEncryption_GET_Extension(struct zx_ac_MobileNetworkRadioEncryption_s* x, int n)
{
  struct zx_ac_Extension_s* y;
  if (!x) return 0;
  for (y = x->Extension; n>=0 && y; --n, y = (struct zx_ac_Extension_s*)y->gg.g.n) ;
  return y;
}

/* FUNC(zx_ac_MobileNetworkRadioEncryption_POP_Extension) */

struct zx_ac_Extension_s* zx_ac_MobileNetworkRadioEncryption_POP_Extension(struct zx_ac_MobileNetworkRadioEncryption_s* x)
{
  struct zx_ac_Extension_s* y;
  if (!x) return 0;
  y = x->Extension;
  if (y)
    x->Extension = (struct zx_ac_Extension_s*)y->gg.g.n;
  return y;
}

/* FUNC(zx_ac_MobileNetworkRadioEncryption_PUSH_Extension) */

void zx_ac_MobileNetworkRadioEncryption_PUSH_Extension(struct zx_ac_MobileNetworkRadioEncryption_s* x, struct zx_ac_Extension_s* z)
{
  if (!x || !z) return;
  z->gg.g.n = &x->Extension->gg.g;
  x->Extension = z;
}

/* FUNC(zx_ac_MobileNetworkRadioEncryption_REV_Extension) */

void zx_ac_MobileNetworkRadioEncryption_REV_Extension(struct zx_ac_MobileNetworkRadioEncryption_s* x)
{
  struct zx_ac_Extension_s* nxt;
  struct zx_ac_Extension_s* y;
  if (!x) return;
  y = x->Extension;
  if (!y) return;
  x->Extension = 0;
  while (y) {
    nxt = (struct zx_ac_Extension_s*)y->gg.g.n;
    y->gg.g.n = &x->Extension->gg.g;
    x->Extension = y;
    y = nxt;
  }
}

/* FUNC(zx_ac_MobileNetworkRadioEncryption_PUT_Extension) */

void zx_ac_MobileNetworkRadioEncryption_PUT_Extension(struct zx_ac_MobileNetworkRadioEncryption_s* x, int n, struct zx_ac_Extension_s* z)
{
  struct zx_ac_Extension_s* y;
  if (!x || !z) return;
  y = x->Extension;
  if (!y) return;
  switch (n) {
  case 0:
    z->gg.g.n = y->gg.g.n;
    x->Extension = z;
    return;
  default:
    for (; n > 1 && y->gg.g.n; --n, y = (struct zx_ac_Extension_s*)y->gg.g.n) ;
    if (!y->gg.g.n) return;
    z->gg.g.n = y->gg.g.n->n;
    y->gg.g.n = &z->gg.g;
  }
}

/* FUNC(zx_ac_MobileNetworkRadioEncryption_ADD_Extension) */

void zx_ac_MobileNetworkRadioEncryption_ADD_Extension(struct zx_ac_MobileNetworkRadioEncryption_s* x, int n, struct zx_ac_Extension_s* z)
{
  struct zx_ac_Extension_s* y;
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
    for (; y->gg.g.n; y = (struct zx_ac_Extension_s*)y->gg.g.n) ;
    break;
  default:
    for (y = x->Extension; n > 1 && y; --n, y = (struct zx_ac_Extension_s*)y->gg.g.n) ;
    if (!y) return;
  }
  z->gg.g.n = y->gg.g.n;
  y->gg.g.n = &z->gg.g;
}

/* FUNC(zx_ac_MobileNetworkRadioEncryption_DEL_Extension) */

void zx_ac_MobileNetworkRadioEncryption_DEL_Extension(struct zx_ac_MobileNetworkRadioEncryption_s* x, int n)
{
  struct zx_ac_Extension_s* y;
  if (!x) return;
  switch (n) {
  case 0:
    x->Extension = (struct zx_ac_Extension_s*)x->Extension->gg.g.n;
    return;
  case -1:
    y = (struct zx_ac_Extension_s*)x->Extension;
    if (!y) return;
    for (; y->gg.g.n; y = (struct zx_ac_Extension_s*)y->gg.g.n) ;
    break;
  default:
    for (y = x->Extension; n > 1 && y->gg.g.n; --n, y = (struct zx_ac_Extension_s*)y->gg.g.n) ;
    if (!y->gg.g.n) return;
  }
  y->gg.g.n = y->gg.g.n->n;
}

#endif








#ifdef ZX_ENA_GETPUT

/* FUNC(zx_ac_OperationalProtection_NUM_SecurityAudit) */

int zx_ac_OperationalProtection_NUM_SecurityAudit(struct zx_ac_OperationalProtection_s* x)
{
  struct zx_ac_SecurityAudit_s* y;
  int n = 0;
  if (!x) return 0;
  for (y = x->SecurityAudit; y; ++n, y = (struct zx_ac_SecurityAudit_s*)y->gg.g.n) ;
  return n;
}

/* FUNC(zx_ac_OperationalProtection_GET_SecurityAudit) */

struct zx_ac_SecurityAudit_s* zx_ac_OperationalProtection_GET_SecurityAudit(struct zx_ac_OperationalProtection_s* x, int n)
{
  struct zx_ac_SecurityAudit_s* y;
  if (!x) return 0;
  for (y = x->SecurityAudit; n>=0 && y; --n, y = (struct zx_ac_SecurityAudit_s*)y->gg.g.n) ;
  return y;
}

/* FUNC(zx_ac_OperationalProtection_POP_SecurityAudit) */

struct zx_ac_SecurityAudit_s* zx_ac_OperationalProtection_POP_SecurityAudit(struct zx_ac_OperationalProtection_s* x)
{
  struct zx_ac_SecurityAudit_s* y;
  if (!x) return 0;
  y = x->SecurityAudit;
  if (y)
    x->SecurityAudit = (struct zx_ac_SecurityAudit_s*)y->gg.g.n;
  return y;
}

/* FUNC(zx_ac_OperationalProtection_PUSH_SecurityAudit) */

void zx_ac_OperationalProtection_PUSH_SecurityAudit(struct zx_ac_OperationalProtection_s* x, struct zx_ac_SecurityAudit_s* z)
{
  if (!x || !z) return;
  z->gg.g.n = &x->SecurityAudit->gg.g;
  x->SecurityAudit = z;
}

/* FUNC(zx_ac_OperationalProtection_REV_SecurityAudit) */

void zx_ac_OperationalProtection_REV_SecurityAudit(struct zx_ac_OperationalProtection_s* x)
{
  struct zx_ac_SecurityAudit_s* nxt;
  struct zx_ac_SecurityAudit_s* y;
  if (!x) return;
  y = x->SecurityAudit;
  if (!y) return;
  x->SecurityAudit = 0;
  while (y) {
    nxt = (struct zx_ac_SecurityAudit_s*)y->gg.g.n;
    y->gg.g.n = &x->SecurityAudit->gg.g;
    x->SecurityAudit = y;
    y = nxt;
  }
}

/* FUNC(zx_ac_OperationalProtection_PUT_SecurityAudit) */

void zx_ac_OperationalProtection_PUT_SecurityAudit(struct zx_ac_OperationalProtection_s* x, int n, struct zx_ac_SecurityAudit_s* z)
{
  struct zx_ac_SecurityAudit_s* y;
  if (!x || !z) return;
  y = x->SecurityAudit;
  if (!y) return;
  switch (n) {
  case 0:
    z->gg.g.n = y->gg.g.n;
    x->SecurityAudit = z;
    return;
  default:
    for (; n > 1 && y->gg.g.n; --n, y = (struct zx_ac_SecurityAudit_s*)y->gg.g.n) ;
    if (!y->gg.g.n) return;
    z->gg.g.n = y->gg.g.n->n;
    y->gg.g.n = &z->gg.g;
  }
}

/* FUNC(zx_ac_OperationalProtection_ADD_SecurityAudit) */

void zx_ac_OperationalProtection_ADD_SecurityAudit(struct zx_ac_OperationalProtection_s* x, int n, struct zx_ac_SecurityAudit_s* z)
{
  struct zx_ac_SecurityAudit_s* y;
  if (!x || !z) return;
  switch (n) {
  case 0:
  add_to_start:
    z->gg.g.n = &x->SecurityAudit->gg.g;
    x->SecurityAudit = z;
    return;
  case -1:
    y = x->SecurityAudit;
    if (!y) goto add_to_start;
    for (; y->gg.g.n; y = (struct zx_ac_SecurityAudit_s*)y->gg.g.n) ;
    break;
  default:
    for (y = x->SecurityAudit; n > 1 && y; --n, y = (struct zx_ac_SecurityAudit_s*)y->gg.g.n) ;
    if (!y) return;
  }
  z->gg.g.n = y->gg.g.n;
  y->gg.g.n = &z->gg.g;
}

/* FUNC(zx_ac_OperationalProtection_DEL_SecurityAudit) */

void zx_ac_OperationalProtection_DEL_SecurityAudit(struct zx_ac_OperationalProtection_s* x, int n)
{
  struct zx_ac_SecurityAudit_s* y;
  if (!x) return;
  switch (n) {
  case 0:
    x->SecurityAudit = (struct zx_ac_SecurityAudit_s*)x->SecurityAudit->gg.g.n;
    return;
  case -1:
    y = (struct zx_ac_SecurityAudit_s*)x->SecurityAudit;
    if (!y) return;
    for (; y->gg.g.n; y = (struct zx_ac_SecurityAudit_s*)y->gg.g.n) ;
    break;
  default:
    for (y = x->SecurityAudit; n > 1 && y->gg.g.n; --n, y = (struct zx_ac_SecurityAudit_s*)y->gg.g.n) ;
    if (!y->gg.g.n) return;
  }
  y->gg.g.n = y->gg.g.n->n;
}

#endif



#ifdef ZX_ENA_GETPUT

/* FUNC(zx_ac_OperationalProtection_NUM_DeactivationCallCenter) */

int zx_ac_OperationalProtection_NUM_DeactivationCallCenter(struct zx_ac_OperationalProtection_s* x)
{
  struct zx_ac_DeactivationCallCenter_s* y;
  int n = 0;
  if (!x) return 0;
  for (y = x->DeactivationCallCenter; y; ++n, y = (struct zx_ac_DeactivationCallCenter_s*)y->gg.g.n) ;
  return n;
}

/* FUNC(zx_ac_OperationalProtection_GET_DeactivationCallCenter) */

struct zx_ac_DeactivationCallCenter_s* zx_ac_OperationalProtection_GET_DeactivationCallCenter(struct zx_ac_OperationalProtection_s* x, int n)
{
  struct zx_ac_DeactivationCallCenter_s* y;
  if (!x) return 0;
  for (y = x->DeactivationCallCenter; n>=0 && y; --n, y = (struct zx_ac_DeactivationCallCenter_s*)y->gg.g.n) ;
  return y;
}

/* FUNC(zx_ac_OperationalProtection_POP_DeactivationCallCenter) */

struct zx_ac_DeactivationCallCenter_s* zx_ac_OperationalProtection_POP_DeactivationCallCenter(struct zx_ac_OperationalProtection_s* x)
{
  struct zx_ac_DeactivationCallCenter_s* y;
  if (!x) return 0;
  y = x->DeactivationCallCenter;
  if (y)
    x->DeactivationCallCenter = (struct zx_ac_DeactivationCallCenter_s*)y->gg.g.n;
  return y;
}

/* FUNC(zx_ac_OperationalProtection_PUSH_DeactivationCallCenter) */

void zx_ac_OperationalProtection_PUSH_DeactivationCallCenter(struct zx_ac_OperationalProtection_s* x, struct zx_ac_DeactivationCallCenter_s* z)
{
  if (!x || !z) return;
  z->gg.g.n = &x->DeactivationCallCenter->gg.g;
  x->DeactivationCallCenter = z;
}

/* FUNC(zx_ac_OperationalProtection_REV_DeactivationCallCenter) */

void zx_ac_OperationalProtection_REV_DeactivationCallCenter(struct zx_ac_OperationalProtection_s* x)
{
  struct zx_ac_DeactivationCallCenter_s* nxt;
  struct zx_ac_DeactivationCallCenter_s* y;
  if (!x) return;
  y = x->DeactivationCallCenter;
  if (!y) return;
  x->DeactivationCallCenter = 0;
  while (y) {
    nxt = (struct zx_ac_DeactivationCallCenter_s*)y->gg.g.n;
    y->gg.g.n = &x->DeactivationCallCenter->gg.g;
    x->DeactivationCallCenter = y;
    y = nxt;
  }
}

/* FUNC(zx_ac_OperationalProtection_PUT_DeactivationCallCenter) */

void zx_ac_OperationalProtection_PUT_DeactivationCallCenter(struct zx_ac_OperationalProtection_s* x, int n, struct zx_ac_DeactivationCallCenter_s* z)
{
  struct zx_ac_DeactivationCallCenter_s* y;
  if (!x || !z) return;
  y = x->DeactivationCallCenter;
  if (!y) return;
  switch (n) {
  case 0:
    z->gg.g.n = y->gg.g.n;
    x->DeactivationCallCenter = z;
    return;
  default:
    for (; n > 1 && y->gg.g.n; --n, y = (struct zx_ac_DeactivationCallCenter_s*)y->gg.g.n) ;
    if (!y->gg.g.n) return;
    z->gg.g.n = y->gg.g.n->n;
    y->gg.g.n = &z->gg.g;
  }
}

/* FUNC(zx_ac_OperationalProtection_ADD_DeactivationCallCenter) */

void zx_ac_OperationalProtection_ADD_DeactivationCallCenter(struct zx_ac_OperationalProtection_s* x, int n, struct zx_ac_DeactivationCallCenter_s* z)
{
  struct zx_ac_DeactivationCallCenter_s* y;
  if (!x || !z) return;
  switch (n) {
  case 0:
  add_to_start:
    z->gg.g.n = &x->DeactivationCallCenter->gg.g;
    x->DeactivationCallCenter = z;
    return;
  case -1:
    y = x->DeactivationCallCenter;
    if (!y) goto add_to_start;
    for (; y->gg.g.n; y = (struct zx_ac_DeactivationCallCenter_s*)y->gg.g.n) ;
    break;
  default:
    for (y = x->DeactivationCallCenter; n > 1 && y; --n, y = (struct zx_ac_DeactivationCallCenter_s*)y->gg.g.n) ;
    if (!y) return;
  }
  z->gg.g.n = y->gg.g.n;
  y->gg.g.n = &z->gg.g;
}

/* FUNC(zx_ac_OperationalProtection_DEL_DeactivationCallCenter) */

void zx_ac_OperationalProtection_DEL_DeactivationCallCenter(struct zx_ac_OperationalProtection_s* x, int n)
{
  struct zx_ac_DeactivationCallCenter_s* y;
  if (!x) return;
  switch (n) {
  case 0:
    x->DeactivationCallCenter = (struct zx_ac_DeactivationCallCenter_s*)x->DeactivationCallCenter->gg.g.n;
    return;
  case -1:
    y = (struct zx_ac_DeactivationCallCenter_s*)x->DeactivationCallCenter;
    if (!y) return;
    for (; y->gg.g.n; y = (struct zx_ac_DeactivationCallCenter_s*)y->gg.g.n) ;
    break;
  default:
    for (y = x->DeactivationCallCenter; n > 1 && y->gg.g.n; --n, y = (struct zx_ac_DeactivationCallCenter_s*)y->gg.g.n) ;
    if (!y->gg.g.n) return;
  }
  y->gg.g.n = y->gg.g.n->n;
}

#endif



#ifdef ZX_ENA_GETPUT

/* FUNC(zx_ac_OperationalProtection_NUM_Extension) */

int zx_ac_OperationalProtection_NUM_Extension(struct zx_ac_OperationalProtection_s* x)
{
  struct zx_ac_Extension_s* y;
  int n = 0;
  if (!x) return 0;
  for (y = x->Extension; y; ++n, y = (struct zx_ac_Extension_s*)y->gg.g.n) ;
  return n;
}

/* FUNC(zx_ac_OperationalProtection_GET_Extension) */

struct zx_ac_Extension_s* zx_ac_OperationalProtection_GET_Extension(struct zx_ac_OperationalProtection_s* x, int n)
{
  struct zx_ac_Extension_s* y;
  if (!x) return 0;
  for (y = x->Extension; n>=0 && y; --n, y = (struct zx_ac_Extension_s*)y->gg.g.n) ;
  return y;
}

/* FUNC(zx_ac_OperationalProtection_POP_Extension) */

struct zx_ac_Extension_s* zx_ac_OperationalProtection_POP_Extension(struct zx_ac_OperationalProtection_s* x)
{
  struct zx_ac_Extension_s* y;
  if (!x) return 0;
  y = x->Extension;
  if (y)
    x->Extension = (struct zx_ac_Extension_s*)y->gg.g.n;
  return y;
}

/* FUNC(zx_ac_OperationalProtection_PUSH_Extension) */

void zx_ac_OperationalProtection_PUSH_Extension(struct zx_ac_OperationalProtection_s* x, struct zx_ac_Extension_s* z)
{
  if (!x || !z) return;
  z->gg.g.n = &x->Extension->gg.g;
  x->Extension = z;
}

/* FUNC(zx_ac_OperationalProtection_REV_Extension) */

void zx_ac_OperationalProtection_REV_Extension(struct zx_ac_OperationalProtection_s* x)
{
  struct zx_ac_Extension_s* nxt;
  struct zx_ac_Extension_s* y;
  if (!x) return;
  y = x->Extension;
  if (!y) return;
  x->Extension = 0;
  while (y) {
    nxt = (struct zx_ac_Extension_s*)y->gg.g.n;
    y->gg.g.n = &x->Extension->gg.g;
    x->Extension = y;
    y = nxt;
  }
}

/* FUNC(zx_ac_OperationalProtection_PUT_Extension) */

void zx_ac_OperationalProtection_PUT_Extension(struct zx_ac_OperationalProtection_s* x, int n, struct zx_ac_Extension_s* z)
{
  struct zx_ac_Extension_s* y;
  if (!x || !z) return;
  y = x->Extension;
  if (!y) return;
  switch (n) {
  case 0:
    z->gg.g.n = y->gg.g.n;
    x->Extension = z;
    return;
  default:
    for (; n > 1 && y->gg.g.n; --n, y = (struct zx_ac_Extension_s*)y->gg.g.n) ;
    if (!y->gg.g.n) return;
    z->gg.g.n = y->gg.g.n->n;
    y->gg.g.n = &z->gg.g;
  }
}

/* FUNC(zx_ac_OperationalProtection_ADD_Extension) */

void zx_ac_OperationalProtection_ADD_Extension(struct zx_ac_OperationalProtection_s* x, int n, struct zx_ac_Extension_s* z)
{
  struct zx_ac_Extension_s* y;
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
    for (; y->gg.g.n; y = (struct zx_ac_Extension_s*)y->gg.g.n) ;
    break;
  default:
    for (y = x->Extension; n > 1 && y; --n, y = (struct zx_ac_Extension_s*)y->gg.g.n) ;
    if (!y) return;
  }
  z->gg.g.n = y->gg.g.n;
  y->gg.g.n = &z->gg.g;
}

/* FUNC(zx_ac_OperationalProtection_DEL_Extension) */

void zx_ac_OperationalProtection_DEL_Extension(struct zx_ac_OperationalProtection_s* x, int n)
{
  struct zx_ac_Extension_s* y;
  if (!x) return;
  switch (n) {
  case 0:
    x->Extension = (struct zx_ac_Extension_s*)x->Extension->gg.g.n;
    return;
  case -1:
    y = (struct zx_ac_Extension_s*)x->Extension;
    if (!y) return;
    for (; y->gg.g.n; y = (struct zx_ac_Extension_s*)y->gg.g.n) ;
    break;
  default:
    for (y = x->Extension; n > 1 && y->gg.g.n; --n, y = (struct zx_ac_Extension_s*)y->gg.g.n) ;
    if (!y->gg.g.n) return;
  }
  y->gg.g.n = y->gg.g.n->n;
}

#endif








#ifdef ZX_ENA_GETPUT

/* FUNC(zx_ac_Password_NUM_Length) */

int zx_ac_Password_NUM_Length(struct zx_ac_Password_s* x)
{
  struct zx_ac_Length_s* y;
  int n = 0;
  if (!x) return 0;
  for (y = x->Length; y; ++n, y = (struct zx_ac_Length_s*)y->gg.g.n) ;
  return n;
}

/* FUNC(zx_ac_Password_GET_Length) */

struct zx_ac_Length_s* zx_ac_Password_GET_Length(struct zx_ac_Password_s* x, int n)
{
  struct zx_ac_Length_s* y;
  if (!x) return 0;
  for (y = x->Length; n>=0 && y; --n, y = (struct zx_ac_Length_s*)y->gg.g.n) ;
  return y;
}

/* FUNC(zx_ac_Password_POP_Length) */

struct zx_ac_Length_s* zx_ac_Password_POP_Length(struct zx_ac_Password_s* x)
{
  struct zx_ac_Length_s* y;
  if (!x) return 0;
  y = x->Length;
  if (y)
    x->Length = (struct zx_ac_Length_s*)y->gg.g.n;
  return y;
}

/* FUNC(zx_ac_Password_PUSH_Length) */

void zx_ac_Password_PUSH_Length(struct zx_ac_Password_s* x, struct zx_ac_Length_s* z)
{
  if (!x || !z) return;
  z->gg.g.n = &x->Length->gg.g;
  x->Length = z;
}

/* FUNC(zx_ac_Password_REV_Length) */

void zx_ac_Password_REV_Length(struct zx_ac_Password_s* x)
{
  struct zx_ac_Length_s* nxt;
  struct zx_ac_Length_s* y;
  if (!x) return;
  y = x->Length;
  if (!y) return;
  x->Length = 0;
  while (y) {
    nxt = (struct zx_ac_Length_s*)y->gg.g.n;
    y->gg.g.n = &x->Length->gg.g;
    x->Length = y;
    y = nxt;
  }
}

/* FUNC(zx_ac_Password_PUT_Length) */

void zx_ac_Password_PUT_Length(struct zx_ac_Password_s* x, int n, struct zx_ac_Length_s* z)
{
  struct zx_ac_Length_s* y;
  if (!x || !z) return;
  y = x->Length;
  if (!y) return;
  switch (n) {
  case 0:
    z->gg.g.n = y->gg.g.n;
    x->Length = z;
    return;
  default:
    for (; n > 1 && y->gg.g.n; --n, y = (struct zx_ac_Length_s*)y->gg.g.n) ;
    if (!y->gg.g.n) return;
    z->gg.g.n = y->gg.g.n->n;
    y->gg.g.n = &z->gg.g;
  }
}

/* FUNC(zx_ac_Password_ADD_Length) */

void zx_ac_Password_ADD_Length(struct zx_ac_Password_s* x, int n, struct zx_ac_Length_s* z)
{
  struct zx_ac_Length_s* y;
  if (!x || !z) return;
  switch (n) {
  case 0:
  add_to_start:
    z->gg.g.n = &x->Length->gg.g;
    x->Length = z;
    return;
  case -1:
    y = x->Length;
    if (!y) goto add_to_start;
    for (; y->gg.g.n; y = (struct zx_ac_Length_s*)y->gg.g.n) ;
    break;
  default:
    for (y = x->Length; n > 1 && y; --n, y = (struct zx_ac_Length_s*)y->gg.g.n) ;
    if (!y) return;
  }
  z->gg.g.n = y->gg.g.n;
  y->gg.g.n = &z->gg.g;
}

/* FUNC(zx_ac_Password_DEL_Length) */

void zx_ac_Password_DEL_Length(struct zx_ac_Password_s* x, int n)
{
  struct zx_ac_Length_s* y;
  if (!x) return;
  switch (n) {
  case 0:
    x->Length = (struct zx_ac_Length_s*)x->Length->gg.g.n;
    return;
  case -1:
    y = (struct zx_ac_Length_s*)x->Length;
    if (!y) return;
    for (; y->gg.g.n; y = (struct zx_ac_Length_s*)y->gg.g.n) ;
    break;
  default:
    for (y = x->Length; n > 1 && y->gg.g.n; --n, y = (struct zx_ac_Length_s*)y->gg.g.n) ;
    if (!y->gg.g.n) return;
  }
  y->gg.g.n = y->gg.g.n->n;
}

#endif



#ifdef ZX_ENA_GETPUT

/* FUNC(zx_ac_Password_NUM_Alphabet) */

int zx_ac_Password_NUM_Alphabet(struct zx_ac_Password_s* x)
{
  struct zx_ac_Alphabet_s* y;
  int n = 0;
  if (!x) return 0;
  for (y = x->Alphabet; y; ++n, y = (struct zx_ac_Alphabet_s*)y->gg.g.n) ;
  return n;
}

/* FUNC(zx_ac_Password_GET_Alphabet) */

struct zx_ac_Alphabet_s* zx_ac_Password_GET_Alphabet(struct zx_ac_Password_s* x, int n)
{
  struct zx_ac_Alphabet_s* y;
  if (!x) return 0;
  for (y = x->Alphabet; n>=0 && y; --n, y = (struct zx_ac_Alphabet_s*)y->gg.g.n) ;
  return y;
}

/* FUNC(zx_ac_Password_POP_Alphabet) */

struct zx_ac_Alphabet_s* zx_ac_Password_POP_Alphabet(struct zx_ac_Password_s* x)
{
  struct zx_ac_Alphabet_s* y;
  if (!x) return 0;
  y = x->Alphabet;
  if (y)
    x->Alphabet = (struct zx_ac_Alphabet_s*)y->gg.g.n;
  return y;
}

/* FUNC(zx_ac_Password_PUSH_Alphabet) */

void zx_ac_Password_PUSH_Alphabet(struct zx_ac_Password_s* x, struct zx_ac_Alphabet_s* z)
{
  if (!x || !z) return;
  z->gg.g.n = &x->Alphabet->gg.g;
  x->Alphabet = z;
}

/* FUNC(zx_ac_Password_REV_Alphabet) */

void zx_ac_Password_REV_Alphabet(struct zx_ac_Password_s* x)
{
  struct zx_ac_Alphabet_s* nxt;
  struct zx_ac_Alphabet_s* y;
  if (!x) return;
  y = x->Alphabet;
  if (!y) return;
  x->Alphabet = 0;
  while (y) {
    nxt = (struct zx_ac_Alphabet_s*)y->gg.g.n;
    y->gg.g.n = &x->Alphabet->gg.g;
    x->Alphabet = y;
    y = nxt;
  }
}

/* FUNC(zx_ac_Password_PUT_Alphabet) */

void zx_ac_Password_PUT_Alphabet(struct zx_ac_Password_s* x, int n, struct zx_ac_Alphabet_s* z)
{
  struct zx_ac_Alphabet_s* y;
  if (!x || !z) return;
  y = x->Alphabet;
  if (!y) return;
  switch (n) {
  case 0:
    z->gg.g.n = y->gg.g.n;
    x->Alphabet = z;
    return;
  default:
    for (; n > 1 && y->gg.g.n; --n, y = (struct zx_ac_Alphabet_s*)y->gg.g.n) ;
    if (!y->gg.g.n) return;
    z->gg.g.n = y->gg.g.n->n;
    y->gg.g.n = &z->gg.g;
  }
}

/* FUNC(zx_ac_Password_ADD_Alphabet) */

void zx_ac_Password_ADD_Alphabet(struct zx_ac_Password_s* x, int n, struct zx_ac_Alphabet_s* z)
{
  struct zx_ac_Alphabet_s* y;
  if (!x || !z) return;
  switch (n) {
  case 0:
  add_to_start:
    z->gg.g.n = &x->Alphabet->gg.g;
    x->Alphabet = z;
    return;
  case -1:
    y = x->Alphabet;
    if (!y) goto add_to_start;
    for (; y->gg.g.n; y = (struct zx_ac_Alphabet_s*)y->gg.g.n) ;
    break;
  default:
    for (y = x->Alphabet; n > 1 && y; --n, y = (struct zx_ac_Alphabet_s*)y->gg.g.n) ;
    if (!y) return;
  }
  z->gg.g.n = y->gg.g.n;
  y->gg.g.n = &z->gg.g;
}

/* FUNC(zx_ac_Password_DEL_Alphabet) */

void zx_ac_Password_DEL_Alphabet(struct zx_ac_Password_s* x, int n)
{
  struct zx_ac_Alphabet_s* y;
  if (!x) return;
  switch (n) {
  case 0:
    x->Alphabet = (struct zx_ac_Alphabet_s*)x->Alphabet->gg.g.n;
    return;
  case -1:
    y = (struct zx_ac_Alphabet_s*)x->Alphabet;
    if (!y) return;
    for (; y->gg.g.n; y = (struct zx_ac_Alphabet_s*)y->gg.g.n) ;
    break;
  default:
    for (y = x->Alphabet; n > 1 && y->gg.g.n; --n, y = (struct zx_ac_Alphabet_s*)y->gg.g.n) ;
    if (!y->gg.g.n) return;
  }
  y->gg.g.n = y->gg.g.n->n;
}

#endif



#ifdef ZX_ENA_GETPUT

/* FUNC(zx_ac_Password_NUM_Generation) */

int zx_ac_Password_NUM_Generation(struct zx_ac_Password_s* x)
{
  struct zx_ac_Generation_s* y;
  int n = 0;
  if (!x) return 0;
  for (y = x->Generation; y; ++n, y = (struct zx_ac_Generation_s*)y->gg.g.n) ;
  return n;
}

/* FUNC(zx_ac_Password_GET_Generation) */

struct zx_ac_Generation_s* zx_ac_Password_GET_Generation(struct zx_ac_Password_s* x, int n)
{
  struct zx_ac_Generation_s* y;
  if (!x) return 0;
  for (y = x->Generation; n>=0 && y; --n, y = (struct zx_ac_Generation_s*)y->gg.g.n) ;
  return y;
}

/* FUNC(zx_ac_Password_POP_Generation) */

struct zx_ac_Generation_s* zx_ac_Password_POP_Generation(struct zx_ac_Password_s* x)
{
  struct zx_ac_Generation_s* y;
  if (!x) return 0;
  y = x->Generation;
  if (y)
    x->Generation = (struct zx_ac_Generation_s*)y->gg.g.n;
  return y;
}

/* FUNC(zx_ac_Password_PUSH_Generation) */

void zx_ac_Password_PUSH_Generation(struct zx_ac_Password_s* x, struct zx_ac_Generation_s* z)
{
  if (!x || !z) return;
  z->gg.g.n = &x->Generation->gg.g;
  x->Generation = z;
}

/* FUNC(zx_ac_Password_REV_Generation) */

void zx_ac_Password_REV_Generation(struct zx_ac_Password_s* x)
{
  struct zx_ac_Generation_s* nxt;
  struct zx_ac_Generation_s* y;
  if (!x) return;
  y = x->Generation;
  if (!y) return;
  x->Generation = 0;
  while (y) {
    nxt = (struct zx_ac_Generation_s*)y->gg.g.n;
    y->gg.g.n = &x->Generation->gg.g;
    x->Generation = y;
    y = nxt;
  }
}

/* FUNC(zx_ac_Password_PUT_Generation) */

void zx_ac_Password_PUT_Generation(struct zx_ac_Password_s* x, int n, struct zx_ac_Generation_s* z)
{
  struct zx_ac_Generation_s* y;
  if (!x || !z) return;
  y = x->Generation;
  if (!y) return;
  switch (n) {
  case 0:
    z->gg.g.n = y->gg.g.n;
    x->Generation = z;
    return;
  default:
    for (; n > 1 && y->gg.g.n; --n, y = (struct zx_ac_Generation_s*)y->gg.g.n) ;
    if (!y->gg.g.n) return;
    z->gg.g.n = y->gg.g.n->n;
    y->gg.g.n = &z->gg.g;
  }
}

/* FUNC(zx_ac_Password_ADD_Generation) */

void zx_ac_Password_ADD_Generation(struct zx_ac_Password_s* x, int n, struct zx_ac_Generation_s* z)
{
  struct zx_ac_Generation_s* y;
  if (!x || !z) return;
  switch (n) {
  case 0:
  add_to_start:
    z->gg.g.n = &x->Generation->gg.g;
    x->Generation = z;
    return;
  case -1:
    y = x->Generation;
    if (!y) goto add_to_start;
    for (; y->gg.g.n; y = (struct zx_ac_Generation_s*)y->gg.g.n) ;
    break;
  default:
    for (y = x->Generation; n > 1 && y; --n, y = (struct zx_ac_Generation_s*)y->gg.g.n) ;
    if (!y) return;
  }
  z->gg.g.n = y->gg.g.n;
  y->gg.g.n = &z->gg.g;
}

/* FUNC(zx_ac_Password_DEL_Generation) */

void zx_ac_Password_DEL_Generation(struct zx_ac_Password_s* x, int n)
{
  struct zx_ac_Generation_s* y;
  if (!x) return;
  switch (n) {
  case 0:
    x->Generation = (struct zx_ac_Generation_s*)x->Generation->gg.g.n;
    return;
  case -1:
    y = (struct zx_ac_Generation_s*)x->Generation;
    if (!y) return;
    for (; y->gg.g.n; y = (struct zx_ac_Generation_s*)y->gg.g.n) ;
    break;
  default:
    for (y = x->Generation; n > 1 && y->gg.g.n; --n, y = (struct zx_ac_Generation_s*)y->gg.g.n) ;
    if (!y->gg.g.n) return;
  }
  y->gg.g.n = y->gg.g.n->n;
}

#endif



#ifdef ZX_ENA_GETPUT

/* FUNC(zx_ac_Password_NUM_Extension) */

int zx_ac_Password_NUM_Extension(struct zx_ac_Password_s* x)
{
  struct zx_ac_Extension_s* y;
  int n = 0;
  if (!x) return 0;
  for (y = x->Extension; y; ++n, y = (struct zx_ac_Extension_s*)y->gg.g.n) ;
  return n;
}

/* FUNC(zx_ac_Password_GET_Extension) */

struct zx_ac_Extension_s* zx_ac_Password_GET_Extension(struct zx_ac_Password_s* x, int n)
{
  struct zx_ac_Extension_s* y;
  if (!x) return 0;
  for (y = x->Extension; n>=0 && y; --n, y = (struct zx_ac_Extension_s*)y->gg.g.n) ;
  return y;
}

/* FUNC(zx_ac_Password_POP_Extension) */

struct zx_ac_Extension_s* zx_ac_Password_POP_Extension(struct zx_ac_Password_s* x)
{
  struct zx_ac_Extension_s* y;
  if (!x) return 0;
  y = x->Extension;
  if (y)
    x->Extension = (struct zx_ac_Extension_s*)y->gg.g.n;
  return y;
}

/* FUNC(zx_ac_Password_PUSH_Extension) */

void zx_ac_Password_PUSH_Extension(struct zx_ac_Password_s* x, struct zx_ac_Extension_s* z)
{
  if (!x || !z) return;
  z->gg.g.n = &x->Extension->gg.g;
  x->Extension = z;
}

/* FUNC(zx_ac_Password_REV_Extension) */

void zx_ac_Password_REV_Extension(struct zx_ac_Password_s* x)
{
  struct zx_ac_Extension_s* nxt;
  struct zx_ac_Extension_s* y;
  if (!x) return;
  y = x->Extension;
  if (!y) return;
  x->Extension = 0;
  while (y) {
    nxt = (struct zx_ac_Extension_s*)y->gg.g.n;
    y->gg.g.n = &x->Extension->gg.g;
    x->Extension = y;
    y = nxt;
  }
}

/* FUNC(zx_ac_Password_PUT_Extension) */

void zx_ac_Password_PUT_Extension(struct zx_ac_Password_s* x, int n, struct zx_ac_Extension_s* z)
{
  struct zx_ac_Extension_s* y;
  if (!x || !z) return;
  y = x->Extension;
  if (!y) return;
  switch (n) {
  case 0:
    z->gg.g.n = y->gg.g.n;
    x->Extension = z;
    return;
  default:
    for (; n > 1 && y->gg.g.n; --n, y = (struct zx_ac_Extension_s*)y->gg.g.n) ;
    if (!y->gg.g.n) return;
    z->gg.g.n = y->gg.g.n->n;
    y->gg.g.n = &z->gg.g;
  }
}

/* FUNC(zx_ac_Password_ADD_Extension) */

void zx_ac_Password_ADD_Extension(struct zx_ac_Password_s* x, int n, struct zx_ac_Extension_s* z)
{
  struct zx_ac_Extension_s* y;
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
    for (; y->gg.g.n; y = (struct zx_ac_Extension_s*)y->gg.g.n) ;
    break;
  default:
    for (y = x->Extension; n > 1 && y; --n, y = (struct zx_ac_Extension_s*)y->gg.g.n) ;
    if (!y) return;
  }
  z->gg.g.n = y->gg.g.n;
  y->gg.g.n = &z->gg.g;
}

/* FUNC(zx_ac_Password_DEL_Extension) */

void zx_ac_Password_DEL_Extension(struct zx_ac_Password_s* x, int n)
{
  struct zx_ac_Extension_s* y;
  if (!x) return;
  switch (n) {
  case 0:
    x->Extension = (struct zx_ac_Extension_s*)x->Extension->gg.g.n;
    return;
  case -1:
    y = (struct zx_ac_Extension_s*)x->Extension;
    if (!y) return;
    for (; y->gg.g.n; y = (struct zx_ac_Extension_s*)y->gg.g.n) ;
    break;
  default:
    for (y = x->Extension; n > 1 && y->gg.g.n; --n, y = (struct zx_ac_Extension_s*)y->gg.g.n) ;
    if (!y->gg.g.n) return;
  }
  y->gg.g.n = y->gg.g.n->n;
}

#endif






/* FUNC(zx_ac_PhysicalVerification_GET_credentialLevel) */
struct zx_str* zx_ac_PhysicalVerification_GET_credentialLevel(struct zx_ac_PhysicalVerification_s* x) { return x->credentialLevel; }
/* FUNC(zx_ac_PhysicalVerification_PUT_credentialLevel) */
void zx_ac_PhysicalVerification_PUT_credentialLevel(struct zx_ac_PhysicalVerification_s* x, struct zx_str* y) { x->credentialLevel = y; }







#ifdef ZX_ENA_GETPUT

/* FUNC(zx_ac_PreviousSession_NUM_Extension) */

int zx_ac_PreviousSession_NUM_Extension(struct zx_ac_PreviousSession_s* x)
{
  struct zx_ac_Extension_s* y;
  int n = 0;
  if (!x) return 0;
  for (y = x->Extension; y; ++n, y = (struct zx_ac_Extension_s*)y->gg.g.n) ;
  return n;
}

/* FUNC(zx_ac_PreviousSession_GET_Extension) */

struct zx_ac_Extension_s* zx_ac_PreviousSession_GET_Extension(struct zx_ac_PreviousSession_s* x, int n)
{
  struct zx_ac_Extension_s* y;
  if (!x) return 0;
  for (y = x->Extension; n>=0 && y; --n, y = (struct zx_ac_Extension_s*)y->gg.g.n) ;
  return y;
}

/* FUNC(zx_ac_PreviousSession_POP_Extension) */

struct zx_ac_Extension_s* zx_ac_PreviousSession_POP_Extension(struct zx_ac_PreviousSession_s* x)
{
  struct zx_ac_Extension_s* y;
  if (!x) return 0;
  y = x->Extension;
  if (y)
    x->Extension = (struct zx_ac_Extension_s*)y->gg.g.n;
  return y;
}

/* FUNC(zx_ac_PreviousSession_PUSH_Extension) */

void zx_ac_PreviousSession_PUSH_Extension(struct zx_ac_PreviousSession_s* x, struct zx_ac_Extension_s* z)
{
  if (!x || !z) return;
  z->gg.g.n = &x->Extension->gg.g;
  x->Extension = z;
}

/* FUNC(zx_ac_PreviousSession_REV_Extension) */

void zx_ac_PreviousSession_REV_Extension(struct zx_ac_PreviousSession_s* x)
{
  struct zx_ac_Extension_s* nxt;
  struct zx_ac_Extension_s* y;
  if (!x) return;
  y = x->Extension;
  if (!y) return;
  x->Extension = 0;
  while (y) {
    nxt = (struct zx_ac_Extension_s*)y->gg.g.n;
    y->gg.g.n = &x->Extension->gg.g;
    x->Extension = y;
    y = nxt;
  }
}

/* FUNC(zx_ac_PreviousSession_PUT_Extension) */

void zx_ac_PreviousSession_PUT_Extension(struct zx_ac_PreviousSession_s* x, int n, struct zx_ac_Extension_s* z)
{
  struct zx_ac_Extension_s* y;
  if (!x || !z) return;
  y = x->Extension;
  if (!y) return;
  switch (n) {
  case 0:
    z->gg.g.n = y->gg.g.n;
    x->Extension = z;
    return;
  default:
    for (; n > 1 && y->gg.g.n; --n, y = (struct zx_ac_Extension_s*)y->gg.g.n) ;
    if (!y->gg.g.n) return;
    z->gg.g.n = y->gg.g.n->n;
    y->gg.g.n = &z->gg.g;
  }
}

/* FUNC(zx_ac_PreviousSession_ADD_Extension) */

void zx_ac_PreviousSession_ADD_Extension(struct zx_ac_PreviousSession_s* x, int n, struct zx_ac_Extension_s* z)
{
  struct zx_ac_Extension_s* y;
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
    for (; y->gg.g.n; y = (struct zx_ac_Extension_s*)y->gg.g.n) ;
    break;
  default:
    for (y = x->Extension; n > 1 && y; --n, y = (struct zx_ac_Extension_s*)y->gg.g.n) ;
    if (!y) return;
  }
  z->gg.g.n = y->gg.g.n;
  y->gg.g.n = &z->gg.g;
}

/* FUNC(zx_ac_PreviousSession_DEL_Extension) */

void zx_ac_PreviousSession_DEL_Extension(struct zx_ac_PreviousSession_s* x, int n)
{
  struct zx_ac_Extension_s* y;
  if (!x) return;
  switch (n) {
  case 0:
    x->Extension = (struct zx_ac_Extension_s*)x->Extension->gg.g.n;
    return;
  case -1:
    y = (struct zx_ac_Extension_s*)x->Extension;
    if (!y) return;
    for (; y->gg.g.n; y = (struct zx_ac_Extension_s*)y->gg.g.n) ;
    break;
  default:
    for (y = x->Extension; n > 1 && y->gg.g.n; --n, y = (struct zx_ac_Extension_s*)y->gg.g.n) ;
    if (!y->gg.g.n) return;
  }
  y->gg.g.n = y->gg.g.n->n;
}

#endif








#ifdef ZX_ENA_GETPUT

/* FUNC(zx_ac_PrincipalAuthenticationMechanism_NUM_Password) */

int zx_ac_PrincipalAuthenticationMechanism_NUM_Password(struct zx_ac_PrincipalAuthenticationMechanism_s* x)
{
  struct zx_ac_Password_s* y;
  int n = 0;
  if (!x) return 0;
  for (y = x->Password; y; ++n, y = (struct zx_ac_Password_s*)y->gg.g.n) ;
  return n;
}

/* FUNC(zx_ac_PrincipalAuthenticationMechanism_GET_Password) */

struct zx_ac_Password_s* zx_ac_PrincipalAuthenticationMechanism_GET_Password(struct zx_ac_PrincipalAuthenticationMechanism_s* x, int n)
{
  struct zx_ac_Password_s* y;
  if (!x) return 0;
  for (y = x->Password; n>=0 && y; --n, y = (struct zx_ac_Password_s*)y->gg.g.n) ;
  return y;
}

/* FUNC(zx_ac_PrincipalAuthenticationMechanism_POP_Password) */

struct zx_ac_Password_s* zx_ac_PrincipalAuthenticationMechanism_POP_Password(struct zx_ac_PrincipalAuthenticationMechanism_s* x)
{
  struct zx_ac_Password_s* y;
  if (!x) return 0;
  y = x->Password;
  if (y)
    x->Password = (struct zx_ac_Password_s*)y->gg.g.n;
  return y;
}

/* FUNC(zx_ac_PrincipalAuthenticationMechanism_PUSH_Password) */

void zx_ac_PrincipalAuthenticationMechanism_PUSH_Password(struct zx_ac_PrincipalAuthenticationMechanism_s* x, struct zx_ac_Password_s* z)
{
  if (!x || !z) return;
  z->gg.g.n = &x->Password->gg.g;
  x->Password = z;
}

/* FUNC(zx_ac_PrincipalAuthenticationMechanism_REV_Password) */

void zx_ac_PrincipalAuthenticationMechanism_REV_Password(struct zx_ac_PrincipalAuthenticationMechanism_s* x)
{
  struct zx_ac_Password_s* nxt;
  struct zx_ac_Password_s* y;
  if (!x) return;
  y = x->Password;
  if (!y) return;
  x->Password = 0;
  while (y) {
    nxt = (struct zx_ac_Password_s*)y->gg.g.n;
    y->gg.g.n = &x->Password->gg.g;
    x->Password = y;
    y = nxt;
  }
}

/* FUNC(zx_ac_PrincipalAuthenticationMechanism_PUT_Password) */

void zx_ac_PrincipalAuthenticationMechanism_PUT_Password(struct zx_ac_PrincipalAuthenticationMechanism_s* x, int n, struct zx_ac_Password_s* z)
{
  struct zx_ac_Password_s* y;
  if (!x || !z) return;
  y = x->Password;
  if (!y) return;
  switch (n) {
  case 0:
    z->gg.g.n = y->gg.g.n;
    x->Password = z;
    return;
  default:
    for (; n > 1 && y->gg.g.n; --n, y = (struct zx_ac_Password_s*)y->gg.g.n) ;
    if (!y->gg.g.n) return;
    z->gg.g.n = y->gg.g.n->n;
    y->gg.g.n = &z->gg.g;
  }
}

/* FUNC(zx_ac_PrincipalAuthenticationMechanism_ADD_Password) */

void zx_ac_PrincipalAuthenticationMechanism_ADD_Password(struct zx_ac_PrincipalAuthenticationMechanism_s* x, int n, struct zx_ac_Password_s* z)
{
  struct zx_ac_Password_s* y;
  if (!x || !z) return;
  switch (n) {
  case 0:
  add_to_start:
    z->gg.g.n = &x->Password->gg.g;
    x->Password = z;
    return;
  case -1:
    y = x->Password;
    if (!y) goto add_to_start;
    for (; y->gg.g.n; y = (struct zx_ac_Password_s*)y->gg.g.n) ;
    break;
  default:
    for (y = x->Password; n > 1 && y; --n, y = (struct zx_ac_Password_s*)y->gg.g.n) ;
    if (!y) return;
  }
  z->gg.g.n = y->gg.g.n;
  y->gg.g.n = &z->gg.g;
}

/* FUNC(zx_ac_PrincipalAuthenticationMechanism_DEL_Password) */

void zx_ac_PrincipalAuthenticationMechanism_DEL_Password(struct zx_ac_PrincipalAuthenticationMechanism_s* x, int n)
{
  struct zx_ac_Password_s* y;
  if (!x) return;
  switch (n) {
  case 0:
    x->Password = (struct zx_ac_Password_s*)x->Password->gg.g.n;
    return;
  case -1:
    y = (struct zx_ac_Password_s*)x->Password;
    if (!y) return;
    for (; y->gg.g.n; y = (struct zx_ac_Password_s*)y->gg.g.n) ;
    break;
  default:
    for (y = x->Password; n > 1 && y->gg.g.n; --n, y = (struct zx_ac_Password_s*)y->gg.g.n) ;
    if (!y->gg.g.n) return;
  }
  y->gg.g.n = y->gg.g.n->n;
}

#endif



#ifdef ZX_ENA_GETPUT

/* FUNC(zx_ac_PrincipalAuthenticationMechanism_NUM_Token) */

int zx_ac_PrincipalAuthenticationMechanism_NUM_Token(struct zx_ac_PrincipalAuthenticationMechanism_s* x)
{
  struct zx_ac_Token_s* y;
  int n = 0;
  if (!x) return 0;
  for (y = x->Token; y; ++n, y = (struct zx_ac_Token_s*)y->gg.g.n) ;
  return n;
}

/* FUNC(zx_ac_PrincipalAuthenticationMechanism_GET_Token) */

struct zx_ac_Token_s* zx_ac_PrincipalAuthenticationMechanism_GET_Token(struct zx_ac_PrincipalAuthenticationMechanism_s* x, int n)
{
  struct zx_ac_Token_s* y;
  if (!x) return 0;
  for (y = x->Token; n>=0 && y; --n, y = (struct zx_ac_Token_s*)y->gg.g.n) ;
  return y;
}

/* FUNC(zx_ac_PrincipalAuthenticationMechanism_POP_Token) */

struct zx_ac_Token_s* zx_ac_PrincipalAuthenticationMechanism_POP_Token(struct zx_ac_PrincipalAuthenticationMechanism_s* x)
{
  struct zx_ac_Token_s* y;
  if (!x) return 0;
  y = x->Token;
  if (y)
    x->Token = (struct zx_ac_Token_s*)y->gg.g.n;
  return y;
}

/* FUNC(zx_ac_PrincipalAuthenticationMechanism_PUSH_Token) */

void zx_ac_PrincipalAuthenticationMechanism_PUSH_Token(struct zx_ac_PrincipalAuthenticationMechanism_s* x, struct zx_ac_Token_s* z)
{
  if (!x || !z) return;
  z->gg.g.n = &x->Token->gg.g;
  x->Token = z;
}

/* FUNC(zx_ac_PrincipalAuthenticationMechanism_REV_Token) */

void zx_ac_PrincipalAuthenticationMechanism_REV_Token(struct zx_ac_PrincipalAuthenticationMechanism_s* x)
{
  struct zx_ac_Token_s* nxt;
  struct zx_ac_Token_s* y;
  if (!x) return;
  y = x->Token;
  if (!y) return;
  x->Token = 0;
  while (y) {
    nxt = (struct zx_ac_Token_s*)y->gg.g.n;
    y->gg.g.n = &x->Token->gg.g;
    x->Token = y;
    y = nxt;
  }
}

/* FUNC(zx_ac_PrincipalAuthenticationMechanism_PUT_Token) */

void zx_ac_PrincipalAuthenticationMechanism_PUT_Token(struct zx_ac_PrincipalAuthenticationMechanism_s* x, int n, struct zx_ac_Token_s* z)
{
  struct zx_ac_Token_s* y;
  if (!x || !z) return;
  y = x->Token;
  if (!y) return;
  switch (n) {
  case 0:
    z->gg.g.n = y->gg.g.n;
    x->Token = z;
    return;
  default:
    for (; n > 1 && y->gg.g.n; --n, y = (struct zx_ac_Token_s*)y->gg.g.n) ;
    if (!y->gg.g.n) return;
    z->gg.g.n = y->gg.g.n->n;
    y->gg.g.n = &z->gg.g;
  }
}

/* FUNC(zx_ac_PrincipalAuthenticationMechanism_ADD_Token) */

void zx_ac_PrincipalAuthenticationMechanism_ADD_Token(struct zx_ac_PrincipalAuthenticationMechanism_s* x, int n, struct zx_ac_Token_s* z)
{
  struct zx_ac_Token_s* y;
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
    for (; y->gg.g.n; y = (struct zx_ac_Token_s*)y->gg.g.n) ;
    break;
  default:
    for (y = x->Token; n > 1 && y; --n, y = (struct zx_ac_Token_s*)y->gg.g.n) ;
    if (!y) return;
  }
  z->gg.g.n = y->gg.g.n;
  y->gg.g.n = &z->gg.g;
}

/* FUNC(zx_ac_PrincipalAuthenticationMechanism_DEL_Token) */

void zx_ac_PrincipalAuthenticationMechanism_DEL_Token(struct zx_ac_PrincipalAuthenticationMechanism_s* x, int n)
{
  struct zx_ac_Token_s* y;
  if (!x) return;
  switch (n) {
  case 0:
    x->Token = (struct zx_ac_Token_s*)x->Token->gg.g.n;
    return;
  case -1:
    y = (struct zx_ac_Token_s*)x->Token;
    if (!y) return;
    for (; y->gg.g.n; y = (struct zx_ac_Token_s*)y->gg.g.n) ;
    break;
  default:
    for (y = x->Token; n > 1 && y->gg.g.n; --n, y = (struct zx_ac_Token_s*)y->gg.g.n) ;
    if (!y->gg.g.n) return;
  }
  y->gg.g.n = y->gg.g.n->n;
}

#endif



#ifdef ZX_ENA_GETPUT

/* FUNC(zx_ac_PrincipalAuthenticationMechanism_NUM_Smartcard) */

int zx_ac_PrincipalAuthenticationMechanism_NUM_Smartcard(struct zx_ac_PrincipalAuthenticationMechanism_s* x)
{
  struct zx_ac_Smartcard_s* y;
  int n = 0;
  if (!x) return 0;
  for (y = x->Smartcard; y; ++n, y = (struct zx_ac_Smartcard_s*)y->gg.g.n) ;
  return n;
}

/* FUNC(zx_ac_PrincipalAuthenticationMechanism_GET_Smartcard) */

struct zx_ac_Smartcard_s* zx_ac_PrincipalAuthenticationMechanism_GET_Smartcard(struct zx_ac_PrincipalAuthenticationMechanism_s* x, int n)
{
  struct zx_ac_Smartcard_s* y;
  if (!x) return 0;
  for (y = x->Smartcard; n>=0 && y; --n, y = (struct zx_ac_Smartcard_s*)y->gg.g.n) ;
  return y;
}

/* FUNC(zx_ac_PrincipalAuthenticationMechanism_POP_Smartcard) */

struct zx_ac_Smartcard_s* zx_ac_PrincipalAuthenticationMechanism_POP_Smartcard(struct zx_ac_PrincipalAuthenticationMechanism_s* x)
{
  struct zx_ac_Smartcard_s* y;
  if (!x) return 0;
  y = x->Smartcard;
  if (y)
    x->Smartcard = (struct zx_ac_Smartcard_s*)y->gg.g.n;
  return y;
}

/* FUNC(zx_ac_PrincipalAuthenticationMechanism_PUSH_Smartcard) */

void zx_ac_PrincipalAuthenticationMechanism_PUSH_Smartcard(struct zx_ac_PrincipalAuthenticationMechanism_s* x, struct zx_ac_Smartcard_s* z)
{
  if (!x || !z) return;
  z->gg.g.n = &x->Smartcard->gg.g;
  x->Smartcard = z;
}

/* FUNC(zx_ac_PrincipalAuthenticationMechanism_REV_Smartcard) */

void zx_ac_PrincipalAuthenticationMechanism_REV_Smartcard(struct zx_ac_PrincipalAuthenticationMechanism_s* x)
{
  struct zx_ac_Smartcard_s* nxt;
  struct zx_ac_Smartcard_s* y;
  if (!x) return;
  y = x->Smartcard;
  if (!y) return;
  x->Smartcard = 0;
  while (y) {
    nxt = (struct zx_ac_Smartcard_s*)y->gg.g.n;
    y->gg.g.n = &x->Smartcard->gg.g;
    x->Smartcard = y;
    y = nxt;
  }
}

/* FUNC(zx_ac_PrincipalAuthenticationMechanism_PUT_Smartcard) */

void zx_ac_PrincipalAuthenticationMechanism_PUT_Smartcard(struct zx_ac_PrincipalAuthenticationMechanism_s* x, int n, struct zx_ac_Smartcard_s* z)
{
  struct zx_ac_Smartcard_s* y;
  if (!x || !z) return;
  y = x->Smartcard;
  if (!y) return;
  switch (n) {
  case 0:
    z->gg.g.n = y->gg.g.n;
    x->Smartcard = z;
    return;
  default:
    for (; n > 1 && y->gg.g.n; --n, y = (struct zx_ac_Smartcard_s*)y->gg.g.n) ;
    if (!y->gg.g.n) return;
    z->gg.g.n = y->gg.g.n->n;
    y->gg.g.n = &z->gg.g;
  }
}

/* FUNC(zx_ac_PrincipalAuthenticationMechanism_ADD_Smartcard) */

void zx_ac_PrincipalAuthenticationMechanism_ADD_Smartcard(struct zx_ac_PrincipalAuthenticationMechanism_s* x, int n, struct zx_ac_Smartcard_s* z)
{
  struct zx_ac_Smartcard_s* y;
  if (!x || !z) return;
  switch (n) {
  case 0:
  add_to_start:
    z->gg.g.n = &x->Smartcard->gg.g;
    x->Smartcard = z;
    return;
  case -1:
    y = x->Smartcard;
    if (!y) goto add_to_start;
    for (; y->gg.g.n; y = (struct zx_ac_Smartcard_s*)y->gg.g.n) ;
    break;
  default:
    for (y = x->Smartcard; n > 1 && y; --n, y = (struct zx_ac_Smartcard_s*)y->gg.g.n) ;
    if (!y) return;
  }
  z->gg.g.n = y->gg.g.n;
  y->gg.g.n = &z->gg.g;
}

/* FUNC(zx_ac_PrincipalAuthenticationMechanism_DEL_Smartcard) */

void zx_ac_PrincipalAuthenticationMechanism_DEL_Smartcard(struct zx_ac_PrincipalAuthenticationMechanism_s* x, int n)
{
  struct zx_ac_Smartcard_s* y;
  if (!x) return;
  switch (n) {
  case 0:
    x->Smartcard = (struct zx_ac_Smartcard_s*)x->Smartcard->gg.g.n;
    return;
  case -1:
    y = (struct zx_ac_Smartcard_s*)x->Smartcard;
    if (!y) return;
    for (; y->gg.g.n; y = (struct zx_ac_Smartcard_s*)y->gg.g.n) ;
    break;
  default:
    for (y = x->Smartcard; n > 1 && y->gg.g.n; --n, y = (struct zx_ac_Smartcard_s*)y->gg.g.n) ;
    if (!y->gg.g.n) return;
  }
  y->gg.g.n = y->gg.g.n->n;
}

#endif



#ifdef ZX_ENA_GETPUT

/* FUNC(zx_ac_PrincipalAuthenticationMechanism_NUM_ActivationPin) */

int zx_ac_PrincipalAuthenticationMechanism_NUM_ActivationPin(struct zx_ac_PrincipalAuthenticationMechanism_s* x)
{
  struct zx_ac_ActivationPin_s* y;
  int n = 0;
  if (!x) return 0;
  for (y = x->ActivationPin; y; ++n, y = (struct zx_ac_ActivationPin_s*)y->gg.g.n) ;
  return n;
}

/* FUNC(zx_ac_PrincipalAuthenticationMechanism_GET_ActivationPin) */

struct zx_ac_ActivationPin_s* zx_ac_PrincipalAuthenticationMechanism_GET_ActivationPin(struct zx_ac_PrincipalAuthenticationMechanism_s* x, int n)
{
  struct zx_ac_ActivationPin_s* y;
  if (!x) return 0;
  for (y = x->ActivationPin; n>=0 && y; --n, y = (struct zx_ac_ActivationPin_s*)y->gg.g.n) ;
  return y;
}

/* FUNC(zx_ac_PrincipalAuthenticationMechanism_POP_ActivationPin) */

struct zx_ac_ActivationPin_s* zx_ac_PrincipalAuthenticationMechanism_POP_ActivationPin(struct zx_ac_PrincipalAuthenticationMechanism_s* x)
{
  struct zx_ac_ActivationPin_s* y;
  if (!x) return 0;
  y = x->ActivationPin;
  if (y)
    x->ActivationPin = (struct zx_ac_ActivationPin_s*)y->gg.g.n;
  return y;
}

/* FUNC(zx_ac_PrincipalAuthenticationMechanism_PUSH_ActivationPin) */

void zx_ac_PrincipalAuthenticationMechanism_PUSH_ActivationPin(struct zx_ac_PrincipalAuthenticationMechanism_s* x, struct zx_ac_ActivationPin_s* z)
{
  if (!x || !z) return;
  z->gg.g.n = &x->ActivationPin->gg.g;
  x->ActivationPin = z;
}

/* FUNC(zx_ac_PrincipalAuthenticationMechanism_REV_ActivationPin) */

void zx_ac_PrincipalAuthenticationMechanism_REV_ActivationPin(struct zx_ac_PrincipalAuthenticationMechanism_s* x)
{
  struct zx_ac_ActivationPin_s* nxt;
  struct zx_ac_ActivationPin_s* y;
  if (!x) return;
  y = x->ActivationPin;
  if (!y) return;
  x->ActivationPin = 0;
  while (y) {
    nxt = (struct zx_ac_ActivationPin_s*)y->gg.g.n;
    y->gg.g.n = &x->ActivationPin->gg.g;
    x->ActivationPin = y;
    y = nxt;
  }
}

/* FUNC(zx_ac_PrincipalAuthenticationMechanism_PUT_ActivationPin) */

void zx_ac_PrincipalAuthenticationMechanism_PUT_ActivationPin(struct zx_ac_PrincipalAuthenticationMechanism_s* x, int n, struct zx_ac_ActivationPin_s* z)
{
  struct zx_ac_ActivationPin_s* y;
  if (!x || !z) return;
  y = x->ActivationPin;
  if (!y) return;
  switch (n) {
  case 0:
    z->gg.g.n = y->gg.g.n;
    x->ActivationPin = z;
    return;
  default:
    for (; n > 1 && y->gg.g.n; --n, y = (struct zx_ac_ActivationPin_s*)y->gg.g.n) ;
    if (!y->gg.g.n) return;
    z->gg.g.n = y->gg.g.n->n;
    y->gg.g.n = &z->gg.g;
  }
}

/* FUNC(zx_ac_PrincipalAuthenticationMechanism_ADD_ActivationPin) */

void zx_ac_PrincipalAuthenticationMechanism_ADD_ActivationPin(struct zx_ac_PrincipalAuthenticationMechanism_s* x, int n, struct zx_ac_ActivationPin_s* z)
{
  struct zx_ac_ActivationPin_s* y;
  if (!x || !z) return;
  switch (n) {
  case 0:
  add_to_start:
    z->gg.g.n = &x->ActivationPin->gg.g;
    x->ActivationPin = z;
    return;
  case -1:
    y = x->ActivationPin;
    if (!y) goto add_to_start;
    for (; y->gg.g.n; y = (struct zx_ac_ActivationPin_s*)y->gg.g.n) ;
    break;
  default:
    for (y = x->ActivationPin; n > 1 && y; --n, y = (struct zx_ac_ActivationPin_s*)y->gg.g.n) ;
    if (!y) return;
  }
  z->gg.g.n = y->gg.g.n;
  y->gg.g.n = &z->gg.g;
}

/* FUNC(zx_ac_PrincipalAuthenticationMechanism_DEL_ActivationPin) */

void zx_ac_PrincipalAuthenticationMechanism_DEL_ActivationPin(struct zx_ac_PrincipalAuthenticationMechanism_s* x, int n)
{
  struct zx_ac_ActivationPin_s* y;
  if (!x) return;
  switch (n) {
  case 0:
    x->ActivationPin = (struct zx_ac_ActivationPin_s*)x->ActivationPin->gg.g.n;
    return;
  case -1:
    y = (struct zx_ac_ActivationPin_s*)x->ActivationPin;
    if (!y) return;
    for (; y->gg.g.n; y = (struct zx_ac_ActivationPin_s*)y->gg.g.n) ;
    break;
  default:
    for (y = x->ActivationPin; n > 1 && y->gg.g.n; --n, y = (struct zx_ac_ActivationPin_s*)y->gg.g.n) ;
    if (!y->gg.g.n) return;
  }
  y->gg.g.n = y->gg.g.n->n;
}

#endif



#ifdef ZX_ENA_GETPUT

/* FUNC(zx_ac_PrincipalAuthenticationMechanism_NUM_Extension) */

int zx_ac_PrincipalAuthenticationMechanism_NUM_Extension(struct zx_ac_PrincipalAuthenticationMechanism_s* x)
{
  struct zx_ac_Extension_s* y;
  int n = 0;
  if (!x) return 0;
  for (y = x->Extension; y; ++n, y = (struct zx_ac_Extension_s*)y->gg.g.n) ;
  return n;
}

/* FUNC(zx_ac_PrincipalAuthenticationMechanism_GET_Extension) */

struct zx_ac_Extension_s* zx_ac_PrincipalAuthenticationMechanism_GET_Extension(struct zx_ac_PrincipalAuthenticationMechanism_s* x, int n)
{
  struct zx_ac_Extension_s* y;
  if (!x) return 0;
  for (y = x->Extension; n>=0 && y; --n, y = (struct zx_ac_Extension_s*)y->gg.g.n) ;
  return y;
}

/* FUNC(zx_ac_PrincipalAuthenticationMechanism_POP_Extension) */

struct zx_ac_Extension_s* zx_ac_PrincipalAuthenticationMechanism_POP_Extension(struct zx_ac_PrincipalAuthenticationMechanism_s* x)
{
  struct zx_ac_Extension_s* y;
  if (!x) return 0;
  y = x->Extension;
  if (y)
    x->Extension = (struct zx_ac_Extension_s*)y->gg.g.n;
  return y;
}

/* FUNC(zx_ac_PrincipalAuthenticationMechanism_PUSH_Extension) */

void zx_ac_PrincipalAuthenticationMechanism_PUSH_Extension(struct zx_ac_PrincipalAuthenticationMechanism_s* x, struct zx_ac_Extension_s* z)
{
  if (!x || !z) return;
  z->gg.g.n = &x->Extension->gg.g;
  x->Extension = z;
}

/* FUNC(zx_ac_PrincipalAuthenticationMechanism_REV_Extension) */

void zx_ac_PrincipalAuthenticationMechanism_REV_Extension(struct zx_ac_PrincipalAuthenticationMechanism_s* x)
{
  struct zx_ac_Extension_s* nxt;
  struct zx_ac_Extension_s* y;
  if (!x) return;
  y = x->Extension;
  if (!y) return;
  x->Extension = 0;
  while (y) {
    nxt = (struct zx_ac_Extension_s*)y->gg.g.n;
    y->gg.g.n = &x->Extension->gg.g;
    x->Extension = y;
    y = nxt;
  }
}

/* FUNC(zx_ac_PrincipalAuthenticationMechanism_PUT_Extension) */

void zx_ac_PrincipalAuthenticationMechanism_PUT_Extension(struct zx_ac_PrincipalAuthenticationMechanism_s* x, int n, struct zx_ac_Extension_s* z)
{
  struct zx_ac_Extension_s* y;
  if (!x || !z) return;
  y = x->Extension;
  if (!y) return;
  switch (n) {
  case 0:
    z->gg.g.n = y->gg.g.n;
    x->Extension = z;
    return;
  default:
    for (; n > 1 && y->gg.g.n; --n, y = (struct zx_ac_Extension_s*)y->gg.g.n) ;
    if (!y->gg.g.n) return;
    z->gg.g.n = y->gg.g.n->n;
    y->gg.g.n = &z->gg.g;
  }
}

/* FUNC(zx_ac_PrincipalAuthenticationMechanism_ADD_Extension) */

void zx_ac_PrincipalAuthenticationMechanism_ADD_Extension(struct zx_ac_PrincipalAuthenticationMechanism_s* x, int n, struct zx_ac_Extension_s* z)
{
  struct zx_ac_Extension_s* y;
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
    for (; y->gg.g.n; y = (struct zx_ac_Extension_s*)y->gg.g.n) ;
    break;
  default:
    for (y = x->Extension; n > 1 && y; --n, y = (struct zx_ac_Extension_s*)y->gg.g.n) ;
    if (!y) return;
  }
  z->gg.g.n = y->gg.g.n;
  y->gg.g.n = &z->gg.g;
}

/* FUNC(zx_ac_PrincipalAuthenticationMechanism_DEL_Extension) */

void zx_ac_PrincipalAuthenticationMechanism_DEL_Extension(struct zx_ac_PrincipalAuthenticationMechanism_s* x, int n)
{
  struct zx_ac_Extension_s* y;
  if (!x) return;
  switch (n) {
  case 0:
    x->Extension = (struct zx_ac_Extension_s*)x->Extension->gg.g.n;
    return;
  case -1:
    y = (struct zx_ac_Extension_s*)x->Extension;
    if (!y) return;
    for (; y->gg.g.n; y = (struct zx_ac_Extension_s*)y->gg.g.n) ;
    break;
  default:
    for (y = x->Extension; n > 1 && y->gg.g.n; --n, y = (struct zx_ac_Extension_s*)y->gg.g.n) ;
    if (!y->gg.g.n) return;
  }
  y->gg.g.n = y->gg.g.n->n;
}

#endif








#ifdef ZX_ENA_GETPUT

/* FUNC(zx_ac_PrivateKeyProtection_NUM_KeyActivation) */

int zx_ac_PrivateKeyProtection_NUM_KeyActivation(struct zx_ac_PrivateKeyProtection_s* x)
{
  struct zx_ac_KeyActivation_s* y;
  int n = 0;
  if (!x) return 0;
  for (y = x->KeyActivation; y; ++n, y = (struct zx_ac_KeyActivation_s*)y->gg.g.n) ;
  return n;
}

/* FUNC(zx_ac_PrivateKeyProtection_GET_KeyActivation) */

struct zx_ac_KeyActivation_s* zx_ac_PrivateKeyProtection_GET_KeyActivation(struct zx_ac_PrivateKeyProtection_s* x, int n)
{
  struct zx_ac_KeyActivation_s* y;
  if (!x) return 0;
  for (y = x->KeyActivation; n>=0 && y; --n, y = (struct zx_ac_KeyActivation_s*)y->gg.g.n) ;
  return y;
}

/* FUNC(zx_ac_PrivateKeyProtection_POP_KeyActivation) */

struct zx_ac_KeyActivation_s* zx_ac_PrivateKeyProtection_POP_KeyActivation(struct zx_ac_PrivateKeyProtection_s* x)
{
  struct zx_ac_KeyActivation_s* y;
  if (!x) return 0;
  y = x->KeyActivation;
  if (y)
    x->KeyActivation = (struct zx_ac_KeyActivation_s*)y->gg.g.n;
  return y;
}

/* FUNC(zx_ac_PrivateKeyProtection_PUSH_KeyActivation) */

void zx_ac_PrivateKeyProtection_PUSH_KeyActivation(struct zx_ac_PrivateKeyProtection_s* x, struct zx_ac_KeyActivation_s* z)
{
  if (!x || !z) return;
  z->gg.g.n = &x->KeyActivation->gg.g;
  x->KeyActivation = z;
}

/* FUNC(zx_ac_PrivateKeyProtection_REV_KeyActivation) */

void zx_ac_PrivateKeyProtection_REV_KeyActivation(struct zx_ac_PrivateKeyProtection_s* x)
{
  struct zx_ac_KeyActivation_s* nxt;
  struct zx_ac_KeyActivation_s* y;
  if (!x) return;
  y = x->KeyActivation;
  if (!y) return;
  x->KeyActivation = 0;
  while (y) {
    nxt = (struct zx_ac_KeyActivation_s*)y->gg.g.n;
    y->gg.g.n = &x->KeyActivation->gg.g;
    x->KeyActivation = y;
    y = nxt;
  }
}

/* FUNC(zx_ac_PrivateKeyProtection_PUT_KeyActivation) */

void zx_ac_PrivateKeyProtection_PUT_KeyActivation(struct zx_ac_PrivateKeyProtection_s* x, int n, struct zx_ac_KeyActivation_s* z)
{
  struct zx_ac_KeyActivation_s* y;
  if (!x || !z) return;
  y = x->KeyActivation;
  if (!y) return;
  switch (n) {
  case 0:
    z->gg.g.n = y->gg.g.n;
    x->KeyActivation = z;
    return;
  default:
    for (; n > 1 && y->gg.g.n; --n, y = (struct zx_ac_KeyActivation_s*)y->gg.g.n) ;
    if (!y->gg.g.n) return;
    z->gg.g.n = y->gg.g.n->n;
    y->gg.g.n = &z->gg.g;
  }
}

/* FUNC(zx_ac_PrivateKeyProtection_ADD_KeyActivation) */

void zx_ac_PrivateKeyProtection_ADD_KeyActivation(struct zx_ac_PrivateKeyProtection_s* x, int n, struct zx_ac_KeyActivation_s* z)
{
  struct zx_ac_KeyActivation_s* y;
  if (!x || !z) return;
  switch (n) {
  case 0:
  add_to_start:
    z->gg.g.n = &x->KeyActivation->gg.g;
    x->KeyActivation = z;
    return;
  case -1:
    y = x->KeyActivation;
    if (!y) goto add_to_start;
    for (; y->gg.g.n; y = (struct zx_ac_KeyActivation_s*)y->gg.g.n) ;
    break;
  default:
    for (y = x->KeyActivation; n > 1 && y; --n, y = (struct zx_ac_KeyActivation_s*)y->gg.g.n) ;
    if (!y) return;
  }
  z->gg.g.n = y->gg.g.n;
  y->gg.g.n = &z->gg.g;
}

/* FUNC(zx_ac_PrivateKeyProtection_DEL_KeyActivation) */

void zx_ac_PrivateKeyProtection_DEL_KeyActivation(struct zx_ac_PrivateKeyProtection_s* x, int n)
{
  struct zx_ac_KeyActivation_s* y;
  if (!x) return;
  switch (n) {
  case 0:
    x->KeyActivation = (struct zx_ac_KeyActivation_s*)x->KeyActivation->gg.g.n;
    return;
  case -1:
    y = (struct zx_ac_KeyActivation_s*)x->KeyActivation;
    if (!y) return;
    for (; y->gg.g.n; y = (struct zx_ac_KeyActivation_s*)y->gg.g.n) ;
    break;
  default:
    for (y = x->KeyActivation; n > 1 && y->gg.g.n; --n, y = (struct zx_ac_KeyActivation_s*)y->gg.g.n) ;
    if (!y->gg.g.n) return;
  }
  y->gg.g.n = y->gg.g.n->n;
}

#endif



#ifdef ZX_ENA_GETPUT

/* FUNC(zx_ac_PrivateKeyProtection_NUM_KeyStorage) */

int zx_ac_PrivateKeyProtection_NUM_KeyStorage(struct zx_ac_PrivateKeyProtection_s* x)
{
  struct zx_ac_KeyStorage_s* y;
  int n = 0;
  if (!x) return 0;
  for (y = x->KeyStorage; y; ++n, y = (struct zx_ac_KeyStorage_s*)y->gg.g.n) ;
  return n;
}

/* FUNC(zx_ac_PrivateKeyProtection_GET_KeyStorage) */

struct zx_ac_KeyStorage_s* zx_ac_PrivateKeyProtection_GET_KeyStorage(struct zx_ac_PrivateKeyProtection_s* x, int n)
{
  struct zx_ac_KeyStorage_s* y;
  if (!x) return 0;
  for (y = x->KeyStorage; n>=0 && y; --n, y = (struct zx_ac_KeyStorage_s*)y->gg.g.n) ;
  return y;
}

/* FUNC(zx_ac_PrivateKeyProtection_POP_KeyStorage) */

struct zx_ac_KeyStorage_s* zx_ac_PrivateKeyProtection_POP_KeyStorage(struct zx_ac_PrivateKeyProtection_s* x)
{
  struct zx_ac_KeyStorage_s* y;
  if (!x) return 0;
  y = x->KeyStorage;
  if (y)
    x->KeyStorage = (struct zx_ac_KeyStorage_s*)y->gg.g.n;
  return y;
}

/* FUNC(zx_ac_PrivateKeyProtection_PUSH_KeyStorage) */

void zx_ac_PrivateKeyProtection_PUSH_KeyStorage(struct zx_ac_PrivateKeyProtection_s* x, struct zx_ac_KeyStorage_s* z)
{
  if (!x || !z) return;
  z->gg.g.n = &x->KeyStorage->gg.g;
  x->KeyStorage = z;
}

/* FUNC(zx_ac_PrivateKeyProtection_REV_KeyStorage) */

void zx_ac_PrivateKeyProtection_REV_KeyStorage(struct zx_ac_PrivateKeyProtection_s* x)
{
  struct zx_ac_KeyStorage_s* nxt;
  struct zx_ac_KeyStorage_s* y;
  if (!x) return;
  y = x->KeyStorage;
  if (!y) return;
  x->KeyStorage = 0;
  while (y) {
    nxt = (struct zx_ac_KeyStorage_s*)y->gg.g.n;
    y->gg.g.n = &x->KeyStorage->gg.g;
    x->KeyStorage = y;
    y = nxt;
  }
}

/* FUNC(zx_ac_PrivateKeyProtection_PUT_KeyStorage) */

void zx_ac_PrivateKeyProtection_PUT_KeyStorage(struct zx_ac_PrivateKeyProtection_s* x, int n, struct zx_ac_KeyStorage_s* z)
{
  struct zx_ac_KeyStorage_s* y;
  if (!x || !z) return;
  y = x->KeyStorage;
  if (!y) return;
  switch (n) {
  case 0:
    z->gg.g.n = y->gg.g.n;
    x->KeyStorage = z;
    return;
  default:
    for (; n > 1 && y->gg.g.n; --n, y = (struct zx_ac_KeyStorage_s*)y->gg.g.n) ;
    if (!y->gg.g.n) return;
    z->gg.g.n = y->gg.g.n->n;
    y->gg.g.n = &z->gg.g;
  }
}

/* FUNC(zx_ac_PrivateKeyProtection_ADD_KeyStorage) */

void zx_ac_PrivateKeyProtection_ADD_KeyStorage(struct zx_ac_PrivateKeyProtection_s* x, int n, struct zx_ac_KeyStorage_s* z)
{
  struct zx_ac_KeyStorage_s* y;
  if (!x || !z) return;
  switch (n) {
  case 0:
  add_to_start:
    z->gg.g.n = &x->KeyStorage->gg.g;
    x->KeyStorage = z;
    return;
  case -1:
    y = x->KeyStorage;
    if (!y) goto add_to_start;
    for (; y->gg.g.n; y = (struct zx_ac_KeyStorage_s*)y->gg.g.n) ;
    break;
  default:
    for (y = x->KeyStorage; n > 1 && y; --n, y = (struct zx_ac_KeyStorage_s*)y->gg.g.n) ;
    if (!y) return;
  }
  z->gg.g.n = y->gg.g.n;
  y->gg.g.n = &z->gg.g;
}

/* FUNC(zx_ac_PrivateKeyProtection_DEL_KeyStorage) */

void zx_ac_PrivateKeyProtection_DEL_KeyStorage(struct zx_ac_PrivateKeyProtection_s* x, int n)
{
  struct zx_ac_KeyStorage_s* y;
  if (!x) return;
  switch (n) {
  case 0:
    x->KeyStorage = (struct zx_ac_KeyStorage_s*)x->KeyStorage->gg.g.n;
    return;
  case -1:
    y = (struct zx_ac_KeyStorage_s*)x->KeyStorage;
    if (!y) return;
    for (; y->gg.g.n; y = (struct zx_ac_KeyStorage_s*)y->gg.g.n) ;
    break;
  default:
    for (y = x->KeyStorage; n > 1 && y->gg.g.n; --n, y = (struct zx_ac_KeyStorage_s*)y->gg.g.n) ;
    if (!y->gg.g.n) return;
  }
  y->gg.g.n = y->gg.g.n->n;
}

#endif



#ifdef ZX_ENA_GETPUT

/* FUNC(zx_ac_PrivateKeyProtection_NUM_KeySharing) */

int zx_ac_PrivateKeyProtection_NUM_KeySharing(struct zx_ac_PrivateKeyProtection_s* x)
{
  struct zx_ac_KeySharing_s* y;
  int n = 0;
  if (!x) return 0;
  for (y = x->KeySharing; y; ++n, y = (struct zx_ac_KeySharing_s*)y->gg.g.n) ;
  return n;
}

/* FUNC(zx_ac_PrivateKeyProtection_GET_KeySharing) */

struct zx_ac_KeySharing_s* zx_ac_PrivateKeyProtection_GET_KeySharing(struct zx_ac_PrivateKeyProtection_s* x, int n)
{
  struct zx_ac_KeySharing_s* y;
  if (!x) return 0;
  for (y = x->KeySharing; n>=0 && y; --n, y = (struct zx_ac_KeySharing_s*)y->gg.g.n) ;
  return y;
}

/* FUNC(zx_ac_PrivateKeyProtection_POP_KeySharing) */

struct zx_ac_KeySharing_s* zx_ac_PrivateKeyProtection_POP_KeySharing(struct zx_ac_PrivateKeyProtection_s* x)
{
  struct zx_ac_KeySharing_s* y;
  if (!x) return 0;
  y = x->KeySharing;
  if (y)
    x->KeySharing = (struct zx_ac_KeySharing_s*)y->gg.g.n;
  return y;
}

/* FUNC(zx_ac_PrivateKeyProtection_PUSH_KeySharing) */

void zx_ac_PrivateKeyProtection_PUSH_KeySharing(struct zx_ac_PrivateKeyProtection_s* x, struct zx_ac_KeySharing_s* z)
{
  if (!x || !z) return;
  z->gg.g.n = &x->KeySharing->gg.g;
  x->KeySharing = z;
}

/* FUNC(zx_ac_PrivateKeyProtection_REV_KeySharing) */

void zx_ac_PrivateKeyProtection_REV_KeySharing(struct zx_ac_PrivateKeyProtection_s* x)
{
  struct zx_ac_KeySharing_s* nxt;
  struct zx_ac_KeySharing_s* y;
  if (!x) return;
  y = x->KeySharing;
  if (!y) return;
  x->KeySharing = 0;
  while (y) {
    nxt = (struct zx_ac_KeySharing_s*)y->gg.g.n;
    y->gg.g.n = &x->KeySharing->gg.g;
    x->KeySharing = y;
    y = nxt;
  }
}

/* FUNC(zx_ac_PrivateKeyProtection_PUT_KeySharing) */

void zx_ac_PrivateKeyProtection_PUT_KeySharing(struct zx_ac_PrivateKeyProtection_s* x, int n, struct zx_ac_KeySharing_s* z)
{
  struct zx_ac_KeySharing_s* y;
  if (!x || !z) return;
  y = x->KeySharing;
  if (!y) return;
  switch (n) {
  case 0:
    z->gg.g.n = y->gg.g.n;
    x->KeySharing = z;
    return;
  default:
    for (; n > 1 && y->gg.g.n; --n, y = (struct zx_ac_KeySharing_s*)y->gg.g.n) ;
    if (!y->gg.g.n) return;
    z->gg.g.n = y->gg.g.n->n;
    y->gg.g.n = &z->gg.g;
  }
}

/* FUNC(zx_ac_PrivateKeyProtection_ADD_KeySharing) */

void zx_ac_PrivateKeyProtection_ADD_KeySharing(struct zx_ac_PrivateKeyProtection_s* x, int n, struct zx_ac_KeySharing_s* z)
{
  struct zx_ac_KeySharing_s* y;
  if (!x || !z) return;
  switch (n) {
  case 0:
  add_to_start:
    z->gg.g.n = &x->KeySharing->gg.g;
    x->KeySharing = z;
    return;
  case -1:
    y = x->KeySharing;
    if (!y) goto add_to_start;
    for (; y->gg.g.n; y = (struct zx_ac_KeySharing_s*)y->gg.g.n) ;
    break;
  default:
    for (y = x->KeySharing; n > 1 && y; --n, y = (struct zx_ac_KeySharing_s*)y->gg.g.n) ;
    if (!y) return;
  }
  z->gg.g.n = y->gg.g.n;
  y->gg.g.n = &z->gg.g;
}

/* FUNC(zx_ac_PrivateKeyProtection_DEL_KeySharing) */

void zx_ac_PrivateKeyProtection_DEL_KeySharing(struct zx_ac_PrivateKeyProtection_s* x, int n)
{
  struct zx_ac_KeySharing_s* y;
  if (!x) return;
  switch (n) {
  case 0:
    x->KeySharing = (struct zx_ac_KeySharing_s*)x->KeySharing->gg.g.n;
    return;
  case -1:
    y = (struct zx_ac_KeySharing_s*)x->KeySharing;
    if (!y) return;
    for (; y->gg.g.n; y = (struct zx_ac_KeySharing_s*)y->gg.g.n) ;
    break;
  default:
    for (y = x->KeySharing; n > 1 && y->gg.g.n; --n, y = (struct zx_ac_KeySharing_s*)y->gg.g.n) ;
    if (!y->gg.g.n) return;
  }
  y->gg.g.n = y->gg.g.n->n;
}

#endif



#ifdef ZX_ENA_GETPUT

/* FUNC(zx_ac_PrivateKeyProtection_NUM_Extension) */

int zx_ac_PrivateKeyProtection_NUM_Extension(struct zx_ac_PrivateKeyProtection_s* x)
{
  struct zx_ac_Extension_s* y;
  int n = 0;
  if (!x) return 0;
  for (y = x->Extension; y; ++n, y = (struct zx_ac_Extension_s*)y->gg.g.n) ;
  return n;
}

/* FUNC(zx_ac_PrivateKeyProtection_GET_Extension) */

struct zx_ac_Extension_s* zx_ac_PrivateKeyProtection_GET_Extension(struct zx_ac_PrivateKeyProtection_s* x, int n)
{
  struct zx_ac_Extension_s* y;
  if (!x) return 0;
  for (y = x->Extension; n>=0 && y; --n, y = (struct zx_ac_Extension_s*)y->gg.g.n) ;
  return y;
}

/* FUNC(zx_ac_PrivateKeyProtection_POP_Extension) */

struct zx_ac_Extension_s* zx_ac_PrivateKeyProtection_POP_Extension(struct zx_ac_PrivateKeyProtection_s* x)
{
  struct zx_ac_Extension_s* y;
  if (!x) return 0;
  y = x->Extension;
  if (y)
    x->Extension = (struct zx_ac_Extension_s*)y->gg.g.n;
  return y;
}

/* FUNC(zx_ac_PrivateKeyProtection_PUSH_Extension) */

void zx_ac_PrivateKeyProtection_PUSH_Extension(struct zx_ac_PrivateKeyProtection_s* x, struct zx_ac_Extension_s* z)
{
  if (!x || !z) return;
  z->gg.g.n = &x->Extension->gg.g;
  x->Extension = z;
}

/* FUNC(zx_ac_PrivateKeyProtection_REV_Extension) */

void zx_ac_PrivateKeyProtection_REV_Extension(struct zx_ac_PrivateKeyProtection_s* x)
{
  struct zx_ac_Extension_s* nxt;
  struct zx_ac_Extension_s* y;
  if (!x) return;
  y = x->Extension;
  if (!y) return;
  x->Extension = 0;
  while (y) {
    nxt = (struct zx_ac_Extension_s*)y->gg.g.n;
    y->gg.g.n = &x->Extension->gg.g;
    x->Extension = y;
    y = nxt;
  }
}

/* FUNC(zx_ac_PrivateKeyProtection_PUT_Extension) */

void zx_ac_PrivateKeyProtection_PUT_Extension(struct zx_ac_PrivateKeyProtection_s* x, int n, struct zx_ac_Extension_s* z)
{
  struct zx_ac_Extension_s* y;
  if (!x || !z) return;
  y = x->Extension;
  if (!y) return;
  switch (n) {
  case 0:
    z->gg.g.n = y->gg.g.n;
    x->Extension = z;
    return;
  default:
    for (; n > 1 && y->gg.g.n; --n, y = (struct zx_ac_Extension_s*)y->gg.g.n) ;
    if (!y->gg.g.n) return;
    z->gg.g.n = y->gg.g.n->n;
    y->gg.g.n = &z->gg.g;
  }
}

/* FUNC(zx_ac_PrivateKeyProtection_ADD_Extension) */

void zx_ac_PrivateKeyProtection_ADD_Extension(struct zx_ac_PrivateKeyProtection_s* x, int n, struct zx_ac_Extension_s* z)
{
  struct zx_ac_Extension_s* y;
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
    for (; y->gg.g.n; y = (struct zx_ac_Extension_s*)y->gg.g.n) ;
    break;
  default:
    for (y = x->Extension; n > 1 && y; --n, y = (struct zx_ac_Extension_s*)y->gg.g.n) ;
    if (!y) return;
  }
  z->gg.g.n = y->gg.g.n;
  y->gg.g.n = &z->gg.g;
}

/* FUNC(zx_ac_PrivateKeyProtection_DEL_Extension) */

void zx_ac_PrivateKeyProtection_DEL_Extension(struct zx_ac_PrivateKeyProtection_s* x, int n)
{
  struct zx_ac_Extension_s* y;
  if (!x) return;
  switch (n) {
  case 0:
    x->Extension = (struct zx_ac_Extension_s*)x->Extension->gg.g.n;
    return;
  case -1:
    y = (struct zx_ac_Extension_s*)x->Extension;
    if (!y) return;
    for (; y->gg.g.n; y = (struct zx_ac_Extension_s*)y->gg.g.n) ;
    break;
  default:
    for (y = x->Extension; n > 1 && y->gg.g.n; --n, y = (struct zx_ac_Extension_s*)y->gg.g.n) ;
    if (!y->gg.g.n) return;
  }
  y->gg.g.n = y->gg.g.n->n;
}

#endif








#ifdef ZX_ENA_GETPUT

/* FUNC(zx_ac_ResumeSession_NUM_Extension) */

int zx_ac_ResumeSession_NUM_Extension(struct zx_ac_ResumeSession_s* x)
{
  struct zx_ac_Extension_s* y;
  int n = 0;
  if (!x) return 0;
  for (y = x->Extension; y; ++n, y = (struct zx_ac_Extension_s*)y->gg.g.n) ;
  return n;
}

/* FUNC(zx_ac_ResumeSession_GET_Extension) */

struct zx_ac_Extension_s* zx_ac_ResumeSession_GET_Extension(struct zx_ac_ResumeSession_s* x, int n)
{
  struct zx_ac_Extension_s* y;
  if (!x) return 0;
  for (y = x->Extension; n>=0 && y; --n, y = (struct zx_ac_Extension_s*)y->gg.g.n) ;
  return y;
}

/* FUNC(zx_ac_ResumeSession_POP_Extension) */

struct zx_ac_Extension_s* zx_ac_ResumeSession_POP_Extension(struct zx_ac_ResumeSession_s* x)
{
  struct zx_ac_Extension_s* y;
  if (!x) return 0;
  y = x->Extension;
  if (y)
    x->Extension = (struct zx_ac_Extension_s*)y->gg.g.n;
  return y;
}

/* FUNC(zx_ac_ResumeSession_PUSH_Extension) */

void zx_ac_ResumeSession_PUSH_Extension(struct zx_ac_ResumeSession_s* x, struct zx_ac_Extension_s* z)
{
  if (!x || !z) return;
  z->gg.g.n = &x->Extension->gg.g;
  x->Extension = z;
}

/* FUNC(zx_ac_ResumeSession_REV_Extension) */

void zx_ac_ResumeSession_REV_Extension(struct zx_ac_ResumeSession_s* x)
{
  struct zx_ac_Extension_s* nxt;
  struct zx_ac_Extension_s* y;
  if (!x) return;
  y = x->Extension;
  if (!y) return;
  x->Extension = 0;
  while (y) {
    nxt = (struct zx_ac_Extension_s*)y->gg.g.n;
    y->gg.g.n = &x->Extension->gg.g;
    x->Extension = y;
    y = nxt;
  }
}

/* FUNC(zx_ac_ResumeSession_PUT_Extension) */

void zx_ac_ResumeSession_PUT_Extension(struct zx_ac_ResumeSession_s* x, int n, struct zx_ac_Extension_s* z)
{
  struct zx_ac_Extension_s* y;
  if (!x || !z) return;
  y = x->Extension;
  if (!y) return;
  switch (n) {
  case 0:
    z->gg.g.n = y->gg.g.n;
    x->Extension = z;
    return;
  default:
    for (; n > 1 && y->gg.g.n; --n, y = (struct zx_ac_Extension_s*)y->gg.g.n) ;
    if (!y->gg.g.n) return;
    z->gg.g.n = y->gg.g.n->n;
    y->gg.g.n = &z->gg.g;
  }
}

/* FUNC(zx_ac_ResumeSession_ADD_Extension) */

void zx_ac_ResumeSession_ADD_Extension(struct zx_ac_ResumeSession_s* x, int n, struct zx_ac_Extension_s* z)
{
  struct zx_ac_Extension_s* y;
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
    for (; y->gg.g.n; y = (struct zx_ac_Extension_s*)y->gg.g.n) ;
    break;
  default:
    for (y = x->Extension; n > 1 && y; --n, y = (struct zx_ac_Extension_s*)y->gg.g.n) ;
    if (!y) return;
  }
  z->gg.g.n = y->gg.g.n;
  y->gg.g.n = &z->gg.g;
}

/* FUNC(zx_ac_ResumeSession_DEL_Extension) */

void zx_ac_ResumeSession_DEL_Extension(struct zx_ac_ResumeSession_s* x, int n)
{
  struct zx_ac_Extension_s* y;
  if (!x) return;
  switch (n) {
  case 0:
    x->Extension = (struct zx_ac_Extension_s*)x->Extension->gg.g.n;
    return;
  case -1:
    y = (struct zx_ac_Extension_s*)x->Extension;
    if (!y) return;
    for (; y->gg.g.n; y = (struct zx_ac_Extension_s*)y->gg.g.n) ;
    break;
  default:
    for (y = x->Extension; n > 1 && y->gg.g.n; --n, y = (struct zx_ac_Extension_s*)y->gg.g.n) ;
    if (!y->gg.g.n) return;
  }
  y->gg.g.n = y->gg.g.n->n;
}

#endif








#ifdef ZX_ENA_GETPUT

/* FUNC(zx_ac_SSL_NUM_Extension) */

int zx_ac_SSL_NUM_Extension(struct zx_ac_SSL_s* x)
{
  struct zx_ac_Extension_s* y;
  int n = 0;
  if (!x) return 0;
  for (y = x->Extension; y; ++n, y = (struct zx_ac_Extension_s*)y->gg.g.n) ;
  return n;
}

/* FUNC(zx_ac_SSL_GET_Extension) */

struct zx_ac_Extension_s* zx_ac_SSL_GET_Extension(struct zx_ac_SSL_s* x, int n)
{
  struct zx_ac_Extension_s* y;
  if (!x) return 0;
  for (y = x->Extension; n>=0 && y; --n, y = (struct zx_ac_Extension_s*)y->gg.g.n) ;
  return y;
}

/* FUNC(zx_ac_SSL_POP_Extension) */

struct zx_ac_Extension_s* zx_ac_SSL_POP_Extension(struct zx_ac_SSL_s* x)
{
  struct zx_ac_Extension_s* y;
  if (!x) return 0;
  y = x->Extension;
  if (y)
    x->Extension = (struct zx_ac_Extension_s*)y->gg.g.n;
  return y;
}

/* FUNC(zx_ac_SSL_PUSH_Extension) */

void zx_ac_SSL_PUSH_Extension(struct zx_ac_SSL_s* x, struct zx_ac_Extension_s* z)
{
  if (!x || !z) return;
  z->gg.g.n = &x->Extension->gg.g;
  x->Extension = z;
}

/* FUNC(zx_ac_SSL_REV_Extension) */

void zx_ac_SSL_REV_Extension(struct zx_ac_SSL_s* x)
{
  struct zx_ac_Extension_s* nxt;
  struct zx_ac_Extension_s* y;
  if (!x) return;
  y = x->Extension;
  if (!y) return;
  x->Extension = 0;
  while (y) {
    nxt = (struct zx_ac_Extension_s*)y->gg.g.n;
    y->gg.g.n = &x->Extension->gg.g;
    x->Extension = y;
    y = nxt;
  }
}

/* FUNC(zx_ac_SSL_PUT_Extension) */

void zx_ac_SSL_PUT_Extension(struct zx_ac_SSL_s* x, int n, struct zx_ac_Extension_s* z)
{
  struct zx_ac_Extension_s* y;
  if (!x || !z) return;
  y = x->Extension;
  if (!y) return;
  switch (n) {
  case 0:
    z->gg.g.n = y->gg.g.n;
    x->Extension = z;
    return;
  default:
    for (; n > 1 && y->gg.g.n; --n, y = (struct zx_ac_Extension_s*)y->gg.g.n) ;
    if (!y->gg.g.n) return;
    z->gg.g.n = y->gg.g.n->n;
    y->gg.g.n = &z->gg.g;
  }
}

/* FUNC(zx_ac_SSL_ADD_Extension) */

void zx_ac_SSL_ADD_Extension(struct zx_ac_SSL_s* x, int n, struct zx_ac_Extension_s* z)
{
  struct zx_ac_Extension_s* y;
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
    for (; y->gg.g.n; y = (struct zx_ac_Extension_s*)y->gg.g.n) ;
    break;
  default:
    for (y = x->Extension; n > 1 && y; --n, y = (struct zx_ac_Extension_s*)y->gg.g.n) ;
    if (!y) return;
  }
  z->gg.g.n = y->gg.g.n;
  y->gg.g.n = &z->gg.g;
}

/* FUNC(zx_ac_SSL_DEL_Extension) */

void zx_ac_SSL_DEL_Extension(struct zx_ac_SSL_s* x, int n)
{
  struct zx_ac_Extension_s* y;
  if (!x) return;
  switch (n) {
  case 0:
    x->Extension = (struct zx_ac_Extension_s*)x->Extension->gg.g.n;
    return;
  case -1:
    y = (struct zx_ac_Extension_s*)x->Extension;
    if (!y) return;
    for (; y->gg.g.n; y = (struct zx_ac_Extension_s*)y->gg.g.n) ;
    break;
  default:
    for (y = x->Extension; n > 1 && y->gg.g.n; --n, y = (struct zx_ac_Extension_s*)y->gg.g.n) ;
    if (!y->gg.g.n) return;
  }
  y->gg.g.n = y->gg.g.n->n;
}

#endif








#ifdef ZX_ENA_GETPUT

/* FUNC(zx_ac_SecretKeyProtection_NUM_KeyActivation) */

int zx_ac_SecretKeyProtection_NUM_KeyActivation(struct zx_ac_SecretKeyProtection_s* x)
{
  struct zx_ac_KeyActivation_s* y;
  int n = 0;
  if (!x) return 0;
  for (y = x->KeyActivation; y; ++n, y = (struct zx_ac_KeyActivation_s*)y->gg.g.n) ;
  return n;
}

/* FUNC(zx_ac_SecretKeyProtection_GET_KeyActivation) */

struct zx_ac_KeyActivation_s* zx_ac_SecretKeyProtection_GET_KeyActivation(struct zx_ac_SecretKeyProtection_s* x, int n)
{
  struct zx_ac_KeyActivation_s* y;
  if (!x) return 0;
  for (y = x->KeyActivation; n>=0 && y; --n, y = (struct zx_ac_KeyActivation_s*)y->gg.g.n) ;
  return y;
}

/* FUNC(zx_ac_SecretKeyProtection_POP_KeyActivation) */

struct zx_ac_KeyActivation_s* zx_ac_SecretKeyProtection_POP_KeyActivation(struct zx_ac_SecretKeyProtection_s* x)
{
  struct zx_ac_KeyActivation_s* y;
  if (!x) return 0;
  y = x->KeyActivation;
  if (y)
    x->KeyActivation = (struct zx_ac_KeyActivation_s*)y->gg.g.n;
  return y;
}

/* FUNC(zx_ac_SecretKeyProtection_PUSH_KeyActivation) */

void zx_ac_SecretKeyProtection_PUSH_KeyActivation(struct zx_ac_SecretKeyProtection_s* x, struct zx_ac_KeyActivation_s* z)
{
  if (!x || !z) return;
  z->gg.g.n = &x->KeyActivation->gg.g;
  x->KeyActivation = z;
}

/* FUNC(zx_ac_SecretKeyProtection_REV_KeyActivation) */

void zx_ac_SecretKeyProtection_REV_KeyActivation(struct zx_ac_SecretKeyProtection_s* x)
{
  struct zx_ac_KeyActivation_s* nxt;
  struct zx_ac_KeyActivation_s* y;
  if (!x) return;
  y = x->KeyActivation;
  if (!y) return;
  x->KeyActivation = 0;
  while (y) {
    nxt = (struct zx_ac_KeyActivation_s*)y->gg.g.n;
    y->gg.g.n = &x->KeyActivation->gg.g;
    x->KeyActivation = y;
    y = nxt;
  }
}

/* FUNC(zx_ac_SecretKeyProtection_PUT_KeyActivation) */

void zx_ac_SecretKeyProtection_PUT_KeyActivation(struct zx_ac_SecretKeyProtection_s* x, int n, struct zx_ac_KeyActivation_s* z)
{
  struct zx_ac_KeyActivation_s* y;
  if (!x || !z) return;
  y = x->KeyActivation;
  if (!y) return;
  switch (n) {
  case 0:
    z->gg.g.n = y->gg.g.n;
    x->KeyActivation = z;
    return;
  default:
    for (; n > 1 && y->gg.g.n; --n, y = (struct zx_ac_KeyActivation_s*)y->gg.g.n) ;
    if (!y->gg.g.n) return;
    z->gg.g.n = y->gg.g.n->n;
    y->gg.g.n = &z->gg.g;
  }
}

/* FUNC(zx_ac_SecretKeyProtection_ADD_KeyActivation) */

void zx_ac_SecretKeyProtection_ADD_KeyActivation(struct zx_ac_SecretKeyProtection_s* x, int n, struct zx_ac_KeyActivation_s* z)
{
  struct zx_ac_KeyActivation_s* y;
  if (!x || !z) return;
  switch (n) {
  case 0:
  add_to_start:
    z->gg.g.n = &x->KeyActivation->gg.g;
    x->KeyActivation = z;
    return;
  case -1:
    y = x->KeyActivation;
    if (!y) goto add_to_start;
    for (; y->gg.g.n; y = (struct zx_ac_KeyActivation_s*)y->gg.g.n) ;
    break;
  default:
    for (y = x->KeyActivation; n > 1 && y; --n, y = (struct zx_ac_KeyActivation_s*)y->gg.g.n) ;
    if (!y) return;
  }
  z->gg.g.n = y->gg.g.n;
  y->gg.g.n = &z->gg.g;
}

/* FUNC(zx_ac_SecretKeyProtection_DEL_KeyActivation) */

void zx_ac_SecretKeyProtection_DEL_KeyActivation(struct zx_ac_SecretKeyProtection_s* x, int n)
{
  struct zx_ac_KeyActivation_s* y;
  if (!x) return;
  switch (n) {
  case 0:
    x->KeyActivation = (struct zx_ac_KeyActivation_s*)x->KeyActivation->gg.g.n;
    return;
  case -1:
    y = (struct zx_ac_KeyActivation_s*)x->KeyActivation;
    if (!y) return;
    for (; y->gg.g.n; y = (struct zx_ac_KeyActivation_s*)y->gg.g.n) ;
    break;
  default:
    for (y = x->KeyActivation; n > 1 && y->gg.g.n; --n, y = (struct zx_ac_KeyActivation_s*)y->gg.g.n) ;
    if (!y->gg.g.n) return;
  }
  y->gg.g.n = y->gg.g.n->n;
}

#endif



#ifdef ZX_ENA_GETPUT

/* FUNC(zx_ac_SecretKeyProtection_NUM_KeyStorage) */

int zx_ac_SecretKeyProtection_NUM_KeyStorage(struct zx_ac_SecretKeyProtection_s* x)
{
  struct zx_ac_KeyStorage_s* y;
  int n = 0;
  if (!x) return 0;
  for (y = x->KeyStorage; y; ++n, y = (struct zx_ac_KeyStorage_s*)y->gg.g.n) ;
  return n;
}

/* FUNC(zx_ac_SecretKeyProtection_GET_KeyStorage) */

struct zx_ac_KeyStorage_s* zx_ac_SecretKeyProtection_GET_KeyStorage(struct zx_ac_SecretKeyProtection_s* x, int n)
{
  struct zx_ac_KeyStorage_s* y;
  if (!x) return 0;
  for (y = x->KeyStorage; n>=0 && y; --n, y = (struct zx_ac_KeyStorage_s*)y->gg.g.n) ;
  return y;
}

/* FUNC(zx_ac_SecretKeyProtection_POP_KeyStorage) */

struct zx_ac_KeyStorage_s* zx_ac_SecretKeyProtection_POP_KeyStorage(struct zx_ac_SecretKeyProtection_s* x)
{
  struct zx_ac_KeyStorage_s* y;
  if (!x) return 0;
  y = x->KeyStorage;
  if (y)
    x->KeyStorage = (struct zx_ac_KeyStorage_s*)y->gg.g.n;
  return y;
}

/* FUNC(zx_ac_SecretKeyProtection_PUSH_KeyStorage) */

void zx_ac_SecretKeyProtection_PUSH_KeyStorage(struct zx_ac_SecretKeyProtection_s* x, struct zx_ac_KeyStorage_s* z)
{
  if (!x || !z) return;
  z->gg.g.n = &x->KeyStorage->gg.g;
  x->KeyStorage = z;
}

/* FUNC(zx_ac_SecretKeyProtection_REV_KeyStorage) */

void zx_ac_SecretKeyProtection_REV_KeyStorage(struct zx_ac_SecretKeyProtection_s* x)
{
  struct zx_ac_KeyStorage_s* nxt;
  struct zx_ac_KeyStorage_s* y;
  if (!x) return;
  y = x->KeyStorage;
  if (!y) return;
  x->KeyStorage = 0;
  while (y) {
    nxt = (struct zx_ac_KeyStorage_s*)y->gg.g.n;
    y->gg.g.n = &x->KeyStorage->gg.g;
    x->KeyStorage = y;
    y = nxt;
  }
}

/* FUNC(zx_ac_SecretKeyProtection_PUT_KeyStorage) */

void zx_ac_SecretKeyProtection_PUT_KeyStorage(struct zx_ac_SecretKeyProtection_s* x, int n, struct zx_ac_KeyStorage_s* z)
{
  struct zx_ac_KeyStorage_s* y;
  if (!x || !z) return;
  y = x->KeyStorage;
  if (!y) return;
  switch (n) {
  case 0:
    z->gg.g.n = y->gg.g.n;
    x->KeyStorage = z;
    return;
  default:
    for (; n > 1 && y->gg.g.n; --n, y = (struct zx_ac_KeyStorage_s*)y->gg.g.n) ;
    if (!y->gg.g.n) return;
    z->gg.g.n = y->gg.g.n->n;
    y->gg.g.n = &z->gg.g;
  }
}

/* FUNC(zx_ac_SecretKeyProtection_ADD_KeyStorage) */

void zx_ac_SecretKeyProtection_ADD_KeyStorage(struct zx_ac_SecretKeyProtection_s* x, int n, struct zx_ac_KeyStorage_s* z)
{
  struct zx_ac_KeyStorage_s* y;
  if (!x || !z) return;
  switch (n) {
  case 0:
  add_to_start:
    z->gg.g.n = &x->KeyStorage->gg.g;
    x->KeyStorage = z;
    return;
  case -1:
    y = x->KeyStorage;
    if (!y) goto add_to_start;
    for (; y->gg.g.n; y = (struct zx_ac_KeyStorage_s*)y->gg.g.n) ;
    break;
  default:
    for (y = x->KeyStorage; n > 1 && y; --n, y = (struct zx_ac_KeyStorage_s*)y->gg.g.n) ;
    if (!y) return;
  }
  z->gg.g.n = y->gg.g.n;
  y->gg.g.n = &z->gg.g;
}

/* FUNC(zx_ac_SecretKeyProtection_DEL_KeyStorage) */

void zx_ac_SecretKeyProtection_DEL_KeyStorage(struct zx_ac_SecretKeyProtection_s* x, int n)
{
  struct zx_ac_KeyStorage_s* y;
  if (!x) return;
  switch (n) {
  case 0:
    x->KeyStorage = (struct zx_ac_KeyStorage_s*)x->KeyStorage->gg.g.n;
    return;
  case -1:
    y = (struct zx_ac_KeyStorage_s*)x->KeyStorage;
    if (!y) return;
    for (; y->gg.g.n; y = (struct zx_ac_KeyStorage_s*)y->gg.g.n) ;
    break;
  default:
    for (y = x->KeyStorage; n > 1 && y->gg.g.n; --n, y = (struct zx_ac_KeyStorage_s*)y->gg.g.n) ;
    if (!y->gg.g.n) return;
  }
  y->gg.g.n = y->gg.g.n->n;
}

#endif



#ifdef ZX_ENA_GETPUT

/* FUNC(zx_ac_SecretKeyProtection_NUM_Extension) */

int zx_ac_SecretKeyProtection_NUM_Extension(struct zx_ac_SecretKeyProtection_s* x)
{
  struct zx_ac_Extension_s* y;
  int n = 0;
  if (!x) return 0;
  for (y = x->Extension; y; ++n, y = (struct zx_ac_Extension_s*)y->gg.g.n) ;
  return n;
}

/* FUNC(zx_ac_SecretKeyProtection_GET_Extension) */

struct zx_ac_Extension_s* zx_ac_SecretKeyProtection_GET_Extension(struct zx_ac_SecretKeyProtection_s* x, int n)
{
  struct zx_ac_Extension_s* y;
  if (!x) return 0;
  for (y = x->Extension; n>=0 && y; --n, y = (struct zx_ac_Extension_s*)y->gg.g.n) ;
  return y;
}

/* FUNC(zx_ac_SecretKeyProtection_POP_Extension) */

struct zx_ac_Extension_s* zx_ac_SecretKeyProtection_POP_Extension(struct zx_ac_SecretKeyProtection_s* x)
{
  struct zx_ac_Extension_s* y;
  if (!x) return 0;
  y = x->Extension;
  if (y)
    x->Extension = (struct zx_ac_Extension_s*)y->gg.g.n;
  return y;
}

/* FUNC(zx_ac_SecretKeyProtection_PUSH_Extension) */

void zx_ac_SecretKeyProtection_PUSH_Extension(struct zx_ac_SecretKeyProtection_s* x, struct zx_ac_Extension_s* z)
{
  if (!x || !z) return;
  z->gg.g.n = &x->Extension->gg.g;
  x->Extension = z;
}

/* FUNC(zx_ac_SecretKeyProtection_REV_Extension) */

void zx_ac_SecretKeyProtection_REV_Extension(struct zx_ac_SecretKeyProtection_s* x)
{
  struct zx_ac_Extension_s* nxt;
  struct zx_ac_Extension_s* y;
  if (!x) return;
  y = x->Extension;
  if (!y) return;
  x->Extension = 0;
  while (y) {
    nxt = (struct zx_ac_Extension_s*)y->gg.g.n;
    y->gg.g.n = &x->Extension->gg.g;
    x->Extension = y;
    y = nxt;
  }
}

/* FUNC(zx_ac_SecretKeyProtection_PUT_Extension) */

void zx_ac_SecretKeyProtection_PUT_Extension(struct zx_ac_SecretKeyProtection_s* x, int n, struct zx_ac_Extension_s* z)
{
  struct zx_ac_Extension_s* y;
  if (!x || !z) return;
  y = x->Extension;
  if (!y) return;
  switch (n) {
  case 0:
    z->gg.g.n = y->gg.g.n;
    x->Extension = z;
    return;
  default:
    for (; n > 1 && y->gg.g.n; --n, y = (struct zx_ac_Extension_s*)y->gg.g.n) ;
    if (!y->gg.g.n) return;
    z->gg.g.n = y->gg.g.n->n;
    y->gg.g.n = &z->gg.g;
  }
}

/* FUNC(zx_ac_SecretKeyProtection_ADD_Extension) */

void zx_ac_SecretKeyProtection_ADD_Extension(struct zx_ac_SecretKeyProtection_s* x, int n, struct zx_ac_Extension_s* z)
{
  struct zx_ac_Extension_s* y;
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
    for (; y->gg.g.n; y = (struct zx_ac_Extension_s*)y->gg.g.n) ;
    break;
  default:
    for (y = x->Extension; n > 1 && y; --n, y = (struct zx_ac_Extension_s*)y->gg.g.n) ;
    if (!y) return;
  }
  z->gg.g.n = y->gg.g.n;
  y->gg.g.n = &z->gg.g;
}

/* FUNC(zx_ac_SecretKeyProtection_DEL_Extension) */

void zx_ac_SecretKeyProtection_DEL_Extension(struct zx_ac_SecretKeyProtection_s* x, int n)
{
  struct zx_ac_Extension_s* y;
  if (!x) return;
  switch (n) {
  case 0:
    x->Extension = (struct zx_ac_Extension_s*)x->Extension->gg.g.n;
    return;
  case -1:
    y = (struct zx_ac_Extension_s*)x->Extension;
    if (!y) return;
    for (; y->gg.g.n; y = (struct zx_ac_Extension_s*)y->gg.g.n) ;
    break;
  default:
    for (y = x->Extension; n > 1 && y->gg.g.n; --n, y = (struct zx_ac_Extension_s*)y->gg.g.n) ;
    if (!y->gg.g.n) return;
  }
  y->gg.g.n = y->gg.g.n->n;
}

#endif








#ifdef ZX_ENA_GETPUT

/* FUNC(zx_ac_SecurityAudit_NUM_SwitchAudit) */

int zx_ac_SecurityAudit_NUM_SwitchAudit(struct zx_ac_SecurityAudit_s* x)
{
  struct zx_ac_SwitchAudit_s* y;
  int n = 0;
  if (!x) return 0;
  for (y = x->SwitchAudit; y; ++n, y = (struct zx_ac_SwitchAudit_s*)y->gg.g.n) ;
  return n;
}

/* FUNC(zx_ac_SecurityAudit_GET_SwitchAudit) */

struct zx_ac_SwitchAudit_s* zx_ac_SecurityAudit_GET_SwitchAudit(struct zx_ac_SecurityAudit_s* x, int n)
{
  struct zx_ac_SwitchAudit_s* y;
  if (!x) return 0;
  for (y = x->SwitchAudit; n>=0 && y; --n, y = (struct zx_ac_SwitchAudit_s*)y->gg.g.n) ;
  return y;
}

/* FUNC(zx_ac_SecurityAudit_POP_SwitchAudit) */

struct zx_ac_SwitchAudit_s* zx_ac_SecurityAudit_POP_SwitchAudit(struct zx_ac_SecurityAudit_s* x)
{
  struct zx_ac_SwitchAudit_s* y;
  if (!x) return 0;
  y = x->SwitchAudit;
  if (y)
    x->SwitchAudit = (struct zx_ac_SwitchAudit_s*)y->gg.g.n;
  return y;
}

/* FUNC(zx_ac_SecurityAudit_PUSH_SwitchAudit) */

void zx_ac_SecurityAudit_PUSH_SwitchAudit(struct zx_ac_SecurityAudit_s* x, struct zx_ac_SwitchAudit_s* z)
{
  if (!x || !z) return;
  z->gg.g.n = &x->SwitchAudit->gg.g;
  x->SwitchAudit = z;
}

/* FUNC(zx_ac_SecurityAudit_REV_SwitchAudit) */

void zx_ac_SecurityAudit_REV_SwitchAudit(struct zx_ac_SecurityAudit_s* x)
{
  struct zx_ac_SwitchAudit_s* nxt;
  struct zx_ac_SwitchAudit_s* y;
  if (!x) return;
  y = x->SwitchAudit;
  if (!y) return;
  x->SwitchAudit = 0;
  while (y) {
    nxt = (struct zx_ac_SwitchAudit_s*)y->gg.g.n;
    y->gg.g.n = &x->SwitchAudit->gg.g;
    x->SwitchAudit = y;
    y = nxt;
  }
}

/* FUNC(zx_ac_SecurityAudit_PUT_SwitchAudit) */

void zx_ac_SecurityAudit_PUT_SwitchAudit(struct zx_ac_SecurityAudit_s* x, int n, struct zx_ac_SwitchAudit_s* z)
{
  struct zx_ac_SwitchAudit_s* y;
  if (!x || !z) return;
  y = x->SwitchAudit;
  if (!y) return;
  switch (n) {
  case 0:
    z->gg.g.n = y->gg.g.n;
    x->SwitchAudit = z;
    return;
  default:
    for (; n > 1 && y->gg.g.n; --n, y = (struct zx_ac_SwitchAudit_s*)y->gg.g.n) ;
    if (!y->gg.g.n) return;
    z->gg.g.n = y->gg.g.n->n;
    y->gg.g.n = &z->gg.g;
  }
}

/* FUNC(zx_ac_SecurityAudit_ADD_SwitchAudit) */

void zx_ac_SecurityAudit_ADD_SwitchAudit(struct zx_ac_SecurityAudit_s* x, int n, struct zx_ac_SwitchAudit_s* z)
{
  struct zx_ac_SwitchAudit_s* y;
  if (!x || !z) return;
  switch (n) {
  case 0:
  add_to_start:
    z->gg.g.n = &x->SwitchAudit->gg.g;
    x->SwitchAudit = z;
    return;
  case -1:
    y = x->SwitchAudit;
    if (!y) goto add_to_start;
    for (; y->gg.g.n; y = (struct zx_ac_SwitchAudit_s*)y->gg.g.n) ;
    break;
  default:
    for (y = x->SwitchAudit; n > 1 && y; --n, y = (struct zx_ac_SwitchAudit_s*)y->gg.g.n) ;
    if (!y) return;
  }
  z->gg.g.n = y->gg.g.n;
  y->gg.g.n = &z->gg.g;
}

/* FUNC(zx_ac_SecurityAudit_DEL_SwitchAudit) */

void zx_ac_SecurityAudit_DEL_SwitchAudit(struct zx_ac_SecurityAudit_s* x, int n)
{
  struct zx_ac_SwitchAudit_s* y;
  if (!x) return;
  switch (n) {
  case 0:
    x->SwitchAudit = (struct zx_ac_SwitchAudit_s*)x->SwitchAudit->gg.g.n;
    return;
  case -1:
    y = (struct zx_ac_SwitchAudit_s*)x->SwitchAudit;
    if (!y) return;
    for (; y->gg.g.n; y = (struct zx_ac_SwitchAudit_s*)y->gg.g.n) ;
    break;
  default:
    for (y = x->SwitchAudit; n > 1 && y->gg.g.n; --n, y = (struct zx_ac_SwitchAudit_s*)y->gg.g.n) ;
    if (!y->gg.g.n) return;
  }
  y->gg.g.n = y->gg.g.n->n;
}

#endif



#ifdef ZX_ENA_GETPUT

/* FUNC(zx_ac_SecurityAudit_NUM_Extension) */

int zx_ac_SecurityAudit_NUM_Extension(struct zx_ac_SecurityAudit_s* x)
{
  struct zx_ac_Extension_s* y;
  int n = 0;
  if (!x) return 0;
  for (y = x->Extension; y; ++n, y = (struct zx_ac_Extension_s*)y->gg.g.n) ;
  return n;
}

/* FUNC(zx_ac_SecurityAudit_GET_Extension) */

struct zx_ac_Extension_s* zx_ac_SecurityAudit_GET_Extension(struct zx_ac_SecurityAudit_s* x, int n)
{
  struct zx_ac_Extension_s* y;
  if (!x) return 0;
  for (y = x->Extension; n>=0 && y; --n, y = (struct zx_ac_Extension_s*)y->gg.g.n) ;
  return y;
}

/* FUNC(zx_ac_SecurityAudit_POP_Extension) */

struct zx_ac_Extension_s* zx_ac_SecurityAudit_POP_Extension(struct zx_ac_SecurityAudit_s* x)
{
  struct zx_ac_Extension_s* y;
  if (!x) return 0;
  y = x->Extension;
  if (y)
    x->Extension = (struct zx_ac_Extension_s*)y->gg.g.n;
  return y;
}

/* FUNC(zx_ac_SecurityAudit_PUSH_Extension) */

void zx_ac_SecurityAudit_PUSH_Extension(struct zx_ac_SecurityAudit_s* x, struct zx_ac_Extension_s* z)
{
  if (!x || !z) return;
  z->gg.g.n = &x->Extension->gg.g;
  x->Extension = z;
}

/* FUNC(zx_ac_SecurityAudit_REV_Extension) */

void zx_ac_SecurityAudit_REV_Extension(struct zx_ac_SecurityAudit_s* x)
{
  struct zx_ac_Extension_s* nxt;
  struct zx_ac_Extension_s* y;
  if (!x) return;
  y = x->Extension;
  if (!y) return;
  x->Extension = 0;
  while (y) {
    nxt = (struct zx_ac_Extension_s*)y->gg.g.n;
    y->gg.g.n = &x->Extension->gg.g;
    x->Extension = y;
    y = nxt;
  }
}

/* FUNC(zx_ac_SecurityAudit_PUT_Extension) */

void zx_ac_SecurityAudit_PUT_Extension(struct zx_ac_SecurityAudit_s* x, int n, struct zx_ac_Extension_s* z)
{
  struct zx_ac_Extension_s* y;
  if (!x || !z) return;
  y = x->Extension;
  if (!y) return;
  switch (n) {
  case 0:
    z->gg.g.n = y->gg.g.n;
    x->Extension = z;
    return;
  default:
    for (; n > 1 && y->gg.g.n; --n, y = (struct zx_ac_Extension_s*)y->gg.g.n) ;
    if (!y->gg.g.n) return;
    z->gg.g.n = y->gg.g.n->n;
    y->gg.g.n = &z->gg.g;
  }
}

/* FUNC(zx_ac_SecurityAudit_ADD_Extension) */

void zx_ac_SecurityAudit_ADD_Extension(struct zx_ac_SecurityAudit_s* x, int n, struct zx_ac_Extension_s* z)
{
  struct zx_ac_Extension_s* y;
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
    for (; y->gg.g.n; y = (struct zx_ac_Extension_s*)y->gg.g.n) ;
    break;
  default:
    for (y = x->Extension; n > 1 && y; --n, y = (struct zx_ac_Extension_s*)y->gg.g.n) ;
    if (!y) return;
  }
  z->gg.g.n = y->gg.g.n;
  y->gg.g.n = &z->gg.g;
}

/* FUNC(zx_ac_SecurityAudit_DEL_Extension) */

void zx_ac_SecurityAudit_DEL_Extension(struct zx_ac_SecurityAudit_s* x, int n)
{
  struct zx_ac_Extension_s* y;
  if (!x) return;
  switch (n) {
  case 0:
    x->Extension = (struct zx_ac_Extension_s*)x->Extension->gg.g.n;
    return;
  case -1:
    y = (struct zx_ac_Extension_s*)x->Extension;
    if (!y) return;
    for (; y->gg.g.n; y = (struct zx_ac_Extension_s*)y->gg.g.n) ;
    break;
  default:
    for (y = x->Extension; n > 1 && y->gg.g.n; --n, y = (struct zx_ac_Extension_s*)y->gg.g.n) ;
    if (!y->gg.g.n) return;
  }
  y->gg.g.n = y->gg.g.n->n;
}

#endif








#ifdef ZX_ENA_GETPUT

/* FUNC(zx_ac_SharedSecretChallengeResponse_NUM_Extension) */

int zx_ac_SharedSecretChallengeResponse_NUM_Extension(struct zx_ac_SharedSecretChallengeResponse_s* x)
{
  struct zx_ac_Extension_s* y;
  int n = 0;
  if (!x) return 0;
  for (y = x->Extension; y; ++n, y = (struct zx_ac_Extension_s*)y->gg.g.n) ;
  return n;
}

/* FUNC(zx_ac_SharedSecretChallengeResponse_GET_Extension) */

struct zx_ac_Extension_s* zx_ac_SharedSecretChallengeResponse_GET_Extension(struct zx_ac_SharedSecretChallengeResponse_s* x, int n)
{
  struct zx_ac_Extension_s* y;
  if (!x) return 0;
  for (y = x->Extension; n>=0 && y; --n, y = (struct zx_ac_Extension_s*)y->gg.g.n) ;
  return y;
}

/* FUNC(zx_ac_SharedSecretChallengeResponse_POP_Extension) */

struct zx_ac_Extension_s* zx_ac_SharedSecretChallengeResponse_POP_Extension(struct zx_ac_SharedSecretChallengeResponse_s* x)
{
  struct zx_ac_Extension_s* y;
  if (!x) return 0;
  y = x->Extension;
  if (y)
    x->Extension = (struct zx_ac_Extension_s*)y->gg.g.n;
  return y;
}

/* FUNC(zx_ac_SharedSecretChallengeResponse_PUSH_Extension) */

void zx_ac_SharedSecretChallengeResponse_PUSH_Extension(struct zx_ac_SharedSecretChallengeResponse_s* x, struct zx_ac_Extension_s* z)
{
  if (!x || !z) return;
  z->gg.g.n = &x->Extension->gg.g;
  x->Extension = z;
}

/* FUNC(zx_ac_SharedSecretChallengeResponse_REV_Extension) */

void zx_ac_SharedSecretChallengeResponse_REV_Extension(struct zx_ac_SharedSecretChallengeResponse_s* x)
{
  struct zx_ac_Extension_s* nxt;
  struct zx_ac_Extension_s* y;
  if (!x) return;
  y = x->Extension;
  if (!y) return;
  x->Extension = 0;
  while (y) {
    nxt = (struct zx_ac_Extension_s*)y->gg.g.n;
    y->gg.g.n = &x->Extension->gg.g;
    x->Extension = y;
    y = nxt;
  }
}

/* FUNC(zx_ac_SharedSecretChallengeResponse_PUT_Extension) */

void zx_ac_SharedSecretChallengeResponse_PUT_Extension(struct zx_ac_SharedSecretChallengeResponse_s* x, int n, struct zx_ac_Extension_s* z)
{
  struct zx_ac_Extension_s* y;
  if (!x || !z) return;
  y = x->Extension;
  if (!y) return;
  switch (n) {
  case 0:
    z->gg.g.n = y->gg.g.n;
    x->Extension = z;
    return;
  default:
    for (; n > 1 && y->gg.g.n; --n, y = (struct zx_ac_Extension_s*)y->gg.g.n) ;
    if (!y->gg.g.n) return;
    z->gg.g.n = y->gg.g.n->n;
    y->gg.g.n = &z->gg.g;
  }
}

/* FUNC(zx_ac_SharedSecretChallengeResponse_ADD_Extension) */

void zx_ac_SharedSecretChallengeResponse_ADD_Extension(struct zx_ac_SharedSecretChallengeResponse_s* x, int n, struct zx_ac_Extension_s* z)
{
  struct zx_ac_Extension_s* y;
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
    for (; y->gg.g.n; y = (struct zx_ac_Extension_s*)y->gg.g.n) ;
    break;
  default:
    for (y = x->Extension; n > 1 && y; --n, y = (struct zx_ac_Extension_s*)y->gg.g.n) ;
    if (!y) return;
  }
  z->gg.g.n = y->gg.g.n;
  y->gg.g.n = &z->gg.g;
}

/* FUNC(zx_ac_SharedSecretChallengeResponse_DEL_Extension) */

void zx_ac_SharedSecretChallengeResponse_DEL_Extension(struct zx_ac_SharedSecretChallengeResponse_s* x, int n)
{
  struct zx_ac_Extension_s* y;
  if (!x) return;
  switch (n) {
  case 0:
    x->Extension = (struct zx_ac_Extension_s*)x->Extension->gg.g.n;
    return;
  case -1:
    y = (struct zx_ac_Extension_s*)x->Extension;
    if (!y) return;
    for (; y->gg.g.n; y = (struct zx_ac_Extension_s*)y->gg.g.n) ;
    break;
  default:
    for (y = x->Extension; n > 1 && y->gg.g.n; --n, y = (struct zx_ac_Extension_s*)y->gg.g.n) ;
    if (!y->gg.g.n) return;
  }
  y->gg.g.n = y->gg.g.n->n;
}

#endif








#ifdef ZX_ENA_GETPUT

/* FUNC(zx_ac_SharedSecretDynamicPlaintext_NUM_Extension) */

int zx_ac_SharedSecretDynamicPlaintext_NUM_Extension(struct zx_ac_SharedSecretDynamicPlaintext_s* x)
{
  struct zx_ac_Extension_s* y;
  int n = 0;
  if (!x) return 0;
  for (y = x->Extension; y; ++n, y = (struct zx_ac_Extension_s*)y->gg.g.n) ;
  return n;
}

/* FUNC(zx_ac_SharedSecretDynamicPlaintext_GET_Extension) */

struct zx_ac_Extension_s* zx_ac_SharedSecretDynamicPlaintext_GET_Extension(struct zx_ac_SharedSecretDynamicPlaintext_s* x, int n)
{
  struct zx_ac_Extension_s* y;
  if (!x) return 0;
  for (y = x->Extension; n>=0 && y; --n, y = (struct zx_ac_Extension_s*)y->gg.g.n) ;
  return y;
}

/* FUNC(zx_ac_SharedSecretDynamicPlaintext_POP_Extension) */

struct zx_ac_Extension_s* zx_ac_SharedSecretDynamicPlaintext_POP_Extension(struct zx_ac_SharedSecretDynamicPlaintext_s* x)
{
  struct zx_ac_Extension_s* y;
  if (!x) return 0;
  y = x->Extension;
  if (y)
    x->Extension = (struct zx_ac_Extension_s*)y->gg.g.n;
  return y;
}

/* FUNC(zx_ac_SharedSecretDynamicPlaintext_PUSH_Extension) */

void zx_ac_SharedSecretDynamicPlaintext_PUSH_Extension(struct zx_ac_SharedSecretDynamicPlaintext_s* x, struct zx_ac_Extension_s* z)
{
  if (!x || !z) return;
  z->gg.g.n = &x->Extension->gg.g;
  x->Extension = z;
}

/* FUNC(zx_ac_SharedSecretDynamicPlaintext_REV_Extension) */

void zx_ac_SharedSecretDynamicPlaintext_REV_Extension(struct zx_ac_SharedSecretDynamicPlaintext_s* x)
{
  struct zx_ac_Extension_s* nxt;
  struct zx_ac_Extension_s* y;
  if (!x) return;
  y = x->Extension;
  if (!y) return;
  x->Extension = 0;
  while (y) {
    nxt = (struct zx_ac_Extension_s*)y->gg.g.n;
    y->gg.g.n = &x->Extension->gg.g;
    x->Extension = y;
    y = nxt;
  }
}

/* FUNC(zx_ac_SharedSecretDynamicPlaintext_PUT_Extension) */

void zx_ac_SharedSecretDynamicPlaintext_PUT_Extension(struct zx_ac_SharedSecretDynamicPlaintext_s* x, int n, struct zx_ac_Extension_s* z)
{
  struct zx_ac_Extension_s* y;
  if (!x || !z) return;
  y = x->Extension;
  if (!y) return;
  switch (n) {
  case 0:
    z->gg.g.n = y->gg.g.n;
    x->Extension = z;
    return;
  default:
    for (; n > 1 && y->gg.g.n; --n, y = (struct zx_ac_Extension_s*)y->gg.g.n) ;
    if (!y->gg.g.n) return;
    z->gg.g.n = y->gg.g.n->n;
    y->gg.g.n = &z->gg.g;
  }
}

/* FUNC(zx_ac_SharedSecretDynamicPlaintext_ADD_Extension) */

void zx_ac_SharedSecretDynamicPlaintext_ADD_Extension(struct zx_ac_SharedSecretDynamicPlaintext_s* x, int n, struct zx_ac_Extension_s* z)
{
  struct zx_ac_Extension_s* y;
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
    for (; y->gg.g.n; y = (struct zx_ac_Extension_s*)y->gg.g.n) ;
    break;
  default:
    for (y = x->Extension; n > 1 && y; --n, y = (struct zx_ac_Extension_s*)y->gg.g.n) ;
    if (!y) return;
  }
  z->gg.g.n = y->gg.g.n;
  y->gg.g.n = &z->gg.g;
}

/* FUNC(zx_ac_SharedSecretDynamicPlaintext_DEL_Extension) */

void zx_ac_SharedSecretDynamicPlaintext_DEL_Extension(struct zx_ac_SharedSecretDynamicPlaintext_s* x, int n)
{
  struct zx_ac_Extension_s* y;
  if (!x) return;
  switch (n) {
  case 0:
    x->Extension = (struct zx_ac_Extension_s*)x->Extension->gg.g.n;
    return;
  case -1:
    y = (struct zx_ac_Extension_s*)x->Extension;
    if (!y) return;
    for (; y->gg.g.n; y = (struct zx_ac_Extension_s*)y->gg.g.n) ;
    break;
  default:
    for (y = x->Extension; n > 1 && y->gg.g.n; --n, y = (struct zx_ac_Extension_s*)y->gg.g.n) ;
    if (!y->gg.g.n) return;
  }
  y->gg.g.n = y->gg.g.n->n;
}

#endif








#ifdef ZX_ENA_GETPUT

/* FUNC(zx_ac_Smartcard_NUM_Extension) */

int zx_ac_Smartcard_NUM_Extension(struct zx_ac_Smartcard_s* x)
{
  struct zx_ac_Extension_s* y;
  int n = 0;
  if (!x) return 0;
  for (y = x->Extension; y; ++n, y = (struct zx_ac_Extension_s*)y->gg.g.n) ;
  return n;
}

/* FUNC(zx_ac_Smartcard_GET_Extension) */

struct zx_ac_Extension_s* zx_ac_Smartcard_GET_Extension(struct zx_ac_Smartcard_s* x, int n)
{
  struct zx_ac_Extension_s* y;
  if (!x) return 0;
  for (y = x->Extension; n>=0 && y; --n, y = (struct zx_ac_Extension_s*)y->gg.g.n) ;
  return y;
}

/* FUNC(zx_ac_Smartcard_POP_Extension) */

struct zx_ac_Extension_s* zx_ac_Smartcard_POP_Extension(struct zx_ac_Smartcard_s* x)
{
  struct zx_ac_Extension_s* y;
  if (!x) return 0;
  y = x->Extension;
  if (y)
    x->Extension = (struct zx_ac_Extension_s*)y->gg.g.n;
  return y;
}

/* FUNC(zx_ac_Smartcard_PUSH_Extension) */

void zx_ac_Smartcard_PUSH_Extension(struct zx_ac_Smartcard_s* x, struct zx_ac_Extension_s* z)
{
  if (!x || !z) return;
  z->gg.g.n = &x->Extension->gg.g;
  x->Extension = z;
}

/* FUNC(zx_ac_Smartcard_REV_Extension) */

void zx_ac_Smartcard_REV_Extension(struct zx_ac_Smartcard_s* x)
{
  struct zx_ac_Extension_s* nxt;
  struct zx_ac_Extension_s* y;
  if (!x) return;
  y = x->Extension;
  if (!y) return;
  x->Extension = 0;
  while (y) {
    nxt = (struct zx_ac_Extension_s*)y->gg.g.n;
    y->gg.g.n = &x->Extension->gg.g;
    x->Extension = y;
    y = nxt;
  }
}

/* FUNC(zx_ac_Smartcard_PUT_Extension) */

void zx_ac_Smartcard_PUT_Extension(struct zx_ac_Smartcard_s* x, int n, struct zx_ac_Extension_s* z)
{
  struct zx_ac_Extension_s* y;
  if (!x || !z) return;
  y = x->Extension;
  if (!y) return;
  switch (n) {
  case 0:
    z->gg.g.n = y->gg.g.n;
    x->Extension = z;
    return;
  default:
    for (; n > 1 && y->gg.g.n; --n, y = (struct zx_ac_Extension_s*)y->gg.g.n) ;
    if (!y->gg.g.n) return;
    z->gg.g.n = y->gg.g.n->n;
    y->gg.g.n = &z->gg.g;
  }
}

/* FUNC(zx_ac_Smartcard_ADD_Extension) */

void zx_ac_Smartcard_ADD_Extension(struct zx_ac_Smartcard_s* x, int n, struct zx_ac_Extension_s* z)
{
  struct zx_ac_Extension_s* y;
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
    for (; y->gg.g.n; y = (struct zx_ac_Extension_s*)y->gg.g.n) ;
    break;
  default:
    for (y = x->Extension; n > 1 && y; --n, y = (struct zx_ac_Extension_s*)y->gg.g.n) ;
    if (!y) return;
  }
  z->gg.g.n = y->gg.g.n;
  y->gg.g.n = &z->gg.g;
}

/* FUNC(zx_ac_Smartcard_DEL_Extension) */

void zx_ac_Smartcard_DEL_Extension(struct zx_ac_Smartcard_s* x, int n)
{
  struct zx_ac_Extension_s* y;
  if (!x) return;
  switch (n) {
  case 0:
    x->Extension = (struct zx_ac_Extension_s*)x->Extension->gg.g.n;
    return;
  case -1:
    y = (struct zx_ac_Extension_s*)x->Extension;
    if (!y) return;
    for (; y->gg.g.n; y = (struct zx_ac_Extension_s*)y->gg.g.n) ;
    break;
  default:
    for (y = x->Extension; n > 1 && y->gg.g.n; --n, y = (struct zx_ac_Extension_s*)y->gg.g.n) ;
    if (!y->gg.g.n) return;
  }
  y->gg.g.n = y->gg.g.n->n;
}

#endif








#ifdef ZX_ENA_GETPUT

/* FUNC(zx_ac_SwitchAudit_NUM_Extension) */

int zx_ac_SwitchAudit_NUM_Extension(struct zx_ac_SwitchAudit_s* x)
{
  struct zx_ac_Extension_s* y;
  int n = 0;
  if (!x) return 0;
  for (y = x->Extension; y; ++n, y = (struct zx_ac_Extension_s*)y->gg.g.n) ;
  return n;
}

/* FUNC(zx_ac_SwitchAudit_GET_Extension) */

struct zx_ac_Extension_s* zx_ac_SwitchAudit_GET_Extension(struct zx_ac_SwitchAudit_s* x, int n)
{
  struct zx_ac_Extension_s* y;
  if (!x) return 0;
  for (y = x->Extension; n>=0 && y; --n, y = (struct zx_ac_Extension_s*)y->gg.g.n) ;
  return y;
}

/* FUNC(zx_ac_SwitchAudit_POP_Extension) */

struct zx_ac_Extension_s* zx_ac_SwitchAudit_POP_Extension(struct zx_ac_SwitchAudit_s* x)
{
  struct zx_ac_Extension_s* y;
  if (!x) return 0;
  y = x->Extension;
  if (y)
    x->Extension = (struct zx_ac_Extension_s*)y->gg.g.n;
  return y;
}

/* FUNC(zx_ac_SwitchAudit_PUSH_Extension) */

void zx_ac_SwitchAudit_PUSH_Extension(struct zx_ac_SwitchAudit_s* x, struct zx_ac_Extension_s* z)
{
  if (!x || !z) return;
  z->gg.g.n = &x->Extension->gg.g;
  x->Extension = z;
}

/* FUNC(zx_ac_SwitchAudit_REV_Extension) */

void zx_ac_SwitchAudit_REV_Extension(struct zx_ac_SwitchAudit_s* x)
{
  struct zx_ac_Extension_s* nxt;
  struct zx_ac_Extension_s* y;
  if (!x) return;
  y = x->Extension;
  if (!y) return;
  x->Extension = 0;
  while (y) {
    nxt = (struct zx_ac_Extension_s*)y->gg.g.n;
    y->gg.g.n = &x->Extension->gg.g;
    x->Extension = y;
    y = nxt;
  }
}

/* FUNC(zx_ac_SwitchAudit_PUT_Extension) */

void zx_ac_SwitchAudit_PUT_Extension(struct zx_ac_SwitchAudit_s* x, int n, struct zx_ac_Extension_s* z)
{
  struct zx_ac_Extension_s* y;
  if (!x || !z) return;
  y = x->Extension;
  if (!y) return;
  switch (n) {
  case 0:
    z->gg.g.n = y->gg.g.n;
    x->Extension = z;
    return;
  default:
    for (; n > 1 && y->gg.g.n; --n, y = (struct zx_ac_Extension_s*)y->gg.g.n) ;
    if (!y->gg.g.n) return;
    z->gg.g.n = y->gg.g.n->n;
    y->gg.g.n = &z->gg.g;
  }
}

/* FUNC(zx_ac_SwitchAudit_ADD_Extension) */

void zx_ac_SwitchAudit_ADD_Extension(struct zx_ac_SwitchAudit_s* x, int n, struct zx_ac_Extension_s* z)
{
  struct zx_ac_Extension_s* y;
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
    for (; y->gg.g.n; y = (struct zx_ac_Extension_s*)y->gg.g.n) ;
    break;
  default:
    for (y = x->Extension; n > 1 && y; --n, y = (struct zx_ac_Extension_s*)y->gg.g.n) ;
    if (!y) return;
  }
  z->gg.g.n = y->gg.g.n;
  y->gg.g.n = &z->gg.g;
}

/* FUNC(zx_ac_SwitchAudit_DEL_Extension) */

void zx_ac_SwitchAudit_DEL_Extension(struct zx_ac_SwitchAudit_s* x, int n)
{
  struct zx_ac_Extension_s* y;
  if (!x) return;
  switch (n) {
  case 0:
    x->Extension = (struct zx_ac_Extension_s*)x->Extension->gg.g.n;
    return;
  case -1:
    y = (struct zx_ac_Extension_s*)x->Extension;
    if (!y) return;
    for (; y->gg.g.n; y = (struct zx_ac_Extension_s*)y->gg.g.n) ;
    break;
  default:
    for (y = x->Extension; n > 1 && y->gg.g.n; --n, y = (struct zx_ac_Extension_s*)y->gg.g.n) ;
    if (!y->gg.g.n) return;
  }
  y->gg.g.n = y->gg.g.n->n;
}

#endif








#ifdef ZX_ENA_GETPUT

/* FUNC(zx_ac_TechnicalProtection_NUM_PrivateKeyProtection) */

int zx_ac_TechnicalProtection_NUM_PrivateKeyProtection(struct zx_ac_TechnicalProtection_s* x)
{
  struct zx_ac_PrivateKeyProtection_s* y;
  int n = 0;
  if (!x) return 0;
  for (y = x->PrivateKeyProtection; y; ++n, y = (struct zx_ac_PrivateKeyProtection_s*)y->gg.g.n) ;
  return n;
}

/* FUNC(zx_ac_TechnicalProtection_GET_PrivateKeyProtection) */

struct zx_ac_PrivateKeyProtection_s* zx_ac_TechnicalProtection_GET_PrivateKeyProtection(struct zx_ac_TechnicalProtection_s* x, int n)
{
  struct zx_ac_PrivateKeyProtection_s* y;
  if (!x) return 0;
  for (y = x->PrivateKeyProtection; n>=0 && y; --n, y = (struct zx_ac_PrivateKeyProtection_s*)y->gg.g.n) ;
  return y;
}

/* FUNC(zx_ac_TechnicalProtection_POP_PrivateKeyProtection) */

struct zx_ac_PrivateKeyProtection_s* zx_ac_TechnicalProtection_POP_PrivateKeyProtection(struct zx_ac_TechnicalProtection_s* x)
{
  struct zx_ac_PrivateKeyProtection_s* y;
  if (!x) return 0;
  y = x->PrivateKeyProtection;
  if (y)
    x->PrivateKeyProtection = (struct zx_ac_PrivateKeyProtection_s*)y->gg.g.n;
  return y;
}

/* FUNC(zx_ac_TechnicalProtection_PUSH_PrivateKeyProtection) */

void zx_ac_TechnicalProtection_PUSH_PrivateKeyProtection(struct zx_ac_TechnicalProtection_s* x, struct zx_ac_PrivateKeyProtection_s* z)
{
  if (!x || !z) return;
  z->gg.g.n = &x->PrivateKeyProtection->gg.g;
  x->PrivateKeyProtection = z;
}

/* FUNC(zx_ac_TechnicalProtection_REV_PrivateKeyProtection) */

void zx_ac_TechnicalProtection_REV_PrivateKeyProtection(struct zx_ac_TechnicalProtection_s* x)
{
  struct zx_ac_PrivateKeyProtection_s* nxt;
  struct zx_ac_PrivateKeyProtection_s* y;
  if (!x) return;
  y = x->PrivateKeyProtection;
  if (!y) return;
  x->PrivateKeyProtection = 0;
  while (y) {
    nxt = (struct zx_ac_PrivateKeyProtection_s*)y->gg.g.n;
    y->gg.g.n = &x->PrivateKeyProtection->gg.g;
    x->PrivateKeyProtection = y;
    y = nxt;
  }
}

/* FUNC(zx_ac_TechnicalProtection_PUT_PrivateKeyProtection) */

void zx_ac_TechnicalProtection_PUT_PrivateKeyProtection(struct zx_ac_TechnicalProtection_s* x, int n, struct zx_ac_PrivateKeyProtection_s* z)
{
  struct zx_ac_PrivateKeyProtection_s* y;
  if (!x || !z) return;
  y = x->PrivateKeyProtection;
  if (!y) return;
  switch (n) {
  case 0:
    z->gg.g.n = y->gg.g.n;
    x->PrivateKeyProtection = z;
    return;
  default:
    for (; n > 1 && y->gg.g.n; --n, y = (struct zx_ac_PrivateKeyProtection_s*)y->gg.g.n) ;
    if (!y->gg.g.n) return;
    z->gg.g.n = y->gg.g.n->n;
    y->gg.g.n = &z->gg.g;
  }
}

/* FUNC(zx_ac_TechnicalProtection_ADD_PrivateKeyProtection) */

void zx_ac_TechnicalProtection_ADD_PrivateKeyProtection(struct zx_ac_TechnicalProtection_s* x, int n, struct zx_ac_PrivateKeyProtection_s* z)
{
  struct zx_ac_PrivateKeyProtection_s* y;
  if (!x || !z) return;
  switch (n) {
  case 0:
  add_to_start:
    z->gg.g.n = &x->PrivateKeyProtection->gg.g;
    x->PrivateKeyProtection = z;
    return;
  case -1:
    y = x->PrivateKeyProtection;
    if (!y) goto add_to_start;
    for (; y->gg.g.n; y = (struct zx_ac_PrivateKeyProtection_s*)y->gg.g.n) ;
    break;
  default:
    for (y = x->PrivateKeyProtection; n > 1 && y; --n, y = (struct zx_ac_PrivateKeyProtection_s*)y->gg.g.n) ;
    if (!y) return;
  }
  z->gg.g.n = y->gg.g.n;
  y->gg.g.n = &z->gg.g;
}

/* FUNC(zx_ac_TechnicalProtection_DEL_PrivateKeyProtection) */

void zx_ac_TechnicalProtection_DEL_PrivateKeyProtection(struct zx_ac_TechnicalProtection_s* x, int n)
{
  struct zx_ac_PrivateKeyProtection_s* y;
  if (!x) return;
  switch (n) {
  case 0:
    x->PrivateKeyProtection = (struct zx_ac_PrivateKeyProtection_s*)x->PrivateKeyProtection->gg.g.n;
    return;
  case -1:
    y = (struct zx_ac_PrivateKeyProtection_s*)x->PrivateKeyProtection;
    if (!y) return;
    for (; y->gg.g.n; y = (struct zx_ac_PrivateKeyProtection_s*)y->gg.g.n) ;
    break;
  default:
    for (y = x->PrivateKeyProtection; n > 1 && y->gg.g.n; --n, y = (struct zx_ac_PrivateKeyProtection_s*)y->gg.g.n) ;
    if (!y->gg.g.n) return;
  }
  y->gg.g.n = y->gg.g.n->n;
}

#endif



#ifdef ZX_ENA_GETPUT

/* FUNC(zx_ac_TechnicalProtection_NUM_SecretKeyProtection) */

int zx_ac_TechnicalProtection_NUM_SecretKeyProtection(struct zx_ac_TechnicalProtection_s* x)
{
  struct zx_ac_SecretKeyProtection_s* y;
  int n = 0;
  if (!x) return 0;
  for (y = x->SecretKeyProtection; y; ++n, y = (struct zx_ac_SecretKeyProtection_s*)y->gg.g.n) ;
  return n;
}

/* FUNC(zx_ac_TechnicalProtection_GET_SecretKeyProtection) */

struct zx_ac_SecretKeyProtection_s* zx_ac_TechnicalProtection_GET_SecretKeyProtection(struct zx_ac_TechnicalProtection_s* x, int n)
{
  struct zx_ac_SecretKeyProtection_s* y;
  if (!x) return 0;
  for (y = x->SecretKeyProtection; n>=0 && y; --n, y = (struct zx_ac_SecretKeyProtection_s*)y->gg.g.n) ;
  return y;
}

/* FUNC(zx_ac_TechnicalProtection_POP_SecretKeyProtection) */

struct zx_ac_SecretKeyProtection_s* zx_ac_TechnicalProtection_POP_SecretKeyProtection(struct zx_ac_TechnicalProtection_s* x)
{
  struct zx_ac_SecretKeyProtection_s* y;
  if (!x) return 0;
  y = x->SecretKeyProtection;
  if (y)
    x->SecretKeyProtection = (struct zx_ac_SecretKeyProtection_s*)y->gg.g.n;
  return y;
}

/* FUNC(zx_ac_TechnicalProtection_PUSH_SecretKeyProtection) */

void zx_ac_TechnicalProtection_PUSH_SecretKeyProtection(struct zx_ac_TechnicalProtection_s* x, struct zx_ac_SecretKeyProtection_s* z)
{
  if (!x || !z) return;
  z->gg.g.n = &x->SecretKeyProtection->gg.g;
  x->SecretKeyProtection = z;
}

/* FUNC(zx_ac_TechnicalProtection_REV_SecretKeyProtection) */

void zx_ac_TechnicalProtection_REV_SecretKeyProtection(struct zx_ac_TechnicalProtection_s* x)
{
  struct zx_ac_SecretKeyProtection_s* nxt;
  struct zx_ac_SecretKeyProtection_s* y;
  if (!x) return;
  y = x->SecretKeyProtection;
  if (!y) return;
  x->SecretKeyProtection = 0;
  while (y) {
    nxt = (struct zx_ac_SecretKeyProtection_s*)y->gg.g.n;
    y->gg.g.n = &x->SecretKeyProtection->gg.g;
    x->SecretKeyProtection = y;
    y = nxt;
  }
}

/* FUNC(zx_ac_TechnicalProtection_PUT_SecretKeyProtection) */

void zx_ac_TechnicalProtection_PUT_SecretKeyProtection(struct zx_ac_TechnicalProtection_s* x, int n, struct zx_ac_SecretKeyProtection_s* z)
{
  struct zx_ac_SecretKeyProtection_s* y;
  if (!x || !z) return;
  y = x->SecretKeyProtection;
  if (!y) return;
  switch (n) {
  case 0:
    z->gg.g.n = y->gg.g.n;
    x->SecretKeyProtection = z;
    return;
  default:
    for (; n > 1 && y->gg.g.n; --n, y = (struct zx_ac_SecretKeyProtection_s*)y->gg.g.n) ;
    if (!y->gg.g.n) return;
    z->gg.g.n = y->gg.g.n->n;
    y->gg.g.n = &z->gg.g;
  }
}

/* FUNC(zx_ac_TechnicalProtection_ADD_SecretKeyProtection) */

void zx_ac_TechnicalProtection_ADD_SecretKeyProtection(struct zx_ac_TechnicalProtection_s* x, int n, struct zx_ac_SecretKeyProtection_s* z)
{
  struct zx_ac_SecretKeyProtection_s* y;
  if (!x || !z) return;
  switch (n) {
  case 0:
  add_to_start:
    z->gg.g.n = &x->SecretKeyProtection->gg.g;
    x->SecretKeyProtection = z;
    return;
  case -1:
    y = x->SecretKeyProtection;
    if (!y) goto add_to_start;
    for (; y->gg.g.n; y = (struct zx_ac_SecretKeyProtection_s*)y->gg.g.n) ;
    break;
  default:
    for (y = x->SecretKeyProtection; n > 1 && y; --n, y = (struct zx_ac_SecretKeyProtection_s*)y->gg.g.n) ;
    if (!y) return;
  }
  z->gg.g.n = y->gg.g.n;
  y->gg.g.n = &z->gg.g;
}

/* FUNC(zx_ac_TechnicalProtection_DEL_SecretKeyProtection) */

void zx_ac_TechnicalProtection_DEL_SecretKeyProtection(struct zx_ac_TechnicalProtection_s* x, int n)
{
  struct zx_ac_SecretKeyProtection_s* y;
  if (!x) return;
  switch (n) {
  case 0:
    x->SecretKeyProtection = (struct zx_ac_SecretKeyProtection_s*)x->SecretKeyProtection->gg.g.n;
    return;
  case -1:
    y = (struct zx_ac_SecretKeyProtection_s*)x->SecretKeyProtection;
    if (!y) return;
    for (; y->gg.g.n; y = (struct zx_ac_SecretKeyProtection_s*)y->gg.g.n) ;
    break;
  default:
    for (y = x->SecretKeyProtection; n > 1 && y->gg.g.n; --n, y = (struct zx_ac_SecretKeyProtection_s*)y->gg.g.n) ;
    if (!y->gg.g.n) return;
  }
  y->gg.g.n = y->gg.g.n->n;
}

#endif



#ifdef ZX_ENA_GETPUT

/* FUNC(zx_ac_TechnicalProtection_NUM_Extension) */

int zx_ac_TechnicalProtection_NUM_Extension(struct zx_ac_TechnicalProtection_s* x)
{
  struct zx_ac_Extension_s* y;
  int n = 0;
  if (!x) return 0;
  for (y = x->Extension; y; ++n, y = (struct zx_ac_Extension_s*)y->gg.g.n) ;
  return n;
}

/* FUNC(zx_ac_TechnicalProtection_GET_Extension) */

struct zx_ac_Extension_s* zx_ac_TechnicalProtection_GET_Extension(struct zx_ac_TechnicalProtection_s* x, int n)
{
  struct zx_ac_Extension_s* y;
  if (!x) return 0;
  for (y = x->Extension; n>=0 && y; --n, y = (struct zx_ac_Extension_s*)y->gg.g.n) ;
  return y;
}

/* FUNC(zx_ac_TechnicalProtection_POP_Extension) */

struct zx_ac_Extension_s* zx_ac_TechnicalProtection_POP_Extension(struct zx_ac_TechnicalProtection_s* x)
{
  struct zx_ac_Extension_s* y;
  if (!x) return 0;
  y = x->Extension;
  if (y)
    x->Extension = (struct zx_ac_Extension_s*)y->gg.g.n;
  return y;
}

/* FUNC(zx_ac_TechnicalProtection_PUSH_Extension) */

void zx_ac_TechnicalProtection_PUSH_Extension(struct zx_ac_TechnicalProtection_s* x, struct zx_ac_Extension_s* z)
{
  if (!x || !z) return;
  z->gg.g.n = &x->Extension->gg.g;
  x->Extension = z;
}

/* FUNC(zx_ac_TechnicalProtection_REV_Extension) */

void zx_ac_TechnicalProtection_REV_Extension(struct zx_ac_TechnicalProtection_s* x)
{
  struct zx_ac_Extension_s* nxt;
  struct zx_ac_Extension_s* y;
  if (!x) return;
  y = x->Extension;
  if (!y) return;
  x->Extension = 0;
  while (y) {
    nxt = (struct zx_ac_Extension_s*)y->gg.g.n;
    y->gg.g.n = &x->Extension->gg.g;
    x->Extension = y;
    y = nxt;
  }
}

/* FUNC(zx_ac_TechnicalProtection_PUT_Extension) */

void zx_ac_TechnicalProtection_PUT_Extension(struct zx_ac_TechnicalProtection_s* x, int n, struct zx_ac_Extension_s* z)
{
  struct zx_ac_Extension_s* y;
  if (!x || !z) return;
  y = x->Extension;
  if (!y) return;
  switch (n) {
  case 0:
    z->gg.g.n = y->gg.g.n;
    x->Extension = z;
    return;
  default:
    for (; n > 1 && y->gg.g.n; --n, y = (struct zx_ac_Extension_s*)y->gg.g.n) ;
    if (!y->gg.g.n) return;
    z->gg.g.n = y->gg.g.n->n;
    y->gg.g.n = &z->gg.g;
  }
}

/* FUNC(zx_ac_TechnicalProtection_ADD_Extension) */

void zx_ac_TechnicalProtection_ADD_Extension(struct zx_ac_TechnicalProtection_s* x, int n, struct zx_ac_Extension_s* z)
{
  struct zx_ac_Extension_s* y;
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
    for (; y->gg.g.n; y = (struct zx_ac_Extension_s*)y->gg.g.n) ;
    break;
  default:
    for (y = x->Extension; n > 1 && y; --n, y = (struct zx_ac_Extension_s*)y->gg.g.n) ;
    if (!y) return;
  }
  z->gg.g.n = y->gg.g.n;
  y->gg.g.n = &z->gg.g;
}

/* FUNC(zx_ac_TechnicalProtection_DEL_Extension) */

void zx_ac_TechnicalProtection_DEL_Extension(struct zx_ac_TechnicalProtection_s* x, int n)
{
  struct zx_ac_Extension_s* y;
  if (!x) return;
  switch (n) {
  case 0:
    x->Extension = (struct zx_ac_Extension_s*)x->Extension->gg.g.n;
    return;
  case -1:
    y = (struct zx_ac_Extension_s*)x->Extension;
    if (!y) return;
    for (; y->gg.g.n; y = (struct zx_ac_Extension_s*)y->gg.g.n) ;
    break;
  default:
    for (y = x->Extension; n > 1 && y->gg.g.n; --n, y = (struct zx_ac_Extension_s*)y->gg.g.n) ;
    if (!y->gg.g.n) return;
  }
  y->gg.g.n = y->gg.g.n->n;
}

#endif






/* FUNC(zx_ac_TimeSyncToken_GET_DeviceInHand) */
struct zx_str* zx_ac_TimeSyncToken_GET_DeviceInHand(struct zx_ac_TimeSyncToken_s* x) { return x->DeviceInHand; }
/* FUNC(zx_ac_TimeSyncToken_PUT_DeviceInHand) */
void zx_ac_TimeSyncToken_PUT_DeviceInHand(struct zx_ac_TimeSyncToken_s* x, struct zx_str* y) { x->DeviceInHand = y; }
/* FUNC(zx_ac_TimeSyncToken_GET_DeviceType) */
struct zx_str* zx_ac_TimeSyncToken_GET_DeviceType(struct zx_ac_TimeSyncToken_s* x) { return x->DeviceType; }
/* FUNC(zx_ac_TimeSyncToken_PUT_DeviceType) */
void zx_ac_TimeSyncToken_PUT_DeviceType(struct zx_ac_TimeSyncToken_s* x, struct zx_str* y) { x->DeviceType = y; }
/* FUNC(zx_ac_TimeSyncToken_GET_SeedLength) */
struct zx_str* zx_ac_TimeSyncToken_GET_SeedLength(struct zx_ac_TimeSyncToken_s* x) { return x->SeedLength; }
/* FUNC(zx_ac_TimeSyncToken_PUT_SeedLength) */
void zx_ac_TimeSyncToken_PUT_SeedLength(struct zx_ac_TimeSyncToken_s* x, struct zx_str* y) { x->SeedLength = y; }







#ifdef ZX_ENA_GETPUT

/* FUNC(zx_ac_Token_NUM_TimeSyncToken) */

int zx_ac_Token_NUM_TimeSyncToken(struct zx_ac_Token_s* x)
{
  struct zx_ac_TimeSyncToken_s* y;
  int n = 0;
  if (!x) return 0;
  for (y = x->TimeSyncToken; y; ++n, y = (struct zx_ac_TimeSyncToken_s*)y->gg.g.n) ;
  return n;
}

/* FUNC(zx_ac_Token_GET_TimeSyncToken) */

struct zx_ac_TimeSyncToken_s* zx_ac_Token_GET_TimeSyncToken(struct zx_ac_Token_s* x, int n)
{
  struct zx_ac_TimeSyncToken_s* y;
  if (!x) return 0;
  for (y = x->TimeSyncToken; n>=0 && y; --n, y = (struct zx_ac_TimeSyncToken_s*)y->gg.g.n) ;
  return y;
}

/* FUNC(zx_ac_Token_POP_TimeSyncToken) */

struct zx_ac_TimeSyncToken_s* zx_ac_Token_POP_TimeSyncToken(struct zx_ac_Token_s* x)
{
  struct zx_ac_TimeSyncToken_s* y;
  if (!x) return 0;
  y = x->TimeSyncToken;
  if (y)
    x->TimeSyncToken = (struct zx_ac_TimeSyncToken_s*)y->gg.g.n;
  return y;
}

/* FUNC(zx_ac_Token_PUSH_TimeSyncToken) */

void zx_ac_Token_PUSH_TimeSyncToken(struct zx_ac_Token_s* x, struct zx_ac_TimeSyncToken_s* z)
{
  if (!x || !z) return;
  z->gg.g.n = &x->TimeSyncToken->gg.g;
  x->TimeSyncToken = z;
}

/* FUNC(zx_ac_Token_REV_TimeSyncToken) */

void zx_ac_Token_REV_TimeSyncToken(struct zx_ac_Token_s* x)
{
  struct zx_ac_TimeSyncToken_s* nxt;
  struct zx_ac_TimeSyncToken_s* y;
  if (!x) return;
  y = x->TimeSyncToken;
  if (!y) return;
  x->TimeSyncToken = 0;
  while (y) {
    nxt = (struct zx_ac_TimeSyncToken_s*)y->gg.g.n;
    y->gg.g.n = &x->TimeSyncToken->gg.g;
    x->TimeSyncToken = y;
    y = nxt;
  }
}

/* FUNC(zx_ac_Token_PUT_TimeSyncToken) */

void zx_ac_Token_PUT_TimeSyncToken(struct zx_ac_Token_s* x, int n, struct zx_ac_TimeSyncToken_s* z)
{
  struct zx_ac_TimeSyncToken_s* y;
  if (!x || !z) return;
  y = x->TimeSyncToken;
  if (!y) return;
  switch (n) {
  case 0:
    z->gg.g.n = y->gg.g.n;
    x->TimeSyncToken = z;
    return;
  default:
    for (; n > 1 && y->gg.g.n; --n, y = (struct zx_ac_TimeSyncToken_s*)y->gg.g.n) ;
    if (!y->gg.g.n) return;
    z->gg.g.n = y->gg.g.n->n;
    y->gg.g.n = &z->gg.g;
  }
}

/* FUNC(zx_ac_Token_ADD_TimeSyncToken) */

void zx_ac_Token_ADD_TimeSyncToken(struct zx_ac_Token_s* x, int n, struct zx_ac_TimeSyncToken_s* z)
{
  struct zx_ac_TimeSyncToken_s* y;
  if (!x || !z) return;
  switch (n) {
  case 0:
  add_to_start:
    z->gg.g.n = &x->TimeSyncToken->gg.g;
    x->TimeSyncToken = z;
    return;
  case -1:
    y = x->TimeSyncToken;
    if (!y) goto add_to_start;
    for (; y->gg.g.n; y = (struct zx_ac_TimeSyncToken_s*)y->gg.g.n) ;
    break;
  default:
    for (y = x->TimeSyncToken; n > 1 && y; --n, y = (struct zx_ac_TimeSyncToken_s*)y->gg.g.n) ;
    if (!y) return;
  }
  z->gg.g.n = y->gg.g.n;
  y->gg.g.n = &z->gg.g;
}

/* FUNC(zx_ac_Token_DEL_TimeSyncToken) */

void zx_ac_Token_DEL_TimeSyncToken(struct zx_ac_Token_s* x, int n)
{
  struct zx_ac_TimeSyncToken_s* y;
  if (!x) return;
  switch (n) {
  case 0:
    x->TimeSyncToken = (struct zx_ac_TimeSyncToken_s*)x->TimeSyncToken->gg.g.n;
    return;
  case -1:
    y = (struct zx_ac_TimeSyncToken_s*)x->TimeSyncToken;
    if (!y) return;
    for (; y->gg.g.n; y = (struct zx_ac_TimeSyncToken_s*)y->gg.g.n) ;
    break;
  default:
    for (y = x->TimeSyncToken; n > 1 && y->gg.g.n; --n, y = (struct zx_ac_TimeSyncToken_s*)y->gg.g.n) ;
    if (!y->gg.g.n) return;
  }
  y->gg.g.n = y->gg.g.n->n;
}

#endif



#ifdef ZX_ENA_GETPUT

/* FUNC(zx_ac_Token_NUM_Extension) */

int zx_ac_Token_NUM_Extension(struct zx_ac_Token_s* x)
{
  struct zx_ac_Extension_s* y;
  int n = 0;
  if (!x) return 0;
  for (y = x->Extension; y; ++n, y = (struct zx_ac_Extension_s*)y->gg.g.n) ;
  return n;
}

/* FUNC(zx_ac_Token_GET_Extension) */

struct zx_ac_Extension_s* zx_ac_Token_GET_Extension(struct zx_ac_Token_s* x, int n)
{
  struct zx_ac_Extension_s* y;
  if (!x) return 0;
  for (y = x->Extension; n>=0 && y; --n, y = (struct zx_ac_Extension_s*)y->gg.g.n) ;
  return y;
}

/* FUNC(zx_ac_Token_POP_Extension) */

struct zx_ac_Extension_s* zx_ac_Token_POP_Extension(struct zx_ac_Token_s* x)
{
  struct zx_ac_Extension_s* y;
  if (!x) return 0;
  y = x->Extension;
  if (y)
    x->Extension = (struct zx_ac_Extension_s*)y->gg.g.n;
  return y;
}

/* FUNC(zx_ac_Token_PUSH_Extension) */

void zx_ac_Token_PUSH_Extension(struct zx_ac_Token_s* x, struct zx_ac_Extension_s* z)
{
  if (!x || !z) return;
  z->gg.g.n = &x->Extension->gg.g;
  x->Extension = z;
}

/* FUNC(zx_ac_Token_REV_Extension) */

void zx_ac_Token_REV_Extension(struct zx_ac_Token_s* x)
{
  struct zx_ac_Extension_s* nxt;
  struct zx_ac_Extension_s* y;
  if (!x) return;
  y = x->Extension;
  if (!y) return;
  x->Extension = 0;
  while (y) {
    nxt = (struct zx_ac_Extension_s*)y->gg.g.n;
    y->gg.g.n = &x->Extension->gg.g;
    x->Extension = y;
    y = nxt;
  }
}

/* FUNC(zx_ac_Token_PUT_Extension) */

void zx_ac_Token_PUT_Extension(struct zx_ac_Token_s* x, int n, struct zx_ac_Extension_s* z)
{
  struct zx_ac_Extension_s* y;
  if (!x || !z) return;
  y = x->Extension;
  if (!y) return;
  switch (n) {
  case 0:
    z->gg.g.n = y->gg.g.n;
    x->Extension = z;
    return;
  default:
    for (; n > 1 && y->gg.g.n; --n, y = (struct zx_ac_Extension_s*)y->gg.g.n) ;
    if (!y->gg.g.n) return;
    z->gg.g.n = y->gg.g.n->n;
    y->gg.g.n = &z->gg.g;
  }
}

/* FUNC(zx_ac_Token_ADD_Extension) */

void zx_ac_Token_ADD_Extension(struct zx_ac_Token_s* x, int n, struct zx_ac_Extension_s* z)
{
  struct zx_ac_Extension_s* y;
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
    for (; y->gg.g.n; y = (struct zx_ac_Extension_s*)y->gg.g.n) ;
    break;
  default:
    for (y = x->Extension; n > 1 && y; --n, y = (struct zx_ac_Extension_s*)y->gg.g.n) ;
    if (!y) return;
  }
  z->gg.g.n = y->gg.g.n;
  y->gg.g.n = &z->gg.g;
}

/* FUNC(zx_ac_Token_DEL_Extension) */

void zx_ac_Token_DEL_Extension(struct zx_ac_Token_s* x, int n)
{
  struct zx_ac_Extension_s* y;
  if (!x) return;
  switch (n) {
  case 0:
    x->Extension = (struct zx_ac_Extension_s*)x->Extension->gg.g.n;
    return;
  case -1:
    y = (struct zx_ac_Extension_s*)x->Extension;
    if (!y) return;
    for (; y->gg.g.n; y = (struct zx_ac_Extension_s*)y->gg.g.n) ;
    break;
  default:
    for (y = x->Extension; n > 1 && y->gg.g.n; --n, y = (struct zx_ac_Extension_s*)y->gg.g.n) ;
    if (!y->gg.g.n) return;
  }
  y->gg.g.n = y->gg.g.n->n;
}

#endif








#ifdef ZX_ENA_GETPUT

/* FUNC(zx_ac_WTLS_NUM_Extension) */

int zx_ac_WTLS_NUM_Extension(struct zx_ac_WTLS_s* x)
{
  struct zx_ac_Extension_s* y;
  int n = 0;
  if (!x) return 0;
  for (y = x->Extension; y; ++n, y = (struct zx_ac_Extension_s*)y->gg.g.n) ;
  return n;
}

/* FUNC(zx_ac_WTLS_GET_Extension) */

struct zx_ac_Extension_s* zx_ac_WTLS_GET_Extension(struct zx_ac_WTLS_s* x, int n)
{
  struct zx_ac_Extension_s* y;
  if (!x) return 0;
  for (y = x->Extension; n>=0 && y; --n, y = (struct zx_ac_Extension_s*)y->gg.g.n) ;
  return y;
}

/* FUNC(zx_ac_WTLS_POP_Extension) */

struct zx_ac_Extension_s* zx_ac_WTLS_POP_Extension(struct zx_ac_WTLS_s* x)
{
  struct zx_ac_Extension_s* y;
  if (!x) return 0;
  y = x->Extension;
  if (y)
    x->Extension = (struct zx_ac_Extension_s*)y->gg.g.n;
  return y;
}

/* FUNC(zx_ac_WTLS_PUSH_Extension) */

void zx_ac_WTLS_PUSH_Extension(struct zx_ac_WTLS_s* x, struct zx_ac_Extension_s* z)
{
  if (!x || !z) return;
  z->gg.g.n = &x->Extension->gg.g;
  x->Extension = z;
}

/* FUNC(zx_ac_WTLS_REV_Extension) */

void zx_ac_WTLS_REV_Extension(struct zx_ac_WTLS_s* x)
{
  struct zx_ac_Extension_s* nxt;
  struct zx_ac_Extension_s* y;
  if (!x) return;
  y = x->Extension;
  if (!y) return;
  x->Extension = 0;
  while (y) {
    nxt = (struct zx_ac_Extension_s*)y->gg.g.n;
    y->gg.g.n = &x->Extension->gg.g;
    x->Extension = y;
    y = nxt;
  }
}

/* FUNC(zx_ac_WTLS_PUT_Extension) */

void zx_ac_WTLS_PUT_Extension(struct zx_ac_WTLS_s* x, int n, struct zx_ac_Extension_s* z)
{
  struct zx_ac_Extension_s* y;
  if (!x || !z) return;
  y = x->Extension;
  if (!y) return;
  switch (n) {
  case 0:
    z->gg.g.n = y->gg.g.n;
    x->Extension = z;
    return;
  default:
    for (; n > 1 && y->gg.g.n; --n, y = (struct zx_ac_Extension_s*)y->gg.g.n) ;
    if (!y->gg.g.n) return;
    z->gg.g.n = y->gg.g.n->n;
    y->gg.g.n = &z->gg.g;
  }
}

/* FUNC(zx_ac_WTLS_ADD_Extension) */

void zx_ac_WTLS_ADD_Extension(struct zx_ac_WTLS_s* x, int n, struct zx_ac_Extension_s* z)
{
  struct zx_ac_Extension_s* y;
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
    for (; y->gg.g.n; y = (struct zx_ac_Extension_s*)y->gg.g.n) ;
    break;
  default:
    for (y = x->Extension; n > 1 && y; --n, y = (struct zx_ac_Extension_s*)y->gg.g.n) ;
    if (!y) return;
  }
  z->gg.g.n = y->gg.g.n;
  y->gg.g.n = &z->gg.g;
}

/* FUNC(zx_ac_WTLS_DEL_Extension) */

void zx_ac_WTLS_DEL_Extension(struct zx_ac_WTLS_s* x, int n)
{
  struct zx_ac_Extension_s* y;
  if (!x) return;
  switch (n) {
  case 0:
    x->Extension = (struct zx_ac_Extension_s*)x->Extension->gg.g.n;
    return;
  case -1:
    y = (struct zx_ac_Extension_s*)x->Extension;
    if (!y) return;
    for (; y->gg.g.n; y = (struct zx_ac_Extension_s*)y->gg.g.n) ;
    break;
  default:
    for (y = x->Extension; n > 1 && y->gg.g.n; --n, y = (struct zx_ac_Extension_s*)y->gg.g.n) ;
    if (!y->gg.g.n) return;
  }
  y->gg.g.n = y->gg.g.n->n;
}

#endif








#ifdef ZX_ENA_GETPUT

/* FUNC(zx_ac_WrittenConsent_NUM_Extension) */

int zx_ac_WrittenConsent_NUM_Extension(struct zx_ac_WrittenConsent_s* x)
{
  struct zx_ac_Extension_s* y;
  int n = 0;
  if (!x) return 0;
  for (y = x->Extension; y; ++n, y = (struct zx_ac_Extension_s*)y->gg.g.n) ;
  return n;
}

/* FUNC(zx_ac_WrittenConsent_GET_Extension) */

struct zx_ac_Extension_s* zx_ac_WrittenConsent_GET_Extension(struct zx_ac_WrittenConsent_s* x, int n)
{
  struct zx_ac_Extension_s* y;
  if (!x) return 0;
  for (y = x->Extension; n>=0 && y; --n, y = (struct zx_ac_Extension_s*)y->gg.g.n) ;
  return y;
}

/* FUNC(zx_ac_WrittenConsent_POP_Extension) */

struct zx_ac_Extension_s* zx_ac_WrittenConsent_POP_Extension(struct zx_ac_WrittenConsent_s* x)
{
  struct zx_ac_Extension_s* y;
  if (!x) return 0;
  y = x->Extension;
  if (y)
    x->Extension = (struct zx_ac_Extension_s*)y->gg.g.n;
  return y;
}

/* FUNC(zx_ac_WrittenConsent_PUSH_Extension) */

void zx_ac_WrittenConsent_PUSH_Extension(struct zx_ac_WrittenConsent_s* x, struct zx_ac_Extension_s* z)
{
  if (!x || !z) return;
  z->gg.g.n = &x->Extension->gg.g;
  x->Extension = z;
}

/* FUNC(zx_ac_WrittenConsent_REV_Extension) */

void zx_ac_WrittenConsent_REV_Extension(struct zx_ac_WrittenConsent_s* x)
{
  struct zx_ac_Extension_s* nxt;
  struct zx_ac_Extension_s* y;
  if (!x) return;
  y = x->Extension;
  if (!y) return;
  x->Extension = 0;
  while (y) {
    nxt = (struct zx_ac_Extension_s*)y->gg.g.n;
    y->gg.g.n = &x->Extension->gg.g;
    x->Extension = y;
    y = nxt;
  }
}

/* FUNC(zx_ac_WrittenConsent_PUT_Extension) */

void zx_ac_WrittenConsent_PUT_Extension(struct zx_ac_WrittenConsent_s* x, int n, struct zx_ac_Extension_s* z)
{
  struct zx_ac_Extension_s* y;
  if (!x || !z) return;
  y = x->Extension;
  if (!y) return;
  switch (n) {
  case 0:
    z->gg.g.n = y->gg.g.n;
    x->Extension = z;
    return;
  default:
    for (; n > 1 && y->gg.g.n; --n, y = (struct zx_ac_Extension_s*)y->gg.g.n) ;
    if (!y->gg.g.n) return;
    z->gg.g.n = y->gg.g.n->n;
    y->gg.g.n = &z->gg.g;
  }
}

/* FUNC(zx_ac_WrittenConsent_ADD_Extension) */

void zx_ac_WrittenConsent_ADD_Extension(struct zx_ac_WrittenConsent_s* x, int n, struct zx_ac_Extension_s* z)
{
  struct zx_ac_Extension_s* y;
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
    for (; y->gg.g.n; y = (struct zx_ac_Extension_s*)y->gg.g.n) ;
    break;
  default:
    for (y = x->Extension; n > 1 && y; --n, y = (struct zx_ac_Extension_s*)y->gg.g.n) ;
    if (!y) return;
  }
  z->gg.g.n = y->gg.g.n;
  y->gg.g.n = &z->gg.g;
}

/* FUNC(zx_ac_WrittenConsent_DEL_Extension) */

void zx_ac_WrittenConsent_DEL_Extension(struct zx_ac_WrittenConsent_s* x, int n)
{
  struct zx_ac_Extension_s* y;
  if (!x) return;
  switch (n) {
  case 0:
    x->Extension = (struct zx_ac_Extension_s*)x->Extension->gg.g.n;
    return;
  case -1:
    y = (struct zx_ac_Extension_s*)x->Extension;
    if (!y) return;
    for (; y->gg.g.n; y = (struct zx_ac_Extension_s*)y->gg.g.n) ;
    break;
  default:
    for (y = x->Extension; n > 1 && y->gg.g.n; --n, y = (struct zx_ac_Extension_s*)y->gg.g.n) ;
    if (!y->gg.g.n) return;
  }
  y->gg.g.n = y->gg.g.n->n;
}

#endif








#ifdef ZX_ENA_GETPUT

/* FUNC(zx_ac_ZeroKnowledge_NUM_Extension) */

int zx_ac_ZeroKnowledge_NUM_Extension(struct zx_ac_ZeroKnowledge_s* x)
{
  struct zx_ac_Extension_s* y;
  int n = 0;
  if (!x) return 0;
  for (y = x->Extension; y; ++n, y = (struct zx_ac_Extension_s*)y->gg.g.n) ;
  return n;
}

/* FUNC(zx_ac_ZeroKnowledge_GET_Extension) */

struct zx_ac_Extension_s* zx_ac_ZeroKnowledge_GET_Extension(struct zx_ac_ZeroKnowledge_s* x, int n)
{
  struct zx_ac_Extension_s* y;
  if (!x) return 0;
  for (y = x->Extension; n>=0 && y; --n, y = (struct zx_ac_Extension_s*)y->gg.g.n) ;
  return y;
}

/* FUNC(zx_ac_ZeroKnowledge_POP_Extension) */

struct zx_ac_Extension_s* zx_ac_ZeroKnowledge_POP_Extension(struct zx_ac_ZeroKnowledge_s* x)
{
  struct zx_ac_Extension_s* y;
  if (!x) return 0;
  y = x->Extension;
  if (y)
    x->Extension = (struct zx_ac_Extension_s*)y->gg.g.n;
  return y;
}

/* FUNC(zx_ac_ZeroKnowledge_PUSH_Extension) */

void zx_ac_ZeroKnowledge_PUSH_Extension(struct zx_ac_ZeroKnowledge_s* x, struct zx_ac_Extension_s* z)
{
  if (!x || !z) return;
  z->gg.g.n = &x->Extension->gg.g;
  x->Extension = z;
}

/* FUNC(zx_ac_ZeroKnowledge_REV_Extension) */

void zx_ac_ZeroKnowledge_REV_Extension(struct zx_ac_ZeroKnowledge_s* x)
{
  struct zx_ac_Extension_s* nxt;
  struct zx_ac_Extension_s* y;
  if (!x) return;
  y = x->Extension;
  if (!y) return;
  x->Extension = 0;
  while (y) {
    nxt = (struct zx_ac_Extension_s*)y->gg.g.n;
    y->gg.g.n = &x->Extension->gg.g;
    x->Extension = y;
    y = nxt;
  }
}

/* FUNC(zx_ac_ZeroKnowledge_PUT_Extension) */

void zx_ac_ZeroKnowledge_PUT_Extension(struct zx_ac_ZeroKnowledge_s* x, int n, struct zx_ac_Extension_s* z)
{
  struct zx_ac_Extension_s* y;
  if (!x || !z) return;
  y = x->Extension;
  if (!y) return;
  switch (n) {
  case 0:
    z->gg.g.n = y->gg.g.n;
    x->Extension = z;
    return;
  default:
    for (; n > 1 && y->gg.g.n; --n, y = (struct zx_ac_Extension_s*)y->gg.g.n) ;
    if (!y->gg.g.n) return;
    z->gg.g.n = y->gg.g.n->n;
    y->gg.g.n = &z->gg.g;
  }
}

/* FUNC(zx_ac_ZeroKnowledge_ADD_Extension) */

void zx_ac_ZeroKnowledge_ADD_Extension(struct zx_ac_ZeroKnowledge_s* x, int n, struct zx_ac_Extension_s* z)
{
  struct zx_ac_Extension_s* y;
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
    for (; y->gg.g.n; y = (struct zx_ac_Extension_s*)y->gg.g.n) ;
    break;
  default:
    for (y = x->Extension; n > 1 && y; --n, y = (struct zx_ac_Extension_s*)y->gg.g.n) ;
    if (!y) return;
  }
  z->gg.g.n = y->gg.g.n;
  y->gg.g.n = &z->gg.g;
}

/* FUNC(zx_ac_ZeroKnowledge_DEL_Extension) */

void zx_ac_ZeroKnowledge_DEL_Extension(struct zx_ac_ZeroKnowledge_s* x, int n)
{
  struct zx_ac_Extension_s* y;
  if (!x) return;
  switch (n) {
  case 0:
    x->Extension = (struct zx_ac_Extension_s*)x->Extension->gg.g.n;
    return;
  case -1:
    y = (struct zx_ac_Extension_s*)x->Extension;
    if (!y) return;
    for (; y->gg.g.n; y = (struct zx_ac_Extension_s*)y->gg.g.n) ;
    break;
  default:
    for (y = x->Extension; n > 1 && y->gg.g.n; --n, y = (struct zx_ac_Extension_s*)y->gg.g.n) ;
    if (!y->gg.g.n) return;
  }
  y->gg.g.n = y->gg.g.n->n;
}

#endif






/* EOF -- c/zx-ac-getput.c */
