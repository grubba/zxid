/* c/zx-is-getput.c - WARNING: This file was automatically generated. DO NOT EDIT!
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
#include "c/zx-is-data.h"



#ifdef ZX_ENA_GETPUT

/* FUNC(zx_is_Confirm_NUM_Help) */

int zx_is_Confirm_NUM_Help(struct zx_is_Confirm_s* x)
{
  struct zx_is_Help_s* y;
  int n = 0;
  if (!x) return 0;
  for (y = x->Help; y; ++n, y = (struct zx_is_Help_s*)y->gg.g.n) ;
  return n;
}

/* FUNC(zx_is_Confirm_GET_Help) */

struct zx_is_Help_s* zx_is_Confirm_GET_Help(struct zx_is_Confirm_s* x, int n)
{
  struct zx_is_Help_s* y;
  if (!x) return 0;
  for (y = x->Help; n>=0 && y; --n, y = (struct zx_is_Help_s*)y->gg.g.n) ;
  return y;
}

/* FUNC(zx_is_Confirm_POP_Help) */

struct zx_is_Help_s* zx_is_Confirm_POP_Help(struct zx_is_Confirm_s* x)
{
  struct zx_is_Help_s* y;
  if (!x) return 0;
  y = x->Help;
  if (y)
    x->Help = (struct zx_is_Help_s*)y->gg.g.n;
  return y;
}

/* FUNC(zx_is_Confirm_PUSH_Help) */

void zx_is_Confirm_PUSH_Help(struct zx_is_Confirm_s* x, struct zx_is_Help_s* z)
{
  if (!x || !z) return;
  z->gg.g.n = &x->Help->gg.g;
  x->Help = z;
}

/* FUNC(zx_is_Confirm_REV_Help) */

void zx_is_Confirm_REV_Help(struct zx_is_Confirm_s* x)
{
  struct zx_is_Help_s* nxt;
  struct zx_is_Help_s* y;
  if (!x) return;
  y = x->Help;
  if (!y) return;
  x->Help = 0;
  while (y) {
    nxt = (struct zx_is_Help_s*)y->gg.g.n;
    y->gg.g.n = &x->Help->gg.g;
    x->Help = y;
    y = nxt;
  }
}

/* FUNC(zx_is_Confirm_PUT_Help) */

void zx_is_Confirm_PUT_Help(struct zx_is_Confirm_s* x, int n, struct zx_is_Help_s* z)
{
  struct zx_is_Help_s* y;
  if (!x || !z) return;
  y = x->Help;
  if (!y) return;
  switch (n) {
  case 0:
    z->gg.g.n = y->gg.g.n;
    x->Help = z;
    return;
  default:
    for (; n > 1 && y->gg.g.n; --n, y = (struct zx_is_Help_s*)y->gg.g.n) ;
    if (!y->gg.g.n) return;
    z->gg.g.n = y->gg.g.n->n;
    y->gg.g.n = &z->gg.g;
  }
}

/* FUNC(zx_is_Confirm_ADD_Help) */

void zx_is_Confirm_ADD_Help(struct zx_is_Confirm_s* x, int n, struct zx_is_Help_s* z)
{
  struct zx_is_Help_s* y;
  if (!x || !z) return;
  switch (n) {
  case 0:
  add_to_start:
    z->gg.g.n = &x->Help->gg.g;
    x->Help = z;
    return;
  case -1:
    y = x->Help;
    if (!y) goto add_to_start;
    for (; y->gg.g.n; y = (struct zx_is_Help_s*)y->gg.g.n) ;
    break;
  default:
    for (y = x->Help; n > 1 && y; --n, y = (struct zx_is_Help_s*)y->gg.g.n) ;
    if (!y) return;
  }
  z->gg.g.n = y->gg.g.n;
  y->gg.g.n = &z->gg.g;
}

/* FUNC(zx_is_Confirm_DEL_Help) */

void zx_is_Confirm_DEL_Help(struct zx_is_Confirm_s* x, int n)
{
  struct zx_is_Help_s* y;
  if (!x) return;
  switch (n) {
  case 0:
    x->Help = (struct zx_is_Help_s*)x->Help->gg.g.n;
    return;
  case -1:
    y = (struct zx_is_Help_s*)x->Help;
    if (!y) return;
    for (; y->gg.g.n; y = (struct zx_is_Help_s*)y->gg.g.n) ;
    break;
  default:
    for (y = x->Help; n > 1 && y->gg.g.n; --n, y = (struct zx_is_Help_s*)y->gg.g.n) ;
    if (!y->gg.g.n) return;
  }
  y->gg.g.n = y->gg.g.n->n;
}

#endif



#ifdef ZX_ENA_GETPUT

/* FUNC(zx_is_Confirm_NUM_Hint) */

int zx_is_Confirm_NUM_Hint(struct zx_is_Confirm_s* x)
{
  struct zx_elem_s* y;
  int n = 0;
  if (!x) return 0;
  for (y = x->Hint; y; ++n, y = (struct zx_elem_s*)y->g.n) ;
  return n;
}

/* FUNC(zx_is_Confirm_GET_Hint) */

struct zx_elem_s* zx_is_Confirm_GET_Hint(struct zx_is_Confirm_s* x, int n)
{
  struct zx_elem_s* y;
  if (!x) return 0;
  for (y = x->Hint; n>=0 && y; --n, y = (struct zx_elem_s*)y->g.n) ;
  return y;
}

/* FUNC(zx_is_Confirm_POP_Hint) */

struct zx_elem_s* zx_is_Confirm_POP_Hint(struct zx_is_Confirm_s* x)
{
  struct zx_elem_s* y;
  if (!x) return 0;
  y = x->Hint;
  if (y)
    x->Hint = (struct zx_elem_s*)y->g.n;
  return y;
}

/* FUNC(zx_is_Confirm_PUSH_Hint) */

void zx_is_Confirm_PUSH_Hint(struct zx_is_Confirm_s* x, struct zx_elem_s* z)
{
  if (!x || !z) return;
  z->g.n = &x->Hint->g;
  x->Hint = z;
}

/* FUNC(zx_is_Confirm_REV_Hint) */

void zx_is_Confirm_REV_Hint(struct zx_is_Confirm_s* x)
{
  struct zx_elem_s* nxt;
  struct zx_elem_s* y;
  if (!x) return;
  y = x->Hint;
  if (!y) return;
  x->Hint = 0;
  while (y) {
    nxt = (struct zx_elem_s*)y->g.n;
    y->g.n = &x->Hint->g;
    x->Hint = y;
    y = nxt;
  }
}

/* FUNC(zx_is_Confirm_PUT_Hint) */

void zx_is_Confirm_PUT_Hint(struct zx_is_Confirm_s* x, int n, struct zx_elem_s* z)
{
  struct zx_elem_s* y;
  if (!x || !z) return;
  y = x->Hint;
  if (!y) return;
  switch (n) {
  case 0:
    z->g.n = y->g.n;
    x->Hint = z;
    return;
  default:
    for (; n > 1 && y->g.n; --n, y = (struct zx_elem_s*)y->g.n) ;
    if (!y->g.n) return;
    z->g.n = y->g.n->n;
    y->g.n = &z->g;
  }
}

/* FUNC(zx_is_Confirm_ADD_Hint) */

void zx_is_Confirm_ADD_Hint(struct zx_is_Confirm_s* x, int n, struct zx_elem_s* z)
{
  struct zx_elem_s* y;
  if (!x || !z) return;
  switch (n) {
  case 0:
  add_to_start:
    z->g.n = &x->Hint->g;
    x->Hint = z;
    return;
  case -1:
    y = x->Hint;
    if (!y) goto add_to_start;
    for (; y->g.n; y = (struct zx_elem_s*)y->g.n) ;
    break;
  default:
    for (y = x->Hint; n > 1 && y; --n, y = (struct zx_elem_s*)y->g.n) ;
    if (!y) return;
  }
  z->g.n = y->g.n;
  y->g.n = &z->g;
}

/* FUNC(zx_is_Confirm_DEL_Hint) */

void zx_is_Confirm_DEL_Hint(struct zx_is_Confirm_s* x, int n)
{
  struct zx_elem_s* y;
  if (!x) return;
  switch (n) {
  case 0:
    x->Hint = (struct zx_elem_s*)x->Hint->g.n;
    return;
  case -1:
    y = (struct zx_elem_s*)x->Hint;
    if (!y) return;
    for (; y->g.n; y = (struct zx_elem_s*)y->g.n) ;
    break;
  default:
    for (y = x->Hint; n > 1 && y->g.n; --n, y = (struct zx_elem_s*)y->g.n) ;
    if (!y->g.n) return;
  }
  y->g.n = y->g.n->n;
}

#endif



#ifdef ZX_ENA_GETPUT

/* FUNC(zx_is_Confirm_NUM_Label) */

int zx_is_Confirm_NUM_Label(struct zx_is_Confirm_s* x)
{
  struct zx_elem_s* y;
  int n = 0;
  if (!x) return 0;
  for (y = x->Label; y; ++n, y = (struct zx_elem_s*)y->g.n) ;
  return n;
}

/* FUNC(zx_is_Confirm_GET_Label) */

struct zx_elem_s* zx_is_Confirm_GET_Label(struct zx_is_Confirm_s* x, int n)
{
  struct zx_elem_s* y;
  if (!x) return 0;
  for (y = x->Label; n>=0 && y; --n, y = (struct zx_elem_s*)y->g.n) ;
  return y;
}

/* FUNC(zx_is_Confirm_POP_Label) */

struct zx_elem_s* zx_is_Confirm_POP_Label(struct zx_is_Confirm_s* x)
{
  struct zx_elem_s* y;
  if (!x) return 0;
  y = x->Label;
  if (y)
    x->Label = (struct zx_elem_s*)y->g.n;
  return y;
}

/* FUNC(zx_is_Confirm_PUSH_Label) */

void zx_is_Confirm_PUSH_Label(struct zx_is_Confirm_s* x, struct zx_elem_s* z)
{
  if (!x || !z) return;
  z->g.n = &x->Label->g;
  x->Label = z;
}

/* FUNC(zx_is_Confirm_REV_Label) */

void zx_is_Confirm_REV_Label(struct zx_is_Confirm_s* x)
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

/* FUNC(zx_is_Confirm_PUT_Label) */

void zx_is_Confirm_PUT_Label(struct zx_is_Confirm_s* x, int n, struct zx_elem_s* z)
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

/* FUNC(zx_is_Confirm_ADD_Label) */

void zx_is_Confirm_ADD_Label(struct zx_is_Confirm_s* x, int n, struct zx_elem_s* z)
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

/* FUNC(zx_is_Confirm_DEL_Label) */

void zx_is_Confirm_DEL_Label(struct zx_is_Confirm_s* x, int n)
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

/* FUNC(zx_is_Confirm_NUM_Value) */

int zx_is_Confirm_NUM_Value(struct zx_is_Confirm_s* x)
{
  struct zx_elem_s* y;
  int n = 0;
  if (!x) return 0;
  for (y = x->Value; y; ++n, y = (struct zx_elem_s*)y->g.n) ;
  return n;
}

/* FUNC(zx_is_Confirm_GET_Value) */

struct zx_elem_s* zx_is_Confirm_GET_Value(struct zx_is_Confirm_s* x, int n)
{
  struct zx_elem_s* y;
  if (!x) return 0;
  for (y = x->Value; n>=0 && y; --n, y = (struct zx_elem_s*)y->g.n) ;
  return y;
}

/* FUNC(zx_is_Confirm_POP_Value) */

struct zx_elem_s* zx_is_Confirm_POP_Value(struct zx_is_Confirm_s* x)
{
  struct zx_elem_s* y;
  if (!x) return 0;
  y = x->Value;
  if (y)
    x->Value = (struct zx_elem_s*)y->g.n;
  return y;
}

/* FUNC(zx_is_Confirm_PUSH_Value) */

void zx_is_Confirm_PUSH_Value(struct zx_is_Confirm_s* x, struct zx_elem_s* z)
{
  if (!x || !z) return;
  z->g.n = &x->Value->g;
  x->Value = z;
}

/* FUNC(zx_is_Confirm_REV_Value) */

void zx_is_Confirm_REV_Value(struct zx_is_Confirm_s* x)
{
  struct zx_elem_s* nxt;
  struct zx_elem_s* y;
  if (!x) return;
  y = x->Value;
  if (!y) return;
  x->Value = 0;
  while (y) {
    nxt = (struct zx_elem_s*)y->g.n;
    y->g.n = &x->Value->g;
    x->Value = y;
    y = nxt;
  }
}

/* FUNC(zx_is_Confirm_PUT_Value) */

void zx_is_Confirm_PUT_Value(struct zx_is_Confirm_s* x, int n, struct zx_elem_s* z)
{
  struct zx_elem_s* y;
  if (!x || !z) return;
  y = x->Value;
  if (!y) return;
  switch (n) {
  case 0:
    z->g.n = y->g.n;
    x->Value = z;
    return;
  default:
    for (; n > 1 && y->g.n; --n, y = (struct zx_elem_s*)y->g.n) ;
    if (!y->g.n) return;
    z->g.n = y->g.n->n;
    y->g.n = &z->g;
  }
}

/* FUNC(zx_is_Confirm_ADD_Value) */

