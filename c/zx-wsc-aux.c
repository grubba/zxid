/* c/zx-wsc-aux.c - WARNING: This file was automatically generated. DO NOT EDIT!
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
#include "c/zx-wsc-data.h"



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

#define EL_NAME   wsc_DerivedKeyToken
#define EL_STRUCT zx_wsc_DerivedKeyToken_s
#define EL_NS     wsc
#define EL_TAG    DerivedKeyToken

/* FUNC(zx_FREE_wsc_DerivedKeyToken) */

/* Depth first traversal of data structure to free it and its subelements. Simple
 * strings are handled as a special case according to the free_strs flag. This
 * is useful if the strings point to underlying data from the wire that was
 * allocated differently. */

/* Called by: */
void zx_FREE_wsc_DerivedKeyToken(struct zx_ctx* c, struct zx_wsc_DerivedKeyToken_s* x, int free_strs)
{
  /* *** deal with xmlns specifications in exc c14n way */

  zx_free_attr(c, x->Algorithm, free_strs);
  zx_free_attr(c, x->Id, free_strs);

  {
      struct zx_wsse_SecurityTokenReference_s* e;
      struct zx_wsse_SecurityTokenReference_s* en;
      for (e = x->SecurityTokenReference; e; e = en) {
	  en = (struct zx_wsse_SecurityTokenReference_s*)e->gg.g.n;
	  zx_FREE_wsse_SecurityTokenReference(c, e, free_strs);
      }
  }
  {
      struct zx_wsc_Properties_s* e;
      struct zx_wsc_Properties_s* en;
      for (e = x->Properties; e; e = en) {
	  en = (struct zx_wsc_Properties_s*)e->gg.g.n;
	  zx_FREE_wsc_Properties(c, e, free_strs);
      }
  }
  zx_free_simple_elems(c, x->Generation, free_strs);
  zx_free_simple_elems(c, x->Offset, free_strs);
  zx_free_simple_elems(c, x->Length, free_strs);
  zx_free_simple_elems(c, x->Label, free_strs);
  zx_free_simple_elems(c, x->Nonce, free_strs);


  zx_free_elem_common(c, &x->gg, free_strs); 
}

/* FUNC(zx_NEW_wsc_DerivedKeyToken) */

/* Trivial allocator/constructor for the datatype. */

/* Called by: */
struct zx_wsc_DerivedKeyToken_s* zx_NEW_wsc_DerivedKeyToken(struct zx_ctx* c)
{
  struct zx_wsc_DerivedKeyToken_s* x = ZX_ZALLOC(c, struct zx_wsc_DerivedKeyToken_s);
  x->gg.g.tok = zx_wsc_DerivedKeyToken_ELEM;
  return x;
}

#ifdef ZX_ENA_AUX

/* FUNC(zx_DUP_STRS_wsc_DerivedKeyToken) */

/* Depth first traversal of data structure to copy its simple strings
 * to memory allocated from the memory allocator. The decoder will
 * use the underlying wireprotocol PDU buffer for strings, i.e.
 * strings are not copied - they point to the real data. If the
 * datastructure needs to outlast the protocol data or needs a different
 * memory allocation strategy, you need to call this function.  */

/* Called by: */
void zx_DUP_STRS_wsc_DerivedKeyToken(struct zx_ctx* c, struct zx_wsc_DerivedKeyToken_s* x)
{
  zx_dup_strs_common(c, &x->gg);
  /* *** deal with xmlns specifications in exc c14n way */

  zx_dup_attr(c, x->Algorithm);
  zx_dup_attr(c, x->Id);

  {
      struct zx_wsse_SecurityTokenReference_s* e;
      for (e = x->SecurityTokenReference; e; e = (struct zx_wsse_SecurityTokenReference_s*)e->gg.g.n)
	  zx_DUP_STRS_wsse_SecurityTokenReference(c, e);
  }
  {
      struct zx_wsc_Properties_s* e;
      for (e = x->Properties; e; e = (struct zx_wsc_Properties_s*)e->gg.g.n)
	  zx_DUP_STRS_wsc_Properties(c, e);
  }
  zx_dup_strs_simple_elems(c, x->Generation);
  zx_dup_strs_simple_elems(c, x->Offset);
  zx_dup_strs_simple_elems(c, x->Length);
  zx_dup_strs_simple_elems(c, x->Label);
  zx_dup_strs_simple_elems(c, x->Nonce);

}

/* FUNC(zx_DEEP_CLONE_wsc_DerivedKeyToken) */

/* Depth first traversal of data structure to clone it and its sublements.
 * The simple strings are handled as a special case according to dup_strs flag. */

