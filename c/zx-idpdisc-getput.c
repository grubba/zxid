/* c/zx-idpdisc-getput.c - WARNING: This file was automatically generated. DO NOT EDIT!
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
#include "c/zx-idpdisc-data.h"

/* FUNC(zx_idpdisc_DiscoveryResponse_GET_Binding) */
struct zx_str* zx_idpdisc_DiscoveryResponse_GET_Binding(struct zx_idpdisc_DiscoveryResponse_s* x) { return x->Binding; }
/* FUNC(zx_idpdisc_DiscoveryResponse_PUT_Binding) */
void zx_idpdisc_DiscoveryResponse_PUT_Binding(struct zx_idpdisc_DiscoveryResponse_s* x, struct zx_str* y) { x->Binding = y; }
/* FUNC(zx_idpdisc_DiscoveryResponse_GET_Location) */
struct zx_str* zx_idpdisc_DiscoveryResponse_GET_Location(struct zx_idpdisc_DiscoveryResponse_s* x) { return x->Location; }
/* FUNC(zx_idpdisc_DiscoveryResponse_PUT_Location) */
void zx_idpdisc_DiscoveryResponse_PUT_Location(struct zx_idpdisc_DiscoveryResponse_s* x, struct zx_str* y) { x->Location = y; }
/* FUNC(zx_idpdisc_DiscoveryResponse_GET_ResponseLocation) */
struct zx_str* zx_idpdisc_DiscoveryResponse_GET_ResponseLocation(struct zx_idpdisc_DiscoveryResponse_s* x) { return x->ResponseLocation; }
/* FUNC(zx_idpdisc_DiscoveryResponse_PUT_ResponseLocation) */
void zx_idpdisc_DiscoveryResponse_PUT_ResponseLocation(struct zx_idpdisc_DiscoveryResponse_s* x, struct zx_str* y) { x->ResponseLocation = y; }
/* FUNC(zx_idpdisc_DiscoveryResponse_GET_index) */
struct zx_str* zx_idpdisc_DiscoveryResponse_GET_index(struct zx_idpdisc_DiscoveryResponse_s* x) { return x->index; }
/* FUNC(zx_idpdisc_DiscoveryResponse_PUT_index) */
void zx_idpdisc_DiscoveryResponse_PUT_index(struct zx_idpdisc_DiscoveryResponse_s* x, struct zx_str* y) { x->index = y; }
/* FUNC(zx_idpdisc_DiscoveryResponse_GET_isDefault) */
struct zx_str* zx_idpdisc_DiscoveryResponse_GET_isDefault(struct zx_idpdisc_DiscoveryResponse_s* x) { return x->isDefault; }
/* FUNC(zx_idpdisc_DiscoveryResponse_PUT_isDefault) */
void zx_idpdisc_DiscoveryResponse_PUT_isDefault(struct zx_idpdisc_DiscoveryResponse_s* x, struct zx_str* y) { x->isDefault = y; }





/* EOF -- c/zx-idpdisc-getput.c */
