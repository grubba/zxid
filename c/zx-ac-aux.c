/* c/zx-ac-aux.c - WARNING: This file was automatically generated. DO NOT EDIT!
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
#include "c/zx-ac-data.h"



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

#define EL_NAME   ac_ActivationLimit
#define EL_STRUCT zx_ac_ActivationLimit_s
#define EL_NS     ac
#define EL_TAG    ActivationLimit

/* FUNC(zx_FREE_ac_ActivationLimit) */

/* Depth first traversal of data structure to free it and its subelements. Simple
 * strings are handled as a special case according to the free_strs flag. This
 * is useful if the strings point to underlying data from the wire that was
 * allocated differently. */

/* Called by: */
void zx_FREE_ac_ActivationLimit(struct zx_ctx* c, struct zx_ac_ActivationLimit_s* x, int free_strs)
{
  /* *** deal with xmlns specifications in exc c14n way */


  {
      struct zx_ac_ActivationLimitDuration_s* e;
      struct zx_ac_ActivationLimitDuration_s* en;
      for (e = x->ActivationLimitDuration; e; e = en) {
	  en = (struct zx_ac_ActivationLimitDuration_s*)e->gg.g.n;
	  zx_FREE_ac_ActivationLimitDuration(c, e, free_strs);
      }
  }
  {
      struct zx_ac_ActivationLimitUsages_s* e;
      struct zx_ac_ActivationLimitUsages_s* en;
      for (e = x->ActivationLimitUsages; e; e = en) {
	  en = (struct zx_ac_ActivationLimitUsages_s*)e->gg.g.n;
	  zx_FREE_ac_ActivationLimitUsages(c, e, free_strs);
      }
  }
  zx_free_simple_elems(c, x->ActivationLimitSession, free_strs);


  zx_free_elem_common(c, &x->gg, free_strs); 
}

/* FUNC(zx_NEW_ac_ActivationLimit) */

/* Trivial allocator/constructor for the datatype. */

/* Called by: */
struct zx_ac_ActivationLimit_s* zx_NEW_ac_ActivationLimit(struct zx_ctx* c)
{
  struct zx_ac_ActivationLimit_s* x = ZX_ZALLOC(c, struct zx_ac_ActivationLimit_s);
  x->gg.g.tok = zx_ac_ActivationLimit_ELEM;
  return x;
}

#ifdef ZX_ENA_AUX

/* FUNC(zx_DUP_STRS_ac_ActivationLimit) */

/* Depth first traversal of data structure to copy its simple strings
 * to memory allocated from the memory allocator. The decoder will
 * use the underlying wireprotocol PDU buffer for strings, i.e.
 * strings are not copied - they point to the real data. If the
 * datastructure needs to outlast the protocol data or needs a different
 * memory allocation strategy, you need to call this function.  */

/* Called by: */
void zx_DUP_STRS_ac_ActivationLimit(struct zx_ctx* c, struct zx_ac_ActivationLimit_s* x)
{
  zx_dup_strs_common(c, &x->gg);
  /* *** deal with xmlns specifications in exc c14n way */


  {
      struct zx_ac_ActivationLimitDuration_s* e;
      for (e = x->ActivationLimitDuration; e; e = (struct zx_ac_ActivationLimitDuration_s*)e->gg.g.n)
	  zx_DUP_STRS_ac_ActivationLimitDuration(c, e);
  }
  {
      struct zx_ac_ActivationLimitUsages_s* e;
      for (e = x->ActivationLimitUsages; e; e = (struct zx_ac_ActivationLimitUsages_s*)e->gg.g.n)
	  zx_DUP_STRS_ac_ActivationLimitUsages(c, e);
  }
  zx_dup_strs_simple_elems(c, x->ActivationLimitSession);

}

/* FUNC(zx_DEEP_CLONE_ac_ActivationLimit) */

/* Depth first traversal of data structure to clone it and its sublements.
 * The simple strings are handled as a special case according to dup_strs flag. */

/* Called by: */
struct zx_ac_ActivationLimit_s* zx_DEEP_CLONE_ac_ActivationLimit(struct zx_ctx* c, struct zx_ac_ActivationLimit_s* x, int dup_strs)
{
  x = (struct zx_ac_ActivationLimit_s*)zx_clone_elem_common(c, &x->gg, sizeof(struct zx_ac_ActivationLimit_s), dup_strs);
  /* *** deal with xmlns specifications in exc c14n way */


  {
      struct zx_ac_ActivationLimitDuration_s* e;
      struct zx_ac_ActivationLimitDuration_s* en;
      struct zx_ac_ActivationLimitDuration_s* enn;
      for (enn = 0, e = x->ActivationLimitDuration; e; e = (struct zx_ac_ActivationLimitDuration_s*)e->gg.g.n) {
	  en = zx_DEEP_CLONE_ac_ActivationLimitDuration(c, e, dup_strs);
	  if (!enn)
	      x->ActivationLimitDuration = en;
	  else
	      enn->gg.g.n = &en->gg.g;
	  enn = en;
      }
  }
  {
      struct zx_ac_ActivationLimitUsages_s* e;
      struct zx_ac_ActivationLimitUsages_s* en;
      struct zx_ac_ActivationLimitUsages_s* enn;
      for (enn = 0, e = x->ActivationLimitUsages; e; e = (struct zx_ac_ActivationLimitUsages_s*)e->gg.g.n) {
	  en = zx_DEEP_CLONE_ac_ActivationLimitUsages(c, e, dup_strs);
	  if (!enn)
	      x->ActivationLimitUsages = en;
	  else
	      enn->gg.g.n = &en->gg.g;
	  enn = en;
      }
  }
  x->ActivationLimitSession = zx_deep_clone_simple_elems(c,x->ActivationLimitSession, dup_strs);

  return x;
}

/* FUNC(zx_WALK_SO_ac_ActivationLimit) */

/* Depth first traversal of the tree in either schema order or the wire order. */
 
