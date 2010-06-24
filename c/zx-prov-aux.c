/* c/zx-prov-aux.c - WARNING: This file was automatically generated. DO NOT EDIT!
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
#include "c/zx-prov-data.h"



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

#define EL_NAME   prov_CallbackEPR
#define EL_STRUCT zx_prov_CallbackEPR_s
#define EL_NS     prov
#define EL_TAG    CallbackEPR

/* FUNC(zx_FREE_prov_CallbackEPR) */

/* Depth first traversal of data structure to free it and its subelements. Simple
 * strings are handled as a special case according to the free_strs flag. This
 * is useful if the strings point to underlying data from the wire that was
 * allocated differently. */

/* Called by: */
void zx_FREE_prov_CallbackEPR(struct zx_ctx* c, struct zx_prov_CallbackEPR_s* x, int free_strs)
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

/* FUNC(zx_NEW_prov_CallbackEPR) */

/* Trivial allocator/constructor for the datatype. */

/* Called by: */
struct zx_prov_CallbackEPR_s* zx_NEW_prov_CallbackEPR(struct zx_ctx* c)
{
  struct zx_prov_CallbackEPR_s* x = ZX_ZALLOC(c, struct zx_prov_CallbackEPR_s);
  x->gg.g.tok = zx_prov_CallbackEPR_ELEM;
  return x;
}

#ifdef ZX_ENA_AUX

/* FUNC(zx_DUP_STRS_prov_CallbackEPR) */

/* Depth first traversal of data structure to copy its simple strings
 * to memory allocated from the memory allocator. The decoder will
 * use the underlying wireprotocol PDU buffer for strings, i.e.
 * strings are not copied - they point to the real data. If the
 * datastructure needs to outlast the protocol data or needs a different
 * memory allocation strategy, you need to call this function.  */

/* Called by: */
void zx_DUP_STRS_prov_CallbackEPR(struct zx_ctx* c, struct zx_prov_CallbackEPR_s* x)
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

/* FUNC(zx_DEEP_CLONE_prov_CallbackEPR) */

/* Depth first traversal of data structure to clone it and its sublements.
 * The simple strings are handled as a special case according to dup_strs flag. */