void zx_is_Confirm_ADD_Value(struct zx_is_Confirm_s* x, int n, struct zx_elem_s* z)
{
  struct zx_elem_s* y;
  if (!x || !z) return;
  switch (n) {
  case 0:
  add_to_start:
    z->g.n = &x->Value->g;
    x->Value = z;
    return;
  case -1:
    y = x->Value;
    if (!y) goto add_to_start;
    for (; y->g.n; y = (struct zx_elem_s*)y->g.n) ;
    break;
  default:
    for (y = x->Value; n > 1 && y; --n, y = (struct zx_elem_s*)y->g.n) ;
    if (!y) return;
  }
  z->g.n = y->g.n;
  y->g.n = &z->g;
}

/* FUNC(zx_is_Confirm_DEL_Value) */

void zx_is_Confirm_DEL_Value(struct zx_is_Confirm_s* x, int n)
{
  struct zx_elem_s* y;
  if (!x) return;
  switch (n) {
  case 0:
    x->Value = (struct zx_elem_s*)x->Value->g.n;
    return;
  case -1:
    y = (struct zx_elem_s*)x->Value;
    if (!y) return;
    for (; y->g.n; y = (struct zx_elem_s*)y->g.n) ;
    break;
  default:
    for (y = x->Value; n > 1 && y->g.n; --n, y = (struct zx_elem_s*)y->g.n) ;
    if (!y->g.n) return;
  }
  y->g.n = y->g.n->n;
}

#endif

/* FUNC(zx_is_Confirm_GET_name) */
struct zx_str* zx_is_Confirm_GET_name(struct zx_is_Confirm_s* x) { return x->name; }
/* FUNC(zx_is_Confirm_PUT_name) */
void zx_is_Confirm_PUT_name(struct zx_is_Confirm_s* x, struct zx_str* y) { x->name = y; }





/* FUNC(zx_is_Help_GET_label) */
struct zx_str* zx_is_Help_GET_label(struct zx_is_Help_s* x) { return x->label; }
/* FUNC(zx_is_Help_PUT_label) */
void zx_is_Help_PUT_label(struct zx_is_Help_s* x, struct zx_str* y) { x->label = y; }
/* FUNC(zx_is_Help_GET_link) */
struct zx_str* zx_is_Help_GET_link(struct zx_is_Help_s* x) { return x->link; }
/* FUNC(zx_is_Help_PUT_link) */
void zx_is_Help_PUT_link(struct zx_is_Help_s* x, struct zx_str* y) { x->link = y; }
/* FUNC(zx_is_Help_GET_moreLink) */
struct zx_str* zx_is_Help_GET_moreLink(struct zx_is_Help_s* x) { return x->moreLink; }
/* FUNC(zx_is_Help_PUT_moreLink) */
void zx_is_Help_PUT_moreLink(struct zx_is_Help_s* x, struct zx_str* y) { x->moreLink = y; }







#ifdef ZX_ENA_GETPUT

/* FUNC(zx_is_Inquiry_NUM_Help) */

int zx_is_Inquiry_NUM_Help(struct zx_is_Inquiry_s* x)
{
  struct zx_is_Help_s* y;
  int n = 0;
  if (!x) return 0;
  for (y = x->Help; y; ++n, y = (struct zx_is_Help_s*)y->gg.g.n) ;
  return n;
}

/* FUNC(zx_is_Inquiry_GET_Help) */

struct zx_is_Help_s* zx_is_Inquiry_GET_Help(struct zx_is_Inquiry_s* x, int n)
{
  struct zx_is_Help_s* y;
  if (!x) return 0;
  for (y = x->Help; n>=0 && y; --n, y = (struct zx_is_Help_s*)y->gg.g.n) ;
  return y;
}

/* FUNC(zx_is_Inquiry_POP_Help) */

struct zx_is_Help_s* zx_is_Inquiry_POP_Help(struct zx_is_Inquiry_s* x)
{
  struct zx_is_Help_s* y;
  if (!x) return 0;
  y = x->Help;
  if (y)
    x->Help = (struct zx_is_Help_s*)y->gg.g.n;
  return y;
}

/* FUNC(zx_is_Inquiry_PUSH_Help) */

void zx_is_Inquiry_PUSH_Help(struct zx_is_Inquiry_s* x, struct zx_is_Help_s* z)
{
  if (!x || !z) return;
  z->gg.g.n = &x->Help->gg.g;
  x->Help = z;
}

/* FUNC(zx_is_Inquiry_REV_Help) */

void zx_is_Inquiry_REV_Help(struct zx_is_Inquiry_s* x)
{
  struct zx_is_Help_s* nxt;
  struct zx_is_Help_s* y;
  if (!x) return;
  y = x->Help;
  if (!y) return;
  x->Help = 0;
  while (y) {
    nxt = (struct zx_is_Help_s*)y->gg.g.n;
    y->gg.g.n = &x->Help->gg.g;
    x->Help = y;
    y = nxt;
  }
}

/* FUNC(zx_is_Inquiry_PUT_Help) */

void zx_is_Inquiry_PUT_Help(struct zx_is_Inquiry_s* x, int n, struct zx_is_Help_s* z)
{
  struct zx_is_Help_s* y;
  if (!x || !z) return;
  y = x->Help;
  if (!y) return;
  switch (n) {
  case 0:
    z->gg.g.n = y->gg.g.n;
    x->Help = z;
    return;
  default:
    for (; n > 1 && y->gg.g.n; --n, y = (struct zx_is_Help_s*)y->gg.g.n) ;
    if (!y->gg.g.n) return;
    z->gg.g.n = y->gg.g.n->n;
    y->gg.g.n = &z->gg.g;
  }
}

/* FUNC(zx_is_Inquiry_ADD_Help) */

void zx_is_Inquiry_ADD_Help(struct zx_is_Inquiry_s* x, int n, struct zx_is_Help_s* z)
{
  struct zx_is_Help_s* y;
  if (!x || !z) return;
  switch (n) {
  case 0:
  add_to_start:
    z->gg.g.n = &x->Help->gg.g;
    x->Help = z;
    return;
  case -1:
    y = x->Help;
    if (!y) goto add_to_start;
    for (; y->gg.g.n; y = (struct zx_is_Help_s*)y->gg.g.n) ;
    break;
  default:
    for (y = x->Help; n > 1 && y; --n, y = (struct zx_is_Help_s*)y->gg.g.n) ;
    if (!y) return;
  }
  z->gg.g.n = y->gg.g.n;
  y->gg.g.n = &z->gg.g;
}

/* FUNC(zx_is_Inquiry_DEL_Help) */

void zx_is_Inquiry_DEL_Help(struct zx_is_Inquiry_s* x, int n)
{
  struct zx_is_Help_s* y;
  if (!x) return;
  switch (n) {
  case 0:
    x->Help = (struct zx_is_Help_s*)x->Help->gg.g.n;
    return;
  case -1:
    y = (struct zx_is_Help_s*)x->Help;
    if (!y) return;
    for (; y->gg.g.n; y = (struct zx_is_Help_s*)y->gg.g.n) ;
    break;
  default:
    for (y = x->Help; n > 1 && y->gg.g.n; --n, y = (struct zx_is_Help_s*)y->gg.g.n) ;
    if (!y->gg.g.n) return;
  }
  y->gg.g.n = y->gg.g.n->n;
}

#endif



#ifdef ZX_ENA_GETPUT

/* FUNC(zx_is_Inquiry_NUM_Select) */

int zx_is_Inquiry_NUM_Select(struct zx_is_Inquiry_s* x)
{
  struct zx_is_Select_s* y;
  int n = 0;
  if (!x) return 0;
  for (y = x->Select; y; ++n, y = (struct zx_is_Select_s*)y->gg.g.n) ;
  return n;
}

/* FUNC(zx_is_Inquiry_GET_Select) */

struct zx_is_Select_s* zx_is_Inquiry_GET_Select(struct zx_is_Inquiry_s* x, int n)
{
  struct zx_is_Select_s* y;
  if (!x) return 0;
  for (y = x->Select; n>=0 && y; --n, y = (struct zx_is_Select_s*)y->gg.g.n) ;
  return y;
}

/* FUNC(zx_is_Inquiry_POP_Select) */

struct zx_is_Select_s* zx_is_Inquiry_POP_Select(struct zx_is_Inquiry_s* x)
{
  struct zx_is_Select_s* y;
  if (!x) return 0;
  y = x->Select;
  if (y)
    x->Select = (struct zx_is_Select_s*)y->gg.g.n;
  return y;
}

/* FUNC(zx_is_Inquiry_PUSH_Select) */

void zx_is_Inquiry_PUSH_Select(struct zx_is_Inquiry_s* x, struct zx_is_Select_s* z)
{
  if (!x || !z) return;
  z->gg.g.n = &x->Select->gg.g;
  x->Select = z;
}

/* FUNC(zx_is_Inquiry_REV_Select) */

void zx_is_Inquiry_REV_Select(struct zx_is_Inquiry_s* x)
{
  struct zx_is_Select_s* nxt;
  struct zx_is_Select_s* y;
  if (!x) return;
  y = x->Select;
  if (!y) return;
  x->Select = 0;
  while (y) {
    nxt = (struct zx_is_Select_s*)y->gg.g.n;
    y->gg.g.n = &x->Select->gg.g;
    x->Select = y;
    y = nxt;
  }
}

/* FUNC(zx_is_Inquiry_PUT_Select) */

void zx_is_Inquiry_PUT_Select(struct zx_is_Inquiry_s* x, int n, struct zx_is_Select_s* z)
{
  struct zx_is_Select_s* y;
  if (!x || !z) return;
  y = x->Select;
  if (!y) return;
  switch (n) {
  case 0:
    z->gg.g.n = y->gg.g.n;
    x->Select = z;
    return;
  default:
    for (; n > 1 && y->gg.g.n; --n, y = (struct zx_is_Select_s*)y->gg.g.n) ;
    if (!y->gg.g.n) return;
    z->gg.g.n = y->gg.g.n->n;
    y->gg.g.n = &z->gg.g;
  }
}

/* FUNC(zx_is_Inquiry_ADD_Select) */

void zx_is_Inquiry_ADD_Select(struct zx_is_Inquiry_s* x, int n, struct zx_is_Select_s* z)
{
  struct zx_is_Select_s* y;
  if (!x || !z) return;
  switch (n) {
  case 0:
  add_to_start:
    z->gg.g.n = &x->Select->gg.g;
    x->Select = z;
    return;
  case -1:
    y = x->Select;
    if (!y) goto add_to_start;
    for (; y->gg.g.n; y = (struct zx_is_Select_s*)y->gg.g.n) ;
    break;
  default:
    for (y = x->Select; n > 1 && y; --n, y = (struct zx_is_Select_s*)y->gg.g.n) ;
    if (!y) return;
  }
  z->gg.g.n = y->gg.g.n;
  y->gg.g.n = &z->gg.g;
}

/* FUNC(zx_is_Inquiry_DEL_Select) */

void zx_is_Inquiry_DEL_Select(struct zx_is_Inquiry_s* x, int n)
{
  struct zx_is_Select_s* y;
  if (!x) return;
  switch (n) {
  case 0:
    x->Select = (struct zx_is_Select_s*)x->Select->gg.g.n;
    return;
  case -1:
    y = (struct zx_is_Select_s*)x->Select;
    if (!y) return;
    for (; y->gg.g.n; y = (struct zx_is_Select_s*)y->gg.g.n) ;
    break;
  default:
    for (y = x->Select; n > 1 && y->gg.g.n; --n, y = (struct zx_is_Select_s*)y->gg.g.n) ;
    if (!y->gg.g.n) return;
  }
  y->gg.g.n = y->gg.g.n->n;
}

#endif



#ifdef ZX_ENA_GETPUT

/* FUNC(zx_is_Inquiry_NUM_Confirm) */

int zx_is_Inquiry_NUM_Confirm(struct zx_is_Inquiry_s* x)
{
  struct zx_is_Confirm_s* y;
  int n = 0;
  if (!x) return 0;
  for (y = x->Confirm; y; ++n, y = (struct zx_is_Confirm_s*)y->gg.g.n) ;
  return n;
}

/* FUNC(zx_is_Inquiry_GET_Confirm) */

struct zx_is_Confirm_s* zx_is_Inquiry_GET_Confirm(struct zx_is_Inquiry_s* x, int n)
{
  struct zx_is_Confirm_s* y;
  if (!x) return 0;
  for (y = x->Confirm; n>=0 && y; --n, y = (struct zx_is_Confirm_s*)y->gg.g.n) ;
  return y;
}

/* FUNC(zx_is_Inquiry_POP_Confirm) */

struct zx_is_Confirm_s* zx_is_Inquiry_POP_Confirm(struct zx_is_Inquiry_s* x)
{
  struct zx_is_Confirm_s* y;
  if (!x) return 0;
  y = x->Confirm;
  if (y)
    x->Confirm = (struct zx_is_Confirm_s*)y->gg.g.n;
  return y;
}

/* FUNC(zx_is_Inquiry_PUSH_Confirm) */

void zx_is_Inquiry_PUSH_Confirm(struct zx_is_Inquiry_s* x, struct zx_is_Confirm_s* z)
{
  if (!x || !z) return;
  z->gg.g.n = &x->Confirm->gg.g;
  x->Confirm = z;
}

