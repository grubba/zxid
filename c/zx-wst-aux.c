/* c/zx-wst-aux.c - WARNING: This file was automatically generated. DO NOT EDIT!
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
#include "c/zx-wst-data.h"



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

#define EL_NAME   wst_Authenticator
#define EL_STRUCT zx_wst_Authenticator_s
#define EL_NS     wst
#define EL_TAG    Authenticator

/* FUNC(zx_FREE_wst_Authenticator) */

/* Depth first traversal of data structure to free it and its subelements. Simple
 * strings are handled as a special case according to the free_strs flag. This
 * is useful if the strings point to underlying data from the wire that was
 * allocated differently. */

/* Called by: */
void zx_FREE_wst_Authenticator(struct zx_ctx* c, struct zx_wst_Authenticator_s* x, int free_strs)
{
  /* *** deal with xmlns specifications in exc c14n way */


  zx_free_simple_elems(c, x->CombinedHash, free_strs);


  zx_free_elem_common(c, &x->gg, free_strs); 
}

/* FUNC(zx_NEW_wst_Authenticator) */

/* Trivial allocator/constructor for the datatype. */

/* Called by: */
struct zx_wst_Authenticator_s* zx_NEW_wst_Authenticator(struct zx_ctx* c)
{
  struct zx_wst_Authenticator_s* x = ZX_ZALLOC(c, struct zx_wst_Authenticator_s);
  x->gg.g.tok = zx_wst_Authenticator_ELEM;
  return x;
}

#ifdef ZX_ENA_AUX

/* FUNC(zx_DUP_STRS_wst_Authenticator) */

/* Depth first traversal of data structure to copy its simple strings
 * to memory allocated from the memory allocator. The decoder will
 * use the underlying wireprotocol PDU buffer for strings, i.e.
 * strings are not copied - they point to the real data. If the
 * datastructure needs to outlast the protocol data or needs a different
 * memory allocation strategy, you need to call this function.  */

/* Called by: */
void zx_DUP_STRS_wst_Authenticator(struct zx_ctx* c, struct zx_wst_Authenticator_s* x)
{
  zx_dup_strs_common(c, &x->gg);
  /* *** deal with xmlns specifications in exc c14n way */


  zx_dup_strs_simple_elems(c, x->CombinedHash);

}

/* FUNC(zx_DEEP_CLONE_wst_Authenticator) */

/* Depth first traversal of data structure to clone it and its sublements.
 * The simple strings are handled as a special case according to dup_strs flag. */

/* Called by: */
struct zx_wst_Authenticator_s* zx_DEEP_CLONE_wst_Authenticator(struct zx_ctx* c, struct zx_wst_Authenticator_s* x, int dup_strs)
{
  x = (struct zx_wst_Authenticator_s*)zx_clone_elem_common(c, &x->gg, sizeof(struct zx_wst_Authenticator_s), dup_strs);
  /* *** deal with xmlns specifications in exc c14n way */


  x->CombinedHash = zx_deep_clone_simple_elems(c,x->CombinedHash, dup_strs);

  return x;
}

/* FUNC(zx_WALK_SO_wst_Authenticator) */

/* Depth first traversal of the tree in either schema order or the wire order. */
 
