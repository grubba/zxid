/* c/zx-tas3sol-aux.c - WARNING: This file was automatically generated. DO NOT EDIT!
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
#include "c/zx-tas3sol-data.h"



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

#define EL_NAME   tas3sol_Dict
#define EL_STRUCT zx_tas3sol_Dict_s
#define EL_NS     tas3sol
#define EL_TAG    Dict

/* FUNC(zx_FREE_tas3sol_Dict) */

/* Depth first traversal of data structure to free it and its subelements. Simple
 * strings are handled as a special case according to the free_strs flag. This
 * is useful if the strings point to underlying data from the wire that was
 * allocated differently. */

/* Called by: */
void zx_FREE_tas3sol_Dict(struct zx_ctx* c, struct zx_tas3sol_Dict_s* x, int free_strs)
{
  /* *** deal with xmlns specifications in exc c14n way */




  zx_free_elem_common(c, &x->gg, free_strs); 
}

/* FUNC(zx_NEW_tas3sol_Dict) */

/* Trivial allocator/constructor for the datatype. */

/* Called by: */
struct zx_tas3sol_Dict_s* zx_NEW_tas3sol_Dict(struct zx_ctx* c)
{
  struct zx_tas3sol_Dict_s* x = ZX_ZALLOC(c, struct zx_tas3sol_Dict_s);
  x->gg.g.tok = zx_tas3sol_Dict_ELEM;
  return x;
}

#ifdef ZX_ENA_AUX

/* FUNC(zx_DUP_STRS_tas3sol_Dict) */

/* Depth first traversal of data structure to copy its simple strings
 * to memory allocated from the memory allocator. The decoder will
 * use the underlying wireprotocol PDU buffer for strings, i.e.
 * strings are not copied - they point to the real data. If the
 * datastructure needs to outlast the protocol data or needs a different
 * memory allocation strategy, you need to call this function.  */

/* Called by: */
void zx_DUP_STRS_tas3sol_Dict(struct zx_ctx* c, struct zx_tas3sol_Dict_s* x)
{
  zx_dup_strs_common(c, &x->gg);
  /* *** deal with xmlns specifications in exc c14n way */



}

/* FUNC(zx_DEEP_CLONE_tas3sol_Dict) */

/* Depth first traversal of data structure to clone it and its sublements.
 * The simple strings are handled as a special case according to dup_strs flag. */

/* Called by: */
struct zx_tas3sol_Dict_s* zx_DEEP_CLONE_tas3sol_Dict(struct zx_ctx* c, struct zx_tas3sol_Dict_s* x, int dup_strs)
{
  x = (struct zx_tas3sol_Dict_s*)zx_clone_elem_common(c, &x->gg, sizeof(struct zx_tas3sol_Dict_s), dup_strs);
  /* *** deal with xmlns specifications in exc c14n way */



  return x;
}

/* FUNC(zx_WALK_SO_tas3sol_Dict) */

/* Depth first traversal of the tree in either schema order or the wire order. */
 
int zx_WALK_SO_tas3sol_Dict(struct zx_ctx* c, struct zx_tas3sol_Dict_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
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

/* FUNC(zx_WALK_WO_tas3sol_Dict) */

int zx_WALK_WO_tas3sol_Dict(struct zx_ctx* c, struct zx_tas3sol_Dict_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
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

#define EL_NAME   tas3sol_Obligations
#define EL_STRUCT zx_tas3sol_Obligations_s
#define EL_NS     tas3sol
#define EL_TAG    Obligations

/* FUNC(zx_FREE_tas3sol_Obligations) */

/* Depth first traversal of data structure to free it and its subelements. Simple
 * strings are handled as a special case according to the free_strs flag. This
 * is useful if the strings point to underlying data from the wire that was
 * allocated differently. */

/* Called by: */
void zx_FREE_tas3sol_Obligations(struct zx_ctx* c, struct zx_tas3sol_Obligations_s* x, int free_strs)
{
  /* *** deal with xmlns specifications in exc c14n way */




  zx_free_elem_common(c, &x->gg, free_strs); 
}

/* FUNC(zx_NEW_tas3sol_Obligations) */

/* Trivial allocator/constructor for the datatype. */

/* Called by: */
struct zx_tas3sol_Obligations_s* zx_NEW_tas3sol_Obligations(struct zx_ctx* c)
{
  struct zx_tas3sol_Obligations_s* x = ZX_ZALLOC(c, struct zx_tas3sol_Obligations_s);
  x->gg.g.tok = zx_tas3sol_Obligations_ELEM;
  return x;
}

#ifdef ZX_ENA_AUX

/* FUNC(zx_DUP_STRS_tas3sol_Obligations) */

/* Depth first traversal of data structure to copy its simple strings
 * to memory allocated from the memory allocator. The decoder will
 * use the underlying wireprotocol PDU buffer for strings, i.e.
 * strings are not copied - they point to the real data. If the
 * datastructure needs to outlast the protocol data or needs a different
 * memory allocation strategy, you need to call this function.  */

/* Called by: */
void zx_DUP_STRS_tas3sol_Obligations(struct zx_ctx* c, struct zx_tas3sol_Obligations_s* x)
{
  zx_dup_strs_common(c, &x->gg);
  /* *** deal with xmlns specifications in exc c14n way */



}

/* FUNC(zx_DEEP_CLONE_tas3sol_Obligations) */

/* Depth first traversal of data structure to clone it and its sublements.
 * The simple strings are handled as a special case according to dup_strs flag. */

/* Called by: */
struct zx_tas3sol_Obligations_s* zx_DEEP_CLONE_tas3sol_Obligations(struct zx_ctx* c, struct zx_tas3sol_Obligations_s* x, int dup_strs)
{
  x = (struct zx_tas3sol_Obligations_s*)zx_clone_elem_common(c, &x->gg, sizeof(struct zx_tas3sol_Obligations_s), dup_strs);
  /* *** deal with xmlns specifications in exc c14n way */



  return x;
}

/* FUNC(zx_WALK_SO_tas3sol_Obligations) */

/* Depth first traversal of the tree in either schema order or the wire order. */
 
int zx_WALK_SO_tas3sol_Obligations(struct zx_ctx* c, struct zx_tas3sol_Obligations_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
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

/* FUNC(zx_WALK_WO_tas3sol_Obligations) */

int zx_WALK_WO_tas3sol_Obligations(struct zx_ctx* c, struct zx_tas3sol_Obligations_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
{
  ERR("*** walk_wo not implemented %d", 0);
  return 0;
}

#endif


/* EOF -- c/zx-tas3sol-aux.c */
