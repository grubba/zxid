/* c/zx-dst-data.h - WARNING: This header was automatically generated. DO NOT EDIT!
 * $Id$ */
/* Datastructure design, topography, and layout
 * Copyright (c) 2006 Sampo Kellomaki (sampo@iki.fi),
 * All Rights Reserved. NO WARRANTY. See file COPYING for
 * terms and conditions of use. Element and attributes names as well
 * as some topography are derived from schema descriptions that were used as
 * input and may be subject to their own copright. */

#ifndef _c_zx_dst_data_h
#define _c_zx_dst_data_h

#include "zx.h"
#include "c/zx-const.h"
#include "c/zx-data.h"

#ifndef ZX_ELEM_EXT
#define ZX_ELEM_EXT  /* This extension point should be defined by who includes this file. */
#endif

/* -------------------------- dst_TestResult -------------------------- */
/* refby( zx_dap_QueryResponse_s zx_idhrxml_QueryResponse_s ) */
#ifndef zx_dst_TestResult_EXT
#define zx_dst_TestResult_EXT
#endif

struct zx_dst_TestResult_s* zx_DEC_dst_TestResult(struct zx_ctx* c, struct zx_ns_s* ns);
struct zx_dst_TestResult_s* zx_NEW_dst_TestResult(struct zx_ctx* c);
void zx_FREE_dst_TestResult(struct zx_ctx* c, struct zx_dst_TestResult_s* x, int free_strs);
#ifdef ZX_ENA_AUX
struct zx_dst_TestResult_s* zx_DEEP_CLONE_dst_TestResult(struct zx_ctx* c, struct zx_dst_TestResult_s* x, int dup_strs);
void zx_DUP_STRS_dst_TestResult(struct zx_ctx* c, struct zx_dst_TestResult_s* x);
int zx_WALK_SO_dst_TestResult(struct zx_ctx* c, struct zx_dst_TestResult_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx));
int zx_WALK_WO_dst_TestResult(struct zx_ctx* c, struct zx_dst_TestResult_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx));
#endif
int zx_LEN_SO_dst_TestResult(struct zx_ctx* c, struct zx_dst_TestResult_s* x);
int zx_LEN_WO_dst_TestResult(struct zx_ctx* c, struct zx_dst_TestResult_s* x);
char* zx_ENC_SO_dst_TestResult(struct zx_ctx* c, struct zx_dst_TestResult_s* x, char* p);
char* zx_ENC_WO_dst_TestResult(struct zx_ctx* c, struct zx_dst_TestResult_s* x, char* p);
struct zx_str* zx_EASY_ENC_SO_dst_TestResult(struct zx_ctx* c, struct zx_dst_TestResult_s* x);
struct zx_str* zx_EASY_ENC_WO_dst_TestResult(struct zx_ctx* c, struct zx_dst_TestResult_s* x);

struct zx_dst_TestResult_s {
  ZX_ELEM_EXT
  zx_dst_TestResult_EXT
  struct zx_str* itemIDRef;	/* {1,1} attribute lu:IDReferenceType */
};

#ifdef ZX_ENA_GETPUT
struct zx_str* zx_dst_TestResult_GET_itemIDRef(struct zx_dst_TestResult_s* x);





void zx_dst_TestResult_PUT_itemIDRef(struct zx_dst_TestResult_s* x, struct zx_str* y);





#endif

#endif