/* FUNC(zx_is_Inquiry_REV_Confirm) */

void zx_is_Inquiry_REV_Confirm(struct zx_is_Inquiry_s* x)
{
  struct zx_is_Confirm_s* nxt;
  struct zx_is_Confirm_s* y;
  if (!x) return;
  y = x->Confirm;
  if (!y) return;
  x->Confirm = 0;
  while (y) {
    nxt = (struct zx_is_Confirm_s*)y->gg.g.n;
    y->gg.g.n = &x->Confirm->gg.g;
    x->Confirm = y;
    y = nxt;
  }
}

/* FUNC(zx_is_Inquiry_PUT_Confirm) */

void zx_is_Inquiry_PUT_Confirm(struct zx_is_Inquiry_s* x, int n, struct zx_is_Confirm_s* z)
{
  struct zx_is_Confirm_s* y;
  if (!x || !z) return;
  y = x->Confirm;
  if (!y) return;
  switch (n) {
  case 0:
    z->gg.g.n = y->gg.g.n;
    x->Confirm = z;
    return;
  default:
    for (; n > 1 && y->gg.g.n; --n, y = (struct zx_is_Confirm_s*)y->gg.g.n) ;
    if (!y->gg.g.n) return;
    z->gg.g.n = y->gg.g.n->n;
    y->gg.g.n = &z->gg.g;
  }
}

/* FUNC(zx_is_Inquiry_ADD_Confirm) */

void zx_is_Inquiry_ADD_Confirm(struct zx_is_Inquiry_s* x, int n, struct zx_is_Confirm_s* z)
{
  struct zx_is_Confirm_s* y;
  if (!x || !z) return;
  switch (n) {
  case 0:
  add_to_start:
    z->gg.g.n = &x->Confirm->gg.g;
    x->Confirm = z;
    return;
  case -1:
    y = x->Confirm;
    if (!y) goto add_to_start;
    for (; y->gg.g.n; y = (struct zx_is_Confirm_s*)y->gg.g.n) ;
    break;
  default:
    for (y = x->Confirm; n > 1 && y; --n, y = (struct zx_is_Confirm_s*)y->gg.g.n) ;
    if (!y) return;
  }
  z->gg.g.n = y->gg.g.n;
  y->gg.g.n = &z->gg.g;
}

/* FUNC(zx_is_Inquiry_DEL_Confirm) */

void zx_is_Inquiry_DEL_Confirm(struct zx_is_Inquiry_s* x, int n)
{
  struct zx_is_Confirm_s* y;
  if (!x) return;
  switch (n) {
  case 0:
    x->Confirm = (struct zx_is_Confirm_s*)x->Confirm->gg.g.n;
    return;
  case -1:
    y = (struct zx_is_Confirm_s*)x->Confirm;
    if (!y) return;
    for (; y->gg.g.n; y = (struct zx_is_Confirm_s*)y->gg.g.n) ;
    break;
  default:
    for (y = x->Confirm; n > 1 && y->gg.g.n; --n, y = (struct zx_is_Confirm_s*)y->gg.g.n) ;
    if (!y->gg.g.n) return;
  }
  y->gg.g.n = y->gg.g.n->n;
}

#endif



#ifdef ZX_ENA_GETPUT

/* FUNC(zx_is_Inquiry_NUM_Text) */

int zx_is_Inquiry_NUM_Text(struct zx_is_Inquiry_s* x)
{
  struct zx_is_Text_s* y;
  int n = 0;
  if (!x) return 0;
  for (y = x->Text; y; ++n, y = (struct zx_is_Text_s*)y->gg.g.n) ;
  return n;
}

/* FUNC(zx_is_Inquiry_GET_Text) */

struct zx_is_Text_s* zx_is_Inquiry_GET_Text(struct zx_is_Inquiry_s* x, int n)
{
  struct zx_is_Text_s* y;
  if (!x) return 0;
  for (y = x->Text; n>=0 && y; --n, y = (struct zx_is_Text_s*)y->gg.g.n) ;
  return y;
}

/* FUNC(zx_is_Inquiry_POP_Text) */

struct zx_is_Text_s* zx_is_Inquiry_POP_Text(struct zx_is_Inquiry_s* x)
{
  struct zx_is_Text_s* y;
  if (!x) return 0;
  y = x->Text;
  if (y)
    x->Text = (struct zx_is_Text_s*)y->gg.g.n;
  return y;
}

/* FUNC(zx_is_Inquiry_PUSH_Text) */

void zx_is_Inquiry_PUSH_Text(struct zx_is_Inquiry_s* x, struct zx_is_Text_s* z)
{
  if (!x || !z) return;
  z->gg.g.n = &x->Text->gg.g;
  x->Text = z;
}

/* FUNC(zx_is_Inquiry_REV_Text) */

void zx_is_Inquiry_REV_Text(struct zx_is_Inquiry_s* x)
{
  struct zx_is_Text_s* nxt;
  struct zx_is_Text_s* y;
  if (!x) return;
  y = x->Text;
  if (!y) return;
  x->Text = 0;
  while (y) {
    nxt = (struct zx_is_Text_s*)y->gg.g.n;
    y->gg.g.n = &x->Text->gg.g;
    x->Text = y;
    y = nxt;
  }
}

/* FUNC(zx_is_Inquiry_PUT_Text) */

void zx_is_Inquiry_PUT_Text(struct zx_is_Inquiry_s* x, int n, struct zx_is_Text_s* z)
{
  struct zx_is_Text_s* y;
  if (!x || !z) return;
  y = x->Text;
  if (!y) return;
  switch (n) {
  case 0:
    z->gg.g.n = y->gg.g.n;
    x->Text = z;
    return;
  default:
    for (; n > 1 && y->gg.g.n; --n, y = (struct zx_is_Text_s*)y->gg.g.n) ;
    if (!y->gg.g.n) return;
    z->gg.g.n = y->gg.g.n->n;
    y->gg.g.n = &z->gg.g;
  }
}

/* FUNC(zx_is_Inquiry_ADD_Text) */

void zx_is_Inquiry_ADD_Text(struct zx_is_Inquiry_s* x, int n, struct zx_is_Text_s* z)
{
  struct zx_is_Text_s* y;
  if (!x || !z) return;
  switch (n) {
  case 0:
  add_to_start:
    z->gg.g.n = &x->Text->gg.g;
    x->Text = z;
    return;
  case -1:
    y = x->Text;
    if (!y) goto add_to_start;
    for (; y->gg.g.n; y = (struct zx_is_Text_s*)y->gg.g.n) ;
    break;
  default:
    for (y = x->Text; n > 1 && y; --n, y = (struct zx_is_Text_s*)y->gg.g.n) ;
    if (!y) return;
  }
  z->gg.g.n = y->gg.g.n;
  y->gg.g.n = &z->gg.g;
}

/* FUNC(zx_is_Inquiry_DEL_Text) */

void zx_is_Inquiry_DEL_Text(struct zx_is_Inquiry_s* x, int n)
{
  struct zx_is_Text_s* y;
  if (!x) return;
  switch (n) {
  case 0:
    x->Text = (struct zx_is_Text_s*)x->Text->gg.g.n;
    return;
  case -1:
    y = (struct zx_is_Text_s*)x->Text;
    if (!y) return;
    for (; y->gg.g.n; y = (struct zx_is_Text_s*)y->gg.g.n) ;
    break;
  default:
    for (y = x->Text; n > 1 && y->gg.g.n; --n, y = (struct zx_is_Text_s*)y->gg.g.n) ;
    if (!y->gg.g.n) return;
  }
  y->gg.g.n = y->gg.g.n->n;
}

#endif

/* FUNC(zx_is_Inquiry_GET_id) */
struct zx_str* zx_is_Inquiry_GET_id(struct zx_is_Inquiry_s* x) { return x->id; }
/* FUNC(zx_is_Inquiry_PUT_id) */
void zx_is_Inquiry_PUT_id(struct zx_is_Inquiry_s* x, struct zx_str* y) { x->id = y; }
/* FUNC(zx_is_Inquiry_GET_title) */
struct zx_str* zx_is_Inquiry_GET_title(struct zx_is_Inquiry_s* x) { return x->title; }
/* FUNC(zx_is_Inquiry_PUT_title) */
void zx_is_Inquiry_PUT_title(struct zx_is_Inquiry_s* x, struct zx_str* y) { x->title = y; }







#ifdef ZX_ENA_GETPUT

/* FUNC(zx_is_InteractionRequest_NUM_Inquiry) */

int zx_is_InteractionRequest_NUM_Inquiry(struct zx_is_InteractionRequest_s* x)
{
  struct zx_is_Inquiry_s* y;
  int n = 0;
  if (!x) return 0;
  for (y = x->Inquiry; y; ++n, y = (struct zx_is_Inquiry_s*)y->gg.g.n) ;
  return n;
}

/* FUNC(zx_is_InteractionRequest_GET_Inquiry) */

struct zx_is_Inquiry_s* zx_is_InteractionRequest_GET_Inquiry(struct zx_is_InteractionRequest_s* x, int n)
{
  struct zx_is_Inquiry_s* y;
  if (!x) return 0;
  for (y = x->Inquiry; n>=0 && y; --n, y = (struct zx_is_Inquiry_s*)y->gg.g.n) ;
  return y;
}

/* FUNC(zx_is_InteractionRequest_POP_Inquiry) */

struct zx_is_Inquiry_s* zx_is_InteractionRequest_POP_Inquiry(struct zx_is_InteractionRequest_s* x)
{
  struct zx_is_Inquiry_s* y;
  if (!x) return 0;
  y = x->Inquiry;
  if (y)
    x->Inquiry = (struct zx_is_Inquiry_s*)y->gg.g.n;
  return y;
}

/* FUNC(zx_is_InteractionRequest_PUSH_Inquiry) */

void zx_is_InteractionRequest_PUSH_Inquiry(struct zx_is_InteractionRequest_s* x, struct zx_is_Inquiry_s* z)
{
  if (!x || !z) return;
  z->gg.g.n = &x->Inquiry->gg.g;
  x->Inquiry = z;
}

/* FUNC(zx_is_InteractionRequest_REV_Inquiry) */

void zx_is_InteractionRequest_REV_Inquiry(struct zx_is_InteractionRequest_s* x)
{
  struct zx_is_Inquiry_s* nxt;
  struct zx_is_Inquiry_s* y;
  if (!x) return;
  y = x->Inquiry;
  if (!y) return;
  x->Inquiry = 0;
  while (y) {
    nxt = (struct zx_is_Inquiry_s*)y->gg.g.n;
    y->gg.g.n = &x->Inquiry->gg.g;
    x->Inquiry = y;
    y = nxt;
  }
}

/* FUNC(zx_is_InteractionRequest_PUT_Inquiry) */

void zx_is_InteractionRequest_PUT_Inquiry(struct zx_is_InteractionRequest_s* x, int n, struct zx_is_Inquiry_s* z)
{
  struct zx_is_Inquiry_s* y;
  if (!x || !z) return;
  y = x->Inquiry;
  if (!y) return;
  switch (n) {
  case 0:
    z->gg.g.n = y->gg.g.n;
    x->Inquiry = z;
    return;
  default:
    for (; n > 1 && y->gg.g.n; --n, y = (struct zx_is_Inquiry_s*)y->gg.g.n) ;
    if (!y->gg.g.n) return;
    z->gg.g.n = y->gg.g.n->n;
    y->gg.g.n = &z->gg.g;
  }
}

/* FUNC(zx_is_InteractionRequest_ADD_Inquiry) */

void zx_is_InteractionRequest_ADD_Inquiry(struct zx_is_InteractionRequest_s* x, int n, struct zx_is_Inquiry_s* z)
{
  struct zx_is_Inquiry_s* y;
  if (!x || !z) return;
  switch (n) {
  case 0:
  add_to_start:
    z->gg.g.n = &x->Inquiry->gg.g;
    x->Inquiry = z;
    return;
  case -1:
    y = x->Inquiry;
    if (!y) goto add_to_start;
    for (; y->gg.g.n; y = (struct zx_is_Inquiry_s*)y->gg.g.n) ;
    break;
  default:
    for (y = x->Inquiry; n > 1 && y; --n, y = (struct zx_is_Inquiry_s*)y->gg.g.n) ;
    if (!y) return;
  }
  z->gg.g.n = y->gg.g.n;
  y->gg.g.n = &z->gg.g;
}

/* FUNC(zx_is_InteractionRequest_DEL_Inquiry) */

void zx_is_InteractionRequest_DEL_Inquiry(struct zx_is_InteractionRequest_s* x, int n)
{
  struct zx_is_Inquiry_s* y;
  if (!x) return;
  switch (n) {
  case 0:
    x->Inquiry = (struct zx_is_Inquiry_s*)x->Inquiry->gg.g.n;
    return;
  case -1:
    y = (struct zx_is_Inquiry_s*)x->Inquiry;
    if (!y) return;
    for (; y->gg.g.n; y = (struct zx_is_Inquiry_s*)y->gg.g.n) ;
    break;
  default:
    for (y = x->Inquiry; n > 1 && y->gg.g.n; --n, y = (struct zx_is_Inquiry_s*)y->gg.g.n) ;
    if (!y->gg.g.n) return;
  }
  y->gg.g.n = y->gg.g.n->n;
}

#endif



#ifdef ZX_ENA_GETPUT

