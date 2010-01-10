/** aux-templ.c  -  Auxiliary functions template: cloning, freeing, walking data
 ** Copyright (c) 2006 Symlabs (symlabs@symlabs.com), All Rights Reserved.
 ** Author: Sampo Kellomaki (sampo@iki.fi)
 ** This is confidential unpublished proprietary source code of the author.
 ** NO WARRANTY, not even implied warranties. Contains trade secrets.
 ** Distribution prohibited unless authorized in writing.
 ** Licensed under Apache License 2.0, see file COPYING.
 ** $Id: aux-templ.c,v 1.12 2008-10-04 23:42:14 sampo Exp $
 **
 ** 30.5.2006, created, Sampo Kellomaki (sampo@iki.fi)
 ** 6.8.2006, factored from enc-templ.c to separate file --Sampo
 **
 ** N.B: wo=wire order (needed for exc-c14n), so=schema order
 **/

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

#define EL_NAME   ELNAME
#define EL_STRUCT ELSTRUCT
#define EL_NS     ELNS
#define EL_TAG    ELTAG

/* FUNC(TXFREE_ELNAME) */

/* Depth first traversal of data structure to free it and its subelements. Simple
 * strings are handled as a special case according to the free_strs flag. This
 * is useful if the strings point to underlying data from the wire that was
 * allocated differently. */

/* Called by: */
void TXFREE_ELNAME(struct zx_ctx* c, struct ELSTRUCT* x, int free_strs)
{
  /* *** deal with xmlns specifications in exc c14n way */

ATTRS_FREE;
ELEMS_FREE;

  zx_free_elem_common(c, &x->gg, free_strs); 
}

/* FUNC(TXNEW_ELNAME) */

/* Trivial allocator/constructor for the datatype. */

/* Called by: */
struct ELSTRUCT* TXNEW_ELNAME(struct zx_ctx* c)
{
  struct ELSTRUCT* x = ZX_ZALLOC(c, struct ELSTRUCT);
  x->gg.g.tok = TXELNAME_ELEM;
  return x;
}

#ifdef ZX_ENA_AUX

/* FUNC(TXDUP_STRS_ELNAME) */

/* Depth first traversal of data structure to copy its simple strings
 * to memory allocated from the memory allocator. The decoder will
 * use the underlying wireprotocol PDU buffer for strings, i.e.
 * strings are not copied - they point to the real data. If the
 * datastructure needs to outlast the protocol data or needs a different
 * memory allocation strategy, you need to call this function.  */

/* Called by: */
void TXDUP_STRS_ELNAME(struct zx_ctx* c, struct ELSTRUCT* x)
{
  zx_dup_strs_common(c, &x->gg);
  /* *** deal with xmlns specifications in exc c14n way */

ATTRS_DUP_STRS;
ELEMS_DUP_STRS;
}

/* FUNC(TXDEEP_CLONE_ELNAME) */

/* Depth first traversal of data structure to clone it and its sublements.
 * The simple strings are handled as a special case according to dup_strs flag. */

/* Called by: */
struct ELSTRUCT* TXDEEP_CLONE_ELNAME(struct zx_ctx* c, struct ELSTRUCT* x, int dup_strs)
{
  x = (struct ELSTRUCT*)zx_clone_elem_common(c, &x->gg, sizeof(struct ELSTRUCT), dup_strs);
  /* *** deal with xmlns specifications in exc c14n way */

ATTRS_CLONE;
ELEMS_CLONE;
  return x;
}

/* FUNC(TXWALK_SO_ELNAME) */

/* Depth first traversal of the tree in either schema order or the wire order. */
 
int TXWALK_SO_ELNAME(struct zx_ctx* c, struct ELSTRUCT* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
{
  int ret = callback(&x->gg.g, ctx);
  if (ret)
    return ret;
  
  /* *** deal with xmlns specifications in exc c14n way */

ATTRS_WALK_SO;
  
  ret = zx_walk_so_unknown_attributes(c, &x->gg, ctx, callback); 
  if (ret)
    return ret;

ELEMS_WALK_SO;
  
  return zx_walk_so_unknown_elems_and_content(c, &x->gg, ctx, callback);
}

/* FUNC(TXWALK_WO_ELNAME) */

int TXWALK_WO_ELNAME(struct zx_ctx* c, struct ELSTRUCT* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
{
  ERR("*** walk_wo not implemented %d", 0);
  return 0;
}

#endif

/* EOF */
