/* c/zx-idp-aux.c - WARNING: This file was automatically generated. DO NOT EDIT!
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
#include "c/zx-idp-data.h"



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

#define EL_NAME   idp_AssertionItem
#define EL_STRUCT zx_idp_AssertionItem_s
#define EL_NS     idp
#define EL_TAG    AssertionItem

/* FUNC(zx_FREE_idp_AssertionItem) */

/* Depth first traversal of data structure to free it and its subelements. Simple
 * strings are handled as a special case according to the free_strs flag. This
 * is useful if the strings point to underlying data from the wire that was
 * allocated differently. */

/* Called by: */
void zx_FREE_idp_AssertionItem(struct zx_ctx* c, struct zx_idp_AssertionItem_s* x, int free_strs)
{
  /* *** deal with xmlns specifications in exc c14n way */

  zx_free_attr(c, x->created, free_strs);
  zx_free_attr(c, x->id, free_strs);

  {
      struct zx_idp_MEDInfo_s* e;
      struct zx_idp_MEDInfo_s* en;
      for (e = x->MEDInfo; e; e = en) {
	  en = (struct zx_idp_MEDInfo_s*)e->gg.g.n;
	  zx_FREE_idp_MEDInfo(c, e, free_strs);
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


  zx_free_elem_common(c, &x->gg, free_strs); 
}

/* FUNC(zx_NEW_idp_AssertionItem) */

/* Trivial allocator/constructor for the datatype. */

/* Called by: */
struct zx_idp_AssertionItem_s* zx_NEW_idp_AssertionItem(struct zx_ctx* c)
{
  struct zx_idp_AssertionItem_s* x = ZX_ZALLOC(c, struct zx_idp_AssertionItem_s);
  x->gg.g.tok = zx_idp_AssertionItem_ELEM;
  return x;
}

#ifdef ZX_ENA_AUX

/* FUNC(zx_DUP_STRS_idp_AssertionItem) */

/* Depth first traversal of data structure to copy its simple strings
 * to memory allocated from the memory allocator. The decoder will
 * use the underlying wireprotocol PDU buffer for strings, i.e.
 * strings are not copied - they point to the real data. If the
 * datastructure needs to outlast the protocol data or needs a different
 * memory allocation strategy, you need to call this function.  */

/* Called by: */
void zx_DUP_STRS_idp_AssertionItem(struct zx_ctx* c, struct zx_idp_AssertionItem_s* x)
{
  zx_dup_strs_common(c, &x->gg);
  /* *** deal with xmlns specifications in exc c14n way */

  zx_dup_attr(c, x->created);
  zx_dup_attr(c, x->id);

  {
      struct zx_idp_MEDInfo_s* e;
      for (e = x->MEDInfo; e; e = (struct zx_idp_MEDInfo_s*)e->gg.g.n)
	  zx_DUP_STRS_idp_MEDInfo(c, e);
  }
  {
      struct zx_sa_Assertion_s* e;
      for (e = x->Assertion; e; e = (struct zx_sa_Assertion_s*)e->gg.g.n)
	  zx_DUP_STRS_sa_Assertion(c, e);
  }

}

/* FUNC(zx_DEEP_CLONE_idp_AssertionItem) */

/* Depth first traversal of data structure to clone it and its sublements.
 * The simple strings are handled as a special case according to dup_strs flag. */

/* Called by: */
struct zx_idp_AssertionItem_s* zx_DEEP_CLONE_idp_AssertionItem(struct zx_ctx* c, struct zx_idp_AssertionItem_s* x, int dup_strs)
{
  x = (struct zx_idp_AssertionItem_s*)zx_clone_elem_common(c, &x->gg, sizeof(struct zx_idp_AssertionItem_s), dup_strs);
  /* *** deal with xmlns specifications in exc c14n way */

  x->created = zx_clone_attr(c, x->created);
  x->id = zx_clone_attr(c, x->id);

  {
      struct zx_idp_MEDInfo_s* e;
      struct zx_idp_MEDInfo_s* en;
      struct zx_idp_MEDInfo_s* enn;
      for (enn = 0, e = x->MEDInfo; e; e = (struct zx_idp_MEDInfo_s*)e->gg.g.n) {
	  en = zx_DEEP_CLONE_idp_MEDInfo(c, e, dup_strs);
	  if (!enn)
	      x->MEDInfo = en;
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

  return x;
}

/* FUNC(zx_WALK_SO_idp_AssertionItem) */

/* Depth first traversal of the tree in either schema order or the wire order. */
 
int zx_WALK_SO_idp_AssertionItem(struct zx_ctx* c, struct zx_idp_AssertionItem_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
{
  int ret = callback(&x->gg.g, ctx);
  if (ret)
    return ret;
  
  /* *** deal with xmlns specifications in exc c14n way */


  
  ret = zx_walk_so_unknown_attributes(c, &x->gg, ctx, callback); 
  if (ret)
    return ret;

  {
      struct zx_idp_MEDInfo_s* e;
      for (e = x->MEDInfo; e; e = (struct zx_idp_MEDInfo_s*)e->gg.g.n) {
	  ret = zx_WALK_SO_idp_MEDInfo(c, e, ctx, callback);
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

  
  return zx_walk_so_unknown_elems_and_content(c, &x->gg, ctx, callback);
}

/* FUNC(zx_WALK_WO_idp_AssertionItem) */

int zx_WALK_WO_idp_AssertionItem(struct zx_ctx* c, struct zx_idp_AssertionItem_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
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

#define EL_NAME   idp_AuthnContextRestriction
#define EL_STRUCT zx_idp_AuthnContextRestriction_s
#define EL_NS     idp
#define EL_TAG    AuthnContextRestriction

/* FUNC(zx_FREE_idp_AuthnContextRestriction) */

/* Depth first traversal of data structure to free it and its subelements. Simple
 * strings are handled as a special case according to the free_strs flag. This
 * is useful if the strings point to underlying data from the wire that was
 * allocated differently. */

/* Called by: */
void zx_FREE_idp_AuthnContextRestriction(struct zx_ctx* c, struct zx_idp_AuthnContextRestriction_s* x, int free_strs)
{
  /* *** deal with xmlns specifications in exc c14n way */


  {
      struct zx_sa_AuthnContext_s* e;
      struct zx_sa_AuthnContext_s* en;
      for (e = x->AuthnContext; e; e = en) {
	  en = (struct zx_sa_AuthnContext_s*)e->gg.g.n;
	  zx_FREE_sa_AuthnContext(c, e, free_strs);
      }
  }


  zx_free_elem_common(c, &x->gg, free_strs); 
}

/* FUNC(zx_NEW_idp_AuthnContextRestriction) */

/* Trivial allocator/constructor for the datatype. */

/* Called by: */
struct zx_idp_AuthnContextRestriction_s* zx_NEW_idp_AuthnContextRestriction(struct zx_ctx* c)
{
  struct zx_idp_AuthnContextRestriction_s* x = ZX_ZALLOC(c, struct zx_idp_AuthnContextRestriction_s);
  x->gg.g.tok = zx_idp_AuthnContextRestriction_ELEM;
  return x;
}

#ifdef ZX_ENA_AUX

/* FUNC(zx_DUP_STRS_idp_AuthnContextRestriction) */

/* Depth first traversal of data structure to copy its simple strings
 * to memory allocated from the memory allocator. The decoder will
 * use the underlying wireprotocol PDU buffer for strings, i.e.
 * strings are not copied - they point to the real data. If the
 * datastructure needs to outlast the protocol data or needs a different
 * memory allocation strategy, you need to call this function.  */

/* Called by: */
void zx_DUP_STRS_idp_AuthnContextRestriction(struct zx_ctx* c, struct zx_idp_AuthnContextRestriction_s* x)
{
  zx_dup_strs_common(c, &x->gg);
  /* *** deal with xmlns specifications in exc c14n way */


  {
      struct zx_sa_AuthnContext_s* e;
      for (e = x->AuthnContext; e; e = (struct zx_sa_AuthnContext_s*)e->gg.g.n)
	  zx_DUP_STRS_sa_AuthnContext(c, e);
  }

}

/* FUNC(zx_DEEP_CLONE_idp_AuthnContextRestriction) */

/* Depth first traversal of data structure to clone it and its sublements.
 * The simple strings are handled as a special case according to dup_strs flag. */

/* Called by: */
struct zx_idp_AuthnContextRestriction_s* zx_DEEP_CLONE_idp_AuthnContextRestriction(struct zx_ctx* c, struct zx_idp_AuthnContextRestriction_s* x, int dup_strs)
{
  x = (struct zx_idp_AuthnContextRestriction_s*)zx_clone_elem_common(c, &x->gg, sizeof(struct zx_idp_AuthnContextRestriction_s), dup_strs);
  /* *** deal with xmlns specifications in exc c14n way */


  {
      struct zx_sa_AuthnContext_s* e;
      struct zx_sa_AuthnContext_s* en;
      struct zx_sa_AuthnContext_s* enn;
      for (enn = 0, e = x->AuthnContext; e; e = (struct zx_sa_AuthnContext_s*)e->gg.g.n) {
	  en = zx_DEEP_CLONE_sa_AuthnContext(c, e, dup_strs);
	  if (!enn)
	      x->AuthnContext = en;
	  else
	      enn->gg.g.n = &en->gg.g;
	  enn = en;
      }
  }

  return x;
}

/* FUNC(zx_WALK_SO_idp_AuthnContextRestriction) */

/* Depth first traversal of the tree in either schema order or the wire order. */
 
int zx_WALK_SO_idp_AuthnContextRestriction(struct zx_ctx* c, struct zx_idp_AuthnContextRestriction_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
{
  int ret = callback(&x->gg.g, ctx);
  if (ret)
    return ret;
  
  /* *** deal with xmlns specifications in exc c14n way */


  
  ret = zx_walk_so_unknown_attributes(c, &x->gg, ctx, callback); 
  if (ret)
    return ret;

  {
      struct zx_sa_AuthnContext_s* e;
      for (e = x->AuthnContext; e; e = (struct zx_sa_AuthnContext_s*)e->gg.g.n) {
	  ret = zx_WALK_SO_sa_AuthnContext(c, e, ctx, callback);
	  if (ret)
	      return ret;
      }
  }

  
  return zx_walk_so_unknown_elems_and_content(c, &x->gg, ctx, callback);
}

/* FUNC(zx_WALK_WO_idp_AuthnContextRestriction) */

int zx_WALK_WO_idp_AuthnContextRestriction(struct zx_ctx* c, struct zx_idp_AuthnContextRestriction_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
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

#define EL_NAME   idp_CreatedStatus
#define EL_STRUCT zx_idp_CreatedStatus_s
#define EL_NS     idp
#define EL_TAG    CreatedStatus

/* FUNC(zx_FREE_idp_CreatedStatus) */

/* Depth first traversal of data structure to free it and its subelements. Simple
 * strings are handled as a special case according to the free_strs flag. This
 * is useful if the strings point to underlying data from the wire that was
 * allocated differently. */

/* Called by: */
void zx_FREE_idp_CreatedStatus(struct zx_ctx* c, struct zx_idp_CreatedStatus_s* x, int free_strs)
{
  /* *** deal with xmlns specifications in exc c14n way */


  {
      struct zx_idp_CreatedStatusItem_s* e;
      struct zx_idp_CreatedStatusItem_s* en;
      for (e = x->CreatedStatusItem; e; e = en) {
	  en = (struct zx_idp_CreatedStatusItem_s*)e->gg.g.n;
	  zx_FREE_idp_CreatedStatusItem(c, e, free_strs);
      }
  }


  zx_free_elem_common(c, &x->gg, free_strs); 
}

/* FUNC(zx_NEW_idp_CreatedStatus) */

/* Trivial allocator/constructor for the datatype. */

/* Called by: */
struct zx_idp_CreatedStatus_s* zx_NEW_idp_CreatedStatus(struct zx_ctx* c)
{
  struct zx_idp_CreatedStatus_s* x = ZX_ZALLOC(c, struct zx_idp_CreatedStatus_s);
  x->gg.g.tok = zx_idp_CreatedStatus_ELEM;
  return x;
}

#ifdef ZX_ENA_AUX

/* FUNC(zx_DUP_STRS_idp_CreatedStatus) */

/* Depth first traversal of data structure to copy its simple strings
 * to memory allocated from the memory allocator. The decoder will
 * use the underlying wireprotocol PDU buffer for strings, i.e.
 * strings are not copied - they point to the real data. If the
 * datastructure needs to outlast the protocol data or needs a different
 * memory allocation strategy, you need to call this function.  */

/* Called by: */
void zx_DUP_STRS_idp_CreatedStatus(struct zx_ctx* c, struct zx_idp_CreatedStatus_s* x)
{
  zx_dup_strs_common(c, &x->gg);
  /* *** deal with xmlns specifications in exc c14n way */


  {
      struct zx_idp_CreatedStatusItem_s* e;
      for (e = x->CreatedStatusItem; e; e = (struct zx_idp_CreatedStatusItem_s*)e->gg.g.n)
	  zx_DUP_STRS_idp_CreatedStatusItem(c, e);
  }

}

/* FUNC(zx_DEEP_CLONE_idp_CreatedStatus) */

/* Depth first traversal of data structure to clone it and its sublements.
 * The simple strings are handled as a special case according to dup_strs flag. */

/* Called by: */
struct zx_idp_CreatedStatus_s* zx_DEEP_CLONE_idp_CreatedStatus(struct zx_ctx* c, struct zx_idp_CreatedStatus_s* x, int dup_strs)
{
  x = (struct zx_idp_CreatedStatus_s*)zx_clone_elem_common(c, &x->gg, sizeof(struct zx_idp_CreatedStatus_s), dup_strs);
  /* *** deal with xmlns specifications in exc c14n way */


  {
      struct zx_idp_CreatedStatusItem_s* e;
      struct zx_idp_CreatedStatusItem_s* en;
      struct zx_idp_CreatedStatusItem_s* enn;
      for (enn = 0, e = x->CreatedStatusItem; e; e = (struct zx_idp_CreatedStatusItem_s*)e->gg.g.n) {
	  en = zx_DEEP_CLONE_idp_CreatedStatusItem(c, e, dup_strs);
	  if (!enn)
	      x->CreatedStatusItem = en;
	  else
	      enn->gg.g.n = &en->gg.g;
	  enn = en;
      }
  }

  return x;
}

/* FUNC(zx_WALK_SO_idp_CreatedStatus) */

/* Depth first traversal of the tree in either schema order or the wire order. */
 
int zx_WALK_SO_idp_CreatedStatus(struct zx_ctx* c, struct zx_idp_CreatedStatus_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
{
  int ret = callback(&x->gg.g, ctx);
  if (ret)
    return ret;
  
  /* *** deal with xmlns specifications in exc c14n way */


  
  ret = zx_walk_so_unknown_attributes(c, &x->gg, ctx, callback); 
  if (ret)
    return ret;

  {
      struct zx_idp_CreatedStatusItem_s* e;
      for (e = x->CreatedStatusItem; e; e = (struct zx_idp_CreatedStatusItem_s*)e->gg.g.n) {
	  ret = zx_WALK_SO_idp_CreatedStatusItem(c, e, ctx, callback);
	  if (ret)
	      return ret;
      }
  }

  
  return zx_walk_so_unknown_elems_and_content(c, &x->gg, ctx, callback);
}

/* FUNC(zx_WALK_WO_idp_CreatedStatus) */

int zx_WALK_WO_idp_CreatedStatus(struct zx_ctx* c, struct zx_idp_CreatedStatus_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
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

#define EL_NAME   idp_CreatedStatusItem
#define EL_STRUCT zx_idp_CreatedStatusItem_s
#define EL_NS     idp
#define EL_TAG    CreatedStatusItem

/* FUNC(zx_FREE_idp_CreatedStatusItem) */

/* Depth first traversal of data structure to free it and its subelements. Simple
 * strings are handled as a special case according to the free_strs flag. This
 * is useful if the strings point to underlying data from the wire that was
 * allocated differently. */

/* Called by: */
void zx_FREE_idp_CreatedStatusItem(struct zx_ctx* c, struct zx_idp_CreatedStatusItem_s* x, int free_strs)
{
  /* *** deal with xmlns specifications in exc c14n way */

  zx_free_attr(c, x->firstUsed, free_strs);
  zx_free_attr(c, x->ref, free_strs);
  zx_free_attr(c, x->used, free_strs);



  zx_free_elem_common(c, &x->gg, free_strs); 
}

/* FUNC(zx_NEW_idp_CreatedStatusItem) */

/* Trivial allocator/constructor for the datatype. */

/* Called by: */
struct zx_idp_CreatedStatusItem_s* zx_NEW_idp_CreatedStatusItem(struct zx_ctx* c)
{
  struct zx_idp_CreatedStatusItem_s* x = ZX_ZALLOC(c, struct zx_idp_CreatedStatusItem_s);
  x->gg.g.tok = zx_idp_CreatedStatusItem_ELEM;
  return x;
}

#ifdef ZX_ENA_AUX

/* FUNC(zx_DUP_STRS_idp_CreatedStatusItem) */

/* Depth first traversal of data structure to copy its simple strings
 * to memory allocated from the memory allocator. The decoder will
 * use the underlying wireprotocol PDU buffer for strings, i.e.
 * strings are not copied - they point to the real data. If the
 * datastructure needs to outlast the protocol data or needs a different
 * memory allocation strategy, you need to call this function.  */

/* Called by: */
void zx_DUP_STRS_idp_CreatedStatusItem(struct zx_ctx* c, struct zx_idp_CreatedStatusItem_s* x)
{
  zx_dup_strs_common(c, &x->gg);
  /* *** deal with xmlns specifications in exc c14n way */

  zx_dup_attr(c, x->firstUsed);
  zx_dup_attr(c, x->ref);
  zx_dup_attr(c, x->used);


}

/* FUNC(zx_DEEP_CLONE_idp_CreatedStatusItem) */

/* Depth first traversal of data structure to clone it and its sublements.
 * The simple strings are handled as a special case according to dup_strs flag. */

/* Called by: */
struct zx_idp_CreatedStatusItem_s* zx_DEEP_CLONE_idp_CreatedStatusItem(struct zx_ctx* c, struct zx_idp_CreatedStatusItem_s* x, int dup_strs)
{
  x = (struct zx_idp_CreatedStatusItem_s*)zx_clone_elem_common(c, &x->gg, sizeof(struct zx_idp_CreatedStatusItem_s), dup_strs);
  /* *** deal with xmlns specifications in exc c14n way */

  x->firstUsed = zx_clone_attr(c, x->firstUsed);
  x->ref = zx_clone_attr(c, x->ref);
  x->used = zx_clone_attr(c, x->used);


  return x;
}

/* FUNC(zx_WALK_SO_idp_CreatedStatusItem) */

/* Depth first traversal of the tree in either schema order or the wire order. */
 
int zx_WALK_SO_idp_CreatedStatusItem(struct zx_ctx* c, struct zx_idp_CreatedStatusItem_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
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

/* FUNC(zx_WALK_WO_idp_CreatedStatusItem) */

int zx_WALK_WO_idp_CreatedStatusItem(struct zx_ctx* c, struct zx_idp_CreatedStatusItem_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
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

#define EL_NAME   idp_CreatedStatusResponse
#define EL_STRUCT zx_idp_CreatedStatusResponse_s
#define EL_NS     idp
#define EL_TAG    CreatedStatusResponse

/* FUNC(zx_FREE_idp_CreatedStatusResponse) */

/* Depth first traversal of data structure to free it and its subelements. Simple
 * strings are handled as a special case according to the free_strs flag. This
 * is useful if the strings point to underlying data from the wire that was
 * allocated differently. */

/* Called by: */
void zx_FREE_idp_CreatedStatusResponse(struct zx_ctx* c, struct zx_idp_CreatedStatusResponse_s* x, int free_strs)
{
  /* *** deal with xmlns specifications in exc c14n way */


  {
      struct zx_lu_Status_s* e;
      struct zx_lu_Status_s* en;
      for (e = x->Status; e; e = en) {
	  en = (struct zx_lu_Status_s*)e->gg.g.n;
	  zx_FREE_lu_Status(c, e, free_strs);
      }
  }


  zx_free_elem_common(c, &x->gg, free_strs); 
}

/* FUNC(zx_NEW_idp_CreatedStatusResponse) */

/* Trivial allocator/constructor for the datatype. */

/* Called by: */
struct zx_idp_CreatedStatusResponse_s* zx_NEW_idp_CreatedStatusResponse(struct zx_ctx* c)
{
  struct zx_idp_CreatedStatusResponse_s* x = ZX_ZALLOC(c, struct zx_idp_CreatedStatusResponse_s);
  x->gg.g.tok = zx_idp_CreatedStatusResponse_ELEM;
  return x;
}

#ifdef ZX_ENA_AUX

/* FUNC(zx_DUP_STRS_idp_CreatedStatusResponse) */

/* Depth first traversal of data structure to copy its simple strings
 * to memory allocated from the memory allocator. The decoder will
 * use the underlying wireprotocol PDU buffer for strings, i.e.
 * strings are not copied - they point to the real data. If the
 * datastructure needs to outlast the protocol data or needs a different
 * memory allocation strategy, you need to call this function.  */

/* Called by: */
void zx_DUP_STRS_idp_CreatedStatusResponse(struct zx_ctx* c, struct zx_idp_CreatedStatusResponse_s* x)
{
  zx_dup_strs_common(c, &x->gg);
  /* *** deal with xmlns specifications in exc c14n way */


  {
      struct zx_lu_Status_s* e;
      for (e = x->Status; e; e = (struct zx_lu_Status_s*)e->gg.g.n)
	  zx_DUP_STRS_lu_Status(c, e);
  }

}

/* FUNC(zx_DEEP_CLONE_idp_CreatedStatusResponse) */

/* Depth first traversal of data structure to clone it and its sublements.
 * The simple strings are handled as a special case according to dup_strs flag. */

/* Called by: */
struct zx_idp_CreatedStatusResponse_s* zx_DEEP_CLONE_idp_CreatedStatusResponse(struct zx_ctx* c, struct zx_idp_CreatedStatusResponse_s* x, int dup_strs)
{
  x = (struct zx_idp_CreatedStatusResponse_s*)zx_clone_elem_common(c, &x->gg, sizeof(struct zx_idp_CreatedStatusResponse_s), dup_strs);
  /* *** deal with xmlns specifications in exc c14n way */


  {
      struct zx_lu_Status_s* e;
      struct zx_lu_Status_s* en;
      struct zx_lu_Status_s* enn;
      for (enn = 0, e = x->Status; e; e = (struct zx_lu_Status_s*)e->gg.g.n) {
	  en = zx_DEEP_CLONE_lu_Status(c, e, dup_strs);
	  if (!enn)
	      x->Status = en;
	  else
	      enn->gg.g.n = &en->gg.g;
	  enn = en;
      }
  }

  return x;
}

/* FUNC(zx_WALK_SO_idp_CreatedStatusResponse) */

/* Depth first traversal of the tree in either schema order or the wire order. */
 
int zx_WALK_SO_idp_CreatedStatusResponse(struct zx_ctx* c, struct zx_idp_CreatedStatusResponse_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
{
  int ret = callback(&x->gg.g, ctx);
  if (ret)
    return ret;
  
  /* *** deal with xmlns specifications in exc c14n way */


  
  ret = zx_walk_so_unknown_attributes(c, &x->gg, ctx, callback); 
  if (ret)
    return ret;

  {
      struct zx_lu_Status_s* e;
      for (e = x->Status; e; e = (struct zx_lu_Status_s*)e->gg.g.n) {
	  ret = zx_WALK_SO_lu_Status(c, e, ctx, callback);
	  if (ret)
	      return ret;
      }
  }

  
  return zx_walk_so_unknown_elems_and_content(c, &x->gg, ctx, callback);
}

/* FUNC(zx_WALK_WO_idp_CreatedStatusResponse) */

int zx_WALK_WO_idp_CreatedStatusResponse(struct zx_ctx* c, struct zx_idp_CreatedStatusResponse_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
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

#define EL_NAME   idp_GetAssertion
#define EL_STRUCT zx_idp_GetAssertion_s
#define EL_NS     idp
#define EL_TAG    GetAssertion

/* FUNC(zx_FREE_idp_GetAssertion) */

/* Depth first traversal of data structure to free it and its subelements. Simple
 * strings are handled as a special case according to the free_strs flag. This
 * is useful if the strings point to underlying data from the wire that was
 * allocated differently. */

/* Called by: */
void zx_FREE_idp_GetAssertion(struct zx_ctx* c, struct zx_idp_GetAssertion_s* x, int free_strs)
{
  /* *** deal with xmlns specifications in exc c14n way */

  zx_free_attr(c, x->purpose, free_strs);

  {
      struct zx_sp_AuthnRequest_s* e;
      struct zx_sp_AuthnRequest_s* en;
      for (e = x->AuthnRequest; e; e = en) {
	  en = (struct zx_sp_AuthnRequest_s*)e->gg.g.n;
	  zx_FREE_sp_AuthnRequest(c, e, free_strs);
      }
  }


  zx_free_elem_common(c, &x->gg, free_strs); 
}

/* FUNC(zx_NEW_idp_GetAssertion) */

/* Trivial allocator/constructor for the datatype. */

/* Called by: */
struct zx_idp_GetAssertion_s* zx_NEW_idp_GetAssertion(struct zx_ctx* c)
{
  struct zx_idp_GetAssertion_s* x = ZX_ZALLOC(c, struct zx_idp_GetAssertion_s);
  x->gg.g.tok = zx_idp_GetAssertion_ELEM;
  return x;
}

#ifdef ZX_ENA_AUX

/* FUNC(zx_DUP_STRS_idp_GetAssertion) */

/* Depth first traversal of data structure to copy its simple strings
 * to memory allocated from the memory allocator. The decoder will
 * use the underlying wireprotocol PDU buffer for strings, i.e.
 * strings are not copied - they point to the real data. If the
 * datastructure needs to outlast the protocol data or needs a different
 * memory allocation strategy, you need to call this function.  */

/* Called by: */
void zx_DUP_STRS_idp_GetAssertion(struct zx_ctx* c, struct zx_idp_GetAssertion_s* x)
{
  zx_dup_strs_common(c, &x->gg);
  /* *** deal with xmlns specifications in exc c14n way */

  zx_dup_attr(c, x->purpose);

  {
      struct zx_sp_AuthnRequest_s* e;
      for (e = x->AuthnRequest; e; e = (struct zx_sp_AuthnRequest_s*)e->gg.g.n)
	  zx_DUP_STRS_sp_AuthnRequest(c, e);
  }

}

/* FUNC(zx_DEEP_CLONE_idp_GetAssertion) */

/* Depth first traversal of data structure to clone it and its sublements.
 * The simple strings are handled as a special case according to dup_strs flag. */

/* Called by: */
struct zx_idp_GetAssertion_s* zx_DEEP_CLONE_idp_GetAssertion(struct zx_ctx* c, struct zx_idp_GetAssertion_s* x, int dup_strs)
{
  x = (struct zx_idp_GetAssertion_s*)zx_clone_elem_common(c, &x->gg, sizeof(struct zx_idp_GetAssertion_s), dup_strs);
  /* *** deal with xmlns specifications in exc c14n way */

  x->purpose = zx_clone_attr(c, x->purpose);

  {
      struct zx_sp_AuthnRequest_s* e;
      struct zx_sp_AuthnRequest_s* en;
      struct zx_sp_AuthnRequest_s* enn;
      for (enn = 0, e = x->AuthnRequest; e; e = (struct zx_sp_AuthnRequest_s*)e->gg.g.n) {
	  en = zx_DEEP_CLONE_sp_AuthnRequest(c, e, dup_strs);
	  if (!enn)
	      x->AuthnRequest = en;
	  else
	      enn->gg.g.n = &en->gg.g;
	  enn = en;
      }
  }

  return x;
}

/* FUNC(zx_WALK_SO_idp_GetAssertion) */

/* Depth first traversal of the tree in either schema order or the wire order. */
 
int zx_WALK_SO_idp_GetAssertion(struct zx_ctx* c, struct zx_idp_GetAssertion_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
{
  int ret = callback(&x->gg.g, ctx);
  if (ret)
    return ret;
  
  /* *** deal with xmlns specifications in exc c14n way */


  
  ret = zx_walk_so_unknown_attributes(c, &x->gg, ctx, callback); 
  if (ret)
    return ret;

  {
      struct zx_sp_AuthnRequest_s* e;
      for (e = x->AuthnRequest; e; e = (struct zx_sp_AuthnRequest_s*)e->gg.g.n) {
	  ret = zx_WALK_SO_sp_AuthnRequest(c, e, ctx, callback);
	  if (ret)
	      return ret;
      }
  }

  
  return zx_walk_so_unknown_elems_and_content(c, &x->gg, ctx, callback);
}

/* FUNC(zx_WALK_WO_idp_GetAssertion) */

int zx_WALK_WO_idp_GetAssertion(struct zx_ctx* c, struct zx_idp_GetAssertion_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
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

#define EL_NAME   idp_GetAssertionResponse
#define EL_STRUCT zx_idp_GetAssertionResponse_s
#define EL_NS     idp
#define EL_TAG    GetAssertionResponse

/* FUNC(zx_FREE_idp_GetAssertionResponse) */

/* Depth first traversal of data structure to free it and its subelements. Simple
 * strings are handled as a special case according to the free_strs flag. This
 * is useful if the strings point to underlying data from the wire that was
 * allocated differently. */

/* Called by: */
void zx_FREE_idp_GetAssertionResponse(struct zx_ctx* c, struct zx_idp_GetAssertionResponse_s* x, int free_strs)
{
  /* *** deal with xmlns specifications in exc c14n way */


  {
      struct zx_lu_Status_s* e;
      struct zx_lu_Status_s* en;
      for (e = x->Status; e; e = en) {
	  en = (struct zx_lu_Status_s*)e->gg.g.n;
	  zx_FREE_lu_Status(c, e, free_strs);
      }
  }
  {
      struct zx_idp_GetAssertionResponseItem_s* e;
      struct zx_idp_GetAssertionResponseItem_s* en;
      for (e = x->GetAssertionResponseItem; e; e = en) {
	  en = (struct zx_idp_GetAssertionResponseItem_s*)e->gg.g.n;
	  zx_FREE_idp_GetAssertionResponseItem(c, e, free_strs);
      }
  }


  zx_free_elem_common(c, &x->gg, free_strs); 
}

/* FUNC(zx_NEW_idp_GetAssertionResponse) */

/* Trivial allocator/constructor for the datatype. */

/* Called by: */
struct zx_idp_GetAssertionResponse_s* zx_NEW_idp_GetAssertionResponse(struct zx_ctx* c)
{
  struct zx_idp_GetAssertionResponse_s* x = ZX_ZALLOC(c, struct zx_idp_GetAssertionResponse_s);
  x->gg.g.tok = zx_idp_GetAssertionResponse_ELEM;
  return x;
}

#ifdef ZX_ENA_AUX

/* FUNC(zx_DUP_STRS_idp_GetAssertionResponse) */

/* Depth first traversal of data structure to copy its simple strings
 * to memory allocated from the memory allocator. The decoder will
 * use the underlying wireprotocol PDU buffer for strings, i.e.
 * strings are not copied - they point to the real data. If the
 * datastructure needs to outlast the protocol data or needs a different
 * memory allocation strategy, you need to call this function.  */

/* Called by: */
void zx_DUP_STRS_idp_GetAssertionResponse(struct zx_ctx* c, struct zx_idp_GetAssertionResponse_s* x)
{
  zx_dup_strs_common(c, &x->gg);
  /* *** deal with xmlns specifications in exc c14n way */


  {
      struct zx_lu_Status_s* e;
      for (e = x->Status; e; e = (struct zx_lu_Status_s*)e->gg.g.n)
	  zx_DUP_STRS_lu_Status(c, e);
  }
  {
      struct zx_idp_GetAssertionResponseItem_s* e;
      for (e = x->GetAssertionResponseItem; e; e = (struct zx_idp_GetAssertionResponseItem_s*)e->gg.g.n)
	  zx_DUP_STRS_idp_GetAssertionResponseItem(c, e);
  }

}

/* FUNC(zx_DEEP_CLONE_idp_GetAssertionResponse) */

/* Depth first traversal of data structure to clone it and its sublements.
 * The simple strings are handled as a special case according to dup_strs flag. */

/* Called by: */
struct zx_idp_GetAssertionResponse_s* zx_DEEP_CLONE_idp_GetAssertionResponse(struct zx_ctx* c, struct zx_idp_GetAssertionResponse_s* x, int dup_strs)
{
  x = (struct zx_idp_GetAssertionResponse_s*)zx_clone_elem_common(c, &x->gg, sizeof(struct zx_idp_GetAssertionResponse_s), dup_strs);
  /* *** deal with xmlns specifications in exc c14n way */


  {
      struct zx_lu_Status_s* e;
      struct zx_lu_Status_s* en;
      struct zx_lu_Status_s* enn;
      for (enn = 0, e = x->Status; e; e = (struct zx_lu_Status_s*)e->gg.g.n) {
	  en = zx_DEEP_CLONE_lu_Status(c, e, dup_strs);
	  if (!enn)
	      x->Status = en;
	  else
	      enn->gg.g.n = &en->gg.g;
	  enn = en;
      }
  }
  {
      struct zx_idp_GetAssertionResponseItem_s* e;
      struct zx_idp_GetAssertionResponseItem_s* en;
      struct zx_idp_GetAssertionResponseItem_s* enn;
      for (enn = 0, e = x->GetAssertionResponseItem; e; e = (struct zx_idp_GetAssertionResponseItem_s*)e->gg.g.n) {
	  en = zx_DEEP_CLONE_idp_GetAssertionResponseItem(c, e, dup_strs);
	  if (!enn)
	      x->GetAssertionResponseItem = en;
	  else
	      enn->gg.g.n = &en->gg.g;
	  enn = en;
      }
  }

  return x;
}

/* FUNC(zx_WALK_SO_idp_GetAssertionResponse) */

/* Depth first traversal of the tree in either schema order or the wire order. */
 
int zx_WALK_SO_idp_GetAssertionResponse(struct zx_ctx* c, struct zx_idp_GetAssertionResponse_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
{
  int ret = callback(&x->gg.g, ctx);
  if (ret)
    return ret;
  
  /* *** deal with xmlns specifications in exc c14n way */


  
  ret = zx_walk_so_unknown_attributes(c, &x->gg, ctx, callback); 
  if (ret)
    return ret;

  {
      struct zx_lu_Status_s* e;
      for (e = x->Status; e; e = (struct zx_lu_Status_s*)e->gg.g.n) {
	  ret = zx_WALK_SO_lu_Status(c, e, ctx, callback);
	  if (ret)
	      return ret;
      }
  }
  {
      struct zx_idp_GetAssertionResponseItem_s* e;
      for (e = x->GetAssertionResponseItem; e; e = (struct zx_idp_GetAssertionResponseItem_s*)e->gg.g.n) {
	  ret = zx_WALK_SO_idp_GetAssertionResponseItem(c, e, ctx, callback);
	  if (ret)
	      return ret;
      }
  }

  
  return zx_walk_so_unknown_elems_and_content(c, &x->gg, ctx, callback);
}

/* FUNC(zx_WALK_WO_idp_GetAssertionResponse) */

int zx_WALK_WO_idp_GetAssertionResponse(struct zx_ctx* c, struct zx_idp_GetAssertionResponse_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
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

#define EL_NAME   idp_GetAssertionResponseItem
#define EL_STRUCT zx_idp_GetAssertionResponseItem_s
#define EL_NS     idp
#define EL_TAG    GetAssertionResponseItem

/* FUNC(zx_FREE_idp_GetAssertionResponseItem) */

/* Depth first traversal of data structure to free it and its subelements. Simple
 * strings are handled as a special case according to the free_strs flag. This
 * is useful if the strings point to underlying data from the wire that was
 * allocated differently. */

/* Called by: */
void zx_FREE_idp_GetAssertionResponseItem(struct zx_ctx* c, struct zx_idp_GetAssertionResponseItem_s* x, int free_strs)
{
  /* *** deal with xmlns specifications in exc c14n way */

  zx_free_attr(c, x->id, free_strs);
  zx_free_attr(c, x->ref, free_strs);

  {
      struct zx_idp_AssertionItem_s* e;
      struct zx_idp_AssertionItem_s* en;
      for (e = x->AssertionItem; e; e = en) {
	  en = (struct zx_idp_AssertionItem_s*)e->gg.g.n;
	  zx_FREE_idp_AssertionItem(c, e, free_strs);
      }
  }


  zx_free_elem_common(c, &x->gg, free_strs); 
}

/* FUNC(zx_NEW_idp_GetAssertionResponseItem) */

/* Trivial allocator/constructor for the datatype. */

/* Called by: */
struct zx_idp_GetAssertionResponseItem_s* zx_NEW_idp_GetAssertionResponseItem(struct zx_ctx* c)
{
  struct zx_idp_GetAssertionResponseItem_s* x = ZX_ZALLOC(c, struct zx_idp_GetAssertionResponseItem_s);
  x->gg.g.tok = zx_idp_GetAssertionResponseItem_ELEM;
  return x;
}

#ifdef ZX_ENA_AUX

/* FUNC(zx_DUP_STRS_idp_GetAssertionResponseItem) */

/* Depth first traversal of data structure to copy its simple strings
 * to memory allocated from the memory allocator. The decoder will
 * use the underlying wireprotocol PDU buffer for strings, i.e.
 * strings are not copied - they point to the real data. If the
 * datastructure needs to outlast the protocol data or needs a different
 * memory allocation strategy, you need to call this function.  */

/* Called by: */
void zx_DUP_STRS_idp_GetAssertionResponseItem(struct zx_ctx* c, struct zx_idp_GetAssertionResponseItem_s* x)
{
  zx_dup_strs_common(c, &x->gg);
  /* *** deal with xmlns specifications in exc c14n way */

  zx_dup_attr(c, x->id);
  zx_dup_attr(c, x->ref);

  {
      struct zx_idp_AssertionItem_s* e;
      for (e = x->AssertionItem; e; e = (struct zx_idp_AssertionItem_s*)e->gg.g.n)
	  zx_DUP_STRS_idp_AssertionItem(c, e);
  }

}

/* FUNC(zx_DEEP_CLONE_idp_GetAssertionResponseItem) */

/* Depth first traversal of data structure to clone it and its sublements.
 * The simple strings are handled as a special case according to dup_strs flag. */

/* Called by: */
struct zx_idp_GetAssertionResponseItem_s* zx_DEEP_CLONE_idp_GetAssertionResponseItem(struct zx_ctx* c, struct zx_idp_GetAssertionResponseItem_s* x, int dup_strs)
{
  x = (struct zx_idp_GetAssertionResponseItem_s*)zx_clone_elem_common(c, &x->gg, sizeof(struct zx_idp_GetAssertionResponseItem_s), dup_strs);
  /* *** deal with xmlns specifications in exc c14n way */

  x->id = zx_clone_attr(c, x->id);
  x->ref = zx_clone_attr(c, x->ref);

  {
      struct zx_idp_AssertionItem_s* e;
      struct zx_idp_AssertionItem_s* en;
      struct zx_idp_AssertionItem_s* enn;
      for (enn = 0, e = x->AssertionItem; e; e = (struct zx_idp_AssertionItem_s*)e->gg.g.n) {
	  en = zx_DEEP_CLONE_idp_AssertionItem(c, e, dup_strs);
	  if (!enn)
	      x->AssertionItem = en;
	  else
	      enn->gg.g.n = &en->gg.g;
	  enn = en;
      }
  }

  return x;
}

/* FUNC(zx_WALK_SO_idp_GetAssertionResponseItem) */

/* Depth first traversal of the tree in either schema order or the wire order. */
 
int zx_WALK_SO_idp_GetAssertionResponseItem(struct zx_ctx* c, struct zx_idp_GetAssertionResponseItem_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
{
  int ret = callback(&x->gg.g, ctx);
  if (ret)
    return ret;
  
  /* *** deal with xmlns specifications in exc c14n way */


  
  ret = zx_walk_so_unknown_attributes(c, &x->gg, ctx, callback); 
  if (ret)
    return ret;

  {
      struct zx_idp_AssertionItem_s* e;
      for (e = x->AssertionItem; e; e = (struct zx_idp_AssertionItem_s*)e->gg.g.n) {
	  ret = zx_WALK_SO_idp_AssertionItem(c, e, ctx, callback);
	  if (ret)
	      return ret;
      }
  }

  
  return zx_walk_so_unknown_elems_and_content(c, &x->gg, ctx, callback);
}

/* FUNC(zx_WALK_WO_idp_GetAssertionResponseItem) */

int zx_WALK_WO_idp_GetAssertionResponseItem(struct zx_ctx* c, struct zx_idp_GetAssertionResponseItem_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
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

#define EL_NAME   idp_GetProviderInfo
#define EL_STRUCT zx_idp_GetProviderInfo_s
#define EL_NS     idp
#define EL_TAG    GetProviderInfo

/* FUNC(zx_FREE_idp_GetProviderInfo) */

/* Depth first traversal of data structure to free it and its subelements. Simple
 * strings are handled as a special case according to the free_strs flag. This
 * is useful if the strings point to underlying data from the wire that was
 * allocated differently. */

/* Called by: */
void zx_FREE_idp_GetProviderInfo(struct zx_ctx* c, struct zx_idp_GetProviderInfo_s* x, int free_strs)
{
  /* *** deal with xmlns specifications in exc c14n way */

  zx_free_attr(c, x->all, free_strs);

  zx_free_simple_elems(c, x->ProviderID, free_strs);


  zx_free_elem_common(c, &x->gg, free_strs); 
}

/* FUNC(zx_NEW_idp_GetProviderInfo) */

/* Trivial allocator/constructor for the datatype. */

/* Called by: */
struct zx_idp_GetProviderInfo_s* zx_NEW_idp_GetProviderInfo(struct zx_ctx* c)
{
  struct zx_idp_GetProviderInfo_s* x = ZX_ZALLOC(c, struct zx_idp_GetProviderInfo_s);
  x->gg.g.tok = zx_idp_GetProviderInfo_ELEM;
  return x;
}

#ifdef ZX_ENA_AUX

/* FUNC(zx_DUP_STRS_idp_GetProviderInfo) */

/* Depth first traversal of data structure to copy its simple strings
 * to memory allocated from the memory allocator. The decoder will
 * use the underlying wireprotocol PDU buffer for strings, i.e.
 * strings are not copied - they point to the real data. If the
 * datastructure needs to outlast the protocol data or needs a different
 * memory allocation strategy, you need to call this function.  */

/* Called by: */
void zx_DUP_STRS_idp_GetProviderInfo(struct zx_ctx* c, struct zx_idp_GetProviderInfo_s* x)
{
  zx_dup_strs_common(c, &x->gg);
  /* *** deal with xmlns specifications in exc c14n way */

  zx_dup_attr(c, x->all);

  zx_dup_strs_simple_elems(c, x->ProviderID);

}

/* FUNC(zx_DEEP_CLONE_idp_GetProviderInfo) */

/* Depth first traversal of data structure to clone it and its sublements.
 * The simple strings are handled as a special case according to dup_strs flag. */

/* Called by: */
struct zx_idp_GetProviderInfo_s* zx_DEEP_CLONE_idp_GetProviderInfo(struct zx_ctx* c, struct zx_idp_GetProviderInfo_s* x, int dup_strs)
{
  x = (struct zx_idp_GetProviderInfo_s*)zx_clone_elem_common(c, &x->gg, sizeof(struct zx_idp_GetProviderInfo_s), dup_strs);
  /* *** deal with xmlns specifications in exc c14n way */

  x->all = zx_clone_attr(c, x->all);

  x->ProviderID = zx_deep_clone_simple_elems(c,x->ProviderID, dup_strs);

  return x;
}

/* FUNC(zx_WALK_SO_idp_GetProviderInfo) */

/* Depth first traversal of the tree in either schema order or the wire order. */
 
int zx_WALK_SO_idp_GetProviderInfo(struct zx_ctx* c, struct zx_idp_GetProviderInfo_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
{
  int ret = callback(&x->gg.g, ctx);
  if (ret)
    return ret;
  
  /* *** deal with xmlns specifications in exc c14n way */


  
  ret = zx_walk_so_unknown_attributes(c, &x->gg, ctx, callback); 
  if (ret)
    return ret;

  ret = zx_walk_so_simple_elems(c, x->ProviderID, ctx, callback);
  if (ret)
    return ret;

  
  return zx_walk_so_unknown_elems_and_content(c, &x->gg, ctx, callback);
}

/* FUNC(zx_WALK_WO_idp_GetProviderInfo) */

int zx_WALK_WO_idp_GetProviderInfo(struct zx_ctx* c, struct zx_idp_GetProviderInfo_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
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

#define EL_NAME   idp_GetProviderInfoResponse
#define EL_STRUCT zx_idp_GetProviderInfoResponse_s
#define EL_NS     idp
#define EL_TAG    GetProviderInfoResponse

/* FUNC(zx_FREE_idp_GetProviderInfoResponse) */

/* Depth first traversal of data structure to free it and its subelements. Simple
 * strings are handled as a special case according to the free_strs flag. This
 * is useful if the strings point to underlying data from the wire that was
 * allocated differently. */

/* Called by: */
void zx_FREE_idp_GetProviderInfoResponse(struct zx_ctx* c, struct zx_idp_GetProviderInfoResponse_s* x, int free_strs)
{
  /* *** deal with xmlns specifications in exc c14n way */


  {
      struct zx_lu_Status_s* e;
      struct zx_lu_Status_s* en;
      for (e = x->Status; e; e = en) {
	  en = (struct zx_lu_Status_s*)e->gg.g.n;
	  zx_FREE_lu_Status(c, e, free_strs);
      }
  }
  {
      struct zx_idp_ProviderInfo_s* e;
      struct zx_idp_ProviderInfo_s* en;
      for (e = x->ProviderInfo; e; e = en) {
	  en = (struct zx_idp_ProviderInfo_s*)e->gg.g.n;
	  zx_FREE_idp_ProviderInfo(c, e, free_strs);
      }
  }


  zx_free_elem_common(c, &x->gg, free_strs); 
}

/* FUNC(zx_NEW_idp_GetProviderInfoResponse) */

/* Trivial allocator/constructor for the datatype. */

/* Called by: */
struct zx_idp_GetProviderInfoResponse_s* zx_NEW_idp_GetProviderInfoResponse(struct zx_ctx* c)
{
  struct zx_idp_GetProviderInfoResponse_s* x = ZX_ZALLOC(c, struct zx_idp_GetProviderInfoResponse_s);
  x->gg.g.tok = zx_idp_GetProviderInfoResponse_ELEM;
  return x;
}

#ifdef ZX_ENA_AUX

/* FUNC(zx_DUP_STRS_idp_GetProviderInfoResponse) */

/* Depth first traversal of data structure to copy its simple strings
 * to memory allocated from the memory allocator. The decoder will
 * use the underlying wireprotocol PDU buffer for strings, i.e.
 * strings are not copied - they point to the real data. If the
 * datastructure needs to outlast the protocol data or needs a different
 * memory allocation strategy, you need to call this function.  */

/* Called by: */
void zx_DUP_STRS_idp_GetProviderInfoResponse(struct zx_ctx* c, struct zx_idp_GetProviderInfoResponse_s* x)
{
  zx_dup_strs_common(c, &x->gg);
  /* *** deal with xmlns specifications in exc c14n way */


  {
      struct zx_lu_Status_s* e;
      for (e = x->Status; e; e = (struct zx_lu_Status_s*)e->gg.g.n)
	  zx_DUP_STRS_lu_Status(c, e);
  }
  {
      struct zx_idp_ProviderInfo_s* e;
      for (e = x->ProviderInfo; e; e = (struct zx_idp_ProviderInfo_s*)e->gg.g.n)
	  zx_DUP_STRS_idp_ProviderInfo(c, e);
  }

}

/* FUNC(zx_DEEP_CLONE_idp_GetProviderInfoResponse) */

/* Depth first traversal of data structure to clone it and its sublements.
 * The simple strings are handled as a special case according to dup_strs flag. */

/* Called by: */
struct zx_idp_GetProviderInfoResponse_s* zx_DEEP_CLONE_idp_GetProviderInfoResponse(struct zx_ctx* c, struct zx_idp_GetProviderInfoResponse_s* x, int dup_strs)
{
  x = (struct zx_idp_GetProviderInfoResponse_s*)zx_clone_elem_common(c, &x->gg, sizeof(struct zx_idp_GetProviderInfoResponse_s), dup_strs);
  /* *** deal with xmlns specifications in exc c14n way */


  {
      struct zx_lu_Status_s* e;
      struct zx_lu_Status_s* en;
      struct zx_lu_Status_s* enn;
      for (enn = 0, e = x->Status; e; e = (struct zx_lu_Status_s*)e->gg.g.n) {
	  en = zx_DEEP_CLONE_lu_Status(c, e, dup_strs);
	  if (!enn)
	      x->Status = en;
	  else
	      enn->gg.g.n = &en->gg.g;
	  enn = en;
      }
  }
  {
      struct zx_idp_ProviderInfo_s* e;
      struct zx_idp_ProviderInfo_s* en;
      struct zx_idp_ProviderInfo_s* enn;
      for (enn = 0, e = x->ProviderInfo; e; e = (struct zx_idp_ProviderInfo_s*)e->gg.g.n) {
	  en = zx_DEEP_CLONE_idp_ProviderInfo(c, e, dup_strs);
	  if (!enn)
	      x->ProviderInfo = en;
	  else
	      enn->gg.g.n = &en->gg.g;
	  enn = en;
      }
  }

  return x;
}

/* FUNC(zx_WALK_SO_idp_GetProviderInfoResponse) */

/* Depth first traversal of the tree in either schema order or the wire order. */
 
int zx_WALK_SO_idp_GetProviderInfoResponse(struct zx_ctx* c, struct zx_idp_GetProviderInfoResponse_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
{
  int ret = callback(&x->gg.g, ctx);
  if (ret)
    return ret;
  
  /* *** deal with xmlns specifications in exc c14n way */


  
  ret = zx_walk_so_unknown_attributes(c, &x->gg, ctx, callback); 
  if (ret)
    return ret;

  {
      struct zx_lu_Status_s* e;
      for (e = x->Status; e; e = (struct zx_lu_Status_s*)e->gg.g.n) {
	  ret = zx_WALK_SO_lu_Status(c, e, ctx, callback);
	  if (ret)
	      return ret;
      }
  }
  {
      struct zx_idp_ProviderInfo_s* e;
      for (e = x->ProviderInfo; e; e = (struct zx_idp_ProviderInfo_s*)e->gg.g.n) {
	  ret = zx_WALK_SO_idp_ProviderInfo(c, e, ctx, callback);
	  if (ret)
	      return ret;
      }
  }

  
  return zx_walk_so_unknown_elems_and_content(c, &x->gg, ctx, callback);
}

/* FUNC(zx_WALK_WO_idp_GetProviderInfoResponse) */

int zx_WALK_WO_idp_GetProviderInfoResponse(struct zx_ctx* c, struct zx_idp_GetProviderInfoResponse_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
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

#define EL_NAME   idp_MEDInfo
#define EL_STRUCT zx_idp_MEDInfo_s
#define EL_NS     idp
#define EL_TAG    MEDInfo

/* FUNC(zx_FREE_idp_MEDInfo) */

/* Depth first traversal of data structure to free it and its subelements. Simple
 * strings are handled as a special case according to the free_strs flag. This
 * is useful if the strings point to underlying data from the wire that was
 * allocated differently. */

/* Called by: */
void zx_FREE_idp_MEDInfo(struct zx_ctx* c, struct zx_idp_MEDInfo_s* x, int free_strs)
{
  /* *** deal with xmlns specifications in exc c14n way */


  {
      struct zx_sa_NameID_s* e;
      struct zx_sa_NameID_s* en;
      for (e = x->NameID; e; e = en) {
	  en = (struct zx_sa_NameID_s*)e->gg.g.n;
	  zx_FREE_sa_NameID(c, e, free_strs);
      }
  }
  {
      struct zx_sa_AttributeStatement_s* e;
      struct zx_sa_AttributeStatement_s* en;
      for (e = x->AttributeStatement; e; e = en) {
	  en = (struct zx_sa_AttributeStatement_s*)e->gg.g.n;
	  zx_FREE_sa_AttributeStatement(c, e, free_strs);
      }
  }


  zx_free_elem_common(c, &x->gg, free_strs); 
}

/* FUNC(zx_NEW_idp_MEDInfo) */

/* Trivial allocator/constructor for the datatype. */

/* Called by: */
struct zx_idp_MEDInfo_s* zx_NEW_idp_MEDInfo(struct zx_ctx* c)
{
  struct zx_idp_MEDInfo_s* x = ZX_ZALLOC(c, struct zx_idp_MEDInfo_s);
  x->gg.g.tok = zx_idp_MEDInfo_ELEM;
  return x;
}

#ifdef ZX_ENA_AUX

/* FUNC(zx_DUP_STRS_idp_MEDInfo) */

/* Depth first traversal of data structure to copy its simple strings
 * to memory allocated from the memory allocator. The decoder will
 * use the underlying wireprotocol PDU buffer for strings, i.e.
 * strings are not copied - they point to the real data. If the
 * datastructure needs to outlast the protocol data or needs a different
 * memory allocation strategy, you need to call this function.  */

/* Called by: */
void zx_DUP_STRS_idp_MEDInfo(struct zx_ctx* c, struct zx_idp_MEDInfo_s* x)
{
  zx_dup_strs_common(c, &x->gg);
  /* *** deal with xmlns specifications in exc c14n way */


  {
      struct zx_sa_NameID_s* e;
      for (e = x->NameID; e; e = (struct zx_sa_NameID_s*)e->gg.g.n)
	  zx_DUP_STRS_sa_NameID(c, e);
  }
  {
      struct zx_sa_AttributeStatement_s* e;
      for (e = x->AttributeStatement; e; e = (struct zx_sa_AttributeStatement_s*)e->gg.g.n)
	  zx_DUP_STRS_sa_AttributeStatement(c, e);
  }

}

/* FUNC(zx_DEEP_CLONE_idp_MEDInfo) */

/* Depth first traversal of data structure to clone it and its sublements.
 * The simple strings are handled as a special case according to dup_strs flag. */

/* Called by: */
struct zx_idp_MEDInfo_s* zx_DEEP_CLONE_idp_MEDInfo(struct zx_ctx* c, struct zx_idp_MEDInfo_s* x, int dup_strs)
{
  x = (struct zx_idp_MEDInfo_s*)zx_clone_elem_common(c, &x->gg, sizeof(struct zx_idp_MEDInfo_s), dup_strs);
  /* *** deal with xmlns specifications in exc c14n way */


  {
      struct zx_sa_NameID_s* e;
      struct zx_sa_NameID_s* en;
      struct zx_sa_NameID_s* enn;
      for (enn = 0, e = x->NameID; e; e = (struct zx_sa_NameID_s*)e->gg.g.n) {
	  en = zx_DEEP_CLONE_sa_NameID(c, e, dup_strs);
	  if (!enn)
	      x->NameID = en;
	  else
	      enn->gg.g.n = &en->gg.g;
	  enn = en;
      }
  }
  {
      struct zx_sa_AttributeStatement_s* e;
      struct zx_sa_AttributeStatement_s* en;
      struct zx_sa_AttributeStatement_s* enn;
      for (enn = 0, e = x->AttributeStatement; e; e = (struct zx_sa_AttributeStatement_s*)e->gg.g.n) {
	  en = zx_DEEP_CLONE_sa_AttributeStatement(c, e, dup_strs);
	  if (!enn)
	      x->AttributeStatement = en;
	  else
	      enn->gg.g.n = &en->gg.g;
	  enn = en;
      }
  }

  return x;
}

/* FUNC(zx_WALK_SO_idp_MEDInfo) */

/* Depth first traversal of the tree in either schema order or the wire order. */
 
int zx_WALK_SO_idp_MEDInfo(struct zx_ctx* c, struct zx_idp_MEDInfo_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
{
  int ret = callback(&x->gg.g, ctx);
  if (ret)
    return ret;
  
  /* *** deal with xmlns specifications in exc c14n way */


  
  ret = zx_walk_so_unknown_attributes(c, &x->gg, ctx, callback); 
  if (ret)
    return ret;

  {
      struct zx_sa_NameID_s* e;
      for (e = x->NameID; e; e = (struct zx_sa_NameID_s*)e->gg.g.n) {
	  ret = zx_WALK_SO_sa_NameID(c, e, ctx, callback);
	  if (ret)
	      return ret;
      }
  }
  {
      struct zx_sa_AttributeStatement_s* e;
      for (e = x->AttributeStatement; e; e = (struct zx_sa_AttributeStatement_s*)e->gg.g.n) {
	  ret = zx_WALK_SO_sa_AttributeStatement(c, e, ctx, callback);
	  if (ret)
	      return ret;
      }
  }

  
  return zx_walk_so_unknown_elems_and_content(c, &x->gg, ctx, callback);
}

/* FUNC(zx_WALK_WO_idp_MEDInfo) */

int zx_WALK_WO_idp_MEDInfo(struct zx_ctx* c, struct zx_idp_MEDInfo_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
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

#define EL_NAME   idp_ProviderInfo
#define EL_STRUCT zx_idp_ProviderInfo_s
#define EL_NS     idp
#define EL_TAG    ProviderInfo

/* FUNC(zx_FREE_idp_ProviderInfo) */

/* Depth first traversal of data structure to free it and its subelements. Simple
 * strings are handled as a special case according to the free_strs flag. This
 * is useful if the strings point to underlying data from the wire that was
 * allocated differently. */

/* Called by: */
void zx_FREE_idp_ProviderInfo(struct zx_ctx* c, struct zx_idp_ProviderInfo_s* x, int free_strs)
{
  /* *** deal with xmlns specifications in exc c14n way */

  zx_free_attr(c, x->name, free_strs);
  zx_free_attr(c, x->providerID, free_strs);



  zx_free_elem_common(c, &x->gg, free_strs); 
}

/* FUNC(zx_NEW_idp_ProviderInfo) */

/* Trivial allocator/constructor for the datatype. */

/* Called by: */
struct zx_idp_ProviderInfo_s* zx_NEW_idp_ProviderInfo(struct zx_ctx* c)
{
  struct zx_idp_ProviderInfo_s* x = ZX_ZALLOC(c, struct zx_idp_ProviderInfo_s);
  x->gg.g.tok = zx_idp_ProviderInfo_ELEM;
  return x;
}

#ifdef ZX_ENA_AUX

/* FUNC(zx_DUP_STRS_idp_ProviderInfo) */

/* Depth first traversal of data structure to copy its simple strings
 * to memory allocated from the memory allocator. The decoder will
 * use the underlying wireprotocol PDU buffer for strings, i.e.
 * strings are not copied - they point to the real data. If the
 * datastructure needs to outlast the protocol data or needs a different
 * memory allocation strategy, you need to call this function.  */

/* Called by: */
void zx_DUP_STRS_idp_ProviderInfo(struct zx_ctx* c, struct zx_idp_ProviderInfo_s* x)
{
  zx_dup_strs_common(c, &x->gg);
  /* *** deal with xmlns specifications in exc c14n way */

  zx_dup_attr(c, x->name);
  zx_dup_attr(c, x->providerID);


}

/* FUNC(zx_DEEP_CLONE_idp_ProviderInfo) */

/* Depth first traversal of data structure to clone it and its sublements.
 * The simple strings are handled as a special case according to dup_strs flag. */

/* Called by: */
struct zx_idp_ProviderInfo_s* zx_DEEP_CLONE_idp_ProviderInfo(struct zx_ctx* c, struct zx_idp_ProviderInfo_s* x, int dup_strs)
{
  x = (struct zx_idp_ProviderInfo_s*)zx_clone_elem_common(c, &x->gg, sizeof(struct zx_idp_ProviderInfo_s), dup_strs);
  /* *** deal with xmlns specifications in exc c14n way */

  x->name = zx_clone_attr(c, x->name);
  x->providerID = zx_clone_attr(c, x->providerID);


  return x;
}

/* FUNC(zx_WALK_SO_idp_ProviderInfo) */

/* Depth first traversal of the tree in either schema order or the wire order. */
 
int zx_WALK_SO_idp_ProviderInfo(struct zx_ctx* c, struct zx_idp_ProviderInfo_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
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

/* FUNC(zx_WALK_WO_idp_ProviderInfo) */

int zx_WALK_WO_idp_ProviderInfo(struct zx_ctx* c, struct zx_idp_ProviderInfo_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
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

#define EL_NAME   idp_SubjectRestriction
#define EL_STRUCT zx_idp_SubjectRestriction_s
#define EL_NS     idp
#define EL_TAG    SubjectRestriction

/* FUNC(zx_FREE_idp_SubjectRestriction) */

/* Depth first traversal of data structure to free it and its subelements. Simple
 * strings are handled as a special case according to the free_strs flag. This
 * is useful if the strings point to underlying data from the wire that was
 * allocated differently. */

/* Called by: */
void zx_FREE_idp_SubjectRestriction(struct zx_ctx* c, struct zx_idp_SubjectRestriction_s* x, int free_strs)
{
  /* *** deal with xmlns specifications in exc c14n way */


  {
      struct zx_sa_Subject_s* e;
      struct zx_sa_Subject_s* en;
      for (e = x->Subject; e; e = en) {
	  en = (struct zx_sa_Subject_s*)e->gg.g.n;
	  zx_FREE_sa_Subject(c, e, free_strs);
      }
  }


  zx_free_elem_common(c, &x->gg, free_strs); 
}

/* FUNC(zx_NEW_idp_SubjectRestriction) */

/* Trivial allocator/constructor for the datatype. */

/* Called by: */
struct zx_idp_SubjectRestriction_s* zx_NEW_idp_SubjectRestriction(struct zx_ctx* c)
{
  struct zx_idp_SubjectRestriction_s* x = ZX_ZALLOC(c, struct zx_idp_SubjectRestriction_s);
  x->gg.g.tok = zx_idp_SubjectRestriction_ELEM;
  return x;
}

#ifdef ZX_ENA_AUX

/* FUNC(zx_DUP_STRS_idp_SubjectRestriction) */

/* Depth first traversal of data structure to copy its simple strings
 * to memory allocated from the memory allocator. The decoder will
 * use the underlying wireprotocol PDU buffer for strings, i.e.
 * strings are not copied - they point to the real data. If the
 * datastructure needs to outlast the protocol data or needs a different
 * memory allocation strategy, you need to call this function.  */

/* Called by: */
void zx_DUP_STRS_idp_SubjectRestriction(struct zx_ctx* c, struct zx_idp_SubjectRestriction_s* x)
{
  zx_dup_strs_common(c, &x->gg);
  /* *** deal with xmlns specifications in exc c14n way */


  {
      struct zx_sa_Subject_s* e;
      for (e = x->Subject; e; e = (struct zx_sa_Subject_s*)e->gg.g.n)
	  zx_DUP_STRS_sa_Subject(c, e);
  }

}

/* FUNC(zx_DEEP_CLONE_idp_SubjectRestriction) */

/* Depth first traversal of data structure to clone it and its sublements.
 * The simple strings are handled as a special case according to dup_strs flag. */

/* Called by: */
struct zx_idp_SubjectRestriction_s* zx_DEEP_CLONE_idp_SubjectRestriction(struct zx_ctx* c, struct zx_idp_SubjectRestriction_s* x, int dup_strs)
{
  x = (struct zx_idp_SubjectRestriction_s*)zx_clone_elem_common(c, &x->gg, sizeof(struct zx_idp_SubjectRestriction_s), dup_strs);
  /* *** deal with xmlns specifications in exc c14n way */


  {
      struct zx_sa_Subject_s* e;
      struct zx_sa_Subject_s* en;
      struct zx_sa_Subject_s* enn;
      for (enn = 0, e = x->Subject; e; e = (struct zx_sa_Subject_s*)e->gg.g.n) {
	  en = zx_DEEP_CLONE_sa_Subject(c, e, dup_strs);
	  if (!enn)
	      x->Subject = en;
	  else
	      enn->gg.g.n = &en->gg.g;
	  enn = en;
      }
  }

  return x;
}

/* FUNC(zx_WALK_SO_idp_SubjectRestriction) */

/* Depth first traversal of the tree in either schema order or the wire order. */
 
int zx_WALK_SO_idp_SubjectRestriction(struct zx_ctx* c, struct zx_idp_SubjectRestriction_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
{
  int ret = callback(&x->gg.g, ctx);
  if (ret)
    return ret;
  
  /* *** deal with xmlns specifications in exc c14n way */


  
  ret = zx_walk_so_unknown_attributes(c, &x->gg, ctx, callback); 
  if (ret)
    return ret;

  {
      struct zx_sa_Subject_s* e;
      for (e = x->Subject; e; e = (struct zx_sa_Subject_s*)e->gg.g.n) {
	  ret = zx_WALK_SO_sa_Subject(c, e, ctx, callback);
	  if (ret)
	      return ret;
      }
  }

  
  return zx_walk_so_unknown_elems_and_content(c, &x->gg, ctx, callback);
}

/* FUNC(zx_WALK_WO_idp_SubjectRestriction) */

int zx_WALK_WO_idp_SubjectRestriction(struct zx_ctx* c, struct zx_idp_SubjectRestriction_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
{
  ERR("*** walk_wo not implemented %d", 0);
  return 0;
}

#endif


/* EOF -- c/zx-idp-aux.c */