/* FUNC(zx_is_InteractionRequest_NUM_KeyInfo) */

int zx_is_InteractionRequest_NUM_KeyInfo(struct zx_is_InteractionRequest_s* x)
{
  struct zx_ds_KeyInfo_s* y;
  int n = 0;
  if (!x) return 0;
  for (y = x->KeyInfo; y; ++n, y = (struct zx_ds_KeyInfo_s*)y->gg.g.n) ;
  return n;
}

/* FUNC(zx_is_InteractionRequest_GET_KeyInfo) */

struct zx_ds_KeyInfo_s* zx_is_InteractionRequest_GET_KeyInfo(struct zx_is_InteractionRequest_s* x, int n)
{
  struct zx_ds_KeyInfo_s* y;
  if (!x) return 0;
  for (y = x->KeyInfo; n>=0 && y; --n, y = (struct zx_ds_KeyInfo_s*)y->gg.g.n) ;
  return y;
}

/* FUNC(zx_is_InteractionRequest_POP_KeyInfo) */

struct zx_ds_KeyInfo_s* zx_is_InteractionRequest_POP_KeyInfo(struct zx_is_InteractionRequest_s* x)
{
  struct zx_ds_KeyInfo_s* y;
  if (!x) return 0;
  y = x->KeyInfo;
  if (y)
    x->KeyInfo = (struct zx_ds_KeyInfo_s*)y->gg.g.n;
  return y;
}

/* FUNC(zx_is_InteractionRequest_PUSH_KeyInfo) */

void zx_is_InteractionRequest_PUSH_KeyInfo(struct zx_is_InteractionRequest_s* x, struct zx_ds_KeyInfo_s* z)
{
  if (!x || !z) return;
  z->gg.g.n = &x->KeyInfo->gg.g;
  x->KeyInfo = z;
}

/* FUNC(zx_is_InteractionRequest_REV_KeyInfo) */

void zx_is_InteractionRequest_REV_KeyInfo(struct zx_is_InteractionRequest_s* x)
{
  struct zx_ds_KeyInfo_s* nxt;
  struct zx_ds_KeyInfo_s* y;
  if (!x) return;
  y = x->KeyInfo;
  if (!y) return;
  x->KeyInfo = 0;
  while (y) {
    nxt = (struct zx_ds_KeyInfo_s*)y->gg.g.n;
    y->gg.g.n = &x->KeyInfo->gg.g;
    x->KeyInfo = y;
    y = nxt;
  }
}

/* FUNC(zx_is_InteractionRequest_PUT_KeyInfo) */

void zx_is_InteractionRequest_PUT_KeyInfo(struct zx_is_InteractionRequest_s* x, int n, struct zx_ds_KeyInfo_s* z)
{
  struct zx_ds_KeyInfo_s* y;
  if (!x || !z) return;
  y = x->KeyInfo;
  if (!y) return;
  switch (n) {
  case 0:
    z->gg.g.n = y->gg.g.n;
    x->KeyInfo = z;
    return;
  default:
    for (; n > 1 && y->gg.g.n; --n, y = (struct zx_ds_KeyInfo_s*)y->gg.g.n) ;
    if (!y->gg.g.n) return;
    z->gg.g.n = y->gg.g.n->n;
    y->gg.g.n = &z->gg.g;
  }
}

/* FUNC(zx_is_InteractionRequest_ADD_KeyInfo) */

void zx_is_InteractionRequest_ADD_KeyInfo(struct zx_is_InteractionRequest_s* x, int n, struct zx_ds_KeyInfo_s* z)
{
  struct zx_ds_KeyInfo_s* y;
  if (!x || !z) return;
  switch (n) {
  case 0:
  add_to_start:
    z->gg.g.n = &x->KeyInfo->gg.g;
    x->KeyInfo = z;
    return;
  case -1:
    y = x->KeyInfo;
    if (!y) goto add_to_start;
    for (; y->gg.g.n; y = (struct zx_ds_KeyInfo_s*)y->gg.g.n) ;
    break;
  default:
    for (y = x->KeyInfo; n > 1 && y; --n, y = (struct zx_ds_KeyInfo_s*)y->gg.g.n) ;
    if (!y) return;
  }
  z->gg.g.n = y->gg.g.n;
  y->gg.g.n = &z->gg.g;
}

/* FUNC(zx_is_InteractionRequest_DEL_KeyInfo) */

void zx_is_InteractionRequest_DEL_KeyInfo(struct zx_is_InteractionRequest_s* x, int n)
{
  struct zx_ds_KeyInfo_s* y;
  if (!x) return;
  switch (n) {
  case 0:
    x->KeyInfo = (struct zx_ds_KeyInfo_s*)x->KeyInfo->gg.g.n;
    return;
  case -1:
    y = (struct zx_ds_KeyInfo_s*)x->KeyInfo;
    if (!y) return;
    for (; y->gg.g.n; y = (struct zx_ds_KeyInfo_s*)y->gg.g.n) ;
    break;
  default:
    for (y = x->KeyInfo; n > 1 && y->gg.g.n; --n, y = (struct zx_ds_KeyInfo_s*)y->gg.g.n) ;
    if (!y->gg.g.n) return;
  }
  y->gg.g.n = y->gg.g.n->n;
}

#endif

/* FUNC(zx_is_InteractionRequest_GET_id) */
struct zx_str* zx_is_InteractionRequest_GET_id(struct zx_is_InteractionRequest_s* x) { return x->id; }
/* FUNC(zx_is_InteractionRequest_PUT_id) */
void zx_is_InteractionRequest_PUT_id(struct zx_is_InteractionRequest_s* x, struct zx_str* y) { x->id = y; }
/* FUNC(zx_is_InteractionRequest_GET_language) */
struct zx_str* zx_is_InteractionRequest_GET_language(struct zx_is_InteractionRequest_s* x) { return x->language; }
/* FUNC(zx_is_InteractionRequest_PUT_language) */
void zx_is_InteractionRequest_PUT_language(struct zx_is_InteractionRequest_s* x, struct zx_str* y) { x->language = y; }
/* FUNC(zx_is_InteractionRequest_GET_maxInteractTime) */
struct zx_str* zx_is_InteractionRequest_GET_maxInteractTime(struct zx_is_InteractionRequest_s* x) { return x->maxInteractTime; }
/* FUNC(zx_is_InteractionRequest_PUT_maxInteractTime) */
void zx_is_InteractionRequest_PUT_maxInteractTime(struct zx_is_InteractionRequest_s* x, struct zx_str* y) { x->maxInteractTime = y; }
/* FUNC(zx_is_InteractionRequest_GET_signed_is_c_keyword) */
struct zx_str* zx_is_InteractionRequest_GET_signed_is_c_keyword(struct zx_is_InteractionRequest_s* x) { return x->signed_is_c_keyword; }
/* FUNC(zx_is_InteractionRequest_PUT_signed_is_c_keyword) */
void zx_is_InteractionRequest_PUT_signed_is_c_keyword(struct zx_is_InteractionRequest_s* x, struct zx_str* y) { x->signed_is_c_keyword = y; }







#ifdef ZX_ENA_GETPUT

/* FUNC(zx_is_InteractionResponse_NUM_Status) */

int zx_is_InteractionResponse_NUM_Status(struct zx_is_InteractionResponse_s* x)
{
  struct zx_lu_Status_s* y;
  int n = 0;
  if (!x) return 0;
  for (y = x->Status; y; ++n, y = (struct zx_lu_Status_s*)y->gg.g.n) ;
  return n;
}

/* FUNC(zx_is_InteractionResponse_GET_Status) */

struct zx_lu_Status_s* zx_is_InteractionResponse_GET_Status(struct zx_is_InteractionResponse_s* x, int n)
{
  struct zx_lu_Status_s* y;
  if (!x) return 0;
  for (y = x->Status; n>=0 && y; --n, y = (struct zx_lu_Status_s*)y->gg.g.n) ;
  return y;
}

/* FUNC(zx_is_InteractionResponse_POP_Status) */

struct zx_lu_Status_s* zx_is_InteractionResponse_POP_Status(struct zx_is_InteractionResponse_s* x)
{
  struct zx_lu_Status_s* y;
  if (!x) return 0;
  y = x->Status;
  if (y)
    x->Status = (struct zx_lu_Status_s*)y->gg.g.n;
  return y;
}

/* FUNC(zx_is_InteractionResponse_PUSH_Status) */

void zx_is_InteractionResponse_PUSH_Status(struct zx_is_InteractionResponse_s* x, struct zx_lu_Status_s* z)
{
  if (!x || !z) return;
  z->gg.g.n = &x->Status->gg.g;
  x->Status = z;
}

/* FUNC(zx_is_InteractionResponse_REV_Status) */

void zx_is_InteractionResponse_REV_Status(struct zx_is_InteractionResponse_s* x)
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

/* FUNC(zx_is_InteractionResponse_PUT_Status) */

void zx_is_InteractionResponse_PUT_Status(struct zx_is_InteractionResponse_s* x, int n, struct zx_lu_Status_s* z)
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

/* FUNC(zx_is_InteractionResponse_ADD_Status) */

void zx_is_InteractionResponse_ADD_Status(struct zx_is_InteractionResponse_s* x, int n, struct zx_lu_Status_s* z)
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

/* FUNC(zx_is_InteractionResponse_DEL_Status) */

void zx_is_InteractionResponse_DEL_Status(struct zx_is_InteractionResponse_s* x, int n)
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

/* FUNC(zx_is_InteractionResponse_NUM_InteractionStatement) */

int zx_is_InteractionResponse_NUM_InteractionStatement(struct zx_is_InteractionResponse_s* x)
{
  struct zx_is_InteractionStatement_s* y;
  int n = 0;
  if (!x) return 0;
  for (y = x->InteractionStatement; y; ++n, y = (struct zx_is_InteractionStatement_s*)y->gg.g.n) ;
  return n;
}

/* FUNC(zx_is_InteractionResponse_GET_InteractionStatement) */

struct zx_is_InteractionStatement_s* zx_is_InteractionResponse_GET_InteractionStatement(struct zx_is_InteractionResponse_s* x, int n)
{
  struct zx_is_InteractionStatement_s* y;
  if (!x) return 0;
  for (y = x->InteractionStatement; n>=0 && y; --n, y = (struct zx_is_InteractionStatement_s*)y->gg.g.n) ;
  return y;
}

/* FUNC(zx_is_InteractionResponse_POP_InteractionStatement) */

struct zx_is_InteractionStatement_s* zx_is_InteractionResponse_POP_InteractionStatement(struct zx_is_InteractionResponse_s* x)
{
  struct zx_is_InteractionStatement_s* y;
  if (!x) return 0;
  y = x->InteractionStatement;
  if (y)
    x->InteractionStatement = (struct zx_is_InteractionStatement_s*)y->gg.g.n;
  return y;
}

/* FUNC(zx_is_InteractionResponse_PUSH_InteractionStatement) */

void zx_is_InteractionResponse_PUSH_InteractionStatement(struct zx_is_InteractionResponse_s* x, struct zx_is_InteractionStatement_s* z)
{
  if (!x || !z) return;
  z->gg.g.n = &x->InteractionStatement->gg.g;
  x->InteractionStatement = z;
}

/* FUNC(zx_is_InteractionResponse_REV_InteractionStatement) */

void zx_is_InteractionResponse_REV_InteractionStatement(struct zx_is_InteractionResponse_s* x)
{
  struct zx_is_InteractionStatement_s* nxt;
  struct zx_is_InteractionStatement_s* y;
  if (!x) return;
  y = x->InteractionStatement;
  if (!y) return;
  x->InteractionStatement = 0;
  while (y) {
    nxt = (struct zx_is_InteractionStatement_s*)y->gg.g.n;
    y->gg.g.n = &x->InteractionStatement->gg.g;
    x->InteractionStatement = y;
    y = nxt;
  }
}

/* FUNC(zx_is_InteractionResponse_PUT_InteractionStatement) */

void zx_is_InteractionResponse_PUT_InteractionStatement(struct zx_is_InteractionResponse_s* x, int n, struct zx_is_InteractionStatement_s* z)
{
  struct zx_is_InteractionStatement_s* y;
  if (!x || !z) return;
  y = x->InteractionStatement;
  if (!y) return;
  switch (n) {
  case 0:
    z->gg.g.n = y->gg.g.n;
    x->InteractionStatement = z;
    return;
  default:
    for (; n > 1 && y->gg.g.n; --n, y = (struct zx_is_InteractionStatement_s*)y->gg.g.n) ;
    if (!y->gg.g.n) return;
    z->gg.g.n = y->gg.g.n->n;
    y->gg.g.n = &z->gg.g;
  }
}

/* FUNC(zx_is_InteractionResponse_ADD_InteractionStatement) */

void zx_is_InteractionResponse_ADD_InteractionStatement(struct zx_is_InteractionResponse_s* x, int n, struct zx_is_InteractionStatement_s* z)
{
  struct zx_is_InteractionStatement_s* y;
  if (!x || !z) return;
  switch (n) {
  case 0:
  add_to_start:
    z->gg.g.n = &x->InteractionStatement->gg.g;
    x->InteractionStatement = z;
    return;
  case -1:
    y = x->InteractionStatement;
    if (!y) goto add_to_start;
    for (; y->gg.g.n; y = (struct zx_is_InteractionStatement_s*)y->gg.g.n) ;
    break;
  default:
    for (y = x->InteractionStatement; n > 1 && y; --n, y = (struct zx_is_InteractionStatement_s*)y->gg.g.n) ;
    if (!y) return;
  }
  z->gg.g.n = y->gg.g.n;
  y->gg.g.n = &z->gg.g;
}

