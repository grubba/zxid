/* c/zx-sbf-data.h - WARNING: This header was automatically generated. DO NOT EDIT!
 * $Id$ */
/* Datastructure design, topography, and layout
 * Copyright (c) 2006 Sampo Kellomaki (sampo@iki.fi),
 * All Rights Reserved. NO WARRANTY. See file COPYING for
 * terms and conditions of use. Element and attributes names as well
 * as some topography are derived from schema descriptions that were used as
 * input and may be subject to their own copright. */

#ifndef _c_zx_sbf_data_h
#define _c_zx_sbf_data_h

#include "zx.h"
#include "c/zx-const.h"
#include "c/zx-data.h"

#ifndef ZX_ELEM_EXT
#define ZX_ELEM_EXT  /* This extension point should be defined by who includes this file. */
#endif

/* -------------------------- sbf_Framework -------------------------- */
/* refby( zx_di_EndpointContext_s zx_e_Header_s zx_a_Metadata_s ) */
#ifndef zx_sbf_Framework_EXT
#define zx_sbf_Framework_EXT
#endif

struct zx_sbf_Framework_s* zx_DEC_sbf_Framework(struct zx_ctx* c, struct zx_ns_s* ns);
struct zx_sbf_Framework_s* zx_NEW_sbf_Framework(struct zx_ctx* c);
void zx_FREE_sbf_Framework(struct zx_ctx* c, struct zx_sbf_Framework_s* x, int free_strs);
#ifdef ZX_ENA_AUX
struct zx_sbf_Framework_s* zx_DEEP_CLONE_sbf_Framework(struct zx_ctx* c, struct zx_sbf_Framework_s* x, int dup_strs);
void zx_DUP_STRS_sbf_Framework(struct zx_ctx* c, struct zx_sbf_Framework_s* x);
int zx_WALK_SO_sbf_Framework(struct zx_ctx* c, struct zx_sbf_Framework_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx));
int zx_WALK_WO_sbf_Framework(struct zx_ctx* c, struct zx_sbf_Framework_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx));
#endif
int zx_LEN_SO_sbf_Framework(struct zx_ctx* c, struct zx_sbf_Framework_s* x);
int zx_LEN_WO_sbf_Framework(struct zx_ctx* c, struct zx_sbf_Framework_s* x);
char* zx_ENC_SO_sbf_Framework(struct zx_ctx* c, struct zx_sbf_Framework_s* x, char* p);
char* zx_ENC_WO_sbf_Framework(struct zx_ctx* c, struct zx_sbf_Framework_s* x, char* p);
struct zx_str* zx_EASY_ENC_SO_sbf_Framework(struct zx_ctx* c, struct zx_sbf_Framework_s* x);
struct zx_str* zx_EASY_ENC_WO_sbf_Framework(struct zx_ctx* c, struct zx_sbf_Framework_s* x);

struct zx_sbf_Framework_s {
  ZX_ELEM_EXT
  zx_sbf_Framework_EXT
  struct zx_str* version;	/* {1,1} attribute xsd:string */
  struct zx_str* Id;	/* {0,1} attribute xs:ID */
  struct zx_str* actor;	/* {0,1} attribute xs:anyURI */
  struct zx_str* mustUnderstand;	/* {0,1} attribute xs:boolean */
};

#ifdef ZX_ENA_GETPUT
struct zx_str* zx_sbf_Framework_GET_version(struct zx_sbf_Framework_s* x);
struct zx_str* zx_sbf_Framework_GET_Id(struct zx_sbf_Framework_s* x);
struct zx_str* zx_sbf_Framework_GET_actor(struct zx_sbf_Framework_s* x);
struct zx_str* zx_sbf_Framework_GET_mustUnderstand(struct zx_sbf_Framework_s* x);





void zx_sbf_Framework_PUT_version(struct zx_sbf_Framework_s* x, struct zx_str* y);
void zx_sbf_Framework_PUT_Id(struct zx_sbf_Framework_s* x, struct zx_str* y);
void zx_sbf_Framework_PUT_actor(struct zx_sbf_Framework_s* x, struct zx_str* y);
void zx_sbf_Framework_PUT_mustUnderstand(struct zx_sbf_Framework_s* x, struct zx_str* y);





#endif

#endif