/* Called by: */
struct zx_wsc_DerivedKeyToken_s* zx_DEEP_CLONE_wsc_DerivedKeyToken(struct zx_ctx* c, struct zx_wsc_DerivedKeyToken_s* x, int dup_strs)
{
  x = (struct zx_wsc_DerivedKeyToken_s*)zx_clone_elem_common(c, &x->gg, sizeof(struct zx_wsc_DerivedKeyToken_s), dup_strs);
  /* *** deal with xmlns specifications in exc c14n way */

  x->Algorithm = zx_clone_attr(c, x->Algorithm);
  x->Id = zx_clone_attr(c, x->Id);

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
      struct zx_wsc_Properties_s* e;
      struct zx_wsc_Properties_s* en;
      struct zx_wsc_Properties_s* enn;
      for (enn = 0, e = x->Properties; e; e = (struct zx_wsc_Properties_s*)e->gg.g.n) {
	  en = zx_DEEP_CLONE_wsc_Properties(c, e, dup_strs);
	  if (!enn)
	      x->Properties = en;
	  else
	      enn->gg.g.n = &en->gg.g;
	  enn = en;
      }
  }
  x->Generation = zx_deep_clone_simple_elems(c,x->Generation, dup_strs);
  x->Offset = zx_deep_clone_simple_elems(c,x->Offset, dup_strs);
  x->Length = zx_deep_clone_simple_elems(c,x->Length, dup_strs);
  x->Label = zx_deep_clone_simple_elems(c,x->Label, dup_strs);
  x->Nonce = zx_deep_clone_simple_elems(c,x->Nonce, dup_strs);

  return x;
}

/* FUNC(zx_WALK_SO_wsc_DerivedKeyToken) */

/* Depth first traversal of the tree in either schema order or the wire order. */
 
int zx_WALK_SO_wsc_DerivedKeyToken(struct zx_ctx* c, struct zx_wsc_DerivedKeyToken_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
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
  {
      struct zx_wsc_Properties_s* e;
      for (e = x->Properties; e; e = (struct zx_wsc_Properties_s*)e->gg.g.n) {
	  ret = zx_WALK_SO_wsc_Properties(c, e, ctx, callback);
	  if (ret)
	      return ret;
      }
  }
  ret = zx_walk_so_simple_elems(c, x->Generation, ctx, callback);
  if (ret)
    return ret;
  ret = zx_walk_so_simple_elems(c, x->Offset, ctx, callback);
  if (ret)
    return ret;
  ret = zx_walk_so_simple_elems(c, x->Length, ctx, callback);
  if (ret)
    return ret;
  ret = zx_walk_so_simple_elems(c, x->Label, ctx, callback);
  if (ret)
    return ret;
  ret = zx_walk_so_simple_elems(c, x->Nonce, ctx, callback);
  if (ret)
    return ret;

  
  return zx_walk_so_unknown_elems_and_content(c, &x->gg, ctx, callback);
}

/* FUNC(zx_WALK_WO_wsc_DerivedKeyToken) */