/* FUNC(zx_is_InteractionResponse_DEL_InteractionStatement) */

void zx_is_InteractionResponse_DEL_InteractionStatement(struct zx_is_InteractionResponse_s* x, int n)
{
  struct zx_is_InteractionStatement_s* y;
  if (!x) return;
  switch (n) {
  case 0:
    x->InteractionStatement = (struct zx_is_InteractionStatement_s*)x->InteractionStatement->gg.g.n;
    return;
  case -1:
    y = (struct zx_is_InteractionStatement_s*)x->InteractionStatement;
    if (!y) return;
    for (; y->gg.g.n; y = (struct zx_is_InteractionStatement_s*)y->gg.g.n) ;
    break;
  default:
    for (y = x->InteractionStatement; n > 1 && y->gg.g.n; --n, y = (struct zx_is_InteractionStatement_s*)y->gg.g.n) ;
    if (!y->gg.g.n) return;
  }
  y->gg.g.n = y->gg.g.n->n;
}

#endif



#ifdef ZX_ENA_GETPUT

/* FUNC(zx_is_InteractionResponse_NUM_Parameter) */

int zx_is_InteractionResponse_NUM_Parameter(struct zx_is_InteractionResponse_s* x)
{
  struct zx_is_Parameter_s* y;
  int n = 0;
  if (!x) return 0;
  for (y = x->Parameter; y; ++n, y = (struct zx_is_Parameter_s*)y->gg.g.n) ;
  return n;
}

/* FUNC(zx_is_InteractionResponse_GET_Parameter) */

struct zx_is_Parameter_s* zx_is_InteractionResponse_GET_Parameter(struct zx_is_InteractionResponse_s* x, int n)
{
  struct zx_is_Parameter_s* y;
  if (!x) return 0;
  for (y = x->Parameter; n>=0 && y; --n, y = (struct zx_is_Parameter_s*)y->gg.g.n) ;
  return y;
}

/* FUNC(zx_is_InteractionResponse_POP_Parameter) */

struct zx_is_Parameter_s* zx_is_InteractionResponse_POP_Parameter(struct zx_is_InteractionResponse_s* x)
{
  struct zx_is_Parameter_s* y;
  if (!x) return 0;
  y = x->Parameter;
  if (y)
    x->Parameter = (struct zx_is_Parameter_s*)y->gg.g.n;
  return y;
}

/* FUNC(zx_is_InteractionResponse_PUSH_Parameter) */

void zx_is_InteractionResponse_PUSH_Parameter(struct zx_is_InteractionResponse_s* x, struct zx_is_Parameter_s* z)
{
  if (!x || !z) return;
  z->gg.g.n = &x->Parameter->gg.g;
  x->Parameter = z;
}

/* FUNC(zx_is_InteractionResponse_REV_Parameter) */

void zx_is_InteractionResponse_REV_Parameter(struct zx_is_InteractionResponse_s* x)
{
  struct zx_is_Parameter_s* nxt;
  struct zx_is_Parameter_s* y;
  if (!x) return;
  y = x->Parameter;
  if (!y) return;
  x->Parameter = 0;
  while (y) {
    nxt = (struct zx_is_Parameter_s*)y->gg.g.n;
    y->gg.g.n = &x->Parameter->gg.g;
    x->Parameter = y;
    y = nxt;
  }
}

/* FUNC(zx_is_InteractionResponse_PUT_Parameter) */

void zx_is_InteractionResponse_PUT_Parameter(struct zx_is_InteractionResponse_s* x, int n, struct zx_is_Parameter_s* z)
{
  struct zx_is_Parameter_s* y;
  if (!x || !z) return;
  y = x->Parameter;
  if (!y) return;
  switch (n) {
  case 0:
    z->gg.g.n = y->gg.g.n;
    x->Parameter = z;
    return;
  default:
    for (; n > 1 && y->gg.g.n; --n, y = (struct zx_is_Parameter_s*)y->gg.g.n) ;
    if (!y->gg.g.n) return;
    z->gg.g.n = y->gg.g.n->n;
    y->gg.g.n = &z->gg.g;
  }
}

/* FUNC(zx_is_InteractionResponse_ADD_Parameter) */

void zx_is_InteractionResponse_ADD_Parameter(struct zx_is_InteractionResponse_s* x, int n, struct zx_is_Parameter_s* z)
{
  struct zx_is_Parameter_s* y;
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
    for (; y->gg.g.n; y = (struct zx_is_Parameter_s*)y->gg.g.n) ;
    break;
  default:
    for (y = x->Parameter; n > 1 && y; --n, y = (struct zx_is_Parameter_s*)y->gg.g.n) ;
    if (!y) return;
  }
  z->gg.g.n = y->gg.g.n;
  y->gg.g.n = &z->gg.g;
}

/* FUNC(zx_is_InteractionResponse_DEL_Parameter) */

void zx_is_InteractionResponse_DEL_Parameter(struct zx_is_InteractionResponse_s* x, int n)
{
  struct zx_is_Parameter_s* y;
  if (!x) return;
  switch (n) {
  case 0:
    x->Parameter = (struct zx_is_Parameter_s*)x->Parameter->gg.g.n;
    return;
  case -1:
    y = (struct zx_is_Parameter_s*)x->Parameter;
    if (!y) return;
    for (; y->gg.g.n; y = (struct zx_is_Parameter_s*)y->gg.g.n) ;
    break;
  default:
    for (y = x->Parameter; n > 1 && y->gg.g.n; --n, y = (struct zx_is_Parameter_s*)y->gg.g.n) ;
    if (!y->gg.g.n) return;
  }
  y->gg.g.n = y->gg.g.n->n;
}

#endif








#ifdef ZX_ENA_GETPUT

/* FUNC(zx_is_InteractionStatement_NUM_Inquiry) */

int zx_is_InteractionStatement_NUM_Inquiry(struct zx_is_InteractionStatement_s* x)
{
  struct zx_is_Inquiry_s* y;
  int n = 0;
  if (!x) return 0;
  for (y = x->Inquiry; y; ++n, y = (struct zx_is_Inquiry_s*)y->gg.g.n) ;
  return n;
}

/* FUNC(zx_is_InteractionStatement_GET_Inquiry) */

struct zx_is_Inquiry_s* zx_is_InteractionStatement_GET_Inquiry(struct zx_is_InteractionStatement_s* x, int n)
{
  struct zx_is_Inquiry_s* y;
  if (!x) return 0;
  for (y = x->Inquiry; n>=0 && y; --n, y = (struct zx_is_Inquiry_s*)y->gg.g.n) ;
  return y;
}

/* FUNC(zx_is_InteractionStatement_POP_Inquiry) */

struct zx_is_Inquiry_s* zx_is_InteractionStatement_POP_Inquiry(struct zx_is_InteractionStatement_s* x)
{
  struct zx_is_Inquiry_s* y;
  if (!x) return 0;
  y = x->Inquiry;
  if (y)
    x->Inquiry = (struct zx_is_Inquiry_s*)y->gg.g.n;
  return y;
}

/* FUNC(zx_is_InteractionStatement_PUSH_Inquiry) */

void zx_is_InteractionStatement_PUSH_Inquiry(struct zx_is_InteractionStatement_s* x, struct zx_is_Inquiry_s* z)
{
  if (!x || !z) return;
  z->gg.g.n = &x->Inquiry->gg.g;
  x->Inquiry = z;
}

/* FUNC(zx_is_InteractionStatement_REV_Inquiry) */

void zx_is_InteractionStatement_REV_Inquiry(struct zx_is_InteractionStatement_s* x)
{
  struct zx_is_Inquiry_s* nxt;
  struct zx_is_Inquiry_s* y;
  if (!x) return;
  y = x->Inquiry;
  if (!y) return;
  x->Inquiry = 0;
  while (y) {
    nxt = (struct zx_is_Inquiry_s*)y->gg.g.n;
    y->gg.g.n = &x->Inquiry->gg.g;
    x->Inquiry = y;
    y = nxt;
  }
}

/* FUNC(zx_is_InteractionStatement_PUT_Inquiry) */

void zx_is_InteractionStatement_PUT_Inquiry(struct zx_is_InteractionStatement_s* x, int n, struct zx_is_Inquiry_s* z)
{
  struct zx_is_Inquiry_s* y;
  if (!x || !z) return;
  y = x->Inquiry;
  if (!y) return;
  switch (n) {
  case 0:
    z->gg.g.n = y->gg.g.n;
    x->Inquiry = z;
    return;
  default:
    for (; n > 1 && y->gg.g.n; --n, y = (struct zx_is_Inquiry_s*)y->gg.g.n) ;
    if (!y->gg.g.n) return;
    z->gg.g.n = y->gg.g.n->n;
    y->gg.g.n = &z->gg.g;
  }
}

/* FUNC(zx_is_InteractionStatement_ADD_Inquiry) */

void zx_is_InteractionStatement_ADD_Inquiry(struct zx_is_InteractionStatement_s* x, int n, struct zx_is_Inquiry_s* z)
{
  struct zx_is_Inquiry_s* y;
  if (!x || !z) return;
  switch (n) {
  case 0:
  add_to_start:
    z->gg.g.n = &x->Inquiry->gg.g;
    x->Inquiry = z;
    return;
  case -1:
    y = x->Inquiry;
    if (!y) goto add_to_start;
    for (; y->gg.g.n; y = (struct zx_is_Inquiry_s*)y->gg.g.n) ;
    break;
  default:
    for (y = x->Inquiry; n > 1 && y; --n, y = (struct zx_is_Inquiry_s*)y->gg.g.n) ;
    if (!y) return;
  }
  z->gg.g.n = y->gg.g.n;
  y->gg.g.n = &z->gg.g;
}

/* FUNC(zx_is_InteractionStatement_DEL_Inquiry) */

void zx_is_InteractionStatement_DEL_Inquiry(struct zx_is_InteractionStatement_s* x, int n)
{
  struct zx_is_Inquiry_s* y;
  if (!x) return;
  switch (n) {
  case 0:
    x->Inquiry = (struct zx_is_Inquiry_s*)x->Inquiry->gg.g.n;
    return;
  case -1:
    y = (struct zx_is_Inquiry_s*)x->Inquiry;
    if (!y) return;
    for (; y->gg.g.n; y = (struct zx_is_Inquiry_s*)y->gg.g.n) ;
    break;
  default:
    for (y = x->Inquiry; n > 1 && y->gg.g.n; --n, y = (struct zx_is_Inquiry_s*)y->gg.g.n) ;
    if (!y->gg.g.n) return;
  }
  y->gg.g.n = y->gg.g.n->n;
}

#endif



#ifdef ZX_ENA_GETPUT

/* FUNC(zx_is_InteractionStatement_NUM_Signature) */

int zx_is_InteractionStatement_NUM_Signature(struct zx_is_InteractionStatement_s* x)
{
  struct zx_ds_Signature_s* y;
  int n = 0;
  if (!x) return 0;
  for (y = x->Signature; y; ++n, y = (struct zx_ds_Signature_s*)y->gg.g.n) ;
  return n;
}

/* FUNC(zx_is_InteractionStatement_GET_Signature) */

struct zx_ds_Signature_s* zx_is_InteractionStatement_GET_Signature(struct zx_is_InteractionStatement_s* x, int n)
{
  struct zx_ds_Signature_s* y;
  if (!x) return 0;
  for (y = x->Signature; n>=0 && y; --n, y = (struct zx_ds_Signature_s*)y->gg.g.n) ;
  return y;
}

/* FUNC(zx_is_InteractionStatement_POP_Signature) */

struct zx_ds_Signature_s* zx_is_InteractionStatement_POP_Signature(struct zx_is_InteractionStatement_s* x)
{
  struct zx_ds_Signature_s* y;
  if (!x) return 0;
  y = x->Signature;
  if (y)
    x->Signature = (struct zx_ds_Signature_s*)y->gg.g.n;
  return y;
}

/* FUNC(zx_is_InteractionStatement_PUSH_Signature) */

void zx_is_InteractionStatement_PUSH_Signature(struct zx_is_InteractionStatement_s* x, struct zx_ds_Signature_s* z)
{
  if (!x || !z) return;
  z->gg.g.n = &x->Signature->gg.g;
  x->Signature = z;
}

/* FUNC(zx_is_InteractionStatement_REV_Signature) */

void zx_is_InteractionStatement_REV_Signature(struct zx_is_InteractionStatement_s* x)
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

/* FUNC(zx_is_InteractionStatement_PUT_Signature) */

void zx_is_InteractionStatement_PUT_Signature(struct zx_is_InteractionStatement_s* x, int n, struct zx_ds_Signature_s* z)
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

/* FUNC(zx_is_InteractionStatement_ADD_Signature) */

void zx_is_InteractionStatement_ADD_Signature(struct zx_is_InteractionStatement_s* x, int n, struct zx_ds_Signature_s* z)
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

/* FUNC(zx_is_InteractionStatement_DEL_Signature) */

