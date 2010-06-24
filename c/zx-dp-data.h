/* c/zx-dp-data.h - WARNING: This header was automatically generated. DO NOT EDIT!
 * $Id$ */
/* Datastructure design, topography, and layout
 * Copyright (c) 2006 Sampo Kellomaki (sampo@iki.fi),
 * All Rights Reserved. NO WARRANTY. See file COPYING for
 * terms and conditions of use. Element and attributes names as well
 * as some topography are derived from schema descriptions that were used as
 * input and may be subject to their own copright. */

#ifndef _c_zx_dp_data_h
#define _c_zx_dp_data_h

#include "zx.h"
#include "c/zx-const.h"
#include "c/zx-data.h"

#ifndef ZX_ELEM_EXT
#define ZX_ELEM_EXT  /* This extension point should be defined by who includes this file. */
#endif

/* -------------------------- dp_Request -------------------------- */
/* refby( zx_shps_PollResponse_s zx_prov_PollResponse_s ) */
#ifndef zx_dp_Request_EXT
#define zx_dp_Request_EXT
#endif

struct zx_dp_Request_s* zx_DEC_dp_Request(struct zx_ctx* c, struct zx_ns_s* ns);
struct zx_dp_Request_s* zx_NEW_dp_Request(struct zx_ctx* c);
void zx_FREE_dp_Request(struct zx_ctx* c, struct zx_dp_Request_s* x, int free_strs);
#ifdef ZX_ENA_AUX
struct zx_dp_Request_s* zx_DEEP_CLONE_dp_Request(struct zx_ctx* c, struct zx_dp_Request_s* x, int dup_strs);
void zx_DUP_STRS_dp_Request(struct zx_ctx* c, struct zx_dp_Request_s* x);
int zx_WALK_SO_dp_Request(struct zx_ctx* c, struct zx_dp_Request_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx));
int zx_WALK_WO_dp_Request(struct zx_ctx* c, struct zx_dp_Request_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx));
#endif
int zx_LEN_SO_dp_Request(struct zx_ctx* c, struct zx_dp_Request_s* x);
int zx_LEN_WO_dp_Request(struct zx_ctx* c, struct zx_dp_Request_s* x);
char* zx_ENC_SO_dp_Request(struct zx_ctx* c, struct zx_dp_Request_s* x, char* p);
char* zx_ENC_WO_dp_Request(struct zx_ctx* c, struct zx_dp_Request_s* x, char* p);
struct zx_str* zx_EASY_ENC_SO_dp_Request(struct zx_ctx* c, struct zx_dp_Request_s* x);
struct zx_str* zx_EASY_ENC_WO_dp_Request(struct zx_ctx* c, struct zx_dp_Request_s* x);

struct zx_dp_Request_s {
  ZX_ELEM_EXT
  zx_dp_Request_EXT
  struct zx_str* itemID;	/* {1,1} attribute xs:string */
};

#ifdef ZX_ENA_GETPUT
struct zx_str* zx_dp_Request_GET_itemID(struct zx_dp_Request_s* x);





void zx_dp_Request_PUT_itemID(struct zx_dp_Request_s* x, struct zx_str* y);





#endif
/* -------------------------- dp_Response -------------------------- */
/* refby( zx_shps_Poll_s zx_prov_Poll_s ) */
#ifndef zx_dp_Response_EXT
#define zx_dp_Response_EXT
#endif

struct zx_dp_Response_s* zx_DEC_dp_Response(struct zx_ctx* c, struct zx_ns_s* ns);
struct zx_dp_Response_s* zx_NEW_dp_Response(struct zx_ctx* c);
void zx_FREE_dp_Response(struct zx_ctx* c, struct zx_dp_Response_s* x, int free_strs);
#ifdef ZX_ENA_AUX
struct zx_dp_Response_s* zx_DEEP_CLONE_dp_Response(struct zx_ctx* c, struct zx_dp_Response_s* x, int dup_strs);
void zx_DUP_STRS_dp_Response(struct zx_ctx* c, struct zx_dp_Response_s* x);
int zx_WALK_SO_dp_Response(struct zx_ctx* c, struct zx_dp_Response_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx));
int zx_WALK_WO_dp_Response(struct zx_ctx* c, struct zx_dp_Response_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx));
#endif
int zx_LEN_SO_dp_Response(struct zx_ctx* c, struct zx_dp_Response_s* x);
int zx_LEN_WO_dp_Response(struct zx_ctx* c, struct zx_dp_Response_s* x);
char* zx_ENC_SO_dp_Response(struct zx_ctx* c, struct zx_dp_Response_s* x, char* p);
char* zx_ENC_WO_dp_Response(struct zx_ctx* c, struct zx_dp_Response_s* x, char* p);
struct zx_str* zx_EASY_ENC_SO_dp_Response(struct zx_ctx* c, struct zx_dp_Response_s* x);
struct zx_str* zx_EASY_ENC_WO_dp_Response(struct zx_ctx* c, struct zx_dp_Response_s* x);

struct zx_dp_Response_s {
  ZX_ELEM_EXT
  zx_dp_Response_EXT
  struct zx_str* ref;	/* {1,1} attribute xs:anyURI */
};

#ifdef ZX_ENA_GETPUT
struct zx_str* zx_dp_Response_GET_ref(struct zx_dp_Response_s* x);





void zx_dp_Response_PUT_ref(struct zx_dp_Response_s* x, struct zx_str* y);





#endif

#endif