int zx_WALK_WO_wsc_DerivedKeyToken(struct zx_ctx* c, struct zx_wsc_DerivedKeyToken_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
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

#define EL_NAME   wsc_Properties
#define EL_STRUCT zx_wsc_Properties_s
#define EL_NS     wsc
#define EL_TAG    Properties

/* FUNC(zx_FREE_wsc_Properties) */

/* Depth first traversal of data structure to free it and its subelements. Simple
 * strings are handled as a special case according to the free_strs flag. This
 * is useful if the strings point to underlying data from the wire that was
 * allocated differently. */

/* Called by: */
void zx_FREE_wsc_Properties(struct zx_ctx* c, struct zx_wsc_Properties_s* x, int free_strs)
{
  /* *** deal with xmlns specifications in exc c14n way */




  zx_free_elem_common(c, &x->gg, free_strs); 
}

/* FUNC(zx_NEW_wsc_Properties) */

/* Trivial allocator/constructor for the datatype. */

/* Called by: */
struct zx_wsc_Properties_s* zx_NEW_wsc_Properties(struct zx_ctx* c)
{
  struct zx_wsc_Properties_s* x = ZX_ZALLOC(c, struct zx_wsc_Properties_s);
  x->gg.g.tok = zx_wsc_Properties_ELEM;
  return x;
}

#ifdef ZX_ENA_AUX

/* FUNC(zx_DUP_STRS_wsc_Properties) */

/* Depth first traversal of data structure to copy its simple strings
 * to memory allocated from the memory allocator. The decoder will
 * use the underlying wireprotocol PDU buffer for strings, i.e.
 * strings are not copied - they point to the real data. If the
 * datastructure needs to outlast the protocol data or needs a different
 * memory allocation strategy, you need to call this function.  */

/* Called by: */
void zx_DUP_STRS_wsc_Properties(struct zx_ctx* c, struct zx_wsc_Properties_s* x)
{
  zx_dup_strs_common(c, &x->gg);
  /* *** deal with xmlns specifications in exc c14n way */



}

/* FUNC(zx_DEEP_CLONE_wsc_Properties) */

/* Depth first traversal of data structure to clone it and its sublements.
 * The simple strings are handled as a special case according to dup_strs flag. */

/* Called by: */
struct zx_wsc_Properties_s* zx_DEEP_CLONE_wsc_Properties(struct zx_ctx* c, struct zx_wsc_Properties_s* x, int dup_strs)
{
  x = (struct zx_wsc_Properties_s*)zx_clone_elem_common(c, &x->gg, sizeof(struct zx_wsc_Properties_s), dup_strs);
  /* *** deal with xmlns specifications in exc c14n way */



  return x;
}

/* FUNC(zx_WALK_SO_wsc_Properties) */

/* Depth first traversal of the tree in either schema order or the wire order. */
 
int zx_WALK_SO_wsc_Properties(struct zx_ctx* c, struct zx_wsc_Properties_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
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

/* FUNC(zx_WALK_WO_wsc_Properties) */

int zx_WALK_WO_wsc_Properties(struct zx_ctx* c, struct zx_wsc_Properties_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
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

#define EL_NAME   wsc_SecurityContextToken
#define EL_STRUCT zx_wsc_SecurityContextToken_s
#define EL_NS     wsc
#define EL_TAG    SecurityContextToken

/* FUNC(zx_FREE_wsc_SecurityContextToken) */

/* Depth first traversal of data structure to free it and its subelements. Simple
 * strings are handled as a special case according to the free_strs flag. This
 * is useful if the strings point to underlying data from the wire that was
 * allocated differently. */

/* Called by: */
void zx_FREE_wsc_SecurityContextToken(struct zx_ctx* c, struct zx_wsc_SecurityContextToken_s* x, int free_strs)
{
  /* *** deal with xmlns specifications in exc c14n way */

  zx_free_attr(c, x->Id, free_strs);



  zx_free_elem_common(c, &x->gg, free_strs); 
}

/* FUNC(zx_NEW_wsc_SecurityContextToken) */

/* Trivial allocator/constructor for the datatype. */

/* Called by: */
struct zx_wsc_SecurityContextToken_s* zx_NEW_wsc_SecurityContextToken(struct zx_ctx* c)
{
  struct zx_wsc_SecurityContextToken_s* x = ZX_ZALLOC(c, struct zx_wsc_SecurityContextToken_s);
  x->gg.g.tok = zx_wsc_SecurityContextToken_ELEM;
  return x;
}

#ifdef ZX_ENA_AUX

/* FUNC(zx_DUP_STRS_wsc_SecurityContextToken) */

/* Depth first traversal of data structure to copy its simple strings
 * to memory allocated from the memory allocator. The decoder will
 * use the underlying wireprotocol PDU buffer for strings, i.e.
 * strings are not copied - they point to the real data. If the
 * datastructure needs to outlast the protocol data or needs a different
 * memory allocation strategy, you need to call this function.  */

/* Called by: */
void zx_DUP_STRS_wsc_SecurityContextToken(struct zx_ctx* c, struct zx_wsc_SecurityContextToken_s* x)
{
  zx_dup_strs_common(c, &x->gg);
  /* *** deal with xmlns specifications in exc c14n way */

  zx_dup_attr(c, x->Id);


}

/* FUNC(zx_DEEP_CLONE_wsc_SecurityContextToken) */

/* Depth first traversal of data structure to clone it and its sublements.
 * The simple strings are handled as a special case according to dup_strs flag. */

/* Called by: */
struct zx_wsc_SecurityContextToken_s* zx_DEEP_CLONE_wsc_SecurityContextToken(struct zx_ctx* c, struct zx_wsc_SecurityContextToken_s* x, int dup_strs)
{
  x = (struct zx_wsc_SecurityContextToken_s*)zx_clone_elem_common(c, &x->gg, sizeof(struct zx_wsc_SecurityContextToken_s), dup_strs);
  /* *** deal with xmlns specifications in exc c14n way */

  x->Id = zx_clone_attr(c, x->Id);


  return x;
}

/* FUNC(zx_WALK_SO_wsc_SecurityContextToken) */

/* Depth first traversal of the tree in either schema order or the wire order. */
 
int zx_WALK_SO_wsc_SecurityContextToken(struct zx_ctx* c, struct zx_wsc_SecurityContextToken_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
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

/* FUNC(zx_WALK_WO_wsc_SecurityContextToken) */

int zx_WALK_WO_wsc_SecurityContextToken(struct zx_ctx* c, struct zx_wsc_SecurityContextToken_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
{
  ERR("*** walk_wo not implemented %d", 0);
  return 0;
}

#endif


/* EOF -- c/zx-wsc-aux.c */
