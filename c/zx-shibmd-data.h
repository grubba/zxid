/* c/zx-shibmd-data.h - WARNING: This header was automatically generated. DO NOT EDIT!
 * $Id$ */
/* Datastructure design, topography, and layout
 * Copyright (c) 2006 Sampo Kellomaki (sampo@iki.fi),
 * All Rights Reserved. NO WARRANTY. See file COPYING for
 * terms and conditions of use. Element and attributes names as well
 * as some topography are derived from schema descriptions that were used as
 * input and may be subject to their own copright. */

#ifndef _c_zx_shibmd_data_h
#define _c_zx_shibmd_data_h

#include "zx.h"
#include "c/zx-const.h"
#include "c/zx-data.h"

#ifndef ZX_ELEM_EXT
#define ZX_ELEM_EXT  /* This extension point should be defined by who includes this file. */
#endif

/* -------------------------- shibmd_KeyAuthority -------------------------- */
/* refby( zx_md_Extensions_s ) */
#ifndef zx_shibmd_KeyAuthority_EXT
#define zx_shibmd_KeyAuthority_EXT
#endif

struct zx_shibmd_KeyAuthority_s* zx_DEC_shibmd_KeyAuthority(struct zx_ctx* c, struct zx_ns_s* ns);
struct zx_shibmd_KeyAuthority_s* zx_NEW_shibmd_KeyAuthority(struct zx_ctx* c);
void zx_FREE_shibmd_KeyAuthority(struct zx_ctx* c, struct zx_shibmd_KeyAuthority_s* x, int free_strs);
#ifdef ZX_ENA_AUX
struct zx_shibmd_KeyAuthority_s* zx_DEEP_CLONE_shibmd_KeyAuthority(struct zx_ctx* c, struct zx_shibmd_KeyAuthority_s* x, int dup_strs);
void zx_DUP_STRS_shibmd_KeyAuthority(struct zx_ctx* c, struct zx_shibmd_KeyAuthority_s* x);
int zx_WALK_SO_shibmd_KeyAuthority(struct zx_ctx* c, struct zx_shibmd_KeyAuthority_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx));
int zx_WALK_WO_shibmd_KeyAuthority(struct zx_ctx* c, struct zx_shibmd_KeyAuthority_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx));
#endif
int zx_LEN_SO_shibmd_KeyAuthority(struct zx_ctx* c, struct zx_shibmd_KeyAuthority_s* x);
int zx_LEN_WO_shibmd_KeyAuthority(struct zx_ctx* c, struct zx_shibmd_KeyAuthority_s* x);
char* zx_ENC_SO_shibmd_KeyAuthority(struct zx_ctx* c, struct zx_shibmd_KeyAuthority_s* x, char* p);
char* zx_ENC_WO_shibmd_KeyAuthority(struct zx_ctx* c, struct zx_shibmd_KeyAuthority_s* x, char* p);
struct zx_str* zx_EASY_ENC_SO_shibmd_KeyAuthority(struct zx_ctx* c, struct zx_shibmd_KeyAuthority_s* x);
struct zx_str* zx_EASY_ENC_WO_shibmd_KeyAuthority(struct zx_ctx* c, struct zx_shibmd_KeyAuthority_s* x);

struct zx_shibmd_KeyAuthority_s {
  ZX_ELEM_EXT
  zx_shibmd_KeyAuthority_EXT
  struct zx_ds_KeyInfo_s* KeyInfo;	/* {1,-1} nada */
  struct zx_str* VerifyDepth;	/* {0,1} attribute xs:unsignedByte */
};

#ifdef ZX_ENA_GETPUT
struct zx_str* zx_shibmd_KeyAuthority_GET_VerifyDepth(struct zx_shibmd_KeyAuthority_s* x);

struct zx_ds_KeyInfo_s* zx_shibmd_KeyAuthority_GET_KeyInfo(struct zx_shibmd_KeyAuthority_s* x, int n);