int zx_WALK_SO_ac_ActivationLimit(struct zx_ctx* c, struct zx_ac_ActivationLimit_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
{
  int ret = callback(&x->gg.g, ctx);
  if (ret)
    return ret;
  
  /* *** deal with xmlns specifications in exc c14n way */


  
  ret = zx_walk_so_unknown_attributes(c, &x->gg, ctx, callback); 
  if (ret)
    return ret;

  {
      struct zx_ac_ActivationLimitDuration_s* e;
      for (e = x->ActivationLimitDuration; e; e = (struct zx_ac_ActivationLimitDuration_s*)e->gg.g.n) {
	  ret = zx_WALK_SO_ac_ActivationLimitDuration(c, e, ctx, callback);
	  if (ret)
	      return ret;
      }
  }
  {
      struct zx_ac_ActivationLimitUsages_s* e;
      for (e = x->ActivationLimitUsages; e; e = (struct zx_ac_ActivationLimitUsages_s*)e->gg.g.n) {
	  ret = zx_WALK_SO_ac_ActivationLimitUsages(c, e, ctx, callback);
	  if (ret)
	      return ret;
      }
  }
  ret = zx_walk_so_simple_elems(c, x->ActivationLimitSession, ctx, callback);
  if (ret)
    return ret;

  
  return zx_walk_so_unknown_elems_and_content(c, &x->gg, ctx, callback);
}

/* FUNC(zx_WALK_WO_ac_ActivationLimit) */

int zx_WALK_WO_ac_ActivationLimit(struct zx_ctx* c, struct zx_ac_ActivationLimit_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
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

#define EL_NAME   ac_ActivationLimitDuration
#define EL_STRUCT zx_ac_ActivationLimitDuration_s
#define EL_NS     ac
#define EL_TAG    ActivationLimitDuration

/* FUNC(zx_FREE_ac_ActivationLimitDuration) */

/* Depth first traversal of data structure to free it and its subelements. Simple
 * strings are handled as a special case according to the free_strs flag. This
 * is useful if the strings point to underlying data from the wire that was
 * allocated differently. */

/* Called by: */
void zx_FREE_ac_ActivationLimitDuration(struct zx_ctx* c, struct zx_ac_ActivationLimitDuration_s* x, int free_strs)
{
  /* *** deal with xmlns specifications in exc c14n way */

  zx_free_attr(c, x->duration, free_strs);



  zx_free_elem_common(c, &x->gg, free_strs); 
}

/* FUNC(zx_NEW_ac_ActivationLimitDuration) */

/* Trivial allocator/constructor for the datatype. */

/* Called by: */
struct zx_ac_ActivationLimitDuration_s* zx_NEW_ac_ActivationLimitDuration(struct zx_ctx* c)
{
  struct zx_ac_ActivationLimitDuration_s* x = ZX_ZALLOC(c, struct zx_ac_ActivationLimitDuration_s);
  x->gg.g.tok = zx_ac_ActivationLimitDuration_ELEM;
  return x;
}

#ifdef ZX_ENA_AUX

/* FUNC(zx_DUP_STRS_ac_ActivationLimitDuration) */

/* Depth first traversal of data structure to copy its simple strings
 * to memory allocated from the memory allocator. The decoder will
 * use the underlying wireprotocol PDU buffer for strings, i.e.
 * strings are not copied - they point to the real data. If the
 * datastructure needs to outlast the protocol data or needs a different
 * memory allocation strategy, you need to call this function.  */

/* Called by: */
void zx_DUP_STRS_ac_ActivationLimitDuration(struct zx_ctx* c, struct zx_ac_ActivationLimitDuration_s* x)
{
  zx_dup_strs_common(c, &x->gg);
  /* *** deal with xmlns specifications in exc c14n way */

  zx_dup_attr(c, x->duration);


}

/* FUNC(zx_DEEP_CLONE_ac_ActivationLimitDuration) */

/* Depth first traversal of data structure to clone it and its sublements.
 * The simple strings are handled as a special case according to dup_strs flag. */

/* Called by: */
struct zx_ac_ActivationLimitDuration_s* zx_DEEP_CLONE_ac_ActivationLimitDuration(struct zx_ctx* c, struct zx_ac_ActivationLimitDuration_s* x, int dup_strs)
{
  x = (struct zx_ac_ActivationLimitDuration_s*)zx_clone_elem_common(c, &x->gg, sizeof(struct zx_ac_ActivationLimitDuration_s), dup_strs);
  /* *** deal with xmlns specifications in exc c14n way */

  x->duration = zx_clone_attr(c, x->duration);


  return x;
}

/* FUNC(zx_WALK_SO_ac_ActivationLimitDuration) */

/* Depth first traversal of the tree in either schema order or the wire order. */
 
int zx_WALK_SO_ac_ActivationLimitDuration(struct zx_ctx* c, struct zx_ac_ActivationLimitDuration_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
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

/* FUNC(zx_WALK_WO_ac_ActivationLimitDuration) */

int zx_WALK_WO_ac_ActivationLimitDuration(struct zx_ctx* c, struct zx_ac_ActivationLimitDuration_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
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

#define EL_NAME   ac_ActivationLimitUsages
#define EL_STRUCT zx_ac_ActivationLimitUsages_s
#define EL_NS     ac
#define EL_TAG    ActivationLimitUsages

/* FUNC(zx_FREE_ac_ActivationLimitUsages) */

/* Depth first traversal of data structure to free it and its subelements. Simple
 * strings are handled as a special case according to the free_strs flag. This
 * is useful if the strings point to underlying data from the wire that was
 * allocated differently. */

/* Called by: */
void zx_FREE_ac_ActivationLimitUsages(struct zx_ctx* c, struct zx_ac_ActivationLimitUsages_s* x, int free_strs)
{
  /* *** deal with xmlns specifications in exc c14n way */

  zx_free_attr(c, x->number, free_strs);



  zx_free_elem_common(c, &x->gg, free_strs); 
}

/* FUNC(zx_NEW_ac_ActivationLimitUsages) */

/* Trivial allocator/constructor for the datatype. */

/* Called by: */
struct zx_ac_ActivationLimitUsages_s* zx_NEW_ac_ActivationLimitUsages(struct zx_ctx* c)
{
  struct zx_ac_ActivationLimitUsages_s* x = ZX_ZALLOC(c, struct zx_ac_ActivationLimitUsages_s);
  x->gg.g.tok = zx_ac_ActivationLimitUsages_ELEM;
  return x;
}

#ifdef ZX_ENA_AUX

/* FUNC(zx_DUP_STRS_ac_ActivationLimitUsages) */

/* Depth first traversal of data structure to copy its simple strings
 * to memory allocated from the memory allocator. The decoder will
 * use the underlying wireprotocol PDU buffer for strings, i.e.
 * strings are not copied - they point to the real data. If the
 * datastructure needs to outlast the protocol data or needs a different
 * memory allocation strategy, you need to call this function.  */

/* Called by: */
void zx_DUP_STRS_ac_ActivationLimitUsages(struct zx_ctx* c, struct zx_ac_ActivationLimitUsages_s* x)
{
  zx_dup_strs_common(c, &x->gg);
  /* *** deal with xmlns specifications in exc c14n way */

  zx_dup_attr(c, x->number);


}

/* FUNC(zx_DEEP_CLONE_ac_ActivationLimitUsages) */

/* Depth first traversal of data structure to clone it and its sublements.
 * The simple strings are handled as a special case according to dup_strs flag. */

/* Called by: */
struct zx_ac_ActivationLimitUsages_s* zx_DEEP_CLONE_ac_ActivationLimitUsages(struct zx_ctx* c, struct zx_ac_ActivationLimitUsages_s* x, int dup_strs)
{
  x = (struct zx_ac_ActivationLimitUsages_s*)zx_clone_elem_common(c, &x->gg, sizeof(struct zx_ac_ActivationLimitUsages_s), dup_strs);
  /* *** deal with xmlns specifications in exc c14n way */

  x->number = zx_clone_attr(c, x->number);


  return x;
}

/* FUNC(zx_WALK_SO_ac_ActivationLimitUsages) */

/* Depth first traversal of the tree in either schema order or the wire order. */
 
int zx_WALK_SO_ac_ActivationLimitUsages(struct zx_ctx* c, struct zx_ac_ActivationLimitUsages_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
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

/* FUNC(zx_WALK_WO_ac_ActivationLimitUsages) */

int zx_WALK_WO_ac_ActivationLimitUsages(struct zx_ctx* c, struct zx_ac_ActivationLimitUsages_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
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

#define EL_NAME   ac_ActivationPin
#define EL_STRUCT zx_ac_ActivationPin_s
#define EL_NS     ac
#define EL_TAG    ActivationPin

/* FUNC(zx_FREE_ac_ActivationPin) */

/* Depth first traversal of data structure to free it and its subelements. Simple
 * strings are handled as a special case according to the free_strs flag. This
 * is useful if the strings point to underlying data from the wire that was
 * allocated differently. */

/* Called by: */
void zx_FREE_ac_ActivationPin(struct zx_ctx* c, struct zx_ac_ActivationPin_s* x, int free_strs)
{
  /* *** deal with xmlns specifications in exc c14n way */


  {
      struct zx_ac_Length_s* e;
      struct zx_ac_Length_s* en;
      for (e = x->Length; e; e = en) {
	  en = (struct zx_ac_Length_s*)e->gg.g.n;
	  zx_FREE_ac_Length(c, e, free_strs);
      }
  }
  {
      struct zx_ac_Alphabet_s* e;
      struct zx_ac_Alphabet_s* en;
      for (e = x->Alphabet; e; e = en) {
	  en = (struct zx_ac_Alphabet_s*)e->gg.g.n;
	  zx_FREE_ac_Alphabet(c, e, free_strs);
      }
  }
  {
      struct zx_ac_Generation_s* e;
      struct zx_ac_Generation_s* en;
      for (e = x->Generation; e; e = en) {
	  en = (struct zx_ac_Generation_s*)e->gg.g.n;
	  zx_FREE_ac_Generation(c, e, free_strs);
      }
  }
  {
      struct zx_ac_ActivationLimit_s* e;
      struct zx_ac_ActivationLimit_s* en;
      for (e = x->ActivationLimit; e; e = en) {
	  en = (struct zx_ac_ActivationLimit_s*)e->gg.g.n;
	  zx_FREE_ac_ActivationLimit(c, e, free_strs);
      }
  }
  {
      struct zx_ac_Extension_s* e;
      struct zx_ac_Extension_s* en;
      for (e = x->Extension; e; e = en) {
	  en = (struct zx_ac_Extension_s*)e->gg.g.n;
	  zx_FREE_ac_Extension(c, e, free_strs);
      }
  }


  zx_free_elem_common(c, &x->gg, free_strs); 
}

/* FUNC(zx_NEW_ac_ActivationPin) */

/* Trivial allocator/constructor for the datatype. */

/* Called by: */
struct zx_ac_ActivationPin_s* zx_NEW_ac_ActivationPin(struct zx_ctx* c)
{
  struct zx_ac_ActivationPin_s* x = ZX_ZALLOC(c, struct zx_ac_ActivationPin_s);
  x->gg.g.tok = zx_ac_ActivationPin_ELEM;
  return x;
}

#ifdef ZX_ENA_AUX

/* FUNC(zx_DUP_STRS_ac_ActivationPin) */

/* Depth first traversal of data structure to copy its simple strings
 * to memory allocated from the memory allocator. The decoder will
 * use the underlying wireprotocol PDU buffer for strings, i.e.
 * strings are not copied - they point to the real data. If the
 * datastructure needs to outlast the protocol data or needs a different
 * memory allocation strategy, you need to call this function.  */

/* Called by: */
void zx_DUP_STRS_ac_ActivationPin(struct zx_ctx* c, struct zx_ac_ActivationPin_s* x)
{
  zx_dup_strs_common(c, &x->gg);
  /* *** deal with xmlns specifications in exc c14n way */


  {
      struct zx_ac_Length_s* e;
      for (e = x->Length; e; e = (struct zx_ac_Length_s*)e->gg.g.n)
	  zx_DUP_STRS_ac_Length(c, e);
  }
  {
      struct zx_ac_Alphabet_s* e;
      for (e = x->Alphabet; e; e = (struct zx_ac_Alphabet_s*)e->gg.g.n)
	  zx_DUP_STRS_ac_Alphabet(c, e);
  }
  {
      struct zx_ac_Generation_s* e;
      for (e = x->Generation; e; e = (struct zx_ac_Generation_s*)e->gg.g.n)
	  zx_DUP_STRS_ac_Generation(c, e);
  }
  {
      struct zx_ac_ActivationLimit_s* e;
      for (e = x->ActivationLimit; e; e = (struct zx_ac_ActivationLimit_s*)e->gg.g.n)
	  zx_DUP_STRS_ac_ActivationLimit(c, e);
  }
  {
      struct zx_ac_Extension_s* e;
      for (e = x->Extension; e; e = (struct zx_ac_Extension_s*)e->gg.g.n)
	  zx_DUP_STRS_ac_Extension(c, e);
  }

}

/* FUNC(zx_DEEP_CLONE_ac_ActivationPin) */

/* Depth first traversal of data structure to clone it and its sublements.
 * The simple strings are handled as a special case according to dup_strs flag. */

/* Called by: */
struct zx_ac_ActivationPin_s* zx_DEEP_CLONE_ac_ActivationPin(struct zx_ctx* c, struct zx_ac_ActivationPin_s* x, int dup_strs)
{
  x = (struct zx_ac_ActivationPin_s*)zx_clone_elem_common(c, &x->gg, sizeof(struct zx_ac_ActivationPin_s), dup_strs);
  /* *** deal with xmlns specifications in exc c14n way */


  {
      struct zx_ac_Length_s* e;
      struct zx_ac_Length_s* en;
      struct zx_ac_Length_s* enn;
      for (enn = 0, e = x->Length; e; e = (struct zx_ac_Length_s*)e->gg.g.n) {
	  en = zx_DEEP_CLONE_ac_Length(c, e, dup_strs);
	  if (!enn)
	      x->Length = en;
	  else
	      enn->gg.g.n = &en->gg.g;
	  enn = en;
      }
  }
  {
      struct zx_ac_Alphabet_s* e;
      struct zx_ac_Alphabet_s* en;
      struct zx_ac_Alphabet_s* enn;
      for (enn = 0, e = x->Alphabet; e; e = (struct zx_ac_Alphabet_s*)e->gg.g.n) {
	  en = zx_DEEP_CLONE_ac_Alphabet(c, e, dup_strs);
	  if (!enn)
	      x->Alphabet = en;
	  else
	      enn->gg.g.n = &en->gg.g;
	  enn = en;
      }
  }
  {
      struct zx_ac_Generation_s* e;
      struct zx_ac_Generation_s* en;
      struct zx_ac_Generation_s* enn;
      for (enn = 0, e = x->Generation; e; e = (struct zx_ac_Generation_s*)e->gg.g.n) {
	  en = zx_DEEP_CLONE_ac_Generation(c, e, dup_strs);
	  if (!enn)
	      x->Generation = en;
	  else
	      enn->gg.g.n = &en->gg.g;
	  enn = en;
      }
  }
  {
      struct zx_ac_ActivationLimit_s* e;
      struct zx_ac_ActivationLimit_s* en;
      struct zx_ac_ActivationLimit_s* enn;
      for (enn = 0, e = x->ActivationLimit; e; e = (struct zx_ac_ActivationLimit_s*)e->gg.g.n) {
	  en = zx_DEEP_CLONE_ac_ActivationLimit(c, e, dup_strs);
	  if (!enn)
	      x->ActivationLimit = en;
	  else
	      enn->gg.g.n = &en->gg.g;
	  enn = en;
      }
  }
  {
      struct zx_ac_Extension_s* e;
      struct zx_ac_Extension_s* en;
      struct zx_ac_Extension_s* enn;
      for (enn = 0, e = x->Extension; e; e = (struct zx_ac_Extension_s*)e->gg.g.n) {
	  en = zx_DEEP_CLONE_ac_Extension(c, e, dup_strs);
	  if (!enn)
	      x->Extension = en;
	  else
	      enn->gg.g.n = &en->gg.g;
	  enn = en;
      }
  }

  return x;
}

/* FUNC(zx_WALK_SO_ac_ActivationPin) */

/* Depth first traversal of the tree in either schema order or the wire order. */
 
int zx_WALK_SO_ac_ActivationPin(struct zx_ctx* c, struct zx_ac_ActivationPin_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
{
  int ret = callback(&x->gg.g, ctx);
  if (ret)
    return ret;
  
  /* *** deal with xmlns specifications in exc c14n way */


  
  ret = zx_walk_so_unknown_attributes(c, &x->gg, ctx, callback); 
  if (ret)
    return ret;

  {
      struct zx_ac_Length_s* e;
      for (e = x->Length; e; e = (struct zx_ac_Length_s*)e->gg.g.n) {
	  ret = zx_WALK_SO_ac_Length(c, e, ctx, callback);
	  if (ret)
	      return ret;
      }
  }
  {
      struct zx_ac_Alphabet_s* e;
      for (e = x->Alphabet; e; e = (struct zx_ac_Alphabet_s*)e->gg.g.n) {
	  ret = zx_WALK_SO_ac_Alphabet(c, e, ctx, callback);
	  if (ret)
	      return ret;
      }
  }
  {
      struct zx_ac_Generation_s* e;
      for (e = x->Generation; e; e = (struct zx_ac_Generation_s*)e->gg.g.n) {
	  ret = zx_WALK_SO_ac_Generation(c, e, ctx, callback);
	  if (ret)
	      return ret;
      }
  }
  {
      struct zx_ac_ActivationLimit_s* e;
      for (e = x->ActivationLimit; e; e = (struct zx_ac_ActivationLimit_s*)e->gg.g.n) {
	  ret = zx_WALK_SO_ac_ActivationLimit(c, e, ctx, callback);
	  if (ret)
	      return ret;
      }
  }
  {
      struct zx_ac_Extension_s* e;
      for (e = x->Extension; e; e = (struct zx_ac_Extension_s*)e->gg.g.n) {
	  ret = zx_WALK_SO_ac_Extension(c, e, ctx, callback);
	  if (ret)
	      return ret;
      }
  }

  
  return zx_walk_so_unknown_elems_and_content(c, &x->gg, ctx, callback);
}

/* FUNC(zx_WALK_WO_ac_ActivationPin) */

int zx_WALK_WO_ac_ActivationPin(struct zx_ctx* c, struct zx_ac_ActivationPin_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
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

#define EL_NAME   ac_Alphabet
#define EL_STRUCT zx_ac_Alphabet_s
#define EL_NS     ac
#define EL_TAG    Alphabet

/* FUNC(zx_FREE_ac_Alphabet) */

/* Depth first traversal of data structure to free it and its subelements. Simple
 * strings are handled as a special case according to the free_strs flag. This
 * is useful if the strings point to underlying data from the wire that was
 * allocated differently. */

/* Called by: */
void zx_FREE_ac_Alphabet(struct zx_ctx* c, struct zx_ac_Alphabet_s* x, int free_strs)
{
  /* *** deal with xmlns specifications in exc c14n way */

  zx_free_attr(c, x->case_is_c_keyword, free_strs);
  zx_free_attr(c, x->excludedChars, free_strs);
  zx_free_attr(c, x->requiredChars, free_strs);



  zx_free_elem_common(c, &x->gg, free_strs); 
}

/* FUNC(zx_NEW_ac_Alphabet) */

/* Trivial allocator/constructor for the datatype. */

/* Called by: */
struct zx_ac_Alphabet_s* zx_NEW_ac_Alphabet(struct zx_ctx* c)
{
  struct zx_ac_Alphabet_s* x = ZX_ZALLOC(c, struct zx_ac_Alphabet_s);
  x->gg.g.tok = zx_ac_Alphabet_ELEM;
  return x;
}

#ifdef ZX_ENA_AUX

/* FUNC(zx_DUP_STRS_ac_Alphabet) */

/* Depth first traversal of data structure to copy its simple strings
 * to memory allocated from the memory allocator. The decoder will
 * use the underlying wireprotocol PDU buffer for strings, i.e.
 * strings are not copied - they point to the real data. If the
 * datastructure needs to outlast the protocol data or needs a different
 * memory allocation strategy, you need to call this function.  */

/* Called by: */
void zx_DUP_STRS_ac_Alphabet(struct zx_ctx* c, struct zx_ac_Alphabet_s* x)
{
  zx_dup_strs_common(c, &x->gg);
  /* *** deal with xmlns specifications in exc c14n way */

  zx_dup_attr(c, x->case_is_c_keyword);
  zx_dup_attr(c, x->excludedChars);
  zx_dup_attr(c, x->requiredChars);


}

/* FUNC(zx_DEEP_CLONE_ac_Alphabet) */

/* Depth first traversal of data structure to clone it and its sublements.
 * The simple strings are handled as a special case according to dup_strs flag. */

/* Called by: */
struct zx_ac_Alphabet_s* zx_DEEP_CLONE_ac_Alphabet(struct zx_ctx* c, struct zx_ac_Alphabet_s* x, int dup_strs)
{
  x = (struct zx_ac_Alphabet_s*)zx_clone_elem_common(c, &x->gg, sizeof(struct zx_ac_Alphabet_s), dup_strs);
  /* *** deal with xmlns specifications in exc c14n way */

  x->case_is_c_keyword = zx_clone_attr(c, x->case_is_c_keyword);
  x->excludedChars = zx_clone_attr(c, x->excludedChars);
  x->requiredChars = zx_clone_attr(c, x->requiredChars);


  return x;
}

/* FUNC(zx_WALK_SO_ac_Alphabet) */

/* Depth first traversal of the tree in either schema order or the wire order. */
 
int zx_WALK_SO_ac_Alphabet(struct zx_ctx* c, struct zx_ac_Alphabet_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
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

/* FUNC(zx_WALK_WO_ac_Alphabet) */

int zx_WALK_WO_ac_Alphabet(struct zx_ctx* c, struct zx_ac_Alphabet_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
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

#define EL_NAME   ac_AsymmetricDecryption
#define EL_STRUCT zx_ac_AsymmetricDecryption_s
#define EL_NS     ac
#define EL_TAG    AsymmetricDecryption

/* FUNC(zx_FREE_ac_AsymmetricDecryption) */

/* Depth first traversal of data structure to free it and its subelements. Simple
 * strings are handled as a special case according to the free_strs flag. This
 * is useful if the strings point to underlying data from the wire that was
 * allocated differently. */

/* Called by: */
void zx_FREE_ac_AsymmetricDecryption(struct zx_ctx* c, struct zx_ac_AsymmetricDecryption_s* x, int free_strs)
{
  /* *** deal with xmlns specifications in exc c14n way */


  {
      struct zx_ac_Extension_s* e;
      struct zx_ac_Extension_s* en;
      for (e = x->Extension; e; e = en) {
	  en = (struct zx_ac_Extension_s*)e->gg.g.n;
	  zx_FREE_ac_Extension(c, e, free_strs);
      }
  }


  zx_free_elem_common(c, &x->gg, free_strs); 
}

/* FUNC(zx_NEW_ac_AsymmetricDecryption) */

/* Trivial allocator/constructor for the datatype. */

/* Called by: */
struct zx_ac_AsymmetricDecryption_s* zx_NEW_ac_AsymmetricDecryption(struct zx_ctx* c)
{
  struct zx_ac_AsymmetricDecryption_s* x = ZX_ZALLOC(c, struct zx_ac_AsymmetricDecryption_s);
  x->gg.g.tok = zx_ac_AsymmetricDecryption_ELEM;
  return x;
}

#ifdef ZX_ENA_AUX

/* FUNC(zx_DUP_STRS_ac_AsymmetricDecryption) */

/* Depth first traversal of data structure to copy its simple strings
 * to memory allocated from the memory allocator. The decoder will
 * use the underlying wireprotocol PDU buffer for strings, i.e.
 * strings are not copied - they point to the real data. If the
 * datastructure needs to outlast the protocol data or needs a different
 * memory allocation strategy, you need to call this function.  */

/* Called by: */
void zx_DUP_STRS_ac_AsymmetricDecryption(struct zx_ctx* c, struct zx_ac_AsymmetricDecryption_s* x)
{
  zx_dup_strs_common(c, &x->gg);
  /* *** deal with xmlns specifications in exc c14n way */


  {
      struct zx_ac_Extension_s* e;
      for (e = x->Extension; e; e = (struct zx_ac_Extension_s*)e->gg.g.n)
	  zx_DUP_STRS_ac_Extension(c, e);
  }

}

/* FUNC(zx_DEEP_CLONE_ac_AsymmetricDecryption) */

/* Depth first traversal of data structure to clone it and its sublements.
 * The simple strings are handled as a special case according to dup_strs flag. */

/* Called by: */
struct zx_ac_AsymmetricDecryption_s* zx_DEEP_CLONE_ac_AsymmetricDecryption(struct zx_ctx* c, struct zx_ac_AsymmetricDecryption_s* x, int dup_strs)
{
  x = (struct zx_ac_AsymmetricDecryption_s*)zx_clone_elem_common(c, &x->gg, sizeof(struct zx_ac_AsymmetricDecryption_s), dup_strs);
  /* *** deal with xmlns specifications in exc c14n way */


  {
      struct zx_ac_Extension_s* e;
      struct zx_ac_Extension_s* en;
      struct zx_ac_Extension_s* enn;
      for (enn = 0, e = x->Extension; e; e = (struct zx_ac_Extension_s*)e->gg.g.n) {
	  en = zx_DEEP_CLONE_ac_Extension(c, e, dup_strs);
	  if (!enn)
	      x->Extension = en;
	  else
	      enn->gg.g.n = &en->gg.g;
	  enn = en;
      }
  }

  return x;
}

/* FUNC(zx_WALK_SO_ac_AsymmetricDecryption) */

/* Depth first traversal of the tree in either schema order or the wire order. */
 
int zx_WALK_SO_ac_AsymmetricDecryption(struct zx_ctx* c, struct zx_ac_AsymmetricDecryption_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
{
  int ret = callback(&x->gg.g, ctx);
  if (ret)
    return ret;
  
  /* *** deal with xmlns specifications in exc c14n way */


  
  ret = zx_walk_so_unknown_attributes(c, &x->gg, ctx, callback); 
  if (ret)
    return ret;

  {
      struct zx_ac_Extension_s* e;
      for (e = x->Extension; e; e = (struct zx_ac_Extension_s*)e->gg.g.n) {
	  ret = zx_WALK_SO_ac_Extension(c, e, ctx, callback);
	  if (ret)
	      return ret;
      }
  }

  
  return zx_walk_so_unknown_elems_and_content(c, &x->gg, ctx, callback);
}

/* FUNC(zx_WALK_WO_ac_AsymmetricDecryption) */

int zx_WALK_WO_ac_AsymmetricDecryption(struct zx_ctx* c, struct zx_ac_AsymmetricDecryption_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
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

#define EL_NAME   ac_AsymmetricKeyAgreement
#define EL_STRUCT zx_ac_AsymmetricKeyAgreement_s
#define EL_NS     ac
#define EL_TAG    AsymmetricKeyAgreement

/* FUNC(zx_FREE_ac_AsymmetricKeyAgreement) */

/* Depth first traversal of data structure to free it and its subelements. Simple
 * strings are handled as a special case according to the free_strs flag. This
 * is useful if the strings point to underlying data from the wire that was
 * allocated differently. */

/* Called by: */
void zx_FREE_ac_AsymmetricKeyAgreement(struct zx_ctx* c, struct zx_ac_AsymmetricKeyAgreement_s* x, int free_strs)
{
  /* *** deal with xmlns specifications in exc c14n way */


  {
      struct zx_ac_Extension_s* e;
      struct zx_ac_Extension_s* en;
      for (e = x->Extension; e; e = en) {
	  en = (struct zx_ac_Extension_s*)e->gg.g.n;
	  zx_FREE_ac_Extension(c, e, free_strs);
      }
  }


  zx_free_elem_common(c, &x->gg, free_strs); 
}

/* FUNC(zx_NEW_ac_AsymmetricKeyAgreement) */

/* Trivial allocator/constructor for the datatype. */

/* Called by: */
struct zx_ac_AsymmetricKeyAgreement_s* zx_NEW_ac_AsymmetricKeyAgreement(struct zx_ctx* c)
{
  struct zx_ac_AsymmetricKeyAgreement_s* x = ZX_ZALLOC(c, struct zx_ac_AsymmetricKeyAgreement_s);
  x->gg.g.tok = zx_ac_AsymmetricKeyAgreement_ELEM;
  return x;
}

#ifdef ZX_ENA_AUX

/* FUNC(zx_DUP_STRS_ac_AsymmetricKeyAgreement) */

/* Depth first traversal of data structure to copy its simple strings
 * to memory allocated from the memory allocator. The decoder will
 * use the underlying wireprotocol PDU buffer for strings, i.e.
 * strings are not copied - they point to the real data. If the
 * datastructure needs to outlast the protocol data or needs a different
 * memory allocation strategy, you need to call this function.  */

/* Called by: */
void zx_DUP_STRS_ac_AsymmetricKeyAgreement(struct zx_ctx* c, struct zx_ac_AsymmetricKeyAgreement_s* x)
{
  zx_dup_strs_common(c, &x->gg);
  /* *** deal with xmlns specifications in exc c14n way */


  {
      struct zx_ac_Extension_s* e;
      for (e = x->Extension; e; e = (struct zx_ac_Extension_s*)e->gg.g.n)
	  zx_DUP_STRS_ac_Extension(c, e);
  }

}

/* FUNC(zx_DEEP_CLONE_ac_AsymmetricKeyAgreement) */

/* Depth first traversal of data structure to clone it and its sublements.
 * The simple strings are handled as a special case according to dup_strs flag. */

/* Called by: */
struct zx_ac_AsymmetricKeyAgreement_s* zx_DEEP_CLONE_ac_AsymmetricKeyAgreement(struct zx_ctx* c, struct zx_ac_AsymmetricKeyAgreement_s* x, int dup_strs)
{
  x = (struct zx_ac_AsymmetricKeyAgreement_s*)zx_clone_elem_common(c, &x->gg, sizeof(struct zx_ac_AsymmetricKeyAgreement_s), dup_strs);
  /* *** deal with xmlns specifications in exc c14n way */


  {
      struct zx_ac_Extension_s* e;
      struct zx_ac_Extension_s* en;
      struct zx_ac_Extension_s* enn;
      for (enn = 0, e = x->Extension; e; e = (struct zx_ac_Extension_s*)e->gg.g.n) {
	  en = zx_DEEP_CLONE_ac_Extension(c, e, dup_strs);
	  if (!enn)
	      x->Extension = en;
	  else
	      enn->gg.g.n = &en->gg.g;
	  enn = en;
      }
  }

  return x;
}

/* FUNC(zx_WALK_SO_ac_AsymmetricKeyAgreement) */

/* Depth first traversal of the tree in either schema order or the wire order. */
 
int zx_WALK_SO_ac_AsymmetricKeyAgreement(struct zx_ctx* c, struct zx_ac_AsymmetricKeyAgreement_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
{
  int ret = callback(&x->gg.g, ctx);
  if (ret)
    return ret;
  
  /* *** deal with xmlns specifications in exc c14n way */


  
  ret = zx_walk_so_unknown_attributes(c, &x->gg, ctx, callback); 
  if (ret)
    return ret;

  {
      struct zx_ac_Extension_s* e;
      for (e = x->Extension; e; e = (struct zx_ac_Extension_s*)e->gg.g.n) {
	  ret = zx_WALK_SO_ac_Extension(c, e, ctx, callback);
	  if (ret)
	      return ret;
      }
  }

  
  return zx_walk_so_unknown_elems_and_content(c, &x->gg, ctx, callback);
}

/* FUNC(zx_WALK_WO_ac_AsymmetricKeyAgreement) */

int zx_WALK_WO_ac_AsymmetricKeyAgreement(struct zx_ctx* c, struct zx_ac_AsymmetricKeyAgreement_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
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

#define EL_NAME   ac_AuthenticatingAuthority
#define EL_STRUCT zx_ac_AuthenticatingAuthority_s
#define EL_NS     ac
#define EL_TAG    AuthenticatingAuthority

/* FUNC(zx_FREE_ac_AuthenticatingAuthority) */

/* Depth first traversal of data structure to free it and its subelements. Simple
 * strings are handled as a special case according to the free_strs flag. This
 * is useful if the strings point to underlying data from the wire that was
 * allocated differently. */

/* Called by: */
void zx_FREE_ac_AuthenticatingAuthority(struct zx_ctx* c, struct zx_ac_AuthenticatingAuthority_s* x, int free_strs)
{
  /* *** deal with xmlns specifications in exc c14n way */

  zx_free_attr(c, x->ID, free_strs);

  {
      struct zx_ac_GoverningAgreements_s* e;
      struct zx_ac_GoverningAgreements_s* en;
      for (e = x->GoverningAgreements; e; e = en) {
	  en = (struct zx_ac_GoverningAgreements_s*)e->gg.g.n;
	  zx_FREE_ac_GoverningAgreements(c, e, free_strs);
      }
  }


  zx_free_elem_common(c, &x->gg, free_strs); 
}

/* FUNC(zx_NEW_ac_AuthenticatingAuthority) */

/* Trivial allocator/constructor for the datatype. */

/* Called by: */
struct zx_ac_AuthenticatingAuthority_s* zx_NEW_ac_AuthenticatingAuthority(struct zx_ctx* c)
{
  struct zx_ac_AuthenticatingAuthority_s* x = ZX_ZALLOC(c, struct zx_ac_AuthenticatingAuthority_s);
  x->gg.g.tok = zx_ac_AuthenticatingAuthority_ELEM;
  return x;
}

#ifdef ZX_ENA_AUX

/* FUNC(zx_DUP_STRS_ac_AuthenticatingAuthority) */

/* Depth first traversal of data structure to copy its simple strings
 * to memory allocated from the memory allocator. The decoder will
 * use the underlying wireprotocol PDU buffer for strings, i.e.
 * strings are not copied - they point to the real data. If the
 * datastructure needs to outlast the protocol data or needs a different
 * memory allocation strategy, you need to call this function.  */

/* Called by: */
void zx_DUP_STRS_ac_AuthenticatingAuthority(struct zx_ctx* c, struct zx_ac_AuthenticatingAuthority_s* x)
{
  zx_dup_strs_common(c, &x->gg);
  /* *** deal with xmlns specifications in exc c14n way */

  zx_dup_attr(c, x->ID);

  {
      struct zx_ac_GoverningAgreements_s* e;
      for (e = x->GoverningAgreements; e; e = (struct zx_ac_GoverningAgreements_s*)e->gg.g.n)
	  zx_DUP_STRS_ac_GoverningAgreements(c, e);
  }

}

/* FUNC(zx_DEEP_CLONE_ac_AuthenticatingAuthority) */

/* Depth first traversal of data structure to clone it and its sublements.
 * The simple strings are handled as a special case according to dup_strs flag. */

/* Called by: */
struct zx_ac_AuthenticatingAuthority_s* zx_DEEP_CLONE_ac_AuthenticatingAuthority(struct zx_ctx* c, struct zx_ac_AuthenticatingAuthority_s* x, int dup_strs)
{
  x = (struct zx_ac_AuthenticatingAuthority_s*)zx_clone_elem_common(c, &x->gg, sizeof(struct zx_ac_AuthenticatingAuthority_s), dup_strs);
  /* *** deal with xmlns specifications in exc c14n way */

  x->ID = zx_clone_attr(c, x->ID);

  {
      struct zx_ac_GoverningAgreements_s* e;
      struct zx_ac_GoverningAgreements_s* en;
      struct zx_ac_GoverningAgreements_s* enn;
      for (enn = 0, e = x->GoverningAgreements; e; e = (struct zx_ac_GoverningAgreements_s*)e->gg.g.n) {
	  en = zx_DEEP_CLONE_ac_GoverningAgreements(c, e, dup_strs);
	  if (!enn)
	      x->GoverningAgreements = en;
	  else
	      enn->gg.g.n = &en->gg.g;
	  enn = en;
      }
  }

  return x;
}

/* FUNC(zx_WALK_SO_ac_AuthenticatingAuthority) */

/* Depth first traversal of the tree in either schema order or the wire order. */
 
int zx_WALK_SO_ac_AuthenticatingAuthority(struct zx_ctx* c, struct zx_ac_AuthenticatingAuthority_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
{
  int ret = callback(&x->gg.g, ctx);
  if (ret)
    return ret;
  
  /* *** deal with xmlns specifications in exc c14n way */


  
  ret = zx_walk_so_unknown_attributes(c, &x->gg, ctx, callback); 
  if (ret)
    return ret;

  {
      struct zx_ac_GoverningAgreements_s* e;
      for (e = x->GoverningAgreements; e; e = (struct zx_ac_GoverningAgreements_s*)e->gg.g.n) {
	  ret = zx_WALK_SO_ac_GoverningAgreements(c, e, ctx, callback);
	  if (ret)
	      return ret;
      }
  }

  
  return zx_walk_so_unknown_elems_and_content(c, &x->gg, ctx, callback);
}

/* FUNC(zx_WALK_WO_ac_AuthenticatingAuthority) */

int zx_WALK_WO_ac_AuthenticatingAuthority(struct zx_ctx* c, struct zx_ac_AuthenticatingAuthority_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
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

#define EL_NAME   ac_AuthenticationContextStatement
#define EL_STRUCT zx_ac_AuthenticationContextStatement_s
#define EL_NS     ac
#define EL_TAG    AuthenticationContextStatement

/* FUNC(zx_FREE_ac_AuthenticationContextStatement) */

/* Depth first traversal of data structure to free it and its subelements. Simple
 * strings are handled as a special case according to the free_strs flag. This
 * is useful if the strings point to underlying data from the wire that was
 * allocated differently. */

/* Called by: */
void zx_FREE_ac_AuthenticationContextStatement(struct zx_ctx* c, struct zx_ac_AuthenticationContextStatement_s* x, int free_strs)
{
  /* *** deal with xmlns specifications in exc c14n way */

  zx_free_attr(c, x->ID, free_strs);

  {
      struct zx_ac_Identification_s* e;
      struct zx_ac_Identification_s* en;
      for (e = x->Identification; e; e = en) {
	  en = (struct zx_ac_Identification_s*)e->gg.g.n;
	  zx_FREE_ac_Identification(c, e, free_strs);
      }
  }
  {
      struct zx_ac_TechnicalProtection_s* e;
      struct zx_ac_TechnicalProtection_s* en;
      for (e = x->TechnicalProtection; e; e = en) {
	  en = (struct zx_ac_TechnicalProtection_s*)e->gg.g.n;
	  zx_FREE_ac_TechnicalProtection(c, e, free_strs);
      }
  }
  {
      struct zx_ac_OperationalProtection_s* e;
      struct zx_ac_OperationalProtection_s* en;
      for (e = x->OperationalProtection; e; e = en) {
	  en = (struct zx_ac_OperationalProtection_s*)e->gg.g.n;
	  zx_FREE_ac_OperationalProtection(c, e, free_strs);
      }
  }
  {
      struct zx_ac_AuthenticationMethod_s* e;
      struct zx_ac_AuthenticationMethod_s* en;
      for (e = x->AuthenticationMethod; e; e = en) {
	  en = (struct zx_ac_AuthenticationMethod_s*)e->gg.g.n;
	  zx_FREE_ac_AuthenticationMethod(c, e, free_strs);
      }
  }
  {
      struct zx_ac_GoverningAgreements_s* e;
      struct zx_ac_GoverningAgreements_s* en;
      for (e = x->GoverningAgreements; e; e = en) {
	  en = (struct zx_ac_GoverningAgreements_s*)e->gg.g.n;
	  zx_FREE_ac_GoverningAgreements(c, e, free_strs);
      }
  }
  {
      struct zx_ac_AuthenticatingAuthority_s* e;
      struct zx_ac_AuthenticatingAuthority_s* en;
      for (e = x->AuthenticatingAuthority; e; e = en) {
	  en = (struct zx_ac_AuthenticatingAuthority_s*)e->gg.g.n;
	  zx_FREE_ac_AuthenticatingAuthority(c, e, free_strs);
      }
  }
  {
      struct zx_ac_Extension_s* e;
      struct zx_ac_Extension_s* en;
      for (e = x->Extension; e; e = en) {
	  en = (struct zx_ac_Extension_s*)e->gg.g.n;
	  zx_FREE_ac_Extension(c, e, free_strs);
      }
  }


  zx_free_elem_common(c, &x->gg, free_strs); 
}

/* FUNC(zx_NEW_ac_AuthenticationContextStatement) */

/* Trivial allocator/constructor for the datatype. */

/* Called by: */
struct zx_ac_AuthenticationContextStatement_s* zx_NEW_ac_AuthenticationContextStatement(struct zx_ctx* c)
{
  struct zx_ac_AuthenticationContextStatement_s* x = ZX_ZALLOC(c, struct zx_ac_AuthenticationContextStatement_s);
  x->gg.g.tok = zx_ac_AuthenticationContextStatement_ELEM;
  return x;
}

#ifdef ZX_ENA_AUX

/* FUNC(zx_DUP_STRS_ac_AuthenticationContextStatement) */

/* Depth first traversal of data structure to copy its simple strings
 * to memory allocated from the memory allocator. The decoder will
 * use the underlying wireprotocol PDU buffer for strings, i.e.
 * strings are not copied - they point to the real data. If the
 * datastructure needs to outlast the protocol data or needs a different
 * memory allocation strategy, you need to call this function.  */

/* Called by: */
void zx_DUP_STRS_ac_AuthenticationContextStatement(struct zx_ctx* c, struct zx_ac_AuthenticationContextStatement_s* x)
{
  zx_dup_strs_common(c, &x->gg);
  /* *** deal with xmlns specifications in exc c14n way */

  zx_dup_attr(c, x->ID);

  {
      struct zx_ac_Identification_s* e;
      for (e = x->Identification; e; e = (struct zx_ac_Identification_s*)e->gg.g.n)
	  zx_DUP_STRS_ac_Identification(c, e);
  }
  {
      struct zx_ac_TechnicalProtection_s* e;
      for (e = x->TechnicalProtection; e; e = (struct zx_ac_TechnicalProtection_s*)e->gg.g.n)
	  zx_DUP_STRS_ac_TechnicalProtection(c, e);
  }
  {
      struct zx_ac_OperationalProtection_s* e;
      for (e = x->OperationalProtection; e; e = (struct zx_ac_OperationalProtection_s*)e->gg.g.n)
	  zx_DUP_STRS_ac_OperationalProtection(c, e);
  }
  {
      struct zx_ac_AuthenticationMethod_s* e;
      for (e = x->AuthenticationMethod; e; e = (struct zx_ac_AuthenticationMethod_s*)e->gg.g.n)
	  zx_DUP_STRS_ac_AuthenticationMethod(c, e);
  }
  {
      struct zx_ac_GoverningAgreements_s* e;
      for (e = x->GoverningAgreements; e; e = (struct zx_ac_GoverningAgreements_s*)e->gg.g.n)
	  zx_DUP_STRS_ac_GoverningAgreements(c, e);
  }
  {
      struct zx_ac_AuthenticatingAuthority_s* e;
      for (e = x->AuthenticatingAuthority; e; e = (struct zx_ac_AuthenticatingAuthority_s*)e->gg.g.n)
	  zx_DUP_STRS_ac_AuthenticatingAuthority(c, e);
  }
  {
      struct zx_ac_Extension_s* e;
      for (e = x->Extension; e; e = (struct zx_ac_Extension_s*)e->gg.g.n)
	  zx_DUP_STRS_ac_Extension(c, e);
  }

}

/* FUNC(zx_DEEP_CLONE_ac_AuthenticationContextStatement) */

/* Depth first traversal of data structure to clone it and its sublements.
 * The simple strings are handled as a special case according to dup_strs flag. */

/* Called by: */
struct zx_ac_AuthenticationContextStatement_s* zx_DEEP_CLONE_ac_AuthenticationContextStatement(struct zx_ctx* c, struct zx_ac_AuthenticationContextStatement_s* x, int dup_strs)
{
  x = (struct zx_ac_AuthenticationContextStatement_s*)zx_clone_elem_common(c, &x->gg, sizeof(struct zx_ac_AuthenticationContextStatement_s), dup_strs);
  /* *** deal with xmlns specifications in exc c14n way */

  x->ID = zx_clone_attr(c, x->ID);

  {
      struct zx_ac_Identification_s* e;
      struct zx_ac_Identification_s* en;
      struct zx_ac_Identification_s* enn;
      for (enn = 0, e = x->Identification; e; e = (struct zx_ac_Identification_s*)e->gg.g.n) {
	  en = zx_DEEP_CLONE_ac_Identification(c, e, dup_strs);
	  if (!enn)
	      x->Identification = en;
	  else
	      enn->gg.g.n = &en->gg.g;
	  enn = en;
      }
  }
  {
      struct zx_ac_TechnicalProtection_s* e;
      struct zx_ac_TechnicalProtection_s* en;
      struct zx_ac_TechnicalProtection_s* enn;
      for (enn = 0, e = x->TechnicalProtection; e; e = (struct zx_ac_TechnicalProtection_s*)e->gg.g.n) {
	  en = zx_DEEP_CLONE_ac_TechnicalProtection(c, e, dup_strs);
	  if (!enn)
	      x->TechnicalProtection = en;
	  else
	      enn->gg.g.n = &en->gg.g;
	  enn = en;
      }
  }
  {
      struct zx_ac_OperationalProtection_s* e;
      struct zx_ac_OperationalProtection_s* en;
      struct zx_ac_OperationalProtection_s* enn;
      for (enn = 0, e = x->OperationalProtection; e; e = (struct zx_ac_OperationalProtection_s*)e->gg.g.n) {
	  en = zx_DEEP_CLONE_ac_OperationalProtection(c, e, dup_strs);
	  if (!enn)
	      x->OperationalProtection = en;
	  else
	      enn->gg.g.n = &en->gg.g;
	  enn = en;
      }
  }
  {
      struct zx_ac_AuthenticationMethod_s* e;
      struct zx_ac_AuthenticationMethod_s* en;
      struct zx_ac_AuthenticationMethod_s* enn;
      for (enn = 0, e = x->AuthenticationMethod; e; e = (struct zx_ac_AuthenticationMethod_s*)e->gg.g.n) {
	  en = zx_DEEP_CLONE_ac_AuthenticationMethod(c, e, dup_strs);
	  if (!enn)
	      x->AuthenticationMethod = en;
	  else
	      enn->gg.g.n = &en->gg.g;
	  enn = en;
      }
  }
  {
      struct zx_ac_GoverningAgreements_s* e;
      struct zx_ac_GoverningAgreements_s* en;
      struct zx_ac_GoverningAgreements_s* enn;
      for (enn = 0, e = x->GoverningAgreements; e; e = (struct zx_ac_GoverningAgreements_s*)e->gg.g.n) {
	  en = zx_DEEP_CLONE_ac_GoverningAgreements(c, e, dup_strs);
	  if (!enn)
	      x->GoverningAgreements = en;
	  else
	      enn->gg.g.n = &en->gg.g;
	  enn = en;
      }
  }
  {
      struct zx_ac_AuthenticatingAuthority_s* e;
      struct zx_ac_AuthenticatingAuthority_s* en;
      struct zx_ac_AuthenticatingAuthority_s* enn;
      for (enn = 0, e = x->AuthenticatingAuthority; e; e = (struct zx_ac_AuthenticatingAuthority_s*)e->gg.g.n) {
	  en = zx_DEEP_CLONE_ac_AuthenticatingAuthority(c, e, dup_strs);
	  if (!enn)
	      x->AuthenticatingAuthority = en;
	  else
	      enn->gg.g.n = &en->gg.g;
	  enn = en;
      }
  }
  {
      struct zx_ac_Extension_s* e;
      struct zx_ac_Extension_s* en;
      struct zx_ac_Extension_s* enn;
      for (enn = 0, e = x->Extension; e; e = (struct zx_ac_Extension_s*)e->gg.g.n) {
	  en = zx_DEEP_CLONE_ac_Extension(c, e, dup_strs);
	  if (!enn)
	      x->Extension = en;
	  else
	      enn->gg.g.n = &en->gg.g;
	  enn = en;
      }
  }

  return x;
}

/* FUNC(zx_WALK_SO_ac_AuthenticationContextStatement) */

/* Depth first traversal of the tree in either schema order or the wire order. */
 
int zx_WALK_SO_ac_AuthenticationContextStatement(struct zx_ctx* c, struct zx_ac_AuthenticationContextStatement_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
{
  int ret = callback(&x->gg.g, ctx);
  if (ret)
    return ret;
  
  /* *** deal with xmlns specifications in exc c14n way */


  
  ret = zx_walk_so_unknown_attributes(c, &x->gg, ctx, callback); 
  if (ret)
    return ret;

  {
      struct zx_ac_Identification_s* e;
      for (e = x->Identification; e; e = (struct zx_ac_Identification_s*)e->gg.g.n) {
	  ret = zx_WALK_SO_ac_Identification(c, e, ctx, callback);
	  if (ret)
	      return ret;
      }
  }
  {
      struct zx_ac_TechnicalProtection_s* e;
      for (e = x->TechnicalProtection; e; e = (struct zx_ac_TechnicalProtection_s*)e->gg.g.n) {
	  ret = zx_WALK_SO_ac_TechnicalProtection(c, e, ctx, callback);
	  if (ret)
	      return ret;
      }
  }
  {
      struct zx_ac_OperationalProtection_s* e;
      for (e = x->OperationalProtection; e; e = (struct zx_ac_OperationalProtection_s*)e->gg.g.n) {
	  ret = zx_WALK_SO_ac_OperationalProtection(c, e, ctx, callback);
	  if (ret)
	      return ret;
      }
  }
  {
      struct zx_ac_AuthenticationMethod_s* e;
      for (e = x->AuthenticationMethod; e; e = (struct zx_ac_AuthenticationMethod_s*)e->gg.g.n) {
	  ret = zx_WALK_SO_ac_AuthenticationMethod(c, e, ctx, callback);
	  if (ret)
	      return ret;
      }
  }
  {
      struct zx_ac_GoverningAgreements_s* e;
      for (e = x->GoverningAgreements; e; e = (struct zx_ac_GoverningAgreements_s*)e->gg.g.n) {
	  ret = zx_WALK_SO_ac_GoverningAgreements(c, e, ctx, callback);
	  if (ret)
	      return ret;
      }
  }
  {
      struct zx_ac_AuthenticatingAuthority_s* e;
      for (e = x->AuthenticatingAuthority; e; e = (struct zx_ac_AuthenticatingAuthority_s*)e->gg.g.n) {
	  ret = zx_WALK_SO_ac_AuthenticatingAuthority(c, e, ctx, callback);
	  if (ret)
	      return ret;
      }
  }
  {
      struct zx_ac_Extension_s* e;
      for (e = x->Extension; e; e = (struct zx_ac_Extension_s*)e->gg.g.n) {
	  ret = zx_WALK_SO_ac_Extension(c, e, ctx, callback);
	  if (ret)
	      return ret;
      }
  }

  
  return zx_walk_so_unknown_elems_and_content(c, &x->gg, ctx, callback);
}

/* FUNC(zx_WALK_WO_ac_AuthenticationContextStatement) */

int zx_WALK_WO_ac_AuthenticationContextStatement(struct zx_ctx* c, struct zx_ac_AuthenticationContextStatement_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
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

#define EL_NAME   ac_AuthenticationMethod
#define EL_STRUCT zx_ac_AuthenticationMethod_s
#define EL_NS     ac
#define EL_TAG    AuthenticationMethod

/* FUNC(zx_FREE_ac_AuthenticationMethod) */

/* Depth first traversal of data structure to free it and its subelements. Simple
 * strings are handled as a special case according to the free_strs flag. This
 * is useful if the strings point to underlying data from the wire that was
 * allocated differently. */

/* Called by: */
void zx_FREE_ac_AuthenticationMethod(struct zx_ctx* c, struct zx_ac_AuthenticationMethod_s* x, int free_strs)
{
  /* *** deal with xmlns specifications in exc c14n way */


  {
      struct zx_ac_PrincipalAuthenticationMechanism_s* e;
      struct zx_ac_PrincipalAuthenticationMechanism_s* en;
      for (e = x->PrincipalAuthenticationMechanism; e; e = en) {
	  en = (struct zx_ac_PrincipalAuthenticationMechanism_s*)e->gg.g.n;
	  zx_FREE_ac_PrincipalAuthenticationMechanism(c, e, free_strs);
      }
  }
  {
      struct zx_ac_Authenticator_s* e;
      struct zx_ac_Authenticator_s* en;
      for (e = x->Authenticator; e; e = en) {
	  en = (struct zx_ac_Authenticator_s*)e->gg.g.n;
	  zx_FREE_ac_Authenticator(c, e, free_strs);
      }
  }
  {
      struct zx_ac_AuthenticatorTransportProtocol_s* e;
      struct zx_ac_AuthenticatorTransportProtocol_s* en;
      for (e = x->AuthenticatorTransportProtocol; e; e = en) {
	  en = (struct zx_ac_AuthenticatorTransportProtocol_s*)e->gg.g.n;
	  zx_FREE_ac_AuthenticatorTransportProtocol(c, e, free_strs);
      }
  }
  {
      struct zx_ac_Extension_s* e;
      struct zx_ac_Extension_s* en;
      for (e = x->Extension; e; e = en) {
	  en = (struct zx_ac_Extension_s*)e->gg.g.n;
	  zx_FREE_ac_Extension(c, e, free_strs);
      }
  }


  zx_free_elem_common(c, &x->gg, free_strs); 
}

/* FUNC(zx_NEW_ac_AuthenticationMethod) */

/* Trivial allocator/constructor for the datatype. */

/* Called by: */
struct zx_ac_AuthenticationMethod_s* zx_NEW_ac_AuthenticationMethod(struct zx_ctx* c)
{
  struct zx_ac_AuthenticationMethod_s* x = ZX_ZALLOC(c, struct zx_ac_AuthenticationMethod_s);
  x->gg.g.tok = zx_ac_AuthenticationMethod_ELEM;
  return x;
}

#ifdef ZX_ENA_AUX

/* FUNC(zx_DUP_STRS_ac_AuthenticationMethod) */

/* Depth first traversal of data structure to copy its simple strings
 * to memory allocated from the memory allocator. The decoder will
 * use the underlying wireprotocol PDU buffer for strings, i.e.
 * strings are not copied - they point to the real data. If the
 * datastructure needs to outlast the protocol data or needs a different
 * memory allocation strategy, you need to call this function.  */

/* Called by: */
void zx_DUP_STRS_ac_AuthenticationMethod(struct zx_ctx* c, struct zx_ac_AuthenticationMethod_s* x)
{
  zx_dup_strs_common(c, &x->gg);
  /* *** deal with xmlns specifications in exc c14n way */


  {
      struct zx_ac_PrincipalAuthenticationMechanism_s* e;
      for (e = x->PrincipalAuthenticationMechanism; e; e = (struct zx_ac_PrincipalAuthenticationMechanism_s*)e->gg.g.n)
	  zx_DUP_STRS_ac_PrincipalAuthenticationMechanism(c, e);
  }
  {
      struct zx_ac_Authenticator_s* e;
      for (e = x->Authenticator; e; e = (struct zx_ac_Authenticator_s*)e->gg.g.n)
	  zx_DUP_STRS_ac_Authenticator(c, e);
  }
  {
      struct zx_ac_AuthenticatorTransportProtocol_s* e;
      for (e = x->AuthenticatorTransportProtocol; e; e = (struct zx_ac_AuthenticatorTransportProtocol_s*)e->gg.g.n)
	  zx_DUP_STRS_ac_AuthenticatorTransportProtocol(c, e);
  }
  {
      struct zx_ac_Extension_s* e;
      for (e = x->Extension; e; e = (struct zx_ac_Extension_s*)e->gg.g.n)
	  zx_DUP_STRS_ac_Extension(c, e);
  }

}

/* FUNC(zx_DEEP_CLONE_ac_AuthenticationMethod) */

/* Depth first traversal of data structure to clone it and its sublements.
 * The simple strings are handled as a special case according to dup_strs flag. */

/* Called by: */
struct zx_ac_AuthenticationMethod_s* zx_DEEP_CLONE_ac_AuthenticationMethod(struct zx_ctx* c, struct zx_ac_AuthenticationMethod_s* x, int dup_strs)
{
  x = (struct zx_ac_AuthenticationMethod_s*)zx_clone_elem_common(c, &x->gg, sizeof(struct zx_ac_AuthenticationMethod_s), dup_strs);
  /* *** deal with xmlns specifications in exc c14n way */


  {
      struct zx_ac_PrincipalAuthenticationMechanism_s* e;
      struct zx_ac_PrincipalAuthenticationMechanism_s* en;
      struct zx_ac_PrincipalAuthenticationMechanism_s* enn;
      for (enn = 0, e = x->PrincipalAuthenticationMechanism; e; e = (struct zx_ac_PrincipalAuthenticationMechanism_s*)e->gg.g.n) {
	  en = zx_DEEP_CLONE_ac_PrincipalAuthenticationMechanism(c, e, dup_strs);
	  if (!enn)
	      x->PrincipalAuthenticationMechanism = en;
	  else
	      enn->gg.g.n = &en->gg.g;
	  enn = en;
      }
  }
  {
      struct zx_ac_Authenticator_s* e;
      struct zx_ac_Authenticator_s* en;
      struct zx_ac_Authenticator_s* enn;
      for (enn = 0, e = x->Authenticator; e; e = (struct zx_ac_Authenticator_s*)e->gg.g.n) {
	  en = zx_DEEP_CLONE_ac_Authenticator(c, e, dup_strs);
	  if (!enn)
	      x->Authenticator = en;
	  else
	      enn->gg.g.n = &en->gg.g;
	  enn = en;
      }
  }
  {
      struct zx_ac_AuthenticatorTransportProtocol_s* e;
      struct zx_ac_AuthenticatorTransportProtocol_s* en;
      struct zx_ac_AuthenticatorTransportProtocol_s* enn;
      for (enn = 0, e = x->AuthenticatorTransportProtocol; e; e = (struct zx_ac_AuthenticatorTransportProtocol_s*)e->gg.g.n) {
	  en = zx_DEEP_CLONE_ac_AuthenticatorTransportProtocol(c, e, dup_strs);
	  if (!enn)
	      x->AuthenticatorTransportProtocol = en;
	  else
	      enn->gg.g.n = &en->gg.g;
	  enn = en;
      }
  }
  {
      struct zx_ac_Extension_s* e;
      struct zx_ac_Extension_s* en;
      struct zx_ac_Extension_s* enn;
      for (enn = 0, e = x->Extension; e; e = (struct zx_ac_Extension_s*)e->gg.g.n) {
	  en = zx_DEEP_CLONE_ac_Extension(c, e, dup_strs);
	  if (!enn)
	      x->Extension = en;
	  else
	      enn->gg.g.n = &en->gg.g;
	  enn = en;
      }
  }

  return x;
}

/* FUNC(zx_WALK_SO_ac_AuthenticationMethod) */

/* Depth first traversal of the tree in either schema order or the wire order. */
 
int zx_WALK_SO_ac_AuthenticationMethod(struct zx_ctx* c, struct zx_ac_AuthenticationMethod_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
{
  int ret = callback(&x->gg.g, ctx);
  if (ret)
    return ret;
  
  /* *** deal with xmlns specifications in exc c14n way */


  
  ret = zx_walk_so_unknown_attributes(c, &x->gg, ctx, callback); 
  if (ret)
    return ret;

  {
      struct zx_ac_PrincipalAuthenticationMechanism_s* e;
      for (e = x->PrincipalAuthenticationMechanism; e; e = (struct zx_ac_PrincipalAuthenticationMechanism_s*)e->gg.g.n) {
	  ret = zx_WALK_SO_ac_PrincipalAuthenticationMechanism(c, e, ctx, callback);
	  if (ret)
	      return ret;
      }
  }
  {
      struct zx_ac_Authenticator_s* e;
      for (e = x->Authenticator; e; e = (struct zx_ac_Authenticator_s*)e->gg.g.n) {
	  ret = zx_WALK_SO_ac_Authenticator(c, e, ctx, callback);
	  if (ret)
	      return ret;
      }
  }
  {
      struct zx_ac_AuthenticatorTransportProtocol_s* e;
      for (e = x->AuthenticatorTransportProtocol; e; e = (struct zx_ac_AuthenticatorTransportProtocol_s*)e->gg.g.n) {
	  ret = zx_WALK_SO_ac_AuthenticatorTransportProtocol(c, e, ctx, callback);
	  if (ret)
	      return ret;
      }
  }
  {
      struct zx_ac_Extension_s* e;
      for (e = x->Extension; e; e = (struct zx_ac_Extension_s*)e->gg.g.n) {
	  ret = zx_WALK_SO_ac_Extension(c, e, ctx, callback);
	  if (ret)
	      return ret;
      }
  }

  
  return zx_walk_so_unknown_elems_and_content(c, &x->gg, ctx, callback);
}

/* FUNC(zx_WALK_WO_ac_AuthenticationMethod) */

int zx_WALK_WO_ac_AuthenticationMethod(struct zx_ctx* c, struct zx_ac_AuthenticationMethod_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
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

#define EL_NAME   ac_Authenticator
#define EL_STRUCT zx_ac_Authenticator_s
#define EL_NS     ac
#define EL_TAG    Authenticator

/* FUNC(zx_FREE_ac_Authenticator) */

/* Depth first traversal of data structure to free it and its subelements. Simple
 * strings are handled as a special case according to the free_strs flag. This
 * is useful if the strings point to underlying data from the wire that was
 * allocated differently. */

/* Called by: */
void zx_FREE_ac_Authenticator(struct zx_ctx* c, struct zx_ac_Authenticator_s* x, int free_strs)
{
  /* *** deal with xmlns specifications in exc c14n way */


  {
      struct zx_ac_PreviousSession_s* e;
      struct zx_ac_PreviousSession_s* en;
      for (e = x->PreviousSession; e; e = en) {
	  en = (struct zx_ac_PreviousSession_s*)e->gg.g.n;
	  zx_FREE_ac_PreviousSession(c, e, free_strs);
      }
  }
  {
      struct zx_ac_ResumeSession_s* e;
      struct zx_ac_ResumeSession_s* en;
      for (e = x->ResumeSession; e; e = en) {
	  en = (struct zx_ac_ResumeSession_s*)e->gg.g.n;
	  zx_FREE_ac_ResumeSession(c, e, free_strs);
      }
  }
  {
      struct zx_ac_DigSig_s* e;
      struct zx_ac_DigSig_s* en;
      for (e = x->DigSig; e; e = en) {
	  en = (struct zx_ac_DigSig_s*)e->gg.g.n;
	  zx_FREE_ac_DigSig(c, e, free_strs);
      }
  }
  {
      struct zx_ac_Password_s* e;
      struct zx_ac_Password_s* en;
      for (e = x->Password; e; e = en) {
	  en = (struct zx_ac_Password_s*)e->gg.g.n;
	  zx_FREE_ac_Password(c, e, free_strs);
      }
  }
  {
      struct zx_ac_ZeroKnowledge_s* e;
      struct zx_ac_ZeroKnowledge_s* en;
      for (e = x->ZeroKnowledge; e; e = en) {
	  en = (struct zx_ac_ZeroKnowledge_s*)e->gg.g.n;
	  zx_FREE_ac_ZeroKnowledge(c, e, free_strs);
      }
  }
  {
      struct zx_ac_SharedSecretChallengeResponse_s* e;
      struct zx_ac_SharedSecretChallengeResponse_s* en;
      for (e = x->SharedSecretChallengeResponse; e; e = en) {
	  en = (struct zx_ac_SharedSecretChallengeResponse_s*)e->gg.g.n;
	  zx_FREE_ac_SharedSecretChallengeResponse(c, e, free_strs);
      }
  }
  {
      struct zx_ac_SharedSecretDynamicPlaintext_s* e;
      struct zx_ac_SharedSecretDynamicPlaintext_s* en;
      for (e = x->SharedSecretDynamicPlaintext; e; e = en) {
	  en = (struct zx_ac_SharedSecretDynamicPlaintext_s*)e->gg.g.n;
	  zx_FREE_ac_SharedSecretDynamicPlaintext(c, e, free_strs);
      }
  }
  {
      struct zx_ac_IPAddress_s* e;
      struct zx_ac_IPAddress_s* en;
      for (e = x->IPAddress; e; e = en) {
	  en = (struct zx_ac_IPAddress_s*)e->gg.g.n;
	  zx_FREE_ac_IPAddress(c, e, free_strs);
      }
  }
  {
      struct zx_ac_AsymmetricDecryption_s* e;
      struct zx_ac_AsymmetricDecryption_s* en;
      for (e = x->AsymmetricDecryption; e; e = en) {
	  en = (struct zx_ac_AsymmetricDecryption_s*)e->gg.g.n;
	  zx_FREE_ac_AsymmetricDecryption(c, e, free_strs);
      }
  }
  {
      struct zx_ac_AsymmetricKeyAgreement_s* e;
      struct zx_ac_AsymmetricKeyAgreement_s* en;
      for (e = x->AsymmetricKeyAgreement; e; e = en) {
	  en = (struct zx_ac_AsymmetricKeyAgreement_s*)e->gg.g.n;
	  zx_FREE_ac_AsymmetricKeyAgreement(c, e, free_strs);
      }
  }
  {
      struct zx_ac_Extension_s* e;
      struct zx_ac_Extension_s* en;
      for (e = x->Extension; e; e = en) {
	  en = (struct zx_ac_Extension_s*)e->gg.g.n;
	  zx_FREE_ac_Extension(c, e, free_strs);
      }
  }


  zx_free_elem_common(c, &x->gg, free_strs); 
}

/* FUNC(zx_NEW_ac_Authenticator) */

/* Trivial allocator/constructor for the datatype. */

/* Called by: */
struct zx_ac_Authenticator_s* zx_NEW_ac_Authenticator(struct zx_ctx* c)
{
  struct zx_ac_Authenticator_s* x = ZX_ZALLOC(c, struct zx_ac_Authenticator_s);
  x->gg.g.tok = zx_ac_Authenticator_ELEM;
  return x;
}

#ifdef ZX_ENA_AUX

/* FUNC(zx_DUP_STRS_ac_Authenticator) */

/* Depth first traversal of data structure to copy its simple strings
 * to memory allocated from the memory allocator. The decoder will
 * use the underlying wireprotocol PDU buffer for strings, i.e.
 * strings are not copied - they point to the real data. If the
 * datastructure needs to outlast the protocol data or needs a different
 * memory allocation strategy, you need to call this function.  */

/* Called by: */
void zx_DUP_STRS_ac_Authenticator(struct zx_ctx* c, struct zx_ac_Authenticator_s* x)
{
  zx_dup_strs_common(c, &x->gg);
  /* *** deal with xmlns specifications in exc c14n way */


  {
      struct zx_ac_PreviousSession_s* e;
      for (e = x->PreviousSession; e; e = (struct zx_ac_PreviousSession_s*)e->gg.g.n)
	  zx_DUP_STRS_ac_PreviousSession(c, e);
  }
  {
      struct zx_ac_ResumeSession_s* e;
      for (e = x->ResumeSession; e; e = (struct zx_ac_ResumeSession_s*)e->gg.g.n)
	  zx_DUP_STRS_ac_ResumeSession(c, e);
  }
  {
      struct zx_ac_DigSig_s* e;
      for (e = x->DigSig; e; e = (struct zx_ac_DigSig_s*)e->gg.g.n)
	  zx_DUP_STRS_ac_DigSig(c, e);
  }
  {
      struct zx_ac_Password_s* e;
      for (e = x->Password; e; e = (struct zx_ac_Password_s*)e->gg.g.n)
	  zx_DUP_STRS_ac_Password(c, e);
  }
  {
      struct zx_ac_ZeroKnowledge_s* e;
      for (e = x->ZeroKnowledge; e; e = (struct zx_ac_ZeroKnowledge_s*)e->gg.g.n)
	  zx_DUP_STRS_ac_ZeroKnowledge(c, e);
  }
  {
      struct zx_ac_SharedSecretChallengeResponse_s* e;
      for (e = x->SharedSecretChallengeResponse; e; e = (struct zx_ac_SharedSecretChallengeResponse_s*)e->gg.g.n)
	  zx_DUP_STRS_ac_SharedSecretChallengeResponse(c, e);
  }
  {
      struct zx_ac_SharedSecretDynamicPlaintext_s* e;
      for (e = x->SharedSecretDynamicPlaintext; e; e = (struct zx_ac_SharedSecretDynamicPlaintext_s*)e->gg.g.n)
	  zx_DUP_STRS_ac_SharedSecretDynamicPlaintext(c, e);
  }
  {
      struct zx_ac_IPAddress_s* e;
      for (e = x->IPAddress; e; e = (struct zx_ac_IPAddress_s*)e->gg.g.n)
	  zx_DUP_STRS_ac_IPAddress(c, e);
  }
  {
      struct zx_ac_AsymmetricDecryption_s* e;
      for (e = x->AsymmetricDecryption; e; e = (struct zx_ac_AsymmetricDecryption_s*)e->gg.g.n)
	  zx_DUP_STRS_ac_AsymmetricDecryption(c, e);
  }
  {
      struct zx_ac_AsymmetricKeyAgreement_s* e;
      for (e = x->AsymmetricKeyAgreement; e; e = (struct zx_ac_AsymmetricKeyAgreement_s*)e->gg.g.n)
	  zx_DUP_STRS_ac_AsymmetricKeyAgreement(c, e);
  }
  {
      struct zx_ac_Extension_s* e;
      for (e = x->Extension; e; e = (struct zx_ac_Extension_s*)e->gg.g.n)
	  zx_DUP_STRS_ac_Extension(c, e);
  }

}

/* FUNC(zx_DEEP_CLONE_ac_Authenticator) */

/* Depth first traversal of data structure to clone it and its sublements.
 * The simple strings are handled as a special case according to dup_strs flag. */

/* Called by: */
struct zx_ac_Authenticator_s* zx_DEEP_CLONE_ac_Authenticator(struct zx_ctx* c, struct zx_ac_Authenticator_s* x, int dup_strs)
{
  x = (struct zx_ac_Authenticator_s*)zx_clone_elem_common(c, &x->gg, sizeof(struct zx_ac_Authenticator_s), dup_strs);
  /* *** deal with xmlns specifications in exc c14n way */


  {
      struct zx_ac_PreviousSession_s* e;
      struct zx_ac_PreviousSession_s* en;
      struct zx_ac_PreviousSession_s* enn;
      for (enn = 0, e = x->PreviousSession; e; e = (struct zx_ac_PreviousSession_s*)e->gg.g.n) {
	  en = zx_DEEP_CLONE_ac_PreviousSession(c, e, dup_strs);
	  if (!enn)
	      x->PreviousSession = en;
	  else
	      enn->gg.g.n = &en->gg.g;
	  enn = en;
      }
  }
  {
      struct zx_ac_ResumeSession_s* e;
      struct zx_ac_ResumeSession_s* en;
      struct zx_ac_ResumeSession_s* enn;
      for (enn = 0, e = x->ResumeSession; e; e = (struct zx_ac_ResumeSession_s*)e->gg.g.n) {
	  en = zx_DEEP_CLONE_ac_ResumeSession(c, e, dup_strs);
	  if (!enn)
	      x->ResumeSession = en;
	  else
	      enn->gg.g.n = &en->gg.g;
	  enn = en;
      }
  }
  {
      struct zx_ac_DigSig_s* e;
      struct zx_ac_DigSig_s* en;
      struct zx_ac_DigSig_s* enn;
      for (enn = 0, e = x->DigSig; e; e = (struct zx_ac_DigSig_s*)e->gg.g.n) {
	  en = zx_DEEP_CLONE_ac_DigSig(c, e, dup_strs);
	  if (!enn)
	      x->DigSig = en;
	  else
	      enn->gg.g.n = &en->gg.g;
	  enn = en;
      }
  }
  {
      struct zx_ac_Password_s* e;
      struct zx_ac_Password_s* en;
      struct zx_ac_Password_s* enn;
      for (enn = 0, e = x->Password; e; e = (struct zx_ac_Password_s*)e->gg.g.n) {
	  en = zx_DEEP_CLONE_ac_Password(c, e, dup_strs);
	  if (!enn)
	      x->Password = en;
	  else
	      enn->gg.g.n = &en->gg.g;
	  enn = en;
      }
  }
  {
      struct zx_ac_ZeroKnowledge_s* e;
      struct zx_ac_ZeroKnowledge_s* en;
      struct zx_ac_ZeroKnowledge_s* enn;
      for (enn = 0, e = x->ZeroKnowledge; e; e = (struct zx_ac_ZeroKnowledge_s*)e->gg.g.n) {
	  en = zx_DEEP_CLONE_ac_ZeroKnowledge(c, e, dup_strs);
	  if (!enn)
	      x->ZeroKnowledge = en;
	  else
	      enn->gg.g.n = &en->gg.g;
	  enn = en;
      }
  }
  {
      struct zx_ac_SharedSecretChallengeResponse_s* e;
      struct zx_ac_SharedSecretChallengeResponse_s* en;
      struct zx_ac_SharedSecretChallengeResponse_s* enn;
      for (enn = 0, e = x->SharedSecretChallengeResponse; e; e = (struct zx_ac_SharedSecretChallengeResponse_s*)e->gg.g.n) {
	  en = zx_DEEP_CLONE_ac_SharedSecretChallengeResponse(c, e, dup_strs);
	  if (!enn)
	      x->SharedSecretChallengeResponse = en;
	  else
	      enn->gg.g.n = &en->gg.g;
	  enn = en;
      }
  }
  {
      struct zx_ac_SharedSecretDynamicPlaintext_s* e;
      struct zx_ac_SharedSecretDynamicPlaintext_s* en;
      struct zx_ac_SharedSecretDynamicPlaintext_s* enn;
      for (enn = 0, e = x->SharedSecretDynamicPlaintext; e; e = (struct zx_ac_SharedSecretDynamicPlaintext_s*)e->gg.g.n) {
	  en = zx_DEEP_CLONE_ac_SharedSecretDynamicPlaintext(c, e, dup_strs);
	  if (!enn)
	      x->SharedSecretDynamicPlaintext = en;
	  else
	      enn->gg.g.n = &en->gg.g;
	  enn = en;
      }
  }
  {
      struct zx_ac_IPAddress_s* e;
      struct zx_ac_IPAddress_s* en;
      struct zx_ac_IPAddress_s* enn;
      for (enn = 0, e = x->IPAddress; e; e = (struct zx_ac_IPAddress_s*)e->gg.g.n) {
	  en = zx_DEEP_CLONE_ac_IPAddress(c, e, dup_strs);
	  if (!enn)
	      x->IPAddress = en;
	  else
	      enn->gg.g.n = &en->gg.g;
	  enn = en;
      }
  }
  {
      struct zx_ac_AsymmetricDecryption_s* e;
      struct zx_ac_AsymmetricDecryption_s* en;
      struct zx_ac_AsymmetricDecryption_s* enn;
      for (enn = 0, e = x->AsymmetricDecryption; e; e = (struct zx_ac_AsymmetricDecryption_s*)e->gg.g.n) {
	  en = zx_DEEP_CLONE_ac_AsymmetricDecryption(c, e, dup_strs);
	  if (!enn)
	      x->AsymmetricDecryption = en;
	  else
	      enn->gg.g.n = &en->gg.g;
	  enn = en;
      }
  }
  {
      struct zx_ac_AsymmetricKeyAgreement_s* e;
      struct zx_ac_AsymmetricKeyAgreement_s* en;
      struct zx_ac_AsymmetricKeyAgreement_s* enn;
      for (enn = 0, e = x->AsymmetricKeyAgreement; e; e = (struct zx_ac_AsymmetricKeyAgreement_s*)e->gg.g.n) {
	  en = zx_DEEP_CLONE_ac_AsymmetricKeyAgreement(c, e, dup_strs);
	  if (!enn)
	      x->AsymmetricKeyAgreement = en;
	  else
	      enn->gg.g.n = &en->gg.g;
	  enn = en;
      }
  }
  {
      struct zx_ac_Extension_s* e;
      struct zx_ac_Extension_s* en;
      struct zx_ac_Extension_s* enn;
      for (enn = 0, e = x->Extension; e; e = (struct zx_ac_Extension_s*)e->gg.g.n) {
	  en = zx_DEEP_CLONE_ac_Extension(c, e, dup_strs);
	  if (!enn)
	      x->Extension = en;
	  else
	      enn->gg.g.n = &en->gg.g;
	  enn = en;
      }
  }

  return x;
}

/* FUNC(zx_WALK_SO_ac_Authenticator) */

/* Depth first traversal of the tree in either schema order or the wire order. */
 
int zx_WALK_SO_ac_Authenticator(struct zx_ctx* c, struct zx_ac_Authenticator_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
{
  int ret = callback(&x->gg.g, ctx);
  if (ret)
    return ret;
  
  /* *** deal with xmlns specifications in exc c14n way */


  
  ret = zx_walk_so_unknown_attributes(c, &x->gg, ctx, callback); 
  if (ret)
    return ret;

  {
      struct zx_ac_PreviousSession_s* e;
      for (e = x->PreviousSession; e; e = (struct zx_ac_PreviousSession_s*)e->gg.g.n) {
	  ret = zx_WALK_SO_ac_PreviousSession(c, e, ctx, callback);
	  if (ret)
	      return ret;
      }
  }
  {
      struct zx_ac_ResumeSession_s* e;
      for (e = x->ResumeSession; e; e = (struct zx_ac_ResumeSession_s*)e->gg.g.n) {
	  ret = zx_WALK_SO_ac_ResumeSession(c, e, ctx, callback);
	  if (ret)
	      return ret;
      }
  }
  {
      struct zx_ac_DigSig_s* e;
      for (e = x->DigSig; e; e = (struct zx_ac_DigSig_s*)e->gg.g.n) {
	  ret = zx_WALK_SO_ac_DigSig(c, e, ctx, callback);
	  if (ret)
	      return ret;
      }
  }
  {
      struct zx_ac_Password_s* e;
      for (e = x->Password; e; e = (struct zx_ac_Password_s*)e->gg.g.n) {
	  ret = zx_WALK_SO_ac_Password(c, e, ctx, callback);
	  if (ret)
	      return ret;
      }
  }
  {
      struct zx_ac_ZeroKnowledge_s* e;
      for (e = x->ZeroKnowledge; e; e = (struct zx_ac_ZeroKnowledge_s*)e->gg.g.n) {
	  ret = zx_WALK_SO_ac_ZeroKnowledge(c, e, ctx, callback);
	  if (ret)
	      return ret;
      }
  }
  {
      struct zx_ac_SharedSecretChallengeResponse_s* e;
      for (e = x->SharedSecretChallengeResponse; e; e = (struct zx_ac_SharedSecretChallengeResponse_s*)e->gg.g.n) {
	  ret = zx_WALK_SO_ac_SharedSecretChallengeResponse(c, e, ctx, callback);
	  if (ret)
	      return ret;
      }
  }
  {
      struct zx_ac_SharedSecretDynamicPlaintext_s* e;
      for (e = x->SharedSecretDynamicPlaintext; e; e = (struct zx_ac_SharedSecretDynamicPlaintext_s*)e->gg.g.n) {
	  ret = zx_WALK_SO_ac_SharedSecretDynamicPlaintext(c, e, ctx, callback);
	  if (ret)
	      return ret;
      }
  }
  {
      struct zx_ac_IPAddress_s* e;
      for (e = x->IPAddress; e; e = (struct zx_ac_IPAddress_s*)e->gg.g.n) {
	  ret = zx_WALK_SO_ac_IPAddress(c, e, ctx, callback);
	  if (ret)
	      return ret;
      }
  }
  {
      struct zx_ac_AsymmetricDecryption_s* e;
      for (e = x->AsymmetricDecryption; e; e = (struct zx_ac_AsymmetricDecryption_s*)e->gg.g.n) {
	  ret = zx_WALK_SO_ac_AsymmetricDecryption(c, e, ctx, callback);
	  if (ret)
	      return ret;
      }
  }
  {
      struct zx_ac_AsymmetricKeyAgreement_s* e;
      for (e = x->AsymmetricKeyAgreement; e; e = (struct zx_ac_AsymmetricKeyAgreement_s*)e->gg.g.n) {
	  ret = zx_WALK_SO_ac_AsymmetricKeyAgreement(c, e, ctx, callback);
	  if (ret)
	      return ret;
      }
  }
  {
      struct zx_ac_Extension_s* e;
      for (e = x->Extension; e; e = (struct zx_ac_Extension_s*)e->gg.g.n) {
	  ret = zx_WALK_SO_ac_Extension(c, e, ctx, callback);
	  if (ret)
	      return ret;
      }
  }

  
  return zx_walk_so_unknown_elems_and_content(c, &x->gg, ctx, callback);
}

/* FUNC(zx_WALK_WO_ac_Authenticator) */

int zx_WALK_WO_ac_Authenticator(struct zx_ctx* c, struct zx_ac_Authenticator_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
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

#define EL_NAME   ac_AuthenticatorTransportProtocol
#define EL_STRUCT zx_ac_AuthenticatorTransportProtocol_s
#define EL_NS     ac
#define EL_TAG    AuthenticatorTransportProtocol

/* FUNC(zx_FREE_ac_AuthenticatorTransportProtocol) */

/* Depth first traversal of data structure to free it and its subelements. Simple
 * strings are handled as a special case according to the free_strs flag. This
 * is useful if the strings point to underlying data from the wire that was
 * allocated differently. */

/* Called by: */
void zx_FREE_ac_AuthenticatorTransportProtocol(struct zx_ctx* c, struct zx_ac_AuthenticatorTransportProtocol_s* x, int free_strs)
{
  /* *** deal with xmlns specifications in exc c14n way */


  {
      struct zx_ac_HTTP_s* e;
      struct zx_ac_HTTP_s* en;
      for (e = x->HTTP; e; e = en) {
	  en = (struct zx_ac_HTTP_s*)e->gg.g.n;
	  zx_FREE_ac_HTTP(c, e, free_strs);
      }
  }
  {
      struct zx_ac_SSL_s* e;
      struct zx_ac_SSL_s* en;
      for (e = x->SSL; e; e = en) {
	  en = (struct zx_ac_SSL_s*)e->gg.g.n;
	  zx_FREE_ac_SSL(c, e, free_strs);
      }
  }
  {
      struct zx_ac_MobileNetworkNoEncryption_s* e;
      struct zx_ac_MobileNetworkNoEncryption_s* en;
      for (e = x->MobileNetworkNoEncryption; e; e = en) {
	  en = (struct zx_ac_MobileNetworkNoEncryption_s*)e->gg.g.n;
	  zx_FREE_ac_MobileNetworkNoEncryption(c, e, free_strs);
      }
  }
  {
      struct zx_ac_MobileNetworkRadioEncryption_s* e;
      struct zx_ac_MobileNetworkRadioEncryption_s* en;
      for (e = x->MobileNetworkRadioEncryption; e; e = en) {
	  en = (struct zx_ac_MobileNetworkRadioEncryption_s*)e->gg.g.n;
	  zx_FREE_ac_MobileNetworkRadioEncryption(c, e, free_strs);
      }
  }
  {
      struct zx_ac_MobileNetworkEndToEndEncryption_s* e;
      struct zx_ac_MobileNetworkEndToEndEncryption_s* en;
      for (e = x->MobileNetworkEndToEndEncryption; e; e = en) {
	  en = (struct zx_ac_MobileNetworkEndToEndEncryption_s*)e->gg.g.n;
	  zx_FREE_ac_MobileNetworkEndToEndEncryption(c, e, free_strs);
      }
  }
  {
      struct zx_ac_WTLS_s* e;
      struct zx_ac_WTLS_s* en;
      for (e = x->WTLS; e; e = en) {
	  en = (struct zx_ac_WTLS_s*)e->gg.g.n;
	  zx_FREE_ac_WTLS(c, e, free_strs);
      }
  }
  {
      struct zx_ac_IPSec_s* e;
      struct zx_ac_IPSec_s* en;
      for (e = x->IPSec; e; e = en) {
	  en = (struct zx_ac_IPSec_s*)e->gg.g.n;
	  zx_FREE_ac_IPSec(c, e, free_strs);
      }
  }
  {
      struct zx_ac_Extension_s* e;
      struct zx_ac_Extension_s* en;
      for (e = x->Extension; e; e = en) {
	  en = (struct zx_ac_Extension_s*)e->gg.g.n;
	  zx_FREE_ac_Extension(c, e, free_strs);
      }
  }


  zx_free_elem_common(c, &x->gg, free_strs); 
}

/* FUNC(zx_NEW_ac_AuthenticatorTransportProtocol) */

/* Trivial allocator/constructor for the datatype. */

/* Called by: */
struct zx_ac_AuthenticatorTransportProtocol_s* zx_NEW_ac_AuthenticatorTransportProtocol(struct zx_ctx* c)
{
  struct zx_ac_AuthenticatorTransportProtocol_s* x = ZX_ZALLOC(c, struct zx_ac_AuthenticatorTransportProtocol_s);
  x->gg.g.tok = zx_ac_AuthenticatorTransportProtocol_ELEM;
  return x;
}

#ifdef ZX_ENA_AUX

/* FUNC(zx_DUP_STRS_ac_AuthenticatorTransportProtocol) */

/* Depth first traversal of data structure to copy its simple strings
 * to memory allocated from the memory allocator. The decoder will
 * use the underlying wireprotocol PDU buffer for strings, i.e.
 * strings are not copied - they point to the real data. If the
 * datastructure needs to outlast the protocol data or needs a different
 * memory allocation strategy, you need to call this function.  */

/* Called by: */
void zx_DUP_STRS_ac_AuthenticatorTransportProtocol(struct zx_ctx* c, struct zx_ac_AuthenticatorTransportProtocol_s* x)
{
  zx_dup_strs_common(c, &x->gg);
  /* *** deal with xmlns specifications in exc c14n way */


  {
      struct zx_ac_HTTP_s* e;
      for (e = x->HTTP; e; e = (struct zx_ac_HTTP_s*)e->gg.g.n)
	  zx_DUP_STRS_ac_HTTP(c, e);
  }
  {
      struct zx_ac_SSL_s* e;
      for (e = x->SSL; e; e = (struct zx_ac_SSL_s*)e->gg.g.n)
	  zx_DUP_STRS_ac_SSL(c, e);
  }
  {
      struct zx_ac_MobileNetworkNoEncryption_s* e;
      for (e = x->MobileNetworkNoEncryption; e; e = (struct zx_ac_MobileNetworkNoEncryption_s*)e->gg.g.n)
	  zx_DUP_STRS_ac_MobileNetworkNoEncryption(c, e);
  }
  {
      struct zx_ac_MobileNetworkRadioEncryption_s* e;
      for (e = x->MobileNetworkRadioEncryption; e; e = (struct zx_ac_MobileNetworkRadioEncryption_s*)e->gg.g.n)
	  zx_DUP_STRS_ac_MobileNetworkRadioEncryption(c, e);
  }
  {
      struct zx_ac_MobileNetworkEndToEndEncryption_s* e;
      for (e = x->MobileNetworkEndToEndEncryption; e; e = (struct zx_ac_MobileNetworkEndToEndEncryption_s*)e->gg.g.n)
	  zx_DUP_STRS_ac_MobileNetworkEndToEndEncryption(c, e);
  }
  {
      struct zx_ac_WTLS_s* e;
      for (e = x->WTLS; e; e = (struct zx_ac_WTLS_s*)e->gg.g.n)
	  zx_DUP_STRS_ac_WTLS(c, e);
  }
  {
      struct zx_ac_IPSec_s* e;
      for (e = x->IPSec; e; e = (struct zx_ac_IPSec_s*)e->gg.g.n)
	  zx_DUP_STRS_ac_IPSec(c, e);
  }
  {
      struct zx_ac_Extension_s* e;
      for (e = x->Extension; e; e = (struct zx_ac_Extension_s*)e->gg.g.n)
	  zx_DUP_STRS_ac_Extension(c, e);
  }

}

/* FUNC(zx_DEEP_CLONE_ac_AuthenticatorTransportProtocol) */

/* Depth first traversal of data structure to clone it and its sublements.
 * The simple strings are handled as a special case according to dup_strs flag. */

/* Called by: */
struct zx_ac_AuthenticatorTransportProtocol_s* zx_DEEP_CLONE_ac_AuthenticatorTransportProtocol(struct zx_ctx* c, struct zx_ac_AuthenticatorTransportProtocol_s* x, int dup_strs)
{
  x = (struct zx_ac_AuthenticatorTransportProtocol_s*)zx_clone_elem_common(c, &x->gg, sizeof(struct zx_ac_AuthenticatorTransportProtocol_s), dup_strs);
  /* *** deal with xmlns specifications in exc c14n way */


  {
      struct zx_ac_HTTP_s* e;
      struct zx_ac_HTTP_s* en;
      struct zx_ac_HTTP_s* enn;
      for (enn = 0, e = x->HTTP; e; e = (struct zx_ac_HTTP_s*)e->gg.g.n) {
	  en = zx_DEEP_CLONE_ac_HTTP(c, e, dup_strs);
	  if (!enn)
	      x->HTTP = en;
	  else
	      enn->gg.g.n = &en->gg.g;
	  enn = en;
      }
  }
  {
      struct zx_ac_SSL_s* e;
      struct zx_ac_SSL_s* en;
      struct zx_ac_SSL_s* enn;
      for (enn = 0, e = x->SSL; e; e = (struct zx_ac_SSL_s*)e->gg.g.n) {
	  en = zx_DEEP_CLONE_ac_SSL(c, e, dup_strs);
	  if (!enn)
	      x->SSL = en;
	  else
	      enn->gg.g.n = &en->gg.g;
	  enn = en;
      }
  }
  {
      struct zx_ac_MobileNetworkNoEncryption_s* e;
      struct zx_ac_MobileNetworkNoEncryption_s* en;
      struct zx_ac_MobileNetworkNoEncryption_s* enn;
      for (enn = 0, e = x->MobileNetworkNoEncryption; e; e = (struct zx_ac_MobileNetworkNoEncryption_s*)e->gg.g.n) {
	  en = zx_DEEP_CLONE_ac_MobileNetworkNoEncryption(c, e, dup_strs);
	  if (!enn)
	      x->MobileNetworkNoEncryption = en;
	  else
	      enn->gg.g.n = &en->gg.g;
	  enn = en;
      }
  }
  {
      struct zx_ac_MobileNetworkRadioEncryption_s* e;
      struct zx_ac_MobileNetworkRadioEncryption_s* en;
      struct zx_ac_MobileNetworkRadioEncryption_s* enn;
      for (enn = 0, e = x->MobileNetworkRadioEncryption; e; e = (struct zx_ac_MobileNetworkRadioEncryption_s*)e->gg.g.n) {
	  en = zx_DEEP_CLONE_ac_MobileNetworkRadioEncryption(c, e, dup_strs);
	  if (!enn)
	      x->MobileNetworkRadioEncryption = en;
	  else
	      enn->gg.g.n = &en->gg.g;
	  enn = en;
      }
  }
  {
      struct zx_ac_MobileNetworkEndToEndEncryption_s* e;
      struct zx_ac_MobileNetworkEndToEndEncryption_s* en;
      struct zx_ac_MobileNetworkEndToEndEncryption_s* enn;
      for (enn = 0, e = x->MobileNetworkEndToEndEncryption; e; e = (struct zx_ac_MobileNetworkEndToEndEncryption_s*)e->gg.g.n) {
	  en = zx_DEEP_CLONE_ac_MobileNetworkEndToEndEncryption(c, e, dup_strs);
	  if (!enn)
	      x->MobileNetworkEndToEndEncryption = en;
	  else
	      enn->gg.g.n = &en->gg.g;
	  enn = en;
      }
  }
  {
      struct zx_ac_WTLS_s* e;
      struct zx_ac_WTLS_s* en;
      struct zx_ac_WTLS_s* enn;
      for (enn = 0, e = x->WTLS; e; e = (struct zx_ac_WTLS_s*)e->gg.g.n) {
	  en = zx_DEEP_CLONE_ac_WTLS(c, e, dup_strs);
	  if (!enn)
	      x->WTLS = en;
	  else
	      enn->gg.g.n = &en->gg.g;
	  enn = en;
      }
  }
  {
      struct zx_ac_IPSec_s* e;
      struct zx_ac_IPSec_s* en;
      struct zx_ac_IPSec_s* enn;
      for (enn = 0, e = x->IPSec; e; e = (struct zx_ac_IPSec_s*)e->gg.g.n) {
	  en = zx_DEEP_CLONE_ac_IPSec(c, e, dup_strs);
	  if (!enn)
	      x->IPSec = en;
	  else
	      enn->gg.g.n = &en->gg.g;
	  enn = en;
      }
  }
  {
      struct zx_ac_Extension_s* e;
      struct zx_ac_Extension_s* en;
      struct zx_ac_Extension_s* enn;
      for (enn = 0, e = x->Extension; e; e = (struct zx_ac_Extension_s*)e->gg.g.n) {
	  en = zx_DEEP_CLONE_ac_Extension(c, e, dup_strs);
	  if (!enn)
	      x->Extension = en;
	  else
	      enn->gg.g.n = &en->gg.g;
	  enn = en;
      }
  }

  return x;
}

/* FUNC(zx_WALK_SO_ac_AuthenticatorTransportProtocol) */

/* Depth first traversal of the tree in either schema order or the wire order. */
 
int zx_WALK_SO_ac_AuthenticatorTransportProtocol(struct zx_ctx* c, struct zx_ac_AuthenticatorTransportProtocol_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
{
  int ret = callback(&x->gg.g, ctx);
  if (ret)
    return ret;
  
  /* *** deal with xmlns specifications in exc c14n way */


  
  ret = zx_walk_so_unknown_attributes(c, &x->gg, ctx, callback); 
  if (ret)
    return ret;

  {
      struct zx_ac_HTTP_s* e;
      for (e = x->HTTP; e; e = (struct zx_ac_HTTP_s*)e->gg.g.n) {
	  ret = zx_WALK_SO_ac_HTTP(c, e, ctx, callback);
	  if (ret)
	      return ret;
      }
  }
  {
      struct zx_ac_SSL_s* e;
      for (e = x->SSL; e; e = (struct zx_ac_SSL_s*)e->gg.g.n) {
	  ret = zx_WALK_SO_ac_SSL(c, e, ctx, callback);
	  if (ret)
	      return ret;
      }
  }
  {
      struct zx_ac_MobileNetworkNoEncryption_s* e;
      for (e = x->MobileNetworkNoEncryption; e; e = (struct zx_ac_MobileNetworkNoEncryption_s*)e->gg.g.n) {
	  ret = zx_WALK_SO_ac_MobileNetworkNoEncryption(c, e, ctx, callback);
	  if (ret)
	      return ret;
      }
  }
  {
      struct zx_ac_MobileNetworkRadioEncryption_s* e;
      for (e = x->MobileNetworkRadioEncryption; e; e = (struct zx_ac_MobileNetworkRadioEncryption_s*)e->gg.g.n) {
	  ret = zx_WALK_SO_ac_MobileNetworkRadioEncryption(c, e, ctx, callback);
	  if (ret)
	      return ret;
      }
  }
  {
      struct zx_ac_MobileNetworkEndToEndEncryption_s* e;
      for (e = x->MobileNetworkEndToEndEncryption; e; e = (struct zx_ac_MobileNetworkEndToEndEncryption_s*)e->gg.g.n) {
	  ret = zx_WALK_SO_ac_MobileNetworkEndToEndEncryption(c, e, ctx, callback);
	  if (ret)
	      return ret;
      }
  }
  {
      struct zx_ac_WTLS_s* e;
      for (e = x->WTLS; e; e = (struct zx_ac_WTLS_s*)e->gg.g.n) {
	  ret = zx_WALK_SO_ac_WTLS(c, e, ctx, callback);
	  if (ret)
	      return ret;
      }
  }
  {
      struct zx_ac_IPSec_s* e;
      for (e = x->IPSec; e; e = (struct zx_ac_IPSec_s*)e->gg.g.n) {
	  ret = zx_WALK_SO_ac_IPSec(c, e, ctx, callback);
	  if (ret)
	      return ret;
      }
  }
  {
      struct zx_ac_Extension_s* e;
      for (e = x->Extension; e; e = (struct zx_ac_Extension_s*)e->gg.g.n) {
	  ret = zx_WALK_SO_ac_Extension(c, e, ctx, callback);
	  if (ret)
	      return ret;
      }
  }

  
  return zx_walk_so_unknown_elems_and_content(c, &x->gg, ctx, callback);
}

/* FUNC(zx_WALK_WO_ac_AuthenticatorTransportProtocol) */

int zx_WALK_WO_ac_AuthenticatorTransportProtocol(struct zx_ctx* c, struct zx_ac_AuthenticatorTransportProtocol_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
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

#define EL_NAME   ac_DeactivationCallCenter
#define EL_STRUCT zx_ac_DeactivationCallCenter_s
#define EL_NS     ac
#define EL_TAG    DeactivationCallCenter

/* FUNC(zx_FREE_ac_DeactivationCallCenter) */

/* Depth first traversal of data structure to free it and its subelements. Simple
 * strings are handled as a special case according to the free_strs flag. This
 * is useful if the strings point to underlying data from the wire that was
 * allocated differently. */

/* Called by: */
void zx_FREE_ac_DeactivationCallCenter(struct zx_ctx* c, struct zx_ac_DeactivationCallCenter_s* x, int free_strs)
{
  /* *** deal with xmlns specifications in exc c14n way */


  {
      struct zx_ac_Extension_s* e;
      struct zx_ac_Extension_s* en;
      for (e = x->Extension; e; e = en) {
	  en = (struct zx_ac_Extension_s*)e->gg.g.n;
	  zx_FREE_ac_Extension(c, e, free_strs);
      }
  }


  zx_free_elem_common(c, &x->gg, free_strs); 
}

/* FUNC(zx_NEW_ac_DeactivationCallCenter) */

/* Trivial allocator/constructor for the datatype. */

/* Called by: */
struct zx_ac_DeactivationCallCenter_s* zx_NEW_ac_DeactivationCallCenter(struct zx_ctx* c)
{
  struct zx_ac_DeactivationCallCenter_s* x = ZX_ZALLOC(c, struct zx_ac_DeactivationCallCenter_s);
  x->gg.g.tok = zx_ac_DeactivationCallCenter_ELEM;
  return x;
}

#ifdef ZX_ENA_AUX

/* FUNC(zx_DUP_STRS_ac_DeactivationCallCenter) */

/* Depth first traversal of data structure to copy its simple strings
 * to memory allocated from the memory allocator. The decoder will
 * use the underlying wireprotocol PDU buffer for strings, i.e.
 * strings are not copied - they point to the real data. If the
 * datastructure needs to outlast the protocol data or needs a different
 * memory allocation strategy, you need to call this function.  */

/* Called by: */
void zx_DUP_STRS_ac_DeactivationCallCenter(struct zx_ctx* c, struct zx_ac_DeactivationCallCenter_s* x)
{
  zx_dup_strs_common(c, &x->gg);
  /* *** deal with xmlns specifications in exc c14n way */


  {
      struct zx_ac_Extension_s* e;
      for (e = x->Extension; e; e = (struct zx_ac_Extension_s*)e->gg.g.n)
	  zx_DUP_STRS_ac_Extension(c, e);
  }

}

/* FUNC(zx_DEEP_CLONE_ac_DeactivationCallCenter) */

/* Depth first traversal of data structure to clone it and its sublements.
 * The simple strings are handled as a special case according to dup_strs flag. */

/* Called by: */
struct zx_ac_DeactivationCallCenter_s* zx_DEEP_CLONE_ac_DeactivationCallCenter(struct zx_ctx* c, struct zx_ac_DeactivationCallCenter_s* x, int dup_strs)
{
  x = (struct zx_ac_DeactivationCallCenter_s*)zx_clone_elem_common(c, &x->gg, sizeof(struct zx_ac_DeactivationCallCenter_s), dup_strs);
  /* *** deal with xmlns specifications in exc c14n way */


  {
      struct zx_ac_Extension_s* e;
      struct zx_ac_Extension_s* en;
      struct zx_ac_Extension_s* enn;
      for (enn = 0, e = x->Extension; e; e = (struct zx_ac_Extension_s*)e->gg.g.n) {
	  en = zx_DEEP_CLONE_ac_Extension(c, e, dup_strs);
	  if (!enn)
	      x->Extension = en;
	  else
	      enn->gg.g.n = &en->gg.g;
	  enn = en;
      }
  }

  return x;
}

/* FUNC(zx_WALK_SO_ac_DeactivationCallCenter) */

/* Depth first traversal of the tree in either schema order or the wire order. */
 
int zx_WALK_SO_ac_DeactivationCallCenter(struct zx_ctx* c, struct zx_ac_DeactivationCallCenter_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
{
  int ret = callback(&x->gg.g, ctx);
  if (ret)
    return ret;
  
  /* *** deal with xmlns specifications in exc c14n way */


  
  ret = zx_walk_so_unknown_attributes(c, &x->gg, ctx, callback); 
  if (ret)
    return ret;

  {
      struct zx_ac_Extension_s* e;
      for (e = x->Extension; e; e = (struct zx_ac_Extension_s*)e->gg.g.n) {
	  ret = zx_WALK_SO_ac_Extension(c, e, ctx, callback);
	  if (ret)
	      return ret;
      }
  }

  
  return zx_walk_so_unknown_elems_and_content(c, &x->gg, ctx, callback);
}

/* FUNC(zx_WALK_WO_ac_DeactivationCallCenter) */

int zx_WALK_WO_ac_DeactivationCallCenter(struct zx_ctx* c, struct zx_ac_DeactivationCallCenter_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
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

#define EL_NAME   ac_DigSig
#define EL_STRUCT zx_ac_DigSig_s
#define EL_NS     ac
#define EL_TAG    DigSig

/* FUNC(zx_FREE_ac_DigSig) */

/* Depth first traversal of data structure to free it and its subelements. Simple
 * strings are handled as a special case according to the free_strs flag. This
 * is useful if the strings point to underlying data from the wire that was
 * allocated differently. */

/* Called by: */
void zx_FREE_ac_DigSig(struct zx_ctx* c, struct zx_ac_DigSig_s* x, int free_strs)
{
  /* *** deal with xmlns specifications in exc c14n way */


  {
      struct zx_ac_Extension_s* e;
      struct zx_ac_Extension_s* en;
      for (e = x->Extension; e; e = en) {
	  en = (struct zx_ac_Extension_s*)e->gg.g.n;
	  zx_FREE_ac_Extension(c, e, free_strs);
      }
  }


  zx_free_elem_common(c, &x->gg, free_strs); 
}

/* FUNC(zx_NEW_ac_DigSig) */

/* Trivial allocator/constructor for the datatype. */

/* Called by: */
struct zx_ac_DigSig_s* zx_NEW_ac_DigSig(struct zx_ctx* c)
{
  struct zx_ac_DigSig_s* x = ZX_ZALLOC(c, struct zx_ac_DigSig_s);
  x->gg.g.tok = zx_ac_DigSig_ELEM;
  return x;
}

#ifdef ZX_ENA_AUX

/* FUNC(zx_DUP_STRS_ac_DigSig) */

/* Depth first traversal of data structure to copy its simple strings
 * to memory allocated from the memory allocator. The decoder will
 * use the underlying wireprotocol PDU buffer for strings, i.e.
 * strings are not copied - they point to the real data. If the
 * datastructure needs to outlast the protocol data or needs a different
 * memory allocation strategy, you need to call this function.  */

/* Called by: */
void zx_DUP_STRS_ac_DigSig(struct zx_ctx* c, struct zx_ac_DigSig_s* x)
{
  zx_dup_strs_common(c, &x->gg);
  /* *** deal with xmlns specifications in exc c14n way */


  {
      struct zx_ac_Extension_s* e;
      for (e = x->Extension; e; e = (struct zx_ac_Extension_s*)e->gg.g.n)
	  zx_DUP_STRS_ac_Extension(c, e);
  }

}

/* FUNC(zx_DEEP_CLONE_ac_DigSig) */

/* Depth first traversal of data structure to clone it and its sublements.
 * The simple strings are handled as a special case according to dup_strs flag. */

/* Called by: */
struct zx_ac_DigSig_s* zx_DEEP_CLONE_ac_DigSig(struct zx_ctx* c, struct zx_ac_DigSig_s* x, int dup_strs)
{
  x = (struct zx_ac_DigSig_s*)zx_clone_elem_common(c, &x->gg, sizeof(struct zx_ac_DigSig_s), dup_strs);
  /* *** deal with xmlns specifications in exc c14n way */


  {
      struct zx_ac_Extension_s* e;
      struct zx_ac_Extension_s* en;
      struct zx_ac_Extension_s* enn;
      for (enn = 0, e = x->Extension; e; e = (struct zx_ac_Extension_s*)e->gg.g.n) {
	  en = zx_DEEP_CLONE_ac_Extension(c, e, dup_strs);
	  if (!enn)
	      x->Extension = en;
	  else
	      enn->gg.g.n = &en->gg.g;
	  enn = en;
      }
  }

  return x;
}

/* FUNC(zx_WALK_SO_ac_DigSig) */

/* Depth first traversal of the tree in either schema order or the wire order. */
 
int zx_WALK_SO_ac_DigSig(struct zx_ctx* c, struct zx_ac_DigSig_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
{
  int ret = callback(&x->gg.g, ctx);
  if (ret)
    return ret;
  
  /* *** deal with xmlns specifications in exc c14n way */


  
  ret = zx_walk_so_unknown_attributes(c, &x->gg, ctx, callback); 
  if (ret)
    return ret;

  {
      struct zx_ac_Extension_s* e;
      for (e = x->Extension; e; e = (struct zx_ac_Extension_s*)e->gg.g.n) {
	  ret = zx_WALK_SO_ac_Extension(c, e, ctx, callback);
	  if (ret)
	      return ret;
      }
  }

  
  return zx_walk_so_unknown_elems_and_content(c, &x->gg, ctx, callback);
}

/* FUNC(zx_WALK_WO_ac_DigSig) */

int zx_WALK_WO_ac_DigSig(struct zx_ctx* c, struct zx_ac_DigSig_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
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

#define EL_NAME   ac_Extension
#define EL_STRUCT zx_ac_Extension_s
#define EL_NS     ac
#define EL_TAG    Extension

/* FUNC(zx_FREE_ac_Extension) */

/* Depth first traversal of data structure to free it and its subelements. Simple
 * strings are handled as a special case according to the free_strs flag. This
 * is useful if the strings point to underlying data from the wire that was
 * allocated differently. */

/* Called by: */
void zx_FREE_ac_Extension(struct zx_ctx* c, struct zx_ac_Extension_s* x, int free_strs)
{
  /* *** deal with xmlns specifications in exc c14n way */




  zx_free_elem_common(c, &x->gg, free_strs); 
}

/* FUNC(zx_NEW_ac_Extension) */

/* Trivial allocator/constructor for the datatype. */

/* Called by: */
struct zx_ac_Extension_s* zx_NEW_ac_Extension(struct zx_ctx* c)
{
  struct zx_ac_Extension_s* x = ZX_ZALLOC(c, struct zx_ac_Extension_s);
  x->gg.g.tok = zx_ac_Extension_ELEM;
  return x;
}

#ifdef ZX_ENA_AUX

/* FUNC(zx_DUP_STRS_ac_Extension) */

/* Depth first traversal of data structure to copy its simple strings
 * to memory allocated from the memory allocator. The decoder will
 * use the underlying wireprotocol PDU buffer for strings, i.e.
 * strings are not copied - they point to the real data. If the
 * datastructure needs to outlast the protocol data or needs a different
 * memory allocation strategy, you need to call this function.  */

/* Called by: */
void zx_DUP_STRS_ac_Extension(struct zx_ctx* c, struct zx_ac_Extension_s* x)
{
  zx_dup_strs_common(c, &x->gg);
  /* *** deal with xmlns specifications in exc c14n way */



}

/* FUNC(zx_DEEP_CLONE_ac_Extension) */

/* Depth first traversal of data structure to clone it and its sublements.
 * The simple strings are handled as a special case according to dup_strs flag. */

/* Called by: */
struct zx_ac_Extension_s* zx_DEEP_CLONE_ac_Extension(struct zx_ctx* c, struct zx_ac_Extension_s* x, int dup_strs)
{
  x = (struct zx_ac_Extension_s*)zx_clone_elem_common(c, &x->gg, sizeof(struct zx_ac_Extension_s), dup_strs);
  /* *** deal with xmlns specifications in exc c14n way */



  return x;
}

/* FUNC(zx_WALK_SO_ac_Extension) */

/* Depth first traversal of the tree in either schema order or the wire order. */
 
int zx_WALK_SO_ac_Extension(struct zx_ctx* c, struct zx_ac_Extension_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
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

/* FUNC(zx_WALK_WO_ac_Extension) */

int zx_WALK_WO_ac_Extension(struct zx_ctx* c, struct zx_ac_Extension_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
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

#define EL_NAME   ac_Generation
#define EL_STRUCT zx_ac_Generation_s
#define EL_NS     ac
#define EL_TAG    Generation

/* FUNC(zx_FREE_ac_Generation) */

/* Depth first traversal of data structure to free it and its subelements. Simple
 * strings are handled as a special case according to the free_strs flag. This
 * is useful if the strings point to underlying data from the wire that was
 * allocated differently. */

/* Called by: */
void zx_FREE_ac_Generation(struct zx_ctx* c, struct zx_ac_Generation_s* x, int free_strs)
{
  /* *** deal with xmlns specifications in exc c14n way */

  zx_free_attr(c, x->mechanism, free_strs);



  zx_free_elem_common(c, &x->gg, free_strs); 
}

/* FUNC(zx_NEW_ac_Generation) */

/* Trivial allocator/constructor for the datatype. */

/* Called by: */
struct zx_ac_Generation_s* zx_NEW_ac_Generation(struct zx_ctx* c)
{
  struct zx_ac_Generation_s* x = ZX_ZALLOC(c, struct zx_ac_Generation_s);
  x->gg.g.tok = zx_ac_Generation_ELEM;
  return x;
}

#ifdef ZX_ENA_AUX

/* FUNC(zx_DUP_STRS_ac_Generation) */

/* Depth first traversal of data structure to copy its simple strings
 * to memory allocated from the memory allocator. The decoder will
 * use the underlying wireprotocol PDU buffer for strings, i.e.
 * strings are not copied - they point to the real data. If the
 * datastructure needs to outlast the protocol data or needs a different
 * memory allocation strategy, you need to call this function.  */

/* Called by: */
void zx_DUP_STRS_ac_Generation(struct zx_ctx* c, struct zx_ac_Generation_s* x)
{
  zx_dup_strs_common(c, &x->gg);
  /* *** deal with xmlns specifications in exc c14n way */

  zx_dup_attr(c, x->mechanism);


}

/* FUNC(zx_DEEP_CLONE_ac_Generation) */

/* Depth first traversal of data structure to clone it and its sublements.
 * The simple strings are handled as a special case according to dup_strs flag. */

/* Called by: */
struct zx_ac_Generation_s* zx_DEEP_CLONE_ac_Generation(struct zx_ctx* c, struct zx_ac_Generation_s* x, int dup_strs)
{
  x = (struct zx_ac_Generation_s*)zx_clone_elem_common(c, &x->gg, sizeof(struct zx_ac_Generation_s), dup_strs);
  /* *** deal with xmlns specifications in exc c14n way */

  x->mechanism = zx_clone_attr(c, x->mechanism);


  return x;
}

/* FUNC(zx_WALK_SO_ac_Generation) */

/* Depth first traversal of the tree in either schema order or the wire order. */
 
int zx_WALK_SO_ac_Generation(struct zx_ctx* c, struct zx_ac_Generation_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
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

/* FUNC(zx_WALK_WO_ac_Generation) */

int zx_WALK_WO_ac_Generation(struct zx_ctx* c, struct zx_ac_Generation_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
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

#define EL_NAME   ac_GoverningAgreementRef
#define EL_STRUCT zx_ac_GoverningAgreementRef_s
#define EL_NS     ac
#define EL_TAG    GoverningAgreementRef

/* FUNC(zx_FREE_ac_GoverningAgreementRef) */

/* Depth first traversal of data structure to free it and its subelements. Simple
 * strings are handled as a special case according to the free_strs flag. This
 * is useful if the strings point to underlying data from the wire that was
 * allocated differently. */

/* Called by: */
void zx_FREE_ac_GoverningAgreementRef(struct zx_ctx* c, struct zx_ac_GoverningAgreementRef_s* x, int free_strs)
{
  /* *** deal with xmlns specifications in exc c14n way */

  zx_free_attr(c, x->governingAgreementRef, free_strs);



  zx_free_elem_common(c, &x->gg, free_strs); 
}

/* FUNC(zx_NEW_ac_GoverningAgreementRef) */

/* Trivial allocator/constructor for the datatype. */

/* Called by: */
struct zx_ac_GoverningAgreementRef_s* zx_NEW_ac_GoverningAgreementRef(struct zx_ctx* c)
{
  struct zx_ac_GoverningAgreementRef_s* x = ZX_ZALLOC(c, struct zx_ac_GoverningAgreementRef_s);
  x->gg.g.tok = zx_ac_GoverningAgreementRef_ELEM;
  return x;
}

#ifdef ZX_ENA_AUX

/* FUNC(zx_DUP_STRS_ac_GoverningAgreementRef) */

/* Depth first traversal of data structure to copy its simple strings
 * to memory allocated from the memory allocator. The decoder will
 * use the underlying wireprotocol PDU buffer for strings, i.e.
 * strings are not copied - they point to the real data. If the
 * datastructure needs to outlast the protocol data or needs a different
 * memory allocation strategy, you need to call this function.  */

/* Called by: */
void zx_DUP_STRS_ac_GoverningAgreementRef(struct zx_ctx* c, struct zx_ac_GoverningAgreementRef_s* x)
{
  zx_dup_strs_common(c, &x->gg);
  /* *** deal with xmlns specifications in exc c14n way */

  zx_dup_attr(c, x->governingAgreementRef);


}

/* FUNC(zx_DEEP_CLONE_ac_GoverningAgreementRef) */

/* Depth first traversal of data structure to clone it and its sublements.
 * The simple strings are handled as a special case according to dup_strs flag. */

/* Called by: */
struct zx_ac_GoverningAgreementRef_s* zx_DEEP_CLONE_ac_GoverningAgreementRef(struct zx_ctx* c, struct zx_ac_GoverningAgreementRef_s* x, int dup_strs)
{
  x = (struct zx_ac_GoverningAgreementRef_s*)zx_clone_elem_common(c, &x->gg, sizeof(struct zx_ac_GoverningAgreementRef_s), dup_strs);
  /* *** deal with xmlns specifications in exc c14n way */

  x->governingAgreementRef = zx_clone_attr(c, x->governingAgreementRef);


  return x;
}

/* FUNC(zx_WALK_SO_ac_GoverningAgreementRef) */

/* Depth first traversal of the tree in either schema order or the wire order. */
 
int zx_WALK_SO_ac_GoverningAgreementRef(struct zx_ctx* c, struct zx_ac_GoverningAgreementRef_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
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

/* FUNC(zx_WALK_WO_ac_GoverningAgreementRef) */

int zx_WALK_WO_ac_GoverningAgreementRef(struct zx_ctx* c, struct zx_ac_GoverningAgreementRef_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
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

#define EL_NAME   ac_GoverningAgreements
#define EL_STRUCT zx_ac_GoverningAgreements_s
#define EL_NS     ac
#define EL_TAG    GoverningAgreements

/* FUNC(zx_FREE_ac_GoverningAgreements) */

/* Depth first traversal of data structure to free it and its subelements. Simple
 * strings are handled as a special case according to the free_strs flag. This
 * is useful if the strings point to underlying data from the wire that was
 * allocated differently. */

/* Called by: */
void zx_FREE_ac_GoverningAgreements(struct zx_ctx* c, struct zx_ac_GoverningAgreements_s* x, int free_strs)
{
  /* *** deal with xmlns specifications in exc c14n way */


  {
      struct zx_ac_GoverningAgreementRef_s* e;
      struct zx_ac_GoverningAgreementRef_s* en;
      for (e = x->GoverningAgreementRef; e; e = en) {
	  en = (struct zx_ac_GoverningAgreementRef_s*)e->gg.g.n;
	  zx_FREE_ac_GoverningAgreementRef(c, e, free_strs);
      }
  }


  zx_free_elem_common(c, &x->gg, free_strs); 
}

/* FUNC(zx_NEW_ac_GoverningAgreements) */

/* Trivial allocator/constructor for the datatype. */

/* Called by: */
struct zx_ac_GoverningAgreements_s* zx_NEW_ac_GoverningAgreements(struct zx_ctx* c)
{
  struct zx_ac_GoverningAgreements_s* x = ZX_ZALLOC(c, struct zx_ac_GoverningAgreements_s);
  x->gg.g.tok = zx_ac_GoverningAgreements_ELEM;
  return x;
}

#ifdef ZX_ENA_AUX

/* FUNC(zx_DUP_STRS_ac_GoverningAgreements) */

/* Depth first traversal of data structure to copy its simple strings
 * to memory allocated from the memory allocator. The decoder will
 * use the underlying wireprotocol PDU buffer for strings, i.e.
 * strings are not copied - they point to the real data. If the
 * datastructure needs to outlast the protocol data or needs a different
 * memory allocation strategy, you need to call this function.  */

/* Called by: */
void zx_DUP_STRS_ac_GoverningAgreements(struct zx_ctx* c, struct zx_ac_GoverningAgreements_s* x)
{
  zx_dup_strs_common(c, &x->gg);
  /* *** deal with xmlns specifications in exc c14n way */


  {
      struct zx_ac_GoverningAgreementRef_s* e;
      for (e = x->GoverningAgreementRef; e; e = (struct zx_ac_GoverningAgreementRef_s*)e->gg.g.n)
	  zx_DUP_STRS_ac_GoverningAgreementRef(c, e);
  }

}

/* FUNC(zx_DEEP_CLONE_ac_GoverningAgreements) */

/* Depth first traversal of data structure to clone it and its sublements.
 * The simple strings are handled as a special case according to dup_strs flag. */

/* Called by: */
struct zx_ac_GoverningAgreements_s* zx_DEEP_CLONE_ac_GoverningAgreements(struct zx_ctx* c, struct zx_ac_GoverningAgreements_s* x, int dup_strs)
{
  x = (struct zx_ac_GoverningAgreements_s*)zx_clone_elem_common(c, &x->gg, sizeof(struct zx_ac_GoverningAgreements_s), dup_strs);
  /* *** deal with xmlns specifications in exc c14n way */


  {
      struct zx_ac_GoverningAgreementRef_s* e;
      struct zx_ac_GoverningAgreementRef_s* en;
      struct zx_ac_GoverningAgreementRef_s* enn;
      for (enn = 0, e = x->GoverningAgreementRef; e; e = (struct zx_ac_GoverningAgreementRef_s*)e->gg.g.n) {
	  en = zx_DEEP_CLONE_ac_GoverningAgreementRef(c, e, dup_strs);
	  if (!enn)
	      x->GoverningAgreementRef = en;
	  else
	      enn->gg.g.n = &en->gg.g;
	  enn = en;
      }
  }

  return x;
}

/* FUNC(zx_WALK_SO_ac_GoverningAgreements) */

/* Depth first traversal of the tree in either schema order or the wire order. */
 
int zx_WALK_SO_ac_GoverningAgreements(struct zx_ctx* c, struct zx_ac_GoverningAgreements_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
{
  int ret = callback(&x->gg.g, ctx);
  if (ret)
    return ret;
  
  /* *** deal with xmlns specifications in exc c14n way */


  
  ret = zx_walk_so_unknown_attributes(c, &x->gg, ctx, callback); 
  if (ret)
    return ret;

  {
      struct zx_ac_GoverningAgreementRef_s* e;
      for (e = x->GoverningAgreementRef; e; e = (struct zx_ac_GoverningAgreementRef_s*)e->gg.g.n) {
	  ret = zx_WALK_SO_ac_GoverningAgreementRef(c, e, ctx, callback);
	  if (ret)
	      return ret;
      }
  }

  
  return zx_walk_so_unknown_elems_and_content(c, &x->gg, ctx, callback);
}

/* FUNC(zx_WALK_WO_ac_GoverningAgreements) */

int zx_WALK_WO_ac_GoverningAgreements(struct zx_ctx* c, struct zx_ac_GoverningAgreements_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
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

#define EL_NAME   ac_HTTP
#define EL_STRUCT zx_ac_HTTP_s
#define EL_NS     ac
#define EL_TAG    HTTP

/* FUNC(zx_FREE_ac_HTTP) */

/* Depth first traversal of data structure to free it and its subelements. Simple
 * strings are handled as a special case according to the free_strs flag. This
 * is useful if the strings point to underlying data from the wire that was
 * allocated differently. */

/* Called by: */
void zx_FREE_ac_HTTP(struct zx_ctx* c, struct zx_ac_HTTP_s* x, int free_strs)
{
  /* *** deal with xmlns specifications in exc c14n way */


  {
      struct zx_ac_Extension_s* e;
      struct zx_ac_Extension_s* en;
      for (e = x->Extension; e; e = en) {
	  en = (struct zx_ac_Extension_s*)e->gg.g.n;
	  zx_FREE_ac_Extension(c, e, free_strs);
      }
  }


  zx_free_elem_common(c, &x->gg, free_strs); 
}

/* FUNC(zx_NEW_ac_HTTP) */

/* Trivial allocator/constructor for the datatype. */

/* Called by: */
struct zx_ac_HTTP_s* zx_NEW_ac_HTTP(struct zx_ctx* c)
{
  struct zx_ac_HTTP_s* x = ZX_ZALLOC(c, struct zx_ac_HTTP_s);
  x->gg.g.tok = zx_ac_HTTP_ELEM;
  return x;
}

#ifdef ZX_ENA_AUX

/* FUNC(zx_DUP_STRS_ac_HTTP) */

/* Depth first traversal of data structure to copy its simple strings
 * to memory allocated from the memory allocator. The decoder will
 * use the underlying wireprotocol PDU buffer for strings, i.e.
 * strings are not copied - they point to the real data. If the
 * datastructure needs to outlast the protocol data or needs a different
 * memory allocation strategy, you need to call this function.  */

/* Called by: */
void zx_DUP_STRS_ac_HTTP(struct zx_ctx* c, struct zx_ac_HTTP_s* x)
{
  zx_dup_strs_common(c, &x->gg);
  /* *** deal with xmlns specifications in exc c14n way */


  {
      struct zx_ac_Extension_s* e;
      for (e = x->Extension; e; e = (struct zx_ac_Extension_s*)e->gg.g.n)
	  zx_DUP_STRS_ac_Extension(c, e);
  }

}

/* FUNC(zx_DEEP_CLONE_ac_HTTP) */

/* Depth first traversal of data structure to clone it and its sublements.
 * The simple strings are handled as a special case according to dup_strs flag. */

/* Called by: */
struct zx_ac_HTTP_s* zx_DEEP_CLONE_ac_HTTP(struct zx_ctx* c, struct zx_ac_HTTP_s* x, int dup_strs)
{
  x = (struct zx_ac_HTTP_s*)zx_clone_elem_common(c, &x->gg, sizeof(struct zx_ac_HTTP_s), dup_strs);
  /* *** deal with xmlns specifications in exc c14n way */


  {
      struct zx_ac_Extension_s* e;
      struct zx_ac_Extension_s* en;
      struct zx_ac_Extension_s* enn;
      for (enn = 0, e = x->Extension; e; e = (struct zx_ac_Extension_s*)e->gg.g.n) {
	  en = zx_DEEP_CLONE_ac_Extension(c, e, dup_strs);
	  if (!enn)
	      x->Extension = en;
	  else
	      enn->gg.g.n = &en->gg.g;
	  enn = en;
      }
  }

  return x;
}

/* FUNC(zx_WALK_SO_ac_HTTP) */

/* Depth first traversal of the tree in either schema order or the wire order. */
 
int zx_WALK_SO_ac_HTTP(struct zx_ctx* c, struct zx_ac_HTTP_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
{
  int ret = callback(&x->gg.g, ctx);
  if (ret)
    return ret;
  
  /* *** deal with xmlns specifications in exc c14n way */


  
  ret = zx_walk_so_unknown_attributes(c, &x->gg, ctx, callback); 
  if (ret)
    return ret;

  {
      struct zx_ac_Extension_s* e;
      for (e = x->Extension; e; e = (struct zx_ac_Extension_s*)e->gg.g.n) {
	  ret = zx_WALK_SO_ac_Extension(c, e, ctx, callback);
	  if (ret)
	      return ret;
      }
  }

  
  return zx_walk_so_unknown_elems_and_content(c, &x->gg, ctx, callback);
}

/* FUNC(zx_WALK_WO_ac_HTTP) */

int zx_WALK_WO_ac_HTTP(struct zx_ctx* c, struct zx_ac_HTTP_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
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

#define EL_NAME   ac_IPAddress
#define EL_STRUCT zx_ac_IPAddress_s
#define EL_NS     ac
#define EL_TAG    IPAddress

/* FUNC(zx_FREE_ac_IPAddress) */

/* Depth first traversal of data structure to free it and its subelements. Simple
 * strings are handled as a special case according to the free_strs flag. This
 * is useful if the strings point to underlying data from the wire that was
 * allocated differently. */

/* Called by: */
void zx_FREE_ac_IPAddress(struct zx_ctx* c, struct zx_ac_IPAddress_s* x, int free_strs)
{
  /* *** deal with xmlns specifications in exc c14n way */


  {
      struct zx_ac_Extension_s* e;
      struct zx_ac_Extension_s* en;
      for (e = x->Extension; e; e = en) {
	  en = (struct zx_ac_Extension_s*)e->gg.g.n;
	  zx_FREE_ac_Extension(c, e, free_strs);
      }
  }


  zx_free_elem_common(c, &x->gg, free_strs); 
}

/* FUNC(zx_NEW_ac_IPAddress) */

/* Trivial allocator/constructor for the datatype. */

/* Called by: */
struct zx_ac_IPAddress_s* zx_NEW_ac_IPAddress(struct zx_ctx* c)
{
  struct zx_ac_IPAddress_s* x = ZX_ZALLOC(c, struct zx_ac_IPAddress_s);
  x->gg.g.tok = zx_ac_IPAddress_ELEM;
  return x;
}

#ifdef ZX_ENA_AUX

/* FUNC(zx_DUP_STRS_ac_IPAddress) */

/* Depth first traversal of data structure to copy its simple strings
 * to memory allocated from the memory allocator. The decoder will
 * use the underlying wireprotocol PDU buffer for strings, i.e.
 * strings are not copied - they point to the real data. If the
 * datastructure needs to outlast the protocol data or needs a different
 * memory allocation strategy, you need to call this function.  */

/* Called by: */
void zx_DUP_STRS_ac_IPAddress(struct zx_ctx* c, struct zx_ac_IPAddress_s* x)
{
  zx_dup_strs_common(c, &x->gg);
  /* *** deal with xmlns specifications in exc c14n way */


  {
      struct zx_ac_Extension_s* e;
      for (e = x->Extension; e; e = (struct zx_ac_Extension_s*)e->gg.g.n)
	  zx_DUP_STRS_ac_Extension(c, e);
  }

}

/* FUNC(zx_DEEP_CLONE_ac_IPAddress) */

/* Depth first traversal of data structure to clone it and its sublements.
 * The simple strings are handled as a special case according to dup_strs flag. */

/* Called by: */
struct zx_ac_IPAddress_s* zx_DEEP_CLONE_ac_IPAddress(struct zx_ctx* c, struct zx_ac_IPAddress_s* x, int dup_strs)
{
  x = (struct zx_ac_IPAddress_s*)zx_clone_elem_common(c, &x->gg, sizeof(struct zx_ac_IPAddress_s), dup_strs);
  /* *** deal with xmlns specifications in exc c14n way */


  {
      struct zx_ac_Extension_s* e;
      struct zx_ac_Extension_s* en;
      struct zx_ac_Extension_s* enn;
      for (enn = 0, e = x->Extension; e; e = (struct zx_ac_Extension_s*)e->gg.g.n) {
	  en = zx_DEEP_CLONE_ac_Extension(c, e, dup_strs);
	  if (!enn)
	      x->Extension = en;
	  else
	      enn->gg.g.n = &en->gg.g;
	  enn = en;
      }
  }

  return x;
}

/* FUNC(zx_WALK_SO_ac_IPAddress) */

/* Depth first traversal of the tree in either schema order or the wire order. */
 
int zx_WALK_SO_ac_IPAddress(struct zx_ctx* c, struct zx_ac_IPAddress_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
{
  int ret = callback(&x->gg.g, ctx);
  if (ret)
    return ret;
  
  /* *** deal with xmlns specifications in exc c14n way */


  
  ret = zx_walk_so_unknown_attributes(c, &x->gg, ctx, callback); 
  if (ret)
    return ret;

  {
      struct zx_ac_Extension_s* e;
      for (e = x->Extension; e; e = (struct zx_ac_Extension_s*)e->gg.g.n) {
	  ret = zx_WALK_SO_ac_Extension(c, e, ctx, callback);
	  if (ret)
	      return ret;
      }
  }

  
  return zx_walk_so_unknown_elems_and_content(c, &x->gg, ctx, callback);
}

/* FUNC(zx_WALK_WO_ac_IPAddress) */

int zx_WALK_WO_ac_IPAddress(struct zx_ctx* c, struct zx_ac_IPAddress_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
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

#define EL_NAME   ac_IPSec
#define EL_STRUCT zx_ac_IPSec_s
#define EL_NS     ac
#define EL_TAG    IPSec

/* FUNC(zx_FREE_ac_IPSec) */

/* Depth first traversal of data structure to free it and its subelements. Simple
 * strings are handled as a special case according to the free_strs flag. This
 * is useful if the strings point to underlying data from the wire that was
 * allocated differently. */

/* Called by: */
void zx_FREE_ac_IPSec(struct zx_ctx* c, struct zx_ac_IPSec_s* x, int free_strs)
{
  /* *** deal with xmlns specifications in exc c14n way */


  {
      struct zx_ac_Extension_s* e;
      struct zx_ac_Extension_s* en;
      for (e = x->Extension; e; e = en) {
	  en = (struct zx_ac_Extension_s*)e->gg.g.n;
	  zx_FREE_ac_Extension(c, e, free_strs);
      }
  }


  zx_free_elem_common(c, &x->gg, free_strs); 
}

/* FUNC(zx_NEW_ac_IPSec) */

/* Trivial allocator/constructor for the datatype. */

/* Called by: */
struct zx_ac_IPSec_s* zx_NEW_ac_IPSec(struct zx_ctx* c)
{
  struct zx_ac_IPSec_s* x = ZX_ZALLOC(c, struct zx_ac_IPSec_s);
  x->gg.g.tok = zx_ac_IPSec_ELEM;
  return x;
}

#ifdef ZX_ENA_AUX

/* FUNC(zx_DUP_STRS_ac_IPSec) */

/* Depth first traversal of data structure to copy its simple strings
 * to memory allocated from the memory allocator. The decoder will
 * use the underlying wireprotocol PDU buffer for strings, i.e.
 * strings are not copied - they point to the real data. If the
 * datastructure needs to outlast the protocol data or needs a different
 * memory allocation strategy, you need to call this function.  */

/* Called by: */
void zx_DUP_STRS_ac_IPSec(struct zx_ctx* c, struct zx_ac_IPSec_s* x)
{
  zx_dup_strs_common(c, &x->gg);
  /* *** deal with xmlns specifications in exc c14n way */


  {
      struct zx_ac_Extension_s* e;
      for (e = x->Extension; e; e = (struct zx_ac_Extension_s*)e->gg.g.n)
	  zx_DUP_STRS_ac_Extension(c, e);
  }

}

/* FUNC(zx_DEEP_CLONE_ac_IPSec) */

/* Depth first traversal of data structure to clone it and its sublements.
 * The simple strings are handled as a special case according to dup_strs flag. */

/* Called by: */
struct zx_ac_IPSec_s* zx_DEEP_CLONE_ac_IPSec(struct zx_ctx* c, struct zx_ac_IPSec_s* x, int dup_strs)
{
  x = (struct zx_ac_IPSec_s*)zx_clone_elem_common(c, &x->gg, sizeof(struct zx_ac_IPSec_s), dup_strs);
  /* *** deal with xmlns specifications in exc c14n way */


  {
      struct zx_ac_Extension_s* e;
      struct zx_ac_Extension_s* en;
      struct zx_ac_Extension_s* enn;
      for (enn = 0, e = x->Extension; e; e = (struct zx_ac_Extension_s*)e->gg.g.n) {
	  en = zx_DEEP_CLONE_ac_Extension(c, e, dup_strs);
	  if (!enn)
	      x->Extension = en;
	  else
	      enn->gg.g.n = &en->gg.g;
	  enn = en;
      }
  }

  return x;
}

/* FUNC(zx_WALK_SO_ac_IPSec) */

/* Depth first traversal of the tree in either schema order or the wire order. */
 
int zx_WALK_SO_ac_IPSec(struct zx_ctx* c, struct zx_ac_IPSec_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
{
  int ret = callback(&x->gg.g, ctx);
  if (ret)
    return ret;
  
  /* *** deal with xmlns specifications in exc c14n way */


  
  ret = zx_walk_so_unknown_attributes(c, &x->gg, ctx, callback); 
  if (ret)
    return ret;

  {
      struct zx_ac_Extension_s* e;
      for (e = x->Extension; e; e = (struct zx_ac_Extension_s*)e->gg.g.n) {
	  ret = zx_WALK_SO_ac_Extension(c, e, ctx, callback);
	  if (ret)
	      return ret;
      }
  }

  
  return zx_walk_so_unknown_elems_and_content(c, &x->gg, ctx, callback);
}

/* FUNC(zx_WALK_WO_ac_IPSec) */

int zx_WALK_WO_ac_IPSec(struct zx_ctx* c, struct zx_ac_IPSec_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
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

#define EL_NAME   ac_Identification
#define EL_STRUCT zx_ac_Identification_s
#define EL_NS     ac
#define EL_TAG    Identification

/* FUNC(zx_FREE_ac_Identification) */

/* Depth first traversal of data structure to free it and its subelements. Simple
 * strings are handled as a special case according to the free_strs flag. This
 * is useful if the strings point to underlying data from the wire that was
 * allocated differently. */

/* Called by: */
void zx_FREE_ac_Identification(struct zx_ctx* c, struct zx_ac_Identification_s* x, int free_strs)
{
  /* *** deal with xmlns specifications in exc c14n way */

  zx_free_attr(c, x->nym, free_strs);

  {
      struct zx_ac_PhysicalVerification_s* e;
      struct zx_ac_PhysicalVerification_s* en;
      for (e = x->PhysicalVerification; e; e = en) {
	  en = (struct zx_ac_PhysicalVerification_s*)e->gg.g.n;
	  zx_FREE_ac_PhysicalVerification(c, e, free_strs);
      }
  }
  {
      struct zx_ac_WrittenConsent_s* e;
      struct zx_ac_WrittenConsent_s* en;
      for (e = x->WrittenConsent; e; e = en) {
	  en = (struct zx_ac_WrittenConsent_s*)e->gg.g.n;
	  zx_FREE_ac_WrittenConsent(c, e, free_strs);
      }
  }
  {
      struct zx_ac_Extension_s* e;
      struct zx_ac_Extension_s* en;
      for (e = x->Extension; e; e = en) {
	  en = (struct zx_ac_Extension_s*)e->gg.g.n;
	  zx_FREE_ac_Extension(c, e, free_strs);
      }
  }


  zx_free_elem_common(c, &x->gg, free_strs); 
}

/* FUNC(zx_NEW_ac_Identification) */

/* Trivial allocator/constructor for the datatype. */

/* Called by: */
struct zx_ac_Identification_s* zx_NEW_ac_Identification(struct zx_ctx* c)
{
  struct zx_ac_Identification_s* x = ZX_ZALLOC(c, struct zx_ac_Identification_s);
  x->gg.g.tok = zx_ac_Identification_ELEM;
  return x;
}

#ifdef ZX_ENA_AUX

/* FUNC(zx_DUP_STRS_ac_Identification) */

/* Depth first traversal of data structure to copy its simple strings
 * to memory allocated from the memory allocator. The decoder will
 * use the underlying wireprotocol PDU buffer for strings, i.e.
 * strings are not copied - they point to the real data. If the
 * datastructure needs to outlast the protocol data or needs a different
 * memory allocation strategy, you need to call this function.  */

/* Called by: */
void zx_DUP_STRS_ac_Identification(struct zx_ctx* c, struct zx_ac_Identification_s* x)
{
  zx_dup_strs_common(c, &x->gg);
  /* *** deal with xmlns specifications in exc c14n way */

  zx_dup_attr(c, x->nym);

  {
      struct zx_ac_PhysicalVerification_s* e;
      for (e = x->PhysicalVerification; e; e = (struct zx_ac_PhysicalVerification_s*)e->gg.g.n)
	  zx_DUP_STRS_ac_PhysicalVerification(c, e);
  }
  {
      struct zx_ac_WrittenConsent_s* e;
      for (e = x->WrittenConsent; e; e = (struct zx_ac_WrittenConsent_s*)e->gg.g.n)
	  zx_DUP_STRS_ac_WrittenConsent(c, e);
  }
  {
      struct zx_ac_Extension_s* e;
      for (e = x->Extension; e; e = (struct zx_ac_Extension_s*)e->gg.g.n)
	  zx_DUP_STRS_ac_Extension(c, e);
  }

}

/* FUNC(zx_DEEP_CLONE_ac_Identification) */

/* Depth first traversal of data structure to clone it and its sublements.
 * The simple strings are handled as a special case according to dup_strs flag. */

/* Called by: */
struct zx_ac_Identification_s* zx_DEEP_CLONE_ac_Identification(struct zx_ctx* c, struct zx_ac_Identification_s* x, int dup_strs)
{
  x = (struct zx_ac_Identification_s*)zx_clone_elem_common(c, &x->gg, sizeof(struct zx_ac_Identification_s), dup_strs);
  /* *** deal with xmlns specifications in exc c14n way */

  x->nym = zx_clone_attr(c, x->nym);

  {
      struct zx_ac_PhysicalVerification_s* e;
      struct zx_ac_PhysicalVerification_s* en;
      struct zx_ac_PhysicalVerification_s* enn;
      for (enn = 0, e = x->PhysicalVerification; e; e = (struct zx_ac_PhysicalVerification_s*)e->gg.g.n) {
	  en = zx_DEEP_CLONE_ac_PhysicalVerification(c, e, dup_strs);
	  if (!enn)
	      x->PhysicalVerification = en;
	  else
	      enn->gg.g.n = &en->gg.g;
	  enn = en;
      }
  }
  {
      struct zx_ac_WrittenConsent_s* e;
      struct zx_ac_WrittenConsent_s* en;
      struct zx_ac_WrittenConsent_s* enn;
      for (enn = 0, e = x->WrittenConsent; e; e = (struct zx_ac_WrittenConsent_s*)e->gg.g.n) {
	  en = zx_DEEP_CLONE_ac_WrittenConsent(c, e, dup_strs);
	  if (!enn)
	      x->WrittenConsent = en;
	  else
	      enn->gg.g.n = &en->gg.g;
	  enn = en;
      }
  }
  {
      struct zx_ac_Extension_s* e;
      struct zx_ac_Extension_s* en;
      struct zx_ac_Extension_s* enn;
      for (enn = 0, e = x->Extension; e; e = (struct zx_ac_Extension_s*)e->gg.g.n) {
	  en = zx_DEEP_CLONE_ac_Extension(c, e, dup_strs);
	  if (!enn)
	      x->Extension = en;
	  else
	      enn->gg.g.n = &en->gg.g;
	  enn = en;
      }
  }

  return x;
}

/* FUNC(zx_WALK_SO_ac_Identification) */

/* Depth first traversal of the tree in either schema order or the wire order. */
 
int zx_WALK_SO_ac_Identification(struct zx_ctx* c, struct zx_ac_Identification_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
{
  int ret = callback(&x->gg.g, ctx);
  if (ret)
    return ret;
  
  /* *** deal with xmlns specifications in exc c14n way */


  
  ret = zx_walk_so_unknown_attributes(c, &x->gg, ctx, callback); 
  if (ret)
    return ret;

  {
      struct zx_ac_PhysicalVerification_s* e;
      for (e = x->PhysicalVerification; e; e = (struct zx_ac_PhysicalVerification_s*)e->gg.g.n) {
	  ret = zx_WALK_SO_ac_PhysicalVerification(c, e, ctx, callback);
	  if (ret)
	      return ret;
      }
  }
  {
      struct zx_ac_WrittenConsent_s* e;
      for (e = x->WrittenConsent; e; e = (struct zx_ac_WrittenConsent_s*)e->gg.g.n) {
	  ret = zx_WALK_SO_ac_WrittenConsent(c, e, ctx, callback);
	  if (ret)
	      return ret;
      }
  }
  {
      struct zx_ac_Extension_s* e;
      for (e = x->Extension; e; e = (struct zx_ac_Extension_s*)e->gg.g.n) {
	  ret = zx_WALK_SO_ac_Extension(c, e, ctx, callback);
	  if (ret)
	      return ret;
      }
  }

  
  return zx_walk_so_unknown_elems_and_content(c, &x->gg, ctx, callback);
}

/* FUNC(zx_WALK_WO_ac_Identification) */

int zx_WALK_WO_ac_Identification(struct zx_ctx* c, struct zx_ac_Identification_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
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

#define EL_NAME   ac_KeyActivation
#define EL_STRUCT zx_ac_KeyActivation_s
#define EL_NS     ac
#define EL_TAG    KeyActivation

/* FUNC(zx_FREE_ac_KeyActivation) */

/* Depth first traversal of data structure to free it and its subelements. Simple
 * strings are handled as a special case according to the free_strs flag. This
 * is useful if the strings point to underlying data from the wire that was
 * allocated differently. */

/* Called by: */
void zx_FREE_ac_KeyActivation(struct zx_ctx* c, struct zx_ac_KeyActivation_s* x, int free_strs)
{
  /* *** deal with xmlns specifications in exc c14n way */


  {
      struct zx_ac_ActivationPin_s* e;
      struct zx_ac_ActivationPin_s* en;
      for (e = x->ActivationPin; e; e = en) {
	  en = (struct zx_ac_ActivationPin_s*)e->gg.g.n;
	  zx_FREE_ac_ActivationPin(c, e, free_strs);
      }
  }
  {
      struct zx_ac_Extension_s* e;
      struct zx_ac_Extension_s* en;
      for (e = x->Extension; e; e = en) {
	  en = (struct zx_ac_Extension_s*)e->gg.g.n;
	  zx_FREE_ac_Extension(c, e, free_strs);
      }
  }


  zx_free_elem_common(c, &x->gg, free_strs); 
}

/* FUNC(zx_NEW_ac_KeyActivation) */

/* Trivial allocator/constructor for the datatype. */

/* Called by: */
struct zx_ac_KeyActivation_s* zx_NEW_ac_KeyActivation(struct zx_ctx* c)
{
  struct zx_ac_KeyActivation_s* x = ZX_ZALLOC(c, struct zx_ac_KeyActivation_s);
  x->gg.g.tok = zx_ac_KeyActivation_ELEM;
  return x;
}

#ifdef ZX_ENA_AUX

/* FUNC(zx_DUP_STRS_ac_KeyActivation) */

/* Depth first traversal of data structure to copy its simple strings
 * to memory allocated from the memory allocator. The decoder will
 * use the underlying wireprotocol PDU buffer for strings, i.e.
 * strings are not copied - they point to the real data. If the
 * datastructure needs to outlast the protocol data or needs a different
 * memory allocation strategy, you need to call this function.  */

/* Called by: */
void zx_DUP_STRS_ac_KeyActivation(struct zx_ctx* c, struct zx_ac_KeyActivation_s* x)
{
  zx_dup_strs_common(c, &x->gg);
  /* *** deal with xmlns specifications in exc c14n way */


  {
      struct zx_ac_ActivationPin_s* e;
      for (e = x->ActivationPin; e; e = (struct zx_ac_ActivationPin_s*)e->gg.g.n)
	  zx_DUP_STRS_ac_ActivationPin(c, e);
  }
  {
      struct zx_ac_Extension_s* e;
      for (e = x->Extension; e; e = (struct zx_ac_Extension_s*)e->gg.g.n)
	  zx_DUP_STRS_ac_Extension(c, e);
  }

}

/* FUNC(zx_DEEP_CLONE_ac_KeyActivation) */

/* Depth first traversal of data structure to clone it and its sublements.
 * The simple strings are handled as a special case according to dup_strs flag. */

/* Called by: */
struct zx_ac_KeyActivation_s* zx_DEEP_CLONE_ac_KeyActivation(struct zx_ctx* c, struct zx_ac_KeyActivation_s* x, int dup_strs)
{
  x = (struct zx_ac_KeyActivation_s*)zx_clone_elem_common(c, &x->gg, sizeof(struct zx_ac_KeyActivation_s), dup_strs);
  /* *** deal with xmlns specifications in exc c14n way */


  {
      struct zx_ac_ActivationPin_s* e;
      struct zx_ac_ActivationPin_s* en;
      struct zx_ac_ActivationPin_s* enn;
      for (enn = 0, e = x->ActivationPin; e; e = (struct zx_ac_ActivationPin_s*)e->gg.g.n) {
	  en = zx_DEEP_CLONE_ac_ActivationPin(c, e, dup_strs);
	  if (!enn)
	      x->ActivationPin = en;
	  else
	      enn->gg.g.n = &en->gg.g;
	  enn = en;
      }
  }
  {
      struct zx_ac_Extension_s* e;
      struct zx_ac_Extension_s* en;
      struct zx_ac_Extension_s* enn;
      for (enn = 0, e = x->Extension; e; e = (struct zx_ac_Extension_s*)e->gg.g.n) {
	  en = zx_DEEP_CLONE_ac_Extension(c, e, dup_strs);
	  if (!enn)
	      x->Extension = en;
	  else
	      enn->gg.g.n = &en->gg.g;
	  enn = en;
      }
  }

  return x;
}

/* FUNC(zx_WALK_SO_ac_KeyActivation) */

/* Depth first traversal of the tree in either schema order or the wire order. */
 
int zx_WALK_SO_ac_KeyActivation(struct zx_ctx* c, struct zx_ac_KeyActivation_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
{
  int ret = callback(&x->gg.g, ctx);
  if (ret)
    return ret;
  
  /* *** deal with xmlns specifications in exc c14n way */


  
  ret = zx_walk_so_unknown_attributes(c, &x->gg, ctx, callback); 
  if (ret)
    return ret;

  {
      struct zx_ac_ActivationPin_s* e;
      for (e = x->ActivationPin; e; e = (struct zx_ac_ActivationPin_s*)e->gg.g.n) {
	  ret = zx_WALK_SO_ac_ActivationPin(c, e, ctx, callback);
	  if (ret)
	      return ret;
      }
  }
  {
      struct zx_ac_Extension_s* e;
      for (e = x->Extension; e; e = (struct zx_ac_Extension_s*)e->gg.g.n) {
	  ret = zx_WALK_SO_ac_Extension(c, e, ctx, callback);
	  if (ret)
	      return ret;
      }
  }

  
  return zx_walk_so_unknown_elems_and_content(c, &x->gg, ctx, callback);
}

/* FUNC(zx_WALK_WO_ac_KeyActivation) */

int zx_WALK_WO_ac_KeyActivation(struct zx_ctx* c, struct zx_ac_KeyActivation_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
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

#define EL_NAME   ac_KeySharing
#define EL_STRUCT zx_ac_KeySharing_s
#define EL_NS     ac
#define EL_TAG    KeySharing

/* FUNC(zx_FREE_ac_KeySharing) */

/* Depth first traversal of data structure to free it and its subelements. Simple
 * strings are handled as a special case according to the free_strs flag. This
 * is useful if the strings point to underlying data from the wire that was
 * allocated differently. */

/* Called by: */
void zx_FREE_ac_KeySharing(struct zx_ctx* c, struct zx_ac_KeySharing_s* x, int free_strs)
{
  /* *** deal with xmlns specifications in exc c14n way */

  zx_free_attr(c, x->sharing, free_strs);



  zx_free_elem_common(c, &x->gg, free_strs); 
}

/* FUNC(zx_NEW_ac_KeySharing) */

/* Trivial allocator/constructor for the datatype. */

/* Called by: */
struct zx_ac_KeySharing_s* zx_NEW_ac_KeySharing(struct zx_ctx* c)
{
  struct zx_ac_KeySharing_s* x = ZX_ZALLOC(c, struct zx_ac_KeySharing_s);
  x->gg.g.tok = zx_ac_KeySharing_ELEM;
  return x;
}

#ifdef ZX_ENA_AUX

/* FUNC(zx_DUP_STRS_ac_KeySharing) */

/* Depth first traversal of data structure to copy its simple strings
 * to memory allocated from the memory allocator. The decoder will
 * use the underlying wireprotocol PDU buffer for strings, i.e.
 * strings are not copied - they point to the real data. If the
 * datastructure needs to outlast the protocol data or needs a different
 * memory allocation strategy, you need to call this function.  */

/* Called by: */
void zx_DUP_STRS_ac_KeySharing(struct zx_ctx* c, struct zx_ac_KeySharing_s* x)
{
  zx_dup_strs_common(c, &x->gg);
  /* *** deal with xmlns specifications in exc c14n way */

  zx_dup_attr(c, x->sharing);


}

/* FUNC(zx_DEEP_CLONE_ac_KeySharing) */

/* Depth first traversal of data structure to clone it and its sublements.
 * The simple strings are handled as a special case according to dup_strs flag. */

/* Called by: */
struct zx_ac_KeySharing_s* zx_DEEP_CLONE_ac_KeySharing(struct zx_ctx* c, struct zx_ac_KeySharing_s* x, int dup_strs)
{
  x = (struct zx_ac_KeySharing_s*)zx_clone_elem_common(c, &x->gg, sizeof(struct zx_ac_KeySharing_s), dup_strs);
  /* *** deal with xmlns specifications in exc c14n way */

  x->sharing = zx_clone_attr(c, x->sharing);


  return x;
}

/* FUNC(zx_WALK_SO_ac_KeySharing) */

/* Depth first traversal of the tree in either schema order or the wire order. */
 
int zx_WALK_SO_ac_KeySharing(struct zx_ctx* c, struct zx_ac_KeySharing_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
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

/* FUNC(zx_WALK_WO_ac_KeySharing) */

int zx_WALK_WO_ac_KeySharing(struct zx_ctx* c, struct zx_ac_KeySharing_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
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

#define EL_NAME   ac_KeyStorage
#define EL_STRUCT zx_ac_KeyStorage_s
#define EL_NS     ac
#define EL_TAG    KeyStorage

/* FUNC(zx_FREE_ac_KeyStorage) */

/* Depth first traversal of data structure to free it and its subelements. Simple
 * strings are handled as a special case according to the free_strs flag. This
 * is useful if the strings point to underlying data from the wire that was
 * allocated differently. */

/* Called by: */
void zx_FREE_ac_KeyStorage(struct zx_ctx* c, struct zx_ac_KeyStorage_s* x, int free_strs)
{
  /* *** deal with xmlns specifications in exc c14n way */

  zx_free_attr(c, x->medium, free_strs);



  zx_free_elem_common(c, &x->gg, free_strs); 
}

/* FUNC(zx_NEW_ac_KeyStorage) */

/* Trivial allocator/constructor for the datatype. */

/* Called by: */
struct zx_ac_KeyStorage_s* zx_NEW_ac_KeyStorage(struct zx_ctx* c)
{
  struct zx_ac_KeyStorage_s* x = ZX_ZALLOC(c, struct zx_ac_KeyStorage_s);
  x->gg.g.tok = zx_ac_KeyStorage_ELEM;
  return x;
}

#ifdef ZX_ENA_AUX

/* FUNC(zx_DUP_STRS_ac_KeyStorage) */

/* Depth first traversal of data structure to copy its simple strings
 * to memory allocated from the memory allocator. The decoder will
 * use the underlying wireprotocol PDU buffer for strings, i.e.
 * strings are not copied - they point to the real data. If the
 * datastructure needs to outlast the protocol data or needs a different
 * memory allocation strategy, you need to call this function.  */

/* Called by: */
void zx_DUP_STRS_ac_KeyStorage(struct zx_ctx* c, struct zx_ac_KeyStorage_s* x)
{
  zx_dup_strs_common(c, &x->gg);
  /* *** deal with xmlns specifications in exc c14n way */

  zx_dup_attr(c, x->medium);


}

/* FUNC(zx_DEEP_CLONE_ac_KeyStorage) */

/* Depth first traversal of data structure to clone it and its sublements.
 * The simple strings are handled as a special case according to dup_strs flag. */

/* Called by: */
struct zx_ac_KeyStorage_s* zx_DEEP_CLONE_ac_KeyStorage(struct zx_ctx* c, struct zx_ac_KeyStorage_s* x, int dup_strs)
{
  x = (struct zx_ac_KeyStorage_s*)zx_clone_elem_common(c, &x->gg, sizeof(struct zx_ac_KeyStorage_s), dup_strs);
  /* *** deal with xmlns specifications in exc c14n way */

  x->medium = zx_clone_attr(c, x->medium);


  return x;
}

/* FUNC(zx_WALK_SO_ac_KeyStorage) */

/* Depth first traversal of the tree in either schema order or the wire order. */
 
int zx_WALK_SO_ac_KeyStorage(struct zx_ctx* c, struct zx_ac_KeyStorage_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
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

/* FUNC(zx_WALK_WO_ac_KeyStorage) */

int zx_WALK_WO_ac_KeyStorage(struct zx_ctx* c, struct zx_ac_KeyStorage_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
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

#define EL_NAME   ac_Length
#define EL_STRUCT zx_ac_Length_s
#define EL_NS     ac
#define EL_TAG    Length

/* FUNC(zx_FREE_ac_Length) */

/* Depth first traversal of data structure to free it and its subelements. Simple
 * strings are handled as a special case according to the free_strs flag. This
 * is useful if the strings point to underlying data from the wire that was
 * allocated differently. */

/* Called by: */
void zx_FREE_ac_Length(struct zx_ctx* c, struct zx_ac_Length_s* x, int free_strs)
{
  /* *** deal with xmlns specifications in exc c14n way */

  zx_free_attr(c, x->max, free_strs);
  zx_free_attr(c, x->min, free_strs);



  zx_free_elem_common(c, &x->gg, free_strs); 
}

/* FUNC(zx_NEW_ac_Length) */

/* Trivial allocator/constructor for the datatype. */

/* Called by: */
struct zx_ac_Length_s* zx_NEW_ac_Length(struct zx_ctx* c)
{
  struct zx_ac_Length_s* x = ZX_ZALLOC(c, struct zx_ac_Length_s);
  x->gg.g.tok = zx_ac_Length_ELEM;
  return x;
}

#ifdef ZX_ENA_AUX

/* FUNC(zx_DUP_STRS_ac_Length) */

/* Depth first traversal of data structure to copy its simple strings
 * to memory allocated from the memory allocator. The decoder will
 * use the underlying wireprotocol PDU buffer for strings, i.e.
 * strings are not copied - they point to the real data. If the
 * datastructure needs to outlast the protocol data or needs a different
 * memory allocation strategy, you need to call this function.  */

/* Called by: */
void zx_DUP_STRS_ac_Length(struct zx_ctx* c, struct zx_ac_Length_s* x)
{
  zx_dup_strs_common(c, &x->gg);
  /* *** deal with xmlns specifications in exc c14n way */

  zx_dup_attr(c, x->max);
  zx_dup_attr(c, x->min);


}

/* FUNC(zx_DEEP_CLONE_ac_Length) */

/* Depth first traversal of data structure to clone it and its sublements.
 * The simple strings are handled as a special case according to dup_strs flag. */

/* Called by: */
struct zx_ac_Length_s* zx_DEEP_CLONE_ac_Length(struct zx_ctx* c, struct zx_ac_Length_s* x, int dup_strs)
{
  x = (struct zx_ac_Length_s*)zx_clone_elem_common(c, &x->gg, sizeof(struct zx_ac_Length_s), dup_strs);
  /* *** deal with xmlns specifications in exc c14n way */

  x->max = zx_clone_attr(c, x->max);
  x->min = zx_clone_attr(c, x->min);


  return x;
}

/* FUNC(zx_WALK_SO_ac_Length) */

/* Depth first traversal of the tree in either schema order or the wire order. */
 
int zx_WALK_SO_ac_Length(struct zx_ctx* c, struct zx_ac_Length_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
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

/* FUNC(zx_WALK_WO_ac_Length) */

int zx_WALK_WO_ac_Length(struct zx_ctx* c, struct zx_ac_Length_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
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

#define EL_NAME   ac_MobileNetworkEndToEndEncryption
#define EL_STRUCT zx_ac_MobileNetworkEndToEndEncryption_s
#define EL_NS     ac
#define EL_TAG    MobileNetworkEndToEndEncryption

/* FUNC(zx_FREE_ac_MobileNetworkEndToEndEncryption) */

/* Depth first traversal of data structure to free it and its subelements. Simple
 * strings are handled as a special case according to the free_strs flag. This
 * is useful if the strings point to underlying data from the wire that was
 * allocated differently. */

/* Called by: */
void zx_FREE_ac_MobileNetworkEndToEndEncryption(struct zx_ctx* c, struct zx_ac_MobileNetworkEndToEndEncryption_s* x, int free_strs)
{
  /* *** deal with xmlns specifications in exc c14n way */


  {
      struct zx_ac_Extension_s* e;
      struct zx_ac_Extension_s* en;
      for (e = x->Extension; e; e = en) {
	  en = (struct zx_ac_Extension_s*)e->gg.g.n;
	  zx_FREE_ac_Extension(c, e, free_strs);
      }
  }


  zx_free_elem_common(c, &x->gg, free_strs); 
}

/* FUNC(zx_NEW_ac_MobileNetworkEndToEndEncryption) */

/* Trivial allocator/constructor for the datatype. */

/* Called by: */
struct zx_ac_MobileNetworkEndToEndEncryption_s* zx_NEW_ac_MobileNetworkEndToEndEncryption(struct zx_ctx* c)
{
  struct zx_ac_MobileNetworkEndToEndEncryption_s* x = ZX_ZALLOC(c, struct zx_ac_MobileNetworkEndToEndEncryption_s);
  x->gg.g.tok = zx_ac_MobileNetworkEndToEndEncryption_ELEM;
  return x;
}

#ifdef ZX_ENA_AUX

/* FUNC(zx_DUP_STRS_ac_MobileNetworkEndToEndEncryption) */

/* Depth first traversal of data structure to copy its simple strings
 * to memory allocated from the memory allocator. The decoder will
 * use the underlying wireprotocol PDU buffer for strings, i.e.
 * strings are not copied - they point to the real data. If the
 * datastructure needs to outlast the protocol data or needs a different
 * memory allocation strategy, you need to call this function.  */

/* Called by: */
void zx_DUP_STRS_ac_MobileNetworkEndToEndEncryption(struct zx_ctx* c, struct zx_ac_MobileNetworkEndToEndEncryption_s* x)
{
  zx_dup_strs_common(c, &x->gg);
  /* *** deal with xmlns specifications in exc c14n way */


  {
      struct zx_ac_Extension_s* e;
      for (e = x->Extension; e; e = (struct zx_ac_Extension_s*)e->gg.g.n)
	  zx_DUP_STRS_ac_Extension(c, e);
  }

}

/* FUNC(zx_DEEP_CLONE_ac_MobileNetworkEndToEndEncryption) */

/* Depth first traversal of data structure to clone it and its sublements.
 * The simple strings are handled as a special case according to dup_strs flag. */

/* Called by: */
struct zx_ac_MobileNetworkEndToEndEncryption_s* zx_DEEP_CLONE_ac_MobileNetworkEndToEndEncryption(struct zx_ctx* c, struct zx_ac_MobileNetworkEndToEndEncryption_s* x, int dup_strs)
{
  x = (struct zx_ac_MobileNetworkEndToEndEncryption_s*)zx_clone_elem_common(c, &x->gg, sizeof(struct zx_ac_MobileNetworkEndToEndEncryption_s), dup_strs);
  /* *** deal with xmlns specifications in exc c14n way */


  {
      struct zx_ac_Extension_s* e;
      struct zx_ac_Extension_s* en;
      struct zx_ac_Extension_s* enn;
      for (enn = 0, e = x->Extension; e; e = (struct zx_ac_Extension_s*)e->gg.g.n) {
	  en = zx_DEEP_CLONE_ac_Extension(c, e, dup_strs);
	  if (!enn)
	      x->Extension = en;
	  else
	      enn->gg.g.n = &en->gg.g;
	  enn = en;
      }
  }

  return x;
}

/* FUNC(zx_WALK_SO_ac_MobileNetworkEndToEndEncryption) */

/* Depth first traversal of the tree in either schema order or the wire order. */
 
int zx_WALK_SO_ac_MobileNetworkEndToEndEncryption(struct zx_ctx* c, struct zx_ac_MobileNetworkEndToEndEncryption_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
{
  int ret = callback(&x->gg.g, ctx);
  if (ret)
    return ret;
  
  /* *** deal with xmlns specifications in exc c14n way */


  
  ret = zx_walk_so_unknown_attributes(c, &x->gg, ctx, callback); 
  if (ret)
    return ret;

  {
      struct zx_ac_Extension_s* e;
      for (e = x->Extension; e; e = (struct zx_ac_Extension_s*)e->gg.g.n) {
	  ret = zx_WALK_SO_ac_Extension(c, e, ctx, callback);
	  if (ret)
	      return ret;
      }
  }

  
  return zx_walk_so_unknown_elems_and_content(c, &x->gg, ctx, callback);
}

/* FUNC(zx_WALK_WO_ac_MobileNetworkEndToEndEncryption) */

int zx_WALK_WO_ac_MobileNetworkEndToEndEncryption(struct zx_ctx* c, struct zx_ac_MobileNetworkEndToEndEncryption_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
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

#define EL_NAME   ac_MobileNetworkNoEncryption
#define EL_STRUCT zx_ac_MobileNetworkNoEncryption_s
#define EL_NS     ac
#define EL_TAG    MobileNetworkNoEncryption

/* FUNC(zx_FREE_ac_MobileNetworkNoEncryption) */

/* Depth first traversal of data structure to free it and its subelements. Simple
 * strings are handled as a special case according to the free_strs flag. This
 * is useful if the strings point to underlying data from the wire that was
 * allocated differently. */

/* Called by: */
void zx_FREE_ac_MobileNetworkNoEncryption(struct zx_ctx* c, struct zx_ac_MobileNetworkNoEncryption_s* x, int free_strs)
{
  /* *** deal with xmlns specifications in exc c14n way */


  {
      struct zx_ac_Extension_s* e;
      struct zx_ac_Extension_s* en;
      for (e = x->Extension; e; e = en) {
	  en = (struct zx_ac_Extension_s*)e->gg.g.n;
	  zx_FREE_ac_Extension(c, e, free_strs);
      }
  }


  zx_free_elem_common(c, &x->gg, free_strs); 
}

/* FUNC(zx_NEW_ac_MobileNetworkNoEncryption) */

/* Trivial allocator/constructor for the datatype. */

/* Called by: */
struct zx_ac_MobileNetworkNoEncryption_s* zx_NEW_ac_MobileNetworkNoEncryption(struct zx_ctx* c)
{
  struct zx_ac_MobileNetworkNoEncryption_s* x = ZX_ZALLOC(c, struct zx_ac_MobileNetworkNoEncryption_s);
  x->gg.g.tok = zx_ac_MobileNetworkNoEncryption_ELEM;
  return x;
}

#ifdef ZX_ENA_AUX

/* FUNC(zx_DUP_STRS_ac_MobileNetworkNoEncryption) */

/* Depth first traversal of data structure to copy its simple strings
 * to memory allocated from the memory allocator. The decoder will
 * use the underlying wireprotocol PDU buffer for strings, i.e.
 * strings are not copied - they point to the real data. If the
 * datastructure needs to outlast the protocol data or needs a different
 * memory allocation strategy, you need to call this function.  */

/* Called by: */
void zx_DUP_STRS_ac_MobileNetworkNoEncryption(struct zx_ctx* c, struct zx_ac_MobileNetworkNoEncryption_s* x)
{
  zx_dup_strs_common(c, &x->gg);
  /* *** deal with xmlns specifications in exc c14n way */


  {
      struct zx_ac_Extension_s* e;
      for (e = x->Extension; e; e = (struct zx_ac_Extension_s*)e->gg.g.n)
	  zx_DUP_STRS_ac_Extension(c, e);
  }

}

/* FUNC(zx_DEEP_CLONE_ac_MobileNetworkNoEncryption) */

/* Depth first traversal of data structure to clone it and its sublements.
 * The simple strings are handled as a special case according to dup_strs flag. */

/* Called by: */
struct zx_ac_MobileNetworkNoEncryption_s* zx_DEEP_CLONE_ac_MobileNetworkNoEncryption(struct zx_ctx* c, struct zx_ac_MobileNetworkNoEncryption_s* x, int dup_strs)
{
  x = (struct zx_ac_MobileNetworkNoEncryption_s*)zx_clone_elem_common(c, &x->gg, sizeof(struct zx_ac_MobileNetworkNoEncryption_s), dup_strs);
  /* *** deal with xmlns specifications in exc c14n way */


  {
      struct zx_ac_Extension_s* e;
      struct zx_ac_Extension_s* en;
      struct zx_ac_Extension_s* enn;
      for (enn = 0, e = x->Extension; e; e = (struct zx_ac_Extension_s*)e->gg.g.n) {
	  en = zx_DEEP_CLONE_ac_Extension(c, e, dup_strs);
	  if (!enn)
	      x->Extension = en;
	  else
	      enn->gg.g.n = &en->gg.g;
	  enn = en;
      }
  }

  return x;
}

/* FUNC(zx_WALK_SO_ac_MobileNetworkNoEncryption) */

/* Depth first traversal of the tree in either schema order or the wire order. */
 
int zx_WALK_SO_ac_MobileNetworkNoEncryption(struct zx_ctx* c, struct zx_ac_MobileNetworkNoEncryption_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
{
  int ret = callback(&x->gg.g, ctx);
  if (ret)
    return ret;
  
  /* *** deal with xmlns specifications in exc c14n way */


  
  ret = zx_walk_so_unknown_attributes(c, &x->gg, ctx, callback); 
  if (ret)
    return ret;

  {
      struct zx_ac_Extension_s* e;
      for (e = x->Extension; e; e = (struct zx_ac_Extension_s*)e->gg.g.n) {
	  ret = zx_WALK_SO_ac_Extension(c, e, ctx, callback);
	  if (ret)
	      return ret;
      }
  }

  
  return zx_walk_so_unknown_elems_and_content(c, &x->gg, ctx, callback);
}

/* FUNC(zx_WALK_WO_ac_MobileNetworkNoEncryption) */

int zx_WALK_WO_ac_MobileNetworkNoEncryption(struct zx_ctx* c, struct zx_ac_MobileNetworkNoEncryption_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
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

#define EL_NAME   ac_MobileNetworkRadioEncryption
#define EL_STRUCT zx_ac_MobileNetworkRadioEncryption_s
#define EL_NS     ac
#define EL_TAG    MobileNetworkRadioEncryption

/* FUNC(zx_FREE_ac_MobileNetworkRadioEncryption) */

/* Depth first traversal of data structure to free it and its subelements. Simple
 * strings are handled as a special case according to the free_strs flag. This
 * is useful if the strings point to underlying data from the wire that was
 * allocated differently. */

/* Called by: */
void zx_FREE_ac_MobileNetworkRadioEncryption(struct zx_ctx* c, struct zx_ac_MobileNetworkRadioEncryption_s* x, int free_strs)
{
  /* *** deal with xmlns specifications in exc c14n way */


  {
      struct zx_ac_Extension_s* e;
      struct zx_ac_Extension_s* en;
      for (e = x->Extension; e; e = en) {
	  en = (struct zx_ac_Extension_s*)e->gg.g.n;
	  zx_FREE_ac_Extension(c, e, free_strs);
      }
  }


  zx_free_elem_common(c, &x->gg, free_strs); 
}

/* FUNC(zx_NEW_ac_MobileNetworkRadioEncryption) */

/* Trivial allocator/constructor for the datatype. */

/* Called by: */
struct zx_ac_MobileNetworkRadioEncryption_s* zx_NEW_ac_MobileNetworkRadioEncryption(struct zx_ctx* c)
{
  struct zx_ac_MobileNetworkRadioEncryption_s* x = ZX_ZALLOC(c, struct zx_ac_MobileNetworkRadioEncryption_s);
  x->gg.g.tok = zx_ac_MobileNetworkRadioEncryption_ELEM;
  return x;
}

#ifdef ZX_ENA_AUX

/* FUNC(zx_DUP_STRS_ac_MobileNetworkRadioEncryption) */

/* Depth first traversal of data structure to copy its simple strings
 * to memory allocated from the memory allocator. The decoder will
 * use the underlying wireprotocol PDU buffer for strings, i.e.
 * strings are not copied - they point to the real data. If the
 * datastructure needs to outlast the protocol data or needs a different
 * memory allocation strategy, you need to call this function.  */

/* Called by: */
void zx_DUP_STRS_ac_MobileNetworkRadioEncryption(struct zx_ctx* c, struct zx_ac_MobileNetworkRadioEncryption_s* x)
{
  zx_dup_strs_common(c, &x->gg);
  /* *** deal with xmlns specifications in exc c14n way */


  {
      struct zx_ac_Extension_s* e;
      for (e = x->Extension; e; e = (struct zx_ac_Extension_s*)e->gg.g.n)
	  zx_DUP_STRS_ac_Extension(c, e);
  }

}

/* FUNC(zx_DEEP_CLONE_ac_MobileNetworkRadioEncryption) */

/* Depth first traversal of data structure to clone it and its sublements.
 * The simple strings are handled as a special case according to dup_strs flag. */

/* Called by: */
struct zx_ac_MobileNetworkRadioEncryption_s* zx_DEEP_CLONE_ac_MobileNetworkRadioEncryption(struct zx_ctx* c, struct zx_ac_MobileNetworkRadioEncryption_s* x, int dup_strs)
{
  x = (struct zx_ac_MobileNetworkRadioEncryption_s*)zx_clone_elem_common(c, &x->gg, sizeof(struct zx_ac_MobileNetworkRadioEncryption_s), dup_strs);
  /* *** deal with xmlns specifications in exc c14n way */


  {
      struct zx_ac_Extension_s* e;
      struct zx_ac_Extension_s* en;
      struct zx_ac_Extension_s* enn;
      for (enn = 0, e = x->Extension; e; e = (struct zx_ac_Extension_s*)e->gg.g.n) {
	  en = zx_DEEP_CLONE_ac_Extension(c, e, dup_strs);
	  if (!enn)
	      x->Extension = en;
	  else
	      enn->gg.g.n = &en->gg.g;
	  enn = en;
      }
  }

  return x;
}

/* FUNC(zx_WALK_SO_ac_MobileNetworkRadioEncryption) */

/* Depth first traversal of the tree in either schema order or the wire order. */
 
int zx_WALK_SO_ac_MobileNetworkRadioEncryption(struct zx_ctx* c, struct zx_ac_MobileNetworkRadioEncryption_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
{
  int ret = callback(&x->gg.g, ctx);
  if (ret)
    return ret;
  
  /* *** deal with xmlns specifications in exc c14n way */


  
  ret = zx_walk_so_unknown_attributes(c, &x->gg, ctx, callback); 
  if (ret)
    return ret;

  {
      struct zx_ac_Extension_s* e;
      for (e = x->Extension; e; e = (struct zx_ac_Extension_s*)e->gg.g.n) {
	  ret = zx_WALK_SO_ac_Extension(c, e, ctx, callback);
	  if (ret)
	      return ret;
      }
  }

  
  return zx_walk_so_unknown_elems_and_content(c, &x->gg, ctx, callback);
}

/* FUNC(zx_WALK_WO_ac_MobileNetworkRadioEncryption) */

int zx_WALK_WO_ac_MobileNetworkRadioEncryption(struct zx_ctx* c, struct zx_ac_MobileNetworkRadioEncryption_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
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

#define EL_NAME   ac_OperationalProtection
#define EL_STRUCT zx_ac_OperationalProtection_s
#define EL_NS     ac
#define EL_TAG    OperationalProtection

/* FUNC(zx_FREE_ac_OperationalProtection) */

/* Depth first traversal of data structure to free it and its subelements. Simple
 * strings are handled as a special case according to the free_strs flag. This
 * is useful if the strings point to underlying data from the wire that was
 * allocated differently. */

/* Called by: */
void zx_FREE_ac_OperationalProtection(struct zx_ctx* c, struct zx_ac_OperationalProtection_s* x, int free_strs)
{
  /* *** deal with xmlns specifications in exc c14n way */


  {
      struct zx_ac_SecurityAudit_s* e;
      struct zx_ac_SecurityAudit_s* en;
      for (e = x->SecurityAudit; e; e = en) {
	  en = (struct zx_ac_SecurityAudit_s*)e->gg.g.n;
	  zx_FREE_ac_SecurityAudit(c, e, free_strs);
      }
  }
  {
      struct zx_ac_DeactivationCallCenter_s* e;
      struct zx_ac_DeactivationCallCenter_s* en;
      for (e = x->DeactivationCallCenter; e; e = en) {
	  en = (struct zx_ac_DeactivationCallCenter_s*)e->gg.g.n;
	  zx_FREE_ac_DeactivationCallCenter(c, e, free_strs);
      }
  }
  {
      struct zx_ac_Extension_s* e;
      struct zx_ac_Extension_s* en;
      for (e = x->Extension; e; e = en) {
	  en = (struct zx_ac_Extension_s*)e->gg.g.n;
	  zx_FREE_ac_Extension(c, e, free_strs);
      }
  }


  zx_free_elem_common(c, &x->gg, free_strs); 
}

/* FUNC(zx_NEW_ac_OperationalProtection) */

/* Trivial allocator/constructor for the datatype. */

/* Called by: */
struct zx_ac_OperationalProtection_s* zx_NEW_ac_OperationalProtection(struct zx_ctx* c)
{
  struct zx_ac_OperationalProtection_s* x = ZX_ZALLOC(c, struct zx_ac_OperationalProtection_s);
  x->gg.g.tok = zx_ac_OperationalProtection_ELEM;
  return x;
}

#ifdef ZX_ENA_AUX

/* FUNC(zx_DUP_STRS_ac_OperationalProtection) */

/* Depth first traversal of data structure to copy its simple strings
 * to memory allocated from the memory allocator. The decoder will
 * use the underlying wireprotocol PDU buffer for strings, i.e.
 * strings are not copied - they point to the real data. If the
 * datastructure needs to outlast the protocol data or needs a different
 * memory allocation strategy, you need to call this function.  */

/* Called by: */
void zx_DUP_STRS_ac_OperationalProtection(struct zx_ctx* c, struct zx_ac_OperationalProtection_s* x)
{
  zx_dup_strs_common(c, &x->gg);
  /* *** deal with xmlns specifications in exc c14n way */


  {
      struct zx_ac_SecurityAudit_s* e;
      for (e = x->SecurityAudit; e; e = (struct zx_ac_SecurityAudit_s*)e->gg.g.n)
	  zx_DUP_STRS_ac_SecurityAudit(c, e);
  }
  {
      struct zx_ac_DeactivationCallCenter_s* e;
      for (e = x->DeactivationCallCenter; e; e = (struct zx_ac_DeactivationCallCenter_s*)e->gg.g.n)
	  zx_DUP_STRS_ac_DeactivationCallCenter(c, e);
  }
  {
      struct zx_ac_Extension_s* e;
      for (e = x->Extension; e; e = (struct zx_ac_Extension_s*)e->gg.g.n)
	  zx_DUP_STRS_ac_Extension(c, e);
  }

}

/* FUNC(zx_DEEP_CLONE_ac_OperationalProtection) */

/* Depth first traversal of data structure to clone it and its sublements.
 * The simple strings are handled as a special case according to dup_strs flag. */

/* Called by: */
struct zx_ac_OperationalProtection_s* zx_DEEP_CLONE_ac_OperationalProtection(struct zx_ctx* c, struct zx_ac_OperationalProtection_s* x, int dup_strs)
{
  x = (struct zx_ac_OperationalProtection_s*)zx_clone_elem_common(c, &x->gg, sizeof(struct zx_ac_OperationalProtection_s), dup_strs);
  /* *** deal with xmlns specifications in exc c14n way */


  {
      struct zx_ac_SecurityAudit_s* e;
      struct zx_ac_SecurityAudit_s* en;
      struct zx_ac_SecurityAudit_s* enn;
      for (enn = 0, e = x->SecurityAudit; e; e = (struct zx_ac_SecurityAudit_s*)e->gg.g.n) {
	  en = zx_DEEP_CLONE_ac_SecurityAudit(c, e, dup_strs);
	  if (!enn)
	      x->SecurityAudit = en;
	  else
	      enn->gg.g.n = &en->gg.g;
	  enn = en;
      }
  }
  {
      struct zx_ac_DeactivationCallCenter_s* e;
      struct zx_ac_DeactivationCallCenter_s* en;
      struct zx_ac_DeactivationCallCenter_s* enn;
      for (enn = 0, e = x->DeactivationCallCenter; e; e = (struct zx_ac_DeactivationCallCenter_s*)e->gg.g.n) {
	  en = zx_DEEP_CLONE_ac_DeactivationCallCenter(c, e, dup_strs);
	  if (!enn)
	      x->DeactivationCallCenter = en;
	  else
	      enn->gg.g.n = &en->gg.g;
	  enn = en;
      }
  }
  {
      struct zx_ac_Extension_s* e;
      struct zx_ac_Extension_s* en;
      struct zx_ac_Extension_s* enn;
      for (enn = 0, e = x->Extension; e; e = (struct zx_ac_Extension_s*)e->gg.g.n) {
	  en = zx_DEEP_CLONE_ac_Extension(c, e, dup_strs);
	  if (!enn)
	      x->Extension = en;
	  else
	      enn->gg.g.n = &en->gg.g;
	  enn = en;
      }
  }

  return x;
}

/* FUNC(zx_WALK_SO_ac_OperationalProtection) */

/* Depth first traversal of the tree in either schema order or the wire order. */
 
int zx_WALK_SO_ac_OperationalProtection(struct zx_ctx* c, struct zx_ac_OperationalProtection_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
{
  int ret = callback(&x->gg.g, ctx);
  if (ret)
    return ret;
  
  /* *** deal with xmlns specifications in exc c14n way */


  
  ret = zx_walk_so_unknown_attributes(c, &x->gg, ctx, callback); 
  if (ret)
    return ret;

  {
      struct zx_ac_SecurityAudit_s* e;
      for (e = x->SecurityAudit; e; e = (struct zx_ac_SecurityAudit_s*)e->gg.g.n) {
	  ret = zx_WALK_SO_ac_SecurityAudit(c, e, ctx, callback);
	  if (ret)
	      return ret;
      }
  }
  {
      struct zx_ac_DeactivationCallCenter_s* e;
      for (e = x->DeactivationCallCenter; e; e = (struct zx_ac_DeactivationCallCenter_s*)e->gg.g.n) {
	  ret = zx_WALK_SO_ac_DeactivationCallCenter(c, e, ctx, callback);
	  if (ret)
	      return ret;
      }
  }
  {
      struct zx_ac_Extension_s* e;
      for (e = x->Extension; e; e = (struct zx_ac_Extension_s*)e->gg.g.n) {
	  ret = zx_WALK_SO_ac_Extension(c, e, ctx, callback);
	  if (ret)
	      return ret;
      }
  }

  
  return zx_walk_so_unknown_elems_and_content(c, &x->gg, ctx, callback);
}

/* FUNC(zx_WALK_WO_ac_OperationalProtection) */

int zx_WALK_WO_ac_OperationalProtection(struct zx_ctx* c, struct zx_ac_OperationalProtection_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
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

#define EL_NAME   ac_Password
#define EL_STRUCT zx_ac_Password_s
#define EL_NS     ac
#define EL_TAG    Password

/* FUNC(zx_FREE_ac_Password) */

/* Depth first traversal of data structure to free it and its subelements. Simple
 * strings are handled as a special case according to the free_strs flag. This
 * is useful if the strings point to underlying data from the wire that was
 * allocated differently. */

/* Called by: */
void zx_FREE_ac_Password(struct zx_ctx* c, struct zx_ac_Password_s* x, int free_strs)
{
  /* *** deal with xmlns specifications in exc c14n way */


  {
      struct zx_ac_Length_s* e;
      struct zx_ac_Length_s* en;
      for (e = x->Length; e; e = en) {
	  en = (struct zx_ac_Length_s*)e->gg.g.n;
	  zx_FREE_ac_Length(c, e, free_strs);
      }
  }
  {
      struct zx_ac_Alphabet_s* e;
      struct zx_ac_Alphabet_s* en;
      for (e = x->Alphabet; e; e = en) {
	  en = (struct zx_ac_Alphabet_s*)e->gg.g.n;
	  zx_FREE_ac_Alphabet(c, e, free_strs);
      }
  }
  {
      struct zx_ac_Generation_s* e;
      struct zx_ac_Generation_s* en;
      for (e = x->Generation; e; e = en) {
	  en = (struct zx_ac_Generation_s*)e->gg.g.n;
	  zx_FREE_ac_Generation(c, e, free_strs);
      }
  }
  {
      struct zx_ac_Extension_s* e;
      struct zx_ac_Extension_s* en;
      for (e = x->Extension; e; e = en) {
	  en = (struct zx_ac_Extension_s*)e->gg.g.n;
	  zx_FREE_ac_Extension(c, e, free_strs);
      }
  }


  zx_free_elem_common(c, &x->gg, free_strs); 
}

/* FUNC(zx_NEW_ac_Password) */

/* Trivial allocator/constructor for the datatype. */

/* Called by: */
struct zx_ac_Password_s* zx_NEW_ac_Password(struct zx_ctx* c)
{
  struct zx_ac_Password_s* x = ZX_ZALLOC(c, struct zx_ac_Password_s);
  x->gg.g.tok = zx_ac_Password_ELEM;
  return x;
}

#ifdef ZX_ENA_AUX

/* FUNC(zx_DUP_STRS_ac_Password) */

/* Depth first traversal of data structure to copy its simple strings
 * to memory allocated from the memory allocator. The decoder will
 * use the underlying wireprotocol PDU buffer for strings, i.e.
 * strings are not copied - they point to the real data. If the
 * datastructure needs to outlast the protocol data or needs a different
 * memory allocation strategy, you need to call this function.  */

/* Called by: */
void zx_DUP_STRS_ac_Password(struct zx_ctx* c, struct zx_ac_Password_s* x)
{
  zx_dup_strs_common(c, &x->gg);
  /* *** deal with xmlns specifications in exc c14n way */


  {
      struct zx_ac_Length_s* e;
      for (e = x->Length; e; e = (struct zx_ac_Length_s*)e->gg.g.n)
	  zx_DUP_STRS_ac_Length(c, e);
  }
  {
      struct zx_ac_Alphabet_s* e;
      for (e = x->Alphabet; e; e = (struct zx_ac_Alphabet_s*)e->gg.g.n)
	  zx_DUP_STRS_ac_Alphabet(c, e);
  }
  {
      struct zx_ac_Generation_s* e;
      for (e = x->Generation; e; e = (struct zx_ac_Generation_s*)e->gg.g.n)
	  zx_DUP_STRS_ac_Generation(c, e);
  }
  {
      struct zx_ac_Extension_s* e;
      for (e = x->Extension; e; e = (struct zx_ac_Extension_s*)e->gg.g.n)
	  zx_DUP_STRS_ac_Extension(c, e);
  }

}

/* FUNC(zx_DEEP_CLONE_ac_Password) */

/* Depth first traversal of data structure to clone it and its sublements.
 * The simple strings are handled as a special case according to dup_strs flag. */

/* Called by: */
struct zx_ac_Password_s* zx_DEEP_CLONE_ac_Password(struct zx_ctx* c, struct zx_ac_Password_s* x, int dup_strs)
{
  x = (struct zx_ac_Password_s*)zx_clone_elem_common(c, &x->gg, sizeof(struct zx_ac_Password_s), dup_strs);
  /* *** deal with xmlns specifications in exc c14n way */


  {
      struct zx_ac_Length_s* e;
      struct zx_ac_Length_s* en;
      struct zx_ac_Length_s* enn;
      for (enn = 0, e = x->Length; e; e = (struct zx_ac_Length_s*)e->gg.g.n) {
	  en = zx_DEEP_CLONE_ac_Length(c, e, dup_strs);
	  if (!enn)
	      x->Length = en;
	  else
	      enn->gg.g.n = &en->gg.g;
	  enn = en;
      }
  }
  {
      struct zx_ac_Alphabet_s* e;
      struct zx_ac_Alphabet_s* en;
      struct zx_ac_Alphabet_s* enn;
      for (enn = 0, e = x->Alphabet; e; e = (struct zx_ac_Alphabet_s*)e->gg.g.n) {
	  en = zx_DEEP_CLONE_ac_Alphabet(c, e, dup_strs);
	  if (!enn)
	      x->Alphabet = en;
	  else
	      enn->gg.g.n = &en->gg.g;
	  enn = en;
      }
  }
  {
      struct zx_ac_Generation_s* e;
      struct zx_ac_Generation_s* en;
      struct zx_ac_Generation_s* enn;
      for (enn = 0, e = x->Generation; e; e = (struct zx_ac_Generation_s*)e->gg.g.n) {
	  en = zx_DEEP_CLONE_ac_Generation(c, e, dup_strs);
	  if (!enn)
	      x->Generation = en;
	  else
	      enn->gg.g.n = &en->gg.g;
	  enn = en;
      }
  }
  {
      struct zx_ac_Extension_s* e;
      struct zx_ac_Extension_s* en;
      struct zx_ac_Extension_s* enn;
      for (enn = 0, e = x->Extension; e; e = (struct zx_ac_Extension_s*)e->gg.g.n) {
	  en = zx_DEEP_CLONE_ac_Extension(c, e, dup_strs);
	  if (!enn)
	      x->Extension = en;
	  else
	      enn->gg.g.n = &en->gg.g;
	  enn = en;
      }
  }

  return x;
}

/* FUNC(zx_WALK_SO_ac_Password) */

/* Depth first traversal of the tree in either schema order or the wire order. */
 
int zx_WALK_SO_ac_Password(struct zx_ctx* c, struct zx_ac_Password_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
{
  int ret = callback(&x->gg.g, ctx);
  if (ret)
    return ret;
  
  /* *** deal with xmlns specifications in exc c14n way */


  
  ret = zx_walk_so_unknown_attributes(c, &x->gg, ctx, callback); 
  if (ret)
    return ret;

  {
      struct zx_ac_Length_s* e;
      for (e = x->Length; e; e = (struct zx_ac_Length_s*)e->gg.g.n) {
	  ret = zx_WALK_SO_ac_Length(c, e, ctx, callback);
	  if (ret)
	      return ret;
      }
  }
  {
      struct zx_ac_Alphabet_s* e;
      for (e = x->Alphabet; e; e = (struct zx_ac_Alphabet_s*)e->gg.g.n) {
	  ret = zx_WALK_SO_ac_Alphabet(c, e, ctx, callback);
	  if (ret)
	      return ret;
      }
  }
  {
      struct zx_ac_Generation_s* e;
      for (e = x->Generation; e; e = (struct zx_ac_Generation_s*)e->gg.g.n) {
	  ret = zx_WALK_SO_ac_Generation(c, e, ctx, callback);
	  if (ret)
	      return ret;
      }
  }
  {
      struct zx_ac_Extension_s* e;
      for (e = x->Extension; e; e = (struct zx_ac_Extension_s*)e->gg.g.n) {
	  ret = zx_WALK_SO_ac_Extension(c, e, ctx, callback);
	  if (ret)
	      return ret;
      }
  }

  
  return zx_walk_so_unknown_elems_and_content(c, &x->gg, ctx, callback);
}

/* FUNC(zx_WALK_WO_ac_Password) */

int zx_WALK_WO_ac_Password(struct zx_ctx* c, struct zx_ac_Password_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
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

#define EL_NAME   ac_PhysicalVerification
#define EL_STRUCT zx_ac_PhysicalVerification_s
#define EL_NS     ac
#define EL_TAG    PhysicalVerification

/* FUNC(zx_FREE_ac_PhysicalVerification) */

/* Depth first traversal of data structure to free it and its subelements. Simple
 * strings are handled as a special case according to the free_strs flag. This
 * is useful if the strings point to underlying data from the wire that was
 * allocated differently. */

/* Called by: */
void zx_FREE_ac_PhysicalVerification(struct zx_ctx* c, struct zx_ac_PhysicalVerification_s* x, int free_strs)
{
  /* *** deal with xmlns specifications in exc c14n way */

  zx_free_attr(c, x->credentialLevel, free_strs);



  zx_free_elem_common(c, &x->gg, free_strs); 
}

/* FUNC(zx_NEW_ac_PhysicalVerification) */

/* Trivial allocator/constructor for the datatype. */

/* Called by: */
struct zx_ac_PhysicalVerification_s* zx_NEW_ac_PhysicalVerification(struct zx_ctx* c)
{
  struct zx_ac_PhysicalVerification_s* x = ZX_ZALLOC(c, struct zx_ac_PhysicalVerification_s);
  x->gg.g.tok = zx_ac_PhysicalVerification_ELEM;
  return x;
}

#ifdef ZX_ENA_AUX

/* FUNC(zx_DUP_STRS_ac_PhysicalVerification) */

/* Depth first traversal of data structure to copy its simple strings
 * to memory allocated from the memory allocator. The decoder will
 * use the underlying wireprotocol PDU buffer for strings, i.e.
 * strings are not copied - they point to the real data. If the
 * datastructure needs to outlast the protocol data or needs a different
 * memory allocation strategy, you need to call this function.  */

/* Called by: */
void zx_DUP_STRS_ac_PhysicalVerification(struct zx_ctx* c, struct zx_ac_PhysicalVerification_s* x)
{
  zx_dup_strs_common(c, &x->gg);
  /* *** deal with xmlns specifications in exc c14n way */

  zx_dup_attr(c, x->credentialLevel);


}

/* FUNC(zx_DEEP_CLONE_ac_PhysicalVerification) */

/* Depth first traversal of data structure to clone it and its sublements.
 * The simple strings are handled as a special case according to dup_strs flag. */

/* Called by: */
struct zx_ac_PhysicalVerification_s* zx_DEEP_CLONE_ac_PhysicalVerification(struct zx_ctx* c, struct zx_ac_PhysicalVerification_s* x, int dup_strs)
{
  x = (struct zx_ac_PhysicalVerification_s*)zx_clone_elem_common(c, &x->gg, sizeof(struct zx_ac_PhysicalVerification_s), dup_strs);
  /* *** deal with xmlns specifications in exc c14n way */

  x->credentialLevel = zx_clone_attr(c, x->credentialLevel);


  return x;
}

/* FUNC(zx_WALK_SO_ac_PhysicalVerification) */

/* Depth first traversal of the tree in either schema order or the wire order. */
 
int zx_WALK_SO_ac_PhysicalVerification(struct zx_ctx* c, struct zx_ac_PhysicalVerification_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
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

/* FUNC(zx_WALK_WO_ac_PhysicalVerification) */

int zx_WALK_WO_ac_PhysicalVerification(struct zx_ctx* c, struct zx_ac_PhysicalVerification_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
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

#define EL_NAME   ac_PreviousSession
#define EL_STRUCT zx_ac_PreviousSession_s
#define EL_NS     ac
#define EL_TAG    PreviousSession

/* FUNC(zx_FREE_ac_PreviousSession) */

/* Depth first traversal of data structure to free it and its subelements. Simple
 * strings are handled as a special case according to the free_strs flag. This
 * is useful if the strings point to underlying data from the wire that was
 * allocated differently. */

/* Called by: */
void zx_FREE_ac_PreviousSession(struct zx_ctx* c, struct zx_ac_PreviousSession_s* x, int free_strs)
{
  /* *** deal with xmlns specifications in exc c14n way */


  {
      struct zx_ac_Extension_s* e;
      struct zx_ac_Extension_s* en;
      for (e = x->Extension; e; e = en) {
	  en = (struct zx_ac_Extension_s*)e->gg.g.n;
	  zx_FREE_ac_Extension(c, e, free_strs);
      }
  }


  zx_free_elem_common(c, &x->gg, free_strs); 
}

/* FUNC(zx_NEW_ac_PreviousSession) */

/* Trivial allocator/constructor for the datatype. */

/* Called by: */
struct zx_ac_PreviousSession_s* zx_NEW_ac_PreviousSession(struct zx_ctx* c)
{
  struct zx_ac_PreviousSession_s* x = ZX_ZALLOC(c, struct zx_ac_PreviousSession_s);
  x->gg.g.tok = zx_ac_PreviousSession_ELEM;
  return x;
}

#ifdef ZX_ENA_AUX

/* FUNC(zx_DUP_STRS_ac_PreviousSession) */

/* Depth first traversal of data structure to copy its simple strings
 * to memory allocated from the memory allocator. The decoder will
 * use the underlying wireprotocol PDU buffer for strings, i.e.
 * strings are not copied - they point to the real data. If the
 * datastructure needs to outlast the protocol data or needs a different
 * memory allocation strategy, you need to call this function.  */

/* Called by: */
void zx_DUP_STRS_ac_PreviousSession(struct zx_ctx* c, struct zx_ac_PreviousSession_s* x)
{
  zx_dup_strs_common(c, &x->gg);
  /* *** deal with xmlns specifications in exc c14n way */


  {
      struct zx_ac_Extension_s* e;
      for (e = x->Extension; e; e = (struct zx_ac_Extension_s*)e->gg.g.n)
	  zx_DUP_STRS_ac_Extension(c, e);
  }

}

/* FUNC(zx_DEEP_CLONE_ac_PreviousSession) */

/* Depth first traversal of data structure to clone it and its sublements.
 * The simple strings are handled as a special case according to dup_strs flag. */

/* Called by: */
struct zx_ac_PreviousSession_s* zx_DEEP_CLONE_ac_PreviousSession(struct zx_ctx* c, struct zx_ac_PreviousSession_s* x, int dup_strs)
{
  x = (struct zx_ac_PreviousSession_s*)zx_clone_elem_common(c, &x->gg, sizeof(struct zx_ac_PreviousSession_s), dup_strs);
  /* *** deal with xmlns specifications in exc c14n way */


  {
      struct zx_ac_Extension_s* e;
      struct zx_ac_Extension_s* en;
      struct zx_ac_Extension_s* enn;
      for (enn = 0, e = x->Extension; e; e = (struct zx_ac_Extension_s*)e->gg.g.n) {
	  en = zx_DEEP_CLONE_ac_Extension(c, e, dup_strs);
	  if (!enn)
	      x->Extension = en;
	  else
	      enn->gg.g.n = &en->gg.g;
	  enn = en;
      }
  }

  return x;
}

/* FUNC(zx_WALK_SO_ac_PreviousSession) */

/* Depth first traversal of the tree in either schema order or the wire order. */
 
int zx_WALK_SO_ac_PreviousSession(struct zx_ctx* c, struct zx_ac_PreviousSession_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
{
  int ret = callback(&x->gg.g, ctx);
  if (ret)
    return ret;
  
  /* *** deal with xmlns specifications in exc c14n way */


  
  ret = zx_walk_so_unknown_attributes(c, &x->gg, ctx, callback); 
  if (ret)
    return ret;

  {
      struct zx_ac_Extension_s* e;
      for (e = x->Extension; e; e = (struct zx_ac_Extension_s*)e->gg.g.n) {
	  ret = zx_WALK_SO_ac_Extension(c, e, ctx, callback);
	  if (ret)
	      return ret;
      }
  }

  
  return zx_walk_so_unknown_elems_and_content(c, &x->gg, ctx, callback);
}

/* FUNC(zx_WALK_WO_ac_PreviousSession) */

int zx_WALK_WO_ac_PreviousSession(struct zx_ctx* c, struct zx_ac_PreviousSession_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
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

#define EL_NAME   ac_PrincipalAuthenticationMechanism
#define EL_STRUCT zx_ac_PrincipalAuthenticationMechanism_s
#define EL_NS     ac
#define EL_TAG    PrincipalAuthenticationMechanism

/* FUNC(zx_FREE_ac_PrincipalAuthenticationMechanism) */

/* Depth first traversal of data structure to free it and its subelements. Simple
 * strings are handled as a special case according to the free_strs flag. This
 * is useful if the strings point to underlying data from the wire that was
 * allocated differently. */

/* Called by: */
void zx_FREE_ac_PrincipalAuthenticationMechanism(struct zx_ctx* c, struct zx_ac_PrincipalAuthenticationMechanism_s* x, int free_strs)
{
  /* *** deal with xmlns specifications in exc c14n way */


  {
      struct zx_ac_Password_s* e;
      struct zx_ac_Password_s* en;
      for (e = x->Password; e; e = en) {
	  en = (struct zx_ac_Password_s*)e->gg.g.n;
	  zx_FREE_ac_Password(c, e, free_strs);
      }
  }
  {
      struct zx_ac_Token_s* e;
      struct zx_ac_Token_s* en;
      for (e = x->Token; e; e = en) {
	  en = (struct zx_ac_Token_s*)e->gg.g.n;
	  zx_FREE_ac_Token(c, e, free_strs);
      }
  }
  {
      struct zx_ac_Smartcard_s* e;
      struct zx_ac_Smartcard_s* en;
      for (e = x->Smartcard; e; e = en) {
	  en = (struct zx_ac_Smartcard_s*)e->gg.g.n;
	  zx_FREE_ac_Smartcard(c, e, free_strs);
      }
  }
  {
      struct zx_ac_ActivationPin_s* e;
      struct zx_ac_ActivationPin_s* en;
      for (e = x->ActivationPin; e; e = en) {
	  en = (struct zx_ac_ActivationPin_s*)e->gg.g.n;
	  zx_FREE_ac_ActivationPin(c, e, free_strs);
      }
  }
  {
      struct zx_ac_Extension_s* e;
      struct zx_ac_Extension_s* en;
      for (e = x->Extension; e; e = en) {
	  en = (struct zx_ac_Extension_s*)e->gg.g.n;
	  zx_FREE_ac_Extension(c, e, free_strs);
      }
  }


  zx_free_elem_common(c, &x->gg, free_strs); 
}

/* FUNC(zx_NEW_ac_PrincipalAuthenticationMechanism) */

/* Trivial allocator/constructor for the datatype. */

/* Called by: */
struct zx_ac_PrincipalAuthenticationMechanism_s* zx_NEW_ac_PrincipalAuthenticationMechanism(struct zx_ctx* c)
{
  struct zx_ac_PrincipalAuthenticationMechanism_s* x = ZX_ZALLOC(c, struct zx_ac_PrincipalAuthenticationMechanism_s);
  x->gg.g.tok = zx_ac_PrincipalAuthenticationMechanism_ELEM;
  return x;
}

#ifdef ZX_ENA_AUX

/* FUNC(zx_DUP_STRS_ac_PrincipalAuthenticationMechanism) */

/* Depth first traversal of data structure to copy its simple strings
 * to memory allocated from the memory allocator. The decoder will
 * use the underlying wireprotocol PDU buffer for strings, i.e.
 * strings are not copied - they point to the real data. If the
 * datastructure needs to outlast the protocol data or needs a different
 * memory allocation strategy, you need to call this function.  */

/* Called by: */
void zx_DUP_STRS_ac_PrincipalAuthenticationMechanism(struct zx_ctx* c, struct zx_ac_PrincipalAuthenticationMechanism_s* x)
{
  zx_dup_strs_common(c, &x->gg);
  /* *** deal with xmlns specifications in exc c14n way */


  {
      struct zx_ac_Password_s* e;
      for (e = x->Password; e; e = (struct zx_ac_Password_s*)e->gg.g.n)
	  zx_DUP_STRS_ac_Password(c, e);
  }
  {
      struct zx_ac_Token_s* e;
      for (e = x->Token; e; e = (struct zx_ac_Token_s*)e->gg.g.n)
	  zx_DUP_STRS_ac_Token(c, e);
  }
  {
      struct zx_ac_Smartcard_s* e;
      for (e = x->Smartcard; e; e = (struct zx_ac_Smartcard_s*)e->gg.g.n)
	  zx_DUP_STRS_ac_Smartcard(c, e);
  }
  {
      struct zx_ac_ActivationPin_s* e;
      for (e = x->ActivationPin; e; e = (struct zx_ac_ActivationPin_s*)e->gg.g.n)
	  zx_DUP_STRS_ac_ActivationPin(c, e);
  }
  {
      struct zx_ac_Extension_s* e;
      for (e = x->Extension; e; e = (struct zx_ac_Extension_s*)e->gg.g.n)
	  zx_DUP_STRS_ac_Extension(c, e);
  }

}

/* FUNC(zx_DEEP_CLONE_ac_PrincipalAuthenticationMechanism) */

/* Depth first traversal of data structure to clone it and its sublements.
 * The simple strings are handled as a special case according to dup_strs flag. */

/* Called by: */
struct zx_ac_PrincipalAuthenticationMechanism_s* zx_DEEP_CLONE_ac_PrincipalAuthenticationMechanism(struct zx_ctx* c, struct zx_ac_PrincipalAuthenticationMechanism_s* x, int dup_strs)
{
  x = (struct zx_ac_PrincipalAuthenticationMechanism_s*)zx_clone_elem_common(c, &x->gg, sizeof(struct zx_ac_PrincipalAuthenticationMechanism_s), dup_strs);
  /* *** deal with xmlns specifications in exc c14n way */


  {
      struct zx_ac_Password_s* e;
      struct zx_ac_Password_s* en;
      struct zx_ac_Password_s* enn;
      for (enn = 0, e = x->Password; e; e = (struct zx_ac_Password_s*)e->gg.g.n) {
	  en = zx_DEEP_CLONE_ac_Password(c, e, dup_strs);
	  if (!enn)
	      x->Password = en;
	  else
	      enn->gg.g.n = &en->gg.g;
	  enn = en;
      }
  }
  {
      struct zx_ac_Token_s* e;
      struct zx_ac_Token_s* en;
      struct zx_ac_Token_s* enn;
      for (enn = 0, e = x->Token; e; e = (struct zx_ac_Token_s*)e->gg.g.n) {
	  en = zx_DEEP_CLONE_ac_Token(c, e, dup_strs);
	  if (!enn)
	      x->Token = en;
	  else
	      enn->gg.g.n = &en->gg.g;
	  enn = en;
      }
  }
  {
      struct zx_ac_Smartcard_s* e;
      struct zx_ac_Smartcard_s* en;
      struct zx_ac_Smartcard_s* enn;
      for (enn = 0, e = x->Smartcard; e; e = (struct zx_ac_Smartcard_s*)e->gg.g.n) {
	  en = zx_DEEP_CLONE_ac_Smartcard(c, e, dup_strs);
	  if (!enn)
	      x->Smartcard = en;
	  else
	      enn->gg.g.n = &en->gg.g;
	  enn = en;
      }
  }
  {
      struct zx_ac_ActivationPin_s* e;
      struct zx_ac_ActivationPin_s* en;
      struct zx_ac_ActivationPin_s* enn;
      for (enn = 0, e = x->ActivationPin; e; e = (struct zx_ac_ActivationPin_s*)e->gg.g.n) {
	  en = zx_DEEP_CLONE_ac_ActivationPin(c, e, dup_strs);
	  if (!enn)
	      x->ActivationPin = en;
	  else
	      enn->gg.g.n = &en->gg.g;
	  enn = en;
      }
  }
  {
      struct zx_ac_Extension_s* e;
      struct zx_ac_Extension_s* en;
      struct zx_ac_Extension_s* enn;
      for (enn = 0, e = x->Extension; e; e = (struct zx_ac_Extension_s*)e->gg.g.n) {
	  en = zx_DEEP_CLONE_ac_Extension(c, e, dup_strs);
	  if (!enn)
	      x->Extension = en;
	  else
	      enn->gg.g.n = &en->gg.g;
	  enn = en;
      }
  }

  return x;
}

/* FUNC(zx_WALK_SO_ac_PrincipalAuthenticationMechanism) */

/* Depth first traversal of the tree in either schema order or the wire order. */
 
int zx_WALK_SO_ac_PrincipalAuthenticationMechanism(struct zx_ctx* c, struct zx_ac_PrincipalAuthenticationMechanism_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
{
  int ret = callback(&x->gg.g, ctx);
  if (ret)
    return ret;
  
  /* *** deal with xmlns specifications in exc c14n way */


  
  ret = zx_walk_so_unknown_attributes(c, &x->gg, ctx, callback); 
  if (ret)
    return ret;

  {
      struct zx_ac_Password_s* e;
      for (e = x->Password; e; e = (struct zx_ac_Password_s*)e->gg.g.n) {
	  ret = zx_WALK_SO_ac_Password(c, e, ctx, callback);
	  if (ret)
	      return ret;
      }
  }
  {
      struct zx_ac_Token_s* e;
      for (e = x->Token; e; e = (struct zx_ac_Token_s*)e->gg.g.n) {
	  ret = zx_WALK_SO_ac_Token(c, e, ctx, callback);
	  if (ret)
	      return ret;
      }
  }
  {
      struct zx_ac_Smartcard_s* e;
      for (e = x->Smartcard; e; e = (struct zx_ac_Smartcard_s*)e->gg.g.n) {
	  ret = zx_WALK_SO_ac_Smartcard(c, e, ctx, callback);
	  if (ret)
	      return ret;
      }
  }
  {
      struct zx_ac_ActivationPin_s* e;
      for (e = x->ActivationPin; e; e = (struct zx_ac_ActivationPin_s*)e->gg.g.n) {
	  ret = zx_WALK_SO_ac_ActivationPin(c, e, ctx, callback);
	  if (ret)
	      return ret;
      }
  }
  {
      struct zx_ac_Extension_s* e;
      for (e = x->Extension; e; e = (struct zx_ac_Extension_s*)e->gg.g.n) {
	  ret = zx_WALK_SO_ac_Extension(c, e, ctx, callback);
	  if (ret)
	      return ret;
      }
  }

  
  return zx_walk_so_unknown_elems_and_content(c, &x->gg, ctx, callback);
}

/* FUNC(zx_WALK_WO_ac_PrincipalAuthenticationMechanism) */

int zx_WALK_WO_ac_PrincipalAuthenticationMechanism(struct zx_ctx* c, struct zx_ac_PrincipalAuthenticationMechanism_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
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

#define EL_NAME   ac_PrivateKeyProtection
#define EL_STRUCT zx_ac_PrivateKeyProtection_s
#define EL_NS     ac
#define EL_TAG    PrivateKeyProtection

/* FUNC(zx_FREE_ac_PrivateKeyProtection) */

/* Depth first traversal of data structure to free it and its subelements. Simple
 * strings are handled as a special case according to the free_strs flag. This
 * is useful if the strings point to underlying data from the wire that was
 * allocated differently. */

/* Called by: */
void zx_FREE_ac_PrivateKeyProtection(struct zx_ctx* c, struct zx_ac_PrivateKeyProtection_s* x, int free_strs)
{
  /* *** deal with xmlns specifications in exc c14n way */


  {
      struct zx_ac_KeyActivation_s* e;
      struct zx_ac_KeyActivation_s* en;
      for (e = x->KeyActivation; e; e = en) {
	  en = (struct zx_ac_KeyActivation_s*)e->gg.g.n;
	  zx_FREE_ac_KeyActivation(c, e, free_strs);
      }
  }
  {
      struct zx_ac_KeyStorage_s* e;
      struct zx_ac_KeyStorage_s* en;
      for (e = x->KeyStorage; e; e = en) {
	  en = (struct zx_ac_KeyStorage_s*)e->gg.g.n;
	  zx_FREE_ac_KeyStorage(c, e, free_strs);
      }
  }
  {
      struct zx_ac_KeySharing_s* e;
      struct zx_ac_KeySharing_s* en;
      for (e = x->KeySharing; e; e = en) {
	  en = (struct zx_ac_KeySharing_s*)e->gg.g.n;
	  zx_FREE_ac_KeySharing(c, e, free_strs);
      }
  }
  {
      struct zx_ac_Extension_s* e;
      struct zx_ac_Extension_s* en;
      for (e = x->Extension; e; e = en) {
	  en = (struct zx_ac_Extension_s*)e->gg.g.n;
	  zx_FREE_ac_Extension(c, e, free_strs);
      }
  }


  zx_free_elem_common(c, &x->gg, free_strs); 
}

/* FUNC(zx_NEW_ac_PrivateKeyProtection) */

/* Trivial allocator/constructor for the datatype. */

/* Called by: */
struct zx_ac_PrivateKeyProtection_s* zx_NEW_ac_PrivateKeyProtection(struct zx_ctx* c)
{
  struct zx_ac_PrivateKeyProtection_s* x = ZX_ZALLOC(c, struct zx_ac_PrivateKeyProtection_s);
  x->gg.g.tok = zx_ac_PrivateKeyProtection_ELEM;
  return x;
}

#ifdef ZX_ENA_AUX

/* FUNC(zx_DUP_STRS_ac_PrivateKeyProtection) */

/* Depth first traversal of data structure to copy its simple strings
 * to memory allocated from the memory allocator. The decoder will
 * use the underlying wireprotocol PDU buffer for strings, i.e.
 * strings are not copied - they point to the real data. If the
 * datastructure needs to outlast the protocol data or needs a different
 * memory allocation strategy, you need to call this function.  */

/* Called by: */
void zx_DUP_STRS_ac_PrivateKeyProtection(struct zx_ctx* c, struct zx_ac_PrivateKeyProtection_s* x)
{
  zx_dup_strs_common(c, &x->gg);
  /* *** deal with xmlns specifications in exc c14n way */


  {
      struct zx_ac_KeyActivation_s* e;
      for (e = x->KeyActivation; e; e = (struct zx_ac_KeyActivation_s*)e->gg.g.n)
	  zx_DUP_STRS_ac_KeyActivation(c, e);
  }
  {
      struct zx_ac_KeyStorage_s* e;
      for (e = x->KeyStorage; e; e = (struct zx_ac_KeyStorage_s*)e->gg.g.n)
	  zx_DUP_STRS_ac_KeyStorage(c, e);
  }
  {
      struct zx_ac_KeySharing_s* e;
      for (e = x->KeySharing; e; e = (struct zx_ac_KeySharing_s*)e->gg.g.n)
	  zx_DUP_STRS_ac_KeySharing(c, e);
  }
  {
      struct zx_ac_Extension_s* e;
      for (e = x->Extension; e; e = (struct zx_ac_Extension_s*)e->gg.g.n)
	  zx_DUP_STRS_ac_Extension(c, e);
  }

}

/* FUNC(zx_DEEP_CLONE_ac_PrivateKeyProtection) */

/* Depth first traversal of data structure to clone it and its sublements.
 * The simple strings are handled as a special case according to dup_strs flag. */

/* Called by: */
struct zx_ac_PrivateKeyProtection_s* zx_DEEP_CLONE_ac_PrivateKeyProtection(struct zx_ctx* c, struct zx_ac_PrivateKeyProtection_s* x, int dup_strs)
{
  x = (struct zx_ac_PrivateKeyProtection_s*)zx_clone_elem_common(c, &x->gg, sizeof(struct zx_ac_PrivateKeyProtection_s), dup_strs);
  /* *** deal with xmlns specifications in exc c14n way */


  {
      struct zx_ac_KeyActivation_s* e;
      struct zx_ac_KeyActivation_s* en;
      struct zx_ac_KeyActivation_s* enn;
      for (enn = 0, e = x->KeyActivation; e; e = (struct zx_ac_KeyActivation_s*)e->gg.g.n) {
	  en = zx_DEEP_CLONE_ac_KeyActivation(c, e, dup_strs);
	  if (!enn)
	      x->KeyActivation = en;
	  else
	      enn->gg.g.n = &en->gg.g;
	  enn = en;
      }
  }
  {
      struct zx_ac_KeyStorage_s* e;
      struct zx_ac_KeyStorage_s* en;
      struct zx_ac_KeyStorage_s* enn;
      for (enn = 0, e = x->KeyStorage; e; e = (struct zx_ac_KeyStorage_s*)e->gg.g.n) {
	  en = zx_DEEP_CLONE_ac_KeyStorage(c, e, dup_strs);
	  if (!enn)
	      x->KeyStorage = en;
	  else
	      enn->gg.g.n = &en->gg.g;
	  enn = en;
      }
  }
  {
      struct zx_ac_KeySharing_s* e;
      struct zx_ac_KeySharing_s* en;
      struct zx_ac_KeySharing_s* enn;
      for (enn = 0, e = x->KeySharing; e; e = (struct zx_ac_KeySharing_s*)e->gg.g.n) {
	  en = zx_DEEP_CLONE_ac_KeySharing(c, e, dup_strs);
	  if (!enn)
	      x->KeySharing = en;
	  else
	      enn->gg.g.n = &en->gg.g;
	  enn = en;
      }
  }
  {
      struct zx_ac_Extension_s* e;
      struct zx_ac_Extension_s* en;
      struct zx_ac_Extension_s* enn;
      for (enn = 0, e = x->Extension; e; e = (struct zx_ac_Extension_s*)e->gg.g.n) {
	  en = zx_DEEP_CLONE_ac_Extension(c, e, dup_strs);
	  if (!enn)
	      x->Extension = en;
	  else
	      enn->gg.g.n = &en->gg.g;
	  enn = en;
      }
  }

  return x;
}

/* FUNC(zx_WALK_SO_ac_PrivateKeyProtection) */

/* Depth first traversal of the tree in either schema order or the wire order. */
 
int zx_WALK_SO_ac_PrivateKeyProtection(struct zx_ctx* c, struct zx_ac_PrivateKeyProtection_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
{
  int ret = callback(&x->gg.g, ctx);
  if (ret)
    return ret;
  
  /* *** deal with xmlns specifications in exc c14n way */


  
  ret = zx_walk_so_unknown_attributes(c, &x->gg, ctx, callback); 
  if (ret)
    return ret;

  {
      struct zx_ac_KeyActivation_s* e;
      for (e = x->KeyActivation; e; e = (struct zx_ac_KeyActivation_s*)e->gg.g.n) {
	  ret = zx_WALK_SO_ac_KeyActivation(c, e, ctx, callback);
	  if (ret)
	      return ret;
      }
  }
  {
      struct zx_ac_KeyStorage_s* e;
      for (e = x->KeyStorage; e; e = (struct zx_ac_KeyStorage_s*)e->gg.g.n) {
	  ret = zx_WALK_SO_ac_KeyStorage(c, e, ctx, callback);
	  if (ret)
	      return ret;
      }
  }
  {
      struct zx_ac_KeySharing_s* e;
      for (e = x->KeySharing; e; e = (struct zx_ac_KeySharing_s*)e->gg.g.n) {
	  ret = zx_WALK_SO_ac_KeySharing(c, e, ctx, callback);
	  if (ret)
	      return ret;
      }
  }
  {
      struct zx_ac_Extension_s* e;
      for (e = x->Extension; e; e = (struct zx_ac_Extension_s*)e->gg.g.n) {
	  ret = zx_WALK_SO_ac_Extension(c, e, ctx, callback);
	  if (ret)
	      return ret;
      }
  }

  
  return zx_walk_so_unknown_elems_and_content(c, &x->gg, ctx, callback);
}

/* FUNC(zx_WALK_WO_ac_PrivateKeyProtection) */

int zx_WALK_WO_ac_PrivateKeyProtection(struct zx_ctx* c, struct zx_ac_PrivateKeyProtection_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
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

#define EL_NAME   ac_ResumeSession
#define EL_STRUCT zx_ac_ResumeSession_s
#define EL_NS     ac
#define EL_TAG    ResumeSession

/* FUNC(zx_FREE_ac_ResumeSession) */

/* Depth first traversal of data structure to free it and its subelements. Simple
 * strings are handled as a special case according to the free_strs flag. This
 * is useful if the strings point to underlying data from the wire that was
 * allocated differently. */

/* Called by: */
void zx_FREE_ac_ResumeSession(struct zx_ctx* c, struct zx_ac_ResumeSession_s* x, int free_strs)
{
  /* *** deal with xmlns specifications in exc c14n way */


  {
      struct zx_ac_Extension_s* e;
      struct zx_ac_Extension_s* en;
      for (e = x->Extension; e; e = en) {
	  en = (struct zx_ac_Extension_s*)e->gg.g.n;
	  zx_FREE_ac_Extension(c, e, free_strs);
      }
  }


  zx_free_elem_common(c, &x->gg, free_strs); 
}

/* FUNC(zx_NEW_ac_ResumeSession) */

/* Trivial allocator/constructor for the datatype. */

/* Called by: */
struct zx_ac_ResumeSession_s* zx_NEW_ac_ResumeSession(struct zx_ctx* c)
{
  struct zx_ac_ResumeSession_s* x = ZX_ZALLOC(c, struct zx_ac_ResumeSession_s);
  x->gg.g.tok = zx_ac_ResumeSession_ELEM;
  return x;
}

#ifdef ZX_ENA_AUX

/* FUNC(zx_DUP_STRS_ac_ResumeSession) */

/* Depth first traversal of data structure to copy its simple strings
 * to memory allocated from the memory allocator. The decoder will
 * use the underlying wireprotocol PDU buffer for strings, i.e.
 * strings are not copied - they point to the real data. If the
 * datastructure needs to outlast the protocol data or needs a different
 * memory allocation strategy, you need to call this function.  */

/* Called by: */
void zx_DUP_STRS_ac_ResumeSession(struct zx_ctx* c, struct zx_ac_ResumeSession_s* x)
{
  zx_dup_strs_common(c, &x->gg);
  /* *** deal with xmlns specifications in exc c14n way */


  {
      struct zx_ac_Extension_s* e;
      for (e = x->Extension; e; e = (struct zx_ac_Extension_s*)e->gg.g.n)
	  zx_DUP_STRS_ac_Extension(c, e);
  }

}

/* FUNC(zx_DEEP_CLONE_ac_ResumeSession) */

/* Depth first traversal of data structure to clone it and its sublements.
 * The simple strings are handled as a special case according to dup_strs flag. */

/* Called by: */
struct zx_ac_ResumeSession_s* zx_DEEP_CLONE_ac_ResumeSession(struct zx_ctx* c, struct zx_ac_ResumeSession_s* x, int dup_strs)
{
  x = (struct zx_ac_ResumeSession_s*)zx_clone_elem_common(c, &x->gg, sizeof(struct zx_ac_ResumeSession_s), dup_strs);
  /* *** deal with xmlns specifications in exc c14n way */


  {
      struct zx_ac_Extension_s* e;
      struct zx_ac_Extension_s* en;
      struct zx_ac_Extension_s* enn;
      for (enn = 0, e = x->Extension; e; e = (struct zx_ac_Extension_s*)e->gg.g.n) {
	  en = zx_DEEP_CLONE_ac_Extension(c, e, dup_strs);
	  if (!enn)
	      x->Extension = en;
	  else
	      enn->gg.g.n = &en->gg.g;
	  enn = en;
      }
  }

  return x;
}

/* FUNC(zx_WALK_SO_ac_ResumeSession) */

/* Depth first traversal of the tree in either schema order or the wire order. */
 
int zx_WALK_SO_ac_ResumeSession(struct zx_ctx* c, struct zx_ac_ResumeSession_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
{
  int ret = callback(&x->gg.g, ctx);
  if (ret)
    return ret;
  
  /* *** deal with xmlns specifications in exc c14n way */


  
  ret = zx_walk_so_unknown_attributes(c, &x->gg, ctx, callback); 
  if (ret)
    return ret;

  {
      struct zx_ac_Extension_s* e;
      for (e = x->Extension; e; e = (struct zx_ac_Extension_s*)e->gg.g.n) {
	  ret = zx_WALK_SO_ac_Extension(c, e, ctx, callback);
	  if (ret)
	      return ret;
      }
  }

  
  return zx_walk_so_unknown_elems_and_content(c, &x->gg, ctx, callback);
}

/* FUNC(zx_WALK_WO_ac_ResumeSession) */

int zx_WALK_WO_ac_ResumeSession(struct zx_ctx* c, struct zx_ac_ResumeSession_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
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

#define EL_NAME   ac_SSL
#define EL_STRUCT zx_ac_SSL_s
#define EL_NS     ac
#define EL_TAG    SSL

/* FUNC(zx_FREE_ac_SSL) */

/* Depth first traversal of data structure to free it and its subelements. Simple
 * strings are handled as a special case according to the free_strs flag. This
 * is useful if the strings point to underlying data from the wire that was
 * allocated differently. */

/* Called by: */
void zx_FREE_ac_SSL(struct zx_ctx* c, struct zx_ac_SSL_s* x, int free_strs)
{
  /* *** deal with xmlns specifications in exc c14n way */


  {
      struct zx_ac_Extension_s* e;
      struct zx_ac_Extension_s* en;
      for (e = x->Extension; e; e = en) {
	  en = (struct zx_ac_Extension_s*)e->gg.g.n;
	  zx_FREE_ac_Extension(c, e, free_strs);
      }
  }


  zx_free_elem_common(c, &x->gg, free_strs); 
}

/* FUNC(zx_NEW_ac_SSL) */

/* Trivial allocator/constructor for the datatype. */

/* Called by: */
struct zx_ac_SSL_s* zx_NEW_ac_SSL(struct zx_ctx* c)
{
  struct zx_ac_SSL_s* x = ZX_ZALLOC(c, struct zx_ac_SSL_s);
  x->gg.g.tok = zx_ac_SSL_ELEM;
  return x;
}

#ifdef ZX_ENA_AUX

/* FUNC(zx_DUP_STRS_ac_SSL) */

/* Depth first traversal of data structure to copy its simple strings
 * to memory allocated from the memory allocator. The decoder will
 * use the underlying wireprotocol PDU buffer for strings, i.e.
 * strings are not copied - they point to the real data. If the
 * datastructure needs to outlast the protocol data or needs a different
 * memory allocation strategy, you need to call this function.  */

/* Called by: */
void zx_DUP_STRS_ac_SSL(struct zx_ctx* c, struct zx_ac_SSL_s* x)
{
  zx_dup_strs_common(c, &x->gg);
  /* *** deal with xmlns specifications in exc c14n way */


  {
      struct zx_ac_Extension_s* e;
      for (e = x->Extension; e; e = (struct zx_ac_Extension_s*)e->gg.g.n)
	  zx_DUP_STRS_ac_Extension(c, e);
  }

}

/* FUNC(zx_DEEP_CLONE_ac_SSL) */

/* Depth first traversal of data structure to clone it and its sublements.
 * The simple strings are handled as a special case according to dup_strs flag. */

/* Called by: */
struct zx_ac_SSL_s* zx_DEEP_CLONE_ac_SSL(struct zx_ctx* c, struct zx_ac_SSL_s* x, int dup_strs)
{
  x = (struct zx_ac_SSL_s*)zx_clone_elem_common(c, &x->gg, sizeof(struct zx_ac_SSL_s), dup_strs);
  /* *** deal with xmlns specifications in exc c14n way */


  {
      struct zx_ac_Extension_s* e;
      struct zx_ac_Extension_s* en;
      struct zx_ac_Extension_s* enn;
      for (enn = 0, e = x->Extension; e; e = (struct zx_ac_Extension_s*)e->gg.g.n) {
	  en = zx_DEEP_CLONE_ac_Extension(c, e, dup_strs);
	  if (!enn)
	      x->Extension = en;
	  else
	      enn->gg.g.n = &en->gg.g;
	  enn = en;
      }
  }

  return x;
}

/* FUNC(zx_WALK_SO_ac_SSL) */

/* Depth first traversal of the tree in either schema order or the wire order. */
 
int zx_WALK_SO_ac_SSL(struct zx_ctx* c, struct zx_ac_SSL_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
{
  int ret = callback(&x->gg.g, ctx);
  if (ret)
    return ret;
  
  /* *** deal with xmlns specifications in exc c14n way */


  
  ret = zx_walk_so_unknown_attributes(c, &x->gg, ctx, callback); 
  if (ret)
    return ret;

  {
      struct zx_ac_Extension_s* e;
      for (e = x->Extension; e; e = (struct zx_ac_Extension_s*)e->gg.g.n) {
	  ret = zx_WALK_SO_ac_Extension(c, e, ctx, callback);
	  if (ret)
	      return ret;
      }
  }

  
  return zx_walk_so_unknown_elems_and_content(c, &x->gg, ctx, callback);
}

/* FUNC(zx_WALK_WO_ac_SSL) */

int zx_WALK_WO_ac_SSL(struct zx_ctx* c, struct zx_ac_SSL_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
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

#define EL_NAME   ac_SecretKeyProtection
#define EL_STRUCT zx_ac_SecretKeyProtection_s
#define EL_NS     ac
#define EL_TAG    SecretKeyProtection

/* FUNC(zx_FREE_ac_SecretKeyProtection) */

/* Depth first traversal of data structure to free it and its subelements. Simple
 * strings are handled as a special case according to the free_strs flag. This
 * is useful if the strings point to underlying data from the wire that was
 * allocated differently. */

/* Called by: */
void zx_FREE_ac_SecretKeyProtection(struct zx_ctx* c, struct zx_ac_SecretKeyProtection_s* x, int free_strs)
{
  /* *** deal with xmlns specifications in exc c14n way */


  {
      struct zx_ac_KeyActivation_s* e;
      struct zx_ac_KeyActivation_s* en;
      for (e = x->KeyActivation; e; e = en) {
	  en = (struct zx_ac_KeyActivation_s*)e->gg.g.n;
	  zx_FREE_ac_KeyActivation(c, e, free_strs);
      }
  }
  {
      struct zx_ac_KeyStorage_s* e;
      struct zx_ac_KeyStorage_s* en;
      for (e = x->KeyStorage; e; e = en) {
	  en = (struct zx_ac_KeyStorage_s*)e->gg.g.n;
	  zx_FREE_ac_KeyStorage(c, e, free_strs);
      }
  }
  {
      struct zx_ac_Extension_s* e;
      struct zx_ac_Extension_s* en;
      for (e = x->Extension; e; e = en) {
	  en = (struct zx_ac_Extension_s*)e->gg.g.n;
	  zx_FREE_ac_Extension(c, e, free_strs);
      }
  }


  zx_free_elem_common(c, &x->gg, free_strs); 
}

/* FUNC(zx_NEW_ac_SecretKeyProtection) */

/* Trivial allocator/constructor for the datatype. */

/* Called by: */
struct zx_ac_SecretKeyProtection_s* zx_NEW_ac_SecretKeyProtection(struct zx_ctx* c)
{
  struct zx_ac_SecretKeyProtection_s* x = ZX_ZALLOC(c, struct zx_ac_SecretKeyProtection_s);
  x->gg.g.tok = zx_ac_SecretKeyProtection_ELEM;
  return x;
}

#ifdef ZX_ENA_AUX

/* FUNC(zx_DUP_STRS_ac_SecretKeyProtection) */

/* Depth first traversal of data structure to copy its simple strings
 * to memory allocated from the memory allocator. The decoder will
 * use the underlying wireprotocol PDU buffer for strings, i.e.
 * strings are not copied - they point to the real data. If the
 * datastructure needs to outlast the protocol data or needs a different
 * memory allocation strategy, you need to call this function.  */

/* Called by: */
void zx_DUP_STRS_ac_SecretKeyProtection(struct zx_ctx* c, struct zx_ac_SecretKeyProtection_s* x)
{
  zx_dup_strs_common(c, &x->gg);
  /* *** deal with xmlns specifications in exc c14n way */


  {
      struct zx_ac_KeyActivation_s* e;
      for (e = x->KeyActivation; e; e = (struct zx_ac_KeyActivation_s*)e->gg.g.n)
	  zx_DUP_STRS_ac_KeyActivation(c, e);
  }
  {
      struct zx_ac_KeyStorage_s* e;
      for (e = x->KeyStorage; e; e = (struct zx_ac_KeyStorage_s*)e->gg.g.n)
	  zx_DUP_STRS_ac_KeyStorage(c, e);
  }
  {
      struct zx_ac_Extension_s* e;
      for (e = x->Extension; e; e = (struct zx_ac_Extension_s*)e->gg.g.n)
	  zx_DUP_STRS_ac_Extension(c, e);
  }

}

/* FUNC(zx_DEEP_CLONE_ac_SecretKeyProtection) */

/* Depth first traversal of data structure to clone it and its sublements.
 * The simple strings are handled as a special case according to dup_strs flag. */

/* Called by: */
struct zx_ac_SecretKeyProtection_s* zx_DEEP_CLONE_ac_SecretKeyProtection(struct zx_ctx* c, struct zx_ac_SecretKeyProtection_s* x, int dup_strs)
{
  x = (struct zx_ac_SecretKeyProtection_s*)zx_clone_elem_common(c, &x->gg, sizeof(struct zx_ac_SecretKeyProtection_s), dup_strs);
  /* *** deal with xmlns specifications in exc c14n way */


  {
      struct zx_ac_KeyActivation_s* e;
      struct zx_ac_KeyActivation_s* en;
      struct zx_ac_KeyActivation_s* enn;
      for (enn = 0, e = x->KeyActivation; e; e = (struct zx_ac_KeyActivation_s*)e->gg.g.n) {
	  en = zx_DEEP_CLONE_ac_KeyActivation(c, e, dup_strs);
	  if (!enn)
	      x->KeyActivation = en;
	  else
	      enn->gg.g.n = &en->gg.g;
	  enn = en;
      }
  }
  {
      struct zx_ac_KeyStorage_s* e;
      struct zx_ac_KeyStorage_s* en;
      struct zx_ac_KeyStorage_s* enn;
      for (enn = 0, e = x->KeyStorage; e; e = (struct zx_ac_KeyStorage_s*)e->gg.g.n) {
	  en = zx_DEEP_CLONE_ac_KeyStorage(c, e, dup_strs);
	  if (!enn)
	      x->KeyStorage = en;
	  else
	      enn->gg.g.n = &en->gg.g;
	  enn = en;
      }
  }
  {
      struct zx_ac_Extension_s* e;
      struct zx_ac_Extension_s* en;
      struct zx_ac_Extension_s* enn;
      for (enn = 0, e = x->Extension; e; e = (struct zx_ac_Extension_s*)e->gg.g.n) {
	  en = zx_DEEP_CLONE_ac_Extension(c, e, dup_strs);
	  if (!enn)
	      x->Extension = en;
	  else
	      enn->gg.g.n = &en->gg.g;
	  enn = en;
      }
  }

  return x;
}

/* FUNC(zx_WALK_SO_ac_SecretKeyProtection) */

/* Depth first traversal of the tree in either schema order or the wire order. */
 
int zx_WALK_SO_ac_SecretKeyProtection(struct zx_ctx* c, struct zx_ac_SecretKeyProtection_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
{
  int ret = callback(&x->gg.g, ctx);
  if (ret)
    return ret;
  
  /* *** deal with xmlns specifications in exc c14n way */


  
  ret = zx_walk_so_unknown_attributes(c, &x->gg, ctx, callback); 
  if (ret)
    return ret;

  {
      struct zx_ac_KeyActivation_s* e;
      for (e = x->KeyActivation; e; e = (struct zx_ac_KeyActivation_s*)e->gg.g.n) {
	  ret = zx_WALK_SO_ac_KeyActivation(c, e, ctx, callback);
	  if (ret)
	      return ret;
      }
  }
  {
      struct zx_ac_KeyStorage_s* e;
      for (e = x->KeyStorage; e; e = (struct zx_ac_KeyStorage_s*)e->gg.g.n) {
	  ret = zx_WALK_SO_ac_KeyStorage(c, e, ctx, callback);
	  if (ret)
	      return ret;
      }
  }
  {
      struct zx_ac_Extension_s* e;
      for (e = x->Extension; e; e = (struct zx_ac_Extension_s*)e->gg.g.n) {
	  ret = zx_WALK_SO_ac_Extension(c, e, ctx, callback);
	  if (ret)
	      return ret;
      }
  }

  
  return zx_walk_so_unknown_elems_and_content(c, &x->gg, ctx, callback);
}

/* FUNC(zx_WALK_WO_ac_SecretKeyProtection) */

int zx_WALK_WO_ac_SecretKeyProtection(struct zx_ctx* c, struct zx_ac_SecretKeyProtection_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
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

#define EL_NAME   ac_SecurityAudit
#define EL_STRUCT zx_ac_SecurityAudit_s
#define EL_NS     ac
#define EL_TAG    SecurityAudit

/* FUNC(zx_FREE_ac_SecurityAudit) */

/* Depth first traversal of data structure to free it and its subelements. Simple
 * strings are handled as a special case according to the free_strs flag. This
 * is useful if the strings point to underlying data from the wire that was
 * allocated differently. */

/* Called by: */
void zx_FREE_ac_SecurityAudit(struct zx_ctx* c, struct zx_ac_SecurityAudit_s* x, int free_strs)
{
  /* *** deal with xmlns specifications in exc c14n way */


  {
      struct zx_ac_SwitchAudit_s* e;
      struct zx_ac_SwitchAudit_s* en;
      for (e = x->SwitchAudit; e; e = en) {
	  en = (struct zx_ac_SwitchAudit_s*)e->gg.g.n;
	  zx_FREE_ac_SwitchAudit(c, e, free_strs);
      }
  }
  {
      struct zx_ac_Extension_s* e;
      struct zx_ac_Extension_s* en;
      for (e = x->Extension; e; e = en) {
	  en = (struct zx_ac_Extension_s*)e->gg.g.n;
	  zx_FREE_ac_Extension(c, e, free_strs);
      }
  }


  zx_free_elem_common(c, &x->gg, free_strs); 
}

/* FUNC(zx_NEW_ac_SecurityAudit) */

/* Trivial allocator/constructor for the datatype. */

/* Called by: */
struct zx_ac_SecurityAudit_s* zx_NEW_ac_SecurityAudit(struct zx_ctx* c)
{
  struct zx_ac_SecurityAudit_s* x = ZX_ZALLOC(c, struct zx_ac_SecurityAudit_s);
  x->gg.g.tok = zx_ac_SecurityAudit_ELEM;
  return x;
}

#ifdef ZX_ENA_AUX

/* FUNC(zx_DUP_STRS_ac_SecurityAudit) */

/* Depth first traversal of data structure to copy its simple strings
 * to memory allocated from the memory allocator. The decoder will
 * use the underlying wireprotocol PDU buffer for strings, i.e.
 * strings are not copied - they point to the real data. If the
 * datastructure needs to outlast the protocol data or needs a different
 * memory allocation strategy, you need to call this function.  */

/* Called by: */
void zx_DUP_STRS_ac_SecurityAudit(struct zx_ctx* c, struct zx_ac_SecurityAudit_s* x)
{
  zx_dup_strs_common(c, &x->gg);
  /* *** deal with xmlns specifications in exc c14n way */


  {
      struct zx_ac_SwitchAudit_s* e;
      for (e = x->SwitchAudit; e; e = (struct zx_ac_SwitchAudit_s*)e->gg.g.n)
	  zx_DUP_STRS_ac_SwitchAudit(c, e);
  }
  {
      struct zx_ac_Extension_s* e;
      for (e = x->Extension; e; e = (struct zx_ac_Extension_s*)e->gg.g.n)
	  zx_DUP_STRS_ac_Extension(c, e);
  }

}

/* FUNC(zx_DEEP_CLONE_ac_SecurityAudit) */

/* Depth first traversal of data structure to clone it and its sublements.
 * The simple strings are handled as a special case according to dup_strs flag. */

/* Called by: */
struct zx_ac_SecurityAudit_s* zx_DEEP_CLONE_ac_SecurityAudit(struct zx_ctx* c, struct zx_ac_SecurityAudit_s* x, int dup_strs)
{
  x = (struct zx_ac_SecurityAudit_s*)zx_clone_elem_common(c, &x->gg, sizeof(struct zx_ac_SecurityAudit_s), dup_strs);
  /* *** deal with xmlns specifications in exc c14n way */


  {
      struct zx_ac_SwitchAudit_s* e;
      struct zx_ac_SwitchAudit_s* en;
      struct zx_ac_SwitchAudit_s* enn;
      for (enn = 0, e = x->SwitchAudit; e; e = (struct zx_ac_SwitchAudit_s*)e->gg.g.n) {
	  en = zx_DEEP_CLONE_ac_SwitchAudit(c, e, dup_strs);
	  if (!enn)
	      x->SwitchAudit = en;
	  else
	      enn->gg.g.n = &en->gg.g;
	  enn = en;
      }
  }
  {
      struct zx_ac_Extension_s* e;
      struct zx_ac_Extension_s* en;
      struct zx_ac_Extension_s* enn;
      for (enn = 0, e = x->Extension; e; e = (struct zx_ac_Extension_s*)e->gg.g.n) {
	  en = zx_DEEP_CLONE_ac_Extension(c, e, dup_strs);
	  if (!enn)
	      x->Extension = en;
	  else
	      enn->gg.g.n = &en->gg.g;
	  enn = en;
      }
  }

  return x;
}

/* FUNC(zx_WALK_SO_ac_SecurityAudit) */

/* Depth first traversal of the tree in either schema order or the wire order. */
 
int zx_WALK_SO_ac_SecurityAudit(struct zx_ctx* c, struct zx_ac_SecurityAudit_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
{
  int ret = callback(&x->gg.g, ctx);
  if (ret)
    return ret;
  
  /* *** deal with xmlns specifications in exc c14n way */


  
  ret = zx_walk_so_unknown_attributes(c, &x->gg, ctx, callback); 
  if (ret)
    return ret;

  {
      struct zx_ac_SwitchAudit_s* e;
      for (e = x->SwitchAudit; e; e = (struct zx_ac_SwitchAudit_s*)e->gg.g.n) {
	  ret = zx_WALK_SO_ac_SwitchAudit(c, e, ctx, callback);
	  if (ret)
	      return ret;
      }
  }
  {
      struct zx_ac_Extension_s* e;
      for (e = x->Extension; e; e = (struct zx_ac_Extension_s*)e->gg.g.n) {
	  ret = zx_WALK_SO_ac_Extension(c, e, ctx, callback);
	  if (ret)
	      return ret;
      }
  }

  
  return zx_walk_so_unknown_elems_and_content(c, &x->gg, ctx, callback);
}

/* FUNC(zx_WALK_WO_ac_SecurityAudit) */

int zx_WALK_WO_ac_SecurityAudit(struct zx_ctx* c, struct zx_ac_SecurityAudit_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
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

#define EL_NAME   ac_SharedSecretChallengeResponse
#define EL_STRUCT zx_ac_SharedSecretChallengeResponse_s
#define EL_NS     ac
#define EL_TAG    SharedSecretChallengeResponse

/* FUNC(zx_FREE_ac_SharedSecretChallengeResponse) */

/* Depth first traversal of data structure to free it and its subelements. Simple
 * strings are handled as a special case according to the free_strs flag. This
 * is useful if the strings point to underlying data from the wire that was
 * allocated differently. */

/* Called by: */
void zx_FREE_ac_SharedSecretChallengeResponse(struct zx_ctx* c, struct zx_ac_SharedSecretChallengeResponse_s* x, int free_strs)
{
  /* *** deal with xmlns specifications in exc c14n way */


  {
      struct zx_ac_Extension_s* e;
      struct zx_ac_Extension_s* en;
      for (e = x->Extension; e; e = en) {
	  en = (struct zx_ac_Extension_s*)e->gg.g.n;
	  zx_FREE_ac_Extension(c, e, free_strs);
      }
  }


  zx_free_elem_common(c, &x->gg, free_strs); 
}

/* FUNC(zx_NEW_ac_SharedSecretChallengeResponse) */

/* Trivial allocator/constructor for the datatype. */

/* Called by: */
struct zx_ac_SharedSecretChallengeResponse_s* zx_NEW_ac_SharedSecretChallengeResponse(struct zx_ctx* c)
{
  struct zx_ac_SharedSecretChallengeResponse_s* x = ZX_ZALLOC(c, struct zx_ac_SharedSecretChallengeResponse_s);
  x->gg.g.tok = zx_ac_SharedSecretChallengeResponse_ELEM;
  return x;
}

#ifdef ZX_ENA_AUX

/* FUNC(zx_DUP_STRS_ac_SharedSecretChallengeResponse) */

/* Depth first traversal of data structure to copy its simple strings
 * to memory allocated from the memory allocator. The decoder will
 * use the underlying wireprotocol PDU buffer for strings, i.e.
 * strings are not copied - they point to the real data. If the
 * datastructure needs to outlast the protocol data or needs a different
 * memory allocation strategy, you need to call this function.  */

/* Called by: */
void zx_DUP_STRS_ac_SharedSecretChallengeResponse(struct zx_ctx* c, struct zx_ac_SharedSecretChallengeResponse_s* x)
{
  zx_dup_strs_common(c, &x->gg);
  /* *** deal with xmlns specifications in exc c14n way */


  {
      struct zx_ac_Extension_s* e;
      for (e = x->Extension; e; e = (struct zx_ac_Extension_s*)e->gg.g.n)
	  zx_DUP_STRS_ac_Extension(c, e);
  }

}

/* FUNC(zx_DEEP_CLONE_ac_SharedSecretChallengeResponse) */

/* Depth first traversal of data structure to clone it and its sublements.
 * The simple strings are handled as a special case according to dup_strs flag. */

/* Called by: */
struct zx_ac_SharedSecretChallengeResponse_s* zx_DEEP_CLONE_ac_SharedSecretChallengeResponse(struct zx_ctx* c, struct zx_ac_SharedSecretChallengeResponse_s* x, int dup_strs)
{
  x = (struct zx_ac_SharedSecretChallengeResponse_s*)zx_clone_elem_common(c, &x->gg, sizeof(struct zx_ac_SharedSecretChallengeResponse_s), dup_strs);
  /* *** deal with xmlns specifications in exc c14n way */


  {
      struct zx_ac_Extension_s* e;
      struct zx_ac_Extension_s* en;
      struct zx_ac_Extension_s* enn;
      for (enn = 0, e = x->Extension; e; e = (struct zx_ac_Extension_s*)e->gg.g.n) {
	  en = zx_DEEP_CLONE_ac_Extension(c, e, dup_strs);
	  if (!enn)
	      x->Extension = en;
	  else
	      enn->gg.g.n = &en->gg.g;
	  enn = en;
      }
  }

  return x;
}

/* FUNC(zx_WALK_SO_ac_SharedSecretChallengeResponse) */

/* Depth first traversal of the tree in either schema order or the wire order. */
 
int zx_WALK_SO_ac_SharedSecretChallengeResponse(struct zx_ctx* c, struct zx_ac_SharedSecretChallengeResponse_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
{
  int ret = callback(&x->gg.g, ctx);
  if (ret)
    return ret;
  
  /* *** deal with xmlns specifications in exc c14n way */


  
  ret = zx_walk_so_unknown_attributes(c, &x->gg, ctx, callback); 
  if (ret)
    return ret;

  {
      struct zx_ac_Extension_s* e;
      for (e = x->Extension; e; e = (struct zx_ac_Extension_s*)e->gg.g.n) {
	  ret = zx_WALK_SO_ac_Extension(c, e, ctx, callback);
	  if (ret)
	      return ret;
      }
  }

  
  return zx_walk_so_unknown_elems_and_content(c, &x->gg, ctx, callback);
}

/* FUNC(zx_WALK_WO_ac_SharedSecretChallengeResponse) */

int zx_WALK_WO_ac_SharedSecretChallengeResponse(struct zx_ctx* c, struct zx_ac_SharedSecretChallengeResponse_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
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

#define EL_NAME   ac_SharedSecretDynamicPlaintext
#define EL_STRUCT zx_ac_SharedSecretDynamicPlaintext_s
#define EL_NS     ac
#define EL_TAG    SharedSecretDynamicPlaintext

/* FUNC(zx_FREE_ac_SharedSecretDynamicPlaintext) */

/* Depth first traversal of data structure to free it and its subelements. Simple
 * strings are handled as a special case according to the free_strs flag. This
 * is useful if the strings point to underlying data from the wire that was
 * allocated differently. */

/* Called by: */
void zx_FREE_ac_SharedSecretDynamicPlaintext(struct zx_ctx* c, struct zx_ac_SharedSecretDynamicPlaintext_s* x, int free_strs)
{
  /* *** deal with xmlns specifications in exc c14n way */


  {
      struct zx_ac_Extension_s* e;
      struct zx_ac_Extension_s* en;
      for (e = x->Extension; e; e = en) {
	  en = (struct zx_ac_Extension_s*)e->gg.g.n;
	  zx_FREE_ac_Extension(c, e, free_strs);
      }
  }


  zx_free_elem_common(c, &x->gg, free_strs); 
}

/* FUNC(zx_NEW_ac_SharedSecretDynamicPlaintext) */

/* Trivial allocator/constructor for the datatype. */

/* Called by: */
struct zx_ac_SharedSecretDynamicPlaintext_s* zx_NEW_ac_SharedSecretDynamicPlaintext(struct zx_ctx* c)
{
  struct zx_ac_SharedSecretDynamicPlaintext_s* x = ZX_ZALLOC(c, struct zx_ac_SharedSecretDynamicPlaintext_s);
  x->gg.g.tok = zx_ac_SharedSecretDynamicPlaintext_ELEM;
  return x;
}

#ifdef ZX_ENA_AUX

/* FUNC(zx_DUP_STRS_ac_SharedSecretDynamicPlaintext) */

/* Depth first traversal of data structure to copy its simple strings
 * to memory allocated from the memory allocator. The decoder will
 * use the underlying wireprotocol PDU buffer for strings, i.e.
 * strings are not copied - they point to the real data. If the
 * datastructure needs to outlast the protocol data or needs a different
 * memory allocation strategy, you need to call this function.  */

/* Called by: */
void zx_DUP_STRS_ac_SharedSecretDynamicPlaintext(struct zx_ctx* c, struct zx_ac_SharedSecretDynamicPlaintext_s* x)
{
  zx_dup_strs_common(c, &x->gg);
  /* *** deal with xmlns specifications in exc c14n way */


  {
      struct zx_ac_Extension_s* e;
      for (e = x->Extension; e; e = (struct zx_ac_Extension_s*)e->gg.g.n)
	  zx_DUP_STRS_ac_Extension(c, e);
  }

}

/* FUNC(zx_DEEP_CLONE_ac_SharedSecretDynamicPlaintext) */

/* Depth first traversal of data structure to clone it and its sublements.
 * The simple strings are handled as a special case according to dup_strs flag. */

/* Called by: */
struct zx_ac_SharedSecretDynamicPlaintext_s* zx_DEEP_CLONE_ac_SharedSecretDynamicPlaintext(struct zx_ctx* c, struct zx_ac_SharedSecretDynamicPlaintext_s* x, int dup_strs)
{
  x = (struct zx_ac_SharedSecretDynamicPlaintext_s*)zx_clone_elem_common(c, &x->gg, sizeof(struct zx_ac_SharedSecretDynamicPlaintext_s), dup_strs);
  /* *** deal with xmlns specifications in exc c14n way */


  {
      struct zx_ac_Extension_s* e;
      struct zx_ac_Extension_s* en;
      struct zx_ac_Extension_s* enn;
      for (enn = 0, e = x->Extension; e; e = (struct zx_ac_Extension_s*)e->gg.g.n) {
	  en = zx_DEEP_CLONE_ac_Extension(c, e, dup_strs);
	  if (!enn)
	      x->Extension = en;
	  else
	      enn->gg.g.n = &en->gg.g;
	  enn = en;
      }
  }

  return x;
}

/* FUNC(zx_WALK_SO_ac_SharedSecretDynamicPlaintext) */

/* Depth first traversal of the tree in either schema order or the wire order. */
 
int zx_WALK_SO_ac_SharedSecretDynamicPlaintext(struct zx_ctx* c, struct zx_ac_SharedSecretDynamicPlaintext_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
{
  int ret = callback(&x->gg.g, ctx);
  if (ret)
    return ret;
  
  /* *** deal with xmlns specifications in exc c14n way */


  
  ret = zx_walk_so_unknown_attributes(c, &x->gg, ctx, callback); 
  if (ret)
    return ret;

  {
      struct zx_ac_Extension_s* e;
      for (e = x->Extension; e; e = (struct zx_ac_Extension_s*)e->gg.g.n) {
	  ret = zx_WALK_SO_ac_Extension(c, e, ctx, callback);
	  if (ret)
	      return ret;
      }
  }

  
  return zx_walk_so_unknown_elems_and_content(c, &x->gg, ctx, callback);
}

/* FUNC(zx_WALK_WO_ac_SharedSecretDynamicPlaintext) */

int zx_WALK_WO_ac_SharedSecretDynamicPlaintext(struct zx_ctx* c, struct zx_ac_SharedSecretDynamicPlaintext_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
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

#define EL_NAME   ac_Smartcard
#define EL_STRUCT zx_ac_Smartcard_s
#define EL_NS     ac
#define EL_TAG    Smartcard

/* FUNC(zx_FREE_ac_Smartcard) */

/* Depth first traversal of data structure to free it and its subelements. Simple
 * strings are handled as a special case according to the free_strs flag. This
 * is useful if the strings point to underlying data from the wire that was
 * allocated differently. */

/* Called by: */
void zx_FREE_ac_Smartcard(struct zx_ctx* c, struct zx_ac_Smartcard_s* x, int free_strs)
{
  /* *** deal with xmlns specifications in exc c14n way */


  {
      struct zx_ac_Extension_s* e;
      struct zx_ac_Extension_s* en;
      for (e = x->Extension; e; e = en) {
	  en = (struct zx_ac_Extension_s*)e->gg.g.n;
	  zx_FREE_ac_Extension(c, e, free_strs);
      }
  }


  zx_free_elem_common(c, &x->gg, free_strs); 
}

/* FUNC(zx_NEW_ac_Smartcard) */

/* Trivial allocator/constructor for the datatype. */

/* Called by: */
struct zx_ac_Smartcard_s* zx_NEW_ac_Smartcard(struct zx_ctx* c)
{
  struct zx_ac_Smartcard_s* x = ZX_ZALLOC(c, struct zx_ac_Smartcard_s);
  x->gg.g.tok = zx_ac_Smartcard_ELEM;
  return x;
}

#ifdef ZX_ENA_AUX

/* FUNC(zx_DUP_STRS_ac_Smartcard) */

/* Depth first traversal of data structure to copy its simple strings
 * to memory allocated from the memory allocator. The decoder will
 * use the underlying wireprotocol PDU buffer for strings, i.e.
 * strings are not copied - they point to the real data. If the
 * datastructure needs to outlast the protocol data or needs a different
 * memory allocation strategy, you need to call this function.  */

/* Called by: */
void zx_DUP_STRS_ac_Smartcard(struct zx_ctx* c, struct zx_ac_Smartcard_s* x)
{
  zx_dup_strs_common(c, &x->gg);
  /* *** deal with xmlns specifications in exc c14n way */


  {
      struct zx_ac_Extension_s* e;
      for (e = x->Extension; e; e = (struct zx_ac_Extension_s*)e->gg.g.n)
	  zx_DUP_STRS_ac_Extension(c, e);
  }

}

/* FUNC(zx_DEEP_CLONE_ac_Smartcard) */

/* Depth first traversal of data structure to clone it and its sublements.
 * The simple strings are handled as a special case according to dup_strs flag. */

/* Called by: */
struct zx_ac_Smartcard_s* zx_DEEP_CLONE_ac_Smartcard(struct zx_ctx* c, struct zx_ac_Smartcard_s* x, int dup_strs)
{
  x = (struct zx_ac_Smartcard_s*)zx_clone_elem_common(c, &x->gg, sizeof(struct zx_ac_Smartcard_s), dup_strs);
  /* *** deal with xmlns specifications in exc c14n way */


  {
      struct zx_ac_Extension_s* e;
      struct zx_ac_Extension_s* en;
      struct zx_ac_Extension_s* enn;
      for (enn = 0, e = x->Extension; e; e = (struct zx_ac_Extension_s*)e->gg.g.n) {
	  en = zx_DEEP_CLONE_ac_Extension(c, e, dup_strs);
	  if (!enn)
	      x->Extension = en;
	  else
	      enn->gg.g.n = &en->gg.g;
	  enn = en;
      }
  }

  return x;
}

/* FUNC(zx_WALK_SO_ac_Smartcard) */

/* Depth first traversal of the tree in either schema order or the wire order. */
 
int zx_WALK_SO_ac_Smartcard(struct zx_ctx* c, struct zx_ac_Smartcard_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
{
  int ret = callback(&x->gg.g, ctx);
  if (ret)
    return ret;
  
  /* *** deal with xmlns specifications in exc c14n way */


  
  ret = zx_walk_so_unknown_attributes(c, &x->gg, ctx, callback); 
  if (ret)
    return ret;

  {
      struct zx_ac_Extension_s* e;
      for (e = x->Extension; e; e = (struct zx_ac_Extension_s*)e->gg.g.n) {
	  ret = zx_WALK_SO_ac_Extension(c, e, ctx, callback);
	  if (ret)
	      return ret;
      }
  }

  
  return zx_walk_so_unknown_elems_and_content(c, &x->gg, ctx, callback);
}

/* FUNC(zx_WALK_WO_ac_Smartcard) */

int zx_WALK_WO_ac_Smartcard(struct zx_ctx* c, struct zx_ac_Smartcard_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
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

#define EL_NAME   ac_SwitchAudit
#define EL_STRUCT zx_ac_SwitchAudit_s
#define EL_NS     ac
#define EL_TAG    SwitchAudit

/* FUNC(zx_FREE_ac_SwitchAudit) */

/* Depth first traversal of data structure to free it and its subelements. Simple
 * strings are handled as a special case according to the free_strs flag. This
 * is useful if the strings point to underlying data from the wire that was
 * allocated differently. */

/* Called by: */
void zx_FREE_ac_SwitchAudit(struct zx_ctx* c, struct zx_ac_SwitchAudit_s* x, int free_strs)
{
  /* *** deal with xmlns specifications in exc c14n way */


  {
      struct zx_ac_Extension_s* e;
      struct zx_ac_Extension_s* en;
      for (e = x->Extension; e; e = en) {
	  en = (struct zx_ac_Extension_s*)e->gg.g.n;
	  zx_FREE_ac_Extension(c, e, free_strs);
      }
  }


  zx_free_elem_common(c, &x->gg, free_strs); 
}

/* FUNC(zx_NEW_ac_SwitchAudit) */

/* Trivial allocator/constructor for the datatype. */

/* Called by: */
struct zx_ac_SwitchAudit_s* zx_NEW_ac_SwitchAudit(struct zx_ctx* c)
{
  struct zx_ac_SwitchAudit_s* x = ZX_ZALLOC(c, struct zx_ac_SwitchAudit_s);
  x->gg.g.tok = zx_ac_SwitchAudit_ELEM;
  return x;
}

#ifdef ZX_ENA_AUX

/* FUNC(zx_DUP_STRS_ac_SwitchAudit) */

/* Depth first traversal of data structure to copy its simple strings
 * to memory allocated from the memory allocator. The decoder will
 * use the underlying wireprotocol PDU buffer for strings, i.e.
 * strings are not copied - they point to the real data. If the
 * datastructure needs to outlast the protocol data or needs a different
 * memory allocation strategy, you need to call this function.  */

/* Called by: */
void zx_DUP_STRS_ac_SwitchAudit(struct zx_ctx* c, struct zx_ac_SwitchAudit_s* x)
{
  zx_dup_strs_common(c, &x->gg);
  /* *** deal with xmlns specifications in exc c14n way */


  {
      struct zx_ac_Extension_s* e;
      for (e = x->Extension; e; e = (struct zx_ac_Extension_s*)e->gg.g.n)
	  zx_DUP_STRS_ac_Extension(c, e);
  }

}

/* FUNC(zx_DEEP_CLONE_ac_SwitchAudit) */

/* Depth first traversal of data structure to clone it and its sublements.
 * The simple strings are handled as a special case according to dup_strs flag. */

/* Called by: */
struct zx_ac_SwitchAudit_s* zx_DEEP_CLONE_ac_SwitchAudit(struct zx_ctx* c, struct zx_ac_SwitchAudit_s* x, int dup_strs)
{
  x = (struct zx_ac_SwitchAudit_s*)zx_clone_elem_common(c, &x->gg, sizeof(struct zx_ac_SwitchAudit_s), dup_strs);
  /* *** deal with xmlns specifications in exc c14n way */


  {
      struct zx_ac_Extension_s* e;
      struct zx_ac_Extension_s* en;
      struct zx_ac_Extension_s* enn;
      for (enn = 0, e = x->Extension; e; e = (struct zx_ac_Extension_s*)e->gg.g.n) {
	  en = zx_DEEP_CLONE_ac_Extension(c, e, dup_strs);
	  if (!enn)
	      x->Extension = en;
	  else
	      enn->gg.g.n = &en->gg.g;
	  enn = en;
      }
  }

  return x;
}

/* FUNC(zx_WALK_SO_ac_SwitchAudit) */

/* Depth first traversal of the tree in either schema order or the wire order. */
 
int zx_WALK_SO_ac_SwitchAudit(struct zx_ctx* c, struct zx_ac_SwitchAudit_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
{
  int ret = callback(&x->gg.g, ctx);
  if (ret)
    return ret;
  
  /* *** deal with xmlns specifications in exc c14n way */


  
  ret = zx_walk_so_unknown_attributes(c, &x->gg, ctx, callback); 
  if (ret)
    return ret;

  {
      struct zx_ac_Extension_s* e;
      for (e = x->Extension; e; e = (struct zx_ac_Extension_s*)e->gg.g.n) {
	  ret = zx_WALK_SO_ac_Extension(c, e, ctx, callback);
	  if (ret)
	      return ret;
      }
  }

  
  return zx_walk_so_unknown_elems_and_content(c, &x->gg, ctx, callback);
}

/* FUNC(zx_WALK_WO_ac_SwitchAudit) */

int zx_WALK_WO_ac_SwitchAudit(struct zx_ctx* c, struct zx_ac_SwitchAudit_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
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

#define EL_NAME   ac_TechnicalProtection
#define EL_STRUCT zx_ac_TechnicalProtection_s
#define EL_NS     ac
#define EL_TAG    TechnicalProtection

/* FUNC(zx_FREE_ac_TechnicalProtection) */

/* Depth first traversal of data structure to free it and its subelements. Simple
 * strings are handled as a special case according to the free_strs flag. This
 * is useful if the strings point to underlying data from the wire that was
 * allocated differently. */

/* Called by: */
void zx_FREE_ac_TechnicalProtection(struct zx_ctx* c, struct zx_ac_TechnicalProtection_s* x, int free_strs)
{
  /* *** deal with xmlns specifications in exc c14n way */


  {
      struct zx_ac_PrivateKeyProtection_s* e;
      struct zx_ac_PrivateKeyProtection_s* en;
      for (e = x->PrivateKeyProtection; e; e = en) {
	  en = (struct zx_ac_PrivateKeyProtection_s*)e->gg.g.n;
	  zx_FREE_ac_PrivateKeyProtection(c, e, free_strs);
      }
  }
  {
      struct zx_ac_SecretKeyProtection_s* e;
      struct zx_ac_SecretKeyProtection_s* en;
      for (e = x->SecretKeyProtection; e; e = en) {
	  en = (struct zx_ac_SecretKeyProtection_s*)e->gg.g.n;
	  zx_FREE_ac_SecretKeyProtection(c, e, free_strs);
      }
  }
  {
      struct zx_ac_Extension_s* e;
      struct zx_ac_Extension_s* en;
      for (e = x->Extension; e; e = en) {
	  en = (struct zx_ac_Extension_s*)e->gg.g.n;
	  zx_FREE_ac_Extension(c, e, free_strs);
      }
  }


  zx_free_elem_common(c, &x->gg, free_strs); 
}

/* FUNC(zx_NEW_ac_TechnicalProtection) */

/* Trivial allocator/constructor for the datatype. */

/* Called by: */
struct zx_ac_TechnicalProtection_s* zx_NEW_ac_TechnicalProtection(struct zx_ctx* c)
{
  struct zx_ac_TechnicalProtection_s* x = ZX_ZALLOC(c, struct zx_ac_TechnicalProtection_s);
  x->gg.g.tok = zx_ac_TechnicalProtection_ELEM;
  return x;
}

#ifdef ZX_ENA_AUX

/* FUNC(zx_DUP_STRS_ac_TechnicalProtection) */

/* Depth first traversal of data structure to copy its simple strings
 * to memory allocated from the memory allocator. The decoder will
 * use the underlying wireprotocol PDU buffer for strings, i.e.
 * strings are not copied - they point to the real data. If the
 * datastructure needs to outlast the protocol data or needs a different
 * memory allocation strategy, you need to call this function.  */

/* Called by: */
void zx_DUP_STRS_ac_TechnicalProtection(struct zx_ctx* c, struct zx_ac_TechnicalProtection_s* x)
{
  zx_dup_strs_common(c, &x->gg);
  /* *** deal with xmlns specifications in exc c14n way */


  {
      struct zx_ac_PrivateKeyProtection_s* e;
      for (e = x->PrivateKeyProtection; e; e = (struct zx_ac_PrivateKeyProtection_s*)e->gg.g.n)
	  zx_DUP_STRS_ac_PrivateKeyProtection(c, e);
  }
  {
      struct zx_ac_SecretKeyProtection_s* e;
      for (e = x->SecretKeyProtection; e; e = (struct zx_ac_SecretKeyProtection_s*)e->gg.g.n)
	  zx_DUP_STRS_ac_SecretKeyProtection(c, e);
  }
  {
      struct zx_ac_Extension_s* e;
      for (e = x->Extension; e; e = (struct zx_ac_Extension_s*)e->gg.g.n)
	  zx_DUP_STRS_ac_Extension(c, e);
  }

}

/* FUNC(zx_DEEP_CLONE_ac_TechnicalProtection) */

/* Depth first traversal of data structure to clone it and its sublements.
 * The simple strings are handled as a special case according to dup_strs flag. */

/* Called by: */
struct zx_ac_TechnicalProtection_s* zx_DEEP_CLONE_ac_TechnicalProtection(struct zx_ctx* c, struct zx_ac_TechnicalProtection_s* x, int dup_strs)
{
  x = (struct zx_ac_TechnicalProtection_s*)zx_clone_elem_common(c, &x->gg, sizeof(struct zx_ac_TechnicalProtection_s), dup_strs);
  /* *** deal with xmlns specifications in exc c14n way */


  {
      struct zx_ac_PrivateKeyProtection_s* e;
      struct zx_ac_PrivateKeyProtection_s* en;
      struct zx_ac_PrivateKeyProtection_s* enn;
      for (enn = 0, e = x->PrivateKeyProtection; e; e = (struct zx_ac_PrivateKeyProtection_s*)e->gg.g.n) {
	  en = zx_DEEP_CLONE_ac_PrivateKeyProtection(c, e, dup_strs);
	  if (!enn)
	      x->PrivateKeyProtection = en;
	  else
	      enn->gg.g.n = &en->gg.g;
	  enn = en;
      }
  }
  {
      struct zx_ac_SecretKeyProtection_s* e;
      struct zx_ac_SecretKeyProtection_s* en;
      struct zx_ac_SecretKeyProtection_s* enn;
      for (enn = 0, e = x->SecretKeyProtection; e; e = (struct zx_ac_SecretKeyProtection_s*)e->gg.g.n) {
	  en = zx_DEEP_CLONE_ac_SecretKeyProtection(c, e, dup_strs);
	  if (!enn)
	      x->SecretKeyProtection = en;
	  else
	      enn->gg.g.n = &en->gg.g;
	  enn = en;
      }
  }
  {
      struct zx_ac_Extension_s* e;
      struct zx_ac_Extension_s* en;
      struct zx_ac_Extension_s* enn;
      for (enn = 0, e = x->Extension; e; e = (struct zx_ac_Extension_s*)e->gg.g.n) {
	  en = zx_DEEP_CLONE_ac_Extension(c, e, dup_strs);
	  if (!enn)
	      x->Extension = en;
	  else
	      enn->gg.g.n = &en->gg.g;
	  enn = en;
      }
  }

  return x;
}

/* FUNC(zx_WALK_SO_ac_TechnicalProtection) */

/* Depth first traversal of the tree in either schema order or the wire order. */
 
int zx_WALK_SO_ac_TechnicalProtection(struct zx_ctx* c, struct zx_ac_TechnicalProtection_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
{
  int ret = callback(&x->gg.g, ctx);
  if (ret)
    return ret;
  
  /* *** deal with xmlns specifications in exc c14n way */


  
  ret = zx_walk_so_unknown_attributes(c, &x->gg, ctx, callback); 
  if (ret)
    return ret;

  {
      struct zx_ac_PrivateKeyProtection_s* e;
      for (e = x->PrivateKeyProtection; e; e = (struct zx_ac_PrivateKeyProtection_s*)e->gg.g.n) {
	  ret = zx_WALK_SO_ac_PrivateKeyProtection(c, e, ctx, callback);
	  if (ret)
	      return ret;
      }
  }
  {
      struct zx_ac_SecretKeyProtection_s* e;
      for (e = x->SecretKeyProtection; e; e = (struct zx_ac_SecretKeyProtection_s*)e->gg.g.n) {
	  ret = zx_WALK_SO_ac_SecretKeyProtection(c, e, ctx, callback);
	  if (ret)
	      return ret;
      }
  }
  {
      struct zx_ac_Extension_s* e;
      for (e = x->Extension; e; e = (struct zx_ac_Extension_s*)e->gg.g.n) {
	  ret = zx_WALK_SO_ac_Extension(c, e, ctx, callback);
	  if (ret)
	      return ret;
      }
  }

  
  return zx_walk_so_unknown_elems_and_content(c, &x->gg, ctx, callback);
}

/* FUNC(zx_WALK_WO_ac_TechnicalProtection) */

int zx_WALK_WO_ac_TechnicalProtection(struct zx_ctx* c, struct zx_ac_TechnicalProtection_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
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

#define EL_NAME   ac_TimeSyncToken
#define EL_STRUCT zx_ac_TimeSyncToken_s
#define EL_NS     ac
#define EL_TAG    TimeSyncToken

/* FUNC(zx_FREE_ac_TimeSyncToken) */

/* Depth first traversal of data structure to free it and its subelements. Simple
 * strings are handled as a special case according to the free_strs flag. This
 * is useful if the strings point to underlying data from the wire that was
 * allocated differently. */

/* Called by: */
void zx_FREE_ac_TimeSyncToken(struct zx_ctx* c, struct zx_ac_TimeSyncToken_s* x, int free_strs)
{
  /* *** deal with xmlns specifications in exc c14n way */

  zx_free_attr(c, x->DeviceInHand, free_strs);
  zx_free_attr(c, x->DeviceType, free_strs);
  zx_free_attr(c, x->SeedLength, free_strs);



  zx_free_elem_common(c, &x->gg, free_strs); 
}

/* FUNC(zx_NEW_ac_TimeSyncToken) */

/* Trivial allocator/constructor for the datatype. */

/* Called by: */
struct zx_ac_TimeSyncToken_s* zx_NEW_ac_TimeSyncToken(struct zx_ctx* c)
{
  struct zx_ac_TimeSyncToken_s* x = ZX_ZALLOC(c, struct zx_ac_TimeSyncToken_s);
  x->gg.g.tok = zx_ac_TimeSyncToken_ELEM;
  return x;
}

#ifdef ZX_ENA_AUX

/* FUNC(zx_DUP_STRS_ac_TimeSyncToken) */

/* Depth first traversal of data structure to copy its simple strings
 * to memory allocated from the memory allocator. The decoder will
 * use the underlying wireprotocol PDU buffer for strings, i.e.
 * strings are not copied - they point to the real data. If the
 * datastructure needs to outlast the protocol data or needs a different
 * memory allocation strategy, you need to call this function.  */

/* Called by: */
void zx_DUP_STRS_ac_TimeSyncToken(struct zx_ctx* c, struct zx_ac_TimeSyncToken_s* x)
{
  zx_dup_strs_common(c, &x->gg);
  /* *** deal with xmlns specifications in exc c14n way */

  zx_dup_attr(c, x->DeviceInHand);
  zx_dup_attr(c, x->DeviceType);
  zx_dup_attr(c, x->SeedLength);


}

/* FUNC(zx_DEEP_CLONE_ac_TimeSyncToken) */

/* Depth first traversal of data structure to clone it and its sublements.
 * The simple strings are handled as a special case according to dup_strs flag. */

/* Called by: */
struct zx_ac_TimeSyncToken_s* zx_DEEP_CLONE_ac_TimeSyncToken(struct zx_ctx* c, struct zx_ac_TimeSyncToken_s* x, int dup_strs)
{
  x = (struct zx_ac_TimeSyncToken_s*)zx_clone_elem_common(c, &x->gg, sizeof(struct zx_ac_TimeSyncToken_s), dup_strs);
  /* *** deal with xmlns specifications in exc c14n way */

  x->DeviceInHand = zx_clone_attr(c, x->DeviceInHand);
  x->DeviceType = zx_clone_attr(c, x->DeviceType);
  x->SeedLength = zx_clone_attr(c, x->SeedLength);


  return x;
}

/* FUNC(zx_WALK_SO_ac_TimeSyncToken) */

/* Depth first traversal of the tree in either schema order or the wire order. */
 
int zx_WALK_SO_ac_TimeSyncToken(struct zx_ctx* c, struct zx_ac_TimeSyncToken_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
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

/* FUNC(zx_WALK_WO_ac_TimeSyncToken) */

int zx_WALK_WO_ac_TimeSyncToken(struct zx_ctx* c, struct zx_ac_TimeSyncToken_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
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

#define EL_NAME   ac_Token
#define EL_STRUCT zx_ac_Token_s
#define EL_NS     ac
#define EL_TAG    Token

/* FUNC(zx_FREE_ac_Token) */

/* Depth first traversal of data structure to free it and its subelements. Simple
 * strings are handled as a special case according to the free_strs flag. This
 * is useful if the strings point to underlying data from the wire that was
 * allocated differently. */

/* Called by: */
void zx_FREE_ac_Token(struct zx_ctx* c, struct zx_ac_Token_s* x, int free_strs)
{
  /* *** deal with xmlns specifications in exc c14n way */


  {
      struct zx_ac_TimeSyncToken_s* e;
      struct zx_ac_TimeSyncToken_s* en;
      for (e = x->TimeSyncToken; e; e = en) {
	  en = (struct zx_ac_TimeSyncToken_s*)e->gg.g.n;
	  zx_FREE_ac_TimeSyncToken(c, e, free_strs);
      }
  }
  {
      struct zx_ac_Extension_s* e;
      struct zx_ac_Extension_s* en;
      for (e = x->Extension; e; e = en) {
	  en = (struct zx_ac_Extension_s*)e->gg.g.n;
	  zx_FREE_ac_Extension(c, e, free_strs);
      }
  }


  zx_free_elem_common(c, &x->gg, free_strs); 
}

/* FUNC(zx_NEW_ac_Token) */

/* Trivial allocator/constructor for the datatype. */

/* Called by: */
struct zx_ac_Token_s* zx_NEW_ac_Token(struct zx_ctx* c)
{
  struct zx_ac_Token_s* x = ZX_ZALLOC(c, struct zx_ac_Token_s);
  x->gg.g.tok = zx_ac_Token_ELEM;
  return x;
}

#ifdef ZX_ENA_AUX

/* FUNC(zx_DUP_STRS_ac_Token) */

/* Depth first traversal of data structure to copy its simple strings
 * to memory allocated from the memory allocator. The decoder will
 * use the underlying wireprotocol PDU buffer for strings, i.e.
 * strings are not copied - they point to the real data. If the
 * datastructure needs to outlast the protocol data or needs a different
 * memory allocation strategy, you need to call this function.  */

/* Called by: */
void zx_DUP_STRS_ac_Token(struct zx_ctx* c, struct zx_ac_Token_s* x)
{
  zx_dup_strs_common(c, &x->gg);
  /* *** deal with xmlns specifications in exc c14n way */


  {
      struct zx_ac_TimeSyncToken_s* e;
      for (e = x->TimeSyncToken; e; e = (struct zx_ac_TimeSyncToken_s*)e->gg.g.n)
	  zx_DUP_STRS_ac_TimeSyncToken(c, e);
  }
  {
      struct zx_ac_Extension_s* e;
      for (e = x->Extension; e; e = (struct zx_ac_Extension_s*)e->gg.g.n)
	  zx_DUP_STRS_ac_Extension(c, e);
  }

}

/* FUNC(zx_DEEP_CLONE_ac_Token) */

/* Depth first traversal of data structure to clone it and its sublements.
 * The simple strings are handled as a special case according to dup_strs flag. */

/* Called by: */
struct zx_ac_Token_s* zx_DEEP_CLONE_ac_Token(struct zx_ctx* c, struct zx_ac_Token_s* x, int dup_strs)
{
  x = (struct zx_ac_Token_s*)zx_clone_elem_common(c, &x->gg, sizeof(struct zx_ac_Token_s), dup_strs);
  /* *** deal with xmlns specifications in exc c14n way */


  {
      struct zx_ac_TimeSyncToken_s* e;
      struct zx_ac_TimeSyncToken_s* en;
      struct zx_ac_TimeSyncToken_s* enn;
      for (enn = 0, e = x->TimeSyncToken; e; e = (struct zx_ac_TimeSyncToken_s*)e->gg.g.n) {
	  en = zx_DEEP_CLONE_ac_TimeSyncToken(c, e, dup_strs);
	  if (!enn)
	      x->TimeSyncToken = en;
	  else
	      enn->gg.g.n = &en->gg.g;
	  enn = en;
      }
  }
  {
      struct zx_ac_Extension_s* e;
      struct zx_ac_Extension_s* en;
      struct zx_ac_Extension_s* enn;
      for (enn = 0, e = x->Extension; e; e = (struct zx_ac_Extension_s*)e->gg.g.n) {
	  en = zx_DEEP_CLONE_ac_Extension(c, e, dup_strs);
	  if (!enn)
	      x->Extension = en;
	  else
	      enn->gg.g.n = &en->gg.g;
	  enn = en;
      }
  }

  return x;
}

/* FUNC(zx_WALK_SO_ac_Token) */

/* Depth first traversal of the tree in either schema order or the wire order. */
 
int zx_WALK_SO_ac_Token(struct zx_ctx* c, struct zx_ac_Token_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
{
  int ret = callback(&x->gg.g, ctx);
  if (ret)
    return ret;
  
  /* *** deal with xmlns specifications in exc c14n way */


  
  ret = zx_walk_so_unknown_attributes(c, &x->gg, ctx, callback); 
  if (ret)
    return ret;

  {
      struct zx_ac_TimeSyncToken_s* e;
      for (e = x->TimeSyncToken; e; e = (struct zx_ac_TimeSyncToken_s*)e->gg.g.n) {
	  ret = zx_WALK_SO_ac_TimeSyncToken(c, e, ctx, callback);
	  if (ret)
	      return ret;
      }
  }
  {
      struct zx_ac_Extension_s* e;
      for (e = x->Extension; e; e = (struct zx_ac_Extension_s*)e->gg.g.n) {
	  ret = zx_WALK_SO_ac_Extension(c, e, ctx, callback);
	  if (ret)
	      return ret;
      }
  }

  
  return zx_walk_so_unknown_elems_and_content(c, &x->gg, ctx, callback);
}

/* FUNC(zx_WALK_WO_ac_Token) */

int zx_WALK_WO_ac_Token(struct zx_ctx* c, struct zx_ac_Token_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
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

#define EL_NAME   ac_WTLS
#define EL_STRUCT zx_ac_WTLS_s
#define EL_NS     ac
#define EL_TAG    WTLS

/* FUNC(zx_FREE_ac_WTLS) */

/* Depth first traversal of data structure to free it and its subelements. Simple
 * strings are handled as a special case according to the free_strs flag. This
 * is useful if the strings point to underlying data from the wire that was
 * allocated differently. */

/* Called by: */
void zx_FREE_ac_WTLS(struct zx_ctx* c, struct zx_ac_WTLS_s* x, int free_strs)
{
  /* *** deal with xmlns specifications in exc c14n way */


  {
      struct zx_ac_Extension_s* e;
      struct zx_ac_Extension_s* en;
      for (e = x->Extension; e; e = en) {
	  en = (struct zx_ac_Extension_s*)e->gg.g.n;
	  zx_FREE_ac_Extension(c, e, free_strs);
      }
  }


  zx_free_elem_common(c, &x->gg, free_strs); 
}

/* FUNC(zx_NEW_ac_WTLS) */

/* Trivial allocator/constructor for the datatype. */

/* Called by: */
struct zx_ac_WTLS_s* zx_NEW_ac_WTLS(struct zx_ctx* c)
{
  struct zx_ac_WTLS_s* x = ZX_ZALLOC(c, struct zx_ac_WTLS_s);
  x->gg.g.tok = zx_ac_WTLS_ELEM;
  return x;
}

#ifdef ZX_ENA_AUX

/* FUNC(zx_DUP_STRS_ac_WTLS) */

/* Depth first traversal of data structure to copy its simple strings
 * to memory allocated from the memory allocator. The decoder will
 * use the underlying wireprotocol PDU buffer for strings, i.e.
 * strings are not copied - they point to the real data. If the
 * datastructure needs to outlast the protocol data or needs a different
 * memory allocation strategy, you need to call this function.  */

/* Called by: */
void zx_DUP_STRS_ac_WTLS(struct zx_ctx* c, struct zx_ac_WTLS_s* x)
{
  zx_dup_strs_common(c, &x->gg);
  /* *** deal with xmlns specifications in exc c14n way */


  {
      struct zx_ac_Extension_s* e;
      for (e = x->Extension; e; e = (struct zx_ac_Extension_s*)e->gg.g.n)
	  zx_DUP_STRS_ac_Extension(c, e);
  }

}

/* FUNC(zx_DEEP_CLONE_ac_WTLS) */

/* Depth first traversal of data structure to clone it and its sublements.
 * The simple strings are handled as a special case according to dup_strs flag. */

/* Called by: */
struct zx_ac_WTLS_s* zx_DEEP_CLONE_ac_WTLS(struct zx_ctx* c, struct zx_ac_WTLS_s* x, int dup_strs)
{
  x = (struct zx_ac_WTLS_s*)zx_clone_elem_common(c, &x->gg, sizeof(struct zx_ac_WTLS_s), dup_strs);
  /* *** deal with xmlns specifications in exc c14n way */


  {
      struct zx_ac_Extension_s* e;
      struct zx_ac_Extension_s* en;
      struct zx_ac_Extension_s* enn;
      for (enn = 0, e = x->Extension; e; e = (struct zx_ac_Extension_s*)e->gg.g.n) {
	  en = zx_DEEP_CLONE_ac_Extension(c, e, dup_strs);
	  if (!enn)
	      x->Extension = en;
	  else
	      enn->gg.g.n = &en->gg.g;
	  enn = en;
      }
  }

  return x;
}

/* FUNC(zx_WALK_SO_ac_WTLS) */

/* Depth first traversal of the tree in either schema order or the wire order. */
 
int zx_WALK_SO_ac_WTLS(struct zx_ctx* c, struct zx_ac_WTLS_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
{
  int ret = callback(&x->gg.g, ctx);
  if (ret)
    return ret;
  
  /* *** deal with xmlns specifications in exc c14n way */


  
  ret = zx_walk_so_unknown_attributes(c, &x->gg, ctx, callback); 
  if (ret)
    return ret;

  {
      struct zx_ac_Extension_s* e;
      for (e = x->Extension; e; e = (struct zx_ac_Extension_s*)e->gg.g.n) {
	  ret = zx_WALK_SO_ac_Extension(c, e, ctx, callback);
	  if (ret)
	      return ret;
      }
  }

  
  return zx_walk_so_unknown_elems_and_content(c, &x->gg, ctx, callback);
}

/* FUNC(zx_WALK_WO_ac_WTLS) */

int zx_WALK_WO_ac_WTLS(struct zx_ctx* c, struct zx_ac_WTLS_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
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

#define EL_NAME   ac_WrittenConsent
#define EL_STRUCT zx_ac_WrittenConsent_s
#define EL_NS     ac
#define EL_TAG    WrittenConsent

/* FUNC(zx_FREE_ac_WrittenConsent) */

/* Depth first traversal of data structure to free it and its subelements. Simple
 * strings are handled as a special case according to the free_strs flag. This
 * is useful if the strings point to underlying data from the wire that was
 * allocated differently. */

/* Called by: */
void zx_FREE_ac_WrittenConsent(struct zx_ctx* c, struct zx_ac_WrittenConsent_s* x, int free_strs)
{
  /* *** deal with xmlns specifications in exc c14n way */


  {
      struct zx_ac_Extension_s* e;
      struct zx_ac_Extension_s* en;
      for (e = x->Extension; e; e = en) {
	  en = (struct zx_ac_Extension_s*)e->gg.g.n;
	  zx_FREE_ac_Extension(c, e, free_strs);
      }
  }


  zx_free_elem_common(c, &x->gg, free_strs); 
}

/* FUNC(zx_NEW_ac_WrittenConsent) */

/* Trivial allocator/constructor for the datatype. */

/* Called by: */
struct zx_ac_WrittenConsent_s* zx_NEW_ac_WrittenConsent(struct zx_ctx* c)
{
  struct zx_ac_WrittenConsent_s* x = ZX_ZALLOC(c, struct zx_ac_WrittenConsent_s);
  x->gg.g.tok = zx_ac_WrittenConsent_ELEM;
  return x;
}

#ifdef ZX_ENA_AUX

/* FUNC(zx_DUP_STRS_ac_WrittenConsent) */

/* Depth first traversal of data structure to copy its simple strings
 * to memory allocated from the memory allocator. The decoder will
 * use the underlying wireprotocol PDU buffer for strings, i.e.
 * strings are not copied - they point to the real data. If the
 * datastructure needs to outlast the protocol data or needs a different
 * memory allocation strategy, you need to call this function.  */

/* Called by: */
void zx_DUP_STRS_ac_WrittenConsent(struct zx_ctx* c, struct zx_ac_WrittenConsent_s* x)
{
  zx_dup_strs_common(c, &x->gg);
  /* *** deal with xmlns specifications in exc c14n way */


  {
      struct zx_ac_Extension_s* e;
      for (e = x->Extension; e; e = (struct zx_ac_Extension_s*)e->gg.g.n)
	  zx_DUP_STRS_ac_Extension(c, e);
  }

}

/* FUNC(zx_DEEP_CLONE_ac_WrittenConsent) */

/* Depth first traversal of data structure to clone it and its sublements.
 * The simple strings are handled as a special case according to dup_strs flag. */

/* Called by: */
struct zx_ac_WrittenConsent_s* zx_DEEP_CLONE_ac_WrittenConsent(struct zx_ctx* c, struct zx_ac_WrittenConsent_s* x, int dup_strs)
{
  x = (struct zx_ac_WrittenConsent_s*)zx_clone_elem_common(c, &x->gg, sizeof(struct zx_ac_WrittenConsent_s), dup_strs);
  /* *** deal with xmlns specifications in exc c14n way */


  {
      struct zx_ac_Extension_s* e;
      struct zx_ac_Extension_s* en;
      struct zx_ac_Extension_s* enn;
      for (enn = 0, e = x->Extension; e; e = (struct zx_ac_Extension_s*)e->gg.g.n) {
	  en = zx_DEEP_CLONE_ac_Extension(c, e, dup_strs);
	  if (!enn)
	      x->Extension = en;
	  else
	      enn->gg.g.n = &en->gg.g;
	  enn = en;
      }
  }

  return x;
}

/* FUNC(zx_WALK_SO_ac_WrittenConsent) */

/* Depth first traversal of the tree in either schema order or the wire order. */
 
int zx_WALK_SO_ac_WrittenConsent(struct zx_ctx* c, struct zx_ac_WrittenConsent_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
{
  int ret = callback(&x->gg.g, ctx);
  if (ret)
    return ret;
  
  /* *** deal with xmlns specifications in exc c14n way */


  
  ret = zx_walk_so_unknown_attributes(c, &x->gg, ctx, callback); 
  if (ret)
    return ret;

  {
      struct zx_ac_Extension_s* e;
      for (e = x->Extension; e; e = (struct zx_ac_Extension_s*)e->gg.g.n) {
	  ret = zx_WALK_SO_ac_Extension(c, e, ctx, callback);
	  if (ret)
	      return ret;
      }
  }

  
  return zx_walk_so_unknown_elems_and_content(c, &x->gg, ctx, callback);
}

/* FUNC(zx_WALK_WO_ac_WrittenConsent) */

int zx_WALK_WO_ac_WrittenConsent(struct zx_ctx* c, struct zx_ac_WrittenConsent_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
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

#define EL_NAME   ac_ZeroKnowledge
#define EL_STRUCT zx_ac_ZeroKnowledge_s
#define EL_NS     ac
#define EL_TAG    ZeroKnowledge

/* FUNC(zx_FREE_ac_ZeroKnowledge) */

/* Depth first traversal of data structure to free it and its subelements. Simple
 * strings are handled as a special case according to the free_strs flag. This
 * is useful if the strings point to underlying data from the wire that was
 * allocated differently. */

/* Called by: */
void zx_FREE_ac_ZeroKnowledge(struct zx_ctx* c, struct zx_ac_ZeroKnowledge_s* x, int free_strs)
{
  /* *** deal with xmlns specifications in exc c14n way */


  {
      struct zx_ac_Extension_s* e;
      struct zx_ac_Extension_s* en;
      for (e = x->Extension; e; e = en) {
	  en = (struct zx_ac_Extension_s*)e->gg.g.n;
	  zx_FREE_ac_Extension(c, e, free_strs);
      }
  }


  zx_free_elem_common(c, &x->gg, free_strs); 
}

/* FUNC(zx_NEW_ac_ZeroKnowledge) */

/* Trivial allocator/constructor for the datatype. */

/* Called by: */
struct zx_ac_ZeroKnowledge_s* zx_NEW_ac_ZeroKnowledge(struct zx_ctx* c)
{
  struct zx_ac_ZeroKnowledge_s* x = ZX_ZALLOC(c, struct zx_ac_ZeroKnowledge_s);
  x->gg.g.tok = zx_ac_ZeroKnowledge_ELEM;
  return x;
}

#ifdef ZX_ENA_AUX

/* FUNC(zx_DUP_STRS_ac_ZeroKnowledge) */

/* Depth first traversal of data structure to copy its simple strings
 * to memory allocated from the memory allocator. The decoder will
 * use the underlying wireprotocol PDU buffer for strings, i.e.
 * strings are not copied - they point to the real data. If the
 * datastructure needs to outlast the protocol data or needs a different
 * memory allocation strategy, you need to call this function.  */

/* Called by: */
void zx_DUP_STRS_ac_ZeroKnowledge(struct zx_ctx* c, struct zx_ac_ZeroKnowledge_s* x)
{
  zx_dup_strs_common(c, &x->gg);
  /* *** deal with xmlns specifications in exc c14n way */


  {
      struct zx_ac_Extension_s* e;
      for (e = x->Extension; e; e = (struct zx_ac_Extension_s*)e->gg.g.n)
	  zx_DUP_STRS_ac_Extension(c, e);
  }

}

/* FUNC(zx_DEEP_CLONE_ac_ZeroKnowledge) */

/* Depth first traversal of data structure to clone it and its sublements.
 * The simple strings are handled as a special case according to dup_strs flag. */

/* Called by: */
struct zx_ac_ZeroKnowledge_s* zx_DEEP_CLONE_ac_ZeroKnowledge(struct zx_ctx* c, struct zx_ac_ZeroKnowledge_s* x, int dup_strs)
{
  x = (struct zx_ac_ZeroKnowledge_s*)zx_clone_elem_common(c, &x->gg, sizeof(struct zx_ac_ZeroKnowledge_s), dup_strs);
  /* *** deal with xmlns specifications in exc c14n way */


  {
      struct zx_ac_Extension_s* e;
      struct zx_ac_Extension_s* en;
      struct zx_ac_Extension_s* enn;
      for (enn = 0, e = x->Extension; e; e = (struct zx_ac_Extension_s*)e->gg.g.n) {
	  en = zx_DEEP_CLONE_ac_Extension(c, e, dup_strs);
	  if (!enn)
	      x->Extension = en;
	  else
	      enn->gg.g.n = &en->gg.g;
	  enn = en;
      }
  }

  return x;
}

/* FUNC(zx_WALK_SO_ac_ZeroKnowledge) */

/* Depth first traversal of the tree in either schema order or the wire order. */
 
int zx_WALK_SO_ac_ZeroKnowledge(struct zx_ctx* c, struct zx_ac_ZeroKnowledge_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
{
  int ret = callback(&x->gg.g, ctx);
  if (ret)
    return ret;
  
  /* *** deal with xmlns specifications in exc c14n way */


  
  ret = zx_walk_so_unknown_attributes(c, &x->gg, ctx, callback); 
  if (ret)
    return ret;

  {
      struct zx_ac_Extension_s* e;
      for (e = x->Extension; e; e = (struct zx_ac_Extension_s*)e->gg.g.n) {
	  ret = zx_WALK_SO_ac_Extension(c, e, ctx, callback);
	  if (ret)
	      return ret;
      }
  }

  
  return zx_walk_so_unknown_elems_and_content(c, &x->gg, ctx, callback);
}

/* FUNC(zx_WALK_WO_ac_ZeroKnowledge) */

int zx_WALK_WO_ac_ZeroKnowledge(struct zx_ctx* c, struct zx_ac_ZeroKnowledge_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
{
  ERR("*** walk_wo not implemented %d", 0);
  return 0;
}

#endif


/* EOF -- c/zx-ac-aux.c */
