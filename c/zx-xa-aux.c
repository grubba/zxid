/* c/zx-xa-aux.c - WARNING: This file was automatically generated. DO NOT EDIT!
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
#include "c/zx-xa-data.h"



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

#define EL_NAME   xa_Action
#define EL_STRUCT zx_xa_Action_s
#define EL_NS     xa
#define EL_TAG    Action

/* FUNC(zx_FREE_xa_Action) */

/* Depth first traversal of data structure to free it and its subelements. Simple
 * strings are handled as a special case according to the free_strs flag. This
 * is useful if the strings point to underlying data from the wire that was
 * allocated differently. */

/* Called by: */
void zx_FREE_xa_Action(struct zx_ctx* c, struct zx_xa_Action_s* x, int free_strs)
{
  /* *** deal with xmlns specifications in exc c14n way */


  {
      struct zx_xa_ActionMatch_s* e;
      struct zx_xa_ActionMatch_s* en;
      for (e = x->ActionMatch; e; e = en) {
	  en = (struct zx_xa_ActionMatch_s*)e->gg.g.n;
	  zx_FREE_xa_ActionMatch(c, e, free_strs);
      }
  }


  zx_free_elem_common(c, &x->gg, free_strs); 
}

/* FUNC(zx_NEW_xa_Action) */

/* Trivial allocator/constructor for the datatype. */

/* Called by: */
struct zx_xa_Action_s* zx_NEW_xa_Action(struct zx_ctx* c)
{
  struct zx_xa_Action_s* x = ZX_ZALLOC(c, struct zx_xa_Action_s);
  x->gg.g.tok = zx_xa_Action_ELEM;
  return x;
}

#ifdef ZX_ENA_AUX

/* FUNC(zx_DUP_STRS_xa_Action) */

/* Depth first traversal of data structure to copy its simple strings
 * to memory allocated from the memory allocator. The decoder will
 * use the underlying wireprotocol PDU buffer for strings, i.e.
 * strings are not copied - they point to the real data. If the
 * datastructure needs to outlast the protocol data or needs a different
 * memory allocation strategy, you need to call this function.  */

/* Called by: */
void zx_DUP_STRS_xa_Action(struct zx_ctx* c, struct zx_xa_Action_s* x)
{
  zx_dup_strs_common(c, &x->gg);
  /* *** deal with xmlns specifications in exc c14n way */


  {
      struct zx_xa_ActionMatch_s* e;
      for (e = x->ActionMatch; e; e = (struct zx_xa_ActionMatch_s*)e->gg.g.n)
	  zx_DUP_STRS_xa_ActionMatch(c, e);
  }

}

/* FUNC(zx_DEEP_CLONE_xa_Action) */

/* Depth first traversal of data structure to clone it and its sublements.
 * The simple strings are handled as a special case according to dup_strs flag. */

/* Called by: */
struct zx_xa_Action_s* zx_DEEP_CLONE_xa_Action(struct zx_ctx* c, struct zx_xa_Action_s* x, int dup_strs)
{
  x = (struct zx_xa_Action_s*)zx_clone_elem_common(c, &x->gg, sizeof(struct zx_xa_Action_s), dup_strs);
  /* *** deal with xmlns specifications in exc c14n way */


  {
      struct zx_xa_ActionMatch_s* e;
      struct zx_xa_ActionMatch_s* en;
      struct zx_xa_ActionMatch_s* enn;
      for (enn = 0, e = x->ActionMatch; e; e = (struct zx_xa_ActionMatch_s*)e->gg.g.n) {
	  en = zx_DEEP_CLONE_xa_ActionMatch(c, e, dup_strs);
	  if (!enn)
	      x->ActionMatch = en;
	  else
	      enn->gg.g.n = &en->gg.g;
	  enn = en;
      }
  }

  return x;
}

/* FUNC(zx_WALK_SO_xa_Action) */

/* Depth first traversal of the tree in either schema order or the wire order. */
 
