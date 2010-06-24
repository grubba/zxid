/* c/zx-idpdisc-data.h - WARNING: This header was automatically generated. DO NOT EDIT!
 * $Id$ */
/* Datastructure design, topography, and layout
 * Copyright (c) 2006 Sampo Kellomaki (sampo@iki.fi),
 * All Rights Reserved. NO WARRANTY. See file COPYING for
 * terms and conditions of use. Element and attributes names as well
 * as some topography are derived from schema descriptions that were used as
 * input and may be subject to their own copright. */

#ifndef _c_zx_idpdisc_data_h
#define _c_zx_idpdisc_data_h

#include "zx.h"
#include "c/zx-const.h"
#include "c/zx-data.h"

#ifndef ZX_ELEM_EXT
#define ZX_ELEM_EXT  /* This extension point should be defined by who includes this file. */
#endif

/* -------------------------- idpdisc_DiscoveryResponse -------------------------- */
/* refby( zx_md_Extensions_s ) */
#ifndef zx_idpdisc_DiscoveryResponse_EXT
#define zx_idpdisc_DiscoveryResponse_EXT
#endif

struct zx_idpdisc_DiscoveryResponse_s* zx_DEC_idpdisc_DiscoveryResponse(struct zx_ctx* c, struct zx_ns_s* ns);
struct zx_idpdisc_DiscoveryResponse_s* zx_NEW_idpdisc_DiscoveryResponse(struct zx_ctx* c);
void zx_FREE_idpdisc_DiscoveryResponse(struct zx_ctx* c, struct zx_idpdisc_DiscoveryResponse_s* x, int free_strs);
#ifdef ZX_ENA_AUX
struct zx_idpdisc_DiscoveryResponse_s* zx_DEEP_CLONE_idpdisc_DiscoveryResponse(struct zx_ctx* c, struct zx_idpdisc_DiscoveryResponse_s* x, int dup_strs);
void zx_DUP_STRS_idpdisc_DiscoveryResponse(struct zx_ctx* c, struct zx_idpdisc_DiscoveryResponse_s* x);
int zx_WALK_SO_idpdisc_DiscoveryResponse(struct zx_ctx* c, struct zx_idpdisc_DiscoveryResponse_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx));
int zx_WALK_WO_idpdisc_DiscoveryResponse(struct zx_ctx* c, struct zx_idpdisc_DiscoveryResponse_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx));
#endif
int zx_LEN_SO_idpdisc_DiscoveryResponse(struct zx_ctx* c, struct zx_idpdisc_DiscoveryResponse_s* x);
int zx_LEN_WO_idpdisc_DiscoveryResponse(struct zx_ctx* c, struct zx_idpdisc_DiscoveryResponse_s* x);
char* zx_ENC_SO_idpdisc_DiscoveryResponse(struct zx_ctx* c, struct zx_idpdisc_DiscoveryResponse_s* x, char* p);
char* zx_ENC_WO_idpdisc_DiscoveryResponse(struct zx_ctx* c, struct zx_idpdisc_DiscoveryResponse_s* x, char* p);
struct zx_str* zx_EASY_ENC_SO_idpdisc_DiscoveryResponse(struct zx_ctx* c, struct zx_idpdisc_DiscoveryResponse_s* x);
struct zx_str* zx_EASY_ENC_WO_idpdisc_DiscoveryResponse(struct zx_ctx* c, struct zx_idpdisc_DiscoveryResponse_s* x);

struct zx_idpdisc_DiscoveryResponse_s {
  ZX_ELEM_EXT
  zx_idpdisc_DiscoveryResponse_EXT
  struct zx_str* Binding;	/* {1,1} attribute xs:anyURI */
  struct zx_str* Location;	/* {1,1} attribute xs:anyURI */
  struct zx_str* ResponseLocation;	/* {0,1} attribute xs:anyURI */
  struct zx_str* index;	/* {0,1} attribute xs:unsignedShort */
  struct zx_str* isDefault;	/* {0,1} attribute xs:boolean */
};

#ifdef ZX_ENA_GETPUT
struct zx_str* zx_idpdisc_DiscoveryResponse_GET_Binding(struct zx_idpdisc_DiscoveryResponse_s* x);
struct zx_str* zx_idpdisc_DiscoveryResponse_GET_Location(struct zx_idpdisc_DiscoveryResponse_s* x);
struct zx_str* zx_idpdisc_DiscoveryResponse_GET_ResponseLocation(struct zx_idpdisc_DiscoveryResponse_s* x);
struct zx_str* zx_idpdisc_DiscoveryResponse_GET_index(struct zx_idpdisc_DiscoveryResponse_s* x);
struct zx_str* zx_idpdisc_DiscoveryResponse_GET_isDefault(struct zx_idpdisc_DiscoveryResponse_s* x);





void zx_idpdisc_DiscoveryResponse_PUT_Binding(struct zx_idpdisc_DiscoveryResponse_s* x, struct zx_str* y);
void zx_idpdisc_DiscoveryResponse_PUT_Location(struct zx_idpdisc_DiscoveryResponse_s* x, struct zx_str* y);
void zx_idpdisc_DiscoveryResponse_PUT_ResponseLocation(struct zx_idpdisc_DiscoveryResponse_s* x, struct zx_str* y);
void zx_idpdisc_DiscoveryResponse_PUT_index(struct zx_idpdisc_DiscoveryResponse_s* x, struct zx_str* y);
void zx_idpdisc_DiscoveryResponse_PUT_isDefault(struct zx_idpdisc_DiscoveryResponse_s* x, struct zx_str* y);





#endif

#endif
