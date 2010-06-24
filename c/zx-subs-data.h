/* c/zx-subs-data.h - WARNING: This header was automatically generated. DO NOT EDIT!
 * $Id$ */
/* Datastructure design, topography, and layout
 * Copyright (c) 2006 Sampo Kellomaki (sampo@iki.fi),
 * All Rights Reserved. NO WARRANTY. See file COPYING for
 * terms and conditions of use. Element and attributes names as well
 * as some topography are derived from schema descriptions that were used as
 * input and may be subject to their own copright. */

#ifndef _c_zx_subs_data_h
#define _c_zx_subs_data_h

#include "zx.h"
#include "c/zx-const.h"
#include "c/zx-data.h"

#ifndef ZX_ELEM_EXT
#define ZX_ELEM_EXT  /* This extension point should be defined by who includes this file. */
#endif

/* -------------------------- subs_RefItem -------------------------- */
/* refby( zx_ps_Subscription_s zx_dap_Subscription_s zx_idhrxml_Subscription_s ) */
#ifndef zx_subs_RefItem_EXT
#define zx_subs_RefItem_EXT
#endif

struct zx_subs_RefItem_s* zx_DEC_subs_RefItem(struct zx_ctx* c, struct zx_ns_s* ns);
struct zx_subs_RefItem_s* zx_NEW_subs_RefItem(struct zx_ctx* c);
void zx_FREE_subs_RefItem(struct zx_ctx* c, struct zx_subs_RefItem_s* x, int free_strs);
#ifdef ZX_ENA_AUX
struct zx_subs_RefItem_s* zx_DEEP_CLONE_subs_RefItem(struct zx_ctx* c, struct zx_subs_RefItem_s* x, int dup_strs);
void zx_DUP_STRS_subs_RefItem(struct zx_ctx* c, struct zx_subs_RefItem_s* x);
int zx_WALK_SO_subs_RefItem(struct zx_ctx* c, struct zx_subs_RefItem_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx));
int zx_WALK_WO_subs_RefItem(struct zx_ctx* c, struct zx_subs_RefItem_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx));
#endif
int zx_LEN_SO_subs_RefItem(struct zx_ctx* c, struct zx_subs_RefItem_s* x);
int zx_LEN_WO_subs_RefItem(struct zx_ctx* c, struct zx_subs_RefItem_s* x);
char* zx_ENC_SO_subs_RefItem(struct zx_ctx* c, struct zx_subs_RefItem_s* x, char* p);
char* zx_ENC_WO_subs_RefItem(struct zx_ctx* c, struct zx_subs_RefItem_s* x, char* p);
struct zx_str* zx_EASY_ENC_SO_subs_RefItem(struct zx_ctx* c, struct zx_subs_RefItem_s* x);
struct zx_str* zx_EASY_ENC_WO_subs_RefItem(struct zx_ctx* c, struct zx_subs_RefItem_s* x);

struct zx_subs_RefItem_s {
  ZX_ELEM_EXT
  zx_subs_RefItem_EXT
  struct zx_str* subscriptionID;	/* {0,1} attribute xs:string */
  struct zx_str* itemIDRef;	/* {1,1} attribute lu:IDReferenceType */
};

#ifdef ZX_ENA_GETPUT
struct zx_str* zx_subs_RefItem_GET_subscriptionID(struct zx_subs_RefItem_s* x);
struct zx_str* zx_subs_RefItem_GET_itemIDRef(struct zx_subs_RefItem_s* x);





void zx_subs_RefItem_PUT_subscriptionID(struct zx_subs_RefItem_s* x, struct zx_str* y);
void zx_subs_RefItem_PUT_itemIDRef(struct zx_subs_RefItem_s* x, struct zx_str* y);





#endif

#endif
