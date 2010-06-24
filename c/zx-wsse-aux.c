/* c/zx-wsse-aux.c - WARNING: This file was automatically generated. DO NOT EDIT!
 * $Id$ */
/* Code generation design Copyright (c) 2006 Sampo Kellomaki (sampo@iki.fi),
 * All Rights Reserved. NO WARRANTY. See file COPYING for terms and conditions
 * of use. Some aspects of code generation were driven by schema
 * descriptions that were used as input and may be subject to their own copyright.
 * Code generation uses a template, whose copyright statement follows. */

/** aux-templ.c  -  Auxiliary functions template: cloning, freeing, walking data
 ** Copyright (c) 2006 Symlabs (symlabs@symlabs.com), All Rights Reserved.
 ** Author: Sampo Kellomaki (sampo@iki.fi)
 ** This is confidential unpublished proprietary source code of the author.
 ** NO WARRANTY, not even implied warranties. Contains trade secrets.
 ** Distribution prohibited unless authorized in writing.
 ** Licensed under Apache License 2.0, see file COPYING.
 ** Id: aux-templ.c,v 1.12 2008-10-04 23:42:14 sampo Exp $
 **
 ** 30.5.2006, created, Sampo Kellomaki (sampo@iki.fi)
 ** 6.8.2006, factored from enc-templ.c to separate file --Sampo
 **
 ** N.B: wo=wire order (needed for exc-c14n), so=schema order
 **/

#include <memory.h>
#include "errmac.h"
#include "zx.h"
#include "c/zx-const.h"
#include "c/zx-data.h"
#include "c/zx-wsse-data.h"



#ifdef EL_NAME
#undef EL_NAME
#endif
#ifdef EL_STRUCT
#undef EL_STRUCT
#endif
#ifdef EL_NS
#undef EL_NS
#endif
#ifdef EL_TAG
#undef EL_TAG
#endif

#define EL_NAME   wsse_BinarySecurityToken
#define EL_STRUCT zx_wsse_BinarySecurityToken_s
#define EL_NS     wsse
#define EL_TAG    BinarySecurityToken

/* FUNC(zx_FREE_wsse_BinarySecurityToken) */

/* Depth first traversal of data structure to free it and its subelements. Simple
 * strings are handled as a special case according to the free_strs flag. This
 * is useful if the strings point to underlying data from the wire that was
 * allocated differently. */

/* Called by: */
void zx_FREE_wsse_BinarySecurityToken(struct zx_ctx* c, struct zx_wsse_BinarySecurityToken_s* x, int free_strs)
{
  /* *** deal with xmlns specifications in exc c14n way */

  zx_free_attr(c, x->EncodingType, free_strs);
  zx_free_attr(c, x->ValueType, free_strs);
  zx_free_attr(c, x->Id, free_strs);



  zx_free_elem_common(c, &x->gg, free_strs); 
}

/* FUNC(zx_NEW_wsse_BinarySecurityToken) */

/* Trivial allocator/constructor for the datatype. */

/* Called by: */
struct zx_wsse_BinarySecurityToken_s* zx_NEW_wsse_BinarySecurityToken(struct zx_ctx* c)
{
  struct zx_wsse_BinarySecurityToken_s* x = ZX_ZALLOC(c, struct zx_wsse_BinarySecurityToken_s);
  x->gg.g.tok = zx_wsse_BinarySecurityToken_ELEM;
  return x;
}

#ifdef ZX_ENA_AUX

/* FUNC(zx_DUP_STRS_wsse_BinarySecurityToken) */

/* Depth first traversal of data structure to copy its simple strings
 * to memory allocated from the memory allocator. The decoder will
 * use the underlying wireprotocol PDU buffer for strings, i.e.
 * strings are not copied - they point to the real data. If the
 * datastructure needs to outlast the protocol data or needs a different
 * memory allocation strategy, you need to call this function.  */

/* Called by: */
void zx_DUP_STRS_wsse_BinarySecurityToken(struct zx_ctx* c, struct zx_wsse_BinarySecurityToken_s* x)
{
  zx_dup_strs_common(c, &x->gg);
  /* *** deal with xmlns specifications in exc c14n way */

  zx_dup_attr(c, x->EncodingType);
  zx_dup_attr(c, x->ValueType);
  zx_dup_attr(c, x->Id);


}

/* FUNC(zx_DEEP_CLONE_wsse_BinarySecurityToken) */

/* Depth first traversal of data structure to clone it and its sublements.
 * The simple strings are handled as a special case according to dup_strs flag. */

/* Called by: */
struct zx_wsse_BinarySecurityToken_s* zx_DEEP_CLONE_wsse_BinarySecurityToken(struct zx_ctx* c, struct zx_wsse_BinarySecurityToken_s* x, int dup_strs)
{
  x = (struct zx_wsse_BinarySecurityToken_s*)zx_clone_elem_common(c, &x->gg, sizeof(struct zx_wsse_BinarySecurityToken_s), dup_strs);
  /* *** deal with xmlns specifications in exc c14n way */

  x->EncodingType = zx_clone_attr(c, x->EncodingType);
  x->ValueType = zx_clone_attr(c, x->ValueType);
  x->Id = zx_clone_attr(c, x->Id);


  return x;
}

/* FUNC(zx_WALK_SO_wsse_BinarySecurityToken) */

/* Depth first traversal of the tree in either schema order or the wire order. */
 
