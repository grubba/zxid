/* c/zx-paos-data.h - WARNING: This header was automatically generated. DO NOT EDIT!
 * $Id$ */
/* Datastructure design, topography, and layout
 * Copyright (c) 2006 Sampo Kellomaki (sampo@iki.fi),
 * All Rights Reserved. NO WARRANTY. See file COPYING for
 * terms and conditions of use. Element and attributes names as well
 * as some topography are derived from schema descriptions that were used as
 * input and may be subject to their own copright. */

#ifndef _c_zx_paos_data_h
#define _c_zx_paos_data_h

#include "zx.h"
#include "c/zx-const.h"
#include "c/zx-data.h"

#ifndef ZX_ELEM_EXT
#define ZX_ELEM_EXT  /* This extension point should be defined by who includes this file. */
#endif

/* -------------------------- paos_Request -------------------------- */
/* refby( zx_e_Header_s ) */
#ifndef zx_paos_Request_EXT
#define zx_paos_Request_EXT
#endif

struct zx_paos_Request_s* zx_DEC_paos_Request(struct zx_ctx* c, struct zx_ns_s* ns);
struct zx_paos_Request_s* zx_NEW_paos_Request(struct zx_ctx* c);
void zx_FREE_paos_Request(struct zx_ctx* c, struct zx_paos_Request_s* x, int free_strs);
#ifdef ZX_ENA_AUX
struct zx_paos_Request_s* zx_DEEP_CLONE_paos_Request(struct zx_ctx* c, struct zx_paos_Request_s* x, int dup_strs);
void zx_DUP_STRS_paos_Request(struct zx_ctx* c, struct zx_paos_Request_s* x);
int zx_WALK_SO_paos_Request(struct zx_ctx* c, struct zx_paos_Request_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx));
int zx_WALK_WO_paos_Request(struct zx_ctx* c, struct zx_paos_Request_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx));
#endif
int zx_LEN_SO_paos_Request(struct zx_ctx* c, struct zx_paos_Request_s* x);
int zx_LEN_WO_paos_Request(struct zx_ctx* c, struct zx_paos_Request_s* x);
char* zx_ENC_SO_paos_Request(struct zx_ctx* c, struct zx_paos_Request_s* x, char* p);
char* zx_ENC_WO_paos_Request(struct zx_ctx* c, struct zx_paos_Request_s* x, char* p);
struct zx_str* zx_EASY_ENC_SO_paos_Request(struct zx_ctx* c, struct zx_paos_Request_s* x);
struct zx_str* zx_EASY_ENC_WO_paos_Request(struct zx_ctx* c, struct zx_paos_Request_s* x);

struct zx_paos_Request_s {
  ZX_ELEM_EXT
  zx_paos_Request_EXT
  struct zx_str* messageID;	/* {0,1} attribute xs:string */
  struct zx_str* responseConsumerURL;	/* {1,1} attribute xs:anyURI */
  struct zx_str* service;	/* {1,1} attribute xs:anyURI */
  struct zx_str* actor;	/* {1,1} attribute xs:anyURI */
  struct zx_str* mustUnderstand;	/* {1,1} attribute xs:boolean */
};

#ifdef ZX_ENA_GETPUT
struct zx_str* zx_paos_Request_GET_messageID(struct zx_paos_Request_s* x);
struct zx_str* zx_paos_Request_GET_responseConsumerURL(struct zx_paos_Request_s* x);
struct zx_str* zx_paos_Request_GET_service(struct zx_paos_Request_s* x);
struct zx_str* zx_paos_Request_GET_actor(struct zx_paos_Request_s* x);
struct zx_str* zx_paos_Request_GET_mustUnderstand(struct zx_paos_Request_s* x);





void zx_paos_Request_PUT_messageID(struct zx_paos_Request_s* x, struct zx_str* y);
void zx_paos_Request_PUT_responseConsumerURL(struct zx_paos_Request_s* x, struct zx_str* y);
void zx_paos_Request_PUT_service(struct zx_paos_Request_s* x, struct zx_str* y);
void zx_paos_Request_PUT_actor(struct zx_paos_Request_s* x, struct zx_str* y);
void zx_paos_Request_PUT_mustUnderstand(struct zx_paos_Request_s* x, struct zx_str* y);





#endif
/* -------------------------- paos_Response -------------------------- */
/* refby( zx_e_Header_s ) */
#ifndef zx_paos_Response_EXT
#define zx_paos_Response_EXT
#endif

struct zx_paos_Response_s* zx_DEC_paos_Response(struct zx_ctx* c, struct zx_ns_s* ns);
struct zx_paos_Response_s* zx_NEW_paos_Response(struct zx_ctx* c);
void zx_FREE_paos_Response(struct zx_ctx* c, struct zx_paos_Response_s* x, int free_strs);
#ifdef ZX_ENA_AUX
struct zx_paos_Response_s* zx_DEEP_CLONE_paos_Response(struct zx_ctx* c, struct zx_paos_Response_s* x, int dup_strs);
void zx_DUP_STRS_paos_Response(struct zx_ctx* c, struct zx_paos_Response_s* x);
int zx_WALK_SO_paos_Response(struct zx_ctx* c, struct zx_paos_Response_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx));
int zx_WALK_WO_paos_Response(struct zx_ctx* c, struct zx_paos_Response_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx));
#endif
int zx_LEN_SO_paos_Response(struct zx_ctx* c, struct zx_paos_Response_s* x);
int zx_LEN_WO_paos_Response(struct zx_ctx* c, struct zx_paos_Response_s* x);
char* zx_ENC_SO_paos_Response(struct zx_ctx* c, struct zx_paos_Response_s* x, char* p);
char* zx_ENC_WO_paos_Response(struct zx_ctx* c, struct zx_paos_Response_s* x, char* p);
struct zx_str* zx_EASY_ENC_SO_paos_Response(struct zx_ctx* c, struct zx_paos_Response_s* x);
struct zx_str* zx_EASY_ENC_WO_paos_Response(struct zx_ctx* c, struct zx_paos_Response_s* x);

struct zx_paos_Response_s {
  ZX_ELEM_EXT
  zx_paos_Response_EXT
  struct zx_str* refToMessageID;	/* {0,1} attribute xs:string */
  struct zx_str* actor;	/* {1,1} attribute xs:anyURI */
  struct zx_str* mustUnderstand;	/* {1,1} attribute xs:boolean */
};

#ifdef ZX_ENA_GETPUT
struct zx_str* zx_paos_Response_GET_refToMessageID(struct zx_paos_Response_s* x);
struct zx_str* zx_paos_Response_GET_actor(struct zx_paos_Response_s* x);
struct zx_str* zx_paos_Response_GET_mustUnderstand(struct zx_paos_Response_s* x);





void zx_paos_Response_PUT_refToMessageID(struct zx_paos_Response_s* x, struct zx_str* y);
void zx_paos_Response_PUT_actor(struct zx_paos_Response_s* x, struct zx_str* y);
void zx_paos_Response_PUT_mustUnderstand(struct zx_paos_Response_s* x, struct zx_str* y);





#endif

#endif