/* Called by: */
struct zx_prov_CallbackEPR_s* zx_DEEP_CLONE_prov_CallbackEPR(struct zx_ctx* c, struct zx_prov_CallbackEPR_s* x, int dup_strs)
{
  x = (struct zx_prov_CallbackEPR_s*)zx_clone_elem_common(c, &x->gg, sizeof(struct zx_prov_CallbackEPR_s), dup_strs);
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

/* FUNC(zx_WALK_SO_prov_CallbackEPR) */

/* Depth first traversal of the tree in either schema order or the wire order. */
 
int zx_WALK_SO_prov_CallbackEPR(struct zx_ctx* c, struct zx_prov_CallbackEPR_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
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

/* FUNC(zx_WALK_WO_prov_CallbackEPR) */

int zx_WALK_WO_prov_CallbackEPR(struct zx_ctx* c, struct zx_prov_CallbackEPR_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
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

#define EL_NAME   prov_PMActivate
#define EL_STRUCT zx_prov_PMActivate_s
#define EL_NS     prov
#define EL_TAG    PMActivate

/* FUNC(zx_FREE_prov_PMActivate) */

/* Depth first traversal of data structure to free it and its subelements. Simple
 * strings are handled as a special case according to the free_strs flag. This
 * is useful if the strings point to underlying data from the wire that was
 * allocated differently. */

/* Called by: */
void zx_FREE_prov_PMActivate(struct zx_ctx* c, struct zx_prov_PMActivate_s* x, int free_strs)
{
  /* *** deal with xmlns specifications in exc c14n way */


  {
      struct zx_prov_PMActivateItem_s* e;
      struct zx_prov_PMActivateItem_s* en;
      for (e = x->PMActivateItem; e; e = en) {
	  en = (struct zx_prov_PMActivateItem_s*)e->gg.g.n;
	  zx_FREE_prov_PMActivateItem(c, e, free_strs);
      }
  }
  zx_free_simple_elems(c, x->NotifyTo, free_strs);


  zx_free_elem_common(c, &x->gg, free_strs); 
}

/* FUNC(zx_NEW_prov_PMActivate) */

/* Trivial allocator/constructor for the datatype. */

/* Called by: */
struct zx_prov_PMActivate_s* zx_NEW_prov_PMActivate(struct zx_ctx* c)
{
  struct zx_prov_PMActivate_s* x = ZX_ZALLOC(c, struct zx_prov_PMActivate_s);
  x->gg.g.tok = zx_prov_PMActivate_ELEM;
  return x;
}

#ifdef ZX_ENA_AUX

/* FUNC(zx_DUP_STRS_prov_PMActivate) */

/* Depth first traversal of data structure to copy its simple strings
 * to memory allocated from the memory allocator. The decoder will
 * use the underlying wireprotocol PDU buffer for strings, i.e.
 * strings are not copied - they point to the real data. If the
 * datastructure needs to outlast the protocol data or needs a different
 * memory allocation strategy, you need to call this function.  */

/* Called by: */
void zx_DUP_STRS_prov_PMActivate(struct zx_ctx* c, struct zx_prov_PMActivate_s* x)
{
  zx_dup_strs_common(c, &x->gg);
  /* *** deal with xmlns specifications in exc c14n way */


  {
      struct zx_prov_PMActivateItem_s* e;
      for (e = x->PMActivateItem; e; e = (struct zx_prov_PMActivateItem_s*)e->gg.g.n)
	  zx_DUP_STRS_prov_PMActivateItem(c, e);
  }
  zx_dup_strs_simple_elems(c, x->NotifyTo);

}

/* FUNC(zx_DEEP_CLONE_prov_PMActivate) */

/* Depth first traversal of data structure to clone it and its sublements.
 * The simple strings are handled as a special case according to dup_strs flag. */

/* Called by: */
struct zx_prov_PMActivate_s* zx_DEEP_CLONE_prov_PMActivate(struct zx_ctx* c, struct zx_prov_PMActivate_s* x, int dup_strs)
{
  x = (struct zx_prov_PMActivate_s*)zx_clone_elem_common(c, &x->gg, sizeof(struct zx_prov_PMActivate_s), dup_strs);
  /* *** deal with xmlns specifications in exc c14n way */


  {
      struct zx_prov_PMActivateItem_s* e;
      struct zx_prov_PMActivateItem_s* en;
      struct zx_prov_PMActivateItem_s* enn;
      for (enn = 0, e = x->PMActivateItem; e; e = (struct zx_prov_PMActivateItem_s*)e->gg.g.n) {
	  en = zx_DEEP_CLONE_prov_PMActivateItem(c, e, dup_strs);
	  if (!enn)
	      x->PMActivateItem = en;
	  else
	      enn->gg.g.n = &en->gg.g;
	  enn = en;
      }
  }
  x->NotifyTo = zx_deep_clone_simple_elems(c,x->NotifyTo, dup_strs);

  return x;
}

/* FUNC(zx_WALK_SO_prov_PMActivate) */

/* Depth first traversal of the tree in either schema order or the wire order. */
 
int zx_WALK_SO_prov_PMActivate(struct zx_ctx* c, struct zx_prov_PMActivate_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
{
  int ret = callback(&x->gg.g, ctx);
  if (ret)
    return ret;
  
  /* *** deal with xmlns specifications in exc c14n way */


  
  ret = zx_walk_so_unknown_attributes(c, &x->gg, ctx, callback); 
  if (ret)
    return ret;

  {
      struct zx_prov_PMActivateItem_s* e;
      for (e = x->PMActivateItem; e; e = (struct zx_prov_PMActivateItem_s*)e->gg.g.n) {
	  ret = zx_WALK_SO_prov_PMActivateItem(c, e, ctx, callback);
	  if (ret)
	      return ret;
      }
  }
  ret = zx_walk_so_simple_elems(c, x->NotifyTo, ctx, callback);
  if (ret)
    return ret;

  
  return zx_walk_so_unknown_elems_and_content(c, &x->gg, ctx, callback);
}

/* FUNC(zx_WALK_WO_prov_PMActivate) */

int zx_WALK_WO_prov_PMActivate(struct zx_ctx* c, struct zx_prov_PMActivate_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
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

#define EL_NAME   prov_PMActivateItem
#define EL_STRUCT zx_prov_PMActivateItem_s
#define EL_NS     prov
#define EL_TAG    PMActivateItem

/* FUNC(zx_FREE_prov_PMActivateItem) */

/* Depth first traversal of data structure to free it and its subelements. Simple
 * strings are handled as a special case according to the free_strs flag. This
 * is useful if the strings point to underlying data from the wire that was
 * allocated differently. */

/* Called by: */
void zx_FREE_prov_PMActivateItem(struct zx_ctx* c, struct zx_prov_PMActivateItem_s* x, int free_strs)
{
  /* *** deal with xmlns specifications in exc c14n way */

  zx_free_attr(c, x->at, free_strs);
  zx_free_attr(c, x->itemID, free_strs);

  {
      struct zx_prov_PMID_s* e;
      struct zx_prov_PMID_s* en;
      for (e = x->PMID; e; e = en) {
	  en = (struct zx_prov_PMID_s*)e->gg.g.n;
	  zx_FREE_prov_PMID(c, e, free_strs);
      }
  }


  zx_free_elem_common(c, &x->gg, free_strs); 
}

/* FUNC(zx_NEW_prov_PMActivateItem) */

/* Trivial allocator/constructor for the datatype. */

/* Called by: */
struct zx_prov_PMActivateItem_s* zx_NEW_prov_PMActivateItem(struct zx_ctx* c)
{
  struct zx_prov_PMActivateItem_s* x = ZX_ZALLOC(c, struct zx_prov_PMActivateItem_s);
  x->gg.g.tok = zx_prov_PMActivateItem_ELEM;
  return x;
}

#ifdef ZX_ENA_AUX

/* FUNC(zx_DUP_STRS_prov_PMActivateItem) */

/* Depth first traversal of data structure to copy its simple strings
 * to memory allocated from the memory allocator. The decoder will
 * use the underlying wireprotocol PDU buffer for strings, i.e.
 * strings are not copied - they point to the real data. If the
 * datastructure needs to outlast the protocol data or needs a different
 * memory allocation strategy, you need to call this function.  */

/* Called by: */
void zx_DUP_STRS_prov_PMActivateItem(struct zx_ctx* c, struct zx_prov_PMActivateItem_s* x)
{
  zx_dup_strs_common(c, &x->gg);
  /* *** deal with xmlns specifications in exc c14n way */

  zx_dup_attr(c, x->at);
  zx_dup_attr(c, x->itemID);

  {
      struct zx_prov_PMID_s* e;
      for (e = x->PMID; e; e = (struct zx_prov_PMID_s*)e->gg.g.n)
	  zx_DUP_STRS_prov_PMID(c, e);
  }

}

/* FUNC(zx_DEEP_CLONE_prov_PMActivateItem) */

/* Depth first traversal of data structure to clone it and its sublements.
 * The simple strings are handled as a special case according to dup_strs flag. */

/* Called by: */
struct zx_prov_PMActivateItem_s* zx_DEEP_CLONE_prov_PMActivateItem(struct zx_ctx* c, struct zx_prov_PMActivateItem_s* x, int dup_strs)
{
  x = (struct zx_prov_PMActivateItem_s*)zx_clone_elem_common(c, &x->gg, sizeof(struct zx_prov_PMActivateItem_s), dup_strs);
  /* *** deal with xmlns specifications in exc c14n way */

  x->at = zx_clone_attr(c, x->at);
  x->itemID = zx_clone_attr(c, x->itemID);

  {
      struct zx_prov_PMID_s* e;
      struct zx_prov_PMID_s* en;
      struct zx_prov_PMID_s* enn;
      for (enn = 0, e = x->PMID; e; e = (struct zx_prov_PMID_s*)e->gg.g.n) {
	  en = zx_DEEP_CLONE_prov_PMID(c, e, dup_strs);
	  if (!enn)
	      x->PMID = en;
	  else
	      enn->gg.g.n = &en->gg.g;
	  enn = en;
      }
  }

  return x;
}

/* FUNC(zx_WALK_SO_prov_PMActivateItem) */

/* Depth first traversal of the tree in either schema order or the wire order. */
 
int zx_WALK_SO_prov_PMActivateItem(struct zx_ctx* c, struct zx_prov_PMActivateItem_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
{
  int ret = callback(&x->gg.g, ctx);
  if (ret)
    return ret;
  
  /* *** deal with xmlns specifications in exc c14n way */


  
  ret = zx_walk_so_unknown_attributes(c, &x->gg, ctx, callback); 
  if (ret)
    return ret;

  {
      struct zx_prov_PMID_s* e;
      for (e = x->PMID; e; e = (struct zx_prov_PMID_s*)e->gg.g.n) {
	  ret = zx_WALK_SO_prov_PMID(c, e, ctx, callback);
	  if (ret)
	      return ret;
      }
  }

  
  return zx_walk_so_unknown_elems_and_content(c, &x->gg, ctx, callback);
}

/* FUNC(zx_WALK_WO_prov_PMActivateItem) */

int zx_WALK_WO_prov_PMActivateItem(struct zx_ctx* c, struct zx_prov_PMActivateItem_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
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

#define EL_NAME   prov_PMActivateResponse
#define EL_STRUCT zx_prov_PMActivateResponse_s
#define EL_NS     prov
#define EL_TAG    PMActivateResponse

/* FUNC(zx_FREE_prov_PMActivateResponse) */

/* Depth first traversal of data structure to free it and its subelements. Simple
 * strings are handled as a special case according to the free_strs flag. This
 * is useful if the strings point to underlying data from the wire that was
 * allocated differently. */

/* Called by: */
void zx_FREE_prov_PMActivateResponse(struct zx_ctx* c, struct zx_prov_PMActivateResponse_s* x, int free_strs)
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

/* FUNC(zx_NEW_prov_PMActivateResponse) */

/* Trivial allocator/constructor for the datatype. */

/* Called by: */
struct zx_prov_PMActivateResponse_s* zx_NEW_prov_PMActivateResponse(struct zx_ctx* c)
{
  struct zx_prov_PMActivateResponse_s* x = ZX_ZALLOC(c, struct zx_prov_PMActivateResponse_s);
  x->gg.g.tok = zx_prov_PMActivateResponse_ELEM;
  return x;
}

#ifdef ZX_ENA_AUX

/* FUNC(zx_DUP_STRS_prov_PMActivateResponse) */

/* Depth first traversal of data structure to copy its simple strings
 * to memory allocated from the memory allocator. The decoder will
 * use the underlying wireprotocol PDU buffer for strings, i.e.
 * strings are not copied - they point to the real data. If the
 * datastructure needs to outlast the protocol data or needs a different
 * memory allocation strategy, you need to call this function.  */

/* Called by: */
void zx_DUP_STRS_prov_PMActivateResponse(struct zx_ctx* c, struct zx_prov_PMActivateResponse_s* x)
{
  zx_dup_strs_common(c, &x->gg);
  /* *** deal with xmlns specifications in exc c14n way */


  {
      struct zx_lu_Status_s* e;
      for (e = x->Status; e; e = (struct zx_lu_Status_s*)e->gg.g.n)
	  zx_DUP_STRS_lu_Status(c, e);
  }

}

/* FUNC(zx_DEEP_CLONE_prov_PMActivateResponse) */

/* Depth first traversal of data structure to clone it and its sublements.
 * The simple strings are handled as a special case according to dup_strs flag. */

/* Called by: */
struct zx_prov_PMActivateResponse_s* zx_DEEP_CLONE_prov_PMActivateResponse(struct zx_ctx* c, struct zx_prov_PMActivateResponse_s* x, int dup_strs)
{
  x = (struct zx_prov_PMActivateResponse_s*)zx_clone_elem_common(c, &x->gg, sizeof(struct zx_prov_PMActivateResponse_s), dup_strs);
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

/* FUNC(zx_WALK_SO_prov_PMActivateResponse) */

/* Depth first traversal of the tree in either schema order or the wire order. */
 
int zx_WALK_SO_prov_PMActivateResponse(struct zx_ctx* c, struct zx_prov_PMActivateResponse_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
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

/* FUNC(zx_WALK_WO_prov_PMActivateResponse) */

int zx_WALK_WO_prov_PMActivateResponse(struct zx_ctx* c, struct zx_prov_PMActivateResponse_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
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

#define EL_NAME   prov_PMDeactivate
#define EL_STRUCT zx_prov_PMDeactivate_s
#define EL_NS     prov
#define EL_TAG    PMDeactivate

/* FUNC(zx_FREE_prov_PMDeactivate) */

/* Depth first traversal of data structure to free it and its subelements. Simple
 * strings are handled as a special case according to the free_strs flag. This
 * is useful if the strings point to underlying data from the wire that was
 * allocated differently. */

/* Called by: */
void zx_FREE_prov_PMDeactivate(struct zx_ctx* c, struct zx_prov_PMDeactivate_s* x, int free_strs)
{
  /* *** deal with xmlns specifications in exc c14n way */


  {
      struct zx_prov_PMDeactivateItem_s* e;
      struct zx_prov_PMDeactivateItem_s* en;
      for (e = x->PMDeactivateItem; e; e = en) {
	  en = (struct zx_prov_PMDeactivateItem_s*)e->gg.g.n;
	  zx_FREE_prov_PMDeactivateItem(c, e, free_strs);
      }
  }
  zx_free_simple_elems(c, x->NotifyTo, free_strs);


  zx_free_elem_common(c, &x->gg, free_strs); 
}

/* FUNC(zx_NEW_prov_PMDeactivate) */

/* Trivial allocator/constructor for the datatype. */

/* Called by: */
struct zx_prov_PMDeactivate_s* zx_NEW_prov_PMDeactivate(struct zx_ctx* c)
{
  struct zx_prov_PMDeactivate_s* x = ZX_ZALLOC(c, struct zx_prov_PMDeactivate_s);
  x->gg.g.tok = zx_prov_PMDeactivate_ELEM;
  return x;
}

#ifdef ZX_ENA_AUX

/* FUNC(zx_DUP_STRS_prov_PMDeactivate) */

/* Depth first traversal of data structure to copy its simple strings
 * to memory allocated from the memory allocator. The decoder will
 * use the underlying wireprotocol PDU buffer for strings, i.e.
 * strings are not copied - they point to the real data. If the
 * datastructure needs to outlast the protocol data or needs a different
 * memory allocation strategy, you need to call this function.  */

/* Called by: */
void zx_DUP_STRS_prov_PMDeactivate(struct zx_ctx* c, struct zx_prov_PMDeactivate_s* x)
{
  zx_dup_strs_common(c, &x->gg);
  /* *** deal with xmlns specifications in exc c14n way */


  {
      struct zx_prov_PMDeactivateItem_s* e;
      for (e = x->PMDeactivateItem; e; e = (struct zx_prov_PMDeactivateItem_s*)e->gg.g.n)
	  zx_DUP_STRS_prov_PMDeactivateItem(c, e);
  }
  zx_dup_strs_simple_elems(c, x->NotifyTo);

}

/* FUNC(zx_DEEP_CLONE_prov_PMDeactivate) */

/* Depth first traversal of data structure to clone it and its sublements.
 * The simple strings are handled as a special case according to dup_strs flag. */

/* Called by: */
struct zx_prov_PMDeactivate_s* zx_DEEP_CLONE_prov_PMDeactivate(struct zx_ctx* c, struct zx_prov_PMDeactivate_s* x, int dup_strs)
{
  x = (struct zx_prov_PMDeactivate_s*)zx_clone_elem_common(c, &x->gg, sizeof(struct zx_prov_PMDeactivate_s), dup_strs);
  /* *** deal with xmlns specifications in exc c14n way */


  {
      struct zx_prov_PMDeactivateItem_s* e;
      struct zx_prov_PMDeactivateItem_s* en;
      struct zx_prov_PMDeactivateItem_s* enn;
      for (enn = 0, e = x->PMDeactivateItem; e; e = (struct zx_prov_PMDeactivateItem_s*)e->gg.g.n) {
	  en = zx_DEEP_CLONE_prov_PMDeactivateItem(c, e, dup_strs);
	  if (!enn)
	      x->PMDeactivateItem = en;
	  else
	      enn->gg.g.n = &en->gg.g;
	  enn = en;
      }
  }
  x->NotifyTo = zx_deep_clone_simple_elems(c,x->NotifyTo, dup_strs);

  return x;
}

/* FUNC(zx_WALK_SO_prov_PMDeactivate) */

/* Depth first traversal of the tree in either schema order or the wire order. */
 
int zx_WALK_SO_prov_PMDeactivate(struct zx_ctx* c, struct zx_prov_PMDeactivate_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
{
  int ret = callback(&x->gg.g, ctx);
  if (ret)
    return ret;
  
  /* *** deal with xmlns specifications in exc c14n way */


  
  ret = zx_walk_so_unknown_attributes(c, &x->gg, ctx, callback); 
  if (ret)
    return ret;

  {
      struct zx_prov_PMDeactivateItem_s* e;
      for (e = x->PMDeactivateItem; e; e = (struct zx_prov_PMDeactivateItem_s*)e->gg.g.n) {
	  ret = zx_WALK_SO_prov_PMDeactivateItem(c, e, ctx, callback);
	  if (ret)
	      return ret;
      }
  }
  ret = zx_walk_so_simple_elems(c, x->NotifyTo, ctx, callback);
  if (ret)
    return ret;

  
  return zx_walk_so_unknown_elems_and_content(c, &x->gg, ctx, callback);
}

/* FUNC(zx_WALK_WO_prov_PMDeactivate) */

int zx_WALK_WO_prov_PMDeactivate(struct zx_ctx* c, struct zx_prov_PMDeactivate_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
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

#define EL_NAME   prov_PMDeactivateItem
#define EL_STRUCT zx_prov_PMDeactivateItem_s
#define EL_NS     prov
#define EL_TAG    PMDeactivateItem

/* FUNC(zx_FREE_prov_PMDeactivateItem) */

/* Depth first traversal of data structure to free it and its subelements. Simple
 * strings are handled as a special case according to the free_strs flag. This
 * is useful if the strings point to underlying data from the wire that was
 * allocated differently. */

/* Called by: */
void zx_FREE_prov_PMDeactivateItem(struct zx_ctx* c, struct zx_prov_PMDeactivateItem_s* x, int free_strs)
{
  /* *** deal with xmlns specifications in exc c14n way */

  zx_free_attr(c, x->at, free_strs);
  zx_free_attr(c, x->itemID, free_strs);

  {
      struct zx_prov_PMID_s* e;
      struct zx_prov_PMID_s* en;
      for (e = x->PMID; e; e = en) {
	  en = (struct zx_prov_PMID_s*)e->gg.g.n;
	  zx_FREE_prov_PMID(c, e, free_strs);
      }
  }


  zx_free_elem_common(c, &x->gg, free_strs); 
}

/* FUNC(zx_NEW_prov_PMDeactivateItem) */

/* Trivial allocator/constructor for the datatype. */

/* Called by: */
struct zx_prov_PMDeactivateItem_s* zx_NEW_prov_PMDeactivateItem(struct zx_ctx* c)
{
  struct zx_prov_PMDeactivateItem_s* x = ZX_ZALLOC(c, struct zx_prov_PMDeactivateItem_s);
  x->gg.g.tok = zx_prov_PMDeactivateItem_ELEM;
  return x;
}

#ifdef ZX_ENA_AUX

/* FUNC(zx_DUP_STRS_prov_PMDeactivateItem) */

/* Depth first traversal of data structure to copy its simple strings
 * to memory allocated from the memory allocator. The decoder will
 * use the underlying wireprotocol PDU buffer for strings, i.e.
 * strings are not copied - they point to the real data. If the
 * datastructure needs to outlast the protocol data or needs a different
 * memory allocation strategy, you need to call this function.  */

/* Called by: */
void zx_DUP_STRS_prov_PMDeactivateItem(struct zx_ctx* c, struct zx_prov_PMDeactivateItem_s* x)
{
  zx_dup_strs_common(c, &x->gg);
  /* *** deal with xmlns specifications in exc c14n way */

  zx_dup_attr(c, x->at);
  zx_dup_attr(c, x->itemID);

  {
      struct zx_prov_PMID_s* e;
      for (e = x->PMID; e; e = (struct zx_prov_PMID_s*)e->gg.g.n)
	  zx_DUP_STRS_prov_PMID(c, e);
  }

}

/* FUNC(zx_DEEP_CLONE_prov_PMDeactivateItem) */

/* Depth first traversal of data structure to clone it and its sublements.
 * The simple strings are handled as a special case according to dup_strs flag. */

/* Called by: */
struct zx_prov_PMDeactivateItem_s* zx_DEEP_CLONE_prov_PMDeactivateItem(struct zx_ctx* c, struct zx_prov_PMDeactivateItem_s* x, int dup_strs)
{
  x = (struct zx_prov_PMDeactivateItem_s*)zx_clone_elem_common(c, &x->gg, sizeof(struct zx_prov_PMDeactivateItem_s), dup_strs);
  /* *** deal with xmlns specifications in exc c14n way */

  x->at = zx_clone_attr(c, x->at);
  x->itemID = zx_clone_attr(c, x->itemID);

  {
      struct zx_prov_PMID_s* e;
      struct zx_prov_PMID_s* en;
      struct zx_prov_PMID_s* enn;
      for (enn = 0, e = x->PMID; e; e = (struct zx_prov_PMID_s*)e->gg.g.n) {
	  en = zx_DEEP_CLONE_prov_PMID(c, e, dup_strs);
	  if (!enn)
	      x->PMID = en;
	  else
	      enn->gg.g.n = &en->gg.g;
	  enn = en;
      }
  }

  return x;
}

/* FUNC(zx_WALK_SO_prov_PMDeactivateItem) */

/* Depth first traversal of the tree in either schema order or the wire order. */
 
int zx_WALK_SO_prov_PMDeactivateItem(struct zx_ctx* c, struct zx_prov_PMDeactivateItem_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
{
  int ret = callback(&x->gg.g, ctx);
  if (ret)
    return ret;
  
  /* *** deal with xmlns specifications in exc c14n way */


  
  ret = zx_walk_so_unknown_attributes(c, &x->gg, ctx, callback); 
  if (ret)
    return ret;

  {
      struct zx_prov_PMID_s* e;
      for (e = x->PMID; e; e = (struct zx_prov_PMID_s*)e->gg.g.n) {
	  ret = zx_WALK_SO_prov_PMID(c, e, ctx, callback);
	  if (ret)
	      return ret;
      }
  }

  
  return zx_walk_so_unknown_elems_and_content(c, &x->gg, ctx, callback);
}

/* FUNC(zx_WALK_WO_prov_PMDeactivateItem) */

int zx_WALK_WO_prov_PMDeactivateItem(struct zx_ctx* c, struct zx_prov_PMDeactivateItem_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
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

#define EL_NAME   prov_PMDeactivateResponse
#define EL_STRUCT zx_prov_PMDeactivateResponse_s
#define EL_NS     prov
#define EL_TAG    PMDeactivateResponse

/* FUNC(zx_FREE_prov_PMDeactivateResponse) */

/* Depth first traversal of data structure to free it and its subelements. Simple
 * strings are handled as a special case according to the free_strs flag. This
 * is useful if the strings point to underlying data from the wire that was
 * allocated differently. */

/* Called by: */
void zx_FREE_prov_PMDeactivateResponse(struct zx_ctx* c, struct zx_prov_PMDeactivateResponse_s* x, int free_strs)
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

/* FUNC(zx_NEW_prov_PMDeactivateResponse) */

/* Trivial allocator/constructor for the datatype. */

/* Called by: */
struct zx_prov_PMDeactivateResponse_s* zx_NEW_prov_PMDeactivateResponse(struct zx_ctx* c)
{
  struct zx_prov_PMDeactivateResponse_s* x = ZX_ZALLOC(c, struct zx_prov_PMDeactivateResponse_s);
  x->gg.g.tok = zx_prov_PMDeactivateResponse_ELEM;
  return x;
}

#ifdef ZX_ENA_AUX

/* FUNC(zx_DUP_STRS_prov_PMDeactivateResponse) */

/* Depth first traversal of data structure to copy its simple strings
 * to memory allocated from the memory allocator. The decoder will
 * use the underlying wireprotocol PDU buffer for strings, i.e.
 * strings are not copied - they point to the real data. If the
 * datastructure needs to outlast the protocol data or needs a different
 * memory allocation strategy, you need to call this function.  */

/* Called by: */
void zx_DUP_STRS_prov_PMDeactivateResponse(struct zx_ctx* c, struct zx_prov_PMDeactivateResponse_s* x)
{
  zx_dup_strs_common(c, &x->gg);
  /* *** deal with xmlns specifications in exc c14n way */


  {
      struct zx_lu_Status_s* e;
      for (e = x->Status; e; e = (struct zx_lu_Status_s*)e->gg.g.n)
	  zx_DUP_STRS_lu_Status(c, e);
  }

}

/* FUNC(zx_DEEP_CLONE_prov_PMDeactivateResponse) */

/* Depth first traversal of data structure to clone it and its sublements.
 * The simple strings are handled as a special case according to dup_strs flag. */

/* Called by: */
struct zx_prov_PMDeactivateResponse_s* zx_DEEP_CLONE_prov_PMDeactivateResponse(struct zx_ctx* c, struct zx_prov_PMDeactivateResponse_s* x, int dup_strs)
{
  x = (struct zx_prov_PMDeactivateResponse_s*)zx_clone_elem_common(c, &x->gg, sizeof(struct zx_prov_PMDeactivateResponse_s), dup_strs);
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

/* FUNC(zx_WALK_SO_prov_PMDeactivateResponse) */

/* Depth first traversal of the tree in either schema order or the wire order. */
 
int zx_WALK_SO_prov_PMDeactivateResponse(struct zx_ctx* c, struct zx_prov_PMDeactivateResponse_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
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

/* FUNC(zx_WALK_WO_prov_PMDeactivateResponse) */

int zx_WALK_WO_prov_PMDeactivateResponse(struct zx_ctx* c, struct zx_prov_PMDeactivateResponse_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
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

#define EL_NAME   prov_PMDelete
#define EL_STRUCT zx_prov_PMDelete_s
#define EL_NS     prov
#define EL_TAG    PMDelete

/* FUNC(zx_FREE_prov_PMDelete) */

/* Depth first traversal of data structure to free it and its subelements. Simple
 * strings are handled as a special case according to the free_strs flag. This
 * is useful if the strings point to underlying data from the wire that was
 * allocated differently. */

/* Called by: */
void zx_FREE_prov_PMDelete(struct zx_ctx* c, struct zx_prov_PMDelete_s* x, int free_strs)
{
  /* *** deal with xmlns specifications in exc c14n way */


  {
      struct zx_prov_PMDeleteItem_s* e;
      struct zx_prov_PMDeleteItem_s* en;
      for (e = x->PMDeleteItem; e; e = en) {
	  en = (struct zx_prov_PMDeleteItem_s*)e->gg.g.n;
	  zx_FREE_prov_PMDeleteItem(c, e, free_strs);
      }
  }
  zx_free_simple_elems(c, x->NotifyTo, free_strs);


  zx_free_elem_common(c, &x->gg, free_strs); 
}

/* FUNC(zx_NEW_prov_PMDelete) */

/* Trivial allocator/constructor for the datatype. */

/* Called by: */
struct zx_prov_PMDelete_s* zx_NEW_prov_PMDelete(struct zx_ctx* c)
{
  struct zx_prov_PMDelete_s* x = ZX_ZALLOC(c, struct zx_prov_PMDelete_s);
  x->gg.g.tok = zx_prov_PMDelete_ELEM;
  return x;
}

#ifdef ZX_ENA_AUX

/* FUNC(zx_DUP_STRS_prov_PMDelete) */

/* Depth first traversal of data structure to copy its simple strings
 * to memory allocated from the memory allocator. The decoder will
 * use the underlying wireprotocol PDU buffer for strings, i.e.
 * strings are not copied - they point to the real data. If the
 * datastructure needs to outlast the protocol data or needs a different
 * memory allocation strategy, you need to call this function.  */

/* Called by: */
void zx_DUP_STRS_prov_PMDelete(struct zx_ctx* c, struct zx_prov_PMDelete_s* x)
{
  zx_dup_strs_common(c, &x->gg);
  /* *** deal with xmlns specifications in exc c14n way */


  {
      struct zx_prov_PMDeleteItem_s* e;
      for (e = x->PMDeleteItem; e; e = (struct zx_prov_PMDeleteItem_s*)e->gg.g.n)
	  zx_DUP_STRS_prov_PMDeleteItem(c, e);
  }
  zx_dup_strs_simple_elems(c, x->NotifyTo);

}

/* FUNC(zx_DEEP_CLONE_prov_PMDelete) */

/* Depth first traversal of data structure to clone it and its sublements.
 * The simple strings are handled as a special case according to dup_strs flag. */

/* Called by: */
struct zx_prov_PMDelete_s* zx_DEEP_CLONE_prov_PMDelete(struct zx_ctx* c, struct zx_prov_PMDelete_s* x, int dup_strs)
{
  x = (struct zx_prov_PMDelete_s*)zx_clone_elem_common(c, &x->gg, sizeof(struct zx_prov_PMDelete_s), dup_strs);
  /* *** deal with xmlns specifications in exc c14n way */


  {
      struct zx_prov_PMDeleteItem_s* e;
      struct zx_prov_PMDeleteItem_s* en;
      struct zx_prov_PMDeleteItem_s* enn;
      for (enn = 0, e = x->PMDeleteItem; e; e = (struct zx_prov_PMDeleteItem_s*)e->gg.g.n) {
	  en = zx_DEEP_CLONE_prov_PMDeleteItem(c, e, dup_strs);
	  if (!enn)
	      x->PMDeleteItem = en;
	  else
	      enn->gg.g.n = &en->gg.g;
	  enn = en;
      }
  }
  x->NotifyTo = zx_deep_clone_simple_elems(c,x->NotifyTo, dup_strs);

  return x;
}

/* FUNC(zx_WALK_SO_prov_PMDelete) */

/* Depth first traversal of the tree in either schema order or the wire order. */
 
int zx_WALK_SO_prov_PMDelete(struct zx_ctx* c, struct zx_prov_PMDelete_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
{
  int ret = callback(&x->gg.g, ctx);
  if (ret)
    return ret;
  
  /* *** deal with xmlns specifications in exc c14n way */


  
  ret = zx_walk_so_unknown_attributes(c, &x->gg, ctx, callback); 
  if (ret)
    return ret;

  {
      struct zx_prov_PMDeleteItem_s* e;
      for (e = x->PMDeleteItem; e; e = (struct zx_prov_PMDeleteItem_s*)e->gg.g.n) {
	  ret = zx_WALK_SO_prov_PMDeleteItem(c, e, ctx, callback);
	  if (ret)
	      return ret;
      }
  }
  ret = zx_walk_so_simple_elems(c, x->NotifyTo, ctx, callback);
  if (ret)
    return ret;

  
  return zx_walk_so_unknown_elems_and_content(c, &x->gg, ctx, callback);
}

/* FUNC(zx_WALK_WO_prov_PMDelete) */

int zx_WALK_WO_prov_PMDelete(struct zx_ctx* c, struct zx_prov_PMDelete_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
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

#define EL_NAME   prov_PMDeleteItem
#define EL_STRUCT zx_prov_PMDeleteItem_s
#define EL_NS     prov
#define EL_TAG    PMDeleteItem

/* FUNC(zx_FREE_prov_PMDeleteItem) */

/* Depth first traversal of data structure to free it and its subelements. Simple
 * strings are handled as a special case according to the free_strs flag. This
 * is useful if the strings point to underlying data from the wire that was
 * allocated differently. */

/* Called by: */
void zx_FREE_prov_PMDeleteItem(struct zx_ctx* c, struct zx_prov_PMDeleteItem_s* x, int free_strs)
{
  /* *** deal with xmlns specifications in exc c14n way */

  zx_free_attr(c, x->itemID, free_strs);

  {
      struct zx_prov_PMID_s* e;
      struct zx_prov_PMID_s* en;
      for (e = x->PMID; e; e = en) {
	  en = (struct zx_prov_PMID_s*)e->gg.g.n;
	  zx_FREE_prov_PMID(c, e, free_strs);
      }
  }


  zx_free_elem_common(c, &x->gg, free_strs); 
}

/* FUNC(zx_NEW_prov_PMDeleteItem) */

/* Trivial allocator/constructor for the datatype. */

/* Called by: */
struct zx_prov_PMDeleteItem_s* zx_NEW_prov_PMDeleteItem(struct zx_ctx* c)
{
  struct zx_prov_PMDeleteItem_s* x = ZX_ZALLOC(c, struct zx_prov_PMDeleteItem_s);
  x->gg.g.tok = zx_prov_PMDeleteItem_ELEM;
  return x;
}

#ifdef ZX_ENA_AUX

/* FUNC(zx_DUP_STRS_prov_PMDeleteItem) */

/* Depth first traversal of data structure to copy its simple strings
 * to memory allocated from the memory allocator. The decoder will
 * use the underlying wireprotocol PDU buffer for strings, i.e.
 * strings are not copied - they point to the real data. If the
 * datastructure needs to outlast the protocol data or needs a different
 * memory allocation strategy, you need to call this function.  */

/* Called by: */
void zx_DUP_STRS_prov_PMDeleteItem(struct zx_ctx* c, struct zx_prov_PMDeleteItem_s* x)
{
  zx_dup_strs_common(c, &x->gg);
  /* *** deal with xmlns specifications in exc c14n way */

  zx_dup_attr(c, x->itemID);

  {
      struct zx_prov_PMID_s* e;
      for (e = x->PMID; e; e = (struct zx_prov_PMID_s*)e->gg.g.n)
	  zx_DUP_STRS_prov_PMID(c, e);
  }

}

/* FUNC(zx_DEEP_CLONE_prov_PMDeleteItem) */

/* Depth first traversal of data structure to clone it and its sublements.
 * The simple strings are handled as a special case according to dup_strs flag. */

/* Called by: */
struct zx_prov_PMDeleteItem_s* zx_DEEP_CLONE_prov_PMDeleteItem(struct zx_ctx* c, struct zx_prov_PMDeleteItem_s* x, int dup_strs)
{
  x = (struct zx_prov_PMDeleteItem_s*)zx_clone_elem_common(c, &x->gg, sizeof(struct zx_prov_PMDeleteItem_s), dup_strs);
  /* *** deal with xmlns specifications in exc c14n way */

  x->itemID = zx_clone_attr(c, x->itemID);

  {
      struct zx_prov_PMID_s* e;
      struct zx_prov_PMID_s* en;
      struct zx_prov_PMID_s* enn;
      for (enn = 0, e = x->PMID; e; e = (struct zx_prov_PMID_s*)e->gg.g.n) {
	  en = zx_DEEP_CLONE_prov_PMID(c, e, dup_strs);
	  if (!enn)
	      x->PMID = en;
	  else
	      enn->gg.g.n = &en->gg.g;
	  enn = en;
      }
  }

  return x;
}

/* FUNC(zx_WALK_SO_prov_PMDeleteItem) */

/* Depth first traversal of the tree in either schema order or the wire order. */
 
int zx_WALK_SO_prov_PMDeleteItem(struct zx_ctx* c, struct zx_prov_PMDeleteItem_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
{
  int ret = callback(&x->gg.g, ctx);
  if (ret)
    return ret;
  
  /* *** deal with xmlns specifications in exc c14n way */


  
  ret = zx_walk_so_unknown_attributes(c, &x->gg, ctx, callback); 
  if (ret)
    return ret;

  {
      struct zx_prov_PMID_s* e;
      for (e = x->PMID; e; e = (struct zx_prov_PMID_s*)e->gg.g.n) {
	  ret = zx_WALK_SO_prov_PMID(c, e, ctx, callback);
	  if (ret)
	      return ret;
      }
  }

  
  return zx_walk_so_unknown_elems_and_content(c, &x->gg, ctx, callback);
}

/* FUNC(zx_WALK_WO_prov_PMDeleteItem) */

int zx_WALK_WO_prov_PMDeleteItem(struct zx_ctx* c, struct zx_prov_PMDeleteItem_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
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

#define EL_NAME   prov_PMDeleteResponse
#define EL_STRUCT zx_prov_PMDeleteResponse_s
#define EL_NS     prov
#define EL_TAG    PMDeleteResponse

/* FUNC(zx_FREE_prov_PMDeleteResponse) */

/* Depth first traversal of data structure to free it and its subelements. Simple
 * strings are handled as a special case according to the free_strs flag. This
 * is useful if the strings point to underlying data from the wire that was
 * allocated differently. */

/* Called by: */
void zx_FREE_prov_PMDeleteResponse(struct zx_ctx* c, struct zx_prov_PMDeleteResponse_s* x, int free_strs)
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

/* FUNC(zx_NEW_prov_PMDeleteResponse) */

/* Trivial allocator/constructor for the datatype. */

/* Called by: */
struct zx_prov_PMDeleteResponse_s* zx_NEW_prov_PMDeleteResponse(struct zx_ctx* c)
{
  struct zx_prov_PMDeleteResponse_s* x = ZX_ZALLOC(c, struct zx_prov_PMDeleteResponse_s);
  x->gg.g.tok = zx_prov_PMDeleteResponse_ELEM;
  return x;
}

#ifdef ZX_ENA_AUX

/* FUNC(zx_DUP_STRS_prov_PMDeleteResponse) */

/* Depth first traversal of data structure to copy its simple strings
 * to memory allocated from the memory allocator. The decoder will
 * use the underlying wireprotocol PDU buffer for strings, i.e.
 * strings are not copied - they point to the real data. If the
 * datastructure needs to outlast the protocol data or needs a different
 * memory allocation strategy, you need to call this function.  */

/* Called by: */
void zx_DUP_STRS_prov_PMDeleteResponse(struct zx_ctx* c, struct zx_prov_PMDeleteResponse_s* x)
{
  zx_dup_strs_common(c, &x->gg);
  /* *** deal with xmlns specifications in exc c14n way */


  {
      struct zx_lu_Status_s* e;
      for (e = x->Status; e; e = (struct zx_lu_Status_s*)e->gg.g.n)
	  zx_DUP_STRS_lu_Status(c, e);
  }

}

/* FUNC(zx_DEEP_CLONE_prov_PMDeleteResponse) */

/* Depth first traversal of data structure to clone it and its sublements.
 * The simple strings are handled as a special case according to dup_strs flag. */

/* Called by: */
struct zx_prov_PMDeleteResponse_s* zx_DEEP_CLONE_prov_PMDeleteResponse(struct zx_ctx* c, struct zx_prov_PMDeleteResponse_s* x, int dup_strs)
{
  x = (struct zx_prov_PMDeleteResponse_s*)zx_clone_elem_common(c, &x->gg, sizeof(struct zx_prov_PMDeleteResponse_s), dup_strs);
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

/* FUNC(zx_WALK_SO_prov_PMDeleteResponse) */

/* Depth first traversal of the tree in either schema order or the wire order. */
 
int zx_WALK_SO_prov_PMDeleteResponse(struct zx_ctx* c, struct zx_prov_PMDeleteResponse_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
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

/* FUNC(zx_WALK_WO_prov_PMDeleteResponse) */

int zx_WALK_WO_prov_PMDeleteResponse(struct zx_ctx* c, struct zx_prov_PMDeleteResponse_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
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

#define EL_NAME   prov_PMDescriptor
#define EL_STRUCT zx_prov_PMDescriptor_s
#define EL_NS     prov
#define EL_TAG    PMDescriptor

/* FUNC(zx_FREE_prov_PMDescriptor) */

/* Depth first traversal of data structure to free it and its subelements. Simple
 * strings are handled as a special case according to the free_strs flag. This
 * is useful if the strings point to underlying data from the wire that was
 * allocated differently. */

/* Called by: */
void zx_FREE_prov_PMDescriptor(struct zx_ctx* c, struct zx_prov_PMDescriptor_s* x, int free_strs)
{
  /* *** deal with xmlns specifications in exc c14n way */

  zx_free_attr(c, x->activate, free_strs);
  zx_free_attr(c, x->activateAt, free_strs);
  zx_free_attr(c, x->deactivateAt, free_strs);

  {
      struct zx_prov_PMID_s* e;
      struct zx_prov_PMID_s* en;
      for (e = x->PMID; e; e = en) {
	  en = (struct zx_prov_PMID_s*)e->gg.g.n;
	  zx_FREE_prov_PMID(c, e, free_strs);
      }
  }
  zx_free_simple_elems(c, x->PMEngineRef, free_strs);
  zx_free_simple_elems(c, x->PMInitData, free_strs);
  zx_free_simple_elems(c, x->PMRTData, free_strs);
  {
      struct zx_ds_Signature_s* e;
      struct zx_ds_Signature_s* en;
      for (e = x->Signature; e; e = en) {
	  en = (struct zx_ds_Signature_s*)e->gg.g.n;
	  zx_FREE_ds_Signature(c, e, free_strs);
      }
  }


  zx_free_elem_common(c, &x->gg, free_strs); 
}

/* FUNC(zx_NEW_prov_PMDescriptor) */

/* Trivial allocator/constructor for the datatype. */

/* Called by: */
struct zx_prov_PMDescriptor_s* zx_NEW_prov_PMDescriptor(struct zx_ctx* c)
{
  struct zx_prov_PMDescriptor_s* x = ZX_ZALLOC(c, struct zx_prov_PMDescriptor_s);
  x->gg.g.tok = zx_prov_PMDescriptor_ELEM;
  return x;
}

#ifdef ZX_ENA_AUX

/* FUNC(zx_DUP_STRS_prov_PMDescriptor) */

/* Depth first traversal of data structure to copy its simple strings
 * to memory allocated from the memory allocator. The decoder will
 * use the underlying wireprotocol PDU buffer for strings, i.e.
 * strings are not copied - they point to the real data. If the
 * datastructure needs to outlast the protocol data or needs a different
 * memory allocation strategy, you need to call this function.  */

/* Called by: */
void zx_DUP_STRS_prov_PMDescriptor(struct zx_ctx* c, struct zx_prov_PMDescriptor_s* x)
{
  zx_dup_strs_common(c, &x->gg);
  /* *** deal with xmlns specifications in exc c14n way */

  zx_dup_attr(c, x->activate);
  zx_dup_attr(c, x->activateAt);
  zx_dup_attr(c, x->deactivateAt);

  {
      struct zx_prov_PMID_s* e;
      for (e = x->PMID; e; e = (struct zx_prov_PMID_s*)e->gg.g.n)
	  zx_DUP_STRS_prov_PMID(c, e);
  }
  zx_dup_strs_simple_elems(c, x->PMEngineRef);
  zx_dup_strs_simple_elems(c, x->PMInitData);
  zx_dup_strs_simple_elems(c, x->PMRTData);
  {
      struct zx_ds_Signature_s* e;
      for (e = x->Signature; e; e = (struct zx_ds_Signature_s*)e->gg.g.n)
	  zx_DUP_STRS_ds_Signature(c, e);
  }

}

/* FUNC(zx_DEEP_CLONE_prov_PMDescriptor) */

/* Depth first traversal of data structure to clone it and its sublements.
 * The simple strings are handled as a special case according to dup_strs flag. */

/* Called by: */
struct zx_prov_PMDescriptor_s* zx_DEEP_CLONE_prov_PMDescriptor(struct zx_ctx* c, struct zx_prov_PMDescriptor_s* x, int dup_strs)
{
  x = (struct zx_prov_PMDescriptor_s*)zx_clone_elem_common(c, &x->gg, sizeof(struct zx_prov_PMDescriptor_s), dup_strs);
  /* *** deal with xmlns specifications in exc c14n way */

  x->activate = zx_clone_attr(c, x->activate);
  x->activateAt = zx_clone_attr(c, x->activateAt);
  x->deactivateAt = zx_clone_attr(c, x->deactivateAt);

  {
      struct zx_prov_PMID_s* e;
      struct zx_prov_PMID_s* en;
      struct zx_prov_PMID_s* enn;
      for (enn = 0, e = x->PMID; e; e = (struct zx_prov_PMID_s*)e->gg.g.n) {
	  en = zx_DEEP_CLONE_prov_PMID(c, e, dup_strs);
	  if (!enn)
	      x->PMID = en;
	  else
	      enn->gg.g.n = &en->gg.g;
	  enn = en;
      }
  }
  x->PMEngineRef = zx_deep_clone_simple_elems(c,x->PMEngineRef, dup_strs);
  x->PMInitData = zx_deep_clone_simple_elems(c,x->PMInitData, dup_strs);
  x->PMRTData = zx_deep_clone_simple_elems(c,x->PMRTData, dup_strs);
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

  return x;
}

/* FUNC(zx_WALK_SO_prov_PMDescriptor) */

/* Depth first traversal of the tree in either schema order or the wire order. */
 
int zx_WALK_SO_prov_PMDescriptor(struct zx_ctx* c, struct zx_prov_PMDescriptor_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
{
  int ret = callback(&x->gg.g, ctx);
  if (ret)
    return ret;
  
  /* *** deal with xmlns specifications in exc c14n way */


  
  ret = zx_walk_so_unknown_attributes(c, &x->gg, ctx, callback); 
  if (ret)
    return ret;

  {
      struct zx_prov_PMID_s* e;
      for (e = x->PMID; e; e = (struct zx_prov_PMID_s*)e->gg.g.n) {
	  ret = zx_WALK_SO_prov_PMID(c, e, ctx, callback);
	  if (ret)
	      return ret;
      }
  }
  ret = zx_walk_so_simple_elems(c, x->PMEngineRef, ctx, callback);
  if (ret)
    return ret;
  ret = zx_walk_so_simple_elems(c, x->PMInitData, ctx, callback);
  if (ret)
    return ret;
  ret = zx_walk_so_simple_elems(c, x->PMRTData, ctx, callback);
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

  
  return zx_walk_so_unknown_elems_and_content(c, &x->gg, ctx, callback);
}

/* FUNC(zx_WALK_WO_prov_PMDescriptor) */

int zx_WALK_WO_prov_PMDescriptor(struct zx_ctx* c, struct zx_prov_PMDescriptor_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
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

#define EL_NAME   prov_PMEDelete
#define EL_STRUCT zx_prov_PMEDelete_s
#define EL_NS     prov
#define EL_TAG    PMEDelete

/* FUNC(zx_FREE_prov_PMEDelete) */

/* Depth first traversal of data structure to free it and its subelements. Simple
 * strings are handled as a special case according to the free_strs flag. This
 * is useful if the strings point to underlying data from the wire that was
 * allocated differently. */

/* Called by: */
void zx_FREE_prov_PMEDelete(struct zx_ctx* c, struct zx_prov_PMEDelete_s* x, int free_strs)
{
  /* *** deal with xmlns specifications in exc c14n way */


  zx_free_simple_elems(c, x->PMEngineRef, free_strs);


  zx_free_elem_common(c, &x->gg, free_strs); 
}

/* FUNC(zx_NEW_prov_PMEDelete) */

/* Trivial allocator/constructor for the datatype. */

/* Called by: */
struct zx_prov_PMEDelete_s* zx_NEW_prov_PMEDelete(struct zx_ctx* c)
{
  struct zx_prov_PMEDelete_s* x = ZX_ZALLOC(c, struct zx_prov_PMEDelete_s);
  x->gg.g.tok = zx_prov_PMEDelete_ELEM;
  return x;
}

#ifdef ZX_ENA_AUX

/* FUNC(zx_DUP_STRS_prov_PMEDelete) */

/* Depth first traversal of data structure to copy its simple strings
 * to memory allocated from the memory allocator. The decoder will
 * use the underlying wireprotocol PDU buffer for strings, i.e.
 * strings are not copied - they point to the real data. If the
 * datastructure needs to outlast the protocol data or needs a different
 * memory allocation strategy, you need to call this function.  */

/* Called by: */
void zx_DUP_STRS_prov_PMEDelete(struct zx_ctx* c, struct zx_prov_PMEDelete_s* x)
{
  zx_dup_strs_common(c, &x->gg);
  /* *** deal with xmlns specifications in exc c14n way */


  zx_dup_strs_simple_elems(c, x->PMEngineRef);

}

/* FUNC(zx_DEEP_CLONE_prov_PMEDelete) */

/* Depth first traversal of data structure to clone it and its sublements.
 * The simple strings are handled as a special case according to dup_strs flag. */

/* Called by: */
struct zx_prov_PMEDelete_s* zx_DEEP_CLONE_prov_PMEDelete(struct zx_ctx* c, struct zx_prov_PMEDelete_s* x, int dup_strs)
{
  x = (struct zx_prov_PMEDelete_s*)zx_clone_elem_common(c, &x->gg, sizeof(struct zx_prov_PMEDelete_s), dup_strs);
  /* *** deal with xmlns specifications in exc c14n way */


  x->PMEngineRef = zx_deep_clone_simple_elems(c,x->PMEngineRef, dup_strs);

  return x;
}

/* FUNC(zx_WALK_SO_prov_PMEDelete) */

/* Depth first traversal of the tree in either schema order or the wire order. */
 
int zx_WALK_SO_prov_PMEDelete(struct zx_ctx* c, struct zx_prov_PMEDelete_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
{
  int ret = callback(&x->gg.g, ctx);
  if (ret)
    return ret;
  
  /* *** deal with xmlns specifications in exc c14n way */


  
  ret = zx_walk_so_unknown_attributes(c, &x->gg, ctx, callback); 
  if (ret)
    return ret;

  ret = zx_walk_so_simple_elems(c, x->PMEngineRef, ctx, callback);
  if (ret)
    return ret;

  
  return zx_walk_so_unknown_elems_and_content(c, &x->gg, ctx, callback);
}

/* FUNC(zx_WALK_WO_prov_PMEDelete) */

int zx_WALK_WO_prov_PMEDelete(struct zx_ctx* c, struct zx_prov_PMEDelete_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
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

#define EL_NAME   prov_PMEDeleteResponse
#define EL_STRUCT zx_prov_PMEDeleteResponse_s
#define EL_NS     prov
#define EL_TAG    PMEDeleteResponse

/* FUNC(zx_FREE_prov_PMEDeleteResponse) */

/* Depth first traversal of data structure to free it and its subelements. Simple
 * strings are handled as a special case according to the free_strs flag. This
 * is useful if the strings point to underlying data from the wire that was
 * allocated differently. */

/* Called by: */
void zx_FREE_prov_PMEDeleteResponse(struct zx_ctx* c, struct zx_prov_PMEDeleteResponse_s* x, int free_strs)
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

/* FUNC(zx_NEW_prov_PMEDeleteResponse) */

/* Trivial allocator/constructor for the datatype. */

/* Called by: */
struct zx_prov_PMEDeleteResponse_s* zx_NEW_prov_PMEDeleteResponse(struct zx_ctx* c)
{
  struct zx_prov_PMEDeleteResponse_s* x = ZX_ZALLOC(c, struct zx_prov_PMEDeleteResponse_s);
  x->gg.g.tok = zx_prov_PMEDeleteResponse_ELEM;
  return x;
}

#ifdef ZX_ENA_AUX

/* FUNC(zx_DUP_STRS_prov_PMEDeleteResponse) */

/* Depth first traversal of data structure to copy its simple strings
 * to memory allocated from the memory allocator. The decoder will
 * use the underlying wireprotocol PDU buffer for strings, i.e.
 * strings are not copied - they point to the real data. If the
 * datastructure needs to outlast the protocol data or needs a different
 * memory allocation strategy, you need to call this function.  */

/* Called by: */
void zx_DUP_STRS_prov_PMEDeleteResponse(struct zx_ctx* c, struct zx_prov_PMEDeleteResponse_s* x)
{
  zx_dup_strs_common(c, &x->gg);
  /* *** deal with xmlns specifications in exc c14n way */


  {
      struct zx_lu_Status_s* e;
      for (e = x->Status; e; e = (struct zx_lu_Status_s*)e->gg.g.n)
	  zx_DUP_STRS_lu_Status(c, e);
  }

}

/* FUNC(zx_DEEP_CLONE_prov_PMEDeleteResponse) */

/* Depth first traversal of data structure to clone it and its sublements.
 * The simple strings are handled as a special case according to dup_strs flag. */

/* Called by: */
struct zx_prov_PMEDeleteResponse_s* zx_DEEP_CLONE_prov_PMEDeleteResponse(struct zx_ctx* c, struct zx_prov_PMEDeleteResponse_s* x, int dup_strs)
{
  x = (struct zx_prov_PMEDeleteResponse_s*)zx_clone_elem_common(c, &x->gg, sizeof(struct zx_prov_PMEDeleteResponse_s), dup_strs);
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

/* FUNC(zx_WALK_SO_prov_PMEDeleteResponse) */

/* Depth first traversal of the tree in either schema order or the wire order. */
 
int zx_WALK_SO_prov_PMEDeleteResponse(struct zx_ctx* c, struct zx_prov_PMEDeleteResponse_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
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

/* FUNC(zx_WALK_WO_prov_PMEDeleteResponse) */

int zx_WALK_WO_prov_PMEDeleteResponse(struct zx_ctx* c, struct zx_prov_PMEDeleteResponse_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
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

#define EL_NAME   prov_PMEDisable
#define EL_STRUCT zx_prov_PMEDisable_s
#define EL_NS     prov
#define EL_TAG    PMEDisable

/* FUNC(zx_FREE_prov_PMEDisable) */

/* Depth first traversal of data structure to free it and its subelements. Simple
 * strings are handled as a special case according to the free_strs flag. This
 * is useful if the strings point to underlying data from the wire that was
 * allocated differently. */

/* Called by: */
void zx_FREE_prov_PMEDisable(struct zx_ctx* c, struct zx_prov_PMEDisable_s* x, int free_strs)
{
  /* *** deal with xmlns specifications in exc c14n way */


  zx_free_simple_elems(c, x->PMEngineRef, free_strs);


  zx_free_elem_common(c, &x->gg, free_strs); 
}

/* FUNC(zx_NEW_prov_PMEDisable) */

/* Trivial allocator/constructor for the datatype. */

/* Called by: */
struct zx_prov_PMEDisable_s* zx_NEW_prov_PMEDisable(struct zx_ctx* c)
{
  struct zx_prov_PMEDisable_s* x = ZX_ZALLOC(c, struct zx_prov_PMEDisable_s);
  x->gg.g.tok = zx_prov_PMEDisable_ELEM;
  return x;
}

#ifdef ZX_ENA_AUX

/* FUNC(zx_DUP_STRS_prov_PMEDisable) */

/* Depth first traversal of data structure to copy its simple strings
 * to memory allocated from the memory allocator. The decoder will
 * use the underlying wireprotocol PDU buffer for strings, i.e.
 * strings are not copied - they point to the real data. If the
 * datastructure needs to outlast the protocol data or needs a different
 * memory allocation strategy, you need to call this function.  */

/* Called by: */
void zx_DUP_STRS_prov_PMEDisable(struct zx_ctx* c, struct zx_prov_PMEDisable_s* x)
{
  zx_dup_strs_common(c, &x->gg);
  /* *** deal with xmlns specifications in exc c14n way */


  zx_dup_strs_simple_elems(c, x->PMEngineRef);

}

/* FUNC(zx_DEEP_CLONE_prov_PMEDisable) */

/* Depth first traversal of data structure to clone it and its sublements.
 * The simple strings are handled as a special case according to dup_strs flag. */

/* Called by: */
struct zx_prov_PMEDisable_s* zx_DEEP_CLONE_prov_PMEDisable(struct zx_ctx* c, struct zx_prov_PMEDisable_s* x, int dup_strs)
{
  x = (struct zx_prov_PMEDisable_s*)zx_clone_elem_common(c, &x->gg, sizeof(struct zx_prov_PMEDisable_s), dup_strs);
  /* *** deal with xmlns specifications in exc c14n way */


  x->PMEngineRef = zx_deep_clone_simple_elems(c,x->PMEngineRef, dup_strs);

  return x;
}

/* FUNC(zx_WALK_SO_prov_PMEDisable) */

/* Depth first traversal of the tree in either schema order or the wire order. */
 
int zx_WALK_SO_prov_PMEDisable(struct zx_ctx* c, struct zx_prov_PMEDisable_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
{
  int ret = callback(&x->gg.g, ctx);
  if (ret)
    return ret;
  
  /* *** deal with xmlns specifications in exc c14n way */


  
  ret = zx_walk_so_unknown_attributes(c, &x->gg, ctx, callback); 
  if (ret)
    return ret;

  ret = zx_walk_so_simple_elems(c, x->PMEngineRef, ctx, callback);
  if (ret)
    return ret;

  
  return zx_walk_so_unknown_elems_and_content(c, &x->gg, ctx, callback);
}

/* FUNC(zx_WALK_WO_prov_PMEDisable) */

int zx_WALK_WO_prov_PMEDisable(struct zx_ctx* c, struct zx_prov_PMEDisable_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
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

#define EL_NAME   prov_PMEDisableResponse
#define EL_STRUCT zx_prov_PMEDisableResponse_s
#define EL_NS     prov
#define EL_TAG    PMEDisableResponse

/* FUNC(zx_FREE_prov_PMEDisableResponse) */

/* Depth first traversal of data structure to free it and its subelements. Simple
 * strings are handled as a special case according to the free_strs flag. This
 * is useful if the strings point to underlying data from the wire that was
 * allocated differently. */

/* Called by: */
void zx_FREE_prov_PMEDisableResponse(struct zx_ctx* c, struct zx_prov_PMEDisableResponse_s* x, int free_strs)
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

/* FUNC(zx_NEW_prov_PMEDisableResponse) */

/* Trivial allocator/constructor for the datatype. */

/* Called by: */
struct zx_prov_PMEDisableResponse_s* zx_NEW_prov_PMEDisableResponse(struct zx_ctx* c)
{
  struct zx_prov_PMEDisableResponse_s* x = ZX_ZALLOC(c, struct zx_prov_PMEDisableResponse_s);
  x->gg.g.tok = zx_prov_PMEDisableResponse_ELEM;
  return x;
}

#ifdef ZX_ENA_AUX

/* FUNC(zx_DUP_STRS_prov_PMEDisableResponse) */

/* Depth first traversal of data structure to copy its simple strings
 * to memory allocated from the memory allocator. The decoder will
 * use the underlying wireprotocol PDU buffer for strings, i.e.
 * strings are not copied - they point to the real data. If the
 * datastructure needs to outlast the protocol data or needs a different
 * memory allocation strategy, you need to call this function.  */

/* Called by: */
void zx_DUP_STRS_prov_PMEDisableResponse(struct zx_ctx* c, struct zx_prov_PMEDisableResponse_s* x)
{
  zx_dup_strs_common(c, &x->gg);
  /* *** deal with xmlns specifications in exc c14n way */


  {
      struct zx_lu_Status_s* e;
      for (e = x->Status; e; e = (struct zx_lu_Status_s*)e->gg.g.n)
	  zx_DUP_STRS_lu_Status(c, e);
  }

}

/* FUNC(zx_DEEP_CLONE_prov_PMEDisableResponse) */

/* Depth first traversal of data structure to clone it and its sublements.
 * The simple strings are handled as a special case according to dup_strs flag. */

/* Called by: */
struct zx_prov_PMEDisableResponse_s* zx_DEEP_CLONE_prov_PMEDisableResponse(struct zx_ctx* c, struct zx_prov_PMEDisableResponse_s* x, int dup_strs)
{
  x = (struct zx_prov_PMEDisableResponse_s*)zx_clone_elem_common(c, &x->gg, sizeof(struct zx_prov_PMEDisableResponse_s), dup_strs);
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

/* FUNC(zx_WALK_SO_prov_PMEDisableResponse) */

/* Depth first traversal of the tree in either schema order or the wire order. */
 
int zx_WALK_SO_prov_PMEDisableResponse(struct zx_ctx* c, struct zx_prov_PMEDisableResponse_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
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

/* FUNC(zx_WALK_WO_prov_PMEDisableResponse) */

int zx_WALK_WO_prov_PMEDisableResponse(struct zx_ctx* c, struct zx_prov_PMEDisableResponse_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
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

#define EL_NAME   prov_PMEDownload
#define EL_STRUCT zx_prov_PMEDownload_s
#define EL_NS     prov
#define EL_TAG    PMEDownload

/* FUNC(zx_FREE_prov_PMEDownload) */

/* Depth first traversal of data structure to free it and its subelements. Simple
 * strings are handled as a special case according to the free_strs flag. This
 * is useful if the strings point to underlying data from the wire that was
 * allocated differently. */

/* Called by: */
void zx_FREE_prov_PMEDownload(struct zx_ctx* c, struct zx_prov_PMEDownload_s* x, int free_strs)
{
  /* *** deal with xmlns specifications in exc c14n way */


  zx_free_simple_elems(c, x->PMEngineRef, free_strs);


  zx_free_elem_common(c, &x->gg, free_strs); 
}

/* FUNC(zx_NEW_prov_PMEDownload) */

/* Trivial allocator/constructor for the datatype. */

/* Called by: */
struct zx_prov_PMEDownload_s* zx_NEW_prov_PMEDownload(struct zx_ctx* c)
{
  struct zx_prov_PMEDownload_s* x = ZX_ZALLOC(c, struct zx_prov_PMEDownload_s);
  x->gg.g.tok = zx_prov_PMEDownload_ELEM;
  return x;
}

#ifdef ZX_ENA_AUX

/* FUNC(zx_DUP_STRS_prov_PMEDownload) */

/* Depth first traversal of data structure to copy its simple strings
 * to memory allocated from the memory allocator. The decoder will
 * use the underlying wireprotocol PDU buffer for strings, i.e.
 * strings are not copied - they point to the real data. If the
 * datastructure needs to outlast the protocol data or needs a different
 * memory allocation strategy, you need to call this function.  */

/* Called by: */
void zx_DUP_STRS_prov_PMEDownload(struct zx_ctx* c, struct zx_prov_PMEDownload_s* x)
{
  zx_dup_strs_common(c, &x->gg);
  /* *** deal with xmlns specifications in exc c14n way */


  zx_dup_strs_simple_elems(c, x->PMEngineRef);

}

/* FUNC(zx_DEEP_CLONE_prov_PMEDownload) */

/* Depth first traversal of data structure to clone it and its sublements.
 * The simple strings are handled as a special case according to dup_strs flag. */

/* Called by: */
struct zx_prov_PMEDownload_s* zx_DEEP_CLONE_prov_PMEDownload(struct zx_ctx* c, struct zx_prov_PMEDownload_s* x, int dup_strs)
{
  x = (struct zx_prov_PMEDownload_s*)zx_clone_elem_common(c, &x->gg, sizeof(struct zx_prov_PMEDownload_s), dup_strs);
  /* *** deal with xmlns specifications in exc c14n way */


  x->PMEngineRef = zx_deep_clone_simple_elems(c,x->PMEngineRef, dup_strs);

  return x;
}

/* FUNC(zx_WALK_SO_prov_PMEDownload) */

/* Depth first traversal of the tree in either schema order or the wire order. */
 
int zx_WALK_SO_prov_PMEDownload(struct zx_ctx* c, struct zx_prov_PMEDownload_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
{
  int ret = callback(&x->gg.g, ctx);
  if (ret)
    return ret;
  
  /* *** deal with xmlns specifications in exc c14n way */


  
  ret = zx_walk_so_unknown_attributes(c, &x->gg, ctx, callback); 
  if (ret)
    return ret;

  ret = zx_walk_so_simple_elems(c, x->PMEngineRef, ctx, callback);
  if (ret)
    return ret;

  
  return zx_walk_so_unknown_elems_and_content(c, &x->gg, ctx, callback);
}

/* FUNC(zx_WALK_WO_prov_PMEDownload) */

int zx_WALK_WO_prov_PMEDownload(struct zx_ctx* c, struct zx_prov_PMEDownload_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
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

#define EL_NAME   prov_PMEDownloadResponse
#define EL_STRUCT zx_prov_PMEDownloadResponse_s
#define EL_NS     prov
#define EL_TAG    PMEDownloadResponse

/* FUNC(zx_FREE_prov_PMEDownloadResponse) */

/* Depth first traversal of data structure to free it and its subelements. Simple
 * strings are handled as a special case according to the free_strs flag. This
 * is useful if the strings point to underlying data from the wire that was
 * allocated differently. */

/* Called by: */
void zx_FREE_prov_PMEDownloadResponse(struct zx_ctx* c, struct zx_prov_PMEDownloadResponse_s* x, int free_strs)
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
  zx_free_simple_elems(c, x->EngineData, free_strs);


  zx_free_elem_common(c, &x->gg, free_strs); 
}

/* FUNC(zx_NEW_prov_PMEDownloadResponse) */

/* Trivial allocator/constructor for the datatype. */

/* Called by: */
struct zx_prov_PMEDownloadResponse_s* zx_NEW_prov_PMEDownloadResponse(struct zx_ctx* c)
{
  struct zx_prov_PMEDownloadResponse_s* x = ZX_ZALLOC(c, struct zx_prov_PMEDownloadResponse_s);
  x->gg.g.tok = zx_prov_PMEDownloadResponse_ELEM;
  return x;
}

#ifdef ZX_ENA_AUX

/* FUNC(zx_DUP_STRS_prov_PMEDownloadResponse) */

/* Depth first traversal of data structure to copy its simple strings
 * to memory allocated from the memory allocator. The decoder will
 * use the underlying wireprotocol PDU buffer for strings, i.e.
 * strings are not copied - they point to the real data. If the
 * datastructure needs to outlast the protocol data or needs a different
 * memory allocation strategy, you need to call this function.  */

/* Called by: */
void zx_DUP_STRS_prov_PMEDownloadResponse(struct zx_ctx* c, struct zx_prov_PMEDownloadResponse_s* x)
{
  zx_dup_strs_common(c, &x->gg);
  /* *** deal with xmlns specifications in exc c14n way */


  {
      struct zx_lu_Status_s* e;
      for (e = x->Status; e; e = (struct zx_lu_Status_s*)e->gg.g.n)
	  zx_DUP_STRS_lu_Status(c, e);
  }
  zx_dup_strs_simple_elems(c, x->EngineData);

}

/* FUNC(zx_DEEP_CLONE_prov_PMEDownloadResponse) */

/* Depth first traversal of data structure to clone it and its sublements.
 * The simple strings are handled as a special case according to dup_strs flag. */

/* Called by: */
struct zx_prov_PMEDownloadResponse_s* zx_DEEP_CLONE_prov_PMEDownloadResponse(struct zx_ctx* c, struct zx_prov_PMEDownloadResponse_s* x, int dup_strs)
{
  x = (struct zx_prov_PMEDownloadResponse_s*)zx_clone_elem_common(c, &x->gg, sizeof(struct zx_prov_PMEDownloadResponse_s), dup_strs);
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
  x->EngineData = zx_deep_clone_simple_elems(c,x->EngineData, dup_strs);

  return x;
}

/* FUNC(zx_WALK_SO_prov_PMEDownloadResponse) */

/* Depth first traversal of the tree in either schema order or the wire order. */
 
int zx_WALK_SO_prov_PMEDownloadResponse(struct zx_ctx* c, struct zx_prov_PMEDownloadResponse_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
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
  ret = zx_walk_so_simple_elems(c, x->EngineData, ctx, callback);
  if (ret)
    return ret;

  
  return zx_walk_so_unknown_elems_and_content(c, &x->gg, ctx, callback);
}

/* FUNC(zx_WALK_WO_prov_PMEDownloadResponse) */

int zx_WALK_WO_prov_PMEDownloadResponse(struct zx_ctx* c, struct zx_prov_PMEDownloadResponse_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
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

#define EL_NAME   prov_PMEEnable
#define EL_STRUCT zx_prov_PMEEnable_s
#define EL_NS     prov
#define EL_TAG    PMEEnable

/* FUNC(zx_FREE_prov_PMEEnable) */

/* Depth first traversal of data structure to free it and its subelements. Simple
 * strings are handled as a special case according to the free_strs flag. This
 * is useful if the strings point to underlying data from the wire that was
 * allocated differently. */

/* Called by: */
void zx_FREE_prov_PMEEnable(struct zx_ctx* c, struct zx_prov_PMEEnable_s* x, int free_strs)
{
  /* *** deal with xmlns specifications in exc c14n way */


  zx_free_simple_elems(c, x->PMEngineRef, free_strs);


  zx_free_elem_common(c, &x->gg, free_strs); 
}

/* FUNC(zx_NEW_prov_PMEEnable) */

/* Trivial allocator/constructor for the datatype. */

/* Called by: */
struct zx_prov_PMEEnable_s* zx_NEW_prov_PMEEnable(struct zx_ctx* c)
{
  struct zx_prov_PMEEnable_s* x = ZX_ZALLOC(c, struct zx_prov_PMEEnable_s);
  x->gg.g.tok = zx_prov_PMEEnable_ELEM;
  return x;
}

#ifdef ZX_ENA_AUX

/* FUNC(zx_DUP_STRS_prov_PMEEnable) */

/* Depth first traversal of data structure to copy its simple strings
 * to memory allocated from the memory allocator. The decoder will
 * use the underlying wireprotocol PDU buffer for strings, i.e.
 * strings are not copied - they point to the real data. If the
 * datastructure needs to outlast the protocol data or needs a different
 * memory allocation strategy, you need to call this function.  */

/* Called by: */
void zx_DUP_STRS_prov_PMEEnable(struct zx_ctx* c, struct zx_prov_PMEEnable_s* x)
{
  zx_dup_strs_common(c, &x->gg);
  /* *** deal with xmlns specifications in exc c14n way */


  zx_dup_strs_simple_elems(c, x->PMEngineRef);

}

/* FUNC(zx_DEEP_CLONE_prov_PMEEnable) */

/* Depth first traversal of data structure to clone it and its sublements.
 * The simple strings are handled as a special case according to dup_strs flag. */

/* Called by: */
struct zx_prov_PMEEnable_s* zx_DEEP_CLONE_prov_PMEEnable(struct zx_ctx* c, struct zx_prov_PMEEnable_s* x, int dup_strs)
{
  x = (struct zx_prov_PMEEnable_s*)zx_clone_elem_common(c, &x->gg, sizeof(struct zx_prov_PMEEnable_s), dup_strs);
  /* *** deal with xmlns specifications in exc c14n way */


  x->PMEngineRef = zx_deep_clone_simple_elems(c,x->PMEngineRef, dup_strs);

  return x;
}

/* FUNC(zx_WALK_SO_prov_PMEEnable) */

/* Depth first traversal of the tree in either schema order or the wire order. */
 
int zx_WALK_SO_prov_PMEEnable(struct zx_ctx* c, struct zx_prov_PMEEnable_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
{
  int ret = callback(&x->gg.g, ctx);
  if (ret)
    return ret;
  
  /* *** deal with xmlns specifications in exc c14n way */


  
  ret = zx_walk_so_unknown_attributes(c, &x->gg, ctx, callback); 
  if (ret)
    return ret;

  ret = zx_walk_so_simple_elems(c, x->PMEngineRef, ctx, callback);
  if (ret)
    return ret;

  
  return zx_walk_so_unknown_elems_and_content(c, &x->gg, ctx, callback);
}

/* FUNC(zx_WALK_WO_prov_PMEEnable) */

int zx_WALK_WO_prov_PMEEnable(struct zx_ctx* c, struct zx_prov_PMEEnable_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
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

#define EL_NAME   prov_PMEEnableResponse
#define EL_STRUCT zx_prov_PMEEnableResponse_s
#define EL_NS     prov
#define EL_TAG    PMEEnableResponse

/* FUNC(zx_FREE_prov_PMEEnableResponse) */

/* Depth first traversal of data structure to free it and its subelements. Simple
 * strings are handled as a special case according to the free_strs flag. This
 * is useful if the strings point to underlying data from the wire that was
 * allocated differently. */

/* Called by: */
void zx_FREE_prov_PMEEnableResponse(struct zx_ctx* c, struct zx_prov_PMEEnableResponse_s* x, int free_strs)
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

/* FUNC(zx_NEW_prov_PMEEnableResponse) */

/* Trivial allocator/constructor for the datatype. */

/* Called by: */
struct zx_prov_PMEEnableResponse_s* zx_NEW_prov_PMEEnableResponse(struct zx_ctx* c)
{
  struct zx_prov_PMEEnableResponse_s* x = ZX_ZALLOC(c, struct zx_prov_PMEEnableResponse_s);
  x->gg.g.tok = zx_prov_PMEEnableResponse_ELEM;
  return x;
}

#ifdef ZX_ENA_AUX

/* FUNC(zx_DUP_STRS_prov_PMEEnableResponse) */

/* Depth first traversal of data structure to copy its simple strings
 * to memory allocated from the memory allocator. The decoder will
 * use the underlying wireprotocol PDU buffer for strings, i.e.
 * strings are not copied - they point to the real data. If the
 * datastructure needs to outlast the protocol data or needs a different
 * memory allocation strategy, you need to call this function.  */

/* Called by: */
void zx_DUP_STRS_prov_PMEEnableResponse(struct zx_ctx* c, struct zx_prov_PMEEnableResponse_s* x)
{
  zx_dup_strs_common(c, &x->gg);
  /* *** deal with xmlns specifications in exc c14n way */


  {
      struct zx_lu_Status_s* e;
      for (e = x->Status; e; e = (struct zx_lu_Status_s*)e->gg.g.n)
	  zx_DUP_STRS_lu_Status(c, e);
  }

}

/* FUNC(zx_DEEP_CLONE_prov_PMEEnableResponse) */

/* Depth first traversal of data structure to clone it and its sublements.
 * The simple strings are handled as a special case according to dup_strs flag. */

/* Called by: */
struct zx_prov_PMEEnableResponse_s* zx_DEEP_CLONE_prov_PMEEnableResponse(struct zx_ctx* c, struct zx_prov_PMEEnableResponse_s* x, int dup_strs)
{
  x = (struct zx_prov_PMEEnableResponse_s*)zx_clone_elem_common(c, &x->gg, sizeof(struct zx_prov_PMEEnableResponse_s), dup_strs);
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

/* FUNC(zx_WALK_SO_prov_PMEEnableResponse) */

/* Depth first traversal of the tree in either schema order or the wire order. */
 
int zx_WALK_SO_prov_PMEEnableResponse(struct zx_ctx* c, struct zx_prov_PMEEnableResponse_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
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

/* FUNC(zx_WALK_WO_prov_PMEEnableResponse) */

int zx_WALK_WO_prov_PMEEnableResponse(struct zx_ctx* c, struct zx_prov_PMEEnableResponse_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
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

#define EL_NAME   prov_PMEGetInfo
#define EL_STRUCT zx_prov_PMEGetInfo_s
#define EL_NS     prov
#define EL_TAG    PMEGetInfo

/* FUNC(zx_FREE_prov_PMEGetInfo) */

/* Depth first traversal of data structure to free it and its subelements. Simple
 * strings are handled as a special case according to the free_strs flag. This
 * is useful if the strings point to underlying data from the wire that was
 * allocated differently. */

/* Called by: */
void zx_FREE_prov_PMEGetInfo(struct zx_ctx* c, struct zx_prov_PMEGetInfo_s* x, int free_strs)
{
  /* *** deal with xmlns specifications in exc c14n way */


  zx_free_simple_elems(c, x->PMEngineRef, free_strs);


  zx_free_elem_common(c, &x->gg, free_strs); 
}

/* FUNC(zx_NEW_prov_PMEGetInfo) */

/* Trivial allocator/constructor for the datatype. */

/* Called by: */
struct zx_prov_PMEGetInfo_s* zx_NEW_prov_PMEGetInfo(struct zx_ctx* c)
{
  struct zx_prov_PMEGetInfo_s* x = ZX_ZALLOC(c, struct zx_prov_PMEGetInfo_s);
  x->gg.g.tok = zx_prov_PMEGetInfo_ELEM;
  return x;
}

#ifdef ZX_ENA_AUX

/* FUNC(zx_DUP_STRS_prov_PMEGetInfo) */

/* Depth first traversal of data structure to copy its simple strings
 * to memory allocated from the memory allocator. The decoder will
 * use the underlying wireprotocol PDU buffer for strings, i.e.
 * strings are not copied - they point to the real data. If the
 * datastructure needs to outlast the protocol data or needs a different
 * memory allocation strategy, you need to call this function.  */

/* Called by: */
void zx_DUP_STRS_prov_PMEGetInfo(struct zx_ctx* c, struct zx_prov_PMEGetInfo_s* x)
{
  zx_dup_strs_common(c, &x->gg);
  /* *** deal with xmlns specifications in exc c14n way */


  zx_dup_strs_simple_elems(c, x->PMEngineRef);

}

/* FUNC(zx_DEEP_CLONE_prov_PMEGetInfo) */

/* Depth first traversal of data structure to clone it and its sublements.
 * The simple strings are handled as a special case according to dup_strs flag. */

/* Called by: */
struct zx_prov_PMEGetInfo_s* zx_DEEP_CLONE_prov_PMEGetInfo(struct zx_ctx* c, struct zx_prov_PMEGetInfo_s* x, int dup_strs)
{
  x = (struct zx_prov_PMEGetInfo_s*)zx_clone_elem_common(c, &x->gg, sizeof(struct zx_prov_PMEGetInfo_s), dup_strs);
  /* *** deal with xmlns specifications in exc c14n way */


  x->PMEngineRef = zx_deep_clone_simple_elems(c,x->PMEngineRef, dup_strs);

  return x;
}

/* FUNC(zx_WALK_SO_prov_PMEGetInfo) */

/* Depth first traversal of the tree in either schema order or the wire order. */
 
int zx_WALK_SO_prov_PMEGetInfo(struct zx_ctx* c, struct zx_prov_PMEGetInfo_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
{
  int ret = callback(&x->gg.g, ctx);
  if (ret)
    return ret;
  
  /* *** deal with xmlns specifications in exc c14n way */


  
  ret = zx_walk_so_unknown_attributes(c, &x->gg, ctx, callback); 
  if (ret)
    return ret;

  ret = zx_walk_so_simple_elems(c, x->PMEngineRef, ctx, callback);
  if (ret)
    return ret;

  
  return zx_walk_so_unknown_elems_and_content(c, &x->gg, ctx, callback);
}

/* FUNC(zx_WALK_WO_prov_PMEGetInfo) */

int zx_WALK_WO_prov_PMEGetInfo(struct zx_ctx* c, struct zx_prov_PMEGetInfo_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
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

#define EL_NAME   prov_PMEGetInfoResponse
#define EL_STRUCT zx_prov_PMEGetInfoResponse_s
#define EL_NS     prov
#define EL_TAG    PMEGetInfoResponse

/* FUNC(zx_FREE_prov_PMEGetInfoResponse) */

/* Depth first traversal of data structure to free it and its subelements. Simple
 * strings are handled as a special case according to the free_strs flag. This
 * is useful if the strings point to underlying data from the wire that was
 * allocated differently. */

/* Called by: */
void zx_FREE_prov_PMEGetInfoResponse(struct zx_ctx* c, struct zx_prov_PMEGetInfoResponse_s* x, int free_strs)
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
      struct zx_prov_PMEInfo_s* e;
      struct zx_prov_PMEInfo_s* en;
      for (e = x->PMEInfo; e; e = en) {
	  en = (struct zx_prov_PMEInfo_s*)e->gg.g.n;
	  zx_FREE_prov_PMEInfo(c, e, free_strs);
      }
  }


  zx_free_elem_common(c, &x->gg, free_strs); 
}

/* FUNC(zx_NEW_prov_PMEGetInfoResponse) */

/* Trivial allocator/constructor for the datatype. */

/* Called by: */
struct zx_prov_PMEGetInfoResponse_s* zx_NEW_prov_PMEGetInfoResponse(struct zx_ctx* c)
{
  struct zx_prov_PMEGetInfoResponse_s* x = ZX_ZALLOC(c, struct zx_prov_PMEGetInfoResponse_s);
  x->gg.g.tok = zx_prov_PMEGetInfoResponse_ELEM;
  return x;
}

#ifdef ZX_ENA_AUX

/* FUNC(zx_DUP_STRS_prov_PMEGetInfoResponse) */

/* Depth first traversal of data structure to copy its simple strings
 * to memory allocated from the memory allocator. The decoder will
 * use the underlying wireprotocol PDU buffer for strings, i.e.
 * strings are not copied - they point to the real data. If the
 * datastructure needs to outlast the protocol data or needs a different
 * memory allocation strategy, you need to call this function.  */

/* Called by: */
void zx_DUP_STRS_prov_PMEGetInfoResponse(struct zx_ctx* c, struct zx_prov_PMEGetInfoResponse_s* x)
{
  zx_dup_strs_common(c, &x->gg);
  /* *** deal with xmlns specifications in exc c14n way */


  {
      struct zx_lu_Status_s* e;
      for (e = x->Status; e; e = (struct zx_lu_Status_s*)e->gg.g.n)
	  zx_DUP_STRS_lu_Status(c, e);
  }
  {
      struct zx_prov_PMEInfo_s* e;
      for (e = x->PMEInfo; e; e = (struct zx_prov_PMEInfo_s*)e->gg.g.n)
	  zx_DUP_STRS_prov_PMEInfo(c, e);
  }

}

/* FUNC(zx_DEEP_CLONE_prov_PMEGetInfoResponse) */

/* Depth first traversal of data structure to clone it and its sublements.
 * The simple strings are handled as a special case according to dup_strs flag. */

/* Called by: */
struct zx_prov_PMEGetInfoResponse_s* zx_DEEP_CLONE_prov_PMEGetInfoResponse(struct zx_ctx* c, struct zx_prov_PMEGetInfoResponse_s* x, int dup_strs)
{
  x = (struct zx_prov_PMEGetInfoResponse_s*)zx_clone_elem_common(c, &x->gg, sizeof(struct zx_prov_PMEGetInfoResponse_s), dup_strs);
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
      struct zx_prov_PMEInfo_s* e;
      struct zx_prov_PMEInfo_s* en;
      struct zx_prov_PMEInfo_s* enn;
      for (enn = 0, e = x->PMEInfo; e; e = (struct zx_prov_PMEInfo_s*)e->gg.g.n) {
	  en = zx_DEEP_CLONE_prov_PMEInfo(c, e, dup_strs);
	  if (!enn)
	      x->PMEInfo = en;
	  else
	      enn->gg.g.n = &en->gg.g;
	  enn = en;
      }
  }

  return x;
}

/* FUNC(zx_WALK_SO_prov_PMEGetInfoResponse) */

/* Depth first traversal of the tree in either schema order or the wire order. */
 
int zx_WALK_SO_prov_PMEGetInfoResponse(struct zx_ctx* c, struct zx_prov_PMEGetInfoResponse_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
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
      struct zx_prov_PMEInfo_s* e;
      for (e = x->PMEInfo; e; e = (struct zx_prov_PMEInfo_s*)e->gg.g.n) {
	  ret = zx_WALK_SO_prov_PMEInfo(c, e, ctx, callback);
	  if (ret)
	      return ret;
      }
  }

  
  return zx_walk_so_unknown_elems_and_content(c, &x->gg, ctx, callback);
}

/* FUNC(zx_WALK_WO_prov_PMEGetInfoResponse) */

int zx_WALK_WO_prov_PMEGetInfoResponse(struct zx_ctx* c, struct zx_prov_PMEGetInfoResponse_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
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

#define EL_NAME   prov_PMEHash
#define EL_STRUCT zx_prov_PMEHash_s
#define EL_NS     prov
#define EL_TAG    PMEHash

/* FUNC(zx_FREE_prov_PMEHash) */

/* Depth first traversal of data structure to free it and its subelements. Simple
 * strings are handled as a special case according to the free_strs flag. This
 * is useful if the strings point to underlying data from the wire that was
 * allocated differently. */

/* Called by: */
void zx_FREE_prov_PMEHash(struct zx_ctx* c, struct zx_prov_PMEHash_s* x, int free_strs)
{
  /* *** deal with xmlns specifications in exc c14n way */

  zx_free_attr(c, x->method, free_strs);



  zx_free_elem_common(c, &x->gg, free_strs); 
}

/* FUNC(zx_NEW_prov_PMEHash) */

/* Trivial allocator/constructor for the datatype. */

/* Called by: */
struct zx_prov_PMEHash_s* zx_NEW_prov_PMEHash(struct zx_ctx* c)
{
  struct zx_prov_PMEHash_s* x = ZX_ZALLOC(c, struct zx_prov_PMEHash_s);
  x->gg.g.tok = zx_prov_PMEHash_ELEM;
  return x;
}

#ifdef ZX_ENA_AUX

/* FUNC(zx_DUP_STRS_prov_PMEHash) */

/* Depth first traversal of data structure to copy its simple strings
 * to memory allocated from the memory allocator. The decoder will
 * use the underlying wireprotocol PDU buffer for strings, i.e.
 * strings are not copied - they point to the real data. If the
 * datastructure needs to outlast the protocol data or needs a different
 * memory allocation strategy, you need to call this function.  */

/* Called by: */
void zx_DUP_STRS_prov_PMEHash(struct zx_ctx* c, struct zx_prov_PMEHash_s* x)
{
  zx_dup_strs_common(c, &x->gg);
  /* *** deal with xmlns specifications in exc c14n way */

  zx_dup_attr(c, x->method);


}

/* FUNC(zx_DEEP_CLONE_prov_PMEHash) */

/* Depth first traversal of data structure to clone it and its sublements.
 * The simple strings are handled as a special case according to dup_strs flag. */

/* Called by: */
struct zx_prov_PMEHash_s* zx_DEEP_CLONE_prov_PMEHash(struct zx_ctx* c, struct zx_prov_PMEHash_s* x, int dup_strs)
{
  x = (struct zx_prov_PMEHash_s*)zx_clone_elem_common(c, &x->gg, sizeof(struct zx_prov_PMEHash_s), dup_strs);
  /* *** deal with xmlns specifications in exc c14n way */

  x->method = zx_clone_attr(c, x->method);


  return x;
}

/* FUNC(zx_WALK_SO_prov_PMEHash) */

/* Depth first traversal of the tree in either schema order or the wire order. */
 
int zx_WALK_SO_prov_PMEHash(struct zx_ctx* c, struct zx_prov_PMEHash_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
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

/* FUNC(zx_WALK_WO_prov_PMEHash) */

int zx_WALK_WO_prov_PMEHash(struct zx_ctx* c, struct zx_prov_PMEHash_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
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

#define EL_NAME   prov_PMEInfo
#define EL_STRUCT zx_prov_PMEInfo_s
#define EL_NS     prov
#define EL_TAG    PMEInfo

/* FUNC(zx_FREE_prov_PMEInfo) */

/* Depth first traversal of data structure to free it and its subelements. Simple
 * strings are handled as a special case according to the free_strs flag. This
 * is useful if the strings point to underlying data from the wire that was
 * allocated differently. */

/* Called by: */
void zx_FREE_prov_PMEInfo(struct zx_ctx* c, struct zx_prov_PMEInfo_s* x, int free_strs)
{
  /* *** deal with xmlns specifications in exc c14n way */


  zx_free_simple_elems(c, x->PMEngineRef, free_strs);
  zx_free_simple_elems(c, x->PMECreatorID, free_strs);
  zx_free_simple_elems(c, x->PMEWhenCreated, free_strs);
  zx_free_simple_elems(c, x->PMEEnabled, free_strs);
  zx_free_simple_elems(c, x->PMEWhenEnabled, free_strs);
  zx_free_simple_elems(c, x->PMESize, free_strs);
  {
      struct zx_prov_PMEHash_s* e;
      struct zx_prov_PMEHash_s* en;
      for (e = x->PMEHash; e; e = en) {
	  en = (struct zx_prov_PMEHash_s*)e->gg.g.n;
	  zx_FREE_prov_PMEHash(c, e, free_strs);
      }
  }


  zx_free_elem_common(c, &x->gg, free_strs); 
}

/* FUNC(zx_NEW_prov_PMEInfo) */

/* Trivial allocator/constructor for the datatype. */

/* Called by: */
struct zx_prov_PMEInfo_s* zx_NEW_prov_PMEInfo(struct zx_ctx* c)
{
  struct zx_prov_PMEInfo_s* x = ZX_ZALLOC(c, struct zx_prov_PMEInfo_s);
  x->gg.g.tok = zx_prov_PMEInfo_ELEM;
  return x;
}

#ifdef ZX_ENA_AUX

/* FUNC(zx_DUP_STRS_prov_PMEInfo) */

/* Depth first traversal of data structure to copy its simple strings
 * to memory allocated from the memory allocator. The decoder will
 * use the underlying wireprotocol PDU buffer for strings, i.e.
 * strings are not copied - they point to the real data. If the
 * datastructure needs to outlast the protocol data or needs a different
 * memory allocation strategy, you need to call this function.  */

/* Called by: */
void zx_DUP_STRS_prov_PMEInfo(struct zx_ctx* c, struct zx_prov_PMEInfo_s* x)
{
  zx_dup_strs_common(c, &x->gg);
  /* *** deal with xmlns specifications in exc c14n way */


  zx_dup_strs_simple_elems(c, x->PMEngineRef);
  zx_dup_strs_simple_elems(c, x->PMECreatorID);
  zx_dup_strs_simple_elems(c, x->PMEWhenCreated);
  zx_dup_strs_simple_elems(c, x->PMEEnabled);
  zx_dup_strs_simple_elems(c, x->PMEWhenEnabled);
  zx_dup_strs_simple_elems(c, x->PMESize);
  {
      struct zx_prov_PMEHash_s* e;
      for (e = x->PMEHash; e; e = (struct zx_prov_PMEHash_s*)e->gg.g.n)
	  zx_DUP_STRS_prov_PMEHash(c, e);
  }

}

/* FUNC(zx_DEEP_CLONE_prov_PMEInfo) */

/* Depth first traversal of data structure to clone it and its sublements.
 * The simple strings are handled as a special case according to dup_strs flag. */

/* Called by: */
struct zx_prov_PMEInfo_s* zx_DEEP_CLONE_prov_PMEInfo(struct zx_ctx* c, struct zx_prov_PMEInfo_s* x, int dup_strs)
{
  x = (struct zx_prov_PMEInfo_s*)zx_clone_elem_common(c, &x->gg, sizeof(struct zx_prov_PMEInfo_s), dup_strs);
  /* *** deal with xmlns specifications in exc c14n way */


  x->PMEngineRef = zx_deep_clone_simple_elems(c,x->PMEngineRef, dup_strs);
  x->PMECreatorID = zx_deep_clone_simple_elems(c,x->PMECreatorID, dup_strs);
  x->PMEWhenCreated = zx_deep_clone_simple_elems(c,x->PMEWhenCreated, dup_strs);
  x->PMEEnabled = zx_deep_clone_simple_elems(c,x->PMEEnabled, dup_strs);
  x->PMEWhenEnabled = zx_deep_clone_simple_elems(c,x->PMEWhenEnabled, dup_strs);
  x->PMESize = zx_deep_clone_simple_elems(c,x->PMESize, dup_strs);
  {
      struct zx_prov_PMEHash_s* e;
      struct zx_prov_PMEHash_s* en;
      struct zx_prov_PMEHash_s* enn;
      for (enn = 0, e = x->PMEHash; e; e = (struct zx_prov_PMEHash_s*)e->gg.g.n) {
	  en = zx_DEEP_CLONE_prov_PMEHash(c, e, dup_strs);
	  if (!enn)
	      x->PMEHash = en;
	  else
	      enn->gg.g.n = &en->gg.g;
	  enn = en;
      }
  }

  return x;
}

/* FUNC(zx_WALK_SO_prov_PMEInfo) */

/* Depth first traversal of the tree in either schema order or the wire order. */
 
int zx_WALK_SO_prov_PMEInfo(struct zx_ctx* c, struct zx_prov_PMEInfo_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
{
  int ret = callback(&x->gg.g, ctx);
  if (ret)
    return ret;
  
  /* *** deal with xmlns specifications in exc c14n way */


  
  ret = zx_walk_so_unknown_attributes(c, &x->gg, ctx, callback); 
  if (ret)
    return ret;

  ret = zx_walk_so_simple_elems(c, x->PMEngineRef, ctx, callback);
  if (ret)
    return ret;
  ret = zx_walk_so_simple_elems(c, x->PMECreatorID, ctx, callback);
  if (ret)
    return ret;
  ret = zx_walk_so_simple_elems(c, x->PMEWhenCreated, ctx, callback);
  if (ret)
    return ret;
  ret = zx_walk_so_simple_elems(c, x->PMEEnabled, ctx, callback);
  if (ret)
    return ret;
  ret = zx_walk_so_simple_elems(c, x->PMEWhenEnabled, ctx, callback);
  if (ret)
    return ret;
  ret = zx_walk_so_simple_elems(c, x->PMESize, ctx, callback);
  if (ret)
    return ret;
  {
      struct zx_prov_PMEHash_s* e;
      for (e = x->PMEHash; e; e = (struct zx_prov_PMEHash_s*)e->gg.g.n) {
	  ret = zx_WALK_SO_prov_PMEHash(c, e, ctx, callback);
	  if (ret)
	      return ret;
      }
  }

  
  return zx_walk_so_unknown_elems_and_content(c, &x->gg, ctx, callback);
}

/* FUNC(zx_WALK_WO_prov_PMEInfo) */

int zx_WALK_WO_prov_PMEInfo(struct zx_ctx* c, struct zx_prov_PMEInfo_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
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

#define EL_NAME   prov_PMERegister
#define EL_STRUCT zx_prov_PMERegister_s
#define EL_NS     prov
#define EL_TAG    PMERegister

/* FUNC(zx_FREE_prov_PMERegister) */

/* Depth first traversal of data structure to free it and its subelements. Simple
 * strings are handled as a special case according to the free_strs flag. This
 * is useful if the strings point to underlying data from the wire that was
 * allocated differently. */

/* Called by: */
void zx_FREE_prov_PMERegister(struct zx_ctx* c, struct zx_prov_PMERegister_s* x, int free_strs)
{
  /* *** deal with xmlns specifications in exc c14n way */


  zx_free_simple_elems(c, x->PMEngineRef, free_strs);
  zx_free_simple_elems(c, x->PMESize, free_strs);
  {
      struct zx_prov_PMEHash_s* e;
      struct zx_prov_PMEHash_s* en;
      for (e = x->PMEHash; e; e = en) {
	  en = (struct zx_prov_PMEHash_s*)e->gg.g.n;
	  zx_FREE_prov_PMEHash(c, e, free_strs);
      }
  }


  zx_free_elem_common(c, &x->gg, free_strs); 
}

/* FUNC(zx_NEW_prov_PMERegister) */

/* Trivial allocator/constructor for the datatype. */

/* Called by: */
struct zx_prov_PMERegister_s* zx_NEW_prov_PMERegister(struct zx_ctx* c)
{
  struct zx_prov_PMERegister_s* x = ZX_ZALLOC(c, struct zx_prov_PMERegister_s);
  x->gg.g.tok = zx_prov_PMERegister_ELEM;
  return x;
}

#ifdef ZX_ENA_AUX

/* FUNC(zx_DUP_STRS_prov_PMERegister) */

/* Depth first traversal of data structure to copy its simple strings
 * to memory allocated from the memory allocator. The decoder will
 * use the underlying wireprotocol PDU buffer for strings, i.e.
 * strings are not copied - they point to the real data. If the
 * datastructure needs to outlast the protocol data or needs a different
 * memory allocation strategy, you need to call this function.  */

/* Called by: */
void zx_DUP_STRS_prov_PMERegister(struct zx_ctx* c, struct zx_prov_PMERegister_s* x)
{
  zx_dup_strs_common(c, &x->gg);
  /* *** deal with xmlns specifications in exc c14n way */


  zx_dup_strs_simple_elems(c, x->PMEngineRef);
  zx_dup_strs_simple_elems(c, x->PMESize);
  {
      struct zx_prov_PMEHash_s* e;
      for (e = x->PMEHash; e; e = (struct zx_prov_PMEHash_s*)e->gg.g.n)
	  zx_DUP_STRS_prov_PMEHash(c, e);
  }

}

/* FUNC(zx_DEEP_CLONE_prov_PMERegister) */

/* Depth first traversal of data structure to clone it and its sublements.
 * The simple strings are handled as a special case according to dup_strs flag. */

/* Called by: */
struct zx_prov_PMERegister_s* zx_DEEP_CLONE_prov_PMERegister(struct zx_ctx* c, struct zx_prov_PMERegister_s* x, int dup_strs)
{
  x = (struct zx_prov_PMERegister_s*)zx_clone_elem_common(c, &x->gg, sizeof(struct zx_prov_PMERegister_s), dup_strs);
  /* *** deal with xmlns specifications in exc c14n way */


  x->PMEngineRef = zx_deep_clone_simple_elems(c,x->PMEngineRef, dup_strs);
  x->PMESize = zx_deep_clone_simple_elems(c,x->PMESize, dup_strs);
  {
      struct zx_prov_PMEHash_s* e;
      struct zx_prov_PMEHash_s* en;
      struct zx_prov_PMEHash_s* enn;
      for (enn = 0, e = x->PMEHash; e; e = (struct zx_prov_PMEHash_s*)e->gg.g.n) {
	  en = zx_DEEP_CLONE_prov_PMEHash(c, e, dup_strs);
	  if (!enn)
	      x->PMEHash = en;
	  else
	      enn->gg.g.n = &en->gg.g;
	  enn = en;
      }
  }

  return x;
}

/* FUNC(zx_WALK_SO_prov_PMERegister) */

/* Depth first traversal of the tree in either schema order or the wire order. */
 
int zx_WALK_SO_prov_PMERegister(struct zx_ctx* c, struct zx_prov_PMERegister_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
{
  int ret = callback(&x->gg.g, ctx);
  if (ret)
    return ret;
  
  /* *** deal with xmlns specifications in exc c14n way */


  
  ret = zx_walk_so_unknown_attributes(c, &x->gg, ctx, callback); 
  if (ret)
    return ret;

  ret = zx_walk_so_simple_elems(c, x->PMEngineRef, ctx, callback);
  if (ret)
    return ret;
  ret = zx_walk_so_simple_elems(c, x->PMESize, ctx, callback);
  if (ret)
    return ret;
  {
      struct zx_prov_PMEHash_s* e;
      for (e = x->PMEHash; e; e = (struct zx_prov_PMEHash_s*)e->gg.g.n) {
	  ret = zx_WALK_SO_prov_PMEHash(c, e, ctx, callback);
	  if (ret)
	      return ret;
      }
  }

  
  return zx_walk_so_unknown_elems_and_content(c, &x->gg, ctx, callback);
}

/* FUNC(zx_WALK_WO_prov_PMERegister) */

int zx_WALK_WO_prov_PMERegister(struct zx_ctx* c, struct zx_prov_PMERegister_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
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

#define EL_NAME   prov_PMERegisterResponse
#define EL_STRUCT zx_prov_PMERegisterResponse_s
#define EL_NS     prov
#define EL_TAG    PMERegisterResponse

/* FUNC(zx_FREE_prov_PMERegisterResponse) */

/* Depth first traversal of data structure to free it and its subelements. Simple
 * strings are handled as a special case according to the free_strs flag. This
 * is useful if the strings point to underlying data from the wire that was
 * allocated differently. */

/* Called by: */
void zx_FREE_prov_PMERegisterResponse(struct zx_ctx* c, struct zx_prov_PMERegisterResponse_s* x, int free_strs)
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
  zx_free_simple_elems(c, x->PMEUploadMax, free_strs);


  zx_free_elem_common(c, &x->gg, free_strs); 
}

/* FUNC(zx_NEW_prov_PMERegisterResponse) */

/* Trivial allocator/constructor for the datatype. */

/* Called by: */
struct zx_prov_PMERegisterResponse_s* zx_NEW_prov_PMERegisterResponse(struct zx_ctx* c)
{
  struct zx_prov_PMERegisterResponse_s* x = ZX_ZALLOC(c, struct zx_prov_PMERegisterResponse_s);
  x->gg.g.tok = zx_prov_PMERegisterResponse_ELEM;
  return x;
}

#ifdef ZX_ENA_AUX

/* FUNC(zx_DUP_STRS_prov_PMERegisterResponse) */

/* Depth first traversal of data structure to copy its simple strings
 * to memory allocated from the memory allocator. The decoder will
 * use the underlying wireprotocol PDU buffer for strings, i.e.
 * strings are not copied - they point to the real data. If the
 * datastructure needs to outlast the protocol data or needs a different
 * memory allocation strategy, you need to call this function.  */

/* Called by: */
void zx_DUP_STRS_prov_PMERegisterResponse(struct zx_ctx* c, struct zx_prov_PMERegisterResponse_s* x)
{
  zx_dup_strs_common(c, &x->gg);
  /* *** deal with xmlns specifications in exc c14n way */


  {
      struct zx_lu_Status_s* e;
      for (e = x->Status; e; e = (struct zx_lu_Status_s*)e->gg.g.n)
	  zx_DUP_STRS_lu_Status(c, e);
  }
  zx_dup_strs_simple_elems(c, x->PMEUploadMax);

}

/* FUNC(zx_DEEP_CLONE_prov_PMERegisterResponse) */

/* Depth first traversal of data structure to clone it and its sublements.
 * The simple strings are handled as a special case according to dup_strs flag. */

/* Called by: */
struct zx_prov_PMERegisterResponse_s* zx_DEEP_CLONE_prov_PMERegisterResponse(struct zx_ctx* c, struct zx_prov_PMERegisterResponse_s* x, int dup_strs)
{
  x = (struct zx_prov_PMERegisterResponse_s*)zx_clone_elem_common(c, &x->gg, sizeof(struct zx_prov_PMERegisterResponse_s), dup_strs);
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
  x->PMEUploadMax = zx_deep_clone_simple_elems(c,x->PMEUploadMax, dup_strs);

  return x;
}

/* FUNC(zx_WALK_SO_prov_PMERegisterResponse) */

/* Depth first traversal of the tree in either schema order or the wire order. */
 
int zx_WALK_SO_prov_PMERegisterResponse(struct zx_ctx* c, struct zx_prov_PMERegisterResponse_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
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
  ret = zx_walk_so_simple_elems(c, x->PMEUploadMax, ctx, callback);
  if (ret)
    return ret;

  
  return zx_walk_so_unknown_elems_and_content(c, &x->gg, ctx, callback);
}

/* FUNC(zx_WALK_WO_prov_PMERegisterResponse) */

int zx_WALK_WO_prov_PMERegisterResponse(struct zx_ctx* c, struct zx_prov_PMERegisterResponse_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
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

#define EL_NAME   prov_PMEUpload
#define EL_STRUCT zx_prov_PMEUpload_s
#define EL_NS     prov
#define EL_TAG    PMEUpload

/* FUNC(zx_FREE_prov_PMEUpload) */

/* Depth first traversal of data structure to free it and its subelements. Simple
 * strings are handled as a special case according to the free_strs flag. This
 * is useful if the strings point to underlying data from the wire that was
 * allocated differently. */

/* Called by: */
void zx_FREE_prov_PMEUpload(struct zx_ctx* c, struct zx_prov_PMEUpload_s* x, int free_strs)
{
  /* *** deal with xmlns specifications in exc c14n way */

  zx_free_attr(c, x->offset, free_strs);
  zx_free_attr(c, x->remaining, free_strs);

  zx_free_simple_elems(c, x->PMEngineRef, free_strs);
  zx_free_simple_elems(c, x->EngineData, free_strs);


  zx_free_elem_common(c, &x->gg, free_strs); 
}

/* FUNC(zx_NEW_prov_PMEUpload) */

/* Trivial allocator/constructor for the datatype. */

/* Called by: */
struct zx_prov_PMEUpload_s* zx_NEW_prov_PMEUpload(struct zx_ctx* c)
{
  struct zx_prov_PMEUpload_s* x = ZX_ZALLOC(c, struct zx_prov_PMEUpload_s);
  x->gg.g.tok = zx_prov_PMEUpload_ELEM;
  return x;
}

#ifdef ZX_ENA_AUX

/* FUNC(zx_DUP_STRS_prov_PMEUpload) */

/* Depth first traversal of data structure to copy its simple strings
 * to memory allocated from the memory allocator. The decoder will
 * use the underlying wireprotocol PDU buffer for strings, i.e.
 * strings are not copied - they point to the real data. If the
 * datastructure needs to outlast the protocol data or needs a different
 * memory allocation strategy, you need to call this function.  */

/* Called by: */
void zx_DUP_STRS_prov_PMEUpload(struct zx_ctx* c, struct zx_prov_PMEUpload_s* x)
{
  zx_dup_strs_common(c, &x->gg);
  /* *** deal with xmlns specifications in exc c14n way */

  zx_dup_attr(c, x->offset);
  zx_dup_attr(c, x->remaining);

  zx_dup_strs_simple_elems(c, x->PMEngineRef);
  zx_dup_strs_simple_elems(c, x->EngineData);

}

/* FUNC(zx_DEEP_CLONE_prov_PMEUpload) */

/* Depth first traversal of data structure to clone it and its sublements.
 * The simple strings are handled as a special case according to dup_strs flag. */

/* Called by: */
struct zx_prov_PMEUpload_s* zx_DEEP_CLONE_prov_PMEUpload(struct zx_ctx* c, struct zx_prov_PMEUpload_s* x, int dup_strs)
{
  x = (struct zx_prov_PMEUpload_s*)zx_clone_elem_common(c, &x->gg, sizeof(struct zx_prov_PMEUpload_s), dup_strs);
  /* *** deal with xmlns specifications in exc c14n way */

  x->offset = zx_clone_attr(c, x->offset);
  x->remaining = zx_clone_attr(c, x->remaining);

  x->PMEngineRef = zx_deep_clone_simple_elems(c,x->PMEngineRef, dup_strs);
  x->EngineData = zx_deep_clone_simple_elems(c,x->EngineData, dup_strs);

  return x;
}

/* FUNC(zx_WALK_SO_prov_PMEUpload) */

/* Depth first traversal of the tree in either schema order or the wire order. */
 
int zx_WALK_SO_prov_PMEUpload(struct zx_ctx* c, struct zx_prov_PMEUpload_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
{
  int ret = callback(&x->gg.g, ctx);
  if (ret)
    return ret;
  
  /* *** deal with xmlns specifications in exc c14n way */


  
  ret = zx_walk_so_unknown_attributes(c, &x->gg, ctx, callback); 
  if (ret)
    return ret;

  ret = zx_walk_so_simple_elems(c, x->PMEngineRef, ctx, callback);
  if (ret)
    return ret;
  ret = zx_walk_so_simple_elems(c, x->EngineData, ctx, callback);
  if (ret)
    return ret;

  
  return zx_walk_so_unknown_elems_and_content(c, &x->gg, ctx, callback);
}

/* FUNC(zx_WALK_WO_prov_PMEUpload) */

int zx_WALK_WO_prov_PMEUpload(struct zx_ctx* c, struct zx_prov_PMEUpload_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
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

#define EL_NAME   prov_PMEUploadResponse
#define EL_STRUCT zx_prov_PMEUploadResponse_s
#define EL_NS     prov
#define EL_TAG    PMEUploadResponse

/* FUNC(zx_FREE_prov_PMEUploadResponse) */

/* Depth first traversal of data structure to free it and its subelements. Simple
 * strings are handled as a special case according to the free_strs flag. This
 * is useful if the strings point to underlying data from the wire that was
 * allocated differently. */

/* Called by: */
void zx_FREE_prov_PMEUploadResponse(struct zx_ctx* c, struct zx_prov_PMEUploadResponse_s* x, int free_strs)
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

/* FUNC(zx_NEW_prov_PMEUploadResponse) */

/* Trivial allocator/constructor for the datatype. */

/* Called by: */
struct zx_prov_PMEUploadResponse_s* zx_NEW_prov_PMEUploadResponse(struct zx_ctx* c)
{
  struct zx_prov_PMEUploadResponse_s* x = ZX_ZALLOC(c, struct zx_prov_PMEUploadResponse_s);
  x->gg.g.tok = zx_prov_PMEUploadResponse_ELEM;
  return x;
}

#ifdef ZX_ENA_AUX

/* FUNC(zx_DUP_STRS_prov_PMEUploadResponse) */

/* Depth first traversal of data structure to copy its simple strings
 * to memory allocated from the memory allocator. The decoder will
 * use the underlying wireprotocol PDU buffer for strings, i.e.
 * strings are not copied - they point to the real data. If the
 * datastructure needs to outlast the protocol data or needs a different
 * memory allocation strategy, you need to call this function.  */

/* Called by: */
void zx_DUP_STRS_prov_PMEUploadResponse(struct zx_ctx* c, struct zx_prov_PMEUploadResponse_s* x)
{
  zx_dup_strs_common(c, &x->gg);
  /* *** deal with xmlns specifications in exc c14n way */


  {
      struct zx_lu_Status_s* e;
      for (e = x->Status; e; e = (struct zx_lu_Status_s*)e->gg.g.n)
	  zx_DUP_STRS_lu_Status(c, e);
  }

}

/* FUNC(zx_DEEP_CLONE_prov_PMEUploadResponse) */

/* Depth first traversal of data structure to clone it and its sublements.
 * The simple strings are handled as a special case according to dup_strs flag. */

/* Called by: */
struct zx_prov_PMEUploadResponse_s* zx_DEEP_CLONE_prov_PMEUploadResponse(struct zx_ctx* c, struct zx_prov_PMEUploadResponse_s* x, int dup_strs)
{
  x = (struct zx_prov_PMEUploadResponse_s*)zx_clone_elem_common(c, &x->gg, sizeof(struct zx_prov_PMEUploadResponse_s), dup_strs);
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

/* FUNC(zx_WALK_SO_prov_PMEUploadResponse) */

/* Depth first traversal of the tree in either schema order or the wire order. */
 
int zx_WALK_SO_prov_PMEUploadResponse(struct zx_ctx* c, struct zx_prov_PMEUploadResponse_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
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

/* FUNC(zx_WALK_WO_prov_PMEUploadResponse) */

int zx_WALK_WO_prov_PMEUploadResponse(struct zx_ctx* c, struct zx_prov_PMEUploadResponse_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
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

#define EL_NAME   prov_PMGetDescriptor
#define EL_STRUCT zx_prov_PMGetDescriptor_s
#define EL_NS     prov
#define EL_TAG    PMGetDescriptor

/* FUNC(zx_FREE_prov_PMGetDescriptor) */

/* Depth first traversal of data structure to free it and its subelements. Simple
 * strings are handled as a special case according to the free_strs flag. This
 * is useful if the strings point to underlying data from the wire that was
 * allocated differently. */

/* Called by: */
void zx_FREE_prov_PMGetDescriptor(struct zx_ctx* c, struct zx_prov_PMGetDescriptor_s* x, int free_strs)
{
  /* *** deal with xmlns specifications in exc c14n way */


  zx_free_simple_elems(c, x->PMDArtifact, free_strs);
  {
      struct zx_prov_CallbackEPR_s* e;
      struct zx_prov_CallbackEPR_s* en;
      for (e = x->CallbackEPR; e; e = en) {
	  en = (struct zx_prov_CallbackEPR_s*)e->gg.g.n;
	  zx_FREE_prov_CallbackEPR(c, e, free_strs);
      }
  }


  zx_free_elem_common(c, &x->gg, free_strs); 
}

/* FUNC(zx_NEW_prov_PMGetDescriptor) */

/* Trivial allocator/constructor for the datatype. */

/* Called by: */
struct zx_prov_PMGetDescriptor_s* zx_NEW_prov_PMGetDescriptor(struct zx_ctx* c)
{
  struct zx_prov_PMGetDescriptor_s* x = ZX_ZALLOC(c, struct zx_prov_PMGetDescriptor_s);
  x->gg.g.tok = zx_prov_PMGetDescriptor_ELEM;
  return x;
}

#ifdef ZX_ENA_AUX

/* FUNC(zx_DUP_STRS_prov_PMGetDescriptor) */

/* Depth first traversal of data structure to copy its simple strings
 * to memory allocated from the memory allocator. The decoder will
 * use the underlying wireprotocol PDU buffer for strings, i.e.
 * strings are not copied - they point to the real data. If the
 * datastructure needs to outlast the protocol data or needs a different
 * memory allocation strategy, you need to call this function.  */

/* Called by: */
void zx_DUP_STRS_prov_PMGetDescriptor(struct zx_ctx* c, struct zx_prov_PMGetDescriptor_s* x)
{
  zx_dup_strs_common(c, &x->gg);
  /* *** deal with xmlns specifications in exc c14n way */


  zx_dup_strs_simple_elems(c, x->PMDArtifact);
  {
      struct zx_prov_CallbackEPR_s* e;
      for (e = x->CallbackEPR; e; e = (struct zx_prov_CallbackEPR_s*)e->gg.g.n)
	  zx_DUP_STRS_prov_CallbackEPR(c, e);
  }

}

/* FUNC(zx_DEEP_CLONE_prov_PMGetDescriptor) */

/* Depth first traversal of data structure to clone it and its sublements.
 * The simple strings are handled as a special case according to dup_strs flag. */

/* Called by: */
struct zx_prov_PMGetDescriptor_s* zx_DEEP_CLONE_prov_PMGetDescriptor(struct zx_ctx* c, struct zx_prov_PMGetDescriptor_s* x, int dup_strs)
{
  x = (struct zx_prov_PMGetDescriptor_s*)zx_clone_elem_common(c, &x->gg, sizeof(struct zx_prov_PMGetDescriptor_s), dup_strs);
  /* *** deal with xmlns specifications in exc c14n way */


  x->PMDArtifact = zx_deep_clone_simple_elems(c,x->PMDArtifact, dup_strs);
  {
      struct zx_prov_CallbackEPR_s* e;
      struct zx_prov_CallbackEPR_s* en;
      struct zx_prov_CallbackEPR_s* enn;
      for (enn = 0, e = x->CallbackEPR; e; e = (struct zx_prov_CallbackEPR_s*)e->gg.g.n) {
	  en = zx_DEEP_CLONE_prov_CallbackEPR(c, e, dup_strs);
	  if (!enn)
	      x->CallbackEPR = en;
	  else
	      enn->gg.g.n = &en->gg.g;
	  enn = en;
      }
  }

  return x;
}

/* FUNC(zx_WALK_SO_prov_PMGetDescriptor) */

/* Depth first traversal of the tree in either schema order or the wire order. */
 
int zx_WALK_SO_prov_PMGetDescriptor(struct zx_ctx* c, struct zx_prov_PMGetDescriptor_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
{
  int ret = callback(&x->gg.g, ctx);
  if (ret)
    return ret;
  
  /* *** deal with xmlns specifications in exc c14n way */


  
  ret = zx_walk_so_unknown_attributes(c, &x->gg, ctx, callback); 
  if (ret)
    return ret;

  ret = zx_walk_so_simple_elems(c, x->PMDArtifact, ctx, callback);
  if (ret)
    return ret;
  {
      struct zx_prov_CallbackEPR_s* e;
      for (e = x->CallbackEPR; e; e = (struct zx_prov_CallbackEPR_s*)e->gg.g.n) {
	  ret = zx_WALK_SO_prov_CallbackEPR(c, e, ctx, callback);
	  if (ret)
	      return ret;
      }
  }

  
  return zx_walk_so_unknown_elems_and_content(c, &x->gg, ctx, callback);
}

/* FUNC(zx_WALK_WO_prov_PMGetDescriptor) */

int zx_WALK_WO_prov_PMGetDescriptor(struct zx_ctx* c, struct zx_prov_PMGetDescriptor_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
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

#define EL_NAME   prov_PMGetDescriptorResponse
#define EL_STRUCT zx_prov_PMGetDescriptorResponse_s
#define EL_NS     prov
#define EL_TAG    PMGetDescriptorResponse

/* FUNC(zx_FREE_prov_PMGetDescriptorResponse) */

/* Depth first traversal of data structure to free it and its subelements. Simple
 * strings are handled as a special case according to the free_strs flag. This
 * is useful if the strings point to underlying data from the wire that was
 * allocated differently. */

/* Called by: */
void zx_FREE_prov_PMGetDescriptorResponse(struct zx_ctx* c, struct zx_prov_PMGetDescriptorResponse_s* x, int free_strs)
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
      struct zx_prov_PMDescriptor_s* e;
      struct zx_prov_PMDescriptor_s* en;
      for (e = x->PMDescriptor; e; e = en) {
	  en = (struct zx_prov_PMDescriptor_s*)e->gg.g.n;
	  zx_FREE_prov_PMDescriptor(c, e, free_strs);
      }
  }


  zx_free_elem_common(c, &x->gg, free_strs); 
}

/* FUNC(zx_NEW_prov_PMGetDescriptorResponse) */

/* Trivial allocator/constructor for the datatype. */

/* Called by: */
struct zx_prov_PMGetDescriptorResponse_s* zx_NEW_prov_PMGetDescriptorResponse(struct zx_ctx* c)
{
  struct zx_prov_PMGetDescriptorResponse_s* x = ZX_ZALLOC(c, struct zx_prov_PMGetDescriptorResponse_s);
  x->gg.g.tok = zx_prov_PMGetDescriptorResponse_ELEM;
  return x;
}

#ifdef ZX_ENA_AUX

/* FUNC(zx_DUP_STRS_prov_PMGetDescriptorResponse) */

/* Depth first traversal of data structure to copy its simple strings
 * to memory allocated from the memory allocator. The decoder will
 * use the underlying wireprotocol PDU buffer for strings, i.e.
 * strings are not copied - they point to the real data. If the
 * datastructure needs to outlast the protocol data or needs a different
 * memory allocation strategy, you need to call this function.  */

/* Called by: */
void zx_DUP_STRS_prov_PMGetDescriptorResponse(struct zx_ctx* c, struct zx_prov_PMGetDescriptorResponse_s* x)
{
  zx_dup_strs_common(c, &x->gg);
  /* *** deal with xmlns specifications in exc c14n way */


  {
      struct zx_lu_Status_s* e;
      for (e = x->Status; e; e = (struct zx_lu_Status_s*)e->gg.g.n)
	  zx_DUP_STRS_lu_Status(c, e);
  }
  {
      struct zx_prov_PMDescriptor_s* e;
      for (e = x->PMDescriptor; e; e = (struct zx_prov_PMDescriptor_s*)e->gg.g.n)
	  zx_DUP_STRS_prov_PMDescriptor(c, e);
  }

}

/* FUNC(zx_DEEP_CLONE_prov_PMGetDescriptorResponse) */

/* Depth first traversal of data structure to clone it and its sublements.
 * The simple strings are handled as a special case according to dup_strs flag. */

/* Called by: */
struct zx_prov_PMGetDescriptorResponse_s* zx_DEEP_CLONE_prov_PMGetDescriptorResponse(struct zx_ctx* c, struct zx_prov_PMGetDescriptorResponse_s* x, int dup_strs)
{
  x = (struct zx_prov_PMGetDescriptorResponse_s*)zx_clone_elem_common(c, &x->gg, sizeof(struct zx_prov_PMGetDescriptorResponse_s), dup_strs);
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
      struct zx_prov_PMDescriptor_s* e;
      struct zx_prov_PMDescriptor_s* en;
      struct zx_prov_PMDescriptor_s* enn;
      for (enn = 0, e = x->PMDescriptor; e; e = (struct zx_prov_PMDescriptor_s*)e->gg.g.n) {
	  en = zx_DEEP_CLONE_prov_PMDescriptor(c, e, dup_strs);
	  if (!enn)
	      x->PMDescriptor = en;
	  else
	      enn->gg.g.n = &en->gg.g;
	  enn = en;
      }
  }

  return x;
}

/* FUNC(zx_WALK_SO_prov_PMGetDescriptorResponse) */

/* Depth first traversal of the tree in either schema order or the wire order. */
 
int zx_WALK_SO_prov_PMGetDescriptorResponse(struct zx_ctx* c, struct zx_prov_PMGetDescriptorResponse_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
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
      struct zx_prov_PMDescriptor_s* e;
      for (e = x->PMDescriptor; e; e = (struct zx_prov_PMDescriptor_s*)e->gg.g.n) {
	  ret = zx_WALK_SO_prov_PMDescriptor(c, e, ctx, callback);
	  if (ret)
	      return ret;
      }
  }

  
  return zx_walk_so_unknown_elems_and_content(c, &x->gg, ctx, callback);
}

/* FUNC(zx_WALK_WO_prov_PMGetDescriptorResponse) */

int zx_WALK_WO_prov_PMGetDescriptorResponse(struct zx_ctx* c, struct zx_prov_PMGetDescriptorResponse_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
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

#define EL_NAME   prov_PMGetStatus
#define EL_STRUCT zx_prov_PMGetStatus_s
#define EL_NS     prov
#define EL_TAG    PMGetStatus

/* FUNC(zx_FREE_prov_PMGetStatus) */

/* Depth first traversal of data structure to free it and its subelements. Simple
 * strings are handled as a special case according to the free_strs flag. This
 * is useful if the strings point to underlying data from the wire that was
 * allocated differently. */

/* Called by: */
void zx_FREE_prov_PMGetStatus(struct zx_ctx* c, struct zx_prov_PMGetStatus_s* x, int free_strs)
{
  /* *** deal with xmlns specifications in exc c14n way */


  {
      struct zx_prov_PMID_s* e;
      struct zx_prov_PMID_s* en;
      for (e = x->PMID; e; e = en) {
	  en = (struct zx_prov_PMID_s*)e->gg.g.n;
	  zx_FREE_prov_PMID(c, e, free_strs);
      }
  }


  zx_free_elem_common(c, &x->gg, free_strs); 
}

/* FUNC(zx_NEW_prov_PMGetStatus) */

/* Trivial allocator/constructor for the datatype. */

/* Called by: */
struct zx_prov_PMGetStatus_s* zx_NEW_prov_PMGetStatus(struct zx_ctx* c)
{
  struct zx_prov_PMGetStatus_s* x = ZX_ZALLOC(c, struct zx_prov_PMGetStatus_s);
  x->gg.g.tok = zx_prov_PMGetStatus_ELEM;
  return x;
}

#ifdef ZX_ENA_AUX

/* FUNC(zx_DUP_STRS_prov_PMGetStatus) */

/* Depth first traversal of data structure to copy its simple strings
 * to memory allocated from the memory allocator. The decoder will
 * use the underlying wireprotocol PDU buffer for strings, i.e.
 * strings are not copied - they point to the real data. If the
 * datastructure needs to outlast the protocol data or needs a different
 * memory allocation strategy, you need to call this function.  */

/* Called by: */
void zx_DUP_STRS_prov_PMGetStatus(struct zx_ctx* c, struct zx_prov_PMGetStatus_s* x)
{
  zx_dup_strs_common(c, &x->gg);
  /* *** deal with xmlns specifications in exc c14n way */


  {
      struct zx_prov_PMID_s* e;
      for (e = x->PMID; e; e = (struct zx_prov_PMID_s*)e->gg.g.n)
	  zx_DUP_STRS_prov_PMID(c, e);
  }

}

/* FUNC(zx_DEEP_CLONE_prov_PMGetStatus) */

/* Depth first traversal of data structure to clone it and its sublements.
 * The simple strings are handled as a special case according to dup_strs flag. */

/* Called by: */
struct zx_prov_PMGetStatus_s* zx_DEEP_CLONE_prov_PMGetStatus(struct zx_ctx* c, struct zx_prov_PMGetStatus_s* x, int dup_strs)
{
  x = (struct zx_prov_PMGetStatus_s*)zx_clone_elem_common(c, &x->gg, sizeof(struct zx_prov_PMGetStatus_s), dup_strs);
  /* *** deal with xmlns specifications in exc c14n way */


  {
      struct zx_prov_PMID_s* e;
      struct zx_prov_PMID_s* en;
      struct zx_prov_PMID_s* enn;
      for (enn = 0, e = x->PMID; e; e = (struct zx_prov_PMID_s*)e->gg.g.n) {
	  en = zx_DEEP_CLONE_prov_PMID(c, e, dup_strs);
	  if (!enn)
	      x->PMID = en;
	  else
	      enn->gg.g.n = &en->gg.g;
	  enn = en;
      }
  }

  return x;
}

/* FUNC(zx_WALK_SO_prov_PMGetStatus) */

/* Depth first traversal of the tree in either schema order or the wire order. */
 
int zx_WALK_SO_prov_PMGetStatus(struct zx_ctx* c, struct zx_prov_PMGetStatus_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
{
  int ret = callback(&x->gg.g, ctx);
  if (ret)
    return ret;
  
  /* *** deal with xmlns specifications in exc c14n way */


  
  ret = zx_walk_so_unknown_attributes(c, &x->gg, ctx, callback); 
  if (ret)
    return ret;

  {
      struct zx_prov_PMID_s* e;
      for (e = x->PMID; e; e = (struct zx_prov_PMID_s*)e->gg.g.n) {
	  ret = zx_WALK_SO_prov_PMID(c, e, ctx, callback);
	  if (ret)
	      return ret;
      }
  }

  
  return zx_walk_so_unknown_elems_and_content(c, &x->gg, ctx, callback);
}

/* FUNC(zx_WALK_WO_prov_PMGetStatus) */

int zx_WALK_WO_prov_PMGetStatus(struct zx_ctx* c, struct zx_prov_PMGetStatus_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
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

#define EL_NAME   prov_PMGetStatusResponse
#define EL_STRUCT zx_prov_PMGetStatusResponse_s
#define EL_NS     prov
#define EL_TAG    PMGetStatusResponse

/* FUNC(zx_FREE_prov_PMGetStatusResponse) */

/* Depth first traversal of data structure to free it and its subelements. Simple
 * strings are handled as a special case according to the free_strs flag. This
 * is useful if the strings point to underlying data from the wire that was
 * allocated differently. */

/* Called by: */
void zx_FREE_prov_PMGetStatusResponse(struct zx_ctx* c, struct zx_prov_PMGetStatusResponse_s* x, int free_strs)
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
      struct zx_prov_PMStatus_s* e;
      struct zx_prov_PMStatus_s* en;
      for (e = x->PMStatus; e; e = en) {
	  en = (struct zx_prov_PMStatus_s*)e->gg.g.n;
	  zx_FREE_prov_PMStatus(c, e, free_strs);
      }
  }


  zx_free_elem_common(c, &x->gg, free_strs); 
}

/* FUNC(zx_NEW_prov_PMGetStatusResponse) */

/* Trivial allocator/constructor for the datatype. */

/* Called by: */
struct zx_prov_PMGetStatusResponse_s* zx_NEW_prov_PMGetStatusResponse(struct zx_ctx* c)
{
  struct zx_prov_PMGetStatusResponse_s* x = ZX_ZALLOC(c, struct zx_prov_PMGetStatusResponse_s);
  x->gg.g.tok = zx_prov_PMGetStatusResponse_ELEM;
  return x;
}

#ifdef ZX_ENA_AUX

/* FUNC(zx_DUP_STRS_prov_PMGetStatusResponse) */

/* Depth first traversal of data structure to copy its simple strings
 * to memory allocated from the memory allocator. The decoder will
 * use the underlying wireprotocol PDU buffer for strings, i.e.
 * strings are not copied - they point to the real data. If the
 * datastructure needs to outlast the protocol data or needs a different
 * memory allocation strategy, you need to call this function.  */

/* Called by: */
void zx_DUP_STRS_prov_PMGetStatusResponse(struct zx_ctx* c, struct zx_prov_PMGetStatusResponse_s* x)
{
  zx_dup_strs_common(c, &x->gg);
  /* *** deal with xmlns specifications in exc c14n way */


  {
      struct zx_lu_Status_s* e;
      for (e = x->Status; e; e = (struct zx_lu_Status_s*)e->gg.g.n)
	  zx_DUP_STRS_lu_Status(c, e);
  }
  {
      struct zx_prov_PMStatus_s* e;
      for (e = x->PMStatus; e; e = (struct zx_prov_PMStatus_s*)e->gg.g.n)
	  zx_DUP_STRS_prov_PMStatus(c, e);
  }

}

/* FUNC(zx_DEEP_CLONE_prov_PMGetStatusResponse) */

/* Depth first traversal of data structure to clone it and its sublements.
 * The simple strings are handled as a special case according to dup_strs flag. */

/* Called by: */
struct zx_prov_PMGetStatusResponse_s* zx_DEEP_CLONE_prov_PMGetStatusResponse(struct zx_ctx* c, struct zx_prov_PMGetStatusResponse_s* x, int dup_strs)
{
  x = (struct zx_prov_PMGetStatusResponse_s*)zx_clone_elem_common(c, &x->gg, sizeof(struct zx_prov_PMGetStatusResponse_s), dup_strs);
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
      struct zx_prov_PMStatus_s* e;
      struct zx_prov_PMStatus_s* en;
      struct zx_prov_PMStatus_s* enn;
      for (enn = 0, e = x->PMStatus; e; e = (struct zx_prov_PMStatus_s*)e->gg.g.n) {
	  en = zx_DEEP_CLONE_prov_PMStatus(c, e, dup_strs);
	  if (!enn)
	      x->PMStatus = en;
	  else
	      enn->gg.g.n = &en->gg.g;
	  enn = en;
      }
  }

  return x;
}

/* FUNC(zx_WALK_SO_prov_PMGetStatusResponse) */

/* Depth first traversal of the tree in either schema order or the wire order. */
 
int zx_WALK_SO_prov_PMGetStatusResponse(struct zx_ctx* c, struct zx_prov_PMGetStatusResponse_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
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
      struct zx_prov_PMStatus_s* e;
      for (e = x->PMStatus; e; e = (struct zx_prov_PMStatus_s*)e->gg.g.n) {
	  ret = zx_WALK_SO_prov_PMStatus(c, e, ctx, callback);
	  if (ret)
	      return ret;
      }
  }

  
  return zx_walk_so_unknown_elems_and_content(c, &x->gg, ctx, callback);
}

/* FUNC(zx_WALK_WO_prov_PMGetStatusResponse) */

int zx_WALK_WO_prov_PMGetStatusResponse(struct zx_ctx* c, struct zx_prov_PMGetStatusResponse_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
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

#define EL_NAME   prov_PMID
#define EL_STRUCT zx_prov_PMID_s
#define EL_NS     prov
#define EL_TAG    PMID

/* FUNC(zx_FREE_prov_PMID) */

/* Depth first traversal of data structure to free it and its subelements. Simple
 * strings are handled as a special case according to the free_strs flag. This
 * is useful if the strings point to underlying data from the wire that was
 * allocated differently. */

/* Called by: */
void zx_FREE_prov_PMID(struct zx_ctx* c, struct zx_prov_PMID_s* x, int free_strs)
{
  /* *** deal with xmlns specifications in exc c14n way */

  zx_free_attr(c, x->issuer, free_strs);



  zx_free_elem_common(c, &x->gg, free_strs); 
}

/* FUNC(zx_NEW_prov_PMID) */

/* Trivial allocator/constructor for the datatype. */

/* Called by: */
struct zx_prov_PMID_s* zx_NEW_prov_PMID(struct zx_ctx* c)
{
  struct zx_prov_PMID_s* x = ZX_ZALLOC(c, struct zx_prov_PMID_s);
  x->gg.g.tok = zx_prov_PMID_ELEM;
  return x;
}

#ifdef ZX_ENA_AUX

/* FUNC(zx_DUP_STRS_prov_PMID) */

/* Depth first traversal of data structure to copy its simple strings
 * to memory allocated from the memory allocator. The decoder will
 * use the underlying wireprotocol PDU buffer for strings, i.e.
 * strings are not copied - they point to the real data. If the
 * datastructure needs to outlast the protocol data or needs a different
 * memory allocation strategy, you need to call this function.  */

/* Called by: */
void zx_DUP_STRS_prov_PMID(struct zx_ctx* c, struct zx_prov_PMID_s* x)
{
  zx_dup_strs_common(c, &x->gg);
  /* *** deal with xmlns specifications in exc c14n way */

  zx_dup_attr(c, x->issuer);


}

/* FUNC(zx_DEEP_CLONE_prov_PMID) */

/* Depth first traversal of data structure to clone it and its sublements.
 * The simple strings are handled as a special case according to dup_strs flag. */

/* Called by: */
struct zx_prov_PMID_s* zx_DEEP_CLONE_prov_PMID(struct zx_ctx* c, struct zx_prov_PMID_s* x, int dup_strs)
{
  x = (struct zx_prov_PMID_s*)zx_clone_elem_common(c, &x->gg, sizeof(struct zx_prov_PMID_s), dup_strs);
  /* *** deal with xmlns specifications in exc c14n way */

  x->issuer = zx_clone_attr(c, x->issuer);


  return x;
}

/* FUNC(zx_WALK_SO_prov_PMID) */

/* Depth first traversal of the tree in either schema order or the wire order. */
 
int zx_WALK_SO_prov_PMID(struct zx_ctx* c, struct zx_prov_PMID_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
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

/* FUNC(zx_WALK_WO_prov_PMID) */

int zx_WALK_WO_prov_PMID(struct zx_ctx* c, struct zx_prov_PMID_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
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

#define EL_NAME   prov_PMRegisterDescriptor
#define EL_STRUCT zx_prov_PMRegisterDescriptor_s
#define EL_NS     prov
#define EL_TAG    PMRegisterDescriptor

/* FUNC(zx_FREE_prov_PMRegisterDescriptor) */

/* Depth first traversal of data structure to free it and its subelements. Simple
 * strings are handled as a special case according to the free_strs flag. This
 * is useful if the strings point to underlying data from the wire that was
 * allocated differently. */

/* Called by: */
void zx_FREE_prov_PMRegisterDescriptor(struct zx_ctx* c, struct zx_prov_PMRegisterDescriptor_s* x, int free_strs)
{
  /* *** deal with xmlns specifications in exc c14n way */


  {
      struct zx_prov_PMRegisterDescriptorItem_s* e;
      struct zx_prov_PMRegisterDescriptorItem_s* en;
      for (e = x->PMRegisterDescriptorItem; e; e = en) {
	  en = (struct zx_prov_PMRegisterDescriptorItem_s*)e->gg.g.n;
	  zx_FREE_prov_PMRegisterDescriptorItem(c, e, free_strs);
      }
  }


  zx_free_elem_common(c, &x->gg, free_strs); 
}

/* FUNC(zx_NEW_prov_PMRegisterDescriptor) */

/* Trivial allocator/constructor for the datatype. */

/* Called by: */
struct zx_prov_PMRegisterDescriptor_s* zx_NEW_prov_PMRegisterDescriptor(struct zx_ctx* c)
{
  struct zx_prov_PMRegisterDescriptor_s* x = ZX_ZALLOC(c, struct zx_prov_PMRegisterDescriptor_s);
  x->gg.g.tok = zx_prov_PMRegisterDescriptor_ELEM;
  return x;
}

#ifdef ZX_ENA_AUX

/* FUNC(zx_DUP_STRS_prov_PMRegisterDescriptor) */

/* Depth first traversal of data structure to copy its simple strings
 * to memory allocated from the memory allocator. The decoder will
 * use the underlying wireprotocol PDU buffer for strings, i.e.
 * strings are not copied - they point to the real data. If the
 * datastructure needs to outlast the protocol data or needs a different
 * memory allocation strategy, you need to call this function.  */

/* Called by: */
void zx_DUP_STRS_prov_PMRegisterDescriptor(struct zx_ctx* c, struct zx_prov_PMRegisterDescriptor_s* x)
{
  zx_dup_strs_common(c, &x->gg);
  /* *** deal with xmlns specifications in exc c14n way */


  {
      struct zx_prov_PMRegisterDescriptorItem_s* e;
      for (e = x->PMRegisterDescriptorItem; e; e = (struct zx_prov_PMRegisterDescriptorItem_s*)e->gg.g.n)
	  zx_DUP_STRS_prov_PMRegisterDescriptorItem(c, e);
  }

}

/* FUNC(zx_DEEP_CLONE_prov_PMRegisterDescriptor) */

/* Depth first traversal of data structure to clone it and its sublements.
 * The simple strings are handled as a special case according to dup_strs flag. */

/* Called by: */
struct zx_prov_PMRegisterDescriptor_s* zx_DEEP_CLONE_prov_PMRegisterDescriptor(struct zx_ctx* c, struct zx_prov_PMRegisterDescriptor_s* x, int dup_strs)
{
  x = (struct zx_prov_PMRegisterDescriptor_s*)zx_clone_elem_common(c, &x->gg, sizeof(struct zx_prov_PMRegisterDescriptor_s), dup_strs);
  /* *** deal with xmlns specifications in exc c14n way */


  {
      struct zx_prov_PMRegisterDescriptorItem_s* e;
      struct zx_prov_PMRegisterDescriptorItem_s* en;
      struct zx_prov_PMRegisterDescriptorItem_s* enn;
      for (enn = 0, e = x->PMRegisterDescriptorItem; e; e = (struct zx_prov_PMRegisterDescriptorItem_s*)e->gg.g.n) {
	  en = zx_DEEP_CLONE_prov_PMRegisterDescriptorItem(c, e, dup_strs);
	  if (!enn)
	      x->PMRegisterDescriptorItem = en;
	  else
	      enn->gg.g.n = &en->gg.g;
	  enn = en;
      }
  }

  return x;
}

/* FUNC(zx_WALK_SO_prov_PMRegisterDescriptor) */

/* Depth first traversal of the tree in either schema order or the wire order. */
 
int zx_WALK_SO_prov_PMRegisterDescriptor(struct zx_ctx* c, struct zx_prov_PMRegisterDescriptor_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
{
  int ret = callback(&x->gg.g, ctx);
  if (ret)
    return ret;
  
  /* *** deal with xmlns specifications in exc c14n way */


  
  ret = zx_walk_so_unknown_attributes(c, &x->gg, ctx, callback); 
  if (ret)
    return ret;

  {
      struct zx_prov_PMRegisterDescriptorItem_s* e;
      for (e = x->PMRegisterDescriptorItem; e; e = (struct zx_prov_PMRegisterDescriptorItem_s*)e->gg.g.n) {
	  ret = zx_WALK_SO_prov_PMRegisterDescriptorItem(c, e, ctx, callback);
	  if (ret)
	      return ret;
      }
  }

  
  return zx_walk_so_unknown_elems_and_content(c, &x->gg, ctx, callback);
}

/* FUNC(zx_WALK_WO_prov_PMRegisterDescriptor) */

int zx_WALK_WO_prov_PMRegisterDescriptor(struct zx_ctx* c, struct zx_prov_PMRegisterDescriptor_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
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

#define EL_NAME   prov_PMRegisterDescriptorItem
#define EL_STRUCT zx_prov_PMRegisterDescriptorItem_s
#define EL_NS     prov
#define EL_TAG    PMRegisterDescriptorItem

/* FUNC(zx_FREE_prov_PMRegisterDescriptorItem) */

/* Depth first traversal of data structure to free it and its subelements. Simple
 * strings are handled as a special case according to the free_strs flag. This
 * is useful if the strings point to underlying data from the wire that was
 * allocated differently. */

/* Called by: */
void zx_FREE_prov_PMRegisterDescriptorItem(struct zx_ctx* c, struct zx_prov_PMRegisterDescriptorItem_s* x, int free_strs)
{
  /* *** deal with xmlns specifications in exc c14n way */

  zx_free_attr(c, x->itemID, free_strs);

  {
      struct zx_prov_PMDescriptor_s* e;
      struct zx_prov_PMDescriptor_s* en;
      for (e = x->PMDescriptor; e; e = en) {
	  en = (struct zx_prov_PMDescriptor_s*)e->gg.g.n;
	  zx_FREE_prov_PMDescriptor(c, e, free_strs);
      }
  }


  zx_free_elem_common(c, &x->gg, free_strs); 
}

/* FUNC(zx_NEW_prov_PMRegisterDescriptorItem) */

/* Trivial allocator/constructor for the datatype. */

/* Called by: */
struct zx_prov_PMRegisterDescriptorItem_s* zx_NEW_prov_PMRegisterDescriptorItem(struct zx_ctx* c)
{
  struct zx_prov_PMRegisterDescriptorItem_s* x = ZX_ZALLOC(c, struct zx_prov_PMRegisterDescriptorItem_s);
  x->gg.g.tok = zx_prov_PMRegisterDescriptorItem_ELEM;
  return x;
}

#ifdef ZX_ENA_AUX

/* FUNC(zx_DUP_STRS_prov_PMRegisterDescriptorItem) */

/* Depth first traversal of data structure to copy its simple strings
 * to memory allocated from the memory allocator. The decoder will
 * use the underlying wireprotocol PDU buffer for strings, i.e.
 * strings are not copied - they point to the real data. If the
 * datastructure needs to outlast the protocol data or needs a different
 * memory allocation strategy, you need to call this function.  */

/* Called by: */
void zx_DUP_STRS_prov_PMRegisterDescriptorItem(struct zx_ctx* c, struct zx_prov_PMRegisterDescriptorItem_s* x)
{
  zx_dup_strs_common(c, &x->gg);
  /* *** deal with xmlns specifications in exc c14n way */

  zx_dup_attr(c, x->itemID);

  {
      struct zx_prov_PMDescriptor_s* e;
      for (e = x->PMDescriptor; e; e = (struct zx_prov_PMDescriptor_s*)e->gg.g.n)
	  zx_DUP_STRS_prov_PMDescriptor(c, e);
  }

}

/* FUNC(zx_DEEP_CLONE_prov_PMRegisterDescriptorItem) */

/* Depth first traversal of data structure to clone it and its sublements.
 * The simple strings are handled as a special case according to dup_strs flag. */

/* Called by: */
struct zx_prov_PMRegisterDescriptorItem_s* zx_DEEP_CLONE_prov_PMRegisterDescriptorItem(struct zx_ctx* c, struct zx_prov_PMRegisterDescriptorItem_s* x, int dup_strs)
{
  x = (struct zx_prov_PMRegisterDescriptorItem_s*)zx_clone_elem_common(c, &x->gg, sizeof(struct zx_prov_PMRegisterDescriptorItem_s), dup_strs);
  /* *** deal with xmlns specifications in exc c14n way */

  x->itemID = zx_clone_attr(c, x->itemID);

  {
      struct zx_prov_PMDescriptor_s* e;
      struct zx_prov_PMDescriptor_s* en;
      struct zx_prov_PMDescriptor_s* enn;
      for (enn = 0, e = x->PMDescriptor; e; e = (struct zx_prov_PMDescriptor_s*)e->gg.g.n) {
	  en = zx_DEEP_CLONE_prov_PMDescriptor(c, e, dup_strs);
	  if (!enn)
	      x->PMDescriptor = en;
	  else
	      enn->gg.g.n = &en->gg.g;
	  enn = en;
      }
  }

  return x;
}

/* FUNC(zx_WALK_SO_prov_PMRegisterDescriptorItem) */

/* Depth first traversal of the tree in either schema order or the wire order. */
 
int zx_WALK_SO_prov_PMRegisterDescriptorItem(struct zx_ctx* c, struct zx_prov_PMRegisterDescriptorItem_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
{
  int ret = callback(&x->gg.g, ctx);
  if (ret)
    return ret;
  
  /* *** deal with xmlns specifications in exc c14n way */


  
  ret = zx_walk_so_unknown_attributes(c, &x->gg, ctx, callback); 
  if (ret)
    return ret;

  {
      struct zx_prov_PMDescriptor_s* e;
      for (e = x->PMDescriptor; e; e = (struct zx_prov_PMDescriptor_s*)e->gg.g.n) {
	  ret = zx_WALK_SO_prov_PMDescriptor(c, e, ctx, callback);
	  if (ret)
	      return ret;
      }
  }

  
  return zx_walk_so_unknown_elems_and_content(c, &x->gg, ctx, callback);
}

/* FUNC(zx_WALK_WO_prov_PMRegisterDescriptorItem) */

int zx_WALK_WO_prov_PMRegisterDescriptorItem(struct zx_ctx* c, struct zx_prov_PMRegisterDescriptorItem_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
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

#define EL_NAME   prov_PMRegisterDescriptorResponse
#define EL_STRUCT zx_prov_PMRegisterDescriptorResponse_s
#define EL_NS     prov
#define EL_TAG    PMRegisterDescriptorResponse

/* FUNC(zx_FREE_prov_PMRegisterDescriptorResponse) */

/* Depth first traversal of data structure to free it and its subelements. Simple
 * strings are handled as a special case according to the free_strs flag. This
 * is useful if the strings point to underlying data from the wire that was
 * allocated differently. */

/* Called by: */
void zx_FREE_prov_PMRegisterDescriptorResponse(struct zx_ctx* c, struct zx_prov_PMRegisterDescriptorResponse_s* x, int free_strs)
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
      struct zx_prov_PMRegisterDescriptorResponseItem_s* e;
      struct zx_prov_PMRegisterDescriptorResponseItem_s* en;
      for (e = x->PMRegisterDescriptorResponseItem; e; e = en) {
	  en = (struct zx_prov_PMRegisterDescriptorResponseItem_s*)e->gg.g.n;
	  zx_FREE_prov_PMRegisterDescriptorResponseItem(c, e, free_strs);
      }
  }


  zx_free_elem_common(c, &x->gg, free_strs); 
}

/* FUNC(zx_NEW_prov_PMRegisterDescriptorResponse) */

/* Trivial allocator/constructor for the datatype. */

/* Called by: */
struct zx_prov_PMRegisterDescriptorResponse_s* zx_NEW_prov_PMRegisterDescriptorResponse(struct zx_ctx* c)
{
  struct zx_prov_PMRegisterDescriptorResponse_s* x = ZX_ZALLOC(c, struct zx_prov_PMRegisterDescriptorResponse_s);
  x->gg.g.tok = zx_prov_PMRegisterDescriptorResponse_ELEM;
  return x;
}

#ifdef ZX_ENA_AUX

/* FUNC(zx_DUP_STRS_prov_PMRegisterDescriptorResponse) */

/* Depth first traversal of data structure to copy its simple strings
 * to memory allocated from the memory allocator. The decoder will
 * use the underlying wireprotocol PDU buffer for strings, i.e.
 * strings are not copied - they point to the real data. If the
 * datastructure needs to outlast the protocol data or needs a different
 * memory allocation strategy, you need to call this function.  */

/* Called by: */
void zx_DUP_STRS_prov_PMRegisterDescriptorResponse(struct zx_ctx* c, struct zx_prov_PMRegisterDescriptorResponse_s* x)
{
  zx_dup_strs_common(c, &x->gg);
  /* *** deal with xmlns specifications in exc c14n way */


  {
      struct zx_lu_Status_s* e;
      for (e = x->Status; e; e = (struct zx_lu_Status_s*)e->gg.g.n)
	  zx_DUP_STRS_lu_Status(c, e);
  }
  {
      struct zx_prov_PMRegisterDescriptorResponseItem_s* e;
      for (e = x->PMRegisterDescriptorResponseItem; e; e = (struct zx_prov_PMRegisterDescriptorResponseItem_s*)e->gg.g.n)
	  zx_DUP_STRS_prov_PMRegisterDescriptorResponseItem(c, e);
  }

}

/* FUNC(zx_DEEP_CLONE_prov_PMRegisterDescriptorResponse) */

/* Depth first traversal of data structure to clone it and its sublements.
 * The simple strings are handled as a special case according to dup_strs flag. */

/* Called by: */
struct zx_prov_PMRegisterDescriptorResponse_s* zx_DEEP_CLONE_prov_PMRegisterDescriptorResponse(struct zx_ctx* c, struct zx_prov_PMRegisterDescriptorResponse_s* x, int dup_strs)
{
  x = (struct zx_prov_PMRegisterDescriptorResponse_s*)zx_clone_elem_common(c, &x->gg, sizeof(struct zx_prov_PMRegisterDescriptorResponse_s), dup_strs);
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
      struct zx_prov_PMRegisterDescriptorResponseItem_s* e;
      struct zx_prov_PMRegisterDescriptorResponseItem_s* en;
      struct zx_prov_PMRegisterDescriptorResponseItem_s* enn;
      for (enn = 0, e = x->PMRegisterDescriptorResponseItem; e; e = (struct zx_prov_PMRegisterDescriptorResponseItem_s*)e->gg.g.n) {
	  en = zx_DEEP_CLONE_prov_PMRegisterDescriptorResponseItem(c, e, dup_strs);
	  if (!enn)
	      x->PMRegisterDescriptorResponseItem = en;
	  else
	      enn->gg.g.n = &en->gg.g;
	  enn = en;
      }
  }

  return x;
}

/* FUNC(zx_WALK_SO_prov_PMRegisterDescriptorResponse) */

/* Depth first traversal of the tree in either schema order or the wire order. */
 
int zx_WALK_SO_prov_PMRegisterDescriptorResponse(struct zx_ctx* c, struct zx_prov_PMRegisterDescriptorResponse_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
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
      struct zx_prov_PMRegisterDescriptorResponseItem_s* e;
      for (e = x->PMRegisterDescriptorResponseItem; e; e = (struct zx_prov_PMRegisterDescriptorResponseItem_s*)e->gg.g.n) {
	  ret = zx_WALK_SO_prov_PMRegisterDescriptorResponseItem(c, e, ctx, callback);
	  if (ret)
	      return ret;
      }
  }

  
  return zx_walk_so_unknown_elems_and_content(c, &x->gg, ctx, callback);
}

/* FUNC(zx_WALK_WO_prov_PMRegisterDescriptorResponse) */

int zx_WALK_WO_prov_PMRegisterDescriptorResponse(struct zx_ctx* c, struct zx_prov_PMRegisterDescriptorResponse_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
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

#define EL_NAME   prov_PMRegisterDescriptorResponseItem
#define EL_STRUCT zx_prov_PMRegisterDescriptorResponseItem_s
#define EL_NS     prov
#define EL_TAG    PMRegisterDescriptorResponseItem

/* FUNC(zx_FREE_prov_PMRegisterDescriptorResponseItem) */

/* Depth first traversal of data structure to free it and its subelements. Simple
 * strings are handled as a special case according to the free_strs flag. This
 * is useful if the strings point to underlying data from the wire that was
 * allocated differently. */

/* Called by: */
void zx_FREE_prov_PMRegisterDescriptorResponseItem(struct zx_ctx* c, struct zx_prov_PMRegisterDescriptorResponseItem_s* x, int free_strs)
{
  /* *** deal with xmlns specifications in exc c14n way */

  zx_free_attr(c, x->ref, free_strs);

  {
      struct zx_prov_ProvisioningHandle_s* e;
      struct zx_prov_ProvisioningHandle_s* en;
      for (e = x->ProvisioningHandle; e; e = en) {
	  en = (struct zx_prov_ProvisioningHandle_s*)e->gg.g.n;
	  zx_FREE_prov_ProvisioningHandle(c, e, free_strs);
      }
  }


  zx_free_elem_common(c, &x->gg, free_strs); 
}

/* FUNC(zx_NEW_prov_PMRegisterDescriptorResponseItem) */

/* Trivial allocator/constructor for the datatype. */

/* Called by: */
struct zx_prov_PMRegisterDescriptorResponseItem_s* zx_NEW_prov_PMRegisterDescriptorResponseItem(struct zx_ctx* c)
{
  struct zx_prov_PMRegisterDescriptorResponseItem_s* x = ZX_ZALLOC(c, struct zx_prov_PMRegisterDescriptorResponseItem_s);
  x->gg.g.tok = zx_prov_PMRegisterDescriptorResponseItem_ELEM;
  return x;
}

#ifdef ZX_ENA_AUX

/* FUNC(zx_DUP_STRS_prov_PMRegisterDescriptorResponseItem) */

/* Depth first traversal of data structure to copy its simple strings
 * to memory allocated from the memory allocator. The decoder will
 * use the underlying wireprotocol PDU buffer for strings, i.e.
 * strings are not copied - they point to the real data. If the
 * datastructure needs to outlast the protocol data or needs a different
 * memory allocation strategy, you need to call this function.  */

/* Called by: */
void zx_DUP_STRS_prov_PMRegisterDescriptorResponseItem(struct zx_ctx* c, struct zx_prov_PMRegisterDescriptorResponseItem_s* x)
{
  zx_dup_strs_common(c, &x->gg);
  /* *** deal with xmlns specifications in exc c14n way */

  zx_dup_attr(c, x->ref);

  {
      struct zx_prov_ProvisioningHandle_s* e;
      for (e = x->ProvisioningHandle; e; e = (struct zx_prov_ProvisioningHandle_s*)e->gg.g.n)
	  zx_DUP_STRS_prov_ProvisioningHandle(c, e);
  }

}

/* FUNC(zx_DEEP_CLONE_prov_PMRegisterDescriptorResponseItem) */

/* Depth first traversal of data structure to clone it and its sublements.
 * The simple strings are handled as a special case according to dup_strs flag. */

/* Called by: */
struct zx_prov_PMRegisterDescriptorResponseItem_s* zx_DEEP_CLONE_prov_PMRegisterDescriptorResponseItem(struct zx_ctx* c, struct zx_prov_PMRegisterDescriptorResponseItem_s* x, int dup_strs)
{
  x = (struct zx_prov_PMRegisterDescriptorResponseItem_s*)zx_clone_elem_common(c, &x->gg, sizeof(struct zx_prov_PMRegisterDescriptorResponseItem_s), dup_strs);
  /* *** deal with xmlns specifications in exc c14n way */

  x->ref = zx_clone_attr(c, x->ref);

  {
      struct zx_prov_ProvisioningHandle_s* e;
      struct zx_prov_ProvisioningHandle_s* en;
      struct zx_prov_ProvisioningHandle_s* enn;
      for (enn = 0, e = x->ProvisioningHandle; e; e = (struct zx_prov_ProvisioningHandle_s*)e->gg.g.n) {
	  en = zx_DEEP_CLONE_prov_ProvisioningHandle(c, e, dup_strs);
	  if (!enn)
	      x->ProvisioningHandle = en;
	  else
	      enn->gg.g.n = &en->gg.g;
	  enn = en;
      }
  }

  return x;
}

/* FUNC(zx_WALK_SO_prov_PMRegisterDescriptorResponseItem) */

/* Depth first traversal of the tree in either schema order or the wire order. */
 
int zx_WALK_SO_prov_PMRegisterDescriptorResponseItem(struct zx_ctx* c, struct zx_prov_PMRegisterDescriptorResponseItem_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
{
  int ret = callback(&x->gg.g, ctx);
  if (ret)
    return ret;
  
  /* *** deal with xmlns specifications in exc c14n way */


  
  ret = zx_walk_so_unknown_attributes(c, &x->gg, ctx, callback); 
  if (ret)
    return ret;

  {
      struct zx_prov_ProvisioningHandle_s* e;
      for (e = x->ProvisioningHandle; e; e = (struct zx_prov_ProvisioningHandle_s*)e->gg.g.n) {
	  ret = zx_WALK_SO_prov_ProvisioningHandle(c, e, ctx, callback);
	  if (ret)
	      return ret;
      }
  }

  
  return zx_walk_so_unknown_elems_and_content(c, &x->gg, ctx, callback);
}

/* FUNC(zx_WALK_WO_prov_PMRegisterDescriptorResponseItem) */

int zx_WALK_WO_prov_PMRegisterDescriptorResponseItem(struct zx_ctx* c, struct zx_prov_PMRegisterDescriptorResponseItem_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
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

#define EL_NAME   prov_PMSetStatus
#define EL_STRUCT zx_prov_PMSetStatus_s
#define EL_NS     prov
#define EL_TAG    PMSetStatus

/* FUNC(zx_FREE_prov_PMSetStatus) */

/* Depth first traversal of data structure to free it and its subelements. Simple
 * strings are handled as a special case according to the free_strs flag. This
 * is useful if the strings point to underlying data from the wire that was
 * allocated differently. */

/* Called by: */
void zx_FREE_prov_PMSetStatus(struct zx_ctx* c, struct zx_prov_PMSetStatus_s* x, int free_strs)
{
  /* *** deal with xmlns specifications in exc c14n way */


  {
      struct zx_prov_PMStatus_s* e;
      struct zx_prov_PMStatus_s* en;
      for (e = x->PMStatus; e; e = en) {
	  en = (struct zx_prov_PMStatus_s*)e->gg.g.n;
	  zx_FREE_prov_PMStatus(c, e, free_strs);
      }
  }


  zx_free_elem_common(c, &x->gg, free_strs); 
}

/* FUNC(zx_NEW_prov_PMSetStatus) */

/* Trivial allocator/constructor for the datatype. */

/* Called by: */
struct zx_prov_PMSetStatus_s* zx_NEW_prov_PMSetStatus(struct zx_ctx* c)
{
  struct zx_prov_PMSetStatus_s* x = ZX_ZALLOC(c, struct zx_prov_PMSetStatus_s);
  x->gg.g.tok = zx_prov_PMSetStatus_ELEM;
  return x;
}

#ifdef ZX_ENA_AUX

/* FUNC(zx_DUP_STRS_prov_PMSetStatus) */

/* Depth first traversal of data structure to copy its simple strings
 * to memory allocated from the memory allocator. The decoder will
 * use the underlying wireprotocol PDU buffer for strings, i.e.
 * strings are not copied - they point to the real data. If the
 * datastructure needs to outlast the protocol data or needs a different
 * memory allocation strategy, you need to call this function.  */

/* Called by: */
void zx_DUP_STRS_prov_PMSetStatus(struct zx_ctx* c, struct zx_prov_PMSetStatus_s* x)
{
  zx_dup_strs_common(c, &x->gg);
  /* *** deal with xmlns specifications in exc c14n way */


  {
      struct zx_prov_PMStatus_s* e;
      for (e = x->PMStatus; e; e = (struct zx_prov_PMStatus_s*)e->gg.g.n)
	  zx_DUP_STRS_prov_PMStatus(c, e);
  }

}

/* FUNC(zx_DEEP_CLONE_prov_PMSetStatus) */

/* Depth first traversal of data structure to clone it and its sublements.
 * The simple strings are handled as a special case according to dup_strs flag. */

/* Called by: */
struct zx_prov_PMSetStatus_s* zx_DEEP_CLONE_prov_PMSetStatus(struct zx_ctx* c, struct zx_prov_PMSetStatus_s* x, int dup_strs)
{
  x = (struct zx_prov_PMSetStatus_s*)zx_clone_elem_common(c, &x->gg, sizeof(struct zx_prov_PMSetStatus_s), dup_strs);
  /* *** deal with xmlns specifications in exc c14n way */


  {
      struct zx_prov_PMStatus_s* e;
      struct zx_prov_PMStatus_s* en;
      struct zx_prov_PMStatus_s* enn;
      for (enn = 0, e = x->PMStatus; e; e = (struct zx_prov_PMStatus_s*)e->gg.g.n) {
	  en = zx_DEEP_CLONE_prov_PMStatus(c, e, dup_strs);
	  if (!enn)
	      x->PMStatus = en;
	  else
	      enn->gg.g.n = &en->gg.g;
	  enn = en;
      }
  }

  return x;
}

/* FUNC(zx_WALK_SO_prov_PMSetStatus) */

/* Depth first traversal of the tree in either schema order or the wire order. */
 
int zx_WALK_SO_prov_PMSetStatus(struct zx_ctx* c, struct zx_prov_PMSetStatus_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
{
  int ret = callback(&x->gg.g, ctx);
  if (ret)
    return ret;
  
  /* *** deal with xmlns specifications in exc c14n way */


  
  ret = zx_walk_so_unknown_attributes(c, &x->gg, ctx, callback); 
  if (ret)
    return ret;

  {
      struct zx_prov_PMStatus_s* e;
      for (e = x->PMStatus; e; e = (struct zx_prov_PMStatus_s*)e->gg.g.n) {
	  ret = zx_WALK_SO_prov_PMStatus(c, e, ctx, callback);
	  if (ret)
	      return ret;
      }
  }

  
  return zx_walk_so_unknown_elems_and_content(c, &x->gg, ctx, callback);
}

/* FUNC(zx_WALK_WO_prov_PMSetStatus) */

int zx_WALK_WO_prov_PMSetStatus(struct zx_ctx* c, struct zx_prov_PMSetStatus_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
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

#define EL_NAME   prov_PMSetStatusResponse
#define EL_STRUCT zx_prov_PMSetStatusResponse_s
#define EL_NS     prov
#define EL_TAG    PMSetStatusResponse

/* FUNC(zx_FREE_prov_PMSetStatusResponse) */

/* Depth first traversal of data structure to free it and its subelements. Simple
 * strings are handled as a special case according to the free_strs flag. This
 * is useful if the strings point to underlying data from the wire that was
 * allocated differently. */

/* Called by: */
void zx_FREE_prov_PMSetStatusResponse(struct zx_ctx* c, struct zx_prov_PMSetStatusResponse_s* x, int free_strs)
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

/* FUNC(zx_NEW_prov_PMSetStatusResponse) */

/* Trivial allocator/constructor for the datatype. */

/* Called by: */
struct zx_prov_PMSetStatusResponse_s* zx_NEW_prov_PMSetStatusResponse(struct zx_ctx* c)
{
  struct zx_prov_PMSetStatusResponse_s* x = ZX_ZALLOC(c, struct zx_prov_PMSetStatusResponse_s);
  x->gg.g.tok = zx_prov_PMSetStatusResponse_ELEM;
  return x;
}

#ifdef ZX_ENA_AUX

/* FUNC(zx_DUP_STRS_prov_PMSetStatusResponse) */

/* Depth first traversal of data structure to copy its simple strings
 * to memory allocated from the memory allocator. The decoder will
 * use the underlying wireprotocol PDU buffer for strings, i.e.
 * strings are not copied - they point to the real data. If the
 * datastructure needs to outlast the protocol data or needs a different
 * memory allocation strategy, you need to call this function.  */

/* Called by: */
void zx_DUP_STRS_prov_PMSetStatusResponse(struct zx_ctx* c, struct zx_prov_PMSetStatusResponse_s* x)
{
  zx_dup_strs_common(c, &x->gg);
  /* *** deal with xmlns specifications in exc c14n way */


  {
      struct zx_lu_Status_s* e;
      for (e = x->Status; e; e = (struct zx_lu_Status_s*)e->gg.g.n)
	  zx_DUP_STRS_lu_Status(c, e);
  }

}

/* FUNC(zx_DEEP_CLONE_prov_PMSetStatusResponse) */

/* Depth first traversal of data structure to clone it and its sublements.
 * The simple strings are handled as a special case according to dup_strs flag. */

/* Called by: */
struct zx_prov_PMSetStatusResponse_s* zx_DEEP_CLONE_prov_PMSetStatusResponse(struct zx_ctx* c, struct zx_prov_PMSetStatusResponse_s* x, int dup_strs)
{
  x = (struct zx_prov_PMSetStatusResponse_s*)zx_clone_elem_common(c, &x->gg, sizeof(struct zx_prov_PMSetStatusResponse_s), dup_strs);
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

/* FUNC(zx_WALK_SO_prov_PMSetStatusResponse) */

/* Depth first traversal of the tree in either schema order or the wire order. */
 
int zx_WALK_SO_prov_PMSetStatusResponse(struct zx_ctx* c, struct zx_prov_PMSetStatusResponse_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
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

/* FUNC(zx_WALK_WO_prov_PMSetStatusResponse) */

int zx_WALK_WO_prov_PMSetStatusResponse(struct zx_ctx* c, struct zx_prov_PMSetStatusResponse_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
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

#define EL_NAME   prov_PMStatus
#define EL_STRUCT zx_prov_PMStatus_s
#define EL_NS     prov
#define EL_TAG    PMStatus

/* FUNC(zx_FREE_prov_PMStatus) */

/* Depth first traversal of data structure to free it and its subelements. Simple
 * strings are handled as a special case according to the free_strs flag. This
 * is useful if the strings point to underlying data from the wire that was
 * allocated differently. */

/* Called by: */
void zx_FREE_prov_PMStatus(struct zx_ctx* c, struct zx_prov_PMStatus_s* x, int free_strs)
{
  /* *** deal with xmlns specifications in exc c14n way */


  {
      struct zx_prov_PMID_s* e;
      struct zx_prov_PMID_s* en;
      for (e = x->PMID; e; e = en) {
	  en = (struct zx_prov_PMID_s*)e->gg.g.n;
	  zx_FREE_prov_PMID(c, e, free_strs);
      }
  }
  {
      struct zx_prov_State_s* e;
      struct zx_prov_State_s* en;
      for (e = x->State; e; e = en) {
	  en = (struct zx_prov_State_s*)e->gg.g.n;
	  zx_FREE_prov_State(c, e, free_strs);
      }
  }


  zx_free_elem_common(c, &x->gg, free_strs); 
}

/* FUNC(zx_NEW_prov_PMStatus) */

/* Trivial allocator/constructor for the datatype. */

/* Called by: */
struct zx_prov_PMStatus_s* zx_NEW_prov_PMStatus(struct zx_ctx* c)
{
  struct zx_prov_PMStatus_s* x = ZX_ZALLOC(c, struct zx_prov_PMStatus_s);
  x->gg.g.tok = zx_prov_PMStatus_ELEM;
  return x;
}

#ifdef ZX_ENA_AUX

/* FUNC(zx_DUP_STRS_prov_PMStatus) */

/* Depth first traversal of data structure to copy its simple strings
 * to memory allocated from the memory allocator. The decoder will
 * use the underlying wireprotocol PDU buffer for strings, i.e.
 * strings are not copied - they point to the real data. If the
 * datastructure needs to outlast the protocol data or needs a different
 * memory allocation strategy, you need to call this function.  */

/* Called by: */
void zx_DUP_STRS_prov_PMStatus(struct zx_ctx* c, struct zx_prov_PMStatus_s* x)
{
  zx_dup_strs_common(c, &x->gg);
  /* *** deal with xmlns specifications in exc c14n way */


  {
      struct zx_prov_PMID_s* e;
      for (e = x->PMID; e; e = (struct zx_prov_PMID_s*)e->gg.g.n)
	  zx_DUP_STRS_prov_PMID(c, e);
  }
  {
      struct zx_prov_State_s* e;
      for (e = x->State; e; e = (struct zx_prov_State_s*)e->gg.g.n)
	  zx_DUP_STRS_prov_State(c, e);
  }

}

/* FUNC(zx_DEEP_CLONE_prov_PMStatus) */

/* Depth first traversal of data structure to clone it and its sublements.
 * The simple strings are handled as a special case according to dup_strs flag. */

/* Called by: */
struct zx_prov_PMStatus_s* zx_DEEP_CLONE_prov_PMStatus(struct zx_ctx* c, struct zx_prov_PMStatus_s* x, int dup_strs)
{
  x = (struct zx_prov_PMStatus_s*)zx_clone_elem_common(c, &x->gg, sizeof(struct zx_prov_PMStatus_s), dup_strs);
  /* *** deal with xmlns specifications in exc c14n way */


  {
      struct zx_prov_PMID_s* e;
      struct zx_prov_PMID_s* en;
      struct zx_prov_PMID_s* enn;
      for (enn = 0, e = x->PMID; e; e = (struct zx_prov_PMID_s*)e->gg.g.n) {
	  en = zx_DEEP_CLONE_prov_PMID(c, e, dup_strs);
	  if (!enn)
	      x->PMID = en;
	  else
	      enn->gg.g.n = &en->gg.g;
	  enn = en;
      }
  }
  {
      struct zx_prov_State_s* e;
      struct zx_prov_State_s* en;
      struct zx_prov_State_s* enn;
      for (enn = 0, e = x->State; e; e = (struct zx_prov_State_s*)e->gg.g.n) {
	  en = zx_DEEP_CLONE_prov_State(c, e, dup_strs);
	  if (!enn)
	      x->State = en;
	  else
	      enn->gg.g.n = &en->gg.g;
	  enn = en;
      }
  }

  return x;
}

/* FUNC(zx_WALK_SO_prov_PMStatus) */

/* Depth first traversal of the tree in either schema order or the wire order. */
 
int zx_WALK_SO_prov_PMStatus(struct zx_ctx* c, struct zx_prov_PMStatus_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
{
  int ret = callback(&x->gg.g, ctx);
  if (ret)
    return ret;
  
  /* *** deal with xmlns specifications in exc c14n way */


  
  ret = zx_walk_so_unknown_attributes(c, &x->gg, ctx, callback); 
  if (ret)
    return ret;

  {
      struct zx_prov_PMID_s* e;
      for (e = x->PMID; e; e = (struct zx_prov_PMID_s*)e->gg.g.n) {
	  ret = zx_WALK_SO_prov_PMID(c, e, ctx, callback);
	  if (ret)
	      return ret;
      }
  }
  {
      struct zx_prov_State_s* e;
      for (e = x->State; e; e = (struct zx_prov_State_s*)e->gg.g.n) {
	  ret = zx_WALK_SO_prov_State(c, e, ctx, callback);
	  if (ret)
	      return ret;
      }
  }

  
  return zx_walk_so_unknown_elems_and_content(c, &x->gg, ctx, callback);
}

/* FUNC(zx_WALK_WO_prov_PMStatus) */

int zx_WALK_WO_prov_PMStatus(struct zx_ctx* c, struct zx_prov_PMStatus_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
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

#define EL_NAME   prov_PMUpdate
#define EL_STRUCT zx_prov_PMUpdate_s
#define EL_NS     prov
#define EL_TAG    PMUpdate

/* FUNC(zx_FREE_prov_PMUpdate) */

/* Depth first traversal of data structure to free it and its subelements. Simple
 * strings are handled as a special case according to the free_strs flag. This
 * is useful if the strings point to underlying data from the wire that was
 * allocated differently. */

/* Called by: */
void zx_FREE_prov_PMUpdate(struct zx_ctx* c, struct zx_prov_PMUpdate_s* x, int free_strs)
{
  /* *** deal with xmlns specifications in exc c14n way */


  {
      struct zx_prov_PMUpdateItem_s* e;
      struct zx_prov_PMUpdateItem_s* en;
      for (e = x->PMUpdateItem; e; e = en) {
	  en = (struct zx_prov_PMUpdateItem_s*)e->gg.g.n;
	  zx_FREE_prov_PMUpdateItem(c, e, free_strs);
      }
  }
  zx_free_simple_elems(c, x->NotifyTo, free_strs);


  zx_free_elem_common(c, &x->gg, free_strs); 
}

/* FUNC(zx_NEW_prov_PMUpdate) */

/* Trivial allocator/constructor for the datatype. */

/* Called by: */
struct zx_prov_PMUpdate_s* zx_NEW_prov_PMUpdate(struct zx_ctx* c)
{
  struct zx_prov_PMUpdate_s* x = ZX_ZALLOC(c, struct zx_prov_PMUpdate_s);
  x->gg.g.tok = zx_prov_PMUpdate_ELEM;
  return x;
}

#ifdef ZX_ENA_AUX

/* FUNC(zx_DUP_STRS_prov_PMUpdate) */

/* Depth first traversal of data structure to copy its simple strings
 * to memory allocated from the memory allocator. The decoder will
 * use the underlying wireprotocol PDU buffer for strings, i.e.
 * strings are not copied - they point to the real data. If the
 * datastructure needs to outlast the protocol data or needs a different
 * memory allocation strategy, you need to call this function.  */

/* Called by: */
void zx_DUP_STRS_prov_PMUpdate(struct zx_ctx* c, struct zx_prov_PMUpdate_s* x)
{
  zx_dup_strs_common(c, &x->gg);
  /* *** deal with xmlns specifications in exc c14n way */


  {
      struct zx_prov_PMUpdateItem_s* e;
      for (e = x->PMUpdateItem; e; e = (struct zx_prov_PMUpdateItem_s*)e->gg.g.n)
	  zx_DUP_STRS_prov_PMUpdateItem(c, e);
  }
  zx_dup_strs_simple_elems(c, x->NotifyTo);

}

/* FUNC(zx_DEEP_CLONE_prov_PMUpdate) */

/* Depth first traversal of data structure to clone it and its sublements.
 * The simple strings are handled as a special case according to dup_strs flag. */

/* Called by: */
struct zx_prov_PMUpdate_s* zx_DEEP_CLONE_prov_PMUpdate(struct zx_ctx* c, struct zx_prov_PMUpdate_s* x, int dup_strs)
{
  x = (struct zx_prov_PMUpdate_s*)zx_clone_elem_common(c, &x->gg, sizeof(struct zx_prov_PMUpdate_s), dup_strs);
  /* *** deal with xmlns specifications in exc c14n way */


  {
      struct zx_prov_PMUpdateItem_s* e;
      struct zx_prov_PMUpdateItem_s* en;
      struct zx_prov_PMUpdateItem_s* enn;
      for (enn = 0, e = x->PMUpdateItem; e; e = (struct zx_prov_PMUpdateItem_s*)e->gg.g.n) {
	  en = zx_DEEP_CLONE_prov_PMUpdateItem(c, e, dup_strs);
	  if (!enn)
	      x->PMUpdateItem = en;
	  else
	      enn->gg.g.n = &en->gg.g;
	  enn = en;
      }
  }
  x->NotifyTo = zx_deep_clone_simple_elems(c,x->NotifyTo, dup_strs);

  return x;
}

/* FUNC(zx_WALK_SO_prov_PMUpdate) */

/* Depth first traversal of the tree in either schema order or the wire order. */
 
int zx_WALK_SO_prov_PMUpdate(struct zx_ctx* c, struct zx_prov_PMUpdate_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
{
  int ret = callback(&x->gg.g, ctx);
  if (ret)
    return ret;
  
  /* *** deal with xmlns specifications in exc c14n way */


  
  ret = zx_walk_so_unknown_attributes(c, &x->gg, ctx, callback); 
  if (ret)
    return ret;

  {
      struct zx_prov_PMUpdateItem_s* e;
      for (e = x->PMUpdateItem; e; e = (struct zx_prov_PMUpdateItem_s*)e->gg.g.n) {
	  ret = zx_WALK_SO_prov_PMUpdateItem(c, e, ctx, callback);
	  if (ret)
	      return ret;
      }
  }
  ret = zx_walk_so_simple_elems(c, x->NotifyTo, ctx, callback);
  if (ret)
    return ret;

  
  return zx_walk_so_unknown_elems_and_content(c, &x->gg, ctx, callback);
}

/* FUNC(zx_WALK_WO_prov_PMUpdate) */

int zx_WALK_WO_prov_PMUpdate(struct zx_ctx* c, struct zx_prov_PMUpdate_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
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

#define EL_NAME   prov_PMUpdateItem
#define EL_STRUCT zx_prov_PMUpdateItem_s
#define EL_NS     prov
#define EL_TAG    PMUpdateItem

/* FUNC(zx_FREE_prov_PMUpdateItem) */

/* Depth first traversal of data structure to free it and its subelements. Simple
 * strings are handled as a special case according to the free_strs flag. This
 * is useful if the strings point to underlying data from the wire that was
 * allocated differently. */

/* Called by: */
void zx_FREE_prov_PMUpdateItem(struct zx_ctx* c, struct zx_prov_PMUpdateItem_s* x, int free_strs)
{
  /* *** deal with xmlns specifications in exc c14n way */

  zx_free_attr(c, x->at, free_strs);
  zx_free_attr(c, x->itemID, free_strs);
  zx_free_attr(c, x->type, free_strs);

  {
      struct zx_prov_PMDescriptor_s* e;
      struct zx_prov_PMDescriptor_s* en;
      for (e = x->PMDescriptor; e; e = en) {
	  en = (struct zx_prov_PMDescriptor_s*)e->gg.g.n;
	  zx_FREE_prov_PMDescriptor(c, e, free_strs);
      }
  }


  zx_free_elem_common(c, &x->gg, free_strs); 
}

/* FUNC(zx_NEW_prov_PMUpdateItem) */

/* Trivial allocator/constructor for the datatype. */

/* Called by: */
struct zx_prov_PMUpdateItem_s* zx_NEW_prov_PMUpdateItem(struct zx_ctx* c)
{
  struct zx_prov_PMUpdateItem_s* x = ZX_ZALLOC(c, struct zx_prov_PMUpdateItem_s);
  x->gg.g.tok = zx_prov_PMUpdateItem_ELEM;
  return x;
}

#ifdef ZX_ENA_AUX

/* FUNC(zx_DUP_STRS_prov_PMUpdateItem) */

/* Depth first traversal of data structure to copy its simple strings
 * to memory allocated from the memory allocator. The decoder will
 * use the underlying wireprotocol PDU buffer for strings, i.e.
 * strings are not copied - they point to the real data. If the
 * datastructure needs to outlast the protocol data or needs a different
 * memory allocation strategy, you need to call this function.  */

/* Called by: */
void zx_DUP_STRS_prov_PMUpdateItem(struct zx_ctx* c, struct zx_prov_PMUpdateItem_s* x)
{
  zx_dup_strs_common(c, &x->gg);
  /* *** deal with xmlns specifications in exc c14n way */

  zx_dup_attr(c, x->at);
  zx_dup_attr(c, x->itemID);
  zx_dup_attr(c, x->type);

  {
      struct zx_prov_PMDescriptor_s* e;
      for (e = x->PMDescriptor; e; e = (struct zx_prov_PMDescriptor_s*)e->gg.g.n)
	  zx_DUP_STRS_prov_PMDescriptor(c, e);
  }

}

/* FUNC(zx_DEEP_CLONE_prov_PMUpdateItem) */

/* Depth first traversal of data structure to clone it and its sublements.
 * The simple strings are handled as a special case according to dup_strs flag. */

/* Called by: */
struct zx_prov_PMUpdateItem_s* zx_DEEP_CLONE_prov_PMUpdateItem(struct zx_ctx* c, struct zx_prov_PMUpdateItem_s* x, int dup_strs)
{
  x = (struct zx_prov_PMUpdateItem_s*)zx_clone_elem_common(c, &x->gg, sizeof(struct zx_prov_PMUpdateItem_s), dup_strs);
  /* *** deal with xmlns specifications in exc c14n way */

  x->at = zx_clone_attr(c, x->at);
  x->itemID = zx_clone_attr(c, x->itemID);
  x->type = zx_clone_attr(c, x->type);

  {
      struct zx_prov_PMDescriptor_s* e;
      struct zx_prov_PMDescriptor_s* en;
      struct zx_prov_PMDescriptor_s* enn;
      for (enn = 0, e = x->PMDescriptor; e; e = (struct zx_prov_PMDescriptor_s*)e->gg.g.n) {
	  en = zx_DEEP_CLONE_prov_PMDescriptor(c, e, dup_strs);
	  if (!enn)
	      x->PMDescriptor = en;
	  else
	      enn->gg.g.n = &en->gg.g;
	  enn = en;
      }
  }

  return x;
}

/* FUNC(zx_WALK_SO_prov_PMUpdateItem) */

/* Depth first traversal of the tree in either schema order or the wire order. */
 
int zx_WALK_SO_prov_PMUpdateItem(struct zx_ctx* c, struct zx_prov_PMUpdateItem_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
{
  int ret = callback(&x->gg.g, ctx);
  if (ret)
    return ret;
  
  /* *** deal with xmlns specifications in exc c14n way */


  
  ret = zx_walk_so_unknown_attributes(c, &x->gg, ctx, callback); 
  if (ret)
    return ret;

  {
      struct zx_prov_PMDescriptor_s* e;
      for (e = x->PMDescriptor; e; e = (struct zx_prov_PMDescriptor_s*)e->gg.g.n) {
	  ret = zx_WALK_SO_prov_PMDescriptor(c, e, ctx, callback);
	  if (ret)
	      return ret;
      }
  }

  
  return zx_walk_so_unknown_elems_and_content(c, &x->gg, ctx, callback);
}

/* FUNC(zx_WALK_WO_prov_PMUpdateItem) */

int zx_WALK_WO_prov_PMUpdateItem(struct zx_ctx* c, struct zx_prov_PMUpdateItem_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
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

#define EL_NAME   prov_PMUpdateResponse
#define EL_STRUCT zx_prov_PMUpdateResponse_s
#define EL_NS     prov
#define EL_TAG    PMUpdateResponse

/* FUNC(zx_FREE_prov_PMUpdateResponse) */

/* Depth first traversal of data structure to free it and its subelements. Simple
 * strings are handled as a special case according to the free_strs flag. This
 * is useful if the strings point to underlying data from the wire that was
 * allocated differently. */

/* Called by: */
void zx_FREE_prov_PMUpdateResponse(struct zx_ctx* c, struct zx_prov_PMUpdateResponse_s* x, int free_strs)
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

/* FUNC(zx_NEW_prov_PMUpdateResponse) */

/* Trivial allocator/constructor for the datatype. */

/* Called by: */
struct zx_prov_PMUpdateResponse_s* zx_NEW_prov_PMUpdateResponse(struct zx_ctx* c)
{
  struct zx_prov_PMUpdateResponse_s* x = ZX_ZALLOC(c, struct zx_prov_PMUpdateResponse_s);
  x->gg.g.tok = zx_prov_PMUpdateResponse_ELEM;
  return x;
}

#ifdef ZX_ENA_AUX

/* FUNC(zx_DUP_STRS_prov_PMUpdateResponse) */

/* Depth first traversal of data structure to copy its simple strings
 * to memory allocated from the memory allocator. The decoder will
 * use the underlying wireprotocol PDU buffer for strings, i.e.
 * strings are not copied - they point to the real data. If the
 * datastructure needs to outlast the protocol data or needs a different
 * memory allocation strategy, you need to call this function.  */

/* Called by: */
void zx_DUP_STRS_prov_PMUpdateResponse(struct zx_ctx* c, struct zx_prov_PMUpdateResponse_s* x)
{
  zx_dup_strs_common(c, &x->gg);
  /* *** deal with xmlns specifications in exc c14n way */


  {
      struct zx_lu_Status_s* e;
      for (e = x->Status; e; e = (struct zx_lu_Status_s*)e->gg.g.n)
	  zx_DUP_STRS_lu_Status(c, e);
  }

}

/* FUNC(zx_DEEP_CLONE_prov_PMUpdateResponse) */

/* Depth first traversal of data structure to clone it and its sublements.
 * The simple strings are handled as a special case according to dup_strs flag. */

/* Called by: */
struct zx_prov_PMUpdateResponse_s* zx_DEEP_CLONE_prov_PMUpdateResponse(struct zx_ctx* c, struct zx_prov_PMUpdateResponse_s* x, int dup_strs)
{
  x = (struct zx_prov_PMUpdateResponse_s*)zx_clone_elem_common(c, &x->gg, sizeof(struct zx_prov_PMUpdateResponse_s), dup_strs);
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

/* FUNC(zx_WALK_SO_prov_PMUpdateResponse) */

/* Depth first traversal of the tree in either schema order or the wire order. */
 
int zx_WALK_SO_prov_PMUpdateResponse(struct zx_ctx* c, struct zx_prov_PMUpdateResponse_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
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

/* FUNC(zx_WALK_WO_prov_PMUpdateResponse) */

int zx_WALK_WO_prov_PMUpdateResponse(struct zx_ctx* c, struct zx_prov_PMUpdateResponse_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
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

#define EL_NAME   prov_Poll
#define EL_STRUCT zx_prov_Poll_s
#define EL_NS     prov
#define EL_TAG    Poll

/* FUNC(zx_FREE_prov_Poll) */

/* Depth first traversal of data structure to free it and its subelements. Simple
 * strings are handled as a special case according to the free_strs flag. This
 * is useful if the strings point to underlying data from the wire that was
 * allocated differently. */

/* Called by: */
void zx_FREE_prov_Poll(struct zx_ctx* c, struct zx_prov_Poll_s* x, int free_strs)
{
  /* *** deal with xmlns specifications in exc c14n way */

  zx_free_attr(c, x->wait, free_strs);

  {
      struct zx_a_Action_s* e;
      struct zx_a_Action_s* en;
      for (e = x->Action; e; e = en) {
	  en = (struct zx_a_Action_s*)e->gg.g.n;
	  zx_FREE_a_Action(c, e, free_strs);
      }
  }
  {
      struct zx_dp_Response_s* e;
      struct zx_dp_Response_s* en;
      for (e = x->Response; e; e = en) {
	  en = (struct zx_dp_Response_s*)e->gg.g.n;
	  zx_FREE_dp_Response(c, e, free_strs);
      }
  }


  zx_free_elem_common(c, &x->gg, free_strs); 
}

/* FUNC(zx_NEW_prov_Poll) */

/* Trivial allocator/constructor for the datatype. */

/* Called by: */
struct zx_prov_Poll_s* zx_NEW_prov_Poll(struct zx_ctx* c)
{
  struct zx_prov_Poll_s* x = ZX_ZALLOC(c, struct zx_prov_Poll_s);
  x->gg.g.tok = zx_prov_Poll_ELEM;
  return x;
}

#ifdef ZX_ENA_AUX

/* FUNC(zx_DUP_STRS_prov_Poll) */

/* Depth first traversal of data structure to copy its simple strings
 * to memory allocated from the memory allocator. The decoder will
 * use the underlying wireprotocol PDU buffer for strings, i.e.
 * strings are not copied - they point to the real data. If the
 * datastructure needs to outlast the protocol data or needs a different
 * memory allocation strategy, you need to call this function.  */

/* Called by: */
void zx_DUP_STRS_prov_Poll(struct zx_ctx* c, struct zx_prov_Poll_s* x)
{
  zx_dup_strs_common(c, &x->gg);
  /* *** deal with xmlns specifications in exc c14n way */

  zx_dup_attr(c, x->wait);

  {
      struct zx_a_Action_s* e;
      for (e = x->Action; e; e = (struct zx_a_Action_s*)e->gg.g.n)
	  zx_DUP_STRS_a_Action(c, e);
  }
  {
      struct zx_dp_Response_s* e;
      for (e = x->Response; e; e = (struct zx_dp_Response_s*)e->gg.g.n)
	  zx_DUP_STRS_dp_Response(c, e);
  }

}

/* FUNC(zx_DEEP_CLONE_prov_Poll) */

/* Depth first traversal of data structure to clone it and its sublements.
 * The simple strings are handled as a special case according to dup_strs flag. */

/* Called by: */
struct zx_prov_Poll_s* zx_DEEP_CLONE_prov_Poll(struct zx_ctx* c, struct zx_prov_Poll_s* x, int dup_strs)
{
  x = (struct zx_prov_Poll_s*)zx_clone_elem_common(c, &x->gg, sizeof(struct zx_prov_Poll_s), dup_strs);
  /* *** deal with xmlns specifications in exc c14n way */

  x->wait = zx_clone_attr(c, x->wait);

  {
      struct zx_a_Action_s* e;
      struct zx_a_Action_s* en;
      struct zx_a_Action_s* enn;
      for (enn = 0, e = x->Action; e; e = (struct zx_a_Action_s*)e->gg.g.n) {
	  en = zx_DEEP_CLONE_a_Action(c, e, dup_strs);
	  if (!enn)
	      x->Action = en;
	  else
	      enn->gg.g.n = &en->gg.g;
	  enn = en;
      }
  }
  {
      struct zx_dp_Response_s* e;
      struct zx_dp_Response_s* en;
      struct zx_dp_Response_s* enn;
      for (enn = 0, e = x->Response; e; e = (struct zx_dp_Response_s*)e->gg.g.n) {
	  en = zx_DEEP_CLONE_dp_Response(c, e, dup_strs);
	  if (!enn)
	      x->Response = en;
	  else
	      enn->gg.g.n = &en->gg.g;
	  enn = en;
      }
  }

  return x;
}

/* FUNC(zx_WALK_SO_prov_Poll) */

/* Depth first traversal of the tree in either schema order or the wire order. */
 
int zx_WALK_SO_prov_Poll(struct zx_ctx* c, struct zx_prov_Poll_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
{
  int ret = callback(&x->gg.g, ctx);
  if (ret)
    return ret;
  
  /* *** deal with xmlns specifications in exc c14n way */


  
  ret = zx_walk_so_unknown_attributes(c, &x->gg, ctx, callback); 
  if (ret)
    return ret;

  {
      struct zx_a_Action_s* e;
      for (e = x->Action; e; e = (struct zx_a_Action_s*)e->gg.g.n) {
	  ret = zx_WALK_SO_a_Action(c, e, ctx, callback);
	  if (ret)
	      return ret;
      }
  }
  {
      struct zx_dp_Response_s* e;
      for (e = x->Response; e; e = (struct zx_dp_Response_s*)e->gg.g.n) {
	  ret = zx_WALK_SO_dp_Response(c, e, ctx, callback);
	  if (ret)
	      return ret;
      }
  }

  
  return zx_walk_so_unknown_elems_and_content(c, &x->gg, ctx, callback);
}

/* FUNC(zx_WALK_WO_prov_Poll) */

int zx_WALK_WO_prov_Poll(struct zx_ctx* c, struct zx_prov_Poll_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
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

#define EL_NAME   prov_PollResponse
#define EL_STRUCT zx_prov_PollResponse_s
#define EL_NS     prov
#define EL_TAG    PollResponse

/* FUNC(zx_FREE_prov_PollResponse) */

/* Depth first traversal of data structure to free it and its subelements. Simple
 * strings are handled as a special case according to the free_strs flag. This
 * is useful if the strings point to underlying data from the wire that was
 * allocated differently. */

/* Called by: */
void zx_FREE_prov_PollResponse(struct zx_ctx* c, struct zx_prov_PollResponse_s* x, int free_strs)
{
  /* *** deal with xmlns specifications in exc c14n way */

  zx_free_attr(c, x->nextPoll, free_strs);

  {
      struct zx_dp_Request_s* e;
      struct zx_dp_Request_s* en;
      for (e = x->Request; e; e = en) {
	  en = (struct zx_dp_Request_s*)e->gg.g.n;
	  zx_FREE_dp_Request(c, e, free_strs);
      }
  }


  zx_free_elem_common(c, &x->gg, free_strs); 
}

/* FUNC(zx_NEW_prov_PollResponse) */

/* Trivial allocator/constructor for the datatype. */

/* Called by: */
struct zx_prov_PollResponse_s* zx_NEW_prov_PollResponse(struct zx_ctx* c)
{
  struct zx_prov_PollResponse_s* x = ZX_ZALLOC(c, struct zx_prov_PollResponse_s);
  x->gg.g.tok = zx_prov_PollResponse_ELEM;
  return x;
}

#ifdef ZX_ENA_AUX

/* FUNC(zx_DUP_STRS_prov_PollResponse) */

/* Depth first traversal of data structure to copy its simple strings
 * to memory allocated from the memory allocator. The decoder will
 * use the underlying wireprotocol PDU buffer for strings, i.e.
 * strings are not copied - they point to the real data. If the
 * datastructure needs to outlast the protocol data or needs a different
 * memory allocation strategy, you need to call this function.  */

/* Called by: */
void zx_DUP_STRS_prov_PollResponse(struct zx_ctx* c, struct zx_prov_PollResponse_s* x)
{
  zx_dup_strs_common(c, &x->gg);
  /* *** deal with xmlns specifications in exc c14n way */

  zx_dup_attr(c, x->nextPoll);

  {
      struct zx_dp_Request_s* e;
      for (e = x->Request; e; e = (struct zx_dp_Request_s*)e->gg.g.n)
	  zx_DUP_STRS_dp_Request(c, e);
  }

}

/* FUNC(zx_DEEP_CLONE_prov_PollResponse) */

/* Depth first traversal of data structure to clone it and its sublements.
 * The simple strings are handled as a special case according to dup_strs flag. */

/* Called by: */
struct zx_prov_PollResponse_s* zx_DEEP_CLONE_prov_PollResponse(struct zx_ctx* c, struct zx_prov_PollResponse_s* x, int dup_strs)
{
  x = (struct zx_prov_PollResponse_s*)zx_clone_elem_common(c, &x->gg, sizeof(struct zx_prov_PollResponse_s), dup_strs);
  /* *** deal with xmlns specifications in exc c14n way */

  x->nextPoll = zx_clone_attr(c, x->nextPoll);

  {
      struct zx_dp_Request_s* e;
      struct zx_dp_Request_s* en;
      struct zx_dp_Request_s* enn;
      for (enn = 0, e = x->Request; e; e = (struct zx_dp_Request_s*)e->gg.g.n) {
	  en = zx_DEEP_CLONE_dp_Request(c, e, dup_strs);
	  if (!enn)
	      x->Request = en;
	  else
	      enn->gg.g.n = &en->gg.g;
	  enn = en;
      }
  }

  return x;
}

/* FUNC(zx_WALK_SO_prov_PollResponse) */

/* Depth first traversal of the tree in either schema order or the wire order. */
 
int zx_WALK_SO_prov_PollResponse(struct zx_ctx* c, struct zx_prov_PollResponse_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
{
  int ret = callback(&x->gg.g, ctx);
  if (ret)
    return ret;
  
  /* *** deal with xmlns specifications in exc c14n way */


  
  ret = zx_walk_so_unknown_attributes(c, &x->gg, ctx, callback); 
  if (ret)
    return ret;

  {
      struct zx_dp_Request_s* e;
      for (e = x->Request; e; e = (struct zx_dp_Request_s*)e->gg.g.n) {
	  ret = zx_WALK_SO_dp_Request(c, e, ctx, callback);
	  if (ret)
	      return ret;
      }
  }

  
  return zx_walk_so_unknown_elems_and_content(c, &x->gg, ctx, callback);
}

/* FUNC(zx_WALK_WO_prov_PollResponse) */

int zx_WALK_WO_prov_PollResponse(struct zx_ctx* c, struct zx_prov_PollResponse_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
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

#define EL_NAME   prov_ProvisioningHandle
#define EL_STRUCT zx_prov_ProvisioningHandle_s
#define EL_NS     prov
#define EL_TAG    ProvisioningHandle

/* FUNC(zx_FREE_prov_ProvisioningHandle) */

/* Depth first traversal of data structure to free it and its subelements. Simple
 * strings are handled as a special case according to the free_strs flag. This
 * is useful if the strings point to underlying data from the wire that was
 * allocated differently. */

/* Called by: */
void zx_FREE_prov_ProvisioningHandle(struct zx_ctx* c, struct zx_prov_ProvisioningHandle_s* x, int free_strs)
{
  /* *** deal with xmlns specifications in exc c14n way */

  zx_free_attr(c, x->expires, free_strs);

  zx_free_simple_elems(c, x->PMDArtifact, free_strs);
  {
      struct zx_prov_ProvisioningServiceEPR_s* e;
      struct zx_prov_ProvisioningServiceEPR_s* en;
      for (e = x->ProvisioningServiceEPR; e; e = en) {
	  en = (struct zx_prov_ProvisioningServiceEPR_s*)e->gg.g.n;
	  zx_FREE_prov_ProvisioningServiceEPR(c, e, free_strs);
      }
  }
  {
      struct zx_ds_Signature_s* e;
      struct zx_ds_Signature_s* en;
      for (e = x->Signature; e; e = en) {
	  en = (struct zx_ds_Signature_s*)e->gg.g.n;
	  zx_FREE_ds_Signature(c, e, free_strs);
      }
  }


  zx_free_elem_common(c, &x->gg, free_strs); 
}

/* FUNC(zx_NEW_prov_ProvisioningHandle) */

/* Trivial allocator/constructor for the datatype. */

/* Called by: */
struct zx_prov_ProvisioningHandle_s* zx_NEW_prov_ProvisioningHandle(struct zx_ctx* c)
{
  struct zx_prov_ProvisioningHandle_s* x = ZX_ZALLOC(c, struct zx_prov_ProvisioningHandle_s);
  x->gg.g.tok = zx_prov_ProvisioningHandle_ELEM;
  return x;
}

#ifdef ZX_ENA_AUX

/* FUNC(zx_DUP_STRS_prov_ProvisioningHandle) */

/* Depth first traversal of data structure to copy its simple strings
 * to memory allocated from the memory allocator. The decoder will
 * use the underlying wireprotocol PDU buffer for strings, i.e.
 * strings are not copied - they point to the real data. If the
 * datastructure needs to outlast the protocol data or needs a different
 * memory allocation strategy, you need to call this function.  */

/* Called by: */
void zx_DUP_STRS_prov_ProvisioningHandle(struct zx_ctx* c, struct zx_prov_ProvisioningHandle_s* x)
{
  zx_dup_strs_common(c, &x->gg);
  /* *** deal with xmlns specifications in exc c14n way */

  zx_dup_attr(c, x->expires);

  zx_dup_strs_simple_elems(c, x->PMDArtifact);
  {
      struct zx_prov_ProvisioningServiceEPR_s* e;
      for (e = x->ProvisioningServiceEPR; e; e = (struct zx_prov_ProvisioningServiceEPR_s*)e->gg.g.n)
	  zx_DUP_STRS_prov_ProvisioningServiceEPR(c, e);
  }
  {
      struct zx_ds_Signature_s* e;
      for (e = x->Signature; e; e = (struct zx_ds_Signature_s*)e->gg.g.n)
	  zx_DUP_STRS_ds_Signature(c, e);
  }

}

/* FUNC(zx_DEEP_CLONE_prov_ProvisioningHandle) */

/* Depth first traversal of data structure to clone it and its sublements.
 * The simple strings are handled as a special case according to dup_strs flag. */

/* Called by: */
struct zx_prov_ProvisioningHandle_s* zx_DEEP_CLONE_prov_ProvisioningHandle(struct zx_ctx* c, struct zx_prov_ProvisioningHandle_s* x, int dup_strs)
{
  x = (struct zx_prov_ProvisioningHandle_s*)zx_clone_elem_common(c, &x->gg, sizeof(struct zx_prov_ProvisioningHandle_s), dup_strs);
  /* *** deal with xmlns specifications in exc c14n way */

  x->expires = zx_clone_attr(c, x->expires);

  x->PMDArtifact = zx_deep_clone_simple_elems(c,x->PMDArtifact, dup_strs);
  {
      struct zx_prov_ProvisioningServiceEPR_s* e;
      struct zx_prov_ProvisioningServiceEPR_s* en;
      struct zx_prov_ProvisioningServiceEPR_s* enn;
      for (enn = 0, e = x->ProvisioningServiceEPR; e; e = (struct zx_prov_ProvisioningServiceEPR_s*)e->gg.g.n) {
	  en = zx_DEEP_CLONE_prov_ProvisioningServiceEPR(c, e, dup_strs);
	  if (!enn)
	      x->ProvisioningServiceEPR = en;
	  else
	      enn->gg.g.n = &en->gg.g;
	  enn = en;
      }
  }
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

  return x;
}

/* FUNC(zx_WALK_SO_prov_ProvisioningHandle) */

/* Depth first traversal of the tree in either schema order or the wire order. */
 
int zx_WALK_SO_prov_ProvisioningHandle(struct zx_ctx* c, struct zx_prov_ProvisioningHandle_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
{
  int ret = callback(&x->gg.g, ctx);
  if (ret)
    return ret;
  
  /* *** deal with xmlns specifications in exc c14n way */


  
  ret = zx_walk_so_unknown_attributes(c, &x->gg, ctx, callback); 
  if (ret)
    return ret;

  ret = zx_walk_so_simple_elems(c, x->PMDArtifact, ctx, callback);
  if (ret)
    return ret;
  {
      struct zx_prov_ProvisioningServiceEPR_s* e;
      for (e = x->ProvisioningServiceEPR; e; e = (struct zx_prov_ProvisioningServiceEPR_s*)e->gg.g.n) {
	  ret = zx_WALK_SO_prov_ProvisioningServiceEPR(c, e, ctx, callback);
	  if (ret)
	      return ret;
      }
  }
  {
      struct zx_ds_Signature_s* e;
      for (e = x->Signature; e; e = (struct zx_ds_Signature_s*)e->gg.g.n) {
	  ret = zx_WALK_SO_ds_Signature(c, e, ctx, callback);
	  if (ret)
	      return ret;
      }
  }

  
  return zx_walk_so_unknown_elems_and_content(c, &x->gg, ctx, callback);
}

/* FUNC(zx_WALK_WO_prov_ProvisioningHandle) */

int zx_WALK_WO_prov_ProvisioningHandle(struct zx_ctx* c, struct zx_prov_ProvisioningHandle_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
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

#define EL_NAME   prov_ProvisioningServiceEPR
#define EL_STRUCT zx_prov_ProvisioningServiceEPR_s
#define EL_NS     prov
#define EL_TAG    ProvisioningServiceEPR

/* FUNC(zx_FREE_prov_ProvisioningServiceEPR) */

/* Depth first traversal of data structure to free it and its subelements. Simple
 * strings are handled as a special case according to the free_strs flag. This
 * is useful if the strings point to underlying data from the wire that was
 * allocated differently. */

/* Called by: */
void zx_FREE_prov_ProvisioningServiceEPR(struct zx_ctx* c, struct zx_prov_ProvisioningServiceEPR_s* x, int free_strs)
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

/* FUNC(zx_NEW_prov_ProvisioningServiceEPR) */

/* Trivial allocator/constructor for the datatype. */

/* Called by: */
struct zx_prov_ProvisioningServiceEPR_s* zx_NEW_prov_ProvisioningServiceEPR(struct zx_ctx* c)
{
  struct zx_prov_ProvisioningServiceEPR_s* x = ZX_ZALLOC(c, struct zx_prov_ProvisioningServiceEPR_s);
  x->gg.g.tok = zx_prov_ProvisioningServiceEPR_ELEM;
  return x;
}

#ifdef ZX_ENA_AUX

/* FUNC(zx_DUP_STRS_prov_ProvisioningServiceEPR) */

/* Depth first traversal of data structure to copy its simple strings
 * to memory allocated from the memory allocator. The decoder will
 * use the underlying wireprotocol PDU buffer for strings, i.e.
 * strings are not copied - they point to the real data. If the
 * datastructure needs to outlast the protocol data or needs a different
 * memory allocation strategy, you need to call this function.  */

/* Called by: */
void zx_DUP_STRS_prov_ProvisioningServiceEPR(struct zx_ctx* c, struct zx_prov_ProvisioningServiceEPR_s* x)
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

/* FUNC(zx_DEEP_CLONE_prov_ProvisioningServiceEPR) */

/* Depth first traversal of data structure to clone it and its sublements.
 * The simple strings are handled as a special case according to dup_strs flag. */

/* Called by: */
struct zx_prov_ProvisioningServiceEPR_s* zx_DEEP_CLONE_prov_ProvisioningServiceEPR(struct zx_ctx* c, struct zx_prov_ProvisioningServiceEPR_s* x, int dup_strs)
{
  x = (struct zx_prov_ProvisioningServiceEPR_s*)zx_clone_elem_common(c, &x->gg, sizeof(struct zx_prov_ProvisioningServiceEPR_s), dup_strs);
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

/* FUNC(zx_WALK_SO_prov_ProvisioningServiceEPR) */

/* Depth first traversal of the tree in either schema order or the wire order. */
 
int zx_WALK_SO_prov_ProvisioningServiceEPR(struct zx_ctx* c, struct zx_prov_ProvisioningServiceEPR_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
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

/* FUNC(zx_WALK_WO_prov_ProvisioningServiceEPR) */

int zx_WALK_WO_prov_ProvisioningServiceEPR(struct zx_ctx* c, struct zx_prov_ProvisioningServiceEPR_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
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

#define EL_NAME   prov_State
#define EL_STRUCT zx_prov_State_s
#define EL_NS     prov
#define EL_TAG    State

/* FUNC(zx_FREE_prov_State) */

/* Depth first traversal of data structure to free it and its subelements. Simple
 * strings are handled as a special case according to the free_strs flag. This
 * is useful if the strings point to underlying data from the wire that was
 * allocated differently. */

/* Called by: */
void zx_FREE_prov_State(struct zx_ctx* c, struct zx_prov_State_s* x, int free_strs)
{
  /* *** deal with xmlns specifications in exc c14n way */

  zx_free_attr(c, x->asof, free_strs);



  zx_free_elem_common(c, &x->gg, free_strs); 
}

/* FUNC(zx_NEW_prov_State) */

/* Trivial allocator/constructor for the datatype. */

/* Called by: */
struct zx_prov_State_s* zx_NEW_prov_State(struct zx_ctx* c)
{
  struct zx_prov_State_s* x = ZX_ZALLOC(c, struct zx_prov_State_s);
  x->gg.g.tok = zx_prov_State_ELEM;
  return x;
}

#ifdef ZX_ENA_AUX

/* FUNC(zx_DUP_STRS_prov_State) */

/* Depth first traversal of data structure to copy its simple strings
 * to memory allocated from the memory allocator. The decoder will
 * use the underlying wireprotocol PDU buffer for strings, i.e.
 * strings are not copied - they point to the real data. If the
 * datastructure needs to outlast the protocol data or needs a different
 * memory allocation strategy, you need to call this function.  */

/* Called by: */
void zx_DUP_STRS_prov_State(struct zx_ctx* c, struct zx_prov_State_s* x)
{
  zx_dup_strs_common(c, &x->gg);
  /* *** deal with xmlns specifications in exc c14n way */

  zx_dup_attr(c, x->asof);


}

/* FUNC(zx_DEEP_CLONE_prov_State) */

/* Depth first traversal of data structure to clone it and its sublements.
 * The simple strings are handled as a special case according to dup_strs flag. */

/* Called by: */
struct zx_prov_State_s* zx_DEEP_CLONE_prov_State(struct zx_ctx* c, struct zx_prov_State_s* x, int dup_strs)
{
  x = (struct zx_prov_State_s*)zx_clone_elem_common(c, &x->gg, sizeof(struct zx_prov_State_s), dup_strs);
  /* *** deal with xmlns specifications in exc c14n way */

  x->asof = zx_clone_attr(c, x->asof);


  return x;
}

/* FUNC(zx_WALK_SO_prov_State) */

/* Depth first traversal of the tree in either schema order or the wire order. */
 
int zx_WALK_SO_prov_State(struct zx_ctx* c, struct zx_prov_State_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
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

/* FUNC(zx_WALK_WO_prov_State) */

int zx_WALK_WO_prov_State(struct zx_ctx* c, struct zx_prov_State_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
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

#define EL_NAME   prov_UpdateEPR
#define EL_STRUCT zx_prov_UpdateEPR_s
#define EL_NS     prov
#define EL_TAG    UpdateEPR

/* FUNC(zx_FREE_prov_UpdateEPR) */

/* Depth first traversal of data structure to free it and its subelements. Simple
 * strings are handled as a special case according to the free_strs flag. This
 * is useful if the strings point to underlying data from the wire that was
 * allocated differently. */

/* Called by: */
void zx_FREE_prov_UpdateEPR(struct zx_ctx* c, struct zx_prov_UpdateEPR_s* x, int free_strs)
{
  /* *** deal with xmlns specifications in exc c14n way */


  {
      struct zx_prov_UpdateEPRItem_s* e;
      struct zx_prov_UpdateEPRItem_s* en;
      for (e = x->UpdateEPRItem; e; e = en) {
	  en = (struct zx_prov_UpdateEPRItem_s*)e->gg.g.n;
	  zx_FREE_prov_UpdateEPRItem(c, e, free_strs);
      }
  }


  zx_free_elem_common(c, &x->gg, free_strs); 
}

/* FUNC(zx_NEW_prov_UpdateEPR) */

/* Trivial allocator/constructor for the datatype. */

/* Called by: */
struct zx_prov_UpdateEPR_s* zx_NEW_prov_UpdateEPR(struct zx_ctx* c)
{
  struct zx_prov_UpdateEPR_s* x = ZX_ZALLOC(c, struct zx_prov_UpdateEPR_s);
  x->gg.g.tok = zx_prov_UpdateEPR_ELEM;
  return x;
}

#ifdef ZX_ENA_AUX

/* FUNC(zx_DUP_STRS_prov_UpdateEPR) */

/* Depth first traversal of data structure to copy its simple strings
 * to memory allocated from the memory allocator. The decoder will
 * use the underlying wireprotocol PDU buffer for strings, i.e.
 * strings are not copied - they point to the real data. If the
 * datastructure needs to outlast the protocol data or needs a different
 * memory allocation strategy, you need to call this function.  */

/* Called by: */
void zx_DUP_STRS_prov_UpdateEPR(struct zx_ctx* c, struct zx_prov_UpdateEPR_s* x)
{
  zx_dup_strs_common(c, &x->gg);
  /* *** deal with xmlns specifications in exc c14n way */


  {
      struct zx_prov_UpdateEPRItem_s* e;
      for (e = x->UpdateEPRItem; e; e = (struct zx_prov_UpdateEPRItem_s*)e->gg.g.n)
	  zx_DUP_STRS_prov_UpdateEPRItem(c, e);
  }

}

/* FUNC(zx_DEEP_CLONE_prov_UpdateEPR) */

/* Depth first traversal of data structure to clone it and its sublements.
 * The simple strings are handled as a special case according to dup_strs flag. */

/* Called by: */
struct zx_prov_UpdateEPR_s* zx_DEEP_CLONE_prov_UpdateEPR(struct zx_ctx* c, struct zx_prov_UpdateEPR_s* x, int dup_strs)
{
  x = (struct zx_prov_UpdateEPR_s*)zx_clone_elem_common(c, &x->gg, sizeof(struct zx_prov_UpdateEPR_s), dup_strs);
  /* *** deal with xmlns specifications in exc c14n way */


  {
      struct zx_prov_UpdateEPRItem_s* e;
      struct zx_prov_UpdateEPRItem_s* en;
      struct zx_prov_UpdateEPRItem_s* enn;
      for (enn = 0, e = x->UpdateEPRItem; e; e = (struct zx_prov_UpdateEPRItem_s*)e->gg.g.n) {
	  en = zx_DEEP_CLONE_prov_UpdateEPRItem(c, e, dup_strs);
	  if (!enn)
	      x->UpdateEPRItem = en;
	  else
	      enn->gg.g.n = &en->gg.g;
	  enn = en;
      }
  }

  return x;
}

/* FUNC(zx_WALK_SO_prov_UpdateEPR) */

/* Depth first traversal of the tree in either schema order or the wire order. */
 
int zx_WALK_SO_prov_UpdateEPR(struct zx_ctx* c, struct zx_prov_UpdateEPR_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
{
  int ret = callback(&x->gg.g, ctx);
  if (ret)
    return ret;
  
  /* *** deal with xmlns specifications in exc c14n way */


  
  ret = zx_walk_so_unknown_attributes(c, &x->gg, ctx, callback); 
  if (ret)
    return ret;

  {
      struct zx_prov_UpdateEPRItem_s* e;
      for (e = x->UpdateEPRItem; e; e = (struct zx_prov_UpdateEPRItem_s*)e->gg.g.n) {
	  ret = zx_WALK_SO_prov_UpdateEPRItem(c, e, ctx, callback);
	  if (ret)
	      return ret;
      }
  }

  
  return zx_walk_so_unknown_elems_and_content(c, &x->gg, ctx, callback);
}

/* FUNC(zx_WALK_WO_prov_UpdateEPR) */

int zx_WALK_WO_prov_UpdateEPR(struct zx_ctx* c, struct zx_prov_UpdateEPR_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
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

#define EL_NAME   prov_UpdateEPRItem
#define EL_STRUCT zx_prov_UpdateEPRItem_s
#define EL_NS     prov
#define EL_TAG    UpdateEPRItem

/* FUNC(zx_FREE_prov_UpdateEPRItem) */

/* Depth first traversal of data structure to free it and its subelements. Simple
 * strings are handled as a special case according to the free_strs flag. This
 * is useful if the strings point to underlying data from the wire that was
 * allocated differently. */

/* Called by: */
void zx_FREE_prov_UpdateEPRItem(struct zx_ctx* c, struct zx_prov_UpdateEPRItem_s* x, int free_strs)
{
  /* *** deal with xmlns specifications in exc c14n way */

  zx_free_attr(c, x->itemID, free_strs);

  {
      struct zx_prov_PMID_s* e;
      struct zx_prov_PMID_s* en;
      for (e = x->PMID; e; e = en) {
	  en = (struct zx_prov_PMID_s*)e->gg.g.n;
	  zx_FREE_prov_PMID(c, e, free_strs);
      }
  }
  {
      struct zx_prov_CallbackEPR_s* e;
      struct zx_prov_CallbackEPR_s* en;
      for (e = x->CallbackEPR; e; e = en) {
	  en = (struct zx_prov_CallbackEPR_s*)e->gg.g.n;
	  zx_FREE_prov_CallbackEPR(c, e, free_strs);
      }
  }


  zx_free_elem_common(c, &x->gg, free_strs); 
}

/* FUNC(zx_NEW_prov_UpdateEPRItem) */

/* Trivial allocator/constructor for the datatype. */

/* Called by: */
struct zx_prov_UpdateEPRItem_s* zx_NEW_prov_UpdateEPRItem(struct zx_ctx* c)
{
  struct zx_prov_UpdateEPRItem_s* x = ZX_ZALLOC(c, struct zx_prov_UpdateEPRItem_s);
  x->gg.g.tok = zx_prov_UpdateEPRItem_ELEM;
  return x;
}

#ifdef ZX_ENA_AUX

/* FUNC(zx_DUP_STRS_prov_UpdateEPRItem) */

/* Depth first traversal of data structure to copy its simple strings
 * to memory allocated from the memory allocator. The decoder will
 * use the underlying wireprotocol PDU buffer for strings, i.e.
 * strings are not copied - they point to the real data. If the
 * datastructure needs to outlast the protocol data or needs a different
 * memory allocation strategy, you need to call this function.  */

/* Called by: */
void zx_DUP_STRS_prov_UpdateEPRItem(struct zx_ctx* c, struct zx_prov_UpdateEPRItem_s* x)
{
  zx_dup_strs_common(c, &x->gg);
  /* *** deal with xmlns specifications in exc c14n way */

  zx_dup_attr(c, x->itemID);

  {
      struct zx_prov_PMID_s* e;
      for (e = x->PMID; e; e = (struct zx_prov_PMID_s*)e->gg.g.n)
	  zx_DUP_STRS_prov_PMID(c, e);
  }
  {
      struct zx_prov_CallbackEPR_s* e;
      for (e = x->CallbackEPR; e; e = (struct zx_prov_CallbackEPR_s*)e->gg.g.n)
	  zx_DUP_STRS_prov_CallbackEPR(c, e);
  }

}

/* FUNC(zx_DEEP_CLONE_prov_UpdateEPRItem) */

/* Depth first traversal of data structure to clone it and its sublements.
 * The simple strings are handled as a special case according to dup_strs flag. */

/* Called by: */
struct zx_prov_UpdateEPRItem_s* zx_DEEP_CLONE_prov_UpdateEPRItem(struct zx_ctx* c, struct zx_prov_UpdateEPRItem_s* x, int dup_strs)
{
  x = (struct zx_prov_UpdateEPRItem_s*)zx_clone_elem_common(c, &x->gg, sizeof(struct zx_prov_UpdateEPRItem_s), dup_strs);
  /* *** deal with xmlns specifications in exc c14n way */

  x->itemID = zx_clone_attr(c, x->itemID);

  {
      struct zx_prov_PMID_s* e;
      struct zx_prov_PMID_s* en;
      struct zx_prov_PMID_s* enn;
      for (enn = 0, e = x->PMID; e; e = (struct zx_prov_PMID_s*)e->gg.g.n) {
	  en = zx_DEEP_CLONE_prov_PMID(c, e, dup_strs);
	  if (!enn)
	      x->PMID = en;
	  else
	      enn->gg.g.n = &en->gg.g;
	  enn = en;
      }
  }
  {
      struct zx_prov_CallbackEPR_s* e;
      struct zx_prov_CallbackEPR_s* en;
      struct zx_prov_CallbackEPR_s* enn;
      for (enn = 0, e = x->CallbackEPR; e; e = (struct zx_prov_CallbackEPR_s*)e->gg.g.n) {
	  en = zx_DEEP_CLONE_prov_CallbackEPR(c, e, dup_strs);
	  if (!enn)
	      x->CallbackEPR = en;
	  else
	      enn->gg.g.n = &en->gg.g;
	  enn = en;
      }
  }

  return x;
}

/* FUNC(zx_WALK_SO_prov_UpdateEPRItem) */

/* Depth first traversal of the tree in either schema order or the wire order. */
 
int zx_WALK_SO_prov_UpdateEPRItem(struct zx_ctx* c, struct zx_prov_UpdateEPRItem_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
{
  int ret = callback(&x->gg.g, ctx);
  if (ret)
    return ret;
  
  /* *** deal with xmlns specifications in exc c14n way */


  
  ret = zx_walk_so_unknown_attributes(c, &x->gg, ctx, callback); 
  if (ret)
    return ret;

  {
      struct zx_prov_PMID_s* e;
      for (e = x->PMID; e; e = (struct zx_prov_PMID_s*)e->gg.g.n) {
	  ret = zx_WALK_SO_prov_PMID(c, e, ctx, callback);
	  if (ret)
	      return ret;
      }
  }
  {
      struct zx_prov_CallbackEPR_s* e;
      for (e = x->CallbackEPR; e; e = (struct zx_prov_CallbackEPR_s*)e->gg.g.n) {
	  ret = zx_WALK_SO_prov_CallbackEPR(c, e, ctx, callback);
	  if (ret)
	      return ret;
      }
  }

  
  return zx_walk_so_unknown_elems_and_content(c, &x->gg, ctx, callback);
}

/* FUNC(zx_WALK_WO_prov_UpdateEPRItem) */

int zx_WALK_WO_prov_UpdateEPRItem(struct zx_ctx* c, struct zx_prov_UpdateEPRItem_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
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

#define EL_NAME   prov_UpdateEPRResponse
#define EL_STRUCT zx_prov_UpdateEPRResponse_s
#define EL_NS     prov
#define EL_TAG    UpdateEPRResponse

/* FUNC(zx_FREE_prov_UpdateEPRResponse) */

/* Depth first traversal of data structure to free it and its subelements. Simple
 * strings are handled as a special case according to the free_strs flag. This
 * is useful if the strings point to underlying data from the wire that was
 * allocated differently. */

/* Called by: */
void zx_FREE_prov_UpdateEPRResponse(struct zx_ctx* c, struct zx_prov_UpdateEPRResponse_s* x, int free_strs)
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

/* FUNC(zx_NEW_prov_UpdateEPRResponse) */

/* Trivial allocator/constructor for the datatype. */

/* Called by: */
struct zx_prov_UpdateEPRResponse_s* zx_NEW_prov_UpdateEPRResponse(struct zx_ctx* c)
{
  struct zx_prov_UpdateEPRResponse_s* x = ZX_ZALLOC(c, struct zx_prov_UpdateEPRResponse_s);
  x->gg.g.tok = zx_prov_UpdateEPRResponse_ELEM;
  return x;
}

#ifdef ZX_ENA_AUX

/* FUNC(zx_DUP_STRS_prov_UpdateEPRResponse) */

/* Depth first traversal of data structure to copy its simple strings
 * to memory allocated from the memory allocator. The decoder will
 * use the underlying wireprotocol PDU buffer for strings, i.e.
 * strings are not copied - they point to the real data. If the
 * datastructure needs to outlast the protocol data or needs a different
 * memory allocation strategy, you need to call this function.  */

/* Called by: */
void zx_DUP_STRS_prov_UpdateEPRResponse(struct zx_ctx* c, struct zx_prov_UpdateEPRResponse_s* x)
{
  zx_dup_strs_common(c, &x->gg);
  /* *** deal with xmlns specifications in exc c14n way */


  {
      struct zx_lu_Status_s* e;
      for (e = x->Status; e; e = (struct zx_lu_Status_s*)e->gg.g.n)
	  zx_DUP_STRS_lu_Status(c, e);
  }

}

/* FUNC(zx_DEEP_CLONE_prov_UpdateEPRResponse) */

/* Depth first traversal of data structure to clone it and its sublements.
 * The simple strings are handled as a special case according to dup_strs flag. */

/* Called by: */
struct zx_prov_UpdateEPRResponse_s* zx_DEEP_CLONE_prov_UpdateEPRResponse(struct zx_ctx* c, struct zx_prov_UpdateEPRResponse_s* x, int dup_strs)
{
  x = (struct zx_prov_UpdateEPRResponse_s*)zx_clone_elem_common(c, &x->gg, sizeof(struct zx_prov_UpdateEPRResponse_s), dup_strs);
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

/* FUNC(zx_WALK_SO_prov_UpdateEPRResponse) */

/* Depth first traversal of the tree in either schema order or the wire order. */
 
int zx_WALK_SO_prov_UpdateEPRResponse(struct zx_ctx* c, struct zx_prov_UpdateEPRResponse_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
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

/* FUNC(zx_WALK_WO_prov_UpdateEPRResponse) */

int zx_WALK_WO_prov_UpdateEPRResponse(struct zx_ctx* c, struct zx_prov_UpdateEPRResponse_s* x, void* ctx, int (*callback)(struct zx_node_s* node, void* ctx))
{
  ERR("*** walk_wo not implemented %d", 0);
  return 0;
}

#endif


/* EOF -- c/zx-prov-aux.c */