void zx_is_InteractionStatement_DEL_Signature(struct zx_is_InteractionStatement_s* x, int n)
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

/* FUNC(zx_is_Item_NUM_Hint) */

int zx_is_Item_NUM_Hint(struct zx_is_Item_s* x)
{
  struct zx_elem_s* y;
  int n = 0;
  if (!x) return 0;
  for (y = x->Hint; y; ++n, y = (struct zx_elem_s*)y->g.n) ;
  return n;
}

/* FUNC(zx_is_Item_GET_Hint) */

struct zx_elem_s* zx_is_Item_GET_Hint(struct zx_is_Item_s* x, int n)
{
  struct zx_elem_s* y;
  if (!x) return 0;
  for (y = x->Hint; n>=0 && y; --n, y = (struct zx_elem_s*)y->g.n) ;
  return y;
}

/* FUNC(zx_is_Item_POP_Hint) */

struct zx_elem_s* zx_is_Item_POP_Hint(struct zx_is_Item_s* x)
{
  struct zx_elem_s* y;
  if (!x) return 0;
  y = x->Hint;
  if (y)
    x->Hint = (struct zx_elem_s*)y->g.n;
  return y;
}

/* FUNC(zx_is_Item_PUSH_Hint) */

void zx_is_Item_PUSH_Hint(struct zx_is_Item_s* x, struct zx_elem_s* z)
{
  if (!x || !z) return;
  z->g.n = &x->Hint->g;
  x->Hint = z;
}

/* FUNC(zx_is_Item_REV_Hint) */

void zx_is_Item_REV_Hint(struct zx_is_Item_s* x)
{
  struct zx_elem_s* nxt;
  struct zx_elem_s* y;
  if (!x) return;
  y = x->Hint;
  if (!y) return;
  x->Hint = 0;
  while (y) {
    nxt = (struct zx_elem_s*)y->g.n;
    y->g.n = &x->Hint->g;
    x->Hint = y;
    y = nxt;
  }
}

/* FUNC(zx_is_Item_PUT_Hint) */

void zx_is_Item_PUT_Hint(struct zx_is_Item_s* x, int n, struct zx_elem_s* z)
{
  struct zx_elem_s* y;
  if (!x || !z) return;
  y = x->Hint;
  if (!y) return;
  switch (n) {
  case 0:
    z->g.n = y->g.n;
    x->Hint = z;
    return;
  default:
    for (; n > 1 && y->g.n; --n, y = (struct zx_elem_s*)y->g.n) ;
    if (!y->g.n) return;
    z->g.n = y->g.n->n;
    y->g.n = &z->g;
  }
}

/* FUNC(zx_is_Item_ADD_Hint) */

void zx_is_Item_ADD_Hint(struct zx_is_Item_s* x, int n, struct zx_elem_s* z)
{
  struct zx_elem_s* y;
  if (!x || !z) return;
  switch (n) {
  case 0:
  add_to_start:
    z->g.n = &x->Hint->g;
    x->Hint = z;
    return;
  case -1:
    y = x->Hint;
    if (!y) goto add_to_start;
    for (; y->g.n; y = (struct zx_elem_s*)y->g.n) ;
    break;
  default:
    for (y = x->Hint; n > 1 && y; --n, y = (struct zx_elem_s*)y->g.n) ;
    if (!y) return;
  }
  z->g.n = y->g.n;
  y->g.n = &z->g;
}

/* FUNC(zx_is_Item_DEL_Hint) */

void zx_is_Item_DEL_Hint(struct zx_is_Item_s* x, int n)
{
  struct zx_elem_s* y;
  if (!x) return;
  switch (n) {
  case 0:
    x->Hint = (struct zx_elem_s*)x->Hint->g.n;
    return;
  case -1:
    y = (struct zx_elem_s*)x->Hint;
    if (!y) return;
    for (; y->g.n; y = (struct zx_elem_s*)y->g.n) ;
    break;
  default:
    for (y = x->Hint; n > 1 && y->g.n; --n, y = (struct zx_elem_s*)y->g.n) ;
    if (!y->g.n) return;
  }
  y->g.n = y->g.n->n;
}

#endif

/* FUNC(zx_is_Item_GET_label) */
struct zx_str* zx_is_Item_GET_label(struct zx_is_Item_s* x) { return x->label; }
/* FUNC(zx_is_Item_PUT_label) */
void zx_is_Item_PUT_label(struct zx_is_Item_s* x, struct zx_str* y) { x->label = y; }
/* FUNC(zx_is_Item_GET_value) */
struct zx_str* zx_is_Item_GET_value(struct zx_is_Item_s* x) { return x->value; }
/* FUNC(zx_is_Item_PUT_value) */
void zx_is_Item_PUT_value(struct zx_is_Item_s* x, struct zx_str* y) { x->value = y; }





/* FUNC(zx_is_Parameter_GET_name) */
struct zx_str* zx_is_Parameter_GET_name(struct zx_is_Parameter_s* x) { return x->name; }
/* FUNC(zx_is_Parameter_PUT_name) */
void zx_is_Parameter_PUT_name(struct zx_is_Parameter_s* x, struct zx_str* y) { x->name = y; }
/* FUNC(zx_is_Parameter_GET_value) */
struct zx_str* zx_is_Parameter_GET_value(struct zx_is_Parameter_s* x) { return x->value; }
/* FUNC(zx_is_Parameter_PUT_value) */
void zx_is_Parameter_PUT_value(struct zx_is_Parameter_s* x, struct zx_str* y) { x->value = y; }







#ifdef ZX_ENA_GETPUT

/* FUNC(zx_is_Select_NUM_Help) */

int zx_is_Select_NUM_Help(struct zx_is_Select_s* x)
{
  struct zx_is_Help_s* y;
  int n = 0;
  if (!x) return 0;
  for (y = x->Help; y; ++n, y = (struct zx_is_Help_s*)y->gg.g.n) ;
  return n;
}

/* FUNC(zx_is_Select_GET_Help) */

struct zx_is_Help_s* zx_is_Select_GET_Help(struct zx_is_Select_s* x, int n)
{
  struct zx_is_Help_s* y;
  if (!x) return 0;
  for (y = x->Help; n>=0 && y; --n, y = (struct zx_is_Help_s*)y->gg.g.n) ;
  return y;
}

/* FUNC(zx_is_Select_POP_Help) */

struct zx_is_Help_s* zx_is_Select_POP_Help(struct zx_is_Select_s* x)
{
  struct zx_is_Help_s* y;
  if (!x) return 0;
  y = x->Help;
  if (y)
    x->Help = (struct zx_is_Help_s*)y->gg.g.n;
  return y;
}

/* FUNC(zx_is_Select_PUSH_Help) */

void zx_is_Select_PUSH_Help(struct zx_is_Select_s* x, struct zx_is_Help_s* z)
{
  if (!x || !z) return;
  z->gg.g.n = &x->Help->gg.g;
  x->Help = z;
}

/* FUNC(zx_is_Select_REV_Help) */

void zx_is_Select_REV_Help(struct zx_is_Select_s* x)
{
  struct zx_is_Help_s* nxt;
  struct zx_is_Help_s* y;
  if (!x) return;
  y = x->Help;
  if (!y) return;
  x->Help = 0;
  while (y) {
    nxt = (struct zx_is_Help_s*)y->gg.g.n;
    y->gg.g.n = &x->Help->gg.g;
    x->Help = y;
    y = nxt;
  }
}

/* FUNC(zx_is_Select_PUT_Help) */

void zx_is_Select_PUT_Help(struct zx_is_Select_s* x, int n, struct zx_is_Help_s* z)
{
  struct zx_is_Help_s* y;
  if (!x || !z) return;
  y = x->Help;
  if (!y) return;
  switch (n) {
  case 0:
    z->gg.g.n = y->gg.g.n;
    x->Help = z;
    return;
  default:
    for (; n > 1 && y->gg.g.n; --n, y = (struct zx_is_Help_s*)y->gg.g.n) ;
    if (!y->gg.g.n) return;
    z->gg.g.n = y->gg.g.n->n;
    y->gg.g.n = &z->gg.g;
  }
}

/* FUNC(zx_is_Select_ADD_Help) */

void zx_is_Select_ADD_Help(struct zx_is_Select_s* x, int n, struct zx_is_Help_s* z)
{
  struct zx_is_Help_s* y;
  if (!x || !z) return;
  switch (n) {
  case 0:
  add_to_start:
    z->gg.g.n = &x->Help->gg.g;
    x->Help = z;
    return;
  case -1:
    y = x->Help;
    if (!y) goto add_to_start;
    for (; y->gg.g.n; y = (struct zx_is_Help_s*)y->gg.g.n) ;
    break;
  default:
    for (y = x->Help; n > 1 && y; --n, y = (struct zx_is_Help_s*)y->gg.g.n) ;
    if (!y) return;
  }
  z->gg.g.n = y->gg.g.n;
  y->gg.g.n = &z->gg.g;
}

/* FUNC(zx_is_Select_DEL_Help) */

void zx_is_Select_DEL_Help(struct zx_is_Select_s* x, int n)
{
  struct zx_is_Help_s* y;
  if (!x) return;
  switch (n) {
  case 0:
    x->Help = (struct zx_is_Help_s*)x->Help->gg.g.n;
    return;
  case -1:
    y = (struct zx_is_Help_s*)x->Help;
    if (!y) return;
    for (; y->gg.g.n; y = (struct zx_is_Help_s*)y->gg.g.n) ;
    break;
  default:
    for (y = x->Help; n > 1 && y->gg.g.n; --n, y = (struct zx_is_Help_s*)y->gg.g.n) ;
    if (!y->gg.g.n) return;
  }
  y->gg.g.n = y->gg.g.n->n;
}

#endif



#ifdef ZX_ENA_GETPUT

/* FUNC(zx_is_Select_NUM_Hint) */

int zx_is_Select_NUM_Hint(struct zx_is_Select_s* x)
{
  struct zx_elem_s* y;
  int n = 0;
  if (!x) return 0;
  for (y = x->Hint; y; ++n, y = (struct zx_elem_s*)y->g.n) ;
  return n;
}

/* FUNC(zx_is_Select_GET_Hint) */

struct zx_elem_s* zx_is_Select_GET_Hint(struct zx_is_Select_s* x, int n)
{
  struct zx_elem_s* y;
  if (!x) return 0;
  for (y = x->Hint; n>=0 && y; --n, y = (struct zx_elem_s*)y->g.n) ;
  return y;
}

/* FUNC(zx_is_Select_POP_Hint) */

struct zx_elem_s* zx_is_Select_POP_Hint(struct zx_is_Select_s* x)
{
  struct zx_elem_s* y;
  if (!x) return 0;
  y = x->Hint;
  if (y)
    x->Hint = (struct zx_elem_s*)y->g.n;
  return y;
}

/* FUNC(zx_is_Select_PUSH_Hint) */

void zx_is_Select_PUSH_Hint(struct zx_is_Select_s* x, struct zx_elem_s* z)
{
  if (!x || !z) return;
  z->g.n = &x->Hint->g;
  x->Hint = z;
}

/* FUNC(zx_is_Select_REV_Hint) */

void zx_is_Select_REV_Hint(struct zx_is_Select_s* x)
{
  struct zx_elem_s* nxt;
  struct zx_elem_s* y;
  if (!x) return;
  y = x->Hint;
  if (!y) return;
  x->Hint = 0;
  while (y) {
    nxt = (struct zx_elem_s*)y->g.n;
    y->g.n = &x->Hint->g;
    x->Hint = y;
    y = nxt;
  }
}

/* FUNC(zx_is_Select_PUT_Hint) */

void zx_is_Select_PUT_Hint(struct zx_is_Select_s* x, int n, struct zx_elem_s* z)
{
  struct zx_elem_s* y;
  if (!x || !z) return;
  y = x->Hint;
  if (!y) return;
  switch (n) {
  case 0:
    z->g.n = y->g.n;
    x->Hint = z;
    return;
  default:
    for (; n > 1 && y->g.n; --n, y = (struct zx_elem_s*)y->g.n) ;
    if (!y->g.n) return;
    z->g.n = y->g.n->n;
    y->g.n = &z->g;
  }
}

/* FUNC(zx_is_Select_ADD_Hint) */

void zx_is_Select_ADD_Hint(struct zx_is_Select_s* x, int n, struct zx_elem_s* z)
{
  struct zx_elem_s* y;
  if (!x || !z) return;
  switch (n) {
  case 0:
  add_to_start:
    z->g.n = &x->Hint->g;
    x->Hint = z;
    return;
  case -1:
    y = x->Hint;
    if (!y) goto add_to_start;
    for (; y->g.n; y = (struct zx_elem_s*)y->g.n) ;
    break;
  default:
    for (y = x->Hint; n > 1 && y; --n, y = (struct zx_elem_s*)y->g.n) ;
    if (!y) return;
  }
  z->g.n = y->g.n;
  y->g.n = &z->g;
}

/* FUNC(zx_is_Select_DEL_Hint) */

void zx_is_Select_DEL_Hint(struct zx_is_Select_s* x, int n)
{
  struct zx_elem_s* y;
  if (!x) return;
  switch (n) {
  case 0:
    x->Hint = (struct zx_elem_s*)x->Hint->g.n;
    return;
  case -1:
    y = (struct zx_elem_s*)x->Hint;
    if (!y) return;
    for (; y->g.n; y = (struct zx_elem_s*)y->g.n) ;
    break;
  default:
    for (y = x->Hint; n > 1 && y->g.n; --n, y = (struct zx_elem_s*)y->g.n) ;
    if (!y->g.n) return;
  }
  y->g.n = y->g.n->n;
}