int zx_WALK_SO_xa_Action(struct zx_ctx* c, struct zx_xa_Action_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
{
  int ret = callback(&x->gg.g, ctx);
  if (ret)
    return ret;
  
  /* *** deal with xmlns specifications in exc c14n way */


  
  ret = zx_walk_so_unknown_attributes(c, &x->gg, ctx, callback); 
  if (ret)
    return ret;

  {
      struct zx_xa_ActionMatch_s* e;
      for (e = x->ActionMatch; e; e = (struct zx_xa_ActionMatch_s*)e->gg.g.n) {
	  ret = zx_WALK_SO_xa_ActionMatch(c, e, ctx, callback);
	  if (ret)
	      return ret;
      }
  }

  
  return zx_walk_so_unknown_elems_and_content(c, &x->gg, ctx, callback);
}

/* FUNC(zx_WALK_WO_xa_Action) */

int zx_WALK_WO_xa_Action(struct zx_ctx* c, struct zx_xa_Action_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
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

#define EL_NAME   xa_ActionAttributeDesignator
#define EL_STRUCT zx_xa_ActionAttributeDesignator_s
#define EL_NS     xa
#define EL_TAG    ActionAttributeDesignator

/* FUNC(zx_FREE_xa_ActionAttributeDesignator) */

/* Depth first traversal of data structure to free it and its subelements. Simple
 * strings are handled as a special case according to the free_strs flag. This
 * is useful if the strings point to underlying data from the wire that was
 * allocated differently. */

/* Called by: */
void zx_FREE_xa_ActionAttributeDesignator(struct zx_ctx* c, struct zx_xa_ActionAttributeDesignator_s* x, int free_strs)
{
  /* *** deal with xmlns specifications in exc c14n way */

  zx_free_attr(c, x->AttributeId, free_strs);
  zx_free_attr(c, x->DataType, free_strs);
  zx_free_attr(c, x->Issuer, free_strs);
  zx_free_attr(c, x->MustBePresent, free_strs);



  zx_free_elem_common(c, &x->gg, free_strs); 
}

/* FUNC(zx_NEW_xa_ActionAttributeDesignator) */

/* Trivial allocator/constructor for the datatype. */

/* Called by: */
struct zx_xa_ActionAttributeDesignator_s* zx_NEW_xa_ActionAttributeDesignator(struct zx_ctx* c)
{
  struct zx_xa_ActionAttributeDesignator_s* x = ZX_ZALLOC(c, struct zx_xa_ActionAttributeDesignator_s);
  x->gg.g.tok = zx_xa_ActionAttributeDesignator_ELEM;
  return x;
}

#ifdef ZX_ENA_AUX

/* FUNC(zx_DUP_STRS_xa_ActionAttributeDesignator) */

/* Depth first traversal of data structure to copy its simple strings
 * to memory allocated from the memory allocator. The decoder will
 * use the underlying wireprotocol PDU buffer for strings, i.e.
 * strings are not copied - they point to the real data. If the
 * datastructure needs to outlast the protocol data or needs a different
 * memory allocation strategy, you need to call this function.  */

/* Called by: */
void zx_DUP_STRS_xa_ActionAttributeDesignator(struct zx_ctx* c, struct zx_xa_ActionAttributeDesignator_s* x)
{
  zx_dup_strs_common(c, &x->gg);
  /* *** deal with xmlns specifications in exc c14n way */

  zx_dup_attr(c, x->AttributeId);
  zx_dup_attr(c, x->DataType);
  zx_dup_attr(c, x->Issuer);
  zx_dup_attr(c, x->MustBePresent);


}

/* FUNC(zx_DEEP_CLONE_xa_ActionAttributeDesignator) */

/* Depth first traversal of data structure to clone it and its sublements.
 * The simple strings are handled as a special case according to dup_strs flag. */

/* Called by: */
struct zx_xa_ActionAttributeDesignator_s* zx_DEEP_CLONE_xa_ActionAttributeDesignator(struct zx_ctx* c, struct zx_xa_ActionAttributeDesignator_s* x, int dup_strs)
{
  x = (struct zx_xa_ActionAttributeDesignator_s*)zx_clone_elem_common(c, &x->gg, sizeof(struct zx_xa_ActionAttributeDesignator_s), dup_strs);
  /* *** deal with xmlns specifications in exc c14n way */

  x->AttributeId = zx_clone_attr(c, x->AttributeId);
  x->DataType = zx_clone_attr(c, x->DataType);
  x->Issuer = zx_clone_attr(c, x->Issuer);
  x->MustBePresent = zx_clone_attr(c, x->MustBePresent);


  return x;
}

/* FUNC(zx_WALK_SO_xa_ActionAttributeDesignator) */

/* Depth first traversal of the tree in either schema order or the wire order. */
 
int zx_WALK_SO_xa_ActionAttributeDesignator(struct zx_ctx* c, struct zx_xa_ActionAttributeDesignator_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
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

/* FUNC(zx_WALK_WO_xa_ActionAttributeDesignator) */

int zx_WALK_WO_xa_ActionAttributeDesignator(struct zx_ctx* c, struct zx_xa_ActionAttributeDesignator_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
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

#define EL_NAME   xa_ActionMatch
#define EL_STRUCT zx_xa_ActionMatch_s
#define EL_NS     xa
#define EL_TAG    ActionMatch

/* FUNC(zx_FREE_xa_ActionMatch) */

/* Depth first traversal of data structure to free it and its subelements. Simple
 * strings are handled as a special case according to the free_strs flag. This
 * is useful if the strings point to underlying data from the wire that was
 * allocated differently. */

/* Called by: */
void zx_FREE_xa_ActionMatch(struct zx_ctx* c, struct zx_xa_ActionMatch_s* x, int free_strs)
{
  /* *** deal with xmlns specifications in exc c14n way */

  zx_free_attr(c, x->MatchId, free_strs);

  {
      struct zx_xa_AttributeValue_s* e;
      struct zx_xa_AttributeValue_s* en;
      for (e = x->AttributeValue; e; e = en) {
	  en = (struct zx_xa_AttributeValue_s*)e->gg.g.n;
	  zx_FREE_xa_AttributeValue(c, e, free_strs);
      }
  }
  {
      struct zx_xa_ActionAttributeDesignator_s* e;
      struct zx_xa_ActionAttributeDesignator_s* en;
      for (e = x->ActionAttributeDesignator; e; e = en) {
	  en = (struct zx_xa_ActionAttributeDesignator_s*)e->gg.g.n;
	  zx_FREE_xa_ActionAttributeDesignator(c, e, free_strs);
      }
  }
  {
      struct zx_xa_AttributeSelector_s* e;
      struct zx_xa_AttributeSelector_s* en;
      for (e = x->AttributeSelector; e; e = en) {
	  en = (struct zx_xa_AttributeSelector_s*)e->gg.g.n;
	  zx_FREE_xa_AttributeSelector(c, e, free_strs);
      }
  }


  zx_free_elem_common(c, &x->gg, free_strs); 
}

/* FUNC(zx_NEW_xa_ActionMatch) */

/* Trivial allocator/constructor for the datatype. */

/* Called by: */
struct zx_xa_ActionMatch_s* zx_NEW_xa_ActionMatch(struct zx_ctx* c)
{
  struct zx_xa_ActionMatch_s* x = ZX_ZALLOC(c, struct zx_xa_ActionMatch_s);
  x->gg.g.tok = zx_xa_ActionMatch_ELEM;
  return x;
}

#ifdef ZX_ENA_AUX

/* FUNC(zx_DUP_STRS_xa_ActionMatch) */

/* Depth first traversal of data structure to copy its simple strings
 * to memory allocated from the memory allocator. The decoder will
 * use the underlying wireprotocol PDU buffer for strings, i.e.
 * strings are not copied - they point to the real data. If the
 * datastructure needs to outlast the protocol data or needs a different
 * memory allocation strategy, you need to call this function.  */

/* Called by: */
void zx_DUP_STRS_xa_ActionMatch(struct zx_ctx* c, struct zx_xa_ActionMatch_s* x)
{
  zx_dup_strs_common(c, &x->gg);
  /* *** deal with xmlns specifications in exc c14n way */

  zx_dup_attr(c, x->MatchId);

  {
      struct zx_xa_AttributeValue_s* e;
      for (e = x->AttributeValue; e; e = (struct zx_xa_AttributeValue_s*)e->gg.g.n)
	  zx_DUP_STRS_xa_AttributeValue(c, e);
  }
  {
      struct zx_xa_ActionAttributeDesignator_s* e;
      for (e = x->ActionAttributeDesignator; e; e = (struct zx_xa_ActionAttributeDesignator_s*)e->gg.g.n)
	  zx_DUP_STRS_xa_ActionAttributeDesignator(c, e);
  }
  {
      struct zx_xa_AttributeSelector_s* e;
      for (e = x->AttributeSelector; e; e = (struct zx_xa_AttributeSelector_s*)e->gg.g.n)
	  zx_DUP_STRS_xa_AttributeSelector(c, e);
  }

}

/* FUNC(zx_DEEP_CLONE_xa_ActionMatch) */

/* Depth first traversal of data structure to clone it and its sublements.
 * The simple strings are handled as a special case according to dup_strs flag. */

/* Called by: */
struct zx_xa_ActionMatch_s* zx_DEEP_CLONE_xa_ActionMatch(struct zx_ctx* c, struct zx_xa_ActionMatch_s* x, int dup_strs)
{
  x = (struct zx_xa_ActionMatch_s*)zx_clone_elem_common(c, &x->gg, sizeof(struct zx_xa_ActionMatch_s), dup_strs);
  /* *** deal with xmlns specifications in exc c14n way */

  x->MatchId = zx_clone_attr(c, x->MatchId);

  {
      struct zx_xa_AttributeValue_s* e;
      struct zx_xa_AttributeValue_s* en;
      struct zx_xa_AttributeValue_s* enn;
      for (enn = 0, e = x->AttributeValue; e; e = (struct zx_xa_AttributeValue_s*)e->gg.g.n) {
	  en = zx_DEEP_CLONE_xa_AttributeValue(c, e, dup_strs);
	  if (!enn)
	      x->AttributeValue = en;
	  else
	      enn->gg.g.n = &en->gg.g;
	  enn = en;
      }
  }
  {
      struct zx_xa_ActionAttributeDesignator_s* e;
      struct zx_xa_ActionAttributeDesignator_s* en;
      struct zx_xa_ActionAttributeDesignator_s* enn;
      for (enn = 0, e = x->ActionAttributeDesignator; e; e = (struct zx_xa_ActionAttributeDesignator_s*)e->gg.g.n) {
	  en = zx_DEEP_CLONE_xa_ActionAttributeDesignator(c, e, dup_strs);
	  if (!enn)
	      x->ActionAttributeDesignator = en;
	  else
	      enn->gg.g.n = &en->gg.g;
	  enn = en;
      }
  }
  {
      struct zx_xa_AttributeSelector_s* e;
      struct zx_xa_AttributeSelector_s* en;
      struct zx_xa_AttributeSelector_s* enn;
      for (enn = 0, e = x->AttributeSelector; e; e = (struct zx_xa_AttributeSelector_s*)e->gg.g.n) {
	  en = zx_DEEP_CLONE_xa_AttributeSelector(c, e, dup_strs);
	  if (!enn)
	      x->AttributeSelector = en;
	  else
	      enn->gg.g.n = &en->gg.g;
	  enn = en;
      }
  }

  return x;
}

/* FUNC(zx_WALK_SO_xa_ActionMatch) */

/* Depth first traversal of the tree in either schema order or the wire order. */
 
int zx_WALK_SO_xa_ActionMatch(struct zx_ctx* c, struct zx_xa_ActionMatch_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
{
  int ret = callback(&x->gg.g, ctx);
  if (ret)
    return ret;
  
  /* *** deal with xmlns specifications in exc c14n way */


  
  ret = zx_walk_so_unknown_attributes(c, &x->gg, ctx, callback); 
  if (ret)
    return ret;

  {
      struct zx_xa_AttributeValue_s* e;
      for (e = x->AttributeValue; e; e = (struct zx_xa_AttributeValue_s*)e->gg.g.n) {
	  ret = zx_WALK_SO_xa_AttributeValue(c, e, ctx, callback);
	  if (ret)
	      return ret;
      }
  }
  {
      struct zx_xa_ActionAttributeDesignator_s* e;
      for (e = x->ActionAttributeDesignator; e; e = (struct zx_xa_ActionAttributeDesignator_s*)e->gg.g.n) {
	  ret = zx_WALK_SO_xa_ActionAttributeDesignator(c, e, ctx, callback);
	  if (ret)
	      return ret;
      }
  }
  {
      struct zx_xa_AttributeSelector_s* e;
      for (e = x->AttributeSelector; e; e = (struct zx_xa_AttributeSelector_s*)e->gg.g.n) {
	  ret = zx_WALK_SO_xa_AttributeSelector(c, e, ctx, callback);
	  if (ret)
	      return ret;
      }
  }

  
  return zx_walk_so_unknown_elems_and_content(c, &x->gg, ctx, callback);
}

/* FUNC(zx_WALK_WO_xa_ActionMatch) */

int zx_WALK_WO_xa_ActionMatch(struct zx_ctx* c, struct zx_xa_ActionMatch_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
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

#define EL_NAME   xa_Actions
#define EL_STRUCT zx_xa_Actions_s
#define EL_NS     xa
#define EL_TAG    Actions

/* FUNC(zx_FREE_xa_Actions) */

/* Depth first traversal of data structure to free it and its subelements. Simple
 * strings are handled as a special case according to the free_strs flag. This
 * is useful if the strings point to underlying data from the wire that was
 * allocated differently. */

/* Called by: */
void zx_FREE_xa_Actions(struct zx_ctx* c, struct zx_xa_Actions_s* x, int free_strs)
{
  /* *** deal with xmlns specifications in exc c14n way */


  {
      struct zx_xa_Action_s* e;
      struct zx_xa_Action_s* en;
      for (e = x->Action; e; e = en) {
	  en = (struct zx_xa_Action_s*)e->gg.g.n;
	  zx_FREE_xa_Action(c, e, free_strs);
      }
  }


  zx_free_elem_common(c, &x->gg, free_strs); 
}

/* FUNC(zx_NEW_xa_Actions) */

/* Trivial allocator/constructor for the datatype. */

/* Called by: */
struct zx_xa_Actions_s* zx_NEW_xa_Actions(struct zx_ctx* c)
{
  struct zx_xa_Actions_s* x = ZX_ZALLOC(c, struct zx_xa_Actions_s);
  x->gg.g.tok = zx_xa_Actions_ELEM;
  return x;
}

#ifdef ZX_ENA_AUX

/* FUNC(zx_DUP_STRS_xa_Actions) */

/* Depth first traversal of data structure to copy its simple strings
 * to memory allocated from the memory allocator. The decoder will
 * use the underlying wireprotocol PDU buffer for strings, i.e.
 * strings are not copied - they point to the real data. If the
 * datastructure needs to outlast the protocol data or needs a different
 * memory allocation strategy, you need to call this function.  */

/* Called by: */
void zx_DUP_STRS_xa_Actions(struct zx_ctx* c, struct zx_xa_Actions_s* x)
{
  zx_dup_strs_common(c, &x->gg);
  /* *** deal with xmlns specifications in exc c14n way */


  {
      struct zx_xa_Action_s* e;
      for (e = x->Action; e; e = (struct zx_xa_Action_s*)e->gg.g.n)
	  zx_DUP_STRS_xa_Action(c, e);
  }

}

/* FUNC(zx_DEEP_CLONE_xa_Actions) */

/* Depth first traversal of data structure to clone it and its sublements.
 * The simple strings are handled as a special case according to dup_strs flag. */

/* Called by: */
struct zx_xa_Actions_s* zx_DEEP_CLONE_xa_Actions(struct zx_ctx* c, struct zx_xa_Actions_s* x, int dup_strs)
{
  x = (struct zx_xa_Actions_s*)zx_clone_elem_common(c, &x->gg, sizeof(struct zx_xa_Actions_s), dup_strs);
  /* *** deal with xmlns specifications in exc c14n way */


  {
      struct zx_xa_Action_s* e;
      struct zx_xa_Action_s* en;
      struct zx_xa_Action_s* enn;
      for (enn = 0, e = x->Action; e; e = (struct zx_xa_Action_s*)e->gg.g.n) {
	  en = zx_DEEP_CLONE_xa_Action(c, e, dup_strs);
	  if (!enn)
	      x->Action = en;
	  else
	      enn->gg.g.n = &en->gg.g;
	  enn = en;
      }
  }

  return x;
}

/* FUNC(zx_WALK_SO_xa_Actions) */

/* Depth first traversal of the tree in either schema order or the wire order. */
 
int zx_WALK_SO_xa_Actions(struct zx_ctx* c, struct zx_xa_Actions_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
{
  int ret = callback(&x->gg.g, ctx);
  if (ret)
    return ret;
  
  /* *** deal with xmlns specifications in exc c14n way */


  
  ret = zx_walk_so_unknown_attributes(c, &x->gg, ctx, callback); 
  if (ret)
    return ret;

  {
      struct zx_xa_Action_s* e;
      for (e = x->Action; e; e = (struct zx_xa_Action_s*)e->gg.g.n) {
	  ret = zx_WALK_SO_xa_Action(c, e, ctx, callback);
	  if (ret)
	      return ret;
      }
  }

  
  return zx_walk_so_unknown_elems_and_content(c, &x->gg, ctx, callback);
}

/* FUNC(zx_WALK_WO_xa_Actions) */

int zx_WALK_WO_xa_Actions(struct zx_ctx* c, struct zx_xa_Actions_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
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

#define EL_NAME   xa_Apply
#define EL_STRUCT zx_xa_Apply_s
#define EL_NS     xa
#define EL_TAG    Apply

/* FUNC(zx_FREE_xa_Apply) */

/* Depth first traversal of data structure to free it and its subelements. Simple
 * strings are handled as a special case according to the free_strs flag. This
 * is useful if the strings point to underlying data from the wire that was
 * allocated differently. */

/* Called by: */
void zx_FREE_xa_Apply(struct zx_ctx* c, struct zx_xa_Apply_s* x, int free_strs)
{
  /* *** deal with xmlns specifications in exc c14n way */

  zx_free_attr(c, x->FunctionId, free_strs);

  zx_free_simple_elems(c, x->Expression, free_strs);


  zx_free_elem_common(c, &x->gg, free_strs); 
}

/* FUNC(zx_NEW_xa_Apply) */

/* Trivial allocator/constructor for the datatype. */

/* Called by: */
struct zx_xa_Apply_s* zx_NEW_xa_Apply(struct zx_ctx* c)
{
  struct zx_xa_Apply_s* x = ZX_ZALLOC(c, struct zx_xa_Apply_s);
  x->gg.g.tok = zx_xa_Apply_ELEM;
  return x;
}

#ifdef ZX_ENA_AUX

/* FUNC(zx_DUP_STRS_xa_Apply) */

/* Depth first traversal of data structure to copy its simple strings
 * to memory allocated from the memory allocator. The decoder will
 * use the underlying wireprotocol PDU buffer for strings, i.e.
 * strings are not copied - they point to the real data. If the
 * datastructure needs to outlast the protocol data or needs a different
 * memory allocation strategy, you need to call this function.  */

/* Called by: */
void zx_DUP_STRS_xa_Apply(struct zx_ctx* c, struct zx_xa_Apply_s* x)
{
  zx_dup_strs_common(c, &x->gg);
  /* *** deal with xmlns specifications in exc c14n way */

  zx_dup_attr(c, x->FunctionId);

  zx_dup_strs_simple_elems(c, x->Expression);

}

/* FUNC(zx_DEEP_CLONE_xa_Apply) */

/* Depth first traversal of data structure to clone it and its sublements.
 * The simple strings are handled as a special case according to dup_strs flag. */

/* Called by: */
struct zx_xa_Apply_s* zx_DEEP_CLONE_xa_Apply(struct zx_ctx* c, struct zx_xa_Apply_s* x, int dup_strs)
{
  x = (struct zx_xa_Apply_s*)zx_clone_elem_common(c, &x->gg, sizeof(struct zx_xa_Apply_s), dup_strs);
  /* *** deal with xmlns specifications in exc c14n way */

  x->FunctionId = zx_clone_attr(c, x->FunctionId);

  x->Expression = zx_deep_clone_simple_elems(c,x->Expression, dup_strs);

  return x;
}

/* FUNC(zx_WALK_SO_xa_Apply) */

/* Depth first traversal of the tree in either schema order or the wire order. */
 
int zx_WALK_SO_xa_Apply(struct zx_ctx* c, struct zx_xa_Apply_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
{
  int ret = callback(&x->gg.g, ctx);
  if (ret)
    return ret;
  
  /* *** deal with xmlns specifications in exc c14n way */


  
  ret = zx_walk_so_unknown_attributes(c, &x->gg, ctx, callback); 
  if (ret)
    return ret;

  ret = zx_walk_so_simple_elems(c, x->Expression, ctx, callback);
  if (ret)
    return ret;

  
  return zx_walk_so_unknown_elems_and_content(c, &x->gg, ctx, callback);
}

/* FUNC(zx_WALK_WO_xa_Apply) */

int zx_WALK_WO_xa_Apply(struct zx_ctx* c, struct zx_xa_Apply_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
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

#define EL_NAME   xa_AttributeAssignment
#define EL_STRUCT zx_xa_AttributeAssignment_s
#define EL_NS     xa
#define EL_TAG    AttributeAssignment

/* FUNC(zx_FREE_xa_AttributeAssignment) */

/* Depth first traversal of data structure to free it and its subelements. Simple
 * strings are handled as a special case according to the free_strs flag. This
 * is useful if the strings point to underlying data from the wire that was
 * allocated differently. */

/* Called by: */
void zx_FREE_xa_AttributeAssignment(struct zx_ctx* c, struct zx_xa_AttributeAssignment_s* x, int free_strs)
{
  /* *** deal with xmlns specifications in exc c14n way */

  zx_free_attr(c, x->AttributeId, free_strs);
  zx_free_attr(c, x->DataType, free_strs);



  zx_free_elem_common(c, &x->gg, free_strs); 
}

/* FUNC(zx_NEW_xa_AttributeAssignment) */

/* Trivial allocator/constructor for the datatype. */

/* Called by: */
struct zx_xa_AttributeAssignment_s* zx_NEW_xa_AttributeAssignment(struct zx_ctx* c)
{
  struct zx_xa_AttributeAssignment_s* x = ZX_ZALLOC(c, struct zx_xa_AttributeAssignment_s);
  x->gg.g.tok = zx_xa_AttributeAssignment_ELEM;
  return x;
}

#ifdef ZX_ENA_AUX

/* FUNC(zx_DUP_STRS_xa_AttributeAssignment) */

/* Depth first traversal of data structure to copy its simple strings
 * to memory allocated from the memory allocator. The decoder will
 * use the underlying wireprotocol PDU buffer for strings, i.e.
 * strings are not copied - they point to the real data. If the
 * datastructure needs to outlast the protocol data or needs a different
 * memory allocation strategy, you need to call this function.  */

/* Called by: */
void zx_DUP_STRS_xa_AttributeAssignment(struct zx_ctx* c, struct zx_xa_AttributeAssignment_s* x)
{
  zx_dup_strs_common(c, &x->gg);
  /* *** deal with xmlns specifications in exc c14n way */

  zx_dup_attr(c, x->AttributeId);
  zx_dup_attr(c, x->DataType);


}

/* FUNC(zx_DEEP_CLONE_xa_AttributeAssignment) */

/* Depth first traversal of data structure to clone it and its sublements.
 * The simple strings are handled as a special case according to dup_strs flag. */

/* Called by: */
struct zx_xa_AttributeAssignment_s* zx_DEEP_CLONE_xa_AttributeAssignment(struct zx_ctx* c, struct zx_xa_AttributeAssignment_s* x, int dup_strs)
{
  x = (struct zx_xa_AttributeAssignment_s*)zx_clone_elem_common(c, &x->gg, sizeof(struct zx_xa_AttributeAssignment_s), dup_strs);
  /* *** deal with xmlns specifications in exc c14n way */

  x->AttributeId = zx_clone_attr(c, x->AttributeId);
  x->DataType = zx_clone_attr(c, x->DataType);


  return x;
}

/* FUNC(zx_WALK_SO_xa_AttributeAssignment) */

/* Depth first traversal of the tree in either schema order or the wire order. */
 
int zx_WALK_SO_xa_AttributeAssignment(struct zx_ctx* c, struct zx_xa_AttributeAssignment_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
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

/* FUNC(zx_WALK_WO_xa_AttributeAssignment) */

int zx_WALK_WO_xa_AttributeAssignment(struct zx_ctx* c, struct zx_xa_AttributeAssignment_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
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

#define EL_NAME   xa_AttributeSelector
#define EL_STRUCT zx_xa_AttributeSelector_s
#define EL_NS     xa
#define EL_TAG    AttributeSelector

/* FUNC(zx_FREE_xa_AttributeSelector) */

/* Depth first traversal of data structure to free it and its subelements. Simple
 * strings are handled as a special case according to the free_strs flag. This
 * is useful if the strings point to underlying data from the wire that was
 * allocated differently. */

/* Called by: */
void zx_FREE_xa_AttributeSelector(struct zx_ctx* c, struct zx_xa_AttributeSelector_s* x, int free_strs)
{
  /* *** deal with xmlns specifications in exc c14n way */

  zx_free_attr(c, x->DataType, free_strs);
  zx_free_attr(c, x->MustBePresent, free_strs);
  zx_free_attr(c, x->RequestContextPath, free_strs);



  zx_free_elem_common(c, &x->gg, free_strs); 
}

/* FUNC(zx_NEW_xa_AttributeSelector) */

/* Trivial allocator/constructor for the datatype. */

/* Called by: */
struct zx_xa_AttributeSelector_s* zx_NEW_xa_AttributeSelector(struct zx_ctx* c)
{
  struct zx_xa_AttributeSelector_s* x = ZX_ZALLOC(c, struct zx_xa_AttributeSelector_s);
  x->gg.g.tok = zx_xa_AttributeSelector_ELEM;
  return x;
}

#ifdef ZX_ENA_AUX

/* FUNC(zx_DUP_STRS_xa_AttributeSelector) */

/* Depth first traversal of data structure to copy its simple strings
 * to memory allocated from the memory allocator. The decoder will
 * use the underlying wireprotocol PDU buffer for strings, i.e.
 * strings are not copied - they point to the real data. If the
 * datastructure needs to outlast the protocol data or needs a different
 * memory allocation strategy, you need to call this function.  */

/* Called by: */
void zx_DUP_STRS_xa_AttributeSelector(struct zx_ctx* c, struct zx_xa_AttributeSelector_s* x)
{
  zx_dup_strs_common(c, &x->gg);
  /* *** deal with xmlns specifications in exc c14n way */

  zx_dup_attr(c, x->DataType);
  zx_dup_attr(c, x->MustBePresent);
  zx_dup_attr(c, x->RequestContextPath);


}

/* FUNC(zx_DEEP_CLONE_xa_AttributeSelector) */

/* Depth first traversal of data structure to clone it and its sublements.
 * The simple strings are handled as a special case according to dup_strs flag. */

/* Called by: */
struct zx_xa_AttributeSelector_s* zx_DEEP_CLONE_xa_AttributeSelector(struct zx_ctx* c, struct zx_xa_AttributeSelector_s* x, int dup_strs)
{
  x = (struct zx_xa_AttributeSelector_s*)zx_clone_elem_common(c, &x->gg, sizeof(struct zx_xa_AttributeSelector_s), dup_strs);
  /* *** deal with xmlns specifications in exc c14n way */

  x->DataType = zx_clone_attr(c, x->DataType);
  x->MustBePresent = zx_clone_attr(c, x->MustBePresent);
  x->RequestContextPath = zx_clone_attr(c, x->RequestContextPath);


  return x;
}

/* FUNC(zx_WALK_SO_xa_AttributeSelector) */

/* Depth first traversal of the tree in either schema order or the wire order. */
 
int zx_WALK_SO_xa_AttributeSelector(struct zx_ctx* c, struct zx_xa_AttributeSelector_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
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

/* FUNC(zx_WALK_WO_xa_AttributeSelector) */

int zx_WALK_WO_xa_AttributeSelector(struct zx_ctx* c, struct zx_xa_AttributeSelector_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
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

#define EL_NAME   xa_AttributeValue
#define EL_STRUCT zx_xa_AttributeValue_s
#define EL_NS     xa
#define EL_TAG    AttributeValue

/* FUNC(zx_FREE_xa_AttributeValue) */

/* Depth first traversal of data structure to free it and its subelements. Simple
 * strings are handled as a special case according to the free_strs flag. This
 * is useful if the strings point to underlying data from the wire that was
 * allocated differently. */

/* Called by: */
void zx_FREE_xa_AttributeValue(struct zx_ctx* c, struct zx_xa_AttributeValue_s* x, int free_strs)
{
  /* *** deal with xmlns specifications in exc c14n way */

  zx_free_attr(c, x->DataType, free_strs);



  zx_free_elem_common(c, &x->gg, free_strs); 
}

/* FUNC(zx_NEW_xa_AttributeValue) */

/* Trivial allocator/constructor for the datatype. */

/* Called by: */
struct zx_xa_AttributeValue_s* zx_NEW_xa_AttributeValue(struct zx_ctx* c)
{
  struct zx_xa_AttributeValue_s* x = ZX_ZALLOC(c, struct zx_xa_AttributeValue_s);
  x->gg.g.tok = zx_xa_AttributeValue_ELEM;
  return x;
}

#ifdef ZX_ENA_AUX

/* FUNC(zx_DUP_STRS_xa_AttributeValue) */

/* Depth first traversal of data structure to copy its simple strings
 * to memory allocated from the memory allocator. The decoder will
 * use the underlying wireprotocol PDU buffer for strings, i.e.
 * strings are not copied - they point to the real data. If the
 * datastructure needs to outlast the protocol data or needs a different
 * memory allocation strategy, you need to call this function.  */

/* Called by: */
void zx_DUP_STRS_xa_AttributeValue(struct zx_ctx* c, struct zx_xa_AttributeValue_s* x)
{
  zx_dup_strs_common(c, &x->gg);
  /* *** deal with xmlns specifications in exc c14n way */

  zx_dup_attr(c, x->DataType);


}

/* FUNC(zx_DEEP_CLONE_xa_AttributeValue) */

/* Depth first traversal of data structure to clone it and its sublements.
 * The simple strings are handled as a special case according to dup_strs flag. */

/* Called by: */
struct zx_xa_AttributeValue_s* zx_DEEP_CLONE_xa_AttributeValue(struct zx_ctx* c, struct zx_xa_AttributeValue_s* x, int dup_strs)
{
  x = (struct zx_xa_AttributeValue_s*)zx_clone_elem_common(c, &x->gg, sizeof(struct zx_xa_AttributeValue_s), dup_strs);
  /* *** deal with xmlns specifications in exc c14n way */

  x->DataType = zx_clone_attr(c, x->DataType);


  return x;
}

/* FUNC(zx_WALK_SO_xa_AttributeValue) */

/* Depth first traversal of the tree in either schema order or the wire order. */
 
int zx_WALK_SO_xa_AttributeValue(struct zx_ctx* c, struct zx_xa_AttributeValue_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
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

/* FUNC(zx_WALK_WO_xa_AttributeValue) */

int zx_WALK_WO_xa_AttributeValue(struct zx_ctx* c, struct zx_xa_AttributeValue_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
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

#define EL_NAME   xa_CombinerParameter
#define EL_STRUCT zx_xa_CombinerParameter_s
#define EL_NS     xa
#define EL_TAG    CombinerParameter

/* FUNC(zx_FREE_xa_CombinerParameter) */

/* Depth first traversal of data structure to free it and its subelements. Simple
 * strings are handled as a special case according to the free_strs flag. This
 * is useful if the strings point to underlying data from the wire that was
 * allocated differently. */

/* Called by: */
void zx_FREE_xa_CombinerParameter(struct zx_ctx* c, struct zx_xa_CombinerParameter_s* x, int free_strs)
{
  /* *** deal with xmlns specifications in exc c14n way */

  zx_free_attr(c, x->ParameterName, free_strs);

  {
      struct zx_xa_AttributeValue_s* e;
      struct zx_xa_AttributeValue_s* en;
      for (e = x->AttributeValue; e; e = en) {
	  en = (struct zx_xa_AttributeValue_s*)e->gg.g.n;
	  zx_FREE_xa_AttributeValue(c, e, free_strs);
      }
  }


  zx_free_elem_common(c, &x->gg, free_strs); 
}

/* FUNC(zx_NEW_xa_CombinerParameter) */

/* Trivial allocator/constructor for the datatype. */

/* Called by: */
struct zx_xa_CombinerParameter_s* zx_NEW_xa_CombinerParameter(struct zx_ctx* c)
{
  struct zx_xa_CombinerParameter_s* x = ZX_ZALLOC(c, struct zx_xa_CombinerParameter_s);
  x->gg.g.tok = zx_xa_CombinerParameter_ELEM;
  return x;
}

#ifdef ZX_ENA_AUX

/* FUNC(zx_DUP_STRS_xa_CombinerParameter) */

/* Depth first traversal of data structure to copy its simple strings
 * to memory allocated from the memory allocator. The decoder will
 * use the underlying wireprotocol PDU buffer for strings, i.e.
 * strings are not copied - they point to the real data. If the
 * datastructure needs to outlast the protocol data or needs a different
 * memory allocation strategy, you need to call this function.  */

/* Called by: */
void zx_DUP_STRS_xa_CombinerParameter(struct zx_ctx* c, struct zx_xa_CombinerParameter_s* x)
{
  zx_dup_strs_common(c, &x->gg);
  /* *** deal with xmlns specifications in exc c14n way */

  zx_dup_attr(c, x->ParameterName);

  {
      struct zx_xa_AttributeValue_s* e;
      for (e = x->AttributeValue; e; e = (struct zx_xa_AttributeValue_s*)e->gg.g.n)
	  zx_DUP_STRS_xa_AttributeValue(c, e);
  }

}

/* FUNC(zx_DEEP_CLONE_xa_CombinerParameter) */

/* Depth first traversal of data structure to clone it and its sublements.
 * The simple strings are handled as a special case according to dup_strs flag. */

/* Called by: */
struct zx_xa_CombinerParameter_s* zx_DEEP_CLONE_xa_CombinerParameter(struct zx_ctx* c, struct zx_xa_CombinerParameter_s* x, int dup_strs)
{
  x = (struct zx_xa_CombinerParameter_s*)zx_clone_elem_common(c, &x->gg, sizeof(struct zx_xa_CombinerParameter_s), dup_strs);
  /* *** deal with xmlns specifications in exc c14n way */

  x->ParameterName = zx_clone_attr(c, x->ParameterName);

  {
      struct zx_xa_AttributeValue_s* e;
      struct zx_xa_AttributeValue_s* en;
      struct zx_xa_AttributeValue_s* enn;
      for (enn = 0, e = x->AttributeValue; e; e = (struct zx_xa_AttributeValue_s*)e->gg.g.n) {
	  en = zx_DEEP_CLONE_xa_AttributeValue(c, e, dup_strs);
	  if (!enn)
	      x->AttributeValue = en;
	  else
	      enn->gg.g.n = &en->gg.g;
	  enn = en;
      }
  }

  return x;
}

/* FUNC(zx_WALK_SO_xa_CombinerParameter) */

/* Depth first traversal of the tree in either schema order or the wire order. */
 
int zx_WALK_SO_xa_CombinerParameter(struct zx_ctx* c, struct zx_xa_CombinerParameter_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
{
  int ret = callback(&x->gg.g, ctx);
  if (ret)
    return ret;
  
  /* *** deal with xmlns specifications in exc c14n way */


  
  ret = zx_walk_so_unknown_attributes(c, &x->gg, ctx, callback); 
  if (ret)
    return ret;

  {
      struct zx_xa_AttributeValue_s* e;
      for (e = x->AttributeValue; e; e = (struct zx_xa_AttributeValue_s*)e->gg.g.n) {
	  ret = zx_WALK_SO_xa_AttributeValue(c, e, ctx, callback);
	  if (ret)
	      return ret;
      }
  }

  
  return zx_walk_so_unknown_elems_and_content(c, &x->gg, ctx, callback);
}

/* FUNC(zx_WALK_WO_xa_CombinerParameter) */

int zx_WALK_WO_xa_CombinerParameter(struct zx_ctx* c, struct zx_xa_CombinerParameter_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
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

#define EL_NAME   xa_CombinerParameters
#define EL_STRUCT zx_xa_CombinerParameters_s
#define EL_NS     xa
#define EL_TAG    CombinerParameters

/* FUNC(zx_FREE_xa_CombinerParameters) */

/* Depth first traversal of data structure to free it and its subelements. Simple
 * strings are handled as a special case according to the free_strs flag. This
 * is useful if the strings point to underlying data from the wire that was
 * allocated differently. */

/* Called by: */
void zx_FREE_xa_CombinerParameters(struct zx_ctx* c, struct zx_xa_CombinerParameters_s* x, int free_strs)
{
  /* *** deal with xmlns specifications in exc c14n way */


  {
      struct zx_xa_CombinerParameter_s* e;
      struct zx_xa_CombinerParameter_s* en;
      for (e = x->CombinerParameter; e; e = en) {
	  en = (struct zx_xa_CombinerParameter_s*)e->gg.g.n;
	  zx_FREE_xa_CombinerParameter(c, e, free_strs);
      }
  }


  zx_free_elem_common(c, &x->gg, free_strs); 
}

/* FUNC(zx_NEW_xa_CombinerParameters) */

/* Trivial allocator/constructor for the datatype. */

/* Called by: */
struct zx_xa_CombinerParameters_s* zx_NEW_xa_CombinerParameters(struct zx_ctx* c)
{
  struct zx_xa_CombinerParameters_s* x = ZX_ZALLOC(c, struct zx_xa_CombinerParameters_s);
  x->gg.g.tok = zx_xa_CombinerParameters_ELEM;
  return x;
}

#ifdef ZX_ENA_AUX

/* FUNC(zx_DUP_STRS_xa_CombinerParameters) */

/* Depth first traversal of data structure to copy its simple strings
 * to memory allocated from the memory allocator. The decoder will
 * use the underlying wireprotocol PDU buffer for strings, i.e.
 * strings are not copied - they point to the real data. If the
 * datastructure needs to outlast the protocol data or needs a different
 * memory allocation strategy, you need to call this function.  */

/* Called by: */
void zx_DUP_STRS_xa_CombinerParameters(struct zx_ctx* c, struct zx_xa_CombinerParameters_s* x)
{
  zx_dup_strs_common(c, &x->gg);
  /* *** deal with xmlns specifications in exc c14n way */


  {
      struct zx_xa_CombinerParameter_s* e;
      for (e = x->CombinerParameter; e; e = (struct zx_xa_CombinerParameter_s*)e->gg.g.n)
	  zx_DUP_STRS_xa_CombinerParameter(c, e);
  }

}

/* FUNC(zx_DEEP_CLONE_xa_CombinerParameters) */

/* Depth first traversal of data structure to clone it and its sublements.
 * The simple strings are handled as a special case according to dup_strs flag. */

/* Called by: */
struct zx_xa_CombinerParameters_s* zx_DEEP_CLONE_xa_CombinerParameters(struct zx_ctx* c, struct zx_xa_CombinerParameters_s* x, int dup_strs)
{
  x = (struct zx_xa_CombinerParameters_s*)zx_clone_elem_common(c, &x->gg, sizeof(struct zx_xa_CombinerParameters_s), dup_strs);
  /* *** deal with xmlns specifications in exc c14n way */


  {
      struct zx_xa_CombinerParameter_s* e;
      struct zx_xa_CombinerParameter_s* en;
      struct zx_xa_CombinerParameter_s* enn;
      for (enn = 0, e = x->CombinerParameter; e; e = (struct zx_xa_CombinerParameter_s*)e->gg.g.n) {
	  en = zx_DEEP_CLONE_xa_CombinerParameter(c, e, dup_strs);
	  if (!enn)
	      x->CombinerParameter = en;
	  else
	      enn->gg.g.n = &en->gg.g;
	  enn = en;
      }
  }

  return x;
}

/* FUNC(zx_WALK_SO_xa_CombinerParameters) */

/* Depth first traversal of the tree in either schema order or the wire order. */
 
int zx_WALK_SO_xa_CombinerParameters(struct zx_ctx* c, struct zx_xa_CombinerParameters_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
{
  int ret = callback(&x->gg.g, ctx);
  if (ret)
    return ret;
  
  /* *** deal with xmlns specifications in exc c14n way */


  
  ret = zx_walk_so_unknown_attributes(c, &x->gg, ctx, callback); 
  if (ret)
    return ret;

  {
      struct zx_xa_CombinerParameter_s* e;
      for (e = x->CombinerParameter; e; e = (struct zx_xa_CombinerParameter_s*)e->gg.g.n) {
	  ret = zx_WALK_SO_xa_CombinerParameter(c, e, ctx, callback);
	  if (ret)
	      return ret;
      }
  }

  
  return zx_walk_so_unknown_elems_and_content(c, &x->gg, ctx, callback);
}

/* FUNC(zx_WALK_WO_xa_CombinerParameters) */

int zx_WALK_WO_xa_CombinerParameters(struct zx_ctx* c, struct zx_xa_CombinerParameters_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
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

#define EL_NAME   xa_Condition
#define EL_STRUCT zx_xa_Condition_s
#define EL_NS     xa
#define EL_TAG    Condition

/* FUNC(zx_FREE_xa_Condition) */

/* Depth first traversal of data structure to free it and its subelements. Simple
 * strings are handled as a special case according to the free_strs flag. This
 * is useful if the strings point to underlying data from the wire that was
 * allocated differently. */

/* Called by: */
void zx_FREE_xa_Condition(struct zx_ctx* c, struct zx_xa_Condition_s* x, int free_strs)
{
  /* *** deal with xmlns specifications in exc c14n way */


  zx_free_simple_elems(c, x->Expression, free_strs);


  zx_free_elem_common(c, &x->gg, free_strs); 
}

/* FUNC(zx_NEW_xa_Condition) */

/* Trivial allocator/constructor for the datatype. */

/* Called by: */
struct zx_xa_Condition_s* zx_NEW_xa_Condition(struct zx_ctx* c)
{
  struct zx_xa_Condition_s* x = ZX_ZALLOC(c, struct zx_xa_Condition_s);
  x->gg.g.tok = zx_xa_Condition_ELEM;
  return x;
}

#ifdef ZX_ENA_AUX

/* FUNC(zx_DUP_STRS_xa_Condition) */

/* Depth first traversal of data structure to copy its simple strings
 * to memory allocated from the memory allocator. The decoder will
 * use the underlying wireprotocol PDU buffer for strings, i.e.
 * strings are not copied - they point to the real data. If the
 * datastructure needs to outlast the protocol data or needs a different
 * memory allocation strategy, you need to call this function.  */

/* Called by: */
void zx_DUP_STRS_xa_Condition(struct zx_ctx* c, struct zx_xa_Condition_s* x)
{
  zx_dup_strs_common(c, &x->gg);
  /* *** deal with xmlns specifications in exc c14n way */


  zx_dup_strs_simple_elems(c, x->Expression);

}

/* FUNC(zx_DEEP_CLONE_xa_Condition) */

/* Depth first traversal of data structure to clone it and its sublements.
 * The simple strings are handled as a special case according to dup_strs flag. */

/* Called by: */
struct zx_xa_Condition_s* zx_DEEP_CLONE_xa_Condition(struct zx_ctx* c, struct zx_xa_Condition_s* x, int dup_strs)
{
  x = (struct zx_xa_Condition_s*)zx_clone_elem_common(c, &x->gg, sizeof(struct zx_xa_Condition_s), dup_strs);
  /* *** deal with xmlns specifications in exc c14n way */


  x->Expression = zx_deep_clone_simple_elems(c,x->Expression, dup_strs);

  return x;
}

/* FUNC(zx_WALK_SO_xa_Condition) */

/* Depth first traversal of the tree in either schema order or the wire order. */
 
int zx_WALK_SO_xa_Condition(struct zx_ctx* c, struct zx_xa_Condition_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
{
  int ret = callback(&x->gg.g, ctx);
  if (ret)
    return ret;
  
  /* *** deal with xmlns specifications in exc c14n way */


  
  ret = zx_walk_so_unknown_attributes(c, &x->gg, ctx, callback); 
  if (ret)
    return ret;

  ret = zx_walk_so_simple_elems(c, x->Expression, ctx, callback);
  if (ret)
    return ret;

  
  return zx_walk_so_unknown_elems_and_content(c, &x->gg, ctx, callback);
}

/* FUNC(zx_WALK_WO_xa_Condition) */

int zx_WALK_WO_xa_Condition(struct zx_ctx* c, struct zx_xa_Condition_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
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

#define EL_NAME   xa_Environment
#define EL_STRUCT zx_xa_Environment_s
#define EL_NS     xa
#define EL_TAG    Environment

/* FUNC(zx_FREE_xa_Environment) */

/* Depth first traversal of data structure to free it and its subelements. Simple
 * strings are handled as a special case according to the free_strs flag. This
 * is useful if the strings point to underlying data from the wire that was
 * allocated differently. */

/* Called by: */
void zx_FREE_xa_Environment(struct zx_ctx* c, struct zx_xa_Environment_s* x, int free_strs)
{
  /* *** deal with xmlns specifications in exc c14n way */


  {
      struct zx_xa_EnvironmentMatch_s* e;
      struct zx_xa_EnvironmentMatch_s* en;
      for (e = x->EnvironmentMatch; e; e = en) {
	  en = (struct zx_xa_EnvironmentMatch_s*)e->gg.g.n;
	  zx_FREE_xa_EnvironmentMatch(c, e, free_strs);
      }
  }


  zx_free_elem_common(c, &x->gg, free_strs); 
}

/* FUNC(zx_NEW_xa_Environment) */

/* Trivial allocator/constructor for the datatype. */

/* Called by: */
struct zx_xa_Environment_s* zx_NEW_xa_Environment(struct zx_ctx* c)
{
  struct zx_xa_Environment_s* x = ZX_ZALLOC(c, struct zx_xa_Environment_s);
  x->gg.g.tok = zx_xa_Environment_ELEM;
  return x;
}

#ifdef ZX_ENA_AUX

/* FUNC(zx_DUP_STRS_xa_Environment) */

/* Depth first traversal of data structure to copy its simple strings
 * to memory allocated from the memory allocator. The decoder will
 * use the underlying wireprotocol PDU buffer for strings, i.e.
 * strings are not copied - they point to the real data. If the
 * datastructure needs to outlast the protocol data or needs a different
 * memory allocation strategy, you need to call this function.  */

/* Called by: */
void zx_DUP_STRS_xa_Environment(struct zx_ctx* c, struct zx_xa_Environment_s* x)
{
  zx_dup_strs_common(c, &x->gg);
  /* *** deal with xmlns specifications in exc c14n way */


  {
      struct zx_xa_EnvironmentMatch_s* e;
      for (e = x->EnvironmentMatch; e; e = (struct zx_xa_EnvironmentMatch_s*)e->gg.g.n)
	  zx_DUP_STRS_xa_EnvironmentMatch(c, e);
  }

}

/* FUNC(zx_DEEP_CLONE_xa_Environment) */

/* Depth first traversal of data structure to clone it and its sublements.
 * The simple strings are handled as a special case according to dup_strs flag. */

/* Called by: */
struct zx_xa_Environment_s* zx_DEEP_CLONE_xa_Environment(struct zx_ctx* c, struct zx_xa_Environment_s* x, int dup_strs)
{
  x = (struct zx_xa_Environment_s*)zx_clone_elem_common(c, &x->gg, sizeof(struct zx_xa_Environment_s), dup_strs);
  /* *** deal with xmlns specifications in exc c14n way */


  {
      struct zx_xa_EnvironmentMatch_s* e;
      struct zx_xa_EnvironmentMatch_s* en;
      struct zx_xa_EnvironmentMatch_s* enn;
      for (enn = 0, e = x->EnvironmentMatch; e; e = (struct zx_xa_EnvironmentMatch_s*)e->gg.g.n) {
	  en = zx_DEEP_CLONE_xa_EnvironmentMatch(c, e, dup_strs);
	  if (!enn)
	      x->EnvironmentMatch = en;
	  else
	      enn->gg.g.n = &en->gg.g;
	  enn = en;
      }
  }

  return x;
}

/* FUNC(zx_WALK_SO_xa_Environment) */

/* Depth first traversal of the tree in either schema order or the wire order. */
 
int zx_WALK_SO_xa_Environment(struct zx_ctx* c, struct zx_xa_Environment_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
{
  int ret = callback(&x->gg.g, ctx);
  if (ret)
    return ret;
  
  /* *** deal with xmlns specifications in exc c14n way */


  
  ret = zx_walk_so_unknown_attributes(c, &x->gg, ctx, callback); 
  if (ret)
    return ret;

  {
      struct zx_xa_EnvironmentMatch_s* e;
      for (e = x->EnvironmentMatch; e; e = (struct zx_xa_EnvironmentMatch_s*)e->gg.g.n) {
	  ret = zx_WALK_SO_xa_EnvironmentMatch(c, e, ctx, callback);
	  if (ret)
	      return ret;
      }
  }

  
  return zx_walk_so_unknown_elems_and_content(c, &x->gg, ctx, callback);
}

/* FUNC(zx_WALK_WO_xa_Environment) */

int zx_WALK_WO_xa_Environment(struct zx_ctx* c, struct zx_xa_Environment_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
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

#define EL_NAME   xa_EnvironmentAttributeDesignator
#define EL_STRUCT zx_xa_EnvironmentAttributeDesignator_s
#define EL_NS     xa
#define EL_TAG    EnvironmentAttributeDesignator

/* FUNC(zx_FREE_xa_EnvironmentAttributeDesignator) */

/* Depth first traversal of data structure to free it and its subelements. Simple
 * strings are handled as a special case according to the free_strs flag. This
 * is useful if the strings point to underlying data from the wire that was
 * allocated differently. */

/* Called by: */
void zx_FREE_xa_EnvironmentAttributeDesignator(struct zx_ctx* c, struct zx_xa_EnvironmentAttributeDesignator_s* x, int free_strs)
{
  /* *** deal with xmlns specifications in exc c14n way */

  zx_free_attr(c, x->AttributeId, free_strs);
  zx_free_attr(c, x->DataType, free_strs);
  zx_free_attr(c, x->Issuer, free_strs);
  zx_free_attr(c, x->MustBePresent, free_strs);



  zx_free_elem_common(c, &x->gg, free_strs); 
}

/* FUNC(zx_NEW_xa_EnvironmentAttributeDesignator) */

/* Trivial allocator/constructor for the datatype. */

/* Called by: */
struct zx_xa_EnvironmentAttributeDesignator_s* zx_NEW_xa_EnvironmentAttributeDesignator(struct zx_ctx* c)
{
  struct zx_xa_EnvironmentAttributeDesignator_s* x = ZX_ZALLOC(c, struct zx_xa_EnvironmentAttributeDesignator_s);
  x->gg.g.tok = zx_xa_EnvironmentAttributeDesignator_ELEM;
  return x;
}

#ifdef ZX_ENA_AUX

/* FUNC(zx_DUP_STRS_xa_EnvironmentAttributeDesignator) */

/* Depth first traversal of data structure to copy its simple strings
 * to memory allocated from the memory allocator. The decoder will
 * use the underlying wireprotocol PDU buffer for strings, i.e.
 * strings are not copied - they point to the real data. If the
 * datastructure needs to outlast the protocol data or needs a different
 * memory allocation strategy, you need to call this function.  */

/* Called by: */
void zx_DUP_STRS_xa_EnvironmentAttributeDesignator(struct zx_ctx* c, struct zx_xa_EnvironmentAttributeDesignator_s* x)
{
  zx_dup_strs_common(c, &x->gg);
  /* *** deal with xmlns specifications in exc c14n way */

  zx_dup_attr(c, x->AttributeId);
  zx_dup_attr(c, x->DataType);
  zx_dup_attr(c, x->Issuer);
  zx_dup_attr(c, x->MustBePresent);


}

/* FUNC(zx_DEEP_CLONE_xa_EnvironmentAttributeDesignator) */

/* Depth first traversal of data structure to clone it and its sublements.
 * The simple strings are handled as a special case according to dup_strs flag. */

/* Called by: */
struct zx_xa_EnvironmentAttributeDesignator_s* zx_DEEP_CLONE_xa_EnvironmentAttributeDesignator(struct zx_ctx* c, struct zx_xa_EnvironmentAttributeDesignator_s* x, int dup_strs)
{
  x = (struct zx_xa_EnvironmentAttributeDesignator_s*)zx_clone_elem_common(c, &x->gg, sizeof(struct zx_xa_EnvironmentAttributeDesignator_s), dup_strs);
  /* *** deal with xmlns specifications in exc c14n way */

  x->AttributeId = zx_clone_attr(c, x->AttributeId);
  x->DataType = zx_clone_attr(c, x->DataType);
  x->Issuer = zx_clone_attr(c, x->Issuer);
  x->MustBePresent = zx_clone_attr(c, x->MustBePresent);


  return x;
}

/* FUNC(zx_WALK_SO_xa_EnvironmentAttributeDesignator) */

/* Depth first traversal of the tree in either schema order or the wire order. */
 
int zx_WALK_SO_xa_EnvironmentAttributeDesignator(struct zx_ctx* c, struct zx_xa_EnvironmentAttributeDesignator_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
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

/* FUNC(zx_WALK_WO_xa_EnvironmentAttributeDesignator) */

int zx_WALK_WO_xa_EnvironmentAttributeDesignator(struct zx_ctx* c, struct zx_xa_EnvironmentAttributeDesignator_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
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

#define EL_NAME   xa_EnvironmentMatch
#define EL_STRUCT zx_xa_EnvironmentMatch_s
#define EL_NS     xa
#define EL_TAG    EnvironmentMatch

/* FUNC(zx_FREE_xa_EnvironmentMatch) */

/* Depth first traversal of data structure to free it and its subelements. Simple
 * strings are handled as a special case according to the free_strs flag. This
 * is useful if the strings point to underlying data from the wire that was
 * allocated differently. */

/* Called by: */
void zx_FREE_xa_EnvironmentMatch(struct zx_ctx* c, struct zx_xa_EnvironmentMatch_s* x, int free_strs)
{
  /* *** deal with xmlns specifications in exc c14n way */

  zx_free_attr(c, x->MatchId, free_strs);

  {
      struct zx_xa_AttributeValue_s* e;
      struct zx_xa_AttributeValue_s* en;
      for (e = x->AttributeValue; e; e = en) {
	  en = (struct zx_xa_AttributeValue_s*)e->gg.g.n;
	  zx_FREE_xa_AttributeValue(c, e, free_strs);
      }
  }
  {
      struct zx_xa_EnvironmentAttributeDesignator_s* e;
      struct zx_xa_EnvironmentAttributeDesignator_s* en;
      for (e = x->EnvironmentAttributeDesignator; e; e = en) {
	  en = (struct zx_xa_EnvironmentAttributeDesignator_s*)e->gg.g.n;
	  zx_FREE_xa_EnvironmentAttributeDesignator(c, e, free_strs);
      }
  }
  {
      struct zx_xa_AttributeSelector_s* e;
      struct zx_xa_AttributeSelector_s* en;
      for (e = x->AttributeSelector; e; e = en) {
	  en = (struct zx_xa_AttributeSelector_s*)e->gg.g.n;
	  zx_FREE_xa_AttributeSelector(c, e, free_strs);
      }
  }


  zx_free_elem_common(c, &x->gg, free_strs); 
}

/* FUNC(zx_NEW_xa_EnvironmentMatch) */

/* Trivial allocator/constructor for the datatype. */

/* Called by: */
struct zx_xa_EnvironmentMatch_s* zx_NEW_xa_EnvironmentMatch(struct zx_ctx* c)
{
  struct zx_xa_EnvironmentMatch_s* x = ZX_ZALLOC(c, struct zx_xa_EnvironmentMatch_s);
  x->gg.g.tok = zx_xa_EnvironmentMatch_ELEM;
  return x;
}

#ifdef ZX_ENA_AUX

/* FUNC(zx_DUP_STRS_xa_EnvironmentMatch) */

/* Depth first traversal of data structure to copy its simple strings
 * to memory allocated from the memory allocator. The decoder will
 * use the underlying wireprotocol PDU buffer for strings, i.e.
 * strings are not copied - they point to the real data. If the
 * datastructure needs to outlast the protocol data or needs a different
 * memory allocation strategy, you need to call this function.  */

/* Called by: */
void zx_DUP_STRS_xa_EnvironmentMatch(struct zx_ctx* c, struct zx_xa_EnvironmentMatch_s* x)
{
  zx_dup_strs_common(c, &x->gg);
  /* *** deal with xmlns specifications in exc c14n way */

  zx_dup_attr(c, x->MatchId);

  {
      struct zx_xa_AttributeValue_s* e;
      for (e = x->AttributeValue; e; e = (struct zx_xa_AttributeValue_s*)e->gg.g.n)
	  zx_DUP_STRS_xa_AttributeValue(c, e);
  }
  {
      struct zx_xa_EnvironmentAttributeDesignator_s* e;
      for (e = x->EnvironmentAttributeDesignator; e; e = (struct zx_xa_EnvironmentAttributeDesignator_s*)e->gg.g.n)
	  zx_DUP_STRS_xa_EnvironmentAttributeDesignator(c, e);
  }
  {
      struct zx_xa_AttributeSelector_s* e;
      for (e = x->AttributeSelector; e; e = (struct zx_xa_AttributeSelector_s*)e->gg.g.n)
	  zx_DUP_STRS_xa_AttributeSelector(c, e);
  }

}

/* FUNC(zx_DEEP_CLONE_xa_EnvironmentMatch) */

/* Depth first traversal of data structure to clone it and its sublements.
 * The simple strings are handled as a special case according to dup_strs flag. */

/* Called by: */
struct zx_xa_EnvironmentMatch_s* zx_DEEP_CLONE_xa_EnvironmentMatch(struct zx_ctx* c, struct zx_xa_EnvironmentMatch_s* x, int dup_strs)
{
  x = (struct zx_xa_EnvironmentMatch_s*)zx_clone_elem_common(c, &x->gg, sizeof(struct zx_xa_EnvironmentMatch_s), dup_strs);
  /* *** deal with xmlns specifications in exc c14n way */

  x->MatchId = zx_clone_attr(c, x->MatchId);

  {
      struct zx_xa_AttributeValue_s* e;
      struct zx_xa_AttributeValue_s* en;
      struct zx_xa_AttributeValue_s* enn;
      for (enn = 0, e = x->AttributeValue; e; e = (struct zx_xa_AttributeValue_s*)e->gg.g.n) {
	  en = zx_DEEP_CLONE_xa_AttributeValue(c, e, dup_strs);
	  if (!enn)
	      x->AttributeValue = en;
	  else
	      enn->gg.g.n = &en->gg.g;
	  enn = en;
      }
  }
  {
      struct zx_xa_EnvironmentAttributeDesignator_s* e;
      struct zx_xa_EnvironmentAttributeDesignator_s* en;
      struct zx_xa_EnvironmentAttributeDesignator_s* enn;
      for (enn = 0, e = x->EnvironmentAttributeDesignator; e; e = (struct zx_xa_EnvironmentAttributeDesignator_s*)e->gg.g.n) {
	  en = zx_DEEP_CLONE_xa_EnvironmentAttributeDesignator(c, e, dup_strs);
	  if (!enn)
	      x->EnvironmentAttributeDesignator = en;
	  else
	      enn->gg.g.n = &en->gg.g;
	  enn = en;
      }
  }
  {
      struct zx_xa_AttributeSelector_s* e;
      struct zx_xa_AttributeSelector_s* en;
      struct zx_xa_AttributeSelector_s* enn;
      for (enn = 0, e = x->AttributeSelector; e; e = (struct zx_xa_AttributeSelector_s*)e->gg.g.n) {
	  en = zx_DEEP_CLONE_xa_AttributeSelector(c, e, dup_strs);
	  if (!enn)
	      x->AttributeSelector = en;
	  else
	      enn->gg.g.n = &en->gg.g;
	  enn = en;
      }
  }

  return x;
}

/* FUNC(zx_WALK_SO_xa_EnvironmentMatch) */

/* Depth first traversal of the tree in either schema order or the wire order. */
 
int zx_WALK_SO_xa_EnvironmentMatch(struct zx_ctx* c, struct zx_xa_EnvironmentMatch_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
{
  int ret = callback(&x->gg.g, ctx);
  if (ret)
    return ret;
  
  /* *** deal with xmlns specifications in exc c14n way */


  
  ret = zx_walk_so_unknown_attributes(c, &x->gg, ctx, callback); 
  if (ret)
    return ret;

  {
      struct zx_xa_AttributeValue_s* e;
      for (e = x->AttributeValue; e; e = (struct zx_xa_AttributeValue_s*)e->gg.g.n) {
	  ret = zx_WALK_SO_xa_AttributeValue(c, e, ctx, callback);
	  if (ret)
	      return ret;
      }
  }
  {
      struct zx_xa_EnvironmentAttributeDesignator_s* e;
      for (e = x->EnvironmentAttributeDesignator; e; e = (struct zx_xa_EnvironmentAttributeDesignator_s*)e->gg.g.n) {
	  ret = zx_WALK_SO_xa_EnvironmentAttributeDesignator(c, e, ctx, callback);
	  if (ret)
	      return ret;
      }
  }
  {
      struct zx_xa_AttributeSelector_s* e;
      for (e = x->AttributeSelector; e; e = (struct zx_xa_AttributeSelector_s*)e->gg.g.n) {
	  ret = zx_WALK_SO_xa_AttributeSelector(c, e, ctx, callback);
	  if (ret)
	      return ret;
      }
  }

  
  return zx_walk_so_unknown_elems_and_content(c, &x->gg, ctx, callback);
}

/* FUNC(zx_WALK_WO_xa_EnvironmentMatch) */

int zx_WALK_WO_xa_EnvironmentMatch(struct zx_ctx* c, struct zx_xa_EnvironmentMatch_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
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

#define EL_NAME   xa_Environments
#define EL_STRUCT zx_xa_Environments_s
#define EL_NS     xa
#define EL_TAG    Environments

/* FUNC(zx_FREE_xa_Environments) */

/* Depth first traversal of data structure to free it and its subelements. Simple
 * strings are handled as a special case according to the free_strs flag. This
 * is useful if the strings point to underlying data from the wire that was
 * allocated differently. */

/* Called by: */
void zx_FREE_xa_Environments(struct zx_ctx* c, struct zx_xa_Environments_s* x, int free_strs)
{
  /* *** deal with xmlns specifications in exc c14n way */


  {
      struct zx_xa_Environment_s* e;
      struct zx_xa_Environment_s* en;
      for (e = x->Environment; e; e = en) {
	  en = (struct zx_xa_Environment_s*)e->gg.g.n;
	  zx_FREE_xa_Environment(c, e, free_strs);
      }
  }


  zx_free_elem_common(c, &x->gg, free_strs); 
}

/* FUNC(zx_NEW_xa_Environments) */

/* Trivial allocator/constructor for the datatype. */

/* Called by: */
struct zx_xa_Environments_s* zx_NEW_xa_Environments(struct zx_ctx* c)
{
  struct zx_xa_Environments_s* x = ZX_ZALLOC(c, struct zx_xa_Environments_s);
  x->gg.g.tok = zx_xa_Environments_ELEM;
  return x;
}

#ifdef ZX_ENA_AUX

/* FUNC(zx_DUP_STRS_xa_Environments) */

/* Depth first traversal of data structure to copy its simple strings
 * to memory allocated from the memory allocator. The decoder will
 * use the underlying wireprotocol PDU buffer for strings, i.e.
 * strings are not copied - they point to the real data. If the
 * datastructure needs to outlast the protocol data or needs a different
 * memory allocation strategy, you need to call this function.  */

/* Called by: */
void zx_DUP_STRS_xa_Environments(struct zx_ctx* c, struct zx_xa_Environments_s* x)
{
  zx_dup_strs_common(c, &x->gg);
  /* *** deal with xmlns specifications in exc c14n way */


  {
      struct zx_xa_Environment_s* e;
      for (e = x->Environment; e; e = (struct zx_xa_Environment_s*)e->gg.g.n)
	  zx_DUP_STRS_xa_Environment(c, e);
  }

}

/* FUNC(zx_DEEP_CLONE_xa_Environments) */

/* Depth first traversal of data structure to clone it and its sublements.
 * The simple strings are handled as a special case according to dup_strs flag. */

/* Called by: */
struct zx_xa_Environments_s* zx_DEEP_CLONE_xa_Environments(struct zx_ctx* c, struct zx_xa_Environments_s* x, int dup_strs)
{
  x = (struct zx_xa_Environments_s*)zx_clone_elem_common(c, &x->gg, sizeof(struct zx_xa_Environments_s), dup_strs);
  /* *** deal with xmlns specifications in exc c14n way */


  {
      struct zx_xa_Environment_s* e;
      struct zx_xa_Environment_s* en;
      struct zx_xa_Environment_s* enn;
      for (enn = 0, e = x->Environment; e; e = (struct zx_xa_Environment_s*)e->gg.g.n) {
	  en = zx_DEEP_CLONE_xa_Environment(c, e, dup_strs);
	  if (!enn)
	      x->Environment = en;
	  else
	      enn->gg.g.n = &en->gg.g;
	  enn = en;
      }
  }

  return x;
}

/* FUNC(zx_WALK_SO_xa_Environments) */

/* Depth first traversal of the tree in either schema order or the wire order. */
 
int zx_WALK_SO_xa_Environments(struct zx_ctx* c, struct zx_xa_Environments_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
{
  int ret = callback(&x->gg.g, ctx);
  if (ret)
    return ret;
  
  /* *** deal with xmlns specifications in exc c14n way */


  
  ret = zx_walk_so_unknown_attributes(c, &x->gg, ctx, callback); 
  if (ret)
    return ret;

  {
      struct zx_xa_Environment_s* e;
      for (e = x->Environment; e; e = (struct zx_xa_Environment_s*)e->gg.g.n) {
	  ret = zx_WALK_SO_xa_Environment(c, e, ctx, callback);
	  if (ret)
	      return ret;
      }
  }

  
  return zx_walk_so_unknown_elems_and_content(c, &x->gg, ctx, callback);
}

/* FUNC(zx_WALK_WO_xa_Environments) */

int zx_WALK_WO_xa_Environments(struct zx_ctx* c, struct zx_xa_Environments_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
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

#define EL_NAME   xa_Function
#define EL_STRUCT zx_xa_Function_s
#define EL_NS     xa
#define EL_TAG    Function

/* FUNC(zx_FREE_xa_Function) */

/* Depth first traversal of data structure to free it and its subelements. Simple
 * strings are handled as a special case according to the free_strs flag. This
 * is useful if the strings point to underlying data from the wire that was
 * allocated differently. */

/* Called by: */
void zx_FREE_xa_Function(struct zx_ctx* c, struct zx_xa_Function_s* x, int free_strs)
{
  /* *** deal with xmlns specifications in exc c14n way */

  zx_free_attr(c, x->FunctionId, free_strs);



  zx_free_elem_common(c, &x->gg, free_strs); 
}

/* FUNC(zx_NEW_xa_Function) */

/* Trivial allocator/constructor for the datatype. */

/* Called by: */
struct zx_xa_Function_s* zx_NEW_xa_Function(struct zx_ctx* c)
{
  struct zx_xa_Function_s* x = ZX_ZALLOC(c, struct zx_xa_Function_s);
  x->gg.g.tok = zx_xa_Function_ELEM;
  return x;
}

#ifdef ZX_ENA_AUX

/* FUNC(zx_DUP_STRS_xa_Function) */

/* Depth first traversal of data structure to copy its simple strings
 * to memory allocated from the memory allocator. The decoder will
 * use the underlying wireprotocol PDU buffer for strings, i.e.
 * strings are not copied - they point to the real data. If the
 * datastructure needs to outlast the protocol data or needs a different
 * memory allocation strategy, you need to call this function.  */

/* Called by: */
void zx_DUP_STRS_xa_Function(struct zx_ctx* c, struct zx_xa_Function_s* x)
{
  zx_dup_strs_common(c, &x->gg);
  /* *** deal with xmlns specifications in exc c14n way */

  zx_dup_attr(c, x->FunctionId);


}

/* FUNC(zx_DEEP_CLONE_xa_Function) */

/* Depth first traversal of data structure to clone it and its sublements.
 * The simple strings are handled as a special case according to dup_strs flag. */

/* Called by: */
struct zx_xa_Function_s* zx_DEEP_CLONE_xa_Function(struct zx_ctx* c, struct zx_xa_Function_s* x, int dup_strs)
{
  x = (struct zx_xa_Function_s*)zx_clone_elem_common(c, &x->gg, sizeof(struct zx_xa_Function_s), dup_strs);
  /* *** deal with xmlns specifications in exc c14n way */

  x->FunctionId = zx_clone_attr(c, x->FunctionId);


  return x;
}

/* FUNC(zx_WALK_SO_xa_Function) */

/* Depth first traversal of the tree in either schema order or the wire order. */
 
int zx_WALK_SO_xa_Function(struct zx_ctx* c, struct zx_xa_Function_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
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

/* FUNC(zx_WALK_WO_xa_Function) */

int zx_WALK_WO_xa_Function(struct zx_ctx* c, struct zx_xa_Function_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
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

#define EL_NAME   xa_Obligation
#define EL_STRUCT zx_xa_Obligation_s
#define EL_NS     xa
#define EL_TAG    Obligation

/* FUNC(zx_FREE_xa_Obligation) */

/* Depth first traversal of data structure to free it and its subelements. Simple
 * strings are handled as a special case according to the free_strs flag. This
 * is useful if the strings point to underlying data from the wire that was
 * allocated differently. */

/* Called by: */
void zx_FREE_xa_Obligation(struct zx_ctx* c, struct zx_xa_Obligation_s* x, int free_strs)
{
  /* *** deal with xmlns specifications in exc c14n way */

  zx_free_attr(c, x->FulfillOn, free_strs);
  zx_free_attr(c, x->ObligationId, free_strs);

  {
      struct zx_xa_AttributeAssignment_s* e;
      struct zx_xa_AttributeAssignment_s* en;
      for (e = x->AttributeAssignment; e; e = en) {
	  en = (struct zx_xa_AttributeAssignment_s*)e->gg.g.n;
	  zx_FREE_xa_AttributeAssignment(c, e, free_strs);
      }
  }


  zx_free_elem_common(c, &x->gg, free_strs); 
}

/* FUNC(zx_NEW_xa_Obligation) */

/* Trivial allocator/constructor for the datatype. */

/* Called by: */
struct zx_xa_Obligation_s* zx_NEW_xa_Obligation(struct zx_ctx* c)
{
  struct zx_xa_Obligation_s* x = ZX_ZALLOC(c, struct zx_xa_Obligation_s);
  x->gg.g.tok = zx_xa_Obligation_ELEM;
  return x;
}

#ifdef ZX_ENA_AUX

/* FUNC(zx_DUP_STRS_xa_Obligation) */

/* Depth first traversal of data structure to copy its simple strings
 * to memory allocated from the memory allocator. The decoder will
 * use the underlying wireprotocol PDU buffer for strings, i.e.
 * strings are not copied - they point to the real data. If the
 * datastructure needs to outlast the protocol data or needs a different
 * memory allocation strategy, you need to call this function.  */

/* Called by: */
void zx_DUP_STRS_xa_Obligation(struct zx_ctx* c, struct zx_xa_Obligation_s* x)
{
  zx_dup_strs_common(c, &x->gg);
  /* *** deal with xmlns specifications in exc c14n way */

  zx_dup_attr(c, x->FulfillOn);
  zx_dup_attr(c, x->ObligationId);

  {
      struct zx_xa_AttributeAssignment_s* e;
      for (e = x->AttributeAssignment; e; e = (struct zx_xa_AttributeAssignment_s*)e->gg.g.n)
	  zx_DUP_STRS_xa_AttributeAssignment(c, e);
  }

}

/* FUNC(zx_DEEP_CLONE_xa_Obligation) */

/* Depth first traversal of data structure to clone it and its sublements.
 * The simple strings are handled as a special case according to dup_strs flag. */

/* Called by: */
struct zx_xa_Obligation_s* zx_DEEP_CLONE_xa_Obligation(struct zx_ctx* c, struct zx_xa_Obligation_s* x, int dup_strs)
{
  x = (struct zx_xa_Obligation_s*)zx_clone_elem_common(c, &x->gg, sizeof(struct zx_xa_Obligation_s), dup_strs);
  /* *** deal with xmlns specifications in exc c14n way */

  x->FulfillOn = zx_clone_attr(c, x->FulfillOn);
  x->ObligationId = zx_clone_attr(c, x->ObligationId);

  {
      struct zx_xa_AttributeAssignment_s* e;
      struct zx_xa_AttributeAssignment_s* en;
      struct zx_xa_AttributeAssignment_s* enn;
      for (enn = 0, e = x->AttributeAssignment; e; e = (struct zx_xa_AttributeAssignment_s*)e->gg.g.n) {
	  en = zx_DEEP_CLONE_xa_AttributeAssignment(c, e, dup_strs);
	  if (!enn)
	      x->AttributeAssignment = en;
	  else
	      enn->gg.g.n = &en->gg.g;
	  enn = en;
      }
  }

  return x;
}

/* FUNC(zx_WALK_SO_xa_Obligation) */

/* Depth first traversal of the tree in either schema order or the wire order. */
 
int zx_WALK_SO_xa_Obligation(struct zx_ctx* c, struct zx_xa_Obligation_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
{
  int ret = callback(&x->gg.g, ctx);
  if (ret)
    return ret;
  
  /* *** deal with xmlns specifications in exc c14n way */


  
  ret = zx_walk_so_unknown_attributes(c, &x->gg, ctx, callback); 
  if (ret)
    return ret;

  {
      struct zx_xa_AttributeAssignment_s* e;
      for (e = x->AttributeAssignment; e; e = (struct zx_xa_AttributeAssignment_s*)e->gg.g.n) {
	  ret = zx_WALK_SO_xa_AttributeAssignment(c, e, ctx, callback);
	  if (ret)
	      return ret;
      }
  }

  
  return zx_walk_so_unknown_elems_and_content(c, &x->gg, ctx, callback);
}

/* FUNC(zx_WALK_WO_xa_Obligation) */

int zx_WALK_WO_xa_Obligation(struct zx_ctx* c, struct zx_xa_Obligation_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
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

#define EL_NAME   xa_Obligations
#define EL_STRUCT zx_xa_Obligations_s
#define EL_NS     xa
#define EL_TAG    Obligations

/* FUNC(zx_FREE_xa_Obligations) */

/* Depth first traversal of data structure to free it and its subelements. Simple
 * strings are handled as a special case according to the free_strs flag. This
 * is useful if the strings point to underlying data from the wire that was
 * allocated differently. */

/* Called by: */
void zx_FREE_xa_Obligations(struct zx_ctx* c, struct zx_xa_Obligations_s* x, int free_strs)
{
  /* *** deal with xmlns specifications in exc c14n way */


  {
      struct zx_xa_Obligation_s* e;
      struct zx_xa_Obligation_s* en;
      for (e = x->Obligation; e; e = en) {
	  en = (struct zx_xa_Obligation_s*)e->gg.g.n;
	  zx_FREE_xa_Obligation(c, e, free_strs);
      }
  }


  zx_free_elem_common(c, &x->gg, free_strs); 
}

/* FUNC(zx_NEW_xa_Obligations) */

/* Trivial allocator/constructor for the datatype. */

/* Called by: */
struct zx_xa_Obligations_s* zx_NEW_xa_Obligations(struct zx_ctx* c)
{
  struct zx_xa_Obligations_s* x = ZX_ZALLOC(c, struct zx_xa_Obligations_s);
  x->gg.g.tok = zx_xa_Obligations_ELEM;
  return x;
}

#ifdef ZX_ENA_AUX

/* FUNC(zx_DUP_STRS_xa_Obligations) */

/* Depth first traversal of data structure to copy its simple strings
 * to memory allocated from the memory allocator. The decoder will
 * use the underlying wireprotocol PDU buffer for strings, i.e.
 * strings are not copied - they point to the real data. If the
 * datastructure needs to outlast the protocol data or needs a different
 * memory allocation strategy, you need to call this function.  */

/* Called by: */
void zx_DUP_STRS_xa_Obligations(struct zx_ctx* c, struct zx_xa_Obligations_s* x)
{
  zx_dup_strs_common(c, &x->gg);
  /* *** deal with xmlns specifications in exc c14n way */


  {
      struct zx_xa_Obligation_s* e;
      for (e = x->Obligation; e; e = (struct zx_xa_Obligation_s*)e->gg.g.n)
	  zx_DUP_STRS_xa_Obligation(c, e);
  }

}

/* FUNC(zx_DEEP_CLONE_xa_Obligations) */

/* Depth first traversal of data structure to clone it and its sublements.
 * The simple strings are handled as a special case according to dup_strs flag. */

/* Called by: */
struct zx_xa_Obligations_s* zx_DEEP_CLONE_xa_Obligations(struct zx_ctx* c, struct zx_xa_Obligations_s* x, int dup_strs)
{
  x = (struct zx_xa_Obligations_s*)zx_clone_elem_common(c, &x->gg, sizeof(struct zx_xa_Obligations_s), dup_strs);
  /* *** deal with xmlns specifications in exc c14n way */


  {
      struct zx_xa_Obligation_s* e;
      struct zx_xa_Obligation_s* en;
      struct zx_xa_Obligation_s* enn;
      for (enn = 0, e = x->Obligation; e; e = (struct zx_xa_Obligation_s*)e->gg.g.n) {
	  en = zx_DEEP_CLONE_xa_Obligation(c, e, dup_strs);
	  if (!enn)
	      x->Obligation = en;
	  else
	      enn->gg.g.n = &en->gg.g;
	  enn = en;
      }
  }

  return x;
}

/* FUNC(zx_WALK_SO_xa_Obligations) */

/* Depth first traversal of the tree in either schema order or the wire order. */
 
int zx_WALK_SO_xa_Obligations(struct zx_ctx* c, struct zx_xa_Obligations_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
{
  int ret = callback(&x->gg.g, ctx);
  if (ret)
    return ret;
  
  /* *** deal with xmlns specifications in exc c14n way */


  
  ret = zx_walk_so_unknown_attributes(c, &x->gg, ctx, callback); 
  if (ret)
    return ret;

  {
      struct zx_xa_Obligation_s* e;
      for (e = x->Obligation; e; e = (struct zx_xa_Obligation_s*)e->gg.g.n) {
	  ret = zx_WALK_SO_xa_Obligation(c, e, ctx, callback);
	  if (ret)
	      return ret;
      }
  }

  
  return zx_walk_so_unknown_elems_and_content(c, &x->gg, ctx, callback);
}

/* FUNC(zx_WALK_WO_xa_Obligations) */

int zx_WALK_WO_xa_Obligations(struct zx_ctx* c, struct zx_xa_Obligations_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
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

#define EL_NAME   xa_Policy
#define EL_STRUCT zx_xa_Policy_s
#define EL_NS     xa
#define EL_TAG    Policy

/* FUNC(zx_FREE_xa_Policy) */

/* Depth first traversal of data structure to free it and its subelements. Simple
 * strings are handled as a special case according to the free_strs flag. This
 * is useful if the strings point to underlying data from the wire that was
 * allocated differently. */

/* Called by: */
void zx_FREE_xa_Policy(struct zx_ctx* c, struct zx_xa_Policy_s* x, int free_strs)
{
  /* *** deal with xmlns specifications in exc c14n way */

  zx_free_attr(c, x->PolicyId, free_strs);
  zx_free_attr(c, x->RuleCombiningAlgId, free_strs);
  zx_free_attr(c, x->Version, free_strs);

  zx_free_simple_elems(c, x->Description, free_strs);
  {
      struct zx_xa_PolicyDefaults_s* e;
      struct zx_xa_PolicyDefaults_s* en;
      for (e = x->PolicyDefaults; e; e = en) {
	  en = (struct zx_xa_PolicyDefaults_s*)e->gg.g.n;
	  zx_FREE_xa_PolicyDefaults(c, e, free_strs);
      }
  }
  {
      struct zx_xa_Target_s* e;
      struct zx_xa_Target_s* en;
      for (e = x->Target; e; e = en) {
	  en = (struct zx_xa_Target_s*)e->gg.g.n;
	  zx_FREE_xa_Target(c, e, free_strs);
      }
  }
  {
      struct zx_xa_CombinerParameters_s* e;
      struct zx_xa_CombinerParameters_s* en;
      for (e = x->CombinerParameters; e; e = en) {
	  en = (struct zx_xa_CombinerParameters_s*)e->gg.g.n;
	  zx_FREE_xa_CombinerParameters(c, e, free_strs);
      }
  }
  {
      struct zx_xa_RuleCombinerParameters_s* e;
      struct zx_xa_RuleCombinerParameters_s* en;
      for (e = x->RuleCombinerParameters; e; e = en) {
	  en = (struct zx_xa_RuleCombinerParameters_s*)e->gg.g.n;
	  zx_FREE_xa_RuleCombinerParameters(c, e, free_strs);
      }
  }
  {
      struct zx_xa_VariableDefinition_s* e;
      struct zx_xa_VariableDefinition_s* en;
      for (e = x->VariableDefinition; e; e = en) {
	  en = (struct zx_xa_VariableDefinition_s*)e->gg.g.n;
	  zx_FREE_xa_VariableDefinition(c, e, free_strs);
      }
  }
  {
      struct zx_xa_Rule_s* e;
      struct zx_xa_Rule_s* en;
      for (e = x->Rule; e; e = en) {
	  en = (struct zx_xa_Rule_s*)e->gg.g.n;
	  zx_FREE_xa_Rule(c, e, free_strs);
      }
  }
  {
      struct zx_xa_Obligations_s* e;
      struct zx_xa_Obligations_s* en;
      for (e = x->Obligations; e; e = en) {
	  en = (struct zx_xa_Obligations_s*)e->gg.g.n;
	  zx_FREE_xa_Obligations(c, e, free_strs);
      }
  }


  zx_free_elem_common(c, &x->gg, free_strs); 
}

/* FUNC(zx_NEW_xa_Policy) */

/* Trivial allocator/constructor for the datatype. */

/* Called by: */
struct zx_xa_Policy_s* zx_NEW_xa_Policy(struct zx_ctx* c)
{
  struct zx_xa_Policy_s* x = ZX_ZALLOC(c, struct zx_xa_Policy_s);
  x->gg.g.tok = zx_xa_Policy_ELEM;
  return x;
}

#ifdef ZX_ENA_AUX

/* FUNC(zx_DUP_STRS_xa_Policy) */

/* Depth first traversal of data structure to copy its simple strings
 * to memory allocated from the memory allocator. The decoder will
 * use the underlying wireprotocol PDU buffer for strings, i.e.
 * strings are not copied - they point to the real data. If the
 * datastructure needs to outlast the protocol data or needs a different
 * memory allocation strategy, you need to call this function.  */

/* Called by: */
void zx_DUP_STRS_xa_Policy(struct zx_ctx* c, struct zx_xa_Policy_s* x)
{
  zx_dup_strs_common(c, &x->gg);
  /* *** deal with xmlns specifications in exc c14n way */

  zx_dup_attr(c, x->PolicyId);
  zx_dup_attr(c, x->RuleCombiningAlgId);
  zx_dup_attr(c, x->Version);

  zx_dup_strs_simple_elems(c, x->Description);
  {
      struct zx_xa_PolicyDefaults_s* e;
      for (e = x->PolicyDefaults; e; e = (struct zx_xa_PolicyDefaults_s*)e->gg.g.n)
	  zx_DUP_STRS_xa_PolicyDefaults(c, e);
  }
  {
      struct zx_xa_Target_s* e;
      for (e = x->Target; e; e = (struct zx_xa_Target_s*)e->gg.g.n)
	  zx_DUP_STRS_xa_Target(c, e);
  }
  {
      struct zx_xa_CombinerParameters_s* e;
      for (e = x->CombinerParameters; e; e = (struct zx_xa_CombinerParameters_s*)e->gg.g.n)
	  zx_DUP_STRS_xa_CombinerParameters(c, e);
  }
  {
      struct zx_xa_RuleCombinerParameters_s* e;
      for (e = x->RuleCombinerParameters; e; e = (struct zx_xa_RuleCombinerParameters_s*)e->gg.g.n)
	  zx_DUP_STRS_xa_RuleCombinerParameters(c, e);
  }
  {
      struct zx_xa_VariableDefinition_s* e;
      for (e = x->VariableDefinition; e; e = (struct zx_xa_VariableDefinition_s*)e->gg.g.n)
	  zx_DUP_STRS_xa_VariableDefinition(c, e);
  }
  {
      struct zx_xa_Rule_s* e;
      for (e = x->Rule; e; e = (struct zx_xa_Rule_s*)e->gg.g.n)
	  zx_DUP_STRS_xa_Rule(c, e);
  }
  {
      struct zx_xa_Obligations_s* e;
      for (e = x->Obligations; e; e = (struct zx_xa_Obligations_s*)e->gg.g.n)
	  zx_DUP_STRS_xa_Obligations(c, e);
  }

}

/* FUNC(zx_DEEP_CLONE_xa_Policy) */

/* Depth first traversal of data structure to clone it and its sublements.
 * The simple strings are handled as a special case according to dup_strs flag. */

/* Called by: */
struct zx_xa_Policy_s* zx_DEEP_CLONE_xa_Policy(struct zx_ctx* c, struct zx_xa_Policy_s* x, int dup_strs)
{
  x = (struct zx_xa_Policy_s*)zx_clone_elem_common(c, &x->gg, sizeof(struct zx_xa_Policy_s), dup_strs);
  /* *** deal with xmlns specifications in exc c14n way */

  x->PolicyId = zx_clone_attr(c, x->PolicyId);
  x->RuleCombiningAlgId = zx_clone_attr(c, x->RuleCombiningAlgId);
  x->Version = zx_clone_attr(c, x->Version);

  x->Description = zx_deep_clone_simple_elems(c,x->Description, dup_strs);
  {
      struct zx_xa_PolicyDefaults_s* e;
      struct zx_xa_PolicyDefaults_s* en;
      struct zx_xa_PolicyDefaults_s* enn;
      for (enn = 0, e = x->PolicyDefaults; e; e = (struct zx_xa_PolicyDefaults_s*)e->gg.g.n) {
	  en = zx_DEEP_CLONE_xa_PolicyDefaults(c, e, dup_strs);
	  if (!enn)
	      x->PolicyDefaults = en;
	  else
	      enn->gg.g.n = &en->gg.g;
	  enn = en;
      }
  }
  {
      struct zx_xa_Target_s* e;
      struct zx_xa_Target_s* en;
      struct zx_xa_Target_s* enn;
      for (enn = 0, e = x->Target; e; e = (struct zx_xa_Target_s*)e->gg.g.n) {
	  en = zx_DEEP_CLONE_xa_Target(c, e, dup_strs);
	  if (!enn)
	      x->Target = en;
	  else
	      enn->gg.g.n = &en->gg.g;
	  enn = en;
      }
  }
  {
      struct zx_xa_CombinerParameters_s* e;
      struct zx_xa_CombinerParameters_s* en;
      struct zx_xa_CombinerParameters_s* enn;
      for (enn = 0, e = x->CombinerParameters; e; e = (struct zx_xa_CombinerParameters_s*)e->gg.g.n) {
	  en = zx_DEEP_CLONE_xa_CombinerParameters(c, e, dup_strs);
	  if (!enn)
	      x->CombinerParameters = en;
	  else
	      enn->gg.g.n = &en->gg.g;
	  enn = en;
      }
  }
  {
      struct zx_xa_RuleCombinerParameters_s* e;
      struct zx_xa_RuleCombinerParameters_s* en;
      struct zx_xa_RuleCombinerParameters_s* enn;
      for (enn = 0, e = x->RuleCombinerParameters; e; e = (struct zx_xa_RuleCombinerParameters_s*)e->gg.g.n) {
	  en = zx_DEEP_CLONE_xa_RuleCombinerParameters(c, e, dup_strs);
	  if (!enn)
	      x->RuleCombinerParameters = en;
	  else
	      enn->gg.g.n = &en->gg.g;
	  enn = en;
      }
  }
  {
      struct zx_xa_VariableDefinition_s* e;
      struct zx_xa_VariableDefinition_s* en;
      struct zx_xa_VariableDefinition_s* enn;
      for (enn = 0, e = x->VariableDefinition; e; e = (struct zx_xa_VariableDefinition_s*)e->gg.g.n) {
	  en = zx_DEEP_CLONE_xa_VariableDefinition(c, e, dup_strs);
	  if (!enn)
	      x->VariableDefinition = en;
	  else
	      enn->gg.g.n = &en->gg.g;
	  enn = en;
      }
  }
  {
      struct zx_xa_Rule_s* e;
      struct zx_xa_Rule_s* en;
      struct zx_xa_Rule_s* enn;
      for (enn = 0, e = x->Rule; e; e = (struct zx_xa_Rule_s*)e->gg.g.n) {
	  en = zx_DEEP_CLONE_xa_Rule(c, e, dup_strs);
	  if (!enn)
	      x->Rule = en;
	  else
	      enn->gg.g.n = &en->gg.g;
	  enn = en;
      }
  }
  {
      struct zx_xa_Obligations_s* e;
      struct zx_xa_Obligations_s* en;
      struct zx_xa_Obligations_s* enn;
      for (enn = 0, e = x->Obligations; e; e = (struct zx_xa_Obligations_s*)e->gg.g.n) {
	  en = zx_DEEP_CLONE_xa_Obligations(c, e, dup_strs);
	  if (!enn)
	      x->Obligations = en;
	  else
	      enn->gg.g.n = &en->gg.g;
	  enn = en;
      }
  }

  return x;
}

/* FUNC(zx_WALK_SO_xa_Policy) */

/* Depth first traversal of the tree in either schema order or the wire order. */
 
int zx_WALK_SO_xa_Policy(struct zx_ctx* c, struct zx_xa_Policy_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
{
  int ret = callback(&x->gg.g, ctx);
  if (ret)
    return ret;
  
  /* *** deal with xmlns specifications in exc c14n way */


  
  ret = zx_walk_so_unknown_attributes(c, &x->gg, ctx, callback); 
  if (ret)
    return ret;

  ret = zx_walk_so_simple_elems(c, x->Description, ctx, callback);
  if (ret)
    return ret;
  {
      struct zx_xa_PolicyDefaults_s* e;
      for (e = x->PolicyDefaults; e; e = (struct zx_xa_PolicyDefaults_s*)e->gg.g.n) {
	  ret = zx_WALK_SO_xa_PolicyDefaults(c, e, ctx, callback);
	  if (ret)
	      return ret;
      }
  }
  {
      struct zx_xa_Target_s* e;
      for (e = x->Target; e; e = (struct zx_xa_Target_s*)e->gg.g.n) {
	  ret = zx_WALK_SO_xa_Target(c, e, ctx, callback);
	  if (ret)
	      return ret;
      }
  }
  {
      struct zx_xa_CombinerParameters_s* e;
      for (e = x->CombinerParameters; e; e = (struct zx_xa_CombinerParameters_s*)e->gg.g.n) {
	  ret = zx_WALK_SO_xa_CombinerParameters(c, e, ctx, callback);
	  if (ret)
	      return ret;
      }
  }
  {
      struct zx_xa_RuleCombinerParameters_s* e;
      for (e = x->RuleCombinerParameters; e; e = (struct zx_xa_RuleCombinerParameters_s*)e->gg.g.n) {
	  ret = zx_WALK_SO_xa_RuleCombinerParameters(c, e, ctx, callback);
	  if (ret)
	      return ret;
      }
  }
  {
      struct zx_xa_VariableDefinition_s* e;
      for (e = x->VariableDefinition; e; e = (struct zx_xa_VariableDefinition_s*)e->gg.g.n) {
	  ret = zx_WALK_SO_xa_VariableDefinition(c, e, ctx, callback);
	  if (ret)
	      return ret;
      }
  }
  {
      struct zx_xa_Rule_s* e;
      for (e = x->Rule; e; e = (struct zx_xa_Rule_s*)e->gg.g.n) {
	  ret = zx_WALK_SO_xa_Rule(c, e, ctx, callback);
	  if (ret)
	      return ret;
      }
  }
  {
      struct zx_xa_Obligations_s* e;
      for (e = x->Obligations; e; e = (struct zx_xa_Obligations_s*)e->gg.g.n) {
	  ret = zx_WALK_SO_xa_Obligations(c, e, ctx, callback);
	  if (ret)
	      return ret;
      }
  }

  
  return zx_walk_so_unknown_elems_and_content(c, &x->gg, ctx, callback);
}

/* FUNC(zx_WALK_WO_xa_Policy) */

int zx_WALK_WO_xa_Policy(struct zx_ctx* c, struct zx_xa_Policy_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
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

#define EL_NAME   xa_PolicyCombinerParameters
#define EL_STRUCT zx_xa_PolicyCombinerParameters_s
#define EL_NS     xa
#define EL_TAG    PolicyCombinerParameters

/* FUNC(zx_FREE_xa_PolicyCombinerParameters) */

/* Depth first traversal of data structure to free it and its subelements. Simple
 * strings are handled as a special case according to the free_strs flag. This
 * is useful if the strings point to underlying data from the wire that was
 * allocated differently. */

/* Called by: */
void zx_FREE_xa_PolicyCombinerParameters(struct zx_ctx* c, struct zx_xa_PolicyCombinerParameters_s* x, int free_strs)
{
  /* *** deal with xmlns specifications in exc c14n way */

  zx_free_attr(c, x->PolicyIdRef, free_strs);

  {
      struct zx_xa_CombinerParameter_s* e;
      struct zx_xa_CombinerParameter_s* en;
      for (e = x->CombinerParameter; e; e = en) {
	  en = (struct zx_xa_CombinerParameter_s*)e->gg.g.n;
	  zx_FREE_xa_CombinerParameter(c, e, free_strs);
      }
  }


  zx_free_elem_common(c, &x->gg, free_strs); 
}

/* FUNC(zx_NEW_xa_PolicyCombinerParameters) */

/* Trivial allocator/constructor for the datatype. */

/* Called by: */
struct zx_xa_PolicyCombinerParameters_s* zx_NEW_xa_PolicyCombinerParameters(struct zx_ctx* c)
{
  struct zx_xa_PolicyCombinerParameters_s* x = ZX_ZALLOC(c, struct zx_xa_PolicyCombinerParameters_s);
  x->gg.g.tok = zx_xa_PolicyCombinerParameters_ELEM;
  return x;
}

#ifdef ZX_ENA_AUX

/* FUNC(zx_DUP_STRS_xa_PolicyCombinerParameters) */

/* Depth first traversal of data structure to copy its simple strings
 * to memory allocated from the memory allocator. The decoder will
 * use the underlying wireprotocol PDU buffer for strings, i.e.
 * strings are not copied - they point to the real data. If the
 * datastructure needs to outlast the protocol data or needs a different
 * memory allocation strategy, you need to call this function.  */

/* Called by: */
void zx_DUP_STRS_xa_PolicyCombinerParameters(struct zx_ctx* c, struct zx_xa_PolicyCombinerParameters_s* x)
{
  zx_dup_strs_common(c, &x->gg);
  /* *** deal with xmlns specifications in exc c14n way */

  zx_dup_attr(c, x->PolicyIdRef);

  {
      struct zx_xa_CombinerParameter_s* e;
      for (e = x->CombinerParameter; e; e = (struct zx_xa_CombinerParameter_s*)e->gg.g.n)
	  zx_DUP_STRS_xa_CombinerParameter(c, e);
  }

}

/* FUNC(zx_DEEP_CLONE_xa_PolicyCombinerParameters) */

/* Depth first traversal of data structure to clone it and its sublements.
 * The simple strings are handled as a special case according to dup_strs flag. */

/* Called by: */
struct zx_xa_PolicyCombinerParameters_s* zx_DEEP_CLONE_xa_PolicyCombinerParameters(struct zx_ctx* c, struct zx_xa_PolicyCombinerParameters_s* x, int dup_strs)
{
  x = (struct zx_xa_PolicyCombinerParameters_s*)zx_clone_elem_common(c, &x->gg, sizeof(struct zx_xa_PolicyCombinerParameters_s), dup_strs);
  /* *** deal with xmlns specifications in exc c14n way */

  x->PolicyIdRef = zx_clone_attr(c, x->PolicyIdRef);

  {
      struct zx_xa_CombinerParameter_s* e;
      struct zx_xa_CombinerParameter_s* en;
      struct zx_xa_CombinerParameter_s* enn;
      for (enn = 0, e = x->CombinerParameter; e; e = (struct zx_xa_CombinerParameter_s*)e->gg.g.n) {
	  en = zx_DEEP_CLONE_xa_CombinerParameter(c, e, dup_strs);
	  if (!enn)
	      x->CombinerParameter = en;
	  else
	      enn->gg.g.n = &en->gg.g;
	  enn = en;
      }
  }

  return x;
}

/* FUNC(zx_WALK_SO_xa_PolicyCombinerParameters) */

/* Depth first traversal of the tree in either schema order or the wire order. */
 
int zx_WALK_SO_xa_PolicyCombinerParameters(struct zx_ctx* c, struct zx_xa_PolicyCombinerParameters_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
{
  int ret = callback(&x->gg.g, ctx);
  if (ret)
    return ret;
  
  /* *** deal with xmlns specifications in exc c14n way */


  
  ret = zx_walk_so_unknown_attributes(c, &x->gg, ctx, callback); 
  if (ret)
    return ret;

  {
      struct zx_xa_CombinerParameter_s* e;
      for (e = x->CombinerParameter; e; e = (struct zx_xa_CombinerParameter_s*)e->gg.g.n) {
	  ret = zx_WALK_SO_xa_CombinerParameter(c, e, ctx, callback);
	  if (ret)
	      return ret;
      }
  }

  
  return zx_walk_so_unknown_elems_and_content(c, &x->gg, ctx, callback);
}

/* FUNC(zx_WALK_WO_xa_PolicyCombinerParameters) */

int zx_WALK_WO_xa_PolicyCombinerParameters(struct zx_ctx* c, struct zx_xa_PolicyCombinerParameters_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
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

#define EL_NAME   xa_PolicyDefaults
#define EL_STRUCT zx_xa_PolicyDefaults_s
#define EL_NS     xa
#define EL_TAG    PolicyDefaults

/* FUNC(zx_FREE_xa_PolicyDefaults) */

/* Depth first traversal of data structure to free it and its subelements. Simple
 * strings are handled as a special case according to the free_strs flag. This
 * is useful if the strings point to underlying data from the wire that was
 * allocated differently. */

/* Called by: */
void zx_FREE_xa_PolicyDefaults(struct zx_ctx* c, struct zx_xa_PolicyDefaults_s* x, int free_strs)
{
  /* *** deal with xmlns specifications in exc c14n way */


  zx_free_simple_elems(c, x->XPathVersion, free_strs);


  zx_free_elem_common(c, &x->gg, free_strs); 
}

/* FUNC(zx_NEW_xa_PolicyDefaults) */

/* Trivial allocator/constructor for the datatype. */

/* Called by: */
struct zx_xa_PolicyDefaults_s* zx_NEW_xa_PolicyDefaults(struct zx_ctx* c)
{
  struct zx_xa_PolicyDefaults_s* x = ZX_ZALLOC(c, struct zx_xa_PolicyDefaults_s);
  x->gg.g.tok = zx_xa_PolicyDefaults_ELEM;
  return x;
}

#ifdef ZX_ENA_AUX

/* FUNC(zx_DUP_STRS_xa_PolicyDefaults) */

/* Depth first traversal of data structure to copy its simple strings
 * to memory allocated from the memory allocator. The decoder will
 * use the underlying wireprotocol PDU buffer for strings, i.e.
 * strings are not copied - they point to the real data. If the
 * datastructure needs to outlast the protocol data or needs a different
 * memory allocation strategy, you need to call this function.  */

/* Called by: */
void zx_DUP_STRS_xa_PolicyDefaults(struct zx_ctx* c, struct zx_xa_PolicyDefaults_s* x)
{
  zx_dup_strs_common(c, &x->gg);
  /* *** deal with xmlns specifications in exc c14n way */


  zx_dup_strs_simple_elems(c, x->XPathVersion);

}

/* FUNC(zx_DEEP_CLONE_xa_PolicyDefaults) */

/* Depth first traversal of data structure to clone it and its sublements.
 * The simple strings are handled as a special case according to dup_strs flag. */

/* Called by: */
struct zx_xa_PolicyDefaults_s* zx_DEEP_CLONE_xa_PolicyDefaults(struct zx_ctx* c, struct zx_xa_PolicyDefaults_s* x, int dup_strs)
{
  x = (struct zx_xa_PolicyDefaults_s*)zx_clone_elem_common(c, &x->gg, sizeof(struct zx_xa_PolicyDefaults_s), dup_strs);
  /* *** deal with xmlns specifications in exc c14n way */


  x->XPathVersion = zx_deep_clone_simple_elems(c,x->XPathVersion, dup_strs);

  return x;
}

/* FUNC(zx_WALK_SO_xa_PolicyDefaults) */

/* Depth first traversal of the tree in either schema order or the wire order. */
 
int zx_WALK_SO_xa_PolicyDefaults(struct zx_ctx* c, struct zx_xa_PolicyDefaults_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
{
  int ret = callback(&x->gg.g, ctx);
  if (ret)
    return ret;
  
  /* *** deal with xmlns specifications in exc c14n way */


  
  ret = zx_walk_so_unknown_attributes(c, &x->gg, ctx, callback); 
  if (ret)
    return ret;

  ret = zx_walk_so_simple_elems(c, x->XPathVersion, ctx, callback);
  if (ret)
    return ret;

  
  return zx_walk_so_unknown_elems_and_content(c, &x->gg, ctx, callback);
}

/* FUNC(zx_WALK_WO_xa_PolicyDefaults) */

int zx_WALK_WO_xa_PolicyDefaults(struct zx_ctx* c, struct zx_xa_PolicyDefaults_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
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

#define EL_NAME   xa_PolicyIdReference
#define EL_STRUCT zx_xa_PolicyIdReference_s
#define EL_NS     xa
#define EL_TAG    PolicyIdReference

/* FUNC(zx_FREE_xa_PolicyIdReference) */

/* Depth first traversal of data structure to free it and its subelements. Simple
 * strings are handled as a special case according to the free_strs flag. This
 * is useful if the strings point to underlying data from the wire that was
 * allocated differently. */

/* Called by: */
void zx_FREE_xa_PolicyIdReference(struct zx_ctx* c, struct zx_xa_PolicyIdReference_s* x, int free_strs)
{
  /* *** deal with xmlns specifications in exc c14n way */

  zx_free_attr(c, x->EarliestVersion, free_strs);
  zx_free_attr(c, x->LatestVersion, free_strs);
  zx_free_attr(c, x->Version, free_strs);



  zx_free_elem_common(c, &x->gg, free_strs); 
}

/* FUNC(zx_NEW_xa_PolicyIdReference) */

/* Trivial allocator/constructor for the datatype. */

/* Called by: */
struct zx_xa_PolicyIdReference_s* zx_NEW_xa_PolicyIdReference(struct zx_ctx* c)
{
  struct zx_xa_PolicyIdReference_s* x = ZX_ZALLOC(c, struct zx_xa_PolicyIdReference_s);
  x->gg.g.tok = zx_xa_PolicyIdReference_ELEM;
  return x;
}

#ifdef ZX_ENA_AUX

/* FUNC(zx_DUP_STRS_xa_PolicyIdReference) */

/* Depth first traversal of data structure to copy its simple strings
 * to memory allocated from the memory allocator. The decoder will
 * use the underlying wireprotocol PDU buffer for strings, i.e.
 * strings are not copied - they point to the real data. If the
 * datastructure needs to outlast the protocol data or needs a different
 * memory allocation strategy, you need to call this function.  */

/* Called by: */
void zx_DUP_STRS_xa_PolicyIdReference(struct zx_ctx* c, struct zx_xa_PolicyIdReference_s* x)
{
  zx_dup_strs_common(c, &x->gg);
  /* *** deal with xmlns specifications in exc c14n way */

  zx_dup_attr(c, x->EarliestVersion);
  zx_dup_attr(c, x->LatestVersion);
  zx_dup_attr(c, x->Version);


}

/* FUNC(zx_DEEP_CLONE_xa_PolicyIdReference) */

/* Depth first traversal of data structure to clone it and its sublements.
 * The simple strings are handled as a special case according to dup_strs flag. */

/* Called by: */
struct zx_xa_PolicyIdReference_s* zx_DEEP_CLONE_xa_PolicyIdReference(struct zx_ctx* c, struct zx_xa_PolicyIdReference_s* x, int dup_strs)
{
  x = (struct zx_xa_PolicyIdReference_s*)zx_clone_elem_common(c, &x->gg, sizeof(struct zx_xa_PolicyIdReference_s), dup_strs);
  /* *** deal with xmlns specifications in exc c14n way */

  x->EarliestVersion = zx_clone_attr(c, x->EarliestVersion);
  x->LatestVersion = zx_clone_attr(c, x->LatestVersion);
  x->Version = zx_clone_attr(c, x->Version);


  return x;
}

/* FUNC(zx_WALK_SO_xa_PolicyIdReference) */

/* Depth first traversal of the tree in either schema order or the wire order. */
 
int zx_WALK_SO_xa_PolicyIdReference(struct zx_ctx* c, struct zx_xa_PolicyIdReference_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
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

/* FUNC(zx_WALK_WO_xa_PolicyIdReference) */

int zx_WALK_WO_xa_PolicyIdReference(struct zx_ctx* c, struct zx_xa_PolicyIdReference_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
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

#define EL_NAME   xa_PolicySet
#define EL_STRUCT zx_xa_PolicySet_s
#define EL_NS     xa
#define EL_TAG    PolicySet

/* FUNC(zx_FREE_xa_PolicySet) */

/* Depth first traversal of data structure to free it and its subelements. Simple
 * strings are handled as a special case according to the free_strs flag. This
 * is useful if the strings point to underlying data from the wire that was
 * allocated differently. */

/* Called by: */
void zx_FREE_xa_PolicySet(struct zx_ctx* c, struct zx_xa_PolicySet_s* x, int free_strs)
{
  /* *** deal with xmlns specifications in exc c14n way */

  zx_free_attr(c, x->PolicyCombiningAlgId, free_strs);
  zx_free_attr(c, x->PolicySetId, free_strs);
  zx_free_attr(c, x->Version, free_strs);

  zx_free_simple_elems(c, x->Description, free_strs);
  {
      struct zx_xa_PolicySetDefaults_s* e;
      struct zx_xa_PolicySetDefaults_s* en;
      for (e = x->PolicySetDefaults; e; e = en) {
	  en = (struct zx_xa_PolicySetDefaults_s*)e->gg.g.n;
	  zx_FREE_xa_PolicySetDefaults(c, e, free_strs);
      }
  }
  {
      struct zx_xa_Target_s* e;
      struct zx_xa_Target_s* en;
      for (e = x->Target; e; e = en) {
	  en = (struct zx_xa_Target_s*)e->gg.g.n;
	  zx_FREE_xa_Target(c, e, free_strs);
      }
  }
  {
      struct zx_xa_PolicySet_s* e;
      struct zx_xa_PolicySet_s* en;
      for (e = x->PolicySet; e; e = en) {
	  en = (struct zx_xa_PolicySet_s*)e->gg.g.n;
	  zx_FREE_xa_PolicySet(c, e, free_strs);
      }
  }
  {
      struct zx_xa_Policy_s* e;
      struct zx_xa_Policy_s* en;
      for (e = x->Policy; e; e = en) {
	  en = (struct zx_xa_Policy_s*)e->gg.g.n;
	  zx_FREE_xa_Policy(c, e, free_strs);
      }
  }
  {
      struct zx_xa_PolicySetIdReference_s* e;
      struct zx_xa_PolicySetIdReference_s* en;
      for (e = x->PolicySetIdReference; e; e = en) {
	  en = (struct zx_xa_PolicySetIdReference_s*)e->gg.g.n;
	  zx_FREE_xa_PolicySetIdReference(c, e, free_strs);
      }
  }
  {
      struct zx_xa_PolicyIdReference_s* e;
      struct zx_xa_PolicyIdReference_s* en;
      for (e = x->PolicyIdReference; e; e = en) {
	  en = (struct zx_xa_PolicyIdReference_s*)e->gg.g.n;
	  zx_FREE_xa_PolicyIdReference(c, e, free_strs);
      }
  }
  {
      struct zx_xa_CombinerParameters_s* e;
      struct zx_xa_CombinerParameters_s* en;
      for (e = x->CombinerParameters; e; e = en) {
	  en = (struct zx_xa_CombinerParameters_s*)e->gg.g.n;
	  zx_FREE_xa_CombinerParameters(c, e, free_strs);
      }
  }
  {
      struct zx_xa_PolicyCombinerParameters_s* e;
      struct zx_xa_PolicyCombinerParameters_s* en;
      for (e = x->PolicyCombinerParameters; e; e = en) {
	  en = (struct zx_xa_PolicyCombinerParameters_s*)e->gg.g.n;
	  zx_FREE_xa_PolicyCombinerParameters(c, e, free_strs);
      }
  }
  {
      struct zx_xa_PolicySetCombinerParameters_s* e;
      struct zx_xa_PolicySetCombinerParameters_s* en;
      for (e = x->PolicySetCombinerParameters; e; e = en) {
	  en = (struct zx_xa_PolicySetCombinerParameters_s*)e->gg.g.n;
	  zx_FREE_xa_PolicySetCombinerParameters(c, e, free_strs);
      }
  }
  {
      struct zx_xa_Obligations_s* e;
      struct zx_xa_Obligations_s* en;
      for (e = x->Obligations; e; e = en) {
	  en = (struct zx_xa_Obligations_s*)e->gg.g.n;
	  zx_FREE_xa_Obligations(c, e, free_strs);
      }
  }


  zx_free_elem_common(c, &x->gg, free_strs); 
}

/* FUNC(zx_NEW_xa_PolicySet) */

/* Trivial allocator/constructor for the datatype. */

/* Called by: */
struct zx_xa_PolicySet_s* zx_NEW_xa_PolicySet(struct zx_ctx* c)
{
  struct zx_xa_PolicySet_s* x = ZX_ZALLOC(c, struct zx_xa_PolicySet_s);
  x->gg.g.tok = zx_xa_PolicySet_ELEM;
  return x;
}

#ifdef ZX_ENA_AUX

/* FUNC(zx_DUP_STRS_xa_PolicySet) */

/* Depth first traversal of data structure to copy its simple strings
 * to memory allocated from the memory allocator. The decoder will
 * use the underlying wireprotocol PDU buffer for strings, i.e.
 * strings are not copied - they point to the real data. If the
 * datastructure needs to outlast the protocol data or needs a different
 * memory allocation strategy, you need to call this function.  */

/* Called by: */
void zx_DUP_STRS_xa_PolicySet(struct zx_ctx* c, struct zx_xa_PolicySet_s* x)
{
  zx_dup_strs_common(c, &x->gg);
  /* *** deal with xmlns specifications in exc c14n way */

  zx_dup_attr(c, x->PolicyCombiningAlgId);
  zx_dup_attr(c, x->PolicySetId);
  zx_dup_attr(c, x->Version);

  zx_dup_strs_simple_elems(c, x->Description);
  {
      struct zx_xa_PolicySetDefaults_s* e;
      for (e = x->PolicySetDefaults; e; e = (struct zx_xa_PolicySetDefaults_s*)e->gg.g.n)
	  zx_DUP_STRS_xa_PolicySetDefaults(c, e);
  }
  {
      struct zx_xa_Target_s* e;
      for (e = x->Target; e; e = (struct zx_xa_Target_s*)e->gg.g.n)
	  zx_DUP_STRS_xa_Target(c, e);
  }
  {
      struct zx_xa_PolicySet_s* e;
      for (e = x->PolicySet; e; e = (struct zx_xa_PolicySet_s*)e->gg.g.n)
	  zx_DUP_STRS_xa_PolicySet(c, e);
  }
  {
      struct zx_xa_Policy_s* e;
      for (e = x->Policy; e; e = (struct zx_xa_Policy_s*)e->gg.g.n)
	  zx_DUP_STRS_xa_Policy(c, e);
  }
  {
      struct zx_xa_PolicySetIdReference_s* e;
      for (e = x->PolicySetIdReference; e; e = (struct zx_xa_PolicySetIdReference_s*)e->gg.g.n)
	  zx_DUP_STRS_xa_PolicySetIdReference(c, e);
  }
  {
      struct zx_xa_PolicyIdReference_s* e;
      for (e = x->PolicyIdReference; e; e = (struct zx_xa_PolicyIdReference_s*)e->gg.g.n)
	  zx_DUP_STRS_xa_PolicyIdReference(c, e);
  }
  {
      struct zx_xa_CombinerParameters_s* e;
      for (e = x->CombinerParameters; e; e = (struct zx_xa_CombinerParameters_s*)e->gg.g.n)
	  zx_DUP_STRS_xa_CombinerParameters(c, e);
  }
  {
      struct zx_xa_PolicyCombinerParameters_s* e;
      for (e = x->PolicyCombinerParameters; e; e = (struct zx_xa_PolicyCombinerParameters_s*)e->gg.g.n)
	  zx_DUP_STRS_xa_PolicyCombinerParameters(c, e);
  }
  {
      struct zx_xa_PolicySetCombinerParameters_s* e;
      for (e = x->PolicySetCombinerParameters; e; e = (struct zx_xa_PolicySetCombinerParameters_s*)e->gg.g.n)
	  zx_DUP_STRS_xa_PolicySetCombinerParameters(c, e);
  }
  {
      struct zx_xa_Obligations_s* e;
      for (e = x->Obligations; e; e = (struct zx_xa_Obligations_s*)e->gg.g.n)
	  zx_DUP_STRS_xa_Obligations(c, e);
  }

}

/* FUNC(zx_DEEP_CLONE_xa_PolicySet) */

/* Depth first traversal of data structure to clone it and its sublements.
 * The simple strings are handled as a special case according to dup_strs flag. */

/* Called by: */
struct zx_xa_PolicySet_s* zx_DEEP_CLONE_xa_PolicySet(struct zx_ctx* c, struct zx_xa_PolicySet_s* x, int dup_strs)
{
  x = (struct zx_xa_PolicySet_s*)zx_clone_elem_common(c, &x->gg, sizeof(struct zx_xa_PolicySet_s), dup_strs);
  /* *** deal with xmlns specifications in exc c14n way */

  x->PolicyCombiningAlgId = zx_clone_attr(c, x->PolicyCombiningAlgId);
  x->PolicySetId = zx_clone_attr(c, x->PolicySetId);
  x->Version = zx_clone_attr(c, x->Version);

  x->Description = zx_deep_clone_simple_elems(c,x->Description, dup_strs);
  {
      struct zx_xa_PolicySetDefaults_s* e;
      struct zx_xa_PolicySetDefaults_s* en;
      struct zx_xa_PolicySetDefaults_s* enn;
      for (enn = 0, e = x->PolicySetDefaults; e; e = (struct zx_xa_PolicySetDefaults_s*)e->gg.g.n) {
	  en = zx_DEEP_CLONE_xa_PolicySetDefaults(c, e, dup_strs);
	  if (!enn)
	      x->PolicySetDefaults = en;
	  else
	      enn->gg.g.n = &en->gg.g;
	  enn = en;
      }
  }
  {
      struct zx_xa_Target_s* e;
      struct zx_xa_Target_s* en;
      struct zx_xa_Target_s* enn;
      for (enn = 0, e = x->Target; e; e = (struct zx_xa_Target_s*)e->gg.g.n) {
	  en = zx_DEEP_CLONE_xa_Target(c, e, dup_strs);
	  if (!enn)
	      x->Target = en;
	  else
	      enn->gg.g.n = &en->gg.g;
	  enn = en;
      }
  }
  {
      struct zx_xa_PolicySet_s* e;
      struct zx_xa_PolicySet_s* en;
      struct zx_xa_PolicySet_s* enn;
      for (enn = 0, e = x->PolicySet; e; e = (struct zx_xa_PolicySet_s*)e->gg.g.n) {
	  en = zx_DEEP_CLONE_xa_PolicySet(c, e, dup_strs);
	  if (!enn)
	      x->PolicySet = en;
	  else
	      enn->gg.g.n = &en->gg.g;
	  enn = en;
      }
  }
  {
      struct zx_xa_Policy_s* e;
      struct zx_xa_Policy_s* en;
      struct zx_xa_Policy_s* enn;
      for (enn = 0, e = x->Policy; e; e = (struct zx_xa_Policy_s*)e->gg.g.n) {
	  en = zx_DEEP_CLONE_xa_Policy(c, e, dup_strs);
	  if (!enn)
	      x->Policy = en;
	  else
	      enn->gg.g.n = &en->gg.g;
	  enn = en;
      }
  }
  {
      struct zx_xa_PolicySetIdReference_s* e;
      struct zx_xa_PolicySetIdReference_s* en;
      struct zx_xa_PolicySetIdReference_s* enn;
      for (enn = 0, e = x->PolicySetIdReference; e; e = (struct zx_xa_PolicySetIdReference_s*)e->gg.g.n) {
	  en = zx_DEEP_CLONE_xa_PolicySetIdReference(c, e, dup_strs);
	  if (!enn)
	      x->PolicySetIdReference = en;
	  else
	      enn->gg.g.n = &en->gg.g;
	  enn = en;
      }
  }
  {
      struct zx_xa_PolicyIdReference_s* e;
      struct zx_xa_PolicyIdReference_s* en;
      struct zx_xa_PolicyIdReference_s* enn;
      for (enn = 0, e = x->PolicyIdReference; e; e = (struct zx_xa_PolicyIdReference_s*)e->gg.g.n) {
	  en = zx_DEEP_CLONE_xa_PolicyIdReference(c, e, dup_strs);
	  if (!enn)
	      x->PolicyIdReference = en;
	  else
	      enn->gg.g.n = &en->gg.g;
	  enn = en;
      }
  }
  {
      struct zx_xa_CombinerParameters_s* e;
      struct zx_xa_CombinerParameters_s* en;
      struct zx_xa_CombinerParameters_s* enn;
      for (enn = 0, e = x->CombinerParameters; e; e = (struct zx_xa_CombinerParameters_s*)e->gg.g.n) {
	  en = zx_DEEP_CLONE_xa_CombinerParameters(c, e, dup_strs);
	  if (!enn)
	      x->CombinerParameters = en;
	  else
	      enn->gg.g.n = &en->gg.g;
	  enn = en;
      }
  }
  {
      struct zx_xa_PolicyCombinerParameters_s* e;
      struct zx_xa_PolicyCombinerParameters_s* en;
      struct zx_xa_PolicyCombinerParameters_s* enn;
      for (enn = 0, e = x->PolicyCombinerParameters; e; e = (struct zx_xa_PolicyCombinerParameters_s*)e->gg.g.n) {
	  en = zx_DEEP_CLONE_xa_PolicyCombinerParameters(c, e, dup_strs);
	  if (!enn)
	      x->PolicyCombinerParameters = en;
	  else
	      enn->gg.g.n = &en->gg.g;
	  enn = en;
      }
  }
  {
      struct zx_xa_PolicySetCombinerParameters_s* e;
      struct zx_xa_PolicySetCombinerParameters_s* en;
      struct zx_xa_PolicySetCombinerParameters_s* enn;
      for (enn = 0, e = x->PolicySetCombinerParameters; e; e = (struct zx_xa_PolicySetCombinerParameters_s*)e->gg.g.n) {
	  en = zx_DEEP_CLONE_xa_PolicySetCombinerParameters(c, e, dup_strs);
	  if (!enn)
	      x->PolicySetCombinerParameters = en;
	  else
	      enn->gg.g.n = &en->gg.g;
	  enn = en;
      }
  }
  {
      struct zx_xa_Obligations_s* e;
      struct zx_xa_Obligations_s* en;
      struct zx_xa_Obligations_s* enn;
      for (enn = 0, e = x->Obligations; e; e = (struct zx_xa_Obligations_s*)e->gg.g.n) {
	  en = zx_DEEP_CLONE_xa_Obligations(c, e, dup_strs);
	  if (!enn)
	      x->Obligations = en;
	  else
	      enn->gg.g.n = &en->gg.g;
	  enn = en;
      }
  }

  return x;
}

/* FUNC(zx_WALK_SO_xa_PolicySet) */

/* Depth first traversal of the tree in either schema order or the wire order. */
 
int zx_WALK_SO_xa_PolicySet(struct zx_ctx* c, struct zx_xa_PolicySet_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
{
  int ret = callback(&x->gg.g, ctx);
  if (ret)
    return ret;
  
  /* *** deal with xmlns specifications in exc c14n way */


  
  ret = zx_walk_so_unknown_attributes(c, &x->gg, ctx, callback); 
  if (ret)
    return ret;

  ret = zx_walk_so_simple_elems(c, x->Description, ctx, callback);
  if (ret)
    return ret;
  {
      struct zx_xa_PolicySetDefaults_s* e;
      for (e = x->PolicySetDefaults; e; e = (struct zx_xa_PolicySetDefaults_s*)e->gg.g.n) {
	  ret = zx_WALK_SO_xa_PolicySetDefaults(c, e, ctx, callback);
	  if (ret)
	      return ret;
      }
  }
  {
      struct zx_xa_Target_s* e;
      for (e = x->Target; e; e = (struct zx_xa_Target_s*)e->gg.g.n) {
	  ret = zx_WALK_SO_xa_Target(c, e, ctx, callback);
	  if (ret)
	      return ret;
      }
  }
  {
      struct zx_xa_PolicySet_s* e;
      for (e = x->PolicySet; e; e = (struct zx_xa_PolicySet_s*)e->gg.g.n) {
	  ret = zx_WALK_SO_xa_PolicySet(c, e, ctx, callback);
	  if (ret)
	      return ret;
      }
  }
  {
      struct zx_xa_Policy_s* e;
      for (e = x->Policy; e; e = (struct zx_xa_Policy_s*)e->gg.g.n) {
	  ret = zx_WALK_SO_xa_Policy(c, e, ctx, callback);
	  if (ret)
	      return ret;
      }
  }
  {
      struct zx_xa_PolicySetIdReference_s* e;
      for (e = x->PolicySetIdReference; e; e = (struct zx_xa_PolicySetIdReference_s*)e->gg.g.n) {
	  ret = zx_WALK_SO_xa_PolicySetIdReference(c, e, ctx, callback);
	  if (ret)
	      return ret;
      }
  }
  {
      struct zx_xa_PolicyIdReference_s* e;
      for (e = x->PolicyIdReference; e; e = (struct zx_xa_PolicyIdReference_s*)e->gg.g.n) {
	  ret = zx_WALK_SO_xa_PolicyIdReference(c, e, ctx, callback);
	  if (ret)
	      return ret;
      }
  }
  {
      struct zx_xa_CombinerParameters_s* e;
      for (e = x->CombinerParameters; e; e = (struct zx_xa_CombinerParameters_s*)e->gg.g.n) {
	  ret = zx_WALK_SO_xa_CombinerParameters(c, e, ctx, callback);
	  if (ret)
	      return ret;
      }
  }
  {
      struct zx_xa_PolicyCombinerParameters_s* e;
      for (e = x->PolicyCombinerParameters; e; e = (struct zx_xa_PolicyCombinerParameters_s*)e->gg.g.n) {
	  ret = zx_WALK_SO_xa_PolicyCombinerParameters(c, e, ctx, callback);
	  if (ret)
	      return ret;
      }
  }
  {
      struct zx_xa_PolicySetCombinerParameters_s* e;
      for (e = x->PolicySetCombinerParameters; e; e = (struct zx_xa_PolicySetCombinerParameters_s*)e->gg.g.n) {
	  ret = zx_WALK_SO_xa_PolicySetCombinerParameters(c, e, ctx, callback);
	  if (ret)
	      return ret;
      }
  }
  {
      struct zx_xa_Obligations_s* e;
      for (e = x->Obligations; e; e = (struct zx_xa_Obligations_s*)e->gg.g.n) {
	  ret = zx_WALK_SO_xa_Obligations(c, e, ctx, callback);
	  if (ret)
	      return ret;
      }
  }

  
  return zx_walk_so_unknown_elems_and_content(c, &x->gg, ctx, callback);
}

/* FUNC(zx_WALK_WO_xa_PolicySet) */

int zx_WALK_WO_xa_PolicySet(struct zx_ctx* c, struct zx_xa_PolicySet_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
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

#define EL_NAME   xa_PolicySetCombinerParameters
#define EL_STRUCT zx_xa_PolicySetCombinerParameters_s
#define EL_NS     xa
#define EL_TAG    PolicySetCombinerParameters

/* FUNC(zx_FREE_xa_PolicySetCombinerParameters) */

/* Depth first traversal of data structure to free it and its subelements. Simple
 * strings are handled as a special case according to the free_strs flag. This
 * is useful if the strings point to underlying data from the wire that was
 * allocated differently. */

/* Called by: */
void zx_FREE_xa_PolicySetCombinerParameters(struct zx_ctx* c, struct zx_xa_PolicySetCombinerParameters_s* x, int free_strs)
{
  /* *** deal with xmlns specifications in exc c14n way */

  zx_free_attr(c, x->PolicySetIdRef, free_strs);

  {
      struct zx_xa_CombinerParameter_s* e;
      struct zx_xa_CombinerParameter_s* en;
      for (e = x->CombinerParameter; e; e = en) {
	  en = (struct zx_xa_CombinerParameter_s*)e->gg.g.n;
	  zx_FREE_xa_CombinerParameter(c, e, free_strs);
      }
  }


  zx_free_elem_common(c, &x->gg, free_strs); 
}

/* FUNC(zx_NEW_xa_PolicySetCombinerParameters) */

/* Trivial allocator/constructor for the datatype. */

/* Called by: */
struct zx_xa_PolicySetCombinerParameters_s* zx_NEW_xa_PolicySetCombinerParameters(struct zx_ctx* c)
{
  struct zx_xa_PolicySetCombinerParameters_s* x = ZX_ZALLOC(c, struct zx_xa_PolicySetCombinerParameters_s);
  x->gg.g.tok = zx_xa_PolicySetCombinerParameters_ELEM;
  return x;
}

#ifdef ZX_ENA_AUX

/* FUNC(zx_DUP_STRS_xa_PolicySetCombinerParameters) */

/* Depth first traversal of data structure to copy its simple strings
 * to memory allocated from the memory allocator. The decoder will
 * use the underlying wireprotocol PDU buffer for strings, i.e.
 * strings are not copied - they point to the real data. If the
 * datastructure needs to outlast the protocol data or needs a different
 * memory allocation strategy, you need to call this function.  */

/* Called by: */
void zx_DUP_STRS_xa_PolicySetCombinerParameters(struct zx_ctx* c, struct zx_xa_PolicySetCombinerParameters_s* x)
{
  zx_dup_strs_common(c, &x->gg);
  /* *** deal with xmlns specifications in exc c14n way */

  zx_dup_attr(c, x->PolicySetIdRef);

  {
      struct zx_xa_CombinerParameter_s* e;
      for (e = x->CombinerParameter; e; e = (struct zx_xa_CombinerParameter_s*)e->gg.g.n)
	  zx_DUP_STRS_xa_CombinerParameter(c, e);
  }

}

/* FUNC(zx_DEEP_CLONE_xa_PolicySetCombinerParameters) */

/* Depth first traversal of data structure to clone it and its sublements.
 * The simple strings are handled as a special case according to dup_strs flag. */

/* Called by: */
struct zx_xa_PolicySetCombinerParameters_s* zx_DEEP_CLONE_xa_PolicySetCombinerParameters(struct zx_ctx* c, struct zx_xa_PolicySetCombinerParameters_s* x, int dup_strs)
{
  x = (struct zx_xa_PolicySetCombinerParameters_s*)zx_clone_elem_common(c, &x->gg, sizeof(struct zx_xa_PolicySetCombinerParameters_s), dup_strs);
  /* *** deal with xmlns specifications in exc c14n way */

  x->PolicySetIdRef = zx_clone_attr(c, x->PolicySetIdRef);

  {
      struct zx_xa_CombinerParameter_s* e;
      struct zx_xa_CombinerParameter_s* en;
      struct zx_xa_CombinerParameter_s* enn;
      for (enn = 0, e = x->CombinerParameter; e; e = (struct zx_xa_CombinerParameter_s*)e->gg.g.n) {
	  en = zx_DEEP_CLONE_xa_CombinerParameter(c, e, dup_strs);
	  if (!enn)
	      x->CombinerParameter = en;
	  else
	      enn->gg.g.n = &en->gg.g;
	  enn = en;
      }
  }

  return x;
}

/* FUNC(zx_WALK_SO_xa_PolicySetCombinerParameters) */

/* Depth first traversal of the tree in either schema order or the wire order. */
 
int zx_WALK_SO_xa_PolicySetCombinerParameters(struct zx_ctx* c, struct zx_xa_PolicySetCombinerParameters_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
{
  int ret = callback(&x->gg.g, ctx);
  if (ret)
    return ret;
  
  /* *** deal with xmlns specifications in exc c14n way */


  
  ret = zx_walk_so_unknown_attributes(c, &x->gg, ctx, callback); 
  if (ret)
    return ret;

  {
      struct zx_xa_CombinerParameter_s* e;
      for (e = x->CombinerParameter; e; e = (struct zx_xa_CombinerParameter_s*)e->gg.g.n) {
	  ret = zx_WALK_SO_xa_CombinerParameter(c, e, ctx, callback);
	  if (ret)
	      return ret;
      }
  }

  
  return zx_walk_so_unknown_elems_and_content(c, &x->gg, ctx, callback);
}

/* FUNC(zx_WALK_WO_xa_PolicySetCombinerParameters) */

int zx_WALK_WO_xa_PolicySetCombinerParameters(struct zx_ctx* c, struct zx_xa_PolicySetCombinerParameters_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
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

#define EL_NAME   xa_PolicySetDefaults
#define EL_STRUCT zx_xa_PolicySetDefaults_s
#define EL_NS     xa
#define EL_TAG    PolicySetDefaults

/* FUNC(zx_FREE_xa_PolicySetDefaults) */

/* Depth first traversal of data structure to free it and its subelements. Simple
 * strings are handled as a special case according to the free_strs flag. This
 * is useful if the strings point to underlying data from the wire that was
 * allocated differently. */

/* Called by: */
void zx_FREE_xa_PolicySetDefaults(struct zx_ctx* c, struct zx_xa_PolicySetDefaults_s* x, int free_strs)
{
  /* *** deal with xmlns specifications in exc c14n way */


  zx_free_simple_elems(c, x->XPathVersion, free_strs);


  zx_free_elem_common(c, &x->gg, free_strs); 
}

/* FUNC(zx_NEW_xa_PolicySetDefaults) */

/* Trivial allocator/constructor for the datatype. */

/* Called by: */
struct zx_xa_PolicySetDefaults_s* zx_NEW_xa_PolicySetDefaults(struct zx_ctx* c)
{
  struct zx_xa_PolicySetDefaults_s* x = ZX_ZALLOC(c, struct zx_xa_PolicySetDefaults_s);
  x->gg.g.tok = zx_xa_PolicySetDefaults_ELEM;
  return x;
}

#ifdef ZX_ENA_AUX

/* FUNC(zx_DUP_STRS_xa_PolicySetDefaults) */

/* Depth first traversal of data structure to copy its simple strings
 * to memory allocated from the memory allocator. The decoder will
 * use the underlying wireprotocol PDU buffer for strings, i.e.
 * strings are not copied - they point to the real data. If the
 * datastructure needs to outlast the protocol data or needs a different
 * memory allocation strategy, you need to call this function.  */

/* Called by: */
void zx_DUP_STRS_xa_PolicySetDefaults(struct zx_ctx* c, struct zx_xa_PolicySetDefaults_s* x)
{
  zx_dup_strs_common(c, &x->gg);
  /* *** deal with xmlns specifications in exc c14n way */


  zx_dup_strs_simple_elems(c, x->XPathVersion);

}

/* FUNC(zx_DEEP_CLONE_xa_PolicySetDefaults) */

/* Depth first traversal of data structure to clone it and its sublements.
 * The simple strings are handled as a special case according to dup_strs flag. */

/* Called by: */
struct zx_xa_PolicySetDefaults_s* zx_DEEP_CLONE_xa_PolicySetDefaults(struct zx_ctx* c, struct zx_xa_PolicySetDefaults_s* x, int dup_strs)
{
  x = (struct zx_xa_PolicySetDefaults_s*)zx_clone_elem_common(c, &x->gg, sizeof(struct zx_xa_PolicySetDefaults_s), dup_strs);
  /* *** deal with xmlns specifications in exc c14n way */


  x->XPathVersion = zx_deep_clone_simple_elems(c,x->XPathVersion, dup_strs);

  return x;
}

/* FUNC(zx_WALK_SO_xa_PolicySetDefaults) */

/* Depth first traversal of the tree in either schema order or the wire order. */
 
int zx_WALK_SO_xa_PolicySetDefaults(struct zx_ctx* c, struct zx_xa_PolicySetDefaults_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
{
  int ret = callback(&x->gg.g, ctx);
  if (ret)
    return ret;
  
  /* *** deal with xmlns specifications in exc c14n way */


  
  ret = zx_walk_so_unknown_attributes(c, &x->gg, ctx, callback); 
  if (ret)
    return ret;

  ret = zx_walk_so_simple_elems(c, x->XPathVersion, ctx, callback);
  if (ret)
    return ret;

  
  return zx_walk_so_unknown_elems_and_content(c, &x->gg, ctx, callback);
}

/* FUNC(zx_WALK_WO_xa_PolicySetDefaults) */

int zx_WALK_WO_xa_PolicySetDefaults(struct zx_ctx* c, struct zx_xa_PolicySetDefaults_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
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

#define EL_NAME   xa_PolicySetIdReference
#define EL_STRUCT zx_xa_PolicySetIdReference_s
#define EL_NS     xa
#define EL_TAG    PolicySetIdReference

/* FUNC(zx_FREE_xa_PolicySetIdReference) */

/* Depth first traversal of data structure to free it and its subelements. Simple
 * strings are handled as a special case according to the free_strs flag. This
 * is useful if the strings point to underlying data from the wire that was
 * allocated differently. */

/* Called by: */
void zx_FREE_xa_PolicySetIdReference(struct zx_ctx* c, struct zx_xa_PolicySetIdReference_s* x, int free_strs)
{
  /* *** deal with xmlns specifications in exc c14n way */

  zx_free_attr(c, x->EarliestVersion, free_strs);
  zx_free_attr(c, x->LatestVersion, free_strs);
  zx_free_attr(c, x->Version, free_strs);



  zx_free_elem_common(c, &x->gg, free_strs); 
}

/* FUNC(zx_NEW_xa_PolicySetIdReference) */

/* Trivial allocator/constructor for the datatype. */

/* Called by: */
struct zx_xa_PolicySetIdReference_s* zx_NEW_xa_PolicySetIdReference(struct zx_ctx* c)
{
  struct zx_xa_PolicySetIdReference_s* x = ZX_ZALLOC(c, struct zx_xa_PolicySetIdReference_s);
  x->gg.g.tok = zx_xa_PolicySetIdReference_ELEM;
  return x;
}

#ifdef ZX_ENA_AUX

/* FUNC(zx_DUP_STRS_xa_PolicySetIdReference) */

/* Depth first traversal of data structure to copy its simple strings
 * to memory allocated from the memory allocator. The decoder will
 * use the underlying wireprotocol PDU buffer for strings, i.e.
 * strings are not copied - they point to the real data. If the
 * datastructure needs to outlast the protocol data or needs a different
 * memory allocation strategy, you need to call this function.  */

/* Called by: */
void zx_DUP_STRS_xa_PolicySetIdReference(struct zx_ctx* c, struct zx_xa_PolicySetIdReference_s* x)
{
  zx_dup_strs_common(c, &x->gg);
  /* *** deal with xmlns specifications in exc c14n way */

  zx_dup_attr(c, x->EarliestVersion);
  zx_dup_attr(c, x->LatestVersion);
  zx_dup_attr(c, x->Version);


}

/* FUNC(zx_DEEP_CLONE_xa_PolicySetIdReference) */

/* Depth first traversal of data structure to clone it and its sublements.
 * The simple strings are handled as a special case according to dup_strs flag. */

/* Called by: */
struct zx_xa_PolicySetIdReference_s* zx_DEEP_CLONE_xa_PolicySetIdReference(struct zx_ctx* c, struct zx_xa_PolicySetIdReference_s* x, int dup_strs)
{
  x = (struct zx_xa_PolicySetIdReference_s*)zx_clone_elem_common(c, &x->gg, sizeof(struct zx_xa_PolicySetIdReference_s), dup_strs);
  /* *** deal with xmlns specifications in exc c14n way */

  x->EarliestVersion = zx_clone_attr(c, x->EarliestVersion);
  x->LatestVersion = zx_clone_attr(c, x->LatestVersion);
  x->Version = zx_clone_attr(c, x->Version);


  return x;
}

/* FUNC(zx_WALK_SO_xa_PolicySetIdReference) */

/* Depth first traversal of the tree in either schema order or the wire order. */
 
int zx_WALK_SO_xa_PolicySetIdReference(struct zx_ctx* c, struct zx_xa_PolicySetIdReference_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
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

/* FUNC(zx_WALK_WO_xa_PolicySetIdReference) */

int zx_WALK_WO_xa_PolicySetIdReference(struct zx_ctx* c, struct zx_xa_PolicySetIdReference_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
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

#define EL_NAME   xa_Resource
#define EL_STRUCT zx_xa_Resource_s
#define EL_NS     xa
#define EL_TAG    Resource

/* FUNC(zx_FREE_xa_Resource) */

/* Depth first traversal of data structure to free it and its subelements. Simple
 * strings are handled as a special case according to the free_strs flag. This
 * is useful if the strings point to underlying data from the wire that was
 * allocated differently. */

/* Called by: */
void zx_FREE_xa_Resource(struct zx_ctx* c, struct zx_xa_Resource_s* x, int free_strs)
{
  /* *** deal with xmlns specifications in exc c14n way */


  {
      struct zx_xa_ResourceMatch_s* e;
      struct zx_xa_ResourceMatch_s* en;
      for (e = x->ResourceMatch; e; e = en) {
	  en = (struct zx_xa_ResourceMatch_s*)e->gg.g.n;
	  zx_FREE_xa_ResourceMatch(c, e, free_strs);
      }
  }


  zx_free_elem_common(c, &x->gg, free_strs); 
}

/* FUNC(zx_NEW_xa_Resource) */

/* Trivial allocator/constructor for the datatype. */

/* Called by: */
struct zx_xa_Resource_s* zx_NEW_xa_Resource(struct zx_ctx* c)
{
  struct zx_xa_Resource_s* x = ZX_ZALLOC(c, struct zx_xa_Resource_s);
  x->gg.g.tok = zx_xa_Resource_ELEM;
  return x;
}

#ifdef ZX_ENA_AUX

/* FUNC(zx_DUP_STRS_xa_Resource) */

/* Depth first traversal of data structure to copy its simple strings
 * to memory allocated from the memory allocator. The decoder will
 * use the underlying wireprotocol PDU buffer for strings, i.e.
 * strings are not copied - they point to the real data. If the
 * datastructure needs to outlast the protocol data or needs a different
 * memory allocation strategy, you need to call this function.  */

/* Called by: */
void zx_DUP_STRS_xa_Resource(struct zx_ctx* c, struct zx_xa_Resource_s* x)
{
  zx_dup_strs_common(c, &x->gg);
  /* *** deal with xmlns specifications in exc c14n way */


  {
      struct zx_xa_ResourceMatch_s* e;
      for (e = x->ResourceMatch; e; e = (struct zx_xa_ResourceMatch_s*)e->gg.g.n)
	  zx_DUP_STRS_xa_ResourceMatch(c, e);
  }

}

/* FUNC(zx_DEEP_CLONE_xa_Resource) */

/* Depth first traversal of data structure to clone it and its sublements.
 * The simple strings are handled as a special case according to dup_strs flag. */

/* Called by: */
struct zx_xa_Resource_s* zx_DEEP_CLONE_xa_Resource(struct zx_ctx* c, struct zx_xa_Resource_s* x, int dup_strs)
{
  x = (struct zx_xa_Resource_s*)zx_clone_elem_common(c, &x->gg, sizeof(struct zx_xa_Resource_s), dup_strs);
  /* *** deal with xmlns specifications in exc c14n way */


  {
      struct zx_xa_ResourceMatch_s* e;
      struct zx_xa_ResourceMatch_s* en;
      struct zx_xa_ResourceMatch_s* enn;
      for (enn = 0, e = x->ResourceMatch; e; e = (struct zx_xa_ResourceMatch_s*)e->gg.g.n) {
	  en = zx_DEEP_CLONE_xa_ResourceMatch(c, e, dup_strs);
	  if (!enn)
	      x->ResourceMatch = en;
	  else
	      enn->gg.g.n = &en->gg.g;
	  enn = en;
      }
  }

  return x;
}

/* FUNC(zx_WALK_SO_xa_Resource) */

/* Depth first traversal of the tree in either schema order or the wire order. */
 
int zx_WALK_SO_xa_Resource(struct zx_ctx* c, struct zx_xa_Resource_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
{
  int ret = callback(&x->gg.g, ctx);
  if (ret)
    return ret;
  
  /* *** deal with xmlns specifications in exc c14n way */


  
  ret = zx_walk_so_unknown_attributes(c, &x->gg, ctx, callback); 
  if (ret)
    return ret;

  {
      struct zx_xa_ResourceMatch_s* e;
      for (e = x->ResourceMatch; e; e = (struct zx_xa_ResourceMatch_s*)e->gg.g.n) {
	  ret = zx_WALK_SO_xa_ResourceMatch(c, e, ctx, callback);
	  if (ret)
	      return ret;
      }
  }

  
  return zx_walk_so_unknown_elems_and_content(c, &x->gg, ctx, callback);
}

/* FUNC(zx_WALK_WO_xa_Resource) */

int zx_WALK_WO_xa_Resource(struct zx_ctx* c, struct zx_xa_Resource_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
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

#define EL_NAME   xa_ResourceAttributeDesignator
#define EL_STRUCT zx_xa_ResourceAttributeDesignator_s
#define EL_NS     xa
#define EL_TAG    ResourceAttributeDesignator

/* FUNC(zx_FREE_xa_ResourceAttributeDesignator) */

/* Depth first traversal of data structure to free it and its subelements. Simple
 * strings are handled as a special case according to the free_strs flag. This
 * is useful if the strings point to underlying data from the wire that was
 * allocated differently. */

/* Called by: */
void zx_FREE_xa_ResourceAttributeDesignator(struct zx_ctx* c, struct zx_xa_ResourceAttributeDesignator_s* x, int free_strs)
{
  /* *** deal with xmlns specifications in exc c14n way */

  zx_free_attr(c, x->AttributeId, free_strs);
  zx_free_attr(c, x->DataType, free_strs);
  zx_free_attr(c, x->Issuer, free_strs);
  zx_free_attr(c, x->MustBePresent, free_strs);



  zx_free_elem_common(c, &x->gg, free_strs); 
}

/* FUNC(zx_NEW_xa_ResourceAttributeDesignator) */

/* Trivial allocator/constructor for the datatype. */

/* Called by: */
struct zx_xa_ResourceAttributeDesignator_s* zx_NEW_xa_ResourceAttributeDesignator(struct zx_ctx* c)
{
  struct zx_xa_ResourceAttributeDesignator_s* x = ZX_ZALLOC(c, struct zx_xa_ResourceAttributeDesignator_s);
  x->gg.g.tok = zx_xa_ResourceAttributeDesignator_ELEM;
  return x;
}

#ifdef ZX_ENA_AUX

/* FUNC(zx_DUP_STRS_xa_ResourceAttributeDesignator) */

/* Depth first traversal of data structure to copy its simple strings
 * to memory allocated from the memory allocator. The decoder will
 * use the underlying wireprotocol PDU buffer for strings, i.e.
 * strings are not copied - they point to the real data. If the
 * datastructure needs to outlast the protocol data or needs a different
 * memory allocation strategy, you need to call this function.  */

/* Called by: */
void zx_DUP_STRS_xa_ResourceAttributeDesignator(struct zx_ctx* c, struct zx_xa_ResourceAttributeDesignator_s* x)
{
  zx_dup_strs_common(c, &x->gg);
  /* *** deal with xmlns specifications in exc c14n way */

  zx_dup_attr(c, x->AttributeId);
  zx_dup_attr(c, x->DataType);
  zx_dup_attr(c, x->Issuer);
  zx_dup_attr(c, x->MustBePresent);


}

/* FUNC(zx_DEEP_CLONE_xa_ResourceAttributeDesignator) */

/* Depth first traversal of data structure to clone it and its sublements.
 * The simple strings are handled as a special case according to dup_strs flag. */

/* Called by: */
struct zx_xa_ResourceAttributeDesignator_s* zx_DEEP_CLONE_xa_ResourceAttributeDesignator(struct zx_ctx* c, struct zx_xa_ResourceAttributeDesignator_s* x, int dup_strs)
{
  x = (struct zx_xa_ResourceAttributeDesignator_s*)zx_clone_elem_common(c, &x->gg, sizeof(struct zx_xa_ResourceAttributeDesignator_s), dup_strs);
  /* *** deal with xmlns specifications in exc c14n way */

  x->AttributeId = zx_clone_attr(c, x->AttributeId);
  x->DataType = zx_clone_attr(c, x->DataType);
  x->Issuer = zx_clone_attr(c, x->Issuer);
  x->MustBePresent = zx_clone_attr(c, x->MustBePresent);


  return x;
}

/* FUNC(zx_WALK_SO_xa_ResourceAttributeDesignator) */

/* Depth first traversal of the tree in either schema order or the wire order. */
 
int zx_WALK_SO_xa_ResourceAttributeDesignator(struct zx_ctx* c, struct zx_xa_ResourceAttributeDesignator_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
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

/* FUNC(zx_WALK_WO_xa_ResourceAttributeDesignator) */

int zx_WALK_WO_xa_ResourceAttributeDesignator(struct zx_ctx* c, struct zx_xa_ResourceAttributeDesignator_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
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

#define EL_NAME   xa_ResourceMatch
#define EL_STRUCT zx_xa_ResourceMatch_s
#define EL_NS     xa
#define EL_TAG    ResourceMatch

/* FUNC(zx_FREE_xa_ResourceMatch) */

/* Depth first traversal of data structure to free it and its subelements. Simple
 * strings are handled as a special case according to the free_strs flag. This
 * is useful if the strings point to underlying data from the wire that was
 * allocated differently. */

/* Called by: */
void zx_FREE_xa_ResourceMatch(struct zx_ctx* c, struct zx_xa_ResourceMatch_s* x, int free_strs)
{
  /* *** deal with xmlns specifications in exc c14n way */

  zx_free_attr(c, x->MatchId, free_strs);

  {
      struct zx_xa_AttributeValue_s* e;
      struct zx_xa_AttributeValue_s* en;
      for (e = x->AttributeValue; e; e = en) {
	  en = (struct zx_xa_AttributeValue_s*)e->gg.g.n;
	  zx_FREE_xa_AttributeValue(c, e, free_strs);
      }
  }
  {
      struct zx_xa_ResourceAttributeDesignator_s* e;
      struct zx_xa_ResourceAttributeDesignator_s* en;
      for (e = x->ResourceAttributeDesignator; e; e = en) {
	  en = (struct zx_xa_ResourceAttributeDesignator_s*)e->gg.g.n;
	  zx_FREE_xa_ResourceAttributeDesignator(c, e, free_strs);
      }
  }
  {
      struct zx_xa_AttributeSelector_s* e;
      struct zx_xa_AttributeSelector_s* en;
      for (e = x->AttributeSelector; e; e = en) {
	  en = (struct zx_xa_AttributeSelector_s*)e->gg.g.n;
	  zx_FREE_xa_AttributeSelector(c, e, free_strs);
      }
  }


  zx_free_elem_common(c, &x->gg, free_strs); 
}

/* FUNC(zx_NEW_xa_ResourceMatch) */

/* Trivial allocator/constructor for the datatype. */

/* Called by: */
struct zx_xa_ResourceMatch_s* zx_NEW_xa_ResourceMatch(struct zx_ctx* c)
{
  struct zx_xa_ResourceMatch_s* x = ZX_ZALLOC(c, struct zx_xa_ResourceMatch_s);
  x->gg.g.tok = zx_xa_ResourceMatch_ELEM;
  return x;
}

#ifdef ZX_ENA_AUX

/* FUNC(zx_DUP_STRS_xa_ResourceMatch) */

/* Depth first traversal of data structure to copy its simple strings
 * to memory allocated from the memory allocator. The decoder will
 * use the underlying wireprotocol PDU buffer for strings, i.e.
 * strings are not copied - they point to the real data. If the
 * datastructure needs to outlast the protocol data or needs a different
 * memory allocation strategy, you need to call this function.  */

/* Called by: */
void zx_DUP_STRS_xa_ResourceMatch(struct zx_ctx* c, struct zx_xa_ResourceMatch_s* x)
{
  zx_dup_strs_common(c, &x->gg);
  /* *** deal with xmlns specifications in exc c14n way */

  zx_dup_attr(c, x->MatchId);

  {
      struct zx_xa_AttributeValue_s* e;
      for (e = x->AttributeValue; e; e = (struct zx_xa_AttributeValue_s*)e->gg.g.n)
	  zx_DUP_STRS_xa_AttributeValue(c, e);
  }
  {
      struct zx_xa_ResourceAttributeDesignator_s* e;
      for (e = x->ResourceAttributeDesignator; e; e = (struct zx_xa_ResourceAttributeDesignator_s*)e->gg.g.n)
	  zx_DUP_STRS_xa_ResourceAttributeDesignator(c, e);
  }
  {
      struct zx_xa_AttributeSelector_s* e;
      for (e = x->AttributeSelector; e; e = (struct zx_xa_AttributeSelector_s*)e->gg.g.n)
	  zx_DUP_STRS_xa_AttributeSelector(c, e);
  }

}

/* FUNC(zx_DEEP_CLONE_xa_ResourceMatch) */

/* Depth first traversal of data structure to clone it and its sublements.
 * The simple strings are handled as a special case according to dup_strs flag. */

/* Called by: */
struct zx_xa_ResourceMatch_s* zx_DEEP_CLONE_xa_ResourceMatch(struct zx_ctx* c, struct zx_xa_ResourceMatch_s* x, int dup_strs)
{
  x = (struct zx_xa_ResourceMatch_s*)zx_clone_elem_common(c, &x->gg, sizeof(struct zx_xa_ResourceMatch_s), dup_strs);
  /* *** deal with xmlns specifications in exc c14n way */

  x->MatchId = zx_clone_attr(c, x->MatchId);

  {
      struct zx_xa_AttributeValue_s* e;
      struct zx_xa_AttributeValue_s* en;
      struct zx_xa_AttributeValue_s* enn;
      for (enn = 0, e = x->AttributeValue; e; e = (struct zx_xa_AttributeValue_s*)e->gg.g.n) {
	  en = zx_DEEP_CLONE_xa_AttributeValue(c, e, dup_strs);
	  if (!enn)
	      x->AttributeValue = en;
	  else
	      enn->gg.g.n = &en->gg.g;
	  enn = en;
      }
  }
  {
      struct zx_xa_ResourceAttributeDesignator_s* e;
      struct zx_xa_ResourceAttributeDesignator_s* en;
      struct zx_xa_ResourceAttributeDesignator_s* enn;
      for (enn = 0, e = x->ResourceAttributeDesignator; e; e = (struct zx_xa_ResourceAttributeDesignator_s*)e->gg.g.n) {
	  en = zx_DEEP_CLONE_xa_ResourceAttributeDesignator(c, e, dup_strs);
	  if (!enn)
	      x->ResourceAttributeDesignator = en;
	  else
	      enn->gg.g.n = &en->gg.g;
	  enn = en;
      }
  }
  {
      struct zx_xa_AttributeSelector_s* e;
      struct zx_xa_AttributeSelector_s* en;
      struct zx_xa_AttributeSelector_s* enn;
      for (enn = 0, e = x->AttributeSelector; e; e = (struct zx_xa_AttributeSelector_s*)e->gg.g.n) {
	  en = zx_DEEP_CLONE_xa_AttributeSelector(c, e, dup_strs);
	  if (!enn)
	      x->AttributeSelector = en;
	  else
	      enn->gg.g.n = &en->gg.g;
	  enn = en;
      }
  }

  return x;
}

/* FUNC(zx_WALK_SO_xa_ResourceMatch) */

/* Depth first traversal of the tree in either schema order or the wire order. */
 
int zx_WALK_SO_xa_ResourceMatch(struct zx_ctx* c, struct zx_xa_ResourceMatch_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
{
  int ret = callback(&x->gg.g, ctx);
  if (ret)
    return ret;
  
  /* *** deal with xmlns specifications in exc c14n way */


  
  ret = zx_walk_so_unknown_attributes(c, &x->gg, ctx, callback); 
  if (ret)
    return ret;

  {
      struct zx_xa_AttributeValue_s* e;
      for (e = x->AttributeValue; e; e = (struct zx_xa_AttributeValue_s*)e->gg.g.n) {
	  ret = zx_WALK_SO_xa_AttributeValue(c, e, ctx, callback);
	  if (ret)
	      return ret;
      }
  }
  {
      struct zx_xa_ResourceAttributeDesignator_s* e;
      for (e = x->ResourceAttributeDesignator; e; e = (struct zx_xa_ResourceAttributeDesignator_s*)e->gg.g.n) {
	  ret = zx_WALK_SO_xa_ResourceAttributeDesignator(c, e, ctx, callback);
	  if (ret)
	      return ret;
      }
  }
  {
      struct zx_xa_AttributeSelector_s* e;
      for (e = x->AttributeSelector; e; e = (struct zx_xa_AttributeSelector_s*)e->gg.g.n) {
	  ret = zx_WALK_SO_xa_AttributeSelector(c, e, ctx, callback);
	  if (ret)
	      return ret;
      }
  }

  
  return zx_walk_so_unknown_elems_and_content(c, &x->gg, ctx, callback);
}

/* FUNC(zx_WALK_WO_xa_ResourceMatch) */

int zx_WALK_WO_xa_ResourceMatch(struct zx_ctx* c, struct zx_xa_ResourceMatch_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
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

#define EL_NAME   xa_Resources
#define EL_STRUCT zx_xa_Resources_s
#define EL_NS     xa
#define EL_TAG    Resources

/* FUNC(zx_FREE_xa_Resources) */

/* Depth first traversal of data structure to free it and its subelements. Simple
 * strings are handled as a special case according to the free_strs flag. This
 * is useful if the strings point to underlying data from the wire that was
 * allocated differently. */

/* Called by: */
void zx_FREE_xa_Resources(struct zx_ctx* c, struct zx_xa_Resources_s* x, int free_strs)
{
  /* *** deal with xmlns specifications in exc c14n way */


  {
      struct zx_xa_Resource_s* e;
      struct zx_xa_Resource_s* en;
      for (e = x->Resource; e; e = en) {
	  en = (struct zx_xa_Resource_s*)e->gg.g.n;
	  zx_FREE_xa_Resource(c, e, free_strs);
      }
  }


  zx_free_elem_common(c, &x->gg, free_strs); 
}

/* FUNC(zx_NEW_xa_Resources) */

/* Trivial allocator/constructor for the datatype. */

/* Called by: */
struct zx_xa_Resources_s* zx_NEW_xa_Resources(struct zx_ctx* c)
{
  struct zx_xa_Resources_s* x = ZX_ZALLOC(c, struct zx_xa_Resources_s);
  x->gg.g.tok = zx_xa_Resources_ELEM;
  return x;
}

#ifdef ZX_ENA_AUX

/* FUNC(zx_DUP_STRS_xa_Resources) */

/* Depth first traversal of data structure to copy its simple strings
 * to memory allocated from the memory allocator. The decoder will
 * use the underlying wireprotocol PDU buffer for strings, i.e.
 * strings are not copied - they point to the real data. If the
 * datastructure needs to outlast the protocol data or needs a different
 * memory allocation strategy, you need to call this function.  */

/* Called by: */
void zx_DUP_STRS_xa_Resources(struct zx_ctx* c, struct zx_xa_Resources_s* x)
{
  zx_dup_strs_common(c, &x->gg);
  /* *** deal with xmlns specifications in exc c14n way */


  {
      struct zx_xa_Resource_s* e;
      for (e = x->Resource; e; e = (struct zx_xa_Resource_s*)e->gg.g.n)
	  zx_DUP_STRS_xa_Resource(c, e);
  }

}

/* FUNC(zx_DEEP_CLONE_xa_Resources) */

/* Depth first traversal of data structure to clone it and its sublements.
 * The simple strings are handled as a special case according to dup_strs flag. */

/* Called by: */
struct zx_xa_Resources_s* zx_DEEP_CLONE_xa_Resources(struct zx_ctx* c, struct zx_xa_Resources_s* x, int dup_strs)
{
  x = (struct zx_xa_Resources_s*)zx_clone_elem_common(c, &x->gg, sizeof(struct zx_xa_Resources_s), dup_strs);
  /* *** deal with xmlns specifications in exc c14n way */


  {
      struct zx_xa_Resource_s* e;
      struct zx_xa_Resource_s* en;
      struct zx_xa_Resource_s* enn;
      for (enn = 0, e = x->Resource; e; e = (struct zx_xa_Resource_s*)e->gg.g.n) {
	  en = zx_DEEP_CLONE_xa_Resource(c, e, dup_strs);
	  if (!enn)
	      x->Resource = en;
	  else
	      enn->gg.g.n = &en->gg.g;
	  enn = en;
      }
  }

  return x;
}

/* FUNC(zx_WALK_SO_xa_Resources) */

/* Depth first traversal of the tree in either schema order or the wire order. */
 
int zx_WALK_SO_xa_Resources(struct zx_ctx* c, struct zx_xa_Resources_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
{
  int ret = callback(&x->gg.g, ctx);
  if (ret)
    return ret;
  
  /* *** deal with xmlns specifications in exc c14n way */


  
  ret = zx_walk_so_unknown_attributes(c, &x->gg, ctx, callback); 
  if (ret)
    return ret;

  {
      struct zx_xa_Resource_s* e;
      for (e = x->Resource; e; e = (struct zx_xa_Resource_s*)e->gg.g.n) {
	  ret = zx_WALK_SO_xa_Resource(c, e, ctx, callback);
	  if (ret)
	      return ret;
      }
  }

  
  return zx_walk_so_unknown_elems_and_content(c, &x->gg, ctx, callback);
}

/* FUNC(zx_WALK_WO_xa_Resources) */

int zx_WALK_WO_xa_Resources(struct zx_ctx* c, struct zx_xa_Resources_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
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

#define EL_NAME   xa_Rule
#define EL_STRUCT zx_xa_Rule_s
#define EL_NS     xa
#define EL_TAG    Rule

/* FUNC(zx_FREE_xa_Rule) */

/* Depth first traversal of data structure to free it and its subelements. Simple
 * strings are handled as a special case according to the free_strs flag. This
 * is useful if the strings point to underlying data from the wire that was
 * allocated differently. */

/* Called by: */
void zx_FREE_xa_Rule(struct zx_ctx* c, struct zx_xa_Rule_s* x, int free_strs)
{
  /* *** deal with xmlns specifications in exc c14n way */

  zx_free_attr(c, x->Effect, free_strs);
  zx_free_attr(c, x->RuleId, free_strs);

  zx_free_simple_elems(c, x->Description, free_strs);
  {
      struct zx_xa_Target_s* e;
      struct zx_xa_Target_s* en;
      for (e = x->Target; e; e = en) {
	  en = (struct zx_xa_Target_s*)e->gg.g.n;
	  zx_FREE_xa_Target(c, e, free_strs);
      }
  }
  {
      struct zx_xa_Condition_s* e;
      struct zx_xa_Condition_s* en;
      for (e = x->Condition; e; e = en) {
	  en = (struct zx_xa_Condition_s*)e->gg.g.n;
	  zx_FREE_xa_Condition(c, e, free_strs);
      }
  }


  zx_free_elem_common(c, &x->gg, free_strs); 
}

/* FUNC(zx_NEW_xa_Rule) */

/* Trivial allocator/constructor for the datatype. */

/* Called by: */
struct zx_xa_Rule_s* zx_NEW_xa_Rule(struct zx_ctx* c)
{
  struct zx_xa_Rule_s* x = ZX_ZALLOC(c, struct zx_xa_Rule_s);
  x->gg.g.tok = zx_xa_Rule_ELEM;
  return x;
}

#ifdef ZX_ENA_AUX

/* FUNC(zx_DUP_STRS_xa_Rule) */

/* Depth first traversal of data structure to copy its simple strings
 * to memory allocated from the memory allocator. The decoder will
 * use the underlying wireprotocol PDU buffer for strings, i.e.
 * strings are not copied - they point to the real data. If the
 * datastructure needs to outlast the protocol data or needs a different
 * memory allocation strategy, you need to call this function.  */

/* Called by: */
void zx_DUP_STRS_xa_Rule(struct zx_ctx* c, struct zx_xa_Rule_s* x)
{
  zx_dup_strs_common(c, &x->gg);
  /* *** deal with xmlns specifications in exc c14n way */

  zx_dup_attr(c, x->Effect);
  zx_dup_attr(c, x->RuleId);

  zx_dup_strs_simple_elems(c, x->Description);
  {
      struct zx_xa_Target_s* e;
      for (e = x->Target; e; e = (struct zx_xa_Target_s*)e->gg.g.n)
	  zx_DUP_STRS_xa_Target(c, e);
  }
  {
      struct zx_xa_Condition_s* e;
      for (e = x->Condition; e; e = (struct zx_xa_Condition_s*)e->gg.g.n)
	  zx_DUP_STRS_xa_Condition(c, e);
  }

}

/* FUNC(zx_DEEP_CLONE_xa_Rule) */

/* Depth first traversal of data structure to clone it and its sublements.
 * The simple strings are handled as a special case according to dup_strs flag. */

/* Called by: */
struct zx_xa_Rule_s* zx_DEEP_CLONE_xa_Rule(struct zx_ctx* c, struct zx_xa_Rule_s* x, int dup_strs)
{
  x = (struct zx_xa_Rule_s*)zx_clone_elem_common(c, &x->gg, sizeof(struct zx_xa_Rule_s), dup_strs);
  /* *** deal with xmlns specifications in exc c14n way */

  x->Effect = zx_clone_attr(c, x->Effect);
  x->RuleId = zx_clone_attr(c, x->RuleId);

  x->Description = zx_deep_clone_simple_elems(c,x->Description, dup_strs);
  {
      struct zx_xa_Target_s* e;
      struct zx_xa_Target_s* en;
      struct zx_xa_Target_s* enn;
      for (enn = 0, e = x->Target; e; e = (struct zx_xa_Target_s*)e->gg.g.n) {
	  en = zx_DEEP_CLONE_xa_Target(c, e, dup_strs);
	  if (!enn)
	      x->Target = en;
	  else
	      enn->gg.g.n = &en->gg.g;
	  enn = en;
      }
  }
  {
      struct zx_xa_Condition_s* e;
      struct zx_xa_Condition_s* en;
      struct zx_xa_Condition_s* enn;
      for (enn = 0, e = x->Condition; e; e = (struct zx_xa_Condition_s*)e->gg.g.n) {
	  en = zx_DEEP_CLONE_xa_Condition(c, e, dup_strs);
	  if (!enn)
	      x->Condition = en;
	  else
	      enn->gg.g.n = &en->gg.g;
	  enn = en;
      }
  }

  return x;
}

/* FUNC(zx_WALK_SO_xa_Rule) */

/* Depth first traversal of the tree in either schema order or the wire order. */
 
int zx_WALK_SO_xa_Rule(struct zx_ctx* c, struct zx_xa_Rule_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
{
  int ret = callback(&x->gg.g, ctx);
  if (ret)
    return ret;
  
  /* *** deal with xmlns specifications in exc c14n way */


  
  ret = zx_walk_so_unknown_attributes(c, &x->gg, ctx, callback); 
  if (ret)
    return ret;

  ret = zx_walk_so_simple_elems(c, x->Description, ctx, callback);
  if (ret)
    return ret;
  {
      struct zx_xa_Target_s* e;
      for (e = x->Target; e; e = (struct zx_xa_Target_s*)e->gg.g.n) {
	  ret = zx_WALK_SO_xa_Target(c, e, ctx, callback);
	  if (ret)
	      return ret;
      }
  }
  {
      struct zx_xa_Condition_s* e;
      for (e = x->Condition; e; e = (struct zx_xa_Condition_s*)e->gg.g.n) {
	  ret = zx_WALK_SO_xa_Condition(c, e, ctx, callback);
	  if (ret)
	      return ret;
      }
  }

  
  return zx_walk_so_unknown_elems_and_content(c, &x->gg, ctx, callback);
}

/* FUNC(zx_WALK_WO_xa_Rule) */

int zx_WALK_WO_xa_Rule(struct zx_ctx* c, struct zx_xa_Rule_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
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

#define EL_NAME   xa_RuleCombinerParameters
#define EL_STRUCT zx_xa_RuleCombinerParameters_s
#define EL_NS     xa
#define EL_TAG    RuleCombinerParameters

/* FUNC(zx_FREE_xa_RuleCombinerParameters) */

/* Depth first traversal of data structure to free it and its subelements. Simple
 * strings are handled as a special case according to the free_strs flag. This
 * is useful if the strings point to underlying data from the wire that was
 * allocated differently. */

/* Called by: */
void zx_FREE_xa_RuleCombinerParameters(struct zx_ctx* c, struct zx_xa_RuleCombinerParameters_s* x, int free_strs)
{
  /* *** deal with xmlns specifications in exc c14n way */

  zx_free_attr(c, x->RuleIdRef, free_strs);

  {
      struct zx_xa_CombinerParameter_s* e;
      struct zx_xa_CombinerParameter_s* en;
      for (e = x->CombinerParameter; e; e = en) {
	  en = (struct zx_xa_CombinerParameter_s*)e->gg.g.n;
	  zx_FREE_xa_CombinerParameter(c, e, free_strs);
      }
  }


  zx_free_elem_common(c, &x->gg, free_strs); 
}

/* FUNC(zx_NEW_xa_RuleCombinerParameters) */

/* Trivial allocator/constructor for the datatype. */

/* Called by: */
struct zx_xa_RuleCombinerParameters_s* zx_NEW_xa_RuleCombinerParameters(struct zx_ctx* c)
{
  struct zx_xa_RuleCombinerParameters_s* x = ZX_ZALLOC(c, struct zx_xa_RuleCombinerParameters_s);
  x->gg.g.tok = zx_xa_RuleCombinerParameters_ELEM;
  return x;
}

#ifdef ZX_ENA_AUX

/* FUNC(zx_DUP_STRS_xa_RuleCombinerParameters) */

/* Depth first traversal of data structure to copy its simple strings
 * to memory allocated from the memory allocator. The decoder will
 * use the underlying wireprotocol PDU buffer for strings, i.e.
 * strings are not copied - they point to the real data. If the
 * datastructure needs to outlast the protocol data or needs a different
 * memory allocation strategy, you need to call this function.  */

/* Called by: */
void zx_DUP_STRS_xa_RuleCombinerParameters(struct zx_ctx* c, struct zx_xa_RuleCombinerParameters_s* x)
{
  zx_dup_strs_common(c, &x->gg);
  /* *** deal with xmlns specifications in exc c14n way */

  zx_dup_attr(c, x->RuleIdRef);

  {
      struct zx_xa_CombinerParameter_s* e;
      for (e = x->CombinerParameter; e; e = (struct zx_xa_CombinerParameter_s*)e->gg.g.n)
	  zx_DUP_STRS_xa_CombinerParameter(c, e);
  }

}

/* FUNC(zx_DEEP_CLONE_xa_RuleCombinerParameters) */

/* Depth first traversal of data structure to clone it and its sublements.
 * The simple strings are handled as a special case according to dup_strs flag. */

/* Called by: */
struct zx_xa_RuleCombinerParameters_s* zx_DEEP_CLONE_xa_RuleCombinerParameters(struct zx_ctx* c, struct zx_xa_RuleCombinerParameters_s* x, int dup_strs)
{
  x = (struct zx_xa_RuleCombinerParameters_s*)zx_clone_elem_common(c, &x->gg, sizeof(struct zx_xa_RuleCombinerParameters_s), dup_strs);
  /* *** deal with xmlns specifications in exc c14n way */

  x->RuleIdRef = zx_clone_attr(c, x->RuleIdRef);

  {
      struct zx_xa_CombinerParameter_s* e;
      struct zx_xa_CombinerParameter_s* en;
      struct zx_xa_CombinerParameter_s* enn;
      for (enn = 0, e = x->CombinerParameter; e; e = (struct zx_xa_CombinerParameter_s*)e->gg.g.n) {
	  en = zx_DEEP_CLONE_xa_CombinerParameter(c, e, dup_strs);
	  if (!enn)
	      x->CombinerParameter = en;
	  else
	      enn->gg.g.n = &en->gg.g;
	  enn = en;
      }
  }

  return x;
}

/* FUNC(zx_WALK_SO_xa_RuleCombinerParameters) */

/* Depth first traversal of the tree in either schema order or the wire order. */
 
int zx_WALK_SO_xa_RuleCombinerParameters(struct zx_ctx* c, struct zx_xa_RuleCombinerParameters_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
{
  int ret = callback(&x->gg.g, ctx);
  if (ret)
    return ret;
  
  /* *** deal with xmlns specifications in exc c14n way */


  
  ret = zx_walk_so_unknown_attributes(c, &x->gg, ctx, callback); 
  if (ret)
    return ret;

  {
      struct zx_xa_CombinerParameter_s* e;
      for (e = x->CombinerParameter; e; e = (struct zx_xa_CombinerParameter_s*)e->gg.g.n) {
	  ret = zx_WALK_SO_xa_CombinerParameter(c, e, ctx, callback);
	  if (ret)
	      return ret;
      }
  }

  
  return zx_walk_so_unknown_elems_and_content(c, &x->gg, ctx, callback);
}

/* FUNC(zx_WALK_WO_xa_RuleCombinerParameters) */

int zx_WALK_WO_xa_RuleCombinerParameters(struct zx_ctx* c, struct zx_xa_RuleCombinerParameters_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
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

#define EL_NAME   xa_Subject
#define EL_STRUCT zx_xa_Subject_s
#define EL_NS     xa
#define EL_TAG    Subject

/* FUNC(zx_FREE_xa_Subject) */

/* Depth first traversal of data structure to free it and its subelements. Simple
 * strings are handled as a special case according to the free_strs flag. This
 * is useful if the strings point to underlying data from the wire that was
 * allocated differently. */

/* Called by: */
void zx_FREE_xa_Subject(struct zx_ctx* c, struct zx_xa_Subject_s* x, int free_strs)
{
  /* *** deal with xmlns specifications in exc c14n way */


  {
      struct zx_xa_SubjectMatch_s* e;
      struct zx_xa_SubjectMatch_s* en;
      for (e = x->SubjectMatch; e; e = en) {
	  en = (struct zx_xa_SubjectMatch_s*)e->gg.g.n;
	  zx_FREE_xa_SubjectMatch(c, e, free_strs);
      }
  }


  zx_free_elem_common(c, &x->gg, free_strs); 
}

/* FUNC(zx_NEW_xa_Subject) */

/* Trivial allocator/constructor for the datatype. */

/* Called by: */
struct zx_xa_Subject_s* zx_NEW_xa_Subject(struct zx_ctx* c)
{
  struct zx_xa_Subject_s* x = ZX_ZALLOC(c, struct zx_xa_Subject_s);
  x->gg.g.tok = zx_xa_Subject_ELEM;
  return x;
}

#ifdef ZX_ENA_AUX

/* FUNC(zx_DUP_STRS_xa_Subject) */

/* Depth first traversal of data structure to copy its simple strings
 * to memory allocated from the memory allocator. The decoder will
 * use the underlying wireprotocol PDU buffer for strings, i.e.
 * strings are not copied - they point to the real data. If the
 * datastructure needs to outlast the protocol data or needs a different
 * memory allocation strategy, you need to call this function.  */

/* Called by: */
void zx_DUP_STRS_xa_Subject(struct zx_ctx* c, struct zx_xa_Subject_s* x)
{
  zx_dup_strs_common(c, &x->gg);
  /* *** deal with xmlns specifications in exc c14n way */


  {
      struct zx_xa_SubjectMatch_s* e;
      for (e = x->SubjectMatch; e; e = (struct zx_xa_SubjectMatch_s*)e->gg.g.n)
	  zx_DUP_STRS_xa_SubjectMatch(c, e);
  }

}

/* FUNC(zx_DEEP_CLONE_xa_Subject) */

/* Depth first traversal of data structure to clone it and its sublements.
 * The simple strings are handled as a special case according to dup_strs flag. */

/* Called by: */
struct zx_xa_Subject_s* zx_DEEP_CLONE_xa_Subject(struct zx_ctx* c, struct zx_xa_Subject_s* x, int dup_strs)
{
  x = (struct zx_xa_Subject_s*)zx_clone_elem_common(c, &x->gg, sizeof(struct zx_xa_Subject_s), dup_strs);
  /* *** deal with xmlns specifications in exc c14n way */


  {
      struct zx_xa_SubjectMatch_s* e;
      struct zx_xa_SubjectMatch_s* en;
      struct zx_xa_SubjectMatch_s* enn;
      for (enn = 0, e = x->SubjectMatch; e; e = (struct zx_xa_SubjectMatch_s*)e->gg.g.n) {
	  en = zx_DEEP_CLONE_xa_SubjectMatch(c, e, dup_strs);
	  if (!enn)
	      x->SubjectMatch = en;
	  else
	      enn->gg.g.n = &en->gg.g;
	  enn = en;
      }
  }

  return x;
}

/* FUNC(zx_WALK_SO_xa_Subject) */

/* Depth first traversal of the tree in either schema order or the wire order. */
 
int zx_WALK_SO_xa_Subject(struct zx_ctx* c, struct zx_xa_Subject_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
{
  int ret = callback(&x->gg.g, ctx);
  if (ret)
    return ret;
  
  /* *** deal with xmlns specifications in exc c14n way */


  
  ret = zx_walk_so_unknown_attributes(c, &x->gg, ctx, callback); 
  if (ret)
    return ret;

  {
      struct zx_xa_SubjectMatch_s* e;
      for (e = x->SubjectMatch; e; e = (struct zx_xa_SubjectMatch_s*)e->gg.g.n) {
	  ret = zx_WALK_SO_xa_SubjectMatch(c, e, ctx, callback);
	  if (ret)
	      return ret;
      }
  }

  
  return zx_walk_so_unknown_elems_and_content(c, &x->gg, ctx, callback);
}

/* FUNC(zx_WALK_WO_xa_Subject) */

int zx_WALK_WO_xa_Subject(struct zx_ctx* c, struct zx_xa_Subject_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
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

#define EL_NAME   xa_SubjectAttributeDesignator
#define EL_STRUCT zx_xa_SubjectAttributeDesignator_s
#define EL_NS     xa
#define EL_TAG    SubjectAttributeDesignator

/* FUNC(zx_FREE_xa_SubjectAttributeDesignator) */

/* Depth first traversal of data structure to free it and its subelements. Simple
 * strings are handled as a special case according to the free_strs flag. This
 * is useful if the strings point to underlying data from the wire that was
 * allocated differently. */

/* Called by: */
void zx_FREE_xa_SubjectAttributeDesignator(struct zx_ctx* c, struct zx_xa_SubjectAttributeDesignator_s* x, int free_strs)
{
  /* *** deal with xmlns specifications in exc c14n way */

  zx_free_attr(c, x->AttributeId, free_strs);
  zx_free_attr(c, x->DataType, free_strs);
  zx_free_attr(c, x->Issuer, free_strs);
  zx_free_attr(c, x->MustBePresent, free_strs);
  zx_free_attr(c, x->SubjectCategory, free_strs);



  zx_free_elem_common(c, &x->gg, free_strs); 
}

/* FUNC(zx_NEW_xa_SubjectAttributeDesignator) */

/* Trivial allocator/constructor for the datatype. */

/* Called by: */
struct zx_xa_SubjectAttributeDesignator_s* zx_NEW_xa_SubjectAttributeDesignator(struct zx_ctx* c)
{
  struct zx_xa_SubjectAttributeDesignator_s* x = ZX_ZALLOC(c, struct zx_xa_SubjectAttributeDesignator_s);
  x->gg.g.tok = zx_xa_SubjectAttributeDesignator_ELEM;
  return x;
}

#ifdef ZX_ENA_AUX

/* FUNC(zx_DUP_STRS_xa_SubjectAttributeDesignator) */

/* Depth first traversal of data structure to copy its simple strings
 * to memory allocated from the memory allocator. The decoder will
 * use the underlying wireprotocol PDU buffer for strings, i.e.
 * strings are not copied - they point to the real data. If the
 * datastructure needs to outlast the protocol data or needs a different
 * memory allocation strategy, you need to call this function.  */

/* Called by: */
void zx_DUP_STRS_xa_SubjectAttributeDesignator(struct zx_ctx* c, struct zx_xa_SubjectAttributeDesignator_s* x)
{
  zx_dup_strs_common(c, &x->gg);
  /* *** deal with xmlns specifications in exc c14n way */

  zx_dup_attr(c, x->AttributeId);
  zx_dup_attr(c, x->DataType);
  zx_dup_attr(c, x->Issuer);
  zx_dup_attr(c, x->MustBePresent);
  zx_dup_attr(c, x->SubjectCategory);


}

/* FUNC(zx_DEEP_CLONE_xa_SubjectAttributeDesignator) */

/* Depth first traversal of data structure to clone it and its sublements.
 * The simple strings are handled as a special case according to dup_strs flag. */

/* Called by: */
struct zx_xa_SubjectAttributeDesignator_s* zx_DEEP_CLONE_xa_SubjectAttributeDesignator(struct zx_ctx* c, struct zx_xa_SubjectAttributeDesignator_s* x, int dup_strs)
{
  x = (struct zx_xa_SubjectAttributeDesignator_s*)zx_clone_elem_common(c, &x->gg, sizeof(struct zx_xa_SubjectAttributeDesignator_s), dup_strs);
  /* *** deal with xmlns specifications in exc c14n way */

  x->AttributeId = zx_clone_attr(c, x->AttributeId);
  x->DataType = zx_clone_attr(c, x->DataType);
  x->Issuer = zx_clone_attr(c, x->Issuer);
  x->MustBePresent = zx_clone_attr(c, x->MustBePresent);
  x->SubjectCategory = zx_clone_attr(c, x->SubjectCategory);


  return x;
}

/* FUNC(zx_WALK_SO_xa_SubjectAttributeDesignator) */

/* Depth first traversal of the tree in either schema order or the wire order. */
 
int zx_WALK_SO_xa_SubjectAttributeDesignator(struct zx_ctx* c, struct zx_xa_SubjectAttributeDesignator_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
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

/* FUNC(zx_WALK_WO_xa_SubjectAttributeDesignator) */

int zx_WALK_WO_xa_SubjectAttributeDesignator(struct zx_ctx* c, struct zx_xa_SubjectAttributeDesignator_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
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

#define EL_NAME   xa_SubjectMatch
#define EL_STRUCT zx_xa_SubjectMatch_s
#define EL_NS     xa
#define EL_TAG    SubjectMatch

/* FUNC(zx_FREE_xa_SubjectMatch) */

/* Depth first traversal of data structure to free it and its subelements. Simple
 * strings are handled as a special case according to the free_strs flag. This
 * is useful if the strings point to underlying data from the wire that was
 * allocated differently. */

/* Called by: */
void zx_FREE_xa_SubjectMatch(struct zx_ctx* c, struct zx_xa_SubjectMatch_s* x, int free_strs)
{
  /* *** deal with xmlns specifications in exc c14n way */

  zx_free_attr(c, x->MatchId, free_strs);

  {
      struct zx_xa_AttributeValue_s* e;
      struct zx_xa_AttributeValue_s* en;
      for (e = x->AttributeValue; e; e = en) {
	  en = (struct zx_xa_AttributeValue_s*)e->gg.g.n;
	  zx_FREE_xa_AttributeValue(c, e, free_strs);
      }
  }
  {
      struct zx_xa_SubjectAttributeDesignator_s* e;
      struct zx_xa_SubjectAttributeDesignator_s* en;
      for (e = x->SubjectAttributeDesignator; e; e = en) {
	  en = (struct zx_xa_SubjectAttributeDesignator_s*)e->gg.g.n;
	  zx_FREE_xa_SubjectAttributeDesignator(c, e, free_strs);
      }
  }
  {
      struct zx_xa_AttributeSelector_s* e;
      struct zx_xa_AttributeSelector_s* en;
      for (e = x->AttributeSelector; e; e = en) {
	  en = (struct zx_xa_AttributeSelector_s*)e->gg.g.n;
	  zx_FREE_xa_AttributeSelector(c, e, free_strs);
      }
  }


  zx_free_elem_common(c, &x->gg, free_strs); 
}

/* FUNC(zx_NEW_xa_SubjectMatch) */

/* Trivial allocator/constructor for the datatype. */

/* Called by: */
struct zx_xa_SubjectMatch_s* zx_NEW_xa_SubjectMatch(struct zx_ctx* c)
{
  struct zx_xa_SubjectMatch_s* x = ZX_ZALLOC(c, struct zx_xa_SubjectMatch_s);
  x->gg.g.tok = zx_xa_SubjectMatch_ELEM;
  return x;
}

#ifdef ZX_ENA_AUX

/* FUNC(zx_DUP_STRS_xa_SubjectMatch) */

/* Depth first traversal of data structure to copy its simple strings
 * to memory allocated from the memory allocator. The decoder will
 * use the underlying wireprotocol PDU buffer for strings, i.e.
 * strings are not copied - they point to the real data. If the
 * datastructure needs to outlast the protocol data or needs a different
 * memory allocation strategy, you need to call this function.  */

/* Called by: */
void zx_DUP_STRS_xa_SubjectMatch(struct zx_ctx* c, struct zx_xa_SubjectMatch_s* x)
{
  zx_dup_strs_common(c, &x->gg);
  /* *** deal with xmlns specifications in exc c14n way */

  zx_dup_attr(c, x->MatchId);

  {
      struct zx_xa_AttributeValue_s* e;
      for (e = x->AttributeValue; e; e = (struct zx_xa_AttributeValue_s*)e->gg.g.n)
	  zx_DUP_STRS_xa_AttributeValue(c, e);
  }
  {
      struct zx_xa_SubjectAttributeDesignator_s* e;
      for (e = x->SubjectAttributeDesignator; e; e = (struct zx_xa_SubjectAttributeDesignator_s*)e->gg.g.n)
	  zx_DUP_STRS_xa_SubjectAttributeDesignator(c, e);
  }
  {
      struct zx_xa_AttributeSelector_s* e;
      for (e = x->AttributeSelector; e; e = (struct zx_xa_AttributeSelector_s*)e->gg.g.n)
	  zx_DUP_STRS_xa_AttributeSelector(c, e);
  }

}

/* FUNC(zx_DEEP_CLONE_xa_SubjectMatch) */

/* Depth first traversal of data structure to clone it and its sublements.
 * The simple strings are handled as a special case according to dup_strs flag. */

/* Called by: */
struct zx_xa_SubjectMatch_s* zx_DEEP_CLONE_xa_SubjectMatch(struct zx_ctx* c, struct zx_xa_SubjectMatch_s* x, int dup_strs)
{
  x = (struct zx_xa_SubjectMatch_s*)zx_clone_elem_common(c, &x->gg, sizeof(struct zx_xa_SubjectMatch_s), dup_strs);
  /* *** deal with xmlns specifications in exc c14n way */

  x->MatchId = zx_clone_attr(c, x->MatchId);

  {
      struct zx_xa_AttributeValue_s* e;
      struct zx_xa_AttributeValue_s* en;
      struct zx_xa_AttributeValue_s* enn;
      for (enn = 0, e = x->AttributeValue; e; e = (struct zx_xa_AttributeValue_s*)e->gg.g.n) {
	  en = zx_DEEP_CLONE_xa_AttributeValue(c, e, dup_strs);
	  if (!enn)
	      x->AttributeValue = en;
	  else
	      enn->gg.g.n = &en->gg.g;
	  enn = en;
      }
  }
  {
      struct zx_xa_SubjectAttributeDesignator_s* e;
      struct zx_xa_SubjectAttributeDesignator_s* en;
      struct zx_xa_SubjectAttributeDesignator_s* enn;
      for (enn = 0, e = x->SubjectAttributeDesignator; e; e = (struct zx_xa_SubjectAttributeDesignator_s*)e->gg.g.n) {
	  en = zx_DEEP_CLONE_xa_SubjectAttributeDesignator(c, e, dup_strs);
	  if (!enn)
	      x->SubjectAttributeDesignator = en;
	  else
	      enn->gg.g.n = &en->gg.g;
	  enn = en;
      }
  }
  {
      struct zx_xa_AttributeSelector_s* e;
      struct zx_xa_AttributeSelector_s* en;
      struct zx_xa_AttributeSelector_s* enn;
      for (enn = 0, e = x->AttributeSelector; e; e = (struct zx_xa_AttributeSelector_s*)e->gg.g.n) {
	  en = zx_DEEP_CLONE_xa_AttributeSelector(c, e, dup_strs);
	  if (!enn)
	      x->AttributeSelector = en;
	  else
	      enn->gg.g.n = &en->gg.g;
	  enn = en;
      }
  }

  return x;
}

/* FUNC(zx_WALK_SO_xa_SubjectMatch) */

/* Depth first traversal of the tree in either schema order or the wire order. */
 
int zx_WALK_SO_xa_SubjectMatch(struct zx_ctx* c, struct zx_xa_SubjectMatch_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
{
  int ret = callback(&x->gg.g, ctx);
  if (ret)
    return ret;
  
  /* *** deal with xmlns specifications in exc c14n way */


  
  ret = zx_walk_so_unknown_attributes(c, &x->gg, ctx, callback); 
  if (ret)
    return ret;

  {
      struct zx_xa_AttributeValue_s* e;
      for (e = x->AttributeValue; e; e = (struct zx_xa_AttributeValue_s*)e->gg.g.n) {
	  ret = zx_WALK_SO_xa_AttributeValue(c, e, ctx, callback);
	  if (ret)
	      return ret;
      }
  }
  {
      struct zx_xa_SubjectAttributeDesignator_s* e;
      for (e = x->SubjectAttributeDesignator; e; e = (struct zx_xa_SubjectAttributeDesignator_s*)e->gg.g.n) {
	  ret = zx_WALK_SO_xa_SubjectAttributeDesignator(c, e, ctx, callback);
	  if (ret)
	      return ret;
      }
  }
  {
      struct zx_xa_AttributeSelector_s* e;
      for (e = x->AttributeSelector; e; e = (struct zx_xa_AttributeSelector_s*)e->gg.g.n) {
	  ret = zx_WALK_SO_xa_AttributeSelector(c, e, ctx, callback);
	  if (ret)
	      return ret;
      }
  }

  
  return zx_walk_so_unknown_elems_and_content(c, &x->gg, ctx, callback);
}

/* FUNC(zx_WALK_WO_xa_SubjectMatch) */

int zx_WALK_WO_xa_SubjectMatch(struct zx_ctx* c, struct zx_xa_SubjectMatch_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
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

#define EL_NAME   xa_Subjects
#define EL_STRUCT zx_xa_Subjects_s
#define EL_NS     xa
#define EL_TAG    Subjects

/* FUNC(zx_FREE_xa_Subjects) */

/* Depth first traversal of data structure to free it and its subelements. Simple
 * strings are handled as a special case according to the free_strs flag. This
 * is useful if the strings point to underlying data from the wire that was
 * allocated differently. */

/* Called by: */
void zx_FREE_xa_Subjects(struct zx_ctx* c, struct zx_xa_Subjects_s* x, int free_strs)
{
  /* *** deal with xmlns specifications in exc c14n way */


  {
      struct zx_xa_Subject_s* e;
      struct zx_xa_Subject_s* en;
      for (e = x->Subject; e; e = en) {
	  en = (struct zx_xa_Subject_s*)e->gg.g.n;
	  zx_FREE_xa_Subject(c, e, free_strs);
      }
  }


  zx_free_elem_common(c, &x->gg, free_strs); 
}

/* FUNC(zx_NEW_xa_Subjects) */

/* Trivial allocator/constructor for the datatype. */

/* Called by: */
struct zx_xa_Subjects_s* zx_NEW_xa_Subjects(struct zx_ctx* c)
{
  struct zx_xa_Subjects_s* x = ZX_ZALLOC(c, struct zx_xa_Subjects_s);
  x->gg.g.tok = zx_xa_Subjects_ELEM;
  return x;
}

#ifdef ZX_ENA_AUX

/* FUNC(zx_DUP_STRS_xa_Subjects) */

/* Depth first traversal of data structure to copy its simple strings
 * to memory allocated from the memory allocator. The decoder will
 * use the underlying wireprotocol PDU buffer for strings, i.e.
 * strings are not copied - they point to the real data. If the
 * datastructure needs to outlast the protocol data or needs a different
 * memory allocation strategy, you need to call this function.  */

/* Called by: */
void zx_DUP_STRS_xa_Subjects(struct zx_ctx* c, struct zx_xa_Subjects_s* x)
{
  zx_dup_strs_common(c, &x->gg);
  /* *** deal with xmlns specifications in exc c14n way */


  {
      struct zx_xa_Subject_s* e;
      for (e = x->Subject; e; e = (struct zx_xa_Subject_s*)e->gg.g.n)
	  zx_DUP_STRS_xa_Subject(c, e);
  }

}

/* FUNC(zx_DEEP_CLONE_xa_Subjects) */

/* Depth first traversal of data structure to clone it and its sublements.
 * The simple strings are handled as a special case according to dup_strs flag. */

/* Called by: */
struct zx_xa_Subjects_s* zx_DEEP_CLONE_xa_Subjects(struct zx_ctx* c, struct zx_xa_Subjects_s* x, int dup_strs)
{
  x = (struct zx_xa_Subjects_s*)zx_clone_elem_common(c, &x->gg, sizeof(struct zx_xa_Subjects_s), dup_strs);
  /* *** deal with xmlns specifications in exc c14n way */


  {
      struct zx_xa_Subject_s* e;
      struct zx_xa_Subject_s* en;
      struct zx_xa_Subject_s* enn;
      for (enn = 0, e = x->Subject; e; e = (struct zx_xa_Subject_s*)e->gg.g.n) {
	  en = zx_DEEP_CLONE_xa_Subject(c, e, dup_strs);
	  if (!enn)
	      x->Subject = en;
	  else
	      enn->gg.g.n = &en->gg.g;
	  enn = en;
      }
  }

  return x;
}

/* FUNC(zx_WALK_SO_xa_Subjects) */

/* Depth first traversal of the tree in either schema order or the wire order. */
 
int zx_WALK_SO_xa_Subjects(struct zx_ctx* c, struct zx_xa_Subjects_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
{
  int ret = callback(&x->gg.g, ctx);
  if (ret)
    return ret;
  
  /* *** deal with xmlns specifications in exc c14n way */


  
  ret = zx_walk_so_unknown_attributes(c, &x->gg, ctx, callback); 
  if (ret)
    return ret;

  {
      struct zx_xa_Subject_s* e;
      for (e = x->Subject; e; e = (struct zx_xa_Subject_s*)e->gg.g.n) {
	  ret = zx_WALK_SO_xa_Subject(c, e, ctx, callback);
	  if (ret)
	      return ret;
      }
  }

  
  return zx_walk_so_unknown_elems_and_content(c, &x->gg, ctx, callback);
}

/* FUNC(zx_WALK_WO_xa_Subjects) */

int zx_WALK_WO_xa_Subjects(struct zx_ctx* c, struct zx_xa_Subjects_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
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

#define EL_NAME   xa_Target
#define EL_STRUCT zx_xa_Target_s
#define EL_NS     xa
#define EL_TAG    Target

/* FUNC(zx_FREE_xa_Target) */

/* Depth first traversal of data structure to free it and its subelements. Simple
 * strings are handled as a special case according to the free_strs flag. This
 * is useful if the strings point to underlying data from the wire that was
 * allocated differently. */

/* Called by: */
void zx_FREE_xa_Target(struct zx_ctx* c, struct zx_xa_Target_s* x, int free_strs)
{
  /* *** deal with xmlns specifications in exc c14n way */


  {
      struct zx_xa_Subjects_s* e;
      struct zx_xa_Subjects_s* en;
      for (e = x->Subjects; e; e = en) {
	  en = (struct zx_xa_Subjects_s*)e->gg.g.n;
	  zx_FREE_xa_Subjects(c, e, free_strs);
      }
  }
  {
      struct zx_xa_Resources_s* e;
      struct zx_xa_Resources_s* en;
      for (e = x->Resources; e; e = en) {
	  en = (struct zx_xa_Resources_s*)e->gg.g.n;
	  zx_FREE_xa_Resources(c, e, free_strs);
      }
  }
  {
      struct zx_xa_Actions_s* e;
      struct zx_xa_Actions_s* en;
      for (e = x->Actions; e; e = en) {
	  en = (struct zx_xa_Actions_s*)e->gg.g.n;
	  zx_FREE_xa_Actions(c, e, free_strs);
      }
  }
  {
      struct zx_xa_Environments_s* e;
      struct zx_xa_Environments_s* en;
      for (e = x->Environments; e; e = en) {
	  en = (struct zx_xa_Environments_s*)e->gg.g.n;
	  zx_FREE_xa_Environments(c, e, free_strs);
      }
  }


  zx_free_elem_common(c, &x->gg, free_strs); 
}

/* FUNC(zx_NEW_xa_Target) */

/* Trivial allocator/constructor for the datatype. */

/* Called by: */
struct zx_xa_Target_s* zx_NEW_xa_Target(struct zx_ctx* c)
{
  struct zx_xa_Target_s* x = ZX_ZALLOC(c, struct zx_xa_Target_s);
  x->gg.g.tok = zx_xa_Target_ELEM;
  return x;
}

#ifdef ZX_ENA_AUX

/* FUNC(zx_DUP_STRS_xa_Target) */

/* Depth first traversal of data structure to copy its simple strings
 * to memory allocated from the memory allocator. The decoder will
 * use the underlying wireprotocol PDU buffer for strings, i.e.
 * strings are not copied - they point to the real data. If the
 * datastructure needs to outlast the protocol data or needs a different
 * memory allocation strategy, you need to call this function.  */

/* Called by: */
void zx_DUP_STRS_xa_Target(struct zx_ctx* c, struct zx_xa_Target_s* x)
{
  zx_dup_strs_common(c, &x->gg);
  /* *** deal with xmlns specifications in exc c14n way */


  {
      struct zx_xa_Subjects_s* e;
      for (e = x->Subjects; e; e = (struct zx_xa_Subjects_s*)e->gg.g.n)
	  zx_DUP_STRS_xa_Subjects(c, e);
  }
  {
      struct zx_xa_Resources_s* e;
      for (e = x->Resources; e; e = (struct zx_xa_Resources_s*)e->gg.g.n)
	  zx_DUP_STRS_xa_Resources(c, e);
  }
  {
      struct zx_xa_Actions_s* e;
      for (e = x->Actions; e; e = (struct zx_xa_Actions_s*)e->gg.g.n)
	  zx_DUP_STRS_xa_Actions(c, e);
  }
  {
      struct zx_xa_Environments_s* e;
      for (e = x->Environments; e; e = (struct zx_xa_Environments_s*)e->gg.g.n)
	  zx_DUP_STRS_xa_Environments(c, e);
  }

}

/* FUNC(zx_DEEP_CLONE_xa_Target) */

/* Depth first traversal of data structure to clone it and its sublements.
 * The simple strings are handled as a special case according to dup_strs flag. */

/* Called by: */
struct zx_xa_Target_s* zx_DEEP_CLONE_xa_Target(struct zx_ctx* c, struct zx_xa_Target_s* x, int dup_strs)
{
  x = (struct zx_xa_Target_s*)zx_clone_elem_common(c, &x->gg, sizeof(struct zx_xa_Target_s), dup_strs);
  /* *** deal with xmlns specifications in exc c14n way */


  {
      struct zx_xa_Subjects_s* e;
      struct zx_xa_Subjects_s* en;
      struct zx_xa_Subjects_s* enn;
      for (enn = 0, e = x->Subjects; e; e = (struct zx_xa_Subjects_s*)e->gg.g.n) {
	  en = zx_DEEP_CLONE_xa_Subjects(c, e, dup_strs);
	  if (!enn)
	      x->Subjects = en;
	  else
	      enn->gg.g.n = &en->gg.g;
	  enn = en;
      }
  }
  {
      struct zx_xa_Resources_s* e;
      struct zx_xa_Resources_s* en;
      struct zx_xa_Resources_s* enn;
      for (enn = 0, e = x->Resources; e; e = (struct zx_xa_Resources_s*)e->gg.g.n) {
	  en = zx_DEEP_CLONE_xa_Resources(c, e, dup_strs);
	  if (!enn)
	      x->Resources = en;
	  else
	      enn->gg.g.n = &en->gg.g;
	  enn = en;
      }
  }
  {
      struct zx_xa_Actions_s* e;
      struct zx_xa_Actions_s* en;
      struct zx_xa_Actions_s* enn;
      for (enn = 0, e = x->Actions; e; e = (struct zx_xa_Actions_s*)e->gg.g.n) {
	  en = zx_DEEP_CLONE_xa_Actions(c, e, dup_strs);
	  if (!enn)
	      x->Actions = en;
	  else
	      enn->gg.g.n = &en->gg.g;
	  enn = en;
      }
  }
  {
      struct zx_xa_Environments_s* e;
      struct zx_xa_Environments_s* en;
      struct zx_xa_Environments_s* enn;
      for (enn = 0, e = x->Environments; e; e = (struct zx_xa_Environments_s*)e->gg.g.n) {
	  en = zx_DEEP_CLONE_xa_Environments(c, e, dup_strs);
	  if (!enn)
	      x->Environments = en;
	  else
	      enn->gg.g.n = &en->gg.g;
	  enn = en;
      }
  }

  return x;
}

/* FUNC(zx_WALK_SO_xa_Target) */

/* Depth first traversal of the tree in either schema order or the wire order. */
 
int zx_WALK_SO_xa_Target(struct zx_ctx* c, struct zx_xa_Target_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
{
  int ret = callback(&x->gg.g, ctx);
  if (ret)
    return ret;
  
  /* *** deal with xmlns specifications in exc c14n way */


  
  ret = zx_walk_so_unknown_attributes(c, &x->gg, ctx, callback); 
  if (ret)
    return ret;

  {
      struct zx_xa_Subjects_s* e;
      for (e = x->Subjects; e; e = (struct zx_xa_Subjects_s*)e->gg.g.n) {
	  ret = zx_WALK_SO_xa_Subjects(c, e, ctx, callback);
	  if (ret)
	      return ret;
      }
  }
  {
      struct zx_xa_Resources_s* e;
      for (e = x->Resources; e; e = (struct zx_xa_Resources_s*)e->gg.g.n) {
	  ret = zx_WALK_SO_xa_Resources(c, e, ctx, callback);
	  if (ret)
	      return ret;
      }
  }
  {
      struct zx_xa_Actions_s* e;
      for (e = x->Actions; e; e = (struct zx_xa_Actions_s*)e->gg.g.n) {
	  ret = zx_WALK_SO_xa_Actions(c, e, ctx, callback);
	  if (ret)
	      return ret;
      }
  }
  {
      struct zx_xa_Environments_s* e;
      for (e = x->Environments; e; e = (struct zx_xa_Environments_s*)e->gg.g.n) {
	  ret = zx_WALK_SO_xa_Environments(c, e, ctx, callback);
	  if (ret)
	      return ret;
      }
  }

  
  return zx_walk_so_unknown_elems_and_content(c, &x->gg, ctx, callback);
}

/* FUNC(zx_WALK_WO_xa_Target) */

int zx_WALK_WO_xa_Target(struct zx_ctx* c, struct zx_xa_Target_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
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

#define EL_NAME   xa_VariableDefinition
#define EL_STRUCT zx_xa_VariableDefinition_s
#define EL_NS     xa
#define EL_TAG    VariableDefinition

/* FUNC(zx_FREE_xa_VariableDefinition) */

/* Depth first traversal of data structure to free it and its subelements. Simple
 * strings are handled as a special case according to the free_strs flag. This
 * is useful if the strings point to underlying data from the wire that was
 * allocated differently. */

/* Called by: */
void zx_FREE_xa_VariableDefinition(struct zx_ctx* c, struct zx_xa_VariableDefinition_s* x, int free_strs)
{
  /* *** deal with xmlns specifications in exc c14n way */

  zx_free_attr(c, x->VariableId, free_strs);

  zx_free_simple_elems(c, x->Expression, free_strs);


  zx_free_elem_common(c, &x->gg, free_strs); 
}

/* FUNC(zx_NEW_xa_VariableDefinition) */

/* Trivial allocator/constructor for the datatype. */

/* Called by: */
struct zx_xa_VariableDefinition_s* zx_NEW_xa_VariableDefinition(struct zx_ctx* c)
{
  struct zx_xa_VariableDefinition_s* x = ZX_ZALLOC(c, struct zx_xa_VariableDefinition_s);
  x->gg.g.tok = zx_xa_VariableDefinition_ELEM;
  return x;
}

#ifdef ZX_ENA_AUX

/* FUNC(zx_DUP_STRS_xa_VariableDefinition) */

/* Depth first traversal of data structure to copy its simple strings
 * to memory allocated from the memory allocator. The decoder will
 * use the underlying wireprotocol PDU buffer for strings, i.e.
 * strings are not copied - they point to the real data. If the
 * datastructure needs to outlast the protocol data or needs a different
 * memory allocation strategy, you need to call this function.  */

/* Called by: */
void zx_DUP_STRS_xa_VariableDefinition(struct zx_ctx* c, struct zx_xa_VariableDefinition_s* x)
{
  zx_dup_strs_common(c, &x->gg);
  /* *** deal with xmlns specifications in exc c14n way */

  zx_dup_attr(c, x->VariableId);

  zx_dup_strs_simple_elems(c, x->Expression);

}

/* FUNC(zx_DEEP_CLONE_xa_VariableDefinition) */

/* Depth first traversal of data structure to clone it and its sublements.
 * The simple strings are handled as a special case according to dup_strs flag. */

/* Called by: */
struct zx_xa_VariableDefinition_s* zx_DEEP_CLONE_xa_VariableDefinition(struct zx_ctx* c, struct zx_xa_VariableDefinition_s* x, int dup_strs)
{
  x = (struct zx_xa_VariableDefinition_s*)zx_clone_elem_common(c, &x->gg, sizeof(struct zx_xa_VariableDefinition_s), dup_strs);
  /* *** deal with xmlns specifications in exc c14n way */

  x->VariableId = zx_clone_attr(c, x->VariableId);

  x->Expression = zx_deep_clone_simple_elems(c,x->Expression, dup_strs);

  return x;
}

/* FUNC(zx_WALK_SO_xa_VariableDefinition) */

/* Depth first traversal of the tree in either schema order or the wire order. */
 
int zx_WALK_SO_xa_VariableDefinition(struct zx_ctx* c, struct zx_xa_VariableDefinition_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
{
  int ret = callback(&x->gg.g, ctx);
  if (ret)
    return ret;
  
  /* *** deal with xmlns specifications in exc c14n way */


  
  ret = zx_walk_so_unknown_attributes(c, &x->gg, ctx, callback); 
  if (ret)
    return ret;

  ret = zx_walk_so_simple_elems(c, x->Expression, ctx, callback);
  if (ret)
    return ret;

  
  return zx_walk_so_unknown_elems_and_content(c, &x->gg, ctx, callback);
}

/* FUNC(zx_WALK_WO_xa_VariableDefinition) */

int zx_WALK_WO_xa_VariableDefinition(struct zx_ctx* c, struct zx_xa_VariableDefinition_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
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

#define EL_NAME   xa_VariableReference
#define EL_STRUCT zx_xa_VariableReference_s
#define EL_NS     xa
#define EL_TAG    VariableReference

/* FUNC(zx_FREE_xa_VariableReference) */

/* Depth first traversal of data structure to free it and its subelements. Simple
 * strings are handled as a special case according to the free_strs flag. This
 * is useful if the strings point to underlying data from the wire that was
 * allocated differently. */

/* Called by: */
void zx_FREE_xa_VariableReference(struct zx_ctx* c, struct zx_xa_VariableReference_s* x, int free_strs)
{
  /* *** deal with xmlns specifications in exc c14n way */

  zx_free_attr(c, x->VariableId, free_strs);



  zx_free_elem_common(c, &x->gg, free_strs); 
}

/* FUNC(zx_NEW_xa_VariableReference) */

/* Trivial allocator/constructor for the datatype. */

/* Called by: */
struct zx_xa_VariableReference_s* zx_NEW_xa_VariableReference(struct zx_ctx* c)
{
  struct zx_xa_VariableReference_s* x = ZX_ZALLOC(c, struct zx_xa_VariableReference_s);
  x->gg.g.tok = zx_xa_VariableReference_ELEM;
  return x;
}

#ifdef ZX_ENA_AUX

/* FUNC(zx_DUP_STRS_xa_VariableReference) */

/* Depth first traversal of data structure to copy its simple strings
 * to memory allocated from the memory allocator. The decoder will
 * use the underlying wireprotocol PDU buffer for strings, i.e.
 * strings are not copied - they point to the real data. If the
 * datastructure needs to outlast the protocol data or needs a different
 * memory allocation strategy, you need to call this function.  */

/* Called by: */
void zx_DUP_STRS_xa_VariableReference(struct zx_ctx* c, struct zx_xa_VariableReference_s* x)
{
  zx_dup_strs_common(c, &x->gg);
  /* *** deal with xmlns specifications in exc c14n way */

  zx_dup_attr(c, x->VariableId);


}

/* FUNC(zx_DEEP_CLONE_xa_VariableReference) */

/* Depth first traversal of data structure to clone it and its sublements.
 * The simple strings are handled as a special case according to dup_strs flag. */

/* Called by: */
struct zx_xa_VariableReference_s* zx_DEEP_CLONE_xa_VariableReference(struct zx_ctx* c, struct zx_xa_VariableReference_s* x, int dup_strs)
{
  x = (struct zx_xa_VariableReference_s*)zx_clone_elem_common(c, &x->gg, sizeof(struct zx_xa_VariableReference_s), dup_strs);
  /* *** deal with xmlns specifications in exc c14n way */

  x->VariableId = zx_clone_attr(c, x->VariableId);


  return x;
}

/* FUNC(zx_WALK_SO_xa_VariableReference) */

/* Depth first traversal of the tree in either schema order or the wire order. */
 
int zx_WALK_SO_xa_VariableReference(struct zx_ctx* c, struct zx_xa_VariableReference_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
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

/* FUNC(zx_WALK_WO_xa_VariableReference) */

int zx_WALK_WO_xa_VariableReference(struct zx_ctx* c, struct zx_xa_VariableReference_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
{
  ERR("*** walk_wo not implemented %d", 0);
  return 0;
}

#endif


/* EOF -- c/zx-xa-aux.c */