int zx_WALK_SO_wsse_BinarySecurityToken(struct zx_ctx* c, struct zx_wsse_BinarySecurityToken_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
{
  int ret = callback(&x->gg.g, ctx);
  if (ret)
    return ret;
  
  /* *** deal with xmlns specifications in exc c14n way */


  
  ret = zx_walk_so_unknown_attributes(c, &x->gg, ctx, callback); 
  if (ret)
    return ret;


  
  return zx_walk_so_unknown_elems_and_content(c, &x->gg, ctx, callback);
}

/* FUNC(zx_WALK_WO_wsse_BinarySecurityToken) */

int zx_WALK_WO_wsse_BinarySecurityToken(struct zx_ctx* c, struct zx_wsse_BinarySecurityToken_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
{
  ERR("*** walk_wo not implemented %d", 0);
  return 0;
}

#endif




#ifdef EL_NAME
#undef EL_NAME
#endif
#ifdef EL_STRUCT
#undef EL_STRUCT
#endif
#ifdef EL_NS
#undef EL_NS
#endif
#ifdef EL_TAG
#undef EL_TAG
#endif

#define EL_NAME   wsse_Embedded
#define EL_STRUCT zx_wsse_Embedded_s
#define EL_NS     wsse
#define EL_TAG    Embedded

/* FUNC(zx_FREE_wsse_Embedded) */

/* Depth first traversal of data structure to free it and its subelements. Simple
 * strings are handled as a special case according to the free_strs flag. This
 * is useful if the strings point to underlying data from the wire that was
 * allocated differently. */

/* Called by: */
void zx_FREE_wsse_Embedded(struct zx_ctx* c, struct zx_wsse_Embedded_s* x, int free_strs)
{
  /* *** deal with xmlns specifications in exc c14n way */

  zx_free_attr(c, x->ValueType, free_strs);



  zx_free_elem_common(c, &x->gg, free_strs); 
}

/* FUNC(zx_NEW_wsse_Embedded) */

/* Trivial allocator/constructor for the datatype. */

/* Called by: */
struct zx_wsse_Embedded_s* zx_NEW_wsse_Embedded(struct zx_ctx* c)
{
  struct zx_wsse_Embedded_s* x = ZX_ZALLOC(c, struct zx_wsse_Embedded_s);
  x->gg.g.tok = zx_wsse_Embedded_ELEM;
  return x;
}

#ifdef ZX_ENA_AUX

/* FUNC(zx_DUP_STRS_wsse_Embedded) */

/* Depth first traversal of data structure to copy its simple strings
 * to memory allocated from the memory allocator. The decoder will
 * use the underlying wireprotocol PDU buffer for strings, i.e.
 * strings are not copied - they point to the real data. If the
 * datastructure needs to outlast the protocol data or needs a different
 * memory allocation strategy, you need to call this function.  */

/* Called by: */
void zx_DUP_STRS_wsse_Embedded(struct zx_ctx* c, struct zx_wsse_Embedded_s* x)
{
  zx_dup_strs_common(c, &x->gg);
  /* *** deal with xmlns specifications in exc c14n way */

  zx_dup_attr(c, x->ValueType);


}

/* FUNC(zx_DEEP_CLONE_wsse_Embedded) */

/* Depth first traversal of data structure to clone it and its sublements.
 * The simple strings are handled as a special case according to dup_strs flag. */

/* Called by: */
struct zx_wsse_Embedded_s* zx_DEEP_CLONE_wsse_Embedded(struct zx_ctx* c, struct zx_wsse_Embedded_s* x, int dup_strs)
{
  x = (struct zx_wsse_Embedded_s*)zx_clone_elem_common(c, &x->gg, sizeof(struct zx_wsse_Embedded_s), dup_strs);
  /* *** deal with xmlns specifications in exc c14n way */

  x->ValueType = zx_clone_attr(c, x->ValueType);


  return x;
}

/* FUNC(zx_WALK_SO_wsse_Embedded) */

/* Depth first traversal of the tree in either schema order or the wire order. */
 
int zx_WALK_SO_wsse_Embedded(struct zx_ctx* c, struct zx_wsse_Embedded_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
{
  int ret = callback(&x->gg.g, ctx);
  if (ret)
    return ret;
  
  /* *** deal with xmlns specifications in exc c14n way */


  
  ret = zx_walk_so_unknown_attributes(c, &x->gg, ctx, callback); 
  if (ret)
    return ret;


  
  return zx_walk_so_unknown_elems_and_content(c, &x->gg, ctx, callback);
}

/* FUNC(zx_WALK_WO_wsse_Embedded) */

int zx_WALK_WO_wsse_Embedded(struct zx_ctx* c, struct zx_wsse_Embedded_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
{
  ERR("*** walk_wo not implemented %d", 0);
  return 0;
}

#endif




#ifdef EL_NAME
#undef EL_NAME
#endif
#ifdef EL_STRUCT
#undef EL_STRUCT
#endif
#ifdef EL_NS
#undef EL_NS
#endif
#ifdef EL_TAG
#undef EL_TAG
#endif

#define EL_NAME   wsse_KeyIdentifier
#define EL_STRUCT zx_wsse_KeyIdentifier_s
#define EL_NS     wsse
#define EL_TAG    KeyIdentifier

/* FUNC(zx_FREE_wsse_KeyIdentifier) */

/* Depth first traversal of data structure to free it and its subelements. Simple
 * strings are handled as a special case according to the free_strs flag. This
 * is useful if the strings point to underlying data from the wire that was
 * allocated differently. */

/* Called by: */
void zx_FREE_wsse_KeyIdentifier(struct zx_ctx* c, struct zx_wsse_KeyIdentifier_s* x, int free_strs)
{
  /* *** deal with xmlns specifications in exc c14n way */

  zx_free_attr(c, x->EncodingType, free_strs);
  zx_free_attr(c, x->ValueType, free_strs);
  zx_free_attr(c, x->Id, free_strs);



  zx_free_elem_common(c, &x->gg, free_strs); 
}

/* FUNC(zx_NEW_wsse_KeyIdentifier) */

/* Trivial allocator/constructor for the datatype. */

/* Called by: */
struct zx_wsse_KeyIdentifier_s* zx_NEW_wsse_KeyIdentifier(struct zx_ctx* c)
{
  struct zx_wsse_KeyIdentifier_s* x = ZX_ZALLOC(c, struct zx_wsse_KeyIdentifier_s);
  x->gg.g.tok = zx_wsse_KeyIdentifier_ELEM;
  return x;
}

#ifdef ZX_ENA_AUX

/* FUNC(zx_DUP_STRS_wsse_KeyIdentifier) */

/* Depth first traversal of data structure to copy its simple strings
 * to memory allocated from the memory allocator. The decoder will
 * use the underlying wireprotocol PDU buffer for strings, i.e.
 * strings are not copied - they point to the real data. If the
 * datastructure needs to outlast the protocol data or needs a different
 * memory allocation strategy, you need to call this function.  */

/* Called by: */
void zx_DUP_STRS_wsse_KeyIdentifier(struct zx_ctx* c, struct zx_wsse_KeyIdentifier_s* x)
{
  zx_dup_strs_common(c, &x->gg);
  /* *** deal with xmlns specifications in exc c14n way */

  zx_dup_attr(c, x->EncodingType);
  zx_dup_attr(c, x->ValueType);
  zx_dup_attr(c, x->Id);


}

/* FUNC(zx_DEEP_CLONE_wsse_KeyIdentifier) */

/* Depth first traversal of data structure to clone it and its sublements.
 * The simple strings are handled as a special case according to dup_strs flag. */

/* Called by: */
struct zx_wsse_KeyIdentifier_s* zx_DEEP_CLONE_wsse_KeyIdentifier(struct zx_ctx* c, struct zx_wsse_KeyIdentifier_s* x, int dup_strs)
{
  x = (struct zx_wsse_KeyIdentifier_s*)zx_clone_elem_common(c, &x->gg, sizeof(struct zx_wsse_KeyIdentifier_s), dup_strs);
  /* *** deal with xmlns specifications in exc c14n way */

  x->EncodingType = zx_clone_attr(c, x->EncodingType);
  x->ValueType = zx_clone_attr(c, x->ValueType);
  x->Id = zx_clone_attr(c, x->Id);


  return x;
}

/* FUNC(zx_WALK_SO_wsse_KeyIdentifier) */

/* Depth first traversal of the tree in either schema order or the wire order. */
 
int zx_WALK_SO_wsse_KeyIdentifier(struct zx_ctx* c, struct zx_wsse_KeyIdentifier_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
{
  int ret = callback(&x->gg.g, ctx);
  if (ret)
    return ret;
  
  /* *** deal with xmlns specifications in exc c14n way */


  
  ret = zx_walk_so_unknown_attributes(c, &x->gg, ctx, callback); 
  if (ret)
    return ret;


  
  return zx_walk_so_unknown_elems_and_content(c, &x->gg, ctx, callback);
}

/* FUNC(zx_WALK_WO_wsse_KeyIdentifier) */

int zx_WALK_WO_wsse_KeyIdentifier(struct zx_ctx* c, struct zx_wsse_KeyIdentifier_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
{
  ERR("*** walk_wo not implemented %d", 0);
  return 0;
}

#endif




#ifdef EL_NAME
#undef EL_NAME
#endif
#ifdef EL_STRUCT
#undef EL_STRUCT
#endif
#ifdef EL_NS
#undef EL_NS
#endif
#ifdef EL_TAG
#undef EL_TAG
#endif

#define EL_NAME   wsse_Nonce
#define EL_STRUCT zx_wsse_Nonce_s
#define EL_NS     wsse
#define EL_TAG    Nonce

/* FUNC(zx_FREE_wsse_Nonce) */

/* Depth first traversal of data structure to free it and its subelements. Simple
 * strings are handled as a special case according to the free_strs flag. This
 * is useful if the strings point to underlying data from the wire that was
 * allocated differently. */

/* Called by: */
void zx_FREE_wsse_Nonce(struct zx_ctx* c, struct zx_wsse_Nonce_s* x, int free_strs)
{
  /* *** deal with xmlns specifications in exc c14n way */

  zx_free_attr(c, x->EncodingType, free_strs);
  zx_free_attr(c, x->Id, free_strs);



  zx_free_elem_common(c, &x->gg, free_strs); 
}

/* FUNC(zx_NEW_wsse_Nonce) */

/* Trivial allocator/constructor for the datatype. */

/* Called by: */
struct zx_wsse_Nonce_s* zx_NEW_wsse_Nonce(struct zx_ctx* c)
{
  struct zx_wsse_Nonce_s* x = ZX_ZALLOC(c, struct zx_wsse_Nonce_s);
  x->gg.g.tok = zx_wsse_Nonce_ELEM;
  return x;
}

#ifdef ZX_ENA_AUX

/* FUNC(zx_DUP_STRS_wsse_Nonce) */

/* Depth first traversal of data structure to copy its simple strings
 * to memory allocated from the memory allocator. The decoder will
 * use the underlying wireprotocol PDU buffer for strings, i.e.
 * strings are not copied - they point to the real data. If the
 * datastructure needs to outlast the protocol data or needs a different
 * memory allocation strategy, you need to call this function.  */

/* Called by: */
void zx_DUP_STRS_wsse_Nonce(struct zx_ctx* c, struct zx_wsse_Nonce_s* x)
{
  zx_dup_strs_common(c, &x->gg);
  /* *** deal with xmlns specifications in exc c14n way */

  zx_dup_attr(c, x->EncodingType);
  zx_dup_attr(c, x->Id);


}

/* FUNC(zx_DEEP_CLONE_wsse_Nonce) */

/* Depth first traversal of data structure to clone it and its sublements.
 * The simple strings are handled as a special case according to dup_strs flag. */

/* Called by: */
struct zx_wsse_Nonce_s* zx_DEEP_CLONE_wsse_Nonce(struct zx_ctx* c, struct zx_wsse_Nonce_s* x, int dup_strs)
{
  x = (struct zx_wsse_Nonce_s*)zx_clone_elem_common(c, &x->gg, sizeof(struct zx_wsse_Nonce_s), dup_strs);
  /* *** deal with xmlns specifications in exc c14n way */

  x->EncodingType = zx_clone_attr(c, x->EncodingType);
  x->Id = zx_clone_attr(c, x->Id);


  return x;
}

/* FUNC(zx_WALK_SO_wsse_Nonce) */

/* Depth first traversal of the tree in either schema order or the wire order. */
 
int zx_WALK_SO_wsse_Nonce(struct zx_ctx* c, struct zx_wsse_Nonce_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
{
  int ret = callback(&x->gg.g, ctx);
  if (ret)
    return ret;
  
  /* *** deal with xmlns specifications in exc c14n way */


  
  ret = zx_walk_so_unknown_attributes(c, &x->gg, ctx, callback); 
  if (ret)
    return ret;


  
  return zx_walk_so_unknown_elems_and_content(c, &x->gg, ctx, callback);
}

/* FUNC(zx_WALK_WO_wsse_Nonce) */

int zx_WALK_WO_wsse_Nonce(struct zx_ctx* c, struct zx_wsse_Nonce_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
{
  ERR("*** walk_wo not implemented %d", 0);
  return 0;
}

#endif




#ifdef EL_NAME
#undef EL_NAME
#endif
#ifdef EL_STRUCT
#undef EL_STRUCT
#endif
#ifdef EL_NS
#undef EL_NS
#endif
#ifdef EL_TAG
#undef EL_TAG
#endif

#define EL_NAME   wsse_Password
#define EL_STRUCT zx_wsse_Password_s
#define EL_NS     wsse
#define EL_TAG    Password

/* FUNC(zx_FREE_wsse_Password) */

/* Depth first traversal of data structure to free it and its subelements. Simple
 * strings are handled as a special case according to the free_strs flag. This
 * is useful if the strings point to underlying data from the wire that was
 * allocated differently. */

/* Called by: */
void zx_FREE_wsse_Password(struct zx_ctx* c, struct zx_wsse_Password_s* x, int free_strs)
{
  /* *** deal with xmlns specifications in exc c14n way */

  zx_free_attr(c, x->Type, free_strs);
  zx_free_attr(c, x->Id, free_strs);



  zx_free_elem_common(c, &x->gg, free_strs); 
}

/* FUNC(zx_NEW_wsse_Password) */

/* Trivial allocator/constructor for the datatype. */

/* Called by: */
struct zx_wsse_Password_s* zx_NEW_wsse_Password(struct zx_ctx* c)
{
  struct zx_wsse_Password_s* x = ZX_ZALLOC(c, struct zx_wsse_Password_s);
  x->gg.g.tok = zx_wsse_Password_ELEM;
  return x;
}

#ifdef ZX_ENA_AUX

/* FUNC(zx_DUP_STRS_wsse_Password) */

/* Depth first traversal of data structure to copy its simple strings
 * to memory allocated from the memory allocator. The decoder will
 * use the underlying wireprotocol PDU buffer for strings, i.e.
 * strings are not copied - they point to the real data. If the
 * datastructure needs to outlast the protocol data or needs a different
 * memory allocation strategy, you need to call this function.  */

/* Called by: */
void zx_DUP_STRS_wsse_Password(struct zx_ctx* c, struct zx_wsse_Password_s* x)
{
  zx_dup_strs_common(c, &x->gg);
  /* *** deal with xmlns specifications in exc c14n way */

  zx_dup_attr(c, x->Type);
  zx_dup_attr(c, x->Id);


}

/* FUNC(zx_DEEP_CLONE_wsse_Password) */

/* Depth first traversal of data structure to clone it and its sublements.
 * The simple strings are handled as a special case according to dup_strs flag. */

/* Called by: */
struct zx_wsse_Password_s* zx_DEEP_CLONE_wsse_Password(struct zx_ctx* c, struct zx_wsse_Password_s* x, int dup_strs)
{
  x = (struct zx_wsse_Password_s*)zx_clone_elem_common(c, &x->gg, sizeof(struct zx_wsse_Password_s), dup_strs);
  /* *** deal with xmlns specifications in exc c14n way */

  x->Type = zx_clone_attr(c, x->Type);
  x->Id = zx_clone_attr(c, x->Id);


  return x;
}

/* FUNC(zx_WALK_SO_wsse_Password) */

/* Depth first traversal of the tree in either schema order or the wire order. */
 
int zx_WALK_SO_wsse_Password(struct zx_ctx* c, struct zx_wsse_Password_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
{
  int ret = callback(&x->gg.g, ctx);
  if (ret)
    return ret;
  
  /* *** deal with xmlns specifications in exc c14n way */


  
  ret = zx_walk_so_unknown_attributes(c, &x->gg, ctx, callback); 
  if (ret)
    return ret;


  
  return zx_walk_so_unknown_elems_and_content(c, &x->gg, ctx, callback);
}

/* FUNC(zx_WALK_WO_wsse_Password) */

int zx_WALK_WO_wsse_Password(struct zx_ctx* c, struct zx_wsse_Password_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
{
  ERR("*** walk_wo not implemented %d", 0);
  return 0;
}

#endif




#ifdef EL_NAME
#undef EL_NAME
#endif
#ifdef EL_STRUCT
#undef EL_STRUCT
#endif
#ifdef EL_NS
#undef EL_NS
#endif
#ifdef EL_TAG
#undef EL_TAG
#endif

#define EL_NAME   wsse_Reference
#define EL_STRUCT zx_wsse_Reference_s
#define EL_NS     wsse
#define EL_TAG    Reference

/* FUNC(zx_FREE_wsse_Reference) */

/* Depth first traversal of data structure to free it and its subelements. Simple
 * strings are handled as a special case according to the free_strs flag. This
 * is useful if the strings point to underlying data from the wire that was
 * allocated differently. */

/* Called by: */
void zx_FREE_wsse_Reference(struct zx_ctx* c, struct zx_wsse_Reference_s* x, int free_strs)
{
  /* *** deal with xmlns specifications in exc c14n way */

  zx_free_attr(c, x->URI, free_strs);
  zx_free_attr(c, x->ValueType, free_strs);



  zx_free_elem_common(c, &x->gg, free_strs); 
}

/* FUNC(zx_NEW_wsse_Reference) */

/* Trivial allocator/constructor for the datatype. */

/* Called by: */
struct zx_wsse_Reference_s* zx_NEW_wsse_Reference(struct zx_ctx* c)
{
  struct zx_wsse_Reference_s* x = ZX_ZALLOC(c, struct zx_wsse_Reference_s);
  x->gg.g.tok = zx_wsse_Reference_ELEM;
  return x;
}

#ifdef ZX_ENA_AUX

/* FUNC(zx_DUP_STRS_wsse_Reference) */

/* Depth first traversal of data structure to copy its simple strings
 * to memory allocated from the memory allocator. The decoder will
 * use the underlying wireprotocol PDU buffer for strings, i.e.
 * strings are not copied - they point to the real data. If the
 * datastructure needs to outlast the protocol data or needs a different
 * memory allocation strategy, you need to call this function.  */

/* Called by: */
void zx_DUP_STRS_wsse_Reference(struct zx_ctx* c, struct zx_wsse_Reference_s* x)
{
  zx_dup_strs_common(c, &x->gg);
  /* *** deal with xmlns specifications in exc c14n way */

  zx_dup_attr(c, x->URI);
  zx_dup_attr(c, x->ValueType);


}

/* FUNC(zx_DEEP_CLONE_wsse_Reference) */

/* Depth first traversal of data structure to clone it and its sublements.
 * The simple strings are handled as a special case according to dup_strs flag. */

/* Called by: */
struct zx_wsse_Reference_s* zx_DEEP_CLONE_wsse_Reference(struct zx_ctx* c, struct zx_wsse_Reference_s* x, int dup_strs)
{
  x = (struct zx_wsse_Reference_s*)zx_clone_elem_common(c, &x->gg, sizeof(struct zx_wsse_Reference_s), dup_strs);
  /* *** deal with xmlns specifications in exc c14n way */

  x->URI = zx_clone_attr(c, x->URI);
  x->ValueType = zx_clone_attr(c, x->ValueType);


  return x;
}

/* FUNC(zx_WALK_SO_wsse_Reference) */

/* Depth first traversal of the tree in either schema order or the wire order. */
 
int zx_WALK_SO_wsse_Reference(struct zx_ctx* c, struct zx_wsse_Reference_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
{
  int ret = callback(&x->gg.g, ctx);
  if (ret)
    return ret;
  
  /* *** deal with xmlns specifications in exc c14n way */


  
  ret = zx_walk_so_unknown_attributes(c, &x->gg, ctx, callback); 
  if (ret)
    return ret;


  
  return zx_walk_so_unknown_elems_and_content(c, &x->gg, ctx, callback);
}

/* FUNC(zx_WALK_WO_wsse_Reference) */

int zx_WALK_WO_wsse_Reference(struct zx_ctx* c, struct zx_wsse_Reference_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
{
  ERR("*** walk_wo not implemented %d", 0);
  return 0;
}

#endif




#ifdef EL_NAME
#undef EL_NAME
#endif
#ifdef EL_STRUCT
#undef EL_STRUCT
#endif
#ifdef EL_NS
#undef EL_NS
#endif
#ifdef EL_TAG
#undef EL_TAG
#endif

#define EL_NAME   wsse_Security
#define EL_STRUCT zx_wsse_Security_s
#define EL_NS     wsse
#define EL_TAG    Security

/* FUNC(zx_FREE_wsse_Security) */

/* Depth first traversal of data structure to free it and its subelements. Simple
 * strings are handled as a special case according to the free_strs flag. This
 * is useful if the strings point to underlying data from the wire that was
 * allocated differently. */

/* Called by: */
void zx_FREE_wsse_Security(struct zx_ctx* c, struct zx_wsse_Security_s* x, int free_strs)
{
  /* *** deal with xmlns specifications in exc c14n way */

  zx_free_attr(c, x->Id, free_strs);
  zx_free_attr(c, x->actor, free_strs);
  zx_free_attr(c, x->mustUnderstand, free_strs);

  {
      struct zx_ds_Signature_s* e;
      struct zx_ds_Signature_s* en;
      for (e = x->Signature; e; e = en) {
	  en = (struct zx_ds_Signature_s*)e->gg.g.n;
	  zx_FREE_ds_Signature(c, e, free_strs);
      }
  }
  {
      struct zx_sa_Assertion_s* e;
      struct zx_sa_Assertion_s* en;
      for (e = x->Assertion; e; e = en) {
	  en = (struct zx_sa_Assertion_s*)e->gg.g.n;
	  zx_FREE_sa_Assertion(c, e, free_strs);
      }
  }
  {
      struct zx_sa_EncryptedAssertion_s* e;
      struct zx_sa_EncryptedAssertion_s* en;
      for (e = x->EncryptedAssertion; e; e = en) {
	  en = (struct zx_sa_EncryptedAssertion_s*)e->gg.g.n;
	  zx_FREE_sa_EncryptedAssertion(c, e, free_strs);
      }
  }
  {
      struct zx_sa11_Assertion_s* e;
      struct zx_sa11_Assertion_s* en;
      for (e = x->sa11_Assertion; e; e = en) {
	  en = (struct zx_sa11_Assertion_s*)e->gg.g.n;
	  zx_FREE_sa11_Assertion(c, e, free_strs);
      }
  }
  {
      struct zx_ff12_Assertion_s* e;
      struct zx_ff12_Assertion_s* en;
      for (e = x->ff12_Assertion; e; e = en) {
	  en = (struct zx_ff12_Assertion_s*)e->gg.g.n;
	  zx_FREE_ff12_Assertion(c, e, free_strs);
      }
  }
  {
      struct zx_wsse_BinarySecurityToken_s* e;
      struct zx_wsse_BinarySecurityToken_s* en;
      for (e = x->BinarySecurityToken; e; e = en) {
	  en = (struct zx_wsse_BinarySecurityToken_s*)e->gg.g.n;
	  zx_FREE_wsse_BinarySecurityToken(c, e, free_strs);
      }
  }
  {
      struct zx_wsse_SecurityTokenReference_s* e;
      struct zx_wsse_SecurityTokenReference_s* en;
      for (e = x->SecurityTokenReference; e; e = en) {
	  en = (struct zx_wsse_SecurityTokenReference_s*)e->gg.g.n;
	  zx_FREE_wsse_SecurityTokenReference(c, e, free_strs);
      }
  }
  {
      struct zx_wsu_Timestamp_s* e;
      struct zx_wsu_Timestamp_s* en;
      for (e = x->Timestamp; e; e = en) {
	  en = (struct zx_wsu_Timestamp_s*)e->gg.g.n;
	  zx_FREE_wsu_Timestamp(c, e, free_strs);
      }
  }


  zx_free_elem_common(c, &x->gg, free_strs); 
}

/* FUNC(zx_NEW_wsse_Security) */

/* Trivial allocator/constructor for the datatype. */

/* Called by: */
struct zx_wsse_Security_s* zx_NEW_wsse_Security(struct zx_ctx* c)
{
  struct zx_wsse_Security_s* x = ZX_ZALLOC(c, struct zx_wsse_Security_s);
  x->gg.g.tok = zx_wsse_Security_ELEM;
  return x;
}

#ifdef ZX_ENA_AUX

/* FUNC(zx_DUP_STRS_wsse_Security) */

/* Depth first traversal of data structure to copy its simple strings
 * to memory allocated from the memory allocator. The decoder will
 * use the underlying wireprotocol PDU buffer for strings, i.e.
 * strings are not copied - they point to the real data. If the
 * datastructure needs to outlast the protocol data or needs a different
 * memory allocation strategy, you need to call this function.  */

/* Called by: */
void zx_DUP_STRS_wsse_Security(struct zx_ctx* c, struct zx_wsse_Security_s* x)
{
  zx_dup_strs_common(c, &x->gg);
  /* *** deal with xmlns specifications in exc c14n way */

  zx_dup_attr(c, x->Id);
  zx_dup_attr(c, x->actor);
  zx_dup_attr(c, x->mustUnderstand);

  {
      struct zx_ds_Signature_s* e;
      for (e = x->Signature; e; e = (struct zx_ds_Signature_s*)e->gg.g.n)
	  zx_DUP_STRS_ds_Signature(c, e);
  }
  {
      struct zx_sa_Assertion_s* e;
      for (e = x->Assertion; e; e = (struct zx_sa_Assertion_s*)e->gg.g.n)
	  zx_DUP_STRS_sa_Assertion(c, e);
  }
  {
      struct zx_sa_EncryptedAssertion_s* e;
      for (e = x->EncryptedAssertion; e; e = (struct zx_sa_EncryptedAssertion_s*)e->gg.g.n)
	  zx_DUP_STRS_sa_EncryptedAssertion(c, e);
  }
  {
      struct zx_sa11_Assertion_s* e;
      for (e = x->sa11_Assertion; e; e = (struct zx_sa11_Assertion_s*)e->gg.g.n)
	  zx_DUP_STRS_sa11_Assertion(c, e);
  }
  {
      struct zx_ff12_Assertion_s* e;
      for (e = x->ff12_Assertion; e; e = (struct zx_ff12_Assertion_s*)e->gg.g.n)
	  zx_DUP_STRS_ff12_Assertion(c, e);
  }
  {
      struct zx_wsse_BinarySecurityToken_s* e;
      for (e = x->BinarySecurityToken; e; e = (struct zx_wsse_BinarySecurityToken_s*)e->gg.g.n)
	  zx_DUP_STRS_wsse_BinarySecurityToken(c, e);
  }
  {
      struct zx_wsse_SecurityTokenReference_s* e;
      for (e = x->SecurityTokenReference; e; e = (struct zx_wsse_SecurityTokenReference_s*)e->gg.g.n)
	  zx_DUP_STRS_wsse_SecurityTokenReference(c, e);
  }
  {
      struct zx_wsu_Timestamp_s* e;
      for (e = x->Timestamp; e; e = (struct zx_wsu_Timestamp_s*)e->gg.g.n)
	  zx_DUP_STRS_wsu_Timestamp(c, e);
  }

}

/* FUNC(zx_DEEP_CLONE_wsse_Security) */

/* Depth first traversal of data structure to clone it and its sublements.
 * The simple strings are handled as a special case according to dup_strs flag. */

/* Called by: */
struct zx_wsse_Security_s* zx_DEEP_CLONE_wsse_Security(struct zx_ctx* c, struct zx_wsse_Security_s* x, int dup_strs)
{
  x = (struct zx_wsse_Security_s*)zx_clone_elem_common(c, &x->gg, sizeof(struct zx_wsse_Security_s), dup_strs);
  /* *** deal with xmlns specifications in exc c14n way */

  x->Id = zx_clone_attr(c, x->Id);
  x->actor = zx_clone_attr(c, x->actor);
  x->mustUnderstand = zx_clone_attr(c, x->mustUnderstand);

  {
      struct zx_ds_Signature_s* e;
      struct zx_ds_Signature_s* en;
      struct zx_ds_Signature_s* enn;
      for (enn = 0, e = x->Signature; e; e = (struct zx_ds_Signature_s*)e->gg.g.n) {
	  en = zx_DEEP_CLONE_ds_Signature(c, e, dup_strs);
	  if (!enn)
	      x->Signature = en;
	  else
	      enn->gg.g.n = &en->gg.g;
	  enn = en;
      }
  }
  {
      struct zx_sa_Assertion_s* e;
      struct zx_sa_Assertion_s* en;
      struct zx_sa_Assertion_s* enn;
      for (enn = 0, e = x->Assertion; e; e = (struct zx_sa_Assertion_s*)e->gg.g.n) {
	  en = zx_DEEP_CLONE_sa_Assertion(c, e, dup_strs);
	  if (!enn)
	      x->Assertion = en;
	  else
	      enn->gg.g.n = &en->gg.g;
	  enn = en;
      }
  }
  {
      struct zx_sa_EncryptedAssertion_s* e;
      struct zx_sa_EncryptedAssertion_s* en;
      struct zx_sa_EncryptedAssertion_s* enn;
      for (enn = 0, e = x->EncryptedAssertion; e; e = (struct zx_sa_EncryptedAssertion_s*)e->gg.g.n) {
	  en = zx_DEEP_CLONE_sa_EncryptedAssertion(c, e, dup_strs);
	  if (!enn)
	      x->EncryptedAssertion = en;
	  else
	      enn->gg.g.n = &en->gg.g;
	  enn = en;
      }
  }
  {
      struct zx_sa11_Assertion_s* e;
      struct zx_sa11_Assertion_s* en;
      struct zx_sa11_Assertion_s* enn;
      for (enn = 0, e = x->sa11_Assertion; e; e = (struct zx_sa11_Assertion_s*)e->gg.g.n) {
	  en = zx_DEEP_CLONE_sa11_Assertion(c, e, dup_strs);
	  if (!enn)
	      x->sa11_Assertion = en;
	  else
	      enn->gg.g.n = &en->gg.g;
	  enn = en;
      }
  }
  {
      struct zx_ff12_Assertion_s* e;
      struct zx_ff12_Assertion_s* en;
      struct zx_ff12_Assertion_s* enn;
      for (enn = 0, e = x->ff12_Assertion; e; e = (struct zx_ff12_Assertion_s*)e->gg.g.n) {
	  en = zx_DEEP_CLONE_ff12_Assertion(c, e, dup_strs);
	  if (!enn)
	      x->ff12_Assertion = en;
	  else
	      enn->gg.g.n = &en->gg.g;
	  enn = en;
      }
  }
  {
      struct zx_wsse_BinarySecurityToken_s* e;
      struct zx_wsse_BinarySecurityToken_s* en;
      struct zx_wsse_BinarySecurityToken_s* enn;
      for (enn = 0, e = x->BinarySecurityToken; e; e = (struct zx_wsse_BinarySecurityToken_s*)e->gg.g.n) {
	  en = zx_DEEP_CLONE_wsse_BinarySecurityToken(c, e, dup_strs);
	  if (!enn)
	      x->BinarySecurityToken = en;
	  else
	      enn->gg.g.n = &en->gg.g;
	  enn = en;
      }
  }
  {
      struct zx_wsse_SecurityTokenReference_s* e;
      struct zx_wsse_SecurityTokenReference_s* en;
      struct zx_wsse_SecurityTokenReference_s* enn;
      for (enn = 0, e = x->SecurityTokenReference; e; e = (struct zx_wsse_SecurityTokenReference_s*)e->gg.g.n) {
	  en = zx_DEEP_CLONE_wsse_SecurityTokenReference(c, e, dup_strs);
	  if (!enn)
	      x->SecurityTokenReference = en;
	  else
	      enn->gg.g.n = &en->gg.g;
	  enn = en;
      }
  }
  {
      struct zx_wsu_Timestamp_s* e;
      struct zx_wsu_Timestamp_s* en;
      struct zx_wsu_Timestamp_s* enn;
      for (enn = 0, e = x->Timestamp; e; e = (struct zx_wsu_Timestamp_s*)e->gg.g.n) {
	  en = zx_DEEP_CLONE_wsu_Timestamp(c, e, dup_strs);
	  if (!enn)
	      x->Timestamp = en;
	  else
	      enn->gg.g.n = &en->gg.g;
	  enn = en;
      }
  }

  return x;
}

/* FUNC(zx_WALK_SO_wsse_Security) */

/* Depth first traversal of the tree in either schema order or the wire order. */
 
int zx_WALK_SO_wsse_Security(struct zx_ctx* c, struct zx_wsse_Security_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
{
  int ret = callback(&x->gg.g, ctx);
  if (ret)
    return ret;
  
  /* *** deal with xmlns specifications in exc c14n way */


  
  ret = zx_walk_so_unknown_attributes(c, &x->gg, ctx, callback); 
  if (ret)
    return ret;

  {
      struct zx_ds_Signature_s* e;
      for (e = x->Signature; e; e = (struct zx_ds_Signature_s*)e->gg.g.n) {
	  ret = zx_WALK_SO_ds_Signature(c, e, ctx, callback);
	  if (ret)
	      return ret;
      }
  }
  {
      struct zx_sa_Assertion_s* e;
      for (e = x->Assertion; e; e = (struct zx_sa_Assertion_s*)e->gg.g.n) {
	  ret = zx_WALK_SO_sa_Assertion(c, e, ctx, callback);
	  if (ret)
	      return ret;
      }
  }
  {
      struct zx_sa_EncryptedAssertion_s* e;
      for (e = x->EncryptedAssertion; e; e = (struct zx_sa_EncryptedAssertion_s*)e->gg.g.n) {
	  ret = zx_WALK_SO_sa_EncryptedAssertion(c, e, ctx, callback);
	  if (ret)
	      return ret;
      }
  }
  {
      struct zx_sa11_Assertion_s* e;
      for (e = x->sa11_Assertion; e; e = (struct zx_sa11_Assertion_s*)e->gg.g.n) {
	  ret = zx_WALK_SO_sa11_Assertion(c, e, ctx, callback);
	  if (ret)
	      return ret;
      }
  }
  {
      struct zx_ff12_Assertion_s* e;
      for (e = x->ff12_Assertion; e; e = (struct zx_ff12_Assertion_s*)e->gg.g.n) {
	  ret = zx_WALK_SO_ff12_Assertion(c, e, ctx, callback);
	  if (ret)
	      return ret;
      }
  }
  {
      struct zx_wsse_BinarySecurityToken_s* e;
      for (e = x->BinarySecurityToken; e; e = (struct zx_wsse_BinarySecurityToken_s*)e->gg.g.n) {
	  ret = zx_WALK_SO_wsse_BinarySecurityToken(c, e, ctx, callback);
	  if (ret)
	      return ret;
      }
  }
  {
      struct zx_wsse_SecurityTokenReference_s* e;
      for (e = x->SecurityTokenReference; e; e = (struct zx_wsse_SecurityTokenReference_s*)e->gg.g.n) {
	  ret = zx_WALK_SO_wsse_SecurityTokenReference(c, e, ctx, callback);
	  if (ret)
	      return ret;
      }
  }
  {
      struct zx_wsu_Timestamp_s* e;
      for (e = x->Timestamp; e; e = (struct zx_wsu_Timestamp_s*)e->gg.g.n) {
	  ret = zx_WALK_SO_wsu_Timestamp(c, e, ctx, callback);
	  if (ret)
	      return ret;
      }
  }

  
  return zx_walk_so_unknown_elems_and_content(c, &x->gg, ctx, callback);
}

/* FUNC(zx_WALK_WO_wsse_Security) */

int zx_WALK_WO_wsse_Security(struct zx_ctx* c, struct zx_wsse_Security_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
{
  ERR("*** walk_wo not implemented %d", 0);
  return 0;
}

#endif




#ifdef EL_NAME
#undef EL_NAME
#endif
#ifdef EL_STRUCT
#undef EL_STRUCT
#endif
#ifdef EL_NS
#undef EL_NS
#endif
#ifdef EL_TAG
#undef EL_TAG
#endif

#define EL_NAME   wsse_SecurityTokenReference
#define EL_STRUCT zx_wsse_SecurityTokenReference_s
#define EL_NS     wsse
#define EL_TAG    SecurityTokenReference

/* FUNC(zx_FREE_wsse_SecurityTokenReference) */

/* Depth first traversal of data structure to free it and its subelements. Simple
 * strings are handled as a special case according to the free_strs flag. This
 * is useful if the strings point to underlying data from the wire that was
 * allocated differently. */

/* Called by: */
void zx_FREE_wsse_SecurityTokenReference(struct zx_ctx* c, struct zx_wsse_SecurityTokenReference_s* x, int free_strs)
{
  /* *** deal with xmlns specifications in exc c14n way */

  zx_free_attr(c, x->Usage, free_strs);
  zx_free_attr(c, x->Id, free_strs);

  {
      struct zx_wsse_KeyIdentifier_s* e;
      struct zx_wsse_KeyIdentifier_s* en;
      for (e = x->KeyIdentifier; e; e = en) {
	  en = (struct zx_wsse_KeyIdentifier_s*)e->gg.g.n;
	  zx_FREE_wsse_KeyIdentifier(c, e, free_strs);
      }
  }


  zx_free_elem_common(c, &x->gg, free_strs); 
}

/* FUNC(zx_NEW_wsse_SecurityTokenReference) */

/* Trivial allocator/constructor for the datatype. */

/* Called by: */
struct zx_wsse_SecurityTokenReference_s* zx_NEW_wsse_SecurityTokenReference(struct zx_ctx* c)
{
  struct zx_wsse_SecurityTokenReference_s* x = ZX_ZALLOC(c, struct zx_wsse_SecurityTokenReference_s);
  x->gg.g.tok = zx_wsse_SecurityTokenReference_ELEM;
  return x;
}

#ifdef ZX_ENA_AUX

/* FUNC(zx_DUP_STRS_wsse_SecurityTokenReference) */

/* Depth first traversal of data structure to copy its simple strings
 * to memory allocated from the memory allocator. The decoder will
 * use the underlying wireprotocol PDU buffer for strings, i.e.
 * strings are not copied - they point to the real data. If the
 * datastructure needs to outlast the protocol data or needs a different
 * memory allocation strategy, you need to call this function.  */

/* Called by: */
void zx_DUP_STRS_wsse_SecurityTokenReference(struct zx_ctx* c, struct zx_wsse_SecurityTokenReference_s* x)
{
  zx_dup_strs_common(c, &x->gg);
  /* *** deal with xmlns specifications in exc c14n way */

  zx_dup_attr(c, x->Usage);
  zx_dup_attr(c, x->Id);

  {
      struct zx_wsse_KeyIdentifier_s* e;
      for (e = x->KeyIdentifier; e; e = (struct zx_wsse_KeyIdentifier_s*)e->gg.g.n)
	  zx_DUP_STRS_wsse_KeyIdentifier(c, e);
  }

}

/* FUNC(zx_DEEP_CLONE_wsse_SecurityTokenReference) */

/* Depth first traversal of data structure to clone it and its sublements.
 * The simple strings are handled as a special case according to dup_strs flag. */

/* Called by: */
struct zx_wsse_SecurityTokenReference_s* zx_DEEP_CLONE_wsse_SecurityTokenReference(struct zx_ctx* c, struct zx_wsse_SecurityTokenReference_s* x, int dup_strs)
{
  x = (struct zx_wsse_SecurityTokenReference_s*)zx_clone_elem_common(c, &x->gg, sizeof(struct zx_wsse_SecurityTokenReference_s), dup_strs);
  /* *** deal with xmlns specifications in exc c14n way */

  x->Usage = zx_clone_attr(c, x->Usage);
  x->Id = zx_clone_attr(c, x->Id);

  {
      struct zx_wsse_KeyIdentifier_s* e;
      struct zx_wsse_KeyIdentifier_s* en;
      struct zx_wsse_KeyIdentifier_s* enn;
      for (enn = 0, e = x->KeyIdentifier; e; e = (struct zx_wsse_KeyIdentifier_s*)e->gg.g.n) {
	  en = zx_DEEP_CLONE_wsse_KeyIdentifier(c, e, dup_strs);
	  if (!enn)
	      x->KeyIdentifier = en;
	  else
	      enn->gg.g.n = &en->gg.g;
	  enn = en;
      }
  }

  return x;
}

/* FUNC(zx_WALK_SO_wsse_SecurityTokenReference) */

/* Depth first traversal of the tree in either schema order or the wire order. */
 
int zx_WALK_SO_wsse_SecurityTokenReference(struct zx_ctx* c, struct zx_wsse_SecurityTokenReference_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
{
  int ret = callback(&x->gg.g, ctx);
  if (ret)
    return ret;
  
  /* *** deal with xmlns specifications in exc c14n way */


  
  ret = zx_walk_so_unknown_attributes(c, &x->gg, ctx, callback); 
  if (ret)
    return ret;

  {
      struct zx_wsse_KeyIdentifier_s* e;
      for (e = x->KeyIdentifier; e; e = (struct zx_wsse_KeyIdentifier_s*)e->gg.g.n) {
	  ret = zx_WALK_SO_wsse_KeyIdentifier(c, e, ctx, callback);
	  if (ret)
	      return ret;
      }
  }

  
  return zx_walk_so_unknown_elems_and_content(c, &x->gg, ctx, callback);
}

/* FUNC(zx_WALK_WO_wsse_SecurityTokenReference) */

int zx_WALK_WO_wsse_SecurityTokenReference(struct zx_ctx* c, struct zx_wsse_SecurityTokenReference_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
{
  ERR("*** walk_wo not implemented %d", 0);
  return 0;
}

#endif




#ifdef EL_NAME
#undef EL_NAME
#endif
#ifdef EL_STRUCT
#undef EL_STRUCT
#endif
#ifdef EL_NS
#undef EL_NS
#endif
#ifdef EL_TAG
#undef EL_TAG
#endif

#define EL_NAME   wsse_TransformationParameters
#define EL_STRUCT zx_wsse_TransformationParameters_s
#define EL_NS     wsse
#define EL_TAG    TransformationParameters

/* FUNC(zx_FREE_wsse_TransformationParameters) */

/* Depth first traversal of data structure to free it and its subelements. Simple
 * strings are handled as a special case according to the free_strs flag. This
 * is useful if the strings point to underlying data from the wire that was
 * allocated differently. */

/* Called by: */
void zx_FREE_wsse_TransformationParameters(struct zx_ctx* c, struct zx_wsse_TransformationParameters_s* x, int free_strs)
{
  /* *** deal with xmlns specifications in exc c14n way */




  zx_free_elem_common(c, &x->gg, free_strs); 
}

/* FUNC(zx_NEW_wsse_TransformationParameters) */

/* Trivial allocator/constructor for the datatype. */

/* Called by: */
struct zx_wsse_TransformationParameters_s* zx_NEW_wsse_TransformationParameters(struct zx_ctx* c)
{
  struct zx_wsse_TransformationParameters_s* x = ZX_ZALLOC(c, struct zx_wsse_TransformationParameters_s);
  x->gg.g.tok = zx_wsse_TransformationParameters_ELEM;
  return x;
}

#ifdef ZX_ENA_AUX

/* FUNC(zx_DUP_STRS_wsse_TransformationParameters) */

/* Depth first traversal of data structure to copy its simple strings
 * to memory allocated from the memory allocator. The decoder will
 * use the underlying wireprotocol PDU buffer for strings, i.e.
 * strings are not copied - they point to the real data. If the
 * datastructure needs to outlast the protocol data or needs a different
 * memory allocation strategy, you need to call this function.  */

/* Called by: */
void zx_DUP_STRS_wsse_TransformationParameters(struct zx_ctx* c, struct zx_wsse_TransformationParameters_s* x)
{
  zx_dup_strs_common(c, &x->gg);
  /* *** deal with xmlns specifications in exc c14n way */



}

/* FUNC(zx_DEEP_CLONE_wsse_TransformationParameters) */

/* Depth first traversal of data structure to clone it and its sublements.
 * The simple strings are handled as a special case according to dup_strs flag. */

/* Called by: */
struct zx_wsse_TransformationParameters_s* zx_DEEP_CLONE_wsse_TransformationParameters(struct zx_ctx* c, struct zx_wsse_TransformationParameters_s* x, int dup_strs)
{
  x = (struct zx_wsse_TransformationParameters_s*)zx_clone_elem_common(c, &x->gg, sizeof(struct zx_wsse_TransformationParameters_s), dup_strs);
  /* *** deal with xmlns specifications in exc c14n way */



  return x;
}

/* FUNC(zx_WALK_SO_wsse_TransformationParameters) */

/* Depth first traversal of the tree in either schema order or the wire order. */
 
int zx_WALK_SO_wsse_TransformationParameters(struct zx_ctx* c, struct zx_wsse_TransformationParameters_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
{
  int ret = callback(&x->gg.g, ctx);
  if (ret)
    return ret;
  
  /* *** deal with xmlns specifications in exc c14n way */


  
  ret = zx_walk_so_unknown_attributes(c, &x->gg, ctx, callback); 
  if (ret)
    return ret;


  
  return zx_walk_so_unknown_elems_and_content(c, &x->gg, ctx, callback);
}

/* FUNC(zx_WALK_WO_wsse_TransformationParameters) */

int zx_WALK_WO_wsse_TransformationParameters(struct zx_ctx* c, struct zx_wsse_TransformationParameters_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
{
  ERR("*** walk_wo not implemented %d", 0);
  return 0;
}

#endif




#ifdef EL_NAME
#undef EL_NAME
#endif
#ifdef EL_STRUCT
#undef EL_STRUCT
#endif
#ifdef EL_NS
#undef EL_NS
#endif
#ifdef EL_TAG
#undef EL_TAG
#endif

#define EL_NAME   wsse_Username
#define EL_STRUCT zx_wsse_Username_s
#define EL_NS     wsse
#define EL_TAG    Username

/* FUNC(zx_FREE_wsse_Username) */

/* Depth first traversal of data structure to free it and its subelements. Simple
 * strings are handled as a special case according to the free_strs flag. This
 * is useful if the strings point to underlying data from the wire that was
 * allocated differently. */

/* Called by: */
void zx_FREE_wsse_Username(struct zx_ctx* c, struct zx_wsse_Username_s* x, int free_strs)
{
  /* *** deal with xmlns specifications in exc c14n way */

  zx_free_attr(c, x->Id, free_strs);



  zx_free_elem_common(c, &x->gg, free_strs); 
}

/* FUNC(zx_NEW_wsse_Username) */

/* Trivial allocator/constructor for the datatype. */

/* Called by: */
struct zx_wsse_Username_s* zx_NEW_wsse_Username(struct zx_ctx* c)
{
  struct zx_wsse_Username_s* x = ZX_ZALLOC(c, struct zx_wsse_Username_s);
  x->gg.g.tok = zx_wsse_Username_ELEM;
  return x;
}

#ifdef ZX_ENA_AUX

/* FUNC(zx_DUP_STRS_wsse_Username) */

/* Depth first traversal of data structure to copy its simple strings
 * to memory allocated from the memory allocator. The decoder will
 * use the underlying wireprotocol PDU buffer for strings, i.e.
 * strings are not copied - they point to the real data. If the
 * datastructure needs to outlast the protocol data or needs a different
 * memory allocation strategy, you need to call this function.  */

/* Called by: */
void zx_DUP_STRS_wsse_Username(struct zx_ctx* c, struct zx_wsse_Username_s* x)
{
  zx_dup_strs_common(c, &x->gg);
  /* *** deal with xmlns specifications in exc c14n way */

  zx_dup_attr(c, x->Id);


}

/* FUNC(zx_DEEP_CLONE_wsse_Username) */

/* Depth first traversal of data structure to clone it and its sublements.
 * The simple strings are handled as a special case according to dup_strs flag. */

/* Called by: */
struct zx_wsse_Username_s* zx_DEEP_CLONE_wsse_Username(struct zx_ctx* c, struct zx_wsse_Username_s* x, int dup_strs)
{
  x = (struct zx_wsse_Username_s*)zx_clone_elem_common(c, &x->gg, sizeof(struct zx_wsse_Username_s), dup_strs);
  /* *** deal with xmlns specifications in exc c14n way */

  x->Id = zx_clone_attr(c, x->Id);


  return x;
}

/* FUNC(zx_WALK_SO_wsse_Username) */

/* Depth first traversal of the tree in either schema order or the wire order. */
 
int zx_WALK_SO_wsse_Username(struct zx_ctx* c, struct zx_wsse_Username_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
{
  int ret = callback(&x->gg.g, ctx);
  if (ret)
    return ret;
  
  /* *** deal with xmlns specifications in exc c14n way */


  
  ret = zx_walk_so_unknown_attributes(c, &x->gg, ctx, callback); 
  if (ret)
    return ret;


  
  return zx_walk_so_unknown_elems_and_content(c, &x->gg, ctx, callback);
}

/* FUNC(zx_WALK_WO_wsse_Username) */

int zx_WALK_WO_wsse_Username(struct zx_ctx* c, struct zx_wsse_Username_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
{
  ERR("*** walk_wo not implemented %d", 0);
  return 0;
}

#endif




#ifdef EL_NAME
#undef EL_NAME
#endif
#ifdef EL_STRUCT
#undef EL_STRUCT
#endif
#ifdef EL_NS
#undef EL_NS
#endif
#ifdef EL_TAG
#undef EL_TAG
#endif

#define EL_NAME   wsse_UsernameToken
#define EL_STRUCT zx_wsse_UsernameToken_s
#define EL_NS     wsse
#define EL_TAG    UsernameToken

/* FUNC(zx_FREE_wsse_UsernameToken) */

/* Depth first traversal of data structure to free it and its subelements. Simple
 * strings are handled as a special case according to the free_strs flag. This
 * is useful if the strings point to underlying data from the wire that was
 * allocated differently. */

/* Called by: */
void zx_FREE_wsse_UsernameToken(struct zx_ctx* c, struct zx_wsse_UsernameToken_s* x, int free_strs)
{
  /* *** deal with xmlns specifications in exc c14n way */

  zx_free_attr(c, x->Id, free_strs);

  {
      struct zx_wsse_Username_s* e;
      struct zx_wsse_Username_s* en;
      for (e = x->Username; e; e = en) {
	  en = (struct zx_wsse_Username_s*)e->gg.g.n;
	  zx_FREE_wsse_Username(c, e, free_strs);
      }
  }


  zx_free_elem_common(c, &x->gg, free_strs); 
}

/* FUNC(zx_NEW_wsse_UsernameToken) */

/* Trivial allocator/constructor for the datatype. */

/* Called by: */
struct zx_wsse_UsernameToken_s* zx_NEW_wsse_UsernameToken(struct zx_ctx* c)
{
  struct zx_wsse_UsernameToken_s* x = ZX_ZALLOC(c, struct zx_wsse_UsernameToken_s);
  x->gg.g.tok = zx_wsse_UsernameToken_ELEM;
  return x;
}

#ifdef ZX_ENA_AUX

/* FUNC(zx_DUP_STRS_wsse_UsernameToken) */

/* Depth first traversal of data structure to copy its simple strings
 * to memory allocated from the memory allocator. The decoder will
 * use the underlying wireprotocol PDU buffer for strings, i.e.
 * strings are not copied - they point to the real data. If the
 * datastructure needs to outlast the protocol data or needs a different
 * memory allocation strategy, you need to call this function.  */

/* Called by: */
void zx_DUP_STRS_wsse_UsernameToken(struct zx_ctx* c, struct zx_wsse_UsernameToken_s* x)
{
  zx_dup_strs_common(c, &x->gg);
  /* *** deal with xmlns specifications in exc c14n way */

  zx_dup_attr(c, x->Id);

  {
      struct zx_wsse_Username_s* e;
      for (e = x->Username; e; e = (struct zx_wsse_Username_s*)e->gg.g.n)
	  zx_DUP_STRS_wsse_Username(c, e);
  }

}

/* FUNC(zx_DEEP_CLONE_wsse_UsernameToken) */

/* Depth first traversal of data structure to clone it and its sublements.
 * The simple strings are handled as a special case according to dup_strs flag. */

/* Called by: */
struct zx_wsse_UsernameToken_s* zx_DEEP_CLONE_wsse_UsernameToken(struct zx_ctx* c, struct zx_wsse_UsernameToken_s* x, int dup_strs)
{
  x = (struct zx_wsse_UsernameToken_s*)zx_clone_elem_common(c, &x->gg, sizeof(struct zx_wsse_UsernameToken_s), dup_strs);
  /* *** deal with xmlns specifications in exc c14n way */

  x->Id = zx_clone_attr(c, x->Id);

  {
      struct zx_wsse_Username_s* e;
      struct zx_wsse_Username_s* en;
      struct zx_wsse_Username_s* enn;
      for (enn = 0, e = x->Username; e; e = (struct zx_wsse_Username_s*)e->gg.g.n) {
	  en = zx_DEEP_CLONE_wsse_Username(c, e, dup_strs);
	  if (!enn)
	      x->Username = en;
	  else
	      enn->gg.g.n = &en->gg.g;
	  enn = en;
      }
  }

  return x;
}

/* FUNC(zx_WALK_SO_wsse_UsernameToken) */

/* Depth first traversal of the tree in either schema order or the wire order. */
 
int zx_WALK_SO_wsse_UsernameToken(struct zx_ctx* c, struct zx_wsse_UsernameToken_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
{
  int ret = callback(&x->gg.g, ctx);
  if (ret)
    return ret;
  
  /* *** deal with xmlns specifications in exc c14n way */


  
  ret = zx_walk_so_unknown_attributes(c, &x->gg, ctx, callback); 
  if (ret)
    return ret;

  {
      struct zx_wsse_Username_s* e;
      for (e = x->Username; e; e = (struct zx_wsse_Username_s*)e->gg.g.n) {
	  ret = zx_WALK_SO_wsse_Username(c, e, ctx, callback);
	  if (ret)
	      return ret;
      }
  }

  
  return zx_walk_so_unknown_elems_and_content(c, &x->gg, ctx, callback);
}

/* FUNC(zx_WALK_WO_wsse_UsernameToken) */

int zx_WALK_WO_wsse_UsernameToken(struct zx_ctx* c, struct zx_wsse_UsernameToken_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
{
  ERR("*** walk_wo not implemented %d", 0);
  return 0;
}

#endif


/* EOF -- c/zx-wsse-aux.c */