#endif



#ifdef ZX_ENA_GETPUT

/* FUNC(zx_is_Select_NUM_Label) */

int zx_is_Select_NUM_Label(struct zx_is_Select_s* x)
{
  struct zx_elem_s* y;
  int n = 0;
  if (!x) return 0;
  for (y = x->Label; y; ++n, y = (struct zx_elem_s*)y->g.n) ;
  return n;
}

/* FUNC(zx_is_Select_GET_Label) */

struct zx_elem_s* zx_is_Select_GET_Label(struct zx_is_Select_s* x, int n)
{
  struct zx_elem_s* y;
  if (!x) return 0;
  for (y = x->Label; n>=0 && y; --n, y = (struct zx_elem_s*)y->g.n) ;
  return y;
}

/* FUNC(zx_is_Select_POP_Label) */

struct zx_elem_s* zx_is_Select_POP_Label(struct zx_is_Select_s* x)
{
  struct zx_elem_s* y;
  if (!x) return 0;
  y = x->Label;
  if (y)
    x->Label = (struct zx_elem_s*)y->g.n;
  return y;
}

/* FUNC(zx_is_Select_PUSH_Label) */

void zx_is_Select_PUSH_Label(struct zx_is_Select_s* x, struct zx_elem_s* z)
{
  if (!x || !z) return;
  z->g.n = &x->Label->g;
  x->Label = z;
}

/* FUNC(zx_is_Select_REV_Label) */

void zx_is_Select_REV_Label(struct zx_is_Select_s* x)
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

/* FUNC(zx_is_Select_PUT_Label) */

void zx_is_Select_PUT_Label(struct zx_is_Select_s* x, int n, struct zx_elem_s* z)
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

/* FUNC(zx_is_Select_ADD_Label) */

void zx_is_Select_ADD_Label(struct zx_is_Select_s* x, int n, struct zx_elem_s* z)
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

/* FUNC(zx_is_Select_DEL_Label) */

void zx_is_Select_DEL_Label(struct zx_is_Select_s* x, int n)
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

/* FUNC(zx_is_Select_NUM_Value) */

int zx_is_Select_NUM_Value(struct zx_is_Select_s* x)
{
  struct zx_elem_s* y;
  int n = 0;
  if (!x) return 0;
  for (y = x->Value; y; ++n, y = (struct zx_elem_s*)y->g.n) ;
  return n;
}

/* FUNC(zx_is_Select_GET_Value) */

struct zx_elem_s* zx_is_Select_GET_Value(struct zx_is_Select_s* x, int n)
{
  struct zx_elem_s* y;
  if (!x) return 0;
  for (y = x->Value; n>=0 && y; --n, y = (struct zx_elem_s*)y->g.n) ;
  return y;
}

/* FUNC(zx_is_Select_POP_Value) */

struct zx_elem_s* zx_is_Select_POP_Value(struct zx_is_Select_s* x)
{
  struct zx_elem_s* y;
  if (!x) return 0;
  y = x->Value;
  if (y)
    x->Value = (struct zx_elem_s*)y->g.n;
  return y;
}

/* FUNC(zx_is_Select_PUSH_Value) */

void zx_is_Select_PUSH_Value(struct zx_is_Select_s* x, struct zx_elem_s* z)
{
  if (!x || !z) return;
  z->g.n = &x->Value->g;
  x->Value = z;
}

/* FUNC(zx_is_Select_REV_Value) */

void zx_is_Select_REV_Value(struct zx_is_Select_s* x)
{
  struct zx_elem_s* nxt;
  struct zx_elem_s* y;
  if (!x) return;
  y = x->Value;
  if (!y) return;
  x->Value = 0;
  while (y) {
    nxt = (struct zx_elem_s*)y->g.n;
    y->g.n = &x->Value->g;
    x->Value = y;
    y = nxt;
  }
}

/* FUNC(zx_is_Select_PUT_Value) */

void zx_is_Select_PUT_Value(struct zx_is_Select_s* x, int n, struct zx_elem_s* z)
{
  struct zx_elem_s* y;
  if (!x || !z) return;
  y = x->Value;
  if (!y) return;
  switch (n) {
  case 0:
    z->g.n = y->g.n;
    x->Value = z;
    return;
  default:
    for (; n > 1 && y->g.n; --n, y = (struct zx_elem_s*)y->g.n) ;
    if (!y->g.n) return;
    z->g.n = y->g.n->n;
    y->g.n = &z->g;
  }
}

/* FUNC(zx_is_Select_ADD_Value) */

void zx_is_Select_ADD_Value(struct zx_is_Select_s* x, int n, struct zx_elem_s* z)
{
  struct zx_elem_s* y;
  if (!x || !z) return;
  switch (n) {
  case 0:
  add_to_start:
    z->g.n = &x->Value->g;
    x->Value = z;
    return;
  case -1:
    y = x->Value;
    if (!y) goto add_to_start;
    for (; y->g.n; y = (struct zx_elem_s*)y->g.n) ;
    break;
  default:
    for (y = x->Value; n > 1 && y; --n, y = (struct zx_elem_s*)y->g.n) ;
    if (!y) return;
  }
  z->g.n = y->g.n;
  y->g.n = &z->g;
}

/* FUNC(zx_is_Select_DEL_Value) */

void zx_is_Select_DEL_Value(struct zx_is_Select_s* x, int n)
{
  struct zx_elem_s* y;
  if (!x) return;
  switch (n) {
  case 0:
    x->Value = (struct zx_elem_s*)x->Value->g.n;
    return;
  case -1:
    y = (struct zx_elem_s*)x->Value;
    if (!y) return;
    for (; y->g.n; y = (struct zx_elem_s*)y->g.n) ;
    break;
  default:
    for (y = x->Value; n > 1 && y->g.n; --n, y = (struct zx_elem_s*)y->g.n) ;
    if (!y->g.n) return;
  }
  y->g.n = y->g.n->n;
}

#endif



#ifdef ZX_ENA_GETPUT

/* FUNC(zx_is_Select_NUM_Item) */

int zx_is_Select_NUM_Item(struct zx_is_Select_s* x)
{
  struct zx_is_Item_s* y;
  int n = 0;
  if (!x) return 0;
  for (y = x->Item; y; ++n, y = (struct zx_is_Item_s*)y->gg.g.n) ;
  return n;
}

/* FUNC(zx_is_Select_GET_Item) */

struct zx_is_Item_s* zx_is_Select_GET_Item(struct zx_is_Select_s* x, int n)
{
  struct zx_is_Item_s* y;
  if (!x) return 0;
  for (y = x->Item; n>=0 && y; --n, y = (struct zx_is_Item_s*)y->gg.g.n) ;
  return y;
}

/* FUNC(zx_is_Select_POP_Item) */

struct zx_is_Item_s* zx_is_Select_POP_Item(struct zx_is_Select_s* x)
{
  struct zx_is_Item_s* y;
  if (!x) return 0;
  y = x->Item;
  if (y)
    x->Item = (struct zx_is_Item_s*)y->gg.g.n;
  return y;
}

/* FUNC(zx_is_Select_PUSH_Item) */

void zx_is_Select_PUSH_Item(struct zx_is_Select_s* x, struct zx_is_Item_s* z)
{
  if (!x || !z) return;
  z->gg.g.n = &x->Item->gg.g;
  x->Item = z;
}

/* FUNC(zx_is_Select_REV_Item) */

void zx_is_Select_REV_Item(struct zx_is_Select_s* x)
{
  struct zx_is_Item_s* nxt;
  struct zx_is_Item_s* y;
  if (!x) return;
  y = x->Item;
  if (!y) return;
  x->Item = 0;
  while (y) {
    nxt = (struct zx_is_Item_s*)y->gg.g.n;
    y->gg.g.n = &x->Item->gg.g;
    x->Item = y;
    y = nxt;
  }
}

/* FUNC(zx_is_Select_PUT_Item) */

void zx_is_Select_PUT_Item(struct zx_is_Select_s* x, int n, struct zx_is_Item_s* z)
{
  struct zx_is_Item_s* y;
  if (!x || !z) return;
  y = x->Item;
  if (!y) return;
  switch (n) {
  case 0:
    z->gg.g.n = y->gg.g.n;
    x->Item = z;
    return;
  default:
    for (; n > 1 && y->gg.g.n; --n, y = (struct zx_is_Item_s*)y->gg.g.n) ;
    if (!y->gg.g.n) return;
    z->gg.g.n = y->gg.g.n->n;
    y->gg.g.n = &z->gg.g;
  }
}

/* FUNC(zx_is_Select_ADD_Item) */

void zx_is_Select_ADD_Item(struct zx_is_Select_s* x, int n, struct zx_is_Item_s* z)
{
  struct zx_is_Item_s* y;
  if (!x || !z) return;
  switch (n) {
  case 0:
  add_to_start:
    z->gg.g.n = &x->Item->gg.g;
    x->Item = z;
    return;
  case -1:
    y = x->Item;
    if (!y) goto add_to_start;
    for (; y->gg.g.n; y = (struct zx_is_Item_s*)y->gg.g.n) ;
    break;
  default:
    for (y = x->Item; n > 1 && y; --n, y = (struct zx_is_Item_s*)y->gg.g.n) ;
    if (!y) return;
  }
  z->gg.g.n = y->gg.g.n;
  y->gg.g.n = &z->gg.g;
}

/* FUNC(zx_is_Select_DEL_Item) */

void zx_is_Select_DEL_Item(struct zx_is_Select_s* x, int n)
{
  struct zx_is_Item_s* y;
  if (!x) return;
  switch (n) {
  case 0:
    x->Item = (struct zx_is_Item_s*)x->Item->gg.g.n;
    return;
  case -1:
    y = (struct zx_is_Item_s*)x->Item;
    if (!y) return;
    for (; y->gg.g.n; y = (struct zx_is_Item_s*)y->gg.g.n) ;
    break;
  default:
    for (y = x->Item; n > 1 && y->gg.g.n; --n, y = (struct zx_is_Item_s*)y->gg.g.n) ;
    if (!y->gg.g.n) return;
  }
  y->gg.g.n = y->gg.g.n->n;
}

#endif

/* FUNC(zx_is_Select_GET_multiple) */
struct zx_str* zx_is_Select_GET_multiple(struct zx_is_Select_s* x) { return x->multiple; }
/* FUNC(zx_is_Select_PUT_multiple) */
void zx_is_Select_PUT_multiple(struct zx_is_Select_s* x, struct zx_str* y) { x->multiple = y; }
/* FUNC(zx_is_Select_GET_name) */
struct zx_str* zx_is_Select_GET_name(struct zx_is_Select_s* x) { return x->name; }
/* FUNC(zx_is_Select_PUT_name) */
void zx_is_Select_PUT_name(struct zx_is_Select_s* x, struct zx_str* y) { x->name = y; }







#ifdef ZX_ENA_GETPUT

/* FUNC(zx_is_Text_NUM_Help) */

int zx_is_Text_NUM_Help(struct zx_is_Text_s* x)
{
  struct zx_is_Help_s* y;
  int n = 0;
  if (!x) return 0;
  for (y = x->Help; y; ++n, y = (struct zx_is_Help_s*)y->gg.g.n) ;
  return n;
}

/* FUNC(zx_is_Text_GET_Help) */

struct zx_is_Help_s* zx_is_Text_GET_Help(struct zx_is_Text_s* x, int n)
{
  struct zx_is_Help_s* y;
  if (!x) return 0;
  for (y = x->Help; n>=0 && y; --n, y = (struct zx_is_Help_s*)y->gg.g.n) ;
  return y;
}

/* FUNC(zx_is_Text_POP_Help) */

struct zx_is_Help_s* zx_is_Text_POP_Help(struct zx_is_Text_s* x)
{
  struct zx_is_Help_s* y;
  if (!x) return 0;
  y = x->Help;
  if (y)
    x->Help = (struct zx_is_Help_s*)y->gg.g.n;
  return y;
}

/* FUNC(zx_is_Text_PUSH_Help) */

void zx_is_Text_PUSH_Help(struct zx_is_Text_s* x, struct zx_is_Help_s* z)
{
  if (!x || !z) return;
  z->gg.g.n = &x->Help->gg.g;
  x->Help = z;
}

/* FUNC(zx_is_Text_REV_Help) */

void zx_is_Text_REV_Help(struct zx_is_Text_s* x)
{
  struct zx_is_Help_s* nxt;
  struct zx_is_Help_s* y;
  if (!x) return;
  y = x->Help;
  if (!y) return;
  x->Help = 0;
  while (y) {
    nxt = (struct zx_is_Help_s*)y->gg.g.n;
    y->gg.g.n = &x->Help->gg.g;
    x->Help = y;
    y = nxt;
  }
}

/* FUNC(zx_is_Text_PUT_Help) */