int zx_shibmd_KeyAuthority_NUM_KeyInfo(struct zx_shibmd_KeyAuthority_s* x);

struct zx_ds_KeyInfo_s* zx_shibmd_KeyAuthority_POP_KeyInfo(struct zx_shibmd_KeyAuthority_s* x);

void zx_shibmd_KeyAuthority_PUSH_KeyInfo(struct zx_shibmd_KeyAuthority_s* x, struct zx_ds_KeyInfo_s* y);

void zx_shibmd_KeyAuthority_PUT_VerifyDepth(struct zx_shibmd_KeyAuthority_s* x, struct zx_str* y);

void zx_shibmd_KeyAuthority_PUT_KeyInfo(struct zx_shibmd_KeyAuthority_s* x, int n, struct zx_ds_KeyInfo_s* y);

void zx_shibmd_KeyAuthority_ADD_KeyInfo(struct zx_shibmd_KeyAuthority_s* x, int n, struct zx_ds_KeyInfo_s* z);

void zx_shibmd_KeyAuthority_DEL_KeyInfo(struct zx_shibmd_KeyAuthority_s* x, int n);

void zx_shibmd_KeyAuthority_REV_KeyInfo(struct zx_shibmd_KeyAuthority_s* x);

#endif
/* -------------------------- shibmd_Scope -------------------------- */
/* refby( zx_md_Extensions_s ) */
#ifndef zx_shibmd_Scope_EXT
#define zx_shibmd_Scope_EXT
#endif

struct zx_shibmd_Scope_s* zx_DEC_shibmd_Scope(struct zx_ctx* c, struct zx_ns_s* ns);
struct zx_shibmd_Scope_s* zx_NEW_shibmd_Scope(struct zx_ctx* c);
void zx_FREE_shibmd_Scope(struct zx_ctx* c, struct zx_shibmd_Scope_s* x, int free_strs);
#ifdef ZX_ENA_AUX
struct zx_shibmd_Scope_s* zx_DEEP_CLONE_shibmd_Scope(struct zx_ctx* c, struct zx_shibmd_Scope_s* x, int dup_strs);
void zx_DUP_STRS_shibmd_Scope(struct zx_ctx* c, struct zx_shibmd_Scope_s* x);
int zx_WALK_SO_shibmd_Scope(struct zx_ctx* c, struct zx_shibmd_Scope_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx));
int zx_WALK_WO_shibmd_Scope(struct zx_ctx* c, struct zx_shibmd_Scope_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx));
#endif
int zx_LEN_SO_shibmd_Scope(struct zx_ctx* c, struct zx_shibmd_Scope_s* x);
int zx_LEN_WO_shibmd_Scope(struct zx_ctx* c, struct zx_shibmd_Scope_s* x);
char* zx_ENC_SO_shibmd_Scope(struct zx_ctx* c, struct zx_shibmd_Scope_s* x, char* p);
char* zx_ENC_WO_shibmd_Scope(struct zx_ctx* c, struct zx_shibmd_Scope_s* x, char* p);
struct zx_str* zx_EASY_ENC_SO_shibmd_Scope(struct zx_ctx* c, struct zx_shibmd_Scope_s* x);
struct zx_str* zx_EASY_ENC_WO_shibmd_Scope(struct zx_ctx* c, struct zx_shibmd_Scope_s* x);

struct zx_shibmd_Scope_s {
  ZX_ELEM_EXT
  zx_shibmd_Scope_EXT
  struct zx_str* regexp;	/* {0,1} attribute xs:boolean */
};

#ifdef ZX_ENA_GETPUT
struct zx_str* zx_shibmd_Scope_GET_regexp(struct zx_shibmd_Scope_s* x);





void zx_shibmd_Scope_PUT_regexp(struct zx_shibmd_Scope_s* x, struct zx_str* y);





#endif

#endif