int zx_WALK_SO_wst_Authenticator(struct zx_ctx* c, struct zx_wst_Authenticator_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
{
  int ret = callback(&x->gg.g, ctx);
  if (ret)
    return ret;
  
  /* *** deal with xmlns specifications in exc c14n way */


  
  ret = zx_walk_so_unknown_attributes(c, &x->gg, ctx, callback); 
  if (ret)
    return ret;

  ret = zx_walk_so_simple_elems(c, x->CombinedHash, ctx, callback);
  if (ret)
    return ret;

  
  return zx_walk_so_unknown_elems_and_content(c, &x->gg, ctx, callback);
}

/* FUNC(zx_WALK_WO_wst_Authenticator) */

int zx_WALK_WO_wst_Authenticator(struct zx_ctx* c, struct zx_wst_Authenticator_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
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

#define EL_NAME   wst_BinaryExchange
#define EL_STRUCT zx_wst_BinaryExchange_s
#define EL_NS     wst
#define EL_TAG    BinaryExchange

/* FUNC(zx_FREE_wst_BinaryExchange) */

/* Depth first traversal of data structure to free it and its subelements. Simple
 * strings are handled as a special case according to the free_strs flag. This
 * is useful if the strings point to underlying data from the wire that was
 * allocated differently. */

/* Called by: */
void zx_FREE_wst_BinaryExchange(struct zx_ctx* c, struct zx_wst_BinaryExchange_s* x, int free_strs)
{
  /* *** deal with xmlns specifications in exc c14n way */

  zx_free_attr(c, x->EncodingType, free_strs);
  zx_free_attr(c, x->ValueType, free_strs);



  zx_free_elem_common(c, &x->gg, free_strs); 
}

/* FUNC(zx_NEW_wst_BinaryExchange) */

/* Trivial allocator/constructor for the datatype. */

/* Called by: */
struct zx_wst_BinaryExchange_s* zx_NEW_wst_BinaryExchange(struct zx_ctx* c)
{
  struct zx_wst_BinaryExchange_s* x = ZX_ZALLOC(c, struct zx_wst_BinaryExchange_s);
  x->gg.g.tok = zx_wst_BinaryExchange_ELEM;
  return x;
}

#ifdef ZX_ENA_AUX

/* FUNC(zx_DUP_STRS_wst_BinaryExchange) */

/* Depth first traversal of data structure to copy its simple strings
 * to memory allocated from the memory allocator. The decoder will
 * use the underlying wireprotocol PDU buffer for strings, i.e.
 * strings are not copied - they point to the real data. If the
 * datastructure needs to outlast the protocol data or needs a different
 * memory allocation strategy, you need to call this function.  */

/* Called by: */
void zx_DUP_STRS_wst_BinaryExchange(struct zx_ctx* c, struct zx_wst_BinaryExchange_s* x)
{
  zx_dup_strs_common(c, &x->gg);
  /* *** deal with xmlns specifications in exc c14n way */

  zx_dup_attr(c, x->EncodingType);
  zx_dup_attr(c, x->ValueType);


}

/* FUNC(zx_DEEP_CLONE_wst_BinaryExchange) */

/* Depth first traversal of data structure to clone it and its sublements.
 * The simple strings are handled as a special case according to dup_strs flag. */

/* Called by: */
struct zx_wst_BinaryExchange_s* zx_DEEP_CLONE_wst_BinaryExchange(struct zx_ctx* c, struct zx_wst_BinaryExchange_s* x, int dup_strs)
{
  x = (struct zx_wst_BinaryExchange_s*)zx_clone_elem_common(c, &x->gg, sizeof(struct zx_wst_BinaryExchange_s), dup_strs);
  /* *** deal with xmlns specifications in exc c14n way */

  x->EncodingType = zx_clone_attr(c, x->EncodingType);
  x->ValueType = zx_clone_attr(c, x->ValueType);


  return x;
}

/* FUNC(zx_WALK_SO_wst_BinaryExchange) */

/* Depth first traversal of the tree in either schema order or the wire order. */
 
int zx_WALK_SO_wst_BinaryExchange(struct zx_ctx* c, struct zx_wst_BinaryExchange_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
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

/* FUNC(zx_WALK_WO_wst_BinaryExchange) */

int zx_WALK_WO_wst_BinaryExchange(struct zx_ctx* c, struct zx_wst_BinaryExchange_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
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

#define EL_NAME   wst_BinarySecret
#define EL_STRUCT zx_wst_BinarySecret_s
#define EL_NS     wst
#define EL_TAG    BinarySecret

/* FUNC(zx_FREE_wst_BinarySecret) */

/* Depth first traversal of data structure to free it and its subelements. Simple
 * strings are handled as a special case according to the free_strs flag. This
 * is useful if the strings point to underlying data from the wire that was
 * allocated differently. */

/* Called by: */
void zx_FREE_wst_BinarySecret(struct zx_ctx* c, struct zx_wst_BinarySecret_s* x, int free_strs)
{
  /* *** deal with xmlns specifications in exc c14n way */

  zx_free_attr(c, x->Type, free_strs);



  zx_free_elem_common(c, &x->gg, free_strs); 
}

/* FUNC(zx_NEW_wst_BinarySecret) */

/* Trivial allocator/constructor for the datatype. */

/* Called by: */
struct zx_wst_BinarySecret_s* zx_NEW_wst_BinarySecret(struct zx_ctx* c)
{
  struct zx_wst_BinarySecret_s* x = ZX_ZALLOC(c, struct zx_wst_BinarySecret_s);
  x->gg.g.tok = zx_wst_BinarySecret_ELEM;
  return x;
}

#ifdef ZX_ENA_AUX

/* FUNC(zx_DUP_STRS_wst_BinarySecret) */

/* Depth first traversal of data structure to copy its simple strings
 * to memory allocated from the memory allocator. The decoder will
 * use the underlying wireprotocol PDU buffer for strings, i.e.
 * strings are not copied - they point to the real data. If the
 * datastructure needs to outlast the protocol data or needs a different
 * memory allocation strategy, you need to call this function.  */

/* Called by: */
void zx_DUP_STRS_wst_BinarySecret(struct zx_ctx* c, struct zx_wst_BinarySecret_s* x)
{
  zx_dup_strs_common(c, &x->gg);
  /* *** deal with xmlns specifications in exc c14n way */

  zx_dup_attr(c, x->Type);


}

/* FUNC(zx_DEEP_CLONE_wst_BinarySecret) */

/* Depth first traversal of data structure to clone it and its sublements.
 * The simple strings are handled as a special case according to dup_strs flag. */

/* Called by: */
struct zx_wst_BinarySecret_s* zx_DEEP_CLONE_wst_BinarySecret(struct zx_ctx* c, struct zx_wst_BinarySecret_s* x, int dup_strs)
{
  x = (struct zx_wst_BinarySecret_s*)zx_clone_elem_common(c, &x->gg, sizeof(struct zx_wst_BinarySecret_s), dup_strs);
  /* *** deal with xmlns specifications in exc c14n way */

  x->Type = zx_clone_attr(c, x->Type);


  return x;
}

/* FUNC(zx_WALK_SO_wst_BinarySecret) */

/* Depth first traversal of the tree in either schema order or the wire order. */
 
int zx_WALK_SO_wst_BinarySecret(struct zx_ctx* c, struct zx_wst_BinarySecret_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
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

/* FUNC(zx_WALK_WO_wst_BinarySecret) */

int zx_WALK_WO_wst_BinarySecret(struct zx_ctx* c, struct zx_wst_BinarySecret_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
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

#define EL_NAME   wst_CancelTarget
#define EL_STRUCT zx_wst_CancelTarget_s
#define EL_NS     wst
#define EL_TAG    CancelTarget

/* FUNC(zx_FREE_wst_CancelTarget) */

/* Depth first traversal of data structure to free it and its subelements. Simple
 * strings are handled as a special case according to the free_strs flag. This
 * is useful if the strings point to underlying data from the wire that was
 * allocated differently. */

/* Called by: */
void zx_FREE_wst_CancelTarget(struct zx_ctx* c, struct zx_wst_CancelTarget_s* x, int free_strs)
{
  /* *** deal with xmlns specifications in exc c14n way */




  zx_free_elem_common(c, &x->gg, free_strs); 
}

/* FUNC(zx_NEW_wst_CancelTarget) */

/* Trivial allocator/constructor for the datatype. */

/* Called by: */
struct zx_wst_CancelTarget_s* zx_NEW_wst_CancelTarget(struct zx_ctx* c)
{
  struct zx_wst_CancelTarget_s* x = ZX_ZALLOC(c, struct zx_wst_CancelTarget_s);
  x->gg.g.tok = zx_wst_CancelTarget_ELEM;
  return x;
}

#ifdef ZX_ENA_AUX

/* FUNC(zx_DUP_STRS_wst_CancelTarget) */

/* Depth first traversal of data structure to copy its simple strings
 * to memory allocated from the memory allocator. The decoder will
 * use the underlying wireprotocol PDU buffer for strings, i.e.
 * strings are not copied - they point to the real data. If the
 * datastructure needs to outlast the protocol data or needs a different
 * memory allocation strategy, you need to call this function.  */

/* Called by: */
void zx_DUP_STRS_wst_CancelTarget(struct zx_ctx* c, struct zx_wst_CancelTarget_s* x)
{
  zx_dup_strs_common(c, &x->gg);
  /* *** deal with xmlns specifications in exc c14n way */



}

/* FUNC(zx_DEEP_CLONE_wst_CancelTarget) */

/* Depth first traversal of data structure to clone it and its sublements.
 * The simple strings are handled as a special case according to dup_strs flag. */

/* Called by: */
struct zx_wst_CancelTarget_s* zx_DEEP_CLONE_wst_CancelTarget(struct zx_ctx* c, struct zx_wst_CancelTarget_s* x, int dup_strs)
{
  x = (struct zx_wst_CancelTarget_s*)zx_clone_elem_common(c, &x->gg, sizeof(struct zx_wst_CancelTarget_s), dup_strs);
  /* *** deal with xmlns specifications in exc c14n way */



  return x;
}

/* FUNC(zx_WALK_SO_wst_CancelTarget) */

/* Depth first traversal of the tree in either schema order or the wire order. */
 
int zx_WALK_SO_wst_CancelTarget(struct zx_ctx* c, struct zx_wst_CancelTarget_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
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

/* FUNC(zx_WALK_WO_wst_CancelTarget) */

int zx_WALK_WO_wst_CancelTarget(struct zx_ctx* c, struct zx_wst_CancelTarget_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
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

#define EL_NAME   wst_Claims
#define EL_STRUCT zx_wst_Claims_s
#define EL_NS     wst
#define EL_TAG    Claims

/* FUNC(zx_FREE_wst_Claims) */

/* Depth first traversal of data structure to free it and its subelements. Simple
 * strings are handled as a special case according to the free_strs flag. This
 * is useful if the strings point to underlying data from the wire that was
 * allocated differently. */

/* Called by: */
void zx_FREE_wst_Claims(struct zx_ctx* c, struct zx_wst_Claims_s* x, int free_strs)
{
  /* *** deal with xmlns specifications in exc c14n way */

  zx_free_attr(c, x->Dialect, free_strs);



  zx_free_elem_common(c, &x->gg, free_strs); 
}

/* FUNC(zx_NEW_wst_Claims) */

/* Trivial allocator/constructor for the datatype. */

/* Called by: */
struct zx_wst_Claims_s* zx_NEW_wst_Claims(struct zx_ctx* c)
{
  struct zx_wst_Claims_s* x = ZX_ZALLOC(c, struct zx_wst_Claims_s);
  x->gg.g.tok = zx_wst_Claims_ELEM;
  return x;
}

#ifdef ZX_ENA_AUX

/* FUNC(zx_DUP_STRS_wst_Claims) */

/* Depth first traversal of data structure to copy its simple strings
 * to memory allocated from the memory allocator. The decoder will
 * use the underlying wireprotocol PDU buffer for strings, i.e.
 * strings are not copied - they point to the real data. If the
 * datastructure needs to outlast the protocol data or needs a different
 * memory allocation strategy, you need to call this function.  */

/* Called by: */
void zx_DUP_STRS_wst_Claims(struct zx_ctx* c, struct zx_wst_Claims_s* x)
{
  zx_dup_strs_common(c, &x->gg);
  /* *** deal with xmlns specifications in exc c14n way */

  zx_dup_attr(c, x->Dialect);


}

/* FUNC(zx_DEEP_CLONE_wst_Claims) */

/* Depth first traversal of data structure to clone it and its sublements.
 * The simple strings are handled as a special case according to dup_strs flag. */

/* Called by: */
struct zx_wst_Claims_s* zx_DEEP_CLONE_wst_Claims(struct zx_ctx* c, struct zx_wst_Claims_s* x, int dup_strs)
{
  x = (struct zx_wst_Claims_s*)zx_clone_elem_common(c, &x->gg, sizeof(struct zx_wst_Claims_s), dup_strs);
  /* *** deal with xmlns specifications in exc c14n way */

  x->Dialect = zx_clone_attr(c, x->Dialect);


  return x;
}

/* FUNC(zx_WALK_SO_wst_Claims) */

/* Depth first traversal of the tree in either schema order or the wire order. */
 
int zx_WALK_SO_wst_Claims(struct zx_ctx* c, struct zx_wst_Claims_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
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

/* FUNC(zx_WALK_WO_wst_Claims) */

int zx_WALK_WO_wst_Claims(struct zx_ctx* c, struct zx_wst_Claims_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
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

#define EL_NAME   wst_DelegateTo
#define EL_STRUCT zx_wst_DelegateTo_s
#define EL_NS     wst
#define EL_TAG    DelegateTo

/* FUNC(zx_FREE_wst_DelegateTo) */

/* Depth first traversal of data structure to free it and its subelements. Simple
 * strings are handled as a special case according to the free_strs flag. This
 * is useful if the strings point to underlying data from the wire that was
 * allocated differently. */

/* Called by: */
void zx_FREE_wst_DelegateTo(struct zx_ctx* c, struct zx_wst_DelegateTo_s* x, int free_strs)
{
  /* *** deal with xmlns specifications in exc c14n way */




  zx_free_elem_common(c, &x->gg, free_strs); 
}

/* FUNC(zx_NEW_wst_DelegateTo) */

/* Trivial allocator/constructor for the datatype. */

/* Called by: */
struct zx_wst_DelegateTo_s* zx_NEW_wst_DelegateTo(struct zx_ctx* c)
{
  struct zx_wst_DelegateTo_s* x = ZX_ZALLOC(c, struct zx_wst_DelegateTo_s);
  x->gg.g.tok = zx_wst_DelegateTo_ELEM;
  return x;
}

#ifdef ZX_ENA_AUX

/* FUNC(zx_DUP_STRS_wst_DelegateTo) */

/* Depth first traversal of data structure to copy its simple strings
 * to memory allocated from the memory allocator. The decoder will
 * use the underlying wireprotocol PDU buffer for strings, i.e.
 * strings are not copied - they point to the real data. If the
 * datastructure needs to outlast the protocol data or needs a different
 * memory allocation strategy, you need to call this function.  */

/* Called by: */
void zx_DUP_STRS_wst_DelegateTo(struct zx_ctx* c, struct zx_wst_DelegateTo_s* x)
{
  zx_dup_strs_common(c, &x->gg);
  /* *** deal with xmlns specifications in exc c14n way */



}

/* FUNC(zx_DEEP_CLONE_wst_DelegateTo) */

/* Depth first traversal of data structure to clone it and its sublements.
 * The simple strings are handled as a special case according to dup_strs flag. */

/* Called by: */
struct zx_wst_DelegateTo_s* zx_DEEP_CLONE_wst_DelegateTo(struct zx_ctx* c, struct zx_wst_DelegateTo_s* x, int dup_strs)
{
  x = (struct zx_wst_DelegateTo_s*)zx_clone_elem_common(c, &x->gg, sizeof(struct zx_wst_DelegateTo_s), dup_strs);
  /* *** deal with xmlns specifications in exc c14n way */



  return x;
}

/* FUNC(zx_WALK_SO_wst_DelegateTo) */

/* Depth first traversal of the tree in either schema order or the wire order. */
 
int zx_WALK_SO_wst_DelegateTo(struct zx_ctx* c, struct zx_wst_DelegateTo_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
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

/* FUNC(zx_WALK_WO_wst_DelegateTo) */

int zx_WALK_WO_wst_DelegateTo(struct zx_ctx* c, struct zx_wst_DelegateTo_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
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

#define EL_NAME   wst_Encryption
#define EL_STRUCT zx_wst_Encryption_s
#define EL_NS     wst
#define EL_TAG    Encryption

/* FUNC(zx_FREE_wst_Encryption) */

/* Depth first traversal of data structure to free it and its subelements. Simple
 * strings are handled as a special case according to the free_strs flag. This
 * is useful if the strings point to underlying data from the wire that was
 * allocated differently. */

/* Called by: */
void zx_FREE_wst_Encryption(struct zx_ctx* c, struct zx_wst_Encryption_s* x, int free_strs)
{
  /* *** deal with xmlns specifications in exc c14n way */




  zx_free_elem_common(c, &x->gg, free_strs); 
}

/* FUNC(zx_NEW_wst_Encryption) */

/* Trivial allocator/constructor for the datatype. */

/* Called by: */
struct zx_wst_Encryption_s* zx_NEW_wst_Encryption(struct zx_ctx* c)
{
  struct zx_wst_Encryption_s* x = ZX_ZALLOC(c, struct zx_wst_Encryption_s);
  x->gg.g.tok = zx_wst_Encryption_ELEM;
  return x;
}

#ifdef ZX_ENA_AUX

/* FUNC(zx_DUP_STRS_wst_Encryption) */

/* Depth first traversal of data structure to copy its simple strings
 * to memory allocated from the memory allocator. The decoder will
 * use the underlying wireprotocol PDU buffer for strings, i.e.
 * strings are not copied - they point to the real data. If the
 * datastructure needs to outlast the protocol data or needs a different
 * memory allocation strategy, you need to call this function.  */

/* Called by: */
void zx_DUP_STRS_wst_Encryption(struct zx_ctx* c, struct zx_wst_Encryption_s* x)
{
  zx_dup_strs_common(c, &x->gg);
  /* *** deal with xmlns specifications in exc c14n way */



}

/* FUNC(zx_DEEP_CLONE_wst_Encryption) */

/* Depth first traversal of data structure to clone it and its sublements.
 * The simple strings are handled as a special case according to dup_strs flag. */

/* Called by: */
struct zx_wst_Encryption_s* zx_DEEP_CLONE_wst_Encryption(struct zx_ctx* c, struct zx_wst_Encryption_s* x, int dup_strs)
{
  x = (struct zx_wst_Encryption_s*)zx_clone_elem_common(c, &x->gg, sizeof(struct zx_wst_Encryption_s), dup_strs);
  /* *** deal with xmlns specifications in exc c14n way */



  return x;
}

/* FUNC(zx_WALK_SO_wst_Encryption) */

/* Depth first traversal of the tree in either schema order or the wire order. */
 
int zx_WALK_SO_wst_Encryption(struct zx_ctx* c, struct zx_wst_Encryption_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
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

/* FUNC(zx_WALK_WO_wst_Encryption) */

int zx_WALK_WO_wst_Encryption(struct zx_ctx* c, struct zx_wst_Encryption_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
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

#define EL_NAME   wst_Entropy
#define EL_STRUCT zx_wst_Entropy_s
#define EL_NS     wst
#define EL_TAG    Entropy

/* FUNC(zx_FREE_wst_Entropy) */

/* Depth first traversal of data structure to free it and its subelements. Simple
 * strings are handled as a special case according to the free_strs flag. This
 * is useful if the strings point to underlying data from the wire that was
 * allocated differently. */

/* Called by: */
void zx_FREE_wst_Entropy(struct zx_ctx* c, struct zx_wst_Entropy_s* x, int free_strs)
{
  /* *** deal with xmlns specifications in exc c14n way */




  zx_free_elem_common(c, &x->gg, free_strs); 
}

/* FUNC(zx_NEW_wst_Entropy) */

/* Trivial allocator/constructor for the datatype. */

/* Called by: */
struct zx_wst_Entropy_s* zx_NEW_wst_Entropy(struct zx_ctx* c)
{
  struct zx_wst_Entropy_s* x = ZX_ZALLOC(c, struct zx_wst_Entropy_s);
  x->gg.g.tok = zx_wst_Entropy_ELEM;
  return x;
}

#ifdef ZX_ENA_AUX

/* FUNC(zx_DUP_STRS_wst_Entropy) */

/* Depth first traversal of data structure to copy its simple strings
 * to memory allocated from the memory allocator. The decoder will
 * use the underlying wireprotocol PDU buffer for strings, i.e.
 * strings are not copied - they point to the real data. If the
 * datastructure needs to outlast the protocol data or needs a different
 * memory allocation strategy, you need to call this function.  */

/* Called by: */
void zx_DUP_STRS_wst_Entropy(struct zx_ctx* c, struct zx_wst_Entropy_s* x)
{
  zx_dup_strs_common(c, &x->gg);
  /* *** deal with xmlns specifications in exc c14n way */



}

/* FUNC(zx_DEEP_CLONE_wst_Entropy) */

/* Depth first traversal of data structure to clone it and its sublements.
 * The simple strings are handled as a special case according to dup_strs flag. */

/* Called by: */
struct zx_wst_Entropy_s* zx_DEEP_CLONE_wst_Entropy(struct zx_ctx* c, struct zx_wst_Entropy_s* x, int dup_strs)
{
  x = (struct zx_wst_Entropy_s*)zx_clone_elem_common(c, &x->gg, sizeof(struct zx_wst_Entropy_s), dup_strs);
  /* *** deal with xmlns specifications in exc c14n way */



  return x;
}

/* FUNC(zx_WALK_SO_wst_Entropy) */

/* Depth first traversal of the tree in either schema order or the wire order. */
 
int zx_WALK_SO_wst_Entropy(struct zx_ctx* c, struct zx_wst_Entropy_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
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

/* FUNC(zx_WALK_WO_wst_Entropy) */

int zx_WALK_WO_wst_Entropy(struct zx_ctx* c, struct zx_wst_Entropy_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
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

#define EL_NAME   wst_IssuedTokens
#define EL_STRUCT zx_wst_IssuedTokens_s
#define EL_NS     wst
#define EL_TAG    IssuedTokens

/* FUNC(zx_FREE_wst_IssuedTokens) */

/* Depth first traversal of data structure to free it and its subelements. Simple
 * strings are handled as a special case according to the free_strs flag. This
 * is useful if the strings point to underlying data from the wire that was
 * allocated differently. */

/* Called by: */
void zx_FREE_wst_IssuedTokens(struct zx_ctx* c, struct zx_wst_IssuedTokens_s* x, int free_strs)
{
  /* *** deal with xmlns specifications in exc c14n way */


  {
      struct zx_wst_RequestSecurityTokenResponse_s* e;
      struct zx_wst_RequestSecurityTokenResponse_s* en;
      for (e = x->RequestSecurityTokenResponse; e; e = en) {
	  en = (struct zx_wst_RequestSecurityTokenResponse_s*)e->gg.g.n;
	  zx_FREE_wst_RequestSecurityTokenResponse(c, e, free_strs);
      }
  }


  zx_free_elem_common(c, &x->gg, free_strs); 
}

/* FUNC(zx_NEW_wst_IssuedTokens) */

/* Trivial allocator/constructor for the datatype. */

/* Called by: */
struct zx_wst_IssuedTokens_s* zx_NEW_wst_IssuedTokens(struct zx_ctx* c)
{
  struct zx_wst_IssuedTokens_s* x = ZX_ZALLOC(c, struct zx_wst_IssuedTokens_s);
  x->gg.g.tok = zx_wst_IssuedTokens_ELEM;
  return x;
}

#ifdef ZX_ENA_AUX

/* FUNC(zx_DUP_STRS_wst_IssuedTokens) */

/* Depth first traversal of data structure to copy its simple strings
 * to memory allocated from the memory allocator. The decoder will
 * use the underlying wireprotocol PDU buffer for strings, i.e.
 * strings are not copied - they point to the real data. If the
 * datastructure needs to outlast the protocol data or needs a different
 * memory allocation strategy, you need to call this function.  */

/* Called by: */
void zx_DUP_STRS_wst_IssuedTokens(struct zx_ctx* c, struct zx_wst_IssuedTokens_s* x)
{
  zx_dup_strs_common(c, &x->gg);
  /* *** deal with xmlns specifications in exc c14n way */


  {
      struct zx_wst_RequestSecurityTokenResponse_s* e;
      for (e = x->RequestSecurityTokenResponse; e; e = (struct zx_wst_RequestSecurityTokenResponse_s*)e->gg.g.n)
	  zx_DUP_STRS_wst_RequestSecurityTokenResponse(c, e);
  }

}

/* FUNC(zx_DEEP_CLONE_wst_IssuedTokens) */

/* Depth first traversal of data structure to clone it and its sublements.
 * The simple strings are handled as a special case according to dup_strs flag. */

/* Called by: */
struct zx_wst_IssuedTokens_s* zx_DEEP_CLONE_wst_IssuedTokens(struct zx_ctx* c, struct zx_wst_IssuedTokens_s* x, int dup_strs)
{
  x = (struct zx_wst_IssuedTokens_s*)zx_clone_elem_common(c, &x->gg, sizeof(struct zx_wst_IssuedTokens_s), dup_strs);
  /* *** deal with xmlns specifications in exc c14n way */


  {
      struct zx_wst_RequestSecurityTokenResponse_s* e;
      struct zx_wst_RequestSecurityTokenResponse_s* en;
      struct zx_wst_RequestSecurityTokenResponse_s* enn;
      for (enn = 0, e = x->RequestSecurityTokenResponse; e; e = (struct zx_wst_RequestSecurityTokenResponse_s*)e->gg.g.n) {
	  en = zx_DEEP_CLONE_wst_RequestSecurityTokenResponse(c, e, dup_strs);
	  if (!enn)
	      x->RequestSecurityTokenResponse = en;
	  else
	      enn->gg.g.n = &en->gg.g;
	  enn = en;
      }
  }

  return x;
}

/* FUNC(zx_WALK_SO_wst_IssuedTokens) */

/* Depth first traversal of the tree in either schema order or the wire order. */
 
int zx_WALK_SO_wst_IssuedTokens(struct zx_ctx* c, struct zx_wst_IssuedTokens_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
{
  int ret = callback(&x->gg.g, ctx);
  if (ret)
    return ret;
  
  /* *** deal with xmlns specifications in exc c14n way */


  
  ret = zx_walk_so_unknown_attributes(c, &x->gg, ctx, callback); 
  if (ret)
    return ret;

  {
      struct zx_wst_RequestSecurityTokenResponse_s* e;
      for (e = x->RequestSecurityTokenResponse; e; e = (struct zx_wst_RequestSecurityTokenResponse_s*)e->gg.g.n) {
	  ret = zx_WALK_SO_wst_RequestSecurityTokenResponse(c, e, ctx, callback);
	  if (ret)
	      return ret;
      }
  }

  
  return zx_walk_so_unknown_elems_and_content(c, &x->gg, ctx, callback);
}

/* FUNC(zx_WALK_WO_wst_IssuedTokens) */

int zx_WALK_WO_wst_IssuedTokens(struct zx_ctx* c, struct zx_wst_IssuedTokens_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
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

#define EL_NAME   wst_Issuer
#define EL_STRUCT zx_wst_Issuer_s
#define EL_NS     wst
#define EL_TAG    Issuer

/* FUNC(zx_FREE_wst_Issuer) */

/* Depth first traversal of data structure to free it and its subelements. Simple
 * strings are handled as a special case according to the free_strs flag. This
 * is useful if the strings point to underlying data from the wire that was
 * allocated differently. */

/* Called by: */
void zx_FREE_wst_Issuer(struct zx_ctx* c, struct zx_wst_Issuer_s* x, int free_strs)
{
  /* *** deal with xmlns specifications in exc c14n way */

  zx_free_attr(c, x->ID, free_strs);
  zx_free_attr(c, x->id, free_strs);
  zx_free_attr(c, x->notOnOrAfter, free_strs);
  zx_free_attr(c, x->Id, free_strs);
  zx_free_attr(c, x->actor, free_strs);
  zx_free_attr(c, x->mustUnderstand, free_strs);

  {
      struct zx_a_Address_s* e;
      struct zx_a_Address_s* en;
      for (e = x->Address; e; e = en) {
	  en = (struct zx_a_Address_s*)e->gg.g.n;
	  zx_FREE_a_Address(c, e, free_strs);
      }
  }
  {
      struct zx_a_ReferenceParameters_s* e;
      struct zx_a_ReferenceParameters_s* en;
      for (e = x->ReferenceParameters; e; e = en) {
	  en = (struct zx_a_ReferenceParameters_s*)e->gg.g.n;
	  zx_FREE_a_ReferenceParameters(c, e, free_strs);
      }
  }
  {
      struct zx_a_Metadata_s* e;
      struct zx_a_Metadata_s* en;
      for (e = x->Metadata; e; e = en) {
	  en = (struct zx_a_Metadata_s*)e->gg.g.n;
	  zx_FREE_a_Metadata(c, e, free_strs);
      }
  }


  zx_free_elem_common(c, &x->gg, free_strs); 
}

/* FUNC(zx_NEW_wst_Issuer) */

/* Trivial allocator/constructor for the datatype. */

/* Called by: */
struct zx_wst_Issuer_s* zx_NEW_wst_Issuer(struct zx_ctx* c)
{
  struct zx_wst_Issuer_s* x = ZX_ZALLOC(c, struct zx_wst_Issuer_s);
  x->gg.g.tok = zx_wst_Issuer_ELEM;
  return x;
}

#ifdef ZX_ENA_AUX

/* FUNC(zx_DUP_STRS_wst_Issuer) */

/* Depth first traversal of data structure to copy its simple strings
 * to memory allocated from the memory allocator. The decoder will
 * use the underlying wireprotocol PDU buffer for strings, i.e.
 * strings are not copied - they point to the real data. If the
 * datastructure needs to outlast the protocol data or needs a different
 * memory allocation strategy, you need to call this function.  */

/* Called by: */
void zx_DUP_STRS_wst_Issuer(struct zx_ctx* c, struct zx_wst_Issuer_s* x)
{
  zx_dup_strs_common(c, &x->gg);
  /* *** deal with xmlns specifications in exc c14n way */

  zx_dup_attr(c, x->ID);
  zx_dup_attr(c, x->id);
  zx_dup_attr(c, x->notOnOrAfter);
  zx_dup_attr(c, x->Id);
  zx_dup_attr(c, x->actor);
  zx_dup_attr(c, x->mustUnderstand);

  {
      struct zx_a_Address_s* e;
      for (e = x->Address; e; e = (struct zx_a_Address_s*)e->gg.g.n)
	  zx_DUP_STRS_a_Address(c, e);
  }
  {
      struct zx_a_ReferenceParameters_s* e;
      for (e = x->ReferenceParameters; e; e = (struct zx_a_ReferenceParameters_s*)e->gg.g.n)
	  zx_DUP_STRS_a_ReferenceParameters(c, e);
  }
  {
      struct zx_a_Metadata_s* e;
      for (e = x->Metadata; e; e = (struct zx_a_Metadata_s*)e->gg.g.n)
	  zx_DUP_STRS_a_Metadata(c, e);
  }

}

/* FUNC(zx_DEEP_CLONE_wst_Issuer) */

/* Depth first traversal of data structure to clone it and its sublements.
 * The simple strings are handled as a special case according to dup_strs flag. */

/* Called by: */
struct zx_wst_Issuer_s* zx_DEEP_CLONE_wst_Issuer(struct zx_ctx* c, struct zx_wst_Issuer_s* x, int dup_strs)
{
  x = (struct zx_wst_Issuer_s*)zx_clone_elem_common(c, &x->gg, sizeof(struct zx_wst_Issuer_s), dup_strs);
  /* *** deal with xmlns specifications in exc c14n way */

  x->ID = zx_clone_attr(c, x->ID);
  x->id = zx_clone_attr(c, x->id);
  x->notOnOrAfter = zx_clone_attr(c, x->notOnOrAfter);
  x->Id = zx_clone_attr(c, x->Id);
  x->actor = zx_clone_attr(c, x->actor);
  x->mustUnderstand = zx_clone_attr(c, x->mustUnderstand);

  {
      struct zx_a_Address_s* e;
      struct zx_a_Address_s* en;
      struct zx_a_Address_s* enn;
      for (enn = 0, e = x->Address; e; e = (struct zx_a_Address_s*)e->gg.g.n) {
	  en = zx_DEEP_CLONE_a_Address(c, e, dup_strs);
	  if (!enn)
	      x->Address = en;
	  else
	      enn->gg.g.n = &en->gg.g;
	  enn = en;
      }
  }
  {
      struct zx_a_ReferenceParameters_s* e;
      struct zx_a_ReferenceParameters_s* en;
      struct zx_a_ReferenceParameters_s* enn;
      for (enn = 0, e = x->ReferenceParameters; e; e = (struct zx_a_ReferenceParameters_s*)e->gg.g.n) {
	  en = zx_DEEP_CLONE_a_ReferenceParameters(c, e, dup_strs);
	  if (!enn)
	      x->ReferenceParameters = en;
	  else
	      enn->gg.g.n = &en->gg.g;
	  enn = en;
      }
  }
  {
      struct zx_a_Metadata_s* e;
      struct zx_a_Metadata_s* en;
      struct zx_a_Metadata_s* enn;
      for (enn = 0, e = x->Metadata; e; e = (struct zx_a_Metadata_s*)e->gg.g.n) {
	  en = zx_DEEP_CLONE_a_Metadata(c, e, dup_strs);
	  if (!enn)
	      x->Metadata = en;
	  else
	      enn->gg.g.n = &en->gg.g;
	  enn = en;
      }
  }

  return x;
}

/* FUNC(zx_WALK_SO_wst_Issuer) */

/* Depth first traversal of the tree in either schema order or the wire order. */
 
int zx_WALK_SO_wst_Issuer(struct zx_ctx* c, struct zx_wst_Issuer_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
{
  int ret = callback(&x->gg.g, ctx);
  if (ret)
    return ret;
  
  /* *** deal with xmlns specifications in exc c14n way */


  
  ret = zx_walk_so_unknown_attributes(c, &x->gg, ctx, callback); 
  if (ret)
    return ret;

  {
      struct zx_a_Address_s* e;
      for (e = x->Address; e; e = (struct zx_a_Address_s*)e->gg.g.n) {
	  ret = zx_WALK_SO_a_Address(c, e, ctx, callback);
	  if (ret)
	      return ret;
      }
  }
  {
      struct zx_a_ReferenceParameters_s* e;
      for (e = x->ReferenceParameters; e; e = (struct zx_a_ReferenceParameters_s*)e->gg.g.n) {
	  ret = zx_WALK_SO_a_ReferenceParameters(c, e, ctx, callback);
	  if (ret)
	      return ret;
      }
  }
  {
      struct zx_a_Metadata_s* e;
      for (e = x->Metadata; e; e = (struct zx_a_Metadata_s*)e->gg.g.n) {
	  ret = zx_WALK_SO_a_Metadata(c, e, ctx, callback);
	  if (ret)
	      return ret;
      }
  }

  
  return zx_walk_so_unknown_elems_and_content(c, &x->gg, ctx, callback);
}

/* FUNC(zx_WALK_WO_wst_Issuer) */

int zx_WALK_WO_wst_Issuer(struct zx_ctx* c, struct zx_wst_Issuer_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
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

#define EL_NAME   wst_KeyExchangeToken
#define EL_STRUCT zx_wst_KeyExchangeToken_s
#define EL_NS     wst
#define EL_TAG    KeyExchangeToken

/* FUNC(zx_FREE_wst_KeyExchangeToken) */

/* Depth first traversal of data structure to free it and its subelements. Simple
 * strings are handled as a special case according to the free_strs flag. This
 * is useful if the strings point to underlying data from the wire that was
 * allocated differently. */

/* Called by: */
void zx_FREE_wst_KeyExchangeToken(struct zx_ctx* c, struct zx_wst_KeyExchangeToken_s* x, int free_strs)
{
  /* *** deal with xmlns specifications in exc c14n way */




  zx_free_elem_common(c, &x->gg, free_strs); 
}

/* FUNC(zx_NEW_wst_KeyExchangeToken) */

/* Trivial allocator/constructor for the datatype. */

/* Called by: */
struct zx_wst_KeyExchangeToken_s* zx_NEW_wst_KeyExchangeToken(struct zx_ctx* c)
{
  struct zx_wst_KeyExchangeToken_s* x = ZX_ZALLOC(c, struct zx_wst_KeyExchangeToken_s);
  x->gg.g.tok = zx_wst_KeyExchangeToken_ELEM;
  return x;
}

#ifdef ZX_ENA_AUX

/* FUNC(zx_DUP_STRS_wst_KeyExchangeToken) */

/* Depth first traversal of data structure to copy its simple strings
 * to memory allocated from the memory allocator. The decoder will
 * use the underlying wireprotocol PDU buffer for strings, i.e.
 * strings are not copied - they point to the real data. If the
 * datastructure needs to outlast the protocol data or needs a different
 * memory allocation strategy, you need to call this function.  */

/* Called by: */
void zx_DUP_STRS_wst_KeyExchangeToken(struct zx_ctx* c, struct zx_wst_KeyExchangeToken_s* x)
{
  zx_dup_strs_common(c, &x->gg);
  /* *** deal with xmlns specifications in exc c14n way */



}

/* FUNC(zx_DEEP_CLONE_wst_KeyExchangeToken) */

/* Depth first traversal of data structure to clone it and its sublements.
 * The simple strings are handled as a special case according to dup_strs flag. */

/* Called by: */
struct zx_wst_KeyExchangeToken_s* zx_DEEP_CLONE_wst_KeyExchangeToken(struct zx_ctx* c, struct zx_wst_KeyExchangeToken_s* x, int dup_strs)
{
  x = (struct zx_wst_KeyExchangeToken_s*)zx_clone_elem_common(c, &x->gg, sizeof(struct zx_wst_KeyExchangeToken_s), dup_strs);
  /* *** deal with xmlns specifications in exc c14n way */



  return x;
}

/* FUNC(zx_WALK_SO_wst_KeyExchangeToken) */

/* Depth first traversal of the tree in either schema order or the wire order. */
 
int zx_WALK_SO_wst_KeyExchangeToken(struct zx_ctx* c, struct zx_wst_KeyExchangeToken_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
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

/* FUNC(zx_WALK_WO_wst_KeyExchangeToken) */

int zx_WALK_WO_wst_KeyExchangeToken(struct zx_ctx* c, struct zx_wst_KeyExchangeToken_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
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

#define EL_NAME   wst_Lifetime
#define EL_STRUCT zx_wst_Lifetime_s
#define EL_NS     wst
#define EL_TAG    Lifetime

/* FUNC(zx_FREE_wst_Lifetime) */

/* Depth first traversal of data structure to free it and its subelements. Simple
 * strings are handled as a special case according to the free_strs flag. This
 * is useful if the strings point to underlying data from the wire that was
 * allocated differently. */

/* Called by: */
void zx_FREE_wst_Lifetime(struct zx_ctx* c, struct zx_wst_Lifetime_s* x, int free_strs)
{
  /* *** deal with xmlns specifications in exc c14n way */


  {
      struct zx_wsu_Created_s* e;
      struct zx_wsu_Created_s* en;
      for (e = x->Created; e; e = en) {
	  en = (struct zx_wsu_Created_s*)e->gg.g.n;
	  zx_FREE_wsu_Created(c, e, free_strs);
      }
  }
  {
      struct zx_wsu_Expires_s* e;
      struct zx_wsu_Expires_s* en;
      for (e = x->Expires; e; e = en) {
	  en = (struct zx_wsu_Expires_s*)e->gg.g.n;
	  zx_FREE_wsu_Expires(c, e, free_strs);
      }
  }


  zx_free_elem_common(c, &x->gg, free_strs); 
}

/* FUNC(zx_NEW_wst_Lifetime) */

/* Trivial allocator/constructor for the datatype. */

/* Called by: */
struct zx_wst_Lifetime_s* zx_NEW_wst_Lifetime(struct zx_ctx* c)
{
  struct zx_wst_Lifetime_s* x = ZX_ZALLOC(c, struct zx_wst_Lifetime_s);
  x->gg.g.tok = zx_wst_Lifetime_ELEM;
  return x;
}

#ifdef ZX_ENA_AUX

/* FUNC(zx_DUP_STRS_wst_Lifetime) */

/* Depth first traversal of data structure to copy its simple strings
 * to memory allocated from the memory allocator. The decoder will
 * use the underlying wireprotocol PDU buffer for strings, i.e.
 * strings are not copied - they point to the real data. If the
 * datastructure needs to outlast the protocol data or needs a different
 * memory allocation strategy, you need to call this function.  */

/* Called by: */
void zx_DUP_STRS_wst_Lifetime(struct zx_ctx* c, struct zx_wst_Lifetime_s* x)
{
  zx_dup_strs_common(c, &x->gg);
  /* *** deal with xmlns specifications in exc c14n way */


  {
      struct zx_wsu_Created_s* e;
      for (e = x->Created; e; e = (struct zx_wsu_Created_s*)e->gg.g.n)
	  zx_DUP_STRS_wsu_Created(c, e);
  }
  {
      struct zx_wsu_Expires_s* e;
      for (e = x->Expires; e; e = (struct zx_wsu_Expires_s*)e->gg.g.n)
	  zx_DUP_STRS_wsu_Expires(c, e);
  }

}

/* FUNC(zx_DEEP_CLONE_wst_Lifetime) */

/* Depth first traversal of data structure to clone it and its sublements.
 * The simple strings are handled as a special case according to dup_strs flag. */

/* Called by: */
struct zx_wst_Lifetime_s* zx_DEEP_CLONE_wst_Lifetime(struct zx_ctx* c, struct zx_wst_Lifetime_s* x, int dup_strs)
{
  x = (struct zx_wst_Lifetime_s*)zx_clone_elem_common(c, &x->gg, sizeof(struct zx_wst_Lifetime_s), dup_strs);
  /* *** deal with xmlns specifications in exc c14n way */


  {
      struct zx_wsu_Created_s* e;
      struct zx_wsu_Created_s* en;
      struct zx_wsu_Created_s* enn;
      for (enn = 0, e = x->Created; e; e = (struct zx_wsu_Created_s*)e->gg.g.n) {
	  en = zx_DEEP_CLONE_wsu_Created(c, e, dup_strs);
	  if (!enn)
	      x->Created = en;
	  else
	      enn->gg.g.n = &en->gg.g;
	  enn = en;
      }
  }
  {
      struct zx_wsu_Expires_s* e;
      struct zx_wsu_Expires_s* en;
      struct zx_wsu_Expires_s* enn;
      for (enn = 0, e = x->Expires; e; e = (struct zx_wsu_Expires_s*)e->gg.g.n) {
	  en = zx_DEEP_CLONE_wsu_Expires(c, e, dup_strs);
	  if (!enn)
	      x->Expires = en;
	  else
	      enn->gg.g.n = &en->gg.g;
	  enn = en;
      }
  }

  return x;
}

/* FUNC(zx_WALK_SO_wst_Lifetime) */

/* Depth first traversal of the tree in either schema order or the wire order. */
 
int zx_WALK_SO_wst_Lifetime(struct zx_ctx* c, struct zx_wst_Lifetime_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
{
  int ret = callback(&x->gg.g, ctx);
  if (ret)
    return ret;
  
  /* *** deal with xmlns specifications in exc c14n way */


  
  ret = zx_walk_so_unknown_attributes(c, &x->gg, ctx, callback); 
  if (ret)
    return ret;

  {
      struct zx_wsu_Created_s* e;
      for (e = x->Created; e; e = (struct zx_wsu_Created_s*)e->gg.g.n) {
	  ret = zx_WALK_SO_wsu_Created(c, e, ctx, callback);
	  if (ret)
	      return ret;
      }
  }
  {
      struct zx_wsu_Expires_s* e;
      for (e = x->Expires; e; e = (struct zx_wsu_Expires_s*)e->gg.g.n) {
	  ret = zx_WALK_SO_wsu_Expires(c, e, ctx, callback);
	  if (ret)
	      return ret;
      }
  }

  
  return zx_walk_so_unknown_elems_and_content(c, &x->gg, ctx, callback);
}

/* FUNC(zx_WALK_WO_wst_Lifetime) */

int zx_WALK_WO_wst_Lifetime(struct zx_ctx* c, struct zx_wst_Lifetime_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
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

#define EL_NAME   wst_OnBehalfOf
#define EL_STRUCT zx_wst_OnBehalfOf_s
#define EL_NS     wst
#define EL_TAG    OnBehalfOf

/* FUNC(zx_FREE_wst_OnBehalfOf) */

/* Depth first traversal of data structure to free it and its subelements. Simple
 * strings are handled as a special case according to the free_strs flag. This
 * is useful if the strings point to underlying data from the wire that was
 * allocated differently. */

/* Called by: */
void zx_FREE_wst_OnBehalfOf(struct zx_ctx* c, struct zx_wst_OnBehalfOf_s* x, int free_strs)
{
  /* *** deal with xmlns specifications in exc c14n way */




  zx_free_elem_common(c, &x->gg, free_strs); 
}

/* FUNC(zx_NEW_wst_OnBehalfOf) */

/* Trivial allocator/constructor for the datatype. */

/* Called by: */
struct zx_wst_OnBehalfOf_s* zx_NEW_wst_OnBehalfOf(struct zx_ctx* c)
{
  struct zx_wst_OnBehalfOf_s* x = ZX_ZALLOC(c, struct zx_wst_OnBehalfOf_s);
  x->gg.g.tok = zx_wst_OnBehalfOf_ELEM;
  return x;
}

#ifdef ZX_ENA_AUX

/* FUNC(zx_DUP_STRS_wst_OnBehalfOf) */

/* Depth first traversal of data structure to copy its simple strings
 * to memory allocated from the memory allocator. The decoder will
 * use the underlying wireprotocol PDU buffer for strings, i.e.
 * strings are not copied - they point to the real data. If the
 * datastructure needs to outlast the protocol data or needs a different
 * memory allocation strategy, you need to call this function.  */

/* Called by: */
void zx_DUP_STRS_wst_OnBehalfOf(struct zx_ctx* c, struct zx_wst_OnBehalfOf_s* x)
{
  zx_dup_strs_common(c, &x->gg);
  /* *** deal with xmlns specifications in exc c14n way */



}

/* FUNC(zx_DEEP_CLONE_wst_OnBehalfOf) */

/* Depth first traversal of data structure to clone it and its sublements.
 * The simple strings are handled as a special case according to dup_strs flag. */

/* Called by: */
struct zx_wst_OnBehalfOf_s* zx_DEEP_CLONE_wst_OnBehalfOf(struct zx_ctx* c, struct zx_wst_OnBehalfOf_s* x, int dup_strs)
{
  x = (struct zx_wst_OnBehalfOf_s*)zx_clone_elem_common(c, &x->gg, sizeof(struct zx_wst_OnBehalfOf_s), dup_strs);
  /* *** deal with xmlns specifications in exc c14n way */



  return x;
}

/* FUNC(zx_WALK_SO_wst_OnBehalfOf) */

/* Depth first traversal of the tree in either schema order or the wire order. */
 
int zx_WALK_SO_wst_OnBehalfOf(struct zx_ctx* c, struct zx_wst_OnBehalfOf_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
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

/* FUNC(zx_WALK_WO_wst_OnBehalfOf) */

int zx_WALK_WO_wst_OnBehalfOf(struct zx_ctx* c, struct zx_wst_OnBehalfOf_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
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

#define EL_NAME   wst_Participant
#define EL_STRUCT zx_wst_Participant_s
#define EL_NS     wst
#define EL_TAG    Participant

/* FUNC(zx_FREE_wst_Participant) */

/* Depth first traversal of data structure to free it and its subelements. Simple
 * strings are handled as a special case according to the free_strs flag. This
 * is useful if the strings point to underlying data from the wire that was
 * allocated differently. */

/* Called by: */
void zx_FREE_wst_Participant(struct zx_ctx* c, struct zx_wst_Participant_s* x, int free_strs)
{
  /* *** deal with xmlns specifications in exc c14n way */




  zx_free_elem_common(c, &x->gg, free_strs); 
}

/* FUNC(zx_NEW_wst_Participant) */

/* Trivial allocator/constructor for the datatype. */

/* Called by: */
struct zx_wst_Participant_s* zx_NEW_wst_Participant(struct zx_ctx* c)
{
  struct zx_wst_Participant_s* x = ZX_ZALLOC(c, struct zx_wst_Participant_s);
  x->gg.g.tok = zx_wst_Participant_ELEM;
  return x;
}

#ifdef ZX_ENA_AUX

/* FUNC(zx_DUP_STRS_wst_Participant) */

/* Depth first traversal of data structure to copy its simple strings
 * to memory allocated from the memory allocator. The decoder will
 * use the underlying wireprotocol PDU buffer for strings, i.e.
 * strings are not copied - they point to the real data. If the
 * datastructure needs to outlast the protocol data or needs a different
 * memory allocation strategy, you need to call this function.  */

/* Called by: */
void zx_DUP_STRS_wst_Participant(struct zx_ctx* c, struct zx_wst_Participant_s* x)
{
  zx_dup_strs_common(c, &x->gg);
  /* *** deal with xmlns specifications in exc c14n way */



}

/* FUNC(zx_DEEP_CLONE_wst_Participant) */

/* Depth first traversal of data structure to clone it and its sublements.
 * The simple strings are handled as a special case according to dup_strs flag. */

/* Called by: */
struct zx_wst_Participant_s* zx_DEEP_CLONE_wst_Participant(struct zx_ctx* c, struct zx_wst_Participant_s* x, int dup_strs)
{
  x = (struct zx_wst_Participant_s*)zx_clone_elem_common(c, &x->gg, sizeof(struct zx_wst_Participant_s), dup_strs);
  /* *** deal with xmlns specifications in exc c14n way */



  return x;
}

/* FUNC(zx_WALK_SO_wst_Participant) */

/* Depth first traversal of the tree in either schema order or the wire order. */
 
int zx_WALK_SO_wst_Participant(struct zx_ctx* c, struct zx_wst_Participant_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
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

/* FUNC(zx_WALK_WO_wst_Participant) */

int zx_WALK_WO_wst_Participant(struct zx_ctx* c, struct zx_wst_Participant_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
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

#define EL_NAME   wst_Participants
#define EL_STRUCT zx_wst_Participants_s
#define EL_NS     wst
#define EL_TAG    Participants

/* FUNC(zx_FREE_wst_Participants) */

/* Depth first traversal of data structure to free it and its subelements. Simple
 * strings are handled as a special case according to the free_strs flag. This
 * is useful if the strings point to underlying data from the wire that was
 * allocated differently. */

/* Called by: */
void zx_FREE_wst_Participants(struct zx_ctx* c, struct zx_wst_Participants_s* x, int free_strs)
{
  /* *** deal with xmlns specifications in exc c14n way */


  {
      struct zx_wst_Primary_s* e;
      struct zx_wst_Primary_s* en;
      for (e = x->Primary; e; e = en) {
	  en = (struct zx_wst_Primary_s*)e->gg.g.n;
	  zx_FREE_wst_Primary(c, e, free_strs);
      }
  }
  {
      struct zx_wst_Participant_s* e;
      struct zx_wst_Participant_s* en;
      for (e = x->Participant; e; e = en) {
	  en = (struct zx_wst_Participant_s*)e->gg.g.n;
	  zx_FREE_wst_Participant(c, e, free_strs);
      }
  }


  zx_free_elem_common(c, &x->gg, free_strs); 
}

/* FUNC(zx_NEW_wst_Participants) */

/* Trivial allocator/constructor for the datatype. */

/* Called by: */
struct zx_wst_Participants_s* zx_NEW_wst_Participants(struct zx_ctx* c)
{
  struct zx_wst_Participants_s* x = ZX_ZALLOC(c, struct zx_wst_Participants_s);
  x->gg.g.tok = zx_wst_Participants_ELEM;
  return x;
}

#ifdef ZX_ENA_AUX

/* FUNC(zx_DUP_STRS_wst_Participants) */

/* Depth first traversal of data structure to copy its simple strings
 * to memory allocated from the memory allocator. The decoder will
 * use the underlying wireprotocol PDU buffer for strings, i.e.
 * strings are not copied - they point to the real data. If the
 * datastructure needs to outlast the protocol data or needs a different
 * memory allocation strategy, you need to call this function.  */

/* Called by: */
void zx_DUP_STRS_wst_Participants(struct zx_ctx* c, struct zx_wst_Participants_s* x)
{
  zx_dup_strs_common(c, &x->gg);
  /* *** deal with xmlns specifications in exc c14n way */


  {
      struct zx_wst_Primary_s* e;
      for (e = x->Primary; e; e = (struct zx_wst_Primary_s*)e->gg.g.n)
	  zx_DUP_STRS_wst_Primary(c, e);
  }
  {
      struct zx_wst_Participant_s* e;
      for (e = x->Participant; e; e = (struct zx_wst_Participant_s*)e->gg.g.n)
	  zx_DUP_STRS_wst_Participant(c, e);
  }

}

/* FUNC(zx_DEEP_CLONE_wst_Participants) */

/* Depth first traversal of data structure to clone it and its sublements.
 * The simple strings are handled as a special case according to dup_strs flag. */

/* Called by: */
struct zx_wst_Participants_s* zx_DEEP_CLONE_wst_Participants(struct zx_ctx* c, struct zx_wst_Participants_s* x, int dup_strs)
{
  x = (struct zx_wst_Participants_s*)zx_clone_elem_common(c, &x->gg, sizeof(struct zx_wst_Participants_s), dup_strs);
  /* *** deal with xmlns specifications in exc c14n way */


  {
      struct zx_wst_Primary_s* e;
      struct zx_wst_Primary_s* en;
      struct zx_wst_Primary_s* enn;
      for (enn = 0, e = x->Primary; e; e = (struct zx_wst_Primary_s*)e->gg.g.n) {
	  en = zx_DEEP_CLONE_wst_Primary(c, e, dup_strs);
	  if (!enn)
	      x->Primary = en;
	  else
	      enn->gg.g.n = &en->gg.g;
	  enn = en;
      }
  }
  {
      struct zx_wst_Participant_s* e;
      struct zx_wst_Participant_s* en;
      struct zx_wst_Participant_s* enn;
      for (enn = 0, e = x->Participant; e; e = (struct zx_wst_Participant_s*)e->gg.g.n) {
	  en = zx_DEEP_CLONE_wst_Participant(c, e, dup_strs);
	  if (!enn)
	      x->Participant = en;
	  else
	      enn->gg.g.n = &en->gg.g;
	  enn = en;
      }
  }

  return x;
}

/* FUNC(zx_WALK_SO_wst_Participants) */

/* Depth first traversal of the tree in either schema order or the wire order. */
 
int zx_WALK_SO_wst_Participants(struct zx_ctx* c, struct zx_wst_Participants_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
{
  int ret = callback(&x->gg.g, ctx);
  if (ret)
    return ret;
  
  /* *** deal with xmlns specifications in exc c14n way */


  
  ret = zx_walk_so_unknown_attributes(c, &x->gg, ctx, callback); 
  if (ret)
    return ret;

  {
      struct zx_wst_Primary_s* e;
      for (e = x->Primary; e; e = (struct zx_wst_Primary_s*)e->gg.g.n) {
	  ret = zx_WALK_SO_wst_Primary(c, e, ctx, callback);
	  if (ret)
	      return ret;
      }
  }
  {
      struct zx_wst_Participant_s* e;
      for (e = x->Participant; e; e = (struct zx_wst_Participant_s*)e->gg.g.n) {
	  ret = zx_WALK_SO_wst_Participant(c, e, ctx, callback);
	  if (ret)
	      return ret;
      }
  }

  
  return zx_walk_so_unknown_elems_and_content(c, &x->gg, ctx, callback);
}

/* FUNC(zx_WALK_WO_wst_Participants) */

int zx_WALK_WO_wst_Participants(struct zx_ctx* c, struct zx_wst_Participants_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
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

#define EL_NAME   wst_Primary
#define EL_STRUCT zx_wst_Primary_s
#define EL_NS     wst
#define EL_TAG    Primary

/* FUNC(zx_FREE_wst_Primary) */

/* Depth first traversal of data structure to free it and its subelements. Simple
 * strings are handled as a special case according to the free_strs flag. This
 * is useful if the strings point to underlying data from the wire that was
 * allocated differently. */

/* Called by: */
void zx_FREE_wst_Primary(struct zx_ctx* c, struct zx_wst_Primary_s* x, int free_strs)
{
  /* *** deal with xmlns specifications in exc c14n way */




  zx_free_elem_common(c, &x->gg, free_strs); 
}

/* FUNC(zx_NEW_wst_Primary) */

/* Trivial allocator/constructor for the datatype. */

/* Called by: */
struct zx_wst_Primary_s* zx_NEW_wst_Primary(struct zx_ctx* c)
{
  struct zx_wst_Primary_s* x = ZX_ZALLOC(c, struct zx_wst_Primary_s);
  x->gg.g.tok = zx_wst_Primary_ELEM;
  return x;
}

#ifdef ZX_ENA_AUX

/* FUNC(zx_DUP_STRS_wst_Primary) */

/* Depth first traversal of data structure to copy its simple strings
 * to memory allocated from the memory allocator. The decoder will
 * use the underlying wireprotocol PDU buffer for strings, i.e.
 * strings are not copied - they point to the real data. If the
 * datastructure needs to outlast the protocol data or needs a different
 * memory allocation strategy, you need to call this function.  */

/* Called by: */
void zx_DUP_STRS_wst_Primary(struct zx_ctx* c, struct zx_wst_Primary_s* x)
{
  zx_dup_strs_common(c, &x->gg);
  /* *** deal with xmlns specifications in exc c14n way */



}

/* FUNC(zx_DEEP_CLONE_wst_Primary) */

/* Depth first traversal of data structure to clone it and its sublements.
 * The simple strings are handled as a special case according to dup_strs flag. */

/* Called by: */
struct zx_wst_Primary_s* zx_DEEP_CLONE_wst_Primary(struct zx_ctx* c, struct zx_wst_Primary_s* x, int dup_strs)
{
  x = (struct zx_wst_Primary_s*)zx_clone_elem_common(c, &x->gg, sizeof(struct zx_wst_Primary_s), dup_strs);
  /* *** deal with xmlns specifications in exc c14n way */



  return x;
}

/* FUNC(zx_WALK_SO_wst_Primary) */

/* Depth first traversal of the tree in either schema order or the wire order. */
 
int zx_WALK_SO_wst_Primary(struct zx_ctx* c, struct zx_wst_Primary_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
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

/* FUNC(zx_WALK_WO_wst_Primary) */

int zx_WALK_WO_wst_Primary(struct zx_ctx* c, struct zx_wst_Primary_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
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

#define EL_NAME   wst_ProofEncryption
#define EL_STRUCT zx_wst_ProofEncryption_s
#define EL_NS     wst
#define EL_TAG    ProofEncryption

/* FUNC(zx_FREE_wst_ProofEncryption) */

/* Depth first traversal of data structure to free it and its subelements. Simple
 * strings are handled as a special case according to the free_strs flag. This
 * is useful if the strings point to underlying data from the wire that was
 * allocated differently. */

/* Called by: */
void zx_FREE_wst_ProofEncryption(struct zx_ctx* c, struct zx_wst_ProofEncryption_s* x, int free_strs)
{
  /* *** deal with xmlns specifications in exc c14n way */




  zx_free_elem_common(c, &x->gg, free_strs); 
}

/* FUNC(zx_NEW_wst_ProofEncryption) */

/* Trivial allocator/constructor for the datatype. */

/* Called by: */
struct zx_wst_ProofEncryption_s* zx_NEW_wst_ProofEncryption(struct zx_ctx* c)
{
  struct zx_wst_ProofEncryption_s* x = ZX_ZALLOC(c, struct zx_wst_ProofEncryption_s);
  x->gg.g.tok = zx_wst_ProofEncryption_ELEM;
  return x;
}

#ifdef ZX_ENA_AUX

/* FUNC(zx_DUP_STRS_wst_ProofEncryption) */

/* Depth first traversal of data structure to copy its simple strings
 * to memory allocated from the memory allocator. The decoder will
 * use the underlying wireprotocol PDU buffer for strings, i.e.
 * strings are not copied - they point to the real data. If the
 * datastructure needs to outlast the protocol data or needs a different
 * memory allocation strategy, you need to call this function.  */

/* Called by: */
void zx_DUP_STRS_wst_ProofEncryption(struct zx_ctx* c, struct zx_wst_ProofEncryption_s* x)
{
  zx_dup_strs_common(c, &x->gg);
  /* *** deal with xmlns specifications in exc c14n way */



}

/* FUNC(zx_DEEP_CLONE_wst_ProofEncryption) */

/* Depth first traversal of data structure to clone it and its sublements.
 * The simple strings are handled as a special case according to dup_strs flag. */

/* Called by: */
struct zx_wst_ProofEncryption_s* zx_DEEP_CLONE_wst_ProofEncryption(struct zx_ctx* c, struct zx_wst_ProofEncryption_s* x, int dup_strs)
{
  x = (struct zx_wst_ProofEncryption_s*)zx_clone_elem_common(c, &x->gg, sizeof(struct zx_wst_ProofEncryption_s), dup_strs);
  /* *** deal with xmlns specifications in exc c14n way */



  return x;
}

/* FUNC(zx_WALK_SO_wst_ProofEncryption) */

/* Depth first traversal of the tree in either schema order or the wire order. */
 
int zx_WALK_SO_wst_ProofEncryption(struct zx_ctx* c, struct zx_wst_ProofEncryption_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
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

/* FUNC(zx_WALK_WO_wst_ProofEncryption) */

int zx_WALK_WO_wst_ProofEncryption(struct zx_ctx* c, struct zx_wst_ProofEncryption_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
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

#define EL_NAME   wst_RenewTarget
#define EL_STRUCT zx_wst_RenewTarget_s
#define EL_NS     wst
#define EL_TAG    RenewTarget

/* FUNC(zx_FREE_wst_RenewTarget) */

/* Depth first traversal of data structure to free it and its subelements. Simple
 * strings are handled as a special case according to the free_strs flag. This
 * is useful if the strings point to underlying data from the wire that was
 * allocated differently. */

/* Called by: */
void zx_FREE_wst_RenewTarget(struct zx_ctx* c, struct zx_wst_RenewTarget_s* x, int free_strs)
{
  /* *** deal with xmlns specifications in exc c14n way */




  zx_free_elem_common(c, &x->gg, free_strs); 
}

/* FUNC(zx_NEW_wst_RenewTarget) */

/* Trivial allocator/constructor for the datatype. */

/* Called by: */
struct zx_wst_RenewTarget_s* zx_NEW_wst_RenewTarget(struct zx_ctx* c)
{
  struct zx_wst_RenewTarget_s* x = ZX_ZALLOC(c, struct zx_wst_RenewTarget_s);
  x->gg.g.tok = zx_wst_RenewTarget_ELEM;
  return x;
}

#ifdef ZX_ENA_AUX

/* FUNC(zx_DUP_STRS_wst_RenewTarget) */

/* Depth first traversal of data structure to copy its simple strings
 * to memory allocated from the memory allocator. The decoder will
 * use the underlying wireprotocol PDU buffer for strings, i.e.
 * strings are not copied - they point to the real data. If the
 * datastructure needs to outlast the protocol data or needs a different
 * memory allocation strategy, you need to call this function.  */

/* Called by: */
void zx_DUP_STRS_wst_RenewTarget(struct zx_ctx* c, struct zx_wst_RenewTarget_s* x)
{
  zx_dup_strs_common(c, &x->gg);
  /* *** deal with xmlns specifications in exc c14n way */



}

/* FUNC(zx_DEEP_CLONE_wst_RenewTarget) */

/* Depth first traversal of data structure to clone it and its sublements.
 * The simple strings are handled as a special case according to dup_strs flag. */

/* Called by: */
struct zx_wst_RenewTarget_s* zx_DEEP_CLONE_wst_RenewTarget(struct zx_ctx* c, struct zx_wst_RenewTarget_s* x, int dup_strs)
{
  x = (struct zx_wst_RenewTarget_s*)zx_clone_elem_common(c, &x->gg, sizeof(struct zx_wst_RenewTarget_s), dup_strs);
  /* *** deal with xmlns specifications in exc c14n way */



  return x;
}

/* FUNC(zx_WALK_SO_wst_RenewTarget) */

/* Depth first traversal of the tree in either schema order or the wire order. */
 
int zx_WALK_SO_wst_RenewTarget(struct zx_ctx* c, struct zx_wst_RenewTarget_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
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

/* FUNC(zx_WALK_WO_wst_RenewTarget) */

int zx_WALK_WO_wst_RenewTarget(struct zx_ctx* c, struct zx_wst_RenewTarget_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
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

#define EL_NAME   wst_Renewing
#define EL_STRUCT zx_wst_Renewing_s
#define EL_NS     wst
#define EL_TAG    Renewing

/* FUNC(zx_FREE_wst_Renewing) */

/* Depth first traversal of data structure to free it and its subelements. Simple
 * strings are handled as a special case according to the free_strs flag. This
 * is useful if the strings point to underlying data from the wire that was
 * allocated differently. */

/* Called by: */
void zx_FREE_wst_Renewing(struct zx_ctx* c, struct zx_wst_Renewing_s* x, int free_strs)
{
  /* *** deal with xmlns specifications in exc c14n way */

  zx_free_attr(c, x->Allow, free_strs);
  zx_free_attr(c, x->OK, free_strs);



  zx_free_elem_common(c, &x->gg, free_strs); 
}

/* FUNC(zx_NEW_wst_Renewing) */

/* Trivial allocator/constructor for the datatype. */

/* Called by: */
struct zx_wst_Renewing_s* zx_NEW_wst_Renewing(struct zx_ctx* c)
{
  struct zx_wst_Renewing_s* x = ZX_ZALLOC(c, struct zx_wst_Renewing_s);
  x->gg.g.tok = zx_wst_Renewing_ELEM;
  return x;
}

#ifdef ZX_ENA_AUX

/* FUNC(zx_DUP_STRS_wst_Renewing) */

/* Depth first traversal of data structure to copy its simple strings
 * to memory allocated from the memory allocator. The decoder will
 * use the underlying wireprotocol PDU buffer for strings, i.e.
 * strings are not copied - they point to the real data. If the
 * datastructure needs to outlast the protocol data or needs a different
 * memory allocation strategy, you need to call this function.  */

/* Called by: */
void zx_DUP_STRS_wst_Renewing(struct zx_ctx* c, struct zx_wst_Renewing_s* x)
{
  zx_dup_strs_common(c, &x->gg);
  /* *** deal with xmlns specifications in exc c14n way */

  zx_dup_attr(c, x->Allow);
  zx_dup_attr(c, x->OK);


}

/* FUNC(zx_DEEP_CLONE_wst_Renewing) */

/* Depth first traversal of data structure to clone it and its sublements.
 * The simple strings are handled as a special case according to dup_strs flag. */

/* Called by: */
struct zx_wst_Renewing_s* zx_DEEP_CLONE_wst_Renewing(struct zx_ctx* c, struct zx_wst_Renewing_s* x, int dup_strs)
{
  x = (struct zx_wst_Renewing_s*)zx_clone_elem_common(c, &x->gg, sizeof(struct zx_wst_Renewing_s), dup_strs);
  /* *** deal with xmlns specifications in exc c14n way */

  x->Allow = zx_clone_attr(c, x->Allow);
  x->OK = zx_clone_attr(c, x->OK);


  return x;
}

/* FUNC(zx_WALK_SO_wst_Renewing) */

/* Depth first traversal of the tree in either schema order or the wire order. */
 
int zx_WALK_SO_wst_Renewing(struct zx_ctx* c, struct zx_wst_Renewing_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
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

/* FUNC(zx_WALK_WO_wst_Renewing) */

int zx_WALK_WO_wst_Renewing(struct zx_ctx* c, struct zx_wst_Renewing_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
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

#define EL_NAME   wst_RequestSecurityToken
#define EL_STRUCT zx_wst_RequestSecurityToken_s
#define EL_NS     wst
#define EL_TAG    RequestSecurityToken

/* FUNC(zx_FREE_wst_RequestSecurityToken) */

/* Depth first traversal of data structure to free it and its subelements. Simple
 * strings are handled as a special case according to the free_strs flag. This
 * is useful if the strings point to underlying data from the wire that was
 * allocated differently. */

/* Called by: */
void zx_FREE_wst_RequestSecurityToken(struct zx_ctx* c, struct zx_wst_RequestSecurityToken_s* x, int free_strs)
{
  /* *** deal with xmlns specifications in exc c14n way */

  zx_free_attr(c, x->Context, free_strs);

  zx_free_simple_elems(c, x->TokenType, free_strs);
  zx_free_simple_elems(c, x->RequestType, free_strs);
  {
      struct zx_wsp_AppliesTo_s* e;
      struct zx_wsp_AppliesTo_s* en;
      for (e = x->AppliesTo; e; e = en) {
	  en = (struct zx_wsp_AppliesTo_s*)e->gg.g.n;
	  zx_FREE_wsp_AppliesTo(c, e, free_strs);
      }
  }
  {
      struct zx_wst_Claims_s* e;
      struct zx_wst_Claims_s* en;
      for (e = x->Claims; e; e = en) {
	  en = (struct zx_wst_Claims_s*)e->gg.g.n;
	  zx_FREE_wst_Claims(c, e, free_strs);
      }
  }
  {
      struct zx_wst_Entropy_s* e;
      struct zx_wst_Entropy_s* en;
      for (e = x->Entropy; e; e = en) {
	  en = (struct zx_wst_Entropy_s*)e->gg.g.n;
	  zx_FREE_wst_Entropy(c, e, free_strs);
      }
  }
  {
      struct zx_wst_Lifetime_s* e;
      struct zx_wst_Lifetime_s* en;
      for (e = x->Lifetime; e; e = en) {
	  en = (struct zx_wst_Lifetime_s*)e->gg.g.n;
	  zx_FREE_wst_Lifetime(c, e, free_strs);
      }
  }
  zx_free_simple_elems(c, x->AllowPostdating, free_strs);
  {
      struct zx_wst_Renewing_s* e;
      struct zx_wst_Renewing_s* en;
      for (e = x->Renewing; e; e = en) {
	  en = (struct zx_wst_Renewing_s*)e->gg.g.n;
	  zx_FREE_wst_Renewing(c, e, free_strs);
      }
  }
  {
      struct zx_wst_OnBehalfOf_s* e;
      struct zx_wst_OnBehalfOf_s* en;
      for (e = x->OnBehalfOf; e; e = en) {
	  en = (struct zx_wst_OnBehalfOf_s*)e->gg.g.n;
	  zx_FREE_wst_OnBehalfOf(c, e, free_strs);
      }
  }
  {
      struct zx_wst_Issuer_s* e;
      struct zx_wst_Issuer_s* en;
      for (e = x->Issuer; e; e = en) {
	  en = (struct zx_wst_Issuer_s*)e->gg.g.n;
	  zx_FREE_wst_Issuer(c, e, free_strs);
      }
  }
  zx_free_simple_elems(c, x->AuthenticationType, free_strs);
  zx_free_simple_elems(c, x->KeyType, free_strs);
  zx_free_simple_elems(c, x->KeySize, free_strs);
  zx_free_simple_elems(c, x->SignatureAlgorithm, free_strs);
  {
      struct zx_wst_Encryption_s* e;
      struct zx_wst_Encryption_s* en;
      for (e = x->Encryption; e; e = en) {
	  en = (struct zx_wst_Encryption_s*)e->gg.g.n;
	  zx_FREE_wst_Encryption(c, e, free_strs);
      }
  }
  zx_free_simple_elems(c, x->EncryptionAlgorithm, free_strs);
  zx_free_simple_elems(c, x->CanonicalizationAlgorithm, free_strs);
  {
      struct zx_wst_ProofEncryption_s* e;
      struct zx_wst_ProofEncryption_s* en;
      for (e = x->ProofEncryption; e; e = en) {
	  en = (struct zx_wst_ProofEncryption_s*)e->gg.g.n;
	  zx_FREE_wst_ProofEncryption(c, e, free_strs);
      }
  }
  {
      struct zx_wst_UseKey_s* e;
      struct zx_wst_UseKey_s* en;
      for (e = x->UseKey; e; e = en) {
	  en = (struct zx_wst_UseKey_s*)e->gg.g.n;
	  zx_FREE_wst_UseKey(c, e, free_strs);
      }
  }
  zx_free_simple_elems(c, x->SignWith, free_strs);
  zx_free_simple_elems(c, x->EncryptWith, free_strs);
  {
      struct zx_wst_DelegateTo_s* e;
      struct zx_wst_DelegateTo_s* en;
      for (e = x->DelegateTo; e; e = en) {
	  en = (struct zx_wst_DelegateTo_s*)e->gg.g.n;
	  zx_FREE_wst_DelegateTo(c, e, free_strs);
      }
  }
  zx_free_simple_elems(c, x->Forwardable, free_strs);
  zx_free_simple_elems(c, x->Delegatable, free_strs);
  {
      struct zx_wsp_Policy_s* e;
      struct zx_wsp_Policy_s* en;
      for (e = x->Policy; e; e = en) {
	  en = (struct zx_wsp_Policy_s*)e->gg.g.n;
	  zx_FREE_wsp_Policy(c, e, free_strs);
      }
  }
  {
      struct zx_wsp_PolicyReference_s* e;
      struct zx_wsp_PolicyReference_s* en;
      for (e = x->PolicyReference; e; e = en) {
	  en = (struct zx_wsp_PolicyReference_s*)e->gg.g.n;
	  zx_FREE_wsp_PolicyReference(c, e, free_strs);
      }
  }


  zx_free_elem_common(c, &x->gg, free_strs); 
}

/* FUNC(zx_NEW_wst_RequestSecurityToken) */

/* Trivial allocator/constructor for the datatype. */

/* Called by: */
struct zx_wst_RequestSecurityToken_s* zx_NEW_wst_RequestSecurityToken(struct zx_ctx* c)
{
  struct zx_wst_RequestSecurityToken_s* x = ZX_ZALLOC(c, struct zx_wst_RequestSecurityToken_s);
  x->gg.g.tok = zx_wst_RequestSecurityToken_ELEM;
  return x;
}

#ifdef ZX_ENA_AUX

/* FUNC(zx_DUP_STRS_wst_RequestSecurityToken) */

/* Depth first traversal of data structure to copy its simple strings
 * to memory allocated from the memory allocator. The decoder will
 * use the underlying wireprotocol PDU buffer for strings, i.e.
 * strings are not copied - they point to the real data. If the
 * datastructure needs to outlast the protocol data or needs a different
 * memory allocation strategy, you need to call this function.  */

/* Called by: */
void zx_DUP_STRS_wst_RequestSecurityToken(struct zx_ctx* c, struct zx_wst_RequestSecurityToken_s* x)
{
  zx_dup_strs_common(c, &x->gg);
  /* *** deal with xmlns specifications in exc c14n way */

  zx_dup_attr(c, x->Context);

  zx_dup_strs_simple_elems(c, x->TokenType);
  zx_dup_strs_simple_elems(c, x->RequestType);
  {
      struct zx_wsp_AppliesTo_s* e;
      for (e = x->AppliesTo; e; e = (struct zx_wsp_AppliesTo_s*)e->gg.g.n)
	  zx_DUP_STRS_wsp_AppliesTo(c, e);
  }
  {
      struct zx_wst_Claims_s* e;
      for (e = x->Claims; e; e = (struct zx_wst_Claims_s*)e->gg.g.n)
	  zx_DUP_STRS_wst_Claims(c, e);
  }
  {
      struct zx_wst_Entropy_s* e;
      for (e = x->Entropy; e; e = (struct zx_wst_Entropy_s*)e->gg.g.n)
	  zx_DUP_STRS_wst_Entropy(c, e);
  }
  {
      struct zx_wst_Lifetime_s* e;
      for (e = x->Lifetime; e; e = (struct zx_wst_Lifetime_s*)e->gg.g.n)
	  zx_DUP_STRS_wst_Lifetime(c, e);
  }
  zx_dup_strs_simple_elems(c, x->AllowPostdating);
  {
      struct zx_wst_Renewing_s* e;
      for (e = x->Renewing; e; e = (struct zx_wst_Renewing_s*)e->gg.g.n)
	  zx_DUP_STRS_wst_Renewing(c, e);
  }
  {
      struct zx_wst_OnBehalfOf_s* e;
      for (e = x->OnBehalfOf; e; e = (struct zx_wst_OnBehalfOf_s*)e->gg.g.n)
	  zx_DUP_STRS_wst_OnBehalfOf(c, e);
  }
  {
      struct zx_wst_Issuer_s* e;
      for (e = x->Issuer; e; e = (struct zx_wst_Issuer_s*)e->gg.g.n)
	  zx_DUP_STRS_wst_Issuer(c, e);
  }
  zx_dup_strs_simple_elems(c, x->AuthenticationType);
  zx_dup_strs_simple_elems(c, x->KeyType);
  zx_dup_strs_simple_elems(c, x->KeySize);
  zx_dup_strs_simple_elems(c, x->SignatureAlgorithm);
  {
      struct zx_wst_Encryption_s* e;
      for (e = x->Encryption; e; e = (struct zx_wst_Encryption_s*)e->gg.g.n)
	  zx_DUP_STRS_wst_Encryption(c, e);
  }
  zx_dup_strs_simple_elems(c, x->EncryptionAlgorithm);
  zx_dup_strs_simple_elems(c, x->CanonicalizationAlgorithm);
  {
      struct zx_wst_ProofEncryption_s* e;
      for (e = x->ProofEncryption; e; e = (struct zx_wst_ProofEncryption_s*)e->gg.g.n)
	  zx_DUP_STRS_wst_ProofEncryption(c, e);
  }
  {
      struct zx_wst_UseKey_s* e;
      for (e = x->UseKey; e; e = (struct zx_wst_UseKey_s*)e->gg.g.n)
	  zx_DUP_STRS_wst_UseKey(c, e);
  }
  zx_dup_strs_simple_elems(c, x->SignWith);
  zx_dup_strs_simple_elems(c, x->EncryptWith);
  {
      struct zx_wst_DelegateTo_s* e;
      for (e = x->DelegateTo; e; e = (struct zx_wst_DelegateTo_s*)e->gg.g.n)
	  zx_DUP_STRS_wst_DelegateTo(c, e);
  }
  zx_dup_strs_simple_elems(c, x->Forwardable);
  zx_dup_strs_simple_elems(c, x->Delegatable);
  {
      struct zx_wsp_Policy_s* e;
      for (e = x->Policy; e; e = (struct zx_wsp_Policy_s*)e->gg.g.n)
	  zx_DUP_STRS_wsp_Policy(c, e);
  }
  {
      struct zx_wsp_PolicyReference_s* e;
      for (e = x->PolicyReference; e; e = (struct zx_wsp_PolicyReference_s*)e->gg.g.n)
	  zx_DUP_STRS_wsp_PolicyReference(c, e);
  }

}

/* FUNC(zx_DEEP_CLONE_wst_RequestSecurityToken) */

/* Depth first traversal of data structure to clone it and its sublements.
 * The simple strings are handled as a special case according to dup_strs flag. */

/* Called by: */
struct zx_wst_RequestSecurityToken_s* zx_DEEP_CLONE_wst_RequestSecurityToken(struct zx_ctx* c, struct zx_wst_RequestSecurityToken_s* x, int dup_strs)
{
  x = (struct zx_wst_RequestSecurityToken_s*)zx_clone_elem_common(c, &x->gg, sizeof(struct zx_wst_RequestSecurityToken_s), dup_strs);
  /* *** deal with xmlns specifications in exc c14n way */

  x->Context = zx_clone_attr(c, x->Context);

  x->TokenType = zx_deep_clone_simple_elems(c,x->TokenType, dup_strs);
  x->RequestType = zx_deep_clone_simple_elems(c,x->RequestType, dup_strs);
  {
      struct zx_wsp_AppliesTo_s* e;
      struct zx_wsp_AppliesTo_s* en;
      struct zx_wsp_AppliesTo_s* enn;
      for (enn = 0, e = x->AppliesTo; e; e = (struct zx_wsp_AppliesTo_s*)e->gg.g.n) {
	  en = zx_DEEP_CLONE_wsp_AppliesTo(c, e, dup_strs);
	  if (!enn)
	      x->AppliesTo = en;
	  else
	      enn->gg.g.n = &en->gg.g;
	  enn = en;
      }
  }
  {
      struct zx_wst_Claims_s* e;
      struct zx_wst_Claims_s* en;
      struct zx_wst_Claims_s* enn;
      for (enn = 0, e = x->Claims; e; e = (struct zx_wst_Claims_s*)e->gg.g.n) {
	  en = zx_DEEP_CLONE_wst_Claims(c, e, dup_strs);
	  if (!enn)
	      x->Claims = en;
	  else
	      enn->gg.g.n = &en->gg.g;
	  enn = en;
      }
  }
  {
      struct zx_wst_Entropy_s* e;
      struct zx_wst_Entropy_s* en;
      struct zx_wst_Entropy_s* enn;
      for (enn = 0, e = x->Entropy; e; e = (struct zx_wst_Entropy_s*)e->gg.g.n) {
	  en = zx_DEEP_CLONE_wst_Entropy(c, e, dup_strs);
	  if (!enn)
	      x->Entropy = en;
	  else
	      enn->gg.g.n = &en->gg.g;
	  enn = en;
      }
  }
  {
      struct zx_wst_Lifetime_s* e;
      struct zx_wst_Lifetime_s* en;
      struct zx_wst_Lifetime_s* enn;
      for (enn = 0, e = x->Lifetime; e; e = (struct zx_wst_Lifetime_s*)e->gg.g.n) {
	  en = zx_DEEP_CLONE_wst_Lifetime(c, e, dup_strs);
	  if (!enn)
	      x->Lifetime = en;
	  else
	      enn->gg.g.n = &en->gg.g;
	  enn = en;
      }
  }
  x->AllowPostdating = zx_deep_clone_simple_elems(c,x->AllowPostdating, dup_strs);
  {
      struct zx_wst_Renewing_s* e;
      struct zx_wst_Renewing_s* en;
      struct zx_wst_Renewing_s* enn;
      for (enn = 0, e = x->Renewing; e; e = (struct zx_wst_Renewing_s*)e->gg.g.n) {
	  en = zx_DEEP_CLONE_wst_Renewing(c, e, dup_strs);
	  if (!enn)
	      x->Renewing = en;
	  else
	      enn->gg.g.n = &en->gg.g;
	  enn = en;
      }
  }
  {
      struct zx_wst_OnBehalfOf_s* e;
      struct zx_wst_OnBehalfOf_s* en;
      struct zx_wst_OnBehalfOf_s* enn;
      for (enn = 0, e = x->OnBehalfOf; e; e = (struct zx_wst_OnBehalfOf_s*)e->gg.g.n) {
	  en = zx_DEEP_CLONE_wst_OnBehalfOf(c, e, dup_strs);
	  if (!enn)
	      x->OnBehalfOf = en;
	  else
	      enn->gg.g.n = &en->gg.g;
	  enn = en;
      }
  }
  {
      struct zx_wst_Issuer_s* e;
      struct zx_wst_Issuer_s* en;
      struct zx_wst_Issuer_s* enn;
      for (enn = 0, e = x->Issuer; e; e = (struct zx_wst_Issuer_s*)e->gg.g.n) {
	  en = zx_DEEP_CLONE_wst_Issuer(c, e, dup_strs);
	  if (!enn)
	      x->Issuer = en;
	  else
	      enn->gg.g.n = &en->gg.g;
	  enn = en;
      }
  }
  x->AuthenticationType = zx_deep_clone_simple_elems(c,x->AuthenticationType, dup_strs);
  x->KeyType = zx_deep_clone_simple_elems(c,x->KeyType, dup_strs);
  x->KeySize = zx_deep_clone_simple_elems(c,x->KeySize, dup_strs);
  x->SignatureAlgorithm = zx_deep_clone_simple_elems(c,x->SignatureAlgorithm, dup_strs);
  {
      struct zx_wst_Encryption_s* e;
      struct zx_wst_Encryption_s* en;
      struct zx_wst_Encryption_s* enn;
      for (enn = 0, e = x->Encryption; e; e = (struct zx_wst_Encryption_s*)e->gg.g.n) {
	  en = zx_DEEP_CLONE_wst_Encryption(c, e, dup_strs);
	  if (!enn)
	      x->Encryption = en;
	  else
	      enn->gg.g.n = &en->gg.g;
	  enn = en;
      }
  }
  x->EncryptionAlgorithm = zx_deep_clone_simple_elems(c,x->EncryptionAlgorithm, dup_strs);
  x->CanonicalizationAlgorithm = zx_deep_clone_simple_elems(c,x->CanonicalizationAlgorithm, dup_strs);
  {
      struct zx_wst_ProofEncryption_s* e;
      struct zx_wst_ProofEncryption_s* en;
      struct zx_wst_ProofEncryption_s* enn;
      for (enn = 0, e = x->ProofEncryption; e; e = (struct zx_wst_ProofEncryption_s*)e->gg.g.n) {
	  en = zx_DEEP_CLONE_wst_ProofEncryption(c, e, dup_strs);
	  if (!enn)
	      x->ProofEncryption = en;
	  else
	      enn->gg.g.n = &en->gg.g;
	  enn = en;
      }
  }
  {
      struct zx_wst_UseKey_s* e;
      struct zx_wst_UseKey_s* en;
      struct zx_wst_UseKey_s* enn;
      for (enn = 0, e = x->UseKey; e; e = (struct zx_wst_UseKey_s*)e->gg.g.n) {
	  en = zx_DEEP_CLONE_wst_UseKey(c, e, dup_strs);
	  if (!enn)
	      x->UseKey = en;
	  else
	      enn->gg.g.n = &en->gg.g;
	  enn = en;
      }
  }
  x->SignWith = zx_deep_clone_simple_elems(c,x->SignWith, dup_strs);
  x->EncryptWith = zx_deep_clone_simple_elems(c,x->EncryptWith, dup_strs);
  {
      struct zx_wst_DelegateTo_s* e;
      struct zx_wst_DelegateTo_s* en;
      struct zx_wst_DelegateTo_s* enn;
      for (enn = 0, e = x->DelegateTo; e; e = (struct zx_wst_DelegateTo_s*)e->gg.g.n) {
	  en = zx_DEEP_CLONE_wst_DelegateTo(c, e, dup_strs);
	  if (!enn)
	      x->DelegateTo = en;
	  else
	      enn->gg.g.n = &en->gg.g;
	  enn = en;
      }
  }
  x->Forwardable = zx_deep_clone_simple_elems(c,x->Forwardable, dup_strs);
  x->Delegatable = zx_deep_clone_simple_elems(c,x->Delegatable, dup_strs);
  {
      struct zx_wsp_Policy_s* e;
      struct zx_wsp_Policy_s* en;
      struct zx_wsp_Policy_s* enn;
      for (enn = 0, e = x->Policy; e; e = (struct zx_wsp_Policy_s*)e->gg.g.n) {
	  en = zx_DEEP_CLONE_wsp_Policy(c, e, dup_strs);
	  if (!enn)
	      x->Policy = en;
	  else
	      enn->gg.g.n = &en->gg.g;
	  enn = en;
      }
  }
  {
      struct zx_wsp_PolicyReference_s* e;
      struct zx_wsp_PolicyReference_s* en;
      struct zx_wsp_PolicyReference_s* enn;
      for (enn = 0, e = x->PolicyReference; e; e = (struct zx_wsp_PolicyReference_s*)e->gg.g.n) {
	  en = zx_DEEP_CLONE_wsp_PolicyReference(c, e, dup_strs);
	  if (!enn)
	      x->PolicyReference = en;
	  else
	      enn->gg.g.n = &en->gg.g;
	  enn = en;
      }
  }

  return x;
}

/* FUNC(zx_WALK_SO_wst_RequestSecurityToken) */

/* Depth first traversal of the tree in either schema order or the wire order. */
 
int zx_WALK_SO_wst_RequestSecurityToken(struct zx_ctx* c, struct zx_wst_RequestSecurityToken_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
{
  int ret = callback(&x->gg.g, ctx);
  if (ret)
    return ret;
  
  /* *** deal with xmlns specifications in exc c14n way */


  
  ret = zx_walk_so_unknown_attributes(c, &x->gg, ctx, callback); 
  if (ret)
    return ret;

  ret = zx_walk_so_simple_elems(c, x->TokenType, ctx, callback);
  if (ret)
    return ret;
  ret = zx_walk_so_simple_elems(c, x->RequestType, ctx, callback);
  if (ret)
    return ret;
  {
      struct zx_wsp_AppliesTo_s* e;
      for (e = x->AppliesTo; e; e = (struct zx_wsp_AppliesTo_s*)e->gg.g.n) {
	  ret = zx_WALK_SO_wsp_AppliesTo(c, e, ctx, callback);
	  if (ret)
	      return ret;
      }
  }
  {
      struct zx_wst_Claims_s* e;
      for (e = x->Claims; e; e = (struct zx_wst_Claims_s*)e->gg.g.n) {
	  ret = zx_WALK_SO_wst_Claims(c, e, ctx, callback);
	  if (ret)
	      return ret;
      }
  }
  {
      struct zx_wst_Entropy_s* e;
      for (e = x->Entropy; e; e = (struct zx_wst_Entropy_s*)e->gg.g.n) {
	  ret = zx_WALK_SO_wst_Entropy(c, e, ctx, callback);
	  if (ret)
	      return ret;
      }
  }
  {
      struct zx_wst_Lifetime_s* e;
      for (e = x->Lifetime; e; e = (struct zx_wst_Lifetime_s*)e->gg.g.n) {
	  ret = zx_WALK_SO_wst_Lifetime(c, e, ctx, callback);
	  if (ret)
	      return ret;
      }
  }
  ret = zx_walk_so_simple_elems(c, x->AllowPostdating, ctx, callback);
  if (ret)
    return ret;
  {
      struct zx_wst_Renewing_s* e;
      for (e = x->Renewing; e; e = (struct zx_wst_Renewing_s*)e->gg.g.n) {
	  ret = zx_WALK_SO_wst_Renewing(c, e, ctx, callback);
	  if (ret)
	      return ret;
      }
  }
  {
      struct zx_wst_OnBehalfOf_s* e;
      for (e = x->OnBehalfOf; e; e = (struct zx_wst_OnBehalfOf_s*)e->gg.g.n) {
	  ret = zx_WALK_SO_wst_OnBehalfOf(c, e, ctx, callback);
	  if (ret)
	      return ret;
      }
  }
  {
      struct zx_wst_Issuer_s* e;
      for (e = x->Issuer; e; e = (struct zx_wst_Issuer_s*)e->gg.g.n) {
	  ret = zx_WALK_SO_wst_Issuer(c, e, ctx, callback);
	  if (ret)
	      return ret;
      }
  }
  ret = zx_walk_so_simple_elems(c, x->AuthenticationType, ctx, callback);
  if (ret)
    return ret;
  ret = zx_walk_so_simple_elems(c, x->KeyType, ctx, callback);
  if (ret)
    return ret;
  ret = zx_walk_so_simple_elems(c, x->KeySize, ctx, callback);
  if (ret)
    return ret;
  ret = zx_walk_so_simple_elems(c, x->SignatureAlgorithm, ctx, callback);
  if (ret)
    return ret;
  {
      struct zx_wst_Encryption_s* e;
      for (e = x->Encryption; e; e = (struct zx_wst_Encryption_s*)e->gg.g.n) {
	  ret = zx_WALK_SO_wst_Encryption(c, e, ctx, callback);
	  if (ret)
	      return ret;
      }
  }
  ret = zx_walk_so_simple_elems(c, x->EncryptionAlgorithm, ctx, callback);
  if (ret)
    return ret;
  ret = zx_walk_so_simple_elems(c, x->CanonicalizationAlgorithm, ctx, callback);
  if (ret)
    return ret;
  {
      struct zx_wst_ProofEncryption_s* e;
      for (e = x->ProofEncryption; e; e = (struct zx_wst_ProofEncryption_s*)e->gg.g.n) {
	  ret = zx_WALK_SO_wst_ProofEncryption(c, e, ctx, callback);
	  if (ret)
	      return ret;
      }
  }
  {
      struct zx_wst_UseKey_s* e;
      for (e = x->UseKey; e; e = (struct zx_wst_UseKey_s*)e->gg.g.n) {
	  ret = zx_WALK_SO_wst_UseKey(c, e, ctx, callback);
	  if (ret)
	      return ret;
      }
  }
  ret = zx_walk_so_simple_elems(c, x->SignWith, ctx, callback);
  if (ret)
    return ret;
  ret = zx_walk_so_simple_elems(c, x->EncryptWith, ctx, callback);
  if (ret)
    return ret;
  {
      struct zx_wst_DelegateTo_s* e;
      for (e = x->DelegateTo; e; e = (struct zx_wst_DelegateTo_s*)e->gg.g.n) {
	  ret = zx_WALK_SO_wst_DelegateTo(c, e, ctx, callback);
	  if (ret)
	      return ret;
      }
  }
  ret = zx_walk_so_simple_elems(c, x->Forwardable, ctx, callback);
  if (ret)
    return ret;
  ret = zx_walk_so_simple_elems(c, x->Delegatable, ctx, callback);
  if (ret)
    return ret;
  {
      struct zx_wsp_Policy_s* e;
      for (e = x->Policy; e; e = (struct zx_wsp_Policy_s*)e->gg.g.n) {
	  ret = zx_WALK_SO_wsp_Policy(c, e, ctx, callback);
	  if (ret)
	      return ret;
      }
  }
  {
      struct zx_wsp_PolicyReference_s* e;
      for (e = x->PolicyReference; e; e = (struct zx_wsp_PolicyReference_s*)e->gg.g.n) {
	  ret = zx_WALK_SO_wsp_PolicyReference(c, e, ctx, callback);
	  if (ret)
	      return ret;
      }
  }

  
  return zx_walk_so_unknown_elems_and_content(c, &x->gg, ctx, callback);
}

/* FUNC(zx_WALK_WO_wst_RequestSecurityToken) */

int zx_WALK_WO_wst_RequestSecurityToken(struct zx_ctx* c, struct zx_wst_RequestSecurityToken_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
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

#define EL_NAME   wst_RequestSecurityTokenCollection
#define EL_STRUCT zx_wst_RequestSecurityTokenCollection_s
#define EL_NS     wst
#define EL_TAG    RequestSecurityTokenCollection

/* FUNC(zx_FREE_wst_RequestSecurityTokenCollection) */

/* Depth first traversal of data structure to free it and its subelements. Simple
 * strings are handled as a special case according to the free_strs flag. This
 * is useful if the strings point to underlying data from the wire that was
 * allocated differently. */

/* Called by: */
void zx_FREE_wst_RequestSecurityTokenCollection(struct zx_ctx* c, struct zx_wst_RequestSecurityTokenCollection_s* x, int free_strs)
{
  /* *** deal with xmlns specifications in exc c14n way */


  {
      struct zx_wst_RequestSecurityToken_s* e;
      struct zx_wst_RequestSecurityToken_s* en;
      for (e = x->RequestSecurityToken; e; e = en) {
	  en = (struct zx_wst_RequestSecurityToken_s*)e->gg.g.n;
	  zx_FREE_wst_RequestSecurityToken(c, e, free_strs);
      }
  }


  zx_free_elem_common(c, &x->gg, free_strs); 
}

/* FUNC(zx_NEW_wst_RequestSecurityTokenCollection) */

/* Trivial allocator/constructor for the datatype. */

/* Called by: */
struct zx_wst_RequestSecurityTokenCollection_s* zx_NEW_wst_RequestSecurityTokenCollection(struct zx_ctx* c)
{
  struct zx_wst_RequestSecurityTokenCollection_s* x = ZX_ZALLOC(c, struct zx_wst_RequestSecurityTokenCollection_s);
  x->gg.g.tok = zx_wst_RequestSecurityTokenCollection_ELEM;
  return x;
}

#ifdef ZX_ENA_AUX

/* FUNC(zx_DUP_STRS_wst_RequestSecurityTokenCollection) */

/* Depth first traversal of data structure to copy its simple strings
 * to memory allocated from the memory allocator. The decoder will
 * use the underlying wireprotocol PDU buffer for strings, i.e.
 * strings are not copied - they point to the real data. If the
 * datastructure needs to outlast the protocol data or needs a different
 * memory allocation strategy, you need to call this function.  */

/* Called by: */
void zx_DUP_STRS_wst_RequestSecurityTokenCollection(struct zx_ctx* c, struct zx_wst_RequestSecurityTokenCollection_s* x)
{
  zx_dup_strs_common(c, &x->gg);
  /* *** deal with xmlns specifications in exc c14n way */


  {
      struct zx_wst_RequestSecurityToken_s* e;
      for (e = x->RequestSecurityToken; e; e = (struct zx_wst_RequestSecurityToken_s*)e->gg.g.n)
	  zx_DUP_STRS_wst_RequestSecurityToken(c, e);
  }

}

/* FUNC(zx_DEEP_CLONE_wst_RequestSecurityTokenCollection) */

/* Depth first traversal of data structure to clone it and its sublements.
 * The simple strings are handled as a special case according to dup_strs flag. */

/* Called by: */
struct zx_wst_RequestSecurityTokenCollection_s* zx_DEEP_CLONE_wst_RequestSecurityTokenCollection(struct zx_ctx* c, struct zx_wst_RequestSecurityTokenCollection_s* x, int dup_strs)
{
  x = (struct zx_wst_RequestSecurityTokenCollection_s*)zx_clone_elem_common(c, &x->gg, sizeof(struct zx_wst_RequestSecurityTokenCollection_s), dup_strs);
  /* *** deal with xmlns specifications in exc c14n way */


  {
      struct zx_wst_RequestSecurityToken_s* e;
      struct zx_wst_RequestSecurityToken_s* en;
      struct zx_wst_RequestSecurityToken_s* enn;
      for (enn = 0, e = x->RequestSecurityToken; e; e = (struct zx_wst_RequestSecurityToken_s*)e->gg.g.n) {
	  en = zx_DEEP_CLONE_wst_RequestSecurityToken(c, e, dup_strs);
	  if (!enn)
	      x->RequestSecurityToken = en;
	  else
	      enn->gg.g.n = &en->gg.g;
	  enn = en;
      }
  }

  return x;
}

/* FUNC(zx_WALK_SO_wst_RequestSecurityTokenCollection) */

/* Depth first traversal of the tree in either schema order or the wire order. */
 
int zx_WALK_SO_wst_RequestSecurityTokenCollection(struct zx_ctx* c, struct zx_wst_RequestSecurityTokenCollection_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
{
  int ret = callback(&x->gg.g, ctx);
  if (ret)
    return ret;
  
  /* *** deal with xmlns specifications in exc c14n way */


  
  ret = zx_walk_so_unknown_attributes(c, &x->gg, ctx, callback); 
  if (ret)
    return ret;

  {
      struct zx_wst_RequestSecurityToken_s* e;
      for (e = x->RequestSecurityToken; e; e = (struct zx_wst_RequestSecurityToken_s*)e->gg.g.n) {
	  ret = zx_WALK_SO_wst_RequestSecurityToken(c, e, ctx, callback);
	  if (ret)
	      return ret;
      }
  }

  
  return zx_walk_so_unknown_elems_and_content(c, &x->gg, ctx, callback);
}

/* FUNC(zx_WALK_WO_wst_RequestSecurityTokenCollection) */

int zx_WALK_WO_wst_RequestSecurityTokenCollection(struct zx_ctx* c, struct zx_wst_RequestSecurityTokenCollection_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
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

#define EL_NAME   wst_RequestSecurityTokenResponse
#define EL_STRUCT zx_wst_RequestSecurityTokenResponse_s
#define EL_NS     wst
#define EL_TAG    RequestSecurityTokenResponse

/* FUNC(zx_FREE_wst_RequestSecurityTokenResponse) */

/* Depth first traversal of data structure to free it and its subelements. Simple
 * strings are handled as a special case according to the free_strs flag. This
 * is useful if the strings point to underlying data from the wire that was
 * allocated differently. */

/* Called by: */
void zx_FREE_wst_RequestSecurityTokenResponse(struct zx_ctx* c, struct zx_wst_RequestSecurityTokenResponse_s* x, int free_strs)
{
  /* *** deal with xmlns specifications in exc c14n way */

  zx_free_attr(c, x->Context, free_strs);

  zx_free_simple_elems(c, x->TokenType, free_strs);
  zx_free_simple_elems(c, x->RequestType, free_strs);
  {
      struct zx_wst_RequestedSecurityToken_s* e;
      struct zx_wst_RequestedSecurityToken_s* en;
      for (e = x->RequestedSecurityToken; e; e = en) {
	  en = (struct zx_wst_RequestedSecurityToken_s*)e->gg.g.n;
	  zx_FREE_wst_RequestedSecurityToken(c, e, free_strs);
      }
  }
  {
      struct zx_wsp_AppliesTo_s* e;
      struct zx_wsp_AppliesTo_s* en;
      for (e = x->AppliesTo; e; e = en) {
	  en = (struct zx_wsp_AppliesTo_s*)e->gg.g.n;
	  zx_FREE_wsp_AppliesTo(c, e, free_strs);
      }
  }
  {
      struct zx_wst_RequestedAttachedReference_s* e;
      struct zx_wst_RequestedAttachedReference_s* en;
      for (e = x->RequestedAttachedReference; e; e = en) {
	  en = (struct zx_wst_RequestedAttachedReference_s*)e->gg.g.n;
	  zx_FREE_wst_RequestedAttachedReference(c, e, free_strs);
      }
  }
  {
      struct zx_wst_RequestedUnattachedReference_s* e;
      struct zx_wst_RequestedUnattachedReference_s* en;
      for (e = x->RequestedUnattachedReference; e; e = en) {
	  en = (struct zx_wst_RequestedUnattachedReference_s*)e->gg.g.n;
	  zx_FREE_wst_RequestedUnattachedReference(c, e, free_strs);
      }
  }
  {
      struct zx_wst_RequestedProofToken_s* e;
      struct zx_wst_RequestedProofToken_s* en;
      for (e = x->RequestedProofToken; e; e = en) {
	  en = (struct zx_wst_RequestedProofToken_s*)e->gg.g.n;
	  zx_FREE_wst_RequestedProofToken(c, e, free_strs);
      }
  }
  {
      struct zx_wst_Entropy_s* e;
      struct zx_wst_Entropy_s* en;
      for (e = x->Entropy; e; e = en) {
	  en = (struct zx_wst_Entropy_s*)e->gg.g.n;
	  zx_FREE_wst_Entropy(c, e, free_strs);
      }
  }
  {
      struct zx_wst_Lifetime_s* e;
      struct zx_wst_Lifetime_s* en;
      for (e = x->Lifetime; e; e = en) {
	  en = (struct zx_wst_Lifetime_s*)e->gg.g.n;
	  zx_FREE_wst_Lifetime(c, e, free_strs);
      }
  }
  {
      struct zx_wst_Status_s* e;
      struct zx_wst_Status_s* en;
      for (e = x->Status; e; e = en) {
	  en = (struct zx_wst_Status_s*)e->gg.g.n;
	  zx_FREE_wst_Status(c, e, free_strs);
      }
  }
  zx_free_simple_elems(c, x->AllowPostdating, free_strs);
  {
      struct zx_wst_Renewing_s* e;
      struct zx_wst_Renewing_s* en;
      for (e = x->Renewing; e; e = en) {
	  en = (struct zx_wst_Renewing_s*)e->gg.g.n;
	  zx_FREE_wst_Renewing(c, e, free_strs);
      }
  }
  {
      struct zx_wst_OnBehalfOf_s* e;
      struct zx_wst_OnBehalfOf_s* en;
      for (e = x->OnBehalfOf; e; e = en) {
	  en = (struct zx_wst_OnBehalfOf_s*)e->gg.g.n;
	  zx_FREE_wst_OnBehalfOf(c, e, free_strs);
      }
  }
  {
      struct zx_wst_Issuer_s* e;
      struct zx_wst_Issuer_s* en;
      for (e = x->Issuer; e; e = en) {
	  en = (struct zx_wst_Issuer_s*)e->gg.g.n;
	  zx_FREE_wst_Issuer(c, e, free_strs);
      }
  }
  zx_free_simple_elems(c, x->AuthenticationType, free_strs);
  {
      struct zx_wst_Authenticator_s* e;
      struct zx_wst_Authenticator_s* en;
      for (e = x->Authenticator; e; e = en) {
	  en = (struct zx_wst_Authenticator_s*)e->gg.g.n;
	  zx_FREE_wst_Authenticator(c, e, free_strs);
      }
  }
  zx_free_simple_elems(c, x->KeyType, free_strs);
  zx_free_simple_elems(c, x->KeySize, free_strs);
  zx_free_simple_elems(c, x->SignatureAlgorithm, free_strs);
  {
      struct zx_wst_Encryption_s* e;
      struct zx_wst_Encryption_s* en;
      for (e = x->Encryption; e; e = en) {
	  en = (struct zx_wst_Encryption_s*)e->gg.g.n;
	  zx_FREE_wst_Encryption(c, e, free_strs);
      }
  }
  zx_free_simple_elems(c, x->EncryptionAlgorithm, free_strs);
  zx_free_simple_elems(c, x->CanonicalizationAlgorithm, free_strs);
  {
      struct zx_wst_ProofEncryption_s* e;
      struct zx_wst_ProofEncryption_s* en;
      for (e = x->ProofEncryption; e; e = en) {
	  en = (struct zx_wst_ProofEncryption_s*)e->gg.g.n;
	  zx_FREE_wst_ProofEncryption(c, e, free_strs);
      }
  }
  {
      struct zx_wst_UseKey_s* e;
      struct zx_wst_UseKey_s* en;
      for (e = x->UseKey; e; e = en) {
	  en = (struct zx_wst_UseKey_s*)e->gg.g.n;
	  zx_FREE_wst_UseKey(c, e, free_strs);
      }
  }
  zx_free_simple_elems(c, x->SignWith, free_strs);
  zx_free_simple_elems(c, x->EncryptWith, free_strs);
  {
      struct zx_wst_DelegateTo_s* e;
      struct zx_wst_DelegateTo_s* en;
      for (e = x->DelegateTo; e; e = en) {
	  en = (struct zx_wst_DelegateTo_s*)e->gg.g.n;
	  zx_FREE_wst_DelegateTo(c, e, free_strs);
      }
  }
  zx_free_simple_elems(c, x->Forwardable, free_strs);
  zx_free_simple_elems(c, x->Delegatable, free_strs);
  {
      struct zx_wsp_Policy_s* e;
      struct zx_wsp_Policy_s* en;
      for (e = x->Policy; e; e = en) {
	  en = (struct zx_wsp_Policy_s*)e->gg.g.n;
	  zx_FREE_wsp_Policy(c, e, free_strs);
      }
  }
  {
      struct zx_wsp_PolicyReference_s* e;
      struct zx_wsp_PolicyReference_s* en;
      for (e = x->PolicyReference; e; e = en) {
	  en = (struct zx_wsp_PolicyReference_s*)e->gg.g.n;
	  zx_FREE_wsp_PolicyReference(c, e, free_strs);
      }
  }


  zx_free_elem_common(c, &x->gg, free_strs); 
}

/* FUNC(zx_NEW_wst_RequestSecurityTokenResponse) */

/* Trivial allocator/constructor for the datatype. */

/* Called by: */
struct zx_wst_RequestSecurityTokenResponse_s* zx_NEW_wst_RequestSecurityTokenResponse(struct zx_ctx* c)
{
  struct zx_wst_RequestSecurityTokenResponse_s* x = ZX_ZALLOC(c, struct zx_wst_RequestSecurityTokenResponse_s);
  x->gg.g.tok = zx_wst_RequestSecurityTokenResponse_ELEM;
  return x;
}

#ifdef ZX_ENA_AUX

/* FUNC(zx_DUP_STRS_wst_RequestSecurityTokenResponse) */

/* Depth first traversal of data structure to copy its simple strings
 * to memory allocated from the memory allocator. The decoder will
 * use the underlying wireprotocol PDU buffer for strings, i.e.
 * strings are not copied - they point to the real data. If the
 * datastructure needs to outlast the protocol data or needs a different
 * memory allocation strategy, you need to call this function.  */

/* Called by: */
void zx_DUP_STRS_wst_RequestSecurityTokenResponse(struct zx_ctx* c, struct zx_wst_RequestSecurityTokenResponse_s* x)
{
  zx_dup_strs_common(c, &x->gg);
  /* *** deal with xmlns specifications in exc c14n way */

  zx_dup_attr(c, x->Context);

  zx_dup_strs_simple_elems(c, x->TokenType);
  zx_dup_strs_simple_elems(c, x->RequestType);
  {
      struct zx_wst_RequestedSecurityToken_s* e;
      for (e = x->RequestedSecurityToken; e; e = (struct zx_wst_RequestedSecurityToken_s*)e->gg.g.n)
	  zx_DUP_STRS_wst_RequestedSecurityToken(c, e);
  }
  {
      struct zx_wsp_AppliesTo_s* e;
      for (e = x->AppliesTo; e; e = (struct zx_wsp_AppliesTo_s*)e->gg.g.n)
	  zx_DUP_STRS_wsp_AppliesTo(c, e);
  }
  {
      struct zx_wst_RequestedAttachedReference_s* e;
      for (e = x->RequestedAttachedReference; e; e = (struct zx_wst_RequestedAttachedReference_s*)e->gg.g.n)
	  zx_DUP_STRS_wst_RequestedAttachedReference(c, e);
  }
  {
      struct zx_wst_RequestedUnattachedReference_s* e;
      for (e = x->RequestedUnattachedReference; e; e = (struct zx_wst_RequestedUnattachedReference_s*)e->gg.g.n)
	  zx_DUP_STRS_wst_RequestedUnattachedReference(c, e);
  }
  {
      struct zx_wst_RequestedProofToken_s* e;
      for (e = x->RequestedProofToken; e; e = (struct zx_wst_RequestedProofToken_s*)e->gg.g.n)
	  zx_DUP_STRS_wst_RequestedProofToken(c, e);
  }
  {
      struct zx_wst_Entropy_s* e;
      for (e = x->Entropy; e; e = (struct zx_wst_Entropy_s*)e->gg.g.n)
	  zx_DUP_STRS_wst_Entropy(c, e);
  }
  {
      struct zx_wst_Lifetime_s* e;
      for (e = x->Lifetime; e; e = (struct zx_wst_Lifetime_s*)e->gg.g.n)
	  zx_DUP_STRS_wst_Lifetime(c, e);
  }
  {
      struct zx_wst_Status_s* e;
      for (e = x->Status; e; e = (struct zx_wst_Status_s*)e->gg.g.n)
	  zx_DUP_STRS_wst_Status(c, e);
  }
  zx_dup_strs_simple_elems(c, x->AllowPostdating);
  {
      struct zx_wst_Renewing_s* e;
      for (e = x->Renewing; e; e = (struct zx_wst_Renewing_s*)e->gg.g.n)
	  zx_DUP_STRS_wst_Renewing(c, e);
  }
  {
      struct zx_wst_OnBehalfOf_s* e;
      for (e = x->OnBehalfOf; e; e = (struct zx_wst_OnBehalfOf_s*)e->gg.g.n)
	  zx_DUP_STRS_wst_OnBehalfOf(c, e);
  }
  {
      struct zx_wst_Issuer_s* e;
      for (e = x->Issuer; e; e = (struct zx_wst_Issuer_s*)e->gg.g.n)
	  zx_DUP_STRS_wst_Issuer(c, e);
  }
  zx_dup_strs_simple_elems(c, x->AuthenticationType);
  {
      struct zx_wst_Authenticator_s* e;
      for (e = x->Authenticator; e; e = (struct zx_wst_Authenticator_s*)e->gg.g.n)
	  zx_DUP_STRS_wst_Authenticator(c, e);
  }
  zx_dup_strs_simple_elems(c, x->KeyType);
  zx_dup_strs_simple_elems(c, x->KeySize);
  zx_dup_strs_simple_elems(c, x->SignatureAlgorithm);
  {
      struct zx_wst_Encryption_s* e;
      for (e = x->Encryption; e; e = (struct zx_wst_Encryption_s*)e->gg.g.n)
	  zx_DUP_STRS_wst_Encryption(c, e);
  }
  zx_dup_strs_simple_elems(c, x->EncryptionAlgorithm);
  zx_dup_strs_simple_elems(c, x->CanonicalizationAlgorithm);
  {
      struct zx_wst_ProofEncryption_s* e;
      for (e = x->ProofEncryption; e; e = (struct zx_wst_ProofEncryption_s*)e->gg.g.n)
	  zx_DUP_STRS_wst_ProofEncryption(c, e);
  }
  {
      struct zx_wst_UseKey_s* e;
      for (e = x->UseKey; e; e = (struct zx_wst_UseKey_s*)e->gg.g.n)
	  zx_DUP_STRS_wst_UseKey(c, e);
  }
  zx_dup_strs_simple_elems(c, x->SignWith);
  zx_dup_strs_simple_elems(c, x->EncryptWith);
  {
      struct zx_wst_DelegateTo_s* e;
      for (e = x->DelegateTo; e; e = (struct zx_wst_DelegateTo_s*)e->gg.g.n)
	  zx_DUP_STRS_wst_DelegateTo(c, e);
  }
  zx_dup_strs_simple_elems(c, x->Forwardable);
  zx_dup_strs_simple_elems(c, x->Delegatable);
  {
      struct zx_wsp_Policy_s* e;
      for (e = x->Policy; e; e = (struct zx_wsp_Policy_s*)e->gg.g.n)
	  zx_DUP_STRS_wsp_Policy(c, e);
  }
  {
      struct zx_wsp_PolicyReference_s* e;
      for (e = x->PolicyReference; e; e = (struct zx_wsp_PolicyReference_s*)e->gg.g.n)
	  zx_DUP_STRS_wsp_PolicyReference(c, e);
  }

}

/* FUNC(zx_DEEP_CLONE_wst_RequestSecurityTokenResponse) */

/* Depth first traversal of data structure to clone it and its sublements.
 * The simple strings are handled as a special case according to dup_strs flag. */

/* Called by: */
struct zx_wst_RequestSecurityTokenResponse_s* zx_DEEP_CLONE_wst_RequestSecurityTokenResponse(struct zx_ctx* c, struct zx_wst_RequestSecurityTokenResponse_s* x, int dup_strs)
{
  x = (struct zx_wst_RequestSecurityTokenResponse_s*)zx_clone_elem_common(c, &x->gg, sizeof(struct zx_wst_RequestSecurityTokenResponse_s), dup_strs);
  /* *** deal with xmlns specifications in exc c14n way */

  x->Context = zx_clone_attr(c, x->Context);

  x->TokenType = zx_deep_clone_simple_elems(c,x->TokenType, dup_strs);
  x->RequestType = zx_deep_clone_simple_elems(c,x->RequestType, dup_strs);
  {
      struct zx_wst_RequestedSecurityToken_s* e;
      struct zx_wst_RequestedSecurityToken_s* en;
      struct zx_wst_RequestedSecurityToken_s* enn;
      for (enn = 0, e = x->RequestedSecurityToken; e; e = (struct zx_wst_RequestedSecurityToken_s*)e->gg.g.n) {
	  en = zx_DEEP_CLONE_wst_RequestedSecurityToken(c, e, dup_strs);
	  if (!enn)
	      x->RequestedSecurityToken = en;
	  else
	      enn->gg.g.n = &en->gg.g;
	  enn = en;
      }
  }
  {
      struct zx_wsp_AppliesTo_s* e;
      struct zx_wsp_AppliesTo_s* en;
      struct zx_wsp_AppliesTo_s* enn;
      for (enn = 0, e = x->AppliesTo; e; e = (struct zx_wsp_AppliesTo_s*)e->gg.g.n) {
	  en = zx_DEEP_CLONE_wsp_AppliesTo(c, e, dup_strs);
	  if (!enn)
	      x->AppliesTo = en;
	  else
	      enn->gg.g.n = &en->gg.g;
	  enn = en;
      }
  }
  {
      struct zx_wst_RequestedAttachedReference_s* e;
      struct zx_wst_RequestedAttachedReference_s* en;
      struct zx_wst_RequestedAttachedReference_s* enn;
      for (enn = 0, e = x->RequestedAttachedReference; e; e = (struct zx_wst_RequestedAttachedReference_s*)e->gg.g.n) {
	  en = zx_DEEP_CLONE_wst_RequestedAttachedReference(c, e, dup_strs);
	  if (!enn)
	      x->RequestedAttachedReference = en;
	  else
	      enn->gg.g.n = &en->gg.g;
	  enn = en;
      }
  }
  {
      struct zx_wst_RequestedUnattachedReference_s* e;
      struct zx_wst_RequestedUnattachedReference_s* en;
      struct zx_wst_RequestedUnattachedReference_s* enn;
      for (enn = 0, e = x->RequestedUnattachedReference; e; e = (struct zx_wst_RequestedUnattachedReference_s*)e->gg.g.n) {
	  en = zx_DEEP_CLONE_wst_RequestedUnattachedReference(c, e, dup_strs);
	  if (!enn)
	      x->RequestedUnattachedReference = en;
	  else
	      enn->gg.g.n = &en->gg.g;
	  enn = en;
      }
  }
  {
      struct zx_wst_RequestedProofToken_s* e;
      struct zx_wst_RequestedProofToken_s* en;
      struct zx_wst_RequestedProofToken_s* enn;
      for (enn = 0, e = x->RequestedProofToken; e; e = (struct zx_wst_RequestedProofToken_s*)e->gg.g.n) {
	  en = zx_DEEP_CLONE_wst_RequestedProofToken(c, e, dup_strs);
	  if (!enn)
	      x->RequestedProofToken = en;
	  else
	      enn->gg.g.n = &en->gg.g;
	  enn = en;
      }
  }
  {
      struct zx_wst_Entropy_s* e;
      struct zx_wst_Entropy_s* en;
      struct zx_wst_Entropy_s* enn;
      for (enn = 0, e = x->Entropy; e; e = (struct zx_wst_Entropy_s*)e->gg.g.n) {
	  en = zx_DEEP_CLONE_wst_Entropy(c, e, dup_strs);
	  if (!enn)
	      x->Entropy = en;
	  else
	      enn->gg.g.n = &en->gg.g;
	  enn = en;
      }
  }
  {
      struct zx_wst_Lifetime_s* e;
      struct zx_wst_Lifetime_s* en;
      struct zx_wst_Lifetime_s* enn;
      for (enn = 0, e = x->Lifetime; e; e = (struct zx_wst_Lifetime_s*)e->gg.g.n) {
	  en = zx_DEEP_CLONE_wst_Lifetime(c, e, dup_strs);
	  if (!enn)
	      x->Lifetime = en;
	  else
	      enn->gg.g.n = &en->gg.g;
	  enn = en;
      }
  }
  {
      struct zx_wst_Status_s* e;
      struct zx_wst_Status_s* en;
      struct zx_wst_Status_s* enn;
      for (enn = 0, e = x->Status; e; e = (struct zx_wst_Status_s*)e->gg.g.n) {
	  en = zx_DEEP_CLONE_wst_Status(c, e, dup_strs);
	  if (!enn)
	      x->Status = en;
	  else
	      enn->gg.g.n = &en->gg.g;
	  enn = en;
      }
  }
  x->AllowPostdating = zx_deep_clone_simple_elems(c,x->AllowPostdating, dup_strs);
  {
      struct zx_wst_Renewing_s* e;
      struct zx_wst_Renewing_s* en;
      struct zx_wst_Renewing_s* enn;
      for (enn = 0, e = x->Renewing; e; e = (struct zx_wst_Renewing_s*)e->gg.g.n) {
	  en = zx_DEEP_CLONE_wst_Renewing(c, e, dup_strs);
	  if (!enn)
	      x->Renewing = en;
	  else
	      enn->gg.g.n = &en->gg.g;
	  enn = en;
      }
  }
  {
      struct zx_wst_OnBehalfOf_s* e;
      struct zx_wst_OnBehalfOf_s* en;
      struct zx_wst_OnBehalfOf_s* enn;
      for (enn = 0, e = x->OnBehalfOf; e; e = (struct zx_wst_OnBehalfOf_s*)e->gg.g.n) {
	  en = zx_DEEP_CLONE_wst_OnBehalfOf(c, e, dup_strs);
	  if (!enn)
	      x->OnBehalfOf = en;
	  else
	      enn->gg.g.n = &en->gg.g;
	  enn = en;
      }
  }
  {
      struct zx_wst_Issuer_s* e;
      struct zx_wst_Issuer_s* en;
      struct zx_wst_Issuer_s* enn;
      for (enn = 0, e = x->Issuer; e; e = (struct zx_wst_Issuer_s*)e->gg.g.n) {
	  en = zx_DEEP_CLONE_wst_Issuer(c, e, dup_strs);
	  if (!enn)
	      x->Issuer = en;
	  else
	      enn->gg.g.n = &en->gg.g;
	  enn = en;
      }
  }
  x->AuthenticationType = zx_deep_clone_simple_elems(c,x->AuthenticationType, dup_strs);
  {
      struct zx_wst_Authenticator_s* e;
      struct zx_wst_Authenticator_s* en;
      struct zx_wst_Authenticator_s* enn;
      for (enn = 0, e = x->Authenticator; e; e = (struct zx_wst_Authenticator_s*)e->gg.g.n) {
	  en = zx_DEEP_CLONE_wst_Authenticator(c, e, dup_strs);
	  if (!enn)
	      x->Authenticator = en;
	  else
	      enn->gg.g.n = &en->gg.g;
	  enn = en;
      }
  }
  x->KeyType = zx_deep_clone_simple_elems(c,x->KeyType, dup_strs);
  x->KeySize = zx_deep_clone_simple_elems(c,x->KeySize, dup_strs);
  x->SignatureAlgorithm = zx_deep_clone_simple_elems(c,x->SignatureAlgorithm, dup_strs);
  {
      struct zx_wst_Encryption_s* e;
      struct zx_wst_Encryption_s* en;
      struct zx_wst_Encryption_s* enn;
      for (enn = 0, e = x->Encryption; e; e = (struct zx_wst_Encryption_s*)e->gg.g.n) {
	  en = zx_DEEP_CLONE_wst_Encryption(c, e, dup_strs);
	  if (!enn)
	      x->Encryption = en;
	  else
	      enn->gg.g.n = &en->gg.g;
	  enn = en;
      }
  }
  x->EncryptionAlgorithm = zx_deep_clone_simple_elems(c,x->EncryptionAlgorithm, dup_strs);
  x->CanonicalizationAlgorithm = zx_deep_clone_simple_elems(c,x->CanonicalizationAlgorithm, dup_strs);
  {
      struct zx_wst_ProofEncryption_s* e;
      struct zx_wst_ProofEncryption_s* en;
      struct zx_wst_ProofEncryption_s* enn;
      for (enn = 0, e = x->ProofEncryption; e; e = (struct zx_wst_ProofEncryption_s*)e->gg.g.n) {
	  en = zx_DEEP_CLONE_wst_ProofEncryption(c, e, dup_strs);
	  if (!enn)
	      x->ProofEncryption = en;
	  else
	      enn->gg.g.n = &en->gg.g;
	  enn = en;
      }
  }
  {
      struct zx_wst_UseKey_s* e;
      struct zx_wst_UseKey_s* en;
      struct zx_wst_UseKey_s* enn;
      for (enn = 0, e = x->UseKey; e; e = (struct zx_wst_UseKey_s*)e->gg.g.n) {
	  en = zx_DEEP_CLONE_wst_UseKey(c, e, dup_strs);
	  if (!enn)
	      x->UseKey = en;
	  else
	      enn->gg.g.n = &en->gg.g;
	  enn = en;
      }
  }
  x->SignWith = zx_deep_clone_simple_elems(c,x->SignWith, dup_strs);
  x->EncryptWith = zx_deep_clone_simple_elems(c,x->EncryptWith, dup_strs);
  {
      struct zx_wst_DelegateTo_s* e;
      struct zx_wst_DelegateTo_s* en;
      struct zx_wst_DelegateTo_s* enn;
      for (enn = 0, e = x->DelegateTo; e; e = (struct zx_wst_DelegateTo_s*)e->gg.g.n) {
	  en = zx_DEEP_CLONE_wst_DelegateTo(c, e, dup_strs);
	  if (!enn)
	      x->DelegateTo = en;
	  else
	      enn->gg.g.n = &en->gg.g;
	  enn = en;
      }
  }
  x->Forwardable = zx_deep_clone_simple_elems(c,x->Forwardable, dup_strs);
  x->Delegatable = zx_deep_clone_simple_elems(c,x->Delegatable, dup_strs);
  {
      struct zx_wsp_Policy_s* e;
      struct zx_wsp_Policy_s* en;
      struct zx_wsp_Policy_s* enn;
      for (enn = 0, e = x->Policy; e; e = (struct zx_wsp_Policy_s*)e->gg.g.n) {
	  en = zx_DEEP_CLONE_wsp_Policy(c, e, dup_strs);
	  if (!enn)
	      x->Policy = en;
	  else
	      enn->gg.g.n = &en->gg.g;
	  enn = en;
      }
  }
  {
      struct zx_wsp_PolicyReference_s* e;
      struct zx_wsp_PolicyReference_s* en;
      struct zx_wsp_PolicyReference_s* enn;
      for (enn = 0, e = x->PolicyReference; e; e = (struct zx_wsp_PolicyReference_s*)e->gg.g.n) {
	  en = zx_DEEP_CLONE_wsp_PolicyReference(c, e, dup_strs);
	  if (!enn)
	      x->PolicyReference = en;
	  else
	      enn->gg.g.n = &en->gg.g;
	  enn = en;
      }
  }

  return x;
}

/* FUNC(zx_WALK_SO_wst_RequestSecurityTokenResponse) */

/* Depth first traversal of the tree in either schema order or the wire order. */
 
int zx_WALK_SO_wst_RequestSecurityTokenResponse(struct zx_ctx* c, struct zx_wst_RequestSecurityTokenResponse_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
{
  int ret = callback(&x->gg.g, ctx);
  if (ret)
    return ret;
  
  /* *** deal with xmlns specifications in exc c14n way */


  
  ret = zx_walk_so_unknown_attributes(c, &x->gg, ctx, callback); 
  if (ret)
    return ret;

  ret = zx_walk_so_simple_elems(c, x->TokenType, ctx, callback);
  if (ret)
    return ret;
  ret = zx_walk_so_simple_elems(c, x->RequestType, ctx, callback);
  if (ret)
    return ret;
  {
      struct zx_wst_RequestedSecurityToken_s* e;
      for (e = x->RequestedSecurityToken; e; e = (struct zx_wst_RequestedSecurityToken_s*)e->gg.g.n) {
	  ret = zx_WALK_SO_wst_RequestedSecurityToken(c, e, ctx, callback);
	  if (ret)
	      return ret;
      }
  }
  {
      struct zx_wsp_AppliesTo_s* e;
      for (e = x->AppliesTo; e; e = (struct zx_wsp_AppliesTo_s*)e->gg.g.n) {
	  ret = zx_WALK_SO_wsp_AppliesTo(c, e, ctx, callback);
	  if (ret)
	      return ret;
      }
  }
  {
      struct zx_wst_RequestedAttachedReference_s* e;
      for (e = x->RequestedAttachedReference; e; e = (struct zx_wst_RequestedAttachedReference_s*)e->gg.g.n) {
	  ret = zx_WALK_SO_wst_RequestedAttachedReference(c, e, ctx, callback);
	  if (ret)
	      return ret;
      }
  }
  {
      struct zx_wst_RequestedUnattachedReference_s* e;
      for (e = x->RequestedUnattachedReference; e; e = (struct zx_wst_RequestedUnattachedReference_s*)e->gg.g.n) {
	  ret = zx_WALK_SO_wst_RequestedUnattachedReference(c, e, ctx, callback);
	  if (ret)
	      return ret;
      }
  }
  {
      struct zx_wst_RequestedProofToken_s* e;
      for (e = x->RequestedProofToken; e; e = (struct zx_wst_RequestedProofToken_s*)e->gg.g.n) {
	  ret = zx_WALK_SO_wst_RequestedProofToken(c, e, ctx, callback);
	  if (ret)
	      return ret;
      }
  }
  {
      struct zx_wst_Entropy_s* e;
      for (e = x->Entropy; e; e = (struct zx_wst_Entropy_s*)e->gg.g.n) {
	  ret = zx_WALK_SO_wst_Entropy(c, e, ctx, callback);
	  if (ret)
	      return ret;
      }
  }
  {
      struct zx_wst_Lifetime_s* e;
      for (e = x->Lifetime; e; e = (struct zx_wst_Lifetime_s*)e->gg.g.n) {
	  ret = zx_WALK_SO_wst_Lifetime(c, e, ctx, callback);
	  if (ret)
	      return ret;
      }
  }
  {
      struct zx_wst_Status_s* e;
      for (e = x->Status; e; e = (struct zx_wst_Status_s*)e->gg.g.n) {
	  ret = zx_WALK_SO_wst_Status(c, e, ctx, callback);
	  if (ret)
	      return ret;
      }
  }
  ret = zx_walk_so_simple_elems(c, x->AllowPostdating, ctx, callback);
  if (ret)
    return ret;
  {
      struct zx_wst_Renewing_s* e;
      for (e = x->Renewing; e; e = (struct zx_wst_Renewing_s*)e->gg.g.n) {
	  ret = zx_WALK_SO_wst_Renewing(c, e, ctx, callback);
	  if (ret)
	      return ret;
      }
  }
  {
      struct zx_wst_OnBehalfOf_s* e;
      for (e = x->OnBehalfOf; e; e = (struct zx_wst_OnBehalfOf_s*)e->gg.g.n) {
	  ret = zx_WALK_SO_wst_OnBehalfOf(c, e, ctx, callback);
	  if (ret)
	      return ret;
      }
  }
  {
      struct zx_wst_Issuer_s* e;
      for (e = x->Issuer; e; e = (struct zx_wst_Issuer_s*)e->gg.g.n) {
	  ret = zx_WALK_SO_wst_Issuer(c, e, ctx, callback);
	  if (ret)
	      return ret;
      }
  }
  ret = zx_walk_so_simple_elems(c, x->AuthenticationType, ctx, callback);
  if (ret)
    return ret;
  {
      struct zx_wst_Authenticator_s* e;
      for (e = x->Authenticator; e; e = (struct zx_wst_Authenticator_s*)e->gg.g.n) {
	  ret = zx_WALK_SO_wst_Authenticator(c, e, ctx, callback);
	  if (ret)
	      return ret;
      }
  }
  ret = zx_walk_so_simple_elems(c, x->KeyType, ctx, callback);
  if (ret)
    return ret;
  ret = zx_walk_so_simple_elems(c, x->KeySize, ctx, callback);
  if (ret)
    return ret;
  ret = zx_walk_so_simple_elems(c, x->SignatureAlgorithm, ctx, callback);
  if (ret)
    return ret;
  {
      struct zx_wst_Encryption_s* e;
      for (e = x->Encryption; e; e = (struct zx_wst_Encryption_s*)e->gg.g.n) {
	  ret = zx_WALK_SO_wst_Encryption(c, e, ctx, callback);
	  if (ret)
	      return ret;
      }
  }
  ret = zx_walk_so_simple_elems(c, x->EncryptionAlgorithm, ctx, callback);
  if (ret)
    return ret;
  ret = zx_walk_so_simple_elems(c, x->CanonicalizationAlgorithm, ctx, callback);
  if (ret)
    return ret;
  {
      struct zx_wst_ProofEncryption_s* e;
      for (e = x->ProofEncryption; e; e = (struct zx_wst_ProofEncryption_s*)e->gg.g.n) {
	  ret = zx_WALK_SO_wst_ProofEncryption(c, e, ctx, callback);
	  if (ret)
	      return ret;
      }
  }
  {
      struct zx_wst_UseKey_s* e;
      for (e = x->UseKey; e; e = (struct zx_wst_UseKey_s*)e->gg.g.n) {
	  ret = zx_WALK_SO_wst_UseKey(c, e, ctx, callback);
	  if (ret)
	      return ret;
      }
  }
  ret = zx_walk_so_simple_elems(c, x->SignWith, ctx, callback);
  if (ret)
    return ret;
  ret = zx_walk_so_simple_elems(c, x->EncryptWith, ctx, callback);
  if (ret)
    return ret;
  {
      struct zx_wst_DelegateTo_s* e;
      for (e = x->DelegateTo; e; e = (struct zx_wst_DelegateTo_s*)e->gg.g.n) {
	  ret = zx_WALK_SO_wst_DelegateTo(c, e, ctx, callback);
	  if (ret)
	      return ret;
      }
  }
  ret = zx_walk_so_simple_elems(c, x->Forwardable, ctx, callback);
  if (ret)
    return ret;
  ret = zx_walk_so_simple_elems(c, x->Delegatable, ctx, callback);
  if (ret)
    return ret;
  {
      struct zx_wsp_Policy_s* e;
      for (e = x->Policy; e; e = (struct zx_wsp_Policy_s*)e->gg.g.n) {
	  ret = zx_WALK_SO_wsp_Policy(c, e, ctx, callback);
	  if (ret)
	      return ret;
      }
  }
  {
      struct zx_wsp_PolicyReference_s* e;
      for (e = x->PolicyReference; e; e = (struct zx_wsp_PolicyReference_s*)e->gg.g.n) {
	  ret = zx_WALK_SO_wsp_PolicyReference(c, e, ctx, callback);
	  if (ret)
	      return ret;
      }
  }

  
  return zx_walk_so_unknown_elems_and_content(c, &x->gg, ctx, callback);
}

/* FUNC(zx_WALK_WO_wst_RequestSecurityTokenResponse) */

int zx_WALK_WO_wst_RequestSecurityTokenResponse(struct zx_ctx* c, struct zx_wst_RequestSecurityTokenResponse_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
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

#define EL_NAME   wst_RequestSecurityTokenResponseCollection
#define EL_STRUCT zx_wst_RequestSecurityTokenResponseCollection_s
#define EL_NS     wst
#define EL_TAG    RequestSecurityTokenResponseCollection

/* FUNC(zx_FREE_wst_RequestSecurityTokenResponseCollection) */

/* Depth first traversal of data structure to free it and its subelements. Simple
 * strings are handled as a special case according to the free_strs flag. This
 * is useful if the strings point to underlying data from the wire that was
 * allocated differently. */

/* Called by: */
void zx_FREE_wst_RequestSecurityTokenResponseCollection(struct zx_ctx* c, struct zx_wst_RequestSecurityTokenResponseCollection_s* x, int free_strs)
{
  /* *** deal with xmlns specifications in exc c14n way */


  {
      struct zx_wst_RequestSecurityTokenResponse_s* e;
      struct zx_wst_RequestSecurityTokenResponse_s* en;
      for (e = x->RequestSecurityTokenResponse; e; e = en) {
	  en = (struct zx_wst_RequestSecurityTokenResponse_s*)e->gg.g.n;
	  zx_FREE_wst_RequestSecurityTokenResponse(c, e, free_strs);
      }
  }


  zx_free_elem_common(c, &x->gg, free_strs); 
}

/* FUNC(zx_NEW_wst_RequestSecurityTokenResponseCollection) */

/* Trivial allocator/constructor for the datatype. */

/* Called by: */
struct zx_wst_RequestSecurityTokenResponseCollection_s* zx_NEW_wst_RequestSecurityTokenResponseCollection(struct zx_ctx* c)
{
  struct zx_wst_RequestSecurityTokenResponseCollection_s* x = ZX_ZALLOC(c, struct zx_wst_RequestSecurityTokenResponseCollection_s);
  x->gg.g.tok = zx_wst_RequestSecurityTokenResponseCollection_ELEM;
  return x;
}

#ifdef ZX_ENA_AUX

/* FUNC(zx_DUP_STRS_wst_RequestSecurityTokenResponseCollection) */

/* Depth first traversal of data structure to copy its simple strings
 * to memory allocated from the memory allocator. The decoder will
 * use the underlying wireprotocol PDU buffer for strings, i.e.
 * strings are not copied - they point to the real data. If the
 * datastructure needs to outlast the protocol data or needs a different
 * memory allocation strategy, you need to call this function.  */

/* Called by: */
void zx_DUP_STRS_wst_RequestSecurityTokenResponseCollection(struct zx_ctx* c, struct zx_wst_RequestSecurityTokenResponseCollection_s* x)
{
  zx_dup_strs_common(c, &x->gg);
  /* *** deal with xmlns specifications in exc c14n way */


  {
      struct zx_wst_RequestSecurityTokenResponse_s* e;
      for (e = x->RequestSecurityTokenResponse; e; e = (struct zx_wst_RequestSecurityTokenResponse_s*)e->gg.g.n)
	  zx_DUP_STRS_wst_RequestSecurityTokenResponse(c, e);
  }

}

/* FUNC(zx_DEEP_CLONE_wst_RequestSecurityTokenResponseCollection) */

/* Depth first traversal of data structure to clone it and its sublements.
 * The simple strings are handled as a special case according to dup_strs flag. */

/* Called by: */
struct zx_wst_RequestSecurityTokenResponseCollection_s* zx_DEEP_CLONE_wst_RequestSecurityTokenResponseCollection(struct zx_ctx* c, struct zx_wst_RequestSecurityTokenResponseCollection_s* x, int dup_strs)
{
  x = (struct zx_wst_RequestSecurityTokenResponseCollection_s*)zx_clone_elem_common(c, &x->gg, sizeof(struct zx_wst_RequestSecurityTokenResponseCollection_s), dup_strs);
  /* *** deal with xmlns specifications in exc c14n way */


  {
      struct zx_wst_RequestSecurityTokenResponse_s* e;
      struct zx_wst_RequestSecurityTokenResponse_s* en;
      struct zx_wst_RequestSecurityTokenResponse_s* enn;
      for (enn = 0, e = x->RequestSecurityTokenResponse; e; e = (struct zx_wst_RequestSecurityTokenResponse_s*)e->gg.g.n) {
	  en = zx_DEEP_CLONE_wst_RequestSecurityTokenResponse(c, e, dup_strs);
	  if (!enn)
	      x->RequestSecurityTokenResponse = en;
	  else
	      enn->gg.g.n = &en->gg.g;
	  enn = en;
      }
  }

  return x;
}

/* FUNC(zx_WALK_SO_wst_RequestSecurityTokenResponseCollection) */

/* Depth first traversal of the tree in either schema order or the wire order. */
 
int zx_WALK_SO_wst_RequestSecurityTokenResponseCollection(struct zx_ctx* c, struct zx_wst_RequestSecurityTokenResponseCollection_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
{
  int ret = callback(&x->gg.g, ctx);
  if (ret)
    return ret;
  
  /* *** deal with xmlns specifications in exc c14n way */


  
  ret = zx_walk_so_unknown_attributes(c, &x->gg, ctx, callback); 
  if (ret)
    return ret;

  {
      struct zx_wst_RequestSecurityTokenResponse_s* e;
      for (e = x->RequestSecurityTokenResponse; e; e = (struct zx_wst_RequestSecurityTokenResponse_s*)e->gg.g.n) {
	  ret = zx_WALK_SO_wst_RequestSecurityTokenResponse(c, e, ctx, callback);
	  if (ret)
	      return ret;
      }
  }

  
  return zx_walk_so_unknown_elems_and_content(c, &x->gg, ctx, callback);
}

/* FUNC(zx_WALK_WO_wst_RequestSecurityTokenResponseCollection) */

int zx_WALK_WO_wst_RequestSecurityTokenResponseCollection(struct zx_ctx* c, struct zx_wst_RequestSecurityTokenResponseCollection_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
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

#define EL_NAME   wst_RequestedAttachedReference
#define EL_STRUCT zx_wst_RequestedAttachedReference_s
#define EL_NS     wst
#define EL_TAG    RequestedAttachedReference

/* FUNC(zx_FREE_wst_RequestedAttachedReference) */

/* Depth first traversal of data structure to free it and its subelements. Simple
 * strings are handled as a special case according to the free_strs flag. This
 * is useful if the strings point to underlying data from the wire that was
 * allocated differently. */

/* Called by: */
void zx_FREE_wst_RequestedAttachedReference(struct zx_ctx* c, struct zx_wst_RequestedAttachedReference_s* x, int free_strs)
{
  /* *** deal with xmlns specifications in exc c14n way */


  {
      struct zx_wsse_SecurityTokenReference_s* e;
      struct zx_wsse_SecurityTokenReference_s* en;
      for (e = x->SecurityTokenReference; e; e = en) {
	  en = (struct zx_wsse_SecurityTokenReference_s*)e->gg.g.n;
	  zx_FREE_wsse_SecurityTokenReference(c, e, free_strs);
      }
  }


  zx_free_elem_common(c, &x->gg, free_strs); 
}

/* FUNC(zx_NEW_wst_RequestedAttachedReference) */

/* Trivial allocator/constructor for the datatype. */

/* Called by: */
struct zx_wst_RequestedAttachedReference_s* zx_NEW_wst_RequestedAttachedReference(struct zx_ctx* c)
{
  struct zx_wst_RequestedAttachedReference_s* x = ZX_ZALLOC(c, struct zx_wst_RequestedAttachedReference_s);
  x->gg.g.tok = zx_wst_RequestedAttachedReference_ELEM;
  return x;
}

#ifdef ZX_ENA_AUX

/* FUNC(zx_DUP_STRS_wst_RequestedAttachedReference) */

/* Depth first traversal of data structure to copy its simple strings
 * to memory allocated from the memory allocator. The decoder will
 * use the underlying wireprotocol PDU buffer for strings, i.e.
 * strings are not copied - they point to the real data. If the
 * datastructure needs to outlast the protocol data or needs a different
 * memory allocation strategy, you need to call this function.  */

/* Called by: */
void zx_DUP_STRS_wst_RequestedAttachedReference(struct zx_ctx* c, struct zx_wst_RequestedAttachedReference_s* x)
{
  zx_dup_strs_common(c, &x->gg);
  /* *** deal with xmlns specifications in exc c14n way */


  {
      struct zx_wsse_SecurityTokenReference_s* e;
      for (e = x->SecurityTokenReference; e; e = (struct zx_wsse_SecurityTokenReference_s*)e->gg.g.n)
	  zx_DUP_STRS_wsse_SecurityTokenReference(c, e);
  }

}

/* FUNC(zx_DEEP_CLONE_wst_RequestedAttachedReference) */

/* Depth first traversal of data structure to clone it and its sublements.
 * The simple strings are handled as a special case according to dup_strs flag. */

/* Called by: */
struct zx_wst_RequestedAttachedReference_s* zx_DEEP_CLONE_wst_RequestedAttachedReference(struct zx_ctx* c, struct zx_wst_RequestedAttachedReference_s* x, int dup_strs)
{
  x = (struct zx_wst_RequestedAttachedReference_s*)zx_clone_elem_common(c, &x->gg, sizeof(struct zx_wst_RequestedAttachedReference_s), dup_strs);
  /* *** deal with xmlns specifications in exc c14n way */


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

  return x;
}

/* FUNC(zx_WALK_SO_wst_RequestedAttachedReference) */

/* Depth first traversal of the tree in either schema order or the wire order. */
 
int zx_WALK_SO_wst_RequestedAttachedReference(struct zx_ctx* c, struct zx_wst_RequestedAttachedReference_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
{
  int ret = callback(&x->gg.g, ctx);
  if (ret)
    return ret;
  
  /* *** deal with xmlns specifications in exc c14n way */


  
  ret = zx_walk_so_unknown_attributes(c, &x->gg, ctx, callback); 
  if (ret)
    return ret;

  {
      struct zx_wsse_SecurityTokenReference_s* e;
      for (e = x->SecurityTokenReference; e; e = (struct zx_wsse_SecurityTokenReference_s*)e->gg.g.n) {
	  ret = zx_WALK_SO_wsse_SecurityTokenReference(c, e, ctx, callback);
	  if (ret)
	      return ret;
      }
  }

  
  return zx_walk_so_unknown_elems_and_content(c, &x->gg, ctx, callback);
}

/* FUNC(zx_WALK_WO_wst_RequestedAttachedReference) */

int zx_WALK_WO_wst_RequestedAttachedReference(struct zx_ctx* c, struct zx_wst_RequestedAttachedReference_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
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

#define EL_NAME   wst_RequestedProofToken
#define EL_STRUCT zx_wst_RequestedProofToken_s
#define EL_NS     wst
#define EL_TAG    RequestedProofToken

/* FUNC(zx_FREE_wst_RequestedProofToken) */

/* Depth first traversal of data structure to free it and its subelements. Simple
 * strings are handled as a special case according to the free_strs flag. This
 * is useful if the strings point to underlying data from the wire that was
 * allocated differently. */

/* Called by: */
void zx_FREE_wst_RequestedProofToken(struct zx_ctx* c, struct zx_wst_RequestedProofToken_s* x, int free_strs)
{
  /* *** deal with xmlns specifications in exc c14n way */




  zx_free_elem_common(c, &x->gg, free_strs); 
}

/* FUNC(zx_NEW_wst_RequestedProofToken) */

/* Trivial allocator/constructor for the datatype. */

/* Called by: */
struct zx_wst_RequestedProofToken_s* zx_NEW_wst_RequestedProofToken(struct zx_ctx* c)
{
  struct zx_wst_RequestedProofToken_s* x = ZX_ZALLOC(c, struct zx_wst_RequestedProofToken_s);
  x->gg.g.tok = zx_wst_RequestedProofToken_ELEM;
  return x;
}

#ifdef ZX_ENA_AUX

/* FUNC(zx_DUP_STRS_wst_RequestedProofToken) */

/* Depth first traversal of data structure to copy its simple strings
 * to memory allocated from the memory allocator. The decoder will
 * use the underlying wireprotocol PDU buffer for strings, i.e.
 * strings are not copied - they point to the real data. If the
 * datastructure needs to outlast the protocol data or needs a different
 * memory allocation strategy, you need to call this function.  */

/* Called by: */
void zx_DUP_STRS_wst_RequestedProofToken(struct zx_ctx* c, struct zx_wst_RequestedProofToken_s* x)
{
  zx_dup_strs_common(c, &x->gg);
  /* *** deal with xmlns specifications in exc c14n way */



}

/* FUNC(zx_DEEP_CLONE_wst_RequestedProofToken) */

/* Depth first traversal of data structure to clone it and its sublements.
 * The simple strings are handled as a special case according to dup_strs flag. */

/* Called by: */
struct zx_wst_RequestedProofToken_s* zx_DEEP_CLONE_wst_RequestedProofToken(struct zx_ctx* c, struct zx_wst_RequestedProofToken_s* x, int dup_strs)
{
  x = (struct zx_wst_RequestedProofToken_s*)zx_clone_elem_common(c, &x->gg, sizeof(struct zx_wst_RequestedProofToken_s), dup_strs);
  /* *** deal with xmlns specifications in exc c14n way */



  return x;
}

/* FUNC(zx_WALK_SO_wst_RequestedProofToken) */

/* Depth first traversal of the tree in either schema order or the wire order. */
 
int zx_WALK_SO_wst_RequestedProofToken(struct zx_ctx* c, struct zx_wst_RequestedProofToken_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
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

/* FUNC(zx_WALK_WO_wst_RequestedProofToken) */

int zx_WALK_WO_wst_RequestedProofToken(struct zx_ctx* c, struct zx_wst_RequestedProofToken_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
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

#define EL_NAME   wst_RequestedSecurityToken
#define EL_STRUCT zx_wst_RequestedSecurityToken_s
#define EL_NS     wst
#define EL_TAG    RequestedSecurityToken

/* FUNC(zx_FREE_wst_RequestedSecurityToken) */

/* Depth first traversal of data structure to free it and its subelements. Simple
 * strings are handled as a special case according to the free_strs flag. This
 * is useful if the strings point to underlying data from the wire that was
 * allocated differently. */

/* Called by: */
void zx_FREE_wst_RequestedSecurityToken(struct zx_ctx* c, struct zx_wst_RequestedSecurityToken_s* x, int free_strs)
{
  /* *** deal with xmlns specifications in exc c14n way */




  zx_free_elem_common(c, &x->gg, free_strs); 
}

/* FUNC(zx_NEW_wst_RequestedSecurityToken) */

/* Trivial allocator/constructor for the datatype. */

/* Called by: */
struct zx_wst_RequestedSecurityToken_s* zx_NEW_wst_RequestedSecurityToken(struct zx_ctx* c)
{
  struct zx_wst_RequestedSecurityToken_s* x = ZX_ZALLOC(c, struct zx_wst_RequestedSecurityToken_s);
  x->gg.g.tok = zx_wst_RequestedSecurityToken_ELEM;
  return x;
}

#ifdef ZX_ENA_AUX

/* FUNC(zx_DUP_STRS_wst_RequestedSecurityToken) */

/* Depth first traversal of data structure to copy its simple strings
 * to memory allocated from the memory allocator. The decoder will
 * use the underlying wireprotocol PDU buffer for strings, i.e.
 * strings are not copied - they point to the real data. If the
 * datastructure needs to outlast the protocol data or needs a different
 * memory allocation strategy, you need to call this function.  */

/* Called by: */
void zx_DUP_STRS_wst_RequestedSecurityToken(struct zx_ctx* c, struct zx_wst_RequestedSecurityToken_s* x)
{
  zx_dup_strs_common(c, &x->gg);
  /* *** deal with xmlns specifications in exc c14n way */



}

/* FUNC(zx_DEEP_CLONE_wst_RequestedSecurityToken) */

/* Depth first traversal of data structure to clone it and its sublements.
 * The simple strings are handled as a special case according to dup_strs flag. */

/* Called by: */
struct zx_wst_RequestedSecurityToken_s* zx_DEEP_CLONE_wst_RequestedSecurityToken(struct zx_ctx* c, struct zx_wst_RequestedSecurityToken_s* x, int dup_strs)
{
  x = (struct zx_wst_RequestedSecurityToken_s*)zx_clone_elem_common(c, &x->gg, sizeof(struct zx_wst_RequestedSecurityToken_s), dup_strs);
  /* *** deal with xmlns specifications in exc c14n way */



  return x;
}

/* FUNC(zx_WALK_SO_wst_RequestedSecurityToken) */

/* Depth first traversal of the tree in either schema order or the wire order. */
 
int zx_WALK_SO_wst_RequestedSecurityToken(struct zx_ctx* c, struct zx_wst_RequestedSecurityToken_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
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

/* FUNC(zx_WALK_WO_wst_RequestedSecurityToken) */

int zx_WALK_WO_wst_RequestedSecurityToken(struct zx_ctx* c, struct zx_wst_RequestedSecurityToken_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
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

#define EL_NAME   wst_RequestedUnattachedReference
#define EL_STRUCT zx_wst_RequestedUnattachedReference_s
#define EL_NS     wst
#define EL_TAG    RequestedUnattachedReference

/* FUNC(zx_FREE_wst_RequestedUnattachedReference) */

/* Depth first traversal of data structure to free it and its subelements. Simple
 * strings are handled as a special case according to the free_strs flag. This
 * is useful if the strings point to underlying data from the wire that was
 * allocated differently. */

/* Called by: */
void zx_FREE_wst_RequestedUnattachedReference(struct zx_ctx* c, struct zx_wst_RequestedUnattachedReference_s* x, int free_strs)
{
  /* *** deal with xmlns specifications in exc c14n way */


  {
      struct zx_wsse_SecurityTokenReference_s* e;
      struct zx_wsse_SecurityTokenReference_s* en;
      for (e = x->SecurityTokenReference; e; e = en) {
	  en = (struct zx_wsse_SecurityTokenReference_s*)e->gg.g.n;
	  zx_FREE_wsse_SecurityTokenReference(c, e, free_strs);
      }
  }


  zx_free_elem_common(c, &x->gg, free_strs); 
}

/* FUNC(zx_NEW_wst_RequestedUnattachedReference) */

/* Trivial allocator/constructor for the datatype. */

/* Called by: */
struct zx_wst_RequestedUnattachedReference_s* zx_NEW_wst_RequestedUnattachedReference(struct zx_ctx* c)
{
  struct zx_wst_RequestedUnattachedReference_s* x = ZX_ZALLOC(c, struct zx_wst_RequestedUnattachedReference_s);
  x->gg.g.tok = zx_wst_RequestedUnattachedReference_ELEM;
  return x;
}

#ifdef ZX_ENA_AUX

/* FUNC(zx_DUP_STRS_wst_RequestedUnattachedReference) */

/* Depth first traversal of data structure to copy its simple strings
 * to memory allocated from the memory allocator. The decoder will
 * use the underlying wireprotocol PDU buffer for strings, i.e.
 * strings are not copied - they point to the real data. If the
 * datastructure needs to outlast the protocol data or needs a different
 * memory allocation strategy, you need to call this function.  */

/* Called by: */
void zx_DUP_STRS_wst_RequestedUnattachedReference(struct zx_ctx* c, struct zx_wst_RequestedUnattachedReference_s* x)
{
  zx_dup_strs_common(c, &x->gg);
  /* *** deal with xmlns specifications in exc c14n way */


  {
      struct zx_wsse_SecurityTokenReference_s* e;
      for (e = x->SecurityTokenReference; e; e = (struct zx_wsse_SecurityTokenReference_s*)e->gg.g.n)
	  zx_DUP_STRS_wsse_SecurityTokenReference(c, e);
  }

}

/* FUNC(zx_DEEP_CLONE_wst_RequestedUnattachedReference) */

/* Depth first traversal of data structure to clone it and its sublements.
 * The simple strings are handled as a special case according to dup_strs flag. */

/* Called by: */
struct zx_wst_RequestedUnattachedReference_s* zx_DEEP_CLONE_wst_RequestedUnattachedReference(struct zx_ctx* c, struct zx_wst_RequestedUnattachedReference_s* x, int dup_strs)
{
  x = (struct zx_wst_RequestedUnattachedReference_s*)zx_clone_elem_common(c, &x->gg, sizeof(struct zx_wst_RequestedUnattachedReference_s), dup_strs);
  /* *** deal with xmlns specifications in exc c14n way */


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

  return x;
}

/* FUNC(zx_WALK_SO_wst_RequestedUnattachedReference) */

/* Depth first traversal of the tree in either schema order or the wire order. */
 
int zx_WALK_SO_wst_RequestedUnattachedReference(struct zx_ctx* c, struct zx_wst_RequestedUnattachedReference_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
{
  int ret = callback(&x->gg.g, ctx);
  if (ret)
    return ret;
  
  /* *** deal with xmlns specifications in exc c14n way */


  
  ret = zx_walk_so_unknown_attributes(c, &x->gg, ctx, callback); 
  if (ret)
    return ret;

  {
      struct zx_wsse_SecurityTokenReference_s* e;
      for (e = x->SecurityTokenReference; e; e = (struct zx_wsse_SecurityTokenReference_s*)e->gg.g.n) {
	  ret = zx_WALK_SO_wsse_SecurityTokenReference(c, e, ctx, callback);
	  if (ret)
	      return ret;
      }
  }

  
  return zx_walk_so_unknown_elems_and_content(c, &x->gg, ctx, callback);
}

/* FUNC(zx_WALK_WO_wst_RequestedUnattachedReference) */

int zx_WALK_WO_wst_RequestedUnattachedReference(struct zx_ctx* c, struct zx_wst_RequestedUnattachedReference_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
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

#define EL_NAME   wst_SignChallenge
#define EL_STRUCT zx_wst_SignChallenge_s
#define EL_NS     wst
#define EL_TAG    SignChallenge

/* FUNC(zx_FREE_wst_SignChallenge) */

/* Depth first traversal of data structure to free it and its subelements. Simple
 * strings are handled as a special case according to the free_strs flag. This
 * is useful if the strings point to underlying data from the wire that was
 * allocated differently. */

/* Called by: */
void zx_FREE_wst_SignChallenge(struct zx_ctx* c, struct zx_wst_SignChallenge_s* x, int free_strs)
{
  /* *** deal with xmlns specifications in exc c14n way */


  zx_free_simple_elems(c, x->Challenge, free_strs);


  zx_free_elem_common(c, &x->gg, free_strs); 
}

/* FUNC(zx_NEW_wst_SignChallenge) */

/* Trivial allocator/constructor for the datatype. */

/* Called by: */
struct zx_wst_SignChallenge_s* zx_NEW_wst_SignChallenge(struct zx_ctx* c)
{
  struct zx_wst_SignChallenge_s* x = ZX_ZALLOC(c, struct zx_wst_SignChallenge_s);
  x->gg.g.tok = zx_wst_SignChallenge_ELEM;
  return x;
}

#ifdef ZX_ENA_AUX

/* FUNC(zx_DUP_STRS_wst_SignChallenge) */

/* Depth first traversal of data structure to copy its simple strings
 * to memory allocated from the memory allocator. The decoder will
 * use the underlying wireprotocol PDU buffer for strings, i.e.
 * strings are not copied - they point to the real data. If the
 * datastructure needs to outlast the protocol data or needs a different
 * memory allocation strategy, you need to call this function.  */

/* Called by: */
void zx_DUP_STRS_wst_SignChallenge(struct zx_ctx* c, struct zx_wst_SignChallenge_s* x)
{
  zx_dup_strs_common(c, &x->gg);
  /* *** deal with xmlns specifications in exc c14n way */


  zx_dup_strs_simple_elems(c, x->Challenge);

}

/* FUNC(zx_DEEP_CLONE_wst_SignChallenge) */

/* Depth first traversal of data structure to clone it and its sublements.
 * The simple strings are handled as a special case according to dup_strs flag. */

/* Called by: */
struct zx_wst_SignChallenge_s* zx_DEEP_CLONE_wst_SignChallenge(struct zx_ctx* c, struct zx_wst_SignChallenge_s* x, int dup_strs)
{
  x = (struct zx_wst_SignChallenge_s*)zx_clone_elem_common(c, &x->gg, sizeof(struct zx_wst_SignChallenge_s), dup_strs);
  /* *** deal with xmlns specifications in exc c14n way */


  x->Challenge = zx_deep_clone_simple_elems(c,x->Challenge, dup_strs);

  return x;
}

/* FUNC(zx_WALK_SO_wst_SignChallenge) */

/* Depth first traversal of the tree in either schema order or the wire order. */
 
int zx_WALK_SO_wst_SignChallenge(struct zx_ctx* c, struct zx_wst_SignChallenge_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
{
  int ret = callback(&x->gg.g, ctx);
  if (ret)
    return ret;
  
  /* *** deal with xmlns specifications in exc c14n way */


  
  ret = zx_walk_so_unknown_attributes(c, &x->gg, ctx, callback); 
  if (ret)
    return ret;

  ret = zx_walk_so_simple_elems(c, x->Challenge, ctx, callback);
  if (ret)
    return ret;

  
  return zx_walk_so_unknown_elems_and_content(c, &x->gg, ctx, callback);
}

/* FUNC(zx_WALK_WO_wst_SignChallenge) */

int zx_WALK_WO_wst_SignChallenge(struct zx_ctx* c, struct zx_wst_SignChallenge_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
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

#define EL_NAME   wst_SignChallengeResponse
#define EL_STRUCT zx_wst_SignChallengeResponse_s
#define EL_NS     wst
#define EL_TAG    SignChallengeResponse

/* FUNC(zx_FREE_wst_SignChallengeResponse) */

/* Depth first traversal of data structure to free it and its subelements. Simple
 * strings are handled as a special case according to the free_strs flag. This
 * is useful if the strings point to underlying data from the wire that was
 * allocated differently. */

/* Called by: */
void zx_FREE_wst_SignChallengeResponse(struct zx_ctx* c, struct zx_wst_SignChallengeResponse_s* x, int free_strs)
{
  /* *** deal with xmlns specifications in exc c14n way */


  zx_free_simple_elems(c, x->Challenge, free_strs);


  zx_free_elem_common(c, &x->gg, free_strs); 
}

/* FUNC(zx_NEW_wst_SignChallengeResponse) */

/* Trivial allocator/constructor for the datatype. */

/* Called by: */
struct zx_wst_SignChallengeResponse_s* zx_NEW_wst_SignChallengeResponse(struct zx_ctx* c)
{
  struct zx_wst_SignChallengeResponse_s* x = ZX_ZALLOC(c, struct zx_wst_SignChallengeResponse_s);
  x->gg.g.tok = zx_wst_SignChallengeResponse_ELEM;
  return x;
}

#ifdef ZX_ENA_AUX

/* FUNC(zx_DUP_STRS_wst_SignChallengeResponse) */

/* Depth first traversal of data structure to copy its simple strings
 * to memory allocated from the memory allocator. The decoder will
 * use the underlying wireprotocol PDU buffer for strings, i.e.
 * strings are not copied - they point to the real data. If the
 * datastructure needs to outlast the protocol data or needs a different
 * memory allocation strategy, you need to call this function.  */

/* Called by: */
void zx_DUP_STRS_wst_SignChallengeResponse(struct zx_ctx* c, struct zx_wst_SignChallengeResponse_s* x)
{
  zx_dup_strs_common(c, &x->gg);
  /* *** deal with xmlns specifications in exc c14n way */


  zx_dup_strs_simple_elems(c, x->Challenge);

}

/* FUNC(zx_DEEP_CLONE_wst_SignChallengeResponse) */

/* Depth first traversal of data structure to clone it and its sublements.
 * The simple strings are handled as a special case according to dup_strs flag. */

/* Called by: */
struct zx_wst_SignChallengeResponse_s* zx_DEEP_CLONE_wst_SignChallengeResponse(struct zx_ctx* c, struct zx_wst_SignChallengeResponse_s* x, int dup_strs)
{
  x = (struct zx_wst_SignChallengeResponse_s*)zx_clone_elem_common(c, &x->gg, sizeof(struct zx_wst_SignChallengeResponse_s), dup_strs);
  /* *** deal with xmlns specifications in exc c14n way */


  x->Challenge = zx_deep_clone_simple_elems(c,x->Challenge, dup_strs);

  return x;
}

/* FUNC(zx_WALK_SO_wst_SignChallengeResponse) */

/* Depth first traversal of the tree in either schema order or the wire order. */
 
int zx_WALK_SO_wst_SignChallengeResponse(struct zx_ctx* c, struct zx_wst_SignChallengeResponse_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
{
  int ret = callback(&x->gg.g, ctx);
  if (ret)
    return ret;
  
  /* *** deal with xmlns specifications in exc c14n way */


  
  ret = zx_walk_so_unknown_attributes(c, &x->gg, ctx, callback); 
  if (ret)
    return ret;

  ret = zx_walk_so_simple_elems(c, x->Challenge, ctx, callback);
  if (ret)
    return ret;

  
  return zx_walk_so_unknown_elems_and_content(c, &x->gg, ctx, callback);
}

/* FUNC(zx_WALK_WO_wst_SignChallengeResponse) */

int zx_WALK_WO_wst_SignChallengeResponse(struct zx_ctx* c, struct zx_wst_SignChallengeResponse_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
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

#define EL_NAME   wst_Status
#define EL_STRUCT zx_wst_Status_s
#define EL_NS     wst
#define EL_TAG    Status

/* FUNC(zx_FREE_wst_Status) */

/* Depth first traversal of data structure to free it and its subelements. Simple
 * strings are handled as a special case according to the free_strs flag. This
 * is useful if the strings point to underlying data from the wire that was
 * allocated differently. */

/* Called by: */
void zx_FREE_wst_Status(struct zx_ctx* c, struct zx_wst_Status_s* x, int free_strs)
{
  /* *** deal with xmlns specifications in exc c14n way */


  zx_free_simple_elems(c, x->Code, free_strs);
  zx_free_simple_elems(c, x->Reason, free_strs);


  zx_free_elem_common(c, &x->gg, free_strs); 
}

/* FUNC(zx_NEW_wst_Status) */

/* Trivial allocator/constructor for the datatype. */

/* Called by: */
struct zx_wst_Status_s* zx_NEW_wst_Status(struct zx_ctx* c)
{
  struct zx_wst_Status_s* x = ZX_ZALLOC(c, struct zx_wst_Status_s);
  x->gg.g.tok = zx_wst_Status_ELEM;
  return x;
}

#ifdef ZX_ENA_AUX

/* FUNC(zx_DUP_STRS_wst_Status) */

/* Depth first traversal of data structure to copy its simple strings
 * to memory allocated from the memory allocator. The decoder will
 * use the underlying wireprotocol PDU buffer for strings, i.e.
 * strings are not copied - they point to the real data. If the
 * datastructure needs to outlast the protocol data or needs a different
 * memory allocation strategy, you need to call this function.  */

/* Called by: */
void zx_DUP_STRS_wst_Status(struct zx_ctx* c, struct zx_wst_Status_s* x)
{
  zx_dup_strs_common(c, &x->gg);
  /* *** deal with xmlns specifications in exc c14n way */


  zx_dup_strs_simple_elems(c, x->Code);
  zx_dup_strs_simple_elems(c, x->Reason);

}

/* FUNC(zx_DEEP_CLONE_wst_Status) */

/* Depth first traversal of data structure to clone it and its sublements.
 * The simple strings are handled as a special case according to dup_strs flag. */

/* Called by: */
struct zx_wst_Status_s* zx_DEEP_CLONE_wst_Status(struct zx_ctx* c, struct zx_wst_Status_s* x, int dup_strs)
{
  x = (struct zx_wst_Status_s*)zx_clone_elem_common(c, &x->gg, sizeof(struct zx_wst_Status_s), dup_strs);
  /* *** deal with xmlns specifications in exc c14n way */


  x->Code = zx_deep_clone_simple_elems(c,x->Code, dup_strs);
  x->Reason = zx_deep_clone_simple_elems(c,x->Reason, dup_strs);

  return x;
}

/* FUNC(zx_WALK_SO_wst_Status) */

/* Depth first traversal of the tree in either schema order or the wire order. */
 
int zx_WALK_SO_wst_Status(struct zx_ctx* c, struct zx_wst_Status_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
{
  int ret = callback(&x->gg.g, ctx);
  if (ret)
    return ret;
  
  /* *** deal with xmlns specifications in exc c14n way */


  
  ret = zx_walk_so_unknown_attributes(c, &x->gg, ctx, callback); 
  if (ret)
    return ret;

  ret = zx_walk_so_simple_elems(c, x->Code, ctx, callback);
  if (ret)
    return ret;
  ret = zx_walk_so_simple_elems(c, x->Reason, ctx, callback);
  if (ret)
    return ret;

  
  return zx_walk_so_unknown_elems_and_content(c, &x->gg, ctx, callback);
}

/* FUNC(zx_WALK_WO_wst_Status) */

int zx_WALK_WO_wst_Status(struct zx_ctx* c, struct zx_wst_Status_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
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

#define EL_NAME   wst_UseKey
#define EL_STRUCT zx_wst_UseKey_s
#define EL_NS     wst
#define EL_TAG    UseKey

/* FUNC(zx_FREE_wst_UseKey) */

/* Depth first traversal of data structure to free it and its subelements. Simple
 * strings are handled as a special case according to the free_strs flag. This
 * is useful if the strings point to underlying data from the wire that was
 * allocated differently. */

/* Called by: */
void zx_FREE_wst_UseKey(struct zx_ctx* c, struct zx_wst_UseKey_s* x, int free_strs)
{
  /* *** deal with xmlns specifications in exc c14n way */

  zx_free_attr(c, x->Sig, free_strs);



  zx_free_elem_common(c, &x->gg, free_strs); 
}

/* FUNC(zx_NEW_wst_UseKey) */

/* Trivial allocator/constructor for the datatype. */

/* Called by: */
struct zx_wst_UseKey_s* zx_NEW_wst_UseKey(struct zx_ctx* c)
{
  struct zx_wst_UseKey_s* x = ZX_ZALLOC(c, struct zx_wst_UseKey_s);
  x->gg.g.tok = zx_wst_UseKey_ELEM;
  return x;
}

#ifdef ZX_ENA_AUX

/* FUNC(zx_DUP_STRS_wst_UseKey) */

/* Depth first traversal of data structure to copy its simple strings
 * to memory allocated from the memory allocator. The decoder will
 * use the underlying wireprotocol PDU buffer for strings, i.e.
 * strings are not copied - they point to the real data. If the
 * datastructure needs to outlast the protocol data or needs a different
 * memory allocation strategy, you need to call this function.  */

/* Called by: */
void zx_DUP_STRS_wst_UseKey(struct zx_ctx* c, struct zx_wst_UseKey_s* x)
{
  zx_dup_strs_common(c, &x->gg);
  /* *** deal with xmlns specifications in exc c14n way */

  zx_dup_attr(c, x->Sig);


}

/* FUNC(zx_DEEP_CLONE_wst_UseKey) */

/* Depth first traversal of data structure to clone it and its sublements.
 * The simple strings are handled as a special case according to dup_strs flag. */

/* Called by: */
struct zx_wst_UseKey_s* zx_DEEP_CLONE_wst_UseKey(struct zx_ctx* c, struct zx_wst_UseKey_s* x, int dup_strs)
{
  x = (struct zx_wst_UseKey_s*)zx_clone_elem_common(c, &x->gg, sizeof(struct zx_wst_UseKey_s), dup_strs);
  /* *** deal with xmlns specifications in exc c14n way */

  x->Sig = zx_clone_attr(c, x->Sig);


  return x;
}

/* FUNC(zx_WALK_SO_wst_UseKey) */

/* Depth first traversal of the tree in either schema order or the wire order. */
 
int zx_WALK_SO_wst_UseKey(struct zx_ctx* c, struct zx_wst_UseKey_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
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

/* FUNC(zx_WALK_WO_wst_UseKey) */

int zx_WALK_WO_wst_UseKey(struct zx_ctx* c, struct zx_wst_UseKey_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
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

#define EL_NAME   wst_ValidateTarget
#define EL_STRUCT zx_wst_ValidateTarget_s
#define EL_NS     wst
#define EL_TAG    ValidateTarget

/* FUNC(zx_FREE_wst_ValidateTarget) */

/* Depth first traversal of data structure to free it and its subelements. Simple
 * strings are handled as a special case according to the free_strs flag. This
 * is useful if the strings point to underlying data from the wire that was
 * allocated differently. */

/* Called by: */
void zx_FREE_wst_ValidateTarget(struct zx_ctx* c, struct zx_wst_ValidateTarget_s* x, int free_strs)
{
  /* *** deal with xmlns specifications in exc c14n way */




  zx_free_elem_common(c, &x->gg, free_strs); 
}

/* FUNC(zx_NEW_wst_ValidateTarget) */

/* Trivial allocator/constructor for the datatype. */

/* Called by: */
struct zx_wst_ValidateTarget_s* zx_NEW_wst_ValidateTarget(struct zx_ctx* c)
{
  struct zx_wst_ValidateTarget_s* x = ZX_ZALLOC(c, struct zx_wst_ValidateTarget_s);
  x->gg.g.tok = zx_wst_ValidateTarget_ELEM;
  return x;
}

#ifdef ZX_ENA_AUX

/* FUNC(zx_DUP_STRS_wst_ValidateTarget) */

/* Depth first traversal of data structure to copy its simple strings
 * to memory allocated from the memory allocator. The decoder will
 * use the underlying wireprotocol PDU buffer for strings, i.e.
 * strings are not copied - they point to the real data. If the
 * datastructure needs to outlast the protocol data or needs a different
 * memory allocation strategy, you need to call this function.  */

/* Called by: */
void zx_DUP_STRS_wst_ValidateTarget(struct zx_ctx* c, struct zx_wst_ValidateTarget_s* x)
{
  zx_dup_strs_common(c, &x->gg);
  /* *** deal with xmlns specifications in exc c14n way */



}

/* FUNC(zx_DEEP_CLONE_wst_ValidateTarget) */

/* Depth first traversal of data structure to clone it and its sublements.
 * The simple strings are handled as a special case according to dup_strs flag. */

/* Called by: */
struct zx_wst_ValidateTarget_s* zx_DEEP_CLONE_wst_ValidateTarget(struct zx_ctx* c, struct zx_wst_ValidateTarget_s* x, int dup_strs)
{
  x = (struct zx_wst_ValidateTarget_s*)zx_clone_elem_common(c, &x->gg, sizeof(struct zx_wst_ValidateTarget_s), dup_strs);
  /* *** deal with xmlns specifications in exc c14n way */



  return x;
}

/* FUNC(zx_WALK_SO_wst_ValidateTarget) */

/* Depth first traversal of the tree in either schema order or the wire order. */
 
int zx_WALK_SO_wst_ValidateTarget(struct zx_ctx* c, struct zx_wst_ValidateTarget_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
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

/* FUNC(zx_WALK_WO_wst_ValidateTarget) */

int zx_WALK_WO_wst_ValidateTarget(struct zx_ctx* c, struct zx_wst_ValidateTarget_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
{
  ERR("*** walk_wo not implemented %d", 0);
  return 0;
}

#endif


/* EOF -- c/zx-wst-aux.c */