void zx_is_Text_PUT_Help(struct zx_is_Text_s* x, int n, struct zx_is_Help_s* z)
{
  struct zx_is_Help_s* y;
  if (!x || !z) return;
  y = x->Help;
  if (!y) return;
  switch (n) {
  case 0:
    z->gg.g.n = y->gg.g.n;
    x->Help = z;
    return;
  default:
    for (; n > 1 && y->gg.g.n; --n, y = (struct zx_is_Help_s*)y->gg.g.n) ;
    if (!y->gg.g.n) return;
    z->gg.g.n = y->gg.g.n->n;
    y->gg.g.n = &z->gg.g;
  }
}

/* FUNC(zx_is_Text_ADD_Help) */

void zx_is_Text_ADD_Help(struct zx_is_Text_s* x, int n, struct zx_is_Help_s* z)
{
  struct zx_is_Help_s* y;
  if (!x || !z) return;
  switch (n) {
  case 0:
  add_to_start:
    z->gg.g.n = &x->Help->gg.g;
    x->Help = z;
    return;
  case -1:
    y = x->Help;
    if (!y) goto add_to_start;
    for (; y->gg.g.n; y = (struct zx_is_Help_s*)y->gg.g.n) ;
    break;
  default:
    for (y = x->Help; n > 1 && y; --n, y = (struct zx_is_Help_s*)y->gg.g.n) ;
    if (!y) return;
  }
  z->gg.g.n = y->gg.g.n;
  y->gg.g.n = &z->gg.g;
}

/* FUNC(zx_is_Text_DEL_Help) */

void zx_is_Text_DEL_Help(struct zx_is_Text_s* x, int n)
{
  struct zx_is_Help_s* y;
  if (!x) return;
  switch (n) {
  case 0:
    x->Help = (struct zx_is_Help_s*)x->Help->gg.g.n;
    return;
  case -1:
    y = (struct zx_is_Help_s*)x->Help;
    if (!y) return;
    for (; y->gg.g.n; y = (struct zx_is_Help_s*)y->gg.g.n) ;
    break;
  default:
    for (y = x->Help; n > 1 && y->gg.g.n; --n, y = (struct zx_is_Help_s*)y->gg.g.n) ;
    if (!y->gg.g.n) return;
  }
  y->gg.g.n = y->gg.g.n->n;
}

#endif



#ifdef ZX_ENA_GETPUT

/* FUNC(zx_is_Text_NUM_Hint) */

int zx_is_Text_NUM_Hint(struct zx_is_Text_s* x)
{
  struct zx_elem_s* y;
  int n = 0;
  if (!x) return 0;
  for (y = x->Hint; y; ++n, y = (struct zx_elem_s*)y->g.n) ;
  return n;
}

/* FUNC(zx_is_Text_GET_Hint) */

struct zx_elem_s* zx_is_Text_GET_Hint(struct zx_is_Text_s* x, int n)
{
  struct zx_elem_s* y;
  if (!x) return 0;
  for (y = x->Hint; n>=0 && y; --n, y = (struct zx_elem_s*)y->g.n) ;
  return y;
}

/* FUNC(zx_is_Text_POP_Hint) */

struct zx_elem_s* zx_is_Text_POP_Hint(struct zx_is_Text_s* x)
{
  struct zx_elem_s* y;
  if (!x) return 0;
  y = x->Hint;
  if (y)
    x->Hint = (struct zx_elem_s*)y->g.n;
  return y;
}

/* FUNC(zx_is_Text_PUSH_Hint) */

void zx_is_Text_PUSH_Hint(struct zx_is_Text_s* x, struct zx_elem_s* z)
{
  if (!x || !z) return;
  z->g.n = &x->Hint->g;
  x->Hint = z;
}

/* FUNC(zx_is_Text_REV_Hint) */

void zx_is_Text_REV_Hint(struct zx_is_Text_s* x)
{
  struct zx_elem_s* nxt;
  struct zx_elem_s* y;
  if (!x) return;
  y = x->Hint;
  if (!y) return;
  x->Hint = 0;
  while (y) {
    nxt = (struct zx_elem_s*)y->g.n;
    y->g.n = &x->Hint->g;
    x->Hint = y;
    y = nxt;
  }
}

/* FUNC(zx_is_Text_PUT_Hint) */

void zx_is_Text_PUT_Hint(struct zx_is_Text_s* x, int n, struct zx_elem_s* z)
{
  struct zx_elem_s* y;
  if (!x || !z) return;
  y = x->Hint;
  if (!y) return;
  switch (n) {
  case 0:
    z->g.n = y->g.n;
    x->Hint = z;
    return;
  default:
    for (; n > 1 && y->g.n; --n, y = (struct zx_elem_s*)y->g.n) ;
    if (!y->g.n) return;
    z->g.n = y->g.n->n;
    y->g.n = &z->g;
  }
}

/* FUNC(zx_is_Text_ADD_Hint) */

void zx_is_Text_ADD_Hint(struct zx_is_Text_s* x, int n, struct zx_elem_s* z)
{
  struct zx_elem_s* y;
  if (!x || !z) return;
  switch (n) {
  case 0:
  add_to_start:
    z->g.n = &x->Hint->g;
    x->Hint = z;
    return;
  case -1:
    y = x->Hint;
    if (!y) goto add_to_start;
    for (; y->g.n; y = (struct zx_elem_s*)y->g.n) ;
    break;
  default:
    for (y = x->Hint; n > 1 && y; --n, y = (struct zx_elem_s*)y->g.n) ;
    if (!y) return;
  }
  z->g.n = y->g.n;
  y->g.n = &z->g;
}

/* FUNC(zx_is_Text_DEL_Hint) */

void zx_is_Text_DEL_Hint(struct zx_is_Text_s* x, int n)
{
  struct zx_elem_s* y;
  if (!x) return;
  switch (n) {
  case 0:
    x->Hint = (struct zx_elem_s*)x->Hint->g.n;
    return;
  case -1:
    y = (struct zx_elem_s*)x->Hint;
    if (!y) return;
    for (; y->g.n; y = (struct zx_elem_s*)y->g.n) ;
    break;
  default:
    for (y = x->Hint; n > 1 && y->g.n; --n, y = (struct zx_elem_s*)y->g.n) ;
    if (!y->g.n) return;
  }
  y->g.n = y->g.n->n;
}

#endif



#ifdef ZX_ENA_GETPUT

/* FUNC(zx_is_Text_NUM_Label) */

int zx_is_Text_NUM_Label(struct zx_is_Text_s* x)
{
  struct zx_elem_s* y;
  int n = 0;
  if (!x) return 0;
  for (y = x->Label; y; ++n, y = (struct zx_elem_s*)y->g.n) ;
  return n;
}

/* FUNC(zx_is_Text_GET_Label) */

struct zx_elem_s* zx_is_Text_GET_Label(struct zx_is_Text_s* x, int n)
{
  struct zx_elem_s* y;
  if (!x) return 0;
  for (y = x->Label; n>=0 && y; --n, y = (struct zx_elem_s*)y->g.n) ;
  return y;
}

/* FUNC(zx_is_Text_POP_Label) */

struct zx_elem_s* zx_is_Text_POP_Label(struct zx_is_Text_s* x)
{
  struct zx_elem_s* y;
  if (!x) return 0;
  y = x->Label;
  if (y)
    x->Label = (struct zx_elem_s*)y->g.n;
  return y;
}

/* FUNC(zx_is_Text_PUSH_Label) */

void zx_is_Text_PUSH_Label(struct zx_is_Text_s* x, struct zx_elem_s* z)
{
  if (!x || !z) return;
  z->g.n = &x->Label->g;
  x->Label = z;
}

/* FUNC(zx_is_Text_REV_Label) */

void zx_is_Text_REV_Label(struct zx_is_Text_s* x)
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

/* FUNC(zx_is_Text_PUT_Label) */

void zx_is_Text_PUT_Label(struct zx_is_Text_s* x, int n, struct zx_elem_s* z)
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

/* FUNC(zx_is_Text_ADD_Label) */

void zx_is_Text_ADD_Label(struct zx_is_Text_s* x, int n, struct zx_elem_s* z)
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

/* FUNC(zx_is_Text_DEL_Label) */

void zx_is_Text_DEL_Label(struct zx_is_Text_s* x, int n)
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

/* FUNC(zx_is_Text_NUM_Value) */

int zx_is_Text_NUM_Value(struct zx_is_Text_s* x)
{
  struct zx_elem_s* y;
  int n = 0;
  if (!x) return 0;
  for (y = x->Value; y; ++n, y = (struct zx_elem_s*)y->g.n) ;
  return n;
}

/* FUNC(zx_is_Text_GET_Value) */

struct zx_elem_s* zx_is_Text_GET_Value(struct zx_is_Text_s* x, int n)
{
  struct zx_elem_s* y;
  if (!x) return 0;
  for (y = x->Value; n>=0 && y; --n, y = (struct zx_elem_s*)y->g.n) ;
  return y;
}

/* FUNC(zx_is_Text_POP_Value) */

struct zx_elem_s* zx_is_Text_POP_Value(struct zx_is_Text_s* x)
{
  struct zx_elem_s* y;
  if (!x) return 0;
  y = x->Value;
  if (y)
    x->Value = (struct zx_elem_s*)y->g.n;
  return y;
}

/* FUNC(zx_is_Text_PUSH_Value) */

void zx_is_Text_PUSH_Value(struct zx_is_Text_s* x, struct zx_elem_s* z)
{
  if (!x || !z) return;
  z->g.n = &x->Value->g;
  x->Value = z;
}

/* FUNC(zx_is_Text_REV_Value) */

void zx_is_Text_REV_Value(struct zx_is_Text_s* x)
{
  struct zx_elem_s* nxt;
  struct zx_elem_s* y;
  if (!x) return;
  y = x->Value;
  if (!y) return;
  x->Value = 0;
  while (y) {
    nxt = (struct zx_elem_s*)y->g.n;
    y->g.n = &x->Value->g;
    x->Value = y;
    y = nxt;
  }
}

/* FUNC(zx_is_Text_PUT_Value) */

void zx_is_Text_PUT_Value(struct zx_is_Text_s* x, int n, struct zx_elem_s* z)
{
  struct zx_elem_s* y;
  if (!x || !z) return;
  y = x->Value;
  if (!y) return;
  switch (n) {
  case 0:
    z->g.n = y->g.n;
    x->Value = z;
    return;
  default:
    for (; n > 1 && y->g.n; --n, y = (struct zx_elem_s*)y->g.n) ;
    if (!y->g.n) return;
    z->g.n = y->g.n->n;
    y->g.n = &z->g;
  }
}

/* FUNC(zx_is_Text_ADD_Value) */

void zx_is_Text_ADD_Value(struct zx_is_Text_s* x, int n, struct zx_elem_s* z)
{
  struct zx_elem_s* y;
  if (!x || !z) return;
  switch (n) {
  case 0:
  add_to_start:
    z->g.n = &x->Value->g;
    x->Value = z;
    return;
  case -1:
    y = x->Value;
    if (!y) goto add_to_start;
    for (; y->g.n; y = (struct zx_elem_s*)y->g.n) ;
    break;
  default:
    for (y = x->Value; n > 1 && y; --n, y = (struct zx_elem_s*)y->g.n) ;
    if (!y) return;
  }
  z->g.n = y->g.n;
  y->g.n = &z->g;
}

/* FUNC(zx_is_Text_DEL_Value) */

void zx_is_Text_DEL_Value(struct zx_is_Text_s* x, int n)
{
  struct zx_elem_s* y;
  if (!x) return;
  switch (n) {
  case 0:
    x->Value = (struct zx_elem_s*)x->Value->g.n;
    return;
  case -1:
    y = (struct zx_elem_s*)x->Value;
    if (!y) return;
    for (; y->g.n; y = (struct zx_elem_s*)y->g.n) ;
    break;
  default:
    for (y = x->Value; n > 1 && y->g.n; --n, y = (struct zx_elem_s*)y->g.n) ;
    if (!y->g.n) return;
  }
  y->g.n = y->g.n->n;
}

#endif

/* FUNC(zx_is_Text_GET_format) */
struct zx_str* zx_is_Text_GET_format(struct zx_is_Text_s* x) { return x->format; }
/* FUNC(zx_is_Text_PUT_format) */
void zx_is_Text_PUT_format(struct zx_is_Text_s* x, struct zx_str* y) { x->format = y; }
/* FUNC(zx_is_Text_GET_maxChars) */
struct zx_str* zx_is_Text_GET_maxChars(struct zx_is_Text_s* x) { return x->maxChars; }
/* FUNC(zx_is_Text_PUT_maxChars) */
void zx_is_Text_PUT_maxChars(struct zx_is_Text_s* x, struct zx_str* y) { x->maxChars = y; }
/* FUNC(zx_is_Text_GET_minChars) */
struct zx_str* zx_is_Text_GET_minChars(struct zx_is_Text_s* x) { return x->minChars; }
/* FUNC(zx_is_Text_PUT_minChars) */
void zx_is_Text_PUT_minChars(struct zx_is_Text_s* x, struct zx_str* y) { x->minChars = y; }
/* FUNC(zx_is_Text_GET_name) */
struct zx_str* zx_is_Text_GET_name(struct zx_is_Text_s* x) { return x->name; }
/* FUNC(zx_is_Text_PUT_name) */
void zx_is_Text_PUT_name(struct zx_is_Text_s* x, struct zx_str* y) { x->name = y; }





/* EOF -- c/zx-is-getput.c */
